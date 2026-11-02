// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x420000-0x42ffff

// ==== FUN_00420050 @ 0x00420050 ====

void FUN_00420050(void *param_1)

{
  if (*(char *)((int)param_1 + 0x81) == '\0') {
    FUN_00420050(*(undefined4 *)((int)param_1 + 8));
    FUN_0041eaa0();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004200a0 @ 0x004200a0 ====

void FUN_004200a0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x71) == '\0') {
    FUN_004200a0(*(undefined4 *)((int)param_1 + 8));
    FUN_0041eac0();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004200e0 @ 0x004200e0 ====

void FUN_004200e0(uint param_1,undefined1 param_2)

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
    FUN_0041f4e0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_00420150 @ 0x00420150 ====

void FUN_00420150(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00979828;
  local_c = ExceptionList;
  if (0x234f72a < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_0041f720(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x80);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x80) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x20] == '\0') {
LAB_0042024f:
        *(undefined1 *)(*piVar5 + 0x80) = 1;
        *(undefined1 *)(piVar6 + 0x20) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x80) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0041e2a0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x80) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x80) = 0;
        FUN_0041e300(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x20] == '\0') goto LAB_0042024f;
      if (piVar7 == (int *)*piVar2) {
        FUN_0041e300(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x80) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x80) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x81) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x80);
  } while( true );
}


// ==== FUN_00420360 @ 0x00420360 ====

void FUN_00420360(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00979828;
  local_c = ExceptionList;
  if (0x28f5c26 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_0041f7b0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x70);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x70) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x1c] == '\0') {
LAB_00420459:
        *(undefined1 *)(*piVar5 + 0x70) = 1;
        *(undefined1 *)(piVar6 + 0x1c) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x70) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0041e360(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x70) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x70) = 0;
        FUN_0041e3b0(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x1c] == '\0') goto LAB_00420459;
      if (piVar7 == (int *)*piVar2) {
        FUN_0041e3b0(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x70) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x70) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x71) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x70);
  } while( true );
}


// ==== FUN_00420540 @ 0x00420540 ====

undefined4 *
FUN_00420540(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 *param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009797f1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x130);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    *(undefined2 *)(puVar1 + 3) = *param_4;
    FUN_0041f240(param_4 + 2);
    *(undefined1 *)(puVar1 + 0x4b) = param_5;
    *(undefined1 *)((int)puVar1 + 0x12d) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@004205d1 @ 0x004205d1 ====

void Catch_004205d1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004205f0 @ 0x004205f0 ====

void * FUN_004205f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00979811;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x180);
  local_8 = 1;
  if (pvVar1 != (void *)0x0) {
    FUN_0041ffe0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00420665 @ 0x00420665 ====

void Catch_00420665(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00420680 @ 0x00420680 ====

/* WARNING: Removing unreachable block (ram,0x004207a9) */
/* WARNING: Removing unreachable block (ram,0x004207b9) */
/* WARNING: Removing unreachable block (ram,0x004207c5) */
/* WARNING: Removing unreachable block (ram,0x004207c8) */
/* WARNING: Removing unreachable block (ram,0x004207b5) */
/* WARNING: Removing unreachable block (ram,0x004207d6) */
/* WARNING: Removing unreachable block (ram,0x004207e3) */
/* WARNING: Removing unreachable block (ram,0x004207ee) */
/* WARNING: Removing unreachable block (ram,0x004207ea) */
/* WARNING: Removing unreachable block (ram,0x004207de) */
/* WARNING: Removing unreachable block (ram,0x004207f1) */

void FUN_00420680(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00979828;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x12d) != '\0') {
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
  FUN_0041e0c0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x12d) == '\0') {
    if (*(char *)(param_2[2] + 0x12d) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x12d) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x12d) == '\0') {
      piVar3 = (int *)FUN_0041deb0(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x12d) == '\0') {
      uVar4 = FUN_0041ded0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0x4b] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x4b] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x4b] == '\0') {
            *(undefined1 *)(piVar5 + 0x4b) = 1;
            *(undefined1 *)(piVar3 + 0x4b) = 0;
            FUN_0041e120(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x12d) == '\0') {
            if ((*(char *)(*piVar5 + 300) == '\x01') && (*(char *)(piVar5[2] + 300) == '\x01'))
            goto LAB_0042091b;
            if (*(char *)(piVar5[2] + 300) == '\x01') {
              *(undefined1 *)(*piVar5 + 300) = 1;
              *(undefined1 *)(piVar5 + 0x4b) = 0;
              FUN_0041e180(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0x4b) = (char)piVar3[0x4b];
            *(undefined1 *)(piVar3 + 0x4b) = 1;
            *(undefined1 *)(piVar5[2] + 300) = 1;
            FUN_0041e120(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0x4b] == '\0') {
            *(undefined1 *)(piVar5 + 0x4b) = 1;
            *(undefined1 *)(piVar3 + 0x4b) = 0;
            FUN_0041e180(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x12d) == '\0') {
            if ((*(char *)(piVar5[2] + 300) != '\x01') || (*(char *)(*piVar5 + 300) != '\x01')) {
              if (*(char *)(*piVar5 + 300) == '\x01') {
                *(undefined1 *)(piVar5[2] + 300) = 1;
                *(undefined1 *)(piVar5 + 0x4b) = 0;
                FUN_0041e120(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0x4b) = (char)piVar3[0x4b];
              *(undefined1 *)(piVar3 + 0x4b) = 1;
              *(undefined1 *)(*piVar5 + 300) = 1;
              FUN_0041e180(piVar3);
              break;
            }
LAB_0042091b:
            *(undefined1 *)(piVar5 + 0x4b) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x4b) = 1;
  }
  FUN_0041eb50();
  _free(param_2);
  return;
}


// ==== FUN_004209d0 @ 0x004209d0 ====

/* WARNING: Removing unreachable block (ram,0x00420af9) */
/* WARNING: Removing unreachable block (ram,0x00420b09) */
/* WARNING: Removing unreachable block (ram,0x00420b15) */
/* WARNING: Removing unreachable block (ram,0x00420b18) */
/* WARNING: Removing unreachable block (ram,0x00420b05) */
/* WARNING: Removing unreachable block (ram,0x00420b26) */
/* WARNING: Removing unreachable block (ram,0x00420b33) */
/* WARNING: Removing unreachable block (ram,0x00420b3e) */
/* WARNING: Removing unreachable block (ram,0x00420b3a) */
/* WARNING: Removing unreachable block (ram,0x00420b2e) */
/* WARNING: Removing unreachable block (ram,0x00420b41) */

void FUN_004209d0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00979828;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x17d) != '\0') {
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
  FUN_0041dfb0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x17d) == '\0') {
    if (*(char *)(param_2[2] + 0x17d) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x17d) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x17d) == '\0') {
      piVar3 = (int *)FUN_0041df10(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x17d) == '\0') {
      uVar4 = FUN_0041def0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0x5f] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x5f] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x5f] == '\0') {
            *(undefined1 *)(piVar5 + 0x5f) = 1;
            *(undefined1 *)(piVar3 + 0x5f) = 0;
            FUN_0041e1e0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x17d) == '\0') {
            if ((*(char *)(*piVar5 + 0x17c) == '\x01') && (*(char *)(piVar5[2] + 0x17c) == '\x01'))
            goto LAB_00420c6b;
            if (*(char *)(piVar5[2] + 0x17c) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x17c) = 1;
              *(undefined1 *)(piVar5 + 0x5f) = 0;
              FUN_0041e240(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0x5f) = (char)piVar3[0x5f];
            *(undefined1 *)(piVar3 + 0x5f) = 1;
            *(undefined1 *)(piVar5[2] + 0x17c) = 1;
            FUN_0041e1e0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0x5f] == '\0') {
            *(undefined1 *)(piVar5 + 0x5f) = 1;
            *(undefined1 *)(piVar3 + 0x5f) = 0;
            FUN_0041e240(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x17d) == '\0') {
            if ((*(char *)(piVar5[2] + 0x17c) != '\x01') || (*(char *)(*piVar5 + 0x17c) != '\x01'))
            {
              if (*(char *)(*piVar5 + 0x17c) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x17c) = 1;
                *(undefined1 *)(piVar5 + 0x5f) = 0;
                FUN_0041e1e0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0x5f) = (char)piVar3[0x5f];
              *(undefined1 *)(piVar3 + 0x5f) = 1;
              *(undefined1 *)(*piVar5 + 0x17c) = 1;
              FUN_0041e240(piVar3);
              break;
            }
LAB_00420c6b:
            *(undefined1 *)(piVar5 + 0x5f) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x5f) = 1;
  }
  _eh_vector_destructor_iterator_(param_2 + 4,0x3c,6,FUN_0040a7d0);
  _free(param_2);
  return;
}


// ==== FUN_00420d20 @ 0x00420d20 ====

void FUN_00420d20(void *param_1)

{
  if (*(char *)((int)param_1 + 0x12d) == '\0') {
    FUN_00420d20(*(undefined4 *)((int)param_1 + 8));
    FUN_0041ed90();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00420d70 @ 0x00420d70 ====

void FUN_00420d70(void *param_1)

{
  if (*(char *)((int)param_1 + 0x17d) == '\0') {
    FUN_00420d70(*(undefined4 *)((int)param_1 + 8));
    FUN_0041eda0();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00420dc0 @ 0x00420dc0 ====

void FUN_00420dc0(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x81) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x81) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_00420150(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0041e4f0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00420150(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00420e80 @ 0x00420e80 ====

void FUN_00420e80(undefined4 *param_1,ushort *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x71) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x71) == '\0');
  }
  param_2 = (ushort *)puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_00420360(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0041e560();
  }
  if (*(ushort *)((int)param_2 + 0xc) < *puVar2) {
    puVar4 = (undefined4 *)FUN_00420360(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00420f40 @ 0x00420f40 ====

void FUN_00420f40(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00979828;
  local_c = ExceptionList;
  if (0xe38e36 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00420540(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 300);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 300) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x4b] == '\0') {
LAB_0042103f:
        *(undefined1 *)(*piVar5 + 300) = 1;
        *(undefined1 *)(piVar6 + 0x4b) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 300) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0041e120(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 300) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 300) = 0;
        FUN_0041e180(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x4b] == '\0') goto LAB_0042103f;
      if (piVar7 == (int *)*piVar2) {
        FUN_0041e180(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 300) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 300) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x12d) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 300);
  } while( true );
}


// ==== FUN_00421150 @ 0x00421150 ====

void FUN_00421150(void)

{
  int in_ECX;
  
  FUN_0041f850();
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00421170 @ 0x00421170 ====

void FUN_00421170(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00979828;
  local_c = ExceptionList;
  if (s___AVProvider_List_Goal_Map_Frame_00b21620 + 0x20 < *(char **)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004205f0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x17c);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x17c) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x5f] == '\0') {
LAB_0042126f:
        *(undefined1 *)(*piVar5 + 0x17c) = 1;
        *(undefined1 *)(piVar6 + 0x5f) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x17c) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0041e1e0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x17c) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x17c) = 0;
        FUN_0041e240(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x5f] == '\0') goto LAB_0042126f;
      if (piVar7 == (int *)*piVar2) {
        FUN_0041e240(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x17c) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x17c) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x17d) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x17c);
  } while( true );
}


// ==== FUN_00421380 @ 0x00421380 ====

