// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x820000-0x82ffff

// ==== FUN_00820450 @ 0x00820450 ====

undefined4 FUN_00820450(undefined4 param_1)

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
  puStack_8 = &LAB_009996b8;
  pvStack_c = ExceptionList;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660(param_1,0,0xffffffff);
  local_10 = (void *)0x19;
  local_4 = 0;
  uVar1 = (**(code **)(*DAT_00b5a7cc + 8))(&local_2c);
  if (local_18 < 0x10) {
    ExceptionList = local_10;
    return uVar1;
  }
  _free(local_2c);
  return extraout_EAX;
}


// ==== FUN_008204e0 @ 0x008204e0 ====

void FUN_008204e0(void)

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
  puStack_8 = &LAB_00999728;
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


// ==== FUN_00820550 @ 0x00820550 ====

void * FUN_00820550(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009996e1;
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


// ==== Catch@008205c2 @ 0x008205c2 ====

void Catch_008205c2(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_008205e0 @ 0x008205e0 ====

void FUN_008205e0(void *param_1,uint param_2,undefined4 *param_3)

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
      uVar7 = FUN_008204e0();
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


// ==== FUN_008207c0 @ 0x008207c0 ====

/* WARNING: Removing unreachable block (ram,0x008208d0) */
/* WARNING: Removing unreachable block (ram,0x008208e1) */
/* WARNING: Removing unreachable block (ram,0x008208ea) */
/* WARNING: Removing unreachable block (ram,0x008208ed) */
/* WARNING: Removing unreachable block (ram,0x008208dd) */
/* WARNING: Removing unreachable block (ram,0x008208fb) */
/* WARNING: Removing unreachable block (ram,0x00820908) */
/* WARNING: Removing unreachable block (ram,0x00820913) */
/* WARNING: Removing unreachable block (ram,0x0082090f) */
/* WARNING: Removing unreachable block (ram,0x00820903) */
/* WARNING: Removing unreachable block (ram,0x00820916) */

void FUN_008207c0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00999728;
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
            goto LAB_008209e7;
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
LAB_008209e7:
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


// ==== FUN_00820a90 @ 0x00820a90 ====

/* WARNING: Removing unreachable block (ram,0x00820ba0) */
/* WARNING: Removing unreachable block (ram,0x00820bb1) */
/* WARNING: Removing unreachable block (ram,0x00820bba) */
/* WARNING: Removing unreachable block (ram,0x00820bbd) */
/* WARNING: Removing unreachable block (ram,0x00820bad) */
/* WARNING: Removing unreachable block (ram,0x00820bcb) */
/* WARNING: Removing unreachable block (ram,0x00820bd8) */
/* WARNING: Removing unreachable block (ram,0x00820be3) */
/* WARNING: Removing unreachable block (ram,0x00820bdf) */
/* WARNING: Removing unreachable block (ram,0x00820bd3) */
/* WARNING: Removing unreachable block (ram,0x00820be6) */

void FUN_00820a90(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00999728;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x21) != '\0') {
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
  FUN_004dde50();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x21) == '\0') {
    if (*(char *)(param_2[2] + 0x21) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x21) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x21) == '\0') {
      piVar3 = (int *)FUN_004128f0(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x21) == '\0') {
      uVar4 = FUN_0057dff0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[8] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[8] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[8] == '\0') {
            *(undefined1 *)(piVar5 + 8) = 1;
            *(undefined1 *)(piVar3 + 8) = 0;
            FUN_004bdf70(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x21) == '\0') {
            if ((*(char *)(*piVar5 + 0x20) == '\x01') && (*(char *)(piVar5[2] + 0x20) == '\x01'))
            goto LAB_00820cb7;
            if (*(char *)(piVar5[2] + 0x20) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x20) = 1;
              *(undefined1 *)(piVar5 + 8) = 0;
              FUN_004bdfc0(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 8) = (char)piVar3[8];
            *(undefined1 *)(piVar3 + 8) = 1;
            *(undefined1 *)(piVar5[2] + 0x20) = 1;
            FUN_004bdf70(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[8] == '\0') {
            *(undefined1 *)(piVar5 + 8) = 1;
            *(undefined1 *)(piVar3 + 8) = 0;
            FUN_004bdfc0(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x21) == '\0') {
            if ((*(char *)(piVar5[2] + 0x20) != '\x01') || (*(char *)(*piVar5 + 0x20) != '\x01')) {
              if (*(char *)(*piVar5 + 0x20) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x20) = 1;
                *(undefined1 *)(piVar5 + 8) = 0;
                FUN_004bdf70(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 8) = (char)piVar3[8];
              *(undefined1 *)(piVar3 + 8) = 1;
              *(undefined1 *)(*piVar5 + 0x20) = 1;
              FUN_004bdfc0(piVar3);
              break;
            }
LAB_00820cb7:
            *(undefined1 *)(piVar5 + 8) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 8) = 1;
  }
  if ((void *)param_2[5] == (void *)0x0) {
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[5]);
  return;
}


// ==== FUN_00820d60 @ 0x00820d60 ====

