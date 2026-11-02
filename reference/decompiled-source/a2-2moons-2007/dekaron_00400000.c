// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x400000-0x40ffff

// ==== FUN_00401000 @ 0x00401000 ====

/* WARNING: Removing unreachable block (ram,0x00401009) */

bool FUN_00401000(uint param_1)

{
  int iVar1;
  
  iVar1 = cpuid_Version_info(1);
  return (param_1 & *(uint *)(iVar1 + 8)) != 0;
}


// ==== FUN_00401030 @ 0x00401030 ====

/* WARNING: Removing unreachable block (ram,0x00401041) */

bool FUN_00401030(void)

{
  int iVar1;
  
  iVar1 = cpuid_Version_info(1);
  return (*(uint *)(iVar1 + 8) & 0x800000) != 0;
}


// ==== FUN_00401060 @ 0x00401060 ====

/* WARNING: Removing unreachable block (ram,0x00401071) */

bool FUN_00401060(void)

{
  int iVar1;
  
  iVar1 = cpuid_Version_info(1);
  return (*(uint *)(iVar1 + 8) & 0x2000000) != 0;
}


// ==== FUN_00401090 @ 0x00401090 ====

/* WARNING: Removing unreachable block (ram,0x004010a1) */

bool FUN_00401090(void)

{
  int iVar1;
  
  iVar1 = cpuid_Version_info(1);
  return (*(uint *)(iVar1 + 8) & 0x4000000) != 0;
}


// ==== FUN_004010c0 @ 0x004010c0 ====

void FUN_004010c0(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  
  FUN_007969c0();
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_004011d0();
  }
  FUN_00401210(param_1,param_2);
  FUN_004011c0();
  DAT_00b5a680 = 1;
  FUN_004011e0();
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
  }
  FUN_00796ad0();
  return;
}


// ==== FUN_00401130 @ 0x00401130 ====

undefined4 FUN_00401130(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0099c518;
  puStack_10 = &DAT_0080015c;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  FUN_004010c0(param_1,param_3);
  ExceptionList = local_14;
  return 0;
}


// ==== FUN_00401187 @ 0x00401187 ====

undefined4 FUN_00401187(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return 0;
}


// ==== FUN_004011c0 @ 0x004011c0 ====

void FUN_004011c0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x004011c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 8))();
  return;
}


// ==== FUN_004011d0 @ 0x004011d0 ====

void FUN_004011d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099c590;
  in_ECX[2] = 0;
  return;
}


// ==== FUN_004011e0 @ 0x004011e0 ====

void FUN_004011e0(void)

{
  int in_ECX;
  
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


// ==== FUN_00401210 @ 0x00401210 ====

void FUN_00401210(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  void *local_20;
  undefined1 local_1c [4];
  undefined1 local_18;
  uint uStack_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_20 = (void *)0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_CShadowApp__Initialize_0099c560,0x16);
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401660(local_38,0,0xffffffff);
  FUN_00796e00(local_1c);
  if ((void *)0xf < local_20) {
    _free(local_34);
    return;
  }
  pvVar1 = operator_new(0x394);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_004034e0();
  }
  (**(code **)(*piVar2 + 0x4c))(param_1,param_2);
  *(int **)(in_ECX + 4) = piVar2;
  pvVar1 = operator_new(0x2c);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_004586a0();
  }
  *(int **)(in_ECX + 8) = piVar2;
  (**(code **)(*piVar2 + 4))();
  FUN_00796d40();
  if (uStack_c < 0x10) {
    return;
  }
  _free(local_20);
  return;
}


// ==== FUN_004012f0 @ 0x004012f0 ====

void FUN_004012f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099c590;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00401310 @ 0x00401310 ====

void FUN_00401310(int param_1)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x14) = param_1;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined1 *)(in_ECX + 4 + param_1) = 0;
    return;
  }
  *(undefined1 *)(*(int *)(in_ECX + 4) + param_1) = 0;
  return;
}


// ==== FUN_00401330 @ 0x00401330 ====

void FUN_00401330(char param_1,uint param_2)

{
  undefined4 *_Memory;
  undefined4 *in_ECX;
  uint uVar1;
  undefined4 *puVar2;
  
  if ((param_1 == '\0') || ((uint)in_ECX[6] < 0x10)) {
    in_ECX[5] = param_2;
    in_ECX[6] = 0xf;
    *(undefined1 *)((int)in_ECX + param_2 + 4) = 0;
    return;
  }
  _Memory = (undefined4 *)in_ECX[1];
  if (param_2 != 0) {
    puVar2 = _Memory;
    for (uVar1 = param_2 >> 2; in_ECX = in_ECX + 1, uVar1 != 0; uVar1 = uVar1 - 1) {
      *in_ECX = *puVar2;
      puVar2 = puVar2 + 1;
    }
    for (param_2 = param_2 & 3; param_2 != 0; param_2 = param_2 - 1) {
      *(undefined1 *)in_ECX = *(undefined1 *)puVar2;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
      in_ECX = (undefined4 *)((int)in_ECX + 1);
    }
  }
  _free(_Memory);
  return;
}


// ==== FUN_00401390 @ 0x00401390 ====

void FUN_00401390(uint param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (*(uint *)(in_ECX + 0x14) < param_1) {
    FUN_0079dba3();
  }
  uVar2 = *(int *)(in_ECX + 0x14) - param_1;
  if (uVar2 < param_2) {
    param_2 = uVar2;
  }
  if (param_2 != 0) {
    puVar5 = (undefined4 *)(in_ECX + 4);
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      puVar4 = puVar5;
      puVar1 = puVar5;
    }
    else {
      puVar4 = (undefined4 *)*puVar5;
      puVar1 = (undefined4 *)*puVar5;
    }
    _memmove((void *)((int)puVar4 + param_1),(void *)((int)puVar1 + param_2 + param_1),
             uVar2 - param_2);
    iVar3 = *(int *)(in_ECX + 0x14) - param_2;
    *(int *)(in_ECX + 0x14) = iVar3;
    if (0xf < *(uint *)(in_ECX + 0x18)) {
      puVar5 = (undefined4 *)*puVar5;
    }
    *(undefined1 *)((int)puVar5 + iVar3) = 0;
  }
  return;
}


// ==== FUN_00401410 @ 0x00401410 ====

void FUN_00401410(uint param_1)

{
  uint uVar1;
  int in_ECX;
  uint uVar2;
  uint uVar3;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00977aa0;
  pvStack_10 = ExceptionList;
  uVar3 = param_1 | 0xf;
  if (uVar3 == 0xffffffff) {
    uVar3 = param_1;
  }
  else {
    uVar1 = *(uint *)(in_ECX + 0x18);
    uVar2 = uVar1 >> 1;
    if ((uVar3 / 3 < uVar2) && (uVar1 <= -uVar2 - 2)) {
      uVar3 = uVar2 + uVar1;
    }
  }
  local_8 = 0;
  ExceptionList = &pvStack_10;
  operator_new(uVar3 + 1);
  FUN_004014b3();
  return;
}


// ==== Catch@00401481 @ 0x00401481 ====

undefined * Catch_00401481(void)

{
  void *pvVar1;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar1 = operator_new(*(int *)(unaff_EBP + 8) + 1);
  *(void **)(unaff_EBP + -0x14) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_004014aa;
}


// ==== FUN_004014b3 @ 0x004014b3 ====

void FUN_004014b3(void)

{
  undefined4 *in_EAX;
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar2 = *(uint *)(unaff_EBP + 0xc);
  iVar3 = 0;
  if (uVar2 != 0) {
    if (*(uint *)(unaff_ESI + 0x18) < 0x10) {
      puVar4 = (undefined4 *)(unaff_ESI + 4);
    }
    else {
      puVar4 = *(undefined4 **)(unaff_ESI + 4);
    }
    puVar5 = in_EAX;
    for (uVar1 = uVar2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    unaff_ESI = *(int *)(unaff_EBP + -0x18);
    iVar3 = *(int *)(unaff_EBP + 0xc);
  }
  if (0xf < *(uint *)(unaff_ESI + 0x18)) {
    _free(*(void **)(unaff_ESI + 4));
    return;
  }
  puVar4 = (undefined4 *)(unaff_ESI + 4);
  *(undefined1 *)puVar4 = 0;
  *puVar4 = in_EAX;
  *(uint *)(unaff_ESI + 0x18) = unaff_EBX;
  *(int *)(unaff_ESI + 0x14) = iVar3;
  if (unaff_EBX < 0x10) {
    in_EAX = puVar4;
  }
  *(undefined1 *)((int)in_EAX + iVar3) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ==== Catch@00401529 @ 0x00401529 ====

void Catch_00401529(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x18);
  if (*(uint *)(iVar1 + 0x18) < 0x10) {
    *(undefined4 *)(iVar1 + 0x18) = 0xf;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined1 *)(iVar1 + 4) = 0;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(0,0);
  }
  _free(*(void **)(iVar1 + 4));
  return;
}


// ==== FUN_00401560 @ 0x00401560 ====

uint FUN_00401560(uint param_1,char param_2)

{
  undefined4 *_Memory;
  uint extraout_EAX;
  undefined4 *in_ECX;
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  if (param_1 == 0xffffffff) {
    FUN_0079dbe3();
  }
  uVar1 = in_ECX[6];
  if (uVar1 < param_1) {
    FUN_00401410(param_1,in_ECX[5]);
    return (uint)(param_1 != 0);
  }
  if ((param_2 == '\0') || (0xf < param_1)) {
    if (param_1 == 0) {
      in_ECX[5] = 0;
      if (0xf < uVar1) {
        *(undefined1 *)in_ECX[1] = 0;
        return 0;
      }
      *(undefined1 *)(in_ECX + 1) = 0;
    }
    return (uint)(param_1 != 0);
  }
  uVar2 = in_ECX[5];
  if (param_1 < (uint)in_ECX[5]) {
    uVar2 = param_1;
  }
  if (uVar1 < 0x10) {
    in_ECX[5] = uVar2;
    in_ECX[6] = 0xf;
    *(undefined1 *)(uVar2 + 4 + (int)in_ECX) = 0;
    return (uint)(param_1 != 0);
  }
  _Memory = (undefined4 *)in_ECX[1];
  if (uVar2 != 0) {
    puVar3 = _Memory;
    for (uVar1 = uVar2 >> 2; in_ECX = in_ECX + 1, uVar1 != 0; uVar1 = uVar1 - 1) {
      *in_ECX = *puVar3;
      puVar3 = puVar3 + 1;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)in_ECX = *(undefined1 *)puVar3;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
      in_ECX = (undefined4 *)((int)in_ECX + 1);
    }
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_00401630 @ 0x00401630 ====

void FUN_00401630(void)

{
  int in_ECX;
  
  FUN_00796d40();
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00401660 @ 0x00401660 ====

void FUN_00401660(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  int in_ECX;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int *piVar5;
  
  if (*(uint *)(param_1 + 0x14) < param_2) {
    FUN_0079dba3();
  }
  uVar3 = *(int *)(param_1 + 0x14) - param_2;
  if (param_3 < uVar3) {
    uVar3 = param_3;
  }
  if (in_ECX == param_1) {
    FUN_00401390(uVar3 + param_2,0xffffffff);
    FUN_00401390(0,param_2);
    return;
  }
  if (uVar3 == 0xffffffff) {
    FUN_0079dbe3();
  }
  if (*(uint *)(in_ECX + 0x18) < uVar3) {
    FUN_00401410(uVar3,*(undefined4 *)(in_ECX + 0x14));
  }
  else if (uVar3 == 0) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      *(undefined1 *)(in_ECX + 4) = 0;
      return;
    }
    **(undefined1 **)(in_ECX + 4) = 0;
    return;
  }
  if (uVar3 != 0) {
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      param_1 = param_1 + 4;
    }
    else {
      param_1 = *(int *)(param_1 + 4);
    }
    piVar1 = (int *)(in_ECX + 4);
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      piVar5 = piVar1;
    }
    else {
      piVar5 = (undefined4 *)*piVar1;
    }
    puVar4 = (undefined4 *)(param_2 + param_1);
    for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *piVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      piVar5 = piVar5 + 1;
    }
    for (uVar2 = uVar3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)piVar5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      piVar5 = (undefined4 *)((int)piVar5 + 1);
    }
    *(uint *)(in_ECX + 0x14) = uVar3;
    if (0xf < *(uint *)(in_ECX + 0x18)) {
      piVar1 = (int *)*piVar1;
    }
    *(undefined1 *)((int)piVar1 + uVar3) = 0;
  }
  return;
}


// ==== FUN_00401740 @ 0x00401740 ====

void FUN_00401740(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(in_ECX + 0x18);
  if (uVar3 < 0x10) {
    puVar1 = (undefined4 *)(in_ECX + 4);
  }
  else {
    puVar1 = *(undefined4 **)(in_ECX + 4);
  }
  if (puVar1 <= param_1) {
    puVar1 = (undefined4 *)(in_ECX + 4);
    if (uVar3 < 0x10) {
      puVar2 = puVar1;
    }
    else {
      puVar2 = (undefined4 *)*puVar1;
    }
    if (param_1 < (undefined4 *)(*(int *)(in_ECX + 0x14) + (int)puVar2)) {
      if (0xf < uVar3) {
        puVar1 = (undefined4 *)*puVar1;
      }
      FUN_00401660(in_ECX,(int)param_1 - (int)puVar1,param_2);
      return;
    }
  }
  if (param_2 == 0xffffffff) {
    FUN_0079dbe3();
  }
  if (*(uint *)(in_ECX + 0x18) < param_2) {
    FUN_00401410(param_2,*(undefined4 *)(in_ECX + 0x14));
  }
  else if (param_2 == 0) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      *(undefined1 *)(in_ECX + 4) = 0;
      return;
    }
    **(undefined1 **)(in_ECX + 4) = 0;
    return;
  }
  if (param_2 != 0) {
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      puVar1 = (undefined4 *)(in_ECX + 4);
    }
    else {
      puVar1 = *(undefined4 **)(in_ECX + 4);
    }
    for (uVar3 = param_2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar1 = *param_1;
      param_1 = param_1 + 1;
      puVar1 = puVar1 + 1;
    }
    for (uVar3 = param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar1 = *(undefined1 *)param_1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      puVar1 = (undefined4 *)((int)puVar1 + 1);
    }
    *(uint *)(in_ECX + 0x14) = param_2;
    if (0xf < *(uint *)(in_ECX + 0x18)) {
      *(undefined1 *)(*(int *)(in_ECX + 4) + param_2) = 0;
      return;
    }
    *(undefined1 *)(in_ECX + 4 + param_2) = 0;
  }
  return;
}


// ==== FUN_00401830 @ 0x00401830 ====

void FUN_00401830(char *param_1)

{
  char cVar1;
  char *pcVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(param_1,(int)pcVar2 - (int)(param_1 + 1));
  return;
}


// ==== FUN_00401870 @ 0x00401870 ====

void FUN_00401870(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  FUN_00796e00();
  return;
}


// ==== FUN_00401ad0 @ 0x00401ad0 ====

void FUN_00401ad0(void)

{
  char cVar1;
  undefined4 uVar2;
  LPCSTR **lpFileName;
  HANDLE hFile;
  int iVar3;
  char *pcVar4;
  LPCVOID pvVar5;
  DWORD DVar6;
  uint uVar7;
  bool bVar8;
  DWORD DStack_60;
  uint uStack_5c;
  uint uStack_58;
  undefined1 local_54 [4];
  LPCSTR **local_50 [5];
  uint local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  uVar2 = FUN_00404890(local_1c,s_userdump_info_0099c6a8);
  uVar2 = FUN_004045b0(local_38,uVar2);
  FUN_00402220(local_54,uVar2);
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
  lpFileName = local_50[0];
  if (local_3c < 0x10) {
    lpFileName = (LPCSTR **)local_50;
  }
  hFile = CreateFileA((LPCSTR)lpFileName,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0)
  ;
  if (hFile == (HANDLE)0xffffffff) {
    bVar8 = local_3c < 0x10;
  }
  else {
    iVar3 = (**(code **)(*DAT_00b5a684 + 0x10))(1);
    if ((iVar3 == 0) && (iVar3 = (**(code **)(*DAT_00b5a684 + 0x10))(0), iVar3 == 0)) {
      pcVar4 = PTR_s_No_Message_00adb070;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      WriteFile(hFile,PTR_s_No_Message_00adb070,(int)pcVar4 - (int)(PTR_s_No_Message_00adb070 + 1),
                &uStack_58,(LPOVERLAPPED)0x0);
      CloseHandle(hFile);
      bVar8 = local_3c < 0x10;
    }
    else {
      if (DAT_00b5a6ac == (int *)0x0) {
        FUN_00401830(s_Crash_Tick_Unknown_0099c6d4);
        FUN_00796dd0(local_38);
        if (0xf < local_20) {
          local_18 = local_34;
          goto LAB_00401c35;
        }
      }
      else {
        (**(code **)(*DAT_00b5a6ac + 0x18))();
        FUN_00401830(s_Crash_Tick__u_0099c6c4);
        uVar2 = FUN_00797530(local_1c);
        FUN_00796dd0(uVar2);
        if (0xf < local_4) {
LAB_00401c35:
          _free(local_18);
          return;
        }
      }
      DStack_60 = (**(code **)(*DAT_00b5a684 + 0x10))(0);
      uStack_58 = (**(code **)(*DAT_00b5a684 + 0x10))(1);
      pcVar4 = PTR_s_<<_LOG_>>_00adb06c;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      WriteFile(hFile,PTR_s_<<_LOG_>>_00adb06c,(int)pcVar4 - (int)(PTR_s_<<_LOG_>>_00adb06c + 1),
                &DStack_60,(LPOVERLAPPED)0x0);
      uVar7 = 0;
      if (uStack_5c != 0) {
        do {
          pvVar5 = (LPCVOID)(**(code **)(*DAT_00b5a684 + 0x14))(0,uVar7);
          if (pvVar5 != (LPCVOID)0x0) {
            DVar6 = 0;
            do {
              if (*(char *)(DVar6 + (int)pvVar5) == '\0') goto LAB_00401cc3;
              DVar6 = DVar6 + 1;
            } while (DVar6 < 0x400);
            DVar6 = 0;
LAB_00401cc3:
            WriteFile(hFile,pvVar5,DVar6,&DStack_60,(LPOVERLAPPED)0x0);
            pcVar4 = PTR_DAT_00adb068;
            do {
              cVar1 = *pcVar4;
              pcVar4 = pcVar4 + 1;
            } while (cVar1 != '\0');
            WriteFile(hFile,PTR_DAT_00adb068,(int)pcVar4 - (int)(PTR_DAT_00adb068 + 1),&DStack_60,
                      (LPOVERLAPPED)0x0);
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uStack_5c);
      }
      pcVar4 = PTR_s_<<_MESSAGE_>>_00adb064;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      WriteFile(hFile,PTR_s_<<_MESSAGE_>>_00adb064,
                (int)pcVar4 - (int)(PTR_s_<<_MESSAGE_>>_00adb064 + 1),&DStack_60,(LPOVERLAPPED)0x0);
      uVar7 = 0;
      if (uStack_58 != 0) {
        do {
          pvVar5 = (LPCVOID)(**(code **)(*DAT_00b5a684 + 0x14))(1,uVar7);
          if (pvVar5 != (LPCVOID)0x0) {
            DVar6 = 0;
            do {
              if (*(char *)(DVar6 + (int)pvVar5) == '\0') goto LAB_00401d57;
              DVar6 = DVar6 + 1;
            } while (DVar6 < 0x400);
            DVar6 = 0;
LAB_00401d57:
            WriteFile(hFile,pvVar5,DVar6,&DStack_60,(LPOVERLAPPED)0x0);
            pcVar4 = PTR_DAT_00adb068;
            do {
              cVar1 = *pcVar4;
              pcVar4 = pcVar4 + 1;
            } while (cVar1 != '\0');
            WriteFile(hFile,PTR_DAT_00adb068,(int)pcVar4 - (int)(PTR_DAT_00adb068 + 1),&DStack_60,
                      (LPOVERLAPPED)0x0);
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uStack_58);
      }
      CloseHandle(hFile);
      bVar8 = local_3c < 0x10;
    }
  }
  if (!bVar8) {
    _free(local_50[0]);
    return;
  }
  return;
}


// ==== FUN_00401ff0 @ 0x00401ff0 ====

void FUN_00401ff0(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (*(uint *)(param_1 + 0x14) < param_2) {
    FUN_0079dba3();
  }
  uVar1 = *(int *)(param_1 + 0x14) - param_2;
  if (uVar1 < param_3) {
    param_3 = uVar1;
  }
  if (-*(int *)(in_ECX + 0x14) - 1U <= param_3) {
    FUN_0079dbe3();
  }
  if (param_3 != 0) {
    uVar1 = *(int *)(in_ECX + 0x14) + param_3;
    if (uVar1 == 0xffffffff) {
      FUN_0079dbe3();
    }
    if (*(uint *)(in_ECX + 0x18) < uVar1) {
      FUN_00401410(uVar1,*(undefined4 *)(in_ECX + 0x14));
    }
    else if (uVar1 == 0) {
      *(undefined4 *)(in_ECX + 0x14) = 0;
      if (*(uint *)(in_ECX + 0x18) < 0x10) {
        *(undefined1 *)(in_ECX + 4) = 0;
        return;
      }
      **(undefined1 **)(in_ECX + 4) = 0;
      return;
    }
    if (uVar1 != 0) {
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        param_1 = param_1 + 4;
      }
      else {
        param_1 = *(int *)(param_1 + 4);
      }
      puVar4 = (undefined4 *)(in_ECX + 4);
      if (*(uint *)(in_ECX + 0x18) < 0x10) {
        puVar2 = puVar4;
      }
      else {
        puVar2 = (undefined4 *)*puVar4;
      }
      puVar5 = (undefined4 *)(param_2 + param_1);
      puVar2 = (undefined4 *)(*(int *)(in_ECX + 0x14) + (int)puVar2);
      for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar2 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar2 = puVar2 + 1;
      }
      for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
        *(undefined1 *)puVar2 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar2 = (undefined4 *)((int)puVar2 + 1);
      }
      *(uint *)(in_ECX + 0x14) = uVar1;
      if (0xf < *(uint *)(in_ECX + 0x18)) {
        puVar4 = (undefined4 *)*puVar4;
      }
      *(undefined1 *)((int)puVar4 + uVar1) = 0;
    }
  }
  return;
}


// ==== FUN_004020e0 @ 0x004020e0 ====

void FUN_004020e0(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(in_ECX + 0x18);
  if (uVar5 < 0x10) {
    puVar1 = (undefined4 *)(in_ECX + 4);
  }
  else {
    puVar1 = *(undefined4 **)(in_ECX + 4);
  }
  if (puVar1 <= param_1) {
    puVar1 = (undefined4 *)(in_ECX + 4);
    if (uVar5 < 0x10) {
      puVar3 = puVar1;
    }
    else {
      puVar3 = (undefined4 *)*puVar1;
    }
    if (param_1 < (undefined4 *)(*(int *)(in_ECX + 0x14) + (int)puVar3)) {
      if (0xf < uVar5) {
        puVar1 = (undefined4 *)*puVar1;
      }
      FUN_00401ff0(in_ECX,(int)param_1 - (int)puVar1,param_2);
      return;
    }
  }
  if (-*(int *)(in_ECX + 0x14) - 1U <= param_2) {
    FUN_0079dbe3();
  }
  if (param_2 != 0) {
    uVar5 = *(int *)(in_ECX + 0x14) + param_2;
    if (uVar5 == 0xffffffff) {
      FUN_0079dbe3();
    }
    if (*(uint *)(in_ECX + 0x18) < uVar5) {
      FUN_00401410(uVar5,*(undefined4 *)(in_ECX + 0x14));
    }
    else if (uVar5 == 0) {
      *(undefined4 *)(in_ECX + 0x14) = 0;
      if (*(uint *)(in_ECX + 0x18) < 0x10) {
        *(undefined1 *)(in_ECX + 4) = 0;
        return;
      }
      **(undefined1 **)(in_ECX + 4) = 0;
      return;
    }
    if (uVar5 != 0) {
      if (*(uint *)(in_ECX + 0x18) < 0x10) {
        iVar2 = in_ECX + 4;
      }
      else {
        iVar2 = *(int *)(in_ECX + 4);
      }
      puVar1 = (undefined4 *)(*(int *)(in_ECX + 0x14) + iVar2);
      for (uVar4 = param_2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar1 = *param_1;
        param_1 = param_1 + 1;
        puVar1 = puVar1 + 1;
      }
      for (param_2 = param_2 & 3; param_2 != 0; param_2 = param_2 - 1) {
        *(undefined1 *)puVar1 = *(undefined1 *)param_1;
        param_1 = (undefined4 *)((int)param_1 + 1);
        puVar1 = (undefined4 *)((int)puVar1 + 1);
      }
      *(uint *)(in_ECX + 0x14) = uVar5;
      if (0xf < *(uint *)(in_ECX + 0x18)) {
        *(undefined1 *)(*(int *)(in_ECX + 4) + uVar5) = 0;
        return;
      }
      *(undefined1 *)(in_ECX + 4 + uVar5) = 0;
    }
  }
  return;
}


// ==== FUN_004021f0 @ 0x004021f0 ====

void FUN_004021f0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_004020e0(param_1,(int)pcVar2 - (int)(param_1 + 1));
  return;
}


// ==== FUN_00402220 @ 0x00402220 ====

/* WARNING: Removing unreachable block (ram,0x0040228a) */

int FUN_00402220(int param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  FUN_00401660(param_2,0,0xffffffff);
  pcVar2 = param_3;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar3 = FUN_004020e0(param_3,(int)pcVar2 - (int)(param_3 + 1));
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(uVar3,0,0xffffffff);
  return param_1;
}


// ==== FUN_004022a0 @ 0x004022a0 ====

/* WARNING: Removing unreachable block (ram,0x0040230a) */

int FUN_004022a0(int param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(param_2,(int)pcVar2 - (int)(param_2 + 1));
  uVar3 = FUN_00401ff0(param_3,0,0xffffffff);
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(uVar3,0,0xffffffff);
  return param_1;
}


// ==== FUN_00402320 @ 0x00402320 ====

void FUN_00402320(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0040232c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(in_ECX + 0x32c) + 4))();
  return;
}


// ==== FUN_00402330 @ 0x00402330 ====

void FUN_00402330(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x33c) = param_1;
  return;
}


// ==== FUN_00402340 @ 0x00402340 ====

void FUN_00402340(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x33c) == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00402351. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)**(undefined4 **)(in_ECX + 0x33c))();
  return;
}


// ==== FUN_00402380 @ 0x00402380 ====

void FUN_00402380(void)

{
  undefined4 uVar1;
  
  FUN_004067d0();
  uVar1 = (**(code **)(*DAT_00b5a6b0 + 8))();
  switch(uVar1) {
  case 0:
    FUN_008015fc(0,s_Korean_0099c770);
    return;
  case 1:
  case 4:
    FUN_008015fc(0,s_Chinese_0099c754);
    return;
  case 2:
    FUN_008015fc(0,s_Japanese_0099c75c);
    return;
  case 3:
    FUN_008015fc(0,s_English_0099c768);
    return;
  default:
    FUN_008015fc(0,s_English_0099c778);
    return;
  }
}


// ==== FUN_00402450 @ 0x00402450 ====

void FUN_00402450(void)