void FUN_00421380(undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = param_3;
  piVar1 = *(int **)(in_ECX + 4);
  if ((param_2 == (int *)*piVar1) && (param_3 == piVar1)) {
    FUN_00420050(piVar1[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (param_2 != piVar2) {
    FUN_0041e010();
    FUN_0041f9d0(&param_3,param_2);
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_00421400 @ 0x00421400 ====

void FUN_00421400(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004200a0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x71) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x71) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x71);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x71);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x71);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x71);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_0041fd20(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004214c0 @ 0x004214c0 ====

void FUN_004214c0(undefined4 *param_1,ushort *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x12d) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x12d) == '\0');
  }
  param_2 = (ushort *)puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_00420f40(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0041e410();
  }
  if (*(ushort *)((int)param_2 + 0xc) < *puVar2) {
    puVar4 = (undefined4 *)FUN_00420f40(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00421590 @ 0x00421590 ====

void FUN_00421590(undefined4 *param_1,ushort *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x17d) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x17d) == '\0');
  }
  param_2 = (ushort *)puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_00421170(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0041e480();
  }
  if (*(ushort *)((int)param_2 + 0xc) < *puVar2) {
    puVar4 = (undefined4 *)FUN_00421170(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00421660 @ 0x00421660 ====

void FUN_00421660(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined1 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097984b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = *param_1;
  uVar1 = FUN_0041e600();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  param_1 = *(undefined1 **)(in_ECX + 8);
  local_4 = 0;
  FUN_0041f920(9,&param_1);
  *(undefined4 *)(in_ECX + 0x20) = 1;
  *(undefined4 *)(in_ECX + 0x24) = 1;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004216e0 @ 0x004216e0 ====

void FUN_004216e0(undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = param_3;
  piVar1 = *(int **)(in_ECX + 4);
  if ((param_2 == (int *)*piVar1) && (param_3 == piVar1)) {
    FUN_00420d20(piVar1[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (param_2 != piVar2) {
    FUN_0041e0c0();
    FUN_00420680(&param_3,param_2);
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_00421760 @ 0x00421760 ====

void FUN_00421760(undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = param_3;
  piVar1 = *(int **)(in_ECX + 4);
  if ((param_2 == (int *)*piVar1) && (param_3 == piVar1)) {
    FUN_00420d70(piVar1[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (param_2 != piVar2) {
    FUN_0041dfb0();
    FUN_004209d0(&param_3,param_2);
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_004217e0 @ 0x004217e0 ====

void FUN_004217e0(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x14) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    FUN_0041f850();
    _free(*(void **)(in_ECX + 8));
    return;
  }
  _free(*(void **)(in_ECX + 0x14));
  return;
}


// ==== FUN_00421820 @ 0x00421820 ====

/* WARNING: Removing unreachable block (ram,0x0042193b) */
/* WARNING: Removing unreachable block (ram,0x00421b2f) */

void FUN_00421820(int *param_1,int param_2)

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
      FUN_004200e0(iVar4 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
LAB_00421a84:
        if ((uint)piVar11[7] <= uVar9) {
          bVar15 = false;
          goto LAB_00421a94;
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
        if (iVar6 == 0) goto LAB_00421a84;
LAB_00421a94:
        if (!bVar15) {
          if (*(uint *)(param_2 + 0x18) < 0x10) {
            pbVar14 = (byte *)(param_2 + 4);
          }
          else {
            pbVar14 = *(byte **)(param_2 + 4);
          }
          uVar9 = piVar11[7];
          if (uVar9 == 0) goto LAB_00421b5c;
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
          goto code_r0x00421b4f;
        }
      }
    } while (piVar11 != *(int **)(*(int *)(in_ECX + 0x14) + iVar4));
  }
  goto LAB_00421aa5;
  while( true ) {
    uVar7 = uVar7 - 1;
    bVar15 = *pbVar13 < *pbVar14;
    bVar16 = *pbVar13 == *pbVar14;
    pbVar13 = pbVar13 + 1;
    pbVar14 = pbVar14 + 1;
    if (!bVar16) break;
code_r0x00421b4f:
    if (uVar7 == 0) break;
  }
  if (!bVar16) {
    iVar6 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
  }
  bVar15 = iVar6 < 0;
  if (iVar6 == 0) {
LAB_00421b5c:
    if (uVar5 <= uVar9) {
      bVar15 = false;
      goto LAB_00421b6d;
    }
  }
  else {
LAB_00421b6d:
    if (!bVar15) {
      *param_1 = (int)piVar11;
      *(undefined1 *)(param_1 + 1) = 0;
      return;
    }
  }
  piVar11 = (int *)*piVar11;
LAB_00421aa5:
  iVar6 = FUN_0041f890(piVar11,piVar11[1],param_2);
  FUN_0041f2e0(1);
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


// ==== FUN_00421b90 @ 0x00421b90 ====

void FUN_00421b90(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00421400(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00421bc0 @ 0x00421bc0 ====

void FUN_00421bc0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00421380(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00421bf0 @ 0x00421bf0 ====

void FUN_00421bf0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004216e0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00421c20 @ 0x00421c20 ====

void FUN_00421c20(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00421760(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00421c50 @ 0x00421c50 ====

undefined4 FUN_00421c50(undefined4 param_1)

{
  int in_ECX;
  
  FUN_0041edc0(in_ECX + 0x144);
  return param_1;
}


// ==== FUN_00421c80 @ 0x00421c80 ====

void FUN_00421c80(byte param_1)

{
  void *in_ECX;
  
  FUN_0041d6f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00421ca0 @ 0x00421ca0 ====

void FUN_00421ca0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e2c4;
  return;
}


// ==== FUN_00421cb0 @ 0x00421cb0 ====

void FUN_00421cb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e2c4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00421cd0 @ 0x00421cd0 ====

int FUN_00421cd0(int param_1)

{
  int in_ECX;
  
  return in_ECX + 4 + param_1 * 0x28;
}


// ==== FUN_00421cf0 @ 0x00421cf0 ====

int FUN_00421cf0(int param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = param_1 * 0x28;
  FUN_0041ec50(&param_1,param_2);
  if (param_1 == *(int *)(in_ECX + iVar1 + 0xc)) {
    return 0;
  }
  return param_1 + 0x24;
}


// ==== FUN_00421d30 @ 0x00421d30 ====

int FUN_00421d30(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x210);
  if (iVar1 != 0) {
    if (param_1 < (uint)((*(int *)(in_ECX + 0x214) - iVar1) / 0x1c)) {
      return iVar1 + param_1 * 0x1c;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_00405ca0();
}


// ==== FUN_00421d80 @ 0x00421d80 ====

/* WARNING: Removing unreachable block (ram,0x00421e91) */

int FUN_00421d80(undefined1 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  undefined4 uVar5;
  int extraout_EAX_02;
  int extraout_EAX_03;
  int extraout_EAX_04;
  int extraout_EAX_05;
  int extraout_EAX_06;
  int in_ECX;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  bool bVar10;
  bool bVar11;
  undefined1 auStack_9c [4];
  undefined1 local_98;
  undefined4 local_88;
  undefined4 *local_84;
  undefined4 *****pppppuStack_80;
  undefined1 local_60 [4];
  void *local_5c;
  undefined4 local_4c;
  uint local_48;
  undefined1 local_44 [4];
  undefined4 *****local_40 [5];
  uint local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979910;
  local_c = ExceptionList;
  pppppuStack_80 = (undefined4 *****)0x0;
  local_84 = (undefined4 *)&DAT_0099e274;
  local_88 = 0x421db6;
  ExceptionList = &local_c;
  FUN_00405850();
  pppppuStack_80 = (undefined4 *****)0x0;
  local_84 = (undefined4 *)local_44;
  local_88 = 0x421dc5;
  FUN_00405b90();
  pppppuStack_80 = (undefined4 *****)0xffffffff;
  local_84 = (undefined4 *)&DAT_0099e278;
  local_4 = 0;
  local_88 = 0x421de0;
  iVar2 = FUN_00405920();
  pppppuStack_80 = (undefined4 *****)0x0;
  local_84 = &param_1;
  param_1 = (undefined1 *)CONCAT31(param_1._1_3_,0x2e);
  local_88 = 0x421e07;
  FUN_00405850();
  local_84 = (undefined4 *)local_60;
  local_88 = 0x421e1d;
  pppppuStack_80 = (undefined4 *****)(iVar2 + 1);
  FUN_00405b90();
  uVar7 = 0;
  param_1 = (undefined1 *)0x0;
  do {
    local_4._0_1_ = 1;
    pppppuStack_80 = (undefined4 *****)local_28;
    local_84 = (undefined4 *)0x421e41;
    iVar3 = FUN_004041d0();
    iVar2 = *(int *)(in_ECX + 0x210);
    local_4 = CONCAT31(local_4._1_3_,2);
    if ((iVar2 == 0) || ((uint)((*(int *)(in_ECX + 0x214) - iVar2) / 0x1c) <= param_1)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    uVar4 = *(uint *)(iVar3 + 0x14);
    if (*(uint *)(iVar3 + 0x18) < 0x10) {
      pbVar9 = (byte *)(iVar3 + 4);
    }
    else {
      pbVar9 = *(byte **)(iVar3 + 4);
    }
    uVar1 = *(uint *)(iVar2 + 0x14 + uVar7);
    if (uVar1 == 0) {
LAB_00421ec0:
      if (uVar1 < uVar4) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = (uint)(uVar1 != uVar4);
      }
      bVar10 = uVar4 == 0;
    }
    else {
      uVar6 = uVar1;
      if (uVar4 <= uVar1) {
        uVar6 = uVar4;
      }
      if (*(uint *)(iVar2 + 0x18 + uVar7) < 0x10) {
        pbVar8 = (byte *)(iVar2 + 4 + uVar7);
      }
      else {
        pbVar8 = *(byte **)(iVar2 + 4 + uVar7);
      }
      bVar10 = false;
      iVar2 = 0;
      bVar11 = true;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        bVar10 = *pbVar8 < *pbVar9;
        bVar11 = *pbVar8 == *pbVar9;
        pbVar8 = pbVar8 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar11);
      if (!bVar11) {
        iVar2 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
      }
      bVar10 = false;
      if (iVar2 == 0) goto LAB_00421ec0;
    }
    local_4._0_1_ = 1;
    if (0xf < local_10) {
      pppppuStack_80 = (undefined4 *****)0x421eef;
      _free(local_24);
      return extraout_EAX;
    }
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    if (bVar10) break;
    param_1 = (undefined1 *)((int)param_1 + 1);
    uVar7 = uVar7 + 0x1c;
  } while (uVar7 < 0x16c);
  if (param_1 == (undefined1 *)0xd) {
    if (0xf < local_48) {
      pppppuStack_80 = (undefined4 *****)0x421f45;
      _free(local_5c);
      return extraout_EAX_00;
    }
    local_48 = 0xf;
    local_4c = 0;
    local_5c = (void *)((uint)local_5c & 0xffffff00);
    if (0xf < local_2c) {
      pppppuStack_80 = (undefined4 *****)0x421f6d;
      _free(local_40[0]);
      return extraout_EAX_01;
    }
  }
  else {
    iVar2 = (int)param_1 * 0x28;
    pppppuStack_80 = (undefined4 *****)&param_1;
    local_84 = (undefined4 *)0x421fa6;
    FUN_0041ec50();
    if (param_1 != (undefined1 *)*(uint *)(in_ECX + iVar2 + 0xc)) {
      if (0xf < local_48) {
        pppppuStack_80 = (undefined4 *****)0x422086;
        _free(local_5c);
        return extraout_EAX_05;
      }
      local_48 = 0xf;
      local_4c = 0;
      local_5c = (void *)((uint)local_5c & 0xffffff00);
      if (local_2c < 0x10) {
        ExceptionList = local_c;
        return (int)param_1 + 0x24;
      }
      pppppuStack_80 = (undefined4 *****)0x4220ae;
      _free(local_40[0]);
      return extraout_EAX_06;
    }
    pppppuStack_80 = local_40[0];
    if (local_2c < 0x10) {
      pppppuStack_80 = local_40;
    }
    param_1 = auStack_9c;
    local_84 = (undefined4 *)0xf;
    local_88 = 0;
    local_98 = 0;
    FUN_00401740(s_Missing_File__s____s_0099e27c,0x14);
    uVar5 = FUN_00404230(local_28);
    local_4 = CONCAT31(local_4._1_3_,3);
    FUN_00403e50(uVar5);
    if (0xf < local_10) {
      pppppuStack_80 = (undefined4 *****)0x422026;
      _free(local_24);
      return extraout_EAX_02;
    }
    if (0xf < local_48) {
      pppppuStack_80 = (undefined4 *****)0x422039;
      _free(local_5c);
      return extraout_EAX_03;
    }
    local_48 = 0xf;
    local_4c = 0;
    local_5c = (void *)((uint)local_5c & 0xffffff00);
    if (0xf < local_2c) {
      pppppuStack_80 = (undefined4 *****)0x422059;
      _free(local_40[0]);
      return extraout_EAX_04;
    }
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_004220d0 @ 0x004220d0 ====

void FUN_004220d0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  undefined *puStack_d8;
  uint local_d4;
  undefined1 *puStack_d0;
  undefined1 local_a4 [4];
  void *local_a0;
  void *local_9c;
  undefined4 local_98;
  void *local_94;
  undefined1 local_90 [4];
  void *local_8c;
  undefined4 local_7c;
  uint local_78;
  undefined1 local_74 [4];
  void *local_70;
  void *local_6c;
  undefined4 uStack_68;
  undefined1 *local_64;
  undefined1 local_60 [4];
  void *local_5c;
  undefined4 local_4c;
  uint local_48;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097996b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00402220();
  puStack_d8 = &DAT_0099e298;
  local_4 = 0;
  FUN_00402220(&local_d4,param_1);
  puStack_d8 = (undefined *)0x0;
  FUN_004056c0(local_a4);
  local_4._0_1_ = 1;
  if ((local_a0 == (void *)0x0) || (pvVar4 = local_a0, ((int)local_9c - (int)local_a0) / 0x1c == 0))
  {
    puStack_d8 = &DAT_0099e29c;
    FUN_00402220(&local_d4,param_1);
    puStack_d8 = (undefined *)0x1;
    FUN_004056c0(local_74);
    local_94 = local_6c;
    pvVar4 = local_70;
    if (local_70 != local_6c) {
      do {
        local_4._0_1_ = 2;
        FUN_00405bd0();
        local_4._0_1_ = 3;
        FUN_00405b90();
        local_4._0_1_ = 4;
        FUN_00401660();
        local_4._0_1_ = 3;
        if (0xf < local_48) {
          _free(local_5c);
          return;
        }
        local_48 = 0xf;
        local_4c = 0;
        local_5c = (void *)((uint)local_5c & 0xffffff00);
        piVar1 = (int *)FUN_004236c0();
        iVar2 = (**(code **)(*piVar1 + 4))();
        if (*(uint *)(*(int *)(iVar2 + 0x1c) + 0xc) < 0x20031117) {
          local_d4 = local_d4 & 0xffffff00;
          FUN_00401740(s__Mesh__Version____s_0099e2a0,0x13);
          uVar3 = FUN_00404230(local_44);
          local_4._0_1_ = 5;
          FUN_00796d50(uVar3);
          local_4._0_1_ = 3;
          if (0xf < local_2c) {
            _free(local_40);
            return;
          }
          local_2c = 0xf;
          local_30 = 0;
          local_40 = (void *)((uint)local_40 & 0xffffff00);
        }
        iVar2 = (**(code **)(*piVar1 + 4))();
        *(undefined4 *)(iVar2 + 0x28) = 0;
        (**(code **)(*DAT_00b5a7cc + 0x2c))();
        local_4._0_1_ = 2;
        if (0xf < local_78) {
          _free(local_8c);
          return;
        }
        pvVar4 = (void *)((int)pvVar4 + 0x1c);
        local_78 = 0xf;
        local_7c = 0;
        local_8c = (void *)((uint)local_8c & 0xffffff00);
      } while (pvVar4 != local_94);
    }
    local_4._0_1_ = 2;
    if (local_70 != (void *)0x0) {
      FUN_00405de0();
      puStack_d0 = (undefined1 *)0x422344;
      _free(local_70);
      return;
    }
    local_70 = (void *)0x0;
    local_6c = (void *)0x0;
    uStack_68 = 0;
    if (local_a0 != (void *)0x0) {
      FUN_00405de0();
      puStack_d0 = (undefined1 *)0x42237a;
      _free(local_a0);
      return;
    }
    if (local_10 < 0x10) {
      ExceptionList = local_c;
      return;
    }
  }
  else {
    for (; pvVar4 != local_9c; pvVar4 = (void *)((int)pvVar4 + 0x1c)) {
      local_4._0_1_ = 1;
      FUN_00405bd0();
      puStack_d0 = local_90;
      local_4._0_1_ = 6;
      local_d4 = 0x4223e2;
      FUN_00402220();
      local_4._0_1_ = 8;
      if (0xf < local_2c) {
        _free(local_40);
        return;
      }
      local_2c = 0xf;
      local_30 = 0;
      local_40 = (void *)((uint)local_40 & 0xffffff00);
      local_64 = (undefined1 *)&puStack_d8;
      local_d4 = local_d4 & 0xffffff00;
      FUN_00401740(&DAT_0099e2b8,2);
      uVar3 = FUN_00404230(local_60);
      local_4._0_1_ = 9;
      FUN_00403e50(uVar3);
      local_4._0_1_ = 8;
      if (0xf < local_48) {
        _free(local_5c);
        return;
      }
      local_48 = 0xf;
      local_4c = 0;
      local_5c = (void *)((uint)local_5c & 0xffffff00);
      FUN_004220d0();
      local_4._0_1_ = 1;
      if (0xf < local_78) {
        _free(local_8c);
        return;
      }
      local_78 = 0xf;
      local_7c = 0;
      local_8c = (void *)((uint)local_8c & 0xffffff00);
    }
    local_4._0_1_ = 1;
    if (local_a0 != (void *)0x0) {
      FUN_00405de0();
      puStack_d0 = (undefined1 *)0x4224f9;
      _free(local_a0);
      return;
    }
    if (local_10 < 0x10) {
      ExceptionList = local_c;
      return;
    }
  }
  local_98 = 0;
  local_9c = (void *)0x0;
  local_a0 = (void *)0x0;
  _free(local_24);
  return;
}


// ==== FUN_00422540 @ 0x00422540 ====

void FUN_00422540(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097997d;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099e2e0;
  DAT_00b5a6d8 = 0;
  local_4 = 0;
  if (in_ECX[0x84] == 0) {
    in_ECX[0x84] = 0;
    in_ECX[0x85] = 0;
    in_ECX[0x86] = 0;
    _eh_vector_destructor_iterator_(in_ECX + 1,0x28,0xd,FUN_00423d30);
    *in_ECX = &PTR_FUN_0099e2c4;
    ExceptionList = local_c;
    return;
  }
  FUN_00405de0(in_ECX[0x84],in_ECX[0x85],in_ECX + 0x83);
  _free((void *)in_ECX[0x84]);
  return;
}


// ==== FUN_004225d0 @ 0x004225d0 ====

undefined4 * FUN_004225d0(void)

{
  undefined4 *extraout_EAX;
  undefined4 *extraout_EAX_00;
  undefined4 *extraout_EAX_01;
  undefined4 *extraout_EAX_02;
  undefined4 *extraout_EAX_03;
  undefined4 *extraout_EAX_04;
  undefined4 *extraout_EAX_05;
  undefined4 *extraout_EAX_06;
  undefined4 *extraout_EAX_07;
  undefined4 *extraout_EAX_08;
  undefined4 *extraout_EAX_09;
  undefined4 *extraout_EAX_10;
  undefined4 *extraout_EAX_11;
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00979a1b;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099e2e0;
  _eh_vector_constructor_iterator_
            (in_ECX + 1,0x28,0xd,(_func_void_void_ptr *)&LAB_00423d70,FUN_00423d30);
  in_ECX[0x84] = 0;
  in_ECX[0x85] = 0;
  in_ECX[0x86] = 0;
  local_4._0_1_ = 2;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_animal_0099e1e8,6);
  local_4._0_1_ = 3;
  FUN_00406720(local_28);
  local_4._0_1_ = 2;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_bridge_0099e1f0,6);
  local_4._0_1_ = 4;
  FUN_00406720(local_28);
  local_4._0_1_ = 2;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_00;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_building_0099e1f8,8);
  local_4._0_1_ = 5;
  FUN_00406720(local_28);
  local_4._0_1_ = 2;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_01;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_building_extra_0099e204,0xe);
  local_4._0_1_ = 6;
  FUN_00406720(local_28);
  local_4._0_1_ = 2;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_02;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_field_extra_0099e214,0xb);
  local_4._0_1_ = 7;
  FUN_00406720(local_28);
  local_4._0_1_ = 2;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_03;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_house_0099e220,5);
  local_4._0_1_ = 8;
  FUN_00406720(local_28);
  local_4._0_1_ = 2;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_04;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(&DAT_0099e228,4);
  local_4._0_1_ = 9;
  FUN_00406720(local_28);
  local_4._0_1_ = 2;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_05;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_plant_0099e230,5);
  local_4._0_1_ = 10;
  FUN_00406720(local_28);
  local_4._0_1_ = 2;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_06;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(&DAT_0099e238,4);
  local_4._0_1_ = 0xb;
  FUN_00406720(local_28);
  local_4._0_1_ = 2;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_07;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(&DAT_0099e240,4);
  local_4._0_1_ = 0xc;
  FUN_00406720(local_28);
  local_4._0_1_ = 2;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_08;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(&DAT_0099e248,4);
  local_4._0_1_ = 0xd;
  FUN_00406720(local_28);
  local_4._0_1_ = 2;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_09;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_portal_0099e250,6);
  local_4._0_1_ = 0xe;
  FUN_00406720(local_28);
  local_4._0_1_ = 2;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_10;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(&PTR_DAT_0099e258,3);
  local_4 = CONCAT31(local_4._1_3_,0xf);
  FUN_00406720(local_28);
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_11;
  }
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a6d8 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a6d8 = in_ECX;
  }
  ExceptionList = local_c;
  return in_ECX;
}


// ==== FUN_004229f0 @ 0x004229f0 ====

void FUN_004229f0(undefined1 param_1,void *param_2)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  float10 fVar5;
  uint in_stack_0000001c;
  undefined1 local_1dc [4];
  void *local_1d8;
  int local_1d4;
  undefined4 local_1d0;
  int local_1cc;
  undefined4 local_1c8;
  undefined1 local_1c4 [4];
  void *local_1c0;
  undefined4 local_1b0;
  uint local_1ac;
  undefined1 local_1a8 [4];
  void *local_1a4;
  undefined4 local_194;
  uint local_190;
  undefined1 uStack_188;
  undefined1 uStack_187;
  undefined1 uStack_186;
  undefined1 uStack_185;
  undefined1 uStack_184;
  undefined1 uStack_183;
  undefined1 uStack_182;
  undefined4 uStack_180;
  float fStack_17c;
  float fStack_178;
  float fStack_174;
  float fStack_170;
  float fStack_16c;
  undefined1 local_168 [4];
  undefined1 local_164;
  int local_154;
  undefined4 local_150;
  undefined1 local_148;
  int local_138;
  undefined4 local_134;
  undefined1 local_12c;
  undefined4 local_11c;
  undefined4 local_118;
  undefined1 local_110;
  undefined4 local_100;
  undefined4 local_fc;
  undefined1 local_f8 [4];
  void *local_f4;
  undefined4 local_e4;
  uint local_e0;
  undefined1 local_dc [4];
  void *local_d8;
  undefined4 local_c8;
  uint local_c4;
  undefined1 auStack_c0 [8];
  undefined1 auStack_b8 [4];
  void *pvStack_b4;
  undefined4 uStack_a4;
  uint uStack_a0;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00979a9b;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  uVar3 = FUN_004022a0(local_1c4,s_Object__0099e264,&param_2);
  local_4._0_1_ = 1;
  uVar3 = FUN_00402220(local_1a8,uVar3,&DAT_0099e25c);
  local_4._0_1_ = 2;
  iVar4 = FUN_00410500(uVar3);
  local_1cc = iVar4;
  if (0xf < local_190) {
    _free(local_1a4);
    return;
  }
  local_190 = 0xf;
  local_194 = 0;
  local_1a4 = (void *)((uint)local_1a4 & 0xffffff00);
  local_4 = (uint)local_4._1_3_ << 8;
  if (0xf < local_1ac) {
    _free(local_1c0);
    return;
  }
  local_1ac = 0xf;
  local_1b0 = 0;
  local_1c0 = (void *)((uint)local_1c0 & 0xffffff00);
  local_1c8 = *(undefined4 *)(iVar4 + 0x4c);
  FUN_0049d760();
  FUN_0049d780();
  cVar2 = FUN_0049d7c0();
  if (cVar2 == '\0') {
    do {
      FUN_0049d800(local_1c4);
      local_1d8 = (void *)0x0;
      local_1d4 = 0;
      local_1d0 = 0;
      local_4._0_1_ = 4;
      FUN_00404fb0(local_1c4,0x2c,local_1dc);
      if (local_1d8 == (void *)0x0) {
        local_1d8 = (void *)0x0;
        local_1d4 = 0;
        local_1d0 = 0;
        local_4 = (uint)local_4._1_3_ << 8;
        if (0xf < local_1ac) {
          _free(local_1c0);
          return;
        }
      }
      else {
        uVar1 = (local_1d4 - (int)local_1d8) / 0x1c;
        if (uVar1 < 2) {
          FUN_00405de0(local_1d8,local_1d4,local_1dc,local_1cc);
          _free(local_1d8);
          return;
        }
        local_150 = 0xf;
        local_154 = 0;
        local_164 = 0;
        local_134 = 0xf;
        local_138 = 0;
        local_148 = 0;
        local_118 = 0xf;
        local_11c = 0;
        local_12c = 0;
        local_fc = 0xf;
        local_100 = 0;
        local_110 = 0;
        local_4._0_1_ = 5;
        if (uVar1 < 2) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        local_190 = 0xf;
        local_194 = 0;
        local_1a4 = (void *)((uint)local_1a4 & 0xffffff00);
        FUN_00401660((int)local_1d8 + 0x1c,0,0xffffffff);
        local_4._0_1_ = 6;
        if ((local_1d8 == (void *)0x0) || ((uint)((local_1d4 - (int)local_1d8) / 0x1c) < 3)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        FUN_00401660((int)local_1d8 + 0x38,0,0xffffffff);
        if ((local_1d8 == (void *)0x0) || ((uint)((local_1d4 - (int)local_1d8) / 0x1c) < 4)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        FUN_00401660((int)local_1d8 + 0x54,0,0xffffffff);
        if ((local_154 != 0) && (local_138 == 0)) {
          uVar3 = FUN_004047b0(local_dc,local_168);
          local_4._0_1_ = 7;
          uVar3 = FUN_00402220(local_f8,uVar3,s__tpack_0099e26c);
          local_4._0_1_ = 8;
          FUN_00401660(uVar3,0,0xffffffff);
          if (0xf < local_e0) {
            _free(local_f4);
            return;
          }
          local_e0 = 0xf;
          local_e4 = 0;
          local_f4 = (void *)((uint)local_f4 & 0xffffff00);
          local_4._0_1_ = 6;
          if (0xf < local_c4) {
            _free(local_d8);
            return;
          }
          local_c4 = 0xf;
          local_c8 = 0;
          local_d8 = (void *)((uint)local_d8 & 0xffffff00);
        }
        if ((local_1d8 == (void *)0x0) || ((uint)((local_1d4 - (int)local_1d8) / 0x1c) < 5)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        FUN_00401660((int)local_1d8 + 0x70,0,0xffffffff);
        if ((local_1d8 == (void *)0x0) || ((uint)((local_1d4 - (int)local_1d8) / 0x1c) < 6)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        FUN_00401660((int)local_1d8 + 0x8c,0,0xffffffff);
        if ((local_1d8 == (void *)0x0) || ((uint)((local_1d4 - (int)local_1d8) / 0x1c) < 7)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        fVar5 = (float10)thunk_FUN_00796ec0((int)local_1d8 + 0xa8);
        fStack_17c = (float)fVar5;
        if ((local_1d8 == (void *)0x0) || ((uint)((local_1d4 - (int)local_1d8) / 0x1c) < 8)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        iVar4 = thunk_FUN_00796e60((int)local_1d8 + 0xc4);
        uStack_188 = iVar4 == 1;
        if ((local_1d8 == (void *)0x0) || ((uint)((local_1d4 - (int)local_1d8) / 0x1c) < 9)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        iVar4 = thunk_FUN_00796e60((int)local_1d8 + 0xe0);
        uStack_187 = iVar4 == 1;
        if ((local_1d8 == (void *)0x0) || ((uint)((local_1d4 - (int)local_1d8) / 0x1c) < 10)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uStack_185 = thunk_FUN_00796f50((int)local_1d8 + 0xfc);
        if ((local_1d8 == (void *)0x0) || ((uint)((local_1d4 - (int)local_1d8) / 0x1c) < 0xb)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uStack_184 = thunk_FUN_00796f50((int)local_1d8 + 0x118);
        if ((local_1d8 == (void *)0x0) || ((uint)((local_1d4 - (int)local_1d8) / 0x1c) < 0xc)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uStack_183 = thunk_FUN_00796f50((int)local_1d8 + 0x134);
        if ((local_1d8 == (void *)0x0) || ((uint)((local_1d4 - (int)local_1d8) / 0x1c) < 0xd)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        fVar5 = (float10)thunk_FUN_00796ec0((int)local_1d8 + 0x150);
        fStack_174 = (float)fVar5;
        if ((local_1d8 == (void *)0x0) || ((uint)((local_1d4 - (int)local_1d8) / 0x1c) < 0xe)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        fVar5 = (float10)thunk_FUN_00796ec0((int)local_1d8 + 0x16c);
        fStack_170 = (float)fVar5;
        if ((local_1d8 == (void *)0x0) || ((uint)((local_1d4 - (int)local_1d8) / 0x1c) < 0xf)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        fVar5 = (float10)thunk_FUN_00796ec0((int)local_1d8 + 0x188);
        fStack_16c = (float)fVar5;
        if ((local_1d8 == (void *)0x0) || ((uint)((local_1d4 - (int)local_1d8) / 0x1c) < 0x10)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uStack_180 = thunk_FUN_00796fb0((int)local_1d8 + 0x1a4);
        if ((local_1d8 == (void *)0x0) || ((uint)((local_1d4 - (int)local_1d8) / 0x1c) < 0x11)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        iVar4 = thunk_FUN_00796e60((int)local_1d8 + 0x1c0);
        uStack_186 = iVar4 == 1;
        if ((local_1d8 == (void *)0x0) || ((uint)((local_1d4 - (int)local_1d8) / 0x1c) < 0x12)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        fVar5 = (float10)thunk_FUN_00796ec0((int)local_1d8 + 0x1dc);
        fStack_178 = (float)fVar5;
        uStack_182 = param_1;
        uStack_a0 = 0xf;
        uStack_a4 = 0;
        pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
        FUN_00401660(local_1a8,0,0xffffffff);
        local_4._0_1_ = 9;
        FUN_00423540(&uStack_188);
        local_4._0_1_ = 10;
        FUN_00423d90(auStack_c0,auStack_b8);
        FUN_00423450();
        if (0xf < uStack_a0) {
          _free(pvStack_b4);
          return;
        }
        uStack_a0 = 0xf;
        uStack_a4 = 0;
        pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
        if (0xf < local_190) {
          _free(local_1a4);
          return;
        }
        local_190 = 0xf;
        local_194 = 0;
        local_1a4 = (void *)((uint)local_1a4 & 0xffffff00);
        FUN_00423450();
        if (local_1d8 != (void *)0x0) {
          FUN_00405de0(local_1d8,local_1d4,local_1dc,local_1cc);
          _free(local_1d8);
          return;
        }
        local_1d8 = (void *)0x0;
        local_1d4 = 0;
        local_1d0 = 0;
        local_4 = (uint)local_4._1_3_ << 8;
        if (0xf < local_1ac) {
          _free(local_1c0);
          return;
        }
      }
      local_1d0 = 0;
      local_1d4 = 0;
      local_1d8 = (void *)0x0;
      local_1ac = 0xf;
      local_1b0 = 0;
      local_1c0 = (void *)((uint)local_1c0 & 0xffffff00);
      FUN_0049d780();
      cVar2 = FUN_0049d7c0();
    } while (cVar2 == '\0');
    iVar4 = local_1cc;
  }
  (**(code **)(*DAT_00b5a7cc + 0x14))(iVar4);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00423340 @ 0x00423340 ====

void FUN_00423340(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  while ((iVar1 = *(int *)(in_ECX + 0x210), iVar1 != 0 &&
         (uVar3 < (uint)((*(int *)(in_ECX + 0x214) - iVar1) / 0x1c)))) {
    FUN_00401660(uVar2 + iVar1,0,0xffffffff);
    FUN_004229f0(uVar3);
    uVar2 = uVar2 + 0x1c;
    uVar3 = uVar3 + 1;
    if (0x16b < uVar2) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_00405ca0();
}


// ==== FUN_004233d0 @ 0x004233d0 ====

void FUN_004233d0(char *param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00405850(param_1,param_2,(int)pcVar2 - (int)(param_1 + 1));
  return;
}


// ==== FUN_00423400 @ 0x00423400 ====

void FUN_00423400(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0xb4);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  return;
}


// ==== FUN_00423420 @ 0x00423420 ====

bool FUN_00423420(int param_1,int param_2)

{
  int iVar1;
  
  if (*(uint *)(param_2 + 0x18) < 0x10) {
    iVar1 = param_2 + 4;
  }
  else {
    iVar1 = *(int *)(param_2 + 4);
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),iVar1,*(undefined4 *)(param_2 + 0x14));
  return iVar1 == 0;
}


// ==== FUN_00423450 @ 0x00423450 ====

void FUN_00423450(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x8c)) {
    _free(*(void **)(in_ECX + 0x78));
    return;
  }
  *(undefined4 *)(in_ECX + 0x8c) = 0xf;
  *(undefined4 *)(in_ECX + 0x88) = 0;
  *(undefined1 *)(in_ECX + 0x78) = 0;
  if (0xf < *(uint *)(in_ECX + 0x70)) {
    _free(*(void **)(in_ECX + 0x5c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x70) = 0xf;
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  *(undefined1 *)(in_ECX + 0x5c) = 0;
  if (0xf < *(uint *)(in_ECX + 0x54)) {
    _free(*(void **)(in_ECX + 0x40));
    return;
  }
  *(undefined4 *)(in_ECX + 0x54) = 0xf;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined1 *)(in_ECX + 0x40) = 0;
  if (*(uint *)(in_ECX + 0x38) < 0x10) {
    *(undefined4 *)(in_ECX + 0x38) = 0xf;
    *(undefined4 *)(in_ECX + 0x34) = 0;
    *(undefined1 *)(in_ECX + 0x24) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x24));
  return;
}


// ==== FUN_004234e0 @ 0x004234e0 ====

void FUN_004234e0(void)

{
  int in_ECX;
  
  FUN_00423450();
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00423510 @ 0x00423510 ====

void FUN_00423510(void)

{
  int in_ECX;
  
  FUN_00423450();
  if (*(uint *)(in_ECX + 0x20) < 0x10) {
    *(undefined4 *)(in_ECX + 0x20) = 0xf;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined1 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0xc));
  return;
}


// ==== FUN_00423540 @ 0x00423540 ====

void FUN_00423540(undefined1 *param_1)

{
  undefined1 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979881;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  in_ECX[4] = param_1[4];
  in_ECX[5] = param_1[5];
  in_ECX[6] = param_1[6];
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x38) = 0xf;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  in_ECX[0x24] = 0;
  FUN_00401660(param_1 + 0x20,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x54) = 0xf;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  local_4 = 0;
  in_ECX[0x40] = 0;
  FUN_00401660(param_1 + 0x3c,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x70) = 0xf;
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  local_4._0_1_ = 1;
  in_ECX[0x5c] = 0;
  FUN_00401660(param_1 + 0x58,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x8c) = 0xf;
  *(undefined4 *)(in_ECX + 0x88) = 0;
  local_4 = CONCAT31(local_4._1_3_,2);
  in_ECX[0x78] = 0;
  FUN_00401660(param_1 + 0x74,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00423650 @ 0x00423650 ====

void FUN_00423650(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979898;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  FUN_00423540(param_1 + 0x1c);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004236c0 @ 0x004236c0 ====

undefined4 FUN_004236c0(undefined4 param_1)

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
  puStack_8 = &LAB_009798b8;
  pvStack_c = ExceptionList;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660(param_1,0,0xffffffff);
  local_10 = (void *)0x8;
  local_4 = 0;
  uVar1 = (**(code **)(*DAT_00b5a7cc + 8))(&local_2c);
  if (local_18 < 0x10) {
    ExceptionList = local_10;
    return uVar1;
  }
  _free(local_2c);
  return extraout_EAX;
}


// ==== FUN_00423750 @ 0x00423750 ====

void FUN_00423750(uint param_1)

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
  puStack_8 = &LAB_009798d8;
  local_c = ExceptionList;
  if (0x17d05f4U - *(int *)(in_ECX + 8) < param_1) {
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


// ==== FUN_004237f0 @ 0x004237f0 ====

void FUN_004237f0(void)

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
  puStack_8 = &LAB_009798d8;
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


// ==== FUN_00423860 @ 0x00423860 ====

void FUN_00423860(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  int iVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00979ab0;
  local_10 = ExceptionList;
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
    ExceptionList = &local_10;
    if (0x3fffffffU - iVar5 < param_2) {
      ExceptionList = &local_10;
      uVar7 = FUN_004237f0();
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
      pvVar3 = operator_new(uVar2 * 4);
      local_8 = 0;
      iVar5 = FUN_0042ea40(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_0045d020(iVar5,param_2,&param_3);
      FUN_0042ea40(param_1,*(undefined4 *)(in_ECX + 8),iVar5 + param_2 * 4);
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - (int)_Memory >> 2;
      }
      if (_Memory == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 4 + (int)pvVar3);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar5) * 4);
        *(void **)(in_ECX + 4) = pvVar3;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar1 = *(int *)(in_ECX + 8);
    iVar5 = param_2 * 4;
    if ((uint)(iVar1 - param_1 >> 2) < param_2) {
      FUN_0042ea40(param_1,iVar1,iVar5 + param_1);
      local_8 = 2;
      FUN_0041ea60(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&param_3);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar5;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + param_2 * -4,&param_3);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar1 + param_2 * -4;
    uVar4 = FUN_0042ea40(iVar6,iVar1,iVar1);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_0056bf90(param_1,iVar6,iVar1);
    FUN_008335f0(param_1,iVar5 + param_1,&param_3);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004239c9 @ 0x004239c9 ====

void Catch_004239c9(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00423aa0 @ 0x00423aa0 ====

void FUN_00423aa0(void)

{
  undefined4 *puVar1;
  void *_Memory;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 4);
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  if (_Memory == *(void **)(in_ECX + 4)) {
    return;
  }
  FUN_00423510();
  _free(_Memory);
  return;
}


// ==== FUN_00423ae0 @ 0x00423ae0 ====

undefined4 * FUN_00423ae0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00979ad1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0xb4);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_2;
    *puVar1 = param_1;
    FUN_00423650(param_3);
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@00423b51 @ 0x00423b51 ====

void Catch_00423b51(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00423b70 @ 0x00423b70 ====

void FUN_00423b70(uint param_1,undefined4 param_2)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00979ae0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 != 0) {
    uVar1 = param_1;
    if (0x3fffffff < param_1) {
      uVar1 = FUN_004237f0();
    }
    uVar1 = uVar1 * 4;
    pvVar2 = operator_new(uVar1);
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 + (int)pvVar2);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    local_8 = 0;
    FUN_0045d020(pvVar2,param_1,param_2);
    *(void **)(in_ECX + 8) = (void *)(uVar1 + (int)pvVar2);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00423c06 @ 0x00423c06 ====

void Catch_00423c06(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00423c20 @ 0x00423c20 ====

void FUN_00423c20(uint param_1,undefined1 param_2)

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
    FUN_00423860(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_00423c90 @ 0x00423c90 ====

void FUN_00423c90(void)

{
  int in_ECX;
  
  FUN_00423aa0();
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00423cb0 @ 0x00423cb0 ====

void FUN_00423cb0(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined1 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979afb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = *param_1;
  uVar1 = FUN_00423400();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  param_1 = *(undefined1 **)(in_ECX + 8);
  local_4 = 0;
  FUN_00423b70(9,&param_1);
  *(undefined4 *)(in_ECX + 0x20) = 1;
  *(undefined4 *)(in_ECX + 0x24) = 1;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00423d30 @ 0x00423d30 ====

void FUN_00423d30(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x14) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    FUN_00423aa0();
    _free(*(void **)(in_ECX + 8));
    return;
  }
  _free(*(void **)(in_ECX + 0x14));
  return;
}


// ==== FUN_00423d90 @ 0x00423d90 ====

/* WARNING: Removing unreachable block (ram,0x00423eab) */
/* WARNING: Removing unreachable block (ram,0x0042409f) */

void FUN_00423d90(int *param_1,int param_2)

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
      FUN_00423c20(iVar4 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
LAB_00423ff4:
        if ((uint)piVar11[7] <= uVar9) {
          bVar15 = false;
          goto LAB_00424004;
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
        if (iVar6 == 0) goto LAB_00423ff4;
LAB_00424004:
        if (!bVar15) {
          if (*(uint *)(param_2 + 0x18) < 0x10) {
            pbVar14 = (byte *)(param_2 + 4);
          }
          else {
            pbVar14 = *(byte **)(param_2 + 4);
          }
          uVar9 = piVar11[7];
          if (uVar9 == 0) goto LAB_004240cc;
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
          goto code_r0x004240bf;
        }
      }
    } while (piVar11 != *(int **)(*(int *)(in_ECX + 0x14) + iVar4));
  }
  goto LAB_00424015;
  while( true ) {
    uVar7 = uVar7 - 1;
    bVar15 = *pbVar13 < *pbVar14;
    bVar16 = *pbVar13 == *pbVar14;
    pbVar13 = pbVar13 + 1;
    pbVar14 = pbVar14 + 1;
    if (!bVar16) break;
code_r0x004240bf:
    if (uVar7 == 0) break;
  }
  if (!bVar16) {
    iVar6 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
  }
  bVar15 = iVar6 < 0;
  if (iVar6 == 0) {
LAB_004240cc:
    if (uVar5 <= uVar9) {
      bVar15 = false;
      goto LAB_004240dd;
    }
  }
  else {
LAB_004240dd:
    if (!bVar15) {
      *param_1 = (int)piVar11;
      *(undefined1 *)(param_1 + 1) = 0;
      return;
    }
  }
  piVar11 = (int *)*piVar11;
LAB_00424015:
  iVar6 = FUN_00423ae0(piVar11,piVar11[1],param_2);
  FUN_00423750(1);
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


// ==== FUN_00424100 @ 0x00424100 ====

void FUN_00424100(byte param_1)

{
  void *in_ECX;
  
  FUN_00422540();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00424120 @ 0x00424120 ====

void FUN_00424120(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e2fc;
  return;
}


// ==== FUN_00424130 @ 0x00424130 ====

void FUN_00424130(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e2fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00424150 @ 0x00424150 ====

void FUN_00424150(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0x10) + 4);
  piVar2 = (int *)*piVar1;
  if (piVar2 != piVar1) {
    do {
      piVar1 = piVar2 + 2;
      piVar2 = (int *)*piVar2;
      (**(code **)(*(int *)*piVar1 + 0x24))();
    } while (piVar2 != (int *)*(int *)(*(int *)(in_ECX + 0x10) + 4));
  }
  return;
}


// ==== FUN_00424180 @ 0x00424180 ====

void FUN_00424180(undefined4 *param_1)

{
  int *piVar1;
  int *_Memory;
  int in_ECX;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0x10) + 4);
  _Memory = (int *)*piVar1;
  if (_Memory != piVar1) {
    while (param_1 != (undefined4 *)_Memory[2]) {
      _Memory = (int *)*_Memory;
      if (_Memory == piVar1) {
        return;
      }
    }
    if (_Memory != *(int **)(*(int *)(in_ECX + 0x10) + 4)) {
      *(int *)_Memory[1] = *_Memory;
      *(int *)(*_Memory + 4) = _Memory[1];
      _free(_Memory);
      return;
    }
    if (param_1 != (undefined4 *)0x0) {
      (**(code **)*param_1)(1);
    }
  }
  return;
}


// ==== FUN_004241e0 @ 0x004241e0 ====

void FUN_004241e0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00979b44;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099e304;
  pvVar1 = operator_new(0xc);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    uVar2 = FUN_00415c90();
    *(undefined4 *)((int)pvVar1 + 4) = uVar2;
    *(undefined4 *)((int)pvVar1 + 8) = 0;
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[4] = pvVar1;
  pvVar1 = operator_new(8);
  local_4._0_1_ = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00443a20();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(8);
  local_4._0_1_ = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00443360();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = CONCAT31(local_4._1_3_,4);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00442f90();
  }
  in_ECX[1] = uVar2;
  DAT_00b5a7dc = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004242d0 @ 0x004242d0 ====

void FUN_004242d0(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00979b56;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099e304;
  DAT_00b5a7dc = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  _Memory = (void *)in_ECX[4];
  in_ECX[3] = 0;
  if (_Memory == (void *)0x0) {
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_0099e2fc;
    ExceptionList = pvStack_c;
    return;
  }
  FUN_008984a0();
  _free(_Memory);
  return;
}


// ==== FUN_00424370 @ 0x00424370 ====

void * FUN_00424370(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  void *pvVar3;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979b6b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_10 = operator_new(0x24);
  pvVar3 = (void *)0x0;
  local_4 = 0;
  if (local_10 != (void *)0x0) {
    pvVar3 = (void *)FUN_004441a0();
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0x10) + 4);
  local_4 = 0xffffffff;
  local_10 = pvVar3;
  iVar2 = FUN_00448300(iVar1,*(undefined4 *)(iVar1 + 4),&local_10);
  FUN_00424420(1);
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  ExceptionList = local_c;
  return pvVar3;
}


// ==== FUN_00424400 @ 0x00424400 ====

void FUN_00424400(byte param_1)

{
  void *in_ECX;
  
  FUN_004242d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00424420 @ 0x00424420 ====

void FUN_00424420(uint param_1)

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
  puStack_8 = &LAB_00979b88;
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


// ==== FUN_004244d0 @ 0x004244d0 ====

void FUN_004244d0(void)

{
  return;
}


// ==== FUN_004244e0 @ 0x004244e0 ====

undefined2 FUN_004244e0(short param_1)

{
  int in_ECX;
  
  return CONCAT11((char)((ushort)*(short *)(in_ECX + 0xe) >> 8),*(short *)(in_ECX + 0xe) == param_1)
  ;
}


// ==== FUN_004244f0 @ 0x004244f0 ====

undefined4 FUN_004244f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00424500 @ 0x00424500 ====

undefined4 FUN_00424500(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00424520 @ 0x00424520 ====

undefined2 FUN_00424520(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 6);
}


// ==== FUN_00424530 @ 0x00424530 ====

void FUN_00424530(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e314;
  return;
}


// ==== FUN_00424540 @ 0x00424540 ====

void FUN_00424540(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e314;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00424560 @ 0x00424560 ====

void FUN_00424560(void)

{
  FUN_00444710();
  return;
}


// ==== FUN_00424570 @ 0x00424570 ====

void FUN_00424570(void)

{
  FUN_00444b50();
  return;
}


// ==== FUN_00424580 @ 0x00424580 ====

void FUN_00424580(void)

{
  FUN_00444c10();
  return;
}


// ==== FUN_00424590 @ 0x00424590 ====

void FUN_00424590(void)

{
  FUN_00444db0();
  return;
}


// ==== FUN_004245a0 @ 0x004245a0 ====

undefined1 FUN_004245a0(void)

{
  return 0;
}


// ==== FUN_004245b0 @ 0x004245b0 ====

undefined4 FUN_004245b0(undefined4 param_1,undefined4 param_2)

{
  FUN_00444de0(param_1,param_2);
  return param_1;
}


// ==== FUN_004245d0 @ 0x004245d0 ====

void FUN_004245d0(void)

{
  FUN_00444e80();
  return;
}


// ==== FUN_004245e0 @ 0x004245e0 ====

void FUN_004245e0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00979bea;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099e338;
  pvVar1 = operator_new(0xc);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004457f0(param_1);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(8);
  local_4._0_1_ = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00444e50();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[6] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00444bf0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 4;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00444b30();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4._0_1_ = 5;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00445060(in_ECX);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[4] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4._0_1_ = 6;
  if (pvVar1 == (void *)0x0) {
    local_10 = 0;
  }
  else {
    local_10 = FUN_00444840(in_ECX[1],in_ECX[6]);
  }
  local_18 = in_ECX[1];
  local_14 = in_ECX[4];
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[5] = local_10;
  FUN_00444d00(&local_18);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00424750 @ 0x00424750 ====

void FUN_00424750(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00979bfc;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099e338;
  local_4 = 0;
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
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[6])(1);
  }
  in_ECX[6] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_0099e314;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00424800 @ 0x00424800 ====

void FUN_00424800(byte param_1)

{
  void *in_ECX;
  
  FUN_00424750();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00424830 @ 0x00424830 ====

void FUN_00424830(void)

{
                    /* WARNING: Could not recover jumptable at 0x00424838. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a6ac + 0x18))();
  return;
}


// ==== FUN_00424840 @ 0x00424840 ====

void FUN_00424840(void)

{
                    /* WARNING: Could not recover jumptable at 0x00424848. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a6ac + 0x1c))();
  return;
}


// ==== FUN_00424850 @ 0x00424850 ====

void FUN_00424850(char *param_1,char param_2)

{
  char cVar1;
  char *pcVar2;
  undefined1 local_428 [4];
  void *local_424;
  undefined4 local_414;
  uint local_410;
  char local_40c [1023];
  undefined1 local_d;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979c1b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  __vsnprintf(local_40c,0x3ff,param_1,&param_2);
  pcVar2 = local_40c;
  local_d = 0;
  local_410 = 0xf;
  local_414 = 0;
  local_424 = (void *)((uint)local_424 & 0xffffff00);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(local_40c,(int)pcVar2 - (int)(local_40c + 1));
  local_4 = 0;
  FUN_00796d50(local_428);
  if (local_410 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_424);
  return;
}


// ==== FUN_00424910 @ 0x00424910 ====

void FUN_00424910(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_00424930 @ 0x00424930 ====

void FUN_00424930(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[1] = param_1;
  uVar1 = FUN_00424a70(param_1);
  in_ECX[2] = uVar1;
  return;
}


// ==== FUN_00424960 @ 0x00424960 ====

void FUN_00424960(int param_1)

{
  undefined4 *puVar1;
  uint *in_ECX;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if (*in_ECX + param_1 <= in_ECX[1]) {
    return;
  }
  uVar3 = in_ECX[1];
  in_ECX[1] = uVar3 * 2;
  puVar1 = (undefined4 *)FUN_00424a70(uVar3 * 2);
  uVar3 = *in_ECX;
  puVar4 = (undefined4 *)in_ECX[2];
  for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar1 = puVar1 + 1;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar1 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_004249c0 @ 0x004249c0 ====

void FUN_004249c0(undefined4 *param_1,uint param_2)

{
  int *in_ECX;
  uint uVar1;
  undefined4 *puVar2;
  
  FUN_00424960(param_2);
  puVar2 = (undefined4 *)(in_ECX[2] + *in_ECX);
  for (uVar1 = param_2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  for (uVar1 = param_2 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)puVar2 = *(undefined1 *)param_1;
    param_1 = (undefined4 *)((int)param_1 + 1);
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  *in_ECX = *in_ECX + param_2;
  return;
}


// ==== FUN_00424a00 @ 0x00424a00 ====

void FUN_00424a00(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int *in_ECX;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  FUN_00424960(*(int *)(param_1 + 0x14) + 4);
  uVar1 = *(undefined4 *)(param_1 + 0x14);
  FUN_00424960(4);
  *(undefined4 *)(*in_ECX + in_ECX[2]) = uVar1;
  *in_ECX = *in_ECX + 4;
  uVar2 = *(uint *)(param_1 + 0x14);
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    puVar4 = (undefined4 *)(param_1 + 4);
  }
  else {
    puVar4 = *(undefined4 **)(param_1 + 4);
  }
  FUN_00424960(uVar2);
  puVar5 = (undefined4 *)(*in_ECX + in_ECX[2]);
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  *in_ECX = *in_ECX + uVar2;
  return;
}


// ==== FUN_00424a70 @ 0x00424a70 ====

void * FUN_00424a70(uint param_1)

{
  code *pcVar1;
  void *pvVar2;
  void *extraout_EAX;
  undefined1 local_28 [4];
  void *local_24;
  void *local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00979c38;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar2 = operator_new(param_1);
  if (pvVar2 != (void *)0x0) {
    ExceptionList = local_c;
    return pvVar2;
  }
  local_10 = 0xf;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_14 = pvVar2;
  FUN_00401740(&DAT_0099e358,2);
  local_4 = pvVar2;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    pvVar2 = (void *)(*pcVar1)();
    return pvVar2;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_00424b00 @ 0x00424b00 ====

void FUN_00424b00(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  return;
}


// ==== FUN_00424b10 @ 0x00424b10 ====

void FUN_00424b10(void)

{
  return;
}


// ==== FUN_00424b20 @ 0x00424b20 ====

bool FUN_00424b20(void)

{
  int iVar1;
  
  iVar1 = FUN_00424da0();
  return iVar1 == 0;
}


// ==== FUN_00424b80 @ 0x00424b80 ====

int FUN_00424b80(int param_1)

{
  int iVar1;
  int extraout_EAX;
  char local_2d;
  undefined4 local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979c78;
  local_c = ExceptionList;
  local_2c = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(&DAT_0099e35d,0);
  local_4 = 0;
  iVar1 = FUN_00424da0();
  do {
    if (iVar1 == 0) {
LAB_00424c4d:
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
    iVar1 = FUN_00424da0();
    if (iVar1 == 0) {
      local_2c = CONCAT31(local_2c._1_3_,0xff);
    }
    else {
      FUN_00424ca0(&local_2d);
      local_2c = CONCAT31(local_2c._1_3_,local_2d);
      if (local_2d == '\r') {
        iVar1 = FUN_00424da0();
        if ((iVar1 != 0) &&
           ((iVar1 = FUN_00424da0(), iVar1 == 0 || (FUN_00424ca0(&local_2d), local_2d != '\n')))) {
          FUN_00424d50(1);
        }
        goto LAB_00424c4d;
      }
      if (local_2d == '\n') goto LAB_00424c4d;
    }
    FUN_00405ac0(1,local_2c);
    iVar1 = FUN_00424da0();
  } while( true );
}


// ==== FUN_00424ca0 @ 0x00424ca0 ====

void FUN_00424ca0(undefined1 *param_1)

{
  code *pcVar1;
  void *pvVar2;
  uint *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979c58;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = *(undefined1 *)(in_ECX[2] + *in_ECX);
  *in_ECX = *in_ECX + 1;
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


// ==== FUN_00424d30 @ 0x00424d30 ====

void FUN_00424d30(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[1] = param_2;
  in_ECX[2] = param_1;
  return;
}


// ==== FUN_00424d50 @ 0x00424d50 ====

uint FUN_00424d50(uint param_1)

{
  uint uVar1;
  uint *in_ECX;
  
  uVar1 = *in_ECX;
  if (uVar1 < param_1) {
    *in_ECX = 0;
    return uVar1;
  }
  *in_ECX = uVar1 - param_1;
  return param_1;
}


// ==== FUN_00424d90 @ 0x00424d90 ====

undefined4 FUN_00424d90(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00424da0 @ 0x00424da0 ====

int FUN_00424da0(void)

{
  int *in_ECX;
  
  return in_ECX[1] - *in_ECX;
}


// ==== FUN_00424db0 @ 0x00424db0 ====

undefined4 FUN_00424db0(void)

{
  uint *in_ECX;
  
  return CONCAT31((int3)(*in_ECX >> 8),in_ECX[1] <= *in_ECX);
}


// ==== FUN_00424dc0 @ 0x00424dc0 ====

int FUN_00424dc0(int param_1)

{
  uint uVar1;
  code *pcVar2;
  void *pvVar3;
  uint uVar4;
  int extraout_EAX;
  int iVar5;
  uint *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar3 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979c98;
  local_c = ExceptionList;
  uVar1 = *in_ECX;
  uVar4 = uVar1 + param_1;
  ExceptionList = &local_c;
  *in_ECX = uVar4;
  if (uVar4 <= in_ECX[1]) {
    ExceptionList = pvVar3;
    return in_ECX[2] + uVar1;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_m_dwCurrent_<__m_dwTotal_0099e380,0x18);
  local_4 = 0;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar2 = (code *)swi(3);
    iVar5 = (*pcVar2)();
    return iVar5;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_00424e50 @ 0x00424e50 ====

void FUN_00424e50(void)

{
  char cVar1;
  code *pcVar2;
  uint uVar3;
  char *_Memory;
  char *pcVar4;
  uint *in_ECX;
  uint uVar5;
  char *pcVar6;
  uint local_48 [2];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979cb2;
  pvStack_c = ExceptionList;
  local_48[0] = 0;
  ExceptionList = &pvStack_c;
  FUN_00424fa0(local_48);
  uVar3 = local_48[0];
  _Memory = operator_new(local_48[0] + 1);
  pcVar4 = (char *)(in_ECX[2] + *in_ECX);
  pcVar6 = _Memory;
  for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar5 = uVar3 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar6 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
  }
  *in_ECX = *in_ECX + uVar3;
  _Memory[uVar3] = '\0';
  if (in_ECX[1] < *in_ECX) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00401740(s_m_dwCurrent_<__m_dwTotal_0099e39c,0x18);
    local_4 = 0;
    FUN_00406880(local_28);
    local_4 = 0xffffffff;
    if (local_10 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_24);
    return;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = 0;
  pcVar4 = _Memory;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(_Memory,(int)pcVar4 - (int)(_Memory + 1));
  local_4 = 1;
  _free(_Memory);
  return;
}


// ==== FUN_00424fa0 @ 0x00424fa0 ====

void FUN_00424fa0(undefined4 *param_1)

{
  code *pcVar1;
  void *pvVar2;
  uint *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979cc8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = *(undefined4 *)(in_ECX[2] + *in_ECX);
  *in_ECX = *in_ECX + 4;
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


// ==== FUN_00425030 @ 0x00425030 ====

int FUN_00425030(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0xa8;
}


// ==== FUN_00425050 @ 0x00425050 ====

int FUN_00425050(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    FUN_00425e70(param_1);
    param_1 = param_1 + 0xa8;
    param_3 = param_3 + 0xa8;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_00425090 @ 0x00425090 ====

int FUN_00425090(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00979cf1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0xa8) {
    local_8 = 1;
    if (param_3 != 0) {
      FUN_00425d90(param_1);
    }
    param_3 = param_3 + 0xa8;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@004250ec @ 0x004250ec ====

void Catch_004250ec(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0xa8) {
    FUN_00412f30();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00425130 @ 0x00425130 ====

void FUN_00425130(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00979d11;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != 0) {
      FUN_00425d90(param_3);
    }
    param_1 = param_1 + 0xa8;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0042518b @ 0x0042518b ====

void Catch_0042518b(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0xa8) {
    FUN_00412f30();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004251c0 @ 0x004251c0 ====

void FUN_004251c0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00425090(param_1,param_2,param_3);
  return;
}


// ==== FUN_004251e0 @ 0x004251e0 ====

int FUN_004251e0(int param_1,int param_2,undefined4 param_3)

{
  FUN_00425130(param_1,param_2,param_3);
  return param_1 + param_2 * 0xa8;
}


// ==== FUN_00425220 @ 0x00425220 ====

void FUN_00425220(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  if (param_2 != param_3) {
    iVar2 = FUN_00425050(param_3,*(undefined4 *)(in_ECX + 8),param_2,param_2);
    iVar1 = *(int *)(in_ECX + 8);
    for (iVar3 = iVar2; iVar3 != iVar1; iVar3 = iVar3 + 0xa8) {
      FUN_00412f30();
    }
    *(int *)(in_ECX + 8) = iVar2;
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_00425280 @ 0x00425280 ====

void FUN_00425280(void)

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
  puStack_8 = &LAB_00979d28;
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


// ==== FUN_004252f0 @ 0x004252f0 ====

void FUN_004252f0(undefined4 *param_1)

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
  puStack_8 = &LAB_00979d48;
  local_c = ExceptionList;
  puVar4 = (undefined4 *)(in_ECX[2] + *in_ECX);
  ExceptionList = &local_c;
  for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *puVar4;
    puVar4 = puVar4 + 1;
    param_1 = param_1 + 1;
  }
  *in_ECX = *in_ECX + 0x60;
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


// ==== FUN_00425390 @ 0x00425390 ====

void FUN_00425390(undefined4 *param_1)

{
  code *pcVar1;
  void *pvVar2;
  undefined4 *puVar3;
  uint *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979d48;
  local_c = ExceptionList;
  puVar3 = (undefined4 *)(in_ECX[2] + *in_ECX);
  ExceptionList = &local_c;
  *param_1 = *puVar3;
  param_1[1] = puVar3[1];
  param_1[2] = puVar3[2];
  *in_ECX = *in_ECX + 0xc;
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


// ==== FUN_00425430 @ 0x00425430 ====

void FUN_00425430(undefined4 *param_1)

{
  code *pcVar1;
  void *pvVar2;
  undefined4 *puVar3;
  uint *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979d48;
  local_c = ExceptionList;
  puVar3 = (undefined4 *)(in_ECX[2] + *in_ECX);
  ExceptionList = &local_c;
  *param_1 = *puVar3;
  param_1[1] = puVar3[1];
  param_1[2] = puVar3[2];
  param_1[3] = puVar3[3];
  *in_ECX = *in_ECX + 0x10;
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


// ==== FUN_004254e0 @ 0x004254e0 ====

void FUN_004254e0(undefined4 *param_1)

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
  puStack_8 = &LAB_00979d48;
  local_c = ExceptionList;
  puVar4 = (undefined4 *)(in_ECX[2] + *in_ECX);
  ExceptionList = &local_c;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *puVar4;
    puVar4 = puVar4 + 1;
    param_1 = param_1 + 1;
  }
  *in_ECX = *in_ECX + 0x40;
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


// ==== FUN_00425580 @ 0x00425580 ====

void FUN_00425580(undefined4 *param_1)

{
  code *pcVar1;
  void *pvVar2;
  uint *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979d48;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = *(undefined4 *)(in_ECX[2] + *in_ECX);
  *in_ECX = *in_ECX + 4;
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


// ==== FUN_00425610 @ 0x00425610 ====

void FUN_00425610(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00979d60;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xa8;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_00413210(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_00425090(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0042569a @ 0x0042569a ====

void Catch_0042569a(void)

{
  FUN_00412e20();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004256b0 @ 0x004256b0 ====

void FUN_004256b0(int param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  uint uVar7;
  
  if (in_ECX == param_1) {
    return;
  }
  iVar5 = *(int *)(param_1 + 4);
  if (iVar5 != 0) {
    iVar6 = *(int *)(param_1 + 8) - iVar5;
    iVar1 = iVar6 >> 0x1f;
    iVar6 = iVar6 / 0xa8 + iVar1;
    uVar7 = iVar6 - iVar1;
    if (iVar6 != iVar1) {
      iVar1 = *(int *)(in_ECX + 4);
      if (iVar1 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(int *)(in_ECX + 8) - iVar1) / 0xa8;
      }
      if (uVar7 <= uVar3) {
        uVar4 = FUN_00425050(iVar5,*(undefined4 *)(param_1 + 8),iVar1,param_1);
        FUN_00412df0(uVar4,*(undefined4 *)(in_ECX + 8));
        iVar5 = 0;
        if (*(int *)(param_1 + 4) != 0) {
          iVar5 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xa8;
        }
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4) + iVar5 * 0xa8;
        return;
      }
      if (iVar1 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(int *)(in_ECX + 0xc) - iVar1) / 0xa8;
      }
      if (uVar7 <= uVar3) {
        iVar6 = FUN_00425030();
        iVar6 = iVar5 + iVar6 * 0xa8;
        FUN_00425050(iVar5,iVar6,iVar1,iVar6);
        uVar4 = FUN_00425090(iVar6,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar4;
        return;
      }
      if (iVar1 != 0) {
        FUN_00412df0(iVar1,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      uVar4 = FUN_00425030();
      cVar2 = FUN_00413210(uVar4);
      if (cVar2 == '\0') {
        return;
      }
      uVar4 = FUN_004251c0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar4;
      return;
    }
  }
  FUN_00412e20();
  return;
}


// ==== FUN_00425830 @ 0x00425830 ====

void FUN_00425830(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  iVar1 = param_2;
  FUN_00424a00(param_2);
  FUN_00424a00(param_2 + 0x1c);
  FUN_00424960(0xc);
  puVar3 = (undefined4 *)(param_1[2] + *param_1);
  *puVar3 = *(undefined4 *)(param_2 + 0x38);
  puVar3[1] = *(undefined4 *)(param_2 + 0x3c);
  puVar3[2] = *(undefined4 *)(param_2 + 0x40);
  *param_1 = *param_1 + 0xc;
  FUN_00424960(0x10);
  puVar3 = (undefined4 *)(param_1[2] + *param_1);
  *puVar3 = *(undefined4 *)(param_2 + 0x44);
  puVar3[1] = *(undefined4 *)(param_2 + 0x48);
  puVar3[2] = *(undefined4 *)(param_2 + 0x4c);
  puVar3[3] = *(undefined4 *)(param_2 + 0x50);
  *param_1 = *param_1 + 0x10;
  FUN_00424960(0x40);
  puVar3 = (undefined4 *)(param_2 + 0x54);
  puVar5 = (undefined4 *)(param_1[2] + *param_1);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  *param_1 = *param_1 + 0x40;
  FUN_00424960(4);
  *(undefined4 *)(param_1[2] + *param_1) = *(undefined4 *)(param_2 + 0x94);
  *param_1 = *param_1 + 4;
  uVar4 = 0;
  if (*(int *)(param_2 + 0x94) != 0) {
    param_2 = 0;
    do {
      iVar2 = *(int *)(iVar1 + 0x9c);
      if ((iVar2 == 0) || ((uint)((*(int *)(iVar1 + 0xa0) - iVar2) / 0xa8) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
        FUN_00425280();
      }
      FUN_00425830(param_1,param_2 + iVar2);
      param_2 = param_2 + 0xa8;
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(iVar1 + 0x94));
  }
  return;
}


// ==== FUN_00425950 @ 0x00425950 ====

void FUN_00425950(int *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  FUN_00424960(0x60);
  puVar2 = (undefined4 *)(in_ECX + 0xc);
  puVar3 = (undefined4 *)(param_1[2] + *param_1);
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *param_1 = *param_1 + 0x60;
  uVar4 = 0;
  if (*(int *)(in_ECX + 0x10) != 0) {
    do {
      iVar1 = *(int *)(in_ECX + 0x70);
      if ((iVar1 == 0) || ((*(int *)(in_ECX + 0x74) - iVar1) / 0xa8 == 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_00425280();
      }
      FUN_00425830(param_1,iVar1);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(in_ECX + 0x10));
  }
  return;
}


// ==== FUN_004259e0 @ 0x004259e0 ====

void FUN_004259e0(int param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  void *local_48 [4];
  undefined4 uStack_38;
  uint uStack_34;
  void *local_28 [5];
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_00979e00;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar3 = FUN_00424e50(local_28);
  puStack_8 = (undefined1 *)0x0;
  FUN_00401660(uVar3,0,0xffffffff);
  puStack_8 = (undefined1 *)0xffffffff;
  if ((void *)0xf < pvStack_14) {
    _free(local_28[0]);
    return;
  }
  uVar3 = FUN_00424e50(local_48);
  pvStack_c = (void *)0x1;
  FUN_00401660(uVar3,0,0xffffffff);
  pvStack_c = (void *)0xffffffff;
  if (0xf < uStack_34) {
    _free(local_48[0]);
    return;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  local_48[0] = (void *)((uint)local_48[0] & 0xffffff00);
  FUN_00425390(param_1 + 0x38);
  FUN_00425430(param_1 + 0x44);
  FUN_004254e0(param_1 + 0x54);
  puVar1 = (uint *)(param_1 + 0x94);
  FUN_00425580(puVar1);
  FUN_00426380(*puVar1);
  uVar4 = 0;
  if (*puVar1 != 0) {
    iStack_4 = 0;
    do {
      iVar2 = *(int *)(param_1 + 0x9c);
      if ((iVar2 == 0) || ((uint)((*(int *)(param_1 + 0xa0) - iVar2) / 0xa8) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
        FUN_00425280();
      }
      FUN_004259e0(param_1,iStack_4 + iVar2);
      iStack_4 = iStack_4 + 0xa8;
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar1);
  }
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_00425b50 @ 0x00425b50 ====

void FUN_00425b50(int param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  void *local_28 [4];
  undefined4 uStack_18;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00979e12;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar3 = FUN_00424e50(local_28);
  puStack_8 = (undefined1 *)0x0;
  FUN_00401660(uVar3,0,0xffffffff);
  puStack_8 = (undefined1 *)0xffffffff;
  if (0xf < uStack_14) {
    _free(local_28[0]);
    return;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  local_28[0] = (void *)((uint)local_28[0] & 0xffffff00);
  FUN_00401660(param_1,0,0xffffffff);
  FUN_00425390(param_1 + 0x38);
  FUN_00425430(param_1 + 0x44);
  FUN_004254e0(param_1 + 0x54);
  puVar1 = (uint *)(param_1 + 0x94);
  FUN_00425580(puVar1);
  FUN_00426380(*puVar1);
  uVar4 = 0;
  if (*puVar1 != 0) {
    iVar5 = 0;
    do {
      iVar2 = *(int *)(param_1 + 0x9c);
      if ((iVar2 == 0) || ((uint)((*(int *)(param_1 + 0xa0) - iVar2) / 0xa8) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
        FUN_00425280();
      }
      FUN_00425b50(param_1,iVar5 + iVar2);
      iVar5 = iVar5 + 0xa8;
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar1);
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00425c90 @ 0x00425c90 ====

void FUN_00425c90(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  int local_68;
  undefined1 local_60 [96];
  
  uVar3 = FUN_00424d90();
  piVar1 = (int *)(in_ECX + 0xc);
  *(undefined4 *)(in_ECX + 8) = uVar3;
  FUN_004252f0(piVar1);
  if (*piVar1 == 0x20030820) {
    FUN_00424d50(0x60);
    FUN_004252f0(local_60);
    *piVar1 = 0x20040303;
    *(undefined4 *)(in_ECX + 0x10) = 1;
  }
  FUN_00426380(*(undefined4 *)(in_ECX + 0x10));
  uVar4 = 0;
  if (*(int *)(in_ECX + 0x10) != 0) {
    local_68 = 0;
    do {
      iVar2 = *(int *)(in_ECX + 0x70);
      if ((iVar2 == 0) || ((uint)((*(int *)(in_ECX + 0x74) - iVar2) / 0xa8) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
        FUN_00425280();
      }
      if (*piVar1 == 0x20040303) {
        FUN_00425b50(param_1,local_68 + iVar2);
      }
      else {
        if (*piVar1 != 0x20040729) {
          return;
        }
        FUN_004259e0(param_1,local_68 + iVar2);
      }
      local_68 = local_68 + 0xa8;
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(in_ECX + 0x10));
  }
  *piVar1 = 0x20040729;
  return;
}


// ==== FUN_00425d90 @ 0x00425d90 ====

void FUN_00425d90(int param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979d83;
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
  *(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 0x50);
  puVar2 = (undefined4 *)(param_1 + 0x54);
  puVar3 = (undefined4 *)(in_ECX + 0x54);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  local_4 = CONCAT31(local_4._1_3_,1);
  *(undefined4 *)(in_ECX + 0x94) = *(undefined4 *)(param_1 + 0x94);
  FUN_00425610(param_1 + 0x98);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00425e70 @ 0x00425e70 ====

void FUN_00425e70(int param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  FUN_00401660(param_1,0,0xffffffff);
  FUN_00401660(param_1 + 0x1c,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 0x50);
  puVar2 = (undefined4 *)(param_1 + 0x54);
  puVar3 = (undefined4 *)(in_ECX + 0x54);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(in_ECX + 0x94) = *(undefined4 *)(param_1 + 0x94);
  FUN_004256b0(param_1 + 0x98);
  return;
}


// ==== FUN_00425f00 @ 0x00425f00 ====

int FUN_00425f00(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    param_2 = param_2 + -0xa8;
    param_3 = param_3 + -0xa8;
    FUN_00425e70(param_2);
  } while (param_2 != param_1);
  return param_3;
}


// ==== FUN_00425f40 @ 0x00425f40 ====

void FUN_00425f40(int param_1,int param_2,undefined4 param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0xa8) {
    FUN_00425e70(param_3);
  }
  return;
}


// ==== FUN_00425f70 @ 0x00425f70 ====

void FUN_00425f70(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  undefined1 local_c4 [2];
  undefined1 auStack_c2 [166];
  void *local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00979d9b;
  local_10 = ExceptionList;
  local_14 = local_c4 + -0xc;
  ExceptionList = &local_10;
  FUN_00425d90(param_3);
  iVar2 = *(int *)(in_ECX + 4);
  uVar5 = 0;
  local_8 = 0;
  if (iVar2 != 0) {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0xa8;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0xa8;
    }
    if (0x1861861U - iVar1 < param_2) {
      FUN_00412e70();
      uVar5 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0xa8;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x1861861 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0xa8;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_00425030();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0xa8);
      local_8 = CONCAT31(local_8._1_3_,1);
      local_1c = pvVar3;
      uVar4 = FUN_00425090(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      uVar4 = FUN_004251e0(uVar4,param_2,local_c4);
      FUN_00425090(param_1,*(undefined4 *)(in_ECX + 8),uVar4);
      iVar2 = *(int *)(in_ECX + 4);
      iVar1 = 0;
      local_8 = 0;
      if (iVar2 != 0) {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0xa8;
      }
      if (iVar2 != 0) {
        FUN_00412df0(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0xa8 + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar1) * 0xa8);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      if ((uint)((iVar2 - param_1) / 0xa8) < param_2) {
        FUN_00425090(param_1,iVar2,param_2 * 0xa8 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004251e0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0xa8,local_c4
                    );
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0xa8;
        local_8 = 0;
        FUN_00425f40(param_1,*(int *)(in_ECX + 8) + param_2 * -0xa8,local_c4);
      }
      else {
        iVar1 = iVar2 + param_2 * -0xa8;
        uVar4 = FUN_00425090(iVar1,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_00425f00(param_1,iVar1,iVar2,iVar1);
        FUN_00425f40(param_1,param_2 * 0xa8 + param_1,local_c4);
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_00412f30();
  ExceptionList = local_10;
  return;
}


// ==== Catch@0042613c @ 0x0042613c ====

void Catch_0042613c(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_00412df0(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@004261fe @ 0x004261fe ====

void Catch_004261fe(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0xa8;
  FUN_00412df0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004262a0 @ 0x004262a0 ====

void FUN_004262a0(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00979db8;
  local_c = ExceptionList;
  iVar2 = *(int *)(in_ECX + 4);
  local_4 = 0;
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0xa8;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0xa8;
    }
    ExceptionList = &local_c;
    FUN_00425f70(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
  }
  else {
    ExceptionList = &local_c;
    if (iVar2 != 0) {
      ExceptionList = &local_c;
      if (param_1 < (uint)((*(int *)(in_ECX + 8) - iVar2) / 0xa8)) {
        ExceptionList = &local_c;
        FUN_00425220(&param_1,iVar2 + param_1 * 0xa8,*(int *)(in_ECX + 8));
      }
    }
  }
  local_4 = 0xffffffff;
  FUN_00412f30();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00426380 @ 0x00426380 ====

void FUN_00426380(undefined4 param_1)

{
  undefined1 auStack_bc [4];
  undefined1 local_b8;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 local_9c;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00979de3;
  local_c = ExceptionList;
  local_10 = auStack_bc;
  local_a4 = 0xf;
  local_a8 = 0;
  local_b8 = 0;
  local_88 = 0xf;
  local_8c = 0;
  local_9c = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_4 = 0xffffffff;
  ExceptionList = &local_c;
  FUN_004262a0(param_1);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00426400 @ 0x00426400 ====

undefined4 FUN_00426400(void)

{
  return 6;
}


// ==== FUN_00426410 @ 0x00426410 ====

int FUN_00426410(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc);
}


// ==== FUN_00426420 @ 0x00426420 ====

void FUN_00426420(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    FUN_004249c0(0,0);
    return;
  }
  FUN_004249c0(*(undefined4 *)(in_ECX + 0xc),*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc));
  return;
}


// ==== FUN_00426450 @ 0x00426450 ====

undefined4 FUN_00426450(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0xc) == 0) || (*(int *)(in_ECX + 0x10) == *(int *)(in_ECX + 0xc))) {
    return 0;
  }
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00426470 @ 0x00426470 ====

void FUN_00426470(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099d4bc;
  if ((void *)in_ECX[3] == (void *)0x0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = &PTR_FUN_0099d408;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_004264b0 @ 0x004264b0 ====

void FUN_004264b0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int in_ECX;
  
  iVar1 = FUN_00424d90();
  iVar2 = FUN_00424dc0(iVar1);
  if (*(void **)(in_ECX + 0xc) != *(void **)(in_ECX + 0x10)) {
    pvVar3 = _memmove(*(void **)(in_ECX + 0xc),*(void **)(in_ECX + 0x10),0);
    *(void **)(in_ECX + 0x10) = pvVar3;
  }
  FUN_00426510(*(undefined4 *)(in_ECX + 0xc),iVar2,iVar1 + iVar2,param_1);
  return;
}


// ==== FUN_00426510 @ 0x00426510 ====

void FUN_00426510(void *param_1,void *param_2,int param_3)

{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  int in_ECX;
  uint extraout_ECX;
  int iVar4;
  uint _Size;
  size_t sVar5;
  uint local_c;
  
  _Size = param_3 - (int)param_2;
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 == 0) {
    local_c = 0;
  }
  else {
    local_c = *(int *)(in_ECX + 0xc) - iVar1;
  }
  if (_Size != 0) {
    if (iVar1 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 8) - iVar1;
    }
    if (-iVar4 - 1U < _Size) {
      iVar1 = FUN_00412e70();
      local_c = extraout_ECX;
    }
    if (iVar1 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 8) - iVar1;
    }
    if (local_c < iVar4 + _Size) {
      if (-(local_c >> 1) - 1 < local_c) {
        local_c = 0;
      }
      else {
        local_c = local_c + (local_c >> 1);
      }
      if (iVar1 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(in_ECX + 8) - iVar1;
      }
      if (local_c < iVar4 + _Size) {
        if (iVar1 == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = *(int *)(in_ECX + 8) - iVar1;
        }
        local_c = iVar1 + _Size;
      }
      pvVar2 = operator_new(local_c);
      sVar5 = (int)param_1 - (int)*(void **)(in_ECX + 4);
      pvVar3 = _memmove(pvVar2,*(void **)(in_ECX + 4),sVar5);
      pvVar3 = _memmove((void *)((int)pvVar3 + sVar5),param_2,_Size);
      _memmove((void *)((int)pvVar3 + _Size),param_1,*(int *)(in_ECX + 8) - (int)param_1);
      pvVar3 = *(void **)(in_ECX + 4);
      if (pvVar3 == (void *)0x0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(in_ECX + 8) - (int)pvVar3;
      }
      if (pvVar3 == (void *)0x0) {
        *(void **)(in_ECX + 4) = pvVar2;
        *(uint *)(in_ECX + 0xc) = local_c + (int)pvVar2;
        *(uint *)(in_ECX + 8) = _Size + iVar1 + (int)pvVar2;
        return;
      }
      _free(pvVar3);
      return;
    }
    pvVar3 = *(void **)(in_ECX + 8);
    if ((uint)((int)pvVar3 - (int)param_1) < _Size) {
      _memmove((void *)((int)param_1 + _Size),param_1,(int)pvVar3 - (int)param_1);
      pvVar3 = (void *)(((int)*(void **)(in_ECX + 8) - (int)param_1) + (int)param_2);
      _memmove(*(void **)(in_ECX + 8),pvVar3,param_3 - (int)pvVar3);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + _Size;
      _memmove(param_1,param_2,(int)pvVar3 - (int)param_2);
      return;
    }
    sVar5 = (int)pvVar3 - (int)((int)pvVar3 - _Size);
    pvVar2 = _memmove(pvVar3,(void *)((int)pvVar3 - _Size),sVar5);
    *(size_t *)(in_ECX + 8) = (int)pvVar2 + sVar5;
    sVar5 = (int)pvVar3 + (-(int)param_1 - _Size);
    _memmove((void *)((int)pvVar3 - sVar5),param_1,sVar5);
    _memmove(param_1,param_2,_Size);
  }
  return;
}


// ==== FUN_004266e0 @ 0x004266e0 ====

void FUN_004266e0(undefined2 *param_1,undefined2 *param_2,undefined2 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    *param_1 = *param_3;
  }
  return;
}


// ==== FUN_00426700 @ 0x00426700 ====

void * FUN_00426700(void *param_1,int param_2,void *param_3)

{
  size_t _Size;
  void *pvVar1;
  
  _Size = (param_2 - (int)param_1 >> 1) * 2;
  pvVar1 = _memmove(param_3,param_1,_Size);
  return (void *)((int)pvVar1 + _Size);
}


// ==== FUN_00426730 @ 0x00426730 ====

void FUN_00426730(void *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_2 - (int)param_1 >> 1;
  _memmove((void *)(param_3 + iVar1 * -2),param_1,iVar1 * 2);
  return;
}


// ==== FUN_00426750 @ 0x00426750 ====

void * FUN_00426750(void *param_1,int param_2,void *param_3)

{
  size_t _Size;
  void *pvVar1;
  
  _Size = (param_2 - (int)param_1 >> 1) * 2;
  pvVar1 = _memmove(param_3,param_1,_Size);
  return (void *)((int)pvVar1 + _Size);
}


// ==== FUN_00426780 @ 0x00426780 ====

void FUN_00426780(undefined2 *param_1,undefined2 *param_2,undefined2 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    *param_3 = *param_1;
    param_3 = param_3 + 1;
  }
  return;
}


// ==== FUN_004267b0 @ 0x004267b0 ====

void FUN_004267b0(undefined2 *param_1,undefined2 *param_2,undefined2 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    if (param_3 != (undefined2 *)0x0) {
      *param_3 = *param_1;
    }
    param_3 = param_3 + 1;
  }
  return;
}


// ==== FUN_004267e0 @ 0x004267e0 ====

void FUN_004267e0(int *param_1)

{
  int in_ECX;
  
  FUN_00424960(4);
  *(undefined4 *)(param_1[2] + *param_1) = *(undefined4 *)(in_ECX + 0xc);
  *param_1 = *param_1 + 4;
  FUN_00424960(4);
  *(undefined4 *)(param_1[2] + *param_1) = *(undefined4 *)(in_ECX + 0x10);
  *param_1 = *param_1 + 4;
  FUN_004249c0(*(undefined4 *)(in_ECX + 0x18),*(int *)(in_ECX + 0x10) * *(int *)(in_ECX + 0xc) * 2);
  return;
}


// ==== FUN_00426850 @ 0x00426850 ====

void FUN_00426850(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  uint local_4;
  
  local_4 = 0;
  if (*(int *)(in_ECX + 0x10) != 0) {
    do {
      uVar4 = *(uint *)(in_ECX + 0xc);
      uVar5 = 0;
      if (uVar4 != 0) {
        do {
          iVar1 = *(int *)(in_ECX + 0x18);
          uVar4 = uVar4 * local_4 + uVar5;
          if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x1c) - iVar1 >> 1) <= uVar4)) {
LAB_00426901:
                    /* WARNING: Subroutine does not return */
            FUN_00426d40();
          }
          iVar3 = uVar4 * 2;
          if (*(short *)(iVar3 + iVar1) == 0) {
            iVar1 = *(int *)(param_1 + 4);
            if ((((iVar1 == 0) || ((uint)(*(int *)(param_1 + 8) - iVar1 >> 1) <= uVar4)) ||
                (iVar2 = *(int *)(in_ECX + 0x18), iVar2 == 0)) ||
               ((uint)(*(int *)(in_ECX + 0x1c) - iVar2 >> 1) <= uVar4)) goto LAB_00426901;
            *(undefined2 *)(iVar2 + iVar3) = *(undefined2 *)(iVar1 + iVar3);
          }
          uVar4 = *(uint *)(in_ECX + 0xc);
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar4);
      }
      local_4 = local_4 + 1;
    } while (local_4 < *(uint *)(in_ECX + 0x10));
  }
  return;
}


// ==== FUN_00426910 @ 0x00426910 ====

void FUN_00426910(uint param_1)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    param_1 = 0;
    if (*(int *)(in_ECX + 0x10) != 0) {
      uVar2 = *(uint *)(in_ECX + 0xc) >> 1;
      do {
        uVar4 = 0;
        if (uVar2 != 0) {
          do {
            iVar1 = *(int *)(in_ECX + 0x18);
            uVar3 = *(int *)(in_ECX + 0xc) * param_1 + uVar4;
            uVar2 = (*(int *)(in_ECX + 0xc) * (param_1 + 1) - uVar4) - 1;
            if (((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x1c) - iVar1 >> 1) <= uVar3)) ||
               ((iVar1 == 0 || ((uint)(*(int *)(in_ECX + 0x1c) - iVar1 >> 1) <= uVar2)))) {
LAB_00426a5e:
                    /* WARNING: Subroutine does not return */
              FUN_00426d40();
            }
            *(undefined2 *)(iVar1 + uVar2 * 2) = *(undefined2 *)(iVar1 + uVar3 * 2);
            uVar4 = uVar4 + 1;
            uVar2 = *(uint *)(in_ECX + 0xc) >> 1;
          } while (uVar4 < uVar2);
        }
        param_1 = param_1 + 1;
      } while (param_1 < *(uint *)(in_ECX + 0x10));
    }
  }
  else {
    param_1 = *(uint *)(in_ECX + 0x10) >> 1;
    if (param_1 < *(uint *)(in_ECX + 0x10)) {
      uVar2 = *(uint *)(in_ECX + 0xc);
      do {
        uVar4 = 0;
        if (uVar2 != 0) {
          do {
            iVar1 = *(int *)(in_ECX + 0x18);
            uVar2 = ((*(int *)(in_ECX + 0x10) - param_1) + -1) * *(int *)(in_ECX + 0xc) + uVar4;
            uVar3 = *(int *)(in_ECX + 0xc) * param_1 + uVar4;
            if ((((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x1c) - iVar1 >> 1) <= uVar2)) ||
                (iVar1 == 0)) || ((uint)(*(int *)(in_ECX + 0x1c) - iVar1 >> 1) <= uVar3))
            goto LAB_00426a5e;
            *(undefined2 *)(iVar1 + uVar3 * 2) = *(undefined2 *)(iVar1 + uVar2 * 2);
            uVar2 = *(uint *)(in_ECX + 0xc);
            uVar4 = uVar4 + 1;
          } while (uVar4 < uVar2);
        }
        param_1 = param_1 + 1;
        if (*(uint *)(in_ECX + 0x10) <= param_1) {
          return;
        }
      } while( true );
    }
  }
  return;
}


// ==== FUN_00426a70 @ 0x00426a70 ====

void FUN_00426a70(int param_1)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x18) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    FUN_00426db0(*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(param_1 + 4),
                 *(undefined4 *)(param_1 + 8),param_1);
    return;
  }
  _free(*(void **)(in_ECX + 0x18));
  return;
}


// ==== FUN_00426ac0 @ 0x00426ac0 ====

void FUN_00426ac0(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  uint local_2c;
  int local_24;
  int local_20 [2];
  void *local_18;
  int local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979e78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00427460(in_ECX + 0x14);
  local_4 = 0;
  FUN_00427520(*(int *)(in_ECX + 0xc) * *(int *)(in_ECX + 0x10),0);
  local_2c = 0;
  if (*(int *)(in_ECX + 0x10) != 0) {
    uVar2 = *(uint *)(in_ECX + 0xc);
    do {
      uVar4 = 0;
      if (uVar2 != 0) {
        do {
          FUN_00445c20(param_1,uVar2,*(undefined4 *)(in_ECX + 0x10),uVar4,local_2c,local_20,
                       &local_24);
          uVar2 = *(int *)(in_ECX + 0xc) * local_2c + uVar4;
          if ((local_18 == (void *)0x0) || ((uint)(local_14 - (int)local_18 >> 1) <= uVar2)) {
                    /* WARNING: Subroutine does not return */
            FUN_00426d40();
          }
          iVar1 = *(int *)(in_ECX + 0x18);
          uVar3 = *(int *)(in_ECX + 0xc) * local_24 + local_20[0];
          if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x1c) - iVar1 >> 1) <= uVar3)) {
                    /* WARNING: Subroutine does not return */
            FUN_00426d40();
          }
          *(undefined2 *)(iVar1 + uVar3 * 2) = *(undefined2 *)((int)local_18 + uVar2 * 2);
          uVar2 = *(uint *)(in_ECX + 0xc);
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar2);
      }
      local_2c = local_2c + 1;
    } while (local_2c < *(uint *)(in_ECX + 0x10));
  }
  if (local_18 == (void *)0x0) {
    ExceptionList = local_c;
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00426be0 @ 0x00426be0 ====

void FUN_00426be0(int param_1,int param_2)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x18) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    *(int *)(in_ECX + 0xc) = param_1;
    *(int *)(in_ECX + 0x10) = param_2;
    FUN_00427520(param_1 * param_2,0);
    return;
  }
  _free(*(void **)(in_ECX + 0x18));
  return;
}


