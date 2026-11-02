// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x4c0000-0x4cffff

// ==== FUN_004c02f0 @ 0x004c02f0 ====

/* WARNING: Removing unreachable block (ram,0x004c0672) */

undefined4 FUN_004c02f0(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  int in_ECX;
  uint uVar7;
  char *pcVar8;
  undefined1 auStack_c0 [4];
  void *pvStack_bc;
  int iStack_b8;
  undefined4 uStack_b4;
  uint uStack_b0;
  int local_ac;
  undefined4 uStack_a8;
  undefined1 auStack_a4 [28];
  undefined1 auStack_88 [4];
  int iStack_84;
  undefined4 uStack_80;
  undefined1 auStack_7c [4];
  undefined1 auStack_78 [4];
  void *pvStack_74;
  undefined4 uStack_64;
  uint uStack_60;
  undefined1 auStack_5c [8];
  undefined1 auStack_54 [28];
  undefined2 auStack_38 [22];
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_00980648;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_ac = in_ECX;
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 9) {
    FUN_004c33b0();
    iStack_4 = 0;
    uStack_b0 = 0;
    iVar2 = FUN_00411430();
    if (iVar2 != 0) {
      do {
        iVar2 = FUN_00411510(uStack_b0);
        pvStack_bc = (void *)0x0;
        iStack_b8 = 0;
        uStack_b4 = 0;
        iStack_4._0_1_ = 1;
        if (*(int *)(iVar2 + 0x14) == 0) {
          iStack_4 = (uint)iStack_4._1_3_ << 8;
          pvStack_bc = (void *)0x0;
          iStack_b8 = 0;
          uStack_b4 = 0;
        }
        else {
          iVar3 = FUN_00405b90(auStack_78,0,1);
          iStack_4._0_1_ = 2;
          iVar3 = FUN_00403620(0,*(undefined4 *)(iVar3 + 0x14),&DAT_009b0484,1);
          iStack_4._0_1_ = 1;
          if (0xf < uStack_60) {
            _free(pvStack_74);
            return extraout_EAX;
          }
          uStack_60 = 0xf;
          uStack_64 = 0;
          pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
          if (iVar3 == 0) {
            iStack_4 = (uint)iStack_4._1_3_ << 8;
            if (pvStack_bc != (void *)0x0) {
              FUN_00405de0(pvStack_bc,iStack_b8,auStack_c0,local_ac);
              _free(pvStack_bc);
              return extraout_EAX_00;
            }
            pvStack_bc = (void *)0x0;
            iStack_b8 = 0;
            uStack_b4 = 0;
          }
          else {
            FUN_00405670(iVar2,auStack_c0);
            if ((pvStack_bc != (void *)0x0) &&
               (iVar2 = iStack_b8 - (int)pvStack_bc >> 0x1f,
               (iStack_b8 - (int)pvStack_bc) / 0x1c + iVar2 != iVar2)) {
              iVar2 = FUN_00403620(0,*(undefined4 *)((int)pvStack_bc + 0x14),s_<cate>_009b0488,6);
              if (iVar2 == 0) {
                uVar6 = FUN_00405d30(1);
                uStack_a8 = thunk_FUN_00796f80(uVar6);
                uVar6 = FUN_00405d30(2);
                FUN_00401660(uVar6,0,0xffffffff);
                FUN_004c30c0(*(undefined4 *)(iStack_84 + 4));
                *(int *)(iStack_84 + 4) = iStack_84;
                uStack_80 = 0;
                *(int *)iStack_84 = iStack_84;
                *(int *)(iStack_84 + 8) = iStack_84;
              }
              else {
                pcVar8 = s_<_cate>_009b0490;
                uVar6 = FUN_00405d30(0);
                cVar1 = FUN_004036a0(uVar6,pcVar8);
                if (cVar1 != '\0') {
                  iVar2 = *(int *)(in_ECX + 0x40);
                  piVar4 = (int *)FUN_004be4e0(auStack_7c,&uStack_a8);
                  if (*piVar4 != iVar2) {
                    FUN_00401830(s_mapEffects_find__wCode______mapE_009b0498);
                    iStack_4._0_1_ = 3;
                    FUN_00406880(auStack_54);
                    iStack_4 = CONCAT31(iStack_4._1_3_,1);
                    /* WARNING: Subroutine does not return */
                    FUN_00446f10();
                  }
                  auStack_38[0] = (undefined2)uStack_a8;
                  FUN_004c34b0(auStack_a4);
                  iStack_4._0_1_ = 4;
                  FUN_004c37b0(auStack_5c,auStack_38);
                  iStack_4._0_1_ = 1;
                  FUN_004c3420();
                  iStack_4 = (uint)iStack_4._1_3_ << 8;
                  FUN_00406250();
                  in_ECX = local_ac;
                  goto LAB_004c0609;
                }
                pcVar8 = s_<effect>_009b04c8;
                uVar6 = FUN_00405d30(0);
                cVar1 = FUN_004036a0(uVar6,pcVar8);
                if (cVar1 != '\0') {
                  FUN_004bfe80(param_1,&uStack_b0,auStack_88);
                }
              }
            }
            iStack_4 = (uint)iStack_4._1_3_ << 8;
            FUN_00406250();
          }
        }
LAB_004c0609:
        uVar7 = uStack_b0 + 1;
        uStack_b0 = uVar7;
        uVar5 = FUN_00411430();
      } while (uVar7 < uVar5);
    }
    uVar6 = (**(code **)(*param_1 + 0x10))();
    *(undefined4 *)(in_ECX + 0x28) = uVar6;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    *(undefined4 *)(in_ECX + 0x34) = 2;
    (**(code **)*param_1)(1);
    puStack_8 = (undefined1 *)0xffffffff;
    FUN_004c3420();
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
  }
  ExceptionList = pvStack_c;
  return uVar6;
}


// ==== FUN_004c0680 @ 0x004c0680 ====

void FUN_004c0680(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  void *_Memory;
  void *_Memory_00;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *piVar10;
  undefined4 *in_ECX;
  int *local_14 [2];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980665;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009b06c0;
  local_14[0] = (int *)in_ECX[0x10];
  piVar2 = (int *)*local_14[0];
  local_4 = 1;
  do {
    if (piVar2 == local_14[0]) {
      local_4 = 0;
      FUN_004c3b70(local_14,*(undefined4 *)in_ECX[0x10],(undefined4 *)in_ECX[0x10]);
      _free((void *)in_ECX[0x10]);
      return;
    }
    puVar3 = (undefined4 *)piVar2[0xc];
    puVar4 = (undefined4 *)*puVar3;
    while (puVar4 != puVar3) {
      puVar5 = (undefined4 *)puVar4[0x11];
      puVar6 = (undefined4 *)*puVar5;
      while (puVar6 != puVar5) {
        if ((undefined4 *)puVar6[0xc] != (undefined4 *)puVar6[0xd]) {
          _Memory = *(void **)puVar6[0xc];
          _Memory_00 = *(void **)((int)_Memory + 0x34);
          if (_Memory_00 == (void *)0x0) {
            *(undefined4 *)((int)_Memory + 0x34) = 0;
            FUN_004c1fb0();
            _free(_Memory);
            return;
          }
          if (0xf < *(uint *)((int)_Memory_00 + 0x38)) {
            _free(*(void **)((int)_Memory_00 + 0x24));
            return;
          }
          *(undefined4 *)((int)_Memory_00 + 0x38) = 0xf;
          *(undefined4 *)((int)_Memory_00 + 0x34) = 0;
          *(undefined1 *)((int)_Memory_00 + 0x24) = 0;
          if (*(uint *)((int)_Memory_00 + 0x1c) < 0x10) {
            *(undefined4 *)((int)_Memory_00 + 0x1c) = 0xf;
            *(undefined4 *)((int)_Memory_00 + 0x18) = 0;
            *(undefined1 *)((int)_Memory_00 + 8) = 0;
            _free(_Memory_00);
            return;
          }
          _free(*(void **)((int)_Memory_00 + 8));
          return;
        }
        if ((void *)puVar6[0xc] != (void *)0x0) {
          _free((void *)puVar6[0xc]);
          return;
        }
        puVar6[0xc] = 0;
        puVar6[0xd] = 0;
        puVar6[0xe] = 0;
        if (*(char *)((int)puVar6 + 0x3d) == '\0') {
          puVar7 = (undefined4 *)puVar6[2];
          if (*(char *)((int)puVar7 + 0x3d) == '\0') {
            cVar1 = *(char *)((int)*puVar7 + 0x3d);
            puVar6 = puVar7;
            puVar7 = (undefined4 *)*puVar7;
            while (cVar1 == '\0') {
              cVar1 = *(char *)((int)*puVar7 + 0x3d);
              puVar6 = puVar7;
              puVar7 = (undefined4 *)*puVar7;
            }
          }
          else {
            cVar1 = *(char *)((int)puVar6[1] + 0x3d);
            puVar9 = (undefined4 *)puVar6[1];
            puVar7 = puVar6;
            while ((puVar6 = puVar9, cVar1 == '\0' && (puVar7 == (undefined4 *)puVar6[2]))) {
              cVar1 = *(char *)((int)puVar6[1] + 0x3d);
              puVar9 = (undefined4 *)puVar6[1];
              puVar7 = puVar6;
            }
          }
        }
      }
      if (*(char *)((int)puVar4 + 0x4d) == '\0') {
        puVar5 = (undefined4 *)puVar4[2];
        if (*(char *)((int)puVar5 + 0x4d) == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x4d);
          puVar4 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar5 + 0x4d);
            puVar4 = puVar5;
            puVar5 = (undefined4 *)*puVar5;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar4[1] + 0x4d);
          puVar6 = (undefined4 *)puVar4[1];
          puVar5 = puVar4;
          while ((puVar4 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar4[2]))) {
            cVar1 = *(char *)((int)puVar4[1] + 0x4d);
            puVar6 = (undefined4 *)puVar4[1];
            puVar5 = puVar4;
          }
        }
      }
    }
    if (*(char *)((int)piVar2 + 0x39) == '\0') {
      piVar8 = (int *)piVar2[2];
      if (*(char *)((int)piVar8 + 0x39) == '\0') {
        cVar1 = *(char *)(*piVar8 + 0x39);
        piVar2 = piVar8;
        piVar8 = (int *)*piVar8;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar8 + 0x39);
          piVar2 = piVar8;
          piVar8 = (int *)*piVar8;
        }
      }
      else {
        cVar1 = *(char *)(piVar2[1] + 0x39);
        piVar10 = (int *)piVar2[1];
        piVar8 = piVar2;
        while ((piVar2 = piVar10, cVar1 == '\0' && (piVar8 == (int *)piVar2[2]))) {
          cVar1 = *(char *)(piVar2[1] + 0x39);
          piVar10 = (int *)piVar2[1];
          piVar8 = piVar2;
        }
      }
    }
  } while( true );
}


// ==== FUN_004c0900 @ 0x004c0900 ====

void FUN_004c0900(undefined4 param_1)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980682;
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
  *in_ECX = &PTR_FUN_009b06c0;
  iVar1 = FUN_004be420();
  in_ECX[0x10] = iVar1;
  *(undefined1 *)(iVar1 + 0x39) = 1;
  *(undefined4 *)(in_ECX[0x10] + 4) = in_ECX[0x10];
  *(undefined4 *)in_ECX[0x10] = in_ECX[0x10];
  *(undefined4 *)(in_ECX[0x10] + 8) = in_ECX[0x10];
  in_ECX[0x11] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004c09b0 @ 0x004c09b0 ====

void FUN_004c09b0(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x30) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x30));
    return;
  }
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  if (*(uint *)(in_ECX + 0x28) < 0x10) {
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined4 *)(in_ECX + 0x28) = 0xf;
    *(undefined1 *)(in_ECX + 0x14) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x14));
  return;
}


// ==== FUN_004c0a00 @ 0x004c0a00 ====

void FUN_004c0a00(void)

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
  puStack_8 = &LAB_009808c8;
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


// ==== FUN_004c0a70 @ 0x004c0a70 ====

/* WARNING: Removing unreachable block (ram,0x004c0b83) */
/* WARNING: Removing unreachable block (ram,0x004c0b93) */
/* WARNING: Removing unreachable block (ram,0x004c0b9c) */
/* WARNING: Removing unreachable block (ram,0x004c0b9f) */
/* WARNING: Removing unreachable block (ram,0x004c0b8f) */
/* WARNING: Removing unreachable block (ram,0x004c0bad) */
/* WARNING: Removing unreachable block (ram,0x004c0bba) */
/* WARNING: Removing unreachable block (ram,0x004c0bc5) */
/* WARNING: Removing unreachable block (ram,0x004c0bc1) */
/* WARNING: Removing unreachable block (ram,0x004c0bb5) */
/* WARNING: Removing unreachable block (ram,0x004c0bc8) */

void FUN_004c0a70(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_009808c8;
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
            goto LAB_004c0c95;
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
LAB_004c0c95:
            *(undefined1 *)(piVar5 + 8) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 8) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_004c0d20 @ 0x004c0d20 ====

void FUN_004c0d20(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_009808c8;
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
  piVar4 = (int *)FUN_004be2c0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_004c0e19:
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
      if ((char)piVar6[8] == '\0') goto LAB_004c0e19;
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


// ==== FUN_004c0f00 @ 0x004c0f00 ====

void FUN_004c0f00(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004be460(piVar6[1]);
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
    FUN_004c0a70(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004c0fc0 @ 0x004c0fc0 ====

void FUN_004c0fc0(void *param_1,uint param_2,undefined4 *param_3)

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
      uVar7 = FUN_004c0a00();
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


// ==== FUN_004c11a0 @ 0x004c11a0 ====

void FUN_004c11a0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00980690;
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
      uVar7 = FUN_004c0a00();
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


// ==== Catch@004c131d @ 0x004c131d ====

void Catch_004c131d(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_004c1400 @ 0x004c1400 ====

void FUN_004c1400(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_1 = *param_3;
      FUN_00401660(param_3 + 1,0,0xffffffff);
      param_1 = param_1 + 8;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_004c1440 @ 0x004c1440 ====

void FUN_004c1440(undefined4 *param_1,int *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x21) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x21) == '\0');
  }
  param_2 = puVar4;
  if (bVar1) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      local_4 = 1;
      goto LAB_004c149e;
    }
    FUN_004ddea0();
  }
  if ((*piVar2 <= param_2[3]) || (piVar2[1] < param_2[4])) {
    *param_1 = param_2;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_004c149e:
  puVar4 = (undefined4 *)FUN_004c0d20(&param_2,local_4,puVar4,piVar2);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_004c1500 @ 0x004c1500 ====

undefined4 * FUN_004c1500(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_009806b1;
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


// ==== Catch@004c156e @ 0x004c156e ====

void Catch_004c156e(void)

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


// ==== FUN_004c15d0 @ 0x004c15d0 ====

void FUN_004c15d0(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009806c0;
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
      uVar1 = FUN_004c0a00();
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


// ==== Catch@004c1676 @ 0x004c1676 ====

void Catch_004c1676(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004c1690 @ 0x004c1690 ====

void FUN_004c1690(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined1 local_1c [8];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(in_ECX + 0x10) = param_2;
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  FUN_004be460(*(undefined4 *)(*(int *)(in_ECX + 4) + 4));
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  puVar1 = *(undefined4 **)(param_3 + 4);
  puVar2 = *(undefined4 **)(param_3 + 8);
  *(undefined4 *)(in_ECX + 0x14) = puVar1[1];
  *(undefined4 *)(in_ECX + 0x18) = puVar1[2];
  *(undefined4 *)(in_ECX + 0x1c) = puVar1[3];
  while (puVar1 != puVar2) {
    local_14 = *puVar1;
    puVar3 = puVar1 + 4;
    if (puVar3 == puVar2) {
      local_10 = 10000000;
    }
    else {
      local_10 = *puVar3;
    }
    local_c = puVar1[1];
    local_8 = puVar1[2];
    local_4 = puVar1[3];
    FUN_004c1440(local_1c,&local_14);
    puVar1 = puVar3;
  }
  return;
}


// ==== FUN_004c1750 @ 0x004c1750 ====

void FUN_004c1750(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_009806e1;
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


// ==== Catch@004c17bf @ 0x004c17bf ====

void Catch_004c17bf(void)

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


// ==== FUN_004c1810 @ 0x004c1810 ====

void FUN_004c1810(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_004c0fc0(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_004c1860 @ 0x004c1860 ====

void FUN_004c1860(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 4) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 4))) {
    FUN_004c11a0(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_004be4a0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x10;
  return;
}


// ==== FUN_004c18d0 @ 0x004c18d0 ====

void FUN_004c18d0(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00980888;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  FUN_004c15d0(param_1 + 0x1c);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004c1940 @ 0x004c1940 ====

void FUN_004c1940(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x20) {
    FUN_00446ee0();
  }
  return;
}


// ==== FUN_004c1970 @ 0x004c1970 ====

/* WARNING: Removing unreachable block (ram,0x004c1a7e) */
/* WARNING: Removing unreachable block (ram,0x004c1a8f) */
/* WARNING: Removing unreachable block (ram,0x004c1a98) */
/* WARNING: Removing unreachable block (ram,0x004c1a9b) */
/* WARNING: Removing unreachable block (ram,0x004c1a8b) */
/* WARNING: Removing unreachable block (ram,0x004c1aa9) */
/* WARNING: Removing unreachable block (ram,0x004c1ab6) */
/* WARNING: Removing unreachable block (ram,0x004c1ac1) */
/* WARNING: Removing unreachable block (ram,0x004c1abd) */
/* WARNING: Removing unreachable block (ram,0x004c1ab1) */
/* WARNING: Removing unreachable block (ram,0x004c1ac4) */

void FUN_004c1970(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_009808c8;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x3d) != '\0') {
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
  FUN_007136c0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x3d) == '\0') {
    if (*(char *)(param_2[2] + 0x3d) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x3d) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x3d) == '\0') {
      piVar3 = (int *)FUN_00713640(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x3d) == '\0') {
      uVar4 = FUN_004bdeb0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0xf] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0xf] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0xf] == '\0') {
            *(undefined1 *)(piVar5 + 0xf) = 1;
            *(undefined1 *)(piVar3 + 0xf) = 0;
            FUN_004be0c0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x3d) == '\0') {
            if ((*(char *)(*piVar5 + 0x3c) == '\x01') && (*(char *)(piVar5[2] + 0x3c) == '\x01'))
            goto LAB_004c1b95;
            if (*(char *)(piVar5[2] + 0x3c) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x3c) = 1;
              *(undefined1 *)(piVar5 + 0xf) = 0;
              FUN_00713660(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0xf) = (char)piVar3[0xf];
            *(undefined1 *)(piVar3 + 0xf) = 1;
            *(undefined1 *)(piVar5[2] + 0x3c) = 1;
            FUN_004be0c0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0xf] == '\0') {
            *(undefined1 *)(piVar5 + 0xf) = 1;
            *(undefined1 *)(piVar3 + 0xf) = 0;
            FUN_00713660(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x3d) == '\0') {
            if ((*(char *)(piVar5[2] + 0x3c) != '\x01') || (*(char *)(*piVar5 + 0x3c) != '\x01')) {
              if (*(char *)(*piVar5 + 0x3c) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x3c) = 1;
                *(undefined1 *)(piVar5 + 0xf) = 0;
                FUN_004be0c0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0xf) = (char)piVar3[0xf];
              *(undefined1 *)(piVar3 + 0xf) = 1;
              *(undefined1 *)(*piVar5 + 0x3c) = 1;
              FUN_00713660(piVar3);
              break;
            }
LAB_004c1b95:
            *(undefined1 *)(piVar5 + 0xf) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xf) = 1;
  }
  if ((void *)param_2[0xc] != (void *)0x0) {
    _free((void *)param_2[0xc]);
    return;
  }
  param_2[0xc] = 0;
  param_2[0xd] = 0;
  param_2[0xe] = 0;
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


// ==== FUN_004c1c60 @ 0x004c1c60 ====

void FUN_004c1c60(void *param_1)

{
  if (*(char *)((int)param_1 + 0x3d) == '\0') {
    FUN_004c1c60(*(undefined4 *)((int)param_1 + 8));
    FUN_004c09b0();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004c1ca0 @ 0x004c1ca0 ====

void FUN_004c1ca0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004c0f00(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004c1cd0 @ 0x004c1cd0 ====

int FUN_004c1cd0(int param_1,int param_2,undefined4 param_3)

{
  FUN_004c1750(param_1,param_2,param_3);
  return param_2 * 0x20 + param_1;
}


// ==== FUN_004c1d00 @ 0x004c1d00 ====

void FUN_004c1d00(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_009806f8;
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
      uVar1 = FUN_004c0a00();
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
      iVar2 = FUN_004c1500(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_004c1750(iVar2,param_2,&local_3c);
      FUN_004c1500(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x20);
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
        FUN_004c1500(param_1,local_1c,param_2 * 0x20 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004c1cd0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 5),&local_3c)
        ;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x20;
        local_8 = 0;
        FUN_004c1400(param_1,*(int *)(in_ECX + 8) + param_2 * -0x20,&local_3c);
      }
      else {
        pvVar3 = (void *)((int)local_1c + param_2 * -0x20);
        uVar4 = FUN_004c1500(pvVar3,local_1c,local_1c);
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


// ==== Catch@004c1e96 @ 0x004c1e96 ====

void Catch_004c1e96(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_004c1940(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@004c1f25 @ 0x004c1f25 ====

void Catch_004c1f25(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x20;
  FUN_004c1940(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004c1fb0 @ 0x004c1fb0 ====

void FUN_004c1fb0(void)

{
  int in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098073f;
  pvStack_c = ExceptionList;
  local_4 = 3;
  ExceptionList = &pvStack_c;
  FUN_004c0f00(local_10,**(undefined4 **)(in_ECX + 0xac),*(undefined4 **)(in_ECX + 0xac));
  _free(*(void **)(in_ECX + 0xac));
  return;
}


// ==== FUN_004c20e0 @ 0x004c20e0 ====

void FUN_004c20e0(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980750;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 5;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uVar1 != 0) {
    if (0x7ffffff < uVar1) {
      uVar1 = FUN_004c0a00();
    }
    pvVar2 = operator_new(uVar1 * 0x20);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 0x20 + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_004c1500(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),pvVar2);
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004c2184 @ 0x004c2184 ====

void Catch_004c2184(void)

{
  FUN_004b6960();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004c21a0 @ 0x004c21a0 ====

void FUN_004c21a0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004c1c60(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x3d) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x3d) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x3d);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x3d);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x3d);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x3d);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_004c1970(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004c2260 @ 0x004c2260 ====

undefined4 *
FUN_004c2260(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980771;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x40);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[3] = *param_4;
    FUN_004c18d0(param_4 + 1);
    *(undefined1 *)(puVar1 + 0xf) = param_5;
    *(undefined1 *)((int)puVar1 + 0x3d) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@004c22e6 @ 0x004c22e6 ====

void Catch_004c22e6(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004c2300 @ 0x004c2300 ====

undefined4 * FUN_004c2300(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980780;
  local_10 = ExceptionList;
  local_18 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)param_1 + 0x3d) == '\0') {
    ExceptionList = &local_10;
    puVar1 = (undefined4 *)
             FUN_004c2260(local_18,param_2,local_18,param_1 + 3,*(undefined1 *)(param_1 + 0xf));
    if (*(char *)((int)local_18 + 0x3d) != '\0') {
      local_18 = puVar1;
    }
    local_8 = 0;
    uVar2 = FUN_004c2300(*param_1,puVar1);
    *puVar1 = uVar2;
    uVar2 = FUN_004c2300(param_1[2],puVar1);
    puVar1[2] = uVar2;
  }
  ExceptionList = local_10;
  return local_18;
}


// ==== Catch@004c2391 @ 0x004c2391 ====

void Catch_004c2391(void)

{
  int unaff_EBP;
  
  FUN_004c1c60(*(undefined4 *)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004c23b0 @ 0x004c23b0 ====

void FUN_004c23b0(void)

{
  int iVar1;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009807bf;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_0058b910();
  *(int *)(in_ECX + 0x3c) = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(int *)(*(int *)(in_ECX + 0x3c) + 4) = *(int *)(in_ECX + 0x3c);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)(in_ECX + 0x3c);
  *(int *)(*(int *)(in_ECX + 0x3c) + 8) = *(int *)(in_ECX + 0x3c);
  *(undefined4 *)(in_ECX + 0x40) = 0;
  local_4 = 0;
  iVar1 = FUN_0058b910();
  *(int *)(in_ECX + 0x54) = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(int *)(*(int *)(in_ECX + 0x54) + 4) = *(int *)(in_ECX + 0x54);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(in_ECX + 0x54);
  *(int *)(*(int *)(in_ECX + 0x54) + 8) = *(int *)(in_ECX + 0x54);
  *(undefined4 *)(in_ECX + 0x58) = 0;
  local_4._0_1_ = 1;
  iVar1 = FUN_004be360();
  *(int *)(in_ECX + 0x6c) = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(int *)(*(int *)(in_ECX + 0x6c) + 4) = *(int *)(in_ECX + 0x6c);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(in_ECX + 0x6c);
  *(int *)(*(int *)(in_ECX + 0x6c) + 8) = *(int *)(in_ECX + 0x6c);
  *(undefined4 *)(in_ECX + 0x70) = 0;
  local_4._0_1_ = 2;
  iVar1 = FUN_004be360();
  *(int *)(in_ECX + 0x8c) = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(int *)(*(int *)(in_ECX + 0x8c) + 4) = *(int *)(in_ECX + 0x8c);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x8c) = *(undefined4 *)(in_ECX + 0x8c);
  *(int *)(*(int *)(in_ECX + 0x8c) + 8) = *(int *)(in_ECX + 0x8c);
  *(undefined4 *)(in_ECX + 0x90) = 0;
  local_4 = CONCAT31(local_4._1_3_,3);
  iVar1 = FUN_004be360();
  *(int *)(in_ECX + 0xac) = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(int *)(*(int *)(in_ECX + 0xac) + 4) = *(int *)(in_ECX + 0xac);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0xac) = *(undefined4 *)(in_ECX + 0xac);
  *(int *)(*(int *)(in_ECX + 0xac) + 8) = *(int *)(in_ECX + 0xac);
  *(undefined4 *)(in_ECX + 0xb0) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004c24c0 @ 0x004c24c0 ====

void FUN_004c24c0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 5) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 5))) {
    FUN_004c1d00(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_004c1750(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x20;
  return;
}


// ==== FUN_004c2530 @ 0x004c2530 ====

void FUN_004c2530(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_009808c8;
  local_c = ExceptionList;
  if (0x5555553 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004c2260(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x3c);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x3c) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0xf] == '\0') {
LAB_004c2629:
        *(undefined1 *)(*piVar5 + 0x3c) = 1;
        *(undefined1 *)(piVar6 + 0xf) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x3c) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_004be0c0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x3c) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x3c) = 0;
        FUN_00713660(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0xf] == '\0') goto LAB_004c2629;
      if (piVar7 == (int *)*piVar2) {
        FUN_00713660(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x3c) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x3c) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x3d) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x3c);
  } while( true );
}


// ==== FUN_004c2710 @ 0x004c2710 ====

void FUN_004c2710(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004c21a0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004c2740 @ 0x004c2740 ====

void FUN_004c2740(int param_1)

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
  uVar7 = FUN_004c2300(*(undefined4 *)(*(int *)(param_1 + 4) + 4),iVar2);
  *(undefined4 *)(iVar2 + 4) = uVar7;
  piVar3 = *(int **)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  piVar4 = (int *)piVar3[1];
  if (*(char *)((int)piVar4 + 0x3d) != '\0') {
    *piVar3 = (int)piVar3;
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    return;
  }
  cVar1 = *(char *)(*piVar4 + 0x3d);
  piVar6 = (int *)*piVar4;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*piVar6 + 0x3d);
    piVar4 = piVar6;
    piVar6 = (int *)*piVar6;
  }
  *piVar3 = (int)piVar4;
  iVar2 = *(int *)(*(int *)(in_ECX + 4) + 4);
  iVar5 = *(int *)(iVar2 + 8);
  cVar1 = *(char *)(iVar5 + 0x3d);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(int *)(iVar5 + 8) + 0x3d);
    iVar2 = iVar5;
    iVar5 = *(int *)(iVar5 + 8);
  }
  *(int *)(*(int *)(in_ECX + 4) + 8) = iVar2;
  return;
}


// ==== FUN_004c27c0 @ 0x004c27c0 ====

void FUN_004c27c0(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x3d) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x3d) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_004c2530(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_00713710();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_004c2530(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004c2880 @ 0x004c2880 ====

void FUN_004c2880(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009807d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_004be3a0();
  *(int *)(in_ECX + 4) = iVar1;
  *(undefined1 *)(iVar1 + 0x3d) = 1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  local_8 = 0;
  FUN_004c2740(param_1);
  ExceptionList = local_10;
  return;
}


// ==== Catch@004c28f1 @ 0x004c28f1 ====

void Catch_004c28f1(void)

{
  FUN_004c2710();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004c2910 @ 0x004c2910 ====

void FUN_004c2910(void)

{
  int iVar1;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009807f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  local_4 = 1;
  iVar1 = FUN_004be3a0();
  *(int *)(in_ECX + 0x34) = iVar1;
  *(undefined1 *)(iVar1 + 0x3d) = 1;
  *(int *)(*(int *)(in_ECX + 0x34) + 4) = *(int *)(in_ECX + 0x34);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(in_ECX + 0x34);
  *(int *)(*(int *)(in_ECX + 0x34) + 8) = *(int *)(in_ECX + 0x34);
  *(undefined4 *)(in_ECX + 0x38) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004c2990 @ 0x004c2990 ====

void FUN_004c2990(void)

{
  int in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980813;
  pvStack_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  FUN_004c21a0(local_10,**(undefined4 **)(in_ECX + 0x34),*(undefined4 **)(in_ECX + 0x34));
  _free(*(void **)(in_ECX + 0x34));
  return;
}


// ==== FUN_004c2a20 @ 0x004c2a20 ====

void FUN_004c2a20(void)

{
  FUN_004c2990();
  return;
}


// ==== FUN_004c2a30 @ 0x004c2a30 ====

void FUN_004c2a30(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009807f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  FUN_004c20e0(param_1 + 0x20);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_004c2880(param_1 + 0x30);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004c2ab0 @ 0x004c2ab0 ====

void FUN_004c2ab0(void)

{
  FUN_004c2990();
  return;
}


// ==== FUN_004c2ac0 @ 0x004c2ac0 ====

undefined4 *
FUN_004c2ac0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 *param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980831;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x50);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    *(undefined2 *)(puVar1 + 3) = *param_4;
    FUN_004c2a30(param_4 + 2);
    *(undefined1 *)(puVar1 + 0x13) = param_5;
    *(undefined1 *)((int)puVar1 + 0x4d) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@004c2b48 @ 0x004c2b48 ====

void Catch_004c2b48(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004c2b60 @ 0x004c2b60 ====

void FUN_004c2b60(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_009808c8;
  local_c = ExceptionList;
  if (0x3fffffd < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004c2ac0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x4c);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x4c) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x13] == '\0') {
LAB_004c2c59:
        *(undefined1 *)(*piVar5 + 0x4c) = 1;
        *(undefined1 *)(piVar6 + 0x13) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x4c) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_004be110(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x4c) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x4c) = 0;
        FUN_004be160(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x13] == '\0') goto LAB_004c2c59;
      if (piVar7 == (int *)*piVar2) {
        FUN_004be160(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x4c) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x4c) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x4d) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x4c);
  } while( true );
}


