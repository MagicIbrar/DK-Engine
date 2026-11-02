// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x4d0000-0x4dffff

// ==== FUN_004d00c0 @ 0x004d00c0 ====

void FUN_004d00c0(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x20) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x20) = 0;
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined4 *)(in_ECX + 0x28) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x20));
  return;
}


// ==== FUN_004d00f0 @ 0x004d00f0 ====

void FUN_004d00f0(void *param_1,int param_2,int param_3)

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
  puStack_c = &LAB_00980e20;
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


// ==== Catch@004d0261 @ 0x004d0261 ====

void Catch_004d0261(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x1c));
  return;
}


// ==== FUN_004d0340 @ 0x004d0340 ====

void FUN_004d0340(undefined4 *param_1,ushort *param_2)

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
      puVar4 = (undefined4 *)FUN_004cf8a0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (*(ushort *)((int)param_2 + 0xc) < *puVar2) {
    puVar4 = (undefined4 *)FUN_004cf8a0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004d0400 @ 0x004d0400 ====

void FUN_004d0400(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980e30;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x71c71c7 < param_1) {
    ExceptionList = &local_10;
    FUN_004cfaf0();
  }
  uVar1 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    uVar1 = (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4)) / 0x24;
  }
  if (uVar1 < param_1) {
    pvVar2 = operator_new(param_1 * 0x24);
    local_8 = 0;
    FUN_004cf5b0(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar2);
    if (*(void **)(in_ECX + 4) != (void *)0x0) {
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x24 + (int)pvVar2);
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 4) = pvVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004d04d4 @ 0x004d04d4 ====

void Catch_004d04d4(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 8));
  return;
}


// ==== FUN_004d04f0 @ 0x004d04f0 ====

void FUN_004d04f0(void *param_1,uint param_2,undefined4 *param_3)

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
      uVar7 = FUN_004abe90();
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


// ==== FUN_004d06d0 @ 0x004d06d0 ====

void FUN_004d06d0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x24 != 0) {
      iVar1 = (param_2 - iVar1) / 0x24;
      goto LAB_004d0715;
    }
  }
  iVar1 = 0;
LAB_004d0715:
  FUN_004cfb60(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x24;
  return;
}


// ==== FUN_004d0740 @ 0x004d0740 ====