// ==== FUN_00426c30 @ 0x00426c30 ====

void FUN_00426c30(undefined4 param_1)

{
  int iVar1;
  ushort *puVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  undefined4 local_4;
  
  uVar3 = FUN_00424d90();
  *(undefined4 *)(in_ECX + 8) = uVar3;
  FUN_00425580((int *)(in_ECX + 0xc));
  FUN_00425580((int *)(in_ECX + 0x10));
  uVar5 = *(int *)(in_ECX + 0x10) * *(int *)(in_ECX + 0xc);
  if (uVar5 != 0) {
    FUN_004271c0(uVar5);
    if (*(uint *)(in_ECX + 8) < uVar5 + 9) {
      iVar4 = FUN_00424dc0(uVar5);
      if (uVar5 != 0) {
        uVar6 = 0;
        do {
          param_1 = CONCAT22((short)((uint)param_1 >> 0x10),(ushort)*(byte *)(uVar6 + iVar4));
          iVar1 = *(int *)(in_ECX + 0x18);
          if ((iVar1 == 0) ||
             ((uint)(*(int *)(in_ECX + 0x20) - iVar1 >> 1) <=
              (uint)(*(int *)(in_ECX + 0x1c) - iVar1 >> 1))) {
            local_4 = param_1;
            FUN_00427290(*(undefined4 *)(in_ECX + 0x1c),1,&local_4);
          }
          else {
            puVar2 = *(ushort **)(in_ECX + 0x1c);
            *puVar2 = (ushort)*(byte *)(uVar6 + iVar4);
            *(ushort **)(in_ECX + 0x1c) = puVar2 + 1;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar5);
        return;
      }
    }
    else {
      iVar4 = FUN_00424dc0(uVar5 * 2);
      FUN_004275f0(iVar4,uVar5 * 2 + iVar4);
    }
  }
  return;
}


// ==== FUN_00426d10 @ 0x00426d10 ====

undefined2 * FUN_00426d10(undefined2 *param_1,int param_2,undefined2 *param_3)

{
  undefined2 *puVar1;
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


// ==== FUN_00426d40 @ 0x00426d40 ====

void FUN_00426d40(void)

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
  puStack_8 = &LAB_00979e28;
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


// ==== FUN_00426db0 @ 0x00426db0 ====

void FUN_00426db0(void *param_1,int param_2,int param_3)

{
  size_t _Size;
  int iVar1;
  uint uVar2;
  void *_Dst;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00979e40;
  local_10 = ExceptionList;
  iVar7 = *(int *)(in_ECX + 4);
  uVar5 = param_3 - param_2 >> 1;
  if (iVar7 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(in_ECX + 0xc) - iVar7 >> 1;
  }
  uVar8 = CONCAT44(iVar7,iVar1);
  if (uVar5 != 0) {
    if (iVar7 == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = *(int *)(in_ECX + 8) - iVar7 >> 1;
    }
    uVar6 = uVar5;
    ExceptionList = &local_10;
    if (0x7fffffffU - iVar7 < uVar5) {
      ExceptionList = &local_10;
      uVar8 = FUN_00412e70();
      uVar6 = extraout_ECX;
    }
    iVar7 = (int)((ulonglong)uVar8 >> 0x20);
    uVar2 = (uint)uVar8;
    if (iVar7 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8) - iVar7 >> 1;
    }
    if (uVar2 < iVar1 + uVar6) {
      if (0x7fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar7 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(in_ECX + 8) - iVar7 >> 1;
      }
      if (uVar2 < iVar1 + uVar6) {
        if (iVar7 == 0) {
          iVar7 = 0;
        }
        else {
          iVar7 = *(int *)(in_ECX + 8) - iVar7 >> 1;
        }
        uVar2 = iVar7 + uVar6;
      }
      _Dst = operator_new(uVar2 * 2);
      _Size = ((int)param_1 - (int)*(void **)(in_ECX + 4) >> 1) * 2;
      local_8 = 0;
      pvVar3 = _memmove(_Dst,*(void **)(in_ECX + 4),_Size);
      pvVar3 = (void *)FUN_004267b0(param_2,param_3,(void *)((int)pvVar3 + _Size));
      _memmove(pvVar3,param_1,(*(int *)(in_ECX + 8) - (int)param_1 >> 1) * 2);
      pvVar3 = *(void **)(in_ECX + 4);
      if (pvVar3 == (void *)0x0) {
        iVar7 = 0;
      }
      else {
        iVar7 = *(int *)(in_ECX + 8) - (int)pvVar3 >> 1;
      }
      if (pvVar3 == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 2 + (int)_Dst);
        *(void **)(in_ECX + 8) = (void *)((int)_Dst + (uVar5 + iVar7) * 2);
        *(void **)(in_ECX + 4) = _Dst;
        ExceptionList = local_10;
        return;
      }
      _free(pvVar3);
      return;
    }
    iVar7 = *(int *)(in_ECX + 8);
    if ((uint)(iVar7 - (int)param_1 >> 1) < uVar6) {
      FUN_00426750(param_1,iVar7,(void *)(uVar6 * 2 + (int)param_1));
      iVar7 = param_2 + (*(int *)(in_ECX + 8) - (int)param_1 >> 1) * 2;
      local_8 = 2;
      FUN_004267b0(iVar7,param_3,*(int *)(in_ECX + 8));
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar6 * 2;
      FUN_00426780(param_2,iVar7,param_1);
      ExceptionList = local_10;
      return;
    }
    iVar1 = iVar7 + uVar6 * -2;
    uVar4 = FUN_00426750(iVar1,iVar7,iVar7);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_00426730(param_1,iVar1,iVar7);
    FUN_00426780(param_2,param_3,param_1);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00426f10 @ 0x00426f10 ====

void Catch_00426f10(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x1c));
  return;
}


