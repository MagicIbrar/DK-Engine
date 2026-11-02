// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x4b0000-0x4bffff

// ==== FUN_004b0040 @ 0x004b0040 ====

void FUN_004b0040(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004afce0(piVar6[1]);
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
    FUN_004af9b0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== __break @ 0x004b00fe ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_004b0100 @ 0x004b0100 ====

void FUN_004b0100(int param_1)

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
  uVar7 = FUN_004afdb0(*(undefined4 *)(*(int *)(param_1 + 4) + 4),iVar2);
  *(undefined4 *)(iVar2 + 4) = uVar7;
  piVar3 = *(int **)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  piVar4 = (int *)piVar3[1];
  if (*(char *)((int)piVar4 + 0x2d) != '\0') {
    *piVar3 = (int)piVar3;
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    return;
  }
  cVar1 = *(char *)(*piVar4 + 0x2d);
  piVar6 = (int *)*piVar4;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*piVar6 + 0x2d);
    piVar4 = piVar6;
    piVar6 = (int *)*piVar6;
  }
  *piVar3 = (int)piVar4;
  iVar2 = *(int *)(*(int *)(in_ECX + 4) + 4);
  iVar5 = *(int *)(iVar2 + 8);
  cVar1 = *(char *)(iVar5 + 0x2d);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(int *)(iVar5 + 8) + 0x2d);
    iVar2 = iVar5;
    iVar5 = *(int *)(iVar5 + 8);
  }
  *(int *)(*(int *)(in_ECX + 4) + 8) = iVar2;
  return;
}


// ==== FUN_004b0240 @ 0x004b0240 ====