void FUN_004d0740(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004cf640(piVar6[1]);
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
    FUN_004cfe10(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004d0800 @ 0x004d0800 ====

void FUN_004d0800(int param_1,uint param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00980e48;
  local_10 = ExceptionList;
  local_34 = *(undefined4 *)(param_3 + 4);
  local_20 = *(undefined4 *)(param_3 + 0x18);
  local_30 = *(undefined4 *)(param_3 + 8);
  local_2c = *(undefined4 *)(param_3 + 0xc);
  local_28 = *(undefined4 *)(param_3 + 0x10);
  local_24 = *(undefined4 *)(param_3 + 0x14);
  local_14 = (undefined1 *)((int)register0x00000010 + -0x44);
  local_38 = &PTR_FUN_009b0e80;
  iVar2 = *(int *)(in_ECX + 4);
  uVar5 = 0;
  local_8 = 0;
  if (iVar2 != 0) {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x1c;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x1c;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x44);
    if (0x9249249U - iVar2 < param_2) {
      ExceptionList = &local_10;
      FUN_004abe90();
      uVar5 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
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
      iVar2 = FUN_004cf5e0(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_004cf6b0(iVar2,param_2,&local_38);
      FUN_004cf5e0(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x1c);
      local_8 = 0;
      iVar2 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x1c;
      }
      if (*(int *)(in_ECX + 4) == 0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x1c + (int)pvVar3);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar2) * 0x1c);
        *(void **)(in_ECX + 4) = pvVar3;
        ExceptionList = local_10;
        return;
      }
      FUN_004abcf0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
      _free(*(void **)(in_ECX + 4));
      return;
    }
    local_1c = *(int *)(in_ECX + 8);
    if ((uint)((local_1c - param_1) / 0x1c) < param_2) {
      FUN_004cf5e0(param_1,local_1c,param_2 * 0x1c + param_1);
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_004cf7e0(*(undefined4 *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x1c,
                   &local_38);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x1c;
      FUN_004cf560(param_1,*(int *)(in_ECX + 8) + param_2 * -0x1c,&local_38);
      ExceptionList = local_10;
      return;
    }
    iVar2 = local_1c + param_2 * -0x1c;
    uVar4 = FUN_004cf5e0(iVar2,local_1c,local_1c);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_004cf3f0(param_1,iVar2,local_1c,param_1);
    FUN_004cf560(param_1,param_2 * 0x1c + param_1,&local_38);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004d0a13 @ 0x004d0a13 ====

void Catch_004d0a13(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + 0x10);
  FUN_004abcf0(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@004d0add @ 0x004d0add ====

void Catch_004d0add(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x1c;
  FUN_004abcf0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004d0b60 @ 0x004d0b60 ====

/* WARNING: Removing unreachable block (ram,0x004d0c70) */
/* WARNING: Removing unreachable block (ram,0x004d0c81) */
/* WARNING: Removing unreachable block (ram,0x004d0c8a) */
/* WARNING: Removing unreachable block (ram,0x004d0c8d) */
/* WARNING: Removing unreachable block (ram,0x004d0c7d) */
/* WARNING: Removing unreachable block (ram,0x004d0c9b) */
/* WARNING: Removing unreachable block (ram,0x004d0ca8) */
/* WARNING: Removing unreachable block (ram,0x004d0cb3) */
/* WARNING: Removing unreachable block (ram,0x004d0caf) */
/* WARNING: Removing unreachable block (ram,0x004d0ca3) */
/* WARNING: Removing unreachable block (ram,0x004d0cb6) */

void FUN_004d0b60(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00980fe8;
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
            goto LAB_004d0d87;
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
LAB_004d0d87:
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


// ==== FUN_004d0e30 @ 0x004d0e30 ====

void FUN_004d0e30(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_004d00f0(param_1,param_2,param_3,param_3);
  return;
}


// ==== FUN_004d0e50 @ 0x004d0e50 ====

void FUN_004d0e50(uint param_1,undefined1 param_2)

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
    FUN_004d04f0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if (((iVar2 != 0) && (pvVar3 = *(void **)(in_ECX + 8), param_1 < (uint)((int)pvVar3 - iVar2 >> 2))
      ) && (_Dst = (void *)(iVar2 + param_1 * 4), _Dst != pvVar3)) {
    pvVar3 = _memmove(_Dst,pvVar3,0);
    *(void **)(in_ECX + 8) = pvVar3;
  }
  return;
}


// ==== FUN_004d0ee0 @ 0x004d0ee0 ====

void FUN_004d0ee0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x24) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x24))) {
    FUN_004d06d0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_004cf680(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x24;
  return;
}


// ==== FUN_004d0f70 @ 0x004d0f70 ====

void FUN_004d0f70(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980e60;
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
      uVar1 = FUN_004abe90();
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


// ==== Catch@004d1016 @ 0x004d1016 ====

void Catch_004d1016(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004d1030 @ 0x004d1030 ====

void FUN_004d1030(void *param_1)

{
  if (*(char *)((int)param_1 + 0x21) == '\0') {
    FUN_004d1030(*(undefined4 *)((int)param_1 + 8));
    FUN_0081f240();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004d1070 @ 0x004d1070 ====

void FUN_004d1070(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x1c != 0) {
      iVar1 = (param_2 - iVar1) / 0x1c;
      goto LAB_004d10b9;
    }
  }
  iVar1 = 0;
LAB_004d10b9:
  FUN_004d0800(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x1c;
  return;
}


// ==== FUN_004d10f0 @ 0x004d10f0 ====

void FUN_004d10f0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  return;
}


// ==== FUN_004d1140 @ 0x004d1140 ====

void FUN_004d1140(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_004d04f0(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_004d1190 @ 0x004d1190 ====

void FUN_004d1190(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x1c) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x1c))) {
    FUN_004d1070(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_004cf6b0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x1c;
  return;
}


// ==== FUN_004d1220 @ 0x004d1220 ====

void FUN_004d1220(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004d1030(piVar6[1]);
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
    FUN_004d0b60(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004d12e0 @ 0x004d12e0 ====

/* WARNING: Removing unreachable block (ram,0x004d13f0) */
/* WARNING: Removing unreachable block (ram,0x004d1401) */
/* WARNING: Removing unreachable block (ram,0x004d140a) */
/* WARNING: Removing unreachable block (ram,0x004d140d) */
/* WARNING: Removing unreachable block (ram,0x004d13fd) */
/* WARNING: Removing unreachable block (ram,0x004d141b) */
/* WARNING: Removing unreachable block (ram,0x004d1428) */
/* WARNING: Removing unreachable block (ram,0x004d1433) */
/* WARNING: Removing unreachable block (ram,0x004d142f) */
/* WARNING: Removing unreachable block (ram,0x004d1423) */
/* WARNING: Removing unreachable block (ram,0x004d1436) */

void FUN_004d12e0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00980fe8;
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
            goto LAB_004d1507;
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
LAB_004d1507:
            *(undefined1 *)(piVar5 + 0xb) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xb) = 1;
  }
  if ((void *)param_2[8] == (void *)0x0) {
    param_2[8] = 0;
    param_2[9] = 0;
    param_2[10] = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[8]);
  return;
}


// ==== FUN_004d15b0 @ 0x004d15b0 ====

void FUN_004d15b0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004d0740(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004d15e0 @ 0x004d15e0 ====

void FUN_004d15e0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) == '\0') {
    FUN_004d15e0(*(undefined4 *)((int)param_1 + 8));
    FUN_004d00c0();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004d1620 @ 0x004d1620 ====

undefined4 *
FUN_004d1620(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980fb1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x24);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[3] = *param_4;
    FUN_00430c20(param_4 + 1);
    *(undefined1 *)(puVar1 + 8) = param_5;
    *(undefined1 *)((int)puVar1 + 0x21) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@004d16a6 @ 0x004d16a6 ====

void Catch_004d16a6(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004d16c0 @ 0x004d16c0 ====

void FUN_004d16c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = *param_4;
  _eh_vector_copy_constructor_iterator_(in_ECX + 4,param_4 + 1,0x10,2,FUN_004d0f70,FUN_00412dc0);
  in_ECX[0xc] = param_4[9];
  in_ECX[0xd] = param_4[10];
  in_ECX[0xe] = param_4[0xb];
  in_ECX[0xf] = param_4[0xc];
  *(undefined1 *)(in_ECX + 0x10) = param_5;
  *(undefined1 *)((int)in_ECX + 0x41) = 0;
  return;
}


// ==== FUN_004d1730 @ 0x004d1730 ====

void FUN_004d1730(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00980fe8;
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
  piVar4 = (int *)FUN_004d1620(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_004d1829:
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
      if ((char)piVar6[8] == '\0') goto LAB_004d1829;
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


// ==== FUN_004d1910 @ 0x004d1910 ====

void FUN_004d1910(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004d15e0(piVar6[1]);
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
    FUN_004d12e0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004d19d0 @ 0x004d19d0 ====

void * FUN_004d19d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980fd1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x44);
  local_8 = 1;
  if (pvVar1 != (void *)0x0) {
    FUN_004d16c0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@004d1a42 @ 0x004d1a42 ====

void Catch_004d1a42(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004d1a60 @ 0x004d1a60 ====

void FUN_004d1a60(void)

{
  undefined4 *in_ECX;
  
  if ((void *)in_ECX[4] == (void *)0x0) {
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    FUN_004d15e0(*(undefined4 *)(in_ECX[0xc] + 4));
    *(undefined4 *)(in_ECX[0xc] + 4) = in_ECX[0xc];
    in_ECX[0xd] = 0;
    *(undefined4 *)in_ECX[0xc] = in_ECX[0xc];
    *(undefined4 *)(in_ECX[0xc] + 8) = in_ECX[0xc];
    *in_ECX = 0;
    in_ECX[1] = 0;
    *(undefined1 *)(in_ECX + 0x2f) = 0;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_004d1ac0 @ 0x004d1ac0 ====

void FUN_004d1ac0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004d1220(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004d1af0 @ 0x004d1af0 ====

void FUN_004d1af0(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_004d1730(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_004ddea0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_004d1730(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004d1bb0 @ 0x004d1bb0 ====

void FUN_004d1bb0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00980fe8;
  local_c = ExceptionList;
  if (0x4ec4ec2 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004d19d0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x40);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x40) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x10] == '\0') {
LAB_004d1ca9:
        *(undefined1 *)(*piVar5 + 0x40) = 1;
        *(undefined1 *)(piVar6 + 0x10) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x40) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_004cf450(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x40) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x40) = 0;
        FUN_004cf4a0(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x10] == '\0') goto LAB_004d1ca9;
      if (piVar7 == (int *)*piVar2) {
        FUN_004cf4a0(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x40) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x40) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x41) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x40);
  } while( true );
}


// ==== FUN_004d1d90 @ 0x004d1d90 ====

void FUN_004d1d90(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x41) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x41) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_004d1bb0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_004cf500();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_004d1bb0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004d1e50 @ 0x004d1e50 ====

void FUN_004d1e50(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004d1910(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004d1e80 @ 0x004d1e80 ====

void FUN_004d1e80(void)

{
  int in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098102c;
  pvStack_c = ExceptionList;
  local_4 = 3;
  ExceptionList = &pvStack_c;
  _eh_vector_destructor_iterator_((void *)(in_ECX + 0x44),0x3c,2,FUN_004cf840);
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_004d1220(local_10,**(undefined4 **)(in_ECX + 0x3c),*(undefined4 **)(in_ECX + 0x3c));
  _free(*(void **)(in_ECX + 0x3c));
  return;
}


// ==== FUN_004d1f60 @ 0x004d1f60 ====

void FUN_004d1f60(void)

{
  int iVar1;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098106c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  local_4 = 1;
  iVar1 = FUN_004a37b0();
  *(int *)(in_ECX + 0x30) = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(int *)(*(int *)(in_ECX + 0x30) + 4) = *(int *)(in_ECX + 0x30);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(in_ECX + 0x30);
  *(int *)(*(int *)(in_ECX + 0x30) + 8) = *(int *)(in_ECX + 0x30);
  *(undefined4 *)(in_ECX + 0x34) = 0;
  local_4._0_1_ = 2;
  iVar1 = FUN_004be360();
  *(int *)(in_ECX + 0x3c) = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(int *)(*(int *)(in_ECX + 0x3c) + 4) = *(int *)(in_ECX + 0x3c);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)(in_ECX + 0x3c);
  *(int *)(*(int *)(in_ECX + 0x3c) + 8) = *(int *)(in_ECX + 0x3c);
  *(undefined4 *)(in_ECX + 0x40) = 0;
  local_4 = CONCAT31(local_4._1_3_,3);
  _eh_vector_constructor_iterator_((void *)(in_ECX + 0x44),0x3c,2,FUN_004d10f0,FUN_004cf840);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004d2020 @ 0x004d2020 ====

void FUN_004d2020(byte param_1)

{
  void *in_ECX;
  
  FUN_004cf320();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d2040 @ 0x004d2040 ====

uint FUN_004d2040(int param_1,int *param_2)

{
  int iVar1;
  
  param_1 = param_1 - (int)param_2;
  iVar1 = 0;
  do {
    if (*(int *)(param_1 + (int)param_2) != *param_2) {
      return (uint)param_2 & 0xffffff00;
    }
    iVar1 = iVar1 + 1;
    param_2 = param_2 + 1;
  } while (iVar1 < 4);
  return CONCAT31((int3)((uint)param_2 >> 8),1);
}


// ==== FUN_004d2070 @ 0x004d2070 ====

void FUN_004d2070(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  param_1[2] = param_1[3];
  param_1[1] = uVar3;
  *param_1 = uVar2;
  param_1[3] = uVar1;
  return;
}


// ==== FUN_004d20a0 @ 0x004d20a0 ====

undefined4 FUN_004d20a0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_1;
  iVar1 = 1;
  while (param_1[iVar1] == iVar3) {
    iVar1 = iVar1 + 1;
    if (3 < iVar1) {
      switch(iVar3) {
      default:
        return 0;
      case 1:
        return 1;
      case 2:
        return 2;
      case 3:
        return 3;
      }
    }
  }
  iVar1 = param_1[iVar1];
  iVar2 = iVar1;
  if (iVar1 < iVar3) {
    iVar2 = iVar3;
    iVar3 = iVar1;
  }
  if (iVar3 == 0) {
    if (iVar2 == 1) {
      return 4;
    }
    if (iVar2 == 2) {
      return 5;
    }
    if (iVar2 == 3) {
      return 6;
    }
  }
  else if (iVar3 != 1) {
    if (iVar3 != 2) {
      return 0;
    }
    if (iVar2 == 3) {
      return 9;
    }
    return 0;
  }
  if (iVar2 == 2) {
    return 7;
  }
  if (iVar2 == 3) {
    return 8;
  }
  return 0;
}


// ==== FUN_004d2150 @ 0x004d2150 ====

undefined4 FUN_004d2150(undefined4 *param_1)

{
  switch(*param_1) {
  default:
    return 0;
  case 7:
  case 8:
  case 9:
    return 1;
  }
}


// ==== FUN_004d21b0 @ 0x004d21b0 ====

/* WARNING: Removing unreachable block (ram,0x004d22f6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d21b0(undefined4 param_1,int param_2,int param_3,uint param_4,uint *param_5)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float fVar6;
  undefined4 *puStack_310;
  undefined1 *puStack_30c;
  undefined1 *puStack_308;
  undefined4 *puStack_304;
  undefined1 *puStack_300;
  undefined1 *puStack_2fc;
  undefined1 *puStack_2f8;
  float *local_2f4;
  float local_2c0 [6];
  undefined4 local_2a8;
  undefined4 local_2a4;
  undefined4 local_2a0;
  undefined4 local_29c;
  float local_298 [7];
  undefined1 auStack_27c [12];
  undefined1 auStack_270 [12];
  undefined4 auStack_264 [25];
  undefined1 local_200 [40];
  undefined4 auStack_1d8 [3];
  undefined1 auStack_1cc [64];
  undefined4 auStack_18c [3];
  undefined1 local_180 [40];
  undefined1 auStack_158 [24];
  undefined1 local_140 [52];
  undefined4 auStack_10c [13];
  undefined4 auStack_d8 [19];
  undefined1 auStack_8c [12];
  undefined1 local_80 [28];
  undefined4 auStack_64 [3];
  undefined1 auStack_58 [8];
  int iStack_50;
  
  fVar6 = DAT_0099d080 / (float)(ushort)param_5[1];
  param_2 = param_2 - *param_5 % param_4;
  fVar1 = (float)param_2;
  if (param_2 < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  param_3 = param_3 - *param_5 / param_4;
  fVar2 = (float)param_3;
  if (param_3 < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  local_2f4 = (float *)0x0;
  puStack_2f8 = (undefined1 *)0xbf000000;
  fVar2 = DAT_0099d080 - fVar2 * fVar6;
  puStack_2fc = (undefined1 *)0xbf000000;
  puStack_300 = local_200;
  puStack_304 = (undefined4 *)0x4d227f;
  thunk_FUN_0079f7f5();
  local_298[4] = 0.0;
  local_298[3] = 0.0;
  local_298[2] = 0.0;
  local_298[1] = 0.0;
  local_29c = 0;
  local_2a0 = 0;
  local_2a4 = 0;
  local_2a8 = 0;
  local_2c0[4] = 0.0;
  local_2c0[3] = 0.0;
  local_2c0[2] = 0.0;
  local_2c0[1] = 0.0;
  local_298[5] = DAT_0099d080;
  local_298[0] = DAT_0099d080;
  local_2c0[5] = DAT_0099d080;
  local_2c0[0] = DAT_0099d080;
  if ((*(ushort *)((int)param_5 + 6) & 1) == 1) {
    local_2c0[0] = DAT_0099d0dc;
  }
  local_2f4 = (float *)((float)(ushort)param_5[2] * DAT_009b0eb8);
  puStack_2f8 = local_80;
  puStack_2fc = (undefined1 *)0x4d2331;
  thunk_FUN_0079f9c8();
  local_2f4 = (float *)0x0;
  puStack_2f8 = (undefined1 *)0x3f000000;
  puStack_2fc = (undefined1 *)0x3f000000;
  puStack_300 = local_140;
  puStack_304 = (undefined4 *)0x4d234a;
  thunk_FUN_0079f7f5();
  local_2f4 = local_2c0;
  puStack_2f8 = local_200;
  puStack_2fc = local_180;
  puStack_300 = (undefined1 *)0x4d2364;
  thunk_FUN_0079ee7b();
  puStack_300 = auStack_8c;
  puStack_304 = auStack_10c;
  puVar4 = auStack_18c;
  puVar5 = auStack_10c;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  puStack_308 = auStack_1cc;
  puStack_30c = (undefined1 *)0x4d2396;
  thunk_FUN_0079ee7b();
  puStack_30c = auStack_158;
  puStack_310 = auStack_d8;
  puVar4 = auStack_1d8;
  puVar5 = auStack_d8;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  thunk_FUN_0079ee7b(auStack_58);
  puVar4 = auStack_64;
  puVar5 = auStack_264;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  thunk_FUN_0079e09f(&local_2a4,&puStack_304,auStack_264);
  thunk_FUN_0079e09f(&local_2a0,&puStack_308,auStack_270);
  thunk_FUN_0079e09f(&local_29c,&puStack_30c,auStack_27c);
  thunk_FUN_0079e09f(local_298,&puStack_310,local_298 + 4);
  *(float *)(iStack_50 + 0x24) = fVar2 - fVar6;
  *(float *)(iStack_50 + 0x28) = fVar1 * fVar6 + fVar6;
  *(float *)(iStack_50 + 0x54) = fVar2;
  *(float *)(iStack_50 + 0x58) = local_2c0[0];
  *(float *)(iStack_50 + 0x84) = local_2c0[3];
  *(float *)(iStack_50 + 0x88) = local_2c0[4];
  *(undefined4 *)(iStack_50 + 0xb4) = local_2a4;
  *(undefined4 *)(iStack_50 + 0xb8) = local_2a0;
  return;
}


// ==== FUN_004d2550 @ 0x004d2550 ====

int FUN_004d2550(int *param_1,int param_2,int param_3)

{
  return ((param_3 - param_1[1]) * (param_1[2] - *param_1) - *param_1) + param_2;
}


// ==== FUN_004d2570 @ 0x004d2570 ====

int FUN_004d2570(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = param_1[2] - *param_1;
  return (param_1[1] + param_2 / uVar1) * param_3 + *param_1 + param_2 % uVar1;
}


// ==== FUN_004d25a0 @ 0x004d25a0 ====

/* WARNING: Removing unreachable block (ram,0x004d26e6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d25a0(undefined4 param_1,int param_2,int param_3,uint param_4,uint *param_5)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float fVar6;
  undefined4 *puStack_310;
  undefined1 *puStack_30c;
  undefined1 *puStack_308;
  undefined4 *puStack_304;
  undefined1 *puStack_300;
  undefined1 *puStack_2fc;
  undefined1 *puStack_2f8;
  float *local_2f4;
  float local_2c0 [6];
  undefined4 local_2a8;
  undefined4 local_2a4;
  undefined4 local_2a0;
  undefined4 local_29c;
  float local_298 [7];
  undefined1 auStack_27c [12];
  undefined1 auStack_270 [12];
  undefined4 auStack_264 [25];
  undefined1 local_200 [40];
  undefined4 auStack_1d8 [3];
  undefined1 auStack_1cc [64];
  undefined4 auStack_18c [3];
  undefined1 local_180 [40];
  undefined1 auStack_158 [24];
  undefined1 local_140 [52];
  undefined4 auStack_10c [13];
  undefined4 auStack_d8 [19];
  undefined1 auStack_8c [12];
  undefined1 local_80 [28];
  undefined4 auStack_64 [3];
  undefined1 auStack_58 [8];
  int iStack_50;
  
  fVar6 = DAT_0099d080 / (float)(ushort)param_5[1];
  param_2 = param_2 - *param_5 % param_4;
  fVar1 = (float)param_2;
  if (param_2 < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  param_3 = param_3 - *param_5 / param_4;
  fVar2 = (float)param_3;
  if (param_3 < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  local_2f4 = (float *)0x0;
  puStack_2f8 = (undefined1 *)0xbf000000;
  fVar2 = DAT_0099d080 - fVar2 * fVar6;
  puStack_2fc = (undefined1 *)0xbf000000;
  puStack_300 = local_200;
  puStack_304 = (undefined4 *)0x4d266f;
  thunk_FUN_0079f7f5();
  local_298[4] = 0.0;
  local_298[3] = 0.0;
  local_298[2] = 0.0;
  local_298[1] = 0.0;
  local_29c = 0;
  local_2a0 = 0;
  local_2a4 = 0;
  local_2a8 = 0;
  local_2c0[4] = 0.0;
  local_2c0[3] = 0.0;
  local_2c0[2] = 0.0;
  local_2c0[1] = 0.0;
  local_298[5] = DAT_0099d080;
  local_298[0] = DAT_0099d080;
  local_2c0[5] = DAT_0099d080;
  local_2c0[0] = DAT_0099d080;
  if ((*(ushort *)((int)param_5 + 6) & 1) == 1) {
    local_2c0[0] = DAT_0099d0dc;
  }
  local_2f4 = (float *)((float)(ushort)param_5[2] * DAT_009b0eb8);
  puStack_2f8 = local_80;
  puStack_2fc = (undefined1 *)0x4d2721;
  thunk_FUN_0079f9c8();
  local_2f4 = (float *)0x0;
  puStack_2f8 = (undefined1 *)0x3f000000;
  puStack_2fc = (undefined1 *)0x3f000000;
  puStack_300 = local_140;
  puStack_304 = (undefined4 *)0x4d273a;
  thunk_FUN_0079f7f5();
  local_2f4 = local_2c0;
  puStack_2f8 = local_200;
  puStack_2fc = local_180;
  puStack_300 = (undefined1 *)0x4d2754;
  thunk_FUN_0079ee7b();
  puStack_300 = auStack_8c;
  puStack_304 = auStack_10c;
  puVar4 = auStack_18c;
  puVar5 = auStack_10c;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  puStack_308 = auStack_1cc;
  puStack_30c = (undefined1 *)0x4d2786;
  thunk_FUN_0079ee7b();
  puStack_30c = auStack_158;
  puStack_310 = auStack_d8;
  puVar4 = auStack_1d8;
  puVar5 = auStack_d8;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  thunk_FUN_0079ee7b(auStack_58);
  puVar4 = auStack_64;
  puVar5 = auStack_264;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  thunk_FUN_0079e09f(&local_2a4,&puStack_304,auStack_264);
  thunk_FUN_0079e09f(&local_2a0,&puStack_308,auStack_270);
  thunk_FUN_0079e09f(&local_29c,&puStack_30c,auStack_27c);
  thunk_FUN_0079e09f(local_298,&puStack_310,local_298 + 4);
  *(float *)(iStack_50 + 0x18) = fVar2 - fVar6;
  *(float *)(iStack_50 + 0x1c) = fVar1 * fVar6 + fVar6;
  *(float *)(iStack_50 + 0x3c) = fVar2;
  *(float *)(iStack_50 + 0x40) = local_2c0[0];
  *(float *)(iStack_50 + 0x60) = local_2c0[3];
  *(float *)(iStack_50 + 100) = local_2c0[4];
  *(undefined4 *)(iStack_50 + 0x84) = local_2a4;
  *(undefined4 *)(iStack_50 + 0x88) = local_2a0;
  return;
}


// ==== FUN_004d28c0 @ 0x004d28c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004d28c0(undefined4 param_1,int param_2,float *param_3)

{
  undefined4 *puVar1;
  float *pfVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined1 local_34 [4];
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
  undefined4 local_8;
  undefined4 local_4;
  
  pfVar2 = param_3;
  *param_3 = DAT_0099d0f0;
  puVar4 = *(undefined4 **)(param_2 + 4);
  puVar1 = *(undefined4 **)(param_2 + 8);
  if (puVar4 != puVar1) {
    do {
      local_30 = *puVar4;
      local_2c = puVar4[1];
      local_28 = puVar4[2];
      local_24 = puVar4[0xc];
      local_20 = puVar4[0xd];
      local_1c = puVar4[0xe];
      local_18 = puVar4[0x18];
      local_14 = puVar4[0x19];
      local_10 = puVar4[0x1a];
      local_c = puVar4[0x24];
      local_8 = puVar4[0x25];
      local_4 = puVar4[0x26];
      puVar4 = puVar4 + 0x30;
      cVar3 = FUN_0040e200(param_1,&local_30,&local_24,&local_c,local_34,&param_2,&param_3);
      if ((cVar3 != '\0') && ((float)param_3 < *pfVar2)) {
        *pfVar2 = (float)param_3;
      }
      cVar3 = FUN_0040e200(param_1,&local_c,&local_24,&local_18,local_34,&param_2,&param_3);
      if ((cVar3 != '\0') && ((float)param_3 < *pfVar2)) {
        *pfVar2 = (float)param_3;
      }
    } while (puVar4 != puVar1);
    if (*pfVar2 < _DAT_009b0ebc) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_004d2a00 @ 0x004d2a00 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004d2a00(undefined4 param_1,int param_2,float *param_3)

{
  undefined4 *puVar1;
  float *pfVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined1 local_34 [4];
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
  undefined4 local_8;
  undefined4 local_4;
  
  pfVar2 = param_3;
  *param_3 = DAT_0099d0f0;
  puVar4 = *(undefined4 **)(param_2 + 4);
  puVar1 = *(undefined4 **)(param_2 + 8);
  if (puVar4 != puVar1) {
    do {
      local_30 = *puVar4;
      local_2c = puVar4[1];
      local_28 = puVar4[2];
      local_24 = puVar4[9];
      local_20 = puVar4[10];
      local_1c = puVar4[0xb];
      local_18 = puVar4[0x12];
      local_14 = puVar4[0x13];
      local_10 = puVar4[0x14];
      local_c = puVar4[0x1b];
      local_8 = puVar4[0x1c];
      local_4 = puVar4[0x1d];
      puVar4 = puVar4 + 0x24;
      cVar3 = FUN_0040e200(param_1,&local_30,&local_24,&local_c,local_34,&param_2,&param_3);
      if ((cVar3 != '\0') && ((float)param_3 < *pfVar2)) {
        *pfVar2 = (float)param_3;
      }
      cVar3 = FUN_0040e200(param_1,&local_c,&local_24,&local_18,local_34,&param_2,&param_3);
      if ((cVar3 != '\0') && ((float)param_3 < *pfVar2)) {
        *pfVar2 = (float)param_3;
      }
    } while (puVar4 != puVar1);
    if (*pfVar2 < _DAT_009b0ebc) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_004d2b40 @ 0x004d2b40 ====

void FUN_004d2b40(int param_1,int param_2,uint *param_3)

{
  code *pcVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00981090;
  local_c = ExceptionList;
  if ((((param_1 == 0) || (param_1 == 1)) || (param_1 == 2)) || (param_1 == 3)) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    ExceptionList = &local_c;
    FUN_00401740(&DAT_009b0ea0,1);
    local_4 = 0;
    FUN_00406880(local_44);
    local_4 = 0xffffffff;
    if (local_2c < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_40);
    return;
  }
  if (param_1 == 4) {
    iVar3 = 0;
  }
  else if (param_1 == 5) {
    iVar3 = 0;
  }
  else if (param_1 == 6) {
    iVar3 = 0;
  }
  else if (param_1 == 7) {
    iVar3 = 1;
  }
  else if (param_1 == 8) {
    iVar3 = 1;
  }
  else {
    if (param_1 != 9) {
      ExceptionList = &local_c;
      FUN_00401830(&DAT_009b0ea4);
      local_4 = 1;
      FUN_00406880(local_28);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    iVar3 = 2;
  }
  iVar4 = 4;
  puVar2 = param_3;
  do {
    iVar4 = iVar4 + -1;
    *puVar2 = (uint)(*(int *)((param_2 - (int)param_3) + (int)puVar2) != iVar3);
    puVar2 = puVar2 + 1;
  } while (iVar4 != 0);
  return;
}


// ==== FUN_004d2c70 @ 0x004d2c70 ====

void FUN_004d2c70(int param_1,undefined4 param_2,undefined4 *param_3,int *param_4)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int local_38 [4];
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009810a2;
  local_c = ExceptionList;
  if ((((param_1 == 0) || (param_1 == 1)) || (param_1 == 2)) || (param_1 == 3)) {
    *param_4 = 0;
    *param_3 = 5;
    return;
  }
  ExceptionList = &local_c;
  FUN_004d2b40(param_1,param_2,local_38);
  iVar4 = 0;
  while( true ) {
    iVar3 = 0;
    while (*(int *)((int)local_38 + iVar3) == *(int *)((int)&DAT_009b0fdc + iVar3)) {
      iVar3 = iVar3 + 4;
      if (0xf < iVar3) {
        *param_4 = iVar4;
        *param_3 = 0;
        ExceptionList = local_c;
        return;
      }
    }
    cVar2 = FUN_004d2040(local_38,&DAT_009b0fec);
    if (cVar2 == '\x01') {
      *param_4 = iVar4;
      *param_3 = 1;
      ExceptionList = local_c;
      return;
    }
    cVar2 = FUN_004d2040(local_38,&DAT_009b0ffc);
    if (cVar2 == '\x01') break;
    cVar2 = FUN_004d2040(local_38,&DAT_009b100c);
    if (cVar2 == '\x01') {
      *param_4 = iVar4;
      *param_3 = 3;
      ExceptionList = local_c;
      return;
    }
    FUN_004d2070(local_38);
    iVar4 = iVar4 + 1;
    if (3 < iVar4) {
      FUN_00401830(&DAT_009b0ea8);
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
  }
  *param_4 = iVar4;
  *param_3 = 2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004d2e40 @ 0x004d2e40 ====

void FUN_004d2e40(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar1 = FUN_004d20a0(param_2);
  FUN_004d2c70(uVar1,param_2,&local_4,&local_8);
  *param_1 = uVar1;
  param_1[1] = local_4;
  param_1[2] = local_8;
  return;
}


// ==== FUN_004d2e90 @ 0x004d2e90 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d2e90(int param_1,int *param_2,ushort param_3)

{
  code *pcVar1;
  int iVar2;
  float *pfVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  void *local_2c [6];
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009810b4;
  local_c = ExceptionList;
  switch(param_2[2]) {
  case 0:
    local_2c[1] = DAT_00ae7ae8;
    local_2c[2] = DAT_00ae7aec;
    local_2c[5] = DAT_00ae7aec;
    local_14 = (uint)DAT_00ae7ae8;
    local_2c[1] = DAT_00ae7aec;
    local_2c[2] = DAT_00ae7ae8;
    goto LAB_004d2f6c;
  case 1:
    local_2c[1] = DAT_00ae7ae8;
    local_2c[2] = DAT_00ae7aec;
    break;
  case 2:
    local_2c[0] = DAT_00ae7ae8;
    local_2c[1] = DAT_00ae7aec;
    local_2c[2] = DAT_00ae7ae8;
    local_2c[3] = DAT_00ae7ae8;
    local_2c[4] = DAT_00ae7aec;
    local_2c[5] = DAT_00ae7ae8;
    local_14 = (uint)DAT_00ae7aec;
    local_10 = DAT_00ae7aec;
    goto LAB_004d2fdc;
  case 3:
    local_2c[1] = DAT_00ae7aec;
    local_2c[2] = DAT_00ae7ae8;
    break;
  default:
    local_14 = 0xf;
    local_2c[5] = (void *)0x0;
    local_2c[1] = (void *)((uint)local_2c[1] & 0xffffff00);
    ExceptionList = &local_c;
    FUN_00401740(&DAT_009b0eac,1);
    local_4 = 0;
    FUN_00406880(local_2c);
    if (local_14 < 0x10) {
      local_14 = 0xf;
      local_2c[5] = (void *)0x0;
      local_2c[1] = (void *)((uint)local_2c[1] & 0xffffff00);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_2c[1]);
    return;
  }
  local_2c[5] = local_2c[2];
  local_14 = (uint)local_2c[1];
LAB_004d2f6c:
  local_2c[0] = local_2c[1];
  local_2c[3] = local_2c[1];
  local_2c[4] = local_2c[2];
  local_10 = local_2c[2];
LAB_004d2fdc:
  iVar2 = *param_2;
  fVar5 = 0.0;
  fVar6 = 0.0;
  if (iVar2 == 0) {
    fVar5 = (float)param_3 * DAT_00ae7ae4;
    goto LAB_004d336d;
  }
  if (iVar2 == 1) {
    fVar5 = (float)(param_3 + 4) * DAT_00ae7ae4;
    goto LAB_004d336d;
  }
  if (iVar2 == 2) {
    fVar5 = (float)param_3 * DAT_00ae7ae4;
    fVar6 = DAT_00ae7ae4;
    goto LAB_004d336d;
  }
  if (iVar2 == 3) {
    uVar4 = param_3 + 4;
LAB_004d323e:
    fVar5 = (float)uVar4 * DAT_00ae7ae4;
    fVar6 = DAT_00ae7ae4;
  }
  else {
    if (iVar2 == 4) {
      iVar2 = param_2[1];
      if (iVar2 == 0) {
        uVar4 = (uint)param_3;
      }
      else {
        if (iVar2 != 1) {
          if (iVar2 == 2) {
            fVar5 = (float)param_3 * DAT_00ae7ae4;
            fVar6 = DAT_00ae7ae4 * DAT_009b0300;
            goto LAB_004d336d;
          }
          if (iVar2 != 3) goto LAB_004d336d;
          uVar4 = param_3 + 4;
LAB_004d32e3:
          fVar5 = (float)uVar4 * DAT_00ae7ae4;
          fVar6 = DAT_00ae7ae4 * DAT_009b0300;
          goto LAB_004d336d;
        }
        uVar4 = param_3 + 4;
      }
LAB_004d3292:
      fVar5 = (float)uVar4 * DAT_00ae7ae4;
      fVar6 = DAT_00ae7ae4 * DAT_0099d0f8;
      goto LAB_004d336d;
    }
    if (iVar2 == 5) {
      iVar2 = param_2[1];
      if (iVar2 == 0) {
        fVar5 = (float)param_3 * DAT_00ae7ae4;
        fVar6 = DAT_00ae7ae4 * DAT_009b0ec8;
        goto LAB_004d336d;
      }
      if (iVar2 != 1) {
        if (iVar2 == 2) {
          fVar5 = (float)param_3;
        }
        else {
          if (iVar2 != 3) goto LAB_004d336d;
          fVar5 = (float)(param_3 + 4);
        }
LAB_004d3359:
        fVar5 = fVar5 * DAT_00ae7ae4;
        fVar6 = DAT_00ae7ae4 * DAT_009b0120;
        goto LAB_004d336d;
      }
      uVar4 = param_3 + 4;
    }
    else {
      if (iVar2 == 6) {
        iVar2 = param_2[1];
        if (iVar2 == 0) {
          fVar5 = (float)param_3 * DAT_00ae7ae4;
          fVar6 = DAT_00ae7ae4 * DAT_009b0ec4;
        }
        else if (iVar2 == 1) {
          fVar5 = (float)(param_3 + 4) * DAT_00ae7ae4;
          fVar6 = DAT_00ae7ae4 * DAT_009b0ec4;
        }
        else if (iVar2 == 2) {
          fVar5 = (float)param_3 * DAT_00ae7ae4;
          fVar6 = DAT_00ae7ae4 * _DAT_009b0ec0;
        }
        else if (iVar2 == 3) {
          fVar5 = (float)(param_3 + 4) * DAT_00ae7ae4;
          fVar6 = DAT_00ae7ae4 * _DAT_009b0ec0;
        }
        goto LAB_004d336d;
      }
      if (iVar2 == 7) {
        iVar2 = param_2[1];
        if (iVar2 == 0) {
          fVar5 = (float)param_3 * DAT_00ae7ae4;
          goto LAB_004d336d;
        }
        if (iVar2 == 1) {
          fVar5 = (float)(param_3 + 4) * DAT_00ae7ae4;
          goto LAB_004d336d;
        }
        if (iVar2 != 2) {
          if (iVar2 == 3) {
            fVar5 = (float)(param_3 + 4) * DAT_00ae7ae4;
            fVar6 = DAT_00ae7ae4;
          }
          goto LAB_004d336d;
        }
        uVar4 = (uint)param_3;
        goto LAB_004d323e;
      }
      if (iVar2 == 8) {
        iVar2 = param_2[1];
        if (iVar2 != 0) {
          if (iVar2 == 1) {
            fVar5 = (float)(param_3 + 4) * DAT_00ae7ae4;
            fVar6 = DAT_00ae7ae4 * DAT_0099d0f8;
            goto LAB_004d336d;
          }
          if (iVar2 == 2) {
            uVar4 = (uint)param_3;
          }
          else {
            if (iVar2 != 3) goto LAB_004d336d;
            uVar4 = param_3 + 4;
          }
          goto LAB_004d32e3;
        }
        uVar4 = (uint)param_3;
        goto LAB_004d3292;
      }
      if (iVar2 != 9) goto LAB_004d336d;
      iVar2 = param_2[1];
      if (iVar2 == 0) {
        uVar4 = (uint)param_3;
      }
      else {
        if (iVar2 != 1) {
          if (iVar2 == 2) {
            fVar5 = (float)param_3;
          }
          else {
            if (iVar2 != 3) goto LAB_004d336d;
            fVar5 = (float)(param_3 + 4);
          }
          goto LAB_004d3359;
        }
        uVar4 = param_3 + 4;
      }
    }
    fVar5 = (float)uVar4 * DAT_00ae7ae4;
    fVar6 = DAT_00ae7ae4 * DAT_009b0ec8;
  }
LAB_004d336d:
  iVar2 = 0;
  pfVar3 = (float *)(param_1 + 0x28);
  do {
    pfVar3[-1] = (float)local_2c[iVar2 * 2] + fVar5;
    *pfVar3 = (float)local_2c[iVar2 * 2 + 1] + fVar6;
    iVar2 = iVar2 + 1;
    pfVar3 = pfVar3 + 0xc;
  } while (iVar2 < 4);
  return;
}


// ==== FUN_004d33d0 @ 0x004d33d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d33d0(int param_1,int *param_2,ushort param_3)

{
  code *pcVar1;
  int iVar2;
  float *pfVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  void *local_2c [6];
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009810c6;
  local_c = ExceptionList;
  switch(param_2[2]) {
  case 0:
    local_2c[1] = DAT_00ae7af4;
    local_2c[2] = DAT_00ae7af8;
    local_2c[5] = DAT_00ae7af8;
    local_14 = (uint)DAT_00ae7af4;
    local_2c[1] = DAT_00ae7af8;
    local_2c[2] = DAT_00ae7af4;
    goto LAB_004d34ac;
  case 1:
    local_2c[1] = DAT_00ae7af4;
    local_2c[2] = DAT_00ae7af8;
    break;
  case 2:
    local_2c[0] = DAT_00ae7af4;
    local_2c[1] = DAT_00ae7af8;
    local_2c[2] = DAT_00ae7af4;
    local_2c[3] = DAT_00ae7af4;
    local_2c[4] = DAT_00ae7af8;
    local_2c[5] = DAT_00ae7af4;
    local_14 = (uint)DAT_00ae7af8;
    local_10 = DAT_00ae7af8;
    goto LAB_004d351c;
  case 3:
    local_2c[1] = DAT_00ae7af8;
    local_2c[2] = DAT_00ae7af4;
    break;
  default:
    local_14 = 0xf;
    local_2c[5] = (void *)0x0;
    local_2c[1] = (void *)((uint)local_2c[1] & 0xffffff00);
    ExceptionList = &local_c;
    FUN_00401740(&DAT_009b0eb0,1);
    local_4 = 0;
    FUN_00406880(local_2c);
    if (local_14 < 0x10) {
      local_14 = 0xf;
      local_2c[5] = (void *)0x0;
      local_2c[1] = (void *)((uint)local_2c[1] & 0xffffff00);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_2c[1]);
    return;
  }
  local_2c[5] = local_2c[2];
  local_14 = (uint)local_2c[1];
LAB_004d34ac:
  local_2c[0] = local_2c[1];
  local_2c[3] = local_2c[1];
  local_2c[4] = local_2c[2];
  local_10 = local_2c[2];
LAB_004d351c:
  iVar2 = *param_2;
  fVar5 = 0.0;
  fVar6 = 0.0;
  if (iVar2 == 0) {
    fVar5 = (float)param_3 * DAT_00ae7af0;
    goto LAB_004d38ad;
  }
  if (iVar2 == 1) {
    fVar5 = (float)(param_3 + 4) * DAT_00ae7af0;
    goto LAB_004d38ad;
  }
  if (iVar2 == 2) {
    fVar5 = (float)param_3 * DAT_00ae7af0;
    fVar6 = DAT_00ae7af0;
    goto LAB_004d38ad;
  }
  if (iVar2 == 3) {
    uVar4 = param_3 + 4;
LAB_004d377e:
    fVar5 = (float)uVar4 * DAT_00ae7af0;
    fVar6 = DAT_00ae7af0;
  }
  else {
    if (iVar2 == 4) {
      iVar2 = param_2[1];
      if (iVar2 == 0) {
        uVar4 = (uint)param_3;
      }
      else {
        if (iVar2 != 1) {
          if (iVar2 == 2) {
            fVar5 = (float)param_3 * DAT_00ae7af0;
            fVar6 = DAT_00ae7af0 * DAT_009b0300;
            goto LAB_004d38ad;
          }
          if (iVar2 != 3) goto LAB_004d38ad;
          uVar4 = param_3 + 4;
LAB_004d3823:
          fVar5 = (float)uVar4 * DAT_00ae7af0;
          fVar6 = DAT_00ae7af0 * DAT_009b0300;
          goto LAB_004d38ad;
        }
        uVar4 = param_3 + 4;
      }
LAB_004d37d2:
      fVar5 = (float)uVar4 * DAT_00ae7af0;
      fVar6 = DAT_00ae7af0 * DAT_0099d0f8;
      goto LAB_004d38ad;
    }
    if (iVar2 == 5) {
      iVar2 = param_2[1];
      if (iVar2 == 0) {
        fVar5 = (float)param_3 * DAT_00ae7af0;
        fVar6 = DAT_00ae7af0 * DAT_009b0ec8;
        goto LAB_004d38ad;
      }
      if (iVar2 != 1) {
        if (iVar2 == 2) {
          fVar5 = (float)param_3;
        }
        else {
          if (iVar2 != 3) goto LAB_004d38ad;
          fVar5 = (float)(param_3 + 4);
        }
LAB_004d3899:
        fVar5 = fVar5 * DAT_00ae7af0;
        fVar6 = DAT_00ae7af0 * DAT_009b0120;
        goto LAB_004d38ad;
      }
      uVar4 = param_3 + 4;
    }
    else {
      if (iVar2 == 6) {
        iVar2 = param_2[1];
        if (iVar2 == 0) {
          fVar5 = (float)param_3 * DAT_00ae7af0;
          fVar6 = DAT_00ae7af0 * DAT_009b0ec4;
        }
        else if (iVar2 == 1) {
          fVar5 = (float)(param_3 + 4) * DAT_00ae7af0;
          fVar6 = DAT_00ae7af0 * DAT_009b0ec4;
        }
        else if (iVar2 == 2) {
          fVar5 = (float)param_3 * DAT_00ae7af0;
          fVar6 = DAT_00ae7af0 * _DAT_009b0ec0;
        }
        else if (iVar2 == 3) {
          fVar5 = (float)(param_3 + 4) * DAT_00ae7af0;
          fVar6 = DAT_00ae7af0 * _DAT_009b0ec0;
        }
        goto LAB_004d38ad;
      }
      if (iVar2 == 7) {
        iVar2 = param_2[1];
        if (iVar2 == 0) {
          fVar5 = (float)param_3 * DAT_00ae7af0;
          goto LAB_004d38ad;
        }
        if (iVar2 == 1) {
          fVar5 = (float)(param_3 + 4) * DAT_00ae7af0;
          goto LAB_004d38ad;
        }
        if (iVar2 != 2) {
          if (iVar2 == 3) {
            fVar5 = (float)(param_3 + 4) * DAT_00ae7af0;
            fVar6 = DAT_00ae7af0;
          }
          goto LAB_004d38ad;
        }
        uVar4 = (uint)param_3;
        goto LAB_004d377e;
      }
      if (iVar2 == 8) {
        iVar2 = param_2[1];
        if (iVar2 != 0) {
          if (iVar2 == 1) {
            fVar5 = (float)(param_3 + 4) * DAT_00ae7af0;
            fVar6 = DAT_00ae7af0 * DAT_0099d0f8;
            goto LAB_004d38ad;
          }
          if (iVar2 == 2) {
            uVar4 = (uint)param_3;
          }
          else {
            if (iVar2 != 3) goto LAB_004d38ad;
            uVar4 = param_3 + 4;
          }
          goto LAB_004d3823;
        }
        uVar4 = (uint)param_3;
        goto LAB_004d37d2;
      }
      if (iVar2 != 9) goto LAB_004d38ad;
      iVar2 = param_2[1];
      if (iVar2 == 0) {
        uVar4 = (uint)param_3;
      }
      else {
        if (iVar2 != 1) {
          if (iVar2 == 2) {
            fVar5 = (float)param_3;
          }
          else {
            if (iVar2 != 3) goto LAB_004d38ad;
            fVar5 = (float)(param_3 + 4);
          }
          goto LAB_004d3899;
        }
        uVar4 = param_3 + 4;
      }
    }
    fVar5 = (float)uVar4 * DAT_00ae7af0;
    fVar6 = DAT_00ae7af0 * DAT_009b0ec8;
  }
LAB_004d38ad:
  iVar2 = 0;
  pfVar3 = (float *)(param_1 + 0x1c);
  do {
    pfVar3[-1] = (float)local_2c[iVar2 * 2] + fVar5;
    *pfVar3 = (float)local_2c[iVar2 * 2 + 1] + fVar6;
    iVar2 = iVar2 + 1;
    pfVar3 = pfVar3 + 9;
  } while (iVar2 < 4);
  return;
}


// ==== FUN_004d3910 @ 0x004d3910 ====

void FUN_004d3910(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b0f10;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_004d3930 @ 0x004d3930 ====

void FUN_004d3930(void)

{
  FUN_0042d0b0();
  return;
}


// ==== FUN_004d3940 @ 0x004d3940 ====

void FUN_004d3940(undefined4 param_1,undefined4 param_2)

{
  FUN_0042b170(param_2,param_1);
  return;
}


// ==== FUN_004d3960 @ 0x004d3960 ====

void FUN_004d3960(void)

{
  FUN_0042cdc0();
  return;
}


// ==== FUN_004d3970 @ 0x004d3970 ====

void FUN_004d3970(void)

{
  FUN_0042b190();
  return;
}


// ==== FUN_004d39a0 @ 0x004d39a0 ====

uint FUN_004d39a0(undefined4 param_1,undefined4 *param_2,uint param_3,undefined4 *param_4,
                 undefined4 *param_5,uint *param_6)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  uint uVar6;
  uint *puVar7;
  
  puVar2 = *(undefined4 **)param_2[1];
  puVar5 = param_2;
  do {
    if (puVar2 == (undefined4 *)param_2[1]) {
      return (uint)puVar5 & 0xffffff00;
    }
    uVar3 = puVar2[3];
    for (puVar7 = (uint *)puVar2[5]; puVar7 != (uint *)puVar2[6]; puVar7 = puVar7 + 3) {
      uVar6 = *puVar7 % *(uint *)(*(int *)(in_ECX + 4) + 0x40);
      puVar5 = (undefined4 *)(*puVar7 / *(uint *)(*(int *)(in_ECX + 4) + 0x44));
      if ((((uVar6 <= param_3) && (puVar5 <= param_4)) && (param_3 < uVar6 + (ushort)puVar7[1])) &&
         (param_4 < (undefined4 *)((uint)(ushort)puVar7[1] + (int)puVar5))) {
        *param_6 = *puVar7;
        param_6[1] = puVar7[1];
        param_6[2] = puVar7[2];
        *param_5 = uVar3;
        return CONCAT31((int3)((uint)uVar3 >> 8),1);
      }
    }
    if (*(char *)((int)puVar2 + 0x25) == '\0') {
      puVar5 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar5 + 0x25) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x25);
        puVar2 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x25);
          puVar2 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x25);
        puVar5 = (undefined4 *)puVar2[1];
        puVar4 = puVar2;
        while ((puVar2 = puVar5, puVar5 = puVar2, cVar1 == '\0' &&
               (puVar4 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x25);
          puVar5 = (undefined4 *)puVar2[1];
          puVar4 = puVar2;
        }
      }
    }
  } while( true );
}


// ==== FUN_004d3ab0 @ 0x004d3ab0 ====

void FUN_004d3ab0(float *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  fVar9 = DAT_0099d080;
  iVar1 = param_3 * param_4 + param_2;
  fVar6 = param_1[0x16] - param_1[10];
  fVar7 = param_1[0x2e] - param_1[10];
  fVar8 = DAT_0099d080 /
          ((param_1[0x15] - param_1[9]) * fVar7 - (param_1[0x2d] - param_1[9]) * fVar6);
  fVar10 = ((param_1[0xc] - *param_1) * fVar7 - (param_1[0x24] - *param_1) * fVar6) * fVar8;
  fVar11 = ((param_1[0xd] - param_1[1]) * fVar7 - (param_1[0x25] - param_1[1]) * fVar6) * fVar8;
  fVar8 = ((param_1[0xe] - param_1[2]) * fVar7 - (param_1[0x26] - param_1[2]) * fVar6) * fVar8;
  param_2 = (param_3 + 1) * param_4 + param_2;
  pfVar5 = (float *)(*(int *)(param_5 + 4) + iVar1 * 0xc);
  *pfVar5 = fVar10 + *pfVar5;
  pfVar5[1] = fVar11 + pfVar5[1];
  pfVar5[2] = fVar8 + pfVar5[2];
  iVar3 = param_2 * 0xc;
  pfVar5 = (float *)(*(int *)(param_5 + 4) + iVar3);
  *pfVar5 = *(float *)(*(int *)(param_5 + 4) + iVar3) + fVar10;
  pfVar5[1] = pfVar5[1] + fVar11;
  pfVar5[2] = pfVar5[2] + fVar8;
  iVar2 = *(int *)(param_5 + 4);
  iVar4 = (iVar1 * 3 + 3) * 4;
  *(float *)(iVar2 + iVar4) = *(float *)(iVar2 + iVar4) + fVar10;
  *(float *)(iVar2 + 4 + iVar4) = *(float *)(iVar2 + 4 + iVar4) + fVar11;
  *(float *)(iVar2 + 8 + iVar4) = *(float *)(iVar2 + 8 + iVar4) + fVar8;
  fVar6 = param_1[0x16] - param_1[0x2e];
  fVar7 = param_1[0x22] - param_1[0x2e];
  fVar9 = fVar9 / ((param_1[0x15] - param_1[0x2d]) * fVar7 - (param_1[0x21] - param_1[0x2d]) * fVar6
                  );
  fVar8 = ((param_1[0xc] - param_1[0x24]) * fVar7 - (param_1[0x18] - param_1[0x24]) * fVar6) * fVar9
  ;
  fVar10 = ((param_1[0xd] - param_1[0x25]) * fVar7 - (param_1[0x19] - param_1[0x25]) * fVar6) *
           fVar9;
  fVar9 = ((param_1[0xe] - param_1[0x26]) * fVar7 - (param_1[0x1a] - param_1[0x26]) * fVar6) * fVar9
  ;
  iVar1 = *(int *)(param_5 + 4);
  fVar6 = *(float *)(iVar1 + 8 + iVar4);
  pfVar5 = (float *)(iVar1 + iVar4);
  *pfVar5 = *(float *)(iVar1 + iVar4) + fVar8;
  pfVar5[1] = *(float *)(iVar1 + 4 + iVar4) + fVar10;
  pfVar5[2] = fVar6 + fVar9;
  pfVar5 = (float *)(*(int *)(param_5 + 4) + iVar3);
  *pfVar5 = fVar8 + *pfVar5;
  pfVar5[1] = pfVar5[1] + fVar10;
  pfVar5[2] = pfVar5[2] + fVar9;
  iVar1 = param_2 * 3 + 3;
  fVar6 = *(float *)(*(int *)(param_5 + 4) + iVar1 * 4);
  pfVar5 = (float *)(*(int *)(param_5 + 4) + iVar1 * 4);
  pfVar5[1] = pfVar5[1] + fVar10;
  *pfVar5 = fVar6 + fVar8;
  pfVar5[2] = pfVar5[2] + fVar9;
  return;
}


// ==== FUN_004d3e10 @ 0x004d3e10 ====

int FUN_004d3e10(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 4) + 0xc0);
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(iVar1 + 0xac,0,0xffffffff);
  return param_1;
}


// ==== FUN_004d3e50 @ 0x004d3e50 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004d3e50(float *param_1,float *param_2)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  int in_ECX;
  uint uVar11;
  uint uVar12;
  
  iVar6 = *(int *)(*(int *)(in_ECX + 4) + 0xc0);
  uVar7 = *(uint *)(iVar6 + 0xc);
  uVar12 = (int)ROUND(*param_1);
  if (uVar7 < (uint)(int)ROUND(*param_1)) {
    uVar12 = uVar7;
  }
  uVar11 = (int)ROUND(*param_2);
  if (*(uint *)(iVar6 + 0x10) < (uint)(int)ROUND(*param_2)) {
    uVar11 = *(uint *)(iVar6 + 0x10);
  }
  uVar1 = (uVar7 + 1) * uVar11 + uVar12;
  iVar8 = *(int *)(iVar6 + 0x2c);
  if ((iVar8 == 0) || ((uint)(*(int *)(iVar6 + 0x30) - iVar8 >> 2) <= uVar1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0042f370();
  }
  fVar2 = *(float *)(iVar8 + uVar1 * 4);
  uVar7 = (uVar11 + 1) * (uVar7 + 1) + uVar12;
  iVar8 = *(int *)(iVar6 + 0x2c);
  if ((iVar8 == 0) || ((uint)(*(int *)(iVar6 + 0x30) - iVar8 >> 2) <= uVar7)) {
                    /* WARNING: Subroutine does not return */
    FUN_0042f370();
  }
  fVar3 = *(float *)(iVar8 + uVar7 * 4);
  iVar8 = *(int *)(iVar6 + 0x2c);
  if ((iVar8 == 0) || ((uint)(*(int *)(iVar6 + 0x30) - iVar8 >> 2) <= uVar7 + 1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0042f370();
  }
  fVar4 = *(float *)(iVar8 + (uVar7 + 1) * 4);
  iVar8 = *(int *)(iVar6 + 0x2c);
  if ((iVar8 == 0) || ((uint)(*(int *)(iVar6 + 0x30) - iVar8 >> 2) <= uVar1 + 1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0042f370();
  }
  fVar5 = *(float *)(iVar8 + (uVar1 + 1) * 4);
  fVar9 = (float)(int)uVar12;
  if ((int)uVar12 < 0) {
    fVar9 = fVar9 + _DAT_0099d104;
  }
  fVar9 = *param_1 - fVar9;
  fVar10 = (float)(int)uVar11;
  if ((int)uVar11 < 0) {
    fVar10 = fVar10 + _DAT_0099d104;
  }
  fVar10 = *param_2 - fVar10;
  if (fVar10 < fVar9) {
    return (float10)((DAT_0099d080 - fVar9) * (fVar2 - fVar5) + (fVar4 - fVar5) * fVar10) +
           (float10)fVar5;
  }
  return (float10)((fVar4 - fVar3) * fVar9 + (DAT_0099d080 - fVar10) * (fVar2 - fVar3)) +
         (float10)fVar3;
}


// ==== FUN_004d4020 @ 0x004d4020 ====

uint FUN_004d4020(float *param_1,float *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  undefined8 uVar6;
  
  iVar2 = *(int *)(in_ECX + 4);
  iVar3 = *(int *)(iVar2 + 0x40);
  iVar4 = *(int *)(iVar2 + 0x6c);
  uVar5 = (int)ROUND(*param_2) * iVar3 + (int)ROUND(*param_1);
  uVar6 = CONCAT44(uVar5,iVar4);
  if ((iVar4 == 0) || ((uint)(*(int *)(iVar2 + 0x70) - iVar4) <= uVar5)) {
    uVar6 = FUN_004d4b70();
  }
  bVar1 = *(byte *)((int)uVar6 + (int)((ulonglong)uVar6 >> 0x20));
  if (bVar1 != 0xff) {
    return (uint)bVar1;
  }
  iVar2 = *(int *)(*(int *)(in_ECX + 4) + 0xc0);
  if (((uint)(int)ROUND(*param_1 + DAT_0099d0b4) <= *(uint *)(iVar2 + 0xc)) &&
     ((uint)(int)ROUND(*param_2 + DAT_0099d0b4) <= *(uint *)(iVar2 + 0x10))) {
    iVar4 = *(int *)(iVar2 + 0x4c);
    uVar5 = (iVar3 + 1) * (int)ROUND(*param_2 + DAT_0099d0b4) + (int)ROUND(*param_1 + DAT_0099d0b4);
    if ((iVar4 == 0) || ((uint)(*(int *)(iVar2 + 0x50) - iVar4 >> 2) <= uVar5)) {
                    /* WARNING: Subroutine does not return */
      FUN_0042f370();
    }
    uVar5 = *(uint *)(iVar4 + uVar5 * 4);
    if (uVar5 < 4) {
      return *(uint *)(iVar2 + 200 + uVar5 * 4);
    }
  }
  return 0;
}


// ==== FUN_004d4160 @ 0x004d4160 ====

void FUN_004d4160(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  float *pfVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  undefined1 *puStack_dc;
  undefined1 *puStack_d8;
  undefined1 *puStack_d4;
  undefined1 *puStack_d0;
  undefined1 *puStack_cc;
  undefined4 uStack_c8;
  undefined4 local_b4;
  float local_b0;
  undefined4 local_ac;
  undefined1 auStack_a8 [4];
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  undefined1 local_90 [4];
  undefined1 auStack_8c [4];
  undefined1 auStack_88 [4];
  undefined1 auStack_84 [4];
  undefined1 auStack_80 [4];
  undefined1 auStack_7c [4];
  undefined1 auStack_78 [12];
  undefined1 auStack_6c [12];
  undefined1 auStack_60 [12];
  undefined1 auStack_54 [12];
  undefined1 auStack_48 [12];
  undefined1 auStack_3c [32];
  float *pfStack_1c;
  
  param_4 = param_4 + 1;
  uVar1 = param_4 * param_3 + param_2;
  iVar2 = *(int *)(param_1 + 0x2c);
  if ((iVar2 == 0) || ((uint)(*(int *)(param_1 + 0x30) - iVar2 >> 2) <= uVar1)) {
                    /* WARNING: Subroutine does not return */
    uStack_c8 = (undefined4 *)0x4d41ae;
    FUN_0042f370();
  }
  local_94 = *(float *)(iVar2 + uVar1 * 4);
  iVar2 = *(int *)(param_1 + 0x2c);
  uVar6 = param_2 + (param_3 + 1) * param_4;
  if ((iVar2 == 0) || ((uint)(*(int *)(param_1 + 0x30) - iVar2 >> 2) <= uVar6)) {
                    /* WARNING: Subroutine does not return */
    uStack_c8 = (undefined4 *)0x4d41da;
    FUN_0042f370();
  }
  iVar3 = *(int *)(param_1 + 0x2c);
  local_b0 = *(float *)(iVar2 + uVar6 * 4) - local_94;
  if ((iVar3 == 0) || ((uint)(*(int *)(param_1 + 0x30) - iVar3 >> 2) <= uVar6 + 1)) {
                    /* WARNING: Subroutine does not return */
    uStack_c8 = (undefined4 *)0x4d41fe;
    FUN_0042f370();
  }
  iVar2 = *(int *)(param_1 + 0x2c);
  local_a4 = *(float *)(iVar3 + (uVar6 + 1) * 4) - local_94;
  if ((iVar2 == 0) || ((uint)(*(int *)(param_1 + 0x30) - iVar2 >> 2) <= uVar1 + 1)) {
                    /* WARNING: Subroutine does not return */
    uStack_c8 = (undefined4 *)0x4d4228;
    FUN_0042f370();
  }
  uVar6 = param_2 + (param_3 + -1) * param_4;
  iVar3 = *(int *)(param_1 + 0x2c);
  local_a0 = *(float *)(iVar2 + (uVar1 + 1) * 4) - local_94;
  if ((iVar3 == 0) || ((uint)(*(int *)(param_1 + 0x30) - iVar3 >> 2) <= uVar6)) {
                    /* WARNING: Subroutine does not return */
    uStack_c8 = (undefined4 *)0x4d4265;
    FUN_0042f370();
  }
  iVar2 = *(int *)(param_1 + 0x2c);
  local_9c = *(float *)(iVar3 + uVar6 * 4) - local_94;
  if ((iVar2 == 0) || ((uint)(*(int *)(param_1 + 0x30) - iVar2 >> 2) <= uVar6 - 1)) {
                    /* WARNING: Subroutine does not return */
    uStack_c8 = (undefined4 *)0x4d428f;
    FUN_0042f370();
  }
  iVar3 = *(int *)(param_1 + 0x2c);
  local_98 = *(float *)(iVar2 + (uVar6 - 1) * 4) - local_94;
  if ((iVar3 == 0) || ((uint)(*(int *)(param_1 + 0x30) - iVar3 >> 2) <= uVar1 - 1)) {
                    /* WARNING: Subroutine does not return */
    uStack_c8 = (undefined4 *)0x4d42b9;
    FUN_0042f370();
  }
  local_94 = *(float *)(iVar3 + (uVar1 - 1) * 4) - local_94;
  uStack_c8 = &local_b4;
  puStack_cc = local_90;
  local_b4 = 0;
  local_ac = DAT_0099d080;
  puStack_d0 = (undefined1 *)0x4d42f4;
  thunk_FUN_0079e1ba();
  uVar4 = local_ac;
  puStack_d0 = auStack_a8 + -0x14;
  puStack_d4 = auStack_8c;
  local_b4 = DAT_0099d080;
  puStack_d8 = (undefined1 *)0x4d4323;
  thunk_FUN_0079e1ba();
  puStack_d8 = auStack_a8 + -0x1c;
  puStack_dc = auStack_88;
  thunk_FUN_0079e1ba();
  puStack_cc = (undefined1 *)0x0;
  uStack_c8 = (undefined4 *)local_b4;
  thunk_FUN_0079e1ba(auStack_84,&puStack_cc);
  puStack_d4 = DAT_0099d0dc;
  puStack_d0 = (undefined1 *)uVar4;
  puStack_cc = DAT_0099d0dc;
  thunk_FUN_0079e1ba(auStack_80,&puStack_d4);
  puStack_dc = DAT_0099d0dc;
  puStack_d4 = (undefined1 *)0x0;
  puStack_d8 = (undefined1 *)0;
  thunk_FUN_0079e1ba(auStack_7c,&puStack_dc);
  pfVar5 = (float *)FUN_004d4ac0(auStack_60,auStack_a8 + -0x18,&local_b4);
  *pfStack_1c = *pfVar5;
  pfStack_1c[1] = pfVar5[1];
  pfStack_1c[2] = pfVar5[2];
  pfVar5 = (float *)FUN_004d4ac0(auStack_54,&local_b4,auStack_a8);
  *pfStack_1c = *pfVar5 + *pfStack_1c;
  pfStack_1c[1] = pfVar5[1] + pfStack_1c[1];
  pfStack_1c[2] = pfVar5[2] + pfStack_1c[2];
  pfVar5 = (float *)FUN_004d4ac0(auStack_3c,auStack_a8,&local_9c);
  fVar7 = *pfVar5 * DAT_0099d0f8;
  fVar8 = pfVar5[2] * DAT_0099d0f8;
  pfStack_1c[1] = pfStack_1c[1] + pfVar5[1] * DAT_0099d0f8;
  *pfStack_1c = *pfStack_1c + fVar7;
  pfStack_1c[2] = pfStack_1c[2] + fVar8;
  pfVar5 = (float *)FUN_004d4ac0(auStack_78,&local_9c,local_90);
  *pfStack_1c = *pfVar5 + *pfStack_1c;
  pfStack_1c[1] = pfVar5[1] + pfStack_1c[1];
  pfStack_1c[2] = pfVar5[2] + pfStack_1c[2];
  pfVar5 = (float *)FUN_004d4ac0(auStack_48,local_90,auStack_84);
  *pfStack_1c = *pfStack_1c + *pfVar5;
  pfStack_1c[1] = pfVar5[1] + pfStack_1c[1];
  pfStack_1c[2] = pfVar5[2] + pfStack_1c[2];
  pfVar5 = (float *)FUN_004d4ac0(auStack_6c,auStack_84,auStack_a8 + -0x18);
  fVar7 = *pfVar5 * DAT_0099d0f8;
  fVar8 = pfVar5[2] * DAT_0099d0f8;
  pfStack_1c[1] = pfStack_1c[1] + pfVar5[1] * DAT_0099d0f8;
  *pfStack_1c = *pfStack_1c + fVar7;
  pfStack_1c[2] = pfStack_1c[2] + fVar8;
  thunk_FUN_0079e1ba(pfStack_1c,pfStack_1c);
  return;
}


// ==== FUN_004d45c0 @ 0x004d45c0 ====

void FUN_004d45c0(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar5 = *(int *)(in_ECX + 4);
  iVar2 = *(int *)(iVar5 + 0xc0);
  local_14 = *param_1 + -1;
  local_1c = *(int *)(iVar5 + 0x40) + -1;
  local_18 = *(int *)(iVar5 + 0x44) + -1;
  if (local_14 < 2) {
    local_14 = 1;
  }
  iVar5 = param_1[1] + -1;
  if (iVar5 < 2) {
    iVar5 = 1;
  }
  iVar4 = *param_1 + 1;
  if (iVar4 <= local_1c) {
    local_1c = iVar4;
  }
  iVar4 = param_1[1] + 1;
  if (iVar4 <= local_18) {
    local_18 = iVar4;
  }
  for (; iVar5 <= local_18; iVar5 = iVar5 + 1) {
    for (iVar4 = local_14; iVar4 <= local_1c; iVar4 = iVar4 + 1) {
      iVar3 = *(int *)(*(int *)(in_ECX + 4) + 0x40);
      local_c = 0;
      local_4 = 0;
      local_8 = DAT_0099d080;
      FUN_004d4160(iVar2,iVar4,iVar5,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x40),&local_c);
      puVar1 = (undefined4 *)(*(int *)(iVar2 + 0x5c) + ((iVar3 + 1) * iVar5 + iVar4) * 0xc);
      *puVar1 = local_c;
      puVar1[1] = local_8;
      puVar1[2] = local_4;
    }
  }
  return;
}


// ==== FUN_004d4720 @ 0x004d4720 ====

void FUN_004d4720(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2;
  iVar2 = FUN_004cd1f0(param_1 + 1,param_2 + 1);
  if (iVar2 != 0) {
    param_2 = iVar2;
    FUN_004d1140(&param_2);
    if (param_1 == *(int *)(iVar2 + 0x40)) {
      param_2 = FUN_004cd390(2);
      if (param_2 != 0) {
        FUN_004d1140(&param_2);
      }
      if ((iVar1 == *(int *)(iVar2 + 0x44)) && (param_2 = FUN_004cd390(6), param_2 != 0)) {
        FUN_004d1140(&param_2);
      }
      if ((iVar1 == *(int *)(iVar2 + 0x4c) + -1) && (param_2 = FUN_004cd390(4), param_2 != 0)) {
        FUN_004d1140(&param_2);
      }
    }
    if (param_1 == *(int *)(iVar2 + 0x48) + -1) {
      param_2 = FUN_004cd390(3);
      if (param_2 != 0) {
        FUN_004d1140(&param_2);
      }
      if ((iVar1 == *(int *)(iVar2 + 0x44)) && (param_2 = FUN_004cd390(7), param_2 != 0)) {
        FUN_004d1140(&param_2);
      }
      if ((iVar1 == *(int *)(iVar2 + 0x4c) + -1) && (param_2 = FUN_004cd390(5), param_2 != 0)) {
        FUN_004d1140(&param_2);
      }
    }
    if ((iVar1 == *(int *)(iVar2 + 0x44)) && (param_2 = FUN_004cd390(1), param_2 != 0)) {
      FUN_004d1140(&param_2);
    }
    if ((iVar1 == *(int *)(iVar2 + 0x4c) + -1) && (param_2 = FUN_004cd390(0), param_2 != 0)) {
      FUN_004d1140(&param_2);
    }
  }
  return;
}


// ==== FUN_004d49b0 @ 0x004d49b0 ====

undefined4 FUN_004d49b0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined1 local_34 [8];
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
  puStack_8 = &LAB_00981118;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0x14) == 0) {
    return 0;
  }
  ExceptionList = &local_c;
  FUN_0069a470(&param_1,param_1);
  if (param_1 != *(int *)(*(int *)(in_ECX + 4) + 0x60)) {
    ExceptionList = local_c;
    return *(undefined4 *)(param_1 + 0x28);
  }
  uVar2 = FUN_004b4e70(iVar1);
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401660(iVar1,0,0xffffffff);
  local_4 = 0;
  local_10 = uVar2;
  FUN_004d4e50(local_34,local_2c);
  if (local_14 < 0x10) {
    ExceptionList = local_c;
    return uVar2;
  }
  _free(local_28);
  return extraout_EAX;
}