// ==== FUN_00426fe0 @ 0x00426fe0 ====

void FUN_00426fe0(void *param_1,void *param_2,int param_3)

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
  
  uVar1 = param_3 - (int)param_2 >> 1;
  iVar4 = *(int *)(in_ECX + 4);
  if (iVar4 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(in_ECX + 0xc) - iVar4 >> 1;
  }
  uVar8 = CONCAT44(uVar1,iVar2);
  if (uVar1 != 0) {
    if (iVar4 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar4 >> 1;
    }
    if (0x7fffffffU - iVar2 < uVar1) {
      uVar8 = FUN_00412e70();
      iVar4 = extraout_ECX;
    }
    uVar7 = (uint)((ulonglong)uVar8 >> 0x20);
    uVar3 = (uint)uVar8;
    if (iVar4 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar4 >> 1;
    }
    if (uVar3 < iVar2 + uVar7) {
      if (0x7fffffff - (uVar3 >> 1) < uVar3) {
        uVar3 = 0;
      }
      else {
        uVar3 = uVar3 + (uVar3 >> 1);
      }
      if (iVar4 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(in_ECX + 8) - iVar4 >> 1;
      }
      if (uVar3 < iVar2 + uVar7) {
        if (iVar4 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(in_ECX + 8) - iVar4 >> 1;
        }
        uVar3 = iVar4 + uVar7;
      }
      _Dst = operator_new(uVar3 * 2);
      _Size = ((int)param_1 - (int)*(void **)(in_ECX + 4) >> 1) * 2;
      pvVar5 = _memmove(_Dst,*(void **)(in_ECX + 4),_Size);
      pvVar5 = _memmove((void *)((int)pvVar5 + _Size),param_2,uVar1 * 2);
      _memmove((void *)((int)pvVar5 + uVar1 * 2),param_1,
               (*(int *)(in_ECX + 8) - (int)param_1 >> 1) * 2);
      pvVar5 = *(void **)(in_ECX + 4);
      if (pvVar5 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(in_ECX + 8) - (int)pvVar5 >> 1;
      }
      if (pvVar5 == (void *)0x0) {
        *(void **)(in_ECX + 4) = _Dst;
        *(void **)(in_ECX + 0xc) = (void *)(uVar3 * 2 + (int)_Dst);
        *(void **)(in_ECX + 8) = (void *)((int)_Dst + (uVar1 + iVar4) * 2);
        return;
      }
      _free(pvVar5);
      return;
    }
    iVar4 = *(int *)(in_ECX + 8);
    if ((uint)(iVar4 - (int)param_1 >> 1) < uVar7) {
      FUN_00426750(param_1,iVar4,(void *)((int)param_1 + uVar7 * 2));
      pvVar5 = (void *)((int)param_2 + (*(int *)(in_ECX + 8) - (int)param_1 >> 1) * 2);
      FUN_00426750(pvVar5,param_3,*(int *)(in_ECX + 8));
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 2;
      FUN_00426700(param_2,pvVar5,param_1);
      return;
    }
    iVar2 = iVar4 + uVar7 * -2;
    uVar6 = FUN_00426750(iVar2,iVar4,iVar4);
    *(undefined4 *)(in_ECX + 8) = uVar6;
    FUN_00426730(param_1,iVar2,iVar4);
    FUN_00426700(param_2,param_3,param_1);
  }
  return;
}


// ==== FUN_004271c0 @ 0x004271c0 ====

void FUN_004271c0(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  uint extraout_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00979e50;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x7fffffff < param_1) {
    ExceptionList = &local_10;
    FUN_00412e70();
    param_1 = extraout_EDX;
  }
  if (*(int *)(in_ECX + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4) >> 1;
  }
  if (uVar1 < param_1) {
    pvVar2 = operator_new(param_1 * 2);
    local_8 = 0;
    FUN_004267b0(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar2);
    if (*(void **)(in_ECX + 4) != (void *)0x0) {
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 2 + (int)pvVar2);
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 4) = pvVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00427274 @ 0x00427274 ====

void Catch_00427274(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00427290 @ 0x00427290 ====

void FUN_00427290(void *param_1,uint param_2,undefined2 *param_3)

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
  
  param_3 = (undefined2 *)CONCAT22((short)((uint)in_ECX >> 0x10),*param_3);
  iVar5 = *(int *)(in_ECX + 4);
  if (iVar5 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(in_ECX + 0xc) - iVar5 >> 1;
  }
  uVar7 = CONCAT44(iVar5,iVar1);
  if (param_2 != 0) {
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 8) - iVar5 >> 1;
    }
    if (0x7fffffffU - iVar5 < param_2) {
      uVar7 = FUN_00412e70();
    }
    iVar5 = (int)((ulonglong)uVar7 >> 0x20);
    uVar2 = (uint)uVar7;
    if (iVar5 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8) - iVar5 >> 1;
    }
    if (uVar2 < iVar1 + param_2) {
      if (0x7fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar5 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(in_ECX + 8) - iVar5 >> 1;
      }
      if (uVar2 < iVar1 + param_2) {
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(in_ECX + 8) - iVar5 >> 1;
        }
        uVar2 = iVar5 + param_2;
      }
      _Dst = operator_new(uVar2 * 2);
      _Size = ((int)param_1 - (int)*(void **)(in_ECX + 4) >> 1) * 2;
      pvVar3 = _memmove(_Dst,*(void **)(in_ECX + 4),_Size);
      pvVar3 = (void *)FUN_00426d10((void *)((int)pvVar3 + _Size),param_2,&param_3);
      _memmove(pvVar3,param_1,(*(int *)(in_ECX + 8) - (int)param_1 >> 1) * 2);
      pvVar3 = *(void **)(in_ECX + 4);
      if (pvVar3 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - (int)pvVar3 >> 1;
      }
      if (pvVar3 == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 2 + (int)_Dst);
        *(void **)(in_ECX + 8) = (void *)((int)_Dst + (param_2 + iVar5) * 2);
        *(void **)(in_ECX + 4) = _Dst;
        return;
      }
      _free(pvVar3);
      return;
    }
    iVar5 = *(int *)(in_ECX + 8);
    iVar1 = param_2 * 2;
    if ((uint)(iVar5 - (int)param_1 >> 1) < param_2) {
      FUN_00426750(param_1,iVar5,(void *)(iVar1 + (int)param_1));
      FUN_00426d10(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - (int)param_1 >> 1),
                   &param_3);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar1;
      FUN_004266e0(param_1,*(int *)(in_ECX + 8) + param_2 * -2,&param_3);
      return;
    }
    iVar6 = iVar5 + param_2 * -2;
    uVar4 = FUN_00426750(iVar6,iVar5,iVar5);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_00426730(param_1,iVar6,iVar5);
    FUN_004266e0(param_1,(void *)(iVar1 + (int)param_1),&param_3);
  }
  return;
}


// ==== FUN_00427460 @ 0x00427460 ====

void FUN_00427460(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00979e60;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 1;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uVar1 != 0) {
    if (0x7fffffff < uVar1) {
      uVar1 = FUN_00412e70();
    }
    pvVar2 = operator_new(uVar1 * 2);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 2 + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_004267b0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),pvVar2);
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00427501 @ 0x00427501 ====

void Catch_00427501(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00427520 @ 0x00427520 ====

void FUN_00427520(uint param_1,undefined1 param_2)

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
    uVar1 = *(int *)(in_ECX + 8) - iVar2 >> 1;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 1;
    }
    FUN_00427290(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if (((iVar2 != 0) && (pvVar3 = *(void **)(in_ECX + 8), param_1 < (uint)((int)pvVar3 - iVar2 >> 1))
      ) && (_Dst = (void *)(iVar2 + param_1 * 2), _Dst != pvVar3)) {
    pvVar3 = _memmove(_Dst,pvVar3,0);
    *(void **)(in_ECX + 8) = pvVar3;
  }
  return;
}


// ==== FUN_004275a0 @ 0x004275a0 ====

void FUN_004275a0(undefined2 *param_1)