void FUN_00820d60(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) == '\0') {
    FUN_00820d60(*(undefined4 *)((int)param_1 + 8));
    FUN_00446f40();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00820da0 @ 0x00820da0 ====

void FUN_00820da0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00999728;
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
  piVar4 = (int *)FUN_00820550(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00820e99:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_00820e99;
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


// ==== FUN_00820f80 @ 0x00820f80 ====

void FUN_00820f80(void *param_1)

{
  if (*(char *)((int)param_1 + 0x21) == '\0') {
    FUN_00820f80(*(undefined4 *)((int)param_1 + 8));
    FUN_0081f240();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00820fc0 @ 0x00820fc0 ====

void FUN_00820fc0(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009996f0;
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
      uVar1 = FUN_008204e0();
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


// ==== Catch@00821066 @ 0x00821066 ====

void Catch_00821066(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00821080 @ 0x00821080 ====

/* WARNING: Removing unreachable block (ram,0x008210df) */

void FUN_00821080(undefined4 *param_1,undefined4 *param_2)

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
LAB_00821110:
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
        if (uVar5 == 0) goto LAB_00821110;
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
      puVar6 = (undefined4 *)FUN_00820da0(&param_2,1,puVar6,iVar3);
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
    puVar6 = (undefined4 *)FUN_00820da0(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_008211f0 @ 0x008211f0 ====

void FUN_008211f0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_008205e0(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_00821240 @ 0x00821240 ====

void FUN_00821240(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00820d60(piVar6[1]);
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
    FUN_008207c0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00821300 @ 0x00821300 ====

void FUN_00821300(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00820f80(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x21) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x21) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x21);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x21);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x21);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x21);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00820a90(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_008213c0 @ 0x008213c0 ====

undefined4 *
FUN_008213c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999711;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x24);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[3] = *param_4;
    FUN_00820fc0(param_4 + 1);
    *(undefined1 *)(puVar1 + 8) = param_5;
    *(undefined1 *)((int)puVar1 + 0x21) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@00821446 @ 0x00821446 ====

void Catch_00821446(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00821460 @ 0x00821460 ====

void FUN_00821460(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00999728;
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
  piVar4 = (int *)FUN_008213c0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00821559:
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
      if ((char)piVar6[8] == '\0') goto LAB_00821559;
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


// ==== FUN_00821640 @ 0x00821640 ====

void FUN_00821640(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00821240(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00821670 @ 0x00821670 ====

void FUN_00821670(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00821300(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_008216a0 @ 0x008216a0 ====

void FUN_008216a0(undefined4 *param_1,int *param_2)

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
  if (*(char *)((int)puVar5[1] + 0x21) == '\0') {
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
    } while (*(char *)((int)puVar4 + 0x21) == '\0');
  }
  param_2 = puVar5;
  if (bVar2) {
    if (puVar5 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar5 = (undefined4 *)FUN_00821460(&param_2,1,puVar5,piVar3);
      uVar1 = *puVar5;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_004ddea0();
  }
  if (param_2[3] < *piVar3) {
    puVar5 = (undefined4 *)FUN_00821460(&param_2,bVar2,puVar5,piVar3);
    *param_1 = *puVar5;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00821760 @ 0x00821760 ====

void FUN_00821760(byte param_1)

{
  void *in_ECX;
  
  FUN_0081f7b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00821780 @ 0x00821780 ====

undefined4 * FUN_00821780(undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined1 local_8 [8];
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_00821460(param_1,1,*(undefined4 *)(in_ECX + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    if (*param_3 < param_2[3]) {
      FUN_00821460(param_1,1,param_2,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    if (*(int *)(piVar1[2] + 0xc) < *param_3) {
      FUN_00821460(param_1,0,piVar1[2],param_3);
      return param_1;
    }
  }
  else {
    iVar2 = *param_3;
    iVar3 = param_2[3];
    iVar4 = iVar3 - iVar2;
    if (iVar2 < iVar3) {
      FUN_004ddea0();
      if (param_2[3] < iVar2) {
        if (*(char *)(param_2[2] + 0x21) == '\0') {
          FUN_00821460(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_00821460(param_1,0,param_2,param_3);
        return param_1;
      }
      iVar3 = param_2[3];
      iVar4 = iVar3 - iVar2;
    }
    if (SBORROW4(iVar3,iVar2) != iVar4 < 0) {
      FUN_004dde50();
      if ((param_2 == *(int **)(in_ECX + 4)) || (iVar2 < param_2[3])) {
        if (*(char *)(param_2[2] + 0x21) == '\0') {
          FUN_00821460(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_00821460(param_1,0,param_2,param_3);
        return param_1;
      }
    }
  }
  puVar5 = (undefined4 *)FUN_008216a0(local_8,param_3);
  *param_1 = *puVar5;
  return param_1;
}


// ==== FUN_008218f0 @ 0x008218f0 ====

undefined4 * FUN_008218f0(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *extraout_EAX;
  int in_ECX;
  undefined1 local_30 [4];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20 [2];
  void *local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00999750;
  local_c = ExceptionList;
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x21) == '\0') {
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
    } while (*(char *)((int)puVar2 + 0x21) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_1 < (int)puVar3[3])) {
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20[0] = *param_1;
    local_4 = 0;
    ExceptionList = &local_c;
    FUN_00820fc0(local_30);
    local_4 = CONCAT31(local_4._1_3_,1);
    puVar3 = (undefined4 *)FUN_00821780(&param_1,puVar3,local_20);
    puVar3 = (undefined4 *)*puVar3;
    if (local_18 != (void *)0x0) {
      _free(local_18);
      return extraout_EAX;
    }
  }
  ExceptionList = local_c;
  return puVar3 + 4;
}


// ==== FUN_008219b0 @ 0x008219b0 ====

uint FUN_008219b0(int *param_1)

{
  uint uVar1;
  uint3 uVar3;
  uint *puVar2;
  int *in_ECX;
  int iVar4;
  
  iVar4 = *in_ECX;
  uVar3 = (uint3)((uint)iVar4 >> 8);
  if (iVar4 < *param_1) {
    return CONCAT31(uVar3,1);
  }
  if (*param_1 < iVar4) {
    return (uint)uVar3 << 8;
  }
  iVar4 = 0;
  puVar2 = (uint *)(in_ECX + 1);
  do {
    uVar1 = *(uint *)(((int)param_1 - (int)in_ECX) + (int)puVar2);
    if (*puVar2 < uVar1) {
      return CONCAT31((int3)((uint)puVar2 >> 8),1);
    }
    if (uVar1 < *puVar2) break;
    iVar4 = iVar4 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar4 < 3);
  return (uint)puVar2 & 0xffffff00;
}


// ==== FUN_00821a00 @ 0x00821a00 ====

void FUN_00821a00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0c21c;
  return;
}


// ==== FUN_00821a10 @ 0x00821a10 ====

void FUN_00821a10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0c21c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00821a30 @ 0x00821a30 ====

undefined4 * FUN_00821a30(uint *param_1)

{
  uint uVar1;
  int in_ECX;
  uint *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *local_4;
  
  local_4 = *(undefined4 **)(in_ECX + 4);
  puVar4 = (undefined4 *)local_4[1];
  if (*(char *)((int)puVar4 + 0x31) == '\0') {
    do {
      if ((int)puVar4[3] < (int)*param_1) {
LAB_00821a94:
        puVar5 = (undefined4 *)puVar4[2];
      }
      else {
        if ((int)puVar4[3] <= (int)*param_1) {
          iVar3 = 0;
          puVar2 = param_1;
          do {
            puVar2 = puVar2 + 1;
            uVar1 = *(uint *)((int)puVar4 + (0xc - (int)param_1) + (int)puVar2);
            if (uVar1 < *puVar2) goto LAB_00821a94;
          } while ((uVar1 <= *puVar2) && (iVar3 = iVar3 + 1, iVar3 < 3));
        }
        puVar5 = (undefined4 *)*puVar4;
        local_4 = puVar4;
      }
      puVar4 = puVar5;
    } while (*(char *)((int)puVar5 + 0x31) == '\0');
  }
  return local_4;
}


// ==== FUN_00821aa0 @ 0x00821aa0 ====

void FUN_00821aa0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x31) == '\0') {
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


// ==== FUN_00821af0 @ 0x00821af0 ====

void FUN_00821af0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x31) == '\0') {
    FUN_00821af0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00821b30 @ 0x00821b30 ====

void FUN_00821b30(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = operator_new(0x34);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[2] = param_3;
    puVar1[1] = param_2;
    puVar3 = puVar1 + 3;
    for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *param_4;
      param_4 = param_4 + 1;
      puVar3 = puVar3 + 1;
    }
    *(undefined1 *)(puVar1 + 0xc) = param_5;
    *(undefined1 *)((int)puVar1 + 0x31) = 0;
  }
  return;
}


// ==== FUN_00821b80 @ 0x00821b80 ====

void FUN_00821b80(void)

{
  undefined4 *puVar1;
  
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
  return;
}


// ==== FUN_00821bc0 @ 0x00821bc0 ====

int FUN_00821bc0(int param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  int local_4;
  
  param_1 = FUN_00821a30(param_1);
  local_4 = *(int *)(in_ECX + 8);
  if (param_1 != local_4) {
    cVar1 = FUN_008219b0(param_1 + 0xc);
    if (cVar1 == '\0') {
      piVar2 = &param_1;
      goto LAB_00821bfd;
    }
  }
  piVar2 = &local_4;
LAB_00821bfd:
  if (*piVar2 == *(int *)(in_ECX + 8)) {
    return 0;
  }
  return *piVar2 + 0x20;
}


// ==== FUN_00821c50 @ 0x00821c50 ====

void FUN_00821c50(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00999793;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_00a0c22c;
  local_4 = 1;
  FUN_00821af0(*(undefined4 *)(in_ECX[2] + 4));
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  in_ECX[3] = 0;
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  DAT_00b5ac68 = 0;
  local_4 = local_4 & 0xffffff00;
  FUN_00822be0(local_10,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00821cf0 @ 0x00821cf0 ====

void FUN_00821cf0(void)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  bool bVar9;
  undefined1 local_98 [4];
  void *local_94;
  int local_90;
  undefined4 local_8c;
  int local_88;
  int local_84;
  int *local_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined1 local_64 [4];
  void *local_60;
  undefined4 local_50;
  uint local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  void *pvStack_28;
  undefined1 auStack_24 [20];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009997b0;
  pvStack_c = ExceptionList;
  local_4c = 0xf;
  local_50 = 0;
  local_60 = (void *)((uint)local_60 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s_Effect_modeleffect_csv_00a0c1e4,0x16);
  local_4 = 0;
  local_7c = (int *)FUN_00410500(local_64);
  local_4 = 0xffffffff;
  if (0xf < local_4c) {
    _free(local_60);
    return;
  }
  local_4c = 0xf;
  local_50 = 0;
  local_60 = (void *)((uint)local_60 & 0xffffff00);
  local_88 = local_7c[0x11];
  iVar8 = local_7c[0x10] + 0x1c;
  bVar9 = iVar8 == local_88;
  piVar7 = local_7c;
  do {
    while( true ) {
      local_4 = 0xffffffff;
      local_84 = iVar8;
      if (bVar9) {
        iVar8 = (**(code **)(*piVar7 + 4))();
        *(undefined4 *)(iVar8 + 0x28) = 0;
        (**(code **)(*DAT_00b5a7cc + 0x2c))(piVar7);
        ExceptionList = pvStack_10;
        return;
      }
      local_94 = (void *)0x0;
      local_90 = 0;
      local_8c = 0;
      local_4 = 1;
      FUN_00404fb0(iVar8,0x2c,local_98);
      if (local_94 != (void *)0x0) break;
LAB_00821de4:
      local_4 = 0xffffffff;
      if (local_94 != (void *)0x0) {
        FUN_00405de0(local_94,local_90,local_98,local_88);
        _free(local_94);
        return;
      }
      iVar8 = iVar8 + 0x1c;
      bVar9 = iVar8 == local_88;
      local_94 = (void *)0x0;
      local_90 = 0;
      local_8c = 0;
    }
    iVar1 = local_90 - (int)local_94 >> 0x1f;
    iVar6 = (local_90 - (int)local_94) / 0x1c + iVar1;
    if ((uint)(iVar6 - iVar1) < 7) goto LAB_00821de4;
    if (iVar6 == iVar1) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    uStack_78 = thunk_FUN_00796e60(local_94);
    if ((local_94 == (void *)0x0) || ((uint)((local_90 - (int)local_94) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    uStack_74 = thunk_FUN_00796fb0((int)local_94 + 0x1c);
    if ((local_94 == (void *)0x0) || ((uint)((local_90 - (int)local_94) / 0x1c) < 3)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    uStack_70 = thunk_FUN_00796fb0((int)local_94 + 0x38);
    if ((local_94 == (void *)0x0) || ((uint)((local_90 - (int)local_94) / 0x1c) < 4)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    uStack_6c = thunk_FUN_00796fb0((int)local_94 + 0x54);
    if ((local_94 == (void *)0x0) || ((uint)((local_90 - (int)local_94) / 0x1c) < 5)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    iVar8 = thunk_FUN_00796f80((int)local_94 + 0x70);
    if ((local_94 == (void *)0x0) || ((uint)((local_90 - (int)local_94) / 0x1c) < 6)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    uVar3 = thunk_FUN_00796f80((int)local_94 + 0x8c);
    if ((local_94 == (void *)0x0) || ((uint)((local_90 - (int)local_94) / 0x1c) < 7)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    uVar4 = thunk_FUN_00796fb0((int)local_94 + 0xa8);
    if ((local_94 == (void *)0x0) || ((uint)((local_90 - (int)local_94) / 0x1c) < 8)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    uVar5 = thunk_FUN_00796fb0((int)local_94 + 0xc4);
    if ((local_94 == (void *)0x0) || ((uint)((local_90 - (int)local_94) / 0x1c) < 9)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    uVar2 = thunk_FUN_00796f50((int)local_94 + 0xe0);
    pvStack_10 = (void *)CONCAT31(pvStack_10._1_3_,uVar2);
    uStack_48 = uStack_78;
    uStack_44 = uStack_74;
    uStack_3c = uStack_6c;
    uStack_38 = uStack_68;
    uStack_40 = uStack_70;
    pvStack_28 = pvStack_10;
    uStack_34 = uVar3 & 0xffff | iVar8 << 0x10;
    uStack_30 = uVar4;
    uStack_2c = uVar5;
    FUN_00822af0(auStack_24,&uStack_48);
    local_4 = 0xffffffff;
    if (local_94 != (void *)0x0) {
      FUN_00405de0(local_94,local_90,local_98,local_88);
      _free(local_94);
      return;
    }
    iVar8 = local_84 + 0x1c;
    bVar9 = iVar8 == local_88;
    local_94 = (void *)0x0;
    local_90 = 0;
    local_8c = 0;
    piVar7 = local_7c;
  } while( true );
}


// ==== FUN_00822180 @ 0x00822180 ====

void FUN_00822180(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  bool bVar8;
  undefined1 local_98 [4];
  void *local_94;
  int local_90;
  undefined4 local_8c;
  int local_88;
  int local_84;
  int *local_7c;
  undefined1 local_78 [4];
  void *local_74;
  undefined4 local_64;
  uint local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  void *pvStack_28;
  undefined1 auStack_24 [20];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009997cd;
  pvStack_c = ExceptionList;
  local_60 = 0xf;
  local_64 = 0;
  local_74 = (void *)((uint)local_74 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s_Effect_soundscript_csv_00a0c1fc,0x16);
  local_4 = 0;
  local_7c = (int *)FUN_00410500(local_78);
  local_4 = 0xffffffff;
  if (0xf < local_60) {
    _free(local_74);
    return;
  }
  local_60 = 0xf;
  local_64 = 0;
  local_74 = (void *)((uint)local_74 & 0xffffff00);
  local_88 = local_7c[0x11];
  iVar6 = local_7c[0x10] + 0x1c;
  bVar8 = iVar6 == local_88;
  piVar7 = local_7c;
  do {
    while( true ) {
      local_4 = 0xffffffff;
      local_84 = iVar6;
      if (bVar8) {
        iVar6 = (**(code **)(*piVar7 + 4))();
        *(undefined4 *)(iVar6 + 0x28) = 0;
        (**(code **)(*DAT_00b5a7cc + 0x2c))(piVar7);
        ExceptionList = pvStack_10;
        return;
      }
      local_94 = (void *)0x0;
      local_90 = 0;
      local_8c = 0;
      local_4 = 1;
      FUN_00404fb0(iVar6,0x2c,local_98);
      if (local_94 != (void *)0x0) break;
LAB_00822275:
      local_4 = 0xffffffff;
      if (local_94 != (void *)0x0) {
        FUN_00405de0(local_94,local_90,local_98,local_88);
        _free(local_94);
        return;
      }
      iVar6 = iVar6 + 0x1c;
      bVar8 = iVar6 == local_88;
      local_94 = (void *)0x0;
      local_90 = 0;
      local_8c = 0;
    }
    iVar1 = local_90 - (int)local_94 >> 0x1f;
    iVar5 = (local_90 - (int)local_94) / 0x1c + iVar1;
    if ((uint)(iVar5 - iVar1) < 7) goto LAB_00822275;
    if (iVar5 == iVar1) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    uStack_5c = thunk_FUN_00796e60(local_94);
    if ((local_94 == (void *)0x0) || ((uint)((local_90 - (int)local_94) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    uStack_58 = thunk_FUN_00796fb0((int)local_94 + 0x1c);
    if ((local_94 == (void *)0x0) || ((uint)((local_90 - (int)local_94) / 0x1c) < 3)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    uStack_54 = thunk_FUN_00796fb0((int)local_94 + 0x38);
    if ((local_94 == (void *)0x0) || ((uint)((local_90 - (int)local_94) / 0x1c) < 4)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    uVar2 = thunk_FUN_00796fb0((int)local_94 + 0x54);
    if ((local_94 == (void *)0x0) || ((uint)((local_90 - (int)local_94) / 0x1c) < 5)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    uVar3 = thunk_FUN_00796fb0((int)local_94 + 0x70);
    if ((local_94 == (void *)0x0) || ((uint)((local_90 - (int)local_94) / 0x1c) < 6)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    uVar4 = thunk_FUN_00796fb0((int)local_94 + 0x8c);
    if ((local_94 == (void *)0x0) || ((uint)((local_90 - (int)local_94) / 0x1c) < 7)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    uStack_2c = thunk_FUN_00796fb0((int)local_94 + 0xa8);
    uStack_48 = uStack_5c;
    uStack_40 = uStack_54;
    uStack_44 = uStack_58;
    uStack_38 = uStack_4c;
    pvStack_10 = (void *)CONCAT31(pvStack_10._1_3_,1);
    pvStack_28 = pvStack_10;
    uStack_3c = uVar2;
    uStack_34 = uVar3 | 0x40000;
    uStack_30 = uVar4;
    FUN_00822af0(auStack_24,&uStack_48);
    local_4 = 0xffffffff;
    if (local_94 != (void *)0x0) {
      FUN_00405de0(local_94,local_90,local_98,local_88);
      _free(local_94);
      return;
    }
    iVar6 = local_84 + 0x1c;
    bVar8 = iVar6 == local_88;
    local_94 = (void *)0x0;
    local_90 = 0;
    local_8c = 0;
    piVar7 = local_7c;
  } while( true );
}


// ==== FUN_00822580 @ 0x00822580 ====

void FUN_00822580(void)

{
  int in_ECX;
  
  FUN_00821af0(*(undefined4 *)(*(int *)(in_ECX + 8) + 4));
  *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 8);
  *(int *)(*(int *)(in_ECX + 8) + 8) = *(int *)(in_ECX + 8);
  FUN_00821cf0();
  FUN_00822180();
  return;
}


// ==== FUN_008225c0 @ 0x008225c0 ====

void FUN_008225c0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009997ea;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_00a0c22c;
  iVar1 = FUN_00821b80();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x31) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ac68 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ac68 = in_ECX;
  }
  FUN_00821cf0();
  FUN_00822180();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00822660 @ 0x00822660 ====

void FUN_00822660(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00999768;
  local_c = ExceptionList;
  if (0x71c71c5 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00821b30(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0xc] == '\0') {
LAB_00822759:
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
      if ((char)piVar6[0xc] == '\0') goto LAB_00822759;
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


// ==== FUN_00822840 @ 0x00822840 ====

/* WARNING: Removing unreachable block (ram,0x00822953) */
/* WARNING: Removing unreachable block (ram,0x00822963) */
/* WARNING: Removing unreachable block (ram,0x0082296c) */
/* WARNING: Removing unreachable block (ram,0x0082296f) */
/* WARNING: Removing unreachable block (ram,0x0082295f) */
/* WARNING: Removing unreachable block (ram,0x0082297d) */
/* WARNING: Removing unreachable block (ram,0x0082298a) */
/* WARNING: Removing unreachable block (ram,0x00822995) */
/* WARNING: Removing unreachable block (ram,0x00822991) */
/* WARNING: Removing unreachable block (ram,0x00822985) */
/* WARNING: Removing unreachable block (ram,0x00822998) */

void FUN_00822840(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00999768;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x31) != '\0') {
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
            goto LAB_00822a65;
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
LAB_00822a65:
            *(undefined1 *)(piVar5 + 0xc) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xc) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_00822af0 @ 0x00822af0 ====

void FUN_00822af0(undefined4 *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  char cVar3;
  char cVar4;
  uint *puVar5;
  undefined4 *puVar6;
  int in_ECX;
  int iVar7;
  undefined4 *puVar8;
  
  puVar2 = param_2;
  puVar6 = *(undefined4 **)(in_ECX + 4);
  cVar3 = '\x01';
  puVar8 = (undefined4 *)puVar6[1];
  if (*(char *)((int)puVar6[1] + 0x31) == '\0') {
    do {
      puVar6 = puVar8;
      if ((int)*param_2 < (int)puVar6[3]) {
LAB_00822b23:
        cVar3 = '\x01';
      }
      else {
        if ((int)*param_2 <= (int)puVar6[3]) {
          iVar7 = 0;
          puVar5 = param_2;
          do {
            puVar5 = puVar5 + 1;
            uVar1 = *(uint *)((int)puVar6 + (0xc - (int)param_2) + (int)puVar5);
            if (*puVar5 < uVar1) goto LAB_00822b23;
          } while ((*puVar5 <= uVar1) && (iVar7 = iVar7 + 1, iVar7 < 3));
        }
        cVar3 = '\0';
      }
      if (cVar3 == '\0') {
        puVar8 = (undefined4 *)puVar6[2];
      }
      else {
        puVar8 = (undefined4 *)*puVar6;
      }
    } while (*(char *)((int)puVar8 + 0x31) == '\0');
  }
  param_2 = puVar6;
  if (cVar3 != '\0') {
    if (puVar6 == (undefined4 *)**(int **)(in_ECX + 4)) {
      cVar3 = '\x01';
      goto LAB_00822b82;
    }
    FUN_008840e0();
  }
  puVar8 = param_2;
  cVar4 = FUN_008219b0(puVar2);
  if (cVar4 == '\0') {
    *param_1 = puVar8;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_00822b82:
  puVar6 = (undefined4 *)FUN_00822660(&param_2,cVar3,puVar6,puVar2);
  *param_1 = *puVar6;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_00822be0 @ 0x00822be0 ====

void FUN_00822be0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00821af0(piVar6[1]);
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
    FUN_00822840(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00822ca0 @ 0x00822ca0 ====

void FUN_00822ca0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00822be0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00822cd0 @ 0x00822cd0 ====

void FUN_00822cd0(byte param_1)

{
  void *in_ECX;
  
  FUN_00821c50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00822cf0 @ 0x00822cf0 ====

void FUN_00822cf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0c2dc;
  return;
}


// ==== FUN_00822d00 @ 0x00822d00 ====

void FUN_00822d00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0c2dc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00822d20 @ 0x00822d20 ====

void FUN_00822d20(void *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_2 - (int)param_1 >> 2;
  _memmove((void *)(param_3 + iVar1 * -4),param_1,iVar1 * 4);
  return;
}


// ==== FUN_00822d50 @ 0x00822d50 ====

undefined4 FUN_00822d50(undefined4 param_1)

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
  puStack_8 = &LAB_00999808;
  pvStack_c = ExceptionList;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660(param_1,0,0xffffffff);
  local_10 = (void *)0x16;
  local_4 = 0;
  uVar1 = (**(code **)(*DAT_00b5a7cc + 8))(&local_2c);
  if (local_18 < 0x10) {
    ExceptionList = local_10;
    return uVar1;
  }
  _free(local_2c);
  return extraout_EAX;
}


// ==== FUN_00822de0 @ 0x00822de0 ====

undefined4 FUN_00822de0(void)

{
  char cVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 uVar3;
  undefined4 extraout_EAX_02;
  undefined1 local_44 [4];
  void *local_40;
  uint local_2c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00999878;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_00405b90(local_44,0,2);
  local_4 = 0;
  iVar2 = FUN_00403620(0,*(undefined4 *)(iVar2 + 0x14),&DAT_00a0c274,2);
  local_4 = 0xffffffff;
  if (0xf < local_2c) {
    _free(local_40);
    return extraout_EAX;
  }
  if (iVar2 == 0) {
    ExceptionList = local_c;
    return 1;
  }
  iVar2 = FUN_00405b90(local_44,0,2);
  local_4 = 1;
  iVar2 = FUN_00403620(0,*(undefined4 *)(iVar2 + 0x14),&DAT_00a0c278,2);
  local_4 = 0xffffffff;
  if (0xf < local_2c) {
    _free(local_40);
    return extraout_EAX_00;
  }
  if (iVar2 == 0) {
    ExceptionList = local_c;
    return 7;
  }
  iVar2 = FUN_00405b90(local_44,0,2);
  local_4 = 2;
  iVar2 = FUN_00403620(0,*(undefined4 *)(iVar2 + 0x14),&DAT_00a0c27c,2);
  local_4 = 0xffffffff;
  if (0xf < local_2c) {
    _free(local_40);
    return extraout_EAX_01;
  }
  if (iVar2 == 0) {
    ExceptionList = local_c;
    return 2;
  }
  uVar3 = FUN_00405b90(local_44,0,2);
  local_4 = 3;
  cVar1 = FUN_004036a0(uVar3,&DAT_00a0c280);
  local_4 = 0xffffffff;
  if (0xf < local_2c) {
    _free(local_40);
    return extraout_EAX_02;
  }
  if (cVar1 == '\0') {
    uVar3 = FUN_00405b90(local_44,0,2);
    local_4 = 4;
    FUN_004036a0(uVar3,&DAT_00a0c284);
    local_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  ExceptionList = local_c;
  return 4;
}


// ==== FUN_008231e0 @ 0x008231e0 ====

int FUN_008231e0(undefined1 *param_1)

{
  int extraout_EAX;
  int in_ECX;
  undefined1 auStack_54 [4];
  undefined1 local_50;
  undefined4 local_40;
  int *local_3c;
  int local_2c;
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099988a;
  local_c = ExceptionList;
  local_3c = (int *)0x823206;
  ExceptionList = &local_c;
  param_1 = (undefined1 *)FUN_00822de0();
  local_3c = &local_2c;
  local_40 = 0x82321c;
  FUN_004c4d40();
  if (local_2c != *(int *)(in_ECX + 0x1c)) {
    local_3c = (int *)&param_1;
    local_40 = 0x823237;
    FUN_0041ec50();
    if (param_1 != (undefined1 *)*(int *)(local_2c + 0x14)) {
      ExceptionList = local_c;
      return (int)param_1 + 0x24;
    }
  }
  param_1 = auStack_54;
  local_3c = (int *)0xf;
  local_40 = 0;
  local_50 = 0;
  FUN_00401740(s__s_EffectData__missing___00a0c2a0,0x18);
  FUN_00404230(local_28);
  local_4 = 0;
  FUN_00796d50(local_28);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return 0;
  }
  local_3c = (int *)0x8232c1;
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_008232e0 @ 0x008232e0 ====

/* WARNING: Removing unreachable block (ram,0x00823373) */

void FUN_008232e0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  void *_Memory;
  int in_ECX;
  int *piVar3;
  undefined4 uStack_4;
  
  piVar1 = *(int **)(in_ECX + 0xc);
  for (piVar3 = *(int **)(in_ECX + 8); piVar3 != piVar1; piVar3 = piVar3 + 1) {
    if (*piVar3 != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(*piVar3);
    }
  }
  if (*(void **)(in_ECX + 8) != (void *)0x0) {
    _free(*(void **)(in_ECX + 8));
    return;
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  puVar2 = *(undefined4 **)(in_ECX + 0x1c);
  _Memory = (void *)*puVar2;
  *puVar2 = puVar2;
  *(int *)(*(int *)(in_ECX + 0x1c) + 4) = *(int *)(in_ECX + 0x1c);
  *(undefined4 *)(in_ECX + 0x20) = 0;
  if (_Memory != *(void **)(in_ECX + 0x1c)) {
    FUN_004c8270();
    _free(_Memory);
    return;
  }
  uStack_4 = *(undefined4 *)(in_ECX + 0x1c);
  if (*(int *)(in_ECX + 0x28) != *(int *)(in_ECX + 0x2c)) {
    *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x28);
  }
  FUN_004c7a80(*(undefined4 *)(in_ECX + 0x28),9,&uStack_4);
  *(undefined4 *)(in_ECX + 0x34) = 1;
  *(undefined4 *)(in_ECX + 0x38) = 1;
  return;
}


// ==== FUN_008233b0 @ 0x008233b0 ====

void FUN_008233b0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009998b2;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_00a0c2ec;
  local_4 = 2;
  FUN_008232e0();
  DAT_00b5acf0 = 0;
  if ((void *)in_ECX[10] == (void *)0x0) {
    in_ECX[10] = 0;
    in_ECX[0xb] = 0;
    in_ECX[0xc] = 0;
    FUN_004c8690();
    _free((void *)in_ECX[7]);
    return;
  }
  _free((void *)in_ECX[10]);
  return;
}


// ==== FUN_00823450 @ 0x00823450 ====

void FUN_00823450(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  undefined1 local_91;
  int local_90;
  int local_8c;
  int *local_88;
  int local_84;
  int local_80;
  int local_7c;
  int *local_78;
  undefined1 local_74 [8];
  undefined1 local_6c [40];
  undefined2 local_44 [6];
  undefined4 *local_38;
  undefined4 local_34;
  void *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009998cc;
  local_14 = ExceptionList;
  local_88 = *(int **)(in_ECX + 8);
  if (((local_88 != (int *)0x0) && (*(int *)(in_ECX + 0xc) - (int)local_88 >> 2 != 0)) &&
     (local_78 = *(int **)(in_ECX + 0xc), local_88 != local_78)) {
    local_84 = *local_88 + 0x3c;
    local_90 = 1;
    ExceptionList = &local_14;
    local_8c = in_ECX;
    while( true ) {
      do {
        iVar1 = local_8c;
        FUN_004c4d40(&local_80,&local_90);
        iVar4 = local_80;
        iVar1 = *(int *)(iVar1 + 0x1c);
        if (local_80 != iVar1) {
          FUN_004c4d40(&local_7c,&local_90);
          if (local_7c == iVar1) {
            FUN_004c8060(&local_91,&local_91);
            local_c = 0;
            if (*(int *)(iVar4 + 0x18) != 0) {
              puVar2 = *(undefined4 **)(iVar4 + 0x14);
              for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3)
              {
                FUN_004c82b0(local_74,puVar3 + 2);
              }
            }
            local_44[0] = (undefined2)local_90;
            FUN_004c8620(local_6c);
            local_c = CONCAT31(local_c._1_3_,1);
            FUN_004c8860(local_74,local_44);
            if (local_2c != (void *)0x0) {
              _free(local_2c);
              return;
            }
            local_2c = (void *)0x0;
            local_28 = 0;
            local_24 = 0;
            puVar2 = (undefined4 *)*local_38;
            *local_38 = local_38;
            local_38[1] = local_38;
            local_34 = 0;
            if (puVar2 == local_38) {
              _free(local_38);
              return;
            }
            if ((uint)puVar2[8] < 0x10) {
              puVar2[8] = 0xf;
              puVar2[7] = 0;
              *(undefined1 *)(puVar2 + 3) = 0;
              _free(puVar2);
              return;
            }
            _free((void *)puVar2[3]);
            return;
          }
          puVar2 = *(undefined4 **)(iVar4 + 0x14);
          for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
            FUN_004c82b0(local_74,puVar3 + 2);
          }
        }
        local_90 = local_90 + 1;
      } while ((ushort)local_90 < 0xc);
      local_88 = local_88 + 1;
      if (local_88 == local_78) break;
      local_84 = *local_88 + 0x3c;
      local_90 = 1;
    }
  }
  ExceptionList = local_14;
  return;
}


// ==== FUN_00823720 @ 0x00823720 ====

void FUN_00823720(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int local_78;
  int local_74;
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
  puStack_8 = &LAB_009998f6;
  local_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(s_effect_list_data_txt_00a0c2bc,0x14);
  local_4 = 0;
  iVar2 = FUN_00410500(local_28);
  local_4 = 0xffffffff;
  local_74 = iVar2;
  if (0xf < local_10) {
    _free(local_24);
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (iVar2 != 0) {
    FUN_0049d760();
    cVar1 = FUN_0049d7c0();
    if (cVar1 == '\0') {
      do {
        FUN_0049d800(local_60);
        local_6c = (void *)0x0;
        local_68 = 0;
        local_64 = 0;
        local_4 = 2;
        FUN_00404fb0(local_60,0x2c,local_70);
        if (local_6c == (void *)0x0) {
          local_6c = (void *)0x0;
          local_68 = 0;
          local_64 = 0;
          local_4 = 0xffffffff;
          if (0xf < local_48) {
            _free(local_5c);
            return;
          }
        }
        else {
          iVar2 = local_68 - (int)local_6c >> 0x1f;
          iVar3 = (local_68 - (int)local_6c) / 0x1c + iVar2;
          if (iVar3 == iVar2) {
            FUN_00405de0(local_6c,local_68,local_70,local_74);
            _free(local_6c);
            return;
          }
          if (iVar3 == iVar2) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          local_2c = 0xf;
          local_30 = 0;
          local_40 = (void *)((uint)local_40 & 0xffffff00);
          FUN_00401660(local_6c,0,0xffffffff);
          local_4 = CONCAT31(local_4._1_3_,3);
          local_78 = FUN_00822d50(local_44);
          if (local_78 == 0) {
            if (0xf < local_2c) {
              _free(local_40);
              return;
            }
            local_2c = 0xf;
            local_30 = 0;
            local_40 = (void *)((uint)local_40 & 0xffffff00);
            if (local_6c != (void *)0x0) {
              FUN_00405de0(local_6c,local_68,local_70,local_74);
              _free(local_6c);
              return;
            }
          }
          else {
            FUN_00823df0(&local_78);
            if (0xf < local_2c) {
              _free(local_40);
              return;
            }
            local_2c = 0xf;
            local_30 = 0;
            local_40 = (void *)((uint)local_40 & 0xffffff00);
            if (local_6c != (void *)0x0) {
              FUN_00405de0(local_6c,local_68,local_70,local_74);
              _free(local_6c);
              return;
            }
          }
          if (0xf < local_48) {
            local_4 = 0xffffffff;
            local_2c = 0xf;
            local_30 = 0;
            local_64 = 0;
            local_68 = 0;
            local_6c = (void *)0x0;
            _free(local_5c);
            return;
          }
          local_2c = 0xf;
          local_30 = 0;
        }
        local_4 = 0xffffffff;
        local_64 = 0;
        local_68 = 0;
        local_6c = (void *)0x0;
        local_48 = 0xf;
        local_4c = 0;
        local_5c = (void *)((uint)local_5c & 0xffffff00);
        FUN_0049d780();
        cVar1 = FUN_0049d7c0();
      } while (cVar1 == '\0');
      iVar2 = local_74;
    }
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar2);
    FUN_00823450();
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00823a30 @ 0x00823a30 ====

/* WARNING: Removing unreachable block (ram,0x00823ad3) */

void FUN_00823a30(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  void *_Memory;
  int iVar4;
  int in_ECX;
  int *piVar5;
  undefined4 uStack_4;
  
  piVar1 = *(int **)(in_ECX + 0xc);
  for (piVar5 = *(int **)(in_ECX + 8); piVar5 != piVar1; piVar5 = piVar5 + 1) {
    piVar2 = (int *)*piVar5;
    if (piVar2 != (int *)0x0) {
      iVar4 = (**(code **)(*piVar2 + 4))();
      *(undefined4 *)(iVar4 + 0x28) = 0;
      (**(code **)(*DAT_00b5a7cc + 0x2c))(piVar2);
    }
  }
  if (*(void **)(in_ECX + 8) != (void *)0x0) {
    _free(*(void **)(in_ECX + 8));
    return;
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  puVar3 = *(undefined4 **)(in_ECX + 0x1c);
  _Memory = (void *)*puVar3;
  *puVar3 = puVar3;
  *(int *)(*(int *)(in_ECX + 0x1c) + 4) = *(int *)(in_ECX + 0x1c);
  *(undefined4 *)(in_ECX + 0x20) = 0;
  if (_Memory != *(void **)(in_ECX + 0x1c)) {
    FUN_004c8270();
    _free(_Memory);
    return;
  }
  uStack_4 = *(undefined4 *)(in_ECX + 0x1c);
  if (*(int *)(in_ECX + 0x28) != *(int *)(in_ECX + 0x2c)) {
    *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x28);
  }
  FUN_004c7a80(*(undefined4 *)(in_ECX + 0x28),9,&uStack_4);
  *(undefined4 *)(in_ECX + 0x34) = 1;
  *(undefined4 *)(in_ECX + 0x38) = 1;
  FUN_00823720();
  return;
}


// ==== FUN_00823b10 @ 0x00823b10 ====

void FUN_00823b10(void)

{
  undefined4 *in_ECX;
  undefined1 local_11 [5];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099991e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_00a0c2ec;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  local_4 = 1;
  FUN_004c8780(local_11,local_11);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5acf0 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5acf0 = in_ECX;
  }
  FUN_00823720();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00823ba0 @ 0x00823ba0 ====

void FUN_00823ba0(void)

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
  puStack_8 = &LAB_00999938;
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


// ==== FUN_00823c10 @ 0x00823c10 ====

void FUN_00823c10(void *param_1,uint param_2,undefined4 *param_3)

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
      uVar7 = FUN_00823ba0();
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


// ==== FUN_00823df0 @ 0x00823df0 ====

void FUN_00823df0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_00823c10(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_00823e40 @ 0x00823e40 ====

void FUN_00823e40(byte param_1)

{
  void *in_ECX;
  
  FUN_008233b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00823e60 @ 0x00823e60 ====

void FUN_00823e60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0c38c;
  return;
}


// ==== FUN_00823e70 @ 0x00823e70 ====

void FUN_00823e70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0c38c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00823e90 @ 0x00823e90 ====

int FUN_00823e90(void)

{
  int in_ECX;
  
  return in_ECX + 0x20;
}


// ==== FUN_00823ea0 @ 0x00823ea0 ====

int FUN_00823ea0(undefined1 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined1 local_4 [4];
  
  piVar1 = (int *)FUN_004be4e0(local_4,&param_1);
  if (*piVar1 == *(int *)(in_ECX + 0x18)) {
    return 0;
  }
  return *piVar1 + 0x10;
}


// ==== FUN_00823ed0 @ 0x00823ed0 ====

int FUN_00823ed0(undefined1 *param_1)

{
  int iVar1;
  int *piVar2;
  int extraout_EAX;
  int in_ECX;
  uint uVar3;
  undefined1 auStack_64 [4];
  undefined1 local_60;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *puStack_48;
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00999978;
  local_c = ExceptionList;
  puStack_48 = (undefined4 *)local_2c;
  uVar3 = (uint)param_1 >> 0x10;
  local_4c = 0x823f11;
  ExceptionList = &local_c;
  param_1 = (undefined1 *)uVar3;
  piVar2 = (int *)FUN_004be4e0();
  iVar1 = *piVar2;
  if (iVar1 != *(int *)(in_ECX + 0x18)) {
    puStack_48 = &param_1;
    local_4c = 0x823f2a;
    FUN_00824c20();
    if (param_1 != (undefined1 *)*(uint *)(iVar1 + 0x30)) {
      ExceptionList = local_c;
      return (int)param_1 + 0x10;
    }
  }
  param_1 = auStack_64;
  local_4c = 0xf;
  local_50 = 0;
  local_60 = 0;
  puStack_48 = (undefined4 *)uVar3;
  FUN_00401740(s_Category__d_EffectID__d__EffectS_00a0c334,0x30);
  FUN_00404230(local_28);
  local_4 = 0;
  FUN_00796d50(local_28);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return 0;
  }
  puStack_48 = (undefined4 *)0x823fa5;
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_00823fc0 @ 0x00823fc0 ====

void FUN_00823fc0(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *local_4c;
  int *local_48;
  int local_44;
  int local_40;
  int local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int local_2c [2];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099998a;
  local_c = ExceptionList;
  local_30 = *(int **)((int)param_2 + 0x20);
  piVar3 = (int *)*local_30;
  ExceptionList = &local_c;
  param_2 = piVar3;
  if (piVar3 != local_30) {
    do {
      local_4c = (int *)CONCAT22((short)((uint)in_ECX >> 0x10),(short)piVar3[3]);
      FUN_00824c20(&local_48,&local_4c);
      piVar5 = local_48;
      in_ECX = extraout_ECX;
      if (local_48 != *(int **)(param_1 + 0x20)) {
        piVar7 = local_48 + 0xc;
        if (local_48[0xd] == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = local_48[0xe] - local_48[0xd] >> 5;
        }
        in_ECX = (int *)piVar3[0xe];
        piVar6 = (int *)piVar3[0xd];
        iVar2 = iVar2 + 1;
        local_3c = iVar2;
        if (piVar6 != in_ECX) {
          local_4c = in_ECX;
          do {
            local_2c[0] = *piVar6;
            local_10 = 0xf;
            local_14 = 0;
            local_24 = (void *)((uint)local_24 & 0xffffff00);
            FUN_00401660(piVar6 + 1,0,0xffffffff);
            iVar4 = piVar5[0xd];
            local_4 = 0;
            local_2c[0] = iVar2;
            if ((iVar4 == 0) ||
               ((uint)(piVar5[0xf] - iVar4 >> 5) <= (uint)(piVar5[0xe] - iVar4 >> 5))) {
              FUN_004c1d00(piVar5[0xe],1,local_2c);
              in_ECX = extraout_ECX_01;
            }
            else {
              iVar4 = piVar5[0xe];
              FUN_004c1750(iVar4,1,local_2c,piVar7,param_2);
              piVar5[0xe] = iVar4 + 0x20;
              in_ECX = extraout_ECX_00;
            }
            iVar2 = iVar2 + 1;
            local_4 = 0xffffffff;
            if (0xf < local_10) {
              _free(local_24);
              return;
            }
            piVar6 = piVar6 + 8;
            local_10 = 0xf;
            local_14 = 0;
            local_24 = (void *)((uint)local_24 & 0xffffff00);
          } while (piVar6 != local_4c);
          piVar3 = param_2;
        }
        piVar3 = (int *)piVar3[0x11];
        piVar5 = (int *)*piVar3;
        local_4c = piVar5;
        local_34 = piVar3;
        if (piVar5 != piVar3) {
          do {
            local_44 = piVar5[3];
            FUN_005babb0(&local_40,&local_44);
            iVar2 = local_40;
            in_ECX = local_48;
            if (local_40 != local_48[0x11]) {
              local_38 = (int *)piVar5[0xd];
              piVar7 = (int *)piVar5[0xc];
              if (piVar7 != local_38) {
                iVar4 = local_3c;
                do {
                  local_44 = *piVar7;
                  *(int *)(local_44 + 4) = iVar4;
                  in_ECX = *(int **)(iVar2 + 0x30);
                  if ((in_ECX == (int *)0x0) ||
                     ((uint)(*(int *)(iVar2 + 0x38) - (int)in_ECX >> 2) <=
                      (uint)(*(int *)(iVar2 + 0x34) - (int)in_ECX >> 2))) {
                    FUN_004c0fc0(*(undefined4 *)(iVar2 + 0x34),1,&local_44);
                    in_ECX = extraout_ECX_02;
                  }
                  else {
                    piVar3 = *(int **)(iVar2 + 0x34);
                    *piVar3 = local_44;
                    *(int **)(iVar2 + 0x34) = piVar3 + 1;
                  }
                  piVar7 = piVar7 + 1;
                  iVar4 = iVar4 + 1;
                } while (piVar7 != local_38);
                piVar5 = local_4c;
                piVar3 = local_34;
              }
            }
            if (*(char *)((int)piVar5 + 0x3d) == '\0') {
              in_ECX = (int *)piVar5[2];
              if (*(char *)((int)in_ECX + 0x3d) == '\0') {
                cVar1 = *(char *)(*in_ECX + 0x3d);
                piVar5 = (int *)*in_ECX;
                while (cVar1 == '\0') {
                  cVar1 = *(char *)(*piVar5 + 0x3d);
                  in_ECX = piVar5;
                  piVar5 = (int *)*piVar5;
                }
                local_4c = in_ECX;
              }
              else {
                local_4c = (int *)piVar5[1];
                if (*(char *)((int)local_4c + 0x3d) == '\0') {
                  while( true ) {
                    piVar7 = local_4c;
                    local_4c = piVar7;
                    if ((piVar5 != (int *)piVar7[2]) ||
                       (local_4c = (int *)piVar7[1], *(char *)((int)local_4c + 0x3d) != '\0'))
                    break;
                    piVar5 = piVar7;
                  }
                }
              }
              piVar5 = local_4c;
            }
          } while (piVar5 != piVar3);
        }
        piVar3 = param_2;
      }
      if (*(char *)((int)piVar3 + 0x4d) == '\0') {
        in_ECX = (int *)piVar3[2];
        if (*(char *)((int)in_ECX + 0x4d) == '\0') {
          cVar1 = *(char *)(*in_ECX + 0x4d);
          piVar3 = (int *)*in_ECX;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x4d);
            in_ECX = piVar3;
            piVar3 = (int *)*piVar3;
          }
          param_2 = in_ECX;
        }
        else {
          param_2 = (int *)piVar3[1];
          if (*(char *)((int)param_2 + 0x4d) == '\0') {
            while( true ) {
              piVar5 = param_2;
              param_2 = piVar5;
              if ((piVar3 != (int *)piVar5[2]) ||
                 (param_2 = (int *)piVar5[1], *(char *)((int)param_2 + 0x4d) != '\0')) break;
              piVar3 = piVar5;
            }
          }
        }
        piVar3 = param_2;
      }
    } while (piVar3 != local_30);
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_008242b0 @ 0x008242b0 ====

void FUN_008242b0(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  undefined1 local_2c [4];
  void *local_28;
  undefined4 local_18;
  uint local_14;
  undefined2 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099999c;
  local_c = ExceptionList;
  piVar2 = *(int **)(in_ECX + 8);
  if ((piVar2 != (int *)0x0) && (*(int *)(in_ECX + 0xc) - (int)piVar2 >> 2 != 0)) {
    piVar2 = *(int **)(*piVar2 + 0x40);
    piVar6 = (int *)*piVar2;
    if (piVar6 != piVar2) {
      ExceptionList = &local_c;
      do {
        local_14 = 0xf;
        local_18 = 0;
        local_28 = (void *)((uint)local_28 & 0xffffff00);
        local_10 = (undefined2)piVar6[3];
        local_4 = 0;
        FUN_00401660(piVar6 + 4,0,0xffffffff);
        iVar3 = *(int *)(in_ECX + 0x24);
        if ((iVar3 == 0) ||
           ((uint)(*(int *)(in_ECX + 0x2c) - iVar3 >> 5) <=
            (uint)(*(int *)(in_ECX + 0x28) - iVar3 >> 5))) {
          FUN_008251f0(*(undefined4 *)(in_ECX + 0x28),1,local_2c);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x28);
          FUN_008250b0(iVar3,1,local_2c,in_ECX + 0x20,piVar2);
          *(int *)(in_ECX + 0x28) = iVar3 + 0x20;
        }
        local_4 = 0xffffffff;
        if (0xf < local_14) {
          _free(local_28);
          return;
        }
        local_28 = (void *)((uint)local_28 & 0xffffff00);
        if (*(char *)((int)piVar6 + 0x39) == '\0') {
          piVar4 = (int *)piVar6[2];
          if (*(char *)((int)piVar4 + 0x39) == '\0') {
            cVar1 = *(char *)(*piVar4 + 0x39);
            piVar6 = piVar4;
            piVar4 = (int *)*piVar4;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar4 + 0x39);
              piVar6 = piVar4;
              piVar4 = (int *)*piVar4;
            }
          }
          else {
            cVar1 = *(char *)(piVar6[1] + 0x39);
            piVar5 = (int *)piVar6[1];
            piVar4 = piVar6;
            while ((piVar6 = piVar5, cVar1 == '\0' && (piVar4 == (int *)piVar6[2]))) {
              cVar1 = *(char *)(piVar6[1] + 0x39);
              piVar5 = (int *)piVar6[1];
              piVar4 = piVar6;
            }
          }
        }
      } while (piVar6 != piVar2);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00824420 @ 0x00824420 ====

void FUN_00824420(void)

{
  int iVar1;
  short sVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  int iVar7;
  short *psVar8;
  int *local_90;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int *local_7c;
  undefined1 *puStack_78;
  undefined1 auStack_74 [8];
  undefined1 auStack_6c [28];
  undefined1 auStack_50 [12];
  short asStack_44 [2];
  undefined1 auStack_40 [4];
  undefined1 uStack_3c;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  void *local_14;
  undefined1 *puStack_10;
  int iStack_c;
  
  iStack_c = 0xffffffff;
  puStack_10 = &LAB_009999be;
  local_14 = ExceptionList;
  local_90 = *(int **)(in_ECX + 8);
  if ((local_90 != (int *)0x0) && (*(int *)(in_ECX + 0xc) - (int)local_90 >> 2 != 0)) {
    local_7c = *(int **)(in_ECX + 0xc);
    ExceptionList = &local_14;
    if (local_90 != local_7c) {
      do {
        piVar3 = (int *)*local_90;
        (**(code **)(*piVar3 + 4))();
        iVar6 = FUN_00405850(&PTR_LAB_00a0c380,0,3);
        iStack_80 = *(int *)(in_ECX + 0x28);
        iVar7 = *(int *)(in_ECX + 0x24);
        if (iVar7 != iStack_80) {
          psVar8 = (short *)(iVar7 + 0x1c);
          do {
            FUN_004be4e0(&iStack_88,psVar8);
            iVar5 = iStack_88;
            if (iStack_88 != piVar3[0x10]) {
              iVar1 = iStack_88 + 0x10;
              FUN_004be4e0(&iStack_84,psVar8);
              if (iStack_84 == *(int *)(in_ECX + 0x18)) {
                FUN_004c33b0();
                iStack_c = 0;
                FUN_00401660(iVar7,0,0xffffffff);
                puVar4 = *(undefined4 **)(iVar5 + 0x30);
                FUN_008254a0(*puVar4,puVar4);
                asStack_44[0] = *psVar8;
                puStack_78 = auStack_40;
                uStack_28 = 0xf;
                uStack_2c = 0;
                uStack_3c = 0;
                FUN_00401660(auStack_6c,0,0xffffffff);
                iStack_c._0_1_ = 1;
                FUN_004c3320(auStack_50);
                iStack_c._0_1_ = 2;
                FUN_004c37b0(auStack_74,asStack_44);
                iStack_c = (uint)iStack_c._1_3_ << 8;
                FUN_004c3420();
                iStack_c = 0xffffffff;
                FUN_004c3420();
              }
              else if ((iVar6 == -1) ||
                      ((((sVar2 = *psVar8, sVar2 != 1 && (sVar2 != 8)) && (sVar2 != 0xc)) &&
                       ((sVar2 != 0xb && (sVar2 != 100)))))) {
                puVar4 = *(undefined4 **)(iVar5 + 0x30);
                FUN_008254a0(*puVar4,puVar4);
              }
              else {
                FUN_00823fc0(iStack_84 + 0x10,iVar1);
              }
            }
            iVar7 = iVar7 + 0x20;
            psVar8 = psVar8 + 0x10;
          } while (iVar7 != iStack_80);
        }
        local_90 = local_90 + 1;
      } while (local_90 != local_7c);
    }
  }
  ExceptionList = local_14;
  return;
}


// ==== FUN_00824660 @ 0x00824660 ====

void FUN_00824660(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int local_78;
  int local_74;
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
  puStack_8 = &LAB_009999e8;
  local_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(s_effect_list_scene_txt_00a0c368,0x15);
  local_4 = 0;
  iVar2 = FUN_00410500(local_28);
  local_4 = 0xffffffff;
  local_74 = iVar2;
  if (0xf < local_10) {
    _free(local_24);
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (iVar2 != 0) {
    FUN_0049d760();
    cVar1 = FUN_0049d7c0();
    if (cVar1 == '\0') {
      do {
        FUN_0049d800(local_60);
        local_6c = (void *)0x0;
        local_68 = 0;
        local_64 = 0;
        local_4 = 2;
        FUN_00404fb0(local_60,0x2c,local_70);
        if (local_6c == (void *)0x0) {
          local_6c = (void *)0x0;
          local_68 = 0;
          local_64 = 0;
          local_4 = 0xffffffff;
          if (0xf < local_48) {
            _free(local_5c);
            return;
          }
        }
        else {
          iVar2 = local_68 - (int)local_6c >> 0x1f;
          iVar3 = (local_68 - (int)local_6c) / 0x1c + iVar2;
          if (iVar3 == iVar2) {
            FUN_00405de0(local_6c,local_68,local_70,local_74);
            _free(local_6c);
            return;
          }
          if (iVar3 == iVar2) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          local_2c = 0xf;
          local_30 = 0;
          local_40 = (void *)((uint)local_40 & 0xffffff00);
          FUN_00401660(local_6c,0,0xffffffff);
          local_4 = CONCAT31(local_4._1_3_,3);
          local_78 = FUN_00824c90(local_44);
          if (local_78 == 0) {
            if (0xf < local_2c) {
              _free(local_40);
              return;
            }
            local_2c = 0xf;
            local_30 = 0;
            local_40 = (void *)((uint)local_40 & 0xffffff00);
            if (local_6c != (void *)0x0) {
              FUN_00405de0(local_6c,local_68,local_70,local_74);
              _free(local_6c);
              return;
            }
          }
          else {
            FUN_00825170(&local_78);
            if (0xf < local_2c) {
              _free(local_40);
              return;
            }
            local_2c = 0xf;
            local_30 = 0;
            local_40 = (void *)((uint)local_40 & 0xffffff00);
            if (local_6c != (void *)0x0) {
              FUN_00405de0(local_6c,local_68,local_70,local_74);
              _free(local_6c);
              return;
            }
          }
          if (0xf < local_48) {
            local_4 = 0xffffffff;
            local_2c = 0xf;
            local_30 = 0;
            local_64 = 0;
            local_68 = 0;
            local_6c = (void *)0x0;
            _free(local_5c);
            return;
          }
          local_2c = 0xf;
          local_30 = 0;
        }
        local_4 = 0xffffffff;
        local_64 = 0;
        local_68 = 0;
        local_6c = (void *)0x0;
        local_48 = 0xf;
        local_4c = 0;
        local_5c = (void *)((uint)local_5c & 0xffffff00);
        FUN_0049d780();
        cVar1 = FUN_0049d7c0();
      } while (cVar1 == '\0');
      iVar2 = local_74;
    }
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar2);
    FUN_008242b0();
    FUN_00824420();
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00824980 @ 0x00824980 ====

void FUN_00824980(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int *piVar4;
  
  FUN_00793e00();
  FUN_004c3b30(*(undefined4 *)(*(int *)(in_ECX + 0x18) + 4));
  *(int *)(*(int *)(in_ECX + 0x18) + 4) = *(int *)(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x18);
  *(int *)(*(int *)(in_ECX + 0x18) + 8) = *(int *)(in_ECX + 0x18);
  piVar1 = *(int **)(in_ECX + 0xc);
  for (piVar4 = *(int **)(in_ECX + 8); piVar4 != piVar1; piVar4 = piVar4 + 1) {
    piVar2 = (int *)*piVar4;
    if (piVar2 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar2 + 4))();
      *(undefined4 *)(iVar3 + 0x28) = 0;
      (**(code **)(*DAT_00b5a7cc + 0x2c))(piVar2);
    }
  }
  if (*(void **)(in_ECX + 8) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    FUN_00824660();
    return;
  }
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_00824a10 @ 0x00824a10 ====

void FUN_00824a10(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  piVar1 = *(int **)(in_ECX + 0xc);
  for (piVar2 = *(int **)(in_ECX + 8); piVar2 != piVar1; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(*piVar2);
    }
  }
  if (*(int *)(in_ECX + 0x24) != 0) {
    if (*(int *)(in_ECX + 0x24) != *(int *)(in_ECX + 0x28)) {
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    _free(*(void **)(in_ECX + 0x24));
    return;
  }
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  FUN_004c3b30(*(undefined4 *)(*(int *)(in_ECX + 0x18) + 4));
  *(int *)(*(int *)(in_ECX + 0x18) + 4) = *(int *)(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x18);
  *(int *)(*(int *)(in_ECX + 0x18) + 8) = *(int *)(in_ECX + 0x18);
  if (*(void **)(in_ECX + 8) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_00824ac0 @ 0x00824ac0 ====

void FUN_00824ac0(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00999a1b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_00a0c3a4;
  local_4 = 3;
  FUN_00824a10();
  DAT_00b5acf4 = 0;
  FUN_00793e00();
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_004c3b70(local_10,*(undefined4 *)in_ECX[6],(undefined4 *)in_ECX[6]);
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_00824b70 @ 0x00824b70 ====

void FUN_00824b70(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00999a4e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_00a0c3a4;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  local_4 = 1;
  iVar1 = FUN_004be420();
  in_ECX[6] = iVar1;
  *(undefined1 *)(iVar1 + 0x39) = 1;
  *(undefined4 *)(in_ECX[6] + 4) = in_ECX[6];
  *(undefined4 *)in_ECX[6] = in_ECX[6];
  *(undefined4 *)(in_ECX[6] + 8) = in_ECX[6];
  in_ECX[7] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  local_4 = CONCAT31(local_4._1_3_,3);
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5acf4 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5acf4 = in_ECX;
  }
  FUN_00824660();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00824c20 @ 0x00824c20 ====

void FUN_00824c20(undefined4 *param_1,ushort *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x4d) == '\0') {
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
    } while (*(char *)((int)puVar2 + 0x4d) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < *(ushort *)(puVar3 + 3))) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_00824c90 @ 0x00824c90 ====

undefined4 FUN_00824c90(undefined4 param_1)

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
  puStack_8 = &LAB_00999958;
  pvStack_c = ExceptionList;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660(param_1,0,0xffffffff);
  local_10 = (void *)0x17;
  local_4 = 0;
  uVar1 = (**(code **)(*DAT_00b5a7cc + 8))(&local_2c);
  if (local_18 < 0x10) {
    ExceptionList = local_10;
    return uVar1;
  }
  _free(local_2c);
  return extraout_EAX;
}


// ==== FUN_00824d20 @ 0x00824d20 ====

void FUN_00824d20(void)

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
  puStack_8 = &LAB_00999a68;
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


// ==== FUN_00824d90 @ 0x00824d90 ====

int FUN_00824d90(int param_1,int param_2,int param_3)

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
    param_2 = iVar1;
    param_3 = iVar2;
  } while (iVar1 != param_1);
  return iVar2;
}


// ==== FUN_00824dd0 @ 0x00824dd0 ====

int FUN_00824dd0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00999a91;
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
      *(undefined2 *)(param_3 + 0x1c) = *(undefined2 *)(param_1 + 0x1c);
    }
    param_3 = param_3 + 0x20;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00824e3e @ 0x00824e3e ====

void Catch_00824e3e(void)

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


// ==== FUN_00824e90 @ 0x00824e90 ====

void FUN_00824e90(void *param_1,uint param_2,undefined4 *param_3)

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
      uVar7 = FUN_00824d20();
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


// ==== FUN_00825070 @ 0x00825070 ====

void FUN_00825070(int param_1,int param_2,int param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x20) {
    FUN_00401660(param_3,0,0xffffffff);
    *(undefined2 *)(param_1 + 0x1c) = *(undefined2 *)(param_3 + 0x1c);
  }
  return;
}


// ==== FUN_008250b0 @ 0x008250b0 ====

void FUN_008250b0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00999ab1;
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
      *(undefined2 *)(param_1 + 0x1c) = *(undefined2 *)(param_3 + 0x1c);
    }
    param_1 = param_1 + 0x20;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00825123 @ 0x00825123 ====

void Catch_00825123(void)

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


// ==== FUN_00825170 @ 0x00825170 ====

void FUN_00825170(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_00824e90(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_008251c0 @ 0x008251c0 ====

int FUN_008251c0(int param_1,int param_2,undefined4 param_3)

{
  FUN_008250b0(param_1,param_2,param_3);
  return param_2 * 0x20 + param_1;
}


// ==== FUN_008251f0 @ 0x008251f0 ====

void FUN_008251f0(int param_1,uint param_2,int param_3)

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
  undefined2 local_20;
  void *local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999ac8;
  local_10 = ExceptionList;
  local_14 = local_3c + -0xc;
  local_24 = 0xf;
  local_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3,0,0xffffffff);
  local_20 = *(undefined2 *)(param_3 + 0x1c);
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
      uVar1 = FUN_00824d20();
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
      iVar2 = FUN_00824dd0(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_008250b0(iVar2,param_2,local_3c);
      FUN_00824dd0(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x20);
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
        FUN_00824dd0(param_1,local_1c,param_2 * 0x20 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_008251c0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 5),local_3c);
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x20;
        local_8 = 0;
        FUN_00825070(param_1,*(int *)(in_ECX + 8) + param_2 * -0x20,local_3c);
      }
      else {
        pvVar3 = (void *)((int)local_1c + param_2 * -0x20);
        uVar4 = FUN_00824dd0(pvVar3,local_1c,local_1c);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_00824d90(param_1,pvVar3,local_1c,param_1);
        FUN_00825070(param_1,param_2 * 0x20 + param_1,local_3c);
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


// ==== Catch@00825386 @ 0x00825386 ====

void Catch_00825386(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_00793d10(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@00825415 @ 0x00825415 ====

void Catch_00825415(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x20;
  FUN_00793d10(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008254a0 @ 0x008254a0 ====

void FUN_008254a0(int *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined1 local_8 [8];
  
  while (param_1 != param_2) {
    FUN_004c3000(local_8,param_1 + 3);
    if (*(char *)((int)param_1 + 0x4d) == '\0') {
      piVar2 = (int *)param_1[2];
      if (*(char *)((int)piVar2 + 0x4d) == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x4d);
        param_1 = piVar2;
        piVar2 = (int *)*piVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x4d);
          param_1 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(param_1[1] + 0x4d);
        piVar3 = (int *)param_1[1];
        piVar2 = param_1;
        while ((param_1 = piVar3, cVar1 == '\0' && (piVar2 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x4d);
          piVar3 = (int *)param_1[1];
          piVar2 = param_1;
        }
      }
    }
  }
  return;
}


// ==== FUN_00825520 @ 0x00825520 ====

void FUN_00825520(byte param_1)

{
  void *in_ECX;
  
  FUN_00824ac0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00825540 @ 0x00825540 ====

int FUN_00825540(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_005beda0(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0x24)) {
    return in_ECX + 4;
  }
  return local_4 + 0x10;
}


// ==== FUN_00825570 @ 0x00825570 ====

/* WARNING: Removing unreachable block (ram,0x008256f3) */

void FUN_00825570(undefined4 param_1)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  char *pcVar6;
  uint uVar7;
  char *pcVar8;
  int unaff_ESI;
  undefined1 auStack_25e [22];
  undefined4 auStack_248 [2];
  void *pvStack_240;
  undefined4 uStack_230;
  uint uStack_22c;
  undefined1 auStack_228 [20];
  char local_214 [256];
  undefined4 local_114;
  undefined1 local_110;
  undefined1 local_10f;
  undefined1 local_10e;
  char local_10c [248];
  void *pvStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00999b36;
  pvStack_c = ExceptionList;
  local_214[0] = '\0';
  ExceptionList = &pvStack_c;
  FUN_0044a580(local_10c,&DAT_00a0c3c8,s_ShareString_00a0c3bc);
  uVar3 = 0;
  do {
    local_214[uVar3] = local_10c[uVar3];
    if (local_10c[uVar3] == '\0') goto LAB_008255cf;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x100);
  local_214[0] = '\0';
LAB_008255cf:
  local_114 = param_1;
  local_110 = 10;
  local_10f = 0x2c;
  local_10e = 1;
  piVar4 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_214);
  uVar3 = (**(code **)(*piVar4 + 8))();
  if (1 < uVar3) {
    uVar3 = 1;
    do {
      uVar5 = FUN_004756e0(uVar3,0);
      pcVar6 = (char *)(**(code **)(*piVar4 + 0x10))(uVar3,1);
      pcVar8 = pcVar6;
      do {
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_00401740(pcVar6,(int)pcVar8 - (int)(pcVar6 + 1));
      uStack_10 = 0;
      uStack_22c = 0xf;
      uStack_230 = 0;
      pvStack_240 = (void *)((uint)pvStack_240 & 0xffffff00);
      auStack_248[0] = uVar5;
      FUN_00401660(auStack_25e + -6,0,0xffffffff);
      uStack_10 = CONCAT31(uStack_10._1_3_,1);
      FUN_00825e50(auStack_228,auStack_248);
      if (0xf < uStack_22c) {
        _free(pvStack_240);
        return;
      }
      uStack_22c = 0xf;
      uStack_230 = 0;
      pvStack_240 = (void *)((uint)pvStack_240 & 0xffffff00);
      uStack_10 = 0xffffffff;
      bVar2 = (char)((uint)unaff_ESI >> 0x18) + 1;
      unaff_ESI = (uint)bVar2 << 0x18;
      uVar3 = (uint)bVar2;
      uVar7 = (**(code **)(*piVar4 + 8))();
    } while (uVar3 < uVar7);
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar4);
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_00825750 @ 0x00825750 ====

void FUN_00825750(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00999b4b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_00a0c3d0;
  local_4 = 0;
  FUN_00825f10(local_10,*(undefined4 *)in_ECX[9],(undefined4 *)in_ECX[9]);
  _free((void *)in_ECX[9]);
  return;
}


// ==== FUN_008257e0 @ 0x008257e0 ====

void FUN_008257e0(undefined4 param_1)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00999b6b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_00a0c3d0;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  local_4 = 0;
  iVar1 = FUN_004a37b0();
  in_ECX[9] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[9] + 4) = in_ECX[9];
  *(undefined4 *)in_ECX[9] = in_ECX[9];
  *(undefined4 *)(in_ECX[9] + 8) = in_ECX[9];
  in_ECX[10] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00825570(param_1);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00825870 @ 0x00825870 ====

void FUN_00825870(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = *param_4;
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  FUN_00401660(param_4 + 1,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0xb) = param_5;
  *(undefined1 *)((int)in_ECX + 0x2d) = 0;
  return;
}


// ==== FUN_008258d0 @ 0x008258d0 ====

void * FUN_008258d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999af1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x30);
  local_8 = 1;
  if (pvVar1 != (void *)0x0) {
    FUN_00825870(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00825942 @ 0x00825942 ====

void Catch_00825942(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00825960 @ 0x00825960 ====

/* WARNING: Removing unreachable block (ram,0x00825a70) */
/* WARNING: Removing unreachable block (ram,0x00825a81) */
/* WARNING: Removing unreachable block (ram,0x00825a8a) */
/* WARNING: Removing unreachable block (ram,0x00825a8d) */
/* WARNING: Removing unreachable block (ram,0x00825a7d) */
/* WARNING: Removing unreachable block (ram,0x00825a9b) */
/* WARNING: Removing unreachable block (ram,0x00825aa8) */
/* WARNING: Removing unreachable block (ram,0x00825ab3) */
/* WARNING: Removing unreachable block (ram,0x00825aaf) */
/* WARNING: Removing unreachable block (ram,0x00825aa3) */
/* WARNING: Removing unreachable block (ram,0x00825ab6) */

void FUN_00825960(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00999b08;
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
            goto LAB_00825b87;
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
LAB_00825b87:
            *(undefined1 *)(piVar5 + 0xb) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xb) = 1;
  }
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


// ==== FUN_00825c30 @ 0x00825c30 ====

void FUN_00825c30(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) == '\0') {
    FUN_00825c30(*(undefined4 *)((int)param_1 + 8));
    FUN_00792590();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00825c70 @ 0x00825c70 ====

void FUN_00825c70(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00999b08;
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
  piVar4 = (int *)FUN_008258d0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00825d69:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_00825d69;
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


// ==== FUN_00825e50 @ 0x00825e50 ====

void FUN_00825e50(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x2d) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x2d) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_00825c70(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0079c420();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00825c70(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00825f10 @ 0x00825f10 ====

void FUN_00825f10(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00825c30(piVar6[1]);
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
    FUN_00825960(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00825fd0 @ 0x00825fd0 ====

void FUN_00825fd0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00825f10(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00826000 @ 0x00826000 ====

void FUN_00826000(byte param_1)

{
  void *in_ECX;
  
  FUN_00825750();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00826020 @ 0x00826020 ====

undefined4 FUN_00826020(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar2 = *(int **)(param_1 + 0x24);
  piVar1 = (int *)(**(code **)(*piVar2 + 0x2c))(4);
  piVar2 = (int *)(**(code **)(*piVar2 + 0x2c))(5);
  if ((piVar1 == (int *)0x0) || (piVar2 == (int *)0x0)) {
    return 0;
  }
  iVar3 = (**(code **)(*piVar1 + 0x2c))();
  iVar3 = *(int *)(iVar3 + 8);
  iVar4 = (**(code **)(*piVar2 + 0x2c))();
  iVar4 = *(int *)(iVar4 + 8);
  if (iVar3 == 0x40f) {
    if (iVar4 != 0x40a) {
      return 0;
    }
  }
  else {
    if (iVar3 != 0x410) goto LAB_008260a1;
    if (iVar4 != 0x40b) {
      return 0;
    }
  }
  iVar5 = (**(code **)(*piVar1 + 0x14))();
  if (*(short *)(iVar5 + 0xc) != 0) {
    return 1;
  }
LAB_008260a1:
  if (iVar3 == 0x40a) {
    if (iVar4 != 0x40f) {
      return 0;
    }
  }
  else {
    if (iVar3 != 0x40b) {
      return 0;
    }
    if (iVar4 != 0x410) {
      return 0;
    }
  }
  iVar3 = (**(code **)(*piVar2 + 0x14))();
  if (*(short *)(iVar3 + 0xc) == 0) {
    return 0;
  }
  return 1;
}


// ==== FUN_00826100 @ 0x00826100 ====

void FUN_00826100(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 unaff_EDI;
  undefined1 local_100 [256];
  
  piVar2 = (int *)param_1[3];
  if (piVar2 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_00a0c438,s_____WARNING_____Skip_StatManager_00a0c3d8);
    FUN_00797b80(local_100);
  }
  else {
    iVar1 = (**(code **)(*DAT_00b5a6b8 + 4))();
    (**(code **)(*piVar2 + 0x1c))
              (CONCAT22((short)((uint)iVar1 >> 0x10),(ushort)*(byte *)(iVar1 + 4)) * param_2);
  }
  if ((int *)param_1[0x10] == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_00a0c438,s_____WARNING_____Skip_SkillManage_00a0c408);
    FUN_00797b80(local_100);
  }
  else {
    piVar2 = (int *)(**(code **)(*(int *)param_1[0x10] + 0x24))();
    (**(code **)(*piVar2 + 0xc))(param_2);
    (**(code **)(*piVar2 + 8))();
  }
  piVar2 = (int *)(**(code **)(*param_1 + 0x10))();
  (**(code **)(*piVar2 + 8))();
  piVar2 = (int *)param_1[0x14];
  piVar3 = (int *)(**(code **)(*param_1 + 0x10))();
  iVar1 = *piVar2;
  uVar4 = (**(code **)(*piVar3 + 0x38))();
  (**(code **)(iVar1 + 0x20))(uVar4);
  piVar2 = (int *)(**(code **)(*piVar2 + 0x14))(0);
  iVar1 = (**(code **)(*piVar2 + 0x18))();
  uVar4 = *(undefined4 *)(iVar1 + 0xc);
  (**(code **)(*piVar2 + 0x18))();
  (**(code **)(*piVar2 + 0x18))();
  if ((int *)param_1[0x11] == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(*(int *)param_1[0x11] + 0x18))();
  }
  (**(code **)(*piVar2 + 0x14))(uVar4);
  (**(code **)(*piVar2 + 0x20))(unaff_EDI);
  (**(code **)(*piVar2 + 0x2c))(unaff_EDI);
  return;
}


// ==== FUN_00826260 @ 0x00826260 ====

void FUN_00826260(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_4;
  
  if (*(int **)(param_1 + 0x44) == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    uStack_28 = 0x82627b;
    piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x44) + 0x18))();
  }
  uStack_28 = 0x3f800000;
  uStack_2c = 0x826289;
  (**(code **)(*piVar3 + 0x14))();
  uStack_2c = 0x3f800000;
  (**(code **)(*piVar3 + 0x20))();
  (**(code **)(*piVar3 + 0x2c))(0x3f800000);
  (**(code **)(*piVar3 + 0x38))(iStack_4 + -60000);
  if (*(int **)(param_1 + 4) == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(param_1 + 4) + 0x18))();
  }
  (**(code **)(*piVar3 + 8))();
  piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x48) + 0x24))();
  (**(code **)(*piVar3 + 8))();
  if (*(int **)(param_1 + 0x4c) == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x4c) + 0x18))();
  }
  iVar2 = (**(code **)(*piVar3 + 0x18))(iStack_4);
  uVar1 = *(undefined4 *)(iVar2 + 4);
  (**(code **)(*piVar3 + 0x18))(iStack_4);
  FUN_00797a50(&uStack_2c,0,0x11);
  uStack_28 = uVar1;
  (**(code **)(*DAT_00b5a6b8 + 4))();
  (**(code **)(*piVar3 + 0x24))(&uStack_2c);
  return;
}


// ==== FUN_00826370 @ 0x00826370 ====

void FUN_00826370(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uStack_28;
  undefined4 uStack_4;
  
  if (*(int **)(param_1 + 0x44) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    uStack_28 = 0x82638b;
    piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x44) + 0x18))();
  }
  uStack_28 = param_3;
  (**(code **)(*piVar1 + 0x14))();
  (**(code **)(*piVar1 + 0x20))(param_3);
  (**(code **)(*piVar1 + 0x2c))(param_3);
  if (*(int **)(param_1 + 4) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(param_1 + 4) + 0x18))();
  }
  (**(code **)(*piVar1 + 8))();
  piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x48) + 0x24))();
  (**(code **)(*piVar1 + 8))();
  if (*(int **)(param_1 + 0x4c) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar1 + 0x18))(uStack_4);
  (**(code **)(*piVar1 + 0x18))(uStack_4);
  FUN_00797a50(&uStack_28,0,0x11);
  (**(code **)(*DAT_00b5a6b8 + 4))();
  (**(code **)(*piVar1 + 0x24))(&uStack_28);
  return;
}


// ==== FUN_00826490 @ 0x00826490 ====

void FUN_00826490(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined2 unaff_BX;
  int *piVar4;
  undefined4 uStack_2c;
  undefined4 uStack_c;
  
  if (*(int **)(param_1 + 0x44) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    uStack_2c = 0x8264aa;
    piVar4 = (int *)(**(code **)(**(int **)(param_1 + 0x44) + 0x18))();
  }
  uStack_2c = 0x8264b3;
  puVar2 = (undefined4 *)(**(code **)(*piVar4 + 0xc))();
  uVar1 = *puVar2;
  uStack_2c = 0x8264c0;
  (**(code **)(*piVar4 + 0xc))();
  uStack_2c = uVar1;
  (**(code **)(*piVar4 + 0x14))();
  (**(code **)(*piVar4 + 0x20))(unaff_BX);
  iVar3 = (**(code **)(*piVar4 + 0xc))();
  (**(code **)(*piVar4 + 0x2c))((short)*(undefined4 *)(iVar3 + 0x28));
  iVar3 = (**(code **)(*DAT_00b5a690 + 4))();
  (**(code **)(*piVar4 + 0x38))(iVar3 + -60000);
  (**(code **)(*piVar4 + 0x3c))(0);
  if (*(int **)(param_1 + 0x4c) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(param_1 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar4 + 0x18))(uStack_c);
  FUN_00797a50(&uStack_2c,0,0x11);
  (**(code **)(*DAT_00b5a6b8 + 4))();
  (**(code **)(*piVar4 + 0x24))(&uStack_2c);
  return;
}


// ==== FUN_008265c0 @ 0x008265c0 ====

void FUN_008265c0(int param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined2 uStack_8;
  
  if (*(int **)(param_1 + 0x8c) == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x8c) + 0x18))();
  }
  puVar4 = (undefined4 *)(**(code **)(*piVar3 + 0x10))();
  uVar2 = *puVar4;
  uVar1 = *(undefined2 *)(puVar4 + 1);
  uStack_8 = (undefined2)uVar2;
  *param_2 = uStack_8;
  param_2[1] = (short)((uint)uVar2 >> 0x10);
  param_2[2] = uVar1;
  *(undefined1 *)(param_2 + 3) = 0;
  return;
}


// ==== FUN_00826610 @ 0x00826610 ====

void FUN_00826610(int param_1,undefined4 param_2)

{
  short sVar1;
  undefined2 uVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined2 *unaff_retaddr;
  char *pcVar8;
  undefined1 auStack_fe [254];
  
  piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x7c) + 0x14))();
  sVar1 = (**(code **)(*piVar3 + 0x20))();
  if (sVar1 == 0) {
    FUN_008265c0(param_1,param_2);
    return;
  }
  iVar6 = *DAT_00b5ab84;
  uVar4 = (**(code **)(*piVar3 + 0x20))();
  piVar5 = (int *)(**(code **)(iVar6 + 0xc))(uVar4);
  if (piVar5 == (int *)0x0) {
    FUN_008265c0(param_1,param_1);
    uVar2 = (**(code **)(*piVar3 + 0x20))();
    pcVar8 = s_Not_Exist_Chaotic_Index____d_00a0c440;
  }
  else {
    iVar6 = (**(code **)(*piVar5 + 4))();
    sVar1 = *(short *)(iVar6 + 0xe);
    if (sVar1 != 0) {
      piVar3 = (int *)(**(code **)(*DAT_00b5ab34 + 8))(sVar1);
      if (piVar3 == (int *)0x0) {
        FUN_008265c0(param_1,unaff_retaddr);
        uVar4 = FUN_0044a580(auStack_fe + -10,s_Not_Exist_Location_Index____d_00a0c488,sVar1);
        FUN_00797b80(uVar4);
        return;
      }
      iVar6 = (**(code **)(*piVar3 + 4))();
      *unaff_retaddr = *(undefined2 *)(iVar6 + 0x102);
      iVar6 = (**(code **)(*piVar3 + 4))();
      unaff_retaddr[1] = *(undefined2 *)(iVar6 + 0x104);
      iVar6 = (**(code **)(*piVar3 + 4))();
      unaff_retaddr[2] = *(undefined2 *)(iVar6 + 0x106);
      return;
    }
    if (*(int **)(param_1 + 0x8c) == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x8c) + 0x18))();
    }
    piVar5 = DAT_00b5ab28;
    puVar7 = (undefined2 *)(**(code **)(*piVar3 + 0x10))();
    piVar5 = (int *)(**(code **)(*piVar5 + 8))(*puVar7);
    if (piVar5 != (int *)0x0) {
      puVar7 = (undefined2 *)(**(code **)(*piVar5 + 4))();
      *unaff_retaddr = *puVar7;
      iVar6 = (**(code **)(*piVar5 + 4))();
      unaff_retaddr[1] = *(undefined2 *)(iVar6 + 2);
      iVar6 = (**(code **)(*piVar5 + 4))();
      unaff_retaddr[2] = *(undefined2 *)(iVar6 + 4);
      return;
    }
    FUN_008265c0(param_1,unaff_retaddr);
    puVar7 = (undefined2 *)(**(code **)(*piVar3 + 0x10))();
    uVar2 = *puVar7;
    pcVar8 = s_Not_Exist_Chaotic_Location_Index_00a0c460;
  }
  uVar4 = FUN_0044a580(auStack_fe + -6,pcVar8,uVar2);
  FUN_00797b80(uVar4);
  return;
}


// ==== FUN_008267f0 @ 0x008267f0 ====

void FUN_008267f0(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 unaff_EBX;
  int *piVar4;
  undefined4 uStack_2c;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  if (*(int **)(param_1 + 0x44) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    uStack_2c = 0x82680b;
    piVar4 = (int *)(**(code **)(**(int **)(param_1 + 0x44) + 0x18))();
  }
  uStack_2c = 0x826814;
  puVar2 = (undefined4 *)(**(code **)(*piVar4 + 0xc))();
  uVar1 = *puVar2;
  uStack_2c = 0x826821;
  (**(code **)(*piVar4 + 0xc))();
  uStack_2c = uVar1;
  (**(code **)(*piVar4 + 0x14))();
  (**(code **)(*piVar4 + 0x20))(unaff_EBX);
  iVar3 = (**(code **)(*piVar4 + 0xc))();
  (**(code **)(*piVar4 + 0x2c))(*(undefined4 *)(iVar3 + 0x28));
  iVar3 = (**(code **)(*DAT_00b5a690 + 4))();
  (**(code **)(*piVar4 + 0x38))(iVar3 + -60000);
  (**(code **)(*piVar4 + 0x3c))(0);
  FUN_00826610(param_1,uStack_8);
  if (*(int **)(param_1 + 0x4c) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(param_1 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar4 + 0x18))(uStack_c);
  FUN_00797a50(&uStack_2c,0,0x11);
  (**(code **)(*DAT_00b5a6b8 + 4))();
  (**(code **)(*piVar4 + 0x24))(&uStack_2c);
  return;
}


// ==== FUN_00826b20 @ 0x00826b20 ====

void FUN_00826b20(int param_1,undefined4 param_2)

{
  if (*(int **)(param_1 + 0x14) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x14) + 0x20))(param_2);
  }
  return;
}


// ==== FUN_00826b40 @ 0x00826b40 ====

void FUN_00826b40(int param_1)

{
  if (*(int **)(param_1 + 0x14) == (int *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00826b4d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x14) + 0x2c))();
  return;
}


// ==== FUN_00826b60 @ 0x00826b60 ====

int FUN_00826b60(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 extraout_var;
  undefined1 auStack_fe [254];
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  piVar1 = (int *)(**(code **)(*param_1 + 0x48))();
  iVar2 = (**(code **)(*piVar1 + 4))();
  if (*(int *)(iVar2 + 0xc) == 0x413) {
    iVar2 = *DAT_00b5ab74;
    iVar3 = (**(code **)(*piVar1 + 4))();
    iVar2 = (**(code **)(iVar2 + 8))(CONCAT22(extraout_var,*(undefined2 *)(iVar3 + 0x24)));
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*piVar1 + 4))();
    uVar4 = FUN_0044a580(auStack_fe + -6,s_CANNOT_FIND_ROD_FLY_index__d_00a0c4dc,
                         *(undefined2 *)(iVar2 + 0x24));
    FUN_00797b80(uVar4);
  }
  return 0;
}