{
                    /* WARNING: Could not recover jumptable at 0x00402458. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a72c + 4))();
  return;
}


// ==== FUN_00402460 @ 0x00402460 ====

undefined4 FUN_00402460(void)

{
  int iVar1;
  BOOL BVar2;
  tagMSG local_1c;
  
  iVar1 = PeekMessageA(&local_1c,(HWND)0x0,0,0,0);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    BVar2 = GetMessageA(&local_1c,(HWND)0x0,0,0);
    if (BVar2 == 0) break;
    iVar1 = TranslateAccelerator(local_1c.hwnd,0,&local_1c);
    if (iVar1 == 0) {
      TranslateMessage(&local_1c);
      DispatchMessageA(&local_1c);
    }
    iVar1 = PeekMessageA(&local_1c,(HWND)0x0,0,0,0);
  }
  return 1;
}


// ==== FUN_00402500 @ 0x00402500 ====

void FUN_00402500(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x33c) = 0;
  return;
}


// ==== FUN_00402530 @ 0x00402530 ====

LRESULT FUN_00402530(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  undefined4 *puVar1;
  char cVar2;
  LRESULT LVar3;
  int in_ECX;
  undefined4 *puVar4;
  UINT local_c;
  WPARAM local_8;
  LPARAM local_4;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x34c);
  for (puVar4 = *(undefined4 **)(in_ECX + 0x348); puVar4 != puVar1; puVar4 = puVar4 + 1) {
    cVar2 = (*(code *)**(undefined4 **)*puVar4)(param_2,param_3,param_4);
    if (cVar2 != '\0') {
      return 0;
    }
  }
  if (*(int **)(in_ECX + 0x380) != (int *)0x0) {
    local_4 = param_4;
    local_c = param_2;
    local_8 = param_3;
    cVar2 = (**(code **)(**(int **)(in_ECX + 0x380) + 0x14))(&local_c);
    if (cVar2 != '\0') {
      return 0;
    }
  }
  if (param_2 == 2) {
    PostQuitMessage(0);
    return 0;
  }
  if (param_2 == 0x1c) {
    *(bool *)(in_ECX + 0x390) = param_3 == 1;
  }
  LVar3 = DefWindowProcA(param_1,param_2,param_3,param_4);
  return LVar3;
}


// ==== FUN_004025f0 @ 0x004025f0 ====

void FUN_004025f0(int param_1)

{
  int *_Dst;
  int in_ECX;
  
  _Dst = *(int **)(in_ECX + 0x348);
  if (_Dst != *(int **)(in_ECX + 0x34c)) {
    while (*_Dst != param_1) {
      _Dst = _Dst + 1;
      if (_Dst == *(int **)(in_ECX + 0x34c)) {
        return;
      }
    }
    _memmove(_Dst,_Dst + 1,(*(int *)(in_ECX + 0x34c) - (int)(_Dst + 1) >> 2) * 4);
    *(int *)(in_ECX + 0x34c) = *(int *)(in_ECX + 0x34c) + -4;
  }
  return;
}


// ==== FUN_00402640 @ 0x00402640 ====

HWND FUN_00402640(HINSTANCE param_1)

{
  DWORD DVar1;
  code *pcVar2;
  BOOL BVar3;
  HWND extraout_EAX;
  HWND pHVar4;
  LONG LVar5;
  HWND extraout_EAX_00;
  DWORD DVar6;
  HWND extraout_EAX_01;
  HWND extraout_EAX_02;
  HWND extraout_EAX_03;
  int iVar7;
  LPCSTR ****lpWindowName;
  int iVar8;
  DWORD DVar9;
  DEVMODEA *pDVar10;
  tagRECT tStack_210;
  DWORD DStack_200;
  int iStack_1fc;
  DWORD DStack_1f8;
  int iStack_1f4;
  LPCSTR ****apppppCStack_1ec [4];
  undefined4 uStack_1dc;
  uint uStack_1d8;
  undefined1 auStack_1d4 [4];
  void *pvStack_1d0;
  undefined4 uStack_1c0;
  uint uStack_1bc;
  WNDCLASSA WStack_1b8;
  undefined1 auStack_190 [4];
  void *pvStack_18c;
  undefined4 uStack_17c;
  uint uStack_178;
  undefined1 auStack_174 [4];
  void *pvStack_170;
  undefined4 uStack_160;
  uint uStack_15c;
  DEVMODEA DStack_158;
  DEVMODEA DStack_b8;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00977b27;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  iStack_1fc = (**(code **)(*DAT_00b5a6e4 + 8))();
  DStack_1f8 = *(DWORD *)(iStack_1fc + 0x54);
  DVar1 = *(DWORD *)(iStack_1fc + 0x50);
  DStack_200 = DVar1;
  iStack_1f4 = (**(code **)(*DAT_00b5a6b0 + 8))();
  if (iStack_1f4 == 1) {
    pDVar10 = &DStack_158;
    for (iVar7 = 0x27; iVar7 != 0; iVar7 = iVar7 + -1) {
      pDVar10->dmDeviceName[0] = '\0';
      pDVar10->dmDeviceName[1] = '\0';
      pDVar10->dmDeviceName[2] = '\0';
      pDVar10->dmDeviceName[3] = '\0';
      pDVar10 = (DEVMODEA *)(pDVar10->dmDeviceName + 4);
    }
    BVar3 = EnumDisplaySettingsA((LPCSTR)0x0,0xffffffff,&DStack_158);
    if (BVar3 == 0) {
      uStack_1bc = 0xf;
      uStack_1c0 = 0;
      pvStack_1d0 = (void *)((uint)pvStack_1d0 & 0xffffff00);
      FUN_00401740(s_EnumDisplaySettings__NULL__ENUM__0099c7c8,0x3f);
      uStack_c = 0;
      FUN_00406880(auStack_1d4);
      uStack_c = 0xffffffff;
      if (uStack_1bc < 0x10) {
        pcVar2 = (code *)swi(3);
        pHVar4 = (HWND)(*pcVar2)();
        return pHVar4;
      }
      _free(pvStack_1d0);
      return extraout_EAX;
    }
    DStack_158.dmPelsHeight = DStack_1f8;
    DStack_158.dmPelsWidth = DVar1;
    LVar5 = ChangeDisplaySettingsA(&DStack_158,4);
    if (LVar5 != 0) {
      uStack_1bc = 0xf;
      uStack_1c0 = 0;
      pvStack_1d0 = (void *)((uint)pvStack_1d0 & 0xffffff00);
      FUN_00401740(s_ChangeDisplaySettings___dmSettin_0099c808,0x4e);
      uStack_c = 1;
      FUN_00406880(auStack_1d4);
      uStack_c = 0xffffffff;
      if (uStack_1bc < 0x10) {
        pcVar2 = (code *)swi(3);
        pHVar4 = (HWND)(*pcVar2)();
        return pHVar4;
      }
      _free(pvStack_1d0);
      return extraout_EAX_00;
    }
  }
  WStack_1b8.style = 0;
  WStack_1b8.lpfnWndProc = (WNDPROC)&LAB_00402510;
  WStack_1b8.cbClsExtra = 0;
  WStack_1b8.cbWndExtra = 0;
  WStack_1b8.hInstance = param_1;
  WStack_1b8.hIcon = LoadIconA(param_1,(LPCSTR)0x83);
  WStack_1b8.hCursor = (HCURSOR)0x0;
  WStack_1b8.hbrBackground = GetStockObject(2);
  WStack_1b8.lpszMenuName = (LPCSTR)0x0;
  WStack_1b8.lpszClassName = s_Renderer_0099c858;
  RegisterClassA(&WStack_1b8);
  iVar7 = GetSystemMetrics(0);
  iVar8 = (int)(iVar7 - DVar1) / 2;
  iVar7 = GetSystemMetrics(1);
  DVar1 = DStack_1f8;
  tStack_210.top = (int)(iVar7 - DStack_1f8) / 2;
  tStack_210.right = iVar8 + DStack_200;
  tStack_210.bottom = tStack_210.top + DStack_1f8;
  DVar9 = 0x10ca0000;
  uStack_1d8 = 0xf;
  uStack_1dc = 0;
  apppppCStack_1ec[0] = (LPCSTR ****)((uint)apppppCStack_1ec[0] & 0xffffff00);
  tStack_210.left = iVar8;
  FUN_00401740(s_Dekaron_0099c864,7);
  uStack_c = 2;
  switch(iStack_1f4) {
  case 1:
    SetRect(&tStack_210,0,0,DStack_200,DVar1);
    break;
  case 2:
  case 4:
    if (*(char *)(iStack_1fc + 5) != '\0') {
      SetRect(&tStack_210,0,0,DStack_200,DVar1);
      DVar9 = 0x92000000;
    }
    break;
  case 3:
    FUN_00401740(s_2Moons_0099c86c,6);
  }
  DVar6 = GetSystemMetrics(1);
  if (DVar6 != DVar1) {
    AdjustWindowRect(&tStack_210,DVar9,0);
  }
  lpWindowName = apppppCStack_1ec[0];
  if (uStack_1d8 < 0x10) {
    lpWindowName = (LPCSTR ****)apppppCStack_1ec;
  }
  pHVar4 = CreateWindowExA(0,s_Renderer_0099c874,(LPCSTR)lpWindowName,DVar9,tStack_210.left,
                           tStack_210.top,tStack_210.right - tStack_210.left,
                           tStack_210.bottom - tStack_210.top,(HWND)0x0,(HMENU)0x0,param_1,
                           (LPVOID)0x0);
  if (iStack_1f4 == 1) {
LAB_0040294d:
    SetWindowLongA(pHVar4,-0x10,-0x6ff80000);
  }
  else {
    if ((iStack_1f4 != 2) && (iStack_1f4 != 4)) {
      if ((*(char *)(iStack_1fc + 5) == '\0') && (DVar6 = GetSystemMetrics(1), DVar6 != DVar1)) {
        SetWindowLongA(pHVar4,-0x10,DVar9);
        goto LAB_00402967;
      }
      goto LAB_0040294d;
    }
    if (*(char *)(iStack_1fc + 5) == '\0') {
      SetWindowLongA(pHVar4,-0x10,DVar9);
      goto LAB_00402967;
    }
    pDVar10 = &DStack_b8;
    for (iVar7 = 0x27; iVar7 != 0; iVar7 = iVar7 + -1) {
      pDVar10->dmDeviceName[0] = '\0';
      pDVar10->dmDeviceName[1] = '\0';
      pDVar10->dmDeviceName[2] = '\0';
      pDVar10->dmDeviceName[3] = '\0';
      pDVar10 = (DEVMODEA *)(pDVar10->dmDeviceName + 4);
    }
    BVar3 = EnumDisplaySettingsA((LPCSTR)0x0,0xffffffff,&DStack_b8);
    DVar9 = DStack_1f8;
    DVar1 = DStack_200;
    if (BVar3 == 0) {
      FUN_00401830(s_EnumDisplaySettings__NULL__ENUM__0099c880);
      uStack_c._0_1_ = 3;
      FUN_00406880(auStack_190);
      uStack_c = CONCAT31(uStack_c._1_3_,2);
      if (uStack_178 < 0x10) {
        uStack_178 = 0xf;
        uStack_17c = 0;
        pvStack_18c = (void *)((uint)pvStack_18c & 0xffffff00);
        pcVar2 = (code *)swi(3);
        pHVar4 = (HWND)(*pcVar2)();
        return pHVar4;
      }
      _free(pvStack_18c);
      return extraout_EAX_02;
    }
    DStack_b8.dmPelsWidth = DStack_200;
    DStack_b8.dmPelsHeight = DStack_1f8;
    LVar5 = ChangeDisplaySettingsA(&DStack_b8,4);
    if (LVar5 != 0) {
      FUN_00401830(s_ChangeDisplaySettings___dmSettin_0099c8c0);
      uStack_c = CONCAT31(uStack_c._1_3_,4);
      FUN_00406880(auStack_174);
      if (uStack_15c < 0x10) {
        uStack_15c = 0xf;
        uStack_160 = 0;
        pvStack_170 = (void *)((uint)pvStack_170 & 0xffffff00);
        pcVar2 = (code *)swi(3);
        pHVar4 = (HWND)(*pcVar2)();
        return pHVar4;
      }
      _free(pvStack_170);
      return extraout_EAX_03;
    }
    SetRect(&tStack_210,0,0,DVar1,DVar9);
    SetWindowLongA(pHVar4,-0x10,-0x6ff80000);
  }
  SetMenu(pHVar4,(HMENU)0x0);
LAB_00402967:
  if (uStack_1d8 < 0x10) {
    ExceptionList = pvStack_14;
    return pHVar4;
  }
  _free(apppppCStack_1ec[0]);
  return extraout_EAX_01;
}


// ==== FUN_00402b00 @ 0x00402b00 ====

void FUN_00402b00(void)

{
  int in_ECX;
  
  FUN_00401660(in_ECX + 0x354,0,0xffffffff);
  return;
}


// ==== FUN_00402b20 @ 0x00402b20 ====

void FUN_00402b20(undefined4 param_1)

{
  FUN_00401660(param_1,0,0xffffffff);
  return;
}


// ==== FUN_00402b40 @ 0x00402b40 ====

void FUN_00402b40(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00977b8a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099ca04;
  local_4 = 6;
  if ((undefined4 *)in_ECX[0xe2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xe2])(1);
  }
  in_ECX[0xe2] = 0;
  if ((undefined4 *)in_ECX[0xe3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xe3])(1);
  }
  in_ECX[0xe3] = 0;
  if ((undefined4 *)in_ECX[0xe1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xe1])(1);
  }
  in_ECX[0xe1] = 0;
  RemoveFontResourceA(s_WebUlnw10_ttf_0099c744);
  FUN_0040d010();
  FUN_0040cf90();
  FUN_004067b0();
  FUN_0040ce60();
  FUN_0040ce40();
  FUN_0040cdd0();
  FUN_0040cd60();
  if ((undefined4 *)in_ECX[0xdd] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xdd])(1);
  }
  in_ECX[0xdd] = 0;
  if ((undefined4 *)in_ECX[0xdc] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xdc])(1);
  }
  in_ECX[0xdc] = 0;
  if ((undefined4 *)in_ECX[0xd0] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xd0])(1);
  }
  in_ECX[0xd0] = 0;
  if ((undefined4 *)in_ECX[0xde] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xde])(1);
  }
  in_ECX[0xde] = 0;
  if ((undefined4 *)in_ECX[0xdf] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xdf])(1);
  }
  in_ECX[0xdf] = 0;
  if ((undefined4 *)in_ECX[0xe0] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xe0])(1);
  }
  in_ECX[0xe0] = 0;
  FUN_0040cce0();
  FUN_00408e00();
  FUN_00797950();
  FUN_0040cb00();
  FUN_0040b860();
  _Memory = DAT_00b5a7d4;
  if (DAT_00b5a7d4 != (void *)0x0) {
    FUN_00815880();
    _free(_Memory);
    return;
  }
  if (0xf < (uint)in_ECX[0xdb]) {
    _free((void *)in_ECX[0xd6]);
    return;
  }
  in_ECX[0xdb] = 0xf;
  in_ECX[0xda] = 0;
  *(undefined1 *)(in_ECX + 0xd6) = 0;
  if ((void *)in_ECX[0xd2] == (void *)0x0) {
    in_ECX[0xd2] = 0;
    in_ECX[0xd3] = 0;
    in_ECX[0xd4] = 0;
    local_4._0_1_ = 3;
    FUN_0040a380();
    local_4._0_1_ = 2;
    FUN_00409ab0();
    local_4._0_1_ = 1;
    FUN_00408f60();
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_00406fc0();
    local_4 = 0xffffffff;
    *in_ECX = &PTR_FUN_0099c9b4;
    FUN_00403840();
    ExceptionList = pvStack_c;
    return;
  }
  _free((void *)in_ECX[0xd2]);
  return;
}


// ==== FUN_00402d60 @ 0x00402d60 ====

void FUN_00402d60(void)

{
  undefined4 uVar1;
  LPCSTR ***lpApplicationName;
  int iVar2;
  _STARTUPINFOA *p_Var3;
  _PROCESS_INFORMATION local_ec;
  LPCSTR ***local_d8 [4];
  undefined4 local_c8;
  uint local_c4;
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
  uint local_54;
  _STARTUPINFOA local_50;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00977bc8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  Sleep(1000);
  p_Var3 = &local_50;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    p_Var3->cb = 0;
    p_Var3 = (_STARTUPINFOA *)&p_Var3->lpReserved;
  }
  local_ec.hProcess = (HANDLE)0x0;
  local_ec.hThread = (HANDLE)0x0;
  local_ec.dwProcessId = 0;
  local_50.cb = 0x44;
  local_ec.dwThreadId = 0;
  local_c4 = 0xf;
  local_c8 = 0;
  local_d8[0] = (LPCSTR ***)((uint)local_d8[0] & 0xffffff00);
  local_4 = 0;
  uVar1 = FUN_00404890(local_6c);
  local_4._0_1_ = 1;
  uVar1 = FUN_004045b0(local_a4,uVar1);
  local_4._0_1_ = 2;
  uVar1 = FUN_004046f0(local_c0,uVar1);
  local_4._0_1_ = 3;
  uVar1 = FUN_00402220(local_88,uVar1,s_MiniLauncher_exe_0099c910);
  local_4 = CONCAT31(local_4._1_3_,4);
  FUN_00401660(uVar1,0,0xffffffff);
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
  local_a8 = 0xf;
  local_ac = 0;
  local_bc = (void *)((uint)local_bc & 0xffffff00);
  if (0xf < local_8c) {
    _free(local_a0);
    return;
  }
  local_8c = 0xf;
  local_90 = 0;
  local_a0 = (void *)((uint)local_a0 & 0xffffff00);
  if (0xf < local_54) {
    _free(local_68);
    return;
  }
  lpApplicationName = local_d8[0];
  if (local_c4 < 0x10) {
    lpApplicationName = (LPCSTR ***)local_d8;
  }
  CreateProcessA((LPCSTR)lpApplicationName,(LPSTR)0x0,(LPSECURITY_ATTRIBUTES)0x0,
                 (LPSECURITY_ATTRIBUTES)0x0,0,0x20,(LPVOID)0x0,(LPCSTR)0x0,&local_50,&local_ec);
  CloseHandle(local_ec.hProcess);
  CloseHandle(local_ec.hThread);
  PostQuitMessage(0);
  if (local_c4 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_d8[0]);
  return;
}


// ==== FUN_00402f30 @ 0x00402f30 ====

/* WARNING: Removing unreachable block (ram,0x00402f99) */

void FUN_00402f30(void)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  char *pcVar4;
  int *in_ECX;
  void *pvStack_74;
  void *pvStack_6c;
  uint uStack_60;
  uint uStack_58;
  undefined4 uStack_54;
  void *pvStack_50;
  undefined4 uStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  void *local_28;
  undefined4 uStack_20;
  undefined1 uStack_1c;
  undefined1 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00977c70;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = 0;
  FUN_00401870();
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_0040cc30();
  FUN_007977f0();
  FUN_0040cba0();
  FUN_00409980();
  FUN_00408df0();
  FUN_0040ce80();
  FUN_0040cdf0();
  (**(code **)(*DAT_00b5a6d4 + 4))();
  FUN_0040cd80();
  cVar1 = (**(code **)(*DAT_00b5a6d4 + 4))();
  if (cVar1 != '\x01') {
    FUN_00402d60();
                    /* WARNING: Subroutine does not return */
    ExitProcess(0);
  }
  cVar1 = (**(code **)(*DAT_00b5a6d4 + 0x18))();
  if (cVar1 == '\0') {
    pvVar2 = operator_new(1);
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,4);
    if (pvVar2 == (void *)0x0) goto LAB_004030b0;
    iVar3 = (**(code **)(*DAT_00b5a6d0 + 4))();
    if (0xf < *(uint *)(iVar3 + 0x18)) {
      FUN_00815730();
      goto LAB_004030b2;
    }
  }
  else {
    pvVar2 = operator_new(1);
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
    if (pvVar2 == (void *)0x0) {
LAB_004030b0:
      pvVar2 = (void *)0x0;
      goto LAB_004030b2;
    }
    iVar3 = (**(code **)(*DAT_00b5a6d0 + 4))();
    if (0xf < *(uint *)(iVar3 + 0x18)) {
      FUN_00815730();
      goto LAB_004030b2;
    }
  }
  FUN_00815730();
LAB_004030b2:
  pvStack_c._0_1_ = 2;
  DAT_00b5a7d4 = pvVar2;
  cVar1 = FUN_0040b4c0();
  if (cVar1 == '\0') {
                    /* WARNING: Subroutine does not return */
    ExitProcess(0);
  }
  FUN_00401740();
  FUN_00407a20();
  pvStack_50 = (void *)0xf;
  uStack_54 = 0;
  pcVar4 = PTR_s_PackIO_00adb08c;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00401740();
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,5);
  (**(code **)(in_ECX[2] + 8))();
  uStack_14 = 6;
  iVar3 = FUN_00403620();
  if (0xf < uStack_3c) {
    _free(pvStack_50);
    return;
  }
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
  uStack_14 = 2;
  if (0xf < uStack_58) {
    _free(pvStack_6c);
    return;
  }
  if (iVar3 != 0) {
    (**(code **)(*DAT_00b5a740 + 0x10))();
  }
  FUN_0049d720();
  (**(code **)(*in_ECX + 0x48))();
  FUN_00402640();
  FUN_00815710();
  AddFontResourceA(s_WebUlnw10_ttf_0099c7ac);
  pcVar4 = PTR_s_WindowHandle_00adb088;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00401740();
  uStack_14 = 7;
  FUN_00401740(&DAT_0099c7bc,2);
  FUN_00404230(&uStack_54);
  uStack_14 = 8;
  (**(code **)(in_ECX[2] + 0x10))();
  if (0xf < uStack_44) {
    _free((void *)0xf);
    return;
  }
  uStack_44 = 0xf;
  uStack_48 = 0;
  uStack_1c = 2;
  if (0xf < uStack_60) {
    _free(pvStack_74);
    return;
  }
  FUN_0040cf30();
  FUN_0040cfb0();
  FUN_0040cd10();
  pvVar2 = operator_new(0x14);
  uStack_1c = 9;
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_0040fc50();
  }
  uStack_1c = 2;
  in_ECX[0xe0] = iVar3;
  pvVar2 = operator_new(4);
  uStack_1c = 10;
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_00459290();
  }
  uStack_1c = 2;
  in_ECX[0xdf] = iVar3;
  iVar3 = FUN_0054a070();
  in_ECX[0xd0] = iVar3;
  pvVar2 = operator_new(0x10);
  uStack_1c = 0xb;
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_00589940();
  }
  uStack_1c = 2;
  in_ECX[0xde] = iVar3;
  pvVar2 = operator_new(0x3c);
  uStack_1c = 0xc;
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_0044a090();
  }
  uStack_1c = 2;
  in_ECX[0xdd] = iVar3;
  pvVar2 = operator_new(0xc);
  uStack_1c = 0xd;
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_0054bab0();
  }
  in_ECX[0xdc] = iVar3;
  uStack_1c = 2;
  (**(code **)(*DAT_00b5a718 + 4))();
  (**(code **)(*DAT_00b5a6ac + 0x18))();
  thunk_FUN_00801d2d();
  FUN_00401740();
  pvVar2 = operator_new(0xc);
  uStack_20._0_1_ = 0xe;
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_0049b950();
  }
  uStack_20._0_1_ = 2;
  in_ECX[0xe1] = iVar3;
  pvVar2 = operator_new(8);
  uStack_20._0_1_ = 0xf;
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_005de6d0();
  }
  uStack_20._0_1_ = 2;
  in_ECX[0xe2] = iVar3;
  pvVar2 = operator_new(8);
  uStack_20 = CONCAT31(uStack_20._1_3_,0x10);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_0046d5f0();
  }
  in_ECX[0xe3] = iVar3;
  uStack_20 = 0xffffffff;
  FUN_00401630();
  ExceptionList = local_28;
  return;
}


// ==== FUN_004034e0 @ 0x004034e0 ====

void FUN_004034e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00977cd3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004039f0();
  local_4 = 0;
  *in_ECX = &PTR_FUN_0099ca04;
  FUN_004079a0();
  local_4._0_1_ = 1;
  FUN_00409100();
  local_4._0_1_ = 2;
  FUN_00409b70();
  local_4._0_1_ = 3;
  FUN_0040a420();
  in_ECX[0xcf] = 0;
  in_ECX[0xd0] = 0;
  in_ECX[0xd2] = 0;
  in_ECX[0xd3] = 0;
  in_ECX[0xd4] = 0;
  in_ECX[0xdb] = 0xf;
  in_ECX[0xda] = 0;
  *(undefined1 *)(in_ECX + 0xd6) = 0;
  local_4 = CONCAT31(local_4._1_3_,6);
  in_ECX[0xdc] = 0;
  in_ECX[0xdd] = 0;
  in_ECX[0xe0] = 0;
  *(undefined1 *)(in_ECX + 0xe4) = 1;
  FUN_0040b820();
  ExceptionList = local_c;
  return;
}


// ==== FUN_004035c0 @ 0x004035c0 ====

void FUN_004035c0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x348);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x350) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x34c) - iVar1 >> 2)
     )) {
    FUN_00403b10(*(undefined4 *)(in_ECX + 0x34c),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x34c);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0x34c) = puVar2 + 1;
  return;
}


// ==== FUN_00403620 @ 0x00403620 ====

uint FUN_00403620(uint param_1,uint param_2,byte *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  
  if (*(uint *)(in_ECX + 0x14) < param_1) {
    FUN_0079dba3();
  }
  uVar1 = *(int *)(in_ECX + 0x14) - param_1;
  if (uVar1 < param_2) {
    param_2 = uVar1;
  }
  if (param_2 != 0) {
    uVar1 = param_2;
    if (param_4 <= param_2) {
      uVar1 = param_4;
    }
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      iVar2 = in_ECX + 4;
    }
    else {
      iVar2 = *(int *)(in_ECX + 4);
    }
    bVar5 = false;
    uVar3 = 0;
    bVar6 = true;
    pbVar4 = (byte *)(iVar2 + param_1);
    do {
      if (uVar1 == 0) break;
      uVar1 = uVar1 - 1;
      bVar5 = *pbVar4 < *param_3;
      bVar6 = *pbVar4 == *param_3;
      pbVar4 = pbVar4 + 1;
      param_3 = param_3 + 1;
    } while (bVar6);
    if (!bVar6) {
      uVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
    }
    if (uVar3 != 0) {
      return uVar3;
    }
  }
  if (param_2 < param_4) {
    return 0xffffffff;
  }
  return (uint)(param_2 != param_4);
}


// ==== FUN_004036a0 @ 0x004036a0 ====

bool FUN_004036a0(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),param_2,(int)pcVar2 - (int)(param_2 + 1));
  return iVar3 == 0;
}


// ==== FUN_004036e0 @ 0x004036e0 ====

bool FUN_004036e0(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),param_2,(int)pcVar2 - (int)(param_2 + 1));
  return iVar3 != 0;
}


// ==== FUN_00403720 @ 0x00403720 ====

void FUN_00403720(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_00403740 @ 0x00403740 ====

int FUN_00403740(void)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x24) < 0x10) {
    return in_ECX + 0x10;
  }
  return *(int *)(in_ECX + 0x10);
}


// ==== FUN_00403750 @ 0x00403750 ====

void FUN_00403750(byte param_1)