{
  int iVar1;
  undefined2 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 1) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 1))) {
    FUN_00427290(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined2 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined2 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_004275f0 @ 0x004275f0 ====

void FUN_004275f0(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  int in_ECX;
  
  if (*(void **)(in_ECX + 4) != *(void **)(in_ECX + 8)) {
    pvVar1 = _memmove(*(void **)(in_ECX + 4),*(void **)(in_ECX + 8),0);
    *(void **)(in_ECX + 8) = pvVar1;
  }
  FUN_00426fe0(*(undefined4 *)(in_ECX + 4),param_1,param_2,param_2);
  return;
}


// ==== FUN_00427640 @ 0x00427640 ====

void FUN_00427640(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  while (param_1 != param_2) {
    puVar1 = param_1 + 0xf;
    puVar3 = param_3;
    puVar4 = param_1;
    for (iVar2 = 0xf; param_1 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


// ==== FUN_00427670 @ 0x00427670 ====

void FUN_00427670(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  FUN_00424960(8);
  iVar1 = *param_1;
  iVar2 = param_1[2];
  *(undefined4 *)(iVar1 + iVar2) = *param_2;
  *(undefined4 *)(iVar1 + 4 + iVar2) = param_2[1];
  *param_1 = *param_1 + 8;
  FUN_00424960(0x10);
  puVar3 = (undefined4 *)(*param_1 + param_1[2]);
  *puVar3 = param_2[2];
  puVar3[1] = param_2[3];
  puVar3[2] = param_2[4];
  puVar3[3] = param_2[5];
  *param_1 = *param_1 + 0x10;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = param_2[6];
  *param_1 = *param_1 + 4;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = param_2[7];
  *param_1 = *param_1 + 4;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = param_2[8];
  *param_1 = *param_1 + 4;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = param_2[9];
  *param_1 = *param_1 + 4;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = param_2[10];
  *param_1 = *param_1 + 4;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = param_2[0xb];
  *param_1 = *param_1 + 4;
  FUN_00424960(0xc);
  puVar3 = (undefined4 *)(*param_1 + param_1[2]);
  *puVar3 = param_2[0xc];
  puVar3[1] = param_2[0xd];
  puVar3[2] = param_2[0xe];
  *param_1 = *param_1 + 0xc;
  return;
}


// ==== FUN_00427780 @ 0x00427780 ====

void FUN_00427780(int *param_1)

{
  int in_ECX;
  uint uVar1;
  int iVar2;
  
  FUN_00424960(4);
  *(undefined4 *)(param_1[2] + *param_1) = *(undefined4 *)(in_ECX + 0xc);
  *param_1 = *param_1 + 4;
  if ((*(int *)(in_ECX + 0xc) != 0) && (uVar1 = 0, *(int *)(in_ECX + 0xc) != 0)) {
    iVar2 = 0;
    do {
      FUN_00427670(param_1,*(int *)(in_ECX + 0x14) + iVar2);
      uVar1 = uVar1 + 1;
      iVar2 = iVar2 + 0x3c;
    } while (uVar1 < *(uint *)(in_ECX + 0xc));
  }
  return;
}


// ==== FUN_004277d0 @ 0x004277d0 ====

void FUN_004277d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 local_18 [8];
  undefined1 local_10 [16];
  
  puVar1 = *(undefined4 **)(in_ECX + 0x18);
  puVar3 = *(undefined4 **)(in_ECX + 0x14);
  if (puVar3 != puVar1) {
    puVar4 = puVar3 + 2;
    do {
      puVar2 = (undefined4 *)FUN_004458c0(local_18,param_1,param_2,param_3,puVar3);
      *puVar3 = *puVar2;
      puVar3[1] = puVar2[1];
      puVar2 = (undefined4 *)FUN_00445ab0(local_10,param_1,puVar4);
      *puVar4 = *puVar2;
      puVar4[1] = puVar2[1];
      puVar4[2] = puVar2[2];
      puVar3 = puVar3 + 0xf;
      puVar4[3] = puVar2[3];
      puVar4 = puVar4 + 0xf;
    } while (puVar3 != puVar1);
  }
  return;
}


// ==== FUN_00427850 @ 0x00427850 ====

void FUN_00427850(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (*(void **)(in_ECX + 0x14) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x14));
  return;
}


// ==== FUN_00427880 @ 0x00427880 ====

void FUN_00427880(undefined4 param_1,int param_2)

{
  FUN_00427d00(param_2);
  FUN_00425430(param_2 + 8);
  FUN_00427da0(param_2 + 0x18);
  FUN_00427da0(param_2 + 0x1c);
  FUN_00425580(param_2 + 0x20);
  FUN_00425580(param_2 + 0x24);
  FUN_00425580(param_2 + 0x28);
  FUN_00425580(param_2 + 0x2c);
  FUN_00425390(param_2 + 0x30);
  return;
}


// ==== FUN_00427920 @ 0x00427920 ====

void FUN_00427920(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 1;
  FUN_00428520();
  return;
}


// ==== FUN_00427930 @ 0x00427930 ====

void FUN_00427930(undefined4 param_1)

{
  uint *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 auStack_88 [12];
  undefined4 uStack_58;
  undefined4 uStack_54;
  uint *puStack_50;
  undefined4 local_3c [15];
  
  puStack_50 = (uint *)0x427944;
  iVar2 = FUN_00424d90();
  *(int *)(in_ECX + 8) = iVar2;
  if (iVar2 != 0) {
    puVar1 = (uint *)(in_ECX + 0xc);
    uStack_54 = 0x427956;
    puStack_50 = puVar1;
    FUN_00425580();
    uVar4 = *puVar1;
    if (uVar4 != 0) {
      puVar3 = local_3c;
      puVar5 = auStack_88;
      for (iVar2 = 0xf; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      FUN_004283f0(uVar4);
      uVar4 = 0;
      if (*puVar1 != 0) {
        iVar2 = 0;
        do {
          puStack_50 = (uint *)(*(int *)(in_ECX + 0x14) + iVar2);
          uStack_54 = param_1;
          uStack_58 = 0x427992;
          FUN_00427880();
          uVar4 = uVar4 + 1;
          iVar2 = iVar2 + 0x3c;
        } while (uVar4 < *puVar1);
      }
    }
  }
  return;
}


// ==== FUN_004279b0 @ 0x004279b0 ====

/* WARNING: Removing unreachable block (ram,0x00427a66) */
/* WARNING: Removing unreachable block (ram,0x00427a10) */
/* WARNING: Removing unreachable block (ram,0x00427b99) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004279b0(int param_1,uint param_2,uint param_3)

{
  float *pfVar1;
  void **ppvVar2;
  int iVar3;
  int in_ECX;
  float *pfVar4;
  float local_48;
  float local_44;
  float local_40;
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
  float local_14;
  float local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00979ed8;
  pfVar4 = *(float **)(in_ECX + 0x14);
  pfVar1 = *(float **)(in_ECX + 0x18);
  local_4 = 0;
  ppvVar2 = &local_c;
  local_c = ExceptionList;
  do {
    ExceptionList = ppvVar2;
    if (pfVar4 == pfVar1) {
      if (*(void **)(in_ECX + 0x14) != (void *)0x0) {
        _free(*(void **)(in_ECX + 0x14));
        return;
      }
      *(undefined4 *)(in_ECX + 0x14) = 0;
      *(undefined4 *)(in_ECX + 0x18) = 0;
      *(undefined4 *)(in_ECX + 0x1c) = 0;
      FUN_00427e30(*(undefined4 *)(in_ECX + 0x18),0,0,param_1);
      iVar3 = 0;
      if (*(int *)(in_ECX + 0x14) != 0) {
        iVar3 = (*(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14)) / 0x3c;
      }
      *(int *)(in_ECX + 0xc) = iVar3;
      ExceptionList = local_c;
      return;
    }
    if (param_1 == 0) {
      if (*pfVar4 <= (float)(param_2 >> 1)) {
        local_48 = (float)(int)param_2;
        if ((int)param_2 < 0) {
          local_48 = local_48 + _DAT_0099d104;
        }
        local_48 = local_48 - *pfVar4;
        local_44 = pfVar4[1];
LAB_00427aa4:
        local_30 = pfVar4[6];
        local_40 = pfVar4[2];
        local_3c = pfVar4[3];
        local_38 = pfVar4[4];
        local_34 = pfVar4[5];
        local_28 = pfVar4[8];
        local_24 = pfVar4[9];
        local_20 = pfVar4[10];
        local_1c = pfVar4[0xb];
        local_18 = pfVar4[0xc];
        local_14 = pfVar4[0xd];
        local_10 = pfVar4[0xe];
        local_2c = pfVar4[7];
        FUN_00428520(pfVar4);
        FUN_00428520(&local_48);
      }
    }
    else if (pfVar4[1] <= (float)(param_3 >> 1)) {
      local_48 = *pfVar4;
      local_44 = (float)(int)param_3;
      if ((int)param_3 < 0) {
        local_44 = local_44 + _DAT_0099d104;
      }
      local_44 = local_44 - pfVar4[1];
      goto LAB_00427aa4;
    }
    pfVar4 = pfVar4 + 0xf;
    ppvVar2 = ExceptionList;
  } while( true );
}


// ==== FUN_00427bc0 @ 0x00427bc0 ====

void FUN_00427bc0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  while (param_1 != param_2) {
    param_2 = param_2 + -0xf;
    param_3 = param_3 + -0xf;
    puVar2 = param_2;
    puVar3 = param_3;
    for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}


// ==== FUN_00427bf0 @ 0x00427bf0 ====

void FUN_00427bf0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  for (; param_1 != param_2; param_1 = param_1 + 0xf) {
    if (param_3 != (undefined4 *)0x0) {
      puVar2 = param_1;
      puVar3 = param_3;
      for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    param_3 = param_3 + 0xf;
  }
  return;
}


// ==== FUN_00427c20 @ 0x00427c20 ====

void FUN_00427c20(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_2 != 0) {
    do {
      if (param_1 != (undefined4 *)0x0) {
        puVar2 = param_3;
        puVar3 = param_1;
        for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
      }
      param_1 = param_1 + 0xf;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_00427c50 @ 0x00427c50 ====

void FUN_00427c50(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  while (param_1 != param_2) {
    puVar3 = param_1 + 0xf;
    puVar1 = param_3 + 0xf;
    puVar4 = param_1;
    puVar5 = param_3;
    for (iVar2 = 0xf; param_1 = puVar3, param_3 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  return;
}


// ==== FUN_00427c80 @ 0x00427c80 ====

int FUN_00427c80(int param_1,int param_2,undefined4 param_3)

{
  FUN_00427c20(param_1,param_2,param_3);
  return param_1 + param_2 * 0x3c;
}


// ==== FUN_00427cb0 @ 0x00427cb0 ====

void FUN_00427cb0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

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
        puVar2 = param_3 + 0xf;
        puVar5 = puVar4 + 0xf;
        for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
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


// ==== FUN_00427d00 @ 0x00427d00 ====

void FUN_00427d00(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  void *pvVar4;
  uint *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar4 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979e98;
  local_c = ExceptionList;
  uVar1 = in_ECX[2];
  uVar2 = *in_ECX;
  ExceptionList = &local_c;
  *param_1 = *(undefined4 *)(uVar1 + uVar2);
  param_1[1] = *(undefined4 *)(uVar1 + 4 + uVar2);
  *in_ECX = *in_ECX + 8;
  if (*in_ECX <= in_ECX[1]) {
    ExceptionList = pvVar4;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_m_dwCurrent_<__m_dwTotal_0099e360,0x18);
  local_4 = 0;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_00427da0 @ 0x00427da0 ====

void FUN_00427da0(undefined4 *param_1)

{
  code *pcVar1;
  void *pvVar2;
  uint *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00979e98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = *(undefined4 *)(in_ECX[2] + *in_ECX);
  *in_ECX = *in_ECX + 4;
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


// ==== FUN_00427e30 @ 0x00427e30 ====

void FUN_00427e30(int param_1,int param_2,int param_3)

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
  puStack_c = &LAB_00979eb0;
  local_10 = ExceptionList;
  uVar1 = (param_3 - param_2) / 0x3c;
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x3c;
  }
  if (uVar1 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x3c;
    }
    ExceptionList = &local_10;
    if (0x4444444U - iVar2 < uVar1) {
      ExceptionList = &local_10;
      FUN_00412e70();
      uVar6 = extraout_ECX;
    }
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x3c;
    }
    if (uVar6 < iVar2 + uVar1) {
      if (0x4444444 - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x3c;
      }
      if (uVar6 < iVar3 + uVar1) {
        iVar3 = FUN_004297e0();
        uVar6 = iVar3 + uVar1;
      }
      pvVar4 = operator_new(uVar6 * 0x3c);
      local_8 = 0;
      uVar5 = FUN_00427bf0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00427bf0(param_2,param_3,uVar5);
      FUN_00427bf0(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
      iVar3 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x3c;
      }
      if (*(void **)(in_ECX + 4) == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar6 * 0x3c + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (uVar1 + iVar3) * 0x3c);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)((iVar3 - param_1) / 0x3c) < uVar1) {
      FUN_00427bf0(param_1,iVar3,uVar1 * 0x3c + param_1);
      iVar3 = param_2 + ((*(int *)(in_ECX + 8) - param_1) / 0x3c) * 0x3c;
      local_8 = 2;
      FUN_00427bf0(iVar3,param_3,*(int *)(in_ECX + 8));
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar1 * 0x3c;
      FUN_00427c50(param_2,iVar3,param_1);
      ExceptionList = local_10;
      return;
    }
    iVar2 = iVar3 + uVar1 * -0x3c;
    uVar5 = FUN_00427bf0(iVar2,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_00427bc0(param_1,iVar2,iVar3);
    FUN_00427c50(param_2,param_3,param_1);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00427ffe @ 0x00427ffe ====

void Catch_00427ffe(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00428120 @ 0x00428120 ====

void FUN_00428120(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  uint uVar5;
  uint extraout_ECX;
  int iVar6;
  undefined4 *puVar7;
  undefined4 local_50;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00979ec0;
  local_10 = ExceptionList;
  puVar7 = &local_50;
  for (iVar4 = 0xf; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *param_3;
    param_3 = param_3 + 1;
    puVar7 = puVar7 + 1;
  }
  iVar4 = *(int *)(in_ECX + 4);
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar4) / 0x3c;
  }
  if (param_2 != 0) {
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x3c;
    }
    ExceptionList = &local_10;
    local_14 = (undefined1 *)((int)register0x00000010 + -0x5c);
    if (0x4444444U - iVar4 < param_2) {
      ExceptionList = &local_10;
      local_14 = (undefined1 *)((int)register0x00000010 + -0x5c);
      FUN_00412e70();
      uVar5 = extraout_ECX;
    }
    if (*(int *)(in_ECX + 4) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x3c;
    }
    if (uVar5 < iVar4 + param_2) {
      if (0x4444444 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (*(int *)(in_ECX + 4) == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x3c;
      }
      if (uVar5 < iVar4 + param_2) {
        iVar4 = FUN_004297e0();
        uVar5 = iVar4 + param_2;
      }
      pvVar2 = operator_new(uVar5 * 0x3c);
      local_8 = 0;
      iVar4 = FUN_00427bf0(*(undefined4 *)(in_ECX + 4),param_1,pvVar2);
      FUN_00427c20(iVar4,param_2,&local_50);
      FUN_00427bf0(param_1,*(undefined4 *)(in_ECX + 8),iVar4 + param_2 * 0x3c);
      iVar4 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar4 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x3c;
      }
      if (*(void **)(in_ECX + 4) == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x3c + (int)pvVar2);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar2 + (param_2 + iVar4) * 0x3c);
        *(void **)(in_ECX + 4) = pvVar2;
        ExceptionList = local_10;
        return;
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar4 = *(int *)(in_ECX + 8);
    iVar1 = param_2 * 0x3c;
    if ((uint)((iVar4 - param_1) / 0x3c) < param_2) {
      FUN_00427bf0(param_1,iVar4,iVar1 + param_1);
      local_8 = 2;
      FUN_00427c80(*(undefined4 *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x3c,
                   &local_50);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar1;
      FUN_00427640(param_1,*(int *)(in_ECX + 8) + param_2 * -0x3c,&local_50);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar4 + param_2 * -0x3c;
    uVar3 = FUN_00427bf0(iVar6,iVar4,iVar4);
    *(undefined4 *)(in_ECX + 8) = uVar3;
    FUN_00427bc0(param_1,iVar6,iVar4);
    FUN_00427640(param_1,iVar1 + param_1,&local_50);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004282ed @ 0x004282ed ====

void Catch_004282ed(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_004283f0 @ 0x004283f0 ====

void FUN_004283f0(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x3c;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x3c;
    }
    FUN_00428120(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)((*(int *)(in_ECX + 8) - iVar2) / 0x3c))) {
    FUN_00427cb0(&param_1,iVar2 + param_1 * 0x3c,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_004284a0 @ 0x004284a0 ====

void FUN_004284a0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x3c != 0) {
      iVar1 = (param_2 - iVar1) / 0x3c;
      goto LAB_004284e9;
    }
  }
  iVar1 = 0;
LAB_004284e9:
  FUN_00428120(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x3c;
  return;
}


// ==== FUN_00428520 @ 0x00428520 ====

void FUN_00428520(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x3c) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x3c))) {
    FUN_004284a0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00427c20(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x3c;
  return;
}


// ==== FUN_004285b0 @ 0x004285b0 ====

void FUN_004285b0(undefined4 param_1)

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


// ==== FUN_00428610 @ 0x00428610 ====

void FUN_00428610(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int in_ECX;
  
  iVar1 = FUN_00424d90();
  iVar2 = FUN_00424dc0(iVar1);
  if (*(void **)(in_ECX + 0xc) != *(void **)(in_ECX + 0x10)) {
    pvVar3 = _memmove(*(void **)(in_ECX + 0xc),*(void **)(in_ECX + 0x10),0);
    *(void **)(in_ECX + 0x10) = pvVar3;
  }
  FUN_00426510(*(undefined4 *)(in_ECX + 0xc),iVar2,iVar1 + iVar2,param_1);
  return;
}


// ==== FUN_00428670 @ 0x00428670 ====

void FUN_00428670(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  FUN_00424960(8);
  iVar1 = *param_1;
  iVar2 = param_1[2];
  *(undefined4 *)(iVar1 + iVar2) = *param_2;
  *(undefined4 *)(iVar1 + 4 + iVar2) = param_2[1];
  *param_1 = *param_1 + 8;
  FUN_00424960(0x10);
  puVar3 = (undefined4 *)(*param_1 + param_1[2]);
  *puVar3 = param_2[2];
  puVar3[1] = param_2[3];
  puVar3[2] = param_2[4];
  puVar3[3] = param_2[5];
  *param_1 = *param_1 + 0x10;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = param_2[6];
  *param_1 = *param_1 + 4;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = param_2[7];
  *param_1 = *param_1 + 4;
  FUN_00424a00(param_2 + 8);
  return;
}


// ==== FUN_00428700 @ 0x00428700 ====

void FUN_00428700(int *param_1)

{
  int in_ECX;
  uint uVar1;
  int iVar2;
  
  FUN_00424960(4);
  *(undefined4 *)(param_1[2] + *param_1) = *(undefined4 *)(in_ECX + 0xc);
  *param_1 = *param_1 + 4;
  if ((*(int *)(in_ECX + 0xc) != 0) && (uVar1 = 0, *(int *)(in_ECX + 0xc) != 0)) {
    iVar2 = 0;
    do {
      FUN_00428670(param_1,*(int *)(in_ECX + 0x14) + iVar2);
      uVar1 = uVar1 + 1;
      iVar2 = iVar2 + 0x3c;
    } while (uVar1 < *(uint *)(in_ECX + 0xc));
  }
  return;
}


// ==== FUN_00428750 @ 0x00428750 ====

void FUN_00428750(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 local_18 [8];
  undefined1 local_10 [16];
  
  puVar1 = *(undefined4 **)(in_ECX + 0x18);
  puVar3 = *(undefined4 **)(in_ECX + 0x14);
  if (puVar3 != puVar1) {
    puVar4 = puVar3 + 2;
    do {
      puVar2 = (undefined4 *)FUN_004458c0(local_18,param_1,param_2,param_3,puVar3);
      *puVar3 = *puVar2;
      puVar3[1] = puVar2[1];
      puVar2 = (undefined4 *)FUN_00445ab0(local_10,param_1,puVar4);
      *puVar4 = *puVar2;
      puVar4[1] = puVar2[1];
      puVar4[2] = puVar2[2];
      puVar3 = puVar3 + 0xf;
      puVar4[3] = puVar2[3];
      puVar4 = puVar4 + 0xf;
    } while (puVar3 != puVar1);
  }
  return;
}


// ==== FUN_004287d0 @ 0x004287d0 ====

void FUN_004287d0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  void *local_28 [5];
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00979f18;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00427d00(param_2);
  FUN_00425430(param_2 + 8);
  FUN_00427da0(param_2 + 0x18);
  FUN_00427da0(param_2 + 0x1c);
  uVar1 = FUN_00424e50(local_28);
  puStack_8 = (undefined1 *)0x0;
  FUN_00401660(uVar1,0,0xffffffff);
  if (uStack_14 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(local_28[0]);
  return;
}


// ==== FUN_00428870 @ 0x00428870 ====

void FUN_00428870(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  FUN_00413810();
  return;
}


// ==== FUN_004288b0 @ 0x004288b0 ====

void FUN_004288b0(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 1;
  FUN_00429750();
  return;
}


// ==== FUN_004288c0 @ 0x004288c0 ====

void FUN_004288c0(undefined4 param_1)

{
  uint *puVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  
  iVar2 = FUN_00424d90();
  *(int *)(in_ECX + 8) = iVar2;
  if (iVar2 != 0) {
    puVar1 = (uint *)(in_ECX + 0xc);
    FUN_00425580(puVar1);
    if (*puVar1 != 0) {
      FUN_00429720(*puVar1);
      uVar3 = 0;
      if (*puVar1 != 0) {
        iVar2 = 0;
        do {
          FUN_004287d0(param_1,*(int *)(in_ECX + 0x14) + iVar2);
          uVar3 = uVar3 + 1;
          iVar2 = iVar2 + 0x3c;
        } while (uVar3 < *puVar1);
      }
    }
  }
  return;
}


// ==== FUN_00428930 @ 0x00428930 ====

/* WARNING: Removing unreachable block (ram,0x00428a01) */
/* WARNING: Removing unreachable block (ram,0x004289a6) */
/* WARNING: Removing unreachable block (ram,0x00428b8e) */
/* WARNING: Removing unreachable block (ram,0x00428b96) */
/* WARNING: Removing unreachable block (ram,0x00428ba0) */
/* WARNING: Removing unreachable block (ram,0x00428ba5) */
/* WARNING: Removing unreachable block (ram,0x00428bb1) */
/* WARNING: Removing unreachable block (ram,0x00428bc7) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00428930(int param_1,uint param_2,uint param_3)

{
  float *pfVar1;
  int iVar2;
  void **ppvVar3;
  int in_ECX;
  int iVar4;
  float *pfVar5;
  uint *puVar6;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00979f32;
  pfVar5 = *(float **)(in_ECX + 0x14);
  pfVar1 = *(float **)(in_ECX + 0x18);
  local_4 = 0;
  ppvVar3 = &local_c;
  local_c = ExceptionList;
  do {
    ExceptionList = ppvVar3;
    if (pfVar5 == pfVar1) {
      iVar4 = *(int *)(in_ECX + 0x14);
      if (iVar4 == 0) {
        *(undefined4 *)(in_ECX + 0x14) = 0;
        *(undefined4 *)(in_ECX + 0x18) = 0;
        *(undefined4 *)(in_ECX + 0x1c) = 0;
        FUN_00429270(*(undefined4 *)(in_ECX + 0x18),0,0,param_1);
        if (*(int *)(in_ECX + 0x14) == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = (*(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14)) / 0x3c;
        }
        *(int *)(in_ECX + 0xc) = iVar4;
        ExceptionList = local_c;
        return;
      }
      iVar2 = *(int *)(in_ECX + 0x18);
      if (iVar4 != iVar2) {
        puVar6 = (uint *)(iVar4 + 0x38);
        do {
          if (0xf < *puVar6) {
            _free((void *)puVar6[-5]);
            return;
          }
          *puVar6 = 0xf;
          puVar6[-1] = 0;
          *(undefined1 *)(puVar6 + -5) = 0;
          iVar4 = iVar4 + 0x3c;
          puVar6 = puVar6 + 0xf;
        } while (iVar4 != iVar2);
      }
      _free(*(void **)(in_ECX + 0x14));
      return;
    }
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    local_4._1_3_ = (uint3)((uint)local_4 >> 8);
    local_4._0_1_ = 1;
    if (param_1 == 0) {
      if (*pfVar5 <= (float)(param_2 >> 1)) {
        local_44 = pfVar5[1];
        local_48 = (float)(int)param_2;
        if ((int)param_2 < 0) {
          local_48 = local_48 + _DAT_0099d104;
        }
        local_48 = local_48 - *pfVar5;
LAB_00428a44:
        local_40 = pfVar5[2];
        local_3c = pfVar5[3];
        local_38 = pfVar5[4];
        local_34 = pfVar5[5];
        FUN_00401660(pfVar5 + 8,0,0xffffffff);
        local_30 = pfVar5[6];
        local_2c = pfVar5[7];
        FUN_00429750(pfVar5);
        FUN_00429750(&local_48);
        local_4 = (uint)local_4._1_3_ << 8;
        if (0xf < local_10) {
          _free(local_24);
          return;
        }
      }
      else {
        local_4 = (uint)local_4._1_3_ << 8;
      }
    }
    else {
      if (pfVar5[1] <= (float)(param_3 >> 1)) {
        local_44 = (float)(int)param_3;
        if ((int)param_3 < 0) {
          local_44 = local_44 + _DAT_0099d104;
        }
        local_44 = local_44 - pfVar5[1];
        local_48 = *pfVar5;
        goto LAB_00428a44;
      }
      local_4 = (uint)local_4._1_3_ << 8;
    }
    pfVar5 = pfVar5 + 0xf;
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    ppvVar3 = ExceptionList;
  } while( true );
}


// ==== FUN_00428bf0 @ 0x00428bf0 ====

undefined4 * FUN_00428bf0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

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
    param_3[5] = param_1[5];
    param_3[6] = param_1[6];
    param_3[7] = param_1[7];
    FUN_00401660(param_1 + 8,0,0xffffffff);
    param_1 = param_1 + 0xf;
    param_3 = param_3 + 0xf;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_00428c60 @ 0x00428c60 ====

int FUN_00428c60(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    *(undefined4 *)(param_3 + -0x3c) = *(undefined4 *)(param_2 + -0x3c);
    iVar1 = param_2 + -0x3c;
    iVar2 = param_3 + -0x3c;
    *(undefined4 *)(param_3 + -0x38) = *(undefined4 *)(param_2 + -0x38);
    *(undefined4 *)(param_3 + -0x34) = *(undefined4 *)(param_2 + -0x34);
    *(undefined4 *)(param_3 + -0x30) = *(undefined4 *)(param_2 + -0x30);
    *(undefined4 *)(param_3 + -0x2c) = *(undefined4 *)(param_2 + -0x2c);
    *(undefined4 *)(param_3 + -0x28) = *(undefined4 *)(param_2 + -0x28);
    *(undefined4 *)(param_3 + -0x24) = *(undefined4 *)(param_2 + -0x24);
    *(undefined4 *)(param_3 + -0x20) = *(undefined4 *)(param_2 + -0x20);
    FUN_00401660(param_2 + -0x1c,0,0xffffffff);
    param_2 = iVar1;
    param_3 = iVar2;
  } while (iVar1 != param_1);
  return iVar2;
}


// ==== FUN_00428cd0 @ 0x00428cd0 ====

undefined4 * FUN_00428cd0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00979f01;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0xf) {
    local_8 = 1;
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      param_3[1] = param_1[1];
      param_3[2] = param_1[2];
      param_3[3] = param_1[3];
      param_3[4] = param_1[4];
      param_3[5] = param_1[5];
      param_3[6] = param_1[6];
      param_3[7] = param_1[7];
      param_3[0xe] = 0xf;
      param_3[0xd] = 0;
      *(undefined1 *)(param_3 + 9) = 0;
      FUN_00401660(param_1 + 8,0,0xffffffff);
    }
    param_3 = param_3 + 0xf;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00428d70 @ 0x00428d70 ====

void Catch_00428d70(void)

{
  int unaff_EBP;
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 0x10)) {
    puVar1 = (uint *)(iVar2 + 0x38);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      iVar2 = iVar2 + 0x3c;
      puVar1 = puVar1 + 0xf;
    } while (iVar2 != *(int *)(unaff_EBP + 0x10));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00428dd0 @ 0x00428dd0 ====

void FUN_00428dd0(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00979f51;
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
      param_1[5] = param_3[5];
      param_1[6] = param_3[6];
      param_1[7] = param_3[7];
      param_1[0xe] = 0xf;
      param_1[0xd] = 0;
      *(undefined1 *)(param_1 + 9) = 0;
      FUN_00401660(param_3 + 8,0,0xffffffff);
    }
    param_1 = param_1 + 0xf;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00428e71 @ 0x00428e71 ====

void Catch_00428e71(void)

{
  int unaff_EBP;
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 8)) {
    puVar1 = (uint *)(iVar2 + 0x38);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      iVar2 = iVar2 + 0x3c;
      puVar1 = puVar1 + 0xf;
    } while (iVar2 != *(int *)(unaff_EBP + 8));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00428ec0 @ 0x00428ec0 ====

int FUN_00428ec0(int param_1,int param_2,undefined4 param_3)

{
  FUN_00428dd0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x3c;
}


// ==== FUN_00428ef0 @ 0x00428ef0 ====

void FUN_00428ef0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  if (param_2 != param_3) {
    iVar2 = FUN_00428bf0(param_3,*(undefined4 *)(in_ECX + 8),param_2,param_2);
    iVar1 = *(int *)(in_ECX + 8);
    for (iVar3 = iVar2; iVar3 != iVar1; iVar3 = iVar3 + 0x3c) {
      FUN_00713830();
    }
    *(int *)(in_ECX + 8) = iVar2;
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_00428f50 @ 0x00428f50 ====

void FUN_00428f50(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  int iVar6;
  undefined1 local_54 [2];
  undefined1 auStack_52 [34];
  void *local_30;
  uint local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00979f68;
  local_10 = ExceptionList;
  local_14 = local_54 + -0xc;
  ExceptionList = &local_10;
  FUN_00429bf0(param_3);
  iVar2 = *(int *)(in_ECX + 4);
  uVar5 = 0;
  local_8 = 0;
  if (iVar2 != 0) {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x3c;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x3c;
    }
    if (0x4444444U - iVar2 < param_2) {
      FUN_00412e70();
      uVar5 = extraout_ECX;
    }
    if (*(int *)(in_ECX + 4) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x3c;
    }
    if (uVar5 < iVar2 + param_2) {
      if (0x4444444 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (*(int *)(in_ECX + 4) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x3c;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_004297e0();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x3c);
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar2 = FUN_00428cd0(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_00428dd0(iVar2,param_2,local_54);
      FUN_00428cd0(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x3c);
      iVar2 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x3c;
      }
      if (*(int *)(in_ECX + 4) != 0) {
        FUN_004136a0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x3c + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar2) * 0x3c);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      iVar1 = param_2 * 0x3c;
      if ((uint)((iVar2 - param_1) / 0x3c) < param_2) {
        FUN_00428cd0(param_1,iVar2,iVar1 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_00428ec0(*(undefined4 *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x3c,
                     local_54);
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar1;
        local_8 = 0;
        FUN_00429fa0(param_1,*(int *)(in_ECX + 8) + param_2 * -0x3c,local_54);
      }
      else {
        iVar6 = iVar2 + param_2 * -0x3c;
        uVar4 = FUN_00428cd0(iVar6,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_00428c60(param_1,iVar6,iVar2,param_1);
        FUN_00429fa0(param_1,iVar1 + param_1,local_54);
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


// ==== Catch@00429124 @ 0x00429124 ====

void Catch_00429124(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + 0x10);
  FUN_004136a0(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@004291e1 @ 0x004291e1 ====

void Catch_004291e1(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x3c;
  FUN_004136a0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00429270 @ 0x00429270 ====

void FUN_00429270(int param_1,int param_2,int param_3)

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
  puStack_c = &LAB_00979f80;
  local_10 = ExceptionList;
  uVar1 = (param_3 - param_2) / 0x3c;
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x3c;
  }
  if (uVar1 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x3c;
    }
    ExceptionList = &local_10;
    if (0x4444444U - iVar2 < uVar1) {
      ExceptionList = &local_10;
      FUN_00412e70();
      uVar6 = extraout_ECX;
    }
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x3c;
    }
    if (uVar6 < iVar2 + uVar1) {
      if (0x4444444 - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x3c;
      }
      if (uVar6 < iVar3 + uVar1) {
        iVar3 = FUN_004297e0();
        uVar6 = iVar3 + uVar1;
      }
      pvVar4 = operator_new(uVar6 * 0x3c);
      local_8 = 0;
      uVar5 = FUN_00428cd0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00428cd0(param_2,param_3,uVar5);
      FUN_00428cd0(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
      iVar3 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x3c;
      }
      if (*(int *)(in_ECX + 4) == 0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar6 * 0x3c + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (uVar1 + iVar3) * 0x3c);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      FUN_004136a0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)((iVar3 - param_1) / 0x3c) < uVar1) {
      FUN_00428cd0(param_1,iVar3,uVar1 * 0x3c + param_1);
      iVar3 = param_2 + ((*(int *)(in_ECX + 8) - param_1) / 0x3c) * 0x3c;
      local_8 = 2;
      FUN_00428cd0(iVar3,param_3,*(int *)(in_ECX + 8));
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar1 * 0x3c;
      local_8 = 0xffffffff;
      FUN_00428bf0(param_2,iVar3,param_1,param_1);
      ExceptionList = local_10;
      return;
    }
    iVar2 = iVar3 + uVar1 * -0x3c;
    uVar5 = FUN_00428cd0(iVar2,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_00428c60(param_1,iVar2,iVar3,param_1);
    FUN_00428bf0(param_2,param_3,param_1,param_1);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0042945c @ 0x0042945c ====

void Catch_0042945c(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_004136a0(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@0042953c @ 0x0042953c ====

void Catch_0042953c(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x14) * 0x3c;
  FUN_004136a0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x1c) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004295c0 @ 0x004295c0 ====

void FUN_004295c0(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *in_stack_0000002c;
  uint in_stack_00000040;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00979f98;
  local_c = ExceptionList;
  iVar2 = *(int *)(in_ECX + 4);
  local_4 = 0;
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x3c;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x3c;
    }
    ExceptionList = &local_c;
    FUN_00428f50(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
  }
  else {
    ExceptionList = &local_c;
    if (iVar2 != 0) {
      ExceptionList = &local_c;
      if (param_1 < (uint)((*(int *)(in_ECX + 8) - iVar2) / 0x3c)) {
        ExceptionList = &local_c;
        FUN_00428ef0(&param_1,iVar2 + param_1 * 0x3c,*(int *)(in_ECX + 8));
      }
    }
  }
  if (in_stack_00000040 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(in_stack_0000002c);
  return;
}


// ==== FUN_004296a0 @ 0x004296a0 ====

void FUN_004296a0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x3c != 0) {
      iVar1 = (param_2 - iVar1) / 0x3c;
      goto LAB_004296e9;
    }
  }
  iVar1 = 0;
LAB_004296e9:
  FUN_00428f50(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x3c;
  return;
}


// ==== FUN_00429720 @ 0x00429720 ====

void FUN_00429720(undefined4 param_1)

{
  undefined1 auStack_40 [36];
  undefined1 local_1c;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 *local_4;
  
  local_4 = auStack_40;
  local_8 = 0xf;
  local_c = 0;
  local_1c = 0;
  FUN_004295c0(param_1);
  return;
}


// ==== FUN_00429750 @ 0x00429750 ====

void FUN_00429750(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x3c) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x3c))) {
    FUN_004296a0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00428dd0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x3c;
  return;
}


// ==== FUN_004297e0 @ 0x004297e0 ====

int FUN_004297e0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x3c;
}


// ==== FUN_00429810 @ 0x00429810 ====

void FUN_00429810(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  FUN_00424960(8);
  iVar1 = *param_1;
  iVar2 = param_1[2];
  *(undefined4 *)(iVar1 + iVar2) = *param_2;
  *(undefined4 *)(iVar1 + 4 + iVar2) = param_2[1];
  *param_1 = *param_1 + 8;
  FUN_00424960(0x10);
  puVar3 = (undefined4 *)(*param_1 + param_1[2]);
  *puVar3 = param_2[2];
  puVar3[1] = param_2[3];
  puVar3[2] = param_2[4];
  puVar3[3] = param_2[5];
  *param_1 = *param_1 + 0x10;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = param_2[6];
  *param_1 = *param_1 + 4;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = param_2[7];
  *param_1 = *param_1 + 4;
  FUN_00424a00(param_2 + 8);
  return;
}


// ==== FUN_004298a0 @ 0x004298a0 ====

void FUN_004298a0(int *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  if (*(int *)(in_ECX + 0x14) != 0) {
    iVar4 = (*(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14)) / 0x3c;
  }
  if (*(int *)(in_ECX + 0xc) == iVar4) {
    FUN_00424960(4);
    *(undefined4 *)(param_1[2] + *param_1) = *(undefined4 *)(in_ECX + 0xc);
    *param_1 = *param_1 + 4;
    uVar2 = 0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      iVar4 = 0;
      do {
        FUN_00429810(param_1,*(int *)(in_ECX + 0x14) + iVar4);
        uVar2 = uVar2 + 1;
        iVar4 = iVar4 + 0x3c;
      } while (uVar2 < *(uint *)(in_ECX + 0xc));
    }
    if (*(int *)(in_ECX + 0x28) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 0x2c) - *(int *)(in_ECX + 0x28) >> 3;
    }
    *(int *)(in_ECX + 0x20) = iVar4;
    FUN_00424960(4);
    *(undefined4 *)(param_1[2] + *param_1) = *(undefined4 *)(in_ECX + 0x20);
    *param_1 = *param_1 + 4;
    puVar1 = *(undefined4 **)(in_ECX + 0x2c);
    for (puVar3 = *(undefined4 **)(in_ECX + 0x28); puVar3 != puVar1; puVar3 = puVar3 + 2) {
      FUN_00424960(1);
      *(undefined1 *)(param_1[2] + *param_1) = *(undefined1 *)(puVar3 + 1);
      *param_1 = *param_1 + 1;
      FUN_00424960(1);
      *(undefined1 *)(param_1[2] + *param_1) = *(undefined1 *)((int)puVar3 + 5);
      *param_1 = *param_1 + 1;
      FUN_00424960(4);
      *(undefined4 *)(param_1[2] + *param_1) = *puVar3;
      *param_1 = *param_1 + 4;
    }
  }
  return;
}


// ==== FUN_004299b0 @ 0x004299b0 ====

void FUN_004299b0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = 0;
  FUN_00413810();
  return;
}


// ==== FUN_004299c0 @ 0x004299c0 ====

void FUN_004299c0(void)

{
  undefined4 uVar1;
  void *local_64 [5];
  uint uStack_50;
  undefined1 auStack_4c [4];
  undefined1 local_48 [8];
  undefined1 local_40 [16];
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  void *pvStack_28;
  undefined1 local_24;
  uint local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097a030;
  pvStack_c = ExceptionList;
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = 0;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  FUN_00427d00(local_48);
  FUN_00425430(local_40);
  FUN_00427da0(local_30);
  FUN_00427da0(local_2c);
  uVar1 = FUN_00424e50(local_64);
  puStack_8._0_1_ = 1;
  FUN_00401660(uVar1,0,0xffffffff);
  puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
  if (0xf < uStack_50) {
    _free(local_64[0]);
    return;
  }
  FUN_0042a620(auStack_4c);
  if (local_14 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(pvStack_28);
  return;
}


// ==== FUN_00429ab0 @ 0x00429ab0 ====

void FUN_00429ab0(undefined4 param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint local_18;
  undefined1 local_10 [4];
  undefined1 local_c;
  undefined1 local_b [7];
  
  uVar3 = FUN_00424d90();
  puVar1 = (uint *)(in_ECX + 0xc);
  *(undefined4 *)(in_ECX + 8) = uVar3;
  FUN_00425580(puVar1);
  local_18 = 0;
  if (*puVar1 != 0) {
    do {
      FUN_004299c0(param_1);
      local_18 = local_18 + 1;
    } while (local_18 < *puVar1);
  }
  puVar1 = (uint *)(in_ECX + 0x20);
  FUN_00425580(puVar1);
  local_18 = 0;
  if (*puVar1 != 0) {
    do {
      FUN_00424ca0(&local_c);
      FUN_00424ca0(local_b);
      FUN_00425580(local_10);
      iVar2 = *(int *)(in_ECX + 0x28);
      if ((iVar2 == 0) ||
         ((uint)(*(int *)(in_ECX + 0x30) - iVar2 >> 3) <=
          (uint)(*(int *)(in_ECX + 0x2c) - iVar2 >> 3))) {
        FUN_00429d50(*(undefined4 *)(in_ECX + 0x2c),1,local_10);
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x2c);
        FUN_00429bc0(iVar2,1,local_10,in_ECX + 0x24,puVar1);
        *(int *)(in_ECX + 0x2c) = iVar2 + 8;
      }
      local_18 = local_18 + 1;
    } while (local_18 < *puVar1);
  }
  return;
}


// ==== FUN_00429bc0 @ 0x00429bc0 ====

void FUN_00429bc0(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  if (param_2 != 0) {
    do {
      if (param_1 != (undefined4 *)0x0) {
        *param_1 = *param_3;
        param_1[1] = param_3[1];
      }
      param_1 = param_1 + 2;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_00429bf0 @ 0x00429bf0 ====

void FUN_00429bf0(undefined4 *param_1)

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
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  FUN_00401660(param_1 + 8,0,0xffffffff);
  return;
}


// ==== FUN_00429c50 @ 0x00429c50 ====

undefined4 * FUN_00429c50(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00979fc1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0xf) {
    local_8 = 1;
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      param_3[1] = param_1[1];
      param_3[2] = param_1[2];
      param_3[3] = param_1[3];
      param_3[4] = param_1[4];
      param_3[5] = param_1[5];
      param_3[6] = param_1[6];
      param_3[7] = param_1[7];
      param_3[0xe] = 0xf;
      param_3[0xd] = 0;
      *(undefined1 *)(param_3 + 9) = 0;
      FUN_00401660(param_1 + 8,0,0xffffffff);
    }
    param_3 = param_3 + 0xf;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00429cf0 @ 0x00429cf0 ====

void Catch_00429cf0(void)

{
  int unaff_EBP;
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 0x10)) {
    puVar1 = (uint *)(iVar2 + 0x38);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      iVar2 = iVar2 + 0x3c;
      puVar1 = puVar1 + 0xf;
    } while (iVar2 != *(int *)(unaff_EBP + 0x10));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00429d50 @ 0x00429d50 ====

void FUN_00429d50(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00979fd0;
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
      uVar2 = FUN_00412e70();
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


// ==== Catch@00429ec1 @ 0x00429ec1 ====

void Catch_00429ec1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00429fa0 @ 0x00429fa0 ====

void FUN_00429fa0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_1 = *param_3;
      param_1[1] = param_3[1];
      param_1[2] = param_3[2];
      param_1[3] = param_3[3];
      param_1[4] = param_3[4];
      param_1[5] = param_3[5];
      param_1[6] = param_3[6];
      param_1[7] = param_3[7];
      FUN_00401660(param_3 + 8,0,0xffffffff);
      param_1 = param_1 + 0xf;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_0042a010 @ 0x0042a010 ====

void FUN_0042a010(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00979ff1;
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
      param_1[5] = param_3[5];
      param_1[6] = param_3[6];
      param_1[7] = param_3[7];
      param_1[0xe] = 0xf;
      param_1[0xd] = 0;
      *(undefined1 *)(param_1 + 9) = 0;
      FUN_00401660(param_3 + 8,0,0xffffffff);
    }
    param_1 = param_1 + 0xf;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0042a0b1 @ 0x0042a0b1 ====

void Catch_0042a0b1(void)

{
  int unaff_EBP;
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 8)) {
    puVar1 = (uint *)(iVar2 + 0x38);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      iVar2 = iVar2 + 0x3c;
      puVar1 = puVar1 + 0xf;
    } while (iVar2 != *(int *)(unaff_EBP + 8));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0042a100 @ 0x0042a100 ====

void FUN_0042a100(int param_1)

{
  void *_Memory;
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if (in_ECX == param_1) {
    return;
  }
  iVar5 = *(int *)(param_1 + 4);
  if (iVar5 != 0) {
    uVar4 = *(int *)(param_1 + 8) - iVar5 >> 3;
    if (uVar4 != 0) {
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(int *)(in_ECX + 8) - (int)_Memory >> 3;
      }
      if (uVar4 <= uVar3) {
        FUN_005d6f70(iVar5,*(int *)(param_1 + 8),_Memory);
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 3) * 8;
        return;
      }
      if (_Memory == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(int *)(in_ECX + 0xc) - (int)_Memory >> 3;
      }
      if (uVar4 <= uVar3) {
        if (_Memory == (void *)0x0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(in_ECX + 8) - (int)_Memory >> 3;
        }
        iVar5 = *(int *)(param_1 + 4) + iVar5 * 8;
        FUN_005d6f70(*(int *)(param_1 + 4),iVar5,_Memory);
        uVar2 = FUN_00751a10(iVar5,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar2;
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
        iVar5 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 3;
      }
      cVar1 = FUN_004131c0(iVar5);
      if (cVar1 == '\0') {
        return;
      }
      uVar2 = FUN_0058a8d0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar2;
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


// ==== FUN_0042a250 @ 0x0042a250 ====

int FUN_0042a250(int param_1,int param_2,undefined4 param_3)

{
  FUN_0042a010(param_1,param_2,param_3);
  return param_1 + param_2 * 0x3c;
}


// ==== FUN_0042a280 @ 0x0042a280 ====

void FUN_0042a280(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  int iVar6;
  undefined1 local_54 [2];
  undefined1 auStack_52 [34];
  void *local_30;
  uint local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a008;
  local_10 = ExceptionList;
  local_14 = local_54 + -0xc;
  ExceptionList = &local_10;
  FUN_00429bf0(param_3);
  iVar2 = *(int *)(in_ECX + 4);
  uVar5 = 0;
  local_8 = 0;
  if (iVar2 != 0) {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x3c;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x3c;
    }
    if (0x4444444U - iVar2 < param_2) {
      FUN_00412e70();
      uVar5 = extraout_ECX;
    }
    if (*(int *)(in_ECX + 4) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x3c;
    }
    if (uVar5 < iVar2 + param_2) {
      if (0x4444444 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (*(int *)(in_ECX + 4) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x3c;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_004297e0();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x3c);
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar2 = FUN_00429c50(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_0042a010(iVar2,param_2,local_54);
      FUN_00429c50(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x3c);
      iVar2 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x3c;
      }
      if (*(int *)(in_ECX + 4) != 0) {
        FUN_004136a0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x3c + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar2) * 0x3c);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      iVar1 = param_2 * 0x3c;
      if ((uint)((iVar2 - param_1) / 0x3c) < param_2) {
        FUN_00429c50(param_1,iVar2,iVar1 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0042a250(*(undefined4 *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x3c,
                     local_54);
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar1;
        local_8 = 0;
        FUN_00429fa0(param_1,*(int *)(in_ECX + 8) + param_2 * -0x3c,local_54);
      }
      else {
        iVar6 = iVar2 + param_2 * -0x3c;
        uVar4 = FUN_00429c50(iVar6,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_00428c60(param_1,iVar6,iVar2,param_1);
        FUN_00429fa0(param_1,iVar1 + param_1,local_54);
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


// ==== Catch@0042a454 @ 0x0042a454 ====

void Catch_0042a454(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + 0x10);
  FUN_004136a0(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@0042a511 @ 0x0042a511 ====

void Catch_0042a511(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x3c;
  FUN_004136a0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0042a5a0 @ 0x0042a5a0 ====

void FUN_0042a5a0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x3c != 0) {
      iVar1 = (param_2 - iVar1) / 0x3c;
      goto LAB_0042a5e9;
    }
  }
  iVar1 = 0;
LAB_0042a5e9:
  FUN_0042a280(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x3c;
  return;
}


// ==== FUN_0042a620 @ 0x0042a620 ====

void FUN_0042a620(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x3c) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x3c))) {
    FUN_0042a5a0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0042a010(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x3c;
  return;
}


// ==== FUN_0042a6b0 @ 0x0042a6b0 ====

void FUN_0042a6b0(int *param_1,undefined2 *param_2)

{
  FUN_00424960(2);
  *(undefined2 *)(*param_1 + param_1[2]) = *param_2;
  *param_1 = *param_1 + 2;
  FUN_00424960(2);
  *(undefined2 *)(*param_1 + param_1[2]) = param_2[1];
  *param_1 = *param_1 + 2;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = *(undefined4 *)(param_2 + 4);
  *param_1 = *param_1 + 4;
  FUN_00424a00(param_2 + 6);
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = *(undefined4 *)(param_2 + 2);
  *param_1 = *param_1 + 4;
  return;
}


// ==== FUN_0042a730 @ 0x0042a730 ====

void FUN_0042a730(int *param_1)

{
  int in_ECX;
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(int *)(in_ECX + 0x10) != 0) {
    iVar2 = (*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x10)) / 0x28;
  }
  *(int *)(in_ECX + 0x1c) = iVar2;
  FUN_00424960(4);
  *(undefined4 *)(param_1[2] + *param_1) = *(undefined4 *)(in_ECX + 0x1c);
  *param_1 = *param_1 + 4;
  if (*(int *)(in_ECX + 0x1c) != 0) {
    iVar2 = 0;
    uVar1 = 0;
    do {
      FUN_0042a6b0(param_1,*(int *)(in_ECX + 0x10) + iVar2);
      uVar1 = uVar1 + 1;
      iVar2 = iVar2 + 0x28;
    } while (uVar1 < *(uint *)(in_ECX + 0x1c));
  }
  return;
}


// ==== FUN_0042a7a0 @ 0x0042a7a0 ====

void FUN_0042a7a0(undefined1 param_1)

{
  void *in_stack_00000014;
  uint in_stack_00000028;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097a0c8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_0042b0c0(&param_1);
  if (in_stack_00000028 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(in_stack_00000014);
  return;
}


// ==== FUN_0042a7f0 @ 0x0042a7f0 ====

void FUN_0042a7f0(void)

{
  undefined4 uVar1;
  void *local_50 [5];
  uint uStack_3c;
  undefined1 auStack_38 [4];
  undefined1 local_34 [2];
  undefined1 local_32 [6];
  undefined1 local_2c [4];
  void *pvStack_28;
  undefined1 local_24;
  uint local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097a0e2;
  pvStack_c = ExceptionList;
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = 0;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  FUN_0042a990(local_34);
  FUN_0042a990(local_32);
  FUN_0042aa30(local_2c);
  uVar1 = FUN_00424e50(local_50);
  puStack_8._0_1_ = 1;
  FUN_00401660(uVar1,0,0xffffffff);
  puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
  if (0xf < uStack_3c) {
    _free(local_50[0]);
    return;
  }
  FUN_00427da0(local_34);
  FUN_0042b0c0(auStack_38);
  if (local_14 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(pvStack_28);
  return;
}


// ==== FUN_0042a8d0 @ 0x0042a8d0 ====

void FUN_0042a8d0(undefined4 param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  int in_ECX;
  uint uVar3;
  
  uVar2 = FUN_00424d90();
  puVar1 = (uint *)(in_ECX + 0x1c);
  *(undefined4 *)(in_ECX + 8) = uVar2;
  FUN_00425580(puVar1);
  uVar3 = 0;
  if (*puVar1 != 0) {
    do {
      FUN_0042a7f0(param_1);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar1);
  }
  return;
}


// ==== FUN_0042a910 @ 0x0042a910 ====

void FUN_0042a910(undefined2 *param_1,undefined2 *param_2)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097a051;
  local_c = ExceptionList;
  local_4 = 0;
  if (param_1 != (undefined2 *)0x0) {
    ExceptionList = &local_c;
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    *(undefined4 *)(param_1 + 2) = *(undefined4 *)(param_2 + 2);
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
    *(undefined4 *)(param_1 + 0x12) = 0xf;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined1 *)(param_1 + 8) = 0;
    FUN_00401660(param_2 + 6,0,0xffffffff);
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0042a990 @ 0x0042a990 ====

void FUN_0042a990(undefined2 *param_1)

{
  code *pcVar1;
  void *pvVar2;
  uint *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a068;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = *(undefined2 *)(in_ECX[2] + *in_ECX);
  *in_ECX = *in_ECX + 2;
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


// ==== FUN_0042aa30 @ 0x0042aa30 ====

void FUN_0042aa30(undefined4 *param_1)

{
  code *pcVar1;
  void *pvVar2;
  uint *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a068;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = *(undefined4 *)(in_ECX[2] + *in_ECX);
  *in_ECX = *in_ECX + 4;
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


// ==== FUN_0042aac0 @ 0x0042aac0 ====

undefined2 * FUN_0042aac0(int param_1,int param_2,undefined2 *param_3)

{
  int iVar1;
  undefined2 *puVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x28;
    puVar2 = param_3 + -0x14;
    *puVar2 = *(undefined2 *)(param_2 + -0x28);
    param_3[-0x13] = *(undefined2 *)(param_2 + -0x26);
    *(undefined4 *)(param_3 + -0x12) = *(undefined4 *)(param_2 + -0x24);
    *(undefined4 *)(param_3 + -0x10) = *(undefined4 *)(param_2 + -0x20);
    FUN_00401660(param_2 + -0x1c,0,0xffffffff);
    param_2 = iVar1;
    param_3 = puVar2;
  } while (iVar1 != param_1);
  return puVar2;
}


// ==== FUN_0042ab20 @ 0x0042ab20 ====

int FUN_0042ab20(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0097a080;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x28) {
    FUN_0042a910(param_3,param_1);
    param_3 = param_3 + 0x28;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0042ab6d @ 0x0042ab6d ====

void Catch_0042ab6d(void)

{
  int unaff_EBP;
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 0x10)) {
    puVar1 = (uint *)(iVar2 + 0x24);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      iVar2 = iVar2 + 0x28;
      puVar1 = puVar1 + 10;
    } while (iVar2 != *(int *)(unaff_EBP + 0x10));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0042abd0 @ 0x0042abd0 ====

void FUN_0042abd0(undefined2 *param_1,undefined2 *param_2,undefined2 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_1 = *param_3;
      param_1[1] = param_3[1];
      *(undefined4 *)(param_1 + 2) = *(undefined4 *)(param_3 + 2);
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_3 + 4);
      FUN_00401660(param_3 + 6,0,0xffffffff);
      param_1 = param_1 + 0x14;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_0042ac30 @ 0x0042ac30 ====

void FUN_0042ac30(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0097a090;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_0042a910(param_1,param_3);
    param_1 = param_1 + 0x28;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0042ac7d @ 0x0042ac7d ====

void Catch_0042ac7d(void)

{
  int iVar1;
  int unaff_EBP;
  uint *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(unaff_EBP + -0x14);
  iVar1 = *(int *)(unaff_EBP + 8);
  if (iVar3 != iVar1) {
    puVar2 = (uint *)(iVar3 + 0x24);
    do {
      if (0xf < *puVar2) {
        _free((void *)puVar2[-5]);
        return;
      }
      *puVar2 = 0xf;
      puVar2[-1] = 0;
      *(undefined1 *)(puVar2 + -5) = 0;
      iVar3 = iVar3 + 0x28;
      puVar2 = puVar2 + 10;
    } while (iVar3 != iVar1);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0042ace0 @ 0x0042ace0 ====

int FUN_0042ace0(int param_1,int param_2,undefined4 param_3)

{
  FUN_0042ac30(param_1,param_2,param_3);
  return param_1 + param_2 * 0x28;
}


// ==== FUN_0042ad10 @ 0x0042ad10 ====

void FUN_0042ad10(int param_1,uint param_2,undefined2 *param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  undefined2 local_44;
  undefined2 local_42;
  undefined4 local_40;
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
  puStack_c = &LAB_0097a0a8;
  local_10 = ExceptionList;
  local_42 = param_3[1];
  local_40 = *(undefined4 *)(param_3 + 2);
  local_14 = (undefined1 *)((int)register0x00000010 + -0x50);
  local_44 = *param_3;
  local_3c = *(undefined4 *)(param_3 + 4);
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3 + 6,0,0xffffffff);
  iVar2 = *(int *)(in_ECX + 4);
  local_8 = 0;
  if (iVar2 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x28;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x28;
    }
    if (0x6666666U - iVar1 < param_2) {
      FUN_00412e70();
      uVar5 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x28;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x6666666 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x28;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_00436560();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x28);
      local_8 = CONCAT31(local_8._1_3_,1);
      local_1c = pvVar3;
      iVar2 = FUN_0042ab20(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_0042ac30(iVar2,param_2,&local_44);
      FUN_0042ab20(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x28);
      iVar2 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x28;
      }
      if (*(int *)(in_ECX + 4) != 0) {
        FUN_004136d0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x28 + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar2) * 0x28);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      if ((uint)((iVar2 - param_1) / 0x28) < param_2) {
        FUN_0042ab20(param_1,iVar2,param_2 * 0x28 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0042ace0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x28,
                     &local_44);
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x28;
        local_8 = 0;
        FUN_0042abd0(param_1,*(int *)(in_ECX + 8) + param_2 * -0x28,&local_44);
      }
      else {
        iVar1 = iVar2 + param_2 * -0x28;
        uVar4 = FUN_0042ab20(iVar1,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_0042aac0(param_1,iVar1,iVar2,iVar1);
        FUN_0042abd0(param_1,param_2 * 0x28 + param_1,&local_44);
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


// ==== Catch@0042af05 @ 0x0042af05 ====

void Catch_0042af05(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_004136d0(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@0042afb8 @ 0x0042afb8 ====

void Catch_0042afb8(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x28;
  FUN_004136d0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0042b050 @ 0x0042b050 ====

void FUN_0042b050(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x28 != 0) {
      iVar1 = (param_2 - iVar1) / 0x28;
      goto LAB_0042b095;
    }
  }
  iVar1 = 0;
LAB_0042b095:
  FUN_0042ad10(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x28;
  return;
}


// ==== FUN_0042b0c0 @ 0x0042b0c0 ====

void FUN_0042b0c0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x28) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x28))) {
    FUN_0042b050(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0042ac30(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x28;
  return;
}


// ==== FUN_0042b150 @ 0x0042b150 ====

void FUN_0042b150(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 200) = 0;
  *(undefined4 *)(in_ECX + 0xcc) = 0;
  *(undefined4 *)(in_ECX + 0xd0) = 0;
  *(undefined4 *)(in_ECX + 0xd4) = 0;
  return;
}


// ==== FUN_0042b170 @ 0x0042b170 ====

void FUN_0042b170(int param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 200 + param_1 * 4) = param_2;
  return;
}


// ==== FUN_0042b190 @ 0x0042b190 ====

undefined4 FUN_0042b190(int param_1)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 200 + param_1 * 4);
}


// ==== FUN_0042b1a0 @ 0x0042b1a0 ====

void FUN_0042b1a0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_0042b1b0 @ 0x0042b1b0 ====

void FUN_0042b1b0(int *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  int *piVar8;
  int in_ECX;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  undefined4 *puVar12;
  
  piVar7 = param_1;
  iVar9 = *(int *)(in_ECX + 0x80);
  FUN_00424960(4);
  *(int *)(param_1[2] + *param_1) = iVar9;
  *param_1 = *param_1 + 4;
  if (iVar9 != 0) {
    puVar2 = *(undefined4 **)(in_ECX + 0x7c);
    puVar3 = (undefined4 *)*puVar2;
    puVar6 = puVar3;
joined_r0x0042b1ee:
    puVar12 = puVar3;
    if (puVar12 != puVar2) {
      FUN_00424a00(puVar12 + 3);
      uVar4 = puVar12[0xc];
      FUN_00424960(4);
      *(undefined4 *)(piVar7[2] + *piVar7) = uVar4;
      *piVar7 = *piVar7 + 4;
      piVar5 = (int *)puVar12[0xb];
      piVar11 = (int *)*piVar5;
      param_1 = piVar11;
      if (piVar11 != piVar5) {
        do {
          FUN_00424960(4);
          *(int *)(piVar7[2] + *piVar7) = piVar11[3];
          *piVar7 = *piVar7 + 4;
          if (piVar11[5] == 0) {
            iVar9 = 0;
          }
          else {
            iVar9 = (piVar11[6] - piVar11[5]) / 0x14;
          }
          FUN_00424960(4);
          *(int *)(piVar7[2] + *piVar7) = iVar9;
          *piVar7 = *piVar7 + 4;
          puVar3 = (undefined4 *)piVar11[6];
          puVar10 = (undefined4 *)piVar11[5];
          if (puVar10 != puVar3) {
            piVar11 = puVar10 + 2;
            do {
              FUN_00424960(4);
              *(undefined4 *)(piVar7[2] + *piVar7) = *puVar10;
              *piVar7 = *piVar7 + 4;
              if (*piVar11 == 0) {
                iVar9 = 0;
              }
              else {
                iVar9 = piVar11[1] - *piVar11 >> 2;
              }
              FUN_00424960(4);
              *(int *)(piVar7[2] + *piVar7) = iVar9;
              *piVar7 = *piVar7 + 4;
              FUN_004249c0(*piVar11,iVar9 * 4);
              puVar10 = puVar10 + 5;
              piVar11 = piVar11 + 5;
            } while (puVar10 != puVar3);
            puVar12 = puVar6;
            piVar11 = param_1;
          }
          if (*(char *)((int)piVar11 + 0x21) == '\0') {
            param_1 = (int *)piVar11[2];
            if (*(char *)((int)param_1 + 0x21) == '\0') {
              cVar1 = *(char *)(*param_1 + 0x21);
              piVar11 = (int *)*param_1;
              while (cVar1 == '\0') {
                cVar1 = *(char *)(*piVar11 + 0x21);
                param_1 = piVar11;
                piVar11 = (int *)*piVar11;
              }
            }
            else {
              param_1 = (int *)piVar11[1];
              if (*(char *)((int)param_1 + 0x21) == '\0') {
                while( true ) {
                  piVar8 = param_1;
                  param_1 = piVar8;
                  if ((piVar11 != (int *)piVar8[2]) ||
                     (param_1 = (int *)piVar8[1], *(char *)((int)param_1 + 0x21) != '\0')) break;
                  piVar11 = piVar8;
                }
              }
            }
            piVar11 = param_1;
          }
        } while (piVar11 != piVar5);
      }
      puVar3 = puVar12;
      if (*(char *)((int)puVar12 + 0x35) == '\0') {
        puVar6 = (undefined4 *)puVar12[2];
        if (*(char *)((int)puVar6 + 0x35) == '\0') {
          cVar1 = *(char *)((int)*puVar6 + 0x35);
          puVar12 = (undefined4 *)*puVar6;
          while (puVar3 = puVar6, cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar12 + 0x35);
            puVar6 = puVar12;
            puVar12 = (undefined4 *)*puVar12;
          }
        }
        else {
          puVar3 = (undefined4 *)puVar12[1];
          puVar6 = puVar3;
          if (*(char *)((int)puVar3 + 0x35) == '\0') {
            while( true ) {
              puVar10 = puVar3;
              puVar3 = puVar10;
              puVar6 = puVar10;
              if (puVar12 != (undefined4 *)puVar10[2]) break;
              puVar6 = (undefined4 *)puVar10[1];
              puVar3 = puVar6;
              if (*(char *)((int)puVar6 + 0x35) != '\0') break;
              puVar12 = puVar10;
            }
          }
        }
      }
      goto joined_r0x0042b1ee;
    }
  }
  return;
}


// ==== FUN_0042b3c0 @ 0x0042b3c0 ====

undefined4 FUN_0042b3c0(uint param_1,uint param_2,uint *param_3)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int in_ECX;
  uint uVar6;
  uint *puVar7;
  
  puVar2 = (undefined4 *)**(undefined4 **)(in_ECX + 0xa4);
  do {
    if (puVar2 == *(undefined4 **)(in_ECX + 0xa4)) {
      return 0;
    }
    puVar7 = (uint *)puVar2[5];
    if (puVar7 != (uint *)puVar2[6]) {
      do {
        uVar5 = *puVar7 / *(uint *)(in_ECX + 0xc);
        uVar6 = *puVar7 % *(uint *)(in_ECX + 0xc);
        if ((((uVar6 <= param_1) && (param_1 < uVar6 + (ushort)puVar7[1])) && (uVar5 <= param_2)) &&
           (param_2 < (ushort)puVar7[1] + uVar5)) {
          *param_3 = *puVar7;
          param_3[1] = puVar7[1];
          param_3[2] = puVar7[2];
          return 1;
        }
        puVar7 = puVar7 + 3;
      } while (puVar7 != (uint *)puVar2[6]);
    }
    if (*(char *)((int)puVar2 + 0x25) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x25) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x25);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x25);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x25);
        puVar4 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar4, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x25);
          puVar4 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  } while( true );
}


// ==== FUN_0042b4a0 @ 0x0042b4a0 ====

int FUN_0042b4a0(int param_1)

{
  int in_ECX;
  
  FUN_0042ed30(&param_1,*(undefined4 *)(in_ECX + 0x94),*(undefined4 *)(in_ECX + 0x98),param_1);
  if (param_1 == *(int *)(in_ECX + 0x98)) {
    return -1;
  }
  return (param_1 - *(int *)(in_ECX + 0x94)) / 0x1c;
}


// ==== FUN_0042b500 @ 0x0042b500 ====

void FUN_0042b500(uint param_1,undefined4 param_2,int *param_3,int *param_4,int param_5,int param_6)

{
  char cVar1;
  undefined4 *puVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int in_ECX;
  undefined4 *puVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x88);
  puVar7 = (undefined4 *)*puVar2;
  puVar4 = puVar7;
  while (puVar7 != puVar2) {
    puVar3 = (uint *)puVar7[0xc];
    puVar9 = (uint *)puVar7[0xb];
    if ((uint *)puVar7[0xb] != puVar3) {
      do {
        uVar6 = *puVar9 / param_1;
        uVar8 = *puVar9 % param_1;
        puVar10 = puVar9 + 2;
        *puVar9 = *param_3 * uVar8 +
                  param_3[1] * uVar6 + param_5 +
                  (*param_4 * uVar8 + param_4[1] * uVar6 + param_6) * *(int *)(in_ECX + 0xc);
        puVar9 = puVar10;
      } while (puVar10 != puVar3);
      puVar7 = puVar4;
    }
    if (*(char *)((int)puVar7 + 0x39) == '\0') {
      puVar4 = (undefined4 *)puVar7[2];
      if (*(char *)((int)puVar4 + 0x39) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x39);
        puVar7 = puVar4;
        puVar5 = (undefined4 *)*puVar4;
        while (puVar4 = puVar7, cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x39);
          puVar7 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar7[1] + 0x39);
        puVar4 = (undefined4 *)puVar7[1];
        puVar5 = puVar7;
        while ((puVar7 = puVar4, puVar4 = puVar7, cVar1 == '\0' &&
               (puVar5 == (undefined4 *)puVar7[2]))) {
          cVar1 = *(char *)((int)puVar7[1] + 0x39);
          puVar4 = (undefined4 *)puVar7[1];
          puVar5 = puVar7;
        }
      }
    }
  }
  return;
}


// ==== FUN_0042b5e0 @ 0x0042b5e0 ====

void FUN_0042b5e0(int *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  int iVar5;
  undefined4 *puVar6;
  
  iVar5 = *(int *)(in_ECX + 0xa8);
  FUN_00424960(4);
  *(int *)(param_1[2] + *param_1) = iVar5;
  *param_1 = *param_1 + 4;
  if (iVar5 != 0) {
    puVar2 = *(undefined4 **)(in_ECX + 0xa4);
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      iVar5 = *(int *)(in_ECX + 0x94);
      if ((iVar5 == 0) || ((uint)((*(int *)(in_ECX + 0x98) - iVar5) / 0x1c) <= (uint)puVar3[3])) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      FUN_00424a00(iVar5 + puVar3[3] * 0x1c);
      if (puVar3[5] == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = (int)(puVar3[6] - puVar3[5]) / 0xc;
      }
      FUN_00424960(4);
      *(int *)(param_1[2] + *param_1) = iVar5;
      *param_1 = *param_1 + 4;
      puVar4 = (undefined4 *)puVar3[6];
      for (puVar6 = (undefined4 *)puVar3[5]; puVar6 != puVar4; puVar6 = puVar6 + 3) {
        FUN_00424960(4);
        *(undefined4 *)(param_1[2] + *param_1) = *puVar6;
        *param_1 = *param_1 + 4;
        FUN_00424960(2);
        *(undefined2 *)(param_1[2] + *param_1) = *(undefined2 *)(puVar6 + 1);
        *param_1 = *param_1 + 2;
        FUN_00424960(2);
        *(undefined2 *)(param_1[2] + *param_1) = *(undefined2 *)((int)puVar6 + 6);
        *param_1 = *param_1 + 2;
        FUN_00424960(2);
        *(undefined2 *)(param_1[2] + *param_1) = *(undefined2 *)(puVar6 + 2);
        *param_1 = *param_1 + 2;
      }
      FUN_00424960(4);
      *(undefined4 *)(param_1[2] + *param_1) = puVar3[8];
      *param_1 = *param_1 + 4;
      if (*(char *)((int)puVar3 + 0x25) == '\0') {
        puVar6 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar6 + 0x25) == '\0') {
          cVar1 = *(char *)((int)*puVar6 + 0x25);
          puVar3 = puVar6;
          puVar6 = (undefined4 *)*puVar6;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar6 + 0x25);
            puVar3 = puVar6;
            puVar6 = (undefined4 *)*puVar6;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x25);
          puVar4 = (undefined4 *)puVar3[1];
          puVar6 = puVar3;
          while ((puVar3 = puVar4, cVar1 == '\0' && (puVar6 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x25);
            puVar4 = (undefined4 *)puVar3[1];
            puVar6 = puVar3;
          }
        }
      }
    }
  }
  return;
}


// ==== FUN_0042b7a0 @ 0x0042b7a0 ====

uint FUN_0042b7a0(uint param_1,int *param_2,uint *param_3)

{
  uint *puVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  int *piVar7;
  uint extraout_EAX;
  uint *puVar8;
  uint extraout_EAX_00;
  int in_ECX;
  uint uVar9;
  uint *puVar10;
  int *piVar11;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097a1a8;
  local_c = ExceptionList;
  piVar3 = *(int **)(in_ECX + 0xa4);
  piVar11 = (int *)*piVar3;
  piVar7 = piVar3;
  ExceptionList = &local_c;
  if (piVar11 != piVar3) {
    do {
      local_4 = 0xffffffff;
      iVar4 = *(int *)(in_ECX + 0x94);
      if ((iVar4 == 0) || ((uint)((*(int *)(in_ECX + 0x98) - iVar4) / 0x1c) <= (uint)piVar11[3])) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
      piVar7 = (int *)FUN_00401660(iVar4 + piVar11[3] * 0x1c,0,0xffffffff);
      puVar10 = (uint *)piVar11[5];
      local_4 = 0;
      if (puVar10 != (uint *)piVar11[6]) {
        do {
          piVar7 = (int *)(*puVar10 / *(uint *)(in_ECX + 0xc));
          uVar9 = *puVar10 % *(uint *)(in_ECX + 0xc);
          if ((((uVar9 <= param_1) && (param_1 < uVar9 + (ushort)puVar10[1])) && (piVar7 <= param_2)
              ) && (param_2 < (int *)((uint)(ushort)puVar10[1] + (int)piVar7))) {
            FUN_00401660(local_28,0,0xffffffff);
            *param_3 = *puVar10;
            param_3[1] = puVar10[1];
            param_3[2] = puVar10[2];
            puVar6 = (uint *)piVar11[6];
            puVar8 = puVar10 + 3;
            if (puVar8 != puVar6) {
              do {
                *puVar10 = *puVar8;
                puVar10[1] = puVar8[1];
                puVar1 = puVar8 + 2;
                puVar8 = puVar8 + 3;
                puVar10[2] = *puVar1;
                puVar10 = puVar10 + 3;
              } while (puVar8 != puVar6);
            }
            piVar11[6] = piVar11[6] + -0xc;
            if (local_10 < 0x10) {
              ExceptionList = local_c;
              return CONCAT31((int3)((uint)puVar8 >> 8),1);
            }
            _free(local_24);
            return extraout_EAX_00;
          }
          puVar10 = puVar10 + 3;
        } while (puVar10 != (uint *)piVar11[6]);
      }
      local_4 = 0xffffffff;
      if (0xf < local_10) {
        _free(local_24);
        return extraout_EAX;
      }
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
      if (*(char *)((int)piVar11 + 0x25) == '\0') {
        piVar5 = (int *)piVar11[2];
        if (*(char *)((int)piVar5 + 0x25) == '\0') {
          cVar2 = *(char *)(*piVar5 + 0x25);
          piVar7 = (int *)*piVar5;
          while (piVar11 = piVar5, cVar2 == '\0') {
            cVar2 = *(char *)(*piVar7 + 0x25);
            piVar5 = piVar7;
            piVar7 = (int *)*piVar7;
          }
        }
        else {
          cVar2 = *(char *)(piVar11[1] + 0x25);
          piVar5 = (int *)piVar11[1];
          while ((piVar7 = piVar5, cVar2 == '\0' && (piVar11 == (int *)piVar7[2]))) {
            cVar2 = *(char *)(piVar7[1] + 0x25);
            piVar5 = (int *)piVar7[1];
            piVar11 = piVar7;
          }
          piVar11 = piVar7;
        }
      }
    } while (piVar11 != piVar3);
  }
  ExceptionList = local_c;
  return (uint)piVar7 & 0xffffff00;
}


// ==== FUN_0042b9b0 @ 0x0042b9b0 ====

undefined4 FUN_0042b9b0(uint param_1,uint param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  uint *puVar7;
  uint uVar8;
  int *piVar9;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097a1ba;
  local_c = ExceptionList;
  piVar2 = *(int **)(in_ECX + 0xa4);
  piVar9 = (int *)*piVar2;
  ExceptionList = &local_c;
  if (piVar9 != piVar2) {
    do {
      local_4 = 0xffffffff;
      iVar3 = *(int *)(in_ECX + 0x94);
      if ((iVar3 == 0) || ((uint)((*(int *)(in_ECX + 0x98) - iVar3) / 0x1c) <= (uint)piVar9[3])) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
      FUN_00401660(iVar3 + piVar9[3] * 0x1c,0,0xffffffff);
      puVar7 = (uint *)piVar9[5];
      local_4 = 0;
      if (puVar7 != (uint *)piVar9[6]) {
        do {
          uVar6 = *puVar7 / *(uint *)(in_ECX + 0xc);
          uVar8 = *puVar7 % *(uint *)(in_ECX + 0xc);
          if ((((uVar8 <= param_1) && (param_1 < uVar8 + (ushort)puVar7[1])) && (uVar6 <= param_2))
             && (param_2 < (ushort)puVar7[1] + uVar6)) {
            FUN_00401660(local_28,0,0xffffffff);
            if (local_10 < 0x10) {
              ExceptionList = local_c;
              return 1;
            }
            _free(local_24);
            return extraout_EAX_00;
          }
          puVar7 = puVar7 + 3;
        } while (puVar7 != (uint *)piVar9[6]);
      }
      local_4 = 0xffffffff;
      if (0xf < local_10) {
        _free(local_24);
        return extraout_EAX;
      }
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
      if (*(char *)((int)piVar9 + 0x25) == '\0') {
        piVar4 = (int *)piVar9[2];
        if (*(char *)((int)piVar4 + 0x25) == '\0') {
          cVar1 = *(char *)(*piVar4 + 0x25);
          piVar9 = piVar4;
          piVar4 = (int *)*piVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar4 + 0x25);
            piVar9 = piVar4;
            piVar4 = (int *)*piVar4;
          }
        }
        else {
          cVar1 = *(char *)(piVar9[1] + 0x25);
          piVar5 = (int *)piVar9[1];
          piVar4 = piVar9;
          while ((piVar9 = piVar5, cVar1 == '\0' && (piVar4 == (int *)piVar9[2]))) {
            cVar1 = *(char *)(piVar9[1] + 0x25);
            piVar5 = (int *)piVar9[1];
            piVar4 = piVar9;
          }
        }
      }
    } while (piVar9 != piVar2);
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_0042bb80 @ 0x0042bb80 ====

/* WARNING: Removing unreachable block (ram,0x0042bd13) */

void FUN_0042bb80(int param_1,uint param_2,undefined4 param_3,int *param_4,int *param_5,int param_6,
                 int param_7)

{
  char cVar1;
  undefined4 *puVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  void **ppvVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  int in_ECX;
  int iVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint *puVar13;
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
  
  puStack_8 = &LAB_0097a1d4;
  puVar2 = *(undefined4 **)(in_ECX + 0xa4);
  puVar11 = (undefined4 *)*puVar2;
  ppvVar6 = &local_c;
  puVar4 = puVar11;
  local_c = ExceptionList;
  do {
    ExceptionList = ppvVar6;
    if (puVar11 == puVar2) {
      ExceptionList = local_c;
      return;
    }
    puVar3 = (uint *)puVar11[6];
    puVar13 = (uint *)puVar11[5];
    if (puVar13 != puVar3) {
      do {
        local_4 = 0xffffffff;
        uVar7 = *puVar13 / param_2;
        uVar12 = *puVar13 % param_2;
        if (param_1 == 0) {
LAB_0042bcbe:
          iVar8 = 0;
LAB_0042bcc0:
          iVar10 = 0;
        }
        else {
          if (param_1 == 1) {
            iVar8 = 1 - (uint)(ushort)puVar13[1];
            goto LAB_0042bcc0;
          }
          if (param_1 == 2) {
            iVar8 = 1 - (uint)(ushort)puVar13[1];
            iVar10 = iVar8;
          }
          else {
            if (param_1 != 3) {
              local_2c = 0xf;
              local_30 = 0;
              local_40 = (void *)((uint)local_40 & 0xffffff00);
              FUN_00401740(s_____data_Map_cpp_776__0099e4b4,0x16);
              local_4 = 0;
              uVar9 = FUN_004022a0(local_28,s_Invalid_Custom_Tile_0099e4cc,local_44);
              local_4 = CONCAT31(local_4._1_3_,1);
              FUN_00796d50(uVar9);
              if (0xf < local_10) {
                _free(local_24);
                return;
              }
              local_10 = 0xf;
              local_14 = 0;
              local_24 = (void *)((uint)local_24 & 0xffffff00);
              local_4 = 0xffffffff;
              if (0xf < local_2c) {
                _free(local_40);
                return;
              }
              local_40 = (void *)((uint)local_40 & 0xffffff00);
              goto LAB_0042bcbe;
            }
            iVar8 = 0;
            iVar10 = 1 - (uint)(ushort)puVar13[1];
          }
        }
        *puVar13 = param_4[1] * uVar7 +
                   *param_4 * uVar12 + iVar8 +
                   (*param_5 * uVar12 + param_5[1] * uVar7 + iVar10 + param_7) *
                   *(int *)(in_ECX + 0xc) + param_6;
        *(ushort *)(puVar13 + 2) = (short)puVar13[2] + (short)param_1 & 3;
        puVar13 = puVar13 + 3;
      } while (puVar13 != puVar3);
      puVar11 = puVar4;
    }
    ppvVar6 = ExceptionList;
    if (*(char *)((int)puVar11 + 0x25) == '\0') {
      puVar4 = (undefined4 *)puVar11[2];
      if (*(char *)((int)puVar4 + 0x25) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x25);
        puVar11 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x25);
          puVar11 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar11[1] + 0x25);
        puVar5 = (undefined4 *)puVar11[1];
        puVar4 = puVar11;
        while ((puVar11 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar11[2]))) {
          cVar1 = *(char *)((int)puVar11[1] + 0x25);
          puVar5 = (undefined4 *)puVar11[1];
          puVar4 = puVar11;
        }
      }
      puVar4 = puVar11;
    }
  } while( true );
}