// ==== FUN_00826bf0 @ 0x00826bf0 ====

void FUN_00826bf0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_1 + 0x24);
  uVar2 = (**(code **)(*piVar1 + 0x2c))(4);
  iVar3 = FUN_00826b60(uVar2);
  if (iVar3 == 0) {
    uVar2 = (**(code **)(*piVar1 + 0x2c))(5);
    FUN_00826b60(uVar2);
    return;
  }
  return;
}


// ==== FUN_00826c30 @ 0x00826c30 ====

undefined2 FUN_00826c30(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = *(int **)(param_1 + 0x24);
  piVar1 = (int *)(**(code **)(*piVar2 + 0x2c))(4);
  piVar2 = (int *)(**(code **)(*piVar2 + 0x2c))(5);
  if ((piVar1 != (int *)0x0) && (piVar2 != (int *)0x0)) {
    iVar3 = (**(code **)(*piVar1 + 0x2c))();
    iVar3 = *(int *)(iVar3 + 8);
    iVar4 = (**(code **)(*piVar2 + 0x2c))();
    iVar4 = *(int *)(iVar4 + 8);
    if (iVar3 == 0x40f) {
      if (iVar4 == 0x40a) {
LAB_00826c91:
        iVar3 = (**(code **)(*piVar1 + 0x14))();
        return *(undefined2 *)(iVar3 + 0xc);
      }
    }
    else {
      if (iVar3 != 0x410) {
        if (iVar3 == 0x40a) {
          if (iVar4 != 0x40f) {
            return 0;
          }
        }
        else {
          if (iVar3 != 0x40b) {
            return 0;
          }
          if (iVar4 != 0x410) {
            return 0;
          }
        }
        iVar3 = (**(code **)(*piVar2 + 0x14))();
        return *(undefined2 *)(iVar3 + 0xc);
      }
      if (iVar4 == 0x40b) goto LAB_00826c91;
    }
  }
  return 0;
}


// ==== FUN_00826cf0 @ 0x00826cf0 ====

int FUN_00826cf0(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (**(code **)(*DAT_00b5adb4 + 4))();
  uVar1 = *(uint *)(iVar2 + 0x2c);
  iVar2 = (**(code **)(*DAT_00b5adb4 + 4))();
  if (param_2 == 0) {
    return param_1 + uVar1;
  }
  uVar3 = *(int *)(iVar2 + 0x30) * param_2;
  if (uVar3 < uVar1) {
    return (uVar1 - uVar3) + param_1;
  }
  return param_1;
}


// ==== FUN_00826d40 @ 0x00826d40 ====

int FUN_00826d40(int *param_1)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5aaf8 + 0xc))();
  iVar5 = 0;
  do {
    if (piVar1 == (int *)0x0) {
      return iVar5;
    }
    piVar1 = (int *)(**(code **)(*piVar1 + 0xc))();
    iVar2 = (**(code **)(*param_1 + 0xc))();
    pcVar3 = (char *)(**(code **)(*piVar1 + 4))();
    uVar4 = 0;
    iVar2 = (iVar2 + 0x200) - (int)pcVar3;
    do {
      if (*pcVar3 != pcVar3[iVar2]) goto LAB_00826d9c;
      if (*pcVar3 == '\0') break;
      uVar4 = uVar4 + 1;
      pcVar3 = pcVar3 + 1;
    } while (uVar4 < 0x21);
    iVar5 = iVar5 + 1;
LAB_00826d9c:
    piVar1 = (int *)(**(code **)(*DAT_00b5aaf8 + 0x10))();
  } while( true );
}


// ==== FUN_00826dc0 @ 0x00826dc0 ====

void FUN_00826dc0(int *param_1,int param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_100 [256];
  
  piVar1 = (int *)(**(code **)(*param_1 + 0xc4))();
  if (piVar1 == (int *)0x0) {
LAB_00826ea0:
    iVar3 = (**(code **)(*DAT_00b5adb4 + 4))();
    iVar3 = *(int *)(iVar3 + 0x2c);
    (**(code **)(*DAT_00b5adb4 + 4))();
    *param_3 = iVar3 + param_2;
    return;
  }
  piVar2 = (int *)(**(code **)(*param_1 + 8))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x2c))();
  iVar3 = (**(code **)(*piVar2 + 0x10))();
  if (*(char *)(iVar3 + 0x963) == '\0') {
    iVar3 = (**(code **)(*DAT_00b5adb4 + 4))();
    iVar3 = *(int *)(iVar3 + 0x2c);
    (**(code **)(*DAT_00b5adb4 + 4))();
    *param_3 = iVar3 + param_2;
    return;
  }
  piVar2 = (int *)(**(code **)(*piVar1 + 0x14))();
  iVar3 = (**(code **)(*piVar2 + 0x10))();
  if (iVar3 != 1) {
    iVar3 = (**(code **)(*piVar2 + 0x10))();
    if (iVar3 != 3) {
      FUN_0044a580(auStack_100,&DAT_00a0c53c,s___ASSERT___Revival__Execute___Lo_00a0c500);
      FUN_00797b80(auStack_100);
      goto LAB_00826ea0;
    }
  }
  uVar4 = FUN_00826d40(piVar1);
  iVar3 = FUN_00826cf0(param_2,uVar4);
  *param_3 = iVar3;
  return;
}


// ==== FUN_00826ee0 @ 0x00826ee0 ====

void FUN_00826ee0(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x88) + 0x14))();
  param_1 = 4;
  (**(code **)(*piVar1 + 0x10))(&param_1);
  return;
}


// ==== FUN_00826f20 @ 0x00826f20 ====

void FUN_00826f20(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined1 uStack00000000;
  
  piVar2 = (int *)(**(code **)(**(int **)(param_1 + 0x88) + 0x14))();
  iVar1 = **(int **)(param_1 + 0x50);
  uVar3 = (**(code **)(*DAT_00b5a690 + 4))();
  (**(code **)(iVar1 + 0x14))(uVar3);
  (**(code **)(*piVar2 + 0x10))(&uStack00000000);
  (**(code **)(*piVar2 + 0x5c))(3);
  return;
}


// ==== FUN_00826f70 @ 0x00826f70 ====

byte FUN_00826f70(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*param_1 + 8))();
  if (*piVar1 < 1) {
    return 1;
  }
  if (*piVar1 < piVar1[1]) {
    return (0 < piVar1[2]) - 1U & 2;
  }
  return 3;
}


// ==== FUN_00826fc0 @ 0x00826fc0 ====

undefined4 FUN_00826fc0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined1 auStack_100 [256];
  
  piVar2 = *(int **)(param_1 + 0x84);
  cVar1 = (**(code **)(*piVar2 + 0x34))();
  if (cVar1 == '\0') {
    FUN_0044a580(auStack_100,&DAT_00a0c574,s_FIGHTING_EXCEPTION___1_00a0c544);
    FUN_00797b80(auStack_100);
    return 4;
  }
  piVar2 = (int *)(**(code **)(*piVar2 + 0x18))();
  piVar3 = (int *)(**(code **)(*piVar2 + 0x14))();
  piVar4 = (int *)(**(code **)(*piVar2 + 0x18))();
  if ((piVar3 == (int *)0x0) || (piVar4 == (int *)0x0)) {
    FUN_0044a580(auStack_100,&DAT_00a0c574,s_FIGHTING_EXCEPTION___2_00a0c55c);
    FUN_00797b80(auStack_100);
    return 4;
  }
  piVar5 = (int *)(**(code **)(*piVar2 + 8))();
  iVar6 = (**(code **)(*piVar3 + 4))();
  iVar7 = (**(code **)(*piVar4 + 4))();
  uVar8 = (**(code **)(*DAT_00b5a690 + 4))();
  if (param_2 == 0) {
    if (param_3 == 0) {
      iVar9 = piVar5[2];
      iVar6 = *piVar5 - *(int *)(iVar7 + 0x10c);
      goto LAB_0082709b;
    }
    iVar9 = *(int *)(iVar7 + 0x108) + piVar5[2];
  }
  else {
    if (param_3 == 0) {
      iVar9 = piVar5[2] - *(int *)(iVar6 + 0x18);
      iVar6 = *piVar5 - *(int *)(iVar7 + 0x10c);
      goto LAB_0082709b;
    }
    iVar9 = *(int *)(iVar7 + 0x108) + piVar5[2];
  }
  iVar6 = *(int *)(iVar6 + 0x14) + *piVar5;
LAB_0082709b:
  (**(code **)(*piVar2 + 0x1c))(iVar6,iVar9,uVar8);
  uVar8 = FUN_00826f70(piVar2);
  return uVar8;
}


// ==== FUN_00827110 @ 0x00827110 ====

void FUN_00827110(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x88) + 0x14))();
  param_1 = 0;
  (**(code **)(*piVar1 + 0x10))(&param_1);
  return;
}


// ==== FUN_00827140 @ 0x00827140 ====

void FUN_00827140(int param_1,undefined4 param_2)

{
  (**(code **)(**(int **)(param_1 + 0x20) + 0x40))(param_2);
  return;
}


// ==== FUN_00827160 @ 0x00827160 ====

void FUN_00827160(int *param_1,byte param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  uint uVar4;
  
  piVar1 = param_1;
  (**(code **)(*param_1 + 0x3c))(param_2);
  iVar2 = *param_1;
  param_1._0_1_ = param_2;
  uVar4 = (uint)param_2;
  iVar2 = (**(code **)(iVar2 + 0x14))();
  if ((int)uVar4 < (int)(*(byte *)(iVar2 + 0x1e) - 1)) {
    do {
      iVar2 = (**(code **)(*piVar1 + 0x14))();
      if (*(short *)(iVar2 + 6 + uVar4 * 2) != 0) {
        (**(code **)(*piVar1 + 0x3c))((byte)param_1);
        iVar2 = *piVar1;
        iVar3 = (**(code **)(iVar2 + 0x14))();
        (**(code **)(iVar2 + 0x38))
                  ((byte)param_1,CONCAT22(extraout_var,*(undefined2 *)(iVar3 + 6 + uVar4 * 2)));
      }
      param_1._0_1_ = (byte)param_1 + 1;
      uVar4 = (uint)(byte)param_1;
      iVar2 = (**(code **)(*piVar1 + 0x14))();
    } while ((int)uVar4 < (int)(*(byte *)(iVar2 + 0x1e) - 1));
  }
  iVar2 = *piVar1;
  iVar3 = (**(code **)(iVar2 + 0x14))();
  (**(code **)(iVar2 + 0x3c))(CONCAT22(extraout_var_00,(ushort)*(byte *)(iVar3 + 0x1e)) + -1);
  iVar2 = *piVar1;
  iVar3 = (**(code **)(iVar2 + 0x14))();
  (**(code **)(iVar2 + 0x40))(*(char *)(iVar3 + 0x1e) + -1);
  return;
}


// ==== FUN_00827210 @ 0x00827210 ====

int FUN_00827210(byte param_1)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (5 < param_1) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                         s_d__usa_24_0_1_2__develop_share_l_00a0c578,0x60);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  return in_ECX + (uint)param_1 * 2 + (uint)param_1;
}


// ==== FUN_00827270 @ 0x00827270 ====