// ==== FUN_004d4aa0 @ 0x004d4aa0 ====

void FUN_004d4aa0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b0f10;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d4ac0 @ 0x004d4ac0 ====

void FUN_004d4ac0(undefined4 param_1,float *param_2,float *param_3)

{
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_18 = param_3[2] * param_2[1] - param_2[2] * param_3[1];
  local_14 = param_2[2] * *param_3 - *param_2 * param_3[2];
  local_10 = *param_2 * param_3[1] - *param_3 * param_2[1];
  local_c = local_18;
  local_8 = local_14;
  local_4 = local_10;
  thunk_FUN_0079e1ba();
  *(float **)local_4 = &local_18;
  *(float **)((int)local_4 + 4) = &local_18;
  *(float *)((int)local_4 + 8) = local_18;
  return;
}


// ==== FUN_004d4b70 @ 0x004d4b70 ====

void FUN_004d4b70(void)

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
  puStack_8 = &LAB_009810f8;
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


// ==== FUN_004d4be0 @ 0x004d4be0 ====

void * FUN_004d4be0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009810e1;
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


// ==== Catch@004d4c52 @ 0x004d4c52 ====

void Catch_004d4c52(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004d4c70 @ 0x004d4c70 ====

void FUN_004d4c70(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_009810f8;
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
  piVar4 = (int *)FUN_004d4be0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_004d4d69:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_004d4d69;
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


// ==== FUN_004d4e50 @ 0x004d4e50 ====

/* WARNING: Removing unreachable block (ram,0x004d4eaf) */

void FUN_004d4e50(undefined4 *param_1,undefined4 *param_2)

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
LAB_004d4ee0:
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
        if (uVar5 == 0) goto LAB_004d4ee0;
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
      puVar6 = (undefined4 *)FUN_004d4c70(&param_2,1,puVar6,iVar3);
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
    puVar6 = (undefined4 *)FUN_004d4c70(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_004d4fc0 @ 0x004d4fc0 ====

void FUN_004d4fc0(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b0e80;
  in_ECX[2] = *param_2;
  in_ECX[3] = param_2[1];
  in_ECX[4] = param_2[2];
  in_ECX[5] = param_2[3];
  in_ECX[6] = param_3;
  return;
}


// ==== FUN_004d5000 @ 0x004d5000 ====

undefined4 FUN_004d5000(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_004d5040 @ 0x004d5040 ====

undefined4 FUN_004d5040(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x18);
}


// ==== FUN_004d5050 @ 0x004d5050 ====

void FUN_004d5050(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b0f58;
  return;
}


// ==== FUN_004d5060 @ 0x004d5060 ====

void FUN_004d5060(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b0f58;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d5080 @ 0x004d5080 ====

int FUN_004d5080(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1c) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0x20) - *(int *)(in_ECX + 0x1c) >> 2;
}


// ==== FUN_004d50a0 @ 0x004d50a0 ====

int FUN_004d50a0(void)

{
  int in_ECX;
  int iVar1;
  
  if (*(int *)(in_ECX + 0x1c) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(in_ECX + 0x20) - *(int *)(in_ECX + 0x1c) >> 2;
  }
  if (*(int *)(in_ECX + 0xc) == 0) {
    return iVar1;
  }
  return (*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc)) / 0x1c + iVar1;
}


// ==== FUN_004d50e0 @ 0x004d50e0 ====

void FUN_004d50e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b0f6c;
  in_ECX[1] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  return;
}


// ==== FUN_004d5130 @ 0x004d5130 ====

void FUN_004d5130(void)

{
  undefined4 *_Dst;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009811ab;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009b0f6c;
  local_4 = 2;
  if (in_ECX[1] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x1c))(in_ECX[1]);
    in_ECX[1] = 0;
  }
  while ((_Dst = (undefined4 *)in_ECX[7], _Dst != (undefined4 *)0x0 &&
         (local_10 = in_ECX[8] - (int)_Dst >> 2, local_10 != 0))) {
    uVar1 = *_Dst;
    _memmove(_Dst,_Dst + 1,(in_ECX[8] - (int)(_Dst + 1) >> 2) * 4);
    in_ECX[8] = in_ECX[8] + -4;
    (**(code **)(*DAT_00b5ac10 + 8))(uVar1);
  }
  if ((void *)in_ECX[7] != (void *)0x0) {
    _free((void *)in_ECX[7]);
    return;
  }
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  if (in_ECX[3] == 0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = &PTR_FUN_009b0f58;
    ExceptionList = pvStack_c;
    return;
  }
  FUN_00405de0(in_ECX[3],in_ECX[4],in_ECX + 2,local_10);
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_004d5220 @ 0x004d5220 ====

uint FUN_004d5220(void)

{
  int iVar1;
  uint uVar2;
  uint extraout_EAX;
  int in_ECX;
  undefined1 auStack_2a [2];
  void *local_28;
  undefined1 local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009811bd;
  local_c = ExceptionList;
  if (*(int *)(in_ECX + 0xc) != 0) {
    iVar1 = (*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc)) / 0x1c;
    if (iVar1 != 0) {
      local_10 = (void *)0xf;
      local_14 = 0;
      local_24 = 0;
      ExceptionList = &local_c;
      FUN_00401660(*(undefined4 *)(in_ECX + 0xc),0,0xffffffff);
      local_4 = 0;
      FUN_0040c0e0(*(int *)(in_ECX + 0xc) + 0x1c,*(undefined4 *)(in_ECX + 0x10),
                   *(int *)(in_ECX + 0xc),iVar1);
      FUN_00405de0(*(int *)(in_ECX + 0x10) + -0x1c,*(int *)(in_ECX + 0x10),in_ECX + 8,iVar1);
      *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + -0x1c;
      iVar1 = (**(code **)(*DAT_00b5ac10 + 4))(&local_28);
      uVar2 = 0;
      if (iVar1 != 0) {
        uVar2 = FUN_004d56e0(auStack_2a + -6);
      }
      if (local_14 < 0x10) {
        ExceptionList = local_10;
        return uVar2 & 0xffffff00;
      }
      _free(local_28);
      return extraout_EAX;
    }
  }
  return 1;
}


// ==== FUN_004d5330 @ 0x004d5330 ====

void FUN_004d5330(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  uint uVar5;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009811cf;
  local_c = ExceptionList;
  uVar5 = 0;
  local_4 = 0;
  ExceptionList = &local_c;
  piVar2 = (int *)FUN_004d5470(param_1);
  *(int **)(in_ECX + 4) = piVar2;
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 4))();
    iVar3 = *(int *)(iVar3 + 0x1c);
    if (*(int *)(iVar3 + 0xc) != 0) {
      iVar4 = 0;
      do {
        iVar1 = *(int *)(iVar3 + 0x14);
        if ((iVar1 == 0) || ((uint)((*(int *)(iVar3 + 0x18) - iVar1) / 0x3c) <= uVar5)) {
                    /* WARNING: Subroutine does not return */
          FUN_004ae940();
        }
        FUN_00406720(iVar1 + 0x20 + iVar4);
        uVar5 = uVar5 + 1;
        iVar4 = iVar4 + 0x3c;
      } while (uVar5 < *(uint *)(iVar3 + 0xc));
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004d5400 @ 0x004d5400 ====

void FUN_004d5400(void)

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
  puStack_8 = &LAB_00981138;
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


// ==== FUN_004d5470 @ 0x004d5470 ====

undefined4 FUN_004d5470(undefined4 param_1)

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
  puStack_8 = &LAB_00981158;
  pvStack_c = ExceptionList;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660(param_1,0,0xffffffff);
  local_10 = (void *)0x2;
  local_4 = 0;
  uVar1 = (**(code **)(*DAT_00b5a7cc + 8))(&local_2c);
  if (local_18 < 0x10) {
    ExceptionList = local_10;
    return uVar1;
  }
  _free(local_2c);
  return extraout_EAX;
}


// ==== FUN_004d5500 @ 0x004d5500 ====

void FUN_004d5500(void *param_1,uint param_2,undefined4 *param_3)

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
      uVar7 = FUN_004d5400();
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


// ==== FUN_004d56e0 @ 0x004d56e0 ====

void FUN_004d56e0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_004d5500(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_004d5730 @ 0x004d5730 ====

void FUN_004d5730(int *param_1,int param_2)

{
  int in_ECX;
  
  FUN_0040c0e0(param_2 + 0x1c,*(undefined4 *)(in_ECX + 8),param_2,param_2);
  FUN_00405de0(*(int *)(in_ECX + 8) + -0x1c,*(int *)(in_ECX + 8));
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + -0x1c;
  *param_1 = param_2;
  return;
}


// ==== FUN_004d5770 @ 0x004d5770 ====

void FUN_004d5770(byte param_1)

{
  void *in_ECX;
  
  FUN_004d5130();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d5790 @ 0x004d5790 ====

int FUN_004d5790(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_004b5520();
  return iVar1 + *(int *)(in_ECX + 0xc);
}


// ==== FUN_004d57a0 @ 0x004d57a0 ====

int FUN_004d57a0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_004b5580();
  return iVar1 + *(int *)(in_ECX + 0x10);
}


// ==== FUN_004d57b0 @ 0x004d57b0 ====

void FUN_004d57b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b0fc8;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[4] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  *(undefined1 *)((int)in_ECX + 0x15) = 0;
  return;
}


// ==== FUN_004d57d0 @ 0x004d57d0 ====

void FUN_004d57d0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009811e8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009b0fc8;
  local_4 = 0;
  if (*(char *)((int)in_ECX + 0x15) == '\0') {
    if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[1])(1);
    }
  }
  else {
    if (in_ECX[1] == 0) goto LAB_004d5824;
    (**(code **)(*DAT_00b5a7cc + 0x1c))(in_ECX[1]);
  }
  in_ECX[1] = 0;
LAB_004d5824:
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_009b0f58;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_004d5850 @ 0x004d5850 ====

undefined4 FUN_004d5850(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  undefined1 auStack_48 [4];
  void *pvStack_44;
  undefined4 uStack_34;
  uint uStack_30;
  undefined1 auStack_2c [4];
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_00981202;
  local_c = ExceptionList;
  if (*(int *)(in_ECX + 4) != 0) {
    ExceptionList = &local_c;
    if (*(char *)(in_ECX + 0x14) == '\0') {
      ExceptionList = &local_c;
      cVar1 = FUN_004ab4c0();
      if (cVar1 == '\0') {
        *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 1;
        ExceptionList = local_c;
        return 0;
      }
      iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      FUN_004a9c30(*(undefined4 *)(iVar2 + 0x1c));
      uStack_14 = 0xf;
      uStack_18 = 0;
      pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
      uStack_10 = 0xffff;
      iStack_4 = 0;
      uStack_10 = (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
      uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      uVar3 = FUN_004a7bb0(auStack_48,uVar3);
      iStack_4._0_1_ = 1;
      FUN_00401660(uVar3,0,0xffffffff);
      iStack_4 = (uint)iStack_4._1_3_ << 8;
      if (0xf < uStack_30) {
        _free(pvStack_44);
        return extraout_EAX;
      }
      uStack_30 = 0xf;
      uStack_34 = 0;
      pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
      iVar2 = (**(code **)(*DAT_00b5a7d0 + 4))(auStack_2c);
      if (iVar2 == 0) {
        iVar2 = **(int **)(in_ECX + 4);
        uVar3 = (**(code **)(*DAT_00b5a6ac + 0x18))();
        (**(code **)(iVar2 + 0x18))(uVar3);
        (**(code **)(**(int **)(in_ECX + 4) + 0x1c))();
        (**(code **)(*DAT_00b5a7d0 + 8))(&uStack_30,*(undefined4 *)(in_ECX + 4));
        *(undefined1 *)(in_ECX + 0x15) = 1;
      }
      *(undefined1 *)(in_ECX + 0x14) = 1;
      iStack_4 = 0xffffffff;
      if (0xf < uStack_14) {
        _free(pvStack_28);
        return extraout_EAX_00;
      }
      uStack_14 = 0xf;
      uStack_18 = 0;
      pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
    }
    iStack_4 = 0xffffffff;
    cVar1 = FUN_004b59a0();
    if (cVar1 == '\0') {
      ExceptionList = local_c;
      return 0;
    }
    *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(in_ECX + 0x10);
  }
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_004d59e0 @ 0x004d59e0 ====

void FUN_004d59e0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  void *pvVar8;
  int in_ECX;
  int *piVar9;
  int iVar10;
  undefined1 local_88 [4];
  void *local_84;
  undefined4 local_74;
  uint local_70;
  int local_6c;
  int local_68;
  undefined1 local_64 [4];
  void *local_60;
  undefined4 local_50;
  uint local_4c;
  undefined1 local_48 [4];
  void *local_44;
  undefined4 local_34;
  uint local_30;
  undefined1 local_2c [4];
  void *local_28;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098129f;
  local_c = ExceptionList;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  local_10 = 0xffff;
  local_4 = 0;
  ExceptionList = &local_c;
  local_68 = in_ECX;
  uVar6 = FUN_004a7bb0(local_64,param_1);
  local_4._0_1_ = 1;
  FUN_00401660(uVar6,0,0xffffffff);
  local_4 = (uint)local_4._1_3_ << 8;
  if (0xf < local_4c) {
    _free(local_60);
    return;
  }
  local_10 = 1;
  iVar7 = FUN_004a8060(local_2c);
  if (iVar7 != 0) {
    pvVar8 = operator_new(0x84);
    local_4._0_1_ = 2;
    if (pvVar8 == (void *)0x0) {
      uVar6 = 0;
    }
    else {
      local_70 = 0xf;
      local_74 = 0;
      local_84 = (void *)((uint)local_84 & 0xffffff00);
      FUN_00401740(s_EMPTY_009b0fb8,5);
      local_4 = CONCAT31(local_4._1_3_,3);
      uVar6 = FUN_004b5800(local_88);
    }
    *(undefined4 *)(in_ECX + 8) = uVar6;
    local_4 = 0;
    if ((pvVar8 != (void *)0x0) && (0xf < local_70)) {
      _free(local_84);
      return;
    }
    local_30 = 0xf;
    local_34 = 0;
    local_44 = (void *)((uint)local_44 & 0xffffff00);
    FUN_00401660(iVar7 + 0xac,0,0xffffffff);
    iVar10 = *(int *)(iVar7 + 0x1c);
    iVar2 = *(int *)(iVar7 + 0x20);
    for (; iVar10 != iVar2; iVar10 = iVar10 + 0x1c) {
      local_4._0_1_ = 5;
      uVar6 = FUN_00405bd0(local_88,local_48,iVar10);
      local_4._0_1_ = 6;
      FUN_004b5bf0(0,uVar6);
      local_4._0_1_ = 5;
      if (0xf < local_70) {
        _free(local_84);
        return;
      }
      local_70 = 0xf;
      local_74 = 0;
      local_84 = (void *)((uint)local_84 & 0xffffff00);
    }
    local_4._0_1_ = 5;
    piVar3 = *(int **)(iVar7 + 0x88);
    piVar9 = (int *)*piVar3;
    if (piVar9 != piVar3) {
      do {
        FUN_004b5bf0(0xe,piVar9 + 3);
        if (*(char *)((int)piVar9 + 0x39) == '\0') {
          piVar4 = (int *)piVar9[2];
          if (*(char *)((int)piVar4 + 0x39) == '\0') {
            cVar1 = *(char *)(*piVar4 + 0x39);
            piVar9 = piVar4;
            piVar4 = (int *)*piVar4;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar4 + 0x39);
              piVar9 = piVar4;
              piVar4 = (int *)*piVar4;
            }
          }
          else {
            cVar1 = *(char *)(piVar9[1] + 0x39);
            piVar5 = (int *)piVar9[1];
            piVar4 = piVar9;
            while ((piVar9 = piVar5, cVar1 == '\0' && (piVar4 == (int *)piVar9[2]))) {
              cVar1 = *(char *)(piVar9[1] + 0x39);
              piVar5 = (int *)piVar9[1];
              piVar4 = piVar9;
            }
          }
        }
      } while (piVar9 != piVar3);
    }
    piVar3 = *(int **)(iVar7 + 0xa4);
    piVar9 = (int *)*piVar3;
    if (piVar9 != piVar3) {
      local_6c = iVar7 + 0x90;
      do {
        iVar10 = *(int *)(local_6c + 4);
        if ((iVar10 == 0) || ((uint)((*(int *)(local_6c + 8) - iVar10) / 0x1c) <= (uint)piVar9[3]))
        {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        local_70 = 0xf;
        local_74 = 0;
        local_84 = (void *)((uint)local_84 & 0xffffff00);
        FUN_00401660(iVar10 + piVar9[3] * 0x1c,0,0xffffffff);
        local_4._0_1_ = 7;
        uVar6 = FUN_00405bd0(local_64,local_48,local_88);
        local_4._0_1_ = 8;
        FUN_004b5bf0(0,uVar6);
        if (0xf < local_4c) {
          _free(local_60);
          return;
        }
        local_4c = 0xf;
        local_50 = 0;
        local_60 = (void *)((uint)local_60 & 0xffffff00);
        local_4._0_1_ = 5;
        if (0xf < local_70) {
          _free(local_84);
          return;
        }
        local_70 = 0xf;
        local_74 = 0;
        local_84 = (void *)((uint)local_84 & 0xffffff00);
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
      } while (piVar9 != piVar3);
      in_ECX = local_68;
    }
    pvVar8 = operator_new(0xe4);
    local_4._0_1_ = 9;
    if (pvVar8 == (void *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_004a7bb0(local_64,param_1);
      local_4 = CONCAT31(local_4._1_3_,10);
      uVar6 = FUN_004aa110(uVar6);
    }
    *(undefined4 *)(in_ECX + 4) = uVar6;
    local_4 = 5;
    if ((pvVar8 != (void *)0x0) && (0xf < local_4c)) {
      _free(local_60);
      return;
    }
    *(undefined4 *)(in_ECX + 0xc) = 0;
    uVar6 = FUN_004a88f0(iVar7);
    *(undefined4 *)(in_ECX + 0x10) = uVar6;
    *(undefined1 *)(in_ECX + 0x15) = 0;
    if (0xf < local_30) {
      _free(local_44);
      return;
    }
    local_30 = 0xf;
    local_34 = 0;
    local_44 = (void *)((uint)local_44 & 0xffffff00);
  }
  if (local_14 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_28);
  return;
}


// ==== FUN_004d5e70 @ 0x004d5e70 ====

void FUN_004d5e70(byte param_1)

{
  void *in_ECX;
  
  FUN_004d57d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d5e90 @ 0x004d5e90 ====

undefined4 FUN_004d5e90(void)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(100);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004d60d0();
  return uVar2;
}


// ==== FUN_004d5eb0 @ 0x004d5eb0 ====

void FUN_004d5eb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1128;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d5f30 @ 0x004d5f30 ====

undefined4 FUN_004d5f30(undefined4 param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x20);
  for (puVar3 = *(undefined4 **)(in_ECX + 0x1c); puVar3 != puVar1; puVar3 = puVar3 + 1) {
    cVar2 = (**(code **)(*(int *)*puVar3 + 8))(param_1);
    if (cVar2 != '\0') {
      return 1;
    }
  }
  puVar3 = *(undefined4 **)(in_ECX + 0x54);
  puVar1 = *(undefined4 **)(in_ECX + 0x58);
  while( true ) {
    if (puVar3 == puVar1) {
      return 0;
    }
    cVar2 = (**(code **)(*(int *)*puVar3 + 4))(param_1);
    if (cVar2 == '\x01') break;
    puVar3 = puVar3 + 1;
  }
  return 1;
}


// ==== FUN_004d5f90 @ 0x004d5f90 ====

undefined4 FUN_004d5f90(void)

{
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0x28) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x28))(1);
  }
  *(undefined4 *)(in_ECX + 0x28) = 0;
  FUN_004d6930();
  FUN_004eb890(in_ECX + 0x18);
  FUN_004eb890(in_ECX + 0x50);
  FUN_0065b720();
  FUN_006ea5d0();
  FUN_0065a200();
  if (*(undefined4 **)(in_ECX + 0x60) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x60))(1);
  }
  *(undefined4 *)(in_ECX + 0x60) = 0;
  if (*(undefined4 **)(in_ECX + 0x48) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x48))(1);
  }
  *(undefined4 *)(in_ECX + 0x48) = 0;
  if (*(undefined4 **)(in_ECX + 0x44) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x44))(1);
  }
  *(undefined4 *)(in_ECX + 0x44) = 0;
  if (*(undefined4 **)(in_ECX + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x40))(1);
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  if (*(undefined4 **)(in_ECX + 0x34) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x34))(1);
  }
  *(undefined4 *)(in_ECX + 0x34) = 0;
  if (*(undefined4 **)(in_ECX + 0x3c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x3c))(1);
  }
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  if (*(undefined4 **)(in_ECX + 0x38) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x38))(1);
  }
  *(undefined4 *)(in_ECX + 0x38) = 0;
  if (*(undefined4 **)(in_ECX + 0x4c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x4c))(1);
  }
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  FUN_004d8420();
  FUN_004d7af0();
  FUN_004d78e0();
  FUN_004d6990();
  return 1;
}


// ==== FUN_004d6070 @ 0x004d6070 ====

void FUN_004d6070(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1150;
  FUN_004d5f90();
  FUN_004d8f20();
  if ((void *)in_ECX[0x15] != (void *)0x0) {
    _free((void *)in_ECX[0x15]);
    return;
  }
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  if ((void *)in_ECX[7] == (void *)0x0) {
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    in_ECX[9] = 0;
    FUN_004d8730();
    *in_ECX = &PTR_FUN_009b1128;
    return;
  }
  _free((void *)in_ECX[7]);
  return;
}


// ==== FUN_004d60d0 @ 0x004d60d0 ====

void FUN_004d60d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1150;
  FUN_004d87c0();
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  FUN_0089cec0();
  in_ECX[0xd] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  FUN_004d8ee0();
  return;
}


// ==== FUN_004d6110 @ 0x004d6110 ====

void FUN_004d6110(void)

{
  int iVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int in_ECX;
  undefined4 local_4;
  
  pvVar3 = operator_new(0x3c);
  if (pvVar3 == (void *)0x0) {
    local_4 = 0;
  }
  else {
    local_4 = FUN_004d97d0();
  }
  iVar1 = *(int *)(in_ECX + 0x54);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x5c) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x58) - iVar1 >> 2)))
  {
    FUN_004d66a0(*(undefined4 *)(in_ECX + 0x58),1,&local_4);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x58);
  *puVar2 = local_4;
  *(undefined4 **)(in_ECX + 0x58) = puVar2 + 1;
  return;
}


// ==== FUN_004d6180 @ 0x004d6180 ====

void FUN_004d6180(void)

{
  int iVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int *piVar4;
  int in_ECX;
  int *piStack_4;
  
  pvVar3 = operator_new(0x1c);
  if (pvVar3 == (void *)0x0) {
    piStack_4 = (int *)0x0;
  }
  else {
    piStack_4 = (int *)FUN_004dca90();
  }
  (**(code **)(*piStack_4 + 4))();
  iVar1 = *(int *)(in_ECX + 0x1c);
  piStack_4 = piStack_4 + 1;
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x24) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x20) - iVar1 >> 2)))
  {
    FUN_004d66a0(*(undefined4 *)(in_ECX + 0x20),1,&piStack_4);
  }
  else {
    piVar4 = *(int **)(in_ECX + 0x20);
    *piVar4 = (int)piStack_4;
    *(int **)(in_ECX + 0x20) = piVar4 + 1;
  }
  FUN_004dc960();
  iVar1 = *(int *)(in_ECX + 0x1c);
  piStack_4 = DAT_00b5ac5c;
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x24) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x20) - iVar1 >> 2)))
  {
    FUN_004d66a0(*(undefined4 *)(in_ECX + 0x20),1,&piStack_4);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0x20);
    *puVar2 = DAT_00b5ac5c;
    *(undefined4 **)(in_ECX + 0x20) = puVar2 + 1;
  }
  pvVar3 = operator_new(0x14);
  if (pvVar3 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_004dbd50();
  }
  FUN_004dbd70();
  iVar1 = *(int *)(in_ECX + 0x1c);
  piStack_4 = piVar4;
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x24) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x20) - iVar1 >> 2)))
  {
    FUN_004d66a0(*(undefined4 *)(in_ECX + 0x20),1,&piStack_4);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0x20);
    *puVar2 = piVar4;
    *(undefined4 **)(in_ECX + 0x20) = puVar2 + 1;
  }
  pvVar3 = operator_new(0xb8);
  if (pvVar3 == (void *)0x0) {
    piStack_4 = (int *)0x0;
  }
  else {
    piStack_4 = (int *)FUN_004dadd0();
  }
  iVar1 = *(int *)(in_ECX + 0x1c);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x24) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x20) - iVar1 >> 2)))
  {
    FUN_004d66a0(*(undefined4 *)(in_ECX + 0x20),1,&piStack_4);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x20);
  *puVar2 = piStack_4;
  *(undefined4 **)(in_ECX + 0x20) = puVar2 + 1;
  return;
}


// ==== FUN_004d6320 @ 0x004d6320 ====

undefined4 FUN_004d6320(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int in_ECX;
  undefined4 local_4;
  
  FUN_004d83c0();
  pvVar1 = operator_new(4);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004e39c0();
  }
  *(undefined4 *)(in_ECX + 0x4c) = uVar2;
  pvVar1 = operator_new(4);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005500a0();
  }
  *(undefined4 *)(in_ECX + 0x38) = uVar2;
  pvVar1 = operator_new(4);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0065b780();
  }
  *(undefined4 *)(in_ECX + 0x3c) = uVar2;
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004e32b0();
  }
  *(undefined4 *)(in_ECX + 0x34) = uVar2;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004e2760();
  }
  *(undefined4 *)(in_ECX + 0x40) = uVar2;
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004e1890();
  }
  *(undefined4 *)(in_ECX + 0x44) = uVar2;
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004e0ac0();
  }
  *(undefined4 *)(in_ECX + 0x48) = uVar2;
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004e0380();
  }
  *(undefined4 *)(in_ECX + 0x60) = uVar2;
  thunk_FUN_0081cfb0();
  FUN_004e0330();
  pvVar1 = operator_new(0x28);
  if (pvVar1 == (void *)0x0) {
    local_4 = 0;
  }
  else {
    local_4 = FUN_004ded80();
  }
  thunk_FUN_004deb80();
  iVar5 = *(int *)(in_ECX + 0x1c);
  if ((iVar5 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x24) - iVar5 >> 2) <= (uint)(*(int *)(in_ECX + 0x20) - iVar5 >> 2)))
  {
    FUN_004d66a0(*(undefined4 *)(in_ECX + 0x20),1,&local_4);
  }
  else {
    puVar4 = *(undefined4 **)(in_ECX + 0x20);
    *puVar4 = local_4;
    *(undefined4 **)(in_ECX + 0x20) = puVar4 + 1;
  }
  pvVar1 = operator_new(0x18);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004dd6c0();
  }
  FUN_004dcf60();
  iVar5 = *(int *)(in_ECX + 0x1c);
  local_4 = uVar2;
  if ((iVar5 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x24) - iVar5 >> 2) <= (uint)(*(int *)(in_ECX + 0x20) - iVar5 >> 2)))
  {
    FUN_004d66a0(*(undefined4 *)(in_ECX + 0x20),1,&local_4);
  }
  else {
    puVar4 = *(undefined4 **)(in_ECX + 0x20);
    *puVar4 = uVar2;
    *(undefined4 **)(in_ECX + 0x20) = puVar4 + 1;
  }
  FUN_006ea490();
  FUN_0065b6c0();
  FUN_004d7220();
  FUN_004d6180();
  FUN_004d86b0();
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  puVar4 = (undefined4 *)(**(code **)(*piVar3 + 0x1c))();
  *puVar4 = 1;
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar5 = (**(code **)(*piVar3 + 0x1c))();
  *(undefined4 *)(iVar5 + 4) = 1;
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004dcd80();
  }
  *(undefined4 *)(in_ECX + 0x28) = uVar2;
  FUN_004d78c0();
  FUN_004d7ab0();
  puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar4 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    FUN_004d68f0();
    return 1;
  }
  *puVar4 = &PTR_FUN_009b113c;
  FUN_00797a20(puVar4);
  FUN_004d68f0();
  return 1;
}


// ==== FUN_004d65a0 @ 0x004d65a0 ====