// ==== FUN_0042bda0 @ 0x0042bda0 ====

void FUN_0042bda0(int *param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  undefined4 *puVar6;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a1e6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = 0x131f510;
  *param_1 = *param_1 + 4;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = *(undefined4 *)(in_ECX + 0xc);
  *param_1 = *param_1 + 4;
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = *(undefined4 *)(in_ECX + 0x10);
  *param_1 = *param_1 + 4;
  if (*(int *)(in_ECX + 0x1c) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = (*(int *)(in_ECX + 0x20) - *(int *)(in_ECX + 0x1c)) / 0x1c;
  }
  if (*(int *)(in_ECX + 0x14) != iVar4) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00401740(s_m_stock_dwNumTexture____m_stock__0099e424,0x36);
    local_4 = 0;
    FUN_00406880(local_28);
    local_4 = 0xffffffff;
    if (local_10 < 0x10) {
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    _free(local_24);
    return;
  }
  FUN_00424960(4);
  *(undefined4 *)(*param_1 + param_1[2]) = *(undefined4 *)(in_ECX + 0x14);
  *param_1 = *param_1 + 4;
  iVar1 = *(int *)(in_ECX + 0x20);
  for (iVar4 = *(int *)(in_ECX + 0x1c); iVar4 != iVar1; iVar4 = iVar4 + 0x1c) {
    FUN_00424a00(iVar4);
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  iVar2 = *(int *)(in_ECX + 0xc);
  iVar5 = (iVar2 + 1) * (iVar1 + 1);
  iVar4 = iVar5 * 4;
  FUN_004249c0(*(undefined4 *)(in_ECX + 0x2c),iVar4);
  FUN_004249c0(*(undefined4 *)(in_ECX + 0x3c),iVar4);
  FUN_004249c0(*(undefined4 *)(in_ECX + 0x4c),iVar4);
  FUN_004249c0(*(undefined4 *)(in_ECX + 0x5c),iVar5 * 0xc);
  FUN_004249c0(*(undefined4 *)(in_ECX + 0x6c),iVar2 * iVar1 * 2);
  FUN_00424a00(in_ECX + 0xac);
  FUN_0042b1b0(param_1);
  FUN_0042b5e0(param_1);
  puVar6 = (undefined4 *)(in_ECX + 200);
  iVar4 = 4;
  do {
    FUN_00424960(4);
    *(undefined4 *)(*param_1 + param_1[2]) = *puVar6;
    *param_1 = *param_1 + 4;
    puVar6 = puVar6 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0042bf90 @ 0x0042bf90 ====

void FUN_0042bf90(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  uint local_34;
  uint local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  int local_1c;
  uint local_18;
  int local_10;
  
  uVar3 = *(int *)(in_ECX + 0x10) + 1;
  uVar6 = *(int *)(in_ECX + 0xc) + 1;
  if (param_1 == 0) {
    local_24 = 0;
    if (uVar3 != 0) {
      local_18 = 0;
      local_28 = 0;
      local_2c = 0;
      do {
        local_34 = 0;
        if (uVar6 >> 1 != 0) {
          local_30 = local_2c;
          uVar4 = local_28;
          param_1 = local_18;
          do {
            iVar9 = *(int *)(in_ECX + 0x2c);
            uVar10 = ((local_18 + uVar6) - local_34) - 1;
            if ((((iVar9 == 0) || ((uint)(*(int *)(in_ECX + 0x30) - iVar9 >> 2) <= param_1)) ||
                (iVar9 == 0)) || ((uint)(*(int *)(in_ECX + 0x30) - iVar9 >> 2) <= uVar10)) {
                    /* WARNING: Subroutine does not return */
              FUN_0042f370();
            }
            *(undefined4 *)(iVar9 + uVar10 * 4) = *(undefined4 *)(iVar9 + uVar4);
            iVar9 = *(int *)(in_ECX + 0x3c);
            if (((iVar9 == 0) || ((uint)(*(int *)(in_ECX + 0x40) - iVar9 >> 2) <= param_1)) ||
               ((iVar9 == 0 || ((uint)(*(int *)(in_ECX + 0x40) - iVar9 >> 2) <= uVar10))))
            goto LAB_0042c418;
            *(undefined4 *)(iVar9 + uVar10 * 4) = *(undefined4 *)(iVar9 + uVar4);
            iVar9 = *(int *)(in_ECX + 0x4c);
            if (((iVar9 == 0) || ((uint)(*(int *)(in_ECX + 0x50) - iVar9 >> 2) <= param_1)) ||
               ((iVar9 == 0 || ((uint)(*(int *)(in_ECX + 0x50) - iVar9 >> 2) <= uVar10))))
            goto LAB_0042c418;
            *(undefined4 *)(iVar9 + uVar10 * 4) = *(undefined4 *)(iVar9 + uVar4);
            iVar9 = *(int *)(in_ECX + 0x5c);
            if ((iVar9 == 0) || ((uint)((*(int *)(in_ECX + 0x60) - iVar9) / 0xc) <= param_1))
            goto LAB_0042c41f;
            iVar5 = *(int *)(in_ECX + 0x5c);
            puVar7 = (undefined4 *)(iVar9 + local_30);
            if ((iVar5 == 0) || ((uint)((*(int *)(in_ECX + 0x60) - iVar5) / 0xc) <= uVar10))
            goto LAB_0042c41f;
            local_30 = local_30 + 0xc;
            param_1 = param_1 + 1;
            puVar8 = (undefined4 *)(iVar5 + uVar10 * 0xc);
            *puVar8 = *puVar7;
            puVar8[1] = puVar7[1];
            puVar8[2] = puVar7[2];
            local_34 = local_34 + 1;
            uVar4 = uVar4 + 4;
          } while (local_34 < uVar6 >> 1);
        }
        local_24 = local_24 + 1;
        local_2c = local_2c + uVar6 * 0xc;
        local_28 = local_28 + uVar6 * 4;
        local_18 = local_18 + uVar6;
      } while (local_24 < uVar3);
    }
  }
  else {
    local_30 = uVar3 >> 1;
    if (local_30 < uVar3) {
      local_28 = local_30 * uVar6;
      local_2c = local_28 * 4;
      local_10 = local_28 * 0xc;
      do {
        local_18 = 0;
        if (uVar6 != 0) {
          param_1 = ((uVar3 - local_30) + -1) * uVar6;
          local_24 = param_1 * 0xc;
          local_34 = local_28;
          iVar9 = param_1 * 4;
          iVar5 = local_2c;
          local_1c = local_10;
          do {
            iVar1 = *(int *)(in_ECX + 0x2c);
            if ((((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x30) - iVar1 >> 2) <= param_1)) ||
                (iVar1 == 0)) || ((uint)(*(int *)(in_ECX + 0x30) - iVar1 >> 2) <= local_34)) {
                    /* WARNING: Subroutine does not return */
              FUN_0042f370();
            }
            *(undefined4 *)(iVar1 + iVar5) = *(undefined4 *)(iVar1 + iVar9);
            iVar1 = *(int *)(in_ECX + 0x3c);
            if (((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x40) - iVar1 >> 2) <= param_1)) ||
               ((iVar1 == 0 || ((uint)(*(int *)(in_ECX + 0x40) - iVar1 >> 2) <= local_34)))) {
LAB_0042c418:
                    /* WARNING: Subroutine does not return */
              FUN_0042f370();
            }
            *(undefined4 *)(iVar1 + iVar5) = *(undefined4 *)(iVar1 + iVar9);
            iVar1 = *(int *)(in_ECX + 0x4c);
            if (((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x50) - iVar1 >> 2) <= param_1)) ||
               ((iVar1 == 0 || ((uint)(*(int *)(in_ECX + 0x50) - iVar1 >> 2) <= local_34))))
            goto LAB_0042c418;
            *(undefined4 *)(iVar1 + iVar5) = *(undefined4 *)(iVar1 + iVar9);
            iVar1 = *(int *)(in_ECX + 0x5c);
            if ((iVar1 == 0) || ((uint)((*(int *)(in_ECX + 0x60) - iVar1) / 0xc) <= param_1)) {
LAB_0042c41f:
                    /* WARNING: Subroutine does not return */
              FUN_0042f370();
            }
            iVar2 = *(int *)(in_ECX + 0x5c);
            puVar7 = (undefined4 *)(iVar1 + local_24);
            if ((iVar2 == 0) || ((uint)((*(int *)(in_ECX + 0x60) - iVar2) / 0xc) <= local_34))
            goto LAB_0042c41f;
            local_24 = local_24 + 0xc;
            puVar8 = (undefined4 *)(iVar2 + local_1c);
            *puVar8 = *puVar7;
            puVar8[1] = puVar7[1];
            puVar8[2] = puVar7[2];
            param_1 = param_1 + 1;
            local_34 = local_34 + 1;
            local_18 = local_18 + 1;
            local_1c = local_1c + 0xc;
            iVar9 = iVar9 + 4;
            iVar5 = iVar5 + 4;
          } while (local_18 < uVar6);
        }
        local_28 = local_28 + uVar6;
        local_30 = local_30 + 1;
        local_2c = local_2c + uVar6 * 4;
        local_10 = local_10 + uVar6 * 0xc;
      } while (local_30 < uVar3);
    }
  }
  return;
}