void FUN_004b0240(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004b0040(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004b0270 @ 0x004b0270 ====

void FUN_004b0270(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097f9a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_004a37b0();
  *(int *)(in_ECX + 4) = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  local_8 = 0;
  FUN_004b0100(param_1);
  ExceptionList = local_10;
  return;
}


// ==== Catch@004b02e1 @ 0x004b02e1 ====

void Catch_004b02e1(void)

{
  FUN_004b0240();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004b0300 @ 0x004b0300 ====

void FUN_004b0300(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004b0040(local_4,**(undefined4 **)(in_ECX + 8),*(undefined4 **)(in_ECX + 8));
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_004b0330 @ 0x004b0330 ====

void FUN_004b0330(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004b0040(local_4,**(undefined4 **)(in_ECX + 0x14),*(undefined4 **)(in_ECX + 0x14));
  _free(*(void **)(in_ECX + 0x14));
  return;
}


// ==== FUN_004b0360 @ 0x004b0360 ====

undefined4 *
FUN_004b0360(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 *param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097f9c1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x20);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    *(undefined2 *)(puVar1 + 3) = *param_4;
    FUN_004b0270(param_4 + 2);
    *(undefined1 *)(puVar1 + 7) = param_5;
    *(undefined1 *)((int)puVar1 + 0x1d) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@004b03e8 @ 0x004b03e8 ====

void Catch_004b03e8(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004b0400 @ 0x004b0400 ====

void FUN_004b0400(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097f9d8;
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
  piVar4 = (int *)FUN_004b0360(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_004b04f9:
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
      if ((char)piVar6[7] == '\0') goto LAB_004b04f9;
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


// ==== FUN_004b05e0 @ 0x004b05e0 ====

/* WARNING: Removing unreachable block (ram,0x004b06f0) */
/* WARNING: Removing unreachable block (ram,0x004b0701) */
/* WARNING: Removing unreachable block (ram,0x004b070a) */
/* WARNING: Removing unreachable block (ram,0x004b070d) */
/* WARNING: Removing unreachable block (ram,0x004b06fd) */
/* WARNING: Removing unreachable block (ram,0x004b071b) */
/* WARNING: Removing unreachable block (ram,0x004b0728) */
/* WARNING: Removing unreachable block (ram,0x004b0733) */
/* WARNING: Removing unreachable block (ram,0x004b072f) */
/* WARNING: Removing unreachable block (ram,0x004b0723) */
/* WARNING: Removing unreachable block (ram,0x004b0736) */

void FUN_004b05e0(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  undefined1 local_54 [4];
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f9d8;
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
            goto LAB_004b0807;
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
LAB_004b0807:
            *(undefined1 *)(piVar5 + 7) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 7) = 1;
  }
  FUN_004b0040(local_54,*(undefined4 *)param_2[5],(undefined4 *)param_2[5]);
  _free((void *)param_2[5]);
  return;
}


// ==== FUN_004b08c0 @ 0x004b08c0 ====

void FUN_004b08c0(undefined4 *param_1,ushort *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x1d) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x1d) == '\0');
  }
  param_2 = (ushort *)puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_004b0400(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0046a3c0();
  }
  if (*(ushort *)((int)param_2 + 0xc) < *puVar2) {
    puVar4 = (undefined4 *)FUN_004b0400(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004b0980 @ 0x004b0980 ====

void FUN_004b0980(void *param_1)

{
  if (*(char *)((int)param_1 + 0x1d) == '\0') {
    FUN_004b0980(*(undefined4 *)((int)param_1 + 8));
    FUN_004b0330();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004b09c0 @ 0x004b09c0 ====

/* WARNING: Removing unreachable block (ram,0x004b0b0c) */
/* WARNING: Removing unreachable block (ram,0x004b0bd0) */
/* WARNING: Removing unreachable block (ram,0x004b0be5) */
/* WARNING: Removing unreachable block (ram,0x004b0bf5) */
/* WARNING: Removing unreachable block (ram,0x004b0c28) */
/* WARNING: Removing unreachable block (ram,0x004b0c34) */
/* WARNING: Removing unreachable block (ram,0x004b0e94) */
/* WARNING: Removing unreachable block (ram,0x004b0c57) */
/* WARNING: Removing unreachable block (ram,0x004b0e9d) */
/* WARNING: Removing unreachable block (ram,0x004b0f1e) */
/* WARNING: Removing unreachable block (ram,0x004b0ec1) */
/* WARNING: Removing unreachable block (ram,0x004b0f03) */
/* WARNING: Removing unreachable block (ram,0x004b0fa6) */
/* WARNING: Removing unreachable block (ram,0x004b0c70) */
/* WARNING: Removing unreachable block (ram,0x004b0bad) */
/* WARNING: Removing unreachable block (ram,0x004b0c7c) */
/* WARNING: Removing unreachable block (ram,0x004b0fb4) */
/* WARNING: Removing unreachable block (ram,0x004b0c9f) */
/* WARNING: Removing unreachable block (ram,0x004b0cd1) */
/* WARNING: Removing unreachable block (ram,0x004b0cfc) */
/* WARNING: Removing unreachable block (ram,0x004b0d1c) */
/* WARNING: Removing unreachable block (ram,0x004b0d9a) */
/* WARNING: Removing unreachable block (ram,0x004b0ce9) */
/* WARNING: Removing unreachable block (ram,0x004b0cb8) */
/* WARNING: Removing unreachable block (ram,0x004b0df5) */
/* WARNING: Removing unreachable block (ram,0x004b0a87) */
/* WARNING: Removing unreachable block (ram,0x004b0b3f) */
/* WARNING: Removing unreachable block (ram,0x004b0b45) */
/* WARNING: Removing unreachable block (ram,0x004b0b5a) */
/* WARNING: Removing unreachable block (ram,0x004b0ba1) */
/* WARNING: Removing unreachable block (ram,0x004b0e8b) */
/* WARNING: Removing unreachable block (ram,0x004b0b6e) */
/* WARNING: Removing unreachable block (ram,0x004b0e82) */

void FUN_004b09c0(undefined4 param_1,uint *param_2)

{
  void *_Memory;
  uint uVar1;
  void *local_b4;
  uint local_a0;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097fa52;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  _Memory = (void *)FUN_004a37b0();
  *(undefined1 *)((int)_Memory + 0x2d) = 1;
  *(void **)((int)_Memory + 4) = _Memory;
  *(void **)_Memory = _Memory;
  *(void **)((int)_Memory + 8) = _Memory;
  local_4 = CONCAT31(local_4._1_3_,1);
  uVar1 = FUN_00411430();
  if (*param_2 < uVar1) {
    do {
      FUN_00411510();
      local_4._0_1_ = 2;
      FUN_00405670();
      FUN_00402220();
      local_4._0_1_ = 3;
      FUN_00401660();
      if (0xf < local_a0) {
        _free(local_b4);
        return;
      }
      local_b4 = (void *)((uint)local_b4 & 0xffffff00);
      local_4 = CONCAT31(local_4._1_3_,1);
      local_a0 = 0xf;
      *param_2 = *param_2 + 1;
      uVar1 = FUN_00411430();
    } while (*param_2 < uVar1);
  }
  local_4 = local_4 & 0xffffff00;
  FUN_004b0040();
  _free(_Memory);
  return;
}


// ==== FUN_004b0fc0 @ 0x004b0fc0 ====

/* WARNING: Removing unreachable block (ram,0x004b123d) */

undefined4 FUN_004b0fc0(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  uint uVar4;
  undefined4 extraout_EAX_01;
  int in_ECX;
  uint uVar5;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  int iStack_3c;
  undefined4 uStack_38;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097fa74;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 != 9) {
    ExceptionList = pvStack_c;
    return 0;
  }
  uVar3 = FUN_00402220(auStack_44,in_ECX + 4,s_Loading______009afad8);
  uStack_4 = 0;
  FUN_00796d50(uVar3);
  uStack_4 = 0xffffffff;
  if (0xf < uStack_2c) {
    _free(pvStack_40);
    return extraout_EAX;
  }
  FUN_004b0980(*(undefined4 *)(*(int *)(in_ECX + 0x40) + 4));
  *(int *)(*(int *)(in_ECX + 0x40) + 4) = *(int *)(in_ECX + 0x40);
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(in_ECX + 0x40);
  *(int *)(*(int *)(in_ECX + 0x40) + 8) = *(int *)(in_ECX + 0x40);
  uVar5 = 0;
  param_1 = (int *)0x0;
  iVar2 = FUN_00411430();
  if (iVar2 != 0) {
    do {
      uVar3 = FUN_00411510(uVar5);
      pvStack_40 = (void *)0x0;
      iStack_3c = 0;
      uStack_38 = 0;
      uStack_4 = 1;
      FUN_00405670(uVar3,auStack_44);
      if ((pvStack_40 == (void *)0x0) ||
         (iVar2 = iStack_3c - (int)pvStack_40 >> 0x1f,
         (iStack_3c - (int)pvStack_40) / 0x1c + iVar2 == iVar2)) {
        uStack_4 = 0xffffffff;
        if (pvStack_40 != (void *)0x0) {
          FUN_00405de0(pvStack_40,iStack_3c,auStack_44,param_1);
          goto LAB_004b118b;
        }
      }
      else {
        iVar2 = FUN_00403620(0,*(undefined4 *)((int)pvStack_40 + 0x14),s_<cate>_009afae8,6);
        if (iVar2 == 0) {
          if ((pvStack_40 == (void *)0x0) || ((uint)((iStack_3c - (int)pvStack_40) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          uVar3 = thunk_FUN_00796fb0((int)pvStack_40 + 0x1c);
          FUN_004b09c0(piVar1,&param_1,uVar3);
        }
        uStack_4 = 0xffffffff;
        if (pvStack_40 != (void *)0x0) {
          FUN_00405de0(pvStack_40,iStack_3c,auStack_44,param_1);
LAB_004b118b:
          _free(pvStack_40);
          return extraout_EAX_00;
        }
      }
      uStack_4 = 0xffffffff;
      uVar5 = (int)param_1 + 1;
      pvStack_40 = (void *)0x0;
      iStack_3c = 0;
      uStack_38 = 0;
      param_1 = (int *)uVar5;
      uVar4 = FUN_00411430();
    } while (uVar5 < uVar4);
  }
  uVar3 = FUN_00402220(auStack_28,in_ECX + 4,s_Loading_End___009afaf0);
  uStack_4 = 2;
  FUN_00796d50(uVar3);
  uStack_4 = 0xffffffff;
  if (pvStack_10 < 0x10) {
    pvStack_10 = (void *)0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    uVar3 = (**(code **)(*piVar1 + 0x10))();
    *(undefined4 *)(in_ECX + 0x28) = uVar3;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    *(undefined4 *)(in_ECX + 0x34) = 2;
    (**(code **)*piVar1)(1);
    ExceptionList = pvStack_10;
    return 1;
  }
  _free(pvStack_24);
  return extraout_EAX_01;
}


// ==== FUN_004b1250 @ 0x004b1250 ====

void FUN_004b1250(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097fa86;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009afb50;
  local_4 = 0;
  FUN_004b1380(local_10,*(undefined4 *)in_ECX[0x10],(undefined4 *)in_ECX[0x10]);
  _free((void *)in_ECX[0x10]);
  return;
}


// ==== FUN_004b12d0 @ 0x004b12d0 ====

void FUN_004b12d0(undefined4 param_1)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097faa3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0xffffffff;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  local_4 = 0;
  *in_ECX = &PTR_FUN_009afb50;
  iVar1 = FUN_004af930();
  in_ECX[0x10] = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[0x10] + 4) = in_ECX[0x10];
  *(undefined4 *)in_ECX[0x10] = in_ECX[0x10];
  *(undefined4 *)(in_ECX[0x10] + 8) = in_ECX[0x10];
  in_ECX[0x11] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004b1380 @ 0x004b1380 ====

void FUN_004b1380(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004b0980(piVar6[1]);
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
    FUN_004b05e0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004b1440 @ 0x004b1440 ====

void FUN_004b1440(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004b1380(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004b1470 @ 0x004b1470 ====

int FUN_004b1470(void)

{
  int in_ECX;
  
  return in_ECX + 0x3c;
}


// ==== FUN_004b1480 @ 0x004b1480 ====

void FUN_004b1480(byte param_1)

{
  void *in_ECX;
  
  FUN_004b1250();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004b14a0 @ 0x004b14a0 ====

void FUN_004b14a0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  for (; param_1 != param_2; param_1 = param_1 + 8) {
    if (param_3 != (undefined4 *)0x0) {
      puVar2 = param_1;
      puVar3 = param_3;
      for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    param_3 = param_3 + 8;
  }
  return;
}


// ==== FUN_004b14d0 @ 0x004b14d0 ====

void FUN_004b14d0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_004b14d0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004b1510 @ 0x004b1510 ====

void FUN_004b1510(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_2 != 0) {
    do {
      if (param_1 != (undefined4 *)0x0) {
        puVar2 = param_3;
        puVar3 = param_1;
        for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
      }
      param_1 = param_1 + 8;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_004b1540 @ 0x004b1540 ====

int FUN_004b1540(int param_1,int param_2,undefined4 param_3)

{
  FUN_004b1510(param_1,param_2,param_3);
  return param_2 * 0x20 + param_1;
}


// ==== FUN_004b1570 @ 0x004b1570 ====

void FUN_004b1570(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097fab8;
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
LAB_004b1669:
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
      if ((char)piVar6[5] == '\0') goto LAB_004b1669;
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


// ==== FUN_004b1750 @ 0x004b1750 ====

void FUN_004b1750(void)

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
  puStack_8 = &LAB_0097fab8;
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


// ==== FUN_004b17c0 @ 0x004b17c0 ====

/* WARNING: Removing unreachable block (ram,0x004b18d3) */
/* WARNING: Removing unreachable block (ram,0x004b18e3) */
/* WARNING: Removing unreachable block (ram,0x004b18ec) */
/* WARNING: Removing unreachable block (ram,0x004b18ef) */
/* WARNING: Removing unreachable block (ram,0x004b18df) */
/* WARNING: Removing unreachable block (ram,0x004b18fd) */
/* WARNING: Removing unreachable block (ram,0x004b190a) */
/* WARNING: Removing unreachable block (ram,0x004b1915) */
/* WARNING: Removing unreachable block (ram,0x004b1911) */
/* WARNING: Removing unreachable block (ram,0x004b1905) */
/* WARNING: Removing unreachable block (ram,0x004b1918) */

void FUN_004b17c0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0097fab8;
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
            goto LAB_004b19e5;
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
LAB_004b19e5:
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


// ==== FUN_004b1a70 @ 0x004b1a70 ====

void FUN_004b1a70(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_004b1570(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_004b1570(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004b1b30 @ 0x004b1b30 ====

void FUN_004b1b30(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  undefined4 local_34;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097fad0;
  local_10 = ExceptionList;
  iVar5 = *(int *)(in_ECX + 4);
  local_14 = (undefined1 *)((int)register0x00000010 + -0x40);
  puVar6 = &local_34;
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *param_3;
    param_3 = param_3 + 1;
    puVar6 = puVar6 + 1;
  }
  if (iVar5 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(in_ECX + 0xc) - iVar5 >> 5;
  }
  uVar7 = CONCAT44(iVar5,iVar4);
  if (param_2 != 0) {
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 8) - iVar5 >> 5;
    }
    ExceptionList = &local_10;
    if (0x7ffffffU - iVar5 < param_2) {
      ExceptionList = &local_10;
      uVar7 = FUN_004b1750();
    }
    iVar5 = (int)((ulonglong)uVar7 >> 0x20);
    uVar1 = (uint)uVar7;
    if (iVar5 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 8) - iVar5 >> 5;
    }
    if (uVar1 < iVar4 + param_2) {
      if (0x7ffffff - (uVar1 >> 1) < uVar1) {
        uVar1 = 0;
      }
      else {
        uVar1 = uVar1 + (uVar1 >> 1);
      }
      if (iVar5 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(in_ECX + 8) - iVar5 >> 5;
      }
      if (uVar1 < iVar4 + param_2) {
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(in_ECX + 8) - iVar5 >> 5;
        }
        uVar1 = iVar5 + param_2;
      }
      pvVar2 = operator_new(uVar1 * 0x20);
      local_8 = 0;
      iVar5 = FUN_004b14a0(*(undefined4 *)(in_ECX + 4),param_1,pvVar2);
      FUN_004b1510(iVar5,param_2,&local_34);
      FUN_004b14a0(param_1,*(undefined4 *)(in_ECX + 8),iVar5 + param_2 * 0x20);
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - (int)_Memory >> 5;
      }
      if (_Memory == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 0x20 + (int)pvVar2);
        *(void **)(in_ECX + 8) = (void *)((param_2 + iVar5) * 0x20 + (int)pvVar2);
        *(void **)(in_ECX + 4) = pvVar2;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar5 = *(int *)(in_ECX + 8);
    if ((uint)(iVar5 - param_1 >> 5) < param_2) {
      FUN_004b14a0(param_1,iVar5,param_2 * 0x20 + param_1);
      local_8 = 2;
      FUN_004b1540(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 5),&local_34);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x20;
      FUN_005d27e0(param_1,*(int *)(in_ECX + 8) + param_2 * -0x20,&local_34);
      ExceptionList = local_10;
      return;
    }
    iVar4 = iVar5 + param_2 * -0x20;
    uVar3 = FUN_004b14a0(iVar4,iVar5,iVar5);
    *(undefined4 *)(in_ECX + 8) = uVar3;
    FUN_005d2810(param_1,iVar4,iVar5);
    FUN_005d27e0(param_1,param_2 * 0x20 + param_1,&local_34);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004b1ca0 @ 0x004b1ca0 ====

void Catch_004b1ca0(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_004b1d80 @ 0x004b1d80 ====

void FUN_004b1d80(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004b14d0(piVar6[1]);
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
    FUN_004b17c0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004b1e40 @ 0x004b1e40 ====

void FUN_004b1e40(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 5) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 5))) {
    FUN_004b1b30(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_004b1510(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x20;
  return;
}


// ==== FUN_004b1eb0 @ 0x004b1eb0 ====

void FUN_004b1eb0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004b1d80(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004b1ee0 @ 0x004b1ee0 ====

void FUN_004b1ee0(undefined4 param_1)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097faf3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0xffffffff;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  local_4 = 0;
  *in_ECX = &PTR_FUN_009afc94;
  iVar1 = FUN_0058d7c0();
  in_ECX[0x10] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[0x10] + 4) = in_ECX[0x10];
  *(undefined4 *)in_ECX[0x10] = in_ECX[0x10];
  *(undefined4 *)(in_ECX[0x10] + 8) = in_ECX[0x10];
  in_ECX[0x11] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004b1f90 @ 0x004b1f90 ====

/* WARNING: Removing unreachable block (ram,0x004b2337) */

void FUN_004b1f90(undefined4 param_1,uint *param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  float10 fVar5;
  char *pcVar6;
  undefined *puVar7;
  undefined1 local_4c [4];
  void *local_48;
  int local_44;
  undefined4 local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined1 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097fb05;
  local_c = ExceptionList;
  if (param_3 != 0) {
    local_3c = DAT_0099d080;
    local_38 = DAT_0099d080;
    local_34 = DAT_0099d080;
    local_30 = DAT_0099d080;
    local_24 = DAT_0099d080;
    local_20 = DAT_0099d080;
    local_2c = DAT_0099d080;
    local_28 = 0.0;
    local_10 = 0;
    local_1c = DAT_0099d080;
    local_18 = DAT_0099d080;
    local_14 = 0;
    ExceptionList = &local_c;
    uVar2 = FUN_00411430();
    if (*param_2 < uVar2) {
      do {
        uVar3 = FUN_00411510(*param_2);
        local_48 = (void *)0x0;
        local_44 = 0;
        local_40 = 0;
        local_4 = 0;
        FUN_00405670(uVar3,local_4c);
        if ((local_48 == (void *)0x0) ||
           (iVar4 = local_44 - (int)local_48 >> 0x1f,
           (local_44 - (int)local_48) / 0x1c + iVar4 == iVar4)) {
          local_4 = 0xffffffff;
          if (local_48 != (void *)0x0) {
            FUN_00405de0(local_48,local_44,local_4c,param_1);
            _free(local_48);
            return;
          }
LAB_004b20ff:
          local_4 = 0xffffffff;
          local_48 = (void *)0x0;
          local_44 = 0;
          local_40 = 0;
        }
        else {
          iVar4 = FUN_00403620(0,*(undefined4 *)((int)local_48 + 0x14),s_<FLARE>_009afc38,7);
          if (iVar4 == 0) {
            local_4 = 0xffffffff;
            if (local_48 != (void *)0x0) {
              FUN_00405de0(local_48,local_44,local_4c,param_1);
              _free(local_48);
              return;
            }
            goto LAB_004b20ff;
          }
          if ((local_48 == (void *)0x0) || ((local_44 - (int)local_48) / 0x1c == 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar4 = FUN_00403620(0,*(undefined4 *)((int)local_48 + 0x14),s_<_FLARE>_009afc40,8);
          if (iVar4 == 0) {
            FUN_004b1e40(&local_2c);
            FUN_00406250();
            ExceptionList = local_c;
            return;
          }
          if ((local_48 == (void *)0x0) || ((local_44 - (int)local_48) / 0x1c == 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar4 = FUN_00403620(0,*(undefined4 *)((int)local_48 + 0x14),&DAT_009afc4c,4);
          if (iVar4 == 0) {
            uVar3 = FUN_00405d30(1);
            fVar5 = (float10)thunk_FUN_00796ec0(uVar3);
            local_2c = (float)fVar5;
          }
          else {
            pcVar6 = s_linepos_009afc54;
            uVar3 = FUN_00405d30(0);
            cVar1 = FUN_004036a0(uVar3,pcVar6);
            if (cVar1 == '\0') {
              pcVar6 = s_color_009afc5c;
              uVar3 = FUN_00405d30(0);
              cVar1 = FUN_004036a0(uVar3,pcVar6);
              if (cVar1 == '\0') {
                pcVar6 = s_obscured_009afc64;
                uVar3 = FUN_00405d30(0);
                cVar1 = FUN_004036a0(uVar3,pcVar6);
                if (cVar1 == '\0') {
                  pcVar6 = s_textureid_009afc80;
                  uVar3 = FUN_00405d30(0);
                  cVar1 = FUN_004036a0(uVar3,pcVar6);
                  if (cVar1 != '\0') {
                    uVar3 = FUN_00405d30(1);
                    local_10 = thunk_FUN_00796fb0(uVar3);
                  }
                }
                else {
                  puVar7 = &DAT_009afc70;
                  uVar3 = FUN_00405d30(1);
                  cVar1 = FUN_004036a0(uVar3,puVar7);
                  if (cVar1 == '\0') {
                    pcVar6 = s_false_009afc78;
                    uVar3 = FUN_00405d30(1);
                    cVar1 = FUN_004036a0(uVar3,pcVar6);
                    if (cVar1 != '\0') {
                      local_14 = 0;
                    }
                  }
                  else {
                    local_14 = 1;
                  }
                }
              }
              else {
                uVar3 = FUN_00405d30(1);
                fVar5 = (float10)thunk_FUN_00796ec0(uVar3);
                local_24 = (float)(fVar5 * (float10)DAT_0099d0b0);
                uVar3 = FUN_00405d30(2);
                fVar5 = (float10)thunk_FUN_00796ec0(uVar3);
                local_20 = (float)(fVar5 * (float10)DAT_0099d0b0);
                uVar3 = FUN_00405d30(3);
                fVar5 = (float10)thunk_FUN_00796ec0(uVar3);
                local_18 = DAT_0099d080;
                local_1c = (float)(fVar5 * (float10)DAT_0099d0b0);
              }
            }
            else {
              uVar3 = FUN_00405d30(1);
              fVar5 = (float10)thunk_FUN_00796ec0(uVar3);
              local_28 = (float)fVar5;
            }
          }
          local_4 = 0xffffffff;
          FUN_00406250();
        }
        *param_2 = *param_2 + 1;
        uVar2 = FUN_00411430();
      } while (*param_2 < uVar2);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004b2390 @ 0x004b2390 ====

/* WARNING: Removing unreachable block (ram,0x004b2626) */

void FUN_004b2390(undefined4 param_1,uint *param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  undefined1 local_38 [4];
  void *local_34;
  int local_30;
  undefined4 local_2c;
  undefined1 local_28 [4];
  void *local_24;
  int local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097fb1f;
  local_c = ExceptionList;
  if (param_3 != 0) {
    ExceptionList = &local_c;
    uVar2 = FUN_00411430();
    if (*param_2 < uVar2) {
      do {
        uVar3 = FUN_00411510(*param_2);
        local_34 = (void *)0x0;
        local_30 = 0;
        local_2c = 0;
        local_4 = 0;
        FUN_00405670(uVar3,local_38);
        if ((local_34 == (void *)0x0) ||
           (iVar4 = local_30 - (int)local_34 >> 0x1f,
           (local_30 - (int)local_34) / 0x1c + iVar4 == iVar4)) {
          local_4 = 0xffffffff;
          if (local_34 != (void *)0x0) {
            FUN_00405de0(local_34,local_30,local_38,param_1);
            _free(local_34);
            return;
          }
LAB_004b24b8:
          local_4 = 0xffffffff;
          local_34 = (void *)0x0;
          local_30 = 0;
          local_2c = 0;
        }
        else {
          iVar4 = FUN_00403620(0,*(undefined4 *)((int)local_34 + 0x14),s_<LENSFLARE>_009afc08,0xb);
          if (iVar4 == 0) {
            local_4 = 0xffffffff;
            if (local_34 != (void *)0x0) {
              FUN_00405de0(local_34,local_30,local_38,param_1);
              _free(local_34);
              return;
            }
            goto LAB_004b24b8;
          }
          if ((local_34 == (void *)0x0) || ((local_30 - (int)local_34) / 0x1c == 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar4 = FUN_00403620(0,*(undefined4 *)((int)local_34 + 0x14),s_<_LENSFLARE>_009afc14,0xc);
          if (iVar4 == 0) {
            FUN_00406250();
            ExceptionList = local_c;
            return;
          }
          if ((local_34 == (void *)0x0) || ((local_30 - (int)local_34) / 0x1c == 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar4 = FUN_00403620(0,*(undefined4 *)((int)local_34 + 0x14),s_texturefile_009afc24,0xb);
          if (iVar4 == 0) {
            uVar3 = FUN_00405d30(1);
            local_10 = 0xf;
            local_14 = 0;
            local_24 = (void *)((uint)local_24 & 0xffffff00);
            FUN_00401660(uVar3,0,0xffffffff);
            local_4 = CONCAT31(local_4._1_3_,1);
            if (local_14 != 0) {
              FUN_00406720(local_28);
            }
            if (0xf < local_10) {
              _free(local_24);
              return;
            }
            local_10 = 0xf;
            local_14 = 0;
            local_24 = (void *)((uint)local_24 & 0xffffff00);
          }
          else {
            pcVar5 = s_<FLARE>_009afc30;
            uVar3 = FUN_00405d30(0);
            cVar1 = FUN_004036a0(uVar3,pcVar5);
            if (cVar1 != '\0') {
              FUN_004b1f90(param_1,param_2,param_3 + 4);
            }
          }
          local_4 = 0xffffffff;
          FUN_00406250();
        }
        *param_2 = *param_2 + 1;
        uVar2 = FUN_00411430();
      } while (*param_2 < uVar2);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004b2660 @ 0x004b2660 ====

/* WARNING: Removing unreachable block (ram,0x004b2932) */

void FUN_004b2660(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  void *local_2c;
  void *local_28;
  undefined1 local_24 [8];
  undefined1 local_1c [4];
  void *local_18;
  int local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097fb47;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_2c = operator_new(0x2c);
  if (local_2c == (void *)0x0) {
    local_2c = (void *)0x0;
  }
  else {
    *(undefined ***)((int)local_2c + 4) = &PTR_FUN_009afccc;
    *(undefined4 *)((int)local_2c + 0xc) = 0;
    *(undefined4 *)((int)local_2c + 0x10) = 0;
    *(undefined4 *)((int)local_2c + 0x14) = 0;
    *(undefined4 *)((int)local_2c + 0x1c) = 0;
    *(undefined4 *)((int)local_2c + 0x20) = 0;
    *(undefined4 *)((int)local_2c + 0x24) = 0;
  }
  local_4 = 0xffffffff;
  uVar1 = FUN_00411430();
  if (*param_2 < uVar1) {
    do {
      uVar2 = FUN_00411510(*param_2);
      local_18 = (void *)0x0;
      local_14 = 0;
      local_10 = 0;
      local_4 = 2;
      FUN_00405670(uVar2,local_1c);
      if ((local_18 == (void *)0x0) ||
         (iVar3 = local_14 - (int)local_18 >> 0x1f,
         (local_14 - (int)local_18) / 0x1c + iVar3 == iVar3)) {
        local_4 = 0xffffffff;
        if (local_18 != (void *)0x0) {
          FUN_00405de0(local_18,local_14,local_1c,param_1);
          goto LAB_004b28f1;
        }
      }
      else {
        iVar3 = FUN_00403620(0,*(undefined4 *)((int)local_18 + 0x14),s_<SKYEFFECT>_009afbd4,0xb);
        if (iVar3 == 0) {
          local_4 = 0xffffffff;
          if (local_18 != (void *)0x0) {
            FUN_00405de0(local_18,local_14,local_1c,param_1);
LAB_004b28f1:
            _free(local_18);
            return;
          }
        }
        else {
          if ((local_18 == (void *)0x0) || ((local_14 - (int)local_18) / 0x1c == 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar3 = FUN_00403620(0,*(undefined4 *)((int)local_18 + 0x14),s_<_SKYEFFECT>_009afbe0,0xc);
          if (iVar3 == 0) {
            local_28 = local_2c;
            local_2c = *(void **)((int)local_2c + 0x28);
            FUN_004b1a70(local_24,&local_2c);
            if (local_18 == (void *)0x0) {
              ExceptionList = local_c;
              return;
            }
            FUN_00405de0(local_18,local_14,local_1c,param_1);
            _free(local_18);
            return;
          }
          if ((local_18 == (void *)0x0) || ((local_14 - (int)local_18) / 0x1c == 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar3 = FUN_00403620(0,*(undefined4 *)((int)local_18 + 0x14),s_timeofday_009afbf0,9);
          if (iVar3 == 0) {
            if ((local_18 == (void *)0x0) || ((uint)((local_14 - (int)local_18) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
              FUN_00405ca0();
            }
            uVar2 = thunk_FUN_00796fb0((int)local_18 + 0x1c);
            *(undefined4 *)((int)local_2c + 0x28) = uVar2;
          }
          else {
            if ((local_18 == (void *)0x0) || ((local_14 - (int)local_18) / 0x1c == 0)) {
                    /* WARNING: Subroutine does not return */
              FUN_00405ca0();
            }
            iVar3 = FUN_00403620(0,*(undefined4 *)((int)local_18 + 0x14),s_<LENSFLARE>_009afbfc,0xb)
            ;
            if (iVar3 == 0) {
              FUN_004b2390(param_1,param_2,local_2c);
            }
          }
          local_4 = 0xffffffff;
          if (local_18 != (void *)0x0) {
            FUN_00405de0(local_18,local_14,local_1c,param_1);
            goto LAB_004b28f1;
          }
        }
      }
      local_4 = 0xffffffff;
      *param_2 = *param_2 + 1;
      local_18 = (void *)0x0;
      local_14 = 0;
      local_10 = 0;
      uVar1 = FUN_00411430();
    } while (*param_2 < uVar1);
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004b29d0 @ 0x004b29d0 ====

/* WARNING: Removing unreachable block (ram,0x004b2ba8) */

undefined4 FUN_004b29d0(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  int iStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097fb59;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 != 9) {
    ExceptionList = pvStack_c;
    return 0;
  }
  uVar5 = 0;
  param_1 = (int *)0x0;
  iVar2 = FUN_00411430();
  if (iVar2 != 0) {
    do {
      uVar3 = FUN_00411510(uVar5);
      pvStack_18 = (void *)0x0;
      iStack_14 = 0;
      pvStack_10 = (void *)0x0;
      uStack_4 = 0;
      FUN_00405670(uVar3,auStack_1c);
      if (((pvStack_18 == (void *)0x0) ||
          (iVar2 = iStack_14 - (int)pvStack_18 >> 0x1f,
          (iStack_14 - (int)pvStack_18) / 0x1c + iVar2 == iVar2)) ||
         (iVar2 = FUN_00403620(0,*(undefined4 *)((int)pvStack_18 + 0x14),&DAT_009afbc4,1),
         iVar2 == 0)) {
        uStack_4 = 0xffffffff;
        if (pvStack_18 != (void *)0x0) {
          FUN_00405de0(pvStack_18,iStack_14,auStack_1c,param_1);
          goto LAB_004b2b47;
        }
      }
      else {
        if ((pvStack_18 == (void *)0x0) || ((iStack_14 - (int)pvStack_18) / 0x1c == 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        iVar2 = FUN_00403620(0,*(undefined4 *)((int)pvStack_18 + 0x14),s_<SKYEFFECT>_009afbc8,0xb);
        if (iVar2 == 0) {
          FUN_004b2660(piVar1,&param_1);
          uVar5 = (uint)param_1;
        }
        uStack_4 = 0xffffffff;
        if (pvStack_18 != (void *)0x0) {
          FUN_00405de0(pvStack_18,iStack_14,auStack_1c,param_1);
LAB_004b2b47:
          _free(pvStack_18);
          return extraout_EAX;
        }
      }
      uStack_4 = 0xffffffff;
      uVar5 = uVar5 + 1;
      pvStack_18 = (void *)0x0;
      iStack_14 = 0;
      pvStack_10 = (void *)0x0;
      param_1 = (int *)uVar5;
      uVar4 = FUN_00411430();
    } while (uVar5 < uVar4);
  }
  uVar3 = (**(code **)(*piVar1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar3;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 2;
  (**(code **)*piVar1)(1);
  ExceptionList = pvStack_10;
  return 1;
}


// ==== FUN_004b2bc0 @ 0x004b2bc0 ====

void FUN_004b2bc0(void)

{
  undefined4 *in_ECX;
  uint local_14 [2];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097fb76;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009afc94;
  local_4 = 1;
  if (in_ECX[0x11] != 0) {
    local_14[0] = local_14[0] & 0xffffff00;
    FUN_004b2da0(*(undefined4 *)in_ECX[0x10],(undefined4 *)in_ECX[0x10],local_14[0]);
    FUN_004b14d0(*(undefined4 *)(in_ECX[0x10] + 4));
    *(undefined4 *)(in_ECX[0x10] + 4) = in_ECX[0x10];
    in_ECX[0x11] = 0;
    *(undefined4 *)in_ECX[0x10] = in_ECX[0x10];
    *(undefined4 *)(in_ECX[0x10] + 8) = in_ECX[0x10];
  }
  local_4 = local_4 & 0xffffff00;
  FUN_004b1d80(local_14,*(undefined4 *)in_ECX[0x10],(undefined4 *)in_ECX[0x10]);
  _free((void *)in_ECX[0x10]);
  return;
}


// ==== FUN_004b2c80 @ 0x004b2c80 ====

undefined4 FUN_004b2c80(void)

{
  return 0x1b;
}


// ==== FUN_004b2c90 @ 0x004b2c90 ====

void FUN_004b2c90(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  undefined4 *local_4;
  
  *in_ECX = &PTR_FUN_009afccc;
  _Memory = (void *)in_ECX[2];
  local_4 = in_ECX;
  if ((_Memory != (void *)0x0) &&
     (local_4 = (undefined4 *)(in_ECX[3] - (int)_Memory >> 5), local_4 != (undefined4 *)0x0)) {
    if (_Memory != (void *)0x0) {
      _free(_Memory);
      return;
    }
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
  }
  if (in_ECX[6] != 0) {
    local_4 = (undefined4 *)((int)(in_ECX[7] - in_ECX[6]) / 0x1c);
    if (local_4 != (undefined4 *)0x0) {
      if (in_ECX[6] != 0) {
        FUN_00405de0(in_ECX[6],in_ECX[7],in_ECX + 5,local_4);
        _free((void *)in_ECX[6]);
        return;
      }
      in_ECX[6] = 0;
      in_ECX[7] = 0;
      in_ECX[8] = 0;
    }
  }
  if (in_ECX[6] != 0) {
    FUN_00405de0(in_ECX[6],in_ECX[7],in_ECX + 5,local_4);
    _free((void *)in_ECX[6]);
    return;
  }
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_004b2d70 @ 0x004b2d70 ====

void FUN_004b2d70(byte param_1)

{
  void *in_ECX;
  
  FUN_004b2c90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004b2d90 @ 0x004b2d90 ====

void FUN_004b2d90(void)

{
  FUN_004b2c90();
  return;
}


// ==== FUN_004b2da0 @ 0x004b2da0 ====

uint FUN_004b2da0(int *param_1,int *param_2,byte param_3)

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
    _Memory = (void *)param_1[4];
    if (_Memory != (void *)0x0) break;
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
  FUN_004b2d90();
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_004b2e20 @ 0x004b2e20 ====

void FUN_004b2e20(byte param_1)

{
  void *in_ECX;
  
  FUN_004b2bc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004b2e40 @ 0x004b2e40 ====

void FUN_004b2e40(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x38) = 1;
  return;
}


// ==== FUN_004b2e50 @ 0x004b2e50 ====

int FUN_004b2e50(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0x44) - *(int *)(in_ECX + 0x40) >> 2;
}


// ==== FUN_004b2e70 @ 0x004b2e70 ====

undefined4 FUN_004b2e70(uint param_1)

{
  int in_ECX;
  int extraout_EDX;
  int iVar1;
  
  if ((*(int *)(in_ECX + 0x40) == 0) ||
     ((uint)(*(int *)(in_ECX + 0x44) - *(int *)(in_ECX + 0x40) >> 2) <= param_1)) {
    return 0;
  }
  iVar1 = *(int *)(in_ECX + 0x40);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x44) - iVar1 >> 2) <= param_1)) {
    FUN_004b36c0();
    iVar1 = extraout_EDX;
  }
  return *(undefined4 *)(iVar1 + param_1 * 4);
}


// ==== FUN_004b2eb0 @ 0x004b2eb0 ====

void FUN_004b2eb0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097fbe3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0xffffffff;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  *in_ECX = &PTR_FUN_009afd48;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  local_4 = 1;
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004b2f40 @ 0x004b2f40 ====

void FUN_004b2f40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009afd48;
  FUN_004b3a70(in_ECX + 0xf);
  *(undefined1 *)(in_ECX + 0xe) = 1;
  if ((void *)in_ECX[0x10] == (void *)0x0) {
    in_ECX[0x10] = 0;
    in_ECX[0x11] = 0;
    in_ECX[0x12] = 0;
    FUN_0049da30();
    return;
  }
  _free((void *)in_ECX[0x10]);
  return;
}


// ==== FUN_004b2f90 @ 0x004b2f90 ====

/* WARNING: Removing unreachable block (ram,0x004b32a0) */
/* WARNING: Removing unreachable block (ram,0x004b3024) */
/* WARNING: Removing unreachable block (ram,0x004b3060) */
/* WARNING: Removing unreachable block (ram,0x004b307c) */
/* WARNING: Removing unreachable block (ram,0x004b30a9) */
/* WARNING: Removing unreachable block (ram,0x004b2ff9) */
/* WARNING: Removing unreachable block (ram,0x004b3035) */
/* WARNING: Removing unreachable block (ram,0x004b303b) */
/* WARNING: Removing unreachable block (ram,0x004b3058) */
/* WARNING: Removing unreachable block (ram,0x004b30c8) */
/* WARNING: Removing unreachable block (ram,0x004b3208) */
/* WARNING: Removing unreachable block (ram,0x004b3193) */
/* WARNING: Removing unreachable block (ram,0x004b31b5) */
/* WARNING: Removing unreachable block (ram,0x004b31c7) */
/* WARNING: Removing unreachable block (ram,0x004b32bb) */
/* WARNING: Removing unreachable block (ram,0x004b32bf) */
/* WARNING: Removing unreachable block (ram,0x004b31e7) */
/* WARNING: Removing unreachable block (ram,0x004b30d0) */
/* WARNING: Removing unreachable block (ram,0x004b30f0) */
/* WARNING: Removing unreachable block (ram,0x004b32a9) */
/* WARNING: Removing unreachable block (ram,0x004b30f8) */
/* WARNING: Removing unreachable block (ram,0x004b3130) */
/* WARNING: Removing unreachable block (ram,0x004b314e) */
/* WARNING: Removing unreachable block (ram,0x004b314a) */
/* WARNING: Removing unreachable block (ram,0x004b3166) */
/* WARNING: Removing unreachable block (ram,0x004b316a) */
/* WARNING: Removing unreachable block (ram,0x004b3187) */
/* WARNING: Removing unreachable block (ram,0x004b32b2) */
/* WARNING: Removing unreachable block (ram,0x004b3201) */
/* WARNING: Removing unreachable block (ram,0x004b3215) */
/* WARNING: Removing unreachable block (ram,0x004b322d) */
/* WARNING: Removing unreachable block (ram,0x004b3239) */
/* WARNING: Removing unreachable block (ram,0x004b3245) */
/* WARNING: Removing unreachable block (ram,0x004b324f) */
/* WARNING: Removing unreachable block (ram,0x004b3297) */

void FUN_004b2f90(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint local_40;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097fbfd;
  local_c = ExceptionList;
  local_40 = 0;
  ExceptionList = &local_c;
  iVar1 = FUN_00411430();
  if (iVar1 != 0) {
    do {
      FUN_00411510();
      local_4 = 0;
      FUN_00405670();
      local_4 = 0xffffffff;
      local_40 = local_40 + 1;
      uVar2 = FUN_00411430();
    } while (local_40 < uVar2);
  }
  iVar1 = *(int *)(param_3 + 0x14);
  if (iVar1 != 0) {
    puVar3 = (undefined4 *)(param_3 + 4);
    if (*(uint *)(param_3 + 0x18) < 0x10) {
      puVar4 = puVar3;
    }
    else {
      puVar4 = (undefined4 *)*puVar3;
    }
    if (*(char *)(iVar1 + -1 + (int)puVar4) != '\\') {
      if (0xf < *(uint *)(param_3 + 0x18)) {
        puVar3 = (undefined4 *)*puVar3;
      }
      if (*(char *)(iVar1 + -1 + (int)puVar3) != '/') {
        FUN_004020e0();
      }
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004b3300 @ 0x004b3300 ====

undefined4 FUN_004b3300(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int *piVar3;
  void *pvVar4;
  undefined4 extraout_EAX_02;
  undefined4 uVar5;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined4 extraout_EAX_05;
  undefined4 extraout_EAX_06;
  int in_ECX;
  void *pvVar6;
  void *pvStack_d8;
  int *piStack_d4;
  undefined *puStack_d0;
  undefined4 uStack_b8;
  undefined auStack_b0 [4];
  void *pvStack_ac;
  void *pvStack_a8;
  undefined4 uStack_a4;
  undefined1 auStack_a0 [4];
  void *pvStack_9c;
  undefined4 uStack_8c;
  uint uStack_88;
  void *pvStack_80;
  undefined4 uStack_70;
  uint uStack_6c;
  undefined4 uStack_68;
  undefined1 *puStack_64;
  undefined1 auStack_60 [4];
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  int iStack_28;
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097fc4e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 9) {
    pvStack_ac = (void *)0x0;
    pvStack_a8 = (void *)0x0;
    uStack_a4 = 0;
    uStack_88 = 0xf;
    uStack_8c = 0;
    pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
    puStack_d0 = auStack_b0;
    piStack_d4 = param_1;
    uStack_4 = 1;
    pvStack_d8 = (void *)0x4b337b;
    FUN_004b2f90();
    pvVar6 = pvStack_ac;
    if (pvStack_ac != pvStack_a8) {
      do {
        uStack_b8 = 0;
        if (*(int *)((int)pvVar6 + 0x14) == 0) {
          piStack_d4 = &iStack_28;
          puStack_d0 = &DAT_009afd0c;
          pvStack_d8 = (void *)0x4b33af;
          pvStack_d8 = (void *)FUN_004022a0();
          uStack_4._0_1_ = 2;
          FUN_00796d50();
          uStack_4 = CONCAT31(uStack_4._1_3_,1);
          if (0xf < uStack_10) {
            puStack_d0 = (undefined *)0x4b33df;
            _free(pvStack_24);
            return extraout_EAX;
          }
          uStack_10 = 0xf;
          uStack_14 = 0;
          pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
        }
        else {
          puStack_d0 = auStack_a0;
          piStack_d4 = (int *)auStack_44;
          pvStack_d8 = (void *)0x4b3413;
          pvStack_d8 = (void *)FUN_00405bd0();
          uStack_4._0_1_ = 3;
          piStack_d4 = (int *)FUN_004a7bb0(auStack_60);
          puStack_d0 = (undefined *)0x0;
          uStack_4._0_1_ = 4;
          uStack_6c = 0xf;
          uStack_70 = 0;
          pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
          pvStack_d8 = (void *)0x4b344f;
          FUN_00401660();
          uStack_68 = 0;
          if (0xf < uStack_48) {
            puStack_d0 = (undefined *)0x4b346b;
            _free(pvStack_5c);
            return extraout_EAX_00;
          }
          uStack_48 = 0xf;
          uStack_4c = 0;
          pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
          uStack_4._0_1_ = 6;
          if (0xf < uStack_2c) {
            puStack_d0 = (undefined *)0x4b349b;
            _free(pvStack_40);
            return extraout_EAX_01;
          }
          uStack_2c = 0xf;
          uStack_30 = 0;
          pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
          puStack_d0 = (undefined *)0x4b34bd;
          piVar3 = (int *)FUN_004a8060();
          if (piVar3 != (int *)0x0) {
            iVar2 = (**(code **)(*piVar3 + 4))();
            if (iVar2 != 4) {
              if (0xf < uStack_6c) {
                puStack_d0 = (undefined *)0x4b3648;
                _free(pvStack_80);
                return extraout_EAX_05;
              }
              uStack_6c = 0xf;
              uStack_70 = 0;
              pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
              if (0xf < uStack_88) {
                puStack_d0 = (undefined *)0x4b366c;
                _free(pvStack_9c);
                return extraout_EAX_06;
              }
              uStack_88 = 0xf;
              uStack_8c = 0;
              pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
              FUN_00406250();
              goto LAB_004b3684;
            }
            puStack_d0 = (undefined *)0x4b34dc;
            pvVar4 = operator_new(0x10);
            uStack_4._0_1_ = 8;
            if (pvVar4 == (void *)0x0) {
              uStack_b8 = 0;
            }
            else {
              puStack_64 = (undefined1 *)&pvStack_d8;
              FUN_004b39c0(piVar3 + 3);
              uStack_b8 = FUN_004b3ac0();
            }
            uStack_4._0_1_ = 6;
            puStack_d0 = (undefined *)0x4b3522;
            (**(code **)*piVar3)();
          }
          uStack_4 = CONCAT31(uStack_4._1_3_,1);
          if (0xf < uStack_6c) {
            puStack_d0 = (undefined *)0x4b353f;
            _free(pvStack_80);
            return extraout_EAX_02;
          }
          uStack_6c = 0xf;
          uStack_70 = 0;
          pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
        }
        iVar2 = *(int *)(in_ECX + 0x40);
        if ((iVar2 == 0) ||
           ((uint)(*(int *)(in_ECX + 0x48) - iVar2 >> 2) <=
            (uint)(*(int *)(in_ECX + 0x44) - iVar2 >> 2))) {
          piStack_d4 = *(int **)(in_ECX + 0x44);
          puStack_d0 = (undefined *)0x1;
          pvStack_d8 = (void *)0x4b359d;
          FUN_004b37a0();
        }
        else {
          puVar1 = *(undefined4 **)(in_ECX + 0x44);
          *puVar1 = uStack_b8;
          *(undefined4 **)(in_ECX + 0x44) = puVar1 + 1;
        }
        pvVar6 = (void *)((int)pvVar6 + 0x1c);
      } while (pvVar6 != pvStack_a8);
    }
    pvVar6 = pvStack_ac;
    uVar5 = (**(code **)(*param_1 + 0x10))();
    *(undefined4 *)(in_ECX + 0x28) = uVar5;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    puStack_d0 = (undefined *)0x4b35ce;
    (**(code **)*param_1)();
    *(undefined4 *)(in_ECX + 0x34) = 2;
    if (0xf < uStack_88) {
      puStack_d0 = (undefined *)0x4b35e6;
      _free(pvStack_9c);
      return extraout_EAX_03;
    }
    uStack_88 = 0xf;
    uStack_8c = 0;
    pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
    if (pvVar6 != (void *)0x0) {
      puStack_d0 = auStack_b0;
      piStack_d4 = pvStack_a8;
      pvStack_d8 = pvVar6;
      FUN_00405de0();
      _free(pvVar6);
      return extraout_EAX_04;
    }
    uVar5 = 1;
  }
  else {
LAB_004b3684:
    uVar5 = 0;
  }
  ExceptionList = pvStack_c;
  return uVar5;
}


// ==== FUN_004b3690 @ 0x004b3690 ====

void FUN_004b3690(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    if (param_3 != (undefined1 *)0x0) {
      *param_3 = *param_1;
    }
    param_3 = param_3 + 1;
  }
  return;
}


// ==== FUN_004b36c0 @ 0x004b36c0 ====

void FUN_004b36c0(void)

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
  puStack_8 = &LAB_0097fb88;
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


// ==== FUN_004b3730 @ 0x004b3730 ====

void FUN_004b3730(void)

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
  puStack_8 = &LAB_0097fb88;
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


// ==== FUN_004b37a0 @ 0x004b37a0 ====

void FUN_004b37a0(void *param_1,uint param_2,undefined4 *param_3)

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
      uVar7 = FUN_004b3730();
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


// ==== FUN_004b3980 @ 0x004b3980 ====

undefined1 FUN_004b3980(undefined4 *param_1,undefined4 *param_2,undefined1 param_3)

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
  FUN_00412dc0();
  _free(_Memory);
  return extraout_AL;
}


// ==== FUN_004b39c0 @ 0x004b39c0 ====

/* WARNING: Removing unreachable block (ram,0x004b3a0d) */

void FUN_004b39c0(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097fba0;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uVar3 != 0) {
    pvVar1 = operator_new(uVar3);
    *(void **)(in_ECX + 4) = pvVar1;
    *(void **)(in_ECX + 8) = pvVar1;
    *(uint *)(in_ECX + 0xc) = (int)pvVar1 + uVar3;
    local_8 = 0;
    uVar2 = FUN_004b3690(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),pvVar1);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004b3a5b @ 0x004b3a5b ====

void Catch_004b3a5b(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004b3a70 @ 0x004b3a70 ====

void FUN_004b3a70(int param_1)

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
      FUN_004b3980(iVar2,*piVar1,param_1);
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


// ==== FUN_004b3ac0 @ 0x004b3ac0 ====

void FUN_004b3ac0(undefined1 param_1,void *param_2)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097fbb8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_004b39c0(&param_1);
  if (param_2 == (void *)0x0) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_004b3b10 @ 0x004b3b10 ====

undefined4 FUN_004b3b10(void)

{
  return 0x11;
}


// ==== FUN_004b3b20 @ 0x004b3b20 ====

void FUN_004b3b20(byte param_1)

{
  void *in_ECX;
  
  FUN_004b2f40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004b3b40 @ 0x004b3b40 ====

int FUN_004b3b40(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0x44) - *(int *)(in_ECX + 0x40) >> 2;
}


// ==== FUN_004b3b60 @ 0x004b3b60 ====

undefined4 FUN_004b3b60(int param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 4);
  piVar1 = *(int **)(param_1 + 8);
  while( true ) {
    if (piVar3 == piVar1) {
      return 1;
    }
    if (((int *)*piVar3 != (int *)0x0) &&
       (cVar2 = (**(code **)(*(int *)*piVar3 + 0x2c))(), cVar2 == '\0')) break;
    piVar3 = piVar3 + 1;
  }
  return 0;
}


// ==== FUN_004b3ba0 @ 0x004b3ba0 ====

undefined4 FUN_004b3ba0(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x34) == 2) {
    return 1;
  }
  if (((*(int *)(in_ECX + 0x34) != 1) || (cVar1 = FUN_004b3b60(in_ECX + 0x3c), cVar1 == '\0')) ||
     (cVar1 = FUN_004b3b60(in_ECX + 0x4c), cVar1 == '\0')) {
    return 0;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar3 = (**(code **)(*piVar2 + 0x1c))();
  if ((*(int *)(iVar3 + 8) == 0) || (cVar1 = FUN_004b3b60(in_ECX + 0x5c), cVar1 != '\0')) {
    *(undefined4 *)(in_ECX + 0x34) = 2;
    return 1;
  }
  return 0;
}


// ==== FUN_004b3c10 @ 0x004b3c10 ====

void FUN_004b3c10(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  for (piVar2 = *(int **)(param_1 + 4); piVar2 != piVar1; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x1c))(*piVar2);
    }
  }
  if (*(void **)(param_1 + 4) == (void *)0x0) {
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    return;
  }
  _free(*(void **)(param_1 + 4));
  return;
}


// ==== FUN_004b3c70 @ 0x004b3c70 ====

void FUN_004b3c70(void)

{
  int in_ECX;
  
  FUN_004b3c10(in_ECX + 0x3c);
  FUN_004b3c10(in_ECX + 0x4c);
  FUN_004b3c10(in_ECX + 0x5c);
  *(undefined1 *)(in_ECX + 0x38) = 1;
  return;
}


// ==== FUN_004b3ca0 @ 0x004b3ca0 ====

void FUN_004b3ca0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097fcd4;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009afdf8;
  local_4 = 4;
  if (*(char *)(in_ECX + 0xe) == '\0') {
    FUN_004b3c10(in_ECX + 0xf);
    FUN_004b3c10(in_ECX + 0x13);
    FUN_004b3c10(in_ECX + 0x17);
    *(undefined1 *)(in_ECX + 0xe) = 1;
  }
  if (0xf < (uint)in_ECX[0x21]) {
    _free((void *)in_ECX[0x1c]);
    return;
  }
  in_ECX[0x21] = 0xf;
  in_ECX[0x20] = 0;
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  if ((void *)in_ECX[0x18] != (void *)0x0) {
    _free((void *)in_ECX[0x18]);
    return;
  }
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  if ((void *)in_ECX[0x14] != (void *)0x0) {
    _free((void *)in_ECX[0x14]);
    return;
  }
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  if ((void *)in_ECX[0x10] == (void *)0x0) {
    in_ECX[0x10] = 0;
    in_ECX[0x11] = 0;
    in_ECX[0x12] = 0;
    local_4 = 0xffffffff;
    FUN_0049da30();
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x10]);
  return;
}


// ==== FUN_004b3d90 @ 0x004b3d90 ====

void FUN_004b3d90(int param_1,int param_2,char param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
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
  
  puStack_8 = &LAB_0097fcee;
  local_c = ExceptionList;
  iVar4 = *(int *)(param_1 + 4);
  iVar1 = *(int *)(param_1 + 8);
  if (iVar4 != iVar1) {
    iVar5 = 0;
    ExceptionList = &local_c;
    do {
      local_4 = 0xffffffff;
      if (*(int *)(iVar4 + 0x14) != 0) {
        if (param_3 == '\0') {
          uVar3 = FUN_00405bd0(local_28,in_ECX + 0x6c,iVar4);
          iVar2 = *(int *)(param_2 + 4);
          local_4 = 1;
          uVar3 = FUN_004b4e70(uVar3);
          *(undefined4 *)(iVar5 + iVar2) = uVar3;
          local_4 = 0xffffffff;
          if (0xf < local_10) {
            _free(local_24);
            return;
          }
          local_10 = 0xf;
          local_14 = 0;
          local_24 = (void *)((uint)local_24 & 0xffffff00);
        }
        else {
          uVar3 = FUN_00405bd0(local_44,in_ECX + 0x6c,iVar4);
          iVar2 = *(int *)(param_2 + 4);
          local_4 = 0;
          uVar3 = FUN_004b4df0(uVar3);
          *(undefined4 *)(iVar5 + iVar2) = uVar3;
          local_4 = 0xffffffff;
          if (0xf < local_2c) {
            _free(local_40);
            return;
          }
          local_2c = 0xf;
          local_30 = 0;
          local_40 = (void *)((uint)local_40 & 0xffffff00);
        }
      }
      iVar4 = iVar4 + 0x1c;
      iVar5 = iVar5 + 4;
    } while (iVar4 != iVar1);
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004b3ec0 @ 0x004b3ec0 ====

void FUN_004b3ec0(int param_1)

{
  int *piVar1;
  int *piVar2;
  void **ppvVar3;
  char cVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097fd00;
  piVar6 = *(int **)(param_1 + 4);
  piVar1 = *(int **)(param_1 + 8);
  ppvVar3 = &local_c;
  local_c = ExceptionList;
  do {
    ExceptionList = ppvVar3;
    if (piVar6 == piVar1) {
      ExceptionList = local_c;
      return;
    }
    piVar2 = (int *)*piVar6;
    if ((piVar2 != (int *)0x0) && (cVar4 = (**(code **)(*piVar2 + 0x2c))(), cVar4 == '\0')) {
      uVar5 = (**(code **)(*piVar2 + 4))();
      uStack_10 = 0xf;
      uStack_14 = 0;
      pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
      FUN_00401660(uVar5,0,0xffffffff);
      uStack_4 = 0;
      (**(code **)(*DAT_00b5a7cc + 0x14))(piVar2);
      FUN_004b4e70(auStack_28);
      uStack_4 = 0xffffffff;
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      uStack_10 = 0xf;
      uStack_14 = 0;
      pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    }
    piVar6 = piVar6 + 1;
    ppvVar3 = ExceptionList;
  } while( true );
}


// ==== FUN_004b3fa0 @ 0x004b3fa0 ====

undefined4 FUN_004b3fa0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x34) != 2) {
    FUN_004b3ec0(in_ECX + 0x3c);
    FUN_004b3ec0(in_ECX + 0x4c);
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    if (*(int *)(iVar2 + 8) != 0) {
      FUN_004b3ec0(in_ECX + 0x5c);
    }
    *(undefined4 *)(in_ECX + 0x34) = 2;
  }
  return 1;
}


// ==== FUN_004b3ff0 @ 0x004b3ff0 ====

undefined4 FUN_004b3ff0(uint param_1)

{
  undefined4 extraout_EAX;
  undefined4 uVar1;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int in_ECX;
  int extraout_EDX;
  int iVar2;
  undefined1 local_64 [4];
  void *local_60;
  undefined4 local_50;
  uint local_4c;
  undefined1 local_48 [4];
  void *local_44;
  undefined4 local_34;
  uint local_30;
  void *local_28;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097fd22;
  local_c = ExceptionList;
  if ((*(int *)(in_ECX + 0x40) != 0) &&
     (param_1 < (uint)(*(int *)(in_ECX + 0x44) - *(int *)(in_ECX + 0x40) >> 2))) {
    iVar2 = *(int *)(in_ECX + 0x40);
    if ((iVar2 == 0) || ((uint)(*(int *)(in_ECX + 0x44) - iVar2 >> 2) <= param_1)) {
      ExceptionList = &local_c;
      FUN_004b4d10();
      iVar2 = extraout_EDX;
    }
    ExceptionList = local_c;
    return *(undefined4 *)(iVar2 + param_1 * 4);
  }
  local_4c = 0xf;
  local_50 = 0;
  local_60 = (void *)((uint)local_60 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(&DAT_009afdca,0);
  local_4 = 0;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401660(local_64,0,0xffffffff);
  local_10 = 0;
  local_4._0_1_ = 2;
  if (0xf < local_4c) {
    _free(local_60);
    return extraout_EAX;
  }
  local_4c = 0xf;
  local_50 = 0;
  local_60 = (void *)((uint)local_60 & 0xffffff00);
  local_30 = 0xf;
  local_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  FUN_00401740(&DAT_009afdcb,0);
  local_4 = CONCAT31(local_4._1_3_,3);
  uVar1 = FUN_004b4e70(local_48);
  if (0xf < local_30) {
    _free(local_44);
    return extraout_EAX_00;
  }
  if (local_14 < 0x10) {
    ExceptionList = local_c;
    return uVar1;
  }
  _free(local_28);
  return extraout_EAX_01;
}


// ==== FUN_004b4130 @ 0x004b4130 ====

undefined4 FUN_004b4130(uint param_1)

{
  undefined4 extraout_EAX;
  undefined4 uVar1;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int in_ECX;
  int extraout_EDX;
  int iVar2;
  undefined1 local_64 [4];
  void *local_60;
  undefined4 local_50;
  uint local_4c;
  undefined1 local_48 [4];
  void *local_44;
  undefined4 local_34;
  uint local_30;
  void *local_28;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097fd44;
  local_c = ExceptionList;
  if ((*(int *)(in_ECX + 0x50) != 0) &&
     (param_1 < (uint)(*(int *)(in_ECX + 0x54) - *(int *)(in_ECX + 0x50) >> 2))) {
    iVar2 = *(int *)(in_ECX + 0x50);
    if ((iVar2 == 0) || ((uint)(*(int *)(in_ECX + 0x54) - iVar2 >> 2) <= param_1)) {
      ExceptionList = &local_c;
      FUN_004b4d10();
      iVar2 = extraout_EDX;
    }
    ExceptionList = local_c;
    return *(undefined4 *)(iVar2 + param_1 * 4);
  }
  local_4c = 0xf;
  local_50 = 0;
  local_60 = (void *)((uint)local_60 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(&DAT_009afdcc,0);
  local_4 = 0;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401660(local_64,0,0xffffffff);
  local_10 = 0;
  local_4._0_1_ = 2;
  if (0xf < local_4c) {
    _free(local_60);
    return extraout_EAX;
  }
  local_4c = 0xf;
  local_50 = 0;
  local_60 = (void *)((uint)local_60 & 0xffffff00);
  local_30 = 0xf;
  local_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  FUN_00401740(&DAT_009afdcd,0);
  local_4 = CONCAT31(local_4._1_3_,3);
  uVar1 = FUN_004b4e70(local_48);
  if (0xf < local_30) {
    _free(local_44);
    return extraout_EAX_00;
  }
  if (local_14 < 0x10) {
    ExceptionList = local_c;
    return uVar1;
  }
  _free(local_28);
  return extraout_EAX_01;
}


// ==== FUN_004b4270 @ 0x004b4270 ====

undefined4 FUN_004b4270(uint param_1)

{
  undefined4 extraout_EAX;
  undefined4 uVar1;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int in_ECX;
  int extraout_EDX;
  int iVar2;
  undefined1 local_64 [4];
  void *local_60;
  undefined4 local_50;
  uint local_4c;
  undefined1 local_48 [4];
  void *local_44;
  undefined4 local_34;
  uint local_30;
  void *local_28;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097fd66;
  local_c = ExceptionList;
  if ((*(int *)(in_ECX + 0x60) != 0) &&
     (param_1 < (uint)(*(int *)(in_ECX + 100) - *(int *)(in_ECX + 0x60) >> 2))) {
    iVar2 = *(int *)(in_ECX + 0x60);
    if ((iVar2 == 0) || ((uint)(*(int *)(in_ECX + 100) - iVar2 >> 2) <= param_1)) {
      ExceptionList = &local_c;
      FUN_004b4d10();
      iVar2 = extraout_EDX;
    }
    ExceptionList = local_c;
    return *(undefined4 *)(iVar2 + param_1 * 4);
  }
  local_4c = 0xf;
  local_50 = 0;
  local_60 = (void *)((uint)local_60 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(&DAT_009afdce,0);
  local_4 = 0;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401660(local_64,0,0xffffffff);
  local_10 = 0;
  local_4._0_1_ = 2;
  if (0xf < local_4c) {
    _free(local_60);
    return extraout_EAX;
  }
  local_4c = 0xf;
  local_50 = 0;
  local_60 = (void *)((uint)local_60 & 0xffffff00);
  local_30 = 0xf;
  local_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  FUN_00401740(&DAT_009afdcf,0);
  local_4 = CONCAT31(local_4._1_3_,3);
  uVar1 = FUN_004b4e70(local_48);
  if (0xf < local_30) {
    _free(local_44);
    return extraout_EAX_00;
  }
  if (local_14 < 0x10) {
    ExceptionList = local_c;
    return uVar1;
  }
  _free(local_28);
  return extraout_EAX_01;
}


// ==== FUN_004b43b0 @ 0x004b43b0 ====

void FUN_004b43b0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097fda4;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0xffffffff;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  *in_ECX = &PTR_FUN_009afdf8;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x21] = 0xf;
  in_ECX[0x20] = 0;
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  *(undefined1 *)(in_ECX + 0x22) = 0;
  local_4 = 4;
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004b4460 @ 0x004b4460 ====

void FUN_004b4460(undefined4 param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  cVar1 = FUN_00403f60(param_1);
  if (cVar1 != '\0') {
    uVar2 = thunk_FUN_00796e60(param_1);
    iVar3 = 0;
    if (*(int *)(param_3 + 4) != 0) {
      iVar3 = (*(int *)(param_3 + 8) - *(int *)(param_3 + 4)) / 0x1c;
    }
    if (iVar3 <= (int)uVar2) {
      FUN_00431650(uVar2 + 1);
    }
    if ((*(int *)(param_3 + 4) == 0) ||
       ((uint)((*(int *)(param_3 + 8) - *(int *)(param_3 + 4)) / 0x1c) <= uVar2)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    FUN_00401660(param_2,0,0xffffffff);
  }
  return;
}


// ==== FUN_004b4500 @ 0x004b4500 ====

/* WARNING: Removing unreachable block (ram,0x004b4953) */

void FUN_004b4500(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  int in_ECX;
  int iVar6;
  uint local_78;
  undefined1 local_70 [4];
  void *local_6c;
  int local_68;
  undefined4 local_64;
  undefined1 local_60 [4];
  void *local_5c;
  undefined4 local_4c;
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
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097fdce;
  local_c = ExceptionList;
  local_78 = 0;
  ExceptionList = &local_c;
  iVar1 = FUN_00411430();
  if (iVar1 != 0) {
    do {
      uVar2 = FUN_00411510(local_78);
      local_6c = (void *)0x0;
      local_68 = 0;
      local_64 = 0;
      local_4 = 0;
      FUN_00405670(uVar2,local_70);
      if (local_6c == (void *)0x0) {
LAB_004b4591:
        local_4 = 0xffffffff;
        if (local_6c != (void *)0x0) {
          FUN_00405de0(local_6c,local_68,local_70,local_78);
LAB_004b4900:
          _free(local_6c);
          return;
        }
LAB_004b4908:
        local_4 = 0xffffffff;
        local_6c = (void *)0x0;
        local_68 = 0;
        local_64 = 0;
      }
      else {
        iVar1 = local_68 - (int)local_6c >> 0x1f;
        iVar6 = (local_68 - (int)local_6c) / 0x1c + iVar1;
        if (iVar6 - iVar1 != 2) goto LAB_004b4591;
        if (iVar6 == iVar1) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        iVar1 = FUN_00403620(0,*(undefined4 *)((int)local_6c + 0x14),s_texpath_009afdb8,7);
        if (iVar1 == 0) {
          if (local_6c == (void *)0x0) goto LAB_004b495c;
          if ((local_68 - (int)local_6c) / 0x1c != 2) goto LAB_004b4691;
          FUN_00401660((int)local_6c + 0x1c,0,0xffffffff);
          if (*(uint *)(in_ECX + 0x84) < 0x10) {
            iVar1 = in_ECX + 0x70;
          }
          else {
            iVar1 = *(int *)(in_ECX + 0x70);
          }
          if (*(char *)(*(int *)(in_ECX + 0x80) + iVar1 + -1) != '\\') {
            if (*(uint *)(in_ECX + 0x84) < 0x10) {
              iVar1 = in_ECX + 0x70;
            }
            else {
              iVar1 = *(int *)(in_ECX + 0x70);
            }
            if (*(char *)(*(int *)(in_ECX + 0x80) + iVar1 + -1) != '/') {
              FUN_004020e0(&DAT_009afdc0,1);
            }
          }
          if (local_6c != (void *)0x0) {
            uVar5 = local_78;
            goto LAB_004b48ea;
          }
          goto LAB_004b4908;
        }
LAB_004b4691:
        if ((local_6c == (void *)0x0) || (uVar5 = (local_68 - (int)local_6c) / 0x1c, uVar5 == 0)) {
LAB_004b495c:
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        local_48 = 0xf;
        local_4c = 0;
        local_5c = (void *)((uint)local_5c & 0xffffff00);
        FUN_00401660(local_6c,0,0xffffffff);
        local_4._0_1_ = 1;
        iVar1 = FUN_00405b90(local_44,0,1);
        local_4._0_1_ = 2;
        iVar1 = FUN_00403620(0,*(undefined4 *)(iVar1 + 0x14),&DAT_009afdc4,1);
        local_4._0_1_ = 1;
        if (0xf < local_2c) {
          _free(local_40);
          return;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (iVar1 == 0) {
          FUN_00401390(0,1);
          if ((local_6c == (void *)0x0) || ((uint)((local_68 - (int)local_6c) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          uVar2 = param_3;
LAB_004b48a0:
          FUN_004b4460(local_60,(int)local_6c + 0x1c,uVar2);
LAB_004b48b3:
          if (0xf < local_48) {
            _free(local_5c);
            return;
          }
          local_48 = 0xf;
          local_4c = 0;
          local_5c = (void *)((uint)local_5c & 0xffffff00);
          if (local_6c != (void *)0x0) {
LAB_004b48ea:
            local_4 = 0xffffffff;
            FUN_00405de0(local_6c,local_68,local_70,uVar5);
            goto LAB_004b4900;
          }
          goto LAB_004b4908;
        }
        iVar1 = FUN_00405b90(local_28,0,1);
        local_4._0_1_ = 3;
        iVar1 = FUN_00403620(0,*(undefined4 *)(iVar1 + 0x14),&DAT_009afdc8,1);
        local_4._0_1_ = 1;
        if (0xf < local_10) {
          _free(local_24);
          return;
        }
        local_10 = 0xf;
        local_14 = 0;
        local_24 = (void *)((uint)local_24 & 0xffffff00);
        if (iVar1 != 0) {
          if ((local_6c == (void *)0x0) || ((uint)((local_68 - (int)local_6c) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          uVar2 = param_2;
          goto LAB_004b48a0;
        }
        piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
        iVar1 = (**(code **)(*piVar3 + 0x1c))();
        if (*(int *)(iVar1 + 8) != 0) {
          FUN_00401390(0,1);
          uVar2 = param_4;
          uVar4 = FUN_00405d30(1);
          FUN_004b4460(local_60,uVar4,uVar2);
          goto LAB_004b48b3;
        }
        if (0xf < local_48) {
          _free(local_5c);
          return;
        }
        local_48 = 0xf;
        local_4c = 0;
        local_5c = (void *)((uint)local_5c & 0xffffff00);
        local_4 = 0xffffffff;
        FUN_00406250();
      }
      local_78 = local_78 + 1;
      uVar5 = FUN_00411430();
    } while (local_78 < uVar5);
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004b4980 @ 0x004b4980 ====

undefined4 FUN_004b4980(int *param_1)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int in_ECX;
  undefined4 unaff_retaddr;
  undefined4 uStack_3c;
  int iStack_38;
  int iStack_34;
  undefined4 uStack_30;
  void *pvStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  void *pvStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097fdf0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 != 9) {
    ExceptionList = pvStack_c;
    return 0;
  }
  uVar1 = (**(code **)(*param_1 + 0x14))();
  *(undefined1 *)(in_ECX + 0x88) = uVar1;
  iStack_38 = 0;
  iStack_34 = 0;
  uStack_30 = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  pvStack_10 = (void *)0x0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_4 = 2;
  FUN_004b4500(param_1,&uStack_3c,&pvStack_1c,&pvStack_2c);
  if (iStack_38 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (iStack_34 - iStack_38) / 0x1c;
  }
  FUN_004b5100(iVar2,0);
  FUN_004b3d90(&uStack_3c,in_ECX + 0x3c,0);
  FUN_004b5100(iVar2,0);
  FUN_004b3d90(&pvStack_1c,in_ECX + 0x4c,0);
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar4 = (**(code **)(*piVar3 + 0x1c))();
  if (*(int *)(iVar4 + 8) != 0) {
    FUN_004b5100(iVar2,0);
    FUN_004b3d90(&pvStack_2c,in_ECX + 0x5c,0);
  }
  uVar5 = (**(code **)(*param_1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar5;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  (**(code **)*param_1)(1);
  *(undefined4 *)(in_ECX + 0x34) = 2;
  if (pvStack_2c != (void *)0x0) {
    FUN_00405de0(pvStack_2c,uStack_28,&uStack_30,unaff_retaddr);
    _free(pvStack_2c);
    return extraout_EAX;
  }
  if (pvStack_1c != (void *)0x0) {
    FUN_00405de0(pvStack_1c,uStack_18,&uStack_20,unaff_retaddr);
    _free(pvStack_1c);
    return extraout_EAX_00;
  }
  if (uStack_3c == (void *)0x0) {
    ExceptionList = pvStack_10;
    return 1;
  }
  FUN_00405de0(uStack_3c,iStack_38,(int)register0x00000010 + -0x40,unaff_retaddr);
  _free(uStack_3c);
  return extraout_EAX_01;
}


// ==== FUN_004b4b50 @ 0x004b4b50 ====

undefined4 FUN_004b4b50(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int in_ECX;
  undefined4 unaff_retaddr;
  undefined4 uStack_3c;
  int iStack_38;
  int iStack_34;
  undefined4 uStack_30;
  void *pvStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  void *pvStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097fe12;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 != 9) {
    ExceptionList = pvStack_c;
    return 0;
  }
  iStack_38 = 0;
  iStack_34 = 0;
  uStack_30 = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  pvStack_10 = (void *)0x0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_4 = 2;
  FUN_004b4500(param_1,&uStack_3c,&pvStack_1c,&pvStack_2c);
  if (iStack_38 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (iStack_34 - iStack_38) / 0x1c;
  }
  FUN_004b5100(iVar1,0);
  FUN_004b3d90(&uStack_3c,in_ECX + 0x3c,1);
  FUN_004b5100(iVar1,0);
  FUN_004b3d90(&pvStack_1c,in_ECX + 0x4c,1);
  piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar3 = (**(code **)(*piVar2 + 0x1c))();
  if (*(int *)(iVar3 + 8) != 0) {
    FUN_004b5100(iVar1,0);
    FUN_004b3d90(&pvStack_2c,in_ECX + 0x5c,1);
  }
  uVar4 = (**(code **)(*param_1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar4;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  (**(code **)*param_1)(1);
  *(undefined4 *)(in_ECX + 0x34) = 1;
  if (pvStack_2c != (void *)0x0) {
    FUN_00405de0(pvStack_2c,uStack_28,&uStack_30,unaff_retaddr);
    _free(pvStack_2c);
    return extraout_EAX;
  }
  if (pvStack_1c != (void *)0x0) {
    FUN_00405de0(pvStack_1c,uStack_18,&uStack_20,unaff_retaddr);
    _free(pvStack_1c);
    return extraout_EAX_00;
  }
  if (uStack_3c == (void *)0x0) {
    ExceptionList = pvStack_10;
    return 1;
  }
  FUN_00405de0(uStack_3c,iStack_38,(int)register0x00000010 + -0x40,unaff_retaddr);
  _free(uStack_3c);
  return extraout_EAX_01;
}


// ==== FUN_004b4d10 @ 0x004b4d10 ====

void FUN_004b4d10(void)

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
  puStack_8 = &LAB_0097fc68;
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


// ==== FUN_004b4d80 @ 0x004b4d80 ====

void FUN_004b4d80(void)

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
  puStack_8 = &LAB_0097fc68;
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


// ==== FUN_004b4df0 @ 0x004b4df0 ====

undefined4 FUN_004b4df0(undefined4 param_1)

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
  puStack_8 = &LAB_0097fc88;
  pvStack_c = ExceptionList;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660(param_1,0,0xffffffff);
  local_10 = (void *)0x0;
  local_4 = 0;
  uVar1 = (**(code **)(*DAT_00b5a7cc + 0x10))(&local_2c);
  if (local_18 < 0x10) {
    ExceptionList = local_10;
    return uVar1;
  }
  _free(local_2c);
  return extraout_EAX;
}


// ==== FUN_004b4e70 @ 0x004b4e70 ====

undefined4 FUN_004b4e70(undefined4 param_1)

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
  puStack_8 = &LAB_0097fc88;
  pvStack_c = ExceptionList;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660(param_1,0,0xffffffff);
  local_10 = (void *)0x0;
  local_4 = 0;
  uVar1 = (**(code **)(*DAT_00b5a7cc + 8))(&local_2c);
  if (local_18 < 0x10) {
    ExceptionList = local_10;
    return uVar1;
  }
  _free(local_2c);
  return extraout_EAX;
}


// ==== FUN_004b4ef0 @ 0x004b4ef0 ====

undefined4 FUN_004b4ef0(void)

{
  return 0x10;
}


// ==== FUN_004b4f00 @ 0x004b4f00 ====

void FUN_004b4f00(void *param_1,uint param_2,undefined4 *param_3)

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
      uVar7 = FUN_004b4d80();
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


// ==== FUN_004b50e0 @ 0x004b50e0 ====

void FUN_004b50e0(byte param_1)

{
  void *in_ECX;
  
  FUN_004b3ca0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004b5100 @ 0x004b5100 ====

void FUN_004b5100(uint param_1,undefined1 param_2)

{
  void *_Dst;
  uint uVar1;
  int iVar2;
  void *pvVar3;
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
    FUN_004b4f00(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if (((iVar2 != 0) && (pvVar3 = *(void **)(in_ECX + 8), param_1 < (uint)((int)pvVar3 - iVar2 >> 2))
      ) && (_Dst = (void *)(iVar2 + param_1 * 4), _Dst != pvVar3)) {
    pvVar3 = _memmove(_Dst,pvVar3,0);
    *(void **)(in_ECX + 8) = pvVar3;
  }
  return;
}


// ==== FUN_004b5190 @ 0x004b5190 ====

void FUN_004b5190(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009afe78;
  if ((void *)in_ECX[0x10] == (void *)0x0) {
    in_ECX[0x10] = 0;
    in_ECX[0x11] = 0;
    in_ECX[0x12] = 0;
    FUN_0049da30();
    return;
  }
  _free((void *)in_ECX[0x10]);
  return;
}


// ==== FUN_004b51d0 @ 0x004b51d0 ====

void FUN_004b51d0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097fe33;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0xffffffff;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  *in_ECX = &PTR_FUN_009afe78;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  local_4 = 1;
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004b5260 @ 0x004b5260 ====

undefined4 FUN_004b5260(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 extraout_EAX;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097fe45;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 != 0xe) {
    ExceptionList = pvStack_c;
    return 0;
  }
  iVar2 = FUN_00405b90(auStack_28,0,7);
  uStack_4 = 0;
  iVar2 = FUN_00403620(0,*(undefined4 *)(iVar2 + 0x14),s_ambient_009afe68,7);
  uStack_4 = 0xffffffff;
  if (0xf < pvStack_10) {
    _free(pvStack_24);
    return extraout_EAX;
  }
  pvStack_10 = (void *)0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  if (iVar2 == 0) {
    *(undefined1 *)(in_ECX + 0x4c) = 1;
  }
  iVar2 = param_1[4];
  iVar3 = (**(code **)(*param_1 + 0x10))();
  if (*(void **)(in_ECX + 0x40) != *(void **)(in_ECX + 0x44)) {
    param_1 = (int *)0x0;
    pvVar4 = _memmove(*(void **)(in_ECX + 0x40),*(void **)(in_ECX + 0x44),0);
    *(void **)(in_ECX + 0x44) = pvVar4;
  }
  FUN_00426510(*(undefined4 *)(in_ECX + 0x40),iVar2,iVar3 + iVar2,param_1);
  uVar5 = (**(code **)(*piVar1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar5;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 2;
  (**(code **)*piVar1)(1);
  ExceptionList = pvStack_10;
  return 1;
}


// ==== FUN_004b5390 @ 0x004b5390 ====

undefined4 FUN_004b5390(void)

{
  return 0x1a;
}


// ==== FUN_004b53a0 @ 0x004b53a0 ====

void FUN_004b53a0(byte param_1)

{
  void *in_ECX;
  
  FUN_004b5190();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004b53c0 @ 0x004b53c0 ====

undefined4 FUN_004b53c0(int *param_1)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 != 0x10) {
    return 0;
  }
  uVar2 = (**(code **)(*param_1 + 0x10))();
  pvVar3 = operator_new(uVar2);
  *(void **)(in_ECX + 0x3c) = pvVar3;
  puVar6 = (undefined4 *)param_1[3];
  uVar2 = (**(code **)(*param_1 + 0x10))();
  puVar7 = *(undefined4 **)(in_ECX + 0x3c);
  for (uVar5 = uVar2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
    puVar6 = (undefined4 *)((int)puVar6 + 1);
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  uVar4 = (**(code **)(*param_1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar4;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 2;
  (**(code **)*param_1)(1);
  return 1;
}


// ==== FUN_004b5440 @ 0x004b5440 ====

void FUN_004b5440(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009afef0;
  _free((void *)in_ECX[0xf]);
  return;
}


// ==== FUN_004b5470 @ 0x004b5470 ====

void FUN_004b5470(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097fe58;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0xffffffff;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  local_4 = 0;
  in_ECX[0xf] = 0;
  *in_ECX = &PTR_FUN_009afef0;
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004b54f0 @ 0x004b54f0 ====

undefined4 FUN_004b54f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x3c);
}


// ==== FUN_004b5500 @ 0x004b5500 ====

void FUN_004b5500(byte param_1)

{
  void *in_ECX;
  
  FUN_004b5440();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004b5520 @ 0x004b5520 ====

int FUN_004b5520(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined4 *puVar5;
  int iVar6;
  
  if (*(int *)(in_ECX + 0x70) == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = *(int *)(in_ECX + 0x74) - *(int *)(in_ECX + 0x70) >> 2;
  }
  puVar1 = *(undefined4 **)(in_ECX + 100);
  for (puVar5 = *(undefined4 **)(in_ECX + 0x60); puVar5 != puVar1; puVar5 = puVar5 + 1) {
    iVar3 = (**(code **)(*(int *)*puVar5 + 4))();
    iVar6 = iVar6 + iVar3;
  }
  iVar3 = *(int *)(in_ECX + 0x50);
  iVar2 = *(int *)(in_ECX + 0x54);
  if (iVar3 != iVar2) {
    do {
      iVar4 = FUN_004b5520();
      iVar3 = iVar3 + 4;
      iVar6 = iVar6 + iVar4;
    } while (iVar3 != iVar2);
  }
  return iVar6;
}


// ==== FUN_004b5580 @ 0x004b5580 ====

int FUN_004b5580(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  undefined4 *puVar6;
  
  if (*(int *)(in_ECX + 0x70) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(in_ECX + 0x74) - *(int *)(in_ECX + 0x70) >> 2;
  }
  if (*(int *)(in_ECX + 0x40) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(in_ECX + 0x44) - *(int *)(in_ECX + 0x40) >> 5;
  }
  puVar1 = *(undefined4 **)(in_ECX + 100);
  iVar3 = iVar3 + iVar5;
  for (puVar6 = *(undefined4 **)(in_ECX + 0x60); puVar6 != puVar1; puVar6 = puVar6 + 1) {
    iVar5 = (**(code **)(*(int *)*puVar6 + 8))();
    iVar3 = iVar3 + iVar5;
  }
  iVar5 = *(int *)(in_ECX + 0x50);
  iVar2 = *(int *)(in_ECX + 0x54);
  if (iVar5 != iVar2) {
    do {
      iVar4 = FUN_004b5580();
      iVar5 = iVar5 + 4;
      iVar3 = iVar3 + iVar4;
    } while (iVar5 != iVar2);
  }
  return iVar3;
}


// ==== FUN_004b5600 @ 0x004b5600 ====

int FUN_004b5600(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_texture_009aff98,7);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),&DAT_009affa0,4);
  if (iVar2 == 0) {
    return 8;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),&DAT_009affa8,4);
  if (iVar2 == 0) {
    return 9;
  }
  cVar1 = FUN_004036a0(param_1,s_tpack_009affb0);
  if (cVar1 != '\0') {
    return 0x10;
  }
  cVar1 = FUN_004036a0(param_1,&DAT_009affb8);
  if (cVar1 == '\0') {
    cVar1 = FUN_004036a0(param_1,&PTR_FUN_009affc0);
    return (-(uint)(cVar1 != '\0') & 0xffff0016) + 0xffff;
  }
  return 7;
}


// ==== FUN_004b56c0 @ 0x004b56c0 ====

int FUN_004b56c0(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  undefined *puVar5;
  
  uVar1 = *(uint *)(param_2 + 0x14);
  if (uVar1 < 3) {
    puVar5 = &DAT_009aff94;
  }
  else {
    uVar2 = *(uint *)(param_2 + 0x18);
    piVar3 = (int *)(param_2 + 4);
    if (uVar2 < 0x10) {
      piVar4 = piVar3;
    }
    else {
      piVar4 = (int *)*piVar3;
    }
    if (*(char *)piVar4 == '<') {
      if (uVar2 < 0x10) {
        piVar4 = piVar3;
      }
      else {
        piVar4 = (int *)*piVar3;
      }
      if (*(char *)((int)piVar4 + 1) != '/') {
        if (0xf < uVar2) {
          piVar3 = (int *)*piVar3;
        }
        if (*(char *)((int)piVar3 + -1 + uVar1) == '>') {
          FUN_00405b90(param_1,1,uVar1 - 2);
          return param_1;
        }
      }
    }
    puVar5 = &DAT_009aff95;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401740(puVar5,0);
  return param_1;
}


// ==== FUN_004b5760 @ 0x004b5760 ====

int FUN_004b5760(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  undefined *puVar5;
  
  uVar1 = *(uint *)(param_2 + 0x14);
  if (uVar1 < 4) {
    puVar5 = &DAT_009aff96;
  }
  else {
    uVar2 = *(uint *)(param_2 + 0x18);
    piVar3 = (int *)(param_2 + 4);
    if (uVar2 < 0x10) {
      piVar4 = piVar3;
    }
    else {
      piVar4 = (int *)*piVar3;
    }
    if (*(char *)piVar4 == '<') {
      if (uVar2 < 0x10) {
        piVar4 = piVar3;
      }
      else {
        piVar4 = (int *)*piVar3;
      }
      if (*(char *)((int)piVar4 + 1) == '/') {
        if (0xf < uVar2) {
          piVar3 = (int *)*piVar3;
        }
        if (*(char *)((int)piVar3 + -1 + uVar1) == '>') {
          FUN_00405b90(param_1,2,uVar1 - 3);
          return param_1;
        }
      }
    }
    puVar5 = &DAT_009aff97;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401740(puVar5,0);
  return param_1;
}


// ==== FUN_004b5800 @ 0x004b5800 ====

void FUN_004b5800(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ff44;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0xffffffff;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  *in_ECX = &PTR_FUN_009affcc;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  local_4 = 4;
  FUN_00401660(param_1,0,0xffffffff);
  in_ECX[0x20] = 0;
  in_ECX[0x1f] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004b58b0 @ 0x004b58b0 ====

void FUN_004b58b0(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  FUN_004b6960();
  piVar1 = *(int **)(in_ECX + 0x74);
  for (piVar2 = *(int **)(in_ECX + 0x70); piVar2 != piVar1; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x1c))(*piVar2);
    }
  }
  if (*(void **)(in_ECX + 0x70) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x70));
    return;
  }
  *(undefined4 *)(in_ECX + 0x70) = 0;
  *(undefined4 *)(in_ECX + 0x74) = 0;
  *(undefined4 *)(in_ECX + 0x78) = 0;
  piVar1 = *(int **)(in_ECX + 0x54);
  for (piVar2 = *(int **)(in_ECX + 0x50); piVar2 != piVar1; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x1c))(*piVar2);
    }
  }
  if (*(void **)(in_ECX + 0x50) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x50));
    return;
  }
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  piVar2 = *(int **)(in_ECX + 0x60);
  if ((piVar2 != (int *)0x0) &&
     (piVar1 = *(int **)(in_ECX + 100), (int)piVar1 - (int)piVar2 >> 2 != 0)) {
    for (; piVar2 != piVar1; piVar2 = piVar2 + 1) {
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
    }
    if (*(void **)(in_ECX + 0x60) != (void *)0x0) {
      _free(*(void **)(in_ECX + 0x60));
      return;
    }
    *(undefined4 *)(in_ECX + 0x60) = 0;
    *(undefined4 *)(in_ECX + 100) = 0;
    *(undefined4 *)(in_ECX + 0x68) = 0;
  }
  return;
}


// ==== FUN_004b59a0 @ 0x004b59a0 ====

undefined4 FUN_004b59a0(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  void **ppvVar4;
  char cVar5;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined4 *puVar6;
  int iVar7;
  int local_30;
  undefined1 local_2c [4];
  void *local_28;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ff56;
  pvStack_c = ExceptionList;
  if ((*(int *)(in_ECX + 0x40) == 0) ||
     (local_30 = *(int *)(in_ECX + 0x44) - *(int *)(in_ECX + 0x40) >> 5, local_30 == 0)) {
    puVar2 = *(undefined4 **)(in_ECX + 100);
    ppvVar4 = &pvStack_c;
    for (puVar6 = *(undefined4 **)(in_ECX + 0x60); ExceptionList = ppvVar4, puVar6 != puVar2;
        puVar6 = puVar6 + 1) {
      cVar5 = (**(code **)(*(int *)*puVar6 + 0xc))();
      if (cVar5 == '\0') {
        ExceptionList = pvStack_c;
        return 0;
      }
      ppvVar4 = ExceptionList;
    }
    iVar7 = *(int *)(in_ECX + 0x50);
    iVar3 = *(int *)(in_ECX + 0x54);
    while( true ) {
      if (iVar7 == iVar3) {
        ExceptionList = pvStack_c;
        return 1;
      }
      cVar5 = FUN_004b59a0();
      if (cVar5 == '\0') break;
      iVar7 = iVar7 + 4;
    }
  }
  else {
    uVar1 = **(undefined4 **)(in_ECX + 0x40);
    local_14 = 0xf;
    local_18 = 0;
    local_28 = (void *)((uint)local_28 & 0xffffff00);
    ExceptionList = &pvStack_c;
    FUN_00401660(*(undefined4 **)(in_ECX + 0x40) + 1,0,0xffffffff);
    local_4 = 0;
    local_10 = uVar1;
    local_30 = (**(code **)(*DAT_00b5a7cc + 8))(local_2c);
    local_4 = 0xffffffff;
    if (0xf < local_14) {
      _free(local_28);
      return extraout_EAX;
    }
    if (local_30 != 0) {
      FUN_004b6910(&local_30);
    }
    FUN_004b69c0(&local_30,*(undefined4 *)(in_ECX + 0x40));
  }
  ExceptionList = pvStack_c;
  return 0;
}


// ==== FUN_004b5ad0 @ 0x004b5ad0 ====

void FUN_004b5ad0(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ff9c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009affcc;
  local_4 = 4;
  if (*(char *)(in_ECX + 0xe) == '\0') {
    FUN_004b58b0();
    *(undefined1 *)(in_ECX + 0xe) = 1;
    FUN_00401740(s_<<<<<<<<<<<<<<<<<<<_Preload_data_009aff64,0x2f);
    uVar1 = FUN_00404230(local_28);
    local_4 = CONCAT31(local_4._1_3_,5);
    FUN_00796d50(uVar1);
    if (0xf < local_10) {
      _free(local_24);
      return;
    }
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
  }
  if ((void *)in_ECX[0x1c] != (void *)0x0) {
    _free((void *)in_ECX[0x1c]);
    return;
  }
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  if ((void *)in_ECX[0x18] != (void *)0x0) {
    _free((void *)in_ECX[0x18]);
    return;
  }
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  if ((void *)in_ECX[0x14] == (void *)0x0) {
    in_ECX[0x14] = 0;
    in_ECX[0x15] = 0;
    in_ECX[0x16] = 0;
    FUN_004b6960();
    local_4 = 0xffffffff;
    FUN_0049da30();
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x14]);
  return;
}


// ==== FUN_004b5bf0 @ 0x004b5bf0 ====

void FUN_004b5bf0(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar1 = (int)param_2;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ffc4;
  local_c = ExceptionList;
  if (*(int *)((int)param_2 + 0x14) != 0) {
    if (param_1 == 0x15) {
      ExceptionList = &local_c;
      param_2 = (int *)FUN_004b62c0(param_2);
      if (param_2 != (int *)0x0) {
        iVar1 = FUN_004b5580();
        *(int *)(in_ECX + 0x80) = *(int *)(in_ECX + 0x80) + iVar1;
        FUN_004b6910(&param_2);
        ExceptionList = local_c;
        return;
      }
    }
    else {
      if (param_1 == 1) {
        ExceptionList = &local_c;
        param_2 = operator_new(0x18);
        local_4 = 0;
        if (param_2 == (void *)0x0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = (int *)FUN_004d57b0();
        }
        local_4 = 0xffffffff;
        FUN_004d59e0(iVar1);
        iVar1 = (**(code **)(*piVar2 + 8))();
        *(int *)(in_ECX + 0x80) = *(int *)(in_ECX + 0x80) + iVar1;
        param_2 = piVar2;
        FUN_004b6910(&param_2);
        ExceptionList = local_c;
        return;
      }
      if (param_1 == 2) {
        ExceptionList = &local_c;
        param_2 = operator_new(0x28);
        local_4 = 1;
        if (param_2 == (void *)0x0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = (int *)FUN_004d50e0();
        }
        local_4 = 0xffffffff;
        FUN_004d5330(iVar1);
        iVar1 = (**(code **)(*piVar2 + 8))();
        *(int *)(in_ECX + 0x80) = *(int *)(in_ECX + 0x80) + iVar1;
        param_2 = piVar2;
        FUN_004b6910(&param_2);
        ExceptionList = local_c;
        return;
      }
      ExceptionList = &local_c;
      *(int *)(in_ECX + 0x80) = *(int *)(in_ECX + 0x80) + 1;
      uVar3 = FUN_004b61b0(param_1,param_2);
      local_4 = 2;
      FUN_004b6cf0(uVar3);
      FUN_00446ee0();
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004b5d90 @ 0x004b5d90 ====

/* WARNING: Removing unreachable block (ram,0x004b6181) */

undefined4 FUN_004b5d90(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int iVar3;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined4 extraout_EAX_05;
  undefined4 extraout_EAX_06;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  uint uStack_74;
  int iStack_70;
  int local_6c;
  undefined1 auStack_68 [4];
  void *pvStack_64;
  int iStack_60;
  undefined4 uStack_5c;
  int iStack_54;
  uint uStack_50;
  int iStack_4c;
  int iStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  int iStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  int iStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097ffee;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_6c = in_ECX;
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 != 9) {
    ExceptionList = pvStack_c;
    return 0;
  }
  *(undefined4 *)(in_ECX + 0x80) = 0;
  *(undefined4 *)(in_ECX + 0x7c) = 0;
  iStack_54 = 0;
  uStack_50 = 0;
  iStack_4c = 0;
  iStack_48 = 0;
  iStack_4 = 0;
  uStack_74 = 0;
  iVar1 = FUN_00411430();
  if (iVar1 != 0) {
    do {
      uVar2 = FUN_00411510(uStack_74);
      pvStack_64 = (void *)0x0;
      iStack_60 = 0;
      uStack_5c = 0;
      iStack_4._0_1_ = 1;
      FUN_00405670(uVar2,auStack_68);
      if ((pvStack_64 == (void *)0x0) ||
         (iVar1 = iStack_60 - (int)pvStack_64 >> 0x1f,
         (iStack_60 - (int)pvStack_64) / 0x1c + iVar1 == iVar1)) {
joined_r0x004b5e6e:
        iStack_4 = (uint)iStack_4._1_3_ << 8;
        if (pvStack_64 != (void *)0x0) {
          FUN_00405de0(pvStack_64,iStack_60,auStack_68,param_1);
          _free(pvStack_64);
          return extraout_EAX_00;
        }
        pvStack_64 = (void *)0x0;
        iStack_60 = 0;
        uStack_5c = 0;
      }
      else {
        FUN_004b56c0(auStack_44,pvStack_64);
        iStack_4._0_1_ = 2;
        if (iStack_30 != 0) {
          iStack_70 = FUN_004b5600(auStack_44);
          FUN_004b67d0(&iStack_70);
          if (0xf < uStack_2c) {
            _free(pvStack_40);
            return extraout_EAX;
          }
          uStack_2c = 0xf;
          iStack_30 = 0;
          pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
          goto joined_r0x004b5e6e;
        }
        if ((pvStack_64 == (void *)0x0) ||
           (iStack_70 = (iStack_60 - (int)pvStack_64) / 0x1c, iStack_70 == 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        FUN_004b5760(auStack_28,pvStack_64);
        iStack_4._0_1_ = 3;
        if (iStack_14 == 0) {
          if (iStack_48 == 0) {
            if ((void *)0xf < pvStack_10) {
              _free(pvStack_24);
              return extraout_EAX_03;
            }
            pvStack_10 = (void *)0xf;
            iStack_14 = 0;
            pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
            if (0xf < uStack_2c) {
              _free(pvStack_40);
              return extraout_EAX_04;
            }
          }
          else {
            uVar5 = (iStack_48 + iStack_4c) - 1;
            uVar4 = uVar5 >> 2;
            iVar1 = uVar4 * -4;
            if (uStack_50 <= uVar4) {
              uVar4 = uVar4 - uStack_50;
            }
            iVar3 = *(int *)(iStack_54 + uVar4 * 4);
            uVar2 = FUN_00405d30(0);
            FUN_004b5bf0(*(undefined4 *)(iVar3 + (uVar5 + iVar1) * 4),uVar2);
            if ((void *)0xf < pvStack_10) {
              _free(pvStack_24);
              return extraout_EAX_05;
            }
            pvStack_10 = (void *)0xf;
            iStack_14 = 0;
            pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
            if (0xf < uStack_2c) {
              _free(pvStack_40);
              return extraout_EAX_06;
            }
          }
          pvStack_10 = (void *)0xf;
          iStack_14 = 0;
          uStack_2c = 0xf;
          pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
          iStack_30 = 0;
          iStack_4 = (uint)iStack_4._1_3_ << 8;
          FUN_00406250();
        }
        else {
          iVar3 = FUN_004b5600(auStack_28);
          uVar5 = (iStack_4c + iStack_48) - 1;
          uVar4 = uVar5 >> 2;
          iVar1 = uVar4 * -4;
          if (uStack_50 <= uVar4) {
            uVar4 = uVar4 - uStack_50;
          }
          if (((iVar3 == *(int *)(*(int *)(iStack_54 + uVar4 * 4) + (uVar5 + iVar1) * 4)) &&
              (iStack_48 != 0)) && (iStack_48 = iStack_48 + -1, iStack_48 == 0)) {
            iStack_4c = 0;
          }
          if ((void *)0xf < pvStack_10) {
            _free(pvStack_24);
            return extraout_EAX_01;
          }
          pvStack_10 = (void *)0xf;
          iStack_14 = 0;
          pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
          if (0xf < uStack_2c) {
            _free(pvStack_40);
            return extraout_EAX_02;
          }
          uStack_2c = 0xf;
          iStack_30 = 0;
          pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
          iStack_4 = (uint)iStack_4._1_3_ << 8;
          FUN_00406250();
          in_ECX = local_6c;
        }
      }
      uStack_74 = uStack_74 + 1;
      uVar4 = FUN_00411430();
    } while (uStack_74 < uVar4);
  }
  uVar2 = (**(code **)(*param_1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar2;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 2;
  (**(code **)*param_1)(1);
  FUN_0046cfc0();
  ExceptionList = pvStack_10;
  return 1;
}


// ==== FUN_004b61b0 @ 0x004b61b0 ====

void FUN_004b61b0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401660(param_2,0,0xffffffff);
  return;
}


// ==== FUN_004b61e0 @ 0x004b61e0 ====

void FUN_004b61e0(void)

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
  puStack_8 = &LAB_0097fe78;
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


// ==== FUN_004b6250 @ 0x004b6250 ====

void FUN_004b6250(void)

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
  puStack_8 = &LAB_0097fe78;
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


// ==== FUN_004b62c0 @ 0x004b62c0 ====

undefined4 FUN_004b62c0(undefined4 param_1)

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
  puStack_8 = &LAB_0097fe98;
  pvStack_c = ExceptionList;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660(param_1,0,0xffffffff);
  local_10 = (void *)0x15;
  local_4 = 0;
  uVar1 = (**(code **)(*DAT_00b5a7cc + 8))(&local_2c);
  if (local_18 < 0x10) {
    ExceptionList = local_10;
    return uVar1;
  }
  _free(local_2c);
  return extraout_EAX;
}


// ==== FUN_004b6350 @ 0x004b6350 ====

void FUN_004b6350(void *param_1,uint param_2,undefined4 *param_3)

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
      uVar7 = FUN_004b61e0();
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


// ==== FUN_004b6530 @ 0x004b6530 ====

void FUN_004b6530(uint param_1)

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
    uVar2 = FUN_004b6250();
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
    if (param_1 == 0) goto LAB_004b665c;
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
    if (uVar4 == 0) goto LAB_004b665c;
    puVar5 = _Dst;
  }
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
LAB_004b665c:
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
    *(undefined4 **)(in_ECX + 4) = _Dst;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004b6680 @ 0x004b6680 ====

undefined4 * FUN_004b6680(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    *param_3 = *param_1;
    FUN_00401660(param_1 + 1,0,0xffffffff);
    param_1 = param_1 + 8;
    param_3 = param_3 + 8;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_004b66c0 @ 0x004b66c0 ====

undefined4 * FUN_004b66c0(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x20;
    param_3 = param_3 + -8;
    *param_3 = *(undefined4 *)(param_2 + -0x20);
    FUN_00401660(param_2 + -0x1c,0,0xffffffff);
    param_2 = iVar1;
  } while (iVar1 != param_1);
  return param_3;
}


// ==== FUN_004b6700 @ 0x004b6700 ====

undefined4 * FUN_004b6700(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097fec1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 8) {
    local_8 = 1;
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      param_3[7] = 0xf;
      param_3[6] = 0;
      *(undefined1 *)(param_3 + 2) = 0;
      FUN_00401660(param_1 + 1,0,0xffffffff);
    }
    param_3 = param_3 + 8;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@004b676e @ 0x004b676e ====

void Catch_004b676e(void)

{
  int unaff_EBP;
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 0x10)) {
    puVar1 = (uint *)(iVar2 + 0x1c);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      iVar2 = iVar2 + 0x20;
      puVar1 = puVar1 + 8;
    } while (iVar2 != *(int *)(unaff_EBP + 0x10));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004b67d0 @ 0x004b67d0 ====

void FUN_004b67d0(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  
  if (((*(int *)(in_ECX + 0xc) + *(int *)(in_ECX + 0x10) & 3U) == 0) &&
     (*(uint *)(in_ECX + 8) <= *(int *)(in_ECX + 0x10) + 4U >> 2)) {
    FUN_004b6530(1);
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


// ==== FUN_004b6850 @ 0x004b6850 ====

void FUN_004b6850(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097fee1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = *param_3;
      param_1[7] = 0xf;
      param_1[6] = 0;
      *(undefined1 *)(param_1 + 2) = 0;
      FUN_00401660(param_3 + 1,0,0xffffffff);
    }
    param_1 = param_1 + 8;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004b68bf @ 0x004b68bf ====

void Catch_004b68bf(void)

{
  int unaff_EBP;
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 8)) {
    puVar1 = (uint *)(iVar2 + 0x1c);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      iVar2 = iVar2 + 0x20;
      puVar1 = puVar1 + 8;
    } while (iVar2 != *(int *)(unaff_EBP + 8));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004b6910 @ 0x004b6910 ====

void FUN_004b6910(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_004b6350(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_004b6960 @ 0x004b6960 ====

void FUN_004b6960(void)

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
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x20) {
    FUN_00446ee0();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004b69b0 @ 0x004b69b0 ====

void FUN_004b69b0(void)

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
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x20) {
    FUN_00446ee0();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004b69c0 @ 0x004b69c0 ====

void FUN_004b69c0(int *param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  FUN_004b6680(param_2 + 0x20,*(undefined4 *)(in_ECX + 8),param_2,param_2);
  iVar1 = *(int *)(in_ECX + 8);
  for (iVar2 = iVar1 + -0x20; iVar2 != iVar1; iVar2 = iVar2 + 0x20) {
    FUN_00446ee0();
  }
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + -0x20;
  *param_1 = param_2;
  return;
}


// ==== FUN_004b6a10 @ 0x004b6a10 ====

int FUN_004b6a10(int param_1,int param_2,undefined4 param_3)

{
  FUN_004b6850(param_1,param_2,param_3);
  return param_2 * 0x20 + param_1;
}


// ==== FUN_004b6a40 @ 0x004b6a40 ====

void FUN_004b6a40(int param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int extraout_ECX;
  int iVar5;
  undefined4 local_3c;
  void *local_34;
  undefined4 local_24;
  uint local_20;
  void *local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097fef8;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x48);
  local_3c = *param_3;
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3 + 1,0,0xffffffff);
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
      uVar1 = FUN_004b61e0();
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
      iVar2 = FUN_004b6700(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_004b6850(iVar2,param_2,&local_3c);
      FUN_004b6700(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x20);
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - iVar2 >> 5;
      }
      if (iVar2 != 0) {
        FUN_004c1940(iVar2,*(undefined4 *)(in_ECX + 8));
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
        FUN_004b6700(param_1,local_1c,param_2 * 0x20 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004b6a10(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 5),&local_3c)
        ;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x20;
        local_8 = 0;
        FUN_004c1400(param_1,*(int *)(in_ECX + 8) + param_2 * -0x20,&local_3c);
      }
      else {
        pvVar3 = (void *)((int)local_1c + param_2 * -0x20);
        uVar4 = FUN_004b6700(pvVar3,local_1c,local_1c);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_004b66c0(param_1,pvVar3,local_1c,param_1);
        FUN_004c1400(param_1,param_2 * 0x20 + param_1,&local_3c);
      }
    }
  }
  if (local_20 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_34);
  return;
}


// ==== Catch@004b6bd6 @ 0x004b6bd6 ====

void Catch_004b6bd6(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_004c1940(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@004b6c65 @ 0x004b6c65 ====

void Catch_004b6c65(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x20;
  FUN_004c1940(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004b6cf0 @ 0x004b6cf0 ====

void FUN_004b6cf0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 5) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 5))) {
    FUN_004b6a40(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_004b6850(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x20;
  return;
}


// ==== FUN_004b6d60 @ 0x004b6d60 ====

void FUN_004b6d60(byte param_1)

{
  void *in_ECX;
  
  FUN_004b5ad0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004b6d80 @ 0x004b6d80 ====

int FUN_004b6d80(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x84;
}


// ==== FUN_004b6da0 @ 0x004b6da0 ====

void FUN_004b6da0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  while (param_1 != param_2) {
    puVar1 = param_1 + 0x21;
    puVar3 = param_3;
    puVar4 = param_1;
    for (iVar2 = 0x21; param_1 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


// ==== FUN_004b6dd0 @ 0x004b6dd0 ====

void FUN_004b6dd0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  uVar2 = DAT_009b012c;
  uVar1 = DAT_009b0128;
  *in_ECX = DAT_0099de80;
  in_ECX[1] = uVar1;
  uVar3 = DAT_009b0124;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x14] = uVar2;
  uVar1 = DAT_0099d080;
  in_ECX[8] = DAT_0099d080;
  in_ECX[9] = uVar1;
  in_ECX[10] = uVar1;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = uVar1;
  uVar2 = DAT_009b0120;
  in_ECX[0xd] = uVar3;
  in_ECX[5] = 0;
  in_ECX[6] = uVar1;
  in_ECX[7] = uVar2;
  in_ECX[0x11] = uVar1;
  in_ECX[0x12] = uVar1;
  in_ECX[0x1f] = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  in_ECX[0x13] = uVar1;
  *(undefined1 *)(in_ECX + 0x15) = 0;
  in_ECX[0x17] = 0;
  *(undefined2 *)(in_ECX + 0x16) = 0;
  *(undefined2 *)((int)in_ECX + 0x56) = 0;
  *(undefined1 *)(in_ECX + 0x18) = 0;
  *(undefined1 *)(in_ECX + 0x1d) = 0;
  *(undefined1 *)((int)in_ECX + 0x75) = 0;
  *(undefined1 *)((int)in_ECX + 0x76) = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  *(undefined1 *)((int)in_ECX + 0x77) = 1;
  *(undefined1 *)(in_ECX + 0x1e) = 0xff;
  *(undefined1 *)((int)in_ECX + 0x79) = 1;
  return;
}


// ==== FUN_004b6f70 @ 0x004b6f70 ====

void FUN_004b6f70(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  while (param_1 != param_2) {
    param_2 = param_2 + -0x21;
    param_3 = param_3 + -0x21;
    puVar2 = param_2;
    puVar3 = param_3;
    for (iVar1 = 0x21; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}


// ==== FUN_004b6fb0 @ 0x004b6fb0 ====

void FUN_004b6fb0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  for (; param_1 != param_2; param_1 = param_1 + 0x21) {
    if (param_3 != (undefined4 *)0x0) {
      puVar2 = param_1;
      puVar3 = param_3;
      for (iVar1 = 0x21; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    param_3 = param_3 + 0x21;
  }
  return;
}


// ==== FUN_004b6ff0 @ 0x004b6ff0 ====

void FUN_004b6ff0(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_2 != 0) {
    do {
      if (param_1 != (undefined4 *)0x0) {
        puVar2 = param_3;
        puVar3 = param_1;
        for (iVar1 = 0x21; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
      }
      param_1 = param_1 + 0x21;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_004b7030 @ 0x004b7030 ====

int FUN_004b7030(int param_1,int param_2,undefined4 param_3)

{
  FUN_004b6ff0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x84;
}


// ==== FUN_004b7060 @ 0x004b7060 ====

void FUN_004b7060(void)

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
  puStack_8 = &LAB_00980008;
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


// ==== FUN_004b70d0 @ 0x004b70d0 ====

void FUN_004b70d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b0134;
  if ((void *)in_ECX[0x10] == (void *)0x0) {
    in_ECX[0x10] = 0;
    in_ECX[0x11] = 0;
    in_ECX[0x12] = 0;
    FUN_0049da30();
    return;
  }
  _free((void *)in_ECX[0x10]);
  return;
}


// ==== FUN_004b7110 @ 0x004b7110 ====

void FUN_004b7110(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980043;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0xffffffff;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  *in_ECX = &PTR_FUN_009b0134;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  local_4 = 1;
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004b71a0 @ 0x004b71a0 ====

/* WARNING: Removing unreachable block (ram,0x004b724d) */

void FUN_004b71a0(undefined4 param_1,uint *param_2)

{
  void *pvVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  float10 fVar13;
  char *pcVar14;
  undefined *puVar15;
  undefined1 local_fc [4];
  void *local_f8;
  int local_f4;
  undefined4 local_f0;
  float local_ec;
  float fStack_e8;
  undefined4 local_e4;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float local_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
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
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined4 uStack_14;
  undefined1 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00980058;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar3 = FUN_00411430();
  if (*param_2 < uVar3) {
    do {
      uVar4 = FUN_00411510(*param_2);
      local_f8 = (void *)0x0;
      local_f4 = 0;
      local_f0 = 0;
      local_4 = 0;
      FUN_00405670(uVar4,local_fc);
      pvVar1 = local_f8;
      if (local_f8 == (void *)0x0) {
LAB_004b7aae:
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      iVar5 = local_f4 - (int)local_f8 >> 0x1f;
      iVar7 = (local_f4 - (int)local_f8) / 0x1c + iVar5;
      if (iVar7 == iVar5) goto LAB_004b7aae;
      uVar3 = *(uint *)((int)local_f8 + 0x14);
      if (uVar3 != 0) {
        uVar6 = uVar3;
        if (6 < uVar3) {
          uVar6 = 7;
        }
        if (*(uint *)((int)local_f8 + 0x18) < 0x10) {
          pbVar9 = (byte *)((int)local_f8 + 4);
        }
        else {
          pbVar9 = *(byte **)((int)local_f8 + 4);
        }
        bVar11 = false;
        iVar8 = 0;
        bVar12 = true;
        pbVar10 = &DAT_009b0044;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          bVar11 = *pbVar9 < *pbVar10;
          bVar12 = *pbVar9 == *pbVar10;
          pbVar9 = pbVar9 + 1;
          pbVar10 = pbVar10 + 1;
        } while (bVar12);
        if (!bVar12) {
          iVar8 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        }
        if (((iVar8 == 0) && (6 < uVar3)) && (uVar3 == 7)) {
          FUN_004b6dd0();
          local_4 = 0xffffffff;
          FUN_00405de0(pvVar1,local_f4,local_fc,local_e4);
          _free(local_f8);
          return;
        }
      }
      if (iVar7 == iVar5) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      iVar5 = FUN_00403620(0,*(undefined4 *)((int)local_f8 + 0x14),s_<_light>_009b004c,8);
      if (iVar5 == 0) {
        FUN_004b8030(&local_90);
        if (local_f8 == (void *)0x0) {
          ExceptionList = local_c;
          return;
        }
        FUN_00405de0(local_f8,local_f4,local_fc,local_e4);
        _free(local_f8);
        return;
      }
      if ((local_f8 == (void *)0x0) ||
         (local_ec = (float)((local_f4 - (int)local_f8) / 0x1c), local_ec == 0.0)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      iVar5 = FUN_00403620(0,*(undefined4 *)((int)local_f8 + 0x14),s_lightdistance_009b0058,0xd);
      if (iVar5 == 0) {
        if ((local_f8 == (void *)0x0) || ((uint)((local_f4 - (int)local_f8) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        fVar13 = (float10)thunk_FUN_00796ec0((int)local_f8 + 0x1c);
        fStack_40 = (float)fVar13;
      }
      else {
        if ((local_f8 == (void *)0x0) ||
           (local_ec = (float)((local_f4 - (int)local_f8) / 0x1c), local_ec == 0.0)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        iVar5 = FUN_00403620(0,*(undefined4 *)((int)local_f8 + 0x14),s_dirlight_dir_009b0068,0xc);
        if (iVar5 == 0) {
          if ((local_f8 == (void *)0x0) || (uVar3 = (local_f4 - (int)local_f8) / 0x1c, uVar3 < 4)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          if (uVar3 < 3) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar5 = (int)local_f8 + 0x38;
          if (uVar3 < 2) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar7 = (int)local_f8 + 0x1c;
          fVar13 = (float10)thunk_FUN_00796ec0((int)local_f8 + 0x54);
          local_ec = (float)fVar13;
          fVar13 = (float10)thunk_FUN_00796ec0(iVar5);
          fStack_e8 = (float)fVar13;
          fVar13 = (float10)thunk_FUN_00796ec0(iVar7);
          fStack_a8 = (float)fVar13;
          fStack_a4 = fStack_e8;
          fStack_a0 = local_ec;
          fStack_78 = fStack_e8;
          fStack_74 = local_ec;
          fStack_7c = fStack_a8;
        }
        else {
          if ((local_f8 == (void *)0x0) ||
             (local_ec = (float)((local_f4 - (int)local_f8) / 0x1c), local_ec == 0.0)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar5 = FUN_00403620(0,*(undefined4 *)((int)local_f8 + 0x14),s_dirlight_color_009b0078,0xe
                              );
          if (iVar5 == 0) {
            uVar4 = FUN_00405d30(3);
            fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
            fStack_e8 = (float)fVar13;
            uVar4 = FUN_00405d30(2);
            fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
            local_ec = (float)fVar13;
            uVar4 = FUN_00405d30(1);
            fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
            fStack_e0 = (float)fVar13;
            fStack_dc = local_ec;
            fStack_d8 = fStack_e8;
            fStack_6c = local_ec;
            fStack_68 = fStack_e8;
            fStack_70 = fStack_e0;
          }
          else {
            pcVar14 = s_dirbacklight_dir_009b0088;
            uVar4 = FUN_00405d30(0);
            cVar2 = FUN_004036a0(uVar4,pcVar14);
            if (cVar2 == '\0') {
              pcVar14 = s_dirbacklight_color_009b009c;
              uVar4 = FUN_00405d30(0);
              cVar2 = FUN_004036a0(uVar4,pcVar14);
              if (cVar2 == '\0') {
                pcVar14 = s_ambient_color_009b00b0;
                uVar4 = FUN_00405d30(0);
                cVar2 = FUN_004036a0(uVar4,pcVar14);
                if (cVar2 == '\0') {
                  pcVar14 = s_fog_value_009b00c0;
                  uVar4 = FUN_00405d30(0);
                  cVar2 = FUN_004036a0(uVar4,pcVar14);
                  if (cVar2 == '\0') {
                    pcVar14 = s_fog_color_009b00cc;
                    uVar4 = FUN_00405d30(0);
                    cVar2 = FUN_004036a0(uVar4,pcVar14);
                    if (cVar2 == '\0') {
                      pcVar14 = s_bloom_value_009b00d8;
                      uVar4 = FUN_00405d30(0);
                      cVar2 = FUN_004036a0(uVar4,pcVar14);
                      if (cVar2 == '\0') {
                        pcVar14 = s_weather_value_009b00e4;
                        uVar4 = FUN_00405d30(0);
                        cVar2 = FUN_004036a0(uVar4,pcVar14);
                        if (cVar2 == '\0') {
                          pcVar14 = s_night_009b00f4;
                          uVar4 = FUN_00405d30(0);
                          cVar2 = FUN_004036a0(uVar4,pcVar14);
                          if (cVar2 == '\0') {
                            puVar15 = &DAT_009b00fc;
                            uVar4 = FUN_00405d30(0);
                            cVar2 = FUN_004036a0(uVar4,puVar15);
                            if (cVar2 == '\0') {
                              pcVar14 = s_sky_type_009b0104;
                              uVar4 = FUN_00405d30(0);
                              cVar2 = FUN_004036a0(uVar4,pcVar14);
                              if (cVar2 == '\0') {
                                pcVar14 = s_cloud_type_009b0110;
                                uVar4 = FUN_00405d30(0);
                                cVar2 = FUN_004036a0(uVar4,pcVar14);
                                if (cVar2 != '\0') {
                                  uVar4 = FUN_00405d30(1);
                                  uStack_1b = thunk_FUN_00796f50(uVar4);
                                  uVar4 = FUN_00405d30(2);
                                  uStack_1a = thunk_FUN_00796f50(uVar4);
                                  uVar4 = FUN_00405d30(3);
                                  uStack_19 = thunk_FUN_00796f50(uVar4);
                                  uVar4 = FUN_00405d30(4);
                                  uStack_18 = thunk_FUN_00796f50(uVar4);
                                  uVar4 = FUN_00405d30(5);
                                  uStack_17 = thunk_FUN_00796f50(uVar4);
                                }
                              }
                              else {
                                uVar4 = FUN_00405d30(1);
                                uStack_1c = thunk_FUN_00796f50(uVar4);
                              }
                            }
                            else {
                              uVar4 = FUN_00405d30(1);
                              uStack_14 = thunk_FUN_00796e60(uVar4);
                            }
                          }
                          else {
                            uVar4 = FUN_00405d30(1);
                            iVar5 = thunk_FUN_00796e60(uVar4);
                            uStack_10 = iVar5 != 0;
                          }
                        }
                        else {
                          uVar4 = FUN_00405d30(1);
                          iVar5 = thunk_FUN_00796e60(uVar4);
                          uStack_3c = iVar5 != 0;
                          uVar4 = FUN_00405d30(2);
                          uStack_3a = thunk_FUN_00796f80(uVar4);
                          uVar4 = FUN_00405d30(3);
                          uStack_38 = thunk_FUN_00796f80(uVar4);
                          uVar4 = FUN_00405d30(4);
                          uStack_34 = thunk_FUN_00796e60(uVar4);
                        }
                      }
                      else {
                        uVar4 = FUN_00405d30(1);
                        iVar5 = thunk_FUN_00796e60(uVar4);
                        uStack_30 = iVar5 != 0;
                        uVar4 = FUN_00405d30(2);
                        fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
                        fStack_2c = (float)fVar13;
                        uVar4 = FUN_00405d30(3);
                        fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
                        fStack_28 = (float)fVar13;
                        uVar4 = FUN_00405d30(4);
                        fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
                        fStack_24 = (float)fVar13;
                        uVar4 = FUN_00405d30(5);
                        fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
                        fStack_20 = (float)fVar13;
                      }
                    }
                    else {
                      uVar4 = FUN_00405d30(3);
                      fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
                      fStack_e8 = (float)fVar13;
                      uVar4 = FUN_00405d30(2);
                      fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
                      local_ec = (float)fVar13;
                      uVar4 = FUN_00405d30(1);
                      fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
                      fStack_c0 = (float)fVar13;
                      fStack_bc = local_ec;
                      fStack_b8 = fStack_e8;
                      fStack_84 = local_ec;
                      fStack_80 = fStack_e8;
                      fStack_88 = fStack_c0;
                    }
                  }
                  else {
                    uVar4 = FUN_00405d30(2);
                    fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
                    local_ec = (float)fVar13;
                    uVar4 = FUN_00405d30(1);
                    fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
                    fStack_c8 = (float)fVar13;
                    fStack_c4 = local_ec;
                    fStack_8c = local_ec;
                    local_90 = fStack_c8;
                  }
                }
                else {
                  uVar4 = FUN_00405d30(3);
                  fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
                  fStack_e8 = (float)fVar13;
                  uVar4 = FUN_00405d30(2);
                  fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
                  local_ec = (float)fVar13;
                  uVar4 = FUN_00405d30(1);
                  fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
                  fStack_d4 = (float)fVar13;
                  fStack_d0 = local_ec;
                  fStack_cc = fStack_e8;
                  fStack_48 = local_ec;
                  fStack_44 = fStack_e8;
                  fStack_4c = fStack_d4;
                }
              }
              else {
                uVar4 = FUN_00405d30(3);
                fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
                fStack_e8 = (float)fVar13;
                uVar4 = FUN_00405d30(2);
                fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
                local_ec = (float)fVar13;
                uVar4 = FUN_00405d30(1);
                fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
                fStack_b4 = (float)fVar13;
                fStack_b0 = local_ec;
                fStack_ac = fStack_e8;
                fStack_54 = local_ec;
                fStack_50 = fStack_e8;
                fStack_58 = fStack_b4;
              }
            }
            else {
              uVar4 = FUN_00405d30(3);
              fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
              fStack_e8 = (float)fVar13;
              uVar4 = FUN_00405d30(2);
              fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
              local_ec = (float)fVar13;
              uVar4 = FUN_00405d30(1);
              fVar13 = (float10)thunk_FUN_00796ec0(uVar4);
              fStack_9c = (float)fVar13;
              fStack_98 = local_ec;
              fStack_94 = fStack_e8;
              fStack_60 = local_ec;
              fStack_5c = fStack_e8;
              fStack_64 = fStack_9c;
            }
          }
        }
      }
      local_4 = 0xffffffff;
      if (local_f8 != (void *)0x0) {
        FUN_00405de0(local_f8,local_f4,local_fc,local_e4);
        _free(local_f8);
        return;
      }
      local_f8 = (void *)0x0;
      local_f4 = 0;
      local_f0 = 0;
      *param_2 = *param_2 + 1;
      uVar3 = FUN_00411430();
    } while (*param_2 < uVar3);
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004b7b40 @ 0x004b7b40 ====

/* WARNING: Removing unreachable block (ram,0x004b7cc3) */

undefined4 FUN_004b7b40(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  int iStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098006a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 != 9) {
    ExceptionList = pvStack_c;
    return 0;
  }
  uVar5 = 0;
  param_1 = (int *)0x0;
  iVar2 = FUN_00411430();
  if (iVar2 != 0) {
    do {
      uVar3 = FUN_00411510(uVar5);
      pvStack_18 = (void *)0x0;
      iStack_14 = 0;
      uStack_10 = 0;
      uStack_4 = 0;
      FUN_00405670(uVar3,auStack_1c);
      if ((pvStack_18 == (void *)0x0) ||
         (iVar2 = iStack_14 - (int)pvStack_18 >> 0x1f,
         (iStack_14 - (int)pvStack_18) / 0x1c + iVar2 == iVar2)) {
        uStack_4 = 0xffffffff;
        if (pvStack_18 != (void *)0x0) {
          FUN_00405de0(pvStack_18,iStack_14,auStack_1c,param_1);
          goto LAB_004b7c65;
        }
      }
      else {
        iVar2 = FUN_00403620(0,*(undefined4 *)((int)pvStack_18 + 0x14),s_<light>_009b003c,7);
        if (iVar2 == 0) {
          FUN_004b71a0(piVar1,&param_1);
        }
        uStack_4 = 0xffffffff;
        if (pvStack_18 != (void *)0x0) {
          FUN_00405de0(pvStack_18,iStack_14,auStack_1c,param_1);
LAB_004b7c65:
          _free(pvStack_18);
          return extraout_EAX;
        }
      }
      uStack_4 = 0xffffffff;
      uVar5 = (int)param_1 + 1;
      pvStack_18 = (void *)0x0;
      iStack_14 = 0;
      uStack_10 = 0;
      param_1 = (int *)uVar5;
      uVar4 = FUN_00411430();
    } while (uVar5 < uVar4);
  }
  uVar3 = (**(code **)(*piVar1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar3;
  *(int **)(in_ECX + 0x20) = piVar1;
  *(undefined4 *)(in_ECX + 0x34) = 2;
  ExceptionList = pvStack_c;
  return 1;
}


// ==== FUN_004b7cd0 @ 0x004b7cd0 ====

void FUN_004b7cd0(int param_1,uint param_2,undefined4 *param_3)

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
  undefined4 local_98;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980020;
  local_10 = ExceptionList;
  puVar7 = &local_98;
  for (iVar4 = 0x21; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *param_3;
    param_3 = param_3 + 1;
    puVar7 = puVar7 + 1;
  }
  iVar4 = *(int *)(in_ECX + 4);
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar4) / 0x84;
  }
  if (param_2 != 0) {
    if (iVar4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar4) / 0x84;
    }
    ExceptionList = &local_10;
    local_14 = (undefined1 *)((int)register0x00000010 + -0xa4);
    if (0x1f07c1fU - iVar1 < param_2) {
      ExceptionList = &local_10;
      local_14 = (undefined1 *)((int)register0x00000010 + -0xa4);
      FUN_004b7060();
      uVar5 = extraout_ECX;
    }
    if (iVar4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar4) / 0x84;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x1f07c1f - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = (*(int *)(in_ECX + 8) - iVar4) / 0x84;
      }
      if (uVar5 < iVar4 + param_2) {
        iVar4 = FUN_004b6d80();
        uVar5 = iVar4 + param_2;
      }
      pvVar2 = operator_new(uVar5 * 0x84);
      local_8 = 0;
      iVar4 = FUN_004b6fb0(*(undefined4 *)(in_ECX + 4),param_1,pvVar2);
      FUN_004b6ff0(iVar4,param_2,&local_98);
      FUN_004b6fb0(param_1,*(undefined4 *)(in_ECX + 8),iVar4 + param_2 * 0x84);
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x84;
      }
      if (_Memory == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x84 + (int)pvVar2);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar2 + (param_2 + iVar4) * 0x84);
        *(void **)(in_ECX + 4) = pvVar2;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar4 = *(int *)(in_ECX + 8);
    iVar1 = param_2 * 0x84;
    if ((uint)((iVar4 - param_1) / 0x84) < param_2) {
      FUN_004b6fb0(param_1,iVar4,iVar1 + param_1);
      local_8 = 2;
      FUN_004b7030(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x84,&local_98)
      ;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar1;
      FUN_004b6da0(param_1,*(int *)(in_ECX + 8) + param_2 * -0x84,&local_98);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar4 + param_2 * -0x84;
    uVar3 = FUN_004b6fb0(iVar6,iVar4,iVar4);
    *(undefined4 *)(in_ECX + 8) = uVar3;
    FUN_004b6f70(param_1,iVar6,iVar4);
    FUN_004b6da0(param_1,iVar1 + param_1,&local_98);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004b7e96 @ 0x004b7e96 ====

void Catch_004b7e96(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_004b7fa0 @ 0x004b7fa0 ====

void FUN_004b7fa0(byte param_1)

{
  void *in_ECX;
  
  FUN_004b70d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004b7fc0 @ 0x004b7fc0 ====

void FUN_004b7fc0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x84 != 0) {
      iVar1 = (param_2 - iVar1) / 0x84;
      goto LAB_004b8005;
    }
  }
  iVar1 = 0;
LAB_004b8005:
  FUN_004b7cd0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x84;
  return;
}


// ==== FUN_004b8030 @ 0x004b8030 ====

void FUN_004b8030(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x84) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x84))) {
    FUN_004b7fc0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_004b6ff0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x84;
  return;
}


// ==== FUN_004b80e0 @ 0x004b80e0 ====

void FUN_004b80e0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098009e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0xffffffff;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  *in_ECX = &PTR_FUN_009b01ac;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  local_4 = 2;
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004b8170 @ 0x004b8170 ====

void FUN_004b8170(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b01ac;
  if ((void *)in_ECX[0x14] == (void *)0x0) {
    in_ECX[0x14] = 0;
    in_ECX[0x15] = 0;
    in_ECX[0x16] = 0;
    FUN_00413810();
    FUN_0049da30();
    return;
  }
  _free((void *)in_ECX[0x14]);
  return;
}


// ==== FUN_004b81b0 @ 0x004b81b0 ====

undefined4 FUN_004b81b0(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 != 10) {
    return 0;
  }
  iVar1 = param_1[6];
  for (iVar2 = param_1[5]; iVar2 != iVar1; iVar2 = iVar2 + 0x3c) {
    FUN_0042a620(iVar2);
  }
  FUN_0042a100(param_1 + 9);
  uVar3 = (**(code **)(*param_1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar3;
  *(int **)(in_ECX + 0x20) = param_1;
  *(undefined4 *)(in_ECX + 0x34) = 2;
  return 1;
}


// ==== FUN_004b8220 @ 0x004b8220 ====

undefined4 FUN_004b8220(void)

{
  char cVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  puVar2 = (undefined4 *)FUN_004b8270();
  if (puVar2 != (undefined4 *)0x0) {
    FUN_004299b0();
    cVar1 = (**(code **)(*in_ECX + 0x10))(puVar2);
    if (cVar1 != '\0') {
      return 1;
    }
    (**(code **)*puVar2)(1);
  }
  return 0;
}


// ==== FUN_004b8260 @ 0x004b8260 ====

undefined4 FUN_004b8260(void)

{
  return 0xc;
}


// ==== FUN_004b8270 @ 0x004b8270 ====

undefined4 * FUN_004b8270(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined4 *extraout_EAX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009800d6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar2 = operator_new(0x34);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_0099d59c;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
    puVar2[10] = 0;
    puVar2[0xb] = 0;
    puVar2[0xc] = 0;
  }
  local_4 = 0xffffffff;
  if (puVar2 != (undefined4 *)0x0) {
    ExceptionList = local_c;
    return puVar2;
  }
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_10 = 0xf;
  FUN_00401740(&DAT_0099e358,2);
  local_4 = 3;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    puVar2 = (undefined4 *)(*pcVar1)();
    return puVar2;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_004b8320 @ 0x004b8320 ====

void FUN_004b8320(byte param_1)

{
  void *in_ECX;
  
  FUN_004b8170();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004b8340 @ 0x004b8340 ====

void FUN_004b8340(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x19) == '\0') {
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


// ==== FUN_004b83a0 @ 0x004b83a0 ====

void FUN_004b83a0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x19) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x19) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x19);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x19);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x19) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x19) == '\0');
    if (*(char *)((int)piVar4 + 0x19) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_004b8400 @ 0x004b8400 ====

void FUN_004b8400(void *param_1)

{
  if (*(char *)((int)param_1 + 0x19) == '\0') {
    FUN_004b8400(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004b8440 @ 0x004b8440 ====

void FUN_004b8440(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  piVar1 = *(int **)(in_ECX + 0x44);
  for (piVar2 = *(int **)(in_ECX + 0x40); piVar2 != piVar1; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x1c))(*piVar2);
    }
  }
  if (*(int *)(in_ECX + 0xb0) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x1c))(*(int *)(in_ECX + 0xb0));
    *(undefined4 *)(in_ECX + 0xb0) = 0;
  }
  *(undefined1 *)(in_ECX + 0x38) = 1;
  return;
}


// ==== FUN_004b84a0 @ 0x004b84a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b84a0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  float10 fVar4;
  int local_8 [2];
  
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || ((uint)((*(int *)(param_1 + 8) - iVar2) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
    FUN_00405ca0();
  }
  iVar1 = in_ECX + param_2 * 0x14;
  local_8[0] = in_ECX;
  fVar4 = (float10)thunk_FUN_00796ec0(iVar2 + 0x1c);
  *(float *)(iVar1 + 0x70) = (float)fVar4;
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || ((uint)((*(int *)(param_1 + 8) - iVar2) / 0x1c) < 3)) {
                    /* WARNING: Subroutine does not return */
    FUN_00405ca0();
  }
  fVar4 = (float10)thunk_FUN_00796ec0(iVar2 + 0x38);
  *(float *)(iVar1 + 0x74) = (float)fVar4;
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || ((uint)((*(int *)(param_1 + 8) - iVar2) / 0x1c) < 4)) {
                    /* WARNING: Subroutine does not return */
    FUN_00405ca0();
  }
  fVar4 = (float10)thunk_FUN_00796ec0(iVar2 + 0x54);
  *(float *)(local_8[0] + (param_2 * 5 + 0x1e) * 4) = (float)fVar4;
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || ((uint)((*(int *)(param_1 + 8) - iVar2) / 0x1c) < 5)) {
                    /* WARNING: Subroutine does not return */
    FUN_00405ca0();
  }
  fVar4 = (float10)thunk_FUN_00796ec0(iVar2 + 0x70);
  uVar3 = FUN_0040d600(local_8,(float)(fVar4 * (float10)_DAT_00ae767c));
  thunk_FUN_0079de77(iVar1 + 0x7c,uVar3);
  return;
}


// ==== FUN_004b85e0 @ 0x004b85e0 ====

void FUN_004b85e0(int param_1,uint param_2)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  void *pvVar7;
  float10 fVar8;
  float local_34;
  int local_2c;
  undefined4 uStack_24;
  float fStack_20;
  undefined1 local_1c [4];
  void *local_18;
  int local_14;
  int local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980118;
  pvStack_c = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
  }
  iVar4 = (int)(iVar4 - param_2) / 2;
  bVar3 = true;
  bVar2 = false;
  local_34 = 0.0;
  local_18 = (void *)0x0;
  local_14 = 0;
  local_10 = 0;
  local_4 = 0;
  local_2c = 0;
  ExceptionList = &pvStack_c;
  if (0 < iVar4) {
    iVar6 = param_2 * 0x1c;
    ExceptionList = &pvStack_c;
    do {
      iVar1 = *(int *)(param_1 + 4);
      if ((iVar1 == 0) || ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x1c) <= param_2)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uVar5 = thunk_FUN_00796e60(iVar1 + iVar6);
      iVar1 = *(int *)(param_1 + 4);
      if ((iVar1 == 0) || ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x1c) <= param_2 + 1)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      fVar8 = (float10)thunk_FUN_00796ec0(iVar1 + iVar6 + 0x1c);
      iVar1 = local_14;
      pvVar7 = local_18;
      fStack_20 = (float)fVar8;
      param_2 = param_2 + 2;
      iVar6 = iVar6 + 0x38;
      uStack_24 = uVar5;
      if ((local_18 == (void *)0x0) ||
         ((uint)(local_10 - (int)local_18 >> 3) <= (uint)(local_14 - (int)local_18 >> 3))) {
        FUN_004b9740(local_14,1,&uStack_24);
        pvVar7 = local_18;
      }
      else {
        FUN_00429bc0(local_14,1,&uStack_24,local_1c,param_1);
        local_14 = iVar1 + 8;
      }
      if (bVar2) {
        if (local_34 != (float)fVar8) {
          bVar3 = false;
        }
      }
      else {
        bVar2 = true;
        local_34 = (float)fVar8;
      }
      local_2c = local_2c + 1;
    } while (local_2c < iVar4);
    if (((pvVar7 != (void *)0x0) && (local_14 - (int)local_18 >> 3 != 0)) && (bVar3)) {
      _free(local_18);
      return;
    }
  }
  FUN_004b9a80(0,1000,local_1c);
  if (local_18 == (void *)0x0) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004b8850 @ 0x004b8850 ====

void FUN_004b8850(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980143;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009b0274;
  local_4 = 2;
  if (*(char *)(in_ECX + 0xe) == '\0') {
    FUN_004b8440();
  }
  if ((void *)in_ECX[0x10] == (void *)0x0) {
    in_ECX[0x10] = 0;
    in_ECX[0x11] = 0;
    in_ECX[0x12] = 0;
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_004b9680(local_10,*(undefined4 *)in_ECX[0x27],(undefined4 *)in_ECX[0x27]);
    _free((void *)in_ECX[0x27]);
    return;
  }
  _free((void *)in_ECX[0x10]);
  return;
}


// ==== FUN_004b8920 @ 0x004b8920 ====

void FUN_004b8920(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *in_ECX;
  int iVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098016e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0xffffffff;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  *in_ECX = &PTR_FUN_009b0274;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  uVar1 = DAT_0099d0f8;
  local_4 = 1;
  puVar3 = in_ECX + 0x1c;
  iVar4 = 2;
  do {
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = uVar1;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3 = puVar3 + 5;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = FUN_0058b910();
  in_ECX[0x27] = iVar4;
  *(undefined1 *)(iVar4 + 0x19) = 1;
  *(undefined4 *)(in_ECX[0x27] + 4) = in_ECX[0x27];
  *(undefined4 *)in_ECX[0x27] = in_ECX[0x27];
  *(undefined4 *)(in_ECX[0x27] + 8) = in_ECX[0x27];
  in_ECX[0x28] = 0;
  local_4 = CONCAT31(local_4._1_3_,2);
  in_ECX[0x2c] = 0;
  in_ECX[0x1b] = 1;
  FUN_00401660(param_1,0,0xffffffff);
  uVar2 = DAT_009b02b0;
  uVar1 = DAT_009b02ac;
  in_ECX[0x14] = DAT_009b02b4;
  in_ECX[0x15] = uVar2;
  uVar2 = DAT_009b02a8;
  in_ECX[0x16] = uVar1;
  in_ECX[0x17] = uVar2;
  uVar1 = DAT_0099d080;
  in_ECX[0x18] = uVar2;
  in_ECX[0x19] = uVar1;
  in_ECX[0x1a] = uVar1;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004b8ab0 @ 0x004b8ab0 ====

uint FUN_004b8ab0(int *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint uVar7;
  uint extraout_EAX_01;
  int in_ECX;
  int iVar8;
  float10 fVar9;
  char *pcVar10;
  undefined *puVar11;
  undefined1 uStack_4d;
  int local_4c;
  uint uStack_48;
  undefined4 uStack_44;
  int iStack_40;
  undefined1 auStack_3c [4];
  void *pvStack_38;
  int iStack_34;
  undefined4 uStack_30;
  void *pvStack_2c;
  int iStack_28;
  undefined1 *puStack_24;
  int iStack_20;
  undefined1 auStack_1c [12];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00980188;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_4c = in_ECX;
  uVar2 = (**(code **)(*param_1 + 4))();
  if (uVar2 != 9) {
    ExceptionList = pvStack_c;
    return uVar2 & 0xffffff00;
  }
  iStack_28 = 0;
  puStack_24 = (undefined1 *)0x0;
  iStack_20 = 0;
  uStack_4 = 0;
  uStack_4d = 0x28;
  FUN_00417f70(0,1,&uStack_4d);
  uStack_4d = 0x29;
  if ((iStack_28 == 0) || ((uint)(iStack_20 - iStack_28) <= (uint)((int)puStack_24 - iStack_28))) {
    FUN_00417f70(puStack_24,1,&uStack_4d);
  }
  else {
    *puStack_24 = 0x29;
    puStack_24 = puStack_24 + 1;
  }
  uStack_4d = 0x7b;
  if ((iStack_28 == 0) || ((uint)(iStack_20 - iStack_28) <= (uint)((int)puStack_24 - iStack_28))) {
    FUN_00417f70(puStack_24,1,&uStack_4d);
  }
  else {
    *puStack_24 = 0x7b;
    puStack_24 = puStack_24 + 1;
  }
  uStack_4d = 0x7d;
  if ((iStack_28 == 0) || ((uint)(iStack_20 - iStack_28) <= (uint)((int)puStack_24 - iStack_28))) {
    FUN_00417f70(puStack_24,1,&uStack_4d);
  }
  else {
    *puStack_24 = 0x7d;
    puStack_24 = puStack_24 + 1;
  }
  uStack_4d = 0x2c;
  if ((iStack_28 == 0) || ((uint)(iStack_20 - iStack_28) <= (uint)((int)puStack_24 - iStack_28))) {
    FUN_00417f70(puStack_24,1,&uStack_4d);
  }
  else {
    *puStack_24 = 0x2c;
    puStack_24 = puStack_24 + 1;
  }
  uStack_4d = 0x20;
  if ((iStack_28 == 0) || ((uint)(iStack_20 - iStack_28) <= (uint)((int)puStack_24 - iStack_28))) {
    FUN_00417f70(puStack_24,1,&uStack_4d);
  }
  else {
    *puStack_24 = 0x20;
    puStack_24 = puStack_24 + 1;
  }
  uStack_4d = 9;
  if ((iStack_28 == 0) || ((uint)(iStack_20 - iStack_28) <= (uint)((int)puStack_24 - iStack_28))) {
    FUN_00417f70(puStack_24,1,&uStack_4d);
  }
  else {
    *puStack_24 = 9;
    puStack_24 = puStack_24 + 1;
  }
  uVar2 = 0;
  uStack_48 = 0;
  iVar3 = FUN_00411430();
  if (iVar3 != 0) {
    do {
      iVar3 = 0;
      uVar4 = FUN_00411510(uVar2);
      pvStack_38 = (void *)0x0;
      iStack_34 = 0;
      uStack_30 = 0;
      uStack_4 = CONCAT31(uStack_4._1_3_,1);
      FUN_00404b60(uVar4,auStack_3c,&pvStack_2c);
      if (pvStack_38 == (void *)0x0) {
LAB_004b9091:
        uStack_4 = uStack_4 & 0xffffff00;
        if (pvStack_38 != (void *)0x0) {
          FUN_00405de0(pvStack_38,iStack_34,auStack_3c,param_1);
          _free(pvStack_38);
          return extraout_EAX_00;
        }
      }
      else {
        iVar5 = iStack_34 - (int)pvStack_38 >> 0x1f;
        iVar8 = (iStack_34 - (int)pvStack_38) / 0x1c + iVar5;
        if (iVar8 == iVar5) goto LAB_004b9091;
        if (iVar8 == iVar5) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        iVar5 = FUN_00403620(0,*(undefined4 *)((int)pvStack_38 + 0x14),&DAT_009b021c,1);
        if (iVar5 == 0) goto LAB_004b9091;
        if ((pvStack_38 == (void *)0x0) ||
           (iStack_40 = (iStack_34 - (int)pvStack_38) / 0x1c, iStack_40 == 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        iVar5 = FUN_00403620(0,*(undefined4 *)((int)pvStack_38 + 0x14),s_texture_009b0220,7);
        if (iVar5 == 0) {
          if ((pvStack_38 == (void *)0x0) || ((uint)((iStack_34 - (int)pvStack_38) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iStack_40 = thunk_FUN_00796e60((int)pvStack_38 + 0x1c);
          if (0 < iStack_40) {
            iVar5 = 0x38;
            do {
              if ((pvStack_38 == (void *)0x0) ||
                 ((uint)((iStack_34 - (int)pvStack_38) / 0x1c) <= iVar3 + 2U)) {
                    /* WARNING: Subroutine does not return */
                FUN_00405ca0();
              }
              uStack_44 = FUN_004b4e70(iVar5 + (int)pvStack_38);
              iVar8 = *(int *)(in_ECX + 0x40);
              if ((iVar8 == 0) ||
                 ((uint)(*(int *)(in_ECX + 0x48) - iVar8 >> 2) <=
                  (uint)(*(int *)(in_ECX + 0x44) - iVar8 >> 2))) {
                FUN_004b4f00(*(undefined4 *)(in_ECX + 0x44),1,&uStack_44);
              }
              else {
                puVar6 = *(undefined4 **)(in_ECX + 0x44);
                *puVar6 = uStack_44;
                *(undefined4 **)(in_ECX + 0x44) = puVar6 + 1;
              }
              iVar3 = iVar3 + 1;
              iVar5 = iVar5 + 0x1c;
              in_ECX = local_4c;
            } while (iVar3 < iStack_40);
            uVar2 = uStack_48;
          }
        }
        else {
          if ((pvStack_38 == (void *)0x0) ||
             (iStack_40 = (iStack_34 - (int)pvStack_38) / 0x1c, iStack_40 == 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar3 = FUN_00403620(0,*(undefined4 *)((int)pvStack_38 + 0x14),&DAT_009b0228,4);
          if (iVar3 == 0) {
            uVar4 = FUN_00405d30(1);
            uVar4 = thunk_FUN_00796e60(uVar4);
            *(undefined4 *)(in_ECX + 0x4c) = uVar4;
          }
          else {
            pcVar10 = s_bumptex_009b0230;
            uVar4 = FUN_00405d30(0);
            cVar1 = FUN_004036a0(uVar4,pcVar10);
            if (cVar1 == '\0') {
              puVar11 = &DAT_009b0238;
              uVar4 = FUN_00405d30(0);
              cVar1 = FUN_004036a0(uVar4,puVar11);
              if (cVar1 == '\0') {
                pcVar10 = s_wave1_009b0240;
                uVar4 = FUN_00405d30(0);
                cVar1 = FUN_004036a0(uVar4,pcVar10);
                if (cVar1 == '\0') {
                  pcVar10 = s_wave2_009b0248;
                  uVar4 = FUN_00405d30(0);
                  cVar1 = FUN_004036a0(uVar4,pcVar10);
                  if (cVar1 == '\0') {
                    pcVar10 = s_attenuation_009b0250;
                    uVar4 = FUN_00405d30(0);
                    cVar1 = FUN_004036a0(uVar4,pcVar10);
                    if (cVar1 == '\0') {
                      pcVar10 = s_color_009b025c;
                      uVar4 = FUN_00405d30(0);
                      cVar1 = FUN_004036a0(uVar4,pcVar10);
                      if (cVar1 == '\0') {
                        pcVar10 = s_alpha_009b0264;
                        uVar4 = FUN_00405d30(0);
                        cVar1 = FUN_004036a0(uVar4,pcVar10);
                        if (cVar1 != '\0') {
                          FUN_004b85e0(auStack_3c,1,in_ECX + 0x98);
                        }
                      }
                      else {
                        uVar4 = FUN_00405d30(1);
                        uVar4 = thunk_FUN_00796e90(uVar4);
                        puVar6 = (undefined4 *)FUN_0040ec60(auStack_1c,uVar4);
                        *(undefined4 *)(in_ECX + 0x5c) = *puVar6;
                        *(undefined4 *)(in_ECX + 0x60) = puVar6[1];
                        *(undefined4 *)(in_ECX + 100) = puVar6[2];
                        *(undefined4 *)(in_ECX + 0x68) = puVar6[3];
                      }
                    }
                    else {
                      uVar4 = FUN_00405d30(1);
                      fVar9 = (float10)thunk_FUN_00796ec0(uVar4);
                      *(float *)(in_ECX + 0x50) = (float)fVar9;
                      uVar4 = FUN_00405d30(2);
                      fVar9 = (float10)thunk_FUN_00796ec0(uVar4);
                      *(float *)(in_ECX + 0x54) = (float)fVar9;
                      uVar4 = FUN_00405d30(3);
                      fVar9 = (float10)thunk_FUN_00796ec0(uVar4);
                      *(float *)(in_ECX + 0x58) = (float)fVar9;
                    }
                  }
                  else {
                    FUN_004b84a0(auStack_3c,1);
                  }
                }
                else {
                  FUN_004b84a0(auStack_3c,0);
                }
              }
              else {
                uVar4 = FUN_00405d30(1);
                uVar4 = thunk_FUN_00796e60(uVar4);
                *(undefined4 *)(in_ECX + 0x6c) = uVar4;
              }
            }
            else {
              uVar4 = FUN_00405d30(1);
              uVar4 = FUN_004b4e70(uVar4);
              *(undefined4 *)(in_ECX + 0xb0) = uVar4;
            }
          }
        }
        uStack_4 = uStack_4 & 0xffffff00;
        if (pvStack_38 != (void *)0x0) {
          FUN_00405de0(pvStack_38,iStack_34,auStack_3c,param_1);
          _free(pvStack_38);
          return extraout_EAX;
        }
      }
      uVar2 = uVar2 + 1;
      pvStack_38 = (void *)0x0;
      iStack_34 = 0;
      uStack_30 = 0;
      uStack_48 = uVar2;
      uVar7 = FUN_00411430();
    } while (uVar2 < uVar7);
  }
  uVar4 = (**(code **)(*param_1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar4;
  *(undefined4 *)(in_ECX + 0x34) = 2;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  (**(code **)*param_1)(1);
  if (pvStack_2c == (void *)0x0) {
    ExceptionList = pvStack_10;
    return 1;
  }
  _free(pvStack_2c);
  return extraout_EAX_01;
}


// ==== FUN_004b9150 @ 0x004b9150 ====

int FUN_004b9150(int param_1,int param_2,undefined4 param_3)

{
  FUN_00429bc0(param_1,param_2,param_3);
  return param_1 + param_2 * 8;
}


// ==== FUN_004b9180 @ 0x004b9180 ====

void FUN_004b9180(void)

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
  puStack_8 = &LAB_009800e8;
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


// ==== FUN_004b91f0 @ 0x004b91f0 ====

/* WARNING: Removing unreachable block (ram,0x004b9303) */
/* WARNING: Removing unreachable block (ram,0x004b9313) */
/* WARNING: Removing unreachable block (ram,0x004b931c) */
/* WARNING: Removing unreachable block (ram,0x004b931f) */
/* WARNING: Removing unreachable block (ram,0x004b930f) */
/* WARNING: Removing unreachable block (ram,0x004b932d) */
/* WARNING: Removing unreachable block (ram,0x004b933a) */
/* WARNING: Removing unreachable block (ram,0x004b9345) */
/* WARNING: Removing unreachable block (ram,0x004b9341) */
/* WARNING: Removing unreachable block (ram,0x004b9335) */
/* WARNING: Removing unreachable block (ram,0x004b9348) */

void FUN_004b91f0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_009800e8;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x19) != '\0') {
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
  FUN_00832d10();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x19) == '\0') {
    if (*(char *)(param_2[2] + 0x19) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x19) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x19) == '\0') {
      piVar3 = (int *)FUN_00894550(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x19) == '\0') {
      uVar4 = FUN_00832cf0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[6] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[6] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[6] == '\0') {
            *(undefined1 *)(piVar5 + 6) = 1;
            *(undefined1 *)(piVar3 + 6) = 0;
            FUN_0058b7a0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x19) == '\0') {
            if ((*(char *)(*piVar5 + 0x18) == '\x01') && (*(char *)(piVar5[2] + 0x18) == '\x01'))
            goto LAB_004b9415;
            if (*(char *)(piVar5[2] + 0x18) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x18) = 1;
              *(undefined1 *)(piVar5 + 6) = 0;
              FUN_004b8340(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 6) = (char)piVar3[6];
            *(undefined1 *)(piVar3 + 6) = 1;
            *(undefined1 *)(piVar5[2] + 0x18) = 1;
            FUN_0058b7a0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[6] == '\0') {
            *(undefined1 *)(piVar5 + 6) = 1;
            *(undefined1 *)(piVar3 + 6) = 0;
            FUN_004b8340(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x19) == '\0') {
            if ((*(char *)(piVar5[2] + 0x18) != '\x01') || (*(char *)(*piVar5 + 0x18) != '\x01')) {
              if (*(char *)(*piVar5 + 0x18) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x18) = 1;
                *(undefined1 *)(piVar5 + 6) = 0;
                FUN_0058b7a0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 6) = (char)piVar3[6];
              *(undefined1 *)(piVar3 + 6) = 1;
              *(undefined1 *)(*piVar5 + 0x18) = 1;
              FUN_004b8340(piVar3);
              break;
            }
LAB_004b9415:
            *(undefined1 *)(piVar5 + 6) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 6) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_004b94a0 @ 0x004b94a0 ====

void FUN_004b94a0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_009800e8;
  local_c = ExceptionList;
  if (0x15555553 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_0058b8c0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[6] == '\0') {
LAB_004b9599:
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
      if ((char)piVar6[6] == '\0') goto LAB_004b9599;
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


// ==== FUN_004b9680 @ 0x004b9680 ====

void FUN_004b9680(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004b8400(piVar6[1]);
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
    FUN_004b91f0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004b9740 @ 0x004b9740 ====

void FUN_004b9740(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  int extraout_ECX;
  int iVar6;
  int iVar7;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980100;
  local_10 = ExceptionList;
  local_1c = param_3[1];
  local_20 = *param_3;
  iVar3 = *(int *)(in_ECX + 4);
  local_14 = (undefined1 *)((int)register0x00000010 + -0x2c);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(in_ECX + 0xc) - iVar3 >> 3;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 3;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x2c);
    if (0x1fffffffU - iVar6 < param_2) {
      ExceptionList = &local_10;
      uVar2 = FUN_004b9180();
      iVar3 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 3;
    }
    if (uVar2 < iVar6 + param_2) {
      if (0x1fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar3 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 3;
      }
      if (uVar2 < iVar6 + param_2) {
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(in_ECX + 8) - iVar3 >> 3;
        }
        uVar2 = iVar3 + param_2;
      }
      pvVar4 = operator_new(uVar2 * 8);
      local_8 = 0;
      local_18 = pvVar4;
      iVar3 = FUN_00751a10(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      FUN_00429bc0(iVar3,param_2,&local_20);
      FUN_00751a10(param_1,*(undefined4 *)(in_ECX + 8),iVar3 + param_2 * 8);
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 8) - (int)_Memory >> 3;
      }
      if (_Memory == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 8 + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (param_2 + iVar3) * 8);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar6 = *(int *)(in_ECX + 8);
    iVar3 = param_2 * 8;
    if ((uint)(iVar6 - param_1 >> 3) < param_2) {
      FUN_00751a10(param_1,iVar6,iVar3 + param_1);
      local_8 = 2;
      FUN_004b9150(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 3),&local_20);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar3;
      FUN_00686630(param_1,*(int *)(in_ECX + 8) + param_2 * -8,&local_20);
      ExceptionList = local_10;
      return;
    }
    iVar7 = iVar6 + param_2 * -8;
    uVar5 = FUN_00751a10(iVar7,iVar6,iVar6);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_00576790(param_1,iVar7,iVar6);
    FUN_00686630(param_1,iVar3 + param_1,&local_20);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004b98b1 @ 0x004b98b1 ====

void Catch_004b98b1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004b9990 @ 0x004b9990 ====

void FUN_004b9990(undefined4 *param_1,int *param_2)

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
      if ((*param_2 < (int)puVar4[3]) && (param_2[1] <= (int)puVar4[4])) {
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
      goto LAB_004b99ee;
    }
    FUN_004b83a0();
  }
  if ((*piVar2 <= param_2[3]) || (piVar2[1] < param_2[4])) {
    *param_1 = param_2;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_004b99ee:
  puVar4 = (undefined4 *)FUN_004b94a0(&param_2,local_4,puVar4,piVar2);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_004b9a50 @ 0x004b9a50 ====

void FUN_004b9a50(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004b9680(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004b9a80 @ 0x004b9a80 ====

void FUN_004b9a80(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined1 local_14 [8];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(in_ECX + 0x10) = param_2;
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  FUN_004b8400(*(undefined4 *)(*(int *)(in_ECX + 4) + 4));
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  puVar1 = *(undefined4 **)(param_3 + 4);
  puVar2 = *(undefined4 **)(param_3 + 8);
  *(undefined4 *)(in_ECX + 0x14) = puVar1[1];
  while (puVar1 != puVar2) {
    local_c = *puVar1;
    puVar3 = puVar1 + 2;
    if (puVar3 == puVar2) {
      local_8 = 10000000;
    }
    else {
      local_8 = *puVar3;
    }
    local_4 = puVar1[1];
    FUN_004b9990(local_14,&local_c);
    puVar1 = puVar3;
  }
  return;
}


// ==== FUN_004b9b20 @ 0x004b9b20 ====

void FUN_004b9b20(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_004b4f00(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_004b9b70 @ 0x004b9b70 ====

void FUN_004b9b70(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 3) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 3))) {
    FUN_004b9740(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00429bc0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 8;
  return;
}


// ==== FUN_004b9be0 @ 0x004b9be0 ====

void FUN_004b9be0(byte param_1)

{
  void *in_ECX;
  
  FUN_004b8850();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004b9c10 @ 0x004b9c10 ====

int FUN_004b9c10(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 100) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0x68) - *(int *)(in_ECX + 100) >> 2;
}


// ==== FUN_004b9c30 @ 0x004b9c30 ====

void FUN_004b9c30(void)

{
  float *pfVar1;
  float *pfVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  undefined4 uVar5;
  float fVar6;
  
  if ((*(int *)(in_ECX + 100) == 0) || (*(int *)(in_ECX + 0x68) - *(int *)(in_ECX + 100) >> 2 == 0))
  {
    *(undefined4 *)(in_ECX + 0x70) = 0;
    *(undefined4 *)(in_ECX + 0x74) = 0;
    *(undefined4 *)(in_ECX + 0x78) = 0;
    *(undefined4 *)(in_ECX + 0x7c) = 0;
    *(undefined4 *)(in_ECX + 0x80) = 0;
    *(undefined4 *)(in_ECX + 0x84) = 0;
    return;
  }
  piVar3 = *(int **)(in_ECX + 100);
  iVar4 = *piVar3;
  pfVar1 = (float *)(in_ECX + 0x70);
  *pfVar1 = *(float *)(iVar4 + 0x10);
  *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(iVar4 + 0x14);
  *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(iVar4 + 0x18);
  pfVar2 = (float *)(in_ECX + 0x7c);
  *pfVar2 = *(float *)(iVar4 + 0x1c);
  *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(iVar4 + 0x20);
  *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(iVar4 + 0x24);
  while (piVar3 = piVar3 + 1, piVar3 != *(int **)(in_ECX + 0x68)) {
    iVar4 = *piVar3;
    if (*(float *)(iVar4 + 0x10) < *pfVar1 || *(float *)(iVar4 + 0x10) == *pfVar1) {
      fVar6 = *(float *)(iVar4 + 0x10);
    }
    else {
      fVar6 = *pfVar1;
    }
    *pfVar1 = fVar6;
    if (*(float *)(iVar4 + 0x14) < *(float *)(in_ECX + 0x74) ||
        *(float *)(iVar4 + 0x14) == *(float *)(in_ECX + 0x74)) {
      uVar5 = *(undefined4 *)(iVar4 + 0x14);
    }
    else {
      uVar5 = *(undefined4 *)(in_ECX + 0x74);
    }
    *(undefined4 *)(in_ECX + 0x74) = uVar5;
    if (*(float *)(iVar4 + 0x18) < *(float *)(in_ECX + 0x78) ||
        *(float *)(iVar4 + 0x18) == *(float *)(in_ECX + 0x78)) {
      uVar5 = *(undefined4 *)(iVar4 + 0x18);
    }
    else {
      uVar5 = *(undefined4 *)(in_ECX + 0x78);
    }
    *(undefined4 *)(in_ECX + 0x78) = uVar5;
    fVar6 = *pfVar2;
    if (fVar6 < *(float *)(iVar4 + 0x1c) || fVar6 == *(float *)(iVar4 + 0x1c)) {
      fVar6 = *(float *)(iVar4 + 0x1c);
    }
    *pfVar2 = fVar6;
    fVar6 = *(float *)(in_ECX + 0x80);
    if (fVar6 < *(float *)(iVar4 + 0x20) || fVar6 == *(float *)(iVar4 + 0x20)) {
      fVar6 = *(float *)(iVar4 + 0x20);
    }
    *(float *)(in_ECX + 0x80) = fVar6;
    fVar6 = *(float *)(in_ECX + 0x84);
    if (fVar6 < *(float *)(iVar4 + 0x24) || fVar6 == *(float *)(iVar4 + 0x24)) {
      fVar6 = *(float *)(iVar4 + 0x24);
    }
    *(float *)(in_ECX + 0x84) = fVar6;
  }
  return;
}


// ==== FUN_004b9ca0 @ 0x004b9ca0 ====

void FUN_004b9ca0(void)

{
  float *pfVar1;
  float *pfVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  undefined4 uVar5;
  float fVar6;
  
  piVar3 = *(int **)(in_ECX + 100);
  iVar4 = *piVar3;
  pfVar1 = (float *)(in_ECX + 0x70);
  *pfVar1 = *(float *)(iVar4 + 0x10);
  *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(iVar4 + 0x14);
  *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(iVar4 + 0x18);
  pfVar2 = (float *)(in_ECX + 0x7c);
  *pfVar2 = *(float *)(iVar4 + 0x1c);
  *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(iVar4 + 0x20);
  *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(iVar4 + 0x24);
  while (piVar3 = piVar3 + 1, piVar3 != *(int **)(in_ECX + 0x68)) {
    iVar4 = *piVar3;
    if (*(float *)(iVar4 + 0x10) < *pfVar1 || *(float *)(iVar4 + 0x10) == *pfVar1) {
      fVar6 = *(float *)(iVar4 + 0x10);
    }
    else {
      fVar6 = *pfVar1;
    }
    *pfVar1 = fVar6;
    if (*(float *)(iVar4 + 0x14) < *(float *)(in_ECX + 0x74) ||
        *(float *)(iVar4 + 0x14) == *(float *)(in_ECX + 0x74)) {
      uVar5 = *(undefined4 *)(iVar4 + 0x14);
    }
    else {
      uVar5 = *(undefined4 *)(in_ECX + 0x74);
    }
    *(undefined4 *)(in_ECX + 0x74) = uVar5;
    if (*(float *)(iVar4 + 0x18) < *(float *)(in_ECX + 0x78) ||
        *(float *)(iVar4 + 0x18) == *(float *)(in_ECX + 0x78)) {
      uVar5 = *(undefined4 *)(iVar4 + 0x18);
    }
    else {
      uVar5 = *(undefined4 *)(in_ECX + 0x78);
    }
    *(undefined4 *)(in_ECX + 0x78) = uVar5;
    fVar6 = *pfVar2;
    if (fVar6 < *(float *)(iVar4 + 0x1c) || fVar6 == *(float *)(iVar4 + 0x1c)) {
      fVar6 = *(float *)(iVar4 + 0x1c);
    }
    *pfVar2 = fVar6;
    fVar6 = *(float *)(in_ECX + 0x80);
    if (fVar6 < *(float *)(iVar4 + 0x20) || fVar6 == *(float *)(iVar4 + 0x20)) {
      fVar6 = *(float *)(iVar4 + 0x20);
    }
    *(float *)(in_ECX + 0x80) = fVar6;
    fVar6 = *(float *)(in_ECX + 0x84);
    if (fVar6 < *(float *)(iVar4 + 0x24) || fVar6 == *(float *)(iVar4 + 0x24)) {
      fVar6 = *(float *)(iVar4 + 0x24);
    }
    *(float *)(in_ECX + 0x84) = fVar6;
  }
  return;
}


// ==== FUN_004b9df0 @ 0x004b9df0 ====

undefined4 FUN_004b9df0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x44) != 0) {
    FUN_0069a470(&param_1,param_1);
    if (param_1 != *(int *)(in_ECX + 0x40)) {
      return *(undefined4 *)(param_1 + 0x28);
    }
  }
  return 0;
}


// ==== FUN_004b9e30 @ 0x004b9e30 ====

undefined4 FUN_004b9e30(int param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x50) != 0) {
    FUN_0069a470(&param_1,param_1);
    if (param_1 != *(int *)(in_ECX + 0x4c)) {
      return *(undefined4 *)(param_1 + 0x28);
    }
  }
  return 0;
}


// ==== FUN_004b9e70 @ 0x004b9e70 ====

undefined4 FUN_004b9e70(int param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_0069a470(&param_1,param_1);
    if (param_1 != *(int *)(in_ECX + 0x58)) {
      return *(undefined4 *)(param_1 + 0x28);
    }
  }
  return 0;
}


// ==== FUN_004b9eb0 @ 0x004b9eb0 ====

undefined4 FUN_004b9eb0(int param_1)

{
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009801a8;
  local_c = ExceptionList;
  if (param_1 == 0) {
    return 4;
  }
  if (param_1 == 1) {
    return 5;
  }
  if (param_1 != 2) {
    ExceptionList = &local_c;
    FUN_00401830(&DAT_009b02f4);
    local_4 = 0;
    FUN_00406880(local_28);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  return 6;
}


// ==== FUN_004b9f60 @ 0x004b9f60 ====

int FUN_004b9f60(int param_1,int param_2)

{
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009801ba;
  local_c = ExceptionList;
  if (param_1 == 4) {
    return param_2 / 3;
  }
  if ((param_1 != 5) && (param_1 != 6)) {
    ExceptionList = &local_c;
    FUN_00401830(&DAT_009b02f8);
    local_4 = 0;
    FUN_00406880(local_28);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  return param_2 + -2;
}


// ==== FUN_004ba010 @ 0x004ba010 ====

undefined4 FUN_004ba010(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 100);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x68) - iVar1 >> 2) <= param_1)) {
    return 0;
  }
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x68) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_004bb6a0();
  }
  return *(undefined4 *)(iVar1 + param_1 * 4);
}


// ==== FUN_004ba050 @ 0x004ba050 ====

void FUN_004ba050(int param_1)

{
  int iVar1;
  short *psVar2;
  int *piVar3;
  int iVar4;
  short sVar5;
  int in_ECX;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  short *psVar6;
  short *extraout_ECX;
  float *pfVar7;
  short sVar8;
  float *pfVar9;
  undefined2 uVar11;
  uint uVar10;
  float fVar12;
  float *pfStack_8e;
  bool bStack_89;
  undefined4 uStack_88;
  int iStack_84;
  int local_80;
  float *pfStack_7c;
  float *local_78;
  float local_74;
  float local_70;
  float local_6c;
  float *local_68;
  float *pfStack_64;
  int *local_60;
  int local_5c;
  int *local_58;
  int iStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
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
  
  FUN_00401660(in_ECX + 4,0,0xffffffff);
  local_78 = (float *)(param_1 + 0x1c);
  *local_78 = 0.0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  local_68 = (float *)(param_1 + 0x28);
  local_74 = 0.0;
  *local_68 = 0.0;
  local_70 = 0.0;
  local_6c = 0.0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  local_5c = param_1 + 0x34;
  *(undefined4 *)(param_1 + 0x30) = 0;
  if (*(void **)(param_1 + 0x38) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x38));
    return;
  }
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  if (*(void **)(param_1 + 0x48) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x48));
    return;
  }
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  if (*(void **)(param_1 + 0x58) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x58));
    return;
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  fVar12 = DAT_0099d0f0;
  if ((*(int *)(in_ECX + 100) != 0) && (*(int *)(in_ECX + 0x68) - *(int *)(in_ECX + 100) >> 2 != 0))
  {
    *local_78 = DAT_0099d0f0;
    *(float *)(param_1 + 0x20) = fVar12;
    local_74 = DAT_0099d0e8;
    *(float *)(param_1 + 0x24) = fVar12;
    *local_68 = local_74;
    local_70 = local_74;
    *(float *)(param_1 + 0x2c) = local_74;
    local_6c = local_74;
    *(float *)(param_1 + 0x30) = local_74;
    local_60 = *(int **)(in_ECX + 100);
    local_58 = *(int **)(in_ECX + 0x68);
    if (local_60 != local_58) {
      do {
        iVar1 = *local_60;
        if (*(int *)(local_5c + 4) == 0) {
          local_80 = 0;
        }
        else {
          local_80 = (*(int *)(local_5c + 8) - *(int *)(local_5c + 4)) / 0x28;
        }
        piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
        iVar4 = (**(code **)(*piVar3 + 0x1c))();
        if (*(int *)(iVar4 + 8) == 0) {
          pfVar7 = *(float **)(iVar1 + 0x40);
          for (pfVar9 = *(float **)(iVar1 + 0x3c); pfVar9 != pfVar7; pfVar9 = pfVar9 + 0xe) {
            fStack_10 = pfVar9[10];
            fStack_28 = *pfVar9;
            fStack_24 = pfVar9[1];
            fStack_20 = pfVar9[2];
            fStack_1c = pfVar9[3];
            fStack_c = pfVar9[0xb];
            fStack_18 = pfVar9[4];
            fStack_14 = pfVar9[5];
            fStack_8 = pfVar9[0xc];
            fStack_4 = pfVar9[0xd];
            FUN_004bc420(&fStack_28);
            if (*pfVar9 < *local_78 || *pfVar9 == *local_78) {
              fVar12 = *pfVar9;
            }
            else {
              fVar12 = *local_78;
            }
            *local_78 = fVar12;
            if (pfVar9[1] < local_78[1] || pfVar9[1] == local_78[1]) {
              fVar12 = pfVar9[1];
            }
            else {
              fVar12 = local_78[1];
            }
            local_78[1] = fVar12;
            if (pfVar9[2] < local_78[2] || pfVar9[2] == local_78[2]) {
              fVar12 = pfVar9[2];
            }
            else {
              fVar12 = local_78[2];
            }
            local_78[2] = fVar12;
            fVar12 = *local_68;
            if (fVar12 < *pfVar9 || fVar12 == *pfVar9) {
              fVar12 = *pfVar9;
            }
            *local_68 = fVar12;
            fVar12 = local_68[1];
            if (fVar12 < pfVar9[1] || fVar12 == pfVar9[1]) {
              fVar12 = pfVar9[1];
            }
            local_68[1] = fVar12;
            fVar12 = local_68[2];
            if (fVar12 < pfVar9[2] || fVar12 == pfVar9[2]) {
              fVar12 = pfVar9[2];
            }
            local_68[2] = fVar12;
          }
        }
        else {
          pfVar7 = *(float **)(iVar1 + 0x50);
          for (pfVar9 = *(float **)(iVar1 + 0x4c); pfVar9 != pfVar7; pfVar9 = pfVar9 + 0x12) {
            fStack_38 = pfVar9[0xe];
            fStack_50 = *pfVar9;
            fStack_4c = pfVar9[1];
            fStack_48 = pfVar9[2];
            fStack_44 = pfVar9[3];
            fStack_34 = pfVar9[0xf];
            fStack_40 = pfVar9[4];
            fStack_3c = pfVar9[5];
            fStack_30 = pfVar9[0x10];
            fStack_2c = pfVar9[0x11];
            FUN_004bc420(&fStack_50);
            if (*pfVar9 < *local_78 || *pfVar9 == *local_78) {
              fVar12 = *pfVar9;
            }
            else {
              fVar12 = *local_78;
            }
            *local_78 = fVar12;
            if (pfVar9[1] < local_78[1] || pfVar9[1] == local_78[1]) {
              fVar12 = pfVar9[1];
            }
            else {
              fVar12 = local_78[1];
            }
            local_78[1] = fVar12;
            if (pfVar9[2] < local_78[2] || pfVar9[2] == local_78[2]) {
              fVar12 = pfVar9[2];
            }
            else {
              fVar12 = local_78[2];
            }
            local_78[2] = fVar12;
            fVar12 = *local_68;
            if (fVar12 < *pfVar9 || fVar12 == *pfVar9) {
              fVar12 = *pfVar9;
            }
            *local_68 = fVar12;
            fVar12 = local_68[1];
            if (fVar12 < pfVar9[1] || fVar12 == pfVar9[1]) {
              fVar12 = pfVar9[1];
            }
            local_68[1] = fVar12;
            fVar12 = local_68[2];
            if (fVar12 < pfVar9[2] || fVar12 == pfVar9[2]) {
              fVar12 = pfVar9[2];
            }
            local_68[2] = fVar12;
          }
        }
        iStack_84 = *(int *)(iVar1 + 0x2c);
        iStack_54 = *(int *)(iVar1 + 0x30);
        if (iStack_84 != iStack_54) {
          do {
            iVar1 = *(int *)(iStack_84 + 4);
            if (iVar1 == 4) {
              psVar6 = *(short **)(iStack_84 + 0x18);
              if ((psVar6 != (short *)0x0) &&
                 (2 < (uint)(*(int *)(iStack_84 + 0x1c) - (int)psVar6 >> 1))) {
                pfVar9 = *(float **)(iStack_84 + 0x18);
                pfStack_7c = *(float **)(iStack_84 + 0x1c);
                if (pfVar9 != pfStack_7c) {
                  do {
                    uStack_88._2_2_ = (undefined2)((uint)psVar6 >> 0x10);
                    uStack_88._0_2_ = *(short *)pfVar9 + (short)local_80;
                    iVar1 = *(int *)(param_1 + 0x48);
                    if ((iVar1 == 0) ||
                       ((uint)(*(int *)(param_1 + 0x50) - iVar1 >> 1) <=
                        (uint)(*(int *)(param_1 + 0x4c) - iVar1 >> 1))) {
                      FUN_00427290(*(undefined4 *)(param_1 + 0x4c),1,&uStack_88);
                      uStack_88._2_2_ = extraout_var;
                    }
                    else {
                      psVar6 = *(short **)(param_1 + 0x4c);
                      *psVar6 = (short)uStack_88;
                      *(short **)(param_1 + 0x4c) = psVar6 + 1;
                    }
                    iVar1 = *(int *)(param_1 + 0x48);
                    sVar5 = (short)local_80;
                    uStack_88._0_2_ = *(short *)((int)pfVar9 + 2) + sVar5;
                    if ((iVar1 == 0) ||
                       ((uint)(*(int *)(param_1 + 0x50) - iVar1 >> 1) <=
                        (uint)(*(int *)(param_1 + 0x4c) - iVar1 >> 1))) {
                      FUN_00427290(*(undefined4 *)(param_1 + 0x4c),1,&uStack_88);
                      uStack_88._2_2_ = extraout_var_00;
                    }
                    else {
                      psVar6 = *(short **)(param_1 + 0x4c);
                      *psVar6 = (short)uStack_88;
                      *(short **)(param_1 + 0x4c) = psVar6 + 1;
                    }
                    iVar1 = *(int *)(param_1 + 0x48);
                    sVar5 = *(short *)(pfVar9 + 1) + sVar5;
                    psVar6 = (short *)CONCAT22(uStack_88._2_2_,sVar5);
                    pfVar9 = (float *)((int)pfVar9 + 6);
                    uStack_88 = psVar6;
                    if ((iVar1 == 0) ||
                       ((uint)(*(int *)(param_1 + 0x50) - iVar1 >> 1) <=
                        (uint)(*(int *)(param_1 + 0x4c) - iVar1 >> 1))) {
                      FUN_00427290(*(undefined4 *)(param_1 + 0x4c),1,&uStack_88);
                      psVar6 = extraout_ECX;
                    }
                    else {
                      psVar2 = *(short **)(param_1 + 0x4c);
                      *psVar2 = sVar5;
                      *(short **)(param_1 + 0x4c) = psVar2 + 1;
                    }
                  } while (pfVar9 != pfStack_7c);
                }
              }
            }
            else if (iVar1 == 5) {
              if ((*(int *)(iStack_84 + 0x18) != 0) &&
                 (2 < (uint)(*(int *)(iStack_84 + 0x1c) - *(int *)(iStack_84 + 0x18) >> 1))) {
                pfStack_7c = *(float **)(iStack_84 + 0x18);
                pfVar9 = *(float **)(iStack_84 + 0x1c);
                uStack_88 = (short *)((int)pfStack_7c + 2);
                pfVar7 = pfStack_7c + 1;
                bStack_89 = false;
                pfStack_64 = pfVar9;
                if (pfVar7 != pfVar9) {
                  do {
                    uVar11 = (undefined2)((uint)pfVar9 >> 0x10);
                    if (bStack_89 == false) {
                      pfStack_8e = (float *)CONCAT22(uVar11,*(short *)pfStack_7c + (short)local_80);
                      iVar1 = *(int *)(param_1 + 0x48);
                      if ((iVar1 == 0) ||
                         ((uint)(*(int *)(param_1 + 0x50) - iVar1 >> 1) <=
                          (uint)(*(int *)(param_1 + 0x4c) - iVar1 >> 1))) {
                        FUN_00427290(*(undefined4 *)(param_1 + 0x4c),1,&pfStack_8e);
                      }
                      else {
                        psVar6 = *(short **)(param_1 + 0x4c);
                        *psVar6 = *(short *)pfStack_7c + (short)local_80;
                        *(short **)(param_1 + 0x4c) = psVar6 + 1;
                      }
                      iVar1 = *(int *)(param_1 + 0x48);
                      sVar5 = (short)local_80;
                      sVar8 = *uStack_88 + sVar5;
                      pfStack_8e = (float *)CONCAT22(uVar11,sVar8);
                      if ((iVar1 == 0) ||
                         ((uint)(*(int *)(param_1 + 0x50) - iVar1 >> 1) <=
                          (uint)(*(int *)(param_1 + 0x4c) - iVar1 >> 1))) {
                        FUN_00427290(*(undefined4 *)(param_1 + 0x4c),1,&pfStack_8e);
                      }
                      else {
                        psVar6 = *(short **)(param_1 + 0x4c);
                        *psVar6 = sVar8;
                        *(short **)(param_1 + 0x4c) = psVar6 + 1;
                      }
                      iVar1 = *(int *)(param_1 + 0x48);
                      sVar5 = *(short *)pfVar7 + sVar5;
                      pfVar9 = (float *)CONCAT22(uVar11,sVar5);
                      pfStack_8e = pfVar9;
                      if ((iVar1 == 0) ||
                         ((uint)(*(int *)(param_1 + 0x50) - iVar1 >> 1) <=
                          (uint)(*(int *)(param_1 + 0x4c) - iVar1 >> 1))) goto LAB_004ba7f3;
                      psVar6 = *(short **)(param_1 + 0x4c);
                      *psVar6 = sVar5;
                      *(short **)(param_1 + 0x4c) = psVar6 + 1;
                    }
                    else {
                      pfStack_8e = (float *)CONCAT22(uVar11,*(short *)pfVar7 + (short)local_80);
                      iVar1 = *(int *)(param_1 + 0x48);
                      if ((iVar1 == 0) ||
                         ((uint)(*(int *)(param_1 + 0x50) - iVar1 >> 1) <=
                          (uint)(*(int *)(param_1 + 0x4c) - iVar1 >> 1))) {
                        FUN_00427290(*(undefined4 *)(param_1 + 0x4c),1,&pfStack_8e);
                      }
                      else {
                        psVar6 = *(short **)(param_1 + 0x4c);
                        *psVar6 = *(short *)pfVar7 + (short)local_80;
                        *(short **)(param_1 + 0x4c) = psVar6 + 1;
                      }
                      iVar1 = *(int *)(param_1 + 0x48);
                      sVar5 = (short)local_80;
                      sVar8 = *uStack_88 + sVar5;
                      pfStack_8e = (float *)CONCAT22(uVar11,sVar8);
                      if ((iVar1 == 0) ||
                         ((uint)(*(int *)(param_1 + 0x50) - iVar1 >> 1) <=
                          (uint)(*(int *)(param_1 + 0x4c) - iVar1 >> 1))) {
                        FUN_00427290(*(undefined4 *)(param_1 + 0x4c),1,&pfStack_8e);
                      }
                      else {
                        psVar6 = *(short **)(param_1 + 0x4c);
                        *psVar6 = sVar8;
                        *(short **)(param_1 + 0x4c) = psVar6 + 1;
                      }
                      iVar1 = *(int *)(param_1 + 0x48);
                      sVar5 = *(short *)pfStack_7c + sVar5;
                      pfVar9 = (float *)CONCAT22(uVar11,sVar5);
                      pfStack_8e = pfVar9;
                      if ((iVar1 == 0) ||
                         ((uint)(*(int *)(param_1 + 0x50) - iVar1 >> 1) <=
                          (uint)(*(int *)(param_1 + 0x4c) - iVar1 >> 1))) {
LAB_004ba7f3:
                        pfVar9 = pfStack_8e;
                        FUN_00427290(*(undefined4 *)(param_1 + 0x4c),1,&pfStack_8e);
                      }
                      else {
                        psVar6 = *(short **)(param_1 + 0x4c);
                        *psVar6 = sVar5;
                        *(short **)(param_1 + 0x4c) = psVar6 + 1;
                      }
                    }
                    bStack_89 = bStack_89 == false;
                    pfStack_7c = (float *)((int)pfStack_7c + 2);
                    uStack_88 = uStack_88 + 1;
                    pfVar7 = (float *)((int)pfVar7 + 2);
                  } while (pfVar7 != pfStack_64);
                }
              }
            }
            else if (((iVar1 == 6) && (*(int *)(iStack_84 + 0x18) != 0)) &&
                    (2 < (uint)(*(int *)(iStack_84 + 0x1c) - *(int *)(iStack_84 + 0x18) >> 1))) {
              pfStack_64 = *(float **)(iStack_84 + 0x18);
              pfStack_7c = *(float **)(iStack_84 + 0x1c);
              pfVar7 = pfStack_64 + 1;
              if (pfVar7 != pfStack_7c) {
                uStack_88 = (short *)((int)pfStack_64 + (2 - (int)pfVar7));
                do {
                  pfStack_8e = (float *)CONCAT22((short)((uint)pfVar9 >> 0x10),
                                                 *(short *)pfStack_64 + (short)local_80);
                  iVar1 = *(int *)(param_1 + 0x48);
                  if ((iVar1 == 0) ||
                     ((uint)(*(int *)(param_1 + 0x50) - iVar1 >> 1) <=
                      (uint)(*(int *)(param_1 + 0x4c) - iVar1 >> 1))) {
                    FUN_00427290(*(undefined4 *)(param_1 + 0x4c),1,&pfStack_8e);
                  }
                  else {
                    psVar6 = *(short **)(param_1 + 0x4c);
                    *psVar6 = *(short *)pfStack_64 + (short)local_80;
                    *(short **)(param_1 + 0x4c) = psVar6 + 1;
                  }
                  iVar1 = *(int *)(param_1 + 0x48);
                  sVar8 = (short)local_80;
                  sVar5 = *(short *)((int)uStack_88 + (int)pfVar7) + sVar8;
                  pfStack_8e = (float *)CONCAT22((short)((uint)uStack_88 >> 0x10),sVar5);
                  if (iVar1 == 0) {
                    uVar10 = 0;
LAB_004ba90f:
                    FUN_00427290(*(undefined4 *)(param_1 + 0x4c),1,&pfStack_8e);
                  }
                  else {
                    uVar10 = *(int *)(param_1 + 0x4c) - iVar1 >> 1;
                    if ((uint)(*(int *)(param_1 + 0x50) - iVar1 >> 1) <= uVar10) goto LAB_004ba90f;
                    psVar6 = *(short **)(param_1 + 0x4c);
                    *psVar6 = sVar5;
                    *(short **)(param_1 + 0x4c) = psVar6 + 1;
                  }
                  iVar1 = *(int *)(param_1 + 0x48);
                  sVar8 = *(short *)pfVar7 + sVar8;
                  pfVar9 = (float *)CONCAT22((short)(uVar10 >> 0x10),sVar8);
                  pfStack_8e = pfVar9;
                  if ((iVar1 == 0) ||
                     ((uint)(*(int *)(param_1 + 0x50) - iVar1 >> 1) <=
                      (uint)(*(int *)(param_1 + 0x4c) - iVar1 >> 1))) {
                    FUN_00427290(*(undefined4 *)(param_1 + 0x4c),1,&pfStack_8e);
                  }
                  else {
                    psVar6 = *(short **)(param_1 + 0x4c);
                    *psVar6 = sVar8;
                    *(short **)(param_1 + 0x4c) = psVar6 + 1;
                  }
                  pfVar7 = (float *)((int)pfVar7 + 2);
                } while (pfVar7 != pfStack_7c);
              }
            }
            iStack_84 = iStack_84 + 0x24;
          } while (iStack_84 != iStack_54);
        }
        local_60 = local_60 + 1;
      } while (local_60 != local_58);
    }
  }
  return;
}


// ==== FUN_004ba9c0 @ 0x004ba9c0 ====

void FUN_004ba9c0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_1;
  if (*(void **)(param_1 + 4) != (void *)0x0) {
    _free(*(void **)(param_1 + 4));
    return;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  iVar1 = *(int *)(param_2 + 8);
  for (iVar5 = *(int *)(param_2 + 4); iVar5 != iVar1; iVar5 = iVar5 + 0x1c) {
    param_1 = (**(code **)(*DAT_00b5a7e4 + 4))(iVar5);
    iVar2 = *(int *)(iVar4 + 4);
    if ((iVar2 == 0) ||
       ((uint)(*(int *)(iVar4 + 0xc) - iVar2 >> 2) <= (uint)(*(int *)(iVar4 + 8) - iVar2 >> 2))) {
      FUN_0042f3e0(*(undefined4 *)(iVar4 + 8),1,&param_1);
    }
    else {
      piVar3 = *(int **)(iVar4 + 8);
      *piVar3 = param_1;
      *(int **)(iVar4 + 8) = piVar3 + 1;
    }
  }
  return;
}


// ==== FUN_004baa60 @ 0x004baa60 ====

void FUN_004baa60(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009801d7;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0xffffffff;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  local_4 = 0;
  *in_ECX = &PTR_FUN_009b0320;
  FUN_004bd5e0();
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004baaf0 @ 0x004baaf0 ====

void FUN_004baaf0(void)

{
  int *piVar1;
  int iVar2;
  void *_Memory;
  int *piVar3;
  undefined4 *in_ECX;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puStack_28;
  undefined4 *apuStack_24 [2];
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 *puStack_14;
  int iStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00980213;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009b0320;
  local_4 = 1;
  puStack_28 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puStack_28 == (undefined4 *)0x0) {
    puStack_28 = (undefined4 *)0x0;
  }
  else {
    *puStack_28 = &PTR_FUN_009b0308;
    puStack_28[2] = 0;
    puStack_28[3] = 0;
    puStack_28[4] = 0;
  }
  pvStack_18 = (void *)0x0;
  puStack_14 = (undefined4 *)0x0;
  iStack_10 = 0;
  iVar4 = in_ECX[0x19];
  iVar2 = in_ECX[0x1a];
  local_4 = CONCAT31(local_4._1_3_,4);
  if (iVar4 != iVar2) {
    apuStack_24[0] = in_ECX;
    do {
      if ((pvStack_18 == (void *)0x0) ||
         ((uint)(iStack_10 - (int)pvStack_18 >> 2) <= (uint)((int)puStack_14 - (int)pvStack_18 >> 2)
         )) {
        FUN_0042f3e0(puStack_14,1,apuStack_24);
      }
      else {
        *puStack_14 = in_ECX;
        puStack_14 = puStack_14 + 1;
      }
      iVar4 = iVar4 + 4;
    } while (iVar4 != iVar2);
  }
  FUN_00430ad0(auStack_1c);
  FUN_00797a20(puStack_28);
  if (in_ECX[0x11] != 0) {
    apuStack_24[0] = (undefined4 *)((uint)apuStack_24[0] & 0xffffff00);
    FUN_004bbd50(*(undefined4 *)in_ECX[0x10],(undefined4 *)in_ECX[0x10],apuStack_24[0]);
    FUN_004bc220(*(undefined4 *)(in_ECX[0x10] + 4));
    *(undefined4 *)(in_ECX[0x10] + 4) = in_ECX[0x10];
    in_ECX[0x11] = 0;
    *(undefined4 *)in_ECX[0x10] = in_ECX[0x10];
    *(undefined4 *)(in_ECX[0x10] + 8) = in_ECX[0x10];
  }
  if (in_ECX[0x14] != 0) {
    apuStack_24[0] = (undefined4 *)((uint)apuStack_24[0] & 0xffffff00);
    FUN_004bd560(*(undefined4 *)in_ECX[0x13],(undefined4 *)in_ECX[0x13],apuStack_24[0]);
    FUN_004bc260(*(undefined4 *)(in_ECX[0x13] + 4));
    *(undefined4 *)(in_ECX[0x13] + 4) = in_ECX[0x13];
    in_ECX[0x14] = 0;
    *(undefined4 *)in_ECX[0x13] = in_ECX[0x13];
    *(undefined4 *)(in_ECX[0x13] + 8) = in_ECX[0x13];
  }
  if (in_ECX[0x17] != 0) {
    apuStack_24[0] = (undefined4 *)((uint)apuStack_24[0] & 0xffffff00);
    FUN_004bbdd0(*(undefined4 *)in_ECX[0x16],(undefined4 *)in_ECX[0x16],apuStack_24[0]);
    FUN_004bc2a0(*(undefined4 *)(in_ECX[0x16] + 4));
    *(undefined4 *)(in_ECX[0x16] + 4) = in_ECX[0x16];
    in_ECX[0x17] = 0;
    *(undefined4 *)in_ECX[0x16] = in_ECX[0x16];
    *(undefined4 *)(in_ECX[0x16] + 8) = in_ECX[0x16];
  }
  puVar6 = (undefined4 *)in_ECX[0x19];
  if ((puVar6 != (undefined4 *)0x0) &&
     (apuStack_24[0] = (undefined4 *)in_ECX[0x1a], (int)apuStack_24[0] - (int)puVar6 >> 2 != 0)) {
    for (; puVar6 != apuStack_24[0]; puVar6 = puVar6 + 1) {
      _Memory = (void *)*puVar6;
      if (_Memory != (void *)0x0) {
        if (*(void **)((int)_Memory + 0x5c) != (void *)0x0) {
          _free(*(void **)((int)_Memory + 0x5c));
          return;
        }
        *(undefined4 *)((int)_Memory + 0x5c) = 0;
        *(undefined4 *)((int)_Memory + 0x60) = 0;
        *(undefined4 *)((int)_Memory + 100) = 0;
        if (*(void **)((int)_Memory + 0x4c) != (void *)0x0) {
          _free(*(void **)((int)_Memory + 0x4c));
          return;
        }
        *(undefined4 *)((int)_Memory + 0x4c) = 0;
        *(undefined4 *)((int)_Memory + 0x50) = 0;
        *(undefined4 *)((int)_Memory + 0x54) = 0;
        if (*(void **)((int)_Memory + 0x3c) != (void *)0x0) {
          _free(*(void **)((int)_Memory + 0x3c));
          return;
        }
        *(undefined4 *)((int)_Memory + 0x3c) = 0;
        *(undefined4 *)((int)_Memory + 0x40) = 0;
        *(undefined4 *)((int)_Memory + 0x44) = 0;
        piVar5 = *(int **)((int)_Memory + 0x2c);
        if (piVar5 == (int *)0x0) {
          *(undefined4 *)((int)_Memory + 0x2c) = 0;
          *(undefined4 *)((int)_Memory + 0x30) = 0;
          *(undefined4 *)((int)_Memory + 0x34) = 0;
          _free(_Memory);
          return;
        }
        piVar3 = *(int **)((int)_Memory + 0x30);
        if (piVar5 != piVar3) {
          piVar5 = piVar5 + 6;
          do {
            iVar4 = *piVar5;
            if (iVar4 != 0) {
              FUN_00412910(iVar4,piVar5[2] - iVar4 >> 1);
            }
            *piVar5 = 0;
            piVar5[1] = 0;
            piVar5[2] = 0;
            piVar1 = piVar5 + 3;
            piVar5 = piVar5 + 9;
          } while (piVar1 != piVar3);
        }
        _free(*(void **)((int)_Memory + 0x2c));
        return;
      }
    }
    if ((void *)in_ECX[0x19] != (void *)0x0) {
      _free((void *)in_ECX[0x19]);
      return;
    }
    in_ECX[0x19] = 0;
    in_ECX[0x1a] = 0;
    in_ECX[0x1b] = 0;
  }
  if (pvStack_18 == (void *)0x0) {
    local_4 = local_4 & 0xffffff00;
    FUN_004bd160();
    local_4 = 0xffffffff;
    FUN_0049da30();
    ExceptionList = pvStack_c;
    return;
  }
  _free(pvStack_18);
  return;
}


// ==== FUN_004badf0 @ 0x004badf0 ====

/* WARNING: Removing unreachable block (ram,0x004bb05a) */
/* WARNING: Removing unreachable block (ram,0x004bb165) */
/* WARNING: Removing unreachable block (ram,0x004baf4b) */

undefined4 FUN_004badf0(int *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  undefined4 uVar6;
  int *piVar7;
  int in_ECX;
  uint *puVar8;
  undefined4 *puVar9;
  uint uStack_5c;
  uint uStack_58;
  int iStack_50;
  uint uStack_4c;
  uint uStack_44;
  uint uStack_40;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00980235;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*param_1 + 4))();
  if (iVar3 != 1) {
    ExceptionList = pvStack_c;
    return 0;
  }
  uStack_40 = 0;
  uStack_44 = 0;
  uStack_5c = 0;
  if (param_1[0x1f] != 0) {
    uStack_58 = 0;
    do {
      iVar3 = param_1[0x21];
      if ((iVar3 == 0) || ((uint)((param_1[0x22] - iVar3) / 0x70) <= uStack_5c)) {
                    /* WARNING: Subroutine does not return */
        FUN_00438a40();
      }
      iVar3 = uStack_58 + iVar3;
      iVar4 = FUN_004bc6c0();
      FUN_00401660();
      *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar3 + 0x1c);
      *(undefined4 *)(iVar4 + 0x20) = *(undefined4 *)(iVar3 + 0x20);
      *(undefined4 *)(iVar4 + 0x24) = *(undefined4 *)(iVar3 + 0x24);
      *(undefined4 *)(iVar4 + 0x28) = *(undefined4 *)(iVar3 + 0x28);
      *(undefined4 *)(iVar4 + 0x2c) = *(undefined4 *)(iVar3 + 0x2c);
      *(undefined4 *)(iVar4 + 0x30) = *(undefined4 *)(iVar3 + 0x30);
      FUN_00439620();
      FUN_004394e0();
      FUN_004ba9c0();
      FUN_00401660();
      uStack_4 = 0;
      FUN_004bc940();
      uStack_4 = 0xffffffff;
      uStack_58 = uStack_58 + 0x70;
      uStack_5c = uStack_5c + 1;
    } while (uStack_5c < (uint)param_1[0x1f]);
  }
  uStack_58 = 0;
  if (param_1[0x24] != 0) {
    do {
      if ((param_1[0x26] == 0) || ((uint)((param_1[0x27] - param_1[0x26]) / 0x44) <= uStack_58)) {
                    /* WARNING: Subroutine does not return */
        FUN_00438a40();
      }
      FUN_004bcf60();
      FUN_00401660();
      FUN_0043bce0();
      FUN_004ba9c0();
      FUN_00401660();
      uStack_4 = 1;
      FUN_004bc940();
      uStack_4 = 0xffffffff;
      uStack_58 = uStack_58 + 1;
    } while (uStack_58 < (uint)param_1[0x24]);
  }
  uStack_58 = 0;
  if (param_1[0x29] != 0) {
    do {
      if ((param_1[0x2b] == 0) || ((uint)((param_1[0x2c] - param_1[0x2b]) / 0x44) <= uStack_58)) {
                    /* WARNING: Subroutine does not return */
        FUN_00438a40();
      }
      FUN_004bc770();
      FUN_00401660();
      FUN_00439620();
      FUN_004ba9c0();
      FUN_00401660();
      uStack_4 = 2;
      FUN_004bc940();
      uStack_4 = 0xffffffff;
      uStack_58 = uStack_58 + 1;
    } while (uStack_58 < (uint)param_1[0x29]);
  }
  FUN_004bb960();
  uStack_4c = 0;
  if (param_1[0x2e] != 0) {
    iStack_50 = 0;
    do {
      iVar3 = param_1[0x30];
      if ((iVar3 == 0) || ((uint)((param_1[0x31] - iVar3) / 0x68) <= uStack_4c)) {
                    /* WARNING: Subroutine does not return */
        FUN_00438a40();
      }
      puVar8 = (uint *)(iVar3 + iStack_50);
      puVar5 = (uint *)FUN_004bd010();
      *puVar5 = uStack_4c;
      puVar5[4] = *puVar8;
      puVar5[5] = puVar8[1];
      puVar5[6] = puVar8[2];
      puVar5[7] = puVar8[3];
      puVar5[8] = puVar8[4];
      puVar5[9] = puVar8[5];
      uStack_5c = 0;
      FUN_004bd6d0(puVar8[6]);
      puVar1 = (undefined4 *)puVar8[9];
      puVar9 = (undefined4 *)puVar8[8];
      uStack_58 = 0;
      if (puVar9 != puVar1) {
        iVar3 = 0;
        do {
          uVar2 = puVar5[0xb];
          if ((uVar2 == 0) || ((uint)((int)(puVar5[0xc] - uVar2) / 0x24) <= uStack_58)) {
                    /* WARNING: Subroutine does not return */
            FUN_004bb6a0();
          }
          *(undefined4 *)(uVar2 + iVar3) = *puVar9;
          uVar6 = FUN_004b9eb0();
          *(undefined4 *)(uVar2 + 4 + iVar3) = uVar6;
          *(undefined4 *)(uVar2 + 8 + iVar3) = puVar9[2];
          *(undefined4 *)(uVar2 + 0xc + iVar3) = puVar9[3];
          uStack_5c = uStack_5c + puVar9[4];
          uVar6 = FUN_004b9f60();
          *(undefined4 *)(uVar2 + 0x10 + iVar3) = uVar6;
          FUN_004394e0();
          uStack_58 = uStack_58 + 1;
          puVar9 = puVar9 + 9;
          iVar3 = iVar3 + 0x24;
        } while (puVar9 != puVar1);
      }
      puVar5[0x1a] = uStack_40;
      puVar5[0x1b] = uStack_44;
      uStack_44 = uStack_44 + uStack_5c;
      puVar5[3] = uStack_5c;
      FUN_00439920();
      FUN_00439a90();
      uStack_40 = uStack_40 + puVar8[0xb];
      FUN_004ba9c0();
      puVar5[1] = puVar8[0x19];
      puVar5[2] = 0xffffffff;
      iVar3 = *(int *)(in_ECX + 100);
      if ((iVar3 == 0) ||
         ((uint)(*(int *)(in_ECX + 0x6c) - iVar3 >> 2) <=
          (uint)(*(int *)(in_ECX + 0x68) - iVar3 >> 2))) {
        FUN_004bb780();
      }
      else {
        piVar7 = *(int **)(in_ECX + 0x68);
        *piVar7 = (int)puVar5;
        *(int **)(in_ECX + 0x68) = piVar7 + 1;
      }
      iStack_50 = iStack_50 + 0x68;
      uStack_4c = uStack_4c + 1;
    } while (uStack_4c < (uint)param_1[0x2e]);
  }
  FUN_004b9c30();
  *(uint *)(in_ECX + 0x8c) = uStack_44;
  *(uint *)(in_ECX + 0x88) = uStack_40;
  uVar6 = (**(code **)(*param_1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar6;
  *(undefined4 *)(in_ECX + 0x34) = 2;
  piVar7 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar3 = (**(code **)(*piVar7 + 0x1c))();
  if (*(int *)(iVar3 + 4) == 0) {
    *(int **)(in_ECX + 0x20) = param_1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x20) = 0;
    (**(code **)*param_1)();
  }
  ExceptionList = pvStack_c;
  return 1;
}


// ==== FUN_004bb470 @ 0x004bb470 ====

void FUN_004bb470(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  while (param_1 != param_2) {
    puVar1 = param_1 + 10;
    puVar3 = param_3;
    puVar4 = param_1;
    for (iVar2 = 10; param_1 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


// ==== FUN_004bb4a0 @ 0x004bb4a0 ====

void FUN_004bb4a0(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_2 != 0) {
    do {
      if (param_1 != (undefined4 *)0x0) {
        puVar2 = param_3;
        puVar3 = param_1;
        for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
      }
      param_1 = param_1 + 10;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_004bb4d0 @ 0x004bb4d0 ====

/* WARNING: Removing unreachable block (ram,0x004bb528) */

undefined4 * FUN_004bb4d0(int param_1)

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
  if (*(char *)((int)local_8[1] + 0x2d) == '\0') {
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
LAB_004bb553:
        if (uVar1 <= uVar2) {
          bVar9 = false;
          goto LAB_004bb560;
        }
LAB_004bb562:
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
        if (iVar4 == 0) goto LAB_004bb553;
LAB_004bb560:
        if (bVar9) goto LAB_004bb562;
        puVar6 = (undefined4 *)*puVar5;
        local_8 = puVar5;
      }
      puVar5 = puVar6;
    } while (*(char *)((int)puVar6 + 0x2d) == '\0');
  }
  return local_8;
}


// ==== FUN_004bb590 @ 0x004bb590 ====

int FUN_004bb590(int param_1,int param_2,undefined4 param_3)

{
  FUN_004bb4a0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x28;
}


// ==== FUN_004bb5c0 @ 0x004bb5c0 ====

void FUN_004bb5c0(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x58) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x58));
    return;
  }
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  if (*(void **)(in_ECX + 0x48) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x48));
    return;
  }
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  if (*(void **)(in_ECX + 0x38) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x38));
    return;
  }
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004bb640 @ 0x004bb640 ====

void FUN_004bb640(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x30) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x30));
    return;
  }
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
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


// ==== FUN_004bb6a0 @ 0x004bb6a0 ====

void FUN_004bb6a0(void)

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
  puStack_8 = &LAB_009802b8;
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


// ==== FUN_004bb710 @ 0x004bb710 ====

void FUN_004bb710(void)

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
  puStack_8 = &LAB_009802b8;
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


// ==== FUN_004bb780 @ 0x004bb780 ====

void FUN_004bb780(void *param_1,uint param_2,undefined4 *param_3)

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
      uVar7 = FUN_004bb710();
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


// ==== FUN_004bb960 @ 0x004bb960 ====

void FUN_004bb960(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  uint extraout_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980240;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x3fffffff < param_1) {
    ExceptionList = &local_10;
    FUN_004bb710();
    param_1 = extraout_EDX;
  }
  if (*(int *)(in_ECX + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4) >> 2;
  }
  if (uVar1 < param_1) {
    pvVar2 = operator_new(param_1 * 4);
    local_8 = 0;
    FUN_0042ea40(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar2);
    if (*(void **)(in_ECX + 4) != (void *)0x0) {
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 4 + (int)pvVar2);
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 4) = pvVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004bba1a @ 0x004bba1a ====

void Catch_004bba1a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004bba30 @ 0x004bba30 ====

void FUN_004bba30(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  uint uVar5;
  uint extraout_ECX;
  undefined4 *puVar6;
  undefined4 local_3c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980250;
  local_10 = ExceptionList;
  puVar6 = &local_3c;
  for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *param_3;
    param_3 = param_3 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar4 = *(int *)(in_ECX + 4);
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar4) / 0x28;
  }
  if (param_2 != 0) {
    if (iVar4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar4) / 0x28;
    }
    ExceptionList = &local_10;
    local_14 = (undefined1 *)((int)register0x00000010 + -0x48);
    if (0x6666666U - iVar1 < param_2) {
      ExceptionList = &local_10;
      local_14 = (undefined1 *)((int)register0x00000010 + -0x48);
      FUN_004389d0();
      uVar5 = extraout_ECX;
    }
    if (iVar4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar4) / 0x28;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x6666666 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = (*(int *)(in_ECX + 8) - iVar4) / 0x28;
      }
      if (uVar5 < iVar4 + param_2) {
        iVar4 = FUN_00436560();
        uVar5 = iVar4 + param_2;
      }
      pvVar2 = operator_new(uVar5 * 0x28);
      local_8 = 0;
      iVar4 = FUN_00438730(*(undefined4 *)(in_ECX + 4),param_1,pvVar2);
      FUN_004bb4a0(iVar4,param_2,&local_3c);
      FUN_00438730(param_1,*(undefined4 *)(in_ECX + 8),iVar4 + param_2 * 0x28);
      iVar4 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar4 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x28;
      }
      if (*(void **)(in_ECX + 4) == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x28 + (int)pvVar2);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar2 + (param_2 + iVar4) * 0x28);
        *(void **)(in_ECX + 4) = pvVar2;
        ExceptionList = local_10;
        return;
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar4 = *(int *)(in_ECX + 8);
    if ((uint)((iVar4 - param_1) / 0x28) < param_2) {
      FUN_00438730(param_1,iVar4,param_2 * 0x28 + param_1);
      local_8 = 2;
      FUN_004bb590(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x28,&local_3c)
      ;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x28;
      FUN_004bb470(param_1,*(int *)(in_ECX + 8) + param_2 * -0x28,&local_3c);
      ExceptionList = local_10;
      return;
    }
    iVar1 = iVar4 + param_2 * -0x28;
    uVar3 = FUN_00438730(iVar1,iVar4,iVar4);
    *(undefined4 *)(in_ECX + 8) = uVar3;
    FUN_00438790(param_1,iVar1,iVar4);
    FUN_004bb470(param_1,param_2 * 0x28 + param_1,&local_3c);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004bbbe2 @ 0x004bbbe2 ====

void Catch_004bbbe2(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_004bbcf0 @ 0x004bbcf0 ====

void FUN_004bbcf0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_2;
  *in_ECX = param_1;
  in_ECX[2] = param_3;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_4,0,0xffffffff);
  in_ECX[10] = *(undefined4 *)(param_4 + 0x1c);
  *(undefined1 *)(in_ECX + 0xb) = param_5;
  *(undefined1 *)((int)in_ECX + 0x2d) = 0;
  return;
}


// ==== FUN_004bbd50 @ 0x004bbd50 ====

uint FUN_004bbd50(int *param_1,int *param_2,byte param_3)

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
    _Memory = (void *)param_1[10];
    if (_Memory != (void *)0x0) break;
    if (*(char *)((int)param_1 + 0x2d) == '\0') {
      piVar2 = (int *)param_1[2];
      if (*(char *)((int)piVar2 + 0x2d) == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x2d);
        param_1 = piVar2;
        piVar2 = (int *)*piVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x2d);
          param_1 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(param_1[1] + 0x2d);
        piVar3 = (int *)param_1[1];
        piVar2 = param_1;
        while ((param_1 = piVar3, cVar1 == '\0' && (piVar2 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x2d);
          piVar3 = (int *)param_1[1];
          piVar2 = param_1;
        }
      }
    }
  }
  FUN_004bb5c0();
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_004bbdd0 @ 0x004bbdd0 ====

uint FUN_004bbdd0(int *param_1,int *param_2,byte param_3)

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
    _Memory = (void *)param_1[10];
    if (_Memory != (void *)0x0) break;
    if (*(char *)((int)param_1 + 0x2d) == '\0') {
      piVar2 = (int *)param_1[2];
      if (*(char *)((int)piVar2 + 0x2d) == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x2d);
        param_1 = piVar2;
        piVar2 = (int *)*piVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x2d);
          param_1 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(param_1[1] + 0x2d);
        piVar3 = (int *)param_1[1];
        piVar2 = param_1;
        while ((param_1 = piVar3, cVar1 == '\0' && (piVar2 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x2d);
          piVar3 = (int *)param_1[1];
          piVar2 = param_1;
        }
      }
    }
  }
  FUN_004bb640();
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_004bbe50 @ 0x004bbe50 ====

void FUN_004bbe50(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x28 != 0) {
      iVar1 = (param_2 - iVar1) / 0x28;
      goto LAB_004bbe95;
    }
  }
  iVar1 = 0;
LAB_004bbe95:
  FUN_004bba30(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x28;
  return;
}


// ==== FUN_004bbec0 @ 0x004bbec0 ====

void * FUN_004bbec0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980271;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x30);
  local_8 = 1;
  if (pvVar1 != (void *)0x0) {
    FUN_004bbcf0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@004bbf32 @ 0x004bbf32 ====

void Catch_004bbf32(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004bbf50 @ 0x004bbf50 ====

/* WARNING: Removing unreachable block (ram,0x004bc060) */
/* WARNING: Removing unreachable block (ram,0x004bc071) */
/* WARNING: Removing unreachable block (ram,0x004bc07a) */
/* WARNING: Removing unreachable block (ram,0x004bc07d) */
/* WARNING: Removing unreachable block (ram,0x004bc06d) */
/* WARNING: Removing unreachable block (ram,0x004bc08b) */
/* WARNING: Removing unreachable block (ram,0x004bc098) */
/* WARNING: Removing unreachable block (ram,0x004bc0a3) */
/* WARNING: Removing unreachable block (ram,0x004bc09f) */
/* WARNING: Removing unreachable block (ram,0x004bc093) */
/* WARNING: Removing unreachable block (ram,0x004bc0a6) */

void FUN_004bbf50(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_009802b8;
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
            goto LAB_004bc177;
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
LAB_004bc177:
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


// ==== FUN_004bc220 @ 0x004bc220 ====

void FUN_004bc220(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) == '\0') {
    FUN_004bc220(*(undefined4 *)((int)param_1 + 8));
    FUN_00446f40();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004bc260 @ 0x004bc260 ====

void FUN_004bc260(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) == '\0') {
    FUN_004bc260(*(undefined4 *)((int)param_1 + 8));
    FUN_00446f40();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004bc2a0 @ 0x004bc2a0 ====

void FUN_004bc2a0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) == '\0') {
    FUN_004bc2a0(*(undefined4 *)((int)param_1 + 8));
    FUN_00446f40();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004bc2e0 @ 0x004bc2e0 ====

void FUN_004bc2e0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  return;
}


// ==== FUN_004bc340 @ 0x004bc340 ====

undefined4 * FUN_004bc340(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x24;
    puVar2 = param_3 + -9;
    *puVar2 = *(undefined4 *)(param_2 + -0x24);
    param_3[-8] = *(undefined4 *)(param_2 + -0x20);
    param_3[-7] = *(undefined4 *)(param_2 + -0x1c);
    param_3[-6] = *(undefined4 *)(param_2 + -0x18);
    param_3[-5] = *(undefined4 *)(param_2 + -0x14);
    FUN_004394e0(param_2 + -0x10);
    param_2 = iVar1;
    param_3 = puVar2;
  } while (iVar1 != param_1);
  return puVar2;
}


// ==== FUN_004bc3a0 @ 0x004bc3a0 ====

undefined4 FUN_004bc3a0(void)

{
  return 0xc0002;
}


// ==== FUN_004bc3b0 @ 0x004bc3b0 ====

void FUN_004bc3b0(byte param_1)

{
  FUN_004bc3e0();
  if ((param_1 & 1) != 0) {
    (**(code **)(*DAT_00b5a6a8 + 8))();
  }
  return;
}


// ==== FUN_004bc3e0 @ 0x004bc3e0 ====

void FUN_004bc3e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b0308;
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_0099cf40;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_004bc420 @ 0x004bc420 ====

void FUN_004bc420(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x28) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x28))) {
    FUN_004bbe50(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_004bb4a0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x28;
  return;
}


// ==== FUN_004bc4b0 @ 0x004bc4b0 ====

void FUN_004bc4b0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_009802b8;
  local_c = ExceptionList;
  if (0x7fffffd < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004bbec0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0xb] == '\0') {
LAB_004bc5a9:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_004bc5a9;
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


// ==== FUN_004bc690 @ 0x004bc690 ====

void FUN_004bc690(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x24) {
    FUN_00705010();
  }
  return;
}