undefined4 FUN_004d65a0(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  cVar1 = FUN_004d5f30(param_1);
  if (((((cVar1 == '\0') && (cVar1 = (**(code **)(*DAT_00b5ac4c + 0x14))(param_1), cVar1 == '\0'))
       && (cVar1 = (**(code **)(*DAT_00b5a748 + 8))(param_1), cVar1 == '\0')) &&
      ((cVar1 = (**(code **)(**(int **)(in_ECX + 0x28) + 4))(param_1), cVar1 == '\0' &&
       (cVar1 = (**(code **)(**(int **)(in_ECX + 0x34) + 0xc))(param_1), cVar1 == '\0')))) &&
     ((cVar1 = FUN_004d8460(param_1), cVar1 == '\0' &&
      (cVar1 = (**(code **)(*DAT_00b5ac44 + 4))(param_1), cVar1 == '\0')))) {
    if ((DAT_00b5a79c != (int *)0x0) &&
       (cVar1 = (**(code **)(*DAT_00b5a79c + 0x10))(param_1), cVar1 != '\0')) {
      return 1;
    }
    cVar1 = (**(code **)(*DAT_00b5ac24 + 4))(param_1);
    if (cVar1 != '\x01') {
      iVar2 = (**(code **)(*param_1 + 4))();
      if (iVar2 == 0x40001) {
        FUN_0089cf30(param_1[2]);
      }
      else if (iVar2 == 0x50060001) {
        FUN_004d6110(param_1);
        return 1;
      }
      return 0;
    }
  }
  return 1;
}


// ==== FUN_004d6670 @ 0x004d6670 ====

undefined4 FUN_004d6670(void)

{
  return 0x50010002;
}


// ==== FUN_004d6680 @ 0x004d6680 ====

void FUN_004d6680(byte param_1)

{
  void *in_ECX;
  
  FUN_004d6070();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d66a0 @ 0x004d66a0 ====

void FUN_004d66a0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_009812b0;
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


// ==== Catch@004d6801 @ 0x004d6801 ====

void Catch_004d6801(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_004d68f0 @ 0x004d68f0 ====

void FUN_004d68f0(void)

{
  void *pvVar1;
  
  if (DAT_00b5ac70 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_004e55f0();
    }
  }
  if (DAT_00b5ac6c == 0) {
    pvVar1 = operator_new(0x10);
    if (pvVar1 != (void *)0x0) {
      FUN_004e47d0();
      return;
    }
  }
  return;
}


// ==== FUN_004d6930 @ 0x004d6930 ====

void FUN_004d6930(void)

{
  if (DAT_00b5ac70 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ac70)(1);
  }
  if (DAT_00b5ac6c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ac6c)(1);
  }
  return;
}


// ==== FUN_004d6960 @ 0x004d6960 ====

void FUN_004d6960(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b14ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d6980 @ 0x004d6980 ====

undefined4 FUN_004d6980(void)

{
  return 0x50050001;
}


// ==== FUN_004d6990 @ 0x004d6990 ====

void FUN_004d6990(void)

{
  if (DAT_00b5ac24 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ac24)(1);
  }
  return;
}


// ==== FUN_004d69b0 @ 0x004d69b0 ====

undefined1 * FUN_004d69b0(void)

{
  undefined1 *extraout_EAX;
  undefined1 *extraout_EAX_00;
  undefined1 *extraout_EAX_01;
  undefined1 *extraout_EAX_02;
  undefined1 *extraout_EAX_03;
  undefined1 *extraout_EAX_04;
  undefined1 *extraout_EAX_05;
  undefined1 *extraout_EAX_06;
  undefined1 *extraout_EAX_07;
  undefined1 *extraout_EAX_08;
  undefined1 *extraout_EAX_09;
  undefined1 *extraout_EAX_10;
  undefined1 *extraout_EAX_11;
  undefined1 *extraout_EAX_12;
  undefined1 *extraout_EAX_13;
  int iVar1;
  undefined4 uVar2;
  undefined1 *extraout_EAX_14;
  undefined4 *in_ECX;
  uint unaff_EBX;
  void *unaff_EBP;
  uint unaff_ESI;
  void *unaff_EDI;
  undefined1 auStackY_100 [48];
  undefined1 *puVar3;
  void *_Memory;
  undefined1 auStack_8e [2];
  undefined4 uStack_80;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uStack_34;
  undefined1 auStack_1e [2];
  uint local_1c;
  uint local_18;
  uint uStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009b14e4;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ac24 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ac24 = in_ECX;
  }
  uStack_34 = 0xd;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = local_18 & 0xffffff00;
  FUN_00401740();
  uStack_34 = 0;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uStack_c) {
    _free(in_ECX);
    return extraout_EAX;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  FUN_00401740();
  uVar9 = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uStack_14) {
    _free(unaff_EBP);
    return extraout_EAX_00;
  }
  uStack_14 = 0xf;
  local_18 = 0;
  FUN_00401740();
  uVar8 = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < local_1c) {
    _free(unaff_EDI);
    return extraout_EAX_01;
  }
  local_1c = 0xf;
  FUN_00401740();
  uVar7 = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < unaff_EBX) {
    _free(&local_1c);
    return extraout_EAX_02;
  }
  FUN_00401740();
  uVar6 = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < unaff_ESI) {
    _free(auStack_1e + -6);
    return extraout_EAX_03;
  }
  FUN_00401740();
  uVar5 = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uStack_34) {
    _free(auStack_1e + -0xe);
    return extraout_EAX_04;
  }
  uStack_34 = 0xf;
  FUN_00401740();
  uVar4 = 3;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uVar9) {
    _free(&uStack_34);
    return extraout_EAX_05;
  }
  FUN_00401740();
  uVar9 = 3;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uVar8) {
    _free(auStack_1e + -0x1e);
    return extraout_EAX_06;
  }
  FUN_00401740();
  uVar8 = 3;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uVar7) {
    _free(auStack_1e + -0x26);
    return extraout_EAX_07;
  }
  FUN_00401740();
  uVar7 = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uVar6) {
    _free(auStack_1e + -0x2e);
    return extraout_EAX_08;
  }
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uVar5) {
    _free(auStack_1e + -0x36);
    return extraout_EAX_09;
  }
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uVar4) {
    _free(auStack_8e + 0x32);
    return extraout_EAX_10;
  }
  FUN_00401740(s_dirbacklight_intensity_009b124c);
  _Memory = (void *)0x1;
  puVar3 = auStack_8e + 0x12;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uVar9) {
    _free(auStack_8e + 0x2a);
    return extraout_EAX_11;
  }
  uStack_80 = auStackY_100;
  FUN_00401740(s_shadelightpos_009b1264,0xd);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(auStack_8e + 10,3);
  if (0xf < uVar8) {
    _free(auStack_8e + 0x22);
    return extraout_EAX_12;
  }
  FUN_00401740(s_shadelightdistance_009b1274,0x12);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(auStack_8e + 2,1);
  if (0xf < uVar7) {
    _free(auStack_8e + 0x1a);
    return extraout_EAX_13;
  }
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  *(undefined1 *)((int)in_ECX + 6) = 1;
  iVar1 = (**(code **)(*DAT_00b5a6e4 + 8))();
  puVar3[6] = *(undefined1 *)(iVar1 + 0x58);
  FUN_00401740(s_settracealone__d_009b1288,0x10);
  uVar2 = FUN_00404230(auStack_8e + -6);
  (**(code **)(*DAT_00b5a688 + 4))(uVar2);
  if (uStack_80 < (undefined1 *)0x10) {
    return puVar3;
  }
  _free(_Memory);
  return extraout_EAX_14;
}


// ==== FUN_004d6e30 @ 0x004d6e30 ====

/* WARNING: Removing unreachable block (ram,0x004d7076) */
/* WARNING: Removing unreachable block (ram,0x004d7037) */
/* WARNING: Removing unreachable block (ram,0x004d70b5) */
/* WARNING: Removing unreachable block (ram,0x004d6ff8) */

void FUN_004d6e30(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  void *unaff_EDI;
  undefined1 auStackY_ec [128];
  undefined1 *_Memory;
  undefined1 *_Memory_00;
  undefined1 *_Memory_01;
  undefined1 *_Memory_02;
  undefined4 *_Memory_03;
  uint uVar1;
  undefined4 uStack_30;
  void *local_1c;
  uint local_18;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  uStack_30 = (void **)0xd;
  *in_ECX = &PTR_FUN_009b14e4;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = local_18 & 0xffffff00;
  FUN_00401740();
  uStack_30 = &local_1c;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uStack_c) {
    _free(unaff_EBX);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uStack_10) {
    _free(unaff_EBP);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uStack_14) {
    _free(unaff_ESI);
    return;
  }
  uStack_14 = 0xf;
  local_18 = 0;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < local_18) {
    _free(unaff_EDI);
    return;
  }
  local_18 = 0xf;
  local_1c = (void *)0x0;
  FUN_00401740();
  _Memory_03 = &uStack_30;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if ((void *)0xf < local_1c) {
    _free(uStack_30);
    return;
  }
  local_1c = (void *)0xf;
  uStack_30 = (void **)((uint)uStack_30 & 0xffffff00);
  FUN_00401740();
  _Memory_02 = auStackY_ec + 0xb8;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  FUN_00401740();
  _Memory_01 = auStackY_ec + 0xb4;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  FUN_00401740();
  _Memory_00 = auStackY_ec + 0xb0;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  FUN_00401740(s_directionallight_intensity_009b1340);
  _Memory = auStackY_ec + 0xac;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  uStack_30 = (void **)0x0;
  FUN_00401740(s_dirbacklight_dir_009b135c,0x10);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStackY_ec + 0xa8);
  if (0xf < uStack_30) {
    _free(_Memory_03);
    return;
  }
  uStack_30 = (void **)0xf;
  uVar1 = 0;
  FUN_00401740(s_dirbacklight_color_009b1370,0x12);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStackY_ec + 0xa4);
  if (0xf < uVar1) {
    _free(_Memory_02);
    return;
  }
  uVar1 = 0;
  FUN_00401740(s_dirbacklight_intensity_009b1384,0x16);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStackY_ec + 0xa0);
  if (0xf < uVar1) {
    _free(_Memory_01);
    return;
  }
  uVar1 = 0;
  FUN_00401740(s_shadelightpos_009b139c,0xd);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStackY_ec + 0x9c);
  if (0xf < uVar1) {
    _free(_Memory_00);
    return;
  }
  uVar1 = 0;
  FUN_00401740(s_shadelightdistance_009b13ac,0x12);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStackY_ec + 0x98);
  if (uVar1 < 0x10) {
    DAT_00b5ac24 = 0;
    *in_ECX = &PTR_FUN_009b14ac;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_004d7220 @ 0x004d7220 ====

void FUN_004d7220(void)

{
  void *pvVar1;
  
  if (DAT_00b5ac24 == 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      FUN_004d69b0();
      return;
    }
  }
  return;
}


// ==== FUN_004d7240 @ 0x004d7240 ====

undefined4 FUN_004d7240(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 extraout_EAX;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 extraout_EAX_00;
  int in_ECX;
  float10 fVar8;
  undefined1 local_54 [4];
  void *local_50;
  uint local_3c;
  undefined1 auStack_38 [28];
  undefined1 local_1c [28];
  
  iVar5 = param_1 + 8;
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_clearprofiler_009b13c0,0xd);
  if (iVar3 == 0) {
    piVar4 = (int *)(**(code **)(*DAT_00b5a688 + 0x10))();
    (**(code **)(*piVar4 + 0x14))();
    return 1;
  }
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_envwnd_009b13d0,6);
  if (iVar3 == 0) {
    iVar5 = FUN_00459160(local_54,0);
    iVar5 = FUN_00403620(0,*(undefined4 *)(iVar5 + 0x14),&DAT_009b13d8,1);
    if (0xf < local_3c) {
      _free(local_50);
      return extraout_EAX;
    }
    puVar6 = operator_new(4);
    if (iVar5 == 0) {
      if (puVar6 != (undefined4 *)0x0) {
        *puVar6 = &PTR_FUN_009b14bc;
        FUN_00797a20(puVar6);
        return 1;
      }
    }
    else if (puVar6 != (undefined4 *)0x0) {
      *puVar6 = &PTR_FUN_009b14d0;
      FUN_00797a20(puVar6);
      return 1;
    }
    FUN_00797a20(0);
    return 1;
  }
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_showeffectInfo_009b13dc,0xe);
  if (iVar3 == 0) {
    uVar7 = FUN_00459160(local_54,0);
    iVar5 = thunk_FUN_00796e60(uVar7);
    *(bool *)(in_ECX + 4) = iVar5 != 0;
    if (local_3c < 0x10) {
      return 1;
    }
    _free(local_50);
    return extraout_EAX_00;
  }
  cVar1 = FUN_004036a0(iVar5,s_showlightInfo_009b13ec);
  if (cVar1 != '\0') {
    uVar7 = FUN_00459160(local_54,0);
    iVar5 = thunk_FUN_00796e60(uVar7);
    *(bool *)(in_ECX + 5) = iVar5 != 0;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  cVar1 = FUN_004036a0(iVar5,s_settracealone_009b13fc);
  if (cVar1 != '\0') {
    uVar7 = FUN_00459160(local_54,0);
    uVar2 = thunk_FUN_00796f50(uVar7);
    *(undefined1 *)(in_ECX + 6) = uVar2;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  cVar1 = FUN_004036a0(iVar5,s_ambientlightintensity_009b140c);
  if (cVar1 != '\0') {
    iVar5 = *DAT_00b5ac5c;
    uVar7 = FUN_00459160(local_54,0);
    fVar8 = (float10)thunk_FUN_00796ec0(uVar7);
    (**(code **)(iVar5 + 0x2c))((float)fVar8);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  cVar1 = FUN_004036a0(iVar5,s_ambientlightcolor_009b1424);
  if (cVar1 != '\0') {
    uVar7 = FUN_00459160(local_1c,2);
    thunk_FUN_00796ec0(uVar7);
    uVar7 = FUN_00459160(auStack_38,1);
    thunk_FUN_00796ec0(uVar7);
    uVar7 = FUN_00459160(local_54,0);
    thunk_FUN_00796ec0(uVar7);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  cVar1 = FUN_004036a0(iVar5,s_directionallight_dir_009b1438);
  if (cVar1 != '\0') {
    uVar7 = FUN_00459160(local_54,2);
    thunk_FUN_00796ec0(uVar7);
    uVar7 = FUN_00459160(auStack_38,1);
    thunk_FUN_00796ec0(uVar7);
    uVar7 = FUN_00459160(local_1c,0);
    thunk_FUN_00796ec0(uVar7);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  cVar1 = FUN_004036a0(iVar5,s_directionallight_color_009b1450);
  if (cVar1 != '\0') {
    uVar7 = FUN_00459160(local_54,2);
    thunk_FUN_00796ec0(uVar7);
    uVar7 = FUN_00459160(auStack_38,1);
    thunk_FUN_00796ec0(uVar7);
    uVar7 = FUN_00459160(local_1c,0);
    thunk_FUN_00796ec0(uVar7);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  cVar1 = FUN_004036a0(iVar5,s_directionallight_intensity_009b1468);
  if (cVar1 != '\0') {
    uVar7 = FUN_00459160(local_1c,0);
    thunk_FUN_00796ec0(uVar7);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  cVar1 = FUN_004036a0(iVar5,s_shadelightpos_009b1484);
  if (cVar1 != '\0') {
    uVar7 = FUN_00459160(local_54,2);
    thunk_FUN_00796ec0(uVar7);
    uVar7 = FUN_00459160(auStack_38,1);
    thunk_FUN_00796ec0(uVar7);
    uVar7 = FUN_00459160(local_1c,0);
    thunk_FUN_00796ec0(uVar7);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  cVar1 = FUN_004036a0(iVar5,s_shadelightdistance_009b1494);
  if (cVar1 != '\0') {
    uVar7 = FUN_00459160(local_1c,0);
    thunk_FUN_00796ec0(uVar7);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  return 0;
}


// ==== FUN_004d77c0 @ 0x004d77c0 ====

undefined4 FUN_004d77c0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_004d7240(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_004d77f0 @ 0x004d77f0 ====

void FUN_004d77f0(byte param_1)

{
  void *in_ECX;
  
  FUN_004d6e30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d7810 @ 0x004d7810 ====

void FUN_004d7810(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b14f4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d7830 @ 0x004d7830 ====

undefined4 FUN_004d7830(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_004d7840 @ 0x004d7840 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d7840(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1504;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ac2c = (undefined4 *)0x0;
    _DAT_00000000 = FUN_004e5c70(0);
    return;
  }
  DAT_00b5ac2c = in_ECX;
  uVar1 = FUN_004e5c70(0);
  in_ECX[1] = uVar1;
  return;
}


// ==== FUN_004d7890 @ 0x004d7890 ====

void FUN_004d7890(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 4))(1);
  }
  *(undefined4 *)(in_ECX + 4) = 0;
  uVar1 = FUN_004e5c70(param_1);
  *(undefined4 *)(in_ECX + 4) = uVar1;
  return;
}


// ==== FUN_004d78c0 @ 0x004d78c0 ====

void FUN_004d78c0(void)

{
  void *pvVar1;
  
  if (DAT_00b5ac2c == 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      FUN_004d7840();
      return;
    }
  }
  return;
}


// ==== FUN_004d78e0 @ 0x004d78e0 ====

void FUN_004d78e0(void)

{
  if (DAT_00b5ac2c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ac2c)(1);
  }
  return;
}


// ==== FUN_004d7900 @ 0x004d7900 ====

void FUN_004d7900(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1504;
  DAT_00b5ac2c = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009b14f4;
  return;
}


// ==== FUN_004d7930 @ 0x004d7930 ====

void FUN_004d7930(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1504;
  DAT_00b5ac2c = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009b14f4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d7980 @ 0x004d7980 ====

void FUN_004d7980(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b152c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d79d0 @ 0x004d79d0 ====

void FUN_004d79d0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = (**(code **)(*DAT_00b5acc4 + 4))();
  if (iVar2 != 0) {
    iVar1 = *DAT_00b5acdc;
    uVar3 = FUN_004e5cf0(param_1,iVar2,param_2);
    (**(code **)(iVar1 + 0x10))(uVar3);
  }
  return;
}


// ==== FUN_004d7a10 @ 0x004d7a10 ====

void FUN_004d7a10(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = (**(code **)(*DAT_00b5acc4 + 4))();
  if (iVar2 != 0) {
    iVar1 = *DAT_00b5acdc;
    uVar3 = FUN_004e5d20(param_1,iVar2,param_2);
    (**(code **)(iVar1 + 0x10))(uVar3);
  }
  return;
}


// ==== FUN_004d7a50 @ 0x004d7a50 ====

void FUN_004d7a50(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 < 2) {
    iVar1 = *DAT_00b5acdc;
    uVar2 = FUN_004e5fa0(param_1);
    (**(code **)(iVar1 + 0x10))(uVar2);
  }
  return;
}


// ==== FUN_004d7ab0 @ 0x004d7ab0 ====

void FUN_004d7ab0(void)

{
  undefined4 *puVar1;
  
  if (DAT_00b5ac28 == (undefined4 *)0x0) {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009b158c;
      if (puVar1 != (undefined4 *)0xfffffffc) {
        DAT_00b5ac28 = puVar1;
        return;
      }
      DAT_00b5ac28 = (undefined4 *)0x0;
    }
  }
  return;
}


// ==== FUN_004d7af0 @ 0x004d7af0 ====

void FUN_004d7af0(void)

{
  if (DAT_00b5ac28 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ac28)(1);
  }
  return;
}


// ==== FUN_004d7b30 @ 0x004d7b30 ====

void FUN_004d7b30(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (DAT_00b5a97c != 0) {
    cVar2 = (**(code **)(*DAT_00b5a980 + 0x28))();
    if (cVar2 == '\0') {
      iVar1 = *DAT_00b5acdc;
      uVar3 = FUN_004e5df0();
      (**(code **)(iVar1 + 0x10))(uVar3);
    }
  }
  return;
}


// ==== FUN_004d7b60 @ 0x004d7b60 ====

void FUN_004d7b60(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (DAT_00b5a97c != 0) {
    cVar2 = (**(code **)(*DAT_00b5a980 + 0x28))();
    if (cVar2 == '\0') {
      iVar1 = *DAT_00b5acdc;
      uVar3 = FUN_004e5ec0(param_1);
      (**(code **)(iVar1 + 0x10))(uVar3);
    }
  }
  return;
}


// ==== FUN_004d7ba0 @ 0x004d7ba0 ====

void FUN_004d7ba0(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (DAT_00b5a97c != 0) {
    cVar2 = (**(code **)(*DAT_00b5a980 + 0x28))();
    if (cVar2 == '\0') {
      iVar1 = *DAT_00b5acdc;
      uVar3 = FUN_004e5ee0();
      (**(code **)(iVar1 + 0x10))(uVar3);
    }
  }
  return;
}


// ==== FUN_004d7c00 @ 0x004d7c00 ====

void FUN_004d7c00(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_00b5a97c != 0) {
    cVar1 = (**(code **)(*DAT_00b5a980 + 0x28))();
    if (cVar1 == '\0') {
      iVar2 = (**(code **)(*DAT_00b5acd4 + 8))();
      if (iVar2 == 0) {
        iVar2 = *DAT_00b5acdc;
        uVar3 = FUN_004e5e30(param_1,0xffffffff,param_2);
        (**(code **)(iVar2 + 0x10))(uVar3);
      }
    }
  }
  return;
}


// ==== FUN_004d7c50 @ 0x004d7c50 ====

void FUN_004d7c50(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_00b5a97c != 0) {
    cVar1 = (**(code **)(*DAT_00b5a980 + 0x28))();
    if (cVar1 == '\0') {
      iVar2 = (**(code **)(*DAT_00b5acd4 + 8))();
      if (iVar2 == 0) {
        iVar2 = *DAT_00b5acdc;
        uVar3 = FUN_004e5d80(param_1);
        (**(code **)(iVar2 + 0x10))(uVar3);
      }
    }
  }
  return;
}


// ==== FUN_004d7ca0 @ 0x004d7ca0 ====

void FUN_004d7ca0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_00b5a97c != 0) {
    cVar1 = (**(code **)(*DAT_00b5a980 + 0x28))();
    if (cVar1 == '\0') {
      iVar2 = (**(code **)(*DAT_00b5acd4 + 8))();
      if (iVar2 == 0) {
        iVar2 = *DAT_00b5acdc;
        uVar3 = FUN_004e5ea0(param_1);
        (**(code **)(iVar2 + 0x10))(uVar3);
      }
    }
  }
  return;
}


// ==== FUN_004d7cf0 @ 0x004d7cf0 ====

void FUN_004d7cf0(undefined4 param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (DAT_00b5a97c != 0) {
    cVar1 = (**(code **)(*DAT_00b5a980 + 0x28))();
    if (cVar1 == '\0') {
      iVar3 = (**(code **)(*DAT_00b5acd4 + 8))();
      if (iVar3 == 0) {
        uVar2 = (**(code **)(*DAT_00b5a980 + 0x1c))(param_1,0,0);
        FUN_004dd240(0x17,uVar2);
        iVar3 = *DAT_00b5acdc;
        uVar4 = FUN_004e5e60(param_1);
        (**(code **)(iVar3 + 0x10))(uVar4);
      }
    }
  }
  return;
}


// ==== FUN_004d7d60 @ 0x004d7d60 ====

void FUN_004d7d60(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_00b5a97c != 0) {
    cVar1 = (**(code **)(*DAT_00b5a980 + 0x28))();
    if (cVar1 == '\0') {
      iVar2 = (**(code **)(*DAT_00b5acd4 + 8))();
      if (iVar2 == 0) {
        iVar2 = *DAT_00b5acdc;
        uVar3 = FUN_004e5e80(param_1);
        (**(code **)(iVar2 + 0x10))(uVar3);
      }
    }
  }
  return;
}


// ==== FUN_004d7db0 @ 0x004d7db0 ====

void FUN_004d7db0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_00b5a97c != 0) {
    cVar1 = (**(code **)(*DAT_00b5a980 + 0x28))();
    if (cVar1 == '\0') {
      iVar2 = (**(code **)(*DAT_00b5acd4 + 8))();
      if (iVar2 == 0) {
        iVar2 = *DAT_00b5acdc;
        uVar3 = FUN_004e5da0(param_1,1,param_2);
        (**(code **)(iVar2 + 0x10))(uVar3);
      }
    }
  }
  return;
}


// ==== FUN_004d7e00 @ 0x004d7e00 ====

void FUN_004d7e00(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_00b5a97c != 0) {
    cVar1 = (**(code **)(*DAT_00b5a980 + 0x28))();
    if (cVar1 == '\0') {
      iVar2 = (**(code **)(*DAT_00b5acd4 + 8))();
      if (iVar2 == 0) {
        iVar2 = *DAT_00b5acdc;
        uVar3 = FUN_004e5dd0(param_1);
        (**(code **)(iVar2 + 0x10))(uVar3);
      }
    }
  }
  return;
}


// ==== FUN_004d7e50 @ 0x004d7e50 ====

void FUN_004d7e50(void)