{
  void *in_ECX;
  
  FUN_004037d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00403770 @ 0x00403770 ====

void FUN_00403770(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00977ab8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00801756();
  *in_ECX = &PTR_FUN_0099c980;
  in_ECX[8] = 0;
  in_ECX[9] = 0xf;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004037d0 @ 0x004037d0 ====

void FUN_004037d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099c980;
  if ((uint)in_ECX[9] < 0x10) {
    in_ECX[9] = 0xf;
    in_ECX[8] = 0;
    *(undefined1 *)(in_ECX + 4) = 0;
    FUN_00801801();
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_00403810 @ 0x00403810 ====

void FUN_00403810(char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(param_1,(int)pcVar2 - (int)(param_1 + 1));
  return;
}


// ==== FUN_00403840 @ 0x00403840 ====

void FUN_00403840(void)

{
  code *pcVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00977ad8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099c998;
  if (DAT_00b5a688 != 0) {
    DAT_00b5a688 = 0;
    ExceptionList = pvVar2;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_I_ms_pInstance_0099c96a + 2,0xc);
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


// ==== FUN_004038d0 @ 0x004038d0 ====

void FUN_004038d0(byte param_1)

{
  void *in_ECX;
  
  FUN_00403840();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004038f0 @ 0x004038f0 ====

void FUN_004038f0(void)

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
  puStack_8 = &LAB_00977ce8;
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


// ==== FUN_00403960 @ 0x00403960 ====

void FUN_00403960(int param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00977ab8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_008017af(param_1);
  *in_ECX = &PTR_FUN_0099c980;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1 + 0xc,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004039d0 @ 0x004039d0 ====

void FUN_004039d0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_00403960(param_1);
  *in_ECX = &PTR_FUN_0099c98c;
  return;
}


// ==== FUN_004039f0 @ 0x004039f0 ====

void FUN_004039f0(void)

{
  code *pcVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00977ad8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099c998;
  if (DAT_00b5a688 == (undefined4 *)0x0) {
    DAT_00b5a688 = in_ECX;
    ExceptionList = pvVar2;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_ms_pInstance____NULL_0099c924,0x14);
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


// ==== FUN_00403a90 @ 0x00403a90 ====

void FUN_00403a90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099c9b4;
  FUN_00403840();
  return;
}


// ==== FUN_00403aa0 @ 0x00403aa0 ====

void FUN_00403aa0(byte param_1)

{
  void *in_ECX;
  
  FUN_00403a90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00403ac0 @ 0x00403ac0 ====

int FUN_00403ac0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00403ad0 @ 0x00403ad0 ====

int FUN_00403ad0(void)

{
  int in_ECX;
  
  return in_ECX + 0x2d4;
}


// ==== FUN_00403ae0 @ 0x00403ae0 ====

int FUN_00403ae0(void)

{
  int in_ECX;
  
  return in_ECX + 0x31c;
}


// ==== FUN_00403af0 @ 0x00403af0 ====

int FUN_00403af0(void)

{
  int in_ECX;
  
  return in_ECX + 0x32c;
}


// ==== FUN_00403b00 @ 0x00403b00 ====

undefined1 FUN_00403b00(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x390);
}


// ==== FUN_00403b10 @ 0x00403b10 ====

void FUN_00403b10(void *param_1,uint param_2,undefined4 *param_3)

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
      uVar7 = FUN_004038f0();
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


// ==== FUN_00403cf0 @ 0x00403cf0 ====

void FUN_00403cf0(byte param_1)

{
  void *in_ECX;
  
  FUN_00402b40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00403d10 @ 0x00403d10 ====

bool FUN_00403d10(int param_1)

{
  int iVar1;
  
  iVar1 = _isalpha(param_1);
  return iVar1 != 0;
}


// ==== FUN_00403d30 @ 0x00403d30 ====

bool FUN_00403d30(int param_1)

{
  int iVar1;
  
  iVar1 = _isdigit(param_1);
  return iVar1 != 0;
}


// ==== FUN_00403d50 @ 0x00403d50 ====

bool FUN_00403d50(int param_1)

{
  int iVar1;
  
  iVar1 = _isalnum(param_1);
  return iVar1 != 0;
}


// ==== FUN_00403d70 @ 0x00403d70 ====

bool FUN_00403d70(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00801bcb(param_1);
  return iVar1 != 0;
}


// ==== FUN_00403d90 @ 0x00403d90 ====

bool FUN_00403d90(int param_1)

{
  int iVar1;
  
  iVar1 = _isgraph(param_1);
  return iVar1 != 0;
}


// ==== FUN_00403e50 @ 0x00403e50 ====

void FUN_00403e50(void)

{
  return;
}


// ==== FUN_00403e60 @ 0x00403e60 ====

void FUN_00403e60(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  return;
}


// ==== FUN_00403ea0 @ 0x00403ea0 ====

void FUN_00403ea0(undefined4 *param_1,undefined1 param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
    param_1 = param_1 + 1;
  }
  for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
    *(undefined1 *)param_1 = param_2;
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  return;
}


// ==== FUN_00403f60 @ 0x00403f60 ====

undefined4 FUN_00403f60(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  
  uVar2 = *(uint *)(param_1 + 0x14);
  uVar3 = 0;
  if (0 < (int)uVar2) {
    bVar4 = false;
    bVar5 = uVar2 == 0;
    do {
      if (bVar4 || bVar5) {
        FUN_0079dba3();
      }
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        iVar1 = param_1 + 4;
      }
      else {
        iVar1 = *(int *)(param_1 + 4);
      }
      iVar1 = _isdigit((int)*(char *)(iVar1 + uVar3));
      if (iVar1 == 0) {
        return 0;
      }
      uVar2 = *(uint *)(param_1 + 0x14);
      uVar3 = uVar3 + 1;
      bVar4 = uVar2 < uVar3;
      bVar5 = uVar2 == uVar3;
    } while (!bVar5 && (int)uVar3 <= (int)uVar2);
  }
  return CONCAT31((int3)(uVar2 >> 8),1);
}


// ==== FUN_00403fb0 @ 0x00403fb0 ====

uint FUN_00403fb0(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint local_8;
  uint local_4;
  
  uVar3 = *(uint *)(param_2 + 0x14);
  if (uVar3 == 0) {
    return 0xffffffff;
  }
  uVar7 = *(uint *)(param_1 + 0x14);
  if ((uVar7 == 0) || (uVar7 < uVar3)) {
    return 0xffffffff;
  }
  local_8 = 0;
  if (uVar7 - uVar3 != -1) {
    local_4 = 1;
    do {
      if (uVar7 <= local_8) {
        FUN_0079dba3();
      }
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        iVar1 = param_1 + 4;
      }
      else {
        iVar1 = *(int *)(param_1 + 4);
      }
      iVar1 = FUN_00801bcb((int)*(char *)(iVar1 + local_8));
      if (*(uint *)(param_1 + 0x14) <= local_8) {
        FUN_0079dba3();
      }
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        iVar5 = param_1 + 4;
      }
      else {
        iVar5 = *(int *)(param_1 + 4);
      }
      if (*(int *)(param_2 + 0x14) == 0) {
        FUN_0079dba3();
      }
      if (*(uint *)(param_2 + 0x18) < 0x10) {
        pcVar2 = (char *)(param_2 + 4);
      }
      else {
        pcVar2 = *(char **)(param_2 + 4);
      }
      if (*(char *)(iVar5 + local_8) == *pcVar2) {
        uVar3 = *(uint *)(param_1 + 0x14);
        if (uVar3 <= local_4) {
          return local_8;
        }
        uVar6 = local_4 - local_8;
        uVar7 = local_4;
        while( true ) {
          if (*(uint *)(param_2 + 0x14) <= uVar6) {
            return local_8;
          }
          if (uVar3 <= uVar7) {
            FUN_0079dba3();
          }
          if (*(uint *)(param_1 + 0x18) < 0x10) {
            iVar5 = param_1 + 4;
          }
          else {
            iVar5 = *(int *)(param_1 + 4);
          }
          if (*(uint *)(param_2 + 0x14) <= uVar6) {
            FUN_0079dba3();
          }
          puVar4 = (undefined4 *)(param_2 + 4);
          if (0xf < *(uint *)(param_2 + 0x18)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          if (*(char *)(uVar7 + iVar5) != *(char *)(uVar6 + (int)puVar4)) break;
          uVar3 = *(uint *)(param_1 + 0x14);
          uVar7 = uVar7 + 1;
          uVar6 = uVar6 + 1;
          if (uVar3 <= uVar7) {
            return local_8;
          }
        }
        if (iVar1 != 0) {
          local_8 = local_8 + 1;
          local_4 = local_4 + 1;
        }
      }
      else if (iVar1 != 0) {
        local_8 = local_8 + 1;
        local_4 = local_4 + 1;
      }
      uVar7 = *(uint *)(param_1 + 0x14);
      local_8 = local_8 + 1;
      local_4 = local_4 + 1;
    } while (local_8 < (uVar7 - *(int *)(param_2 + 0x14)) + 1);
  }
  return 0xffffffff;
}


// ==== FUN_00404150 @ 0x00404150 ====

bool FUN_00404150(void)

{
  int iVar1;
  undefined4 in_ECX;
  undefined1 local_4;
  undefined3 uStack_3;
  
  _local_4 = CONCAT31((int3)((uint)in_ECX >> 8),0x3a);
  iVar1 = FUN_00405850(&local_4,0,1);
  return iVar1 != -1;
}


// ==== FUN_00404170 @ 0x00404170 ====

undefined4 FUN_00404170(undefined4 param_1,undefined4 param_2)

{
  FUN_007972d0(param_1,param_2);
  return param_1;
}


// ==== FUN_004041a0 @ 0x004041a0 ====

undefined4 FUN_004041a0(undefined4 param_1,undefined4 param_2)

{
  FUN_00797600(param_1,param_2);
  return param_1;
}


// ==== FUN_004041d0 @ 0x004041d0 ====

undefined4 FUN_004041d0(undefined4 param_1,undefined4 param_2)

{
  FUN_00797020(param_1,param_2);
  return param_1;
}


// ==== FUN_00404230 @ 0x00404230 ====

int FUN_00404230(int param_1,undefined1 param_2,void *param_3)

{
  int extraout_EAX;
  int extraout_EAX_00;
  uint in_stack_00000020;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00977d10;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00401660(&param_2,0,0xffffffff);
  FUN_00797200(local_28);
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660();
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (in_stack_00000020 < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(param_3);
  return extraout_EAX_00;
}


// ==== FUN_00404300 @ 0x00404300 ====

int FUN_00404300(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  undefined1 uVar3;
  void **ppvVar4;
  int iVar5;
  int extraout_EAX;
  undefined1 uVar6;
  int iVar7;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00977d22;
  local_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  iVar1 = *(int *)(param_2 + 0x14);
  local_4 = 0;
  if (*(uint *)(param_2 + 0x18) < 0x10) {
    param_2 = param_2 + 4;
  }
  else {
    param_2 = *(int *)(param_2 + 4);
  }
  uVar6 = 0;
  iVar7 = 0;
  bVar2 = false;
  uVar3 = 0;
  ExceptionList = &local_c;
  ppvVar4 = &local_c;
  if (0 < iVar1) {
    do {
      if (bVar2) {
        iVar5 = _isspace((uint)CONCAT11(uVar6,*(undefined1 *)(iVar7 + param_2)));
        if (iVar5 == 0) {
          FUN_00405ac0(1,uVar3);
          FUN_00405ac0(1,*(undefined1 *)(iVar7 + param_2));
        }
        uVar6 = 0;
        bVar2 = false;
        uVar3 = 0;
      }
      else {
        iVar5 = FUN_00801bcb(*(undefined1 *)(iVar7 + param_2));
        if (iVar5 == 0) {
          iVar5 = _isspace((uint)*(byte *)(iVar7 + param_2));
          if (iVar5 == 0) {
            FUN_00405ac0(1,*(undefined1 *)(iVar7 + param_2));
          }
        }
        else {
          uVar6 = *(undefined1 *)(iVar7 + param_2);
          bVar2 = true;
          uVar3 = uVar6;
        }
      }
      iVar7 = iVar7 + 1;
      ppvVar4 = ExceptionList;
    } while (iVar7 < iVar1);
  }
  ExceptionList = ppvVar4;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_28,0,0xffffffff);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_00404440 @ 0x00404440 ====

void FUN_00404440(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_60 [4];
  void *local_5c;
  int local_4c;
  uint local_48;
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
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00977d44;
  local_c = ExceptionList;
  if (*(int *)(param_2 + 0x14) != 0) {
    local_48 = 0xf;
    local_4c = 0;
    local_5c = (void *)((uint)local_5c & 0xffffff00);
    ExceptionList = &local_c;
    FUN_00401660(param_1,0,0xffffffff);
    local_4._0_1_ = 0;
    local_4._1_3_ = 0;
    FUN_00401740(&DAT_0099ca56,0);
    while (local_4c != 0) {
      iVar1 = FUN_00403fb0(local_60,param_2);
      if (iVar1 == -1) {
        FUN_00401ff0(local_60,0,0xffffffff);
        break;
      }
      uVar2 = FUN_00405b90(local_44,0,iVar1);
      local_4._0_1_ = 1;
      FUN_00401ff0(uVar2,0,0xffffffff);
      local_4 = (uint)local_4._1_3_ << 8;
      if (0xf < local_2c) {
        _free(local_40);
        return;
      }
      local_2c = 0xf;
      local_30 = 0;
      local_40 = (void *)((uint)local_40 & 0xffffff00);
      FUN_00401ff0(param_3,0,0xffffffff);
      uVar2 = FUN_00405b90(local_28,*(int *)(param_2 + 0x14) + iVar1,0xffffffff);
      local_4._0_1_ = 2;
      FUN_00401660(uVar2,0,0xffffffff);
      local_4._0_1_ = 0;
      if (0xf < local_10) {
        _free(local_24);
        return;
      }
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
    }
    if (0xf < local_48) {
      _free(local_5c);
      return;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004045b0 @ 0x004045b0 ====

int FUN_004045b0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 local_8 [4];
  undefined4 local_4;
  
  local_4 = 0;
  local_8[0] = 0x5c;
  uVar1 = FUN_00405920(local_8,0xffffffff,1);
  local_8[0] = 0x2f;
  uVar2 = FUN_00405920(local_8,0xffffffff,1);
  if ((uVar1 == 0xffffffff) && (uVar2 == 0xffffffff)) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(&DAT_0099ca58,1);
    return param_1;
  }
  uVar3 = 0;
  if (uVar1 != 0xffffffff) {
    uVar3 = uVar1;
  }
  if ((uVar2 != 0xffffffff) && (uVar3 <= uVar2)) {
    uVar3 = uVar2;
  }
  FUN_00405b90(param_1,0,uVar3 + 1);
  return param_1;
}


// ==== FUN_00404650 @ 0x00404650 ====

int FUN_00404650(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 local_8 [4];
  undefined4 local_4;
  
  local_4 = 0;
  local_8[0] = 0x5c;
  uVar1 = FUN_00405920(local_8,0xffffffff,1);
  local_8[0] = 0x2f;
  uVar2 = FUN_00405920(local_8,0xffffffff,1);
  if ((uVar1 == 0xffffffff) && (uVar2 == 0xffffffff)) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(param_2,0,0xffffffff);
    return param_1;
  }
  uVar3 = 0;
  if (uVar1 != 0xffffffff) {
    uVar3 = uVar1;
  }
  if ((uVar2 != 0xffffffff) && (uVar3 <= uVar2)) {
    uVar3 = uVar2;
  }
  FUN_00405b90(param_1,uVar3 + 1,0xffffffff);
  return param_1;
}


// ==== FUN_004046f0 @ 0x004046f0 ====

int FUN_004046f0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (*(uint *)(param_2 + 0x14) < 2) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(&DAT_0099ca5e,0);
    return param_1;
  }
  iVar1 = *(uint *)(param_2 + 0x14) - 2;
  param_2._0_1_ = 0x5c;
  uVar2 = FUN_00405920(&param_2,iVar1,1);
  param_2 = CONCAT31(param_2._1_3_,0x2f);
  uVar3 = FUN_00405920(&param_2,iVar1,1);
  if ((uVar2 == 0xffffffff) && (uVar3 == 0xffffffff)) {
    FUN_00401830(&DAT_0099ca5c);
    return param_1;
  }
  uVar4 = 0;
  if (uVar2 != 0xffffffff) {
    uVar4 = uVar2;
  }
  if ((uVar3 != 0xffffffff) && (uVar4 <= uVar3)) {
    uVar4 = uVar3;
  }
  FUN_00405b90(param_1,0,uVar4 + 1);
  return param_1;
}


// ==== FUN_004047b0 @ 0x004047b0 ====

int FUN_004047b0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_8 [4];
  undefined4 local_4;
  
  local_4 = 0;
  local_8[0] = 0x2e;
  iVar1 = FUN_00405920(local_8,0xffffffff,1);
  if (iVar1 == -1) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(param_2,0,0xffffffff);
    return param_1;
  }
  FUN_00405b90(param_1,0,iVar1);
  return param_1;
}


// ==== FUN_00404820 @ 0x00404820 ====

int FUN_00404820(int param_1)

{
  int iVar1;
  undefined1 local_8 [4];
  undefined4 local_4;
  
  local_4 = 0;
  local_8[0] = 0x2e;
  iVar1 = FUN_00405920(local_8,0xffffffff,1);
  if (iVar1 == -1) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(&DAT_0099ca5f,0);
    return param_1;
  }
  FUN_00405b90(param_1,iVar1 + 1,0xffffffff);
  return param_1;
}


// ==== FUN_00404890 @ 0x00404890 ====

int FUN_00404890(int param_1)

{
  char cVar1;
  DWORD DVar2;
  char *pcVar3;
  CHAR local_400 [1024];
  
  DVar2 = GetModuleFileNameA((HMODULE)0x0,local_400,0x3ff);
  local_400[DVar2] = '\0';
  pcVar3 = local_400;
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(local_400,(int)pcVar3 - (int)(local_400 + 1));
  return param_1;
}


// ==== FUN_00404900 @ 0x00404900 ====

undefined4 FUN_00404900(int param_1,int param_2)

{
  int iVar1;
  undefined4 extraout_EAX;
  undefined4 uVar2;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00977d5e;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0x14) == 0) {
    return 0;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  FUN_00401740(&DAT_0099ca60,0);
  if (*(uint *)(param_2 + 0x18) < 0x10) {
    iVar1 = param_2 + 4;
  }
  else {
    iVar1 = *(int *)(param_2 + 4);
  }
  iVar1 = FUN_00405850(iVar1,0,*(undefined4 *)(param_2 + 0x14));
  if (iVar1 == -1) {
    FUN_00401ff0(local_44,0,0xffffffff);
    if (local_2c < 0x10) {
      ExceptionList = local_c;
      return 0;
    }
    _free(local_40);
    return extraout_EAX;
  }
  uVar2 = FUN_00405b90(local_28,*(int *)(param_2 + 0x14) + iVar1,0xffffffff);
  local_4._0_1_ = 1;
  FUN_00401660(uVar2,0,0xffffffff);
  local_4 = (uint)local_4._1_3_ << 8;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_00;
  }
  FUN_00401660(local_44,0,0xffffffff);
  if (local_2c < 0x10) {
    ExceptionList = local_c;
    return 1;
  }
  _free(local_40);
  return extraout_EAX_01;
}


// ==== FUN_00404a40 @ 0x00404a40 ====

int FUN_00404a40(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int extraout_EAX;
  int iVar3;
  uint uVar4;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00977d70;
  local_c = ExceptionList;
  uVar4 = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401660(param_2,0,0xffffffff);
  local_4 = 0;
  iVar3 = 0;
  while( true ) {
    iVar1 = *(int *)(param_3 + 4);
    if ((iVar1 == 0) || ((uint)((*(int *)(param_3 + 8) - iVar1) / 0x1c) <= uVar4)) {
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
    iVar2 = *(int *)(param_4 + 4);
    if ((iVar2 == 0) || ((uint)((*(int *)(param_4 + 8) - iVar2) / 0x1c) <= uVar4)) break;
    FUN_00404440(local_28,iVar1 + iVar3,iVar2 + iVar3);
    uVar4 = uVar4 + 1;
    iVar3 = iVar3 + 0x1c;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00405ca0();
}


// ==== FUN_00404b60 @ 0x00404b60 ====

void FUN_00404b60(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_478;
  undefined1 local_470 [4];
  void *local_46c;
  undefined4 local_45c;
  uint local_458;
  void *local_450;
  undefined4 local_44c;
  undefined4 local_448;
  undefined1 local_444 [4];
  void *local_440;
  undefined4 local_430;
  uint local_42c;
  char local_40c [1024];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00977db1;
  local_c = ExceptionList;
  iVar1 = *(int *)(param_1 + 0x14);
  iVar10 = 0;
  local_478 = 0;
  local_450 = (void *)0x0;
  local_44c = 0;
  local_448 = 0;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_004060a0(param_3);
  iVar8 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 4) != iVar8) {
    uVar4 = FUN_0040c0e0(iVar8,iVar8,*(int *)(param_2 + 4),iVar1);
    FUN_00405de0(uVar4,*(undefined4 *)(param_2 + 8),param_2,iVar1);
    *(undefined4 *)(param_2 + 8) = uVar4;
  }
  iVar8 = 0;
  if (0 < iVar1) {
    do {
      switch(local_478) {
      case 0:
        uVar2 = *(uint *)(param_1 + 0x18);
        puVar6 = (undefined4 *)(param_1 + 4);
        if (uVar2 < 0x10) {
          puVar5 = puVar6;
        }
        else {
          puVar5 = (undefined4 *)*puVar6;
        }
        if (*(char *)((int)puVar5 + iVar8) == '/') {
          if (uVar2 < 0x10) {
            puVar5 = puVar6;
          }
          else {
            puVar5 = (undefined4 *)*puVar6;
          }
          if (*(char *)((int)puVar5 + iVar8 + 1) == '/') goto LAB_00404f6a;
        }
        if (uVar2 < 0x10) {
          puVar5 = puVar6;
        }
        else {
          puVar5 = (undefined4 *)*puVar6;
        }
        cVar3 = FUN_00405a70(*(undefined1 *)((int)puVar5 + iVar8));
        if (cVar3 != '\0') {
          if (*(uint *)(param_1 + 0x18) < 0x10) {
            puVar5 = puVar6;
          }
          else {
            puVar5 = (undefined4 *)*puVar6;
          }
          if (-1 < *(char *)((int)puVar5 + iVar8)) {
            if (iVar8 != 0) {
              local_40c[iVar10] = '\0';
              uVar4 = FUN_00401830(local_40c);
              local_4._0_1_ = 1;
              FUN_00406720(uVar4);
              local_4 = (uint)local_4._1_3_ << 8;
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            local_478 = 3;
            break;
          }
        }
        uVar2 = *(uint *)(param_1 + 0x18);
        if (uVar2 < 0x10) {
          puVar5 = puVar6;
        }
        else {
          puVar5 = (undefined4 *)*puVar6;
        }
        if (*(char *)((int)puVar5 + iVar8) == '\"') {
          iVar10 = 0;
          local_478 = 1;
        }
        else {
          if (uVar2 < 0x10) {
            puVar5 = puVar6;
          }
          else {
            puVar5 = (undefined4 *)*puVar6;
          }
          if (*(char *)((int)puVar5 + iVar8) == '\'') {
            iVar10 = 0;
            local_478 = 2;
          }
          else {
            if (0xf < uVar2) {
              puVar6 = (undefined4 *)*puVar6;
            }
            local_40c[iVar10] = *(char *)((int)puVar6 + iVar8);
            iVar10 = iVar10 + 1;
          }
        }
        break;
      case 1:
        puVar6 = (undefined4 *)(param_1 + 4);
        if (*(uint *)(param_1 + 0x18) < 0x10) {
          puVar5 = puVar6;
        }
        else {
          puVar5 = (undefined4 *)*puVar6;
        }
        if (*(char *)((int)puVar5 + iVar8) == '\"') {
          pcVar7 = local_40c;
          local_40c[iVar10] = '\0';
          local_42c = 0xf;
          local_430 = 0;
          local_440 = (void *)((uint)local_440 & 0xffffff00);
          do {
            cVar3 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar3 != '\0');
          FUN_00401740(local_40c,(int)pcVar7 - (int)(local_40c + 1));
          local_4._0_1_ = 2;
          FUN_00406720(local_444);
          local_4 = (uint)local_4._1_3_ << 8;
          if (0xf < local_42c) {
            _free(local_440);
            return;
          }
          local_42c = 0xf;
          local_430 = 0;
          local_440 = (void *)((uint)local_440 & 0xffffff00);
          local_478 = 3;
          iVar10 = 0;
        }
        else {
          if (0xf < *(uint *)(param_1 + 0x18)) {
            puVar6 = (undefined4 *)*puVar6;
          }
          local_40c[iVar10] = *(char *)((int)puVar6 + iVar8);
          iVar10 = iVar10 + 1;
        }
        break;
      case 2:
        puVar6 = (undefined4 *)(param_1 + 4);
        if (*(uint *)(param_1 + 0x18) < 0x10) {
          puVar5 = puVar6;
        }
        else {
          puVar5 = (undefined4 *)*puVar6;
        }
        if (*(char *)((int)puVar5 + iVar8) == '\'') {
          pcVar7 = local_40c;
          local_40c[iVar10] = '\0';
          local_458 = 0xf;
          local_45c = 0;
          local_46c = (void *)((uint)local_46c & 0xffffff00);
          do {
            cVar3 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar3 != '\0');
          FUN_00401740(local_40c,(int)pcVar7 - (int)(local_40c + 1));
          local_4._0_1_ = 3;
          FUN_00406720(local_470);
          local_4 = (uint)local_4._1_3_ << 8;
          if (0xf < local_458) {
            _free(local_46c);
            return;
          }
          local_458 = 0xf;
          local_45c = 0;
          local_46c = (void *)((uint)local_46c & 0xffffff00);
          local_478 = 3;
          iVar10 = 0;
        }
        else {
          if (0xf < *(uint *)(param_1 + 0x18)) {
            puVar6 = (undefined4 *)*puVar6;
          }
          local_40c[iVar10] = *(char *)((int)puVar6 + iVar8);
          iVar10 = iVar10 + 1;
        }
        break;
      case 3:
        if (*(uint *)(param_1 + 0x18) < 0x10) {
          iVar9 = param_1 + 4;
        }
        else {
          iVar9 = *(int *)(param_1 + 4);
        }
        puVar6 = (undefined4 *)(param_1 + 4);
        cVar3 = FUN_00405a70(CONCAT31((int3)((uint)iVar9 >> 8),*(undefined1 *)(iVar9 + iVar8)));
        if (cVar3 != '\0') {
          if (0xf < *(uint *)(param_1 + 0x18)) {
            puVar6 = (undefined4 *)*puVar6;
          }
          if (-1 < *(char *)((int)puVar6 + iVar8)) break;
        }
        local_478 = 0;
        iVar8 = iVar8 + -1;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar1);
    if ((local_478 != 3) && (iVar8 != 0)) {
      pcVar7 = local_40c;
      local_40c[iVar10] = '\0';
      local_458 = 0xf;
      local_45c = 0;
      local_46c = (void *)((uint)local_46c & 0xffffff00);
      do {
        cVar3 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar3 != '\0');
      FUN_00401740(local_40c,(int)pcVar7 - (int)(local_40c + 1));
      local_4 = CONCAT31(local_4._1_3_,4);
      FUN_00406720(local_470);
      if (0xf < local_458) {
        _free(local_46c);
        return;
      }
    }
  }
LAB_00404f6a:
  if (local_450 == (void *)0x0) {
    ExceptionList = local_c;
    return;
  }
  _free(local_450);
  return;
}


// ==== FUN_00404fb0 @ 0x00404fb0 ====

void FUN_00404fb0(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_4c [4];
  int local_48;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 local_28 [4];
  void *local_24;
  int local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00977ddb;
  local_c = ExceptionList;
  iVar3 = 0;
  local_4c[0] = param_2;
  ExceptionList = &local_c;
  iVar1 = FUN_00405850(local_4c,0,1);
  while (iVar1 != -1) {
    local_48 = iVar1 - iVar3;
    if (local_48 == 0) {
      local_2c = 0xf;
      local_30 = 0;
      local_40 = (void *)((uint)local_40 & 0xffffff00);
      FUN_00401740(&DAT_0099ca61,0);
      local_4 = 3;
      FUN_00406720(local_44);
      local_4 = 0xffffffff;
      if (0xf < local_2c) {
        _free(local_40);
        return;
      }
      local_2c = 0xf;
      local_30 = 0;
      local_40 = (void *)((uint)local_40 & 0xffffff00);
    }
    else {
      uVar2 = FUN_00405b90(local_28,iVar3,local_48);
      local_4 = 2;
      FUN_00406720(uVar2);
      local_4 = 0xffffffff;
      if (0xf < local_10) {
        _free(local_24);
        return;
      }
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
    }
    local_4 = 0xffffffff;
    iVar3 = iVar1 + 1;
    local_4c[0] = param_2;
    iVar1 = FUN_00405850(local_4c,iVar3,1);
  }
  FUN_00405b90(local_28,iVar3,0xffffffff);
  local_4 = 0;
  if (local_14 != 0) {
    uVar2 = FUN_00405b90(local_44,iVar3,0xffffffff);
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_00406720(uVar2);
    if (0xf < local_2c) {
      _free(local_40);
      return;
    }
  }
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_00405160 @ 0x00405160 ====

void FUN_00405160(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 local_28 [4];
  void *local_24;
  int local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00977e05;
  local_c = ExceptionList;
  iVar3 = 0;
  ExceptionList = &local_c;
  while( true ) {
    local_4 = 0xffffffff;
    if (*(uint *)(param_2 + 0x18) < 0x10) {
      iVar1 = param_2 + 4;
    }
    else {
      iVar1 = *(int *)(param_2 + 4);
    }
    iVar1 = FUN_004059c0(iVar1,iVar3,*(undefined4 *)(param_2 + 0x14));
    if (iVar1 == -1) break;
    if (iVar1 - iVar3 == 0) {
      local_2c = 0xf;
      local_30 = 0;
      local_40 = (void *)((uint)local_40 & 0xffffff00);
      FUN_00401740(&DAT_0099ca62,0);
      local_4 = 3;
      FUN_00406720(local_44);
      local_4 = 0xffffffff;
      if (0xf < local_2c) {
        _free(local_40);
        return;
      }
      local_2c = 0xf;
      local_30 = 0;
      local_40 = (void *)((uint)local_40 & 0xffffff00);
      iVar3 = iVar1 + 1;
    }
    else {
      uVar2 = FUN_00405b90(local_28,iVar3,iVar1 - iVar3);
      local_4 = 2;
      FUN_00406720(uVar2);
      local_4 = 0xffffffff;
      if (0xf < local_10) {
        _free(local_24);
        return;
      }
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
      iVar3 = iVar1 + 1;
    }
  }
  FUN_00405b90(local_28,iVar3,0xffffffff);
  local_4 = 0;
  if (local_14 != 0) {
    uVar2 = FUN_00405b90(local_44,iVar3,0xffffffff);
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_00406720(uVar2);
    if (0xf < local_2c) {
      _free(local_40);
      return;
    }
  }
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_00405300 @ 0x00405300 ====

void FUN_00405300(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
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
  
  puStack_8 = &LAB_00977e27;
  local_c = ExceptionList;
  iVar3 = 0;
  ExceptionList = &local_c;
  while( true ) {
    local_4 = 0xffffffff;
    uVar1 = FUN_00405b90(local_44,iVar3,0xffffffff);
    local_4 = 0;
    iVar2 = FUN_00403fb0(uVar1,param_2);
    local_4 = 0xffffffff;
    if (0xf < local_2c) {
      _free(local_40);
      return;
    }
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    if (iVar2 == -1) break;
    uVar1 = FUN_00405b90(local_28,iVar3,iVar2);
    local_4 = 2;
    FUN_00406720(uVar1);
    local_4 = 0xffffffff;
    if (0xf < local_10) {
      _free(local_24);
      return;
    }
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    iVar3 = iVar3 + *(int *)(param_2 + 0x14) + iVar2;
  }
  uVar1 = FUN_00405b90(local_44,iVar3,*(int *)(param_1 + 0x14) - iVar3);
  local_4 = 1;
  FUN_00406720(uVar1);
  if (local_2c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_40);
  return;
}


// ==== FUN_00405420 @ 0x00405420 ====

/* WARNING: Removing unreachable block (ram,0x00405618) */
/* WARNING: Removing unreachable block (ram,0x004054bb) */
/* WARNING: Removing unreachable block (ram,0x004055f7) */

undefined4 FUN_00405420(undefined4 param_1,int param_2,undefined4 param_3,LPCSTR param_4)

{
  LPCSTR lpFileName;
  HANDLE hFindFile;
  undefined4 extraout_EAX;
  int iVar1;
  BOOL BVar2;
  undefined4 extraout_EAX_00;
  uint in_stack_00000024;
  undefined1 local_168 [4];
  void *local_164;
  undefined4 local_154;
  uint local_150;
  _WIN32_FIND_DATAA local_14c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00977e5a;
  local_c = ExceptionList;
  local_4 = 2;
  lpFileName = param_4;
  if (in_stack_00000024 < 0x10) {
    lpFileName = (LPCSTR)&param_4;
  }
  ExceptionList = &local_c;
  hFindFile = FindFirstFileA(lpFileName,&local_14c);
  if (hFindFile == (HANDLE)0xffffffff) {
    FUN_00406600();
  }
  else {
    do {
      FUN_00401740(&DAT_0099ca64,2);
      FUN_00404230(local_168);
      local_4._0_1_ = 3;
      FUN_00401660();
      local_4 = CONCAT31(local_4._1_3_,2);
      if (0xf < local_150) {
        _free(local_164);
        return extraout_EAX;
      }
      local_150 = 0xf;
      local_154 = 0;
      local_164 = (void *)((uint)local_164 & 0xffffff00);
      if (((byte)local_14c.dwFileAttributes & 2) == 0) {
        if (param_2 == 0) {
          if (((byte)local_14c.dwFileAttributes & 0x10) != 0) {
LAB_0040557f:
            if ((((byte)local_14c.dwFileAttributes & 0x10) == 0) ||
               ((iVar1 = FUN_00403620(), iVar1 != 0 && (iVar1 = FUN_00403620(), iVar1 != 0)))) {
              FUN_00406720();
            }
          }
        }
        else if ((param_2 != 1) || (((byte)local_14c.dwFileAttributes & 0x10) == 0))
        goto LAB_0040557f;
      }
      BVar2 = FindNextFileA(hFindFile,&local_14c);
    } while (BVar2 == 1);
    FUN_00406600();
  }
  if (in_stack_00000024 < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(param_4);
  return extraout_EAX_00;
}


// ==== FUN_00405670 @ 0x00405670 ====

void FUN_00405670(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00977e6c;
  local_c = ExceptionList;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00404b60(param_1,param_2,local_1c);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004056c0 @ 0x004056c0 ====

undefined4 FUN_004056c0(undefined4 param_1,void *param_2)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int *piVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 unaff_retaddr;
  uint in_stack_0000001c;
  uint uStack_50;
  undefined4 local_4c;
  void *local_48;
  undefined4 uStack_38;
  uint uStack_34;
  void *pvStack_2c;
  undefined4 uStack_1c;
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00977e96;
  pvStack_c = ExceptionList;
  local_4 = 0;
  local_48 = (void *)0xf;
  local_4c = 0;
  pcVar3 = PTR_s_DataPath_00adb14c;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = CONCAT31(local_4._1_3_,1);
  piVar4 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  (**(code **)(*piVar4 + 8))();
  pvStack_c._0_1_ = 2;
  FUN_00405bd0();
  if (0xf < uStack_18) {
    _free(pvStack_2c);
    return extraout_EAX;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,4);
  if (0xf < uStack_50) {
    _free((void *)0x0);
    return extraout_EAX_00;
  }
  FUN_00401660(&local_4c,0,0xffffffff);
  uVar2 = local_4;
  FUN_00405420(local_4,unaff_retaddr);
  if (0xf < uStack_34) {
    _free(local_48);
    return extraout_EAX_01;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  local_48 = (void *)((uint)local_48 & 0xffffff00);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = pvStack_14;
    return uVar2;
  }
  _free(param_2);
  return extraout_EAX_02;
}


// ==== FUN_00405820 @ 0x00405820 ====

int FUN_00405820(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x1c;
}


// ==== FUN_00405850 @ 0x00405850 ====

undefined4 * FUN_00405850(char *param_1,undefined4 *param_2,uint param_3)

{
  char *pcVar1;
  int in_ECX;
  uint uVar2;
  uint uVar3;
  char *_MaxCount;
  int iVar4;
  char *_Buf;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  
  uVar2 = (uint)param_2;
  if ((param_3 != 0) || (*(uint *)(in_ECX + 0x14) < param_2)) {
    if ((param_2 < *(uint *)(in_ECX + 0x14)) &&
       (uVar3 = *(uint *)(in_ECX + 0x14) - (int)param_2, param_3 <= uVar3)) {
      _MaxCount = (char *)(uVar3 + (1 - param_3));
      if (*(uint *)(in_ECX + 0x18) < 0x10) {
        iVar4 = in_ECX + 4;
      }
      else {
        iVar4 = *(int *)(in_ECX + 4);
      }
      param_2 = (undefined4 *)(in_ECX + 4);
      _Buf = (char *)(iVar4 + uVar2);
      pcVar1 = _memchr(_Buf,(int)*param_1,(size_t)_MaxCount);
      if (pcVar1 != (char *)0x0) {
        do {
          bVar7 = true;
          uVar2 = param_3;
          pcVar5 = pcVar1;
          pcVar6 = param_1;
          do {
            if (uVar2 == 0) break;
            uVar2 = uVar2 - 1;
            bVar7 = *pcVar5 == *pcVar6;
            pcVar5 = pcVar5 + 1;
            pcVar6 = pcVar6 + 1;
          } while (bVar7);
          if (bVar7) {
            if (0xf < *(uint *)(in_ECX + 0x18)) {
              param_2 = (undefined4 *)*param_2;
            }
            return (undefined4 *)((int)pcVar1 - (int)param_2);
          }
          _MaxCount = _Buf + (int)(_MaxCount + (-1 - (int)pcVar1));
          _Buf = pcVar1 + 1;
          pcVar1 = _memchr(_Buf,(int)*param_1,(size_t)_MaxCount);
          if (pcVar1 == (char *)0x0) {
            return (undefined4 *)0xffffffff;
          }
        } while( true );
      }
    }
    param_2 = (undefined4 *)0xffffffff;
  }
  return param_2;
}


// ==== FUN_00405920 @ 0x00405920 ====

uint FUN_00405920(char *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  int in_ECX;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  
  if (param_3 == 0) {
    if (*(uint *)(in_ECX + 0x14) <= param_2) {
      return *(uint *)(in_ECX + 0x14);
    }
  }
  else {
    if (param_3 <= *(uint *)(in_ECX + 0x14)) {
      uVar2 = *(uint *)(in_ECX + 0x14) - param_3;
      if (param_2 < uVar2) {
        uVar2 = param_2;
      }
      uVar1 = *(uint *)(in_ECX + 0x18);
      pcVar5 = (char *)(in_ECX + 4);
      if (uVar1 < 0x10) {
        pcVar3 = pcVar5;
      }
      else {
        pcVar3 = *(char **)pcVar5;
      }
      pcVar3 = pcVar3 + uVar2;
      do {
        if (*pcVar3 == *param_1) {
          bVar7 = true;
          uVar2 = param_3;
          pcVar4 = pcVar3;
          pcVar6 = param_1;
          do {
            if (uVar2 == 0) break;
            uVar2 = uVar2 - 1;
            bVar7 = *pcVar4 == *pcVar6;
            pcVar4 = pcVar4 + 1;
            pcVar6 = pcVar6 + 1;
          } while (bVar7);
          if (bVar7) {
            if (0xf < uVar1) {
              pcVar5 = *(char **)pcVar5;
            }
            return (int)pcVar3 - (int)pcVar5;
          }
        }
        if (uVar1 < 0x10) {
          pcVar4 = pcVar5;
        }
        else {
          pcVar4 = *(char **)pcVar5;
        }
        if (pcVar3 == pcVar4) break;
        pcVar3 = pcVar3 + -1;
      } while( true );
    }
    param_2 = 0xffffffff;
  }
  return param_2;
}


// ==== FUN_004059c0 @ 0x004059c0 ====

int FUN_004059c0(void *param_1,uint param_2,size_t param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int in_ECX;
  undefined4 *puVar5;
  char *pcVar6;
  
  if ((param_3 != 0) && (uVar1 = *(uint *)(in_ECX + 0x14), param_2 < uVar1)) {
    puVar5 = (undefined4 *)(in_ECX + 4);
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      puVar2 = puVar5;
    }
    else {
      puVar2 = (undefined4 *)*puVar5;
    }
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      puVar3 = puVar5;
    }
    else {
      puVar3 = (undefined4 *)*puVar5;
    }
    for (pcVar6 = (char *)(param_2 + (int)puVar3); pcVar6 < (char *)(uVar1 + (int)puVar2);
        pcVar6 = pcVar6 + 1) {
      pvVar4 = _memchr(param_1,(int)*pcVar6,param_3);
      if (pvVar4 != (void *)0x0) {
        if (0xf < *(uint *)(in_ECX + 0x18)) {
          puVar5 = (undefined4 *)*puVar5;
        }
        return (int)pcVar6 - (int)puVar5;
      }
    }
  }
  return -1;
}


// ==== FUN_00405a50 @ 0x00405a50 ====

int FUN_00405a50(void *param_1,int param_2,void *param_3)

{
  void *pvVar1;
  
  pvVar1 = _memmove(param_3,param_1,param_2 - (int)param_1);
  return (int)pvVar1 + (param_2 - (int)param_1);
}


// ==== FUN_00405a70 @ 0x00405a70 ====

uint FUN_00405a70(char param_1)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  int in_ECX;
  
  pcVar3 = *(char **)(in_ECX + 4);
  if ((pcVar3 == (char *)0x0) || (pcVar1 = *(char **)(in_ECX + 8), pcVar1 == pcVar3)) {
    iVar2 = _isspace((int)param_1);
    return (uint)(iVar2 != 0);
  }
  for (; (pcVar3 != pcVar1 && (*pcVar3 != param_1)); pcVar3 = pcVar3 + 1) {
  }
  return CONCAT31((int3)((uint)pcVar3 >> 8),pcVar3 != pcVar1);
}


// ==== FUN_00405ac0 @ 0x00405ac0 ====

void FUN_00405ac0(uint param_1,undefined1 param_2)

{
  int in_ECX;
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if (-*(int *)(in_ECX + 0x14) - 1U <= param_1) {
    FUN_0079dbe3();
  }
  if (param_1 != 0) {
    uVar3 = *(int *)(in_ECX + 0x14) + param_1;
    if (uVar3 == 0xffffffff) {
      FUN_0079dbe3();
    }
    if (*(uint *)(in_ECX + 0x18) < uVar3) {
      FUN_00401410(uVar3,*(undefined4 *)(in_ECX + 0x14));
    }
    else if (uVar3 == 0) {
      *(undefined4 *)(in_ECX + 0x14) = 0;
      if (*(uint *)(in_ECX + 0x18) < 0x10) {
        *(undefined1 *)(in_ECX + 4) = 0;
        return;
      }
      **(undefined1 **)(in_ECX + 4) = 0;
      return;
    }
    if (uVar3 != 0) {
      if (*(uint *)(in_ECX + 0x18) < 0x10) {
        iVar2 = in_ECX + 4;
      }
      else {
        iVar2 = *(int *)(in_ECX + 4);
      }
      puVar4 = (undefined4 *)(*(int *)(in_ECX + 0x14) + iVar2);
      for (uVar1 = param_1 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar4 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
        puVar4 = puVar4 + 1;
      }
      for (param_1 = param_1 & 3; param_1 != 0; param_1 = param_1 - 1) {
        *(undefined1 *)puVar4 = param_2;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
      *(uint *)(in_ECX + 0x14) = uVar3;
      if (0xf < *(uint *)(in_ECX + 0x18)) {
        *(undefined1 *)(*(int *)(in_ECX + 4) + uVar3) = 0;
        return;
      }
      *(undefined1 *)(in_ECX + 4 + uVar3) = 0;
    }
  }
  return;
}


// ==== FUN_00405b90 @ 0x00405b90 ====

int FUN_00405b90(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 in_ECX;
  
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(in_ECX,param_2,param_3);
  return param_1;
}


// ==== FUN_00405bd0 @ 0x00405bd0 ====

/* WARNING: Removing unreachable block (ram,0x00405c49) */

int FUN_00405bd0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00977ea8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00401660(param_2,0,0xffffffff);
  local_4 = 0;
  uVar1 = FUN_00401ff0(param_3,0,0xffffffff);
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(uVar1,0,0xffffffff);
  ExceptionList = local_c;
  return param_1;
}


// ==== FUN_00405c70 @ 0x00405c70 ====

void FUN_00405c70(int param_1)

{
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    return;
  }
  _free(*(void **)(param_1 + 4));
  return;
}


// ==== FUN_00405ca0 @ 0x00405ca0 ====

void FUN_00405ca0(void)

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
  puStack_8 = &LAB_00977ec8;
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


// ==== FUN_00405d10 @ 0x00405d10 ====

void FUN_00405d10(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_00403960(param_1);
  *in_ECX = &PTR_FUN_0099ca80;
  return;
}


// ==== FUN_00405d30 @ 0x00405d30 ====

int FUN_00405d30(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if (param_1 < (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x1c)) {
      return iVar1 + param_1 * 0x1c;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_00405ca0();
}


// ==== FUN_00405d70 @ 0x00405d70 ====

void FUN_00405d70(void)

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
  puStack_8 = &LAB_00977ec8;
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


// ==== FUN_00405de0 @ 0x00405de0 ====

void FUN_00405de0(int param_1,int param_2)

{
  while( true ) {
    if (param_1 == param_2) {
      return;
    }
    if (0xf < *(uint *)(param_1 + 0x18)) break;
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    param_1 = param_1 + 0x1c;
  }
  _free(*(void **)(param_1 + 4));
  return;
}


// ==== FUN_00405e20 @ 0x00405e20 ====

void FUN_00405e20(int param_1,int param_2,undefined4 param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x1c) {
    FUN_00401660(param_3,0,0xffffffff);
  }
  return;
}


// ==== FUN_00405e50 @ 0x00405e50 ====

int FUN_00405e50(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    param_2 = param_2 + -0x1c;
    param_3 = param_3 + -0x1c;
    FUN_00401660(param_2,0,0xffffffff);
  } while (param_2 != param_1);
  return param_3;
}