// ==== FUN_004c2d40 @ 0x004c2d40 ====

/* WARNING: Removing unreachable block (ram,0x004c2e53) */
/* WARNING: Removing unreachable block (ram,0x004c2e63) */
/* WARNING: Removing unreachable block (ram,0x004c2e6c) */
/* WARNING: Removing unreachable block (ram,0x004c2e6f) */
/* WARNING: Removing unreachable block (ram,0x004c2e5f) */
/* WARNING: Removing unreachable block (ram,0x004c2e7d) */
/* WARNING: Removing unreachable block (ram,0x004c2e8a) */
/* WARNING: Removing unreachable block (ram,0x004c2e95) */
/* WARNING: Removing unreachable block (ram,0x004c2e91) */
/* WARNING: Removing unreachable block (ram,0x004c2e85) */
/* WARNING: Removing unreachable block (ram,0x004c2e98) */

void FUN_004c2d40(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_009808c8;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x4d) != '\0') {
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
  FUN_004be210();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x4d) == '\0') {
    if (*(char *)(param_2[2] + 0x4d) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x4d) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x4d) == '\0') {
      piVar3 = (int *)FUN_004bdef0(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x4d) == '\0') {
      uVar4 = FUN_004bded0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0x13] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x13] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x13] == '\0') {
            *(undefined1 *)(piVar5 + 0x13) = 1;
            *(undefined1 *)(piVar3 + 0x13) = 0;
            FUN_004be110(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x4d) == '\0') {
            if ((*(char *)(*piVar5 + 0x4c) == '\x01') && (*(char *)(piVar5[2] + 0x4c) == '\x01'))
            goto LAB_004c2f65;
            if (*(char *)(piVar5[2] + 0x4c) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x4c) = 1;
              *(undefined1 *)(piVar5 + 0x13) = 0;
              FUN_004be160(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0x13) = (char)piVar3[0x13];
            *(undefined1 *)(piVar3 + 0x13) = 1;
            *(undefined1 *)(piVar5[2] + 0x4c) = 1;
            FUN_004be110(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0x13] == '\0') {
            *(undefined1 *)(piVar5 + 0x13) = 1;
            *(undefined1 *)(piVar3 + 0x13) = 0;
            FUN_004be160(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x4d) == '\0') {
            if ((*(char *)(piVar5[2] + 0x4c) != '\x01') || (*(char *)(*piVar5 + 0x4c) != '\x01')) {
              if (*(char *)(*piVar5 + 0x4c) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x4c) = 1;
                *(undefined1 *)(piVar5 + 0x13) = 0;
                FUN_004be110(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0x13) = (char)piVar3[0x13];
              *(undefined1 *)(piVar3 + 0x13) = 1;
              *(undefined1 *)(*piVar5 + 0x4c) = 1;
              FUN_004be160(piVar3);
              break;
            }
LAB_004c2f65:
            *(undefined1 *)(piVar5 + 0x13) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x13) = 1;
  }
  FUN_004c2990();
  _free(param_2);
  return;
}


// ==== FUN_004c3000 @ 0x004c3000 ====

void FUN_004c3000(undefined4 *param_1,ushort *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x4d) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x4d) == '\0');
  }
  param_2 = (ushort *)puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_004c2b60(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_004bdf10();
  }
  if (*(ushort *)((int)param_2 + 0xc) < *puVar2) {
    puVar4 = (undefined4 *)FUN_004c2b60(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004c30c0 @ 0x004c30c0 ====

void FUN_004c30c0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x4d) == '\0') {
    FUN_004c30c0(*(undefined4 *)((int)param_1 + 8));
    FUN_004c2ab0();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004c3100 @ 0x004c3100 ====

undefined4 * FUN_004c3100(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980840;
  local_10 = ExceptionList;
  local_18 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)param_1 + 0x4d) == '\0') {
    ExceptionList = &local_10;
    puVar1 = (undefined4 *)
             FUN_004c2ac0(local_18,param_2,local_18,param_1 + 3,*(undefined1 *)(param_1 + 0x13));
    if (*(char *)((int)local_18 + 0x4d) != '\0') {
      local_18 = puVar1;
    }
    local_8 = 0;
    uVar2 = FUN_004c3100(*param_1,puVar1);
    *puVar1 = uVar2;
    uVar2 = FUN_004c3100(param_1[2],puVar1);
    puVar1[2] = uVar2;
  }
  ExceptionList = local_10;
  return local_18;
}


// ==== Catch@004c3191 @ 0x004c3191 ====

void Catch_004c3191(void)

{
  int unaff_EBP;
  
  FUN_004c30c0(*(undefined4 *)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004c31b0 @ 0x004c31b0 ====

void FUN_004c31b0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004c30c0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x4d) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x4d) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x4d);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x4d);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x4d);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x4d);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_004c2d40(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004c3270 @ 0x004c3270 ====

void FUN_004c3270(int param_1)

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
  uVar7 = FUN_004c3100(*(undefined4 *)(*(int *)(param_1 + 4) + 4),iVar2);
  *(undefined4 *)(iVar2 + 4) = uVar7;
  piVar3 = *(int **)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  piVar4 = (int *)piVar3[1];
  if (*(char *)((int)piVar4 + 0x4d) != '\0') {
    *piVar3 = (int)piVar3;
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    return;
  }
  cVar1 = *(char *)(*piVar4 + 0x4d);
  piVar6 = (int *)*piVar4;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*piVar6 + 0x4d);
    piVar4 = piVar6;
    piVar6 = (int *)*piVar6;
  }
  *piVar3 = (int)piVar4;
  iVar2 = *(int *)(*(int *)(in_ECX + 4) + 4);
  iVar5 = *(int *)(iVar2 + 8);
  cVar1 = *(char *)(iVar5 + 0x4d);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(int *)(iVar5 + 8) + 0x4d);
    iVar2 = iVar5;
    iVar5 = *(int *)(iVar5 + 8);
  }
  *(int *)(*(int *)(in_ECX + 4) + 8) = iVar2;
  return;
}


// ==== FUN_004c32f0 @ 0x004c32f0 ====

void FUN_004c32f0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004c31b0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004c3320 @ 0x004c3320 ====

void FUN_004c3320(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980850;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_004be3e0();
  *(int *)(in_ECX + 4) = iVar1;
  *(undefined1 *)(iVar1 + 0x4d) = 1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  local_8 = 0;
  FUN_004c3270(param_1);
  ExceptionList = local_10;
  return;
}


// ==== Catch@004c3391 @ 0x004c3391 ====

void Catch_004c3391(void)

{
  FUN_004c32f0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004c33b0 @ 0x004c33b0 ====

void FUN_004c33b0(void)

{
  int iVar1;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980888;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  local_4 = 0;
  iVar1 = FUN_004be3e0();
  *(int *)(in_ECX + 0x20) = iVar1;
  *(undefined1 *)(iVar1 + 0x4d) = 1;
  *(int *)(*(int *)(in_ECX + 0x20) + 4) = *(int *)(in_ECX + 0x20);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(in_ECX + 0x20);
  *(int *)(*(int *)(in_ECX + 0x20) + 8) = *(int *)(in_ECX + 0x20);
  *(undefined4 *)(in_ECX + 0x24) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004c3420 @ 0x004c3420 ====

void FUN_004c3420(void)

{
  int in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980868;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  FUN_004c31b0(local_10,**(undefined4 **)(in_ECX + 0x20),*(undefined4 **)(in_ECX + 0x20));
  _free(*(void **)(in_ECX + 0x20));
  return;
}


// ==== FUN_004c34a0 @ 0x004c34a0 ====

void FUN_004c34a0(void)

{
  FUN_004c3420();
  return;
}


// ==== FUN_004c34b0 @ 0x004c34b0 ====

void FUN_004c34b0(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00980888;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  FUN_004c3320(param_1 + 0x1c);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004c3520 @ 0x004c3520 ====

void FUN_004c3520(void)

{
  FUN_004c3420();
  return;
}


// ==== FUN_004c3530 @ 0x004c3530 ====

undefined4 *
FUN_004c3530(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 *param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009808b1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x3c);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    *(undefined2 *)(puVar1 + 3) = *param_4;
    FUN_004c34b0(param_4 + 2);
    *(undefined1 *)(puVar1 + 0xe) = param_5;
    *(undefined1 *)((int)puVar1 + 0x39) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@004c35b8 @ 0x004c35b8 ====

void Catch_004c35b8(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004c35d0 @ 0x004c35d0 ====

void FUN_004c35d0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_009808c8;
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
  piVar4 = (int *)FUN_004c3530(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_004c36c9:
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
      if ((char)piVar6[0xe] == '\0') goto LAB_004c36c9;
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


// ==== FUN_004c37b0 @ 0x004c37b0 ====

void FUN_004c37b0(undefined4 *param_1,ushort *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x39) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x39) == '\0');
  }
  param_2 = (ushort *)puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_004c35d0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_004be260();
  }
  if (*(ushort *)((int)param_2 + 0xc) < *puVar2) {
    puVar4 = (undefined4 *)FUN_004c35d0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004c3870 @ 0x004c3870 ====

/* WARNING: Removing unreachable block (ram,0x004c3983) */
/* WARNING: Removing unreachable block (ram,0x004c3993) */
/* WARNING: Removing unreachable block (ram,0x004c399c) */
/* WARNING: Removing unreachable block (ram,0x004c399f) */
/* WARNING: Removing unreachable block (ram,0x004c398f) */
/* WARNING: Removing unreachable block (ram,0x004c39ad) */
/* WARNING: Removing unreachable block (ram,0x004c39ba) */
/* WARNING: Removing unreachable block (ram,0x004c39c5) */
/* WARNING: Removing unreachable block (ram,0x004c39c1) */
/* WARNING: Removing unreachable block (ram,0x004c39b5) */
/* WARNING: Removing unreachable block (ram,0x004c39c8) */

void FUN_004c3870(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_009808c8;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x39) != '\0') {
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
  FUN_004be1c0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x39) == '\0') {
    if (*(char *)(param_2[2] + 0x39) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x39) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x39) == '\0') {
      piVar3 = (int *)FUN_00412850(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x39) == '\0') {
      uVar4 = FUN_004be020(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0xe] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0xe] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0xe] == '\0') {
            *(undefined1 *)(piVar5 + 0xe) = 1;
            *(undefined1 *)(piVar3 + 0xe) = 0;
            FUN_006c8fe0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x39) == '\0') {
            if ((*(char *)(*piVar5 + 0x38) == '\x01') && (*(char *)(piVar5[2] + 0x38) == '\x01'))
            goto LAB_004c3a95;
            if (*(char *)(piVar5[2] + 0x38) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x38) = 1;
              *(undefined1 *)(piVar5 + 0xe) = 0;
              FUN_006c9030(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0xe) = (char)piVar3[0xe];
            *(undefined1 *)(piVar3 + 0xe) = 1;
            *(undefined1 *)(piVar5[2] + 0x38) = 1;
            FUN_006c8fe0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0xe] == '\0') {
            *(undefined1 *)(piVar5 + 0xe) = 1;
            *(undefined1 *)(piVar3 + 0xe) = 0;
            FUN_006c9030(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x39) == '\0') {
            if ((*(char *)(piVar5[2] + 0x38) != '\x01') || (*(char *)(*piVar5 + 0x38) != '\x01')) {
              if (*(char *)(*piVar5 + 0x38) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x38) = 1;
                *(undefined1 *)(piVar5 + 0xe) = 0;
                FUN_006c8fe0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0xe) = (char)piVar3[0xe];
              *(undefined1 *)(piVar3 + 0xe) = 1;
              *(undefined1 *)(*piVar5 + 0x38) = 1;
              FUN_006c9030(piVar3);
              break;
            }
LAB_004c3a95:
            *(undefined1 *)(piVar5 + 0xe) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xe) = 1;
  }
  FUN_004c3420();
  _free(param_2);
  return;
}


// ==== FUN_004c3b30 @ 0x004c3b30 ====

void FUN_004c3b30(void *param_1)