{
  char cVar1;
  int iVar2;
  
  if (DAT_00b5a97c != 0) {
    cVar1 = (**(code **)(*DAT_00b5a980 + 0x28))();
    if (cVar1 == '\0') {
      iVar2 = (**(code **)(*DAT_00b5acd4 + 8))();
      if (iVar2 == 0) {
                    /* WARNING: Could not recover jumptable at 0x004d7e7f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*DAT_00b5acdc + 4))();
        return;
      }
    }
  }
  return;
}


// ==== FUN_004d7e90 @ 0x004d7e90 ====

void FUN_004d7e90(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_00b5a97c != 0) {
    cVar1 = (**(code **)(*DAT_00b5a980 + 0x28))();
    if (cVar1 == '\0') {
      iVar2 = (**(code **)(*DAT_00b5acd4 + 8))();
      if (iVar2 == 0) {
        iVar2 = *DAT_00b5acdc;
        uVar3 = FUN_004e5df0();
        (**(code **)(iVar2 + 0x10))(uVar3);
      }
    }
  }
  return;
}


// ==== FUN_004d7ed0 @ 0x004d7ed0 ====

void FUN_004d7ed0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_00b5a97c != 0) {
    cVar1 = (**(code **)(*DAT_00b5a980 + 0x28))();
    if (cVar1 == '\0') {
      iVar2 = (**(code **)(*DAT_00b5acd4 + 8))();
      if (iVar2 == 0) {
        iVar2 = *DAT_00b5acdc;
        uVar3 = FUN_004e5cd0(param_1);
        (**(code **)(iVar2 + 0x10))(uVar3);
      }
    }
  }
  return;
}


// ==== FUN_004d7f20 @ 0x004d7f20 ====

void FUN_004d7f20(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_00b5a97c != 0) {
    cVar1 = (**(code **)(*DAT_00b5a980 + 0x28))();
    if (cVar1 == '\0') {
      iVar2 = (**(code **)(*DAT_00b5acd4 + 8))();
      if (iVar2 == 0) {
        iVar2 = *DAT_00b5acdc;
        uVar3 = FUN_004e5f20(param_1);
        (**(code **)(iVar2 + 0x10))(uVar3);
      }
    }
  }
  return;
}


// ==== FUN_004d7f70 @ 0x004d7f70 ====

undefined4 FUN_004d7f70(byte *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if ((((DAT_00b5a97c != 0) && (cVar1 = (**(code **)(*DAT_00b5a980 + 0x28))(), cVar1 == '\0')) &&
      (iVar2 = (**(code **)(*DAT_00b5acd4 + 8))(), iVar2 == 0)) && (param_1 != (byte *)0x0)) {
    switch(*(undefined4 *)(param_1 + 4)) {
    case 1:
      FUN_004d7a10(param_1 + 0xc,*param_1);
      return 1;
    case 2:
    case 4:
    case 8:
      FUN_004d79d0(*(undefined4 *)(param_1 + 8),*param_1);
      return 1;
    case 0x10:
      uVar3 = (uint)*param_1;
      uVar4 = (**(code **)(*DAT_00b5a980 + 0x10))(uVar3);
      FUN_004d79d0(uVar4,uVar3);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_004d8030 @ 0x004d8030 ====

void FUN_004d8030(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_00b5a97c != 0) {
    cVar1 = (**(code **)(*DAT_00b5a980 + 0x28))();
    if (cVar1 == '\0') {
      iVar2 = (**(code **)(*DAT_00b5acd4 + 8))();
      if (iVar2 == 0) {
        iVar2 = *DAT_00b5acdc;
        uVar3 = FUN_004e5f40(param_1);
        (**(code **)(iVar2 + 0x10))(uVar3);
      }
    }
  }
  return;
}


// ==== FUN_004d8080 @ 0x004d8080 ====

void FUN_004d8080(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_00b5a97c != 0) {
    cVar1 = (**(code **)(*DAT_00b5a980 + 0x28))();
    if (cVar1 == '\0') {
      iVar2 = (**(code **)(*DAT_00b5acd4 + 8))();
      if (iVar2 == 0) {
        iVar2 = *DAT_00b5acdc;
        uVar3 = FUN_004e5f60(param_1);
        (**(code **)(iVar2 + 0x10))(uVar3);
      }
    }
  }
  return;
}


// ==== FUN_004d80d0 @ 0x004d80d0 ====

void FUN_004d80d0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_00b5a97c != 0) {
    cVar1 = (**(code **)(*DAT_00b5a980 + 0x28))();
    if (cVar1 == '\0') {
      iVar2 = (**(code **)(*DAT_00b5acd4 + 8))();
      if (iVar2 == 0) {
        iVar2 = *DAT_00b5acdc;
        uVar3 = FUN_004e5f80(param_1);
        (**(code **)(iVar2 + 0x10))(uVar3);
      }
    }
  }
  return;
}


// ==== FUN_004d8120 @ 0x004d8120 ====

uint FUN_004d8120(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uStack_54;
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [40];
  
  uStack_54 = param_1;
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))();
  uVar3 = 0;
  if (piVar2 != (int *)0x0) {
    uVar3 = (**(code **)(*piVar2 + 0xc))();
    if (uVar3 == 5) {
      piVar2 = (int *)(**(code **)(*piVar2 + 0x14))();
      uVar4 = (**(code **)(*piVar2 + 0x24))
                        (0,&Framework::ICreature::RTTI_Type_Descriptor,
                         &Framework::Creature::IBrick::RTTI_Type_Descriptor,0);
      piVar2 = (int *)FUN_00803725(uVar4);
      uVar3 = 0;
      if (piVar2 != (int *)0x0) {
        piVar2 = (int *)(**(code **)(*piVar2 + 0x20))();
        iVar5 = (**(code **)(*piVar2 + 4))();
        if (*(int *)(iVar5 + 0x1c) == 1) {
          uVar3 = (**(code **)(*DAT_00b5acac + 0x48))();
          if (uVar3 == 1) {
            return 1;
          }
        }
        else {
          uVar3 = (**(code **)(*piVar2 + 4))();
          if (*(int *)(uVar3 + 0x1c) == 2) {
            (**(code **)(*DAT_00b5ac98 + 0x6c))();
            piVar2 = (int *)(**(code **)(*DAT_00b5acac + 0x30))();
            uVar3 = 0;
            if (piVar2 != (int *)0x0) {
              (**(code **)(*DAT_00b5ac98 + 0x78))(auStack_30,param_1);
              iVar5 = (**(code **)(*piVar2 + 0xc))();
              FUN_00401830(iVar5 + 0x200);
              cVar1 = FUN_00423420(auStack_28,&uStack_54);
              if (cVar1 == '\0') {
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
          }
        }
      }
    }
  }
  return uVar3 & 0xffffff00;
}


// ==== FUN_004d8250 @ 0x004d8250 ====

void FUN_004d8250(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  char *pcVar5;
  void *pvStack_1c;
  undefined1 uStack_18;
  uint uStack_8;
  undefined4 uStack_4;
  
  if (DAT_00b5a97c != 0) {
    cVar1 = (**(code **)(*DAT_00b5a980 + 0x28))();
    if (cVar1 == '\0') {
      iVar2 = (**(code **)(*DAT_00b5acd4 + 8))();
      if (iVar2 == 0) {
        piVar3 = (int *)(**(code **)(*DAT_00b5ac1c + 0x14))();
        iVar2 = (**(code **)(*piVar3 + 0x74))();
        uStack_4 = 0xf;
        uStack_8 = 0;
        uStack_18 = 0;
        pcVar5 = (char *)(iVar2 + 0x5c);
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        FUN_00401740((char *)(iVar2 + 0x5c),(int)pcVar5 - (iVar2 + 0x5d));
        piVar3 = DAT_00b5acdc;
        FUN_00401660(&pvStack_1c,0,0xffffffff);
        uVar4 = FUN_004e5fc0(param_1);
        (**(code **)(*piVar3 + 0x10))(uVar4);
        if (0xf < uStack_8) {
          _free(pvStack_1c);
          return;
        }
      }
    }
  }
  return;
}


// ==== FUN_004d8320 @ 0x004d8320 ====

void FUN_004d8320(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((((DAT_00b5a97c != 0) && (cVar1 = (**(code **)(*DAT_00b5a980 + 0x28))(), cVar1 == '\0')) &&
      (iVar2 = (**(code **)(*DAT_00b5acd4 + 8))(), iVar2 == 0)) &&
     (cVar1 = FUN_004d8120(param_1), cVar1 != '\x01')) {
    iVar2 = *DAT_00b5acdc;
    uVar3 = FUN_004e5d50(param_1,param_2,param_3);
    (**(code **)(iVar2 + 0x10))(uVar3);
  }
  return;
}


// ==== FUN_004d8390 @ 0x004d8390 ====

void FUN_004d8390(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5ac28 = 0;
  *in_ECX = &PTR_FUN_009b152c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d83c0 @ 0x004d83c0 ====

void FUN_004d83c0(void)

{
  void *pvVar1;
  
  if (DAT_00b5ace0 == 0) {
    pvVar1 = operator_new(0x1c);
    if (pvVar1 != (void *)0x0) {
      FUN_004e7680();
    }
  }
  if (DAT_00b5ac30 == 0) {
    pvVar1 = operator_new(0x2c);
    if (pvVar1 != (void *)0x0) {
      FUN_004e6dd0();
    }
  }
  if (DAT_00b5ace4 == 0) {
    pvVar1 = operator_new(0x20);
    if (pvVar1 != (void *)0x0) {
      FUN_004e6060();
      return;
    }
  }
  return;
}


// ==== FUN_004d8420 @ 0x004d8420 ====

void FUN_004d8420(void)

{
  if (DAT_00b5ace4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ace4)(1);
  }
  if (DAT_00b5ac30 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ac30)(1);
  }
  if (DAT_00b5ace0 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ace0)(1);
  }
  return;
}


// ==== FUN_004d8460 @ 0x004d8460 ====

undefined4 FUN_004d8460(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    cVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_004d84d0 @ 0x004d84d0 ====

void FUN_004d84d0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 4) == 0) {
    local_20 = 0xf;
    local_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_00401740(s_____Packet_SenderSelector_cpp_61_009b15e8,0x22);
    uVar1 = FUN_004022a0(local_1c,s_Empty_PacketSender_009b160c,local_38);
    FUN_00796d50(uVar1);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    if (0xf < local_20) {
      _free(local_34);
      return;
    }
  }
  else {
    (**(code **)(**(int **)(in_ECX + 4) + 8))(param_1,param_2);
  }
  return;
}


// ==== FUN_004d8570 @ 0x004d8570 ====

void FUN_004d8570(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 4) == 0) {
    local_20 = 0xf;
    local_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_00401740(s_____Packet_SenderSelector_cpp_74_009b1620,0x22);
    uVar1 = FUN_004022a0(local_1c,s_Empty_PacketSender_009b1644,local_38);
    FUN_00796d50(uVar1);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    if (0xf < local_20) {
      _free(local_34);
      return;
    }
  }
  else {
    (**(code **)(**(int **)(in_ECX + 4) + 0xc))(param_1);
  }
  return;
}


// ==== FUN_004d8610 @ 0x004d8610 ====

void FUN_004d8610(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 4) == 0) {
    local_20 = 0xf;
    local_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_00401740(s_____Packet_SenderSelector_cpp_87_009b1658,0x22);
    uVar1 = FUN_004022a0(local_1c,s_Empty_PacketSender_009b167c,local_38);
    FUN_00796d50(uVar1);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    if (0xf < local_20) {
      _free(local_34);
      return;
    }
  }
  else {
    (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  }
  return;
}


// ==== FUN_004d86b0 @ 0x004d86b0 ====

void FUN_004d86b0(void)

{
  void *pvVar1;
  int in_ECX;
  undefined4 local_10 [2];
  int local_8;
  undefined4 local_4;
  
  pvVar1 = operator_new(4);
  if (pvVar1 == (void *)0x0) {
    local_4 = 0;
  }
  else {
    local_4 = FUN_004e7e80();
  }
  local_8 = 0;
  FUN_004d8cd0(local_10,&local_8);
  local_10[0] = 0;
  FUN_004d8980(&local_8,local_10);
  if (local_8 == *(int *)(in_ECX + 0xc)) {
    *(undefined4 *)(in_ECX + 4) = 0;
    return;
  }
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(local_8 + 0x10);
  return;
}


// ==== FUN_004d8730 @ 0x004d8730 ====

void FUN_004d8730(void)

{
  undefined4 *in_ECX;
  undefined4 *local_4;
  
  *in_ECX = &PTR_FUN_009b16c4;
  local_4 = in_ECX;
  if (in_ECX[4] != 0) {
    local_4 = (undefined4 *)((uint)in_ECX & 0xffffff00);
    FUN_00409660(*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3],local_4);
    FUN_004d8940(*(undefined4 *)(in_ECX[3] + 4));
    *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
    in_ECX[4] = 0;
    *(undefined4 *)in_ECX[3] = in_ECX[3];
    *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  }
  FUN_004d8d90(&local_4,*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3]);
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_004d87c0 @ 0x004d87c0 ====

void FUN_004d87c0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  FUN_004d8bd0();
  *in_ECX = &PTR_FUN_009b16c4;
  in_ECX[1] = 0;
  iVar1 = FUN_004d88a0();
  in_ECX[3] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  *(undefined4 *)in_ECX[3] = in_ECX[3];
  *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  in_ECX[4] = 0;
  return;
}


// ==== FUN_004d8810 @ 0x004d8810 ====

void * FUN_004d8810(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009812c0;
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


// ==== Catch@004d8885 @ 0x004d8885 ====

void Catch_004d8885(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004d88a0 @ 0x004d88a0 ====

void FUN_004d88a0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009812d0;
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


// ==== Catch@004d892a @ 0x004d892a ====

void Catch_004d892a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_004d8940 @ 0x004d8940 ====

void FUN_004d8940(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_004d8940(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004d8980 @ 0x004d8980 ====

void FUN_004d8980(undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x15) == '\0') {
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
    } while (*(char *)((int)puVar2 + 0x15) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < (int)puVar3[3])) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_004d89f0 @ 0x004d89f0 ====

void FUN_004d89f0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_004d8810(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_004d8af5:
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
      if ((char)piVar6[5] == '\0') goto LAB_004d8af5;
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


// ==== FUN_004d8bd0 @ 0x004d8bd0 ====

void FUN_004d8bd0(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b16bc;
  if (DAT_00b5ac20 == (undefined4 *)0x0) {
    DAT_00b5ac20 = in_ECX;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance____NULL_009b1690,0x14);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004d8c40 @ 0x004d8c40 ====

void FUN_004d8c40(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b16bc;
  if (DAT_00b5ac20 != 0) {
    DAT_00b5ac20 = 0;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance_009b16a8,0xc);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004d8cb0 @ 0x004d8cb0 ====

void FUN_004d8cb0(byte param_1)

{
  void *in_ECX;
  
  FUN_004d8c40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d8cd0 @ 0x004d8cd0 ====

void FUN_004d8cd0(undefined4 *param_1,int *param_2)

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
      puVar5 = (undefined4 *)FUN_004d89f0(&param_2,1,puVar5,piVar3);
      uVar1 = *puVar5;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *piVar3) {
    puVar5 = (undefined4 *)FUN_004d89f0(&param_2,bVar2,puVar5,piVar3);
    *param_1 = *puVar5;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004d8d90 @ 0x004d8d90 ====

void FUN_004d8d90(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004d8940(piVar6[1]);
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


// ==== FUN_004d8e50 @ 0x004d8e50 ====

void FUN_004d8e50(byte param_1)

{
  void *in_ECX;
  
  FUN_004d8730();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d8e70 @ 0x004d8e70 ====

void FUN_004d8e70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b16cc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d8e90 @ 0x004d8e90 ====

undefined4 FUN_004d8e90(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_004d8ea0 @ 0x004d8ea0 ====

void FUN_004d8ea0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_004d8ee0 @ 0x004d8ee0 ====

void FUN_004d8ee0(void)

{
  undefined4 *puVar1;
  
  if (DAT_00b5ac84 == (undefined4 *)0x0) {
    puVar1 = operator_new(8);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009b16dc;
      puVar1[1] = 0;
      if (puVar1 + 1 != (undefined4 *)0x0) {
        DAT_00b5ac84 = puVar1;
        return;
      }
      DAT_00b5ac84 = (undefined4 *)0x0;
    }
  }
  return;
}


// ==== FUN_004d8f20 @ 0x004d8f20 ====

void FUN_004d8f20(void)

{
  if (DAT_00b5ac84 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ac84)(1);
  }
  return;
}


// ==== FUN_004d8f60 @ 0x004d8f60 ====

void FUN_004d8f60(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5ac84 = 0;
  *in_ECX = &PTR_FUN_009b16cc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d8f90 @ 0x004d8f90 ====

void FUN_004d8f90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1758;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d8fb0 @ 0x004d8fb0 ====

undefined4 FUN_004d8fb0(void)

{
  return 0;
}


// ==== FUN_004d8fc0 @ 0x004d8fc0 ====

undefined1 FUN_004d8fc0(void)

{
  return 0;
}


// ==== FUN_004d8fd0 @ 0x004d8fd0 ====

void FUN_004d8fd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1764;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d9010 @ 0x004d9010 ====

void FUN_004d9010(void)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0x2c))();
  pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
  cVar1 = *pcVar3;
  (**(code **)(*piVar2 + 0x24))(cVar1 == '\0');
  if ((cVar1 == '\0') && (*(int *)(in_ECX + 0x10) != 0)) {
    puVar4 = operator_new(8);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = &PTR_FUN_009b1798;
    }
    uVar5 = (**(code **)(**(int **)(in_ECX + 0x10) + 4))();
    puVar4[1] = uVar5;
    FUN_00797a20(puVar4);
  }
  return;
}


// ==== FUN_004d90a0 @ 0x004d90a0 ====

/* WARNING: Removing unreachable block (ram,0x004d918d) */
/* WARNING: Removing unreachable block (ram,0x004d91ce) */
/* WARNING: Removing unreachable block (ram,0x004d9100) */

void FUN_004d90a0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  uint in_ECX;
  undefined1 auStack_1e [30];
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004e8040();
  }
  *(undefined4 *)(in_ECX + 0x30) = uVar2;
  FUN_00401740(s_UI_Console_UI_Main_txt_009b16ec);
  iVar3 = FUN_00410500();
  piVar4 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar3 + 0x3c);
  *(int **)(in_ECX + 8) = piVar4;
  (**(code **)(*piVar4 + 0x40))(-(uint)(in_ECX != 4) & in_ECX);
  (**(code **)(**(int **)(in_ECX + 8) + 0x48))(*(undefined4 *)(in_ECX + 0x30));
  if (iVar3 != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar3);
  }
  FUN_00401740(s_text_out_009b1704,8);
  uVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x34))(auStack_1e + -0xe);
  *(undefined4 *)(in_ECX + 0x10) = uVar2;
  FUN_00401740(s_edit_command_009b1710,0xc);
  uVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x34))(auStack_1e + -0x12);
  *(undefined4 *)(in_ECX + 0xc) = uVar2;
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004e7f70(in_ECX - 4);
  }
  *(undefined4 *)(in_ECX + 0x34) = uVar2;
  (**(code **)(*DAT_00b5a79c + 4))(uVar2);
  return;
}


// ==== FUN_004d9210 @ 0x004d9210 ====

void FUN_004d9210(char param_1)

{
  int iVar1;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  if ((*(int *)(in_ECX + 0x24) != 0) &&
     ((*(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24)) / 0x1c != 0)) {
    if (param_1 == '\0') {
      if (*(int *)(in_ECX + 0x30) == *(int *)(in_ECX + 0x28)) {
        return;
      }
      *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + 0x1c;
    }
    else {
      if (*(int *)(in_ECX + 0x30) == *(int *)(in_ECX + 0x24)) {
        return;
      }
      *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + -0x1c;
    }
    iVar1 = *(int *)(in_ECX + 0x30);
    if (iVar1 == *(int *)(in_ECX + 0x28)) {
      FUN_00401830(&DAT_009b1737);
      if (*(int *)(in_ECX + 0x10) != 0) {
        (**(code **)(**(int **)(in_ECX + 0x10) + 0x30))();
        FUN_00551410(local_1c);
      }
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
    }
    else if (*(int *)(in_ECX + 0x10) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x10) + 0x30))();
      FUN_00551410(iVar1);
    }
  }
  return;
}


// ==== FUN_004d92d0 @ 0x004d92d0 ====

void FUN_004d92d0(void)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_Console_Already_Opened_009b1738,0x16);
  FUN_00796d20(local_1c);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004d9320 @ 0x004d9320 ====

void FUN_004d9320(void)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined4 uStack_38;
  void *pvStack_34;
  undefined4 uStack_30;
  undefined4 uStack_24;
  uint uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  if (*(int *)(in_ECX + 0x14) != 0) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0x2c))();
    pcVar2 = (char *)(**(code **)(*piVar1 + 0x10))();
    if (*pcVar2 != '\0') {
      piVar1 = (int *)(**(code **)(*DAT_00b5a72c + 0xc))();
      (**(code **)(**(int **)(in_ECX + 0x14) + 0x30))();
      iVar3 = (**(code **)(**(int **)(in_ECX + 0x14) + 0x14))();
      uStack_38 = *(undefined4 *)(iVar3 + 8);
      uStack_30 = *(undefined4 *)(iVar3 + 0x10);
      iVar3 = *(int *)(iVar3 + 0x14) - *(int *)(iVar3 + 0xc);
      if (*(char *)(in_ECX + 0x18) == '\0') {
        iVar4 = (**(code **)(*piVar1 + 4))();
      }
      else {
        iVar4 = (**(code **)(*piVar1 + 4))();
        if (*(int *)(in_ECX + 0x1c) <= iVar4) {
          iVar4 = *(int *)(in_ECX + 0x1c);
        }
      }
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      for (iVar3 = iVar4 - ((int)(iVar3 + (iVar3 >> 0x1f & 0xfU)) >> 4); iVar3 < iVar4;
          iVar3 = iVar3 + 1) {
        if (-1 < iVar3) {
          uVar5 = (**(code **)(*piVar1 + 8))(&uStack_38,iVar3);
          FUN_00401ff0(uVar5,0,0xffffffff);
          if (0xf < uStack_20) {
            _free(pvStack_34);
            return;
          }
          uStack_20 = 0xf;
          uStack_24 = 0;
          pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
        }
        FUN_004020e0(&DAT_009b1750,1);
      }
      FUN_005569f0(auStack_1c,0);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
    }
  }
  return;
}


// ==== FUN_004d9460 @ 0x004d9460 ====

undefined4 FUN_004d9460(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    FUN_004d9320(param_1);
  }
  else if (iVar1 == 0x50060001) {
    FUN_004d92d0(param_1);
    return 1;
  }
  return 0;
}


// ==== FUN_004d94a0 @ 0x004d94a0 ====

void FUN_004d94a0(void)

{
  undefined4 uVar1;
  undefined4 ****ppppuVar2;
  undefined4 *in_ECX;
  int iVar3;
  undefined4 *unaff_EBX;
  uint uVar4;
  uint uVar5;
  undefined4 ****ppppuVar6;
  undefined4 *puVar7;
  undefined4 *puStack_ac;
  undefined4 uStack_a8;
  undefined4 *puStack_a4;
  undefined4 uStack_a0;
  undefined4 ****appppuStack_9c [4];
  uint uStack_8c;
  uint uStack_88;
  undefined1 auStack_84 [4];
  undefined4 ****appppuStack_80 [4];
  uint uStack_70;
  uint uStack_6c;
  undefined4 *puStack_68;
  int *piStack_64;
  undefined4 *local_60;
  undefined4 uStack_5c;
  void *pvStack_58;
  undefined1 auStack_54 [4];
  undefined1 uStack_50;
  uint uStack_44;
  undefined4 uStack_40;
  void *pvStack_3c;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  
  local_60 = in_ECX;
  uStack_5c = (**(code **)(*DAT_00b5a72c + 0xc))();
  (**(code **)(*(int *)in_ECX[4] + 0x30))();
  uVar1 = FUN_00550150();
  pvStack_3c = (void *)0xf;
  uStack_40 = 0;
  uStack_50 = 0;
  FUN_00401660(uVar1,0,0xffffffff);
  uStack_a8 = 0;
  puStack_a4 = (undefined4 *)0x0;
  uStack_a0 = 0;
  (**(code **)(*DAT_00b5a7d8 + 0x10))(auStack_54,&puStack_ac);
  if (unaff_EBX != (undefined4 *)0x0) {
    iVar3 = (int)puStack_ac - (int)unaff_EBX >> 2;
    if (iVar3 == 0) {
      _free(unaff_EBX);
      return;
    }
    if (iVar3 == 1) {
      uVar1 = FUN_00402220(auStack_24,*unaff_EBX,&DAT_009b1730);
      FUN_00551410(uVar1);
      if (0xf < uStack_c) {
        _free(pvStack_20);
        return;
      }
    }
    else {
      local_60 = puStack_ac;
      uStack_88 = 0xf;
      uStack_8c = 0;
      appppuStack_9c[0] = (undefined4 ****)((uint)appppuStack_9c[0] & 0xffffff00);
      puStack_a4 = unaff_EBX;
      FUN_00401660(*unaff_EBX,0,0xffffffff);
      puVar7 = unaff_EBX;
      if (unaff_EBX != puStack_ac) {
        do {
          uStack_6c = 0xf;
          uStack_70 = 0;
          appppuStack_80[0] = (undefined4 ****)((uint)appppuStack_80[0] & 0xffffff00);
          FUN_00401660(*puVar7,0,0xffffffff);
          uVar4 = uStack_70;
          if (uStack_8c <= uStack_70) {
            uVar4 = uStack_8c;
          }
          uVar5 = 0;
          if (uVar4 != 0) {
            do {
              if (uStack_8c <= uVar5) {
                FUN_0079dba3();
              }
              ppppuVar6 = appppuStack_9c[0];
              if (uStack_88 < 0x10) {
                ppppuVar6 = appppuStack_9c;
              }
              if (uStack_70 <= uVar5) {
                FUN_0079dba3();
              }
              ppppuVar2 = appppuStack_80[0];
              if (uStack_6c < 0x10) {
                ppppuVar2 = appppuStack_80;
              }
            } while ((*(char *)((int)ppppuVar6 + uVar5) == *(char *)((int)ppppuVar2 + uVar5)) &&
                    (uVar5 = uVar5 + 1, uVar5 < uVar4));
            puVar7 = puStack_a4;
          }
          uStack_28 = 0xf;
          uStack_2c = 0;
          pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
          FUN_00401660(&uStack_a0,0,uVar5);
          FUN_00401660(&uStack_40,0,0xffffffff);
          if (0xf < uStack_28) {
            _free(pvStack_3c);
            return;
          }
          uStack_28 = 0xf;
          iVar3 = *piStack_64;
          uStack_2c = 0;
          pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
          uVar1 = FUN_004022a0(auStack_24,&DAT_009b1734,auStack_84);
          (**(code **)(iVar3 + 0xc))(uVar1);
          if (0xf < uStack_c) {
            _free(pvStack_20);
            return;
          }
          uStack_c = 0xf;
          uStack_10 = 0;
          pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
          if (0xf < uStack_6c) {
            _free(appppuStack_80[0]);
            return;
          }
          puStack_a4 = puVar7 + 1;
          uStack_6c = 0xf;
          uStack_70 = 0;
          appppuStack_80[0] = (undefined4 ****)((uint)appppuStack_80[0] & 0xffffff00);
          puVar7 = puStack_a4;
        } while (puStack_a4 != local_60);
        in_ECX = puStack_68;
      }
      if (in_ECX[4] != 0) {
        (**(code **)(*(int *)in_ECX[4] + 0x30))();
        FUN_00551410(&uStack_a0);
      }
      if (0xf < uStack_88) {
        _free(appppuStack_9c[0]);
        return;
      }
      uStack_88 = 0xf;
      uStack_8c = 0;
      appppuStack_9c[0] = (undefined4 ****)((uint)appppuStack_9c[0] & 0xffffff00);
    }
    if (unaff_EBX != (undefined4 *)0x0) {
      _free(unaff_EBX);
      return;
    }
  }
  puStack_ac = (undefined4 *)0x0;
  uStack_a8 = 0;
  if (uStack_44 < 0x10) {
    return;
  }
  _free(pvStack_58);
  return;
}


// ==== FUN_004d97d0 @ 0x004d97d0 ====

void FUN_004d97d0(void)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = &PTR_FUN_009b1764;
  *in_ECX = &PTR_FUN_009b17e0;
  in_ECX[1] = &PTR_FUN_009b17ac;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[3] = 0;
  in_ECX[5] = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  in_ECX[7] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  FUN_004d90a0();
  return;
}


// ==== FUN_004d9820 @ 0x004d9820 ====

void FUN_004d9820(void)

{
  undefined4 *in_ECX;
  undefined4 unaff_ESI;
  
  *in_ECX = &PTR_FUN_009b17e0;
  in_ECX[1] = &PTR_FUN_009b17ac;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[3]);
  (**(code **)(*DAT_00b5a79c + 0xc))(in_ECX[0xe]);
  if ((undefined4 *)in_ECX[0xe] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xe])(1);
  }
  in_ECX[0xe] = 0;
  if ((undefined4 *)in_ECX[0xd] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xd])(1);
  }
  in_ECX[0xd] = 0;
  if (in_ECX[9] == 0) {
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    in_ECX[0xb] = 0;
    in_ECX[1] = &PTR_FUN_009b1764;
    *in_ECX = &PTR_FUN_009b1758;
    return;
  }
  FUN_00405de0(in_ECX[9],in_ECX[10],in_ECX + 8,unaff_ESI);
  _free((void *)in_ECX[9]);
  return;
}


// ==== FUN_004d98c0 @ 0x004d98c0 ====

void FUN_004d98c0(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x24) != 0) {
    if ((*(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24)) / 0x1c != 0) {
      iVar2 = *(int *)(in_ECX + 0x28);
      if (*(uint *)(iVar2 + -4) < 0x10) {
        iVar1 = iVar2 + -0x18;
      }
      else {
        iVar1 = *(int *)(iVar2 + -0x18);
      }
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),iVar1,*(undefined4 *)(iVar2 + -8));
      if (iVar2 == 0) {
        *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(in_ECX + 0x28);
        return;
      }
    }
  }
  FUN_00406720(param_1);
  *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(in_ECX + 0x28);
  return;
}


// ==== FUN_004d9940 @ 0x004d9940 ====

undefined4 FUN_004d9940(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  undefined4 uStack_38;
  undefined1 uStack_34;
  uint uStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  if ((param_1 == 2) && (param_3 == 4)) {
    iVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_edit_command_009b1720,0xc);
    if (iVar1 == 0) {
      (**(code **)(**(int **)(in_ECX + 0xc) + 0x30))();
      uVar2 = FUN_00550150();
      uStack_20 = 0xf;
      uStack_24 = 0;
      uStack_34 = 0;
      FUN_00401660(uVar2,0,0xffffffff);
      FUN_00401830(&DAT_009b172d);
      FUN_00551410(auStack_1c);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return extraout_EAX;
      }
      (**(code **)(*DAT_00b5a72c + 4))(&uStack_38);
      FUN_004d98c0(auStack_1c + -0x20);
      if (uStack_24 < 0x10) {
        return 1;
      }
      _free(uStack_38);
      return extraout_EAX_00;
    }
  }
  return 0;
}


// ==== FUN_004d9a30 @ 0x004d9a30 ====

undefined4 FUN_004d9a30(void)

{
  return 0x90000000;
}


// ==== FUN_004d9a40 @ 0x004d9a40 ====

int FUN_004d9a40(uint param_1)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x14) <= param_1) {
    FUN_0079dba3();
  }
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    return in_ECX + 4 + param_1;
  }
  return *(int *)(in_ECX + 4) + param_1;
}


// ==== FUN_004d9a70 @ 0x004d9a70 ====

void FUN_004d9a70(void)

{
  FUN_004d9a80();
  return;
}


// ==== FUN_004d9a80 @ 0x004d9a80 ====

void FUN_004d9a80(byte param_1)

{
  void *in_ECX;
  
  FUN_004d9820();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d9aa0 @ 0x004d9aa0 ====

void FUN_004d9aa0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1834;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004d9ac0 @ 0x004d9ac0 ====

undefined4 FUN_004d9ac0(void)

{
  return 0xffffffff;
}


// ==== FUN_004d9ad0 @ 0x004d9ad0 ====

void FUN_004d9ad0(int param_1)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0xc) = param_1 * 60000;
  return;
}


// ==== FUN_004d9ae0 @ 0x004d9ae0 ====

int FUN_004d9ae0(void)

{
  int in_ECX;
  
  return in_ECX + 0x34;
}


// ==== FUN_004d9af0 @ 0x004d9af0 ====

void FUN_004d9af0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 9) = param_1;
  return;
}


// ==== FUN_004d9b00 @ 0x004d9b00 ====

undefined1 FUN_004d9b00(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 9);
}


// ==== FUN_004d9b10 @ 0x004d9b10 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004d9b10(void)

{
  int in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)*(int *)(in_ECX + 0x10);
  if (*(int *)(in_ECX + 0x10) < 0) {
    fVar1 = fVar1 + (float10)_DAT_0099d104;
  }
  return fVar1 * (float10)_DAT_009b1844 * (float10)DAT_009b1840;
}


// ==== FUN_004d9b30 @ 0x004d9b30 ====

void FUN_004d9b30(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_004d9b60 @ 0x004d9b60 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004d9b60(int param_1)

{
  float fVar1;
  float fVar2;
  int in_ECX;
  float fVar3;
  
  fVar3 = *(float *)(param_1 + 0x14) - *(float *)(in_ECX + 0x48);
  fVar2 = *(float *)(param_1 + 0x18) - *(float *)(in_ECX + 0x4c);
  fVar1 = *(float *)(param_1 + 0x1c) - *(float *)(in_ECX + 0x50);
  if (((SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1) <= _DAT_009b18d4) &&
      (fVar3 = *(float *)(param_1 + 0x20) - *(float *)(in_ECX + 0x54),
      fVar2 = *(float *)(param_1 + 0x24) - *(float *)(in_ECX + 0x58),
      fVar1 = *(float *)(param_1 + 0x28) - *(float *)(in_ECX + 0x5c),
      SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1) <= DAT_0099d0ec)) &&
     (fVar3 = *(float *)(param_1 + 0x44) - *(float *)(in_ECX + 0x78),
     fVar2 = *(float *)(param_1 + 0x48) - *(float *)(in_ECX + 0x7c),
     fVar1 = *(float *)(param_1 + 0x4c) - *(float *)(in_ECX + 0x80),
     SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1) <= DAT_0099d0ec)) {
    fVar3 = *(float *)(in_ECX + 0x84) - *(float *)(param_1 + 0x50);
    if (fVar3 <= 0.0) {
      fVar3 = 0.0 - fVar3;
    }
    if (fVar3 <= DAT_0099d0ec) {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_004d9cb0 @ 0x004d9cb0 ====

void FUN_004d9cb0(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined4 *puVar6;
  
  uVar1 = *param_1;
  puVar6 = operator_new(0xc);
  if (puVar6 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  uVar2 = param_1[3];
  uVar3 = param_1[4];
  uVar4 = param_1[2];
  uVar5 = param_1[1];
  *(undefined1 *)(puVar6 + 1) = uVar1;
  *(undefined1 *)((int)puVar6 + 6) = uVar2;
  *(undefined1 *)((int)puVar6 + 5) = uVar4;
  *puVar6 = &PTR_FUN_009b18c4;
  *(undefined1 *)((int)puVar6 + 7) = uVar5;
  *(undefined1 *)(puVar6 + 2) = uVar3;
  FUN_00797a20(puVar6);
  return;
}


// ==== FUN_004d9d30 @ 0x004d9d30 ====

uint FUN_004d9d30(int *param_1)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if ((uVar1 == 0x40001) && (*(char *)((int)in_ECX + 9) != '\0')) {
    uVar1 = (**(code **)(*in_ECX + 0x2c))(param_1[3]);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_004d9d90 @ 0x004d9d90 ====

void FUN_004d9d90(int param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  if ((*(short *)(param_1 + 2) == 0) || (*(short *)(param_1 + 4) == 0)) {
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = &PTR_FUN_009b1874;
      puVar5[1] = 0xe;
      FUN_00797a20(puVar5);
      return;
    }
    FUN_00797a20(0);
  }
  else if (DAT_00b5ac1c != (int *)0x0) {
    iVar3 = (**(code **)(*DAT_00b5ac1c + 0x14))();
    if (iVar3 != 0) {
      uVar4 = *(undefined4 *)(iVar3 + 0xac);
      uVar1 = *(undefined2 *)(param_1 + 4);
      uVar2 = *(ushort *)(param_1 + 2);
      iVar3 = (**(code **)(*DAT_00b5a6a8 + 4))();
      if (iVar3 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = FUN_004db040(uVar2 | 0xa0000,uVar4,0xe);
      }
      FUN_00797a20(uVar4);
      iVar3 = (**(code **)(*DAT_00b5a6a8 + 4))();
      if (iVar3 == 0) {
        FUN_00797a20(0);
        return;
      }
      uVar4 = FUN_004db090(0xe,uVar1,*(undefined4 *)(param_1 + 8),0,0);
      FUN_00797a20(uVar4);
      return;
    }
  }
  return;
}


// ==== FUN_004d9e80 @ 0x004d9e80 ====

void FUN_004d9e80(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 local_14;
  
  fVar4 = *(float *)(param_1 + 4) * DAT_009a09bc;
  fVar5 = *(float *)(param_1 + 8) * DAT_009a09bc;
  fVar3 = *(float *)(param_1 + 0xc) * DAT_009a09b8;
  local_14 = CONCAT31(local_14._1_3_,*param_1);
  uVar1 = *(undefined4 *)(param_1 + 0x10);
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009b189c;
  }
  puVar2[1] = local_14;
  puVar2[2] = fVar4;
  puVar2[3] = fVar5;
  puVar2[4] = fVar3;
  puVar2[5] = uVar1;
  FUN_00797a20(puVar2);
  return;
}


// ==== FUN_004d9f20 @ 0x004d9f20 ====

void FUN_004d9f20(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  uVar5 = DAT_0099d080;
  if (puVar6 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  uVar1 = param_1[1];
  uVar2 = *param_1;
  uVar3 = param_1[3];
  uVar4 = param_1[4];
  puVar6[4] = param_1[2];
  puVar6[5] = uVar3;
  puVar6[6] = uVar4;
  *puVar6 = &PTR_FUN_009b184c;
  puVar6[1] = uVar5;
  puVar6[2] = uVar2;
  puVar6[3] = uVar1;
  FUN_00797a20(puVar6);
  return;
}


// ==== FUN_004d9f90 @ 0x004d9f90 ====

int FUN_004d9f90(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x24) == 0) {
    return 0;
  }
  return **(int **)(in_ECX + 0x20) + 0x14;
}


// ==== FUN_004d9fb0 @ 0x004d9fb0 ====

void FUN_004d9fb0(undefined4 *param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  
  (**(code **)(*DAT_00b5ac5c + 0x1c))(param_1 + 5);
  (**(code **)(*DAT_00b5ac5c + 0x20))(param_1 + 8);
  (**(code **)(*DAT_00b5ac5c + 0x28))(param_1 + 0x11);
  (**(code **)(*DAT_00b5ac5c + 0x18))(param_1[0x14]);
  FUN_004d9f20(param_1);
  FUN_004d9e80(param_1 + 0x18);
  uVar1 = *(undefined1 *)(param_1 + 0x20);
  puVar3 = operator_new(0xc);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    bVar2 = *(byte *)(param_1 + 0x1d);
    *puVar3 = &PTR_FUN_009b18b0;
    *(undefined1 *)(puVar3 + 1) = uVar1;
    puVar3[2] = (uint)bVar2;
  }
  FUN_00797a20(puVar3);
  FUN_004d9cb0((int)param_1 + 0x75);
  (**(code **)(*DAT_00b5ac5c + 0x30))(*(undefined1 *)(param_1 + 0x20));
  if (*(char *)(param_1 + 0x15) != '\0') {
    FUN_004d9d90(param_1 + 0x15);
    puVar3 = (undefined4 *)(in_ECX + 0x34);
    for (iVar4 = 0x21; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar3 = *param_1;
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 1;
    }
    return;
  }
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar3 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    puVar3 = (undefined4 *)(in_ECX + 0x34);
    for (iVar4 = 0x21; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar3 = *param_1;
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 1;
    }
    return;
  }
  *puVar3 = &PTR_FUN_009b1874;
  puVar3[1] = 0xe;
  FUN_00797a20(puVar3);
  puVar3 = (undefined4 *)(in_ECX + 0x34);
  for (iVar4 = 0x21; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar3 = *param_1;
    param_1 = param_1 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ==== FUN_004da0d0 @ 0x004da0d0 ====

int FUN_004da0d0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int in_ECX;
  uint local_8;
  uint local_4;
  
  uVar1 = param_1;
  local_8 = param_1;
  local_4 = param_1;
  uVar2 = FUN_004db160(&local_8);
  if ((uVar2 == *(uint *)(in_ECX + 0x20)) ||
     ((uVar1 < *(uint *)(uVar2 + 0xc) && (uVar1 <= *(uint *)(uVar2 + 0x10))))) {
    local_8 = *(uint *)(in_ECX + 0x20);
    puVar3 = &local_8;
  }
  else {
    puVar3 = &param_1;
  }
  param_1 = *puVar3;
  uVar1 = *(uint *)(in_ECX + 0x20);
  if (param_1 != uVar1) {
    FUN_004daf90();
    if (param_1 != uVar1) {
      return param_1 + 0x14;
    }
  }
  return 0;
}


// ==== FUN_004da150 @ 0x004da150 ====

uint FUN_004da150(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int in_ECX;
  uint local_8;
  uint local_4;
  
  uVar1 = param_1;
  local_8 = param_1;
  local_4 = param_1;
  uVar2 = FUN_004db160(&local_8);
  if ((uVar2 == *(uint *)(in_ECX + 0x20)) ||
     ((uVar1 < *(uint *)(uVar2 + 0xc) && (uVar1 <= *(uint *)(uVar2 + 0x10))))) {
    local_8 = *(uint *)(in_ECX + 0x20);
    puVar3 = &local_8;
  }
  else {
    puVar3 = &param_1;
  }
  uVar2 = *puVar3;
  if (uVar2 == *(uint *)(in_ECX + 0x20)) {
    return 0;
  }
  return uVar2 + 0x14 & (*(uint *)(uVar2 + 0x90) != uVar1) - 1;
}


// ==== FUN_004da1d0 @ 0x004da1d0 ====

void FUN_004da1d0(void)

{
  int in_ECX;
  
  FUN_004db1e0(*(undefined4 *)(*(int *)(in_ECX + 0x20) + 4));
  *(int *)(*(int *)(in_ECX + 0x20) + 4) = *(int *)(in_ECX + 0x20);
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(in_ECX + 0x20);
  *(int *)(*(int *)(in_ECX + 0x20) + 8) = *(int *)(in_ECX + 0x20);
  return;
}


// ==== FUN_004da200 @ 0x004da200 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004da200(void)