// ==== FUN_004bc6c0 @ 0x004bc6c0 ====

int FUN_004bc6c0(void)

{
  code *pcVar1;
  void *pvVar2;
  int extraout_EAX;
  int iVar3;
  undefined1 local_28 [4];
  void *local_24;
  int local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009802e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar2 = operator_new(100);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    local_14 = 0;
  }
  else {
    local_14 = FUN_004bc2e0();
  }
  local_4 = 0xffffffff;
  if (local_14 != 0) {
    ExceptionList = local_c;
    return local_14;
  }
  local_10 = 0xf;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  local_4 = 1;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)(pvVar2);
    return iVar3;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_004bc770 @ 0x004bc770 ====

void * FUN_004bc770(void)

{
  code *pcVar1;
  void *pvVar2;
  void *extraout_EAX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00980316;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar2 = operator_new(0x3c);
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar2 + 0x18) = 0xf;
    *(undefined4 *)((int)pvVar2 + 0x14) = 0;
    *(undefined1 *)((int)pvVar2 + 4) = 0;
    *(undefined4 *)((int)pvVar2 + 0x20) = 0;
    *(undefined4 *)((int)pvVar2 + 0x24) = 0;
    *(undefined4 *)((int)pvVar2 + 0x28) = 0;
    *(undefined4 *)((int)pvVar2 + 0x30) = 0;
    *(undefined4 *)((int)pvVar2 + 0x34) = 0;
    *(undefined4 *)((int)pvVar2 + 0x38) = 0;
  }
  local_4 = 0xffffffff;
  if (pvVar2 != (void *)0x0) {
    ExceptionList = local_c;
    return pvVar2;
  }
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_10 = 0xf;
  FUN_00401740(&DAT_0099e358,2);
  local_4 = 3;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    pvVar2 = (void *)(*pcVar1)();
    return pvVar2;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_004bc830 @ 0x004bc830 ====