// ==== FUN_00405e90 @ 0x00405e90 ====

int FUN_00405e90(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00977ef1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x1c) {
    local_8 = 1;
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x18) = 0xf;
      *(undefined4 *)(param_3 + 0x14) = 0;
      *(undefined1 *)(param_3 + 4) = 0;
      FUN_00401660(param_1,0,0xffffffff);
    }
    param_3 = param_3 + 0x1c;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00405ef6 @ 0x00405ef6 ====

void Catch_00405ef6(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x1c) {
    FUN_00405c70(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00405f30 @ 0x00405f30 ====

undefined4 FUN_00405f30(uint param_1)

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
    param_1 = FUN_00405d70();
  }
  pvVar1 = operator_new(param_1 * 0x1c);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x1c + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_00405f90 @ 0x00405f90 ====

/* WARNING: Removing unreachable block (ram,0x00405fb3) */

undefined4 FUN_00405f90(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  pvVar1 = operator_new(param_1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  *(uint *)(in_ECX + 0xc) = (int)pvVar1 + param_1;
  return CONCAT31((int3)((int)pvVar1 + param_1 >> 8),1);
}


// ==== FUN_00405fe0 @ 0x00405fe0 ====

void FUN_00405fe0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00977f11;
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
    }
    param_1 = param_1 + 0x1c;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00406048 @ 0x00406048 ====

void Catch_00406048(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x1c) {
    FUN_00405c70(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00406080 @ 0x00406080 ====

void FUN_00406080(undefined4 param_1,undefined4 param_2)

{
  FUN_00405de0(param_1,param_2);
  return;
}


// ==== FUN_004060a0 @ 0x004060a0 ====

void FUN_004060a0(int param_1)

{
  void *pvVar1;
  void *_Memory;
  char cVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  size_t _Size;
  
  if (in_ECX == param_1) {
    return;
  }
  pvVar3 = *(void **)(param_1 + 4);
  if (pvVar3 != (void *)0x0) {
    pvVar1 = *(void **)(param_1 + 8);
    if (pvVar1 != pvVar3) {
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = *(int *)(in_ECX + 8) - (int)_Memory;
      }
      if ((uint)((int)pvVar1 - (int)pvVar3) <= uVar6) {
        _memmove(_Memory,pvVar3,(int)pvVar1 - (int)pvVar3);
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + (*(int *)(param_1 + 8) - *(int *)(param_1 + 4));
        return;
      }
      if (_Memory == (void *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = *(int *)(in_ECX + 0xc) - (int)_Memory;
      }
      if ((uint)((int)pvVar1 - (int)pvVar3) <= uVar6) {
        if (_Memory == (void *)0x0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(in_ECX + 8) - (int)_Memory;
        }
        pvVar1 = *(void **)(param_1 + 4);
        pvVar3 = (void *)((int)pvVar1 + iVar5);
        _memmove(_Memory,pvVar1,(int)pvVar3 - (int)pvVar1);
        _Size = *(int *)(param_1 + 8) - (int)pvVar3;
        pvVar3 = _memmove(*(void **)(in_ECX + 8),pvVar3,_Size);
        *(size_t *)(in_ECX + 8) = (int)pvVar3 + _Size;
        return;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
        return;
      }
      if (*(int *)(param_1 + 4) == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
      }
      cVar2 = FUN_00405f90(iVar5);
      if (cVar2 == '\0') {
        return;
      }
      uVar4 = FUN_00405a50(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
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


// ==== FUN_004061e0 @ 0x004061e0 ====

void FUN_004061e0(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_2 != param_3) {
    uVar1 = FUN_0040c0e0(param_3,*(undefined4 *)(in_ECX + 8),param_2,param_1);
    FUN_00405de0(uVar1,*(undefined4 *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = uVar1;
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_00406230 @ 0x00406230 ====

void FUN_00406230(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00405e90(param_1,param_2,param_3);
  return;
}


// ==== FUN_00406250 @ 0x00406250 ====

void FUN_00406250(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  FUN_00405de0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00406290 @ 0x00406290 ====

int FUN_00406290(int param_1,int param_2,undefined4 param_3)

{
  FUN_00405fe0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x1c;
}


// ==== FUN_004062c0 @ 0x004062c0 ====

void FUN_004062c0(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  int iVar6;
  undefined1 local_34 [2];
  undefined1 auStack_32 [2];
  void *local_30;
  undefined4 local_20;
  uint local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00977f28;
  local_10 = ExceptionList;
  local_14 = local_34 + -0xc;
  local_1c = 0xf;
  local_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3,0,0xffffffff);
  iVar2 = *(int *)(in_ECX + 4);
  local_8 = 0;
  if (iVar2 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x1c;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x1c;
    }
    if (0x9249249U - iVar2 < param_2) {
      FUN_00405d70();
      uVar5 = extraout_ECX;
    }
    if (*(int *)(in_ECX + 4) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x1c;
    }
    if (uVar5 < iVar2 + param_2) {
      if (0x9249249 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (*(int *)(in_ECX + 4) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x1c;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_00405820();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x1c);
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar2 = FUN_00405e90(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_00405fe0(iVar2,param_2,local_34);
      FUN_00405e90(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x1c);
      iVar2 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x1c;
      }
      if (*(int *)(in_ECX + 4) != 0) {
        FUN_00405de0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x1c + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar2) * 0x1c);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      iVar1 = param_2 * 0x1c;
      if ((uint)((iVar2 - param_1) / 0x1c) < param_2) {
        FUN_00405e90(param_1,iVar2,iVar1 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_00406290(*(undefined4 *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x1c,
                     local_34);
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar1;
        local_8 = 0;
        FUN_00405e20(param_1,*(int *)(in_ECX + 8) + param_2 * -0x1c,local_34);
      }
      else {
        iVar6 = iVar2 + param_2 * -0x1c;
        uVar4 = FUN_00405e90(iVar6,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_00405e50(param_1,iVar6,iVar2,param_1);
        FUN_00405e20(param_1,iVar1 + param_1,local_34);
      }
    }
  }
  if (local_1c < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_30);
  return;
}


// ==== Catch@004064b2 @ 0x004064b2 ====

void Catch_004064b2(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + 0x10);
  FUN_00406080(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@00406571 @ 0x00406571 ====

void Catch_00406571(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x1c;
  FUN_00406080(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00406600 @ 0x00406600 ====

void FUN_00406600(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00977f40;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_00405f30(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_00405e90(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0040668c @ 0x0040668c ====

void Catch_0040668c(void)

{
  FUN_00406250();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004066a0 @ 0x004066a0 ====

void FUN_004066a0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x1c != 0) {
      iVar1 = (param_2 - iVar1) / 0x1c;
      goto LAB_004066e9;
    }
  }
  iVar1 = 0;
LAB_004066e9:
  FUN_004062c0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x1c;
  return;
}


// ==== FUN_00406720 @ 0x00406720 ====

void FUN_00406720(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x1c) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x1c))) {
    FUN_004066a0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00405fe0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x1c;
  return;
}


// ==== FUN_004067b0 @ 0x004067b0 ====

void FUN_004067b0(void)

{
  if (DAT_00b5a6b0 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a6b0)(1);
  }
  return;
}


// ==== FUN_004067d0 @ 0x004067d0 ====

void FUN_004067d0(void)

{
  void *pvVar1;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00977f74;
  local_c = ExceptionList;
  if (DAT_00b5a6b0 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x10);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
      FUN_00401740(s_Locale_txt_0099caa8,10);
      local_4 = CONCAT31(local_4._1_3_,1);
      FUN_00410470(local_28);
      if (0xf < local_10) {
        _free(local_24);
        return;
      }
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00406880 @ 0x00406880 ====

void FUN_00406880(void)

{
  return;
}


// ==== FUN_00406890 @ 0x00406890 ====

void FUN_00406890(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00406896. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_004068b0 @ 0x004068b0 ====

void FUN_004068b0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void *_Memory;
  undefined4 *puVar5;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x18);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if ((undefined4 *)puVar3[4] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)puVar3[4])(1);
    }
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
  _Memory = *(void **)(*(int *)(in_ECX + 0x18) + 4);
  if (*(char *)((int)_Memory + 0x15) == '\0') {
    FUN_00408110(*(undefined4 *)((int)_Memory + 8));
    _free(_Memory);
    return;
  }
  *(int *)(*(int *)(in_ECX + 0x18) + 4) = *(int *)(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x18);
  *(int *)(*(int *)(in_ECX + 0x18) + 8) = *(int *)(in_ECX + 0x18);
  return;
}


// ==== FUN_00406970 @ 0x00406970 ====

undefined4 FUN_00406970(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  (**(code **)(*(int *)(in_ECX + 4) + 4))(param_1,param_2);
  return param_1;
}


// ==== FUN_004069a0 @ 0x004069a0 ====

void FUN_004069a0(undefined1 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_0079bba0(&local_4,&param_1);
  if (local_4 != *(int *)(in_ECX + 0x18)) {
    (**(code **)(**(int **)(local_4 + 0x10) + 8))(param_2,param_3);
  }
  return;
}


// ==== FUN_004069e0 @ 0x004069e0 ====

undefined4 FUN_004069e0(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_path_action_0099cb14,0xb);
  if (iVar2 == 0) {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_path_texture_0099cb20,0xc);
  if (iVar2 == 0) {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_path_map_0099cb30,8);
  if (iVar2 == 0) {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_mapobject_0099cb3c);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_mapkeepout_0099cb4c);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_mapeffect_0099cb5c);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_mappack_0099cb6c);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_anidesc_0099cb7c);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_actiondesc_0099cb8c);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_bone_0099cb9c);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_bonemesh_0099cba8);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_boneanimation_0099cbb8);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_shader_0099cbcc);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_objectpack_0099cbd8);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_simpleobject_0099cbe8);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_effect_0099cbfc);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_water_0099cc08);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_property_0099cc14);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_texturepack_0099cc24);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_effectpd_0099cc38);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_script_0099cc48);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_luascript_0099cc54);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_preload_0099cc64);
  if (cVar1 != '\0') {
    FUN_00401660(param_2,0,0xffffffff);
    return 1;
  }
  cVar1 = FUN_004036a0(param_1,s_path_sound_0099cc74);
  if (cVar1 == '\0') {
    return 0;
  }
  FUN_00401660(param_2,0,0xffffffff);
  return 1;
}


// ==== FUN_00406e30 @ 0x00406e30 ====

int FUN_00406e30(int param_1,undefined1 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int extraout_EAX;
  int extraout_EAX_00;
  int in_ECX;
  int local_48;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 local_28 [4];
  void *pvStack_24;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00977f90;
  pvStack_c = ExceptionList;
  local_48 = 0;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(&DAT_0099ccf7,0);
  local_4 = 0;
  FUN_0079bba0(&local_48,&param_2);
  if (local_48 != *(int *)(in_ECX + 0x18)) {
    uVar1 = (**(code **)(**(int **)(local_48 + 0x10) + 4))(local_28,param_3);
    local_4._0_1_ = 1;
    FUN_00401660(uVar1,0,0xffffffff);
    local_4 = (uint)local_4._1_3_ << 8;
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return extraout_EAX;
    }
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_44,0,0xffffffff);
  if (local_2c < 0x10) {
    ExceptionList = pvStack_c;
    return param_1;
  }
  _free(local_40);
  return extraout_EAX_00;
}


// ==== FUN_00406f20 @ 0x00406f20 ====

void FUN_00406f20(void *param_1)

{
  int in_ECX;
  void *local_1c;
  undefined4 local_18;
  undefined1 local_14 [8];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00977fa5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0079bba0(&local_1c,&param_1);
  if (local_1c == *(void **)(in_ECX + 0x18)) {
    local_1c = operator_new(0x10);
    local_4 = 0;
    if (local_1c == (void *)0x0) {
      local_18 = 0;
    }
    else {
      local_18 = FUN_00410b20();
    }
    local_4 = 0xffffffff;
    local_1c = param_1;
    FUN_00408bb0(local_14,&local_1c);
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00406fc0 @ 0x00406fc0 ====

void FUN_00406fc0(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00977fd8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099cd88;
  local_4 = 3;
  FUN_004068b0();
  FUN_004081b0();
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00408c70(local_10,*(undefined4 *)in_ECX[6],(undefined4 *)in_ECX[6]);
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_00407050 @ 0x00407050 ====

/* WARNING: Removing unreachable block (ram,0x00407107) */
/* WARNING: Removing unreachable block (ram,0x00407125) */
/* WARNING: Removing unreachable block (ram,0x00407139) */
/* WARNING: Removing unreachable block (ram,0x0040714a) */
/* WARNING: Removing unreachable block (ram,0x0040717e) */

void FUN_00407050(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_56 [10];
  undefined1 auStack_4c [4];
  void *pvStack_48;
  undefined4 uStack_38;
  uint uStack_34;
  void *pvStack_2c;
  undefined1 local_28 [16];
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00977ffa;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00405bd0(local_28,param_1,param_2);
  local_4 = 0;
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a740 + 4))(local_28,9);
  uVar5 = 0;
  iVar2 = FUN_00411430();
  if (iVar2 != 0) {
    do {
      pvStack_c._0_1_ = 1;
      uVar3 = FUN_00411510(uVar5);
      uStack_34 = 0xf;
      uStack_38 = 0;
      pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
      FUN_00401660(uVar3,0,0xffffffff);
      pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
      FUN_00405670(auStack_4c,auStack_56 + -6);
      if (0xf < uStack_34) {
        _free(pvStack_48);
        return;
      }
      uStack_34 = 0xf;
      uStack_38 = 0;
      pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
      pvStack_c = (void *)((uint)pvStack_c & 0xffffff00);
      uVar5 = uVar5 + 1;
      uVar4 = FUN_00411430();
    } while (uVar5 < uVar4);
  }
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
  }
  if (uStack_18 < 0x10) {
    ExceptionList = pvStack_14;
    return;
  }
  _free(pvStack_2c);
  return;
}


// ==== FUN_00407200 @ 0x00407200 ====

/* WARNING: Removing unreachable block (ram,0x00407681) */
/* WARNING: Removing unreachable block (ram,0x004075f8) */

void FUN_00407200(undefined1 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  void *in_ECX;
  uint unaff_EBX;
  void *unaff_EBP;
  uint uVar4;
  uint unaff_ESI;
  int *piVar5;
  void *unaff_EDI;
  undefined1 **_Memory;
  undefined1 auStack_aa [2];
  undefined1 *puVar6;
  undefined1 *puVar7;
  uint *puStack_94;
  void *pvVar8;
  undefined4 uStack_8c;
  undefined1 *puVar9;
  undefined4 uStack_84;
  undefined1 *puVar10;
  undefined1 *puStack_7c;
  undefined4 uStack_78;
  undefined4 local_64;
  void *pvStack_60;
  uint uStack_5c;
  void *pvStack_58;
  uint uStack_54;
  void *pvStack_50;
  uint uStack_4c;
  void *pvStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  undefined1 uStack_2c;
  undefined1 local_28 [4];
  undefined1 uStack_24;
  undefined1 uStack_1c;
  undefined1 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009780bc;
  pvStack_c = ExceptionList;
  uStack_78 = (void *)param_2;
  puStack_7c = param_1;
  uStack_84 = (uint *)0x407236;
  ExceptionList = &pvStack_c;
  local_64 = in_ECX;
  FUN_00405bd0();
  uStack_78 = (void *)0x9;
  puStack_7c = local_28;
  local_4 = 0;
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a740 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    uStack_84 = (uint *)&DAT_0099cc80;
    pvStack_50 = (void *)0xf;
    uStack_54 = 0;
    local_64 = (uint *)((uint)local_64 & 0xffffff00);
    FUN_00401740();
    uStack_84 = (uint *)&DAT_0099cc84;
    pvStack_c._0_1_ = 1;
    uStack_34 = 0xf;
    uStack_38 = 0;
    pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
    FUN_00401740();
    puVar10 = local_28 + -0x40;
    piVar5 = (int *)((int)in_ECX + 4);
    uStack_84 = &uStack_4c;
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
    (**(code **)(*(int *)((int)in_ECX + 4) + 8))();
    if (0xf < uStack_3c) {
      uStack_8c = (uint *)0x4072cc;
      _free(pvStack_50);
      return;
    }
    uStack_3c = 0xf;
    uStack_40 = 0;
    pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
    uStack_14 = 0;
    if (0xf < pvStack_58) {
      uStack_8c = (uint *)0x4072ef;
      _free(unaff_EBP);
      return;
    }
    uStack_8c = (uint *)&DAT_0099cc8c;
    pvStack_58 = (void *)0xf;
    uStack_5c = 0;
    FUN_00401740();
    uStack_8c = (uint *)&DAT_0099cc90;
    uStack_14 = 3;
    uStack_3c = 0xf;
    uStack_40 = 0;
    pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
    FUN_00401740();
    puVar9 = auStack_aa + 0x3a;
    uStack_8c = &uStack_54;
    uStack_14 = 4;
    (**(code **)(*piVar5 + 8))();
    if (0xf < uStack_44) {
      puStack_94 = (uint *)0x407355;
      _free(pvStack_58);
      return;
    }
    uStack_44 = 0xf;
    pvStack_48 = (void *)0x0;
    pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
    uStack_1c = 0;
    if (0xf < pvStack_60) {
      puStack_94 = (uint *)0x407378;
      _free(unaff_EDI);
      return;
    }
    puStack_94 = (uint *)&DAT_0099cc98;
    pvStack_60 = (void *)0xf;
    local_64 = (uint *)0x0;
    FUN_00401740();
    puStack_94 = (uint *)&DAT_0099cc9c;
    uStack_1c = 5;
    uStack_44 = 0xf;
    pvStack_48 = (void *)0x0;
    pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
    FUN_00401740();
    puVar1 = &uStack_78;
    puStack_94 = &uStack_5c;
    uStack_1c = 6;
    (**(code **)(*piVar5 + 8))();
    if (0xf < uStack_4c) {
      _free(pvStack_60);
      return;
    }
    uStack_4c = 0xf;
    pvStack_50 = (void *)0x0;
    pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
    uStack_24 = 0;
    if (0xf < unaff_EBX) {
      _free(puStack_7c);
      return;
    }
    puStack_7c = (undefined1 *)((uint)puStack_7c & 0xffffff00);
    FUN_00401740();
    uStack_24 = 7;
    uStack_4c = 0xf;
    pvStack_50 = (void *)0x0;
    pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
    FUN_00401740();
    puVar7 = auStack_aa + 0x2a;
    uStack_24 = 8;
    (**(code **)(*piVar5 + 8))();
    if (0xf < uStack_54) {
      _free((void *)0xf);
      return;
    }
    uStack_54 = 0xf;
    pvStack_58 = (void *)0x0;
    uStack_2c = 0;
    if (0xf < unaff_ESI) {
      _free(uStack_84);
      return;
    }
    uStack_84 = (uint *)((uint)uStack_84 & 0xffffff00);
    FUN_00401740();
    uStack_2c = 9;
    uStack_54 = 0xf;
    pvStack_58 = (void *)0x0;
    FUN_00401740();
    puVar6 = auStack_aa + 0x22;
    uStack_2c = 10;
    (**(code **)(*piVar5 + 8))();
    if (0xf < uStack_5c) {
      _free((void *)0xf);
      return;
    }
    uStack_5c = 0xf;
    pvStack_60 = (void *)0x0;
    uStack_34 = uStack_34 & 0xffffff00;
    if (0xf < uStack_78) {
      _free(uStack_8c);
      return;
    }
    uStack_78 = (void *)0xf;
    puStack_7c = (undefined1 *)0x0;
    uStack_8c = (uint *)((uint)uStack_8c & 0xffffff00);
    FUN_00401740();
    uStack_34._0_1_ = 0xb;
    uStack_5c = 0xf;
    pvStack_60 = (void *)0x0;
    FUN_00401740();
    uStack_34 = CONCAT31(uStack_34._1_3_,0xc);
    (**(code **)(*piVar5 + 8))();
    if (0xf < local_64) {
      _free(uStack_78);
      return;
    }
    local_64 = (uint *)0xf;
    uStack_78 = (void *)((uint)uStack_78 & 0xffffff00);
    uStack_3c = uStack_3c & 0xffffff00;
    if ((undefined1 *)0xf < puVar10) {
      _free(puStack_94);
      return;
    }
    uStack_84 = (uint *)0x0;
    puStack_94 = (uint *)((uint)puStack_94 & 0xffffff00);
    FUN_00401740(&DAT_0099ccc8);
    uStack_3c._0_1_ = 0xd;
    local_64 = (void *)0xf;
    unaff_EBX = 0;
    uStack_78 = (void *)((uint)uStack_78 & 0xffffff00);
    FUN_00401740(&DAT_0099cccc);
    _Memory = &puStack_7c;
    uStack_3c = CONCAT31(uStack_3c._1_3_,0xe);
    (**(code **)(*piVar5 + 8))();
    uStack_44 = uStack_44 & 0xffffff00;
    if ((undefined1 *)0xf < puVar9) {
      _free(&local_64);
      return;
    }
    uStack_8c = (uint *)0x0;
    FUN_00401740(&DAT_0099ccd4,1);
    uStack_44._0_1_ = 0xf;
    FUN_00401740(&DAT_0099ccd8,5);
    uStack_44 = CONCAT31(uStack_44._1_3_,0x10);
    (**(code **)(*piVar5 + 8))(&uStack_84,auStack_aa + 10);
    uStack_78 = (void *)0x0;
    uStack_4c = uStack_4c & 0xffffff00;
    if ((undefined4 *)0xf < puVar1) {
      _free(auStack_aa + 0x3e);
      return;
    }
    pvVar8 = (void *)0xf;
    puStack_94 = (uint *)0x0;
    FUN_00401740(&DAT_0099cce0,1);
    uStack_4c._0_1_ = 0x11;
    uStack_78 = (void *)0x0;
    FUN_00401740(&DAT_0099cce4,5);
    uStack_4c = CONCAT31(uStack_4c._1_3_,0x12);
    (**(code **)(*piVar5 + 8))(&uStack_8c,auStack_aa + 2);
    if ((undefined1 *)0xf < puStack_7c) {
      _free(pvVar8);
      return;
    }
    puStack_7c = (undefined1 *)0xf;
    uStack_54 = uStack_54 & 0xffffff00;
    if ((undefined1 *)0xf < puVar7) {
      _free(auStack_aa + 0x36);
      return;
    }
    pvVar8 = (void *)0xf;
    FUN_00401740(&DAT_0099ccec,1);
    uStack_54._0_1_ = 0x13;
    puStack_7c = (undefined1 *)0xf;
    FUN_00401740(&DAT_0099ccf0,6);
    uStack_54 = CONCAT31(uStack_54._1_3_,0x14);
    (**(code **)(*piVar5 + 8))(&puStack_94,auStack_aa + -6);
    if (0xf < uStack_84) {
      _free(pvVar8);
      return;
    }
    uStack_84 = (uint *)0xf;
    if ((undefined1 *)0xf < puVar6) {
      _free(_Memory);
      return;
    }
  }
  else {
    uVar4 = 0;
    iVar2 = FUN_00411430();
    if (iVar2 != 0) {
      do {
        local_64 = (uint *)0x0;
        pvStack_60 = (void *)0x0;
        uStack_5c = 0;
        pvStack_c._0_1_ = 0x15;
        uStack_84 = (uint *)0x4077f9;
        FUN_00411510();
        uStack_84 = (uint *)0x0;
        uStack_34 = 0xf;
        uStack_38 = 0;
        pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
        uStack_8c = (uint *)0x407816;
        FUN_00401660();
        uStack_84 = &uStack_4c;
        pvStack_c._0_1_ = 0x16;
        FUN_00405670();
        if ((local_64 == (uint *)0x0) || ((uint)(((int)pvStack_60 - (int)local_64) / 0x1c) < 2)) {
          if (0xf < uStack_34) {
            uStack_84 = (uint *)0x407864;
            _free(pvStack_48);
            return;
          }
        }
        else {
          uStack_84 = local_64;
          (**(code **)(*(int *)((int)unaff_EBP + 4) + 8))();
          if (0xf < uStack_34) {
            uStack_84 = (uint *)0x4078b8;
            _free(pvStack_48);
            return;
          }
        }
        pvStack_c = (void *)((uint)pvStack_c._1_3_ << 8);
        pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
        if (local_64 != (uint *)0x0) {
          uStack_34 = 0xf;
          uStack_38 = 0;
          uStack_84 = (uint *)(local_28 + -0x40);
          uStack_8c = local_64;
          FUN_00405de0();
          puStack_94 = (uint *)0x4078f6;
          _free(local_64);
          return;
        }
        uStack_34 = 0xf;
        uStack_38 = 0;
        local_64 = (void *)0x0;
        pvStack_60 = (void *)0x0;
        uStack_5c = 0;
        uVar4 = uVar4 + 1;
        uVar3 = FUN_00411430();
      } while (uVar4 < uVar3);
    }
    uStack_84 = (uint *)0x40791f;
    (**(code **)*puVar1)();
  }
  if (unaff_EBX < 0x10) {
    ExceptionList = local_64;
    return;
  }
  _free(puStack_7c);
  return;
}