{
  float fVar1;
  float fVar2;
  uint *puVar3;
  float fVar4;
  float *pfVar5;
  int *in_ECX;
  int iVar6;
  float *pfVar7;
  uint *puVar8;
  float10 fVar9;
  uint *local_90;
  float local_8c;
  float local_88;
  float local_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  undefined1 uStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  undefined1 uStack_10;
  undefined4 uStack_f;
  undefined1 uStack_b;
  int local_8;
  undefined1 uStack_4;
  
  if (in_ECX[9] != 0) {
    local_90 = (uint *)in_ECX[3];
    puVar8 = (uint *)0x0;
    fVar4 = (float)FUN_00802534();
    in_ECX[4] = (int)fVar4;
    local_8c = fVar4;
    local_88 = fVar4;
    FUN_004db360(&local_90,&local_8c);
    if (local_90 == (uint *)in_ECX[8]) {
      local_90 = (uint *)in_ECX[8];
      FUN_004daf20();
      pfVar7 = (float *)(local_90 + 5);
      puVar8 = (uint *)(*(int *)in_ECX[8] + 0x14);
    }
    else {
      pfVar7 = (float *)(local_90 + 5);
      if ((float)local_90[0x24] != fVar4) {
        FUN_004daf90();
        puVar8 = local_90;
        if (local_90 == (uint *)in_ECX[8]) {
          puVar8 = *(uint **)in_ECX[8];
        }
        puVar8 = puVar8 + 5;
      }
    }
    if (pfVar7 != (float *)0x0) {
      fVar1 = pfVar7[0x1f];
      if ((fVar1 != fVar4) && (puVar8 != (uint *)0x0)) {
        in_ECX[5] = (int)fVar1;
        fVar2 = (float)puVar8[0x1f];
        in_ECX[6] = (int)fVar2;
        if ((uint)fVar2 < (uint)fVar1) {
          in_ECX[6] = (int)fVar2 + 240000;
        }
        if ((uint)fVar4 < (uint)fVar1) {
          in_ECX[4] = (int)fVar4 + 240000;
        }
        if ((float)in_ECX[6] == fVar1) {
          local_90 = (uint *)0x0;
        }
        else {
          fVar4 = (float)(in_ECX[4] - (int)fVar1);
          if (in_ECX[4] - (int)fVar1 < 0) {
            fVar4 = fVar4 + _DAT_0099d104;
          }
          iVar6 = in_ECX[6] - (int)fVar1;
          fVar1 = (float)iVar6;
          if (iVar6 < 0) {
            fVar1 = fVar1 + _DAT_0099d104;
          }
          local_90 = (uint *)(fVar4 / fVar1);
        }
        FUN_004b6dd0();
        puVar3 = local_90;
        local_8 = in_ECX[4];
        local_70 = ((float)puVar8[5] - pfVar7[5]) * (float)local_90 + pfVar7[5];
        local_6c = ((float)puVar8[6] - pfVar7[6]) * (float)local_90 + pfVar7[6];
        local_68 = ((float)puVar8[7] - pfVar7[7]) * (float)local_90 + pfVar7[7];
        local_64 = ((float)puVar8[8] - pfVar7[8]) * (float)local_90 + pfVar7[8];
        local_60 = ((float)puVar8[9] - pfVar7[9]) * (float)local_90 + pfVar7[9];
        local_5c = ((float)puVar8[10] - pfVar7[10]) * (float)local_90 + pfVar7[10];
        local_40 = ((float)puVar8[0x11] - pfVar7[0x11]) * (float)local_90 + pfVar7[0x11];
        local_3c = ((float)puVar8[0x12] - pfVar7[0x12]) * (float)local_90 + pfVar7[0x12];
        local_38 = ((float)puVar8[0x13] - pfVar7[0x13]) * (float)local_90 + pfVar7[0x13];
        fVar9 = (float10)FUN_0040d140(pfVar7[0x14],puVar8[0x14],local_90);
        local_34 = (float)fVar9;
        pfVar5 = (float *)(**(code **)(*in_ECX + 0x30))();
        fStack_7c = (pfVar7[2] - pfVar5[2]) * (float)local_90 + pfVar5[2];
        fStack_78 = (pfVar7[3] - pfVar5[3]) * (float)local_90 + pfVar5[3];
        fStack_74 = (pfVar7[4] - pfVar5[4]) * (float)local_90 + pfVar5[4];
        local_84 = (*pfVar7 - *pfVar5) * (float)local_90 + *pfVar5;
        fStack_80 = (pfVar7[1] - pfVar5[1]) * (float)local_90 + pfVar5[1];
        uStack_24 = *(undefined1 *)(pfVar7 + 0x18);
        fVar9 = (float10)FUN_0040d140(pfVar7[0x19],puVar8[0x19],puVar3);
        fStack_20 = (float)fVar9;
        fVar9 = (float10)FUN_0040d140(pfVar7[0x1a],puVar8[0x1a],puVar3);
        fStack_1c = (float)fVar9;
        fVar9 = (float10)FUN_0040d140(pfVar7[0x1b],puVar8[0x1b],puVar3);
        fStack_18 = (float)fVar9;
        uStack_4 = *(undefined1 *)(pfVar7 + 0x20);
        fStack_30 = pfVar7[0x15];
        fStack_2c = pfVar7[0x16];
        fStack_28 = pfVar7[0x17];
        uStack_10 = *(undefined1 *)(pfVar7 + 0x1d);
        uStack_f = *(undefined4 *)((int)pfVar7 + 0x75);
        uStack_b = *(undefined1 *)((int)pfVar7 + 0x79);
        (**(code **)(*in_ECX + 0x38))(&local_84);
        return;
      }
      (**(code **)(*in_ECX + 0x38))(pfVar7);
    }
  }
  return;
}


// ==== FUN_004da5b0 @ 0x004da5b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004da5b0(float *param_1)

{
  undefined1 uVar1;
  byte bVar2;
  float fVar3;
  float *pfVar4;
  undefined4 *puVar5;
  int *piVar6;
  int in_ECX;
  int iVar7;
  float *pfVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined1 auStack_38 [4];
  undefined1 uStack_34;
  uint uStack_28;
  undefined4 uStack_24;
  void *pvStack_20;
  undefined1 auStack_1c [16];
  uint uStack_c;
  
  fVar3 = (float)FUN_004d9b60(param_1);
  if (SUB41(fVar3,0) != '\0') {
    (**(code **)(*DAT_00b5ac5c + 0x1c))(param_1 + 5);
    (**(code **)(*DAT_00b5ac5c + 0x20))(param_1 + 8);
    (**(code **)(*DAT_00b5ac5c + 0x28))(param_1 + 0x11);
    fVar3 = (float)(**(code **)(*DAT_00b5ac5c + 0x18))(param_1[0x14]);
    pfVar4 = param_1 + 5;
    pfVar8 = (float *)(in_ECX + 0x48);
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *pfVar8 = *pfVar4;
      pfVar4 = pfVar4 + 1;
      pfVar8 = pfVar8 + 1;
    }
  }
  fVar11 = param_1[2] - *(float *)(in_ECX + 0x3c);
  fVar10 = param_1[3] - *(float *)(in_ECX + 0x40);
  fVar9 = param_1[4] - *(float *)(in_ECX + 0x44);
  if ((DAT_0099d0ec < SQRT(fVar11 * fVar11 + fVar10 * fVar10 + fVar9 * fVar9)) ||
     (fVar10 = *param_1 - *(float *)(in_ECX + 0x34), fVar9 = param_1[1] - *(float *)(in_ECX + 0x38),
     DAT_0099d0ec < SQRT(fVar10 * fVar10 + fVar9 * fVar9))) {
    FUN_004d9f20(param_1);
    *(float *)(in_ECX + 0x34) = *param_1;
    *(float *)(in_ECX + 0x38) = param_1[1];
    *(float *)(in_ECX + 0x3c) = param_1[2];
    fVar3 = param_1[3];
    *(float *)(in_ECX + 0x40) = fVar3;
    *(float *)(in_ECX + 0x44) = param_1[4];
  }
  fVar9 = *(float *)(in_ECX + 0x9c) - param_1[0x1a];
  if (fVar9 <= 0.0) {
    fVar9 = 0.0 - fVar9;
  }
  if (fVar9 <= DAT_0099d0ec) {
    fVar9 = *(float *)(in_ECX + 0x98) - param_1[0x19];
    if (fVar9 <= 0.0) {
      fVar9 = 0.0 - fVar9;
    }
    if (fVar9 <= DAT_0099d0ec) {
      fVar9 = *(float *)(in_ECX + 0xa0) - param_1[0x1b];
      if (fVar9 <= 0.0) {
        fVar9 = 0.0 - fVar9;
      }
      if ((fVar9 <= DAT_0099d0ec) &&
         (fVar3 = (float)CONCAT31((int3)((uint)fVar3 >> 8),*(char *)(in_ECX + 0x94)),
         *(char *)(in_ECX + 0x94) == *(char *)(param_1 + 0x18))) goto LAB_004da774;
    }
  }
  FUN_004d9e80(param_1 + 0x18);
  *(float *)(in_ECX + 0x94) = param_1[0x18];
  *(float *)(in_ECX + 0x98) = param_1[0x19];
  *(float *)(in_ECX + 0x9c) = param_1[0x1a];
  fVar3 = param_1[0x1b];
  *(float *)(in_ECX + 0xa0) = fVar3;
  *(float *)(in_ECX + 0xa4) = param_1[0x1c];
LAB_004da774:
  if ((((*(short *)(in_ECX + 0x8a) != *(short *)((int)param_1 + 0x56)) ||
       (*(short *)(in_ECX + 0x8c) != *(short *)(param_1 + 0x16))) ||
      (*(float *)(in_ECX + 0x90) != param_1[0x17])) ||
     (pfVar4 = (float *)CONCAT31((int3)(CONCAT22((short)((uint)fVar3 >> 0x10),
                                                 *(short *)(in_ECX + 0x8a)) >> 8),
                                 *(char *)(in_ECX + 0x88)),
     *(char *)(in_ECX + 0x88) != *(char *)(param_1 + 0x15))) {
    if (*(char *)(param_1 + 0x15) == '\0') {
      puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar5 == (undefined4 *)0x0) {
        FUN_00797a20(0);
      }
      else {
        *puVar5 = &PTR_FUN_009b1874;
        puVar5[1] = 0xe;
        FUN_00797a20(puVar5);
      }
    }
    else {
      FUN_004d9d90(param_1 + 0x15);
    }
    pfVar4 = (float *)(in_ECX + 0x88);
    *pfVar4 = param_1[0x15];
    *(float *)(in_ECX + 0x8c) = param_1[0x16];
    *(float *)(in_ECX + 0x90) = param_1[0x17];
  }
  if ((*(char *)(in_ECX + 0xa8) != *(char *)(param_1 + 0x1d)) ||
     (pfVar4 = (float *)CONCAT31((int3)((uint)pfVar4 >> 8),*(char *)(in_ECX + 0xb4)),
     *(char *)(in_ECX + 0xb4) != *(char *)(param_1 + 0x20))) {
    (**(code **)(*DAT_00b5ac5c + 0x30))
              (CONCAT31((int3)((uint)pfVar4 >> 8),*(undefined1 *)(param_1 + 0x20)));
    *(undefined1 *)(in_ECX + 0xb4) = *(undefined1 *)(param_1 + 0x20);
    uVar1 = *(undefined1 *)(param_1 + 0x20);
    puVar5 = operator_new(0xc);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      bVar2 = *(byte *)(param_1 + 0x1d);
      *puVar5 = &PTR_FUN_009b18b0;
      *(undefined1 *)(puVar5 + 1) = uVar1;
      puVar5[2] = (uint)bVar2;
    }
    FUN_00797a20(puVar5);
    *(undefined1 *)(in_ECX + 0xa8) = *(undefined1 *)(param_1 + 0x1d);
  }
  if (((*(char *)(in_ECX + 0xa9) != *(char *)((int)param_1 + 0x75)) ||
      (*(char *)(in_ECX + 0xab) != *(char *)((int)param_1 + 0x77))) ||
     ((*(char *)(in_ECX + 0xac) != *(char *)(param_1 + 0x1e) ||
      (((*(char *)(in_ECX + 0xaa) != *(char *)((int)param_1 + 0x76) ||
        (*(char *)(in_ECX + 0xad) != *(char *)((int)param_1 + 0x79))) ||
       (*(char *)(in_ECX + 0xa9) != '\x01')))))) {
    FUN_004d9cb0((undefined4 *)((int)param_1 + 0x75));
    *(undefined4 *)(in_ECX + 0xa9) = *(undefined4 *)((int)param_1 + 0x75);
    *(undefined1 *)(in_ECX + 0xad) = *(undefined1 *)((int)param_1 + 0x79);
  }
  *(float *)(in_ECX + 0xb0) = param_1[0x1f];
  iVar7 = (**(code **)(*DAT_00b5ac24 + 8))();
  if (*(char *)(iVar7 + 1) != '\0') {
    fVar3 = (float)*(int *)(in_ECX + 0x10);
    if (*(int *)(in_ECX + 0x10) < 0) {
      fVar3 = fVar3 + _DAT_0099d104;
    }
    fVar3 = _DAT_009b1844 * fVar3 * DAT_009b1840;
    FUN_00401740(s__d_h___d_m_009b17ec,0xb);
    FUN_00404230(auStack_1c);
    pvStack_20 = (void *)0xf;
    uStack_24 = 0;
    uStack_34 = 0;
    FUN_00401740(s___Curent_Time___009b17f8,0xf);
    piVar6 = (int *)(**(code **)(*DAT_00b5a688 + 0x18))();
    (**(code **)(*piVar6 + 4))(auStack_38,auStack_1c);
    if (0xf < uStack_28) {
      _free((void *)(int)ROUND(fVar3));
      return;
    }
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return;
    }
  }
  return;
}


// ==== FUN_004daa00 @ 0x004daa00 ====

void FUN_004daa00(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009b1954;
  in_ECX[1] = &PTR_FUN_009b1948;
  FUN_004db7a0(local_4,*(undefined4 *)in_ECX[8],(undefined4 *)in_ECX[8]);
  _free((void *)in_ECX[8]);
  return;
}


// ==== FUN_004daa60 @ 0x004daa60 ====

void FUN_004daa60(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint local_a0;
  int iStack_9c;
  undefined4 auStack_90 [35];
  
  iVar2 = FUN_004db400(param_1);
  if (iVar2 == 0) {
    return;
  }
  if ((*(int *)(iVar2 + 0x40) == 0) ||
     ((*(int *)(iVar2 + 0x44) - *(int *)(iVar2 + 0x40)) / 0x84 == 0)) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar2);
    return;
  }
  (**(code **)(*in_ECX + 0x28))();
  local_a0 = 0;
  iStack_9c = 0;
  while( true ) {
    if ((*(int *)(iVar2 + 0x40) == 0) ||
       ((uint)((*(int *)(iVar2 + 0x44) - *(int *)(iVar2 + 0x40)) / 0x84) <= local_a0)) {
      if ((*(int *)(iVar2 + 0x40) == 0) ||
         ((uint)((*(int *)(iVar2 + 0x44) - *(int *)(iVar2 + 0x40)) / 0x84) < 2)) {
        (**(code **)(*in_ECX + 0x3c))(0);
      }
      else {
        (**(code **)(*in_ECX + 0x3c))(1);
      }
      if (in_ECX[9] != 0) {
        FUN_004d9fb0(*(int *)in_ECX[8] + 0x14);
      }
      iVar2 = (**(code **)(*in_ECX + 4))();
      *(undefined4 *)(iVar2 + 0x28) = 0;
      (**(code **)(*DAT_00b5a7cc + 0x2c))(in_ECX);
      return;
    }
    iVar1 = *(int *)(iVar2 + 0x40);
    if ((iVar1 == 0) || ((uint)((*(int *)(iVar2 + 0x44) - iVar1) / 0x84) <= local_a0)) break;
    puVar4 = (undefined4 *)(iVar1 + iStack_9c);
    puVar5 = auStack_90;
    for (iVar3 = 0x21; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    (**(code **)(*in_ECX + 0x20))(auStack_90);
    local_a0 = local_a0 + 1;
    iStack_9c = iStack_9c + 0x84;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0085b340();
}


// ==== FUN_004dabe0 @ 0x004dabe0 ====

undefined4 FUN_004dabe0(uint *param_1)

{
  uint uVar1;
  uint in_ECX;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint local_13c;
  uint local_138;
  uint local_134;
  int local_130;
  undefined4 local_12c;
  uint local_128 [37];
  uint uStack_94;
  uint uStack_90;
  uint auStack_8c [34];
  
  uVar1 = param_1[0x1f];
  if (239999 < uVar1) {
    return 0;
  }
  if (*(int *)(in_ECX + 0x24) == 0) {
    local_128[1] = 240000;
    puVar4 = local_128 + 2;
    for (iVar2 = 0x21; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *param_1;
      param_1 = param_1 + 1;
      puVar4 = puVar4 + 1;
    }
    local_128[0] = uVar1;
    FUN_004dbb80(&local_13c,local_128);
    return 1;
  }
  local_13c = uVar1;
  local_138 = uVar1;
  local_134 = in_ECX;
  FUN_004db360(&local_130,&local_13c);
  if (local_130 == *(int *)(local_134 + 0x20)) {
    puVar4 = local_128 + 2;
    puVar3 = local_128;
    local_128[0] = uVar1;
    local_128[1] = uVar1;
  }
  else {
    if (*(uint *)(local_130 + 0x90) == uVar1) {
      puVar4 = (uint *)(local_130 + 0x14);
      for (iVar2 = 0x21; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *param_1;
        param_1 = param_1 + 1;
        puVar4 = puVar4 + 1;
      }
      return 1;
    }
    local_13c = *(uint *)(local_130 + 0xc);
    local_12c = *(undefined4 *)(local_130 + 0x10);
    puVar4 = (uint *)(local_130 + 0x14);
    puVar3 = local_128;
    for (iVar2 = 0x21; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_004db460(&local_134,local_130);
    uStack_94 = local_13c;
    uStack_90 = uVar1;
    puVar4 = local_128;
    puVar3 = auStack_8c;
    for (iVar2 = 0x21; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_004dbb80(&local_13c,&uStack_94);
    uStack_90 = local_12c;
    puVar4 = auStack_8c;
    puVar3 = &uStack_94;
    uStack_94 = uVar1;
  }
  for (iVar2 = 0x21; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *param_1;
    param_1 = param_1 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_004dbb80(&local_13c,puVar3);
  return 1;
}


// ==== FUN_004dad60 @ 0x004dad60 ====

undefined4 FUN_004dad60(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  int in_ECX;
  uint local_c;
  uint local_8;
  uint local_4;
  
  uVar1 = param_1;
  local_8 = param_1;
  local_4 = param_1;
  param_1 = FUN_004db160(&local_8);
  if ((param_1 == *(uint *)(in_ECX + 0x20)) ||
     ((uVar1 < *(uint *)(param_1 + 0xc) && (uVar1 <= *(uint *)(param_1 + 0x10))))) {
    local_c = *(uint *)(in_ECX + 0x20);
    puVar2 = &local_c;
  }
  else {
    puVar2 = &param_1;
  }
  if (*puVar2 == *(uint *)(in_ECX + 0x20)) {
    return 0;
  }
  FUN_004dbc40(&local_8);
  return 1;
}


// ==== FUN_004dadd0 @ 0x004dadd0 ====

void FUN_004dadd0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1834;
  FUN_004dba30();
  in_ECX[1] = &PTR_FUN_009b1948;
  *in_ECX = &PTR_FUN_009b1954;
  iVar1 = FUN_004db2b0();
  in_ECX[8] = iVar1;
  *(undefined1 *)(iVar1 + 0x99) = 1;
  *(undefined4 *)(in_ECX[8] + 4) = in_ECX[8];
  *(undefined4 *)in_ECX[8] = in_ECX[8];
  *(undefined4 *)(in_ECX[8] + 8) = in_ECX[8];
  in_ECX[9] = 0;
  *(undefined1 *)((int)in_ECX + 9) = 1;
  in_ECX[3] = 240000;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_004b6dd0();
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar2 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar2 = &PTR_FUN_009b1874;
  puVar2[1] = 0xe;
  FUN_00797a20(puVar2);
  return;
}


// ==== FUN_004dae80 @ 0x004dae80 ====

void FUN_004dae80(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  cVar1 = *(char *)(iVar2 + 0x99);
  while (cVar1 == '\0') {
    iVar2 = *(int *)(iVar2 + 8);
    cVar1 = *(char *)(iVar2 + 0x99);
  }
  return;
}


// ==== FUN_004daea0 @ 0x004daea0 ====

void FUN_004daea0(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x99);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x99);
  }
  return;
}


// ==== FUN_004daec0 @ 0x004daec0 ====

void FUN_004daec0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x99) == '\0') {
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


// ==== FUN_004daf20 @ 0x004daf20 ====

void FUN_004daf20(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x99) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x99) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x99);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x99);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x99) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x99) == '\0');
    if (*(char *)((int)piVar4 + 0x99) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_004daf90 @ 0x004daf90 ====

void FUN_004daf90(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x99) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x99) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x99);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x99);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x99);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x99);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_004daff0 @ 0x004daff0 ====

void FUN_004daff0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  *in_ECX = param_1;
  in_ECX[2] = param_3;
  in_ECX[1] = param_2;
  puVar2 = in_ECX + 3;
  for (iVar1 = 0x23; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_4;
    param_4 = param_4 + 1;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)(in_ECX + 0x26) = param_5;
  *(undefined1 *)((int)in_ECX + 0x99) = 0;
  return;
}


// ==== FUN_004db030 @ 0x004db030 ====

undefined4 FUN_004db030(void)

{
  return 0x10040019;
}


// ==== FUN_004db040 @ 0x004db040 ====

void FUN_004db040(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b1860;
  in_ECX[2] = param_2;
  in_ECX[3] = param_3;
  *(undefined1 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_004db070 @ 0x004db070 ====

undefined4 FUN_004db070(void)

{
  return 0x60010000;
}


// ==== FUN_004db080 @ 0x004db080 ====

undefined4 FUN_004db080(void)

{
  return 0x60010001;
}


// ==== FUN_004db090 @ 0x004db090 ====

void FUN_004db090(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  in_ECX[2] = param_2;
  in_ECX[3] = param_3;
  *in_ECX = &PTR_FUN_009b1888;
  in_ECX[4] = param_4;
  in_ECX[5] = param_5;
  return;
}


// ==== FUN_004db0c0 @ 0x004db0c0 ====

undefined4 FUN_004db0c0(void)

{
  return 0x60010003;
}


// ==== FUN_004db0d0 @ 0x004db0d0 ====

undefined4 FUN_004db0d0(void)

{
  return 0x60040005;
}


// ==== FUN_004db0e0 @ 0x004db0e0 ====

undefined4 FUN_004db0e0(void)

{
  return 0x60040020;
}


// ==== FUN_004db0f0 @ 0x004db0f0 ====

undefined4 FUN_004db0f0(void)

{
  return 0x60040021;
}


// ==== FUN_004db100 @ 0x004db100 ====

void FUN_004db100(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x99) == '\0') {
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


// ==== FUN_004db160 @ 0x004db160 ====

undefined4 * FUN_004db160(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar2[1] + 0x99) == '\0') {
    puVar1 = puVar2;
    puVar3 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar3;
      if (((uint)puVar2[3] < *param_1) && ((uint)puVar2[4] <= param_1[1])) {
        puVar3 = (undefined4 *)puVar2[2];
        puVar2 = puVar1;
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar3 + 0x99) == '\0');
  }
  return puVar2;
}


// ==== FUN_004db1a0 @ 0x004db1a0 ====

undefined4 * FUN_004db1a0(uint *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar1[1] + 0x99) == '\0') {
    puVar2 = (undefined4 *)puVar1[1];
    do {
      if ((*param_1 < (uint)puVar2[3]) && (param_1[1] <= (uint)puVar2[4])) {
        puVar3 = (undefined4 *)*puVar2;
        puVar1 = puVar2;
      }
      else {
        puVar3 = (undefined4 *)puVar2[2];
      }
      puVar2 = puVar3;
    } while (*(char *)((int)puVar3 + 0x99) == '\0');
  }
  return puVar1;
}


// ==== FUN_004db1e0 @ 0x004db1e0 ====

void FUN_004db1e0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x99) == '\0') {
    FUN_004db1e0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004db220 @ 0x004db220 ====

void * FUN_004db220(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009812e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x9c);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_004daff0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@004db298 @ 0x004db298 ====

void Catch_004db298(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004db2b0 @ 0x004db2b0 ====

void FUN_004db2b0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009812f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x9c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x26) = 1;
  *(undefined1 *)((int)puVar1 + 0x99) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@004db343 @ 0x004db343 ====

void Catch_004db343(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_004db360 @ 0x004db360 ====

void FUN_004db360(int *param_1,uint *param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_004db160(param_2);
  if ((iVar1 == *(int *)(in_ECX + 4)) ||
     ((*param_2 < *(uint *)(iVar1 + 0xc) && (param_2[1] <= *(uint *)(iVar1 + 0x10))))) {
    *param_1 = *(int *)(in_ECX + 4);
    return;
  }
  *param_1 = iVar1;
  return;
}


// ==== FUN_004db3c0 @ 0x004db3c0 ====

void FUN_004db3c0(int param_1,int param_2,int *param_3)

{
  while (param_1 != param_2) {
    *param_3 = *param_3 + 1;
    FUN_004daf90();
  }
  return;
}


// ==== FUN_004db400 @ 0x004db400 ====

undefined4 FUN_004db400(undefined4 param_1)

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
  local_4 = 6;
  uVar2 = (**(code **)(*piVar1 + 8))(&local_20);
  if (local_c < 0x10) {
    return uVar2;
  }
  _free(local_20);
  return extraout_EAX;
}


// ==== FUN_004db460 @ 0x004db460 ====

/* WARNING: Removing unreachable block (ram,0x004db592) */
/* WARNING: Removing unreachable block (ram,0x004db5a2) */
/* WARNING: Removing unreachable block (ram,0x004db5ae) */
/* WARNING: Removing unreachable block (ram,0x004db5b1) */
/* WARNING: Removing unreachable block (ram,0x004db59e) */
/* WARNING: Removing unreachable block (ram,0x004db5bf) */
/* WARNING: Removing unreachable block (ram,0x004db5cc) */
/* WARNING: Removing unreachable block (ram,0x004db5d7) */
/* WARNING: Removing unreachable block (ram,0x004db5d3) */
/* WARNING: Removing unreachable block (ram,0x004db5c7) */
/* WARNING: Removing unreachable block (ram,0x004db5da) */

void FUN_004db460(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0x99) != '\0') {
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
  FUN_004daf90();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x99) == '\0') {
    if (*(char *)(param_2[2] + 0x99) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x99) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x99) == '\0') {
      piVar3 = (int *)FUN_004daea0(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x99) == '\0') {
      uVar4 = FUN_004dae80(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0x26] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x26] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x26] == '\0') {
            *(undefined1 *)(piVar5 + 0x26) = 1;
            *(undefined1 *)(piVar3 + 0x26) = 0;
            FUN_004db100(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x99) == '\0') {
            if ((*(char *)(*piVar5 + 0x98) == '\x01') && (*(char *)(piVar5[2] + 0x98) == '\x01'))
            goto LAB_004db70b;
            if (*(char *)(piVar5[2] + 0x98) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x98) = 1;
              *(undefined1 *)(piVar5 + 0x26) = 0;
              FUN_004daec0(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0x26) = (char)piVar3[0x26];
            *(undefined1 *)(piVar3 + 0x26) = 1;
            *(undefined1 *)(piVar5[2] + 0x98) = 1;
            FUN_004db100(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0x26] == '\0') {
            *(undefined1 *)(piVar5 + 0x26) = 1;
            *(undefined1 *)(piVar3 + 0x26) = 0;
            FUN_004daec0(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x99) == '\0') {
            if ((*(char *)(piVar5[2] + 0x98) != '\x01') || (*(char *)(*piVar5 + 0x98) != '\x01')) {
              if (*(char *)(*piVar5 + 0x98) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x98) = 1;
                *(undefined1 *)(piVar5 + 0x26) = 0;
                FUN_004db100(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0x26) = (char)piVar3[0x26];
              *(undefined1 *)(piVar3 + 0x26) = 1;
              *(undefined1 *)(*piVar5 + 0x98) = 1;
              FUN_004daec0(piVar3);
              break;
            }
LAB_004db70b:
            *(undefined1 *)(piVar5 + 0x26) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x26) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_004db7a0 @ 0x004db7a0 ====

void FUN_004db7a0(undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = param_3;
  piVar1 = *(int **)(in_ECX + 4);
  if ((param_2 == (int *)*piVar1) && (param_3 == piVar1)) {
    FUN_004db1e0(piVar1[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (param_2 != piVar2) {
    FUN_004daf90();
    FUN_004db460(&param_3,param_2);
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_004db820 @ 0x004db820 ====

void FUN_004db820(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0x1d41d3f < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004db220(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x98);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x98) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x26] == '\0') {
LAB_004db928:
        *(undefined1 *)(*piVar5 + 0x98) = 1;
        *(undefined1 *)(piVar6 + 0x26) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x98) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_004db100(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x98) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x98) = 0;
        FUN_004daec0(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x26] == '\0') goto LAB_004db928;
      if (piVar7 == (int *)*piVar2) {
        FUN_004daec0(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x98) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x98) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x99) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x98);
  } while( true );
}


// ==== FUN_004dba30 @ 0x004dba30 ====

void FUN_004dba30(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b18e8;
  if (DAT_00b5ac58 == (undefined4 *)0x0) {
    DAT_00b5ac58 = in_ECX + -1;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance____NULL_009b1808,0x14);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004dbaa0 @ 0x004dbaa0 ====

void FUN_004dbaa0(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b18e8;
  if (DAT_00b5ac58 != 0) {
    DAT_00b5ac58 = 0;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance_009b1820,0xc);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004dbb10 @ 0x004dbb10 ====

void FUN_004dbb10(byte param_1)

{
  void *in_ECX;
  
  FUN_004dbaa0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004dbb30 @ 0x004dbb30 ====

void FUN_004dbb30(void)

{
  FUN_004dbb40();
  return;
}


// ==== FUN_004dbb40 @ 0x004dbb40 ====

void FUN_004dbb40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b18fc;
  in_ECX[1] = &PTR_FUN_009b18f0;
  FUN_004dbaa0();
  *in_ECX = &PTR_FUN_009b1834;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004dbb80 @ 0x004dbb80 ====

void FUN_004dbb80(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x99) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      if ((*param_2 < (uint)puVar4[3]) && (param_2[1] <= (uint)puVar4[4])) {
        puVar3 = (undefined4 *)*puVar4;
        bVar1 = true;
        local_4 = 1;
      }
      else {
        puVar3 = (undefined4 *)puVar4[2];
        bVar1 = false;
        local_4 = 0;
      }
    } while (*(char *)((int)puVar3 + 0x99) == '\0');
  }
  param_2 = puVar4;
  if (bVar1) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      local_4 = 1;
      goto LAB_004dbbe4;
    }
    FUN_004daf20();
  }
  if ((*puVar2 <= param_2[3]) || (puVar2[1] < param_2[4])) {
    *param_1 = param_2;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_004dbbe4:
  puVar4 = (undefined4 *)FUN_004db820(&param_2,local_4,puVar4,puVar2);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_004dbc40 @ 0x004dbc40 ====

undefined4 FUN_004dbc40(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 local_4 [4];
  
  uVar2 = param_1;
  uVar1 = FUN_004db160(param_1);
  uVar2 = FUN_004db1a0(uVar2);
  param_1 = 0;
  FUN_004db3c0(uVar1,uVar2,&param_1);
  FUN_004db7a0(local_4,uVar1,uVar2);
  return param_1;
}


// ==== FUN_004dbc90 @ 0x004dbc90 ====

void FUN_004dbc90(void)

{
  FUN_004dbca0();
  return;
}


// ==== FUN_004dbca0 @ 0x004dbca0 ====

void FUN_004dbca0(byte param_1)

{
  void *in_ECX;
  
  FUN_004daa00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004dbcc0 @ 0x004dbcc0 ====

undefined4 FUN_004dbcc0(undefined4 param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 8);
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  while( true ) {
    if (puVar3 == puVar1) {
      return 0;
    }
    cVar2 = (**(code **)(*(int *)*puVar3 + 8))(param_1);
    if (cVar2 != '\0') break;
    puVar3 = puVar3 + 1;
  }
  return 1;
}


// ==== FUN_004dbd00 @ 0x004dbd00 ====

void FUN_004dbd00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b19a0;
  FUN_004eb890(in_ECX + 1);
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_009b1834;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_004dbd50 @ 0x004dbd50 ====

void FUN_004dbd50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b19a0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_004dbd70 @ 0x004dbd70 ====

void FUN_004dbd70(void)

{
  int iVar1;
  undefined4 *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 local_4;
  
  pvVar3 = operator_new(0x14);
  if (pvVar3 == (void *)0x0) {
    local_4 = 0;
  }
  else {
    local_4 = FUN_004e9130();
  }
  thunk_FUN_004e8de0();
  iVar1 = *(int *)(in_ECX + 8);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x10) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2)))
  {
    FUN_004dbeb0(*(undefined4 *)(in_ECX + 0xc),1,&local_4);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0xc);
    *puVar2 = local_4;
    *(undefined4 **)(in_ECX + 0xc) = puVar2 + 1;
  }
  pvVar3 = operator_new(0x14);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004e88d0();
  }
  thunk_FUN_004e8380();
  iVar1 = *(int *)(in_ECX + 8);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x10) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2)))
  {
    local_4 = uVar4;
    FUN_004dbeb0(*(undefined4 *)(in_ECX + 0xc),1,&local_4);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0xc);
  *puVar2 = uVar4;
  *(undefined4 **)(in_ECX + 0xc) = puVar2 + 1;
  return;
}


// ==== FUN_004dbe50 @ 0x004dbe50 ====

void FUN_004dbe50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b19a0;
  FUN_004eb890(in_ECX + 1);
  if ((void *)in_ECX[2] != (void *)0x0) {
    _free((void *)in_ECX[2]);
    return;
  }
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  *in_ECX = &PTR_FUN_009b1834;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004dbeb0 @ 0x004dbeb0 ====

void FUN_004dbeb0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00981300;
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


// ==== Catch@004dc011 @ 0x004dc011 ====

void Catch_004dc011(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_004dc100 @ 0x004dc100 ====

undefined4 FUN_004dc100(void)

{
  return 0x11;
}


// ==== FUN_004dc110 @ 0x004dc110 ====

void FUN_004dc110(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x44) = param_1;
  return;
}