void FUN_004bc830(void)

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
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x24) {
    FUN_00705010();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004bc880 @ 0x004bc880 ====

undefined4 * FUN_004bc880(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00980331;
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


// ==== Catch@004bc8f6 @ 0x004bc8f6 ====

void Catch_004bc8f6(void)

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


// ==== FUN_004bc940 @ 0x004bc940 ====

/* WARNING: Removing unreachable block (ram,0x004bc99f) */

void FUN_004bc940(undefined4 *param_1,undefined4 *param_2)

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
LAB_004bc9d0:
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
        if (uVar5 == 0) goto LAB_004bc9d0;
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
      puVar6 = (undefined4 *)FUN_004bc4b0(&param_2,1,puVar6,iVar3);
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
    puVar6 = (undefined4 *)FUN_004bc4b0(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_004bcab0 @ 0x004bcab0 ====

void FUN_004bcab0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004bc220(piVar6[1]);
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
    FUN_004bbf50(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004bcb70 @ 0x004bcb70 ====

void FUN_004bcb70(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004bc260(piVar6[1]);
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
    FUN_004bbf50(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004bcc30 @ 0x004bcc30 ====

void FUN_004bcc30(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004bc2a0(piVar6[1]);
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
    FUN_004bbf50(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004bccf0 @ 0x004bccf0 ====

void FUN_004bccf0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  if (param_2 != param_3) {
    iVar2 = FUN_0043ab10(param_3,*(undefined4 *)(in_ECX + 8),param_2,param_2);
    iVar1 = *(int *)(in_ECX + 8);
    for (iVar3 = iVar2; iVar3 != iVar1; iVar3 = iVar3 + 0x24) {
      FUN_00705010();
    }
    *(int *)(in_ECX + 8) = iVar2;
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_004bcd60 @ 0x004bcd60 ====

void FUN_004bcd60(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00980351;
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


// ==== Catch@004bcdd7 @ 0x004bcdd7 ====

void Catch_004bcdd7(void)

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


// ==== FUN_004bce20 @ 0x004bce20 ====

void FUN_004bce20(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    FUN_00405de0(*(int *)(in_ECX + 0x40),*(undefined4 *)(in_ECX + 0x44),in_ECX + 0x3c);
    _free(*(void **)(in_ECX + 0x40));
    return;
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  if (*(void **)(in_ECX + 0x30) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x30));
    return;
  }
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  if (*(int *)(in_ECX + 0x20) != 0) {
    FUN_0043ab70(*(int *)(in_ECX + 0x20),*(undefined4 *)(in_ECX + 0x24),in_ECX + 0x1c);
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


// ==== FUN_004bced0 @ 0x004bced0 ====

void FUN_004bced0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  return;
}


// ==== FUN_004bcf30 @ 0x004bcf30 ====

int FUN_004bcf30(int param_1,int param_2,undefined4 param_3)

{
  FUN_004bcd60(param_1,param_2,param_3);
  return param_1 + param_2 * 0x24;
}


// ==== FUN_004bcf60 @ 0x004bcf60 ====

int FUN_004bcf60(void)

{
  code *pcVar1;
  void *pvVar2;
  int extraout_EAX;
  int iVar3;
  undefined1 local_28 [4];
  void *local_24;
  int local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009802e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar2 = operator_new(0x4c);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    local_14 = 0;
  }
  else {
    local_14 = FUN_004bced0();
  }
  local_4 = 0xffffffff;
  if (local_14 != 0) {
    ExceptionList = local_c;
    return local_14;
  }
  local_10 = 0xf;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  local_4 = 1;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)(pvVar2);
    return iVar3;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_004bd010 @ 0x004bd010 ====

void * FUN_004bd010(void)

{
  code *pcVar1;
  void *pvVar2;
  void *extraout_EAX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009803c4;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar2 = operator_new(0x70);
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar2 + 0x2c) = 0;
    *(undefined4 *)((int)pvVar2 + 0x30) = 0;
    *(undefined4 *)((int)pvVar2 + 0x34) = 0;
    *(undefined4 *)((int)pvVar2 + 0x3c) = 0;
    *(undefined4 *)((int)pvVar2 + 0x40) = 0;
    *(undefined4 *)((int)pvVar2 + 0x44) = 0;
    *(undefined4 *)((int)pvVar2 + 0x4c) = 0;
    *(undefined4 *)((int)pvVar2 + 0x50) = 0;
    *(undefined4 *)((int)pvVar2 + 0x54) = 0;
    *(undefined4 *)((int)pvVar2 + 0x5c) = 0;
    *(undefined4 *)((int)pvVar2 + 0x60) = 0;
    *(undefined4 *)((int)pvVar2 + 100) = 0;
  }
  local_4 = 0xffffffff;
  if (pvVar2 != (void *)0x0) {
    ExceptionList = local_c;
    return pvVar2;
  }
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_10 = 0xf;
  FUN_00401740(&DAT_0099e358,2);
  local_4 = 4;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    pvVar2 = (void *)(*pcVar1)();
    return pvVar2;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_004bd0d0 @ 0x004bd0d0 ====

void FUN_004bd0d0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004bcab0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004bd100 @ 0x004bd100 ====

void FUN_004bd100(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004bcb70(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004bd130 @ 0x004bd130 ====

void FUN_004bd130(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004bcc30(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004bd160 @ 0x004bd160 ====

void FUN_004bd160(void)

{
  int in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009803e3;
  pvStack_c = ExceptionList;
  local_4 = 1;
  if (*(void **)(in_ECX + 0x28) == (void *)0x0) {
    ExceptionList = &pvStack_c;
    *(undefined4 *)(in_ECX + 0x28) = 0;
    *(undefined4 *)(in_ECX + 0x2c) = 0;
    *(undefined4 *)(in_ECX + 0x30) = 0;
    FUN_004bcc30(local_10,**(undefined4 **)(in_ECX + 0x1c),*(undefined4 **)(in_ECX + 0x1c));
    _free(*(void **)(in_ECX + 0x1c));
    return;
  }
  ExceptionList = &pvStack_c;
  _free(*(void **)(in_ECX + 0x28));
  return;
}


// ==== FUN_004bd240 @ 0x004bd240 ====

void FUN_004bd240(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_009803f8;
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
      FUN_004bb710();
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
      iVar2 = FUN_004bc880(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_004bcd60(iVar2,param_2,&local_40);
      FUN_004bc880(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x24);
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
        FUN_004bc880(param_1,iVar2,param_2 * 0x24 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004bcf30(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x24,
                     &local_40);
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x24;
        local_8 = 0;
        FUN_0043ad60(param_1,*(int *)(in_ECX + 8) + param_2 * -0x24,&local_40);
      }
      else {
        iVar1 = iVar2 + param_2 * -0x24;
        uVar4 = FUN_004bc880(iVar1,iVar2,iVar2);
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


// ==== Catch@004bd41c @ 0x004bd41c ====

void Catch_004bd41c(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_004bc690(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@004bd4cd @ 0x004bd4cd ====

void Catch_004bd4cd(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x24;
  FUN_004bc690(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004bd560 @ 0x004bd560 ====

uint FUN_004bd560(int *param_1,int *param_2,byte param_3)

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
    _Memory = (void *)param_1[10];
    if (_Memory != (void *)0x0) break;
    if (*(char *)((int)param_1 + 0x2d) == '\0') {
      piVar2 = (int *)param_1[2];
      if (*(char *)((int)piVar2 + 0x2d) == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x2d);
        param_1 = piVar2;
        piVar2 = (int *)*piVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x2d);
          param_1 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(param_1[1] + 0x2d);
        piVar3 = (int *)param_1[1];
        piVar2 = param_1;
        while ((param_1 = piVar3, cVar1 == '\0' && (piVar2 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x2d);
          piVar3 = (int *)param_1[1];
          piVar2 = param_1;
        }
      }
    }
  }
  FUN_004bce20();
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_004bd5e0 @ 0x004bd5e0 ====

void FUN_004bd5e0(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098042e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_004a37b0();
  *(int *)(in_ECX + 4) = iVar2;
  *(undefined1 *)(iVar2 + 0x2d) = 1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  local_4 = 0;
  iVar2 = FUN_004a37b0();
  *(int *)(in_ECX + 0x10) = iVar2;
  *(undefined1 *)(iVar2 + 0x2d) = 1;
  *(int *)(*(int *)(in_ECX + 0x10) + 4) = *(int *)(in_ECX + 0x10);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x10);
  *(int *)(*(int *)(in_ECX + 0x10) + 8) = *(int *)(in_ECX + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  iVar2 = FUN_004a37b0();
  *(int *)(in_ECX + 0x1c) = iVar2;
  *(undefined1 *)(iVar2 + 0x2d) = 1;
  *(int *)(*(int *)(in_ECX + 0x1c) + 4) = *(int *)(in_ECX + 0x1c);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(in_ECX + 0x1c);
  *(int *)(*(int *)(in_ECX + 0x1c) + 8) = *(int *)(in_ECX + 0x1c);
  *(undefined4 *)(in_ECX + 0x20) = 0;
  uVar1 = DAT_009b0318;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = uVar1;
  *(undefined4 *)(in_ECX + 0x38) = uVar1;
  *(undefined4 *)(in_ECX + 0x3c) = uVar1;
  uVar1 = DAT_0099d0b4;
  *(undefined4 *)(in_ECX + 0x40) = DAT_0099d0b4;
  *(undefined4 *)(in_ECX + 0x44) = uVar1;
  *(undefined4 *)(in_ECX + 0x48) = uVar1;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004bd6d0 @ 0x004bd6d0 ====

void FUN_004bd6d0(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *in_stack_00000020;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980448;
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
    FUN_004bd240(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
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


// ==== FUN_004bd7b0 @ 0x004bd7b0 ====

void FUN_004bd7b0(byte param_1)

{
  void *in_ECX;
  
  FUN_004baaf0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004bd7d0 @ 0x004bd7d0 ====

void FUN_004bd7d0(void)

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
  puStack_8 = &LAB_00980468;
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


// ==== FUN_004bd840 @ 0x004bd840 ====

void FUN_004bd840(void)

{
  undefined1 uStack00000010;
  void *in_stack_00000014;
  uint in_stack_00000028;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980488;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00401660(&uStack00000010,0,0xffffffff);
  FUN_0042a7a0();
  if (in_stack_00000028 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(in_stack_00000014);
  return;
}


// ==== FUN_004bd8e0 @ 0x004bd8e0 ====

void FUN_004bd8e0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009804a5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0xffffffff;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  *in_ECX = &PTR_FUN_009b0398;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  local_4 = 1;
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004bd970 @ 0x004bd970 ====

void FUN_004bd970(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b0398;
  FUN_00413860();
  FUN_0049da30();
  return;
}


// ==== FUN_004bd990 @ 0x004bd990 ====

undefined4 FUN_004bd990(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 != 0xb) {
    return 0;
  }
  uVar4 = 0;
  if (param_1[7] != 0) {
    iVar2 = 0;
    do {
      iVar1 = param_1[4];
      if ((iVar1 == 0) || ((uint)((param_1[5] - iVar1) / 0x28) <= uVar4)) {
        FUN_004bd7d0();
        break;
      }
      FUN_0042b0c0(iVar1 + iVar2);
      uVar4 = uVar4 + 1;
      iVar2 = iVar2 + 0x28;
    } while (uVar4 < (uint)param_1[7]);
  }
  uVar3 = (**(code **)(*param_1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar3;
  *(int **)(in_ECX + 0x20) = param_1;
  *(undefined4 *)(in_ECX + 0x34) = 2;
  return 1;
}


// ==== FUN_004bda30 @ 0x004bda30 ====

undefined4 FUN_004bda30(void)

{
  char cVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  puVar2 = (undefined4 *)FUN_004bda60();
  if (puVar2 != (undefined4 *)0x0) {
    cVar1 = (**(code **)(*in_ECX + 0x10))(puVar2);
    if (cVar1 != '\0') {
      return 1;
    }
    (**(code **)*puVar2)(1);
  }
  return 0;
}


// ==== FUN_004bda60 @ 0x004bda60 ====

undefined4 * FUN_004bda60(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined4 *extraout_EAX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009804cb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar2 = operator_new(0x20);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_0099d5bc;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
  }
  local_4 = 0xffffffff;
  if (puVar2 != (undefined4 *)0x0) {
    ExceptionList = local_c;
    return puVar2;
  }
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_10 = 0xf;
  FUN_00401740(&DAT_0099e358,2);
  local_4 = 2;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    puVar2 = (undefined4 *)(*pcVar1)();
    return puVar2;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_004bdb10 @ 0x004bdb10 ====

void FUN_004bdb10(byte param_1)

{
  void *in_ECX;
  
  FUN_004bd970();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004bdb30 @ 0x004bdb30 ====

void FUN_004bdb30(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  
  piVar1 = (int *)(in_ECX + 4);
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    piVar2 = piVar1;
  }
  else {
    piVar2 = (int *)*piVar1;
  }
  if (param_2 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_2 - (int)piVar2;
  }
  if (param_3 != 0) {
    param_3 = param_3 - param_2;
  }
  FUN_00401390(iVar3,param_3);
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *param_1 = (int)piVar1 + iVar3;
    return;
  }
  *param_1 = *piVar1 + iVar3;
  return;
}


// ==== FUN_004bdb90 @ 0x004bdb90 ====

void FUN_004bdb90(void)

{
  int in_ECX;
  int *piVar1;
  int *piVar2;
  undefined1 local_4 [4];
  
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
  FUN_004bdb30(local_4,piVar1,*(int *)(in_ECX + 0x14) + (int)piVar2);
  return;
}


// ==== FUN_004bdbc0 @ 0x004bdbc0 ====

void FUN_004bdbc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b0410;
  if ((uint)in_ECX[0x15] < 0x10) {
    in_ECX[0x15] = 0xf;
    in_ECX[0x14] = 0;
    *(undefined1 *)(in_ECX + 0x10) = 0;
    FUN_0049da30();
    return;
  }
  _free((void *)in_ECX[0x10]);
  return;
}


// ==== FUN_004bdc00 @ 0x004bdc00 ====

undefined4 FUN_004bdc00(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  int *piVar4;
  int *piVar5;
  undefined1 auStack_4 [4];
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 != 6) {
    return 0;
  }
  uVar2 = FUN_00426450();
  piVar4 = (int *)(in_ECX + 0x40);
  if (*(uint *)(in_ECX + 0x54) < 0x10) {
    piVar5 = piVar4;
  }
  else {
    piVar5 = (int *)*piVar4;
  }
  if (0xf < *(uint *)(in_ECX + 0x54)) {
    piVar4 = (int *)*piVar4;
  }
  FUN_004bdb30(auStack_4,piVar4,*(int *)(in_ECX + 0x50) + (int)piVar5);
  uVar3 = (**(code **)(*param_1 + 0x10))();
  FUN_00401740(uVar2,uVar3);
  uVar2 = (**(code **)(*param_1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar2;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 2;
  (**(code **)*param_1)(1);
  return 1;
}


// ==== FUN_004bdca0 @ 0x004bdca0 ====

undefined4 FUN_004bdca0(void)

{
  int *piVar1;
  undefined4 extraout_EAX;
  int iVar2;
  undefined4 extraout_EAX_00;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX_01;
  int in_ECX;
  int *piVar5;
  int *piVar6;
  undefined1 auStack_30 [4];
  void *local_2c;
  void *local_28;
  uint local_18;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009804e8;
  local_c = ExceptionList;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401660(in_ECX + 4,0,0xffffffff);
  local_10 = (void *)0x13;
  local_4 = 0;
  piVar1 = (int *)FUN_004a8060(&local_2c);
  if (piVar1 == (int *)0x0) {
    if (0xf < local_14) {
      _free(local_28);
      return extraout_EAX;
    }
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 4))();
    if (iVar2 == 6) {
      if (*(undefined4 **)(in_ECX + 0x20) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(in_ECX + 0x20))(1);
      }
      *(undefined4 *)(in_ECX + 0x20) = 0;
      uVar3 = FUN_00426450();
      piVar5 = (int *)(in_ECX + 0x40);
      if (*(uint *)(in_ECX + 0x54) < 0x10) {
        piVar6 = piVar5;
      }
      else {
        piVar6 = (int *)*piVar5;
      }
      if (0xf < *(uint *)(in_ECX + 0x54)) {
        piVar5 = (int *)*piVar5;
      }
      FUN_004bdb30(auStack_30,piVar5,*(int *)(in_ECX + 0x50) + (int)piVar6);
      uVar4 = (**(code **)(*piVar1 + 0x10))();
      FUN_00401740(uVar3,uVar4);
      uVar3 = (**(code **)(*piVar1 + 0x10))();
      *(undefined4 *)(in_ECX + 0x28) = uVar3;
      *(undefined4 *)(in_ECX + 0x20) = 0;
      (**(code **)*piVar1)(1);
      if (local_18 < 0x10) {
        ExceptionList = local_10;
        return 1;
      }
      _free(local_2c);
      return extraout_EAX_01;
    }
    if (0xf < local_14) {
      _free(local_28);
      return extraout_EAX_00;
    }
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_004bde00 @ 0x004bde00 ====

void FUN_004bde00(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980505;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0xffffffff;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  *in_ECX = &PTR_FUN_009b0410;
  in_ECX[0x15] = 0xf;
  in_ECX[0x14] = 0;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  local_4 = 1;
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004bde90 @ 0x004bde90 ====

void FUN_004bde90(byte param_1)

{
  void *in_ECX;
  
  FUN_004bdbc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004bdeb0 @ 0x004bdeb0 ====

void FUN_004bdeb0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x3d) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x3d) == '\0');
  }
  return;
}


// ==== FUN_004bded0 @ 0x004bded0 ====

void FUN_004bded0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x4d) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x4d) == '\0');
  }
  return;
}


// ==== FUN_004bdef0 @ 0x004bdef0 ====

void FUN_004bdef0(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x4d);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x4d);
  }
  return;
}


// ==== FUN_004bdf10 @ 0x004bdf10 ====

void FUN_004bdf10(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x4d) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x4d) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x4d);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x4d);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x4d) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x4d) == '\0');
    if (*(char *)((int)piVar4 + 0x4d) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_004bdf70 @ 0x004bdf70 ====

void FUN_004bdf70(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x21) == '\0') {
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


// ==== FUN_004bdfc0 @ 0x004bdfc0 ====

void FUN_004bdfc0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x21) == '\0') {
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


// ==== FUN_004be020 @ 0x004be020 ====

void FUN_004be020(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x39) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x39) == '\0');
  }
  return;
}