{
  if (*(char *)((int)param_1 + 0x39) == '\0') {
    FUN_004c3b30(*(undefined4 *)((int)param_1 + 8));
    FUN_004c3520();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004c3b70 @ 0x004c3b70 ====

void FUN_004c3b70(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004c3b30(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x39) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x39) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x39);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x39);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x39);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x39);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_004c3870(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004c3c30 @ 0x004c3c30 ====

void FUN_004c3c30(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004c3b70(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004c3c60 @ 0x004c3c60 ====

void FUN_004c3c60(byte param_1)

{
  void *in_ECX;
  
  FUN_004c0680();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004c3c80 @ 0x004c3c80 ====

void FUN_004c3c80(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_004c3c80(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004c3cc0 @ 0x004c3cc0 ====

uint FUN_004c3cc0(int param_1,int param_2,byte param_3)

{
  uint extraout_EAX;
  
  if (param_1 == param_2) {
    return (uint)param_3;
  }
  _free(*(void **)(param_1 + 0x10));
  return extraout_EAX;
}


// ==== FUN_004c3d30 @ 0x004c3d30 ====

void FUN_004c3d30(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_009808e8;
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
LAB_004c3e29:
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
      if ((char)piVar6[5] == '\0') goto LAB_004c3e29;
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


// ==== FUN_004c3f10 @ 0x004c3f10 ====

/* WARNING: Removing unreachable block (ram,0x004c4023) */
/* WARNING: Removing unreachable block (ram,0x004c4033) */
/* WARNING: Removing unreachable block (ram,0x004c403c) */
/* WARNING: Removing unreachable block (ram,0x004c403f) */
/* WARNING: Removing unreachable block (ram,0x004c402f) */
/* WARNING: Removing unreachable block (ram,0x004c404d) */
/* WARNING: Removing unreachable block (ram,0x004c405a) */
/* WARNING: Removing unreachable block (ram,0x004c4065) */
/* WARNING: Removing unreachable block (ram,0x004c4061) */
/* WARNING: Removing unreachable block (ram,0x004c4055) */
/* WARNING: Removing unreachable block (ram,0x004c4068) */

void FUN_004c3f10(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_009808e8;
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
            goto LAB_004c4135;
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
LAB_004c4135:
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


// ==== FUN_004c41c0 @ 0x004c41c0 ====

void FUN_004c41c0(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_004c3d30(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_004c3d30(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004c4280 @ 0x004c4280 ====

void FUN_004c4280(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004c3c80(piVar6[1]);
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
    FUN_004c3f10(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004c4340 @ 0x004c4340 ====

void FUN_004c4340(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004c4280(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004c4370 @ 0x004c4370 ====

void FUN_004c4370(void)

{
  undefined4 *in_ECX;
  uint local_14 [2];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00980913;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009b078c;
  local_4 = 1;
  if (in_ECX[0x11] != 0) {
    local_14[0] = local_14[0] & 0xffffff00;
    FUN_004c3cc0(*(undefined4 *)in_ECX[0x10],(undefined4 *)in_ECX[0x10],local_14[0]);
    FUN_004c3c80(*(undefined4 *)(in_ECX[0x10] + 4));
    *(undefined4 *)(in_ECX[0x10] + 4) = in_ECX[0x10];
    in_ECX[0x11] = 0;
    *(undefined4 *)in_ECX[0x10] = in_ECX[0x10];
    *(undefined4 *)(in_ECX[0x10] + 8) = in_ECX[0x10];
  }
  local_4 = local_4 & 0xffffff00;
  FUN_004c4280(local_14,*(undefined4 *)in_ECX[0x10],(undefined4 *)in_ECX[0x10]);
  _free((void *)in_ECX[0x10]);
  return;
}


// ==== FUN_004c4430 @ 0x004c4430 ====

void FUN_004c4430(undefined4 param_1)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980930;
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
  *in_ECX = &PTR_FUN_009b078c;
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


// ==== FUN_004c44e0 @ 0x004c44e0 ====

/* WARNING: Removing unreachable block (ram,0x004c496b) */

void FUN_004c44e0(undefined4 param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int local_30;
  undefined1 local_2c [8];
  int local_24;
  uint *local_20;
  undefined1 local_1c [4];
  void *local_18;
  int local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00980942;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = operator_new(0x10);
  if (puVar1 == (uint *)0x0) {
    puVar1 = (uint *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 1000;
    puVar1[3] = 0;
  }
  uVar2 = FUN_00411430();
  if (*param_2 < uVar2) {
    do {
      uVar3 = FUN_00411510(*param_2);
      local_18 = (void *)0x0;
      local_14 = 0;
      local_10 = 0;
      local_4 = 0;
      FUN_00405670(uVar3,local_1c);
      if ((local_18 == (void *)0x0) ||
         (iVar4 = local_14 - (int)local_18 >> 0x1f,
         (local_14 - (int)local_18) / 0x1c + iVar4 == iVar4)) {
        local_4 = 0xffffffff;
        if (local_18 != (void *)0x0) {
          FUN_00405de0(local_18,local_14,local_1c,param_2);
          _free(local_18);
          return;
        }
      }
      else {
        iVar4 = FUN_00403620(0,*(undefined4 *)((int)local_18 + 0x14),s_<model>_009b073c,7);
        if (iVar4 != 0) {
          if ((local_18 == (void *)0x0) ||
             (local_24 = (local_14 - (int)local_18) / 0x1c, local_24 == 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar4 = FUN_00403620(0,*(undefined4 *)((int)local_18 + 0x14),s_<_model>_009b0744,8);
          if (iVar4 == 0) {
            local_24 = local_30;
            local_20 = puVar1;
            FUN_004c41c0(local_2c,&local_24);
            if (local_18 == (void *)0x0) {
              ExceptionList = local_c;
              return;
            }
            FUN_00405de0(local_18,local_14,local_1c,param_2);
            _free(local_18);
            return;
          }
          if ((local_18 == (void *)0x0) ||
             (local_24 = (local_14 - (int)local_18) / 0x1c, local_24 == 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar4 = FUN_00403620(0,*(undefined4 *)((int)local_18 + 0x14),s_modelID_009b0750,7);
          if (iVar4 == 0) {
            if ((local_18 == (void *)0x0) || ((uint)((local_14 - (int)local_18) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
              FUN_00405ca0();
            }
            local_30 = thunk_FUN_00796fb0((int)local_18 + 0x1c);
          }
          if ((local_18 == (void *)0x0) ||
             (local_24 = (local_14 - (int)local_18) / 0x1c, local_24 == 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar4 = FUN_00403620(0,*(undefined4 *)((int)local_18 + 0x14),s_effectID_009b0758,8);
          if (iVar4 == 0) {
            if ((local_18 == (void *)0x0) || ((uint)((local_14 - (int)local_18) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
              FUN_00405ca0();
            }
            iVar4 = thunk_FUN_00796f80((int)local_18 + 0x1c);
            if ((local_18 == (void *)0x0) || ((uint)((local_14 - (int)local_18) / 0x1c) < 3)) {
                    /* WARNING: Subroutine does not return */
              FUN_00405ca0();
            }
            uVar2 = thunk_FUN_00796f80((int)local_18 + 0x38);
            *puVar1 = iVar4 << 0x10 | uVar2 & 0xffff;
          }
          if ((local_18 == (void *)0x0) ||
             (local_24 = (local_14 - (int)local_18) / 0x1c, local_24 == 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar4 = FUN_00403620(0,*(undefined4 *)((int)local_18 + 0x14),s_sceneID_009b0764,7);
          if (iVar4 == 0) {
            if ((local_18 == (void *)0x0) || ((uint)((local_14 - (int)local_18) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
              FUN_00405ca0();
            }
            uVar2 = thunk_FUN_00796fb0((int)local_18 + 0x1c);
            puVar1[1] = uVar2;
          }
          if ((local_18 == (void *)0x0) ||
             (local_24 = (local_14 - (int)local_18) / 0x1c, local_24 == 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar4 = FUN_00403620(0,*(undefined4 *)((int)local_18 + 0x14),s_playTime_009b076c,8);
          if (iVar4 == 0) {
            if ((local_18 == (void *)0x0) || ((uint)((local_14 - (int)local_18) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
              FUN_00405ca0();
            }
            uVar2 = thunk_FUN_00796fb0((int)local_18 + 0x1c);
            puVar1[2] = uVar2;
          }
          if ((local_18 == (void *)0x0) ||
             (local_24 = (local_14 - (int)local_18) / 0x1c, local_24 == 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          iVar4 = FUN_00403620(0,*(undefined4 *)((int)local_18 + 0x14),s_playLoop_009b0778,8);
          if (iVar4 == 0) {
            if ((local_18 == (void *)0x0) || ((uint)((local_14 - (int)local_18) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
              FUN_00405ca0();
            }
            uVar2 = thunk_FUN_00796fb0((int)local_18 + 0x1c);
            puVar1[3] = uVar2;
          }
        }
        local_4 = 0xffffffff;
        if (local_18 != (void *)0x0) {
          FUN_00405de0(local_18,local_14,local_1c,param_2);
          _free(local_18);
          return;
        }
      }
      local_4 = 0xffffffff;
      *param_2 = *param_2 + 1;
      local_18 = (void *)0x0;
      local_14 = 0;
      local_10 = 0;
      uVar2 = FUN_00411430();
    } while (*param_2 < uVar2);
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004c4a50 @ 0x004c4a50 ====

/* WARNING: Removing unreachable block (ram,0x004c4c28) */

undefined4 FUN_004c4a50(int *param_1)

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
  puStack_8 = &LAB_00980954;
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
         (iVar2 = FUN_00403620(0,*(undefined4 *)((int)pvStack_18 + 0x14),&DAT_009b0730,1),
         iVar2 == 0)) {
        uStack_4 = 0xffffffff;
        if (pvStack_18 != (void *)0x0) {
          FUN_00405de0(pvStack_18,iStack_14,auStack_1c,param_1);
          goto LAB_004c4bc7;
        }
      }
      else {
        if ((pvStack_18 == (void *)0x0) || ((iStack_14 - (int)pvStack_18) / 0x1c == 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        iVar2 = FUN_00403620(0,*(undefined4 *)((int)pvStack_18 + 0x14),s_<model>_009b0734,7);
        if (iVar2 == 0) {
          FUN_004c44e0(piVar1,&param_1);
          uVar5 = (uint)param_1;
        }
        uStack_4 = 0xffffffff;
        if (pvStack_18 != (void *)0x0) {
          FUN_00405de0(pvStack_18,iStack_14,auStack_1c,param_1);
LAB_004c4bc7:
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


// ==== FUN_004c4c40 @ 0x004c4c40 ====

void FUN_004c4c40(byte param_1)

{
  void *in_ECX;
  
  FUN_004c4370();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004c4c60 @ 0x004c4c60 ====

void FUN_004c4c60(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  uVar2 = DAT_009b0120;
  uVar1 = DAT_0099d080;
  in_ECX[7] = DAT_0099d080;
  in_ECX[8] = uVar1;
  in_ECX[9] = uVar1;
  in_ECX[10] = uVar1;
  in_ECX[0xb] = uVar1;
  in_ECX[0xc] = uVar1;
  in_ECX[4] = uVar2;
  uVar2 = DAT_0099d100;
  in_ECX[5] = uVar1;
  in_ECX[6] = uVar1;
  in_ECX[2] = 100;
  *(undefined1 *)(in_ECX + 0xd) = 0;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  in_ECX[0x13] = uVar1;
  *in_ECX = uVar2;
  in_ECX[1] = uVar1;
  return;
}


// ==== FUN_004c4d00 @ 0x004c4d00 ====

void FUN_004c4d00(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x50);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  return;
}


// ==== FUN_004c4d20 @ 0x004c4d20 ====

void FUN_004c4d20(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x34);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  return;
}


// ==== FUN_004c4d40 @ 0x004c4d40 ====

void FUN_004c4d40(undefined4 *param_1,ushort *param_2)

{
  int *piVar1;
  ushort uVar2;
  uint uVar3;
  int *piVar4;
  int in_ECX;
  
  uVar2 = *param_2;
  uVar3 = (uVar2 ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20);
  if (*(uint *)(in_ECX + 0x24) <= uVar3) {
    uVar3 = uVar3 + (-1 - (*(uint *)(in_ECX + 0x20) >> 1));
  }
  piVar1 = (int *)(*(int *)(in_ECX + 0x14) + uVar3 * 4);
  piVar4 = (int *)*piVar1;
  if (piVar4 != (int *)piVar1[1]) {
    do {
      if (uVar2 <= *(ushort *)(piVar4 + 2)) {
        if (uVar2 < *(ushort *)(piVar4 + 2)) {
          *param_1 = *(undefined4 *)(in_ECX + 8);
          return;
        }
        *param_1 = piVar4;
        return;
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)piVar1[1]);
  }
  *param_1 = *(undefined4 *)(in_ECX + 8);
  return;
}


// ==== FUN_004c4de0 @ 0x004c4de0 ====

void FUN_004c4de0(void)

{
  undefined4 *in_ECX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980981;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  in_ECX[0x16] = 0xf;
  in_ECX[0x15] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  local_4 = 2;
  if ((uint)in_ECX[8] < 0x10) {
    puVar2 = in_ECX + 3;
  }
  else {
    puVar2 = (undefined4 *)in_ECX[3];
  }
  if ((uint)in_ECX[8] < 0x10) {
    puVar1 = in_ECX + 3;
  }
  else {
    puVar1 = (undefined4 *)in_ECX[3];
  }
  FUN_004bdb30(local_10,puVar1,in_ECX[7] + (int)puVar2);
  puVar2 = in_ECX + 10;
  if ((uint)in_ECX[0xf] < 0x10) {
    puVar1 = puVar2;
  }
  else {
    puVar1 = (undefined4 *)*puVar2;
  }
  if (0xf < (uint)in_ECX[0xf]) {
    puVar2 = (undefined4 *)*puVar2;
  }
  FUN_004bdb30(local_10,puVar2,in_ECX[0xe] + (int)puVar1);
  puVar2 = in_ECX + 0x11;
  if ((uint)in_ECX[0x16] < 0x10) {
    puVar1 = puVar2;
  }
  else {
    puVar1 = (undefined4 *)*puVar2;
  }
  if (0xf < (uint)in_ECX[0x16]) {
    puVar2 = (undefined4 *)*puVar2;
  }
  FUN_004bdb30(local_10,puVar2,in_ECX[0x15] + (int)puVar1);
  *(undefined1 *)(in_ECX + 0x17) = 0;
  in_ECX[1] = 100;
  *in_ECX = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004c4ef0 @ 0x004c4ef0 ====

void FUN_004c4ef0(void)

{
  undefined4 *in_ECX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009809a6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  local_4 = 1;
  *in_ECX = 0;
  in_ECX[1] = 1;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  puVar1 = in_ECX + 3;
  if ((uint)in_ECX[8] < 0x10) {
    puVar2 = puVar1;
  }
  else {
    puVar2 = (undefined4 *)*puVar1;
  }
  if (0xf < (uint)in_ECX[8]) {
    puVar1 = (undefined4 *)*puVar1;
  }
  FUN_004bdb30(local_10,puVar1,in_ECX[7] + (int)puVar2);
  puVar1 = in_ECX + 10;
  if ((uint)in_ECX[0xf] < 0x10) {
    puVar2 = puVar1;
  }
  else {
    puVar2 = (undefined4 *)*puVar1;
  }
  if (0xf < (uint)in_ECX[0xf]) {
    puVar1 = (undefined4 *)*puVar1;
  }
  FUN_004bdb30(local_10,puVar1,in_ECX[0xe] + (int)puVar2);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004c4fc0 @ 0x004c4fc0 ====

void FUN_004c4fc0(void)

{
  undefined4 *in_ECX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009809bb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[0x27] = 0xf;
  in_ECX[0x26] = 0;
  *(undefined1 *)(in_ECX + 0x22) = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  local_4 = 0;
  in_ECX[1] = 0;
  *in_ECX = 0;
  *(undefined1 *)((int)in_ECX + 9) = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined1 *)((int)in_ECX + 10) = 0;
  in_ECX[0x19] = 0;
  in_ECX[8] = 0;
  in_ECX[10] = 0;
  in_ECX[9] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = 0;
  in_ECX[7] = 0;
  in_ECX[0x20] = 0;
  local_14 = DAT_0099d080;
  in_ECX[0x1a] = DAT_0099d080;
  in_ECX[0x1b] = local_14;
  in_ECX[0x1c] = local_14;
  local_10 = local_14;
  local_18 = local_14;
  in_ECX[0x1d] = local_14;
  local_1c = local_14;
  in_ECX[0x1f] = local_14;
  in_ECX[4] = 500;
  in_ECX[3] = 1000;
  in_ECX[5] = 1;
  in_ECX[6] = 5;
  in_ECX[0x1e] = local_14;
  puVar1 = in_ECX + 0x22;
  if ((uint)in_ECX[0x27] < 0x10) {
    puVar2 = puVar1;
  }
  else {
    puVar2 = (undefined4 *)*puVar1;
  }
  if (0xf < (uint)in_ECX[0x27]) {
    puVar1 = (undefined4 *)*puVar1;
  }
  FUN_004bdb30(&local_1c,puVar1,in_ECX[0x26] + (int)puVar2);
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004c5180 @ 0x004c5180 ====

void FUN_004c5180(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009809d8;
  local_c = ExceptionList;
  puVar2 = (undefined4 *)(in_ECX + 4);
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)puVar2 = 0;
  uVar1 = DAT_0099d080;
  local_4 = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 10;
  *(undefined4 *)(in_ECX + 0x24) = uVar1;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    puVar3 = puVar2;
  }
  else {
    puVar3 = (undefined4 *)*puVar2;
  }
  if (0xf < *(uint *)(in_ECX + 0x18)) {
    puVar2 = (undefined4 *)*puVar2;
  }
  FUN_004bdb30(local_10,puVar2,*(int *)(in_ECX + 0x14) + (int)puVar3);
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004c5210 @ 0x004c5210 ====

void FUN_004c5210(void)

{
  undefined4 uVar1;
  int in_ECX;
  int *piVar2;
  int *piVar3;
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009809fb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x38) = 0xf;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  uVar1 = DAT_0099d0b4;
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x14) = uVar1;
  local_14 = DAT_0099d080;
  local_4 = 0;
  local_18 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 8) = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0xc) = local_14;
  local_10 = local_14;
  *(undefined4 *)(in_ECX + 0x10) = local_14;
  piVar2 = (int *)(in_ECX + 0x24);
  if (*(uint *)(in_ECX + 0x38) < 0x10) {
    piVar3 = piVar2;
  }
  else {
    piVar3 = (int *)*piVar2;
  }
  if (0xf < *(uint *)(in_ECX + 0x38)) {
    piVar2 = (int *)*piVar2;
  }
  FUN_004bdb30(local_1c,piVar2,*(int *)(in_ECX + 0x34) + (int)piVar3);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004c52d0 @ 0x004c52d0 ====

void FUN_004c52d0(int *param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00980a52;
  local_c = ExceptionList;
  iVar2 = *param_1;
  ExceptionList = &local_c;
  param_1[2] = DAT_0099d080;
  param_1[1] = 3;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  if (iVar2 == 6) {
    pvVar1 = operator_new(0x30);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      param_1[10] = 0;
      ExceptionList = local_c;
      return;
    }
    iVar2 = FUN_004c5180();
    param_1[10] = iVar2;
    ExceptionList = local_c;
    return;
  }
  if (iVar2 == 5) {
    puVar3 = operator_new(0xc);
    if (puVar3 == (undefined4 *)0x0) {
      param_1[4] = 0;
      ExceptionList = local_c;
      return;
    }
    puVar3[1] = DAT_009a09bc;
    iVar2 = DAT_0099d080;
    *puVar3 = 0;
    puVar3[2] = iVar2;
    param_1[4] = (int)puVar3;
    ExceptionList = local_c;
    return;
  }
  if (iVar2 == 4) {
    pvVar1 = operator_new(0x5c);
    if (pvVar1 == (void *)0x0) {
      param_1[6] = 0;
      ExceptionList = local_c;
      return;
    }
    iVar2 = FUN_004c4c60();
    param_1[6] = iVar2;
    ExceptionList = local_c;
    return;
  }
  pvVar1 = operator_new(0x48);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_004c4ef0();
  }
  param_1[8] = iVar2;
  iVar2 = *param_1;
  local_4 = 0xffffffff;
  if (iVar2 == 0xb) {
    pvVar1 = operator_new(0x3c);
    local_4 = 2;
    if (pvVar1 == (void *)0x0) {
      param_1[3] = 0;
      ExceptionList = local_c;
      return;
    }
    iVar2 = FUN_004c5210();
    param_1[3] = iVar2;
    ExceptionList = local_c;
    return;
  }
  if (((iVar2 == 3) || (iVar2 == 1)) || (iVar2 == 7)) {
    puVar3 = operator_new(0x14);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      *(undefined1 *)(puVar3 + 4) = 0;
    }
    param_1[5] = (int)puVar3;
    iVar2 = *param_1;
    if (iVar2 != 7) goto LAB_004c54d4;
  }
  else {
LAB_004c54d4:
    if (iVar2 != 3) goto LAB_004c553e;
  }
  pvVar1 = operator_new(0x60);
  local_4 = 3;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_004c4de0();
  }
  local_4 = 0xffffffff;
  param_1[7] = iVar2;
  if (*param_1 == 3) {
    pvVar1 = operator_new(0x3c);
    local_4 = 4;
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004c5210();
    }
    local_4 = 0xffffffff;
    param_1[3] = iVar2;
  }
LAB_004c553e:
  if ((*param_1 == 7) || (*param_1 == 8)) {
    pvVar1 = operator_new(0xa0);
    local_4 = 5;
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004c4fc0();
    }
    param_1[9] = iVar2;
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004c5590 @ 0x004c5590 ====

/* WARNING: Removing unreachable block (ram,0x004c6f55) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c5590(undefined4 param_1,uint *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  float fVar7;
  float *pfVar8;
  undefined4 *puVar9;
  float *pfVar10;
  float10 fVar11;
  undefined *puVar12;
  char *pcVar13;
  undefined1 local_128 [4];
  void *local_124;
  int local_120;
  undefined4 local_11c;
  float local_118;
  float local_114 [3];
  int iStack_108;
  undefined4 *puStack_104;
  undefined4 *puStack_100;
  float *local_fc;
  undefined4 *local_f8;
  undefined4 *local_f4;
  undefined4 *local_f0;
  int local_ec;
  float fStack_e8;
  float fStack_e4;
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
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  undefined1 local_78 [4];
  void *local_74;
  undefined4 local_64;
  uint local_60;
  undefined1 local_5c [8];
  undefined1 local_54 [4];
  void *local_50;
  undefined4 local_40;
  uint local_3c;
  float local_38 [11];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00980a77;
  local_c = ExceptionList;
  local_60 = 0xf;
  local_64 = 0;
  local_74 = (void *)((uint)local_74 & 0xffffff00);
  local_4 = 0;
  ExceptionList = &local_c;
  uVar4 = FUN_00411430();
  if (*param_2 < uVar4) {
    puVar9 = local_f0;
    do {
      uVar5 = FUN_00411510(*param_2);
      local_124 = (void *)0x0;
      local_120 = 0;
      local_11c = 0;
      local_4._0_1_ = 1;
      FUN_00405670(uVar5,local_128);
      if (((local_124 == (void *)0x0) ||
          (iVar6 = local_120 - (int)local_124 >> 0x1f,
          (local_120 - (int)local_124) / 0x1c + iVar6 == iVar6)) ||
         (iVar6 = FUN_00403620(0,*(undefined4 *)((int)local_124 + 0x14),&DAT_009b084c,1), iVar6 == 0
         )) {
        local_4 = (uint)local_4._1_3_ << 8;
        if (local_124 != (void *)0x0) {
          FUN_00405de0(local_124,local_120,local_128,local_118);
LAB_004c6f1f:
          _free(local_124);
          return;
        }
LAB_004c6f27:
        local_124 = (void *)0x0;
        local_120 = 0;
        local_11c = 0;
      }
      else {
        if ((local_124 == (void *)0x0) ||
           (local_118 = (float)((local_120 - (int)local_124) / 0x1c), local_118 == 0.0)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        iVar6 = FUN_00403620(0,*(undefined4 *)((int)local_124 + 0x14),s_<effectdata>_009b0850,0xc);
        if (iVar6 == 0) {
          local_4 = (uint)local_4._1_3_ << 8;
          if (local_124 != (void *)0x0) {
            FUN_00405de0(local_124,local_120,local_128,local_118);
            goto LAB_004c6f1f;
          }
          goto LAB_004c6f27;
        }
        if ((local_124 == (void *)0x0) ||
           (local_118 = (float)((local_120 - (int)local_124) / 0x1c), local_118 == 0.0)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        iVar6 = FUN_00403620(0,*(undefined4 *)((int)local_124 + 0x14),s_<_effectdata>_009b0860,0xd);
        if (iVar6 == 0) {
          local_3c = 0xf;
          local_40 = 0;
          local_50 = (void *)((uint)local_50 & 0xffffff00);
          FUN_00401660(local_78,0,0xffffffff);
          pfVar8 = local_114;
          pfVar10 = local_38;
          for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
            *pfVar10 = *pfVar8;
            pfVar8 = pfVar8 + 1;
            pfVar10 = pfVar10 + 1;
          }
          local_4 = CONCAT31(local_4._1_3_,2);
          FUN_004c82b0(local_5c,local_54);
          if (0xf < local_3c) {
            _free(local_50);
            return;
          }
          FUN_00406250();
          break;
        }
        if ((local_124 == (void *)0x0) || ((local_120 - (int)local_124) / 0x1c != 1)) {
          puVar12 = &DAT_009b0870;
          uVar5 = FUN_00405d30(0);
          cVar2 = FUN_004036a0(uVar5,puVar12);
          if (cVar2 == '\0') {
            pcVar13 = s_unittype_009b0878;
            uVar5 = FUN_00405d30(0);
            cVar2 = FUN_004036a0(uVar5,pcVar13);
            if (cVar2 == '\0') {
              pcVar13 = s_billboardtype_009b08e0;
              uVar5 = FUN_00405d30(0);
              cVar2 = FUN_004036a0(uVar5,pcVar13);
              if (cVar2 == '\0') {
                puVar12 = &DAT_009b0910;
                uVar5 = FUN_00405d30(0);
                cVar2 = FUN_004036a0(uVar5,puVar12);
                if (cVar2 == '\0') {
                  pcVar13 = s_sound_009b0918;
                  uVar5 = FUN_00405d30(0);
                  cVar2 = FUN_004036a0(uVar5,pcVar13);
                  if (cVar2 == '\0') {
                    pcVar13 = s_camera_009b0920;
                    uVar5 = FUN_00405d30(0);
                    cVar2 = FUN_004036a0(uVar5,pcVar13);
                    if (cVar2 == '\0') {
                      pcVar13 = s_textureloop_009b0928;
                      uVar5 = FUN_00405d30(0);
                      cVar2 = FUN_004036a0(uVar5,pcVar13);
                      if (cVar2 == '\0') {
                        pcVar13 = s_blendtype_009b0954;
                        uVar5 = FUN_00405d30(0);
                        cVar2 = FUN_004036a0(uVar5,pcVar13);
                        if (cVar2 == '\0') {
                          pcVar13 = s_texturefile_009b0970;
                          uVar5 = FUN_00405d30(0);
                          cVar2 = FUN_004036a0(uVar5,pcVar13);
                          if (cVar2 == '\0') {
                            pcVar13 = s_backprint_009b097c;
                            uVar5 = FUN_00405d30(0);
                            cVar2 = FUN_004036a0(uVar5,pcVar13);
                            if (cVar2 != '\0') {
                              uVar5 = FUN_00405d30(1);
                              uVar3 = thunk_FUN_00796fe0(uVar5);
                              *(undefined1 *)(local_f4 + 0x11) = uVar3;
                              goto LAB_004c6ee6;
                            }
                            pcVar13 = s_texturepack_009b0988;
                            uVar5 = FUN_00405d30(0);
                            cVar2 = FUN_004036a0(uVar5,pcVar13);
                            if (cVar2 == '\0') {
                              pcVar13 = s_texanimtime_009b0994;
                              uVar5 = FUN_00405d30(0);
                              cVar2 = FUN_004036a0(uVar5,pcVar13);
                              if (cVar2 != '\0') {
                                uVar5 = FUN_00405d30(1);
                                uVar5 = thunk_FUN_00796fb0(uVar5);
                                local_f4[0x10] = uVar5;
                                goto LAB_004c6ee6;
                              }
                              pcVar13 = s_leaftype_009b09a0;
                              uVar5 = FUN_00405d30(0);
                              cVar2 = FUN_004036a0(uVar5,pcVar13);
                              if (cVar2 == '\0') {
                                pcVar13 = s_activestate_009b09bc;
                                uVar5 = FUN_00405d30(0);
                                cVar2 = FUN_004036a0(uVar5,pcVar13);
                                if (cVar2 == '\0') {
                                  pcVar13 = s_lifetime_009b0a24;
                                  uVar5 = FUN_00405d30(0);
                                  cVar2 = FUN_004036a0(uVar5,pcVar13);
                                  if (cVar2 != '\0') {
                                    uVar5 = FUN_00405d30(1);
                                    uVar5 = thunk_FUN_00796fb0(uVar5);
                                    puVar9[4] = uVar5;
                                    uVar5 = FUN_00405d30(2);
                                    uVar5 = thunk_FUN_00796fb0(uVar5);
                                    puVar9[3] = uVar5;
                                    goto LAB_004c6ee6;
                                  }
                                  pcVar13 = s_followdirection_009b0a30;
                                  uVar5 = FUN_00405d30(0);
                                  cVar2 = FUN_004036a0(uVar5,pcVar13);
                                  if (cVar2 == '\0') {
                                    pcVar13 = s_trianglerender_009b0a48;
                                    uVar5 = FUN_00405d30(0);
                                    cVar2 = FUN_004036a0(uVar5,pcVar13);
                                    if (cVar2 == '\0') {
                                      pcVar13 = s_emitrate_009b0a60;
                                      uVar5 = FUN_00405d30(0);
                                      cVar2 = FUN_004036a0(uVar5,pcVar13);
                                      if (cVar2 == '\0') {
                                        pcVar13 = s_particlesize_009b0a6c;
                                        uVar5 = FUN_00405d30(0);
                                        cVar2 = FUN_004036a0(uVar5,pcVar13);
                                        if (cVar2 == '\0') {
                                          pcVar13 = s_maxelementcount_009b0a7c;
                                          uVar5 = FUN_00405d30(0);
                                          cVar2 = FUN_004036a0(uVar5,pcVar13);
                                          if (cVar2 == '\0') {
                                            pcVar13 = s_startrange_009b0a8c;
                                            uVar5 = FUN_00405d30(0);
                                            cVar2 = FUN_004036a0(uVar5,pcVar13);
                                            if (cVar2 == '\0') {
                                              pcVar13 = s_colorrange_009b0a98;
                                              uVar5 = FUN_00405d30(0);
                                              cVar2 = FUN_004036a0(uVar5,pcVar13);
                                              if (cVar2 == '\0') {
                                                pcVar13 = s_addrotate_009b0aa4;
                                                uVar5 = FUN_00405d30(0);
                                                cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                if (cVar2 == '\0') {
                                                  pcVar13 = s_endposition_009b0ab0;
                                                  uVar5 = FUN_00405d30(0);
                                                  cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                  if (cVar2 == '\0') {
                                                    pcVar13 = s_spawndirection_009b0abc;
                                                    uVar5 = FUN_00405d30(0);
                                                    cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                    if (cVar2 == '\0') {
                                                      pcVar13 = s_spawndirabs_009b0acc;
                                                      uVar5 = FUN_00405d30(0);
                                                      cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                      if (cVar2 == '\0') {
                                                        pcVar13 = s_velocity_009b0ad8;
                                                        uVar5 = FUN_00405d30(0);
                                                        cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                        if (cVar2 == '\0') {
                                                          pcVar13 = s_gravity_009b0ae4;
                                                          uVar5 = FUN_00405d30(0);
                                                          cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                          if (cVar2 == '\0') {
                                                            pcVar13 = s_acceleration_009b0aec;
                                                            uVar5 = FUN_00405d30(0);
                                                            cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                            if (cVar2 == '\0') {
                                                              pcVar13 = s_flattexturefile_009b0afc;
                                                              uVar5 = FUN_00405d30(0);
                                                              cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                              if (cVar2 != '\0') {
                                                                uVar5 = FUN_00405d30(1);
                                                                FUN_00401660(uVar5,0,0xffffffff);
                                                                local_4 = (uint)local_4._1_3_ << 8;
                                                                FUN_00406250();
                                                                goto LAB_004c6f33;
                                                              }
                                                              pcVar13 = 
                                                  s_flatmaxelementcount_009b0b0c;
                                                  uVar5 = FUN_00405d30(0);
                                                  cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                  if (cVar2 == '\0') {
                                                    pcVar13 = s_flatrenderrate_009b0b20;
                                                    uVar5 = FUN_00405d30(0);
                                                    cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                    if (cVar2 == '\0') {
                                                      pcVar13 = s_flatcolor_009b0b30;
                                                      uVar5 = FUN_00405d30(0);
                                                      cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                      if (cVar2 == '\0') {
                                                        pcVar13 = s_flatscale_009b0b3c;
                                                        uVar5 = FUN_00405d30(0);
                                                        cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                        if (cVar2 == '\0') {
                                                          pcVar13 = s_light_009b0b48;
                                                          uVar5 = FUN_00405d30(0);
                                                          cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                          if (cVar2 == '\0') {
                                                            pcVar13 = s_dirlight_009b0b50;
                                                            uVar5 = FUN_00405d30(0);
                                                            cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                            if (cVar2 == '\0') {
                                                              pcVar13 = s_light_enable_009b0b5c;
                                                              uVar5 = FUN_00405d30(0);
                                                              cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                              if (cVar2 == '\0') {
                                                                pcVar13 = s_bloom_enable_009b0b6c;
                                                                uVar5 = FUN_00405d30(0);
                                                                cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                                if (cVar2 == '\0') {
                                                                  pcVar13 = s_bloom_009b0b7c;
                                                                  uVar5 = FUN_00405d30(0);
                                                                  cVar2 = FUN_004036a0(uVar5,pcVar13
                                                                                      );
                                                                  if (cVar2 == '\0') {
                                                                    pcVar13 = s_fog_enable_009b0b84;
                                                                    uVar5 = FUN_00405d30(0);
                                                                    cVar2 = FUN_004036a0(uVar5,
                                                  pcVar13);
                                                  if (cVar2 == '\0') {
                                                    puVar12 = &DAT_009b0b90;
                                                    uVar5 = FUN_00405d30(0);
                                                    cVar2 = FUN_004036a0(uVar5,puVar12);
                                                    if ((cVar2 != '\0') &&
                                                       (uVar4 = FUN_00405820(), 6 < uVar4)) {
                                                      uVar5 = FUN_00405d30(1);
                                                      fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                      pfVar8 = local_fc;
                                                      local_fc[0x11] = (float)fVar11;
                                                      uVar5 = FUN_00405d30(2);
                                                      fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                      pfVar8[0x12] = (float)fVar11;
                                                      uVar5 = FUN_00405d30(3);
                                                      fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                      pfVar8[0x13] = (float)fVar11;
                                                      uVar5 = FUN_00405d30(4);
                                                      fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                      fStack_dc = (float)(fVar11 * (float10)
                                                  DAT_0099d0b0);
                                                  uVar5 = FUN_00405d30(5);
                                                  fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                  fStack_d8 = (float)(fVar11 * (float10)DAT_0099d0b0
                                                                     );
                                                  uVar5 = FUN_00405d30(6);
                                                  fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                  fStack_d4 = (float)(fVar11 * (float10)DAT_0099d0b0
                                                                     );
                                                  pfVar8[0x14] = fStack_dc;
                                                  pfVar8[0x15] = fStack_d8;
                                                  pfVar8[0x16] = fStack_d4;
                                                  local_4 = (uint)local_4._1_3_ << 8;
                                                  FUN_00406250();
                                                  goto LAB_004c6f33;
                                                  }
                                                  pcVar13 = s_light_fadetime_009b0b94;
                                                  uVar5 = FUN_00405d30(0);
                                                  cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                  if (cVar2 == '\0') {
                                                    pcVar13 = s_light_range_009b0ba4;
                                                    uVar5 = FUN_00405d30(0);
                                                    cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                    if (cVar2 == '\0') {
                                                      pcVar13 = s_light_faderange_009b0bb0;
                                                      uVar5 = FUN_00405d30(0);
                                                      cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                      if (cVar2 == '\0') {
                                                        pcVar13 = s_tailstep_009b0bc0;
                                                        uVar5 = FUN_00405d30(0);
                                                        cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                        if (cVar2 == '\0') {
                                                          pcVar13 = s_animlength_009b0bcc;
                                                          uVar5 = FUN_00405d30(0);
                                                          cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                          if (cVar2 == '\0') {
                                                            pcVar13 = s_loopcount_009b0bd8;
                                                            uVar5 = FUN_00405d30(0);
                                                            cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                            if (cVar2 == '\0') {
                                                              pcVar13 = s_animation_009b0be4;
                                                              uVar5 = FUN_00405d30(0);
                                                              cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                              if (cVar2 == '\0') {
                                                                puVar12 = &DAT_009b0bf0;
                                                                uVar5 = FUN_00405d30(0);
                                                                cVar2 = FUN_004036a0(uVar5,puVar12);
                                                                if (cVar2 == '\0') {
                                                                  pcVar13 = s_skeleton_009b0bf8;
                                                                  uVar5 = FUN_00405d30(0);
                                                                  cVar2 = FUN_004036a0(uVar5,pcVar13
                                                                                      );
                                                                  if (cVar2 == '\0') {
                                                                    pcVar13 = s_twoside_009b0c04;
                                                                    uVar5 = FUN_00405d30(0);
                                                                    cVar2 = FUN_004036a0(uVar5,
                                                  pcVar13);
                                                  if (cVar2 == '\0') {
                                                    pcVar13 = s_mesh_status_009b0c0c;
                                                    uVar5 = FUN_00405d30(0);
                                                    cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                    if (cVar2 != '\0') {
                                                      uVar5 = FUN_00405d30(1);
                                                      uVar3 = thunk_FUN_00796f50(uVar5);
                                                      iVar6 = iStack_108;
                                                      *(undefined1 *)(iStack_108 + 0x1c) = uVar3;
                                                      uVar5 = FUN_00405d30(2);
                                                      fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                      local_118 = (float)(fVar11 * (float10)
                                                  _DAT_00ae7884);
                                                  uVar5 = FUN_0040d600(local_5c,local_118);
                                                  FUN_0040fa30(iVar6,uVar5);
                                                  uVar5 = FUN_00405d30(3);
                                                  fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                  *(float *)(iVar6 + 0x18) = (float)fVar11;
                                                  uVar5 = FUN_00405d30(4);
                                                  FUN_00401660(uVar5,0,0xffffffff);
                                                  local_4 = (uint)local_4._1_3_ << 8;
                                                  FUN_00406250();
                                                  goto LAB_004c6f33;
                                                  }
                                                  pcVar13 = s_mesh_color_009b0c18;
                                                  uVar5 = FUN_00405d30(0);
                                                  cVar2 = FUN_004036a0(uVar5,pcVar13);
                                                  if (cVar2 != '\0') {
                                                    uVar5 = FUN_00405d30(1);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    fStack_d0 = (float)(fVar11 * (float10)
                                                  DAT_0099d0b0);
                                                  uVar5 = FUN_00405d30(2);
                                                  fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                  fStack_cc = (float)(fVar11 * (float10)DAT_0099d0b0
                                                                     );
                                                  uVar5 = FUN_00405d30(3);
                                                  fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                  iVar6 = iStack_108;
                                                  fStack_c8 = (float)(fVar11 * (float10)DAT_0099d0b0
                                                                     );
                                                  *(float *)(iStack_108 + 8) = fStack_d0;
                                                  *(float *)(iStack_108 + 0xc) = fStack_cc;
                                                  *(float *)(iStack_108 + 0x10) = fStack_c8;
                                                  uVar5 = FUN_00405d30(4);
                                                  fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                  *(float *)(iVar6 + 0x14) = (float)fVar11;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar3 = thunk_FUN_00796fe0(uVar5);
                                                    *(undefined1 *)(local_f8 + 0x17) = uVar3;
                                                  }
                                                  goto LAB_004c6ee6;
                                                  }
                                                  uVar5 = FUN_00405d30(1);
                                                  FUN_00401660(uVar5,0,0xffffffff);
                                                  local_4 = (uint)local_4._1_3_ << 8;
                                                  FUN_00406250();
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    FUN_00401660(uVar5,0,0xffffffff);
                                                    local_4 = (uint)local_4._1_3_ << 8;
                                                    FUN_00406250();
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    FUN_00401660(uVar5,0,0xffffffff);
                                                    local_4 = (uint)local_4._1_3_ << 8;
                                                    FUN_00406250();
                                                  }
                                                  goto LAB_004c6f33;
                                                  }
                                                  uVar5 = FUN_00405d30(1);
                                                  uVar5 = thunk_FUN_00796fb0(uVar5);
                                                  *local_f8 = uVar5;
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar5 = thunk_FUN_00796fb0(uVar5);
                                                    local_f8[1] = uVar5;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar5 = thunk_FUN_00796fb0(uVar5);
                                                    puVar1 = puStack_100;
                                                    *puStack_100 = uVar5;
                                                    uVar4 = FUN_00405820();
                                                    if (5 < uVar4) {
                                                      uVar5 = FUN_00405d30(2);
                                                      uVar5 = thunk_FUN_00796fb0(uVar5);
                                                      puVar1[1] = uVar5;
                                                      uVar5 = FUN_00405d30(3);
                                                      fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                      puVar1[2] = (float)fVar11;
                                                      uVar5 = FUN_00405d30(4);
                                                      uVar5 = thunk_FUN_00796fb0(uVar5);
                                                      puVar1[3] = uVar5;
                                                      uVar5 = FUN_00405d30(5);
                                                      uVar3 = thunk_FUN_00796fe0(uVar5);
                                                      *(undefined1 *)(puVar1 + 4) = uVar3;
                                                    }
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    local_fc[1] = (float)fVar11;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    *local_fc = (float)fVar11;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    fVar7 = (float)thunk_FUN_00796fb0(uVar5);
                                                    local_fc[2] = fVar7;
                                                    if (fVar7 == 0.0) {
                                                      local_fc[2] = 1.4013e-42;
                                                      local_4 = (uint)local_4._1_3_ << 8;
                                                      FUN_00406250();
                                                      goto LAB_004c6f33;
                                                    }
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar3 = thunk_FUN_00796fe0(uVar5);
                                                    *(undefined1 *)(local_fc + 0x10) = uVar3;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    pfVar8 = local_fc;
                                                    local_fc[0xe] =
                                                         (float)(fVar11 * (float10)DAT_009a09bc);
                                                    uVar5 = FUN_00405d30(2);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    pfVar8[0xf] = (float)(fVar11 * (float10)
                                                  DAT_009a09bc);
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar3 = thunk_FUN_00796fe0(uVar5);
                                                    *(undefined1 *)(local_fc + 0xd) = uVar3;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar3 = thunk_FUN_00796fe0(uVar5);
                                                    *(undefined1 *)(local_fc + 3) = uVar3;
                                                  }
                                                  goto LAB_004c6ee6;
                                                  }
                                                  uVar5 = FUN_00405d30(1);
                                                  fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                  pfVar8 = local_fc;
                                                  local_fc[6] = (float)fVar11;
                                                  uVar5 = FUN_00405d30(2);
                                                  fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                  fStack_90 = (float)(fVar11 * (float10)DAT_0099d0b0
                                                                     );
                                                  uVar5 = FUN_00405d30(3);
                                                  fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                  fStack_8c = (float)(fVar11 * (float10)DAT_0099d0b0
                                                                     );
                                                  uVar5 = FUN_00405d30(4);
                                                  fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                  fStack_88 = (float)(fVar11 * (float10)DAT_0099d0b0
                                                                     );
                                                  pfVar8[10] = fStack_90;
                                                  pfVar8[0xb] = fStack_8c;
                                                  pfVar8[0xc] = fStack_88;
                                                  local_4 = (uint)local_4._1_3_ << 8;
                                                  FUN_00406250();
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    pfVar8 = local_fc;
                                                    local_fc[5] = (float)fVar11;
                                                    uVar5 = FUN_00405d30(2);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    pfVar8[4] = (float)fVar11;
                                                    uVar5 = FUN_00405d30(3);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    fStack_e8 = (float)(fVar11 * (float10)
                                                  DAT_0099d0b0);
                                                  uVar5 = FUN_00405d30(4);
                                                  fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                  fStack_e4 = (float)(fVar11 * (float10)DAT_0099d0b0
                                                                     );
                                                  uVar5 = FUN_00405d30(5);
                                                  fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                  fStack_e0 = (float)(fVar11 * (float10)DAT_0099d0b0
                                                                     );
                                                  pfVar8[7] = fStack_e8;
                                                  pfVar8[8] = fStack_e4;
                                                  pfVar8[9] = fStack_e0;
                                                  local_4 = (uint)local_4._1_3_ << 8;
                                                  FUN_00406250();
                                                  }
                                                  goto LAB_004c6f33;
                                                  }
                                                  uVar5 = FUN_00405d30(2);
                                                  fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                  local_118 = (float)fVar11;
                                                  uVar5 = FUN_00405d30(1);
                                                  fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                  fStack_b8 = (float)fVar11;
                                                  puVar9[0x1e] = fStack_b8;
                                                  fStack_b4 = local_118;
                                                  puVar9[0x1f] = local_118;
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    fStack_ac = (float)(fVar11 * (float10)
                                                  DAT_0099d0b0);
                                                  uVar5 = FUN_00405d30(2);
                                                  fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                  fStack_a8 = (float)(fVar11 * (float10)DAT_0099d0b0
                                                                     );
                                                  uVar5 = FUN_00405d30(3);
                                                  fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                  fStack_a4 = (float)(fVar11 * (float10)DAT_0099d0b0
                                                                     );
                                                  uVar5 = FUN_00405d30(4);
                                                  fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                  fStack_a0 = (float)(fVar11 * (float10)DAT_0099d0b0
                                                                     );
                                                  puVar9[0x1a] = fStack_ac;
                                                  puVar9[0x1b] = fStack_a8;
                                                  puVar9[0x1c] = fStack_a4;
                                                  puVar9[0x1d] = fStack_a0;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    puVar9[0x20] = (float)fVar11;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar5 = thunk_FUN_00796fb0(uVar5);
                                                    puVar9[0x19] = uVar5;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    puVar9[0xd] = (float)fVar11;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    fStack_84 = (float)fVar11;
                                                    uVar5 = FUN_00405d30(2);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    fStack_80 = (float)fVar11;
                                                    uVar5 = FUN_00405d30(3);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    fStack_7c = (float)fVar11;
                                                    puVar9[0x13] = fStack_84;
                                                    puVar9[0x14] = fStack_80;
                                                    puVar9[0x15] = fStack_7c;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    puVar9[0xc] = (float)fVar11;
                                                    uVar5 = FUN_00405d30(2);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    puVar9[0xb] = (float)fVar11;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    uVar3 = thunk_FUN_00796fe0(uVar5);
                                                    *(undefined1 *)((int)puVar9 + 10) = uVar3;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    fStack_c4 = (float)fVar11;
                                                    uVar5 = FUN_00405d30(2);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    fStack_c0 = (float)fVar11;
                                                    uVar5 = FUN_00405d30(3);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    fStack_bc = (float)fVar11;
                                                    puVar9[0x10] = fStack_c4;
                                                    puVar9[0x11] = fStack_c0;
                                                    puVar9[0x12] = fStack_bc;
                                                  }
                                                  }
                                                  else {
                                                    uVar5 = FUN_00405d30(1);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    fStack_9c = (float)fVar11;
                                                    uVar5 = FUN_00405d30(2);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    fStack_98 = (float)fVar11;
                                                    uVar5 = FUN_00405d30(3);
                                                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                    fStack_94 = (float)fVar11;
                                                    puVar9[0x16] = fStack_9c;
                                                    puVar9[0x17] = fStack_98;
                                                    puVar9[0x18] = fStack_94;
                                                  }
                                                }
                                                else {
                                                  uVar5 = FUN_00405d30(1);
                                                  fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                  puVar9[7] = (float)((float10)_DAT_00ae7884 *
                                                                     fVar11);
                                                }
                                              }
                                              else {
                                                uVar5 = FUN_00405d30(1);
                                                fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                                puVar9[8] = (float)fVar11;
                                              }
                                            }
                                            else {
                                              uVar5 = FUN_00405d30(1);
                                              fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                              puVar9[10] = (float)fVar11;
                                              uVar5 = FUN_00405d30(2);
                                              fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                              puVar9[9] = (float)fVar11;
                                            }
                                          }
                                          else {
                                            uVar5 = FUN_00405d30(1);
                                            uVar5 = thunk_FUN_00796fb0(uVar5);
                                            puVar9[6] = uVar5;
                                          }
                                        }
                                        else {
                                          uVar5 = FUN_00405d30(1);
                                          fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                          puVar9[0xf] = (float)fVar11;
                                          uVar5 = FUN_00405d30(2);
                                          fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                                          puVar9[0xe] = (float)fVar11;
                                        }
                                      }
                                      else {
                                        uVar5 = FUN_00405d30(1);
                                        uVar5 = thunk_FUN_00796e60(uVar5);
                                        puVar9[5] = uVar5;
                                      }
                                      goto LAB_004c6ee6;
                                    }
                                    puVar12 = &DAT_009b0a58;
                                    uVar5 = FUN_00405d30(1);
                                    cVar2 = FUN_004036a0(uVar5,puVar12);
                                    *(bool *)(puVar9 + 2) = cVar2 != '\0';
                                    local_4 = (uint)local_4._1_3_ << 8;
                                    FUN_00406250();
                                  }
                                  else {
                                    puVar12 = &DAT_009b0a40;
                                    uVar5 = FUN_00405d30(1);
                                    cVar2 = FUN_004036a0(uVar5,puVar12);
                                    *(bool *)((int)puVar9 + 9) = cVar2 != '\0';
                                    local_4 = (uint)local_4._1_3_ << 8;
                                    FUN_00406250();
                                  }
                                }
                                else {
                                  pcVar13 = s_explode_009b09c8;
                                  uVar5 = FUN_00405d30(1);
                                  cVar2 = FUN_004036a0(uVar5,pcVar13);
                                  if (cVar2 == '\0') {
                                    pcVar13 = s_direct_009b09d0;
                                    uVar5 = FUN_00405d30(1);
                                    cVar2 = FUN_004036a0(uVar5,pcVar13);
                                    if (cVar2 == '\0') {
                                      pcVar13 = s_gather_009b09d8;
                                      uVar5 = FUN_00405d30(1);
                                      cVar2 = FUN_004036a0(uVar5,pcVar13);
                                      if (cVar2 == '\0') {
                                        pcVar13 = s_plane_009b09e0;
                                        uVar5 = FUN_00405d30(1);
                                        cVar2 = FUN_004036a0(uVar5,pcVar13);
                                        if (cVar2 == '\0') {
                                          pcVar13 = s_directplane_009b09e8;
                                          uVar5 = FUN_00405d30(1);
                                          cVar2 = FUN_004036a0(uVar5,pcVar13);
                                          if (cVar2 == '\0') {
                                            pcVar13 = s_explodeplane_009b09f4;
                                            uVar5 = FUN_00405d30(1);
                                            cVar2 = FUN_004036a0(uVar5,pcVar13);
                                            if (cVar2 == '\0') {
                                              pcVar13 = s_exploderange_009b0a04;
                                              uVar5 = FUN_00405d30(1);
                                              cVar2 = FUN_004036a0(uVar5,pcVar13);
                                              if (cVar2 == '\0') {
                                                puVar12 = &DAT_009b0a14;
                                                uVar5 = FUN_00405d30(1);
                                                cVar2 = FUN_004036a0(uVar5,puVar12);
                                                if (cVar2 == '\0') {
                                                  puVar12 = &DAT_009b0a1c;
                                                  uVar5 = FUN_00405d30(1);
                                                  cVar2 = FUN_004036a0(uVar5,puVar12);
                                                  local_4 = (uint)local_4._1_3_ << 8;
                                                  puVar9[1] = -(uint)(cVar2 != '\0') & 9;
                                                  FUN_00406250();
                                                }
                                                else {
                                                  puVar9[1] = 8;
                                                  local_4 = (uint)local_4._1_3_ << 8;
                                                  FUN_00406250();
                                                }
                                              }
                                              else {
                                                puVar9[1] = 7;
                                                local_4 = (uint)local_4._1_3_ << 8;
                                                FUN_00406250();
                                              }
                                            }
                                            else {
                                              puVar9[1] = 6;
                                              local_4 = (uint)local_4._1_3_ << 8;
                                              FUN_00406250();
                                            }
                                          }
                                          else {
                                            puVar9[1] = 5;
                                            local_4 = (uint)local_4._1_3_ << 8;
                                            FUN_00406250();
                                          }
                                        }
                                        else {
                                          puVar9[1] = 4;
                                          local_4 = (uint)local_4._1_3_ << 8;
                                          FUN_00406250();
                                        }
                                      }
                                      else {
                                        puVar9[1] = 3;
                                        local_4 = (uint)local_4._1_3_ << 8;
                                        FUN_00406250();
                                      }
                                    }
                                    else {
                                      puVar9[1] = 1;
                                      local_4 = (uint)local_4._1_3_ << 8;
                                      FUN_00406250();
                                    }
                                  }
                                  else {
                                    puVar9[1] = 2;
                                    local_4 = (uint)local_4._1_3_ << 8;
                                    FUN_00406250();
                                  }
                                }
                              }
                              else {
                                pcVar13 = s_sprite_009b09ac;
                                uVar5 = FUN_00405d30(1);
                                cVar2 = FUN_004036a0(uVar5,pcVar13);
                                if (cVar2 == '\0') {
                                  puVar12 = &DAT_009b09b4;
                                  uVar5 = FUN_00405d30(1);
                                  cVar2 = FUN_004036a0(uVar5,puVar12);
                                  if (cVar2 == '\0') goto LAB_004c6ee6;
                                  *puVar9 = 1;
                                  local_4 = (uint)local_4._1_3_ << 8;
                                  FUN_00406250();
                                }
                                else {
                                  *puVar9 = 0;
                                  local_4 = (uint)local_4._1_3_ << 8;
                                  FUN_00406250();
                                }
                              }
                            }
                            else {
                              uVar5 = FUN_00405d30(1);
                              FUN_00401660(uVar5,0,0xffffffff);
                              local_4 = (uint)local_4._1_3_ << 8;
                              FUN_00406250();
                            }
                          }
                          else {
                            uVar5 = FUN_00405d30(1);
                            FUN_00401660(uVar5,0,0xffffffff);
                            local_4 = (uint)local_4._1_3_ << 8;
                            FUN_00406250();
                          }
                        }
                        else {
                          pcVar13 = s_modulate_009b0960;
                          uVar5 = FUN_00405d30(1);
                          cVar2 = FUN_004036a0(uVar5,pcVar13);
                          if (cVar2 == '\0') {
                            puVar12 = &DAT_009b096c;
                            uVar5 = FUN_00405d30(1);
                            cVar2 = FUN_004036a0(uVar5,puVar12);
                            if (cVar2 == '\0') goto LAB_004c6ee6;
                            local_f4[1] = 0;
                            local_4 = (uint)local_4._1_3_ << 8;
                            FUN_00406250();
                          }
                          else {
                            local_f4[1] = 1;
                            local_4 = (uint)local_4._1_3_ << 8;
                            FUN_00406250();
                          }
                        }
                      }
                      else {
                        pcVar13 = s_increase_009b0934;
                        uVar5 = FUN_00405d30(1);
                        cVar2 = FUN_004036a0(uVar5,pcVar13);
                        if (cVar2 == '\0') {
                          pcVar13 = s_decrease_009b0940;
                          uVar5 = FUN_00405d30(1);
                          cVar2 = FUN_004036a0(uVar5,pcVar13);
                          if (cVar2 == '\0') {
                            pcVar13 = s_cycle_009b094c;
                            uVar5 = FUN_00405d30(1);
                            cVar2 = FUN_004036a0(uVar5,pcVar13);
                            if (cVar2 == '\0') goto LAB_004c6ee6;
                            *local_f4 = 2;
                            local_4 = (uint)local_4._1_3_ << 8;
                            FUN_00406250();
                          }
                          else {
                            *local_f4 = 1;
                            local_4 = (uint)local_4._1_3_ << 8;
                            FUN_00406250();
                          }
                        }
                        else {
                          *local_f4 = 0;
                          local_4 = (uint)local_4._1_3_ << 8;
                          FUN_00406250();
                        }
                      }
                      goto LAB_004c6f33;
                    }
                    uVar5 = FUN_00405d30(1);
                    uVar5 = thunk_FUN_00796fb0(uVar5);
                    puVar1 = puStack_104;
                    *puStack_104 = uVar5;
                    uVar5 = FUN_00405d30(2);
                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                    puVar1[1] = (float)fVar11;
                    uVar5 = FUN_00405d30(3);
                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                    puVar1[2] = (float)fVar11;
                  }
                  else {
                    uVar5 = FUN_00405d30(1);
                    iVar6 = local_ec;
                    FUN_00401660(uVar5,0,0xffffffff);
                    uVar5 = FUN_00405d30(2);
                    uVar5 = thunk_FUN_00796fb0(uVar5);
                    *(undefined4 *)(iVar6 + 0x1c) = uVar5;
                    uVar5 = FUN_00405d30(3);
                    uVar5 = thunk_FUN_00796fb0(uVar5);
                    *(undefined4 *)(iVar6 + 0x20) = uVar5;
                    uVar5 = FUN_00405d30(4);
                    fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                    *(float *)(iVar6 + 0x24) = (float)fVar11;
                    uVar5 = FUN_00405d30(5);
                    uVar5 = thunk_FUN_00796fb0(uVar5);
                    *(undefined4 *)(iVar6 + 0x28) = uVar5;
                    uVar4 = FUN_00405820();
                    if (7 < uVar4) {
                      uVar5 = FUN_00405d30(6);
                      uVar3 = thunk_FUN_00796fe0(uVar5);
                      *(undefined1 *)(iVar6 + 0x2c) = uVar3;
                    }
                  }
                }
                else {
                  uVar5 = FUN_00405d30(1);
                  fVar11 = (float10)thunk_FUN_00796ec0(uVar5);
                  local_114[2] = (float)fVar11;
                }
LAB_004c6ee6:
                local_4 = (uint)local_4._1_3_ << 8;
                FUN_00406250();
              }
              else {
                pcVar13 = s_camera_009b08f0;
                uVar5 = FUN_00405d30(1);
                cVar2 = FUN_004036a0(uVar5,pcVar13);
                if (cVar2 == '\0') {
                  pcVar13 = s_carpet_009b08f8;
                  uVar5 = FUN_00405d30(1);
                  cVar2 = FUN_004036a0(uVar5,pcVar13);
                  if (cVar2 == '\0') {
                    pcVar13 = s_yaxis_009b0900;
                    uVar5 = FUN_00405d30(1);
                    cVar2 = FUN_004036a0(uVar5,pcVar13);
                    if (cVar2 == '\0') {
                      pcVar13 = s_stand_009b0908;
                      uVar5 = FUN_00405d30(1);
                      cVar2 = FUN_004036a0(uVar5,pcVar13);
                      if (cVar2 == '\0') goto LAB_004c6ee6;
                      local_114[1] = 1.4013e-45;
                      local_4 = (uint)local_4._1_3_ << 8;
                      FUN_00406250();
                    }
                    else {
                      local_114[1] = 0.0;
                      local_4 = (uint)local_4._1_3_ << 8;
                      FUN_00406250();
                    }
                  }
                  else {
                    local_114[1] = 2.8026e-45;
                    local_4 = (uint)local_4._1_3_ << 8;
                    FUN_00406250();
                  }
                }
                else {
                  local_114[1] = 4.2039e-45;
                  local_4 = (uint)local_4._1_3_ << 8;
                  FUN_00406250();
                }
              }
            }
            else {
              pcVar13 = s_sprite_009b0884;
              uVar5 = FUN_00405d30(1);
              cVar2 = FUN_004036a0(uVar5,pcVar13);
              if (cVar2 == '\0') {
                pcVar13 = s_particle_009b088c;
                uVar5 = FUN_00405d30(1);
                cVar2 = FUN_004036a0(uVar5,pcVar13);
                if (cVar2 == '\0') {
                  pcVar13 = s_decal_009b0898;
                  uVar5 = FUN_00405d30(1);
                  cVar2 = FUN_004036a0(uVar5,pcVar13);
                  if (cVar2 == '\0') {
                    pcVar13 = s_light_009b08a0;
                    uVar5 = FUN_00405d30(1);
                    cVar2 = FUN_004036a0(uVar5,pcVar13);
                    if (cVar2 == '\0') {
                      puVar12 = &DAT_009b08a8;
                      uVar5 = FUN_00405d30(1);
                      cVar2 = FUN_004036a0(uVar5,puVar12);
                      if (cVar2 == '\0') {
                        pcVar13 = s_sound_009b08b0;
                        uVar5 = FUN_00405d30(1);
                        cVar2 = FUN_004036a0(uVar5,pcVar13);
                        if (cVar2 == '\0') {
                          pcVar13 = s_quake_009b08b8;
                          uVar5 = FUN_00405d30(1);
                          cVar2 = FUN_004036a0(uVar5,pcVar13);
                          if (cVar2 == '\0') {
                            pcVar13 = s_shockwave_009b08c0;
                            uVar5 = FUN_00405d30(1);
                            cVar2 = FUN_004036a0(uVar5,pcVar13);
                            if (cVar2 == '\0') {
                              pcVar13 = s_weather_009b08cc;
                              uVar5 = FUN_00405d30(1);
                              cVar2 = FUN_004036a0(uVar5,pcVar13);
                              if (cVar2 == '\0') {
                                pcVar13 = s_meshstatus_009b08d4;
                                uVar5 = FUN_00405d30(1);
                                cVar2 = FUN_004036a0(uVar5,pcVar13);
                                if (cVar2 != '\0') {
                                  local_114[0] = 1.54143e-44;
                                }
                              }
                              else {
                                local_114[0] = 1.12104e-44;
                              }
                            }
                            else {
                              local_114[0] = 1.26117e-44;
                            }
                          }
                          else {
                            local_114[0] = 7.00649e-45;
                          }
                        }
                        else {
                          local_114[0] = 8.40779e-45;
                        }
                      }
                      else {
                        local_114[0] = 4.2039e-45;
                      }
                    }
                    else {
                      local_114[0] = 5.60519e-45;
                    }
                  }
                  else {
                    local_114[0] = 2.8026e-45;
                  }
                }
                else {
                  local_114[0] = 9.80909e-45;
                }
              }
              else {
                local_114[0] = 1.4013e-45;
              }
              FUN_004c52d0(local_114);
              puVar9 = local_f0;
              local_4 = (uint)local_4._1_3_ << 8;
              FUN_00406250();
            }
          }
          else {
            uVar5 = FUN_00405d30(1);
            FUN_00401660(uVar5,0,0xffffffff);
            local_4 = (uint)local_4._1_3_ << 8;
            FUN_00406250();
          }
        }
        else {
          local_4 = (uint)local_4._1_3_ << 8;
          FUN_00406250();
        }
      }
LAB_004c6f33:
      *param_2 = *param_2 + 1;
      uVar4 = FUN_00411430();
    } while (*param_2 < uVar4);
  }
  if (local_60 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_74);
  return;
}


// ==== FUN_004c7030 @ 0x004c7030 ====

/* WARNING: Removing unreachable block (ram,0x004c727b) */
/* WARNING: Removing unreachable block (ram,0x004c7280) */
/* WARNING: Removing unreachable block (ram,0x004c736a) */
/* WARNING: Removing unreachable block (ram,0x004c7370) */

void FUN_004c7030(void)

{
  int *piVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *in_ECX;
  int *piVar6;
  int *local_14;
  int *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980a94;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009b0c2c;
  local_10 = (int *)in_ECX[0x11];
  piVar6 = (int *)*local_10;
  local_4 = 1;
  if (piVar6 != local_10) {
    do {
      local_14 = (int *)piVar6[5];
      piVar1 = (int *)*local_14;
      if (piVar1 != local_14) {
        pvVar2 = (void *)piVar1[0xc];
        if (pvVar2 == (void *)0x0) {
          piVar1[0xc] = 0;
          _free((void *)piVar1[0xd]);
          return;
        }
        if (*(uint *)((int)pvVar2 + 0x38) < 0x10) {
          *(undefined4 *)((int)pvVar2 + 0x38) = 0xf;
          *(undefined4 *)((int)pvVar2 + 0x34) = 0;
          *(undefined1 *)((int)pvVar2 + 0x24) = 0;
          _free(pvVar2);
          return;
        }
        _free(*(void **)((int)pvVar2 + 0x24));
        return;
      }
      puVar3 = (undefined4 *)piVar6[5];
      pvVar2 = (void *)*puVar3;
      *puVar3 = puVar3;
      *(int *)(piVar6[5] + 4) = piVar6[5];
      piVar6[6] = 0;
      if (pvVar2 != (void *)piVar6[5]) {
        if (*(uint *)((int)pvVar2 + 0x20) < 0x10) {
          *(undefined4 *)((int)pvVar2 + 0x20) = 0xf;
          *(undefined4 *)((int)pvVar2 + 0x1c) = 0;
          *(undefined1 *)((int)pvVar2 + 0xc) = 0;
          _free(pvVar2);
          return;
        }
        _free(*(void **)((int)pvVar2 + 0xc));
        return;
      }
      local_14 = (int *)piVar6[5];
      if (piVar6[8] != piVar6[9]) {
        piVar6[9] = piVar6[8];
      }
      FUN_004c7a80(piVar6[8],9,&local_14);
      piVar6[0xb] = 1;
      piVar6[0xc] = 1;
      piVar6 = (int *)*piVar6;
    } while (piVar6 != local_10);
  }
  piVar6 = (int *)in_ECX[0x11];
  puVar3 = (undefined4 *)*piVar6;
  *piVar6 = (int)piVar6;
  *(undefined4 *)(in_ECX[0x11] + 4) = in_ECX[0x11];
  in_ECX[0x12] = 0;
  if (puVar3 != (undefined4 *)in_ECX[0x11]) {
    local_10 = (int *)*puVar3;
    if ((void *)puVar3[8] != (void *)0x0) {
      _free((void *)puVar3[8]);
      return;
    }
    puVar3[8] = 0;
    puVar3[9] = 0;
    puVar3[10] = 0;
    piVar6 = (int *)puVar3[5];
    iVar4 = *piVar6;
    *piVar6 = (int)piVar6;
    *(undefined4 *)(puVar3[5] + 4) = puVar3[5];
    puVar3[6] = 0;
    if (iVar4 != puVar3[5]) {
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    _free((void *)puVar3[5]);
    return;
  }
  local_10 = (int *)in_ECX[0x11];
  if (in_ECX[0x14] != in_ECX[0x15]) {
    in_ECX[0x15] = in_ECX[0x14];
  }
  FUN_004c7a80(in_ECX[0x14],9,&local_10);
  in_ECX[0x17] = 1;
  in_ECX[0x18] = 1;
  if ((void *)in_ECX[0x14] != (void *)0x0) {
    _free((void *)in_ECX[0x14]);
    return;
  }
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  piVar6 = (int *)in_ECX[0x11];
  puVar3 = (undefined4 *)*piVar6;
  *piVar6 = (int)piVar6;
  *(undefined4 *)(in_ECX[0x11] + 4) = in_ECX[0x11];
  in_ECX[0x12] = 0;
  if (puVar3 == (undefined4 *)in_ECX[0x11]) {
    _free((void *)in_ECX[0x11]);
    return;
  }
  local_10 = (int *)*puVar3;
  if ((void *)puVar3[8] != (void *)0x0) {
    _free((void *)puVar3[8]);
    return;
  }
  puVar3[8] = 0;
  puVar3[9] = 0;
  puVar3[10] = 0;
  puVar5 = (undefined4 *)puVar3[5];
  pvVar2 = (void *)*puVar5;
  *puVar5 = puVar5;
  *(undefined4 *)(puVar3[5] + 4) = puVar3[5];
  puVar3[6] = 0;
  if (pvVar2 == (void *)puVar3[5]) {
    _free((void *)puVar3[5]);
    return;
  }
  FUN_004c7a70(pvVar2);
  _free(pvVar2);
  return;
}


// ==== FUN_004c7480 @ 0x004c7480 ====

void FUN_004c7480(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980ab1;
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
  *in_ECX = &PTR_FUN_009b0c2c;
  FUN_004c8780(&param_1,&param_1);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004c7510 @ 0x004c7510 ====

/* WARNING: Removing unreachable block (ram,0x004c786d) */

uint FUN_004c7510(int *param_1)

{
  undefined4 *_Memory;
  uint3 uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint extraout_EAX;
  undefined4 uVar6;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  uint extraout_EAX_03;
  int in_ECX;
  uint uVar7;
  char *pcVar8;
  undefined1 uStack_c1;
  uint uStack_c0;
  undefined1 auStack_bc [4];
  int iStack_b8;
  int iStack_b4;
  undefined4 uStack_b0;
  int local_ac;
  undefined4 uStack_a8;
  int iStack_a4;
  undefined1 auStack_a0 [4];
  undefined4 *puStack_9c;
  undefined4 uStack_98;
  void *pvStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined1 auStack_78 [4];
  void *pvStack_74;
  undefined4 uStack_64;
  uint uStack_60;
  undefined1 auStack_5c [8];
  undefined1 auStack_54 [28];
  undefined2 auStack_38 [22];
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_00980ae9;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_ac = in_ECX;
  uVar3 = (**(code **)(*param_1 + 4))();
  if (uVar3 != 9) {
    ExceptionList = pvStack_c;
    return uVar3 & 0xffffff00;
  }
  FUN_004c8060(&uStack_c1,&uStack_c1);
  iStack_4 = 0;
  uStack_c0 = 0;
  iVar4 = FUN_00411430();
  if (iVar4 != 0) {
    do {
      iVar4 = FUN_00411510(uStack_c0);
      if (*(int *)(iVar4 + 0x14) != 0) {
        iVar5 = FUN_00405b90(auStack_78,0,1);
        iStack_4._0_1_ = 1;
        iVar5 = FUN_00403620(0,*(undefined4 *)(iVar5 + 0x14),&DAT_009b07fc,1);
        uVar1 = iStack_4._1_3_;
        uStack_c1 = iVar5 == 0;
        iStack_4 = (uint)iStack_4._1_3_ << 8;
        if (0xf < uStack_60) {
          _free(pvStack_74);
          return extraout_EAX;
        }
        uStack_60 = 0xf;
        uStack_64 = 0;
        pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
        if (!(bool)uStack_c1) {
          iStack_b8 = 0;
          iStack_b4 = 0;
          uStack_b0 = 0;
          iStack_4._0_1_ = 2;
          iStack_4._1_3_ = uVar1;
          FUN_00405670(iVar4,auStack_bc);
          if ((iStack_b8 != 0) &&
             (iVar4 = iStack_b4 - iStack_b8 >> 0x1f, (iStack_b4 - iStack_b8) / 0x1c + iVar4 != iVar4
             )) {
            iVar4 = FUN_00403620(0,*(undefined4 *)(iStack_b8 + 0x14),s_<cate>_009b0800,6);
            if (iVar4 == 0) {
              uVar6 = FUN_00405d30(1);
              uStack_a8 = thunk_FUN_00796f80(uVar6);
              FUN_004c8030();
            }
            else {
              pcVar8 = s_<_cate>_009b0808;
              uVar6 = FUN_00405d30(0);
              cVar2 = FUN_004036a0(uVar6,pcVar8);
              if (cVar2 != '\0') {
                iVar4 = *(int *)(in_ECX + 0x44);
                FUN_004c4d40(&iStack_a4,&uStack_a8);
                if (iStack_a4 != iVar4) {
                  FUN_00401830(s_mapDescs_find__wCode______mapDes_009b0810);
                  iStack_4._0_1_ = 3;
                  FUN_00406880(auStack_54);
                  iStack_4 = CONCAT31(iStack_4._1_3_,2);
                    /* WARNING: Subroutine does not return */
                  FUN_00446f10();
                }
                auStack_38[0] = (undefined2)uStack_a8;
                FUN_004c8620(auStack_a0);
                iStack_4._0_1_ = 4;
                FUN_004c8860(auStack_5c,auStack_38);
                FUN_004c8120();
                iStack_4 = (uint)iStack_4._1_3_ << 8;
                FUN_00406250();
                in_ECX = local_ac;
                goto LAB_004c77a3;
              }
              pcVar8 = s_<effectdata>_009b083c;
              uVar6 = FUN_00405d30(0);
              cVar2 = FUN_004036a0(uVar6,pcVar8);
              if (cVar2 != '\0') {
                FUN_004c5590(param_1,&uStack_c0,auStack_a0);
              }
            }
          }
          iStack_4 = (uint)iStack_4._1_3_ << 8;
          FUN_00406250();
        }
      }
LAB_004c77a3:
      uVar7 = uStack_c0 + 1;
      uStack_c0 = uVar7;
      uVar3 = FUN_00411430();
    } while (uVar7 < uVar3);
  }
  uVar6 = (**(code **)(*param_1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar6;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 2;
  (**(code **)*param_1)(1);
  if (pvStack_90 != (void *)0x0) {
    _free(pvStack_90);
    return extraout_EAX_00;
  }
  pvStack_90 = (void *)0x0;
  uStack_8c = 0;
  uStack_88 = 0;
  _Memory = (undefined4 *)*puStack_9c;
  *puStack_9c = puStack_9c;
  puStack_9c[1] = puStack_9c;
  uStack_98 = 0;
  if (_Memory == puStack_9c) {
    _free(puStack_9c);
    return extraout_EAX_03;
  }
  if ((uint)_Memory[8] < 0x10) {
    _Memory[8] = 0xf;
    _Memory[7] = 0;
    *(undefined1 *)(_Memory + 3) = 0;
    _free(_Memory);
    return extraout_EAX_02;
  }
  _free((void *)_Memory[3]);
  return extraout_EAX_01;
}


// ==== FUN_004c7880 @ 0x004c7880 ====

void FUN_004c7880(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  if (param_2 != param_3) {
    puVar1 = *(undefined4 **)(in_ECX + 8);
    puVar2 = param_2;
    if (param_3 != puVar1) {
      do {
        *puVar2 = *param_3;
        param_3 = param_3 + 1;
        puVar2 = puVar2 + 1;
      } while (param_3 != puVar1);
    }
    *(undefined4 **)(in_ECX + 8) = puVar2;
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_004c78c0 @ 0x004c78c0 ====

void FUN_004c78c0(uint param_1)

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
  puStack_8 = &LAB_00980b08;
  local_c = ExceptionList;
  if (0x38e38e3U - *(int *)(in_ECX + 8) < param_1) {
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


// ==== FUN_004c7960 @ 0x004c7960 ====

void FUN_004c7960(uint param_1)

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
  puStack_8 = &LAB_00980b08;
  local_c = ExceptionList;
  if (0x5d1745dU - *(int *)(in_ECX + 8) < param_1) {
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


// ==== FUN_004c7a00 @ 0x004c7a00 ====

void FUN_004c7a00(void)

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
  puStack_8 = &LAB_00980b08;
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


// ==== FUN_004c7a70 @ 0x004c7a70 ====

void FUN_004c7a70(void)

{
  FUN_006c1c60();
  return;
}


// ==== FUN_004c7a80 @ 0x004c7a80 ====

void FUN_004c7a80(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00980b20;
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
      uVar7 = FUN_004c7a00();
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


// ==== Catch@004c7be9 @ 0x004c7be9 ====

void Catch_004c7be9(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_004c7cc0 @ 0x004c7cc0 ====

void FUN_004c7cc0(int *param_1,int *param_2)

{
  int in_ECX;
  
  if (param_2 == *(int **)(in_ECX + 4)) {
    *param_1 = *param_2;
    return;
  }
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  FUN_006c1c60();
  _free(param_2);
  return;
}


// ==== FUN_004c7d00 @ 0x004c7d00 ====

void FUN_004c7d00(void)

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
  FUN_006c1c60();
  _free(_Memory);
  return;
}


// ==== FUN_004c7d40 @ 0x004c7d40 ====

void FUN_004c7d40(uint param_1,undefined1 param_2)

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
    FUN_004c7a80(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_004c7db0 @ 0x004c7db0 ====

/* WARNING: Removing unreachable block (ram,0x004c7dcb) */
/* WARNING: Removing unreachable block (ram,0x004c7dd0) */
/* WARNING: Removing unreachable block (ram,0x004c7dde) */

void FUN_004c7db0(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_004c7a80(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_004c7e00 @ 0x004c7e00 ====

undefined4 * FUN_004c7e00(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980b51;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x50);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[8] = 0xf;
    puVar1[7] = 0;
    *(undefined1 *)(puVar1 + 3) = 0;
    FUN_00401660(param_3,0,0xffffffff);
    puVar3 = (undefined4 *)(param_3 + 0x1c);
    puVar4 = puVar1 + 9;
    for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@004c7e8b @ 0x004c7e8b ====

void Catch_004c7e8b(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004c7eb0 @ 0x004c7eb0 ====

void FUN_004c7eb0(uint param_1,undefined4 param_2)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980b30;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 != 0) {
    uVar1 = param_1;
    if (0x3fffffff < param_1) {
      uVar1 = FUN_004c7a00();
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


// ==== Catch@004c7f46 @ 0x004c7f46 ====

void Catch_004c7f46(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004c7f60 @ 0x004c7f60 ====

void FUN_004c7f60(void)

{
  int in_ECX;
  
  FUN_004c7d00();
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004c7f80 @ 0x004c7f80 ====

void FUN_004c7f80(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00980b60;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != param_3; param_2 = (undefined4 *)*param_2) {
    iVar1 = FUN_004c7e00(param_1,*(undefined4 *)(param_1 + 4),param_2 + 2);
    FUN_004c78c0(1);
    *(int *)(param_1 + 4) = iVar1;
    **(int **)(iVar1 + 4) = iVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004c7fe5 @ 0x004c7fe5 ====

void Catch_004c7fe5(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  
  puVar2 = *(undefined4 **)(unaff_EBP + 0xc);
  for (puVar1 = *(undefined4 **)(unaff_EBP + -0x18); puVar1 != puVar2;
      puVar1 = (undefined4 *)*puVar1) {
    FUN_004c7cc0(unaff_EBP + 0xc,*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004c8030 @ 0x004c8030 ====

void FUN_004c8030(void)

{
  int in_ECX;
  undefined4 local_4;
  
  FUN_004c7d00();
  local_4 = *(undefined4 *)(in_ECX + 8);
  FUN_004c7db0(9,&local_4);
  *(undefined4 *)(in_ECX + 0x20) = 1;
  *(undefined4 *)(in_ECX + 0x24) = 1;
  return;
}


// ==== FUN_004c8060 @ 0x004c8060 ====

void FUN_004c8060(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined1 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00980b7b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = *param_1;
  uVar1 = FUN_004c4d00();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  param_1 = *(undefined1 **)(in_ECX + 8);
  local_4 = 0;
  FUN_004c7eb0(9,&param_1);
  *(undefined4 *)(in_ECX + 0x20) = 1;
  *(undefined4 *)(in_ECX + 0x24) = 1;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004c80e0 @ 0x004c80e0 ====

void FUN_004c80e0(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x14) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    FUN_004c7d00();
    _free(*(void **)(in_ECX + 8));
    return;
  }
  _free(*(void **)(in_ECX + 0x14));
  return;
}


// ==== FUN_004c8120 @ 0x004c8120 ====

void FUN_004c8120(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x18) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    FUN_004c7d00();
    _free(*(void **)(in_ECX + 0xc));
    return;
  }
  _free(*(void **)(in_ECX + 0x18));
  return;
}


// ==== FUN_004c8160 @ 0x004c8160 ====

void FUN_004c8160(undefined1 *param_1)

{
  int iVar1;
  undefined1 *in_ECX;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980b90;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14) >> 2;
  }
  ExceptionList = &local_10;
  FUN_004c7d40(iVar1,*(undefined4 *)(in_ECX + 8));
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 0x24);
  FUN_004c7d00();
  local_8 = 0;
  FUN_004c7f80(*(undefined4 *)(in_ECX + 8),**(undefined4 **)(param_1 + 8),
               *(undefined4 **)(param_1 + 8),param_1);
  *in_ECX = *param_1;
  puVar3 = (undefined4 *)**(undefined4 **)(in_ECX + 8);
  puVar4 = (undefined4 *)**(undefined4 **)(param_1 + 8);
  uVar2 = 0;
  while ((*(int *)(in_ECX + 0x14) != 0 &&
         (uVar2 < (uint)(*(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2)))) {
    if (puVar4 == *(undefined4 **)(*(int *)(param_1 + 0x14) + uVar2 * 4)) {
      *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar2 * 4) = puVar3;
      uVar2 = uVar2 + 1;
    }
    else {
      puVar3 = (undefined4 *)*puVar3;
      puVar4 = (undefined4 *)*puVar4;
    }
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004c822b @ 0x004c822b ====

void Catch_004c822b(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x14);
  FUN_004c7d00();
  *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(iVar1 + 8);
  FUN_008335f0(*(undefined4 *)(iVar1 + 0x14),*(undefined4 *)(iVar1 + 0x18),unaff_EBP + 8);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004c8270 @ 0x004c8270 ====

void FUN_004c8270(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x20) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x20) = 0;
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined4 *)(in_ECX + 0x28) = 0;
    FUN_004c7d00();
    _free(*(void **)(in_ECX + 0x14));
    return;
  }
  _free(*(void **)(in_ECX + 0x20));
  return;
}


// ==== FUN_004c82b0 @ 0x004c82b0 ====

/* WARNING: Removing unreachable block (ram,0x004c83cb) */
/* WARNING: Removing unreachable block (ram,0x004c85bf) */

void FUN_004c82b0(int *param_1,int param_2)

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
      FUN_004c7d40(iVar4 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
LAB_004c8514:
        if ((uint)piVar11[7] <= uVar9) {
          bVar15 = false;
          goto LAB_004c8524;
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
        if (iVar6 == 0) goto LAB_004c8514;
LAB_004c8524:
        if (!bVar15) {
          if (*(uint *)(param_2 + 0x18) < 0x10) {
            pbVar14 = (byte *)(param_2 + 4);
          }
          else {
            pbVar14 = *(byte **)(param_2 + 4);
          }
          uVar9 = piVar11[7];
          if (uVar9 == 0) goto LAB_004c85ec;
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
          goto code_r0x004c85df;
        }
      }
    } while (piVar11 != *(int **)(*(int *)(in_ECX + 0x14) + iVar4));
  }
  goto LAB_004c8535;
  while( true ) {
    uVar7 = uVar7 - 1;
    bVar15 = *pbVar13 < *pbVar14;
    bVar16 = *pbVar13 == *pbVar14;
    pbVar13 = pbVar13 + 1;
    pbVar14 = pbVar14 + 1;
    if (!bVar16) break;
code_r0x004c85df:
    if (uVar7 == 0) break;
  }
  if (!bVar16) {
    iVar6 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
  }
  bVar15 = iVar6 < 0;
  if (iVar6 == 0) {
LAB_004c85ec:
    if (uVar5 <= uVar9) {
      bVar15 = false;
      goto LAB_004c85fd;
    }
  }
  else {
LAB_004c85fd:
    if (!bVar15) {
      *param_1 = (int)piVar11;
      *(undefined1 *)(param_1 + 1) = 0;
      return;
    }
  }
  piVar11 = (int *)*piVar11;
LAB_004c8535:
  iVar6 = FUN_004c7e00(piVar11,piVar11[1],param_2);
  FUN_004c78c0(1);
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


// ==== FUN_004c8620 @ 0x004c8620 ====

void FUN_004c8620(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined1 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00980bb6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = *param_1;
  uVar1 = FUN_004c4d00();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  local_4 = 1;
  FUN_004c8160(param_1);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004c8690 @ 0x004c8690 ====

void FUN_004c8690(void)

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
  FUN_004c8270();
  _free(_Memory);
  return;
}


// ==== FUN_004c86d0 @ 0x004c86d0 ====

undefined4 * FUN_004c86d0(undefined4 param_1,undefined4 param_2,undefined2 *param_3)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980bd1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x34);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    *(undefined2 *)(puVar1 + 2) = *param_3;
    FUN_004c8620(param_3 + 2);
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@004c8748 @ 0x004c8748 ====

void Catch_004c8748(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004c8760 @ 0x004c8760 ====

void FUN_004c8760(void)

{
  int in_ECX;
  
  FUN_004c8690();
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004c8780 @ 0x004c8780 ====

void FUN_004c8780(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined1 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00980beb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = *param_1;
  uVar1 = FUN_004c4d20();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  param_1 = *(undefined1 **)(in_ECX + 8);
  local_4 = 0;
  FUN_004c7eb0(9,&param_1);
  *(undefined4 *)(in_ECX + 0x20) = 1;
  *(undefined4 *)(in_ECX + 0x24) = 1;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004c8800 @ 0x004c8800 ====

void FUN_004c8800(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x14) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    FUN_004c8690();
    _free(*(void **)(in_ECX + 8));
    return;
  }
  _free(*(void **)(in_ECX + 0x14));
  return;
}


// ==== FUN_004c8840 @ 0x004c8840 ====

void FUN_004c8840(byte param_1)

{
  void *in_ECX;
  
  FUN_004c7030();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004c8860 @ 0x004c8860 ====

/* WARNING: Removing unreachable block (ram,0x004c894f) */

void FUN_004c8860(int *param_1,ushort *param_2)

{
  undefined4 *puVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  uVar6 = *(uint *)(in_ECX + 0x24);
  if (uVar6 <= *(uint *)(in_ECX + 0xc) >> 2) {
    if (*(int *)(in_ECX + 0x14) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
    }
    if (uVar6 < iVar4 - 1U) {
      if (*(uint *)(in_ECX + 0x20) < uVar6) {
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
      FUN_004c7d40(iVar4 * 2 + -1,*(undefined4 *)(in_ECX + 8));
    }
    uVar6 = (*(int *)(in_ECX + 0x24) - (*(uint *)(in_ECX + 0x20) >> 1)) - 1;
    puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
    if (puVar8 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4 + 4)) {
      do {
        iVar4 = uVar6 * 4;
        if (((*(ushort *)(puVar8 + 2) ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20)) == uVar6) {
          puVar9 = (undefined4 *)*puVar8;
        }
        else {
          puVar9 = (undefined4 *)*puVar8;
          if (puVar9 != *(undefined4 **)(in_ECX + 8)) {
            puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4);
            uVar7 = uVar6;
            while ((puVar8 == puVar1 &&
                   (*(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4) = puVar9, uVar7 != 0))) {
              uVar7 = uVar7 - 1;
              iVar4 = uVar7 * 4;
              puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4);
            }
            iVar4 = *(int *)(in_ECX + 8);
            *(undefined4 **)puVar8[1] = puVar9;
            *(int *)puVar9[1] = iVar4;
            **(undefined4 **)(iVar4 + 4) = puVar8;
            uVar3 = *(undefined4 *)(iVar4 + 4);
            *(undefined4 *)(iVar4 + 4) = puVar9[1];
            puVar9[1] = puVar8[1];
            puVar8[1] = uVar3;
            puVar8 = *(undefined4 **)(*(int *)(in_ECX + 8) + 4);
            *(int *)(*(int *)(in_ECX + 0x14) + 4 + *(int *)(in_ECX + 0x24) * 4) =
                 *(int *)(in_ECX + 8);
          }
          for (uVar7 = *(uint *)(in_ECX + 0x24);
              (uVar6 < uVar7 &&
              (*(int *)(*(int *)(in_ECX + 0x14) + uVar7 * 4) == *(int *)(in_ECX + 8)));
              uVar7 = uVar7 - 1) {
            *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar7 * 4) = puVar8;
          }
          if (puVar9 == *(undefined4 **)(in_ECX + 8)) break;
        }
        puVar8 = puVar9;
      } while (puVar9 != *(undefined4 **)(uVar6 * 4 + 4 + *(int *)(in_ECX + 0x14)));
    }
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
  }
  uVar2 = *param_2;
  uVar6 = (uVar2 ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20);
  if (*(uint *)(in_ECX + 0x24) <= uVar6) {
    uVar6 = uVar6 + (-1 - (*(uint *)(in_ECX + 0x20) >> 1));
  }
  iVar4 = uVar6 * 4;
  puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + 4 + iVar4);
  if (puVar8 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4)) {
    do {
      puVar8 = (undefined4 *)puVar8[1];
      if (*(ushort *)(puVar8 + 2) <= uVar2) {
        if (uVar2 <= *(ushort *)(puVar8 + 2)) {
          *param_1 = (int)puVar8;
          *(undefined1 *)(param_1 + 1) = 0;
          return;
        }
        puVar8 = (undefined4 *)*puVar8;
        break;
      }
    } while (puVar8 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4));
  }
  iVar5 = FUN_004c86d0(puVar8,puVar8[1],param_2);
  FUN_004c7960(1);
  puVar8[1] = iVar5;
  **(int **)(iVar5 + 4) = iVar5;
  iVar5 = puVar8[1];
  puVar9 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4);
  while ((puVar8 == puVar9 && (*(int *)(*(int *)(in_ECX + 0x14) + iVar4) = iVar5, uVar6 != 0))) {
    uVar6 = uVar6 - 1;
    iVar4 = uVar6 * 4;
    puVar9 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4);
  }
  *param_1 = iVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_004c8aa0 @ 0x004c8aa0 ====

undefined4 FUN_004c8aa0(void)

{
  return 9;
}


// ==== FUN_004c8ac0 @ 0x004c8ac0 ====

void FUN_004c8ac0(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 local_30 [20];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar1 = *(undefined4 **)(param_2 + 8);
  puVar2 = *(undefined4 **)(param_2 + 4);
  while (puVar2 != puVar1) {
    local_1c = puVar2[3];
    local_10 = *puVar2;
    local_c = puVar2[1];
    local_8 = puVar2[2];
    local_14 = DAT_0099d100;
    if (puVar2 + 4 != puVar1) {
      local_14 = puVar2[7];
    }
    local_18 = local_1c;
    local_4 = local_1c;
    FUN_004cadb0(local_30,&local_18);
    puVar2 = puVar2 + 4;
  }
  return;
}


// ==== FUN_004c8b60 @ 0x004c8b60 ====

void FUN_004c8b60(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 local_38 [24];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar1 = *(undefined4 **)(param_2 + 8);
  puVar2 = *(undefined4 **)(param_2 + 4);
  while (puVar2 != puVar1) {
    local_20 = puVar2[4];
    local_14 = *puVar2;
    local_10 = puVar2[1];
    local_c = puVar2[2];
    local_8 = puVar2[3];
    local_18 = DAT_0099d100;
    if (puVar2 + 5 != puVar1) {
      local_18 = puVar2[9];
    }
    local_1c = local_20;
    local_4 = local_20;
    FUN_004cae80(local_38,&local_1c);
    puVar2 = puVar2 + 5;
  }
  return;
}


// ==== FUN_004c8c00 @ 0x004c8c00 ====

void FUN_004c8c00(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 local_a8 [8];
  undefined4 local_a0 [16];
  undefined4 local_60;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c [18];
  
  puVar3 = *(undefined4 **)(param_2 + 4);
  puVar1 = *(undefined4 **)(param_2 + 8);
  if (puVar3 != puVar1) {
    while( true ) {
      local_60 = puVar3[0x10];
      puVar4 = puVar3 + 0x11;
      puVar5 = puVar3;
      puVar6 = local_a0;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      local_50 = DAT_0099d100;
      if (puVar4 != puVar1) {
        local_50 = puVar3[0x21];
      }
      local_54 = local_60;
      puVar3 = local_a0;
      puVar5 = local_4c;
      for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      FUN_004caf50(local_a8,&local_54);
      if (puVar4 == puVar1) break;
      puVar3 = puVar4;
    }
  }
  return;
}


// ==== FUN_004c8cb0 @ 0x004c8cb0 ====

void FUN_004c8cb0(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 local_28 [8];
  undefined4 local_20;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar2 = *(undefined4 **)(param_2 + 4);
  puVar1 = *(undefined4 **)(param_2 + 8);
  while (puVar2 != puVar1) {
    local_20 = *puVar2;
    local_8 = puVar2[1];
    local_4 = puVar2[2];
    puVar2 = puVar2 + 3;
    local_10 = DAT_0099d100;
    if (puVar2 != puVar1) {
      local_10 = *puVar2;
    }
    local_14 = local_20;
    local_c = local_20;
    FUN_004cb020(local_28,&local_14);
  }
  return;
}


// ==== FUN_004c8d40 @ 0x004c8d40 ====

void FUN_004c8d40(int param_1,float *param_2)

{
  char cVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  float fVar6;
  
  FUN_004c8cb0(param_2 + 8,param_1 + 8);
  if (param_2[10] == 0.0) {
    *param_2 = 0.0;
    param_2[1] = 0.0;
    param_2[2] = 0.0;
    param_2[3] = 0.0;
    param_2[4] = 0.0;
    param_2[5] = 0.0;
    param_2[6] = 0.0;
    param_2[7] = 0.0;
    return;
  }
  pfVar2 = (float *)param_2[9];
  fVar6 = *pfVar2;
  FUN_004ddea0();
  param_2[4] = *(float *)((int)fVar6 + 0x18);
  param_2[5] = *(float *)((int)fVar6 + 0x1c);
  param_2[6] = pfVar2[6];
  param_2[7] = pfVar2[7];
  *param_2 = *(float *)((int)fVar6 + 0x18);
  param_2[1] = *(float *)((int)fVar6 + 0x1c);
  param_2[2] = *(float *)((int)fVar6 + 0x18);
  param_2[3] = *(float *)((int)fVar6 + 0x1c);
  pfVar3 = (float *)*pfVar2;
  while (pfVar3 != pfVar2) {
    if (pfVar3[6] < *param_2 || pfVar3[6] == *param_2) {
      fVar6 = pfVar3[6];
    }
    else {
      fVar6 = *param_2;
    }
    *param_2 = fVar6;
    if (pfVar3[7] < param_2[1] || pfVar3[7] == param_2[1]) {
      fVar6 = pfVar3[7];
    }
    else {
      fVar6 = param_2[1];
    }
    param_2[1] = fVar6;
    fVar6 = param_2[2];
    if (fVar6 < pfVar3[6] || fVar6 == pfVar3[6]) {
      fVar6 = pfVar3[6];
    }
    param_2[2] = fVar6;
    fVar6 = param_2[3];
    if (fVar6 < pfVar3[7] || fVar6 == pfVar3[7]) {
      fVar6 = pfVar3[7];
    }
    param_2[3] = fVar6;
    if (*(char *)((int)pfVar3 + 0x21) == '\0') {
      pfVar4 = (float *)pfVar3[2];
      if (*(char *)((int)pfVar4 + 0x21) == '\0') {
        cVar1 = *(char *)((int)*pfVar4 + 0x21);
        pfVar3 = pfVar4;
        pfVar4 = (float *)*pfVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*pfVar4 + 0x21);
          pfVar3 = pfVar4;
          pfVar4 = (float *)*pfVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)pfVar3[1] + 0x21);
        pfVar5 = (float *)pfVar3[1];
        pfVar4 = pfVar3;
        while ((pfVar3 = pfVar5, cVar1 == '\0' && (pfVar4 == (float *)pfVar3[2]))) {
          cVar1 = *(char *)((int)pfVar3[1] + 0x21);
          pfVar5 = (float *)pfVar3[1];
          pfVar4 = pfVar3;
        }
      }
    }
  }
  return;
}


// ==== FUN_004c8ee0 @ 0x004c8ee0 ====

void FUN_004c8ee0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980c86;
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
  *in_ECX = &PTR_FUN_009b0ce4;
  iVar1 = FUN_0058d7c0();
  in_ECX[0x10] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[0x10] + 4) = in_ECX[0x10];
  *(undefined4 *)in_ECX[0x10] = in_ECX[0x10];
  *(undefined4 *)(in_ECX[0x10] + 8) = in_ECX[0x10];
  in_ECX[0x11] = 0;
  local_4._0_1_ = 1;
  iVar1 = FUN_004be360();
  in_ECX[0x1b] = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(undefined4 *)(in_ECX[0x1b] + 4) = in_ECX[0x1b];
  *(undefined4 *)in_ECX[0x1b] = in_ECX[0x1b];
  *(undefined4 *)(in_ECX[0x1b] + 8) = in_ECX[0x1b];
  in_ECX[0x1c] = 0;
  local_4._0_1_ = 2;
  FUN_00401660(param_1,0,0xffffffff);
  uVar2 = FUN_004022a0(local_28,s__Resource__Animation_Created_009b0c9c,in_ECX + 1);
  local_4 = CONCAT31(local_4._1_3_,3);
  FUN_00403e50(uVar2);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_004c8ff0 @ 0x004c8ff0 ====

undefined4 FUN_004c8ff0(int *param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uStack_28;
  undefined4 *puStack_24;
  undefined1 auStack_20 [8];
  void *pvStack_18;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00980c9b;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  iVar1 = (**(code **)(*param_1 + 4))();
  if (((iVar1 != 3) || (param_1[3] != 0x20031113)) || (param_1[0x1d] == 0)) {
    ExceptionList = pvStack_14;
    return 0;
  }
  iVar1 = param_1[0x20];
  for (iVar4 = param_1[0x1f]; iVar4 != iVar1; iVar4 = iVar4 + 100) {
    pvVar2 = operator_new(0x28);
    puVar5 = (undefined4 *)0x0;
    uStack_c = 0;
    if (pvVar2 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_004cb700();
    }
    uStack_c = 0xffffffff;
    uVar3 = (**(code **)(*DAT_00b5a7e4 + 4))(iVar4);
    *puVar5 = uVar3;
    FUN_004c8ac0(puVar5 + 1,iVar4 + 0x24);
    FUN_004c8b60(puVar5 + 4,iVar4 + 0x3c);
    FUN_004c8c00(puVar5 + 7,iVar4 + 0x54);
    uStack_28 = uVar3;
    puStack_24 = puVar5;
    FUN_004cb0f0(auStack_20,&uStack_28);
  }
  FUN_004c8d40(param_1 + 0x22,in_ECX + 0x48);
  uVar3 = (**(code **)(*param_1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar3;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 2;
  (**(code **)*param_1)(1);
  ExceptionList = pvStack_18;
  return 1;
}


// ==== FUN_004c9140 @ 0x004c9140 ====

void FUN_004c9140(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  uint local_30 [2];
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980ccb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009b0ce4;
  local_4 = 2;
  if (in_ECX[0x11] != 0) {
    local_30[0] = local_30[0] & 0xffffff00;
    FUN_004cb7b0(*(undefined4 *)in_ECX[0x10],(undefined4 *)in_ECX[0x10],local_30[0]);
    FUN_004c96a0(*(undefined4 *)(in_ECX[0x10] + 4));
    *(undefined4 *)(in_ECX[0x10] + 4) = in_ECX[0x10];
    in_ECX[0x11] = 0;
    *(undefined4 *)in_ECX[0x10] = in_ECX[0x10];
    *(undefined4 *)(in_ECX[0x10] + 8) = in_ECX[0x10];
  }
  uVar1 = FUN_004022a0(local_28,s__Resource__Animation_Removed_009b0cbc,in_ECX + 1);
  local_4._0_1_ = 3;
  FUN_00403e50(uVar1);
  if (local_10 < 0x10) {
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_004cb3f0(local_30,*(undefined4 *)in_ECX[0x1b],(undefined4 *)in_ECX[0x1b]);
    _free((void *)in_ECX[0x1b]);
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_004c9270 @ 0x004c9270 ====

void FUN_004c9270(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x59) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x59) == '\0');
  }
  return;
}


// ==== FUN_004c9290 @ 0x004c9290 ====

void FUN_004c9290(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x59);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x59);
  }
  return;
}


// ==== FUN_004c92b0 @ 0x004c92b0 ====

void FUN_004c92b0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x59) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x59) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x59);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x59);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x59);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x59);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_004c9300 @ 0x004c9300 ====

void FUN_004c9300(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x29) == '\0') {
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


// ==== FUN_004c9350 @ 0x004c9350 ====

void FUN_004c9350(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x59) == '\0') {
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


// ==== FUN_004c93a0 @ 0x004c93a0 ====

void FUN_004c93a0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x59) == '\0') {
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


// ==== FUN_004c9400 @ 0x004c9400 ====

void FUN_004c9400(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x59) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x59) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x59);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x59);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x59) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x59) == '\0');
    if (*(char *)((int)piVar4 + 0x59) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_004c9460 @ 0x004c9460 ====

void FUN_004c9460(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x28);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[3] = *param_4;
    puVar1[4] = param_4[1];
    puVar1[5] = param_4[2];
    puVar1[6] = param_4[3];
    puVar1[7] = param_4[4];
    puVar1[8] = param_4[5];
    *(undefined1 *)(puVar1 + 9) = param_5;
    *(undefined1 *)((int)puVar1 + 0x25) = 0;
  }
  return;
}


// ==== FUN_004c94c0 @ 0x004c94c0 ====

void FUN_004c94c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = operator_new(0x2c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[2] = param_3;
    puVar1[1] = param_2;
    puVar3 = puVar1 + 3;
    for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *param_4;
      param_4 = param_4 + 1;
      puVar3 = puVar3 + 1;
    }
    *(undefined1 *)(puVar1 + 10) = param_5;
    *(undefined1 *)((int)puVar1 + 0x29) = 0;
  }
  return;
}


// ==== FUN_004c9510 @ 0x004c9510 ====

void FUN_004c9510(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = operator_new(0x5c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[2] = param_3;
    puVar1[1] = param_2;
    puVar3 = puVar1 + 3;
    for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *param_4;
      param_4 = param_4 + 1;
      puVar3 = puVar3 + 1;
    }
    *(undefined1 *)(puVar1 + 0x16) = param_5;
    *(undefined1 *)((int)puVar1 + 0x59) = 0;
  }
  return;
}


// ==== FUN_004c9560 @ 0x004c9560 ====

void FUN_004c9560(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x5c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x16) = 1;
  *(undefined1 *)((int)puVar1 + 0x59) = 0;
  return;
}


// ==== FUN_004c95a0 @ 0x004c95a0 ====

void FUN_004c95a0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x25) == '\0') {
    FUN_004c95a0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004c95e0 @ 0x004c95e0 ====

void FUN_004c95e0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x29) == '\0') {
    FUN_004c95e0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004c9620 @ 0x004c9620 ====

void FUN_004c9620(void *param_1)

{
  if (*(char *)((int)param_1 + 0x59) == '\0') {
    FUN_004c9620(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004c9660 @ 0x004c9660 ====

void FUN_004c9660(void *param_1)

{
  if (*(char *)((int)param_1 + 0x21) == '\0') {
    FUN_004c9660(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004c96a0 @ 0x004c96a0 ====

void FUN_004c96a0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_004c96a0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004c96e0 @ 0x004c96e0 ====

void FUN_004c96e0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00980c08;
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
  piVar4 = (int *)FUN_004c9460(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_004c97d9:
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
      if ((char)piVar6[9] == '\0') goto LAB_004c97d9;
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


// ==== FUN_004c98c0 @ 0x004c98c0 ====

void FUN_004c98c0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00980c08;
  local_c = ExceptionList;
  if (0x9249247 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004c94c0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[10] == '\0') {
LAB_004c99b9:
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
      if ((char)piVar6[10] == '\0') goto LAB_004c99b9;
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


// ==== FUN_004c9aa0 @ 0x004c9aa0 ====

void FUN_004c9aa0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00980c08;
  local_c = ExceptionList;
  if (0x35e50d5 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004c9510(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x58);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x58) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x16] == '\0') {
LAB_004c9b99:
        *(undefined1 *)(*piVar5 + 0x58) = 1;
        *(undefined1 *)(piVar6 + 0x16) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x58) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_004c9350(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x58) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x58) = 0;
        FUN_004c93a0(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x16] == '\0') goto LAB_004c9b99;
      if (piVar7 == (int *)*piVar2) {
        FUN_004c93a0(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x58) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x58) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x59) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x58);
  } while( true );
}


// ==== FUN_004c9c80 @ 0x004c9c80 ====

void FUN_004c9c80(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00980c08;
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
  piVar4 = (int *)FUN_004be2c0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_004c9d79:
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
      if ((char)piVar6[8] == '\0') goto LAB_004c9d79;
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


// ==== FUN_004c9e60 @ 0x004c9e60 ====

void FUN_004c9e60(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00980c08;
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
LAB_004c9f59:
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
      if ((char)piVar6[5] == '\0') goto LAB_004c9f59;
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


// ==== FUN_004ca040 @ 0x004ca040 ====

/* WARNING: Removing unreachable block (ram,0x004ca153) */
/* WARNING: Removing unreachable block (ram,0x004ca163) */
/* WARNING: Removing unreachable block (ram,0x004ca16c) */
/* WARNING: Removing unreachable block (ram,0x004ca16f) */
/* WARNING: Removing unreachable block (ram,0x004ca15f) */
/* WARNING: Removing unreachable block (ram,0x004ca17d) */
/* WARNING: Removing unreachable block (ram,0x004ca18a) */
/* WARNING: Removing unreachable block (ram,0x004ca195) */
/* WARNING: Removing unreachable block (ram,0x004ca191) */
/* WARNING: Removing unreachable block (ram,0x004ca185) */
/* WARNING: Removing unreachable block (ram,0x004ca198) */

void FUN_004ca040(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00980c08;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x25) != '\0') {
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
  FUN_0051b6b0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x25) == '\0') {
    if (*(char *)(param_2[2] + 0x25) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x25) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x25) == '\0') {
      piVar3 = (int *)FUN_00412870(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x25) == '\0') {
      uVar4 = FUN_004ae4e0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[9] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[9] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[9] == '\0') {
            *(undefined1 *)(piVar5 + 9) = 1;
            *(undefined1 *)(piVar3 + 9) = 0;
            FUN_0058b7f0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x25) == '\0') {
            if ((*(char *)(*piVar5 + 0x24) == '\x01') && (*(char *)(piVar5[2] + 0x24) == '\x01'))
            goto LAB_004ca265;
            if (*(char *)(piVar5[2] + 0x24) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x24) = 1;
              *(undefined1 *)(piVar5 + 9) = 0;
              FUN_00412890(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 9) = (char)piVar3[9];
            *(undefined1 *)(piVar3 + 9) = 1;
            *(undefined1 *)(piVar5[2] + 0x24) = 1;
            FUN_0058b7f0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[9] == '\0') {
            *(undefined1 *)(piVar5 + 9) = 1;
            *(undefined1 *)(piVar3 + 9) = 0;
            FUN_00412890(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x25) == '\0') {
            if ((*(char *)(piVar5[2] + 0x24) != '\x01') || (*(char *)(*piVar5 + 0x24) != '\x01')) {
              if (*(char *)(*piVar5 + 0x24) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x24) = 1;
                *(undefined1 *)(piVar5 + 9) = 0;
                FUN_0058b7f0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 9) = (char)piVar3[9];
              *(undefined1 *)(piVar3 + 9) = 1;
              *(undefined1 *)(*piVar5 + 0x24) = 1;
              FUN_00412890(piVar3);
              break;
            }
LAB_004ca265:
            *(undefined1 *)(piVar5 + 9) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 9) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_004ca2f0 @ 0x004ca2f0 ====

/* WARNING: Removing unreachable block (ram,0x004ca403) */
/* WARNING: Removing unreachable block (ram,0x004ca413) */
/* WARNING: Removing unreachable block (ram,0x004ca41c) */
/* WARNING: Removing unreachable block (ram,0x004ca41f) */
/* WARNING: Removing unreachable block (ram,0x004ca40f) */
/* WARNING: Removing unreachable block (ram,0x004ca42d) */
/* WARNING: Removing unreachable block (ram,0x004ca43a) */
/* WARNING: Removing unreachable block (ram,0x004ca445) */
/* WARNING: Removing unreachable block (ram,0x004ca441) */
/* WARNING: Removing unreachable block (ram,0x004ca435) */
/* WARNING: Removing unreachable block (ram,0x004ca448) */

void FUN_004ca2f0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00980c08;
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
            goto LAB_004ca515;
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
LAB_004ca515:
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


// ==== FUN_004ca5a0 @ 0x004ca5a0 ====

/* WARNING: Removing unreachable block (ram,0x004ca6b3) */
/* WARNING: Removing unreachable block (ram,0x004ca6c3) */
/* WARNING: Removing unreachable block (ram,0x004ca6cc) */
/* WARNING: Removing unreachable block (ram,0x004ca6cf) */
/* WARNING: Removing unreachable block (ram,0x004ca6bf) */
/* WARNING: Removing unreachable block (ram,0x004ca6dd) */
/* WARNING: Removing unreachable block (ram,0x004ca6ea) */
/* WARNING: Removing unreachable block (ram,0x004ca6f5) */
/* WARNING: Removing unreachable block (ram,0x004ca6f1) */
/* WARNING: Removing unreachable block (ram,0x004ca6e5) */
/* WARNING: Removing unreachable block (ram,0x004ca6f8) */

void FUN_004ca5a0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00980c08;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x59) != '\0') {
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
  FUN_004c92b0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x59) == '\0') {
    if (*(char *)(param_2[2] + 0x59) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x59) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x59) == '\0') {
      piVar3 = (int *)FUN_004c9290(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x59) == '\0') {
      uVar4 = FUN_004c9270(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0x16] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x16] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x16] == '\0') {
            *(undefined1 *)(piVar5 + 0x16) = 1;
            *(undefined1 *)(piVar3 + 0x16) = 0;
            FUN_004c9350(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x59) == '\0') {
            if ((*(char *)(*piVar5 + 0x58) == '\x01') && (*(char *)(piVar5[2] + 0x58) == '\x01'))
            goto LAB_004ca7c5;
            if (*(char *)(piVar5[2] + 0x58) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x58) = 1;
              *(undefined1 *)(piVar5 + 0x16) = 0;
              FUN_004c93a0(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0x16) = (char)piVar3[0x16];
            *(undefined1 *)(piVar3 + 0x16) = 1;
            *(undefined1 *)(piVar5[2] + 0x58) = 1;
            FUN_004c9350(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0x16] == '\0') {
            *(undefined1 *)(piVar5 + 0x16) = 1;
            *(undefined1 *)(piVar3 + 0x16) = 0;
            FUN_004c93a0(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x59) == '\0') {
            if ((*(char *)(piVar5[2] + 0x58) != '\x01') || (*(char *)(*piVar5 + 0x58) != '\x01')) {
              if (*(char *)(*piVar5 + 0x58) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x58) = 1;
                *(undefined1 *)(piVar5 + 0x16) = 0;
                FUN_004c9350(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0x16) = (char)piVar3[0x16];
              *(undefined1 *)(piVar3 + 0x16) = 1;
              *(undefined1 *)(*piVar5 + 0x58) = 1;
              FUN_004c93a0(piVar3);
              break;
            }
LAB_004ca7c5:
            *(undefined1 *)(piVar5 + 0x16) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x16) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_004ca850 @ 0x004ca850 ====

/* WARNING: Removing unreachable block (ram,0x004ca963) */
/* WARNING: Removing unreachable block (ram,0x004ca973) */
/* WARNING: Removing unreachable block (ram,0x004ca97c) */
/* WARNING: Removing unreachable block (ram,0x004ca97f) */
/* WARNING: Removing unreachable block (ram,0x004ca96f) */
/* WARNING: Removing unreachable block (ram,0x004ca98d) */
/* WARNING: Removing unreachable block (ram,0x004ca99a) */
/* WARNING: Removing unreachable block (ram,0x004ca9a5) */
/* WARNING: Removing unreachable block (ram,0x004ca9a1) */
/* WARNING: Removing unreachable block (ram,0x004ca995) */
/* WARNING: Removing unreachable block (ram,0x004ca9a8) */

void FUN_004ca850(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00980c08;
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
            goto LAB_004caa75;
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
LAB_004caa75:
            *(undefined1 *)(piVar5 + 8) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 8) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_004cab00 @ 0x004cab00 ====

/* WARNING: Removing unreachable block (ram,0x004cac13) */
/* WARNING: Removing unreachable block (ram,0x004cac23) */
/* WARNING: Removing unreachable block (ram,0x004cac2c) */
/* WARNING: Removing unreachable block (ram,0x004cac2f) */
/* WARNING: Removing unreachable block (ram,0x004cac1f) */
/* WARNING: Removing unreachable block (ram,0x004cac3d) */
/* WARNING: Removing unreachable block (ram,0x004cac4a) */
/* WARNING: Removing unreachable block (ram,0x004cac55) */
/* WARNING: Removing unreachable block (ram,0x004cac51) */
/* WARNING: Removing unreachable block (ram,0x004cac45) */
/* WARNING: Removing unreachable block (ram,0x004cac58) */

void FUN_004cab00(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00980c08;
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
            goto LAB_004cad25;
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
LAB_004cad25:
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


// ==== FUN_004cadb0 @ 0x004cadb0 ====

void FUN_004cadb0(undefined4 *param_1,float *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  float *pfVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int in_ECX;
  bool bVar7;
  
  pfVar4 = param_2;
  puVar6 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  bVar7 = true;
  cVar1 = *(char *)((int)puVar6 + 0x25);
  puVar3 = *(undefined4 **)(in_ECX + 4);
  while (cVar1 == '\0') {
    if (((float)puVar6[3] < *param_2 || (float)puVar6[3] == *param_2) ||
       ((float)puVar6[4] < param_2[1] || (float)puVar6[4] == param_2[1])) {
      bVar7 = false;
    }
    else {
      bVar7 = true;
    }
    if (bVar7) {
      puVar5 = (undefined4 *)*puVar6;
    }
    else {
      puVar5 = (undefined4 *)puVar6[2];
    }
    puVar3 = puVar6;
    puVar6 = puVar5;
    cVar1 = *(char *)((int)puVar5 + 0x25);
  }
  param_2 = (float *)puVar3;
  if (bVar7 != false) {
    if (puVar3 == (undefined4 *)**(int **)(in_ECX + 4)) {
      bVar7 = true;
      goto LAB_004cae46;
    }
    FUN_0058aca0();
  }
  if ((*pfVar4 < param_2[3] || *pfVar4 == param_2[3]) ||
     (pfVar4[1] < param_2[4] || pfVar4[1] == param_2[4])) {
    *(undefined1 *)(param_1 + 1) = 0;
    *param_1 = param_2;
    return;
  }
LAB_004cae46:
  puVar6 = (undefined4 *)FUN_004c96e0(&param_2,bVar7,puVar3,pfVar4);
  uVar2 = *puVar6;
  *(undefined1 *)(param_1 + 1) = 1;
  *param_1 = uVar2;
  return;
}


// ==== FUN_004cae80 @ 0x004cae80 ====

void FUN_004cae80(undefined4 *param_1,float *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  float *pfVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int in_ECX;
  bool bVar7;
  
  pfVar4 = param_2;
  puVar6 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  bVar7 = true;
  cVar1 = *(char *)((int)puVar6 + 0x29);
  puVar3 = *(undefined4 **)(in_ECX + 4);
  while (cVar1 == '\0') {
    if (((float)puVar6[3] < *param_2 || (float)puVar6[3] == *param_2) ||
       ((float)puVar6[4] < param_2[1] || (float)puVar6[4] == param_2[1])) {
      bVar7 = false;
    }
    else {
      bVar7 = true;
    }
    if (bVar7) {
      puVar5 = (undefined4 *)*puVar6;
    }
    else {
      puVar5 = (undefined4 *)puVar6[2];
    }
    puVar3 = puVar6;
    puVar6 = puVar5;
    cVar1 = *(char *)((int)puVar5 + 0x29);
  }
  param_2 = (float *)puVar3;
  if (bVar7 != false) {
    if (puVar3 == (undefined4 *)**(int **)(in_ECX + 4)) {
      bVar7 = true;
      goto LAB_004caf16;
    }
    FUN_00798b50();
  }
  if ((*pfVar4 < param_2[3] || *pfVar4 == param_2[3]) ||
     (pfVar4[1] < param_2[4] || pfVar4[1] == param_2[4])) {
    *(undefined1 *)(param_1 + 1) = 0;
    *param_1 = param_2;
    return;
  }
LAB_004caf16:
  puVar6 = (undefined4 *)FUN_004c98c0(&param_2,bVar7,puVar3,pfVar4);
  uVar2 = *puVar6;
  *(undefined1 *)(param_1 + 1) = 1;
  *param_1 = uVar2;
  return;
}


// ==== FUN_004caf50 @ 0x004caf50 ====

void FUN_004caf50(undefined4 *param_1,float *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  float *pfVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int in_ECX;
  bool bVar7;
  
  pfVar4 = param_2;
  puVar6 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  bVar7 = true;
  cVar1 = *(char *)((int)puVar6 + 0x59);
  puVar3 = *(undefined4 **)(in_ECX + 4);
  while (cVar1 == '\0') {
    if (((float)puVar6[3] < *param_2 || (float)puVar6[3] == *param_2) ||
       ((float)puVar6[4] < param_2[1] || (float)puVar6[4] == param_2[1])) {
      bVar7 = false;
    }
    else {
      bVar7 = true;
    }
    if (bVar7) {
      puVar5 = (undefined4 *)*puVar6;
    }
    else {
      puVar5 = (undefined4 *)puVar6[2];
    }
    puVar3 = puVar6;
    puVar6 = puVar5;
    cVar1 = *(char *)((int)puVar5 + 0x59);
  }
  param_2 = (float *)puVar3;
  if (bVar7 != false) {
    if (puVar3 == (undefined4 *)**(int **)(in_ECX + 4)) {
      bVar7 = true;
      goto LAB_004cafe6;
    }
    FUN_004c9400();
  }
  if ((*pfVar4 < param_2[3] || *pfVar4 == param_2[3]) ||
     (pfVar4[1] < param_2[4] || pfVar4[1] == param_2[4])) {
    *(undefined1 *)(param_1 + 1) = 0;
    *param_1 = param_2;
    return;
  }
LAB_004cafe6:
  puVar6 = (undefined4 *)FUN_004c9aa0(&param_2,bVar7,puVar3,pfVar4);
  uVar2 = *puVar6;
  *(undefined1 *)(param_1 + 1) = 1;
  *param_1 = uVar2;
  return;
}


// ==== FUN_004cb020 @ 0x004cb020 ====

void FUN_004cb020(undefined4 *param_1,float *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  float *pfVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int in_ECX;
  bool bVar7;
  
  pfVar4 = param_2;
  puVar6 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  bVar7 = true;
  cVar1 = *(char *)((int)puVar6 + 0x21);
  puVar3 = *(undefined4 **)(in_ECX + 4);
  while (cVar1 == '\0') {
    if (((float)puVar6[3] < *param_2 || (float)puVar6[3] == *param_2) ||
       ((float)puVar6[4] < param_2[1] || (float)puVar6[4] == param_2[1])) {
      bVar7 = false;
    }
    else {
      bVar7 = true;
    }
    if (bVar7) {
      puVar5 = (undefined4 *)*puVar6;
    }
    else {
      puVar5 = (undefined4 *)puVar6[2];
    }
    puVar3 = puVar6;
    puVar6 = puVar5;
    cVar1 = *(char *)((int)puVar5 + 0x21);
  }
  param_2 = (float *)puVar3;
  if (bVar7 != false) {
    if (puVar3 == (undefined4 *)**(int **)(in_ECX + 4)) {
      bVar7 = true;
      goto LAB_004cb0b6;
    }
    FUN_004ddea0();
  }
  if ((*pfVar4 < param_2[3] || *pfVar4 == param_2[3]) ||
     (pfVar4[1] < param_2[4] || pfVar4[1] == param_2[4])) {
    *(undefined1 *)(param_1 + 1) = 0;
    *param_1 = param_2;
    return;
  }
LAB_004cb0b6:
  puVar6 = (undefined4 *)FUN_004c9c80(&param_2,bVar7,puVar3,pfVar4);
  uVar2 = *puVar6;
  *(undefined1 *)(param_1 + 1) = 1;
  *param_1 = uVar2;
  return;
}


// ==== FUN_004cb0f0 @ 0x004cb0f0 ====

void FUN_004cb0f0(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_004c9e60(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_004c9e60(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004cb1b0 @ 0x004cb1b0 ====

void FUN_004cb1b0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004c95a0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x25) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x25) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x25);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x25);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x25);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x25);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_004ca040(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004cb270 @ 0x004cb270 ====

void FUN_004cb270(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004c95e0(piVar6[1]);
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
    FUN_004ca2f0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004cb330 @ 0x004cb330 ====

void FUN_004cb330(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004c9620(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x59) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x59) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x59);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x59);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x59);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x59);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_004ca5a0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004cb3f0 @ 0x004cb3f0 ====

void FUN_004cb3f0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004c9660(piVar6[1]);
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
    FUN_004ca850(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004cb4b0 @ 0x004cb4b0 ====

void FUN_004cb4b0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004c96a0(piVar6[1]);
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
    FUN_004cab00(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004cb570 @ 0x004cb570 ====

void FUN_004cb570(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004cb4b0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004cb5a0 @ 0x004cb5a0 ====

void FUN_004cb5a0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004cb1b0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004cb5d0 @ 0x004cb5d0 ====

void FUN_004cb5d0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004cb270(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004cb600 @ 0x004cb600 ====

void FUN_004cb600(void)

{
  int in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980c36;
  pvStack_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  FUN_004cb330(local_10,**(undefined4 **)(in_ECX + 0x20),*(undefined4 **)(in_ECX + 0x20));
  _free(*(void **)(in_ECX + 0x20));
  return;
}


// ==== FUN_004cb6d0 @ 0x004cb6d0 ====

void FUN_004cb6d0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004cb3f0(local_4,**(undefined4 **)(in_ECX + 0x24),*(undefined4 **)(in_ECX + 0x24));
  _free(*(void **)(in_ECX + 0x24));
  return;
}


// ==== FUN_004cb700 @ 0x004cb700 ====

void FUN_004cb700(void)

{
  int iVar1;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00980c56;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_00412d20();
  *(int *)(in_ECX + 8) = iVar1;
  *(undefined1 *)(iVar1 + 0x25) = 1;
  *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
  *(undefined4 *)*(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 8);
  *(int *)(*(int *)(in_ECX + 8) + 8) = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  local_4 = 0;
  iVar1 = FUN_00415ec0();
  *(int *)(in_ECX + 0x14) = iVar1;
  *(undefined1 *)(iVar1 + 0x29) = 1;
  *(int *)(*(int *)(in_ECX + 0x14) + 4) = *(int *)(in_ECX + 0x14);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x14);
  *(int *)(*(int *)(in_ECX + 0x14) + 8) = *(int *)(in_ECX + 0x14);
  *(undefined4 *)(in_ECX + 0x18) = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  iVar1 = FUN_004c9560();
  *(int *)(in_ECX + 0x20) = iVar1;
  *(undefined1 *)(iVar1 + 0x59) = 1;
  *(int *)(*(int *)(in_ECX + 0x20) + 4) = *(int *)(in_ECX + 0x20);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(in_ECX + 0x20);
  *(int *)(*(int *)(in_ECX + 0x20) + 8) = *(int *)(in_ECX + 0x20);
  *(undefined4 *)(in_ECX + 0x24) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004cb7b0 @ 0x004cb7b0 ====

uint FUN_004cb7b0(int *param_1,int *param_2,byte param_3)

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
  FUN_004cb600();
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_004cb830 @ 0x004cb830 ====

void FUN_004cb830(byte param_1)

{
  void *in_ECX;
  
  FUN_004c9140();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004cb860 @ 0x004cb860 ====

void FUN_004cb860(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980d48;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009b0d5c;
  local_4 = 0;
  FUN_004cbdd0();
  local_4 = 0xffffffff;
  FUN_0049da30();
  ExceptionList = local_c;
  return;
}


// ==== FUN_004cb8c0 @ 0x004cb8c0 ====

void FUN_004cb8c0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980d65;
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
  *in_ECX = &PTR_FUN_009b0d5c;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  local_4 = 1;
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004cb950 @ 0x004cb950 ====

void FUN_004cb950(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *unaff_retaddr;
  
  uVar2 = (**(code **)(*DAT_00b5a7e4 + 4))(param_1);
  uVar3 = (**(code **)(*DAT_00b5a7e4 + 4))(param_1 + 0x1c);
  unaff_retaddr[1] = uVar3;
  *unaff_retaddr = uVar2;
  unaff_retaddr[2] = *(undefined4 *)(param_1 + 0x38);
  unaff_retaddr[3] = *(undefined4 *)(param_1 + 0x3c);
  unaff_retaddr[4] = *(undefined4 *)(param_1 + 0x40);
  unaff_retaddr[5] = *(undefined4 *)(param_1 + 0x44);
  unaff_retaddr[6] = *(undefined4 *)(param_1 + 0x48);
  unaff_retaddr[7] = *(undefined4 *)(param_1 + 0x4c);
  unaff_retaddr[8] = *(undefined4 *)(param_1 + 0x50);
  puVar7 = (undefined4 *)(param_1 + 0x54);
  puVar9 = unaff_retaddr + 9;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar9 = puVar9 + 1;
  }
  iVar4 = 0;
  if (*(int *)(param_1 + 0x9c) != 0) {
    iVar4 = (*(int *)(param_1 + 0xa0) - *(int *)(param_1 + 0x9c)) / 0xa8;
  }
  FUN_004cc840(iVar4);
  iVar4 = *(int *)(param_1 + 0xa0);
  iVar8 = *(int *)(param_1 + 0x9c);
  uVar5 = 0;
  if (iVar8 != iVar4) {
    iVar6 = 0;
    do {
      iVar1 = unaff_retaddr[0x1a];
      if ((iVar1 == 0) || ((uint)((unaff_retaddr[0x1b] - iVar1) / 0x74) <= uVar5)) {
        FUN_004cbea0();
        return;
      }
      FUN_004cb950(iVar8,iVar1 + iVar6);
      iVar8 = iVar8 + 0xa8;
      uVar5 = uVar5 + 1;
      iVar6 = iVar6 + 0x74;
    } while (iVar8 != iVar4);
  }
  return;
}


// ==== FUN_004cba70 @ 0x004cba70 ====

undefined4 FUN_004cba70(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  int iStack_10;
  
  iVar3 = (**(code **)(*param_1 + 4))();
  if ((iVar3 != 2) || (param_1[3] != 0x20040729)) {
    return 0;
  }
  uVar6 = 0;
  if (param_1[0x1c] == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (param_1[0x1d] - param_1[0x1c]) / 0xa8;
  }
  FUN_004cc840(uVar5);
  if (uVar5 != 0) {
    iVar3 = 0;
    iStack_10 = 0;
    do {
      iVar1 = *(int *)(in_ECX + 0x40);
      if ((iVar1 == 0) || ((uint)((*(int *)(in_ECX + 0x44) - iVar1) / 0x74) <= uVar6)) {
        FUN_004cbea0();
LAB_004cbba4:
                    /* WARNING: Subroutine does not return */
        FUN_00425280();
      }
      iVar2 = param_1[0x1c];
      if ((iVar2 == 0) || ((uint)((param_1[0x1d] - iVar2) / 0xa8) <= uVar6)) goto LAB_004cbba4;
      FUN_004cb950(iVar2 + iVar3,iVar1 + iStack_10);
      iStack_10 = iStack_10 + 0x74;
      uVar6 = uVar6 + 1;
      iVar3 = iVar3 + 0xa8;
    } while (uVar6 < uVar5);
  }
  uVar4 = (**(code **)(*param_1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar4;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 2;
  (**(code **)*param_1)(1);
  return 1;
}


// ==== FUN_004cbbb0 @ 0x004cbbb0 ====

int FUN_004cbbb0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x74;
}


// ==== FUN_004cbbe0 @ 0x004cbbe0 ====

int FUN_004cbbe0(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    FUN_004cc290(param_1);
    param_1 = param_1 + 0x74;
    param_3 = param_3 + 0x74;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_004cbc20 @ 0x004cbc20 ====

int FUN_004cbc20(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00980cf1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x74) {
    local_8 = 1;
    if (param_3 != 0) {
      FUN_004cc220(param_1);
    }
    param_3 = param_3 + 0x74;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@004cbc76 @ 0x004cbc76 ====

void Catch_004cbc76(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x74) {
    FUN_004cbdd0();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004cbcb0 @ 0x004cbcb0 ====

void FUN_004cbcb0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00980d11;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != 0) {
      FUN_004cc220(param_3);
    }
    param_1 = param_1 + 0x74;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004cbd08 @ 0x004cbd08 ====

void Catch_004cbd08(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x74) {
    FUN_004cbdd0();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004cbd40 @ 0x004cbd40 ====

void FUN_004cbd40(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_004cbc20(param_1,param_2,param_3);
  return;
}


// ==== FUN_004cbd60 @ 0x004cbd60 ====

void FUN_004cbd60(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x74) {
    FUN_004cbe90();
  }
  return;
}


// ==== FUN_004cbd90 @ 0x004cbd90 ====

int FUN_004cbd90(int param_1,int param_2,undefined4 param_3)

{
  FUN_004cbcb0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x74;
}


// ==== FUN_004cbdd0 @ 0x004cbdd0 ====

void FUN_004cbdd0(void)

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
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x74) {
    FUN_004cbe90();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004cbe20 @ 0x004cbe20 ====

void FUN_004cbe20(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  if (param_2 != param_3) {
    iVar2 = FUN_004cbbe0(param_3,*(undefined4 *)(in_ECX + 8),param_2,param_2);
    iVar1 = *(int *)(in_ECX + 8);
    for (iVar3 = iVar2; iVar3 != iVar1; iVar3 = iVar3 + 0x74) {
      FUN_004cbe90();
    }
    *(int *)(in_ECX + 8) = iVar2;
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_004cbe80 @ 0x004cbe80 ====

void FUN_004cbe80(void)

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
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x74) {
    FUN_004cbe90();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004cbe90 @ 0x004cbe90 ====

void FUN_004cbe90(void)

{
  FUN_004cbdd0();
  return;
}


// ==== FUN_004cbea0 @ 0x004cbea0 ====

void FUN_004cbea0(void)

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
  puStack_8 = &LAB_00980d28;
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


// ==== FUN_004cbf10 @ 0x004cbf10 ====

void FUN_004cbf10(void)

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
  puStack_8 = &LAB_00980d28;
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


// ==== FUN_004cbf80 @ 0x004cbf80 ====

undefined4 FUN_004cbf80(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x234f72c < param_1) {
    param_1 = FUN_004cbf10();
  }
  pvVar1 = operator_new(param_1 * 0x74);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x74 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_004cbfe0 @ 0x004cbfe0 ====

void FUN_004cbfe0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980d70;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x74;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_004cbf80(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_004cbc20(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004cc06c @ 0x004cc06c ====

void Catch_004cc06c(void)

{
  FUN_004cbdd0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004cc080 @ 0x004cc080 ====

void FUN_004cc080(int param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  
  if (in_ECX == param_1) {
    return;
  }
  if (*(int *)(param_1 + 4) != 0) {
    iVar5 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
    iVar4 = iVar5 >> 0x1f;
    iVar5 = iVar5 / 0x74 + iVar4;
    uVar6 = iVar5 - iVar4;
    if (iVar5 != iVar4) {
      iVar4 = *(int *)(in_ECX + 4);
      if (iVar4 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = (*(int *)(in_ECX + 8) - iVar4) / 0x74;
      }
      if (uVar6 <= uVar2) {
        uVar3 = FUN_004cbbe0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),iVar4,param_1
                            );
        FUN_004cbd60(uVar3,*(undefined4 *)(in_ECX + 8));
        iVar4 = 0;
        if (*(int *)(param_1 + 4) != 0) {
          iVar4 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x74;
        }
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4) + iVar4 * 0x74;
        return;
      }
      if (iVar4 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = (*(int *)(in_ECX + 0xc) - iVar4) / 0x74;
      }
      if (uVar6 <= uVar2) {
        iVar5 = FUN_004cbbb0();
        iVar5 = *(int *)(param_1 + 4) + iVar5 * 0x74;
        FUN_004cbbe0(*(int *)(param_1 + 4),iVar5,iVar4,param_1);
        uVar3 = FUN_004cbc20(iVar5,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar3;
        return;
      }
      if (iVar4 != 0) {
        FUN_004cbd60(iVar4,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      uVar3 = FUN_004cbbb0();
      cVar1 = FUN_004cbf80(uVar3);
      if (cVar1 == '\0') {
        return;
      }
      uVar3 = FUN_004cbd40(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar3;
      return;
    }
  }
  FUN_004cbdd0();
  return;
}


// ==== FUN_004cc200 @ 0x004cc200 ====

void FUN_004cc200(byte param_1)

{
  void *in_ECX;
  
  FUN_004cb860();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004cc220 @ 0x004cc220 ====

void FUN_004cc220(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  in_ECX[4] = param_1[4];
  in_ECX[5] = param_1[5];
  in_ECX[6] = param_1[6];
  in_ECX[7] = param_1[7];
  in_ECX[8] = param_1[8];
  puVar2 = param_1 + 9;
  puVar3 = in_ECX + 9;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_004cbfe0(param_1 + 0x19);
  return;
}


// ==== FUN_004cc290 @ 0x004cc290 ====

void FUN_004cc290(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  in_ECX[4] = param_1[4];
  in_ECX[5] = param_1[5];
  in_ECX[6] = param_1[6];
  in_ECX[7] = param_1[7];
  in_ECX[8] = param_1[8];
  puVar2 = param_1 + 9;
  puVar3 = in_ECX + 9;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_004cc080(param_1 + 0x19);
  return;
}


// ==== FUN_004cc300 @ 0x004cc300 ====

undefined4 * FUN_004cc300(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_1 != param_2) {
    puVar2 = param_2 + 2;
    puVar3 = param_3 + 2;
    while( true ) {
      param_2 = param_2 + -0x1d;
      param_3 = param_3 + -0x1d;
      *param_3 = *param_2;
      puVar3[-0x1e] = puVar2[-0x1e];
      puVar3[-0x1d] = puVar2[-0x1d];
      puVar3[-0x1c] = puVar2[-0x1c];
      puVar3[-0x1b] = puVar2[-0x1b];
      puVar3[-0x1a] = puVar2[-0x1a];
      puVar3[-0x19] = puVar2[-0x19];
      puVar3[-0x18] = puVar2[-0x18];
      puVar3[-0x17] = puVar2[-0x17];
      puVar4 = puVar2 + -0x16;
      puVar5 = puVar3 + -0x16;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      FUN_004cc080(puVar2 + -6);
      if (param_2 == param_1) break;
      puVar2 = puVar2 + -0x1d;
      puVar3 = puVar3 + -0x1d;
    }
  }
  return param_3;
}


// ==== FUN_004cc3a0 @ 0x004cc3a0 ====

void FUN_004cc3a0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (param_1 != param_2) {
    puVar2 = param_1 + 2;
    do {
      *param_1 = *param_3;
      puVar2[-1] = param_3[1];
      *puVar2 = param_3[2];
      puVar2[1] = param_3[3];
      puVar2[2] = param_3[4];
      puVar2[3] = param_3[5];
      puVar2[4] = param_3[6];
      puVar2[5] = param_3[7];
      puVar2[6] = param_3[8];
      puVar3 = param_3 + 9;
      puVar4 = puVar2 + 7;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      FUN_004cc080(param_3 + 0x19);
      param_1 = param_1 + 0x1d;
      puVar2 = puVar2 + 0x1d;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_004cc420 @ 0x004cc420 ====

void FUN_004cc420(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  int iVar6;
  undefined1 local_8c [2];
  undefined1 auStack_8a [118];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980d8b;
  local_10 = ExceptionList;
  local_14 = local_8c + -0xc;
  ExceptionList = &local_10;
  FUN_004cc220(param_3);
  iVar2 = *(int *)(in_ECX + 4);
  uVar5 = 0;
  local_8 = 0;
  if (iVar2 != 0) {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x74;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x74;
    }
    if (0x234f72cU - iVar2 < param_2) {
      FUN_004cbf10();
      uVar5 = extraout_ECX;
    }
    if (*(int *)(in_ECX + 4) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x74;
    }
    if (uVar5 < iVar2 + param_2) {
      if (0x234f72c - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (*(int *)(in_ECX + 4) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x74;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_004cbbb0();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x74);
      local_8 = CONCAT31(local_8._1_3_,1);
      uVar4 = FUN_004cbc20(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      uVar4 = FUN_004cbd90(uVar4,param_2,local_8c);
      FUN_004cbc20(param_1,*(undefined4 *)(in_ECX + 8),uVar4);
      local_8 = 0;
      iVar2 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x74;
      }
      if (*(int *)(in_ECX + 4) != 0) {
        FUN_004cbd60(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x74 + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar2) * 0x74);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      iVar1 = param_2 * 0x74;
      if ((uint)((iVar2 - param_1) / 0x74) < param_2) {
        FUN_004cbc20(param_1,iVar2,iVar1 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004cbd90(*(undefined4 *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x74,
                     local_8c);
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar1;
        local_8 = 0;
        FUN_004cc3a0(param_1,*(int *)(in_ECX + 8) + param_2 * -0x74,local_8c);
      }
      else {
        iVar6 = iVar2 + param_2 * -0x74;
        uVar4 = FUN_004cbc20(iVar6,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_004cc300(param_1,iVar6,iVar2,param_1);
        FUN_004cc3a0(param_1,iVar1 + param_1,local_8c);
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_004cbdd0();
  ExceptionList = local_10;
  return;
}


// ==== Catch@004cc5f6 @ 0x004cc5f6 ====

void Catch_004cc5f6(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + 0x10);
  FUN_004cbd60(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@004cc6bd @ 0x004cc6bd ====

void Catch_004cc6bd(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x74;
  FUN_004cbd60(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004cc750 @ 0x004cc750 ====

void FUN_004cc750(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980da8;
  local_c = ExceptionList;
  iVar2 = *(int *)(in_ECX + 4);
  local_4 = 0;
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x74;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x74;
    }
    ExceptionList = &local_c;
    FUN_004cc420(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
  }
  else {
    ExceptionList = &local_c;
    if (iVar2 != 0) {
      ExceptionList = &local_c;
      if (param_1 < (uint)((*(int *)(in_ECX + 8) - iVar2) / 0x74)) {
        ExceptionList = &local_c;
        FUN_004cbe20(&param_1,iVar2 + param_1 * 0x74,*(int *)(in_ECX + 8));
      }
    }
  }
  local_4 = 0xffffffff;
  FUN_004cbdd0();
  ExceptionList = local_c;
  return;
}


// ==== FUN_004cc840 @ 0x004cc840 ====

void FUN_004cc840(undefined4 param_1)

{
  undefined1 auStack_78 [104];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 *local_4;
  
  local_4 = auStack_78;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  FUN_004cc750(param_1);
  return;
}


// ==== FUN_004cc8c0 @ 0x004cc8c0 ====

int FUN_004cc8c0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0x44) - *(int *)(in_ECX + 0x40);
}


// ==== FUN_004cc8d0 @ 0x004cc8d0 ====

void FUN_004cc8d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae824;
  return;
}


// ==== FUN_004cc930 @ 0x004cc930 ====

void FUN_004cc930(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae824;
  return;
}


// ==== FUN_004cc940 @ 0x004cc940 ====

void FUN_004cc940(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b0de4;
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  return;
}


// ==== FUN_004cc960 @ 0x004cc960 ====

undefined4 FUN_004cc960(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x40) == 0) || (*(int *)(in_ECX + 0x44) == *(int *)(in_ECX + 0x40))) {
    return 0;
  }
  return *(undefined4 *)(in_ECX + 0x40);
}


// ==== FUN_004cc980 @ 0x004cc980 ====

int FUN_004cc980(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    return 0;
  }
  if (*(int *)(iVar2 + 0x40) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(int *)(iVar2 + 0x44) - *(int *)(iVar2 + 0x40);
  }
  uVar1 = *(uint *)(in_ECX + 8);
  if (uVar3 <= uVar1) {
    return 0;
  }
  if (*(int *)(iVar2 + 0x40) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(int *)(iVar2 + 0x44) - *(int *)(iVar2 + 0x40);
  }
  if (uVar3 < uVar1 + param_1) {
    if (*(int *)(iVar2 + 0x40) == 0) {
      param_1 = 0;
    }
    else {
      param_1 = *(int *)(iVar2 + 0x44) - *(int *)(iVar2 + 0x40);
    }
    param_1 = param_1 - uVar1;
    if ((*(int *)(iVar2 + 0x40) == 0) || (*(int *)(iVar2 + 0x44) == *(int *)(iVar2 + 0x40))) {
      iVar2 = 0;
      goto LAB_004cca0c;
    }
  }
  else if ((*(int *)(iVar2 + 0x40) == 0) || (*(int *)(iVar2 + 0x44) == *(int *)(iVar2 + 0x40))) {
    iVar2 = 0;
    goto LAB_004cca0c;
  }
  iVar2 = *(int *)(iVar2 + 0x40);
LAB_004cca0c:
  FUN_00403e60(param_2,uVar1 + iVar2,param_1);
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
  return param_1;
}


// ==== FUN_004ccac0 @ 0x004ccac0 ====

void FUN_004ccac0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b0e04;
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


// ==== FUN_004ccb00 @ 0x004ccb00 ====

int FUN_004ccb00(int param_1,int param_2)

{
  code *pcVar1;
  int extraout_EAX;
  int in_ECX;
  int iVar2;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00980dc8;
  local_c = ExceptionList;
  if ((param_1 == 1) || (param_1 == 2)) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    ExceptionList = &local_c;
    FUN_00401740(s_GFALSE_009b0dcc,6);
    local_4 = 0;
    FUN_00406880(local_28);
    if (local_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      iVar2 = (*pcVar1)();
      return iVar2;
    }
    _free(local_24);
    return extraout_EAX;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 0x40) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x44) - *(int *)(iVar2 + 0x40);
    }
    if (param_2 <= iVar2) {
      *(int *)(in_ECX + 8) = param_2;
      return param_2;
    }
  }
  return 0;
}


// ==== FUN_004ccbc0 @ 0x004ccbc0 ====

void FUN_004ccbc0(void)

{
  code *pcVar1;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00980dda;
  pvStack_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s_GFALSE_009b0dd4,6);
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


// ==== FUN_004ccc40 @ 0x004ccc40 ====

undefined4 FUN_004ccc40(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 6) {
    uVar2 = (**(code **)(*param_1 + 0x10))();
    *(undefined4 *)(in_ECX + 0x28) = uVar2;
    *(undefined4 *)(in_ECX + 0x34) = 2;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    iVar1 = FUN_00426450();
    iVar3 = (**(code **)(*param_1 + 0x10))();
    FUN_00426510(*(undefined4 *)(in_ECX + 0x44),iVar1,iVar3 + iVar1,param_1);
    (**(code **)*param_1)(1);
    return 1;
  }
  return 0;
}


// ==== FUN_004cccb0 @ 0x004cccb0 ====

undefined4 FUN_004cccb0(int param_1,int param_2)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  FUN_00426510(*(undefined4 *)(*(int *)(in_ECX + 4) + 0x44),param_2,param_1 + param_2,param_1);
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_004cccf0 @ 0x004cccf0 ====

void FUN_004cccf0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980df7;
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
  *in_ECX = &PTR_FUN_009b0e04;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  local_4 = 1;
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004ccd80 @ 0x004ccd80 ====

void FUN_004ccd80(byte param_1)

{
  void *in_ECX;
  
  FUN_004cc8d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004ccda0 @ 0x004ccda0 ====

void FUN_004ccda0(byte param_1)

{
  void *in_ECX;
  
  FUN_004cc930();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004ccdc0 @ 0x004ccdc0 ====

void FUN_004ccdc0(byte param_1)

{
  void *in_ECX;
  
  FUN_004ccac0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004ccde0 @ 0x004ccde0 ====

void FUN_004ccde0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b0e80;
  return;
}


// ==== FUN_004ccdf0 @ 0x004ccdf0 ====

void FUN_004ccdf0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b0e80;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004cce80 @ 0x004cce80 ====

uint FUN_004cce80(int param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  undefined3 uVar2;
  int in_ECX;
  uint uVar3;
  
  uVar1 = *(uint *)(in_ECX + 0x24) / *(uint *)(in_ECX + 0x28);
  uVar3 = *(uint *)(in_ECX + 0x24) % *(uint *)(in_ECX + 0x28);
  if (((((param_1 == 1) || (param_1 == 6)) || (param_1 == 7)) && (uVar1 < 0x10)) ||
     (((((param_1 == 0 || (param_1 == 4)) || (param_1 == 5)) &&
       (*(int *)(in_ECX + 0x28) - 0x10U < uVar1)) ||
      (((((param_1 == 2 || (param_1 == 4)) || (param_1 == 6)) && (uVar3 < 0x10)) ||
       ((((param_1 == 3 || (param_1 == 5)) || (param_1 == 7)) &&
        (*(int *)(in_ECX + 0x28) - 0x10U < uVar3)))))))) {
    return uVar1 & 0xffffff00;
  }
  uVar2 = (undefined3)(uVar1 >> 8);
  switch(param_1) {
  case 2:
    *param_2 = uVar3 - 0x10;
    *param_3 = uVar1;
    return CONCAT31(uVar2,1);
  case 3:
    *param_2 = uVar3 + 0x10;
    *param_3 = uVar1;
    return CONCAT31(uVar2,1);
  case 4:
    uVar3 = uVar3 - 0x10;
  case 0:
    *param_2 = uVar3;
    *param_3 = uVar1 + 0x10;
    return CONCAT31((int3)(uVar1 + 0x10 >> 8),1);
  case 5:
    *param_2 = uVar3 + 0x10;
    *param_3 = uVar1 + 0x10;
    return CONCAT31((int3)(uVar1 + 0x10 >> 8),1);
  case 6:
    uVar3 = uVar3 - 0x10;
  case 1:
    *param_2 = uVar3;
    uVar1 = uVar1 - 0x10;
    *param_3 = uVar1;
  default:
    return CONCAT31((int3)(uVar1 >> 8),1);
  case 7:
    *param_2 = uVar3 + 0x10;
    *param_3 = uVar1 - 0x10;
    return CONCAT31((int3)(uVar1 - 0x10 >> 8),1);
  }
}


// ==== FUN_004ccfe0 @ 0x004ccfe0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ccfe0(int param_1)

{
  uint uVar1;
  float *pfVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int in_ECX;
  
  uVar1 = *(int *)(param_1 + 0xc) + 1;
  *(uint *)(in_ECX + 0x28) = uVar1;
  *(uint *)(in_ECX + 0x40) = *(uint *)(in_ECX + 0x30) % uVar1;
  fVar4 = (float)*(int *)(in_ECX + 0x40);
  *(uint *)(in_ECX + 0x44) = *(uint *)(in_ECX + 0x30) / uVar1;
  *(uint *)(in_ECX + 0x48) = *(uint *)(in_ECX + 0x3c) % *(uint *)(in_ECX + 0x28);
  *(uint *)(in_ECX + 0x4c) = *(uint *)(in_ECX + 0x3c) / *(uint *)(in_ECX + 0x28);
  pfVar2 = (float *)(in_ECX + 0x58);
  if (*(int *)(in_ECX + 0x40) < 0) {
    fVar4 = fVar4 + _DAT_0099d104;
  }
  *pfVar2 = fVar4;
  fVar4 = (float)*(int *)(in_ECX + 0x44);
  *(undefined4 *)(in_ECX + 0x5c) = DAT_009b0e88;
  if (*(int *)(in_ECX + 0x44) < 0) {
    fVar4 = fVar4 + _DAT_0099d104;
  }
  *(float *)(in_ECX + 0x60) = fVar4;
  fVar4 = (float)*(int *)(in_ECX + 0x48);
  pfVar3 = (float *)(in_ECX + 100);
  if (*(int *)(in_ECX + 0x48) < 0) {
    fVar4 = fVar4 + _DAT_0099d104;
  }
  *pfVar3 = fVar4;
  fVar4 = (float)*(int *)(in_ECX + 0x4c);
  *(undefined4 *)(in_ECX + 0x68) = DAT_009b0e84;
  if (*(int *)(in_ECX + 0x4c) < 0) {
    fVar4 = fVar4 + _DAT_0099d104;
  }
  *(float *)(in_ECX + 0x6c) = fVar4;
  fVar6 = DAT_0099d0b4;
  fVar4 = *(float *)(in_ECX + 0x5c) - *(float *)(in_ECX + 0x68);
  fVar5 = *(float *)(in_ECX + 0x60) - *(float *)(in_ECX + 0x6c);
  *(float *)(in_ECX + 0x54) =
       SQRT((*pfVar2 - *pfVar3) * (*pfVar2 - *pfVar3) + fVar5 * fVar5 + fVar4 * fVar4) *
       DAT_0099d0b4;
  *(float *)(in_ECX + 0xb8) = (*pfVar3 - *pfVar2) * fVar6 + *pfVar2;
  *(float *)(in_ECX + 0xbc) =
       (*(float *)(in_ECX + 0x68) - *(float *)(in_ECX + 0x5c)) * fVar6 + *(float *)(in_ECX + 0x5c);
  *(float *)(in_ECX + 0xc0) =
       (*(float *)(in_ECX + 0x6c) - *(float *)(in_ECX + 0x60)) * fVar6 + *(float *)(in_ECX + 0x60);
  *(float *)(in_ECX + 0x70) = *pfVar2;
  *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(in_ECX + 0x5c);
  *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(in_ECX + 0x60);
  *(undefined4 *)(in_ECX + 0x7c) = *(undefined4 *)(in_ECX + 100);
  *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(in_ECX + 0x68);
  *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(in_ECX + 0x6c);
  FUN_0040d8a0(pfVar2,pfVar3,in_ECX + 0x88);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(in_ECX + 0x2c);
  return;
}


// ==== FUN_004cd160 @ 0x004cd160 ====

void FUN_004cd160(float param_1,undefined1 *param_2)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
  if (*(char *)(in_ECX + 0x51) == '\0') {
    if (*(char *)(in_ECX + 0x50) != '\0') {
      uVar3 = 0;
      piVar2 = (int *)(*(int *)(in_ECX + 0xc4) + 0x7c);
      while (((((char)piVar2[-0xe] == '\0' || (*piVar2 == 0)) || ((float)piVar2[-0xd] != param_1))
             || (*(int *)(*piVar2 + 0x6c) == 0))) {
        uVar3 = uVar3 + 1;
        piVar2 = piVar2 + 0xf;
        if (1 < uVar3) {
          return;
        }
      }
      *param_2 = 1;
      return;
    }
    iVar1 = *(int *)(in_ECX + 0x10);
    for (iVar4 = *(int *)(in_ECX + 0xc); iVar4 != iVar1; iVar4 = iVar4 + 4) {
      FUN_004cd160(param_1,param_2);
    }
  }
  return;
}


// ==== FUN_004cd1f0 @ 0x004cd1f0 ====

void FUN_004cd1f0(uint param_1,uint param_2)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  
  while (((((*(char *)(in_ECX + 0x50) == '\0' || (param_1 < *(uint *)(in_ECX + 0x40))) ||
           (*(uint *)(in_ECX + 0x48) < param_1)) ||
          ((param_2 < *(uint *)(in_ECX + 0x44) || (*(uint *)(in_ECX + 0x4c) < param_2)))) &&
         ((*(int *)(in_ECX + 0xc) != 0 &&
          (*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc) >> 2 != 0))))) {
    uVar2 = 0;
    while( true ) {
      if (3 < uVar2) {
        return;
      }
      iVar1 = *(int *)(*(int *)(in_ECX + 0xc) + uVar2 * 4);
      if (((*(uint *)(iVar1 + 0x40) <= param_1) && (param_1 <= *(uint *)(iVar1 + 0x48))) &&
         ((*(uint *)(iVar1 + 0x44) <= param_2 && (param_2 <= *(uint *)(iVar1 + 0x4c))))) break;
      uVar2 = uVar2 + 1;
    }
    in_ECX = *(int *)(*(int *)(in_ECX + 0xc) + uVar2 * 4);
  }
  return;
}


// ==== FUN_004cd280 @ 0x004cd280 ====

undefined1 FUN_004cd280(undefined4 param_1,undefined4 param_2,float *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  float local_4;
  
  uVar2 = param_1;
  if (*(char *)(in_ECX + 0x51) != '\0') {
    return 0;
  }
  local_4 = DAT_009b0e8c;
  cVar3 = FUN_0040dfb0(param_1,in_ECX + 0x70,in_ECX + 0x7c,&local_4);
  if (cVar3 == '\0') {
    return 0;
  }
  if (local_4 < *param_3) {
    if (*(char *)(in_ECX + 0x50) == '\0') {
      piVar4 = *(int **)(in_ECX + 0xc);
      piVar1 = *(int **)(in_ECX + 0x10);
      param_1._0_1_ = 0;
      if (piVar4 != piVar1) {
        param_1._0_1_ = 0;
        do {
          if ((*piVar4 != 0) && (cVar3 = FUN_004cd280(uVar2,param_2,param_3), cVar3 != '\0')) {
            param_1._0_1_ = 1;
          }
          piVar4 = piVar4 + 1;
        } while (piVar4 != piVar1);
      }
      return (undefined1)param_1;
    }
    piVar4 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar5 = (**(code **)(*piVar4 + 0x1c))();
    if (*(int *)(iVar5 + 8) == 0) {
      cVar3 = FUN_004d2a00(param_1,*(int *)(in_ECX + 0xc4) + 0x1c,&local_4);
    }
    else {
      cVar3 = FUN_004d28c0(param_1,*(int *)(in_ECX + 0xc4) + 0xc,&local_4);
    }
    if (cVar3 != '\0') {
      if (*param_3 <= local_4 && local_4 != *param_3) {
        local_4 = *param_3;
      }
      *param_3 = local_4;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_004cd390 @ 0x004cd390 ====

undefined4 FUN_004cd390(undefined1 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined1 local_4 [4];
  
  piVar1 = (int *)FUN_006e5150(local_4,&param_1);
  if (*piVar1 == *(int *)(in_ECX + 0x1c)) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 0x10);
}


// ==== FUN_004cd3c0 @ 0x004cd3c0 ====

void FUN_004cd3c0(undefined1 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x50) != '\0') {
    iVar3 = FUN_004d2550(in_ECX + 0x40,param_2,param_3);
    iVar1 = *(int *)(in_ECX + 0xc4);
    FUN_00558e70(&param_3,&param_1);
    if (param_3 != *(int *)(iVar1 + 0x3c)) {
      piVar2 = *(int **)(param_3 + 0x18);
      piVar4 = *(int **)(param_3 + 0x14);
      if (piVar4 != piVar2) {
        do {
          if (*piVar4 == iVar3) break;
          piVar4 = piVar4 + 1;
        } while (piVar4 != piVar2);
        if (piVar4 != piVar2) {
          FUN_00598f00(&param_3,piVar4);
        }
      }
    }
  }
  return;
}


// ==== FUN_004cd430 @ 0x004cd430 ====

void FUN_004cd430(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  ushort uVar4;
  undefined4 local_1c;
  undefined4 local_18 [2];
  ushort local_10 [2];
  int local_c;
  
  if (*(char *)(in_ECX + 0x50) == '\0') {
    iVar2 = *(int *)(in_ECX + 0x10);
    for (iVar3 = *(int *)(in_ECX + 0xc); iVar3 != iVar2; iVar3 = iVar3 + 4) {
      FUN_004cd430(param_1);
    }
    return;
  }
  uVar4 = 0;
  iVar3 = 0;
  do {
    local_18[0] = 0;
    local_1c = 0;
    cVar1 = FUN_004cce80(iVar3,local_18,&local_1c);
    if ((cVar1 != '\0') && (iVar2 = FUN_004cd1f0(local_18[0],local_1c), iVar2 != 0)) {
      local_10[0] = uVar4;
      local_c = iVar2;
      FUN_004d0340(local_18,local_10);
    }
    uVar4 = uVar4 + 1;
    iVar3 = iVar3 + 1;
  } while (uVar4 < 8);
  return;
}


// ==== FUN_004cd4e0 @ 0x004cd4e0 ====

void FUN_004cd4e0(void)

{
  float *pfVar1;
  float *pfVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float local_20;
  float local_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_4;
  
  local_20 = DAT_0099d0f0;
  local_1c = DAT_0099d0e8;
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar4 = (**(code **)(*piVar3 + 0x1c))();
  piVar3 = *(int **)(in_ECX + 0xc4);
  if (*(int *)(iVar4 + 8) == 0) {
    iVar4 = 0;
    if (piVar3[8] != 0) {
      iVar4 = (piVar3[9] - piVar3[8]) / 0x24;
    }
    *piVar3 = iVar4;
    piVar3 = *(int **)(in_ECX + 0xc4);
    pfVar2 = (float *)piVar3[8];
    fStack_18 = *pfVar2;
    iVar4 = piVar3[8];
    fStack_10 = pfVar2[2];
    uVar6 = *piVar3 - 2;
    if ((iVar4 == 0) || ((uint)((piVar3[9] - iVar4) / 0x24) <= uVar6)) {
      FUN_004cfa80();
      return;
    }
    fStack_c = *(float *)(iVar4 + uVar6 * 0x24);
    iVar4 = iVar4 + uVar6 * 0x24;
    fStack_4 = *(float *)(iVar4 + 8);
    fVar9 = pfVar2[1] - *(float *)(iVar4 + 4);
    *(float *)(in_ECX + 0x54) =
         SQRT((fStack_18 - fStack_c) * (fStack_18 - fStack_c) +
              fVar9 * fVar9 + (fStack_10 - fStack_4) * (fStack_10 - fStack_4)) * DAT_0099d0b4;
    for (iVar4 = piVar3[8]; iVar4 != piVar3[9]; iVar4 = iVar4 + 0x24) {
      fVar9 = *(float *)(iVar4 + 4);
      if (fVar9 < local_20) {
        local_20 = fVar9;
      }
      if (local_1c <= fVar9) {
        local_1c = fVar9;
      }
    }
  }
  else {
    iVar4 = 0;
    if (piVar3[4] != 0) {
      iVar4 = (piVar3[5] - piVar3[4]) / 0x30;
    }
    *piVar3 = iVar4;
    piVar3 = *(int **)(in_ECX + 0xc4);
    pfVar2 = (float *)piVar3[4];
    fStack_18 = *pfVar2;
    iVar4 = piVar3[4];
    fStack_10 = pfVar2[2];
    if ((iVar4 == 0) || ((uint)((piVar3[5] - iVar4) / 0x30) <= *piVar3 - 2U)) {
      FUN_004cfa80();
      return;
    }
    iVar5 = (*piVar3 - 2U) * 0x30;
    fStack_c = *(float *)(iVar5 + iVar4);
    fStack_4 = *(float *)(iVar5 + iVar4 + 8);
    fVar9 = pfVar2[1] - *(float *)(iVar5 + 4 + iVar4);
    *(float *)(in_ECX + 0x54) =
         SQRT((fStack_18 - fStack_c) * (fStack_18 - fStack_c) +
              fVar9 * fVar9 + (fStack_10 - fStack_4) * (fStack_10 - fStack_4)) * DAT_0099d0b4;
    for (iVar4 = piVar3[4]; iVar4 != piVar3[5]; iVar4 = iVar4 + 0x30) {
      fVar9 = *(float *)(iVar4 + 4);
      if (fVar9 < local_20) {
        local_20 = fVar9;
      }
      if (local_1c <= fVar9) {
        local_1c = fVar9;
      }
    }
  }
  fVar9 = DAT_0099d0b4;
  fVar7 = (local_1c - local_20) * DAT_0099d0b4;
  if (fVar7 < *(float *)(in_ECX + 0x54)) {
    fVar7 = *(float *)(in_ECX + 0x54);
  }
  *(float *)(in_ECX + 0x54) = fVar7 + DAT_0099d0f8;
  fVar7 = fStack_10;
  if (fStack_10 <= fStack_4) {
    fVar7 = fStack_4;
  }
  fVar8 = fStack_18;
  if (fStack_18 <= fStack_c) {
    fVar8 = fStack_c;
  }
  pfVar2 = (float *)(in_ECX + 100);
  *pfVar2 = fVar8;
  *(float *)(in_ECX + 0x68) = local_1c;
  *(float *)(in_ECX + 0x6c) = fVar7;
  if (fStack_4 < fStack_10) {
    fStack_10 = fStack_4;
  }
  if (fStack_18 <= fStack_c) {
    fStack_c = fStack_18;
  }
  pfVar1 = (float *)(in_ECX + 0x58);
  *pfVar1 = fStack_c;
  *(float *)(in_ECX + 0x5c) = local_20;
  *(float *)(in_ECX + 0x60) = fStack_10;
  *(float *)(in_ECX + 0xb8) = (*pfVar2 - *pfVar1) * fVar9 + *pfVar1;
  *(float *)(in_ECX + 0xbc) =
       (*(float *)(in_ECX + 0x68) - *(float *)(in_ECX + 0x5c)) * fVar9 + *(float *)(in_ECX + 0x5c);
  *(float *)(in_ECX + 0xc0) =
       (*(float *)(in_ECX + 0x6c) - *(float *)(in_ECX + 0x60)) * fVar9 + *(float *)(in_ECX + 0x60);
  fVar9 = *(float *)(in_ECX + 0x68) + DAT_0099de80;
  *(float *)(in_ECX + 0x70) = *pfVar1;
  *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(in_ECX + 0x5c);
  *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(in_ECX + 0x60);
  *(undefined4 *)(in_ECX + 0x7c) = *(undefined4 *)(in_ECX + 100);
  *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(in_ECX + 0x68);
  *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(in_ECX + 0x6c);
  *(float *)(in_ECX + 0x68) = fVar9;
  FUN_0040d8a0(pfVar1,pfVar2,in_ECX + 0x88);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(in_ECX + 0x2c);
  return;
}


// ==== FUN_004cd8b0 @ 0x004cd8b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cd8b0(uint param_1,float *param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int in_ECX;
  uint uVar8;
  uint uVar9;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  float local_4;
  
  iVar2 = param_1 * 0x3c;
  iVar7 = *(int *)(in_ECX + 0xc4) + iVar2;
  if ((*(int *)(iVar7 + 0x50) == 0) ||
     ((*(int *)(iVar7 + 0x54) - *(int *)(iVar7 + 0x50)) / 0x24 == 0)) {
    iVar7 = *(int *)(*(int *)(in_ECX + 200) + 0xc0);
    uVar6 = (uint)(ushort)((*(short *)(in_ECX + 0x48) - *(short *)(in_ECX + 0x40)) + 1);
    FUN_004d0400(uVar6 * uVar6);
    uVar6 = *(uint *)(in_ECX + 0x44);
    if (uVar6 <= *(uint *)(in_ECX + 0x4c)) {
      uVar8 = *(uint *)(in_ECX + 0x48);
      do {
        uVar5 = DAT_0099d080;
        uVar9 = *(uint *)(in_ECX + 0x40);
        if (uVar9 <= uVar8) {
          fVar3 = (float)(int)uVar6;
          if ((int)uVar6 < 0) {
            fVar3 = fVar3 + _DAT_0099d104;
          }
          fVar4 = fVar3 * _DAT_009b0e90;
          do {
            local_24 = (float)(int)uVar9;
            if ((int)uVar9 < 0) {
              local_24 = local_24 + _DAT_0099d104;
            }
            local_8 = local_24 * _DAT_009b0e90;
            local_20 = *param_2;
            local_14 = 0;
            local_10 = uVar5;
            local_c = 0;
            if (iVar7 != 0) {
              local_18 = *(undefined4 *)
                          (*(int *)(iVar7 + 0x2c) + (*(int *)(in_ECX + 0x28) * uVar6 + uVar9) * 4);
            }
            local_1c = fVar3;
            local_4 = fVar4;
            FUN_004d0ee0(&local_24);
            uVar8 = *(uint *)(in_ECX + 0x48);
            uVar9 = uVar9 + 1;
          } while (uVar9 <= uVar8);
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 <= *(uint *)(in_ECX + 0x4c));
    }
    *(undefined1 *)(iVar2 + 0x44 + *(int *)(in_ECX + 0xc4)) = 1;
  }
  else {
    if (*(float *)(iVar7 + 0x48) == *param_2) {
      return;
    }
    iVar1 = *(int *)(iVar7 + 0x54);
    for (iVar7 = *(int *)(iVar7 + 0x50); iVar7 != iVar1; iVar7 = iVar7 + 0x24) {
      *(float *)(iVar7 + 4) = *param_2;
    }
    param_1 = *(uint *)(in_ECX + 0x44);
    if (param_1 < *(uint *)(in_ECX + 0x4c)) {
      do {
        uVar6 = *(uint *)(in_ECX + 0x40);
        if (uVar6 < *(uint *)(in_ECX + 0x48)) {
          do {
            iVar7 = *(int *)(in_ECX + 200);
            iVar1 = *(int *)(iVar7 + 0x50);
            uVar8 = *(int *)(iVar7 + 0x40) * param_1 + uVar6;
            if ((iVar1 == 0) || ((uint)(*(int *)(iVar7 + 0x54) - iVar1 >> 2) <= uVar8)) {
LAB_004cdb20:
                    /* WARNING: Subroutine does not return */
              FUN_0042f370();
            }
            if (*(float *)(iVar1 + uVar8 * 4) == *(float *)(*(int *)(in_ECX + 0xc4) + 0x48 + iVar2))
            {
              iVar7 = *(int *)(*(int *)(in_ECX + 200) + 0x50);
              if ((iVar7 == 0) ||
                 ((uint)(*(int *)(*(int *)(in_ECX + 200) + 0x54) - iVar7 >> 2) <= uVar8))
              goto LAB_004cdb20;
              *(float *)(iVar7 + uVar8 * 4) = *param_2;
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 < *(uint *)(in_ECX + 0x48));
        }
        param_1 = param_1 + 1;
      } while (param_1 < *(uint *)(in_ECX + 0x4c));
    }
  }
  *(float *)(*(int *)(in_ECX + 0xc4) + 0x48 + iVar2) = *param_2;
  return;
}


// ==== FUN_004cdb30 @ 0x004cdb30 ====

void FUN_004cdb30(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  int in_ECX;
  int iVar5;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar2 = param_2;
  local_10 = *(undefined4 *)(in_ECX + 100);
  local_c = *(undefined4 *)(in_ECX + 0x6c);
  local_8 = *(undefined4 *)(in_ECX + 0x58);
  local_4 = *(undefined4 *)(in_ECX + 0x60);
  cVar4 = FUN_0040eed0(param_1,param_2,&local_8,&local_10);
  uVar3 = param_3;
  if (cVar4 != '\0') {
    if (*(char *)(in_ECX + 0x50) != '\0') {
      param_1 = *(undefined4 *)(in_ECX + 0x2c);
      FUN_00430ce0(&param_1);
      return;
    }
    iVar1 = *(int *)(in_ECX + 0x10);
    for (iVar5 = *(int *)(in_ECX + 0xc); iVar5 != iVar1; iVar5 = iVar5 + 4) {
      FUN_004cdb30(param_1,uVar2,uVar3);
    }
  }
  return;
}


// ==== FUN_004cdbe0 @ 0x004cdbe0 ====

void FUN_004cdbe0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  undefined4 local_4;
  
  *(undefined1 *)(in_ECX + 0x51) = 0;
  if (*(char *)(in_ECX + 0x50) != '\0') {
    local_4 = *(undefined4 *)(in_ECX + 0x2c);
    FUN_00430ce0(&local_4);
    return;
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  for (iVar2 = *(int *)(in_ECX + 0xc); iVar2 != iVar1; iVar2 = iVar2 + 4) {
    FUN_004cdbe0(param_1);
  }
  return;
}


// ==== FUN_004cdce0 @ 0x004cdce0 ====

undefined4 FUN_004cdce0(int param_1,int param_2,float *param_3)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x50) != '\0') {
    if (DAT_009af6c0 != *param_3) {
      FUN_004cd8b0(param_1,param_3);
      param_1 = param_1 * 0x3c;
      piVar1 = (int *)(*(int *)(in_ECX + 0xc4) + 0x7c + param_1);
      iVar2 = *piVar1;
      if (iVar2 == 0) {
        *piVar1 = param_2;
        return 1;
      }
      if (iVar2 != param_2) {
        (**(code **)(*DAT_00b5a7cc + 0x14))(iVar2);
        *(undefined4 *)(*(int *)(in_ECX + 0xc4) + 0x7c + param_1) = 0;
        *(int *)(*(int *)(in_ECX + 0xc4) + 0x7c + param_1) = param_2;
        return 0;
      }
      if (param_2 != 0) {
        (**(code **)(*DAT_00b5a7cc + 0x14))(param_2);
      }
      return 1;
    }
  }
  return 1;
}


// ==== FUN_004cdd90 @ 0x004cdd90 ====

void FUN_004cdd90(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined4 in_EDX;
  int iVar3;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  local_8 = *(int *)(in_ECX + 0xc4) + param_1 * 0x3c;
  if (*(char *)(local_8 + 0x44) != '\0') {
    iVar3 = CONCAT22((short)((uint)in_EDX >> 0x10),(short)param_3 - *(short *)(in_ECX + 0x44));
    local_10 = CONCAT22((short)((uint)in_ECX >> 0x10),(short)param_2 - *(short *)(in_ECX + 0x40));
    iVar1 = CONCAT22((short)((uint)local_8 >> 0x10),
                     *(short *)(in_ECX + 0x48) - *(short *)(in_ECX + 0x40)) + 1;
    local_c = iVar3 * iVar1 + local_10;
    local_10 = local_10 + (iVar3 + 1) * iVar1;
    local_4 = local_10 + 1;
    param_1 = local_c + 1;
    FUN_004275a0(&local_c);
    FUN_004275a0(&local_10);
    FUN_004275a0(&param_1);
    FUN_004275a0(&param_1);
    FUN_004275a0(&local_10);
    FUN_004275a0(&local_4);
    piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar1 = (**(code **)(*piVar2 + 0x1c))();
    if (*(int *)(iVar1 + 4) == 0) {
      param_3 = FUN_004d2550(in_ECX + 0x40,param_2,param_3);
      FUN_00430ce0(&param_3);
    }
  }
  return;
}


// ==== FUN_004cded0 @ 0x004cded0 ====

void FUN_004cded0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 ****ppppuVar5;
  undefined4 ****ppppuVar6;
  undefined4 *puVar7;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  int *piStack_4c;
  int iStack_48;
  undefined4 ****appppuStack_40 [4];
  int iStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *apvStack_24 [4];
  undefined4 uStack_14;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00980ea8;
  local_c = ExceptionList;
  iVar2 = param_1 * 0x3c;
  iVar3 = *(int *)(in_ECX + 0xc4) + iVar2;
  if (((*(char *)(iVar3 + 0x44) != '\0') && (*(int *)(iVar3 + 0x70) != 0)) &&
     (param_1 = *(int *)(iVar3 + 0x74) - *(int *)(iVar3 + 0x70) >> 2, param_1 != 0)) {
    ExceptionList = &local_c;
    uVar4 = (**(code **)(**(int **)(*(int *)(in_ECX + 0xc4) + 0x7c + iVar2) + 4))();
    uStack_2c = 0xf;
    iStack_30 = 0;
    appppuStack_40[0] = (undefined4 ****)((uint)appppuStack_40[0] & 0xffffff00);
    FUN_00401660(uVar4,0,0xffffffff);
    uStack_4 = 0;
    iVar3 = FUN_00405920(&DAT_009b0e74,0xffffffff,1);
    uStack_10 = 0xf;
    uStack_14 = 0;
    apvStack_24[0] = (void *)((uint)apvStack_24[0] & 0xffffff00);
    uStack_4._0_1_ = 1;
    ppppuVar6 = appppuStack_40[0];
    if (uStack_2c < 0x10) {
      ppppuVar6 = appppuStack_40;
    }
    ppppuVar5 = appppuStack_40[0];
    if (uStack_2c < 0x10) {
      ppppuVar5 = appppuStack_40;
    }
    FUN_00430560(apvStack_24,apvStack_24,iVar3 + 1 + (int)ppppuVar5,(int)ppppuVar6 + iStack_30,
                 param_1);
    pvStack_50 = (void *)0x0;
    piStack_4c = (int *)0x0;
    iStack_48 = 0;
    puVar7 = *(undefined4 **)(*(int *)(in_ECX + 0xc4) + 0x70 + iVar2);
    puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0xc4) + iVar2 + 0x74);
    uStack_4 = CONCAT31(uStack_4._1_3_,2);
    for (; puVar7 != puVar1; puVar7 = puVar7 + 1) {
      param_1 = FUN_004d2570(in_ECX + 0x40,*puVar7,*(int *)(in_ECX + 0x28) + -1);
      if ((pvStack_50 == (void *)0x0) ||
         ((uint)(iStack_48 - (int)pvStack_50 >> 2) <= (uint)((int)piStack_4c - (int)pvStack_50 >> 2)
         )) {
        FUN_0042f3e0(piStack_4c,1,&param_1);
      }
      else {
        *piStack_4c = param_1;
        piStack_4c = piStack_4c + 1;
      }
    }
    FUN_0042e2e0(*(undefined4 *)(in_ECX + 0x24),auStack_28,*(int *)(in_ECX + 0xc4) + 0x48 + iVar2,
                 auStack_54);
    if (pvStack_50 != (void *)0x0) {
      _free(pvStack_50);
      return;
    }
    pvStack_50 = (void *)0x0;
    piStack_4c = (int *)0x0;
    iStack_48 = 0;
    if (0xf < uStack_10) {
      _free(apvStack_24[0]);
      return;
    }
    uStack_10 = 0xf;
    uStack_14 = 0;
    apvStack_24[0] = (void *)((uint)apvStack_24[0] & 0xffffff00);
    if (0xf < uStack_2c) {
      _free(appppuStack_40[0]);
      return;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004ce0f0 @ 0x004ce0f0 ====

void FUN_004ce0f0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  undefined1 local_4 [4];
  
  if (*(char *)(in_ECX + 0x51) == '\0') {
    if (*(char *)(in_ECX + 0x50) != '\0') {
      FUN_004d1140(local_4);
      return;
    }
    iVar1 = *(int *)(in_ECX + 0x10);
    for (iVar2 = *(int *)(in_ECX + 0xc); iVar2 != iVar1; iVar2 = iVar2 + 4) {
      FUN_004ce0f0(param_1);
    }
  }
  return;
}


// ==== FUN_004ce140 @ 0x004ce140 ====

void FUN_004ce140(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  undefined4 local_4;
  
  if (*(char *)(in_ECX + 0x51) == '\0') {
    if (*(char *)(in_ECX + 0x50) == '\0') {
      iVar4 = *(int *)(in_ECX + 0x10);
      for (iVar5 = *(int *)(in_ECX + 0xc); iVar5 != iVar4; iVar5 = iVar5 + 4) {
        FUN_004ce140(param_1);
      }
    }
    else {
      FUN_004d1140(&local_4);
      piVar1 = *(int **)(in_ECX + 0x1c);
      piVar2 = (int *)*piVar1;
      if (piVar2 != piVar1) {
        do {
          iVar5 = *(int *)(param_1 + 4);
          local_4 = piVar2[4];
          if ((iVar5 == 0) ||
             ((uint)(*(int *)(param_1 + 0xc) - iVar5 >> 2) <=
              (uint)(*(int *)(param_1 + 8) - iVar5 >> 2))) {
            FUN_004d04f0(*(undefined4 *)(param_1 + 8),1,&local_4);
          }
          else {
            puVar3 = *(undefined4 **)(param_1 + 8);
            *puVar3 = local_4;
            *(undefined4 **)(param_1 + 8) = puVar3 + 1;
          }
          FUN_00458720();
        } while (piVar2 != piVar1);
        return;
      }
    }
  }
  return;
}


// ==== FUN_004ce210 @ 0x004ce210 ====

void FUN_004ce210(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980ec8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009b0e98;
  in_ECX[1] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  local_4 = 0;
  iVar3 = FUN_0058d7c0();
  in_ECX[7] = iVar3;
  *(undefined1 *)(iVar3 + 0x15) = 1;
  *(undefined4 *)(in_ECX[7] + 4) = in_ECX[7];
  *(undefined4 *)in_ECX[7] = in_ECX[7];
  *(undefined4 *)(in_ECX[7] + 8) = in_ECX[7];
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)((int)in_ECX + 0x51) = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x31] = 0;
  in_ECX[0x32] = param_1;
  local_4 = CONCAT31(local_4._1_3_,1);
  if ((void *)in_ECX[3] == (void *)0x0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    FUN_004cf640(*(undefined4 *)(in_ECX[7] + 4));
    uVar1 = DAT_0099d0e8;
    *(undefined4 *)(in_ECX[7] + 4) = in_ECX[7];
    in_ECX[8] = 0;
    *(undefined4 *)in_ECX[7] = in_ECX[7];
    *(undefined4 *)(in_ECX[7] + 8) = in_ECX[7];
    in_ECX[0x19] = uVar1;
    in_ECX[0x1a] = uVar1;
    uVar2 = DAT_0099d0f0;
    in_ECX[0x1b] = uVar1;
    in_ECX[0x16] = uVar2;
    in_ECX[0x17] = uVar2;
    in_ECX[0x18] = uVar2;
    iVar4 = (param_2 + 1) * param_3;
    in_ECX[0xe] = iVar4;
    iVar3 = (param_3 + 1) * (param_2 + 1) + -1;
    iVar4 = iVar4 + iVar3 + param_2;
    in_ECX[0xf] = iVar3;
    in_ECX[0xb] = (int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2;
    in_ECX[0xc] = 0;
    in_ECX[0xd] = param_2;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_004ce380 @ 0x004ce380 ====

void FUN_004ce380(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00980ee8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009b0e98;
  in_ECX[1] = param_2;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  local_4 = 0;
  iVar3 = FUN_0058d7c0();
  in_ECX[7] = iVar3;
  *(undefined1 *)(iVar3 + 0x15) = 1;
  *(undefined4 *)(in_ECX[7] + 4) = in_ECX[7];
  *(undefined4 *)in_ECX[7] = in_ECX[7];
  *(undefined4 *)(in_ECX[7] + 8) = in_ECX[7];
  in_ECX[8] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  in_ECX[0xb] = 0;
  *(undefined1 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)((int)in_ECX + 0x51) = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x31] = 0;
  in_ECX[0x32] = param_1;
  if ((void *)in_ECX[3] == (void *)0x0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    FUN_004cf640(*(undefined4 *)(in_ECX[7] + 4));
    uVar1 = DAT_0099d0e8;
    *(undefined4 *)(in_ECX[7] + 4) = in_ECX[7];
    in_ECX[8] = 0;
    *(undefined4 *)in_ECX[7] = in_ECX[7];
    *(undefined4 *)(in_ECX[7] + 8) = in_ECX[7];
    in_ECX[0x19] = uVar1;
    in_ECX[0x1a] = uVar1;
    uVar2 = DAT_0099d0f0;
    in_ECX[0x1b] = uVar1;
    in_ECX[0x16] = uVar2;
    in_ECX[0x17] = uVar2;
    in_ECX[0x18] = uVar2;
    in_ECX[0xc] = 0;
    in_ECX[0xd] = 0;
    in_ECX[0xe] = 0;
    in_ECX[0xf] = 0;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_004ce4d0 @ 0x004ce4d0 ====

int FUN_004ce4d0(int param_1,int param_2,int param_3,int param_4)

{
  void *pvVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00980efd;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0xcc);
  iVar3 = 0;
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    iVar3 = FUN_004ce380(*(undefined4 *)(in_ECX + 200),in_ECX);
  }
  *(int *)(iVar3 + 0x30) = param_1;
  iVar2 = param_1 + param_2 + param_3 + param_4;
  *(int *)(iVar3 + 0x34) = param_2;
  *(int *)(iVar3 + 0x2c) = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
  *(int *)(iVar3 + 0x38) = param_3;
  *(int *)(iVar3 + 0x3c) = param_4;
  ExceptionList = local_c;
  return iVar3;
}


// ==== FUN_004ce560 @ 0x004ce560 ====

undefined4 FUN_004ce560(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int in_ECX;
  int iVar9;
  
  FUN_004ccfe0(param_1);
  iVar1 = *(int *)(in_ECX + 0x34);
  iVar2 = *(int *)(in_ECX + 0x30);
  iVar4 = *(int *)(in_ECX + 0x38) + *(int *)(in_ECX + 0x3c);
  iVar5 = iVar4 / 2;
  iVar6 = (*(int *)(in_ECX + 0x38) + iVar2) / 2;
  iVar7 = (*(int *)(in_ECX + 0x3c) + iVar1) / 2;
  iVar4 = iVar4 + iVar2 + iVar1;
  iVar9 = (iVar2 + iVar1) / 2;
  iVar4 = (int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2;
  if ((uint)(iVar1 - iVar2) < 0x11) {
    return 0;
  }
  FUN_004d0e50(4,0);
  puVar3 = *(undefined4 **)(in_ECX + 0xc);
  uVar8 = FUN_004ce4d0(*(undefined4 *)(in_ECX + 0x30),iVar9,iVar6,iVar4);
  *puVar3 = uVar8;
  iVar1 = *(int *)(in_ECX + 0xc);
  uVar8 = FUN_004ce4d0(iVar9,*(undefined4 *)(in_ECX + 0x34),iVar4,iVar7);
  *(undefined4 *)(iVar1 + 4) = uVar8;
  iVar1 = *(int *)(in_ECX + 0xc);
  uVar8 = FUN_004ce4d0(iVar6,iVar4,*(undefined4 *)(in_ECX + 0x38),iVar5);
  *(undefined4 *)(iVar1 + 8) = uVar8;
  iVar1 = *(int *)(in_ECX + 0xc);
  uVar8 = FUN_004ce4d0(iVar4,iVar7,iVar5,*(undefined4 *)(in_ECX + 0x3c));
  *(undefined4 *)(iVar1 + 0xc) = uVar8;
  return 1;
}


// ==== FUN_004ce660 @ 0x004ce660 ====

void FUN_004ce660(undefined4 param_1,float *param_2,undefined4 param_3,float *param_4,float param_5)

{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  undefined4 uVar5;
  int iVar6;
  int in_ECX;
  float fVar7;
  float fVar8;
  
  fVar8 = *param_4 - *(float *)(in_ECX + 0xb8);
  fVar7 = param_4[1] - *(float *)(in_ECX + 0xc0);
  if (param_5 < SQRT(fVar8 * fVar8 + fVar7 * fVar7) - *(float *)(in_ECX + 0x54)) {
    *(undefined1 *)(in_ECX + 0x51) = 1;
    return;
  }
  pfVar1 = (float *)(in_ECX + 100);
  pfVar2 = (float *)(in_ECX + 0x58);
  iVar6 = FUN_0040f280(in_ECX + 0x88,pfVar2,pfVar1,param_1);
  fVar7 = param_5;
  uVar5 = param_3;
  pfVar4 = param_2;
  if (iVar6 == 1) {
    *(undefined1 *)(in_ECX + 0x51) = 1;
    return;
  }
  if (iVar6 == 0) {
    if (*pfVar2 < *param_2 || *pfVar2 == *param_2) {
      fVar7 = *pfVar2;
    }
    else {
      fVar7 = *param_2;
    }
    *param_2 = fVar7;
    if (*(float *)(in_ECX + 0x5c) < param_2[1] || *(float *)(in_ECX + 0x5c) == param_2[1]) {
      fVar7 = *(float *)(in_ECX + 0x5c);
    }
    else {
      fVar7 = param_2[1];
    }
    param_2[1] = fVar7;
    if (*(float *)(in_ECX + 0x60) < param_2[2] || *(float *)(in_ECX + 0x60) == param_2[2]) {
      fVar7 = *(float *)(in_ECX + 0x60);
    }
    else {
      fVar7 = param_2[2];
    }
    param_2[2] = fVar7;
    fVar7 = param_2[3];
    if (fVar7 < *pfVar1 || fVar7 == *pfVar1) {
      fVar7 = *pfVar1;
    }
    param_2[3] = fVar7;
    fVar7 = param_2[4];
    if (fVar7 < *(float *)(in_ECX + 0x68) || fVar7 == *(float *)(in_ECX + 0x68)) {
      fVar7 = *(float *)(in_ECX + 0x68);
    }
    param_2[4] = fVar7;
    fVar7 = param_2[5];
    if (fVar7 < *(float *)(in_ECX + 0x6c) || fVar7 == *(float *)(in_ECX + 0x6c)) {
      fVar7 = *(float *)(in_ECX + 0x6c);
    }
    param_2[5] = fVar7;
    FUN_004cdbe0(param_3);
    *(undefined1 *)(in_ECX + 0x51) = 0;
    return;
  }
  if ((iVar6 == 2) && (*(undefined1 *)(in_ECX + 0x51) = 0, *(char *)(in_ECX + 0x50) != '\0')) {
    FUN_0040fab0(param_2,param_2,pfVar2);
    FUN_0040fa50(pfVar4 + 3,pfVar4 + 3,pfVar1);
    param_2 = *(float **)(in_ECX + 0x2c);
    FUN_00430ce0(&param_2);
    return;
  }
  iVar3 = *(int *)(in_ECX + 0x10);
  for (iVar6 = *(int *)(in_ECX + 0xc); iVar6 != iVar3; iVar6 = iVar6 + 4) {
    FUN_004ce660(param_1,param_2,uVar5,param_4,fVar7);
  }
  return;
}


// ==== FUN_004cec00 @ 0x004cec00 ====

void FUN_004cec00(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  if (*(char *)(in_ECX + 0x50) != '\0') {
    FUN_004cded0(0,param_1);
    FUN_004cded0(1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  for (iVar2 = *(int *)(in_ECX + 0xc); iVar2 != iVar1; iVar2 = iVar2 + 4) {
    FUN_004cec00(param_1);
  }
  return;
}


// ==== FUN_004cec50 @ 0x004cec50 ====

void FUN_004cec50(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int in_ECX;
  undefined1 local_38 [8];
  undefined1 local_30 [4];
  void *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [2];
  void *local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00980f31;
  local_c = ExceptionList;
  if (*(char *)(in_ECX + 0x50) != '\0') {
    ExceptionList = &local_c;
    param_3 = FUN_004d2550(in_ECX + 0x40,param_2,param_3);
    iVar1 = *(int *)(in_ECX + 0xc4);
    FUN_00558e70(&param_2,&param_1);
    if (param_2 == *(int *)(iVar1 + 0x3c)) {
      local_2c = (void *)0x0;
      local_28 = 0;
      local_24 = 0;
      local_4 = 0;
      FUN_00430ce0(&param_3);
      local_20[0] = param_1;
      FUN_00430c20(local_30);
      local_4 = CONCAT31(local_4._1_3_,1);
      FUN_004d1af0(local_38,local_20);
      if (local_18 != (void *)0x0) {
        _free(local_18);
        return;
      }
      if (local_2c != (void *)0x0) {
        _free(local_2c);
        return;
      }
    }
    else {
      FUN_00430ce0(&param_3);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004ced70 @ 0x004ced70 ====

void FUN_004ced70(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int in_ECX;
  undefined1 local_78 [8];
  undefined1 local_70 [32];
  int local_50 [5];
  undefined1 local_3c [32];
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  iVar6 = param_2;
  iVar5 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00980f4b;
  local_c = ExceptionList;
  iVar1 = param_1 * 0x3c;
  ExceptionList = &local_c;
  FUN_004cf740(&param_1,iVar1 + 0x7c + *(int *)(in_ECX + 0xc4));
  iVar7 = param_1;
  if (param_1 == *(int *)(iVar6 + 4)) {
    _eh_vector_constructor_iterator_(local_70,0x10,2,FUN_0045a320,FUN_00412dc0);
    local_50[0] = 0;
    local_50[2] = 0;
    local_50[1] = 0;
    local_50[3] = 0;
    local_4 = 0;
    FUN_004d1140(&param_1);
    iVar1 = iVar1 + *(int *)(in_ECX + 0xc4);
    if (*(int *)(iVar1 + 0x50) == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = (*(int *)(iVar1 + 0x54) - *(int *)(iVar1 + 0x50)) / 0x24;
    }
    local_50[iVar5] = iVar7;
    if (*(int *)(iVar1 + 0x60) == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = *(int *)(iVar1 + 100) - *(int *)(iVar1 + 0x60) >> 1;
    }
    local_50[iVar5 + 2] = iVar7;
    local_50[4] = *(undefined4 *)(iVar1 + 0x7c);
    _eh_vector_copy_constructor_iterator_(local_3c,local_70,0x10,2,FUN_004d0f70,FUN_00412dc0);
    local_1c = local_50[0];
    local_18 = local_50[1];
    local_14 = local_50[2];
    local_10 = local_50[3];
    local_4._0_1_ = 1;
    FUN_004d1d90(local_78,local_50 + 4);
    local_4 = (uint)local_4._1_3_ << 8;
    _eh_vector_destructor_iterator_(local_3c,0x10,2,FUN_00412dc0);
    local_4 = 0xffffffff;
    _eh_vector_destructor_iterator_(local_70,0x10,2,FUN_00412dc0);
    ExceptionList = local_c;
    return;
  }
  FUN_004d1140(&param_2);
  iVar6 = iVar1 + 0x4c + *(int *)(in_ECX + 0xc4);
  iVar4 = *(int *)(iVar6 + 4);
  if (iVar4 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = (*(int *)(iVar6 + 8) - iVar4) / 0x24;
  }
  piVar2 = (int *)(iVar7 + 0x30 + iVar5 * 4);
  *piVar2 = *piVar2 + iVar6;
  iVar6 = *(int *)(iVar1 + 0x60 + *(int *)(in_ECX + 0xc4));
  if (iVar6 == 0) {
    puVar3 = (undefined4 *)(iVar7 + 0x38 + iVar5 * 4);
    *puVar3 = *puVar3;
    ExceptionList = local_c;
    return;
  }
  piVar2 = (int *)(iVar7 + 0x38 + iVar5 * 4);
  *piVar2 = *piVar2 + (*(int *)(iVar1 + *(int *)(in_ECX + 0xc4) + 100) - iVar6 >> 1);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004cefb0 @ 0x004cefb0 ====

void FUN_004cefb0(undefined4 param_1,undefined4 param_2,float param_3,undefined4 param_4)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (*(char *)(in_ECX + 0x51) == '\0') {
    if (*(char *)(in_ECX + 0x50) != '\0') {
      iVar3 = 0;
      uVar2 = 0;
      do {
        iVar1 = *(int *)(in_ECX + 0xc4) + uVar2;
        if ((*(char *)(iVar1 + 0x44) != '\0') && (*(int *)(iVar1 + 0x7c) != 0)) {
          if (((char)param_4 == '\0') ||
             ((*(float *)(iVar1 + 0x48) != param_3 || (*(int *)(*(int *)(iVar1 + 0x7c) + 0x6c) == 0)
              ))) {
            uVar4 = param_1;
          }
          else {
            uVar4 = param_2;
          }
          FUN_004ced70(iVar3,uVar4);
        }
        uVar2 = uVar2 + 0x3c;
        iVar3 = iVar3 + 1;
      } while (uVar2 < 0x78);
      return;
    }
    iVar1 = *(int *)(in_ECX + 0x10);
    for (iVar3 = *(int *)(in_ECX + 0xc); iVar3 != iVar1; iVar3 = iVar3 + 4) {
      FUN_004cefb0(param_1,param_2,param_3,param_4);
    }
  }
  return;
}


// ==== FUN_004cf060 @ 0x004cf060 ====

void FUN_004cf060(void)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00980f60;
  local_c = ExceptionList;
  if (*(int *)(in_ECX + 0xc4) != 0) {
    ExceptionList = &local_c;
    FUN_004d1a60();
    ExceptionList = local_c;
    return;
  }
  ExceptionList = &local_c;
  pvVar2 = operator_new(0xc0);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_004d1f60();
  }
  uVar1 = DAT_0099d0e8;
  *(undefined4 **)(in_ECX + 0xc4) = puVar3;
  *(undefined1 *)(puVar3 + 0x11) = 0;
  puVar3[0x1f] = 0;
  puVar3[0x12] = uVar1;
  *(undefined1 *)(puVar3 + 0x20) = 0;
  puVar3[0x2e] = 0;
  puVar3[0x21] = uVar1;
  *puVar3 = 0;
  puVar3[1] = 0;
  *(undefined1 *)(puVar3 + 0x2f) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004cf110 @ 0x004cf110 ====

void FUN_004cf110(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  uint uVar2;
  
  cVar1 = FUN_004ce560(param_1);
  if (cVar1 == '\0') {
    *(undefined1 *)(in_ECX + 0x50) = 1;
    FUN_004cf060();
    FUN_004aa6f0(param_1);
    return;
  }
  uVar2 = 0;
  do {
    if (*(int *)(*(int *)(in_ECX + 0xc) + uVar2) != 0) {
      FUN_004cf110(param_1);
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x10);
  return;
}


// ==== FUN_004cf170 @ 0x004cf170 ====

void FUN_004cf170(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int in_ECX;
  uint uVar2;
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00980f72;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  cVar1 = FUN_004ce560(param_1);
  if (cVar1 == '\0') {
    *(undefined1 *)(in_ECX + 0x50) = 1;
    FUN_004cf060();
    FUN_004d4fc0(in_ECX,in_ECX + 0x40,param_1);
    local_4 = 0;
    FUN_004d1190(local_28);
    ExceptionList = local_c;
    return;
  }
  uVar2 = 0;
  do {
    if (*(int *)(*(int *)(in_ECX + 0xc) + uVar2) != 0) {
      FUN_004cf170(param_1,param_2);
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x10);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004cf220 @ 0x004cf220 ====

void FUN_004cf220(void)

{
  int iVar1;
  void *_Memory;
  int *piVar2;
  int in_ECX;
  int *piVar3;
  
  if (*(char *)(in_ECX + 0x50) != '\0') {
    iVar1 = *(int *)(*(int *)(in_ECX + 0xc4) + 0x7c);
    if (iVar1 != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
      *(undefined4 *)(*(int *)(in_ECX + 0xc4) + 0x7c) = 0;
    }
    iVar1 = *(int *)(*(int *)(in_ECX + 0xc4) + 0xb8);
    if (iVar1 != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
      *(undefined4 *)(*(int *)(in_ECX + 0xc4) + 0xb8) = 0;
    }
    _Memory = *(void **)(in_ECX + 0xc4);
    if (_Memory != (void *)0x0) {
      FUN_004d1e80();
      _free(_Memory);
      return;
    }
    *(undefined4 *)(in_ECX + 0xc4) = 0;
  }
  piVar2 = *(int **)(in_ECX + 0x10);
  for (piVar3 = *(int **)(in_ECX + 0xc); piVar3 != piVar2; piVar3 = piVar3 + 1) {
    if ((undefined4 *)*piVar3 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar3)(1);
    }
  }
  return;
}


// ==== FUN_004cf2d0 @ 0x004cf2d0 ====

undefined4 FUN_004cf2d0(undefined4 param_1)

{
  undefined4 in_ECX;
  
  FUN_004cf110(param_1);
  FUN_004cd430(in_ECX);
  return 1;
}


// ==== FUN_004cf2f0 @ 0x004cf2f0 ====

undefined4 FUN_004cf2f0(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_ECX;
  
  FUN_004cf170(param_1,param_2);
  FUN_004cd430(in_ECX);
  return 1;
}


// ==== FUN_004cf320 @ 0x004cf320 ====

void FUN_004cf320(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00980f92;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009b0e98;
  local_4 = 1;
  FUN_004cf220();
  local_4 = local_4 & 0xffffff00;
  FUN_004d0740(local_10,*(undefined4 *)in_ECX[7],(undefined4 *)in_ECX[7]);
  _free((void *)in_ECX[7]);
  return;
}


// ==== FUN_004cf3b0 @ 0x004cf3b0 ====

void FUN_004cf3b0(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x15);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x15);
  }
  return;
}


// ==== FUN_004cf3d0 @ 0x004cf3d0 ====

void FUN_004cf3d0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x41) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x41) == '\0');
  }
  return;
}


// ==== FUN_004cf3f0 @ 0x004cf3f0 ====

int FUN_004cf3f0(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 != param_2) {
    puVar1 = (undefined4 *)(param_2 + 8);
    puVar2 = (undefined4 *)(param_3 + 8);
    do {
      puVar2[-8] = puVar1[-8];
      puVar2[-7] = puVar1[-7];
      puVar2[-6] = puVar1[-6];
      puVar2[-5] = puVar1[-5];
      param_2 = param_2 + -0x1c;
      puVar2[-4] = puVar1[-4];
      param_3 = param_3 + -0x1c;
      puVar2[-3] = puVar1[-3];
      puVar1 = puVar1 + -7;
      puVar2 = puVar2 + -7;
    } while (param_2 != param_1);
  }
  return param_3;
}


// ==== FUN_004cf450 @ 0x004cf450 ====

void FUN_004cf450(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x41) == '\0') {
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


// ==== FUN_004cf4a0 @ 0x004cf4a0 ====

void FUN_004cf4a0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x41) == '\0') {
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


// ==== FUN_004cf500 @ 0x004cf500 ====

void FUN_004cf500(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x41) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x41) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x41);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x41);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x41) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x41) == '\0');
    if (*(char *)((int)piVar4 + 0x41) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_004cf560 @ 0x004cf560 ====

void FUN_004cf560(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  
  if (param_1 != param_2) {
    puVar1 = (undefined4 *)(param_1 + 8);
    do {
      puVar1[-1] = *(undefined4 *)(param_3 + 4);
      *puVar1 = *(undefined4 *)(param_3 + 8);
      puVar1[1] = *(undefined4 *)(param_3 + 0xc);
      puVar1[2] = *(undefined4 *)(param_3 + 0x10);
      puVar1[3] = *(undefined4 *)(param_3 + 0x14);
      puVar1[4] = *(undefined4 *)(param_3 + 0x18);
      param_1 = param_1 + 0x1c;
      puVar1 = puVar1 + 7;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_004cf5b0 @ 0x004cf5b0 ====

void FUN_004cf5b0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  for (; param_1 != param_2; param_1 = param_1 + 9) {
    if (param_3 != (undefined4 *)0x0) {
      puVar2 = param_1;
      puVar3 = param_3;
      for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    param_3 = param_3 + 9;
  }
  return;
}


// ==== FUN_004cf5e0 @ 0x004cf5e0 ====

void FUN_004cf5e0(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 != param_2) {
    puVar1 = param_3 + 2;
    puVar2 = (undefined4 *)(param_1 + 8);
    do {
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = &PTR_FUN_009b0e80;
        puVar1[-1] = puVar2[-1];
        *puVar1 = *puVar2;
        puVar1[1] = puVar2[1];
        puVar1[2] = puVar2[2];
        puVar1[3] = puVar2[3];
        puVar1[4] = puVar2[4];
      }
      param_1 = param_1 + 0x1c;
      param_3 = param_3 + 7;
      puVar1 = puVar1 + 7;
      puVar2 = puVar2 + 7;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_004cf640 @ 0x004cf640 ====

void FUN_004cf640(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_004cf640(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004cf680 @ 0x004cf680 ====

void FUN_004cf680(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_2 != 0) {
    do {
      if (param_1 != (undefined4 *)0x0) {
        puVar2 = param_3;
        puVar3 = param_1;
        for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
      }
      param_1 = param_1 + 9;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_004cf6b0 @ 0x004cf6b0 ====

void FUN_004cf6b0(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  
  if (param_2 != 0) {
    puVar1 = param_1 + 2;
    do {
      if (param_1 != (undefined4 *)0x0) {
        *param_1 = &PTR_FUN_009b0e80;
        puVar1[-1] = *(undefined4 *)(param_3 + 4);
        *puVar1 = *(undefined4 *)(param_3 + 8);
        puVar1[1] = *(undefined4 *)(param_3 + 0xc);
        puVar1[2] = *(undefined4 *)(param_3 + 0x10);
        puVar1[3] = *(undefined4 *)(param_3 + 0x14);
        puVar1[4] = *(undefined4 *)(param_3 + 0x18);
      }
      param_1 = param_1 + 7;
      puVar1 = puVar1 + 7;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_004cf710 @ 0x004cf710 ====

void FUN_004cf710(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    *param_3 = *param_1;
    param_3 = param_3 + 1;
  }
  return;
}


// ==== FUN_004cf740 @ 0x004cf740 ====

void FUN_004cf740(undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x41) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((uint)puVar1[3] < *param_2) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x41) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < (uint)puVar3[3])) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_004cf7b0 @ 0x004cf7b0 ====

int FUN_004cf7b0(int param_1,int param_2,undefined4 param_3)

{
  FUN_004cf680(param_1,param_2,param_3);
  return param_1 + param_2 * 0x24;
}


// ==== FUN_004cf7e0 @ 0x004cf7e0 ====

int FUN_004cf7e0(int param_1,int param_2,undefined4 param_3)

{
  FUN_004cf6b0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x1c;
}


// ==== FUN_004cf810 @ 0x004cf810 ====

void FUN_004cf810(void)

{
  void *in_ECX;
  
  _eh_vector_destructor_iterator_(in_ECX,0x10,2,FUN_00412dc0);
  return;
}


// ==== FUN_004cf820 @ 0x004cf820 ====

void FUN_004cf820(void)

{
  int in_ECX;
  
  _eh_vector_destructor_iterator_((void *)(in_ECX + 4),0x10,2,FUN_00412dc0);
  return;
}


// ==== FUN_004cf840 @ 0x004cf840 ====

void FUN_004cf840(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x2c) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x2c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  if (*(void **)(in_ECX + 0x1c) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x1c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  if (*(void **)(in_ECX + 0xc) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0xc));
  return;
}


// ==== FUN_004cf8a0 @ 0x004cf8a0 ====

void FUN_004cf8a0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
LAB_004cf999:
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
      if ((char)piVar6[5] == '\0') goto LAB_004cf999;
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


// ==== FUN_004cfa80 @ 0x004cfa80 ====

void FUN_004cfa80(void)

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
  puStack_8 = &LAB_00980fe8;
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


// ==== FUN_004cfaf0 @ 0x004cfaf0 ====

void FUN_004cfaf0(void)

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
  puStack_8 = &LAB_00980fe8;
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


// ==== FUN_004cfb60 @ 0x004cfb60 ====

void FUN_004cfb60(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  uint uVar5;
  uint extraout_ECX;
  undefined4 *puVar6;
  undefined4 local_38;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00980e10;
  local_10 = ExceptionList;
  puVar6 = &local_38;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *param_3;
    param_3 = param_3 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar4 = *(int *)(in_ECX + 4);
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar4) / 0x24;
  }
  if (param_2 != 0) {
    if (iVar4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar4) / 0x24;
    }
    ExceptionList = &local_10;
    local_14 = (undefined1 *)((int)register0x00000010 + -0x44);
    if (0x71c71c7U - iVar1 < param_2) {
      ExceptionList = &local_10;
      local_14 = (undefined1 *)((int)register0x00000010 + -0x44);
      FUN_004cfaf0();
      uVar5 = extraout_ECX;
    }
    if (iVar4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar4) / 0x24;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x71c71c7 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = (*(int *)(in_ECX + 8) - iVar4) / 0x24;
      }
      if (uVar5 < iVar4 + param_2) {
        iVar4 = FUN_0066e7e0();
        uVar5 = iVar4 + param_2;
      }
      pvVar2 = operator_new(uVar5 * 0x24);
      local_8 = 0;
      iVar4 = FUN_004cf5b0(*(undefined4 *)(in_ECX + 4),param_1,pvVar2);
      FUN_004cf680(iVar4,param_2,&local_38);
      FUN_004cf5b0(param_1,*(undefined4 *)(in_ECX + 8),iVar4 + param_2 * 0x24);
      iVar4 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar4 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x24;
      }
      if (*(void **)(in_ECX + 4) == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x24 + (int)pvVar2);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar2 + (param_2 + iVar4) * 0x24);
        *(void **)(in_ECX + 4) = pvVar2;
        ExceptionList = local_10;
        return;
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar4 = *(int *)(in_ECX + 8);
    if ((uint)((iVar4 - param_1) / 0x24) < param_2) {
      FUN_004cf5b0(param_1,iVar4,param_2 * 0x24 + param_1);
      local_8 = 2;
      FUN_004cf7b0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x24,&local_38)
      ;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x24;
      FUN_008684a0(param_1,*(int *)(in_ECX + 8) + param_2 * -0x24,&local_38);
      ExceptionList = local_10;
      return;
    }
    iVar1 = iVar4 + param_2 * -0x24;
    uVar3 = FUN_004cf5b0(iVar1,iVar4,iVar4);
    *(undefined4 *)(in_ECX + 8) = uVar3;
    FUN_004ab860(param_1,iVar1,iVar4);
    FUN_008684a0(param_1,param_2 * 0x24 + param_1,&local_38);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004cfd10 @ 0x004cfd10 ====

void Catch_004cfd10(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_004cfe10 @ 0x004cfe10 ====

/* WARNING: Removing unreachable block (ram,0x004cff23) */
/* WARNING: Removing unreachable block (ram,0x004cff33) */
/* WARNING: Removing unreachable block (ram,0x004cff3c) */
/* WARNING: Removing unreachable block (ram,0x004cff3f) */
/* WARNING: Removing unreachable block (ram,0x004cff2f) */
/* WARNING: Removing unreachable block (ram,0x004cff4d) */
/* WARNING: Removing unreachable block (ram,0x004cff5a) */
/* WARNING: Removing unreachable block (ram,0x004cff65) */
/* WARNING: Removing unreachable block (ram,0x004cff61) */
/* WARNING: Removing unreachable block (ram,0x004cff55) */
/* WARNING: Removing unreachable block (ram,0x004cff68) */

void FUN_004cfe10(undefined4 param_1,int *param_2)

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
            goto LAB_004d0035;
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
LAB_004d0035:
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