void FUN_00827270(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined3 *puVar6;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  undefined1 auStack_6 [2];
  uint uStack_4;
  
  piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x20) + 0x28))(param_2 + 0x15);
  piVar4 = (int *)(**(code **)(*piVar3 + 0x48))();
  bVar1 = *(byte *)(param_2 + 0x10);
  (**(code **)(*piVar4 + 4))();
  (**(code **)(*piVar3 + 0x14))();
  piVar3 = (int *)(**(code **)(*DAT_00b5aa20 + 8))(auStack_6 + -6);
  puVar5 = (undefined4 *)(**(code **)(*piVar3 + 4))();
  FUN_00827bf0(param_1,*puVar5);
  if ((char)uStack_4 != '\0') {
    FUN_00827440(param_1,CONCAT13(extraout_var,*(undefined3 *)(param_2 + 0x12)),1);
  }
  if (bVar1 != 0) {
    uStack_4 = uStack_4 & 0xffffff00;
    do {
      puVar6 = (undefined3 *)FUN_00827210(uStack_4);
      FUN_00827440(param_1,CONCAT13(extraout_var_00,*puVar6),1);
      bVar2 = (char)uStack_4 + 1;
      uStack_4 = CONCAT31(uStack_4._1_3_,bVar2);
    } while (bVar2 < bVar1);
  }
  return;
}


// ==== FUN_00827360 @ 0x00827360 ====

void FUN_00827360(int *param_1,undefined1 param_2)

{
  (**(code **)(*param_1 + 0x3c))(param_2);
  return;
}


// ==== FUN_00827380 @ 0x00827380 ====

void FUN_00827380(int param_1,undefined1 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar1 = *(int **)(param_1 + 0x20);
  piVar2 = (int *)(**(code **)(*piVar1 + 0x28))(&param_2);
  iVar3 = (**(code **)(*piVar2 + 0x14))();
  if (*(ushort *)(iVar3 + 0xc) < 2) {
    uVar4 = (**(code **)(*piVar1 + 0x20))(&param_1);
    (**(code **)(*DAT_00b5a730 + 0x10))(1,uVar4);
    return;
  }
  (**(code **)(*piVar2 + 0x20))
            (CONCAT22((short)((uint)iVar3 >> 0x10),*(ushort *)(iVar3 + 0xc)) + -1);
  return;
}


// ==== FUN_008273e0 @ 0x008273e0 ====

void FUN_008273e0(int param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar1 = *(int **)(param_1 + 0x24);
  piVar2 = (int *)(**(code **)(*piVar1 + 0x2c))(param_2);
  iVar3 = (**(code **)(*piVar2 + 0x14))();
  if (*(ushort *)(iVar3 + 0xc) < 2) {
    uVar4 = (**(code **)(*piVar1 + 0x20))(param_2);
    (**(code **)(*DAT_00b5a730 + 0x10))(1,uVar4);
    return;
  }
  (**(code **)(*piVar2 + 0x20))
            (CONCAT22((short)((uint)iVar3 >> 0x10),*(ushort *)(iVar3 + 0xc)) + -1);
  return;
}


// ==== FUN_00827440 @ 0x00827440 ====

void FUN_00827440(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  
  piVar1 = *(int **)(param_1 + 0x20);
  piVar2 = (int *)(**(code **)(*piVar1 + 0x28))(&param_2);
  if (piVar2 != (int *)0x0) {
    piVar3 = (int *)(**(code **)(*piVar2 + 0x48))();
    iVar4 = (**(code **)(*piVar3 + 4))();
    if (*(ushort *)(iVar4 + 0x76) < 2) {
      uVar5 = (**(code **)(*piVar1 + 0x20))(&param_1);
      (**(code **)(*DAT_00b5a730 + 0x10))(1,uVar5);
      return;
    }
    iVar4 = (**(code **)(*piVar2 + 0x14))();
    if (*(ushort *)(iVar4 + 0xc) <= (ushort)param_2) {
      uVar5 = (**(code **)(*piVar1 + 0x20))(&param_1);
      (**(code **)(*DAT_00b5a730 + 0x10))(1,uVar5);
      return;
    }
    (**(code **)(*piVar2 + 0x20))
              (CONCAT22((short)((uint)iVar4 >> 0x10),*(ushort *)(iVar4 + 0xc)) - param_2);
  }
  return;
}


// ==== FUN_008274d0 @ 0x008274d0 ====

int * FUN_008274d0(int *param_1,short param_2)

{
  int *piVar1;
  short *psVar2;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x30))();
  if (piVar1 != (int *)0x0) {
    do {
      psVar2 = (short *)(**(code **)(*piVar1 + 0x14))();
      if (*psVar2 == param_2) {
        return piVar1;
      }
      piVar1 = (int *)(**(code **)(*param_1 + 0x34))();
    } while (piVar1 != (int *)0x0);
  }
  return (int *)0x0;
}


// ==== FUN_00827520 @ 0x00827520 ====

undefined4 FUN_00827520(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = FUN_008274d0(piVar1,param_2);
  if (iVar2 == 0) {
    return 0;
  }
  (**(code **)(*piVar1 + 0x18))(iVar2,param_3);
  return 1;
}


// ==== FUN_00827550 @ 0x00827550 ====

undefined1 FUN_00827550(int param_1,int *param_2,undefined4 param_3,undefined2 param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_1 + 0x20);
  cVar2 = FUN_00829ed0(param_1,param_3,param_4);
  if (cVar2 == '\0') {
    return 0;
  }
  cVar2 = (**(code **)(*piVar1 + 0x40))(param_2);
  if (cVar2 != '\x01') {
    iVar3 = (**(code **)(*param_2 + 0x14))();
    if (*(char *)(iVar3 + 0x21) == '\x01') {
      cVar2 = (**(code **)(*piVar1 + 0x5c))(param_2);
      if (cVar2 == '\0') {
        return 0;
      }
    }
  }
  return 1;
}


// ==== FUN_008275b0 @ 0x008275b0 ====

bool FUN_008275b0(int param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
                 undefined4 param_5)

{
  int *piVar1;
  char cVar2;
  
  piVar1 = *(int **)(param_1 + 0x20);
  cVar2 = FUN_00829ed0(param_1,param_3,param_4);
  if (cVar2 == '\0') {
    return false;
  }
  cVar2 = (**(code **)(*piVar1 + 0x1c))(param_5,param_2);
  return cVar2 != '\0';
}


// ==== FUN_008275f0 @ 0x008275f0 ====

undefined4 FUN_008275f0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x20) + 0x20))(param_2);
  if (iVar1 == 0) {
    return 0;
  }
  (**(code **)(*DAT_00b5a730 + 0x10))(1,iVar1);
  return 1;
}


// ==== FUN_00827620 @ 0x00827620 ====

uint FUN_00827620(int param_1,int *param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  ushort *puVar8;
  int *unaff_EDI;
  
  piVar5 = *(int **)(param_1 + 0x24);
  piVar2 = *(int **)(param_1 + 0x98);
  (**(code **)(*piVar2 + 0x1c))();
  uVar1 = (**(code **)(*piVar2 + 0x40))();
  if (uVar1 != 0) {
LAB_00827642:
    return uVar1 & 0xffff0000;
  }
  piVar2 = (int *)(**(code **)(*param_2 + 0x2c))();
  iVar3 = (**(code **)(*piVar2 + 0x10))();
  if (*(char *)(iVar3 + 0xee4) == '\0') {
    uVar1 = (**(code **)(*piVar2 + 0x10))();
    if (*(char *)(uVar1 + 0x963) == '\0') goto LAB_00827642;
  }
  uVar1 = 0;
  piVar2 = (int *)(**(code **)(*piVar5 + 0x2c))(6);
  piVar4 = (int *)(**(code **)(*piVar5 + 0x2c))(7);
  (**(code **)(*piVar5 + 0x2c))(0x13);
  piVar5 = (int *)(**(code **)(*piVar5 + 0x2c))(0x14);
  if ((((piVar2 == (int *)0x0) && (piVar4 == (int *)0x0)) && (unaff_EDI == (int *)0x0)) &&
     (piVar5 == (int *)0x0)) {
    return 0;
  }
  iVar3 = 0;
  if (piVar2 != (int *)0x0) {
    piVar6 = (int *)(**(code **)(*piVar2 + 0x48))();
    iVar7 = (**(code **)(*piVar6 + 4))();
    if (*(int *)(iVar7 + 0xc) == 0x604) {
      puVar8 = (ushort *)(**(code **)(*piVar2 + 0x14))();
      uVar1 = (uint)*puVar8;
      iVar3 = 1;
    }
  }
  if (piVar4 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*piVar4 + 0x48))();
    iVar7 = (**(code **)(*piVar2 + 4))();
    if (*(int *)(iVar7 + 0xc) == 0x604) {
      puVar8 = (ushort *)(**(code **)(*piVar4 + 0x14))();
      uVar1 = (uint)*puVar8;
      iVar3 = iVar3 + 1;
    }
  }
  if (unaff_EDI != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*unaff_EDI + 0x48))();
    iVar7 = (**(code **)(*piVar2 + 4))();
    if (*(int *)(iVar7 + 0xc) == 0x604) {
      puVar8 = (ushort *)(**(code **)(*unaff_EDI + 0x14))();
      uVar1 = (uint)*puVar8;
      iVar3 = iVar3 + 1;
    }
  }
  if (piVar5 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*piVar5 + 0x48))();
    iVar7 = (**(code **)(*piVar2 + 4))();
    if (*(int *)(iVar7 + 0xc) == 0x604) {
      puVar8 = (ushort *)(**(code **)(*piVar5 + 0x14))();
      uVar1 = (uint)*puVar8;
      iVar3 = iVar3 + 1;
    }
  }
  return -(uint)(iVar3 != 0) & uVar1;
}


// ==== FUN_00827780 @ 0x00827780 ====

bool FUN_00827780(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  
  piVar5 = *(int **)(param_1 + 0x24);
  piVar2 = *(int **)(param_1 + 0x98);
  (**(code **)(*piVar2 + 0x1c))();
  iVar1 = (**(code **)(*piVar2 + 0x40))();
  if (iVar1 == 0) {
    return false;
  }
  piVar2 = (int *)(**(code **)(*piVar5 + 0x2c))(6);
  piVar3 = (int *)(**(code **)(*piVar5 + 0x2c))(7);
  piVar4 = (int *)(**(code **)(*piVar5 + 0x2c))(0x13);
  piVar5 = (int *)(**(code **)(*piVar5 + 0x2c))(0x14);
  if ((((piVar2 == (int *)0x0) && (piVar3 == (int *)0x0)) && (piVar4 == (int *)0x0)) &&
     (piVar5 == (int *)0x0)) {
    return false;
  }
  iVar1 = 0;
  if (piVar2 != (int *)0x0) {
    piVar6 = (int *)(**(code **)(*piVar2 + 0x48))();
    iVar7 = (**(code **)(*piVar6 + 4))();
    if (*(int *)(iVar7 + 0xc) == 0x604) {
      (**(code **)(*piVar2 + 0x14))();
      iVar1 = 1;
    }
  }
  if (piVar3 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*piVar3 + 0x48))();
    iVar7 = (**(code **)(*piVar2 + 4))();
    if (*(int *)(iVar7 + 0xc) == 0x604) {
      (**(code **)(*piVar3 + 0x14))();
      iVar1 = iVar1 + 1;
    }
  }
  if (piVar4 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*piVar4 + 0x48))();
    iVar7 = (**(code **)(*piVar2 + 4))();
    if (*(int *)(iVar7 + 0xc) == 0x604) {
      (**(code **)(*piVar4 + 0x14))();
      iVar1 = iVar1 + 1;
    }
  }
  if (piVar5 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*piVar5 + 0x48))();
    iVar7 = (**(code **)(*piVar2 + 4))();
    if (*(int *)(iVar7 + 0xc) == 0x604) {
      (**(code **)(*piVar5 + 0x14))();
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1 != 0;
}


// ==== FUN_008278a0 @ 0x008278a0 ====

void FUN_008278a0(int param_1,int *param_2)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  char local_44 [33];
  char local_23 [25];
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  undefined1 local_4;
  
  FUN_00496ec0();
  uVar2 = 0;
  do {
    cVar1 = *(char *)(param_1 + 0x19 + uVar2);
    local_44[uVar2] = cVar1;
    if (cVar1 == '\0') goto LAB_008278cd;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x21);
  local_44[0] = '\0';
LAB_008278cd:
  uVar2 = 0;
  do {
    cVar1 = *(char *)(param_1 + 0x3a + uVar2);
    local_23[uVar2] = cVar1;
    if (cVar1 == '\0') goto LAB_008278e9;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  local_23[0] = '\0';
LAB_008278e9:
  local_a = *(undefined2 *)(param_1 + 0x54);
  local_8 = *(undefined2 *)(param_1 + 0x56);
  local_6 = *(undefined2 *)(param_1 + 0x58);
  local_4 = *(undefined1 *)(param_1 + 0x5b);
  (**(code **)(*param_2 + 0x28))
            (CONCAT31((int3)(CONCAT22((short)(uVar2 >> 0x10),local_a) >> 8),local_4));
  piVar3 = (int *)(**(code **)(*DAT_00b5aca0 + 4))(local_44 + -4);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(*(undefined1 *)(param_1 + 0x5a));
    (**(code **)(*DAT_00b5ac9c + 4))(piVar3);
  }
  return;
}


// ==== FUN_00827960 @ 0x00827960 ====

undefined4 FUN_00827960(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  short *psVar5;
  int iVar6;
  ushort *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int *unaff_retaddr;
  char *pcVar10;
  undefined1 *puStack_134;
  char acStack_108 [4];
  undefined1 auStack_104 [240];
  undefined4 uStack_14;
  undefined2 *puStack_c;
  int iStack_8;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5ab34 + 8))();
  if (piVar2 == (int *)0x0) {
    puStack_134 = auStack_104;
    auStack_104[0] = 0;
    uVar3 = FUN_0044a580();
    FUN_00797b80(uVar3);
    return 0;
  }
  piVar4 = (int *)(**(code **)(*unaff_retaddr + 8))();
  psVar5 = (short *)(**(code **)(*piVar4 + 0x1c))();
  iVar6 = (**(code **)(*piVar2 + 4))();
  if (*psVar5 != *(short *)(iVar6 + 0x102)) {
    piVar4 = (int *)(**(code **)(*unaff_retaddr + 8))();
    auStack_104[0] = 0;
    puVar7 = (ushort *)(**(code **)(*piVar4 + 0x1c))();
    (**(code **)(*piVar2 + 4))();
    puStack_134 = (undefined1 *)(uint)*puVar7;
    uVar3 = FUN_0044a580(auStack_104,s___ASSERT___NOT_SAME___PC_Map_Ind_00a0c638);
    FUN_00797b80(uVar3);
    return 0;
  }
  iVar6 = *DAT_00b5ab14;
  puStack_134 = (undefined1 *)0x827a33;
  iVar8 = (**(code **)(*piVar2 + 4))();
  puStack_134 = (undefined1 *)CONCAT22((short)((uint)iVar8 >> 0x10),*(undefined2 *)(iVar8 + 0x102));
  piVar4 = (int *)(**(code **)(iVar6 + 8))();
  if (piVar4 == (int *)0x0) {
    acStack_108[0] = '\0';
    iVar6 = (**(code **)(*piVar2 + 4))();
    uVar1 = *(undefined2 *)(iVar6 + 0x102);
    pcVar10 = s___ASSERT___Respawn__Execute___Is_00a0c684;
  }
  else {
    acStack_108[0] = (**(code **)(*piVar4 + 0x1c))();
    if (acStack_108[0] != '\0') {
      if ((int *)unaff_retaddr[0x11] == (int *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)(**(code **)(*(int *)unaff_retaddr[0x11] + 0x18))();
      }
      puVar9 = (undefined4 *)(**(code **)(*piVar4 + 0xc))();
      uVar3 = *puVar9;
      (**(code **)(*piVar4 + 0xc))();
      (**(code **)(*piVar4 + 0x14))(uVar3);
      (**(code **)(*piVar4 + 0x20))(param_2);
      iVar6 = (**(code **)(*piVar4 + 0xc))();
      (**(code **)(*piVar4 + 0x2c))(*(undefined4 *)(iVar6 + 0x28));
      (**(code **)(*piVar4 + 0x38))(iStack_8 + -60000);
      (**(code **)(*piVar4 + 0x3c))(0);
      iVar6 = (**(code **)(*piVar2 + 4))();
      *puStack_c = *(undefined2 *)(iVar6 + 0x102);
      iVar6 = (**(code **)(*piVar2 + 4))();
      puStack_c[1] = *(undefined2 *)(iVar6 + 0x104);
      iVar6 = (**(code **)(*piVar2 + 4))();
      puStack_c[2] = *(undefined2 *)(iVar6 + 0x106);
      if ((int *)unaff_retaddr[0x13] == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = (int *)(**(code **)(*(int *)unaff_retaddr[0x13] + 0x18))();
      }
      iVar6 = (**(code **)(*piVar2 + 0x18))(iStack_8 + -60000);
      FUN_00506db0(&puStack_134,uStack_14,*(undefined1 *)(iVar6 + 10));
      (**(code **)(*DAT_00b5a6b8 + 4))();
      (**(code **)(*piVar2 + 0x24))(&puStack_134);
      return 1;
    }
    iVar6 = (**(code **)(*piVar2 + 4))();
    uVar1 = *(undefined2 *)(iVar6 + 0x102);
    pcVar10 = s___ASSERT___Is_Not_Siege_Map__MAP_00a0c6c4;
  }
  uVar3 = FUN_0044a580(acStack_108,pcVar10,uVar1);
  FUN_00797b80(uVar3);
  return 0;
}


// ==== FUN_00827bf0 @ 0x00827bf0 ====

bool FUN_00827bf0(int param_1,uint param_2)

{
  char cVar1;
  int *piVar2;
  uint *puVar3;
  
  piVar2 = (int *)(**(code **)(**(int **)(param_1 + 0x20) + 0x54))();
  puVar3 = (uint *)(**(code **)(*piVar2 + 4))();
  if (*puVar3 < param_2) {
    return false;
  }
  cVar1 = (**(code **)(*piVar2 + 0x10))(param_2);
  return cVar1 != '\0';
}


// ==== FUN_00827c40 @ 0x00827c40 ====

undefined4 FUN_00827c40(int *param_1,int *param_2,undefined4 param_3,int param_4,uint *param_5)

{
  uint uVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  piVar2 = (int *)(**(code **)(**(int **)(param_4 + 0x20) + 0x54))();
  if (param_5 != (uint *)0x0) {
    puVar3 = (uint *)(**(code **)(*piVar2 + 4))();
    if (param_5 <= (uint *)*puVar3) {
      iVar4 = (**(code **)(*param_2 + 4))();
      uVar1 = *(uint *)(iVar4 + 0x2c);
      (**(code **)(*DAT_00b5adb4 + 4))();
      iVar4 = (**(code **)(*DAT_00b5adb4 + 4))();
      puVar3 = *(uint **)(iVar4 + 0x14);
      if (param_5 < puVar3) {
        return 2;
      }
      iVar4 = (**(code **)(*param_1 + 0x34))(param_3);
      iVar5 = (**(code **)(*param_2 + 4))();
      uVar6 = *(int *)(iVar5 + 0x30) + *(int *)(iVar4 + 8);
      if (uVar6 < uVar1) {
        if ((uint)param_5 % (uint)puVar3 != 0) {
          return 4;
        }
        if (uVar6 + (uint)param_5 / (uint)puVar3 <= uVar1) {
          *param_5 = (uint)param_5 / (uint)puVar3;
          return 0;
        }
      }
      return 3;
    }
  }
  return 1;
}


// ==== FUN_00827c67 @ 0x00827c67 ====

undefined4
FUN_00827c67(undefined4 param_1,int *param_2,int *param_3,undefined4 param_4,undefined4 param_5,
            uint *param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint unaff_EDI;
  
  iVar3 = (**(code **)(*param_3 + 4))();
  uVar1 = *(uint *)(iVar3 + 0x2c);
  (**(code **)(*DAT_00b5adb4 + 4))();
  iVar3 = (**(code **)(*DAT_00b5adb4 + 4))();
  uVar2 = *(uint *)(iVar3 + 0x14);
  if (unaff_EDI < uVar2) {
    return 2;
  }
  iVar3 = (**(code **)(*param_2 + 0x34))(param_4);
  iVar4 = (**(code **)(*param_3 + 4))();
  uVar5 = *(int *)(iVar4 + 0x30) + *(int *)(iVar3 + 8);
  if (uVar5 < uVar1) {
    if (unaff_EDI % uVar2 != 0) {
      return 4;
    }
    if (uVar5 + unaff_EDI / uVar2 <= uVar1) {
      *param_6 = unaff_EDI / uVar2;
      return 0;
    }
  }
  return 3;
}


// ==== FUN_00827d10 @ 0x00827d10 ====

void FUN_00827d10(int *param_1,int *param_2,undefined4 param_3,int *param_4,ushort *param_5)

{
  int *piVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uStack_10c;
  undefined2 uStack_108;
  undefined2 uStack_106;
  ushort uStack_104;
  ushort uStack_102;
  
  piVar1 = (int *)(**(code **)(*param_2 + 0x3c))();
  (**(code **)(*piVar1 + 0x1c))();
  (**(code **)(*DAT_00b5adb4 + 4))();
  uStack_10c = param_3;
  puVar2 = (undefined2 *)(**(code **)(*param_1 + 0x1c))();
  uStack_108 = *puVar2;
  puVar2 = (undefined2 *)(**(code **)(*param_4 + 0x1c))();
  uStack_106 = *puVar2;
  uStack_104 = *param_5;
  uStack_102 = param_5[1];
  iVar3 = (**(code **)(*DAT_00b5abf8 + 4))(&uStack_10c);
  if (iVar3 == 0) {
    uStack_104 = uStack_104 & 0xff00;
    uVar4 = FUN_0044a580(&uStack_104,s_SENTRYTREE_LOCATE_ARRANGE_FAIL_L_00a0c6fc,param_3);
    FUN_00797b80(uVar4);
    return;
  }
  (**(code **)(*piVar1 + 4))(iVar3);
  return;
}


// ==== FUN_00827dd0 @ 0x00827dd0 ====

void FUN_00827dd0(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_fe [254];
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x3c))();
  iVar2 = (**(code **)(*piVar1 + 0x14))(param_2);
  if (iVar2 == 0) {
    uVar3 = FUN_0044a580(auStack_fe + -6,s_SENTRYTREE_LOCATE_SEARCH_FAIL_LO_00a0c730);
    FUN_00797b80(uVar3);
    return;
  }
  (**(code **)(*piVar1 + 8))(param_2);
  (**(code **)(*DAT_00b5abf8 + 8))(iVar2);
  return;
}


// ==== FUN_00827e80 @ 0x00827e80 ====

undefined4 FUN_00827e80(int param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  
  piVar1 = *(int **)(param_1 + 0x20);
  piVar2 = *(int **)(param_1 + 0x24);
  cVar3 = (**(code **)(*piVar2 + 0x34))(param_2);
  if (cVar3 == '\x01') {
    (**(code **)(*piVar2 + 0x38))();
    return 1;
  }
  cVar3 = (**(code **)(*piVar1 + 0x58))(param_2);
  if (cVar3 == '\x01') {
    (**(code **)(*piVar1 + 0x5c))();
    return 1;
  }
  cVar3 = (**(code **)(*piVar1 + 0x3c))(param_2);
  if (cVar3 == '\x01') {
    (**(code **)(*piVar1 + 0x40))(param_2);
    return 1;
  }
  return 0;
}


// ==== FUN_00827ef0 @ 0x00827ef0 ====

undefined4 FUN_00827ef0(int param_1,undefined4 param_2)

{
  ushort *puVar1;
  ushort *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int *unaff_EBX;
  int *piVar6;
  uint uVar7;
  int *apiStack_404 [64];
  undefined1 auStack_304 [256];
  undefined1 auStack_204 [256];
  undefined1 auStack_104 [260];
  
  if (*(int **)(param_1 + 0xc) == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)(**(code **)(**(int **)(param_1 + 0xc) + 0x28))();
  }
  puVar1 = (ushort *)(**(code **)(*piVar6 + 0xc))();
  apiStack_404[0] = *(int **)(param_1 + 0xc);
  puVar2 = (ushort *)(**(code **)(*apiStack_404[0] + 0x14))();
  if (*(int **)(param_1 + 4) == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(param_1 + 4) + 0x18))();
  }
  piVar3 = (int *)(**(code **)(*piVar3 + 0x10))();
  iVar4 = (**(code **)(*piVar3 + 4))();
  switch(param_2) {
  case 0:
    if (*(ushort *)(iVar4 + 0x5e) < *puVar1) {
      uVar7 = ((uint)*puVar2 - (uint)*(ushort *)(iVar4 + 0x5e)) + (uint)*puVar1;
      (**(code **)(*piVar6 + 0x14))(*(ushort *)(iVar4 + 0x5e));
      if (0xffff < uVar7) {
        auStack_204[0] = 0;
        uVar5 = FUN_0044a580(auStack_204,s_File___s__Line___d_00a0c78c,
                             s___Perform_Article_Stat_InitPartS_00a0c764,0x49);
        FUN_00797b80(uVar5);
        FUN_00797a40();
      }
      (**(code **)(*unaff_EBX + 0x18))(uVar7);
      return 1;
    }
    break;
  case 1:
    if (*(ushort *)(iVar4 + 0x60) < puVar1[1]) {
      uVar7 = ((uint)*puVar2 - (uint)*(ushort *)(iVar4 + 0x60)) + (uint)puVar1[1];
      (**(code **)(*piVar6 + 0x18))(*(ushort *)(iVar4 + 0x60));
      if (0xffff < uVar7) {
        apiStack_404[0] = (int *)((uint)apiStack_404[0] & 0xffffff00);
        uVar5 = FUN_0044a580(apiStack_404,s_File___s__Line___d_00a0c7c8,
                             s___Perform_Article_Stat_InitPartS_00a0c7a0,0x55);
        FUN_00797b80(uVar5);
        FUN_00797a40();
      }
      (**(code **)(*unaff_EBX + 0x18))(uVar7);
      return 1;
    }
    break;
  case 2:
    if (*(ushort *)(iVar4 + 0x62) < puVar1[2]) {
      uVar7 = ((uint)*puVar2 - (uint)*(ushort *)(iVar4 + 0x62)) + (uint)puVar1[2];
      (**(code **)(*piVar6 + 0x1c))(*(ushort *)(iVar4 + 0x62));
      if (0xffff < uVar7) {
        auStack_304[0] = 0;
        uVar5 = FUN_0044a580(auStack_304,s_File___s__Line___d_00a0c804,
                             s___Perform_Article_Stat_InitPartS_00a0c7dc,0x61);
        FUN_00797b80(uVar5);
        FUN_00797a40();
      }
      (**(code **)(*unaff_EBX + 0x18))(uVar7);
      return 1;
    }
    break;
  case 3:
    if (*(ushort *)(iVar4 + 100) < puVar1[3]) {
      uVar7 = ((uint)*puVar2 - (uint)*(ushort *)(iVar4 + 100)) + (uint)puVar1[3];
      (**(code **)(*piVar6 + 0x20))(*(ushort *)(iVar4 + 100));
      if (0xffff < uVar7) {
        auStack_104[0] = 0;
        uVar5 = FUN_0044a580(auStack_104,s_File___s__Line___d_00a0c840,
                             s___Perform_Article_Stat_InitPartS_00a0c818,0x6d);
        FUN_00797b80(uVar5);
        FUN_00797a40();
      }
      (**(code **)(*unaff_EBX + 0x18))(uVar7);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00828150 @ 0x00828150 ====

undefined4 FUN_00828150(int *param_1)

{
  int *piVar1;
  byte bVar2;
  char cVar3;
  
  piVar1 = (int *)param_1[8];
  bVar2 = (**(code **)(*piVar1 + 0x70))();
  if (bVar2 < 4) {
    cVar3 = (**(code **)(*piVar1 + 0x74))();
    if (cVar3 != '\0') {
      (**(code **)(*param_1 + 0x80))();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00828190 @ 0x00828190 ====

void FUN_00828190(int *param_1)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 0x14))();
  bVar1 = *(byte *)(iVar2 + 0x1e);
  if (bVar1 != 0) {
    (**(code **)(*param_1 + 0x3c))(CONCAT22((short)((uint)iVar2 >> 0x10),(ushort)bVar1) + -1);
    (**(code **)(*param_1 + 0x40))(bVar1 - 1);
  }
  return;
}


// ==== FUN_008281d0 @ 0x008281d0 ====

void FUN_008281d0(int param_1,undefined3 *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined1 auStack_6 [2];
  byte bStack_4;
  
  piVar2 = (int *)(**(code **)(**(int **)(param_1 + 0x20) + 0x28))(param_2 + 5);
  piVar3 = (int *)(**(code **)(*piVar2 + 0x48))();
  cVar1 = *(char *)(param_2 + 4);
  (**(code **)(*piVar3 + 4))();
  (**(code **)(*piVar2 + 0x14))();
  piVar2 = (int *)(**(code **)(*DAT_00b5aa28 + 8))(auStack_6 + -6);
  puVar4 = (undefined4 *)(**(code **)(*piVar2 + 4))();
  FUN_00827bf0(param_1,*puVar4);
  if (cVar1 != '\0') {
    FUN_00827440(param_1,*(undefined3 *)((int)param_2 + 0x11),1);
  }
  if (bStack_4 != 0) {
    uVar5 = (uint)bStack_4;
    do {
      FUN_00827440(param_1,*param_2,1);
      param_2 = (undefined3 *)((int)param_2 + 3);
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  return;
}


// ==== FUN_008282a0 @ 0x008282a0 ====

void FUN_008282a0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x14))();
  (**(code **)(*param_1 + 0x40))(*(char *)(iVar1 + 0x1e) + '\x01');
  return;
}


// ==== FUN_008282c0 @ 0x008282c0 ====

void FUN_008282c0(int param_1,char param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x6c) + 0x14))();
  piVar2 = (int *)(**(code **)(*piVar1 + 0x14))();
  while (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x14))();
    if (*(char *)(iVar3 + 3) == param_2) {
      (**(code **)(*piVar2 + 0x18))();
    }
    piVar2 = (int *)(**(code **)(*piVar1 + 0x18))();
  }
  return;
}


// ==== FUN_00828310 @ 0x00828310 ====

undefined4 FUN_00828310(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x6c) + 0x14))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0xc))(param_2);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*piVar1 + 0x18))();
  return 1;
}


// ==== FUN_00828340 @ 0x00828340 ====