// ==== FUN_0042c430 @ 0x0042c430 ====

void FUN_0042c430(uint param_1)

{
  undefined2 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  
  uVar2 = *(uint *)(in_ECX + 0x10);
  uVar3 = *(uint *)(in_ECX + 0xc);
  if (param_1 == 0) {
    local_10 = 0;
    if (uVar2 != 0) {
      param_1 = 0;
      local_1c = 0;
      do {
        if (uVar3 >> 1 != 0) {
          local_20 = param_1;
          local_18 = local_1c;
          uVar7 = 0;
          do {
            iVar6 = *(int *)(in_ECX + 0x6c);
            uVar5 = ((param_1 + uVar3) - uVar7) - 1;
            if ((((iVar6 == 0) || ((uint)(*(int *)(in_ECX + 0x70) - iVar6 >> 1) <= local_20)) ||
                (iVar6 == 0)) || ((uint)(*(int *)(in_ECX + 0x70) - iVar6 >> 1) <= uVar5))
            goto LAB_0042c5fa;
            puVar1 = (undefined2 *)(local_18 + iVar6);
            local_20 = local_20 + 1;
            uVar7 = uVar7 + 1;
            local_18 = local_18 + 2;
            *(undefined2 *)(iVar6 + uVar5 * 2) = *puVar1;
          } while (uVar7 < uVar3 >> 1);
        }
        param_1 = param_1 + uVar3;
        local_10 = local_10 + 1;
        local_1c = local_1c + uVar3 * 2;
      } while (local_10 < uVar2);
    }
  }
  else {
    local_14 = uVar2 >> 1;
    if (local_14 < uVar2) {
      local_1c = local_14 * uVar3;
      local_18 = local_1c * 2;
      do {
        local_10 = 0;
        if (uVar3 != 0) {
          uVar7 = ((uVar2 - local_14) + -1) * uVar3;
          param_1 = local_1c;
          iVar6 = uVar7 * 2;
          iVar8 = local_18;
          do {
            iVar4 = *(int *)(in_ECX + 0x6c);
            if (((iVar4 == 0) || ((uint)(*(int *)(in_ECX + 0x70) - iVar4 >> 1) <= param_1)) ||
               ((iVar4 == 0 || ((uint)(*(int *)(in_ECX + 0x70) - iVar4 >> 1) <= uVar7)))) {
LAB_0042c5fa:
                    /* WARNING: Subroutine does not return */
              FUN_00426d40();
            }
            param_1 = param_1 + 1;
            *(undefined2 *)(iVar6 + iVar4) = *(undefined2 *)(iVar8 + iVar4);
            uVar7 = uVar7 + 1;
            local_10 = local_10 + 1;
            iVar6 = iVar6 + 2;
            iVar8 = iVar8 + 2;
          } while (local_10 < uVar3);
        }
        local_1c = local_1c + uVar3;
        local_14 = local_14 + 1;
        local_18 = local_18 + uVar3 * 2;
      } while (local_14 < uVar2);
    }
  }
  return;
}


// ==== FUN_0042c600 @ 0x0042c600 ====

void FUN_0042c600(undefined4 *param_1,uint param_2,int *param_3,int *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  int local_70;
  undefined4 *local_68;
  undefined4 *local_48;
  int local_44;
  undefined4 *local_38;
  int local_34;
  void *local_28;
  int local_24;
  void *local_18;
  int local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a210;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00430c20(in_ECX + 0x28);
  local_4 = 0;
  FUN_00430c20(in_ECX + 0x38);
  local_4._0_1_ = 1;
  FUN_00430c20(in_ECX + 0x48);
  local_4._0_1_ = 2;
  FUN_00430d30(in_ECX + 0x58);
  iVar9 = param_2 + 1;
  local_4 = CONCAT31(local_4._1_3_,3);
  local_70 = 0;
  if (0 < iVar9) {
    iVar4 = (int)param_1 + 1;
    param_2 = 0;
    param_1 = local_38;
    puVar7 = local_48;
    do {
      iVar6 = 0;
      if (0 < iVar4) {
        local_68 = param_1;
        puVar8 = puVar7;
        uVar10 = param_2;
        do {
          uVar5 = (param_4[1] * local_70 + *param_4 * iVar6 + param_4[2]) *
                  (*(int *)(in_ECX + 0xc) + 1) + param_3[1] * local_70 + *param_3 * iVar6 +
                  param_3[2];
          if ((local_18 == (void *)0x0) || ((uint)(local_14 - (int)local_18 >> 2) <= uVar10)) {
                    /* WARNING: Subroutine does not return */
            FUN_0042f370();
          }
          iVar3 = *(int *)(in_ECX + 0x2c);
          if ((iVar3 == 0) || ((uint)(*(int *)(in_ECX + 0x30) - iVar3 >> 2) <= uVar5)) {
                    /* WARNING: Subroutine does not return */
            FUN_0042f370();
          }
          *(undefined4 *)(iVar3 + uVar5 * 4) =
               *(undefined4 *)(((int)local_18 - (int)local_48) + (int)puVar8);
          if ((local_48 == (undefined4 *)0x0) || ((uint)(local_44 - (int)local_48 >> 2) <= uVar10))
          {
                    /* WARNING: Subroutine does not return */
            FUN_0042f370();
          }
          iVar3 = *(int *)(in_ECX + 0x3c);
          if ((iVar3 == 0) || ((uint)(*(int *)(in_ECX + 0x40) - iVar3 >> 2) <= uVar5)) {
LAB_0042c96b:
                    /* WARNING: Subroutine does not return */
            FUN_0042f370();
          }
          *(undefined4 *)(iVar3 + uVar5 * 4) = *puVar8;
          if ((local_28 == (void *)0x0) || ((uint)(local_24 - (int)local_28 >> 2) <= uVar10)) {
                    /* WARNING: Subroutine does not return */
            FUN_0042f370();
          }
          iVar3 = *(int *)(in_ECX + 0x4c);
          if ((iVar3 == 0) || ((uint)(*(int *)(in_ECX + 0x50) - iVar3 >> 2) <= uVar5))
          goto LAB_0042c96b;
          *(undefined4 *)(iVar3 + uVar5 * 4) =
               *(undefined4 *)(((int)local_28 - (int)local_48) + (int)puVar8);
          if ((local_38 == (undefined4 *)0x0) ||
             ((uint)((local_34 - (int)local_38) / 0xc) <= uVar10)) {
                    /* WARNING: Subroutine does not return */
            FUN_0042f370();
          }
          iVar3 = *(int *)(in_ECX + 0x5c);
          if ((iVar3 == 0) || ((uint)((*(int *)(in_ECX + 0x60) - iVar3) / 0xc) <= uVar5)) {
                    /* WARNING: Subroutine does not return */
            FUN_0042f370();
          }
          puVar2 = (undefined4 *)(iVar3 + uVar5 * 0xc);
          *puVar2 = *local_68;
          puVar2[1] = local_68[1];
          puVar1 = local_68 + 2;
          iVar6 = iVar6 + 1;
          local_68 = local_68 + 3;
          puVar8 = puVar8 + 1;
          uVar10 = uVar10 + 1;
          puVar2[2] = *puVar1;
        } while (iVar6 < iVar4);
      }
      param_2 = param_2 + iVar4;
      param_1 = param_1 + iVar4 * 3;
      local_70 = local_70 + 1;
      puVar7 = puVar7 + iVar4;
    } while (local_70 < iVar9);
  }
  if (local_38 != (undefined4 *)0x0) {
    _free(local_38);
    return;
  }
  if (local_28 != (void *)0x0) {
    _free(local_28);
    return;
  }
  if (local_48 != (undefined4 *)0x0) {
    _free(local_48);
    return;
  }
  if (local_18 == (void *)0x0) {
    ExceptionList = local_c;
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0042c990 @ 0x0042c990 ====

void FUN_0042c990(int param_1,int param_2,int *param_3,int *param_4,int param_5,int param_6)

{
  undefined2 uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int in_ECX;
  int iVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  int iVar8;
  uint local_2c;
  undefined2 *local_18;
  int local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  piVar3 = param_4;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a222;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00427460(in_ECX + 0x68);
  iVar8 = 0;
  local_4 = 0;
  if (0 < param_2) {
    local_2c = 0;
    puVar6 = local_18;
    do {
      iVar5 = 0;
      if (0 < param_1) {
        param_4 = (int *)local_2c;
        puVar7 = puVar6;
        do {
          uVar4 = param_3[1] * iVar8 +
                  *param_3 * iVar5 + param_5 +
                  (piVar3[1] * iVar8 + *piVar3 * iVar5 + param_6) * *(int *)(in_ECX + 0xc);
          if ((local_18 == (undefined2 *)0x0) || ((uint)(local_14 - (int)local_18 >> 1) <= param_4))
          {
                    /* WARNING: Subroutine does not return */
            FUN_00426d40();
          }
          iVar2 = *(int *)(in_ECX + 0x6c);
          if ((iVar2 == 0) || ((uint)(*(int *)(in_ECX + 0x70) - iVar2 >> 1) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
            FUN_00426d40();
          }
          uVar1 = *puVar7;
          param_4 = (int *)((int)param_4 + 1);
          iVar5 = iVar5 + 1;
          puVar7 = puVar7 + 1;
          *(undefined2 *)(iVar2 + uVar4 * 2) = uVar1;
        } while (iVar5 < param_1);
      }
      local_2c = local_2c + param_1;
      iVar8 = iVar8 + 1;
      puVar6 = puVar6 + param_1;
    } while (iVar8 < param_2);
  }
  if (local_18 == (undefined2 *)0x0) {
    ExceptionList = local_c;
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0042cae0 @ 0x0042cae0 ====

void FUN_0042cae0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  iVar3 = 0;
  iVar1 = *(int *)(in_ECX + 0x10);
  iVar4 = 0;
  iVar2 = *(int *)(in_ECX + 0xc);
  local_c = 1;
  local_8 = 0;
  local_4 = 0;
  local_18 = 0;
  local_14 = 1;
  local_10 = 0;
  local_1c = 0;
  if (param_1 == 1) {
    local_8 = 0xffffffff;
    iVar4 = iVar1 + -1;
    local_18 = 1;
    local_10 = 0;
    local_4 = iVar1;
  }
  else {
    if (param_1 == 2) {
      local_c = 0xffffffff;
      local_14 = 0xffffffff;
      local_1c = iVar1 + -1;
      local_8 = 0;
      iVar4 = iVar2 + -1;
      local_18 = 0;
      local_10 = iVar1;
      local_4 = iVar2;
      goto LAB_0042cb95;
    }
    if (param_1 != 3) goto LAB_0042cb95;
    local_4 = 0;
    local_8 = 1;
    local_18 = 0xffffffff;
    iVar3 = iVar2 + -1;
    local_10 = iVar2;
  }
  local_c = 0;
  local_14 = 0;
  *(int *)(in_ECX + 0xc) = iVar1;
  *(int *)(in_ECX + 0x10) = iVar2;
  local_1c = iVar3;
LAB_0042cb95:
  FUN_0042c600(iVar2,iVar1,&local_c,&local_18);
  FUN_0042c990(iVar2,iVar1,&local_c,&local_18,iVar4,local_1c);
  FUN_0042b500(iVar2,iVar1,&local_c,&local_18,iVar4,local_1c);
  FUN_0042bb80(param_1,iVar2,iVar1,&local_c,&local_18,iVar4,local_1c);
  return;
}


// ==== FUN_0042cc10 @ 0x0042cc10 ====

/* WARNING: Removing unreachable block (ram,0x0042ccd9) */

void FUN_0042cc10(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint *puVar6;
  undefined4 *puVar7;
  void **ppvVar8;
  undefined4 *puVar9;
  uint uVar10;
  int in_ECX;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  void *_Memory;
  int local_28;
  undefined2 local_24;
  undefined2 local_22;
  void *local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097a234;
  iVar2 = *(int *)(in_ECX + 0x10);
  uVar3 = *(uint *)(in_ECX + 0xc);
  puVar4 = *(undefined4 **)(in_ECX + 0xa4);
  puVar5 = (undefined4 *)*puVar4;
  ppvVar8 = &local_c;
  local_c = ExceptionList;
  do {
    if (puVar5 == puVar4) {
      ExceptionList = local_c;
      return;
    }
    _Memory = (void *)0x0;
    local_18 = (void *)0x0;
    local_14 = 0;
    local_10 = 0;
    puVar6 = (uint *)puVar5[6];
    puVar13 = (uint *)puVar5[5];
    local_4 = 0;
    ExceptionList = ppvVar8;
    for (; puVar13 != puVar6; puVar13 = puVar13 + 3) {
      uVar10 = *puVar13 / uVar3;
      uVar12 = *puVar13 % uVar3;
      uVar11 = *(uint *)(in_ECX + 0xc) >> 1;
      if (param_1 == 0) {
        if (uVar12 <= uVar11) {
          local_28 = ((uVar10 + 1) * uVar3 - uVar12) + -1;
LAB_0042cce2:
          local_22 = *(undefined2 *)((int)puVar13 + 6);
          local_24 = (undefined2)puVar13[1];
          FUN_00430ed0(puVar13);
          FUN_00430ed0(&local_28);
          _Memory = local_18;
        }
      }
      else if (uVar10 <= uVar11) {
        local_28 = ((iVar2 - uVar10) + -1) * uVar3 + uVar12;
        *(ushort *)(puVar13 + 2) = (short)puVar13[2] + 2U & 3;
        goto LAB_0042cce2;
      }
    }
    FUN_0042fe10(puVar5[6],_Memory,local_14,param_1);
    local_4 = 0xffffffff;
    if (_Memory != (void *)0x0) {
      _free(_Memory);
      return;
    }
    ppvVar8 = ExceptionList;
    if (*(char *)((int)puVar5 + 0x25) == '\0') {
      puVar7 = (undefined4 *)puVar5[2];
      if (*(char *)((int)puVar7 + 0x25) == '\0') {
        cVar1 = *(char *)((int)*puVar7 + 0x25);
        puVar5 = puVar7;
        puVar7 = (undefined4 *)*puVar7;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar7 + 0x25);
          puVar5 = puVar7;
          puVar7 = (undefined4 *)*puVar7;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar5[1] + 0x25);
        puVar9 = (undefined4 *)puVar5[1];
        puVar7 = puVar5;
        while ((puVar5 = puVar9, cVar1 == '\0' && (puVar7 == (undefined4 *)puVar5[2]))) {
          cVar1 = *(char *)((int)puVar5[1] + 0x25);
          puVar9 = (undefined4 *)puVar5[1];
          puVar7 = puVar5;
        }
      }
    }
  } while( true );
}


// ==== FUN_0042cdc0 @ 0x0042cdc0 ====

undefined4 FUN_0042cdc0(int param_1)

{
  undefined4 extraout_EAX;
  int local_18 [2];
  void *local_10;
  
  param_1 = FUN_0042b4a0(param_1);
  if (param_1 == -1) {
    return 0;
  }
  FUN_0042eb40(local_18,&param_1);
  FUN_00430e00(local_18[0] + 0x10);
  if (local_10 == (void *)0x0) {
    return *(undefined4 *)(local_18[0] + 0x20);
  }
  _free(local_10);
  return extraout_EAX;
}


// ==== FUN_0042ce30 @ 0x0042ce30 ====

void FUN_0042ce30(void)

{
  int iVar1;
  int iVar2;
  undefined4 ****ppppuVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 ****ppppuVar5;
  undefined4 ****ppppuVar6;
  undefined4 ****ppppuVar7;
  int iStack_84;
  int local_80;
  int local_7c;
  int iStack_78;
  undefined1 auStack_74 [4];
  undefined1 auStack_70 [4];
  undefined1 local_6c [4];
  undefined4 ****appppuStack_68 [4];
  int iStack_58;
  uint uStack_54;
  undefined1 auStack_50 [4];
  void *pvStack_4c;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined1 auStack_34 [4];
  void *pvStack_30;
  undefined4 uStack_20;
  uint uStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0097a256;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_00425580(&local_80);
  if (local_80 != 0) {
    local_7c = in_ECX + 0x84;
    do {
      FUN_00424e50(local_6c);
      uStack_c = 0;
      iVar2 = FUN_00405920(&DAT_0099e3e4,0xffffffff,1);
      ppppuVar6 = appppuStack_68[0];
      if (uStack_54 < 0x10) {
        ppppuVar6 = appppuStack_68;
      }
      ppppuVar7 = appppuStack_68[0];
      if (uStack_54 < 0x10) {
        ppppuVar7 = appppuStack_68;
      }
      ppppuVar3 = appppuStack_68[0];
      if (uStack_54 < 0x10) {
        ppppuVar3 = appppuStack_68;
      }
      ppppuVar5 = appppuStack_68[0];
      if (uStack_54 < 0x10) {
        ppppuVar5 = appppuStack_68;
      }
      uVar4 = FUN_00430560(ppppuVar5,(int)ppppuVar3 + iStack_58,(int)ppppuVar7 + iVar2,
                           iStack_58 + (int)ppppuVar6,iStack_78);
      uStack_38 = 0xf;
      uStack_3c = 0;
      pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
      FUN_00401660(uVar4,0,0xffffffff);
      uStack_c._0_1_ = 1;
      uVar4 = FUN_004022a0(auStack_34,s_Effect_Water_0099e3e8,auStack_50);
      uStack_c._0_1_ = 2;
      FUN_00401660(uVar4,0,0xffffffff);
      uStack_c = CONCAT31(uStack_c._1_3_,1);
      if (0xf < uStack_1c) {
        _free(pvStack_30);
        return;
      }
      uStack_1c = 0xf;
      uStack_20 = 0;
      pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
      FUN_00425580(&iStack_78);
      iVar2 = FUN_00432040(local_6c);
      iStack_84 = iStack_78;
      FUN_00430770(iStack_78);
      if (iStack_84 != 0) {
        do {
          FUN_00425580(auStack_74);
          FUN_00427da0(auStack_70);
          iVar1 = *(int *)(iVar2 + 4);
          if ((iVar1 == 0) ||
             ((uint)(*(int *)(iVar2 + 0xc) - iVar1 >> 3) <= (uint)(*(int *)(iVar2 + 8) - iVar1 >> 3)
             )) {
            FUN_0042f630(*(undefined4 *)(iVar2 + 8),1,auStack_74);
          }
          else {
            iVar1 = *(int *)(iVar2 + 8);
            FUN_00429bc0(iVar1,1,auStack_74,iVar2,iStack_78);
            *(int *)(iVar2 + 8) = iVar1 + 8;
          }
          iStack_84 = iStack_84 + -1;
        } while (iStack_84 != 0);
      }
      if (0xf < uStack_38) {
        _free(pvStack_4c);
        return;
      }
      uStack_38 = 0xf;
      uStack_3c = 0;
      pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
      uStack_c = 0xffffffff;
      if (0xf < uStack_54) {
        _free(appppuStack_68[0]);
        return;
      }
      local_80 = local_80 + -1;
      uStack_54 = 0xf;
      iStack_58 = 0;
      appppuStack_68[0] = (undefined4 ****)((uint)appppuStack_68[0] & 0xffffff00);
    } while (local_80 != 0);
  }
  ExceptionList = local_14;
  return;
}


// ==== FUN_0042d0b0 @ 0x0042d0b0 ====

void FUN_0042d0b0(undefined4 param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int local_44 [2];
  undefined1 local_3c [4];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  void *local_24;
  void *local_20;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar2 = param_2;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a278;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0042ed30(&param_2,*(undefined4 *)(in_ECX + 0x94),*(undefined4 *)(in_ECX + 0x98),param_2);
  if (param_2 == *(int *)(in_ECX + 0x98)) {
    if (*(int *)(in_ECX + 0x94) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (*(int *)(in_ECX + 0x98) - *(int *)(in_ECX + 0x94)) / 0x1c;
    }
    FUN_00406720(iVar2);
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_4 = 0;
    local_2c = param_1;
    local_28 = iVar3;
    FUN_00430e00(local_3c);
    local_14 = param_1;
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_00432120(local_44,&local_28);
    if (local_20 != (void *)0x0) {
      _free(local_20);
      return;
    }
  }
  else {
    param_2 = (param_2 - *(int *)(in_ECX + 0x94)) / 0x1c;
    FUN_0042eb40(local_44,&param_2);
    if (local_44[0] == *(int *)(in_ECX + 0xa4)) {
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
      FUN_00401740(s_itCustomTile____m_stock_mapCusto_0099e45c,0x2b);
      local_4 = 2;
      FUN_00406880(&local_28);
      if (local_10 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(local_24);
      return;
    }
    *(undefined4 *)(local_44[0] + 0x20) = param_1;
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0042d250 @ 0x0042d250 ====

uint FUN_0042d250(int param_1,int param_2,undefined4 param_3,int param_4,undefined2 param_5,
                 undefined2 param_6,undefined2 param_7)

{
  code *pcVar1;
  undefined4 uVar2;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint uVar3;
  int *piVar4;
  int in_ECX;
  int iVar5;
  int local_48;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  undefined1 local_3c [4];
  void *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  void *local_24;
  void *local_20;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a29a;
  local_c = ExceptionList;
  param_1 = *(int *)(in_ECX + 0xc) * param_2 + param_1;
  ExceptionList = &local_c;
  FUN_0042ed30(&param_2,*(undefined4 *)(in_ECX + 0x94),*(undefined4 *)(in_ECX + 0x98),param_4);
  local_48 = param_1;
  if (param_2 == *(int *)(in_ECX + 0x98)) {
    if (*(int *)(in_ECX + 0x94) == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = (*(int *)(in_ECX + 0x98) - *(int *)(in_ECX + 0x94)) / 0x1c;
    }
    FUN_00406720(param_4);
    local_38 = (void *)0x0;
    local_34 = 0;
    local_30 = 0;
    local_4 = 0;
    local_42 = 0;
    local_40 = 0;
    local_44 = param_5;
    FUN_00430ed0(&local_48);
    uVar2 = param_3;
    local_2c = param_3;
    local_28 = iVar5;
    FUN_00430e00(local_3c);
    local_14 = uVar2;
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_00432120(&local_48,&local_28);
    if (local_20 != (void *)0x0) {
      _free(local_20);
      return extraout_EAX;
    }
    if (local_38 == (void *)0x0) {
      ExceptionList = local_c;
      return 1;
    }
    _free(local_38);
    return extraout_EAX_00;
  }
  param_4 = (param_2 - *(int *)(in_ECX + 0x94)) / 0x1c;
  FUN_0042eb40(&param_2,&param_4);
  if (param_2 == *(int *)(in_ECX + 0xa4)) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00401740(s_itCustomTile____m_stock_mapCusto_0099e488,0x2b);
    local_4 = 2;
    FUN_00406880(&local_28);
    local_4 = 0xffffffff;
    if (local_10 < 0x10) {
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    _free(local_24);
    return extraout_EAX_01;
  }
  for (piVar4 = *(int **)(param_2 + 0x14); piVar4 != *(int **)(param_2 + 0x18); piVar4 = piVar4 + 3)
  {
    if (*piVar4 == param_1) goto LAB_0042d477;
  }
  local_40 = param_6;
  local_42 = param_7;
  local_44 = param_5;
  piVar4 = (int *)FUN_00430ed0(&local_48);
LAB_0042d477:
  ExceptionList = local_c;
  return (uint)piVar4 & 0xffffff00;
}


// ==== FUN_0042d490 @ 0x0042d490 ====

uint FUN_0042d490(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  uint extraout_EAX;
  uint extraout_EAX_00;
  int in_ECX;
  uint local_34;
  ushort local_30;
  undefined2 local_2e;
  short sStack_2c;
  undefined2 uStack_2a;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097a2ac;
  local_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_4 = 0;
  ExceptionList = &local_c;
  cVar1 = FUN_0042b7a0(param_1,param_2,&local_34,local_28);
  if (cVar1 == '\0') {
    if (local_10 < 0x10) {
      ExceptionList = local_c;
      return 0;
    }
    _free(local_24);
    return extraout_EAX_00;
  }
  sStack_2c = sStack_2c + 1;
  FUN_0042d250(local_34 % *(uint *)(in_ECX + 0xc),local_34 / *(uint *)(in_ECX + 0xc),0,local_28,
               CONCAT22(local_2e,local_30),CONCAT22(uStack_2a,sStack_2c),
               CONCAT22(sStack_2c,local_2e));
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return (uint)local_30;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_0042d570 @ 0x0042d570 ====

void FUN_0042d570(void)

{
  uint uVar1;
  int iVar2;
  uint in_ECX;
  int iVar3;
  int *piVar4;
  uint local_84;
  uint local_80;
  uint local_7c;
  int local_78;
  int local_74;
  int iStack_70;
  undefined1 auStack_6c [4];
  undefined1 auStack_68 [2];
  undefined1 auStack_66 [2];
  undefined1 auStack_64 [4];
  undefined1 auStack_60 [4];
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 local_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097a2ce;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_7c = in_ECX;
  FUN_00425580(&local_80);
  uVar1 = local_80;
  if (local_80 != 0) {
    local_78 = in_ECX + 0x90;
    FUN_00431000(local_80);
    local_84 = 0;
    if (uVar1 != 0) {
      local_74 = local_7c + 0xa0;
      do {
        FUN_00424e50(local_28);
        uStack_4 = 0;
        FUN_00425580(&iStack_70);
        uStack_2c = 0xf;
        uStack_30 = 0;
        pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
        FUN_00401740(&DAT_0099e41c,3);
        uStack_4._0_1_ = 1;
        uStack_48 = 0xf;
        uStack_4c = 0;
        pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
        FUN_00401740(&DAT_0099e420,3);
        uStack_4 = CONCAT31(uStack_4._1_3_,2);
        FUN_00404440(local_28,auStack_44,auStack_60);
        FUN_00406720(local_28);
        local_7c = local_84;
        iVar2 = FUN_00432450(&local_7c);
        iVar3 = iStack_70;
        FUN_00430840(iStack_70);
        for (; iVar3 != 0; iVar3 = iVar3 + -1) {
          FUN_00425580(auStack_6c);
          FUN_0042a990(auStack_68);
          FUN_0042a990(auStack_66);
          FUN_0042a990(auStack_64);
          FUN_00430ed0(auStack_6c);
        }
        piVar4 = (int *)(iVar2 + 0x10);
        FUN_0042fb30(piVar4);
        if ((9 < *piVar4) || (*piVar4 < 0)) {
          *piVar4 = 0;
        }
        if (0xf < uStack_48) {
          _free(pvStack_5c);
          return;
        }
        uStack_48 = 0xf;
        uStack_4c = 0;
        pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
        if (0xf < uStack_2c) {
          _free(pvStack_40);
          return;
        }
        uStack_2c = 0xf;
        uStack_30 = 0;
        pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
        uStack_4 = 0xffffffff;
        if (0xf < uStack_10) {
          _free(pvStack_24);
          return;
        }
        local_84 = local_84 + 1;
        uStack_10 = 0xf;
        uStack_14 = 0;
        pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
      } while (local_84 < local_80);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0042d7b0 @ 0x0042d7b0 ====

void FUN_0042d7b0(int param_1,int param_2)

{
  undefined4 *puVar1;
  char cVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  int *piVar6;
  int in_ECX;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  void *_Memory;
  undefined4 *puVar10;
  int iVar11;
  int *local_b0;
  uint *local_a8;
  undefined4 *local_a4;
  int local_a0;
  undefined4 local_9c [2];
  void *local_94;
  int *local_90;
  int local_8c;
  undefined1 local_88 [4];
  undefined4 *local_84;
  undefined4 *local_80;
  undefined4 local_7c;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 *local_64 [2];
  int local_5c;
  int local_58;
  uint local_54;
  uint *local_50;
  int *local_4c;
  uint local_48;
  int local_44 [2];
  undefined4 *local_3c;
  undefined4 *local_38;
  undefined4 local_34;
  int local_30 [2];
  undefined4 *local_28;
  undefined4 *local_24;
  undefined4 local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  puStack_8 = &LAB_0097a30e;
  local_c = ExceptionList;
  local_4c = *(int **)(param_2 + 4);
  piVar9 = (int *)*local_4c;
  iVar11 = *(int *)(in_ECX + 0x10) + 1;
  uVar8 = *(int *)(in_ECX + 0xc) + 1;
  if (piVar9 == local_4c) {
    return;
  }
  local_48 = uVar8 >> 1;
  ExceptionList = &local_c;
  local_b0 = piVar9;
  local_58 = iVar11;
  local_54 = uVar8;
  do {
    local_70 = 0;
    local_6c = 0;
    local_68 = 0;
    uVar4 = (uint)piVar9[3] / uVar8;
    uVar7 = (uint)piVar9[3] % uVar8;
    if (param_1 == 0) {
      if (uVar7 <= local_48) {
        local_a0 = ((uVar4 + 1) * uVar8 - uVar7) + -1;
        goto LAB_0042d869;
      }
    }
    else if (uVar4 <= local_48) {
      local_a0 = ((iVar11 - uVar4) + -1) * uVar8 + uVar7;
LAB_0042d869:
      local_84 = (undefined4 *)0x0;
      local_80 = (undefined4 *)0x0;
      local_7c = 0;
      local_a4 = (undefined4 *)piVar9[5];
      local_64[0] = (undefined4 *)piVar9[6];
      uStack_3 = 0;
      if (local_a4 != local_64[0]) {
        do {
          _Memory = (void *)0x0;
          piVar9 = (int *)0x0;
          local_94 = (void *)0x0;
          local_90 = (int *)0x0;
          local_8c = 0;
          local_9c[0] = *local_a4;
          local_18 = 0;
          local_14 = 0;
          local_10 = 0;
          local_a8 = (uint *)local_a4[2];
          local_50 = (uint *)local_a4[3];
          local_4 = 3;
          if (local_a8 != local_50) {
            do {
              puVar3 = local_a8;
              uVar8 = *local_a8 / *(uint *)(in_ECX + 0xc);
              uVar7 = *local_a8 % *(uint *)(in_ECX + 0xc);
              uVar4 = *(uint *)(in_ECX + 0xc) >> 1;
              if (param_1 == 0) {
                if (uVar7 <= uVar4) {
                  puVar5 = (uint *)(((uVar8 + 1) * *(int *)(in_ECX + 0xc) - uVar7) + -1);
                  if ((_Memory == (void *)0x0) ||
                     ((uint)(local_8c - (int)_Memory >> 2) <=
                      (uint)((int)piVar9 - (int)_Memory >> 2))) {
                    local_a8 = puVar5;
                    FUN_0042f3e0(piVar9,1,&local_a8);
                    local_a8 = puVar3;
                    goto LAB_0042d9ba;
                  }
                  *piVar9 = (int)puVar5;
                  piVar9 = piVar9 + 1;
                  local_90 = piVar9;
                }
              }
              else if (uVar8 <= uVar4) {
                local_5c = ((*(int *)(in_ECX + 0xc) - uVar8) + -1) * *(int *)(in_ECX + 0xc) + uVar7;
                if ((_Memory == (void *)0x0) ||
                   ((uint)(local_8c - (int)_Memory >> 2) <= (uint)((int)piVar9 - (int)_Memory >> 2))
                   ) {
                  FUN_0042f3e0(piVar9,1,&local_5c);
LAB_0042d9ba:
                  piVar9 = local_90;
                  _Memory = local_94;
                }
                else {
                  *piVar9 = local_5c;
                  piVar9 = piVar9 + 1;
                  local_90 = piVar9;
                }
              }
              local_a8 = local_a8 + 1;
            } while (local_a8 != local_50);
          }
          FUN_004323c0(local_9c);
          local_18 = 0;
          local_14 = 0;
          local_10 = 0;
          local_4 = 1;
          if (_Memory != (void *)0x0) {
            _free(_Memory);
            return;
          }
          local_a4 = local_a4 + 5;
          local_94 = (void *)0x0;
          local_90 = (int *)0x0;
          local_8c = 0;
        } while (local_a4 != local_64[0]);
        piVar9 = local_b0;
      }
      iVar11 = local_a0;
      local_4 = 1;
      local_44[0] = piVar9[3];
      FUN_004318a0(piVar9 + 4);
      local_4 = 4;
      FUN_004328c0(local_64,local_44);
      local_4 = 1;
      if (local_3c != (undefined4 *)0x0) {
        if (local_3c != local_38) {
          puVar10 = local_3c + 2;
          do {
            if ((void *)*puVar10 != (void *)0x0) {
              _free((void *)*puVar10);
              return;
            }
            *puVar10 = 0;
            puVar10[1] = 0;
            puVar10[2] = 0;
            puVar1 = puVar10 + 3;
            puVar10 = puVar10 + 5;
          } while (puVar1 != local_38);
        }
        _free(local_3c);
        return;
      }
      local_3c = (undefined4 *)0x0;
      local_38 = (undefined4 *)0x0;
      local_34 = 0;
      local_30[0] = iVar11;
      FUN_004318a0(local_88);
      _local_4 = CONCAT31(uStack_3,5);
      FUN_004328c0(local_64,local_30);
      if (local_28 != (undefined4 *)0x0) {
        if (local_28 != local_24) {
          puVar10 = local_28 + 2;
          do {
            if ((void *)*puVar10 != (void *)0x0) {
              _free((void *)*puVar10);
              return;
            }
            *puVar10 = 0;
            puVar10[1] = 0;
            puVar10[2] = 0;
            puVar1 = puVar10 + 3;
            puVar10 = puVar10 + 5;
          } while (puVar1 != local_24);
        }
        _free(local_28);
        return;
      }
      local_28 = (undefined4 *)0x0;
      local_24 = (undefined4 *)0x0;
      local_20 = 0;
      if (local_84 != (undefined4 *)0x0) {
        if (local_84 != local_80) {
          puVar10 = local_84 + 2;
          do {
            if ((void *)*puVar10 != (void *)0x0) {
              _free((void *)*puVar10);
              return;
            }
            *puVar10 = 0;
            puVar10[1] = 0;
            puVar10[2] = 0;
            puVar1 = puVar10 + 3;
            puVar10 = puVar10 + 5;
          } while (puVar1 != local_80);
        }
        _free(local_84);
        return;
      }
      uVar8 = local_54;
      iVar11 = local_58;
    }
    if (*(char *)((int)piVar9 + 0x21) == '\0') {
      local_b0 = (int *)piVar9[2];
      if (*(char *)((int)local_b0 + 0x21) == '\0') {
        cVar2 = *(char *)(*local_b0 + 0x21);
        piVar9 = (int *)*local_b0;
        while (cVar2 == '\0') {
          cVar2 = *(char *)(*piVar9 + 0x21);
          local_b0 = piVar9;
          piVar9 = (int *)*piVar9;
        }
      }
      else {
        local_b0 = (int *)piVar9[1];
        if (*(char *)((int)local_b0 + 0x21) == '\0') {
          while( true ) {
            piVar6 = local_b0;
            local_b0 = piVar6;
            if ((piVar9 != (int *)piVar6[2]) ||
               (local_b0 = (int *)piVar6[1], *(char *)((int)local_b0 + 0x21) != '\0')) break;
            piVar9 = piVar6;
          }
        }
      }
      piVar9 = local_b0;
    }
    if (piVar9 == local_4c) {
      ExceptionList = local_c;
      return;
    }
  } while( true );
}


// ==== FUN_0042dc60 @ 0x0042dc60 ====

void FUN_0042dc60(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined4 *local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a320;
  local_c = ExceptionList;
  piVar1 = (int *)**(int **)(in_ECX + 0x7c);
  if (piVar1 == *(int **)(in_ECX + 0x7c)) {
    return;
  }
  ExceptionList = &local_c;
  local_14 = (undefined4 *)FUN_004be360();
  *(undefined1 *)((int)local_14 + 0x21) = 1;
  local_14[1] = local_14;
  *local_14 = local_14;
  local_14[2] = local_14;
  local_10 = 0;
  local_4 = 0;
  FUN_0042d7b0(param_1,piVar1 + 10,local_18);
  FUN_004145c0(*(undefined4 *)(piVar1[0xb] + 4));
  *(int *)(piVar1[0xb] + 4) = piVar1[0xb];
  piVar1[0xc] = 0;
  *(int *)piVar1[0xb] = piVar1[0xb];
  *(int *)(piVar1[0xb] + 8) = piVar1[0xb];
  FUN_00432980(*local_14,local_14);
  local_4 = 0xffffffff;
  FUN_00414630(local_1c,*local_14,local_14);
  _free(local_14);
  return;
}


// ==== FUN_0042ddd0 @ 0x0042ddd0 ====

/* WARNING: Removing unreachable block (ram,0x0042dfc3) */
/* WARNING: Removing unreachable block (ram,0x0042e012) */
/* WARNING: Removing unreachable block (ram,0x0042e020) */
/* WARNING: Removing unreachable block (ram,0x0042e077) */
/* WARNING: Removing unreachable block (ram,0x0042e086) */
/* WARNING: Removing unreachable block (ram,0x0042e0b5) */
/* WARNING: Removing unreachable block (ram,0x0042e0be) */
/* WARNING: Removing unreachable block (ram,0x0042e0dc) */
/* WARNING: Removing unreachable block (ram,0x0042e0e0) */
/* WARNING: Removing unreachable block (ram,0x0042e11f) */
/* WARNING: Removing unreachable block (ram,0x0042e12a) */
/* WARNING: Removing unreachable block (ram,0x0042e130) */
/* WARNING: Removing unreachable block (ram,0x0042e136) */
/* WARNING: Removing unreachable block (ram,0x0042e146) */
/* WARNING: Removing unreachable block (ram,0x0042e158) */
/* WARNING: Removing unreachable block (ram,0x0042e15c) */
/* WARNING: Removing unreachable block (ram,0x0042e165) */
/* WARNING: Removing unreachable block (ram,0x0042e186) */
/* WARNING: Removing unreachable block (ram,0x0042e18c) */
/* WARNING: Removing unreachable block (ram,0x0042e190) */
/* WARNING: Removing unreachable block (ram,0x0042e196) */
/* WARNING: Removing unreachable block (ram,0x0042e19f) */
/* WARNING: Removing unreachable block (ram,0x0042e1b3) */
/* WARNING: Removing unreachable block (ram,0x0042e1b7) */
/* WARNING: Removing unreachable block (ram,0x0042e1c0) */
/* WARNING: Removing unreachable block (ram,0x0042dfd0) */

void FUN_0042ddd0(void)

{
  int iVar1;
  undefined4 ****ppppuVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 ****ppppuVar4;
  undefined4 ****ppppuVar5;
  undefined1 auStack_e6 [2];
  int local_e4;
  undefined4 *puStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  int local_d4;
  undefined1 auStack_d0 [4];
  undefined4 ****local_cc [4];
  int iStack_bc;
  uint uStack_b8;
  undefined1 auStack_90 [32];
  undefined1 auStack_70 [4];
  void *pvStack_6c;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined1 auStack_38 [4];
  undefined1 uStack_34;
  undefined4 uStack_24;
  undefined4 uStack_20;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097a37e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00425580(&local_e4);
  if (local_e4 == 0) {
    ExceptionList = local_c;
    return;
  }
  local_d4 = in_ECX + 0x78;
  FUN_00424e50(local_cc);
  puStack_8 = (undefined1 *)0x0;
  iVar1 = FUN_00405920(&DAT_0099e3f8,0xffffffff,1);
  if (iVar1 < 1) {
    uVar3 = FUN_004022a0(auStack_54,s_Effect_Water__0099e40c,auStack_d0);
    puStack_8._0_1_ = 2;
    FUN_00401660(uVar3,0,0xffffffff);
    puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
    if (0xf < uStack_3c) {
      _free(pvStack_50);
      return;
    }
    uStack_3c = 0xf;
    uStack_40 = 0;
    pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
  }
  else {
    ppppuVar4 = local_cc[0];
    if (uStack_b8 < 0x10) {
      ppppuVar4 = local_cc;
    }
    ppppuVar5 = local_cc[0];
    if (uStack_b8 < 0x10) {
      ppppuVar5 = local_cc;
    }
    ppppuVar2 = local_cc[0];
    if (uStack_b8 < 0x10) {
      ppppuVar2 = local_cc;
    }
    if (uStack_b8 < 0x10) {
      local_cc[0] = local_cc;
    }
    FUN_00430560(local_cc[0],(int)ppppuVar2 + iStack_bc,(int)ppppuVar5 + iVar1,
                 iStack_bc + (int)ppppuVar4,uStack_d8);
    uVar3 = FUN_004022a0(auStack_70,s_Effect_Water_0099e3fc,auStack_d0);
    puStack_8._0_1_ = 1;
    FUN_00401660(uVar3,0,0xffffffff);
    puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
    if (0xf < uStack_58) {
      _free(pvStack_6c);
      return;
    }
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
  }
  FUN_00425580(auStack_e6 + -6);
  puStack_e0 = (undefined4 *)FUN_004be360();
  *(undefined1 *)((int)puStack_e0 + 0x21) = 1;
  puStack_e0[1] = puStack_e0;
  *puStack_e0 = puStack_e0;
  puStack_e0[2] = puStack_e0;
  uStack_dc = 0;
  puStack_8._0_1_ = 3;
  uStack_20 = 0xf;
  uStack_24 = 0;
  uStack_34 = 0;
  FUN_00401660(auStack_d0,0,0xffffffff);
  puStack_8._0_1_ = 7;
  FUN_00432a00(&local_e4);
  puStack_8._0_1_ = 8;
  FUN_00432df0(auStack_90,auStack_38);
  puStack_8._0_1_ = 3;
  FUN_00414720();
  puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
  FUN_00414630(&local_d4,*puStack_e0,puStack_e0);
  _free(puStack_e0);
  return;
}


// ==== FUN_0042e2e0 @ 0x0042e2e0 ====

void FUN_0042e2e0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_6c [8];
  undefined1 local_64 [4];
  undefined4 *local_60;
  undefined4 local_5c;
  undefined1 local_58 [4];
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48 [2];
  void *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34 [10];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097a3b8;
  local_c = ExceptionList;
  local_40 = (void *)0x0;
  local_3c = 0;
  local_38 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48[0] = *param_3;
  local_4 = 1;
  ExceptionList = &local_c;
  FUN_0042fbc0(0,*(undefined4 *)(param_4 + 4),*(undefined4 *)(param_4 + 8),param_1);
  uVar2 = param_2;
  FUN_0042f170(&param_3,param_2);
  puVar1 = param_3;
  if (param_3 == *(undefined4 **)(in_ECX + 0x7c)) {
    local_60 = (undefined4 *)FUN_004be360();
    *(undefined1 *)((int)local_60 + 0x21) = 1;
    local_60[1] = local_60;
    *local_60 = local_60;
    local_60[2] = local_60;
    local_5c = 0;
    local_4._0_1_ = 2;
    FUN_004323c0(local_48);
    local_34[0] = param_1;
    FUN_004318a0(local_58);
    local_4._0_1_ = 3;
    FUN_004328c0(local_6c,local_34);
    local_4._0_1_ = 2;
    FUN_00413700();
    uVar2 = FUN_00432b00(uVar2,local_64);
    local_4._0_1_ = 4;
    FUN_00432df0(local_6c,uVar2);
    local_4._0_1_ = 2;
    FUN_00414720();
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_00414630(&param_1,*local_60,local_60);
    _free(local_60);
    return;
  }
  FUN_00558e70(&param_3,&param_1);
  if (param_3 == (undefined4 *)puVar1[0xb]) {
    FUN_004323c0(local_48);
    local_34[0] = param_1;
    FUN_004318a0(local_58);
    local_4 = CONCAT31(local_4._1_3_,5);
    FUN_004328c0(local_6c,local_34);
    FUN_00413700();
  }
  else {
    FUN_004323c0(local_48);
  }
  FUN_00413700();
  if (local_40 == (void *)0x0) {
    ExceptionList = local_c;
    return;
  }
  _free(local_40);
  return;
}


// ==== FUN_0042e520 @ 0x0042e520 ====

/* WARNING: Removing unreachable block (ram,0x0042e89e) */
/* WARNING: Removing unreachable block (ram,0x0042e8a0) */
/* WARNING: Removing unreachable block (ram,0x0042e8ca) */
/* WARNING: Removing unreachable block (ram,0x0042e71a) */
/* WARNING: Removing unreachable block (ram,0x0042e6c9) */

void FUN_0042e520(void)

{
  uint *puVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  int in_ECX;
  uint local_5c;
  undefined4 local_58;
  undefined4 local_54;
  void *pvStack_40;
  uint uStack_2c;
  void *pvStack_28;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097a3e2;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *(undefined4 *)(in_ECX + 200) = 0;
  *(undefined4 *)(in_ECX + 0xcc) = 0;
  *(undefined4 *)(in_ECX + 0xd0) = 0;
  *(undefined4 *)(in_ECX + 0xd4) = 0;
  uVar3 = FUN_00424d90();
  *(undefined4 *)(in_ECX + 8) = uVar3;
  FUN_00425580();
  FUN_00425580();
  FUN_00425580();
  puVar1 = (uint *)(in_ECX + 0x14);
  *(undefined4 *)(in_ECX + 0xc) = local_54;
  *(undefined4 *)(in_ECX + 0x10) = local_58;
  FUN_00425580();
  FUN_004312d0(*puVar1);
  local_5c = 0;
  if (*puVar1 != 0) {
    do {
      FUN_00424e50();
      uStack_4 = 0;
      FUN_00401660();
      uStack_4 = 0xffffffff;
      if (0xf < uStack_2c) {
        _free(pvStack_40);
        return;
      }
      local_5c = local_5c + 1;
      uStack_2c = 0xf;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    } while (local_5c < *puVar1);
  }
  *puVar1 = 2;
  if (*(int *)(in_ECX + 0x1c) != 0) {
    FUN_00405de0();
    _free(*(void **)(in_ECX + 0x1c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  FUN_00401740();
  uStack_4 = 1;
  FUN_00406720();
  uStack_4 = 0xffffffff;
  FUN_00401740();
  uStack_4 = 2;
  FUN_00406720();
  uStack_4 = 0xffffffff;
  FUN_0042f2a0();
  FUN_00424dc0();
  if (*(void **)(in_ECX + 0x2c) != *(void **)(in_ECX + 0x30)) {
    pvVar4 = _memmove(*(void **)(in_ECX + 0x2c),*(void **)(in_ECX + 0x30),0);
    *(void **)(in_ECX + 0x30) = pvVar4;
  }
  FUN_004300c0();
  FUN_0042f2a0();
  FUN_00424dc0();
  if (*(void **)(in_ECX + 0x3c) != *(void **)(in_ECX + 0x40)) {
    pvVar4 = _memmove(*(void **)(in_ECX + 0x3c),*(void **)(in_ECX + 0x40),0);
    *(void **)(in_ECX + 0x40) = pvVar4;
  }
  FUN_004300c0();
  FUN_0042f2a0();
  FUN_00424dc0();
  if (*(void **)(in_ECX + 0x4c) != *(void **)(in_ECX + 0x50)) {
    pvVar4 = _memmove(*(void **)(in_ECX + 0x4c),*(void **)(in_ECX + 0x50),0);
    *(void **)(in_ECX + 0x50) = pvVar4;
  }
  FUN_004300c0();
  FUN_00430640();
  FUN_00424dc0();
  if (*(int *)(in_ECX + 0x5c) != *(int *)(in_ECX + 0x60)) {
    *(int *)(in_ECX + 0x60) = *(int *)(in_ECX + 0x5c);
  }
  FUN_004302b0();
  FUN_004271c0();
  iVar5 = FUN_00424dc0();
  if (*(void **)(in_ECX + 0x6c) != *(void **)(in_ECX + 0x70)) {
    pvVar4 = _memmove(*(void **)(in_ECX + 0x6c),*(void **)(in_ECX + 0x70),0);
    *(void **)(in_ECX + 0x70) = pvVar4;
  }
  FUN_00426fe0();
  FUN_00424e50();
  puStack_8 = (undefined1 *)0x3;
  FUN_00401660();
  puStack_8 = (undefined1 *)0xffffffff;
  if (0xf < uStack_14) {
    _free(pvStack_28);
    return;
  }
  if (iVar5 == 0x131f510) {
    FUN_0042ddd0();
  }
  else {
    FUN_0042ce30();
  }
  cVar2 = FUN_00424db0();
  if (cVar2 == '\0') {
    FUN_0042d570();
    iVar5 = 4;
    do {
      FUN_0042fb30();
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0042ea00 @ 0x0042ea00 ====

void FUN_0042ea00(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 3) {
    *param_3 = *param_1;
    param_3[1] = param_1[1];
    param_3[2] = param_1[2];
    param_3 = param_3 + 3;
  }
  return;
}


// ==== FUN_0042ea40 @ 0x0042ea40 ====

void FUN_0042ea40(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
    }
    param_3 = param_3 + 1;
  }
  return;
}


// ==== FUN_0042ea70 @ 0x0042ea70 ====

void FUN_0042ea70(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  if (param_2 != 0) {
    do {
      if (param_1 != (undefined4 *)0x0) {
        *param_1 = *param_3;
        param_1[1] = param_3[1];
        param_1[2] = param_3[2];
      }
      param_1 = param_1 + 3;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_0042eab0 @ 0x0042eab0 ====

void FUN_0042eab0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 3) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      param_3[1] = param_1[1];
      param_3[2] = param_1[2];
    }
    param_3 = param_3 + 3;
  }
  return;
}


// ==== FUN_0042eaf0 @ 0x0042eaf0 ====

void FUN_0042eaf0(int *param_1)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *param_1 = in_ECX + 4;
    return;
  }
  *param_1 = *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_0042eb10 @ 0x0042eb10 ====

void FUN_0042eb10(int *param_1)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *param_1 = *(int *)(in_ECX + 0x14) + in_ECX + 4;
    return;
  }
  *param_1 = *(int *)(in_ECX + 0x14) + *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_0042eb40 @ 0x0042eb40 ====

void FUN_0042eb40(undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x25) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((int)puVar1[3] < *param_2) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x25) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < (int)puVar3[3])) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_0042ebb0 @ 0x0042ebb0 ====

/* WARNING: Removing unreachable block (ram,0x0042ec08) */

undefined4 * FUN_0042ebb0(int param_1)

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
  if (*(char *)((int)local_8[1] + 0x35) == '\0') {
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
LAB_0042ec33:
        if (uVar1 <= uVar2) {
          bVar9 = false;
          goto LAB_0042ec40;
        }
LAB_0042ec42:
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
        if (iVar4 == 0) goto LAB_0042ec33;
LAB_0042ec40:
        if (bVar9) goto LAB_0042ec42;
        puVar6 = (undefined4 *)*puVar5;
        local_8 = puVar5;
      }
      puVar5 = puVar6;
    } while (*(char *)((int)puVar6 + 0x35) == '\0');
  }
  return local_8;
}


// ==== FUN_0042ec70 @ 0x0042ec70 ====

/* WARNING: Removing unreachable block (ram,0x0042ecc8) */

undefined4 * FUN_0042ec70(int param_1)

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
  if (*(char *)((int)local_8[1] + 0x39) == '\0') {
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
LAB_0042ecf3:
        if (uVar1 <= uVar2) {
          bVar9 = false;
          goto LAB_0042ed00;
        }
LAB_0042ed02:
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
        if (iVar4 == 0) goto LAB_0042ecf3;
LAB_0042ed00:
        if (bVar9) goto LAB_0042ed02;
        puVar6 = (undefined4 *)*puVar5;
        local_8 = puVar5;
      }
      puVar5 = puVar6;
    } while (*(char *)((int)puVar6 + 0x39) == '\0');
  }
  return local_8;
}