// ==== FUN_004be040 @ 0x004be040 ====

void FUN_004be040(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 4) {
    *param_1 = *param_3;
    param_1[1] = param_3[1];
    param_1[2] = param_3[2];
    param_1[3] = param_3[3];
  }
  return;
}


// ==== FUN_004be080 @ 0x004be080 ====

void FUN_004be080(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  while (param_1 != param_2) {
    param_3[-4] = param_2[-4];
    param_3[-3] = param_2[-3];
    param_3[-2] = param_2[-2];
    param_3[-1] = param_2[-1];
    param_2 = param_2 + -4;
    param_3 = param_3 + -4;
  }
  return;
}


// ==== FUN_004be0c0 @ 0x004be0c0 ====

void FUN_004be0c0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x3d) == '\0') {
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


// ==== FUN_004be110 @ 0x004be110 ====

void FUN_004be110(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x4d) == '\0') {
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


// ==== FUN_004be160 @ 0x004be160 ====

void FUN_004be160(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x4d) == '\0') {
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


// ==== FUN_004be1c0 @ 0x004be1c0 ====

void FUN_004be1c0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x39) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x39) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x39);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x39);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x39);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x39);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_004be210 @ 0x004be210 ====

void FUN_004be210(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x4d) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x4d) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x4d);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x4d);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x4d);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x4d);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_004be260 @ 0x004be260 ====