void FUN_00828340(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x6c) + 0x14))();
                    /* WARNING: Could not recover jumptable at 0x00828350. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x20))();
  return;
}


// ==== FUN_00828360 @ 0x00828360 ====

void FUN_00828360(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x6c) + 0x14))();
  (**(code **)(*piVar1 + 0xc))(param_2);
  return;
}


// ==== FUN_00828380 @ 0x00828380 ====

undefined4 FUN_00828380(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x6c) + 0x14))();
  iVar2 = (**(code **)(*piVar1 + 0xc))(param_2);
  if (iVar2 == 0) {
    return 0;
  }
  uVar3 = (**(code **)(*piVar1 + 8))(iVar2);
  return uVar3;
}


// ==== FUN_008283b0 @ 0x008283b0 ====

uint FUN_008283b0(undefined1 param_1,undefined1 param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int unaff_ESI;
  undefined4 unaff_retaddr;
  undefined4 uStack_14;
  
  uStack_14 = 0;
  piVar1 = (int *)(**(code **)(*DAT_00b5abe4 + 0xc))(1);
  (**(code **)(*piVar1 + 8))(unaff_retaddr);
  uStack_14 = CONCAT13(param_2,CONCAT12(param_1,(short)unaff_retaddr));
  (**(code **)(*piVar1 + 0x10))(&uStack_14);
  piVar2 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x6c) + 0x14))();
  uVar3 = (**(code **)(*piVar2 + 0x1c))();
  if (uVar3 < 0x1e) {
    uVar3 = (**(code **)(*piVar2 + 4))(piVar1);
    return uVar3;
  }
  return uVar3 & 0xffffff00;
}


// ==== FUN_00828440 @ 0x00828440 ====

undefined4 FUN_00828440(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  uint uStack_104;
  undefined1 auStack_100 [256];
  
  piVar2 = (int *)(**(code **)(*param_1 + 0x48))();
  uStack_104 = 0;
  if (piVar2 != (int *)0x0) {
    while( true ) {
      iVar1 = *DAT_00b5a738;
      iVar3 = (**(code **)(*piVar2 + 4))();
      piVar4 = (int *)(**(code **)(iVar1 + 0x10))(*(undefined2 *)(iVar3 + 0x118));
      if (piVar4 == (int *)0x0) break;
      uStack_104 = uStack_104 + 1;
      piVar2 = piVar4;
      if (10 < uStack_104) {
        auStack_100[0] = 0;
        puVar5 = (undefined2 *)(**(code **)(*param_1 + 0x14))();
        uVar6 = FUN_0044a580(auStack_100,s_cannot_find_zero_level_index___B_00a0c860,*puVar5);
        FUN_00797b80(uVar6);
        return 0;
      }
    }
  }
  puVar5 = (undefined2 *)(**(code **)(*piVar2 + 4))();
  (**(code **)(*param_1 + 0x18))(*puVar5);
  (**(code **)(*param_1 + 0x44))(piVar2);
  return 1;
}


// ==== FUN_00828500 @ 0x00828500 ====

void FUN_00828500(uint param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined1 extraout_var;
  undefined3 unaff_ESI;
  
  uVar2 = param_1;
  puVar1 = (undefined4 *)(param_1 + 0x20);
  param_1 = param_1 & 0xff000000;
  (**(code **)(*(int *)*puVar1 + 0x18))(param_2,&param_1);
  FUN_00827440(uVar2,CONCAT13(extraout_var,unaff_ESI),1);
  return;
}


// ==== FUN_00828550 @ 0x00828550 ====

undefined4 FUN_00828550(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *unaff_retaddr;
  undefined1 auStack_fe [254];
  
  iVar1 = (**(code **)(*DAT_00b5a738 + 0x10))(param_2);
  if (iVar1 == 0) {
    uVar2 = FUN_0044a580(auStack_fe + -6,s_Not_Exist_Item_Flyweight____d_00a0c8ac,param_2 & 0xffff);
    FUN_00797b80(uVar2);
    return 0;
  }
  (**(code **)(*unaff_retaddr + 0x18))(param_2);
  (**(code **)(*unaff_retaddr + 0x44))(iVar1);
  return 1;
}


// ==== FUN_008285c0 @ 0x008285c0 ====

undefined4 FUN_008285c0(int *param_1)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  undefined1 auStack_100 [256];
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  piVar1 = (int *)(**(code **)(*param_1 + 0x48))();
  if (piVar1 == (int *)0x0) {
    pcVar3 = s___GetCashItemRate___ERROR___Cash_00a0c8d0;
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 4))();
    if (*(int *)(iVar2 + 4) == 4) {
      iVar2 = (**(code **)(*piVar1 + 4))();
      if (*(int *)(iVar2 + 0xc) == 0x101) {
        return 0x12;
      }
      pcVar3 = s___GetCashItemRate___ERROR___NOT_U_00a0c938;
    }
    else {
      pcVar3 = s___GetCashItemRate___ERROR___NOT_C_00a0c90c;
    }
  }
  FUN_0044a580(auStack_100,&DAT_00a0c970,pcVar3);
  FUN_00797b80(auStack_100);
  return 0;
}


// ==== FUN_00828650 @ 0x00828650 ====

undefined4 FUN_00828650(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  piVar1 = *(int **)(param_1 + 0x20);
  piVar3 = *(int **)(param_1 + 0x24);
  iVar4 = 0;
  do {
    piVar2 = (int *)(**(code **)(*piVar3 + 0x2c))(iVar4);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x60))(0);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x15);
  piVar3 = (int *)(**(code **)(*piVar1 + 0x30))();
  while (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x60))(0);
    piVar3 = (int *)(**(code **)(*piVar1 + 0x34))();
  }
  (**(code **)(**(int **)(param_1 + 0x38) + 0x30))();
  return 1;
}


// ==== FUN_008286b0 @ 0x008286b0 ====

undefined4 FUN_008286b0(int param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  uint *puVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int unaff_retaddr;
  
  piVar1 = *(int **)(param_1 + 0x20);
  piVar3 = (int *)(**(code **)(*piVar1 + 0x54))();
  uVar4 = FUN_00828910(param_1);
  puVar5 = (uint *)(**(code **)(*piVar3 + 4))();
  if (*puVar5 < uVar4) {
    return 0;
  }
  piVar7 = *(int **)(param_1 + 0x24);
  iVar8 = 0;
  do {
    piVar6 = (int *)(**(code **)(*piVar7 + 0x2c))(iVar8);
    if ((piVar6 != (int *)0x0) && (cVar2 = (**(code **)(*piVar6 + 100))(), cVar2 == '\x01')) {
      FUN_0082a800(piVar6);
      (**(code **)(*piVar6 + 0x60))(0);
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 < 0x15);
  piVar7 = (int *)(**(code **)(*piVar1 + 0x30))();
  while (piVar7 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar7 + 100))();
    if (cVar2 == '\x01') {
      FUN_0082a800(piVar7);
      (**(code **)(*piVar7 + 0x60))(0);
    }
    piVar7 = (int *)(**(code **)(*piVar1 + 0x34))();
  }
  (**(code **)(*piVar3 + 0x10))(uVar4);
  (**(code **)(**(int **)(unaff_retaddr + 0x38) + 0x30))();
  return 1;
}


// ==== FUN_00828790 @ 0x00828790 ====

undefined4 FUN_00828790(int param_1)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  uint uVar5;
  uint *puVar6;
  int *piVar7;
  int iVar8;
  undefined1 uStack00000000;
  
  iVar8 = param_1;
  piVar4 = (int *)(**(code **)(**(int **)(param_1 + 0x20) + 0x54))();
  uVar5 = FUN_0082a830(iVar8);
  puVar6 = (uint *)(**(code **)(*piVar4 + 4))();
  if (*puVar6 < uVar5) {
    return 0;
  }
  piVar1 = *(int **)(iVar8 + 0x24);
  piVar2 = *(int **)(iVar8 + 0x38);
  iVar8 = 0;
  do {
    piVar7 = (int *)(**(code **)(*piVar1 + 0x2c))(iVar8);
    if (piVar7 != (int *)0x0) {
      FUN_0082a800(piVar7);
      (**(code **)(*piVar7 + 0x60))(0);
      cVar3 = (**(code **)(*piVar2 + 0x14))(piVar7,&uStack00000000);
      if (cVar3 == '\x01') {
        (**(code **)(*piVar2 + 0x1c))(&param_1);
      }
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 < 0x15);
  (**(code **)(*piVar4 + 0x10))(uVar5);
  return 1;
}


// ==== FUN_00828850 @ 0x00828850 ====

uint FUN_00828850(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  undefined4 unaff_retaddr;
  
  piVar1 = *(int **)(param_1 + 0x20);
  piVar2 = (int *)(**(code **)(*piVar1 + 0x54))();
  iVar3 = FUN_0082a830(param_1);
  iVar4 = FUN_0082a870(param_1);
  puVar5 = (uint *)(**(code **)(*piVar2 + 4))();
  if ((uint)(iVar3 + iVar4) <= *puVar5) {
    piVar7 = *(int **)(param_1 + 0x24);
    iVar8 = 0;
    do {
      piVar6 = (int *)(**(code **)(*piVar7 + 0x2c))(iVar8);
      if (piVar6 != (int *)0x0) {
        FUN_0082a800(piVar6);
        (**(code **)(*piVar6 + 0x60))(0);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < 0x15);
    piVar7 = (int *)(**(code **)(*piVar1 + 0x30))();
    while (piVar7 != (int *)0x0) {
      FUN_0082a800(piVar7);
      (**(code **)(*piVar7 + 0x60))(0);
      piVar7 = (int *)(**(code **)(*piVar1 + 0x34))();
    }
    (**(code **)(*piVar2 + 0x10))(iVar3 + iVar4);
    puVar5 = (uint *)FUN_00828650(unaff_retaddr);
  }
  return (uint)puVar5 & 0xffffff00;
}


// ==== FUN_00828910 @ 0x00828910 ====

int FUN_00828910(int param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  piVar5 = *(int **)(param_1 + 0x24);
  piVar1 = *(int **)(param_1 + 0x20);
  iVar6 = 0;
  param_1 = 0;
  do {
    piVar3 = (int *)(**(code **)(*piVar5 + 0x2c))(iVar6);
    if ((piVar3 != (int *)0x0) && (cVar2 = (**(code **)(*piVar3 + 100))(), cVar2 == '\x01')) {
      iVar4 = FUN_0082a8d0(piVar3);
      param_1 = param_1 + iVar4;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x15);
  piVar5 = (int *)(**(code **)(*piVar1 + 0x30))();
  while (piVar5 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar5 + 100))();
    if (cVar2 == '\x01') {
      iVar6 = FUN_0082a8d0(piVar5);
      param_1 = param_1 + iVar6;
    }
    piVar5 = (int *)(**(code **)(*piVar1 + 0x34))();
  }
  return param_1;
}


// ==== FUN_008289a0 @ 0x008289a0 ====

undefined4 FUN_008289a0(int param_1,undefined2 *param_2)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined2 *puVar8;
  undefined1 local_100 [2];
  undefined1 auStack_fe [234];
  undefined4 uStack_14;
  undefined4 uStack_4;
  
  piVar1 = *(int **)(param_1 + 0x10);
  if (piVar1 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_00a0c9ec,s_this_Creature_has_no_Status_Buff_00a0c978);
    FUN_00797b80(local_100);
    return 0;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5ab90 + 8))(*param_2);
  if (piVar3 == (int *)0x0) {
    uVar4 = FUN_0044a580(local_100 + -4,s_NULL_STATUS_Flyweight_____index___00a0c9ac,*param_2);
    FUN_00797b80(uVar4);
    return 0;
  }
  iVar5 = (**(code **)(*piVar3 + 4))();
  cVar2 = *(char *)(iVar5 + 0x102);
  piVar6 = (int *)(**(code **)(*piVar1 + 0x18))();
  do {
    if (piVar6 == (int *)0x0) {
LAB_00828a81:
      piVar6 = (int *)(**(code **)(*DAT_00b5b01c + 0xc))(1,0);
      piVar7 = (int *)(**(code **)(*piVar6 + 8))();
      (**(code **)(*piVar7 + 8))(uStack_4);
      (**(code **)(*piVar6 + 0x10))(piVar3);
      cVar2 = (**(code **)(*piVar1 + 0x20))(piVar6);
      if (cVar2 == '\0') {
        (**(code **)(*DAT_00b5b01c + 0x10))(1,piVar6);
        return 0;
      }
      FUN_0082a9c0(uStack_14);
      return 1;
    }
    piVar7 = (int *)(**(code **)(*piVar6 + 0xc))();
    iVar5 = (**(code **)(*piVar7 + 4))();
    if (*(char *)(iVar5 + 0x102) == cVar2) {
      piVar6 = (int *)(**(code **)(*piVar6 + 8))();
      puVar8 = (undefined2 *)(**(code **)(*piVar6 + 4))();
      (**(code **)(*piVar1 + 0x24))(*puVar8);
      goto LAB_00828a81;
    }
    piVar6 = (int *)(**(code **)(*piVar1 + 0x1c))();
  } while( true );
}


// ==== FUN_00828b00 @ 0x00828b00 ====

void FUN_00828b00(int param_1,undefined4 param_2)

{
  undefined1 local_100 [256];
  
  if (*(int **)(param_1 + 0x10) == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_00a0ca28,s_this_Creature_has_no_Status_Buff_00a0c9f4);
    FUN_00797b80(local_100);
    return;
  }
  (**(code **)(**(int **)(param_1 + 0x10) + 0x24))(param_2);
  FUN_0082a9c0(param_1);
  return;
}


// ==== FUN_00828b60 @ 0x00828b60 ====

void FUN_00828b60(int param_1,undefined4 param_2)

{
  if (*(int **)(param_1 + 0x14) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x14) + 0x24))(param_2);
  }
  return;
}


// ==== FUN_00828b80 @ 0x00828b80 ====

void FUN_00828b80(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined1 local_100 [256];
  
  if ((param_1[4] != 0) && (param_1[0x14] != 0)) {
    piVar1 = (int *)param_1[4];
    if (piVar1 == (int *)0x0) {
      FUN_0044a580(local_100,&DAT_00a0ca64,s_this_Creature_has_no_Status_Buff_00a0ca30);
      FUN_00797b80(local_100);
      return;
    }
    iVar2 = (**(code **)(*piVar1 + 0x18))();
    if (iVar2 != 0) {
      (**(code **)(*piVar1 + 0x28))();
      FUN_0082a9c0(param_1);
      piVar1 = (int *)param_1[0x14];
      piVar3 = (int *)(**(code **)(*param_1 + 0x10))();
      iVar2 = *piVar1;
      uVar4 = (**(code **)(*piVar3 + 0x38))();
      (**(code **)(iVar2 + 0x14))(uVar4);
    }
  }
  return;
}


// ==== FUN_00828c10 @ 0x00828c10 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00828c10(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  if (*(int **)(param_1 + 0xa4) == (int *)0x0) {
    (**(code **)(_DAT_00000000 + 0x10))(param_2);
    return;
  }
  piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0xa4) + 0x18))();
  (**(code **)(*piVar1 + 0x10))(param_2);
  return;
}


// ==== FUN_00828c40 @ 0x00828c40 ====

undefined4 FUN_00828c40(int param_1)

{
  int *piVar1;
  short *psVar2;
  undefined2 *puVar3;
  int *piVar4;
  int iVar5;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  ushort uVar6;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  int *piVar7;
  
  iVar5 = param_1;
  if (*(int **)(param_1 + 0xc) == (int *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = (int *)(**(code **)(**(int **)(param_1 + 0xc) + 0x28))();
  }
  psVar2 = (short *)(**(code **)(*piVar7 + 0xc))();
  piVar1 = *(int **)(param_1 + 0xc);
  puVar3 = (undefined2 *)(**(code **)(*piVar1 + 0x14))();
  param_1 = CONCAT22(param_1._2_2_,*puVar3);
  if (*(int **)(iVar5 + 4) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(iVar5 + 4) + 0x18))();
  }
  piVar4 = (int *)(**(code **)(*piVar4 + 0x10))();
  iVar5 = (**(code **)(*piVar4 + 4))();
  uVar6 = *(short *)(iVar5 + 100) + *(short *)(iVar5 + 0x60) + *(short *)(iVar5 + 0x5e) +
          *(short *)(iVar5 + 0x62);
  param_1 = CONCAT22((short)((uint)iVar5 >> 0x10),psVar2[3] + psVar2[2] + psVar2[1] + *psVar2) +
            param_1;
  if ((ushort)param_1 < uVar6) {
    return 0;
  }
  (**(code **)(*piVar1 + 0x18))(param_1 - CONCAT22(extraout_var_02,uVar6));
  (**(code **)(*piVar7 + 0x14))(CONCAT22(extraout_var_03,*(undefined2 *)(iVar5 + 0x5e)));
  (**(code **)(*piVar7 + 0x18))(CONCAT22(extraout_var,*(undefined2 *)(iVar5 + 0x60)));
  (**(code **)(*piVar7 + 0x1c))(CONCAT22(extraout_var_00,*(undefined2 *)(iVar5 + 0x62)));
  (**(code **)(*piVar7 + 0x20))(CONCAT22(extraout_var_01,*(undefined2 *)(iVar5 + 100)));
  (**(code **)(*piVar7 + 0x24))();
  return 1;
}


// ==== FUN_00828d10 @ 0x00828d10 ====

undefined4 FUN_00828d10(int param_1,undefined1 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x28) + 0x20))(&param_2);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*piVar1 + 0x58))(0);
  return 1;
}


// ==== FUN_00828d40 @ 0x00828d40 ====

uint FUN_00828d40(int param_1,uint param_2,undefined1 param_3)

{
  int *piVar1;
  char cVar2;
  char extraout_AL;
  undefined3 uVar5;
  undefined3 extraout_var;
  int *piVar3;
  uint uVar4;
  undefined3 extraout_var_00;
  char *pcVar6;
  uint uStack_118;
  int iStack_114;
  undefined4 uStack_110;
  
  piVar1 = *(int **)(param_1 + 0x28);
  uVar5 = (undefined3)((uint)param_1 >> 8);
  if ((char)param_2 == '\0') {
    uStack_110 = &param_3;
    iStack_114 = 0x828d69;
    iStack_114 = (**(code **)(*piVar1 + 0x20))();
    uVar4 = 0;
    if (iStack_114 == 0) {
LAB_00828e72:
      return uVar4 & 0xffffff00;
    }
    uStack_118 = 1;
    (**(code **)(*DAT_00b5a730 + 0x10))();
    uVar5 = extraout_var;
  }
  else if ((char)param_2 == '\x01') {
    uStack_110 = (undefined1 *)0x0;
    iStack_114 = 1;
    uStack_118 = 0x828d9d;
    piVar3 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))();
    uStack_118 = param_2;
    cVar2 = (**(code **)(*piVar3 + 8))();
    if (cVar2 == '\0') {
      pcVar6 = s_ChangeOtherItem___Execute___pIte_00a0ca6c;
    }
    else {
      (**(code **)(*piVar3 + 0x78))(param_2);
      (**(code **)(*piVar3 + 0x84))(param_2);
      uStack_118 = uStack_118 & 0xff000000;
      cVar2 = (**(code **)(*piVar1 + 0x40))(piVar3,&uStack_118);
      if (cVar2 != '\0') {
        (**(code **)(*piVar1 + 0x1c))(&uStack_110,piVar3);
        uVar5 = extraout_var_00;
        if (extraout_AL == '\0') {
          FUN_0044a670(s_SuitItemPick__Execute___pTrade_>_00a0caf8);
          FUN_00797b80(&iStack_114);
          uVar4 = (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar3);
          goto LAB_00828e72;
        }
        goto LAB_00828d7f;
      }
      pcVar6 = s_SuitItemPick__Execute___pTrade_>_00a0caa0;
    }
    FUN_0044a580((int)register0x00000010 + -0x10c,&DAT_00a0cb40,pcVar6);
    FUN_00797b80((int)register0x00000010 + -0x10c);
    uVar4 = (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar3);
    return uVar4 & 0xffffff00;
  }
LAB_00828d7f:
  return CONCAT31(uVar5,1);
}


// ==== FUN_00828ea0 @ 0x00828ea0 ====

void FUN_00828ea0(int *param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int *unaff_EBX;
  int *unaff_EDI;
  int **ppiVar8;
  int **ppiStack_350;
  int *piStack_34c;
  int *piStack_348;
  int *apiStack_334 [6];
  undefined1 auStack_31c [28];
  int *apiStack_300 [63];
  undefined1 auStack_204 [4];
  undefined1 auStack_200 [236];
  undefined1 auStack_114 [16];
  undefined1 auStack_104 [260];
  
  piVar5 = (int *)param_1[10];
  piStack_348 = (int *)0x828ebb;
  piVar2 = (int *)(**(code **)(*piVar5 + 0x28))();
  while (piVar2 != (int *)0x0) {
    piStack_348 = (int *)0x0;
    piStack_34c = (int *)0x828ec9;
    (**(code **)(*piVar2 + 0x58))();
    piStack_34c = (int *)0x828ed0;
    piVar2 = (int *)(**(code **)(*piVar5 + 0x2c))();
  }
  piStack_348 = (int *)0x828edb;
  (**(code **)(*piVar5 + 0x30))();
  piVar5 = (int *)param_1[9];
  apiStack_334[0] = (int *)0x0;
  apiStack_334[1] = piVar5;
  do {
    piVar2 = apiStack_334[0];
    piStack_34c = (int *)0x828ef0;
    piStack_348 = apiStack_334[0];
    piVar3 = (int *)(**(code **)(*piVar5 + 0x2c))();
    if (piVar3 != (int *)0x0) {
      piStack_34c = (int *)0x828f06;
      piStack_348 = piVar3;
      cVar1 = (**(code **)(*DAT_00b5a9ec + 4))();
      if (cVar1 == '\0') {
        piStack_348 = (int *)s_CancelTrade__Execute___ISUIT_ITE_00a0cb4c;
        ppiStack_350 = apiStack_300;
        piStack_34c = (int *)&DAT_00a0ceb0;
        FUN_0044a580();
        FUN_00797b80(apiStack_300);
        piVar5 = DAT_00b5a698;
        piStack_348 = (int *)0x828f3d;
        apiStack_334[2] = (int *)(**(code **)(*param_1 + 0x70))();
        auStack_200[0] = 0;
        piStack_348 = (int *)0x828f50;
        apiStack_334[3] = (int *)(**(code **)(*piVar3 + 0x14))();
        iVar7 = *piVar5;
        piStack_348 = (int *)0x828f5d;
        iVar4 = (**(code **)(*piVar3 + 0x14))();
        piStack_348 = (int *)(uint)*(ushort *)(iVar4 + 0xc);
        piStack_34c = (int *)0x828f69;
        iVar4 = (**(code **)(*piVar3 + 0x14))();
        piStack_34c = (int *)(uint)*(byte *)(iVar4 + 0x1c);
        ppiStack_350 = (int **)0x828f75;
        iVar4 = (**(code **)(*piVar3 + 0x14))();
        ppiStack_350 = (int **)(uint)*(ushort *)(iVar4 + 0x1a);
        iVar4 = (**(code **)(*piVar3 + 0x14))();
        iVar4 = (**(code **)(*piVar3 + 0x14))(*(undefined1 *)(iVar4 + 0x18));
        iVar4 = (**(code **)(*piVar3 + 0x14))(*(undefined2 *)(iVar4 + 0x16));
        iVar4 = (**(code **)(*piVar3 + 0x14))(*(undefined1 *)(iVar4 + 0x14));
        iVar4 = (**(code **)(*piVar3 + 0x14))(*(undefined2 *)(iVar4 + 0x12));
        iVar4 = (**(code **)(*piVar3 + 0x14))(*(undefined1 *)(iVar4 + 0x10));
        iVar4 = (**(code **)(*piVar3 + 0x14))(*(undefined2 *)(iVar4 + 0xe));
        iVar4 = (**(code **)(*piVar3 + 0x14))(*(undefined1 *)(iVar4 + 0x1f));
        iVar4 = (**(code **)(*piVar3 + 0x14))(*(undefined2 *)(iVar4 + 10));
        iVar4 = (**(code **)(*piVar3 + 0x14))(*(undefined2 *)(iVar4 + 8));
        iVar4 = (**(code **)(*piVar3 + 0x14))(*(undefined2 *)(iVar4 + 6));
        iVar4 = (**(code **)(*piVar3 + 0x14))(*(undefined2 *)(iVar4 + 4));
        iVar4 = (**(code **)(*piVar3 + 0x14))((short)*apiStack_334[3],*(undefined1 *)(iVar4 + 0x1e))
        ;
        piStack_348 = (int *)FUN_0044a580(auStack_200,s__________________________________00a0cb78,
                                          apiStack_334[2],*(undefined1 *)(iVar4 + 0x21));
        piStack_34c = (int *)0x82903e;
        (**(code **)(iVar7 + 4))();
        ppiStack_350 = (int **)0x82904c;
        piStack_34c = unaff_EBX;
        (**(code **)(*apiStack_334[0] + 0x20))();
        ppiStack_350 = (int **)0x0;
        piVar5 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))(1);
        puVar6 = (undefined4 *)(**(code **)(*piVar3 + 0x14))();
        ppiVar8 = apiStack_334;
        for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
          *ppiVar8 = (int *)*puVar6;
          puVar6 = puVar6 + 1;
          ppiVar8 = ppiVar8 + 1;
        }
        cVar1 = (**(code **)(*piVar5 + 8))(apiStack_334);
        if (cVar1 == '\0') {
          FUN_0044a580(auStack_114,&DAT_00a0ceb0,&DAT_00a0ccf4);
          (**(code **)(*DAT_00b5a698 + 4))(auStack_114);
        }
        (**(code **)(*unaff_EDI + 0x24))(piStack_348,piVar5);
        piVar2 = apiStack_334[0];
        piVar5 = apiStack_334[1];
      }
    }
    apiStack_334[0] = (int *)((int)piVar2 + 1);
  } while ((int)apiStack_334[0] < 0x15);
  piVar5 = (int *)param_1[8];
  piStack_348 = (int *)0x8290e3;
  apiStack_334[1] = piVar5;
  piVar2 = (int *)(**(code **)(*piVar5 + 0x30))();
  while (piVar2 != (int *)0x0) {
    piStack_34c = (int *)0x8290fc;
    piStack_348 = piVar2;
    cVar1 = (**(code **)(*DAT_00b5a9ec + 4))();
    if (cVar1 == '\0') {
      piStack_34c = (int *)s_CancelTrade__Execute___IBAG_ITEM_00a0cd00;
      ppiStack_350 = (int **)&DAT_00a0ceb0;
      FUN_0044a580(auStack_104);
      FUN_00797b80(auStack_104);
      piVar5 = DAT_00b5a698;
      piStack_34c = (int *)0x829139;
      apiStack_334[2] = (int *)(**(code **)(*param_1 + 0x70))();
      auStack_204[0] = 0;
      piStack_34c = (int *)0x82914c;
      apiStack_334[1] = (int *)(**(code **)(*piVar2 + 0x14))();
      iVar7 = *piVar5;
      piStack_34c = (int *)0x829159;
      iVar4 = (**(code **)(*piVar2 + 0x14))();
      piStack_34c = (int *)(uint)*(ushort *)(iVar4 + 0xc);
      ppiStack_350 = (int **)0x829165;
      iVar4 = (**(code **)(*piVar2 + 0x14))();
      ppiStack_350 = (int **)(uint)*(byte *)(iVar4 + 0x1c);
      iVar4 = (**(code **)(*piVar2 + 0x14))();
      iVar4 = (**(code **)(*piVar2 + 0x14))(*(undefined2 *)(iVar4 + 0x1a));
      iVar4 = (**(code **)(*piVar2 + 0x14))(*(undefined1 *)(iVar4 + 0x18));
      iVar4 = (**(code **)(*piVar2 + 0x14))(*(undefined2 *)(iVar4 + 0x16));
      iVar4 = (**(code **)(*piVar2 + 0x14))(*(undefined1 *)(iVar4 + 0x14));
      iVar4 = (**(code **)(*piVar2 + 0x14))(*(undefined2 *)(iVar4 + 0x12));
      iVar4 = (**(code **)(*piVar2 + 0x14))(*(undefined1 *)(iVar4 + 0x10));
      iVar4 = (**(code **)(*piVar2 + 0x14))(*(undefined2 *)(iVar4 + 0xe));
      iVar4 = (**(code **)(*piVar2 + 0x14))(*(undefined1 *)(iVar4 + 0x1f));
      iVar4 = (**(code **)(*piVar2 + 0x14))(*(undefined2 *)(iVar4 + 10));
      iVar4 = (**(code **)(*piVar2 + 0x14))(*(undefined2 *)(iVar4 + 8));
      iVar4 = (**(code **)(*piVar2 + 0x14))(*(undefined2 *)(iVar4 + 6));
      iVar4 = (**(code **)(*piVar2 + 0x14))(*(undefined2 *)(iVar4 + 4));
      iVar4 = (**(code **)(*piVar2 + 0x14))((short)*apiStack_334[1],*(undefined1 *)(iVar4 + 0x1e));
      piStack_34c = (int *)FUN_0044a580(auStack_204,s__________________________________00a0cd28,
                                        apiStack_334[2],*(undefined1 *)(iVar4 + 0x21));
      ppiStack_350 = (int **)0x82923a;
      (**(code **)(iVar7 + 4))();
      ppiStack_350 = apiStack_334 + -2;
      (**(code **)(*unaff_EBX + 0x18))(piVar2);
      piVar5 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))(1,0);
      puVar6 = (undefined4 *)(**(code **)(*piVar2 + 0x14))();
      ppiVar8 = apiStack_334 + -2;
      for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
        *ppiVar8 = (int *)*puVar6;
        puVar6 = puVar6 + 1;
        ppiVar8 = ppiVar8 + 1;
      }
      cVar1 = (**(code **)(*piVar5 + 8))(apiStack_334 + -2);
      if (cVar1 == '\0') {
        FUN_0044a580(auStack_31c,&DAT_00a0ceb0,&DAT_00a0cea4);
        (**(code **)(*DAT_00b5a698 + 4))(auStack_31c);
      }
      (**(code **)(*piStack_34c + 0x1c))(&ppiStack_350,piVar5);
      piVar5 = apiStack_334[0];
    }
    piStack_34c = (int *)0x8292ce;
    piVar2 = (int *)(**(code **)(*piVar5 + 0x34))();
  }
  return;
}


// ==== FUN_00829310 @ 0x00829310 ====

void FUN_00829310(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  int *unaff_EBX;
  int *unaff_EDI;
  int **ppiVar8;
  int **ppiStack_350;
  int *piStack_34c;
  int *piStack_348;
  int *apiStack_334 [6];
  undefined1 auStack_31c [28];
  int *apiStack_300 [63];
  undefined1 auStack_204 [4];
  undefined1 auStack_200 [236];
  undefined1 auStack_114 [16];
  undefined1 auStack_104 [260];
  
  piStack_348 = (int *)0x829329;
  (**(code **)(*(int *)param_1[10] + 0x30))();
  piVar4 = (int *)param_1[9];
  apiStack_334[0] = (int *)0x0;
  apiStack_334[1] = piVar4;
  do {
    piVar6 = apiStack_334[0];
    piStack_34c = (int *)0x82933e;
    piStack_348 = apiStack_334[0];
    piVar2 = (int *)(**(code **)(*piVar4 + 0x2c))();
    if (piVar2 != (int *)0x0) {
      piStack_34c = (int *)0x829354;
      piStack_348 = piVar2;
      cVar1 = (**(code **)(*DAT_00b5a9ec + 4))();
      if (cVar1 == '\0') {
        piStack_348 = (int *)s_EndTrade__Execute___ISUIT_ITEM_C_00a0cebc;
        ppiStack_350 = apiStack_300;
        piStack_34c = (int *)&DAT_00a0d21c;
        FUN_0044a580();
        FUN_00797b80(apiStack_300);
        piVar4 = DAT_00b5a698;
        piStack_348 = (int *)0x82938b;
        apiStack_334[2] = (int *)(**(code **)(*param_1 + 0x70))();
        auStack_200[0] = 0;
        piStack_348 = (int *)0x82939e;
        apiStack_334[3] = (int *)(**(code **)(*piVar2 + 0x14))();
        iVar7 = *piVar4;
        piStack_348 = (int *)0x8293ab;
        iVar3 = (**(code **)(*piVar2 + 0x14))();
        piStack_348 = (int *)(uint)*(ushort *)(iVar3 + 0xc);
        piStack_34c = (int *)0x8293b7;
        iVar3 = (**(code **)(*piVar2 + 0x14))();
        piStack_34c = (int *)(uint)*(byte *)(iVar3 + 0x1c);
        ppiStack_350 = (int **)0x8293c3;
        iVar3 = (**(code **)(*piVar2 + 0x14))();
        ppiStack_350 = (int **)(uint)*(ushort *)(iVar3 + 0x1a);
        iVar3 = (**(code **)(*piVar2 + 0x14))();
        iVar3 = (**(code **)(*piVar2 + 0x14))(*(undefined1 *)(iVar3 + 0x18));
        iVar3 = (**(code **)(*piVar2 + 0x14))(*(undefined2 *)(iVar3 + 0x16));
        iVar3 = (**(code **)(*piVar2 + 0x14))(*(undefined1 *)(iVar3 + 0x14));
        iVar3 = (**(code **)(*piVar2 + 0x14))(*(undefined2 *)(iVar3 + 0x12));
        iVar3 = (**(code **)(*piVar2 + 0x14))(*(undefined1 *)(iVar3 + 0x10));
        iVar3 = (**(code **)(*piVar2 + 0x14))(*(undefined2 *)(iVar3 + 0xe));
        iVar3 = (**(code **)(*piVar2 + 0x14))(*(undefined1 *)(iVar3 + 0x1f));
        iVar3 = (**(code **)(*piVar2 + 0x14))(*(undefined2 *)(iVar3 + 10));
        iVar3 = (**(code **)(*piVar2 + 0x14))(*(undefined2 *)(iVar3 + 8));
        iVar3 = (**(code **)(*piVar2 + 0x14))(*(undefined2 *)(iVar3 + 6));
        iVar3 = (**(code **)(*piVar2 + 0x14))(*(undefined2 *)(iVar3 + 4));
        iVar3 = (**(code **)(*piVar2 + 0x14))((short)*apiStack_334[3],*(undefined1 *)(iVar3 + 0x1e))
        ;
        piStack_348 = (int *)FUN_0044a580(auStack_200,s__________________________________00a0cee8,
                                          apiStack_334[2],*(undefined1 *)(iVar3 + 0x21));
        piStack_34c = (int *)0x82948c;
        (**(code **)(iVar7 + 4))();
        ppiStack_350 = (int **)0x82949a;
        piStack_34c = unaff_EBX;
        (**(code **)(*apiStack_334[0] + 0x20))();
        ppiStack_350 = (int **)0x0;
        piVar4 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))(1);
        puVar5 = (undefined4 *)(**(code **)(*piVar2 + 0x14))();
        ppiVar8 = apiStack_334;
        for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
          *ppiVar8 = (int *)*puVar5;
          puVar5 = puVar5 + 1;
          ppiVar8 = ppiVar8 + 1;
        }
        cVar1 = (**(code **)(*piVar4 + 8))(apiStack_334);
        if (cVar1 == '\0') {
          FUN_0044a580(auStack_114,&DAT_00a0d21c,&DAT_00a0d060);
          (**(code **)(*DAT_00b5a698 + 4))(auStack_114);
        }
        (**(code **)(*unaff_EDI + 0x24))(piStack_348,piVar4);
        piVar6 = apiStack_334[0];
        piVar4 = apiStack_334[1];
      }
    }
    apiStack_334[0] = (int *)((int)piVar6 + 1);
  } while ((int)apiStack_334[0] < 0x15);
  piVar4 = (int *)param_1[8];
  piStack_348 = (int *)0x829531;
  apiStack_334[1] = piVar4;
  piVar6 = (int *)(**(code **)(*piVar4 + 0x30))();
  while (piVar6 != (int *)0x0) {
    piStack_34c = (int *)0x82954c;
    piStack_348 = piVar6;
    cVar1 = (**(code **)(*DAT_00b5a9ec + 4))();
    if (cVar1 == '\0') {
      piStack_34c = (int *)s_EndTrade__Execute___ISUIT_ITEM_C_00a0d06c;
      ppiStack_350 = (int **)&DAT_00a0d21c;
      FUN_0044a580(auStack_104);
      FUN_00797b80(auStack_104);
      piVar4 = DAT_00b5a698;
      piStack_34c = (int *)0x829589;
      apiStack_334[2] = (int *)(**(code **)(*param_1 + 0x70))();
      auStack_204[0] = 0;
      piStack_34c = (int *)0x82959c;
      apiStack_334[1] = (int *)(**(code **)(*piVar6 + 0x14))();
      iVar7 = *piVar4;
      piStack_34c = (int *)0x8295a9;
      iVar3 = (**(code **)(*piVar6 + 0x14))();
      piStack_34c = (int *)(uint)*(ushort *)(iVar3 + 0xc);
      ppiStack_350 = (int **)0x8295b5;
      iVar3 = (**(code **)(*piVar6 + 0x14))();
      ppiStack_350 = (int **)(uint)*(byte *)(iVar3 + 0x1c);
      iVar3 = (**(code **)(*piVar6 + 0x14))();
      iVar3 = (**(code **)(*piVar6 + 0x14))(*(undefined2 *)(iVar3 + 0x1a));
      iVar3 = (**(code **)(*piVar6 + 0x14))(*(undefined1 *)(iVar3 + 0x18));
      iVar3 = (**(code **)(*piVar6 + 0x14))(*(undefined2 *)(iVar3 + 0x16));
      iVar3 = (**(code **)(*piVar6 + 0x14))(*(undefined1 *)(iVar3 + 0x14));
      iVar3 = (**(code **)(*piVar6 + 0x14))(*(undefined2 *)(iVar3 + 0x12));
      iVar3 = (**(code **)(*piVar6 + 0x14))(*(undefined1 *)(iVar3 + 0x10));
      iVar3 = (**(code **)(*piVar6 + 0x14))(*(undefined2 *)(iVar3 + 0xe));
      iVar3 = (**(code **)(*piVar6 + 0x14))(*(undefined1 *)(iVar3 + 0x1f));
      iVar3 = (**(code **)(*piVar6 + 0x14))(*(undefined2 *)(iVar3 + 10));
      iVar3 = (**(code **)(*piVar6 + 0x14))(*(undefined2 *)(iVar3 + 8));
      iVar3 = (**(code **)(*piVar6 + 0x14))(*(undefined2 *)(iVar3 + 6));
      iVar3 = (**(code **)(*piVar6 + 0x14))(*(undefined2 *)(iVar3 + 4));
      iVar3 = (**(code **)(*piVar6 + 0x14))((short)*apiStack_334[1],*(undefined1 *)(iVar3 + 0x1e));
      piStack_34c = (int *)FUN_0044a580(auStack_204,s__________________________________00a0d098,
                                        apiStack_334[2],*(undefined1 *)(iVar3 + 0x21));
      ppiStack_350 = (int **)0x82968a;
      (**(code **)(iVar7 + 4))();
      ppiStack_350 = apiStack_334 + -2;
      (**(code **)(*unaff_EBX + 0x18))(piVar6);
      piVar4 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))(1,0);
      puVar5 = (undefined4 *)(**(code **)(*piVar6 + 0x14))();
      ppiVar8 = apiStack_334 + -2;
      for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
        *ppiVar8 = (int *)*puVar5;
        puVar5 = puVar5 + 1;
        ppiVar8 = ppiVar8 + 1;
      }
      cVar1 = (**(code **)(*piVar4 + 8))(apiStack_334 + -2);
      if (cVar1 == '\0') {
        FUN_0044a580(auStack_31c,&DAT_00a0d21c,&DAT_00a0d210);
        (**(code **)(*DAT_00b5a698 + 4))(auStack_31c);
      }
      (**(code **)(*piStack_34c + 0x1c))(&ppiStack_350,piVar4);
      piVar4 = apiStack_334[0];
    }
    piStack_34c = (int *)0x82971e;
    piVar6 = (int *)(**(code **)(*piVar4 + 0x34))();
  }
  return;
}


// ==== FUN_00829740 @ 0x00829740 ====

undefined4 FUN_00829740(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  
  piVar5 = (int *)(**(code **)(*param_2 + 0x34))();
  piVar9 = *(int **)(param_1 + 0x24);
  piVar1 = *(int **)(param_1 + 0x20);
  piVar6 = (int *)(**(code **)(**(int **)(param_1 + 0x28) + 0x34))();
  piVar7 = (int *)(**(code **)(*piVar1 + 0x54))();
  piVar8 = (int *)(**(code **)(*param_2 + 0x28))();
  do {
    if (piVar8 == (int *)0x0) {
      piVar9 = (int *)(**(code **)(*piVar7 + 4))();
      iVar2 = *piVar9;
      piVar9 = (int *)(**(code **)(*piVar6 + 4))();
      iVar3 = *piVar9;
      piVar9 = (int *)(**(code **)(*piVar5 + 4))();
      (**(code **)(*piVar7 + 8))((iVar2 - iVar3) + *piVar9);
      return 1;
    }
    cVar4 = (**(code **)(*piVar9 + 0x34))(piVar8);
    if (cVar4 == '\x01') {
      (**(code **)(*piVar6 + 0x38))();
    }
    else {
      cVar4 = (**(code **)(*piVar1 + 0x3c))(piVar8);
      if (cVar4 != '\x01') {
        return 0;
      }
      (**(code **)(*piVar1 + 0x40))(piVar8);
    }
    (**(code **)(*piVar8 + 0x58))(0);
    piVar8 = (int *)(**(code **)(*param_2 + 0x2c))();
  } while( true );
}


// ==== FUN_00829810 @ 0x00829810 ====

short FUN_00829810(uint param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  short sVar4;
  int iVar5;
  undefined1 auStackY_9c [128];
  
  piVar1 = *(int **)(param_1 + 0x24);
  sVar4 = 0;
  iVar5 = 0;
  do {
    piVar3 = (int *)(**(code **)(*piVar1 + 0x2c))(iVar5);
    if ((piVar3 != (int *)0x0) && (cVar2 = (**(code **)(*piVar3 + 0x5c))(), cVar2 == '\x01')) {
      (**(code **)(*piVar1 + 0x20))(iVar5);
      sVar4 = sVar4 + 1;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x15);
  piVar1 = *(int **)(param_1 + 0x20);
  piVar3 = (int *)(**(code **)(*piVar1 + 0x30))();
  while (piVar3 != (int *)0x0) {
    param_1 = param_1 & 0xff000000;
    (**(code **)(*piVar1 + 0x18))(piVar3,&param_1);
    cVar2 = (**(code **)(*piVar3 + 0x5c))();
    if (cVar2 == '\x01') {
      (**(code **)(*piVar1 + 0x20))(auStackY_9c + 0x98);
      sVar4 = sVar4 + 1;
    }
    piVar3 = (int *)(**(code **)(*piVar1 + 0x34))();
  }
  return sVar4;
}


// ==== FUN_008298b0 @ 0x008298b0 ====

void FUN_008298b0(int *param_1)

{
  int *piVar1;
  undefined2 *puVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = param_1;
  if ((int *)param_1[0x12] == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(*(int *)param_1[0x12] + 0x28))();
  }
  puVar2 = (undefined2 *)(**(code **)(*piVar1 + 8))();
  piVar1 = (int *)param_1[0x10];
  param_1 = (int *)CONCAT22(param_1._2_2_,*puVar2);
  piVar3 = (int *)(**(code **)(*piVar1 + 0x20))();
  piVar4 = (int *)(**(code **)(*piVar1 + 0x1c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x24))();
  (**(code **)(*piVar3 + 4))();
  (**(code **)(*piVar4 + 4))();
  (**(code **)(*piVar1 + 4))((int)param_1 + -1);
  (**(code **)(*piVar1 + 0x1c))();
  piVar5 = (int *)(**(code **)(*piVar5 + 0x10))();
                    /* WARNING: Could not recover jumptable at 0x00829929. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar5 + 0x14))();
  return;
}


// ==== FUN_00829930 @ 0x00829930 ====

void FUN_00829930(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x20) + 0x54))();
  (**(code **)(*piVar1 + 8))(param_2);
  return;
}


// ==== FUN_00829990 @ 0x00829990 ====

undefined4 FUN_00829990(int param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  
  piVar1 = *(int **)(param_1 + 0x20);
  piVar2 = *(int **)(param_1 + 0x24);
  cVar3 = (**(code **)(*piVar2 + 0x34))(param_2);
  if (cVar3 == '\x01') {
    (**(code **)(*piVar2 + 0x38))();
    return 1;
  }
  cVar3 = (**(code **)(*piVar1 + 0x58))(param_2);
  if (cVar3 == '\x01') {
    (**(code **)(*piVar1 + 0x5c))();
    return 1;
  }
  cVar3 = (**(code **)(*piVar1 + 0x3c))(param_2);
  if (cVar3 == '\x01') {
    (**(code **)(*piVar1 + 0x40))(param_2);
    return 1;
  }
  return 0;
}


// ==== FUN_00829a00 @ 0x00829a00 ====

undefined4 FUN_00829a00(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x1c);
  iVar2 = (**(code **)(*piVar1 + 0x1c))();
  if (iVar2 == 0) {
    (**(code **)(*piVar1 + 0x14))(param_2);
    return 1;
  }
  return 0;
}


// ==== FUN_00829a60 @ 0x00829a60 ====

undefined4 FUN_00829a60(int param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = (int *)(**(code **)(**(int **)(param_1 + 0x20) + 0x54))();
  piVar3 = (int *)(**(code **)(*piVar2 + 4))();
  if ((uint)(*piVar3 + param_2) < 0x3b9aca01) {
    cVar1 = (**(code **)(*piVar2 + 0x14))(param_2);
    if (cVar1 != '\0') {
      (**(code **)(*piVar2 + 0xc))(param_2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00829ac0 @ 0x00829ac0 ====

uint FUN_00829ac0(int *param_1)

{
  byte bVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined2 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uStack_10c;
  uint auStack_108 [66];
  
  piVar3 = (int *)(**(code **)(*DAT_00b5aa2c + 8))();
  if (piVar3 == (int *)0x0) {
    return 1;
  }
  (**(code **)(*piVar3 + 4))();
  iVar4 = (**(code **)(*param_1 + 0x14))();
  bVar1 = *(byte *)(iVar4 + 0x1e);
  piVar5 = (int *)(**(code **)(*param_1 + 0x48))();
  iVar4 = (**(code **)(*piVar5 + 4))();
  if (*(int *)(iVar4 + 4) == 3) {
    uStack_10c = 5;
  }
  else {
    iVar4 = (**(code **)(*param_1 + 0x14))();
    uStack_10c = (uint)*(byte *)(iVar4 + 0x1f);
  }
  auStack_108[0] = (uint)bVar1;
  piVar5 = (int *)(**(code **)(*DAT_00b5ab24 + 8))(&uStack_10c);
  if (piVar5 == (int *)0x0) {
    return 1;
  }
  piVar5 = (int *)(**(code **)(*piVar5 + 4))();
  iVar4 = (**(code **)(*param_1 + 0x2c))();
  uVar9 = *(uint *)(iVar4 + 0x2c);
  iVar4 = (**(code **)(*param_1 + 0x2c))();
  uVar2 = *(ushort *)(iVar4 + 0x72);
  if (uVar2 != 0) {
    iVar4 = (**(code **)(*param_1 + 0x14))();
    if (*(ushort *)(iVar4 + 0xc) == 0) {
      auStack_108[0] = auStack_108[0] & 0xffffff00;
      puVar6 = (undefined2 *)(**(code **)(*param_1 + 0x14))();
      uVar7 = FUN_0044a580(auStack_108,s___ASSERT___wStackCount_is_0_for_s_00a0d228,*puVar6);
      FUN_00797b80(uVar7);
    }
    else {
      uVar9 = (*(ushort *)(iVar4 + 0xc) * uVar9) / (uint)uVar2;
    }
  }
  uVar9 = (((((uint)param_1 & 0xffff) * uVar9) / 10) * *piVar5) / 100;
  iVar4 = (**(code **)(*piVar3 + 4))();
  uVar8 = (uint)(*(int *)(iVar4 + 4) * *piVar5) / 100;
  if (uVar8 < uVar9) {
    uVar9 = uVar8;
  }
  return uVar9;
}


// ==== FUN_00829c20 @ 0x00829c20 ====

uint FUN_00829c20(uint param_1,int *param_2)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined1 auStack_fe [254];
  
  piVar3 = (int *)(**(code **)(*DAT_00b5aa2c + 8))(param_1);
  iVar4 = (**(code **)(*piVar3 + 4))();
  uVar1 = *(ushort *)((param_1 & 0xff) * 0x60 + 0x26 + iVar4);
  iVar4 = (**(code **)(*param_2 + 0x2c))();
  uVar7 = *(uint *)(iVar4 + 0x2c);
  iVar4 = (**(code **)(*param_2 + 0x2c))();
  uVar2 = *(ushort *)(iVar4 + 0x72);
  if (uVar2 != 0) {
    iVar4 = (**(code **)(*param_2 + 0x14))();
    if (*(ushort *)(iVar4 + 0xc) == 0) {
      puVar5 = (undefined2 *)(**(code **)(*param_2 + 0x14))();
      uVar6 = FUN_0044a580(auStack_fe + -6,s___ASSERT___wStackCount_is_0_for_s_00a0d278,*puVar5);
      FUN_00797b80(uVar6);
    }
    else {
      uVar7 = (*(ushort *)(iVar4 + 0xc) * uVar7) / (uint)uVar2;
    }
  }
  return (uVar1 * uVar7) / 10;
}


// ==== FUN_00829ce0 @ 0x00829ce0 ====

undefined4 FUN_00829ce0(int param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x2c);
  piVar2 = (int *)(**(code **)(**(int **)(param_1 + 0x20) + 0x54))();
  piVar3 = (int *)(**(code **)(*piVar3 + 0x3c))();
  cVar1 = (**(code **)(*piVar3 + 0x18))(param_2);
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*piVar2 + 0x14))(param_2);
    if (cVar1 != '\0') {
      (**(code **)(*piVar3 + 0x10))(param_2);
      (**(code **)(*piVar2 + 0xc))(param_2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00829d40 @ 0x00829d40 ====

undefined4 FUN_00829d40(int param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x2c);
  piVar2 = (int *)(**(code **)(**(int **)(param_1 + 0x20) + 0x54))();
  piVar3 = (int *)(**(code **)(*piVar3 + 0x3c))();
  cVar1 = (**(code **)(*piVar2 + 0x18))(param_2);
  if (cVar1 == '\0') {
    return 1;
  }
  cVar1 = (**(code **)(*piVar3 + 0x14))(param_2);
  if (cVar1 == '\0') {
    return 2;
  }
  (**(code **)(*piVar2 + 0x10))(param_2);
  (**(code **)(*piVar3 + 0xc))(param_2);
  return 0;
}


// ==== FUN_00829da0 @ 0x00829da0 ====

undefined4 FUN_00829da0(int param_1,undefined1 param_2)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  undefined1 uStack00000000;
  undefined1 auStackY_a0 [128];
  
  piVar1 = *(int **)(param_1 + 0x28);
  piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x20) + 0x28))(&param_2);
  if (piVar3 != (int *)0x0) {
    piVar4 = (int *)(**(code **)(*piVar3 + 0x48))();
    cVar2 = (**(code **)(*piVar4 + 0x10))();
    if (cVar2 != '\0') {
      cVar2 = (**(code **)(*piVar3 + 0x5c))();
      if (cVar2 != '\x01') {
        cVar2 = (**(code **)(*piVar1 + 0x40))(piVar3,&uStack00000000);
        if (cVar2 != '\0') {
          cVar2 = (**(code **)(*piVar1 + 0x1c))(auStackY_a0 + 0x98,piVar3);
          if (cVar2 != '\0') {
            (**(code **)(*piVar3 + 0x58))(1);
            return 1;
          }
        }
      }
    }
  }
  return 0;
}


// ==== FUN_00829e20 @ 0x00829e20 ====

undefined4 FUN_00829e20(uint param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  undefined1 auStackY_a0 [128];
  
  if ((((param_2 == 0xd) || (param_2 == 0xe)) || (param_2 == 0xf)) ||
     ((param_2 == 0x10 || (param_2 == 0x11)))) {
    return 0;
  }
  piVar1 = *(int **)(param_1 + 0x28);
  piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x24) + 0x2c))(param_2);
  if (piVar3 != (int *)0x0) {
    piVar4 = (int *)(**(code **)(*piVar3 + 0x48))();
    cVar2 = (**(code **)(*piVar4 + 0x10))();
    if (cVar2 != '\0') {
      cVar2 = (**(code **)(*piVar3 + 0x5c))();
      if (cVar2 != '\x01') {
        param_1 = param_1 & 0xff000000;
        cVar2 = (**(code **)(*piVar1 + 0x40))(piVar3,&param_1);
        if (cVar2 != '\0') {
          cVar2 = (**(code **)(*piVar1 + 0x1c))(auStackY_a0 + 0x9c,piVar3);
          if (cVar2 != '\0') {
            (**(code **)(*piVar3 + 0x58))(1);
            return 1;
          }
        }
      }
    }
  }
  return 0;
}


// ==== FUN_00829ed0 @ 0x00829ed0 ====

undefined4 FUN_00829ed0(uint param_1,short param_2,uint param_3)

{
  int *piVar1;
  int *piVar2;
  short *psVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 auStackY_224 [128];
  
  uVar5 = param_3;
  piVar1 = *(int **)(param_1 + 0x20);
  piVar2 = (int *)(**(code **)(*piVar1 + 0x30))();
  while( true ) {
    while( true ) {
      if (piVar2 == (int *)0x0) {
        return 0;
      }
      psVar3 = (short *)(**(code **)(*piVar2 + 0x14))();
      if (*psVar3 == param_2) break;
      piVar2 = (int *)(**(code **)(*piVar1 + 0x34))();
    }
    if (*(char *)((int)psVar3 + 0x21) == '\0') {
      uVar5 = uVar5 - 1;
      param_3 = param_3 & 0xff000000;
      (**(code **)(*piVar1 + 0x18))(piVar2,&param_3);
      puVar4 = &param_1;
    }
    else {
      if (uVar5 < (ushort)psVar3[6]) {
        (**(code **)(*piVar2 + 0x20))(psVar3[6] - (short)uVar5);
        return 1;
      }
      uVar5 = uVar5 - (ushort)psVar3[6];
      param_1 = param_1 & 0xff000000;
      (**(code **)(*piVar1 + 0x18))(piVar2,&param_1);
      puVar4 = auStackY_224 + 0x88;
    }
    (**(code **)(*piVar1 + 0x20))(puVar4);
    (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar2);
    if (uVar5 == 0) break;
    piVar2 = (int *)(**(code **)(*piVar1 + 0x34))();
  }
  return 1;
}


// ==== FUN_00829fb0 @ 0x00829fb0 ====

undefined4 FUN_00829fb0(uint param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  
  piVar1 = *(int **)(param_1 + 0x20);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  param_1 = param_1 & 0xff000000;
  piVar4 = (int *)(**(code **)(*piVar1 + 0x30))();
  iVar2 = param_2;
  while( true ) {
    if (piVar4 == (int *)0x0) {
      return 0;
    }
    iVar5 = (**(code **)(*piVar4 + 0x2c))();
    if ((*(int *)(iVar5 + 8) == iVar2) &&
       (cVar3 = (**(code **)(*piVar1 + 0x18))(piVar4,&param_1), cVar3 == '\x01')) break;
    piVar4 = (int *)(**(code **)(*piVar1 + 0x34))();
  }
  uVar6 = (**(code **)(*piVar1 + 0x20))(&param_1);
  return uVar6;
}


// ==== FUN_0082a030 @ 0x0082a030 ====

undefined4 FUN_0082a030(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 unaff_EBP;
  undefined4 uVar7;
  
  piVar1 = *(int **)(param_1 + 0x24);
  uVar7 = 4;
  piVar2 = (int *)(**(code **)(*piVar1 + 0x2c))(4);
  piVar3 = (int *)(**(code **)(*piVar1 + 0x2c))(5);
  if ((piVar2 == (int *)0x0) || (piVar3 == (int *)0x0)) {
    return 0;
  }
  iVar4 = (**(code **)(*piVar2 + 0x2c))();
  iVar4 = *(int *)(iVar4 + 8);
  iVar5 = (**(code **)(*piVar3 + 0x2c))();
  iVar5 = *(int *)(iVar5 + 8);
  if (iVar4 == 0x40f) {
    if (iVar5 != 0x40a) {
      return 0;
    }
  }
  else {
    if (iVar4 != 0x410) {
      if (iVar4 == 0x40a) {
        if (iVar5 != 0x40f) {
          return 0;
        }
      }
      else {
        if (iVar4 != 0x40b) {
          return 0;
        }
        if (iVar5 != 0x410) {
          return 0;
        }
      }
      iVar4 = (**(code **)(*piVar3 + 0x14))();
      if (*(short *)(iVar4 + 0xc) == 0) {
        return 0;
      }
      iVar4 = *piVar3;
      iVar5 = (**(code **)(iVar4 + 0x14))();
      (**(code **)(iVar4 + 0x20))(*(short *)(iVar5 + 0xc) + -1);
      iVar4 = (**(code **)(*piVar3 + 0x14))();
      if (*(short *)(iVar4 + 0xc) != 0) {
        return 1;
      }
      (**(code **)(*piVar1 + 0x20))(5);
      (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar3);
      iVar4 = FUN_00829fb0(uVar7,unaff_EBP);
      if (iVar4 == 0) {
        return 1;
      }
      (**(code **)(*piVar1 + 0x24))(5,iVar4);
      return 1;
    }
    if (iVar5 != 0x40b) {
      return 0;
    }
  }
  iVar5 = (**(code **)(*piVar2 + 0x14))();
  if (*(short *)(iVar5 + 0xc) == 0) {
    return 0;
  }
  iVar5 = *piVar2;
  iVar6 = (**(code **)(iVar5 + 0x14))();
  (**(code **)(iVar5 + 0x20))(*(short *)(iVar6 + 0xc) + -1);
  iVar5 = (**(code **)(*piVar2 + 0x14))();
  if (*(short *)(iVar5 + 0xc) == 0) {
    (**(code **)(*piVar1 + 0x20))(4);
    (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar2);
    iVar4 = FUN_00829fb0(uVar7,iVar4);
    if (iVar4 != 0) {
      (**(code **)(*piVar1 + 0x24))(4,iVar4);
    }
  }
  return 1;
}


// ==== FUN_0082a1d0 @ 0x0082a1d0 ====

void FUN_0082a1d0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[0x1e];
  (**(code **)(*piVar1 + 0x20))(0);
  FUN_00636fd0();
  (**(code **)(*piVar1 + 0x20))(1);
  FUN_00636fd0();
  (**(code **)(*piVar1 + 0x20))(2);
  FUN_00636fd0();
  (**(code **)(*piVar1 + 0x20))(3);
  FUN_00636fd0();
  piVar1 = (int *)(**(code **)(*param_1 + 0x10))();
                    /* WARNING: Could not recover jumptable at 0x0082a226. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x14))();
  return;
}


// ==== FUN_0082a230 @ 0x0082a230 ====

void FUN_0082a230(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  
  if ((int *)param_1[0x13] == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(*(int *)param_1[0x13] + 0x18))();
  }
  (**(code **)(*piVar4 + 8))(0);
  iVar1 = (**(code **)(*piVar4 + 0x10))();
  if (*(char *)(iVar1 + 0xb) != '\x01') {
    (**(code **)(*piVar4 + 8))(0);
    iVar1 = (**(code **)(*piVar4 + 0x10))();
    if (*(char *)(iVar1 + 0xb) != '\x02') {
      return;
    }
  }
  piVar4 = (int *)param_1[0x10];
  uVar2 = (**(code **)(*DAT_00b5acd0 + 4))(0);
  piVar3 = (int *)(**(code **)(*piVar4 + 0x20))();
  piVar4 = (int *)(**(code **)(*piVar3 + 0x20))();
  while (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 0x24))(uVar2,0);
    piVar4 = (int *)(**(code **)(*piVar3 + 0x24))();
  }
  piVar4 = (int *)(**(code **)(*param_1 + 0x10))();
                    /* WARNING: Could not recover jumptable at 0x0082a2c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar4 + 0x14))();
  return;
}


// ==== FUN_0082a2d0 @ 0x0082a2d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0082a2d0(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  
  if (*(int **)(param_1 + 0xa4) == (int *)0x0) {
    puVar1 = (undefined4 *)(**(code **)(_DAT_00000000 + 0xc))();
    return *puVar1;
  }
  piVar2 = (int *)(**(code **)(**(int **)(param_1 + 0xa4) + 0x18))();
  puVar1 = (undefined4 *)(**(code **)(*piVar2 + 0xc))();
  return *puVar1;
}


// ==== FUN_0082a300 @ 0x0082a300 ====

undefined4 FUN_0082a300(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x60) + 0x14))();
  iVar2 = (**(code **)(*piVar1 + 0xc))(param_2);
  if (iVar2 == 0) {
    return 0;
  }
  (**(code **)(*piVar1 + 8))(iVar2);
  return 1;
}


// ==== FUN_0082a330 @ 0x0082a330 ====

int * FUN_0082a330(int param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar2 = (int *)(**(code **)(**(int **)(param_1 + 0x60) + 0x14))();
  iVar3 = (**(code **)(*piVar2 + 0xc))(param_2);
  if (iVar3 != 0) {
    return (int *)0x0;
  }
  piVar4 = (int *)(**(code **)(*DAT_00b5abe0 + 0xc))(1,0);
  cVar1 = (**(code **)(*piVar4 + 8))(param_2);
  if (cVar1 == '\0') {
    (**(code **)(*DAT_00b5abe0 + 0x10))(1);
    return (int *)0x0;
  }
  cVar1 = (**(code **)(*piVar2 + 4))(piVar4);
  if (cVar1 == '\0') {
    (**(code **)(*DAT_00b5abe0 + 0x10))(1,piVar4);
    return (int *)0x0;
  }
  return piVar4;
}


// ==== FUN_0082a3b0 @ 0x0082a3b0 ====

void FUN_0082a3b0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x60) + 0x14))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0xc))(param_2);
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0xc))();
    (**(code **)(*piVar1 + 0xc))(param_2,param_3);
  }
  return;
}


// ==== FUN_0082a3f0 @ 0x0082a3f0 ====

void FUN_0082a3f0(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x60) + 0x14))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0xc))(param_2);
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0xc))();
    (**(code **)(*piVar1 + 0x10))(param_2);
  }
  return;
}


// ==== FUN_0082a420 @ 0x0082a420 ====

void FUN_0082a420(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x60) + 0x14))();
  iVar2 = (**(code **)(*piVar1 + 0xc))(param_2);
  if (iVar2 != 0) {
    (**(code **)(*piVar1 + 8))(iVar2);
  }
  return;
}


// ==== FUN_0082a450 @ 0x0082a450 ====

void FUN_0082a450(int param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)(**(code **)(**(int **)(param_1 + 0x60) + 0x18))();
  cVar1 = (**(code **)(*piVar2 + 0xc))(param_2);
  if (cVar1 != '\x01') {
    (**(code **)(*piVar2 + 4))(param_2);
  }
  return;
}


// ==== FUN_0082a480 @ 0x0082a480 ====

void FUN_0082a480(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x60) + 0x18))();
  (**(code **)(*piVar1 + 8))(param_2);
  return;
}


// ==== FUN_0082a4a0 @ 0x0082a4a0 ====

char FUN_0082a4a0(int param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = FUN_00826bf0(param_1);
  if (iVar3 == 0) {
    return '\x04';
  }
  cVar1 = FUN_0082aa30(param_3);
  if (cVar1 == '\0') {
    return '\x05';
  }
  iVar3 = (**(code **)(*param_2 + 4))();
  if (*(char *)(iVar3 + 10) == '\0') {
    return '\x06';
  }
  bVar2 = (**(code **)(*DAT_00b5ab70 + 0xc))(param_1);
  if (bVar2 == 0) {
    return '\x02';
  }
  iVar3 = (**(code **)(*param_2 + 4))();
  if (bVar2 < *(byte *)(iVar3 + 0x10c)) {
    return '\x03';
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x98) + 0x40))();
  return (-(iVar3 != 0) & 9U) + 1;
}


// ==== FUN_0082a800 @ 0x0082a800 ====

undefined4 FUN_0082a800(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0082aae0(param_1);
  if (iVar1 == 0) {
    uVar2 = (**(code **)(*DAT_00b5a734 + 0x40))(param_1);
    (**(code **)(*param_1 + 0x28))(uVar2);
    return 1;
  }
  return 0;
}


// ==== FUN_0082a830 @ 0x0082a830 ====

int FUN_0082a830(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = *(int **)(param_1 + 0x24);
  iVar3 = 0;
  iVar4 = 0;
  do {
    iVar2 = (**(code **)(*piVar1 + 0x2c))(iVar4);
    if (iVar2 != 0) {
      iVar2 = FUN_0082a8d0(iVar2);
      iVar3 = iVar3 + iVar2;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x15);
  return iVar3;
}


// ==== FUN_0082a870 @ 0x0082a870 ====

int FUN_0082a870(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar3 = 0;
  iVar2 = (**(code **)(*piVar1 + 0x30))();
  while (iVar2 != 0) {
    iVar2 = FUN_0082a8d0(iVar2);
    iVar3 = iVar3 + iVar2;
    iVar2 = (**(code **)(*piVar1 + 0x34))();
  }
  return iVar3;
}


// ==== FUN_0082a8d0 @ 0x0082a8d0 ====

uint FUN_0082a8d0(int *param_1)

{
  ushort uVar1;
  char cVar2;
  byte bVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int unaff_EBX;
  
  piVar4 = (int *)(**(code **)(*param_1 + 0x48))();
  (**(code **)(*piVar4 + 4))();
  iVar5 = FUN_0082aae0(param_1);
  if (iVar5 != 0) {
    return 0;
  }
  uVar6 = (**(code **)(*DAT_00b5a734 + 0x40))(param_1);
  iVar5 = (**(code **)(*param_1 + 0x14))();
  uVar1 = *(ushort *)(iVar5 + 2);
  if (uVar1 / 100 < (uVar6 & 0xffff) / 100) {
    cVar2 = (**(code **)(*DAT_00b5a734 + 0x48))(param_1);
    if (cVar2 != '\x01') {
      cVar2 = (**(code **)(*DAT_00b5a734 + 0x44))(param_1);
      if (cVar2 == '\0') {
        iVar5 = (**(code **)(*DAT_00b5a6b8 + 4))();
        bVar3 = *(byte *)(iVar5 + 0x70);
      }
      else {
        iVar5 = (**(code **)(*DAT_00b5a6b8 + 4))();
        bVar3 = *(byte *)(iVar5 + 0x71);
      }
      uVar6 = ((((uint)bVar3 * *(int *)(unaff_EBX + 0x30)) / 100) * (uVar6 - uVar1 & 0xffff)) /
              (uVar6 & 0xffff);
      if (uVar6 < 2) {
        uVar6 = 1;
      }
      return uVar6;
    }
  }
  return 0;
}


// ==== FUN_0082a9c0 @ 0x0082a9c0 ====

void FUN_0082a9c0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = *(int **)(param_1 + 0x14);
  piVar2 = *(int **)(param_1 + 0x10);
  if ((piVar1 != (int *)0x0) && (piVar2 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x2c))();
    piVar3 = (int *)(**(code **)(*piVar2 + 0x18))();
    while (piVar3 != (int *)0x0) {
      piVar3 = (int *)(**(code **)(*piVar3 + 0xc))();
      iVar4 = (**(code **)(*piVar3 + 4))();
      if (*(char *)(iVar4 + 0x120) == '\x01') {
        iVar4 = *piVar1;
        iVar5 = (**(code **)(*piVar3 + 4))();
        (**(code **)(iVar4 + 0x20))(*(undefined1 *)(iVar5 + 0x102));
      }
      piVar3 = (int *)(**(code **)(*piVar2 + 0x1c))();
    }
  }
  return;
}


// ==== FUN_0082aa30 @ 0x0082aa30 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0082aa30(int *param_1)

{
  float fVar1;
  int *piVar2;
  float *pfVar3;
  undefined4 uStack_20;
  float fStack_10;
  float fStack_c;
  
  if (*(int **)(*param_1 + 0x4c) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(*param_1 + 0x4c) + 0x18))();
  }
  pfVar3 = (float *)(**(code **)(*piVar2 + 0x3c))(param_1[3]);
  fVar1 = *pfVar3;
  uStack_20 = (float)CONCAT22(uStack_20._2_2_,*(undefined2 *)(pfVar3 + 1));
  FUN_004f5730(&fStack_10);
  FUN_004f5730((int)register0x00000010 + -0x24);
  if (_DAT_00a0d5ac <
      (fStack_c - uStack_20) * (fStack_c - uStack_20) + (fStack_10 - fVar1) * (fStack_10 - fVar1)) {
    return 0;
  }
  return 1;
}


// ==== FUN_0082aae0 @ 0x0082aae0 ====

undefined1 FUN_0082aae0(int *param_1)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)(**(code **)(*param_1 + 0x48))();
  iVar4 = (**(code **)(*piVar3 + 4))();
  if (*(char *)(iVar4 + 0x7e) == '\0') {
    return 2;
  }
  if (*(char *)(iVar4 + 0x7f) == '\0') {
    return 3;
  }
  iVar4 = (**(code **)(*param_1 + 0x14))();
  uVar1 = *(ushort *)(iVar4 + 2);
  if (uVar1 == 0) {
    return 4;
  }
  uVar2 = (**(code **)(*DAT_00b5a734 + 0x40))(param_1);
  return uVar2 <= uVar1;
}


// ==== FUN_0082ab40 @ 0x0082ab40 ====

void FUN_0082ab40(void)

{
  void *pvVar1;
  
  if (DAT_00b5d920 == 0) {
    pvVar1 = operator_new(0x10);
    if (pvVar1 != (void *)0x0) {
      FUN_0082c800();
    }
  }
  if (DAT_00b5d92c == 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      FUN_0082bf70();
    }
  }
  if (DAT_00b5d928 == 0) {
    pvVar1 = operator_new(0x30);
    if (pvVar1 != (void *)0x0) {
      FUN_0082b6e0();
    }
  }
  if (DAT_00b5d924 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_0082b1b0();
      return;
    }
  }
  return;
}


// ==== FUN_0082abc0 @ 0x0082abc0 ====

void FUN_0082abc0(void)

{
  if (DAT_00b5d924 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d924)(1);
  }
  if (DAT_00b5d928 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d928)(1);
  }
  if (DAT_00b5d92c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d92c)(1);
  }
  if (DAT_00b5d920 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d920)(1);
  }
  return;
}


// ==== FUN_0082ac10 @ 0x0082ac10 ====

void FUN_0082ac10(void)

{
  void *pvVar1;
  
  if (DAT_00b5d930 == 0) {
    pvVar1 = operator_new(0x10);
    if (pvVar1 != (void *)0x0) {
      FUN_0082e210();
    }
  }
  if (DAT_00b5d93c == 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      FUN_0082da40();
    }
  }
  if (DAT_00b5d938 == 0) {
    pvVar1 = operator_new(0x30);
    if (pvVar1 != (void *)0x0) {
      FUN_0082d1b0();
    }
  }
  if (DAT_00b5d934 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_0082cca0();
      return;
    }
  }
  return;
}


// ==== FUN_0082ac90 @ 0x0082ac90 ====

void FUN_0082ac90(void)

{
  if (DAT_00b5d934 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d934)(1);
  }
  if (DAT_00b5d938 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d938)(1);
  }
  if (DAT_00b5d93c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d93c)(1);
  }
  if (DAT_00b5d930 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d930)(1);
  }
  return;
}


// ==== FUN_0082ace0 @ 0x0082ace0 ====

void FUN_0082ace0(void)

{
  void *pvVar1;
  
  if (DAT_00b5afa4 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_0082e6b0();
      return;
    }
  }
  return;
}


// ==== FUN_0082ad00 @ 0x0082ad00 ====

void FUN_0082ad00(void)

{
  if (DAT_00b5afa4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5afa4)(1);
  }
  return;
}


// ==== FUN_0082ad20 @ 0x0082ad20 ====

void FUN_0082ad20(void)

{
  void *pvVar1;
  
  FUN_008308b0();
  if (DAT_00b5d940 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_008304a0();
    }
  }
  if (DAT_00b5d948 == 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      FUN_0082ffd0();
    }
  }
  if (DAT_00b5d944 == 0) {
    pvVar1 = operator_new(0x30);
    if (pvVar1 != (void *)0x0) {
      FUN_0082f750();
    }
  }
  if (DAT_00b5ad24 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_0082e860();
      return;
    }
  }
  return;
}


// ==== FUN_0082ada0 @ 0x0082ada0 ====

void FUN_0082ada0(void)

{
  if (DAT_00b5ad24 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ad24)(1);
  }
  if (DAT_00b5d944 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d944)(1);
  }
  if (DAT_00b5d948 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d948)(1);
  }
  if (DAT_00b5d940 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d940)(1);
  }
  FUN_00830910();
  return;
}


// ==== FUN_0082adf0 @ 0x0082adf0 ====

void FUN_0082adf0(void)

{
  void *pvVar1;
  
  if (DAT_00b5d950 == 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      FUN_00831670();
    }
  }
  if (DAT_00b5d94c == 0) {
    pvVar1 = operator_new(0x2c);
    if (pvVar1 != (void *)0x0) {
      FUN_00830dd0();
    }
  }
  if (DAT_00b5af38 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_00830970();
      return;
    }
  }
  return;
}


// ==== FUN_0082ae50 @ 0x0082ae50 ====

void FUN_0082ae50(void)

{
  if (DAT_00b5af38 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5af38)(1);
  }
  if (DAT_00b5d94c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d94c)(1);
  }
  if (DAT_00b5d950 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d950)(1);
  }
  return;
}


// ==== FUN_0082ae90 @ 0x0082ae90 ====

void FUN_0082ae90(void)

{
  void *pvVar1;
  
  if (DAT_00b5d954 == 0) {
    pvVar1 = operator_new(0x10);
    if (pvVar1 != (void *)0x0) {
      FUN_00833320();
    }
  }
  if (DAT_00b5d95c == 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      FUN_00832820();
    }
  }
  if (DAT_00b5d958 == 0) {
    pvVar1 = operator_new(0x2c);
    if (pvVar1 != (void *)0x0) {
      FUN_00831fb0();
    }
  }
  if (DAT_00b5af3c == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_00831b50();
      return;
    }
  }
  return;
}


// ==== FUN_0082af10 @ 0x0082af10 ====

void FUN_0082af10(void)

{
  if (DAT_00b5af3c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5af3c)(1);
  }
  if (DAT_00b5d958 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d958)(1);
  }
  if (DAT_00b5d95c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d95c)(1);
  }
  if (DAT_00b5d954 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d954)(1);
  }
  return;
}


// ==== FUN_0082af60 @ 0x0082af60 ====

void FUN_0082af60(void)

{
  void *pvVar1;
  
  if (DAT_00b5ac10 == 0) {
    pvVar1 = operator_new(0x10);
    if (pvVar1 != (void *)0x0) {
      FUN_00834a40();
    }
  }
  if (DAT_00b5d964 == 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      FUN_00834230();
    }
  }
  if (DAT_00b5d960 == 0) {
    pvVar1 = operator_new(0x2c);
    if (pvVar1 != (void *)0x0) {
      FUN_00833930();
    }
  }
  if (DAT_00b5afe4 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_00833480();
      return;
    }
  }
  return;
}


// ==== FUN_0082afe0 @ 0x0082afe0 ====

void FUN_0082afe0(void)

{
  if (DAT_00b5afe4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5afe4)(1);
  }
  if (DAT_00b5d960 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d960)(1);
  }
  if (DAT_00b5d964 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d964)(1);
  }
  if (DAT_00b5ac10 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ac10)(1);
  }
  return;
}


// ==== FUN_0082b030 @ 0x0082b030 ====

void FUN_0082b030(void)

{
  void *pvVar1;
  
  if (DAT_00b5d96c == 0) {
    pvVar1 = operator_new(0x2c);
    if (pvVar1 != (void *)0x0) {
      FUN_00837a10();
    }
  }
  if (DAT_00b5d970 == 0) {
    pvVar1 = operator_new(0x2c);
    if (pvVar1 != (void *)0x0) {
      FUN_00836ce0();
    }
  }
  if (DAT_00b5afd4 == 0) {
    pvVar1 = operator_new(0x1c);
    if (pvVar1 != (void *)0x0) {
      FUN_00836860();
    }
  }
  if (DAT_00b5b010 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_00836010();
    }
  }
  if (DAT_00b5d968 == 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      FUN_00835b40();
    }
  }
  if (DAT_00b5afdc == 0) {
    pvVar1 = operator_new(0x2c);
    if (pvVar1 != (void *)0x0) {
      FUN_008350b0();
    }
  }
  if (DAT_00b5afe0 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_00834ee0();
      return;
    }
  }
  return;
}


// ==== FUN_0082b110 @ 0x0082b110 ====

void FUN_0082b110(void)

{
  if (DAT_00b5afe0 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5afe0)(1);
  }
  if (DAT_00b5afdc != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5afdc)(1);
  }
  if (DAT_00b5d968 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d968)(1);
  }
  if (DAT_00b5b010 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5b010)(1);
  }
  if (DAT_00b5afd4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5afd4)(1);
  }
  if (DAT_00b5d970 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d970)(1);
  }
  if (DAT_00b5d96c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d96c)(1);
  }
  return;
}


// ==== FUN_0082b190 @ 0x0082b190 ====

void FUN_0082b190(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0d6f4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082b1b0 @ 0x0082b1b0 ====

void FUN_0082b1b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0d70c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5d924 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5d924 = in_ECX;
  return;
}


// ==== FUN_0082b1e0 @ 0x0082b1e0 ====

undefined4 FUN_0082b1e0(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5d92c + 4))();
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 4))(param_1);
    if (cVar1 == '\0') {
      (**(code **)(*DAT_00b5d92c + 8))();
      return 0;
    }
    cVar1 = (**(code **)(*DAT_00b5d928 + 8))(piVar2);
    if (cVar1 != '\0') {
      return 1;
    }
    (**(code **)(*DAT_00b5d92c + 8))(piVar2);
  }
  return 0;
}


// ==== FUN_0082b240 @ 0x0082b240 ====

undefined4 FUN_0082b240(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5d928 + 0xc))(param_1);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*piVar1 + 0xc))();
  (**(code **)(*DAT_00b5d92c + 8))(piVar1);
  return 1;
}


// ==== FUN_0082b280 @ 0x0082b280 ====

void FUN_0082b280(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5d928 + 0x14))();
  while (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x18))(param_1);
    piVar1 = (int *)(**(code **)(*DAT_00b5d928 + 0x18))();
  }
  return;
}


// ==== FUN_0082b2b0 @ 0x0082b2b0 ====

void FUN_0082b2b0(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5d928 + 0x14))();
  if (piVar1 != (int *)0x0) {
    do {
      iVar2 = (**(code **)(*piVar1 + 8))();
      if (*(int *)(iVar2 + 0x60) == param_1) {
        (**(code **)(*piVar1 + 0x1c))(param_2);
      }
      piVar1 = (int *)(**(code **)(*DAT_00b5d928 + 0x18))();
    } while (piVar1 != (int *)0x0);
  }
  return;
}


// ==== FUN_0082b320 @ 0x0082b320 ====

void FUN_0082b320(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5d924 = 0;
  *in_ECX = &PTR_FUN_00a0d6f4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082b350 @ 0x0082b350 ====

void FUN_0082b350(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0d764;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082b370 @ 0x0082b370 ====

int FUN_0082b370(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999b80;
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


// ==== Catch@0082b3d6 @ 0x0082b3d6 ====

void Catch_0082b3d6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0082b3e0 @ 0x0082b3e0 ====

void FUN_0082b3e0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999b90;
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


// ==== Catch@0082b44f @ 0x0082b44f ====

void Catch_0082b44f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0082b470 @ 0x0082b470 ====

void * FUN_0082b470(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999ba0;
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


// ==== Catch@0082b4dd @ 0x0082b4dd ====

void Catch_0082b4dd(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0082b500 @ 0x0082b500 ====

void FUN_0082b500(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999bb0;
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


// ==== Catch@0082b566 @ 0x0082b566 ====

void Catch_0082b566(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0082b570 @ 0x0082b570 ====

void FUN_0082b570(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0082b370(param_1,param_2,param_3);
  return;
}


// ==== FUN_0082b590 @ 0x0082b590 ====

undefined4 FUN_0082b590(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x14) == 0) {
    return 0;
  }
  iVar1 = **(int **)(in_ECX + 0x10);
  *(int *)(in_ECX + 4) = iVar1;
  return *(undefined4 *)(iVar1 + 0xc);
}


// ==== FUN_0082b5b0 @ 0x0082b5b0 ====

undefined4 FUN_0082b5b0(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x14) != 0) && (*(int **)(in_ECX + 4) != *(int **)(in_ECX + 0x10))) {
    iVar1 = **(int **)(in_ECX + 4);
    *(int *)(in_ECX + 4) = iVar1;
    if (iVar1 != *(int *)(in_ECX + 0x10)) {
      return *(undefined4 *)(iVar1 + 0xc);
    }
  }
  return 0;
}


// ==== FUN_0082b5e0 @ 0x0082b5e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0082b5e0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  float fVar3;
  int in_ECX;
  
  fVar3 = (float)*(int *)(param_1 + 4);
  if (*(int *)(param_1 + 4) < 0) {
    fVar3 = fVar3 + _DAT_0099d104;
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x10);
  fVar3 = fVar3 * DAT_0099d0ec;
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    (**(code **)(*(int *)puVar2[3] + 0x20))(fVar3);
  }
  return;
}


// ==== FUN_0082b630 @ 0x0082b630 ====

uint FUN_0082b630(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_0082b5e0(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0082b660 @ 0x0082b660 ====

undefined4 FUN_0082b660(undefined1 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0x10)) {
    return 0;
  }
  uVar1 = *(undefined4 *)(local_4 + 0xc);
  FUN_00598f60(&param_1,local_4);
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 0x10);
  return uVar1;
}


// ==== FUN_0082b6b0 @ 0x0082b6b0 ====

undefined4 FUN_0082b6b0(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0x10)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0xc);
}


// ==== FUN_0082b6e0 @ 0x0082b6e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0082b6e0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_00a0d784;
  puVar1 = in_ECX + 1;
  *puVar1 = 0;
  *(undefined1 *)(in_ECX + 2) = local_5;
  uVar2 = FUN_0082b3e0();
  in_ECX[4] = uVar2;
  in_ECX[5] = 0;
  local_4 = in_ECX[4];
  FUN_0082bb00(9,&local_4);
  in_ECX[10] = 1;
  in_ECX[0xb] = 1;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5d928 = (undefined4 *)0x0;
    _DAT_00000000 = in_ECX[4];
    return;
  }
  DAT_00b5d928 = in_ECX;
  *puVar1 = in_ECX[4];
  return;
}


// ==== FUN_0082b770 @ 0x0082b770 ====

void FUN_0082b770(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  void *_Memory;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0d784;
  DAT_00b5d928 = 0;
  puVar1 = (undefined4 *)in_ECX[4];
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    piVar3 = (int *)puVar2[3];
    (**(code **)(*piVar3 + 0xc))();
    (**(code **)(*DAT_00b5d92c + 8))(piVar3);
  }
  FUN_0082bea0();
  in_ECX[1] = in_ECX[4];
  if ((void *)in_ECX[7] != (void *)0x0) {
    _free((void *)in_ECX[7]);
    return;
  }
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  puVar1 = (undefined4 *)in_ECX[4];
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(undefined4 *)(in_ECX[4] + 4) = in_ECX[4];
  in_ECX[5] = 0;
  if (_Memory == (void *)in_ECX[4]) {
    _free((void *)in_ECX[4]);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_0082b820 @ 0x0082b820 ====

char FUN_0082b820(int *param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 uStack_10;
  int *piStack_c;
  undefined1 auStack_8 [4];
  char cStack_4;
  
  if (param_1 == (int *)0x0) {
    return '\0';
  }
  iVar1 = (**(code **)(*param_1 + 8))();
  uStack_10 = *(undefined4 *)(iVar1 + 4);
  piStack_c = param_1;
  FUN_0082bc70(auStack_8,&uStack_10);
  if (cStack_4 == '\x01') {
    *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 0x10);
  }
  return cStack_4;
}


// ==== FUN_0082b880 @ 0x0082b880 ====

int FUN_0082b880(int param_1,int param_2,undefined4 param_3)

{
  FUN_0082b500(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_0082b8b0 @ 0x0082b8b0 ====

void FUN_0082b8b0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00999bc0;
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
      uVar5 = FUN_0082b570(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_0082b880(uVar5,param_2,&local_18);
      FUN_0082b570(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_0082b370(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_0082b880(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_0082b370(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0082ba11 @ 0x0082ba11 ====

void Catch_0082ba11(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0082bb00 @ 0x0082bb00 ====

void FUN_0082bb00(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999bd0;
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
    uVar2 = FUN_0082b880(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0082bb94 @ 0x0082bb94 ====

void Catch_0082bb94(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0082bbb0 @ 0x0082bbb0 ====

void FUN_0082bbb0(uint param_1,undefined1 param_2)

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
    FUN_0082b8b0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_0082bc20 @ 0x0082bc20 ====

/* WARNING: Removing unreachable block (ram,0x0082bc3b) */
/* WARNING: Removing unreachable block (ram,0x0082bc40) */
/* WARNING: Removing unreachable block (ram,0x0082bc4e) */