// ==== FUN_004dc120 @ 0x004dc120 ====

undefined1 FUN_004dc120(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x44);
}


// ==== FUN_004dc130 @ 0x004dc130 ====

int FUN_004dc130(void)

{
  int in_ECX;
  
  return in_ECX + 0x24;
}


// ==== FUN_004dc140 @ 0x004dc140 ====

float10 FUN_004dc140(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x30);
}


// ==== FUN_004dc150 @ 0x004dc150 ====

int FUN_004dc150(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_004dc160 @ 0x004dc160 ====

int FUN_004dc160(void)

{
  int in_ECX;
  
  return in_ECX + 0x14;
}


// ==== FUN_004dc170 @ 0x004dc170 ====

float10 FUN_004dc170(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x20);
}


// ==== FUN_004dc180 @ 0x004dc180 ====

int FUN_004dc180(void)

{
  int in_ECX;
  
  return in_ECX + 0x34;
}


// ==== FUN_004dc190 @ 0x004dc190 ====

float10 FUN_004dc190(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x40);
}


// ==== FUN_004dc1c0 @ 0x004dc1c0 ====

void FUN_004dc1c0(void)

{
  int iVar1;
  int *piVar2;
  undefined1 auStack_68 [4];
  void *pvStack_60;
  undefined1 auStack_5c [4];
  undefined1 uStack_58;
  uint uStack_54;
  undefined4 uStack_50;
  void *pvStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_3c;
  uint uStack_38;
  void *pvStack_30;
  undefined1 auStack_24 [8];
  uint uStack_1c;
  undefined1 auStack_18 [20];
  
  iVar1 = (**(code **)(*DAT_00b5ac24 + 8))();
  if (*(char *)(iVar1 + 1) != '\0') {
    FUN_00401740(s_Dist___2f__color___3f___3f___3f__009b19c0,0x21);
    FUN_00404230(auStack_24);
    uStack_44 = 0xf;
    uStack_48 = 0;
    uStack_58 = 0;
    FUN_00401740(s___Ambient_Color___009b19e4,0x11);
    piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0x18))();
    (**(code **)(*piVar2 + 4))(auStack_5c,auStack_24);
    if (0xf < pvStack_4c) {
      _free(pvStack_60);
      return;
    }
    FUN_00401740(s_Dir____3f___3f___3f__Color____3f_009b19f8,0x2c);
    FUN_00404230(&uStack_48);
    pvStack_4c = (void *)0xf;
    uStack_50 = 0;
    FUN_00401740(s__Direction_Light___009b1a28,0x12);
    piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0x18))();
    (**(code **)(*piVar2 + 4))(auStack_68 + 4,&uStack_48);
    if (0xf < uStack_54) {
      _free(auStack_18 + 0x14);
      return;
    }
    if (0xf < uStack_38) {
      _free(pvStack_4c);
      return;
    }
    uStack_38 = 0xf;
    uStack_3c = 0;
    pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
    if (0xf < uStack_1c) {
      _free(pvStack_30);
      return;
    }
  }
  return;
}


// ==== FUN_004dc360 @ 0x004dc360 ====

void FUN_004dc360(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0x30);
  *(undefined4 *)(in_ECX + 0x24) = *param_1;
  *(undefined4 *)(in_ECX + 0x28) = param_1[1];
  *(undefined4 *)(in_ECX + 0x2c) = param_1[2];
  uVar2 = *param_1;
  uVar3 = param_1[1];
  uVar4 = param_1[2];
  puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    *puVar5 = &PTR_FUN_009b1a44;
  }
  puVar5[1] = uVar2;
  puVar5[2] = uVar3;
  puVar5[3] = uVar4;
  puVar5[4] = uVar1;
  FUN_00797a20(puVar5);
  FUN_004dc1c0();
  return;
}


// ==== FUN_004dc3e0 @ 0x004dc3e0 ====

void FUN_004dc3e0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0x24);
  uVar2 = *(undefined4 *)(in_ECX + 0x28);
  uVar3 = *(undefined4 *)(in_ECX + 0x2c);
  *(undefined4 *)(in_ECX + 0x30) = param_1;
  puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    *puVar4 = &PTR_FUN_009b1a44;
  }
  puVar4[1] = uVar1;
  puVar4[2] = uVar2;
  puVar4[3] = uVar3;
  puVar4[4] = param_1;
  FUN_00797a20(puVar4);
  FUN_004dc1c0();
  return;
}


// ==== FUN_004dc450 @ 0x004dc450 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dc450(float *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_1c [4];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  if (_DAT_009b1a3c < SQRT(param_1[2] * param_1[2] + param_1[1] * param_1[1] + *param_1 * *param_1))
  {
    thunk_FUN_0079e1ba(&local_28,param_1);
    *(undefined4 *)(in_ECX + 8) = local_28;
    *(undefined4 *)(in_ECX + 0xc) = uStack_24;
    *(undefined4 *)(in_ECX + 0x10) = uStack_20;
  }
  uStack_4 = *(undefined4 *)(in_ECX + 0x20);
  local_1c[0] = *(undefined4 *)(in_ECX + 8);
  local_1c[1] = *(undefined4 *)(in_ECX + 0xc);
  local_1c[2] = *(undefined4 *)(in_ECX + 0x10);
  local_1c[3] = *(undefined4 *)(in_ECX + 0x14);
  local_c = *(undefined4 *)(in_ECX + 0x18);
  local_8 = *(undefined4 *)(in_ECX + 0x1c);
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b1a58;
  }
  puVar3 = local_1c;
  puVar4 = puVar1;
  for (iVar2 = 7; puVar4 = puVar4 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
  }
  FUN_00797a20(puVar1);
  FUN_004dc1c0();
  return;
}


// ==== FUN_004dc530 @ 0x004dc530 ====

void FUN_004dc530(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_1c [4];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_4 = *(undefined4 *)(in_ECX + 0x20);
  *(undefined4 *)(in_ECX + 0x14) = *param_1;
  *(undefined4 *)(in_ECX + 0x18) = param_1[1];
  *(undefined4 *)(in_ECX + 0x1c) = param_1[2];
  local_1c[0] = *(undefined4 *)(in_ECX + 8);
  local_1c[1] = *(undefined4 *)(in_ECX + 0xc);
  local_1c[2] = *(undefined4 *)(in_ECX + 0x10);
  local_c = param_1[1];
  local_1c[3] = *param_1;
  local_8 = param_1[2];
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b1a58;
  }
  puVar3 = local_1c;
  puVar4 = puVar1;
  for (iVar2 = 7; puVar4 = puVar4 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
  }
  FUN_00797a20(puVar1);
  FUN_004dc1c0();
  return;
}


// ==== FUN_004dc5d0 @ 0x004dc5d0 ====

void FUN_004dc5d0(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_1c [4];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_1c[0] = *(undefined4 *)(in_ECX + 8);
  local_1c[1] = *(undefined4 *)(in_ECX + 0xc);
  local_1c[2] = *(undefined4 *)(in_ECX + 0x10);
  local_1c[3] = *(undefined4 *)(in_ECX + 0x14);
  local_c = *(undefined4 *)(in_ECX + 0x18);
  local_8 = *(undefined4 *)(in_ECX + 0x1c);
  *(undefined4 *)(in_ECX + 0x20) = param_1;
  local_4 = param_1;
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b1a58;
  }
  puVar3 = local_1c;
  puVar4 = puVar1;
  for (iVar2 = 7; puVar4 = puVar4 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
  }
  FUN_00797a20(puVar1);
  FUN_004dc1c0();
  return;
}


// ==== FUN_004dc660 @ 0x004dc660 ====

void FUN_004dc660(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x34) = *param_1;
  *(undefined4 *)(in_ECX + 0x38) = param_1[1];
  *(undefined4 *)(in_ECX + 0x3c) = param_1[2];
  FUN_004dc1c0();
  return;
}


// ==== FUN_004dc690 @ 0x004dc690 ====

void FUN_004dc690(void)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  float *pfVar5;
  undefined4 *puVar6;
  int in_ECX;
  float10 fVar7;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = *(float *)(in_ECX + 0x34);
  local_c = *(float *)(in_ECX + 0x38);
  local_8 = *(float *)(in_ECX + 0x3c);
  if ((*(int *)(in_ECX + 4) != -1) && (DAT_00b5acd8 != (int *)0x0)) {
    piVar4 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(int *)(in_ECX + 4));
    if (piVar4 != (int *)0x0) {
      pfVar5 = (float *)(**(code **)(*piVar4 + 0x28))();
      fVar2 = *pfVar5;
      fVar3 = pfVar5[1];
      fVar7 = (float10)(**(code **)(*piVar4 + 0x30))();
      local_10 = local_10 + fVar2;
      local_c = (float)((float10)local_c + fVar7);
      local_8 = local_8 + fVar3;
    }
  }
  uVar1 = *(undefined4 *)(in_ECX + 0x40);
  puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    *puVar6 = &PTR_FUN_009b1a6c;
  }
  puVar6[1] = local_10;
  puVar6[2] = local_c;
  puVar6[3] = local_8;
  puVar6[4] = uVar1;
  FUN_00797a20(puVar6);
  FUN_004dc1c0();
  return;
}


// ==== FUN_004dc780 @ 0x004dc780 ====

void FUN_004dc780(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x40) = param_1;
  FUN_004dc690();
  FUN_004dc1c0();
  return;
}


// ==== FUN_004dc7b0 @ 0x004dc7b0 ====

void FUN_004dc7b0(void)

{
  undefined4 *in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009b1a84;
  in_ECX[1] = 0xffffffff;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ac5c = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ac5c = in_ECX;
  }
  local_c = 0;
  local_8 = DAT_0099d080;
  local_4 = 0;
  FUN_004dc450(&local_c);
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  FUN_004dc530(&local_c);
  FUN_004dc5d0(0x3f800000);
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  FUN_004dc360(&local_c);
  FUN_004dc3e0(0x3f800000);
  in_ECX[0x10] = 0;
  FUN_004dc690();
  FUN_004dc1c0();
  local_8 = DAT_0099d080;
  local_c = 0;
  in_ECX[0xd] = 0;
  local_4 = 0;
  in_ECX[0xe] = local_8;
  in_ECX[0xf] = 0;
  FUN_004dc1c0();
  return;
}


// ==== FUN_004dc8c0 @ 0x004dc8c0 ====

void FUN_004dc8c0(void)

{
  undefined4 *in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009b1a84;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  FUN_004dc360(&local_c);
  FUN_004dc3e0(0);
  DAT_00b5ac5c = 0;
  *in_ECX = &PTR_FUN_009b1834;
  return;
}


// ==== FUN_004dc910 @ 0x004dc910 ====

uint FUN_004dc910(int *param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if ((uVar1 == 0x40001) && (*(int *)(in_ECX + 4) != -1)) {
    uVar1 = FUN_004dc690();
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_004dc940 @ 0x004dc940 ====

void FUN_004dc940(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  FUN_004dc690();
  return;
}


// ==== FUN_004dc950 @ 0x004dc950 ====

void FUN_004dc950(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0xffffffff;
  FUN_004dc690();
  return;
}


// ==== FUN_004dc960 @ 0x004dc960 ====

void FUN_004dc960(void)

{
  void *pvVar1;
  
  if (DAT_00b5ac5c == 0) {
    pvVar1 = operator_new(0x48);
    if (pvVar1 != (void *)0x0) {
      FUN_004dc7b0();
      return;
    }
  }
  return;
}


// ==== FUN_004dc980 @ 0x004dc980 ====

undefined4 FUN_004dc980(void)

{
  return 0x60040001;
}


// ==== FUN_004dc990 @ 0x004dc990 ====

undefined4 FUN_004dc990(void)

{
  return 0x60040002;
}


// ==== FUN_004dc9a0 @ 0x004dc9a0 ====

undefined4 FUN_004dc9a0(void)

{
  return 0x60040004;
}


// ==== FUN_004dc9b0 @ 0x004dc9b0 ====

void FUN_004dc9b0(byte param_1)

{
  undefined4 *in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009b1a84;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  FUN_004dc360(&local_c);
  FUN_004dc3e0(0);
  DAT_00b5ac5c = 0;
  *in_ECX = &PTR_FUN_009b1834;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004dca10 @ 0x004dca10 ====

void FUN_004dca10(void)

{
  return;
}


// ==== FUN_004dca20 @ 0x004dca20 ====

undefined4 FUN_004dca20(void)

{
  return 5;
}


// ==== FUN_004dca30 @ 0x004dca30 ====

bool FUN_004dca30(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*(int *)(in_ECX + 4) + 8))(param_1);
  return cVar1 != '\0';
}


// ==== FUN_004dca50 @ 0x004dca50 ====

void FUN_004dca50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1b3c;
  in_ECX[1] = &PTR_FUN_009b1b2c;
  FUN_004e9400();
  *in_ECX = &PTR_FUN_009b1b20;
  in_ECX[1] = &PTR_FUN_009b1b10;
  in_ECX[1] = &PTR_FUN_009b1834;
  FUN_004dcb30();
  return;
}


// ==== FUN_004dca90 @ 0x004dca90 ====

void FUN_004dca90(void)

{
  undefined4 *in_ECX;
  
  FUN_004dcac0();
  in_ECX[1] = &PTR_FUN_009b1834;
  *in_ECX = &PTR_FUN_009b1b3c;
  in_ECX[1] = &PTR_FUN_009b1b2c;
  FUN_004e93e0();
  return;
}


// ==== FUN_004dcac0 @ 0x004dcac0 ====

void FUN_004dcac0(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b1b08;
  if (DAT_00b5ac60 == (undefined4 *)0x0) {
    DAT_00b5ac60 = in_ECX;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance____NULL_009b1adc,0x14);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004dcb30 @ 0x004dcb30 ====

void FUN_004dcb30(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b1b08;
  if (DAT_00b5ac60 != 0) {
    DAT_00b5ac60 = 0;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance_009b1af4,0xc);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004dcba0 @ 0x004dcba0 ====

void FUN_004dcba0(byte param_1)

{
  void *in_ECX;
  
  FUN_004dcb30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004dcbc0 @ 0x004dcbc0 ====

void FUN_004dcbc0(void)

{
  FUN_004dcbd0();
  return;
}


// ==== FUN_004dcbd0 @ 0x004dcbd0 ====

void FUN_004dcbd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1b20;
  in_ECX[1] = &PTR_FUN_009b1b10;
  in_ECX[1] = &PTR_FUN_009b1834;
  FUN_004dcb30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004dcc10 @ 0x004dcc10 ====

void FUN_004dcc10(void)

{
  FUN_004dcc20();
  return;
}


// ==== FUN_004dcc20 @ 0x004dcc20 ====

void FUN_004dcc20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1b3c;
  in_ECX[1] = &PTR_FUN_009b1b2c;
  FUN_004e9400();
  *in_ECX = &PTR_FUN_009b1b20;
  in_ECX[1] = &PTR_FUN_009b1b10;
  in_ECX[1] = &PTR_FUN_009b1834;
  FUN_004dcb30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004dcc70 @ 0x004dcc70 ====

void FUN_004dcc70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1b64;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004dcc90 @ 0x004dcc90 ====

int FUN_004dcc90(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 4) + 0x14;
}


// ==== FUN_004dcca0 @ 0x004dcca0 ====

undefined4 FUN_004dcca0(void)

{
  int in_ECX;
  
  return CONCAT31((int3)((uint)*(int *)(in_ECX + 4) >> 8),
                  *(undefined1 *)(*(int *)(in_ECX + 4) + 0x7d));
}


// ==== FUN_004dccb0 @ 0x004dccb0 ====

undefined4 FUN_004dccb0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 4) + 0x54);
}


// ==== FUN_004dccc0 @ 0x004dccc0 ====

void FUN_004dccc0(void)

{
  FUN_004e9b60();
  return;
}


// ==== FUN_004dccd0 @ 0x004dccd0 ====

void FUN_004dccd0(void)

{
  FUN_004e9fe0();
  return;
}


// ==== FUN_004dcce0 @ 0x004dcce0 ====

undefined4 FUN_004dcce0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 4) + 0xbc);
}


// ==== FUN_004dccf0 @ 0x004dccf0 ====

undefined4 FUN_004dccf0(void)

{
  int in_ECX;
  
  return CONCAT31((int3)((uint)*(int *)(in_ECX + 4) >> 8),
                  *(undefined1 *)(*(int *)(in_ECX + 4) + 0x78));
}


// ==== FUN_004dcd00 @ 0x004dcd00 ====

undefined4 FUN_004dcd00(void)

{
  int in_ECX;
  
  return CONCAT31((int3)((uint)*(int *)(in_ECX + 4) >> 8),
                  *(undefined1 *)(*(int *)(in_ECX + 4) + 0x79));
}


// ==== FUN_004dcd10 @ 0x004dcd10 ====

undefined4 FUN_004dcd10(void)

{
  int in_ECX;
  
  return CONCAT31((int3)((uint)*(int *)(in_ECX + 4) >> 8),*(int *)(*(int *)(in_ECX + 4) + 0x9c) == 2
                 );
}


// ==== FUN_004dcd30 @ 0x004dcd30 ====

undefined4 FUN_004dcd30(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9c);
}


// ==== FUN_004dcd50 @ 0x004dcd50 ====

undefined4 FUN_004dcd50(void)

{
  int in_ECX;
  
  return CONCAT31((int3)((uint)*(int *)(in_ECX + 4) >> 8),
                  *(undefined1 *)(*(int *)(in_ECX + 4) + 0x7b));
}


// ==== FUN_004dcd60 @ 0x004dcd60 ====

undefined4 FUN_004dcd60(void)

{
  int in_ECX;
  
  return CONCAT31((int3)((uint)*(int *)(in_ECX + 4) >> 8),
                  *(undefined1 *)(*(int *)(in_ECX + 4) + 0x7c));
}


// ==== FUN_004dcd70 @ 0x004dcd70 ====

undefined4 FUN_004dcd70(void)

{
  int in_ECX;
  
  return CONCAT31((int3)((uint)*(int *)(in_ECX + 4) >> 8),
                  *(undefined1 *)(*(int *)(in_ECX + 4) + 0x7a));
}


// ==== FUN_004dcd80 @ 0x004dcd80 ====

void FUN_004dcd80(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  puVar1 = in_ECX + 1;
  *in_ECX = &PTR_FUN_009b1bac;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ac1c = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ac1c = in_ECX;
  }
  pvVar2 = operator_new(0xfc);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    return;
  }
  uVar3 = FUN_004eb590();
  *puVar1 = uVar3;
  return;
}


// ==== FUN_004dcdd0 @ 0x004dcdd0 ====

undefined4 FUN_004dcdd0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_004eb190(param_1);
  if (cVar1 != '\x01') {
    iVar2 = (**(code **)(*param_1 + 4))();
    if (iVar2 != 0x50010002) {
      return 0;
    }
    FUN_004eae60();
  }
  return 1;
}


// ==== FUN_004dce10 @ 0x004dce10 ====

void FUN_004dce10(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  
  _Memory = (void *)in_ECX[1];
  *in_ECX = &PTR_FUN_009b1bac;
  if (_Memory == (void *)0x0) {
    in_ECX[1] = 0;
    DAT_00b5ac1c = 0;
    *in_ECX = &PTR_FUN_009b1b64;
    return;
  }
  FUN_004eb350();
  _free(_Memory);
  return;
}


// ==== FUN_004dce50 @ 0x004dce50 ====

uint FUN_004dce50(void)

{
  int *piVar1;
  uint extraout_EAX;
  ushort *puVar2;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  piVar1 = (int *)FUN_004e9b60();
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x2c))();
    puVar2 = (ushort *)(**(code **)(*piVar1 + 0x10))();
    return (uint)*puVar2;
  }
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  local_4 = 0xf;
  FUN_00401740(&DAT_009b1b48,0x17);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    return 0;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_004dcec0 @ 0x004dcec0 ====

void FUN_004dcec0(byte param_1)

{
  void *_Memory;
  undefined4 *in_ECX;
  
  _Memory = (void *)in_ECX[1];
  *in_ECX = &PTR_FUN_009b1bac;
  if (_Memory != (void *)0x0) {
    FUN_004eb350();
    _free(_Memory);
    return;
  }
  in_ECX[1] = 0;
  DAT_00b5ac1c = 0;
  *in_ECX = &PTR_FUN_009b1b64;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004dcf10 @ 0x004dcf10 ====

void FUN_004dcf10(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 6) {
    *param_1 = *param_3;
    param_1[1] = param_3[1];
    param_1[2] = param_3[2];
    param_1[3] = param_3[3];
    param_1[4] = param_3[4];
    param_1[5] = param_3[5];
  }
  return;
}


// ==== FUN_004dcf60 @ 0x004dcf60 ====

void FUN_004dcf60(void)

{
                    /* WARNING: Could not recover jumptable at 0x004dcf68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ac68 + 8))();
  return;
}


// ==== FUN_004dcfd0 @ 0x004dcfd0 ====

undefined4 FUN_004dcfd0(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int unaff_retaddr;
  
  puVar5 = (undefined4 *)(**(code **)(*DAT_00b5ac68 + 4))(param_1);
  if (puVar5 == (undefined4 *)0x0) {
    return 0;
  }
  uVar1 = puVar5[3];
  uVar2 = puVar5[2];
  uVar3 = *puVar5;
  uVar4 = puVar5[1];
  iVar6 = *(int *)(unaff_retaddr + 0x10);
  if (iVar6 == 0) {
    if (DAT_00b5a97c == (int *)0x0) {
      return 0;
    }
    iVar6 = (**(code **)(*DAT_00b5a97c + 0xc))();
  }
  (**(code **)(*DAT_00b5ac70 + 0xc))(iVar6,uVar3,uVar4,uVar2,0,uVar1 & 0xff);
  return uVar3;
}


// ==== FUN_004dd040 @ 0x004dd040 ====

void FUN_004dd040(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int unaff_retaddr;
  
  puVar5 = (undefined4 *)(**(code **)(*DAT_00b5ac68 + 4))(param_1);
  if (puVar5 != (undefined4 *)0x0) {
    uVar1 = puVar5[3];
    uVar2 = puVar5[2];
    uVar3 = *puVar5;
    uVar4 = puVar5[1];
    iVar6 = *(int *)(unaff_retaddr + 0x10);
    if (iVar6 == 0) {
      if (DAT_00b5a97c == (int *)0x0) {
        return;
      }
      iVar6 = (**(code **)(*DAT_00b5a97c + 0xc))();
    }
    (**(code **)(*DAT_00b5ac70 + 0x10))(iVar6,uVar3,uVar4,uVar2,0,uVar1 & 0xff);
  }
  return;
}


// ==== FUN_004dd0a0 @ 0x004dd0a0 ====

undefined4 FUN_004dd0a0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar4 = (undefined4 *)(**(code **)(*DAT_00b5ac68 + 4))(param_1);
  if (puVar4 == (undefined4 *)0x0) {
    return 0;
  }
  uVar1 = puVar4[3];
  uVar2 = *puVar4;
  uVar3 = puVar4[1];
  iVar5 = *(int *)(param_1 + 0x10);
  if (iVar5 == 0) {
    if (DAT_00b5a97c == (int *)0x0) {
      return 0;
    }
    iVar5 = (**(code **)(*DAT_00b5a97c + 0xc))();
  }
  (**(code **)(*DAT_00b5ac70 + 0xc))(iVar5,uVar2,uVar3,param_1,0,uVar1 & 0xff);
  return uVar2;
}


// ==== FUN_004dd120 @ 0x004dd120 ====

void FUN_004dd120(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int unaff_retaddr;
  
  puVar5 = (undefined4 *)(**(code **)(*DAT_00b5ac68 + 4))(param_1);
  if (puVar5 != (undefined4 *)0x0) {
    uVar1 = puVar5[3];
    uVar2 = puVar5[2];
    uVar3 = *puVar5;
    uVar4 = puVar5[1];
    iVar6 = *(int *)(unaff_retaddr + 0x10);
    if (iVar6 == 0) {
      if (DAT_00b5a97c == (int *)0x0) {
        return;
      }
      iVar6 = (**(code **)(*DAT_00b5a97c + 0xc))();
    }
    (**(code **)(*DAT_00b5ac70 + 0xc))(iVar6,uVar3,uVar4,uVar2,param_1,uVar1 & 0xff);
  }
  return;
}


// ==== FUN_004dd180 @ 0x004dd180 ====

void FUN_004dd180(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int unaff_retaddr;
  
  puVar5 = (undefined4 *)(**(code **)(*DAT_00b5ac68 + 4))(param_1);
  if (puVar5 != (undefined4 *)0x0) {
    uVar1 = puVar5[3];
    uVar2 = puVar5[2];
    uVar3 = *puVar5;
    uVar4 = puVar5[1];
    iVar6 = *(int *)(unaff_retaddr + 0x10);
    if (iVar6 == 0) {
      if (DAT_00b5a97c == (int *)0x0) {
        return;
      }
      iVar6 = (**(code **)(*DAT_00b5a97c + 0xc))();
    }
    (**(code **)(*DAT_00b5ac70 + 4))(param_1,iVar6,uVar3,uVar4,uVar2,0,uVar1 & 0xff);
  }
  return;
}


// ==== FUN_004dd1e0 @ 0x004dd1e0 ====

void FUN_004dd1e0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar4 = (undefined4 *)(**(code **)(*DAT_00b5ac68 + 4))(param_1);
  if (puVar4 != (undefined4 *)0x0) {
    uVar1 = puVar4[1];
    uVar2 = puVar4[2];
    uVar3 = *puVar4;
    iVar5 = *(int *)(param_1 + 0x10);
    if (iVar5 == 0) {
      if (DAT_00b5a97c == (int *)0x0) {
        return;
      }
      iVar5 = (**(code **)(*DAT_00b5a97c + 0xc))();
    }
    (**(code **)(*DAT_00b5ac70 + 0x14))(iVar5,uVar3,uVar1,uVar2,param_1);
  }
  return;
}


// ==== FUN_004dd240 @ 0x004dd240 ====

void FUN_004dd240(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = param_2;
  local_c = param_3;
  local_14 = param_1;
  local_4 = param_5;
  local_8 = param_4;
  FUN_004dcfd0(&local_14);
  return;
}


// ==== FUN_004dd280 @ 0x004dd280 ====

void FUN_004dd280(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_14 = param_1;
  local_10 = param_2;
  local_c = param_3;
  local_8 = param_4;
  local_4 = param_6;
  FUN_004dd0a0(&local_14,param_5);
  return;
}


// ==== FUN_004dd2d0 @ 0x004dd2d0 ====

void FUN_004dd2d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_14 = param_1;
  local_10 = param_2;
  local_c = param_3;
  local_8 = param_4;
  local_4 = param_6;
  FUN_004dd120(&local_14,param_5);
  return;
}


// ==== FUN_004dd320 @ 0x004dd320 ====

void FUN_004dd320(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_14 = param_1;
  local_10 = param_2;
  local_c = param_3;
  local_8 = param_4;
  local_4 = param_5;
  FUN_004dd180(&local_14,param_6);
  return;
}


// ==== FUN_004dd370 @ 0x004dd370 ====

void FUN_004dd370(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = param_2;
  local_c = param_3;
  local_14 = param_1;
  local_4 = param_5;
  local_8 = param_4;
  FUN_004dd040(&local_14);
  return;
}


// ==== FUN_004dd3b0 @ 0x004dd3b0 ====

void FUN_004dd3b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_14 = param_1;
  local_10 = param_2;
  local_c = param_3;
  local_8 = param_4;
  local_4 = param_5;
  FUN_004dd1e0(&local_14,param_6);
  return;
}


// ==== FUN_004dd400 @ 0x004dd400 ====

void FUN_004dd400(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int in_ECX;
  int iVar8;
  
  if ((*(int *)(in_ECX + 0xc) != 0) &&
     ((*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc)) / 0x18 != 0)) {
    uVar1 = *(uint *)(param_1 + 4);
    iVar8 = *(int *)(in_ECX + 0xc);
    if (iVar8 != *(int *)(in_ECX + 0x10)) {
      do {
        if (uVar1 < *(uint *)(iVar8 + 0x14)) {
          *(uint *)(iVar8 + 0x14) = *(uint *)(iVar8 + 0x14) - uVar1;
          iVar8 = iVar8 + 0x18;
        }
        else {
          puVar6 = (undefined4 *)(**(code **)(*DAT_00b5ac68 + 4))(iVar8);
          if (puVar6 != (undefined4 *)0x0) {
            uVar2 = puVar6[2];
            uVar3 = *puVar6;
            uVar4 = puVar6[1];
            uVar5 = puVar6[3];
            iVar7 = *(int *)(iVar8 + 0x10);
            if (iVar7 == 0) {
              if (DAT_00b5a97c == (int *)0x0) goto LAB_004dd4a9;
              iVar7 = (**(code **)(*DAT_00b5a97c + 0xc))();
            }
            (**(code **)(*DAT_00b5ac70 + 0x10))(iVar7,uVar3,uVar4,uVar2,0,uVar5 & 0xff);
          }
LAB_004dd4a9:
          FUN_0085d550(iVar8 + 0x18,*(undefined4 *)(in_ECX + 0x10),iVar8,uVar1);
          *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + -0x18;
        }
      } while (iVar8 != *(int *)(in_ECX + 0x10));
    }
  }
  return;
}


// ==== FUN_004dd4f0 @ 0x004dd4f0 ====

void FUN_004dd4f0(int *param_1)

{
  int in_ECX;
  int *piVar1;
  
  piVar1 = *(int **)(in_ECX + 0xc);
  if (piVar1 != *(int **)(in_ECX + 0x10)) {
    do {
      if ((((piVar1[4] == param_1[4]) && (*piVar1 == *param_1)) && (piVar1[1] == param_1[1])) &&
         (piVar1[2] == param_1[2])) {
        FUN_0085d550(piVar1 + 6,*(undefined4 *)(in_ECX + 0x10),piVar1,param_1);
        *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + -0x18;
      }
      else {
        piVar1 = piVar1 + 6;
      }
    } while (piVar1 != *(int **)(in_ECX + 0x10));
  }
  return;
}


// ==== FUN_004dd550 @ 0x004dd550 ====

undefined4 FUN_004dd550(int param_1)

{
  undefined4 extraout_EAX;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  local_8 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_refresh_modeleffect_009b1c18,0x13);
  if (local_8 != 0) {
    return 0;
  }
  local_4 = 0xf;
  local_18 = 0;
  FUN_00401740(s_modeleffect_csv_009b1c2c,0xf);
  (**(code **)(*DAT_00b5a7cc + 0x24))(&local_1c);
  if (local_8 < 0x10) {
    (**(code **)(*DAT_00b5ac68 + 8))();
    return 1;
  }
  _free(local_1c);
  return extraout_EAX;
}


// ==== FUN_004dd5d0 @ 0x004dd5d0 ====

/* WARNING: Removing unreachable block (ram,0x004dd64c) */

void FUN_004dd5d0(void)

{
  undefined4 *in_ECX;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009b1c78;
  in_ECX[1] = &PTR_FUN_009b1c70;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_refresh_modeleffect_009b1c04,0x13);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  if ((void *)in_ECX[3] == (void *)0x0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    FUN_004dd9c0();
    *in_ECX = &PTR_FUN_009b1834;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_004dd680 @ 0x004dd680 ====

undefined4 FUN_004dd680(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x40001) {
    FUN_004dd400(param_1);
  }
  else if (iVar2 == 0x70004) {
    cVar1 = FUN_004dd550(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_004dd6c0 @ 0x004dd6c0 ====

void FUN_004dd6c0(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  undefined1 local_1c [4];
  undefined1 local_18;
  uint uStack_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009b1834;
  FUN_004dd950();
  *in_ECX = &PTR_FUN_009b1c78;
  in_ECX[1] = &PTR_FUN_009b1c70;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_refresh_modeleffect_009b1bf0,0x13);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(local_1c,0);
  if (uStack_c < 0x10) {
    return;
  }
  _free(unaff_EBX);
  return;
}


// ==== FUN_004dd750 @ 0x004dd750 ====

void FUN_004dd750(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,uint param_5
                 ,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  int iStack_4;
  
  local_28 = param_2;
  local_24 = param_3;
  local_2c = param_1;
  local_1c = param_6;
  local_20 = param_4;
  iVar2 = 0;
  FUN_004dd4f0(&local_2c);
  for (; local_20 <= param_5; local_20 = local_20 + 1) {
    iVar1 = (**(code **)(*DAT_00b5ac68 + 4))(&local_2c);
    if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 8), iVar1 != 0)) {
      uStack_14 = local_28;
      uStack_8 = local_1c;
      uStack_10 = local_24;
      uStack_18 = local_2c;
      uStack_c = local_20;
      iStack_4 = iVar2;
      FUN_004dddc0(&uStack_18);
      iVar2 = iVar2 + iVar1;
    }
  }
  return;
}


// ==== FUN_004dd820 @ 0x004dd820 ====

