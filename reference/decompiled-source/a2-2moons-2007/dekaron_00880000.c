// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x880000-0x88ffff

// ==== FUN_00880900 @ 0x00880900 ====

undefined4 FUN_00880900(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_0087f6f0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00880930 @ 0x00880930 ====

void FUN_00880930(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xd) = param_1;
  return;
}


// ==== FUN_00880940 @ 0x00880940 ====

void FUN_00880940(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 7) = param_1;
  return;
}


// ==== FUN_00880950 @ 0x00880950 ====

void FUN_00880950(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 9) = param_1;
  return;
}


// ==== FUN_00880960 @ 0x00880960 ====

void FUN_00880960(byte param_1)

{
  void *in_ECX;
  
  FUN_0087ee50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00880980 @ 0x00880980 ====

void FUN_00880980(void)

{
  void *pvVar1;
  
  if (DAT_00b5af70 == 0) {
    pvVar1 = operator_new(0x24);
    if (pvVar1 != (void *)0x0) {
      FUN_008960a0();
      return;
    }
  }
  return;
}


// ==== FUN_008809a0 @ 0x008809a0 ====

void FUN_008809a0(void)

{
  if (DAT_00b5af70 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5af70)(1);
  }
  return;
}


// ==== FUN_008809c0 @ 0x008809c0 ====

void FUN_008809c0(void)

{
  void *pvVar1;
  
  if (DAT_00b5d98c == 0) {
    pvVar1 = operator_new(0x1c);
    if (pvVar1 != (void *)0x0) {
      FUN_008967f0();
      return;
    }
  }
  return;
}


// ==== FUN_008809e0 @ 0x008809e0 ====

void FUN_008809e0(void)

{
  if (DAT_00b5d98c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d98c)(1);
  }
  return;
}


// ==== FUN_00880a00 @ 0x00880a00 ====

void FUN_00880a00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a147e0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00880a20 @ 0x00880a20 ====

void FUN_00880a20(void)

{
  FUN_00896870();
  return;
}


// ==== FUN_00880a30 @ 0x00880a30 ====

void FUN_00880a30(void)

{
  FUN_00896a70();
  return;
}


// ==== FUN_00880a40 @ 0x00880a40 ====

void FUN_00880a40(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a147f4;
  pvVar1 = operator_new(0x70);
  if (pvVar1 == (void *)0x0) {
    in_ECX[1] = 0;
    return;
  }
  uVar2 = FUN_00896c00();
  in_ECX[1] = uVar2;
  return;
}


// ==== FUN_00880a70 @ 0x00880a70 ====

void FUN_00880a70(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  
  _Memory = (void *)in_ECX[1];
  *in_ECX = &PTR_FUN_00a147f4;
  if (_Memory == (void *)0x0) {
    in_ECX[1] = 0;
    *in_ECX = &PTR_FUN_00a147e0;
    return;
  }
  FUN_00896920();
  _free(_Memory);
  return;
}


// ==== FUN_00880ab0 @ 0x00880ab0 ====

undefined4 FUN_00880ab0(undefined4 param_1,undefined4 param_2)

{
  FUN_00896f50(param_1,param_2);
  return param_1;
}


// ==== FUN_00880ad0 @ 0x00880ad0 ====

void FUN_00880ad0(byte param_1)

{
  void *_Memory;
  undefined4 *in_ECX;
  
  _Memory = (void *)in_ECX[1];
  *in_ECX = &PTR_FUN_00a147f4;
  if (_Memory != (void *)0x0) {
    FUN_00896920();
    _free(_Memory);
    return;
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_00a147e0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00880b20 @ 0x00880b20 ====

void FUN_00880b20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a14848;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00880b40 @ 0x00880b40 ====

void FUN_00880b40(void)

{
  FUN_00897df0();
  return;
}


// ==== FUN_00880b50 @ 0x00880b50 ====

undefined4 FUN_00880b50(undefined4 param_1,undefined4 param_2)

{
  FUN_00898380(param_1,param_2);
  return param_1;
}


// ==== FUN_00880b70 @ 0x00880b70 ====

void FUN_00880b70(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a1485c;
  pvVar1 = operator_new(0x70);
  if (pvVar1 == (void *)0x0) {
    in_ECX[1] = 0;
    return;
  }
  uVar2 = FUN_008982e0();
  in_ECX[1] = uVar2;
  return;
}


// ==== FUN_00880ba0 @ 0x00880ba0 ====

void FUN_00880ba0(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  
  _Memory = (void *)in_ECX[1];
  *in_ECX = &PTR_FUN_00a1485c;
  if (_Memory == (void *)0x0) {
    in_ECX[1] = 0;
    *in_ECX = &PTR_FUN_00a14848;
    return;
  }
  FUN_00897f10();
  _free(_Memory);
  return;
}


// ==== FUN_00880be0 @ 0x00880be0 ====

void FUN_00880be0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  for (puVar2 = *(undefined4 **)(param_1 + 4); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    FUN_00897e80(*puVar2);
  }
  return;
}


// ==== FUN_00880c10 @ 0x00880c10 ====

void FUN_00880c10(byte param_1)

{
  void *_Memory;
  undefined4 *in_ECX;
  
  _Memory = (void *)in_ECX[1];
  *in_ECX = &PTR_FUN_00a1485c;
  if (_Memory != (void *)0x0) {
    FUN_00897f10();
    _free(_Memory);
    return;
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_00a14848;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00880c60 @ 0x00880c60 ====

void FUN_00880c60(void)

{
  undefined4 *in_ECX;
  
  FUN_00881030();
  *in_ECX = &PTR_FUN_00a148c8;
  return;
}


// ==== FUN_00880c80 @ 0x00880c80 ====

void FUN_00880c80(uint param_1,undefined4 *param_2)

{
  int in_ECX;
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x14);
  for (uVar1 = param_1 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  for (uVar1 = param_1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)puVar2 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + param_1;
  *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) - param_1;
  *(uint *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + param_1;
  return;
}


// ==== FUN_00880cc0 @ 0x00880cc0 ====

void FUN_00880cc0(uint param_1,undefined4 *param_2)

{
  uint uVar1;
  int in_ECX;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar1 = param_1 * 2;
  puVar3 = *(undefined4 **)(in_ECX + 0x24);
  for (uVar2 = (param_1 & 0x7fffffff) >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = *param_2;
    param_2 = param_2 + 1;
    puVar3 = puVar3 + 1;
  }
  for (uVar2 = uVar1 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + uVar1;
  *(uint *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x20) + uVar1;
  return;
}


// ==== FUN_00880d00 @ 0x00880d00 ====

uint FUN_00880d00(int param_1)

{
  int *piVar1;
  int in_ECX;
  
  if (param_1 == 0) {
    param_1 = *(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x20);
  }
  piVar1 = *(int **)(in_ECX + 0x18);
  if (*(char *)(in_ECX + 0x28) == '\0') {
    (**(code **)(*piVar1 + 0x2c))
              (piVar1,*(undefined4 *)(in_ECX + 0x20),param_1,in_ECX + 0x24,0x1000);
    return *(uint *)(in_ECX + 0x20) >> 1;
  }
  (**(code **)(*piVar1 + 0x2c))(piVar1,0,param_1,in_ECX + 0x24,0x2000);
  *(undefined1 *)(in_ECX + 0x28) = 0;
  return *(uint *)(in_ECX + 0x20) >> 1;
}


// ==== FUN_00880d60 @ 0x00880d60 ====

void FUN_00880d60(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  piVar1 = *(int **)(in_ECX + 0x18);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x18) = 0;
  }
  return;
}


// ==== FUN_00880d90 @ 0x00880d90 ====

void FUN_00880d90(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  piVar1 = (int *)in_ECX[1];
  *in_ECX = &PTR_FUN_00a148c8;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[1] = 0;
  }
  piVar1 = (int *)in_ECX[6];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[6] = 0;
  }
  FUN_00880fa0();
  return;
}


// ==== FUN_00880dd0 @ 0x00880dd0 ====

void FUN_00880dd0(void)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = (-(uint)(*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xe8) != '\0') & 0xfffffff0) + 0x218;
  piVar1 = (int *)FUN_0049b670();
  (**(code **)(*piVar1 + 0x68))(piVar1,0x80000,iVar2,0,0,in_ECX + 4,0);
  *(undefined4 *)(in_ECX + 8) = 0x80000;
  (**(code **)(*piVar1 + 0x6c))(piVar1,0x20000,iVar2,0x65,0,in_ECX + 0x18,0);
  *(undefined4 *)(in_ECX + 0x1c) = 0x20000;
  return;
}


// ==== FUN_00880e40 @ 0x00880e40 ====

uint FUN_00880e40(uint param_1)

{
  code *pcVar1;
  uint extraout_EAX;
  int in_ECX;
  int iVar2;
  uint uVar3;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  uVar3 = *(uint *)(in_ECX + 0xc) % param_1;
  if (uVar3 == 0) {
    return *(uint *)(in_ECX + 0xc) / param_1;
  }
  iVar2 = param_1 - uVar3;
  uVar3 = FUN_00881000(1,iVar2);
  if ((char)uVar3 != '\0') {
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + iVar2;
    return uVar3;
  }
  FUN_00401830(s_false_00a148a8);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_00880ec0 @ 0x00880ec0 ====

uint FUN_00880ec0(uint param_1,int param_2)

{
  int *piVar1;
  int in_ECX;
  
  FUN_00880e40(param_1);
  if (param_2 == 0) {
    param_2 = *(int *)(in_ECX + 8) - *(int *)(in_ECX + 0xc);
  }
  piVar1 = *(int **)(in_ECX + 4);
  *(int *)(in_ECX + 0x10) = param_2;
  if (*(char *)(in_ECX + 0x29) == '\0') {
    (**(code **)(*piVar1 + 0x2c))(piVar1,*(undefined4 *)(in_ECX + 0xc),param_2,in_ECX + 0x14,0x1000)
    ;
    return *(uint *)(in_ECX + 0xc) / param_1;
  }
  (**(code **)(*piVar1 + 0x2c))(piVar1,0,param_2,in_ECX + 0x14,0x2000);
  *(undefined1 *)(in_ECX + 0x29) = 0;
  return *(uint *)(in_ECX + 0xc) / param_1;
}


// ==== FUN_00880f30 @ 0x00880f30 ====

void FUN_00880f30(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined1 *)(in_ECX + 0x29) = 1;
  return;
}


// ==== FUN_00880f40 @ 0x00880f40 ====

void FUN_00880f40(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined1 *)(in_ECX + 0x28) = 1;
  return;
}


// ==== FUN_00880f50 @ 0x00880f50 ====

void FUN_00880f50(byte param_1)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  piVar1 = (int *)in_ECX[1];
  *in_ECX = &PTR_FUN_00a148c8;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[1] = 0;
  }
  piVar1 = (int *)in_ECX[6];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[6] = 0;
  }
  FUN_00880fa0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00880fa0 @ 0x00880fa0 ====

void FUN_00880fa0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a14930;
  return;
}


// ==== FUN_00880fb0 @ 0x00880fb0 ====

void FUN_00880fb0(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xc))();
                    /* WARNING: Could not recover jumptable at 0x00880fbd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x10))();
  return;
}


// ==== FUN_00880fc0 @ 0x00880fc0 ====

uint FUN_00880fc0(int param_1)

{
  int iVar1;
  int in_ECX;
  
  if (param_1 == 0) {
    param_1 = *(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x20);
  }
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x18) + 0x2c))
                    (*(int **)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0x20),param_1,in_ECX + 0x24,0
                    );
  if (iVar1 < 0) {
    return 0;
  }
  return *(uint *)(in_ECX + 0x20) >> 1;
}


// ==== FUN_00881000 @ 0x00881000 ====

undefined4 FUN_00881000(uint param_1,int param_2)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(uint *)(in_ECX + 0xc);
  if (uVar1 % param_1 != 0) {
    param_2 = (param_1 - uVar1 % param_1) + param_2;
  }
  return CONCAT31((int3)(uVar1 / param_1 >> 8),uVar1 + param_2 < *(uint *)(in_ECX + 8));
}


// ==== FUN_00881030 @ 0x00881030 ====

void FUN_00881030(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a14930;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *(undefined1 *)((int)in_ECX + 0x29) = 0;
  return;
}


// ==== FUN_00881060 @ 0x00881060 ====

void FUN_00881060(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x30))(*(int **)(in_ECX + 4));
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  return;
}


// ==== FUN_00881080 @ 0x00881080 ====

void FUN_00881080(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x18) + 0x30))(*(int **)(in_ECX + 0x18));
  *(undefined4 *)(in_ECX + 0x24) = 0;
  return;
}


// ==== FUN_008810a0 @ 0x008810a0 ====

void FUN_008810a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a14930;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008810c0 @ 0x008810c0 ====

undefined4 FUN_008810c0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1c) == 0) {
    return 0;
  }
  uVar1 = (**(code **)(**(int **)(in_ECX + 0x1c) + 0x11c))(*(int **)(in_ECX + 0x1c));
  return uVar1;
}


// ==== FUN_008810e0 @ 0x008810e0 ====

undefined4 FUN_008810e0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1c) == 0) {
    return 0;
  }
  uVar1 = (**(code **)(**(int **)(in_ECX + 0x1c) + 0x120))(*(int **)(in_ECX + 0x1c));
  return uVar1;
}


// ==== FUN_00881100 @ 0x00881100 ====

void FUN_00881100(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x1c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x1c) = 0;
  }
  piVar1 = *(int **)(in_ECX + 0x20);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x20) = 0;
  }
  return;
}


// ==== FUN_00881130 @ 0x00881130 ====

void FUN_00881130(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x1c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x1c) = 0;
  }
  piVar1 = *(int **)(in_ECX + 0x20);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x20) = 0;
  }
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


// ==== FUN_008811a0 @ 0x008811a0 ====

/* WARNING: Removing unreachable block (ram,0x00881297) */
/* WARNING: Removing unreachable block (ram,0x0088122d) */

void FUN_008811a0(int *param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  code *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  int in_ECX;
  char *pcVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  undefined1 auStack_1a [26];
  
  piVar3 = param_2;
  uVar4 = (**(code **)(*param_2 + 4))();
  FUN_00401660(uVar4,0,0xffffffff);
  puVar14 = &param_2;
  iVar7 = in_ECX + 0x1c;
  uVar13 = 0;
  uVar12 = 0x20;
  uVar11 = 0;
  uVar10 = 0;
  iVar5 = (**(code **)(*piVar3 + 4))(0,0,0x20,0,iVar7,puVar14);
  uVar4 = *(undefined4 *)(iVar5 + 0x24);
  uVar6 = (**(code **)(*piVar3 + 0x34))(uVar4);
  iVar7 = FUN_008a17e4(param_1,uVar6,uVar4,uVar10,uVar11,uVar12,uVar13,iVar7,puVar14);
  if (iVar7 < 0) {
    pcVar8 = (char *)(**(code **)(*param_2 + 0xc))(param_2);
    pcVar9 = pcVar8;
    do {
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(pcVar8,(int)pcVar9 - (int)(pcVar8 + 1));
  }
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
    param_2 = (int *)0x0;
  }
  iVar7 = (**(code **)(*param_1 + 0x158))(param_1,param_3,in_ECX + 0x20);
  if (iVar7 < 0) {
    FUN_00401740(s_SUCCEEDED__hr___00a14990,0xf);
    FUN_00406880(auStack_1a + -0xe);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  return;
}


// ==== FUN_008812b0 @ 0x008812b0 ====

/* WARNING: Removing unreachable block (ram,0x0088130f) */

undefined4 FUN_008812b0(undefined4 param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  int iStack_28;
  uint uStack_8;
  
  if (*(uint *)(param_2 + 0x18) < 0x10) {
    iStack_28 = param_2 + 4;
  }
  else {
    iStack_28 = *(int *)(param_2 + 4);
  }
  iVar3 = (**(code **)(**(int **)(in_ECX + 0x1c) + 0x24))(*(int **)(in_ECX + 0x1c),0);
  if (iVar3 == 0) {
    FUN_00401740(s_hConst____NULL_00a149a0,0xe);
    FUN_00406880(&iStack_28);
    pcVar2 = (code *)swi(3);
    uVar4 = (*pcVar2)();
    return uVar4;
  }
  iVar1 = *(int *)(in_ECX + 0x28);
  if ((iVar1 == 0) || (iVar5 = *(int *)(in_ECX + 0x2c) - iVar1, (uint)(iVar5 >> 2) <= uStack_8)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(int *)(iVar1 + uStack_8 * 4) = iVar3;
  return CONCAT31((int3)(iVar5 >> 10),1);
}


// ==== FUN_00881350 @ 0x00881350 ====

void FUN_00881350(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  FUN_0087e010(0x8d,0);
  return;
}


// ==== FUN_00881390 @ 0x00881390 ====

void FUN_00881390(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a149b8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00881470 @ 0x00881470 ====

void FUN_00881470(uint *param_1,uint *param_2,undefined1 *param_3)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  uint local_4;
  
  uVar1 = *(uint *)(in_ECX + 0x18);
  if ((uVar1 < *param_2) || (*(uint *)(in_ECX + 0x1c) < param_2[1])) {
    uVar2 = *(uint *)(in_ECX + 0x1c);
    *param_3 = 0;
    *param_1 = uVar1;
    param_1[1] = uVar2;
    local_4 = CONCAT31(local_4._1_3_,0x20);
    param_1[2] = local_4;
    return;
  }
  *param_3 = 1;
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  return;
}


// ==== FUN_00881510 @ 0x00881510 ====

undefined4 FUN_00881510(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((((uVar1 & 3) != 0) || (param_1[1] % 3 != 0)) || (uVar1 >> 2 != param_1[1] / 3)) {
    if ((((uVar1 & 0xf) == 0) && (param_1[1] % 9 == 0)) && (uVar1 >> 4 == param_1[1] / 9)) {
      return 0;
    }
    if (((((uVar1 & 0xf) != 0) || (param_1[1] % 10 != 0)) || (uVar1 >> 4 != param_1[1] / 10)) &&
       ((uVar1 != 0x500 || (param_1[1] != 0x400)))) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_008815a0 @ 0x008815a0 ====

uint FUN_008815a0(int *param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 8);
  if (piVar1 != *(int **)(in_ECX + 0xc)) {
    do {
      if (((*param_1 == *piVar1) && (param_1[1] == piVar1[1])) &&
         ((char)param_1[2] == (char)piVar1[2])) {
        return (uint)piVar1 & 0xffffff00;
      }
      piVar1 = piVar1 + 3;
    } while (piVar1 != *(int **)(in_ECX + 0xc));
  }
  return CONCAT31((int3)((uint)piVar1 >> 8),1);
}


// ==== FUN_008815e0 @ 0x008815e0 ====

void FUN_008815e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a149c8;
  DAT_00b5b144 = 0;
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_00a149b8;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00881620 @ 0x00881620 ====

void FUN_00881620(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar6 = *(undefined4 **)(in_ECX + 8);
  if (puVar6 != *(undefined4 **)(in_ECX + 0xc)) {
    do {
      cVar3 = FUN_00881510(puVar6);
      if (cVar3 == '\0') {
        puVar6 = puVar6 + 3;
      }
      else {
        puVar2 = *(undefined4 **)(in_ECX + 0xc);
        puVar4 = puVar6 + 3;
        if (puVar4 != puVar2) {
          puVar5 = puVar6;
          do {
            *puVar5 = *puVar4;
            puVar5[1] = puVar4[1];
            puVar1 = puVar4 + 2;
            puVar4 = puVar4 + 3;
            puVar5[2] = *puVar1;
            puVar5 = puVar5 + 3;
          } while (puVar4 != puVar2);
        }
        *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + -0xc;
      }
    } while (puVar6 != *(undefined4 **)(in_ECX + 0xc));
  }
  return;
}


// ==== FUN_00881690 @ 0x00881690 ====

undefined4 FUN_00881690(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00881c90(in_ECX + 4);
  return param_1;
}


// ==== FUN_00881710 @ 0x00881710 ====

void FUN_00881710(char param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uStack_1c;
  uint uStack_18;
  
  if (param_1 == '\x10') {
    uVar4 = 0x17;
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x14) + 0x18))(*(int **)(in_ECX + 0x14),0,0x17);
    if (iVar2 == 0) {
      uVar4 = 0x18;
    }
  }
  else {
    uVar4 = 0x16;
  }
  uVar3 = (**(code **)(**(int **)(in_ECX + 0x14) + 0x18))(*(int **)(in_ECX + 0x14),0,uVar4);
  if ((uVar3 != 0) && (uVar5 = 0, uVar3 != 0)) {
    do {
      (**(code **)(**(int **)(in_ECX + 0x14) + 0x1c))
                (*(int **)(in_ECX + 0x14),0,uVar4,uVar5,&uStack_1c);
      if ((0x3ff < uStack_1c) &&
         ((0x2ff < uStack_18 &&
          (cVar1 = FUN_008815a0((int)register0x00000010 + -0x28), cVar1 != '\0')))) {
        FUN_00881de0((int)register0x00000010 + -0x28);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar3);
  }
  return;
}


// ==== FUN_008817d0 @ 0x008817d0 ====

void FUN_008817d0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a149c8;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = param_1;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b144 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5b144 = in_ECX;
  }
  (**(code **)(*(int *)in_ECX[5] + 0x20))((int *)in_ECX[5],0,in_ECX + 6);
  FUN_00881710(0x10);
  FUN_00881710(0x20);
  if ((in_ECX[2] != 0) && (0xc < (uint)((int)(in_ECX[3] - in_ECX[2]) / 0xc))) {
    FUN_00881620();
  }
  return;
}


// ==== FUN_00881860 @ 0x00881860 ====

int FUN_00881860(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a680;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0xc) {
    FUN_004e3d80(param_3,param_1);
    param_3 = param_3 + 0xc;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@008818c6 @ 0x008818c6 ====

void Catch_008818c6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008818d0 @ 0x008818d0 ====

void FUN_008818d0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a690;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_004e3d80(param_1,param_3);
    param_1 = param_1 + 0xc;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00881936 @ 0x00881936 ====

void Catch_00881936(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00881940 @ 0x00881940 ====

void FUN_00881940(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00881860(param_1,param_2,param_3);
  return;
}


// ==== FUN_00881960 @ 0x00881960 ====

int FUN_00881960(int param_1,int param_2,undefined4 param_3)

{
  FUN_008818d0(param_1,param_2,param_3);
  return param_1 + param_2 * 0xc;
}


// ==== FUN_00881990 @ 0x00881990 ====

void FUN_00881990(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a149c8;
  DAT_00b5b144 = 0;
  if ((void *)in_ECX[2] != (void *)0x0) {
    _free((void *)in_ECX[2]);
    return;
  }
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  *in_ECX = &PTR_FUN_00a149b8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008819e0 @ 0x008819e0 ====

void FUN_008819e0(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint extraout_ECX;
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
  puStack_c = &LAB_0099a6a0;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x50);
  local_44 = *param_3;
  local_40 = param_3[1];
  local_3c = param_3[2];
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = (*(int *)(in_ECX + 0xc) - iVar3) / 0xc;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x50);
    if (0x15555555U - iVar2 < param_2) {
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
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
    }
    if (local_20 < iVar2 + param_2) {
      if (0x15555555 - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
      }
      if (local_20 < iVar3 + param_2) {
        iVar3 = FUN_004a3750();
        local_20 = iVar3 + param_2;
      }
      local_20 = local_20 * 0xc;
      local_18 = operator_new(local_20);
      local_8 = 0;
      local_1c = FUN_00881940(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_1c = FUN_00881960(local_1c,param_2,&local_44);
      FUN_00881940(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0xc;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)local_18;
        *(void **)(in_ECX + 8) = (void *)((int)local_18 + (param_2 + iVar3) * 0xc);
        *(void **)(in_ECX + 4) = local_18;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_28 = *(int *)(in_ECX + 8);
    if ((uint)((local_28 - param_1) / 0xc) < param_2) {
      local_24 = param_2 * 0xc;
      FUN_00881860(param_1,local_28,local_24 + param_1);
      local_8 = 2;
      FUN_00881960(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0xc,&local_44);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_24;
      FUN_006d89e0(param_1,*(int *)(in_ECX + 8) - local_24,&local_44);
      ExceptionList = local_10;
      return;
    }
    local_2c = local_28 + param_2 * -0xc;
    uVar4 = FUN_00881860(local_2c,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_004ab780(param_1,local_2c,local_28,local_38);
    FUN_006d89e0(param_1,param_2 * 0xc + param_1,&local_44);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00881b88 @ 0x00881b88 ====

void Catch_00881b88(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00881c90 @ 0x00881c90 ====

void FUN_00881c90(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a6b0;
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
      uVar1 = FUN_0085b3b0();
    }
    pvVar2 = operator_new(uVar1 * 0xc);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 0xc + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_00881940(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00881d56 @ 0x00881d56 ====

void Catch_00881d56(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00881d70 @ 0x00881d70 ====

void FUN_00881d70(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0xc != 0) {
      iVar1 = (param_2 - iVar1) / 0xc;
      goto LAB_00881db3;
    }
  }
  iVar1 = 0;
LAB_00881db3:
  FUN_008819e0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0xc;
  return;
}


// ==== FUN_00881de0 @ 0x00881de0 ====

void FUN_00881de0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0xc) <= (uint)((*(int *)(in_ECX + 8) - iVar1) / 0xc)
     )) {
    FUN_00881d70(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_008818d0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0xc;
  return;
}


// ==== FUN_00881e60 @ 0x00881e60 ====

bool FUN_00881e60(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return false;
  }
  piVar1 = (int *)FUN_004af750();
  iVar2 = (**(code **)(*piVar1 + 0x10))();
  return iVar2 == 2;
}


// ==== FUN_00881e80 @ 0x00881e80 ====

bool FUN_00881e80(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return false;
  }
  piVar1 = (int *)FUN_004af750();
  iVar2 = (**(code **)(*piVar1 + 0x10))();
  return iVar2 == 1;
}


// ==== FUN_00881ea0 @ 0x00881ea0 ====

void FUN_00881ea0(undefined4 *param_1,char param_2)

{
  undefined4 uVar1;
  
  uVar1 = DAT_009c3038;
  if (param_2 == '\0') {
    uVar1 = 0;
  }
  param_1[2] = uVar1;
  param_1[1] = uVar1;
  *param_1 = uVar1;
  param_1[3] = DAT_0099d080;
  return;
}


// ==== FUN_00881ee0 @ 0x00881ee0 ====

void FUN_00881ee0(undefined4 *param_1)

{
  int iVar1;
  undefined4 unaff_ESI;
  undefined4 *puVar2;
  undefined4 **ppuVar3;
  undefined4 *puVar4;
  undefined4 *apuStack_26c [4];
  undefined4 uStack_248;
  undefined4 uStack_238;
  undefined4 auStack_22c [3];
  undefined1 auStack_220 [76];
  undefined4 auStack_1d4 [3];
  undefined1 auStack_1c8 [52];
  undefined4 auStack_194 [13];
  undefined4 auStack_160 [3];
  undefined1 auStack_154 [64];
  undefined1 auStack_114 [20];
  undefined1 local_100 [32];
  undefined1 auStack_e0 [32];
  undefined4 local_c0 [14];
  undefined1 auStack_88 [40];
  undefined4 auStack_60 [24];
  
  apuStack_26c[3] = (undefined4 *)param_1[2];
  apuStack_26c[2] = (undefined4 *)param_1[1];
  apuStack_26c[1] = (undefined4 *)*param_1;
  apuStack_26c[0] = local_c0;
  thunk_FUN_0079f7f5();
  apuStack_26c[3] = param_1 + 3;
  apuStack_26c[2] = (undefined4 *)local_100;
  apuStack_26c[1] = (undefined4 *)0x881f19;
  thunk_FUN_0079fb96();
  apuStack_26c[0] = (undefined4 *)param_1[7];
  apuStack_26c[1] = apuStack_26c[0];
  thunk_FUN_0079f761(auStack_88,apuStack_26c[0]);
  apuStack_26c[1] = (undefined4 *)auStack_88;
  apuStack_26c[0] = param_1 + 0x35;
  thunk_FUN_0079ee7b(auStack_1c8);
  puVar2 = auStack_1d4;
  puVar4 = auStack_194;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  thunk_FUN_0079ee7b(auStack_154,auStack_194,auStack_114);
  puVar2 = auStack_160;
  puVar4 = auStack_60;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  thunk_FUN_0079ee7b(auStack_220,auStack_60,auStack_e0);
  puVar2 = auStack_22c;
  ppuVar3 = apuStack_26c;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar3 = (undefined4 *)*puVar2;
    puVar2 = puVar2 + 1;
    ppuVar3 = ppuVar3 + 1;
  }
  param_1[0x28] = apuStack_26c[1];
  param_1[0x29] = unaff_ESI;
  param_1[0x2a] = uStack_248;
  param_1[0x2b] = uStack_238;
  puVar2 = auStack_22c;
  puVar4 = param_1 + 8;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  thunk_FUN_0079f3a1(param_1 + 0x18,0,apuStack_26c);
  return;
}


// ==== FUN_00882040 @ 0x00882040 ====

undefined4 FUN_00882040(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0) {
    return 0;
  }
  uVar1 = FUN_004b3ff0(param_2);
  return uVar1;
}


// ==== FUN_00882060 @ 0x00882060 ====

undefined4 FUN_00882060(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0) {
    return 0;
  }
  uVar1 = FUN_004b4130(param_2);
  return uVar1;
}


// ==== FUN_00882080 @ 0x00882080 ====

undefined4 FUN_00882080(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0) {
    return 0;
  }
  uVar1 = FUN_004b4270(param_2);
  return uVar1;
}


// ==== FUN_008820a0 @ 0x008820a0 ====

void FUN_008820a0(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  float fVar3;
  undefined4 local_2c;
  float local_28;
  float local_24;
  float fStack_20;
  float afStack_1c [3];
  undefined4 uStack_10;
  
  iVar2 = *(int *)(DAT_00b5ac04 + 0x74);
  local_2c = *(undefined4 *)(iVar2 + 0x1c);
  local_28 = *(float *)(iVar2 + 0x20);
  iVar1 = in_ECX + 0x60;
  local_24 = *(float *)(iVar2 + 0x24);
  thunk_FUN_0079e6b3(in_ECX + 0xb0,&local_2c,iVar1);
  if ((*(float *)(in_ECX + 0x1c) == DAT_0099cdc8) || (*(float *)(in_ECX + 0x1c) == DAT_0099d080)) {
    iVar2 = *(int *)(DAT_00b5ac04 + 0x74);
    local_28 = *(float *)(iVar2 + 0x44);
    local_24 = *(float *)(iVar2 + 0x48);
    fStack_20 = *(float *)(iVar2 + 0x4c);
    uStack_10 = *(undefined4 *)(iVar2 + 0x50);
    thunk_FUN_0079e43e(afStack_1c,&local_28,iVar1);
    afStack_1c[0] = DAT_0099d080 / afStack_1c[0];
    *(float *)(in_ECX + 0xbc) = afStack_1c[0] * local_28;
    *(float *)(in_ECX + 0xc0) = afStack_1c[0] * local_24;
    *(float *)(in_ECX + 0xc4) = afStack_1c[0] * fStack_20;
    *(undefined4 *)(in_ECX + 200) = *(undefined4 *)(*(int *)(DAT_00b5ac04 + 0x74) + 0x50);
    return;
  }
  iVar2 = *(int *)(DAT_00b5ac04 + 0x74);
  local_28 = *(float *)(iVar2 + 0x44);
  local_24 = *(float *)(iVar2 + 0x48);
  fStack_20 = *(float *)(iVar2 + 0x4c);
  uStack_10 = *(undefined4 *)(iVar2 + 0x50);
  thunk_FUN_0079e43e(afStack_1c,&local_28,iVar1);
  afStack_1c[0] = DAT_0099d080 / afStack_1c[0];
  fVar3 = DAT_0099d080 / *(float *)(in_ECX + 0x1c);
  *(float *)(in_ECX + 0xbc) = afStack_1c[0] * local_28;
  *(float *)(in_ECX + 0xc0) = afStack_1c[0] * local_24;
  *(float *)(in_ECX + 0xc4) = afStack_1c[0] * fStack_20;
  *(float *)(in_ECX + 200) = fVar3 * *(float *)(*(int *)(DAT_00b5ac04 + 0x74) + 0x50);
  return;
}


// ==== FUN_008822a0 @ 0x008822a0 ====

void FUN_008822a0(void)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iStack_4c;
  undefined1 local_40 [64];
  
  if (*in_ECX == 0) {
    piVar2 = (int *)(in_ECX[0x1d] + 0x20);
    piVar3 = in_ECX + 0xd;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    return;
  }
  iStack_4c = in_ECX[0x1d] + 0x20;
  thunk_FUN_0079ee7b(local_40,*in_ECX);
  piVar2 = &iStack_4c;
  piVar3 = in_ECX + 0xd;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  }
  return;
}


// ==== FUN_008822f0 @ 0x008822f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008822f0(float *param_1,float *param_2,float param_3)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  float fVar4;
  float fVar5;
  
  if (param_3 == 0.0) {
    *param_1 = 0.0;
    param_1[1] = 0.0;
    return;
  }
  iVar1 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  fVar5 = (float)iVar1;
  if (iVar1 < 0) {
    fVar5 = fVar5 + _DAT_0099d104;
  }
  fVar4 = *param_2 * param_3 * fVar5 * DAT_0099d0ec;
  fVar5 = param_2[1] * param_3 * fVar5 * DAT_0099d0ec;
  fVar2 = (float10)FUN_008044f0((double)fVar4);
  fVar3 = (float10)FUN_008044f0((double)fVar5);
  *param_1 = (float)((float10)fVar4 - fVar2);
  param_1[1] = (float)((float10)fVar5 - fVar3);
  return;
}


// ==== FUN_008823b0 @ 0x008823b0 ====

uint FUN_008823b0(uint *param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if (uVar1 < *param_2) {
LAB_008823c1:
    return CONCAT31((int3)(uVar1 >> 8),1);
  }
  if (uVar1 <= *param_2) {
    uVar1 = param_1[1];
    if (uVar1 < param_2[1]) goto LAB_008823c1;
    if (uVar1 <= param_2[1]) {
      return CONCAT31((int3)(param_1[2] >> 8),(int)param_1[2] < (int)param_2[2]);
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_008823f0 @ 0x008823f0 ====

void FUN_008823f0(int param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined1 local_8 [8];
  
  if (param_2[2] != param_1) {
    piVar1 = (int *)FUN_00850950();
    (**(code **)(*piVar1 + 8))(local_8,param_1);
    *param_2 = unaff_EDI;
    param_2[1] = unaff_ESI;
    param_2[2] = param_1;
  }
  return;
}


// ==== FUN_00882440 @ 0x00882440 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00882440(void)

{
  int iVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int in_ECX;
  float10 fVar5;
  
  fVar5 = (float10)(**(code **)(*DAT_00b5af70 + 0x24))(0);
  uVar4 = DAT_009b0318;
  uVar3 = DAT_0099d080;
  iVar1 = (int)ROUND(fVar5);
  if (iVar1 != *(int *)(in_ECX + 0x78)) {
    *(undefined4 *)(in_ECX + 8) = DAT_009b0318;
    *(undefined4 *)(in_ECX + 0xc) = uVar4;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    *(undefined4 *)(in_ECX + 0x14) = uVar3;
    fVar2 = (float)iVar1;
    *(int *)(in_ECX + 0x78) = iVar1;
    *(undefined4 *)(in_ECX + 0x18) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    if (iVar1 < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar2 = fVar2 - DAT_0099d0b4;
    *(float *)(in_ECX + 0x24) = fVar2;
    *(undefined4 *)(in_ECX + 0x28) = uVar4;
    *(undefined4 *)(in_ECX + 0x2c) = 0;
    *(undefined4 *)(in_ECX + 0x30) = uVar3;
    *(undefined4 *)(in_ECX + 0x40) = uVar4;
    *(float *)(in_ECX + 0x44) = fVar2;
    *(undefined4 *)(in_ECX + 0x48) = 0;
    *(undefined4 *)(in_ECX + 0x4c) = uVar3;
    *(float *)(in_ECX + 0x5c) = fVar2;
    *(float *)(in_ECX + 0x60) = fVar2;
    *(undefined4 *)(in_ECX + 100) = 0;
    *(undefined4 *)(in_ECX + 0x34) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x38) = uVar3;
    *(undefined4 *)(in_ECX + 0x3c) = 0;
    *(undefined4 *)(in_ECX + 0x50) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x54) = 0;
    *(undefined4 *)(in_ECX + 0x58) = uVar3;
    *(undefined4 *)(in_ECX + 0x68) = uVar3;
    *(undefined4 *)(in_ECX + 0x6c) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x70) = uVar3;
    *(undefined4 *)(in_ECX + 0x74) = uVar3;
  }
  return;
}


// ==== FUN_008825d0 @ 0x008825d0 ====

int FUN_008825d0(void)

{
  int iVar1;
  int extraout_EAX;
  int *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*in_ECX == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_shmask_dds_00a14a60,10);
    iVar1 = FUN_004b4e70(local_1c);
    *in_ECX = iVar1;
    if (0xf < local_4) {
      _free(local_18);
      return extraout_EAX;
    }
  }
  return *in_ECX;
}


// ==== FUN_00882630 @ 0x00882630 ====

void FUN_00882630(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int in_ECX;
  undefined4 uVar8;
  
  FUN_00882440();
  piVar1 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
  cVar3 = FUN_00881000(0x1c,0x70);
  if (cVar3 == '\0') {
    (**(code **)(*piVar1 + 0xc))();
  }
  (**(code **)(*piVar1 + 0x1c))(0x1c,0x70);
  (**(code **)(*piVar1 + 0x14))(0x70,in_ECX + 8);
  FUN_00881060();
  FUN_00858a60();
  piVar4 = (int *)FUN_0049b670();
  iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
  iVar5 = FUN_008825d0();
  iVar6 = 0;
  if (iVar5 != 0) {
    piVar7 = (int *)FUN_004af750();
    iVar6 = (**(code **)(*piVar7 + 4))();
  }
  if (*(int *)(iVar2 + 0x134) != iVar6) {
    *(int *)(iVar2 + 0x134) = iVar6;
    (**(code **)(**(int **)(iVar2 + 0x90) + 0x104))(*(int **)(iVar2 + 0x90),0,iVar6);
  }
  (**(code **)(*piVar4 + 0x164))(piVar4,0x144);
  piVar7 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  uVar8 = 0x1c;
  (**(code **)(*piVar7 + 400))(piVar7,0,piVar1[1],0,0x1c);
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 0x144))(piVar1,5,uVar8,2);
  (**(code **)(*piVar4 + 0x164))(piVar4,0);
  FUN_00858b90();
  return;
}


// ==== FUN_00882750 @ 0x00882750 ====

void FUN_00882750(int *param_1,int param_2)

{
  if (*(int *)(param_2 + 0xc) != *param_1) {
    FUN_0085e340(0x5b,*param_1);
    *(int *)(param_2 + 0xc) = *param_1;
  }
  return;
}


// ==== FUN_00882780 @ 0x00882780 ====

void FUN_00882780(undefined4 *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 **ppuVar5;
  undefined4 ***pppuVar6;
  undefined4 *puVar7;
  float10 fVar8;
  undefined4 **appuStack_2c0 [5];
  undefined4 *apuStack_2ac [4];
  undefined1 *puStack_29c;
  undefined1 *puStack_298;
  undefined4 *puStack_294;
  undefined1 auStack_26c [12];
  undefined4 auStack_260 [16];
  undefined4 auStack_220 [3];
  undefined1 auStack_214 [64];
  undefined4 auStack_1d4 [3];
  undefined1 auStack_1c8 [52];
  undefined4 auStack_194 [16];
  undefined1 auStack_154 [20];
  undefined1 local_140 [32];
  undefined1 auStack_120 [32];
  undefined1 local_100 [12];
  undefined1 auStack_f4 [8];
  undefined4 auStack_ec [25];
  undefined1 auStack_88 [8];
  undefined4 auStack_80 [32];
  
  puStack_294 = (undefined4 *)param_1[2];
  puStack_29c = (undefined1 *)*param_1;
  puStack_298 = (undefined1 *)param_1[1];
  apuStack_2ac[3] = (undefined4 *)local_100;
  apuStack_2ac[2] = (undefined4 *)0x8827aa;
  thunk_FUN_0079f7f5();
  puStack_294 = param_1 + 3;
  puStack_298 = local_140;
  puStack_29c = (undefined1 *)0x8827bb;
  thunk_FUN_0079fb96();
  apuStack_2ac[2] = (undefined4 *)param_1[7];
  apuStack_2ac[1] = (undefined4 *)auStack_88;
  apuStack_2ac[0] = (undefined4 *)0x8827d2;
  apuStack_2ac[3] = apuStack_2ac[2];
  puStack_29c = (undefined1 *)apuStack_2ac[2];
  thunk_FUN_0079f761();
  puStack_29c = auStack_88;
  apuStack_2ac[3] = param_1 + 0x35;
  apuStack_2ac[2] = (undefined4 *)auStack_1c8;
  apuStack_2ac[1] = (undefined4 *)0x8827ee;
  thunk_FUN_0079ee7b();
  apuStack_2ac[1] = (undefined4 *)auStack_154;
  puVar4 = auStack_1d4;
  puVar7 = auStack_194;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar7 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar7 = puVar7 + 1;
  }
  apuStack_2ac[0] = auStack_194;
  appuStack_2c0[4] = (undefined4 **)auStack_214;
  appuStack_2c0[3] = (undefined4 **)0x882820;
  thunk_FUN_0079ee7b();
  appuStack_2c0[3] = (undefined4 **)auStack_120;
  puVar4 = auStack_220;
  puVar7 = auStack_260;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar7 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar7 = puVar7 + 1;
  }
  appuStack_2c0[2] = (undefined4 **)auStack_260;
  appuStack_2c0[1] = apuStack_2ac + 3;
  appuStack_2c0[0] = (undefined4 **)0x882849;
  thunk_FUN_0079ee7b();
  ppuVar5 = apuStack_2ac;
  puVar4 = auStack_ec;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *ppuVar5;
    ppuVar5 = ppuVar5 + 1;
    puVar4 = puVar4 + 1;
  }
  appuStack_2c0[0] = (undefined4 **)0x0;
  uVar1 = (**(code **)(*DAT_00b5af70 + 0x28))(auStack_26c);
  thunk_FUN_0079ee7b(appuStack_2c0 + 3,auStack_f4,uVar1);
  iVar2 = *(int *)(in_ECX + 4);
  pppuVar6 = appuStack_2c0;
  puVar4 = auStack_80;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *pppuVar6;
    pppuVar6 = pppuVar6 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar3 = *(int *)(iVar2 + 0x28);
  if ((iVar3 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar3 >> 2) < 0x59)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x98))
            (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar3 + 0x160),auStack_80);
  fVar8 = (float10)FUN_0087a480();
  iVar2 = *(int *)(in_ECX + 4);
  iVar3 = *(int *)(iVar2 + 0x28);
  if ((iVar3 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar3 >> 2) < 0x5a)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x78))
            (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar3 + 0x164),(float)fVar8);
  return;
}


// ==== FUN_00882920 @ 0x00882920 ====

void FUN_00882920(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  undefined4 *puVar7;
  undefined1 auStack_86 [58];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puVar7 = *(undefined4 **)(param_1 + 0x5c);
  puVar1 = *(undefined4 **)(param_1 + 0x60);
  iVar6 = 0;
  do {
    if (puVar7 == puVar1) {
      return;
    }
    if ((*(char *)(param_2 + 0xcc) == '\0') && (*(int *)(param_2 + 0xd0) != 0)) {
      iVar4 = (**(code **)(**(int **)(param_2 + 0xd0) + 0xc))(*puVar7);
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar4 == 0) {
        uStack_48 = 0;
        uStack_4c = 0;
        uStack_44 = DAT_0099d080;
        iVar4 = *(int *)(iVar2 + 0x28);
        if ((iVar4 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar4 >> 2) < 0x5b)) {
LAB_00882b67:
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        uVar5 = (**(code **)(**(int **)(iVar2 + 0x1c) + 0x2c))
                          (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar4 + 0x168),iVar6);
        (**(code **)(**(int **)(iVar2 + 0x1c) + 0x98))
                  (*(int **)(iVar2 + 0x1c),uVar5,auStack_86 + -6);
      }
      else {
        iVar3 = *(int *)(iVar2 + 0x28);
        if ((iVar3 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar3 >> 2) < 0x5b)) goto LAB_00882b67;
        uVar5 = (**(code **)(**(int **)(iVar2 + 0x1c) + 0x2c))
                          (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar3 + 0x168),iVar6);
        (**(code **)(**(int **)(iVar2 + 0x1c) + 0x98))(*(int **)(iVar2 + 0x1c),uVar5,iVar4 + 0xe0);
      }
    }
    else {
      iVar2 = *(int *)(in_ECX + 4);
      uStack_8 = 0;
      uStack_c = 0;
      uStack_10 = 0;
      uStack_14 = 0;
      uStack_1c = 0;
      uStack_20 = 0;
      uStack_24 = 0;
      uStack_28 = 0;
      uStack_30 = 0;
      uStack_34 = 0;
      uStack_38 = 0;
      uStack_3c = 0;
      iVar4 = *(int *)(iVar2 + 0x28);
      uStack_40 = DAT_0099d080;
      uStack_2c = DAT_0099d080;
      uStack_18 = DAT_0099d080;
      uStack_4 = DAT_0099d080;
      if ((iVar4 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar4 >> 2) < 0x5b)) goto LAB_00882b67;
      uVar5 = (**(code **)(**(int **)(iVar2 + 0x1c) + 0x2c))
                        (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar4 + 0x168),iVar6);
      (**(code **)(**(int **)(iVar2 + 0x1c) + 0x98))(*(int **)(iVar2 + 0x1c),uVar5,&uStack_4c);
    }
    puVar7 = puVar7 + 1;
    iVar6 = iVar6 + 1;
  } while( true );
}


// ==== FUN_00882b70 @ 0x00882b70 ====

void FUN_00882b70(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 100);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(*(int *)(param_1 + 4) + 0x68) - iVar1 >> 2) <= *(uint *)(param_1 + 8))) {
                    /* WARNING: Subroutine does not return */
    FUN_004bb6a0();
  }
  iVar1 = *(int *)(iVar1 + *(uint *)(param_1 + 8) * 4);
  iVar4 = *(int *)(iVar1 + 0x2c);
  iVar1 = *(int *)(iVar1 + 0x30);
  iVar6 = 0;
  if (iVar4 != iVar1) {
    piVar5 = (int *)(iVar4 + 0x18);
    do {
      piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
      (**(code **)(*piVar2 + 0x148))
                (piVar2,piVar5[-5],param_4,piVar5[-4],piVar5[-3],param_3 + iVar6,piVar5[-2]);
      if (*piVar5 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = piVar5[1] - *piVar5 >> 1;
      }
      iVar4 = iVar4 + 0x24;
      iVar6 = iVar6 + iVar3;
      piVar5 = piVar5 + 9;
    } while (iVar4 != iVar1);
  }
  return;
}


// ==== FUN_00882c10 @ 0x00882c10 ====

void FUN_00882c10(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  int in_ECX;
  undefined4 unaff_EBP;
  undefined4 *puVar13;
  undefined4 uVar14;
  int local_18;
  int iStack_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar3 = (undefined4 *)*puVar2;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  puVar7 = puVar3;
  do {
    if (puVar3 == puVar2) {
      return;
    }
    iVar10 = puVar3[4];
    iVar11 = *(int *)(iVar10 + 100);
    if ((iVar11 == 0) || ((uint)(*(int *)(iVar10 + 0x68) - iVar11 >> 2) <= (uint)puVar3[5])) {
                    /* WARNING: Subroutine does not return */
      FUN_004bb6a0();
    }
    iVar11 = *(int *)(iVar11 + puVar3[5] * 4);
    if (local_8 != iVar10) {
      piVar8 = (int *)FUN_00850950();
      (**(code **)(*piVar8 + 8))(&local_18,iVar10);
      local_10 = local_18;
      local_c = iStack_14;
      local_8 = iVar10;
    }
    if (local_4 != puVar3[3]) {
      iVar10 = *(int *)(in_ECX + 4);
      uVar9 = 0;
      if (puVar3[3] != 0) {
        piVar8 = (int *)FUN_004af750();
        uVar9 = (**(code **)(*piVar8 + 4))();
      }
      iVar4 = *(int *)(iVar10 + 0x28);
      if ((iVar4 == 0) || ((uint)(*(int *)(iVar10 + 0x2c) - iVar4 >> 2) < 0x5c)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      (**(code **)(**(int **)(iVar10 + 0x1c) + 0xd0))
                (*(int **)(iVar10 + 0x1c),*(undefined4 *)(iVar4 + 0x16c),uVar9);
      local_4 = puVar3[3];
    }
    iVar10 = *(int *)(iVar11 + 0x68) + local_10;
    iVar11 = *(int *)(iVar11 + 0x6c) + local_c;
    piVar8 = (int *)puVar3[7];
    piVar5 = (int *)puVar3[8];
    puVar13 = puVar3;
    if (piVar8 != piVar5) {
      do {
        uVar9 = *(undefined4 *)(*piVar8 + 0x74);
        iVar4 = *(int *)(DAT_00b5ac04 + 0x28);
        if (*(char *)(*piVar8 + 8) == '\0') {
          if (*(char *)(iVar4 + 0x7e) == '\0') {
            uVar14 = 2;
            goto LAB_00882d62;
          }
          (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x16,3);
        }
        else {
          uVar14 = 1;
LAB_00882d62:
          (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x16,uVar14);
        }
        *(undefined1 *)(iVar4 + 0x74) = (undefined1)local_8;
        FUN_00882780(uVar9);
        FUN_00882920(unaff_EBP,uVar9);
        piVar6 = *(int **)(*(int *)(in_ECX + 4) + 0x1c);
        (**(code **)(*piVar6 + 0x10c))(piVar6);
        FUN_00882b70(puVar7 + 3,uVar9,iVar11,iVar10);
        piVar8 = piVar8 + 1;
      } while (piVar8 != piVar5);
      puVar13 = puVar7;
    }
    puVar3 = puVar13;
    if (*(char *)((int)puVar13 + 0x29) == '\0') {
      puVar3 = (undefined4 *)puVar13[2];
      if (*(char *)((int)puVar3 + 0x29) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x29);
        puVar13 = (undefined4 *)*puVar3;
        while (puVar7 = puVar3, cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar13 + 0x29);
          puVar3 = puVar13;
          puVar13 = (undefined4 *)*puVar13;
        }
      }
      else {
        puVar3 = (undefined4 *)puVar13[1];
        puVar7 = puVar3;
        if (*(char *)((int)puVar3 + 0x29) == '\0') {
          while ((puVar12 = puVar3, puVar3 = puVar12, puVar7 = puVar12,
                 puVar13 == (undefined4 *)puVar12[2] &&
                 (puVar3 = (undefined4 *)puVar12[1], puVar7 = puVar3,
                 *(char *)((int)puVar3 + 0x29) == '\0'))) {
            puVar13 = puVar12;
          }
        }
      }
    }
  } while( true );
}


// ==== FUN_00882e40 @ 0x00882e40 ====

void FUN_00882e40(void)

{
  int in_ECX;
  
  FUN_00883940(*(undefined4 *)(*(int *)(in_ECX + 0x98) + 4));
  *(int *)(*(int *)(in_ECX + 0x98) + 4) = *(int *)(in_ECX + 0x98);
  *(undefined4 *)(in_ECX + 0x9c) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x98) = *(undefined4 *)(in_ECX + 0x98);
  *(int *)(*(int *)(in_ECX + 0x98) + 8) = *(int *)(in_ECX + 0x98);
  FUN_00883940(*(undefined4 *)(*(int *)(in_ECX + 0xa4) + 4));
  *(int *)(*(int *)(in_ECX + 0xa4) + 4) = *(int *)(in_ECX + 0xa4);
  *(undefined4 *)(in_ECX + 0xa8) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0xa4) = *(undefined4 *)(in_ECX + 0xa4);
  *(int *)(*(int *)(in_ECX + 0xa4) + 8) = *(int *)(in_ECX + 0xa4);
  FUN_00883940(*(undefined4 *)(*(int *)(in_ECX + 0x80) + 4));
  *(int *)(*(int *)(in_ECX + 0x80) + 4) = *(int *)(in_ECX + 0x80);
  *(undefined4 *)(in_ECX + 0x84) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(in_ECX + 0x80);
  *(int *)(*(int *)(in_ECX + 0x80) + 8) = *(int *)(in_ECX + 0x80);
  FUN_00883940(*(undefined4 *)(*(int *)(in_ECX + 0x8c) + 4));
  *(int *)(*(int *)(in_ECX + 0x8c) + 4) = *(int *)(in_ECX + 0x8c);
  *(undefined4 *)(in_ECX + 0x90) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x8c) = *(undefined4 *)(in_ECX + 0x8c);
  *(int *)(*(int *)(in_ECX + 0x8c) + 8) = *(int *)(in_ECX + 0x8c);
  return;
}


// ==== FUN_00882f00 @ 0x00882f00 ====

void FUN_00882f00(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  uint unaff_EBP;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  undefined4 uStack_30;
  undefined4 uStack_20;
  
  if ((((*(int *)(in_ECX + 0x84) == 0) && (*(int *)(in_ECX + 0x90) == 0)) &&
      (*(int *)(in_ECX + 0x9c) == 0)) && (*(int *)(in_ECX + 0xa8) == 0)) {
    FUN_00882630();
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  (**(code **)(*piVar2 + 0x1c))();
  uVar3 = FUN_0085e3a0();
  *(undefined4 *)(in_ECX + 4) = uVar3;
  (**(code **)(**(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90) + 0x15c))();
  piVar2 = (int *)FUN_00850950();
  (**(code **)(*piVar2 + 4))();
  iVar4 = (**(code **)(*DAT_00b5ac00 + 8))();
  piVar2 = *(int **)(*(int *)(in_ECX + 4) + 0x1c);
  if (*(byte *)(iVar4 + 9) < 3) {
    (**(code **)(*piVar2 + 0xf0))();
  }
  else {
    (**(code **)(*piVar2 + 0xf0))();
  }
  iVar4 = *(int *)(in_ECX + 4);
  if ((*(int *)(iVar4 + 0x28) == 0) ||
     ((uint)(*(int *)(iVar4 + 0x2c) - *(int *)(iVar4 + 0x28) >> 2) < 0x5c)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_20 = 0;
  (**(code **)(**(int **)(iVar4 + 0x1c) + 0xd0))();
  FUN_00859b60();
  iVar4 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar4 + 0x112) != '\0') {
    uStack_30 = 7;
    (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90));
    (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0xe,0);
    (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x17,8);
    *(undefined1 *)(iVar4 + 0x112) = 0;
  }
  piVar2 = *(int **)(*(int *)(in_ECX + 4) + 0x1c);
  uStack_30 = 0;
  (**(code **)(*piVar2 + 0x104))(piVar2,&uStack_20);
  uVar5 = 0;
  if (unaff_EBP != 0) {
    uVar6 = 0;
    do {
      if (*(int *)(in_ECX + (uVar6 * 3 + 0x27) * 4) != 0) {
        piVar2 = *(int **)(*(int *)(in_ECX + 4) + 0x1c);
        (**(code **)(*piVar2 + 0x108))(piVar2,uVar6);
        FUN_00882c10(in_ECX + 0x94 + uVar6 * 0xc);
        piVar2 = *(int **)(*(int *)(in_ECX + 4) + 0x1c);
        (**(code **)(*piVar2 + 0x110))(piVar2);
      }
      uVar5 = uVar5 + 1;
      uVar6 = uVar5 & 0xffff;
    } while (uVar6 < unaff_EBP);
  }
  piVar2 = *(int **)(*(int *)(in_ECX + 4) + 0x1c);
  (**(code **)(*piVar2 + 0x114))();
  iVar4 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar4 + 0x112) != '\x01') {
    (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),7,1);
    (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0xe,1);
    (**(code **)(**(int **)(iVar4 + 0x90) + 0xe4))(*(int **)(iVar4 + 0x90),0x17,4);
    *(undefined1 *)(iVar4 + 0x112) = 1;
  }
  piVar7 = *(int **)(*(int *)(in_ECX + 4) + 0x1c);
  (**(code **)(*piVar7 + 0x104))(piVar7,&uStack_30,0);
  uVar5 = 0;
  if (piVar2 != (int *)0x0) {
    piVar7 = (int *)0x0;
    do {
      if (*(int *)(in_ECX + ((int)piVar7 * 3 + 0x21) * 4) != 0) {
        piVar1 = *(int **)(*(int *)(in_ECX + 4) + 0x1c);
        (**(code **)(*piVar1 + 0x108))(piVar1,piVar7);
        FUN_00882c10(in_ECX + 0x7c + (int)piVar7 * 0xc);
        piVar7 = *(int **)(*(int *)(in_ECX + 4) + 0x1c);
        (**(code **)(*piVar7 + 0x110))(piVar7);
      }
      uVar5 = uVar5 + 1;
      piVar7 = (int *)(uVar5 & 0xffff);
    } while (piVar7 < piVar2);
  }
  piVar2 = *(int **)(*(int *)(in_ECX + 4) + 0x1c);
  (**(code **)(*piVar2 + 0x114))(piVar2);
  FUN_00859e10();
  iVar4 = (**(code **)(*DAT_00b5ac00 + 8))();
  if (*(byte *)(iVar4 + 9) < 3) {
    FUN_00882630();
    return;
  }
  FUN_00858b90();
  return;
}


// ==== FUN_008831e0 @ 0x008831e0 ====

void FUN_008831e0(void)

{
  int *in_ECX;
  undefined1 local_4 [4];
  
  if (*in_ECX != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(*in_ECX);
    *in_ECX = 0;
  }
  FUN_008839f0(local_4,*(undefined4 *)in_ECX[0x29],(undefined4 *)in_ECX[0x29]);
  _free((void *)in_ECX[0x29]);
  return;
}


// ==== FUN_00883280 @ 0x00883280 ====

void FUN_00883280(void)

{
  int iVar1;
  undefined4 *in_ECX;
  undefined4 *puVar2;
  int iVar3;
  int local_4;
  
  puVar2 = in_ECX + 0x1f;
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[0x1e] = 0;
  iVar3 = 2;
  do {
    iVar1 = FUN_00883470();
    puVar2[1] = iVar1;
    *(undefined1 *)(iVar1 + 0x29) = 1;
    *(undefined4 *)(puVar2[1] + 4) = puVar2[1];
    *(undefined4 *)puVar2[1] = puVar2[1];
    *(undefined4 *)(puVar2[1] + 8) = puVar2[1];
    puVar2[2] = 0;
    puVar2 = puVar2 + 3;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar2 = in_ECX + 0x25;
  local_4 = 2;
  do {
    iVar3 = FUN_00883470();
    puVar2[1] = iVar3;
    *(undefined1 *)(iVar3 + 0x29) = 1;
    *(undefined4 *)(puVar2[1] + 4) = puVar2[1];
    *(undefined4 *)puVar2[1] = puVar2[1];
    *(undefined4 *)(puVar2[1] + 8) = puVar2[1];
    puVar2[2] = 0;
    puVar2 = puVar2 + 3;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  FUN_00883940(*(undefined4 *)(in_ECX[0x26] + 4));
  *(undefined4 *)(in_ECX[0x26] + 4) = in_ECX[0x26];
  in_ECX[0x27] = 0;
  *(undefined4 *)in_ECX[0x26] = in_ECX[0x26];
  *(undefined4 *)(in_ECX[0x26] + 8) = in_ECX[0x26];
  FUN_00883940(*(undefined4 *)(in_ECX[0x29] + 4));
  *(undefined4 *)(in_ECX[0x29] + 4) = in_ECX[0x29];
  in_ECX[0x2a] = 0;
  *(undefined4 *)in_ECX[0x29] = in_ECX[0x29];
  *(undefined4 *)(in_ECX[0x29] + 8) = in_ECX[0x29];
  FUN_00883940(*(undefined4 *)(in_ECX[0x20] + 4));
  *(undefined4 *)(in_ECX[0x20] + 4) = in_ECX[0x20];
  in_ECX[0x21] = 0;
  *(undefined4 *)in_ECX[0x20] = in_ECX[0x20];
  *(undefined4 *)(in_ECX[0x20] + 8) = in_ECX[0x20];
  FUN_00883940(*(undefined4 *)(in_ECX[0x23] + 4));
  *(undefined4 *)(in_ECX[0x23] + 4) = in_ECX[0x23];
  in_ECX[0x24] = 0;
  *(undefined4 *)in_ECX[0x23] = in_ECX[0x23];
  *(undefined4 *)(in_ECX[0x23] + 8) = in_ECX[0x23];
  return;
}


// ==== FUN_008833c0 @ 0x008833c0 ====

void FUN_008833c0(undefined4 param_1,char param_2,undefined4 param_3,undefined1 param_4)

{
  if (param_2 == '\0') {
    FUN_00883fc0(param_3);
    FUN_0085b670(&param_4);
    return;
  }
  FUN_00883fc0(param_3);
  FUN_0085b670(&param_4);
  return;
}


// ==== FUN_00883420 @ 0x00883420 ====

undefined4 * FUN_00883420(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar2[1] + 0x29) == '\0') {
    puVar1 = puVar2;
    puVar3 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar3;
      if ((uint)puVar2[3] < *param_1) {
LAB_00883452:
        puVar3 = (undefined4 *)puVar2[2];
        puVar2 = puVar1;
      }
      else {
        if ((uint)puVar2[3] <= *param_1) {
          if (((uint)puVar2[4] < param_1[1]) ||
             (((uint)puVar2[4] <= param_1[1] && ((int)puVar2[5] < (int)param_1[2]))))
          goto LAB_00883452;
        }
        puVar3 = (undefined4 *)*puVar2;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar3 + 0x29) == '\0');
  }
  return puVar2;
}


// ==== FUN_00883470 @ 0x00883470 ====

void FUN_00883470(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a6c0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
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
  ExceptionList = local_10;
  return;
}


// ==== Catch@008834fa @ 0x008834fa ====

void Catch_008834fa(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00883510 @ 0x00883510 ====

int FUN_00883510(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a6d0;
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


// ==== Catch@00883576 @ 0x00883576 ====

void Catch_00883576(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00883580 @ 0x00883580 ====

void FUN_00883580(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00883510(param_1,param_2,param_3);
  return;
}


// ==== FUN_008835a0 @ 0x008835a0 ====

void FUN_008835a0(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a6e0;
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
      uVar1 = FUN_0085b3b0();
    }
    pvVar2 = operator_new(uVar1 * 4);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 4 + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_00883580(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00883659 @ 0x00883659 ====

void Catch_00883659(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00883670 @ 0x00883670 ====

/* WARNING: Removing unreachable block (ram,0x00883789) */
/* WARNING: Removing unreachable block (ram,0x0088379a) */
/* WARNING: Removing unreachable block (ram,0x008837a3) */
/* WARNING: Removing unreachable block (ram,0x008837a6) */
/* WARNING: Removing unreachable block (ram,0x00883796) */
/* WARNING: Removing unreachable block (ram,0x008837b4) */
/* WARNING: Removing unreachable block (ram,0x008837c1) */
/* WARNING: Removing unreachable block (ram,0x008837cc) */
/* WARNING: Removing unreachable block (ram,0x008837c8) */
/* WARNING: Removing unreachable block (ram,0x008837bc) */
/* WARNING: Removing unreachable block (ram,0x008837cf) */

void FUN_00883670(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0x29) != '\0') {
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
            goto LAB_008838a4;
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
LAB_008838a4:
            *(undefined1 *)(piVar5 + 10) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 10) = 1;
  }
  if ((void *)param_2[7] == (void *)0x0) {
    param_2[7] = 0;
    param_2[8] = 0;
    param_2[9] = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[7]);
  return;
}


// ==== FUN_00883940 @ 0x00883940 ====

void FUN_00883940(void *param_1)

{
  if (*(char *)((int)param_1 + 0x29) != '\0') {
    return;
  }
  FUN_00883940(*(undefined4 *)((int)param_1 + 8));
  if (*(void **)((int)param_1 + 0x1c) == (void *)0x0) {
    *(undefined4 *)((int)param_1 + 0x1c) = 0;
    *(undefined4 *)((int)param_1 + 0x20) = 0;
    *(undefined4 *)((int)param_1 + 0x24) = 0;
    _free(param_1);
    return;
  }
  _free(*(void **)((int)param_1 + 0x1c));
  return;
}


// ==== FUN_00883990 @ 0x00883990 ====

void FUN_00883990(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_2;
  *in_ECX = param_1;
  in_ECX[2] = param_3;
  in_ECX[3] = *param_4;
  in_ECX[4] = param_4[1];
  in_ECX[5] = param_4[2];
  FUN_008835a0(param_4 + 3);
  *(undefined1 *)(in_ECX + 10) = param_5;
  *(undefined1 *)((int)in_ECX + 0x29) = 0;
  return;
}


// ==== FUN_008839f0 @ 0x008839f0 ====

void FUN_008839f0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00883940(piVar6[1]);
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
    FUN_00883670(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00883ab0 @ 0x00883ab0 ====

void * FUN_00883ab0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a6f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x2c);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00883990(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00883b25 @ 0x00883b25 ====

void Catch_00883b25(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00883b40 @ 0x00883b40 ====

void FUN_00883b40(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0x9249247 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00883ab0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[10] == '\0') {
LAB_00883c45:
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
      if ((char)piVar6[10] == '\0') goto LAB_00883c45;
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


// ==== FUN_00883d20 @ 0x00883d20 ====

void FUN_00883d20(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x29) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      if (*param_2 < (uint)puVar4[3]) {
        bVar5 = true;
      }
      else if ((uint)puVar4[3] < *param_2) {
        bVar5 = false;
      }
      else if (param_2[1] < (uint)puVar4[4]) {
        bVar5 = true;
      }
      else if ((uint)puVar4[4] < param_2[1]) {
        bVar5 = false;
      }
      else {
        bVar5 = (int)param_2[2] < (int)puVar4[5];
      }
      if (bVar5) {
        puVar3 = (undefined4 *)*puVar4;
      }
      else {
        puVar3 = (undefined4 *)puVar4[2];
      }
    } while (*(char *)((int)puVar3 + 0x29) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_00883b40(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_00798b50();
  }
  if (param_2[3] < *puVar2) {
LAB_00883de9:
    puVar4 = (undefined4 *)FUN_00883b40(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  if (param_2[3] <= *puVar2) {
    if ((param_2[4] < puVar2[1]) ||
       ((param_2[4] <= puVar2[1] && ((int)param_2[5] < (int)puVar2[2])))) goto LAB_00883de9;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00883e20 @ 0x00883e20 ====

undefined4 * FUN_00883e20(undefined4 *param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 local_8 [8];
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_00883b40(param_1,1,*(undefined4 *)(in_ECX + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    cVar3 = FUN_008823b0(param_3,param_2 + 3);
    if (cVar3 != '\0') {
      FUN_00883b40(param_1,1,param_2,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    iVar2 = piVar1[2];
    cVar3 = FUN_008823b0(iVar2 + 0xc,param_3);
    if (cVar3 != '\0') {
      FUN_00883b40(param_1,0,iVar2,param_3);
      return param_1;
    }
  }
  else {
    cVar3 = FUN_008823b0(param_3,param_2 + 3);
    if (cVar3 != '\0') {
      FUN_00798b50();
      cVar3 = FUN_008823b0(param_2 + 3,param_3);
      if (cVar3 != '\0') {
        if (*(char *)(param_2[2] + 0x29) == '\0') {
          FUN_00883b40(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_00883b40(param_1,0,param_2,param_3);
        return param_1;
      }
    }
    cVar3 = FUN_008823b0(param_2 + 3,param_3);
    if (cVar3 != '\0') {
      FUN_00798b00();
      if (param_2 != *(int **)(in_ECX + 4)) {
        cVar3 = FUN_008823b0(param_3,param_2 + 3);
        if (cVar3 == '\0') goto LAB_00883f9d;
      }
      if (*(char *)(param_2[2] + 0x29) == '\0') {
        FUN_00883b40(param_1,1,param_2,param_3);
        return param_1;
      }
      FUN_00883b40(param_1,0,param_2,param_3);
      return param_1;
    }
  }
LAB_00883f9d:
  puVar4 = (undefined4 *)FUN_00883d20(local_8,param_3);
  *param_1 = *puVar4;
  return param_1;
}


// ==== FUN_00883fc0 @ 0x00883fc0 ====

int FUN_00883fc0(uint *param_1)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int extraout_EAX;
  int in_ECX;
  undefined1 local_2c [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  void *local_c;
  
  puVar1 = param_1;
  iVar2 = FUN_00883420(param_1);
  if (iVar2 != *(int *)(in_ECX + 4)) {
    if (*(uint *)(iVar2 + 0xc) <= *puVar1) {
      if (*(uint *)(iVar2 + 0xc) < *puVar1) goto LAB_00884057;
      if ((*(uint *)(iVar2 + 0x10) <= puVar1[1]) &&
         ((*(uint *)(iVar2 + 0x10) < puVar1[1] || (*(int *)(iVar2 + 0x14) <= (int)puVar1[2]))))
      goto LAB_00884057;
    }
  }
  local_1c = *puVar1;
  local_18 = puVar1[1];
  local_14 = puVar1[2];
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  FUN_008835a0(local_2c);
  piVar3 = (int *)FUN_00883e20(&param_1,iVar2,&local_1c);
  iVar2 = *piVar3;
  if (local_c != (void *)0x0) {
    _free(local_c);
    return extraout_EAX;
  }
LAB_00884057:
  return iVar2 + 0x18;
}


// ==== FUN_00884070 @ 0x00884070 ====

bool FUN_00884070(uint *param_1,uint *param_2)

{
  if (*param_1 < *param_2) {
    return true;
  }
  if (*param_1 <= *param_2) {
    if (param_1[2] < param_2[2]) {
      return true;
    }
    if (param_1[2] <= param_2[2]) {
      if ((byte)param_1[4] < (byte)param_2[4]) {
        return true;
      }
      if ((byte)param_1[4] <= (byte)param_2[4]) {
        return (int)param_1[3] < (int)param_2[3];
      }
    }
  }
  return false;
}


// ==== FUN_008840c0 @ 0x008840c0 ====

void FUN_008840c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a14afc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008840e0 @ 0x008840e0 ====

void FUN_008840e0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x31) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x31) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x31);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x31);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x31) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x31) == '\0');
    if (*(char *)((int)piVar4 + 0x31) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_00884160 @ 0x00884160 ====

void FUN_00884160(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined1 local_8 [8];
  
  if ((undefined4 *)param_2[2] != param_1) {
    piVar1 = (int *)FUN_00850950();
    (**(code **)(*piVar1 + 8))(local_8,param_1);
    *param_1 = unaff_EDI;
    *param_2 = unaff_ESI;
    param_2[2] = param_1;
  }
  return;
}


// ==== FUN_00884270 @ 0x00884270 ====

void FUN_00884270(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iStack_164;
  undefined4 *puStack_160;
  undefined4 *puStack_15c;
  undefined4 *puStack_158;
  undefined4 *puStack_154;
  undefined4 local_140 [7];
  int aiStack_124 [3];
  undefined1 auStack_118 [12];
  undefined4 auStack_10c [13];
  undefined1 auStack_d8 [24];
  undefined4 local_c0 [16];
  undefined4 local_80 [10];
  undefined1 auStack_58 [24];
  undefined4 local_40 [16];
  
  puVar3 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 200);
  puVar5 = local_80;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar3 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 8);
  puVar5 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar3 = param_1 + 0xd;
  puVar5 = local_c0;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    puStack_154 = (undefined4 *)(param_1[0x1d] + 0x20);
    puVar3 = (undefined4 *)*param_1;
    puVar5 = local_140;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    }
    puStack_158 = local_140;
    puStack_15c = auStack_10c + 3;
    puStack_160 = (undefined4 *)0x8842ea;
    thunk_FUN_0079ee7b();
    puVar3 = auStack_10c + 3;
    puVar5 = local_c0;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  puStack_154 = local_80;
  puStack_158 = local_c0;
  puStack_15c = auStack_10c + 3;
  puStack_160 = (undefined4 *)0x884316;
  thunk_FUN_0079ee7b();
  iVar1 = *(int *)(in_ECX + 0x1c);
  puVar3 = auStack_10c;
  puVar5 = local_140 + -3;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  piVar4 = *(int **)(iVar1 + 0x28);
  if ((piVar4 == (int *)0x0) || (*(int *)(iVar1 + 0x2c) - (int)piVar4 >> 2 == 0)) {
                    /* WARNING: Subroutine does not return */
    puStack_160 = (undefined4 *)0x884345;
    FUN_0085b340();
  }
  iStack_164 = *piVar4;
  puStack_160 = local_140 + -3;
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0x98))(*(int **)(iVar1 + 0x1c));
  thunk_FUN_0079ee7b(auStack_118,auStack_d8,auStack_58);
  iVar1 = *(int *)(in_ECX + 0x1c);
  piVar4 = aiStack_124;
  piVar6 = &iStack_164;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar6 = *piVar4;
    piVar4 = piVar4 + 1;
    piVar6 = piVar6 + 1;
  }
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 4)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0x98))
            (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar2 + 0xc),&iStack_164);
  return;
}


// ==== FUN_008843d0 @ 0x008843d0 ====

void FUN_008843d0(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  undefined4 *puVar7;
  undefined1 auStack_86 [58];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puVar7 = *(undefined4 **)(param_1 + 0x5c);
  puVar1 = *(undefined4 **)(param_1 + 0x60);
  iVar6 = 0;
  do {
    if (puVar7 == puVar1) {
      return;
    }
    if ((*(char *)(param_2 + 0xcc) == '\0') && (*(int *)(param_2 + 0xd0) != 0)) {
      iVar4 = (**(code **)(**(int **)(param_2 + 0xd0) + 0xc))(*puVar7);
      iVar2 = *(int *)(in_ECX + 0x1c);
      if (iVar4 == 0) {
        uStack_48 = 0;
        uStack_4c = 0;
        uStack_44 = DAT_0099d080;
        iVar4 = *(int *)(iVar2 + 0x28);
        if ((iVar4 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar4 >> 2) < 0xc)) {
LAB_0088460e:
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        uVar5 = (**(code **)(**(int **)(iVar2 + 0x1c) + 0x2c))
                          (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar4 + 0x2c),iVar6);
        (**(code **)(**(int **)(iVar2 + 0x1c) + 0x98))
                  (*(int **)(iVar2 + 0x1c),uVar5,auStack_86 + -6);
      }
      else {
        iVar3 = *(int *)(iVar2 + 0x28);
        if ((iVar3 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar3 >> 2) < 0xc)) goto LAB_0088460e;
        uVar5 = (**(code **)(**(int **)(iVar2 + 0x1c) + 0x2c))
                          (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar3 + 0x2c),iVar6);
        (**(code **)(**(int **)(iVar2 + 0x1c) + 0x98))(*(int **)(iVar2 + 0x1c),uVar5,iVar4 + 0xe0);
      }
    }
    else {
      iVar2 = *(int *)(in_ECX + 0x1c);
      uStack_8 = 0;
      uStack_c = 0;
      uStack_10 = 0;
      uStack_14 = 0;
      uStack_1c = 0;
      uStack_20 = 0;
      uStack_24 = 0;
      uStack_28 = 0;
      uStack_30 = 0;
      uStack_34 = 0;
      uStack_38 = 0;
      uStack_3c = 0;
      iVar4 = *(int *)(iVar2 + 0x28);
      uStack_40 = DAT_0099d080;
      uStack_2c = DAT_0099d080;
      uStack_18 = DAT_0099d080;
      uStack_4 = DAT_0099d080;
      if ((iVar4 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar4 >> 2) < 0xc)) goto LAB_0088460e;
      uVar5 = (**(code **)(**(int **)(iVar2 + 0x1c) + 0x2c))
                        (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar4 + 0x2c),iVar6);
      (**(code **)(**(int **)(iVar2 + 0x1c) + 0x98))(*(int **)(iVar2 + 0x1c),uVar5,&uStack_4c);
    }
    puVar7 = puVar7 + 1;
    iVar6 = iVar6 + 1;
  } while( true );
}


// ==== FUN_00884620 @ 0x00884620 ====

void FUN_00884620(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 100);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(*(int *)(param_1 + 8) + 0x68) - iVar1 >> 2) <= *(uint *)(param_1 + 0xc))) {
                    /* WARNING: Subroutine does not return */
    FUN_004bb6a0();
  }
  iVar1 = *(int *)(iVar1 + *(uint *)(param_1 + 0xc) * 4);
  iVar4 = *(int *)(iVar1 + 0x2c);
  iVar1 = *(int *)(iVar1 + 0x30);
  iVar6 = 0;
  if (iVar4 != iVar1) {
    piVar5 = (int *)(iVar4 + 0x18);
    do {
      piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
      (**(code **)(*piVar2 + 0x148))
                (piVar2,piVar5[-5],param_4,piVar5[-4],piVar5[-3],param_3 + iVar6,piVar5[-2]);
      if (*piVar5 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = piVar5[1] - *piVar5 >> 1;
      }
      iVar4 = iVar4 + 0x24;
      iVar6 = iVar6 + iVar3;
      piVar5 = piVar5 + 9;
    } while (iVar4 != iVar1);
  }
  return;
}


// ==== FUN_008846c0 @ 0x008846c0 ====

void FUN_008846c0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int in_ECX;
  undefined1 *puVar8;
  int iVar9;
  float fVar10;
  undefined1 uStack00000000;
  undefined4 uVar11;
  uint uVar12;
  int *piStack_78;
  int *piStack_74;
  int iStack_70;
  int iStack_6c;
  int *piStack_68;
  undefined4 uStack_60;
  int *piStack_5c;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int *piStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_34;
  undefined1 auStack_30 [12];
  float fStack_24;
  undefined1 auStack_20 [28];
  
  if (*(int *)(in_ECX + 0x20) != 0) {
    piVar5 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar6 = (**(code **)(*piVar5 + 0x1c))();
    if (*(int *)(iVar6 + 8) == 0) {
      uVar11 = 0x11;
    }
    else {
      uVar11 = 1;
    }
    uVar11 = FUN_0085e3a0(uVar11);
    *(undefined4 *)(in_ECX + 0x1c) = uVar11;
    piStack_74 = (int *)((uint)piStack_74 & 0xffffff);
    piVar5 = (int *)FUN_00850950();
    (**(code **)(*piVar5 + 4))();
    piVar5 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar5 + 0x15c))(piVar5,*(undefined4 *)(*(int *)(in_ECX + 0x1c) + 0x20));
    iVar6 = *(int *)(in_ECX + 0x1c);
    iVar9 = *(int *)(iVar6 + 0x28);
    if ((iVar9 == 0) || ((uint)(*(int *)(iVar6 + 0x2c) - iVar9 >> 2) < 0x1c)) {
LAB_00884762:
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(iVar6 + 0x1c) + 0xd0))
              (*(int **)(iVar6 + 0x1c),*(undefined4 *)(iVar9 + 0x6c),0);
    piVar5 = *(int **)(*(int *)(in_ECX + 0x1c) + 0x1c);
    piStack_48 = (int *)0x0;
    iStack_40 = 0;
    cVar4 = '\0';
    (**(code **)(*piVar5 + 0xf0))(piVar5,s_EdgeBone_00a14ad8);
    FUN_00859a20();
    piVar5 = *(int **)(*(int *)(in_ECX + 0x1c) + 0x1c);
    (**(code **)(*piVar5 + 0x104))(piVar5,&piStack_74,0);
    uVar12 = 0;
    if (&uStack00000000 != (undefined1 *)0x4) {
      puVar8 = (undefined1 *)0x0;
      do {
        if (*(int *)(in_ECX + 0xc + (int)puVar8 * 0xc) != 0) {
          piVar5 = *(int **)(*(int *)(in_ECX + 0x1c) + 0x1c);
          (**(code **)(*piVar5 + 0x108))(piVar5,puVar8);
          piStack_48 = *(int **)(in_ECX + (int)puVar8 * 0xc + 8);
          piVar5 = (int *)*piStack_48;
          piStack_78 = piVar5;
          if (piVar5 != piStack_48) {
LAB_00884805:
            iVar6 = piVar5[5];
            iVar9 = *(int *)(iVar6 + 100);
            if ((iVar9 == 0) || ((uint)(*(int *)(iVar6 + 0x68) - iVar9 >> 2) <= (uint)piVar5[6])) {
                    /* WARNING: Subroutine does not return */
              FUN_004bb6a0();
            }
            iVar9 = *(int *)(iVar9 + piVar5[6] * 4);
            iStack_54 = iVar9;
            if (iStack_34 != iVar6) {
              piVar7 = (int *)FUN_00850950();
              (**(code **)(*piVar7 + 8))(&iStack_44,iVar6);
              iStack_70 = iStack_44;
              iStack_6c = iStack_40;
              iStack_34 = iVar6;
            }
            iStack_50 = *(int *)(iVar9 + 0x68) + iStack_70;
            piStack_74 = (int *)piVar5[9];
            piStack_68 = (int *)piVar5[10];
            iStack_4c = *(int *)(iVar9 + 0x6c) + iStack_6c;
            if (*(byte *)(piVar5 + 7) < 10) {
              if (piVar5[4] == 0) goto LAB_00884d49;
              if (iStack_3c == piVar5[4]) goto LAB_00884940;
              iVar6 = *(int *)(in_ECX + 0x1c);
              piVar7 = (int *)FUN_004af750();
              uVar11 = (**(code **)(*piVar7 + 4))();
              iVar9 = *(int *)(iVar6 + 0x28);
              if ((iVar9 == 0) || ((uint)(*(int *)(iVar6 + 0x2c) - iVar9 >> 2) < 0x19))
              goto LAB_00884762;
              (**(code **)(**(int **)(iVar6 + 0x1c) + 0xd0))
                        (*(int **)(iVar6 + 0x1c),*(undefined4 *)(iVar9 + 0x60),uVar11);
              iStack_3c = piVar5[4];
            }
            else if (iStack_3c != piVar5[3]) {
              iVar6 = *(int *)(in_ECX + 0x1c);
              uVar11 = 0;
              if (piVar5[3] != 0) {
                piVar7 = (int *)FUN_004af750();
                uVar11 = (**(code **)(*piVar7 + 4))();
              }
              iVar9 = *(int *)(iVar6 + 0x28);
              if ((iVar9 == 0) || ((uint)(*(int *)(iVar6 + 0x2c) - iVar9 >> 2) < 0x19))
              goto LAB_00884762;
              (**(code **)(**(int **)(iVar6 + 0x1c) + 0xd0))
                        (*(int **)(iVar6 + 0x1c),*(undefined4 *)(iVar9 + 0x60),uVar11);
              iStack_3c = piVar5[3];
            }
LAB_00884940:
            if ((char)piVar5[7] != cVar4) {
              iVar6 = *piStack_74;
              if (iStack_3c != *(int *)(iVar6 + 0x1c)) {
                iVar9 = *(int *)(in_ECX + 0x1c);
                uVar11 = 0;
                if (*(int *)(iVar6 + 0x1c) != 0) {
                  piVar5 = (int *)FUN_004af750();
                  uVar11 = (**(code **)(*piVar5 + 4))();
                }
                iVar2 = *(int *)(iVar9 + 0x28);
                if ((iVar2 == 0) || ((uint)(*(int *)(iVar9 + 0x2c) - iVar2 >> 2) < 0x1c))
                goto LAB_00884762;
                (**(code **)(**(int **)(iVar9 + 0x1c) + 0xd0))
                          (*(int **)(iVar9 + 0x1c),*(undefined4 *)(iVar2 + 0x6c),uVar11);
                iStack_3c = *(int *)(iVar6 + 0x1c);
              }
              if (*(char *)(iVar6 + 4) == '\0') {
                piVar5 = (int *)FUN_0049b670();
                (**(code **)(*piVar5 + 0xe4))(piVar5,0x16,3);
              }
              else {
                piVar5 = (int *)FUN_0049b670();
                (**(code **)(*piVar5 + 0xe4))(piVar5,0x16,2);
              }
              if (*(int *)(iVar6 + 8) == 1) {
                iVar9 = *(int *)(DAT_00b5ac04 + 0x28);
                if ((((*(int *)(iVar9 + 0x114) != 2) || (*(int *)(iVar9 + 0x118) != 5)) ||
                    (*(int *)(iVar9 + 0x11c) != 6)) && (*(int *)(iVar9 + 100) == 0)) {
                  (**(code **)(**(int **)(iVar9 + 0x90) + 0xe4))(*(int **)(iVar9 + 0x90),0x1b,1);
                  (**(code **)(**(int **)(iVar9 + 0x90) + 0xe4))(*(int **)(iVar9 + 0x90),0xf,1);
                  (**(code **)(**(int **)(iVar9 + 0x90) + 0xe4))(*(int **)(iVar9 + 0x90),0x19,5);
                  (**(code **)(**(int **)(iVar9 + 0x90) + 0xe4))(*(int **)(iVar9 + 0x90),0x18,1);
                  (**(code **)(**(int **)(iVar9 + 0x90) + 0xe4))(*(int **)(iVar9 + 0x90),0x13,5);
                  (**(code **)(**(int **)(iVar9 + 0x90) + 0xe4))(*(int **)(iVar9 + 0x90),0x14,6);
                  *(undefined4 *)(iVar9 + 0x11c) = 6;
                  goto LAB_00884b48;
                }
              }
              else {
                iVar9 = *(int *)(DAT_00b5ac04 + 0x28);
                if ((((*(int *)(iVar9 + 0x114) != 2) || (*(int *)(iVar9 + 0x118) != 5)) ||
                    (*(int *)(iVar9 + 0x11c) != 2)) && (*(int *)(iVar9 + 100) == 0)) {
                  (**(code **)(**(int **)(iVar9 + 0x90) + 0xe4))(*(int **)(iVar9 + 0x90),0x1b,1);
                  (**(code **)(**(int **)(iVar9 + 0x90) + 0xe4))(*(int **)(iVar9 + 0x90),0xf,1);
                  (**(code **)(**(int **)(iVar9 + 0x90) + 0xe4))(*(int **)(iVar9 + 0x90),0x19,5);
                  (**(code **)(**(int **)(iVar9 + 0x90) + 0xe4))(*(int **)(iVar9 + 0x90),0x18,1);
                  (**(code **)(**(int **)(iVar9 + 0x90) + 0xe4))(*(int **)(iVar9 + 0x90),0x13,5);
                  (**(code **)(**(int **)(iVar9 + 0x90) + 0xe4))(*(int **)(iVar9 + 0x90),0x14,2);
                  *(undefined4 *)(iVar9 + 0x11c) = 2;
LAB_00884b48:
                  *(undefined4 *)(iVar9 + 0x114) = 2;
                  *(undefined4 *)(iVar9 + 0x118) = 5;
                }
              }
              iVar9 = *(int *)(in_ECX + 0x1c);
              iVar2 = *(int *)(iVar9 + 0x28);
              if ((iVar2 == 0) || ((uint)(*(int *)(iVar9 + 0x2c) - iVar2 >> 2) < 0xf))
              goto LAB_00884762;
              (**(code **)(**(int **)(iVar9 + 0x1c) + 0x80))
                        (*(int **)(iVar9 + 0x1c),*(undefined4 *)(iVar2 + 0x38),iVar6 + 0x14,2);
              cVar4 = (char)piStack_78[7];
              piVar5 = piStack_78;
            }
            if (piStack_74 != piStack_68) {
              do {
                piVar5 = (int *)*piStack_74;
                iVar6 = *piVar5;
                iVar9 = *(int *)(iVar6 + 0x74);
                piStack_5c = piVar5;
                if (*(char *)(iVar6 + 10) == '\0') {
                  FUN_0040ec60(auStack_20,piVar5[3]);
                  iVar2 = *(int *)(in_ECX + 0x1c);
                  iVar3 = *(int *)(iVar2 + 0x28);
                  if ((iVar3 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar3 >> 2) < 0xd))
                  goto LAB_00884762;
                  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x88))
                            (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar3 + 0x30),auStack_20);
                  piVar5 = piStack_5c;
                }
                else {
                  FUN_0040ec60(auStack_30,*(undefined4 *)(iVar6 + 4));
                  fVar10 = (float)*(byte *)(iVar6 + 0xc) * DAT_0099d0b0;
                  if (fStack_24 <= fVar10) {
                    fVar10 = fStack_24;
                  }
                  iVar2 = *(int *)(*(int *)(in_ECX + 0x1c) + 0x28);
                  fStack_24 = fVar10;
                  if ((iVar2 == 0) ||
                     ((uint)(*(int *)(*(int *)(in_ECX + 0x1c) + 0x2c) - iVar2 >> 2) < 0xd))
                  goto LAB_00884762;
                  piStack_5c = *(int **)(*(int *)(in_ECX + 0x1c) + 0x1c);
                  (**(code **)(*piStack_5c + 0x88))
                            (piStack_5c,*(undefined4 *)(iVar2 + 0x30),auStack_30);
                }
                iVar2 = *(int *)(in_ECX + 0x1c);
                iVar3 = *(int *)(iVar2 + 0x28);
                iStack_58 = piVar5[4];
                if ((iVar3 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar3 >> 2) < 0x14))
                goto LAB_00884762;
                (**(code **)(**(int **)(iVar2 + 0x1c) + 0x78))
                          (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar3 + 0x4c),iStack_58);
                FUN_0087a760(*(undefined4 *)(in_ECX + 0x1c),iVar9 + 0xb0,iVar9 + 0xbc,
                             *(undefined4 *)(iVar9 + 200));
                FUN_00884270(iVar6);
                FUN_008843d0(uStack_60,iVar9);
                piVar5 = *(int **)(*(int *)(in_ECX + 0x1c) + 0x1c);
                (**(code **)(*piVar5 + 0x10c))(piVar5);
                FUN_00884620(piStack_78 + 3,iVar9,iStack_4c,iStack_50);
                piStack_74 = piStack_74 + 1;
              } while (piStack_74 != piStack_68);
              piVar5 = piStack_78;
            }
LAB_00884d49:
            if (*(char *)((int)piVar5 + 0x31) == '\0') {
              piStack_78 = (int *)piVar5[2];
              if (*(char *)((int)piStack_78 + 0x31) == '\0') {
                cVar1 = *(char *)(*piStack_78 + 0x31);
                piVar5 = (int *)*piStack_78;
                while (cVar1 == '\0') {
                  cVar1 = *(char *)(*piVar5 + 0x31);
                  piStack_78 = piVar5;
                  piVar5 = (int *)*piVar5;
                }
              }
              else {
                piStack_78 = (int *)piVar5[1];
                if (*(char *)((int)piStack_78 + 0x31) == '\0') {
                  while( true ) {
                    piVar7 = piStack_78;
                    piStack_78 = piVar7;
                    if ((piVar5 != (int *)piVar7[2]) ||
                       (piStack_78 = (int *)piVar7[1], *(char *)((int)piStack_78 + 0x31) != '\0'))
                    break;
                    piVar5 = piVar7;
                  }
                }
              }
              piVar5 = piStack_78;
            }
            if (piVar5 == piStack_48) goto LAB_00884da6;
            goto LAB_00884805;
          }
LAB_00884da6:
          piVar5 = *(int **)(*(int *)(in_ECX + 0x1c) + 0x1c);
          (**(code **)(*piVar5 + 0x110))(piVar5);
        }
        uVar12 = uVar12 + 1;
        puVar8 = (undefined1 *)(uVar12 & 0xffff);
      } while (puVar8 < auStack_20 + 0x1c);
    }
    piVar5 = *(int **)(*(int *)(in_ECX + 0x1c) + 0x1c);
    (**(code **)(*piVar5 + 0x114))(piVar5);
    FUN_00859b20();
  }
  return;
}


// ==== FUN_00884e00 @ 0x00884e00 ====

void FUN_00884e00(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(in_ECX + 8);
  iVar3 = 2;
  do {
    FUN_00885530(*(undefined4 *)(*piVar2 + 4));
    *(int *)(*piVar2 + 4) = *piVar2;
    piVar2[1] = 0;
    *(int *)*piVar2 = *piVar2;
    iVar1 = *piVar2;
    piVar2 = piVar2 + 3;
    iVar3 = iVar3 + -1;
    *(int *)(iVar1 + 8) = iVar1;
  } while (iVar3 != 0);
  *(undefined4 *)(in_ECX + 0x20) = 0;
  return;
}


// ==== FUN_00884e50 @ 0x00884e50 ====

void FUN_00884e50(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_00a14b18;
  FUN_008855e0(local_4,*(undefined4 *)in_ECX[5],(undefined4 *)in_ECX[5]);
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_00884eb0 @ 0x00884eb0 ====

void FUN_00884eb0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  undefined4 *puVar2;
  int iVar3;
  
  *in_ECX = &PTR_FUN_00a14b18;
  puVar2 = in_ECX + 1;
  iVar3 = 2;
  do {
    iVar1 = FUN_00885060();
    puVar2[1] = iVar1;
    *(undefined1 *)(iVar1 + 0x31) = 1;
    *(undefined4 *)(puVar2[1] + 4) = puVar2[1];
    *(undefined4 *)puVar2[1] = puVar2[1];
    *(undefined4 *)(puVar2[1] + 8) = puVar2[1];
    puVar2[2] = 0;
    puVar2 = puVar2 + 3;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  return;
}


// ==== FUN_00884f10 @ 0x00884f10 ====

undefined4 FUN_00884f10(void)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x24);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_00884eb0();
  return uVar2;
}


// ==== FUN_00884f30 @ 0x00884f30 ====

void FUN_00884f30(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  
  iVar3 = FUN_00885bc0(param_2);
  iVar1 = *(int *)(iVar3 + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(iVar3 + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(iVar3 + 8) - iVar1 >> 2))) {
    FUN_0085b420(*(undefined4 *)(iVar3 + 8),1,&param_3);
    *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x20) + 1;
    return;
  }
  puVar2 = *(undefined4 **)(iVar3 + 8);
  *puVar2 = param_3;
  *(undefined4 **)(iVar3 + 8) = puVar2 + 1;
  *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x20) + 1;
  return;
}


// ==== FUN_00884fb0 @ 0x00884fb0 ====

void FUN_00884fb0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x31) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x31) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x31);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x31);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x31);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x31);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_00885000 @ 0x00885000 ====

undefined4 * FUN_00885000(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar2[1] + 0x31) == '\0') {
    puVar1 = puVar2;
    puVar3 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar3;
      if ((uint)puVar2[3] < *param_1) {
LAB_0088503f:
        puVar3 = (undefined4 *)puVar2[2];
        puVar2 = puVar1;
      }
      else {
        if ((uint)puVar2[3] <= *param_1) {
          if ((uint)puVar2[5] < param_1[2]) goto LAB_0088503f;
          if ((uint)puVar2[5] <= param_1[2]) {
            if ((*(byte *)(puVar2 + 7) < (byte)param_1[4]) ||
               ((*(byte *)(puVar2 + 7) <= (byte)param_1[4] && ((int)puVar2[6] < (int)param_1[3]))))
            goto LAB_0088503f;
          }
        }
        puVar3 = (undefined4 *)*puVar2;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar3 + 0x31) == '\0');
  }
  return puVar2;
}


// ==== FUN_00885060 @ 0x00885060 ====

void FUN_00885060(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a700;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x34);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0xc) = 1;
  *(undefined1 *)((int)puVar1 + 0x31) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@008850ea @ 0x008850ea ====

void Catch_008850ea(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00885100 @ 0x00885100 ====

int FUN_00885100(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a710;
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


// ==== Catch@00885166 @ 0x00885166 ====

void Catch_00885166(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00885170 @ 0x00885170 ====

void FUN_00885170(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00885100(param_1,param_2,param_3);
  return;
}


// ==== FUN_00885190 @ 0x00885190 ====

void FUN_00885190(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a720;
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
      uVar1 = FUN_0085b3b0();
    }
    pvVar2 = operator_new(uVar1 * 4);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 4 + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_00885170(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00885249 @ 0x00885249 ====

void Catch_00885249(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00885260 @ 0x00885260 ====

/* WARNING: Removing unreachable block (ram,0x00885379) */
/* WARNING: Removing unreachable block (ram,0x0088538a) */
/* WARNING: Removing unreachable block (ram,0x00885393) */
/* WARNING: Removing unreachable block (ram,0x00885396) */
/* WARNING: Removing unreachable block (ram,0x00885386) */
/* WARNING: Removing unreachable block (ram,0x008853a4) */
/* WARNING: Removing unreachable block (ram,0x008853b1) */
/* WARNING: Removing unreachable block (ram,0x008853bc) */
/* WARNING: Removing unreachable block (ram,0x008853b8) */
/* WARNING: Removing unreachable block (ram,0x008853ac) */
/* WARNING: Removing unreachable block (ram,0x008853bf) */

void FUN_00885260(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0x31) != '\0') {
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
  FUN_00884fb0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x31) == '\0') {
    if (*(char *)(param_2[2] + 0x31) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x31) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x31) == '\0') {
      piVar3 = (int *)FUN_00446e00(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x31) == '\0') {
      uVar4 = FUN_0049ff70(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0xc] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0xc] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0xc] == '\0') {
            *(undefined1 *)(piVar5 + 0xc) = 1;
            *(undefined1 *)(piVar3 + 0xc) = 0;
            FUN_00821aa0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x31) == '\0') {
            if ((*(char *)(*piVar5 + 0x30) == '\x01') && (*(char *)(piVar5[2] + 0x30) == '\x01'))
            goto LAB_00885494;
            if (*(char *)(piVar5[2] + 0x30) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x30) = 1;
              *(undefined1 *)(piVar5 + 0xc) = 0;
              FUN_0049ff90(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0xc) = (char)piVar3[0xc];
            *(undefined1 *)(piVar3 + 0xc) = 1;
            *(undefined1 *)(piVar5[2] + 0x30) = 1;
            FUN_00821aa0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0xc] == '\0') {
            *(undefined1 *)(piVar5 + 0xc) = 1;
            *(undefined1 *)(piVar3 + 0xc) = 0;
            FUN_0049ff90(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x31) == '\0') {
            if ((*(char *)(piVar5[2] + 0x30) != '\x01') || (*(char *)(*piVar5 + 0x30) != '\x01')) {
              if (*(char *)(*piVar5 + 0x30) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x30) = 1;
                *(undefined1 *)(piVar5 + 0xc) = 0;
                FUN_00821aa0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0xc) = (char)piVar3[0xc];
              *(undefined1 *)(piVar3 + 0xc) = 1;
              *(undefined1 *)(*piVar5 + 0x30) = 1;
              FUN_0049ff90(piVar3);
              break;
            }
LAB_00885494:
            *(undefined1 *)(piVar5 + 0xc) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xc) = 1;
  }
  if ((void *)param_2[9] == (void *)0x0) {
    param_2[9] = 0;
    param_2[10] = 0;
    param_2[0xb] = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[9]);
  return;
}


// ==== FUN_00885530 @ 0x00885530 ====

void FUN_00885530(void *param_1)

{
  if (*(char *)((int)param_1 + 0x31) != '\0') {
    return;
  }
  FUN_00885530(*(undefined4 *)((int)param_1 + 8));
  if (*(void **)((int)param_1 + 0x24) == (void *)0x0) {
    *(undefined4 *)((int)param_1 + 0x24) = 0;
    *(undefined4 *)((int)param_1 + 0x28) = 0;
    *(undefined4 *)((int)param_1 + 0x2c) = 0;
    _free(param_1);
    return;
  }
  _free(*(void **)((int)param_1 + 0x24));
  return;
}


// ==== FUN_00885580 @ 0x00885580 ====

void FUN_00885580(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_2;
  *in_ECX = param_1;
  in_ECX[2] = param_3;
  in_ECX[3] = *param_4;
  in_ECX[4] = param_4[1];
  in_ECX[5] = param_4[2];
  in_ECX[6] = param_4[3];
  in_ECX[7] = param_4[4];
  FUN_00885190(param_4 + 5);
  *(undefined1 *)(in_ECX + 0xc) = param_5;
  *(undefined1 *)((int)in_ECX + 0x31) = 0;
  return;
}


// ==== FUN_008855e0 @ 0x008855e0 ====

void FUN_008855e0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00885530(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x31) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x31) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x31);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x31);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x31);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x31);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00885260(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_008856a0 @ 0x008856a0 ====

void * FUN_008856a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a730;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x34);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00885580(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00885715 @ 0x00885715 ====

void Catch_00885715(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00885730 @ 0x00885730 ====

void FUN_00885730(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0x71c71c5 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_008856a0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x30);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x30) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0xc] == '\0') {
LAB_00885835:
        *(undefined1 *)(*piVar5 + 0x30) = 1;
        *(undefined1 *)(piVar6 + 0xc) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x30) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_00821aa0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x30) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x30) = 0;
        FUN_0049ff90(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0xc] == '\0') goto LAB_00885835;
      if (piVar7 == (int *)*piVar2) {
        FUN_0049ff90(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x30) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x30) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x31) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x30);
  } while( true );
}


// ==== FUN_00885910 @ 0x00885910 ====

void FUN_00885910(undefined4 *param_1,uint *param_2)

{
  uint *puVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  bool bVar5;
  int in_ECX;
  
  puVar1 = param_2;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  bVar5 = true;
  if (*(char *)((int)puVar4[1] + 0x31) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      if (*param_2 < (uint)puVar4[3]) {
LAB_0088595c:
        puVar3 = (undefined4 *)*puVar4;
        bVar5 = true;
      }
      else {
        if (*param_2 <= (uint)puVar4[3]) {
          if (param_2[2] < (uint)puVar4[5]) goto LAB_0088595c;
          if (param_2[2] <= (uint)puVar4[5]) {
            if (((byte)param_2[4] < *(byte *)(puVar4 + 7)) ||
               (((byte)param_2[4] <= *(byte *)(puVar4 + 7) && ((int)param_2[3] < (int)puVar4[6]))))
            goto LAB_0088595c;
          }
        }
        puVar3 = (undefined4 *)puVar4[2];
        bVar5 = false;
      }
    } while (*(char *)((int)puVar3 + 0x31) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_00885730(&param_2,1,puVar4,puVar1);
      *param_1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_008840e0();
  }
  puVar3 = param_2;
  cVar2 = FUN_00884070(param_2 + 3,puVar1);
  if (cVar2 == '\0') {
    *param_1 = puVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
  puVar4 = (undefined4 *)FUN_00885730(&param_2,bVar5,puVar4,puVar1);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_00885a00 @ 0x00885a00 ====

undefined4 * FUN_00885a00(undefined4 *param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 local_8 [8];
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_00885730(param_1,1,*(undefined4 *)(in_ECX + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    cVar3 = FUN_00884070(param_3,param_2 + 3);
    if (cVar3 != '\0') {
      FUN_00885730(param_1,1,param_2,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    iVar2 = piVar1[2];
    cVar3 = FUN_00884070(iVar2 + 0xc,param_3);
    if (cVar3 != '\0') {
      FUN_00885730(param_1,0,iVar2,param_3);
      return param_1;
    }
  }
  else {
    cVar3 = FUN_00884070(param_3,param_2 + 3);
    if (cVar3 != '\0') {
      FUN_008840e0();
      cVar3 = FUN_00884070(param_2 + 3,param_3);
      if (cVar3 != '\0') {
        if (*(char *)(param_2[2] + 0x31) == '\0') {
          FUN_00885730(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_00885730(param_1,0,param_2,param_3);
        return param_1;
      }
    }
    cVar3 = FUN_00884070(param_2 + 3,param_3);
    if (cVar3 != '\0') {
      FUN_00884fb0();
      if (param_2 != *(int **)(in_ECX + 4)) {
        cVar3 = FUN_00884070(param_3,param_2 + 3);
        if (cVar3 == '\0') goto LAB_00885b7d;
      }
      if (*(char *)(param_2[2] + 0x31) == '\0') {
        FUN_00885730(param_1,1,param_2,param_3);
        return param_1;
      }
      FUN_00885730(param_1,0,param_2,param_3);
      return param_1;
    }
  }
LAB_00885b7d:
  puVar4 = (undefined4 *)FUN_00885910(local_8,param_3);
  *param_1 = *puVar4;
  return param_1;
}


// ==== FUN_00885ba0 @ 0x00885ba0 ====

void FUN_00885ba0(byte param_1)

{
  void *in_ECX;
  
  FUN_00884e50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00885bc0 @ 0x00885bc0 ====

int FUN_00885bc0(uint *param_1)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int extraout_EAX;
  int in_ECX;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  void *local_c;
  
  puVar1 = param_1;
  iVar2 = FUN_00885000(param_1);
  if (iVar2 != *(int *)(in_ECX + 4)) {
    if (*(uint *)(iVar2 + 0xc) <= *puVar1) {
      if (*(uint *)(iVar2 + 0xc) < *puVar1) goto LAB_00885c79;
      if (*(uint *)(iVar2 + 0x14) <= puVar1[2]) {
        if (*(uint *)(iVar2 + 0x14) < puVar1[2]) goto LAB_00885c79;
        if ((*(byte *)(iVar2 + 0x1c) <= (byte)puVar1[4]) &&
           ((*(byte *)(iVar2 + 0x1c) < (byte)puVar1[4] || (*(int *)(iVar2 + 0x18) <= (int)puVar1[3])
            ))) goto LAB_00885c79;
      }
    }
  }
  local_24 = *puVar1;
  local_1c = puVar1[2];
  local_20 = puVar1[1];
  local_18 = puVar1[3];
  local_14 = puVar1[4];
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  FUN_00885190(local_34);
  piVar3 = (int *)FUN_00885a00(&param_1,iVar2,&local_24);
  iVar2 = *piVar3;
  if (local_c != (void *)0x0) {
    _free(local_c);
    return extraout_EAX;
  }
LAB_00885c79:
  return iVar2 + 0x20;
}


// ==== FUN_00885c90 @ 0x00885c90 ====

uint FUN_00885c90(uint *param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if (uVar1 < *param_2) {
LAB_00885ca1:
    return CONCAT31((int3)(uVar1 >> 8),1);
  }
  if (uVar1 <= *param_2) {
    uVar1 = param_1[3];
    if (uVar1 < param_2[3]) goto LAB_00885ca1;
    if (uVar1 <= param_2[3]) {
      return CONCAT31((int3)(param_1[4] >> 8),(int)param_1[4] < (int)param_2[4]);
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00885cd0 @ 0x00885cd0 ====

void FUN_00885cd0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x35) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x35) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x35);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x35);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x35) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x35) == '\0');
    if (*(char *)((int)piVar4 + 0x35) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_00885d50 @ 0x00885d50 ====

void FUN_00885d50(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  if (4 < (int)param_1) {
    iVar1 = (**(code **)(*DAT_00b5ac00 + 8))();
    if (*(char *)(iVar1 + 3) == '\0') {
      param_1 = (uint)(param_1 != 5);
      goto LAB_00885d92;
    }
  }
  if (param_1 == 4) {
    iVar1 = (**(code **)(*DAT_00b5ac00 + 8))();
    if (*(char *)(iVar1 + 5) == '\0') {
      param_1 = 0;
    }
  }
LAB_00885d92:
  iVar1 = (**(code **)(*DAT_00b5ac00 + 8))();
  if (2 < *(byte *)(iVar1 + 9)) {
    (**(code **)(*DAT_00b5d990 + 8))(2);
    return;
  }
  if (*(char *)(in_ECX + 0xb8) == '\0') {
    (**(code **)(*DAT_00b5d990 + 8))(0);
    return;
  }
  (**(code **)(*DAT_00b5d990 + 8))(1,param_1);
  return;
}


// ==== FUN_00885df0 @ 0x00885df0 ====

void FUN_00885df0(char param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 == 1) {
    iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
    if ((((*(int *)(iVar1 + 0x114) != 1) || (*(int *)(iVar1 + 0x118) != 5)) ||
        (*(int *)(iVar1 + 0x11c) != 6)) && (*(int *)(iVar1 + 100) == 0)) {
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,0);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,0xf0);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,6);
      *(undefined4 *)(iVar1 + 0x118) = 5;
      *(undefined4 *)(iVar1 + 0x11c) = 6;
      *(undefined4 *)(iVar1 + 0x114) = 1;
      return;
    }
  }
  else if (iVar1 == 0) {
    iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
    if ((((*(int *)(iVar1 + 0x114) != 0) || (*(int *)(iVar1 + 0x118) != 5)) ||
        (*(int *)(iVar1 + 0x11c) != 6)) && (*(int *)(iVar1 + 100) == 0)) {
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,0);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,0);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,6);
      *(undefined4 *)(iVar1 + 0x118) = 5;
      *(undefined4 *)(iVar1 + 0x11c) = 6;
      *(undefined4 *)(iVar1 + 0x114) = 0;
      return;
    }
  }
  else if ((iVar1 == 2) || (iVar1 == 3)) {
    iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
    if (param_1 == '\0') {
      if ((((*(int *)(iVar1 + 0x114) != 2) || (*(int *)(iVar1 + 0x118) != 5)) ||
          (*(int *)(iVar1 + 0x11c) != 6)) && (*(int *)(iVar1 + 100) == 0)) {
        (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
        (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
        (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
        (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
        (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
        (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,6);
        *(undefined4 *)(iVar1 + 0x11c) = 6;
        *(undefined4 *)(iVar1 + 0x114) = 2;
        *(undefined4 *)(iVar1 + 0x118) = 5;
      }
    }
    else if ((((*(int *)(iVar1 + 0x114) != 2) || (*(int *)(iVar1 + 0x118) != 5)) ||
             (*(int *)(iVar1 + 0x11c) != 2)) && (*(int *)(iVar1 + 100) == 0)) {
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,2);
      *(undefined4 *)(iVar1 + 0x11c) = 2;
      *(undefined4 *)(iVar1 + 0x114) = 2;
      *(undefined4 *)(iVar1 + 0x118) = 5;
      return;
    }
  }
  return;
}


// ==== FUN_00886100 @ 0x00886100 ====

void FUN_00886100(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined1 local_8 [8];
  
  if ((undefined4 *)param_2[2] != param_1) {
    piVar1 = (int *)FUN_00850950();
    (**(code **)(*piVar1 + 8))(local_8,param_1);
    *param_1 = unaff_EDI;
    *param_2 = unaff_ESI;
    param_2[2] = param_1;
  }
  return;
}


// ==== FUN_00886150 @ 0x00886150 ====

void FUN_00886150(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int in_ECX;
  float10 fVar5;
  float fStack_4;
  
  *(undefined1 *)(in_ECX + 0xb8) = 0;
  iVar2 = (**(code **)(*DAT_00b5ac00 + 8))();
  if (*(char *)(iVar2 + 2) != '\0') {
    if (*(char *)(DAT_00b5ac04 + 0xcc) == '\0') {
      if (*(char *)(in_ECX + 0xb9) != '\0') {
        *(char *)(in_ECX + 0xb8) = *(char *)(in_ECX + 0xb9);
      }
    }
    else {
      *(undefined1 *)(in_ECX + 0xb8) = 1;
    }
  }
  iVar2 = (**(code **)(*DAT_00b5ac00 + 8))();
  if (*(byte *)(iVar2 + 9) < 3) {
    if (*(char *)(in_ECX + 0xb8) == '\0') {
      piVar4 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
      iVar2 = (**(code **)(*piVar4 + 0x1c))();
      if (*(int *)(iVar2 + 8) == 0) {
        uVar3 = 0x11;
      }
      else {
        uVar3 = 1;
      }
    }
    else {
      piVar4 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
      iVar2 = (**(code **)(*piVar4 + 0x1c))();
      if (*(int *)(iVar2 + 8) == 0) {
        uVar3 = 0x12;
      }
      else {
        uVar3 = 2;
      }
    }
    uVar3 = FUN_0085e3a0(uVar3);
    *(undefined4 *)(in_ECX + 0xb0) = uVar3;
  }
  else {
    uVar3 = FUN_0085e3a0(3);
    *(undefined4 *)(in_ECX + 0xb0) = uVar3;
    fVar5 = (float10)FUN_0087a480();
    if (fVar5 <= (float10)DAT_0099d0b4) {
      fStack_4 = DAT_0099d0b4;
    }
    else {
      fVar5 = (float10)FUN_0087a480();
      fStack_4 = (float)fVar5;
    }
    iVar2 = *(int *)(in_ECX + 0xb0);
    iVar1 = *(int *)(iVar2 + 0x28);
    if ((iVar1 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar1 >> 2) < 0x17)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(iVar2 + 0x1c) + 0x78))
              (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar1 + 0x58),fStack_4);
    iVar2 = *(int *)(in_ECX + 0xb0);
    iVar1 = *(int *)(iVar2 + 0x28);
    if ((iVar1 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar1 >> 2) < 0x18)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(iVar2 + 0x1c) + 0x78))
              (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar1 + 0x5c),0x3b800000);
  }
  if (*(char *)(in_ECX + 0xb8) == '\0') {
    iVar2 = *(int *)(in_ECX + 0xb0);
    iVar1 = *(int *)(iVar2 + 0x28);
    if ((iVar1 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar1 >> 2) < 0x15)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(iVar2 + 0x1c) + 0x58))
              (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar1 + 0x50),0);
    return;
  }
  iVar2 = *(int *)(in_ECX + 0xb0);
  iVar1 = *(int *)(iVar2 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar1 >> 2) < 0x15)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x58))
            (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar1 + 0x50),1);
  if (*(char *)(in_ECX + 0xb8) == '\x01') {
    uVar3 = (**(code **)(*DAT_00b5af70 + 4))(1);
  }
  else {
    uVar3 = (**(code **)(*DAT_00b5af70 + 4))(2);
  }
  iVar2 = *(int *)(in_ECX + 0xb0);
  iVar1 = *(int *)(iVar2 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar1 >> 2) < 0x1b)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0xd0))
            (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar1 + 0x68),uVar3);
  return;
}


// ==== FUN_00886390 @ 0x00886390 ====

void FUN_00886390(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar2 = (**(code **)(*DAT_00b5ac00 + 8))();
  if ((*(char *)(iVar2 + 5) != '\0') && (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xe9) != '\0')) {
    if (param_1 == 4) {
      uVar3 = (**(code **)(*DAT_00b5d98c + 8))();
      FUN_0085e340(0x1c,uVar3);
      return;
    }
    iVar2 = *(int *)(in_ECX + 0xb0);
    iVar1 = *(int *)(iVar2 + 0x28);
    if ((iVar1 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar1 >> 2) < 0x1d)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(iVar2 + 0x1c) + 0xd0))
              (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar1 + 0x70),0);
  }
  return;
}


// ==== FUN_00886420 @ 0x00886420 ====

void FUN_00886420(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int in_ECX;
  
  if (*param_2 == *param_3) {
    return;
  }
  FUN_0085e340(0x18,*param_3);
  iVar2 = (**(code **)(*DAT_00b5ac00 + 8))();
  if ((*(char *)(iVar2 + 9) == '\0') || ((char)param_3[5] == '\0')) {
    *(undefined1 *)(param_2 + 1) = 0;
    if ((*(char *)(in_ECX + 0xb8) == '\0') &&
       (iVar2 = (**(code **)(*DAT_00b5ac00 + 8))(), *(char *)(iVar2 + 3) == '\0')) {
      iVar2 = *(int *)(in_ECX + 0xb0);
      iVar1 = *(int *)(iVar2 + 0x28);
      if ((iVar1 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar1 >> 2) < 0x1a)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      (**(code **)(**(int **)(iVar2 + 0x1c) + 0xd0))
                (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar1 + 100),0);
    }
    else {
      uVar3 = (**(code **)(*DAT_00b5d98c + 0x10))();
      FUN_0085e340(0x19,uVar3);
    }
    iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
    piVar4 = *(int **)(iVar2 + 0x90);
    (**(code **)(*piVar4 + 0x114))(piVar4,1,1,1);
    piVar4 = *(int **)(iVar2 + 0x90);
    (**(code **)(*piVar4 + 0x114))(piVar4,1,2,1);
  }
  else if ((char)param_2[1] == '\0') {
    FUN_00855360(1,3);
    uVar3 = (**(code **)(*DAT_00b5af70 + 4))(0);
    FUN_00878b10(0x19,uVar3);
    *(undefined1 *)(param_2 + 1) = 1;
  }
  if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xe9) != '\0') {
    iVar2 = (**(code **)(*DAT_00b5ac00 + 8))();
    if ((*(char *)(iVar2 + 5) != '\0') && (param_1 == 4)) {
      FUN_0085e340(0x1b,param_3[1]);
    }
    piVar4 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar4 + 0x1c))();
    if (((*(int *)(iVar2 + 8) != 0) &&
        (iVar2 = (**(code **)(*DAT_00b5ac00 + 8))(), *(char *)(iVar2 + 3) != '\0')) && (4 < param_1)
       ) {
      FUN_0085e340(0x1d,param_3[2]);
    }
  }
  *param_2 = *param_3;
  return;
}


// ==== FUN_008865d0 @ 0x008865d0 ====

void FUN_008865d0(float param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_8;
  float local_4;
  
  if (((param_1 == DAT_0099cdc8) || (param_1 == DAT_0099d080)) ||
     (DAT_0099d080 / param_1 == DAT_0099d080)) {
    local_8 = *(undefined4 *)(DAT_00b5ac04 + 0x9c);
    local_4 = *(float *)(DAT_00b5ac04 + 0xa0);
  }
  else {
    local_4 = DAT_0099d0dc / (*(float *)(DAT_00b5ac04 + 0xa8) * (DAT_0099d080 / param_1));
    local_8 = *(undefined4 *)(DAT_00b5ac04 + 0x9c);
  }
  iVar1 = *(int *)(in_ECX + 0xb0);
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x11)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0x80))
            (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar2 + 0x40),&local_8,2);
  return;
}


// ==== FUN_008866a0 @ 0x008866a0 ====

void FUN_008866a0(undefined4 *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int **ppiVar7;
  undefined4 *puVar8;
  int *piVar9;
  int **ppiVar10;
  undefined1 *puStack_214;
  undefined1 *puStack_210;
  undefined1 *puStack_20c;
  undefined1 *puStack_208;
  int *piStack_204;
  undefined4 uStack_200;
  int *piStack_1fc;
  int **ppiStack_1f8;
  undefined1 *puStack_1f4;
  int *apiStack_1f0 [4];
  undefined4 uStack_1e0;
  undefined4 *puStack_1dc;
  int *piStack_1d8;
  int *piStack_1d4;
  int *apiStack_1d0 [6];
  int *piStack_1b8;
  int local_1a4;
  int local_1a0 [3];
  undefined1 auStack_194 [4];
  int aiStack_190 [7];
  undefined1 auStack_174 [4];
  undefined4 auStack_170 [2];
  undefined1 auStack_168 [8];
  int aiStack_160 [2];
  undefined1 auStack_158 [8];
  undefined1 auStack_150 [4];
  undefined4 local_14c [5];
  undefined1 auStack_138 [32];
  undefined1 auStack_118 [8];
  undefined1 auStack_110 [8];
  undefined1 auStack_108 [8];
  int local_100 [2];
  undefined1 auStack_f8 [8];
  undefined1 auStack_f0 [20];
  undefined1 auStack_dc [12];
  undefined1 auStack_d0 [16];
  undefined1 auStack_c0 [60];
  int iStack_84;
  int aiStack_4c [19];
  
  local_1a0[0] = param_1[0x1d];
  iVar4 = *(int *)(DAT_00b5ac04 + 0x78);
  piVar6 = param_1 + 0xd;
  piVar9 = local_100;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar9 = *piVar6;
    piVar6 = piVar6 + 1;
    piVar9 = piVar9 + 1;
  }
  local_1a4 = iVar4 + 8;
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    piStack_1b8 = (int *)(local_1a0[0] + 0x20);
    apiStack_1d0[5] = local_14c;
    puVar5 = (undefined4 *)*param_1;
    puVar8 = local_14c;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar8 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar8 = puVar8 + 1;
    }
    apiStack_1d0[4] = aiStack_190 + 1;
    apiStack_1d0[3] = (int *)0x886709;
    thunk_FUN_0079ee7b();
    piVar6 = aiStack_190;
    piVar9 = local_100;
    for (iVar2 = 0x10; piVar6 = piVar6 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar9 = *piVar6;
      piVar9 = piVar9 + 1;
    }
  }
  piStack_1b8 = (int *)0x886726;
  iVar2 = (**(code **)(*DAT_00b5ac00 + 8))();
  if (2 < *(byte *)(iVar2 + 9)) {
    piStack_1b8 = (int *)0x0;
    apiStack_1d0[5] = (int *)auStack_c0;
    apiStack_1d0[4] = (int *)0x886741;
    apiStack_1d0[4] = (int *)(**(code **)(*DAT_00b5af70 + 0x28))();
    apiStack_1d0[3] = (int *)auStack_108;
    apiStack_1d0[2] = (int *)auStack_194;
    apiStack_1d0[1] = (int *)0x886754;
    thunk_FUN_0079ee7b();
    iVar2 = *(int *)(in_ECX + 0xb0);
    piVar6 = local_1a0;
    piVar9 = aiStack_160;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar9 = *piVar6;
      piVar6 = piVar6 + 1;
      piVar9 = piVar9 + 1;
    }
    iVar3 = *(int *)(iVar2 + 0x28);
    if ((iVar3 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar3 >> 2) < 0x16)) {
                    /* WARNING: Subroutine does not return */
      apiStack_1d0[1] = (int *)0x886785;
      FUN_0085b340();
    }
    apiStack_1d0[0] = *(int **)(iVar3 + 0x54);
    piStack_1d4 = *(int **)(iVar2 + 0x1c);
    apiStack_1d0[1] = aiStack_160;
    piStack_1d8 = (int *)0x88679a;
    (**(code **)(*piStack_1d4 + 0x98))();
  }
  apiStack_1d0[5] = local_100;
  apiStack_1d0[4] = aiStack_190 + 1;
  apiStack_1d0[3] = (int *)0x8867ad;
  piStack_1b8 = (int *)(iVar4 + 200);
  thunk_FUN_0079ee7b();
  iVar4 = *(int *)(in_ECX + 0xb0);
  piVar6 = local_1a0 + 2;
  piVar9 = aiStack_4c;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar9 = *piVar6;
    piVar6 = piVar6 + 1;
    piVar9 = piVar9 + 1;
  }
  puVar5 = *(undefined4 **)(iVar4 + 0x28);
  if ((puVar5 == (undefined4 *)0x0) ||
     (local_1a0[1] = *(int *)(iVar4 + 0x2c) - (int)puVar5 >> 2, local_1a0[1] == 0)) {
                    /* WARNING: Subroutine does not return */
    apiStack_1d0[3] = (int *)0x8867e2;
    FUN_0085b340();
  }
  apiStack_1d0[2] = (int *)*puVar5;
  apiStack_1d0[1] = *(int **)(iVar4 + 0x1c);
  apiStack_1d0[3] = aiStack_4c;
  apiStack_1d0[0] = (int *)0x8867f9;
  (**(code **)(*apiStack_1d0[1] + 0x98))();
  apiStack_1d0[0] = apiStack_1d0[5];
  piStack_1d4 = (int *)auStack_118;
  piStack_1d8 = &local_1a4;
  puStack_1dc = (undefined4 *)0x886810;
  thunk_FUN_0079ee7b();
  iVar4 = *(int *)(in_ECX + 0xb0);
  ppiVar7 = apiStack_1d0 + 8;
  puVar5 = auStack_170;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *ppiVar7;
    ppiVar7 = ppiVar7 + 1;
    puVar5 = puVar5 + 1;
  }
  iVar2 = *(int *)(iVar4 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar2 >> 2) < 4)) {
                    /* WARNING: Subroutine does not return */
    puStack_1dc = (undefined4 *)0x886841;
    FUN_0085b340();
  }
  uStack_1e0 = *(undefined4 *)(iVar2 + 0xc);
  apiStack_1f0[3] = *(int **)(iVar4 + 0x1c);
  puStack_1dc = auStack_170;
  apiStack_1f0[2] = (int *)0x886856;
  (**(code **)(*apiStack_1f0[3] + 0x98))();
  apiStack_1f0[2] = (int *)0x0;
  apiStack_1f0[1] = (int *)auStack_f0;
  apiStack_1f0[0] = (int *)0x88686b;
  apiStack_1f0[0] = (int *)(**(code **)(*DAT_00b5af70 + 0x20))();
  puStack_1f4 = auStack_138;
  ppiStack_1f8 = apiStack_1d0 + 3;
  piStack_1fc = (int *)0x88687e;
  thunk_FUN_0079ee7b();
  iVar4 = *(int *)(in_ECX + 0xb0);
  ppiVar7 = apiStack_1d0;
  piVar6 = aiStack_190;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar6 = (int)*ppiVar7;
    ppiVar7 = ppiVar7 + 1;
    piVar6 = piVar6 + 1;
  }
  iVar2 = *(int *)(iVar4 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar2 >> 2) < 2)) {
                    /* WARNING: Subroutine does not return */
    piStack_1fc = (int *)0x8868af;
    FUN_0085b340();
  }
  uStack_200 = *(undefined4 *)(iVar2 + 4);
  piStack_204 = *(int **)(iVar4 + 0x1c);
  piStack_1fc = aiStack_190;
  puStack_208 = (undefined1 *)0x8868c4;
  (**(code **)(*piStack_204 + 0x98))();
  if (*(char *)(in_ECX + 0xb8) != '\0') {
    puStack_20c = auStack_110;
    if (*(char *)(in_ECX + 0xb8) == '\x01') {
      puStack_208 = (undefined1 *)0x1;
    }
    else {
      puStack_208 = (undefined1 *)0x2;
    }
    puStack_210 = (undefined1 *)0x8868eb;
    puStack_210 = (undefined1 *)(**(code **)(*DAT_00b5af70 + 0x20))();
    puStack_214 = auStack_158;
    thunk_FUN_0079ee7b(apiStack_1f0 + 3);
    ppiVar7 = apiStack_1f0;
    ppiVar10 = apiStack_1d0 + 8;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *ppiVar10 = *ppiVar7;
      ppiVar7 = ppiVar7 + 1;
      ppiVar10 = ppiVar10 + 1;
    }
    iVar4 = *(int *)(in_ECX + 0xb0);
    iVar2 = *(int *)(iVar4 + 0x28);
    if ((iVar2 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar2 >> 2) < 3)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(iVar4 + 0x1c) + 0x98))
              (*(int **)(iVar4 + 0x1c),*(undefined4 *)(iVar2 + 8),apiStack_1d0 + 8);
  }
  puStack_208 = auStack_150;
  puStack_20c = (undefined1 *)0x0;
  puStack_210 = auStack_d0;
  puStack_214 = (undefined1 *)0x88695b;
  thunk_FUN_0079f3a1();
  iVar4 = *(int *)(*(int *)(DAT_00b5ac04 + 0x78) + 4);
  ppiStack_1f8 = *(int ***)(iVar4 + 0xc);
  puStack_1f4 = *(undefined1 **)(iVar4 + 0x10);
  apiStack_1f0[0] = *(int **)(iVar4 + 0x14);
  puStack_214 = auStack_dc;
  thunk_FUN_0079e5a0(auStack_168,&ppiStack_1f8);
  iVar4 = *(int *)(in_ECX + 0xb0);
  iVar2 = *(int *)(iVar4 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar2 >> 2) < 7)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  iVar2 = *(int *)(iVar2 + 0x18);
  (**(code **)(**(int **)(iVar4 + 0x1c) + 0x80))(*(int **)(iVar4 + 0x1c),iVar2,auStack_174,3);
  uVar1 = FUN_00862ac0(&puStack_214,auStack_f8);
  iVar4 = *(int *)(in_ECX + 0xb0);
  iVar3 = *(int *)(iVar4 + 0x28);
  if ((iVar3 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar3 >> 2) < 0x12)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar4 + 0x1c) + 0x80))
            (*(int **)(iVar4 + 0x1c),*(undefined4 *)(iVar3 + 0x44),uVar1,3);
  FUN_008865d0(*(undefined4 *)(iVar2 + 0x1c));
  iVar4 = *(int *)(in_ECX + 0xb0);
  iVar2 = *(int *)(iVar4 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar2 >> 2) < 0x10)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar4 + 0x1c) + 0x78))
            (*(int **)(iVar4 + 0x1c),*(undefined4 *)(iVar2 + 0x3c),*(undefined4 *)(iStack_84 + 0x24)
            );
  return;
}


// ==== FUN_00886a90 @ 0x00886a90 ====

void FUN_00886a90(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  undefined4 *puVar7;
  undefined1 auStack_86 [58];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puVar7 = *(undefined4 **)(param_1 + 0x5c);
  puVar1 = *(undefined4 **)(param_1 + 0x60);
  iVar6 = 0;
  do {
    if (puVar7 == puVar1) {
      return;
    }
    if ((*(char *)(param_2 + 0xcc) == '\0') && (*(int *)(param_2 + 0xd0) != 0)) {
      iVar4 = (**(code **)(**(int **)(param_2 + 0xd0) + 0xc))(*puVar7);
      iVar2 = *(int *)(in_ECX + 0xb0);
      if (iVar4 == 0) {
        uStack_48 = 0;
        uStack_4c = 0;
        uStack_44 = DAT_0099d080;
        iVar4 = *(int *)(iVar2 + 0x28);
        if ((iVar4 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar4 >> 2) < 0xc)) {
LAB_00886cd4:
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        uVar5 = (**(code **)(**(int **)(iVar2 + 0x1c) + 0x2c))
                          (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar4 + 0x2c),iVar6);
        (**(code **)(**(int **)(iVar2 + 0x1c) + 0x98))
                  (*(int **)(iVar2 + 0x1c),uVar5,auStack_86 + -6);
      }
      else {
        iVar3 = *(int *)(iVar2 + 0x28);
        if ((iVar3 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar3 >> 2) < 0xc)) goto LAB_00886cd4;
        uVar5 = (**(code **)(**(int **)(iVar2 + 0x1c) + 0x2c))
                          (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar3 + 0x2c),iVar6);
        (**(code **)(**(int **)(iVar2 + 0x1c) + 0x98))(*(int **)(iVar2 + 0x1c),uVar5,iVar4 + 0xe0);
      }
    }
    else {
      iVar2 = *(int *)(in_ECX + 0xb0);
      uStack_8 = 0;
      uStack_c = 0;
      uStack_10 = 0;
      uStack_14 = 0;
      uStack_1c = 0;
      uStack_20 = 0;
      uStack_24 = 0;
      uStack_28 = 0;
      uStack_30 = 0;
      uStack_34 = 0;
      uStack_38 = 0;
      uStack_3c = 0;
      iVar4 = *(int *)(iVar2 + 0x28);
      uStack_40 = DAT_0099d080;
      uStack_2c = DAT_0099d080;
      uStack_18 = DAT_0099d080;
      uStack_4 = DAT_0099d080;
      if ((iVar4 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar4 >> 2) < 0xc)) goto LAB_00886cd4;
      uVar5 = (**(code **)(**(int **)(iVar2 + 0x1c) + 0x2c))
                        (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar4 + 0x2c),iVar6);
      (**(code **)(**(int **)(iVar2 + 0x1c) + 0x98))(*(int **)(iVar2 + 0x1c),uVar5,&uStack_4c);
    }
    puVar7 = puVar7 + 1;
    iVar6 = iVar6 + 1;
  } while( true );
}


// ==== FUN_00886ce0 @ 0x00886ce0 ====

void FUN_00886ce0(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 100);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(*(int *)(param_1 + 0xc) + 0x68) - iVar1 >> 2) <= *(uint *)(param_1 + 0x10))) {
                    /* WARNING: Subroutine does not return */
    FUN_004bb6a0();
  }
  iVar1 = *(int *)(iVar1 + *(uint *)(param_1 + 0x10) * 4);
  iVar4 = *(int *)(iVar1 + 0x2c);
  iVar1 = *(int *)(iVar1 + 0x30);
  iVar6 = 0;
  if (iVar4 != iVar1) {
    piVar5 = (int *)(iVar4 + 0x18);
    do {
      piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
      (**(code **)(*piVar2 + 0x148))
                (piVar2,piVar5[-5],param_4,piVar5[-4],piVar5[-3],param_3 + iVar6,piVar5[-2]);
      if (*piVar5 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = piVar5[1] - *piVar5 >> 1;
      }
      iVar4 = iVar4 + 0x24;
      iVar6 = iVar6 + iVar3;
      piVar5 = piVar5 + 9;
    } while (iVar4 != iVar1);
  }
  return;
}


// ==== FUN_00886d80 @ 0x00886d80 ====

void FUN_00886d80(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  float fVar6;
  undefined4 uVar7;
  int local_10 [3];
  float local_4;
  
  if (*(char *)(param_2 + 10) == '\0') {
    uVar4 = FUN_0040ec60(local_10,*(undefined4 *)(param_2 + 4));
    iVar2 = *(int *)(in_ECX + 0xb0);
    iVar3 = *(int *)(iVar2 + 0x28);
    if ((iVar3 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar3 >> 2) < 0xd)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(iVar2 + 0x1c) + 0x88))
              (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar3 + 0x30),uVar4);
  }
  else {
    FUN_0040ec60(local_10,*(undefined4 *)(param_2 + 4));
    fVar6 = (float)*(byte *)(param_2 + 0xc) * DAT_0099d0b0;
    if (local_4 <= fVar6) {
      fVar6 = local_4;
    }
    iVar2 = *(int *)(in_ECX + 0xb0);
    iVar3 = *(int *)(iVar2 + 0x28);
    local_4 = fVar6;
    if ((iVar3 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar3 >> 2) < 0xd)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(iVar2 + 0x1c) + 0x88))
              (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar3 + 0x30),local_10);
  }
  iVar2 = *(int *)(in_ECX + 0xb0);
  iVar3 = *(int *)(iVar2 + 0x28);
  if ((iVar3 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar3 >> 2) < 0x14)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x78))
            (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar3 + 0x4c),*(undefined4 *)(param_2 + 0x20));
  iVar2 = *(int *)(in_ECX + 0xb0);
  iVar3 = *(int *)(iVar2 + 0x28);
  if ((iVar3 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar3 >> 2) < 0xf)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  iVar5 = local_10[0] + 0x114;
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x80))
            (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar3 + 0x38),iVar5,2);
  iVar2 = *(int *)(in_ECX + 0xb0);
  iVar3 = *(int *)(iVar2 + 0x28);
  if ((iVar3 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar3 >> 2) < 0xe)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x88))
            (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar3 + 0x34),param_2 + 0x10);
  iVar2 = *(int *)(in_ECX + 0xb0);
  iVar3 = *(int *)(iVar2 + 0x28);
  uVar4 = *(undefined4 *)(param_2 + 0x28);
  if ((iVar3 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar3 >> 2) < 6)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x78))
            (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar3 + 0x14),uVar4);
  cVar1 = *(char *)(param_2 + 8);
  iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
  if (cVar1 == '\0') {
    if (*(char *)(iVar2 + 0x7e) != '\0') {
      (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x16,3);
      goto LAB_00886f7c;
    }
    uVar7 = 2;
  }
  else {
    uVar7 = 1;
  }
  (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x16,uVar7);
LAB_00886f7c:
  *(char *)(iVar2 + 0x74) = cVar1;
  FUN_0087a760(*(undefined4 *)(in_ECX + 0xb0),iVar5 + 0xb0,iVar5 + 0xbc,*(undefined4 *)(iVar5 + 200)
              );
  FUN_008866a0(param_2);
  FUN_00886a90(uVar4,iVar5);
  return;
}


// ==== FUN_00887020 @ 0x00887020 ====

void FUN_00887020(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)(in_ECX + 0xc);
  iVar2 = 7;
  do {
    iVar4 = 2;
    do {
      FUN_00887690(*(undefined4 *)(*piVar3 + 4));
      *(int *)(*piVar3 + 4) = *piVar3;
      piVar3[1] = 0;
      *(int *)*piVar3 = *piVar3;
      iVar1 = *piVar3;
      piVar3 = piVar3 + 3;
      iVar4 = iVar4 + -1;
      *(int *)(iVar1 + 8) = iVar1;
    } while (iVar4 != 0);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(in_ECX + 0xb4) = 0;
  return;
}


// ==== FUN_00887080 @ 0x00887080 ====

void FUN_00887080(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int in_ECX;
  uint uVar8;
  int *piVar9;
  uint unaff_EDI;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  undefined1 auStack_4c [4];
  int iStack_48;
  int iStack_44;
  undefined4 uStack_40;
  undefined1 uStack_3c;
  int iStack_38;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  if (*(int *)(in_ECX + 0xb4) != 0) {
    FUN_00886150();
    FUN_00885df0(param_1);
    piVar5 = (int *)FUN_00850950();
    (**(code **)(*piVar5 + 4))();
    piVar5 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar5 + 0x15c))(piVar5,*(undefined4 *)(*(int *)(in_ECX + 0xb0) + 0x20));
    iVar14 = *(int *)(in_ECX + 0xb0);
    uStack_2c = 0;
    uStack_28 = 0;
    iVar10 = *(int *)(iVar14 + 0x28);
    if ((iVar10 == 0) || ((uint)(*(int *)(iVar14 + 0x2c) - iVar10 >> 2) < 0xf)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(iVar14 + 0x1c) + 0x80))
              (*(int **)(iVar14 + 0x1c),*(undefined4 *)(iVar10 + 0x38),&uStack_2c,2);
    FUN_008598a0(param_1);
    iVar14 = 0;
    do {
      FUN_00885d50(iVar14);
      piVar5 = *(int **)(*(int *)(in_ECX + 0xb0) + 0x1c);
      iVar10 = 0;
      (**(code **)(*piVar5 + 0x104))(piVar5,auStack_4c);
      FUN_00886390(iVar14);
      uVar15 = 0;
      if (unaff_EDI != 0) {
        uVar8 = 0;
        do {
          iVar12 = uVar8 + iVar14 * 2;
          if (*(int *)(in_ECX + 0x10 + iVar12 * 0xc) != 0) {
            piVar5 = *(int **)(*(int *)(in_ECX + 0xb0) + 0x1c);
            (**(code **)(*piVar5 + 0x108))(piVar5,uVar8);
            piVar5 = *(int **)(in_ECX + iVar12 * 0xc + 0xc);
            uStack_40 = 0;
            uStack_3c = 0;
            iStack_38 = 0;
            iVar12 = 0;
            iVar13 = 0;
            piVar9 = (int *)*piVar5;
            if (piVar9 != piVar5) {
              do {
                iVar2 = piVar9[6];
                iVar14 = *(int *)(iVar2 + 100);
                piVar7 = piVar9 + 3;
                if ((iVar14 == 0) ||
                   ((uint)(*(int *)(iVar2 + 0x68) - iVar14 >> 2) <= (uint)piVar9[7])) {
                    /* WARNING: Subroutine does not return */
                  FUN_004bb6a0();
                }
                iVar3 = *(int *)(iVar14 + piVar9[7] * 4);
                piVar6 = piVar9;
                iVar14 = iVar10;
                iVar11 = iVar3;
                if (iStack_38 != iVar2) {
                  piVar6 = (int *)FUN_00850950();
                  (**(code **)(*piVar6 + 8))(&iStack_48,iVar2);
                  piVar6 = piVar9;
                  iVar14 = iVar10;
                  iVar12 = iStack_48;
                  iVar13 = iStack_44;
                  iStack_38 = iVar2;
                }
                FUN_00886420(iVar14,&uStack_40,piVar7);
                uVar15 = *(int *)(iVar3 + 0x6c) + iVar13;
                iVar10 = *(int *)(iVar3 + 0x68) + iVar12;
                piVar9 = (int *)piVar6[10];
                piVar7 = (int *)piVar6[0xb];
                if (piVar9 != piVar7) {
                  do {
                    unaff_EDI = *(uint *)(*piVar9 + 0x74);
                    FUN_00886d80(iVar11,*piVar9);
                    piVar4 = *(int **)(*(int *)(in_ECX + 0xb0) + 0x1c);
                    (**(code **)(*piVar4 + 0x10c))(piVar4);
                    FUN_00886ce0(piVar6 + 3,unaff_EDI,uVar15,iVar10);
                    piVar9 = piVar9 + 1;
                  } while (piVar9 != piVar7);
                }
                piVar9 = piVar6;
                if (*(char *)((int)piVar6 + 0x35) == '\0') {
                  piVar9 = (int *)piVar6[2];
                  if (*(char *)((int)piVar9 + 0x35) == '\0') {
                    cVar1 = *(char *)(*piVar9 + 0x35);
                    piVar7 = (int *)*piVar9;
                    while (cVar1 == '\0') {
                      cVar1 = *(char *)(*piVar7 + 0x35);
                      piVar9 = piVar7;
                      piVar7 = (int *)*piVar7;
                    }
                  }
                  else {
                    piVar9 = (int *)piVar6[1];
                    if (*(char *)((int)piVar9 + 0x35) == '\0') {
                      while( true ) {
                        piVar7 = piVar9;
                        piVar9 = piVar7;
                        if ((piVar6 != (int *)piVar7[2]) ||
                           (piVar9 = (int *)piVar7[1], *(char *)((int)piVar9 + 0x35) != '\0'))
                        break;
                        piVar6 = piVar7;
                      }
                    }
                  }
                }
                iVar10 = iVar14;
              } while (piVar9 != piVar5);
            }
            piVar5 = *(int **)(*(int *)(in_ECX + 0xb0) + 0x1c);
            (**(code **)(*piVar5 + 0x110))(piVar5);
          }
          uVar15 = uVar15 + 1;
          uVar8 = uVar15 & 0xffff;
        } while (uVar8 < unaff_EDI);
      }
      piVar5 = *(int **)(*(int *)(in_ECX + 0xb0) + 0x1c);
      (**(code **)(*piVar5 + 0x114))(piVar5);
      iVar14 = iVar14 + 1;
    } while (iVar14 < 7);
    FUN_00859930(param_1);
    iVar14 = (**(code **)(*DAT_00b5ac00 + 8))();
    if ((*(char *)(iVar14 + 5) != '\0') && (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xe9) != '\0')
       ) {
      iVar14 = *(int *)(in_ECX + 0xb0);
      iVar10 = *(int *)(iVar14 + 0x28);
      if ((iVar10 == 0) || ((uint)(*(int *)(iVar14 + 0x2c) - iVar10 >> 2) < 0x1d)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      (**(code **)(**(int **)(iVar14 + 0x1c) + 0xd0))
                (*(int **)(iVar14 + 0x1c),*(undefined4 *)(iVar10 + 0x70),0);
    }
  }
  return;
}


// ==== FUN_00887410 @ 0x00887410 ====

void FUN_00887410(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_00a14b84;
  FUN_00887750(local_4,*(undefined4 *)in_ECX[0x2a],(undefined4 *)in_ECX[0x2a]);
  _free((void *)in_ECX[0x2a]);
  return;
}


// ==== FUN_00887470 @ 0x00887470 ====

void FUN_00887470(undefined4 param_1)

{
  int iVar1;
  undefined4 *in_ECX;
  undefined4 *puVar2;
  int iVar3;
  
  *in_ECX = &PTR_FUN_00a14b84;
  in_ECX[1] = param_1;
  puVar2 = in_ECX + 2;
  iVar3 = 0xe;
  do {
    iVar1 = FUN_008875f0();
    puVar2[1] = iVar1;
    *(undefined1 *)(iVar1 + 0x35) = 1;
    *(undefined4 *)(puVar2[1] + 4) = puVar2[1];
    *(undefined4 *)puVar2[1] = puVar2[1];
    *(undefined4 *)(puVar2[1] + 8) = puVar2[1];
    puVar2[2] = 0;
    puVar2 = puVar2 + 3;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  in_ECX[0x2c] = 0;
  in_ECX[0x2d] = 0;
  *(undefined1 *)(in_ECX + 0x2e) = 0;
  *(undefined1 *)((int)in_ECX + 0xb9) = 0;
  return;
}


// ==== FUN_008874e0 @ 0x008874e0 ====

undefined4 FUN_008874e0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0xbc);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_00887470(param_1);
  return uVar2;
}


// ==== FUN_00887510 @ 0x00887510 ====

void FUN_00887510(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  
  iVar3 = FUN_00887d50(param_3);
  iVar1 = *(int *)(iVar3 + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(iVar3 + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(iVar3 + 8) - iVar1 >> 2))) {
    FUN_0085b420(*(undefined4 *)(iVar3 + 8),1,&param_4);
    *(int *)(in_ECX + 0xb4) = *(int *)(in_ECX + 0xb4) + 1;
    return;
  }
  puVar2 = *(undefined4 **)(iVar3 + 8);
  *puVar2 = param_4;
  *(undefined4 **)(iVar3 + 8) = puVar2 + 1;
  *(int *)(in_ECX + 0xb4) = *(int *)(in_ECX + 0xb4) + 1;
  return;
}


// ==== FUN_008875a0 @ 0x008875a0 ====

undefined4 * FUN_008875a0(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar2[1] + 0x35) == '\0') {
    puVar1 = puVar2;
    puVar3 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar3;
      if ((uint)puVar2[3] < *param_1) {
LAB_008875d2:
        puVar3 = (undefined4 *)puVar2[2];
        puVar2 = puVar1;
      }
      else {
        if ((uint)puVar2[3] <= *param_1) {
          if (((uint)puVar2[6] < param_1[3]) ||
             (((uint)puVar2[6] <= param_1[3] && ((int)puVar2[7] < (int)param_1[4]))))
          goto LAB_008875d2;
        }
        puVar3 = (undefined4 *)*puVar2;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar3 + 0x35) == '\0');
  }
  return puVar2;
}


// ==== FUN_008875f0 @ 0x008875f0 ====

void FUN_008875f0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a740;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
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
  ExceptionList = local_10;
  return;
}


// ==== Catch@0088767a @ 0x0088767a ====

void Catch_0088767a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00887690 @ 0x00887690 ====

void FUN_00887690(void *param_1)

{
  if (*(char *)((int)param_1 + 0x35) != '\0') {
    return;
  }
  FUN_00887690(*(undefined4 *)((int)param_1 + 8));
  if (*(void **)((int)param_1 + 0x28) == (void *)0x0) {
    *(undefined4 *)((int)param_1 + 0x28) = 0;
    *(undefined4 *)((int)param_1 + 0x2c) = 0;
    *(undefined4 *)((int)param_1 + 0x30) = 0;
    _free(param_1);
    return;
  }
  _free(*(void **)((int)param_1 + 0x28));
  return;
}


// ==== FUN_008876e0 @ 0x008876e0 ====

void FUN_008876e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_2;
  *in_ECX = param_1;
  in_ECX[2] = param_3;
  in_ECX[3] = *param_4;
  in_ECX[4] = param_4[1];
  in_ECX[5] = param_4[2];
  in_ECX[6] = param_4[3];
  in_ECX[7] = param_4[4];
  in_ECX[8] = param_4[5];
  FUN_008835a0(param_4 + 6);
  *(undefined1 *)(in_ECX + 0xd) = param_5;
  *(undefined1 *)((int)in_ECX + 0x35) = 0;
  return;
}


// ==== FUN_00887750 @ 0x00887750 ====

void FUN_00887750(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00887690(piVar6[1]);
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
    FUN_00869720(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00887810 @ 0x00887810 ====

void * FUN_00887810(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a750;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x38);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_008876e0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00887885 @ 0x00887885 ====

void Catch_00887885(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_008878a0 @ 0x008878a0 ====

void FUN_008878a0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0x6666664 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00887810(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0xd] == '\0') {
LAB_008879a5:
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
      if ((char)piVar6[0xd] == '\0') goto LAB_008879a5;
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


// ==== FUN_00887a80 @ 0x00887a80 ====

void FUN_00887a80(undefined4 *param_1,uint *param_2)

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
      if (*param_2 < (uint)puVar4[3]) {
        bVar5 = true;
      }
      else if ((uint)puVar4[3] < *param_2) {
        bVar5 = false;
      }
      else if (param_2[3] < (uint)puVar4[6]) {
        bVar5 = true;
      }
      else if ((uint)puVar4[6] < param_2[3]) {
        bVar5 = false;
      }
      else {
        bVar5 = (int)param_2[4] < (int)puVar4[7];
      }
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
      puVar4 = (undefined4 *)FUN_008878a0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_00885cd0();
  }
  if (param_2[3] < *puVar2) {
LAB_00887b49:
    puVar4 = (undefined4 *)FUN_008878a0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  if (param_2[3] <= *puVar2) {
    if ((param_2[6] < puVar2[3]) ||
       ((param_2[6] <= puVar2[3] && ((int)param_2[7] < (int)puVar2[4])))) goto LAB_00887b49;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00887b80 @ 0x00887b80 ====

void FUN_00887b80(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xb9) = param_1;
  return;
}


// ==== FUN_00887b90 @ 0x00887b90 ====

undefined4 * FUN_00887b90(undefined4 *param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 local_8 [8];
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_008878a0(param_1,1,*(undefined4 *)(in_ECX + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    cVar3 = FUN_00885c90(param_3,param_2 + 3);
    if (cVar3 != '\0') {
      FUN_008878a0(param_1,1,param_2,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    iVar2 = piVar1[2];
    cVar3 = FUN_00885c90(iVar2 + 0xc,param_3);
    if (cVar3 != '\0') {
      FUN_008878a0(param_1,0,iVar2,param_3);
      return param_1;
    }
  }
  else {
    cVar3 = FUN_00885c90(param_3,param_2 + 3);
    if (cVar3 != '\0') {
      FUN_00885cd0();
      cVar3 = FUN_00885c90(param_2 + 3,param_3);
      if (cVar3 != '\0') {
        if (*(char *)(param_2[2] + 0x35) == '\0') {
          FUN_008878a0(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_008878a0(param_1,0,param_2,param_3);
        return param_1;
      }
    }
    cVar3 = FUN_00885c90(param_2 + 3,param_3);
    if (cVar3 != '\0') {
      FUN_00411640();
      if (param_2 != *(int **)(in_ECX + 4)) {
        cVar3 = FUN_00885c90(param_3,param_2 + 3);
        if (cVar3 == '\0') goto LAB_00887d0d;
      }
      if (*(char *)(param_2[2] + 0x35) == '\0') {
        FUN_008878a0(param_1,1,param_2,param_3);
        return param_1;
      }
      FUN_008878a0(param_1,0,param_2,param_3);
      return param_1;
    }
  }
LAB_00887d0d:
  puVar4 = (undefined4 *)FUN_00887a80(local_8,param_3);
  *param_1 = *puVar4;
  return param_1;
}


// ==== FUN_00887d30 @ 0x00887d30 ====

void FUN_00887d30(byte param_1)

{
  void *in_ECX;
  
  FUN_00887410();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00887d50 @ 0x00887d50 ====

int FUN_00887d50(uint *param_1)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int extraout_EAX;
  int in_ECX;
  undefined1 local_38 [4];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  void *local_c;
  
  puVar1 = param_1;
  iVar2 = FUN_008875a0(param_1);
  if (iVar2 != *(int *)(in_ECX + 4)) {
    if (*(uint *)(iVar2 + 0xc) <= *puVar1) {
      if (*(uint *)(iVar2 + 0xc) < *puVar1) goto LAB_00887e00;
      if ((*(uint *)(iVar2 + 0x18) <= puVar1[3]) &&
         ((*(uint *)(iVar2 + 0x18) < puVar1[3] || (*(int *)(iVar2 + 0x1c) <= (int)puVar1[4]))))
      goto LAB_00887e00;
    }
  }
  local_28 = *puVar1;
  local_24 = puVar1[1];
  local_20 = puVar1[2];
  local_1c = puVar1[3];
  local_18 = puVar1[4];
  local_14 = puVar1[5];
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  FUN_008835a0(local_38);
  piVar3 = (int *)FUN_00887b90(&param_1,iVar2,&local_28);
  iVar2 = *piVar3;
  if (local_c != (void *)0x0) {
    _free(local_c);
    return extraout_EAX;
  }
LAB_00887e00:
  return iVar2 + 0x24;
}


// ==== FUN_00887e10 @ 0x00887e10 ====

void FUN_00887e10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a14c00;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00887e30 @ 0x00887e30 ====

void FUN_00887e30(void)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int in_ECX;
  float fVar5;
  float fVar6;
  
  uVar4 = DAT_009b0318;
  fVar6 = DAT_0099d0b4;
  uVar3 = DAT_0099d080;
  fVar1 = *(float *)(*(int *)(in_ECX + 4) + 0xc);
  fVar2 = *(float *)(*(int *)(in_ECX + 4) + 0x10);
  if ((*(float *)(in_ECX + 0x3c) != fVar1) || (*(float *)(in_ECX + 0x40) != fVar2)) {
    *(undefined4 *)(in_ECX + 0x114) = DAT_009b0318;
    fVar5 = fVar2 - fVar6;
    *(float *)(in_ECX + 0x118) = fVar5;
    *(undefined4 *)(in_ECX + 0x11c) = 0;
    *(undefined4 *)(in_ECX + 0x120) = uVar3;
    *(undefined4 *)(in_ECX + 300) = uVar4;
    *(undefined4 *)(in_ECX + 0x130) = uVar4;
    *(undefined4 *)(in_ECX + 0x134) = 0;
    *(undefined4 *)(in_ECX + 0x138) = uVar3;
    fVar6 = fVar1 - fVar6;
    *(float *)(in_ECX + 0x144) = fVar6;
    *(float *)(in_ECX + 0x148) = fVar5;
    *(undefined4 *)(in_ECX + 0x14c) = 0;
    *(undefined4 *)(in_ECX + 0x150) = uVar3;
    *(float *)(in_ECX + 0x15c) = fVar6;
    *(undefined4 *)(in_ECX + 0x160) = uVar4;
    *(undefined4 *)(in_ECX + 0x164) = 0;
    *(undefined4 *)(in_ECX + 0x168) = uVar3;
    *(float *)(in_ECX + 0x3c) = fVar1;
    *(float *)(in_ECX + 0x40) = fVar2;
  }
  return;
}


// ==== FUN_00887f80 @ 0x00887f80 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00887f80(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  float fVar4;
  float fVar5;
  float fVar6;
  
  uVar3 = _DAT_00a13628;
  uVar2 = DAT_009b0318;
  uVar1 = DAT_0099d080;
  fVar6 = *(float *)(*(int *)(in_ECX + 4) + 0x10);
  fVar4 = *(float *)(*(int *)(in_ECX + 4) + 0xc);
  *(undefined4 *)(in_ECX + 0x44) = DAT_009b0318;
  *(undefined4 *)(in_ECX + 0x48) = uVar2;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x50) = uVar1;
  *(undefined4 *)(in_ECX + 0x60) = uVar3;
  *(undefined4 *)(in_ECX + 100) = uVar2;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 0x6c) = uVar1;
  *(undefined4 *)(in_ECX + 0x7c) = uVar2;
  *(undefined4 *)(in_ECX + 0x80) = uVar3;
  *(undefined4 *)(in_ECX + 0x84) = 0;
  *(undefined4 *)(in_ECX + 0x88) = uVar1;
  *(undefined4 *)(in_ECX + 0x98) = uVar3;
  fVar5 = DAT_0099d0b4;
  *(undefined4 *)(in_ECX + 0x9c) = uVar3;
  *(undefined4 *)(in_ECX + 0xa0) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x70) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8c) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xa4) = uVar1;
  *(undefined4 *)(in_ECX + 0xa8) = 0xffffffff;
  fVar6 = fVar6 - fVar5;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x74) = uVar1;
  *(undefined4 *)(in_ECX + 0x78) = 0;
  *(undefined4 *)(in_ECX + 0x90) = 0;
  *(undefined4 *)(in_ECX + 0x94) = uVar1;
  *(undefined4 *)(in_ECX + 0xac) = uVar1;
  *(undefined4 *)(in_ECX + 0xb0) = uVar1;
  *(undefined4 *)(in_ECX + 0x114) = uVar2;
  *(float *)(in_ECX + 0x118) = fVar6;
  *(undefined4 *)(in_ECX + 0x11c) = 0;
  *(undefined4 *)(in_ECX + 0x120) = uVar1;
  *(undefined4 *)(in_ECX + 0x124) = 0;
  *(undefined4 *)(in_ECX + 0x128) = uVar1;
  *(undefined4 *)(in_ECX + 300) = uVar2;
  *(undefined4 *)(in_ECX + 0x130) = uVar2;
  *(undefined4 *)(in_ECX + 0x134) = 0;
  *(undefined4 *)(in_ECX + 0x138) = uVar1;
  *(undefined4 *)(in_ECX + 0x13c) = 0;
  *(undefined4 *)(in_ECX + 0x140) = 0;
  fVar4 = fVar4 - fVar5;
  *(float *)(in_ECX + 0x144) = fVar4;
  *(float *)(in_ECX + 0x148) = fVar6;
  *(undefined4 *)(in_ECX + 0x14c) = 0;
  *(undefined4 *)(in_ECX + 0x150) = uVar1;
  *(undefined4 *)(in_ECX + 0x154) = uVar1;
  *(undefined4 *)(in_ECX + 0x158) = uVar1;
  *(float *)(in_ECX + 0x15c) = fVar4;
  *(undefined4 *)(in_ECX + 0x160) = uVar2;
  *(undefined4 *)(in_ECX + 0x164) = 0;
  *(undefined4 *)(in_ECX + 0x168) = uVar1;
  *(undefined4 *)(in_ECX + 0x16c) = uVar1;
  *(undefined4 *)(in_ECX + 0x170) = 0;
  fVar5 = *(float *)(in_ECX + 0x1c) - fVar5;
  *(undefined4 *)(in_ECX + 0xb4) = uVar2;
  *(float *)(in_ECX + 0xb8) = fVar5;
  *(undefined4 *)(in_ECX + 0xbc) = 0;
  *(undefined4 *)(in_ECX + 0xc0) = uVar1;
  *(undefined4 *)(in_ECX + 0xc4) = 0;
  *(undefined4 *)(in_ECX + 200) = uVar1;
  *(undefined4 *)(in_ECX + 0xcc) = uVar2;
  *(undefined4 *)(in_ECX + 0xd0) = uVar2;
  *(undefined4 *)(in_ECX + 0xd4) = 0;
  *(undefined4 *)(in_ECX + 0xd8) = uVar1;
  *(undefined4 *)(in_ECX + 0xdc) = 0;
  *(undefined4 *)(in_ECX + 0xe0) = 0;
  *(float *)(in_ECX + 0xe4) = fVar5;
  *(float *)(in_ECX + 0xe8) = fVar5;
  *(undefined4 *)(in_ECX + 0xec) = 0;
  *(undefined4 *)(in_ECX + 0xf0) = uVar1;
  *(undefined4 *)(in_ECX + 0xf4) = uVar1;
  *(undefined4 *)(in_ECX + 0xf8) = uVar1;
  *(float *)(in_ECX + 0xfc) = fVar5;
  *(undefined4 *)(in_ECX + 0x100) = uVar2;
  *(undefined4 *)(in_ECX + 0x104) = 0;
  *(undefined4 *)(in_ECX + 0x108) = uVar1;
  *(undefined4 *)(in_ECX + 0x10c) = uVar1;
  *(undefined4 *)(in_ECX + 0x110) = 0;
  return;
}


// ==== FUN_008883f0 @ 0x008883f0 ====

void FUN_008883f0(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int in_ECX;
  int *piVar4;
  
  piVar4 = (int *)**(int **)(in_ECX + 0x2c);
  if (piVar4 != *(int **)(in_ECX + 0x2c)) {
    do {
      piVar2 = (int *)piVar4[4];
      if (piVar2 != (int *)0x0) {
        piVar4 = (int *)piVar2[1];
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 8))(piVar4);
          piVar2[1] = 0;
        }
        piVar4 = (int *)*piVar2;
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 8))(piVar4);
          *piVar2 = 0;
        }
        _free(piVar2);
        return;
      }
      if (*(char *)((int)piVar4 + 0x15) == '\0') {
        piVar2 = (int *)piVar4[2];
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          piVar4 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x15);
            piVar4 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar4[1] + 0x15);
          piVar3 = (int *)piVar4[1];
          piVar2 = piVar4;
          while ((piVar4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar4[2]))) {
            cVar1 = *(char *)(piVar4[1] + 0x15);
            piVar3 = (int *)piVar4[1];
            piVar2 = piVar4;
          }
        }
      }
    } while (piVar4 != *(int **)(in_ECX + 0x2c));
  }
  FUN_00888e60(*(undefined4 *)(*(int *)(in_ECX + 0x2c) + 4));
  *(int *)(*(int *)(in_ECX + 0x2c) + 4) = *(int *)(in_ECX + 0x2c);
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(in_ECX + 0x2c);
  *(int *)(*(int *)(in_ECX + 0x2c) + 8) = *(int *)(in_ECX + 0x2c);
  return;
}


// ==== FUN_008884b0 @ 0x008884b0 ====

void FUN_008884b0(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  int *piVar4;
  undefined1 local_8 [4];
  int local_4;
  
  piVar3 = (int *)FUN_0049b670();
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if ((((*(int *)(iVar1 + 0x114) != 2) || (*(int *)(iVar1 + 0x118) != 2)) ||
      (*(int *)(iVar1 + 0x11c) != 2)) && (*(int *)(iVar1 + 100) == 0)) {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,2);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,2);
    *(undefined4 *)(iVar1 + 0x114) = 2;
    *(undefined4 *)(iVar1 + 0x118) = 2;
    *(undefined4 *)(iVar1 + 0x11c) = 2;
  }
  local_8[0] = 3;
  FUN_005c8a80(&local_4,local_8);
  if (local_4 == *(int *)(in_ECX + 0x2c)) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(local_4 + 0x10);
  }
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  iVar2 = *piVar4;
  if (*(int *)(iVar1 + 0x134) != iVar2) {
    *(int *)(iVar1 + 0x134) = iVar2;
    (**(code **)(**(int **)(iVar1 + 0x90) + 0x104))(*(int **)(iVar1 + 0x90),0,iVar2);
  }
  (**(code **)(*piVar3 + 0x164))(piVar3,0x104);
  piVar4 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar4 + 0x14c))(piVar4,5,2,in_ECX + 0x114,0x18);
  (**(code **)(*piVar3 + 0x164))(piVar3,0);
  return;
}


// ==== FUN_00888620 @ 0x00888620 ====

undefined4 FUN_00888620(undefined1 param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int *piVar4;
  int unaff_EDI;
  undefined4 uVar5;
  undefined4 local_4;
  
  local_4 = in_ECX;
  piVar2 = (int *)FUN_0049b670();
  FUN_005c8a80(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0x2c)) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(local_4 + 0x10);
  }
  (**(code **)(*piVar2 + 0x94))(piVar2,0,*(undefined4 *)(iVar3 + 4));
  (**(code **)(*piVar2 + 0xa4))(piVar2);
  FUN_005c8a80((int)register0x00000010 + -0x14,(int)register0x00000010 + -0xc);
  if (unaff_EDI == *(int *)(in_ECX + 0x2c)) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(unaff_EDI + 0x10);
  }
  iVar3 = *(int *)(DAT_00b5ac04 + 0x28);
  iVar1 = *piVar4;
  if (*(int *)(iVar3 + 0x134) != iVar1) {
    *(int *)(iVar3 + 0x134) = iVar1;
    (**(code **)(**(int **)(iVar3 + 0x90) + 0x104))(*(int **)(iVar3 + 0x90),0,iVar1);
  }
  uVar5 = 0;
  (**(code **)(*piVar2 + 0xac))(piVar2,0,0,1,0,0x3f800000,0);
  piVar4 = *(int **)(*(int *)(in_ECX + 0xc) + 0x1c);
  (**(code **)(*piVar4 + 0x104))(piVar4,0,0);
  piVar4 = *(int **)(*(int *)(in_ECX + 0xc) + 0x1c);
  (**(code **)(*piVar4 + 0x108))(piVar4,uVar5);
  piVar4 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar4 + 0x14c))(piVar4,5,2,in_ECX + 0xb4,0x18);
  piVar4 = *(int **)(*(int *)(in_ECX + 0xc) + 0x1c);
  (**(code **)(*piVar4 + 0x110))(piVar4);
  piVar4 = *(int **)(*(int *)(in_ECX + 0xc) + 0x1c);
  (**(code **)(*piVar4 + 0x114))(piVar4);
  (**(code **)(*piVar2 + 0xa8))(piVar2);
  return 1;
}


// ==== FUN_00888770 @ 0x00888770 ====

void FUN_00888770(undefined1 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  char cVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_005c8a80(&local_4,&param_1);
  if ((local_4 != *(int *)(in_ECX + 0x2c)) &&
     (piVar1 = *(int **)(local_4 + 0x10), piVar1 != (int *)0x0)) {
    piVar6 = (int *)FUN_0049b670();
    iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
    iVar3 = *piVar1;
    if (*(int *)(iVar2 + 0x134) != iVar3) {
      *(int *)(iVar2 + 0x134) = iVar3;
      (**(code **)(**(int **)(iVar2 + 0x90) + 0x104))(*(int **)(iVar2 + 0x90),0,iVar3);
    }
    piVar1 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
    cVar5 = FUN_00881000(0x1c,0x70);
    if (cVar5 == '\0') {
      (**(code **)(*piVar1 + 0xc))();
    }
    uVar7 = (**(code **)(*piVar1 + 0x1c))(0x1c,0x70);
    (**(code **)(*piVar1 + 0x14))(0x70,in_ECX + 0x44);
    FUN_00881060();
    (**(code **)(*piVar6 + 0x164))(piVar6,0x144);
    piVar4 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar4 + 400))(piVar4,0,piVar1[1],0,0x1c);
    piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar1 + 0x144))(piVar1,5,uVar7,2);
    (**(code **)(*piVar6 + 0x164))(piVar6,0);
  }
  return;
}


// ==== FUN_00888890 @ 0x00888890 ====

void FUN_00888890(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  int *piStack_5c;
  int **ppiStack_58;
  int *piStack_54;
  undefined4 uStack_50;
  int **ppiStack_4c;
  int *piStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  int *piStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int *piStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int *piStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (*(char *)(*(int *)(in_ECX + 4) + 8) != '\0') {
    *(undefined4 *)(in_ECX + 0x10) = DAT_009bac80;
    *(undefined4 *)(in_ECX + 0x14) = DAT_00a14c24;
  }
  iVar1 = *(int *)(in_ECX + 0xc);
  iVar2 = *(int *)(iVar1 + 0x28);
  uStack_14 = *(undefined4 *)(in_ECX + 0x10);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x79)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_18 = *(undefined4 *)(iVar2 + 0x1e0);
  piStack_1c = *(int **)(iVar1 + 0x1c);
  uStack_20 = 0x8888f9;
  (**(code **)(*piStack_1c + 0x78))();
  iVar1 = *(int *)(in_ECX + 0xc);
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x7a)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_24 = *(undefined4 *)(iVar2 + 0x1e4);
  piStack_28 = *(int **)(iVar1 + 0x1c);
  uStack_2c = 0x888938;
  uStack_20 = *(undefined4 *)(in_ECX + 0x1c);
  (**(code **)(*piStack_28 + 0x78))();
  iVar1 = *(int *)(in_ECX + 0xc);
  iVar2 = *(int *)(iVar1 + 0x28);
  piStack_1c = *(int **)(in_ECX + 0x1c);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x7b)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_30 = *(undefined4 *)(iVar2 + 0x1e8);
  piStack_34 = *(int **)(iVar1 + 0x1c);
  uStack_2c = piStack_1c;
  (**(code **)(*piStack_34 + 0x78))();
  iVar1 = *(int *)(in_ECX + 0xc);
  iVar2 = *(int *)(iVar1 + 0x28);
  uStack_3c = *(undefined4 *)(in_ECX + 0x14);
  piStack_28 = (int *)uStack_3c;
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x7c)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  iStack_40 = *(int *)(iVar2 + 0x1ec);
  piStack_44 = *(int **)(iVar1 + 0x1c);
  (**(code **)(*piStack_44 + 0x78))();
  ppiStack_4c = &piStack_34;
  uStack_50 = 0x8889d0;
  FUN_005c8a80();
  if (piStack_34 == *(int **)(in_ECX + 0x2c)) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)piStack_34[4];
  }
  iVar1 = *(int *)(in_ECX + 0xc);
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x7d)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_50 = *(undefined4 *)(iVar2 + 0x1f0);
  piStack_54 = *(int **)(iVar1 + 0x1c);
  ppiStack_58 = (int **)0x888a16;
  ppiStack_4c = (int **)*piVar3;
  (**(code **)(*piStack_54 + 0xd0))();
  ppiStack_58 = &piStack_44;
  piStack_5c = &iStack_40;
  piStack_44 = (int *)CONCAT31(piStack_44._1_3_,1);
  FUN_005c8a80();
  if (iStack_40 == *(int *)(in_ECX + 0x2c)) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(iStack_40 + 0x10);
  }
  iVar1 = *(int *)(in_ECX + 0xc);
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x7e)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  piStack_5c = *(int **)(iVar2 + 500);
  ppiStack_58 = (int **)*piVar3;
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0xd0))(*(int **)(iVar1 + 0x1c));
  uStack_50 = CONCAT31(uStack_50._1_3_,2);
  FUN_005c8a80(&ppiStack_4c,&uStack_50);
  if (ppiStack_4c == *(int ***)(in_ECX + 0x2c)) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = ppiStack_4c[4];
  }
  iVar1 = *(int *)(in_ECX + 0xc);
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x7f)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0xd0))
            (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar2 + 0x1f8),*piVar3);
  piStack_5c = (int *)CONCAT31(piStack_5c._1_3_,3);
  FUN_005c8a80(&ppiStack_58,&piStack_5c);
  if (ppiStack_58 == *(int ***)(in_ECX + 0x2c)) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = ppiStack_58[4];
  }
  iVar1 = *(int *)(in_ECX + 0xc);
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x80)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0xd0))
            (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar2 + 0x1fc),*piVar3);
  return;
}


// ==== FUN_00888b30 @ 0x00888b30 ====

undefined4 FUN_00888b30(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 local_18;
  undefined1 local_14 [20];
  
  uVar1 = FUN_0049b670();
  FUN_008560c0(&local_18,local_14);
  puVar2 = operator_new(8);
  uVar3 = FUN_00802534();
  FUN_008a0665(uVar1,uVar3,uVar3,1,1,local_18,0,puVar2);
  (**(code **)(*(int *)*puVar2 + 0x48))((int *)*puVar2,0,puVar2 + 1);
  local_18 = puVar2;
  FUN_00889270(local_14,local_14 + -8);
  return 1;
}


// ==== FUN_00888bc0 @ 0x00888bc0 ====

void FUN_00888bc0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  int *piStack_1c;
  int *piStack_18;
  undefined1 local_8 [4];
  int local_4;
  
  piStack_18 = (int *)0x888bcd;
  FUN_00887e30();
  piStack_18 = (int *)0x888bda;
  piVar2 = (int *)FUN_0049b670();
  piVar1 = DAT_00b5af70;
  if (*(char *)(in_ECX[1] + 8) == '\0') {
    piVar1 = in_ECX + 2;
    piStack_1c = (int *)0x0;
    piStack_18 = piVar1;
    (**(code **)(*piVar2 + 0x48))(piVar2,0,0);
    piStack_1c = (int *)((uint)piStack_1c & 0xffffff00);
    FUN_005c8a80(&piStack_18,&piStack_1c);
    if (piStack_18 == (int *)in_ECX[0xb]) {
      iVar3 = 0;
    }
    else {
      iVar3 = piStack_18[4];
    }
    (**(code **)(*piVar2 + 0x88))(piVar2,*piVar1,0,*(undefined4 *)(iVar3 + 4),0,2);
    piVar2 = (int *)*piVar1;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *piVar1 = 0;
    }
  }
  else {
    piStack_18 = (int *)local_8;
    piStack_1c = &local_4;
    local_8[0] = 0;
    FUN_005c8a80();
    if (local_4 == in_ECX[0xb]) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(local_4 + 0x10);
    }
    local_4 = *piVar2;
    piStack_18 = (int *)0x2;
    piStack_1c = (int *)0x0;
    uVar4 = (**(code **)(*piVar1 + 8))(0,*(undefined4 *)(iVar3 + 4));
    (**(code **)(local_4 + 0x88))(piVar2,uVar4);
  }
  iVar3 = FUN_0085e3a0(0xe);
  in_ECX[3] = iVar3;
  (**(code **)(**(int **)(iVar3 + 0x1c) + 0xf0))(*(int **)(iVar3 + 0x1c),s_TBloomEffect_00a14bd8);
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 0x15c))(piVar1,*(undefined4 *)(in_ECX[3] + 0x20));
  (**(code **)(*in_ECX + 0x10))();
  FUN_00888620(1,0);
  FUN_00888620(2,1);
  FUN_00888620(3,2);
  return;
}


// ==== FUN_00888d10 @ 0x00888d10 ====

void FUN_00888d10(void)

{
  int in_ECX;
  
  FUN_00887f80();
  if (*(int *)(in_ECX + 0x30) == 0) {
    FUN_00888b30(0);
    FUN_00888b30(1);
    FUN_00888b30(2);
    FUN_00888b30(3);
  }
  return;
}


// ==== FUN_00888da0 @ 0x00888da0 ====

void FUN_00888da0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a14c2c;
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  iVar2 = FUN_00888f30();
  uVar1 = DAT_009b2d80;
  in_ECX[0xb] = iVar2;
  *(undefined1 *)(iVar2 + 0x15) = 1;
  *(undefined4 *)(in_ECX[0xb] + 4) = in_ECX[0xb];
  *(undefined4 *)in_ECX[0xb] = in_ECX[0xb];
  *(undefined4 *)(in_ECX[0xb] + 8) = in_ECX[0xb];
  in_ECX[0xc] = 0;
  in_ECX[7] = uVar1;
  in_ECX[4] = DAT_009b0300;
  in_ECX[5] = DAT_009ba338;
  in_ECX[6] = 0;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  FUN_00887f80();
  if (in_ECX[0xc] == 0) {
    FUN_00888b30(0);
    FUN_00888b30(1);
    FUN_00888b30(2);
    FUN_00888b30(3);
  }
  return;
}


// ==== FUN_00888e60 @ 0x00888e60 ====

void FUN_00888e60(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_00888e60(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00888ea0 @ 0x00888ea0 ====

void * FUN_00888ea0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a760;
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


// ==== Catch@00888f15 @ 0x00888f15 ====

void Catch_00888f15(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00888f30 @ 0x00888f30 ====

void FUN_00888f30(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a770;
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


// ==== Catch@00888fba @ 0x00888fba ====

void Catch_00888fba(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00888fd0 @ 0x00888fd0 ====

void FUN_00888fd0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_00888ea0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_008890d5:
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
      if ((char)piVar6[5] == '\0') goto LAB_008890d5;
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


// ==== FUN_008891b0 @ 0x008891b0 ====

void FUN_008891b0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00888e60(piVar6[1]);
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


// ==== FUN_00889270 @ 0x00889270 ====

void FUN_00889270(undefined4 *param_1,byte *param_2)

{
  undefined4 uVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  bool bVar5;
  
  pbVar2 = param_2;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  bVar5 = true;
  if (*(char *)((int)puVar4[1] + 0x15) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      bVar5 = *param_2 < *(byte *)(puVar4 + 3);
      if (bVar5) {
        puVar3 = (undefined4 *)*puVar4;
      }
      else {
        puVar3 = (undefined4 *)puVar4[2];
      }
    } while (*(char *)((int)puVar3 + 0x15) == '\0');
  }
  param_2 = (byte *)puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_00888fd0(&param_2,1,puVar4,pbVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (*(byte *)((int)param_2 + 0xc) < *pbVar2) {
    puVar4 = (undefined4 *)FUN_00888fd0(&param_2,bVar5,puVar4,pbVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00889330 @ 0x00889330 ====

int FUN_00889330(void)

{
  int in_ECX;
  
  return in_ECX + 0x10;
}


// ==== FUN_00889340 @ 0x00889340 ====

void FUN_00889340(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_00a14c2c;
  FUN_008883f0();
  FUN_008891b0(local_4,*(undefined4 *)in_ECX[0xb],(undefined4 *)in_ECX[0xb]);
  _free((void *)in_ECX[0xb]);
  return;
}


// ==== FUN_008893a0 @ 0x008893a0 ====

void FUN_008893a0(void)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int in_ECX;
  float fVar5;
  float fVar6;
  
  uVar4 = DAT_009b0318;
  fVar6 = DAT_0099d0b4;
  uVar3 = DAT_0099d080;
  fVar1 = *(float *)(*(int *)(in_ECX + 4) + 0xc);
  fVar2 = *(float *)(*(int *)(in_ECX + 4) + 0x10);
  if ((*(float *)(in_ECX + 0x10) != fVar1) || (*(float *)(in_ECX + 0x14) != fVar2)) {
    *(undefined4 *)(in_ECX + 0xfc) = DAT_009b0318;
    fVar5 = fVar2 - fVar6;
    *(float *)(in_ECX + 0x100) = fVar5;
    *(undefined4 *)(in_ECX + 0x104) = 0;
    *(undefined4 *)(in_ECX + 0x108) = uVar3;
    *(undefined4 *)(in_ECX + 0x114) = uVar4;
    *(undefined4 *)(in_ECX + 0x118) = uVar4;
    *(undefined4 *)(in_ECX + 0x11c) = 0;
    *(undefined4 *)(in_ECX + 0x120) = uVar3;
    fVar6 = fVar1 - fVar6;
    *(float *)(in_ECX + 300) = fVar6;
    *(float *)(in_ECX + 0x130) = fVar5;
    *(undefined4 *)(in_ECX + 0x134) = 0;
    *(undefined4 *)(in_ECX + 0x138) = uVar3;
    *(float *)(in_ECX + 0x144) = fVar6;
    *(undefined4 *)(in_ECX + 0x148) = uVar4;
    *(undefined4 *)(in_ECX + 0x14c) = 0;
    *(undefined4 *)(in_ECX + 0x150) = uVar3;
    *(float *)(in_ECX + 0x10) = fVar1;
    *(float *)(in_ECX + 0x14) = fVar2;
  }
  return;
}


// ==== FUN_008894f0 @ 0x008894f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008894f0(void)

{
  undefined4 uVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int in_ECX;
  float fVar7;
  float fVar8;
  
  uVar6 = _DAT_00a13628;
  uVar5 = DAT_009b0318;
  uVar1 = DAT_0099d080;
  fVar7 = *(float *)(*(int *)(in_ECX + 4) + 0xc);
  fVar8 = *(float *)(*(int *)(in_ECX + 4) + 0x10);
  *(undefined4 *)(in_ECX + 0x3c) = DAT_009b0318;
  *(undefined4 *)(in_ECX + 0x40) = uVar5;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = uVar1;
  *(undefined4 *)(in_ECX + 0x58) = uVar6;
  *(undefined4 *)(in_ECX + 0x5c) = uVar5;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  uVar4 = DAT_009a09bc;
  *(undefined4 *)(in_ECX + 100) = uVar1;
  *(undefined4 *)(in_ECX + 0x74) = uVar5;
  *(undefined4 *)(in_ECX + 0x78) = uVar6;
  *(undefined4 *)(in_ECX + 0x7c) = 0;
  *(undefined4 *)(in_ECX + 0x80) = uVar1;
  *(undefined4 *)(in_ECX + 0x90) = uVar6;
  uVar3 = DAT_0099d0dc;
  *(undefined4 *)(in_ECX + 0x94) = uVar6;
  *(undefined4 *)(in_ECX + 0x98) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x68) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x84) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xa0) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x9c) = uVar1;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x6c) = uVar1;
  *(undefined4 *)(in_ECX + 0x70) = 0;
  *(undefined4 *)(in_ECX + 0x88) = 0;
  *(undefined4 *)(in_ECX + 0x8c) = uVar1;
  *(undefined4 *)(in_ECX + 0xa4) = uVar1;
  *(undefined4 *)(in_ECX + 0xa8) = uVar1;
  *(undefined4 *)(in_ECX + 0xac) = uVar3;
  *(undefined4 *)(in_ECX + 0xb0) = uVar1;
  *(undefined4 *)(in_ECX + 0xb4) = uVar4;
  *(undefined4 *)(in_ECX + 0xb8) = 0;
  *(undefined4 *)(in_ECX + 0xbc) = 0;
  *(undefined4 *)(in_ECX + 0xc0) = uVar1;
  *(undefined4 *)(in_ECX + 0xc4) = uVar1;
  *(undefined4 *)(in_ECX + 200) = uVar4;
  *(undefined4 *)(in_ECX + 0xcc) = uVar1;
  *(undefined4 *)(in_ECX + 0xd0) = 0;
  *(undefined4 *)(in_ECX + 0xd4) = uVar1;
  *(undefined4 *)(in_ECX + 0xd8) = uVar3;
  *(undefined4 *)(in_ECX + 0xdc) = uVar4;
  *(undefined4 *)(in_ECX + 0xe0) = uVar1;
  *(undefined4 *)(in_ECX + 0xe4) = uVar1;
  *(undefined4 *)(in_ECX + 0xe8) = uVar3;
  fVar2 = DAT_0099d0b4;
  *(undefined4 *)(in_ECX + 0xec) = uVar3;
  *(undefined4 *)(in_ECX + 0xf0) = uVar4;
  *(undefined4 *)(in_ECX + 0xf4) = 0;
  *(undefined4 *)(in_ECX + 0xf8) = uVar1;
  *(undefined4 *)(in_ECX + 0xfc) = uVar5;
  fVar8 = fVar8 - fVar2;
  *(float *)(in_ECX + 0x100) = fVar8;
  *(undefined4 *)(in_ECX + 0x104) = 0;
  *(undefined4 *)(in_ECX + 0x108) = uVar1;
  *(undefined4 *)(in_ECX + 0x10c) = 0;
  *(undefined4 *)(in_ECX + 0x110) = uVar1;
  *(undefined4 *)(in_ECX + 0x114) = uVar5;
  *(undefined4 *)(in_ECX + 0x118) = uVar5;
  *(undefined4 *)(in_ECX + 0x11c) = 0;
  *(undefined4 *)(in_ECX + 0x120) = uVar1;
  *(undefined4 *)(in_ECX + 0x124) = 0;
  *(undefined4 *)(in_ECX + 0x128) = 0;
  fVar7 = fVar7 - fVar2;
  *(float *)(in_ECX + 300) = fVar7;
  *(float *)(in_ECX + 0x130) = fVar8;
  *(undefined4 *)(in_ECX + 0x134) = 0;
  *(undefined4 *)(in_ECX + 0x138) = uVar1;
  *(undefined4 *)(in_ECX + 0x13c) = uVar1;
  *(undefined4 *)(in_ECX + 0x140) = uVar1;
  *(float *)(in_ECX + 0x144) = fVar7;
  *(undefined4 *)(in_ECX + 0x148) = uVar5;
  *(undefined4 *)(in_ECX + 0x14c) = 0;
  *(undefined4 *)(in_ECX + 0x150) = uVar1;
  *(undefined4 *)(in_ECX + 0x154) = uVar1;
  *(undefined4 *)(in_ECX + 0x158) = 0;
  return;
}


// ==== FUN_00889930 @ 0x00889930 ====

void FUN_00889930(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int in_ECX;
  int *piVar4;
  
  piVar4 = (int *)**(int **)(in_ECX + 0x34);
  if (piVar4 != *(int **)(in_ECX + 0x34)) {
    do {
      piVar2 = (int *)piVar4[4];
      if (piVar2 != (int *)0x0) {
        piVar4 = (int *)piVar2[1];
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 8))(piVar4);
          piVar2[1] = 0;
        }
        piVar4 = (int *)*piVar2;
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 8))(piVar4);
          *piVar2 = 0;
        }
        _free(piVar2);
        return;
      }
      if (*(char *)((int)piVar4 + 0x15) == '\0') {
        piVar2 = (int *)piVar4[2];
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          piVar4 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x15);
            piVar4 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar4[1] + 0x15);
          piVar3 = (int *)piVar4[1];
          piVar2 = piVar4;
          while ((piVar4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar4[2]))) {
            cVar1 = *(char *)(piVar4[1] + 0x15);
            piVar3 = (int *)piVar4[1];
            piVar2 = piVar4;
          }
        }
      }
    } while (piVar4 != *(int **)(in_ECX + 0x34));
  }
  FUN_00888e60(*(undefined4 *)(*(int *)(in_ECX + 0x34) + 4));
  *(int *)(*(int *)(in_ECX + 0x34) + 4) = *(int *)(in_ECX + 0x34);
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(in_ECX + 0x34);
  *(int *)(*(int *)(in_ECX + 0x34) + 8) = *(int *)(in_ECX + 0x34);
  return;
}


// ==== FUN_008899f0 @ 0x008899f0 ====

void FUN_008899f0(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int *piVar4;
  uint uStack_34;
  int aiStack_30 [3];
  int *piStack_24;
  int *piStack_20;
  int *piStack_1c;
  undefined1 *puStack_18;
  undefined1 local_8 [4];
  int local_4;
  
  puStack_18 = (undefined1 *)0x889a05;
  piVar2 = (int *)FUN_0049b670();
  puStack_18 = local_8;
  piStack_1c = &local_4;
  local_8[0] = 1;
  piStack_20 = (int *)0x889a20;
  FUN_005c8a80();
  if (local_4 == *(int *)(in_ECX + 0x34)) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(local_4 + 0x10);
  }
  puStack_18 = *(undefined1 **)(iVar3 + 4);
  piStack_1c = (int *)0x0;
  piStack_24 = (int *)0x889a3f;
  piStack_20 = piVar2;
  (**(code **)(*piVar2 + 0x94))();
  aiStack_30[2] = 0x889a48;
  piStack_24 = piVar2;
  (**(code **)(*piVar2 + 0xa4))();
  aiStack_30[2] = 0;
  aiStack_30[1] = 0x3f800000;
  aiStack_30[0] = -0x1000000;
  uStack_34 = 3;
  (**(code **)(*piVar2 + 0xac))(piVar2,0,0);
  uStack_34 = uStack_34 & 0xffffff00;
  FUN_005c8a80(aiStack_30,&uStack_34);
  if (aiStack_30[0] == *(int *)(in_ECX + 0x34)) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(aiStack_30[0] + 0x10);
  }
  iVar3 = *(int *)(DAT_00b5ac04 + 0x28);
  iVar1 = *piVar4;
  if (*(int *)(iVar3 + 0x134) != iVar1) {
    *(int *)(iVar3 + 0x134) = iVar1;
    (**(code **)(**(int **)(iVar3 + 0x90) + 0x104))(*(int **)(iVar3 + 0x90),0,iVar1);
  }
  piVar4 = *(int **)(*(int *)(in_ECX + 0xc) + 0x1c);
  (**(code **)(*piVar4 + 0x104))(piVar4,0,0);
  piVar4 = *(int **)(*(int *)(in_ECX + 0xc) + 0x1c);
  (**(code **)(*piVar4 + 0x108))(piVar4,0);
  piVar4 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar4 + 0x14c))(piVar4,6,2,in_ECX + 0xac,0x14);
  piVar4 = *(int **)(*(int *)(in_ECX + 0xc) + 0x1c);
  (**(code **)(*piVar4 + 0x110))(piVar4);
  piVar4 = *(int **)(*(int *)(in_ECX + 0xc) + 0x1c);
  (**(code **)(*piVar4 + 0x114))(piVar4);
  (**(code **)(*piVar2 + 0xa8))(piVar2);
  return;
}


// ==== FUN_00889b30 @ 0x00889b30 ====

void FUN_00889b30(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  int *piVar4;
  undefined1 local_8 [4];
  int local_4;
  
  piVar3 = (int *)FUN_0049b670();
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if ((((*(int *)(iVar1 + 0x114) != 2) || (*(int *)(iVar1 + 0x118) != 2)) ||
      (*(int *)(iVar1 + 0x11c) != 2)) && (*(int *)(iVar1 + 100) == 0)) {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,2);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,2);
    *(undefined4 *)(iVar1 + 0x114) = 2;
    *(undefined4 *)(iVar1 + 0x118) = 2;
    *(undefined4 *)(iVar1 + 0x11c) = 2;
  }
  local_8[0] = 1;
  FUN_005c8a80(&local_4,local_8);
  if (local_4 == *(int *)(in_ECX + 0x34)) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(local_4 + 0x10);
  }
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  iVar2 = *piVar4;
  if (*(int *)(iVar1 + 0x134) != iVar2) {
    *(int *)(iVar1 + 0x134) = iVar2;
    (**(code **)(**(int **)(iVar1 + 0x90) + 0x104))(*(int **)(iVar1 + 0x90),0,iVar2);
  }
  (**(code **)(*piVar3 + 0x164))(piVar3,0x104);
  piVar4 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar4 + 0x14c))(piVar4,5,2,in_ECX + 0xfc,0x18);
  (**(code **)(*piVar3 + 0x164))(piVar3,0);
  return;
}


// ==== FUN_00889ca0 @ 0x00889ca0 ====

void FUN_00889ca0(undefined1 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  char cVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_005c8a80(&local_4,&param_1);
  if ((local_4 != *(int *)(in_ECX + 0x34)) &&
     (piVar1 = *(int **)(local_4 + 0x10), piVar1 != (int *)0x0)) {
    piVar6 = (int *)FUN_0049b670();
    iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
    iVar3 = *piVar1;
    if (*(int *)(iVar2 + 0x134) != iVar3) {
      *(int *)(iVar2 + 0x134) = iVar3;
      (**(code **)(**(int **)(iVar2 + 0x90) + 0x104))(*(int **)(iVar2 + 0x90),0,iVar3);
    }
    piVar1 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
    cVar5 = FUN_00881000(0x1c,0x70);
    if (cVar5 == '\0') {
      (**(code **)(*piVar1 + 0xc))();
    }
    uVar7 = (**(code **)(*piVar1 + 0x1c))(0x1c,0x70);
    (**(code **)(*piVar1 + 0x14))(0x70,in_ECX + 0x3c);
    FUN_00881060();
    (**(code **)(*piVar6 + 0x164))(piVar6,0x144);
    piVar4 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar4 + 400))(piVar4,0,piVar1[1],0,0x1c);
    piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar1 + 0x144))(piVar1,5,uVar7,2);
    (**(code **)(*piVar6 + 0x164))(piVar6,0);
  }
  return;
}


// ==== FUN_00889dc0 @ 0x00889dc0 ====

undefined4 FUN_00889dc0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_18;
  undefined1 local_14 [20];
  
  iVar1 = FUN_0049b670();
  if (iVar1 == 0) {
    return 0;
  }
  FUN_008560c0(&local_18,local_14);
  puVar2 = operator_new(8);
  iVar1 = FUN_008a0665(iVar1,param_2,param_2,1,1,local_18,0,puVar2);
  if (iVar1 < 0) {
    return 0;
  }
  (**(code **)(*(int *)*puVar2 + 0x48))((int *)*puVar2,0,puVar2 + 1);
  local_18 = puVar2;
  FUN_00889270(local_14,local_14 + -8);
  return 1;
}


// ==== FUN_00889e70 @ 0x00889e70 ====

void FUN_00889e70(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 uVar4;
  uint uStack_38;
  int *piStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int *piStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int *piStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (*(char *)(*(int *)(in_ECX + 4) + 8) == '\0') {
    if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x7f) == '\0') {
      *(undefined4 *)(in_ECX + 0x18) = DAT_009b6df8;
      uVar4 = DAT_00a14cb0;
    }
    else {
      *(undefined4 *)(in_ECX + 0x18) = DAT_00a14cb8;
      uVar4 = DAT_00a14cb4;
    }
  }
  else if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x7f) == '\0') {
    *(undefined4 *)(in_ECX + 0x18) = DAT_0099d080;
    uVar4 = DAT_009c1cac;
  }
  else {
    *(undefined4 *)(in_ECX + 0x18) = DAT_00a14cac;
    uVar4 = DAT_009bf3cc;
  }
  iVar1 = *(int *)(in_ECX + 0xc);
  *(undefined4 *)(in_ECX + 0x1c) = uVar4;
  iVar2 = *(int *)(iVar1 + 0x28);
  uStack_14 = *(undefined4 *)(in_ECX + 0x18);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x81)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_18 = *(undefined4 *)(iVar2 + 0x200);
  piStack_1c = *(int **)(iVar1 + 0x1c);
  uStack_20 = 0x889f3e;
  (**(code **)(*piStack_1c + 0x78))();
  iVar1 = *(int *)(in_ECX + 0xc);
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x82)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_24 = *(undefined4 *)(iVar2 + 0x204);
  piStack_28 = *(int **)(iVar1 + 0x1c);
  uStack_2c = 0x889f80;
  uStack_20 = *(undefined4 *)(in_ECX + 0x24);
  (**(code **)(*piStack_28 + 0x78))();
  iVar1 = *(int *)(in_ECX + 0xc);
  iVar2 = *(int *)(iVar1 + 0x28);
  piStack_1c = *(int **)(in_ECX + 0x24);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x83)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_30 = *(undefined4 *)(iVar2 + 0x208);
  piStack_34 = *(int **)(iVar1 + 0x1c);
  uStack_38 = 0x889fc2;
  uStack_2c = piStack_1c;
  (**(code **)(*piStack_34 + 0x78))();
  iVar1 = *(int *)(in_ECX + 0xc);
  iVar2 = *(int *)(iVar1 + 0x28);
  piStack_28 = *(int **)(in_ECX + 0x1c);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x84)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_38 = (uint)piStack_28;
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0x78))
            (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar2 + 0x20c));
  uStack_38 = uStack_38 & 0xffffff00;
  FUN_005c8a80(&piStack_34,&uStack_38);
  if (piStack_34 == *(int **)(in_ECX + 0x34)) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)piStack_34[4];
  }
  iVar1 = *(int *)(in_ECX + 0xc);
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x85)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0xd0))
            (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar2 + 0x210),*puVar3);
  return;
}


// ==== FUN_0088a070 @ 0x0088a070 ====

void FUN_0088a070(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  int *piStack_1c;
  int *piStack_18;
  undefined1 local_8 [4];
  int local_4;
  
  piStack_18 = (int *)0x88a07d;
  FUN_008893a0();
  piStack_18 = (int *)0x88a08a;
  piVar2 = (int *)FUN_0049b670();
  piVar1 = DAT_00b5af70;
  if (*(char *)(in_ECX[1] + 8) == '\0') {
    piVar1 = in_ECX + 2;
    piStack_1c = (int *)0x0;
    piStack_18 = piVar1;
    (**(code **)(*piVar2 + 0x48))(piVar2,0,0);
    piStack_1c = (int *)((uint)piStack_1c & 0xffffff00);
    FUN_005c8a80(&piStack_18,&piStack_1c);
    if (piStack_18 == (int *)in_ECX[0xd]) {
      iVar3 = 0;
    }
    else {
      iVar3 = piStack_18[4];
    }
    (**(code **)(*piVar2 + 0x88))(piVar2,*piVar1,0,*(undefined4 *)(iVar3 + 4),0,2);
    piVar2 = (int *)*piVar1;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *piVar1 = 0;
    }
  }
  else {
    piStack_18 = (int *)local_8;
    piStack_1c = &local_4;
    local_8[0] = 0;
    FUN_005c8a80();
    if (local_4 == in_ECX[0xd]) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(local_4 + 0x10);
    }
    local_4 = *piVar2;
    piStack_18 = (int *)0x2;
    piStack_1c = (int *)0x0;
    uVar4 = (**(code **)(*piVar1 + 8))(0,*(undefined4 *)(iVar3 + 4));
    (**(code **)(local_4 + 0x88))(piVar2,uVar4);
  }
  iVar3 = FUN_0085e3a0(0xf);
  in_ECX[3] = iVar3;
  (**(code **)(**(int **)(iVar3 + 0x1c) + 0xf0))(*(int **)(iVar3 + 0x1c),s_TBloomLower_00a14c8c);
  (**(code **)(*in_ECX + 0x10))();
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 0x15c))(piVar1,*(undefined4 *)(in_ECX[3] + 0x20));
  FUN_008899f0();
  return;
}


// ==== FUN_0088a1b0 @ 0x0088a1b0 ====

void FUN_0088a1b0(void)

{
  float fVar1;
  int in_ECX;
  
  FUN_008894f0();
  if (*(int *)(in_ECX + 0x38) == 0) {
    fVar1 = *(float *)(in_ECX + 0x24);
    FUN_00889dc0(0,(int)ROUND(fVar1));
    FUN_00889dc0(1,(int)ROUND(fVar1));
  }
  return;
}


// ==== FUN_0088a250 @ 0x0088a250 ====

void FUN_0088a250(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a14cc0;
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  iVar2 = FUN_00888f30();
  uVar1 = DAT_009b2d80;
  in_ECX[0xd] = iVar2;
  *(undefined1 *)(iVar2 + 0x15) = 1;
  *(undefined4 *)(in_ECX[0xd] + 4) = in_ECX[0xd];
  *(undefined4 *)in_ECX[0xd] = in_ECX[0xd];
  *(undefined4 *)(in_ECX[0xd] + 8) = in_ECX[0xd];
  in_ECX[0xe] = 0;
  in_ECX[9] = uVar1;
  in_ECX[6] = DAT_009b0300;
  in_ECX[7] = DAT_009ba338;
  in_ECX[8] = 0;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  FUN_0088a1b0();
  return;
}


// ==== FUN_0088a2e0 @ 0x0088a2e0 ====

int FUN_0088a2e0(void)

{
  int in_ECX;
  
  return in_ECX + 0x18;
}


// ==== FUN_0088a2f0 @ 0x0088a2f0 ====

void FUN_0088a2f0(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_00a14cc0;
  FUN_00889930();
  FUN_008891b0(local_4,*(undefined4 *)in_ECX[0xd],(undefined4 *)in_ECX[0xd]);
  _free((void *)in_ECX[0xd]);
  return;
}


// ==== FUN_0088a350 @ 0x0088a350 ====

void FUN_0088a350(float *param_1,float param_2)

{
  float *pfVar1;
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
  
  pfVar1 = param_1 + 3;
  fVar15 = DAT_0099d0b4 - param_2 * DAT_0099d0b4;
  fVar2 = *pfVar1;
  fVar14 = param_2 * DAT_0099d0b4 + DAT_0099d0b4;
  fVar3 = *pfVar1;
  fVar4 = param_1[4];
  fVar5 = param_1[4];
  fVar6 = param_1[5];
  fVar7 = param_1[5];
  fVar8 = *param_1;
  fVar9 = *param_1;
  fVar10 = param_1[1];
  fVar11 = param_1[1];
  fVar12 = param_1[2];
  fVar13 = param_1[2];
  *param_1 = (param_1[9] - *param_1) * fVar15 + *param_1;
  param_1[1] = (param_1[10] - param_1[1]) * fVar15 + param_1[1];
  param_1[2] = (param_1[0xb] - param_1[2]) * fVar15 + param_1[2];
  *pfVar1 = (param_1[6] - param_1[3]) * fVar15 + *pfVar1;
  param_1[4] = (param_1[7] - param_1[4]) * fVar15 + param_1[4];
  param_1[5] = (param_1[8] - param_1[5]) * fVar15 + param_1[5];
  param_1[6] = (param_1[6] - fVar2) * fVar14 + fVar3;
  param_1[7] = (param_1[7] - fVar4) * fVar14 + fVar5;
  param_1[8] = (param_1[8] - fVar6) * fVar14 + fVar7;
  param_1[9] = (param_1[9] - fVar8) * fVar14 + fVar9;
  param_1[10] = (param_1[10] - fVar10) * fVar14 + fVar11;
  param_1[0xb] = (param_1[0xb] - fVar12) * fVar14 + fVar13;
  return;
}


// ==== FUN_0088a500 @ 0x0088a500 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0088a500(undefined4 param_1,int param_2,float *param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 *puVar5;
  float fVar6;
  undefined1 local_c0 [64];
  undefined1 local_80 [52];
  undefined4 auStack_4c [3];
  undefined1 local_40 [56];
  undefined4 *puStack_8;
  
  iVar4 = *(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xa0);
  iVar1 = *(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x9c);
  fVar2 = (float)iVar4;
  if (iVar4 < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  fVar2 = DAT_0099d080 / fVar2;
  fVar3 = (float)iVar1;
  if (iVar1 < 0) {
    fVar3 = fVar3 + _DAT_0099d104;
  }
  fVar6 = DAT_0099d080 / fVar3;
  thunk_FUN_0079f7f5(local_80,((((float)*(int *)(param_2 + 0x70) + *param_3) * fVar2 - DAT_0099d0b4)
                               * DAT_0099d0f8 +
                              (((float)*(int *)(param_2 + 0x6c) + *param_3) * fVar2 - DAT_0099d0b4)
                              * DAT_0099d0f8) * DAT_0099d0b4,
                     (((fVar3 - ((float)*(int *)(param_2 + 0x74) + param_3[1])) * fVar6 -
                      DAT_0099d0b4) * DAT_0099d0f8 +
                     ((fVar3 - ((float)*(int *)(param_2 + 0x78) + param_3[1])) * fVar6 -
                     DAT_0099d0b4) * DAT_0099d0f8) * DAT_0099d0b4,0x3f0ccccd);
  thunk_FUN_0079f761(local_c0,fVar2 * DAT_0099de78,fVar6 * DAT_0099de78,0x3a83126f);
  thunk_FUN_0079ee7b(local_40,local_c0,local_80);
  puVar5 = auStack_4c;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puStack_8 = *puVar5;
    puVar5 = puVar5 + 1;
    puStack_8 = puStack_8 + 1;
  }
  return;
}


// ==== FUN_0088a6a0 @ 0x0088a6a0 ====

void FUN_0088a6a0(int param_1)

{
  int iVar1;
  
  if (param_1 == 1) {
    iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
    if (((*(int *)(iVar1 + 0x114) == 2) && (*(int *)(iVar1 + 0x118) == 5)) &&
       (*(int *)(iVar1 + 0x11c) == 6)) {
      return;
    }
    if (*(int *)(iVar1 + 100) != 0) {
      return;
    }
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,6);
    *(undefined4 *)(iVar1 + 0x11c) = 6;
  }
  else {
    if (param_1 != 0) {
      return;
    }
    iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
    if (((*(int *)(iVar1 + 0x114) == 2) && (*(int *)(iVar1 + 0x118) == 5)) &&
       (*(int *)(iVar1 + 0x11c) == 2)) {
      return;
    }
    if (*(int *)(iVar1 + 100) != 0) {
      return;
    }
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,2);
    *(undefined4 *)(iVar1 + 0x11c) = 2;
  }
  *(undefined4 *)(iVar1 + 0x114) = 2;
  *(undefined4 *)(iVar1 + 0x118) = 5;
  return;
}


// ==== FUN_0088a830 @ 0x0088a830 ====

undefined4 FUN_0088a830(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar3 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x18;
  }
  piVar1 = (int *)**(undefined4 **)(DAT_00b5ac04 + 0x34);
  iVar3 = iVar3 * 0x18;
  cVar2 = FUN_00881000(0x18,iVar3);
  if (cVar2 == '\0') {
    (**(code **)(*piVar1 + 0xc))();
  }
  cVar2 = FUN_00881000(0x18,iVar3);
  if (cVar2 == '\0') {
    return 0;
  }
  uVar4 = (**(code **)(*piVar1 + 0x1c))(0x18,iVar3);
  (**(code **)(*piVar1 + 0x14))(iVar3,*(undefined4 *)(param_1 + 4));
  FUN_00881060();
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 400))(piVar1,0,*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 4),0,0x18)
  ;
  return uVar4;
}


// ==== FUN_0088a8f0 @ 0x0088a8f0 ====

undefined4 FUN_0088a8f0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14) >> 1;
  }
  iVar2 = iVar2 * 2;
  piVar1 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
  if ((uint)piVar1[7] <= (uint)(piVar1[8] + iVar2)) {
    (**(code **)(*piVar1 + 0x10))();
  }
  if ((uint)piVar1[7] <= (uint)(piVar1[8] + iVar2)) {
    return 0;
  }
  uVar3 = (**(code **)(*piVar1 + 0x20))(iVar2);
  iVar2 = *(int *)(param_1 + 0x14);
  if (iVar2 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x18) - iVar2 >> 1;
  }
  (**(code **)(*piVar1 + 0x18))(iVar4,iVar2);
  FUN_00881080();
  return uVar3;
}


// ==== FUN_0088a9b0 @ 0x0088a9b0 ====

void FUN_0088a9b0(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBX;
  uint uVar4;
  undefined4 uVar5;
  
  uVar2 = FUN_0088a830(param_2);
  FUN_0088a8f0(param_2);
  if ((*(int *)(param_2 + 0x14) != 0) &&
     (2 < (uint)(*(int *)(param_2 + 0x18) - *(int *)(param_2 + 0x14) >> 1))) {
    piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    uVar5 = 0x18;
    (**(code **)(*piVar1 + 400))
              (piVar1,0,*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 4),0,0x18);
    FUN_0084b7f0(*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 0x18));
    (**(code **)(**(int **)(unaff_EBX + 0x1c) + 0x108))(*(int **)(unaff_EBX + 0x1c),0);
    if (*(int *)(param_2 + 0x14) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(int *)(param_2 + 0x18) - *(int *)(param_2 + 0x14) >> 1;
    }
    if (*(int *)(param_2 + 4) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x18;
    }
    piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar1 + 0x148))(piVar1,4,uVar2,0,iVar3,uVar5,uVar4 / 3);
    (**(code **)(**(int **)(unaff_EBX + 0x1c) + 0x110))(*(int **)(unaff_EBX + 0x1c));
  }
  return;
}


// ==== FUN_0088aac0 @ 0x0088aac0 ====

void FUN_0088aac0(int param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  int *piVar10;
  int iVar11;
  int iStack_8;
  int local_4;
  
  if (*(int *)(param_2 + 8) != 0) {
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x104))(*(int **)(param_1 + 0x1c),&local_4,0);
    puVar2 = *(undefined4 **)(param_2 + 4);
    puVar3 = (undefined4 *)*puVar2;
    local_4 = 0;
    iVar11 = -1;
    while (puVar3 != puVar2) {
      iVar4 = puVar3[3];
      uVar5 = puVar3[5];
      if (local_4 != iVar4) {
        local_4 = iVar4;
        iVar8 = FUN_0085e3a0(7);
        uVar9 = 0;
        if (iVar4 != 0) {
          piVar10 = (int *)FUN_004af750();
          uVar9 = (**(code **)(*piVar10 + 4))();
        }
        iVar4 = *(int *)(iVar8 + 0x28);
        if ((iVar4 == 0) || ((uint)(*(int *)(iVar8 + 0x2c) - iVar4 >> 2) < 0x21)) {
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        (**(code **)(**(int **)(iVar8 + 0x1c) + 0xd0))
                  (*(int **)(iVar8 + 0x1c),*(undefined4 *)(iVar4 + 0x80),uVar9);
      }
      if (iVar11 != puVar3[4]) {
        iVar11 = puVar3[4];
        FUN_0088a6a0(iVar11);
      }
      FUN_0088a9b0(iStack_8,uVar5);
      if (*(char *)((int)puVar3 + 0x19) == '\0') {
        puVar6 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar6 + 0x19) == '\0') {
          cVar1 = *(char *)((int)*puVar6 + 0x19);
          puVar3 = puVar6;
          puVar6 = (undefined4 *)*puVar6;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar6 + 0x19);
            puVar3 = puVar6;
            puVar6 = (undefined4 *)*puVar6;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x19);
          puVar7 = (undefined4 *)puVar3[1];
          puVar6 = puVar3;
          while ((puVar3 = puVar7, cVar1 == '\0' && (puVar6 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x19);
            puVar7 = (undefined4 *)puVar3[1];
            puVar6 = puVar3;
          }
        }
      }
    }
    (**(code **)(**(int **)(iStack_8 + 0x1c) + 0x114))(*(int **)(iStack_8 + 0x1c));
  }
  return;
}


// ==== FUN_0088ac60 @ 0x0088ac60 ====

void FUN_0088ac60(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int *piStack_50;
  undefined4 uStack_4c;
  
  uStack_4c = 7;
  piStack_50 = (int *)0x88ac76;
  iVar2 = FUN_0085e3a0();
  uStack_4c = *(undefined4 *)(iVar2 + 0x20);
  piStack_50 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piStack_50 + 0x15c))();
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0xf0))(*(int **)(iVar2 + 0x1c),s_Billboard_00a14d20);
  uStack_4c = 0;
  piStack_50 = DAT_0099d080;
  iVar1 = *(int *)(iVar2 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar1 >> 2) < 0x1f)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x98))
            (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar1 + 0x78),&piStack_50);
  FUN_0088aac0(iVar2,in_ECX + 0xc,0);
  FUN_0088aac0(iVar2,in_ECX,1);
  return;
}


// ==== FUN_0088ad70 @ 0x0088ad70 ====

void FUN_0088ad70(float *param_1,int param_2,undefined4 param_3)

{
  short *psVar1;
  float in_ECX;
  int iVar2;
  short sVar3;
  float unaff_EBX;
  uint uVar4;
  float *pfVar5;
  float *pfVar6;
  float10 fVar7;
  float fVar8;
  float fVar9;
  undefined4 uStack_174;
  float **ppfStack_170;
  float **ppfStack_16c;
  float *pfStack_168;
  float **ppfStack_164;
  float *pfStack_160;
  float *pfStack_15c;
  float *local_158;
  float local_144 [3];
  float local_138;
  float local_134;
  float *local_130;
  float *pfStack_12c;
  float *pfStack_124;
  float local_120;
  float local_11c;
  float *local_118;
  float *local_114;
  float local_110;
  undefined4 uStack_10c;
  float *pfStack_108;
  float fStack_fc;
  float fStack_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float *local_e8;
  float local_e4;
  float local_e0;
  float *local_dc;
  float local_d8;
  float local_d4;
  float *local_d0;
  float local_cc [2];
  float *local_c4;
  float local_c0 [7];
  undefined1 auStack_a4 [12];
  undefined1 auStack_98 [12];
  undefined1 auStack_8c [12];
  undefined1 auStack_80 [52];
  float afStack_4c [19];
  
  fVar9 = 0.0;
  local_110 = param_1[4] * DAT_0099d0b4;
  local_144[2] = param_1[5] * DAT_0099d0b4;
  fVar8 = local_144[2];
  local_144[0] = in_ECX;
  if (param_1[7] != 0.0) {
    local_158 = (float *)param_1[7];
    pfStack_15c = (float *)0x88adca;
    fVar7 = (float10)FUN_0040d4d0();
    pfStack_15c = (float *)param_1[7];
    local_120 = (float)(fVar7 * (float10)local_144[2]);
    pfStack_160 = (float *)0x88addb;
    fVar7 = (float10)FUN_0040d4c0();
    fVar9 = (float)(fVar7 * (float10)local_144[2]);
    fVar8 = local_120;
    local_f4 = fVar9;
  }
  pfStack_160 = (float *)*param_1;
  pfStack_15c = (float *)param_1[1];
  local_114 = (float *)param_1[2];
  if (*(char *)(param_1 + 10) != '\0') {
    local_114 = (float *)((float)local_114 + local_144[2]);
  }
  local_11c = (float)pfStack_160;
  local_118 = pfStack_15c;
  if (*(char *)((int)param_1 + 0x29) == '\0') {
    local_f0 = ((float)pfStack_160 - fVar8) + fVar9;
    local_e4 = ((float)pfStack_160 - fVar8) - fVar9;
    local_ec = ((float)pfStack_15c - fVar9) - fVar8;
    local_d8 = ((float)pfStack_160 + fVar8) - fVar9;
    local_e0 = ((float)pfStack_15c - fVar9) + fVar8;
    local_d4 = (float)pfStack_15c + fVar9 + fVar8;
    local_138 = (float)pfStack_160 + fVar9 + fVar8;
    local_134 = ((float)pfStack_15c + fVar9) - fVar8;
    local_130 = local_114;
    local_e8 = local_114;
    local_dc = local_114;
    local_d0 = local_114;
    local_cc[0] = local_138;
    local_cc[1] = local_134;
    local_c4 = local_114;
  }
  else {
    local_158 = local_114;
    ppfStack_164 = (float **)(afStack_4c + 3);
    pfStack_168 = (float *)0x88ae42;
    thunk_FUN_0079f7f5();
    pfVar5 = afStack_4c + 3;
    pfVar6 = local_cc + 3;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *pfVar6 = *pfVar5;
      pfVar5 = pfVar5 + 1;
      pfVar6 = pfVar6 + 1;
    }
    local_158 = local_cc + 3;
    pfStack_15c = param_1 + 0xb;
    pfStack_160 = afStack_4c + 3;
    ppfStack_164 = (float **)0x88ae70;
    thunk_FUN_0079ee7b();
    pfVar5 = afStack_4c;
    pfVar6 = local_cc;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *pfVar6 = *pfVar5;
      pfVar5 = pfVar5 + 1;
      pfVar6 = pfVar6 + 1;
    }
    ppfStack_164 = (float **)local_cc;
    pfStack_168 = local_144;
    ppfStack_16c = (float **)&fStack_fc;
    local_144[0] = 0.0 - unaff_EBX;
    local_144[1] = 0.0;
    ppfStack_170 = (float **)0x88aec0;
    local_144[2] = local_144[0];
    pfStack_12c = (float *)local_144[0];
    thunk_FUN_0079e5a0();
    fVar9 = local_138;
    ppfStack_170 = (float **)&local_d8;
    uStack_174 = local_144 + -3;
    thunk_FUN_0079e5a0(&fStack_fc);
    pfStack_15c = pfStack_160;
    local_158 = (float *)0x0;
    thunk_FUN_0079e5a0(&fStack_fc,&pfStack_15c,&local_e4);
    pfStack_168 = (float *)ppfStack_16c;
    ppfStack_164 = (float **)0x0;
    pfStack_160 = (float *)fVar9;
    thunk_FUN_0079e5a0(&fStack_fc,&pfStack_168,&local_f0);
  }
  if (local_110 != local_144[2]) {
    local_158 = (float *)(local_110 / local_144[2]);
    pfStack_15c = &local_f0;
    pfStack_160 = (float *)0x88b0a4;
    FUN_0088a350();
  }
  if (*(int *)(param_2 + 4) == 0) {
    sVar3 = 0;
  }
  else {
    sVar3 = (short)((*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x18);
  }
  fStack_f8 = param_1[6];
  local_158 = (float *)param_3;
  pfStack_15c = param_1;
  pfStack_160 = (float *)auStack_80;
  ppfStack_164 = (float **)0x88b0ef;
  FUN_0088a500();
  local_158 = (float *)auStack_80;
  pfStack_15c = &local_f0;
  pfStack_160 = (float *)&uStack_10c;
  ppfStack_164 = (float **)0x88b106;
  thunk_FUN_0079e5a0();
  ppfStack_164 = &local_118;
  uStack_10c = 0;
  pfStack_108 = DAT_0099d080;
  pfStack_168 = (float *)0x88b139;
  FUN_0085e470();
  ppfStack_164 = (float **)auStack_8c;
  pfStack_168 = &local_f0;
  ppfStack_16c = &local_118;
  ppfStack_170 = (float **)0x88b150;
  thunk_FUN_0079e5a0();
  ppfStack_170 = &pfStack_124;
  pfStack_15c = (float *)0x0;
  local_158 = (float *)0x0;
  local_118 = (float *)0x0;
  local_114 = (float *)0x0;
  uStack_174 = (float *)0x88b17b;
  FUN_0085e470();
  ppfStack_170 = (float **)auStack_98;
  uStack_174 = &local_f0;
  thunk_FUN_0079e5a0(&pfStack_124);
  pfStack_168 = DAT_0099d080;
  ppfStack_164 = (float **)0x0;
  pfStack_124 = DAT_0099d080;
  local_120 = 0.0;
  FUN_0085e470(&local_130);
  thunk_FUN_0079e5a0(&local_130,&local_f0,auStack_a4);
  uStack_174 = DAT_0099d080;
  ppfStack_170 = (float **)DAT_0099d080;
  local_130 = DAT_0099d080;
  pfStack_12c = DAT_0099d080;
  FUN_0085e470(local_144 + 2);
  uVar4 = 0;
  pfStack_168 = (float *)0x10000;
  ppfStack_164 = (float **)0x2;
  pfStack_160 = (float *)0x30002;
  pfStack_15c = (float *)0x20003;
  local_158 = (float *)0x20000;
  do {
    iVar2 = *(int *)(param_2 + 0x14);
    uStack_174._0_2_ = *(short *)((int)local_144 + uVar4 * 2 + -0x24) + sVar3;
    if ((iVar2 == 0) ||
       ((uint)(*(int *)(param_2 + 0x1c) - iVar2 >> 1) <=
        (uint)(*(int *)(param_2 + 0x18) - iVar2 >> 1))) {
      uStack_174._2_2_ = 0;
      FUN_00427290(*(undefined4 *)(param_2 + 0x18),1,&uStack_174);
    }
    else {
      psVar1 = *(short **)(param_2 + 0x18);
      *psVar1 = (short)uStack_174;
      *(short **)(param_2 + 0x18) = psVar1 + 1;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 6);
  return;
}


// ==== FUN_0088b2d0 @ 0x0088b2d0 ====

void FUN_0088b2d0(void)

{
  uint in_ECX;
  uint local_4;
  
  local_4 = in_ECX;
  if (*(int *)(in_ECX + 0x14) != 0) {
    local_4 = in_ECX & 0xffffff00;
    FUN_0088b8a0(**(undefined4 **)(in_ECX + 0x10),*(undefined4 **)(in_ECX + 0x10),local_4);
    FUN_008735f0(*(undefined4 *)(*(int *)(in_ECX + 0x10) + 4));
    *(int *)(*(int *)(in_ECX + 0x10) + 4) = *(int *)(in_ECX + 0x10);
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x10);
    *(int *)(*(int *)(in_ECX + 0x10) + 8) = *(int *)(in_ECX + 0x10);
  }
  if (*(int *)(in_ECX + 8) != 0) {
    local_4 = local_4 & 0xffffff00;
    FUN_0088b8a0(**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4),local_4);
    FUN_008735f0(*(undefined4 *)(*(int *)(in_ECX + 4) + 4));
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  }
  return;
}


// ==== FUN_0088b360 @ 0x0088b360 ====

void FUN_0088b360(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  void *pvVar5;
  int local_1c [2];
  uint local_14;
  int local_10;
  uint local_c;
  int local_8;
  void *local_4;
  
  iVar3 = param_2;
  uVar1 = *(uint *)(param_1 + 0xc);
  iVar2 = *(int *)(param_1 + 0x24);
  local_14 = uVar1;
  local_10 = iVar2;
  param_2 = FUN_0088b520(&local_14);
  iVar3 = *(int *)(iVar3 + 4);
  if (((param_2 == iVar3) || (uVar1 < *(uint *)(param_2 + 0xc))) ||
     ((uVar1 <= *(uint *)(param_2 + 0xc) && (iVar2 < *(int *)(param_2 + 0x10))))) {
    local_1c[0] = iVar3;
    piVar4 = local_1c;
  }
  else {
    piVar4 = &param_2;
  }
  if (*piVar4 == iVar3) {
    pvVar5 = operator_new(0x20);
    if (pvVar5 == (void *)0x0) {
      pvVar5 = (void *)0x0;
    }
    else {
      *(undefined4 *)((int)pvVar5 + 4) = 0;
      *(undefined4 *)((int)pvVar5 + 8) = 0;
      *(undefined4 *)((int)pvVar5 + 0xc) = 0;
      *(undefined4 *)((int)pvVar5 + 0x14) = 0;
      *(undefined4 *)((int)pvVar5 + 0x18) = 0;
      *(undefined4 *)((int)pvVar5 + 0x1c) = 0;
      FUN_0085de00(0x40);
      FUN_004271c0(0x80);
    }
    local_8 = local_10;
    local_c = uVar1;
    local_4 = pvVar5;
    FUN_0088b7d0(&local_14,&local_c);
  }
  else {
    pvVar5 = *(void **)(*piVar4 + 0x14);
  }
  FUN_0088ad70(param_1,pvVar5,param_3);
  return;
}


// ==== FUN_0088b440 @ 0x0088b440 ====

void FUN_0088b440(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_0088b2d0();
  FUN_00873740(local_4,**(undefined4 **)(in_ECX + 0x10),*(undefined4 **)(in_ECX + 0x10));
  _free(*(void **)(in_ECX + 0x10));
  return;
}


// ==== FUN_0088b4a0 @ 0x0088b4a0 ====

void FUN_0088b4a0(int param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  for (iVar2 = *(int *)(param_1 + 4); iVar2 != iVar1; iVar2 = iVar2 + 0x7c) {
    if ((*(int *)(iVar2 + 0x20) == 3) && (*(char *)(iVar2 + 0x29) == '\0')) {
      iVar3 = in_ECX + 0xc;
    }
    else {
      iVar3 = in_ECX;
    }
    FUN_0088b360(iVar2,iVar3,param_2);
  }
  return;
}


// ==== FUN_0088b4f0 @ 0x0088b4f0 ====

void FUN_0088b4f0(int param_1)

{
  float local_8;
  float local_4;
  
  local_8 = (float)*(int *)(param_1 + 0x14);
  local_4 = (float)*(int *)(param_1 + 0x18);
  FUN_0088b4a0(param_1 + 100,&local_8);
  return;
}


// ==== FUN_0088b520 @ 0x0088b520 ====

undefined4 * FUN_0088b520(uint *param_1)

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
      if (((uint)puVar2[3] < *param_1) ||
         (((uint)puVar2[3] <= *param_1 && ((int)puVar2[4] < (int)param_1[1])))) {
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


// ==== FUN_0088b560 @ 0x0088b560 ====

void * FUN_0088b560(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a780;
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


// ==== Catch@0088b5d5 @ 0x0088b5d5 ====

void Catch_0088b5d5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0088b5f0 @ 0x0088b5f0 ====

void FUN_0088b5f0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_0088b560(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_0088b6f5:
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
      if ((char)piVar6[6] == '\0') goto LAB_0088b6f5;
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


// ==== FUN_0088b7d0 @ 0x0088b7d0 ====

void FUN_0088b7d0(undefined4 *param_1,uint *param_2)

{
  bool bVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 local_4;
  
  puVar2 = param_2;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  bVar1 = true;
  local_4 = 1;
  if (*(char *)((int)puVar4[1] + 0x19) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      if ((*param_2 < (uint)puVar4[3]) ||
         ((*param_2 <= (uint)puVar4[3] && ((int)param_2[1] < (int)puVar4[4])))) {
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
      goto LAB_0088b825;
    }
    FUN_004b83a0();
  }
  if ((*puVar2 <= param_2[3]) && ((*puVar2 < param_2[3] || ((int)puVar2[1] <= (int)param_2[4])))) {
    *param_1 = param_2;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_0088b825:
  puVar4 = (undefined4 *)FUN_0088b5f0(&param_2,local_4,puVar4,puVar2);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_0088b8a0 @ 0x0088b8a0 ====

uint FUN_0088b8a0(int *param_1,int *param_2,byte param_3)

{
  char cVar1;
  void *_Memory;
  int *piVar2;
  int *piVar3;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  
  while( true ) {
    if (param_1 == param_2) {
      return (uint)param_3;
    }
    _Memory = (void *)param_1[5];
    if (_Memory != (void *)0x0) break;
    if (*(char *)((int)param_1 + 0x19) == '\0') {
      piVar2 = (int *)param_1[2];
      if (*(char *)((int)piVar2 + 0x19) == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x19);
        param_1 = piVar2;
        piVar2 = (int *)*piVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x19);
          param_1 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(param_1[1] + 0x19);
        piVar3 = (int *)param_1[1];
        piVar2 = param_1;
        while ((param_1 = piVar3, cVar1 == '\0' && (piVar2 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x19);
          piVar3 = (int *)param_1[1];
          piVar2 = param_1;
        }
      }
    }
  }
  if (*(void **)((int)_Memory + 0x14) != (void *)0x0) {
    _free(*(void **)((int)_Memory + 0x14));
    return extraout_EAX;
  }
  *(undefined4 *)((int)_Memory + 0x14) = 0;
  *(undefined4 *)((int)_Memory + 0x18) = 0;
  *(undefined4 *)((int)_Memory + 0x1c) = 0;
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


// ==== FUN_0088b950 @ 0x0088b950 ====

void FUN_0088b950(void)

{
  FUN_0081d670();
  return;
}


// ==== FUN_0088b9e0 @ 0x0088b9e0 ====

void FUN_0088b9e0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  FUN_0081d760();
  uVar2 = DAT_009c1cac;
  uVar1 = DAT_0099d0b4;
  in_ECX[1] = DAT_0099d0b4;
  in_ECX[2] = uVar2;
  in_ECX[3] = uVar1;
  in_ECX[8] = 0;
  *in_ECX = 0;
  FUN_0081d790();
  return;
}


// ==== FUN_0088ba50 @ 0x0088ba50 ====

void FUN_0088ba50(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char unaff_SI;
  
  if (param_1 != 0) {
    cVar1 = FUN_0084be00(param_1);
    if (cVar1 != '\0') {
      iVar3 = *(int *)(DAT_00b5ac04 + 0x28);
      if ((((*(int *)(iVar3 + 0x114) != 2) || (*(int *)(iVar3 + 0x118) != 5)) ||
          (*(int *)(iVar3 + 0x11c) != 2)) && (*(int *)(iVar3 + 100) == 0)) {
        (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0x1b,1);
        (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0xf,1);
        (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0x19,5);
        (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0x18,1);
        (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0x13,5);
        (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0x14,2);
        *(undefined4 *)(iVar3 + 0x114) = 2;
        *(undefined4 *)(iVar3 + 0x118) = 5;
        *(undefined4 *)(iVar3 + 0x11c) = 2;
      }
      piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
      (**(code **)(*piVar2 + 0xe4))(piVar2,0xe,0);
      return;
    }
    piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar2 + 0xe4))(piVar2,0xe,1);
    if (unaff_SI == '\0') {
      piVar2 = (int *)FUN_004af750();
      iVar3 = (**(code **)(*piVar2 + 0x10))();
      if (iVar3 == 1) {
        FUN_00848e90(1,5,6);
        return;
      }
      iVar3 = *(int *)(DAT_00b5ac04 + 0x28);
      if (((*(int *)(iVar3 + 0x114) == 2) && (*(int *)(iVar3 + 0x118) == 5)) &&
         (*(int *)(iVar3 + 0x11c) == 6)) {
        return;
      }
      if (*(int *)(iVar3 + 100) != 0) {
        return;
      }
      (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0x1b,1);
      (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0xf,1);
      (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0x19,5);
      (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0x18,1);
      (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0x13,5);
      (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0x14,6);
    }
    else {
      iVar3 = *(int *)(DAT_00b5ac04 + 0x28);
      if (((*(int *)(iVar3 + 0x114) == 2) && (*(int *)(iVar3 + 0x118) == 5)) &&
         (*(int *)(iVar3 + 0x11c) == 6)) {
        return;
      }
      if (*(int *)(iVar3 + 100) != 0) {
        return;
      }
      (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0x1b,1);
      (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0xf,1);
      (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0x19,5);
      (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0x18,1);
      (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0x13,5);
      (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0x14,6);
    }
    *(undefined4 *)(iVar3 + 0x114) = 2;
    *(undefined4 *)(iVar3 + 0x118) = 5;
    *(undefined4 *)(iVar3 + 0x11c) = 6;
  }
  return;
}


// ==== FUN_0088bd20 @ 0x0088bd20 ====

void FUN_0088bd20(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  int unaff_ESI;
  int *piVar6;
  int iVar7;
  uint unaff_retaddr;
  undefined4 *puVar8;
  undefined4 uVar9;
  uint local_4;
  
  iVar1 = *(int *)(param_1 + 0x68);
  piVar6 = *(int **)(*(int *)(in_ECX + 0x20) + 0x1c);
  iVar5 = 0;
  uVar9 = 0;
  puVar8 = &param_3;
  (**(code **)(*piVar6 + 0x104))(piVar6,puVar8,0);
  local_4 = 0;
  if (unaff_retaddr != 0) {
    while( true ) {
      piVar6 = *(int **)(*(int *)(in_ECX + 0x20) + 0x1c);
      (**(code **)(*piVar6 + 0x108))(piVar6,local_4);
      iVar7 = *(int *)(param_1 + 0x2c);
      iVar2 = *(int *)(param_1 + 0x30);
      if (iVar7 != iVar2) {
        piVar6 = (int *)(iVar7 + 0x18);
        do {
          piVar3 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
          (**(code **)(*piVar3 + 0x148))
                    (piVar3,piVar6[-5],uVar9,piVar6[-4],piVar6[-3],(int)puVar8 + iVar5,piVar6[-2]);
          if (*piVar6 == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = piVar6[1] - *piVar6 >> 1;
          }
          iVar7 = iVar7 + 0x24;
          iVar5 = iVar5 + iVar4;
          piVar6 = piVar6 + 9;
        } while (iVar7 != iVar2);
        in_ECX = unaff_ESI;
      }
      piVar6 = *(int **)(*(int *)(in_ECX + 0x20) + 0x1c);
      (**(code **)(*piVar6 + 0x110))(piVar6);
      local_4 = local_4 + 1;
      if (unaff_retaddr <= local_4) break;
      param_1 = iVar1 + param_2;
    }
  }
  piVar6 = *(int **)(*(int *)(in_ECX + 0x20) + 0x1c);
  (**(code **)(*piVar6 + 0x114))(piVar6);
  return;
}


// ==== FUN_0088be30 @ 0x0088be30 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0088be30(int param_1,int param_2,undefined4 *param_3)

{
  float fVar1;
  undefined4 uVar2;
  int *in_ECX;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  float fVar7;
  undefined4 uStack_274;
  undefined1 **ppuStack_270;
  undefined4 uStack_26c;
  int *piStack_268;
  float fStack_264;
  int **ppiStack_260;
  float fStack_25c;
  int *piStack_258;
  undefined4 uStack_254;
  undefined4 *puStack_250;
  undefined4 uStack_24c;
  undefined4 **ppuStack_248;
  int *piStack_244;
  int *piStack_240;
  int *piStack_23c;
  int *piStack_238;
  undefined1 *puStack_234;
  undefined1 *puStack_230;
  undefined4 uStack_22c;
  undefined1 *puStack_228;
  int *piStack_224;
  undefined4 uStack_220;
  undefined4 *puStack_21c;
  undefined1 *puStack_218;
  undefined4 *puStack_214;
  undefined1 *puStack_210;
  undefined1 *puStack_20c;
  undefined4 *puStack_208;
  undefined4 uStack_204;
  undefined1 auStack_1e4 [8];
  float local_1dc;
  undefined4 auStack_1d8 [10];
  undefined1 auStack_1b0 [24];
  undefined4 auStack_198 [3];
  undefined1 auStack_18c [64];
  undefined1 auStack_14c [12];
  undefined1 local_140 [52];
  undefined4 auStack_10c [16];
  undefined4 auStack_cc [3];
  undefined1 local_c0 [64];
  undefined1 local_80 [4];
  undefined1 auStack_7c [24];
  undefined1 auStack_64 [100];
  
  iVar3 = *(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xa0);
  iVar4 = *(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x9c);
  local_1dc = (float)iVar3;
  if (iVar3 < 0) {
    local_1dc = local_1dc + _DAT_0099d104;
  }
  local_1dc = DAT_0099d080 / local_1dc;
  fVar1 = (float)iVar4;
  if (iVar4 < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  fVar7 = DAT_0099d080 / fVar1;
  puStack_208 = (undefined4 *)
                ((((fVar1 - (float)(param_3[4] + param_2)) * fVar7 - DAT_0099d0b4) * DAT_0099d0f8 +
                 ((fVar1 - (float)(param_3[3] + param_2)) * fVar7 - DAT_0099d0b4) * DAT_0099d0f8) *
                DAT_0099d0b4);
  uStack_204 = (undefined1 *)0x3f000000;
  puStack_20c = (undefined1 *)
                ((((float)(param_3[2] + param_1) * local_1dc - DAT_0099d0b4) * DAT_0099d0f8 +
                 ((float)(param_3[1] + param_1) * local_1dc - DAT_0099d0b4) * DAT_0099d0f8) *
                DAT_0099d0b4);
  puStack_210 = local_140;
  puStack_214 = (undefined4 *)0x88bf5c;
  thunk_FUN_0079f7f5();
  uStack_204 = (undefined1 *)0x3a83126f;
  puStack_20c = (undefined1 *)local_1dc;
  puStack_210 = local_80;
  puStack_214 = (undefined4 *)0x88bf78;
  puStack_208 = (undefined4 *)fVar7;
  thunk_FUN_0079f761();
  uStack_204 = local_80;
  puStack_208 = param_3 + 6;
  puStack_20c = local_c0;
  puStack_210 = (undefined1 *)0x88bf91;
  thunk_FUN_0079ee7b();
  puStack_210 = auStack_14c;
  puStack_214 = auStack_10c;
  puVar5 = auStack_cc;
  puVar6 = auStack_10c;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  puStack_218 = auStack_18c;
  puStack_21c = (undefined4 *)0x88bfc3;
  thunk_FUN_0079ee7b();
  iVar3 = in_ECX[8];
  puVar5 = auStack_198;
  puVar6 = auStack_1d8;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar4 = *(int *)(iVar3 + 0x28);
  if ((iVar4 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - iVar4 >> 2) < 0x6e)) {
                    /* WARNING: Subroutine does not return */
    puStack_21c = (undefined4 *)0x88bff4;
    FUN_0085b340();
  }
  uStack_220 = *(undefined4 *)(iVar4 + 0x1b4);
  piStack_224 = *(int **)(iVar3 + 0x1c);
  puStack_21c = auStack_1d8;
  puStack_228 = (undefined1 *)0x88c00c;
  (**(code **)(*piStack_224 + 0x98))();
  puStack_228 = (undefined1 *)0x88c017;
  iVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  if (100 < (uint)(iVar3 - *in_ECX)) {
    puStack_228 = (undefined1 *)(DAT_00b52aac * DAT_009c3038);
    uStack_22c = 0x88c040;
    FUN_0081d8f0();
    puStack_228 = (undefined1 *)(DAT_00b52aac * DAT_009c3038);
    uStack_22c = 0x88c05d;
    FUN_0081d990();
    *in_ECX = iVar3;
  }
  puStack_228 = auStack_1e4;
  uStack_22c = 0;
  puStack_230 = auStack_64;
  puStack_234 = (undefined1 *)0x88c073;
  thunk_FUN_0079f3a1();
  puStack_234 = auStack_1b0;
  piStack_238 = (int *)0x88c083;
  puStack_234 = (undefined1 *)FUN_0081d830();
  piStack_23c = (int *)(auStack_1e4 + -0x18);
  piStack_240 = (int *)0x88c092;
  piStack_238 = in_ECX + 1;
  thunk_FUN_0079e6b3();
  piStack_240 = (int *)auStack_7c;
  ppuStack_248 = &puStack_214;
  uStack_24c = 0x88c0a5;
  piStack_244 = in_ECX + 1;
  thunk_FUN_0079e6b3();
  iVar3 = in_ECX[8];
  iVar4 = *(int *)(iVar3 + 0x28);
  if ((iVar4 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - iVar4 >> 2) < 0x70)) {
                    /* WARNING: Subroutine does not return */
    uStack_24c = 0x88c0c4;
    FUN_0085b340();
  }
  uStack_254 = *(undefined4 *)(iVar4 + 0x1bc);
  piStack_258 = *(int **)(iVar3 + 0x1c);
  uStack_24c = 3;
  puStack_250 = &uStack_220;
  fStack_25c = 1.2558815e-38;
  (**(code **)(*piStack_258 + 0x80))();
  iVar3 = in_ECX[8];
  piStack_244 = DAT_009b2dbc;
  piStack_240 = DAT_009b2dbc;
  piStack_23c = DAT_009b2dbc;
  iVar4 = *(int *)(iVar3 + 0x28);
  if ((iVar4 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - iVar4 >> 2) < 0x72)) {
                    /* WARNING: Subroutine does not return */
    fStack_25c = 1.2558895e-38;
    FUN_0085b340();
  }
  fStack_264 = *(float *)(iVar4 + 0x1c4);
  piStack_268 = *(int **)(iVar3 + 0x1c);
  fStack_25c = 4.2039e-45;
  ppiStack_260 = &piStack_244;
  uStack_26c = 0x88c131;
  (**(code **)(*piStack_268 + 0x80))();
  iVar3 = in_ECX[8];
  iVar4 = *(int *)(iVar3 + 0x28);
  if ((iVar4 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - iVar4 >> 2) < 0x73)) {
                    /* WARNING: Subroutine does not return */
    uStack_26c = 0x88c150;
    FUN_0085b340();
  }
  uStack_274 = *(undefined4 *)(iVar4 + 0x1c8);
  uStack_26c = 3;
  ppuStack_270 = &puStack_234;
  (**(code **)(**(int **)(iVar3 + 0x1c) + 0x80))(*(int **)(iVar3 + 0x1c));
  iVar3 = in_ECX[8];
  fStack_264 = DAT_0099d080;
  ppiStack_260 = (int **)DAT_0099d080;
  fStack_25c = DAT_0099d080;
  iVar4 = *(int *)(iVar3 + 0x28);
  if ((iVar4 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - iVar4 >> 2) < 0x74)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar3 + 0x1c) + 0x80))
            (*(int **)(iVar3 + 0x1c),*(undefined4 *)(iVar4 + 0x1cc),&fStack_264,3);
  uVar2 = FUN_0040ec60(&uStack_274,*param_3);
  iVar3 = in_ECX[8];
  iVar4 = *(int *)(iVar3 + 0x28);
  if ((iVar4 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - iVar4 >> 2) < 0x71)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar3 + 0x1c) + 0x88))
            (*(int **)(iVar3 + 0x1c),*(undefined4 *)(iVar4 + 0x1c0),uVar2);
  iVar3 = in_ECX[8];
  iVar4 = *(int *)(iVar3 + 0x28);
  if ((iVar4 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - iVar4 >> 2) < 0x6f)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar3 + 0x1c) + 0x78))
            (*(int **)(iVar3 + 0x1c),*(undefined4 *)(iVar4 + 0x1b8),0x41f00000);
  return;
}


// ==== FUN_0088c250 @ 0x0088c250 ====

void FUN_0088c250(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  char *pcVar6;
  
  if ((int)param_1 < 0) {
    piVar1 = *(int **)(*(int *)(in_ECX + 0x20) + 0x1c);
    (**(code **)(*piVar1 + 0xf0))(piVar1,s_ItemMeshRender_00a14d7c);
    iVar4 = *(int *)(in_ECX + 0x20);
    iVar2 = *(int *)(iVar4 + 0x28);
    if ((iVar2 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar2 >> 2) < 0x75)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(iVar4 + 0x1c) + 0xd0))
              (*(int **)(iVar4 + 0x1c),*(undefined4 *)(iVar2 + 0x1d0),0);
    iVar4 = *(int *)(in_ECX + 0x20);
    iVar2 = *(int *)(iVar4 + 0x28);
    if ((iVar2 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar2 >> 2) < 0x76)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(iVar4 + 0x1c) + 0xd0))
              (*(int **)(iVar4 + 0x1c),*(undefined4 *)(iVar2 + 0x1d4),0);
    return;
  }
  uVar3 = FUN_004b3ff0(param_1);
  FUN_0085e340(0x74,uVar3);
  FUN_0088ba50(uVar3,param_3);
  iVar4 = (**(code **)(*DAT_00b5ac00 + 8))();
  if (*(char *)(iVar4 + 5) != '\0') {
    uVar5 = FUN_004b3b40();
    if (param_1 < uVar5) {
      iVar4 = FUN_004b4130(param_1);
      if (iVar4 != 0) {
        FUN_0085e340(0x75,iVar4);
        piVar1 = *(int **)(*(int *)(in_ECX + 0x20) + 0x1c);
        if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xea) == '\0') {
          (**(code **)(*piVar1 + 0xf0))(piVar1,s_ItemMeshSpecularLow_00a14db0);
          return;
        }
        (**(code **)(*piVar1 + 0xf0))(piVar1,s_ItemMeshSpecular_00a14d9c);
        return;
      }
      iVar4 = *(int *)(in_ECX + 0x20);
      iVar2 = *(int *)(iVar4 + 0x28);
      if ((iVar2 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar2 >> 2) < 0x76)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      (**(code **)(**(int **)(iVar4 + 0x1c) + 0xd0))
                (*(int **)(iVar4 + 0x1c),*(undefined4 *)(iVar2 + 0x1d4),0);
      pcVar6 = s_ItemMeshRender_00a14d8c;
      goto LAB_0088c3fe;
    }
  }
  iVar4 = *(int *)(in_ECX + 0x20);
  iVar2 = *(int *)(iVar4 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar2 >> 2) < 0x76)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar4 + 0x1c) + 0xd0))
            (*(int **)(iVar4 + 0x1c),*(undefined4 *)(iVar2 + 0x1d4),0);
  pcVar6 = s_ItemMeshRender_00a14dc4;
LAB_0088c3fe:
  piVar1 = *(int **)(*(int *)(in_ECX + 0x20) + 0x1c);
  (**(code **)(*piVar1 + 0xf0))(piVar1,pcVar6);
  return;
}


// ==== FUN_0088c420 @ 0x0088c420 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0088c420(int param_1,int param_2,int param_3)

{
  float fVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  float *pfVar5;
  undefined4 *puVar6;
  float *pfVar7;
  undefined4 *puVar8;
  float fVar9;
  undefined4 uStack_1e8;
  int iStack_1e4;
  undefined4 uStack_1e0;
  int *piStack_1dc;
  float fStack_1d8;
  undefined1 **ppuStack_1d4;
  float fStack_1d0;
  int *piStack_1cc;
  undefined4 uStack_1c8;
  undefined4 *puStack_1c4;
  undefined1 *puStack_1c0;
  float *pfStack_1bc;
  undefined1 *puStack_1b8;
  undefined1 *local_1b4;
  undefined1 *local_1b0;
  undefined1 *local_1ac;
  float afStack_18c [3];
  undefined1 local_180 [52];
  float afStack_14c [19];
  undefined1 local_100 [40];
  undefined4 auStack_d8 [3];
  undefined1 auStack_cc [64];
  undefined1 auStack_8c [12];
  undefined1 local_80 [40];
  undefined4 auStack_58 [22];
  
  iVar3 = *(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xa0);
  iVar4 = *(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x9c);
  afStack_18c[2] = (float)iVar3;
  if (iVar3 < 0) {
    afStack_18c[2] = afStack_18c[2] + _DAT_0099d104;
  }
  afStack_18c[2] = DAT_0099d080 / afStack_18c[2];
  fVar1 = (float)iVar4;
  if (iVar4 < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  fVar9 = DAT_0099d080 / fVar1;
  local_1b0 = (undefined1 *)
              ((((fVar1 - (float)(*(int *)(param_3 + 0x10) + param_2)) * fVar9 - DAT_0099d0b4) *
                DAT_0099d0f8 +
               ((fVar1 - (float)(*(int *)(param_3 + 0xc) + param_2)) * fVar9 - DAT_0099d0b4) *
               DAT_0099d0f8) * DAT_0099d0b4);
  local_1ac = (undefined1 *)0x3f000000;
  local_1b4 = (undefined1 *)
              ((((float)(*(int *)(param_3 + 8) + param_1) * afStack_18c[2] - DAT_0099d0b4) *
                DAT_0099d0f8 +
               ((float)(*(int *)(param_3 + 4) + param_1) * afStack_18c[2] - DAT_0099d0b4) *
               DAT_0099d0f8) * DAT_0099d0b4);
  puStack_1b8 = local_80;
  pfStack_1bc = (float *)0x88c54c;
  thunk_FUN_0079f7f5();
  local_1ac = (undefined1 *)(*(float *)(param_3 + 0x68) + DAT_0099d0ec);
  local_1b0 = (undefined1 *)(fVar9 + *(float *)(param_3 + 0x68));
  local_1b4 = (undefined1 *)(afStack_18c[2] + *(float *)(param_3 + 0x68));
  puStack_1b8 = local_100;
  pfStack_1bc = (float *)0x88c590;
  thunk_FUN_0079f761();
  local_1ac = local_100;
  local_1b0 = (undefined1 *)(param_3 + 0x18);
  local_1b4 = local_180;
  puStack_1b8 = (undefined1 *)0x88c5a6;
  thunk_FUN_0079ee7b();
  puStack_1b8 = auStack_8c;
  pfVar5 = afStack_18c;
  pfVar7 = afStack_14c;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar7 = *pfVar5;
    pfVar5 = pfVar5 + 1;
    pfVar7 = pfVar7 + 1;
  }
  pfStack_1bc = afStack_14c;
  puStack_1c0 = auStack_cc;
  puStack_1c4 = (undefined4 *)0x88c5cf;
  thunk_FUN_0079ee7b();
  iVar3 = *(int *)(in_ECX + 0x20);
  puVar6 = auStack_d8;
  puVar8 = auStack_58;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar8 = puVar8 + 1;
  }
  iVar4 = *(int *)(iVar3 + 0x28);
  if ((iVar4 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - iVar4 >> 2) < 0x6e)) {
                    /* WARNING: Subroutine does not return */
    puStack_1c4 = (undefined4 *)0x88c603;
    FUN_0085b340();
  }
  uStack_1c8 = *(undefined4 *)(iVar4 + 0x1b4);
  piStack_1cc = *(int **)(iVar3 + 0x1c);
  puStack_1c4 = auStack_58;
  fStack_1d0 = 1.2560699e-38;
  (**(code **)(*piStack_1cc + 0x98))();
  iVar3 = *(int *)(in_ECX + 0x20);
  puStack_1b8 = DAT_009b2dbc;
  local_1b4 = DAT_009b2dbc;
  local_1b0 = DAT_009b2dbc;
  iVar4 = *(int *)(iVar3 + 0x28);
  if ((iVar4 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - iVar4 >> 2) < 0x72)) {
                    /* WARNING: Subroutine does not return */
    fStack_1d0 = 1.2560778e-38;
    FUN_0085b340();
  }
  fStack_1d8 = *(float *)(iVar4 + 0x1c4);
  piStack_1dc = *(int **)(iVar3 + 0x1c);
  fStack_1d0 = 4.2039e-45;
  ppuStack_1d4 = &puStack_1b8;
  uStack_1e0 = 0x88c671;
  (**(code **)(*piStack_1dc + 0x80))();
  iVar3 = *(int *)(in_ECX + 0x20);
  iVar4 = *(int *)(iVar3 + 0x28);
  if ((iVar4 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - iVar4 >> 2) < 0x73)) {
                    /* WARNING: Subroutine does not return */
    uStack_1e0 = 0x88c690;
    FUN_0085b340();
  }
  uStack_1e8 = *(undefined4 *)(iVar4 + 0x1c8);
  uStack_1e0 = 3;
  iStack_1e4 = in_ECX + 4;
  (**(code **)(**(int **)(iVar3 + 0x1c) + 0x80))(*(int **)(iVar3 + 0x1c));
  iVar3 = *(int *)(in_ECX + 0x20);
  fStack_1d8 = DAT_0099d080;
  ppuStack_1d4 = (undefined1 **)DAT_0099d080;
  fStack_1d0 = DAT_0099d080;
  iVar4 = *(int *)(iVar3 + 0x28);
  if ((iVar4 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - iVar4 >> 2) < 0x74)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar3 + 0x1c) + 0x80))
            (*(int **)(iVar3 + 0x1c),*(undefined4 *)(iVar4 + 0x1cc),&fStack_1d8,3);
  uVar2 = FUN_0040ec60(&uStack_1e8,*(undefined4 *)(param_3 + 100));
  iVar3 = *(int *)(in_ECX + 0x20);
  iVar4 = *(int *)(iVar3 + 0x28);
  if ((iVar4 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - iVar4 >> 2) < 0x71)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar3 + 0x1c) + 0x88))
            (*(int **)(iVar3 + 0x1c),*(undefined4 *)(iVar4 + 0x1c0),uVar2);
  return;
}


// ==== FUN_0088c750 @ 0x0088c750 ====

void FUN_0088c750(undefined4 param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 in_ECX;
  undefined4 unaff_EBX;
  uint uVar7;
  uint unaff_EDI;
  undefined4 uVar8;
  undefined1 auStack_14 [4];
  uint uStack_10;
  uint uStack_c;
  uint *puStack_8;
  undefined4 uStack_4;
  
  cVar1 = *(char *)(param_3 + 0x14);
  iVar3 = *(int *)(DAT_00b5ac04 + 0x28);
  if (cVar1 == '\0') {
    if (*(char *)(iVar3 + 0x7e) != '\0') {
      (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0x16,3);
      goto LAB_0088c7a0;
    }
    uVar8 = 2;
  }
  else {
    uVar8 = 1;
  }
  (**(code **)(**(int **)(iVar3 + 0x90) + 0xe4))(*(int **)(iVar3 + 0x90),0x16,uVar8);
LAB_0088c7a0:
  *(char *)(iVar3 + 0x74) = cVar1;
  uVar8 = *(undefined4 *)(param_3 + 0x58);
  iVar3 = FUN_004b9c10();
  uVar2 = *(undefined4 *)(param_3 + 0x5c);
  FUN_0088be30(puStack_8,uStack_4,param_3,uVar8);
  piVar4 = (int *)FUN_00850950();
  (**(code **)(*piVar4 + 8))(auStack_14,uVar8);
  uStack_c = 0;
  uVar7 = 0;
  if (iVar3 != 0) {
    do {
      iVar5 = FUN_004ba010(uStack_c);
      iVar3 = *(int *)(iVar5 + 4);
      iVar6 = FUN_004b3b40();
      if (iVar3 < iVar6) {
        FUN_004b3ff0(iVar3);
        piVar4 = (int *)FUN_004af750();
        iVar3 = (**(code **)(*piVar4 + 0x10))();
        if (iVar3 != 2) goto LAB_0088c83d;
      }
      else {
LAB_0088c83d:
        uVar7 = uStack_10 >> 8;
        uStack_10 = uStack_10 & 0xffffff00;
        if (*puStack_8 < 0xff000000) {
          uStack_10 = CONCAT31((int3)uVar7,1);
        }
        FUN_0088c250(*(undefined4 *)(iVar5 + 4),uVar2,uStack_10);
        FUN_0088bd20(iVar5,unaff_EBX,in_ECX);
      }
      uStack_c = uStack_c + 1;
    } while (uStack_c < unaff_EDI);
    uVar7 = unaff_EDI;
  }
  uStack_c = 0;
  if (uVar7 != 0) {
    do {
      iVar5 = FUN_004ba010(uStack_c);
      iVar3 = *(int *)(iVar5 + 4);
      iVar6 = FUN_004b3b40();
      if (iVar3 < iVar6) {
        FUN_004b3ff0(iVar3);
        piVar4 = (int *)FUN_004af750();
        iVar3 = (**(code **)(*piVar4 + 0x10))();
        if (iVar3 == 2) {
          uVar7 = uStack_10 >> 8;
          uStack_10 = uStack_10 & 0xffffff00;
          if (*puStack_8 < 0xff000000) {
            uStack_10 = CONCAT31((int3)uVar7,1);
          }
          FUN_0088c250(*(undefined4 *)(iVar5 + 4),uVar2,uStack_10);
          FUN_0088bd20(iVar5,unaff_EBX,in_ECX);
        }
      }
      uStack_c = uStack_c + 1;
    } while (uStack_c < unaff_EDI);
  }
  return;
}


// ==== FUN_0088c940 @ 0x0088c940 ====

void FUN_0088c940(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  undefined4 unaff_EBX;
  int *piVar6;
  int *piVar7;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uVar8;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(char *)(param_3 + 0x60) != '\0') {
    if (*(char *)(param_3 + 0x14) == '\0') {
      iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
      piVar7 = *(int **)(iVar1 + 0x90);
      if (*(char *)(iVar1 + 0x7e) == '\0') {
        uStack_24 = 2;
        uStack_28 = 0x16;
        (**(code **)(*piVar7 + 0xe4))(piVar7);
      }
      else {
        uStack_24 = 3;
        uStack_28 = 0x16;
        (**(code **)(*piVar7 + 0xe4))(piVar7);
      }
      *(undefined1 *)(iVar1 + 0x74) = 0;
    }
    else {
      iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
      piVar7 = *(int **)(iVar1 + 0x90);
      uStack_24 = 1;
      uStack_28 = 0x16;
      (**(code **)(*piVar7 + 0xe4))(piVar7);
      *(undefined1 *)(iVar1 + 0x74) = 1;
    }
    uVar8 = *(undefined4 *)(param_3 + 0x58);
    FUN_004b9c10();
    FUN_0088c420(uStack_8,uStack_4,param_3,uVar8);
    iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
    if ((((*(int *)(iVar1 + 0x114) != 2) || (*(int *)(iVar1 + 0x118) != 5)) ||
        (*(int *)(iVar1 + 0x11c) != 2)) && (*(int *)(iVar1 + 100) == 0)) {
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,2);
      *(undefined4 *)(iVar1 + 0x114) = 2;
      *(undefined4 *)(iVar1 + 0x118) = 5;
      *(undefined4 *)(iVar1 + 0x11c) = 2;
    }
    piVar6 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar6 + 0xe4))(piVar6,0xe,0);
    FUN_0085e340(0x75,*(undefined4 *)(param_3 + 0x78));
    piVar2 = *(int **)(*(int *)(in_ECX + 0x20) + 0x1c);
    (**(code **)(*piVar2 + 0xf0))(piVar2,s_EdgeItem_00a14dd4);
    piVar2 = (int *)FUN_00850950();
    (**(code **)(*piVar2 + 8))(&uStack_28,uVar8);
    piVar2 = (int *)0x0;
    uStack_24 = unaff_EBX;
    if (piVar6 != (int *)0x0) {
      do {
        iVar3 = FUN_004ba010(piVar2);
        iVar4 = FUN_004b3ff0(*(undefined4 *)(iVar3 + 4));
        iVar1 = *(int *)(in_ECX + 0x20);
        uVar8 = 0;
        if (iVar4 != 0) {
          piVar5 = (int *)FUN_004af750();
          uVar8 = (**(code **)(*piVar5 + 4))();
        }
        iVar4 = *(int *)(iVar1 + 0x28);
        if ((iVar4 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar4 >> 2) < 0x75)) {
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        (**(code **)(**(int **)(iVar1 + 0x1c) + 0xd0))
                  (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar4 + 0x1d0),uVar8);
        FUN_0088bd20(iVar3,uStack_24,piVar7);
        piVar2 = (int *)((int)piVar2 + 1);
      } while (piVar2 < piVar6);
    }
  }
  return;
}


// ==== FUN_0088cbb0 @ 0x0088cbb0 ====

void FUN_0088cbb0(int param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x78) != 0) {
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    if (*(int *)(iVar2 + 8) == 0) {
      uVar3 = 0x14;
    }
    else {
      uVar3 = 0xb;
    }
    uVar3 = FUN_0085e3a0(uVar3);
    *(undefined4 *)(in_ECX + 0x20) = uVar3;
    piVar1 = (int *)FUN_00850950();
    (**(code **)(*piVar1 + 4))();
    piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar1 + 0x15c))(piVar1,*(undefined4 *)(*(int *)(in_ECX + 0x20) + 0x20));
    uVar3 = *(undefined4 *)(param_1 + 0x78);
    FUN_0088c750(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),uVar3);
    FUN_0088c940(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),uVar3);
  }
  return;
}


// ==== FUN_0088cc60 @ 0x0088cc60 ====

int FUN_0088cc60(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x34;
}


// ==== FUN_0088cc90 @ 0x0088cc90 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0088cc90(int *param_1,float *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar1 = *param_1;
  local_10 = *param_2;
  local_c = param_2[2];
  if ((0.0 <= local_10) && (0.0 <= local_c)) {
    fVar8 = (float)*(int *)(iVar1 + 0x40);
    if (*(int *)(iVar1 + 0x40) < 0) {
      fVar8 = fVar8 + _DAT_0099d104;
    }
    if (local_10 < fVar8) {
      fVar8 = (float)*(int *)(iVar1 + 0x44);
      if (*(int *)(iVar1 + 0x44) < 0) {
        fVar8 = fVar8 + _DAT_0099d104;
      }
      if (local_c < fVar8) {
        fVar3 = (float10)FUN_004a9180((int)ROUND(*param_2),(int)ROUND(param_2[2]));
        if (param_2[1] - DAT_0099d0b4 <= (float)fVar3) {
          local_10 = *param_2;
          local_c = param_2[2];
          param_3[0xb] = (int)local_10;
          param_3[0xc] = (int)local_c;
          fVar4 = (float10)FUN_0040d4c0(param_2[4]);
          param_3[7] = (int)(float)fVar4;
          fVar4 = (float10)FUN_0040d4d0(param_2[4]);
          param_3[8] = (int)(float)fVar4;
          param_3[9] = (int)(param_2[3] * DAT_0099d0f8);
          local_10 = DAT_0099d080;
          local_c = DAT_0099d080;
          local_8 = DAT_0099d080;
          local_4 = param_2[5];
          iVar1 = FUN_0040ead0(&local_10);
          param_3[6] = iVar1;
          fVar8 = 0.0;
          if (0.0 <= (float)param_3[0xb] - param_2[3]) {
            fVar8 = (float)param_3[0xb] - param_2[3];
          }
          fVar7 = 0.0;
          if (0.0 <= (float)param_3[0xc] - param_2[3]) {
            fVar7 = (float)param_3[0xc] - param_2[3];
          }
          fVar6 = param_2[3] + (float)param_3[0xb];
          if (fVar6 < 0.0) {
            fVar6 = 0.0;
          }
          fVar5 = 0.0;
          if (0.0 <= param_2[3] + (float)param_3[0xc]) {
            fVar5 = param_2[3] + (float)param_3[0xc];
          }
          iVar1 = (int)(fVar6 + DAT_0099d0b4) + 1;
          iVar2 = (int)(fVar5 + DAT_0099d0b4) + 1;
          param_3[2] = iVar1;
          param_3[3] = iVar2;
          *param_3 = (int)fVar8;
          param_3[1] = (int)fVar7;
          param_3[4] = (iVar1 - (int)fVar8) + 1;
          param_3[5] = (iVar2 - (int)fVar7) + 1;
          param_3[10] = (int)(float)fVar3;
        }
      }
    }
  }
  return;
}


// ==== FUN_0088cea0 @ 0x0088cea0 ====

undefined4 FUN_0088cea0(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = *(int *)(*(int *)(in_ECX + 0x1c) + 0x219e4) * *(int *)(in_ECX + 0x24);
  piVar1 = (int *)**(undefined4 **)(DAT_00b5ac04 + 0x34);
  cVar2 = FUN_00881000(*(int *)(in_ECX + 0x24),iVar4);
  if (cVar2 == '\0') {
    (**(code **)(*piVar1 + 0xc))();
  }
  cVar2 = FUN_00881000(*(undefined4 *)(in_ECX + 0x24),iVar4);
  if (cVar2 == '\0') {
    return 0;
  }
  uVar3 = (**(code **)(*piVar1 + 0x1c))(*(undefined4 *)(in_ECX + 0x24),iVar4);
  (**(code **)(*piVar1 + 0x14))(iVar4,*(undefined4 *)(in_ECX + 0x1c));
  FUN_00881060();
  return uVar3;
}


// ==== FUN_0088cf20 @ 0x0088cf20 ====

undefined4 FUN_0088cf20(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0x1c) + 0x219e8);
  piVar2 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
  iVar3 = iVar1 * 2;
  if ((uint)piVar2[7] <= (uint)(piVar2[8] + iVar3)) {
    (**(code **)(*piVar2 + 0x10))();
  }
  if ((uint)(piVar2[8] + iVar3) < (uint)piVar2[7]) {
    uVar4 = (**(code **)(*piVar2 + 0x20))(iVar3);
    (**(code **)(*piVar2 + 0x18))(iVar1,*(int *)(in_ECX + 0x1c) + 0x1de20);
    FUN_00881080();
    return uVar4;
  }
  return 0;
}


// ==== FUN_0088cf90 @ 0x0088cf90 ====

undefined4 FUN_0088cf90(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = *(int *)(*(int *)(in_ECX + 0x20) + 0x1a25c) * *(int *)(in_ECX + 0x24);
  piVar1 = (int *)**(undefined4 **)(DAT_00b5ac04 + 0x34);
  cVar2 = FUN_00881000(*(int *)(in_ECX + 0x24),iVar4);
  if (cVar2 == '\0') {
    (**(code **)(*piVar1 + 0xc))();
  }
  cVar2 = FUN_00881000(*(undefined4 *)(in_ECX + 0x24),iVar4);
  if (cVar2 == '\0') {
    return 0;
  }
  uVar3 = (**(code **)(*piVar1 + 0x1c))(*(undefined4 *)(in_ECX + 0x24),iVar4);
  (**(code **)(*piVar1 + 0x14))(iVar4,*(undefined4 *)(in_ECX + 0x20));
  FUN_00881060();
  return uVar3;
}


// ==== FUN_0088d010 @ 0x0088d010 ====

undefined4 FUN_0088d010(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0x20) + 0x1a260);
  piVar2 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
  iVar3 = iVar1 * 2;
  if ((uint)piVar2[7] <= (uint)(piVar2[8] + iVar3)) {
    (**(code **)(*piVar2 + 0x10))();
  }
  if ((uint)(piVar2[8] + iVar3) < (uint)piVar2[7]) {
    uVar4 = (**(code **)(*piVar2 + 0x20))(iVar3);
    (**(code **)(*piVar2 + 0x18))(iVar1,*(int *)(in_ECX + 0x20) + 0x16698);
    FUN_00881080();
    return uVar4;
  }
  return 0;
}


// ==== FUN_0088d080 @ 0x0088d080 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0088d080(int *param_1)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short sVar7;
  float fVar8;
  float fVar9;
  int in_ECX;
  float *pfVar10;
  short *psVar11;
  short *psVar12;
  uint uVar13;
  short sVar14;
  uint uVar15;
  uint uVar16;
  float fVar17;
  float fVar18;
  
  fVar9 = DAT_0099d0b4;
  fVar8 = DAT_0099d080;
  iVar3 = *(int *)(*(int *)(in_ECX + 0x1c) + 0x219e4);
  uVar16 = param_1[4];
  if (uVar16 * param_1[5] + iVar3 < 0x9f7) {
    uVar13 = 0;
    if (param_1[5] != 0) {
      do {
        uVar15 = 0;
        if (uVar16 != 0) {
          do {
            fVar17 = (float)(int)(*param_1 + uVar15);
            if ((int)(*param_1 + uVar15) < 0) {
              fVar17 = fVar17 + _DAT_0099d104;
            }
            fVar18 = (float)(int)(param_1[1] + uVar13);
            if ((int)(param_1[1] + uVar13) < 0) {
              fVar18 = fVar18 + _DAT_0099d104;
            }
            fVar2 = (float)param_1[10];
            pfVar10 = (float *)(*(int *)(*(int *)(in_ECX + 0x1c) + 0x219e4) * 0x30 +
                               *(int *)(in_ECX + 0x1c));
            *pfVar10 = fVar17;
            pfVar10[1] = fVar2;
            pfVar10[2] = fVar18;
            fVar17 = (fVar17 - (float)param_1[0xb]) * (fVar8 / (float)param_1[9]);
            fVar18 = (fVar18 - (float)param_1[0xc]) * (fVar8 / (float)param_1[9]);
            pfVar10[9] = ((float)param_1[8] * fVar17 + fVar9) - (float)param_1[7] * fVar18;
            pfVar10[10] = (float)param_1[7] * fVar17 + (float)param_1[8] * fVar18 + fVar9;
            pfVar10[0xb] = (float)param_1[6];
            piVar1 = (int *)(*(int *)(in_ECX + 0x1c) + 0x219e4);
            *piVar1 = *piVar1 + 1;
            uVar16 = param_1[4];
            uVar15 = uVar15 + 1;
          } while (uVar15 < uVar16);
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 < (uint)param_1[5]);
    }
    iVar4 = param_1[5];
    iVar5 = param_1[4];
    iVar6 = *(int *)(in_ECX + 0x1c);
    psVar11 = (short *)(iVar6 + 0x1de20);
    sVar14 = (short)iVar3;
    if (*(int *)(iVar6 + 0x219e8) != 0) {
      psVar11 = psVar11 + *(int *)(iVar6 + 0x219e8);
      psVar11[-1] = (short)param_1[4] + sVar14;
    }
    uVar16 = 0;
    if (param_1[5] != 1) {
      do {
        uVar13 = 0;
        sVar7 = (short)uVar16;
        psVar12 = psVar11;
        if (param_1[4] != 0) {
          do {
            psVar12 = psVar11 + 2;
            *psVar11 = (short)param_1[4] * (sVar7 + 1) + (short)uVar13 + sVar14;
            psVar11[1] = (short)param_1[4] * sVar7 + (short)uVar13 + sVar14;
            uVar13 = uVar13 + 1;
            psVar11 = psVar12;
          } while (uVar13 < (uint)param_1[4]);
        }
        *psVar12 = psVar12[-1];
        uVar16 = uVar16 + 1;
        psVar11 = psVar12 + 2;
        psVar12[1] = (sVar7 + 2) * (short)param_1[4] + sVar14;
      } while (uVar16 < param_1[5] - 1U);
    }
    piVar1 = (int *)(*(int *)(in_ECX + 0x1c) + 0x219e8);
    *piVar1 = *piVar1 + (iVar4 + -1) * (iVar5 + 1) * 2;
  }
  return;
}


// ==== FUN_0088d2b0 @ 0x0088d2b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0088d2b0(int *param_1)

{
  int *piVar1;
  float *pfVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  float fVar9;
  float fVar10;
  int in_ECX;
  short *psVar11;
  short *psVar12;
  uint uVar13;
  short sVar14;
  uint uVar15;
  uint uVar16;
  float fVar17;
  float fVar18;
  
  fVar10 = DAT_0099d0b4;
  fVar9 = DAT_0099d080;
  iVar4 = *(int *)(*(int *)(in_ECX + 0x20) + 0x1a25c);
  uVar16 = param_1[4];
  if (uVar16 * param_1[5] + iVar4 < 0x9f7) {
    uVar13 = 0;
    if (param_1[5] != 0) {
      do {
        uVar15 = 0;
        if (uVar16 != 0) {
          do {
            fVar17 = (float)(int)(*param_1 + uVar15);
            if ((int)(*param_1 + uVar15) < 0) {
              fVar17 = fVar17 + _DAT_0099d104;
            }
            fVar18 = (float)(int)(param_1[1] + uVar13);
            if ((int)(param_1[1] + uVar13) < 0) {
              fVar18 = fVar18 + _DAT_0099d104;
            }
            fVar3 = (float)param_1[10];
            pfVar2 = (float *)(*(int *)(in_ECX + 0x20) +
                              *(int *)(*(int *)(in_ECX + 0x20) + 0x1a25c) * 0x24);
            *pfVar2 = fVar17;
            pfVar2[1] = fVar3;
            pfVar2[2] = fVar18;
            fVar17 = (fVar17 - (float)param_1[0xb]) * (fVar9 / (float)param_1[9]);
            fVar18 = (fVar18 - (float)param_1[0xc]) * (fVar9 / (float)param_1[9]);
            pfVar2[6] = ((float)param_1[8] * fVar17 + fVar10) - (float)param_1[7] * fVar18;
            pfVar2[7] = (float)param_1[7] * fVar17 + (float)param_1[8] * fVar18 + fVar10;
            pfVar2[8] = (float)param_1[6];
            piVar1 = (int *)(*(int *)(in_ECX + 0x20) + 0x1a25c);
            *piVar1 = *piVar1 + 1;
            uVar16 = param_1[4];
            uVar15 = uVar15 + 1;
          } while (uVar15 < uVar16);
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 < (uint)param_1[5]);
    }
    iVar5 = param_1[5];
    iVar6 = param_1[4];
    iVar7 = *(int *)(in_ECX + 0x20);
    psVar11 = (short *)(iVar7 + 0x16698);
    sVar14 = (short)iVar4;
    if (*(int *)(iVar7 + 0x1a260) != 0) {
      psVar11 = psVar11 + *(int *)(iVar7 + 0x1a260);
      psVar11[-1] = (short)param_1[4] + sVar14;
    }
    uVar16 = 0;
    if (param_1[5] != 1) {
      do {
        uVar13 = 0;
        sVar8 = (short)uVar16;
        psVar12 = psVar11;
        if (param_1[4] != 0) {
          do {
            psVar12 = psVar11 + 2;
            *psVar11 = (short)param_1[4] * (sVar8 + 1) + (short)uVar13 + sVar14;
            psVar11[1] = (short)param_1[4] * sVar8 + (short)uVar13 + sVar14;
            uVar13 = uVar13 + 1;
            psVar11 = psVar12;
          } while (uVar13 < (uint)param_1[4]);
        }
        *psVar12 = psVar12[-1];
        uVar16 = uVar16 + 1;
        psVar11 = psVar12 + 2;
        psVar12[1] = (sVar8 + 2) * (short)param_1[4] + sVar14;
      } while (uVar16 < param_1[5] - 1U);
    }
    piVar1 = (int *)(*(int *)(in_ECX + 0x20) + 0x1a260);
    *piVar1 = *piVar1 + (iVar5 + -1) * (iVar6 + 1) * 2;
  }
  return;
}


// ==== FUN_0088d4e0 @ 0x0088d4e0 ====

void FUN_0088d4e0(int param_1)

{
  int iVar1;
  
  if (param_1 == 1) {
    iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
    if (((*(int *)(iVar1 + 0x114) == 2) && (*(int *)(iVar1 + 0x118) == 5)) &&
       (*(int *)(iVar1 + 0x11c) == 6)) {
      return;
    }
    if (*(int *)(iVar1 + 100) != 0) {
      return;
    }
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,6);
    *(undefined4 *)(iVar1 + 0x11c) = 6;
  }
  else {
    if (param_1 != 0) {
      return;
    }
    iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
    if (((*(int *)(iVar1 + 0x114) == 2) && (*(int *)(iVar1 + 0x118) == 5)) &&
       (*(int *)(iVar1 + 0x11c) == 2)) {
      return;
    }
    if (*(int *)(iVar1 + 100) != 0) {
      return;
    }
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,2);
    *(undefined4 *)(iVar1 + 0x11c) = 2;
  }
  *(undefined4 *)(iVar1 + 0x114) = 2;
  *(undefined4 *)(iVar1 + 0x118) = 5;
  return;
}


// ==== FUN_0088d670 @ 0x0088d670 ====

void FUN_0088d670(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a14e74;
  if (in_ECX[1] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[1]);
    in_ECX[1] = 0;
  }
  _free((void *)in_ECX[7]);
  return;
}


// ==== FUN_0088d6d0 @ 0x0088d6d0 ====

undefined4 FUN_0088d6d0(void)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 4) == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_effect_common_waterfront_dds_00a14e30,0x1c);
    uVar1 = FUN_004b4e70(local_1c);
    *(undefined4 *)(in_ECX + 4) = uVar1;
    if (0xf < local_4) {
      _free(local_18);
      return extraout_EAX;
    }
  }
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0088d730 @ 0x0088d730 ====

void FUN_0088d730(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0xc) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0xc));
  return;
}


// ==== FUN_0088d760 @ 0x0088d760 ====

void FUN_0088d760(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 uVar5;
  undefined4 uVar6;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar3 = (**(code **)(*piVar2 + 0x1c))();
  if (*(int *)(iVar3 + 8) == 0) {
    if (*(uint *)(*(int *)(in_ECX + 0x20) + 0x1a260) < 4) {
      return;
    }
    uVar4 = FUN_0088cf90();
    FUN_0088d010();
    iVar3 = *(int *)(*(int *)(in_ECX + 0x20) + 0x1a260);
  }
  else {
    if (*(uint *)(*(int *)(in_ECX + 0x1c) + 0x219e8) < 4) {
      return;
    }
    uVar4 = FUN_0088cea0();
    FUN_0088cf20();
    iVar3 = *(int *)(*(int *)(in_ECX + 0x1c) + 0x219e8);
  }
  piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  iVar1 = **(int **)(DAT_00b5ac04 + 0x34);
  uVar6 = *(undefined4 *)(in_ECX + 0x24);
  uVar5 = 0;
  (**(code **)(*piVar2 + 400))(piVar2,0,*(undefined4 *)(iVar1 + 4),0,uVar6);
  FUN_0084b7f0(*(undefined4 *)(iVar1 + 0x18));
  piVar2 = *(int **)(*(int *)(in_ECX + 0x18) + 0x1c);
  (**(code **)(*piVar2 + 0x10c))(piVar2);
  piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar2 + 0x148))(piVar2,5,uVar4,0,uVar6,uVar5,iVar3 + -3);
  return;
}


// ==== FUN_0088d870 @ 0x0088d870 ====

void FUN_0088d870(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 uStack_28;
  int *piStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  iVar1 = *(int *)(in_ECX + 0x18);
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x3f)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_20 = *(undefined4 *)(iVar2 + 0xf8);
  piStack_24 = *(int **)(iVar1 + 0x1c);
  uStack_1c = *(int *)(DAT_00b5ac04 + 0x78) + 200;
  uStack_28 = 0x88d8b9;
  (**(code **)(*piStack_24 + 0x98))();
  iVar1 = *(int *)(in_ECX + 0x18);
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x49)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_28 = 2;
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0x80))
            (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar2 + 0x120),(int)register0x00000010 + -0x18)
  ;
  uVar3 = FUN_00862b50(&uStack_28);
  iVar1 = *(int *)(in_ECX + 0x18);
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x4a)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0x80))
            (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar2 + 0x124),uVar3,3);
  return;
}


// ==== FUN_0088d960 @ 0x0088d960 ====

void FUN_0088d960(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *in_ECX;
  undefined4 *puVar5;
  
  *in_ECX = &PTR_FUN_00a14e74;
  in_ECX[1] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar2 = (**(code **)(*piVar1 + 0x1c))();
  if (*(int *)(iVar2 + 8) == 0) {
    in_ECX[9] = 0x24;
    puVar3 = operator_new(0x1a264);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar5 = puVar3;
      for (iVar2 = 0x59a6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      puVar5 = puVar3 + 0x59a6;
      for (iVar2 = 0xef1; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
    }
    in_ECX[8] = puVar3;
    uVar4 = FUN_0085e3a0(0x16);
    in_ECX[6] = uVar4;
    return;
  }
  in_ECX[9] = 0x30;
  puVar3 = operator_new(0x219ec);
  if (puVar3 == (undefined4 *)0x0) {
    in_ECX[7] = 0;
    uVar4 = FUN_0085e3a0(5);
    in_ECX[6] = uVar4;
    return;
  }
  puVar5 = puVar3;
  for (iVar2 = 0x7788; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  puVar5 = puVar3 + 0x7788;
  for (iVar2 = 0xef1; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  in_ECX[7] = puVar3;
  uVar4 = FUN_0085e3a0(5);
  in_ECX[6] = uVar4;
  return;
}


// ==== FUN_0088da60 @ 0x0088da60 ====

void FUN_0088da60(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  int *piStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int *piStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int *piStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  if ((*(int *)(in_ECX + 0xc) != 0) &&
     ((*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc)) / 0x34 != 0)) {
    uStack_18 = 0x88daa2;
    FUN_00859460();
    iVar4 = *(int *)(DAT_00b5ac04 + 0x28);
    piStack_24 = *(int **)(iVar4 + 0x90);
    if (*(char *)(iVar4 + 0x104) == '\0') {
      uStack_18 = 3;
      uStack_1c = 1;
      uStack_20 = 0;
      uStack_28 = 0x88db05;
      (**(code **)(*piStack_24 + 0x114))();
      piStack_34 = *(int **)(iVar4 + 0x90);
      uStack_28 = 3;
      uStack_2c = 2;
      uStack_30 = 0;
      uStack_38 = 0x88db19;
      (**(code **)(*piStack_34 + 0x114))();
    }
    else {
      uStack_18 = 4;
      uStack_1c = 1;
      uStack_20 = 0;
      uStack_28 = 0x88dac7;
      (**(code **)(*piStack_24 + 0x114))();
      piStack_34 = *(int **)(iVar4 + 0x90);
      uStack_28 = 4;
      uStack_2c = 2;
      uStack_30 = 0;
      uStack_38 = 0x88dadb;
      (**(code **)(*piStack_34 + 0x114))();
      uStack_38 = 0x88dae8;
      piStack_44 = (int *)FUN_0049b670();
      uStack_38 = 0;
      uStack_3c = 4;
      uStack_40 = 0;
      (**(code **)(*piStack_44 + 0x114))();
    }
    piVar3 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar3 + 0x15c))(piVar3,*(undefined4 *)(*(int *)(in_ECX + 0x18) + 0x20));
    piVar3 = *(int **)(*(int *)(in_ECX + 0x18) + 0x1c);
    (**(code **)(*piVar3 + 0xf0))(piVar3,s_MapEffect_00a14e50);
    FUN_0088d870();
    FUN_0088d4e0(0);
    uVar2 = FUN_0088d6d0();
    FUN_0085e340(0x54,uVar2);
    piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar4 = (**(code **)(*piVar3 + 0x1c))();
    if (*(int *)(iVar4 + 8) == 0) {
      iVar4 = *(int *)(in_ECX + 0x20);
      *(undefined4 *)(iVar4 + 0x1a25c) = 0;
      *(undefined4 *)(iVar4 + 0x1a260) = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 0x1c);
      *(undefined4 *)(iVar4 + 0x219e4) = 0;
      *(undefined4 *)(iVar4 + 0x219e8) = 0;
    }
    iVar4 = *(int *)(in_ECX + 0xc);
    iVar1 = *(int *)(in_ECX + 0x10);
    if (iVar4 != iVar1) {
      do {
        piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
        iVar5 = (**(code **)(*piVar3 + 0x1c))();
        if (*(int *)(iVar5 + 8) == 0) {
          FUN_0088d2b0(iVar4);
        }
        else {
          FUN_0088d080(iVar4);
        }
        iVar4 = iVar4 + 0x34;
      } while (iVar4 != iVar1);
    }
    piVar3 = *(int **)(*(int *)(in_ECX + 0x18) + 0x1c);
    (**(code **)(*piVar3 + 0x104))(piVar3,&piStack_44,0);
    piVar3 = *(int **)(*(int *)(in_ECX + 0x18) + 0x1c);
    (**(code **)(*piVar3 + 0x108))(piVar3,0);
    FUN_0088d760();
    piVar3 = *(int **)(*(int *)(in_ECX + 0x18) + 0x1c);
    (**(code **)(*piVar3 + 0x110))(piVar3);
    piVar3 = *(int **)(*(int *)(in_ECX + 0x18) + 0x1c);
    (**(code **)(*piVar3 + 0x114))(piVar3);
    FUN_00859590();
  }
  return;
}


// ==== FUN_0088dc40 @ 0x0088dc40 ====

void FUN_0088dc40(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 local_34 [52];
  
  if ((*(int *)(param_1 + 0x34) != 0) &&
     ((*(int *)(param_1 + 0x38) - *(int *)(param_1 + 0x34)) / 0x18 != 0)) {
    iVar1 = *(int *)(param_1 + 0x38);
    for (iVar2 = *(int *)(param_1 + 0x34); iVar2 != iVar1; iVar2 = iVar2 + 0x18) {
      FUN_0088cc90(param_1,iVar2,local_34);
      FUN_0088e1e0(local_34);
    }
  }
  return;
}


// ==== FUN_0088dcb0 @ 0x0088dcb0 ====

void FUN_0088dcb0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  while (param_1 != param_2) {
    puVar1 = param_1 + 0xd;
    puVar3 = param_3;
    puVar4 = param_1;
    for (iVar2 = 0xd; param_1 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


// ==== FUN_0088dce0 @ 0x0088dce0 ====

void FUN_0088dce0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  while (param_1 != param_2) {
    param_2 = param_2 + -0xd;
    param_3 = param_3 + -0xd;
    puVar2 = param_2;
    puVar3 = param_3;
    for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}


// ==== FUN_0088dd10 @ 0x0088dd10 ====

void FUN_0088dd10(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}


// ==== FUN_0088dd30 @ 0x0088dd30 ====

int FUN_0088dd30(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a790;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x34) {
    FUN_0088dd10(param_3,param_1);
    param_3 = param_3 + 0x34;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0088dd96 @ 0x0088dd96 ====

void Catch_0088dd96(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0088dda0 @ 0x0088dda0 ====

void FUN_0088dda0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a7a0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_0088dd10(param_1,param_3);
    param_1 = param_1 + 0x34;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0088de06 @ 0x0088de06 ====

void Catch_0088de06(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0088de10 @ 0x0088de10 ====

void FUN_0088de10(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0088dd30(param_1,param_2,param_3);
  return;
}


// ==== FUN_0088de30 @ 0x0088de30 ====

int FUN_0088de30(int param_1,int param_2,undefined4 param_3)

{
  FUN_0088dda0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x34;
}


// ==== FUN_0088de70 @ 0x0088de70 ====

void FUN_0088de70(byte param_1)

{
  void *in_ECX;
  
  FUN_0088d670();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0088de90 @ 0x0088de90 ====

void FUN_0088de90(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  uint extraout_ECX;
  undefined4 *puVar4;
  undefined4 local_60;
  uint local_24;
  undefined4 local_20;
  int local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a7b0;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x6c);
  puVar4 = &local_60;
  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_3;
    param_3 = param_3 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x34;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar3) / 0x34;
    }
    ExceptionList = &local_10;
    if (0x4ec4ec4U - iVar1 < param_2) {
      ExceptionList = &local_10;
      FUN_0085b3b0();
      local_24 = extraout_ECX;
    }
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar3) / 0x34;
    }
    if (local_24 < iVar1 + param_2) {
      if (0x4ec4ec4 - (local_24 >> 1) < local_24) {
        local_24 = 0;
      }
      else {
        local_24 = local_24 + (local_24 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x34;
      }
      if (local_24 < iVar3 + param_2) {
        iVar3 = FUN_0088cc60();
        local_24 = iVar3 + param_2;
      }
      local_24 = local_24 * 0x34;
      local_18 = operator_new(local_24);
      local_8 = 0;
      local_20 = FUN_0088de10(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_20 = FUN_0088de30(local_20,param_2,&local_60);
      FUN_0088de10(param_1,*(undefined4 *)(in_ECX + 8),local_20);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x34;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_24 + (int)local_18;
        *(void **)(in_ECX + 8) = (void *)((int)local_18 + (param_2 + iVar3) * 0x34);
        *(void **)(in_ECX + 4) = local_18;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_1c = *(int *)(in_ECX + 8);
    iVar3 = param_2 * 0x34;
    if ((uint)((local_1c - param_1) / 0x34) < param_2) {
      FUN_0088dd30(param_1,local_1c,iVar3 + param_1);
      local_8 = 2;
      FUN_0088de30(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x34,&local_60)
      ;
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar3;
      FUN_0088dcb0(param_1,*(int *)(in_ECX + 8) + param_2 * -0x34,&local_60);
      ExceptionList = local_10;
      return;
    }
    iVar1 = local_1c + param_2 * -0x34;
    uVar2 = FUN_0088dd30(iVar1,local_1c,local_1c);
    *(undefined4 *)(in_ECX + 8) = uVar2;
    FUN_0088dce0(param_1,iVar1,local_1c);
    FUN_0088dcb0(param_1,iVar3 + param_1,&local_60);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0088e04a @ 0x0088e04a ====

void Catch_0088e04a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0088e160 @ 0x0088e160 ====

void FUN_0088e160(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x34 != 0) {
      iVar1 = (param_2 - iVar1) / 0x34;
      goto LAB_0088e1a5;
    }
  }
  iVar1 = 0;
LAB_0088e1a5:
  FUN_0088de90(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x34;
  return;
}


// ==== FUN_0088e1e0 @ 0x0088e1e0 ====

void FUN_0088e1e0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x34) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x34))) {
    FUN_0088e160(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0088dda0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x34;
  return;
}


// ==== FUN_0088e2b0 @ 0x0088e2b0 ====

bool FUN_0088e2b0(void)

{
  int in_ECX;
  
  if (((*(char *)(in_ECX + 0xc) == '\0') && (*(char *)(in_ECX + 0xd) == '\0')) &&
     (*(char *)(in_ECX + 0xe) == '\0')) {
    return *(int *)(in_ECX + 0x28) != 0;
  }
  return true;
}


// ==== FUN_0088e2d0 @ 0x0088e2d0 ====

void FUN_0088e2d0(void)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *unaff_retaddr;
  undefined1 auStack_e [14];
  
  piVar1 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
  if ((uint)piVar1[7] <= piVar1[8] + 0x1000U) {
    (**(code **)(*piVar1 + 0x10))();
  }
  uVar2 = (**(code **)(*piVar1 + 0x20))(0x1000);
  *unaff_retaddr = uVar2;
  uVar3 = 0;
  do {
    uVar4 = 0;
    do {
      (**(code **)(*piVar1 + 0x18))(8,auStack_e + -6);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x10);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x10);
  FUN_00881080();
  return;
}


// ==== FUN_0088e380 @ 0x0088e380 ====

void FUN_0088e380(void)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *unaff_retaddr;
  undefined1 auStack_2 [2];
  
  piVar1 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
  if ((uint)piVar1[7] <= piVar1[8] + 0x100U) {
    (**(code **)(*piVar1 + 0x10))();
  }
  uVar2 = (**(code **)(*piVar1 + 0x20))(0x100);
  *unaff_retaddr = uVar2;
  uVar3 = 0;
  do {
    (**(code **)(*piVar1 + 0x18))(2,auStack_2 + -6);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x10);
  uVar3 = 0;
  do {
    (**(code **)(*piVar1 + 0x18))(2,auStack_2 + -6);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x10);
  uVar3 = 0;
  do {
    (**(code **)(*piVar1 + 0x18))(2,auStack_2 + -6);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x10);
  uVar3 = 0;
  do {
    (**(code **)(*piVar1 + 0x18))(2,auStack_2 + -6);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x10);
  FUN_00881080();
  return;
}


// ==== FUN_0088e480 @ 0x0088e480 ====

void FUN_0088e480(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  undefined4 unaff_EDI;
  int *piVar4;
  int local_4;
  
  piVar3 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
  piVar4 = &local_4;
  local_4 = in_ECX;
  iVar2 = (**(code **)(*piVar3 + 0x104))(piVar3,piVar4,0);
  if (-1 < iVar2) {
    piVar3 = (int *)0x0;
    if (piVar4 != (int *)0x0) {
      do {
        piVar1 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
        (**(code **)(*piVar1 + 0x108))(piVar1,piVar3);
        piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
        (**(code **)(*piVar1 + 0x148))(piVar1,2,unaff_EDI,0,0x400,local_4,0x400);
        piVar1 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
        (**(code **)(*piVar1 + 0x110))(piVar1);
        piVar3 = (int *)((int)piVar3 + 1);
      } while (piVar3 < piVar4);
    }
    piVar4 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
    (**(code **)(*piVar4 + 0x114))(piVar4);
  }
  return;
}


// ==== FUN_0088e520 @ 0x0088e520 ====

void FUN_0088e520(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined4 unaff_EBX;
  uint uVar4;
  uint unaff_retaddr;
  undefined4 *puVar5;
  
  if (*(int *)(param_3 + 4) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_3 + 8) - *(int *)(param_3 + 4) >> 2;
  }
  piVar1 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
  puVar5 = &param_3;
  iVar3 = (**(code **)(*piVar1 + 0x104))(piVar1,puVar5,0);
  if (-1 < iVar3) {
    uVar4 = 0;
    if (unaff_retaddr != 0) {
      do {
        piVar1 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
        (**(code **)(*piVar1 + 0x108))(piVar1,uVar4);
        piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
        (**(code **)(*piVar1 + 0x148))(piVar1,4,puVar5,0,0x400,unaff_EBX,iVar2 * 2);
        piVar1 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
        (**(code **)(*piVar1 + 0x110))(piVar1);
        uVar4 = uVar4 + 1;
      } while (uVar4 < unaff_retaddr);
    }
    piVar1 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
    (**(code **)(*piVar1 + 0x114))(piVar1);
  }
  return;
}


// ==== FUN_0088e5d0 @ 0x0088e5d0 ====

void FUN_0088e5d0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  undefined4 unaff_EDI;
  int *piVar4;
  int local_4;
  
  piVar3 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
  piVar4 = &local_4;
  local_4 = in_ECX;
  iVar2 = (**(code **)(*piVar3 + 0x104))(piVar3,piVar4,0);
  if (-1 < iVar2) {
    piVar3 = (int *)0x0;
    if (piVar4 != (int *)0x0) {
      do {
        piVar1 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
        (**(code **)(*piVar1 + 0x108))(piVar1,piVar3);
        piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
        (**(code **)(*piVar1 + 0x148))(piVar1,2,unaff_EDI,0,0x400,local_4,0x40);
        piVar1 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
        (**(code **)(*piVar1 + 0x110))(piVar1);
        piVar3 = (int *)((int)piVar3 + 1);
      } while (piVar3 < piVar4);
    }
    piVar4 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
    (**(code **)(*piVar4 + 0x114))(piVar4);
  }
  return;
}


// ==== FUN_0088e670 @ 0x0088e670 ====

void FUN_0088e670(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *unaff_retaddr;
  undefined1 auStack_a [10];
  
  if (*(int *)(param_2 + 4) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 2;
  }
  piVar1 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
  if ((uint)piVar1[7] <= (uint)(piVar1[8] + iVar3 * 0xc)) {
    (**(code **)(*piVar1 + 0x10))();
  }
  uVar4 = (**(code **)(*piVar1 + 0x20))(iVar3 * 0xc);
  *unaff_retaddr = uVar4;
  iVar2 = *(int *)(param_2 + 8);
  for (iVar3 = *(int *)(param_2 + 4); iVar3 != iVar2; iVar3 = iVar3 + 4) {
    (**(code **)(*piVar1 + 0x18))(6,auStack_a + -6);
  }
  FUN_00881080();
  return;
}


// ==== FUN_0088e720 @ 0x0088e720 ====

void FUN_0088e720(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x44);
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x4f)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0x88))
            (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar2 + 0x138),param_1);
  return;
}


// ==== FUN_0088e760 @ 0x0088e760 ====

void FUN_0088e760(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined4 unaff_retaddr;
  
  iVar1 = param_3;
  if ((*(int *)(param_3 + 8) != 0) &&
     (FUN_00558e70(&param_3,&param_1), iVar2 = param_3, param_3 != *(int *)(iVar1 + 4))) {
    piVar3 = (int *)FUN_00850960();
    (**(code **)(*piVar3 + 4))();
    piVar3 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
    (**(code **)(*piVar3 + 0xf0))(piVar3,s_MapGrid_00a14ec8);
    FUN_0088e720(param_2);
    FUN_0088e670(&param_1,iVar2 + 0x10);
    FUN_0084b7f0(*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 0x18));
    FUN_0088e520(unaff_retaddr,param_1,iVar2 + 0x10);
  }
  return;
}


// ==== FUN_0088e800 @ 0x0088e800 ====

void FUN_0088e800(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  undefined4 unaff_retaddr;
  undefined1 auStack_1e [30];
  
  iVar2 = param_3;
  iVar1 = param_1 * 0x3c;
  iVar3 = *(int *)(param_3 + 0xc4) + iVar1;
  if (((*(char *)(iVar3 + 0x44) != '\0') && (*(int *)(iVar3 + 0x70) != 0)) &&
     (param_3 = *(int *)(iVar3 + 0x74) - *(int *)(iVar3 + 0x70) >> 2, param_3 != 0)) {
    piVar4 = (int *)FUN_00850960();
    (**(code **)(*piVar4 + 4))();
    piVar4 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
    (**(code **)(*piVar4 + 0xf0))(piVar4,s_MapGrid_00a14ec8);
    FUN_0088e720(auStack_1e + -10);
    FUN_0088e670(&param_1,iVar1 + 0x6c + *(int *)(iVar2 + 0xc4));
    FUN_0084b7f0(*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 0x18));
    FUN_0088e520(unaff_retaddr,param_1,iVar1 + 0x6c + *(int *)(iVar2 + 0xc4));
  }
  return;
}


// ==== FUN_0088e970 @ 0x0088e970 ====

void FUN_0088e970(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *piVar8;
  int in_ECX;
  undefined1 uStack00000000;
  undefined1 auStack_18 [12];
  undefined4 uStack_c;
  undefined4 uStack_4;
  
  if (*(int *)(*(int *)(param_2 + 0xc4) + 0x40) != 0) {
    piVar8 = (int *)FUN_00850960();
    (**(code **)(*piVar8 + 4))();
    piVar8 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
    (**(code **)(*piVar8 + 0xf0))(piVar8,s_MapGrid_00a14ec8);
    puVar2 = *(undefined4 **)(*(int *)(param_2 + 0xc4) + 0x3c);
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      FUN_0040ec60(auStack_18,puVar3[3]);
      uStack_c = DAT_00a0fd50;
      if ((puVar3[5] != 0) && ((int)(puVar3[6] - puVar3[5]) >> 2 != 0)) {
        iVar4 = *(int *)(in_ECX + 0x44);
        iVar5 = *(int *)(iVar4 + 0x28);
        if ((iVar5 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar5 >> 2) < 0x4f)) {
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        (**(code **)(**(int **)(iVar4 + 0x1c) + 0x88))
                  (*(int **)(iVar4 + 0x1c),*(undefined4 *)(iVar5 + 0x138),auStack_18);
        FUN_0088e670(&uStack00000000,puVar3 + 4);
        FUN_0084b7f0(*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 0x18));
        FUN_0088e520(uStack_4,_uStack00000000,puVar3 + 4);
      }
      if (*(char *)((int)puVar3 + 0x21) == '\0') {
        puVar6 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar6 + 0x21) == '\0') {
          cVar1 = *(char *)((int)*puVar6 + 0x21);
          puVar3 = puVar6;
          puVar6 = (undefined4 *)*puVar6;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar6 + 0x21);
            puVar3 = puVar6;
            puVar6 = (undefined4 *)*puVar6;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x21);
          puVar7 = (undefined4 *)puVar3[1];
          puVar6 = puVar3;
          while ((puVar3 = puVar7, cVar1 == '\0' && (puVar6 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x21);
            puVar7 = (undefined4 *)puVar3[1];
            puVar6 = puVar3;
          }
        }
      }
    }
  }
  return;
}


// ==== FUN_0088eae0 @ 0x0088eae0 ====

void FUN_0088eae0(char *param_1)

{
  int iVar1;
  void *_Memory;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 **ppuStack_50;
  int *piStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int *piStack_40;
  char *pcStack_3c;
  undefined4 uStack_28;
  int iStack_1c;
  int local_14 [5];
  
  pcStack_3c = (char *)0x88eaf6;
  piVar2 = (int *)FUN_00850960();
  pcStack_3c = param_1;
  piStack_40 = local_14;
  uStack_44 = 0x88eb07;
  (**(code **)(*piVar2 + 8))();
  piStack_4c = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  uStack_44 = 0;
  uStack_48 = 0xe;
  ppuStack_50 = (undefined4 **)0x88eb23;
  (**(code **)(*piStack_4c + 0xe4))();
  if (*(char *)(in_ECX + 0xc) != '\0') {
    ppuStack_50 = (undefined4 **)0x88eb40;
    piVar2 = (int *)FUN_00850960();
    ppuStack_50 = (undefined4 **)0x88eb47;
    (**(code **)(*piVar2 + 4))();
    piVar2 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
    ppuStack_50 = (undefined4 **)s_MapGrid_00a14ec8;
    (**(code **)(*piVar2 + 0xf0))(piVar2);
    uVar3 = FUN_0040ec60(&piStack_40,*(undefined4 *)(in_ECX + 8));
    iVar1 = *(int *)(in_ECX + 0x44);
    iVar4 = *(int *)(iVar1 + 0x28);
    if ((iVar4 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar4 >> 2) < 0x4f)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(iVar1 + 0x1c) + 0x88))
              (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar4 + 0x138),uVar3);
    iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
    if (((*(int *)(iVar1 + 0x114) != 0) ||
        ((*(int *)(iVar1 + 0x118) != 5 || (*(int *)(iVar1 + 0x11c) != 6)))) &&
       (*(int *)(iVar1 + 100) == 0)) {
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,0);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,0);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,6);
      *(undefined4 *)(iVar1 + 0x114) = 0;
      *(undefined4 *)(iVar1 + 0x118) = 5;
      *(undefined4 *)(iVar1 + 0x11c) = 6;
    }
    FUN_0088e2d0(&ppuStack_50);
    FUN_0084b7f0(*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 0x18));
    FUN_0088e480(pcStack_3c,ppuStack_50);
    iVar1 = *(int *)(in_ECX + 0x44);
    piStack_4c = DAT_0099d080;
    uStack_48 = 0;
    uStack_44 = 0;
    piStack_40 = DAT_0099d080;
    iVar4 = *(int *)(iVar1 + 0x28);
    if ((iVar4 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar4 >> 2) < 0x4f)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(iVar1 + 0x1c) + 0x88))
              (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar4 + 0x138),&piStack_4c);
    ppuStack_50 = (undefined4 **)&pcStack_3c;
    FUN_0088e380();
    ppuStack_50 = *(undefined4 ***)(**(int **)(DAT_00b5ac04 + 0x34) + 0x18);
    FUN_0084b7f0();
    ppuStack_50 = (undefined4 **)pcStack_3c;
    FUN_0088e5d0(uStack_28);
  }
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if ((((*(int *)(iVar1 + 0x114) != 2) || (*(int *)(iVar1 + 0x118) != 5)) ||
      (*(int *)(iVar1 + 0x11c) != 2)) && (*(int *)(iVar1 + 100) == 0)) {
    ppuStack_50 = (undefined4 **)0x1;
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,2);
    *(undefined4 *)(iVar1 + 0x114) = 2;
    *(undefined4 *)(iVar1 + 0x118) = 5;
    *(undefined4 *)(iVar1 + 0x11c) = 2;
  }
  iVar1 = *(int *)(in_ECX + 4);
  ppuStack_50 = (undefined4 **)0x5;
  iVar4 = FUN_0085e3a0();
  ppuStack_50 = (undefined4 **)0x0;
  if (iVar1 != 0) {
    ppuStack_50 = (undefined4 **)0x88edc0;
    piVar2 = (int *)FUN_004af750();
    ppuStack_50 = (undefined4 **)0x88edc7;
    ppuStack_50 = (undefined4 **)(**(code **)(*piVar2 + 4))();
  }
  iVar1 = *(int *)(iVar4 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar1 >> 2) < 0x55)) {
                    /* WARNING: Subroutine does not return */
    ppuStack_50 = (undefined4 **)0x88ede3;
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar4 + 0x1c) + 0xd0))
            (*(int **)(iVar4 + 0x1c),*(undefined4 *)(iVar1 + 0x150));
  if (*(char *)(in_ECX + 0xd) != '\0') {
    FUN_0088e800(0,unaff_ESI,iStack_1c);
    FUN_0088e800(1,unaff_ESI,iStack_1c);
  }
  if (*(char *)(in_ECX + 0xe) != '\0') {
    FUN_0088e970(unaff_ESI,iStack_1c);
  }
  uStack_44 = *(undefined4 *)(DAT_00b5ac04 + 0xbc);
  piStack_40 = *(int **)(DAT_00b5ac04 + 0xc0);
  pcStack_3c = *(char **)(DAT_00b5ac04 + 0xc4);
  _Memory = *(void **)(DAT_00b5ac04 + 200);
  FUN_0088e760(*(undefined4 *)(iStack_1c + 0x2c),unaff_ESI,in_ECX + 0x20,&uStack_44);
  piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar2 + 0xe4))(piVar2,0xe,1);
  if (_Memory == (void *)0x0) {
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_0088eeb0 @ 0x0088eeb0 ====

void FUN_0088eeb0(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int *in_ECX;
  uint uVar7;
  uint *local_50;
  undefined4 local_44 [2];
  int local_3c;
  uint *local_38;
  undefined1 local_34 [4];
  void *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_18;
  undefined4 local_14 [2];
  void *local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_50 = *(uint **)(param_1 + 4);
  if (local_50 != (uint *)0x0) {
    local_38 = *(uint **)(param_1 + 8);
    param_1 = (int)local_38 - (int)local_50 >> 2;
    if ((param_1 != 0) && (uVar1 = *(uint *)(*in_ECX + 0x40), local_50 != local_38)) {
      do {
        uVar5 = *local_50 / uVar1;
        uVar7 = *local_50 % uVar1;
        iVar6 = FUN_004cd1f0(uVar7 + 1,uVar5 + 1);
        iVar3 = param_2;
        uVar2 = *(undefined4 *)(iVar6 + 0x2c);
        local_18 = *(undefined4 *)(iVar6 + 0x4c);
        iVar6 = ((*(int *)(iVar6 + 0x48) - *(int *)(iVar6 + 0x40)) *
                 (uVar5 - *(int *)(iVar6 + 0x44)) - *(int *)(iVar6 + 0x40)) + uVar7;
        param_1 = iVar6;
        local_44[0] = uVar2;
        FUN_00558e70(&local_3c,local_44);
        if (local_3c == *(int *)(iVar3 + 4)) {
          local_30 = (void *)0x0;
          local_2c = 0;
          local_28 = 0;
          FUN_0042f3e0(0,1,&param_1);
          local_14[0] = uVar2;
          FUN_00430c20(local_34);
          FUN_004d1af0(local_44,local_14);
          if (local_c != (void *)0x0) {
            _free(local_c);
            return;
          }
          local_c = (void *)0x0;
          local_8 = 0;
          local_4 = 0;
          if (local_30 != (void *)0x0) {
            _free(local_30);
            return;
          }
          local_30 = (void *)0x0;
          local_2c = 0;
          local_28 = 0;
        }
        else {
          iVar3 = *(int *)(local_3c + 0x14);
          if ((iVar3 == 0) ||
             ((uint)(*(int *)(local_3c + 0x1c) - iVar3 >> 2) <=
              (uint)(*(int *)(local_3c + 0x18) - iVar3 >> 2))) {
            FUN_0042f3e0(*(undefined4 *)(local_3c + 0x18),1,&param_1);
          }
          else {
            piVar4 = *(int **)(local_3c + 0x18);
            *piVar4 = iVar6;
            *(int **)(local_3c + 0x18) = piVar4 + 1;
          }
        }
        local_50 = local_50 + 1;
      } while (local_50 != local_38);
    }
  }
  return;
}


// ==== FUN_0088f060 @ 0x0088f060 ====

void FUN_0088f060(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  FUN_00430ad0(param_1 + 8);
  *(undefined1 *)(in_ECX + 3) = *(undefined1 *)(param_1 + 2);
  in_ECX[2] = param_1[1];
  *(undefined1 *)((int)in_ECX + 0xd) = *(undefined1 *)((int)param_1 + 0xb);
  *(undefined1 *)((int)in_ECX + 0xe) = *(undefined1 *)(param_1 + 3);
  FUN_0088eeb0(param_1 + 4,in_ECX + 8);
  return;
}


// ==== FUN_0088f0b0 @ 0x0088f0b0 ====

void FUN_0088f0b0(void)

{
  int in_ECX;
  
  FUN_004d1030(*(undefined4 *)(*(int *)(in_ECX + 0x30) + 4));
  *(int *)(*(int *)(in_ECX + 0x30) + 4) = *(int *)(in_ECX + 0x30);
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(in_ECX + 0x30);
  *(int *)(*(int *)(in_ECX + 0x30) + 8) = *(int *)(in_ECX + 0x30);
  FUN_0088f6c0(*(undefined4 *)(*(int *)(in_ECX + 0x3c) + 4));
  *(int *)(*(int *)(in_ECX + 0x3c) + 4) = *(int *)(in_ECX + 0x3c);
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)(in_ECX + 0x3c);
  *(int *)(*(int *)(in_ECX + 0x3c) + 8) = *(int *)(in_ECX + 0x3c);
  FUN_004d1030(*(undefined4 *)(*(int *)(in_ECX + 0x24) + 4));
  *(int *)(*(int *)(in_ECX + 0x24) + 4) = *(int *)(in_ECX + 0x24);
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(in_ECX + 0x24);
  *(int *)(*(int *)(in_ECX + 0x24) + 8) = *(int *)(in_ECX + 0x24);
  return;
}


// ==== FUN_0088f140 @ 0x0088f140 ====

void FUN_0088f140(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  if (*(int *)(in_ECX + 4) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  FUN_0088f720(local_4,**(undefined4 **)(in_ECX + 0x3c),*(undefined4 **)(in_ECX + 0x3c));
  _free(*(void **)(in_ECX + 0x3c));
  return;
}


// ==== FUN_0088f200 @ 0x0088f200 ====

void FUN_0088f200(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  iVar1 = FUN_004be360();
  in_ECX[9] = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(undefined4 *)(in_ECX[9] + 4) = in_ECX[9];
  *(undefined4 *)in_ECX[9] = in_ECX[9];
  *(undefined4 *)(in_ECX[9] + 8) = in_ECX[9];
  in_ECX[10] = 0;
  iVar1 = FUN_004be360();
  in_ECX[0xc] = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(undefined4 *)(in_ECX[0xc] + 4) = in_ECX[0xc];
  *(undefined4 *)in_ECX[0xc] = in_ECX[0xc];
  *(undefined4 *)(in_ECX[0xc] + 8) = in_ECX[0xc];
  in_ECX[0xd] = 0;
  iVar1 = FUN_0088f340();
  in_ECX[0xf] = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[0xf] + 4) = in_ECX[0xf];
  *(undefined4 *)in_ECX[0xf] = in_ECX[0xf];
  *(undefined4 *)(in_ECX[0xf] + 8) = in_ECX[0xf];
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_Etc_highlight_w_dds_00a14eb4,0x13);
  uVar2 = FUN_004b4e70(local_1c);
  in_ECX[1] = uVar2;
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar1 = (**(code **)(*piVar3 + 0x1c))();
  if (*(int *)(iVar1 + 8) == 0) {
    uVar2 = FUN_0085e3a0(0x16);
    in_ECX[0x11] = uVar2;
    return;
  }
  uVar2 = FUN_0085e3a0(5);
  in_ECX[0x11] = uVar2;
  return;
}


// ==== FUN_0088f320 @ 0x0088f320 ====

void FUN_0088f320(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x1d) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x1d) == '\0');
  }
  return;
}


// ==== FUN_0088f340 @ 0x0088f340 ====

void FUN_0088f340(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a7c0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x20);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 7) = 1;
  *(undefined1 *)((int)puVar1 + 0x1d) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@0088f3ca @ 0x0088f3ca ====

void Catch_0088f3ca(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_0088f3e0 @ 0x0088f3e0 ====

/* WARNING: Removing unreachable block (ram,0x0088f4f9) */
/* WARNING: Removing unreachable block (ram,0x0088f50a) */
/* WARNING: Removing unreachable block (ram,0x0088f513) */
/* WARNING: Removing unreachable block (ram,0x0088f516) */
/* WARNING: Removing unreachable block (ram,0x0088f506) */
/* WARNING: Removing unreachable block (ram,0x0088f524) */
/* WARNING: Removing unreachable block (ram,0x0088f531) */
/* WARNING: Removing unreachable block (ram,0x0088f53c) */
/* WARNING: Removing unreachable block (ram,0x0088f538) */
/* WARNING: Removing unreachable block (ram,0x0088f52c) */
/* WARNING: Removing unreachable block (ram,0x0088f53f) */

void FUN_0088f3e0(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  undefined1 local_48 [4];
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28 [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(char *)((int)param_2 + 0x1d) != '\0') {
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
            goto LAB_0088f614;
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
LAB_0088f614:
            *(undefined1 *)(piVar5 + 7) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 7) = 1;
  }
  FUN_004d1220(local_48,*(undefined4 *)param_2[5],(undefined4 *)param_2[5]);
  _free((void *)param_2[5]);
  return;
}


// ==== FUN_0088f6c0 @ 0x0088f6c0 ====

void FUN_0088f6c0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = param_1;
  if (*(char *)(param_1 + 0x1d) == '\0') {
    FUN_0088f6c0(*(undefined4 *)(param_1 + 8));
    puVar1 = *(undefined4 **)(iVar2 + 0x14);
    FUN_004d1220(&param_1,*puVar1,puVar1);
    _free(*(void **)(iVar2 + 0x14));
    return;
  }
  return;
}


// ==== FUN_0088f720 @ 0x0088f720 ====

void FUN_0088f720(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0088f6c0(piVar6[1]);
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
    FUN_0088f3e0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0088f7e0 @ 0x0088f7e0 ====

void FUN_0088f7e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a14f38;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0088f800 @ 0x0088f800 ====

uint FUN_0088f800(void)

{
  uint in_EAX;
  
  if (in_EAX < 0x11) {
    if (4 < in_EAX) {
      return (-(uint)(8 < in_EAX) & 8) + 8;
    }
    if (2 < in_EAX) {
      in_EAX = 4;
    }
    return in_EAX;
  }
  if (in_EAX < 0x41) {
    return (-(uint)(0x20 < in_EAX) & 0x20) + 0x20;
  }
  if (in_EAX < 0x81) {
    return 0x80;
  }
  if (in_EAX < 0x101) {
    return 0x100;
  }
  return (-(uint)(0x200 < in_EAX) & 0x200) + 0x200;
}


// ==== FUN_0088f8b0 @ 0x0088f8b0 ====

void FUN_0088f8b0(undefined4 param_1)

{
  int in_ECX;
  
  _BinkSetVolume_12(*(undefined4 *)(in_ECX + 0x30),0,param_1);
  return;
}


// ==== FUN_0088f8d0 @ 0x0088f8d0 ====

int FUN_0088f8d0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = param_1[1];
  iVar2 = *param_1;
  iVar4 = 0;
  iVar3 = _BinkGetRects_8(param_1,0);
  if (0 < iVar3) {
    param_1 = param_1 + 0xf;
    iVar4 = 0;
    do {
      iVar4 = iVar4 + param_1[1] * *param_1;
      param_1 = param_1 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return (iVar4 * 100) / (iVar1 * iVar2);
}


// ==== FUN_0088f920 @ 0x0088f920 ====

void FUN_0088f920(int *param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined1 *puStack_64;
  undefined1 *puStack_60;
  undefined1 *puStack_5c;
  undefined4 uStack_58;
  int *piStack_54;
  undefined1 *puStack_50;
  undefined1 *puStack_4c;
  undefined1 *puStack_48;
  undefined1 *puStack_44;
  undefined1 *puStack_40;
  undefined1 *puStack_3c;
  undefined1 auStack_1c [2];
  undefined1 auStack_1a [2];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [4];
  undefined1 auStack_c [12];
  
  _BinkDoFrame_4();
  if (param_3 == 0) {
    iVar2 = _BinkShouldSkip_4();
    if (iVar2 != 0) {
      _BinkNextFrame_4();
      puStack_3c = (undefined1 *)0x88f956;
      _BinkDoFrame_4();
    }
  }
  if (param_2 == 0) {
    iVar2 = FUN_0088f8d0();
    if (0x4a < iVar2) {
      param_2 = 1;
    }
  }
  puStack_3c = auStack_1c + -4;
  puStack_40 = auStack_1c;
  puStack_44 = auStack_18;
  puStack_48 = auStack_14;
  puStack_4c = auStack_10;
  puStack_50 = auStack_c;
  piStack_54 = (int *)0x88f99f;
  cVar1 = (**(code **)(*param_1 + 0x14))();
  if (cVar1 != '\0') {
    do {
      piStack_54 = (int *)(*(uint *)(unaff_ESI + 8 + param_2 * 4) |
                           -(uint)(param_2 != 0) & 0x80000000 | 0x80000);
      puStack_5c = puStack_40;
      puStack_60 = puStack_3c;
      uStack_68 = 0;
      uStack_6c = 0;
      puStack_64 = (undefined1 *)register0x00000010;
      _BinkCopyToBufferRect_44(param_1,unaff_EDI,param_1,param_1[1]);
      (**(code **)(*param_1 + 8))();
      cVar1 = (**(code **)(*param_1 + 0x14))
                        (&uStack_58,&puStack_5c,&puStack_60,&puStack_64,&uStack_68,&uStack_6c,
                         &puStack_4c,param_2);
    } while (cVar1 != '\0');
  }
  piStack_54 = param_1;
  uStack_58 = 0x88fa32;
  _BinkNextFrame_4();
  return;
}


// ==== FUN_0088fa40 @ 0x0088fa40 ====

void FUN_0088fa40(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = DAT_0099d080;
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_00a14f50;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0x100;
  in_ECX[0x10] = uVar1;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  in_ECX[10] = 1;
  in_ECX[0xb] = 2;
  in_ECX[2] = 3;
  in_ECX[8] = 4;
  in_ECX[3] = 5;
  in_ECX[9] = 6;
  in_ECX[4] = 9;
  in_ECX[5] = 10;
  in_ECX[6] = 8;
  in_ECX[7] = 7;
  return;
}


// ==== FUN_0088fac0 @ 0x0088fac0 ====

void FUN_0088fac0(void)

{
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x38) + 0xc))();
    if (*(undefined4 **)(in_ECX + 0x38) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x38))(1);
    }
    *(undefined4 *)(in_ECX + 0x38) = 0;
  }
  if (*(undefined4 **)(in_ECX + 0x34) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x34))(1);
  }
  *(undefined4 *)(in_ECX + 0x34) = 0;
  return;
}


// ==== FUN_0088fb00 @ 0x0088fb00 ====

void FUN_0088fb00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a14f50;
  if ((int *)in_ECX[0xe] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0xe] + 0xc))();
    if ((undefined4 *)in_ECX[0xe] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0xe])(1);
    }
    in_ECX[0xe] = 0;
  }
  if ((undefined4 *)in_ECX[0xd] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xd])(1);
  }
  in_ECX[0xd] = 0;
  *in_ECX = &PTR_FUN_00a14f38;
  return;
}


// ==== FUN_0088fb50 @ 0x0088fb50 ====

undefined4 FUN_0088fb50(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  undefined4 uVar6;
  int in_ECX;
  
  iVar1 = (*(int **)(in_ECX + 0x30))[1];
  iVar2 = **(int **)(in_ECX + 0x30);
  iVar3 = FUN_0088f800();
  if (iVar3 == iVar2) {
    iVar3 = FUN_0088f800();
    if (iVar3 != iVar1) goto LAB_0088fb74;
LAB_0088fb7d:
    pvVar4 = operator_new(0x68);
    if (pvVar4 != (void *)0x0) {
      piVar5 = (int *)FUN_00899840();
      goto LAB_0088fbad;
    }
  }
  else {
LAB_0088fb74:
    if (*(int *)(*(int *)(in_ECX + 0x34) + 0x1c) != 0) goto LAB_0088fb7d;
    pvVar4 = operator_new(0x68);
    if (pvVar4 != (void *)0x0) {
      piVar5 = (int *)FUN_00898ed0();
      goto LAB_0088fbad;
    }
  }
  piVar5 = (int *)0x0;
LAB_0088fbad:
  *(int **)(in_ECX + 0x38) = piVar5;
  iVar3 = *piVar5;
  uVar6 = FUN_0049b670(iVar2,iVar1,0,*(undefined4 *)(in_ECX + 0x3c));
  (**(code **)(iVar3 + 4))(*(undefined4 *)(in_ECX + 0x34),uVar6);
  if (*(int *)(in_ECX + 0x38) == 0) {
    return 0;
  }
  FUN_0088f920(*(undefined4 *)(in_ECX + 0x30),*(int *)(in_ECX + 0x38),1,1);
  return 1;
}


// ==== FUN_0088fc00 @ 0x0088fc00 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0088fc00(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int in_ECX;
  float fVar4;
  float fVar5;
  
  piVar3 = (int *)FUN_0049b670();
  FUN_00858a60();
  (**(code **)(*piVar3 + 0x164))(piVar3,0x104);
  iVar1 = *(int *)(in_ECX + 4);
  fVar5 = (float)*(int *)(iVar1 + 4);
  if (*(int *)(iVar1 + 4) < 0) {
    fVar5 = fVar5 + _DAT_0099d104;
  }
  fVar4 = (float)*(int *)(iVar1 + 8);
  if (*(int *)(iVar1 + 8) < 0) {
    fVar4 = fVar4 + _DAT_0099d104;
  }
  if ((fVar5 == DAT_0099cdc8) || (fVar4 == DAT_0099cdc8)) {
    piVar2 = *(int **)(in_ECX + 0x30);
    fVar5 = (float)*piVar2;
    if (*piVar2 < 0) {
      fVar5 = fVar5 + _DAT_0099d104;
    }
    fVar4 = (float)piVar2[1];
    if (piVar2[1] < 0) {
      fVar4 = fVar4 + _DAT_0099d104;
    }
  }
  (**(code **)(**(int **)(in_ECX + 0x38) + 0x10))
            (*(undefined4 *)(in_ECX + 0x34),fVar5,fVar4,0x3f800000);
  (**(code **)(*piVar3 + 0x164))(piVar3,0);
  FUN_00858b90();
  return;
}


// ==== FUN_0088fcf0 @ 0x0088fcf0 ====

void FUN_0088fcf0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = _BinkWait_4(*(undefined4 *)(in_ECX + 0x30));
  if ((iVar1 == 0) || (*(char *)(in_ECX + 0x44) != '\0')) {
    piVar2 = (int *)FUN_0049b670();
    (**(code **)(*piVar2 + 0xac))(piVar2,0,0,1,0xffffffff,0x3f800000,0);
    FUN_0088f920(*(undefined4 *)(in_ECX + 0x30),*(undefined4 *)(in_ECX + 0x38),0,0);
    FUN_0088fc00();
    return;
  }
  return;
}


// ==== FUN_0088fd50 @ 0x0088fd50 ====

uint FUN_0088fd50(undefined4 param_1,void *param_2,undefined4 param_3,undefined4 param_4,
                 uint param_5,undefined4 param_6,uint param_7)

{
  char cVar1;
  uint in_EAX;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint extraout_EAX;
  int in_ECX;
  undefined1 *unaff_retaddr;
  
  if (((*(int *)(in_ECX + 0x30) != 0) || (*(int *)(in_ECX + 0x34) != 0)) ||
     (*(int *)(in_ECX + 0x38) != 0)) {
    if (param_7 < 0x10) {
      return in_EAX & 0xffffff00;
    }
    _free(param_2);
    return extraout_EAX;
  }
  pvVar2 = operator_new(0x28);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00899c90();
  }
  *(undefined4 *)(in_ECX + 0x34) = uVar3;
  uVar3 = *(undefined4 *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x8c);
  uVar4 = FUN_0049b670();
  cVar1 = FUN_00899e30(uVar3,uVar4);
  if (cVar1 != '\0') {
    _BinkSetSoundSystem_8(_BinkOpenDirectSound_4_exref,0);
    if (param_5 < 0x10) {
      unaff_retaddr = (undefined1 *)register0x00000010;
    }
    iVar5 = _BinkOpen_8(unaff_retaddr,0x4000);
    *(int *)(in_ECX + 0x30) = iVar5;
    if ((iVar5 != 0) && (cVar1 = FUN_0088fb50(), cVar1 != '\0')) {
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0088fe30 @ 0x0088fe30 ====

void FUN_0088fe30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a14f50;
  if ((int *)in_ECX[0xe] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0xe] + 0xc))();
    if ((undefined4 *)in_ECX[0xe] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0xe])(1);
    }
    in_ECX[0xe] = 0;
  }
  if ((undefined4 *)in_ECX[0xd] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xd])(1);
  }
  in_ECX[0xd] = 0;
  *in_ECX = &PTR_FUN_00a14f38;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0088fe90 @ 0x0088fe90 ====

void FUN_0088fe90(undefined4 param_1)

{
  int in_ECX;
  
  _BinkSetVolume_12(*(undefined4 *)(in_ECX + 0xc),0,param_1);
  return;
}


// ==== FUN_0088feb0 @ 0x0088feb0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0088feb0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  float fVar4;
  undefined4 uVar5;
  int in_ECX;
  float fVar6;
  float local_14;
  
  uVar5 = DAT_009b0318;
  fVar4 = DAT_0099d0b4;
  uVar3 = DAT_0099d080;
  iVar1 = *(int *)(in_ECX + 4);
  local_14 = (float)*(int *)(iVar1 + 4);
  if (*(int *)(iVar1 + 4) < 0) {
    local_14 = local_14 + _DAT_0099d104;
  }
  fVar6 = (float)*(int *)(iVar1 + 8);
  if (*(int *)(iVar1 + 8) < 0) {
    fVar6 = fVar6 + _DAT_0099d104;
  }
  if ((local_14 == DAT_0099cdc8) || (fVar6 == 0.0)) {
    piVar2 = *(int **)(in_ECX + 0xc);
    local_14 = (float)*piVar2;
    if (*piVar2 < 0) {
      local_14 = local_14 + _DAT_0099d104;
    }
    fVar6 = (float)piVar2[1];
    if (piVar2[1] < 0) {
      fVar6 = fVar6 + _DAT_0099d104;
    }
  }
  *(undefined4 *)(in_ECX + 0x10) = DAT_009b0318;
  *(float *)(in_ECX + 0x14) = fVar4;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = uVar3;
  *(float *)(in_ECX + 0x28) = local_14 - fVar4;
  *(float *)(in_ECX + 0x2c) = fVar4;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = uVar3;
  *(undefined4 *)(in_ECX + 0x40) = uVar5;
  *(float *)(in_ECX + 0x44) = fVar6 + fVar4;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = uVar3;
  *(float *)(in_ECX + 0x58) = local_14 - fVar4;
  *(float *)(in_ECX + 0x5c) = fVar6 + fVar4;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x38) = uVar3;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x54) = uVar3;
  *(undefined4 *)(in_ECX + 100) = uVar3;
  *(undefined4 *)(in_ECX + 0x68) = uVar3;
  *(undefined4 *)(in_ECX + 0x6c) = uVar3;
  return;
}