void FUN_0082bc20(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_0082b8b0(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_0082bc70 @ 0x0082bc70 ====

/* WARNING: Removing unreachable block (ram,0x0082bd58) */

void FUN_0082bc70(int *param_1,uint *param_2)

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
      FUN_0082bbb0(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
  iVar5 = FUN_0082b470(puVar7,puVar7[1],param_2);
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


// ==== FUN_0082bea0 @ 0x0082bea0 ====

void FUN_0082bea0(void)

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
    FUN_0082bc20(9,&local_4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_0082bf00 @ 0x0082bf00 ====

void FUN_0082bf00(byte param_1)

{
  void *in_ECX;
  
  FUN_0082b770();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082bf20 @ 0x0082bf20 ====

void FUN_0082bf20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0d968;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082bf40 @ 0x0082bf40 ====

void FUN_0082bf40(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0082bf60 @ 0x0082bf60 ====

void FUN_0082bf60(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  return;
}


// ==== FUN_0082bf70 @ 0x0082bf70 ====

void FUN_0082bf70(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  puVar1 = in_ECX + 1;
  *in_ECX = &PTR_FUN_00a0d9b0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5d92c = (undefined4 *)0x0;
  }
  else {
    DAT_00b5d92c = in_ECX;
  }
  pvVar2 = operator_new(0x39018);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    return;
  }
  uVar3 = FUN_0082c050();
  *puVar1 = uVar3;
  return;
}


// ==== FUN_0082bfc0 @ 0x0082bfc0 ====

void FUN_0082bfc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0d9b0;
  DAT_00b5d92c = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_00a0d968;
  return;
}


// ==== FUN_0082bff0 @ 0x0082bff0 ====

void FUN_0082bff0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0d978;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082c010 @ 0x0082c010 ====

void FUN_0082c010(void)

{
  undefined4 *in_ECX;
  int iVar1;
  
  *in_ECX = &PTR_FUN_00a0d990;
  iVar1 = 0x200;
  do {
    FUN_00838c90();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  in_ECX[0xe401] = 0;
  return;
}


// ==== FUN_0082c050 @ 0x0082c050 ====

void FUN_0082c050(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_00a0d998;
  FUN_0082c010();
  in_ECX[0xe402] = in_ECX[0xe402] + 0x200;
  in_ECX[0xe405] = in_ECX + 2;
  in_ECX[0xe403] = 0;
  in_ECX[0xe404] = 0;
  iVar2 = 0x1ff;
  puVar1 = in_ECX;
  do {
    puVar1[0x71] = puVar1 + 0x74;
    puVar1[0x72] = 0;
    puVar1[0x73] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x72;
  } while (iVar2 != 0);
  in_ECX[0xe3ff] = 0;
  in_ECX[0xe400] = 0;
  in_ECX[0xe401] = 0;
  return;
}


// ==== FUN_0082c0c0 @ 0x0082c0c0 ====

undefined4 FUN_0082c0c0(void)

{
  return 0x200;
}


// ==== FUN_0082c0d0 @ 0x0082c0d0 ====

undefined4 FUN_0082c0d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x3900c);
}


// ==== FUN_0082c0e0 @ 0x0082c0e0 ====

void FUN_0082c0e0(byte param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  *in_ECX = &PTR_FUN_00a0d990;
  iVar1 = 0x200;
  do {
    FUN_00838bc0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082c130 @ 0x0082c130 ====

void * FUN_0082c130(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x1c4) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a0d9c0,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x1c4) = *(int *)((int)param_2 + 0x1c4) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x39014);
  *(int *)(in_ECX + 0x3900c) = *(int *)(in_ECX + 0x3900c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x1c8);
    if (pvVar2 == (void *)0x0) {
      pvVar2 = (void *)0x0;
    }
    else {
      FUN_00838c90();
    }
    *(undefined4 *)((int)pvVar2 + 0x1c0) = *(undefined4 *)(in_ECX + 0x39010);
    *(void **)(in_ECX + 0x39010) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x39014) = *(undefined4 *)((int)pvVar2 + 0x1bc);
  }
  *(int *)((int)pvVar2 + 0x1c4) = param_1;
  *(undefined4 *)((int)pvVar2 + 0x1bc) = 0;
  FUN_00838570();
  return pvVar2;
}


