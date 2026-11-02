// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x520000-0x52ffff

// ==== FUN_00520030 @ 0x00520030 ====

void FUN_00520030(void)

{
  undefined2 uVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  
  uVar1 = *(undefined2 *)(in_ECX + 0xe);
  iVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uVar3 = *(ushort *)(in_ECX + 0xc) | 0x640000;
  *(uint *)(in_ECX + 8) = uVar3;
  (**(code **)(*DAT_00b5ac70 + 4))
            (0,*(undefined4 *)(in_ECX + 4),uVar3,uVar1,
             *(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24),iVar2 - *(int *)(in_ECX + 0x24),1);
  return;
}


// ==== FUN_00520080 @ 0x00520080 ====

void FUN_00520080(void)

{
  int in_ECX;
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
  
  local_2c = *(undefined4 *)(in_ECX + 4);
  local_10 = *(undefined4 *)(in_ECX + 0x1c);
  local_8 = *(undefined4 *)(in_ECX + 0x20);
  local_28 = *(undefined4 *)(in_ECX + 0x10);
  local_24 = *(undefined4 *)(in_ECX + 0x14);
  local_20 = *(undefined4 *)(in_ECX + 0x18);
  local_1c = *(undefined4 *)(in_ECX + 0x10);
  local_18 = *(undefined4 *)(in_ECX + 0x14);
  local_14 = *(undefined4 *)(in_ECX + 0x18);
  local_c = 0;
  local_4 = 0;
  (**(code **)(*DAT_00b5af38 + 4))(&local_2c);
  return;
}


// ==== FUN_00520110 @ 0x00520110 ====

/* WARNING: Removing unreachable block (ram,0x00520191) */

void FUN_00520110(void)

{
  undefined2 uVar1;
  int in_ECX;
  uint uVar2;
  int iStack_34;
  uint uStack_30;
  
  uVar1 = *(undefined2 *)(in_ECX + 0xe);
  uStack_30 = 0x520128;
  iStack_34 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uStack_30 = 1;
  iStack_34 = iStack_34 - *(int *)(in_ECX + 0x24);
  uVar2 = *(ushort *)(in_ECX + 0xc) | 0x640000;
  *(uint *)(in_ECX + 8) = uVar2;
  (**(code **)(*DAT_00b5ac70 + 0xc))
            (*(undefined4 *)(in_ECX + 4),uVar2,uVar1,
             *(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24));
  uStack_30 = uStack_30 & 0xffffff00;
  FUN_00401740(&DAT_009b7594,0x19);
  FUN_00796d50(&iStack_34);
  return;
}


// ==== FUN_005201b0 @ 0x005201b0 ====

void FUN_005201b0(void)

{
  FUN_00520080();
  FUN_00520110();
  return;
}


// ==== FUN_005201c0 @ 0x005201c0 ====

void FUN_005201c0(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  int iVar3;
  undefined4 *puVar4;
  
  *in_ECX = &PTR_FUN_009b75e4;
  puVar4 = in_ECX + 3;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_1;
    param_1 = param_1 + 1;
    puVar4 = puVar4 + 1;
  }
  if (in_ECX[0xb] == 0) {
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
    uVar2 = (**(code **)(*piVar1 + 4))(2,s___Model2_Holder_Effect_cpp_009b755c,0x13);
    in_ECX[1] = uVar2;
    FUN_00520080();
    FUN_00520110();
    return;
  }
  in_ECX[1] = in_ECX[0xb];
  FUN_00520030();
  return;
}


// ==== FUN_00520230 @ 0x00520230 ====

void FUN_00520230(byte param_1)

{
  void *in_ECX;
  
  FUN_0051ffc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00520250 @ 0x00520250 ====

/* WARNING: Removing unreachable block (ram,0x0052027b) */
/* WARNING: Removing unreachable block (ram,0x00520281) */
/* WARNING: Removing unreachable block (ram,0x005202af) */
/* WARNING: Removing unreachable block (ram,0x00520290) */
/* WARNING: Removing unreachable block (ram,0x005202b3) */
/* WARNING: Removing unreachable block (ram,0x005202bf) */

void FUN_00520250(void)

{
  (**(code **)(*DAT_00b5af0c + 8))();
  (**(code **)(*DAT_00b5af0c + 0xc))();
  return;
}


// ==== FUN_005202d0 @ 0x005202d0 ====

void FUN_005202d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b683c;
  FUN_00514280();
  return;
}


// ==== FUN_005202e0 @ 0x005202e0 ====

int FUN_005202e0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009818b0;
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


// ==== Catch@00520346 @ 0x00520346 ====

void Catch_00520346(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00520350 @ 0x00520350 ====

void * FUN_00520350(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009818c0;
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


// ==== Catch@005203bd @ 0x005203bd ====

void Catch_005203bd(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005203e0 @ 0x005203e0 ====

void FUN_005203e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005202e0(param_1,param_2,param_3);
  return;
}


// ==== FUN_00520400 @ 0x00520400 ====

void FUN_00520400(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = **(undefined4 **)(in_ECX + 0xc);
  return;
}


// ==== FUN_00520410 @ 0x00520410 ====

void FUN_00520410(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0xc);
  return;
}


// ==== FUN_00520420 @ 0x00520420 ====

undefined4 FUN_00520420(undefined4 param_1,undefined4 param_2)

{
  FUN_00598f60(param_1,param_2);
  return param_1;
}


// ==== FUN_00520440 @ 0x00520440 ====

void FUN_00520440(int *param_1)

{
  undefined4 uStack_10;
  int *piStack_c;
  undefined1 auStack_8 [8];
  
  if (param_1 != (int *)0x0) {
    uStack_10 = (**(code **)(*param_1 + 4))();
    piStack_c = param_1;
    FUN_00520800(auStack_8,&uStack_10);
  }
  return;
}


// ==== FUN_00520480 @ 0x00520480 ====

void FUN_00520480(void)

{
  undefined4 *in_ECX;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b6854;
  if (in_ECX[4] != 0) {
    local_4 = (uint)in_ECX & 0xffffff00;
    FUN_0051f7e0(*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3],local_4);
    FUN_00520a30();
  }
  if ((void *)in_ECX[6] == (void *)0x0) {
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    FUN_008984a0();
    *in_ECX = &PTR_FUN_009b6824;
    FUN_005141a0();
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_005204f0 @ 0x005204f0 ====

void FUN_005204f0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_009818d0;
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
      uVar5 = FUN_005203e0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00514100(uVar5,param_2,&local_18);
      FUN_005203e0(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_005202e0(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_00514100(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_005202e0(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00520651 @ 0x00520651 ====

void Catch_00520651(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00520740 @ 0x00520740 ====

void FUN_00520740(uint param_1,undefined1 param_2)

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
    FUN_005204f0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_005207b0 @ 0x005207b0 ====

/* WARNING: Removing unreachable block (ram,0x005207cb) */
/* WARNING: Removing unreachable block (ram,0x005207d0) */
/* WARNING: Removing unreachable block (ram,0x005207de) */

void FUN_005207b0(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_005204f0(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_00520800 @ 0x00520800 ====

/* WARNING: Removing unreachable block (ram,0x005208e8) */

void FUN_00520800(int *param_1,uint *param_2)

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
      FUN_00520740(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
  iVar5 = FUN_00520350(puVar7,puVar7[1],param_2);
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


// ==== FUN_00520a30 @ 0x00520a30 ====

void FUN_00520a30(void)

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
    FUN_005207b0(9,&local_4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00520a90 @ 0x00520a90 ====

void FUN_00520a90(void)

{
  return;
}


// ==== FUN_00520ab0 @ 0x00520ab0 ====

/* WARNING: Removing unreachable block (ram,0x00520af6) */

undefined4 FUN_00520ab0(int *param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  
  (**(code **)(*param_1 + 4))();
  cVar2 = (**(code **)(*param_1 + 8))();
  if (cVar2 == '\0') {
    piVar4 = (int *)(**(code **)(*DAT_00b5acd8 + 0x18))();
    while (piVar4 != (int *)0x0) {
      cVar2 = (**(code **)(*piVar4 + 0x24))(param_1);
      if (cVar2 != '\0') {
        return 1;
      }
      piVar4 = (int *)(**(code **)(*DAT_00b5acd8 + 0x1c))();
    }
  }
  else {
    FUN_00401740(&DAT_009b7640,0x43);
    iVar1 = *DAT_00b5acd8;
    uVar3 = (**(code **)(*param_1 + 0x10))();
    piVar4 = (int *)(**(code **)(iVar1 + 0xc))(uVar3);
    if (piVar4 != (int *)0x0) {
      uVar3 = (**(code **)(*piVar4 + 0x24))(param_1);
      return uVar3;
    }
  }
  return 0;
}


// ==== FUN_00520b80 @ 0x00520b80 ====

void FUN_00520b80(void)

{
  undefined4 *in_ECX;
  
  FUN_00520ba0();
  *in_ECX = &PTR_FUN_009b76c8;
  return;
}


// ==== FUN_00520ba0 @ 0x00520ba0 ====

void FUN_00520ba0(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b76b0;
  if (DAT_00b5af18 == (undefined4 *)0x0) {
    DAT_00b5af18 = in_ECX;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance____NULL_009b7684,0x14);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00520c10 @ 0x00520c10 ====

void FUN_00520c10(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b76b0;
  if (DAT_00b5af18 != 0) {
    DAT_00b5af18 = 0;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance_009b769c,0xc);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00520c80 @ 0x00520c80 ====

void FUN_00520c80(byte param_1)

{
  void *in_ECX;
  
  FUN_00520c10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00520ca0 @ 0x00520ca0 ====

void FUN_00520ca0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b76b8;
  FUN_00520c10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00520cd0 @ 0x00520cd0 ====

void FUN_00520cd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7784;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00520cf0 @ 0x00520cf0 ====

void * FUN_00520cf0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009818e0;
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


// ==== Catch@00520d65 @ 0x00520d65 ====

void Catch_00520d65(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00520d80 @ 0x00520d80 ====

void FUN_00520d80(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_00520d80(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00520dc0 @ 0x00520dc0 ====

void FUN_00520dc0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009818f0;
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


// ==== Catch@00520e4a @ 0x00520e4a ====

void Catch_00520e4a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00520e60 @ 0x00520e60 ====

undefined4 FUN_00520e60(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) == 0) {
    return 0;
  }
  iVar1 = **(int **)(in_ECX + 0xc);
  *(int *)(in_ECX + 4) = iVar1;
  return *(undefined4 *)(iVar1 + 0x10);
}


// ==== FUN_00520e80 @ 0x00520e80 ====

undefined4 FUN_00520e80(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_0079bba0(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0xc)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0x10);
}


// ==== FUN_00520eb0 @ 0x00520eb0 ====

undefined4 FUN_00520eb0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 0xc)) {
    FUN_00458720();
    if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 0xc)) {
      return *(undefined4 *)(*(int *)(in_ECX + 4) + 0x10);
    }
  }
  return 0;
}


// ==== FUN_00520ee0 @ 0x00520ee0 ====

int FUN_00520ee0(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  char *pcVar8;
  undefined4 *****pppppuVar9;
  int extraout_EAX;
  int extraout_EAX_00;
  int in_ECX;
  char *pcVar10;
  int *piVar11;
  undefined4 *****local_18 [4];
  undefined4 local_8;
  uint local_4;
  
  piVar2 = *(int **)(in_ECX + 0xc);
  local_4 = 0xf;
  local_8 = 0;
  local_18[0] = (undefined4 *****)((uint)local_18[0] & 0xffffff00);
  piVar11 = (int *)*piVar2;
  if (piVar11 != piVar2) {
    do {
      piVar6 = (int *)piVar11[4];
      iVar3 = piVar11[3];
      iVar5 = (**(code **)(*piVar6 + 0xc))();
      if (iVar5 == 0) {
        piVar6 = (int *)(**(code **)(*piVar6 + 0x14))();
        piVar6 = (int *)(**(code **)(*piVar6 + 0x24))();
        iVar5 = *piVar6;
        uVar7 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        pcVar8 = (char *)(**(code **)(iVar5 + 0x1c))(uVar7);
        pcVar10 = pcVar8;
        do {
          cVar1 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar1 != '\0');
        FUN_00401740(pcVar8,(int)pcVar10 - (int)(pcVar8 + 1));
        pppppuVar9 = local_18[0];
        if (local_4 < 0x10) {
          pppppuVar9 = local_18;
        }
        iVar5 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),pppppuVar9,local_8);
        if (iVar5 == 0) {
          if (local_4 < 0x10) {
            return iVar3;
          }
          _free(local_18[0]);
          return extraout_EAX_00;
        }
      }
      if (*(char *)((int)piVar11 + 0x15) == '\0') {
        piVar6 = (int *)piVar11[2];
        if (*(char *)((int)piVar6 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar6 + 0x15);
          piVar11 = piVar6;
          piVar6 = (int *)*piVar6;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar6 + 0x15);
            piVar11 = piVar6;
            piVar6 = (int *)*piVar6;
          }
        }
        else {
          cVar1 = *(char *)(piVar11[1] + 0x15);
          piVar4 = (int *)piVar11[1];
          piVar6 = piVar11;
          while ((piVar11 = piVar4, cVar1 == '\0' && (piVar6 == (int *)piVar11[2]))) {
            cVar1 = *(char *)(piVar11[1] + 0x15);
            piVar4 = (int *)piVar11[1];
            piVar6 = piVar11;
          }
        }
      }
    } while (piVar11 != piVar2);
    if (0xf < local_4) {
      _free(local_18[0]);
      return extraout_EAX;
    }
  }
  return 0;
}


// ==== FUN_00521020 @ 0x00521020 ====

void FUN_00521020(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  void *in_ECX;
  uint uVar9;
  undefined1 *puVar10;
  undefined1 uVar11;
  undefined1 auStack_7c [4];
  undefined1 local_78;
  uint uStack_6c;
  undefined4 local_68;
  void *local_64;
  undefined1 auStack_60 [4];
  void *pvStack_5c;
  uint uStack_50;
  undefined4 uStack_4c;
  uint uStack_48;
  int local_44 [17];
  
  local_44[0] = 0;
  local_44[1] = 0;
  local_44[2] = 0;
  local_44[3] = 0;
  local_44[4] = 0;
  local_44[5] = 0;
  local_44[6] = 0;
  local_44[7] = 0;
  local_44[8] = 0;
  local_44[9] = 0;
  local_44[10] = 0;
  local_44[0xb] = 0;
  local_44[0xc] = 0;
  local_44[0xd] = 0;
  puVar2 = *(undefined4 **)((int)in_ECX + 0xc);
  local_64 = (void *)0xf;
  local_68 = 0;
  local_78 = 0;
  puVar3 = (undefined4 *)*puVar2;
  local_44[0xe] = 0;
  local_44[0xf] = 0;
  local_44[0x10] = 0;
  while (puVar3 != puVar2) {
    iVar7 = (**(code **)(*(int *)puVar3[4] + 0xc))();
    local_44[iVar7] = local_44[iVar7] + 1;
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
        puVar6 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar6 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  FUN_00401740(s_Total__d___009b7758,10);
  puVar10 = auStack_60;
  uVar8 = FUN_00404230(puVar10);
  FUN_00401660(uVar8,0,0xffffffff);
  if (0xf < uStack_48) {
    _free(pvStack_5c);
    return;
  }
  uVar9 = 0;
  do {
    uVar11 = 0;
    FUN_00401740(s___d____d___009b7764,10);
    uVar8 = FUN_00404230(auStack_60,puVar10,uVar11);
    FUN_00401ff0(uVar8,0,0xffffffff);
    if (0xf < uStack_48) {
      _free(pvStack_5c);
      return;
    }
    uVar9 = uVar9 + 1;
    uStack_48 = 0xf;
    uStack_4c = 0;
    uVar5 = (uint)pvStack_5c >> 8;
    pvStack_5c = (void *)(uVar5 << 8);
  } while (uVar9 < 0x11);
  uStack_48 = 0xf;
  uStack_4c = 0;
  pvStack_5c = (void *)(uVar5 << 8);
  FUN_00401740(s_Object_Count_009b7770,0xc);
  (**(code **)(*DAT_00b5a688 + 8))(auStack_60,auStack_7c);
  if (0xf < uStack_50) {
    _free(local_64);
    return;
  }
  if (uStack_6c < 0x10) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00521220 @ 0x00521220 ====

undefined4 FUN_00521220(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int *in_ECX;
  char *pcVar4;
  undefined1 *puVar5;
  undefined1 auStack_62 [2];
  undefined1 auStack_60 [4];
  void *pvStack_5c;
  undefined1 auStack_58 [4];
  undefined1 uStack_54;
  uint uStack_48;
  undefined4 uStack_44;
  void *pvStack_40;
  undefined1 auStack_3c [12];
  undefined4 uStack_30;
  uint uStack_2c;
  void *pvStack_24;
  undefined1 auStack_20 [16];
  uint uStack_10;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0xc))(param_1);
  if (piVar2 == (int *)0x0) {
    FUN_00521750(auStack_60,auStack_62 + -6);
    return 1;
  }
  pvStack_40 = (void *)0xf;
  uStack_44 = 0;
  uStack_54 = 0;
  uVar3 = (**(code **)(*piVar2 + 0xc))();
  switch(uVar3) {
  case 0:
    pcVar4 = s_AT_PC_009b76d8;
    break;
  case 1:
    pcVar4 = s_AT_MONSTER_009b76e0;
    break;
  default:
    goto switchD_00521258_caseD_2;
  case 3:
    pcVar4 = s_AT_GUARD_009b7714;
    break;
  case 4:
    pcVar4 = s_AT_NPC_009b76ec;
    break;
  case 5:
    pcVar4 = s_AT_BRICK_009b7728;
    break;
  case 9:
    pcVar4 = s_AT_ITEM_009b76f4;
    break;
  case 10:
    pcVar4 = s_AT_MONEY_009b76fc;
    break;
  case 0xd:
    pcVar4 = s_AT_REMOTE_009b7708;
    break;
  case 0xf:
    pcVar4 = s_AT_FLAG_009b7720;
    break;
  case 0x10:
    pcVar4 = s_AT_ORNAMENT_009b7734;
  }
  FUN_00403810(pcVar4);
switchD_00521258_caseD_2:
  piVar2 = DAT_00b5a6c0;
  puVar5 = auStack_58;
  FUN_00401740(s_Already_Exist____08X___009b7740,0x17);
  uVar3 = FUN_00404230(auStack_20);
  iVar1 = *piVar2;
  uVar3 = FUN_00405bd0(auStack_3c,uVar3,puVar5);
  (**(code **)(iVar1 + 4))(2,uVar3);
  if (0xf < uStack_2c) {
    _free(pvStack_40);
    return extraout_EAX;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return extraout_EAX_00;
  }
  if (uStack_48 < 0x10) {
    return 0;
  }
  _free(pvStack_5c);
  return extraout_EAX_01;
}


// ==== FUN_005213d0 @ 0x005213d0 ====

void FUN_005213d0(void)

{
  undefined4 *in_ECX;
  undefined4 *local_4;
  
  *in_ECX = &PTR_FUN_009b77a8;
  DAT_00b5acd8 = 0;
  local_4 = in_ECX;
  if (in_ECX[4] != 0) {
    local_4 = (undefined4 *)((uint)in_ECX & 0xffffff00);
    FUN_00409660(*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3],local_4);
    FUN_00520d80(*(undefined4 *)(in_ECX[3] + 4));
    *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
    in_ECX[4] = 0;
    *(undefined4 *)in_ECX[3] = in_ECX[3];
    *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  }
  FUN_00521810(&local_4,*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3]);
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00521460 @ 0x00521460 ====

undefined4 FUN_00521460(undefined4 param_1)

{
  undefined4 *puVar1;
  int *in_ECX;
  undefined1 auStackY_90 [128];
  
  puVar1 = (undefined4 *)(**(code **)(*in_ECX + 0xc))(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  (**(code **)*puVar1)(1);
  FUN_005218d0(auStackY_90 + 0x8c);
  return 1;
}


// ==== FUN_005214a0 @ 0x005214a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005214a0(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b77a8;
  puVar1 = in_ECX + 1;
  *puVar1 = 0;
  iVar2 = FUN_00520dc0();
  in_ECX[3] = iVar2;
  *(undefined1 *)(iVar2 + 0x15) = 1;
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  *(undefined4 *)in_ECX[3] = in_ECX[3];
  *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  in_ECX[4] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5acd8 = (undefined4 *)0x0;
    _DAT_00000000 = in_ECX[3];
    return;
  }
  DAT_00b5acd8 = in_ECX;
  *puVar1 = in_ECX[3];
  return;
}


// ==== FUN_00521510 @ 0x00521510 ====

void FUN_00521510(int *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  while (param_1 != param_2) {
    *param_3 = *param_3 + 1;
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
  return;
}


// ==== FUN_00521570 @ 0x00521570 ====

void FUN_00521570(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_00520cf0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00521675:
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
      if ((char)piVar6[5] == '\0') goto LAB_00521675;
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


// ==== FUN_00521750 @ 0x00521750 ====

void FUN_00521750(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_00521570(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00521570(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00521810 @ 0x00521810 ====

void FUN_00521810(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00520d80(piVar6[1]);
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


// ==== FUN_005218d0 @ 0x005218d0 ====

undefined4 FUN_005218d0(undefined4 param_1)

{
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_00408150(&local_8,param_1);
  param_1 = 0;
  FUN_00521510(local_8,local_4,&param_1,0);
  FUN_00521810(&local_8,local_8,local_4);
  return param_1;
}


// ==== FUN_00521930 @ 0x00521930 ====

void FUN_00521930(byte param_1)

{
  void *in_ECX;
  
  FUN_005213d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00521950 @ 0x00521950 ====

void FUN_00521950(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7814;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00521970 @ 0x00521970 ====

undefined4 FUN_00521970(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00521980 @ 0x00521980 ====

undefined4 FUN_00521980(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00521990 @ 0x00521990 ====

undefined4 FUN_00521990(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_005219a0 @ 0x005219a0 ====

void FUN_005219a0(void)

{
  return;
}


// ==== FUN_005219b0 @ 0x005219b0 ====

uint FUN_005219b0(int *param_1)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = (**(code **)(*in_ECX + 0x50))(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_005219e0 @ 0x005219e0 ====

void FUN_005219e0(void)

{
  return;
}


// ==== FUN_005219f0 @ 0x005219f0 ====

int FUN_005219f0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 4) + 0x18;
}


// ==== FUN_00521a00 @ 0x00521a00 ====

int FUN_00521a00(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 4) + 0x20;
}


// ==== FUN_00521a10 @ 0x00521a10 ====

float10 FUN_00521a10(void)

{
  int in_ECX;
  
  return (float10)*(float *)(*(int *)(in_ECX + 4) + 0x34);
}


// ==== FUN_00521a20 @ 0x00521a20 ====

void FUN_00521a20(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00521a25. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x38))();
  return;
}


// ==== FUN_00521a30 @ 0x00521a30 ====

void FUN_00521a30(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7864;
  pvVar1 = operator_new(0x14);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00521ca0();
  }
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x3c);
  if (pvVar1 == (void *)0x0) {
    in_ECX[1] = 0;
    return;
  }
  uVar2 = FUN_0053c7a0();
  in_ECX[1] = uVar2;
  return;
}


// ==== FUN_00521a80 @ 0x00521a80 ====

void FUN_00521a80(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7864;
  iVar1 = *DAT_00b5ac6c;
  uVar2 = (**(code **)(*(int *)in_ECX[2] + 8))();
  (**(code **)(iVar1 + 0x18))(uVar2);
  iVar1 = *DAT_00b5af3c;
  uVar2 = (**(code **)(*(int *)in_ECX[2] + 8))();
  (**(code **)(iVar1 + 8))(uVar2);
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009b7814;
  return;
}


// ==== FUN_00521af0 @ 0x00521af0 ====

void FUN_00521af0(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined2 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  uVar2 = (**(code **)(*piVar1 + 0x24))();
  iVar3 = FUN_00803725(uVar2,0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPortal::RTTI_Type_Descriptor,0);
  if (iVar3 != 0) {
    piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
    uStack_18 = (**(code **)(*piVar1 + 8))();
    uStack_14 = 2;
    uStack_10 = 0;
    uStack_c = *(undefined4 *)(in_ECX[1] + 0x18);
    uStack_8 = *(undefined4 *)(in_ECX[1] + 0x1c);
    uStack_4 = param_1;
    (**(code **)(*DAT_00b5af3c + 4))(&uStack_18);
    iVar3 = (**(code **)(*DAT_00b5a6dc + 0x18))(uStack_18,uStack_14);
    if (iVar3 != 0) {
      uVar2 = (**(code **)(*(int *)in_ECX[2] + 8))();
      FUN_004dd750(0x1f,1,*(undefined2 *)(iVar3 + 0x110),1,2,uVar2);
    }
  }
  return;
}


// ==== FUN_00521bb0 @ 0x00521bb0 ====

undefined4 FUN_00521bb0(void)

{
  return 0;
}


// ==== FUN_00521bc0 @ 0x00521bc0 ====

float10 FUN_00521bc0(float *param_1)

{
  float *pfVar1;
  int *in_ECX;
  
  pfVar1 = (float *)(**(code **)(*in_ECX + 0x28))();
  return SQRT(((float10)param_1[1] - (float10)pfVar1[1]) *
              ((float10)param_1[1] - (float10)pfVar1[1]) +
              ((float10)*param_1 - (float10)*pfVar1) * ((float10)*param_1 - (float10)*pfVar1));
}


// ==== FUN_00521bf0 @ 0x00521bf0 ====

void FUN_00521bf0(byte param_1)

{
  void *in_ECX;
  
  FUN_00521a80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00521c10 @ 0x00521c10 ====

undefined1 FUN_00521c10(void)

{
  return 4;
}


// ==== FUN_00521c20 @ 0x00521c20 ====

void FUN_00521c20(void)

{
  return;
}


// ==== FUN_00521c30 @ 0x00521c30 ====

void FUN_00521c30(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_00521c40 @ 0x00521c40 ====

void FUN_00521c40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b78dc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00521c60 @ 0x00521c60 ====

undefined4 FUN_00521c60(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00521c70 @ 0x00521c70 ====

void FUN_00521c70(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00521c80 @ 0x00521c80 ====

undefined4 FUN_00521c80(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00521c90 @ 0x00521c90 ====

undefined4 FUN_00521c90(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00521ca0 @ 0x00521ca0 ====

void FUN_00521ca0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b797c;
  in_ECX[3] = 0;
  *(undefined1 *)(in_ECX + 4) = 1;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_00521cc0 @ 0x00521cc0 ====

void FUN_00521cc0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b797c;
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b7950;
  }
  puVar1[1] = in_ECX[2];
  FUN_00797a20(puVar1);
  if (in_ECX[3] != 0) {
    (**(code **)(*DAT_00b5adb0 + 0x10))(1,in_ECX[3]);
  }
  *in_ECX = &PTR_FUN_009b78dc;
  return;
}


// ==== FUN_00521d10 @ 0x00521d10 ====

void FUN_00521d10(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 uStack_c;
  int iStack_8;
  
  iVar1 = (**(code **)(*in_ECX + 0x68))();
  if (*(char *)(iVar1 + 0x14) == '\x01') {
    if ((char)in_ECX[4] == '\0') {
      puVar2 = operator_new(0x10);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = &PTR_FUN_009b7964;
        puVar2[3] = 0;
        *(undefined1 *)(puVar2 + 2) = 1;
      }
      uVar3 = (**(code **)(*in_ECX + 8))();
      puVar2[1] = uStack_c;
      iStack_8 = CONCAT31(iStack_8._1_3_,1);
      puVar2[2] = iStack_8;
      puVar2[3] = uVar3;
      FUN_00797a20(puVar2);
      *(undefined1 *)(in_ECX + 4) = 1;
      return;
    }
  }
  else if ((char)in_ECX[4] == '\x01') {
    puVar2 = operator_new(0x10);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009b7964;
      puVar2[3] = 0;
      *(undefined1 *)(puVar2 + 2) = 1;
    }
    uVar3 = (**(code **)(*in_ECX + 8))();
    puVar2[1] = uStack_c;
    iStack_8 = (uint)iStack_8._1_3_ << 8;
    puVar2[2] = iStack_8;
    puVar2[3] = uVar3;
    FUN_00797a20(puVar2);
    *(undefined1 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00521de0 @ 0x00521de0 ====

void FUN_00521de0(int *param_1)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  void *pvVar7;
  int *in_ECX;
  char *pcVar8;
  undefined1 auStack_7c [4];
  void *pvStack_78;
  undefined4 uStack_68;
  uint uStack_64;
  undefined1 auStack_60 [4];
  void *apvStack_5c [4];
  undefined4 uStack_4c;
  uint uStack_48;
  void *pvStack_40;
  undefined1 uStack_3c;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  void *pvStack_24;
  undefined1 uStack_18;
  uint uStack_10;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  in_ECX[3] = (int)param_1;
  iVar3 = (**(code **)(*param_1 + 0x20))();
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  pcVar8 = (char *)(iVar3 + 0x12);
  do {
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar3 + 0x12),(int)pcVar8 - (iVar3 + 0x13));
  uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(5,0x65002f);
  FUN_00401ff0(uVar4,0,0xffffffff);
  iVar3 = (**(code **)(*(int *)in_ECX[3] + 0x20))();
  uVar2 = *(undefined2 *)(iVar3 + 2);
  iVar3 = (**(code **)(*(int *)in_ECX[3] + 0x20))();
  uStack_28 = 0xf;
  uStack_2c = 0;
  uStack_3c = 0;
  pcVar8 = (char *)(iVar3 + 0x12);
  do {
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar3 + 0x12),(int)pcVar8 - (iVar3 + 0x13));
  iVar3 = (**(code **)(*DAT_00b5ad1c + 4))(apvStack_5c);
  if (*(uint *)(iVar3 + 0x18) < 0x10) {
    iVar5 = iVar3 + 4;
  }
  else {
    iVar5 = *(int *)(iVar3 + 4);
  }
  iVar3 = FUN_00403620(0,uStack_30,iVar5,*(undefined4 *)(iVar3 + 0x14));
  if (0xf < uStack_48) {
    _free(apvStack_5c[0]);
    return;
  }
  if (iVar3 == 0) {
    uStack_48 = 0xf;
    uStack_4c = 0;
    apvStack_5c[0] = (void *)((uint)apvStack_5c[0] & 0xffffff00);
    piVar6 = (int *)(**(code **)(*DAT_00b5ab14 + 8))(uVar2);
    if (piVar6 == (int *)0x0) {
      FUN_00401740(s_no_name_009b78bc,7);
    }
    else {
      iVar3 = (**(code **)(*piVar6 + 0x10))();
      pcVar8 = (char *)(iVar3 + 2);
      do {
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_00401740((char *)(iVar3 + 2),(int)pcVar8 - (iVar3 + 3));
    }
    uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(5,0x65003b);
    FUN_00401ff0(uVar4,0,0xffffffff);
    FUN_004020e0(&DAT_009b78c4,3);
    FUN_00401ff0(auStack_60,0,0xffffffff);
    if (0xf < uStack_48) {
      _free(apvStack_5c[0]);
      return;
    }
  }
  uStack_64 = 0xf;
  uStack_68 = 0;
  pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
  FUN_00401740(s_No_Name_009b79ec,7);
  uVar4 = (**(code **)(*in_ECX + 8))();
  FUN_00401660(&uStack_28,0,0xffffffff);
  pvVar7 = operator_new(0x34);
  if (pvVar7 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_00522170();
  }
  *(undefined4 *)(iVar3 + 4) = 0;
  *(undefined1 *)(iVar3 + 8) = 1;
  *(undefined4 *)(iVar3 + 0xc) = uVar4;
  *(undefined4 *)(iVar3 + 0x10) = 0xffffff;
  *(undefined4 *)(iVar3 + 0x14) = 0x3c;
  FUN_00401660(auStack_7c,0,0xffffffff);
  FUN_00797a20(iVar3);
  if (0xf < uStack_64) {
    _free(pvStack_78);
    return;
  }
  uStack_64 = 0xf;
  uStack_68 = 0;
  pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
  if (0xf < uStack_2c) {
    _free(pvStack_40);
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  if (uStack_10 < 0x10) {
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_005220f0 @ 0x005220f0 ====

undefined4 FUN_005220f0(void)

{
  return 0x7004000b;
}


// ==== FUN_00522100 @ 0x00522100 ====

undefined4 FUN_00522100(void)

{
  return 0x7004000c;
}


// ==== FUN_00522110 @ 0x00522110 ====

void FUN_00522110(byte param_1)

{
  void *in_ECX;
  
  FUN_00521cc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00522130 @ 0x00522130 ====

void FUN_00522130(void)

{
  undefined4 *in_ECX;
  
  in_ECX[0xb] = 0xf;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  *in_ECX = 0;
  in_ECX[2] = 0xffffffff;
  in_ECX[3] = 0xffffff;
  in_ECX[4] = 0x38;
  *(undefined1 *)(in_ECX + 1) = 0;
  FUN_00401740(s_No_Name_009b79ec,7);
  return;
}


// ==== FUN_00522170 @ 0x00522170 ====

void FUN_00522170(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b79f8;
  in_ECX[0xc] = 0xf;
  in_ECX[0xb] = 0;
  *(undefined1 *)(in_ECX + 7) = 0;
  in_ECX[1] = 0;
  in_ECX[3] = 0xffffffff;
  in_ECX[4] = 0xffffff;
  in_ECX[5] = 0x38;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401740(s_No_Name_009b79ec,7);
  return;
}


// ==== FUN_005221c0 @ 0x005221c0 ====

undefined4 FUN_005221c0(void)

{
  return 0x7004000a;
}


// ==== FUN_005221d0 @ 0x005221d0 ====

void FUN_005221d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b79f8;
  FUN_00713800();
  *in_ECX = &PTR_FUN_0099cf40;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00522200 @ 0x00522200 ====

undefined4 FUN_00522200(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00522210 @ 0x00522210 ====

undefined4 FUN_00522210(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00522220 @ 0x00522220 ====

undefined4 FUN_00522220(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00522230 @ 0x00522230 ====

void FUN_00522230(void)

{
  return;
}


// ==== FUN_00522250 @ 0x00522250 ====

int FUN_00522250(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 4) + 0x18;
}


// ==== FUN_00522260 @ 0x00522260 ====

int FUN_00522260(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 4) + 0x20;
}


// ==== FUN_00522270 @ 0x00522270 ====

float10 FUN_00522270(void)

{
  int in_ECX;
  
  return (float10)*(float *)(*(int *)(in_ECX + 4) + 0x34);
}


// ==== FUN_00522280 @ 0x00522280 ====

void FUN_00522280(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00522285. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x38))();
  return;
}


// ==== FUN_00522290 @ 0x00522290 ====

void FUN_00522290(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7a6c;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00522520();
  }
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x40);
  if (pvVar1 == (void *)0x0) {
    in_ECX[1] = 0;
    return;
  }
  uVar2 = FUN_0053c860();
  in_ECX[1] = uVar2;
  return;
}


// ==== FUN_005222e0 @ 0x005222e0 ====

void FUN_005222e0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7a6c;
  iVar1 = *DAT_00b5ac6c;
  uVar2 = (**(code **)(*(int *)in_ECX[2] + 8))();
  (**(code **)(iVar1 + 0x18))(uVar2);
  iVar1 = *DAT_00b5af3c;
  uVar2 = (**(code **)(*(int *)in_ECX[2] + 8))();
  (**(code **)(iVar1 + 8))(uVar2);
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009b7814;
  return;
}


// ==== FUN_00522350 @ 0x00522350 ====

undefined4 FUN_00522350(void)

{
  return 0;
}


// ==== FUN_00522360 @ 0x00522360 ====

uint FUN_00522360(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  return uVar1 & 0xffffff00;
}


// ==== FUN_00522370 @ 0x00522370 ====

void FUN_00522370(void)

{
  code *pcVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined2 *puVar5;
  int iVar6;
  int *in_ECX;
  undefined1 auStack_32 [18];
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x14))();
  uVar3 = (**(code **)(*piVar2 + 0x24))();
  piVar2 = (int *)FUN_00803725(uVar3,0,&Framework::ICreature::RTTI_Type_Descriptor,
                               &Framework::Creature::IOrnament::RTTI_Type_Descriptor,0);
  if (piVar2 != (int *)0x0) {
    piVar4 = (int *)(**(code **)(*in_ECX + 0x14))();
    (**(code **)(*piVar4 + 8))();
    piVar4 = DAT_00b5ad20;
    puVar5 = (undefined2 *)(**(code **)(*piVar2 + 0x1c))();
    piVar2 = (int *)(**(code **)(*piVar4 + 0xc))(*puVar5);
    if (piVar2 == (int *)0x0) {
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      FUN_00401740(s_pItemArticle____NULL_009b7a0c,0x14);
      FUN_00406880(auStack_20);
      if (uStack_8 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_1c);
      return;
    }
    piVar2 = (int *)(**(code **)(*piVar2 + 0x48))();
    iVar6 = (**(code **)(*piVar2 + 4))();
    if (*(int *)(iVar6 + 0xc) == 0x900) {
      uVar3 = 1;
    }
    else {
      uVar3 = 2;
    }
    FUN_005224e0(uVar3);
    (**(code **)(*DAT_00b5af3c + 4))(auStack_32 + -6);
  }
  return;
}


// ==== FUN_00522490 @ 0x00522490 ====

float10 FUN_00522490(void)

{
  return (float10)DAT_0099cdc8;
}


// ==== FUN_005224a0 @ 0x005224a0 ====

void FUN_005224a0(byte param_1)

{
  void *in_ECX;
  
  FUN_005222e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005224c0 @ 0x005224c0 ====

undefined4 FUN_005224c0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_005224d0 @ 0x005224d0 ====

void FUN_005224d0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_005224e0 @ 0x005224e0 ====

void FUN_005224e0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_005224f0 @ 0x005224f0 ====

undefined4 FUN_005224f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x14);
}


// ==== FUN_00522500 @ 0x00522500 ====

undefined4 FUN_00522500(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x14);
}


// ==== FUN_00522510 @ 0x00522510 ====

void FUN_00522510(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_00522520 @ 0x00522520 ====

void FUN_00522520(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7ae4;
  in_ECX[5] = 0;
  in_ECX[2] = 0;
  return;
}


// ==== FUN_00522540 @ 0x00522540 ====

void FUN_00522540(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7ae4;
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b7950;
  }
  puVar1[1] = in_ECX[2];
  FUN_00797a20(puVar1);
  if (in_ECX[5] != 0) {
    (**(code **)(*DAT_00b5adfc + 0x10))(1,in_ECX[5]);
  }
  *in_ECX = &PTR_FUN_009b78dc;
  return;
}


// ==== FUN_00522590 @ 0x00522590 ====

void FUN_00522590(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  void *pvVar9;
  int *in_ECX;
  char *pcVar10;
  char *pcVar11;
  undefined1 auStack_a4 [4];
  void *pvStack_a0;
  undefined1 uStack_9c;
  undefined4 uStack_90;
  uint uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  uint uStack_78;
  undefined1 auStack_74 [4];
  void *pvStack_70;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  uint uStack_5c;
  void *pvStack_54;
  undefined1 uStack_50;
  undefined1 auStack_44 [4];
  uint uStack_40;
  undefined4 uStack_3c;
  void *pvStack_38;
  undefined4 uStack_28;
  void *pvStack_24;
  uint uStack_10;
  
  in_ECX[5] = (int)param_1;
  iVar4 = (**(code **)(*param_1 + 0x1c))();
  pcVar11 = (char *)(iVar4 + 0x12);
  uStack_3c = 0xf;
  uStack_40 = 0;
  uStack_50 = 0;
  pcVar10 = pcVar11;
  do {
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar11,(int)pcVar10 - (iVar4 + 0x13));
  puVar5 = (undefined2 *)(**(code **)(*(int *)in_ECX[5] + 0x1c))();
  uVar3 = *puVar5;
  uStack_88 = 0xf;
  uStack_8c = 0;
  uStack_9c = 0;
  FUN_00401740(&DAT_009b7abe,0);
  piVar6 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))
                            (CONCAT22((short)((uint)pcVar11 >> 0x10),uVar3));
  if (piVar6 == (int *)0x0) {
    if (0xf < uStack_8c) {
      _free(pvStack_a0);
      return;
    }
    if (uStack_40 < 0x10) {
      return;
    }
  }
  else {
    iVar4 = (**(code **)(*piVar6 + 4))();
    pcVar10 = (char *)(iVar4 + 0x36);
    do {
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    FUN_00401740((char *)(iVar4 + 0x36),(int)pcVar10 - (iVar4 + 0x37));
    uVar7 = (**(code **)(*DAT_00b5a794 + 0xc))(5,0x650041,auStack_a4);
    uVar7 = FUN_00405bd0(&uStack_28,&uStack_60,uVar7);
    FUN_00405bd0(auStack_44,uVar7);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
    iVar4 = (**(code **)(*piVar6 + 4))();
    piVar6 = DAT_00b5a6ac;
    uVar2 = *(undefined1 *)(iVar4 + 0xc);
    iVar4 = (**(code **)(*param_1 + 0x1c))();
    iVar8 = (**(code **)(*piVar6 + 0x20))();
    iVar4 = *(int *)(iVar4 + 8);
    uVar7 = (**(code **)(*in_ECX + 8))();
    FUN_004dd2d0(0x20,uVar2,(short)in_ECX[3],0,iVar8 - iVar4,uVar7);
    uStack_64 = 0xf;
    uStack_68 = 0;
    uStack_78 = uStack_78 & 0xffffff00;
    uStack_90 = 0;
    uStack_88 = 0xffffffff;
    uStack_84 = 0xffffff;
    uStack_80 = 0x38;
    uStack_8c = uStack_8c & 0xffffff00;
    FUN_00401740(s_No_Name_009b79ec,7);
    uStack_80 = (**(code **)(*in_ECX + 8))();
    uStack_88 = 0;
    uStack_84 = CONCAT31(uStack_84._1_3_,1);
    FUN_00401660(&uStack_3c,0,0xffffffff);
    uStack_78 = 0x3c;
    pvVar9 = operator_new(0x34);
    if (pvVar9 == (void *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_00522170();
    }
    *(undefined4 *)(iVar4 + 4) = uStack_88;
    *(undefined1 *)(iVar4 + 8) = (undefined1)uStack_84;
    *(undefined4 *)(iVar4 + 0xc) = uStack_80;
    *(undefined4 *)(iVar4 + 0x10) = uStack_7c;
    *(uint *)(iVar4 + 0x14) = uStack_78;
    FUN_00401660(auStack_74,0,0xffffffff);
    FUN_00797a20(iVar4);
    if (0xf < uStack_5c) {
      _free(pvStack_70);
      return;
    }
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
    if ((void *)0xf < pvStack_24) {
      _free(pvStack_38);
      return;
    }
    pvStack_24 = (void *)0xf;
    uStack_28 = 0;
    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    if (0xf < uStack_8c) {
      _free(pvStack_a0);
      return;
    }
    if (uStack_40 < 0x10) {
      return;
    }
  }
  uStack_8c = 0xf;
  uStack_90 = 0;
  pvStack_a0 = (void *)((uint)pvStack_a0 & 0xffffff00);
  _free(pvStack_54);
  return;
}


// ==== FUN_00522890 @ 0x00522890 ====

void FUN_00522890(byte param_1)

{
  void *in_ECX;
  
  FUN_00522540();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005228b0 @ 0x005228b0 ====

float10 FUN_005228b0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x24))();
  return (float10)*(float *)(iVar1 + 0x70);
}


// ==== FUN_005228c0 @ 0x005228c0 ====

float10 FUN_005228c0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x28))();
  return (float10)*(float *)(iVar1 + 0x50);
}


// ==== FUN_005228d0 @ 0x005228d0 ====

float10 FUN_005228d0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x24))();
  return (float10)*(float *)(iVar1 + 0x48);
}


// ==== FUN_005228e0 @ 0x005228e0 ====

float10 FUN_005228e0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x24))();
  return (float10)*(byte *)(iVar1 + 0x3c);
}


// ==== FUN_00522900 @ 0x00522900 ====

float10 FUN_00522900(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x24))();
  return (float10)*(byte *)(iVar1 + 0x3d);
}


// ==== FUN_00522920 @ 0x00522920 ====

float10 FUN_00522920(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x24))();
  return (float10)*(float *)(iVar1 + 0x48);
}


// ==== FUN_00522930 @ 0x00522930 ====

undefined1 FUN_00522930(int *param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = (**(code **)(*DAT_00b5ac1c + 0x18))();
  if (cVar1 == '\0') {
    return 0;
  }
  iVar2 = (**(code **)(*param_1 + 0x24))();
  return *(undefined1 *)(iVar2 + 99);
}


// ==== FUN_00522950 @ 0x00522950 ====

undefined1 FUN_00522950(int *param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = (**(code **)(*DAT_00b5ac1c + 0x18))();
  if (cVar1 == '\0') {
    return 0;
  }
  iVar2 = (**(code **)(*param_1 + 0x28))();
  return *(undefined1 *)(iVar2 + 0x43);
}


// ==== FUN_00522970 @ 0x00522970 ====

undefined1 FUN_00522970(int *param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = (**(code **)(*DAT_00b5ac1c + 0x18))();
  if (cVar1 == '\0') {
    return 0;
  }
  iVar2 = (**(code **)(*param_1 + 0x24))();
  return *(undefined1 *)(iVar2 + 0x3b);
}


// ==== FUN_00522990 @ 0x00522990 ====

undefined1 FUN_00522990(int *param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = (**(code **)(*DAT_00b5ac1c + 0x18))();
  if (cVar1 == '\0') {
    return 0;
  }
  iVar2 = (**(code **)(*param_1 + 0x24))();
  return *(undefined1 *)(iVar2 + 0x3b);
}


// ==== FUN_005229b0 @ 0x005229b0 ====

void FUN_005229b0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float10 fVar3;
  undefined4 *unaff_retaddr;
  undefined4 local_14;
  undefined4 local_10;
  float fStack_c;
  undefined4 local_8;
  
  local_14 = *param_2;
  uVar1 = *param_2;
  local_8 = param_2[1];
  uVar2 = param_2[2];
  local_10 = param_2[2];
  fVar3 = (float10)(**(code **)(*DAT_00b5a6b4 + 0x14))(&local_14);
  *unaff_retaddr = uVar1;
  unaff_retaddr[1] = (float)(fVar3 + (float10)fStack_c);
  unaff_retaddr[2] = uVar2;
  return;
}


// ==== FUN_00522a20 @ 0x00522a20 ====

undefined4 FUN_00522a20(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a6fc + 8))();
  piVar2 = (int *)(**(code **)(*piVar1 + 8))();
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    piVar3 = (int *)(**(code **)(**(int **)(*piVar2 + 4) + 0xc))();
    piVar3 = (int *)(**(code **)(*piVar3 + 4))();
    if (param_1 == *piVar3) break;
    piVar2 = (int *)(**(code **)(*piVar1 + 0x48))(piVar2);
  }
  return 1;
}


// ==== FUN_00522a70 @ 0x00522a70 ====

undefined4 FUN_00522a70(int param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  
  switch(*(undefined1 *)(param_1 + 0xb)) {
  case 4:
    pvVar1 = operator_new(0x44);
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_0053e6f0();
    }
    FUN_0053df60(param_2,param_3);
    return uVar2;
  case 5:
    pvVar1 = operator_new(0x28);
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_0053d8f0();
    }
    break;
  default:
    return 0;
  case 0x13:
    pvVar1 = operator_new(0x2c);
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_0053d0c0();
    }
    FUN_0053d0f0(param_2,param_3);
    return uVar2;
  case 0x14:
    pvVar1 = operator_new(0x3c);
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_0053c910();
    }
    FUN_0053c950(param_2,param_3);
    return uVar2;
  }
  FUN_0053d920(param_2,param_3);
  return uVar2;
}


// ==== FUN_00522b80 @ 0x00522b80 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_00522b80(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a764 + 0xc))(1,0);
  iVar1 = *piVar2;
  uVar3 = (**(code **)(*DAT_00b5ac1c + 0x3c))(unaff_ESI);
  (**(code **)(iVar1 + 0x18))(uVar3);
  if ((int *)piVar2[0x13] == (int *)0x0) {
    (**(code **)(_DAT_00000000 + 0x24))(unaff_EDI);
    return piVar2;
  }
  piVar4 = (int *)(**(code **)(*(int *)piVar2[0x13] + 0x18))();
  (**(code **)(*piVar4 + 0x24))(unaff_EDI);
  return piVar2;
}


// ==== FUN_00522be0 @ 0x00522be0 ====

int * FUN_00522be0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  undefined1 auStack_12 [2];
  int iStack_10;
  int iStack_c;
  
  uVar3 = FUN_00522b80(param_3,param_4);
  pvVar4 = operator_new(0x14);
  if (pvVar4 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_0053ec80();
  }
  piVar6 = (int *)(**(code **)(*piVar5 + 0x14))();
  (**(code **)(*piVar6 + 0xc))(param_1);
  iVar1 = param_1;
  FUN_0053f070(param_1);
  FUN_0053f060(uVar3);
  FUN_004f5730(&iStack_10);
  piVar6 = (int *)(**(code **)(*piVar5 + 0x10))();
  iVar8 = *piVar6;
  piVar6[6] = iStack_10;
  piVar6[7] = iStack_c;
  uVar3 = FUN_005e0c90(&param_1);
  (**(code **)(iVar8 + 8))(uVar3);
  piVar7 = (int *)FUN_0040d600(auStack_12 + -10,iStack_c);
  piVar6[8] = *piVar7;
  piVar6[9] = piVar7[1];
  piVar6[0xb] = 0;
  uVar3 = 0;
  iVar8 = (**(code **)(*DAT_00b5a97c + 0xc))();
  if (iVar1 != iVar8) {
    cVar2 = FUN_00522a20(iVar1);
    if (cVar2 == '\0') goto LAB_00522ce5;
  }
  uVar3 = 1;
LAB_00522ce5:
  uVar3 = FUN_00522a70(param_2,piVar5,uVar3);
  FUN_0053ebc0(uVar3);
  (**(code **)(*piVar5 + 0x20))();
  return piVar5;
}


// ==== FUN_00522d20 @ 0x00522d20 ====

undefined4 FUN_00522d20(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00522d30 @ 0x00522d30 ====

undefined4 FUN_00522d30(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_00522d40 @ 0x00522d40 ====

void FUN_00522d40(void)

{
  return;
}


// ==== FUN_00522d50 @ 0x00522d50 ====

undefined1 FUN_00522d50(void)

{
  return 0;
}


// ==== FUN_00522d60 @ 0x00522d60 ====

int FUN_00522d60(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0xc) + 0x18;
}


// ==== FUN_00522d70 @ 0x00522d70 ====

int FUN_00522d70(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0xc) + 0x20;
}


// ==== FUN_00522d80 @ 0x00522d80 ====

float10 FUN_00522d80(void)

{
  int in_ECX;
  
  return (float10)*(float *)(*(int *)(in_ECX + 0xc) + 0x34);
}


// ==== FUN_00522d90 @ 0x00522d90 ====

void FUN_00522d90(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00522d95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x38))();
  return;
}


// ==== FUN_00522da0 @ 0x00522da0 ====

void FUN_00522da0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7bb4;
  pvVar1 = operator_new(0x14);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00522ff0();
  }
  in_ECX[4] = uVar2;
  pvVar1 = operator_new(0x3c);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0053f1c0();
  }
  in_ECX[3] = uVar2;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  in_ECX[2] = 0;
  return;
}


// ==== FUN_00522e00 @ 0x00522e00 ====

void FUN_00522e00(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7bb4;
  iVar1 = *DAT_00b5ac6c;
  uVar2 = (**(code **)(*(int *)in_ECX[4] + 8))();
  (**(code **)(iVar1 + 0x18))(uVar2);
  iVar1 = *DAT_00b5af3c;
  uVar2 = (**(code **)(*(int *)in_ECX[4] + 8))();
  (**(code **)(iVar1 + 8))(uVar2);
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  in_ECX[4] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  *in_ECX = &PTR_FUN_009b7814;
  return;
}


// ==== FUN_00522e70 @ 0x00522e70 ====

void FUN_00522e70(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int *in_ECX;
  undefined4 unaff_ESI;
  undefined1 auStack_16 [22];
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  uVar2 = (**(code **)(*piVar1 + 0x24))();
  piVar1 = (int *)FUN_00803725(uVar2,0,&Framework::ICreature::RTTI_Type_Descriptor,
                               &Framework::Creature::IMoney::RTTI_Type_Descriptor,0);
  if (piVar1 != (int *)0x0) {
    puVar3 = (undefined4 *)(**(code **)(*piVar1 + 0x1c))();
    piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
    uVar2 = (**(code **)(*piVar1 + 8))();
    (**(code **)(*DAT_00b5af3c + 0xc))(*puVar3);
    (**(code **)(*DAT_00b5af3c + 4))(auStack_16 + -6);
    iVar4 = (**(code **)(*DAT_00b5a6dc + 0x18))(unaff_ESI,uVar2);
    if (iVar4 != 0) {
      uVar2 = (**(code **)(*(int *)in_ECX[4] + 8))();
      FUN_004dd240(0x1f,0,*(undefined2 *)(iVar4 + 0x110),0,uVar2);
    }
  }
  return;
}


// ==== FUN_00522f50 @ 0x00522f50 ====

undefined4 FUN_00522f50(void)

{
  return 0;
}


// ==== FUN_00522f60 @ 0x00522f60 ====

float10 FUN_00522f60(float *param_1)

{
  float *pfVar1;
  int *in_ECX;
  
  pfVar1 = (float *)(**(code **)(*in_ECX + 0x28))();
  return SQRT(((float10)param_1[1] - (float10)pfVar1[1]) *
              ((float10)param_1[1] - (float10)pfVar1[1]) +
              ((float10)*param_1 - (float10)*pfVar1) * ((float10)*param_1 - (float10)*pfVar1));
}


// ==== FUN_00522f90 @ 0x00522f90 ====

void FUN_00522f90(byte param_1)

{
  void *in_ECX;
  
  FUN_00522e00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00522fb0 @ 0x00522fb0 ====

undefined4 FUN_00522fb0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00522fc0 @ 0x00522fc0 ====

void FUN_00522fc0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00522fd0 @ 0x00522fd0 ====

undefined4 FUN_00522fd0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00522fe0 @ 0x00522fe0 ====

undefined4 FUN_00522fe0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00522ff0 @ 0x00522ff0 ====

void FUN_00522ff0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7c2c;
  in_ECX[3] = 0;
  *(undefined1 *)(in_ECX + 4) = 1;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_00523010 @ 0x00523010 ====

void FUN_00523010(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7c2c;
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b7950;
  }
  puVar1[1] = in_ECX[2];
  FUN_00797a20(puVar1);
  if (in_ECX[3] != 0) {
    (**(code **)(*DAT_00b5af14 + 0x10))(1,in_ECX[3]);
  }
  *in_ECX = &PTR_FUN_009b78dc;
  return;
}


// ==== FUN_00523060 @ 0x00523060 ====

void FUN_00523060(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 uStack_c;
  int iStack_8;
  
  iVar1 = (**(code **)(*in_ECX + 0x68))();
  if (*(char *)(iVar1 + 0x14) == '\x01') {
    if ((char)in_ECX[4] == '\0') {
      puVar2 = operator_new(0x10);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = &PTR_FUN_009b7964;
        puVar2[3] = 0;
        *(undefined1 *)(puVar2 + 2) = 1;
      }
      uVar3 = (**(code **)(*in_ECX + 8))();
      puVar2[1] = uStack_c;
      iStack_8 = CONCAT31(iStack_8._1_3_,1);
      puVar2[2] = iStack_8;
      puVar2[3] = uVar3;
      FUN_00797a20(puVar2);
      *(undefined1 *)(in_ECX + 4) = 1;
      return;
    }
  }
  else if ((char)in_ECX[4] == '\x01') {
    puVar2 = operator_new(0x10);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009b7964;
      puVar2[3] = 0;
      *(undefined1 *)(puVar2 + 2) = 1;
    }
    uVar3 = (**(code **)(*in_ECX + 8))();
    puVar2[1] = uStack_c;
    iStack_8 = (uint)iStack_8._1_3_ << 8;
    puVar2[2] = iStack_8;
    puVar2[3] = uVar3;
    FUN_00797a20(puVar2);
    *(undefined1 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00523130 @ 0x00523130 ====

void FUN_00523130(int *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  int *in_ECX;
  undefined1 auStack_4c [4];
  void *pvStack_48;
  uint uStack_34;
  undefined4 uStack_30;
  undefined1 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  in_ECX[3] = (int)param_1;
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 0x1c))();
  FUN_004041a0(auStack_4c,*puVar1);
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  uStack_30 = 0;
  uStack_28 = 0xffffffff;
  uStack_24 = 0xffffff;
  uStack_20 = 0x38;
  uStack_2c = 0;
  FUN_00401740(s_No_Name_009b79ec,7);
  uStack_28 = (**(code **)(*in_ECX + 8))();
  uStack_2c = 1;
  uStack_30 = 1;
  FUN_00401660(auStack_4c,0,0xffffffff);
  uStack_20 = 0x3c;
  pvVar2 = operator_new(0x34);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_00522170();
  }
  *(undefined4 *)(iVar3 + 4) = uStack_30;
  *(undefined1 *)(iVar3 + 8) = uStack_2c;
  *(undefined4 *)(iVar3 + 0xc) = uStack_28;
  *(undefined4 *)(iVar3 + 0x10) = uStack_24;
  *(undefined4 *)(iVar3 + 0x14) = uStack_20;
  FUN_00401660(auStack_1c,0,0xffffffff);
  FUN_00797a20(iVar3);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  uStack_4 = 0xf;
  if (uStack_34 < 0x10) {
    return;
  }
  _free(pvStack_48);
  return;
}


// ==== FUN_00523260 @ 0x00523260 ====

void FUN_00523260(byte param_1)

{
  void *in_ECX;
  
  FUN_00523010();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00523280 @ 0x00523280 ====

void FUN_00523280(void)

{
  return;
}


// ==== FUN_00523290 @ 0x00523290 ====

undefined4 FUN_00523290(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_005232a0 @ 0x005232a0 ====

undefined4 FUN_005232a0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_005232b0 @ 0x005232b0 ====

undefined1 FUN_005232b0(void)

{
  return 0;
}


// ==== FUN_005232c0 @ 0x005232c0 ====

int FUN_005232c0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0xc) + 0x18;
}


// ==== FUN_005232d0 @ 0x005232d0 ====

int FUN_005232d0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0xc) + 0x20;
}


// ==== FUN_005232e0 @ 0x005232e0 ====

void FUN_005232e0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005232e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x38))();
  return;
}


// ==== FUN_005232f0 @ 0x005232f0 ====

float10 FUN_005232f0(void)

{
  int in_ECX;
  
  return (float10)*(float *)(*(int *)(in_ECX + 0xc) + 0x34);
}


// ==== FUN_00523300 @ 0x00523300 ====

void FUN_00523300(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7cb4;
  *(undefined1 *)(in_ECX + 1) = 0;
  pvVar1 = operator_new(0x50);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005235a0();
  }
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x40);
  if (pvVar1 == (void *)0x0) {
    in_ECX[3] = 0;
    return;
  }
  uVar2 = FUN_0053f2f0();
  in_ECX[3] = uVar2;
  return;
}


// ==== FUN_00523350 @ 0x00523350 ====

void FUN_00523350(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int in_ECX;
  undefined4 uVar7;
  undefined1 auStack_38 [12];
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
  
  uStack_2c = (**(code **)(**(int **)(in_ECX + 8) + 8))();
  puVar4 = (undefined4 *)FUN_0053f260(auStack_38);
  uStack_28 = *puVar4;
  uStack_24 = puVar4[1];
  uStack_20 = puVar4[2];
  puVar4 = (undefined4 *)FUN_0053f260(auStack_38);
  uStack_1c = *puVar4;
  uStack_18 = puVar4[1];
  uStack_14 = puVar4[2];
  puVar4 = (undefined4 *)FUN_0053f2b0(auStack_38);
  uStack_10 = *puVar4;
  uStack_c = puVar4[1];
  uStack_8 = puVar4[2];
  uStack_4 = *(undefined4 *)(*(int *)(in_ECX + 0xc) + 0x28);
  (**(code **)(*DAT_00b5af38 + 4))(&uStack_2c);
  iVar5 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar1 = *(int **)(in_ECX + 8);
  iVar5 = *(int *)(iVar5 + 0xac);
  iVar2 = piVar1[4];
  iVar3 = piVar1[3];
  uVar6 = (**(code **)(*piVar1 + 8))();
  if ((iVar2 == iVar5) || (uVar7 = 0x507d4, iVar3 == iVar5)) {
    uVar7 = 0x507d1;
  }
  (**(code **)(*DAT_00b5ac70 + 0xc))(uVar6,uVar7,1,5000,0,0);
  return;
}


// ==== FUN_00523440 @ 0x00523440 ====

void FUN_00523440(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = *DAT_00b5af38;
  uVar2 = (**(code **)(**(int **)(in_ECX + 8) + 8))();
  (**(code **)(iVar1 + 8))(uVar2);
  if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 8))(1);
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  if (*(undefined4 **)(in_ECX + 0xc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0xc))(1);
  }
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}


// ==== FUN_00523490 @ 0x00523490 ====

undefined4 FUN_00523490(void)

{
  return 0;
}


// ==== FUN_005234a0 @ 0x005234a0 ====

float10 FUN_005234a0(float *param_1)

{
  float *pfVar1;
  int *in_ECX;
  
  pfVar1 = (float *)(**(code **)(*in_ECX + 0x28))();
  return SQRT(((float10)param_1[1] - (float10)pfVar1[1]) *
              ((float10)param_1[1] - (float10)pfVar1[1]) +
              ((float10)*param_1 - (float10)*pfVar1) * ((float10)*param_1 - (float10)*pfVar1));
}


// ==== FUN_005234d0 @ 0x005234d0 ====

void FUN_005234d0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7cb4;
  iVar1 = *DAT_00b5af38;
  uVar2 = (**(code **)(*(int *)in_ECX[2] + 8))();
  (**(code **)(iVar1 + 8))(uVar2);
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  *in_ECX = &PTR_FUN_009b7814;
  return;
}


// ==== FUN_00523520 @ 0x00523520 ====

void FUN_00523520(byte param_1)

{
  void *in_ECX;
  
  FUN_005234d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00523540 @ 0x00523540 ====

undefined4 FUN_00523540(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00523550 @ 0x00523550 ====

void FUN_00523550(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00523560 @ 0x00523560 ====

undefined4 FUN_00523560(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x4c);
}


// ==== FUN_00523570 @ 0x00523570 ====

undefined4 FUN_00523570(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x4c);
}


// ==== FUN_00523580 @ 0x00523580 ====

void FUN_00523580(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = *param_1;
  return;
}


// ==== FUN_00523590 @ 0x00523590 ====

void FUN_00523590(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = *param_1;
  return;
}


// ==== FUN_005235a0 @ 0x005235a0 ====

void FUN_005235a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7d2c;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0xf;
  *(undefined1 *)(in_ECX + 6) = 0;
  in_ECX[0x12] = 0xf;
  in_ECX[0x11] = 0;
  *(undefined1 *)(in_ECX + 0xd) = 0;
  in_ECX[0x13] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_005235d0 @ 0x005235d0 ====

void FUN_005235d0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7d2c;
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b7950;
  }
  puVar1[1] = in_ECX[2];
  FUN_00797a20(puVar1);
  if ((int *)in_ECX[0x13] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x13] + 4))();
    (**(code **)(*DAT_00b5ae00 + 0x10))(1,in_ECX[0x13]);
  }
  if (0xf < (uint)in_ECX[0x12]) {
    _free((void *)in_ECX[0xd]);
    return;
  }
  in_ECX[0x12] = 0xf;
  in_ECX[0x11] = 0;
  *(undefined1 *)(in_ECX + 0xd) = 0;
  if ((uint)in_ECX[0xb] < 0x10) {
    in_ECX[10] = 0;
    in_ECX[0xb] = 0xf;
    *(undefined1 *)(in_ECX + 6) = 0;
    *in_ECX = &PTR_FUN_009b78dc;
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_00523670 @ 0x00523670 ====

void FUN_00523670(undefined4 param_1)

{
  FUN_00401660(param_1,0,0xffffffff);
  return;
}


// ==== FUN_00523690 @ 0x00523690 ====

void FUN_00523690(undefined4 param_1)

{
  FUN_00401660(param_1,0,0xffffffff);
  return;
}


// ==== FUN_005236b0 @ 0x005236b0 ====

int FUN_005236b0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int unaff_retaddr;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_2);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
    *(undefined4 *)(unaff_retaddr + 0x14) = 0;
    *(undefined1 *)(unaff_retaddr + 4) = 0;
    FUN_00401740(s_Enemy_009b7d14,5);
    return unaff_retaddr;
  }
  iVar2 = (**(code **)(*piVar1 + 0xc))();
  if (iVar2 == 0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
    (**(code **)(*piVar1 + 0x40))(unaff_retaddr);
    return unaff_retaddr;
  }
  *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
  *(undefined4 *)(unaff_retaddr + 0x14) = 0;
  *(undefined1 *)(unaff_retaddr + 4) = 0;
  FUN_00401740(s_Enemy_009b7d1c,5);
  return unaff_retaddr;
}


// ==== FUN_00523740 @ 0x00523740 ====

void FUN_00523740(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int in_ECX;
  void *unaff_EBX;
  undefined1 local_bc [2];
  undefined1 auStack_ba [2];
  void *local_b8;
  undefined4 uStack_b0;
  uint uStack_ac;
  undefined4 local_a8;
  uint local_a4;
  undefined4 local_a0;
  uint local_9c;
  undefined4 local_98;
  undefined4 local_94;
  void *local_90;
  undefined1 local_88;
  uint uStack_7c;
  undefined4 local_78;
  void *local_74;
  undefined1 local_70 [12];
  undefined4 uStack_64;
  uint uStack_60;
  undefined4 local_5c;
  void *pvStack_58;
  undefined4 uStack_48;
  uint uStack_44;
  undefined1 auStack_40 [4];
  void *pvStack_3c;
  undefined1 local_38 [12];
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 local_24;
  void *pvStack_20;
  uint uStack_c;
  
  *(undefined4 *)(in_ECX + 0x4c) = param_1;
  local_74 = (void *)0xf;
  local_78 = 0;
  local_88 = 0;
  local_a0 = 0;
  local_98 = 0xffffffff;
  local_94 = 0xffffff;
  local_90 = (void *)0x38;
  local_9c = local_9c & 0xffffff00;
  FUN_00401740(s_No_Name_009b79ec,7);
  local_98 = *(undefined4 *)(in_ECX + 8);
  local_a0 = 0;
  local_94 = 0xffff00;
  local_90 = (void *)0x38;
  local_9c = CONCAT31(local_9c._1_3_,1);
  FUN_005236b0(local_70,*(undefined4 *)(in_ECX + 0x10));
  iVar1 = FUN_00403620(0,local_5c,s_Enemy_009b7d04,5);
  if (iVar1 == 0) {
    local_a4 = 0xf;
    local_a8 = 0;
    local_b8 = (void *)((uint)local_b8 & 0xffffff00);
    FUN_00401660(in_ECX + 0x30,0,0xffffffff);
    FUN_00401660(local_bc,0,0xffffffff);
    if (0xf < local_a4) {
      _free(local_b8);
      return;
    }
  }
  FUN_005236b0(local_38,*(undefined4 *)(in_ECX + 0xc));
  iVar1 = FUN_00403620(0,local_24,s_Enemy_009b7d0c,5);
  if (iVar1 == 0) {
    local_a4 = 0xf;
    local_a8 = 0;
    local_b8 = (void *)((uint)local_b8 & 0xffffff00);
    FUN_00401660(in_ECX + 0x14,0,0xffffffff);
    FUN_00401660(local_bc,0,0xffffffff);
    if (0xf < local_a4) {
      _free(local_b8);
      return;
    }
  }
  uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x3f00012);
  uStack_44 = 0xf;
  uStack_48 = 0;
  pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
  FUN_00401660(uVar2,0,0xffffffff);
  uVar2 = FUN_00405bd0(&local_24,&local_78,&local_5c,auStack_40);
  uVar2 = FUN_00405bd0(local_bc + -8,uVar2);
  FUN_00401660(uVar2,0,0xffffffff);
  if (0xf < uStack_ac) {
    _free(unaff_EBX);
    return;
  }
  uStack_ac = 0xf;
  uStack_b0 = 0;
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  pvVar3 = operator_new(0x34);
  if (pvVar3 == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00522170();
  }
  *(undefined4 *)(iVar1 + 4) = local_a8;
  *(undefined1 *)(iVar1 + 8) = (undefined1)local_a4;
  *(undefined4 *)(iVar1 + 0xc) = local_a0;
  *(uint *)(iVar1 + 0x10) = local_9c;
  *(undefined4 *)(iVar1 + 0x14) = local_98;
  FUN_00401660(&local_94,0,0xffffffff);
  FUN_00797a20(iVar1);
  if (0xf < uStack_44) {
    _free(pvStack_58);
    return;
  }
  uStack_44 = 0xf;
  uStack_48 = 0;
  pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
  if (0xf < uStack_28) {
    _free(pvStack_3c);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  if (0xf < uStack_60) {
    _free(local_74);
    return;
  }
  uStack_60 = 0xf;
  uStack_64 = 0;
  local_74 = (void *)((uint)local_74 & 0xffffff00);
  if (uStack_7c < 0x10) {
    return;
  }
  _free(local_90);
  return;
}


// ==== FUN_00523a40 @ 0x00523a40 ====

void FUN_00523a40(byte param_1)

{
  void *in_ECX;
  
  FUN_005235d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00523a60 @ 0x00523a60 ====

undefined4 FUN_00523a60(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00523a70 @ 0x00523a70 ====

undefined4 FUN_00523a70(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00523a80 @ 0x00523a80 ====

undefined4 FUN_00523a80(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00523a90 @ 0x00523a90 ====

void FUN_00523a90(void)

{
  return;
}


// ==== FUN_00523aa0 @ 0x00523aa0 ====

undefined1 FUN_00523aa0(void)

{
  return 0;
}


// ==== FUN_00523ab0 @ 0x00523ab0 ====

int FUN_00523ab0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 4) + 0x18;
}


// ==== FUN_00523ac0 @ 0x00523ac0 ====

int FUN_00523ac0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 4) + 0x20;
}


// ==== FUN_00523ad0 @ 0x00523ad0 ====

float10 FUN_00523ad0(void)

{
  int in_ECX;
  
  return (float10)*(float *)(*(int *)(in_ECX + 4) + 0x34);
}


// ==== FUN_00523ae0 @ 0x00523ae0 ====

void FUN_00523ae0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00523ae5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x38))();
  return;
}


// ==== FUN_00523af0 @ 0x00523af0 ====

void FUN_00523af0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7de4;
  pvVar1 = operator_new(0x18);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00523d30();
  }
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x3c);
  if (pvVar1 == (void *)0x0) {
    in_ECX[1] = 0;
    return;
  }
  uVar2 = FUN_0053f3e0();
  in_ECX[1] = uVar2;
  return;
}


// ==== FUN_00523b40 @ 0x00523b40 ====

void FUN_00523b40(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7de4;
  iVar1 = *DAT_00b5ac6c;
  uVar2 = (**(code **)(*(int *)in_ECX[2] + 8))();
  (**(code **)(iVar1 + 0x18))(uVar2);
  iVar1 = *DAT_00b5af3c;
  uVar2 = (**(code **)(*(int *)in_ECX[2] + 8))();
  (**(code **)(iVar1 + 8))(uVar2);
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009b7814;
  return;
}


// ==== FUN_00523bb0 @ 0x00523bb0 ====

void FUN_00523bb0(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  int iVar4;
  int *in_ECX;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined2 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  uVar2 = (**(code **)(*piVar1 + 0x24))();
  piVar1 = (int *)FUN_00803725(uVar2,0,&Framework::ICreature::RTTI_Type_Descriptor,
                               &Framework::Creature::IItem::RTTI_Type_Descriptor,0);
  if (piVar1 != (int *)0x0) {
    puVar3 = (undefined2 *)(**(code **)(*piVar1 + 0x1c))();
    piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
    uStack_18 = (**(code **)(*piVar1 + 8))();
    uStack_14 = 0;
    uStack_10 = *puVar3;
    uStack_c = *(undefined4 *)(in_ECX[1] + 0x18);
    uStack_8 = *(undefined4 *)(in_ECX[1] + 0x1c);
    uStack_4 = param_1;
    (**(code **)(*DAT_00b5af3c + 4))(&uStack_18);
    iVar4 = (**(code **)(*DAT_00b5a6dc + 0x18))(uStack_18,uStack_14);
    if (iVar4 != 0) {
      uVar2 = (**(code **)(*(int *)in_ECX[2] + 8))();
      FUN_004dd240(0x1f,0,*(undefined2 *)(iVar4 + 0x110),0,uVar2);
    }
  }
  return;
}


// ==== FUN_00523c80 @ 0x00523c80 ====

undefined4 FUN_00523c80(void)

{
  return 0;
}


// ==== FUN_00523c90 @ 0x00523c90 ====

float10 FUN_00523c90(float *param_1)

{
  float *pfVar1;
  int *in_ECX;
  
  pfVar1 = (float *)(**(code **)(*in_ECX + 0x28))();
  return SQRT(((float10)param_1[1] - (float10)pfVar1[1]) *
              ((float10)param_1[1] - (float10)pfVar1[1]) +
              ((float10)*param_1 - (float10)*pfVar1) * ((float10)*param_1 - (float10)*pfVar1));
}


// ==== FUN_00523cc0 @ 0x00523cc0 ====

void FUN_00523cc0(byte param_1)

{
  void *in_ECX;
  
  FUN_00523b40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00523ce0 @ 0x00523ce0 ====

undefined4 FUN_00523ce0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00523cf0 @ 0x00523cf0 ====

void FUN_00523cf0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00523d00 @ 0x00523d00 ====

undefined4 FUN_00523d00(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_00523d10 @ 0x00523d10 ====

undefined4 FUN_00523d10(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_00523d30 @ 0x00523d30 ====

void FUN_00523d30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7e4c;
  in_ECX[4] = 0;
  *(undefined1 *)(in_ECX + 5) = 1;
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  *(undefined1 *)((int)in_ECX + 0xd) = 0;
  return;
}


// ==== FUN_00523d50 @ 0x00523d50 ====

void FUN_00523d50(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7e4c;
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b7950;
  }
  puVar1[1] = in_ECX[2];
  FUN_00797a20(puVar1);
  if (in_ECX[4] != 0) {
    (**(code **)(*DAT_00b5aa14 + 0x10))(1,in_ECX[4]);
  }
  *in_ECX = &PTR_FUN_009b78dc;
  return;
}


// ==== FUN_00523da0 @ 0x00523da0 ====

void FUN_00523da0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 uStack_c;
  int iStack_8;
  
  iVar1 = (**(code **)(*in_ECX + 0x68))();
  if (*(char *)(iVar1 + 0x14) == '\x01') {
    if ((char)in_ECX[5] == '\0') {
      puVar2 = operator_new(0x10);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = &PTR_FUN_009b7964;
        puVar2[3] = 0;
        *(undefined1 *)(puVar2 + 2) = 1;
      }
      uVar3 = (**(code **)(*in_ECX + 8))();
      puVar2[1] = uStack_c;
      iStack_8 = CONCAT31(iStack_8._1_3_,1);
      puVar2[2] = iStack_8;
      puVar2[3] = uVar3;
      FUN_00797a20(puVar2);
      *(undefined1 *)(in_ECX + 5) = 1;
      return;
    }
  }
  else if ((char)in_ECX[5] == '\x01') {
    puVar2 = operator_new(0x10);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009b7964;
      puVar2[3] = 0;
      *(undefined1 *)(puVar2 + 2) = 1;
    }
    uVar3 = (**(code **)(*in_ECX + 8))();
    puVar2[1] = uStack_c;
    iStack_8 = (uint)iStack_8._1_3_ << 8;
    puVar2[2] = iStack_8;
    puVar2[3] = uVar3;
    FUN_00797a20(puVar2);
    *(undefined1 *)(in_ECX + 5) = 0;
  }
  return;
}


// ==== FUN_00523e70 @ 0x00523e70 ====

void FUN_00523e70(int *param_1)

{
  char cVar1;
  undefined2 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  void *pvVar7;
  int *in_ECX;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  in_ECX[4] = (int)param_1;
  puVar2 = (undefined2 *)(**(code **)(*param_1 + 0x1c))();
  piVar3 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(*puVar2);
  iVar4 = (**(code **)(*piVar3 + 4))();
  *(undefined1 *)((int)in_ECX + 0xd) = *(undefined1 *)((int)puVar2 + 0x1f);
  *(undefined1 *)(in_ECX + 3) = *(undefined1 *)(puVar2 + 0xf);
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  FUN_00401740(s_No_Name_009b79ec,7);
  uVar5 = (**(code **)(*in_ECX + 8))();
  pcVar6 = (char *)(iVar4 + 0x36);
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar4 + 0x36),(int)pcVar6 - (iVar4 + 0x37));
  pvVar7 = operator_new(0x34);
  if (pvVar7 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_00522170();
  }
  *(undefined4 *)(iVar4 + 4) = 1;
  *(undefined1 *)(iVar4 + 8) = 1;
  *(undefined4 *)(iVar4 + 0xc) = uVar5;
  *(undefined4 *)(iVar4 + 0x10) = 0xffffff;
  *(undefined4 *)(iVar4 + 0x14) = 0x3c;
  FUN_00401660(auStack_20,0,0xffffffff);
  FUN_00797a20(iVar4);
  if (uStack_8 < 0x10) {
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_00523fb0 @ 0x00523fb0 ====

void FUN_00523fb0(byte param_1)

{
  void *in_ECX;
  
  FUN_00523d50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00523fd0 @ 0x00523fd0 ====

void FUN_00523fd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7ed4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00523ff0 @ 0x00523ff0 ====

void FUN_00523ff0(void)

{
  return;
}


// ==== FUN_00524000 @ 0x00524000 ====

void FUN_00524000(void)

{
  return;
}


// ==== FUN_00524010 @ 0x00524010 ====

void FUN_00524010(void)

{
  return;
}


// ==== FUN_00524020 @ 0x00524020 ====

void FUN_00524020(void)

{
  return;
}


// ==== FUN_00524030 @ 0x00524030 ====

void FUN_00524030(void)

{
  return;
}


// ==== FUN_00524050 @ 0x00524050 ====

void FUN_00524050(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined1 auStack_a [2];
  undefined4 auStack_8 [2];
  
  if (*(char *)(in_ECX + 8) == '\0') {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
    uVar2 = (**(code **)(*piVar1 + 8))();
    piVar1 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
    if ((piVar1 != (int *)0x0) &&
       (auStack_8[0] = uVar2, iVar3 = (**(code **)(*piVar1 + 0x30))(auStack_8), iVar3 == 0)) {
      (**(code **)(*piVar1 + 0x54))(auStack_a + -6,*(undefined4 *)(in_ECX + 0xc));
      *(undefined1 *)(in_ECX + 8) = 1;
    }
  }
  return;
}


// ==== FUN_005240c0 @ 0x005240c0 ====

void FUN_005240c0(void)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  undefined4 auStack_8 [2];
  
  if ((*(char *)(in_ECX + 8) != '\0') &&
     (piVar1 = (int *)(**(code **)(*DAT_00b5a6fc + 4))(), piVar1 != (int *)0x0)) {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
    auStack_8[0] = (**(code **)(*piVar2 + 8))();
    piVar2 = (int *)(**(code **)(*piVar1 + 0x30))(auStack_8);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*DAT_00b5a6f8 + 0x10))(1,*(undefined4 *)(*piVar2 + 4));
      (**(code **)(*piVar1 + 0x40))(piVar2);
      *(undefined1 *)(in_ECX + 8) = 0;
    }
  }
  return;
}


// ==== FUN_00524130 @ 0x00524130 ====

void FUN_00524130(void)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puVar2 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x28))();
  uStack_8 = *puVar2;
  iVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x28))();
  uStack_4 = *(undefined4 *)(iVar3 + 4);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
  (**(code **)(*piVar4 + 0x40))(&uStack_8);
  iVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x1c))();
  if (iVar3 != 0) {
    cVar1 = FUN_00511d60();
    if (cVar1 != '\0') {
      FUN_00524050();
      return;
    }
    FUN_005240c0();
  }
  return;
}


// ==== FUN_005241a0 @ 0x005241a0 ====

void FUN_005241a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7f08;
  FUN_005240c0();
  *in_ECX = &PTR_FUN_009b7ed4;
  return;
}


// ==== FUN_005241c0 @ 0x005241c0 ====

void FUN_005241c0(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *in_ECX;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  *in_ECX = &PTR_FUN_009b7f08;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[1] = param_1;
  piVar2 = (int *)(**(code **)(*param_1 + 0x14))();
  uVar3 = (**(code **)(*piVar2 + 8))();
  puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x28))();
  uStack_10 = *puVar4;
  uStack_c = puVar4[1];
  uStack_8 = uStack_10;
  uStack_4 = uStack_c;
  piVar2 = (int *)(**(code **)(*DAT_00b5a6f8 + 0xc))(1,0);
  in_ECX[3] = piVar2;
  piVar2 = (int *)(**(code **)(*piVar2 + 0xc))();
  (**(code **)(*piVar2 + 0x40))(&uStack_10);
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[3] + 0xc))();
  (**(code **)(*piVar2 + 0x4c))(0);
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[3] + 0xc))();
  (**(code **)(*piVar2 + 0x28))(0);
  (**(code **)(*(int *)in_ECX[3] + 0x24))(0);
  FUN_00524050();
  piVar2 = (int *)(**(code **)(*param_1 + 0x14))();
  iVar5 = (**(code **)(*piVar2 + 0x24))();
  if ((iVar5 != 0) && (*(int **)(iVar5 + 0x4c) != (int *)0x0)) {
    piVar2 = (int *)(**(code **)(**(int **)(iVar5 + 0x4c) + 0x18))();
    if (piVar2 != (int *)0x0) {
      iVar5 = (**(code **)(*piVar2 + 0xc))();
      if (iVar5 == 8) {
        (**(code **)(*piVar2 + 8))(0);
        puVar4 = (undefined4 *)(**(code **)(*piVar2 + 0x10))();
        uVar1 = *puVar4;
        puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1,0);
        *puVar4 = 7;
        puVar4[1] = uVar1;
        puVar4[2] = uVar3;
        (**(code **)(*DAT_00b5a804 + 0xc))(uVar3,puVar4);
        (**(code **)(*DAT_00b5a70c + 0x10))(1,puVar4);
      }
    }
  }
  return;
}


// ==== FUN_00524300 @ 0x00524300 ====

void FUN_00524300(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7f08;
  FUN_005240c0();
  *in_ECX = &PTR_FUN_009b7ed4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00524330 @ 0x00524330 ====

void FUN_00524330(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00524335. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc) + 8))();
  return;
}


// ==== FUN_00524340 @ 0x00524340 ====

void FUN_00524340(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00524345. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
  return;
}


// ==== FUN_00524350 @ 0x00524350 ====

void FUN_00524350(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00524355. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))();
  return;
}


// ==== FUN_00524360 @ 0x00524360 ====

void FUN_00524360(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00524365. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x14))();
  return;
}


// ==== FUN_00524370 @ 0x00524370 ====

void FUN_00524370(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00524375. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x1c))();
  return;
}


// ==== FUN_00524380 @ 0x00524380 ====

void FUN_00524380(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00524385. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x20))();
  return;
}


// ==== FUN_00524390 @ 0x00524390 ====

void FUN_00524390(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00524395. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x28))();
  return;
}


// ==== FUN_005243a0 @ 0x005243a0 ====

void FUN_005243a0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005243a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x2c))();
  return;
}


// ==== FUN_005243b0 @ 0x005243b0 ====

void FUN_005243b0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005243b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x30))();
  return;
}


// ==== FUN_005243c0 @ 0x005243c0 ====

void FUN_005243c0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005243c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x34))();
  return;
}


// ==== FUN_005243d0 @ 0x005243d0 ====

void FUN_005243d0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005243d5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x40))();
  return;
}


// ==== FUN_005243e0 @ 0x005243e0 ====

void FUN_005243e0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  iVar2 = (**(code **)(*piVar1 + 8))();
  iVar3 = (**(code **)(*param_1 + 0x10))();
  if (iVar3 == iVar2) {
    in_ECX[0x11] = 3;
    *(undefined1 *)(in_ECX + 1) = 0;
    in_ECX[2] = 0;
  }
  return;
}


// ==== FUN_00524420 @ 0x00524420 ====

void FUN_00524420(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  iVar2 = (**(code **)(*piVar1 + 8))();
  iVar3 = (**(code **)(*param_1 + 0x10))();
  if (iVar3 == iVar2) {
    in_ECX[0x11] = 1;
    *(char *)(in_ECX + 1) = (char)param_1[9];
    in_ECX[2] = param_1[6];
  }
  return;
}


// ==== FUN_005244b0 @ 0x005244b0 ====

float10 FUN_005244b0(void)

{
  return (float10)DAT_0099cdc8;
}


// ==== FUN_00524500 @ 0x00524500 ====

void FUN_00524500(undefined4 *param_1)

{
  char cVar1;
  short sVar2;
  int *piVar3;
  undefined4 uVar4;
  void *pvVar5;
  int iVar6;
  int in_ECX;
  undefined1 auStack_12 [6];
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5ac2c + 8))();
  cVar1 = (**(code **)(*piVar3 + 4))();
  if (cVar1 != '\0') {
    uStack_4 = 0;
    uStack_c = *param_1;
    uStack_8 = param_1[1];
    iVar6 = *DAT_00b5af40;
    uVar4 = FUN_004ef0e0(auStack_12);
    sVar2 = (**(code **)(iVar6 + 4))(uVar4);
    if (sVar2 != *(short *)(in_ECX + 0x40)) {
      *(short *)(in_ECX + 0x40) = sVar2;
      pvVar5 = operator_new(0x400);
      *(undefined4 **)((int)pvVar5 + 8) = param_1;
      *(undefined4 *)((int)pvVar5 + 0xc) = 0x50d0001;
      *(undefined2 *)((int)pvVar5 + 6) = 0x14;
      iVar6 = FUN_004244d0();
      *(undefined2 *)(iVar6 + 0x10) = *(undefined2 *)(in_ECX + 0x40);
      FUN_004d8570(iVar6);
    }
  }
  return;
}


// ==== FUN_005245b0 @ 0x005245b0 ====

void FUN_005245b0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  iVar2 = (**(code **)(*piVar1 + 8))();
  iVar3 = (**(code **)(*param_1 + 0x10))();
  if (iVar3 == iVar2) {
    if (*(char *)((int)param_1 + 0x13) == '\x01') {
      in_ECX[0x11] = 0;
      *(undefined1 *)(in_ECX + 1) = 0;
      in_ECX[2] = 0;
      return;
    }
    if (*(char *)((int)param_1 + 0x13) == '\x02') {
      in_ECX[0x11] = 1;
      *(bool *)(in_ECX + 1) = *(char *)((int)param_1 + 0x15) == '\x01';
      in_ECX[2] = (int)((float)*(ushort *)((int)param_1 + 0x16) * DAT_009b3508);
      return;
    }
    in_ECX[0x11] = 2;
    *(undefined1 *)(in_ECX + 1) = 0;
    in_ECX[2] = 0;
  }
  return;
}


// ==== FUN_00524640 @ 0x00524640 ====

void FUN_00524640(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  iVar2 = (**(code **)(*piVar1 + 8))();
  iVar3 = (**(code **)(*param_1 + 0x10))();
  if (iVar3 == iVar2) {
    iVar2 = param_1[1];
    in_ECX[0xe] = *(int *)(iVar2 + 0x14);
    in_ECX[0xf] = *(int *)(iVar2 + 0x18);
    in_ECX[0xc] = *(int *)(iVar2 + 0x1c);
    in_ECX[0xd] = *(int *)(iVar2 + 0x20);
    in_ECX[10] = *(int *)(iVar2 + 0x24);
    in_ECX[0xb] = *(int *)(iVar2 + 0x28);
  }
  return;
}


// ==== FUN_00524690 @ 0x00524690 ====

void FUN_00524690(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  iVar2 = (**(code **)(*piVar1 + 8))();
  iVar3 = (**(code **)(*param_1 + 0x10))();
  if (iVar3 == iVar2) {
    (**(code **)(*in_ECX + 0x1c))();
    iVar2 = FUN_00511d20();
    if (*(int *)(iVar2 + 8) == param_1[2]) {
      piVar1 = (int *)(**(code **)(*in_ECX + 0x10))();
      iVar2 = (**(code **)(*piVar1 + 0x18))();
      if (iVar2 != 0) {
        piVar1 = (int *)(**(code **)(*in_ECX + 0x10))();
        piVar1 = (int *)(**(code **)(*piVar1 + 0x18))();
        iVar2 = (**(code **)(*piVar1 + 4))();
        if (iVar2 == 5) {
          return;
        }
      }
      iVar2 = param_1[3];
      if ((iVar2 != 0) && ((iVar2 == 1 || (iVar2 == 2)))) {
        in_ECX[0x11] = 0;
        *(undefined1 *)(in_ECX + 1) = 0;
        in_ECX[2] = 0;
      }
    }
  }
  return;
}


// ==== FUN_00524720 @ 0x00524720 ====

void FUN_00524720(undefined4 param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  undefined1 auStack_38 [16];
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  undefined1 uStack_14;
  int iStack_10;
  int iStack_c;
  undefined1 uStack_8;
  int iStack_4;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5ac2c + 8))();
  cVar1 = (**(code **)(*piVar2 + 4))();
  if (cVar1 != '\0') {
    piVar2 = (int *)(**(code **)(*(int *)in_ECX[3] + 0x14))();
    uStack_14 = (**(code **)(*piVar2 + 0x30))();
    iStack_28 = in_ECX[0xe];
    iStack_24 = in_ECX[0xf];
    iStack_4 = in_ECX[2];
    iStack_20 = in_ECX[0xc];
    iStack_1c = in_ECX[0xd];
    uStack_8 = (undefined1)in_ECX[1];
    iStack_18 = param_2;
    iStack_10 = iStack_20;
    iStack_c = iStack_1c;
    FUN_00507870(&iStack_28,auStack_38);
    pvVar3 = operator_new(0x400);
    *(int *)((int)pvVar3 + 8) = param_2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x50d0000;
    *(undefined2 *)((int)pvVar3 + 6) = 0x30;
    iVar4 = FUN_004244d0();
    piVar2 = (int *)(**(code **)(*in_ECX + 0x14))();
    uVar5 = (**(code **)(*piVar2 + 8))();
    *(undefined4 *)(iVar4 + 0x10) = uVar5;
    FUN_00403e60(iVar4 + 0x14,auStack_38,0x10);
    FUN_004d8570(iVar4);
    in_ECX[7] = in_ECX[0xc];
    in_ECX[8] = in_ECX[0xd];
    in_ECX[4] = param_2;
    in_ECX[5] = in_ECX[0xe];
    in_ECX[6] = in_ECX[0xf];
    in_ECX[9] = in_ECX[2];
  }
  return;
}


// ==== FUN_00524830 @ 0x00524830 ====

void FUN_00524830(int *param_1,int *param_2,int param_3)

{
  char cVar1;
  undefined1 uVar2;
  int *piVar3;
  void *pvVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int *in_ECX;
  float10 fVar8;
  undefined1 auStack_1e [6];
  int iStack_18;
  undefined4 uStack_14;
  undefined2 uStack_10;
  undefined1 uStack_e;
  undefined1 uStack_d;
  int iStack_c;
  int iStack_8;
  float fStack_4;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5ac2c + 8))();
  cVar1 = (**(code **)(*piVar3 + 4))();
  if (cVar1 != '\0') {
    pvVar4 = operator_new(0x400);
    *(int *)((int)pvVar4 + 8) = param_3;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x50d0000;
    *(undefined2 *)((int)pvVar4 + 6) = 0x30;
    iVar5 = FUN_004244d0();
    piVar3 = (int *)(**(code **)(*in_ECX + 0x14))();
    uVar6 = (**(code **)(*piVar3 + 8))();
    *(undefined4 *)(iVar5 + 0x10) = uVar6;
    piVar3 = (int *)(**(code **)(*(int *)in_ECX[3] + 0x14))();
    uVar2 = (**(code **)(*piVar3 + 0x30))();
    FUN_00797a50(&iStack_18,0,0xc);
    iStack_c = *param_1;
    iStack_8 = param_1[1];
    uStack_d = 1;
    iStack_18 = param_3;
    uStack_e = uVar2;
    fVar8 = (float10)FUN_0040d5f0(param_2);
    fStack_4 = (float)fVar8;
    puVar7 = (undefined4 *)FUN_004ef0e0(auStack_1e);
    uStack_14 = *puVar7;
    uStack_10 = *(undefined2 *)(puVar7 + 1);
    FUN_00403e60(iVar5 + 0x14,&iStack_18,0xc);
    FUN_004d8570(iVar5);
    in_ECX[4] = param_3;
    in_ECX[7] = *param_2;
    in_ECX[8] = param_2[1];
    in_ECX[5] = *param_1;
    in_ECX[6] = param_1[1];
    in_ECX[9] = 0;
  }
  return;
}


// ==== FUN_00524950 @ 0x00524950 ====

void FUN_00524950(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int in_ECX;
  float fVar4;
  float fVar5;
  undefined1 *puVar6;
  undefined1 auStack_62 [2];
  undefined1 auStack_60 [6];
  undefined1 auStack_5a [2];
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 auStack_4c [2];
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  (**(code **)(**(int **)(in_ECX + 0xc) + 4))(param_1);
  if (*(char *)(param_1 + 0xb) == '\x01') {
    FUN_004f5730(&uStack_44);
    uStack_54 = uStack_44;
    uStack_50 = uStack_40;
    FUN_0040d600(auStack_4c,uStack_3c);
    *(undefined4 *)(in_ECX + 0x44) = 0;
    *(undefined1 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    *(undefined4 *)(in_ECX + 0x10) = uVar3;
    puVar6 = auStack_5a;
  }
  else {
    if (*(char *)(param_1 + 0xb) == '\x02') {
      FUN_00506ea0(param_1,&uStack_2c);
      *(undefined4 *)(in_ECX + 0x44) = 1;
      *(undefined1 *)(in_ECX + 4) = (undefined1)uStack_c;
      *(undefined4 *)(in_ECX + 8) = uStack_8;
      uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      *(undefined4 *)(in_ECX + 0x10) = uVar3;
      iVar1 = *DAT_00b5af40;
      uStack_30 = 0;
      uStack_38 = uStack_2c;
      uStack_34 = uStack_28;
      uVar3 = FUN_004ef0e0(auStack_60);
      uVar2 = (**(code **)(iVar1 + 4))(uVar3);
      *(undefined2 *)(in_ECX + 0x40) = uVar2;
      *(undefined4 *)(in_ECX + 0x24) = uStack_c;
      fVar4 = *(float *)(in_ECX + 8);
      *(undefined4 *)(in_ECX + 0x14) = uStack_30;
      *(undefined4 *)(in_ECX + 0x18) = uStack_2c;
      *(undefined4 *)(in_ECX + 0x1c) = uStack_28;
      *(undefined4 *)(in_ECX + 0x20) = uStack_24;
      fVar5 = fVar4 * *(float *)(in_ECX + 0x1c);
      uStack_58 = uStack_30;
      uStack_54 = uStack_2c;
      uStack_50 = uStack_28;
      auStack_4c[0] = uStack_24;
      goto LAB_00524b44;
    }
    *(undefined4 *)(in_ECX + 0x44) = 2;
    *(undefined1 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    FUN_004f5730(&uStack_44);
    uStack_54 = uStack_44;
    uStack_50 = uStack_40;
    FUN_0040d600(auStack_4c,uStack_3c);
    puVar6 = auStack_62 + -4;
  }
  iVar1 = *DAT_00b5af40;
  uStack_30 = 0;
  uStack_38 = uStack_44;
  uStack_34 = uStack_40;
  uVar3 = FUN_004ef0e0(puVar6);
  uVar2 = (**(code **)(iVar1 + 4))(uVar3);
  *(undefined2 *)(in_ECX + 0x40) = uVar2;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  fVar4 = *(float *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0x20) = auStack_4c[0];
  *(undefined4 *)(in_ECX + 0x1c) = uStack_50;
  *(undefined4 *)(in_ECX + 0x18) = uStack_54;
  *(undefined4 *)(in_ECX + 0x14) = uStack_58;
  fVar5 = *(float *)(in_ECX + 0x1c) * fVar4;
LAB_00524b44:
  *(float *)(in_ECX + 0x28) = fVar5;
  *(undefined4 *)(in_ECX + 0x34) = auStack_4c[0];
  *(float *)(in_ECX + 0x2c) = *(float *)(in_ECX + 0x20) * fVar4;
  *(undefined4 *)(in_ECX + 0x30) = uStack_50;
  *(undefined4 *)(in_ECX + 0x38) = uStack_58;
  *(undefined4 *)(in_ECX + 0x3c) = uStack_54;
  return;
}


// ==== FUN_00524b80 @ 0x00524b80 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00524b80(float *param_1,float *param_2,float param_3)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  if (uVar1 < *(uint *)(in_ECX + 0x10)) {
    fVar6 = 0.0;
  }
  else {
    iVar2 = uVar1 - *(uint *)(in_ECX + 0x10);
    fVar6 = (float)iVar2;
    if (iVar2 < 0) {
      fVar6 = fVar6 + _DAT_0099d104;
    }
    fVar6 = fVar6 * DAT_0099d0ec;
  }
  fVar3 = *(float *)(in_ECX + 0x4c) - fVar6;
  if (fVar3 < *(float *)(in_ECX + 0x48)) {
    fVar3 = *(float *)(in_ECX + 0x48);
  }
  fVar4 = *(float *)(in_ECX + 0x54) - fVar6;
  if (fVar4 < *(float *)(in_ECX + 0x50)) {
    fVar4 = *(float *)(in_ECX + 0x50);
  }
  fVar7 = fVar6;
  if (*(float *)(in_ECX + 0x58) <= fVar6) {
    fVar7 = *(float *)(in_ECX + 0x58);
  }
  fVar5 = *param_1 -
          (*(float *)(in_ECX + 0x14) + *(float *)(in_ECX + 0x1c) * *(float *)(in_ECX + 0x24) * fVar6
          );
  fVar6 = param_1[1] -
          (*(float *)(in_ECX + 0x18) + *(float *)(in_ECX + 0x20) * *(float *)(in_ECX + 0x24) * fVar6
          );
  if (((SQRT(fVar5 * fVar5 + fVar6 * fVar6) <= fVar3) &&
      (ABS(*(float *)(in_ECX + 0x24) - param_3) <= fVar4)) &&
     (fVar7 <= *(float *)(in_ECX + 0x20) * param_2[1] + *param_2 * *(float *)(in_ECX + 0x1c))) {
    return 0;
  }
  return 1;
}


// ==== FUN_00524cd0 @ 0x00524cd0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00524cd0(float *param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  float fVar3;
  float fVar4;
  float fVar5;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  if (uVar1 < *(uint *)(in_ECX + 0x10)) {
    fVar5 = 0.0;
  }
  else {
    iVar2 = uVar1 - *(uint *)(in_ECX + 0x10);
    fVar5 = (float)iVar2;
    if (iVar2 < 0) {
      fVar5 = fVar5 + _DAT_0099d104;
    }
    fVar5 = fVar5 * DAT_0099d0ec;
  }
  fVar3 = *(float *)(in_ECX + 0x4c) - fVar5;
  if (fVar3 < *(float *)(in_ECX + 0x48)) {
    fVar3 = *(float *)(in_ECX + 0x48);
  }
  fVar4 = *param_1 -
          (*(float *)(in_ECX + 0x14) + *(float *)(in_ECX + 0x1c) * *(float *)(in_ECX + 0x24) * fVar5
          );
  fVar5 = param_1[1] -
          (*(float *)(in_ECX + 0x18) + *(float *)(in_ECX + 0x20) * *(float *)(in_ECX + 0x24) * fVar5
          );
  if (fVar3 < SQRT(fVar4 * fVar4 + fVar5 * fVar5)) {
    return 1;
  }
  return 0;
}


// ==== FUN_00524db0 @ 0x00524db0 ====

void FUN_00524db0(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x5c) < 2) {
    *(uint *)(in_ECX + 0x5c) = *(uint *)(in_ECX + 0x5c) + 1;
    return;
  }
  if (*(int *)(in_ECX + 0x44) == 1) {
    cVar1 = FUN_00524cd0(in_ECX + 0x38);
    if (cVar1 != '\0') {
      uVar2 = (**(code **)(*DAT_00b5ad54 + 0x68))();
      FUN_00524720(uVar2,*(undefined4 *)(param_1 + 0xc));
      FUN_00524500(in_ECX + 0x38,*(undefined4 *)(param_1 + 0xc));
      return;
    }
  }
  else if (*(int *)(in_ECX + 0x44) == 0) {
    cVar1 = FUN_00524b80(in_ECX + 0x38,in_ECX + 0x30,0);
    if (cVar1 != '\0') {
      FUN_00524830(in_ECX + 0x38,in_ECX + 0x30,*(undefined4 *)(param_1 + 0xc));
    }
  }
  FUN_00524500(in_ECX + 0x38,*(undefined4 *)(param_1 + 0xc));
  return;
}


// ==== FUN_00524e60 @ 0x00524e60 ====

void FUN_00524e60(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *unaff_ESI;
  undefined1 local_38 [4];
  undefined1 local_34;
  undefined4 uStack_30;
  uint uStack_2c;
  void *local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  undefined1 local_18;
  uint uStack_10;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar2 = DAT_0099d0f8;
  uVar1 = DAT_0099d0b4;
  in_ECX[0x12] = DAT_0099d0b4;
  in_ECX[0x14] = uVar1;
  in_ECX[0x15] = DAT_0099d080;
  uVar1 = DAT_009b2dbc;
  *in_ECX = &PTR_FUN_009b7fb4;
  in_ECX[3] = param_1;
  in_ECX[0x11] = 0;
  in_ECX[0x13] = uVar2;
  in_ECX[0x16] = uVar1;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_sync__pos_min___pos_max___speed_m_009b7f3c,0x36);
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = 0;
  FUN_00401740(&DAT_009b7f74,4);
  (**(code **)(*DAT_00b5a6c8 + 8))(local_38,5,local_1c);
  if (0xf < uStack_2c) {
    _free(unaff_ESI);
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  if (uStack_10 < 0x10) {
    in_ECX[0x17] = 0;
    return;
  }
  _free(local_24);
  return;
}


// ==== __break @ 0x00524f4e ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00524f50 @ 0x00524f50 ====

void FUN_00524f50(void)

{
  undefined4 *in_ECX;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009b7fb4;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(&DAT_009b7f7c,4);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_1c);
  if (local_8 < 0x10) {
    *in_ECX = &PTR_FUN_009b7814;
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_00524fd0 @ 0x00524fd0 ====

undefined4 FUN_00524fd0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  int in_ECX;
  float10 fVar3;
  float10 extraout_ST0;
  undefined1 local_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),&DAT_009b7f84,4);
  if (iVar1 != 0) {
    return 0;
  }
  uVar2 = FUN_00459160(local_1c,0);
  fVar3 = (float10)thunk_FUN_00796ec0(uVar2);
  *(float *)(in_ECX + 0x48) = (float)fVar3;
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return extraout_EAX;
  }
  uVar2 = FUN_00459160(local_1c,1);
  fVar3 = (float10)thunk_FUN_00796ec0(uVar2);
  *(float *)(in_ECX + 0x4c) = (float)fVar3;
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return extraout_EAX_00;
  }
  uVar2 = FUN_00459160(local_1c,2);
  fVar3 = (float10)thunk_FUN_00796ec0(uVar2);
  *(float *)(in_ECX + 0x50) = (float)fVar3;
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return extraout_EAX_01;
  }
  uVar2 = FUN_00459160(local_1c,3);
  fVar3 = (float10)thunk_FUN_00796ec0(uVar2);
  *(float *)(in_ECX + 0x54) = (float)fVar3;
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return extraout_EAX_02;
  }
  uVar2 = FUN_00459160(local_1c,4);
  thunk_FUN_00796ec0(uVar2);
  *(float *)(in_ECX + 0x58) = (float)extraout_ST0;
  if (uStack_4 < 0x10) {
    return 1;
  }
  _free(pvStack_18);
  return extraout_EAX_03;
}


// ==== FUN_00525100 @ 0x00525100 ====

undefined1 FUN_00525100(int *param_1)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  
  iVar3 = (**(code **)(*param_1 + 4))();
  if (iVar3 == 0x20010022) {
    FUN_00524690(param_1);
  }
  uVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x24))(param_1);
  uVar4 = (**(code **)(*param_1 + 4))();
  if (uVar4 < 0x20010022) {
    if (uVar4 == 0x20010021) {
      FUN_00524640(param_1);
      return uVar1;
    }
    if (uVar4 == 0x40001) {
      FUN_00524db0(param_1);
      return uVar1;
    }
    if (uVar4 == 0x70004) {
      cVar2 = FUN_00524fd0(param_1);
      if (cVar2 == '\x01') {
        return 1;
      }
    }
  }
  else if (uVar4 == 0x30060003) {
    FUN_00524420(param_1);
  }
  else if (uVar4 == 0x50070002) {
    FUN_005245b0(param_1);
    return uVar1;
  }
  return uVar1;
}


// ==== FUN_005251b0 @ 0x005251b0 ====

void FUN_005251b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00524f50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005251d0 @ 0x005251d0 ====

undefined4 FUN_005251d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_005251e0 @ 0x005251e0 ====

void FUN_005251e0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_005251f0 @ 0x005251f0 ====

undefined4 FUN_005251f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00525200 @ 0x00525200 ====

undefined4 FUN_00525200(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00525210 @ 0x00525210 ====

uint FUN_00525210(uint param_1,char param_2,char param_3,undefined4 param_4,undefined1 param_5)

{
  uint uVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  char cStack00000028;
  char cStack00000029;
  short sStack0000002a;
  short sStack0000002c;
  short sStack0000002e;
  short sStack00000030;
  short sStack00000032;
  short sStack00000034;
  short sStack00000036;
  short sStack00000038;
  short sStack0000003c;
  undefined1 uStack00000040;
  char cStack00000054;
  char cStack00000055;
  short sStack00000056;
  short sStack00000058;
  short sStack0000005a;
  short sStack0000005c;
  short sStack0000005e;
  short sStack00000060;
  short sStack00000062;
  short sStack00000064;
  
  uVar1 = 0;
  if (*(byte *)(in_ECX + 0x39) != param_1) {
    return 4;
  }
  if ((char)((uint)_sStack00000038 >> 0x10) != (char)((uint)_sStack00000064 >> 0x10)) {
    return 3;
  }
  if (((short)param_4 != sStack0000003c) ||
     ((short)((uint)param_4 >> 0x10) != (short)((uint)_sStack0000003c >> 0x10))) {
    uVar1 = 2;
  }
  iVar2 = 0;
  iVar3 = 10;
  do {
    if (*(short *)(&param_5 + iVar2) != *(short *)(&uStack00000040 + iVar2)) {
      uVar1 = uVar1 | 1;
    }
    iVar2 = iVar2 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (cStack00000028 != cStack00000054) {
    uVar1 = uVar1 | 2;
  }
  if (cStack00000029 != cStack00000055) {
    uVar1 = uVar1 | 2;
  }
  if ((((sStack0000002a != sStack00000056) || (sStack0000002c != sStack00000058)) ||
      (sStack0000002e != sStack0000005a)) || (sStack00000030 != sStack0000005c)) {
    uVar1 = uVar1 | 2;
  }
  if (((sStack00000032 != sStack0000005e) || (sStack00000034 != sStack00000060)) ||
     ((sStack00000036 != sStack00000062 || (sStack00000038 != sStack00000064)))) {
    uVar1 = uVar1 | 2;
  }
  if (param_2 != param_3) {
    uVar1 = uVar1 | 2;
  }
  return uVar1;
}


// ==== FUN_00525320 @ 0x00525320 ====

void FUN_00525320(char param_1)

{
  int in_ECX;
  
  if (param_1 == '\0') {
    FUN_004dd240(0x24,0,1,4,*(undefined4 *)(in_ECX + 8));
  }
  else if (param_1 == '\x01') {
    FUN_004dd750(0x24,0,1,1,2,*(undefined4 *)(in_ECX + 8));
    *(undefined1 *)(in_ECX + 0xc0) = 1;
    return;
  }
  *(char *)(in_ECX + 0xc0) = param_1;
  return;
}


// ==== FUN_00525380 @ 0x00525380 ====

bool FUN_00525380(void)

{
  int in_ECX;
  
  return *(char *)(in_ECX + 0x39) != '\0';
}


// ==== FUN_00525390 @ 0x00525390 ====

void FUN_00525390(char param_1)

{
  if (param_1 == '\0') {
    (**(code **)(*DAT_00b5ad1c + 0xc))();
    return;
  }
  (**(code **)(*DAT_00b5ad1c + 0x10))();
  return;
}


// ==== FUN_005253b0 @ 0x005253b0 ====

bool FUN_005253b0(void)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5ac1c + 0x18))();
  return cVar1 != '\0';
}


// ==== FUN_005253d0 @ 0x005253d0 ====

void FUN_005253d0(char param_1,int *param_2,int *param_3)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  ushort uVar4;
  int iVar5;
  int in_ECX;
  
  *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x20) + *param_3;
  if ((*param_2 != 5) && (*param_2 != 10)) {
    iVar3 = *(int *)(in_ECX + 8);
    iVar5 = (**(code **)(*DAT_00b5a97c + 0xc))();
    if ((iVar5 == iVar3) && (199 < *(uint *)(in_ECX + 0x20))) {
      cVar1 = *(char *)(in_ECX + 100);
      uVar4 = 0;
      if (((cVar1 == '\x01') || (cVar1 == '\x04')) || (cVar1 == '\x02')) {
        uVar4 = 1;
      }
      uVar2 = *(ushort *)(in_ECX + 0x66);
      if (1 < uVar2) {
        uVar4 = uVar2;
      }
      if (param_1 == '\0') {
        FUN_004dd320(0x10,uVar4,*param_2,*(undefined4 *)(in_ECX + 0x14),iVar3,
                     *(undefined4 *)(in_ECX + 0x18));
        FUN_004dd320(0x11,1 < uVar2,*param_2,0,*(undefined4 *)(in_ECX + 8),
                     *(undefined4 *)(in_ECX + 0x18));
      }
      else {
        FUN_004dd320(0x10,uVar4,*param_2,*(undefined4 *)(in_ECX + 0x14),iVar3,
                     *(undefined4 *)(in_ECX + 0x18));
      }
      *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
      if (8 < *(uint *)(in_ECX + 0x18)) {
        *(undefined4 *)(in_ECX + 0x18) = 0;
      }
      *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
      *(undefined4 *)(in_ECX + 0x20) = 0;
      if (1 < *(uint *)(in_ECX + 0x14)) {
        *(undefined4 *)(in_ECX + 0x14) = 0;
      }
    }
  }
  return;
}


// ==== FUN_00525510 @ 0x00525510 ====

undefined1 FUN_00525510(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = **(int **)(in_ECX + 0xc);
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar2 = (**(code **)(iVar2 + 0x1c))(uVar1);
  return *(undefined1 *)(iVar2 + 0x46);
}


// ==== FUN_00525540 @ 0x00525540 ====

void FUN_00525540(undefined4 param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 uVar4;
  
  cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
  if (cVar1 == '\0') {
    in_ECX[7] = in_ECX[7] + *param_3;
    FUN_005253d0(param_1,param_2,param_3);
    uVar2 = 0x226;
    if ((char)param_1 == '\0') {
      uVar2 = 0x1c2;
    }
    if (uVar2 <= (uint)in_ECX[7]) {
      if ((char)param_1 == '\0') {
        uVar3 = (**(code **)(*in_ECX + 0x38))(*param_2,in_ECX[4],in_ECX[2]);
        uVar4 = 2;
      }
      else {
        uVar3 = (**(code **)(*in_ECX + 0x38))(*param_2,in_ECX[4],in_ECX[2]);
        uVar4 = 1;
      }
      FUN_004dd240(uVar4,uVar3);
      in_ECX[4] = in_ECX[4] + 1;
      in_ECX[7] = 0;
      if (1 < (uint)in_ECX[4]) {
        in_ECX[4] = 0;
      }
    }
  }
  return;
}


// ==== FUN_005255e0 @ 0x005255e0 ====

void FUN_005255e0(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = **(int **)(in_ECX + 0xc);
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))
                    (*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0x28));
  iVar2 = (**(code **)(iVar2 + 0x1c))(uVar1);
  FUN_004dd320(0,3,0,*(undefined1 *)(iVar2 + 0x44));
  *(int *)(in_ECX + 0x28) = *(int *)(in_ECX + 0x28) + 1;
  if (1 < *(uint *)(in_ECX + 0x28)) {
    *(undefined4 *)(in_ECX + 0x28) = 0;
  }
  return;
}


// ==== FUN_00525630 @ 0x00525630 ====

void FUN_00525630(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = **(int **)(in_ECX + 0xc);
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))(*(undefined4 *)(in_ECX + 8));
  iVar2 = (**(code **)(iVar2 + 0x1c))(uVar1);
  FUN_004dd240(0,4,0,*(undefined1 *)(iVar2 + 0x44));
  return;
}


// ==== FUN_005256e0 @ 0x005256e0 ====

char FUN_005256e0(undefined4 param_1,char param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  char cVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(param_1);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 4))();
    bVar1 = *(byte *)(iVar3 + 0x108);
    if (bVar1 != 0) {
      if ((bVar1 == 0) || (3 < bVar1)) {
        if ((bVar1 < 4) || (cVar4 = '\x02', 6 < bVar1)) {
          cVar4 = '\x03';
        }
      }
      else {
        cVar4 = '\x01';
      }
      if (param_2 != '\0') {
        cVar4 = cVar4 + '\n';
      }
      if (*(char *)(in_ECX + 0x68) == '\0') {
        uVar7 = 3000;
        uVar6 = 1;
        uVar5 = 0x7000a;
        FUN_00511d10(0x7000a,1,3000);
        FUN_00512cd0();
        FUN_005127a0(uVar5,uVar6,uVar7);
        *(undefined1 *)(in_ECX + 0x68) = 1;
      }
      return cVar4;
    }
  }
  return '\0';
}


// ==== FUN_00525770 @ 0x00525770 ====

undefined4 FUN_00525770(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined4 *puVar6;
  undefined4 auStack_a4 [40];
  
  iVar3 = **(int **)(in_ECX + 0xc);
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar3 = (**(code **)(iVar3 + 0x1c))(uVar2);
  sVar1 = *(short *)(iVar3 + 0x1a + param_1 * 2);
  piVar4 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(sVar1);
  if ((sVar1 == 0) || (piVar4 == (int *)0x0)) {
    return 0;
  }
  puVar5 = (undefined4 *)(**(code **)(*piVar4 + 4))();
  puVar6 = auStack_a4 + -3;
  for (iVar3 = 0x27; puVar5 = puVar5 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar5;
    puVar6 = puVar6 + 1;
  }
  return auStack_a4[2];
}


// ==== FUN_005257f0 @ 0x005257f0 ====

char FUN_005257f0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  if ((short)param_1 == 0) {
    return '\0';
  }
  piVar1 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(param_1);
  if (piVar1 == (int *)0x0) {
    return '\0';
  }
  iVar2 = (**(code **)(*piVar1 + 4))();
  if (*(char *)(iVar2 + 0xa5) == '\0') {
    return '\0';
  }
  iVar2 = (**(code **)(*piVar1 + 4))();
  if (*(char *)(iVar2 + 0xa6) == '\0') {
    return '\x01';
  }
  iVar2 = (**(code **)(*piVar1 + 4))();
  if (*(char *)(iVar2 + 0xa7) == '\0') {
    return '\x02';
  }
  iVar2 = (**(code **)(*piVar1 + 4))();
  return (*(char *)(iVar2 + 0xa8) != '\0') + '\x03';
}


// ==== FUN_00525880 @ 0x00525880 ====

void FUN_00525880(void)

{
  FUN_00525770(3);
  return;
}


// ==== FUN_00525890 @ 0x00525890 ====

void FUN_00525890(void)

{
  FUN_00525770(6);
  return;
}


// ==== FUN_005258a0 @ 0x005258a0 ====

void FUN_005258a0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  float10 fVar4;
  
  iVar2 = (**(code **)(*DAT_00b5a97c + 0xc))();
  if (iVar2 == *(int *)(in_ECX + 8)) {
    fVar4 = (float10)FUN_0040d0a0(0x3f800000,0x40400000);
    piVar1 = DAT_00b5a6ac;
    if ((int)ROUND(fVar4) == 1) {
      fVar4 = (float10)FUN_0040d0a0(0x3f800000,0x40400000,*(undefined4 *)(in_ECX + 8));
      iVar2 = **(int **)(in_ECX + 0xc);
      uVar3 = (**(code **)(*piVar1 + 0x20))((int)ROUND(fVar4));
      iVar2 = (**(code **)(iVar2 + 0x1c))(uVar3);
      FUN_004dd240(0,5,*(undefined1 *)(iVar2 + 0x44));
    }
    iVar2 = FUN_00525770(1);
    if (iVar2 == 0) {
      iVar2 = FUN_00525770(0);
    }
    if (((iVar2 != 0xe) && (iVar2 != 0xf)) && (iVar2 != 0x2e)) {
      fVar4 = (float10)FUN_0040d0a0(0x3f800000,0x40400000,0,*(undefined4 *)(in_ECX + 0x24));
      FUN_004dd320(6,iVar2,1,(int)ROUND(fVar4));
      *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
      if (1 < *(uint *)(in_ECX + 0x24)) {
        *(undefined4 *)(in_ECX + 0x24) = 0;
      }
    }
  }
  return;
}


// ==== FUN_005259e0 @ 0x005259e0 ====

void FUN_005259e0(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = *(undefined4 *)(in_ECX + 8);
  uVar2 = 0;
  uVar1 = FUN_00525770(0);
  FUN_004dd240(3,param_1,uVar1,uVar2,uVar3);
  if ((param_1 < 3) || (0xb < param_1)) {
    FUN_004dd320(0x15,2,0,1,*(undefined4 *)(in_ECX + 8),0);
    return;
  }
  FUN_004dd320(0x15,2,0,0,*(undefined4 *)(in_ECX + 8),0);
  return;
}


// ==== FUN_00525a50 @ 0x00525a50 ====

undefined4 FUN_00525a50(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int *in_ECX;
  char acStack_5e [2];
  undefined1 uStack_40;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  undefined1 uStack_18;
  undefined1 uStack_17;
  int iStack_10;
  
  iVar2 = (**(code **)(*param_1 + 0x10))();
  iVar3 = (**(code **)(*in_ECX + 8))();
  if (iVar2 != iVar3) {
    return 0;
  }
  (**(code **)(*(int *)in_ECX[3] + 0x28))();
  (**(code **)(*(int *)in_ECX[3] + 0x40))(*(undefined1 *)((int)param_1 + 0x5f));
  (**(code **)(*(int *)in_ECX[3] + 0x2c))((char)param_1[0xd]);
  (**(code **)(*(int *)in_ECX[3] + 0x30))(param_1[0xe]);
  (**(code **)(*(int *)in_ECX[3] + 0x3c))(*(undefined1 *)((int)param_1 + 0x5e));
  uStack_1c = *(undefined2 *)((int)param_1 + 0x3e);
  uStack_1e = (undefined2)param_1[0xf];
  uStack_40 = 0;
  if ((uint)param_1[0x16] < 0x10) {
    piVar4 = param_1 + 0x11;
  }
  else {
    piVar4 = (int *)param_1[0x11];
  }
  FUN_0050cd30(acStack_5e + -3,&DAT_009b8048,piVar4);
  uVar5 = 0;
  do {
    cVar1 = acStack_5e[uVar5 - 3];
    acStack_5e[uVar5 + 0x1e] = cVar1;
    if (cVar1 == '\0') goto LAB_00525b0a;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x21);
  uStack_40 = 0;
LAB_00525b0a:
  uStack_17 = *(undefined1 *)((int)param_1 + 0x5d);
  uStack_18 = (undefined1)param_1[0x17];
  (**(code **)(*(int *)in_ECX[3] + 0x20))(&stack0xffffffc0);
  (**(code **)(*in_ECX + 0x28))(*(undefined4 *)(iStack_10 + 8));
  if (*(char *)((int)param_1 + 0x5e) == '\x01') {
    iVar2 = FUN_004dd240(0x23,3,0,0,in_ECX[2]);
    in_ECX[0xb] = iVar2;
    return 1;
  }
  (**(code **)(*DAT_00b5ac70 + 0x20))(in_ECX[2],in_ECX[0xb]);
  return 1;
}


// ==== FUN_00525b80 @ 0x00525b80 ====

void FUN_00525b80(int param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  for (puVar2 = *(undefined4 **)(param_1 + 4); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(*DAT_00b5ac70 + 0x20))(*(undefined4 *)(in_ECX + 8),*puVar2);
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


// ==== FUN_00525bd0 @ 0x00525bd0 ====

void FUN_00525bd0(void)

{
  int in_ECX;
  
  FUN_00525b80(in_ECX + 0xa0);
  FUN_00525b80(in_ECX + 0xb0);
  FUN_00511d10();
  FUN_00512da0();
  return;
}


// ==== FUN_00525c10 @ 0x00525c10 ====

void FUN_00525c10(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b80d4;
  (**(code **)(*DAT_00b5ac6c + 0x18))(in_ECX[2]);
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b7950;
  }
  puVar1[1] = in_ECX[2];
  FUN_00797a20(puVar1);
  if (in_ECX[3] != 0) {
    (**(code **)(*DAT_00b5a754 + 0x10))(1,in_ECX[3]);
  }
  if ((void *)in_ECX[0x2d] != (void *)0x0) {
    _free((void *)in_ECX[0x2d]);
    return;
  }
  in_ECX[0x2d] = 0;
  in_ECX[0x2e] = 0;
  in_ECX[0x2f] = 0;
  if ((void *)in_ECX[0x29] != (void *)0x0) {
    _free((void *)in_ECX[0x29]);
    return;
  }
  in_ECX[0x29] = 0;
  in_ECX[0x2a] = 0;
  in_ECX[0x2b] = 0;
  if ((uint)in_ECX[0x26] < 0x10) {
    in_ECX[0x25] = 0;
    in_ECX[0x26] = 0xf;
    *(undefined1 *)(in_ECX + 0x21) = 0;
    *in_ECX = &PTR_FUN_009b78dc;
    return;
  }
  _free((void *)in_ECX[0x21]);
  return;
}


// ==== FUN_00525cf0 @ 0x00525cf0 ====

int FUN_00525cf0(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int extraout_EAX;
  int *in_ECX;
  void *unaff_ESI;
  undefined1 local_1c [16];
  uint uStack_c;
  
  if (DAT_00b5a7b4 == (int *)0x0) {
    return 0xffffff;
  }
  iVar1 = *DAT_00b5a7b4;
  uVar3 = (**(code **)(*in_ECX + 0x40))(local_1c);
  cVar2 = (**(code **)(iVar1 + 0x28))(uVar3);
  if (uStack_c < 0x10) {
    return (-(uint)(cVar2 == '\0') & 0xff00ff) + 0xff00;
  }
  _free(unaff_ESI);
  return extraout_EAX;
}


// ==== FUN_00525d50 @ 0x00525d50 ====

int FUN_00525d50(int param_1,ushort param_2,uint param_3,undefined4 param_4,char param_5,int param_6
                )

{
  int *piVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 unaff_ESI;
  uint *puVar5;
  uint auStack_a8 [41];
  
  if ((short)param_3 == 0) {
    piVar1 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(param_4);
    puVar2 = (uint *)(**(code **)(*piVar1 + 4))();
    puVar5 = auStack_a8;
    for (iVar4 = 0x27; puVar2 = puVar2 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *puVar2;
      puVar5 = puVar5 + 1;
    }
    param_3 = auStack_a8[2];
  }
  uVar3 = (**(code **)(*DAT_00b5a6dc + 0x28))
                    ((uint)param_2 << 0x10 | param_3 & 0xffff,
                     (-(uint)(param_5 != '\0') & 2) + param_6);
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = unaff_ESI;
  *(char *)(param_1 + 4) = (char)unaff_ESI;
  FUN_00401660(uVar3,unaff_ESI,0xffffffff);
  return param_1;
}


// ==== FUN_00525df0 @ 0x00525df0 ====

void FUN_00525df0(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined4 uStack_c;
  uint uStack_8;
  
  iVar1 = (**(code **)(*in_ECX + 0x68))();
  if (*(char *)(iVar1 + 0x14) == '\x01') {
    iVar1 = FUN_00525cf0();
    if (in_ECX[0x1e] != iVar1) {
      in_ECX[0x1e] = iVar1;
      pvVar2 = operator_new(0x34);
      if (pvVar2 == (void *)0x0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_00527cb0();
      }
      *(int *)(iVar1 + 4) = in_ECX[0x1b];
      *(char *)(iVar1 + 8) = (char)in_ECX[0x1c];
      *(int *)(iVar1 + 0xc) = in_ECX[0x1d];
      *(int *)(iVar1 + 0x10) = in_ECX[0x1e];
      *(int *)(iVar1 + 0x14) = in_ECX[0x1f];
      FUN_00401660(in_ECX + 0x20,0,0xffffffff);
      FUN_00797a20(iVar1);
      *(undefined1 *)(in_ECX + 0x27) = 1;
      return;
    }
  }
  else if ((char)in_ECX[0x27] == '\x01') {
    puVar3 = operator_new(0x10);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = &PTR_FUN_009b7964;
      puVar3[3] = 0;
      *(undefined1 *)(puVar3 + 2) = 1;
    }
    uVar4 = (**(code **)(*in_ECX + 8))();
    puVar3[1] = uStack_c;
    uStack_8 = uStack_8 & 0xffffff00;
    puVar3[2] = uStack_8;
    puVar3[3] = uVar4;
    FUN_00797a20(puVar3);
    in_ECX[0x1e] = 0;
    *(undefined1 *)(in_ECX + 0x27) = 0;
  }
  return;
}


// ==== FUN_00525ef0 @ 0x00525ef0 ====

void FUN_00525ef0(int param_1,int param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  short sVar7;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  byte unaff_retaddr;
  undefined1 *puVar8;
  undefined4 *puVar9;
  void **ppvVar10;
  undefined1 *puVar11;
  undefined1 local_84 [2];
  undefined1 auStack_82 [2];
  void *pvStack_80;
  undefined1 uStack_7c;
  undefined4 local_74;
  undefined4 uStack_70;
  uint uStack_6c;
  undefined4 uStack_68;
  void *pvStack_64;
  undefined1 uStack_60;
  undefined4 uStack_54;
  uint uStack_50;
  undefined4 uStack_4c;
  void *pvStack_48;
  undefined4 uStack_38;
  uint uStack_34;
  void *pvStack_2c;
  undefined1 uStack_28;
  uint uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_8;
  
  sVar7 = *(short *)(param_2 + param_1 * 2);
  uVar4 = CONCAT22((short)((uint)unaff_EBP >> 0x10),sVar7);
  local_74 = uVar4;
  iVar3 = (**(code **)(*DAT_00b5ad20 + 0x14))(uVar4);
  if (iVar3 == 0x601) {
    uVar4 = (**(code **)(*DAT_00b5a6dc + 8))
                      (CONCAT31(6,*(undefined1 *)(param_2 + 0x2a)),param_1,uVar4);
    uStack_14 = 0xf;
    uStack_18 = 0;
    uStack_28 = 0;
    FUN_00401740(s_weaponW_009b8028,7);
    if (*(short *)(param_2 + (uint)unaff_retaddr * 2) != 0) {
      sVar7 = sVar7 + 1;
    }
    iVar3 = CONCAT22((short)((uint)unaff_ESI >> 0x10),sVar7);
    uStack_4c = 0xf;
    uStack_50 = 0;
    uStack_60 = 0;
    pcVar5 = PTR_DAT_00aed03c;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_DAT_00aed03c,(int)pcVar5 - (int)(PTR_DAT_00aed03c + 1));
    uStack_68 = 0xf;
    uStack_6c = 0;
    uStack_7c = 0;
    pcVar5 = PTR_s_WingArmor_00aed04c;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_s_WingArmor_00aed04c,(int)pcVar5 - (int)(PTR_s_WingArmor_00aed04c + 1));
    puVar11 = local_84 + -0xc;
    ppvVar10 = &pvStack_2c;
    uVar6 = (**(code **)(*DAT_00b5a7e4 + 4))(ppvVar10,puVar11,0);
    puVar9 = &uStack_68;
    puVar8 = local_84;
    FUN_00511d10(puVar8,puVar9,uVar6);
    FUN_00513030(puVar8,puVar9,uVar6,ppvVar10,puVar11);
    if (0xf < uStack_6c) {
      _free(pvStack_80);
      return;
    }
    uStack_6c = 0xf;
    uStack_70 = 0;
    pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
    if (0xf < uStack_50) {
      _free(pvStack_64);
      return;
    }
    uStack_50 = 0xf;
    uStack_34 = 0xf;
    uStack_54 = 0;
    pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
    uStack_38 = 0;
    pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
    pcVar5 = PTR_s_WingArmor_00aed04c;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_s_WingArmor_00aed04c,(int)pcVar5 - (int)(PTR_s_WingArmor_00aed04c + 1));
    puVar9 = &uStack_4c;
    FUN_00511d10(puVar9);
    FUN_00512ca0(puVar9);
    if (0xf < uStack_34) {
      _free(pvStack_48);
      return;
    }
    uVar2 = FUN_005256e0(uVar4,uStack_8,1);
    FUN_00512a90(iVar3 + 0x78,iVar3 + 0x94,uVar2,*(undefined1 *)(iVar3 + 0x116));
    if (0xf < uStack_18) {
      _free(pvStack_2c);
      return;
    }
  }
  return;
}


// ==== FUN_00526130 @ 0x00526130 ====

void FUN_00526130(void)

{
  char cVar1;
  char *pcVar2;
  int in_ECX;
  undefined1 *puVar3;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  FUN_00525b80(in_ECX + 0xb0);
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  pcVar2 = PTR_s_R_Weapon_00aed044;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_s_R_Weapon_00aed044,(int)pcVar2 - (int)(PTR_s_R_Weapon_00aed044 + 1));
  puVar3 = local_38;
  FUN_00511d10(puVar3);
  FUN_00512d50(puVar3);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  pcVar2 = PTR_s_L_Weapon_00aed048;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_s_L_Weapon_00aed048,(int)pcVar2 - (int)(PTR_s_L_Weapon_00aed048 + 1));
  puVar3 = local_1c;
  FUN_00511d10(puVar3);
  FUN_00512d50(puVar3);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00526220 @ 0x00526220 ====

void FUN_00526220(void)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int *in_ECX;
  void *apvStack_1c [5];
  uint uStack_8;
  
  iVar1 = (**(code **)(*in_ECX + 8))();
  in_ECX[0x1d] = iVar1;
  in_ECX[0x1b] = 0;
  in_ECX[0x1e] = 0;
  uVar2 = (**(code **)(*in_ECX + 0x40))(apvStack_1c);
  FUN_00401660(uVar2,0,0xffffffff);
  if (0xf < uStack_8) {
    _free(apvStack_1c[0]);
    return;
  }
  in_ECX[0x1f] = 0x38;
  pvVar3 = operator_new(0x34);
  if (pvVar3 == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00522170();
  }
  *(int *)(iVar1 + 4) = in_ECX[0x1b];
  *(char *)(iVar1 + 8) = (char)in_ECX[0x1c];
  *(int *)(iVar1 + 0xc) = in_ECX[0x1d];
  *(int *)(iVar1 + 0x10) = in_ECX[0x1e];
  *(int *)(iVar1 + 0x14) = in_ECX[0x1f];
  FUN_00401660(in_ECX + 0x20,0,0xffffffff);
  FUN_00797a20(iVar1);
  return;
}


// ==== FUN_005262d0 @ 0x005262d0 ====

void FUN_005262d0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  FUN_00526220();
  return;
}


// ==== FUN_005262f0 @ 0x005262f0 ====

void FUN_005262f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b80d4;
  in_ECX[3] = 0;
  in_ECX[0x26] = 0xf;
  in_ECX[0x25] = 0;
  *(undefined1 *)(in_ECX + 0x21) = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1d] = 0xffffffff;
  in_ECX[0x1e] = 0xffffff;
  in_ECX[0x1f] = 0x38;
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  FUN_00401740(s_No_Name_009b79ec,7);
  *(undefined1 *)(in_ECX + 0x27) = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x2a] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x2d] = 0;
  in_ECX[0x2e] = 0;
  in_ECX[0x2f] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0xff;
  *(undefined1 *)(in_ECX + 0x19) = 0xff;
  *(undefined1 *)((int)in_ECX + 0x9d) = 6;
  *(undefined1 *)((int)in_ECX + 0x9e) = 6;
  in_ECX[1] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[6] = 0;
  in_ECX[5] = 0;
  in_ECX[4] = 0;
  in_ECX[0xb] = 0;
  *(undefined1 *)((int)in_ECX + 0x39) = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 0x1a) = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  in_ECX[0xd] = 0;
  *(undefined2 *)((int)in_ECX + 0x66) = 0;
  *(undefined1 *)(in_ECX + 0x30) = 0;
  *(undefined1 *)((int)in_ECX + 0x31) = 1;
  return;
}


// ==== FUN_005263c0 @ 0x005263c0 ====

undefined4 FUN_005263c0(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x40001) {
    FUN_00525df0();
  }
  else if (iVar2 == 0x50070001) {
    cVar1 = FUN_00525a50(param_1,param_2);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00526410 @ 0x00526410 ====

char FUN_00526410(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  uint uVar4;
  char cVar5;
  
  pcVar1 = *(char **)(param_1 + 4);
  cVar3 = '\a';
  if (pcVar1 != (char *)0x0) {
    pcVar2 = *(char **)(param_1 + 8);
    if (pcVar2 != pcVar1) {
      cVar3 = '\a';
      if (pcVar2 == pcVar1) {
        cVar3 = FUN_004d4b70();
      }
      cVar5 = *pcVar1;
      for (uVar4 = 0; uVar4 < (uint)((int)pcVar2 - (int)pcVar1);
          uVar4 = (uint)(byte)((char)uVar4 + 1)) {
        cVar3 = pcVar1[uVar4];
        if (cVar3 != cVar5) {
          return '\x06';
        }
        cVar5 = cVar3;
      }
    }
  }
  return cVar3;
}


// ==== FUN_00526470 @ 0x00526470 ====

void FUN_00526470(undefined4 param_1)

{
  char cVar1;
  char *pcVar2;
  int in_ECX;
  undefined1 *puVar3;
  undefined1 local_2c [4];
  void *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  FUN_00525b80(in_ECX + 0xa0);
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  pcVar2 = PTR_s_WingArmor_00aed04c;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_s_WingArmor_00aed04c,(int)pcVar2 - (int)(PTR_s_WingArmor_00aed04c + 1));
  puVar3 = local_1c;
  FUN_00511d10(puVar3);
  FUN_00512d50(puVar3);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  puVar3 = local_2c;
  local_28 = (void *)0x0;
  local_24 = 0;
  local_20 = 0;
  FUN_00511d10(puVar3);
  FUN_00512cd0();
  FUN_00512a20(puVar3);
  if (local_28 == (void *)0x0) {
    return;
  }
  FUN_004ff020(local_28,local_24,local_2c,param_1);
  _free(local_28);
  return;
}


// ==== FUN_00526540 @ 0x00526540 ====

undefined4 FUN_00526540(char param_1,byte param_2,int param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  int *piVar5;
  int iVar6;
  undefined4 extraout_EAX_00;
  byte bVar7;
  uint uVar8;
  void *_Memory;
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *local_8;
  int local_4;
  
  iVar1 = param_3;
  if (param_1 == '\0') {
    bVar7 = *(byte *)(param_3 + 0x18);
  }
  else {
    if (param_1 != '\x01') {
      return 7;
    }
    bVar7 = *(byte *)(param_3 + 0x19);
  }
  if ((bVar7 == 0) || (bVar7 < param_2)) {
    return 7;
  }
  _Memory = (void *)0x0;
  uVar8 = 0;
  local_c = (void *)0x0;
  local_8 = (undefined1 *)0x0;
  local_4 = 0;
  if (param_2 != 0) {
    do {
      puVar2 = local_8;
      if (param_1 == '\0') {
        uVar3 = *(undefined2 *)(iVar1 + 0x1a + uVar8 * 2);
      }
      else {
        uVar3 = *(undefined2 *)(iVar1 + 0x22 + uVar8 * 2);
      }
      piVar5 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(uVar3);
      if (piVar5 == (int *)0x0) {
        if (_Memory == (void *)0x0) {
          return 7;
        }
        _free(_Memory);
        return extraout_EAX_00;
      }
      iVar6 = (**(code **)(*piVar5 + 4))();
      param_3 = CONCAT31(param_3._1_3_,*(undefined1 *)(iVar6 + 0x10));
      if ((_Memory == (void *)0x0) ||
         ((uint)(local_4 - (int)_Memory) <= (uint)((int)puVar2 - (int)_Memory))) {
        FUN_00469780(puVar2,1,&param_3);
        _Memory = local_c;
      }
      else {
        *puVar2 = *(undefined1 *)(iVar6 + 0x10);
        local_8 = puVar2 + 1;
      }
      bVar7 = (char)uVar8 + 1;
      uVar8 = (uint)bVar7;
    } while (bVar7 < param_2);
  }
  uVar4 = FUN_00526410(local_10);
  if (_Memory == (void *)0x0) {
    return uVar4;
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_00526670 @ 0x00526670 ====

void FUN_00526670(int param_1)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  undefined2 extraout_var;
  int *piVar7;
  int iVar8;
  int in_ECX;
  undefined4 in_EDX;
  int iVar9;
  int unaff_ESI;
  undefined4 unaff_retaddr;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined1 *puVar13;
  undefined1 local_60 [4];
  void *pvStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined1 uStack_50;
  undefined1 uStack_4f;
  undefined1 uStack_4e;
  undefined1 uStack_4d;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar10 = CONCAT22((short)((uint)in_EDX >> 0x10),*(undefined2 *)(param_1 + 0x16));
  iVar5 = (**(code **)(*DAT_00b5a6dc + 8))
                    (CONCAT31((int3)((uint)uVar10 >> 8),*(undefined1 *)(param_1 + 0x2a)),0,uVar10);
  pvStack_5c = (void *)0x0;
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  uStack_4d = 0;
  uStack_50 = 0;
  uStack_4f = 0;
  uStack_4e = 0;
  uStack_48 = DAT_0099d080;
  uStack_4c = 0xffffffff;
  iVar9 = 2;
  do {
    if ((iVar9 < 7) || (10 < iVar9)) {
      bVar2 = (char)iVar9 - 2;
      uVar4 = bVar2 + 1;
      if ((*(ushort *)(iVar5 + 0x114) & uVar4) != uVar4) {
        iVar6 = (**(code **)(*DAT_00b5a6dc + 8))
                          (*(undefined1 *)(param_1 + 0x2a),bVar2,
                           *(undefined2 *)(param_1 + iVar9 * 2));
        FUN_00401660(iVar6 + 0x78,0,0xffffffff);
        FUN_00401660(iVar6 + 0x94,0,0xffffffff);
        piVar7 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))
                                  (CONCAT22(extraout_var,*(undefined2 *)(param_1 + iVar9 * 2)));
        if (piVar7 == (int *)0x0) {
          uVar3 = 0;
        }
        else {
          iVar8 = (**(code **)(*piVar7 + 4))();
          bVar2 = *(byte *)(iVar8 + 0x108);
          uVar3 = 0;
          if (bVar2 != 0) {
            if ((bVar2 == 0) || (3 < bVar2)) {
              if ((bVar2 < 4) || (uStack_8 = CONCAT31(uStack_8._1_3_,2), 6 < bVar2)) {
                uStack_8 = CONCAT31(uStack_8._1_3_,3);
              }
            }
            else {
              uStack_8 = CONCAT31(uStack_8._1_3_,1);
            }
            if (*(char *)(in_ECX + 0x68) == '\0') {
              uVar12 = 3000;
              uVar11 = 1;
              uVar10 = 0x7000a;
              FUN_00511d10(0x7000a,1,3000);
              FUN_00512cd0();
              FUN_005127a0(uVar10,uVar11,uVar12);
              *(undefined1 *)(in_ECX + 0x68) = 1;
            }
            uVar3 = (undefined1)uStack_8;
          }
        }
        uStack_50 = *(undefined1 *)(iVar6 + 0x116);
        uStack_4d = uVar3;
        FUN_004ff800(&uStack_50);
        if (*(short *)(iVar6 + 0xb0) != 0) {
          uStack_8 = FUN_004dd240(0x1f,1,*(short *)(iVar6 + 0xb0),0,*(undefined4 *)(in_ECX + 8));
          iVar6 = *(int *)(in_ECX + 0xa4);
          if ((iVar6 == 0) ||
             ((uint)(*(int *)(in_ECX + 0xac) - iVar6 >> 2) <=
              (uint)(*(int *)(in_ECX + 0xa8) - iVar6 >> 2))) {
            FUN_0042f3e0(*(undefined4 *)(in_ECX + 0xa8),1,&uStack_8);
          }
          else {
            puVar1 = *(undefined4 **)(in_ECX + 0xa8);
            *puVar1 = uStack_8;
            *(undefined4 **)(in_ECX + 0xa8) = puVar1 + 1;
          }
          in_ECX = unaff_ESI;
        }
      }
    }
    else {
      iVar6 = (**(code **)(*DAT_00b5a6dc + 0x18))(0,*(undefined2 *)(param_1 + iVar9 * 2));
      if (iVar6 != 0) {
        FUN_00525ef0(iVar9,param_1,uStack_4,unaff_retaddr);
        if (*(short *)(iVar6 + 0xb0) != 0) {
          uStack_8 = FUN_004dd240(0x1f,1,*(short *)(iVar6 + 0xb0),0,*(undefined4 *)(in_ECX + 8));
          FUN_00430ce0(&uStack_8);
        }
      }
    }
    iVar9 = iVar9 + 1;
  } while (iVar9 < 0xb);
  if (*(short *)(iVar5 + 0x114) != 0) {
    uVar10 = CONCAT22((short)((uint)&uStack_50 >> 0x10),*(undefined2 *)(param_1 + 0x16));
    iVar5 = (**(code **)(*DAT_00b5a6dc + 0x14))
                      (CONCAT31((int3)((uint)uVar10 >> 8),*(undefined1 *)(param_1 + 0x2a)),uVar10,
                       &uStack_50);
    FUN_00401660(iVar5,0,0xffffffff);
    FUN_00401660(iVar5 + 0x1c,0,0xffffffff);
    uStack_4d = 0;
    FUN_004ff800(&uStack_50);
  }
  puVar13 = local_60;
  FUN_00511d10(puVar13);
  FUN_00512cd0();
  FUN_00512a20(puVar13);
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  if (0xf < uStack_2c) {
    _free(pvStack_40);
    return;
  }
  uStack_30 = 0;
  uStack_2c = 0xf;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  if (pvStack_5c == (void *)0x0) {
    return;
  }
  FUN_004ff020(pvStack_5c,uStack_58,local_60,uStack_4);
  _free(pvStack_5c);
  return;
}


// ==== FUN_005269f0 @ 0x005269f0 ====

/* WARNING: Removing unreachable block (ram,0x00526b60) */

void FUN_005269f0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  int *unaff_retaddr;
  undefined1 *puVar4;
  undefined1 auStack_92 [10];
  undefined1 uStack_88;
  undefined1 uStack_87;
  undefined1 uStack_86;
  undefined1 uStack_85;
  undefined4 uStack_84;
  undefined4 uStack_80;
  void *pvStack_78;
  undefined4 uStack_68;
  uint uStack_64;
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  undefined1 auStack_40 [4];
  void *local_3c [5];
  uint uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  
  (**(code **)(*DAT_00b5a6dc + 0x24))(local_3c);
  FUN_00526130(unaff_retaddr);
  FUN_00526470(unaff_retaddr);
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    uVar2 = (**(code **)(*in_ECX + 8))();
    *puVar1 = &PTR_FUN_009b80a4;
    puVar1[1] = uVar2;
  }
  FUN_00797a20(puVar1);
  uStack_64 = 0xf;
  uStack_68 = 0;
  pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
  uStack_48 = 0xf;
  uStack_4c = 0;
  pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
  uStack_85 = 0;
  uStack_88 = 0;
  uStack_87 = 0;
  uStack_86 = 0;
  uStack_80 = DAT_0099d080;
  uStack_84 = 0xffffffff;
  FUN_00401660(auStack_40,0,0xffffffff);
  FUN_00401660(auStack_24,0,0xffffffff);
  uStack_85 = 0;
  FUN_004ff800(&uStack_88);
  puVar4 = auStack_92 + -6;
  FUN_00511d10(puVar4);
  FUN_00512cd0();
  FUN_00512a20(puVar4);
  (**(code **)(*unaff_retaddr + 0x10))();
  if ((char)in_ECX[0xc] == '\0') {
    iVar3 = FUN_004dd240(0x25,1,0,0,in_ECX[2]);
    in_ECX[0xd] = iVar3;
  }
  if (0xf < uStack_48) {
    _free(pvStack_5c);
    return;
  }
  uStack_48 = 0xf;
  uStack_4c = 0;
  pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
  if (0xf < uStack_64) {
    _free(pvStack_78);
    return;
  }
  uStack_64 = 0xf;
  uStack_68 = 0;
  pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  if (uStack_28 < 0x10) {
    return;
  }
  _free(local_3c[0]);
  return;
}


// ==== FUN_00526c20 @ 0x00526c20 ====

void FUN_00526c20(int param_1,int param_2,int param_3)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  int in_ECX;
  undefined4 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  void **ppvVar9;
  uint *puVar10;
  undefined4 uVar11;
  undefined4 uStack_98;
  void *local_94;
  void *pvStack_90;
  void *local_8c;
  undefined4 uStack_84;
  uint uStack_80;
  uint local_7c;
  uint local_78 [4];
  undefined1 auStack_68 [4];
  void *pvStack_64;
  uint uStack_50;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_4a;
  undefined1 uStack_49;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined1 uStack_3c;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 uStack_20;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if ((6 < param_1) && (param_1 < 0xb)) {
    iVar3 = (**(code **)(*DAT_00b5ad20 + 0x14))(*(undefined2 *)(param_2 + param_1 * 2));
    if (iVar3 == 0x604) {
      iVar3 = (**(code **)(*DAT_00b5a6dc + 0x20))(*(undefined2 *)(param_2 + param_1 * 2));
      *(undefined2 *)(in_ECX + 0x66) = *(undefined2 *)(iVar3 + 0x5c);
      puVar2 = PTR_s_T_Port_00aed040;
      uStack_98 = CONCAT22(uStack_98._2_2_,*(undefined2 *)(iVar3 + 0x5a));
      *(undefined4 *)(param_2 + 0x1c) = 7;
      *(undefined4 *)(param_2 + 0x20) = uStack_98;
      FUN_00401830(puVar2);
      puVar10 = local_78 + -9;
      ppvVar9 = &local_94;
      FUN_00511d10(ppvVar9,puVar10);
      FUN_00512e40(ppvVar9,puVar10);
      if (0xf < local_7c) {
        _free(pvStack_90);
        return;
      }
      uStack_98 = CONCAT22(uStack_98._2_2_,
                           (ushort)*(byte *)(param_2 + 0x2a) + *(short *)(iVar3 + 0x5a));
      FUN_00401830(PTR_s_T_Port_00aed040);
      FUN_00401830(PTR_DAT_00aed03c);
      puVar10 = local_78 + -9;
      iVar8 = iVar3 + 0x3c;
      uVar4 = (**(code **)(*DAT_00b5a7e4 + 4))(iVar8,puVar10,1);
      puVar7 = auStack_68;
      puVar6 = &uStack_98;
      FUN_00511d10(puVar6,puVar7,uVar4);
      FUN_00513030(puVar6,puVar7,uVar4,iVar8,puVar10);
      if (0xf < uStack_80) {
        _free(local_94);
        return;
      }
      uStack_80 = 0xf;
      uStack_84 = 0;
      local_94 = (void *)((uint)local_94 & 0xffffff00);
      if (0xf < uStack_50) {
        _free(pvStack_64);
        return;
      }
      local_78[1] = 0;
      local_78[2] = 0;
      local_78[3] = 0;
      uStack_28 = 0xf;
      uStack_2c = 0;
      uStack_3c = 0;
      uStack_c = 0xf;
      uStack_10 = 0;
      uStack_20 = 0;
      uStack_49 = 0;
      uStack_4c = 0;
      uStack_4b = 0;
      uStack_4a = 0;
      uStack_44 = DAT_0099d080;
      uStack_48 = 0xffffffff;
      FUN_00401660(iVar3,0,0xffffffff);
      FUN_00401660(iVar3 + 0x1c,0,0xffffffff);
      uStack_4c = *(undefined1 *)(iVar3 + 0x58);
      FUN_004ff800(&uStack_4c);
      FUN_00401830(PTR_s_T_Port_00aed040);
      puVar10 = local_78;
      puVar7 = auStack_68;
      FUN_00511d10(puVar7,puVar10);
      FUN_00512ca0(puVar7);
      FUN_00512a20(puVar10);
      if (0xf < uStack_50) {
        _free(pvStack_64);
        return;
      }
      if (*(char *)(local_7c + 0xc0) == '\x02') {
        FUN_004dd240(0x24,0,1,3,*(undefined4 *)(local_7c + 8));
      }
      FUN_004107d0();
      FUN_004ff750();
      *(undefined1 *)(local_7c + 0xc0) = 0;
      return;
    }
  }
  puVar2 = PTR_DAT_00aed03c;
  *(undefined2 *)(in_ECX + 0x66) = 0;
  local_94 = (void *)CONCAT22(local_94._2_2_,(ushort)*(byte *)(param_2 + 0x2a));
  *(undefined4 *)(param_3 + 0x1c) = 0;
  *(void **)(param_3 + 0x20) = local_94;
  local_78[0] = 0xf;
  local_7c = 0;
  local_8c = (void *)((uint)local_8c & 0xffffff00);
  pcVar5 = puVar2;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(puVar2,(int)pcVar5 - (int)(puVar2 + 1));
  ppvVar9 = &pvStack_90;
  FUN_00511d10(ppvVar9);
  FUN_00512f40(ppvVar9);
  if (0xf < local_78[0]) {
    _free(local_8c);
    return;
  }
  if (*(char *)(in_ECX + 0x39) == (char)param_1) {
    uVar4 = *(undefined4 *)(in_ECX + 8);
    uVar11 = 3;
  }
  else {
    uVar4 = *(undefined4 *)(in_ECX + 8);
    uVar11 = 5;
  }
  FUN_004dd240(0x24,0,1,uVar11,uVar4);
  *(undefined1 *)(in_ECX + 0xc0) = 0;
  return;
}


// ==== FUN_00526f70 @ 0x00526f70 ====

/* WARNING: Removing unreachable block (ram,0x0052719b) */

int FUN_00526f70(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int extraout_EAX_02;
  int extraout_EAX_03;
  int extraout_EAX_04;
  int extraout_EAX_05;
  int extraout_EAX_06;
  int in_ECX;
  char *pcVar5;
  int unaff_retaddr;
  undefined1 auStack_56 [10];
  undefined1 auStack_4c [4];
  void *pvStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 auStack_3c [4];
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(&DAT_009b8002,0);
    return param_1;
  }
  iVar2 = **(int **)(in_ECX + 0xc);
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pcVar4 = (char *)(**(code **)(iVar2 + 0x1c))(uVar3);
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  pcVar5 = pcVar4;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar4,(int)pcVar5 - (int)(pcVar4 + 1));
  pvStack_48 = (void *)0x0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_24 = 0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  FUN_00401740(&DAT_009b8004,1);
  FUN_00406720(auStack_3c);
  if (0xf < uStack_24) {
    _free(pvStack_38);
    return extraout_EAX;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  FUN_00401740(&DAT_009b8008,1);
  FUN_00406720(auStack_3c);
  if (0xf < uStack_24) {
    _free(pvStack_38);
    return extraout_EAX_00;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  FUN_00401740(&DAT_009b800c,1);
  FUN_00406720(auStack_3c);
  if (0xf < uStack_24) {
    _free(pvStack_38);
    return extraout_EAX_01;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  FUN_00401740(s___BS___009b8010,6);
  FUN_00406720(auStack_3c);
  if (0xf < uStack_24) {
    _free(pvStack_38);
    return extraout_EAX_02;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  FUN_00401740(s___GT___009b8018,6);
  FUN_00406720(auStack_3c);
  if (0xf < uStack_24) {
    _free(pvStack_38);
    return extraout_EAX_03;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  FUN_00401740(s___LT___009b8020,6);
  FUN_00406720(auStack_3c);
  if (0xf < uStack_24) {
    _free(pvStack_38);
    return extraout_EAX_04;
  }
  FUN_00404a40(unaff_retaddr,auStack_20,auStack_4c,auStack_56 + -6);
  if (pvStack_48 != (void *)0x0) {
    FUN_00405de0(pvStack_48,uStack_44,auStack_4c,unaff_retaddr);
    _free(pvStack_48);
    return extraout_EAX_05;
  }
  pvStack_48 = (void *)0x0;
  uStack_44 = 0;
  uStack_40 = 0;
  if (uStack_8 < 0x10) {
    return unaff_retaddr;
  }
  _free(pvStack_1c);
  return extraout_EAX_06;
}


// ==== FUN_00527220 @ 0x00527220 ====

void FUN_00527220(undefined4 param_1,undefined4 *param_2)

{
  short sVar1;
  undefined1 uVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int *in_ECX;
  int iVar8;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined4 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined2 uVar14;
  char cVar15;
  undefined *puStack_b4;
  uint uStack_b0;
  undefined1 auStack_ac [4];
  void *pvStack_a8;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  uint uStack_94;
  undefined1 uStack_90;
  undefined1 auStack_88 [4];
  void *pvStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  uint uStack_74;
  uint uStack_70;
  undefined1 auStack_6c [4];
  void *pvStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_58;
  uint uStack_54;
  short sStack_50;
  short sStack_4e;
  undefined4 local_4c [5];
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined2 uStack_36;
  undefined2 uStack_34;
  undefined2 uStack_32;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  undefined4 uStack_26;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  uVar14 = *(undefined2 *)((int)param_2 + 2);
  puVar6 = param_2;
  puVar9 = local_4c;
  for (iVar8 = 0xb; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar9 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar9 = puVar9 + 1;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(uVar14);
  sVar1 = sStack_4e;
  if (piVar3 != (int *)0x0) {
    iVar8 = (**(code **)(*piVar3 + 4))();
    if ((*(int *)(iVar8 + 0xc) == 0x414) || (*(int *)(iVar8 + 0xc) == 0x411)) {
      uStack_36 = uStack_2e;
      uStack_38 = uStack_37;
      sStack_50 = sVar1;
      uStack_34 = uStack_2c;
      uStack_32 = uStack_2a;
      uStack_30 = uStack_28;
    }
  }
  uVar14 = 0x606;
  if (sVar1 != 0) {
    uVar7 = CONCAT22((undefined2)local_4c[0],sStack_4e);
    iVar8 = (**(code **)(*DAT_00b5a738 + 0x10))(uVar7);
    if (iVar8 != 0) {
      uVar12 = 1;
      uVar13 = uVar7;
      iVar8 = (**(code **)(*DAT_00b5a6dc + 8))(uStack_26,1,uVar7);
      FUN_00525d50(&uStack_2c,CONCAT22((short)((uint)iVar8 >> 0x10),uStack_32) & 0xffff00ff,
                   CONCAT22(extraout_var_00,*(undefined2 *)(iVar8 + 0x118)),uVar7,uStack_c,1);
      uStack_98 = CONCAT22(uStack_98._2_2_,sVar1);
      uStack_9c = 9;
      uStack_60 = 0xf;
      uStack_64 = 0;
      uStack_74 = uStack_74 & 0xffffff00;
      pcVar4 = PTR_DAT_00aed03c;
      do {
        cVar15 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar15 != '\0');
      FUN_00401740(PTR_DAT_00aed03c,(int)pcVar4 - (int)(PTR_DAT_00aed03c + 1));
      uStack_7c = 0xf;
      uStack_80 = 0;
      uStack_90 = 0;
      pcVar4 = PTR_s_R_Weapon_00aed044;
      do {
        cVar15 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar15 != '\0');
      FUN_00401740(PTR_s_R_Weapon_00aed044,(int)pcVar4 - (int)(PTR_s_R_Weapon_00aed044 + 1));
      uVar5 = (**(code **)(*DAT_00b5a7e4 + 4))(&uStack_2c,&uStack_9c,0);
      puVar11 = auStack_6c;
      puVar10 = auStack_88;
      FUN_00511d10(puVar10,puVar11,uVar5);
      FUN_00513030(puVar10,puVar11,uVar5,uVar12,uVar13);
      if (0xf < uStack_70) {
        _free(pvStack_84);
        return;
      }
      uStack_70 = 0xf;
      uStack_74 = 0;
      pvStack_84 = (void *)((uint)pvStack_84 & 0xffffff00);
      if (0xf < uStack_54) {
        _free(pvStack_68);
        return;
      }
      uStack_54 = 0xf;
      uStack_94 = 0xf;
      uStack_58 = 0;
      pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
      uStack_98 = 0;
      pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
      pcVar4 = PTR_s_R_Weapon_00aed044;
      do {
        cVar15 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar15 != '\0');
      FUN_00401740(PTR_s_R_Weapon_00aed044,(int)pcVar4 - (int)(PTR_s_R_Weapon_00aed044 + 1));
      puVar11 = auStack_ac;
      FUN_00511d10(puVar11);
      FUN_00512ca0(puVar11);
      if (0xf < uStack_94) {
        _free(pvStack_a8);
        return;
      }
      uVar2 = FUN_005256e0(uVar7,param_2,1);
      uStack_b0 = CONCAT31(uStack_b0._1_3_,uVar2);
      FUN_00512a90(puStack_b4 + 0x78,puStack_b4 + 0x94,uStack_b0,puStack_b4[0x116]);
      uVar2 = FUN_005257f0(uVar7);
      uStack_b0 = CONCAT31(uStack_b0._1_3_,uVar2);
      uStack_b0 = FUN_00526540(1,uStack_b0,&sStack_50);
      uVar14 = 0x606;
      if (uStack_b0 < 7) {
        uStack_94 = 0xf;
        uStack_98 = 0;
        pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
        pcVar4 = PTR_s_R_Weapon_00aed044;
        do {
          cVar15 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar15 != '\0');
        FUN_00401740(PTR_s_R_Weapon_00aed044,(int)pcVar4 - (int)(PTR_s_R_Weapon_00aed044 + 1));
        FUN_005129c0(auStack_ac,1,0,uStack_b0);
        if (0xf < uStack_94) {
          _free(pvStack_a8);
          return;
        }
        uVar14 = (undefined2)CONCAT31(6,(undefined1)uStack_b0);
      }
      if (*(short *)(puStack_b4 + 0xb0) != 0) {
        puStack_b4 = (undefined *)FUN_004dd240(0x1f,1,*(short *)(puStack_b4 + 0xb0),0,in_ECX[2]);
        FUN_00430ce0(&puStack_b4);
      }
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return;
      }
    }
  }
  sVar1 = sStack_50;
  if (sStack_50 != 0) {
    uVar7 = CONCAT22(sStack_4e,sStack_50);
    iVar8 = (**(code **)(*DAT_00b5a738 + 0x10))(uVar7);
    if (iVar8 != 0) {
      uVar12 = 0;
      uVar13 = uVar7;
      iVar8 = (**(code **)(*DAT_00b5a6dc + 8))(uStack_26,0,uVar7);
      FUN_00525d50(&uStack_2c,CONCAT22(extraout_var_01,uStack_32) & 0xffff00ff,
                   CONCAT22(extraout_var,*(undefined2 *)(iVar8 + 0x118)),uVar7,uStack_c,0);
      uStack_98 = CONCAT22(uStack_98._2_2_,sVar1);
      uStack_9c = 9;
      uStack_7c = 0xf;
      uStack_80 = 0;
      uStack_90 = 0;
      pcVar4 = PTR_DAT_00aed03c;
      do {
        cVar15 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar15 != '\0');
      FUN_00401740(PTR_DAT_00aed03c,(int)pcVar4 - (int)(PTR_DAT_00aed03c + 1));
      uStack_60 = 0xf;
      uStack_64 = 0;
      uStack_74 = uStack_74 & 0xffffff00;
      pcVar4 = PTR_s_L_Weapon_00aed048;
      do {
        cVar15 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar15 != '\0');
      FUN_00401740(PTR_s_L_Weapon_00aed048,(int)pcVar4 - (int)(PTR_s_L_Weapon_00aed048 + 1));
      uVar5 = (**(code **)(*DAT_00b5a7e4 + 4))(&uStack_2c,&uStack_9c,0);
      puVar11 = auStack_88;
      puVar10 = auStack_6c;
      FUN_00511d10(puVar10,puVar11,uVar5);
      FUN_00513030(puVar10,puVar11,uVar5,uVar12,uVar13);
      if (0xf < uStack_54) {
        _free(pvStack_68);
        return;
      }
      uStack_54 = 0xf;
      uStack_58 = 0;
      pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
      if (0xf < uStack_70) {
        _free(pvStack_84);
        return;
      }
      uStack_70 = 0xf;
      uStack_94 = 0xf;
      puStack_b4 = PTR_s_L_Weapon_00aed048 + 1;
      uStack_74 = 0;
      pvStack_84 = (void *)((uint)pvStack_84 & 0xffffff00);
      uStack_98 = 0;
      pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
      pcVar4 = PTR_s_L_Weapon_00aed048;
      do {
        cVar15 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar15 != '\0');
      FUN_00401740(PTR_s_L_Weapon_00aed048,(int)pcVar4 - (int)puStack_b4);
      puVar11 = auStack_ac;
      FUN_00511d10(puVar11);
      puStack_b4 = (undefined *)FUN_00512ca0(puVar11);
      if (0xf < uStack_94) {
        _free(pvStack_a8);
        return;
      }
      uVar2 = FUN_005256e0(uVar7,param_2,1);
      uStack_b0 = CONCAT31(uStack_b0._1_3_,uVar2);
      FUN_00512a90(iVar8 + 0x78,iVar8 + 0x94,uStack_b0,*(undefined1 *)(iVar8 + 0x116));
      uVar2 = FUN_005257f0(uVar7);
      uStack_b0 = CONCAT31(uStack_b0._1_3_,uVar2);
      uStack_b0 = FUN_00526540(0,uStack_b0,&sStack_50);
      if (uStack_b0 < 7) {
        uStack_94 = 0xf;
        uStack_98 = 0;
        pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
        pcVar4 = PTR_s_L_Weapon_00aed048;
        do {
          cVar15 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar15 != '\0');
        FUN_00401740(PTR_s_L_Weapon_00aed048,(int)pcVar4 - (int)(PTR_s_L_Weapon_00aed048 + 1));
        FUN_005129c0(auStack_ac,1,0,uStack_b0);
        if (0xf < uStack_94) {
          _free(pvStack_a8);
          return;
        }
        uVar14 = CONCAT11((undefined1)uStack_b0,(char)uVar14);
      }
      if (*(short *)(iVar8 + 0xb0) != 0) {
        puStack_b4 = (undefined *)FUN_004dd240(0x1f,1,*(short *)(iVar8 + 0xb0),0,in_ECX[2]);
        FUN_00430ce0(&puStack_b4);
      }
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return;
      }
    }
  }
  cVar15 = (char)((ushort)uVar14 >> 8);
  if ((*(char *)((int)in_ECX + 0x9d) != (char)uVar14) || (*(char *)((int)in_ECX + 0x9e) != cVar15))
  {
    puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      uVar7 = (**(code **)(*in_ECX + 8))();
      puVar6[2] = uVar7;
      *puVar6 = &PTR_FUN_009b80bc;
    }
    *(undefined2 *)(puVar6 + 1) = uVar14;
    FUN_00797a20(puVar6);
    *(char *)((int)in_ECX + 0x9e) = cVar15;
    *(char *)((int)in_ECX + 0x9d) = (char)uVar14;
    FUN_00401740(s_Left____d_Right__d_009b8030,0x14);
    uVar7 = FUN_00404230(auStack_20);
    FUN_00796d50(uVar7);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
  }
  return;
}


// ==== FUN_00527950 @ 0x00527950 ====

void FUN_00527950(void)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  byte bVar8;
  int *in_ECX;
  undefined4 unaff_EBX;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  int *unaff_retaddr;
  int aiStack_84 [11];
  int aiStack_58 [6];
  undefined4 uStack_40;
  int iStack_3c;
  int *piStack_38;
  int *piStack_34;
  int *piStack_30;
  undefined4 uStack_2c;
  uint3 uVar14;
  int iVar13;
  int *piStack_18;
  
  iVar3 = *(int *)in_ECX[3];
  uStack_2c = 0x527969;
  uStack_2c = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piStack_30 = (int *)0x527970;
  iVar3 = (**(code **)(iVar3 + 0x1c))();
  if (*(int **)(in_ECX[3] + 0x4c) == (int *)0x0) {
    piVar11 = (int *)0x0;
  }
  else {
    piStack_30 = (int *)0x527989;
    piVar11 = (int *)(**(code **)(**(int **)(in_ECX[3] + 0x4c) + 0x18))();
  }
  piStack_30 = (int *)0x527992;
  iVar4 = (**(code **)(*piVar11 + 0x10))();
  piStack_30 = (int *)0x5279a1;
  (**(code **)(*unaff_retaddr + 0xc))();
  if (*(int *)(iVar3 + 0x48) == 2) {
    piStack_30 = (int *)0x0;
  }
  else {
    if (*(int *)(iVar3 + 0x48) == 3) {
      piStack_30 = (int *)0x5279b9;
      cVar1 = FUN_00511d60();
      if (cVar1 != *(char *)((int)in_ECX + 0x31)) {
        piStack_30 = (int *)0x5279c5;
        cVar1 = FUN_00511d60();
        *(char *)((int)in_ECX + 0x31) = cVar1;
        if (cVar1 == '\x01') {
          *(undefined1 *)(in_ECX + 0xc) = 0;
        }
      }
      piStack_34 = (int *)0x5279d8;
      FUN_005269f0();
      *(undefined1 *)(in_ECX + 0xc) = 1;
      return;
    }
    piStack_30 = (int *)0x1;
  }
  piStack_34 = (int *)0x5279ef;
  FUN_00511f40();
  piVar10 = (int *)(iVar3 + 0x1a);
  uVar14 = (uint3)((uint)unaff_EBX >> 8);
  iVar13 = CONCAT31(uVar14,*(char *)(iVar3 + 0x76));
  piStack_18 = (int *)CONCAT31(piStack_18._1_3_,*(undefined1 *)(iVar4 + 10));
  bVar8 = 0;
  if (*(char *)(iVar3 + 0x76) != '\0') {
    piStack_30 = (int *)0x527a13;
    iVar5 = (**(code **)(*piVar11 + 0xc))();
    if (iVar5 == 8) {
      piStack_30 = (int *)0x0;
      iVar13 = (uint)uVar14 << 8;
      piStack_34 = (int *)0x527a27;
      (**(code **)(*(int *)in_ECX[3] + 0x40))();
    }
    bVar8 = (byte)iVar13;
    piStack_18 = (int *)((uint)piStack_18._1_3_ << 8);
  }
  piVar11 = (int *)((int)in_ECX + 0x3a);
  piVar9 = piVar10;
  piVar12 = aiStack_58;
  for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar12 = *piVar9;
    piVar9 = piVar9 + 1;
    piVar12 = piVar12 + 1;
  }
  piVar9 = piVar11;
  piVar12 = aiStack_84;
  for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar12 = *piVar9;
    piVar9 = piVar9 + 1;
    piVar12 = piVar12 + 1;
  }
  uVar2 = FUN_00525210((uint)bVar8,CONCAT31((int3)((uint)piVar11 >> 8),(char)in_ECX[0xe]),
                       *(undefined1 *)(iVar4 + 10));
  if ((uVar2 & 4) == 0) {
    if (uVar2 == 0) {
      if ((char)in_ECX[0xc] == '\x01') {
        piStack_34 = (int *)0x527b2f;
        FUN_00526470();
        piStack_34 = (int *)0x527b37;
        FUN_00526130();
        piStack_30 = (int *)0x527b42;
        puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
        if (puVar6 == (undefined4 *)0x0) {
          puVar6 = (undefined4 *)0x0;
        }
        else {
          piStack_30 = (int *)0x527b50;
          uVar7 = (**(code **)(*in_ECX + 8))();
          *puVar6 = &PTR_FUN_009b80a4;
          puVar6[1] = uVar7;
        }
        piStack_34 = (int *)0x527b63;
        piStack_30 = puVar6;
        FUN_00797a20();
        piStack_30 = (int *)in_ECX[2];
        piStack_34 = (int *)0x527b75;
        (**(code **)(*DAT_00b5ac6c + 0x1c))();
        uStack_40 = 0x527b87;
        FUN_00526670();
        uStack_40 = 0x527b95;
        iStack_3c = iVar13;
        FUN_00527220();
        piStack_34 = (int *)in_ECX[0xd];
        piStack_38 = (int *)in_ECX[2];
        iStack_3c = 0x527ba8;
        (**(code **)(*DAT_00b5ac70 + 0x20))();
        in_ECX[0xd] = 0;
        *(undefined1 *)(in_ECX + 0xc) = 0;
      }
      goto LAB_00527c33;
    }
    if ((uVar2 & 1) != 0) {
      piStack_34 = (int *)0x527bc1;
      FUN_00526470();
      iStack_3c = 0x527bd3;
      piStack_38 = piVar10;
      piStack_34 = unaff_retaddr;
      piStack_30 = (int *)iVar13;
      FUN_00526670();
    }
    if ((uVar2 & 2) == 0) goto LAB_00527c33;
    piStack_34 = (int *)0x527be3;
    FUN_00526130();
    piStack_30 = (int *)0x527bee;
    puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      piStack_30 = (int *)0x527bfc;
      uVar7 = (**(code **)(*in_ECX + 8))();
      *puVar6 = &PTR_FUN_009b80a4;
      puVar6[1] = uVar7;
    }
    piStack_34 = (int *)0x527c0f;
    piStack_30 = puVar6;
    FUN_00797a20();
    piStack_30 = (int *)in_ECX[2];
    piStack_34 = (int *)0x527c21;
    (**(code **)(*DAT_00b5ac6c + 0x1c))();
  }
  else {
    piStack_30 = in_ECX + 0x28;
    piStack_34 = (int *)0x527a8a;
    FUN_00525b80();
    piStack_30 = in_ECX + 0x2c;
    piStack_34 = (int *)0x527a98;
    FUN_00525b80();
    piStack_30 = (int *)0x527a9f;
    FUN_00511d10();
    piStack_30 = (int *)0x527aa6;
    FUN_00512da0();
    iStack_3c = 0x527ab8;
    piStack_38 = (int *)(uint)bVar8;
    piStack_34 = piVar10;
    FUN_00526c20();
    iStack_3c = 0x527ac6;
    piStack_38 = piVar10;
    piStack_30 = (int *)iVar13;
    FUN_00526670();
    piStack_30 = (int *)0x527ad1;
    puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      piStack_30 = (int *)0x527adf;
      uVar7 = (**(code **)(*in_ECX + 8))();
      *puVar6 = &PTR_FUN_009b80a4;
      puVar6[1] = uVar7;
    }
    piStack_34 = (int *)0x527af2;
    piStack_30 = puVar6;
    FUN_00797a20();
    piStack_30 = (int *)in_ECX[2];
    piStack_34 = (int *)0x527b04;
    (**(code **)(*DAT_00b5ac6c + 0x1c))();
  }
  piStack_38 = piStack_18;
  iStack_3c = 0x527c33;
  piStack_34 = piVar10;
  FUN_00527220();
LAB_00527c33:
  piStack_30 = (int *)0x527c3a;
  (**(code **)(*unaff_retaddr + 0x10))();
  *(undefined1 *)(in_ECX + 0xe) = *(undefined1 *)(iVar4 + 10);
  *(undefined1 *)((int)in_ECX + 0x39) = *(undefined1 *)(iVar3 + 0x76);
  for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar11 = *piVar10;
    piVar10 = piVar10 + 1;
    piVar11 = piVar11 + 1;
  }
  return;
}


// ==== FUN_00527c70 @ 0x00527c70 ====

undefined4 FUN_00527c70(void)

{
  return 0x60060020;
}


// ==== FUN_00527c80 @ 0x00527c80 ====

undefined4 FUN_00527c80(void)

{
  return 0x60060021;
}


// ==== FUN_00527c90 @ 0x00527c90 ====

void FUN_00527c90(byte param_1)

{
  void *in_ECX;
  
  FUN_00525c10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00527cb0 @ 0x00527cb0 ====

void FUN_00527cb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8148;
  in_ECX[0xc] = 0xf;
  in_ECX[0xb] = 0;
  *(undefined1 *)(in_ECX + 7) = 0;
  in_ECX[1] = 0;
  in_ECX[3] = 0xffffffff;
  in_ECX[4] = 0xffffff;
  in_ECX[5] = 0x38;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401740(s_No_Name_009b79ec,7);
  return;
}


// ==== FUN_00527d00 @ 0x00527d00 ====

undefined4 FUN_00527d00(void)

{
  return 0x7004000f;
}


// ==== FUN_00527d10 @ 0x00527d10 ====

void FUN_00527d10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8148;
  FUN_00713800();
  *in_ECX = &PTR_FUN_0099cf40;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00527d40 @ 0x00527d40 ====

undefined4 FUN_00527d40(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_0053f650(param_1,param_2);
  return uVar2;
}


// ==== FUN_00527d70 @ 0x00527d70 ====

float10 FUN_00527d70(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x2c);
}


// ==== FUN_00527d80 @ 0x00527d80 ====

void FUN_00527d80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8184;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00527da0 @ 0x00527da0 ====

undefined1 FUN_00527da0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x3c);
}


// ==== FUN_00527db0 @ 0x00527db0 ====

void FUN_00527db0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x3c) = param_1;
  return;
}


// ==== FUN_00527dc0 @ 0x00527dc0 ====

void FUN_00527dc0(undefined2 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined2 *)(in_ECX + 0x3e);
  return;
}


// ==== FUN_00527dd0 @ 0x00527dd0 ====

void FUN_00527dd0(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x3e) = *param_1;
  return;
}


// ==== FUN_00527de0 @ 0x00527de0 ====

void FUN_00527de0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x48) == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00527df0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(**(int **)(in_ECX + 0x44) + 8) + 0xc))();
  return;
}


// ==== FUN_00527e00 @ 0x00527e00 ====

undefined4 FUN_00527e00(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x48) == 0) {
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x00527e10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(**(int **)(in_ECX + 0x44) + 8) + 8))();
  return uVar1;
}


// ==== FUN_00527e20 @ 0x00527e20 ====

undefined4 FUN_00527e20(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x48) == 0) {
    return 0;
  }
  return *(undefined4 *)(**(int **)(in_ECX + 0x44) + 8);
}


// ==== __break @ 0x00527e3d ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00527e40 @ 0x00527e40 ====

void FUN_00527e40(void)

{
  uint in_ECX;
  uint local_4;
  
  if ((*(int *)(in_ECX + 0x48) == 0) || (*(int *)(in_ECX + 0x48) == 0)) {
    return;
  }
  local_4 = in_ECX & 0xffffff00;
  FUN_00528030(**(undefined4 **)(in_ECX + 0x44),*(undefined4 **)(in_ECX + 0x44),local_4);
  FUN_00510b80();
  return;
}


// ==== FUN_00527e80 @ 0x00527e80 ====

void FUN_00527e80(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b81c4;
  *(undefined1 *)(in_ECX + 0xf) = 0;
  uVar2 = FUN_005170b0();
  uVar1 = DAT_0099d080;
  in_ECX[0x11] = uVar2;
  in_ECX[0x12] = 0;
  in_ECX[3] = 100;
  in_ECX[4] = 100;
  in_ECX[6] = 0;
  uVar2 = DAT_0099d0f8;
  in_ECX[9] = uVar1;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = uVar2;
  in_ECX[0xe] = 0;
  in_ECX[10] = 0;
  in_ECX[0xc] = 0;
  return;
}


// ==== FUN_00527f80 @ 0x00527f80 ====

uint FUN_00527f80(void)

{
  int *_Memory;
  uint in_EAX;
  uint extraout_EAX;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x48) == 0) {
    return in_EAX & 0xffffff00;
  }
  _Memory = (int *)**(int **)(in_ECX + 0x44);
  if (_Memory == *(int **)(in_ECX + 0x44)) {
    return CONCAT31((int3)((uint)_Memory >> 8),1);
  }
  *(int *)_Memory[1] = *_Memory;
  *(int *)(*_Memory + 4) = _Memory[1];
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_00527fc0 @ 0x00527fc0 ====

void FUN_00527fc0(int param_1)

{
  int in_ECX;
  
  FUN_005280c0(*(undefined4 *)(in_ECX + 0x44),**(undefined4 **)(param_1 + 4),
               *(undefined4 **)(param_1 + 4),param_1);
  return;
}


// ==== FUN_00527ff0 @ 0x00527ff0 ====

void FUN_00527ff0(undefined1 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x44);
  iVar2 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_1);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}


// ==== FUN_00528030 @ 0x00528030 ====

undefined1 FUN_00528030(undefined4 *param_1,undefined4 *param_2,undefined1 param_3)

{
  for (; param_1 != param_2; param_1 = (undefined4 *)*param_1) {
    if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[2])(1);
    }
  }
  return param_3;
}


// ==== FUN_00528060 @ 0x00528060 ====

void FUN_00528060(byte param_1)

{
  undefined4 *in_ECX;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b81c4;
  if (in_ECX[0x12] != 0) {
    local_4 = (uint)in_ECX & 0xffffff00;
    FUN_00528030(*(undefined4 *)in_ECX[0x11],(undefined4 *)in_ECX[0x11],local_4);
    FUN_00510b80();
  }
  FUN_008984a0();
  *in_ECX = &PTR_FUN_009b8184;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005280c0 @ 0x005280c0 ====

void FUN_005280c0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981900;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != param_3; param_2 = (undefined4 *)*param_2) {
    FUN_00517290(param_1,param_2 + 2);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00528128 @ 0x00528128 ====

void Catch_00528128(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  
  puVar2 = *(undefined4 **)(unaff_EBP + 0xc);
  for (puVar1 = *(undefined4 **)(unaff_EBP + -0x14); puVar1 != puVar2;
      puVar1 = (undefined4 *)*puVar1) {
    FUN_005171c0(unaff_EBP + -0x1c,*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00528160 @ 0x00528160 ====

undefined1 FUN_00528160(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_005281b0 @ 0x005281b0 ====

void FUN_005281b0(void)

{
  return;
}


// ==== FUN_00528200 @ 0x00528200 ====

void FUN_00528200(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  char cVar3;
  undefined1 uStack00000000;
  undefined1 auStackY_9c [128];
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
  (**(code **)(*piVar1 + 0x4c))(param_1);
  piVar1 = (int *)(**(code **)(*DAT_00b5a6fc + 8))();
  if (piVar1 != (int *)0x0) {
    cVar3 = (char)param_1;
    if ((*(char *)(in_ECX + 4) == '\0') && (cVar3 == '\x01')) {
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
      (**(code **)(*piVar2 + 0x28))(1);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
      (**(code **)(*piVar2 + 8))();
      (**(code **)(*piVar1 + 0x54))(auStackY_9c + 0x98,*(undefined4 *)(in_ECX + 0xc));
      *(undefined1 *)(in_ECX + 4) = 1;
      return;
    }
    if ((*(char *)(in_ECX + 4) == '\x01') && (cVar3 == '\0')) {
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
      (**(code **)(*piVar2 + 8))();
      (**(code **)(*piVar1 + 0x58))(&uStack00000000);
    }
    *(char *)(in_ECX + 4) = cVar3;
  }
  return;
}


// ==== FUN_005282b0 @ 0x005282b0 ====

void FUN_005282b0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  undefined4 auStack_8 [2];
  
  if (*(char *)(in_ECX + 4) != '\0') {
    piVar1 = (int *)(**(code **)(*DAT_00b5a6fc + 8))();
    if (piVar1 == (int *)0x0) {
      return;
    }
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    auStack_8[0] = (**(code **)(*piVar2 + 8))();
    iVar3 = (**(code **)(*piVar1 + 0x30))(auStack_8);
    if (iVar3 == 0) {
      return;
    }
    (**(code **)(*piVar1 + 0x40))(iVar3);
  }
  piVar1 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
  if (piVar1 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    auStack_8[0] = (**(code **)(*piVar2 + 8))();
    piVar2 = (int *)(**(code **)(*piVar1 + 0x30))(auStack_8);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*DAT_00b5a6f8 + 0x10))(1,*(undefined4 *)(*piVar2 + 4));
      (**(code **)(*piVar1 + 0x40))(piVar2);
      *(undefined1 *)(in_ECX + 4) = 0;
    }
  }
  return;
}


// ==== FUN_00528360 @ 0x00528360 ====

void FUN_00528360(void)

{
  float *pfVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  pfVar1 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
  if ((((0.0 <= *pfVar1) && (*pfVar1 <= DAT_009b8324)) && (0.0 <= pfVar1[1])) &&
     (pfVar1[1] <= DAT_009b8324)) {
    puVar2 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
    uStack_8 = *puVar2;
    iVar3 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))();
    uStack_4 = *(undefined4 *)(iVar3 + 4);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
    (**(code **)(*piVar4 + 0x40))(&uStack_8);
  }
  return;
}


// ==== FUN_00528420 @ 0x00528420 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00528420(float param_1)

{
  float fVar1;
  float fVar2;
  
  if ((int)param_1 < 100) {
    fVar2 = (float)(int)param_1 * DAT_009a09b8;
    fVar1 = DAT_0099d0f8;
  }
  else {
    fVar2 = ((float)(int)param_1 - DAT_0099de78) * _DAT_009b832c;
    fVar1 = DAT_0099d080;
  }
  fVar1 = fVar1 - fVar2;
  if (DAT_0099d0f8 < fVar1) {
    return (float10)DAT_0099d0f8;
  }
  param_1 = DAT_009b8328;
  if (DAT_009b8328 <= fVar1) {
    param_1 = fVar1;
  }
  return (float10)param_1;
}


// ==== FUN_005284a0 @ 0x005284a0 ====

void FUN_005284a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8334;
  FUN_005282b0();
  *in_ECX = &PTR_FUN_009b7ed4;
  return;
}


// ==== FUN_005284c0 @ 0x005284c0 ====

void FUN_005284c0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 auStack_a [10];
  
  piVar2 = DAT_00b5a780;
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x1c))();
  piVar2 = (int *)(**(code **)(*piVar2 + 8))(iVar1 + 0x14);
  if (piVar2 == (int *)0x0) {
    return;
  }
  (**(code **)(*piVar2 + 0xc))(auStack_a + -6);
  return;
}


// ==== FUN_00528540 @ 0x00528540 ====

void FUN_00528540(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined1 uStack00000000;
  undefined4 auStack_8 [2];
  
  piVar3 = (int *)(**(code **)(*DAT_00b5a6fc + 8))();
  if (piVar3 != (int *)0x0) {
    auStack_8[0] = param_1[1];
    piVar3 = (int *)(**(code **)(*piVar3 + 0x30))(auStack_8);
    if ((piVar3 != (int *)0x0) && (*(int **)(*piVar3 + 4) != (int *)0x0)) {
      (**(code **)(**(int **)(*piVar3 + 4) + 0x3c))(&uStack00000000);
      uVar1 = param_1[2];
      uVar2 = *param_1;
      puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1,0);
      *puVar4 = 0xc;
      puVar4[1] = uVar2;
      puVar4[2] = uVar1;
      (**(code **)(*DAT_00b5a804 + 0xc))(param_1[1],puVar4);
      (**(code **)(*DAT_00b5a70c + 0x10))(1,puVar4);
    }
  }
  return;
}


// ==== FUN_005285e0 @ 0x005285e0 ====

uint FUN_005285e0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x70004) {
    uVar1 = FUN_00403620(0,param_1[7],s_enemy_monster_009b8220,0xd);
    if (uVar1 == 0) {
      return 1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00528620 @ 0x00528620 ====

void FUN_00528620(int *param_1)

{
  uint uVar1;
  uint *puVar2;
  undefined2 *puVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  undefined4 *in_ECX;
  undefined4 uStack_e4;
  TypeDescriptor *pTStack_e0;
  TypeDescriptor *pTStack_dc;
  uint uStack_bc;
  undefined4 uStack_b8;
  uint uStack_b4;
  uint uStack_b0;
  uint uStack_ac;
  undefined4 uStack_a8;
  uint uStack_a4;
  undefined4 uStack_a0;
  uint uStack_9c;
  undefined4 uStack_98;
  uint uStack_94;
  undefined4 uStack_90;
  uint uStack_8c;
  undefined4 uStack_88;
  uint uStack_84;
  undefined4 uStack_80;
  void *pvStack_64;
  undefined2 auStack_5c [2];
  undefined4 uStack_58;
  int iStack_54;
  uint uStack_50;
  uint uStack_40;
  uint uStack_38;
  undefined1 uStack_34;
  undefined1 uStack_33;
  undefined4 auStack_18 [6];
  
  *in_ECX = &PTR_FUN_009b8334;
  in_ECX[2] = param_1;
  *(undefined1 *)(in_ECX + 1) = 0;
  puVar2 = (uint *)(**(code **)(*param_1 + 0x28))();
  uVar1 = *puVar2;
  uStack_b0 = puVar2[1];
  pTStack_dc = (TypeDescriptor *)&uStack_bc;
  uStack_ac = 0;
  pTStack_e0 = (TypeDescriptor *)0x528688;
  uStack_b4 = uVar1;
  FUN_004ef0e0();
  pTStack_dc = (TypeDescriptor *)0x52868f;
  puVar3 = (undefined2 *)FUN_005e0c90();
  *(undefined2 *)((int)in_ECX + 6) = *puVar3;
  piVar4 = (int *)(**(code **)(*param_1 + 0x14))();
  uVar5 = (**(code **)(*piVar4 + 0x24))();
  pTStack_dc = &Framework::Creature::IMonster::RTTI_Type_Descriptor;
  pTStack_e0 = &Framework::ICreature::RTTI_Type_Descriptor;
  uStack_e4 = 0;
  piVar4 = (int *)FUN_00803725(uVar5);
  if (piVar4 == (int *)0x0) {
    pTStack_dc = (TypeDescriptor *)s_Invalid_Actor_Info_009b820c;
    uStack_50 = 0xf;
    iStack_54 = 0;
    pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
    pTStack_e0 = (TypeDescriptor *)0x5286e5;
    FUN_00401740();
    pTStack_dc = (TypeDescriptor *)0x5286ef;
    FUN_00796d50();
    if (0xf < uStack_50) {
      pTStack_dc = (TypeDescriptor *)0x52870a;
      _free(pvStack_64);
      return;
    }
  }
  else {
    pTStack_dc = (TypeDescriptor *)0x0;
    pTStack_e0 = (TypeDescriptor *)0x528725;
    piVar6 = (int *)(**(code **)(*(int *)piVar4[0x14] + 0x14))();
    pTStack_e0 = (TypeDescriptor *)0x52872e;
    puVar3 = (undefined2 *)(**(code **)(*piVar4 + 0x24))();
    pTStack_e0 = (TypeDescriptor *)0x0;
    uStack_e4 = 1;
    uStack_bc = uVar1;
    uVar5 = (**(code **)(*DAT_00b5a6f8 + 0xc))();
    in_ECX[3] = uVar5;
    piVar4 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x14))();
    auStack_18[0] = (**(code **)(*piVar4 + 8))();
    piVar4 = (int *)(**(code **)(*(int *)in_ECX[3] + 0xc))();
    (**(code **)(*piVar4 + 0x10))(auStack_18);
    auStack_5c[0] = puVar3[0x26];
    uStack_58 = 1;
    iVar7 = (**(code **)(*piVar6 + 8))();
    iStack_54 = (int)*(float *)(iVar7 + 0xc);
    uStack_50 = *(uint *)(puVar3 + 0x28);
    uStack_34 = 0;
    uStack_33 = 0;
    uStack_40 = uVar1;
    uStack_38 = uVar1;
    piVar4 = (int *)(**(code **)(*(int *)in_ECX[3] + 0xc))();
    (**(code **)(*piVar4 + 0x14))(auStack_5c);
    uStack_bc = (uint)*(byte *)(puVar3 + 0xb2);
    uStack_b8 = *(undefined4 *)(puVar3 + 0xb4);
    uStack_b4 = (uint)*(byte *)(puVar3 + 0xe6);
    uStack_b0 = *(uint *)(puVar3 + 0xe8);
    uStack_ac = (uint)*(byte *)(puVar3 + 0xcc);
    uStack_a8 = *(undefined4 *)(puVar3 + 0xce);
    uStack_a4 = (uint)*(byte *)(puVar3 + 0x100);
    uStack_a0 = *(undefined4 *)(puVar3 + 0x102);
    uStack_9c = (uint)*(byte *)(puVar3 + 0x134);
    uStack_98 = *(undefined4 *)(puVar3 + 0x136);
    uStack_94 = (uint)*(byte *)(puVar3 + 0x11a);
    uStack_90 = *(undefined4 *)(puVar3 + 0x11c);
    uStack_8c = (uint)*(byte *)(puVar3 + 0x11a);
    uStack_88 = *(undefined4 *)(puVar3 + 0x11c);
    uStack_84 = (uint)*(byte *)(puVar3 + 0x168);
    uStack_80 = *(undefined4 *)(puVar3 + 0x16a);
    piVar4 = (int *)(**(code **)(*(int *)in_ECX[3] + 0xc))();
    (**(code **)(*piVar4 + 0x18))(&uStack_bc);
    uVar5 = (**(code **)(*DAT_00b5a6f4 + 8))(puVar3[0xa2]);
    piVar4 = (int *)(**(code **)(*(int *)in_ECX[3] + 0x28))();
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 4))(uVar5);
    }
    piVar4 = (int *)(**(code **)(*DAT_00b5a714 + 8))(*puVar3);
    uVar5 = (**(code **)(*piVar4 + 8))();
    (**(code **)(*(int *)in_ECX[3] + 0x44))(uVar5);
    piVar4 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
    piVar6 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x14))();
    uStack_e4 = (**(code **)(*piVar6 + 8))();
    (**(code **)(*piVar4 + 0x54))(&uStack_e4,in_ECX[3]);
    (**(code **)(*(int *)in_ECX[2] + 0x28))();
  }
  return;
}


// ==== FUN_00528950 @ 0x00528950 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00528950(int param_1)

{
  int iVar1;
  int *piVar2;
  float *pfVar3;
  float *pfVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int in_ECX;
  int unaff_ESI;
  undefined2 in_FPUControlWord;
  float10 fVar9;
  undefined1 auStack_56 [6];
  float fStack_50;
  float fStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  float fStack_40;
  undefined1 auStack_3c [4];
  undefined4 uStack_38;
  undefined2 uStack_34;
  undefined2 uStack_30;
  undefined1 uStack_2e;
  int iStack_2d;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    iVar1 = FUN_005284c0(0,*(undefined4 *)(param_1 + 0xc));
    if (iVar1 == 0) {
      (**(code **)(**(int **)(in_ECX + 8) + 0x1c))();
      FUN_00401740(s_Cannot_Find__u_Monster__u__Attac_009b8230,0x28);
      FUN_00404230(auStack_1c);
      FUN_00796d50(auStack_1c);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
    }
    else {
      piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 8));
      if (piVar2 == (int *)0x0) {
        (**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
        return;
      }
      pfVar3 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
      pfVar4 = (float *)(**(code **)(*piVar2 + 0x28))();
      fStack_50 = *pfVar4 - *pfVar3;
      fStack_4c = pfVar4[1] - pfVar3[1];
      if (SQRT(fStack_4c * fStack_4c + fStack_50 * fStack_50) <= _DAT_009b8320) {
        pfVar3 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
        fStack_50 = *pfVar3;
        fStack_4c = pfVar3[1];
      }
      else {
        thunk_FUN_0079de77(&uStack_48,&fStack_50);
      }
      pfVar3 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
      if ((((0.0 <= *pfVar3) && (*pfVar3 <= DAT_009b8324)) && (0.0 <= pfVar3[1])) &&
         (pfVar3[1] <= DAT_009b8324)) {
        puVar5 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
        uStack_48 = *puVar5;
        iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))();
        uStack_44 = *(undefined4 *)(iVar1 + 4);
        fVar9 = (float10)FUN_0040d5f0(&fStack_50);
        fStack_40 = (float)fVar9;
        iVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        FUN_004eef40(auStack_3c,iVar1,0);
        puVar5 = (undefined4 *)FUN_004ef0e0(auStack_56 + -10);
        uStack_38 = *puVar5;
        uStack_2e = *(undefined1 *)(param_1 + 0xc);
        uStack_34 = *(undefined2 *)(puVar5 + 1);
        uStack_30 = FUN_004eefa0(uStack_8);
        iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
        fVar9 = (float10)FUN_00528420(*(undefined4 *)(iVar6 + 0xc));
        uStack_8 = CONCAT22(uStack_8._2_2_,in_FPUControlWord);
        iStack_2d = iVar1 - (int)ROUND(fVar9 * (float10)*(float *)(unaff_ESI + 0x114) *
                                       (float10)DAT_0099d0f4);
        puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          *puVar5 = &PTR_FUN_009b2d88;
        }
        piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
        uVar7 = (**(code **)(*piVar2 + 8))();
        puVar5[1] = uVar7;
        FUN_00403e60(puVar5 + 2,auStack_3c,0x19);
        FUN_00797a20(puVar5);
        piVar2 = (int *)(**(code **)(*DAT_00b5a77c + 8))(*(undefined4 *)(param_1 + 8));
        iVar1 = FUN_005295b0(iVar1);
        piVar8 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
        uVar7 = (**(code **)(*piVar8 + 8))();
        *(undefined4 *)(iVar1 + 0x10) = uVar7;
        puVar5 = (undefined4 *)(**(code **)(*piVar2 + 8))();
        *(undefined4 *)(iVar1 + 0x2d) = *puVar5;
        *(undefined4 *)(iVar1 + 0x31) = puVar5[1];
        (**(code **)(*DAT_00b5a77c + 0x18))(piVar2);
        FUN_00403e60(iVar1 + 0x14,&uStack_44,0x13);
        FUN_004d8570(iVar1);
      }
    }
  }
  return;
}


// ==== FUN_00528c90 @ 0x00528c90 ====

void FUN_00528c90(int param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  float *pfVar6;
  undefined4 *puVar7;
  int in_ECX;
  float10 fVar8;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined2 uStack_2c;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined4 uStack_28;
  undefined4 uStack_24;
  float fStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    local_44 = *(float *)(param_1 + 8);
    local_40 = *(float *)(param_1 + 0xc);
    if ((((0.0 <= local_44) && (local_44 <= DAT_009b8324)) && (0.0 <= local_40)) &&
       (local_40 <= DAT_009b8324)) {
      local_3c = local_44;
      local_38 = local_40;
      uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar2 = operator_new(0x400);
      *(undefined4 *)((int)pvVar2 + 8) = uVar1;
      *(undefined4 *)((int)pvVar2 + 0xc) = 0x50d0000;
      *(undefined2 *)((int)pvVar2 + 6) = 0x30;
      iVar3 = FUN_004244d0();
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
      uVar5 = (**(code **)(*piVar4 + 8))();
      *(undefined4 *)(iVar3 + 0x10) = uVar5;
      FUN_00797a50(&uStack_34,0,0xc);
      uStack_29 = 1;
      uStack_2a = 0;
      uStack_34 = uVar1;
      pfVar6 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
      local_3c = *pfVar6;
      uStack_28 = *(undefined4 *)(param_1 + 8);
      local_38 = pfVar6[1];
      uStack_24 = *(undefined4 *)(param_1 + 0xc);
      fVar8 = (float10)FUN_0040d5f0(&local_3c);
      fStack_20 = (float)fVar8;
      puVar7 = (undefined4 *)FUN_004ef0e0(&local_44);
      uStack_30 = *puVar7;
      uStack_2c = *(undefined2 *)(puVar7 + 1);
      puVar7 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        *puVar7 = &PTR_FUN_009b2d88;
      }
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
      uVar1 = (**(code **)(*piVar4 + 8))();
      puVar7[1] = uVar1;
      FUN_00403e60(puVar7 + 2,&uStack_34,0x19);
      FUN_00797a20(puVar7);
      FUN_00403e60(iVar3 + 0x14,&uStack_34,0xc);
      FUN_004d8570(iVar3);
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      FUN_00401740(s_______________________________Mo_009b825c,0x30);
      FUN_00796d50(auStack_1c);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
    }
  }
  return;
}


// ==== FUN_00528e80 @ 0x00528e80 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00528e80(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  int *piVar10;
  int in_ECX;
  undefined2 in_FPUControlWord;
  float10 fVar11;
  undefined1 auStack_52 [6];
  float fStack_4c;
  float fStack_48;
  float local_44;
  float local_40;
  float fStack_3c;
  undefined1 auStack_38 [4];
  undefined4 uStack_34;
  undefined2 uStack_30;
  undefined2 uStack_2c;
  undefined1 uStack_2a;
  int iStack_29;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    iVar3 = FUN_005284c0(0,7);
    if (iVar3 == 0) {
      (**(code **)(**(int **)(in_ECX + 8) + 0x1c))();
      FUN_00401740(s_Cannot_Find__u_Monster__u__Attac_009b8290,0x28);
      FUN_00404230(auStack_1c);
      FUN_00796d50(auStack_1c);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
    }
    else {
      fVar1 = *(float *)(param_1 + 8);
      fVar2 = *(float *)(param_1 + 0xc);
      if ((((0.0 <= fVar1) && (fVar1 <= DAT_009b8324)) && (0.0 <= fVar2)) && (fVar2 <= DAT_009b8324)
         ) {
        local_44 = fVar1;
        local_40 = fVar2;
        pfVar4 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
        local_44 = *pfVar4;
        local_40 = pfVar4[1];
        if (((0.0 <= local_44) && (local_44 <= DAT_009b8324)) &&
           ((0.0 <= local_40 && (local_40 <= DAT_009b8324)))) {
          pfVar4 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
          fStack_4c = fVar1 - *pfVar4;
          fStack_48 = fVar2 - pfVar4[1];
          if (SQRT(fStack_48 * fStack_48 + fStack_4c * fStack_4c) <= _DAT_009b8320) {
            pfVar4 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
            local_40 = *pfVar4;
            fStack_3c = pfVar4[1];
          }
          else {
            thunk_FUN_0079de77(auStack_38,&fStack_4c);
          }
          pfVar4 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
          fStack_4c = *pfVar4;
          iVar5 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))();
          fStack_48 = *(float *)(iVar5 + 4);
          fVar11 = (float10)FUN_0040d5f0(&local_40);
          local_44 = (float)fVar11;
          iVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
          FUN_004eef40(auStack_38,iVar5,0);
          puVar6 = (undefined4 *)FUN_004ef0e0(auStack_52 + -10);
          uStack_34 = *puVar6;
          uStack_30 = *(undefined2 *)(puVar6 + 1);
          uStack_2a = 7;
          uStack_2c = FUN_004eefa0(uStack_4);
          iVar7 = (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
          fVar11 = (float10)FUN_00528420(*(undefined4 *)(iVar7 + 0xc));
          uStack_4 = CONCAT22(uStack_4._2_2_,in_FPUControlWord);
          iStack_29 = iVar5 - (int)ROUND(fVar11 * (float10)*(float *)(iVar3 + 0x114) *
                                         (float10)DAT_0099d0f4);
          puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
          if (puVar6 == (undefined4 *)0x0) {
            puVar6 = (undefined4 *)0x0;
          }
          else {
            *puVar6 = &PTR_FUN_009b2d88;
          }
          piVar8 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
          uVar9 = (**(code **)(*piVar8 + 8))();
          puVar6[1] = uVar9;
          FUN_00403e60(puVar6 + 2,auStack_38,0x19);
          FUN_00797a20(puVar6);
          fStack_4c = *(float *)(param_1 + 8);
          fStack_48 = *(float *)(param_1 + 0xc);
          iVar3 = *DAT_00b5a77c;
          local_44 = 0.0;
          uVar9 = FUN_004ef0e0(auStack_52 + -10);
          piVar8 = (int *)(**(code **)(iVar3 + 4))(uVar9);
          iVar3 = FUN_005295b0(iVar5);
          piVar10 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
          uVar9 = (**(code **)(*piVar10 + 8))();
          *(undefined4 *)(iVar3 + 0x10) = uVar9;
          puVar6 = (undefined4 *)(**(code **)(*piVar8 + 8))();
          *(undefined4 *)(iVar3 + 0x2d) = *puVar6;
          *(undefined4 *)(iVar3 + 0x31) = puVar6[1];
          (**(code **)(*DAT_00b5a77c + 0x18))(piVar8);
          FUN_00403e60(iVar3 + 0x14,&local_40,0x13);
          FUN_004d8570(iVar3);
          FUN_00401830(s_______________________________Mo_009b82bc);
          FUN_00796d50(&uStack_2c);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
      }
    }
  }
  return;
}


// ==== FUN_00529230 @ 0x00529230 ====

/* WARNING: Removing unreachable block (ram,0x0052932b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00529230(float param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  int in_ECX;
  char *pcVar5;
  float10 fVar6;
  float10 extraout_ST0;
  float fVar7;
  float fVar8;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  uint uStack_8;
  
  if (99 < param_2) {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    fVar6 = (float10)(**(code **)(*piVar2 + 0x18))(param_1);
    fVar7 = (param_1 - DAT_0099de78) * _DAT_009b836c + DAT_0099d080;
    fVar8 = DAT_009b8368;
    if ((DAT_009b8368 < fVar7) || (fVar8 = DAT_009a09b8, fVar7 < DAT_009a09b8)) {
      fVar7 = fVar8;
    }
    fVar7 = fVar7 * (float)fVar6;
    goto LAB_005293c2;
  }
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  fVar6 = (float10)(**(code **)(*piVar2 + 0x18))(param_1);
  fVar7 = param_1 * _DAT_009b836c + DAT_009a09b8;
  if (fVar7 <= DAT_009b8368) {
    fVar8 = DAT_009a09b8;
    if (DAT_009a09b8 <= fVar7) goto LAB_00529297;
  }
  else {
    fVar7 = DAT_009b8368;
LAB_00529297:
    fVar8 = fVar7;
  }
  fVar7 = (float)((float10)fVar8 * fVar6);
  FUN_00401740(s___1f_speed_set_009b82f0,0xe);
  iVar3 = FUN_00404230(auStack_20);
  if (*(uint *)(iVar3 + 0x18) < 0x10) {
    pcVar5 = (char *)(iVar3 + 4);
  }
  else {
    pcVar5 = *(char **)(iVar3 + 4);
  }
  pcVar4 = pcVar5;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar5,(int)pcVar4 - (int)(pcVar5 + 1));
  FUN_00796d50();
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return extraout_ST0;
  }
LAB_005293c2:
  return (float10)fVar7;
}


// ==== FUN_005293d0 @ 0x005293d0 ====

void FUN_005293d0(int param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  float *pfVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  void *pvVar9;
  int in_ECX;
  float10 fVar10;
  float fStack_48;
  float fStack_44;
  undefined1 auStack_40 [16];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  float fStack_28;
  float fStack_24;
  undefined4 uStack_20;
  undefined1 uStack_1c;
  float fStack_18;
  float fStack_14;
  undefined4 uStack_10;
  float fStack_c;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    fVar1 = *(float *)(param_1 + 0xc);
    fVar2 = *(float *)(param_1 + 0x10);
    if ((((0.0 <= fVar1) && (fVar1 <= DAT_009b8324)) && (0.0 <= fVar2)) && (fVar2 <= DAT_009b8324))
    {
      fStack_48 = fVar1;
      fStack_44 = fVar2;
      pfVar4 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
      fStack_44 = fVar2 - pfVar4[1];
      fStack_48 = fVar1 - *pfVar4;
      thunk_FUN_0079de77(auStack_40,&fStack_48);
      puVar5 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
      uStack_30 = *puVar5;
      uStack_2c = puVar5[1];
      fStack_28 = fStack_48;
      fStack_18 = fStack_48;
      fStack_24 = fStack_44;
      fStack_14 = fStack_44;
      uStack_1c = 0;
      uStack_10 = CONCAT31(uStack_10._1_3_,*(char *)(param_1 + 8) == '\x01');
      uStack_20 = uVar3;
      iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
      fVar10 = (float10)FUN_00529230(uStack_10,*(undefined4 *)(iVar6 + 0x10));
      fStack_c = (float)fVar10;
      FUN_00507870(&uStack_30,auStack_40);
      puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        *puVar5 = &PTR_FUN_009b2d88;
      }
      piVar7 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
      uVar8 = (**(code **)(*piVar7 + 8))();
      puVar5[1] = uVar8;
      FUN_00403e60(puVar5 + 2,auStack_40,0x19);
      FUN_00797a20(puVar5);
      pvVar9 = operator_new(0x400);
      *(undefined4 *)((int)pvVar9 + 8) = uVar3;
      *(undefined4 *)((int)pvVar9 + 0xc) = 0x50d0000;
      *(undefined2 *)((int)pvVar9 + 6) = 0x30;
      iVar6 = FUN_004244d0();
      piVar7 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
      uVar3 = (**(code **)(*piVar7 + 8))();
      *(undefined4 *)(iVar6 + 0x10) = uVar3;
      FUN_00403e60(iVar6 + 0x14,auStack_40,0x10);
      FUN_004d8570(iVar6);
    }
  }
  return;
}


// ==== FUN_005295b0 @ 0x005295b0 ====

void FUN_005295b0(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0xe010002;
  *(undefined2 *)((int)pvVar1 + 6) = 0x38;
  FUN_004244d0();
  return;
}


// ==== FUN_005295e0 @ 0x005295e0 ====

void FUN_005295e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8334;
  FUN_005282b0();
  *in_ECX = &PTR_FUN_009b7ed4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00529610 @ 0x00529610 ====

undefined4 FUN_00529610(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00529620 @ 0x00529620 ====

void FUN_00529620(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00529630 @ 0x00529630 ====

void FUN_00529630(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x20) = param_1;
  return;
}


// ==== FUN_00529640 @ 0x00529640 ====

undefined4 FUN_00529640(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_00529650 @ 0x00529650 ====

undefined4 FUN_00529650(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_00529670 @ 0x00529670 ====

undefined1 FUN_00529670(void)

{
  return 0;
}


// ==== FUN_00529680 @ 0x00529680 ====

undefined4 FUN_00529680(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x14) + 0x48);
}


// ==== FUN_00529690 @ 0x00529690 ====

undefined4 FUN_00529690(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x14) + 0x48);
}


// ==== FUN_005296a0 @ 0x005296a0 ====

void FUN_005296a0(void)

{
  undefined2 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 0x10) + 0x1c))();
  FUN_004dd240(0,2,1,*puVar1,*(undefined4 *)(in_ECX + 8));
  return;
}


// ==== FUN_005296d0 @ 0x005296d0 ====

void FUN_005296d0(void)

{
  undefined2 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 0x10) + 0x1c))();
  FUN_004dd320(0,3,1,*puVar1,*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0x18));
  *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
  if (1 < *(uint *)(in_ECX + 0x18)) {
    *(undefined4 *)(in_ECX + 0x18) = 0;
  }
  return;
}


// ==== FUN_00529710 @ 0x00529710 ====

void FUN_00529710(char param_1,int *param_2,int *param_3)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x1c))();
  if ((((iVar1 == 3) && (param_1 == '\0')) && (*param_2 != 3)) &&
     (in_ECX[10] = in_ECX[10] + *param_3, 799 < (uint)in_ECX[10])) {
    FUN_004dd240(0x1a,1,0,in_ECX[9],in_ECX[2]);
    in_ECX[9] = in_ECX[9] + 1;
    in_ECX[10] = 0;
    if (1 < (uint)in_ECX[9]) {
      in_ECX[9] = 0;
    }
  }
  return;
}


// ==== FUN_00529770 @ 0x00529770 ====

void FUN_00529770(void)

{
  undefined2 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 0x10) + 0x1c))();
  FUN_004dd240(0,4,1,*puVar1,*(undefined4 *)(in_ECX + 8));
  return;
}


// ==== FUN_005297a0 @ 0x005297a0 ====

void FUN_005297a0(int param_1)

{
  undefined4 uVar1;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0x34))(0,in_ECX[2]);
  FUN_004dd240(3,param_1,uVar1);
  if ((param_1 < 3) || (0xb < param_1)) {
    FUN_004dd320(0x15,2,0,1,in_ECX[2],0);
    return;
  }
  FUN_004dd320(0x15,2,0,0,in_ECX[2],0);
  return;
}


// ==== FUN_00529800 @ 0x00529800 ====

void FUN_00529800(void)

{
  int iVar1;
  undefined2 *puVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar1 == 3) {
    puVar2 = (undefined2 *)(**(code **)(*(int *)in_ECX[4] + 0x1c))();
    FUN_004dd320(0,5,1,*puVar2,in_ECX[2],in_ECX[7]);
    in_ECX[7] = in_ECX[7] + 1;
    if (1 < (uint)in_ECX[7]) {
      in_ECX[7] = 0;
    }
  }
  return;
}


// ==== FUN_00529850 @ 0x00529850 ====

void FUN_00529850(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b843c;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 8) = 0;
  *(undefined1 *)((int)in_ECX + 0x21) = 0;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  in_ECX[0xc] = 0;
  in_ECX[1] = 0;
  in_ECX[7] = 0;
  in_ECX[10] = 0;
  in_ECX[9] = 0;
  return;
}


// ==== FUN_005298c0 @ 0x005298c0 ====

float10 FUN_005298c0(char param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x14);
  if (iVar1 == 0) {
    return (float10)DAT_009a09bc;
  }
  if (param_1 == '\0') {
    return (float10)*(float *)(iVar1 + 0x68);
  }
  return (float10)*(float *)(iVar1 + 0x6c);
}


// ==== FUN_005298f0 @ 0x005298f0 ====

undefined4 FUN_005298f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x14) + 0x44);
}


// ==== FUN_00529900 @ 0x00529900 ====

uint FUN_00529900(void)

{
  void *_Memory;
  uint extraout_EAX;
  int in_ECX;
  
  _Memory = *(void **)(in_ECX + 0xc);
  if ((_Memory == (void *)0x0) || (*(char *)((int)_Memory + 0x10) == '\x01')) {
    return (uint)_Memory & 0xffffff00;
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_00529930 @ 0x00529930 ====

void FUN_00529930(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 uStack_c;
  int iStack_8;
  
  iVar1 = (**(code **)(*in_ECX + 0x68))();
  if (*(char *)(iVar1 + 0x14) == '\x01') {
    if (*(char *)((int)in_ECX + 0x21) == '\0') {
      puVar2 = operator_new(0x10);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = &PTR_FUN_009b7964;
        puVar2[3] = 0;
        *(undefined1 *)(puVar2 + 2) = 1;
      }
      uVar3 = (**(code **)(*in_ECX + 8))();
      puVar2[1] = uStack_c;
      iStack_8 = CONCAT31(iStack_8._1_3_,1);
      puVar2[2] = iStack_8;
      puVar2[3] = uVar3;
      FUN_00797a20(puVar2);
      *(undefined1 *)((int)in_ECX + 0x21) = 1;
      return;
    }
  }
  else if (*(char *)((int)in_ECX + 0x21) == '\x01') {
    puVar2 = operator_new(0x10);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009b7964;
      puVar2[3] = 0;
      *(undefined1 *)(puVar2 + 2) = 1;
    }
    uVar3 = (**(code **)(*in_ECX + 8))();
    puVar2[1] = uStack_c;
    iStack_8 = (uint)iStack_8._1_3_ << 8;
    puVar2[2] = iStack_8;
    puVar2[3] = uVar3;
    FUN_00797a20(puVar2);
    *(undefined1 *)((int)in_ECX + 0x21) = 0;
  }
  return;
}


// ==== FUN_00529a00 @ 0x00529a00 ====

undefined1 FUN_00529a00(void)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5ac1c + 0x18))();
  if (cVar1 == '\0') {
    return 0;
  }
  return *(undefined1 *)(in_ECX + 0x20);
}


// ==== FUN_00529a20 @ 0x00529a20 ====

void FUN_00529a20(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  *in_ECX = (int)&PTR_FUN_009b843c;
  (**(code **)(*DAT_00b5ac6c + 0x18))(in_ECX[2]);
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b7950;
  }
  uVar2 = (**(code **)(*in_ECX + 8))();
  puVar1[1] = uVar2;
  FUN_00797a20(puVar1);
  if (in_ECX[4] != 0) {
    (**(code **)(*DAT_00b5a758 + 0x10))(1,in_ECX[4]);
  }
  in_ECX[5] = 0;
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00529aa0 @ 0x00529aa0 ====

undefined4 FUN_00529aa0(void)

{
  short sVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined2 *puVar6;
  int *in_ECX;
  
  if (DAT_00b5a97c == 0) {
    return 0xffffff;
  }
  uVar3 = (**(code **)(*in_ECX + 0x24))();
  piVar4 = (int *)FUN_00803725(uVar3,0,&Framework::ICreature::RTTI_Type_Descriptor,
                               &Framework::Creature::IMonster::RTTI_Type_Descriptor,0);
  piVar4 = (int *)(**(code **)(*piVar4 + 0x20))();
  iVar5 = (**(code **)(*piVar4 + 4))();
  sVar1 = *(short *)(iVar5 + 0x4c);
  if (sVar1 == 0) {
    return 0xffffff;
  }
  uVar3 = 0xffffff;
  iVar5 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar5 != 0) {
    piVar4 = (int *)(**(code **)(**(int **)(iVar5 + 0x48) + 0x24))();
    puVar6 = (undefined2 *)(**(code **)(*piVar4 + 8))();
    uVar2 = *puVar6;
    uVar3 = (**(code **)(*DAT_00b5ac1c + 0x38))();
    piVar4 = (int *)(**(code **)(*DAT_00b5ab1c + 8))(uVar3);
    if (piVar4 == (int *)0x0) {
      return 0xffffff;
    }
    iVar5 = (**(code **)(*piVar4 + 4))(CONCAT22(0xff,uVar2),sVar1);
    uVar3 = *(undefined4 *)(iVar5 + 0x14);
  }
  return uVar3;
}


// ==== FUN_00529b50 @ 0x00529b50 ====

void FUN_00529b50(undefined4 param_1,uint param_2,byte param_3,int param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  uint uVar4;
  uint uVar5;
  float10 fVar6;
  undefined4 unaff_retaddr;
  int iVar7;
  int iVar8;
  
  if (in_ECX[0xc] != 0) {
    (**(code **)(*in_ECX + 0x30))();
    iVar3 = **(int **)(in_ECX[4] + 0x50);
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    piVar2 = (int *)(**(code **)(iVar3 + 0x14))(uVar1);
    iVar3 = (**(code **)(*piVar2 + 0x18))();
    iVar3 = (int)ROUND(*(float *)(iVar3 + 0xc));
    if (param_4 == 3) {
      uVar4 = 0;
    }
    else if (param_4 == 4) {
      uVar4 = 1;
    }
    else {
      uVar4 = (param_4 != 5) - 1 & 2;
    }
    iVar7 = in_ECX[0xc];
    uVar5 = (uint)param_3;
    param_2 = param_2 & 0xff;
    iVar8 = iVar7 + 0x1c;
    FUN_00511d20(iVar7,iVar8,unaff_retaddr,param_2,uVar4,uVar5,param_1,iVar3);
    FUN_00511c30(iVar7,iVar8,unaff_retaddr,param_2,uVar4,uVar5,param_1,iVar3);
    fVar6 = (float10)FUN_0040d0a0(0,0x40200000);
    uVar1 = (**(code **)(*in_ECX + 0x34))((int)ROUND(fVar6),0,in_ECX[2]);
    FUN_004dd240(7,uVar1);
  }
  return;
}


// ==== FUN_00529c60 @ 0x00529c60 ====

undefined4 FUN_00529c60(int *param_1)

{
  float fVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  float *pfVar7;
  int *in_ECX;
  float unaff_EDI;
  float10 extraout_ST0;
  float fStack_14;
  undefined4 uStack_10;
  
  iVar3 = (**(code **)(*param_1 + 0x10))();
  iVar4 = (**(code **)(*in_ECX + 8))();
  if (iVar3 != iVar4) {
    return 0;
  }
  iVar3 = *DAT_00b5acd8;
  uVar5 = (**(code **)(*param_1 + 0x14))();
  piVar6 = (int *)(**(code **)(iVar3 + 0xc))(uVar5);
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 0x28))();
    iVar3 = *DAT_00b5acd8;
    uVar5 = (**(code **)(*in_ECX + 8))();
    piVar6 = (int *)(**(code **)(iVar3 + 0xc))(uVar5);
    if (piVar6 != (int *)0x0) {
      pfVar7 = (float *)(**(code **)(*piVar6 + 0x28))();
      fVar1 = *pfVar7;
      iVar3 = *DAT_00b5a6b4;
      uVar5 = (**(code **)(*in_ECX + 8))();
      (**(code **)(iVar3 + 0x1c))(uVar5);
      if (SQRT(unaff_EDI * unaff_EDI + (fVar1 - fStack_14) * (fVar1 - fStack_14)) <=
          (float)extraout_ST0 + DAT_0099d0f8) {
        iVar3 = (**(code **)(*DAT_00b5a6a8 + 4))();
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          uVar5 = (**(code **)(*param_1 + 0x14))();
          iVar3 = FUN_0052a580(uVar5);
        }
        uVar2 = (**(code **)(*in_ECX + 0x3c))();
        uStack_10 = CONCAT31(0x10000,uVar2);
        iVar4 = (**(code **)(*param_1 + 0x18))();
        if (iVar4 == 0) {
          uStack_10 = CONCAT13(1,CONCAT12(1,(undefined2)uStack_10));
        }
        *(float *)(iVar3 + 4) = (float)extraout_ST0;
        *(float *)(iVar3 + 8) = fStack_14;
        *(undefined4 *)(iVar3 + 0xc) = uStack_10;
        FUN_00797a20(iVar3);
        return 1;
      }
    }
  }
  return 1;
}


// ==== FUN_00529de0 @ 0x00529de0 ====

void FUN_00529de0(float param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int *in_ECX;
  float unaff_retaddr;
  
  if (param_1 != DAT_0099cdc8) {
    iVar1 = (**(code **)(*in_ECX + 0x24))();
    piVar2 = (int *)FUN_00803725(iVar1,0,&Framework::ICreature::RTTI_Type_Descriptor,
                                 &Framework::Creature::IMonster::RTTI_Type_Descriptor,0);
    iVar5 = *(int *)piVar2[0x14];
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    piVar4 = (int *)(**(code **)(iVar5 + 0x14))(uVar3);
    iVar5 = (**(code **)(*piVar2 + 0x24))();
    piVar2 = (int *)0x0;
    if (*(int **)(iVar1 + 0x44) != (int *)0x0) {
      piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x44) + 0x18))();
    }
    iVar1 = (**(code **)(*piVar4 + 8))();
    iVar1 = (int)(unaff_retaddr * DAT_0099d0b4 + *(float *)(iVar1 + 0xc));
    if (*(int *)(iVar5 + 0x50) < iVar1) {
      iVar1 = *(int *)(iVar5 + 0x50);
    }
    (**(code **)(*piVar2 + 0x14))((float)iVar1);
  }
  return;
}


// ==== FUN_00529e90 @ 0x00529e90 ====

void FUN_00529e90(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 0xc));
  return;
}


// ==== FUN_00529f00 @ 0x00529f00 ====

int FUN_00529f00(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int in_ECX;
  char *pcVar4;
  
  iVar2 = *(int *)(in_ECX + 0x14);
  pcVar4 = (char *)(iVar2 + 2);
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  pcVar3 = pcVar4;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar4,(int)pcVar3 - (iVar2 + 3));
  return param_1;
}


// ==== FUN_00529f40 @ 0x00529f40 ====

void FUN_00529f40(void)

{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int *in_ECX;
  undefined1 local_2e [6];
  undefined4 local_28;
  undefined4 local_24;
  void *local_20;
  undefined4 uStack_10;
  uint uStack_c;
  
  if ((in_ECX[3] != 0) && (iVar1 = in_ECX[5], iVar1 != 0)) {
    iVar4 = *(int *)(in_ECX[3] + 8);
    if (iVar4 == -1) {
      local_28 = *(undefined4 *)in_ECX[3];
      iVar4 = *DAT_00b5a77c;
      local_24 = ((undefined4 *)in_ECX[3])[1];
      local_20 = (void *)0x0;
      uVar5 = FUN_004ef0e0(local_2e);
      piVar2 = (int *)(**(code **)(iVar4 + 4))(uVar5);
    }
    else {
      piVar2 = (int *)(**(code **)(*DAT_00b5a77c + 8))(iVar4);
    }
    uVar5 = *(undefined4 *)(in_ECX[3] + 0x14);
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar5;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x600000b;
    *(undefined2 *)((int)pvVar3 + 6) = 0x24;
    iVar4 = FUN_004244d0();
    uVar5 = (**(code **)(*in_ECX + 8))();
    *(undefined4 *)(iVar4 + 0x18) = uVar5;
    puVar6 = (undefined4 *)(**(code **)(*piVar2 + 8))();
    *(undefined4 *)(iVar4 + 0x10) = *puVar6;
    *(undefined4 *)(iVar4 + 0x14) = puVar6[1];
    *(undefined1 *)(iVar4 + 0x1c) = *(undefined1 *)(in_ECX[3] + 0xc);
    *(undefined1 *)(iVar4 + 0x1d) = *(undefined1 *)(in_ECX[3] + 0xd);
    *(undefined1 *)(iVar4 + 0x1f) =
         *(undefined1 *)(iVar1 + 0x158 + (uint)*(byte *)(in_ECX[3] + 0xf) * 0x34);
    *(undefined1 *)(iVar4 + 0x1e) = *(undefined1 *)(in_ECX[3] + 0xe);
    *(undefined1 *)(iVar4 + 0x20) = *(undefined1 *)(in_ECX[3] + 0xf);
    FUN_004d8570(iVar4);
    (**(code **)(*DAT_00b5a77c + 0x18))(piVar2);
    *(undefined1 *)(in_ECX[3] + 0x10) = 1;
    uStack_c = 0xf;
    uStack_10 = 0;
    local_20 = (void *)((uint)local_20 & 0xffffff00);
    FUN_00401740(s_>>>>>>>>>>>>>_Send_Monster_Hit_009b83a0,0x2c);
    FUN_00796d20(&local_24);
    if (0xf < uStack_c) {
      _free(local_20);
      return;
    }
  }
  return;
}


// ==== FUN_0052a0b0 @ 0x0052a0b0 ====

undefined4 FUN_0052a0b0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 extraout_EAX;
  int *in_ECX;
  undefined4 unaff_EBP;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  uint uStack_8;
  
  iVar2 = (**(code **)(*param_1 + 0x10))();
  iVar3 = (**(code **)(*in_ECX + 8))();
  if (iVar2 != iVar3) {
    return 0;
  }
  piVar1 = *(int **)(in_ECX[4] + 0x44);
  piVar4 = (int *)(**(code **)(*piVar1 + 0x18))();
  iVar2 = *piVar1;
  uVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(iVar2 + 0x1c))(uVar5);
  FUN_00401740(s_Update_Monster_HPMP____f__f_009b83d0,0x1b);
  uVar5 = FUN_00404230(auStack_20);
  FUN_00403e50(uVar5);
  if (uStack_8 < 0x10) {
    (**(code **)(*piVar4 + 0x14))();
    (**(code **)(*piVar4 + 0x20))(unaff_EBP);
    return 1;
  }
  _free(pvStack_1c);
  return extraout_EAX;
}


// ==== FUN_0052a1a0 @ 0x0052a1a0 ====

void FUN_0052a1a0(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int *in_ECX;
  void *apvStack_4c [5];
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  uint local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  local_30 = 0;
  local_28 = 0xffffffff;
  local_24 = 0xffffff;
  local_20 = 0x38;
  local_2c = local_2c & 0xffffff00;
  FUN_00401740(s_No_Name_009b79ec,7);
  local_28 = (**(code **)(*in_ECX + 8))();
  local_30 = 0;
  uVar1 = (**(code **)(*in_ECX + 0x40))(apvStack_4c);
  FUN_00401660(uVar1,0,0xffffffff);
  if (0xf < uStack_38) {
    _free(apvStack_4c[0]);
    return;
  }
  local_24 = 0x3a;
  local_28 = FUN_00529aa0();
  pvVar2 = operator_new(0x34);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_00522170();
  }
  *(undefined4 *)(iVar3 + 4) = uStack_34;
  *(undefined1 *)(iVar3 + 8) = (undefined1)local_30;
  *(uint *)(iVar3 + 0xc) = local_2c;
  *(undefined4 *)(iVar3 + 0x10) = local_28;
  *(undefined4 *)(iVar3 + 0x14) = local_24;
  FUN_00401660(&local_20,0,0xffffffff);
  FUN_00797a20(iVar3);
  if (local_8 < 0x10) {
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_0052a2b0 @ 0x0052a2b0 ====

void FUN_0052a2b0(int *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int in_ECX;
  void *unaff_ESI;
  undefined1 auStack_1c [4];
  undefined1 uStack_18;
  uint uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  *(int **)(in_ECX + 0x10) = param_1;
  iVar2 = (**(code **)(*param_1 + 0x24))();
  *(int *)(in_ECX + 0x14) = iVar2;
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  pcVar3 = (char *)(iVar2 + 0x74);
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar2 + 0x74),(int)pcVar3 - (iVar2 + 0x75));
  uVar4 = (**(code **)(*DAT_00b5a6dc + 0x1c))(1,auStack_1c);
  *(undefined4 *)(in_ECX + 0x30) = uVar4;
  FUN_0052a1a0();
  if (uStack_c < 0x10) {
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_0052a340 @ 0x0052a340 ====

void FUN_0052a340(uint param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  int *piVar3;
  
  if ((in_ECX[3] != 0) && (*(char *)(in_ECX[3] + 0x10) == '\0')) {
    iVar2 = (**(code **)(*in_ECX + 0x24))();
    if (*(int **)(iVar2 + 0x4c) == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x4c) + 0x18))();
    }
    (**(code **)(*piVar3 + 8))(param_1);
    iVar2 = (**(code **)(*piVar3 + 0x10))();
    cVar1 = *(char *)(iVar2 + 0xb);
    if ((((cVar1 == '\a') || (cVar1 == '\b')) || (cVar1 == '\t')) ||
       ((cVar1 == '\f' || (cVar1 == '\x0e')))) {
      _free((void *)in_ECX[3]);
      return;
    }
    if (*(int *)(in_ECX[3] + 0x14) - 100U <= param_1) {
      FUN_00529f40();
      return;
    }
  }
  return;
}


// ==== FUN_0052a400 @ 0x0052a400 ====

uint FUN_0052a400(int *param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x40001) {
    cVar1 = (**(code **)(*(int *)*param_2 + 0x2c))();
    if (cVar1 != '\0') {
      FUN_0052a340(param_1[3]);
    }
    uVar3 = FUN_00529930();
  }
  else {
    if (iVar2 == 0x30060031) {
      uVar3 = FUN_0052a0b0(param_1);
      return uVar3;
    }
    uVar3 = iVar2 + 0xcff9ffce;
    if (uVar3 == 0) {
      uVar3 = FUN_00529c60(param_1);
      return uVar3;
    }
  }
  return uVar3 & 0xffffff00;
}


// ==== FUN_0052a470 @ 0x0052a470 ====

void FUN_0052a470(int *param_1)

{
  short sVar1;
  int in_ECX;
  undefined1 *puVar2;
  undefined1 auStack_54 [4];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 uStack_44;
  undefined1 uStack_43;
  undefined1 uStack_42;
  undefined1 uStack_41;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 uStack_34;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 uStack_18;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(int *)(in_ECX + 0x30) != 0) {
    (**(code **)(*param_1 + 0xc))();
    if (*(char *)(in_ECX + 0x2c) == '\0') {
      uStack_50 = 0;
      uStack_4c = 0;
      uStack_48 = 0;
      uStack_20 = 0xf;
      uStack_24 = 0;
      uStack_34 = 0;
      uStack_4 = 0xf;
      uStack_8 = 0;
      uStack_18 = 0;
      uStack_41 = 0;
      uStack_44 = 0;
      uStack_43 = 0;
      uStack_42 = 0;
      uStack_3c = DAT_0099d080;
      uStack_40 = 0xffffffff;
      FUN_00401660(*(undefined4 *)(in_ECX + 0x30),0,0xffffffff);
      FUN_00401660(*(int *)(in_ECX + 0x30) + 0x1c,0,0xffffffff);
      FUN_004ff800(&uStack_44);
      puVar2 = auStack_54;
      FUN_00511d10(puVar2);
      FUN_00512cd0();
      FUN_00512a20(puVar2);
      sVar1 = *(short *)(*(int *)(in_ECX + 0x30) + 0x38);
      if (sVar1 != 0) {
        FUN_004dd240(0x19,1,1,sVar1,*(undefined4 *)(in_ECX + 8));
      }
      *(undefined1 *)(in_ECX + 0x2c) = 1;
      FUN_004107d0();
      FUN_004ff750();
    }
    (**(code **)(*param_1 + 0x10))();
  }
  return;
}


// ==== FUN_0052a580 @ 0x0052a580 ====

void FUN_0052a580(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8420;
  *(undefined1 *)((int)in_ECX + 0xd) = 0;
  *(undefined1 *)((int)in_ECX + 0xe) = 0;
  *(undefined1 *)((int)in_ECX + 0xf) = 1;
  in_ECX[4] = param_1;
  return;
}


// ==== FUN_0052a5a0 @ 0x0052a5a0 ====

undefined4 FUN_0052a5a0(void)

{
  return 0x60060031;
}


// ==== FUN_0052a5b0 @ 0x0052a5b0 ====

void FUN_0052a5b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00529a20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0052a5d0 @ 0x0052a5d0 ====

void FUN_0052a5d0(undefined2 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined2 *)(in_ECX + 0x48);
  return;
}


// ==== FUN_0052a5e0 @ 0x0052a5e0 ====

void FUN_0052a5e0(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x48) = *param_1;
  return;
}


// ==== FUN_0052a5f0 @ 0x0052a5f0 ====

undefined1 FUN_0052a5f0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x3c);
}


// ==== FUN_0052a600 @ 0x0052a600 ====

void FUN_0052a600(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x3c) = param_1;
  return;
}


// ==== FUN_0052a610 @ 0x0052a610 ====

void FUN_0052a610(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x3d) = param_1;
  return;
}


// ==== FUN_0052a620 @ 0x0052a620 ====

undefined1 FUN_0052a620(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x3d);
}


// ==== FUN_0052a630 @ 0x0052a630 ====

void FUN_0052a630(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x3e) = param_1;
  return;
}


// ==== FUN_0052a640 @ 0x0052a640 ====

undefined1 FUN_0052a640(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x3e);
}


// ==== FUN_0052a650 @ 0x0052a650 ====

void FUN_0052a650(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x3f) = param_1;
  return;
}


// ==== FUN_0052a660 @ 0x0052a660 ====

undefined1 FUN_0052a660(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x3f);
}


// ==== FUN_0052a670 @ 0x0052a670 ====

void FUN_0052a670(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x54) == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0052a680. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(**(int **)(in_ECX + 0x50) + 8) + 0xc))();
  return;
}


// ==== FUN_0052a690 @ 0x0052a690 ====

undefined4 FUN_0052a690(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x54) == 0) {
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x0052a6a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(**(int **)(in_ECX + 0x50) + 8) + 8))();
  return uVar1;
}


// ==== FUN_0052a6b0 @ 0x0052a6b0 ====

undefined4 FUN_0052a6b0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x54) == 0) {
    return 0;
  }
  return *(undefined4 *)(**(int **)(in_ECX + 0x50) + 8);
}


// ==== FUN_0052a6d0 @ 0x0052a6d0 ====

void FUN_0052a6d0(void)

{
  uint in_ECX;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x54) == 0) {
    return;
  }
  local_4 = in_ECX & 0xffffff00;
  FUN_00528030(**(undefined4 **)(in_ECX + 0x50),*(undefined4 **)(in_ECX + 0x50),local_4);
  FUN_00510b80();
  return;
}


// ==== FUN_0052a710 @ 0x0052a710 ====

void FUN_0052a710(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b84c4;
  *(undefined1 *)(in_ECX + 0xf) = 1;
  *(undefined1 *)((int)in_ECX + 0x3d) = 0;
  *(undefined1 *)((int)in_ECX + 0x3e) = 1;
  *(undefined1 *)((int)in_ECX + 0x3f) = 0;
  uVar2 = FUN_005170b0();
  uVar1 = DAT_0099d080;
  in_ECX[0x14] = uVar2;
  in_ECX[0x15] = 0;
  in_ECX[3] = 100;
  in_ECX[4] = 100;
  in_ECX[6] = 0;
  uVar2 = DAT_009a000c;
  in_ECX[9] = uVar1;
  *(undefined1 *)(in_ECX + 5) = 0;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  in_ECX[0x11] = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = uVar2;
  in_ECX[0xe] = 0;
  in_ECX[10] = 0;
  in_ECX[0xc] = 0;
  return;
}


// ==== FUN_0052a820 @ 0x0052a820 ====

uint FUN_0052a820(void)

{
  int *_Memory;
  uint in_EAX;
  uint extraout_EAX;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x54) == 0) {
    return in_EAX & 0xffffff00;
  }
  _Memory = (int *)**(int **)(in_ECX + 0x50);
  if (_Memory == *(int **)(in_ECX + 0x50)) {
    return CONCAT31((int3)((uint)_Memory >> 8),1);
  }
  *(int *)_Memory[1] = *_Memory;
  *(int *)(*_Memory + 4) = _Memory[1];
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_0052a860 @ 0x0052a860 ====

void FUN_0052a860(int param_1)

{
  int in_ECX;
  
  FUN_005280c0(*(undefined4 *)(in_ECX + 0x50),**(undefined4 **)(param_1 + 4),
               *(undefined4 **)(param_1 + 4),param_1);
  return;
}


// ==== FUN_0052a890 @ 0x0052a890 ====

void FUN_0052a890(undefined1 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x50);
  iVar2 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_1);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}


// ==== FUN_0052a8d0 @ 0x0052a8d0 ====

void FUN_0052a8d0(byte param_1)

{
  undefined4 *in_ECX;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b84c4;
  if (in_ECX[0x15] != 0) {
    local_4 = (uint)in_ECX & 0xffffff00;
    FUN_00528030(*(undefined4 *)in_ECX[0x14],(undefined4 *)in_ECX[0x14],local_4);
    FUN_00510b80();
  }
  FUN_008984a0();
  *in_ECX = &PTR_FUN_009b8184;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0052a940 @ 0x0052a940 ====

undefined1 FUN_0052a940(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_0052a950 @ 0x0052a950 ====

void FUN_0052a950(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
  uStack_8 = *puVar1;
  iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))();
  uStack_4 = *(undefined4 *)(iVar2 + 4);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
  (**(code **)(*piVar3 + 0x40))(&uStack_8);
  return;
}


// ==== FUN_0052a9d0 @ 0x0052a9d0 ====

uint FUN_0052a9d0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  return uVar1 & 0xffffff00;
}


// ==== FUN_0052a9e0 @ 0x0052a9e0 ====

void FUN_0052a9e0(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  char cVar3;
  undefined1 uStack00000000;
  undefined1 auStackY_9c [128];
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
  (**(code **)(*piVar1 + 0x4c))(param_1);
  piVar1 = (int *)(**(code **)(*DAT_00b5a6fc + 8))();
  if (piVar1 != (int *)0x0) {
    cVar3 = (char)param_1;
    if ((*(char *)(in_ECX + 4) == '\0') && (cVar3 == '\x01')) {
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
      (**(code **)(*piVar2 + 0x28))(2);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
      (**(code **)(*piVar2 + 8))();
      (**(code **)(*piVar1 + 0x54))(auStackY_9c + 0x98,*(undefined4 *)(in_ECX + 0xc));
      *(undefined1 *)(in_ECX + 4) = 1;
      *(undefined1 *)(in_ECX + 4) = 1;
      return;
    }
    if ((*(char *)(in_ECX + 4) == '\x01') && (cVar3 == '\0')) {
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
      (**(code **)(*piVar2 + 8))();
      (**(code **)(*piVar1 + 0x58))(&uStack00000000);
      *(undefined1 *)(in_ECX + 4) = 0;
    }
    *(char *)(in_ECX + 4) = cVar3;
  }
  return;
}


// ==== FUN_0052aa90 @ 0x0052aa90 ====

void FUN_0052aa90(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  undefined4 auStack_8 [2];
  
  if (*(char *)(in_ECX + 4) != '\0') {
    piVar1 = (int *)(**(code **)(*DAT_00b5a6fc + 8))();
    if (piVar1 == (int *)0x0) {
      return;
    }
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    auStack_8[0] = (**(code **)(*piVar2 + 8))();
    iVar3 = (**(code **)(*piVar1 + 0x30))(auStack_8);
    if (iVar3 == 0) {
      return;
    }
    (**(code **)(*piVar1 + 0x40))(iVar3);
  }
  piVar1 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
  if (piVar1 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    auStack_8[0] = (**(code **)(*piVar2 + 8))();
    piVar2 = (int *)(**(code **)(*piVar1 + 0x30))(auStack_8);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*DAT_00b5a6f8 + 0x10))(1,*(undefined4 *)(*piVar2 + 4));
      (**(code **)(*piVar1 + 0x40))(piVar2);
      *(undefined1 *)(in_ECX + 4) = 0;
    }
  }
  return;
}


// ==== FUN_0052ab70 @ 0x0052ab70 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0052ab70(float param_1)

{
  float fVar1;
  float fVar2;
  
  if ((int)param_1 < 100) {
    fVar2 = (float)(int)param_1 * DAT_009a09b8;
    fVar1 = DAT_0099d0f8;
  }
  else {
    fVar2 = ((float)(int)param_1 - DAT_0099de78) * _DAT_009b832c;
    fVar1 = DAT_0099d080;
  }
  fVar1 = fVar1 - fVar2;
  if (DAT_0099d0f8 < fVar1) {
    return (float10)DAT_0099d0f8;
  }
  param_1 = DAT_009b8328;
  if (DAT_009b8328 <= fVar1) {
    param_1 = fVar1;
  }
  return (float10)param_1;
}


// ==== FUN_0052abf0 @ 0x0052abf0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0052abf0(float param_1,int param_2)

{
  int *piVar1;
  int in_ECX;
  float10 fVar2;
  float fVar3;
  float fVar4;
  
  if (99 < param_2) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    fVar2 = (float10)(**(code **)(*piVar1 + 0x18))(param_1);
    fVar4 = (param_1 - DAT_0099de78) * _DAT_009b836c + DAT_0099d080;
    fVar3 = DAT_009b8368;
    if ((DAT_009b8368 < fVar4) || (fVar3 = DAT_009a09b8, fVar4 < DAT_009a09b8)) {
      fVar4 = fVar3;
    }
    return (float10)(fVar4 * (float)fVar2);
  }
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  fVar2 = (float10)(**(code **)(*piVar1 + 0x18))(param_1);
  fVar3 = param_1 * _DAT_009b836c + DAT_009a09b8;
  if (DAT_009b8368 < fVar3) {
    return (float10)(DAT_009b8368 * (float)fVar2);
  }
  fVar4 = DAT_009a09b8;
  if (DAT_009a09b8 <= fVar3) {
    fVar4 = fVar3;
  }
  return (float10)(fVar4 * (float)fVar2);
}


// ==== FUN_0052ace0 @ 0x0052ace0 ====

void FUN_0052ace0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x51d0004;
  *(undefined2 *)((int)pvVar1 + 6) = 0x10;
  uVar2 = FUN_004244d0();
  FUN_004d8570(uVar2);
  return;
}


// ==== FUN_0052ad20 @ 0x0052ad20 ====

void FUN_0052ad20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8648;
  FUN_0052aa90();
  *in_ECX = &PTR_FUN_009b7ed4;
  return;
}


// ==== FUN_0052ad40 @ 0x0052ad40 ====

void FUN_0052ad40(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 auStack_a [10];
  
  piVar2 = DAT_00b5a780;
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x1c))();
  piVar2 = (int *)(**(code **)(*piVar2 + 8))(iVar1 + 0x14);
  if (piVar2 == (int *)0x0) {
    return;
  }
  (**(code **)(*piVar2 + 0xc))(auStack_a + -6);
  return;
}


// ==== FUN_0052ad90 @ 0x0052ad90 ====

void FUN_0052ad90(int *param_1)

{
  uint uVar1;
  uint *puVar2;
  undefined2 *puVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  undefined4 *in_ECX;
  int iStack_ec;
  uint *puStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  uint uStack_b4;
  uint uStack_b0;
  uint uStack_ac;
  undefined4 uStack_a8;
  uint uStack_a4;
  undefined4 uStack_a0;
  uint uStack_9c;
  undefined4 uStack_98;
  uint uStack_94;
  undefined4 uStack_90;
  uint uStack_8c;
  undefined4 uStack_88;
  uint uStack_84;
  undefined4 uStack_80;
  uint uStack_7c;
  undefined4 uStack_78;
  void *pvStack_58;
  undefined2 auStack_54 [2];
  undefined4 uStack_50;
  int iStack_4c;
  int *piStack_48;
  uint uStack_44;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  
  *in_ECX = &PTR_FUN_009b8648;
  in_ECX[2] = param_1;
  *(undefined1 *)(in_ECX + 1) = 0;
  puVar2 = (uint *)(**(code **)(*param_1 + 0x28))();
  uVar1 = *puVar2;
  uStack_b0 = puVar2[1];
  uStack_ac = 0;
  uStack_dc = (TypeDescriptor *)0x52adf6;
  uStack_b4 = uVar1;
  FUN_004ef0e0();
  puVar3 = (undefined2 *)FUN_005e0c90();
  *(undefined2 *)((int)in_ECX + 6) = *puVar3;
  piVar4 = (int *)(**(code **)(*param_1 + 0x14))();
  uStack_e4 = (**(code **)(*piVar4 + 0x24))();
  uStack_dc = &Framework::ICreature::RTTI_Type_Descriptor;
  uStack_e0 = 0;
  puStack_e8 = (uint *)0x52ae26;
  piStack_48 = (int *)FUN_00803725();
  if (piStack_48 == (int *)0x0) {
    uStack_44 = 0xf;
    pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
    uStack_dc = (TypeDescriptor *)0x52ae58;
    FUN_00401740();
    FUN_00796d50();
    if (0xf < uStack_44) {
      _free(pvStack_58);
      return;
    }
  }
  else {
    uStack_dc = (TypeDescriptor *)0x0;
    uStack_e0 = 0x52ae99;
    piVar4 = (int *)(**(code **)(*(int *)piStack_48[0x14] + 0x14))();
    uStack_e0 = 0x52aea2;
    puVar3 = (undefined2 *)(**(code **)(*piStack_48 + 0x24))();
    uStack_e0 = 0;
    uStack_e4 = 1;
    puStack_e8 = (uint *)0x52aecb;
    uVar5 = (**(code **)(*DAT_00b5a6f8 + 0xc))();
    in_ECX[3] = uVar5;
    puStack_e8 = (uint *)0x52aed6;
    piVar6 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x14))();
    puStack_e8 = (uint *)0x52aedd;
    uStack_b4 = (**(code **)(*piVar6 + 8))();
    puStack_e8 = (uint *)0x52aee9;
    iVar7 = (**(code **)(*(int *)in_ECX[2] + 0x14))();
    uStack_b0 = *(undefined4 *)(iVar7 + 0xc);
    puStack_e8 = (uint *)0x52aefa;
    piVar6 = (int *)(**(code **)(*(int *)in_ECX[3] + 0xc))();
    puStack_e8 = &uStack_b4;
    iStack_ec = 0x52af06;
    (**(code **)(*piVar6 + 0x10))();
    iStack_ec = 0x52af11;
    piVar6 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
    if (piVar6 != (int *)0x0) {
      iStack_ec = (int)register0x00000010 + -0xd8;
      piVar6 = (int *)(**(code **)(*piVar6 + 0x30))();
      if ((piVar6 != (int *)0x0) && (*(int **)(*piVar6 + 4) != (int *)0x0)) {
        piVar6 = (int *)(**(code **)(**(int **)(*piVar6 + 4) + 0xc))();
        (**(code **)(*piVar6 + 0x20))(uVar1);
      }
      auStack_54[0] = puVar3[0x12];
      uStack_50 = 2;
      iVar7 = (**(code **)(*piVar4 + 8))();
      iStack_4c = (int)*(float *)(iVar7 + 0xc);
      piStack_48 = *(int **)(puVar3 + 0x14);
      uStack_2c = 0;
      uStack_2b = 0;
      piVar4 = (int *)(**(code **)(*(int *)in_ECX[3] + 0xc))();
      (**(code **)(*piVar4 + 0x14))(auStack_54);
      uStack_b4 = (uint)*(byte *)(puVar3 + 0x82);
      uStack_b0 = *(uint *)(puVar3 + 0x84);
      uStack_ac = (uint)*(byte *)(puVar3 + 0xb6);
      uStack_a8 = *(undefined4 *)(puVar3 + 0xb8);
      uStack_a4 = (uint)*(byte *)(puVar3 + 0x9c);
      uStack_a0 = *(undefined4 *)(puVar3 + 0x9e);
      uStack_9c = (uint)*(byte *)(puVar3 + 0xd0);
      uStack_98 = *(undefined4 *)(puVar3 + 0xd2);
      uStack_94 = (uint)*(byte *)(puVar3 + 0x104);
      uStack_90 = *(undefined4 *)(puVar3 + 0x106);
      uStack_8c = (uint)*(byte *)(puVar3 + 0xea);
      uStack_88 = *(undefined4 *)(puVar3 + 0xec);
      uStack_84 = (uint)*(byte *)(puVar3 + 0xea);
      uStack_80 = *(undefined4 *)(puVar3 + 0xec);
      uStack_7c = (uint)*(byte *)(puVar3 + 0x138);
      uStack_78 = *(undefined4 *)(puVar3 + 0x13a);
      piVar4 = (int *)(**(code **)(*(int *)in_ECX[3] + 0xc))();
      (**(code **)(*piVar4 + 0x18))(&uStack_b4);
      uVar5 = (**(code **)(*DAT_00b5a6f4 + 8))(puVar3[0x73]);
      piVar4 = (int *)(**(code **)(*(int *)in_ECX[3] + 0x28))();
      (**(code **)(*piVar4 + 4))(uVar5);
      piVar4 = (int *)(**(code **)(*DAT_00b5a714 + 8))(*puVar3);
      uVar5 = (**(code **)(*piVar4 + 8))();
      (**(code **)(*(int *)in_ECX[3] + 0x44))(uVar5);
      piVar4 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
      if (piVar4 != (int *)0x0) {
        piVar6 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x14))();
        iStack_ec = (**(code **)(*piVar6 + 8))();
        (**(code **)(*piVar4 + 0x54))(&iStack_ec,in_ECX[3]);
        (**(code **)(*DAT_00b5a6fc + 8))();
      }
    }
  }
  return;
}


// ==== FUN_0052b110 @ 0x0052b110 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0052b110(int param_1)

{
  int iVar1;
  int *piVar2;
  float *pfVar3;
  float *pfVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int in_ECX;
  int unaff_EBP;
  undefined4 unaff_ESI;
  float10 fVar9;
  undefined1 auStack_76 [10];
  float fStack_6c;
  float fStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  float fStack_5c;
  int iStack_58;
  undefined4 uStack_54;
  undefined2 uStack_50;
  undefined1 uStack_4e;
  undefined1 uStack_4d;
  undefined2 uStack_4c;
  undefined1 uStack_4a;
  int iStack_49;
  undefined1 auStack_38 [4];
  void *pvStack_34;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  uint uStack_20;
  uint uStack_10;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    iVar1 = FUN_0052ad40(0,*(undefined4 *)(param_1 + 0xc));
    if (iVar1 == 0) {
      (**(code **)(**(int **)(in_ECX + 8) + 0x1c))();
      FUN_00401740(s_Cannot_Find__u_Monster__u__Attac_009b8520,0x28);
      FUN_00404230(auStack_38);
      FUN_00796d50(auStack_38);
      if (0xf < uStack_20) {
        _free(pvStack_34);
        return;
      }
    }
    else {
      piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 8));
      if (piVar2 == (int *)0x0) {
        (**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
        return;
      }
      pfVar3 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
      pfVar4 = (float *)(**(code **)(*piVar2 + 0x28))();
      fStack_6c = *pfVar4 - *pfVar3;
      fStack_68 = pfVar4[1] - pfVar3[1];
      if (SQRT(fStack_68 * fStack_68 + fStack_6c * fStack_6c) <= _DAT_009b8640) {
        pfVar3 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
        fStack_6c = *pfVar3;
        fStack_68 = pfVar3[1];
      }
      else {
        thunk_FUN_0079de77(&uStack_64,&fStack_6c);
      }
      puVar5 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
      uStack_64 = *puVar5;
      iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))();
      uStack_60 = *(undefined4 *)(iVar6 + 4);
      fVar9 = (float10)FUN_0040d5f0(&fStack_6c);
      fStack_5c = (float)fVar9;
      (**(code **)(*piVar2 + 0x28))();
      (**(code **)(*piVar2 + 0x28))();
      iVar6 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      FUN_00797a50(&iStack_58,0,0x13);
      uStack_4d = 6;
      uStack_4e = 0;
      iStack_58 = iVar6;
      puVar5 = (undefined4 *)FUN_004ef0e0(auStack_76 + -6);
      uStack_54 = *puVar5;
      uStack_4a = *(undefined1 *)(param_1 + 0xc);
      uStack_50 = *(undefined2 *)(puVar5 + 1);
      uStack_4c = FUN_004eefa0(unaff_ESI);
      iVar7 = (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
      fVar9 = (float10)FUN_0052ab70(*(undefined4 *)(iVar7 + 0xc));
      iStack_49 = iVar6 - (int)ROUND(fVar9 * (float10)*(float *)(iVar1 + 0x114) *
                                     (float10)DAT_0099d0f4);
      puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        *puVar5 = &PTR_FUN_009b2d88;
      }
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
      uVar8 = (**(code **)(*piVar2 + 8))();
      puVar5[1] = uVar8;
      FUN_00403e60(puVar5 + 2,&iStack_58,0x19);
      FUN_00797a20(puVar5);
      iVar1 = FUN_004eef70(iVar6);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
      uVar8 = (**(code **)(*piVar2 + 8))();
      *(undefined4 *)(iVar1 + 0x10) = uVar8;
      FUN_00403e60(iVar1 + 0x14,&iStack_58,0x13);
      FUN_004d8570(iVar1);
      FUN_00401830(s_______________________________GU_009b854c);
      FUN_00404230(auStack_28);
      FUN_00796d50(auStack_28);
      puVar5 = operator_new(0x14);
      *(undefined1 *)(puVar5 + 2) = 0;
      *(undefined1 *)((int)puVar5 + 5) = *(undefined1 *)(unaff_EBP + 0x119);
      *(undefined1 *)(puVar5 + 1) = *(undefined1 *)(unaff_EBP + 0x118);
      *(undefined1 *)((int)puVar5 + 7) = *(undefined1 *)(param_1 + 0xc);
      iVar1 = FUN_004ef0e0(auStack_76 + -6);
      *(undefined1 *)((int)puVar5 + 6) = *(undefined1 *)(iVar1 + 4);
      puVar5[3] = iVar6 - (int)ROUND(*(float *)(unaff_EBP + 0x11c) * *(float *)(unaff_EBP + 0x114) *
                                     DAT_0099d0f4);
      *puVar5 = *(undefined4 *)(param_1 + 8);
      *(undefined1 *)(puVar5 + 4) = *(undefined1 *)(param_1 + 0x10);
      uVar8 = (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
      iVar1 = FUN_00803725(uVar8,0,&Framework::ModelCenter::Actors::Info::IActorInfo::
                                    RTTI_Type_Descriptor,
                           &Framework::ModelCenter::Actors::Info::Guard::RTTI_Type_Descriptor,0);
      if (iVar1 != 0) {
        FUN_0052bf40(puVar5);
      }
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
    }
  }
  return;
}


// ==== FUN_0052b4f0 @ 0x0052b4f0 ====

void FUN_0052b4f0(int param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  float *pfVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  void *pvVar9;
  int in_ECX;
  float10 fVar10;
  float fStack_64;
  float fStack_60;
  undefined1 auStack_5c [12];
  undefined1 auStack_50 [4];
  void *pvStack_4c;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined1 auStack_34 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  float fStack_28;
  float fStack_24;
  undefined4 uStack_20;
  undefined1 uStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    fVar1 = *(float *)(param_1 + 0xc);
    fVar2 = *(float *)(param_1 + 0x10);
    pfVar4 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
    fStack_60 = fVar2 - pfVar4[1];
    fStack_64 = fVar1 - *pfVar4;
    thunk_FUN_0079de77(auStack_5c,&fStack_64);
    puVar5 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
    uStack_30 = *puVar5;
    uStack_2c = puVar5[1];
    fStack_28 = fStack_64;
    fStack_18 = fStack_64;
    fStack_24 = fStack_60;
    fStack_14 = fStack_60;
    uStack_1c = 0;
    fStack_10 = (float)CONCAT31(fStack_10._1_3_,*(char *)(param_1 + 8) == '\x01');
    uStack_20 = uVar3;
    piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    fVar10 = (float10)(**(code **)(*piVar6 + 0x18))(fStack_10);
    fStack_10 = (float)fVar10;
    iVar7 = (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
    fVar10 = (float10)FUN_0052abf0(fStack_14,*(undefined4 *)(iVar7 + 0x10));
    fStack_10 = (float)fVar10;
    FUN_00507870(auStack_34,&fStack_60);
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = &PTR_FUN_009b2d88;
    }
    piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    uVar8 = (**(code **)(*piVar6 + 8))();
    puVar5[1] = uVar8;
    FUN_00403e60(puVar5 + 2,&fStack_60,0x19);
    FUN_00797a20(puVar5);
    pvVar9 = operator_new(0x400);
    *(undefined4 *)((int)pvVar9 + 8) = uVar3;
    *(undefined4 *)((int)pvVar9 + 0xc) = 0x50d0000;
    *(undefined2 *)((int)pvVar9 + 6) = 0x30;
    iVar7 = FUN_004244d0();
    piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    uVar3 = (**(code **)(*piVar6 + 8))();
    *(undefined4 *)(iVar7 + 0x10) = uVar3;
    FUN_00403e60(iVar7 + 0x14,&fStack_60,0x10);
    FUN_004d8570(iVar7);
    uStack_38 = 0xf;
    uStack_3c = 0;
    pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
    FUN_00401740(s_______________________________Gu_009b858c,0x30);
    FUN_00796d50(auStack_50);
    if (0xf < uStack_38) {
      _free(pvStack_4c);
      return;
    }
  }
  return;
}


// ==== FUN_0052b6e0 @ 0x0052b6e0 ====

void FUN_0052b6e0(int param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int in_ECX;
  float10 fVar7;
  undefined1 auStack_42 [6];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined2 uStack_2c;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined4 uStack_28;
  undefined4 uStack_24;
  float fStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = uVar1;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x50d0000;
    *(undefined2 *)((int)pvVar2 + 6) = 0x30;
    iVar3 = FUN_004244d0();
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    uVar5 = (**(code **)(*piVar4 + 8))();
    *(undefined4 *)(iVar3 + 0x10) = uVar5;
    FUN_00797a50(&uStack_34,0,0xc);
    uStack_29 = 1;
    uStack_2a = 0;
    uStack_34 = uVar1;
    puVar6 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
    uStack_3c = *puVar6;
    uStack_38 = puVar6[1];
    uStack_28 = *(undefined4 *)(param_1 + 8);
    uStack_24 = *(undefined4 *)(param_1 + 0xc);
    fVar7 = (float10)FUN_0040d5f0(&uStack_3c);
    fStack_20 = (float)fVar7;
    puVar6 = (undefined4 *)FUN_004ef0e0(auStack_42);
    uStack_30 = *puVar6;
    uStack_2c = *(undefined2 *)(puVar6 + 1);
    puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      *puVar6 = &PTR_FUN_009b2d88;
    }
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    uVar1 = (**(code **)(*piVar4 + 8))();
    puVar6[1] = uVar1;
    FUN_00403e60(puVar6 + 2,&uStack_34,0x19);
    FUN_00797a20(puVar6);
    FUN_00403e60(iVar3 + 0x14,&uStack_34,0xc);
    FUN_004d8570(iVar3);
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_00401740(s_______________________________Gu_009b85c0,0x2e);
    FUN_00796d50(auStack_1c);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
  }
  return;
}


// ==== FUN_0052b870 @ 0x0052b870 ====

void FUN_0052b870(int param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int in_ECX;
  float10 fVar7;
  undefined1 auStack_42 [6];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined2 uStack_2c;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined4 uStack_28;
  undefined4 uStack_24;
  float fStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = uVar1;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x50d0000;
    *(undefined2 *)((int)pvVar2 + 6) = 0x30;
    iVar3 = FUN_004244d0();
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    uVar5 = (**(code **)(*piVar4 + 8))();
    *(undefined4 *)(iVar3 + 0x10) = uVar5;
    FUN_00797a50(&uStack_34,0,0xc);
    uStack_29 = 1;
    uStack_2a = 0;
    uStack_34 = uVar1;
    puVar6 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
    uStack_3c = *puVar6;
    uStack_38 = puVar6[1];
    uStack_28 = *(undefined4 *)(param_1 + 8);
    uStack_24 = *(undefined4 *)(param_1 + 0xc);
    fVar7 = (float10)FUN_0040d5f0(&uStack_3c);
    fStack_20 = (float)fVar7;
    puVar6 = (undefined4 *)FUN_004ef0e0(auStack_42);
    uStack_30 = *puVar6;
    uStack_2c = *(undefined2 *)(puVar6 + 1);
    puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      *puVar6 = &PTR_FUN_009b2d88;
    }
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    uVar1 = (**(code **)(*piVar4 + 8))();
    puVar6[1] = uVar1;
    FUN_00403e60(puVar6 + 2,&uStack_34,0x19);
    FUN_00797a20(puVar6);
    FUN_00403e60(iVar3 + 0x14,&uStack_34,0xc);
    FUN_004d8570(iVar3);
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_00401740(s_______________________________Gu_009b85f0,0x2d);
    FUN_00796d50(auStack_1c);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
  }
  return;
}


// ==== FUN_0052ba00 @ 0x0052ba00 ====

void FUN_0052ba00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8648;
  FUN_0052aa90();
  *in_ECX = &PTR_FUN_009b7ed4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0052ba30 @ 0x0052ba30 ====

undefined4 FUN_0052ba30(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_0052ba40 @ 0x0052ba40 ====

void FUN_0052ba40(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_0052ba50 @ 0x0052ba50 ====

void FUN_0052ba50(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x1c) = param_1;
  return;
}


// ==== FUN_0052ba60 @ 0x0052ba60 ====

undefined4 FUN_0052ba60(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x14);
}


// ==== FUN_0052ba70 @ 0x0052ba70 ====

undefined4 FUN_0052ba70(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x14);
}


// ==== FUN_0052ba90 @ 0x0052ba90 ====

undefined1 FUN_0052ba90(void)

{
  return 0;
}


// ==== FUN_0052baa0 @ 0x0052baa0 ====

undefined4 FUN_0052baa0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x18) + 0x20);
}


// ==== FUN_0052bab0 @ 0x0052bab0 ====

undefined4 FUN_0052bab0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x18) + 0x20);
}


// ==== FUN_0052bac0 @ 0x0052bac0 ====

void FUN_0052bac0(void)

{
  undefined2 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 0x14) + 0x1c))();
  FUN_004dd240(0,2,3,*puVar1,*(undefined4 *)(in_ECX + 8));
  return;
}


// ==== FUN_0052baf0 @ 0x0052baf0 ====

void FUN_0052baf0(void)

{
  undefined2 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 0x14) + 0x1c))();
  FUN_004dd240(0,3,3,*puVar1,*(undefined4 *)(in_ECX + 8));
  return;
}


// ==== FUN_0052bb20 @ 0x0052bb20 ====

void FUN_0052bb20(void)

{
  undefined2 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 0x14) + 0x1c))();
  FUN_004dd240(0,4,3,*puVar1,*(undefined4 *)(in_ECX + 8));
  return;
}


// ==== FUN_0052bb50 @ 0x0052bb50 ====

void FUN_0052bb50(undefined4 param_1)

{
  undefined4 uVar1;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0x34))(0,in_ECX[2]);
  FUN_004dd240(3,param_1,uVar1);
  return;
}


// ==== FUN_0052bb70 @ 0x0052bb70 ====

void FUN_0052bb70(void)

{
  undefined2 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 0x14) + 0x1c))();
  FUN_004dd240(0,5,3,*puVar1,*(undefined4 *)(in_ECX + 8));
  return;
}


// ==== FUN_0052bba0 @ 0x0052bba0 ====

void FUN_0052bba0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b872c;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 7) = 0;
  *(undefined1 *)((int)in_ECX + 0x1d) = 0;
  *(undefined1 *)((int)in_ECX + 0x1e) = 0;
  in_ECX[8] = 0;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_0052bbd0 @ 0x0052bbd0 ====

void FUN_0052bbd0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b872c;
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b7950;
  }
  puVar1[1] = in_ECX[2];
  FUN_00797a20(puVar1);
  if (in_ECX[5] != 0) {
    (**(code **)(*DAT_00b5af20 + 0x10))(1,in_ECX[5]);
  }
  in_ECX[6] = 0;
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_0052bc40 @ 0x0052bc40 ====

float10 FUN_0052bc40(char param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x18);
  if (iVar1 == 0) {
    return (float10)DAT_009a09bc;
  }
  if (param_1 == '\0') {
    return (float10)*(float *)(iVar1 + 0x40);
  }
  return (float10)*(float *)(iVar1 + 0x44);
}


// ==== FUN_0052bc70 @ 0x0052bc70 ====

undefined4 FUN_0052bc70(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x18) + 0x1c);
}


// ==== FUN_0052bc80 @ 0x0052bc80 ====

uint FUN_0052bc80(void)

{
  void *_Memory;
  uint extraout_EAX;
  int in_ECX;
  
  _Memory = *(void **)(in_ECX + 0x10);
  if ((_Memory == (void *)0x0) || (*(char *)((int)_Memory + 8) == '\x01')) {
    return (uint)_Memory & 0xffffff00;
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_0052bcb0 @ 0x0052bcb0 ====

void FUN_0052bcb0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 uStack_c;
  int iStack_8;
  
  iVar1 = (**(code **)(*in_ECX + 0x68))();
  if (*(char *)(iVar1 + 0x14) == '\x01') {
    if (*(char *)((int)in_ECX + 0x1d) == '\0') {
      puVar2 = operator_new(0x10);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = &PTR_FUN_009b7964;
        puVar2[3] = 0;
        *(undefined1 *)(puVar2 + 2) = 1;
      }
      uVar3 = (**(code **)(*in_ECX + 8))();
      puVar2[1] = uStack_c;
      iStack_8 = CONCAT31(iStack_8._1_3_,1);
      puVar2[2] = iStack_8;
      puVar2[3] = uVar3;
      FUN_00797a20(puVar2);
      *(undefined1 *)((int)in_ECX + 0x1d) = 1;
      return;
    }
  }
  else if (*(char *)((int)in_ECX + 0x1d) == '\x01') {
    puVar2 = operator_new(0x10);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009b7964;
      puVar2[3] = 0;
      *(undefined1 *)(puVar2 + 2) = 1;
    }
    uVar3 = (**(code **)(*in_ECX + 8))();
    puVar2[1] = uStack_c;
    iStack_8 = (uint)iStack_8._1_3_ << 8;
    puVar2[2] = iStack_8;
    puVar2[3] = uVar3;
    FUN_00797a20(puVar2);
    *(undefined1 *)((int)in_ECX + 0x1d) = 0;
  }
  return;
}


// ==== FUN_0052bd80 @ 0x0052bd80 ====

undefined1 FUN_0052bd80(void)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5ac1c + 0x18))();
  if (cVar1 == '\0') {
    return 0;
  }
  return *(undefined1 *)(in_ECX + 0x1c);
}


// ==== FUN_0052bda0 @ 0x0052bda0 ====

void FUN_0052bda0(byte param_1,byte param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_retaddr;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 uStack_4;
  
  if (in_ECX[8] != 0) {
    (**(code **)(*DAT_00b5ac6c + 0x18))(in_ECX[2]);
    (**(code **)(*in_ECX + 0x30))();
    iVar3 = **(int **)(in_ECX[5] + 0x50);
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    piVar2 = (int *)(**(code **)(iVar3 + 0x14))(uVar1);
    iVar3 = (**(code **)(*piVar2 + 0x18))();
    iVar3 = (int)ROUND(*(float *)(iVar3 + 0xc));
    if (param_3 == 3) {
      uVar6 = 0;
    }
    else if (param_3 == 4) {
      uVar6 = 1;
    }
    else {
      uVar6 = (param_3 != 5) - 1 & 2;
    }
    uVar5 = (uint)param_2;
    iVar7 = in_ECX[8];
    uVar4 = (uint)param_1;
    iVar8 = iVar7 + 0x1c;
    uVar9 = uVar6;
    FUN_00511d20(iVar7,iVar8,uStack_4,uVar4,uVar6,uVar5,unaff_retaddr,iVar3);
    FUN_00511c30(iVar7,iVar8,uStack_4,uVar4,uVar9,uVar5,unaff_retaddr,iVar3);
    uVar1 = (**(code **)(*in_ECX + 0x34))(uVar6,0,in_ECX[2]);
    FUN_004dd240(7,uVar1);
  }
  return;
}


// ==== FUN_0052be90 @ 0x0052be90 ====

void FUN_0052be90(float param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int *in_ECX;
  float unaff_retaddr;
  
  if (param_1 != DAT_0099cdc8) {
    iVar1 = (**(code **)(*in_ECX + 0x24))();
    piVar2 = (int *)FUN_00803725(iVar1,0,&Framework::ICreature::RTTI_Type_Descriptor,
                                 &Framework::Creature::IGuard::RTTI_Type_Descriptor,0);
    iVar5 = *(int *)piVar2[0x14];
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    piVar4 = (int *)(**(code **)(iVar5 + 0x14))(uVar3);
    iVar5 = (**(code **)(*piVar2 + 0x24))();
    piVar2 = (int *)0x0;
    if (*(int **)(iVar1 + 0x44) != (int *)0x0) {
      piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x44) + 0x18))();
    }
    iVar1 = (**(code **)(*piVar4 + 8))();
    iVar1 = (int)(unaff_retaddr * DAT_0099d0b4 + *(float *)(iVar1 + 0xc));
    if (*(int *)(iVar5 + 0x28) < iVar1) {
      iVar1 = *(int *)(iVar5 + 0x28);
    }
    (**(code **)(*piVar2 + 0x14))((float)iVar1);
  }
  return;
}


// ==== FUN_0052bf40 @ 0x0052bf40 ====

void FUN_0052bf40(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 0x10));
  return;
}


// ==== FUN_0052bfb0 @ 0x0052bfb0 ====

int FUN_0052bfb0(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int in_ECX;
  char *pcVar4;
  
  iVar2 = *(int *)(in_ECX + 0x18);
  pcVar4 = (char *)(iVar2 + 2);
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  pcVar3 = pcVar4;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar4,(int)pcVar3 - (iVar2 + 3));
  return param_1;
}


// ==== FUN_0052bff0 @ 0x0052bff0 ====

/* WARNING: Removing unreachable block (ram,0x0052c101) */

void FUN_0052bff0(void)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *in_ECX;
  undefined1 auStack_1a [26];
  
  if ((in_ECX[4] != 0) && (iVar4 = in_ECX[6], iVar4 != 0)) {
    uVar3 = *(undefined4 *)(in_ECX[4] + 0xc);
    pvVar1 = operator_new(0x400);
    *(undefined4 *)((int)pvVar1 + 8) = uVar3;
    *(undefined4 *)((int)pvVar1 + 0xc) = 0x600000d;
    *(undefined2 *)((int)pvVar1 + 6) = 0x20;
    iVar2 = FUN_004244d0();
    uVar3 = (**(code **)(*in_ECX + 8))();
    *(undefined4 *)(iVar2 + 0x10) = uVar3;
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)in_ECX[4];
    *(undefined1 *)(iVar2 + 0x18) = *(undefined1 *)(in_ECX[4] + 4);
    *(undefined1 *)(iVar2 + 0x19) = *(undefined1 *)(in_ECX[4] + 5);
    *(undefined1 *)(iVar2 + 0x1b) =
         *(undefined1 *)(iVar4 + 0xf8 + (uint)*(byte *)(in_ECX[4] + 7) * 0x34);
    *(undefined1 *)(iVar2 + 0x1a) = *(undefined1 *)(in_ECX[4] + 6);
    iVar4 = (**(code **)(*DAT_00b5ad04 + 0x18))(*(undefined4 *)in_ECX[4]);
    if ((iVar4 == 0) || (*(short *)(iVar4 + 0x14) == 0)) {
      *(undefined1 *)(iVar2 + 0x1c) = 0;
    }
    else {
      *(undefined1 *)(iVar2 + 0x1c) = *(undefined1 *)(in_ECX[4] + 0x10);
    }
    *(undefined1 *)(iVar2 + 0x1d) = *(undefined1 *)(in_ECX[4] + 7);
    FUN_004d8570(iVar2);
    *(undefined1 *)(in_ECX[4] + 8) = 1;
    FUN_00401740(s_>>>>>>>>>>>>>_Send_Guard_Hit_009b86ac,0x2a);
    FUN_00796d20(auStack_1a + -6);
  }
  return;
}


// ==== FUN_0052c120 @ 0x0052c120 ====

undefined4 FUN_0052c120(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 extraout_EAX;
  int *in_ECX;
  undefined4 unaff_EBP;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  uint uStack_8;
  
  iVar2 = (**(code **)(*param_1 + 0x10))();
  iVar3 = (**(code **)(*in_ECX + 8))();
  if (iVar2 != iVar3) {
    return 0;
  }
  piVar1 = *(int **)(in_ECX[5] + 0x44);
  piVar4 = (int *)(**(code **)(*piVar1 + 0x18))();
  iVar2 = *piVar1;
  uVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(iVar2 + 0x1c))(uVar5);
  FUN_00401740(s_Update_Servant_HPMP____f__f_009b86d8,0x1b);
  uVar5 = FUN_00404230(auStack_20);
  FUN_00796d50(uVar5);
  if (uStack_8 < 0x10) {
    (**(code **)(*piVar4 + 0x14))();
    (**(code **)(*piVar4 + 0x20))(unaff_EBP);
    return 1;
  }
  _free(pvStack_1c);
  return extraout_EAX;
}


// ==== FUN_0052c210 @ 0x0052c210 ====

void FUN_0052c210(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  char *pcVar5;
  int *in_ECX;
  char *pcVar6;
  void *unaff_ESI;
  undefined1 auStack_66 [10];
  uint uStack_5c;
  void *apvStack_4c [5];
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  void *pvStack_24;
  undefined4 auStack_20 [2];
  undefined1 uStack_18;
  uint uStack_10;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  in_ECX[5] = (int)param_1;
  iVar2 = (**(code **)(*param_1 + 0x24))();
  in_ECX[6] = iVar2;
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  uStack_30 = 0;
  uStack_28 = 0xffffffff;
  pvStack_24 = (void *)0xffffff;
  auStack_20[0] = 0x38;
  uStack_2c = uStack_2c & 0xffffff00;
  FUN_00401740(s_No_Name_009b79ec,7);
  uStack_28 = (**(code **)(*in_ECX + 8))();
  uStack_30 = 0;
  uVar3 = (**(code **)(*in_ECX + 0x40))(apvStack_4c);
  FUN_00401660(uVar3,0,0xffffffff);
  if (0xf < uStack_38) {
    _free(apvStack_4c[0]);
    return;
  }
  pvStack_24 = (void *)0x3b;
  pvVar4 = operator_new(0x34);
  if (pvVar4 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00522170();
  }
  *(undefined4 *)(iVar2 + 4) = uStack_34;
  *(undefined1 *)(iVar2 + 8) = (undefined1)uStack_30;
  *(uint *)(iVar2 + 0xc) = uStack_2c;
  *(undefined4 *)(iVar2 + 0x10) = uStack_28;
  *(void **)(iVar2 + 0x14) = pvStack_24;
  FUN_00401660(auStack_20,0,0xffffffff);
  FUN_00797a20(iVar2);
  pcVar6 = (char *)(in_ECX[6] + 0x4c);
  pcVar5 = pcVar6;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar6,(int)pcVar5 - (in_ECX[6] + 0x4d));
  iVar2 = (**(code **)(*DAT_00b5a6dc + 0x1c))(3,auStack_66 + -6);
  in_ECX[8] = iVar2;
  if (0xf < uStack_5c) {
    _free(unaff_ESI);
    return;
  }
  if (uStack_10 < 0x10) {
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_0052c390 @ 0x0052c390 ====

void FUN_0052c390(uint param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  if ((in_ECX[4] != 0) && (*(char *)(in_ECX[4] + 8) == '\0')) {
    iVar2 = (**(code **)(*in_ECX + 0x24))();
    if ((*(int **)(iVar2 + 0x4c) != (int *)0x0) &&
       (piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x4c) + 0x18))(), piVar3 != (int *)0x0)) {
      (**(code **)(*piVar3 + 8))(param_1);
      iVar2 = (**(code **)(*piVar3 + 0x10))();
      if (iVar2 != 0) {
        cVar1 = *(char *)(iVar2 + 0xb);
        if ((((cVar1 == '\a') || (cVar1 == '\b')) || (cVar1 == '\t')) ||
           ((cVar1 == '\f' || (cVar1 == '\x0e')))) {
          _free((void *)in_ECX[4]);
          return;
        }
        if (*(int *)(in_ECX[4] + 0xc) - 100U <= param_1) {
          FUN_0052bff0();
          return;
        }
      }
    }
  }
  return;
}


// ==== FUN_0052c450 @ 0x0052c450 ====

uint FUN_0052c450(int *param_1,undefined4 *param_2)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = (**(code **)(*param_1 + 4))();
  if (uVar2 == 0x40001) {
    cVar1 = (**(code **)(*(int *)*param_2 + 0x2c))();
    if (cVar1 != '\0') {
      FUN_0052c390(param_1[3]);
    }
    uVar2 = FUN_0052bcb0();
  }
  else if (uVar2 == 0x30060031) {
    uVar2 = FUN_0052c120(param_1);
    return uVar2;
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_0052c4b0 @ 0x0052c4b0 ====

void FUN_0052c4b0(int *param_1)

{
  short sVar1;
  int in_ECX;
  undefined1 *puVar2;
  undefined1 auStack_54 [4];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 uStack_44;
  undefined1 uStack_43;
  undefined1 uStack_42;
  undefined1 uStack_41;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 uStack_34;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 uStack_18;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(int *)(in_ECX + 0x20) != 0) {
    (**(code **)(*param_1 + 0xc))();
    if (*(char *)(in_ECX + 0x1e) == '\0') {
      uStack_50 = 0;
      uStack_4c = 0;
      uStack_48 = 0;
      uStack_20 = 0xf;
      uStack_24 = 0;
      uStack_34 = 0;
      uStack_4 = 0xf;
      uStack_8 = 0;
      uStack_18 = 0;
      uStack_41 = 0;
      uStack_44 = 0;
      uStack_43 = 0;
      uStack_42 = 0;
      uStack_3c = DAT_0099d080;
      uStack_40 = 0xffffffff;
      FUN_00401660(*(undefined4 *)(in_ECX + 0x20),0,0xffffffff);
      FUN_00401660(*(int *)(in_ECX + 0x20) + 0x1c,0,0xffffffff);
      FUN_004ff800(&uStack_44);
      puVar2 = auStack_54;
      FUN_00511d10(puVar2);
      FUN_00512cd0();
      FUN_00512a20(puVar2);
      sVar1 = *(short *)(*(int *)(in_ECX + 0x20) + 0x38);
      if (sVar1 != 0) {
        FUN_004dd240(0x19,3,1,sVar1,*(undefined4 *)(in_ECX + 8));
      }
      *(undefined1 *)(in_ECX + 0x1e) = 1;
      FUN_004107d0();
      FUN_004ff750();
    }
    (**(code **)(*param_1 + 0x10))();
  }
  return;
}


// ==== FUN_0052c5c0 @ 0x0052c5c0 ====

void FUN_0052c5c0(byte param_1)

{
  void *in_ECX;
  
  FUN_0052bbd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0052c5e0 @ 0x0052c5e0 ====

void FUN_0052c5e0(undefined2 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined2 *)(in_ECX + 0x40);
  return;
}


// ==== FUN_0052c5f0 @ 0x0052c5f0 ====

void FUN_0052c5f0(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x40) = *param_1;
  return;
}


// ==== FUN_0052c600 @ 0x0052c600 ====

undefined1 FUN_0052c600(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x3c);
}


// ==== FUN_0052c610 @ 0x0052c610 ====

void FUN_0052c610(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x3c) = param_1;
  return;
}


// ==== FUN_0052c620 @ 0x0052c620 ====

void FUN_0052c620(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x3d) = param_1;
  return;
}


// ==== FUN_0052c630 @ 0x0052c630 ====

undefined1 FUN_0052c630(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x3d);
}


// ==== FUN_0052c660 @ 0x0052c660 ====

void FUN_0052c660(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x3f) = param_1;
  return;
}


// ==== FUN_0052c670 @ 0x0052c670 ====

undefined1 FUN_0052c670(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x3f);
}


// ==== FUN_0052c680 @ 0x0052c680 ====

void FUN_0052c680(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x4c) == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0052c690. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(**(int **)(in_ECX + 0x48) + 8) + 0xc))();
  return;
}


// ==== FUN_0052c6a0 @ 0x0052c6a0 ====

undefined4 FUN_0052c6a0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x4c) == 0) {
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x0052c6b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(**(int **)(in_ECX + 0x48) + 8) + 8))();
  return uVar1;
}


// ==== FUN_0052c6c0 @ 0x0052c6c0 ====

undefined4 FUN_0052c6c0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x4c) == 0) {
    return 0;
  }
  return *(undefined4 *)(**(int **)(in_ECX + 0x48) + 8);
}


// ==== FUN_0052c6e0 @ 0x0052c6e0 ====

void FUN_0052c6e0(void)

{
  uint in_ECX;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x4c) == 0) {
    return;
  }
  local_4 = in_ECX & 0xffffff00;
  FUN_00528030(**(undefined4 **)(in_ECX + 0x48),*(undefined4 **)(in_ECX + 0x48),local_4);
  FUN_00510b80();
  return;
}


// ==== FUN_0052c720 @ 0x0052c720 ====

void FUN_0052c720(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b87b4;
  *(undefined1 *)(in_ECX + 0xf) = 1;
  *(undefined1 *)((int)in_ECX + 0x3d) = 1;
  *(undefined1 *)((int)in_ECX + 0x3e) = 1;
  *(undefined1 *)((int)in_ECX + 0x3f) = 0;
  uVar2 = FUN_005170b0();
  uVar1 = DAT_0099d080;
  in_ECX[0x12] = uVar2;
  in_ECX[0x13] = 0;
  in_ECX[3] = 100;
  in_ECX[4] = 100;
  in_ECX[6] = 0;
  uVar2 = DAT_0099d0f8;
  in_ECX[9] = uVar1;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = uVar2;
  in_ECX[0xe] = 0;
  in_ECX[10] = 0;
  in_ECX[0xc] = 0;
  return;
}


// ==== FUN_0052c830 @ 0x0052c830 ====

uint FUN_0052c830(void)

{
  int *_Memory;
  uint in_EAX;
  uint extraout_EAX;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x4c) == 0) {
    return in_EAX & 0xffffff00;
  }
  _Memory = (int *)**(int **)(in_ECX + 0x48);
  if (_Memory == *(int **)(in_ECX + 0x48)) {
    return CONCAT31((int3)((uint)_Memory >> 8),1);
  }
  *(int *)_Memory[1] = *_Memory;
  *(int *)(*_Memory + 4) = _Memory[1];
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_0052c870 @ 0x0052c870 ====

void FUN_0052c870(int param_1)

{
  int in_ECX;
  
  FUN_005280c0(*(undefined4 *)(in_ECX + 0x48),**(undefined4 **)(param_1 + 4),
               *(undefined4 **)(param_1 + 4),param_1);
  return;
}


// ==== FUN_0052c8a0 @ 0x0052c8a0 ====

void FUN_0052c8a0(undefined1 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x48);
  iVar2 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_1);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}


// ==== FUN_0052c8e0 @ 0x0052c8e0 ====

void FUN_0052c8e0(byte param_1)

{
  undefined4 *in_ECX;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b87b4;
  if (in_ECX[0x13] != 0) {
    local_4 = (uint)in_ECX & 0xffffff00;
    FUN_00528030(*(undefined4 *)in_ECX[0x12],(undefined4 *)in_ECX[0x12],local_4);
    FUN_00510b80();
  }
  FUN_008984a0();
  *in_ECX = &PTR_FUN_009b8184;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0052c950 @ 0x0052c950 ====

undefined1 FUN_0052c950(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_0052c960 @ 0x0052c960 ====

void FUN_0052c960(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
  uStack_8 = *puVar1;
  iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))();
  uStack_4 = *(undefined4 *)(iVar2 + 4);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
  (**(code **)(*piVar3 + 0x40))(&uStack_8);
  return;
}


// ==== FUN_0052c9b0 @ 0x0052c9b0 ====

void FUN_0052c9b0(void)

{
  return;
}


// ==== FUN_0052c9f0 @ 0x0052c9f0 ====

uint FUN_0052c9f0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  return uVar1 & 0xffffff00;
}


// ==== FUN_0052ca00 @ 0x0052ca00 ====

void FUN_0052ca00(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  char cVar3;
  undefined1 uStack00000000;
  undefined1 auStackY_9c [128];
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
  (**(code **)(*piVar1 + 0x4c))(param_1);
  piVar1 = (int *)(**(code **)(*DAT_00b5a6fc + 8))();
  if (piVar1 != (int *)0x0) {
    cVar3 = (char)param_1;
    if ((*(char *)(in_ECX + 4) == '\0') && (cVar3 == '\x01')) {
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
      (**(code **)(*piVar2 + 0x28))(0);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
      (**(code **)(*piVar2 + 8))();
      (**(code **)(*piVar1 + 0x54))(auStackY_9c + 0x98,*(undefined4 *)(in_ECX + 0xc));
      *(undefined1 *)(in_ECX + 4) = 1;
      *(undefined1 *)(in_ECX + 4) = 1;
      return;
    }
    if ((*(char *)(in_ECX + 4) == '\x01') && (cVar3 == '\0')) {
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
      (**(code **)(*piVar2 + 8))();
      (**(code **)(*piVar1 + 0x58))(&uStack00000000);
      *(undefined1 *)(in_ECX + 4) = 0;
    }
    *(char *)(in_ECX + 4) = cVar3;
  }
  return;
}


// ==== FUN_0052cab0 @ 0x0052cab0 ====

void FUN_0052cab0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  undefined4 auStack_8 [2];
  
  if (*(char *)(in_ECX + 4) != '\0') {
    piVar1 = (int *)(**(code **)(*DAT_00b5a6fc + 8))();
    if (piVar1 == (int *)0x0) {
      return;
    }
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    auStack_8[0] = (**(code **)(*piVar2 + 8))();
    iVar3 = (**(code **)(*piVar1 + 0x30))(auStack_8);
    if (iVar3 == 0) {
      return;
    }
    (**(code **)(*piVar1 + 0x40))(iVar3);
  }
  piVar1 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
  if (piVar1 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    auStack_8[0] = (**(code **)(*piVar2 + 8))();
    piVar2 = (int *)(**(code **)(*piVar1 + 0x30))(auStack_8);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*DAT_00b5a6f8 + 0x10))(1,*(undefined4 *)(*piVar2 + 4));
      (**(code **)(*piVar1 + 0x40))(piVar2);
      *(undefined1 *)(in_ECX + 4) = 0;
    }
  }
  return;
}


// ==== FUN_0052cb90 @ 0x0052cb90 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0052cb90(float param_1)

{
  float fVar1;
  float fVar2;
  
  if ((int)param_1 < 100) {
    fVar2 = (float)(int)param_1 * DAT_009a09b8;
    fVar1 = DAT_0099d0f8;
  }
  else {
    fVar2 = ((float)(int)param_1 - DAT_0099de78) * _DAT_009b832c;
    fVar1 = DAT_0099d080;
  }
  fVar1 = fVar1 - fVar2;
  if (DAT_0099d0f8 < fVar1) {
    return (float10)DAT_0099d0f8;
  }
  param_1 = DAT_009b8328;
  if (DAT_009b8328 <= fVar1) {
    param_1 = fVar1;
  }
  return (float10)param_1;
}


// ==== FUN_0052cc10 @ 0x0052cc10 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0052cc10(float param_1,int param_2)

{
  int *piVar1;
  int in_ECX;
  float10 fVar2;
  float fVar3;
  float fVar4;
  
  if (99 < param_2) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    fVar2 = (float10)(**(code **)(*piVar1 + 0x18))(param_1);
    fVar4 = (param_1 - DAT_0099de78) * _DAT_009b836c + DAT_0099d080;
    fVar3 = DAT_009b8368;
    if ((DAT_009b8368 < fVar4) || (fVar3 = DAT_009a09b8, fVar4 < DAT_009a09b8)) {
      fVar4 = fVar3;
    }
    return (float10)(fVar4 * (float)fVar2);
  }
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  fVar2 = (float10)(**(code **)(*piVar1 + 0x18))(param_1);
  fVar3 = param_1 * _DAT_009b836c + DAT_009a09b8;
  if (DAT_009b8368 < fVar3) {
    return (float10)(DAT_009b8368 * (float)fVar2);
  }
  fVar4 = DAT_009a09b8;
  if (DAT_009a09b8 <= fVar3) {
    fVar4 = fVar3;
  }
  return (float10)(fVar4 * (float)fVar2);
}


// ==== FUN_0052cd00 @ 0x0052cd00 ====

void FUN_0052cd00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b88c8;
  FUN_0052cab0();
  *in_ECX = &PTR_FUN_009b7ed4;
  return;
}


// ==== FUN_0052cd20 @ 0x0052cd20 ====

void FUN_0052cd20(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 auStack_a [10];
  
  piVar2 = DAT_00b5a780;
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x1c))();
  piVar2 = (int *)(**(code **)(*piVar2 + 8))(iVar1 + 0x14);
  if (piVar2 == (int *)0x0) {
    return;
  }
  (**(code **)(*piVar2 + 0xc))(auStack_a + -6);
  return;
}


// ==== FUN_0052cd70 @ 0x0052cd70 ====

void FUN_0052cd70(int param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  float *pfVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  void *pvVar9;
  int in_ECX;
  float10 fVar10;
  float fStack_48;
  float fStack_44;
  undefined1 auStack_40 [16];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  float fStack_28;
  float fStack_24;
  undefined4 uStack_20;
  undefined1 uStack_1c;
  float fStack_18;
  float fStack_14;
  undefined4 uStack_10;
  float fStack_c;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    fVar1 = *(float *)(param_1 + 0xc);
    fVar2 = *(float *)(param_1 + 0x10);
    pfVar4 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
    fStack_44 = fVar2 - pfVar4[1];
    fStack_48 = fVar1 - *pfVar4;
    thunk_FUN_0079de77(auStack_40,&fStack_48);
    puVar5 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
    uStack_30 = *puVar5;
    uStack_2c = puVar5[1];
    fStack_28 = fStack_48;
    fStack_18 = fStack_48;
    fStack_24 = fStack_44;
    fStack_14 = fStack_44;
    uStack_1c = 0;
    uStack_10 = CONCAT31(uStack_10._1_3_,*(char *)(param_1 + 8) == '\x01');
    uStack_20 = uVar3;
    iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
    fVar10 = (float10)FUN_0052cc10(uStack_10,*(undefined4 *)(iVar6 + 0x10));
    fStack_c = (float)fVar10;
    FUN_00507870(&uStack_30,auStack_40);
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = &PTR_FUN_009b2d88;
    }
    piVar7 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    uVar8 = (**(code **)(*piVar7 + 8))();
    puVar5[1] = uVar8;
    FUN_00403e60(puVar5 + 2,auStack_40,0x19);
    FUN_00797a20(puVar5);
    pvVar9 = operator_new(0x400);
    *(undefined4 *)((int)pvVar9 + 8) = uVar3;
    *(undefined4 *)((int)pvVar9 + 0xc) = 0x50d0000;
    *(undefined2 *)((int)pvVar9 + 6) = 0x30;
    iVar6 = FUN_004244d0();
    piVar7 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    uVar3 = (**(code **)(*piVar7 + 8))();
    *(undefined4 *)(iVar6 + 0x10) = uVar3;
    FUN_00403e60(iVar6 + 0x14,auStack_40,0x10);
    FUN_004d8570(iVar6);
  }
  return;
}


// ==== FUN_0052cf00 @ 0x0052cf00 ====

void FUN_0052cf00(int *param_1)

{
  uint uVar1;
  uint *puVar2;
  undefined2 *puVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  undefined4 *in_ECX;
  int iStack_ec;
  uint *puStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  uint uStack_b4;
  uint uStack_b0;
  uint uStack_ac;
  undefined4 uStack_a8;
  uint uStack_a4;
  undefined4 uStack_a0;
  uint uStack_9c;
  undefined4 uStack_98;
  uint uStack_94;
  undefined4 uStack_90;
  uint uStack_8c;
  undefined4 uStack_88;
  uint uStack_84;
  undefined4 uStack_80;
  uint uStack_7c;
  undefined4 uStack_78;
  void *pvStack_58;
  undefined2 auStack_54 [2];
  undefined4 uStack_50;
  int iStack_4c;
  int *piStack_48;
  uint uStack_44;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  
  *in_ECX = &PTR_FUN_009b88c8;
  in_ECX[2] = param_1;
  *(undefined1 *)(in_ECX + 1) = 0;
  puVar2 = (uint *)(**(code **)(*param_1 + 0x28))();
  uVar1 = *puVar2;
  uStack_b0 = puVar2[1];
  uStack_ac = 0;
  uStack_dc = (TypeDescriptor *)0x52cf66;
  uStack_b4 = uVar1;
  FUN_004ef0e0();
  puVar3 = (undefined2 *)FUN_005e0c90();
  *(undefined2 *)((int)in_ECX + 6) = *puVar3;
  piVar4 = (int *)(**(code **)(*param_1 + 0x14))();
  uStack_e4 = (**(code **)(*piVar4 + 0x24))();
  uStack_dc = &Framework::ICreature::RTTI_Type_Descriptor;
  uStack_e0 = 0;
  puStack_e8 = (uint *)0x52cf96;
  piStack_48 = (int *)FUN_00803725();
  if (piStack_48 == (int *)0x0) {
    uStack_44 = 0xf;
    pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
    uStack_dc = (TypeDescriptor *)0x52cfc8;
    FUN_00401740();
    FUN_00796d50();
    if (0xf < uStack_44) {
      _free(pvStack_58);
      return;
    }
  }
  else {
    uStack_dc = (TypeDescriptor *)0x0;
    uStack_e0 = 0x52d009;
    piVar4 = (int *)(**(code **)(*(int *)piStack_48[0x14] + 0x14))();
    uStack_e0 = 0x52d012;
    puVar3 = (undefined2 *)(**(code **)(*piStack_48 + 0x28))();
    uStack_e0 = 0;
    uStack_e4 = 1;
    puStack_e8 = (uint *)0x52d03b;
    uVar5 = (**(code **)(*DAT_00b5a6f8 + 0xc))();
    in_ECX[3] = uVar5;
    puStack_e8 = (uint *)0x52d046;
    piVar6 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x14))();
    puStack_e8 = (uint *)0x52d04d;
    uStack_b4 = (**(code **)(*piVar6 + 8))();
    puStack_e8 = (uint *)0x52d059;
    iVar7 = (**(code **)(*(int *)in_ECX[2] + 0x14))();
    uStack_b0 = *(undefined4 *)(iVar7 + 0xc);
    puStack_e8 = (uint *)0x52d06a;
    piVar6 = (int *)(**(code **)(*(int *)in_ECX[3] + 0xc))();
    puStack_e8 = &uStack_b4;
    iStack_ec = 0x52d076;
    (**(code **)(*piVar6 + 0x10))();
    iStack_ec = 0x52d081;
    piVar6 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
    if (piVar6 != (int *)0x0) {
      iStack_ec = (int)register0x00000010 + -0xd8;
      piVar6 = (int *)(**(code **)(*piVar6 + 0x30))();
      if ((piVar6 != (int *)0x0) && (*(int **)(*piVar6 + 4) != (int *)0x0)) {
        piVar6 = (int *)(**(code **)(**(int **)(*piVar6 + 4) + 0xc))();
        (**(code **)(*piVar6 + 0x20))(uVar1);
      }
      auStack_54[0] = puVar3[0x16];
      uStack_50 = 0;
      iVar7 = (**(code **)(*piVar4 + 8))();
      iStack_4c = (int)*(float *)(iVar7 + 0xc);
      piStack_48 = *(int **)(puVar3 + 0x18);
      uStack_2c = 0;
      uStack_2b = 0;
      piVar4 = (int *)(**(code **)(*(int *)in_ECX[3] + 0xc))();
      (**(code **)(*piVar4 + 0x14))(auStack_54);
      uStack_b4 = (uint)*(byte *)(puVar3 + 0x86);
      uStack_b0 = *(uint *)(puVar3 + 0x88);
      uStack_ac = (uint)*(byte *)(puVar3 + 0xba);
      uStack_a8 = *(undefined4 *)(puVar3 + 0xbc);
      uStack_a4 = (uint)*(byte *)(puVar3 + 0xa0);
      uStack_a0 = *(undefined4 *)(puVar3 + 0xa2);
      uStack_9c = (uint)*(byte *)(puVar3 + 0xd4);
      uStack_98 = *(undefined4 *)(puVar3 + 0xd6);
      uStack_94 = (uint)*(byte *)(puVar3 + 0x108);
      uStack_90 = *(undefined4 *)(puVar3 + 0x10a);
      uStack_8c = (uint)*(byte *)(puVar3 + 0xee);
      uStack_88 = *(undefined4 *)(puVar3 + 0xf0);
      uStack_84 = (uint)*(byte *)(puVar3 + 0xee);
      uStack_80 = *(undefined4 *)(puVar3 + 0xf0);
      uStack_7c = (uint)*(byte *)(puVar3 + 0x13c);
      uStack_78 = *(undefined4 *)(puVar3 + 0x13e);
      piVar4 = (int *)(**(code **)(*(int *)in_ECX[3] + 0xc))();
      (**(code **)(*piVar4 + 0x18))(&uStack_b4);
      uVar5 = (**(code **)(*DAT_00b5a6f4 + 8))(puVar3[0x77]);
      piVar4 = (int *)(**(code **)(*(int *)in_ECX[3] + 0x28))();
      (**(code **)(*piVar4 + 4))(uVar5);
      piVar4 = (int *)(**(code **)(*DAT_00b5a714 + 8))(*puVar3);
      uVar5 = (**(code **)(*piVar4 + 8))();
      (**(code **)(*(int *)in_ECX[3] + 0x44))(uVar5);
      piVar4 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
      if (piVar4 != (int *)0x0) {
        piVar6 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x14))();
        iStack_ec = (**(code **)(*piVar6 + 8))();
        (**(code **)(*piVar4 + 0x54))(&iStack_ec,in_ECX[3]);
      }
    }
  }
  return;
}


// ==== FUN_0052d270 @ 0x0052d270 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0052d270(int param_1)

{
  int iVar1;
  int *piVar2;
  float *pfVar3;
  float *pfVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int in_ECX;
  undefined4 unaff_ESI;
  float10 fVar9;
  undefined1 auStack_56 [6];
  float fStack_50;
  float fStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  float fStack_40;
  int iStack_3c;
  undefined4 uStack_38;
  undefined2 uStack_34;
  undefined1 uStack_32;
  undefined1 uStack_31;
  undefined2 uStack_30;
  undefined1 uStack_2e;
  int iStack_2d;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  int iStack_8;
  uint uStack_4;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    iVar1 = FUN_0052cd20(0,*(undefined4 *)(param_1 + 0xc));
    if (iVar1 == 0) {
      (**(code **)(**(int **)(in_ECX + 8) + 0x1c))();
      FUN_00401740(s_Cannot_Find__u_Monster__u__Attac_009b8810,0x28);
      FUN_00404230(auStack_1c);
      FUN_00796d50(auStack_1c);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
    }
    else {
      piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 8));
      if (piVar2 == (int *)0x0) {
        (**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
        return;
      }
      pfVar3 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
      pfVar4 = (float *)(**(code **)(*piVar2 + 0x28))();
      fStack_50 = *pfVar4 - *pfVar3;
      fStack_4c = pfVar4[1] - pfVar3[1];
      if (SQRT(fStack_4c * fStack_4c + fStack_50 * fStack_50) <= _DAT_009b88c0) {
        pfVar3 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
        fStack_50 = *pfVar3;
        fStack_4c = pfVar3[1];
      }
      else {
        thunk_FUN_0079de77(&uStack_48,&fStack_50);
      }
      puVar5 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
      uStack_48 = *puVar5;
      iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))();
      uStack_44 = *(undefined4 *)(iVar6 + 4);
      fVar9 = (float10)FUN_0040d5f0(&fStack_50);
      fStack_40 = (float)fVar9;
      (**(code **)(*piVar2 + 0x28))();
      (**(code **)(*piVar2 + 0x28))();
      iVar6 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      FUN_00797a50(&iStack_3c,0,0x13);
      uStack_31 = 6;
      uStack_32 = 0;
      iStack_3c = iVar6;
      puVar5 = (undefined4 *)FUN_004ef0e0(auStack_56 + -10);
      uStack_38 = *puVar5;
      uStack_2e = *(undefined1 *)(param_1 + 0xc);
      uStack_34 = *(undefined2 *)(puVar5 + 1);
      uStack_30 = FUN_004eefa0(unaff_ESI);
      iVar7 = (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
      fVar9 = (float10)FUN_0052cb90(*(undefined4 *)(iVar7 + 0xc));
      iStack_2d = iVar6 - (int)ROUND(fVar9 * (float10)*(float *)(iVar1 + 0x114) *
                                     (float10)DAT_0099d0f4);
      puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        *puVar5 = &PTR_FUN_009b2d88;
      }
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
      uVar8 = (**(code **)(*piVar2 + 8))();
      puVar5[1] = uVar8;
      FUN_00403e60(puVar5 + 2,&iStack_3c,0x19);
      FUN_00797a20(puVar5);
      iVar7 = FUN_004eef70(iVar6);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
      uVar8 = (**(code **)(*piVar2 + 8))();
      *(undefined4 *)(iVar7 + 0x10) = uVar8;
      FUN_00403e60(iVar7 + 0x14,&iStack_3c,0x13);
      FUN_004d8570(iVar7);
      puVar5 = operator_new(0x14);
      *(undefined1 *)(puVar5 + 2) = 0;
      *(undefined1 *)((int)puVar5 + 5) = *(undefined1 *)(iVar1 + 0x119);
      *(undefined1 *)(puVar5 + 1) = *(undefined1 *)(iVar1 + 0x118);
      *(undefined1 *)((int)puVar5 + 7) = *(undefined1 *)(iStack_8 + 0xc);
      iVar7 = FUN_004ef0e0(auStack_56 + -10);
      *(undefined1 *)((int)puVar5 + 6) = *(undefined1 *)(iVar7 + 4);
      puVar5[3] = iVar6 - (int)ROUND(*(float *)(iVar1 + 0x11c) * *(float *)(iVar1 + 0x114) *
                                     DAT_0099d0f4);
      *puVar5 = *(undefined4 *)(iStack_8 + 8);
      *(undefined1 *)(puVar5 + 4) = *(undefined1 *)(iStack_8 + 0x10);
      uVar8 = (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
      iVar1 = FUN_00803725(uVar8,0,&Framework::ModelCenter::Actors::Info::IActorInfo::
                                    RTTI_Type_Descriptor,
                           &Framework::ModelCenter::Actors::Info::Servant::RTTI_Type_Descriptor,0);
      if (iVar1 != 0) {
        FUN_0052df40(puVar5);
      }
    }
  }
  return;
}


// ==== FUN_0052d600 @ 0x0052d600 ====

void FUN_0052d600(int param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int in_ECX;
  float10 fVar7;
  undefined1 auStack_42 [6];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined2 uStack_2c;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined4 uStack_28;
  undefined4 uStack_24;
  float fStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = uVar1;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x50d0000;
    *(undefined2 *)((int)pvVar2 + 6) = 0x30;
    iVar3 = FUN_004244d0();
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    uVar5 = (**(code **)(*piVar4 + 8))();
    *(undefined4 *)(iVar3 + 0x10) = uVar5;
    FUN_00797a50(&uStack_34,0,0xc);
    uStack_29 = 1;
    uStack_2a = 0;
    uStack_34 = uVar1;
    puVar6 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
    uStack_3c = *puVar6;
    uStack_38 = puVar6[1];
    uStack_28 = *(undefined4 *)(param_1 + 8);
    uStack_24 = *(undefined4 *)(param_1 + 0xc);
    fVar7 = (float10)FUN_0040d5f0(&uStack_3c);
    fStack_20 = (float)fVar7;
    puVar6 = (undefined4 *)FUN_004ef0e0(auStack_42);
    uStack_30 = *puVar6;
    uStack_2c = *(undefined2 *)(puVar6 + 1);
    puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      *puVar6 = &PTR_FUN_009b2d88;
    }
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    uVar1 = (**(code **)(*piVar4 + 8))();
    puVar6[1] = uVar1;
    FUN_00403e60(puVar6 + 2,&uStack_34,0x19);
    FUN_00797a20(puVar6);
    FUN_00403e60(iVar3 + 0x14,&uStack_34,0xc);
    FUN_004d8570(iVar3);
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_00401740(s_______________________________Se_009b883c,0x30);
    FUN_00796d50(auStack_1c);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
  }
  return;
}


// ==== FUN_0052d790 @ 0x0052d790 ====

void FUN_0052d790(int param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int in_ECX;
  float10 fVar7;
  undefined1 auStack_42 [6];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined2 uStack_2c;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined4 uStack_28;
  undefined4 uStack_24;
  float fStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = uVar1;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x50d0000;
    *(undefined2 *)((int)pvVar2 + 6) = 0x30;
    iVar3 = FUN_004244d0();
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    uVar5 = (**(code **)(*piVar4 + 8))();
    *(undefined4 *)(iVar3 + 0x10) = uVar5;
    FUN_00797a50(&uStack_34,0,0xc);
    uStack_29 = 1;
    uStack_2a = 0;
    uStack_34 = uVar1;
    puVar6 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
    uStack_3c = *puVar6;
    uStack_38 = puVar6[1];
    uStack_28 = *(undefined4 *)(param_1 + 8);
    uStack_24 = *(undefined4 *)(param_1 + 0xc);
    fVar7 = (float10)FUN_0040d5f0(&uStack_3c);
    fStack_20 = (float)fVar7;
    puVar6 = (undefined4 *)FUN_004ef0e0(auStack_42);
    uStack_30 = *puVar6;
    uStack_2c = *(undefined2 *)(puVar6 + 1);
    puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      *puVar6 = &PTR_FUN_009b2d88;
    }
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    uVar1 = (**(code **)(*piVar4 + 8))();
    puVar6[1] = uVar1;
    FUN_00403e60(puVar6 + 2,&uStack_34,0x19);
    FUN_00797a20(puVar6);
    FUN_00403e60(iVar3 + 0x14,&uStack_34,0xc);
    FUN_004d8570(iVar3);
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_00401740(s_______________________________Se_009b8870,0x2f);
    FUN_00796d50(auStack_1c);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
  }
  return;
}


// ==== FUN_0052d920 @ 0x0052d920 ====

void FUN_0052d920(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b88c8;
  FUN_0052cab0();
  *in_ECX = &PTR_FUN_009b7ed4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0052d950 @ 0x0052d950 ====

undefined4 FUN_0052d950(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_0052d960 @ 0x0052d960 ====

void FUN_0052d960(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_0052d970 @ 0x0052d970 ====

void FUN_0052d970(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x1c) = param_1;
  return;
}


// ==== FUN_0052d980 @ 0x0052d980 ====

undefined4 FUN_0052d980(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x14);
}


// ==== FUN_0052d990 @ 0x0052d990 ====

undefined4 FUN_0052d990(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x14);
}


// ==== FUN_0052d9b0 @ 0x0052d9b0 ====

undefined1 FUN_0052d9b0(void)

{
  return 0;
}


// ==== FUN_0052d9c0 @ 0x0052d9c0 ====

undefined4 FUN_0052d9c0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x18) + 0x28);
}


// ==== FUN_0052d9d0 @ 0x0052d9d0 ====

undefined4 FUN_0052d9d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x18) + 0x28);
}


// ==== FUN_0052d9e0 @ 0x0052d9e0 ====

void FUN_0052d9e0(void)

{
  undefined2 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 0x14) + 0x1c))();
  FUN_004dd240(0,2,2,*puVar1,*(undefined4 *)(in_ECX + 8));
  return;
}


// ==== FUN_0052da10 @ 0x0052da10 ====

void FUN_0052da10(void)

{
  undefined2 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 0x14) + 0x1c))();
  FUN_004dd240(0,3,2,*puVar1,*(undefined4 *)(in_ECX + 8));
  return;
}


// ==== FUN_0052da40 @ 0x0052da40 ====

void FUN_0052da40(void)

{
  undefined2 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 0x14) + 0x1c))();
  FUN_004dd240(0,4,2,*puVar1,*(undefined4 *)(in_ECX + 8));
  return;
}


// ==== FUN_0052da70 @ 0x0052da70 ====

void FUN_0052da70(undefined4 param_1)

{
  undefined4 uVar1;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0x34))(0,in_ECX[2]);
  FUN_004dd240(3,param_1,uVar1);
  return;
}


// ==== FUN_0052da90 @ 0x0052da90 ====

void FUN_0052da90(void)

{
  undefined2 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 0x14) + 0x1c))();
  FUN_004dd240(0,5,2,*puVar1,*(undefined4 *)(in_ECX + 8));
  return;
}


// ==== FUN_0052dac0 @ 0x0052dac0 ====

void FUN_0052dac0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b89dc;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 7) = 0;
  *(undefined1 *)((int)in_ECX + 0x1d) = 0;
  *(undefined1 *)((int)in_ECX + 0x1e) = 0;
  in_ECX[8] = 0;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_0052daf0 @ 0x0052daf0 ====

void FUN_0052daf0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b89dc;
  (**(code **)(*DAT_00b5ac6c + 0x18))(in_ECX[2]);
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b7950;
  }
  puVar1[1] = in_ECX[2];
  FUN_00797a20(puVar1);
  if (in_ECX[5] != 0) {
    (**(code **)(*DAT_00b5addc + 0x10))(1,in_ECX[5]);
  }
  in_ECX[6] = 0;
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_0052db70 @ 0x0052db70 ====

float10 FUN_0052db70(char param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x18);
  if (iVar1 == 0) {
    return (float10)DAT_009a09bc;
  }
  if (param_1 == '\0') {
    return (float10)*(float *)(iVar1 + 0x48);
  }
  return (float10)*(float *)(iVar1 + 0x4c);
}


// ==== FUN_0052dba0 @ 0x0052dba0 ====

undefined4 FUN_0052dba0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x18) + 0x24);
}


// ==== FUN_0052dbb0 @ 0x0052dbb0 ====

uint FUN_0052dbb0(void)

{
  void *_Memory;
  uint extraout_EAX;
  int in_ECX;
  
  _Memory = *(void **)(in_ECX + 0x10);
  if ((_Memory == (void *)0x0) || (*(char *)((int)_Memory + 8) == '\x01')) {
    return (uint)_Memory & 0xffffff00;
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_0052dbe0 @ 0x0052dbe0 ====

void FUN_0052dbe0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 uStack_c;
  int iStack_8;
  
  iVar1 = (**(code **)(*in_ECX + 0x68))();
  if (*(char *)(iVar1 + 0x14) == '\x01') {
    if (*(char *)((int)in_ECX + 0x1d) == '\0') {
      puVar2 = operator_new(0x10);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = &PTR_FUN_009b7964;
        puVar2[3] = 0;
        *(undefined1 *)(puVar2 + 2) = 1;
      }
      uVar3 = (**(code **)(*in_ECX + 8))();
      puVar2[1] = uStack_c;
      iStack_8 = CONCAT31(iStack_8._1_3_,1);
      puVar2[2] = iStack_8;
      puVar2[3] = uVar3;
      FUN_00797a20(puVar2);
      *(undefined1 *)((int)in_ECX + 0x1d) = 1;
      return;
    }
  }
  else if (*(char *)((int)in_ECX + 0x1d) == '\x01') {
    puVar2 = operator_new(0x10);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009b7964;
      puVar2[3] = 0;
      *(undefined1 *)(puVar2 + 2) = 1;
    }
    uVar3 = (**(code **)(*in_ECX + 8))();
    puVar2[1] = uStack_c;
    iStack_8 = (uint)iStack_8._1_3_ << 8;
    puVar2[2] = iStack_8;
    puVar2[3] = uVar3;
    FUN_00797a20(puVar2);
    *(undefined1 *)((int)in_ECX + 0x1d) = 0;
  }
  return;
}


// ==== FUN_0052dcb0 @ 0x0052dcb0 ====

undefined1 FUN_0052dcb0(void)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5ac1c + 0x18))();
  if (cVar1 == '\0') {
    return 0;
  }
  return *(undefined1 *)(in_ECX + 0x1c);
}


// ==== FUN_0052dcd0 @ 0x0052dcd0 ====

void FUN_0052dcd0(byte param_1,byte param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_retaddr;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 uStack_4;
  
  if (in_ECX[8] != 0) {
    (**(code **)(*DAT_00b5ac6c + 0x18))(in_ECX[2]);
    (**(code **)(*in_ECX + 0x30))();
    iVar3 = **(int **)(in_ECX[5] + 0x50);
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    piVar2 = (int *)(**(code **)(iVar3 + 0x14))(uVar1);
    iVar3 = (**(code **)(*piVar2 + 0x18))();
    iVar3 = (int)ROUND(*(float *)(iVar3 + 0xc));
    if (param_3 == 3) {
      uVar6 = 0;
    }
    else if (param_3 == 4) {
      uVar6 = 1;
    }
    else {
      uVar6 = (param_3 != 5) - 1 & 2;
    }
    uVar5 = (uint)param_2;
    iVar7 = in_ECX[8];
    uVar4 = (uint)param_1;
    iVar8 = iVar7 + 0x1c;
    uVar9 = uVar6;
    FUN_00511d20(iVar7,iVar8,uStack_4,uVar4,uVar6,uVar5,unaff_retaddr,iVar3);
    FUN_00511c30(iVar7,iVar8,uStack_4,uVar4,uVar9,uVar5,unaff_retaddr,iVar3);
    uVar1 = (**(code **)(*in_ECX + 0x34))(uVar6,0,in_ECX[2]);
    FUN_004dd240(7,uVar1);
  }
  return;
}


// ==== FUN_0052ddc0 @ 0x0052ddc0 ====

undefined4 FUN_0052ddc0(int *param_1)

{
  float fVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  float *pfVar7;
  int *in_ECX;
  float unaff_EDI;
  float10 extraout_ST0;
  float fStack_14;
  undefined4 uStack_10;
  
  iVar3 = (**(code **)(*param_1 + 0x10))();
  iVar4 = (**(code **)(*in_ECX + 8))();
  if (iVar3 != iVar4) {
    return 0;
  }
  iVar3 = *DAT_00b5acd8;
  uVar5 = (**(code **)(*param_1 + 0x14))();
  piVar6 = (int *)(**(code **)(iVar3 + 0xc))(uVar5);
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 0x28))();
    iVar3 = *DAT_00b5acd8;
    uVar5 = (**(code **)(*in_ECX + 8))();
    piVar6 = (int *)(**(code **)(iVar3 + 0xc))(uVar5);
    if (piVar6 != (int *)0x0) {
      pfVar7 = (float *)(**(code **)(*piVar6 + 0x28))();
      fVar1 = *pfVar7;
      iVar3 = *DAT_00b5a6b4;
      uVar5 = (**(code **)(*in_ECX + 8))();
      (**(code **)(iVar3 + 0x1c))(uVar5);
      if (SQRT(unaff_EDI * unaff_EDI + (fVar1 - fStack_14) * (fVar1 - fStack_14)) <=
          (float)extraout_ST0 + DAT_0099d0f8) {
        iVar3 = (**(code **)(*DAT_00b5a6a8 + 4))();
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          uVar5 = (**(code **)(*param_1 + 0x14))();
          iVar3 = FUN_0052a580(uVar5);
        }
        uVar2 = (**(code **)(*in_ECX + 0x3c))();
        uStack_10 = CONCAT31(0x10000,uVar2);
        iVar4 = (**(code **)(*param_1 + 0x18))();
        if (iVar4 == 0) {
          uStack_10 = CONCAT13(1,CONCAT12(1,(undefined2)uStack_10));
        }
        *(float *)(iVar3 + 4) = (float)extraout_ST0;
        *(float *)(iVar3 + 8) = fStack_14;
        *(undefined4 *)(iVar3 + 0xc) = uStack_10;
        FUN_00797a20(iVar3);
        return 1;
      }
    }
  }
  return 1;
}


// ==== FUN_0052df40 @ 0x0052df40 ====

void FUN_0052df40(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 0x10));
  return;
}


// ==== FUN_0052dfb0 @ 0x0052dfb0 ====

int FUN_0052dfb0(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int in_ECX;
  char *pcVar4;
  
  iVar2 = *(int *)(in_ECX + 0x18);
  pcVar4 = (char *)(iVar2 + 8);
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  pcVar3 = pcVar4;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar4,(int)pcVar3 - (iVar2 + 9));
  return param_1;
}


// ==== FUN_0052dff0 @ 0x0052dff0 ====

void FUN_0052dff0(void)

{
  int iVar1;
  char cVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  if ((in_ECX[4] != 0) && (iVar1 = in_ECX[6], iVar1 != 0)) {
    uVar5 = *(undefined4 *)(in_ECX[4] + 0xc);
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar5;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x600000c;
    *(undefined2 *)((int)pvVar3 + 6) = 0x20;
    iVar4 = FUN_004244d0();
    uVar5 = (**(code **)(*in_ECX + 8))();
    *(undefined4 *)(iVar4 + 0x10) = uVar5;
    *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)in_ECX[4];
    *(undefined1 *)(iVar4 + 0x18) = *(undefined1 *)(in_ECX[4] + 4);
    *(undefined1 *)(iVar4 + 0x19) = *(undefined1 *)(in_ECX[4] + 5);
    *(undefined1 *)(iVar4 + 0x1b) =
         *(undefined1 *)(iVar1 + 0x100 + (uint)*(byte *)(in_ECX[4] + 7) * 0x34);
    *(undefined1 *)(iVar4 + 0x1a) = *(undefined1 *)(in_ECX[4] + 6);
    cVar2 = (**(code **)(*DAT_00b5ac1c + 0x24))();
    if (cVar2 == '\x01') {
      *(undefined1 *)(iVar4 + 0x1c) = *(undefined1 *)(in_ECX[4] + 0x10);
    }
    else {
      *(undefined1 *)(iVar4 + 0x1c) = 0;
    }
    *(undefined1 *)(iVar4 + 0x1d) = *(undefined1 *)(in_ECX[4] + 7);
    FUN_004d8570(iVar4);
    *(undefined1 *)(in_ECX[4] + 8) = 1;
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_00401740(s_>>>>>>>>>>>>>_Send_Servant_Hit_009b892c,0x2c);
    FUN_00796d20(auStack_1c);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
  }
  return;
}


// ==== FUN_0052e110 @ 0x0052e110 ====

undefined4 FUN_0052e110(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 extraout_EAX;
  int *in_ECX;
  undefined4 unaff_EBP;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  uint uStack_8;
  
  iVar2 = (**(code **)(*param_1 + 0x10))();
  iVar3 = (**(code **)(*in_ECX + 8))();
  if (iVar2 != iVar3) {
    return 0;
  }
  piVar1 = *(int **)(in_ECX[5] + 0x44);
  piVar4 = (int *)(**(code **)(*piVar1 + 0x18))();
  iVar2 = *piVar1;
  uVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(iVar2 + 0x1c))(uVar5);
  FUN_00401740(s_Update_Servant_HPMP____f__f_009b895c,0x1b);
  uVar5 = FUN_00404230(auStack_20);
  FUN_00796d50(uVar5);
  if (uStack_8 < 0x10) {
    (**(code **)(*piVar4 + 0x14))();
    (**(code **)(*piVar4 + 0x20))(unaff_EBP);
    return 1;
  }
  _free(pvStack_1c);
  return extraout_EAX;
}


// ==== FUN_0052e200 @ 0x0052e200 ====

void FUN_0052e200(float param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int *in_ECX;
  float unaff_retaddr;
  undefined4 uStack_1c;
  uint uStack_8;
  
  if (param_1 != DAT_0099cdc8) {
    iVar1 = (**(code **)(*in_ECX + 0x24))();
    piVar2 = (int *)FUN_00803725(iVar1,0,&Framework::ICreature::RTTI_Type_Descriptor,
                                 &Framework::Creature::IServant::RTTI_Type_Descriptor,0);
    iVar5 = *(int *)piVar2[0x14];
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    piVar4 = (int *)(**(code **)(iVar5 + 0x14))(uVar3);
    iVar5 = (**(code **)(*piVar2 + 0x28))();
    piVar2 = (int *)0x0;
    if (*(int **)(iVar1 + 0x44) != (int *)0x0) {
      piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x44) + 0x18))();
    }
    iVar1 = (**(code **)(*piVar4 + 8))();
    iVar1 = (int)(unaff_retaddr * DAT_0099d0b4 + *(float *)(iVar1 + 0xc));
    if (*(int *)(iVar5 + 0x30) < iVar1) {
      iVar1 = *(int *)(iVar5 + 0x30);
    }
    FUN_00401740(s_Update_Servant_HPMP______________009b8978,0x2c);
    uVar3 = FUN_00404230((int)register0x00000010 + -0x20);
    FUN_00796d50(uVar3);
    if (0xf < uStack_8) {
      _free(uStack_1c);
      return;
    }
    (**(code **)(*piVar2 + 0x14))((float)iVar1);
  }
  return;
}


// ==== FUN_0052e300 @ 0x0052e300 ====

void FUN_0052e300(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  char *pcVar5;
  int *in_ECX;
  char *pcVar6;
  void *unaff_ESI;
  undefined1 auStack_66 [10];
  uint uStack_5c;
  void *apvStack_4c [5];
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  void *pvStack_24;
  undefined4 auStack_20 [2];
  undefined1 uStack_18;
  uint uStack_10;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  in_ECX[5] = (int)param_1;
  iVar2 = (**(code **)(*param_1 + 0x28))();
  in_ECX[6] = iVar2;
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  uStack_30 = 0;
  uStack_28 = 0xffffffff;
  pvStack_24 = (void *)0xffffff;
  auStack_20[0] = 0x38;
  uStack_2c = uStack_2c & 0xffffff00;
  FUN_00401740(s_No_Name_009b79ec,7);
  uStack_28 = (**(code **)(*in_ECX + 8))();
  uStack_30 = 0;
  uVar3 = (**(code **)(*in_ECX + 0x40))(apvStack_4c);
  FUN_00401660(uVar3,0,0xffffffff);
  if (0xf < uStack_38) {
    _free(apvStack_4c[0]);
    return;
  }
  pvStack_24 = (void *)0x38;
  pvVar4 = operator_new(0x34);
  if (pvVar4 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00522170();
  }
  *(undefined4 *)(iVar2 + 4) = uStack_34;
  *(undefined1 *)(iVar2 + 8) = (undefined1)uStack_30;
  *(uint *)(iVar2 + 0xc) = uStack_2c;
  *(undefined4 *)(iVar2 + 0x10) = uStack_28;
  *(void **)(iVar2 + 0x14) = pvStack_24;
  FUN_00401660(auStack_20,0,0xffffffff);
  FUN_00797a20(iVar2);
  pcVar6 = (char *)(in_ECX[6] + 0x54);
  pcVar5 = pcVar6;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar6,(int)pcVar5 - (in_ECX[6] + 0x55));
  iVar2 = (**(code **)(*DAT_00b5a6dc + 0x1c))(2,auStack_66 + -6);
  in_ECX[8] = iVar2;
  if (0xf < uStack_5c) {
    _free(unaff_ESI);
    return;
  }
  if (uStack_10 < 0x10) {
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_0052e480 @ 0x0052e480 ====

void FUN_0052e480(uint param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  if ((in_ECX[4] != 0) && (*(char *)(in_ECX[4] + 8) == '\0')) {
    iVar2 = (**(code **)(*in_ECX + 0x24))();
    if ((*(int **)(iVar2 + 0x4c) != (int *)0x0) &&
       (piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x4c) + 0x18))(), piVar3 != (int *)0x0)) {
      (**(code **)(*piVar3 + 8))(param_1);
      iVar2 = (**(code **)(*piVar3 + 0x10))();
      if (iVar2 != 0) {
        cVar1 = *(char *)(iVar2 + 0xb);
        if ((((cVar1 == '\a') || (cVar1 == '\b')) || (cVar1 == '\t')) ||
           ((cVar1 == '\f' || (cVar1 == '\x0e')))) {
          _free((void *)in_ECX[4]);
          return;
        }
        if (*(int *)(in_ECX[4] + 0xc) - 100U <= param_1) {
          FUN_0052dff0();
          return;
        }
      }
    }
  }
  return;
}


// ==== FUN_0052e540 @ 0x0052e540 ====

uint FUN_0052e540(int *param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x40001) {
    cVar1 = (**(code **)(*(int *)*param_2 + 0x2c))();
    if (cVar1 != '\0') {
      FUN_0052e480(param_1[3]);
    }
    uVar3 = FUN_0052dbe0();
  }
  else {
    if (iVar2 == 0x30060031) {
      uVar3 = FUN_0052e110(param_1);
      return uVar3;
    }
    uVar3 = iVar2 + 0xcff9ffcc;
    if (uVar3 == 0) {
      uVar3 = FUN_0052ddc0(param_1);
      return uVar3;
    }
  }
  return uVar3 & 0xffffff00;
}


// ==== FUN_0052e5b0 @ 0x0052e5b0 ====

void FUN_0052e5b0(int *param_1)

{
  short sVar1;
  int in_ECX;
  undefined1 *puVar2;
  undefined1 auStack_54 [4];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 uStack_44;
  undefined1 uStack_43;
  undefined1 uStack_42;
  undefined1 uStack_41;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 uStack_34;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 uStack_18;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(int *)(in_ECX + 0x20) != 0) {
    (**(code **)(*param_1 + 0xc))();
    if (*(char *)(in_ECX + 0x1e) == '\0') {
      uStack_50 = 0;
      uStack_4c = 0;
      uStack_48 = 0;
      uStack_20 = 0xf;
      uStack_24 = 0;
      uStack_34 = 0;
      uStack_4 = 0xf;
      uStack_8 = 0;
      uStack_18 = 0;
      uStack_41 = 0;
      uStack_44 = 0;
      uStack_43 = 0;
      uStack_42 = 0;
      uStack_3c = DAT_0099d080;
      uStack_40 = 0xffffffff;
      FUN_00401660(*(undefined4 *)(in_ECX + 0x20),0,0xffffffff);
      FUN_00401660(*(int *)(in_ECX + 0x20) + 0x1c,0,0xffffffff);
      FUN_004ff800(&uStack_44);
      puVar2 = auStack_54;
      FUN_00511d10(puVar2);
      FUN_00512cd0();
      FUN_00512a20(puVar2);
      sVar1 = *(short *)(*(int *)(in_ECX + 0x20) + 0x38);
      if (sVar1 != 0) {
        FUN_004dd240(0x19,2,1,sVar1,*(undefined4 *)(in_ECX + 8));
      }
      *(undefined1 *)(in_ECX + 0x1e) = 1;
      FUN_004107d0();
      FUN_004ff750();
    }
    (**(code **)(*param_1 + 0x10))();
  }
  return;
}


// ==== FUN_0052e6c0 @ 0x0052e6c0 ====

void FUN_0052e6c0(byte param_1)

{
  void *in_ECX;
  
  FUN_0052daf0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0052e6e0 @ 0x0052e6e0 ====

void FUN_0052e6e0(undefined2 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined2 *)(in_ECX + 0x40);
  return;
}


// ==== FUN_0052e6f0 @ 0x0052e6f0 ====

void FUN_0052e6f0(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x40) = *param_1;
  return;
}


// ==== FUN_0052e700 @ 0x0052e700 ====

undefined1 FUN_0052e700(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x3c);
}


// ==== FUN_0052e710 @ 0x0052e710 ====

void FUN_0052e710(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x3c) = param_1;
  return;
}


// ==== FUN_0052e720 @ 0x0052e720 ====

void FUN_0052e720(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x3d) = param_1;
  return;
}


// ==== FUN_0052e730 @ 0x0052e730 ====

undefined1 FUN_0052e730(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x3d);
}


// ==== FUN_0052e760 @ 0x0052e760 ====

void FUN_0052e760(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x3f) = param_1;
  return;
}


// ==== FUN_0052e770 @ 0x0052e770 ====

undefined1 FUN_0052e770(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x3f);
}


// ==== FUN_0052e780 @ 0x0052e780 ====

void FUN_0052e780(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x4c) == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0052e790. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(**(int **)(in_ECX + 0x48) + 8) + 0xc))();
  return;
}


// ==== FUN_0052e7a0 @ 0x0052e7a0 ====

undefined4 FUN_0052e7a0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x4c) == 0) {
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x0052e7b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(**(int **)(in_ECX + 0x48) + 8) + 8))();
  return uVar1;
}


// ==== FUN_0052e7c0 @ 0x0052e7c0 ====

undefined4 FUN_0052e7c0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x4c) == 0) {
    return 0;
  }
  return *(undefined4 *)(**(int **)(in_ECX + 0x48) + 8);
}


// ==== FUN_0052e7e0 @ 0x0052e7e0 ====

void FUN_0052e7e0(void)

{
  uint in_ECX;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x4c) == 0) {
    return;
  }
  local_4 = in_ECX & 0xffffff00;
  FUN_00528030(**(undefined4 **)(in_ECX + 0x48),*(undefined4 **)(in_ECX + 0x48),local_4);
  FUN_00510b80();
  return;
}


// ==== FUN_0052e820 @ 0x0052e820 ====

void FUN_0052e820(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8a64;
  *(undefined1 *)(in_ECX + 0xf) = 1;
  *(undefined1 *)((int)in_ECX + 0x3d) = 1;
  *(undefined1 *)((int)in_ECX + 0x3e) = 1;
  *(undefined1 *)((int)in_ECX + 0x3f) = 0;
  uVar2 = FUN_005170b0();
  uVar1 = DAT_0099d080;
  in_ECX[0x12] = uVar2;
  in_ECX[0x13] = 0;
  in_ECX[3] = 100;
  in_ECX[4] = 100;
  in_ECX[6] = 0;
  uVar2 = DAT_0099d0f8;
  in_ECX[9] = uVar1;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = uVar2;
  in_ECX[0xe] = 0;
  in_ECX[10] = 0;
  in_ECX[0xc] = 0;
  return;
}


// ==== FUN_0052e930 @ 0x0052e930 ====

uint FUN_0052e930(void)

{
  int *_Memory;
  uint in_EAX;
  uint extraout_EAX;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x4c) == 0) {
    return in_EAX & 0xffffff00;
  }
  _Memory = (int *)**(int **)(in_ECX + 0x48);
  if (_Memory == *(int **)(in_ECX + 0x48)) {
    return CONCAT31((int3)((uint)_Memory >> 8),1);
  }
  *(int *)_Memory[1] = *_Memory;
  *(int *)(*_Memory + 4) = _Memory[1];
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_0052e970 @ 0x0052e970 ====

void FUN_0052e970(int param_1)

{
  int in_ECX;
  
  FUN_005280c0(*(undefined4 *)(in_ECX + 0x48),**(undefined4 **)(param_1 + 4),
               *(undefined4 **)(param_1 + 4),param_1);
  return;
}


// ==== FUN_0052e9a0 @ 0x0052e9a0 ====

void FUN_0052e9a0(undefined1 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x48);
  iVar2 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_1);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}


// ==== FUN_0052e9e0 @ 0x0052e9e0 ====

void FUN_0052e9e0(byte param_1)

{
  undefined4 *in_ECX;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b8a64;
  if (in_ECX[0x13] != 0) {
    local_4 = (uint)in_ECX & 0xffffff00;
    FUN_00528030(*(undefined4 *)in_ECX[0x12],(undefined4 *)in_ECX[0x12],local_4);
    FUN_00510b80();
  }
  FUN_008984a0();
  *in_ECX = &PTR_FUN_009b8184;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0052ea40 @ 0x0052ea40 ====

undefined4 FUN_0052ea40(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_0052ea50 @ 0x0052ea50 ====

void FUN_0052ea50(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_0052ea60 @ 0x0052ea60 ====

undefined4 FUN_0052ea60(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x28);
}


// ==== FUN_0052ea70 @ 0x0052ea70 ====

undefined4 FUN_0052ea70(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x28);
}


// ==== FUN_0052ea80 @ 0x0052ea80 ====

void FUN_0052ea80(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 uStack_c;
  int iStack_8;
  
  iVar1 = (**(code **)(*in_ECX + 0x68))();
  if (*(char *)(iVar1 + 0x14) == '\x01') {
    if ((char)in_ECX[0xb] == '\0') {
      puVar2 = operator_new(0x10);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = &PTR_FUN_009b7964;
        puVar2[3] = 0;
        *(undefined1 *)(puVar2 + 2) = 1;
      }
      uVar3 = (**(code **)(*in_ECX + 8))();
      puVar2[1] = uStack_c;
      iStack_8 = CONCAT31(iStack_8._1_3_,1);
      puVar2[2] = iStack_8;
      puVar2[3] = uVar3;
      FUN_00797a20(puVar2);
      *(undefined1 *)(in_ECX + 0xb) = 1;
      return;
    }
  }
  else if ((char)in_ECX[0xb] == '\x01') {
    puVar2 = operator_new(0x10);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009b7964;
      puVar2[3] = 0;
      *(undefined1 *)(puVar2 + 2) = 1;
    }
    uVar3 = (**(code **)(*in_ECX + 8))();
    puVar2[1] = uStack_c;
    iStack_8 = (uint)iStack_8._1_3_ << 8;
    puVar2[2] = iStack_8;
    puVar2[3] = uVar3;
    FUN_00797a20(puVar2);
    *(undefined1 *)(in_ECX + 0xb) = 0;
  }
  return;
}


// ==== FUN_0052eb50 @ 0x0052eb50 ====

void FUN_0052eb50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8acc;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 0xb) = 1;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_0052eb80 @ 0x0052eb80 ====

void FUN_0052eb80(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8acc;
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b7950;
  }
  puVar1[1] = in_ECX[2];
  FUN_00797a20(puVar1);
  if ((int *)in_ECX[10] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[10] + 4))();
    (**(code **)(*DAT_00b5a76c + 0x10))(1,in_ECX[10]);
  }
  if ((uint)in_ECX[9] < 0x10) {
    in_ECX[9] = 0xf;
    in_ECX[8] = 0;
    *(undefined1 *)(in_ECX + 4) = 0;
    *in_ECX = &PTR_FUN_009b78dc;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_0052ec00 @ 0x0052ec00 ====

void FUN_0052ec00(int *param_1)

{
  char cVar1;
  undefined2 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  void *pvVar5;
  int *in_ECX;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  in_ECX[10] = (int)param_1;
  piVar3 = DAT_00b5a770;
  puVar2 = (undefined2 *)(**(code **)(*param_1 + 0x1c))();
  piVar3 = (int *)(**(code **)(*piVar3 + 8))(*puVar2);
  if (piVar3 == (int *)0x0) {
    iVar8 = 7;
    pcVar7 = s_No_Name_009b8aac;
  }
  else {
    iVar8 = (**(code **)(*piVar3 + 4))();
    pcVar7 = (char *)(iVar8 + 2);
    pcVar6 = pcVar7;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    iVar8 = (int)pcVar6 - (iVar8 + 3);
  }
  FUN_00401740(pcVar7,iVar8);
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  FUN_00401740(s_No_Name_009b79ec,7);
  uVar4 = (**(code **)(*in_ECX + 8))();
  FUN_00401660(in_ECX + 3,0,0xffffffff);
  pvVar5 = operator_new(0x34);
  if (pvVar5 == (void *)0x0) {
    iVar8 = 0;
  }
  else {
    iVar8 = FUN_00522170();
  }
  *(undefined4 *)(iVar8 + 4) = 0;
  *(undefined1 *)(iVar8 + 8) = 1;
  *(undefined4 *)(iVar8 + 0xc) = uVar4;
  *(undefined4 *)(iVar8 + 0x10) = 0xffff00;
  *(undefined4 *)(iVar8 + 0x14) = 0x3b;
  FUN_00401660(auStack_20,0,0xffffffff);
  FUN_00797a20(iVar8);
  if (uStack_8 < 0x10) {
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_0052ed40 @ 0x0052ed40 ====

void FUN_0052ed40(byte param_1)

{
  void *in_ECX;
  
  FUN_0052eb80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0052ed60 @ 0x0052ed60 ====

undefined4 FUN_0052ed60(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00765c50(in_ECX + 0xc);
  return param_1;
}


// ==== FUN_0052ed80 @ 0x0052ed80 ====

undefined4 FUN_0052ed80(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0052ed90 @ 0x0052ed90 ====

undefined4 FUN_0052ed90(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_0052eda0 @ 0x0052eda0 ====

undefined4 FUN_0052eda0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_0052edb0 @ 0x0052edb0 ====

int FUN_0052edb0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 4) + 0x18;
}


// ==== FUN_0052edc0 @ 0x0052edc0 ====

int FUN_0052edc0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 4) + 0x20;
}


// ==== FUN_0052edd0 @ 0x0052edd0 ====

float10 FUN_0052edd0(void)

{
  int in_ECX;
  
  return (float10)*(float *)(*(int *)(in_ECX + 4) + 0x34);
}


// ==== FUN_0052ede0 @ 0x0052ede0 ====

void FUN_0052ede0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0052ede5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x38))();
  return;
}


// ==== FUN_0052ee00 @ 0x0052ee00 ====

void FUN_0052ee00(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8bbc;
  *(undefined1 *)(in_ECX + 4) = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  pvVar1 = operator_new(0x40);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0053fae0();
  }
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x30);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0052eb50();
  }
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x40);
  if (pvVar1 == (void *)0x0) {
    in_ECX[3] = 0;
    return;
  }
  uVar2 = FUN_005121e0();
  in_ECX[3] = uVar2;
  return;
}


// ==== FUN_0052ee80 @ 0x0052ee80 ====

void FUN_0052ee80(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8bbc;
  iVar1 = *DAT_00b5ac6c;
  uVar2 = (**(code **)(*(int *)in_ECX[2] + 8))();
  (**(code **)(iVar1 + 0x18))(uVar2);
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
  in_ECX[3] = 0;
  *in_ECX = &PTR_FUN_009b7814;
  return;
}


// ==== FUN_0052eee0 @ 0x0052eee0 ====

void FUN_0052eee0(int param_1)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x10) != '\x01') {
    if (*(uint *)(in_ECX + 0x18) != 0) {
      if (*(int *)(in_ECX + 0x14) == 0) {
        *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(param_1 + 0xc);
        return;
      }
      if ((uint)(*(int *)(param_1 + 0xc) - *(int *)(in_ECX + 0x14)) < *(uint *)(in_ECX + 0x18)) {
        return;
      }
    }
    piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x28))();
      pvVar2 = operator_new(0x400);
      *(undefined4 *)((int)pvVar2 + 8) = 0;
      *(undefined4 *)((int)pvVar2 + 0xc) = 0x5050005;
      *(undefined2 *)((int)pvVar2 + 6) = 0x14;
      iVar3 = FUN_004244d0();
      uVar4 = (**(code **)(**(int **)(in_ECX + 8) + 8))();
      *(undefined4 *)(iVar3 + 0x10) = uVar4;
      FUN_004d8570(iVar3);
      *(undefined4 *)(in_ECX + 0x18) = 0;
      *(undefined4 *)(in_ECX + 0x14) = 0;
      *(undefined1 *)(in_ECX + 0x10) = 1;
    }
  }
  return;
}


// ==== FUN_0052ef90 @ 0x0052ef90 ====

undefined4 FUN_0052ef90(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x14))();
  iVar3 = (**(code **)(*piVar2 + 8))();
  iVar4 = (**(code **)(*param_1 + 0x10))();
  if (iVar4 == iVar3) {
    iVar3 = param_1[1];
    iVar4 = (**(code **)(*in_ECX + 0x10))();
    *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(iVar3 + 0x14);
    *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar3 + 0x18);
    iVar4 = (**(code **)(*in_ECX + 0x10))();
    *(undefined4 *)(iVar4 + 0x20) = *(undefined4 *)(iVar3 + 0x1c);
    *(undefined4 *)(iVar4 + 0x24) = *(undefined4 *)(iVar3 + 0x20);
    uVar1 = *(undefined4 *)(iVar3 + 4);
    iVar4 = (**(code **)(*in_ECX + 0x10))();
    *(undefined4 *)(iVar4 + 0x30) = uVar1;
    uVar1 = *(undefined4 *)(iVar3 + 8);
    iVar3 = (**(code **)(*in_ECX + 0x10))();
    *(undefined4 *)(iVar3 + 0x2c) = uVar1;
    return 1;
  }
  return 0;
}


// ==== FUN_0052f030 @ 0x0052f030 ====

float10 FUN_0052f030(float *param_1)

{
  float *pfVar1;
  int *in_ECX;
  
  pfVar1 = (float *)(**(code **)(*in_ECX + 0x28))();
  return SQRT(((float10)param_1[1] - (float10)pfVar1[1]) *
              ((float10)param_1[1] - (float10)pfVar1[1]) +
              ((float10)*param_1 - (float10)*pfVar1) * ((float10)*param_1 - (float10)*pfVar1));
}


// ==== FUN_0052f0d0 @ 0x0052f0d0 ====

void FUN_0052f0d0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *in_ECX;
  undefined4 uVar6;
  undefined1 *puVar7;
  undefined1 auStack_1c [4];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined1 auStack_10 [4];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar2 = DAT_00b5a780;
  local_4 = 0;
  local_8 = 1;
  local_c = 0;
  iVar1 = (**(code **)(*in_ECX + 0x1c))();
  piVar2 = (int *)(**(code **)(*piVar2 + 8))(iVar1 + 0x14);
  if (piVar2 == (int *)0x0) {
    uVar6 = DAT_0099d080;
  }
  else {
    auStack_1c[0] = 0;
    uStack_18 = 1;
    uStack_14 = 0;
    iVar1 = (**(code **)(*piVar2 + 0xc))(auStack_1c);
    uVar6 = DAT_0099d080;
    if (iVar1 != 0) {
      uVar6 = *(undefined4 *)(iVar1 + 0x114);
    }
  }
  iVar1 = (**(code **)(*in_ECX + 0x10))();
  uVar5 = *(undefined4 *)(iVar1 + 0x30);
  uVar3 = (**(code **)(*in_ECX + 0x2c))(uVar5);
  uVar4 = (**(code **)(*in_ECX + 0x28))(uVar3);
  (**(code **)(*in_ECX + 0x1c))(uVar4);
  FUN_00511d20();
  FUN_005118f0(uVar4,uVar3,uVar5);
  uVar4 = 0;
  uVar3 = 0;
  uVar5 = (**(code **)(*in_ECX + 0x2c))(uVar6,0,0);
  puVar7 = auStack_10;
  (**(code **)(*in_ECX + 0x1c))(puVar7,uVar5);
  FUN_00511d20();
  FUN_00511c00(puVar7,uVar5,uVar6,uVar3,uVar4);
  return;
}


// ==== FUN_0052f1b0 @ 0x0052f1b0 ====

undefined4 FUN_0052f1b0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  iVar2 = (**(code **)(*piVar1 + 8))();
  iVar3 = (**(code **)(*param_1 + 0x10))();
  if (iVar3 != iVar2) {
    return 0;
  }
  if (param_1[3] == 0) {
    FUN_0052f0d0();
  }
  return 1;
}


// ==== FUN_0052f1f0 @ 0x0052f1f0 ====

int FUN_0052f1f0(void)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  int iVar5;
  int *in_ECX;
  char *pcVar6;
  int unaff_retaddr;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x14))();
  uVar3 = (**(code **)(*piVar2 + 0x24))();
  piVar2 = (int *)FUN_00803725(uVar3,0,&Framework::ICreature::RTTI_Type_Descriptor,
                               &Framework::Creature::INPC::RTTI_Type_Descriptor,0);
  puVar4 = (undefined2 *)(**(code **)(*piVar2 + 0x1c))();
  piVar2 = (int *)(**(code **)(*DAT_00b5a770 + 8))(*puVar4);
  if (piVar2 == (int *)0x0) {
    *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
    *(undefined4 *)(unaff_retaddr + 0x14) = 0;
    *(undefined1 *)(unaff_retaddr + 4) = 0;
    FUN_00401740(s___Actors_NPC_cpp_362___Invalie_N_009b8b58,0x28);
    return unaff_retaddr;
  }
  iVar5 = (**(code **)(*piVar2 + 4))();
  *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
  *(undefined4 *)(unaff_retaddr + 0x14) = 0;
  *(undefined1 *)(unaff_retaddr + 4) = 0;
  pcVar6 = (char *)(iVar5 + 2);
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar5 + 2),(int)pcVar6 - (iVar5 + 3));
  return unaff_retaddr;
}


// ==== FUN_0052f2a0 @ 0x0052f2a0 ====

undefined4 FUN_0052f2a0(int param_1)

{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int *in_ECX;
  undefined1 auStack_38 [4];
  void *pvStack_34;
  undefined4 uStack_24;
  uint uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x14))();
  iVar3 = (**(code **)(*piVar2 + 8))();
  if (*(int *)(param_1 + 0x10) != iVar3) {
    return 0;
  }
  piVar2 = (int *)(**(code **)(*in_ECX + 0x14))();
  uVar1 = *(undefined1 *)(param_1 + 0x14);
  uVar4 = (**(code **)(*piVar2 + 8))();
  FUN_004dd240(0x12,uVar1,0,0,uVar4);
  FUN_0052f1f0(auStack_1c);
  FUN_00401740(s_Receive_NPC_Icon__u__s__009b8b40,0x17);
  uVar4 = FUN_00404230(auStack_38);
  FUN_00796d20(uVar4);
  if (0xf < uStack_20) {
    _free(pvStack_34);
    return extraout_EAX;
  }
  uStack_20 = 0xf;
  uStack_24 = 0;
  pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
  if (uStack_4 < 0x10) {
    return 1;
  }
  _free(pvStack_18);
  return extraout_EAX_00;
}


// ==== FUN_0052f380 @ 0x0052f380 ====

uint FUN_0052f380(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00424500();
  if (uVar1 == 0x5050006) {
    uVar1 = FUN_0052f2a0(*(undefined4 *)(param_1 + 0xc));
    if ((char)uVar1 == '\x01') {
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0052f3c0 @ 0x0052f3c0 ====

undefined1 FUN_0052f3c0(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  int in_ECX;
  
  uVar3 = (**(code **)(*param_1 + 4))();
  if (uVar3 < 0x20010022) {
    if (uVar3 == 0x20010021) {
      cVar1 = FUN_0052ef90(param_1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
    else {
      if (uVar3 == 0x40001) {
        FUN_0052eee0(param_1);
        return 0;
      }
      if (uVar3 == 0x50011) {
        cVar1 = FUN_0052f380(param_1);
        if (cVar1 == '\x01') {
          return 1;
        }
      }
    }
  }
  else {
    if (uVar3 == 0x20010022) {
      uVar2 = FUN_0052f1b0(param_1);
      return uVar2;
    }
    if (uVar3 == 0x30060120) {
      *(undefined4 *)(in_ECX + 0x18) = 2000;
      *(undefined1 *)(in_ECX + 0x10) = 0;
    }
  }
  return 0;
}


// ==== FUN_0052f450 @ 0x0052f450 ====

/* WARNING: Removing unreachable block (ram,0x0052f5c9) */

void FUN_0052f450(void)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  int iVar5;
  int *in_ECX;
  char *pcVar6;
  undefined1 *puVar7;
  undefined1 auStack_72 [10];
  void *pvStack_68;
  undefined1 auStack_64 [4];
  undefined1 uStack_60;
  uint uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 uStack_40;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_24;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x14))();
  uVar3 = (**(code **)(*piVar2 + 0x24))();
  piVar2 = (int *)FUN_00803725(uVar3,0,&Framework::ICreature::RTTI_Type_Descriptor,
                               &Framework::Creature::INPC::RTTI_Type_Descriptor,0);
  puVar4 = (undefined2 *)(**(code **)(*piVar2 + 0x1c))();
  piVar2 = (int *)(**(code **)(*DAT_00b5a770 + 8))(*puVar4);
  iVar5 = (**(code **)(*piVar2 + 4))();
  uStack_4c = 0xf;
  uStack_50 = 0;
  uStack_60 = 0;
  pcVar6 = (char *)(iVar5 + 0x1b);
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar5 + 0x1b),(int)pcVar6 - (iVar5 + 0x1c));
  iVar5 = (**(code **)(*DAT_00b5a6dc + 0x1c))(0,auStack_64);
  if (iVar5 != 0) {
    (**(code **)(*(int *)in_ECX[3] + 0xc))();
    uStack_2c = 0xf;
    uStack_30 = 0;
    uStack_40 = 0;
    uStack_10 = 0xf;
    uStack_14 = 0;
    uStack_24 = 0;
    uStack_50 = 0;
    uStack_48 = DAT_0099d080;
    uStack_4c = 0xffffffff;
    FUN_00401660(iVar5,0,0xffffffff);
    FUN_00401660(iVar5 + 0x1c,0,0xffffffff);
    FUN_004ff800(&uStack_50);
    if (*(short *)(iVar5 + 0x38) != 0) {
      uVar3 = (**(code **)(*(int *)in_ECX[2] + 8))();
      FUN_004dd240(0x19,4,1,*(undefined2 *)(iVar5 + 0x38),uVar3);
    }
    puVar7 = auStack_72 + -10;
    FUN_00511d10(puVar7);
    FUN_00512cd0();
    FUN_00512a20(puVar7);
    (**(code **)(*(int *)in_ECX[3] + 0x10))();
    FUN_0052f0d0();
    FUN_004107d0();
  }
  if (uStack_54 < 0x10) {
    return;
  }
  _free(pvStack_68);
  return;
}


// ==== FUN_0052f620 @ 0x0052f620 ====

void FUN_0052f620(byte param_1)

{
  void *in_ECX;
  
  FUN_0052ee80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0052f640 @ 0x0052f640 ====

void FUN_0052f640(void)

{
  return;
}


// ==== FUN_0052f650 @ 0x0052f650 ====

void FUN_0052f650(void)

{
  return;
}


// ==== FUN_0052f660 @ 0x0052f660 ====

void FUN_0052f660(void)

{
  return;
}


// ==== FUN_0052f670 @ 0x0052f670 ====

void FUN_0052f670(void)

{
  return;
}


// ==== FUN_0052f680 @ 0x0052f680 ====

void FUN_0052f680(void)

{
  return;
}


// ==== FUN_0052f6a0 @ 0x0052f6a0 ====

void FUN_0052f6a0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined1 auStack_a [2];
  undefined4 auStack_8 [2];
  
  if (*(char *)(in_ECX + 8) == '\0') {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
    uVar2 = (**(code **)(*piVar1 + 8))();
    piVar1 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
    if ((piVar1 != (int *)0x0) &&
       (auStack_8[0] = uVar2, iVar3 = (**(code **)(*piVar1 + 0x30))(auStack_8), iVar3 == 0)) {
      (**(code **)(*piVar1 + 0x54))(auStack_a + -6,*(undefined4 *)(in_ECX + 0xc));
      *(undefined1 *)(in_ECX + 8) = 1;
    }
  }
  return;
}


// ==== FUN_0052f710 @ 0x0052f710 ====

void FUN_0052f710(void)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  undefined4 auStack_8 [2];
  
  if ((*(char *)(in_ECX + 8) != '\0') &&
     (piVar1 = (int *)(**(code **)(*DAT_00b5a6fc + 4))(), piVar1 != (int *)0x0)) {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
    auStack_8[0] = (**(code **)(*piVar2 + 8))();
    piVar2 = (int *)(**(code **)(*piVar1 + 0x30))(auStack_8);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*DAT_00b5a6f8 + 0x10))(1,*(undefined4 *)(*piVar2 + 4));
      (**(code **)(*piVar1 + 0x40))(piVar2);
      *(undefined1 *)(in_ECX + 8) = 0;
    }
  }
  return;
}


// ==== FUN_0052f780 @ 0x0052f780 ====

void FUN_0052f780(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x1c))();
  if (iVar2 == 0) {
    return;
  }
  cVar1 = FUN_00511d60();
  if (cVar1 == '\0') {
    FUN_0052f710();
    return;
  }
  FUN_0052f6a0();
  return;
}


// ==== FUN_0052f7b0 @ 0x0052f7b0 ====

void FUN_0052f7b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8c20;
  FUN_0052f710();
  *in_ECX = &PTR_FUN_009b7ed4;
  return;
}


// ==== FUN_0052f7d0 @ 0x0052f7d0 ====

void FUN_0052f7d0(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *in_ECX;
  float10 fVar5;
  undefined4 uVar6;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  *in_ECX = &PTR_FUN_009b8c20;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[1] = param_1;
  piVar2 = (int *)(**(code **)(*param_1 + 0x14))();
  (**(code **)(*piVar2 + 8))();
  puVar3 = (undefined4 *)(**(code **)(*param_1 + 0x28))();
  uStack_10 = *puVar3;
  uStack_c = puVar3[1];
  uVar6 = 1;
  uStack_8 = uStack_10;
  uStack_4 = uStack_c;
  piVar2 = (int *)(**(code **)(*DAT_00b5a6f8 + 0xc))(1,0);
  in_ECX[3] = piVar2;
  piVar2 = (int *)(**(code **)(*piVar2 + 0xc))();
  (**(code **)(*piVar2 + 0x40))(&uStack_10);
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[3] + 0xc))();
  (**(code **)(*piVar2 + 0x4c))(0);
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[3] + 0xc))();
  (**(code **)(*piVar2 + 0x28))(3);
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[3] + 0xc))();
  iVar4 = *piVar2;
  fVar5 = (float10)(**(code **)(*param_1 + 0x34))();
  (**(code **)(iVar4 + 0x94))((float)fVar5);
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[3] + 0xc))();
  iVar4 = *piVar2;
  fVar5 = (float10)(**(code **)(*param_1 + 0x30))();
  (**(code **)(iVar4 + 0x90))((float)fVar5);
  (**(code **)(*(int *)in_ECX[3] + 0x24))(0);
  FUN_0052f6a0();
  piVar2 = (int *)(**(code **)(*param_1 + 0x14))();
  iVar4 = (**(code **)(*piVar2 + 0x24))();
  if ((iVar4 != 0) && (*(int **)(iVar4 + 0x4c) != (int *)0x0)) {
    piVar2 = (int *)(**(code **)(**(int **)(iVar4 + 0x4c) + 0x18))();
    if (piVar2 != (int *)0x0) {
      iVar4 = (**(code **)(*piVar2 + 0xc))();
      if (iVar4 == 8) {
        (**(code **)(*piVar2 + 8))(0);
        puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x10))();
        uVar1 = *puVar3;
        puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1,0);
        *puVar3 = 7;
        puVar3[1] = uVar1;
        puVar3[2] = uVar6;
        (**(code **)(*DAT_00b5a804 + 0xc))(uVar6,puVar3);
        (**(code **)(*DAT_00b5a70c + 0x10))(1,puVar3);
      }
    }
  }
  return;
}


// ==== FUN_0052f950 @ 0x0052f950 ====

void FUN_0052f950(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8c20;
  FUN_0052f710();
  *in_ECX = &PTR_FUN_009b7ed4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0052f980 @ 0x0052f980 ====

undefined4 FUN_0052f980(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_0052f990 @ 0x0052f990 ====

undefined4 FUN_0052f990(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0052f9a0 @ 0x0052f9a0 ====

undefined4 FUN_0052f9a0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_0052f9b0 @ 0x0052f9b0 ====

int FUN_0052f9b0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 8) + 0x18;
}


// ==== FUN_0052f9c0 @ 0x0052f9c0 ====

int FUN_0052f9c0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 8) + 0x20;
}


// ==== FUN_0052f9d0 @ 0x0052f9d0 ====

float10 FUN_0052f9d0(void)

{
  int in_ECX;
  
  return (float10)*(float *)(*(int *)(in_ECX + 8) + 0x34);
}


// ==== FUN_0052f9e0 @ 0x0052f9e0 ====

void FUN_0052f9e0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0052f9e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x38))();
  return;
}


// ==== FUN_0052f9f0 @ 0x0052f9f0 ====

void FUN_0052f9f0(void)

{
  FUN_0053fbc0();
  return;
}


// ==== FUN_0052fa00 @ 0x0052fa00 ====

undefined4 FUN_0052fa00(void)

{
  int in_ECX;
  
  return CONCAT31((int3)((uint)*(int *)(in_ECX + 4) >> 8),
                  *(undefined1 *)(*(int *)(in_ECX + 4) + 0x18));
}


// ==== FUN_0052fa10 @ 0x0052fa10 ====

void FUN_0052fa10(void)

{
  FUN_0053fe30();
  return;
}


// ==== FUN_0052fa40 @ 0x0052fa40 ====

uint FUN_0052fa40(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 8))();
  uVar2 = (**(code **)(*param_1 + 0x10))();
  if (uVar1 == uVar2) {
    uVar1 = FUN_00541590((float)param_1[2]);
    return uVar1;
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_0052fa80 @ 0x0052fa80 ====

float10 FUN_0052fa80(float *param_1)

{
  int iVar1;
  float *pfVar2;
  int *in_ECX;
  float10 fVar3;
  float10 fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  pfVar2 = (float *)(**(code **)(*in_ECX + 0x28))();
  iVar1 = in_ECX[2];
  fVar6 = (float)(int)*pfVar2 - *(float *)(iVar1 + 0x38);
  fVar8 = (float)(int)pfVar2[1] - *(float *)(iVar1 + 0x34);
  fVar5 = (float)(int)*pfVar2 + *(float *)(iVar1 + 0x38) + DAT_0099d080;
  fVar7 = *(float *)(iVar1 + 0x34) + (float)(int)pfVar2[1] + DAT_0099d080;
  if (fVar6 < *param_1 || fVar6 == *param_1) {
    if (*param_1 <= fVar5) {
      fVar3 = (float10)0.0;
    }
    else {
      fVar3 = ABS((float10)*param_1 - (float10)fVar5);
    }
  }
  else {
    fVar3 = ABS((float10)*param_1 - (float10)fVar6);
  }
  if (fVar8 < param_1[1] || fVar8 == param_1[1]) {
    if (param_1[1] <= fVar7) {
      fVar4 = (float10)0.0;
    }
    else {
      fVar4 = ABS((float10)param_1[1] - (float10)fVar7);
    }
  }
  else {
    fVar4 = ABS((float10)param_1[1] - (float10)fVar8);
  }
  return SQRT(fVar3 * fVar3 + fVar4 * fVar4);
}


// ==== FUN_0052fb70 @ 0x0052fb70 ====

void FUN_0052fb70(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = param_1;
  return;
}


// ==== FUN_0052fb90 @ 0x0052fb90 ====

void FUN_0052fb90(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8cdc;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  pvVar1 = operator_new(100);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0053fc40();
  }
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x3c);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00541150();
  }
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x40);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005121e0();
  }
  in_ECX[4] = uVar2;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    in_ECX[5] = 0;
    in_ECX[3] = 0;
    return;
  }
  uVar2 = FUN_0053fd90();
  in_ECX[5] = 0;
  in_ECX[3] = uVar2;
  return;
}


// ==== FUN_0052fc30 @ 0x0052fc30 ====

void FUN_0052fc30(void)

{
  char cVar1;
  int *piVar2;
  int *in_ECX;
  undefined4 uStack_4;
  
  if (*(char *)(in_ECX[1] + 8) != '\x01') {
    FUN_00541ac0();
    FUN_0053fb70();
    cVar1 = (**(code **)(*in_ECX + 0x38))();
    if (cVar1 == '\x01') {
      piVar2 = (int *)FUN_00513b60();
      uStack_4 = 1;
      (**(code **)(*piVar2 + 0x3c))(&uStack_4);
      (**(code **)(*DAT_00b5ad5c + 4))(piVar2);
    }
  }
  return;
}


// ==== FUN_0052fc90 @ 0x0052fc90 ====

void FUN_0052fc90(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if ((char)(*(int **)(in_ECX + 4))[2] == '\0') {
    return;
  }
  iVar1 = *DAT_00b5ad5c;
  uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 8))();
  (**(code **)(iVar1 + 8))(uVar2);
  FUN_00541620();
  FUN_0053fb80();
  return;
}


// ==== FUN_0052fcd0 @ 0x0052fcd0 ====

void FUN_0052fcd0(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  FUN_00540f00();
  return;
}


// ==== FUN_0052fcf0 @ 0x0052fcf0 ====

void FUN_0052fcf0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) != 0) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x28))(*(int *)(in_ECX + 0x10));
  }
  return;
}


// ==== FUN_0052fd10 @ 0x0052fd10 ====

void FUN_0052fd10(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  FUN_0053fbb0(param_1);
  if ((char)param_1 == '\0') {
    iVar1 = *DAT_00b5ad5c;
    uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 8))();
    (**(code **)(iVar1 + 8))(uVar2);
  }
  return;
}


// ==== FUN_0052fd50 @ 0x0052fd50 ====

uint FUN_0052fd50(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 8))();
  uVar4 = (**(code **)(*param_1 + 0x10))();
  if (uVar3 == uVar4) {
    iVar1 = param_1[1];
    iVar2 = *(int *)(in_ECX + 8);
    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar1 + 0x14);
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar1 + 0x18);
    iVar2 = *(int *)(in_ECX + 8);
    *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar1 + 0x1c);
    *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar1 + 0x20);
    *(undefined4 *)(*(int *)(in_ECX + 8) + 0x30) = *(undefined4 *)(iVar1 + 4);
    *(undefined4 *)(*(int *)(in_ECX + 8) + 0x2c) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(*(int *)(in_ECX + 8) + 0x34) = *(undefined4 *)(iVar1 + 0xc);
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  return uVar4 & 0xffffff00;
}


// ==== FUN_0052fdc0 @ 0x0052fdc0 ====

void FUN_0052fdc0(int param_1,char param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined4 uStack_4;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 8))();
    *puVar1 = &PTR_FUN_009b8cc4;
    puVar1[1] = uVar2;
  }
  uVar2 = 0;
  uStack_4 = 0;
  iVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x1c))();
  if (iVar3 == 3) {
    uStack_4 = *(undefined4 *)(*(int *)(in_ECX + 8) + 0x38);
    uVar2 = 2;
  }
  if (param_1 == 0) {
    iVar3 = 1;
  }
  else {
    iVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x1c))();
    if (iVar3 != 3) {
      uVar2 = 1;
    }
    if (param_2 == '\x01') {
      iVar3 = 4;
    }
    else {
      iVar3 = (-(uint)(param_2 != '\0') & 3) + 3;
    }
  }
  puVar1[2] = iVar3;
  puVar1[3] = uVar2;
  puVar1[4] = param_1;
  puVar1[5] = uStack_4;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0052fe80 @ 0x0052fe80 ====

undefined4 FUN_0052fe80(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  float fVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined1 auStack_14 [8];
  float afStack_c [2];
  undefined4 uStack_4;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 8))();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (iVar1 == iVar2) {
    FUN_004f5730(afStack_c);
    FUN_0040d600(auStack_14,uStack_4);
    fVar3 = afStack_c[0] * DAT_009b0120;
    uVar5 = 0x3e4ccccd;
    puVar4 = auStack_14;
    FUN_00511d20(puVar4,fVar3,0x3e4ccccd);
    FUN_00511950(puVar4,fVar3,uVar5);
    FUN_0052fdc0(param_1[3],(char)param_1[4]);
    return 1;
  }
  return 0;
}


// ==== FUN_0052ff30 @ 0x0052ff30 ====

undefined4 FUN_0052ff30(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 8))();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (iVar1 == iVar2) {
    FUN_0052fdc0(0,0);
    return 1;
  }
  return 0;
}


// ==== FUN_0052ff70 @ 0x0052ff70 ====

void FUN_0052ff70(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  int iStack_8;
  uint uStack_4;
  
  uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x24))
                    (0,&Framework::ICreature::RTTI_Type_Descriptor,
                     &Framework::Creature::IBrick::RTTI_Type_Descriptor,0);
  iStack_8 = FUN_00803725(uVar2);
  if (iStack_8 != 0) {
    FUN_006eb430(iStack_8);
    return;
  }
  uStack_4 = 0xf;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_pBrick_L____NULL_009b8c54,0x10);
  FUN_00406880(auStack_1c);
  if (uStack_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_18);
  return;
}


// ==== FUN_0052fff0 @ 0x0052fff0 ====

void FUN_0052fff0(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  int iStack_8;
  uint uStack_4;
  
  uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x24))
                    (0,&Framework::ICreature::RTTI_Type_Descriptor,
                     &Framework::Creature::IBrick::RTTI_Type_Descriptor,0);
  iStack_8 = FUN_00803725(uVar2);
  if (iStack_8 != 0) {
    FUN_006eb460(iStack_8);
    return;
  }
  uStack_4 = 0xf;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_pBrick_L____NULL_009b8c68,0x10);
  FUN_00406880(auStack_1c);
  if (uStack_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_18);
  return;
}