int FUN_004dd820(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981310;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x18) {
    FUN_0057e010(param_3,param_1);
    param_3 = param_3 + 0x18;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@004dd886 @ 0x004dd886 ====

void Catch_004dd886(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004dd890 @ 0x004dd890 ====

void FUN_004dd890(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981320;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_0057e010(param_1,param_3);
    param_1 = param_1 + 0x18;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004dd8f6 @ 0x004dd8f6 ====

void Catch_004dd8f6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004dd900 @ 0x004dd900 ====

void FUN_004dd900(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_004dd820(param_1,param_2,param_3);
  return;
}


// ==== FUN_004dd920 @ 0x004dd920 ====

int FUN_004dd920(int param_1,int param_2,undefined4 param_3)

{
  FUN_004dd890(param_1,param_2,param_3);
  return param_1 + param_2 * 0x18;
}


// ==== FUN_004dd950 @ 0x004dd950 ====

void FUN_004dd950(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b1c68;
  if (DAT_00b5ac64 == (undefined4 *)0x0) {
    DAT_00b5ac64 = in_ECX + -1;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance____NULL_009b1c3c,0x14);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004dd9c0 @ 0x004dd9c0 ====

void FUN_004dd9c0(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b1c68;
  if (DAT_00b5ac64 != 0) {
    DAT_00b5ac64 = 0;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance_009b1c54,0xc);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004dda30 @ 0x004dda30 ====

void FUN_004dda30(byte param_1)

{
  void *in_ECX;
  
  FUN_004dd9c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004dda50 @ 0x004dda50 ====

void FUN_004dda50(void)

{
  FUN_004ddd30();
  return;
}


// ==== FUN_004dda60 @ 0x004dda60 ====

void FUN_004dda60(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint extraout_ECX;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
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
  puStack_c = &LAB_00981330;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x5c);
  local_50 = *param_3;
  local_4c = param_3[1];
  local_48 = param_3[2];
  local_44 = param_3[3];
  local_40 = param_3[4];
  local_3c = param_3[5];
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x18;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x18;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x5c);
    if (0xaaaaaaaU - iVar2 < param_2) {
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
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x18;
    }
    if (local_20 < iVar2 + param_2) {
      if (0xaaaaaaa - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x18;
      }
      if (local_20 < iVar3 + param_2) {
        iVar3 = FUN_0057dfd0();
        local_20 = iVar3 + param_2;
      }
      local_20 = local_20 * 0x18;
      local_18 = operator_new(local_20);
      local_8 = 0;
      local_1c = FUN_004dd900(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_1c = FUN_004dd920(local_1c,param_2,&local_50);
      FUN_004dd900(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x18;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)local_18;
        *(void **)(in_ECX + 8) = (void *)((int)local_18 + (param_2 + iVar3) * 0x18);
        *(void **)(in_ECX + 4) = local_18;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_28 = *(int *)(in_ECX + 8);
    if ((uint)((local_28 - param_1) / 0x18) < param_2) {
      local_24 = param_2 * 0x18;
      FUN_004dd820(param_1,local_28,local_24 + param_1);
      local_8 = 2;
      FUN_004dd920(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x18,&local_50)
      ;
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_24;
      FUN_004dcf10(param_1,*(int *)(in_ECX + 8) - local_24,&local_50);
      ExceptionList = local_10;
      return;
    }
    local_2c = local_28 + param_2 * -0x18;
    uVar4 = FUN_004dd820(local_2c,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_0085d5a0(param_1,local_2c,local_28,local_38);
    FUN_004dcf10(param_1,param_2 * 0x18 + param_1,&local_50);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004ddc21 @ 0x004ddc21 ====

void Catch_004ddc21(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004ddd30 @ 0x004ddd30 ====

void FUN_004ddd30(byte param_1)

{
  void *in_ECX;
  
  FUN_004dd5d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004ddd50 @ 0x004ddd50 ====

void FUN_004ddd50(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x18 != 0) {
      iVar1 = (param_2 - iVar1) / 0x18;
      goto LAB_004ddd95;
    }
  }
  iVar1 = 0;
LAB_004ddd95:
  FUN_004dda60(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x18;
  return;
}


// ==== FUN_004dddc0 @ 0x004dddc0 ====

void FUN_004dddc0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x18) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x18))) {
    FUN_004ddd50(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_004dd890(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x18;
  return;
}


// ==== FUN_004dde50 @ 0x004dde50 ====

void FUN_004dde50(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x21) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x21) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x21);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x21);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x21);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x21);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_004ddea0 @ 0x004ddea0 ====

void FUN_004ddea0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x21) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x21) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x21);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x21);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x21) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x21) == '\0');
    if (*(char *)((int)piVar4 + 0x21) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_004ddf00 @ 0x004ddf00 ====

void FUN_004ddf00(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981340;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
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
  ExceptionList = local_10;
  return;
}


// ==== Catch@004ddf8a @ 0x004ddf8a ====

void Catch_004ddf8a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_004ddfa0 @ 0x004ddfa0 ====

void FUN_004ddfa0(undefined4 param_1,undefined4 param_2,undefined1 param_3,void *param_4)

{
  undefined4 *in_ECX;
  uint in_stack_00000024;
  undefined1 uStack00000028;
  void *in_stack_0000002c;
  uint in_stack_00000040;
  undefined2 in_stack_00000044;
  
  in_ECX[2] = param_2;
  *in_ECX = &PTR_FUN_009b1ce4;
  in_ECX[1] = param_1;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(&param_3,0,0xffffffff);
  in_ECX[0x10] = 0xf;
  in_ECX[0xf] = 0;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  FUN_00401660(&uStack00000028,0,0xffffffff);
  *(undefined2 *)(in_ECX + 0x11) = in_stack_00000044;
  if (0xf < in_stack_00000024) {
    _free(param_4);
    return;
  }
  if (in_stack_00000040 < 0x10) {
    return;
  }
  _free(in_stack_0000002c);
  return;
}


// ==== FUN_004de030 @ 0x004de030 ====

undefined4 FUN_004de030(void)

{
  return 0xb0003;
}


// ==== FUN_004de040 @ 0x004de040 ====

void FUN_004de040(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1ce4;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_004de080 @ 0x004de080 ====

void FUN_004de080(undefined4 param_1,undefined1 param_2,void *param_3)

{
  undefined4 *in_ECX;
  uint in_stack_00000020;
  undefined1 uStack00000024;
  void *in_stack_00000028;
  uint in_stack_0000003c;
  
  *in_ECX = &PTR_FUN_009b1cf8;
  in_ECX[1] = param_1;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  FUN_00401660(&param_2,0,0xffffffff);
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  FUN_00401660(&uStack00000024,0,0xffffffff);
  if (0xf < in_stack_00000020) {
    _free(param_3);
    return;
  }
  if (in_stack_0000003c < 0x10) {
    return;
  }
  _free(in_stack_00000028);
  return;
}


// ==== FUN_004de100 @ 0x004de100 ====

undefined4 FUN_004de100(void)

{
  return 0xb0005;
}


// ==== FUN_004de110 @ 0x004de110 ====

void FUN_004de110(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1cf8;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_004de150 @ 0x004de150 ====

void FUN_004de150(undefined4 param_1,undefined1 param_2,void *param_3)

{
  undefined4 *in_ECX;
  uint in_stack_00000020;
  undefined1 uStack00000024;
  void *in_stack_00000028;
  uint in_stack_0000003c;
  
  *in_ECX = &PTR_FUN_009b1d0c;
  in_ECX[1] = param_1;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  FUN_00401660(&param_2,0,0xffffffff);
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  FUN_00401660(&uStack00000024,0,0xffffffff);
  if (0xf < in_stack_00000020) {
    _free(param_3);
    return;
  }
  if (in_stack_0000003c < 0x10) {
    return;
  }
  _free(in_stack_00000028);
  return;
}


// ==== FUN_004de1d0 @ 0x004de1d0 ====

undefined4 FUN_004de1d0(void)

{
  return 0xb0010;
}


// ==== FUN_004de1e0 @ 0x004de1e0 ====

void FUN_004de1e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1d0c;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_004de220 @ 0x004de220 ====

/* WARNING: Removing unreachable block (ram,0x004de27b) */

uint FUN_004de220(int param_1)

{
  int iVar1;
  uint in_EAX;
  int in_ECX;
  
  if (*(int *)(param_1 + 4) == 2) {
    FUN_00401660(param_1 + 0xc,0,0xffffffff);
    iVar1 = *(int *)(param_1 + 8);
    *(int *)(in_ECX + 0x20) = iVar1 * 1000;
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_004de2a0 @ 0x004de2a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004de2a0(int param_1,undefined4 param_2)

{
  void *pvVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int in_ECX;
  undefined4 in_stack_ffffff78;
  undefined1 in_stack_ffffff7c;
  undefined1 in_stack_ffffff80;
  undefined1 uVar7;
  int local_3c;
  undefined1 local_38 [4];
  void *local_34;
  int local_30;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  undefined4 local_c;
  undefined2 local_8;
  undefined4 local_6;
  
  piVar3 = (int *)FUN_00558e70(&local_3c,&param_2);
  if (*piVar3 == *(int *)(in_ECX + 0xc)) {
    *(undefined4 *)(in_ECX + 0x14) = 1;
    iVar4 = (**(code **)(*DAT_00b5a6a8 + 4))();
    if (iVar4 == 0) {
      FUN_00797a20(0);
      return;
    }
    FUN_00401740(&DAT_009b1ca8,1);
    uVar7 = 0;
    FUN_00401740(&DAT_009b1cac,1);
    uVar5 = FUN_004de080(2,in_stack_ffffff7c,uVar7);
    FUN_00797a20(uVar5);
    return;
  }
  uVar5 = FUN_004e00e0(&param_2);
  FUN_004df280(uVar5);
  iVar4 = *(int *)(in_ECX + 0x1c);
  if (local_34 == (void *)0x0) {
    local_3c = 0;
  }
  else {
    local_3c = (local_30 - (int)local_34) / 0x28;
  }
  local_3c = local_3c + -1;
  fVar2 = (float)local_3c;
  if (local_3c < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  FUN_0040d0a0(0,fVar2);
  iVar6 = FUN_00802534();
  *(int *)(in_ECX + 0x1c) = iVar6;
  if (iVar4 == iVar6) {
    *(uint *)(in_ECX + 0x1c) = iVar6 + 1U;
    if ((local_34 == (void *)0x0) || ((uint)((local_30 - (int)local_34) / 0x28) <= iVar6 + 1U)) {
      *(undefined4 *)(in_ECX + 0x1c) = 0;
    }
  }
  if ((local_34 == (void *)0x0) ||
     ((uint)((local_30 - (int)local_34) / 0x28) <= *(uint *)(in_ECX + 0x1c))) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  pvVar1 = (void *)((int)local_34 + *(uint *)(in_ECX + 0x1c) * 0x28);
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401660(pvVar1,0,0xffffffff);
  local_c = *(undefined4 *)((int)pvVar1 + 0x1c);
  local_8 = *(undefined2 *)((int)pvVar1 + 0x20);
  local_6 = *(undefined4 *)((int)pvVar1 + 0x22);
  if (param_1 == 0) {
    *(undefined4 *)(in_ECX + 0x18) = param_2;
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined4 *)(in_ECX + 0x20) = 10000;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    iVar4 = (**(code **)(*DAT_00b5a6a8 + 4))();
    if (iVar4 == 0) {
      uVar5 = 0;
    }
    else {
      FUN_00401830(&DAT_009b1cae);
      in_stack_ffffff7c = 0;
      FUN_00401660(local_28,0,0xffffffff);
      uVar5 = FUN_004ddfa0(2,local_8,in_stack_ffffff78,in_stack_ffffff7c,in_stack_ffffff80);
    }
    FUN_00797a20(uVar5);
    iVar4 = (**(code **)(*DAT_00b5a6a8 + 4))();
    if (iVar4 != 0) {
      FUN_00401660(local_28,0,0xffffffff);
      FUN_00401830(&DAT_009b1cb0);
      uVar5 = FUN_004de150(2,in_stack_ffffff7c,in_stack_ffffff80);
      goto LAB_004de573;
    }
  }
  else {
    *(undefined4 *)(in_ECX + 0x14) = 1;
    iVar4 = (**(code **)(*DAT_00b5a6a8 + 4))();
    if (iVar4 != 0) {
      FUN_00401830(&DAT_009b1cb4);
      uVar7 = 0;
      FUN_00401660(local_28,0,0xffffffff);
      uVar5 = FUN_004de080(2,in_stack_ffffff7c,uVar7);
      goto LAB_004de573;
    }
  }
  uVar5 = 0;
LAB_004de573:
  FUN_00797a20(uVar5);
  if (local_10 < 0x10) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_004def50(local_34,local_30,local_38,param_2);
    _free(local_34);
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_004de5d0 @ 0x004de5d0 ====

void FUN_004de5d0(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  void *pvVar5;
  undefined1 *puVar6;
  undefined4 uStack_b0;
  int local_ac;
  void *pvStack_a8;
  undefined4 uStack_a4;
  undefined1 auStack_9c [4];
  void *pvStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  int local_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  void *pvStack_7c;
  void *pvStack_78;
  undefined4 uStack_74;
  undefined4 uStack_6c;
  uint uStack_68;
  undefined4 uStack_64;
  undefined2 uStack_60;
  undefined2 uStack_5e;
  undefined2 uStack_5c;
  undefined4 uStack_58;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  undefined2 uStack_8;
  undefined2 uStack_6;
  undefined2 uStack_4;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    local_ac = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
    if (local_ac != 0) {
      uStack_b0 = thunk_FUN_00796fb0(iVar1);
      iVar1 = *(int *)(param_1 + 4);
      if ((iVar1 == 0) || ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uStack_2c = 0xf;
      uStack_30 = 0;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
      FUN_00401660(iVar1 + 0x1c,0,0xffffffff);
      iVar1 = *(int *)(param_1 + 4);
      if ((iVar1 == 0) || ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x1c) < 3)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uStack_88 = thunk_FUN_00796fb0(iVar1 + 0x38);
      iVar1 = *(int *)(param_1 + 4);
      if ((iVar1 == 0) || ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x1c) < 4)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uStack_84 = thunk_FUN_00796f80(iVar1 + 0x54);
      iVar1 = *(int *)(param_1 + 4);
      if ((iVar1 == 0) || ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x1c) < 5)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uVar2 = thunk_FUN_00796f80(iVar1 + 0x70);
      iVar1 = *(int *)(param_1 + 4);
      if ((iVar1 == 0) || ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x1c) < 6)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uVar3 = thunk_FUN_00796f80(iVar1 + 0x8c);
      FUN_00558e70(&local_ac,&uStack_b0);
      if (local_ac == *(int *)(local_8c + 0xc)) {
        uStack_10 = 0xf;
        uStack_14 = 0;
        pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
        FUN_00401660(auStack_44,0,0xffffffff);
        uStack_c = uStack_88;
        uStack_8 = (undefined2)uStack_84;
        pvStack_98 = (void *)0x0;
        uStack_94 = 0;
        uStack_90 = 0;
        uStack_6 = uVar2;
        uStack_4 = uVar3;
        FUN_004df8d0(auStack_28);
        FUN_004df280(auStack_9c);
        uStack_58 = uStack_b0;
        FUN_004df280(&local_ac);
        if (pvStack_a8 != (void *)0x0) {
          FUN_004def50(pvStack_a8,uStack_a4,&local_ac,local_ac);
          _free(pvStack_a8);
          return;
        }
        uStack_80 = uStack_58;
        FUN_004df280(auStack_54);
        FUN_004dfbd0(&local_ac,&uStack_80);
        pvVar5 = pvStack_98;
        if (pvStack_78 != (void *)0x0) {
          FUN_004def50(pvStack_78,uStack_74,&pvStack_7c,local_ac);
          _free(pvStack_78);
          return;
        }
        if (pvStack_50 != (void *)0x0) {
          FUN_004def50(pvStack_50,uStack_4c,auStack_54,local_ac);
          _free(pvStack_50);
          return;
        }
        if (pvStack_98 != (void *)0x0) {
          FUN_004def50(pvStack_98,uStack_94,auStack_9c,local_ac);
          _free(pvVar5);
          return;
        }
        if (uStack_10 < 0x10) goto LAB_004de9b8;
        pvVar5 = pvStack_24;
      }
      else {
        uStack_68 = 0xf;
        uStack_6c = 0;
        pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
        FUN_00401660(auStack_44,0,0xffffffff);
        uStack_60 = (undefined2)uStack_84;
        uStack_64 = uStack_88;
        uStack_5e = uVar2;
        uStack_5c = uVar3;
        uVar4 = FUN_004e00e0(&uStack_b0);
        FUN_004df280(uVar4);
        FUN_004df8d0(&uStack_80);
        puVar6 = auStack_9c;
        FUN_004e00e0(&uStack_b0);
        FUN_004df690(puVar6);
        if (pvStack_98 != (void *)0x0) {
          FUN_004def50(pvStack_98,uStack_94,auStack_9c,local_ac);
          _free(pvStack_98);
          return;
        }
        if (uStack_68 < 0x10) {
LAB_004de9b8:
          if (uStack_2c < 0x10) {
            return;
          }
          _free(pvStack_40);
          return;
        }
        pvVar5 = pvStack_7c;
      }
      _free(pvVar5);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_00405ca0();
}


// ==== FUN_004de9e0 @ 0x004de9e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004de9e0(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int in_ECX;
  undefined4 in_stack_ffffffa0;
  int local_c;
  
  if (*(int *)(in_ECX + 0x14) != 1) {
    iVar5 = *(int *)(param_1 + 4);
    FUN_00558e70(&param_1,in_ECX + 0x18);
    if (param_1 != *(int *)(in_ECX + 0xc)) {
      uVar4 = FUN_004e00e0(in_ECX + 0x18);
      FUN_004df280(uVar4);
      iVar2 = *(int *)(in_ECX + 0x1c);
      iVar1 = local_c + iVar2 * 0x28;
      if ((*(short *)(iVar1 + 0x24) != 0) &&
         (*(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + iVar5,
         (uint)(*(int *)(iVar1 + 0x1c) + *(int *)(in_ECX + 0x20)) < *(uint *)(in_ECX + 0x24))) {
        *(undefined4 *)(in_ECX + 0x24) = 0;
        *(undefined4 *)(in_ECX + 0x20) = 10000;
        param_1 = FUN_00436560();
        param_1 = param_1 + -1;
        fVar3 = (float)param_1;
        if (param_1 < 0) {
          fVar3 = fVar3 + _DAT_0099d104;
        }
        FUN_0040d0a0(0,fVar3);
        iVar5 = FUN_00802534();
        *(int *)(in_ECX + 0x1c) = iVar5;
        if (iVar2 == iVar5) {
          *(uint *)(in_ECX + 0x1c) = iVar5 + 1U;
          uVar6 = FUN_00436560();
          if (uVar6 <= iVar5 + 1U) {
            *(undefined4 *)(in_ECX + 0x1c) = 0;
          }
        }
        iVar5 = (**(code **)(*DAT_00b5a6a8 + 4))();
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          iVar5 = local_c + *(int *)(in_ECX + 0x1c) * 0x28;
          FUN_00401830(&DAT_009b1cb6);
          FUN_00765c50(iVar5);
          uVar4 = FUN_004ddfa0(2,*(undefined2 *)(iVar5 + 0x20),in_stack_ffffffa0);
        }
        FUN_00797a20(uVar4);
        iVar5 = (**(code **)(*DAT_00b5a6a8 + 4))();
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          FUN_00765c50(local_c + *(int *)(in_ECX + 0x1c) * 0x28);
          FUN_00401830(&DAT_009b1cb7);
          uVar4 = FUN_004de150(2);
        }
        FUN_00797a20(uVar4);
        *(undefined4 *)(in_ECX + 0x14) = 0;
      }
      FUN_004df220();
    }
  }
  return;
}


// ==== FUN_004deb80 @ 0x004deb80 ====

void FUN_004deb80(void)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_bgsound_csv_009b1c88,0xb);
  iVar3 = FUN_00410500(local_38);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  if (iVar3 == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_cpScriptRes____NULL_009b1c94,0x13);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_18);
    return;
  }
  iVar4 = *(int *)(iVar3 + 0x40);
  iVar1 = *(int *)(iVar3 + 0x44);
  while( true ) {
    if (iVar4 == iVar1) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(iVar3);
      return;
    }
    local_34 = (void *)0x0;
    local_30 = 0;
    local_2c = 0;
    FUN_00404fb0(iVar4,0x2c,local_38);
    FUN_004de5d0(local_38);
    if (local_34 != (void *)0x0) break;
    iVar4 = iVar4 + 0x1c;
    local_34 = (void *)0x0;
    local_30 = 0;
    local_2c = 0;
  }
  FUN_00405de0(local_34,local_30,local_38,iVar3);
  _free(local_34);
  return;
}


// ==== FUN_004decb0 @ 0x004decb0 ====

undefined4 FUN_004decb0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x40001) {
    FUN_004de9e0(param_1);
  }
  else if (iVar2 == 0xb0011) {
    cVar1 = FUN_004de220(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_004ded00 @ 0x004ded00 ====

void FUN_004ded00(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009b1d30;
  in_ECX[1] = &PTR_FUN_009b1d28;
  FUN_004e01a0(*(undefined4 *)(in_ECX[3] + 4));
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  in_ECX[4] = 0;
  *(undefined4 *)in_ECX[3] = in_ECX[3];
  *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  FUN_004e0210(local_4,*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3]);
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_004ded80 @ 0x004ded80 ====

void FUN_004ded80(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1834;
  FUN_004dedf0();
  in_ECX[1] = &PTR_FUN_009b1d28;
  *in_ECX = &PTR_FUN_009b1d30;
  iVar1 = FUN_004ddf00();
  in_ECX[3] = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  *(undefined4 *)in_ECX[3] = in_ECX[3];
  *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  in_ECX[4] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[9] = 0;
  in_ECX[5] = 1;
  in_ECX[8] = 10000;
  return;
}


// ==== FUN_004dedf0 @ 0x004dedf0 ====

void FUN_004dedf0(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b1d20;
  if (DAT_00b5ac74 == (undefined4 *)0x0) {
    DAT_00b5ac74 = in_ECX + -1;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance____NULL_009b1cb8,0x14);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004dee60 @ 0x004dee60 ====

void FUN_004dee60(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b1d20;
  if (DAT_00b5ac74 != 0) {
    DAT_00b5ac74 = 0;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance_009b1cd0,0xc);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004deed0 @ 0x004deed0 ====

void FUN_004deed0(byte param_1)

{
  void *in_ECX;
  
  FUN_004dee60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004deef0 @ 0x004deef0 ====

int FUN_004deef0(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    FUN_00401660(param_1,0,0xffffffff);
    *(undefined4 *)(param_3 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
    *(undefined2 *)(param_3 + 0x20) = *(undefined2 *)(param_1 + 0x20);
    *(undefined2 *)(param_3 + 0x22) = *(undefined2 *)(param_1 + 0x22);
    *(undefined2 *)(param_3 + 0x24) = *(undefined2 *)(param_1 + 0x24);
    param_1 = param_1 + 0x28;
    param_3 = param_3 + 0x28;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_004def50 @ 0x004def50 ====

void FUN_004def50(int param_1,int param_2)

{
  while( true ) {
    if (param_1 == param_2) {
      return;
    }
    if (0xf < *(uint *)(param_1 + 0x18)) break;
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    param_1 = param_1 + 0x28;
  }
  _free(*(void **)(param_1 + 4));
  return;
}


// ==== FUN_004def90 @ 0x004def90 ====

int FUN_004def90(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x28;
    iVar2 = param_3 + -0x28;
    FUN_00401660(iVar1,0,0xffffffff);
    *(undefined4 *)(param_3 + -0xc) = *(undefined4 *)(param_2 + -0xc);
    *(undefined2 *)(param_3 + -8) = *(undefined2 *)(param_2 + -8);
    *(undefined2 *)(param_3 + -6) = *(undefined2 *)(param_2 + -6);
    *(undefined2 *)(param_3 + -4) = *(undefined2 *)(param_2 + -4);
    param_2 = iVar1;
    param_3 = iVar2;
  } while (iVar1 != param_1);
  return iVar2;
}


// ==== FUN_004deff0 @ 0x004deff0 ====

void FUN_004deff0(int param_1,int param_2)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(param_2,0,0xffffffff);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
    *(undefined2 *)(param_1 + 0x20) = *(undefined2 *)(param_2 + 0x20);
    *(undefined2 *)(param_1 + 0x22) = *(undefined2 *)(param_2 + 0x22);
    *(undefined2 *)(param_1 + 0x24) = *(undefined2 *)(param_2 + 0x24);
  }
  return;
}


// ==== FUN_004df040 @ 0x004df040 ====

int FUN_004df040(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981350;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x28) {
    FUN_004deff0(param_3,param_1);
    param_3 = param_3 + 0x28;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@004df0aa @ 0x004df0aa ====

void Catch_004df0aa(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x28) {
    FUN_00405c70(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004df0d0 @ 0x004df0d0 ====

undefined4 FUN_004df0d0(uint param_1)

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
    param_1 = FUN_0085b3b0();
  }
  pvVar1 = operator_new(param_1 * 0x28);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x28 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_004df120 @ 0x004df120 ====

void FUN_004df120(int param_1,int param_2,int param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x28) {
    FUN_00401660(param_3,0,0xffffffff);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_3 + 0x1c);
    *(undefined2 *)(param_1 + 0x20) = *(undefined2 *)(param_3 + 0x20);
    *(undefined2 *)(param_1 + 0x22) = *(undefined2 *)(param_3 + 0x22);
    *(undefined2 *)(param_1 + 0x24) = *(undefined2 *)(param_3 + 0x24);
  }
  return;
}


// ==== FUN_004df170 @ 0x004df170 ====

void FUN_004df170(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981360;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_004deff0(param_1,param_3);
    param_1 = param_1 + 0x28;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004df1da @ 0x004df1da ====

void Catch_004df1da(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x28) {
    FUN_00405c70(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004df200 @ 0x004df200 ====

void FUN_004df200(undefined4 param_1,undefined4 param_2)

{
  FUN_004def50(param_1,param_2);
  return;
}


// ==== FUN_004df220 @ 0x004df220 ====

void FUN_004df220(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  FUN_004def50(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004df260 @ 0x004df260 ====

void FUN_004df260(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_004df040(param_1,param_2,param_3);
  return;
}


// ==== FUN_004df280 @ 0x004df280 ====

void FUN_004df280(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981370;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x28;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_004df0d0(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_004df260(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004df317 @ 0x004df317 ====

void Catch_004df317(void)

{
  FUN_004df220();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004df330 @ 0x004df330 ====

int FUN_004df330(int param_1,int param_2,undefined4 param_3)

{
  FUN_004df170(param_1,param_2,param_3);
  return param_1 + param_2 * 0x28;
}


// ==== FUN_004df360 @ 0x004df360 ====

void FUN_004df360(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint extraout_ECX;
  undefined1 local_68 [2];
  undefined1 auStack_66 [2];
  void *local_64;
  undefined4 local_54;
  uint local_50;
  undefined4 local_4c;
  undefined2 local_48;
  undefined2 local_46;
  undefined2 local_44;
  undefined4 local_40;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  void *local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981380;
  local_10 = ExceptionList;
  local_14 = local_68 + -0xc;
  local_50 = 0xf;
  local_54 = 0;
  local_64 = (void *)((uint)local_64 & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3,0,0xffffffff);
  local_4c = *(undefined4 *)(param_3 + 0x1c);
  local_48 = *(undefined2 *)(param_3 + 0x20);
  local_46 = *(undefined2 *)(param_3 + 0x22);
  local_44 = *(undefined2 *)(param_3 + 0x24);
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x28;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x28;
    }
    if (0x6666666U - iVar1 < param_2) {
      FUN_0085b3b0();
      uVar4 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x28;
    }
    if (uVar4 < iVar1 + param_2) {
      if (0x6666666 - (uVar4 >> 1) < uVar4) {
        uVar4 = 0;
      }
      else {
        uVar4 = uVar4 + (uVar4 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x28;
      }
      if (uVar4 < iVar2 + param_2) {
        iVar2 = FUN_00436560();
        uVar4 = iVar2 + param_2;
      }
      local_24 = uVar4 * 0x28;
      local_1c = operator_new(local_24);
      local_8 = 0;
      local_18 = local_1c;
      local_18 = (void *)FUN_004df260(*(undefined4 *)(in_ECX + 4),param_1,local_1c);
      local_18 = (void *)FUN_004df330(local_18,param_2,local_68);
      FUN_004df260(param_1,*(undefined4 *)(in_ECX + 8),local_18);
      local_8 = 0xffffffff;
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x28;
      }
      if (iVar2 != 0) {
        FUN_004def50(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(uint *)(in_ECX + 0xc) = local_24 + (int)local_1c;
      *(void **)(in_ECX + 8) = (void *)((int)local_1c + (param_2 + iVar1) * 0x28);
      *(void **)(in_ECX + 4) = local_1c;
    }
    else {
      local_2c = *(int *)(in_ECX + 8);
      if ((uint)((local_2c - param_1) / 0x28) < param_2) {
        local_28 = param_2 * 0x28;
        FUN_004df040(param_1,local_2c,local_28 + param_1);
        local_8 = 2;
        FUN_004df330(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x28,local_68
                    );
        local_8 = 0xffffffff;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_28;
        FUN_004df120(param_1,*(int *)(in_ECX + 8) - local_28,local_68);
      }
      else {
        local_30 = local_2c + param_2 * -0x28;
        uVar3 = FUN_004df040(local_30,local_2c,local_2c);
        *(undefined4 *)(in_ECX + 8) = uVar3;
        FUN_004def90(param_1,local_30,local_2c,local_40);
        FUN_004df120(param_1,param_2 * 0x28 + param_1,local_68);
      }
    }
  }
  if (local_50 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_64);
  return;
}


// ==== Catch@004df545 @ 0x004df545 ====

void Catch_004df545(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_004df200(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@004df5fb @ 0x004df5fb ====

void Catch_004df5fb(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x28;
  FUN_004df200(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x1c) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004df690 @ 0x004df690 ====

void FUN_004df690(int param_1)

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
    iVar6 = iVar6 / 0x28 + iVar2;
    uVar7 = iVar6 - iVar2;
    if (iVar6 != iVar2) {
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = (*(int *)(in_ECX + 8) - iVar2) / 0x28;
      }
      if (uVar7 <= uVar4) {
        uVar5 = FUN_004deef0(iVar1,*(undefined4 *)(param_1 + 8),iVar2,param_1);
        FUN_004def50(uVar5,*(undefined4 *)(in_ECX + 8));
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x28) * 0x28;
        return;
      }
      if (iVar2 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x28;
      }
      if (uVar7 <= uVar4) {
        iVar6 = FUN_00436560();
        iVar6 = iVar1 + iVar6 * 0x28;
        FUN_004deef0(iVar1,iVar6,iVar2,iVar6);
        uVar5 = FUN_004df040(iVar6,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar5;
        return;
      }
      if (iVar2 != 0) {
        FUN_004df200(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      uVar5 = FUN_00436560();
      cVar3 = FUN_004df0d0(uVar5);
      if (cVar3 == '\0') {
        return;
      }
      uVar5 = FUN_004df260(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar5;
      return;
    }
  }
  FUN_004df220();
  return;
}


// ==== FUN_004df820 @ 0x004df820 ====

void FUN_004df820(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x28 != 0) {
      iVar1 = (param_2 - iVar1) / 0x28;
      goto LAB_004df865;
    }
  }
  iVar1 = 0;
LAB_004df865:
  FUN_004df360(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x28;
  return;
}


// ==== FUN_004df890 @ 0x004df890 ====

void FUN_004df890(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = *param_4;
  FUN_004df280(param_4 + 1);
  *(undefined1 *)(in_ECX + 8) = param_5;
  *(undefined1 *)((int)in_ECX + 0x21) = 0;
  return;
}


// ==== FUN_004df8d0 @ 0x004df8d0 ====

void FUN_004df8d0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x28) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x28))) {
    FUN_004df820(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_004df170(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x28;
  return;
}


// ==== FUN_004df960 @ 0x004df960 ====

void * FUN_004df960(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981390;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x24);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_004df890(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@004df9d5 @ 0x004df9d5 ====

void Catch_004df9d5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004df9f0 @ 0x004df9f0 ====

void FUN_004df9f0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0xcccccca < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004df960(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[8] == '\0') {
LAB_004dfaf5:
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
      if ((char)piVar6[8] == '\0') goto LAB_004dfaf5;
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


// ==== FUN_004dfbd0 @ 0x004dfbd0 ====

void FUN_004dfbd0(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_004df9f0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_004ddea0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_004df9f0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004dfc90 @ 0x004dfc90 ====

undefined4 * FUN_004dfc90(undefined4 *param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 local_8 [8];
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_004df9f0(param_1,1,*(undefined4 *)(in_ECX + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    if (*param_3 < (uint)param_2[3]) {
      FUN_004df9f0(param_1,1,param_2,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    if (*(uint *)(piVar1[2] + 0xc) < *param_3) {
      FUN_004df9f0(param_1,0,piVar1[2],param_3);
      return param_1;
    }
  }
  else {
    uVar2 = *param_3;
    uVar3 = param_2[3];
    if (uVar2 < uVar3) {
      FUN_004ddea0();
      if ((uint)param_2[3] < uVar2) {
        if (*(char *)(param_2[2] + 0x21) == '\0') {
          FUN_004df9f0(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_004df9f0(param_1,0,param_2,param_3);
        return param_1;
      }
      uVar3 = param_2[3];
    }
    if (uVar3 < uVar2) {
      FUN_004dde50();
      if ((param_2 == *(int **)(in_ECX + 4)) || (uVar2 < (uint)param_2[3])) {
        if (*(char *)(param_2[2] + 0x21) == '\0') {
          FUN_004df9f0(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_004df9f0(param_1,0,param_2,param_3);
        return param_1;
      }
    }
  }
  puVar4 = (undefined4 *)FUN_004dfbd0(local_8,param_3);
  *param_1 = *puVar4;
  return param_1;
}


// ==== FUN_004dfe00 @ 0x004dfe00 ====

/* WARNING: Removing unreachable block (ram,0x004dff19) */
/* WARNING: Removing unreachable block (ram,0x004dff2a) */
/* WARNING: Removing unreachable block (ram,0x004dff33) */
/* WARNING: Removing unreachable block (ram,0x004dff36) */
/* WARNING: Removing unreachable block (ram,0x004dff26) */
/* WARNING: Removing unreachable block (ram,0x004dff44) */
/* WARNING: Removing unreachable block (ram,0x004dff51) */
/* WARNING: Removing unreachable block (ram,0x004dff5c) */
/* WARNING: Removing unreachable block (ram,0x004dff58) */
/* WARNING: Removing unreachable block (ram,0x004dff4c) */
/* WARNING: Removing unreachable block (ram,0x004dff5f) */

void FUN_004dfe00(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0x21) != '\0') {
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
            goto LAB_004e0034;
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
LAB_004e0034:
            *(undefined1 *)(piVar5 + 8) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 8) = 1;
  }
  if (param_2[5] == 0) {
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    _free(param_2);
    return;
  }
  FUN_004def50(param_2[5],param_2[6],param_2 + 4,param_2);
  _free((void *)param_2[5]);
  return;
}