// ==== FUN_0082c210 @ 0x0082c210 ====

undefined4 FUN_0082c210(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c4) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a0d9c0,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c4);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c4);
    }
    FUN_008384b0();
    *(undefined4 *)(param_2 + 0x1bc) = *(undefined4 *)(in_ECX + 0x39014);
    *(int *)(in_ECX + 0x3900c) = *(int *)(in_ECX + 0x3900c) + -1;
    *(int *)(in_ECX + 0x39014) = param_2;
  }
  return 0;
}


// ==== FUN_0082c2a0 @ 0x0082c2a0 ====

void FUN_0082c2a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0082c2c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082c2c0 @ 0x0082c2c0 ====

void FUN_0082c2c0(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_00a0d998;
  if (in_ECX[0xe403] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0d84c,
                         s_d__usa_24_0_1_2__develop_module__00a0d7e0,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x73;
  iVar3 = 0x200;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0d8cc,
                           s_d__usa_24_0_1_2__develop_module__00a0d860,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x72;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0xe404];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_00a0d990;
    iVar3 = 0x200;
    do {
      FUN_00838bc0();
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *in_ECX = &PTR_FUN_00a0d978;
    return;
  }
  if (*(int *)((int)_Memory + 0x1c4) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0d94c,
                         s_d__usa_24_0_1_2__develop_module__00a0d8e0,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_00838bc0();
  _free(_Memory);
  return;
}


// ==== FUN_0082c3e0 @ 0x0082c3e0 ====

void FUN_0082c3e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0d9b0;
  DAT_00b5d92c = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_00a0d968;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082c430 @ 0x0082c430 ====

void FUN_0082c430(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0da70;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082c450 @ 0x0082c450 ====

void FUN_0082c450(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999be0;
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


// ==== Catch@0082c4da @ 0x0082c4da ====

void Catch_0082c4da(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_0082c4f0 @ 0x0082c4f0 ====

undefined1 FUN_0082c4f0(int *param_1,int *param_2,undefined1 param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  while (param_1 != param_2) {
    if ((undefined4 *)param_1[10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[10])(1);
    }
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
  return param_3;
}


// ==== FUN_0082c560 @ 0x0082c560 ====

void FUN_0082c560(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) != '\0') {
    return;
  }
  FUN_0082c560(*(undefined4 *)((int)param_1 + 8));
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


// ==== FUN_0082c5c0 @ 0x0082c5c0 ====

void * FUN_0082c5c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999bf0;
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


// ==== Catch@0082c635 @ 0x0082c635 ====

void Catch_0082c635(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0082c650 @ 0x0082c650 ====

void FUN_0082c650(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  
  if (param_1 != (int *)0x0) {
    uVar3 = (**(code **)(*param_1 + 0x14))();
    FUN_0069a470(&param_1,uVar3);
    piVar2 = param_1;
    if (param_1 != *(int **)(in_ECX + 8)) {
      puVar1 = (undefined4 *)param_1[10];
      iVar4 = FUN_008393a0();
      if ((iVar4 == 0) && (FUN_005a4100(&param_1,piVar2), puVar1 != (undefined4 *)0x0)) {
        (**(code **)*puVar1)(1);
      }
    }
  }
  return;
}


// ==== FUN_0082c6b0 @ 0x0082c6b0 ====

undefined4 FUN_0082c6b0(int param_1,undefined4 param_2)

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
    FUN_00839390();
    return uVar3;
  }
  pvVar2 = operator_new(0x34);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00839420();
  }
  FUN_008394d0(iVar1,param_2);
  FUN_00839390();
  local_8 = 0xf;
  local_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401660(iVar1,0,0xffffffff);
  local_4 = uVar3;
  FUN_0082caf0(local_28,local_20);
  if (local_8 < 0x10) {
    return uVar3;
  }
  _free(local_1c);
  return extraout_EAX;
}


// ==== FUN_0082c770 @ 0x0082c770 ====

void FUN_0082c770(void)

{
  undefined4 *in_ECX;
  undefined4 *local_4;
  
  *in_ECX = &PTR_FUN_00a0da80;
  DAT_00b5d920 = 0;
  local_4 = in_ECX;
  if (in_ECX[3] != 0) {
    local_4 = (undefined4 *)((uint)in_ECX & 0xffffff00);
    FUN_0082c4f0(*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2],local_4);
    FUN_0082c560(*(undefined4 *)(in_ECX[2] + 4));
    *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
    in_ECX[3] = 0;
    *(undefined4 *)in_ECX[2] = in_ECX[2];
    *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  }
  FUN_0082ca30(&local_4,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0082c800 @ 0x0082c800 ====

void FUN_0082c800(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0da80;
  iVar1 = FUN_0082c450();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5d920 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5d920 = in_ECX;
  return;
}


// ==== FUN_0082c850 @ 0x0082c850 ====

void FUN_0082c850(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_0082c5c0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_0082c955:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_0082c955;
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


// ==== FUN_0082ca30 @ 0x0082ca30 ====

void FUN_0082ca30(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0082c560(piVar6[1]);
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


// ==== FUN_0082caf0 @ 0x0082caf0 ====

/* WARNING: Removing unreachable block (ram,0x0082cb4f) */

void FUN_0082caf0(undefined4 *param_1,undefined4 *param_2)

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
LAB_0082cb80:
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
        if (uVar5 == 0) goto LAB_0082cb80;
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
      puVar6 = (undefined4 *)FUN_0082c850(&param_2,1,puVar6,iVar3);
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
    puVar6 = (undefined4 *)FUN_0082c850(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_0082cc60 @ 0x0082cc60 ====

void FUN_0082cc60(byte param_1)

{
  void *in_ECX;
  
  FUN_0082c770();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082cc80 @ 0x0082cc80 ====

void FUN_0082cc80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0dad0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082cca0 @ 0x0082cca0 ====

void FUN_0082cca0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0dae8;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5d934 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5d934 = in_ECX;
  return;
}


// ==== FUN_0082ccd0 @ 0x0082ccd0 ====

undefined4 FUN_0082ccd0(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5d93c + 4))();
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 4))(param_1);
    if (cVar1 == '\0') {
      (**(code **)(*DAT_00b5d93c + 8))();
      return 0;
    }
    cVar1 = (**(code **)(*DAT_00b5d938 + 8))(piVar2);
    if (cVar1 != '\0') {
      return 1;
    }
    (**(code **)(*DAT_00b5d93c + 8))(piVar2);
  }
  return 0;
}


// ==== FUN_0082cd30 @ 0x0082cd30 ====

undefined4 FUN_0082cd30(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5d938 + 0xc))(param_1);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*piVar1 + 0xc))();
  (**(code **)(*DAT_00b5d93c + 8))(piVar1);
  return 1;
}


// ==== FUN_0082cd70 @ 0x0082cd70 ====

void FUN_0082cd70(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5d938 + 0x14))();
  while (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x18))(param_1);
    piVar1 = (int *)(**(code **)(*DAT_00b5d938 + 0x18))();
  }
  return;
}


// ==== FUN_0082cda0 @ 0x0082cda0 ====

void FUN_0082cda0(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5d938 + 0x14))();
  while (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x1c))(param_1);
    piVar1 = (int *)(**(code **)(*DAT_00b5d938 + 0x18))();
  }
  return;
}


// ==== FUN_0082cdf0 @ 0x0082cdf0 ====

void FUN_0082cdf0(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5d934 = 0;
  *in_ECX = &PTR_FUN_00a0dad0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082ce20 @ 0x0082ce20 ====

void FUN_0082ce20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0db40;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082ce40 @ 0x0082ce40 ====

int FUN_0082ce40(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999c00;
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


// ==== Catch@0082cea6 @ 0x0082cea6 ====

void Catch_0082cea6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0082ceb0 @ 0x0082ceb0 ====

void FUN_0082ceb0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999c10;
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


// ==== Catch@0082cf1f @ 0x0082cf1f ====

void Catch_0082cf1f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0082cf40 @ 0x0082cf40 ====

void * FUN_0082cf40(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999c20;
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


// ==== Catch@0082cfad @ 0x0082cfad ====

void Catch_0082cfad(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0082cfd0 @ 0x0082cfd0 ====

void FUN_0082cfd0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999c30;
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


// ==== Catch@0082d036 @ 0x0082d036 ====

void Catch_0082d036(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0082d040 @ 0x0082d040 ====

void FUN_0082d040(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0082ce40(param_1,param_2,param_3);
  return;
}


// ==== FUN_0082d060 @ 0x0082d060 ====

undefined4 FUN_0082d060(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x14) == 0) {
    return 0;
  }
  iVar1 = **(int **)(in_ECX + 0x10);
  *(int *)(in_ECX + 4) = iVar1;
  return *(undefined4 *)(iVar1 + 0xc);
}


// ==== FUN_0082d080 @ 0x0082d080 ====

undefined4 FUN_0082d080(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x14) != 0) && (*(int **)(in_ECX + 4) != *(int **)(in_ECX + 0x10))) {
    iVar1 = **(int **)(in_ECX + 4);
    *(int *)(in_ECX + 4) = iVar1;
    if (iVar1 != *(int *)(in_ECX + 0x10)) {
      return *(undefined4 *)(iVar1 + 0xc);
    }
  }
  return 0;
}


// ==== FUN_0082d0b0 @ 0x0082d0b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0082d0b0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  float fVar3;
  int in_ECX;
  
  fVar3 = (float)*(int *)(param_1 + 4);
  if (*(int *)(param_1 + 4) < 0) {
    fVar3 = fVar3 + _DAT_0099d104;
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x10);
  fVar3 = fVar3 * DAT_0099d0ec;
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    (**(code **)(*(int *)puVar2[3] + 0x20))(fVar3);
  }
  return;
}


// ==== FUN_0082d100 @ 0x0082d100 ====

uint FUN_0082d100(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_0082d0b0(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0082d130 @ 0x0082d130 ====

undefined4 FUN_0082d130(undefined1 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0x10)) {
    return 0;
  }
  uVar1 = *(undefined4 *)(local_4 + 0xc);
  FUN_00598f60(&param_1,local_4);
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 0x10);
  return uVar1;
}


// ==== FUN_0082d180 @ 0x0082d180 ====

undefined4 FUN_0082d180(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0x10)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0xc);
}


// ==== FUN_0082d1b0 @ 0x0082d1b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0082d1b0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_00a0db60;
  puVar1 = in_ECX + 1;
  *puVar1 = 0;
  *(undefined1 *)(in_ECX + 2) = local_5;
  uVar2 = FUN_0082ceb0();
  in_ECX[4] = uVar2;
  in_ECX[5] = 0;
  local_4 = in_ECX[4];
  FUN_0082d5d0(9,&local_4);
  in_ECX[10] = 1;
  in_ECX[0xb] = 1;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5d938 = (undefined4 *)0x0;
    _DAT_00000000 = in_ECX[4];
    return;
  }
  DAT_00b5d938 = in_ECX;
  *puVar1 = in_ECX[4];
  return;
}


// ==== FUN_0082d240 @ 0x0082d240 ====

void FUN_0082d240(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  void *_Memory;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0db60;
  DAT_00b5d938 = 0;
  puVar1 = (undefined4 *)in_ECX[4];
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    piVar3 = (int *)puVar2[3];
    (**(code **)(*piVar3 + 0xc))();
    (**(code **)(*DAT_00b5d93c + 8))(piVar3);
  }
  FUN_0082d970();
  in_ECX[1] = in_ECX[4];
  if ((void *)in_ECX[7] != (void *)0x0) {
    _free((void *)in_ECX[7]);
    return;
  }
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  puVar1 = (undefined4 *)in_ECX[4];
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(undefined4 *)(in_ECX[4] + 4) = in_ECX[4];
  in_ECX[5] = 0;
  if (_Memory == (void *)in_ECX[4]) {
    _free((void *)in_ECX[4]);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_0082d2f0 @ 0x0082d2f0 ====

char FUN_0082d2f0(int *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 uStack_10;
  int *piStack_c;
  undefined1 auStack_8 [4];
  char cStack_4;
  
  if (param_1 == (int *)0x0) {
    return '\0';
  }
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 8))();
  uStack_10 = *puVar1;
  piStack_c = param_1;
  FUN_0082d740(auStack_8,&uStack_10);
  if (cStack_4 == '\x01') {
    *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 0x10);
  }
  return cStack_4;
}


// ==== FUN_0082d350 @ 0x0082d350 ====

int FUN_0082d350(int param_1,int param_2,undefined4 param_3)