void FUN_004be260(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x39) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x39) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x39);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x39);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x39) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x39) == '\0');
    if (*(char *)((int)piVar4 + 0x39) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_004be2c0 @ 0x004be2c0 ====

void FUN_004be2c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x24);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[3] = *param_4;
    puVar1[4] = param_4[1];
    puVar1[5] = param_4[2];
    puVar1[6] = param_4[3];
    puVar1[7] = param_4[4];
    *(undefined1 *)(puVar1 + 8) = param_5;
    *(undefined1 *)((int)puVar1 + 0x21) = 0;
  }
  return;
}


// ==== FUN_004be320 @ 0x004be320 ====

void FUN_004be320(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 4) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      param_3[1] = param_1[1];
      param_3[2] = param_1[2];
      param_3[3] = param_1[3];
    }
    param_3 = param_3 + 4;
  }
  return;
}


// ==== FUN_004be360 @ 0x004be360 ====

void FUN_004be360(void)

{
  undefined4 *puVar1;
  
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
  return;
}


// ==== FUN_004be3a0 @ 0x004be3a0 ====

void FUN_004be3a0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x40);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0xf) = 1;
  *(undefined1 *)((int)puVar1 + 0x3d) = 0;
  return;
}


// ==== FUN_004be3e0 @ 0x004be3e0 ====