// ==== FUN_00407950 @ 0x00407950 ====

void FUN_00407950(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_0079bba0(&local_4,&param_1);
  if (local_4 != *(int *)(in_ECX + 0x18)) {
    if (*(undefined4 **)(local_4 + 0x10) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(local_4 + 0x10))(1);
    }
    FUN_00408d30(&param_1);
  }
  return;
}


// ==== FUN_004079a0 @ 0x004079a0 ====

void FUN_004079a0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009780d9;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099cd88;
  FUN_00410b20();
  local_4 = CONCAT31(local_4._1_3_,1);
  iVar1 = FUN_0058d7c0();
  in_ECX[6] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[6] + 4) = in_ECX[6];
  *(undefined4 *)in_ECX[6] = in_ECX[6];
  *(undefined4 *)(in_ECX[6] + 8) = in_ECX[6];
  in_ECX[7] = 0;
  FUN_00408570();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00407a20 @ 0x00407a20 ====

void FUN_00407a20(void)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  int in_ECX;
  uint unaff_EBX;
  undefined3 unaff_EBP;
  int *piVar5;
  void *unaff_EDI;
  void **_Memory;
  undefined4 uStack_f0;
  void *local_ec;
  void *local_e8;
  void *pvStack_e4;
  undefined4 uStack_e0;
  void *pvStack_dc;
  uint local_d8;
  uint local_d4;
  void *pvStack_d0;
  undefined4 uStack_cc;
  uint uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  uint uStack_bc;
  void *pvStack_b8;
  void *local_b4;
  undefined1 local_b0 [4];
  void *pvStack_ac;
  undefined1 auStack_a8 [4];
  uint uStack_a4;
  uint local_a0;
  void *local_9c;
  uint uStack_98;
  undefined4 uStack_8c;
  void *pvStack_88;
  void *local_7c;
  void *local_78;
  uint uStack_74;
  undefined4 uStack_6c;
  uint local_68;
  uint local_64;
  void *local_60 [4];
  undefined4 uStack_50;
  uint uStack_4c;
  void *local_44;
  undefined1 auStack_40 [16];
  uint uStack_30;
  void *pvStack_2c;
  undefined1 uStack_1c;
  void *pvStack_18;
  undefined1 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009781c3;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  FUN_00404890();
  local_4._0_1_ = 1;
  FUN_004045b0(&local_44);
  local_4._0_1_ = 3;
  if (0xf < local_d4) {
    _free(local_e8);
    return;
  }
  local_d4 = 0xf;
  local_d8 = 0;
  local_e8 = (void *)((uint)local_e8 & 0xffffff00);
  uVar2 = FUN_004046f0(&local_7c);
  local_4._0_1_ = 4;
  FUN_00402220(local_60,uVar2,s_Data__0099caf0);
  local_4._0_1_ = 6;
  if (0xf < local_64) {
    _free(local_78);
    return;
  }
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  FUN_00407050(local_60);
  local_9c = (void *)0xf;
  local_a0 = 0;
  local_b0[0] = 0;
  pcVar3 = PTR_s_PackIO_00adb190;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_s_PackIO_00adb190);
  piVar5 = (int *)(in_ECX + 4);
  _Memory = &local_ec;
  local_4 = CONCAT31(local_4._1_3_,7);
  iVar4 = (**(code **)(*(int *)(in_ECX + 4) + 4))();
  pvStack_c._0_1_ = 8;
  iVar4 = FUN_00403620(0,*(undefined4 *)(iVar4 + 0x14),&DAT_0099caf8,1);
  if (0xf < pvStack_dc) {
    _free(uStack_f0);
    return;
  }
  pvStack_dc = (void *)0xf;
  uStack_e0 = 0;
  uStack_f0 = (void *)((uint)uStack_f0 & 0xffffff00);
  pvStack_c._0_1_ = 6;
  if (0xf < uStack_a4) {
    _free(pvStack_b8);
    return;
  }
  if (iVar4 == 0) {
    uVar2 = FUN_00404890(local_b0 + -0x44);
    pvStack_c._0_1_ = 9;
    FUN_004045b0(&local_a0,uVar2);
    pvStack_c._0_1_ = 0xb;
    if (0xf < pvStack_dc) {
      _free(uStack_f0);
      return;
    }
    pvStack_dc = (void *)0xf;
    uStack_c0 = 0xf;
    uStack_e0 = 0;
    uStack_c4 = 0;
    local_d4 = local_d4 & 0xffffff00;
    pcVar3 = PTR_s_BinaryPath_00adb184;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_s_BinaryPath_00adb184,(int)pcVar3 - (int)(PTR_s_BinaryPath_00adb184 + 1));
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,0xc);
    (**(code **)(*piVar5 + 8))(&local_d8,&local_a0);
    uStack_14 = 0xb;
    if (0xf < uStack_c8) {
      _free(pvStack_dc);
      return;
    }
    uVar2 = FUN_004046f0(&uStack_8c,auStack_a8);
    uStack_14 = 0xd;
    FUN_00402220(&uStack_c4,uVar2,s_Data__0099cafc);
    uStack_14 = 0xf;
    if (0xf < uStack_74) {
      _free(pvStack_88);
      return;
    }
    uStack_74 = 0xf;
    uStack_c8 = 0xf;
    local_78 = (void *)0x0;
    pvStack_88 = (void *)((uint)pvStack_88 & 0xffffff00);
    uStack_cc = 0;
    pvStack_dc = (void *)((uint)pvStack_dc & 0xffffff00);
    pcVar3 = PTR_s_DataPath_00adb188;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_s_DataPath_00adb188,(int)pcVar3 - (int)(PTR_s_DataPath_00adb188 + 1));
    uStack_14 = 0x10;
    (**(code **)(*piVar5 + 8))(&uStack_e0,&uStack_c4);
    uStack_1c = 0xf;
    if ((void *)0xf < pvStack_d0) {
      _free(pvStack_e4);
      return;
    }
    pvStack_d0 = (void *)0xf;
    local_ec = (void *)0xf;
    local_d4 = 0;
    pvStack_e4 = (void *)((uint)pvStack_e4 & 0xffffff00);
    pcVar3 = PTR_s_RealDataPath_00adb18c;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_s_RealDataPath_00adb18c,(int)pcVar3 - (int)(PTR_s_RealDataPath_00adb18c + 1));
    uStack_1c = 0x11;
    (**(code **)(*piVar5 + 8))(local_b0 + -0x54,&uStack_cc);
    if (0xf < unaff_EBX) {
      _free(_Memory);
      return;
    }
    if (0xf < uStack_bc) {
      _free(pvStack_d0);
      return;
    }
    pvStack_d0 = (void *)((uint)pvStack_d0 & 0xffffff00);
    if (local_a0 < 0x10) goto LAB_0040803f;
  }
  else {
    uVar2 = FUN_00404890(&local_a0);
    pvStack_c._0_1_ = 0x12;
    FUN_004045b0(&uStack_30,uVar2);
    pvStack_c._0_1_ = 0x14;
    if ((void *)0xf < pvStack_88) {
      _free(local_9c);
      return;
    }
    pvStack_88 = (void *)0xf;
    pvStack_dc = (void *)0xf;
    uStack_8c = 0;
    local_9c = (void *)((uint)local_9c & 0xffffff00);
    uStack_e0 = 0;
    pcVar3 = PTR_s_BinaryPath_00adb184;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_s_BinaryPath_00adb184,(int)pcVar3 - (int)(PTR_s_BinaryPath_00adb184 + 1));
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,0x15);
    (**(code **)(*piVar5 + 8))(local_b0 + -0x44,&uStack_30);
    uStack_14 = 0x14;
    if ((void *)0xf < pvStack_e4) {
      _free((void *)CONCAT13(iVar4 == 0,unaff_EBP));
      return;
    }
    uStack_c8 = 0xf;
    uStack_cc = 0;
    pvStack_dc = (void *)((uint)pvStack_dc & 0xffffff00);
    FUN_00401740(s_Data__0099cb04,5);
    pvStack_e4 = (void *)0xf;
    uStack_14 = 0x16;
    local_e8 = (void *)0x0;
    pcVar3 = PTR_s_DataPath_00adb188;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_s_DataPath_00adb188,(int)pcVar3 - (int)(PTR_s_DataPath_00adb188 + 1));
    uStack_14 = 0x17;
    (**(code **)(*piVar5 + 8))(local_b0 + -0x4c,&uStack_e0);
    uStack_1c = 0x16;
    if ((void *)0xf < local_ec) {
      _free(unaff_EDI);
      return;
    }
    uVar2 = FUN_004046f0(local_b0,auStack_40);
    uStack_1c = 0x18;
    FUN_00402220(&uStack_cc,uVar2,s_Data__0099cb0c);
    uStack_1c = 0x1a;
    if (0xf < uStack_98) {
      _free(pvStack_ac);
      return;
    }
    uStack_98 = 0xf;
    local_ec = (void *)0xf;
    local_9c = (void *)0x0;
    pvStack_ac = (void *)((uint)pvStack_ac & 0xffffff00);
    pcVar3 = PTR_s_RealDataPath_00adb18c;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_s_RealDataPath_00adb18c,(int)pcVar3 - (int)(PTR_s_RealDataPath_00adb18c + 1));
    uStack_1c = 0x1b;
    (**(code **)(*piVar5 + 8))(local_b0 + -0x54,&uStack_cc);
    if (0xf < unaff_EBX) {
      _free(_Memory);
      return;
    }
    if (0xf < uStack_bc) {
      _free(pvStack_d0);
      return;
    }
    uStack_bc = 0xf;
    uStack_c0 = 0;
    pvStack_d0 = (void *)((uint)pvStack_d0 & 0xffffff00);
    if (0xf < local_d8) {
      _free(local_ec);
      return;
    }
    local_d8 = 0xf;
    pvStack_dc = (void *)0x0;
    local_ec = (void *)((uint)local_ec & 0xffffff00);
    if (uStack_30 < 0x10) {
LAB_0040803f:
      uStack_bc = 0xf;
      uStack_c0 = 0;
      if (0xf < local_68) {
        _free(local_7c);
        return;
      }
      local_68 = 0xf;
      uStack_6c = 0;
      local_7c = (void *)((uint)local_7c & 0xffffff00);
      if (0xf < uStack_4c) {
        _free(local_60[0]);
        return;
      }
      uStack_4c = 0xf;
      uStack_50 = 0;
      local_60[0] = (void *)((uint)local_60[0] & 0xffffff00);
      if (local_4 < 0x10) {
        ExceptionList = pvStack_2c;
        return;
      }
      _free(pvStack_18);
      return;
    }
    local_b4 = local_44;
  }
  uStack_bc = 0xf;
  uStack_c0 = 0;
  _free(local_b4);
  return;
}


// ==== FUN_004080e0 @ 0x004080e0 ====

void FUN_004080e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099cd30;
  return;
}


// ==== FUN_004080f0 @ 0x004080f0 ====

void FUN_004080f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099cd30;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00408110 @ 0x00408110 ====

void FUN_00408110(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_00408110(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00408150 @ 0x00408150 ====

void FUN_00408150(int *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar4 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar4[1] + 0x15) == '\0') {
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
    } while (*(char *)((int)puVar2 + 0x15) == '\0');
  }
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar1[1] + 0x15) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x15) == '\0');
  }
  *param_1 = (int)puVar1;
  param_1[1] = (int)puVar4;
  return;
}


// ==== FUN_004081b0 @ 0x004081b0 ====

void FUN_004081b0(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x2a8)) {
    _free(*(void **)(in_ECX + 0x294));
    return;
  }
  *(undefined4 *)(in_ECX + 0x2a8) = 0xf;
  *(undefined4 *)(in_ECX + 0x2a4) = 0;
  *(undefined1 *)(in_ECX + 0x294) = 0;
  if (0xf < *(uint *)(in_ECX + 0x28c)) {
    _free(*(void **)(in_ECX + 0x278));
    return;
  }
  *(undefined4 *)(in_ECX + 0x28c) = 0xf;
  *(undefined4 *)(in_ECX + 0x288) = 0;
  *(undefined1 *)(in_ECX + 0x278) = 0;
  if (0xf < *(uint *)(in_ECX + 0x270)) {
    _free(*(void **)(in_ECX + 0x25c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x270) = 0xf;
  *(undefined4 *)(in_ECX + 0x26c) = 0;
  *(undefined1 *)(in_ECX + 0x25c) = 0;
  if (0xf < *(uint *)(in_ECX + 0x254)) {
    _free(*(void **)(in_ECX + 0x240));
    return;
  }
  *(undefined4 *)(in_ECX + 0x254) = 0xf;
  *(undefined4 *)(in_ECX + 0x250) = 0;
  *(undefined1 *)(in_ECX + 0x240) = 0;
  if (0xf < *(uint *)(in_ECX + 0x238)) {
    _free(*(void **)(in_ECX + 0x224));
    return;
  }
  *(undefined4 *)(in_ECX + 0x238) = 0xf;
  *(undefined4 *)(in_ECX + 0x234) = 0;
  *(undefined1 *)(in_ECX + 0x224) = 0;
  if (0xf < *(uint *)(in_ECX + 0x21c)) {
    _free(*(void **)(in_ECX + 0x208));
    return;
  }
  *(undefined4 *)(in_ECX + 0x21c) = 0xf;
  *(undefined4 *)(in_ECX + 0x218) = 0;
  *(undefined1 *)(in_ECX + 0x208) = 0;
  if (0xf < *(uint *)(in_ECX + 0x200)) {
    _free(*(void **)(in_ECX + 0x1ec));
    return;
  }
  *(undefined4 *)(in_ECX + 0x200) = 0xf;
  *(undefined4 *)(in_ECX + 0x1fc) = 0;
  *(undefined1 *)(in_ECX + 0x1ec) = 0;
  if (0xf < *(uint *)(in_ECX + 0x1e4)) {
    _free(*(void **)(in_ECX + 0x1d0));
    return;
  }
  *(undefined4 *)(in_ECX + 0x1e4) = 0xf;
  *(undefined4 *)(in_ECX + 0x1e0) = 0;
  *(undefined1 *)(in_ECX + 0x1d0) = 0;
  if (0xf < *(uint *)(in_ECX + 0x1c8)) {
    _free(*(void **)(in_ECX + 0x1b4));
    return;
  }
  *(undefined4 *)(in_ECX + 0x1c8) = 0xf;
  *(undefined4 *)(in_ECX + 0x1c4) = 0;
  *(undefined1 *)(in_ECX + 0x1b4) = 0;
  if (0xf < *(uint *)(in_ECX + 0x1ac)) {
    _free(*(void **)(in_ECX + 0x198));
    return;
  }
  *(undefined4 *)(in_ECX + 0x1ac) = 0xf;
  *(undefined4 *)(in_ECX + 0x1a8) = 0;
  *(undefined1 *)(in_ECX + 0x198) = 0;
  if (0xf < *(uint *)(in_ECX + 400)) {
    _free(*(void **)(in_ECX + 0x17c));
    return;
  }
  *(undefined4 *)(in_ECX + 400) = 0xf;
  *(undefined4 *)(in_ECX + 0x18c) = 0;
  *(undefined1 *)(in_ECX + 0x17c) = 0;
  if (0xf < *(uint *)(in_ECX + 0x174)) {
    _free(*(void **)(in_ECX + 0x160));
    return;
  }
  *(undefined4 *)(in_ECX + 0x174) = 0xf;
  *(undefined4 *)(in_ECX + 0x170) = 0;
  *(undefined1 *)(in_ECX + 0x160) = 0;
  if (0xf < *(uint *)(in_ECX + 0x158)) {
    _free(*(void **)(in_ECX + 0x144));
    return;
  }
  *(undefined4 *)(in_ECX + 0x158) = 0xf;
  *(undefined4 *)(in_ECX + 0x154) = 0;
  *(undefined1 *)(in_ECX + 0x144) = 0;
  if (0xf < *(uint *)(in_ECX + 0x13c)) {
    _free(*(void **)(in_ECX + 0x128));
    return;
  }
  *(undefined4 *)(in_ECX + 0x13c) = 0xf;
  *(undefined4 *)(in_ECX + 0x138) = 0;
  *(undefined1 *)(in_ECX + 0x128) = 0;
  if (0xf < *(uint *)(in_ECX + 0x120)) {
    _free(*(void **)(in_ECX + 0x10c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x120) = 0xf;
  *(undefined4 *)(in_ECX + 0x11c) = 0;
  *(undefined1 *)(in_ECX + 0x10c) = 0;
  if (0xf < *(uint *)(in_ECX + 0x104)) {
    _free(*(void **)(in_ECX + 0xf0));
    return;
  }
  *(undefined4 *)(in_ECX + 0x104) = 0xf;
  *(undefined4 *)(in_ECX + 0x100) = 0;
  *(undefined1 *)(in_ECX + 0xf0) = 0;
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
  if (0xf < *(uint *)(in_ECX + 0xb0)) {
    _free(*(void **)(in_ECX + 0x9c));
    return;
  }
  *(undefined4 *)(in_ECX + 0xb0) = 0xf;
  *(undefined4 *)(in_ECX + 0xac) = 0;
  *(undefined1 *)(in_ECX + 0x9c) = 0;
  if (0xf < *(uint *)(in_ECX + 0x94)) {
    _free(*(void **)(in_ECX + 0x80));
    return;
  }
  *(undefined4 *)(in_ECX + 0x94) = 0xf;
  *(undefined4 *)(in_ECX + 0x90) = 0;
  *(undefined1 *)(in_ECX + 0x80) = 0;
  if (0xf < *(uint *)(in_ECX + 0x78)) {
    _free(*(void **)(in_ECX + 100));
    return;
  }
  *(undefined4 *)(in_ECX + 0x78) = 0xf;
  *(undefined4 *)(in_ECX + 0x74) = 0;
  *(undefined1 *)(in_ECX + 100) = 0;
  if (0xf < *(uint *)(in_ECX + 0x5c)) {
    _free(*(void **)(in_ECX + 0x48));
    return;
  }
  *(undefined4 *)(in_ECX + 0x5c) = 0xf;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined1 *)(in_ECX + 0x48) = 0;
  if (0xf < *(uint *)(in_ECX + 0x40)) {
    _free(*(void **)(in_ECX + 0x2c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x40) = 0xf;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  if (*(uint *)(in_ECX + 0x24) < 0x10) {
    *(undefined4 *)(in_ECX + 0x24) = 0xf;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    *(undefined1 *)(in_ECX + 0x10) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x10));
  return;
}


// ==== FUN_00408570 @ 0x00408570 ====

void FUN_00408570(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 1;
  in_ECX[1] = 1;
  in_ECX[2] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0xf;
  *(undefined1 *)(in_ECX + 4) = 0;
  in_ECX[0x10] = 0xf;
  in_ECX[0xf] = 0;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  in_ECX[0x17] = 0xf;
  in_ECX[0x16] = 0;
  *(undefined1 *)(in_ECX + 0x12) = 0;
  in_ECX[0x1e] = 0xf;
  in_ECX[0x1d] = 0;
  *(undefined1 *)(in_ECX + 0x19) = 0;
  in_ECX[0x25] = 0xf;
  in_ECX[0x24] = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  in_ECX[0x2c] = 0xf;
  in_ECX[0x2b] = 0;
  *(undefined1 *)(in_ECX + 0x27) = 0;
  in_ECX[0x33] = 0xf;
  in_ECX[0x32] = 0;
  *(undefined1 *)(in_ECX + 0x2e) = 0;
  in_ECX[0x3a] = 0xf;
  in_ECX[0x39] = 0;
  *(undefined1 *)(in_ECX + 0x35) = 0;
  in_ECX[0x41] = 0xf;
  in_ECX[0x40] = 0;
  *(undefined1 *)(in_ECX + 0x3c) = 0;
  in_ECX[0x48] = 0xf;
  in_ECX[0x47] = 0;
  *(undefined1 *)(in_ECX + 0x43) = 0;
  in_ECX[0x4f] = 0xf;
  in_ECX[0x4e] = 0;
  *(undefined1 *)(in_ECX + 0x4a) = 0;
  in_ECX[0x56] = 0xf;
  in_ECX[0x55] = 0;
  *(undefined1 *)(in_ECX + 0x51) = 0;
  in_ECX[0x5d] = 0xf;
  in_ECX[0x5c] = 0;
  *(undefined1 *)(in_ECX + 0x58) = 0;
  in_ECX[100] = 0xf;
  in_ECX[99] = 0;
  *(undefined1 *)(in_ECX + 0x5f) = 0;
  in_ECX[0x6b] = 0xf;
  in_ECX[0x6a] = 0;
  *(undefined1 *)(in_ECX + 0x66) = 0;
  in_ECX[0x72] = 0xf;
  in_ECX[0x71] = 0;
  *(undefined1 *)(in_ECX + 0x6d) = 0;
  in_ECX[0x79] = 0xf;
  in_ECX[0x78] = 0;
  *(undefined1 *)(in_ECX + 0x74) = 0;
  in_ECX[0x80] = 0xf;
  in_ECX[0x7f] = 0;
  *(undefined1 *)(in_ECX + 0x7b) = 0;
  in_ECX[0x87] = 0xf;
  in_ECX[0x86] = 0;
  *(undefined1 *)(in_ECX + 0x82) = 0;
  in_ECX[0x8e] = 0xf;
  in_ECX[0x8d] = 0;
  *(undefined1 *)(in_ECX + 0x89) = 0;
  in_ECX[0x95] = 0xf;
  in_ECX[0x94] = 0;
  *(undefined1 *)(in_ECX + 0x90) = 0;
  in_ECX[0x9c] = 0xf;
  in_ECX[0x9b] = 0;
  *(undefined1 *)(in_ECX + 0x97) = 0;
  in_ECX[0xa3] = 0xf;
  in_ECX[0xa2] = 0;
  *(undefined1 *)(in_ECX + 0x9e) = 0;
  in_ECX[0xaa] = 0xf;
  in_ECX[0xa9] = 0;
  *(undefined1 *)(in_ECX + 0xa5) = 0;
  return;
}


// ==== FUN_00408720 @ 0x00408720 ====

void FUN_00408720(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_009781d8;
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
LAB_00408819:
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
      if ((char)piVar6[5] == '\0') goto LAB_00408819;
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


// ==== FUN_00408900 @ 0x00408900 ====

/* WARNING: Removing unreachable block (ram,0x00408a13) */
/* WARNING: Removing unreachable block (ram,0x00408a23) */
/* WARNING: Removing unreachable block (ram,0x00408a2c) */
/* WARNING: Removing unreachable block (ram,0x00408a2f) */
/* WARNING: Removing unreachable block (ram,0x00408a1f) */
/* WARNING: Removing unreachable block (ram,0x00408a3d) */
/* WARNING: Removing unreachable block (ram,0x00408a4a) */
/* WARNING: Removing unreachable block (ram,0x00408a55) */
/* WARNING: Removing unreachable block (ram,0x00408a51) */
/* WARNING: Removing unreachable block (ram,0x00408a45) */
/* WARNING: Removing unreachable block (ram,0x00408a58) */

void FUN_00408900(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_009781d8;
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
            goto LAB_00408b25;
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
LAB_00408b25:
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


// ==== FUN_00408bb0 @ 0x00408bb0 ====

void FUN_00408bb0(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_00408720(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00408720(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00408c70 @ 0x00408c70 ====

void FUN_00408c70(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00408110(piVar6[1]);
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
    FUN_00408900(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00408d30 @ 0x00408d30 ====

undefined4 FUN_00408d30(undefined4 param_1)

{
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_00408150(&local_8,param_1);
  param_1 = 0;
  FUN_00521510(local_8,local_4,&param_1,0);
  FUN_00408c70(&local_8,local_8,local_4);
  return param_1;
}


// ==== FUN_00408d90 @ 0x00408d90 ====

void FUN_00408d90(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00408c70(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00408dc0 @ 0x00408dc0 ====

int FUN_00408dc0(void)

{
  int in_ECX;
  
  return in_ECX + 0x20;
}


// ==== FUN_00408dd0 @ 0x00408dd0 ====

void FUN_00408dd0(byte param_1)

{
  void *in_ECX;
  
  FUN_00406fc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00408df0 @ 0x00408df0 ====

void FUN_00408df0(void)

{
  return;
}


// ==== FUN_00408e00 @ 0x00408e00 ====

void FUN_00408e00(void)

{
  return;
}


// ==== FUN_00408e10 @ 0x00408e10 ====

void FUN_00408e10(void)

{
  return;
}


// ==== FUN_00408e20 @ 0x00408e20 ====

void FUN_00408e20(void)

{
  return;
}


// ==== FUN_00408e30 @ 0x00408e30 ====

void FUN_00408e30(void)

{
  return;
}


// ==== FUN_00408e40 @ 0x00408e40 ====

void FUN_00408e40(void)

{
  return;
}


// ==== FUN_00408e50 @ 0x00408e50 ====

void FUN_00408e50(void)

{
  return;
}


// ==== FUN_00408e60 @ 0x00408e60 ====

void FUN_00408e60(void)

{
  return;
}


// ==== __break @ 0x00408ed6 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00408f60 @ 0x00408f60 ====

void FUN_00408f60(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097822e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099cdd0;
  local_4 = 2;
  if (in_ECX[0xc] == 0) {
    in_ECX[0xc] = 0;
    in_ECX[0xd] = 0;
    in_ECX[0xe] = 0;
    FUN_004094e0(local_10,*(undefined4 *)in_ECX[9],(undefined4 *)in_ECX[9]);
    _free((void *)in_ECX[9]);
    return;
  }
  FUN_00405de0(in_ECX[0xc],in_ECX[0xd],in_ECX + 0xb);
  _free((void *)in_ECX[0xc]);
  return;
}


// ==== FUN_00409050 @ 0x00409050 ====

void FUN_00409050(void)

{
  int in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097824b;
  pvStack_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  FUN_004094e0(local_10,**(undefined4 **)(in_ECX + 0x5c),*(undefined4 **)(in_ECX + 0x5c));
  _free(*(void **)(in_ECX + 0x5c));
  return;
}


// ==== FUN_00409100 @ 0x00409100 ====

void FUN_00409100(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097827e;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099cdd0;
  iVar1 = FUN_004a37b0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  local_4 = CONCAT31(local_4._1_3_,2);
  iVar1 = FUN_004a37b0();
  in_ECX[9] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[9] + 4) = in_ECX[9];
  *(undefined4 *)in_ECX[9] = in_ECX[9];
  *(undefined4 *)(in_ECX[9] + 8) = in_ECX[9];
  in_ECX[10] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004091a0 @ 0x004091a0 ====

void FUN_004091a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099cdb0;
  return;
}


// ==== FUN_004091b0 @ 0x004091b0 ====

void FUN_004091b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099cdb0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004091d0 @ 0x004091d0 ====

/* WARNING: Removing unreachable block (ram,0x004092e0) */
/* WARNING: Removing unreachable block (ram,0x004092f1) */
/* WARNING: Removing unreachable block (ram,0x004092fa) */
/* WARNING: Removing unreachable block (ram,0x004092fd) */
/* WARNING: Removing unreachable block (ram,0x004092ed) */
/* WARNING: Removing unreachable block (ram,0x0040930b) */
/* WARNING: Removing unreachable block (ram,0x00409318) */
/* WARNING: Removing unreachable block (ram,0x00409323) */
/* WARNING: Removing unreachable block (ram,0x0040931f) */
/* WARNING: Removing unreachable block (ram,0x00409313) */
/* WARNING: Removing unreachable block (ram,0x00409326) */

void FUN_004091d0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_009781f8;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x2d) != '\0') {
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
  FUN_00699bf0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x2d) == '\0') {
    if (*(char *)(param_2[2] + 0x2d) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x2d) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x2d) == '\0') {
      piVar3 = (int *)FUN_0079c400(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x2d) == '\0') {
      uVar4 = FUN_00578a40(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0xb] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0xb] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0xb] == '\0') {
            *(undefined1 *)(piVar5 + 0xb) = 1;
            *(undefined1 *)(piVar3 + 0xb) = 0;
            FUN_004eb7a0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x2d) == '\0') {
            if ((*(char *)(*piVar5 + 0x2c) == '\x01') && (*(char *)(piVar5[2] + 0x2c) == '\x01'))
            goto LAB_004093f7;
            if (*(char *)(piVar5[2] + 0x2c) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x2c) = 1;
              *(undefined1 *)(piVar5 + 0xb) = 0;
              FUN_005a3430(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0xb) = (char)piVar3[0xb];
            *(undefined1 *)(piVar3 + 0xb) = 1;
            *(undefined1 *)(piVar5[2] + 0x2c) = 1;
            FUN_004eb7a0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0xb] == '\0') {
            *(undefined1 *)(piVar5 + 0xb) = 1;
            *(undefined1 *)(piVar3 + 0xb) = 0;
            FUN_005a3430(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x2d) == '\0') {
            if ((*(char *)(piVar5[2] + 0x2c) != '\x01') || (*(char *)(*piVar5 + 0x2c) != '\x01')) {
              if (*(char *)(*piVar5 + 0x2c) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x2c) = 1;
                *(undefined1 *)(piVar5 + 0xb) = 0;
                FUN_004eb7a0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0xb) = (char)piVar3[0xb];
              *(undefined1 *)(piVar3 + 0xb) = 1;
              *(undefined1 *)(*piVar5 + 0x2c) = 1;
              FUN_005a3430(piVar3);
              break;
            }
LAB_004093f7:
            *(undefined1 *)(piVar5 + 0xb) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xb) = 1;
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


// ==== FUN_004094a0 @ 0x004094a0 ====

void FUN_004094a0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) == '\0') {
    FUN_004094a0(*(undefined4 *)((int)param_1 + 8));
    FUN_00446f40();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004094e0 @ 0x004094e0 ====

void FUN_004094e0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004094a0(piVar6[1]);
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
    FUN_004091d0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004095a0 @ 0x004095a0 ====

void FUN_004095a0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004094e0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004095d0 @ 0x004095d0 ====

void FUN_004095d0(byte param_1)

{
  void *in_ECX;
  
  FUN_00408f60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004095f0 @ 0x004095f0 ====

void FUN_004095f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ce54;
  return;
}


// ==== FUN_00409600 @ 0x00409600 ====

void FUN_00409600(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ce54;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00409620 @ 0x00409620 ====

void FUN_00409620(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_00409620(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00409660 @ 0x00409660 ====

undefined1 FUN_00409660(int *param_1,int *param_2,undefined1 param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  while (param_1 != param_2) {
    if ((undefined4 *)param_1[4] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[4])(1);
    }
    if (*(char *)((int)param_1 + 0x15) == '\0') {
      piVar2 = (int *)param_1[2];
      if (*(char *)((int)piVar2 + 0x15) == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x15);
        param_1 = piVar2;
        piVar2 = (int *)*piVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          param_1 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(param_1[1] + 0x15);
        piVar3 = (int *)param_1[1];
        piVar2 = param_1;
        while ((param_1 = piVar3, cVar1 == '\0' && (piVar2 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x15);
          piVar3 = (int *)param_1[1];
          piVar2 = param_1;
        }
      }
    }
  }
  return param_3;
}


// ==== FUN_004096d0 @ 0x004096d0 ====

void FUN_004096d0(void)

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
    FUN_00411970();
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


// ==== FUN_00409730 @ 0x00409730 ====

void FUN_00409730(undefined1 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
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
  puStack_8 = &LAB_00978298;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004d8980(&local_2c,&param_1);
  if (local_2c != *(int *)(in_ECX + 8)) {
    FUN_004116a0(param_2,param_3);
    ExceptionList = local_c;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_find_it____m_mapIDStorage_end___0099cdf0,0x1f);
  local_4 = 0;
  FUN_00406880(local_28);
  local_4 = 0xffffffff;
  if (local_10 < 0x10) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_004097f0 @ 0x004097f0 ====

void FUN_004097f0(undefined1 param_1,undefined4 param_2)

{
  code *pcVar1;
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
  puStack_8 = &LAB_009782aa;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004d8980(&local_2c,&param_1);
  if (local_2c != *(int *)(in_ECX + 8)) {
    FUN_00411870(param_2);
    ExceptionList = local_c;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_find_it____m_mapIDStorage_end___0099ce10,0x1f);
  local_4 = 0;
  FUN_00406880(local_28);
  local_4 = 0xffffffff;
  if (local_10 < 0x10) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_004098b0 @ 0x004098b0 ====

void FUN_004098b0(undefined4 param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4)

{
  code *pcVar1;
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
  puStack_8 = &LAB_009782bc;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004d8980(&local_2c,&param_3);
  if (local_2c != *(int *)(in_ECX + 8)) {
    FUN_00411960(param_1,param_2,param_4);
    ExceptionList = local_c;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_find_it____m_mapIDStorage_end___0099ce30,0x1f);
  local_4 = 0;
  FUN_00406880(local_28);
  local_4 = 0xffffffff;
  if (local_10 < 0x10) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_00409980 @ 0x00409980 ====

void FUN_00409980(void)

{
  void *local_1c;
  undefined4 local_18;
  undefined1 local_14 [8];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009782e7;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_1c = operator_new(0x44);
  local_4 = 0;
  if (local_1c == (void *)0x0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_00411c00(0x2a,0x1fffff);
  }
  local_4 = 0xffffffff;
  local_1c = (void *)0x0;
  FUN_0040a070(local_14,&local_1c);
  local_1c = operator_new(0x44);
  local_4 = 1;
  if (local_1c == (void *)0x0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_00411c00(0x200000,0x3fffff);
  }
  local_4 = 0xffffffff;
  local_1c = (void *)0x1;
  FUN_0040a070(local_14,&local_1c);
  local_1c = operator_new(0x44);
  local_4 = 2;
  if (local_1c == (void *)0x0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_00411c00(0x400000,0x5fffff);
  }
  local_4 = 0xffffffff;
  local_1c = (void *)0x2;
  FUN_0040a070(local_14,&local_1c);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00409ab0 @ 0x00409ab0 ====

void FUN_00409ab0(void)

{
  undefined4 *in_ECX;
  uint local_14 [2];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00978304;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099ce6c;
  local_4 = 1;
  if (in_ECX[3] != 0) {
    local_14[0] = local_14[0] & 0xffffff00;
    FUN_00409660(*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2],local_14[0]);
    FUN_00409620(*(undefined4 *)(in_ECX[2] + 4));
    *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
    in_ECX[3] = 0;
    *(undefined4 *)in_ECX[2] = in_ECX[2];
    *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  }
  local_4 = local_4 & 0xffffff00;
  FUN_0040a130(local_14,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00409b70 @ 0x00409b70 ====

void FUN_00409b70(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978316;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099ce6c;
  iVar1 = FUN_0058d7c0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00409be0 @ 0x00409be0 ====

void FUN_00409be0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00978328;
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
LAB_00409cd9:
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
      if ((char)piVar6[5] == '\0') goto LAB_00409cd9;
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


// ==== FUN_00409dc0 @ 0x00409dc0 ====

/* WARNING: Removing unreachable block (ram,0x00409ed3) */
/* WARNING: Removing unreachable block (ram,0x00409ee3) */
/* WARNING: Removing unreachable block (ram,0x00409eec) */
/* WARNING: Removing unreachable block (ram,0x00409eef) */
/* WARNING: Removing unreachable block (ram,0x00409edf) */
/* WARNING: Removing unreachable block (ram,0x00409efd) */
/* WARNING: Removing unreachable block (ram,0x00409f0a) */
/* WARNING: Removing unreachable block (ram,0x00409f15) */
/* WARNING: Removing unreachable block (ram,0x00409f11) */
/* WARNING: Removing unreachable block (ram,0x00409f05) */
/* WARNING: Removing unreachable block (ram,0x00409f18) */

void FUN_00409dc0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00978328;
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
            goto LAB_00409fe5;
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
LAB_00409fe5:
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


// ==== FUN_0040a070 @ 0x0040a070 ====

void FUN_0040a070(undefined4 *param_1,int *param_2)

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
  if (*(char *)((int)puVar5[1] + 0x15) == '\0') {
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
    } while (*(char *)((int)puVar4 + 0x15) == '\0');
  }
  param_2 = puVar5;
  if (bVar2) {
    if (puVar5 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar5 = (undefined4 *)FUN_00409be0(&param_2,1,puVar5,piVar3);
      uVar1 = *puVar5;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *piVar3) {
    puVar5 = (undefined4 *)FUN_00409be0(&param_2,bVar2,puVar5,piVar3);
    *param_1 = *puVar5;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0040a130 @ 0x0040a130 ====

void FUN_0040a130(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00409620(piVar6[1]);
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
    FUN_00409dc0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0040a1f0 @ 0x0040a1f0 ====

void FUN_0040a1f0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_0040a130(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0040a220 @ 0x0040a220 ====

void FUN_0040a220(byte param_1)

{
  void *in_ECX;
  
  FUN_00409ab0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0040a240 @ 0x0040a240 ====

int FUN_0040a240(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0040a250 @ 0x0040a250 ====

void FUN_0040a250(void)

{
  int in_ECX;
  
  FUN_0040ad30(*(undefined4 *)(*(int *)(in_ECX + 8) + 4));
  *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 8);
  *(int *)(*(int *)(in_ECX + 8) + 8) = *(int *)(in_ECX + 8);
  return;
}


// ==== FUN_0040a280 @ 0x0040a280 ====

void FUN_0040a280(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_ECX;
  int local_a0 [2];
  undefined1 local_98 [4];
  undefined1 local_94;
  undefined4 local_84;
  undefined4 local_80;
  undefined1 local_78;
  undefined4 local_68;
  undefined4 local_64;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009783b3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0040a8a0(local_a0,param_1);
  if (local_a0[0] == *(int *)(in_ECX + 8)) {
    local_80 = 0xf;
    local_84 = 0;
    local_94 = 0;
    local_64 = 0xf;
    local_68 = 0;
    local_78 = 0;
    local_4 = 0;
    FUN_00401660(param_1,0,0xffffffff);
    FUN_00401660(param_2,0,0xffffffff);
    uVar1 = FUN_0040aa00(local_98,local_98);
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_0040b0b0(local_a0,uVar1);
    FUN_0040a820();
    FUN_0040a7d0();
  }
  else {
    FUN_00401660(param_2,0,0xffffffff);
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0040a380 @ 0x0040a380 ====

void FUN_0040a380(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009783d0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099ce98;
  local_4 = 1;
  FUN_0040ad30(*(undefined4 *)(in_ECX[2] + 4));
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  in_ECX[3] = 0;
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  local_4 = local_4 & 0xffffff00;
  FUN_0040aff0(local_10,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0040a420 @ 0x0040a420 ====

void FUN_0040a420(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009783e2;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099ce98;
  iVar1 = FUN_0040a660();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x61) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0040a490 @ 0x0040a490 ====

void FUN_0040a490(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x61) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x61) == '\0');
  }
  return;
}


// ==== FUN_0040a4b0 @ 0x0040a4b0 ====

void FUN_0040a4b0(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x61);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x61);
  }
  return;
}


// ==== FUN_0040a4d0 @ 0x0040a4d0 ====

void FUN_0040a4d0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x61) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x61) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x61);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x61);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x61);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x61);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_0040a520 @ 0x0040a520 ====

void FUN_0040a520(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ce84;
  return;
}


// ==== FUN_0040a530 @ 0x0040a530 ====

void FUN_0040a530(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ce84;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0040a550 @ 0x0040a550 ====

void FUN_0040a550(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x61) == '\0') {
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


// ==== FUN_0040a5a0 @ 0x0040a5a0 ====

void FUN_0040a5a0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x61) == '\0') {
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


// ==== FUN_0040a600 @ 0x0040a600 ====

void FUN_0040a600(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x61) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x61) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x61);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x61);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x61) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x61) == '\0');
    if (*(char *)((int)piVar4 + 0x61) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_0040a660 @ 0x0040a660 ====

void FUN_0040a660(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(100);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x18) = 1;
  *(undefined1 *)((int)puVar1 + 0x61) = 0;
  return;
}