{
  FUN_0082cfd0(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_0082d380 @ 0x0082d380 ====

void FUN_0082d380(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00999c40;
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
      uVar5 = FUN_0082d040(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_0082d350(uVar5,param_2,&local_18);
      FUN_0082d040(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_0082ce40(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_0082d350(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_0082ce40(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0082d4e1 @ 0x0082d4e1 ====

void Catch_0082d4e1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0082d5d0 @ 0x0082d5d0 ====

void FUN_0082d5d0(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999c50;
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
    uVar2 = FUN_0082d350(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0082d664 @ 0x0082d664 ====

void Catch_0082d664(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0082d680 @ 0x0082d680 ====

void FUN_0082d680(uint param_1,undefined1 param_2)

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
    FUN_0082d380(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_0082d6f0 @ 0x0082d6f0 ====

/* WARNING: Removing unreachable block (ram,0x0082d70b) */
/* WARNING: Removing unreachable block (ram,0x0082d710) */
/* WARNING: Removing unreachable block (ram,0x0082d71e) */

void FUN_0082d6f0(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_0082d380(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_0082d740 @ 0x0082d740 ====

/* WARNING: Removing unreachable block (ram,0x0082d828) */

void FUN_0082d740(int *param_1,uint *param_2)

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
      FUN_0082d680(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
  iVar5 = FUN_0082cf40(puVar7,puVar7[1],param_2);
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


// ==== FUN_0082d970 @ 0x0082d970 ====

void FUN_0082d970(void)

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
    FUN_0082d6f0(9,&local_4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_0082d9d0 @ 0x0082d9d0 ====

void FUN_0082d9d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0082d240();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082d9f0 @ 0x0082d9f0 ====

void FUN_0082d9f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0dd48;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082da10 @ 0x0082da10 ====

void FUN_0082da10(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0082da30 @ 0x0082da30 ====

void FUN_0082da30(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  return;
}


// ==== FUN_0082da40 @ 0x0082da40 ====

void FUN_0082da40(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  puVar1 = in_ECX + 1;
  *in_ECX = &PTR_FUN_00a0dd90;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5d93c = (undefined4 *)0x0;
  }
  else {
    DAT_00b5d93c = in_ECX;
  }
  pvVar2 = operator_new(0x35818);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    return;
  }
  uVar3 = FUN_0082db20();
  *puVar1 = uVar3;
  return;
}


// ==== FUN_0082da90 @ 0x0082da90 ====

void FUN_0082da90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0dd90;
  DAT_00b5d93c = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_00a0dd48;
  return;
}


// ==== FUN_0082dac0 @ 0x0082dac0 ====

void FUN_0082dac0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0dd58;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082dae0 @ 0x0082dae0 ====

void FUN_0082dae0(void)

{
  undefined4 *in_ECX;
  int iVar1;
  
  *in_ECX = &PTR_FUN_00a0dd70;
  iVar1 = 0x200;
  do {
    FUN_0083a3b0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  in_ECX[0xd601] = 0;
  return;
}


// ==== FUN_0082db20 @ 0x0082db20 ====

void FUN_0082db20(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_00a0dd78;
  FUN_0082dae0();
  in_ECX[0xd602] = in_ECX[0xd602] + 0x200;
  in_ECX[0xd605] = in_ECX + 2;
  in_ECX[0xd603] = 0;
  in_ECX[0xd604] = 0;
  iVar2 = 0x1ff;
  puVar1 = in_ECX;
  do {
    puVar1[0x6a] = puVar1 + 0x6d;
    puVar1[0x6b] = 0;
    puVar1[0x6c] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x6b;
  } while (iVar2 != 0);
  in_ECX[0xd5ff] = 0;
  in_ECX[0xd600] = 0;
  in_ECX[0xd601] = 0;
  return;
}


// ==== FUN_0082db90 @ 0x0082db90 ====

undefined4 FUN_0082db90(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x3580c);
}


// ==== FUN_0082dba0 @ 0x0082dba0 ====

void FUN_0082dba0(byte param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  *in_ECX = &PTR_FUN_00a0dd70;
  iVar1 = 0x200;
  do {
    FUN_0083a2f0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082dbf0 @ 0x0082dbf0 ====

void * FUN_0082dbf0(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x1a8) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a0dda0,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x1a8) = *(int *)((int)param_2 + 0x1a8) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x35814);
  *(int *)(in_ECX + 0x3580c) = *(int *)(in_ECX + 0x3580c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x1ac);
    if (pvVar2 == (void *)0x0) {
      pvVar2 = (void *)0x0;
    }
    else {
      FUN_0083a3b0();
    }
    *(undefined4 *)((int)pvVar2 + 0x1a4) = *(undefined4 *)(in_ECX + 0x35810);
    *(void **)(in_ECX + 0x35810) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x35814) = *(undefined4 *)((int)pvVar2 + 0x1a0);
  }
  *(int *)((int)pvVar2 + 0x1a8) = param_1;
  *(undefined4 *)((int)pvVar2 + 0x1a0) = 0;
  FUN_00839870();
  return pvVar2;
}


// ==== FUN_0082dcd0 @ 0x0082dcd0 ====

undefined4 FUN_0082dcd0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1a8) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a0dda0,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1a8);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1a8);
    }
    FUN_00839600();
    *(undefined4 *)(param_2 + 0x1a0) = *(undefined4 *)(in_ECX + 0x35814);
    *(int *)(in_ECX + 0x3580c) = *(int *)(in_ECX + 0x3580c) + -1;
    *(int *)(in_ECX + 0x35814) = param_2;
  }
  return 0;
}


// ==== FUN_0082dd60 @ 0x0082dd60 ====

void FUN_0082dd60(byte param_1)

{
  void *in_ECX;
  
  FUN_0082dd80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082dd80 @ 0x0082dd80 ====

void FUN_0082dd80(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_00a0dd78;
  if (in_ECX[0xd603] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0dc2c,
                         s_d__usa_24_0_1_2__develop_module__00a0dbc0,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x6c;
  iVar3 = 0x200;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0dcac,
                           s_d__usa_24_0_1_2__develop_module__00a0dc40,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x6b;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0xd604];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_00a0dd70;
    iVar3 = 0x200;
    do {
      FUN_0083a2f0();
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *in_ECX = &PTR_FUN_00a0dd58;
    return;
  }
  if (*(int *)((int)_Memory + 0x1a8) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a0dd2c,
                         s_d__usa_24_0_1_2__develop_module__00a0dcc0,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_0083a2f0();
  _free(_Memory);
  return;
}


// ==== FUN_0082dea0 @ 0x0082dea0 ====

void FUN_0082dea0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0dd90;
  DAT_00b5d93c = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_00a0dd48;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082def0 @ 0x0082def0 ====

void FUN_0082def0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0de50;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082df10 @ 0x0082df10 ====

void FUN_0082df10(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999c60;
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


// ==== Catch@0082df9a @ 0x0082df9a ====

void Catch_0082df9a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_0082dfb0 @ 0x0082dfb0 ====

void FUN_0082dfb0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) != '\0') {
    return;
  }
  FUN_0082dfb0(*(undefined4 *)((int)param_1 + 8));
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


// ==== FUN_0082e010 @ 0x0082e010 ====

void * FUN_0082e010(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999c70;
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


// ==== Catch@0082e085 @ 0x0082e085 ====

void Catch_0082e085(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0082e0a0 @ 0x0082e0a0 ====

void FUN_0082e0a0(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  
  if ((param_1 != (int *)0x0) && (*(int *)(in_ECX + 0xc) != 0)) {
    uVar3 = (**(code **)(*param_1 + 4))();
    FUN_0069a470(&param_1,uVar3);
    piVar2 = param_1;
    if (param_1 != *(int **)(in_ECX + 8)) {
      puVar1 = (undefined4 *)param_1[10];
      iVar4 = FUN_0083a9f0();
      if ((iVar4 == 0) && (FUN_005a4100(&param_1,piVar2), puVar1 != (undefined4 *)0x0)) {
        (**(code **)*puVar1)(1);
      }
    }
  }
  return;
}


// ==== FUN_0082e100 @ 0x0082e100 ====

undefined4 FUN_0082e100(int param_1)

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
    FUN_0083a9e0();
    return uVar3;
  }
  pvVar2 = operator_new(0x8c);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0083ad20();
  }
  FUN_0083acd0(iVar1);
  FUN_0083a9e0();
  local_8 = 0xf;
  local_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401660(iVar1,0,0xffffffff);
  local_4 = uVar3;
  FUN_0082e500(local_28,local_20);
  if (local_8 < 0x10) {
    return uVar3;
  }
  _free(local_1c);
  return extraout_EAX;
}


// ==== FUN_0082e1c0 @ 0x0082e1c0 ====

void FUN_0082e1c0(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_00a0de60;
  DAT_00b5d930 = 0;
  FUN_0082e440(local_4,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0082e210 @ 0x0082e210 ====

void FUN_0082e210(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0de60;
  iVar1 = FUN_0082df10();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5d930 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5d930 = in_ECX;
  return;
}


// ==== FUN_0082e260 @ 0x0082e260 ====

void FUN_0082e260(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_0082e010(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_0082e365:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_0082e365;
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


// ==== FUN_0082e440 @ 0x0082e440 ====

void FUN_0082e440(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0082dfb0(piVar6[1]);
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


// ==== FUN_0082e500 @ 0x0082e500 ====

/* WARNING: Removing unreachable block (ram,0x0082e55f) */

void FUN_0082e500(undefined4 *param_1,undefined4 *param_2)

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
LAB_0082e590:
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
        if (uVar5 == 0) goto LAB_0082e590;
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
      puVar6 = (undefined4 *)FUN_0082e260(&param_2,1,puVar6,iVar3);
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
    puVar6 = (undefined4 *)FUN_0082e260(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_0082e670 @ 0x0082e670 ====

void FUN_0082e670(byte param_1)

{
  void *in_ECX;
  
  FUN_0082e1c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082e690 @ 0x0082e690 ====

void FUN_0082e690(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0deb0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082e6b0 @ 0x0082e6b0 ====

void FUN_0082e6b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0dec0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5afa4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5afa4 = in_ECX;
  return;
}


// ==== FUN_0082e6e0 @ 0x0082e6e0 ====

byte FUN_0082e6e0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5d958 + 0x10))(param_1);
  return -(iVar1 != 0) & 2;
}


// ==== FUN_0082e720 @ 0x0082e720 ====

bool FUN_0082e720(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  cVar1 = (**(code **)(*DAT_00b5d960 + 4))(param_1);
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*DAT_00b5d958 + 4))(param_1);
    if (cVar1 == '\0') {
      cVar1 = (**(code **)(*DAT_00b5d94c + 4))(param_1);
      if (cVar1 == '\0') {
        cVar1 = (**(code **)(*DAT_00b5d944 + 4))(param_1);
        if (cVar1 == '\0') {
          cVar1 = (**(code **)(*DAT_00b5ad24 + 4))(param_1);
          if (cVar1 == '\0') {
            cVar1 = (**(code **)(*DAT_00b5afdc + 4))(param_1);
            if (cVar1 == '\0') {
              cVar1 = (**(code **)(*DAT_00b5afd4 + 0x14))(param_1);
              if (cVar1 != '\x01') {
                piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
                iVar3 = (**(code **)(*piVar2 + 0x1c))();
                if (*(int *)(iVar3 + 4) == 1) {
                  return false;
                }
                cVar1 = (**(code **)(*DAT_00b5d938 + 4))(param_1);
                if (cVar1 == '\0') {
                  cVar1 = (**(code **)(*DAT_00b5d928 + 4))(param_1);
                  return cVar1 != '\0';
                }
              }
            }
          }
        }
      }
    }
  }
  return true;
}


// ==== FUN_0082e7f0 @ 0x0082e7f0 ====

void FUN_0082e7f0(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5afa4 = 0;
  *in_ECX = &PTR_FUN_00a0deb0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082e820 @ 0x0082e820 ====

void FUN_0082e820(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0df14;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082e860 @ 0x0082e860 ====

void FUN_0082e860(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0df2c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ad24 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ad24 = in_ECX;
  return;
}


// ==== FUN_0082e890 @ 0x0082e890 ====

int * FUN_0082e890(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5d948 + 4))();
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 4))(param_1);
    if (cVar1 == '\0') {
      (**(code **)(*DAT_00b5d948 + 8))();
      return (int *)0x0;
    }
    cVar1 = (**(code **)(*DAT_00b5d944 + 8))(piVar2);
    if (cVar1 != '\0') {
      return piVar2;
    }
    (**(code **)(*DAT_00b5d948 + 8))(piVar2);
  }
  return (int *)0x0;
}


// ==== FUN_0082e8f0 @ 0x0082e8f0 ====

undefined4 FUN_0082e8f0(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5d944 + 0xc))(param_1);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*piVar1 + 0xc))();
  (**(code **)(*DAT_00b5d948 + 8))(piVar1);
  return 1;
}


// ==== FUN_0082e930 @ 0x0082e930 ====

uint FUN_0082e930(int *param_1)

{
  uint in_EAX;
  undefined4 uVar1;
  uint uVar2;
  int *in_ECX;
  
  if (param_1 == (int *)0x0) {
    return in_EAX & 0xffffff00;
  }
  uVar1 = (**(code **)(*param_1 + 8))();
  uVar2 = (**(code **)(*in_ECX + 0x10))(uVar1);
  return uVar2;
}


// ==== FUN_0082e960 @ 0x0082e960 ====

void FUN_0082e960(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar2 = (**(code **)(*param_1 + 0x10))();
  piVar3 = (int *)(**(code **)(*DAT_00b5d944 + 0x10))(uVar2);
  if (piVar3 != (int *)0x0) {
    piVar4 = (int *)(**(code **)(*piVar3 + 0x3c))();
    if ((char)param_1[2] == '\0') {
      (**(code **)(*piVar4 + 0xc))();
      return;
    }
    iVar6 = param_1[6];
    iVar1 = param_1[5];
    piVar5 = (int *)(**(code **)(*piVar3 + 0x14))();
    iStack_28 = piVar5[1] + iVar6;
    iStack_20 = param_1[8];
    iStack_2c = *piVar5 + iVar1;
    iStack_24 = param_1[7];
    iStack_1c = param_1[4];
    iVar6 = (**(code **)(*piVar3 + 0x14))();
    iStack_18 = *(int *)(iVar6 + 0x20) + 1;
    iVar6 = (**(code **)(*piVar3 + 0x14))();
    uStack_14 = *(undefined4 *)(iVar6 + 0x10);
    uStack_10 = *(undefined4 *)(iVar6 + 0x14);
    uStack_c = *(undefined4 *)(iVar6 + 0x18);
    uStack_8 = *(undefined4 *)(iVar6 + 0x1c);
    (**(code **)(*piVar4 + 4))(&iStack_2c);
  }
  return;
}


// ==== FUN_0082ea30 @ 0x0082ea30 ====

void FUN_0082ea30(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = (**(code **)(*param_1 + 0x10))();
  piVar2 = (int *)(**(code **)(*DAT_00b5d944 + 0x10))(uVar1);
  if (piVar2 == (int *)0x0) {
    return;
  }
  piVar2 = (int *)(**(code **)(*piVar2 + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0082ea5f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar2 + 8))();
  return;
}


// ==== FUN_0082ea70 @ 0x0082ea70 ====

void FUN_0082ea70(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = (**(code **)(*param_1 + 0x10))();
  piVar2 = (int *)(**(code **)(*DAT_00b5d944 + 0x10))(uVar1);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
  }
  return;
}


// ==== FUN_0082eae0 @ 0x0082eae0 ====

void FUN_0082eae0(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined1 uStack00000000;
  
  uVar1 = (**(code **)(*param_1 + 0x10))();
  piVar2 = (int *)(**(code **)(*DAT_00b5d944 + 0x10))(uVar1);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x24))();
    (**(code **)(*piVar2 + 0x1c))(&uStack00000000);
  }
  return;
}


// ==== FUN_0082eb30 @ 0x0082eb30 ====

void FUN_0082eb30(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined1 auStack_6 [6];
  
  uVar1 = (**(code **)(*param_1 + 0x10))();
  piVar2 = (int *)(**(code **)(*DAT_00b5d944 + 0x10))(uVar1);
  if (piVar2 != (int *)0x0) {
    FUN_0040d0f0(param_1[2]);
    (**(code **)(*piVar2 + 0x18))(auStack_6 + -6);
  }
  return;
}


// ==== FUN_0082ebc0 @ 0x0082ebc0 ====

void FUN_0082ebc0(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined1 auStack_e [14];
  
  uVar1 = (**(code **)(*param_1 + 0x10))();
  piVar2 = (int *)(**(code **)(*DAT_00b5d944 + 0x10))(uVar1);
  if (piVar2 != (int *)0x0) {
    if (*(char *)((int)param_1 + 0x19) == '\0') {
      (**(code **)(*piVar2 + 0x58))();
      return;
    }
    piVar2 = (int *)(**(code **)(*piVar2 + 0x54))();
    (**(code **)(*piVar2 + 4))(auStack_e + -6,param_1[5]);
  }
  return;
}


// ==== FUN_0082ec40 @ 0x0082ec40 ====

void FUN_0082ec40(void)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5d944 + 0x14))();
  while (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x5c))();
    piVar1 = (int *)(**(code **)(*DAT_00b5d944 + 0x18))();
  }
  (**(code **)(*DAT_00b5d96c + 8))();
  (**(code **)(*DAT_00b5d970 + 8))();
  return;
}


// ==== FUN_0082eca0 @ 0x0082eca0 ====

void FUN_0082eca0(int param_1)

{
  int *piVar1;
  undefined2 *puVar2;
  undefined1 auStack_32 [46];
  undefined1 uStack_4;
  undefined1 uStack_3;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5d944 + 0x10))(*(undefined4 *)(param_1 + 4));
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x20))(auStack_32 + -6);
    puVar2 = (undefined2 *)(**(code **)(*piVar1 + 0x24))();
    _uStack_4 = CONCAT11((char)((ushort)*puVar2 >> 8),*(undefined1 *)(param_1 + 8));
    (**(code **)(*piVar1 + 0x1c))(&uStack_4);
  }
  return;
}


// ==== FUN_0082ed50 @ 0x0082ed50 ====

void FUN_0082ed50(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar2 = (**(code **)(*param_1 + 0x10))();
  piVar3 = (int *)(**(code **)(*DAT_00b5d944 + 0x10))(uVar2);
  if (piVar3 != (int *)0x0) {
    piVar4 = (int *)(**(code **)(*piVar3 + 0x34))();
    if ((char)param_1[2] == '\0') {
      (**(code **)(*piVar4 + 0xc))();
      return;
    }
    iVar6 = param_1[6];
    iVar1 = param_1[5];
    piVar5 = (int *)(**(code **)(*piVar3 + 0x14))();
    iStack_28 = piVar5[1] + iVar6;
    iStack_20 = param_1[8];
    iStack_2c = *piVar5 + iVar1;
    iStack_24 = param_1[7];
    iStack_1c = param_1[4];
    iVar6 = (**(code **)(*piVar3 + 0x14))();
    iStack_18 = *(int *)(iVar6 + 0x20) + 1;
    iVar6 = (**(code **)(*piVar3 + 0x14))();
    uStack_14 = *(undefined4 *)(iVar6 + 0x10);
    uStack_10 = *(undefined4 *)(iVar6 + 0x14);
    uStack_c = *(undefined4 *)(iVar6 + 0x18);
    uStack_8 = *(undefined4 *)(iVar6 + 0x1c);
    (**(code **)(*piVar4 + 4))(&iStack_2c);
  }
  return;
}


// ==== FUN_0082ee20 @ 0x0082ee20 ====

void FUN_0082ee20(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  
  uVar2 = (**(code **)(*param_1 + 0x10))();
  piVar3 = (int *)(**(code **)(*DAT_00b5d944 + 0x10))(uVar2);
  if (piVar3 != (int *)0x0) {
    piVar3 = (int *)(**(code **)(*piVar3 + 0x44))();
    (**(code **)(*piVar3 + 8))();
    while (param_1[6] != 0) {
      uVar4 = (uint)param_1[5] >> 2;
      iVar1 = uVar4 * -4;
      if ((uint)param_1[4] <= uVar4) {
        uVar4 = uVar4 - param_1[4];
      }
      iVar1 = *(int *)(*(int *)(param_1[3] + uVar4 * 4) + (param_1[5] + iVar1) * 4);
      if (param_1[6] != 0) {
        param_1[5] = param_1[5] + 1;
        if ((uint)(param_1[4] * 4) <= (uint)param_1[5]) {
          param_1[5] = 0;
        }
        iVar5 = param_1[6] + -1;
        param_1[6] = iVar5;
        if (iVar5 == 0) {
          param_1[5] = 0;
        }
      }
      if (iVar1 == 0) {
        return;
      }
      (**(code **)(*piVar3 + 4))(iVar1);
    }
  }
  return;
}


// ==== FUN_0082eec0 @ 0x0082eec0 ====

void FUN_0082eec0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined2 auStack_54 [2];
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  undefined1 uStack_40;
  undefined1 uStack_3f;
  void *pvStack_3c;
  void *pvStack_38;
  uint uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  uVar5 = (**(code **)(*param_1 + 0x10))();
  piVar6 = (int *)(**(code **)(*DAT_00b5d944 + 0x10))(uVar5);
  if (piVar6 != (int *)0x0) {
    uStack_24 = 0xf;
    uStack_28 = 0;
    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    FUN_00401660(param_1 + 6,0,0xffffffff);
    if (uStack_28 < 10) {
      if (0xf < uStack_24) {
        _free(pvStack_38);
        return;
      }
    }
    else {
      iVar1 = param_1[4];
      iVar2 = param_1[5];
      iVar3 = param_1[3];
      iVar4 = param_1[2];
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      FUN_00401660(&pvStack_3c,5,uStack_28 - 9);
      auStack_54[0] = FUN_00796f80(auStack_20);
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return;
      }
      piVar6 = (int *)(**(code **)(*piVar6 + 0x2c))();
      uStack_40 = (undefined1)param_1[0xd];
      uStack_3f = *(undefined1 *)((int)param_1 + 0x35);
      iStack_50 = iVar4;
      iStack_4c = iVar3;
      iStack_48 = iVar1 + iVar4;
      iStack_44 = iVar2 + iVar3;
      (**(code **)(*piVar6 + 4))(auStack_54);
      if (0xf < uStack_28) {
        _free(pvStack_3c);
        return;
      }
    }
  }
  return;
}


// ==== FUN_0082f000 @ 0x0082f000 ====

/* WARNING: Removing unreachable block (ram,0x0082f0aa) */

void FUN_0082f000(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined1 auStack_3a [58];
  
  uVar1 = (**(code **)(*param_1 + 0x10))();
  piVar2 = (int *)(**(code **)(*DAT_00b5d944 + 0x10))(uVar1);
  if (piVar2 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*piVar2 + 0x4c))();
    (**(code **)(*piVar2 + 0xc))();
    FUN_00401660(param_1 + 10,0,0xffffffff);
    (**(code **)(*piVar2 + 4))(auStack_3a + -6);
  }
  return;
}


// ==== FUN_0082f0c0 @ 0x0082f0c0 ====

void FUN_0082f0c0(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  undefined1 auStack_16 [22];
  
  uVar1 = (**(code **)(*param_1 + 0x10))();
  piVar2 = (int *)(**(code **)(*DAT_00b5d944 + 0x10))(uVar1);
  if (piVar2 != (int *)0x0) {
    if ((param_1[3] == 0) || ((param_1[4] - param_1[3]) / 0x18 == 0)) {
      (**(code **)(*piVar2 + 0x50))();
      return;
    }
    piVar2 = (int *)(**(code **)(*piVar2 + 0x4c))();
    (**(code **)(*piVar2 + 0xc))();
    for (uVar3 = 0; (param_1[3] != 0 && (uVar3 < (uint)((param_1[4] - param_1[3]) / 0x18)));
        uVar3 = uVar3 + 1) {
      if ((param_1[3] == 0) || ((uint)((param_1[4] - param_1[3]) / 0x18) <= uVar3)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      (**(code **)(*piVar2 + 8))(auStack_16 + -6);
    }
  }
  return;
}


// ==== FUN_0082f1e0 @ 0x0082f1e0 ====

undefined4 FUN_0082f1e0(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int *piVar3;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 < 0x60000024) {
    if (uVar1 == 0x60000023) {
      uVar2 = (**(code **)(*param_1 + 0x10))();
      piVar3 = (int *)(**(code **)(*DAT_00b5d944 + 0x10))(uVar2);
      if (piVar3 == (int *)0x0) {
        return 1;
      }
      piVar3 = (int *)(**(code **)(*piVar3 + 0x2c))();
      (**(code **)(*piVar3 + 0xc))(param_1[2]);
      return 1;
    }
    switch(uVar1) {
    case 0x60000002:
      FUN_0082eca0(param_1);
      return 1;
    case 0x60000003:
      FUN_0082ee20(param_1);
      return 1;
    case 0x60000010:
      FUN_0082ed50(param_1);
      return 1;
    case 0x60000011:
      FUN_0082e960(param_1);
      return 1;
    case 0x60000020:
      FUN_0082eec0(param_1);
      return 1;
    case 0x60000021:
      FUN_0082ea30(param_1);
      return 1;
    case 0x60000022:
      FUN_0082ea70(param_1);
      return 1;
    }
  }
  else if (uVar1 < 0x60000046) {
    if (uVar1 == 0x60000045) {
      FUN_0082f000(param_1);
      return 1;
    }
    if (uVar1 == 0x60000030) {
      FUN_0082eae0(param_1);
      return 1;
    }
    if (uVar1 == 0x60000040) {
      FUN_0082f0c0(param_1);
      return 1;
    }
    if (uVar1 == 0x60000041) {
      FUN_0082eb30(param_1);
      return 1;
    }
  }
  else {
    if (uVar1 == 0x60000050) {
      FUN_0082ebc0(param_1);
      return 1;
    }
    if (uVar1 == 0x60010010) {
      FUN_0082ec40(param_1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0082f390 @ 0x0082f390 ====

void FUN_0082f390(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5ad24 = 0;
  *in_ECX = &PTR_FUN_00a0df14;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082f3c0 @ 0x0082f3c0 ====

void FUN_0082f3c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0df84;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082f3e0 @ 0x0082f3e0 ====

int FUN_0082f3e0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999c80;
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


// ==== Catch@0082f446 @ 0x0082f446 ====

void Catch_0082f446(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0082f450 @ 0x0082f450 ====

void FUN_0082f450(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999c90;
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


// ==== Catch@0082f4bf @ 0x0082f4bf ====

void Catch_0082f4bf(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0082f4e0 @ 0x0082f4e0 ====

void * FUN_0082f4e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999ca0;
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


// ==== Catch@0082f54d @ 0x0082f54d ====

void Catch_0082f54d(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0082f570 @ 0x0082f570 ====

void FUN_0082f570(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999cb0;
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


// ==== Catch@0082f5d6 @ 0x0082f5d6 ====

void Catch_0082f5d6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0082f5e0 @ 0x0082f5e0 ====

void FUN_0082f5e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0082f3e0(param_1,param_2,param_3);
  return;
}


// ==== FUN_0082f600 @ 0x0082f600 ====

undefined4 FUN_0082f600(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x14) == 0) {
    return 0;
  }
  iVar1 = **(int **)(in_ECX + 0x10);
  *(int *)(in_ECX + 4) = iVar1;
  return *(undefined4 *)(iVar1 + 0xc);
}


// ==== FUN_0082f620 @ 0x0082f620 ====

undefined4 FUN_0082f620(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x14) != 0) && (*(int **)(in_ECX + 4) != *(int **)(in_ECX + 0x10))) {
    iVar1 = **(int **)(in_ECX + 4);
    *(int *)(in_ECX + 4) = iVar1;
    if (iVar1 != *(int *)(in_ECX + 0x10)) {
      return *(undefined4 *)(iVar1 + 0xc);
    }
  }
  return 0;
}


// ==== FUN_0082f680 @ 0x0082f680 ====

uint FUN_0082f680(int *param_1)

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
  puVar1 = *(undefined4 **)(in_ECX + 0x10);
  iVar2 = param_1[1];
  uVar4 = 0x40001;
  for (puVar3 = (undefined4 *)*puVar1; puVar3 != puVar1; puVar3 = (undefined4 *)*puVar3) {
    uVar4 = (**(code **)(*(int *)puVar3[3] + 0x10))(iVar2);
  }
  return uVar4 & 0xffffff00;
}


// ==== FUN_0082f6d0 @ 0x0082f6d0 ====

undefined4 FUN_0082f6d0(undefined1 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0x10)) {
    return 0;
  }
  uVar1 = *(undefined4 *)(local_4 + 0xc);
  FUN_00598f60(&param_1,local_4);
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 0x10);
  return uVar1;
}


// ==== FUN_0082f720 @ 0x0082f720 ====

undefined4 FUN_0082f720(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0x10)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0xc);
}


// ==== FUN_0082f750 @ 0x0082f750 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0082f750(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_00a0dfa4;
  puVar1 = in_ECX + 1;
  *puVar1 = 0;
  *(undefined1 *)(in_ECX + 2) = local_5;
  uVar2 = FUN_0082f450();
  in_ECX[4] = uVar2;
  in_ECX[5] = 0;
  local_4 = in_ECX[4];
  FUN_0082fb60(9,&local_4);
  in_ECX[10] = 1;
  in_ECX[0xb] = 1;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5d944 = (undefined4 *)0x0;
    _DAT_00000000 = in_ECX[4];
    return;
  }
  DAT_00b5d944 = in_ECX;
  *puVar1 = in_ECX[4];
  return;
}


// ==== FUN_0082f7e0 @ 0x0082f7e0 ====

void FUN_0082f7e0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  void *_Memory;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0dfa4;
  DAT_00b5d944 = 0;
  puVar1 = (undefined4 *)in_ECX[4];
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    piVar3 = (int *)puVar2[3];
    (**(code **)(*piVar3 + 0xc))();
    (**(code **)(*DAT_00b5d948 + 8))(piVar3);
  }
  FUN_0082ff00();
  in_ECX[1] = in_ECX[4];
  if ((void *)in_ECX[7] != (void *)0x0) {
    _free((void *)in_ECX[7]);
    return;
  }
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  puVar1 = (undefined4 *)in_ECX[4];
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(undefined4 *)(in_ECX[4] + 4) = in_ECX[4];
  in_ECX[5] = 0;
  if (_Memory == (void *)in_ECX[4]) {
    _free((void *)in_ECX[4]);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_0082f890 @ 0x0082f890 ====

uint FUN_0082f890(int *param_1)

{
  uint in_EAX;
  int in_ECX;
  undefined4 uStack_10;
  int *piStack_c;
  undefined1 auStack_8 [4];
  undefined1 uStack_4;
  
  if (param_1 == (int *)0x0) {
    return in_EAX & 0xffffff00;
  }
  uStack_10 = (**(code **)(*param_1 + 8))();
  piStack_c = param_1;
  FUN_0082fcd0(auStack_8,&uStack_10);
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 0x10);
  return CONCAT31((int3)((uint)*(undefined4 *)(in_ECX + 0x10) >> 8),uStack_4);
}


// ==== FUN_0082f8e0 @ 0x0082f8e0 ====

int FUN_0082f8e0(int param_1,int param_2,undefined4 param_3)

{
  FUN_0082f570(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_0082f910 @ 0x0082f910 ====

void FUN_0082f910(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00999cc0;
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
      uVar5 = FUN_0082f5e0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_0082f8e0(uVar5,param_2,&local_18);
      FUN_0082f5e0(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_0082f3e0(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_0082f8e0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_0082f3e0(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0082fa71 @ 0x0082fa71 ====

void Catch_0082fa71(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0082fb60 @ 0x0082fb60 ====

void FUN_0082fb60(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999cd0;
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
    uVar2 = FUN_0082f8e0(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0082fbf4 @ 0x0082fbf4 ====

void Catch_0082fbf4(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0082fc10 @ 0x0082fc10 ====

void FUN_0082fc10(uint param_1,undefined1 param_2)

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
    FUN_0082f910(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_0082fc80 @ 0x0082fc80 ====

/* WARNING: Removing unreachable block (ram,0x0082fc9b) */
/* WARNING: Removing unreachable block (ram,0x0082fca0) */
/* WARNING: Removing unreachable block (ram,0x0082fcae) */

void FUN_0082fc80(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_0082f910(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_0082fcd0 @ 0x0082fcd0 ====

/* WARNING: Removing unreachable block (ram,0x0082fdb8) */

void FUN_0082fcd0(int *param_1,uint *param_2)

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
      FUN_0082fc10(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
  iVar5 = FUN_0082f4e0(puVar7,puVar7[1],param_2);
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


// ==== FUN_0082ff00 @ 0x0082ff00 ====

void FUN_0082ff00(void)

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
    FUN_0082fc80(9,&local_4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_0082ff60 @ 0x0082ff60 ====

void FUN_0082ff60(byte param_1)

{
  void *in_ECX;
  
  FUN_0082f7e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082ff80 @ 0x0082ff80 ====

void FUN_0082ff80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0e184;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0082ffa0 @ 0x0082ffa0 ====

void FUN_0082ffa0(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0082ffc0 @ 0x0082ffc0 ====

void FUN_0082ffc0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  return;
}


// ==== FUN_0082ffd0 @ 0x0082ffd0 ====

void FUN_0082ffd0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  puVar1 = in_ECX + 1;
  *in_ECX = &PTR_FUN_00a0e1cc;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5d948 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5d948 = in_ECX;
  }
  pvVar2 = operator_new(0x8818);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    return;
  }
  uVar3 = FUN_008300b0();
  *puVar1 = uVar3;
  return;
}