// ==== FUN_0042ed30 @ 0x0042ed30 ====

/* WARNING: Removing unreachable block (ram,0x0042ed66) */

void FUN_0042ed30(int *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  
  if (param_2 == param_3) {
    *param_1 = param_2;
    return;
  }
  uVar1 = *(uint *)(param_4 + 0x14);
  do {
    if (*(uint *)(param_4 + 0x18) < 0x10) {
      pbVar6 = (byte *)(param_4 + 4);
    }
    else {
      pbVar6 = *(byte **)(param_4 + 4);
    }
    uVar2 = *(uint *)(param_2 + 0x14);
    if (uVar2 == 0) {
LAB_0042ed96:
      if ((uVar1 <= uVar2) && (uVar2 == uVar1)) break;
    }
    else {
      uVar4 = uVar2;
      if (uVar1 <= uVar2) {
        uVar4 = uVar1;
      }
      if (*(uint *)(param_2 + 0x18) < 0x10) {
        pbVar5 = (byte *)(param_2 + 4);
      }
      else {
        pbVar5 = *(byte **)(param_2 + 4);
      }
      bVar7 = false;
      iVar3 = 0;
      bVar8 = true;
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
      if (iVar3 == 0) goto LAB_0042ed96;
    }
    param_2 = param_2 + 0x1c;
  } while (param_2 != param_3);
  *param_1 = param_2;
  return;
}


// ==== FUN_0042edd0 @ 0x0042edd0 ====

void FUN_0042edd0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0042eab0(param_1,param_2,param_3);
  return;
}


// ==== FUN_0042edf0 @ 0x0042edf0 ====

int FUN_0042edf0(int param_1,int param_2,undefined4 param_3)

{
  FUN_0042ea70(param_1,param_2,param_3);
  return param_1 + param_2 * 0xc;
}


// ==== FUN_0042ee20 @ 0x0042ee20 ====

void FUN_0042ee20(uint param_1,uint param_2,int *param_3,uint param_4,uint param_5)

{
  uint uVar1;
  undefined1 *puVar2;
  int *piVar3;
  void *_Dst;
  int *piVar4;
  int in_ECX;
  size_t sVar5;
  void *_Src;
  int iVar6;
  uint uVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  if ((*(uint *)(in_ECX + 0x14) < param_1) || (*(uint *)((int)param_3 + 0x14) < param_4)) {
    FUN_0079dba3();
  }
  uVar1 = *(int *)(in_ECX + 0x14) - param_1;
  if (uVar1 < param_2) {
    param_2 = uVar1;
  }
  uVar1 = *(int *)((int)param_3 + 0x14) - param_4;
  if (uVar1 < param_5) {
    param_5 = uVar1;
  }
  if (-param_5 - 1 <= *(int *)(in_ECX + 0x14) - param_2) {
    FUN_0079dbe3();
  }
  uVar1 = *(uint *)(in_ECX + 0x14);
  uVar7 = (uVar1 - param_2) + param_5;
  sVar5 = (uVar1 - param_1) - param_2;
  if (uVar1 < uVar7) {
    if (uVar7 == 0xffffffff) {
      FUN_0079dbe3();
    }
    if (*(uint *)(in_ECX + 0x18) < uVar7) {
      FUN_00401410(uVar7,*(undefined4 *)(in_ECX + 0x14));
    }
    else if (uVar7 == 0) {
      *(undefined4 *)(in_ECX + 0x14) = 0;
      if (*(uint *)(in_ECX + 0x18) < 0x10) {
        puVar2 = (undefined1 *)(in_ECX + 4);
      }
      else {
        puVar2 = *(undefined1 **)(in_ECX + 4);
      }
      *puVar2 = 0;
    }
  }
  piVar8 = (int *)(in_ECX + 4);
  if ((int *)in_ECX != param_3) {
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      piVar4 = piVar8;
      piVar3 = piVar8;
    }
    else {
      piVar4 = (int *)*piVar8;
      piVar3 = (int *)*piVar8;
    }
    _memmove((void *)((int)piVar4 + param_5 + param_1),(void *)((int)piVar3 + param_2 + param_1),
             sVar5);
    if (*(uint *)((int)param_3 + 0x18) < 0x10) {
      iVar6 = (int)param_3 + 4;
    }
    else {
      iVar6 = *(int *)((int)param_3 + 4);
    }
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      piVar3 = piVar8;
    }
    else {
      piVar3 = (int *)*piVar8;
    }
    puVar9 = (undefined4 *)(param_4 + iVar6);
    puVar10 = (undefined4 *)(param_1 + (int)piVar3);
    for (uVar1 = param_5 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    for (param_5 = param_5 & 3; param_5 != 0; param_5 = param_5 - 1) {
      *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    goto LAB_0042f152;
  }
  if (param_2 < param_5) {
    if (param_4 <= param_1) {
      if (*(uint *)(in_ECX + 0x18) < 0x10) {
        piVar4 = piVar8;
        piVar3 = piVar8;
      }
      else {
        piVar4 = (int *)*piVar8;
        piVar3 = (int *)*piVar8;
      }
      _memmove((void *)((int)piVar4 + param_5 + param_1),(void *)((int)piVar3 + param_2 + param_1),
               sVar5);
      sVar5 = param_5;
      if (*(uint *)(in_ECX + 0x18) < 0x10) {
        _Src = (void *)((int)piVar8 + param_4);
        _Dst = (void *)((int)piVar8 + param_1);
      }
      else {
        _Src = (void *)(*piVar8 + param_4);
        _Dst = (void *)(*piVar8 + param_1);
      }
      goto LAB_0042f148;
    }
    if (param_4 < param_1 + param_2) {
      if (*(uint *)(in_ECX + 0x18) < 0x10) {
        piVar4 = piVar8;
        piVar3 = piVar8;
      }
      else {
        piVar4 = (int *)*piVar8;
        piVar3 = (int *)*piVar8;
      }
      _memmove((void *)((int)piVar4 + param_1),(void *)((int)piVar3 + param_4),param_2);
      if (*(uint *)(in_ECX + 0x18) < 0x10) {
        piVar4 = piVar8;
        piVar3 = piVar8;
      }
      else {
        piVar4 = (int *)*piVar8;
        piVar3 = (int *)*piVar8;
      }
      _memmove((void *)((int)piVar4 + param_5 + param_1),(void *)((int)piVar3 + param_2 + param_1),
               sVar5);
      if (*(uint *)(in_ECX + 0x18) < 0x10) {
        piVar3 = piVar8;
        param_3 = piVar8;
      }
      else {
        piVar3 = (int *)*piVar8;
        param_3 = (int *)*piVar8;
      }
      sVar5 = param_5 - param_2;
      _Src = (void *)((int)piVar3 + param_5 + param_4);
      _Dst = (void *)((int)param_3 + param_2 + param_1);
      goto LAB_0042f148;
    }
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      piVar4 = piVar8;
      piVar3 = piVar8;
    }
    else {
      piVar4 = (int *)*piVar8;
      piVar3 = (int *)*piVar8;
    }
    _memmove((void *)((int)piVar4 + param_5 + param_1),(void *)((int)piVar3 + param_2 + param_1),
             sVar5);
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      _Src = (void *)((int)piVar8 + param_5 + (param_4 - param_2));
      _Dst = (void *)((int)piVar8 + param_1);
    }
    else {
      _Src = (void *)((*piVar8 - param_2) + param_4 + param_5);
      _Dst = (void *)(*piVar8 + param_1);
    }
  }
  else {
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      piVar4 = piVar8;
      piVar3 = piVar8;
    }
    else {
      piVar4 = (int *)*piVar8;
      piVar3 = (int *)*piVar8;
    }
    _memmove((void *)((int)piVar4 + param_1),(void *)((int)piVar3 + param_4),param_5);
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      _Src = (void *)((int)piVar8 + param_2 + param_1);
      _Dst = (void *)((int)piVar8 + param_5 + param_1);
    }
    else {
      _Src = (void *)(*piVar8 + param_1 + param_2);
      _Dst = (void *)(*piVar8 + param_1 + param_5);
    }
LAB_0042f148:
    param_5 = sVar5;
  }
  _memmove(_Dst,_Src,param_5);
LAB_0042f152:
  *(uint *)(in_ECX + 0x14) = uVar7;
  if (0xf < *(uint *)(in_ECX + 0x18)) {
    piVar8 = (int *)*piVar8;
  }
  *(undefined1 *)((int)piVar8 + uVar7) = 0;
  return;
}


// ==== FUN_0042f170 @ 0x0042f170 ====

void FUN_0042f170(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_0042ebb0(param_2);
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


// ==== FUN_0042f1e0 @ 0x0042f1e0 ====

void FUN_0042f1e0(undefined1 *param_1,undefined1 *param_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a0f0;
  local_10 = ExceptionList;
  uVar1 = *(uint *)(in_ECX + 0x14);
  uVar3 = (int)param_2 - (int)param_1;
  ExceptionList = &local_10;
  if ((uVar1 <= uVar3) && (ExceptionList = &local_10, *(uint *)(in_ECX + 0x18) != uVar3)) {
    ExceptionList = &local_10;
    cVar2 = FUN_00401560(uVar3,1);
    if (cVar2 != '\0') {
      *(uint *)(in_ECX + 0x14) = uVar1;
      if (*(uint *)(in_ECX + 0x18) < 0x10) {
        iVar4 = in_ECX + 4;
      }
      else {
        iVar4 = *(int *)(in_ECX + 4);
      }
      *(undefined1 *)(iVar4 + uVar1) = 0;
    }
  }
  local_8 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    FUN_00405ac0(1,*param_1);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0042f258 @ 0x0042f258 ====

void Catch_0042f258(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x14);
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


// ==== FUN_0042f2a0 @ 0x0042f2a0 ====

void FUN_0042f2a0(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  uint extraout_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a100;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x3fffffff < param_1) {
    ExceptionList = &local_10;
    FUN_00412e70();
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


// ==== Catch@0042f35a @ 0x0042f35a ====

void Catch_0042f35a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0042f370 @ 0x0042f370 ====

void FUN_0042f370(void)

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
  puStack_8 = &LAB_0097a118;
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


// ==== FUN_0042f3e0 @ 0x0042f3e0 ====

void FUN_0042f3e0(void *param_1,uint param_2,undefined4 *param_3)

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
      uVar7 = FUN_00412e70();
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


// ==== FUN_0042f5c0 @ 0x0042f5c0 ====

void FUN_0042f5c0(void)

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
  puStack_8 = &LAB_0097a118;
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


// ==== FUN_0042f630 @ 0x0042f630 ====

void FUN_0042f630(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0097a130;
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
      uVar2 = FUN_0042f5c0();
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


// ==== Catch@0042f7a1 @ 0x0042f7a1 ====

void Catch_0042f7a1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0042f880 @ 0x0042f880 ====

void FUN_0042f880(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0097a140;
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
      FUN_0042f5c0();
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


// ==== Catch@0042fa32 @ 0x0042fa32 ====

void Catch_0042fa32(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_0042fb30 @ 0x0042fb30 ====

void FUN_0042fb30(undefined4 *param_1)

{
  code *pcVar1;
  void *pvVar2;
  uint *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097a158;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = *(undefined4 *)(in_ECX[2] + *in_ECX);
  *in_ECX = *in_ECX + 4;
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


// ==== FUN_0042fbc0 @ 0x0042fbc0 ====

void FUN_0042fbc0(void *param_1,int param_2,int param_3)

{
  size_t _Size;
  int iVar1;
  uint uVar2;
  void *_Dst;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097a170;
  local_10 = ExceptionList;
  iVar7 = *(int *)(in_ECX + 4);
  uVar5 = param_3 - param_2 >> 2;
  if (iVar7 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(in_ECX + 0xc) - iVar7 >> 2;
  }
  uVar8 = CONCAT44(iVar7,iVar1);
  if (uVar5 != 0) {
    if (iVar7 == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = *(int *)(in_ECX + 8) - iVar7 >> 2;
    }
    uVar6 = uVar5;
    ExceptionList = &local_10;
    if (0x3fffffffU - iVar7 < uVar5) {
      ExceptionList = &local_10;
      uVar8 = FUN_00412e70();
      uVar6 = extraout_ECX;
    }
    iVar7 = (int)((ulonglong)uVar8 >> 0x20);
    uVar2 = (uint)uVar8;
    if (iVar7 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8) - iVar7 >> 2;
    }
    if (uVar2 < iVar1 + uVar6) {
      if (0x3fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar7 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(in_ECX + 8) - iVar7 >> 2;
      }
      if (uVar2 < iVar1 + uVar6) {
        if (iVar7 == 0) {
          iVar7 = 0;
        }
        else {
          iVar7 = *(int *)(in_ECX + 8) - iVar7 >> 2;
        }
        uVar2 = iVar7 + uVar6;
      }
      _Dst = operator_new(uVar2 * 4);
      _Size = ((int)param_1 - (int)*(void **)(in_ECX + 4) >> 2) * 4;
      local_8 = 0;
      pvVar3 = _memmove(_Dst,*(void **)(in_ECX + 4),_Size);
      pvVar3 = (void *)FUN_0042ea40(param_2,param_3,(void *)((int)pvVar3 + _Size));
      _memmove(pvVar3,param_1,(*(int *)(in_ECX + 8) - (int)param_1 >> 2) * 4);
      pvVar3 = *(void **)(in_ECX + 4);
      if (pvVar3 == (void *)0x0) {
        iVar7 = 0;
      }
      else {
        iVar7 = *(int *)(in_ECX + 8) - (int)pvVar3 >> 2;
      }
      if (pvVar3 == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 4 + (int)_Dst);
        *(void **)(in_ECX + 8) = (void *)((int)_Dst + (uVar5 + iVar7) * 4);
        *(void **)(in_ECX + 4) = _Dst;
        ExceptionList = local_10;
        return;
      }
      _free(pvVar3);
      return;
    }
    iVar7 = *(int *)(in_ECX + 8);
    if ((uint)(iVar7 - (int)param_1 >> 2) < uVar6) {
      FUN_005a6d90(param_1,iVar7,(void *)(uVar6 * 4 + (int)param_1));
      iVar7 = param_2 + (*(int *)(in_ECX + 8) - (int)param_1 >> 2) * 4;
      local_8 = 2;
      FUN_0042ea40(iVar7,param_3,*(int *)(in_ECX + 8));
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar6 * 4;
      FUN_004cf710(param_2,iVar7,param_1);
      ExceptionList = local_10;
      return;
    }
    iVar1 = iVar7 + uVar6 * -4;
    uVar4 = FUN_005a6d90(iVar1,iVar7,iVar7);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_00822d20(param_1,iVar1,iVar7);
    FUN_004cf710(param_2,param_3,param_1);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0042fd31 @ 0x0042fd31 ====

void Catch_0042fd31(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x1c));
  return;
}


// ==== FUN_0042fe10 @ 0x0042fe10 ====

void FUN_0042fe10(int param_1,int param_2,int param_3)

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
  puStack_c = &LAB_0097a180;
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
      FUN_0042f5c0();
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


// ==== Catch@0042ffb8 @ 0x0042ffb8 ====

void Catch_0042ffb8(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