// ==== FUN_0040a6a0 @ 0x0040a6a0 ====

bool FUN_0040a6a0(int param_1,int param_2)

{
  int iVar1;
  
  if (*(uint *)(param_2 + 0x18) < 0x10) {
    iVar1 = param_2 + 4;
  }
  else {
    iVar1 = *(int *)(param_2 + 4);
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),iVar1,*(undefined4 *)(param_2 + 0x14));
  return iVar1 < 0;
}


// ==== FUN_0040a6d0 @ 0x0040a6d0 ====

bool FUN_0040a6d0(int param_1,int param_2)

{
  int iVar1;
  
  if (*(uint *)(param_2 + 0x18) < 0x10) {
    iVar1 = param_2 + 4;
  }
  else {
    iVar1 = *(int *)(param_2 + 4);
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),iVar1,*(undefined4 *)(param_2 + 0x14));
  return iVar1 < 0;
}


// ==== FUN_0040a710 @ 0x0040a710 ====

/* WARNING: Removing unreachable block (ram,0x0040a768) */

undefined4 * FUN_0040a710(int param_1)

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
  if (*(char *)((int)local_8[1] + 0x61) == '\0') {
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
LAB_0040a793:
        if (uVar1 <= uVar2) {
          bVar9 = false;
          goto LAB_0040a7a0;
        }
LAB_0040a7a2:
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
        if (iVar4 == 0) goto LAB_0040a793;
LAB_0040a7a0:
        if (bVar9) goto LAB_0040a7a2;
        puVar6 = (undefined4 *)*puVar5;
        local_8 = puVar5;
      }
      puVar5 = puVar6;
    } while (*(char *)((int)puVar6 + 0x61) == '\0');
  }
  return local_8;
}


// ==== FUN_0040a7d0 @ 0x0040a7d0 ====

void FUN_0040a7d0(void)

{
  int in_ECX;
  
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


// ==== FUN_0040a820 @ 0x0040a820 ====

void FUN_0040a820(void)

{
  int in_ECX;
  
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
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0040a890 @ 0x0040a890 ====

void FUN_0040a890(void)

{
  FUN_0040a820();
  return;
}


// ==== FUN_0040a8a0 @ 0x0040a8a0 ====

void FUN_0040a8a0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_0040a710(param_2);
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


// ==== FUN_0040a910 @ 0x0040a910 ====

void FUN_0040a910(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978348;
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


// ==== FUN_0040a990 @ 0x0040a990 ====

void FUN_0040a990(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978348;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  FUN_0040a910(param_1 + 0x1c);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0040aa00 @ 0x0040aa00 ====

void FUN_0040aa00(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978348;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  FUN_0040a910(param_2);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0040aa70 @ 0x0040aa70 ====

/* WARNING: Removing unreachable block (ram,0x0040ab83) */
/* WARNING: Removing unreachable block (ram,0x0040ab93) */
/* WARNING: Removing unreachable block (ram,0x0040ab9c) */
/* WARNING: Removing unreachable block (ram,0x0040ab9f) */
/* WARNING: Removing unreachable block (ram,0x0040ab8f) */
/* WARNING: Removing unreachable block (ram,0x0040abad) */
/* WARNING: Removing unreachable block (ram,0x0040abba) */
/* WARNING: Removing unreachable block (ram,0x0040abc5) */
/* WARNING: Removing unreachable block (ram,0x0040abc1) */
/* WARNING: Removing unreachable block (ram,0x0040abb5) */
/* WARNING: Removing unreachable block (ram,0x0040abc8) */

void FUN_0040aa70(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00978368;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x61) != '\0') {
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
  FUN_0040a4d0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x61) == '\0') {
    if (*(char *)(param_2[2] + 0x61) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x61) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x61) == '\0') {
      piVar3 = (int *)FUN_0040a4b0(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x61) == '\0') {
      uVar4 = FUN_0040a490(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0x18] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x18] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x18] == '\0') {
            *(undefined1 *)(piVar5 + 0x18) = 1;
            *(undefined1 *)(piVar3 + 0x18) = 0;
            FUN_0040a550(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x61) == '\0') {
            if ((*(char *)(*piVar5 + 0x60) == '\x01') && (*(char *)(piVar5[2] + 0x60) == '\x01'))
            goto LAB_0040ac95;
            if (*(char *)(piVar5[2] + 0x60) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x60) = 1;
              *(undefined1 *)(piVar5 + 0x18) = 0;
              FUN_0040a5a0(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0x18) = (char)piVar3[0x18];
            *(undefined1 *)(piVar3 + 0x18) = 1;
            *(undefined1 *)(piVar5[2] + 0x60) = 1;
            FUN_0040a550(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0x18] == '\0') {
            *(undefined1 *)(piVar5 + 0x18) = 1;
            *(undefined1 *)(piVar3 + 0x18) = 0;
            FUN_0040a5a0(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x61) == '\0') {
            if ((*(char *)(piVar5[2] + 0x60) != '\x01') || (*(char *)(*piVar5 + 0x60) != '\x01')) {
              if (*(char *)(*piVar5 + 0x60) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x60) = 1;
                *(undefined1 *)(piVar5 + 0x18) = 0;
                FUN_0040a550(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0x18) = (char)piVar3[0x18];
              *(undefined1 *)(piVar3 + 0x18) = 1;
              *(undefined1 *)(*piVar5 + 0x60) = 1;
              FUN_0040a5a0(piVar3);
              break;
            }
LAB_0040ac95:
            *(undefined1 *)(piVar5 + 0x18) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x18) = 1;
  }
  FUN_0040a820();
  _free(param_2);
  return;
}


// ==== FUN_0040ad30 @ 0x0040ad30 ====

void FUN_0040ad30(void *param_1)

{
  if (*(char *)((int)param_1 + 0x61) == '\0') {
    FUN_0040ad30(*(undefined4 *)((int)param_1 + 8));
    FUN_0040a890();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0040ad70 @ 0x0040ad70 ====

undefined4 *
FUN_0040ad70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00978391;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(100);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    FUN_0040a990(param_4);
    *(undefined1 *)(puVar1 + 0x18) = param_5;
    *(undefined1 *)((int)puVar1 + 0x61) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@0040adee @ 0x0040adee ====

void Catch_0040adee(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0040ae10 @ 0x0040ae10 ====

void FUN_0040ae10(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00978368;
  local_c = ExceptionList;
  if (0x30c30c1 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_0040ad70(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x60);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x60) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x18] == '\0') {
LAB_0040af09:
        *(undefined1 *)(*piVar5 + 0x60) = 1;
        *(undefined1 *)(piVar6 + 0x18) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x60) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0040a550(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x60) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x60) = 0;
        FUN_0040a5a0(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x18] == '\0') goto LAB_0040af09;
      if (piVar7 == (int *)*piVar2) {
        FUN_0040a5a0(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x60) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x60) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x61) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x60);
  } while( true );
}


// ==== FUN_0040aff0 @ 0x0040aff0 ====