void FUN_004be3e0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x50);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x13) = 1;
  *(undefined1 *)((int)puVar1 + 0x4d) = 0;
  return;
}


// ==== FUN_004be420 @ 0x004be420 ====

void FUN_004be420(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x3c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0xe) = 1;
  *(undefined1 *)((int)puVar1 + 0x39) = 0;
  return;
}


// ==== FUN_004be460 @ 0x004be460 ====

void FUN_004be460(void *param_1)

{
  if (*(char *)((int)param_1 + 0x21) == '\0') {
    FUN_004be460(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004be4a0 @ 0x004be4a0 ====

void FUN_004be4a0(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  if (param_2 != 0) {
    do {
      if (param_1 != (undefined4 *)0x0) {
        *param_1 = *param_3;
        param_1[1] = param_3[1];
        param_1[2] = param_3[2];
        param_1[3] = param_3[3];
      }
      param_1 = param_1 + 4;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_004be4e0 @ 0x004be4e0 ====

void FUN_004be4e0(undefined4 *param_1,ushort *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x39) == '\0') {
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
    } while (*(char *)((int)puVar2 + 0x39) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < *(ushort *)(puVar3 + 3))) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_004be550 @ 0x004be550 ====

void FUN_004be550(void)

{
  undefined4 *in_ECX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980526;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  *in_ECX = 0;
  *(undefined1 *)(in_ECX + 0xf) = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  local_4 = 1;
  puVar1 = in_ECX + 2;
  if ((uint)in_ECX[7] < 0x10) {
    puVar2 = puVar1;
  }
  else {
    puVar2 = (undefined4 *)*puVar1;
  }
  if (0xf < (uint)in_ECX[7]) {
    puVar1 = (undefined4 *)*puVar1;
  }
  FUN_004bdb30(local_10,puVar1,in_ECX[6] + (int)puVar2);
  puVar1 = in_ECX + 9;
  if ((uint)in_ECX[0xe] < 0x10) {
    puVar2 = puVar1;
  }
  else {
    puVar2 = (undefined4 *)*puVar1;
  }
  if (0xf < (uint)in_ECX[0xe]) {
    puVar1 = (undefined4 *)*puVar1;
  }
  FUN_004bdb30(local_10,puVar1,in_ECX[0xd] + (int)puVar2);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004be610 @ 0x004be610 ====

void FUN_004be610(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x24) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x24));
    return;
  }
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  if (*(uint *)(in_ECX + 0x1c) < 0x10) {
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0xf;
    *(undefined1 *)(in_ECX + 8) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_004be660 @ 0x004be660 ====

void FUN_004be660(undefined1 *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098053b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *param_1 = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  *(undefined4 *)(param_1 + 8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 1000;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  pvVar1 = operator_new(0x48);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(param_1 + 0x34) = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_004be550();
  *(undefined4 *)(param_1 + 0x34) = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004be740 @ 0x004be740 ====

void FUN_004be740(uint param_1,uint param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  float10 fVar10;
  int local_50;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  undefined1 local_2c [4];
  void *local_28;
  int local_24;
  int local_20;
  undefined4 uStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  uVar6 = param_1;
  puStack_8 = &LAB_0098054d;
  pvStack_c = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    iVar7 = 0;
  }
  else {
    iVar7 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
  }
  iVar7 = (int)((iVar7 - param_2) + ((int)(iVar7 - param_2) >> 0x1f & 3U)) >> 2;
  bVar5 = true;
  param_1 = param_1 & 0xffffff00;
  local_28 = (void *)0x0;
  local_24 = 0;
  local_20 = 0;
  local_4 = 0;
  local_50 = 0;
  ExceptionList = &pvStack_c;
  if (0 < iVar7) {
    iVar9 = param_2 * 0x1c;
    ExceptionList = &pvStack_c;
    do {
      iVar4 = *(int *)(uVar6 + 4);
      if ((iVar4 == 0) || ((uint)((*(int *)(uVar6 + 8) - iVar4) / 0x1c) <= param_2)) {
LAB_004bea59:
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uVar8 = thunk_FUN_00796e60(iVar9 + iVar4);
      iVar4 = *(int *)(uVar6 + 4);
      if ((iVar4 == 0) || ((uint)((*(int *)(uVar6 + 8) - iVar4) / 0x1c) <= param_2 + 1))
      goto LAB_004bea59;
      fVar10 = (float10)thunk_FUN_00796ec0(iVar4 + iVar9 + 0x1c);
      fVar1 = (float)fVar10;
      iVar4 = *(int *)(uVar6 + 4);
      if ((iVar4 == 0) || ((uint)((*(int *)(uVar6 + 8) - iVar4) / 0x1c) <= param_2 + 2))
      goto LAB_004bea59;
      fVar10 = (float10)thunk_FUN_00796ec0(iVar9 + 0x38 + iVar4);
      fVar2 = (float)fVar10;
      iVar4 = *(int *)(uVar6 + 4);
      if ((iVar4 == 0) || ((uint)((*(int *)(uVar6 + 8) - iVar4) / 0x1c) <= param_2 + 3))
      goto LAB_004bea59;
      fVar10 = (float10)thunk_FUN_00796ec0(iVar4 + iVar9 + 0x54);
      fVar3 = (float)fVar10;
      param_2 = param_2 + 4;
      iVar9 = iVar9 + 0x70;
      uStack_1c = uVar8;
      fStack_18 = fVar1;
      fStack_14 = fVar2;
      fStack_10 = fVar3;
      if ((local_28 == (void *)0x0) ||
         ((uint)(local_20 - (int)local_28 >> 4) <= (uint)(local_24 - (int)local_28 >> 4))) {
        FUN_004c11a0(local_24,1,&uStack_1c);
      }
      else {
        FUN_004be4a0(local_24,1,&uStack_1c,local_2c,param_1);
        local_24 = local_24 + 0x10;
      }
      if ((char)param_1 == '\0') {
        param_1 = CONCAT31(param_1._1_3_,1);
        fStack_38 = fVar1;
        fStack_34 = fVar2;
        fStack_30 = fVar3;
      }
      else if (((fStack_38 != fVar1) || (fStack_34 != fVar2)) || (fStack_30 != fVar3)) {
        bVar5 = false;
      }
      local_50 = local_50 + 1;
    } while (local_50 < iVar7);
    if (((local_28 != (void *)0x0) && (local_24 - (int)local_28 >> 4 != 0)) && (bVar5)) {
      _free(local_28);
      return;
    }
  }
  FUN_004c1690(0,1000,local_2c);
  if (local_28 == (void *)0x0) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(local_28);
  return;
}


// ==== FUN_004bea70 @ 0x004bea70 ====

void FUN_004bea70(int param_1,uint param_2)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  void *pvVar7;
  float10 fVar8;
  float local_34;
  int local_2c;
  undefined4 uStack_24;
  float fStack_20;
  undefined1 local_1c [4];
  void *local_18;
  int local_14;
  int local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098055f;
  pvStack_c = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
  }
  iVar4 = (int)(iVar4 - param_2) / 2;
  bVar3 = true;
  bVar2 = false;
  local_34 = 0.0;
  local_18 = (void *)0x0;
  local_14 = 0;
  local_10 = 0;
  local_4 = 0;
  local_2c = 0;
  ExceptionList = &pvStack_c;
  if (0 < iVar4) {
    iVar6 = param_2 * 0x1c;
    ExceptionList = &pvStack_c;
    do {
      iVar1 = *(int *)(param_1 + 4);
      if ((iVar1 == 0) || ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x1c) <= param_2)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uVar5 = thunk_FUN_00796e60(iVar1 + iVar6);
      iVar1 = *(int *)(param_1 + 4);
      if ((iVar1 == 0) || ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x1c) <= param_2 + 1)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      fVar8 = (float10)thunk_FUN_00796ec0(iVar1 + iVar6 + 0x1c);
      iVar1 = local_14;
      pvVar7 = local_18;
      fStack_20 = (float)fVar8;
      param_2 = param_2 + 2;
      iVar6 = iVar6 + 0x38;
      uStack_24 = uVar5;
      if ((local_18 == (void *)0x0) ||
         ((uint)(local_10 - (int)local_18 >> 3) <= (uint)(local_14 - (int)local_18 >> 3))) {
        FUN_004b9740(local_14,1,&uStack_24);
        pvVar7 = local_18;
      }
      else {
        FUN_00429bc0(local_14,1,&uStack_24,local_1c,param_1);
        local_14 = iVar1 + 8;
      }
      if (bVar2) {
        if (local_34 != (float)fVar8) {
          bVar3 = false;
        }
      }
      else {
        bVar2 = true;
        local_34 = (float)fVar8;
      }
      local_2c = local_2c + 1;
    } while (local_2c < iVar4);
    if (((pvVar7 != (void *)0x0) && (local_14 - (int)local_18 >> 3 != 0)) && (bVar3)) {
      _free(local_18);
      return;
    }
  }
  FUN_004b9a80(0,1000,local_1c);
  if (local_18 == (void *)0x0) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004bece0 @ 0x004bece0 ====

/* WARNING: Removing unreachable block (ram,0x004befa9) */

void FUN_004bece0(undefined4 param_1,uint *param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_3c [4];
  void *local_38;
  int local_34;
  undefined4 local_30;
  undefined4 auStack_2c [2];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00980579;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar1 = FUN_00411430();
  if (*param_2 < uVar1) {
    do {
      uVar2 = FUN_00411510(*param_2);
      local_38 = (void *)0x0;
      local_34 = 0;
      local_30 = 0;
      local_4 = 0;
      FUN_00405670(uVar2,local_3c);
      if ((local_38 == (void *)0x0) ||
         (iVar3 = local_34 - (int)local_38 >> 0x1f,
         (local_34 - (int)local_38) / 0x1c + iVar3 == iVar3)) {
        local_4 = 0xffffffff;
        if (local_38 != (void *)0x0) {
          FUN_00405de0(local_38,local_34,local_3c,param_3);
          goto LAB_004bef68;
        }
      }
      else {
        iVar3 = FUN_00403620(0,*(undefined4 *)((int)local_38 + 0x14),s_<list>_009b054c,6);
        if (iVar3 == 0) {
          FUN_004b6960();
          local_4 = 0xffffffff;
          if (local_38 != (void *)0x0) {
            FUN_00405de0(local_38,local_34,local_3c,param_3);
LAB_004bef68:
            _free(local_38);
            return;
          }
        }
        else {
          if ((local_38 == (void *)0x0) || ((local_34 - (int)local_38) / 0x1c == 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar3 = FUN_00403620(0,*(undefined4 *)((int)local_38 + 0x14),s_<_list>_009b0554,7);
          if (iVar3 == 0) {
            if (local_38 == (void *)0x0) {
              ExceptionList = local_c;
              return;
            }
            FUN_00405de0(local_38,local_34,local_3c,param_3);
            _free(local_38);
            return;
          }
          if ((local_38 == (void *)0x0) || ((local_34 - (int)local_38) / 0x1c == 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar3 = FUN_00403620(0,*(undefined4 *)((int)local_38 + 0x14),&PTR_LAB_009b055c,3);
          if (iVar3 == 0) {
            local_10 = 0xf;
            local_14 = 0;
            local_24 = (void *)((uint)local_24 & 0xffffff00);
            local_4 = CONCAT31(local_4._1_3_,1);
            if ((local_38 == (void *)0x0) || ((uint)((local_34 - (int)local_38) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
              FUN_00405ca0();
            }
            auStack_2c[0] = thunk_FUN_00796e60((int)local_38 + 0x1c);
            if ((local_38 == (void *)0x0) || ((uint)((local_34 - (int)local_38) / 0x1c) < 3)) {
                    /* WARNING: Subroutine does not return */
              FUN_00405ca0();
            }
            FUN_00401660((int)local_38 + 0x38,0,0xffffffff);
            FUN_004c24c0(auStack_2c);
            if (0xf < local_10) {
              _free(local_24);
              return;
            }
            local_10 = 0xf;
            local_14 = 0;
            local_24 = (void *)((uint)local_24 & 0xffffff00);
          }
          local_4 = 0xffffffff;
          if (local_38 != (void *)0x0) {
            FUN_00405de0(local_38,local_34,local_3c,param_3);
            goto LAB_004bef68;
          }
        }
      }
      local_4 = 0xffffffff;
      *param_2 = *param_2 + 1;
      local_38 = (void *)0x0;
      local_34 = 0;
      local_30 = 0;
      uVar1 = FUN_00411430();
    } while (*param_2 < uVar1);
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004bf020 @ 0x004bf020 ====

/* WARNING: Removing unreachable block (ram,0x004bfa62) */

void FUN_004bf020(undefined4 param_1,uint *param_2,undefined4 param_3,undefined4 *param_4)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 *puVar7;
  float10 fVar8;
  char *pcVar9;
  undefined *puVar10;
  undefined1 local_6d [5];
  undefined1 *local_68;
  void *local_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  undefined1 local_48 [4];
  void *local_44;
  int local_40;
  undefined4 local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined1 *local_30;
  int local_2c;
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  puStack_8 = &LAB_009805a6;
  local_c = ExceptionList;
  puVar7 = (undefined1 *)0x0;
  local_68 = (undefined1 *)0x0;
  local_34 = (void *)0x0;
  local_30 = (undefined1 *)0x0;
  local_2c = 0;
  local_4 = 0;
  uStack_3 = 0;
  local_6d[0] = 0x28;
  ExceptionList = &local_c;
  FUN_00417f70(0,1,local_6d);
  local_6d[0] = 0x29;
  if ((local_34 == (void *)0x0) ||
     ((uint)(local_2c - (int)local_34) <= (uint)((int)local_30 - (int)local_34))) {
    FUN_00417f70(local_30,1,local_6d);
  }
  else {
    *local_30 = 0x29;
    local_30 = local_30 + 1;
  }
  local_6d[0] = 0x7b;
  if ((local_34 == (void *)0x0) ||
     ((uint)(local_2c - (int)local_34) <= (uint)((int)local_30 - (int)local_34))) {
    FUN_00417f70(local_30,1,local_6d);
  }
  else {
    *local_30 = 0x7b;
    local_30 = local_30 + 1;
  }
  local_6d[0] = 0x7d;
  if ((local_34 == (void *)0x0) ||
     ((uint)(local_2c - (int)local_34) <= (uint)((int)local_30 - (int)local_34))) {
    FUN_00417f70(local_30,1,local_6d);
  }
  else {
    *local_30 = 0x7d;
    local_30 = local_30 + 1;
  }
  local_6d[0] = 0x2c;
  if ((local_34 == (void *)0x0) ||
     ((uint)(local_2c - (int)local_34) <= (uint)((int)local_30 - (int)local_34))) {
    FUN_00417f70(local_30,1,local_6d);
  }
  else {
    *local_30 = 0x2c;
    local_30 = local_30 + 1;
  }
  local_6d[0] = 0x20;
  if ((local_34 == (void *)0x0) ||
     ((uint)(local_2c - (int)local_34) <= (uint)((int)local_30 - (int)local_34))) {
    FUN_00417f70(local_30,1,local_6d);
  }
  else {
    *local_30 = 0x20;
    local_30 = local_30 + 1;
  }
  local_6d[0] = 9;
  if ((local_34 == (void *)0x0) ||
     ((uint)(local_2c - (int)local_34) <= (uint)((int)local_30 - (int)local_34))) {
    FUN_00417f70(local_30,1,local_6d);
  }
  else {
    *local_30 = 9;
    local_30 = local_30 + 1;
  }
  uVar4 = FUN_00411430();
  if (*param_2 < uVar4) {
    do {
      uVar5 = FUN_00411510(*param_2);
      local_44 = (void *)0x0;
      local_40 = 0;
      local_3c = 0;
      local_4 = 1;
      FUN_00404b60(uVar5,local_48,local_38);
      if (((local_44 == (void *)0x0) ||
          (iVar6 = local_40 - (int)local_44 >> 0x1f,
          (local_40 - (int)local_44) / 0x1c + iVar6 == iVar6)) ||
         (iVar6 = FUN_00403620(0,*(undefined4 *)((int)local_44 + 0x14),&DAT_009b05d4,1), iVar6 == 0)
         ) {
        local_4 = 0;
        if (local_44 != (void *)0x0) {
          FUN_00405de0(local_44,local_40,local_48,param_1);
          _free(local_44);
          return;
        }
        local_44 = (void *)0x0;
        local_40 = 0;
        local_3c = 0;
      }
      else {
        if ((local_44 == (void *)0x0) ||
           (local_64 = (void *)((local_40 - (int)local_44) / 0x1c), local_64 == (void *)0x0)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        iVar6 = FUN_00403620(0,*(undefined4 *)((int)local_44 + 0x14),s_<_scene>_009b05d8,8);
        if (iVar6 == 0) {
          *param_2 = *param_2 - 1;
          if (local_44 != (void *)0x0) {
            FUN_00405de0(local_44,local_40,local_48,param_1);
            _free(local_44);
            return;
          }
          break;
        }
        if ((local_44 == (void *)0x0) ||
           (local_64 = (void *)((local_40 - (int)local_44) / 0x1c), local_64 == (void *)0x0)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        iVar6 = FUN_00403620(0,*(undefined4 *)((int)local_44 + 0x14),s_<control>_009b05e4,9);
        if (iVar6 == 0) {
          local_64 = operator_new(200);
          local_4 = 2;
          if (local_64 == (void *)0x0) {
            puVar7 = (undefined1 *)0x0;
          }
          else {
            puVar7 = (undefined1 *)FUN_004c23b0();
          }
          local_4 = 1;
          local_68 = puVar7;
          FUN_004be660(puVar7);
          local_4 = 0;
          FUN_00406250();
        }
        else {
          if ((local_44 == (void *)0x0) ||
             (local_64 = (void *)((local_40 - (int)local_44) / 0x1c), local_64 == (void *)0x0)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar6 = FUN_00403620(0,*(undefined4 *)((int)local_44 + 0x14),s_<_control>_009b05f0,10);
          if (iVar6 == 0) {
            FUN_004c1810(&local_68);
            local_4 = 0;
            FUN_00406250();
          }
          else {
            pcVar9 = s_sceneid_009b05fc;
            uVar5 = FUN_00405d30(0);
            cVar2 = FUN_004036a0(uVar5,pcVar9);
            if (cVar2 == '\0') {
              puVar10 = &DAT_009b0604;
              uVar5 = FUN_00405d30(0);
              cVar2 = FUN_004036a0(uVar5,puVar10);
              if (cVar2 == '\0') {
                iVar6 = FUN_00405820();
                if (iVar6 == 1) {
                  local_4 = 0;
                  FUN_00406250();
                }
                else {
                  pcVar9 = s_active_009b060c;
                  uVar5 = FUN_00405d30(0);
                  cVar2 = FUN_004036a0(uVar5,pcVar9);
                  if (cVar2 == '\0') {
                    pcVar9 = s_follow_009b0614;
                    uVar5 = FUN_00405d30(0);
                    cVar2 = FUN_004036a0(uVar5,pcVar9);
                    if (cVar2 == '\0') {
                      pcVar9 = s_absdir_009b061c;
                      uVar5 = FUN_00405d30(0);
                      cVar2 = FUN_004036a0(uVar5,pcVar9);
                      if (cVar2 == '\0') {
                        pcVar9 = s_randomstart_009b0624;
                        uVar5 = FUN_00405d30(0);
                        cVar2 = FUN_004036a0(uVar5,pcVar9);
                        if (cVar2 == '\0') {
                          pcVar9 = s_unitid_009b0630;
                          uVar5 = FUN_00405d30(0);
                          cVar2 = FUN_004036a0(uVar5,pcVar9);
                          if (cVar2 == '\0') {
                            pcVar9 = s_bonename_009b0638;
                            uVar5 = FUN_00405d30(0);
                            cVar2 = FUN_004036a0(uVar5,pcVar9);
                            piVar1 = DAT_00b5a7e4;
                            if (cVar2 != '\0') {
                              uVar5 = FUN_00405d30(1);
                              FUN_00765c50(uVar5);
                              _local_4 = CONCAT31(uStack_3,3);
                              uVar5 = (**(code **)(*piVar1 + 4))(local_28);
                              *(undefined4 *)(puVar7 + 8) = uVar5;
                    /* WARNING: Subroutine does not return */
                              FUN_00446f10();
                            }
                            pcVar9 = s_lifetime_009b0644;
                            uVar5 = FUN_00405d30(0);
                            cVar2 = FUN_004036a0(uVar5,pcVar9);
                            if (cVar2 == '\0') {
                              pcVar9 = s_animtime_009b0650;
                              uVar5 = FUN_00405d30(0);
                              cVar2 = FUN_004036a0(uVar5,pcVar9);
                              if (cVar2 == '\0') {
                                pcVar9 = s_startposition_009b065c;
                                uVar5 = FUN_00405d30(0);
                                cVar2 = FUN_004036a0(uVar5,pcVar9);
                                if (cVar2 == '\0') {
                                  pcVar9 = s_endposition_009b066c;
                                  uVar5 = FUN_00405d30(0);
                                  cVar2 = FUN_004036a0(uVar5,pcVar9);
                                  if (cVar2 == '\0') {
                                    pcVar9 = s_color_009b0678;
                                    uVar5 = FUN_00405d30(0);
                                    cVar2 = FUN_004036a0(uVar5,pcVar9);
                                    if (cVar2 == '\0') {
                                      pcVar9 = s_scale_009b0680;
                                      uVar5 = FUN_00405d30(0);
                                      cVar2 = FUN_004036a0(uVar5,pcVar9);
                                      if (cVar2 == '\0') {
                                        pcVar9 = s_alpha_009b0688;
                                        uVar5 = FUN_00405d30(0);
                                        cVar2 = FUN_004036a0(uVar5,pcVar9);
                                        if (cVar2 == '\0') {
                                          pcVar9 = s_rotation_009b0690;
                                          uVar5 = FUN_00405d30(0);
                                          cVar2 = FUN_004036a0(uVar5,pcVar9);
                                          if (cVar2 == '\0') {
                                            pcVar9 = s_position_009b069c;
                                            uVar5 = FUN_00405d30(0);
                                            cVar2 = FUN_004036a0(uVar5,pcVar9);
                                            if (cVar2 == '\0') {
                                              pcVar9 = s_bone_animation_009b06a8;
                                              uVar5 = FUN_00405d30(0);
                                              cVar2 = FUN_004036a0(uVar5,pcVar9);
                                              if (cVar2 != '\0') {
                                                iVar6 = *DAT_00b5a7e4;
                                                uVar5 = FUN_00405d30(1);
                                                uVar5 = (**(code **)(iVar6 + 4))(uVar5);
                                                **(undefined4 **)(puVar7 + 0x34) = uVar5;
                                                uVar5 = FUN_00405d30(2);
                                                FUN_00401660(uVar5,0,0xffffffff);
                                                uVar5 = FUN_00405d30(3);
                                                FUN_00401660(uVar5,0,0xffffffff);
                                                uVar5 = FUN_00405d30(4);
                                                uVar3 = thunk_FUN_00796f50(uVar5);
                                                *(undefined1 *)(*(int *)(puVar7 + 0x34) + 0x3c) =
                                                     uVar3;
                                                uVar5 = FUN_00405d30(5);
                                                uVar5 = thunk_FUN_00796fb0(uVar5);
                                                *(undefined4 *)(*(int *)(puVar7 + 0x34) + 0x40) =
                                                     uVar5;
                                                uVar5 = FUN_00405d30(6);
                                                uVar5 = thunk_FUN_00796fb0(uVar5);
                                                *(undefined4 *)(*(int *)(puVar7 + 0x34) + 0x44) =
                                                     uVar5;
                                              }
                                              local_4 = 0;
                                              FUN_00406250();
                                            }
                                            else {
                                              FUN_004be740(local_48,1,puVar7 + 0xa8);
                                              local_4 = 0;
                                              FUN_00406250();
                                            }
                                          }
                                          else {
                                            FUN_004bea70(local_48,1,puVar7 + 0x38);
                                            local_4 = 0;
                                            FUN_00406250();
                                          }
                                        }
                                        else {
                                          FUN_004bea70(local_48,1,puVar7 + 0x50);
                                          local_4 = 0;
                                          FUN_00406250();
                                        }
                                      }
                                      else {
                                        FUN_004be740(local_48,1,puVar7 + 0x68);
                                        local_4 = 0;
                                        FUN_00406250();
                                      }
                                    }
                                    else {
                                      FUN_004be740(local_48,1,puVar7 + 0x88);
                                      local_4 = 0;
                                      FUN_00406250();
                                    }
                                  }
                                  else {
                                    uVar5 = FUN_00405d30(1);
                                    fVar8 = (float10)thunk_FUN_00796ec0(uVar5);
                                    fStack_54 = (float)fVar8;
                                    uVar5 = FUN_00405d30(2);
                                    fVar8 = (float10)thunk_FUN_00796ec0(uVar5);
                                    fStack_50 = (float)fVar8;
                                    uVar5 = FUN_00405d30(3);
                                    fVar8 = (float10)thunk_FUN_00796ec0(uVar5);
                                    fStack_4c = (float)fVar8;
                                    *(float *)(puVar7 + 0x24) = fStack_54;
                                    *(float *)(puVar7 + 0x28) = fStack_50;
                                    *(float *)(puVar7 + 0x2c) = fStack_4c;
                                    local_4 = 0;
                                    FUN_00406250();
                                  }
                                }
                                else {
                                  uVar5 = FUN_00405d30(1);
                                  fVar8 = (float10)thunk_FUN_00796ec0(uVar5);
                                  fStack_60 = (float)fVar8;
                                  uVar5 = FUN_00405d30(2);
                                  fVar8 = (float10)thunk_FUN_00796ec0(uVar5);
                                  fStack_5c = (float)fVar8;
                                  uVar5 = FUN_00405d30(3);
                                  fVar8 = (float10)thunk_FUN_00796ec0(uVar5);
                                  fStack_58 = (float)fVar8;
                                  *(float *)(puVar7 + 0x18) = fStack_60;
                                  *(float *)(puVar7 + 0x1c) = fStack_5c;
                                  *(float *)(puVar7 + 0x20) = fStack_58;
                                  local_4 = 0;
                                  FUN_00406250();
                                }
                              }
                              else {
                                uVar5 = FUN_00405d30(1);
                                uVar5 = thunk_FUN_00796e60(uVar5);
                                *(undefined4 *)(puVar7 + 0x14) = uVar5;
                                local_4 = 0;
                                FUN_00406250();
                              }
                            }
                            else {
                              uVar5 = FUN_00405d30(1);
                              uVar5 = thunk_FUN_00796e60(uVar5);
                              *(undefined4 *)(puVar7 + 0xc) = uVar5;
                              uVar5 = FUN_00405d30(2);
                              uVar5 = thunk_FUN_00796e60(uVar5);
                              *(undefined4 *)(puVar7 + 0x10) = uVar5;
                              local_4 = 0;
                              FUN_00406250();
                            }
                          }
                          else {
                            uVar5 = FUN_00405d30(1);
                            uVar5 = thunk_FUN_00796e60(uVar5);
                            *(undefined4 *)(puVar7 + 4) = uVar5;
                            local_4 = 0;
                            FUN_00406250();
                          }
                        }
                        else {
                          uVar5 = FUN_00405d30(1);
                          uVar3 = thunk_FUN_00796fe0(uVar5);
                          puVar7[0x32] = uVar3;
                          local_4 = 0;
                          FUN_00406250();
                        }
                      }
                      else {
                        uVar5 = FUN_00405d30(1);
                        uVar3 = thunk_FUN_00796fe0(uVar5);
                        puVar7[0x31] = uVar3;
                        local_4 = 0;
                        FUN_00406250();
                      }
                    }
                    else {
                      uVar5 = FUN_00405d30(1);
                      uVar3 = thunk_FUN_00796fe0(uVar5);
                      puVar7[0x30] = uVar3;
                      local_4 = 0;
                      FUN_00406250();
                    }
                  }
                  else {
                    uVar5 = FUN_00405d30(1);
                    uVar3 = thunk_FUN_00796fe0(uVar5);
                    *puVar7 = uVar3;
                    local_4 = 0;
                    FUN_00406250();
                  }
                }
              }
              else {
                uVar5 = FUN_00405d30(1);
                FUN_00401660(uVar5,0,0xffffffff);
                local_4 = 0;
                FUN_00406250();
              }
            }
            else {
              uVar5 = FUN_00405d30(1);
              uVar5 = thunk_FUN_00796e60(uVar5);
              *param_4 = uVar5;
              local_4 = 0;
              FUN_00406250();
            }
          }
        }
      }
      *param_2 = *param_2 + 1;
      uVar4 = FUN_00411430();
    } while (*param_2 < uVar4);
  }
  if (local_34 == (void *)0x0) {
    ExceptionList = local_c;
    return;
  }
  _free(local_34);
  return;
}


// ==== FUN_004bfac0 @ 0x004bfac0 ====

/* WARNING: Removing unreachable block (ram,0x004bfd01) */

void FUN_004bfac0(undefined4 param_1,uint *param_2,int param_3)

{
  code *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int local_88;
  int local_84;
  int local_80 [2];
  undefined1 local_78 [4];
  void *local_74;
  int local_70;
  undefined4 local_6c;
  int local_68;
  void *local_64;
  void *local_60;
  undefined4 local_54;
  uint local_50;
  uint local_4c;
  void *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  void *local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009805e0;
  local_c = ExceptionList;
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  local_18 = (void *)0x0;
  local_14 = 0;
  local_10 = 0;
  local_4 = 1;
  local_88 = 0;
  ExceptionList = &local_c;
  uVar2 = FUN_00411430();
  if (*param_2 < uVar2) {
    do {
      uVar3 = FUN_00411510(*param_2);
      local_74 = (void *)0x0;
      local_70 = 0;
      local_6c = 0;
      local_4._0_1_ = 2;
      FUN_00405670(uVar3,local_78);
      if ((local_74 == (void *)0x0) ||
         (iVar4 = local_70 - (int)local_74 >> 0x1f,
         (local_70 - (int)local_74) / 0x1c + iVar4 == iVar4)) {
        local_4 = CONCAT31(local_4._1_3_,1);
        if (local_74 != (void *)0x0) {
          FUN_00405de0(local_74,local_70,local_78,local_84);
          goto LAB_004bfc76;
        }
      }
      else {
        iVar4 = FUN_00403620(0,*(undefined4 *)((int)local_74 + 0x14),s_<scene>_009b0560,7);
        if (iVar4 == 0) {
          FUN_004bf020(param_1,param_2,local_38,&local_88);
          local_4 = CONCAT31(local_4._1_3_,1);
          if (local_74 != (void *)0x0) {
LAB_004bfc60:
            FUN_00405de0(local_74,local_70,local_78,local_84);
LAB_004bfc76:
            _free(local_74);
            return;
          }
        }
        else {
          if ((local_74 == (void *)0x0) ||
             (local_80[0] = (local_70 - (int)local_74) / 0x1c, local_80[0] == 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar4 = FUN_00403620(0,*(undefined4 *)((int)local_74 + 0x14),s_<_scene>_009b0568,8);
          if (iVar4 == 0) {
            iVar4 = *(int *)(param_3 + 0x34);
            piVar5 = (int *)FUN_005babb0(local_80,&local_88);
            if (*piVar5 != iVar4) {
              local_50 = 0xf;
              local_54 = 0;
              local_64 = (void *)((uint)local_64._1_3_ << 8);
              FUN_00401740(s_o_effectDesc_mapScenes_find__dwS_009b0578,0x48);
              local_4._0_1_ = 3;
              FUN_00406880(&local_68);
              local_4 = CONCAT31(local_4._1_3_,2);
              if (local_50 < 0x10) {
                pcVar1 = (code *)swi(3);
                (*pcVar1)();
                return;
              }
              _free(local_64);
              return;
            }
            if (local_88 == 0) {
              local_50 = 0xf;
              local_54 = 0;
              local_64 = (void *)((uint)local_64._1_3_ << 8);
              FUN_00401740(s_dwSceneId____0_009b05c4,0xe);
              local_4._0_1_ = 4;
              FUN_00406880(&local_68);
              local_4 = CONCAT31(local_4._1_3_,2);
              if (local_50 < 0x10) {
                pcVar1 = (code *)swi(3);
                (*pcVar1)();
                return;
              }
              _free(local_64);
              return;
            }
            local_68 = local_88;
            FUN_004c18d0(local_38);
            local_4 = CONCAT31(local_4._1_3_,5);
            FUN_004c27c0(local_80,&local_68);
            if (local_44 != (void *)0x0) {
              _free(local_44);
              return;
            }
            local_44 = (void *)0x0;
            local_40 = 0;
            local_3c = 0;
            if (0xf < local_4c) {
              _free(local_60);
              return;
            }
            if (local_74 != (void *)0x0) {
              FUN_00405de0(local_74,local_70,local_78,local_80[0]);
              _free(local_74);
              return;
            }
            break;
          }
          local_4 = CONCAT31(local_4._1_3_,1);
          if (local_74 != (void *)0x0) {
            local_84 = local_80[0];
            goto LAB_004bfc60;
          }
        }
      }
      *param_2 = *param_2 + 1;
      local_74 = (void *)0x0;
      local_70 = 0;
      local_6c = 0;
      uVar2 = FUN_00411430();
    } while (*param_2 < uVar2);
  }
  if (local_18 != (void *)0x0) {
    _free(local_18);
    return;
  }
  local_18 = (void *)0x0;
  local_14 = 0;
  local_10 = 0;
  if (local_20 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_34);
  return;
}


// ==== FUN_004bfe80 @ 0x004bfe80 ====

/* WARNING: Removing unreachable block (ram,0x004c0202) */

void FUN_004bfe80(undefined4 param_1,uint *param_2,int param_3)

{
  code *pcVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  float10 fVar7;
  undefined *puVar8;
  char *pcVar9;
  undefined1 local_c4 [4];
  void *local_c0;
  int local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  int local_b0 [3];
  undefined1 local_a4 [28];
  float local_88;
  undefined1 local_68 [4];
  void *local_64;
  uint local_50;
  undefined2 local_4c [32];
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00980610;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_004c2910();
  local_4 = 0;
  local_b4 = 0;
  uVar3 = FUN_00411430();
  if (*param_2 < uVar3) {
    do {
      uVar4 = FUN_00411510(*param_2);
      local_c0 = (void *)0x0;
      local_bc = 0;
      local_b8 = 0;
      local_4._0_1_ = 1;
      FUN_00405670(uVar4,local_c4);
      if (((local_c0 == (void *)0x0) ||
          (iVar5 = local_bc - (int)local_c0 >> 0x1f,
          (local_bc - (int)local_c0) / 0x1c + iVar5 == iVar5)) ||
         (iVar5 = FUN_00403620(0,*(undefined4 *)((int)local_c0 + 0x14),&DAT_009b04d4,1), iVar5 == 0)
         ) {
        local_4 = (uint)local_4._1_3_ << 8;
        if (local_c0 != (void *)0x0) {
          FUN_00405de0(local_c0,local_bc,local_c4,local_b0[0]);
LAB_004c01ad:
          _free(local_c0);
          return;
        }
LAB_004c01b5:
        local_c0 = (void *)0x0;
        local_bc = 0;
        local_b8 = 0;
      }
      else {
        if ((local_c0 == (void *)0x0) ||
           (local_b0[0] = (local_bc - (int)local_c0) / 0x1c, local_b0[0] == 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        iVar5 = FUN_00403620(0,*(undefined4 *)((int)local_c0 + 0x14),s_<effect>_009b04d8,8);
        if (iVar5 == 0) {
          local_88 = 0.0;
          local_4 = (uint)local_4._1_3_ << 8;
          if (local_c0 != (void *)0x0) {
            FUN_00405de0(local_c0,local_bc,local_c4,local_b0[0]);
            goto LAB_004c01ad;
          }
          goto LAB_004c01b5;
        }
        if ((local_c0 == (void *)0x0) ||
           (local_b0[0] = (local_bc - (int)local_c0) / 0x1c, local_b0[0] == 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        iVar5 = FUN_00403620(0,*(undefined4 *)((int)local_c0 + 0x14),s_<_effect>_009b04e4,9);
        if (iVar5 == 0) {
          iVar5 = *(int *)(param_3 + 4);
          piVar6 = (int *)FUN_00824c20(local_b0,&local_b4);
          if (*piVar6 != iVar5) {
            FUN_00401830(s_i_mapEffect_find__wEffectId______009b04f0);
            local_4._0_1_ = 2;
            FUN_00406880(local_68);
            local_4 = CONCAT31(local_4._1_3_,1);
            if (local_50 < 0x10) {
              pcVar1 = (code *)swi(3);
              (*pcVar1)();
              return;
            }
            _free(local_64);
            return;
          }
          local_4c[0] = (undefined2)local_b4;
          FUN_004c2a30(local_a4);
          local_4._0_1_ = 3;
          FUN_004c3000(local_b0,local_4c);
          local_4 = CONCAT31(local_4._1_3_,1);
          FUN_004c2990();
          FUN_00406250();
          break;
        }
        if ((local_c0 == (void *)0x0) ||
           (local_b0[0] = (local_bc - (int)local_c0) / 0x1c, local_b0[0] == 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        iVar5 = FUN_00403620(0,*(undefined4 *)((int)local_c0 + 0x14),&DAT_009b0524,2);
        if (iVar5 == 0) {
          uVar4 = FUN_00405d30(1);
          local_b4 = thunk_FUN_00796f80(uVar4);
          local_4 = (uint)local_4._1_3_ << 8;
          FUN_00406250();
        }
        else {
          puVar8 = &DAT_009b0528;
          uVar4 = FUN_00405d30(0);
          cVar2 = FUN_004036a0(uVar4,puVar8);
          if (cVar2 == '\0') {
            pcVar9 = s_culldist_009b0530;
            uVar4 = FUN_00405d30(0);
            cVar2 = FUN_004036a0(uVar4,pcVar9);
            if (cVar2 == '\0') {
              pcVar9 = s_<scene>_009b053c;
              uVar4 = FUN_00405d30(0);
              cVar2 = FUN_004036a0(uVar4,pcVar9);
              if (cVar2 == '\0') {
                pcVar9 = s_<list>_009b0544;
                uVar4 = FUN_00405d30(0);
                cVar2 = FUN_004036a0(uVar4,pcVar9);
                if (cVar2 != '\0') {
                  FUN_004bece0(param_1,param_2,local_a4);
                }
                local_4 = (uint)local_4._1_3_ << 8;
                FUN_00406250();
              }
              else {
                FUN_004bfac0(param_1,param_2,local_a4);
                local_4 = (uint)local_4._1_3_ << 8;
                FUN_00406250();
              }
            }
            else {
              uVar4 = FUN_00405d30(1);
              fVar7 = (float10)thunk_FUN_00796ec0(uVar4);
              local_88 = (float)fVar7;
              local_4 = (uint)local_4._1_3_ << 8;
              FUN_00406250();
            }
          }
          else {
            uVar4 = FUN_00405d30(1);
            FUN_00401660(uVar4,0,0xffffffff);
            local_4 = (uint)local_4._1_3_ << 8;
            FUN_00406250();
          }
        }
      }
      *param_2 = *param_2 + 1;
      uVar3 = FUN_00411430();
    } while (*param_2 < uVar3);
  }
  local_4 = 0xffffffff;
  FUN_004c2990();
  ExceptionList = pvStack_c;
  return;
}