void FUN_0040aff0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0040ad30(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x61) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x61) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x61);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x61);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x61);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x61);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_0040aa70(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0040b0b0 @ 0x0040b0b0 ====

/* WARNING: Removing unreachable block (ram,0x0040b10f) */

void FUN_0040b0b0(undefined4 *param_1,undefined4 *param_2)

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
  if (*(char *)((int)puVar6[1] + 0x61) == '\0') {
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
LAB_0040b140:
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
        if (uVar5 == 0) goto LAB_0040b140;
      }
      bVar11 = (int)uVar5 < 0;
      if (bVar11) {
        puVar9 = (undefined4 *)*puVar6;
      }
      else {
        puVar9 = (undefined4 *)puVar6[2];
      }
    } while (*(char *)((int)puVar9 + 0x61) == '\0');
  }
  param_2 = puVar6;
  if (bVar11) {
    if (puVar6 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar6 = (undefined4 *)FUN_0040ae10(&param_2,1,puVar6,iVar3);
      *param_1 = *puVar6;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_0040a600();
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
    puVar6 = (undefined4 *)FUN_0040ae10(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_0040b220 @ 0x0040b220 ====

void FUN_0040b220(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_0040aff0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0040b250 @ 0x0040b250 ====

void FUN_0040b250(byte param_1)

{
  void *in_ECX;
  
  FUN_0040a380();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0040b270 @ 0x0040b270 ====

undefined4 FUN_0040b270(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  LPCSTR lpCaption;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  LPCSTR ******lpText;
  undefined1 auStack_c0 [16];
  undefined4 uStack_b0;
  LPCSTR ******local_8c [4];
  int local_7c;
  undefined1 *local_78;
  undefined1 auStack_2c [32];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00978413;
  local_c = ExceptionList;
  local_78 = (undefined1 *)0xf;
  local_7c = 0;
  local_8c[0] = (LPCSTR ******)((uint)local_8c[0] & 0xffffff00);
  local_4 = 0;
  switch(param_1) {
  case 0x3e9:
  case 0x3ea:
    ExceptionList = &local_c;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 0x3f3:
  case 0x3f4:
  case 0x3f5:
  case 0x3f7:
    ExceptionList = &local_c;
    (**(code **)(*DAT_00b5a6d0 + 4))();
    FUN_00401660();
    if (local_7c != 0) {
      iVar2 = (**(code **)(*DAT_00b5a6d0 + 4))();
      if (*(uint *)(iVar2 + 0x18) < 0x10) {
        lpCaption = (LPCSTR)(iVar2 + 4);
      }
      else {
        lpCaption = *(LPCSTR *)(iVar2 + 4);
      }
      lpText = local_8c[0];
      if (local_78 < 0x10) {
        lpText = (LPCSTR ******)local_8c;
      }
      uStack_b0 = 0x40b446;
      MessageBoxA((HWND)0x0,(LPCSTR)lpText,lpCaption,0);
      if (local_78 < 0x10) {
        ExceptionList = local_c;
        return 0;
      }
      _free(local_8c[0]);
      return extraout_EAX;
    }
    if (0xf < local_78) {
      _free(local_8c[0]);
      return extraout_EAX_00;
    }
    break;
  case 0x3f6:
    ExceptionList = &local_c;
    uVar1 = (**(code **)(*DAT_00b5a6d0 + 4))();
    local_78 = auStack_c0;
    FUN_00765c50(uVar1);
    FUN_00404230(auStack_2c);
    puStack_8._0_1_ = 1;
    uStack_b0 = 0x40b327;
    FUN_00401660();
    puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 0x3f9:
    ExceptionList = &local_c;
    FUN_00401830();
    local_4._0_1_ = 2;
    FUN_00403e50();
    local_4 = (uint)local_4._1_3_ << 8;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_0040b4c0 @ 0x0040b4c0 ====

uint FUN_0040b4c0(void)

{
  uint uVar1;
  undefined4 uVar2;
  LPCSTR ****lpText;
  uint extraout_EAX;
  uint extraout_EAX_00;
  LPCSTR ****lpCaption;
  LPCSTR ****apppppCStack_48 [2];
  undefined1 local_40;
  uint uStack_34;
  undefined4 local_30;
  LPCSTR ****local_2c [4];
  undefined4 uStack_1c;
  uint uStack_18;
  void *pvStack_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978425;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar1 = FUN_008156f0();
  if (uVar1 == 0x755) {
    ExceptionList = local_c;
    return 0x701;
  }
  local_2c[0] = (LPCSTR ****)0xf;
  local_30 = 0;
  local_40 = 0;
  local_4 = 0;
  if (uVar1 < 0x7d) {
    if (uVar1 == 0x7c) {
switchD_0040b523_caseD_78:
      (**(code **)(*DAT_00b5a6d0 + 4))();
      goto LAB_0040b5c2;
    }
    switch(uVar1) {
    case 0x6e:
      (**(code **)(*DAT_00b5a6d0 + 4))();
      goto LAB_0040b5c2;
    default:
      goto switchD_0040b523_caseD_6f;
    case 0x70:
      break;
    case 0x72:
      (**(code **)(*DAT_00b5a6d0 + 4))();
      goto LAB_0040b5c2;
    case 0x73:
      break;
    case 0x78:
      goto switchD_0040b523_caseD_78;
    }
    goto LAB_0040b5b7;
  }
  switch(uVar1) {
  case 0x96:
  case 0x99:
    goto switchD_0040b523_caseD_78;
  default:
switchD_0040b523_caseD_6f:
    break;
  case 0x9b:
    break;
  case 0xaa:
    (**(code **)(*DAT_00b5a6d0 + 4))();
    goto LAB_0040b5c2;
  case 200:
    break;
  case 0x154:
  case 0x17c:
    break;
  case 0x15e:
    (**(code **)(*DAT_00b5a6d0 + 4))();
    goto LAB_0040b5c2;
  case 0x168:
    (**(code **)(*DAT_00b5a6d0 + 4))();
    goto LAB_0040b5c2;
  }
LAB_0040b5b7:
  (**(code **)(*DAT_00b5a6d0 + 4))();
LAB_0040b5c2:
  FUN_00401660();
  uVar2 = (**(code **)(*DAT_00b5a6d0 + 4))();
  FUN_00401660(uVar2,0,0xffffffff);
  FUN_00404230(&local_30);
  lpCaption = local_2c[0];
  if (uStack_18 < 0x10) {
    lpCaption = (LPCSTR ****)local_2c;
  }
  lpText = apppppCStack_48[0];
  if (uStack_34 < 0x10) {
    lpText = (LPCSTR ****)apppppCStack_48;
  }
  uVar1 = MessageBoxA((HWND)0x0,(LPCSTR)lpText,(LPCSTR)lpCaption,0);
  if (0xf < uStack_18) {
    _free(local_2c[0]);
    return extraout_EAX;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  local_2c[0] = (LPCSTR ****)((uint)local_2c[0] & 0xffffff00);
  if (uStack_34 < 0x10) {
    ExceptionList = pvStack_14;
    return uVar1 & 0xffffff00;
  }
  _free(apppppCStack_48[0]);
  return extraout_EAX_00;
}


// ==== FUN_0040b7c0 @ 0x0040b7c0 ====

void FUN_0040b7c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099cf20;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0040b810 @ 0x0040b810 ====

void FUN_0040b810(void)

{
                    /* WARNING: Could not recover jumptable at 0x0040b818. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a7d8 + 8))();
  return;
}


// ==== FUN_0040b820 @ 0x0040b820 ====

void FUN_0040b820(void)

{
  undefined4 *puVar1;
  
  if (DAT_00b5a6c8 == (undefined4 *)0x0) {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_0099cf54;
      if (puVar1 != (undefined4 *)0xfffffffc) {
        DAT_00b5a6c8 = puVar1;
        return;
      }
      DAT_00b5a6c8 = (undefined4 *)0x0;
    }
  }
  return;
}


// ==== FUN_0040b860 @ 0x0040b860 ====

void FUN_0040b860(void)

{
  if (DAT_00b5a6c8 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a6c8)(1);
  }
  return;
}


// ==== FUN_0040b880 @ 0x0040b880 ====

void FUN_0040b880(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5a6c8 = 0;
  *in_ECX = &PTR_FUN_0099cf20;
  return;
}


// ==== FUN_0040b8a0 @ 0x0040b8a0 ====

void FUN_0040b8a0(undefined4 param_1,undefined4 param_2)

{
  void *local_48 [5];
  uint uStack_34;
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978458;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0040bf70(param_1,param_2);
  local_4 = 0;
  (**(code **)(*DAT_00b5a7d8 + 4))(local_48);
  if (0xf < uStack_14) {
    _free(pvStack_28);
    return;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  if (uStack_34 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(local_48[0]);
  return;
}


// ==== FUN_0040b930 @ 0x0040b930 ====

void FUN_0040b930(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *local_48 [5];
  uint uStack_34;
  void *local_28;
  undefined4 uStack_18;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097846a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0040bf70(param_1,param_2);
  local_4 = 0;
  FUN_00401660(param_3,0,0xffffffff);
  (**(code **)(*DAT_00b5a7d8 + 4))(local_48);
  if (0xf < uStack_14) {
    _free(local_28);
    return;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  if (uStack_34 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(local_48[0]);
  return;
}


// ==== FUN_0040b9e0 @ 0x0040b9e0 ====

void FUN_0040b9e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *local_48 [5];
  uint uStack_34;
  void *local_28;
  undefined4 uStack_18;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097847c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0040bff0(param_1,param_2,param_3);
  local_4 = 0;
  FUN_00401660(param_4,0,0xffffffff);
  (**(code **)(*DAT_00b5a7d8 + 4))(local_48);
  if (0xf < uStack_14) {
    _free(local_28);
    return;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  if (uStack_34 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(local_48[0]);
  return;
}


// ==== FUN_0040ba90 @ 0x0040ba90 ====

void FUN_0040ba90(undefined1 param_1,void *param_2)

{
  undefined4 *puVar1;
  void **ppvVar2;
  undefined4 *puVar3;
  int in_stack_00000018;
  uint in_stack_0000001c;
  undefined1 local_1c [4];
  undefined4 *local_18;
  undefined4 *local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978496;
  local_c = ExceptionList;
  local_4 = 0;
  ppvVar2 = &local_c;
  if (in_stack_00000018 != 0) {
    local_18 = (undefined4 *)0x0;
    local_14 = (undefined4 *)0x0;
    local_10 = 0;
    local_4 = 1;
    ExceptionList = &local_c;
    (**(code **)(*DAT_00b5a7d8 + 0x10))(&param_1,local_1c);
    puVar1 = local_14;
    for (puVar3 = local_18; puVar3 != puVar1; puVar3 = puVar3 + 1) {
      FUN_00406720(*puVar3);
    }
    if (local_18 != (undefined4 *)0x0) {
      _free(local_18);
      return;
    }
    local_18 = (undefined4 *)0x0;
    local_14 = (undefined4 *)0x0;
    local_10 = 0;
    ppvVar2 = ExceptionList;
  }
  ExceptionList = ppvVar2;
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_0040bb60 @ 0x0040bb60 ====

/* WARNING: Removing unreachable block (ram,0x0040bc0e) */
/* WARNING: Removing unreachable block (ram,0x0040bea0) */
/* WARNING: Removing unreachable block (ram,0x0040bd17) */
/* WARNING: Removing unreachable block (ram,0x0040bc0c) */
/* WARNING: Removing unreachable block (ram,0x0040bd07) */
/* WARNING: Removing unreachable block (ram,0x0040bd13) */
/* WARNING: Removing unreachable block (ram,0x0040bd2e) */
/* WARNING: Removing unreachable block (ram,0x0040bd3a) */
/* WARNING: Removing unreachable block (ram,0x0040bd3e) */
/* WARNING: Removing unreachable block (ram,0x0040bdc3) */
/* WARNING: Removing unreachable block (ram,0x0040bdff) */
/* WARNING: Removing unreachable block (ram,0x0040be0c) */
/* WARNING: Removing unreachable block (ram,0x0040be5d) */
/* WARNING: Removing unreachable block (ram,0x0040be6a) */
/* WARNING: Removing unreachable block (ram,0x0040be84) */
/* WARNING: Removing unreachable block (ram,0x0040bc79) */
/* WARNING: Removing unreachable block (ram,0x0040bcb6) */
/* WARNING: Removing unreachable block (ram,0x0040bcc3) */
/* WARNING: Removing unreachable block (ram,0x0040be91) */
/* WARNING: Removing unreachable block (ram,0x0040bead) */
/* WARNING: Removing unreachable block (ram,0x0040bcfe) */
/* WARNING: Removing unreachable block (ram,0x0040be88) */
/* WARNING: Removing unreachable block (ram,0x0040bbb6) */
/* WARNING: Removing unreachable block (ram,0x0040bbd5) */
/* WARNING: Removing unreachable block (ram,0x0040bd42) */
/* WARNING: Removing unreachable block (ram,0x0040bd57) */
/* WARNING: Removing unreachable block (ram,0x0040bd5f) */
/* WARNING: Removing unreachable block (ram,0x0040bd7a) */
/* WARNING: Removing unreachable block (ram,0x0040bd95) */

undefined4 FUN_0040bb60(undefined4 param_1,void *param_2)

{
  undefined4 extraout_EAX;
  uint in_stack_0000001c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009784fa;
  pvStack_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  FUN_00405670();
  if (in_stack_0000001c < 0x10) {
    ExceptionList = pvStack_c;
    return 0;
  }
  _free(param_2);
  return extraout_EAX;
}


// ==== FUN_0040bf00 @ 0x0040bf00 ====

void FUN_0040bf00(byte param_1)

{
  void *in_ECX;
  
  FUN_0040b880();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0040bf20 @ 0x0040bf20 ====

void FUN_0040bf20(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x38)) {
    _free(*(void **)(in_ECX + 0x24));
    return;
  }
  *(undefined4 *)(in_ECX + 0x38) = 0xf;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0040bf70 @ 0x0040bf70 ====

void FUN_0040bf70(undefined4 param_1,undefined1 param_2)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978438;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0x1c) = param_2;
  *(undefined1 *)(in_ECX + 0x1d) = param_2;
  *(undefined4 *)(in_ECX + 0x38) = 0xf;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  FUN_00401740(&DAT_0099cf70,0);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0040bff0 @ 0x0040bff0 ====

void FUN_0040bff0(undefined4 param_1,undefined1 param_2,undefined1 param_3)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978438;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0x1c) = param_2;
  *(undefined1 *)(in_ECX + 0x1d) = param_3;
  *(undefined4 *)(in_ECX + 0x38) = 0xf;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  FUN_00401740(&DAT_0099cf70,0);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0040c070 @ 0x0040c070 ====

void FUN_0040c070(void)

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
  puStack_8 = &LAB_00978518;
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


// ==== FUN_0040c0e0 @ 0x0040c0e0 ====

int FUN_0040c0e0(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    FUN_00401660(param_1,0,0xffffffff);
    param_1 = param_1 + 0x1c;
    param_3 = param_3 + 0x1c;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_0040c120 @ 0x0040c120 ====

int FUN_0040c120(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00978541;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x1c) {
    local_8 = 1;
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x18) = 0xf;
      *(undefined4 *)(param_3 + 0x14) = 0;
      *(undefined1 *)(param_3 + 4) = 0;
      FUN_00401660(param_1,0,0xffffffff);
    }
    param_3 = param_3 + 0x1c;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0040c186 @ 0x0040c186 ====

void Catch_0040c186(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x1c) {
    FUN_00405c70(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0040c1c0 @ 0x0040c1c0 ====

void FUN_0040c1c0(int param_1,int param_2,int param_3)

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
  puStack_c = &LAB_00978550;
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
      FUN_00405d70();
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
      uVar5 = FUN_00405e90(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00405e90(param_2,param_3,uVar5);
      FUN_00405e90(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
      iVar3 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x1c;
      }
      if (*(int *)(in_ECX + 4) == 0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar6 * 0x1c + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (uVar1 + iVar3) * 0x1c);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      FUN_00405de0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)((iVar3 - param_1) / 0x1c) < uVar1) {
      FUN_00405e90(param_1,iVar3,uVar1 * 0x1c + param_1);
      iVar3 = param_2 + ((*(int *)(in_ECX + 8) - param_1) / 0x1c) * 0x1c;
      local_8 = 2;
      FUN_00405e90(iVar3,param_3,*(int *)(in_ECX + 8));
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar1 * 0x1c;
      local_8 = 0xffffffff;
      FUN_0040c0e0(param_2,iVar3,param_1,param_1);
      ExceptionList = local_10;
      return;
    }
    iVar2 = iVar3 + uVar1 * -0x1c;
    uVar5 = FUN_00405e90(iVar2,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_00405e50(param_1,iVar2,iVar3,param_1);
    FUN_0040c0e0(param_2,param_3,param_1,param_1);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0040c3b3 @ 0x0040c3b3 ====

void Catch_0040c3b3(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_00406080(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@0040c497 @ 0x0040c497 ====

void Catch_0040c497(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x14) * 0x1c;
  FUN_00406080(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x1c) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0040c520 @ 0x0040c520 ====

void FUN_0040c520(int param_1,int param_2,int param_3)

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
  puStack_c = &LAB_00978560;
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
      FUN_00405d70();
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
      uVar5 = FUN_00405e90(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_0040c120(param_2,param_3,uVar5);
      FUN_00405e90(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
      iVar3 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x1c;
      }
      if (*(int *)(in_ECX + 4) == 0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar6 * 0x1c + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (uVar1 + iVar3) * 0x1c);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      FUN_00405de0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)((iVar3 - param_1) / 0x1c) < uVar1) {
      FUN_00405e90(param_1,iVar3,uVar1 * 0x1c + param_1);
      iVar3 = param_2 + ((*(int *)(in_ECX + 8) - param_1) / 0x1c) * 0x1c;
      local_8 = 2;
      FUN_0040c120(iVar3,param_3,*(int *)(in_ECX + 8));
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar1 * 0x1c;
      local_8 = 0xffffffff;
      FUN_0040c0e0(param_2,iVar3,param_1,param_1);
      ExceptionList = local_10;
      return;
    }
    iVar2 = iVar3 + uVar1 * -0x1c;
    uVar5 = FUN_00405e90(iVar2,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_00405e50(param_1,iVar2,iVar3,param_1);
    FUN_0040c0e0(param_2,param_3,param_1,param_1);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0040c713 @ 0x0040c713 ====

void Catch_0040c713(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_00406080(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@0040c7f7 @ 0x0040c7f7 ====

void Catch_0040c7f7(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x14) * 0x1c;
  FUN_00406080(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x1c) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0040c880 @ 0x0040c880 ====

void FUN_0040c880(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8);
  if (*(int *)(in_ECX + 4) != iVar1) {
    uVar2 = FUN_0040c0e0(iVar1,iVar1,*(int *)(in_ECX + 4),param_2);
    FUN_00405de0(uVar2,*(undefined4 *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  FUN_0040c1c0(*(undefined4 *)(in_ECX + 4),param_1,param_2,param_2);
  return;
}


// ==== FUN_0040c8e0 @ 0x0040c8e0 ====

void FUN_0040c8e0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8);
  if (*(int *)(in_ECX + 4) != iVar1) {
    uVar2 = FUN_0040c0e0(iVar1,iVar1,*(int *)(in_ECX + 4),param_2);
    FUN_00405de0(uVar2,*(undefined4 *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  FUN_0040c520(*(undefined4 *)(in_ECX + 4),param_1,param_2,param_2);
  return;
}


// ==== FUN_0040c940 @ 0x0040c940 ====

void FUN_0040c940(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00978599;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099cf78;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0x13] = 0xf;
  in_ECX[0x12] = 0;
  local_4._0_1_ = 2;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  FUN_00401660(param_3,0,0xffffffff);
  in_ECX[1] = 0xffffffff;
  local_4 = CONCAT31(local_4._1_3_,3);
  FUN_0040c880(*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8));
  ExceptionList = local_c;
  return;
}


// ==== FUN_0040c9f0 @ 0x0040c9f0 ====

undefined4 FUN_0040c9f0(void)

{
  return 0x70004;
}


// ==== FUN_0040ca00 @ 0x0040ca00 ====

void FUN_0040ca00(byte param_1)

{
  FUN_0040ca30();
  if ((param_1 & 1) != 0) {
    (**(code **)(*DAT_00b5a6a8 + 8))();
  }
  return;
}


// ==== FUN_0040ca30 @ 0x0040ca30 ====

void FUN_0040ca30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099cf78;
  if (0xf < (uint)in_ECX[0x13]) {
    _free((void *)in_ECX[0xe]);
    return;
  }
  in_ECX[0x13] = 0xf;
  in_ECX[0x12] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  if (in_ECX[10] != 0) {
    FUN_00405de0(in_ECX[10],in_ECX[0xb],in_ECX + 9);
    _free((void *)in_ECX[10]);
    return;
  }
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[7] = 0;
    in_ECX[8] = 0xf;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_0099cf40;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_0040cac0 @ 0x0040cac0 ====

void FUN_0040cac0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099cf8c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0040caf0 @ 0x0040caf0 ====

void FUN_0040caf0(void)

{
  return;
}


// ==== FUN_0040cb00 @ 0x0040cb00 ====

void FUN_0040cb00(void)

{
  if (DAT_00b5a6c0 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a6c0)(1);
  }
  return;
}


// ==== FUN_0040cb60 @ 0x0040cb60 ====

void FUN_0040cb60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099cf98;
  DAT_00b5a6c0 = 0;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[7] = 0xf;
    in_ECX[6] = 0;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_0099cf8c;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0040cba0 @ 0x0040cba0 ====

void FUN_0040cba0(void)

{
  undefined4 *puVar1;
  
  if (DAT_00b5a6c0 == (undefined4 *)0x0) {
    puVar1 = operator_new(0x24);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_0099cf98;
      puVar1[7] = 0xf;
      puVar1[6] = 0;
      *(undefined1 *)(puVar1 + 2) = 0;
      puVar1[8] = 0xffffffff;
      if (puVar1 != (undefined4 *)0xfffffffc) {
        DAT_00b5a6c0 = puVar1;
        return;
      }
      DAT_00b5a6c0 = (undefined4 *)0x0;
    }
  }
  return;
}


// ==== FUN_0040cc00 @ 0x0040cc00 ====

void FUN_0040cc00(byte param_1)

{
  void *in_ECX;
  
  FUN_0040cb60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0040cc30 @ 0x0040cc30 ====

void FUN_0040cc30(void)

{
  char cVar1;
  void *pvVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009785d1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (DAT_00b5a740 == 0) {
    ExceptionList = &local_c;
    cVar1 = FUN_007979d0();
    if (cVar1 == '\0') {
      pvVar2 = operator_new(0xc);
      local_4 = 1;
      if (pvVar2 != (void *)0x0) {
        FUN_00414f90(pvVar2);
      }
    }
    else {
      pvVar2 = operator_new(0x1c);
      local_4 = 0;
      if (pvVar2 != (void *)0x0) {
        FUN_004159e0(pvVar2);
      }
    }
  }
  local_4 = 0xffffffff;
  if (DAT_00b5a744 == 0) {
    pvVar2 = operator_new(4);
    local_4 = 2;
    if (pvVar2 != (void *)0x0) {
      FUN_00412920(pvVar2);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0040cce0 @ 0x0040cce0 ====

void FUN_0040cce0(void)

{
  if (DAT_00b5a744 != (void *)0x0) {
    _free(DAT_00b5a744);
    return;
  }
  if (DAT_00b5a740 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a740)(1);
  }
  return;
}


// ==== FUN_0040cd10 @ 0x0040cd10 ====

void FUN_0040cd10(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009785eb;
  local_c = ExceptionList;
  if (DAT_00b5a6cc == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x10);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_00416170(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0040cd60 @ 0x0040cd60 ====

void FUN_0040cd60(void)

{
  if (DAT_00b5a6cc != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a6cc)(1);
  }
  return;
}


// ==== FUN_0040cd80 @ 0x0040cd80 ====

void FUN_0040cd80(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097860b;
  local_c = ExceptionList;
  if (DAT_00b5a6d0 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_00416e00(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0040cdd0 @ 0x0040cdd0 ====

void FUN_0040cdd0(void)

{
  if (DAT_00b5a6d0 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a6d0)(1);
  }
  return;
}


// ==== FUN_0040cdf0 @ 0x0040cdf0 ====

void FUN_0040cdf0(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097862b;
  local_c = ExceptionList;
  if (DAT_00b5a6d4 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x4c);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_00416f70(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0040ce40 @ 0x0040ce40 ====

void FUN_0040ce40(void)

{
  if (DAT_00b5a6d4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a6d4)(1);
  }
  return;
}


// ==== FUN_0040ce60 @ 0x0040ce60 ====

void FUN_0040ce60(void)

{
  if (DAT_00b5a6e4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a6e4)(1);
  }
  return;
}


// ==== FUN_0040ce80 @ 0x0040ce80 ====

void FUN_0040ce80(void)

{
  void *pvVar1;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00978664;
  local_c = ExceptionList;
  if (DAT_00b5a6e4 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xcc);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
      FUN_00401740(s_option_txt_0099cfe4,10);
      local_4 = CONCAT31(local_4._1_3_,1);
      FUN_00419f10(local_28);
      if (0xf < local_10) {
        _free(local_24);
        return;
      }
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0040cf30 @ 0x0040cf30 ====

void FUN_0040cf30(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097867b;
  local_c = ExceptionList;
  if (DAT_00b5a6dc == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x22ec);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_0041dc30(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0040cf90 @ 0x0040cf90 ====

void FUN_0040cf90(void)

{
  if (DAT_00b5a6dc != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a6dc)(1);
  }
  return;
}


// ==== FUN_0040cfb0 @ 0x0040cfb0 ====

void FUN_0040cfb0(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097869b;
  local_c = ExceptionList;
  if (DAT_00b5a6d8 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x21c);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_004225d0(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0040d010 @ 0x0040d010 ====

void FUN_0040d010(void)

{
  if (DAT_00b5a6d8 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a6d8)(1);
  }
  return;
}


// ==== FUN_0040d030 @ 0x0040d030 ====

void FUN_0040d030(undefined4 param_1,undefined4 param_2,int param_3,code *param_4)

{
  if (-1 < param_3 + -1) {
    do {
      (*param_4)();
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}


// ==== FUN_0040d0a0 @ 0x0040d0a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0040d0a0(float param_1,float param_2)

{
  int iVar1;
  
  iVar1 = _rand();
  return ((float10)param_2 - (float10)param_1) * (float10)iVar1 * (float10)_DAT_0099d07c +
         (float10)param_1;
}


// ==== FUN_0040d0f0 @ 0x0040d0f0 ====

float10 FUN_0040d0f0(float param_1)

{
  param_1 = param_1 - (float)(int)(param_1 / DAT_00adb4a4) * DAT_00adb4a4;
  if (param_1 < 0.0) {
    return (float10)DAT_00adb4a4 + (float10)param_1;
  }
  return (float10)param_1;
}


// ==== FUN_0040d140 @ 0x0040d140 ====

float10 FUN_0040d140(float param_1,float param_2,float param_3)

{
  return ((float10)param_2 - (float10)param_1) * (float10)param_3 + (float10)param_1;
}


// ==== FUN_0040d160 @ 0x0040d160 ====

uint FUN_0040d160(float *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  float *pfVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float local_20 [8];
  
  local_20[0] = *param_1;
  local_20[1] = param_1[1];
  local_20[2] = (float)*param_2;
  local_20[3] = (float)param_2[1];
  local_20[6] = (float)*param_4;
  local_20[7] = (float)param_4[1];
  local_20[4] = (float)*param_3;
  local_20[5] = (float)param_3[1];
  uVar2 = 0;
  do {
    fVar3 = *(float *)((int)local_20 + uVar2 + 8);
    if (fVar3 < *(float *)((int)local_20 + uVar2) || fVar3 == *(float *)((int)local_20 + uVar2)) {
      fVar3 = *(float *)((int)local_20 + uVar2 + 8);
      pfVar1 = (float *)((int)local_20 + uVar2 + 0x10);
      if ((*pfVar1 <= fVar3 && fVar3 != *pfVar1) ||
         (fVar3 = *(float *)((int)local_20 + uVar2 + 0x18),
         *(float *)((int)local_20 + uVar2) <= fVar3 && fVar3 != *(float *)((int)local_20 + uVar2)))
      goto LAB_0040d2d1;
      fVar3 = *(float *)((int)local_20 + uVar2);
      pfVar1 = (float *)((int)local_20 + uVar2 + 0x18);
      fVar4 = *(float *)((int)local_20 + uVar2 + 8) - *(float *)((int)local_20 + uVar2);
      if (fVar3 < *pfVar1 || fVar3 == *pfVar1) {
        fVar3 = 0.0;
      }
      else {
        fVar3 = (*(float *)((int)local_20 + uVar2 + 0x10) - fVar3) / fVar4;
      }
      fVar5 = *(float *)((int)local_20 + uVar2 + 0x10);
      pfVar1 = (float *)((int)local_20 + uVar2 + 8);
      if (fVar5 < *pfVar1 || fVar5 == *pfVar1) goto LAB_0040d2a7;
      fVar4 = (*(float *)((int)local_20 + uVar2 + 0x18) - *(float *)((int)local_20 + uVar2)) / fVar4
      ;
    }
    else {
      pfVar1 = (float *)((int)local_20 + uVar2 + 0x10);
      if ((*pfVar1 <= *(float *)((int)local_20 + uVar2) &&
           *(float *)((int)local_20 + uVar2) != *pfVar1) ||
         (fVar3 = *(float *)((int)local_20 + uVar2 + 0x18),
         pfVar1 = (float *)((int)local_20 + uVar2 + 8), *pfVar1 <= fVar3 && fVar3 != *pfVar1))
      goto LAB_0040d2d1;
      fVar4 = *(float *)((int)local_20 + uVar2 + 8) - *(float *)((int)local_20 + uVar2);
      if (fVar3 < *(float *)((int)local_20 + uVar2) || fVar3 == *(float *)((int)local_20 + uVar2)) {
        fVar3 = 0.0;
      }
      else {
        fVar3 = (fVar3 - *(float *)((int)local_20 + uVar2)) / fVar4;
      }
      fVar5 = *(float *)((int)local_20 + uVar2 + 8);
      pfVar1 = (float *)((int)local_20 + uVar2 + 0x10);
      if (fVar5 < *pfVar1 || fVar5 == *pfVar1) {
LAB_0040d2a7:
        fVar4 = DAT_0099d080;
      }
      else {
        fVar4 = (*(float *)((int)local_20 + uVar2 + 0x10) - *(float *)((int)local_20 + uVar2)) /
                fVar4;
      }
    }
    fVar5 = 0.0;
    if (0.0 < fVar3) {
      fVar5 = fVar3;
    }
    fVar3 = DAT_0099d080;
    if (fVar4 < DAT_0099d080) {
      fVar3 = fVar4;
    }
    if (fVar3 < fVar5) {
LAB_0040d2d1:
      return uVar2 & 0xffffff00;
    }
    uVar2 = uVar2 + 4;
    if (7 < (int)uVar2) {
      return CONCAT31((int3)(uVar2 >> 8),1);
    }
  } while( true );
}


// ==== FUN_0040d2e0 @ 0x0040d2e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0040d2e0(float *param_1,float param_2,float param_3,float param_4,float param_5,
            undefined8 param_6,float param_7,float param_8)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  
  param_4 = param_4 - param_2;
  param_5 = param_5 - param_3;
  fVar3 = ((float10)param_8 - (float10)param_6._4_4_) * (float10)param_4 -
          ((float10)param_7 - (float10)(float)param_6) * (float10)param_5;
  if ((float10)_DAT_0099d0a8 < ABS(fVar3)) {
    fVar3 = (float10)_DAT_0099d0a0 / fVar3;
    fVar2 = ((float10)(param_3 - param_6._4_4_) * ((float10)param_7 - (float10)(float)param_6) -
            (float10)(param_2 - (float)param_6) * ((float10)param_8 - (float10)param_6._4_4_)) *
            fVar3;
    fVar1 = ((param_3 - param_6._4_4_) * param_4 - (param_2 - (float)param_6) * param_5) *
            (float)fVar3;
    if (ABS(fVar2) < (float10)_DAT_0099d0a8) {
      fVar2 = (float10)_DAT_0099d098;
    }
    if (ABS(fVar1) < (float)_DAT_0099d0a8) {
      fVar1 = (float)_DAT_0099d098;
    }
    if (((float10)_DAT_0099d090 < fVar2) && (fVar2 < (float10)_DAT_0099d088)) {
      fVar2 = (float10)_DAT_0099d0a0;
    }
    if ((_DAT_0099d090 < (double)fVar1) && (fVar1 < (float)_DAT_0099d088)) {
      fVar1 = (float)_DAT_0099d0a0;
    }
    *param_1 = (float)((float10)param_4 * fVar2 + (float10)param_2);
    param_1[1] = (float)((float10)param_5 * fVar2 + (float10)param_3);
    if (fVar2 < (float10)_DAT_0099d098) {
      return 0;
    }
    if (((fVar2 <= (float10)_DAT_0099d0a0) && (_DAT_0099d098 <= (double)fVar1)) &&
       (fVar1 <= (float)_DAT_0099d0a0)) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0040d4c0 @ 0x0040d4c0 ====

unkbyte10 FUN_0040d4c0(float param_1)

{
  unkbyte10 Var1;
  
  Var1 = fsin((float10)param_1);
  return Var1;
}


// ==== FUN_0040d4d0 @ 0x0040d4d0 ====

unkbyte10 FUN_0040d4d0(float param_1)

{
  unkbyte10 Var1;
  
  Var1 = fcos((float10)param_1);
  return Var1;
}


// ==== FUN_0040d4f0 @ 0x0040d4f0 ====

void FUN_0040d4f0(void)

{
  FUN_00801e30();
  return;
}


// ==== FUN_0040d520 @ 0x0040d520 ====

unkbyte10 FUN_0040d520(float param_1,float param_2)

{
  unkbyte10 Var1;
  
  Var1 = fpatan((float10)param_1,(float10)param_2);
  return Var1;
}


// ==== FUN_0040d530 @ 0x0040d530 ====

void FUN_0040d530(void)

{
  FUN_00801f40();
  return;
}


// ==== FUN_0040d540 @ 0x0040d540 ====

float10 FUN_0040d540(float param_1)

{
  return SQRT((float10)param_1);
}


// ==== FUN_0040d570 @ 0x0040d570 ====

byte FUN_0040d570(float *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  
  iVar4 = 0;
  pfVar3 = (float *)(param_2 + 4);
  iVar1 = 0;
  do {
    iVar2 = iVar1;
    if (pfVar3[-1] * *param_1 + pfVar3[1] * param_1[2] + *pfVar3 * param_1[1] + pfVar3[2] +
        param_1[3] < 0.0) {
      return 1;
    }
    iVar4 = iVar4 + 1;
    pfVar3 = pfVar3 + 4;
    iVar1 = iVar2 + 1;
  } while (iVar4 < 6);
  return -(iVar2 != 5) & 2;
}


// ==== FUN_0040d5f0 @ 0x0040d5f0 ====

unkbyte10 FUN_0040d5f0(float *param_1)

{
  unkbyte10 Var1;
  
  Var1 = fpatan(-(float10)*param_1,-(float10)param_1[1]);
  return Var1;
}


// ==== FUN_0040d600 @ 0x0040d600 ====

void FUN_0040d600(float *param_1,float param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)fsin((float10)param_2);
  *param_1 = (float)-fVar1;
  fVar1 = (float10)fcos((float10)param_2);
  param_1[1] = (float)-fVar1;
  return;
}


// ==== FUN_0040d620 @ 0x0040d620 ====

void FUN_0040d620(undefined4 *param_1,float *param_2)

{
  float10 fVar1;
  float10 fVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  fVar1 = (float10)fpatan((float10)param_2[1],
                          SQRT((float10)*param_2 * (float10)*param_2 +
                               (float10)param_2[2] * (float10)param_2[2]));
  fVar2 = (float10)fpatan(-(float10)*param_2,-(float10)param_2[2]);
  thunk_FUN_007a09e6(&local_10,(float)fVar2,(float)fVar1,0);
  *param_1 = local_10;
  param_1[1] = local_c;
  param_1[2] = local_8;
  param_1[3] = local_4;
  return;
}


// ==== FUN_0040d690 @ 0x0040d690 ====

void FUN_0040d690(undefined4 *param_1,float *param_2)

{
  float10 fVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  fVar1 = (float10)fpatan(-(float10)*param_2,-(float10)param_2[1]);
  local_1c = 0;
  local_18 = DAT_0099d080;
  local_14 = 0;
  thunk_FUN_007a095f(&local_10,&local_1c,(float)fVar1);
  *param_1 = local_10;
  param_1[1] = local_c;
  param_1[2] = local_8;
  param_1[3] = local_4;
  return;
}


// ==== FUN_0040d790 @ 0x0040d790 ====

undefined4
FUN_0040d790(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6)

{
  float unaff_retaddr;
  float local_8;
  float local_4;
  
  local_8 = param_3 - param_1;
  local_4 = param_4 - param_2;
  param_3 = param_5 - param_1;
  param_4 = param_6 - param_2;
  thunk_FUN_0079de77(&local_8,&local_8);
  thunk_FUN_0079de77();
  if (DAT_0099cdc8 <= unaff_retaddr * (float)&param_1 + local_4 * (float)&param_1) {
    return 1;
  }
  return 0;
}


// ==== FUN_0040d830 @ 0x0040d830 ====

undefined4 FUN_0040d830(float param_1,float param_2,float param_3,float param_4)

{
  float local_8;
  float local_4;
  
  local_8 = param_3 - param_1;
  local_4 = param_4 - param_2;
  thunk_FUN_0079de77();
  if (DAT_0099cdc8 <= param_4 * (float)&local_8 + param_3 * (float)&local_8) {
    return 1;
  }
  return 0;
}


// ==== FUN_0040d8a0 @ 0x0040d8a0 ====

void FUN_0040d8a0(float *param_1,float *param_2,float *param_3)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar4 = param_2[1];
  fVar5 = param_2[2];
  fVar6 = param_1[1];
  fVar7 = param_1[2];
  *param_3 = *param_1 - *param_2;
  param_3[1] = fVar6 - fVar4;
  param_3[2] = fVar7 - fVar5;
  fVar4 = param_2[1];
  fVar5 = param_1[2];
  fVar6 = param_1[1];
  fVar7 = param_2[2];
  pfVar1 = param_3 + 3;
  *pfVar1 = *param_1 - *param_2;
  param_3[4] = fVar6 - fVar4;
  param_3[5] = fVar7 - fVar5;
  fVar4 = param_1[1];
  fVar5 = param_2[2];
  fVar6 = param_2[1];
  fVar7 = param_1[2];
  pfVar2 = param_3 + 6;
  *pfVar2 = *param_1 - *param_2;
  param_3[7] = fVar6 - fVar4;
  param_3[8] = fVar7 - fVar5;
  fVar4 = param_2[1];
  fVar5 = param_2[2];
  fVar6 = param_1[1];
  fVar7 = param_1[2];
  pfVar3 = param_3 + 9;
  *pfVar3 = *param_2 - *param_1;
  param_3[10] = fVar6 - fVar4;
  param_3[0xb] = fVar7 - fVar5;
  thunk_FUN_0079e1ba(param_3,param_3);
  thunk_FUN_0079e1ba(pfVar1,pfVar1);
  thunk_FUN_0079e1ba(pfVar2,pfVar2);
  thunk_FUN_0079e1ba(pfVar3,pfVar3);
  return;
}


// ==== FUN_0040da20 @ 0x0040da20 ====

void FUN_0040da20(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 float *param_5,float *param_6)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  byte bVar6;
  undefined4 uVar7;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  fVar2 = *param_6;
  fVar3 = param_6[1];
  fVar4 = param_6[2];
  local_10 = 0.0;
  fVar5 = ABS(fVar2 * *param_5 + fVar3 * param_5[1] + fVar4 * param_5[2]);
  if (DAT_0099cdc8 <= fVar5) {
    local_10 = fVar5;
  }
  fVar5 = ABS(fVar2 * param_5[3] + fVar3 * param_5[4] + fVar4 * param_5[5]);
  bVar6 = local_10 <= fVar5;
  if ((bool)bVar6) {
    local_10 = fVar5;
  }
  fVar5 = ABS(fVar2 * param_5[6] + fVar3 * param_5[7] + fVar4 * param_5[8]);
  if (local_10 <= fVar5) {
    bVar6 = 2;
    local_10 = fVar5;
  }
  if (ABS(fVar2 * param_5[9] + fVar3 * param_5[10] + fVar4 * param_5[0xb]) < local_10) {
    if (3 < bVar6) {
      return;
    }
  }
  else {
    bVar6 = 3;
  }
  switch(bVar6) {
  case 0:
    uVar7 = param_4[1];
    uVar1 = param_4[2];
    *param_1 = *param_4;
    param_1[1] = uVar7;
    param_1[2] = uVar1;
    uVar7 = param_3[1];
    uVar1 = param_3[2];
    *param_2 = *param_3;
    param_2[1] = uVar7;
    param_2[2] = uVar1;
    return;
  case 1:
    uVar7 = param_4[1];
    uVar1 = param_3[2];
    *param_1 = *param_4;
    param_1[1] = uVar7;
    param_1[2] = uVar1;
    local_c = *param_3;
    local_8 = param_3[1];
    param_3 = param_4;
    break;
  case 2:
    uVar7 = param_3[1];
    uVar1 = param_4[2];
    *param_1 = *param_4;
    param_1[1] = uVar7;
    param_1[2] = uVar1;
    local_c = *param_3;
    local_8 = param_4[1];
    uVar7 = param_3[2];
    goto LAB_0040dc99;
  case 3:
    uVar7 = param_4[1];
    uVar1 = param_4[2];
    *param_1 = *param_3;
    param_1[1] = uVar7;
    param_1[2] = uVar1;
    local_c = *param_4;
    local_8 = param_3[1];
  }
  uVar7 = param_3[2];
LAB_0040dc99:
  *param_2 = local_c;
  param_2[1] = local_8;
  param_2[2] = uVar7;
  return;
}


// ==== FUN_0040dd30 @ 0x0040dd30 ====

void FUN_0040dd30(undefined4 *param_1,float *param_2,float *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  float10 fVar3;
  float fVar4;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  undefined4 local_40 [6];
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
  
  fVar4 = param_2[1] * param_3[1] + *param_2 * *param_3 + param_3[2] * param_2[2];
  if (fVar4 <= DAT_0099d0e4) {
    if (DAT_0099d0e0 <= fVar4) {
      local_64 = param_2[1] * param_3[2] - param_2[2] * param_3[1];
      local_60 = *param_3 * param_2[2] - param_3[2] * *param_2;
      local_5c = *param_2 * param_3[1] - param_2[1] * *param_3;
      local_58 = local_64;
      local_54 = local_60;
      local_50 = local_5c;
      thunk_FUN_0079e1ba(&local_64,&local_64);
      local_58 = param_2[1] * local_5c - local_60 * param_2[2];
      local_50 = *param_2 * local_60 - param_2[1] * local_64;
      local_54 = local_64 * param_2[2] - *param_2 * local_5c;
      fVar3 = (float10)fpatan(-((float10)local_54 * (float10)param_3[1] +
                               (float10)local_58 * (float10)*param_3 +
                               (float10)local_50 * (float10)param_3[2]),(float10)fVar4);
      fStack_4c = local_58;
      fStack_48 = local_54;
      fStack_44 = local_50;
      thunk_FUN_0079fa6c(local_40,&local_64,(float)fVar3);
    }
    else {
      local_8 = 0;
      local_c = 0;
      local_10 = 0;
      local_14 = 0;
      local_1c = 0;
      local_20 = 0;
      local_24 = 0;
      local_28 = 0;
      local_40[4] = 0;
      local_40[3] = 0;
      local_40[2] = 0;
      local_40[1] = 0;
      local_4 = DAT_0099d080;
      local_40[5] = DAT_0099d080;
      local_18 = DAT_0099d0dc;
      local_40[0] = DAT_0099d0dc;
    }
  }
  else {
    local_8 = 0;
    local_c = 0;
    local_10 = 0;
    local_14 = 0;
    local_1c = 0;
    local_20 = 0;
    local_24 = 0;
    local_28 = 0;
    local_40[4] = 0;
    local_40[3] = 0;
    local_40[2] = 0;
    local_40[1] = 0;
    local_4 = DAT_0099d080;
    local_18 = DAT_0099d080;
    local_40[5] = DAT_0099d080;
    local_40[0] = DAT_0099d080;
  }
  puVar2 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_0040dfb0 @ 0x0040dfb0 ====

undefined4 FUN_0040dfb0(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  if (((((*param_2 <= *param_1) && (*param_1 <= *param_3)) && (param_2[1] <= param_1[1])) &&
      ((param_1[1] <= param_3[1] && (param_2[2] <= param_1[2])))) && (param_1[2] <= param_3[2])) {
    *param_4 = 0.0;
    return 1;
  }
  if (DAT_0099d0ec < ABS(param_1[3])) {
    fVar3 = (*param_3 - *param_1) * (DAT_0099d080 / param_1[3]);
    fVar4 = (*param_2 - *param_1) * (DAT_0099d080 / param_1[3]);
    fVar5 = fVar4;
    if (fVar4 <= fVar3) {
      fVar5 = fVar3;
      fVar3 = fVar4;
    }
    if (fVar5 < 0.0) {
      return 0;
    }
  }
  else {
    if (*param_1 < *param_2) {
      return 0;
    }
    if (*param_3 < *param_1) {
      return 0;
    }
    fVar5 = DAT_0099d0f0;
    fVar3 = DAT_0099d0e8;
  }
  if (DAT_0099d0ec < ABS(param_1[4])) {
    fVar1 = (param_2[1] - param_1[1]) * (DAT_0099d080 / param_1[4]);
    fVar4 = (param_3[1] - param_1[1]) * (DAT_0099d080 / param_1[4]);
    fVar2 = fVar1;
    if (fVar1 <= fVar4) {
      fVar2 = fVar4;
      fVar4 = fVar1;
    }
    if (fVar2 < 0.0) {
      return 0;
    }
  }
  else {
    if (param_1[1] < param_2[1]) {
      return 0;
    }
    if (param_3[1] < param_1[1]) {
      return 0;
    }
    fVar2 = DAT_0099d0f0;
    fVar4 = DAT_0099d0e8;
  }
  if (fVar3 <= fVar4) {
    fVar3 = fVar4;
  }
  if (fVar2 < fVar5) {
    fVar5 = fVar2;
  }
  if ((fVar3 <= fVar5) && (0.0 <= fVar5)) {
    if (DAT_0099d0ec < ABS(param_1[5])) {
      fVar1 = (param_2[2] - param_1[2]) * (DAT_0099d080 / param_1[5]);
      fVar4 = (param_3[2] - param_1[2]) * (DAT_0099d080 / param_1[5]);
      fVar2 = fVar1;
      if (fVar1 <= fVar4) {
        fVar2 = fVar4;
        fVar4 = fVar1;
      }
      if (fVar2 < 0.0) {
        return 0;
      }
    }
    else {
      if (param_1[2] < param_2[2]) {
        return 0;
      }
      if (param_3[2] < param_1[2]) {
        return 0;
      }
      fVar2 = DAT_0099d0f0;
      fVar4 = DAT_0099d0e8;
    }
    fVar1 = fVar2;
    if (fVar5 <= fVar2) {
      fVar1 = fVar5;
    }
    fVar6 = fVar3;
    if (fVar3 <= fVar4) {
      fVar6 = fVar4;
    }
    if (fVar5 <= fVar2) {
      fVar2 = fVar5;
    }
    if (fVar3 <= fVar4) {
      fVar3 = fVar4;
    }
    if (fVar3 <= fVar2) {
      if (DAT_0099cdc8 <= fVar6) {
        *param_4 = fVar6;
        return 1;
      }
      *param_4 = fVar1;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0040e200 @ 0x0040e200 ====

undefined4
FUN_0040e200(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
            float *param_6,float *param_7)

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
  
  fVar3 = param_4[1] - param_2[1];
  fVar5 = param_4[2] - param_2[2];
  fVar1 = *param_4 - *param_2;
  fVar10 = param_3[2] - param_2[2];
  fVar8 = param_3[1] - param_2[1];
  fVar11 = *param_3 - *param_2;
  fVar12 = param_1[4] * fVar5 - param_1[5] * fVar3;
  fVar13 = param_1[5] * fVar1 - param_1[3] * fVar5;
  fVar6 = param_1[3] * fVar3 - param_1[4] * fVar1;
  fVar7 = fVar13 * fVar8 + fVar6 * fVar10 + fVar11 * fVar12;
  if (fVar7 <= 0.0) {
    fVar2 = *param_2 - *param_1;
    fVar9 = param_2[1] - param_1[1];
    fVar4 = param_2[2] - param_1[2];
    fVar7 = 0.0 - fVar7;
  }
  else {
    fVar2 = *param_1 - *param_2;
    fVar9 = param_1[1] - param_2[1];
    fVar4 = param_1[2] - param_2[2];
  }
  if (DAT_0099d074 <= fVar7) {
    fVar6 = fVar4 * fVar6 + fVar9 * fVar13 + fVar2 * fVar12;
    *param_5 = fVar6;
    if ((0.0 <= fVar6) && (fVar6 <= fVar7)) {
      fVar12 = fVar9 * fVar10 - fVar4 * fVar8;
      fVar6 = fVar2 * fVar8 - fVar9 * fVar11;
      fVar10 = fVar4 * fVar11 - fVar2 * fVar10;
      fVar8 = param_1[4] * fVar10 + param_1[5] * fVar6 + param_1[3] * fVar12;
      *param_6 = fVar8;
      if ((0.0 <= fVar8) && (fVar8 + *param_5 <= fVar7)) {
        fVar7 = DAT_0099d080 / fVar7;
        *param_7 = (fVar6 * fVar5 + fVar10 * fVar3 + fVar12 * fVar1) * fVar7;
        *param_5 = *param_5 * fVar7;
        *param_6 = *param_6 * fVar7;
        if (0.0 < *param_7 || *param_7 == 0.0) {
          return 1;
        }
      }
    }
  }
  return 0;
}


// ==== FUN_0040e4a0 @ 0x0040e4a0 ====

float10 FUN_0040e4a0(float *param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar2 = param_1[5] * (param_2[2] - param_1[2]) + param_1[4] * (param_2[1] - param_1[1]) +
          param_1[3] * (*param_2 - *param_1);
  fVar3 = param_1[3] * fVar2;
  fVar4 = param_1[4] * fVar2;
  fVar2 = param_1[5] * fVar2;
  fVar1 = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar2 * fVar2);
  if ((DAT_0099cdc8 <= fVar1) &&
     (fVar3 = (*param_2 - *param_1) - fVar3, fVar4 = (param_2[1] - param_1[1]) - fVar4,
     fVar2 = (param_2[2] - param_1[2]) - fVar2,
     fVar3 = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar2 * fVar2), fVar3 <= param_3)) {
    fVar3 = SQRT(param_3 * param_3 - fVar3 * fVar3);
    fVar2 = fVar1 - fVar3;
    if (0.0 <= fVar2) {
      return (float10)fVar2;
    }
    return (float10)fVar3 + (float10)fVar1;
  }
  return (float10)DAT_0099d0f4;
}


// ==== FUN_0040e5f0 @ 0x0040e5f0 ====

undefined4 FUN_0040e5f0(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)

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
  
  fVar1 = param_4[2] - param_2[2];
  fVar13 = param_4[1] - param_2[1];
  fVar12 = *param_4 - *param_2;
  fVar10 = param_3[1] - param_2[1];
  fVar11 = param_3[2] - param_2[2];
  fVar9 = *param_3 - *param_2;
  fVar6 = param_1[4] * fVar1 - param_1[5] * fVar13;
  fVar7 = param_1[5] * fVar12 - param_1[3] * fVar1;
  fVar2 = param_1[3] * fVar13 - param_1[4] * fVar12;
  fVar8 = fVar7 * fVar10 + fVar2 * fVar11 + fVar9 * fVar6;
  if (DAT_0099d074 <= fVar8) {
    fVar3 = *param_1 - *param_2;
    fVar4 = param_1[1] - param_2[1];
    fVar5 = param_1[2] - param_2[2];
    fVar2 = fVar5 * fVar2 + fVar4 * fVar7 + fVar3 * fVar6;
    if ((0.0 <= fVar2) && (fVar2 <= fVar8)) {
      fVar6 = param_1[4] * (fVar5 * fVar9 - fVar3 * fVar11) +
              param_1[5] * (fVar3 * fVar10 - fVar4 * fVar9) +
              param_1[3] * (fVar4 * fVar11 - fVar5 * fVar10);
      if ((0.0 <= fVar6) && (fVar6 + fVar2 <= fVar8)) {
        fVar6 = (DAT_0099d080 / fVar8) * fVar6;
        fVar2 = (DAT_0099d080 / fVar8) * fVar2;
        fVar7 = param_2[2];
        fVar8 = param_2[1];
        *param_5 = *param_2 + fVar9 * fVar2 + fVar12 * fVar6;
        param_5[1] = fVar8 + fVar10 * fVar2 + fVar13 * fVar6;
        param_5[2] = fVar7 + fVar11 * fVar2 + fVar1 * fVar6;
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_0040e8c0 @ 0x0040e8c0 ====

void FUN_0040e8c0(float *param_1,uint param_2)

{
  float fVar1;
  
  fVar1 = DAT_0099d0b0;
  *param_1 = (float)(param_2 >> 0x10 & 0xff) * DAT_0099d0b0;
  param_1[1] = (float)(param_2 >> 8 & 0xff) * fVar1;
  param_1[2] = (float)(param_2 & 0xff) * fVar1;
  param_1[3] = (float)(param_2 >> 0x18) * fVar1;
  return;
}


// ==== FUN_0040e920 @ 0x0040e920 ====

void FUN_0040e920(undefined4 param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 uStack_30;
  float fStack_2c;
  float fStack_28;
  undefined1 local_18 [4];
  float *pfStack_14;
  
  thunk_FUN_0079e5a0(local_18,param_2,param_3);
  fVar1 = param_2[3];
  fVar2 = *param_2;
  fVar3 = param_2[4];
  fVar4 = param_2[1];
  fVar5 = param_2[5];
  fVar6 = param_2[2];
  thunk_FUN_0079e5a0(&uStack_30,local_18 + -0x24,param_3);
  *pfStack_14 = uStack_30;
  pfStack_14[1] = fStack_2c;
  pfStack_14[2] = fStack_28;
  pfStack_14[3] = (fVar1 + fVar2) - uStack_30;
  pfStack_14[4] = (fVar3 + fVar4) - fStack_2c;
  pfStack_14[5] = (fVar5 + fVar6) - fStack_28;
  return;
}


// ==== FUN_0040e9f0 @ 0x0040e9f0 ====

undefined4 FUN_0040e9f0(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *param_3 - *param_4;
  if (*param_3 - *param_4 < *param_1) {
    fVar1 = *param_1;
  }
  fVar2 = *param_3 + *param_4;
  if (*param_2 <= *param_3 + *param_4) {
    fVar2 = *param_2;
  }
  if (fVar1 <= fVar2) {
    fVar1 = param_3[1] - *param_4;
    if (param_3[1] - *param_4 < param_1[1]) {
      fVar1 = param_1[1];
    }
    fVar2 = param_3[1] + *param_4;
    if (param_2[1] <= param_3[1] + *param_4) {
      fVar2 = param_2[1];
    }
    if (fVar1 <= fVar2) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0040ead0 @ 0x0040ead0 ====

uint FUN_0040ead0(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  fVar1 = *param_1;
  fVar2 = param_1[1];
  fVar3 = param_1[2];
  fVar4 = param_1[3];
  if (fVar1 < DAT_0099d080) {
    if (0.0 < fVar1) {
      uVar7 = (uint)ROUND(fVar1 * DAT_0099d0b8 + DAT_0099d0b4);
    }
    else {
      uVar7 = 0;
    }
  }
  else {
    uVar7 = 0xff;
  }
  if (fVar2 < DAT_0099d080) {
    if (0.0 < fVar2) {
      uVar6 = (uint)ROUND(fVar2 * DAT_0099d0b8 + DAT_0099d0b4);
    }
    else {
      uVar6 = 0;
    }
  }
  else {
    uVar6 = 0xff;
  }
  if (fVar3 < DAT_0099d080) {
    if (0.0 < fVar3) {
      uVar5 = (uint)ROUND(fVar3 * DAT_0099d0b8 + DAT_0099d0b4);
    }
    else {
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 0xff;
  }
  if (DAT_0099d080 <= fVar4) {
    return ((uVar7 | 0xff00) << 8 | uVar6) << 8 | uVar5;
  }
  if (fVar4 <= 0.0) {
    return (uVar7 << 8 | uVar6) << 8 | uVar5;
  }
  return (((int)ROUND(fVar4 * DAT_0099d0b8 + DAT_0099d0b4) << 8 | uVar7) << 8 | uVar6) << 8 | uVar5;
}


// ==== FUN_0040ec60 @ 0x0040ec60 ====

void FUN_0040ec60(float *param_1,uint param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = (float)(param_2 >> 8 & 0xff) * DAT_0099d0b0;
  fVar2 = (float)(param_2 & 0xff) * DAT_0099d0b0;
  fVar3 = (float)(param_2 >> 0x18) * DAT_0099d0b0;
  *param_1 = (float)(param_2 >> 0x10 & 0xff) * DAT_0099d0b0;
  param_1[1] = fVar1;
  param_1[2] = fVar2;
  param_1[3] = fVar3;
  return;
}


// ==== FUN_0040ecc0 @ 0x0040ecc0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040ecc0(undefined4 *param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float local_18;
  float local_14;
  float local_10;
  float local_c [2];
  float *pfStack_4;
  
  iVar2 = _rand();
  fVar3 = (float)iVar2 * _DAT_0099d07c * DAT_0099d0f8 - DAT_0099d080;
  iVar2 = _rand();
  fVar4 = (float)iVar2 * _DAT_0099d07c * DAT_0099d0f8 - DAT_0099d080;
  iVar2 = _rand();
  fVar1 = DAT_0099d080;
  local_18 = ((float)iVar2 * _DAT_0099d07c + (float)iVar2 * _DAT_0099d07c) - DAT_0099d080;
  if (SQRT(fVar3 * fVar3 + fVar4 * fVar4 + local_18 * local_18) < DAT_0099d074) {
    *param_1 = 0;
    param_1[1] = fVar1;
    param_1[2] = 0;
    return;
  }
  local_14 = fVar4;
  local_10 = fVar3;
  thunk_FUN_0079e1ba(local_c,&local_18);
  *pfStack_4 = local_14;
  pfStack_4[1] = local_10;
  pfStack_4[2] = local_c[0];
  return;
}


// ==== FUN_0040edc0 @ 0x0040edc0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040edc0(void)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float local_c;
  float local_8;
  float *local_4;
  
  iVar1 = _rand();
  pfVar2 = (float *)((float)iVar1 * _DAT_0099d07c * DAT_0099d0f8 - DAT_0099d080);
  iVar1 = _rand();
  fVar3 = (float)iVar1 * _DAT_0099d07c * DAT_0099d0f8 - DAT_0099d080;
  iVar1 = _rand();
  local_c = (float)iVar1 * _DAT_0099d07c * DAT_0099d0f8 - DAT_0099d080;
  local_8 = fVar3;
  local_4 = pfVar2;
  thunk_FUN_0079e1ba(&local_c,&local_c);
  *local_4 = fVar3;
  local_4[1] = (float)pfVar2;
  local_4[2] = local_c;
  return;
}


// ==== FUN_0040eed0 @ 0x0040eed0 ====

undefined4 FUN_0040eed0(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  
  if (*param_2 < *param_4 || *param_2 == *param_4) {
    fVar2 = *param_2;
  }
  else {
    fVar2 = *param_4;
  }
  fVar1 = *param_1;
  if (fVar1 < *param_3 || fVar1 == *param_3) {
    fVar1 = *param_3;
  }
  if (fVar1 <= fVar2) {
    if (param_2[1] < param_4[1] || param_2[1] == param_4[1]) {
      fVar2 = param_2[1];
    }
    else {
      fVar2 = param_4[1];
    }
    fVar1 = param_1[1];
    if (fVar1 < param_3[1] || fVar1 == param_3[1]) {
      fVar1 = param_3[1];
    }
    if (fVar1 <= fVar2) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0040ef40 @ 0x0040ef40 ====

uint FUN_0040ef40(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_2[2];
  if (param_1[2] <= param_2[2]) {
    uVar2 = param_1[2];
  }
  uVar1 = *param_1;
  if (*param_1 <= *param_2) {
    uVar1 = *param_2;
  }
  if (uVar1 <= uVar2) {
    uVar2 = param_2[3];
    if (param_1[3] <= param_2[3]) {
      uVar2 = param_1[3];
    }
    uVar1 = param_1[1];
    if (param_1[1] <= param_2[1]) {
      uVar1 = param_2[1];
    }
    if (uVar1 <= uVar2) {
      return CONCAT31((int3)(uVar1 >> 8),1);
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0040ef90 @ 0x0040ef90 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0040ef90(float param_1,float param_2)

{
  param_2 = param_2 - (float)(int)((DAT_0099d080 / DAT_00adb4a4) * param_2) * DAT_00adb4a4;
  if (param_2 < 0.0) {
    param_2 = DAT_00adb4a4 + param_2;
  }
  param_1 = param_1 - (float)(int)((DAT_0099d080 / DAT_00adb4a4) * param_1) * DAT_00adb4a4;
  if (param_1 < 0.0) {
    param_1 = DAT_00adb4a4 + param_1;
  }
  param_2 = param_2 - param_1;
  if (param_2 <= _DAT_0099d078) {
    if (param_2 < DAT_0099d0fc) {
      param_2 = DAT_00adb4a4 + param_2;
    }
    return (float10)param_2;
  }
  return (float10)(param_2 - DAT_00adb4a4);
}


// ==== FUN_0040f050 @ 0x0040f050 ====

undefined4 FUN_0040f050(float *param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float fStack_8;
  float fStack_4;
  
  local_18 = *param_2 - *param_1;
  local_14 = param_2[1] - param_1[1];
  local_10 = param_2[2] - param_1[2];
  if ((SQRT(local_18 * local_18 + local_14 * local_14 + local_10 * local_10) <= param_3) ||
     (thunk_FUN_0079e1ba(&local_c,&local_18),
     0.0 < param_1[4] * fStack_8 + param_1[5] * fStack_4 + param_1[3] * local_c)) {
    fVar3 = param_1[1] - param_2[1];
    fVar4 = param_1[2] - param_2[2];
    fVar2 = *param_1 - *param_2;
    fVar1 = param_1[5] * fVar4 + param_1[4] * fVar3 + param_1[3] * fVar2;
    fVar2 = (fVar4 * fVar4 + fVar3 * fVar3 + fVar2 * fVar2) - param_2[3] * param_2[3];
    if (0.0 <= fVar1 * fVar1 - fVar2) {
      fVar3 = fVar1 * param_3 * DAT_0099d0f8;
      fVar2 = param_3 * param_3 + fVar2;
      fVar4 = fVar2 - fVar3;
      if ((fVar3 + fVar2) * fVar4 <= 0.0) {
        return 1;
      }
      if ((0.0 < fVar4) && (ABS(fVar1) < param_3)) {
        return 1;
      }
      return 0;
    }
  }
  return 0;
}


// ==== FUN_0040f1e0 @ 0x0040f1e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040f1e0(undefined4 param_1,undefined1 param_2,int param_3,int param_4,undefined4 param_5)

{
  float fVar1;
  float *pfVar2;
  undefined1 *puVar3;
  float local_10 [2];
  float *pfStack_8;
  
  puVar3 = &param_2;
  pfVar2 = local_10;
  thunk_FUN_0079e43e(pfVar2,puVar3,param_5);
  local_10[0] = DAT_0099d080 / local_10[0];
  fVar1 = (float)param_3;
  if (param_3 < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  *pfStack_8 = fVar1 * (local_10[0] * (float)pfVar2 + DAT_0099d080) * DAT_0099d0b4;
  fVar1 = (float)param_4;
  if (param_4 < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  pfStack_8[1] = fVar1 * (DAT_0099d080 - local_10[0] * (float)puVar3) * DAT_0099d0b4 - DAT_0099d100;
  return;
}


// ==== FUN_0040f280 @ 0x0040f280 ====

byte FUN_0040f280(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float fVar6;
  float fVar7;
  int local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  fVar7 = 0.0;
  iVar4 = 0;
  local_1c = 0;
  pfVar5 = (float *)(param_4 + 4);
  do {
    pfVar1 = pfVar5 + -1;
    FUN_0040da20(&local_18,&local_c,param_2,param_3,param_1,pfVar1);
    fVar6 = pfVar5[1] * local_10 + *pfVar1 * local_18 + local_14 * *pfVar5 + pfVar5[2];
    if (fVar7 <= fVar6) {
      if (fVar6 == fVar7) {
        iVar3 = 3;
      }
      else {
        iVar3 = 0;
      }
    }
    else {
      iVar3 = 1;
    }
    fVar6 = *pfVar1 * local_c + pfVar5[1] * local_4 + local_8 * *pfVar5 + pfVar5[2];
    if (fVar7 <= fVar6) {
      if (fVar6 == fVar7) {
        iVar2 = 3;
      }
      else {
        iVar2 = 0;
      }
    }
    else {
      iVar2 = 1;
    }
    if (iVar3 == 1) {
      if (iVar2 == 1) {
        return 1;
      }
    }
    else if ((iVar3 == 0) && (iVar2 == 0)) {
      local_1c = local_1c + 1;
    }
    iVar4 = iVar4 + 1;
    pfVar5 = pfVar5 + 4;
  } while (iVar4 < 6);
  return -(local_1c != 6) & 2;
}


// ==== FUN_0040f420 @ 0x0040f420 ====

uint FUN_0040f420(float *param_1,int param_2)

{
  float *pfVar1;
  int iVar2;
  
  iVar2 = 0;
  pfVar1 = (float *)(param_2 + 4);
  do {
    if (pfVar1[-1] * *param_1 + pfVar1[1] * param_1[2] + *pfVar1 * param_1[1] + pfVar1[2] < 0.0) {
      return CONCAT31((int3)((uint)pfVar1 >> 8),1);
    }
    iVar2 = iVar2 + 1;
    pfVar1 = pfVar1 + 4;
  } while (iVar2 < 3);
  return (uint)pfVar1 & 0xffffff00;
}


// ==== FUN_0040f630 @ 0x0040f630 ====

void FUN_0040f630(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_30 [48];
  
  FUN_0040d8a0(param_1,param_2,local_30);
  FUN_0040f280(local_30,param_1,param_2,param_3);
  return;
}


// ==== FUN_0040f670 @ 0x0040f670 ====

void FUN_0040f670(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  float *pfVar1;
  int iVar2;
  float *pfVar3;
  float local_78;
  float local_74;
  float local_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  undefined4 local_60;
  undefined4 local_5c;
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
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
  float *local_8;
  undefined4 local_4;
  
  local_60 = *param_2;
  local_5c = param_2[1];
  local_58 = (float)param_2[2];
  local_54 = *param_2;
  local_50 = param_2[1];
  local_4c = param_2[5];
  local_48 = *param_2;
  local_44 = param_2[4];
  local_40 = param_2[2];
  local_3c = *param_2;
  local_38 = param_2[4];
  local_34 = param_2[5];
  local_30 = param_2[3];
  local_2c = param_2[1];
  local_28 = param_2[2];
  local_24 = param_2[3];
  local_20 = param_2[1];
  local_1c = param_2[5];
  local_18 = param_2[3];
  local_14 = param_2[4];
  local_10 = param_2[2];
  local_c = param_2[3];
  local_8 = (float *)param_2[4];
  local_4 = param_2[5];
  thunk_FUN_0079e5a0(&local_60,&local_60,param_3);
  local_78 = fStack_6c;
  local_74 = fStack_68;
  local_70 = fStack_64;
  pfVar3 = &local_58;
  iVar2 = 7;
  do {
    pfVar1 = pfVar3 + -2;
    thunk_FUN_0079e5a0(pfVar1,pfVar1,param_3);
    if (*pfVar1 <= fStack_6c) {
      fStack_6c = *pfVar1;
    }
    if (pfVar3[-1] <= fStack_68) {
      fStack_68 = pfVar3[-1];
    }
    if (*pfVar3 <= fStack_64) {
      fStack_64 = *pfVar3;
    }
    if (local_78 < *pfVar1 || local_78 == *pfVar1) {
      local_78 = *pfVar1;
    }
    if (local_74 < pfVar3[-1] || local_74 == pfVar3[-1]) {
      local_74 = pfVar3[-1];
    }
    if (local_70 < *pfVar3 || local_70 == *pfVar3) {
      local_70 = *pfVar3;
    }
    pfVar3 = pfVar3 + 3;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *local_8 = fStack_6c;
  local_8[1] = fStack_68;
  local_8[2] = fStack_64;
  local_8[3] = local_78;
  local_8[4] = local_74;
  local_8[5] = local_70;
  return;
}


// ==== FUN_0040f960 @ 0x0040f960 ====

void FUN_0040f960(undefined4 param_1,float *param_2)

{
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  undefined1 local_30 [48];
  
  local_3c = *param_2 - param_2[0xc];
  local_38 = param_2[1] - param_2[0xd];
  local_34 = param_2[2] - param_2[0xe];
  local_48 = param_2[0xc] + *param_2;
  local_44 = param_2[1] + param_2[0xd];
  local_40 = param_2[2] + param_2[0xe];
  FUN_0040d8a0(&local_3c,&local_48,local_30);
  FUN_0040f280(local_30,&local_3c,&local_48,param_1);
  return;
}


// ==== FUN_0040fa30 @ 0x0040fa30 ====

undefined4 FUN_0040fa30(undefined4 param_1,undefined4 param_2)

{
  thunk_FUN_0079de77(param_1,param_2);
  return param_1;
}


// ==== FUN_0040fa50 @ 0x0040fa50 ====

void FUN_0040fa50(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  fVar1 = *param_2;
  if (fVar1 < *param_3 || fVar1 == *param_3) {
    fVar1 = *param_3;
  }
  *param_1 = fVar1;
  fVar1 = param_2[1];
  if (fVar1 < param_3[1] || fVar1 == param_3[1]) {
    fVar1 = param_3[1];
  }
  param_1[1] = fVar1;
  fVar1 = param_2[2];
  if (fVar1 < param_3[2] || fVar1 == param_3[2]) {
    param_1[2] = param_3[2];
    return;
  }
  param_1[2] = fVar1;
  return;
}


// ==== FUN_0040fab0 @ 0x0040fab0 ====

void FUN_0040fab0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  if (*param_3 < *param_2 || *param_3 == *param_2) {
    fVar1 = *param_3;
  }
  else {
    fVar1 = *param_2;
  }
  *param_1 = fVar1;
  if (param_3[1] < param_2[1] || param_3[1] == param_2[1]) {
    fVar1 = param_3[1];
  }
  else {
    fVar1 = param_2[1];
  }
  param_1[1] = fVar1;
  if (param_2[2] <= param_3[2] && param_3[2] != param_2[2]) {
    param_1[2] = param_2[2];
    return;
  }
  param_1[2] = param_3[2];
  return;
}


// ==== FUN_0040fb10 @ 0x0040fb10 ====

void FUN_0040fb10(undefined4 *param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 8))(*param_1,param_1[1]);
  return;
}


// ==== FUN_0040fb30 @ 0x0040fb30 ====

uint FUN_0040fb30(int *param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x1c))(param_1);
  if ((char)uVar1 == '\x01') {
    return uVar1;
  }
  if (*param_1 == 0x113) {
    uVar1 = FUN_00424150();
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0040fb70 @ 0x0040fb70 ====

void FUN_0040fb70(int *param_1,void *param_2)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_8;
  undefined2 local_4;
  
  cVar1 = FUN_004244e0(1);
  if (cVar1 == '\0') {
    (**(code **)(*param_1 + 0x18))(param_2);
    return;
  }
  iVar2 = FUN_00424500();
  if (iVar2 == 0x10001) {
    _free(param_2);
    return;
  }
  if (*(char *)((int)param_2 + 0x10) == '\0') {
    local_8 = *(undefined4 *)((int)param_2 + 0x14);
    local_4 = *(undefined2 *)((int)param_2 + 0x18);
    (**(code **)(**(int **)(in_ECX + 8) + 4))(&local_8);
  }
  _free(param_2);
  return;
}


// ==== FUN_0040fc00 @ 0x0040fc00 ====

void FUN_0040fc00(undefined4 *param_1)

{
  int iVar1;
  int *_Memory;
  int in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(in_ECX + 0xc);
  uVar2 = 0;
  uVar3 = 0;
  if (*(int *)(iVar1 + 8) != 0) {
    uVar3 = *(undefined4 *)(**(int **)(iVar1 + 4) + 8);
    uVar2 = *(undefined4 *)(**(int **)(iVar1 + 4) + 0xc);
    _Memory = (int *)**(int **)(iVar1 + 4);
    if (_Memory != *(int **)(iVar1 + 4)) {
      *(int *)_Memory[1] = *_Memory;
      *(int *)(*_Memory + 4) = _Memory[1];
      _free(_Memory);
      return;
    }
  }
  *param_1 = uVar3;
  param_1[1] = uVar2;
  return;
}


// ==== FUN_0040fc50 @ 0x0040fc50 ====

void FUN_0040fc50(undefined4 param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  WSADATA local_19c;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009786e5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099d1b8;
  iVar1 = WSAStartup(0x202,&local_19c);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _abort();
  }
  in_ECX[1] = param_1;
  pvVar2 = operator_new(0x1c);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004245e0(in_ECX[1]);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar3;
  pvVar2 = operator_new(0xc);
  local_4._0_1_ = 2;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    uVar3 = FUN_0040fed0();
    *(undefined4 *)((int)pvVar2 + 4) = uVar3;
    *(undefined4 *)((int)pvVar2 + 8) = 0;
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[3] = pvVar2;
  pvVar2 = operator_new(0x14);
  local_4 = CONCAT31(local_4._1_3_,3);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004241e0();
  }
  in_ECX[4] = uVar3;
  SetTimer((HWND)in_ECX[1],0x18,1,(TIMERPROC)0x0);
  DAT_00b5a68c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0040fd80 @ 0x0040fd80 ====

void FUN_0040fd80(void)

{
  int *piVar1;
  void *_Memory;
  int iVar2;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009786f7;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099d1b8;
  DAT_00b5a68c = 0;
  piVar1 = (int *)**(int **)(in_ECX[3] + 4);
  local_4 = 0;
  if (piVar1 != *(int **)(in_ECX[3] + 4)) {
    _free((void *)piVar1[3]);
    return;
  }
  KillTimer((HWND)in_ECX[1],0x18);
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  _Memory = (void *)in_ECX[3];
  in_ECX[4] = 0;
  if (_Memory != (void *)0x0) {
    FUN_008984a0();
    _free(_Memory);
    return;
  }
  in_ECX[3] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  iVar2 = WSACleanup();
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    _abort();
  }
  *in_ECX = &PTR_FUN_0099d1b0;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0040fe60 @ 0x0040fe60 ====

void FUN_0040fe60(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0xc) + 4);
  iVar2 = FUN_0040fef0(iVar1,*(undefined4 *)(iVar1 + 4),param_1);
  FUN_0040ff40(1);
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}


// ==== FUN_0040fea0 @ 0x0040fea0 ====

void FUN_0040fea0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d1b0;
  return;
}


// ==== FUN_0040feb0 @ 0x0040feb0 ====

void FUN_0040feb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d1b0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0040fed0 @ 0x0040fed0 ====

void FUN_0040fed0(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x10);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  return;
}


// ==== FUN_0040fef0 @ 0x0040fef0 ====

void FUN_0040fef0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x10);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = *param_3;
    puVar1[3] = param_3[1];
  }
  return;
}


// ==== FUN_0040ff20 @ 0x0040ff20 ====

void FUN_0040ff20(byte param_1)

{
  void *in_ECX;
  
  FUN_0040fd80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0040ff40 @ 0x0040ff40 ====

void FUN_0040ff40(uint param_1)

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
  puStack_8 = &LAB_00978718;
  local_c = ExceptionList;
  if (0x1fffffffU - *(int *)(in_ECX + 8) < param_1) {
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


// ==== FUN_0040ffe0 @ 0x0040ffe0 ====

void FUN_0040ffe0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d284;
  return;
}


// ==== FUN_0040fff0 @ 0x0040fff0 ====

void FUN_0040fff0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d284;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


