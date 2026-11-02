// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x5c0000-0x5cffff

// ==== FUN_005c0190 @ 0x005c0190 ====

/* WARNING: Removing unreachable block (ram,0x005c01f0) */
/* WARNING: Removing unreachable block (ram,0x005c0305) */

void FUN_005c0190(uint *param_1)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  byte *pbVar6;
  int *piVar7;
  int *piVar8;
  int in_ECX;
  uint uVar9;
  int *piVar10;
  int *piVar11;
  uint *puVar12;
  int *piVar13;
  undefined4 *puVar14;
  int *piVar15;
  bool bVar16;
  bool bVar17;
  char *local_8;
  
  local_8 = (char *)param_1[1];
  pcVar1 = (char *)param_1[2];
  if (local_8 == pcVar1) {
LAB_005c03f1:
    (**(code **)(**(int **)(in_ECX + 8) + 8))();
    puVar4 = *(undefined4 **)(in_ECX + 0x14);
    for (puVar14 = *(undefined4 **)(in_ECX + 0x10); puVar14 != puVar4; puVar14 = puVar14 + 0x18) {
      (**(code **)(**(int **)(in_ECX + 8) + 4))(*puVar14);
    }
    if (*(int *)(in_ECX + 0x30) != 0) {
      FUN_0069d3a0(*(int *)(in_ECX + 0x30),*(undefined4 *)(in_ECX + 0x34),in_ECX + 0x2c,param_1);
      _free(*(void **)(in_ECX + 0x30));
      return;
    }
    *(undefined4 *)(in_ECX + 0x30) = 0;
    *(undefined4 *)(in_ECX + 0x34) = 0;
    *(undefined4 *)(in_ECX + 0x38) = 0;
    if (*(int *)(in_ECX + 0x40) == 0) {
      *(undefined4 *)(in_ECX + 0x40) = 0;
      *(undefined4 *)(in_ECX + 0x44) = 0;
      *(undefined4 *)(in_ECX + 0x48) = 0;
      return;
    }
    FUN_0069d3a0(*(int *)(in_ECX + 0x40),*(undefined4 *)(in_ECX + 0x44),in_ECX + 0x3c,param_1);
    _free(*(void **)(in_ECX + 0x40));
    return;
  }
  param_1 = (uint *)(local_8 + 0x24);
  do {
    piVar13 = *(int **)(in_ECX + 0x14);
    piVar10 = *(int **)(in_ECX + 0x10);
joined_r0x005c01cc:
    if (piVar10 == piVar13) goto LAB_005c02a6;
    iVar5 = (**(code **)(*(int *)*piVar10 + 4))();
    uVar2 = param_1[-1];
    if (*param_1 < 0x10) {
      puVar12 = param_1 + -5;
    }
    else {
      puVar12 = (uint *)param_1[-5];
    }
    uVar3 = *(uint *)(iVar5 + 0x14);
    if (uVar3 != 0) {
      uVar9 = uVar3;
      if (uVar2 <= uVar3) {
        uVar9 = uVar2;
      }
      if (*(uint *)(iVar5 + 0x18) < 0x10) {
        pbVar6 = (byte *)(iVar5 + 4);
      }
      else {
        pbVar6 = *(byte **)(iVar5 + 4);
      }
      bVar16 = false;
      iVar5 = 0;
      bVar17 = true;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        bVar16 = *pbVar6 < (byte)*puVar12;
        bVar17 = *pbVar6 == (byte)*puVar12;
        pbVar6 = pbVar6 + 1;
        puVar12 = (uint *)((int)puVar12 + 1);
      } while (bVar17);
      if (!bVar17) {
        iVar5 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
      }
      if (iVar5 == 0) goto LAB_005c0224;
LAB_005c0233:
      piVar10 = piVar10 + 0x18;
      goto joined_r0x005c01cc;
    }
LAB_005c0224:
    if ((uVar3 < uVar2) || (uVar3 != uVar2)) goto LAB_005c0233;
    if (*piVar10 != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(*piVar10);
      *piVar10 = 0;
    }
    if (piVar10[1] != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(piVar10[1]);
      piVar10[1] = 0;
    }
    piVar13 = *(int **)(in_ECX + 0x14);
    if (piVar10 + 0x18 != piVar13) {
      piVar7 = piVar10 + 0x18;
      do {
        piVar15 = piVar7 + 0x18;
        piVar11 = piVar10;
        for (iVar5 = 0x18; iVar5 != 0; iVar5 = iVar5 + -1) {
          *piVar11 = *piVar7;
          piVar7 = piVar7 + 1;
          piVar11 = piVar11 + 1;
        }
        piVar7 = piVar15;
        piVar10 = piVar10 + 0x18;
      } while (piVar15 != piVar13);
    }
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + -0x60;
LAB_005c02a6:
    if ((*(int *)(in_ECX + 0x20) != 0) &&
       ((*(int *)(in_ECX + 0x24) - *(int *)(in_ECX + 0x20)) / 0x60 != 0)) {
      piVar10 = *(int **)(in_ECX + 0x24);
      for (piVar13 = *(int **)(in_ECX + 0x20); piVar13 != piVar10; piVar13 = piVar13 + 0x18) {
        iVar5 = (**(code **)(*(int *)*piVar13 + 4))();
        uVar2 = param_1[-1];
        if (*param_1 < 0x10) {
          puVar12 = param_1 + -5;
        }
        else {
          puVar12 = (uint *)param_1[-5];
        }
        uVar3 = *(uint *)(iVar5 + 0x14);
        if (uVar3 == 0) {
LAB_005c033d:
          if ((uVar2 <= uVar3) && (uVar3 == uVar2)) {
            piVar10 = *(int **)(in_ECX + 0x24);
            if (piVar13 + 0x18 != piVar10) {
              piVar7 = piVar13 + 0x18;
              piVar11 = piVar13;
              do {
                piVar8 = piVar7 + 0x18;
                piVar15 = piVar11;
                for (iVar5 = 0x18; iVar5 != 0; iVar5 = iVar5 + -1) {
                  *piVar15 = *piVar7;
                  piVar7 = piVar7 + 1;
                  piVar15 = piVar15 + 1;
                }
                piVar7 = piVar8;
                piVar11 = piVar11 + 0x18;
              } while (piVar8 != piVar10);
            }
            *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + -0x60;
            if (*local_8 != '\0') {
              if (*piVar13 != 0) {
                (**(code **)(*DAT_00b5a7cc + 0x14))(*piVar13);
                *piVar13 = 0;
              }
              if (piVar13[1] != 0) {
                (**(code **)(*DAT_00b5a7cc + 0x14))(piVar13[1]);
                piVar13[1] = 0;
              }
            }
            break;
          }
        }
        else {
          uVar9 = uVar3;
          if (uVar2 <= uVar3) {
            uVar9 = uVar2;
          }
          if (*(uint *)(iVar5 + 0x18) < 0x10) {
            pbVar6 = (byte *)(iVar5 + 4);
          }
          else {
            pbVar6 = *(byte **)(iVar5 + 4);
          }
          bVar16 = false;
          iVar5 = 0;
          bVar17 = true;
          do {
            if (uVar9 == 0) break;
            uVar9 = uVar9 - 1;
            bVar16 = *pbVar6 < (byte)*puVar12;
            bVar17 = *pbVar6 == (byte)*puVar12;
            pbVar6 = pbVar6 + 1;
            puVar12 = (uint *)((int)puVar12 + 1);
          } while (bVar17);
          if (!bVar17) {
            iVar5 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
          }
          if (iVar5 == 0) goto LAB_005c033d;
        }
      }
    }
    local_8 = local_8 + 0x44;
    param_1 = param_1 + 0x11;
    if (local_8 == pcVar1) goto LAB_005c03f1;
  } while( true );
}


// ==== FUN_005c0480 @ 0x005c0480 ====

/* WARNING: Removing unreachable block (ram,0x005c0508) */

void FUN_005c0480(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2470;
  FUN_005bfed0();
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if (in_ECX[0xc] != 0) {
    FUN_0069d3a0(in_ECX[0xc],in_ECX[0xd],in_ECX + 0xb,in_ECX);
    _free((void *)in_ECX[0xc]);
    return;
  }
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  if (in_ECX[0x10] != 0) {
    FUN_0069d3a0(in_ECX[0x10],in_ECX[0x11],in_ECX + 0xf,in_ECX);
    _free((void *)in_ECX[0x10]);
    return;
  }
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  if (in_ECX[0xc] != 0) {
    FUN_0069d3a0(in_ECX[0xc],in_ECX[0xd],in_ECX + 0xb,in_ECX);
    _free((void *)in_ECX[0xc]);
    return;
  }
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  if ((void *)in_ECX[8] != (void *)0x0) {
    _free((void *)in_ECX[8]);
    return;
  }
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  if ((void *)in_ECX[4] == (void *)0x0) {
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_005c0590 @ 0x005c0590 ====

void FUN_005c0590(int param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  char local_29;
  int local_28;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 *local_20;
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (param_3 == '\0') {
    cVar2 = *(char *)(in_ECX + 0x4c);
  }
  else {
    cVar2 = *(char *)(in_ECX + 0x4d);
  }
  local_29 = '\0';
  local_28 = in_ECX;
  puVar3 = (undefined4 *)FUN_005c7ee0(&local_29);
  if (cVar2 != local_29) {
    if (*(char *)(in_ECX + 0x4e) == '\0') {
      FUN_005c1760();
    }
    if ((puVar3[6] == 0) || (cVar2 = FUN_005bf880(puVar3 + 1), cVar2 != '\0')) {
      iVar1 = *(int *)(param_1 + 8);
      for (iVar4 = *(int *)(param_1 + 4); iVar4 != iVar1; iVar4 = iVar4 + 0x60) {
        local_20 = *(undefined1 **)(iVar4 + 0x5c);
        local_24 = *(undefined1 *)(iVar4 + 0x58);
        local_4 = 0xf;
        local_8 = 0;
        local_18 = (void *)((uint)local_18 & 0xffffff00);
        if (local_20 == (undefined1 *)0x0) {
          local_23 = 0;
          local_20 = (undefined1 *)0x0;
        }
        else {
          local_23 = *local_20;
        }
        FUN_005c1810(&local_24);
        *(undefined4 *)(iVar4 + 0x5c) = *puVar3;
        *(undefined1 *)(iVar4 + 0x58) = 1;
        *(char *)(iVar4 + 0x59) = param_3;
        if (0xf < local_4) {
          _free(local_18);
          return;
        }
        local_18 = (void *)((uint)local_18 & 0xffffff00);
      }
      *(undefined1 *)(local_28 + 0x4e) = 1;
      if (param_3 != '\0') {
        *(char *)(local_28 + 0x4d) = local_29;
        return;
      }
      *(char *)(local_28 + 0x4c) = local_29;
    }
  }
  return;
}


// ==== FUN_005c06c0 @ 0x005c06c0 ====

undefined4 FUN_005c06c0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  iVar1 = *(int *)(in_ECX + 0x14);
  iVar3 = *(int *)(in_ECX + 0x10);
  while( true ) {
    if (iVar3 == iVar1) {
      return 0;
    }
    iVar2 = FUN_004b9e30(param_2);
    if (iVar2 != 0) break;
    iVar3 = iVar3 + 0x60;
  }
  FUN_0043bce0(iVar2 + 0x1c);
  return 1;
}


// ==== FUN_005c0710 @ 0x005c0710 ====

void FUN_005c0710(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  
  cVar2 = FUN_005c8120();
  if ((cVar2 == '\0') || (*(char *)(in_ECX + 0x4f) != '\x01')) {
    cVar2 = FUN_005c7ef0();
    if (cVar2 == '\0') {
      FUN_005bf950(in_ECX + 0xc,in_ECX + 0x2c);
      return;
    }
    FUN_005c0590(in_ECX + 0xc,in_ECX + 0x2c,0);
  }
  else {
    iVar3 = *(int *)(param_1 + 4);
    iVar1 = *(int *)(param_1 + 8);
    if (iVar3 != iVar1) {
      do {
        *(undefined1 *)(iVar3 + 0x58) = 0;
        iVar3 = iVar3 + 0x60;
      } while (iVar3 != iVar1);
      return;
    }
  }
  return;
}


// ==== FUN_005c0780 @ 0x005c0780 ====

void FUN_005c0780(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  
  cVar2 = FUN_005c8120();
  if ((cVar2 == '\0') || (*(char *)(in_ECX + 0x4f) != '\x01')) {
    cVar2 = FUN_005c7ef0();
    if (cVar2 == '\0') {
      if (*(char *)(in_ECX + 0x4e) != '\0') {
        FUN_005bf950(in_ECX + 0xc,in_ECX + 0x2c);
        FUN_005bf950(in_ECX + 0x1c,in_ECX + 0x3c);
        return;
      }
    }
    else {
      if (*(char *)(in_ECX + 0x4e) == '\0') {
        FUN_005c1760();
        FUN_005c1760();
      }
      FUN_005c0590(in_ECX + 0xc,in_ECX + 0x2c,0);
      FUN_005c0590(in_ECX + 0x1c,in_ECX + 0x3c,1);
    }
  }
  else {
    iVar3 = *(int *)(param_1 + 4);
    iVar1 = *(int *)(param_1 + 8);
    if (iVar3 != iVar1) {
      do {
        *(undefined1 *)(iVar3 + 0x58) = 0;
        iVar3 = iVar3 + 0x60;
      } while (iVar3 != iVar1);
      return;
    }
  }
  return;
}


// ==== FUN_005c0830 @ 0x005c0830 ====

void FUN_005c0830(int param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    if (*(char *)(in_ECX + 0x50) != '\0') {
      iVar2 = (**(code **)(*DAT_00b5af48 + 8))();
      if (*(char *)(iVar2 + 1) != '\0') {
        cVar1 = FUN_005c08f0();
        if (cVar1 == '\0') {
          if (*(char *)(*(int *)(in_ECX + 4) + 0x38) == '\0') {
            FUN_005c10d0(*(undefined4 *)(param_1 + 0x50),*(undefined4 *)(in_ECX + 0x10),
                         *(undefined4 *)(in_ECX + 0x14));
            FUN_005c0780(in_ECX + 0xc);
            return;
          }
          FUN_005c10d0(*(undefined4 *)(param_1 + 0x50),*(undefined4 *)(in_ECX + 0x20),
                       *(undefined4 *)(in_ECX + 0x24));
          FUN_005c0780(in_ECX + 0x1c);
          return;
        }
      }
    }
    FUN_005c0a90(*(undefined4 *)(param_1 + 0x50),*(undefined4 *)(in_ECX + 0x10),
                 *(undefined4 *)(in_ECX + 0x14),param_1);
    FUN_005c0710(in_ECX + 0xc);
  }
  return;
}


// ==== FUN_005c08f0 @ 0x005c08f0 ====

undefined4 FUN_005c08f0(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 1;
  }
  iVar1 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x60;
  return CONCAT31((int3)((uint)iVar1 >> 8),iVar1 == 0);
}


// ==== FUN_005c0930 @ 0x005c0930 ====

void FUN_005c0930(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  while (param_1 != param_2) {
    puVar3 = param_1 + 0x18;
    puVar1 = param_3 + 0x18;
    puVar4 = param_1;
    puVar5 = param_3;
    for (iVar2 = 0x18; param_1 = puVar3, param_3 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  return;
}


// ==== FUN_005c0960 @ 0x005c0960 ====

int FUN_005c0960(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982980;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x60) {
    FUN_005b1900(param_3,param_1);
    param_3 = param_3 + 0x60;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@005c09c6 @ 0x005c09c6 ====

void Catch_005c09c6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005c09d0 @ 0x005c09d0 ====

void FUN_005c09d0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982990;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_005b1900(param_1,param_3);
    param_1 = param_1 + 0x60;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005c0a36 @ 0x005c0a36 ====

void Catch_005c0a36(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005c0a40 @ 0x005c0a40 ====

void FUN_005c0a40(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005c0960(param_1,param_2,param_3);
  return;
}


// ==== FUN_005c0a60 @ 0x005c0a60 ====

int FUN_005c0a60(int param_1,int param_2,undefined4 param_3)

{
  FUN_005c09d0(param_1,param_2,param_3);
  return param_2 * 0x60 + param_1;
}


// ==== FUN_005c0a90 @ 0x005c0a90 ====

void FUN_005c0a90(int param_1,int param_2,int param_3)

{
  void *_Memory;
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
  puStack_c = &LAB_009829a0;
  local_10 = ExceptionList;
  uVar1 = (param_3 - param_2) / 0x60;
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x60;
  }
  if (uVar1 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x60;
    }
    ExceptionList = &local_10;
    if (0x2aaaaaaU - iVar2 < uVar1) {
      ExceptionList = &local_10;
      FUN_0085b3b0();
      uVar6 = extraout_ECX;
    }
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x60;
    }
    if (uVar6 < iVar2 + uVar1) {
      if (0x2aaaaaa - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x60;
      }
      if (uVar6 < iVar3 + uVar1) {
        iVar3 = FUN_005b1840();
        uVar6 = iVar3 + uVar1;
      }
      pvVar4 = operator_new(uVar6 * 0x60);
      local_8 = 0;
      uVar5 = FUN_005c0a40(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_005c0a40(param_2,param_3,uVar5);
      FUN_005c0a40(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x60;
      }
      if (_Memory == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar6 * 0x60 + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((uVar1 + iVar3) * 0x60 + (int)pvVar4);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)((iVar3 - param_1) / 0x60) < uVar1) {
      FUN_005c0960(param_1,iVar3,uVar1 * 0x60 + param_1);
      iVar3 = ((*(int *)(in_ECX + 8) - param_1) / 0x60) * 0x60 + param_2;
      local_8 = 2;
      FUN_005c0a40(iVar3,param_3,*(undefined4 *)(in_ECX + 8));
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar1 * 0x60;
      FUN_005c0930(param_2,iVar3,param_1);
      ExceptionList = local_10;
      return;
    }
    iVar2 = iVar3 + uVar1 * -0x60;
    uVar5 = FUN_005c0960(iVar2,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_005b18d0(param_1,iVar2,iVar3);
    FUN_005c0930(param_2,param_3,param_1);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005c0c41 @ 0x005c0c41 ====

void Catch_005c0c41(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005c0d50 @ 0x005c0d50 ====

void FUN_005c0d50(int param_1)

{
  if (*(uint *)(param_1 + 0x20) < 0x10) {
    *(undefined4 *)(param_1 + 0x20) = 0xf;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined1 *)(param_1 + 0xc) = 0;
    return;
  }
  _free(*(void **)(param_1 + 0xc));
  return;
}


// ==== FUN_005c0d80 @ 0x005c0d80 ====

int FUN_005c0d80(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if (param_1 < (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x60)) {
      return param_1 * 0x60 + iVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0085b340();
}


// ==== FUN_005c0dc0 @ 0x005c0dc0 ====

undefined4 FUN_005c0dc0(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x2aaaaaa < param_1) {
    param_1 = FUN_0085b3b0();
  }
  pvVar1 = operator_new(param_1 * 0x60);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x60 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_005c0e10 @ 0x005c0e10 ====

void FUN_005c0e10(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  uint extraout_ECX;
  undefined4 *puVar4;
  undefined4 local_94;
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
  puStack_c = &LAB_009829b0;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0xa0);
  puVar4 = &local_94;
  for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_3;
    param_3 = param_3 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x60;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar3) / 0x60;
    }
    ExceptionList = &local_10;
    if (0x2aaaaaaU - iVar1 < param_2) {
      ExceptionList = &local_10;
      FUN_0085b3b0();
      local_20 = extraout_ECX;
    }
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar3) / 0x60;
    }
    if (local_20 < iVar1 + param_2) {
      if (0x2aaaaaa - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x60;
      }
      if (local_20 < iVar3 + param_2) {
        iVar3 = FUN_005b1840();
        local_20 = iVar3 + param_2;
      }
      local_20 = local_20 * 0x60;
      local_18 = operator_new(local_20);
      local_8 = 0;
      local_1c = FUN_005c0a40(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_1c = FUN_005c0a60(local_1c,param_2,&local_94);
      FUN_005c0a40(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x60;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)local_18;
        *(void **)(in_ECX + 8) = (void *)((param_2 + iVar3) * 0x60 + (int)local_18);
        *(void **)(in_ECX + 4) = local_18;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_28 = *(int *)(in_ECX + 8);
    if ((uint)((local_28 - param_1) / 0x60) < param_2) {
      local_24 = param_2 * 0x60;
      FUN_005c0960(param_1,local_28,local_24 + param_1);
      local_8 = 2;
      FUN_005c0a60(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x60,&local_94)
      ;
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_24;
      FUN_005b18a0(param_1,*(int *)(in_ECX + 8) - local_24,&local_94);
      ExceptionList = local_10;
      return;
    }
    local_2c = local_28 + param_2 * -0x60;
    uVar2 = FUN_005c0960(local_2c,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar2;
    FUN_005b18d0(param_1,local_2c,local_28);
    FUN_005b18a0(param_1,param_2 * 0x60 + param_1,&local_94);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005c0fc0 @ 0x005c0fc0 ====

void Catch_005c0fc0(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005c10d0 @ 0x005c10d0 ====

void FUN_005c10d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005c0a90(param_1,param_2,param_3,param_3);
  return;
}


// ==== FUN_005c10f0 @ 0x005c10f0 ====

undefined1 * FUN_005c10f0(int param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x24;
    puVar2 = param_3 + -0x24;
    *puVar2 = *(undefined1 *)(param_2 + -0x24);
    param_3[-0x23] = *(undefined1 *)(param_2 + -0x23);
    *(undefined4 *)(param_3 + -0x20) = *(undefined4 *)(param_2 + -0x20);
    FUN_00401660(param_2 + -0x1c,0,0xffffffff);
    param_2 = iVar1;
    param_3 = puVar2;
  } while (iVar1 != param_1);
  return puVar2;
}


// ==== FUN_005c1140 @ 0x005c1140 ====

void FUN_005c1140(undefined1 *param_1,undefined1 *param_2)

{
  if (param_1 != (undefined1 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
    *(undefined4 *)(param_1 + 0x20) = 0xf;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    param_1[0xc] = 0;
    FUN_00401660(param_2 + 8,0,0xffffffff);
  }
  return;
}


// ==== FUN_005c1190 @ 0x005c1190 ====

int FUN_005c1190(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009829c0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x24) {
    FUN_005c1140(param_3,param_1);
    param_3 = param_3 + 0x24;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@005c11fa @ 0x005c11fa ====

void Catch_005c11fa(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x24) {
    FUN_005c0d50(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005c1220 @ 0x005c1220 ====

void FUN_005c1220(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x60 != 0) {
      iVar1 = (param_2 - iVar1) / 0x60;
      goto LAB_005c1265;
    }
  }
  iVar1 = 0;
LAB_005c1265:
  FUN_005c0e10(param_2,1,param_3);
  *param_1 = iVar1 * 0x60 + *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_005c1290 @ 0x005c1290 ====

void FUN_005c1290(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_1 = *param_3;
      param_1[1] = param_3[1];
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_3 + 4);
      FUN_00401660(param_3 + 8,0,0xffffffff);
      param_1 = param_1 + 0x24;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_005c12d0 @ 0x005c12d0 ====

void FUN_005c12d0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009829d0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_005c1140(param_1,param_3);
    param_1 = param_1 + 0x24;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005c133a @ 0x005c133a ====

void Catch_005c133a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x24) {
    FUN_005c0d50(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005c1360 @ 0x005c1360 ====

void FUN_005c1360(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x60) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x60))) {
    FUN_005c1220(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_005c09d0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x60;
  return;
}


// ==== FUN_005c13f0 @ 0x005c13f0 ====

void FUN_005c13f0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005c1190(param_1,param_2,param_3);
  return;
}


// ==== FUN_005c1410 @ 0x005c1410 ====

int FUN_005c1410(int param_1,int param_2,undefined4 param_3)

{
  FUN_005c12d0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x24;
}


// ==== FUN_005c1440 @ 0x005c1440 ====

void FUN_005c1440(int param_1,uint param_2,undefined1 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint extraout_ECX;
  undefined1 local_64;
  undefined1 local_63;
  undefined1 auStack_62 [2];
  undefined4 local_60;
  void *local_58;
  undefined4 local_48;
  uint local_44;
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
  puStack_c = &LAB_009829e0;
  local_10 = ExceptionList;
  local_14 = auStack_62 + -0xe;
  local_64 = *param_3;
  local_63 = param_3[1];
  local_60 = *(undefined4 *)(param_3 + 4);
  local_44 = 0xf;
  local_48 = 0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3 + 8,0,0xffffffff);
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x24;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
    }
    if (0x71c71c7U - iVar1 < param_2) {
      FUN_0085b3b0();
      uVar4 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
    }
    if (uVar4 < iVar1 + param_2) {
      if (0x71c71c7 - (uVar4 >> 1) < uVar4) {
        uVar4 = 0;
      }
      else {
        uVar4 = uVar4 + (uVar4 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
      }
      if (uVar4 < iVar2 + param_2) {
        iVar2 = FUN_0066e7e0();
        uVar4 = iVar2 + param_2;
      }
      local_24 = uVar4 * 0x24;
      local_1c = operator_new(local_24);
      local_8 = 0;
      local_18 = local_1c;
      local_18 = (void *)FUN_005c13f0(*(undefined4 *)(in_ECX + 4),param_1,local_1c);
      local_18 = (void *)FUN_005c1410(local_18,param_2,&local_64);
      FUN_005c13f0(param_1,*(undefined4 *)(in_ECX + 8),local_18);
      local_8 = 0xffffffff;
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
      }
      if (iVar2 != 0) {
        FUN_0069d3a0(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(uint *)(in_ECX + 0xc) = local_24 + (int)local_1c;
      *(void **)(in_ECX + 8) = (void *)((int)local_1c + (param_2 + iVar1) * 0x24);
      *(void **)(in_ECX + 4) = local_1c;
    }
    else {
      local_2c = *(int *)(in_ECX + 8);
      if ((uint)((local_2c - param_1) / 0x24) < param_2) {
        local_28 = param_2 * 0x24;
        FUN_005c1190(param_1,local_2c,local_28 + param_1);
        local_8 = 2;
        FUN_005c1410(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x24,
                     &local_64);
        local_8 = 0xffffffff;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_28;
        FUN_005c1290(param_1,*(int *)(in_ECX + 8) - local_28,&local_64);
      }
      else {
        local_30 = local_2c + param_2 * -0x24;
        uVar3 = FUN_005c1190(local_30,local_2c,local_2c);
        *(undefined4 *)(in_ECX + 8) = uVar3;
        FUN_005c10f0(param_1,local_30,local_2c,local_40);
        FUN_005c1290(param_1,param_2 * 0x24 + param_1,&local_64);
      }
    }
  }
  if (local_44 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_58);
  return;
}


// ==== Catch@005c1619 @ 0x005c1619 ====

void Catch_005c1619(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_0069d5e0(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@005c16cd @ 0x005c16cd ====

void Catch_005c16cd(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x24;
  FUN_0069d5e0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x1c) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005c1760 @ 0x005c1760 ====

void FUN_005c1760(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  FUN_0069d3a0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_005c17a0 @ 0x005c17a0 ====

void FUN_005c17a0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x24 != 0) {
      iVar1 = (param_2 - iVar1) / 0x24;
      goto LAB_005c17e5;
    }
  }
  iVar1 = 0;
LAB_005c17e5:
  FUN_005c1440(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x24;
  return;
}


// ==== FUN_005c1810 @ 0x005c1810 ====

void FUN_005c1810(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x24) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x24))) {
    FUN_005c17a0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_005c12d0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x24;
  return;
}


// ==== FUN_005c18a0 @ 0x005c18a0 ====

void FUN_005c18a0(byte param_1)

{
  void *in_ECX;
  
  FUN_005c0480();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005c18c0 @ 0x005c18c0 ====

void FUN_005c18c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c248c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005c18e0 @ 0x005c18e0 ====

undefined4 FUN_005c18e0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  
  piVar3 = *(int **)(in_ECX + 0x58);
  piVar1 = *(int **)(in_ECX + 0x5c);
  do {
    if (piVar3 == piVar1) {
      return 0;
    }
    if (*piVar3 != 0) {
      iVar2 = FUN_004b9df0(in_ECX + 0x38);
      if (iVar2 != 0) {
        return 1;
      }
    }
    piVar3 = piVar3 + 1;
  } while( true );
}


// ==== FUN_005c1920 @ 0x005c1920 ====

void FUN_005c1920(void)

{
  int in_ECX;
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)(in_ECX + 0x5c);
  for (piVar1 = *(int **)(in_ECX + 0x58); piVar1 != piVar2; piVar1 = piVar1 + 1) {
    if (*piVar1 != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(*piVar1);
    }
  }
  if (*(void **)(in_ECX + 0x58) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x58));
    return;
  }
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  piVar1 = *(int **)(in_ECX + 0x6c);
  for (piVar2 = *(int **)(in_ECX + 0x68); piVar2 != piVar1; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(*piVar2);
    }
  }
  if (*(void **)(in_ECX + 0x68) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x68) = 0;
    *(undefined4 *)(in_ECX + 0x6c) = 0;
    *(undefined4 *)(in_ECX + 0x70) = 0;
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x68));
  return;
}


// ==== FUN_005c1a00 @ 0x005c1a00 ====

void FUN_005c1a00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c24a4;
  FUN_005c1920();
  if ((void *)in_ECX[0x1a] != (void *)0x0) {
    _free((void *)in_ECX[0x1a]);
    return;
  }
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  if ((void *)in_ECX[0x16] != (void *)0x0) {
    _free((void *)in_ECX[0x16]);
    return;
  }
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  if (0xf < (uint)in_ECX[0x14]) {
    _free((void *)in_ECX[0xf]);
    return;
  }
  in_ECX[0x14] = 0xf;
  in_ECX[0x13] = 0;
  *(undefined1 *)(in_ECX + 0xf) = 0;
  if ((uint)in_ECX[0xd] < 0x10) {
    in_ECX[0xc] = 0;
    in_ECX[0xd] = 0xf;
    *(undefined1 *)(in_ECX + 8) = 0;
    *in_ECX = &PTR_FUN_009c248c;
    return;
  }
  _free((void *)in_ECX[8]);
  return;
}


// ==== FUN_005c1a90 @ 0x005c1a90 ====

void FUN_005c1a90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c24a4;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[0xd] = 0xf;
  in_ECX[0xc] = 0;
  *(undefined1 *)(in_ECX + 8) = 0;
  FUN_00401740(s_picking_009c2478,7);
  in_ECX[0x14] = 0xf;
  in_ECX[0x13] = 0;
  *(undefined1 *)(in_ECX + 0xf) = 0;
  FUN_00401740(s_ground_009c2480,6);
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  return;
}


// ==== FUN_005c1b10 @ 0x005c1b10 ====

void FUN_005c1b10(int *param_1)

{
  int *piVar1;
  char cVar2;
  
  piVar1 = param_1;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x1c))();
    cVar2 = (**(code **)(*piVar1 + 0x2c))();
    if (cVar2 != '\0') {
      FUN_005c2480(&param_1);
      return;
    }
    FUN_005c2480(&param_1);
  }
  return;
}


// ==== FUN_005c1b60 @ 0x005c1b60 ====

uint FUN_005c1b60(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int in_ECX;
  undefined4 *_Dst;
  undefined4 *puVar5;
  undefined4 *local_8;
  int *local_4;
  
  uVar4 = *(uint *)(in_ECX + 0x68);
  if ((uVar4 != 0) && ((int)(*(int *)(in_ECX + 0x6c) - uVar4) >> 2 != 0)) {
    _Dst = *(undefined4 **)(in_ECX + 0x68);
    puVar5 = *(undefined4 **)(in_ECX + 0x6c);
    if (_Dst != puVar5) {
      local_8 = _Dst + 1;
      do {
        piVar1 = (int *)*_Dst;
        local_4 = piVar1;
        cVar3 = (**(code **)(*piVar1 + 0x2c))();
        if (cVar3 == '\0') {
          _Dst = _Dst + 1;
          local_8 = local_8 + 1;
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x58);
          if ((iVar2 == 0) ||
             ((uint)(*(int *)(in_ECX + 0x60) - iVar2 >> 2) <=
              (uint)(*(int *)(in_ECX + 0x5c) - iVar2 >> 2))) {
            FUN_005c2140(*(undefined4 *)(in_ECX + 0x5c),1,&local_4);
          }
          else {
            puVar5 = *(undefined4 **)(in_ECX + 0x5c);
            *puVar5 = piVar1;
            *(undefined4 **)(in_ECX + 0x5c) = puVar5 + 1;
          }
          _memmove(_Dst,local_8,(*(int *)(in_ECX + 0x6c) - (int)local_8 >> 2) * 4);
          *(int *)(in_ECX + 0x6c) = *(int *)(in_ECX + 0x6c) + -4;
          puVar5 = *(undefined4 **)(in_ECX + 0x6c);
        }
      } while (_Dst != puVar5);
    }
    uVar4 = *(uint *)(in_ECX + 0x68);
    if ((uVar4 != 0) && ((int)(*(int *)(in_ECX + 0x6c) - uVar4) >> 2 != 0)) {
      return uVar4 & 0xffffff00;
    }
  }
  return CONCAT31((int3)(uVar4 >> 8),1);
}


// ==== FUN_005c1c50 @ 0x005c1c50 ====

uint FUN_005c1c50(int param_1,float *param_2,float *param_3)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  float *pfVar8;
  uint uVar9;
  ushort *puVar10;
  uint extraout_EAX;
  uint extraout_EAX_00;
  ushort *puVar11;
  ushort *puVar12;
  undefined1 local_20 [4];
  undefined1 local_1c [16];
  float *local_c;
  float *local_8;
  undefined4 local_4;
  
  uVar9 = FUN_0040dfb0(param_2,param_1 + 0x1c,param_1 + 0x28,local_20);
  if ((char)uVar9 == '\0') {
    return uVar9;
  }
  puVar2 = *(ushort **)(param_1 + 0x4c);
  puVar11 = *(ushort **)(param_1 + 0x48);
  local_c = (float *)0x0;
  local_8 = (float *)0x0;
  local_4 = 0;
  puVar10 = puVar2;
  if (puVar11 != puVar2) {
    do {
      iVar3 = *(int *)(param_1 + 0x38);
      uVar1 = *puVar11;
      puVar10 = puVar11 + 1;
      if ((iVar3 == 0) || ((uint)((*(int *)(param_1 + 0x3c) - iVar3) / 0x28) <= (uint)uVar1)) {
LAB_005c1db5:
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      puVar12 = puVar11 + 2;
      if ((iVar3 == 0) || ((uint)((*(int *)(param_1 + 0x3c) - iVar3) / 0x28) <= (uint)*puVar10))
      goto LAB_005c1db5;
      iVar4 = *(int *)(param_1 + 0x38);
      puVar11 = puVar11 + 3;
      if ((iVar4 == 0) || ((uint)((*(int *)(param_1 + 0x3c) - iVar4) / 0x28) <= (uint)*puVar12))
      goto LAB_005c1db5;
      puVar10 = (ushort *)
                FUN_0040e5f0(param_2,iVar3 + (uint)uVar1 * 0x28,iVar3 + (uint)*puVar10 * 0x28,
                             iVar4 + (uint)*puVar12 * 0x28,local_1c);
      if ((char)puVar10 != '\0') {
        puVar10 = (ushort *)FUN_005c2400(local_1c);
      }
    } while (puVar11 != puVar2);
    if (local_c != (float *)0x0) {
      if (((int)local_8 - (int)local_c) / 0xc == 0) {
        _free(local_c);
        return extraout_EAX;
      }
      *param_3 = *local_c;
      param_3[1] = local_c[1];
      param_3[2] = local_c[2];
      fVar6 = SQRT((*param_3 - *param_2) * (*param_3 - *param_2) +
                   (param_3[1] - param_2[1]) * (param_3[1] - param_2[1]) +
                   (param_3[2] - param_2[2]) * (param_3[2] - param_2[2]));
      pfVar8 = local_c;
      while (pfVar7 = pfVar8, pfVar8 = pfVar7 + 3, pfVar8 != local_8) {
        fVar5 = SQRT((*pfVar8 - *param_2) * (*pfVar8 - *param_2) +
                     (pfVar7[4] - param_2[1]) * (pfVar7[4] - param_2[1]) +
                     (pfVar7[5] - param_2[2]) * (pfVar7[5] - param_2[2]));
        if (fVar5 < fVar6) {
          *param_3 = *pfVar8;
          param_3[1] = pfVar7[4];
          param_3[2] = pfVar7[5];
          fVar6 = fVar5;
        }
      }
      _free(local_c);
      return extraout_EAX_00;
    }
  }
  return (uint)puVar10 & 0xffffff00;
}


// ==== FUN_005c1e80 @ 0x005c1e80 ====

undefined4 FUN_005c1e80(int param_1,byte *param_2,undefined4 *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  char cVar7;
  int iVar8;
  int in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  pbVar5 = param_2;
  if ((*param_2 & 5) == 0) {
    return 0;
  }
  iVar8 = FUN_004b9df0(in_ECX + 0x1c);
  puVar6 = param_3;
  if (iVar8 == 0) {
    local_c = *(undefined4 *)(param_1 + 0x70);
    local_8 = *(undefined4 *)(param_1 + 0x74);
    local_4 = *(undefined4 *)(param_1 + 0x78);
    local_18 = *(undefined4 *)(param_1 + 0x7c);
    local_14 = *(undefined4 *)(param_1 + 0x80);
    local_10 = *(undefined4 *)(param_1 + 0x84);
    cVar7 = FUN_0040dfb0(pbVar5 + 0xc,&local_c,&local_18,&param_2);
    if (cVar7 != '\0') {
      fVar1 = *(float *)(pbVar5 + 0x1c);
      fVar2 = *(float *)(pbVar5 + 0x20);
      fVar3 = *(float *)(pbVar5 + 0x10);
      fVar4 = *(float *)(pbVar5 + 0x14);
      param_3[2] = *(float *)(pbVar5 + 0xc) + *(float *)(pbVar5 + 0x18) * (float)param_2;
      param_3[3] = fVar3 + fVar1 * (float)param_2;
      *param_3 = 1;
      param_3[4] = fVar4 + fVar2 * (float)param_2;
      return 1;
    }
  }
  else {
    cVar7 = FUN_005c1c50(iVar8,pbVar5 + 0xc,param_3 + 2);
    if (cVar7 != '\0') {
      *puVar6 = 1;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_005c1fb0 @ 0x005c1fb0 ====

char FUN_005c1fb0(int param_1,undefined4 *param_2)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  char cVar6;
  int in_ECX;
  int *piVar7;
  float local_1c;
  undefined4 local_14;
  undefined4 local_10;
  float local_c;
  float local_8;
  float local_4;
  
  cVar5 = FUN_005c1b60();
  if (cVar5 == '\0') {
    return '\0';
  }
  piVar1 = *(int **)(in_ECX + 0x5c);
  piVar7 = *(int **)(in_ECX + 0x58);
  cVar5 = '\0';
  local_1c = 0.0;
  if (piVar7 != piVar1) {
    cVar5 = '\0';
    do {
      if ((*piVar7 != 0) && (cVar6 = FUN_005c1e80(*piVar7,param_1,&local_14), cVar6 != '\0')) {
        fVar2 = local_c - *(float *)(param_1 + 0xc);
        fVar4 = local_8 - *(float *)(param_1 + 0x10);
        fVar3 = local_4 - *(float *)(param_1 + 0x14);
        fVar2 = SQRT(fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3);
        if (cVar5 == '\0') {
          *param_2 = local_14;
          param_2[1] = local_10;
          param_2[2] = local_c;
          param_2[3] = local_8;
          cVar5 = '\x01';
          param_2[4] = local_4;
        }
        else {
          if (local_1c <= fVar2) goto LAB_005c20a8;
          *param_2 = local_14;
          param_2[1] = local_10;
          param_2[2] = local_c;
          param_2[3] = local_8;
          param_2[4] = local_4;
        }
        local_1c = fVar2;
      }
LAB_005c20a8:
      piVar7 = piVar7 + 1;
    } while (piVar7 != piVar1);
  }
  return cVar5;
}


// ==== FUN_005c20d0 @ 0x005c20d0 ====

void FUN_005c20d0(byte param_1)

{
  void *in_ECX;
  
  FUN_005c1a00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005c20f0 @ 0x005c20f0 ====

undefined4 FUN_005c20f0(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x3fffffff < param_1) {
    param_1 = FUN_0085b3b0();
  }
  pvVar1 = operator_new(param_1 * 4);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 4 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_005c2140 @ 0x005c2140 ====

void FUN_005c2140(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_009829f0;
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


// ==== Catch@005c22a1 @ 0x005c22a1 ====

void Catch_005c22a1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_005c2390 @ 0x005c2390 ====

void FUN_005c2390(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0xc != 0) {
      iVar1 = (param_2 - iVar1) / 0xc;
      goto LAB_005c23d3;
    }
  }
  iVar1 = 0;
LAB_005c23d3:
  FUN_00446310(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0xc;
  return;
}


// ==== FUN_005c2400 @ 0x005c2400 ====

void FUN_005c2400(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0xc) <= (uint)((*(int *)(in_ECX + 8) - iVar1) / 0xc)
     )) {
    FUN_005c2390(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0042ea70(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0xc;
  return;
}


// ==== FUN_005c2480 @ 0x005c2480 ====

void FUN_005c2480(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_005c2140(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_005c24d0 @ 0x005c24d0 ====

void FUN_005c24d0(void)

{
  FUN_005ca9e0();
  return;
}


// ==== FUN_005c24e0 @ 0x005c24e0 ====

void FUN_005c24e0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_005ca7a0();
  *param_1 = uVar1;
  return;
}


// ==== FUN_005c2500 @ 0x005c2500 ====

void FUN_005c2500(void)

{
  FUN_005ca7b0();
  return;
}


// ==== FUN_005c2520 @ 0x005c2520 ====

void FUN_005c2520(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_005c2530 @ 0x005c2530 ====

void FUN_005c2530(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x6d) = param_1;
  return;
}


// ==== FUN_005c2540 @ 0x005c2540 ====

void FUN_005c2540(void)

{
  FUN_005ca7c0();
  return;
}


// ==== FUN_005c2570 @ 0x005c2570 ====

void FUN_005c2570(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  float fVar2;
  float fVar3;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  *(undefined4 *)(in_ECX + 0x30) = param_1[3];
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x78) + 8))((undefined4 *)(in_ECX + 4));
  if (iVar1 == 0) {
    FUN_005caad0();
    return;
  }
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(iVar1 + 0x1c);
  FUN_005cab40(iVar1);
  fVar2 = (float)param_1[4] * *(float *)(in_ECX + 0x34);
  fVar3 = DAT_0099d080;
  if (fVar2 <= DAT_0099d080) {
    fVar3 = fVar2;
  }
  FUN_005ca8b0(*(undefined4 *)(in_ECX + 0x30),fVar3,0);
  return;
}


// ==== FUN_005c2600 @ 0x005c2600 ====

void FUN_005c2600(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x30) = param_1;
  FUN_005ca8b0();
  return;
}


// ==== FUN_005c2640 @ 0x005c2640 ====

undefined4 FUN_005c2640(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  piVar1 = (int *)FUN_005ca7a0();
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xc))(param_1);
    if (iVar2 != 0) {
      puVar4 = (undefined4 *)(iVar2 + 0xe0);
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *param_1 = *puVar4;
        puVar4 = puVar4 + 1;
        param_1 = param_1 + 1;
      }
      return 1;
    }
  }
  return 0;
}


// ==== FUN_005c2680 @ 0x005c2680 ====

void FUN_005c2680(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = DAT_0099d080;
  *in_ECX = &PTR_FUN_009c24bc;
  in_ECX[1] = 0;
  in_ECX[2] = 0x20;
  in_ECX[3] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  in_ECX[0xb] = 0xf;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  in_ECX[0xd] = uVar1;
  FUN_005caa30();
  in_ECX[0x1e] = param_1;
  return;
}


// ==== FUN_005c26d0 @ 0x005c26d0 ====

void FUN_005c26d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c24bc;
  if (in_ECX[0x1e] != 0) {
    (**(code **)(*DAT_00b5aff0 + 8))(in_ECX[0x1e]);
    in_ECX[0x1e] = 0;
  }
  FUN_005caa70();
  if ((uint)in_ECX[0xb] < 0x10) {
    in_ECX[0xb] = 0xf;
    in_ECX[10] = 0;
    *(undefined1 *)(in_ECX + 6) = 0;
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_005c2730 @ 0x005c2730 ====

void FUN_005c2730(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 0x78) + 4))();
  FUN_00401660(uVar1,0,0xffffffff);
  FUN_005ca810(in_ECX + 0x14,*(undefined1 *)(in_ECX + 0x10));
  FUN_005caad0();
  return;
}


// ==== FUN_005c2770 @ 0x005c2770 ====

void FUN_005c2770(byte param_1)

{
  void *in_ECX;
  
  FUN_005c26d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005c2790 @ 0x005c2790 ====

void FUN_005c2790(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2504;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005c27b0 @ 0x005c27b0 ====

void FUN_005c27b0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x24) = param_1;
  FUN_005c2540(param_2);
  return;
}


// ==== FUN_005c27d0 @ 0x005c27d0 ====

void FUN_005c27d0(void)

{
  FUN_005bf580();
  return;
}


// ==== FUN_005c27e0 @ 0x005c27e0 ====

int FUN_005c27e0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_005c27f0 @ 0x005c27f0 ====

undefined4 FUN_005c27f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x24);
}


// ==== FUN_005c2800 @ 0x005c2800 ====

void FUN_005c2800(void)

{
  FUN_005c2640();
  return;
}


// ==== FUN_005c2810 @ 0x005c2810 ====

void FUN_005c2810(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x48) = param_1;
  return;
}


// ==== FUN_005c2820 @ 0x005c2820 ====

undefined4 FUN_005c2820(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x28) == 0) {
    return 0xffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x005c282f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(in_ECX + 0x28) + 0x20))();
  return uVar1;
}


// ==== FUN_005c2840 @ 0x005c2840 ====

void FUN_005c2840(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x28) == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x005c284d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x28) + 0x28))();
  return;
}


// ==== FUN_005c2860 @ 0x005c2860 ====

undefined4 FUN_005c2860(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x28) != 0) {
    do {
      iVar1 = (**(code **)(**(int **)(in_ECX + 0x28) + 0x48))();
      if (iVar1 == 2) {
        return *(undefined4 *)(in_ECX + 0x28);
      }
      in_ECX = *(int *)(in_ECX + 0x28);
    } while (*(int *)(in_ECX + 0x28) != 0);
  }
  return 0;
}


// ==== FUN_005c2890 @ 0x005c2890 ====

void FUN_005c2890(void)

{
  char cVar1;
  int in_ECX;
  int iVar2;
  undefined1 **ppuVar3;
  undefined1 *puStack_cc;
  undefined1 local_c0 [52];
  undefined1 auStack_8c [8];
  undefined1 auStack_84 [56];
  undefined1 *apuStack_4c [17];
  undefined4 *puStack_8;
  
  puStack_cc = local_c0;
  (**(code **)(**(int **)(in_ECX + 0x28) + 0x2c))();
  cVar1 = (**(code **)(**(int **)(in_ECX + 0x28) + 0x30))(*(undefined4 *)(in_ECX + 0x24),auStack_84)
  ;
  if (cVar1 == '\0') {
    ppuVar3 = &puStack_cc;
  }
  else {
    thunk_FUN_0079ee7b(apuStack_4c,auStack_8c,&puStack_cc);
    ppuVar3 = apuStack_4c;
  }
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puStack_8 = *ppuVar3;
    ppuVar3 = ppuVar3 + 1;
    puStack_8 = puStack_8 + 1;
  }
  return;
}


// ==== FUN_005c2900 @ 0x005c2900 ====

void FUN_005c2900(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  *(int **)(in_ECX + 0x28) = param_1;
  if (param_1 != (int *)0x0) {
    iVar1 = (**(code **)(*param_1 + 0x48))();
    if (iVar1 == 2) {
      iVar1 = *(int *)(in_ECX + 0x28);
    }
    else {
      iVar1 = FUN_005c2860();
    }
    if (iVar1 != 0) {
      uVar2 = FUN_005c2860();
      FUN_005bf590(uVar2);
    }
  }
  return;
}


// ==== FUN_005c2940 @ 0x005c2940 ====

void FUN_005c2940(undefined4 *param_1)

{
  char cVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
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
  
  if (*(int *)(in_ECX + 0x28) != 0) {
    cVar1 = (**(code **)(**(int **)(in_ECX + 0x28) + 0x30))(*(undefined4 *)(in_ECX + 0x24),local_40)
    ;
    if (cVar1 != '\0') goto LAB_005c29cd;
  }
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
LAB_005c29cd:
  puVar3 = local_40;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *puVar3;
    puVar3 = puVar3 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_005c29f0 @ 0x005c29f0 ====

void FUN_005c29f0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_40 [64];
  
  puVar1 = (undefined4 *)FUN_005c2940(local_40);
  puVar3 = param_1;
  for (iVar2 = 0x10; puVar3 = puVar3 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
  }
  FUN_005c24e0(param_1);
  FUN_005c0830(param_1);
  param_1[0x11] = *(undefined4 *)(in_ECX + 0x48);
  return;
}


// ==== FUN_005c2a40 @ 0x005c2a40 ====

void FUN_005c2a40(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x28) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x28) + 0x48))();
    if (iVar1 == 2) {
      iVar1 = *(int *)(in_ECX + 0x28);
    }
    else {
      iVar1 = FUN_005c2860();
    }
  }
  FUN_005c2530(*(undefined1 *)(iVar1 + 0x39));
  FUN_005c2500(param_1);
  return;
}


// ==== FUN_005c2a90 @ 0x005c2a90 ====

undefined4 FUN_005c2a90(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *puStack_c8;
  undefined1 local_c0 [56];
  undefined1 auStack_88 [8];
  undefined1 local_80 [44];
  undefined4 auStack_54 [3];
  undefined1 auStack_48 [60];
  undefined4 *puStack_c;
  
  puStack_c8 = local_80;
  FUN_005c2940();
  puStack_c8 = local_c0;
  cVar1 = FUN_005c24d0(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  thunk_FUN_0079ee7b(auStack_48,&puStack_c8,auStack_88);
  puVar3 = auStack_54;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puStack_c = *puVar3;
    puVar3 = puVar3 + 1;
    puStack_c = puStack_c + 1;
  }
  return 1;
}


// ==== FUN_005c2b10 @ 0x005c2b10 ====

void FUN_005c2b10(void)

{
  int unaff_ESI;
  undefined1 *puVar1;
  undefined1 local_70 [24];
  undefined1 local_58 [12];
  undefined1 auStack_4c [12];
  undefined1 local_40 [44];
  int *piStack_14;
  
  FUN_005c2940(local_40);
  FUN_005bf5c0(local_58);
  puVar1 = local_40;
  thunk_FUN_0079e5a0();
  thunk_FUN_0079e5a0(local_70);
  *piStack_14 = (int)local_58;
  piStack_14[1] = (int)auStack_4c;
  piStack_14[2] = (int)local_70;
  piStack_14[3] = (int)local_58;
  piStack_14[4] = (int)puVar1;
  piStack_14[5] = unaff_ESI;
  return;
}


// ==== FUN_005c2b90 @ 0x005c2b90 ====

uint FUN_005c2b90(void)

{
  float *pfVar1;
  float *pfVar2;
  undefined4 *puVar3;
  float fVar4;
  float fVar5;
  char cVar6;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 *puVar7;
  float unaff_EDI;
  undefined1 *puVar8;
  undefined4 uStack_a4;
  float local_a0;
  float fStack_9c;
  undefined1 auStack_94 [20];
  undefined1 local_80 [52];
  undefined1 auStack_4c [12];
  undefined1 local_40 [48];
  undefined4 uStack_10;
  int iStack_8;
  undefined4 *puStack_4;
  
  uStack_a4 = (float)(uint)(uint3)uStack_a4;
  local_a0 = 0.0;
  FUN_005c2940(local_80);
  puVar8 = local_80;
  thunk_FUN_0079f3a1(local_40,0);
  pfVar1 = (float *)(iStack_8 + 0xc);
  FUN_0040e920(&uStack_a4,pfVar1,auStack_4c);
  cVar6 = FUN_005bf570(iStack_8,puStack_4);
  if (cVar6 == '\x01') {
    pfVar2 = (float *)(puStack_4 + 2);
    puVar8 = (undefined1 *)0x1000000;
    thunk_FUN_0079e5a0(pfVar2,pfVar2,auStack_94);
    fVar5 = *(float *)(iStack_8 + 0x10) - (float)puStack_4[3];
    fVar4 = *(float *)(iStack_8 + 0x14) - (float)puStack_4[4];
    unaff_EDI = SQRT((*pfVar1 - *pfVar2) * (*pfVar1 - *pfVar2) + fVar5 * fVar5 + fVar4 * fVar4);
  }
  puVar3 = *(undefined4 **)(in_ECX + 0x54);
  for (puVar7 = *(undefined4 **)(in_ECX + 0x50); puVar7 != puVar3; puVar7 = puVar7 + 1) {
    cVar6 = (**(code **)(*(int *)*puVar7 + 8))(uStack_10,auStack_94 + -0x18);
    if (cVar6 != '\0') {
      if ((char)((uint)puVar8 >> 0x18) == '\0') {
        *puStack_4 = unaff_EBP;
        puStack_4[1] = unaff_EBX;
        puStack_4[2] = uStack_a4;
        puStack_4[3] = local_a0;
        puStack_4[4] = fStack_9c;
        puVar8 = (undefined1 *)0x1000000;
        fVar5 = (float)puStack_4[3] - *(float *)(iStack_8 + 0x10);
        fVar4 = (float)puStack_4[4] - *(float *)(iStack_8 + 0x14);
        unaff_EDI = SQRT(((float)puStack_4[2] - *pfVar1) * ((float)puStack_4[2] - *pfVar1) +
                         fVar5 * fVar5 + fVar4 * fVar4);
      }
      else {
        fVar5 = local_a0 - *(float *)(iStack_8 + 0x10);
        fVar4 = fStack_9c - *(float *)(iStack_8 + 0x14);
        fVar4 = SQRT((uStack_a4 - *pfVar1) * (uStack_a4 - *pfVar1) + fVar5 * fVar5 + fVar4 * fVar4);
        if (fVar4 < unaff_EDI) {
          *puStack_4 = unaff_EBP;
          puStack_4[1] = unaff_EBX;
          puStack_4[2] = uStack_a4;
          puStack_4[3] = local_a0;
          puStack_4[4] = fStack_9c;
          unaff_EDI = fVar4;
        }
      }
    }
  }
  return (uint)puVar8 >> 0x18;
}


// ==== FUN_005c2d50 @ 0x005c2d50 ====

undefined4 FUN_005c2d50(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 *puVar5;
  undefined4 unaff_retaddr;
  undefined4 uStack_50;
  undefined1 auStack_42 [58];
  undefined4 uStack_8;
  
  if (param_1 == 0) {
    return 0;
  }
  uStack_50 = param_2;
  cVar3 = FUN_005c24d0(param_1);
  if (cVar3 != '\0') {
    return 1;
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x54);
  puVar5 = *(undefined4 **)(in_ECX + 0x50);
  while( true ) {
    if (puVar5 == puVar1) {
      return 0;
    }
    piVar2 = (int *)*puVar5;
    cVar3 = (**(code **)(*piVar2 + 0x18))(param_1,unaff_retaddr);
    if (cVar3 != '\0') break;
    puVar5 = puVar5 + 1;
  }
  uVar4 = (**(code **)(*piVar2 + 0x70))(auStack_42 + -6);
  cVar3 = FUN_005c24d0(uVar4);
  if (cVar3 == '\x01') {
    thunk_FUN_0079ee7b(uStack_8,uStack_8,&uStack_50);
  }
  return 1;
}


// ==== FUN_005c2e00 @ 0x005c2e00 ====

void FUN_005c2e00(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  *(undefined4 *)(in_ECX + 0x34) = *param_1;
  *(undefined4 *)(in_ECX + 0x38) = param_1[1];
  *(undefined4 *)(in_ECX + 0x3c) = param_1[2];
  *(undefined4 *)(in_ECX + 0x40) = param_1[3];
  *(undefined4 *)(in_ECX + 0x44) = param_1[4];
  FUN_005c2570(param_1);
  puVar1 = *(undefined4 **)(in_ECX + 0x54);
  for (puVar2 = *(undefined4 **)(in_ECX + 0x50); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(*(int *)*puVar2 + 0x60))(param_1);
  }
  return;
}


// ==== FUN_005c2e60 @ 0x005c2e60 ====

void FUN_005c2e60(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 unaff_EBP;
  undefined4 *puVar4;
  
  if ((*(int *)(in_ECX + 0x28) != 0) &&
     (iVar2 = (**(code **)(**(int **)(in_ECX + 0x28) + 0x48))(), iVar2 != 2)) {
    FUN_005c2860();
  }
  uVar3 = FUN_005c7f00();
  FUN_005c2600(param_2,param_3,uVar3);
  puVar1 = *(undefined4 **)(in_ECX + 0x54);
  for (puVar4 = *(undefined4 **)(in_ECX + 0x50); puVar4 != puVar1; puVar4 = puVar4 + 1) {
    (**(code **)(*(int *)*puVar4 + 100))(unaff_EBP,param_2,param_3);
  }
  return;
}


// ==== FUN_005c2ed0 @ 0x005c2ed0 ====

void FUN_005c2ed0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2554;
  FUN_004eb890(in_ECX + 0x13);
  if ((undefined4 *)in_ECX[0xc] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xc])(1);
  }
  in_ECX[0xc] = 0;
  if ((undefined4 *)in_ECX[0xb] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xb])(1);
  }
  in_ECX[0xb] = 0;
  in_ECX[10] = 0;
  if ((void *)in_ECX[0x14] != (void *)0x0) {
    _free((void *)in_ECX[0x14]);
    return;
  }
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[7] = 0;
    in_ECX[8] = 0xf;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_009c2504;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_005c2f50 @ 0x005c2f50 ====

undefined4 FUN_005c2f50(int param_1)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  
  if ((uint)in_ECX[8] < 0x10) {
    piVar2 = in_ECX + 3;
  }
  else {
    piVar2 = (int *)in_ECX[3];
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x18),piVar2,in_ECX[7]);
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x20);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      FUN_005c0190(param_1 + 0x24);
      goto LAB_005c2faa;
    }
    if (iVar1 != 2) goto LAB_005c2faa;
    FUN_005bfed0();
  }
  FUN_005bfbf0(param_1 + 0x24);
LAB_005c2faa:
  piVar2 = (int *)(**(code **)(*in_ECX + 0x28))();
  (**(code **)(*piVar2 + 0x24))();
  return 1;
}


// ==== FUN_005c2fd0 @ 0x005c2fd0 ====

/* WARNING: Removing unreachable block (ram,0x005c3029) */

undefined4 FUN_005c2fd0(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  int in_ECX;
  uint uVar7;
  undefined4 *_Dst;
  bool bVar8;
  bool bVar9;
  byte *pbStack_c;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    return 0;
  }
  _Dst = *(undefined4 **)(in_ECX + 0x50);
  puVar1 = *(undefined4 **)(in_ECX + 0x54);
  do {
    if (_Dst == puVar1) {
      return 0;
    }
    piVar2 = (int *)*_Dst;
    iVar5 = (**(code **)(*piVar2 + 0x6c))();
    uVar3 = *(uint *)(param_1 + 0x18);
    if (*(uint *)(param_1 + 0x1c) < 0x10) {
      pbStack_c = (byte *)(param_1 + 8);
    }
    else {
      pbStack_c = *(byte **)(param_1 + 8);
    }
    uVar4 = *(uint *)(iVar5 + 0x14);
    if (uVar4 == 0) {
LAB_005c3063:
      if ((uVar3 <= uVar4) && (uVar4 == uVar3)) {
        (**(code **)*piVar2)(1);
        _memmove(_Dst,_Dst + 1,(puVar1[0x15] - (int)(_Dst + 1) >> 2) * 4);
        puVar1[0x15] = puVar1[0x15] + -4;
        return 1;
      }
    }
    else {
      uVar7 = uVar4;
      if (uVar3 <= uVar4) {
        uVar7 = uVar3;
      }
      if (*(uint *)(iVar5 + 0x18) < 0x10) {
        pbVar6 = (byte *)(iVar5 + 4);
      }
      else {
        pbVar6 = *(byte **)(iVar5 + 4);
      }
      bVar8 = false;
      iVar5 = 0;
      bVar9 = true;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        bVar8 = *pbVar6 < *pbStack_c;
        bVar9 = *pbVar6 == *pbStack_c;
        pbVar6 = pbVar6 + 1;
        pbStack_c = pbStack_c + 1;
      } while (bVar9);
      if (!bVar9) {
        iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      }
      if (iVar5 == 0) goto LAB_005c3063;
    }
    _Dst = _Dst + 1;
  } while( true );
}


// ==== FUN_005c30d0 @ 0x005c30d0 ====

void FUN_005c30d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2554;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0xe] = 0x20;
  in_ECX[0x12] = 3;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[1] = 3;
  in_ECX[0xb] = param_2;
  in_ECX[0xc] = param_3;
  return;
}


// ==== FUN_005c3140 @ 0x005c3140 ====

void FUN_005c3140(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x54);
  for (puVar4 = *(undefined4 **)(in_ECX + 0x50); puVar4 != puVar1; puVar4 = puVar4 + 1) {
    (**(code **)(*(int *)*puVar4 + 0x50))(param_1,param_2,param_3);
  }
  if ((*(int *)(in_ECX + 0x50) == 0) ||
     (*(int *)(in_ECX + 0x54) - *(int *)(in_ECX + 0x50) >> 2 == 0)) {
    if (*(uint *)(param_2 + 0x18) < 0x10) {
      iVar3 = param_2 + 4;
    }
    else {
      iVar3 = *(int *)(param_2 + 4);
    }
    iVar3 = FUN_00403620(0,*(undefined4 *)(in_ECX + 0x1c),iVar3,*(undefined4 *)(param_2 + 0x14));
    if ((iVar3 == 0) && (cVar2 = FUN_005c06c0(param_1,param_3), cVar2 != '\0')) {
      FUN_00430ce0(in_ECX + 0x24);
    }
  }
  return;
}


// ==== FUN_005c31d0 @ 0x005c31d0 ====

undefined4 FUN_005c31d0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  undefined1 auStackY_98 [128];
  
  iVar1 = (**(code **)(*in_ECX + 0x6c))();
  if (*(uint *)(iVar1 + 0x18) < 0x10) {
    iVar2 = iVar1 + 4;
  }
  else {
    iVar2 = *(int *)(iVar1 + 4);
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x34),iVar2,*(undefined4 *)(iVar1 + 0x14));
  if (iVar1 == 0) {
    piVar3 = (int *)(**(code **)(*DAT_00b5afec + 8))(param_1);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x58))();
      (**(code **)(*piVar3 + 0x60))(in_ECX + 0xd);
      FUN_005c4470(auStackY_98 + 0x90);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_005c3250 @ 0x005c3250 ====

undefined4 FUN_005c3250(int *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x54);
  for (puVar4 = *(undefined4 **)(in_ECX + 0x50); puVar4 != puVar1; puVar4 = puVar4 + 1) {
    cVar2 = (**(code **)(*(int *)*puVar4 + 4))(param_1);
    if (cVar2 != '\0') {
      return 1;
    }
  }
  iVar3 = (**(code **)(*param_1 + 4))();
  if (iVar3 == 1) {
    cVar2 = FUN_005c2f50(param_1);
    if (cVar2 != '\0') {
      return 1;
    }
  }
  else if (iVar3 == 0x30) {
    cVar2 = FUN_005c31d0(param_1);
    if (cVar2 != '\0') {
      return 1;
    }
  }
  else if ((iVar3 == 0x31) && (cVar2 = FUN_005c2fd0(param_1), cVar2 != '\0')) {
    return 1;
  }
  return 0;
}


// ==== FUN_005c32e0 @ 0x005c32e0 ====

void FUN_005c32e0(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  void *_Memory;
  char cVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined1 local_c8 [4];
  void *pvStack_c4;
  undefined4 uStack_b4;
  uint uStack_b0;
  undefined1 auStack_ac [4];
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  void *pvStack_98;
  int iStack_94;
  undefined1 auStack_8c [4];
  void *pvStack_88;
  int iStack_84;
  undefined4 uStack_78;
  uint uStack_74;
  undefined1 auStack_70 [4];
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 auStack_60 [8];
  undefined1 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x54);
  for (puVar6 = *(undefined4 **)(in_ECX + 0x50); puVar6 != puVar1; puVar6 = puVar6 + 1) {
    (**(code **)(*(int *)*puVar6 + 0x14))(param_1,param_2);
  }
  if ((*(int *)(in_ECX + 0x50) == 0) ||
     (*(int *)(in_ECX + 0x54) - *(int *)(in_ECX + 0x50) >> 2 == 0)) {
    local_58 = 0;
    local_54 = 0xffffffff;
    uStack_4c = 0;
    uStack_4b = 0;
    uStack_8 = 0;
    uStack_7 = 0;
    uStack_b0 = 0xf;
    uStack_b4 = 0;
    pvStack_c4 = (void *)((uint)pvStack_c4 & 0xffffff00);
    local_50 = DAT_0099d080;
    FUN_00401740(s_traceline_009c24c4,9);
    cVar2 = FUN_005bf8c0(auStack_60,local_c8,1);
    if (0xf < uStack_b0) {
      _free(pvStack_c4);
      return;
    }
    if (cVar2 != '\0') {
      uStack_74 = 0xf;
      uStack_78 = 0;
      pvStack_88 = (void *)((uint)pvStack_88 & 0xffffff00);
      FUN_00401740(s_traceline_009c24d0,9);
      iVar3 = FUN_004b9e30(auStack_8c);
      if (0xf < uStack_74) {
        _free(pvStack_88);
        return;
      }
      uStack_74 = 0xf;
      uStack_78 = 0;
      pvStack_88 = (void *)((uint)pvStack_88 & 0xffffff00);
      uStack_b0 = 0xf;
      uStack_b4 = 0;
      pvStack_c4 = (void *)((uint)pvStack_c4 & 0xffffff00);
      FUN_00401740(s_traceline2_009c24dc,10);
      iVar4 = FUN_004b9e30(local_c8);
      if (0xf < uStack_b0) {
        _free(pvStack_c4);
        return;
      }
      uStack_b0 = 0xf;
      uStack_b4 = 0;
      pvStack_c4 = (void *)((uint)pvStack_c4 & 0xffffff00);
      uStack_6c = 0;
      uStack_68 = 0;
      uStack_64 = 0;
      uStack_a8 = 0;
      uStack_a4 = 0;
      uStack_a0 = 0;
      FUN_00439260(*(undefined4 *)(iVar3 + 0x20));
      if (pvStack_98 != (void *)0x0) {
        iVar3 = iStack_94 - (int)pvStack_98 >> 0x1f;
        iVar5 = (iStack_94 - (int)pvStack_98) / 0x1c + iVar3;
        if (iVar5 != iVar3) {
          FUN_005c43e0(pvStack_98);
          FUN_005c43e0(iStack_94 + -0x1c);
          if (iVar4 == 0) {
            if (iVar5 == iVar3) {
                    /* WARNING: Subroutine does not return */
              FUN_0085b340();
            }
            FUN_005c43e0(pvStack_98);
            FUN_005c43e0(iStack_94 + -0x1c);
            iVar3 = *(int *)(param_1 + 0x30);
            if ((iVar3 == 0) ||
               ((uint)(*(int *)(param_1 + 0x38) - iVar3 >> 2) <=
                (uint)(*(int *)(param_1 + 0x34) - iVar3 >> 2))) {
              FUN_0042f3e0(*(undefined4 *)(param_1 + 0x34),1,(undefined4 *)(in_ECX + 0x24));
            }
            else {
              puVar6 = *(undefined4 **)(param_1 + 0x34);
              *puVar6 = *(undefined4 *)(in_ECX + 0x24);
              *(undefined4 **)(param_1 + 0x34) = puVar6 + 1;
            }
            iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),&DAT_009c24e8,4);
            if ((iVar3 == 0) ||
               (iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),&DAT_009c24ed,0), iVar3 == 0)
               ) {
              uVar8 = 5;
              pcVar7 = s_right_009c24f0;
            }
            else {
              uVar8 = 6;
              pcVar7 = s_double_009c24f8;
            }
            FUN_00401740(pcVar7,uVar8);
            FUN_005c1360(auStack_60);
            FUN_005c4a70(auStack_70);
            FUN_005c4a70(auStack_ac);
            _free(pvStack_98);
            return;
          }
          FUN_00439260(*(undefined4 *)(iVar4 + 0x20));
          _Memory = pvStack_88;
          if ((pvStack_88 == (void *)0x0) || ((iStack_84 - (int)pvStack_88) / 0x1c == 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_0085b340();
          }
          FUN_005c43e0(pvStack_88);
          FUN_005c43e0(iStack_84 + -0x1c);
          _free(_Memory);
          return;
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
  }
  return;
}


// ==== FUN_005c3680 @ 0x005c3680 ====

void FUN_005c3680(undefined4 param_1,int param_2)

{
  char cVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 auStack_40 [6];
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
  
  puVar5 = *(undefined4 **)(in_ECX + 0x54);
  for (puVar4 = *(undefined4 **)(in_ECX + 0x50); puVar4 != puVar5; puVar4 = puVar4 + 1) {
    (**(code **)(*(int *)*puVar4 + 0xc))(param_1,param_2);
  }
  if (*(int *)(param_2 + 0x40) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (*(int *)(param_2 + 0x44) - *(int *)(param_2 + 0x40)) / 0x58;
  }
  FUN_005c4ae0(iVar3 + 1,0);
  iVar3 = *(int *)(param_2 + 0x44);
  if ((*(int *)(in_ECX + 0x28) == 0) ||
     (cVar1 = (**(code **)(**(int **)(in_ECX + 0x28) + 0x30))
                        (*(undefined4 *)(in_ECX + 0x24),auStack_40), cVar1 == '\0')) {
    uStack_8 = 0;
    uStack_c = 0;
    uStack_10 = 0;
    uStack_14 = 0;
    uStack_1c = 0;
    uStack_20 = 0;
    uStack_24 = 0;
    uStack_28 = 0;
    auStack_40[4] = 0;
    auStack_40[3] = 0;
    auStack_40[2] = 0;
    auStack_40[1] = 0;
    uStack_4 = DAT_0099d080;
    uStack_18 = DAT_0099d080;
    auStack_40[5] = DAT_0099d080;
    auStack_40[0] = DAT_0099d080;
  }
  puVar4 = auStack_40;
  puVar5 = (undefined4 *)(iVar3 + -0x54);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  FUN_005c24e0(iVar3 + -0x58);
  FUN_005c0830(iVar3 + -0x58);
  *(undefined4 *)(iVar3 + -0x14) = *(undefined4 *)(in_ECX + 0x48);
  return;
}


// ==== FUN_005c37b0 @ 0x005c37b0 ====

void FUN_005c37b0(int param_1)

{
  char cVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 auStack_40 [6];
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
  
  puVar5 = *(undefined4 **)(in_ECX + 0x54);
  for (puVar4 = *(undefined4 **)(in_ECX + 0x50); puVar4 != puVar5; puVar4 = puVar4 + 1) {
    (**(code **)(*(int *)*puVar4 + 0x4c))(param_1);
  }
  if (*(int *)(param_1 + 0x40) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (*(int *)(param_1 + 0x44) - *(int *)(param_1 + 0x40)) / 0x58;
  }
  FUN_005c4ae0(iVar3 + 1,0);
  iVar3 = *(int *)(param_1 + 0x44);
  if ((*(int *)(in_ECX + 0x28) == 0) ||
     (cVar1 = (**(code **)(**(int **)(in_ECX + 0x28) + 0x30))
                        (*(undefined4 *)(in_ECX + 0x24),auStack_40), cVar1 == '\0')) {
    uStack_8 = 0;
    uStack_c = 0;
    uStack_10 = 0;
    uStack_14 = 0;
    uStack_1c = 0;
    uStack_20 = 0;
    uStack_24 = 0;
    uStack_28 = 0;
    auStack_40[4] = 0;
    auStack_40[3] = 0;
    auStack_40[2] = 0;
    auStack_40[1] = 0;
    uStack_4 = DAT_0099d080;
    uStack_18 = DAT_0099d080;
    auStack_40[5] = DAT_0099d080;
    auStack_40[0] = DAT_0099d080;
  }
  puVar4 = auStack_40;
  puVar5 = (undefined4 *)(iVar3 + -0x54);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  FUN_005c24e0(iVar3 + -0x58);
  FUN_005c0830(iVar3 + -0x58);
  *(undefined4 *)(iVar3 + -0x14) = *(undefined4 *)(in_ECX + 0x48);
  return;
}


// ==== FUN_005c38e0 @ 0x005c38e0 ====

void FUN_005c38e0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  param_1[0xe] = 0;
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  param_1[0xb] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  param_1[7] = 0;
  param_1[6] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  uVar1 = DAT_0099d080;
  param_1[0xf] = DAT_0099d080;
  param_1[10] = uVar1;
  param_1[5] = uVar1;
  *param_1 = uVar1;
  return;
}


// ==== FUN_005c3950 @ 0x005c3950 ====

void FUN_005c3950(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982a00;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_005cf5b0(param_1,param_3);
    param_1 = param_1 + 0x1c;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005c39b6 @ 0x005c39b6 ====

void Catch_005c39b6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005c39c0 @ 0x005c39c0 ====

int FUN_005c39c0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982a10;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x60) {
    FUN_005b1900(param_3,param_1);
    param_3 = param_3 + 0x60;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@005c3a26 @ 0x005c3a26 ====

void Catch_005c3a26(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005c3a30 @ 0x005c3a30 ====

void FUN_005c3a30(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return;
}


// ==== FUN_005c3a50 @ 0x005c3a50 ====

int FUN_005c3a50(int param_1,int param_2,undefined4 param_3)

{
  FUN_005c3950(param_1,param_2,param_3);
  return param_1 + param_2 * 0x1c;
}


// ==== FUN_005c3a80 @ 0x005c3a80 ====

void FUN_005c3a80(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005c39c0(param_1,param_2,param_3);
  return;
}


// ==== FUN_005c3aa0 @ 0x005c3aa0 ====

void FUN_005c3aa0(byte param_1)

{
  void *in_ECX;
  
  FUN_005c2ed0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005c3ac0 @ 0x005c3ac0 ====

void FUN_005c3ac0(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  uint extraout_ECX;
  undefined4 *puVar3;
  undefined4 local_50;
  int local_2c;
  int local_28;
  uint local_24;
  undefined4 local_20;
  void *local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982a20;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x5c);
  puVar3 = &local_50;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_3;
    param_3 = param_3 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x1c;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x1c;
    }
    ExceptionList = &local_10;
    if (0x9249249U - iVar2 < param_2) {
      ExceptionList = &local_10;
      FUN_004389d0();
      local_24 = extraout_ECX;
    }
    if (*(int *)(in_ECX + 4) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x1c;
    }
    if (local_24 < iVar2 + param_2) {
      if (0x9249249 - (local_24 >> 1) < local_24) {
        local_24 = 0;
      }
      else {
        local_24 = local_24 + (local_24 >> 1);
      }
      if (*(int *)(in_ECX + 4) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x1c;
      }
      if (local_24 < iVar2 + param_2) {
        iVar2 = FUN_00405820();
        local_24 = iVar2 + param_2;
      }
      local_24 = local_24 * 0x1c;
      local_1c = operator_new(local_24);
      local_8 = 0;
      local_20 = FUN_004388b0(*(undefined4 *)(in_ECX + 4),param_1,local_1c);
      local_20 = FUN_005c3a50(local_20,param_2,&local_50);
      FUN_004388b0(param_1,*(undefined4 *)(in_ECX + 8),local_20);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x1c;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_24 + (int)local_1c;
        *(void **)(in_ECX + 8) = (void *)((int)local_1c + (param_2 + iVar2) * 0x1c);
        *(void **)(in_ECX + 4) = local_1c;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_2c = *(int *)(in_ECX + 8);
    local_28 = local_2c - param_1;
    if ((uint)(local_28 / 0x1c) < param_2) {
      local_18 = param_2 * 0x1c;
      FUN_00438760(param_1,local_2c,local_18 + param_1);
      local_8 = 2;
      FUN_005c3a50(*(undefined4 *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x1c,
                   &local_50);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_18;
      FUN_005cf550(param_1,*(int *)(in_ECX + 8) - local_18,&local_50);
      ExceptionList = local_10;
      return;
    }
    local_18 = param_2 * 0x1c;
    iVar2 = local_2c + param_2 * -0x1c;
    uVar1 = FUN_00438760(iVar2,local_2c,local_2c);
    *(undefined4 *)(in_ECX + 8) = uVar1;
    FUN_005cf580(param_1,iVar2,local_2c);
    FUN_005cf550(param_1,local_18 + param_1,&local_50);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005c3c83 @ 0x005c3c83 ====

void Catch_005c3c83(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_005c3da0 @ 0x005c3da0 ====

void FUN_005c3da0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00982a30;
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


// ==== Catch@005c3f01 @ 0x005c3f01 ====

void Catch_005c3f01(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_005c3ff0 @ 0x005c3ff0 ====

void FUN_005c3ff0(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982a40;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x60;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uVar1 != 0) {
    if (0x2aaaaaa < uVar1) {
      uVar1 = FUN_0085b3b0();
    }
    pvVar2 = operator_new(uVar1 * 0x60);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 0x60 + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_005c3a80(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005c40b6 @ 0x005c40b6 ====

void Catch_005c40b6(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005c40d0 @ 0x005c40d0 ====

void FUN_005c40d0(int param_1)

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
    iVar5 = iVar5 / 0x60 + iVar3;
    uVar6 = iVar5 - iVar3;
    if (iVar5 != iVar3) {
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x60;
      }
      if (uVar6 <= uVar2) {
        FUN_005c0930(*(undefined4 *)(param_1 + 4),*(int *)(param_1 + 8),_Memory);
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x60) * 0x60 + *(int *)(in_ECX + 4);
        return;
      }
      if (_Memory == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = (*(int *)(in_ECX + 0xc) - (int)_Memory) / 0x60;
      }
      if (uVar6 <= uVar2) {
        iVar3 = FUN_005b1840();
        iVar3 = iVar3 * 0x60 + *(int *)(param_1 + 4);
        FUN_005c0930(*(int *)(param_1 + 4),iVar3,_Memory);
        uVar4 = FUN_005c0960(iVar3,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar4;
        return;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
        return;
      }
      uVar4 = FUN_005b1840();
      cVar1 = FUN_005c0dc0(uVar4);
      if (cVar1 == '\0') {
        return;
      }
      uVar4 = FUN_005c0a40(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
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


// ==== FUN_005c4250 @ 0x005c4250 ====

void FUN_005c4250(int param_1)

{
  if (*(void **)(param_1 + 0x4c) == (void *)0x0) {
    *(undefined4 *)(param_1 + 0x4c) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x54) = 0;
    return;
  }
  _free(*(void **)(param_1 + 0x4c));
  return;
}


// ==== FUN_005c4280 @ 0x005c4280 ====

void FUN_005c4280(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x1c != 0) {
      iVar1 = (param_2 - iVar1) / 0x1c;
      goto LAB_005c42c9;
    }
  }
  iVar1 = 0;
LAB_005c42c9:
  FUN_005c3ac0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x1c;
  return;
}


// ==== FUN_005c4300 @ 0x005c4300 ====

undefined4 * FUN_005c4300(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    *param_3 = *param_1;
    iVar1 = 0x10;
    puVar2 = param_1;
    puVar3 = param_3;
    while( true ) {
      puVar3 = puVar3 + 1;
      puVar2 = puVar2 + 1;
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      *puVar3 = *puVar2;
    }
    param_3[0x11] = param_1[0x11];
    FUN_005c40d0(param_1 + 0x12);
    param_1 = param_1 + 0x16;
    param_3 = param_3 + 0x16;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_005c4350 @ 0x005c4350 ====

void FUN_005c4350(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (param_1 != param_2) {
    puVar1 = (undefined4 *)(param_1 + 0x4c);
    do {
      if ((void *)*puVar1 != (void *)0x0) {
        _free((void *)*puVar1);
        return;
      }
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      param_1 = param_1 + 0x58;
      puVar1 = puVar1 + 0x16;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_005c4390 @ 0x005c4390 ====

undefined4 * FUN_005c4390(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar2 = param_2 + -0x58;
    puVar3 = param_3 + -0x16;
    *puVar3 = *(undefined4 *)(param_2 + -0x58);
    puVar4 = (undefined4 *)(param_2 + -0x54);
    puVar5 = param_3 + -0x15;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    param_3[-5] = *(undefined4 *)(param_2 + -0x14);
    FUN_005c40d0(param_2 + -0x10);
    param_2 = iVar2;
    param_3 = puVar3;
  } while (iVar2 != param_1);
  return puVar3;
}


// ==== FUN_005c43e0 @ 0x005c43e0 ====

void FUN_005c43e0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x1c) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x1c))) {
    FUN_005c4280(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_005c3950(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x1c;
  return;
}


// ==== FUN_005c4470 @ 0x005c4470 ====

void FUN_005c4470(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_005c3da0(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_005c44c0 @ 0x005c44c0 ====

void FUN_005c44c0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  for (; param_1 != param_2; param_1 = param_1 + 0x16) {
    *param_1 = *param_3;
    iVar1 = 0x10;
    puVar2 = param_3;
    puVar3 = param_1;
    while( true ) {
      puVar3 = puVar3 + 1;
      puVar2 = puVar2 + 1;
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      *puVar3 = *puVar2;
    }
    param_1[0x11] = param_3[0x11];
    FUN_005c40d0(param_3 + 0x12);
  }
  return;
}


// ==== FUN_005c4510 @ 0x005c4510 ====

void FUN_005c4510(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    iVar1 = 0x10;
    puVar2 = param_2;
    puVar3 = param_1;
    while( true ) {
      puVar3 = puVar3 + 1;
      puVar2 = puVar2 + 1;
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      *puVar3 = *puVar2;
    }
    param_1[0x11] = param_2[0x11];
    FUN_005c3ff0(param_2 + 0x12);
  }
  return;
}


// ==== FUN_005c4550 @ 0x005c4550 ====

int FUN_005c4550(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982a50;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x58) {
    FUN_005c4510(param_3,param_1);
    param_3 = param_3 + 0x58;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@005c45ba @ 0x005c45ba ====

void Catch_005c45ba(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x58) {
    FUN_005c4250(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005c45e0 @ 0x005c45e0 ====

void FUN_005c45e0(undefined4 param_1,undefined4 param_2)

{
  FUN_005c4350(param_1,param_2);
  return;
}


// ==== FUN_005c4600 @ 0x005c4600 ====

void FUN_005c4600(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982a60;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_005c4510(param_1,param_3);
    param_1 = param_1 + 0x58;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005c466a @ 0x005c466a ====

void Catch_005c466a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x58) {
    FUN_005c4250(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005c4690 @ 0x005c4690 ====

void FUN_005c4690(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_2 != param_3) {
    uVar1 = FUN_005c4300(param_3,*(undefined4 *)(in_ECX + 8),param_2,param_1);
    FUN_005c4350(uVar1,*(undefined4 *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = uVar1;
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_005c46e0 @ 0x005c46e0 ====

void FUN_005c46e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005c4550(param_1,param_2,param_3);
  return;
}


// ==== FUN_005c4700 @ 0x005c4700 ====

int FUN_005c4700(int param_1,int param_2,undefined4 param_3)

{
  FUN_005c4600(param_1,param_2,param_3);
  return param_1 + param_2 * 0x58;
}


// ==== FUN_005c4730 @ 0x005c4730 ====

void FUN_005c4730(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  uint uVar4;
  uint extraout_ECX;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 local_94;
  undefined4 local_90 [16];
  undefined4 local_50;
  void *local_48;
  undefined4 local_3c;
  int local_2c;
  uint local_28;
  void *local_20;
  int local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982a70;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)(local_90 + -4);
  local_94 = *param_3;
  puVar6 = local_90;
  puVar5 = param_3;
  for (iVar3 = 0x10; puVar5 = puVar5 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar5;
    puVar6 = puVar6 + 1;
  }
  local_50 = param_3[0x11];
  ExceptionList = &local_10;
  FUN_005c3ff0(param_3 + 0x12);
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x58;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar3) / 0x58;
    }
    if (0x2e8ba2eU - iVar1 < param_2) {
      FUN_0085b3b0();
      uVar4 = extraout_ECX;
    }
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar3) / 0x58;
    }
    if (uVar4 < iVar1 + param_2) {
      if (0x2e8ba2e - (uVar4 >> 1) < uVar4) {
        uVar4 = 0;
      }
      else {
        uVar4 = uVar4 + (uVar4 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x58;
      }
      if (uVar4 < iVar3 + param_2) {
        iVar3 = FUN_006dc7b0();
        uVar4 = iVar3 + param_2;
      }
      local_28 = uVar4 * 0x58;
      local_20 = operator_new(local_28);
      local_8 = 0;
      local_18 = local_20;
      local_18 = (void *)FUN_005c46e0(*(undefined4 *)(in_ECX + 4),param_1,local_20);
      local_18 = (void *)FUN_005c4700(local_18,param_2,&local_94);
      FUN_005c46e0(param_1,*(undefined4 *)(in_ECX + 8),local_18);
      local_8 = 0xffffffff;
      iVar3 = *(int *)(in_ECX + 4);
      if (iVar3 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar3) / 0x58;
      }
      if (iVar3 != 0) {
        FUN_005c4350(iVar3,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(uint *)(in_ECX + 0xc) = local_28 + (int)local_20;
      *(void **)(in_ECX + 8) = (void *)((int)local_20 + (param_2 + iVar1) * 0x58);
      *(void **)(in_ECX + 4) = local_20;
    }
    else {
      local_2c = *(int *)(in_ECX + 8);
      if ((uint)((local_2c - param_1) / 0x58) < param_2) {
        local_1c = param_2 * 0x58;
        FUN_005c4550(param_1,local_2c,local_1c + param_1);
        local_8 = 2;
        FUN_005c4700(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x58,
                     &local_94);
        local_8 = 0xffffffff;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_1c;
        FUN_005c44c0(param_1,*(int *)(in_ECX + 8) - local_1c,&local_94);
      }
      else {
        local_1c = param_2 * 0x58;
        iVar3 = local_2c + param_2 * -0x58;
        uVar2 = FUN_005c4550(iVar3,local_2c,local_2c);
        *(undefined4 *)(in_ECX + 8) = uVar2;
        FUN_005c4390(param_1,iVar3,local_2c,local_3c);
        FUN_005c44c0(param_1,local_1c + param_1,&local_94);
      }
    }
  }
  if (local_48 == (void *)0x0) {
    ExceptionList = local_10;
    return;
  }
  _free(local_48);
  return;
}


// ==== Catch@005c4914 @ 0x005c4914 ====

void Catch_005c4914(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x1c);
  FUN_005c45e0(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@005c49d6 @ 0x005c49d6 ====

void Catch_005c49d6(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x58;
  FUN_005c45e0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x20) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005c4a70 @ 0x005c4a70 ====

void FUN_005c4a70(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 4) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 4))) {
    FUN_0043b7c0(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0043adb0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x10;
  return;
}


// ==== FUN_005c4ae0 @ 0x005c4ae0 ====

void FUN_005c4ae0(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *in_stack_00000054;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x58;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x58;
    }
    FUN_005c4730(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
  }
  else if ((iVar2 != 0) && (param_1 < (uint)((*(int *)(in_ECX + 8) - iVar2) / 0x58))) {
    FUN_005c4690(&param_1,iVar2 + param_1 * 0x58,*(int *)(in_ECX + 8));
  }
  if (in_stack_00000054 == (void *)0x0) {
    return;
  }
  _free(in_stack_00000054);
  return;
}


// ==== FUN_005c4b90 @ 0x005c4b90 ====

void FUN_005c4b90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2610;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005c4bc0 @ 0x005c4bc0 ====

void FUN_005c4bc0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x18) = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x1c) = uVar1;
  *(undefined4 *)(in_ECX + 4) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  return;
}


// ==== FUN_005c4bf0 @ 0x005c4bf0 ====

undefined4 FUN_005c4bf0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_005c4c00 @ 0x005c4c00 ====

void FUN_005c4c00(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x28) = param_1;
  return;
}


// ==== FUN_005c4c20 @ 0x005c4c20 ====

int FUN_005c4c20(void)

{
  int iVar1;
  uint3 uVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xc);
  uVar2 = (uint3)((uint)iVar1 >> 8);
  if ((((iVar1 == 8) || (iVar1 == 0x1b)) || (iVar1 == 0x18)) || (iVar1 == 0x19)) {
    return CONCAT31(uVar2,1);
  }
  return (uint)uVar2 << 8;
}


// ==== FUN_005c4c50 @ 0x005c4c50 ====

void FUN_005c4c50(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = DAT_0099d080;
  *in_ECX = &PTR_FUN_009c262c;
  in_ECX[1] = 0xffffffff;
  in_ECX[2] = 0;
  in_ECX[4] = 0;
  in_ECX[3] = 0x20;
  in_ECX[5] = 0;
  in_ECX[8] = 0;
  in_ECX[10] = 0;
  in_ECX[6] = uVar1;
  in_ECX[7] = uVar1;
  in_ECX[9] = 0;
  in_ECX[0xb] = param_1;
  return;
}


// ==== FUN_005c4ca0 @ 0x005c4ca0 ====

void FUN_005c4ca0(int param_1)

{
  int *piVar1;
  int in_ECX;
  float fVar2;
  float fStack_2c;
  float fStack_28;
  float local_24;
  float fStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  float fStack_10;
  undefined4 uStack_c;
  float fStack_4;
  
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  piVar1 = (int *)(param_1 + 8);
  (**(code **)(**(int **)(in_ECX + 0x2c) + 0xc))(&local_24,piVar1);
  if (DAT_009c2608 <= *(float *)(param_1 + 0x14)) {
    fStack_4 = local_24 - fStack_2c;
    fStack_20 = fStack_20 - fStack_28;
    if (DAT_009c2608 <= SQRT(fStack_4 * fStack_4 + fStack_20 * fStack_20)) {
      fStack_4 = SQRT(fStack_4 * fStack_4 + fStack_20 * fStack_20) / *(float *)(param_1 + 0x14);
      if (DAT_009c2608 <= fStack_4) {
        fVar2 = fStack_4;
      }
      else {
        fVar2 = DAT_0099d080;
      }
      goto LAB_005c4d75;
    }
  }
  fVar2 = DAT_0099d100;
LAB_005c4d75:
  if (((*(int *)(in_ECX + 8) == *piVar1) && (*(int *)(in_ECX + 0xc) == *(int *)(param_1 + 0xc))) &&
     (*(int *)(in_ECX + 0x10) == *(int *)(param_1 + 0x10))) {
    *(undefined4 *)(in_ECX + 0x14) = 0xffffffff;
    *(float *)(in_ECX + 0x18) = fVar2;
    *(float *)(in_ECX + 0x24) = (*(float *)(in_ECX + 0x24) / *(float *)(in_ECX + 0x1c)) * fVar2;
    *(float *)(in_ECX + 0x1c) = fVar2;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    return;
  }
  *(int *)(in_ECX + 8) = *piVar1;
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 0x10);
  iStack_1c = *(int *)(in_ECX + 8);
  uStack_18 = *(undefined4 *)(in_ECX + 0xc);
  uStack_14 = *(undefined4 *)(in_ECX + 0x10);
  fStack_10 = 0.0 / fVar2;
  *(undefined4 *)(in_ECX + 0x14) = 0xffffffff;
  *(float *)(in_ECX + 0x18) = fVar2;
  *(float *)(in_ECX + 0x1c) = fVar2;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  uStack_c = 0;
  (**(code **)(**(int **)(in_ECX + 0x28) + 4))(&iStack_1c);
  return;
}


// ==== FUN_005c4e40 @ 0x005c4e40 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005c4e40(float param_1)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  if (in_ECX[8] == in_ECX[5]) {
    (**(code **)(*(int *)in_ECX[10] + 8))
              ((float)in_ECX[9] / (float)in_ECX[7],(float)in_ECX[9] / (float)in_ECX[7],param_1);
    return;
  }
  fVar6 = (float)in_ECX[9] + param_1;
  if (fVar6 < (float)in_ECX[6]) {
    fVar5 = (float)in_ECX[9];
    fVar3 = DAT_0099d080 / (float)in_ECX[7];
    in_ECX[9] = (int)fVar6;
    (**(code **)(*(int *)in_ECX[10] + 8))(fVar3 * fVar5,fVar6 * fVar3,param_1);
    return;
  }
  fVar6 = (float)in_ECX[9];
  fVar3 = (float)in_ECX[6] - fVar6;
  fVar4 = DAT_0099d080 / (float)in_ECX[7];
  in_ECX[9] = in_ECX[6];
  fVar5 = fVar3;
  (**(code **)(*(int *)in_ECX[10] + 8))(fVar4 * fVar6,fVar4 * (float)in_ECX[9]);
  in_ECX[8] = in_ECX[8] + 1;
  fVar5 = fVar3 - fVar5;
  if ((float)in_ECX[7] <= fVar5 && fVar5 != (float)in_ECX[7]) {
    iVar1 = (int)ROUND(fVar5 / (float)in_ECX[7]);
    uVar2 = in_ECX[8] + iVar1;
    if ((uint)in_ECX[5] <= (uint)(in_ECX[8] + iVar1)) {
      uVar2 = in_ECX[5];
    }
    fVar6 = (float)iVar1;
    in_ECX[8] = uVar2;
    if (iVar1 < 0) {
      fVar6 = fVar6 + _DAT_0099d104;
    }
    fVar5 = fVar5 - fVar6 * (float)in_ECX[7];
  }
  if ((uint)in_ECX[8] < (uint)in_ECX[5]) {
    in_ECX[9] = 0;
    (**(code **)(*in_ECX + 0x10))(fVar5);
    return;
  }
  (**(code **)(*(int *)in_ECX[10] + 0xc))
            ((float)in_ECX[9] / (float)in_ECX[7],(float)in_ECX[9] / (float)in_ECX[7],fVar3);
  (**(code **)(*(int *)in_ECX[10] + 0x10))();
  return;
}


// ==== FUN_005c4fe0 @ 0x005c4fe0 ====

void FUN_005c4fe0(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  int in_ECX;
  float fVar3;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  fVar1 = DAT_009c2608;
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = 1;
  fVar3 = *(float *)(param_1 + 0x14);
  if (*(float *)(param_1 + 0x14) < fVar1) {
    fVar3 = DAT_0099d080;
  }
  *(float *)(in_ECX + 0x18) = fVar3;
  *(float *)(in_ECX + 0x1c) = fVar3;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 0x18);
  FUN_00401740(s_Animation_Type__d__Length_____2f_009c25d0,0x35);
  uVar2 = FUN_00404230(local_1c);
  FUN_00403e50(uVar2);
  if (local_4 < 0x10) {
    (**(code **)(**(int **)(in_ECX + 0x28) + 4))();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005c50f0 @ 0x005c50f0 ====

undefined4 FUN_005c50f0(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 4) {
    *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(in_ECX + 0x14);
    return 1;
  }
  if (iVar1 == 0x20) {
    FUN_005c4fe0(param_1);
    return 1;
  }
  if (iVar1 == 0x21) {
    FUN_005c4ca0(param_1);
    return 1;
  }
  return 0;
}


// ==== FUN_005c5140 @ 0x005c5140 ====

void FUN_005c5140(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2648;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005c5160 @ 0x005c5160 ====

void FUN_005c5160(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8);
  *(undefined4 *)(iVar1 + 0x14) = *param_1;
  *(undefined4 *)(iVar1 + 0x18) = param_1[1];
  iVar1 = *(int *)(in_ECX + 8);
  *(undefined4 *)(iVar1 + 0x1c) = *param_2;
  *(undefined4 *)(iVar1 + 0x20) = param_2[1];
  *(undefined4 *)(*(int *)(in_ECX + 8) + 4) = param_3;
  *(undefined4 *)(*(int *)(in_ECX + 8) + 8) = *(undefined4 *)(*(int *)(in_ECX + 8) + 4);
  *(undefined4 *)(*(int *)(in_ECX + 8) + 0x10) = param_4;
  return;
}


// ==== FUN_005c51b0 @ 0x005c51b0 ====

void FUN_005c51b0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_005c51c0 @ 0x005c51c0 ====

void FUN_005c51c0(void)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2674;
  in_ECX[1] = 0;
  puVar2 = operator_new(0x2c);
  uVar1 = DAT_0099d0dc;
  if (puVar2 == (undefined1 *)0x0) {
    in_ECX[2] = 0;
    return;
  }
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
  in_ECX[2] = puVar2;
  return;
}


// ==== FUN_005c5270 @ 0x005c5270 ====

void FUN_005c5270(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2674;
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_005c52a0 @ 0x005c52a0 ====

undefined1 FUN_005c52a0(char *param_1)

{
  char *pcVar1;
  int in_ECX;
  
  pcVar1 = *(char **)(in_ECX + 8);
  if ((((((*param_1 == *pcVar1) && (*(float *)(param_1 + 4) == *(float *)(pcVar1 + 4))) &&
        (*(float *)(param_1 + 8) == *(float *)(pcVar1 + 8))) &&
       ((*(float *)(param_1 + 0x10) == *(float *)(pcVar1 + 0x10) &&
        (*(float *)(param_1 + 0x14) == *(float *)(pcVar1 + 0x14))))) &&
      ((*(float *)(param_1 + 0x18) == *(float *)(pcVar1 + 0x18) &&
       ((*(float *)(param_1 + 0x1c) == *(float *)(pcVar1 + 0x1c) &&
        (*(float *)(param_1 + 0x20) == *(float *)(pcVar1 + 0x20))))))) &&
     ((*(float *)(param_1 + 0x24) == *(float *)(pcVar1 + 0x24) &&
      (*(float *)(param_1 + 0x28) == *(float *)(pcVar1 + 0x28))))) {
    return 1;
  }
  return 0;
}


// ==== FUN_005c5350 @ 0x005c5350 ====

void FUN_005c5350(undefined1 *param_1)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 4) != 0) && (cVar2 = FUN_005c52a0(param_1), cVar2 == '\0')) {
    puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      *puVar3 = &PTR_FUN_009c2688;
      puVar3[1] = 0;
      puVar3[2] = uVar4;
    }
    puVar3[1] = param_1;
    FUN_00797a20(puVar3);
    iVar1 = *(int *)(in_ECX + 8);
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(param_1 + 0x18);
    iVar1 = *(int *)(in_ECX + 8);
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(param_1 + 0x20);
    iVar1 = *(int *)(in_ECX + 8);
    *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(*(int *)(in_ECX + 8) + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(*(int *)(in_ECX + 8) + 8) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(*(int *)(in_ECX + 8) + 0x10) = *(undefined4 *)(param_1 + 0x10);
    **(undefined1 **)(in_ECX + 8) = *param_1;
  }
  return;
}


// ==== FUN_005c5400 @ 0x005c5400 ====

void FUN_005c5400(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    if (param_2 == 1) {
      puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar1 == (undefined4 *)0x0) {
        uRam00000008 = param_1;
        uRam0000000c = 1;
        FUN_00797a20(0);
        return;
      }
      uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      puVar1[1] = uVar2;
      *puVar1 = &PTR_FUN_009c265c;
      puVar1[2] = param_1;
      puVar1[3] = 1;
      FUN_00797a20(puVar1);
      return;
    }
    if (param_2 == 2) {
      puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar1 == (undefined4 *)0x0) {
        uRam0000000c = 2;
        uRam00000008 = param_1;
        FUN_00797a20(0);
        return;
      }
      uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      *puVar1 = &PTR_FUN_009c265c;
      puVar1[1] = uVar2;
      puVar1[3] = 2;
      puVar1[2] = param_1;
      FUN_00797a20(puVar1);
      return;
    }
    if (param_2 == 0) {
      puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar1 == (undefined4 *)0x0) {
        uRam0000000c = 0;
        uRam00000008 = param_1;
        FUN_00797a20(0);
        return;
      }
      uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      *puVar1 = &PTR_FUN_009c265c;
      puVar1[1] = uVar2;
      puVar1[3] = 0;
      puVar1[2] = param_1;
      FUN_00797a20(puVar1);
      return;
    }
    if (param_2 == 3) {
      puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
        *puVar1 = &PTR_FUN_009c265c;
        puVar1[1] = uVar2;
      }
      puVar1[3] = 3;
      puVar1[2] = param_1;
      FUN_00797a20(puVar1);
    }
  }
  return;
}


// ==== FUN_005c5580 @ 0x005c5580 ====

undefined4 FUN_005c5580(void)

{
  return 0x20010022;
}


// ==== FUN_005c5590 @ 0x005c5590 ====

undefined4 FUN_005c5590(void)

{
  return 0x20010021;
}


// ==== FUN_005c55a0 @ 0x005c55a0 ====

void FUN_005c55a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2674;
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_005c55e0 @ 0x005c55e0 ====

float10 FUN_005c55e0(void)

{
  return (float10)DAT_0099d080;
}


// ==== FUN_005c55f0 @ 0x005c55f0 ====

void FUN_005c55f0(void)

{
  return;
}


// ==== FUN_005c5600 @ 0x005c5600 ====

void FUN_005c5600(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c26bc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005c5620 @ 0x005c5620 ====

void FUN_005c5620(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c26fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005c5640 @ 0x005c5640 ====

void FUN_005c5640(int *param_1)

{
  int *piVar1;
  int *in_ECX;
  float10 fVar2;
  undefined1 auStack_10 [16];
  
  *param_1 = in_ECX[3];
  fVar2 = (float10)(**(code **)(*in_ECX + 0x20))();
  param_1[1] = (int)(float)fVar2;
  param_1[2] = in_ECX[4];
  piVar1 = (int *)FUN_0040d690(auStack_10,in_ECX + 5);
  param_1[3] = *piVar1;
  param_1[4] = piVar1[1];
  param_1[5] = piVar1[2];
  param_1[6] = piVar1[3];
  param_1[7] = in_ECX[0xb];
  return;
}


// ==== FUN_005c56a0 @ 0x005c56a0 ====

void FUN_005c56a0(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0xc);
  param_1[1] = *(undefined4 *)(in_ECX + 0x10);
  return;
}


// ==== FUN_005c56c0 @ 0x005c56c0 ====

void FUN_005c56c0(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x14);
  param_1[1] = *(undefined4 *)(in_ECX + 0x18);
  return;
}


// ==== FUN_005c56e0 @ 0x005c56e0 ====

void FUN_005c56e0(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x1c);
  param_1[1] = *(undefined4 *)(in_ECX + 0x20);
  return;
}


// ==== FUN_005c5700 @ 0x005c5700 ====

float10 FUN_005c5700(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x24);
}


// ==== FUN_005c5710 @ 0x005c5710 ====

float10 FUN_005c5710(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x28);
}


// ==== FUN_005c5720 @ 0x005c5720 ====

float10 FUN_005c5720(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x2c);
}


// ==== FUN_005c5730 @ 0x005c5730 ====

void FUN_005c5730(void)

{
  return;
}


// ==== FUN_005c5740 @ 0x005c5740 ====

void FUN_005c5740(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = DAT_0099d080;
  *in_ECX = &PTR_FUN_009c2714;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = uVar1;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[0xb] = uVar1;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0x20;
  in_ECX[0xe] = 0;
  FUN_005cec90();
  in_ECX[0x14] = param_1;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x15] = 0;
  in_ECX[2] = 0;
  in_ECX[1] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_005c57e0 @ 0x005c57e0 ====

void FUN_005c57e0(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  
  _Memory = (void *)in_ECX[0x12];
  *in_ECX = &PTR_FUN_009c2714;
  if (_Memory != (void *)0x0) {
    FUN_005cea00();
    _free(_Memory);
    return;
  }
  in_ECX[0x12] = 0;
  if ((undefined4 *)in_ECX[0x13] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x13])(1);
  }
  in_ECX[0x13] = 0;
  if (in_ECX[0x14] != 0) {
    (**(code **)(*DAT_00b5aff0 + 8))(in_ECX[0x14]);
    in_ECX[0x14] = 0;
  }
  FUN_005cecb0();
  *in_ECX = &PTR_FUN_009c26bc;
  return;
}


// ==== FUN_005c5850 @ 0x005c5850 ====

void FUN_005c5850(float *param_1,undefined4 *param_2,undefined4 param_3)

{
  float *pfVar1;
  int in_ECX;
  float10 fVar2;
  
  pfVar1 = (float *)(in_ECX + 0xc);
  *pfVar1 = *param_1;
  *(float *)(in_ECX + 0x10) = param_1[1];
  *(int *)(in_ECX + 4) = (int)*pfVar1;
  *(int *)(in_ECX + 8) = (int)*(float *)(in_ECX + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = *param_2;
  *(undefined4 *)(in_ECX + 0x18) = param_2[1];
  *(undefined4 *)(in_ECX + 0x24) = param_3;
  fVar2 = (float10)(**(code **)(*DAT_00b5a6b4 + 0x14))(pfVar1);
  *(float *)(in_ECX + 0x28) = (float)(fVar2 + (float10)*(float *)(in_ECX + 0x24));
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = param_3;
  *(undefined4 *)(in_ECX + 0x34) = 0x20;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  FUN_005cec80(param_3);
  FUN_005cecd0();
  return;
}


// ==== FUN_005c58e0 @ 0x005c58e0 ====

void FUN_005c58e0(void)

{
  int *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float10 fVar4;
  undefined1 auStack_180 [52];
  undefined1 auStack_14c [12];
  undefined1 auStack_140 [64];
  undefined1 auStack_100 [52];
  undefined4 auStack_cc [16];
  undefined4 auStack_8c [3];
  undefined1 auStack_80 [40];
  undefined4 auStack_58 [3];
  undefined1 auStack_4c [56];
  undefined4 *puStack_14;
  
  iVar1 = in_ECX[4];
  fVar4 = (float10)(**(code **)(*in_ECX + 0x20))();
  thunk_FUN_0079f7f5(auStack_140,in_ECX[3],(float)fVar4,iVar1);
  fVar4 = (float10)FUN_0040d5f0(in_ECX + 5);
  thunk_FUN_0079f925(auStack_100,(float)fVar4);
  iVar1 = in_ECX[0xb];
  thunk_FUN_0079f761(auStack_180,iVar1,iVar1,iVar1);
  thunk_FUN_0079ee7b(auStack_80,auStack_180,auStack_100);
  puVar2 = auStack_8c;
  puVar3 = auStack_cc;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  thunk_FUN_0079ee7b(auStack_4c,auStack_cc,auStack_14c);
  puVar2 = auStack_58;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puStack_14 = *puVar2;
    puVar2 = puVar2 + 1;
    puStack_14 = puStack_14 + 1;
  }
  return;
}


// ==== FUN_005c59c0 @ 0x005c59c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005c59c0(undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int *piVar5;
  float *pfVar6;
  int in_ECX;
  undefined4 unaff_EDI;
  float fVar7;
  undefined4 *unaff_retaddr;
  
  iVar4 = (**(code **)(**(int **)(in_ECX + 0x50) + 8))();
  if ((iVar4 == 0) || (*(int *)(iVar4 + 0x14) == 0)) {
    *unaff_retaddr = unaff_EDI;
    unaff_retaddr[1] = 0;
    unaff_retaddr[2] = 0;
    unaff_retaddr[3] = 0;
    return;
  }
  piVar5 = (int *)(**(code **)(*DAT_00b5ae50 + 8))(iVar4);
  if (piVar5 == (int *)0x0) {
    _DAT_00000000 = (float)param_2;
    fRam00000004 = (float)unaff_EDI;
    fRam00000008 = 0.0;
    fRam0000000c = 0.0;
    return;
  }
  fVar1 = *(float *)(in_ECX + 0x2c);
  pfVar6 = (float *)(**(code **)(*piVar5 + 4))();
  fVar2 = *pfVar6;
  fVar3 = pfVar6[1];
  fVar7 = *(float *)(in_ECX + 0x2c);
  iVar4 = (**(code **)(*piVar5 + 4))();
  fVar7 = *(float *)(iVar4 + 8) * fVar7;
  (**(code **)(*DAT_00b5ae50 + 0xc))(piVar5);
  _DAT_00000000 = fVar2 * fVar1;
  fRam00000004 = fVar3 * fVar1;
  fRam00000008 = fVar7;
  fRam0000000c = fVar7;
  return;
}


// ==== FUN_005c5b10 @ 0x005c5b10 ====

void FUN_005c5b10(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x48) == 0) {
    pvVar1 = operator_new(0x10);
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_005ce9e0(in_ECX);
    }
    *(undefined4 *)(in_ECX + 0x48) = uVar2;
    FUN_005cea30();
  }
  FUN_005ce9b0(in_ECX + 4,param_1 + 4,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0xd))
  ;
  FUN_005ce990(1);
  return;
}


// ==== FUN_005c5b70 @ 0x005c5b70 ====

void FUN_005c5b70(int param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x4c) == 0) {
    puVar1 = operator_new(0x18);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_009c2708;
    }
    *(undefined4 **)(in_ECX + 0x4c) = puVar1;
  }
  FUN_005ceae0(param_1 + 4,*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
  return;
}


// ==== FUN_005c5bb0 @ 0x005c5bb0 ====

void FUN_005c5bb0(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x48) == 0) {
    pvVar1 = operator_new(0x10);
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_005ce9e0(in_ECX);
    }
    *(undefined4 *)(in_ECX + 0x48) = uVar2;
    FUN_005cea30();
  }
  FUN_005ce9a0(in_ECX + 4,param_1 + 4,
               CONCAT31((int3)((uint)*(undefined4 *)(param_1 + 0x10) >> 8),
                        *(undefined1 *)(param_1 + 0xc)),
               CONCAT31((int3)((uint)*(undefined4 *)(param_1 + 0x14) >> 8),
                        *(undefined1 *)(param_1 + 0xd)),*(undefined4 *)(param_1 + 0x10),
               *(undefined4 *)(param_1 + 0x14));
  FUN_005ce990(0);
  return;
}


// ==== FUN_005c5c10 @ 0x005c5c10 ====

void FUN_005c5c10(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x30) = *param_1;
  *(undefined4 *)(in_ECX + 0x34) = param_1[1];
  *(undefined4 *)(in_ECX + 0x38) = param_1[2];
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x50) + 8))((undefined4 *)(in_ECX + 0x30));
  if (iVar1 == 0) {
    FUN_005cecd0();
    return;
  }
  FUN_005cecf0(iVar1);
  return;
}


// ==== FUN_005c5c60 @ 0x005c5c60 ====

void FUN_005c5c60(int param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    if (param_1 == 3) {
                    /* WARNING: Could not recover jumptable at 0x005c5c7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(in_ECX + 0x54) + 8))();
      return;
    }
    if (param_1 == 2) {
                    /* WARNING: Could not recover jumptable at 0x005c5c91. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(in_ECX + 0x54) + 8))();
      return;
    }
  }
  return;
}


// ==== FUN_005c5ca0 @ 0x005c5ca0 ====

void FUN_005c5ca0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar5 = (**(code **)(*DAT_00b5a988 + 0x14))();
  uVar1 = *(undefined4 *)(iVar5 + 0x28);
  uVar2 = *(undefined4 *)(iVar5 + 0x2c);
  uVar3 = *(undefined4 *)(iVar5 + 0x30);
  iVar5 = (**(code **)(*DAT_00b5a988 + 0x14))();
  piVar4 = DAT_00b5a720;
  uStack_c = *(undefined4 *)(iVar5 + 0x4c);
  uStack_8 = *(undefined4 *)(iVar5 + 0x50);
  uStack_4 = *(undefined4 *)(iVar5 + 0x54);
  uStack_18 = uVar1;
  uStack_14 = uVar2;
  uStack_10 = uVar3;
  puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a988 + 0x14))();
  (**(code **)(*piVar4 + 0x14))(&uStack_18,*puVar6);
  return;
}


// ==== FUN_005c5d20 @ 0x005c5d20 ====

void FUN_005c5d20(undefined4 param_1,float param_2,undefined4 param_3)

{
  float *pfVar1;
  float fVar2;
  undefined4 uVar3;
  float fVar4;
  float10 fVar5;
  int iVar6;
  int iVar7;
  int in_ECX;
  float unaff_EBX;
  float10 fVar8;
  
  fVar4 = *(float *)(in_ECX + 0xc);
  pfVar1 = (float *)(in_ECX + 0xc);
  iVar6 = (**(code **)(**(int **)(in_ECX + 0x54) + 4))();
  if (*(int **)(in_ECX + 0x4c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x4c) + 4))();
  }
  if (*(int *)(in_ECX + 0x48) != 0) {
    FUN_005ce950(param_1,param_2,param_3,iVar6,in_ECX + 4,in_ECX + 0x14);
  }
  fVar8 = (float10)(**(code **)(*DAT_00b5a6b4 + 0x14))(pfVar1);
  fVar8 = fVar8 + (float10)*(float *)(in_ECX + 0x24);
  fVar2 = *pfVar1;
  uVar3 = *(undefined4 *)(in_ECX + 0x10);
  *(float *)(in_ECX + 0x28) = (float)fVar8;
  fVar5 = (float10)DAT_0099d080;
  *(float *)(in_ECX + 0x1c) = *pfVar1 - unaff_EBX;
  *(float *)(in_ECX + 0x20) = *(float *)(in_ECX + 0x10) - fVar4;
  iVar7 = (**(code **)(*DAT_00b5ad14 + 0xc))();
  if (iVar7 == iVar6) {
    FUN_005c5ca0(param_2,fVar2,(float)(fVar8 + fVar5),uVar3);
  }
  if (param_2 < DAT_009c26b0) {
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    return;
  }
  param_2 = DAT_0099d080 / param_2;
  *(float *)(in_ECX + 0x1c) = *(float *)(in_ECX + 0x1c) * param_2;
  *(float *)(in_ECX + 0x20) = *(float *)(in_ECX + 0x20) * param_2;
  return;
}


// ==== FUN_005c5ea0 @ 0x005c5ea0 ====

void FUN_005c5ea0(int param_1)

{
  undefined4 *_Memory;
  undefined4 *puVar1;
  char cVar2;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 *puVar3;
  int local_20;
  int local_1c;
  int iStack_18;
  undefined4 *puStack_10;
  undefined4 *puStack_c;
  undefined4 uStack_8;
  
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(param_1 + 0x18);
  local_1c = (int)*(float *)(in_ECX + 0x10);
  local_20 = (int)*(float *)(in_ECX + 0xc);
  cVar2 = (**(code **)(*DAT_00b5af50 + 0x14))(&local_20);
  if (cVar2 == '\0') {
    puStack_10 = (undefined4 *)0x0;
    puStack_c = (undefined4 *)0x0;
    uStack_8 = 0;
    local_1c = (int)(*(float *)(in_ECX + 0xc) - DAT_009a09b8);
    iStack_18 = (int)(*(float *)(in_ECX + 0x10) - DAT_009a09b8);
    FUN_005c64c0(&local_1c);
    iStack_18 = (int)(*(float *)(in_ECX + 0x10) + DAT_009a09b8);
    local_1c = (int)(*(float *)(in_ECX + 0xc) - DAT_009a09b8);
    FUN_005c64c0(&local_1c);
    iStack_18 = (int)(*(float *)(in_ECX + 0x10) - DAT_009a09b8);
    local_1c = (int)(*(float *)(in_ECX + 0xc) + DAT_009a09b8);
    FUN_005c64c0(&local_1c);
    local_1c = (int)(*(float *)(in_ECX + 0xc) + DAT_009a09b8);
    iStack_18 = (int)(*(float *)(in_ECX + 0x10) + DAT_009a09b8);
    FUN_005c64c0(&local_1c);
    puVar1 = puStack_c;
    _Memory = puStack_10;
    for (puVar3 = puStack_10; puVar3 != puVar1; puVar3 = puVar3 + 2) {
      cVar2 = (**(code **)(*DAT_00b5af50 + 0x14))(puVar3);
      if (cVar2 != '\0') {
        unaff_ESI = *puVar3;
        local_20 = puVar3[1];
        break;
      }
    }
    if (_Memory != (undefined4 *)0x0) {
      _free(_Memory);
      return;
    }
  }
  *(undefined4 *)(in_ECX + 4) = unaff_ESI;
  *(int *)(in_ECX + 8) = local_20;
  FUN_005cec80(*(undefined4 *)(in_ECX + 0x2c));
  return;
}


// ==== FUN_005c6050 @ 0x005c6050 ====

undefined4 FUN_005c6050(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  switch(uVar1) {
  case 2:
    FUN_005c5ea0(param_1);
    return 1;
  default:
    return 0;
  case 0x10:
    FUN_005c5b10(param_1);
    return 1;
  case 0x11:
    FUN_005c5bb0(param_1);
    return 1;
  case 0x13:
    FUN_005c5b70(param_1);
    return 1;
  }
}


// ==== FUN_005c60e0 @ 0x005c60e0 ====

void FUN_005c60e0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = DAT_0099d080;
  return;
}


// ==== FUN_005c6100 @ 0x005c6100 ====

void FUN_005c6100(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x54) = param_1;
  return;
}


// ==== FUN_005c6110 @ 0x005c6110 ====

int FUN_005c6110(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982a80;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 8) {
    FUN_005767c0(param_3,param_1);
    param_3 = param_3 + 8;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@005c6176 @ 0x005c6176 ====

void Catch_005c6176(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005c6180 @ 0x005c6180 ====

void FUN_005c6180(byte param_1)

{
  void *in_ECX;
  
  FUN_005c57e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005c61a0 @ 0x005c61a0 ====

void FUN_005c61a0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982a90;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_005767c0(param_1,param_3);
    param_1 = param_1 + 8;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005c6206 @ 0x005c6206 ====

void Catch_005c6206(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005c6210 @ 0x005c6210 ====

void FUN_005c6210(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005c6110(param_1,param_2,param_3);
  return;
}


// ==== FUN_005c6230 @ 0x005c6230 ====

int FUN_005c6230(int param_1,int param_2,undefined4 param_3)

{
  FUN_005c61a0(param_1,param_2,param_3);
  return param_1 + param_2 * 8;
}


// ==== FUN_005c6260 @ 0x005c6260 ====

void FUN_005c6260(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int extraout_ECX;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined4 local_38;
  undefined4 local_34;
  int local_28;
  void *local_24;
  uint local_20;
  undefined4 local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982aa0;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x44);
  local_38 = *param_3;
  local_34 = param_3[1];
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = *(int *)(in_ECX + 0xc) - iVar2 >> 3;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar2 >> 3;
    }
    uVar5 = param_2;
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x44);
    if (0x1fffffffU - iVar6 < param_2) {
      ExceptionList = &local_10;
      uVar7 = FUN_0085b3b0();
      uVar5 = (uint)((ulonglong)uVar7 >> 0x20);
      local_20 = (uint)uVar7;
      iVar2 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar2 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar2 >> 3;
    }
    if (local_20 < iVar6 + uVar5) {
      if (0x1fffffff - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar2 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(in_ECX + 8) - iVar2 >> 3;
      }
      if (local_20 < iVar6 + uVar5) {
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 3;
        }
        local_20 = iVar2 + uVar5;
      }
      local_20 = local_20 * 8;
      pvVar3 = operator_new(local_20);
      local_8 = 0;
      local_24 = pvVar3;
      local_1c = FUN_005c6210(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      local_1c = FUN_005c6230(local_1c,param_2,&local_38);
      FUN_005c6210(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(in_ECX + 8) - (int)_Memory >> 3;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)pvVar3;
        *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar2) * 8);
        *(void **)(in_ECX + 4) = pvVar3;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar2 = *(int *)(in_ECX + 8);
    if ((uint)(iVar2 - param_1 >> 3) < uVar5) {
      local_18 = uVar5 * 8;
      FUN_005c6110(param_1,iVar2,local_18 + param_1);
      local_8 = 2;
      FUN_005c6230(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 3),&local_38);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_18;
      FUN_00686630(param_1,*(int *)(in_ECX + 8) - local_18,&local_38);
      ExceptionList = local_10;
      return;
    }
    local_18 = uVar5 * 8;
    local_28 = iVar2 + uVar5 * -8;
    uVar4 = FUN_005c6110(local_28,iVar2,iVar2);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_00576790(param_1,local_28,iVar2);
    FUN_00686630(param_1,local_18 + param_1,&local_38);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005c63c9 @ 0x005c63c9 ====

void Catch_005c63c9(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x20));
  return;
}


// ==== FUN_005c64c0 @ 0x005c64c0 ====

void FUN_005c64c0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 3) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 3))) {
    FUN_005c6260(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_005c61a0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 8;
  return;
}


// ==== FUN_005c6530 @ 0x005c6530 ====

void FUN_005c6530(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2774;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005c6550 @ 0x005c6550 ====

void FUN_005c6550(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2780;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005c6570 @ 0x005c6570 ====

void FUN_005c6570(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2798;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005c6590 @ 0x005c6590 ====

undefined1 FUN_005c6590(void)

{
  return 0;
}


// ==== FUN_005c65a0 @ 0x005c65a0 ====

void FUN_005c65a0(void)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(**(int **)(in_ECX + 0xc0) + 0x14))();
  if (cVar1 != '\0') {
    FUN_005c83e0(0x3f800000,0x3f800000,0);
  }
  return;
}


// ==== FUN_005c65d0 @ 0x005c65d0 ====

void FUN_005c65d0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = **(int **)(in_ECX + 200);
  uVar2 = (**(code **)(**(int **)(in_ECX + 0xc0) + 4))(0);
  (**(code **)(iVar1 + 0xc))(uVar2);
  return;
}


// ==== FUN_005c6600 @ 0x005c6600 ====

void FUN_005c6600(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 1;
  }
  else if (param_1 == 1) {
    uVar2 = 2;
  }
  else {
    if (param_1 != 2) {
      return;
    }
    uVar2 = 3;
  }
  iVar1 = **(int **)(in_ECX + 0xc4);
  uVar2 = (**(code **)(**(int **)(in_ECX + 0xbc) + 4))(uVar2);
  (**(code **)(iVar1 + 0xc))(uVar2);
  return;
}


// ==== FUN_005c6650 @ 0x005c6650 ====

void FUN_005c6650(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005c6655. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(in_ECX + -0x10) + 0x20))();
  return;
}


// ==== FUN_005c6660 @ 0x005c6660 ====

void FUN_005c6660(int *param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x70))();
  *(undefined1 *)(iVar1 + 0x25) = *(undefined1 *)((int)in_ECX + 0x15);
  (**(code **)(*in_ECX + 0xc))(param_1,iVar1);
  if (in_ECX[7] == 0x12) {
    (**(code **)(*param_1 + 0x11c))();
    return;
  }
  (**(code **)(*param_1 + 0x98))(iVar1);
  return;
}


// ==== FUN_005c66b0 @ 0x005c66b0 ====

void FUN_005c66b0(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0xcc) + 4))(param_1);
  FUN_005c82b0(param_1);
  return;
}


// ==== FUN_005c6700 @ 0x005c6700 ====

void FUN_005c6700(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x16) = param_1;
  FUN_005c8430();
  return;
}


// ==== FUN_005c6720 @ 0x005c6720 ====

void FUN_005c6720(undefined4 param_1)

{
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x16) == '\0') || (*(int *)(*(int *)(in_ECX + 0xbc) + 8) == 0)) {
    (**(code **)(**(int **)(in_ECX + 0xe0) + 0xc))();
    return;
  }
  (**(code **)(**(int **)(in_ECX + 0xe0) + 0x14))(param_1,*(int *)(in_ECX + 0xbc));
  *(undefined4 *)(*(int *)(in_ECX + 0xbc) + 8) = 1;
  return;
}


// ==== __break @ 0x005c676f ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_005c6770 @ 0x005c6770 ====

void FUN_005c6770(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  float10 extraout_ST0;
  
  if (*(char *)((int)in_ECX + 0x17) != '\0') {
    iVar1 = *(int *)in_ECX[0x39];
    (**(code **)(*in_ECX + 0x44))();
    (**(code **)(iVar1 + 0x14))(param_1,*(undefined1 *)((int)in_ECX + 0x8e),(float)extraout_ST0);
    *(undefined1 *)((int)in_ECX + 0x17) = 0;
  }
  return;
}


// ==== FUN_005c67d0 @ 0x005c67d0 ====

uint FUN_005c67d0(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *in_ECX;
  
  uVar2 = (**(code **)(*param_1 + 0x10))();
  uVar3 = (**(code **)(*in_ECX + 0x20))();
  if (uVar2 == uVar3) {
    iVar1 = in_ECX[0x2f];
    *(char *)(iVar1 + 2) = (char)param_1[1];
    *(undefined1 *)(in_ECX[0x2f] + 3) = *(undefined1 *)((int)param_1 + 5);
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  return uVar3 & 0xffffff00;
}


// ==== FUN_005c6820 @ 0x005c6820 ====

void FUN_005c6820(void)

{
  FUN_005c8670();
  return;
}


// ==== FUN_005c6830 @ 0x005c6830 ====

void FUN_005c6830(void)

{
  FUN_005c8620();
  return;
}


// ==== FUN_005c6840 @ 0x005c6840 ====

void FUN_005c6840(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005c6848. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xd4) + 0x14))();
  return;
}


// ==== FUN_005c6850 @ 0x005c6850 ====

void FUN_005c6850(void)

{
  FUN_005c8080();
  return;
}


// ==== FUN_005c6860 @ 0x005c6860 ====

void FUN_005c6860(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005c6868. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xd4) + 0x18))();
  return;
}


// ==== FUN_005c6870 @ 0x005c6870 ====

void FUN_005c6870(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005c6878. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xd4) + 0x1c))();
  return;
}


// ==== FUN_005c6880 @ 0x005c6880 ====

void FUN_005c6880(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *unaff_retaddr;
  undefined1 local_40 [64];
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 0xcc) + 8))(local_40);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *unaff_retaddr = *puVar1;
    puVar1 = puVar1 + 1;
    unaff_retaddr = unaff_retaddr + 1;
  }
  return;
}


// ==== FUN_005c68f0 @ 0x005c68f0 ====

void FUN_005c68f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c27dc;
  in_ECX[2] = &PTR_FUN_009c27c4;
  in_ECX[3] = &PTR_FUN_009c27b4;
  in_ECX[4] = &PTR_FUN_009c27a8;
  _free((void *)in_ECX[0x30]);
  return;
}


// ==== FUN_005c6a00 @ 0x005c6a00 ====

void FUN_005c6a00(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  undefined1 auStack_a [10];
  
  (**(code **)(**(int **)(in_ECX + 0xc4) + 0x34))(param_1);
  FUN_005c8370(param_1);
  if ((((*(int **)(in_ECX + 0xbc) != (int *)0x0) && (*(char *)(in_ECX + 0xe) != '\0')) &&
      (iVar1 = (**(code **)(**(int **)(in_ECX + 0xbc) + 0xc))(auStack_a + -6), iVar1 != 0)) &&
     (0.0 < *(float *)(iVar1 + 0x128))) {
    *(float *)(in_ECX + 0x88) = *(float *)(iVar1 + 0x128);
    return;
  }
  *(undefined4 *)(in_ECX + 0x88) = 0;
  return;
}


// ==== FUN_005c6a90 @ 0x005c6a90 ====

void FUN_005c6a90(float param_1,float param_2,float param_3)

{
  float fVar1;
  int in_ECX;
  float fVar2;
  float fVar3;
  
  fVar1 = param_3;
  fVar3 = DAT_0099d080;
  if (DAT_009c276c <= DAT_0099d080 - *(float *)(in_ECX + 0x88)) {
    fVar2 = DAT_0099d080 / (DAT_0099d080 - *(float *)(in_ECX + 0x88));
    param_1 = fVar2 * param_1;
    fVar2 = fVar2 * param_2;
    if (param_1 <= DAT_0099d080) {
      param_2 = 0.0;
      if (0.0 <= param_1) goto LAB_005c6af7;
    }
    else {
      param_1 = DAT_0099d080;
LAB_005c6af7:
      param_2 = param_1;
    }
    if ((fVar2 <= DAT_0099d080) && (param_1 = 0.0, fVar3 = fVar2, fVar2 < 0.0)) goto LAB_005c6b16;
  }
  else {
    param_2 = DAT_0099d080;
  }
  param_1 = fVar3;
LAB_005c6b16:
  param_3 = 0.0;
  if (0.0 <= fVar1) {
    param_3 = fVar1;
  }
  (**(code **)(**(int **)(in_ECX + 0xc4) + 0x38))(param_2,param_1,param_3);
  (**(code **)(*(int *)(in_ECX + -8) + 0x24))();
  if (*(char *)(in_ECX + 0xe) == '\x01') {
    FUN_005c83e0(param_2,param_1,param_3);
    return;
  }
  FUN_005c7ec0(param_1,param_3);
  return;
}


// ==== FUN_005c6b80 @ 0x005c6b80 ====

void FUN_005c6b80(void)

{
  int iVar1;
  float fVar2;
  int *in_ECX;
  int iVar3;
  float unaff_EBX;
  float unaff_ESI;
  int *piVar4;
  int *piVar5;
  float10 fVar6;
  float local_7c;
  float local_78;
  float local_74;
  undefined4 uStack_70;
  int iStack_6c;
  undefined4 uStack_68;
  float local_64;
  float local_60;
  float local_5c;
  undefined4 uStack_58;
  float fStack_54;
  float fStack_50;
  float local_4c;
  int aiStack_48 [2];
  float fStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  int local_4;
  
  if ((char)in_ECX[0x23] == '\x01') {
    local_4 = -0x2f5fbfc0;
  }
  else {
    local_4 = (-(uint)((char)in_ECX[0x23] != '\x02') & 0xff6fdfe0) + 0xd0f05050;
  }
  local_7c = (float)in_ECX[0xb] - (float)in_ECX[8];
  local_64 = ((float)in_ECX[0xb] - (float)in_ECX[8]) * DAT_0099d0b4 + (float)in_ECX[8];
  local_78 = (float)in_ECX[0xc] - (float)in_ECX[9];
  local_60 = ((float)in_ECX[0xc] - (float)in_ECX[9]) * DAT_0099d0b4 + (float)in_ECX[9];
  local_74 = (float)in_ECX[0xd] - (float)in_ECX[10];
  local_5c = ((float)in_ECX[0xd] - (float)in_ECX[10]) * DAT_0099d0b4 + (float)in_ECX[10];
  thunk_FUN_0079e1ba(&local_4c,&local_7c);
  local_60 = 0.0;
  local_5c = 0.0;
  uStack_58 = DAT_0099d080;
  fVar2 = SQRT(unaff_ESI * unaff_ESI + unaff_EBX * unaff_EBX + local_7c * local_7c) * DAT_0099d0b4;
  fStack_18 = fStack_54 * fVar2;
  aiStack_48[0] = iStack_6c;
  iStack_6c = DAT_0099d080;
  fStack_14 = fStack_50 * fVar2;
  aiStack_48[1] = uStack_68;
  fStack_10 = local_4c * fVar2;
  uStack_68 = 0;
  fStack_40 = local_64;
  local_64 = 0.0;
  local_78 = 0.0;
  local_74 = (float)DAT_0099d080;
  uStack_70 = 0;
  uStack_3c = DAT_0099d080;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_28 = 0;
  uStack_30 = 0;
  uStack_2c = DAT_0099d080;
  uStack_1c = DAT_0099d080;
  uStack_24 = 0;
  iVar1 = *in_ECX;
  uStack_20 = 0;
  piVar4 = aiStack_48;
  piVar5 = in_ECX + 0xe;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar5 = *piVar4;
    piVar4 = piVar4 + 1;
    piVar5 = piVar5 + 1;
  }
  fVar6 = (float10)(**(code **)(iVar1 + 0x40))();
  in_ECX[0x20] = (int)(float)((float10)(float)in_ECX[0xc] - fVar6);
  return;
}


// ==== FUN_005c6d60 @ 0x005c6d60 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005c6d60(int param_1)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  int in_ECX;
  bool bVar4;
  float fVar5;
  float fVar6;
  
  fVar5 = DAT_0099d080;
  uVar1 = *(uint *)(in_ECX + 0xb4);
  if (*(uint *)(in_ECX + 0xb8) <= uVar1) {
    bVar4 = *(char *)(in_ECX + 0x8f) == '\0';
    fVar6 = DAT_00a0fd50;
    if (!bVar4) {
      fVar6 = 0.0;
    }
    fVar2 = (float)param_1;
    if (param_1 < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar3 = (float)(int)uVar1;
    if ((int)uVar1 < 0) {
      fVar3 = fVar3 + _DAT_0099d104;
    }
    if (bVar4) {
      if (*(char *)(in_ECX + 0xac) != '\0') {
        fVar6 = *(float *)(in_ECX + 0xb0) + fVar2 / fVar3;
        bVar4 = DAT_0099d080 <= fVar6;
        *(float *)(in_ECX + 0xb0) = fVar6;
        if (bVar4) {
          *(undefined4 *)(in_ECX + 0xb8) = 0;
          *(undefined1 *)(in_ECX + 0xac) = 0;
          *(float *)(in_ECX + 0xb0) = fVar5;
          return;
        }
      }
    }
    else {
      fVar5 = *(float *)(in_ECX + 0xb0) - fVar2 / fVar3;
      *(undefined1 *)(in_ECX + 0xac) = 1;
      if (fVar5 < fVar6) {
        fVar5 = fVar6;
      }
      *(float *)(in_ECX + 0xb0) = fVar5;
    }
    *(uint *)(in_ECX + 0xb8) = *(uint *)(in_ECX + 0xb8) + param_1;
  }
  return;
}


// ==== FUN_005c6e40 @ 0x005c6e40 ====

void FUN_005c6e40(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined1 uVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = DAT_009bfa74;
  local_8 = *(undefined4 *)(in_ECX + 0x38);
  local_4 = *(undefined4 *)(in_ECX + 0x40);
  *(undefined1 *)(in_ECX + 0x8c) = 0;
  local_c = DAT_009bac80;
  iVar2 = (**(code **)(*DAT_00b5af48 + 8))();
  if (*(char *)(iVar2 + 0x18) != '\0') {
    iVar2 = (**(code **)(*DAT_00b5af48 + 8))();
    iVar2 = *(byte *)(iVar2 + 0x18) - 1;
    if (2 < iVar2) {
      iVar2 = 2;
    }
    local_10 = *(undefined4 *)(in_ECX + 0x94 + iVar2 * 8);
    local_c = *(undefined4 *)(in_ECX + 0x98 + iVar2 * 8);
  }
  cVar1 = (**(code **)(*DAT_00b5a988 + 0x28))(local_10,&local_8);
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*DAT_00b5a988 + 0x28))(unaff_ESI,&local_10);
    *(char *)(in_ECX + 0x8c) = (cVar1 != '\0') + '\x01';
  }
  if (*(float *)(in_ECX + 0x80) <= DAT_009b0ec8) {
    iVar2 = (**(code **)(*DAT_00b5af48 + 8))();
    if (*(char *)(iVar2 + 0x18) != '\0') {
      uVar3 = *(undefined1 *)(in_ECX + 0x8c);
      goto LAB_005c6f32;
    }
  }
  uVar3 = 0;
LAB_005c6f32:
  FUN_005c84a0(uVar3);
  (**(code **)(*DAT_00b5a988 + 0x24))(0,&local_10);
  return;
}


// ==== FUN_005c6f70 @ 0x005c6f70 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005c6f70(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *in_ECX;
  float10 fVar4;
  float10 extraout_ST0;
  undefined4 local_18;
  
  iVar1 = *(int *)(param_1 + 4);
  local_18 = (float)iVar1;
  if (iVar1 < 0) {
    local_18 = local_18 + _DAT_0099d104;
  }
  local_18 = local_18 * DAT_0099d0ec;
  (**(code **)(*(int *)in_ECX[0x32] + 0x10))();
  (**(code **)(*(int *)in_ECX[0x33] + 0x28))(param_1);
  *(undefined1 *)in_ECX[0x30] = *(undefined1 *)((int)in_ECX + 0x16);
  if (1 < *(byte *)(in_ECX + 0x23)) {
    *(undefined1 *)in_ECX[0x30] = 0;
  }
  puVar3 = (undefined4 *)(**(code **)(*(int *)in_ECX[0x33] + 0x14))((int)register0x00000010 + -0x10)
  ;
  iVar2 = in_ECX[0x30];
  *(undefined4 *)(iVar2 + 0x1c) = *puVar3;
  *(undefined4 *)(iVar2 + 0x20) = puVar3[1];
  puVar3 = (undefined4 *)(**(code **)(*(int *)in_ECX[0x33] + 0x10))((int)register0x00000010 + -0x14)
  ;
  iVar2 = in_ECX[0x30];
  *(undefined4 *)(iVar2 + 0x14) = *puVar3;
  *(undefined4 *)(iVar2 + 0x18) = puVar3[1];
  puVar3 = (undefined4 *)(**(code **)(*(int *)in_ECX[0x33] + 0x18))(&local_18);
  iVar2 = in_ECX[0x30];
  *(undefined4 *)(iVar2 + 0x24) = *puVar3;
  *(undefined4 *)(iVar2 + 0x28) = puVar3[1];
  fVar4 = (float10)(**(code **)(*(int *)in_ECX[0x33] + 0x20))();
  *(float *)(in_ECX[0x30] + 8) = (float)fVar4;
  fVar4 = (float10)(**(code **)(*(int *)in_ECX[0x33] + 0x1c))();
  *(float *)(in_ECX[0x30] + 4) = (float)fVar4;
  *(int *)(in_ECX[0x30] + 0xc) = in_ECX[0x20];
  fVar4 = (float10)(**(code **)(*(int *)in_ECX[0x33] + 0x24))();
  *(float *)(in_ECX[0x30] + 0x10) = (float)fVar4;
  (**(code **)(*(int *)in_ECX[0x34] + 8))(in_ECX[0x30]);
  FUN_005c6d60(iVar1);
  if (in_ECX[0x38] != 0) {
    FUN_005c6720(iVar1);
  }
  if (((int *)in_ECX[0x39] != (int *)0x0) && (*(char *)((int)in_ECX + 0x17) != '\0')) {
    iVar2 = *(int *)in_ECX[0x39];
    (**(code **)(*in_ECX + 0x44))();
    (**(code **)(iVar2 + 0x14))(iVar1,*(undefined1 *)((int)in_ECX + 0x8e),(float)extraout_ST0);
    *(undefined1 *)((int)in_ECX + 0x17) = 0;
  }
  if ((int *)in_ECX[0x36] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x36] + 4))(iVar1);
  }
  if ((int *)in_ECX[0x37] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x37] + 4))(iVar1);
  }
  if ((int *)in_ECX[0x38] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x38] + 4))(iVar1);
  }
  if ((int *)in_ECX[0x39] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x39] + 4))(iVar1);
  }
  return;
}


// ==== FUN_005c7130 @ 0x005c7130 ====

void FUN_005c7130(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 *puStack_1c;
  undefined4 uStack_18;
  undefined4 auStack_c [3];
  
  iVar2 = param_1;
  param_1 = *(undefined4 *)(param_1 + 4);
  iVar1 = in_ECX + 0x1c;
  uStack_18 = 0;
  puStack_1c = &param_1;
  (**(code **)(*DAT_00b5afc4 + 8))(iVar1,iVar1);
  auStack_c[0] = *(undefined4 *)(iVar2 + 0xc);
  puStack_1c = (undefined4 *)0x0;
  uStack_18 = 0;
  (**(code **)(*DAT_00b5afc8 + 8))(iVar1,auStack_c + -2,&uStack_18,&puStack_1c,auStack_c);
  return;
}


// ==== FUN_005c71a0 @ 0x005c71a0 ====

undefined4 FUN_005c71a0(int *param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x10))();
  iVar2 = (**(code **)(*in_ECX + 0x20))();
  if (iVar1 != iVar2) {
    return 0;
  }
  if (*(byte *)(in_ECX + 0x23) < 2) {
    if (in_ECX[0x37] == 0) {
      if ((char)param_1[2] == '\x01') {
        pvVar3 = operator_new(0x5c);
        if (pvVar3 == (void *)0x0) {
          uRam00000040 = 1;
          in_ECX[0x37] = 0;
          return 1;
        }
        iVar1 = FUN_005cf430(in_ECX);
        *(undefined1 *)(iVar1 + 0x40) = 1;
        in_ECX[0x37] = iVar1;
        return 1;
      }
    }
    else {
      *(char *)(in_ECX[0x37] + 0x40) = (char)param_1[2];
    }
  }
  return 1;
}


// ==== FUN_005c7230 @ 0x005c7230 ====

undefined4 FUN_005c7230(int *param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x10))();
  iVar2 = (**(code **)(*in_ECX + 0x20))();
  if (iVar1 != iVar2) {
    return 0;
  }
  if (*(byte *)(in_ECX + 0x23) < 2) {
    if (in_ECX[0x36] == 0) {
      pvVar3 = operator_new(0x4c);
      if (pvVar3 == (void *)0x0) {
        FUN_005d0af0(param_1);
        in_ECX[0x36] = 0;
        return 1;
      }
      iVar1 = FUN_005d05d0(in_ECX);
      FUN_005d0af0(param_1);
      in_ECX[0x36] = iVar1;
      return 1;
    }
    FUN_005d0af0(param_1);
  }
  return 1;
}


// ==== FUN_005c72c0 @ 0x005c72c0 ====

uint FUN_005c72c0(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  undefined3 uVar6;
  int *in_ECX;
  
  uVar2 = (**(code **)(*param_1 + 0x10))();
  uVar3 = (**(code **)(*in_ECX + 0x20))();
  if (uVar2 != uVar3) {
    return uVar3 & 0xffffff00;
  }
  if (1 < *(byte *)(in_ECX + 0x23)) {
    iVar5 = in_ECX[0x2f];
    *(undefined4 *)(iVar5 + 8) = 0;
    return CONCAT31((int3)((uint)iVar5 >> 8),1);
  }
  if ((in_ECX[0x38] == 0) && (*(char *)((int)param_1 + 0xf) == '\x01')) {
    pvVar4 = operator_new(0xdc);
    if (pvVar4 == (void *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_005d1770(in_ECX);
    }
    in_ECX[0x38] = iVar5;
  }
  uVar1 = DAT_0099d0b4;
  if (*(char *)((int)param_1 + 0xf) == '\0') {
    *(undefined4 *)(in_ECX[0x2f] + 8) = 0;
    *(undefined1 *)(in_ECX[0x2f] + 1) = 0;
    iVar5 = in_ECX[0x2f];
    *(undefined4 *)(iVar5 + 0xc) = uVar1;
    *(undefined4 *)(in_ECX[0x2f] + 0x10) = DAT_0099d080;
    return CONCAT31((int3)((uint)iVar5 >> 8),1);
  }
  if ((char)param_1[3] == -1) {
    *(undefined1 *)in_ECX[0x2f] = *(undefined1 *)((int)param_1 + 0xd);
    iVar5 = param_1[2];
    *(int *)(in_ECX[0x2f] + 0x10) = iVar5;
    *(undefined4 *)(in_ECX[0x2f] + 8) = 1;
  }
  else {
    ((undefined1 *)in_ECX[0x2f])[1] = (char)param_1[3];
    *(undefined4 *)(in_ECX[0x2f] + 8) = 2;
    *(int *)(in_ECX[0x2f] + 0xc) = param_1[1];
    iVar5 = in_ECX[0x2f];
    if (5 < *(byte *)(iVar5 + 1)) {
      *(undefined1 *)(iVar5 + 1) = 0;
    }
  }
  uVar6 = (undefined3)((uint)iVar5 >> 8);
  if ((char)in_ECX[0x23] == '\0') {
    *(undefined1 *)(in_ECX[0x2f] + 4) = 2;
    return CONCAT31(uVar6,1);
  }
  *(undefined1 *)(in_ECX[0x2f] + 4) = 1;
  return CONCAT31(uVar6,1);
}


// ==== FUN_005c7400 @ 0x005c7400 ====

undefined4 FUN_005c7400(int *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int *in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 0x10))();
  iVar3 = (**(code **)(*in_ECX + 0x20))();
  if (iVar2 != iVar3) {
    return 0;
  }
  if (*(byte *)(in_ECX + 0x23) < 2) {
    if (in_ECX[0x39] == 0) {
      pvVar4 = operator_new(0x40);
      if (pvVar4 == (void *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_005d2580(in_ECX);
      }
      in_ECX[0x39] = iVar2;
    }
    bVar1 = *(byte *)(param_1 + 1);
    *(byte *)((int)in_ECX + 0x8e) = bVar1;
    *(undefined1 *)((int)in_ECX + 0x8d) = *(undefined1 *)((int)param_1 + 6);
    *(undefined1 *)((int)in_ECX + 0x17) = 1;
    if (5 < bVar1) {
      *(undefined1 *)((int)in_ECX + 0x8e) = 0;
    }
  }
  return 1;
}


// ==== FUN_005c7480 @ 0x005c7480 ====

undefined4 FUN_005c7480(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x10))();
  iVar2 = (**(code **)(*in_ECX + 0x20))();
  if (iVar1 != iVar2) {
    return 0;
  }
  if (in_ECX[0x38] != 0) {
    (**(code **)(*(int *)in_ECX[0x38] + 0xc))();
  }
  return 1;
}


// ==== FUN_005c74c0 @ 0x005c74c0 ====

void FUN_005c74c0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined4 *in_ECX;
  
  uVar2 = DAT_009b2dbc;
  uVar1 = DAT_0099d080;
  in_ECX[2] = &PTR_FUN_009c2780;
  in_ECX[3] = &PTR_FUN_009c2798;
  in_ECX[4] = &PTR_FUN_009c2774;
  *in_ECX = &PTR_FUN_009c27dc;
  in_ECX[2] = &PTR_FUN_009c27c4;
  in_ECX[3] = &PTR_FUN_009c27b4;
  in_ECX[4] = &PTR_FUN_009c27a8;
  *(undefined1 *)((int)in_ECX + 0x15) = 0;
  *(undefined1 *)((int)in_ECX + 0x16) = 0;
  *(undefined1 *)((int)in_ECX + 0x17) = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  in_ECX[0x1f] = 0xffffffff;
  in_ECX[0x20] = uVar1;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = uVar2;
  *(undefined1 *)(in_ECX + 0x23) = 0;
  *(undefined1 *)((int)in_ECX + 0x8e) = 0;
  *(undefined1 *)((int)in_ECX + 0x8f) = 0;
  *(undefined1 *)(in_ECX + 0x2b) = 0;
  in_ECX[0x2c] = uVar1;
  in_ECX[0x2d] = 2000;
  in_ECX[0x2e] = 0;
  in_ECX[0x33] = param_2;
  in_ECX[0x34] = param_3;
  in_ECX[0x36] = 0;
  in_ECX[0x37] = 0;
  in_ECX[0x38] = 0;
  in_ECX[0x39] = 0;
  in_ECX[1] = 0;
  in_ECX[0x32] = param_1;
  in_ECX[0x35] = param_4;
  in_ECX[0x24] = 0;
  (**(code **)(*param_1 + 8))(in_ECX + 2);
  (**(code **)(*(int *)in_ECX[0x33] + 0x30))(in_ECX + 3);
  FUN_005c7eb0(in_ECX);
  puVar5 = operator_new(0x2c);
  uVar1 = DAT_0099d0dc;
  if (puVar5 == (undefined1 *)0x0) {
    puVar5 = (undefined1 *)0x0;
  }
  else {
    *(undefined4 *)(puVar5 + 0x14) = 0;
    *(undefined4 *)(puVar5 + 0x18) = 0;
    *(undefined4 *)(puVar5 + 0x1c) = 0;
    *(undefined4 *)(puVar5 + 0x20) = uVar1;
    *puVar5 = 0;
    *(undefined4 *)(puVar5 + 4) = 0;
    *(undefined4 *)(puVar5 + 8) = 0;
    *(undefined4 *)(puVar5 + 0xc) = 0;
    *(undefined4 *)(puVar5 + 0x10) = 0;
    *(undefined4 *)(puVar5 + 0x24) = 0;
    *(undefined4 *)(puVar5 + 0x28) = 0;
  }
  in_ECX[0x30] = puVar5;
  puVar5 = operator_new(0x14);
  uVar1 = DAT_0099d080;
  if (puVar5 == (undefined1 *)0x0) {
    puVar5 = (undefined1 *)0x0;
  }
  else {
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[3] = 6;
    puVar5[2] = 6;
    puVar5[4] = 4;
    *(undefined4 *)(puVar5 + 8) = 0;
    *(undefined4 *)(puVar5 + 0xc) = uVar1;
    *(undefined4 *)(puVar5 + 0x10) = uVar1;
  }
  uVar4 = DAT_009c2848;
  uVar3 = DAT_009c1350;
  uVar2 = DAT_009bfa74;
  in_ECX[0x2f] = puVar5;
  uVar1 = DAT_009bac80;
  in_ECX[0x25] = uVar3;
  uVar3 = DAT_009c2844;
  in_ECX[0x26] = uVar4;
  in_ECX[0x27] = uVar2;
  in_ECX[0x28] = uVar1;
  in_ECX[0x29] = 0;
  in_ECX[0x2a] = uVar3;
  return;
}


// ==== FUN_005c7730 @ 0x005c7730 ====

void FUN_005c7730(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 auStack_56 [22];
  undefined1 local_40 [64];
  
  uVar2 = DAT_0099d0dc;
  uVar3 = DAT_0099d080;
  puVar1 = (undefined4 *)(in_ECX + 0x20);
  *puVar1 = DAT_0099d0dc;
  *(undefined4 *)(in_ECX + 0x24) = uVar2;
  *(undefined4 *)(in_ECX + 0x28) = uVar2;
  *(undefined4 *)(in_ECX + 0x2c) = uVar3;
  *(undefined4 *)(in_ECX + 0x30) = uVar3;
  *(undefined4 *)(in_ECX + 0x34) = uVar3;
  uVar3 = (**(code **)(**(int **)(in_ECX + 0xcc) + 8))(local_40);
  puVar4 = (undefined4 *)FUN_0040f670(auStack_56 + -6,puVar1,uVar3);
  *puVar1 = *puVar4;
  *(undefined4 *)(in_ECX + 0x24) = puVar4[1];
  *(undefined4 *)(in_ECX + 0x28) = puVar4[2];
  *(undefined4 *)(in_ECX + 0x2c) = puVar4[3];
  *(undefined4 *)(in_ECX + 0x30) = puVar4[4];
  *(undefined4 *)(in_ECX + 0x34) = puVar4[5];
  FUN_005c6b80();
  return;
}


// ==== FUN_005c77f0 @ 0x005c77f0 ====

undefined1 FUN_005c77f0(void)

{
  char cVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined1 **ppuVar4;
  undefined1 *puStack_cc;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined1 auStack_9c [4];
  undefined1 local_98 [48];
  undefined1 auStack_68 [24];
  undefined1 auStack_50 [12];
  undefined1 auStack_44 [56];
  undefined4 *puStack_c;
  int iStack_8;
  
  puStack_cc = local_98;
  (**(code **)(**(int **)(in_ECX + 0xcc) + 8))();
  thunk_FUN_0079f3a1(auStack_44,0,auStack_9c);
  puVar3 = puStack_c;
  ppuVar4 = &puStack_cc;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar4 = (undefined1 *)*puVar3;
    puVar3 = puVar3 + 1;
    ppuVar4 = ppuVar4 + 1;
  }
  iVar2 = FUN_0040e920(auStack_68,puStack_c + 3,auStack_50);
  uStack_b0 = *(undefined4 *)(iVar2 + 0x10);
  uStack_ac = *(undefined4 *)(iVar2 + 0x14);
  cVar1 = (**(code **)(**(int **)(in_ECX + 0xd4) + 8))(&puStack_cc,iStack_8);
  if (cVar1 == '\0') {
    return 0;
  }
  thunk_FUN_0079e5a0(iStack_8 + 8,iStack_8 + 8,&uStack_b0);
  return 1;
}


// ==== FUN_005c78c0 @ 0x005c78c0 ====

void FUN_005c78c0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined1 auStack_56 [18];
  undefined1 auStack_44 [68];
  
  puVar1 = (undefined4 *)(in_ECX + 0x20);
  (**(code **)(**(int **)(in_ECX + 0xd4) + 0x10))(puVar1);
  uVar2 = (**(code **)(**(int **)(in_ECX + 0xcc) + 8))(auStack_44);
  puVar3 = (undefined4 *)FUN_0040f670(auStack_56 + -10,puVar1,uVar2);
  *puVar1 = *puVar3;
  *(undefined4 *)(in_ECX + 0x24) = puVar3[1];
  *(undefined4 *)(in_ECX + 0x28) = puVar3[2];
  *(undefined4 *)(in_ECX + 0x2c) = puVar3[3];
  *(undefined4 *)(in_ECX + 0x30) = puVar3[4];
  *(undefined4 *)(in_ECX + 0x34) = puVar3[5];
  FUN_005c6b80();
  return;
}


// ==== FUN_005c7930 @ 0x005c7930 ====

void FUN_005c7930(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a780 + 8))(param_1);
  *(undefined4 *)(in_ECX + 0xc4) = uVar1;
  *(undefined4 *)(in_ECX + 0x90) = 0;
  return;
}


// ==== FUN_005c7960 @ 0x005c7960 ====

uint FUN_005c7960(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    uVar2 = FUN_005c6f70(param_1);
  }
  else {
    uVar2 = (**(code **)(*param_1 + 4))();
    if (uVar2 < 0x60060022) {
      if (uVar2 == 0x60060021) {
        uVar2 = FUN_005c67d0(param_1);
        return uVar2;
      }
      if (uVar2 == 0x60010030) {
        uVar2 = FUN_005c7230(param_1);
        return uVar2;
      }
      if (uVar2 == 0x60010031) {
        uVar2 = FUN_005c71a0(param_1);
        return uVar2;
      }
      uVar2 = uVar2 + 0x9ff9ffe0;
      if (uVar2 == 0) {
        uVar2 = FUN_005c7480(param_1);
        return uVar2;
      }
    }
    else {
      if (uVar2 == 0x60060031) {
        uVar2 = FUN_005c72c0(param_1);
        return uVar2;
      }
      uVar2 = uVar2 + 0x9ff9ffce;
      if (uVar2 == 0) {
        uVar2 = FUN_005c7400(param_1);
        return uVar2;
      }
    }
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_005c7a10 @ 0x005c7a10 ====

void FUN_005c7a10(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined1 param_4)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = DAT_00a0fd50;
  *(undefined4 *)(in_ECX + 0x1c) = param_1;
  *(undefined1 *)(in_ECX + 0x14) = param_2;
  *(undefined4 *)(in_ECX + 0x78) = param_3;
  *(undefined4 *)(in_ECX + 0xb8) = 0;
  *(undefined1 *)(in_ECX + 0xac) = 1;
  *(undefined4 *)(in_ECX + 0xb0) = uVar1;
  *(undefined1 *)(in_ECX + 0x18) = param_4;
  FUN_005c7730();
  return;
}


// ==== FUN_005c7a60 @ 0x005c7a60 ====

void FUN_005c7a60(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int in_ECX;
  
  puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar4 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  uVar1 = *(undefined4 *)(in_ECX + 0x1c);
  uVar2 = *(undefined4 *)(param_1 + 8);
  uVar3 = *(undefined4 *)(param_1 + 4);
  puVar4[5] = *(undefined4 *)(param_1 + 0xc);
  *puVar4 = &PTR_FUN_009c2850;
  puVar4[1] = uVar1;
  puVar4[2] = 0x18;
  puVar4[3] = uVar3;
  puVar4[4] = uVar2;
  puVar4[0xc] = 0xf;
  puVar4[0xb] = 0;
  *(undefined1 *)(puVar4 + 7) = 0;
  FUN_00401660(param_1 + 0x10,0,0xffffffff);
  FUN_00797a20(puVar4);
  return;
}


// ==== FUN_005c7ae0 @ 0x005c7ae0 ====

void FUN_005c7ae0(undefined4 param_1,int param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  int in_ECX;
  int *unaff_retaddr;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  uVar2 = DAT_009c2848;
  if (*(int *)(in_ECX + 0xcc) != 0) {
    *(bool *)(param_2 + 0x24) = *(char *)(in_ECX + 0x14) == '\x01';
    *(undefined1 *)(param_2 + 0x20) = *(undefined1 *)(in_ECX + 0x78);
    *(undefined1 *)(param_2 + 0x23) = 0;
    *(undefined1 *)(param_2 + 0x22) = 0xff;
    *(undefined1 *)(param_2 + 0x26) = 0;
    *(undefined4 *)(param_2 + 0x28) = uVar2;
    *(undefined1 *)(param_2 + 0x21) = 0xf0;
    (**(code **)(**(int **)(in_ECX + 0xcc) + 4))(param_2);
    (**(code **)(**(int **)(in_ECX + 0xd4) + 0xc))(unaff_retaddr,param_2);
    (**(code **)(*unaff_retaddr + 0x94))(in_ECX + 0x38);
    if (*(int *)(in_ECX + 0x1c) != 0x12) {
      *(undefined1 *)(param_2 + 0x23) = *(undefined1 *)(in_ECX + 0xac);
      uVar3 = FUN_00802534();
      *(undefined1 *)(param_2 + 0x22) = uVar3;
      if (*(char *)(in_ECX + 0x8f) != '\0') {
        *(undefined1 *)(param_2 + 0x20) = 0;
      }
      if (*(int *)(in_ECX + 0xd8) != 0) {
        (**(code **)(**(int **)(in_ECX + 0xd8) + 8))(unaff_retaddr,param_2);
      }
      if (*(byte *)(in_ECX + 0x8c) < 2) {
        if (*(int *)(in_ECX + 0xdc) != 0) {
          (**(code **)(**(int **)(in_ECX + 0xdc) + 8))(unaff_retaddr,param_2);
        }
        if (*(int *)(in_ECX + 0xe0) != 0) {
          (**(code **)(**(int **)(in_ECX + 0xe0) + 8))(unaff_retaddr,param_2);
        }
        if (*(int *)(in_ECX + 0xe4) != 0) {
          (**(code **)(**(int **)(in_ECX + 0xe4) + 8))(unaff_retaddr,param_2);
        }
      }
    }
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_m_pTransform____NULL_009c2754,0x14);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005c7c30 @ 0x005c7c30 ====

bool FUN_005c7c30(int *param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  
  iVar3 = (**(code **)(*param_1 + 4))();
  if (iVar3 == 0x70) {
    *(char *)(in_ECX + 0x15) = (char)param_1[1];
  }
  else {
    iVar3 = (**(code **)(*param_1 + 4))();
    if (iVar3 == 0x61) {
      *(undefined1 *)(in_ECX + 0x8f) = 1;
      *(undefined4 *)(in_ECX + 0xb8) = 0;
      return true;
    }
    iVar3 = (**(code **)(*param_1 + 4))();
    if (iVar3 == 0x80) {
      *(int *)(in_ECX + 0x7c) = param_1[1];
      return true;
    }
    iVar3 = (**(code **)(*param_1 + 4))();
    if (iVar3 == 0x41) {
      FUN_005c7130(param_1);
      return true;
    }
    iVar3 = (**(code **)(*param_1 + 4))();
    if (iVar3 == 0x40) {
      FUN_005c7a60(param_1);
      return true;
    }
    iVar3 = (**(code **)(*param_1 + 4))();
    uVar1 = DAT_00a0fd50;
    if ((iVar3 == 0x30) && (DAT_0099cdc8 < (float)param_1[0x11])) {
      *(undefined1 *)(in_ECX + 0xac) = 1;
      *(undefined4 *)(in_ECX + 0xb8) = 0;
      *(undefined4 *)(in_ECX + 0xb0) = uVar1;
    }
    cVar2 = (**(code **)(**(int **)(in_ECX + 0xd4) + 4))(param_1);
    if (cVar2 == '\0') {
      cVar2 = (**(code **)(**(int **)(in_ECX + 200) + 0xc))(param_1);
      if (cVar2 == '\0') {
        cVar2 = (**(code **)(**(int **)(in_ECX + 0xcc) + 0x2c))(param_1);
        return cVar2 != '\0';
      }
    }
  }
  return true;
}


// ==== FUN_005c7d40 @ 0x005c7d40 ====

undefined4 FUN_005c7d40(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1c);
}


// ==== FUN_005c7d50 @ 0x005c7d50 ====

void FUN_005c7d50(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x20);
  param_1[1] = *(undefined4 *)(in_ECX + 0x24);
  param_1[2] = *(undefined4 *)(in_ECX + 0x28);
  param_1[3] = *(undefined4 *)(in_ECX + 0x2c);
  param_1[4] = *(undefined4 *)(in_ECX + 0x30);
  param_1[5] = *(undefined4 *)(in_ECX + 0x34);
  return;
}


// ==== FUN_005c7d80 @ 0x005c7d80 ====

float10 FUN_005c7d80(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x80) * (float10)DAT_0099d0b4;
}


// ==== FUN_005c7d90 @ 0x005c7d90 ====

undefined4 FUN_005c7d90(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0xcc) + 0x10))(param_1);
  return param_1;
}


// ==== FUN_005c7db0 @ 0x005c7db0 ====

undefined4 FUN_005c7db0(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0xcc) + 0x14))(param_1);
  return param_1;
}


// ==== FUN_005c7dd0 @ 0x005c7dd0 ====

void FUN_005c7dd0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005c7dd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xcc) + 0x20))();
  return;
}


// ==== FUN_005c7de0 @ 0x005c7de0 ====

void FUN_005c7de0(void)

{
  FUN_005c7e20();
  return;
}


// ==== FUN_005c7df0 @ 0x005c7df0 ====

void FUN_005c7df0(void)

{
  FUN_005c7e20();
  return;
}


// ==== FUN_005c7e00 @ 0x005c7e00 ====

void FUN_005c7e00(void)

{
  FUN_005c7d40();
  return;
}


// ==== FUN_005c7e10 @ 0x005c7e10 ====

void FUN_005c7e10(void)

{
  FUN_005c7e20();
  return;
}


// ==== FUN_005c7e20 @ 0x005c7e20 ====

void FUN_005c7e20(byte param_1)

{
  void *in_ECX;
  
  FUN_005c68f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005c7e40 @ 0x005c7e40 ====

undefined4 FUN_005c7e40(void)

{
  return 0x60010012;
}


// ==== FUN_005c7e50 @ 0x005c7e50 ====

void FUN_005c7e50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2850;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_005c7e80 @ 0x005c7e80 ====

void FUN_005c7e80(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005c7e85. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x24) + 0x20))();
  return;
}


// ==== FUN_005c7e90 @ 0x005c7e90 ====

undefined1 FUN_005c7e90(void)

{
  return 0;
}


// ==== FUN_005c7ea0 @ 0x005c7ea0 ====

void FUN_005c7ea0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005c7ea5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x24) + 0x2c))();
  return;
}


// ==== FUN_005c7eb0 @ 0x005c7eb0 ====

void FUN_005c7eb0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x24) = param_1;
  return;
}


// ==== FUN_005c7ec0 @ 0x005c7ec0 ====

void FUN_005c7ec0(undefined4 param_1,float param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1c) = param_1;
  *(float *)(in_ECX + 0x20) = *(float *)(in_ECX + 0x20) + param_2;
  return;
}


// ==== FUN_005c7ee0 @ 0x005c7ee0 ====

undefined4 FUN_005c7ee0(undefined1 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined1 *)(in_ECX + 0x3a);
  return *(undefined4 *)(in_ECX + 0x3c);
}


// ==== FUN_005c7ef0 @ 0x005c7ef0 ====

bool FUN_005c7ef0(void)

{
  int in_ECX;
  
  return *(char *)(in_ECX + 0x3a) != '\0';
}


// ==== FUN_005c7f00 @ 0x005c7f00 ====

void FUN_005c7f00(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005c7f0b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(*(int *)(in_ECX + 0x24) + 200) + 0x14))();
  return;
}


// ==== FUN_005c7f10 @ 0x005c7f10 ====

void FUN_005c7f10(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x24) == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x005c7f1d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x24) + 0x28))();
  return;
}


// ==== FUN_005c7f30 @ 0x005c7f30 ====

void FUN_005c7f30(float *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  float fVar3;
  int in_ECX;
  float fVar4;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float fStack_c;
  float fStack_8;
  
  fVar4 = DAT_0099d0dc;
  if ((*(int *)(in_ECX + 0x2c) == 0) ||
     (local_1c = (float)(*(int *)(in_ECX + 0x30) - *(int *)(in_ECX + 0x2c) >> 2), local_1c == 0.0))
  {
    *param_1 = DAT_0099d0dc;
    param_1[1] = fVar4;
    fVar3 = DAT_0099d080;
    param_1[2] = fVar4;
    param_1[3] = fVar3;
    param_1[4] = fVar3;
    param_1[5] = fVar3;
    return;
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x2c);
  (**(code **)(*(int *)*puVar1 + 0x10))(param_1);
  puVar2 = *(undefined4 **)(in_ECX + 0x30);
  while (puVar1 = puVar1 + 1, puVar1 != puVar2) {
    (**(code **)(*(int *)*puVar1 + 0x10))(&local_1c);
    fVar4 = local_1c;
    if (*param_1 <= local_1c && local_1c != *param_1) {
      fVar4 = *param_1;
    }
    *param_1 = fVar4;
    fVar4 = local_18;
    if (param_1[1] <= local_18 && local_18 != param_1[1]) {
      fVar4 = param_1[1];
    }
    param_1[1] = fVar4;
    fVar4 = local_14;
    if (param_1[2] <= local_14 && local_14 != param_1[2]) {
      fVar4 = param_1[2];
    }
    param_1[2] = fVar4;
    fVar4 = local_10;
    if (local_10 < param_1[3]) {
      fVar4 = param_1[3];
    }
    param_1[3] = fVar4;
    fVar4 = fStack_c;
    if (fStack_c < param_1[4]) {
      fVar4 = param_1[4];
    }
    param_1[4] = fVar4;
    fVar4 = fStack_8;
    if (fStack_8 < param_1[5]) {
      fVar4 = param_1[5];
    }
    param_1[5] = fVar4;
  }
  return;
}


// ==== FUN_005c8080 @ 0x005c8080 ====

void FUN_005c8080(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x2c);
  if ((puVar2 != (undefined4 *)0x0) && (*(int *)(in_ECX + 0x30) - (int)puVar2 >> 2 != 0)) {
    puVar1 = *(undefined4 **)(in_ECX + 0x30);
    for (; puVar2 != puVar1; puVar2 = puVar2 + 1) {
      (**(code **)(*(int *)*puVar2 + 0x50))(param_1,param_2,param_3);
    }
  }
  return;
}


// ==== FUN_005c80d0 @ 0x005c80d0 ====

void FUN_005c80d0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x2c);
  if ((puVar2 != (undefined4 *)0x0) && (*(int *)(in_ECX + 0x30) - (int)puVar2 >> 2 != 0)) {
    puVar1 = *(undefined4 **)(in_ECX + 0x30);
    for (; puVar2 != puVar1; puVar2 = puVar2 + 1) {
      (**(code **)(*(int *)*puVar2 + 0x14))(param_1,param_2);
    }
  }
  return;
}


// ==== FUN_005c8120 @ 0x005c8120 ====

bool FUN_005c8120(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x48) == 0;
}


// ==== FUN_005c8130 @ 0x005c8130 ====

char FUN_005c8130(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  int in_ECX;
  char cVar6;
  undefined4 *puVar7;
  float local_1c;
  undefined4 local_14;
  undefined4 uStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (*(char *)(in_ECX + 8) == '\0') {
    return '\0';
  }
  puVar7 = *(undefined4 **)(in_ECX + 0x2c);
  puVar1 = *(undefined4 **)(in_ECX + 0x30);
  cVar6 = '\0';
  local_1c = 0.0;
  if (puVar7 != puVar1) {
    cVar6 = '\0';
    do {
      cVar5 = (**(code **)(*(int *)*puVar7 + 8))(param_1,&local_14);
      if (cVar5 != '\0') {
        if (cVar6 == '\0') {
          *param_2 = local_14;
          param_2[1] = uStack_10;
          param_2[2] = fStack_c;
          param_2[3] = fStack_8;
          param_2[4] = fStack_4;
          fVar2 = (float)param_2[2] - *(float *)(param_1 + 0xc);
          cVar6 = '\x01';
          fVar4 = (float)param_2[3] - *(float *)(param_1 + 0x10);
          fVar3 = (float)param_2[4] - *(float *)(param_1 + 0x14);
          local_1c = SQRT(fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3);
        }
        else {
          fVar2 = fStack_c - *(float *)(param_1 + 0xc);
          fVar4 = fStack_8 - *(float *)(param_1 + 0x10);
          fVar3 = fStack_4 - *(float *)(param_1 + 0x14);
          fVar2 = SQRT(fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3);
          if (fVar2 < local_1c) {
            *param_2 = local_14;
            param_2[1] = uStack_10;
            param_2[2] = fStack_c;
            param_2[3] = fStack_8;
            param_2[4] = fStack_4;
            local_1c = fVar2;
          }
        }
      }
      puVar7 = puVar7 + 1;
    } while (puVar7 != puVar1);
  }
  return cVar6;
}


// ==== FUN_005c8270 @ 0x005c8270 ====

void FUN_005c8270(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  if (*(char *)(in_ECX + 8) != '\0') {
    puVar1 = *(undefined4 **)(in_ECX + 0x30);
    for (puVar2 = *(undefined4 **)(in_ECX + 0x2c); puVar2 != puVar1; puVar2 = puVar2 + 1) {
      (**(code **)(*(int *)*puVar2 + 0xc))(param_1,param_2);
    }
  }
  return;
}


// ==== FUN_005c82b0 @ 0x005c82b0 ====

void FUN_005c82b0(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x30);
  for (puVar2 = *(undefined4 **)(in_ECX + 0x2c); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(*(int *)*puVar2 + 0x4c))(param_1);
  }
  return;
}


// ==== FUN_005c82e0 @ 0x005c82e0 ====

undefined4 FUN_005c82e0(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  char cVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  if (param_1 == 0) {
    return 0;
  }
  puVar3 = *(undefined4 **)(in_ECX + 0x2c);
  puVar1 = *(undefined4 **)(in_ECX + 0x30);
  while( true ) {
    if (puVar3 == puVar1) {
      return 0;
    }
    cVar2 = (**(code **)(*(int *)*puVar3 + 0x18))(param_1,param_2);
    if (cVar2 != '\0') break;
    puVar3 = puVar3 + 1;
  }
  return 1;
}


// ==== FUN_005c8330 @ 0x005c8330 ====

undefined4 FUN_005c8330(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  char cVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 0x2c);
  puVar1 = *(undefined4 **)(in_ECX + 0x30);
  while( true ) {
    if (puVar3 == puVar1) {
      return 0;
    }
    cVar2 = (**(code **)(*(int *)*puVar3 + 0x1c))(param_1,param_2);
    if (cVar2 != '\0') break;
    puVar3 = puVar3 + 1;
  }
  return 1;
}


// ==== FUN_005c8370 @ 0x005c8370 ====

void FUN_005c8370(undefined4 *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  *(undefined4 *)(in_ECX + 0xc) = 1;
  *(undefined4 *)(in_ECX + 0x10) = *param_1;
  *(undefined4 *)(in_ECX + 0x14) = param_1[1];
  *(undefined4 *)(in_ECX + 0x18) = param_1[2];
  *(undefined4 *)(in_ECX + 0x1c) = param_1[3];
  *(undefined4 *)(in_ECX + 0x20) = param_1[4];
  cVar2 = (**(code **)(**(int **)(*(int *)(in_ECX + 0x24) + 200) + 0x14))();
  if ((cVar2 != '\0') || (*(char *)(in_ECX + 8) != '\0')) {
    puVar1 = *(undefined4 **)(in_ECX + 0x30);
    for (puVar3 = *(undefined4 **)(in_ECX + 0x2c); puVar3 != puVar1; puVar3 = puVar3 + 1) {
      (**(code **)(*(int *)*puVar3 + 0x60))(param_1);
    }
  }
  return;
}


// ==== FUN_005c83e0 @ 0x005c83e0 ====

void FUN_005c83e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x2c);
  puVar1 = *(undefined4 **)(in_ECX + 0x30);
  *(undefined4 *)(in_ECX + 0x1c) = param_2;
  *(undefined4 *)(in_ECX + 0x20) = param_3;
  for (; puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(*(int *)*puVar2 + 100))(param_1,param_2,param_3);
  }
  return;
}


// ==== FUN_005c8430 @ 0x005c8430 ====

void FUN_005c8430(char param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = *(char *)(in_ECX + 8);
  if (cVar1 != param_1) {
    *(char *)(in_ECX + 8) = param_1;
    if (cVar1 == '\x01') {
      if (param_1 == '\0') {
        *(undefined4 *)(in_ECX + 0xc) = 0;
      }
    }
    else if ((param_1 != '\0') && (*(int *)(in_ECX + 0xc) == 1)) {
      FUN_005c8370();
      return;
    }
  }
  return;
}


// ==== FUN_005c84a0 @ 0x005c84a0 ====

void FUN_005c84a0(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  if (*(char *)(in_ECX + 0x38) != (char)param_1) {
    puVar1 = *(undefined4 **)(in_ECX + 0x30);
    for (puVar2 = *(undefined4 **)(in_ECX + 0x2c); puVar2 != puVar1; puVar2 = puVar2 + 1) {
      (**(code **)(*(int *)*puVar2 + 0x74))(param_1);
    }
    *(char *)(in_ECX + 0x38) = (char)param_1;
  }
  return;
}


// ==== FUN_005c84e0 @ 0x005c84e0 ====

/* WARNING: Removing unreachable block (ram,0x005c8539) */

undefined4 FUN_005c84e0(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  int in_ECX;
  uint uVar7;
  undefined4 *_Dst;
  bool bVar8;
  bool bVar9;
  byte *pbStack_c;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    return 0;
  }
  _Dst = *(undefined4 **)(in_ECX + 0x2c);
  puVar1 = *(undefined4 **)(in_ECX + 0x30);
  do {
    if (_Dst == puVar1) {
      return 0;
    }
    piVar2 = (int *)*_Dst;
    iVar5 = (**(code **)(*piVar2 + 0x6c))();
    uVar3 = *(uint *)(param_1 + 0x18);
    if (*(uint *)(param_1 + 0x1c) < 0x10) {
      pbStack_c = (byte *)(param_1 + 8);
    }
    else {
      pbStack_c = *(byte **)(param_1 + 8);
    }
    uVar4 = *(uint *)(iVar5 + 0x14);
    if (uVar4 == 0) {
LAB_005c8573:
      if ((uVar3 <= uVar4) && (uVar4 == uVar3)) {
        (**(code **)*piVar2)(1);
        _memmove(_Dst,_Dst + 1,(puVar1[0xc] - (int)(_Dst + 1) >> 2) * 4);
        puVar1[0xc] = puVar1[0xc] + -4;
        return 1;
      }
    }
    else {
      uVar7 = uVar4;
      if (uVar3 <= uVar4) {
        uVar7 = uVar3;
      }
      if (*(uint *)(iVar5 + 0x18) < 0x10) {
        pbVar6 = (byte *)(iVar5 + 4);
      }
      else {
        pbVar6 = *(byte **)(iVar5 + 4);
      }
      bVar8 = false;
      iVar5 = 0;
      bVar9 = true;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        bVar8 = *pbVar6 < *pbStack_c;
        bVar9 = *pbVar6 == *pbStack_c;
        pbVar6 = pbVar6 + 1;
        pbStack_c = pbStack_c + 1;
      } while (bVar9);
      if (!bVar9) {
        iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      }
      if (iVar5 == 0) goto LAB_005c8573;
    }
    _Dst = _Dst + 1;
  } while( true );
}


// ==== FUN_005c85e0 @ 0x005c85e0 ====

undefined4 FUN_005c85e0(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_005c8a80(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0x44)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0x10);
}


// ==== FUN_005c8620 @ 0x005c8620 ====

void FUN_005c8620(byte param_1)

{
  int in_ECX;
  int local_4;
  
  if (param_1 < 0x65) {
    local_4 = in_ECX;
    FUN_005c8a80(&local_4,&param_1);
    if (local_4 != *(int *)(in_ECX + 0x44)) {
      FUN_0051a2a0(&param_1,local_4);
    }
  }
  else if (*(byte *)(in_ECX + 0x3a) == param_1) {
    *(undefined1 *)(in_ECX + 0x3a) = 0;
    *(undefined4 *)(in_ECX + 0x3c) = 0;
    return;
  }
  return;
}


// ==== FUN_005c8670 @ 0x005c8670 ====

void FUN_005c8670(byte param_1,undefined4 param_2)

{
  byte bVar1;
  int in_ECX;
  int local_10;
  undefined4 local_c;
  undefined1 local_8 [8];
  
  bVar1 = param_1;
  if (param_1 < 0x65) {
    FUN_005c8a80(&local_10,&param_1);
    if (local_10 == *(int *)(in_ECX + 0x44)) {
      local_c = param_2;
      local_10 = CONCAT31(local_10._1_3_,bVar1);
      FUN_005c8d90(local_8,&local_10);
    }
  }
  else if (*(byte *)(in_ECX + 0x3a) < param_1) {
    *(byte *)(in_ECX + 0x3a) = param_1;
    *(undefined4 *)(in_ECX + 0x3c) = param_2;
    return;
  }
  return;
}


// ==== FUN_005c86e0 @ 0x005c86e0 ====

void FUN_005c86e0(void)

{
  int *piVar1;
  void *_Memory;
  undefined4 *in_ECX;
  int *piVar2;
  undefined1 auStack_4 [4];
  
  piVar2 = (int *)in_ECX[0xb];
  piVar1 = (int *)in_ECX[0xc];
  *in_ECX = &PTR_FUN_009c2864;
  for (; piVar2 != piVar1; piVar2 = piVar2 + 1) {
    if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
  }
  if ((void *)in_ECX[0xb] != (void *)0x0) {
    _free((void *)in_ECX[0xb]);
    return;
  }
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  _Memory = *(void **)(in_ECX[0x11] + 4);
  if (*(char *)((int)_Memory + 0x15) == '\0') {
    FUN_005c8910(*(undefined4 *)((int)_Memory + 8));
    _free(_Memory);
    return;
  }
  *(undefined4 *)(in_ECX[0x11] + 4) = in_ECX[0x11];
  in_ECX[0x12] = 0;
  *(undefined4 *)in_ECX[0x11] = in_ECX[0x11];
  *(undefined4 *)(in_ECX[0x11] + 8) = in_ECX[0x11];
  FUN_005c8cd0(auStack_4,*(undefined4 *)in_ECX[0x11],(undefined4 *)in_ECX[0x11]);
  _free((void *)in_ECX[0x11]);
  return;
}


// ==== FUN_005c87c0 @ 0x005c87c0 ====

void FUN_005c87c0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2864;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0x20;
  in_ECX[6] = 0;
  in_ECX[9] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 1;
  *(undefined1 *)((int)in_ECX + 0x39) = 1;
  iVar1 = FUN_005c89e0();
  in_ECX[0x11] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[0x11] + 4) = in_ECX[0x11];
  *(undefined4 *)in_ECX[0x11] = in_ECX[0x11];
  *(undefined4 *)(in_ECX[0x11] + 8) = in_ECX[0x11];
  in_ECX[0x12] = 0;
  *(undefined1 *)((int)in_ECX + 0x3a) = 0;
  in_ECX[0xf] = 0;
  in_ECX[1] = 2;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  return;
}


// ==== FUN_005c8840 @ 0x005c8840 ====

undefined4 FUN_005c8840(int param_1)

{
  int *piVar1;
  undefined1 auStack_c [4];
  
  if (*(int *)(param_1 + 0x34) == 0) {
    piVar1 = (int *)(**(code **)(*DAT_00b5afec + 8))(param_1);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x58))();
      FUN_005c4470(auStack_c + 8);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_005c8890 @ 0x005c8890 ====

undefined4 FUN_005c8890(int *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  iVar3 = (**(code **)(*param_1 + 4))();
  if (iVar3 == 0x30) {
    cVar2 = FUN_005c8840(param_1);
    if (cVar2 != '\0') {
      return 1;
    }
  }
  else if ((iVar3 == 0x31) && (cVar2 = FUN_005c84e0(param_1), cVar2 != '\0')) {
    return 1;
  }
  puVar4 = *(undefined4 **)(in_ECX + 0x2c);
  puVar1 = *(undefined4 **)(in_ECX + 0x30);
  while( true ) {
    if (puVar4 == puVar1) {
      return 0;
    }
    cVar2 = (**(code **)(*(int *)*puVar4 + 4))(param_1);
    if (cVar2 != '\0') break;
    puVar4 = puVar4 + 1;
  }
  return 1;
}


// ==== FUN_005c8910 @ 0x005c8910 ====

void FUN_005c8910(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_005c8910(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_005c8950 @ 0x005c8950 ====

void * FUN_005c8950(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982ab0;
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


// ==== Catch@005c89c5 @ 0x005c89c5 ====

void Catch_005c89c5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005c89e0 @ 0x005c89e0 ====

void FUN_005c89e0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982ac0;
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


// ==== Catch@005c8a6a @ 0x005c8a6a ====

void Catch_005c8a6a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_005c8a80 @ 0x005c8a80 ====

void FUN_005c8a80(undefined4 *param_1,byte *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x15) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (*(byte *)(puVar1 + 3) < *param_2) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x15) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < *(byte *)(puVar3 + 3))) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_005c8af0 @ 0x005c8af0 ====

void FUN_005c8af0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_005c8950(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_005c8bf5:
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
      if ((char)piVar6[5] == '\0') goto LAB_005c8bf5;
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


// ==== FUN_005c8cd0 @ 0x005c8cd0 ====

void FUN_005c8cd0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_005c8910(piVar6[1]);
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


// ==== FUN_005c8d90 @ 0x005c8d90 ====

void FUN_005c8d90(undefined4 *param_1,byte *param_2)

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
      puVar4 = (undefined4 *)FUN_005c8af0(&param_2,1,puVar4,pbVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (*(byte *)((int)param_2 + 0xc) < *pbVar2) {
    puVar4 = (undefined4 *)FUN_005c8af0(&param_2,bVar5,puVar4,pbVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_005c8e50 @ 0x005c8e50 ====

float10 FUN_005c8e50(void)

{
  return (float10)DAT_0099cdc8;
}


// ==== FUN_005c8e60 @ 0x005c8e60 ====

void FUN_005c8e60(byte param_1)

{
  void *in_ECX;
  
  FUN_005c86e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005c8e80 @ 0x005c8e80 ====

float10 FUN_005c8e80(void)

{
  return (float10)DAT_0099d0b4;
}


// ==== FUN_005c8e90 @ 0x005c8e90 ====

undefined1 FUN_005c8e90(void)

{
  return 1;
}


// ==== FUN_005c8ea0 @ 0x005c8ea0 ====

void FUN_005c8ea0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2e74;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005c8ec0 @ 0x005c8ec0 ====

void FUN_005c8ec0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2eb0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005c8ee0 @ 0x005c8ee0 ====

void FUN_005c8ee0(undefined4 param_1,undefined1 param_2,undefined4 *param_3)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x2c) = param_1;
  *(undefined1 *)(in_ECX + 0x31) = param_2;
  *(undefined4 *)(in_ECX + 0x3c) = *param_3;
  return;
}


// ==== FUN_005c8f00 @ 0x005c8f00 ====

undefined4 FUN_005c8f00(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x10))();
  iVar2 = (**(code **)(*in_ECX + 4))();
  if (iVar1 == iVar2) {
    *(char *)(in_ECX + 0xc) = (char)param_1[2];
    return 1;
  }
  return 0;
}


// ==== FUN_005c8f40 @ 0x005c8f40 ====

undefined4 FUN_005c8f40(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x2c);
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (iVar2 == iVar1) {
    *(char *)(in_ECX + 0x31) = (char)param_1[2];
    return 1;
  }
  return 0;
}


// ==== FUN_005c8f70 @ 0x005c8f70 ====

bool FUN_005c8f70(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x10))();
  return iVar1 == *(int *)(in_ECX + 0x2c);
}


// ==== FUN_005c8f90 @ 0x005c8f90 ====

void FUN_005c8f90(void)

{
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x28) == '\0') || (*(char *)(in_ECX + 0x1c) != '\0')) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x005c8fa1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x2c) + 0x50))();
  return;
}


// ==== FUN_005c8fb0 @ 0x005c8fb0 ====

uint FUN_005c8fb0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  uint in_EAX;
  uint uVar2;
  int in_ECX;
  
  if (((*(char *)(in_ECX + 8) == '\0') || (*(char *)(in_ECX + -4) != '\0')) ||
     (*(char *)(in_ECX + 9) == '\0')) {
    return in_EAX & 0xffffff00;
  }
  uVar2 = (**(code **)(**(int **)(in_ECX + 0xc) + 8))(param_1,param_2);
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  uVar1 = *(undefined4 *)(in_ECX + 4);
  *(undefined4 *)(param_2 + 4) = uVar1;
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}


// ==== FUN_005c9000 @ 0x005c9000 ====

undefined4 FUN_005c9000(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x3c))(param_1);
  return param_1;
}


// ==== FUN_005c9020 @ 0x005c9020 ====

void FUN_005c9020(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005c9025. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x40))();
  return;
}


// ==== FUN_005c9030 @ 0x005c9030 ====

void FUN_005c9030(void)

{
  int *in_ECX;
  float10 fVar1;
  undefined4 *unaff_retaddr;
  undefined4 uStack_c;
  undefined4 local_8 [2];
  
  (**(code **)(*in_ECX + 8))(local_8);
  fVar1 = (float10)(**(code **)(*in_ECX + 0xc))();
  unaff_retaddr[1] = (float)fVar1;
  *unaff_retaddr = uStack_c;
  unaff_retaddr[2] = local_8[0];
  return;
}


// ==== FUN_005c9080 @ 0x005c9080 ====

void FUN_005c9080(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005c9085. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x34) + 0x44))();
  return;
}


// ==== FUN_005c9090 @ 0x005c9090 ====

void FUN_005c9090(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005c9095. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x34) + 0x2c))();
  return;
}


// ==== FUN_005c90a0 @ 0x005c90a0 ====

void FUN_005c90a0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005c90a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x34) + 0x18))();
  return;
}


// ==== FUN_005c90b0 @ 0x005c90b0 ====

undefined1 FUN_005c90b0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x30);
}


// ==== FUN_005c90c0 @ 0x005c90c0 ====

void FUN_005c90c0(char param_1)

{
  int in_ECX;
  
  if (param_1 != *(char *)(in_ECX + 0x1c)) {
    (**(code **)(**(int **)(in_ECX + 0x2c) + 0x54))(param_1 == '\0');
  }
  *(char *)(in_ECX + 0x1c) = param_1;
  return;
}


// ==== FUN_005c90f0 @ 0x005c90f0 ====

void FUN_005c90f0(undefined1 param_1,undefined1 param_2)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x41) = param_1;
  *(undefined1 *)(in_ECX + 0x42) = param_2;
  return;
}


// ==== FUN_005c9110 @ 0x005c9110 ====

void FUN_005c9110(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x34) + 0x48))();
  if (iVar1 == 0) {
    FUN_005c6820(param_1,param_2);
  }
  return;
}


// ==== FUN_005c9140 @ 0x005c9140 ====

void FUN_005c9140(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x34) + 0x48))();
  if (iVar1 == 0) {
    FUN_005c6830(param_1);
  }
  return;
}


// ==== FUN_005c9160 @ 0x005c9160 ====

void FUN_005c9160(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x2c) == 0x12) {
    *(undefined1 *)(in_ECX + 0x24) = 0;
    (**(code **)(*DAT_00b5afac + 4))(0x12,in_ECX + 8,1);
    (**(code **)(**(int **)(in_ECX + 0x34) + 0x54))(1);
  }
  else {
    (**(code **)(*DAT_00b5afac + 4))(*(int *)(in_ECX + 0x2c),in_ECX + 8,0);
    (**(code **)(**(int **)(in_ECX + 0x34) + 0x54))(*(char *)(in_ECX + 0x24) == '\0');
  }
  (**(code **)(*DAT_00b5a728 + 4))(in_ECX + 0x28);
  *(undefined1 *)(in_ECX + 0x32) = 0;
  uVar1 = (**(code **)(*DAT_00b5b010 + 0x14))();
  *(undefined4 *)(in_ECX + 0x58) = uVar1;
  return;
}


// ==== FUN_005c91e0 @ 0x005c91e0 ====

void FUN_005c91e0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x32) == '\0') {
    (**(code **)(*DAT_00b5a728 + 8))(*(undefined4 *)(in_ECX + 0x2c));
  }
  if (*(int *)(in_ECX + 0x2c) == 0x12) {
    (**(code **)(*DAT_00b5afac + 8))(0x12,1);
  }
  else {
    (**(code **)(*DAT_00b5afac + 8))(*(int *)(in_ECX + 0x2c),0);
  }
  (**(code **)(*DAT_00b5afc8 + 0x34))(*(undefined4 *)(in_ECX + 0x2c));
  (**(code **)(*DAT_00b5b010 + 0x18))(*(undefined4 *)(in_ECX + 0x58));
  *(undefined4 *)(in_ECX + 0x58) = 0;
  return;
}


// ==== FUN_005c9240 @ 0x005c9240 ====

undefined4 FUN_005c9240(undefined **param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x2c);
  iVar2 = (**(code **)((int)*param_1 + 0x10))();
  if (iVar2 == iVar1) {
    param_1 = &PTR_FUN_009c2ed0;
    (**(code **)(**(int **)(in_ECX + 0x34) + 4))(&param_1);
    return 1;
  }
  return 0;
}


// ==== FUN_005c9280 @ 0x005c9280 ====

bool FUN_005c9280(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  undefined4 unaff_retaddr;
  undefined1 auStack_18 [2];
  undefined1 auStack_16 [6];
  undefined1 auStack_10 [16];
  
  if (*(int *)(in_ECX + 0x24) == 0x12) {
    return true;
  }
  cVar1 = (**(code **)(**(int **)(in_ECX + 0x2c) + 0x60))();
  if (cVar1 == '\0') {
    (**(code **)(**(int **)(in_ECX + 0x2c) + 0x10))(auStack_18);
    iVar2 = FUN_0040f630(auStack_18 + -4,auStack_10,unaff_retaddr);
    return iVar2 != 1;
  }
  return false;
}


// ==== FUN_005c92e0 @ 0x005c92e0 ====

void FUN_005c92e0(undefined4 param_1)

{
  int in_ECX;
  undefined1 *puStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined1 local_18 [4];
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_8;
  
  puStack_2c = local_18;
  (**(code **)(**(int **)(in_ECX + 0x2c) + 0x10))();
  uStack_24 = uStack_1c;
  uStack_20 = uStack_14;
  puStack_2c = puStack_10;
  uStack_28 = uStack_8;
  FUN_004a8890(&uStack_24,&puStack_2c,param_1);
  return;
}


// ==== FUN_005c9340 @ 0x005c9340 ====

void FUN_005c9340(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2f14;
  in_ECX[2] = &PTR_FUN_009c2efc;
  in_ECX[10] = &PTR_FUN_009c2edc;
  FUN_005c91e0();
  if ((undefined4 *)in_ECX[0xd] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xd])(1);
  }
  in_ECX[0xd] = 0;
  if ((void *)in_ECX[0x13] == (void *)0x0) {
    in_ECX[0x13] = 0;
    in_ECX[0x14] = 0;
    in_ECX[0x15] = 0;
    in_ECX[10] = &PTR_FUN_009c2eb0;
    in_ECX[2] = &PTR_FUN_009bf514;
    *in_ECX = &PTR_FUN_009c2e74;
    return;
  }
  _free((void *)in_ECX[0x13]);
  return;
}


// ==== FUN_005c93a0 @ 0x005c93a0 ====

void FUN_005c93a0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  undefined1 *_Memory;
  undefined1 local_1c [4];
  undefined1 local_18;
  uint uStack_10;
  undefined4 local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_weaponline_009c2cb8,10);
  _Memory = local_1c;
  (**(code **)(**(int **)(in_ECX + 0x34) + 100))(param_1,param_2);
  if (uStack_10 < 0x10) {
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_005c9400 @ 0x005c9400 ====

int FUN_005c9400(int param_1,int param_2)

{
  int extraout_EAX;
  undefined *puVar1;
  undefined4 uVar2;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (param_2 < 0x407) {
    if (param_2 == 0x406) {
      uVar2 = 4;
      puVar1 = &DAT_009c2cec;
      goto LAB_005c9593;
    }
    if (param_2 < 0x402) {
      if (param_2 == 0x401) {
        FUN_00401830(s_sword_009c2cd0);
        return param_1;
      }
      if (param_2 == -1) {
        FUN_00401830(s_magic_009c2d10);
        return param_1;
      }
      if (param_2 == 0x400) {
        FUN_00401830(s_short_sword_009c2cc4);
        return param_1;
      }
    }
    else {
      if (param_2 == 0x402) {
        FUN_00401830(s_long_sword_009c2cd8);
        return param_1;
      }
      if (param_2 == 0x404) {
        FUN_00401830(s_spear_009c2ce4);
        return param_1;
      }
    }
  }
  else {
    switch(param_2) {
    case 0x408:
      FUN_00401830(&PTR_LAB_009c2cf4);
      return param_1;
    case 0x40a:
      FUN_00401830(&PTR_LAB_00776f60_2_009c2d00);
      return param_1;
    case 0x40b:
      FUN_00401830(s_cross_bow_009c2d04);
      return param_1;
    case 0x40d:
      FUN_00401830(&DAT_009c2cf8);
      return param_1;
    }
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_Invalid_weapon_class_009c2d18,0x14);
  FUN_00796d20(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  uVar2 = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  puVar1 = &DAT_009c2d2d;
LAB_005c9593:
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401740(puVar1,uVar2);
  return param_1;
}


// ==== FUN_005c95d0 @ 0x005c95d0 ====

int FUN_005c95d0(int param_1,undefined1 param_2)

{
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  switch(param_2) {
  case 1:
    FUN_00401830(s_twolimbs_009c2d30);
    return param_1;
  case 2:
    FUN_00401830(s_fourlimbs_009c2d3c);
    return param_1;
  case 3:
    FUN_00401830(s_insect_009c2d48);
    return param_1;
  case 4:
    FUN_00401830(&DAT_009c2d50);
    return param_1;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_Invalid_Monster_Type_009c2d58,0x14);
  FUN_00796d20(local_1c);
  if (local_4 < 0x10) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(s_twolimbs_009c2d70,8);
    return param_1;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_005c96d0 @ 0x005c96d0 ====

int FUN_005c96d0(int param_1,undefined4 param_2)

{
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  switch(param_2) {
  case 0:
    FUN_00401830(s_right_left_009c2d8c);
    return param_1;
  case 1:
    FUN_00401830(s_left_right_009c2dc0);
    return param_1;
  case 2:
    FUN_00401830(s_up_down_009c2d7c);
    return param_1;
  case 3:
    FUN_00401830(s_down_up_009c2d84);
    return param_1;
  case 4:
    FUN_00401830(s_upright_downleft_009c2d98);
    return param_1;
  case 5:
    FUN_00401830(s_downright_upleft_009c2dac);
    return param_1;
  case 6:
    FUN_00401830(s_upleft_downright_009c2dcc);
    return param_1;
  case 7:
    FUN_00401830(s_downleft_upright_009c2de0);
    return param_1;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_Invalid_Attack_Dir_009c2df4,0x12);
  FUN_00796d20(local_1c);
  if (local_4 < 0x10) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(&DAT_009c2e07,0);
    return param_1;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_005c9840 @ 0x005c9840 ====

int FUN_005c9840(int param_1,int param_2)

{
  int extraout_EAX;
  char *pcVar1;
  undefined4 uVar2;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (param_2 == 0) {
    uVar2 = 6;
    pcVar1 = s_strike_009c2e0c;
  }
  else if (param_2 == 1) {
    uVar2 = 3;
    pcVar1 = &DAT_009c2e08;
  }
  else {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_Invalid_Attack_Type_009c2e14,0x13);
    FUN_00796d20(local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return extraout_EAX;
    }
    uVar2 = 0;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    pcVar1 = &DAT_009c2e28;
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401740(pcVar1,uVar2);
  return param_1;
}


// ==== FUN_005c98e0 @ 0x005c98e0 ====

int FUN_005c98e0(int param_1,int param_2)

{
  int extraout_EAX;
  char *pcVar1;
  undefined4 uVar2;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (param_2 == 0) {
    uVar2 = 0xd;
    pcVar1 = s_normal_finish_009c2e2c;
  }
  else if (param_2 == 1) {
    uVar2 = 10;
    pcVar1 = s_big_finish_009c2e3c;
  }
  else if (param_2 == 2) {
    uVar2 = 0xf;
    pcVar1 = s_enormous_finish_009c2e48;
  }
  else {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_Invalid_Finish_Type_009c2e58,0x13);
    FUN_00796d20(local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return extraout_EAX;
    }
    uVar2 = 0;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    pcVar1 = &DAT_009c2e6c;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401740(pcVar1,uVar2);
  return param_1;
}


// ==== FUN_005c9990 @ 0x005c9990 ====

/* WARNING: Removing unreachable block (ram,0x005c9f0e) */
/* WARNING: Removing unreachable block (ram,0x005c9b3b) */
/* WARNING: Removing unreachable block (ram,0x005c9ad4) */
/* WARNING: Removing unreachable block (ram,0x005c9d0d) */
/* WARNING: Removing unreachable block (ram,0x005c9a7e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005c9990(int param_1)

{
  code *pcVar1;
  double dVar2;
  char cVar3;
  void *pvVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  char *pcVar9;
  int in_ECX;
  char *pcVar10;
  float10 fVar11;
  undefined1 auStack_184 [4];
  void *pvStack_180;
  uint uStack_16c;
  int iStack_168;
  int iStack_164;
  int local_160;
  undefined1 auStack_15c [4];
  void *pvStack_158;
  undefined4 uStack_148;
  uint uStack_144;
  int iStack_140;
  float fStack_13c;
  float fStack_138;
  void *pvStack_130;
  undefined4 uStack_120;
  uint uStack_11c;
  undefined1 auStack_118 [32];
  void *pvStack_f8;
  undefined4 uStack_e8;
  uint uStack_e4;
  undefined1 auStack_1c [28];
  
  local_160 = in_ECX;
  pvVar4 = operator_new(0xf4);
  if (pvVar4 == (void *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    puVar5 = (undefined4 *)FUN_005d3f90();
  }
  cVar3 = FUN_005d4280(*(undefined4 *)(in_ECX + 0x2c),*(undefined4 *)(in_ECX + 0x34),param_1 + 4,
                       param_1 + 0x20,param_1 + 0x3c,*(undefined1 *)(in_ECX + 0x41));
  if (cVar3 == '\0') {
    if (puVar5 != (undefined4 *)0x0) {
      (**(code **)*puVar5)();
      return;
    }
  }
  else {
    iVar6 = (**(code **)(*DAT_00b5afb8 + 0x14))();
    uVar7 = (**(code **)(*DAT_00b5a6bc + 8))();
    if (*(uint *)(iVar6 + 0x54) < 0x10) {
      iVar8 = iVar6 + 0x40;
    }
    else {
      iVar8 = *(int *)(iVar6 + 0x40);
    }
    iVar6 = FUN_007bb860(uVar7,iVar8,*(undefined4 *)(iVar6 + 0x50));
    if (iVar6 != 0) {
      FUN_00401740(s_res____0_009c28d0,8);
      FUN_00406880();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    iVar6 = FUN_007bca30(uVar7,0,0);
    if (iVar6 != 0) {
      FUN_00401740(s_res____0_009c28dc,8);
      FUN_00406880();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_007bc470(uVar7);
    FUN_007bc620(uVar7,0xffffd8ef);
    iVar6 = FUN_007bbfa0(uVar7,0xffffffff);
    if (iVar6 != 6) {
      FUN_00401740(s_lua_isfunction__pLuaState___1___009c28f4,0x1f);
      FUN_00406880();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_005c96d0(auStack_184);
    FUN_007bc470(uVar7);
    if (0xf < uStack_16c) {
      _free(pvStack_180);
      return;
    }
    FUN_005c9840(auStack_184);
    FUN_007bc470(uVar7);
    if (0xf < uStack_16c) {
      _free(pvStack_180);
      return;
    }
    dVar2 = (double)*(int *)(param_1 + 0x50);
    if (*(int *)(param_1 + 0x50) < 0) {
      dVar2 = dVar2 + _DAT_009c2f50;
    }
    FUN_007bc400(uVar7,dVar2);
    FUN_005c98e0(auStack_184,*(undefined4 *)(param_1 + 0x4c));
    FUN_007bc470(uVar7);
    if (0xf < uStack_16c) {
      _free(pvStack_180);
      return;
    }
    dVar2 = (double)*(int *)(param_1 + 0x54);
    if (*(int *)(param_1 + 0x54) < 0) {
      dVar2 = dVar2 + _DAT_009c2f50;
    }
    FUN_007bc400(uVar7,dVar2);
    FUN_005c9400(auStack_184,*(undefined4 *)(param_1 + 0x58));
    FUN_007bc470(uVar7);
    iVar6 = local_160;
    if (0xf < uStack_16c) {
      _free(pvStack_180);
      return;
    }
    FUN_005c95d0(auStack_184);
    FUN_007bc470(uVar7);
    if (0xf < uStack_16c) {
      _free(pvStack_180);
      return;
    }
    iVar8 = FUN_007bca30(uVar7,7,1);
    if (iVar8 != 0) {
      pcVar9 = (char *)FUN_007bc230();
      pcVar10 = pcVar9;
      do {
        cVar3 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar3 != '\0');
      FUN_00401740(pcVar9,(int)pcVar10 - (int)(pcVar9 + 1));
      FUN_00796d20();
      FUN_007bbdf0(uVar7,0xfffffffe);
      puVar5[0x30] = 0;
      (**(code **)*puVar5)();
      return;
    }
    iVar8 = FUN_007bbfa0(uVar7);
    if (iVar8 != 5) {
      FUN_00401830();
      FUN_00406880();
      if (uStack_16c < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_180);
      return;
    }
    FUN_007bc470(uVar7);
    FUN_007bc620(uVar7,0xfffffffe);
    iVar8 = FUN_007bc030(uVar7,0xffffffff);
    if (iVar8 == 0) {
      FUN_00401830();
      FUN_00406880();
      if (uStack_16c < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_180);
      return;
    }
    fVar11 = (float10)FUN_007bc1a0(uVar7,0xffffffff);
    FUN_007bbdf0(uVar7,0xfffffffe);
    iStack_168 = 1;
    if (0 < (int)ROUND(fVar11)) {
      do {
        FUN_007bc400(uVar7,(double)iStack_168);
        FUN_007bc620(uVar7,0xfffffffe);
        iVar6 = FUN_007bbfa0(uVar7,0xffffffff);
        if (iVar6 == 5) {
          FUN_007bc470(uVar7);
          FUN_007bc620(uVar7,0xfffffffe);
          iVar6 = FUN_007bc080(uVar7,0xffffffff);
          if (iVar6 == 0) {
            FUN_00401740(s___Doll_Human_HumanImpl_cpp_331____009c29c8,0x47);
            FUN_00796d50();
          }
          else {
            pcVar9 = (char *)FUN_007bc230(uVar7);
            uStack_144 = 0xf;
            uStack_148 = 0;
            pvStack_158 = (void *)((uint)pvStack_158 & 0xffffff00);
            pcVar10 = pcVar9;
            do {
              cVar3 = *pcVar10;
              pcVar10 = pcVar10 + 1;
            } while (cVar3 != '\0');
            FUN_00401740(pcVar9,(int)pcVar10 - (int)(pcVar9 + 1));
            FUN_007bbdf0(uVar7);
            FUN_007bc470(uVar7,s_direction_009c2a10);
            FUN_007bc620(uVar7,0xfffffffe);
            iVar6 = FUN_007bc030(uVar7,0xffffffff);
            if (iVar6 != 0) {
              fVar11 = (float10)FUN_007bc1a0(uVar7,0xffffffff);
              iStack_164 = (int)ROUND(fVar11);
              FUN_007bbdf0(uVar7,0xfffffffe);
              FUN_007bc470(uVar7,s_length_009c2a68);
              FUN_007bc620(uVar7,0xfffffffe);
              iVar6 = FUN_007bc030(uVar7,0xffffffff);
              if (iVar6 == 0) {
                FUN_00401830();
                FUN_00796d50();
              }
              else {
                fVar11 = (float10)FUN_007bc1a0(uVar7,0xffffffff);
                fStack_138 = (float)fVar11;
                FUN_007bbdf0(uVar7,0xfffffffe);
                FUN_007bc470(uVar7,s_height_009c2ab8);
                FUN_007bc620(uVar7,0xfffffffe);
                iVar6 = FUN_007bc030(uVar7,0xffffffff);
                if (iVar6 == 0) {
                  FUN_00401830();
                  FUN_00796d50();
                }
                else {
                  fVar11 = (float10)FUN_007bc1a0(uVar7,0xffffffff);
                  fStack_13c = (float)fVar11;
                  FUN_007bbdf0(uVar7,0xfffffffe);
                  FUN_007bc470(uVar7,s_rotate_axis_009c2b08);
                  FUN_007bc620(uVar7,0xfffffffe);
                  iVar6 = FUN_007bc080(uVar7,0xffffffff);
                  if (iVar6 != 0) {
                    FUN_007bc230(uVar7,0xffffffff);
                    FUN_00401830();
                    FUN_007bbdf0(uVar7,0xfffffffe);
                    FUN_007bc470(uVar7,s_rotate_speed_009c2b60);
                    FUN_007bc620(uVar7,0xfffffffe);
                    iVar6 = FUN_007bc030(uVar7,0xffffffff);
                    if (iVar6 == 0) {
                      FUN_00401830();
                      FUN_00796d50();
                    }
                    else {
                      fVar11 = (float10)FUN_007bc1a0(uVar7,0xffffffff);
                      iStack_140 = (int)ROUND(fVar11);
                      FUN_007bbdf0(uVar7,0xfffffffe);
                      FUN_007bc470(uVar7,s_rotate_point_009c2bb8);
                      FUN_007bc620(uVar7,0xfffffffe);
                      iVar6 = FUN_007bc080(uVar7,0xffffffff);
                      if (iVar6 != 0) {
                        FUN_007bc230(uVar7,0xffffffff);
                        FUN_00401830();
                        FUN_007bbdf0(uVar7,0xfffffffe);
                        FUN_007bc470(uVar7,s_speed_009c2c10);
                        FUN_007bc620(uVar7,0xfffffffe);
                        iVar6 = FUN_007bc030(uVar7,0xffffffff);
                        if (iVar6 == 0) {
                          FUN_00401830();
                          FUN_00796d50();
                        }
                        else {
                          fVar11 = (float10)FUN_007bc1a0(uVar7,0xffffffff);
                          FUN_007bbdf0(uVar7,0xfffffffe);
                          FUN_007bc470(uVar7,s_property_009c2c60);
                          FUN_007bc620(uVar7,0xfffffffe);
                          iVar6 = FUN_007bc080(uVar7,0xffffffff);
                          if (iVar6 == 0) {
                            FUN_00401830();
                            FUN_00796d50();
                          }
                          else {
                            FUN_007bc230(uVar7,0xffffffff);
                            FUN_00401830();
                            FUN_007bbdf0(uVar7,0xfffffffe);
                            FUN_005d3b30(auStack_15c,iStack_164,fStack_138,fStack_13c,auStack_118,
                                         iStack_140,auStack_184,(float)fVar11,auStack_1c);
                            FUN_007bbdf0(uVar7,0xfffffffe);
                          }
                        }
                    /* WARNING: Subroutine does not return */
                        FUN_00446f10();
                      }
                      FUN_00401830();
                      FUN_00796d50();
                    }
                    /* WARNING: Subroutine does not return */
                    FUN_00446f10();
                  }
                  FUN_00401830();
                  FUN_00796d50();
                }
              }
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            FUN_00401830();
            FUN_00796d50();
            if (0xf < uStack_e4) {
              _free(pvStack_f8);
              return;
            }
            uStack_e4 = 0xf;
            uStack_e8 = 0;
            pvStack_f8 = (void *)((uint)pvStack_f8 & 0xffffff00);
            if (0xf < uStack_144) {
              _free(pvStack_158);
              return;
            }
            uStack_144 = 0xf;
            uStack_148 = 0;
            pvStack_158 = (void *)((uint)pvStack_158 & 0xffffff00);
          }
        }
        else {
          uStack_11c = 0xf;
          uStack_120 = 0;
          pvStack_130 = (void *)((uint)pvStack_130 & 0xffffff00);
          FUN_00401740(s___Doll_Human_HumanImpl_cpp_327____009c2970,0x46);
          FUN_00796d50();
          if (0xf < uStack_11c) {
            _free(pvStack_130);
            return;
          }
          uStack_11c = 0xf;
          uStack_120 = 0;
          pvStack_130 = (void *)((uint)pvStack_130 & 0xffffff00);
        }
        iStack_168 = iStack_168 + 1;
      } while (iStack_168 <= (int)ROUND(fVar11));
      iVar6 = local_160;
    }
    FUN_007bbdf0(uVar7,0xfffffffe);
    *(undefined4 **)(iVar6 + 0x34) = puVar5;
    puVar5[0x3b] = *(undefined4 *)(iVar6 + 0x44);
  }
  return;
}


// ==== FUN_005ca3f0 @ 0x005ca3f0 ====

void FUN_005ca3f0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = DAT_0099d080;
  in_ECX[2] = &PTR_FUN_009bf514;
  in_ECX[10] = &PTR_FUN_009c2eb0;
  in_ECX[0xd] = param_1;
  *in_ECX = &PTR_FUN_009c2f14;
  in_ECX[2] = &PTR_FUN_009c2efc;
  in_ECX[10] = &PTR_FUN_009c2edc;
  in_ECX[0xb] = 0xffffffff;
  *(undefined1 *)(in_ECX + 0xc) = 1;
  *(undefined1 *)((int)in_ECX + 0x32) = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  in_ECX[0xf] = 0;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  *(undefined1 *)((int)in_ECX + 0x41) = 0;
  *(undefined1 *)((int)in_ECX + 0x42) = 0;
  in_ECX[0x11] = uVar1;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  *(undefined1 *)(in_ECX + 9) = 1;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_005ca460 @ 0x005ca460 ====

undefined4 FUN_005ca460(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined4 *puVar5;
  
  iVar4 = *(int *)(in_ECX + 0x2c);
  iVar3 = (**(code **)(*param_1 + 0x10))();
  if (iVar3 != iVar4) {
    return 0;
  }
  puVar1 = (undefined4 *)param_1[4];
  for (puVar5 = (undefined4 *)param_1[3]; puVar5 != puVar1; puVar5 = puVar5 + 1) {
    piVar2 = (int *)*puVar5;
    iVar4 = (**(code **)(*piVar2 + 4))();
    if ((iVar4 == 0x60) && (*(char *)(in_ECX + 0x40) == '\0')) {
      FUN_005c9990(piVar2);
      *(undefined1 *)(in_ECX + 0x40) = 1;
    }
    else {
      (**(code **)(**(int **)(in_ECX + 0x34) + 4))(piVar2);
    }
  }
  return 1;
}


// ==== FUN_005ca4d0 @ 0x005ca4d0 ====

void FUN_005ca4d0(void)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int in_ECX;
  void *unaff_ESI;
  uint uVar4;
  int *piStack_14;
  int aiStack_10 [4];
  
  if (*(int *)(in_ECX + 0x2c) != 0x12) {
    if (*(int *)(in_ECX + 0x4c) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(int *)(in_ECX + 0x50) - *(int *)(in_ECX + 0x4c) >> 2;
    }
    iVar1 = (**(code **)(*DAT_00b5afb4 + 0x10))();
    aiStack_10[1] = 0;
    aiStack_10[2] = 0;
    aiStack_10[3] = 0;
    (**(code **)(*(int *)(in_ECX + 8) + 8))(*(undefined4 *)(iVar1 + 0x34),aiStack_10);
    if (piStack_14 == (int *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = aiStack_10[0] - (int)piStack_14 >> 2;
    }
    if (uVar4 == uVar2) {
      uVar2 = 0;
      if (uVar4 != 0) {
        piVar3 = piStack_14;
        do {
          if (*(int *)((int)piVar3 + (*(int *)(in_ECX + 0x4c) - (int)piStack_14)) != *piVar3) break;
          uVar2 = uVar2 + 1;
          piVar3 = piVar3 + 1;
        } while (uVar2 < uVar4);
      }
      if (uVar2 == uVar4) {
        if (piStack_14 == (int *)0x0) {
          return;
        }
        _free(piStack_14);
        return;
      }
    }
    FUN_00430ad0(aiStack_10 + -2);
    (**(code **)(*DAT_00b5afac + 4))(*(undefined4 *)(in_ECX + 0x2c),in_ECX + 8,0);
    if (unaff_ESI != (void *)0x0) {
      _free(unaff_ESI);
      return;
    }
  }
  return;
}


// ==== FUN_005ca5c0 @ 0x005ca5c0 ====

uint FUN_005ca5c0(int *param_1)

{
  code *pcVar1;
  char cVar2;
  uint extraout_EAX;
  uint uVar3;
  int iVar4;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x34) != 0) {
    uVar3 = (**(code **)(*param_1 + 4))();
    if (uVar3 < 0x60060013) {
      if (uVar3 == 0x60060012) {
        iVar4 = (**(code **)(*param_1 + 0x10))();
        return (uint)(iVar4 == *(int *)(in_ECX + 0x2c));
      }
      if (uVar3 == 0x40001) {
        FUN_005ca4d0();
      }
      else if (uVar3 == 0x60060010) {
        cVar2 = FUN_005c8f00(param_1);
        if (cVar2 != '\0') {
          return 1;
        }
      }
      else if (uVar3 == 0x60060011) {
        cVar2 = FUN_005c8f40(param_1);
        if (cVar2 != '\0') {
          return 1;
        }
      }
    }
    else if (uVar3 == 0x60060013) {
      cVar2 = FUN_005ca460(param_1);
      if (cVar2 != '\0') {
        return 1;
      }
    }
    else if (uVar3 == 0x60060030) {
      uVar3 = FUN_005c9240(param_1);
      return uVar3;
    }
    uVar3 = (**(code **)(**(int **)(in_ECX + 0x34) + 0x4c))(param_1);
    return uVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_m_pMainBody____NULL_009c28b4,0x13);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_005ca6d0 @ 0x005ca6d0 ====

undefined4 FUN_005ca6d0(void)

{
  return 0x61;
}


// ==== FUN_005ca6e0 @ 0x005ca6e0 ====

void FUN_005ca6e0(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}


// ==== FUN_005ca6f0 @ 0x005ca6f0 ====

void FUN_005ca6f0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0099d080;
  *param_1 = DAT_0099d080;
  param_1[1] = uVar1;
  return;
}


// ==== FUN_005ca710 @ 0x005ca710 ====

void FUN_005ca710(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x3c);
  return;
}


// ==== FUN_005ca720 @ 0x005ca720 ====

undefined4 FUN_005ca720(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x34) + 0x38))(param_1);
  return param_1;
}


// ==== FUN_005ca740 @ 0x005ca740 ====

void FUN_005ca740(void)

{
  FUN_005ca780();
  return;
}


// ==== FUN_005ca750 @ 0x005ca750 ====

void FUN_005ca750(void)

{
  FUN_005ca780();
  return;
}


// ==== FUN_005ca760 @ 0x005ca760 ====

void FUN_005ca760(void)

{
  FUN_005c9080();
  return;
}


// ==== FUN_005ca770 @ 0x005ca770 ====

undefined4 FUN_005ca770(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x2c);
}


// ==== FUN_005ca780 @ 0x005ca780 ====

void FUN_005ca780(byte param_1)

{
  void *in_ECX;
  
  FUN_005c9340();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ca7a0 @ 0x005ca7a0 ====

undefined4 FUN_005ca7a0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x3c);
}


// ==== FUN_005ca7b0 @ 0x005ca7b0 ====

void FUN_005ca7b0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x30) = param_1;
  return;
}


// ==== FUN_005ca7c0 @ 0x005ca7c0 ====

void FUN_005ca7c0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x38) = param_1;
  return;
}


// ==== FUN_005ca810 @ 0x005ca810 ====

void FUN_005ca810(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5affc + 4))(param_1,param_2);
  *(undefined4 *)(in_ECX + 4) = uVar1;
  uVar1 = (**(code **)(*DAT_00b5aff4 + 4))();
  *(undefined4 *)(in_ECX + 0x3c) = uVar1;
  if (*(int **)(in_ECX + 4) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x14))(uVar1);
    *(char *)(in_ECX + 0x35) = (char)param_2;
  }
  return;
}


// ==== FUN_005ca850 @ 0x005ca850 ====

void FUN_005ca850(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  undefined4 unaff_retaddr;
  
  if (*(int **)(in_ECX + 0x3c) == (int *)0x0) {
    uVar1 = (**(code **)(*DAT_00b5aff4 + 4))();
    *(undefined4 *)(in_ECX + 0x3c) = uVar1;
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0x3c) + 0x10))();
  }
  (**(code **)(*DAT_00b5affc + 8))(*(undefined4 *)(in_ECX + 4));
  piVar2 = (int *)(**(code **)(*DAT_00b5affc + 4))(unaff_retaddr,0);
  *(int **)(in_ECX + 4) = piVar2;
  if (piVar2 == (int *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x005ca8a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar2 + 0x14))(*(undefined4 *)(in_ECX + 0x3c));
  return;
}


// ==== FUN_005ca8b0 @ 0x005ca8b0 ====

void FUN_005ca8b0(float param_1,float param_2,undefined4 param_3)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  float fVar4;
  float fVar5;
  undefined4 local_10;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return;
  }
  local_10 = *(undefined4 *)(in_ECX + 0x24);
  local_4 = *(undefined4 *)(in_ECX + 0x30);
  local_c = DAT_0099d080;
  if (param_1 <= DAT_0099d080) {
    local_c = param_1;
  }
  param_2 = *(float *)(in_ECX + 0x2c) + param_2;
  local_8 = DAT_0099d080;
  if (param_2 <= DAT_0099d080) {
    local_8 = param_2;
  }
  fVar4 = *(float *)(in_ECX + 0x28) - local_c;
  if (fVar4 <= 0.0) {
    fVar5 = 0.0 - fVar4;
  }
  else {
    fVar5 = fVar4;
  }
  if ((fVar5 < DAT_009c2f5c) && (*(float *)(in_ECX + 0x2c) == local_8)) {
    return;
  }
  fVar5 = DAT_009c2f5c;
  if ((*(byte *)(in_ECX + 0x30) != 0) && (fVar5 = DAT_009a09b8, *(byte *)(in_ECX + 0x30) < 2)) {
    fVar5 = DAT_0099e170;
  }
  if (fVar4 <= 0.0) {
    fVar4 = 0.0 - fVar4;
  }
  if (fVar4 < fVar5) {
    return;
  }
  if ((*(char *)(in_ECX + 0x35) == '\0') ||
     (iVar3 = (**(code **)(*DAT_00b5af48 + 8))(), *(char *)(iVar3 + 1) == '\0')) {
    *(undefined1 *)(in_ECX + 0x30) = 0;
  }
  uVar1 = *(undefined1 *)(in_ECX + 0x30);
  cVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x18))(&local_10,*(undefined4 *)(in_ECX + 0x3c));
  if (cVar2 == '\x01') {
    *(uint *)(in_ECX + 0x28) = CONCAT31((int3)((uint)param_3 >> 8),uVar1);
    *(undefined4 *)(in_ECX + 0x2c) = param_3;
  }
  return;
}


// ==== FUN_005ca9e0 @ 0x005ca9e0 ====

undefined4 FUN_005ca9e0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *unaff_retaddr;
  
  if ((*(int *)(in_ECX + 4) != 0) && (*(int *)(in_ECX + 0x3c) != 0)) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x1c))(param_1);
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x3c) + 0xc))(uVar1);
    if (iVar2 != 0) {
      puVar4 = (undefined4 *)(iVar2 + 0xa0);
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *unaff_retaddr = *puVar4;
        puVar4 = puVar4 + 1;
        unaff_retaddr = unaff_retaddr + 1;
      }
      return 1;
    }
  }
  return 0;
}


// ==== FUN_005caa30 @ 0x005caa30 ====

void FUN_005caa30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2f64;
  in_ECX[1] = 0;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  *(undefined1 *)(in_ECX + 0xd) = 0;
  *(undefined1 *)((int)in_ECX + 0x35) = 0;
  in_ECX[0xf] = 0;
  in_ECX[9] = 0xffffffff;
  in_ECX[0xb] = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  in_ECX[10] = 0;
  return;
}


// ==== FUN_005caa70 @ 0x005caa70 ====

void FUN_005caa70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2f64;
  if ((int *)in_ECX[1] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[1] + 0x10))(in_ECX + 2);
  }
  (**(code **)(*DAT_00b5affc + 8))(in_ECX[1]);
  (**(code **)(*DAT_00b5aff4 + 8))(in_ECX[0xf]);
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_005caad0 @ 0x005caad0 ====

void FUN_005caad0(void)

{
  undefined4 uVar1;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  if (*(int *)(in_ECX + 4) != 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = 0;
    FUN_00401740(&DAT_009c2f5a,0);
    uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0xc))(&local_1c);
    *(undefined4 *)(in_ECX + 0x24) = uVar1;
    if (0xf < local_8) {
      _free(local_1c);
      return;
    }
    FUN_00401740(&DAT_009c2f5b,0);
    *(undefined1 *)(in_ECX + 0x34) = 1;
  }
  return;
}


// ==== FUN_005cab40 @ 0x005cab40 ====

void FUN_005cab40(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return;
  }
  if (*(int *)(in_ECX + 0x24) != -1) {
    cVar1 = (**(code **)(*DAT_00b5a7e4 + 0xc))(param_1,in_ECX + 8);
    if (cVar1 != '\0') goto LAB_005caba9;
    if (*(int *)(in_ECX + 0x24) != -1) {
      (**(code **)(**(int **)(in_ECX + 4) + 0x10))(in_ECX + 8);
    }
  }
  uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0xc))(param_1);
  *(undefined4 *)(in_ECX + 0x24) = uVar2;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
LAB_005caba9:
  if (*(char *)(in_ECX + 0x34) == '\0') {
    *(undefined4 *)(in_ECX + 0x2c) = 0;
    return;
  }
  FUN_005ca8b0(0,0x3f800000,0);
  *(undefined1 *)(in_ECX + 0x34) = 0;
  return;
}


// ==== FUN_005cabe0 @ 0x005cabe0 ====

void FUN_005cabe0(byte param_1)

{
  void *in_ECX;
  
  FUN_005caa70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005cac00 @ 0x005cac00 ====

void FUN_005cac00(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x78) = param_1;
  *(undefined4 *)(in_ECX + 0x7c) = param_2;
  return;
}


// ==== FUN_005cac20 @ 0x005cac20 ====

void FUN_005cac20(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x8c) = param_1;
  return;
}


// ==== FUN_005cac30 @ 0x005cac30 ====

undefined4 FUN_005cac30(void)

{
  char cVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x90) == '\x01') {
    return 1;
  }
  if ((((*(int **)(in_ECX + 0x80) == (int *)0x0) || (*(int *)(in_ECX + 0x84) == 0)) ||
      (cVar1 = (**(code **)(**(int **)(in_ECX + 0x80) + 0x2c))(), cVar1 == '\0')) ||
     (cVar1 = (**(code **)(**(int **)(in_ECX + 0x84) + 0x2c))(), cVar1 == '\0')) {
    return 0;
  }
  *(undefined1 *)(in_ECX + 0x90) = 1;
  return 1;
}


// ==== FUN_005cac80 @ 0x005cac80 ====

void FUN_005cac80(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x88) != 0) {
    FUN_005ca8b0(param_1,0x3f800000,0);
    uVar1 = FUN_005ca7a0();
    *(undefined4 *)(in_ECX + 0x94) = uVar1;
  }
  return;
}


// ==== FUN_005cacc0 @ 0x005cacc0 ====

void FUN_005cacc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2f6c;
  if (in_ECX[0x20] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x20]);
    in_ECX[0x20] = 0;
  }
  if (in_ECX[0x21] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x21]);
    in_ECX[0x21] = 0;
  }
  if ((undefined4 *)in_ECX[0x22] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x22])(1);
  }
  in_ECX[0x22] = 0;
  FUN_005b1b00();
  return;
}


// ==== FUN_005cad30 @ 0x005cad30 ====

void FUN_005cad30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2f6c;
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  in_ECX[0x16] = 0xf;
  in_ECX[0x15] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  in_ECX[0x1d] = 0xf;
  in_ECX[0x1c] = 0;
  *(undefined1 *)(in_ECX + 0x18) = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 3;
  in_ECX[0x25] = 0;
  return;
}


// ==== FUN_005cad90 @ 0x005cad90 ====

undefined4 FUN_005cad90(int param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  
  FUN_005cb110(param_1);
  uVar3 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x78) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x7c) = uVar3;
  *(undefined1 *)(in_ECX + 0x90) = 0;
  iVar1 = FUN_005b1c00(param_1 + 4);
  *(int *)(in_ECX + 0x80) = iVar1;
  if (iVar1 != 0) {
    iVar1 = FUN_005aa220(param_1 + 0x20);
    *(int *)(in_ECX + 0x84) = iVar1;
    if (iVar1 != 0) {
      if ((*(int *)(param_1 + 0x50) != 0) && (*(int *)(param_1 + 0x6c) != 0)) {
        pvVar2 = operator_new(0x40);
        if (pvVar2 == (void *)0x0) {
          uVar3 = 0;
        }
        else {
          uVar3 = FUN_005caa30();
        }
        *(undefined4 *)(in_ECX + 0x88) = uVar3;
        FUN_005ca810(param_1 + 0x3c,0);
        FUN_005cab40(param_1 + 0x58);
      }
      return 1;
    }
  }
  return 0;
}


// ==== FUN_005cae40 @ 0x005cae40 ====

void FUN_005cae40(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  char cVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  if (*(char *)(in_ECX + 0x90) != '\x01') {
    if (*(int **)(in_ECX + 0x80) == (int *)0x0) {
      return;
    }
    if (*(int *)(in_ECX + 0x84) == 0) {
      return;
    }
    cVar2 = (**(code **)(**(int **)(in_ECX + 0x80) + 0x2c))();
    if (cVar2 == '\0') {
      return;
    }
    cVar2 = (**(code **)(**(int **)(in_ECX + 0x84) + 0x2c))();
    if (cVar2 == '\0') {
      return;
    }
    *(undefined1 *)(in_ECX + 0x90) = 1;
  }
  iVar4 = *(int *)(in_ECX + 0x88);
  *(undefined4 *)(param_3 + 0x30) = DAT_0099d080;
  uVar1 = DAT_009bac80;
  *(bool *)(param_3 + 0x24) = iVar4 == 0;
  *(undefined1 *)(param_3 + 0x21) = 0xc;
  *(undefined1 *)(param_3 + 0x20) = 0;
  *(undefined1 *)(param_3 + 0x23) = 0;
  *(undefined1 *)(param_3 + 0x26) = 0;
  *(undefined4 *)(param_3 + 0x28) = uVar1;
  if (*(int *)(param_3 + 0x40) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = (*(int *)(param_3 + 0x44) - *(int *)(param_3 + 0x40)) / 0x58;
  }
  FUN_005c4ae0(iVar4 + 1,0);
  iVar4 = *(int *)(param_3 + 0x44);
  *(undefined4 *)(iVar4 + -0x14) = *(undefined4 *)(in_ECX + 0x8c);
  puVar5 = (undefined4 *)(iVar4 + -0x54);
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *param_1;
    param_1 = param_1 + 1;
    puVar5 = puVar5 + 1;
  }
  if (*(int *)(in_ECX + 0x88) == 0) {
    *(undefined4 *)(iVar4 + -0x58) = 0;
  }
  else {
    *(undefined4 *)(iVar4 + -0x58) = *(undefined4 *)(in_ECX + 0x94);
  }
  uStack_60 = *(undefined4 *)(in_ECX + 0x80);
  uStack_5c = *(undefined4 *)(in_ECX + 0x84);
  uStack_50 = *(undefined4 *)(in_ECX + 0x7c);
  uStack_58 = *(undefined1 *)(in_ECX + 4);
  uStack_54 = *(undefined4 *)(in_ECX + 0x78);
  uStack_4b = 0;
  uStack_7 = 0;
  uStack_4c = 0;
  uStack_8 = 0;
  FUN_005c1360(&uStack_60);
  return;
}


// ==== FUN_005cafa0 @ 0x005cafa0 ====

void FUN_005cafa0(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  char cVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  if (*(char *)(in_ECX + 0x90) != '\x01') {
    if (*(int **)(in_ECX + 0x80) == (int *)0x0) {
      return;
    }
    if (*(int *)(in_ECX + 0x84) == 0) {
      return;
    }
    cVar2 = (**(code **)(**(int **)(in_ECX + 0x80) + 0x2c))();
    if (cVar2 == '\0') {
      return;
    }
    cVar2 = (**(code **)(**(int **)(in_ECX + 0x84) + 0x2c))();
    if (cVar2 == '\0') {
      return;
    }
    *(undefined1 *)(in_ECX + 0x90) = 1;
  }
  iVar4 = *(int *)(in_ECX + 0x88);
  *(undefined4 *)(param_3 + 0x30) = DAT_0099d080;
  uVar1 = DAT_009bac80;
  *(bool *)(param_3 + 0x24) = iVar4 == 0;
  *(undefined1 *)(param_3 + 0x21) = 0xc;
  *(undefined1 *)(param_3 + 0x20) = 0;
  *(undefined1 *)(param_3 + 0x23) = 0;
  *(undefined1 *)(param_3 + 0x26) = 0;
  *(undefined4 *)(param_3 + 0x28) = uVar1;
  if (*(int *)(param_3 + 0x40) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = (*(int *)(param_3 + 0x44) - *(int *)(param_3 + 0x40)) / 0x58;
  }
  FUN_005c4ae0(iVar4 + 1,0);
  iVar4 = *(int *)(param_3 + 0x44);
  *(undefined4 *)(iVar4 + -0x14) = *(undefined4 *)(in_ECX + 0x8c);
  puVar5 = (undefined4 *)(iVar4 + -0x54);
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *param_1;
    param_1 = param_1 + 1;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)(iVar4 + -0x58) = param_4;
  uStack_60 = *(undefined4 *)(in_ECX + 0x80);
  uStack_5c = *(undefined4 *)(in_ECX + 0x84);
  uStack_50 = *(undefined4 *)(in_ECX + 0x7c);
  uStack_58 = *(undefined1 *)(in_ECX + 4);
  uStack_54 = *(undefined4 *)(in_ECX + 0x78);
  uStack_4b = 0;
  uStack_7 = 0;
  uStack_4c = 0;
  uStack_8 = 0;
  FUN_005c1360(&uStack_60);
  return;
}


// ==== FUN_005cb0f0 @ 0x005cb0f0 ====

void FUN_005cb0f0(byte param_1)

{
  void *in_ECX;
  
  FUN_005cacc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005cb110 @ 0x005cb110 ====

void FUN_005cb110(undefined1 *param_1)

{
  undefined1 *in_ECX;
  
  *in_ECX = *param_1;
  FUN_00401660(param_1 + 4,0,0xffffffff);
  FUN_00401660(param_1 + 0x20,0,0xffffffff);
  FUN_00401660(param_1 + 0x3c,0,0xffffffff);
  FUN_00401660(param_1 + 0x58,0,0xffffffff);
  return;
}


// ==== FUN_005cb170 @ 0x005cb170 ====

void FUN_005cb170(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2fcc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005cb190 @ 0x005cb190 ====

void FUN_005cb190(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2fe0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  *(undefined1 *)((int)in_ECX + 0x21) = 0;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_005cb1b0 @ 0x005cb1b0 ====

void FUN_005cb1b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2fe0;
  if (in_ECX[7] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[7]);
    in_ECX[7] = 0;
  }
  if (in_ECX[6] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[6]);
    in_ECX[6] = 0;
  }
  *in_ECX = &PTR_FUN_009c2fcc;
  return;
}


// ==== FUN_005cb200 @ 0x005cb200 ====

undefined4 FUN_005cb200(void)

{
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x20) != '\x01') {
    if (*(int **)(in_ECX + 0x18) == (int *)0x0) {
      cVar1 = (**(code **)(**(int **)(in_ECX + 0x1c) + 0x2c))();
      if (cVar1 == '\0') {
        return 0;
      }
      uVar2 = FUN_004b3b40();
      *(undefined4 *)(in_ECX + 4) = uVar2;
    }
    else {
      cVar1 = (**(code **)(**(int **)(in_ECX + 0x18) + 0x2c))();
      if (cVar1 == '\0') {
        return 0;
      }
    }
    *(undefined1 *)(in_ECX + 0x20) = 1;
  }
  return 1;
}


// ==== FUN_005cb240 @ 0x005cb240 ====

void FUN_005cb240(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  *(undefined1 *)(in_ECX + 0x20) = 0;
  *(undefined1 *)(in_ECX + 0x21) = *(undefined1 *)(*(int *)(param_1 + 0x24) + 8);
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(*(int *)(param_1 + 0x20) + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 4);
  *(undefined1 *)(in_ECX + 0x14) = *(undefined1 *)(*(int *)(param_1 + 0x24) + 9);
  *(undefined4 *)(in_ECX + 0x10) = 0;
  iVar1 = *(int *)(param_1 + 0x20);
  if (*(int *)(iVar1 + 0x1c) != 0) {
    uVar3 = FUN_005aa1b0(iVar1 + 8);
    *(undefined4 *)(in_ECX + 0x18) = uVar3;
    *(undefined4 *)(in_ECX + 4) = 1;
    return;
  }
  if (*(int *)(iVar1 + 0x38) != 0) {
    uVar3 = FUN_005aa220(iVar1 + 0x24);
    *(undefined4 *)(in_ECX + 0x1c) = uVar3;
    *(undefined4 *)(in_ECX + 4) = 1;
    return;
  }
  FUN_00401830(s_false_009c2f74);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005cb300 @ 0x005cb300 ====

void FUN_005cb300(int param_1,int *param_2,undefined4 param_3,char param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  code *pcVar7;
  char cVar8;
  undefined4 uVar9;
  float *pfVar10;
  uint uVar11;
  float fVar12;
  int in_ECX;
  int iVar13;
  float *pfVar14;
  float *pfVar15;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  undefined4 uStack_3c;
  undefined1 auStack_38 [4];
  void *pvStack_34;
  undefined4 uStack_24;
  uint uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  if (*(int *)(param_1 + 8) == 0) {
    return;
  }
  if (*(char *)(in_ECX + 0x20) != '\x01') {
    if (*(int **)(in_ECX + 0x18) == (int *)0x0) {
      cVar8 = (**(code **)(**(int **)(in_ECX + 0x1c) + 0x2c))();
      if (cVar8 == '\0') {
        return;
      }
      uVar9 = FUN_004b3b40();
      *(undefined4 *)(in_ECX + 4) = uVar9;
    }
    else {
      cVar8 = (**(code **)(**(int **)(in_ECX + 0x18) + 0x2c))();
      if (cVar8 == '\0') {
        return;
      }
    }
    *(undefined1 *)(in_ECX + 0x20) = 1;
  }
  puVar4 = *(undefined4 **)(param_1 + 4);
  puVar5 = (undefined4 *)*puVar4;
  while( true ) {
    if (puVar5 == puVar4) {
      return;
    }
    iVar6 = puVar5[2];
    if (iVar6 == 0) break;
    pfVar10 = (float *)(**(code **)(*param_2 + 0xc0))();
    fVar12 = *(float *)(in_ECX + 0x18);
    if (fVar12 == 0.0) {
      uVar11 = *(uint *)(iVar6 + 0x44);
      if (*(uint *)(in_ECX + 4) <= uVar11) {
        uStack_4 = 0xf;
        uStack_8 = 0;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
        FUN_00401740(s_Warning___Effect_Particle_txture_009c2f90,0x34);
        FUN_00796d50(auStack_1c);
        if (0xf < uStack_4) {
          _free(pvStack_18);
          return;
        }
        uStack_4 = 0xf;
        uStack_8 = 0;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
        uVar11 = *(int *)(in_ECX + 4) - 1;
      }
      fVar12 = (float)FUN_004b3ff0(uVar11);
    }
    pfVar10[3] = fVar12;
    pfVar10[9] = *(float *)(in_ECX + 0xc);
    pfVar10[8] = *(float *)(in_ECX + 8);
    pfVar10[6] = *(float *)(iVar6 + 0x40);
    pfVar10[7] = *(float *)(iVar6 + 0x30);
    *(undefined1 *)(pfVar10 + 10) = *(undefined1 *)(in_ECX + 0x14);
    fVar12 = *(float *)(iVar6 + 0x38);
    fVar1 = *(float *)(iVar6 + 0x24);
    pfVar10[5] = *(float *)(iVar6 + 0x2c) * fVar12;
    pfVar10[4] = fVar12 * fVar1;
    fVar12 = *(float *)(iVar6 + 0x10);
    fVar1 = *(float *)(iVar6 + 0x1c);
    fVar2 = *(float *)(iVar6 + 0x14);
    fVar3 = *(float *)(iVar6 + 0x20);
    *pfVar10 = *(float *)(iVar6 + 0x18) + *(float *)(iVar6 + 0xc);
    pfVar10[1] = fVar12 + fVar1;
    pfVar10[2] = fVar2 + fVar3;
    if (*(char *)(iVar6 + 0xac) != '\0') {
      fStack_48 = *pfVar10;
      fStack_44 = pfVar10[1];
      fStack_40 = pfVar10[2];
      uStack_3c = DAT_0099d080;
      thunk_FUN_0079ebf5(&fStack_48,&fStack_48,iVar6 + 0xe8);
      *pfVar10 = fStack_48;
      pfVar10[1] = fStack_44;
      pfVar10[2] = fStack_40;
    }
    if (*(char *)(in_ECX + 0x14) != '\0') {
      pfVar14 = (float *)(iVar6 + 0x4c);
      pfVar15 = pfVar10 + 0xb;
      for (iVar13 = 0x10; iVar13 != 0; iVar13 = iVar13 + -1) {
        *pfVar15 = *pfVar14;
        pfVar14 = pfVar14 + 1;
        pfVar15 = pfVar15 + 1;
      }
    }
    if (*(char *)(in_ECX + 0x21) == '\0') {
      if (param_4 == '\0') {
        (**(code **)(*param_2 + 0x88))(pfVar10);
      }
      else {
        (**(code **)(*param_2 + 0x118))();
      }
    }
    else if (param_4 == '\0') {
      (**(code **)(*param_2 + 200))();
    }
    else {
      (**(code **)(*param_2 + 300))();
    }
    puVar5 = (undefined4 *)*puVar5;
  }
  uStack_20 = 0xf;
  uStack_24 = 0;
  pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
  FUN_00401740(s_pElement____NULL_009c2f7c,0x10);
  FUN_00406880(auStack_38);
  if (uStack_20 < 0x10) {
    uStack_20 = 0xf;
    uStack_24 = 0;
    pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
    pcVar7 = (code *)swi(3);
    (*pcVar7)();
    return;
  }
  _free(pvStack_34);
  return;
}


// ==== FUN_005cb600 @ 0x005cb600 ====

void FUN_005cb600(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2fe0;
  if (in_ECX[7] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[7]);
    in_ECX[7] = 0;
  }
  if (in_ECX[6] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[6]);
    in_ECX[6] = 0;
  }
  *in_ECX = &PTR_FUN_009c2fcc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005cb660 @ 0x005cb660 ====

void FUN_005cb660(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_40 [16];
  
  thunk_FUN_0079f761(local_40,*param_2,param_2[1],param_2[2]);
  puVar2 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_005cb6a0 @ 0x005cb6a0 ====

void FUN_005cb6a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2ff4;
  FUN_005caa30();
  in_ECX[0x17] = 0;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_005cb6c0 @ 0x005cb6c0 ====

void FUN_005cb6c0(undefined4 param_1,int param_2)

{
  char cVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined1 local_d0 [8];
  undefined4 auStack_c8 [13];
  undefined4 auStack_94 [3];
  undefined1 auStack_88 [8];
  undefined4 local_80 [14];
  undefined4 auStack_48 [14];
  undefined4 *puStack_10;
  
  local_dc = DAT_0099d080;
  local_d8 = DAT_0099d080;
  local_d4 = 0;
  thunk_FUN_007a095f(local_d0,&local_dc,*(undefined4 *)(param_2 + 0x30));
  thunk_FUN_0079f761(auStack_c8 + 2,*(undefined4 *)(param_2 + 0x24),*(undefined4 *)(param_2 + 0x28),
                     *(undefined4 *)(param_2 + 0x2c));
  puVar3 = auStack_c8 + 2;
  puVar4 = local_80;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  thunk_FUN_0079fb96(auStack_c8 + 2,local_d0);
  cVar1 = *(char *)(in_ECX + 0x60);
  puVar3 = auStack_c8;
  puVar4 = auStack_48;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  if (cVar1 == '\0') {
    puVar3 = auStack_48;
  }
  else {
    puVar3 = (undefined4 *)(param_2 + 0x4c);
  }
  thunk_FUN_0079ee7b(auStack_c8,auStack_88,puVar3);
  puVar3 = &local_d4;
  puVar4 = auStack_94;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar3 = auStack_94;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puStack_10 = *puVar3;
    puVar3 = puVar3 + 1;
    puStack_10 = puStack_10 + 1;
  }
  return;
}


// ==== FUN_005cb7a0 @ 0x005cb7a0 ====

void FUN_005cb7a0(void)

{
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0x5c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x5c))(1);
  }
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  return;
}


// ==== FUN_005cb7c0 @ 0x005cb7c0 ====

void FUN_005cb7c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2ff4;
  if ((undefined4 *)in_ECX[0x17] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x17])(1);
  }
  in_ECX[0x17] = 0;
  FUN_005caa70();
  *in_ECX = &PTR_FUN_009c2fcc;
  return;
}


// ==== FUN_005cb7f0 @ 0x005cb7f0 ====

void FUN_005cb7f0(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  float *pfVar4;
  undefined4 uVar5;
  float *pfVar6;
  undefined4 uVar7;
  int in_ECX;
  int *piVar8;
  undefined1 auStack_64 [8];
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [64];
  
  if ((*(int *)(param_1 + 8) != 0) && (*(int *)(in_ECX + 0x5c) != 0)) {
    puVar1 = *(undefined4 **)(param_1 + 4);
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      iVar3 = puVar2[2];
      pfVar4 = (float *)(**(code **)(*param_2 + 0x70))();
      fStack_5c = *(float *)(iVar3 + 0x18) + *(float *)(iVar3 + 0xc);
      fStack_58 = *(float *)(iVar3 + 0x1c) + *(float *)(iVar3 + 0x10);
      fStack_54 = *(float *)(iVar3 + 0x20) + *(float *)(iVar3 + 0x14);
      *pfVar4 = fStack_5c;
      pfVar4[1] = fStack_58;
      pfVar4[2] = fStack_54;
      uVar5 = FUN_0040d600(auStack_64,*(undefined4 *)(iVar3 + 0x30));
      pfVar6 = (float *)FUN_0040d690(auStack_50,uVar5);
      pfVar4[3] = *pfVar6;
      pfVar4[4] = pfVar6[1];
      pfVar4[5] = pfVar6[2];
      pfVar4[6] = pfVar6[3];
      *(undefined1 *)(pfVar4 + 8) = 0;
      *(undefined1 *)((int)pfVar4 + 0x21) = 0xc;
      *(undefined1 *)((int)pfVar4 + 0x26) = 0;
      pfVar4[10] = 0.0;
      pfVar4[7] = *(float *)(iVar3 + 0x38);
      *(undefined1 *)((int)pfVar4 + 0x23) = 0;
      FUN_005cac00(*(undefined4 *)(iVar3 + 0x40),0x3f800000);
      piVar8 = param_2;
      pfVar6 = pfVar4;
      uVar5 = param_4;
      uVar7 = FUN_005cb6c0(auStack_40,iVar3);
      FUN_005cae40(uVar7,piVar8,pfVar6,uVar5);
      if ((char)param_4 == '\0') {
        (**(code **)(*param_2 + 0x98))(pfVar4);
      }
      else {
        (**(code **)(*param_2 + 0x11c))();
      }
    }
  }
  return;
}


// ==== FUN_005cb950 @ 0x005cb950 ====

void FUN_005cb950(void)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_74 [8];
  undefined1 local_6c;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 local_50;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_34;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(int *)(in_ECX + 0x5c) == 0) {
    local_58 = 0xf;
    local_3c = 0xf;
    local_20 = 0xf;
    local_4 = 0xf;
    local_5c = 0;
    local_6c = 0;
    local_40 = 0;
    local_50 = 0;
    local_24 = 0;
    local_34 = 0;
    local_8 = 0;
    local_18 = 0;
    local_74[0] = *(undefined1 *)(*(int *)(in_ECX + 0x18) + 0x5c);
    FUN_00401660(*(int *)(in_ECX + 0x18) + 0x24,0,0xffffffff);
    FUN_00401660(*(int *)(in_ECX + 0x14) + 0x24,0,0xffffffff);
    pvVar2 = operator_new(0x98);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_005cad30();
    }
    *(undefined4 *)(in_ECX + 0x5c) = uVar3;
    cVar1 = FUN_005cad90(local_74);
    if (cVar1 == '\0') {
      if (*(undefined4 **)(in_ECX + 0x5c) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(in_ECX + 0x5c))(1);
      }
      *(undefined4 *)(in_ECX + 0x5c) = 0;
      FUN_005b1b00();
      return;
    }
    FUN_005cac20(0);
    FUN_005b1b00();
  }
  return;
}


// ==== FUN_005cba30 @ 0x005cba30 ====

void FUN_005cba30(int param_1)

{
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0x5c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x5c))(1);
  }
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 4);
  *(undefined1 *)(in_ECX + 0x60) = *(undefined1 *)(*(int *)(param_1 + 0x24) + 9);
  FUN_005cb950();
  return;
}


// ==== FUN_005cba80 @ 0x005cba80 ====

void FUN_005cba80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2ff4;
  if ((undefined4 *)in_ECX[0x17] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x17])(1);
  }
  in_ECX[0x17] = 0;
  FUN_005caa70();
  *in_ECX = &PTR_FUN_009c2fcc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005cbaf0 @ 0x005cbaf0 ====

void FUN_005cbaf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3028;
  if (in_ECX[0xd] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0xd]);
    in_ECX[0xd] = 0;
  }
  *in_ECX = &PTR_FUN_009c2fcc;
  return;
}


// ==== FUN_005cbb20 @ 0x005cbb20 ====

void FUN_005cbb20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3028;
  in_ECX[0xd] = 0;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_005cbb40 @ 0x005cbb40 ====

void FUN_005cbb40(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(*(int *)(param_1 + 0x20) + 4);
  *(undefined4 *)(in_ECX + 8) = 2;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(*(int *)(param_1 + 0x24) + 100);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x80);
  iVar1 = *(int *)(param_1 + 0x24);
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(iVar1 + 0x78);
  *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(iVar1 + 0x7c);
  iVar1 = *(int *)(param_1 + 0x24);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(iVar1 + 0x68);
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(iVar1 + 0x6c);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(iVar1 + 0x70);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(iVar1 + 0x74);
  if (*(int *)(*(int *)(param_1 + 0x20) + 0x1c) != 0) {
    uVar3 = FUN_005aa1b0(*(int *)(param_1 + 0x24) + 0x84);
    *(undefined4 *)(in_ECX + 0x34) = uVar3;
    *(undefined4 *)(in_ECX + 4) = 1;
    return;
  }
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  local_4 = 0xf;
  FUN_00401740(s_FALSE_009c3008,5);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005cbc20 @ 0x005cbc20 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005cbc20(int param_1,int *param_2,undefined4 param_3,char param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  code *pcVar6;
  float10 fVar7;
  float fVar8;
  char cVar9;
  int iVar10;
  float *pfVar11;
  float fVar12;
  int in_ECX;
  float10 fVar13;
  float fVar14;
  uint uStack_54;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  float fStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  int iStack_8;
  uint uStack_4;
  
  if ((*(int *)(param_1 + 8) != 0) &&
     (cVar9 = (**(code **)(**(int **)(in_ECX + 0x34) + 0x2c))(), cVar9 != '\0')) {
    iVar10 = (**(code **)(*DAT_00b5afb4 + 0x10))();
    iVar10 = *(int *)(iVar10 + 0x34);
    if (iVar10 != 0) {
      puVar3 = *(undefined4 **)(param_1 + 4);
      puVar4 = (undefined4 *)*puVar3;
      uStack_54 = 0;
      for (; puVar4 != puVar3; puVar4 = (undefined4 *)*puVar4) {
        iVar5 = puVar4[2];
        if (iVar5 == 0) {
          uStack_4 = 0xf;
          pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
          iStack_8 = iVar5;
          FUN_00401740(s_pElement____NULL_009c3010,0x10);
          FUN_00406880(auStack_1c);
          if (uStack_4 < 0x10) {
            uStack_4 = 0xf;
            iStack_8 = 0;
            pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
            pcVar6 = (code *)swi(3);
            (*pcVar6)();
            return;
          }
          _free(pvStack_18);
          return;
        }
        *(undefined1 *)(iVar5 + 0x48) = 1;
        if (*(uint *)(in_ECX + 0x14) < uStack_54) {
          return;
        }
        if (*(float *)(iVar5 + 0x34) < *(float *)(in_ECX + 0x18)) {
          uVar1 = (uint)ROUND(*(float *)(iVar5 + 0xc));
          uVar2 = (uint)ROUND(*(float *)(iVar5 + 0x14));
          if ((uVar1 <= *(uint *)(iVar10 + 0x40)) && (uVar2 <= *(uint *)(iVar10 + 0x44))) {
            pfVar11 = (float *)(**(code **)(*param_2 + 0xc0))();
            if (*(float *)(in_ECX + 0x34) != 0.0) {
              pfVar11[3] = *(float *)(in_ECX + 0x34);
            }
            fVar12 = DAT_0099d080;
            pfVar11[9] = *(float *)(in_ECX + 0xc);
            pfVar11[8] = *(float *)(in_ECX + 8);
            uStack_2c = *(undefined4 *)(in_ECX + 0x1c);
            fVar14 = (fVar12 / *(float *)(in_ECX + 0x18)) * *(float *)(iVar5 + 0x34);
            uStack_28 = *(undefined4 *)(in_ECX + 0x20);
            uStack_24 = *(undefined4 *)(in_ECX + 0x24);
            fStack_20 = *(float *)(in_ECX + 0x28) * fVar14;
            fVar12 = (float)FUN_0040ead0(&uStack_2c);
            fVar14 = fVar14 * DAT_0099d0f8;
            pfVar11[6] = fVar12;
            fVar12 = *(float *)(in_ECX + 0x30);
            fVar8 = (float)(int)uVar1;
            pfVar11[4] = *(float *)(in_ECX + 0x2c) * fVar14;
            pfVar11[5] = fVar12 * fVar14;
            pfVar11[7] = 0.0;
            if ((int)uVar1 < 0) {
              fVar8 = fVar8 + _DAT_0099d104;
            }
            fVar13 = (float10)FUN_005cbf00(uVar1,uVar2);
            fVar7 = (float10)DAT_009c3038;
            fVar12 = (float)(int)uVar2;
            if ((int)uVar2 < 0) {
              fVar12 = fVar12 + _DAT_0099d104;
            }
            *pfVar11 = fVar8;
            pfVar11[1] = (float)(fVar13 + fVar7);
            pfVar11[2] = fVar12;
            if (param_4 == '\0') {
              (**(code **)(*param_2 + 0x88))(pfVar11);
            }
            else {
              (**(code **)(*param_2 + 0x118))();
            }
            uStack_54 = uStack_54 + 1;
          }
        }
      }
    }
  }
  return;
}


// ==== FUN_005cbec0 @ 0x005cbec0 ====

void FUN_005cbec0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3028;
  if (in_ECX[0xd] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0xd]);
    in_ECX[0xd] = 0;
  }
  *in_ECX = &PTR_FUN_009c2fcc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005cbf00 @ 0x005cbf00 ====

float10 FUN_005cbf00(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xc0);
  uVar3 = *(int *)(iVar1 + 0xc) - 1;
  if (uVar3 < param_1) {
    param_1 = uVar3;
  }
  uVar3 = *(int *)(iVar1 + 0x10) - 1;
  if (uVar3 < param_2) {
    param_2 = uVar3;
  }
  iVar2 = *(int *)(iVar1 + 0x2c);
  param_1 = (*(int *)(iVar1 + 0xc) + 1) * param_2 + param_1;
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x30) - iVar2 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0042f370();
  }
  return (float10)*(float *)(iVar2 + param_1 * 4);
}


// ==== FUN_005cbf60 @ 0x005cbf60 ====

int FUN_005cbf60(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982ad0;
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


// ==== Catch@005cbfc6 @ 0x005cbfc6 ====

void Catch_005cbfc6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005cbfd0 @ 0x005cbfd0 ====

void FUN_005cbfd0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982ae0;
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


// ==== Catch@005cc03f @ 0x005cc03f ====

void Catch_005cc03f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005cc060 @ 0x005cc060 ====

void * FUN_005cc060(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982af0;
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


// ==== Catch@005cc0cd @ 0x005cc0cd ====

void Catch_005cc0cd(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005cc0f0 @ 0x005cc0f0 ====

void FUN_005cc0f0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982b00;
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


// ==== Catch@005cc156 @ 0x005cc156 ====

void Catch_005cc156(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005cc160 @ 0x005cc160 ====

void FUN_005cc160(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005cbf60(param_1,param_2,param_3);
  return;
}


// ==== FUN_005cc180 @ 0x005cc180 ====

void FUN_005cc180(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  char cVar4;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    piVar3 = (int *)puVar2[3];
    cVar4 = (**(code **)(*piVar3 + 4))();
    if ((cVar4 != '\0') && (cVar4 = (**(code **)(*piVar3 + 0x3c))(), cVar4 == '\0')) {
      if (param_2 == 0x12) {
        (**(code **)(*piVar3 + 0x24))(param_1,1);
      }
      else {
        (**(code **)(*piVar3 + 0x24))(param_1,0);
      }
    }
  }
  return;
}


// ==== FUN_005cc1e0 @ 0x005cc1e0 ====

undefined4 FUN_005cc1e0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  puVar2 = (undefined4 *)*puVar1;
  while( true ) {
    if (puVar2 == puVar1) {
      return 0;
    }
    cVar3 = (**(code **)(*(int *)puVar2[3] + 0x1c))(param_1);
    if (cVar3 != '\0') break;
    puVar2 = (undefined4 *)*puVar2;
  }
  return 1;
}


// ==== FUN_005cc220 @ 0x005cc220 ====

void FUN_005cc220(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int *piVar4;
  
  piVar1 = *(int **)(in_ECX + 8);
  piVar4 = (int *)*piVar1;
  if (piVar4 != piVar1) {
    do {
      piVar2 = (int *)piVar4[3];
      (**(code **)(*piVar2 + 0x34))();
      iVar3 = (**(code **)(*piVar2 + 0x14))();
      if (iVar3 != 7) {
        (**(code **)(*piVar2 + 8))(0);
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != piVar1);
  }
  return;
}


// ==== FUN_005cc260 @ 0x005cc260 ====

bool FUN_005cc260(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  bool bVar4;
  char cVar5;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  bVar4 = true;
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    piVar3 = (int *)puVar2[3];
    cVar5 = (**(code **)(*piVar3 + 4))();
    if ((((cVar5 != '\0') && (cVar5 = (**(code **)(*piVar3 + 0x3c))(), cVar5 == '\0')) &&
        (cVar5 = (**(code **)(*piVar3 + 0x18))(param_1), cVar5 != '\0')) && (bVar4)) {
      bVar4 = false;
    }
  }
  return bVar4;
}


// ==== FUN_005cc2b0 @ 0x005cc2b0 ====

void FUN_005cc2b0(void)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int in_ECX;
  int *piVar4;
  
  piVar1 = *(int **)(in_ECX + 8);
  piVar4 = (int *)*piVar1;
  if (piVar4 != piVar1) {
    do {
      piVar2 = (int *)piVar4[3];
      cVar3 = (**(code **)(*piVar2 + 4))();
      if (cVar3 != '\0') {
        (**(code **)(*piVar2 + 0x30))();
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != piVar1);
  }
  return;
}


// ==== FUN_005cc2e0 @ 0x005cc2e0 ====

undefined4 FUN_005cc2e0(undefined4 param_1)

{
  char cVar1;
  char ****ppppcVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  char ****ppppcVar3;
  int local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  char ****local_18 [5];
  uint local_4;
  
  FUN_00897340(&local_3c,&param_1);
  if (local_3c != *(int *)(in_ECX + 8)) {
    return *(undefined4 *)(local_3c + 0xc);
  }
  FUN_00401740(s_Unit____d_Effect_Play_Fail____009c3040,0x1e);
  FUN_00404230(local_1c);
  ppppcVar3 = local_18[0];
  if (local_4 < 0x10) {
    ppppcVar3 = (char ****)local_18;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  ppppcVar2 = ppppcVar3;
  do {
    cVar1 = *(char *)ppppcVar2;
    ppppcVar2 = (char ****)((int)ppppcVar2 + 1);
  } while (cVar1 != '\0');
  FUN_00401740(ppppcVar3,(int)ppppcVar2 - (int)((int)ppppcVar3 + 1));
  FUN_00796d50(local_38);
  if (0xf < local_20) {
    _free(local_34);
    return extraout_EAX;
  }
  if (local_4 < 0x10) {
    return 0;
  }
  _free(local_18[0]);
  return extraout_EAX_00;
}


// ==== FUN_005cc3c0 @ 0x005cc3c0 ====

void FUN_005cc3c0(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x14) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    FUN_008984a0();
    return;
  }
  _free(*(void **)(in_ECX + 0x14));
  return;
}


// ==== FUN_005cc400 @ 0x005cc400 ====

void FUN_005cc400(void)

{
  undefined4 uVar1;
  undefined1 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = local_5;
  uVar1 = FUN_005cbfd0();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  local_4 = *(undefined4 *)(in_ECX + 8);
  FUN_005cc7f0(9,&local_4);
  *(undefined4 *)(in_ECX + 0x20) = 1;
  *(undefined4 *)(in_ECX + 0x24) = 1;
  return;
}


// ==== FUN_005cc450 @ 0x005cc450 ====

void FUN_005cc450(undefined4 *param_1,uint param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 uStack_18;
  undefined1 auStack_14 [16];
  
  iVar2 = (**(code **)(*DAT_00b5acf4 + 4))(*param_1);
  if (iVar2 != 0) {
    piVar1 = *(int **)(iVar2 + 0x28);
    for (piVar4 = *(int **)(iVar2 + 0x24); piVar4 != piVar1; piVar4 = piVar4 + 8) {
      iVar2 = (**(code **)(*DAT_00b5acf0 + 4))(piVar4 + 1);
      if (iVar2 != 0) {
        if (param_2 == 0) {
          uStack_20 = (**(code **)(*DAT_00b5aff8 + 8))(iVar2,param_3);
          iStack_24 = *piVar4 << 0x10;
          FUN_005cc960(auStack_14,&iStack_24);
        }
        else {
          uVar3 = 0;
          if (param_2 != 0) {
            do {
              uStack_18 = (**(code **)(*DAT_00b5aff8 + 8))(iVar2,param_3);
              uVar3 = uVar3 + 1;
              uStack_1c = *piVar4 << 0x10 | uVar3;
              FUN_005cc960(auStack_14,&uStack_1c);
            } while (uVar3 < param_2);
          }
        }
      }
    }
  }
  return;
}


// ==== FUN_005cc540 @ 0x005cc540 ====

void FUN_005cc540(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    (**(code **)(*DAT_00b5aff8 + 4))(puVar2[3]);
  }
  FUN_005ccb90();
  return;
}


// ==== FUN_005cc570 @ 0x005cc570 ====

int FUN_005cc570(int param_1,int param_2,undefined4 param_3)

{
  FUN_005cc0f0(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_005cc5a0 @ 0x005cc5a0 ====

void FUN_005cc5a0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00982b10;
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
      uVar5 = FUN_005cc160(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_005cc570(uVar5,param_2,&local_18);
      FUN_005cc160(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_005cbf60(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_005cc570(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_005cbf60(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005cc701 @ 0x005cc701 ====

void Catch_005cc701(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_005cc7f0 @ 0x005cc7f0 ====

void FUN_005cc7f0(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982b20;
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
    uVar2 = FUN_005cc570(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005cc884 @ 0x005cc884 ====

void Catch_005cc884(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005cc8a0 @ 0x005cc8a0 ====

void FUN_005cc8a0(uint param_1,undefined1 param_2)

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
    FUN_005cc5a0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_005cc910 @ 0x005cc910 ====

/* WARNING: Removing unreachable block (ram,0x005cc92b) */
/* WARNING: Removing unreachable block (ram,0x005cc930) */
/* WARNING: Removing unreachable block (ram,0x005cc93e) */

void FUN_005cc910(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_005cc5a0(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_005cc960 @ 0x005cc960 ====

/* WARNING: Removing unreachable block (ram,0x005cca48) */

void FUN_005cc960(int *param_1,uint *param_2)

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
      FUN_005cc8a0(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
  iVar5 = FUN_005cc060(puVar7,puVar7[1],param_2);
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


// ==== FUN_005ccb90 @ 0x005ccb90 ====

void FUN_005ccb90(void)

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
    FUN_005cc910(9,&local_4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_005ccc00 @ 0x005ccc00 ====

void FUN_005ccc00(void)

{
  int in_ECX;
  
  FUN_004eb890(in_ECX + 0xe8);
  FUN_005bc0a0(in_ECX + 0xf8);
  if (*(void **)(in_ECX + 0xfc) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0xfc));
    return;
  }
  *(undefined4 *)(in_ECX + 0xfc) = 0;
  *(undefined4 *)(in_ECX + 0x100) = 0;
  *(undefined4 *)(in_ECX + 0x104) = 0;
  if (*(void **)(in_ECX + 0xec) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0xec) = 0;
    *(undefined4 *)(in_ECX + 0xf0) = 0;
    *(undefined4 *)(in_ECX + 0xf4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0xec));
  return;
}


// ==== FUN_005ccc60 @ 0x005ccc60 ====

/* WARNING: Removing unreachable block (ram,0x005ccd47) */

void FUN_005ccc60(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 auStack_16c [3];
  undefined1 local_160 [52];
  undefined1 auStack_12c [12];
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100 [16];
  undefined4 local_c0 [16];
  undefined4 local_80 [13];
  undefined4 auStack_4c [17];
  int *piStack_8;
  
  local_120 = *in_ECX;
  local_11c = in_ECX[2];
  local_118 = in_ECX[3];
  local_114 = in_ECX[4];
  local_110 = in_ECX[5];
  local_10c = in_ECX[6];
  local_108 = in_ECX[7];
  local_104 = in_ECX[8];
  puVar2 = in_ECX + 9;
  puVar4 = local_100;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar2 = (undefined4 *)FUN_005cd200(local_160,in_ECX + 2,in_ECX + 5,in_ECX + 9);
  puVar4 = local_c0;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar2 = in_ECX + 0x19;
  puVar4 = local_80;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  thunk_FUN_0079ee7b(local_160,in_ECX + 0x29,in_ECX + 0x19);
  puVar2 = auStack_16c;
  puVar4 = auStack_4c;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_00401740(s_o_pTransform_>Insert_009c3064,0x14);
  (**(code **)(*piStack_8 + 4))(auStack_12c);
  iVar1 = in_ECX[0x40];
  for (iVar3 = in_ECX[0x3f]; iVar3 != iVar1; iVar3 = iVar3 + 4) {
    FUN_005ccc60(piStack_8);
  }
  return;
}


// ==== FUN_005ccda0 @ 0x005ccda0 ====

void FUN_005ccda0(uint param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  if ((*(int *)(in_ECX + 0xec) != 0) &&
     (param_1 < (uint)(*(int *)(in_ECX + 0xf0) - *(int *)(in_ECX + 0xec) >> 2))) {
    iVar1 = *(int *)(in_ECX + 0x100);
    for (iVar2 = *(int *)(in_ECX + 0xfc); iVar2 != iVar1; iVar2 = iVar2 + 4) {
      FUN_005ccda0(param_1);
    }
    iVar1 = *(int *)(in_ECX + 0xec);
    if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0xf0) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    if (*(int *)(iVar1 + param_1 * 4) != 0) {
      FUN_005d55f0();
    }
  }
  return;
}


// ==== FUN_005cce10 @ 0x005cce10 ====

void FUN_005cce10(uint param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 unaff_retaddr;
  undefined4 uStack_50;
  undefined1 auStack_3e [50];
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar2 = in_ECX[0x3b];
  if ((iVar2 != 0) && (param_1 < (uint)(in_ECX[0x3c] - iVar2 >> 2))) {
    if ((iVar2 == 0) || ((uint)(in_ECX[0x3c] - iVar2 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    if (*(int *)(iVar2 + param_1 * 4) != 0) {
      uStack_50 = *in_ECX;
      iVar2 = (**(code **)(*param_4 + 0xc))();
      if (iVar2 != 0) {
        FUN_005d5730(param_1,param_2,iVar2);
        thunk_FUN_0079ee7b(auStack_3e + -6,in_ECX + 0x29,iVar2 + 0xa0);
        puVar4 = &uStack_50;
        puVar5 = (undefined4 *)(iVar2 + 0xe0);
        for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        iVar1 = in_ECX[0x40];
        for (iVar3 = in_ECX[0x3f]; iVar3 != iVar1; iVar3 = iVar3 + 4) {
          FUN_005cce10(uStack_c,uStack_8,iVar2 + 0xa0,unaff_retaddr);
        }
      }
    }
  }
  return;
}


// ==== FUN_005ccef0 @ 0x005ccef0 ====

void FUN_005ccef0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xec) = 0;
  *(undefined4 *)(in_ECX + 0xf0) = 0;
  *(undefined4 *)(in_ECX + 0xf4) = 0;
  *(undefined4 *)(in_ECX + 0xfc) = 0;
  *(undefined4 *)(in_ECX + 0x100) = 0;
  *(undefined4 *)(in_ECX + 0x104) = 0;
  *(undefined4 *)(in_ECX + 0x108) = 0;
  *(undefined1 *)(in_ECX + 0x10c) = 0;
  return;
}


// ==== FUN_005ccf30 @ 0x005ccf30 ====

void FUN_005ccf30(undefined4 param_1,uint param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40 [16];
  
  if ((in_ECX[0x3b] == 0) || ((uint)((int)(in_ECX[0x3c] - in_ECX[0x3b]) >> 2) <= param_2)) {
    FUN_005cd4c0(param_2 + 1,0);
  }
  iVar3 = in_ECX[0x3b];
  if ((iVar3 == 0) || ((uint)(in_ECX[0x3c] - iVar3 >> 2) <= param_2)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  iVar3 = *(int *)(iVar3 + param_2 * 4);
  if (iVar3 == 0) {
    local_60 = *in_ECX;
    local_5c = in_ECX[2];
    local_58 = in_ECX[3];
    local_54 = in_ECX[4];
    local_50 = in_ECX[5];
    local_4c = in_ECX[6];
    local_48 = in_ECX[7];
    local_44 = in_ECX[8];
    puVar4 = in_ECX + 9;
    puVar5 = local_40;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    pvVar2 = operator_new(0x70);
    if (pvVar2 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_005d5590(&local_60);
    }
  }
  *(int *)(in_ECX[0x3b] + param_2 * 4) = iVar3;
  FUN_005d5600(param_1);
  iVar1 = in_ECX[0x40];
  for (iVar3 = in_ECX[0x3f]; iVar3 != iVar1; iVar3 = iVar3 + 4) {
    FUN_005ccf30(param_1,param_2);
  }
  return;
}


// ==== FUN_005cd040 @ 0x005cd040 ====

void FUN_005cd040(undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined4 *in_ECX;
  int iVar6;
  void *pvVar7;
  undefined4 *puVar8;
  undefined4 unaff_retaddr;
  undefined1 auStack_86 [6];
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  in_ECX[0x42] = param_3;
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  in_ECX[4] = param_1[4];
  in_ECX[5] = param_1[5];
  in_ECX[6] = param_1[6];
  in_ECX[7] = param_1[7];
  in_ECX[8] = param_1[8];
  puVar4 = param_1 + 9;
  puVar8 = in_ECX + 9;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar8 = puVar8 + 1;
  }
  puVar4 = (undefined4 *)FUN_005cd200(local_40,in_ECX + 2,in_ECX + 5,in_ECX + 9);
  uVar1 = *in_ECX;
  puVar8 = local_80;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar8 = puVar8 + 1;
  }
  puVar4 = local_80;
  puVar8 = in_ECX + 0x19;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar8 = puVar8 + 1;
  }
  FUN_005bb5f0(in_ECX[1],uVar1);
  if (param_2 != 0) {
    thunk_FUN_0079ee7b(local_80,in_ECX + 0x19,param_2 + 100);
    puVar4 = local_80;
    puVar8 = in_ECX + 0x19;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar8 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar8 = puVar8 + 1;
    }
  }
  thunk_FUN_0079f3a1(in_ECX + 0x29,0,in_ECX + 0x19);
  iVar2 = param_1[0x1b];
  for (iVar6 = param_1[0x1a]; iVar6 != iVar2; iVar6 = iVar6 + 0x74) {
    pvVar5 = operator_new(0x110);
    pvVar7 = (void *)0x0;
    if (pvVar5 != (void *)0x0) {
      *(undefined4 *)((int)pvVar5 + 0xec) = 0;
      *(undefined4 *)((int)pvVar5 + 0xf0) = 0;
      *(undefined4 *)((int)pvVar5 + 0xf4) = 0;
      *(undefined4 *)((int)pvVar5 + 0xfc) = 0;
      *(undefined4 *)((int)pvVar5 + 0x100) = 0;
      *(undefined4 *)((int)pvVar5 + 0x104) = 0;
      *(undefined4 *)((int)pvVar5 + 0x108) = 0;
      *(undefined1 *)((int)pvVar5 + 0x10c) = 0;
      pvVar7 = pvVar5;
    }
    FUN_005cd040(iVar6,in_ECX,unaff_retaddr);
    iVar3 = in_ECX[0x3f];
    if ((iVar3 == 0) || ((uint)(in_ECX[0x41] - iVar3 >> 2) <= (uint)(in_ECX[0x40] - iVar3 >> 2))) {
      FUN_005bc8c0(in_ECX[0x40],1,auStack_86 + -0xe);
    }
    else {
      puVar4 = (undefined4 *)in_ECX[0x40];
      *puVar4 = pvVar7;
      in_ECX[0x40] = puVar4 + 1;
    }
  }
  return;
}


// ==== FUN_005cd200 @ 0x005cd200 ====

void FUN_005cd200(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 local_80 [2];
  undefined1 auStack_7e [42];
  undefined4 auStack_54 [3];
  undefined1 auStack_48 [56];
  undefined4 *puStack_10;
  undefined4 *puStack_c;
  
  thunk_FUN_0079fb96(local_80,param_3);
  thunk_FUN_0079ee7b(auStack_48,param_2,local_80 + -8);
  puVar2 = auStack_54;
  puVar3 = puStack_10;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puStack_10[0xc] = *puStack_c;
  puStack_10[0xd] = puStack_c[1];
  puStack_10[0xe] = puStack_c[2];
  return;
}


// ==== FUN_005cd270 @ 0x005cd270 ====

void FUN_005cd270(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00982b30;
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


// ==== Catch@005cd3d1 @ 0x005cd3d1 ====

void Catch_005cd3d1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_005cd4c0 @ 0x005cd4c0 ====

void FUN_005cd4c0(uint param_1,undefined1 param_2)

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
    FUN_005cd270(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if (((iVar2 != 0) && (pvVar3 = *(void **)(in_ECX + 8), param_1 < (uint)((int)pvVar3 - iVar2 >> 2))
      ) && (_Dst = (void *)(iVar2 + param_1 * 4), _Dst != pvVar3)) {
    pvVar3 = _memmove(_Dst,pvVar3,0);
    *(void **)(in_ECX + 8) = pvVar3;
  }
  return;
}


// ==== FUN_005cd550 @ 0x005cd550 ====

void FUN_005cd550(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c30b0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005cd570 @ 0x005cd570 ====

int FUN_005cd570(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982b40;
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


// ==== Catch@005cd5d6 @ 0x005cd5d6 ====

void Catch_005cd5d6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005cd5e0 @ 0x005cd5e0 ====

void FUN_005cd5e0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982b50;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x18);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005cd64f @ 0x005cd64f ====

void Catch_005cd64f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005cd670 @ 0x005cd670 ====

void FUN_005cd670(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982b60;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005cd6df @ 0x005cd6df ====

void Catch_005cd6df(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005cd700 @ 0x005cd700 ====

void FUN_005cd700(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982b70;
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


// ==== Catch@005cd766 @ 0x005cd766 ====

void Catch_005cd766(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005cd770 @ 0x005cd770 ====

void FUN_005cd770(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005cd570(param_1,param_2,param_3);
  return;
}


// ==== FUN_005cd790 @ 0x005cd790 ====

int FUN_005cd790(int param_1,int param_2,undefined4 param_3)

{
  FUN_005cd700(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_005cd7c0 @ 0x005cd7c0 ====

void FUN_005cd7c0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *_Memory;
  int *in_ECX;
  
  _Memory = (undefined4 *)FUN_005bb150();
  puVar1 = *(undefined4 **)(param_1 + 8);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    (**(code **)(*in_ECX + 8))(puVar2[2],puVar2[3]);
  }
  puVar1 = (undefined4 *)*_Memory;
  *_Memory = _Memory;
  _Memory[1] = _Memory;
  if (puVar1 == _Memory) {
    _free(_Memory);
    return;
  }
  _free(puVar1);
  return;
}


// ==== FUN_005cd860 @ 0x005cd860 ====

void FUN_005cd860(undefined1 param_1,undefined1 param_2)

{
  code *pcVar1;
  int in_ECX;
  int local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  FUN_00897340(&local_20,&param_1);
  if (local_20 != *(int *)(in_ECX + 0xc)) {
    FUN_00467950(&param_2);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_itObjectInNode_____nodeID_Object_009c3080,0x2a);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005cd8e0 @ 0x005cd8e0 ====

void FUN_005cd8e0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *puVar3;
  int local_c;
  undefined4 *local_8;
  undefined4 *local_4;
  
  local_8 = (undefined4 *)(in_ECX + 0x2c);
  FUN_00897340(&local_c,&param_1);
  uVar2 = param_1;
  if (local_c != *(int *)(in_ECX + 0x34)) {
    puVar1 = *(undefined4 **)(local_c + 0x14);
    for (puVar3 = *(undefined4 **)(local_c + 0x10); puVar3 != puVar1; puVar3 = puVar3 + 1) {
      FUN_005cd860(*puVar3,uVar2);
    }
  }
  FUN_005a8440(&local_8,&param_1);
  for (puVar1 = local_8; puVar1 != local_4; puVar1 = (undefined4 *)*puVar1) {
  }
  FUN_005ce270(&param_1,local_8,local_4);
  return;
}


// ==== FUN_005cd970 @ 0x005cd970 ====

void FUN_005cd970(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_1c [8];
  undefined4 local_14 [2];
  void *local_c;
  
  local_14[0] = param_1;
  FUN_00430c20(param_2);
  FUN_005ce3e0(local_1c,local_14);
  if (local_c == (void *)0x0) {
    return;
  }
  _free(local_c);
  return;
}


// ==== FUN_005cd9c0 @ 0x005cd9c0 ====

void FUN_005cd9c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c30c8;
  if ((void *)in_ECX[0x10] == (void *)0x0) {
    in_ECX[0x10] = 0;
    in_ECX[0x11] = 0;
    in_ECX[0x12] = 0;
    FUN_00897490();
    _free((void *)in_ECX[0xd]);
    return;
  }
  _free((void *)in_ECX[0x10]);
  return;
}


// ==== FUN_005cda40 @ 0x005cda40 ====

void FUN_005cda40(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009c30c8;
  *(undefined1 *)(in_ECX + 1) = local_5;
  uVar1 = FUN_005cd5e0();
  in_ECX[3] = uVar1;
  in_ECX[4] = 0;
  local_4 = in_ECX[3];
  FUN_005ce010(9,&local_4);
  in_ECX[9] = 1;
  in_ECX[10] = 1;
  *(undefined1 *)(in_ECX + 0xb) = local_5;
  uVar1 = FUN_005cd670();
  in_ECX[0xd] = uVar1;
  in_ECX[0xe] = 0;
  local_4 = in_ECX[0xd];
  FUN_005ce010(9,&local_4);
  in_ECX[0x13] = 1;
  in_ECX[0x14] = 1;
  return;
}


// ==== FUN_005cdad0 @ 0x005cdad0 ====

void FUN_005cdad0(undefined1 param_1,undefined1 param_2)

{
  undefined1 local_8 [8];
  
  FUN_005ce840(&param_1);
  FUN_004677a0(local_8,&param_2);
  return;
}


// ==== FUN_005cdb00 @ 0x005cdb00 ====

void FUN_005cdb00(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 local_8 [8];
  
  puVar2 = *(undefined4 **)(param_2 + 4);
  puVar1 = *(undefined4 **)(param_2 + 8);
  if (puVar2 != puVar1) {
    do {
      param_2 = *puVar2;
      FUN_005ce840(&param_2);
      FUN_004677a0(local_8,&param_1);
      puVar2 = puVar2 + 1;
    } while (puVar2 != puVar1);
  }
  return;
}


// ==== FUN_005cdb60 @ 0x005cdb60 ====

void FUN_005cdb60(int *param_1)

{
  int iVar1;
  int *in_ECX;
  undefined4 uStack_2c;
  undefined1 auStack_28 [4];
  undefined4 uStack_24;
  int *piStack_20;
  undefined4 uStack_1c;
  void *pvStack_18;
  
  (**(code **)(*in_ECX + 0xc))(param_1);
  iVar1 = (**(code **)(*DAT_00b5afb4 + 0x10))();
  uStack_24 = 0;
  piStack_20 = (int *)0x0;
  uStack_1c = 0;
  (**(code **)(*param_1 + 8))(*(undefined4 *)(iVar1 + 0x34),auStack_28);
  piStack_20 = param_1;
  FUN_00430c20(auStack_28);
  FUN_005ce3e0(auStack_28 + -0x10,&piStack_20);
  if (pvStack_18 != (void *)0x0) {
    _free(pvStack_18);
    return;
  }
  FUN_005cdb00(param_1,auStack_28 + -8);
  if (uStack_2c == (void *)0x0) {
    return;
  }
  _free(uStack_2c);
  return;
}


// ==== FUN_005cdc10 @ 0x005cdc10 ====

void FUN_005cdc10(undefined4 param_1)

{
  int in_ECX;
  int local_24 [2];
  undefined1 local_1c [4];
  int local_18;
  undefined4 local_14;
  undefined4 local_10 [2];
  undefined4 *local_8;
  
  FUN_00897340(local_24,&param_1);
  if (local_24[0] == *(int *)(in_ECX + 0xc)) {
    local_18 = FUN_00751a80();
    *(undefined1 *)(local_18 + 0x11) = 1;
    *(int *)(local_18 + 4) = local_18;
    *(int *)local_18 = local_18;
    *(int *)(local_18 + 8) = local_18;
    local_14 = 0;
    FUN_00467210(*(undefined4 *)(local_18 + 4));
    *(int *)(local_18 + 4) = local_18;
    local_14 = 0;
    *(int *)local_18 = local_18;
    *(int *)(local_18 + 8) = local_18;
    local_10[0] = param_1;
    FUN_00594840(local_1c);
    FUN_005ce610(local_24,local_10);
    FUN_00467860(local_24,*local_8,local_8);
    _free(local_8);
    return;
  }
  FUN_005ce840(&param_1);
  return;
}


// ==== FUN_005cdd10 @ 0x005cdd10 ====

void FUN_005cdd10(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  
  uVar4 = (param_2[2] ^ 0xdeadbeefU) & *(uint *)(in_ECX + 0x20);
  if (*(uint *)(in_ECX + 0x24) <= uVar4) {
    uVar4 = uVar4 + (-1 - (*(uint *)(in_ECX + 0x20) >> 1));
  }
  iVar3 = *(int *)(in_ECX + 0x14);
  iVar1 = uVar4 * 4;
  piVar2 = *(int **)(iVar1 + iVar3);
  while ((param_2 == piVar2 &&
         (*(undefined4 *)(iVar1 + iVar3) = **(undefined4 **)(iVar1 + iVar3), uVar4 != 0))) {
    iVar3 = *(int *)(in_ECX + 0x14);
    uVar4 = uVar4 - 1;
    iVar1 = uVar4 * 4;
    piVar2 = *(int **)(iVar1 + iVar3);
  }
  if (param_2 == *(int **)(in_ECX + 8)) {
    *param_1 = *param_2;
    return;
  }
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  if ((void *)param_2[4] == (void *)0x0) {
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[4]);
  return;
}


// ==== FUN_005cddc0 @ 0x005cddc0 ====

void FUN_005cddc0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00982b80;
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
      uVar5 = FUN_005cd770(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_005cd790(uVar5,param_2,&local_18);
      FUN_005cd770(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_005cd570(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_005cd790(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_005cd570(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005cdf21 @ 0x005cdf21 ====

void Catch_005cdf21(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_005ce010 @ 0x005ce010 ====

void FUN_005ce010(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982b90;
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
    uVar2 = FUN_005cd790(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005ce0a4 @ 0x005ce0a4 ====

void Catch_005ce0a4(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005ce0c0 @ 0x005ce0c0 ====

void FUN_005ce0c0(uint param_1,undefined1 param_2)

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
    FUN_005cddc0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_005ce130 @ 0x005ce130 ====

/* WARNING: Removing unreachable block (ram,0x005ce14b) */
/* WARNING: Removing unreachable block (ram,0x005ce150) */
/* WARNING: Removing unreachable block (ram,0x005ce15e) */

void FUN_005ce130(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_005cddc0(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_005ce180 @ 0x005ce180 ====

void FUN_005ce180(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = *param_3;
  FUN_00430c20(param_3 + 1);
  return;
}


// ==== FUN_005ce1b0 @ 0x005ce1b0 ====

void * FUN_005ce1b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982ba0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x1c);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_005ce180(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@005ce21d @ 0x005ce21d ====

void Catch_005ce21d(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005ce240 @ 0x005ce240 ====

void FUN_005ce240(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = *param_3;
  FUN_00594840(param_3 + 1);
  return;
}


// ==== FUN_005ce270 @ 0x005ce270 ====

void FUN_005ce270(undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int in_ECX;
  
  piVar3 = param_3;
  piVar2 = param_2;
  if ((param_2 == (int *)**(int **)(in_ECX + 8)) && (param_3 == *(int **)(in_ECX + 8))) {
    FUN_00897490();
    param_2 = *(int **)(in_ECX + 8);
    FUN_005ce130(9,&param_2);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    *param_1 = **(undefined4 **)(in_ECX + 8);
    return;
  }
  while (piVar2 != piVar3) {
    piVar1 = (int *)*piVar2;
    FUN_005cdd10(&param_2,piVar2);
    piVar2 = piVar1;
  }
  *param_1 = piVar2;
  return;
}


// ==== FUN_005ce2f0 @ 0x005ce2f0 ====

void * FUN_005ce2f0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982bb0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x18);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_005ce240(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@005ce35d @ 0x005ce35d ====

void Catch_005ce35d(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005ce3e0 @ 0x005ce3e0 ====

/* WARNING: Removing unreachable block (ram,0x005ce4c8) */

void FUN_005ce3e0(int *param_1,uint *param_2)

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
      FUN_005ce0c0(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
  iVar5 = FUN_005ce1b0(puVar7,puVar7[1],param_2);
  FUN_00897400(1);
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


// ==== FUN_005ce610 @ 0x005ce610 ====

/* WARNING: Removing unreachable block (ram,0x005ce6f8) */

void FUN_005ce610(int *param_1,uint *param_2)

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
      FUN_005ce0c0(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
  iVar5 = FUN_005ce2f0(puVar7,puVar7[1],param_2);
  FUN_005a1420(1);
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


// ==== FUN_005ce840 @ 0x005ce840 ====

undefined4 * FUN_005ce840(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *extraout_EAX;
  int in_ECX;
  undefined1 local_24 [8];
  undefined1 local_1c [4];
  int local_18;
  undefined4 local_14;
  undefined4 local_10 [2];
  undefined4 *local_8;
  
  puVar1 = param_1;
  FUN_00897340(&param_1,param_1);
  if (param_1 == *(undefined4 **)(in_ECX + 8)) {
    local_18 = FUN_00751a80();
    *(undefined1 *)(local_18 + 0x11) = 1;
    *(int *)(local_18 + 4) = local_18;
    *(int *)local_18 = local_18;
    *(int *)(local_18 + 8) = local_18;
    local_10[0] = *puVar1;
    local_14 = 0;
    FUN_00594840(local_1c);
    FUN_005ce610(local_24,local_10);
    FUN_00467860(&param_1,*local_8,local_8);
    _free(local_8);
    return extraout_EAX;
  }
  return param_1 + 3;
}


// ==== FUN_005ce930 @ 0x005ce930 ====

void FUN_005ce930(byte param_1)

{
  void *in_ECX;
  
  FUN_005cd9c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ce950 @ 0x005ce950 ====

void FUN_005ce950(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int *in_ECX;
  
  (**(code **)(*(int *)in_ECX[*in_ECX + 2] + 4))
            (in_ECX[1],param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== FUN_005ce990 @ 0x005ce990 ====

void FUN_005ce990(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  return;
}


// ==== FUN_005ce9a0 @ 0x005ce9a0 ====

void FUN_005ce9a0(void)

{
  FUN_005d6810();
  return;
}


// ==== FUN_005ce9b0 @ 0x005ce9b0 ====

void FUN_005ce9b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  if (param_4 == '\0') {
    FUN_005d6ce0();
  }
  FUN_005d6d50(param_1,param_2,param_3);
  return;
}


// ==== FUN_005ce9e0 @ 0x005ce9e0 ====

void FUN_005ce9e0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  return;
}


// ==== FUN_005cea00 @ 0x005cea00 ====

void FUN_005cea00(void)

{
  int in_ECX;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(in_ECX + 8);
  iVar2 = 2;
  do {
    if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar1)(1);
    }
    *piVar1 = 0;
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== FUN_005cea30 @ 0x005cea30 ====

void FUN_005cea30(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  
  puVar1 = operator_new(0x3c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009c30e0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = DAT_0099d080;
    puVar1[8] = 0;
    puVar1[0xc] = 0;
    puVar1[0xd] = 0;
    puVar1[0xe] = 0;
  }
  *(undefined4 **)(in_ECX + 8) = puVar1;
  pvVar2 = operator_new(0x24);
  if (pvVar2 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  uVar3 = FUN_005d6d30();
  *(undefined4 *)(in_ECX + 0xc) = uVar3;
  return;
}


// ==== FUN_005ceab0 @ 0x005ceab0 ====

void FUN_005ceab0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c30e0;
  FUN_00412dc0();
  *in_ECX = &PTR_FUN_009c26fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ceae0 @ 0x005ceae0 ====

void FUN_005ceae0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  uVar1 = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_2;
  *(undefined4 *)(in_ECX + 0x10) = param_3;
  *(undefined4 *)(in_ECX + 8) = uVar1;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  return;
}


// ==== FUN_005ceb30 @ 0x005ceb30 ====

void FUN_005ceb30(void)

{
  int in_ECX;
  float fVar1;
  float fVar2;
  float in_stack_00000010;
  undefined4 in_stack_00000018;
  float local_18;
  float local_14;
  float local_8;
  float local_4;
  
  local_14 = *(float *)(in_ECX + 0x14);
  if (local_14 < *(float *)(in_ECX + 0x10)) {
    in_stack_00000010 = in_stack_00000010 + local_14;
    *(float *)(in_ECX + 0x14) = in_stack_00000010;
    if (in_stack_00000010 < *(float *)(in_ECX + 0x10) ||
        in_stack_00000010 == *(float *)(in_ECX + 0x10)) {
      fVar1 = *(float *)(in_ECX + 0x14);
    }
    else {
      fVar1 = *(float *)(in_ECX + 0x10);
    }
    fVar2 = *(float *)(in_ECX + 0x10) * DAT_0099d0b4;
    if (fVar2 <= local_14) {
      local_14 = *(float *)(in_ECX + 0x10) - local_14;
      local_18 = local_14 * *(float *)(in_ECX + 4);
      local_14 = *(float *)(in_ECX + 8) * local_14;
    }
    else {
      local_18 = *(float *)(in_ECX + 4) * local_14;
      local_14 = *(float *)(in_ECX + 8) * local_14;
    }
    local_4 = local_14;
    local_8 = local_18;
    if (fVar2 <= fVar1) {
      fVar1 = *(float *)(in_ECX + 0x10) - fVar1;
      local_18 = *(float *)(in_ECX + 4) * fVar1;
      local_14 = *(float *)(in_ECX + 8) * fVar1;
    }
    else {
      local_18 = *(float *)(in_ECX + 4) * fVar1;
      local_14 = *(float *)(in_ECX + 8) * fVar1;
    }
    local_8 = local_18 - local_8;
    local_4 = local_14 - local_4;
    (**(code **)(*DAT_00b5a6b4 + 0x30))(&local_8,in_stack_00000018);
  }
  return;
}


// ==== FUN_005cec80 @ 0x005cec80 ====

void FUN_005cec80(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_005cec90 @ 0x005cec90 ====

void FUN_005cec90(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = DAT_0099d080;
  *in_ECX = &PTR_FUN_009c30ec;
  in_ECX[1] = uVar1;
  in_ECX[2] = 0;
  return;
}


// ==== FUN_005cecb0 @ 0x005cecb0 ====

void FUN_005cecb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c30ec;
  (**(code **)(*DAT_00b5ae50 + 0xc))(in_ECX[2]);
  return;
}


// ==== FUN_005cecd0 @ 0x005cecd0 ====

void FUN_005cecd0(void)

{
  int in_ECX;
  
  (**(code **)(*DAT_00b5ae50 + 0xc))(*(undefined4 *)(in_ECX + 8));
  return;
}


// ==== FUN_005cecf0 @ 0x005cecf0 ====

void FUN_005cecf0(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 unaff_retaddr;
  
  (**(code **)(*DAT_00b5ae50 + 0xc))(*(undefined4 *)(in_ECX + 8));
  uVar1 = (**(code **)(*DAT_00b5ae50 + 8))(unaff_retaddr);
  *(undefined4 *)(in_ECX + 8) = uVar1;
  return;
}


// ==== FUN_005ced20 @ 0x005ced20 ====

float10 FUN_005ced20(undefined4 param_1)

{
  float *pfVar1;
  float *pfVar2;
  int in_ECX;
  undefined4 unaff_retaddr;
  undefined1 local_10 [16];
  
  if (*(int *)(in_ECX + 8) == 0) {
    return (float10)DAT_0099cdc8;
  }
  pfVar1 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 8))(local_10,param_1);
  pfVar2 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 8))(local_10,unaff_retaddr);
  return SQRT(((float10)*pfVar2 - (float10)*pfVar1) * ((float10)*pfVar2 - (float10)*pfVar1) +
              ((float10)pfVar2[1] - (float10)pfVar1[1]) * ((float10)pfVar2[1] - (float10)pfVar1[1]))
         * (float10)*(float *)(in_ECX + 4);
}


// ==== FUN_005ced90 @ 0x005ced90 ====

void FUN_005ced90(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  int in_ECX;
  float10 fVar6;
  undefined1 *puStack_28;
  float fStack_24;
  undefined1 auStack_18 [8];
  undefined1 local_10 [4];
  float *pfStack_c;
  undefined4 uStack_8;
  float fStack_4;
  
  if (*(int *)(in_ECX + 8) == 0) {
    param_1[1] = 0;
    *param_1 = 0;
    return;
  }
  fStack_24 = (float)param_3;
  puStack_28 = local_10;
  pfVar4 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
  pfVar5 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 8))(local_10,param_2);
  puStack_28 = (undefined1 *)(*pfVar5 - *pfVar4);
  fStack_24 = pfVar5[1] - pfVar4[1];
  fVar3 = SQRT(fStack_24 * fStack_24 + (float)puStack_28 * (float)puStack_28);
  fStack_4 = fStack_24;
  fVar6 = (float10)FUN_0040d5f0(uStack_8);
  fStack_4 = (float)fVar6;
  fVar6 = (float10)FUN_0040d5f0(&puStack_28);
  pfVar4 = (float *)FUN_0040d600(auStack_18,(float)(fVar6 + (float10)fStack_4));
  fVar1 = *pfVar4;
  fVar2 = *(float *)(in_ECX + 4);
  pfStack_c[1] = pfVar4[1] * fVar3 * fVar2;
  *pfStack_c = fVar3 * fVar1 * fVar2;
  return;
}


// ==== FUN_005cee80 @ 0x005cee80 ====

undefined4 * FUN_005cee80(undefined4 *param_1)

{
  undefined4 *extraout_EAX;
  undefined4 *puVar1;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 8) == 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[10] = 0xf;
    param_1[9] = 0;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    *(undefined1 *)(param_1 + 5) = 0;
    FUN_00401660(local_1c,0,0xffffffff);
    if (0xf < local_4) {
      _free(local_18);
      return extraout_EAX;
    }
  }
  else {
    puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 4))();
    *param_1 = *puVar1;
    param_1[1] = puVar1[1];
    param_1[2] = puVar1[2];
    param_1[3] = puVar1[3];
    param_1[10] = 0xf;
    param_1[9] = 0;
    *(undefined1 *)(param_1 + 5) = 0;
    FUN_00401660(puVar1 + 4,0,0xffffffff);
  }
  return param_1;
}


// ==== FUN_005cf0b0 @ 0x005cf0b0 ====

void FUN_005cf0b0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009c30ec;
  (**(code **)(*DAT_00b5ae50 + 0xc))(in_ECX[2]);
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005cf0e0 @ 0x005cf0e0 ====

undefined4 FUN_005cf0e0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    return 0xffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x005cf0eb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  return uVar1;
}


// ==== FUN_005cf100 @ 0x005cf100 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005cf100(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  int in_ECX;
  int *piVar6;
  float10 fVar7;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  float fStack_c;
  int iStack_8;
  float fStack_4;
  
  if ((*(int *)(in_ECX + 0x10) != 0) &&
     ((*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x10)) / 0x1c != 0)) {
    (**(code **)(*param_1 + 0x6c))();
    piVar1 = *(int **)(in_ECX + 0x14);
    for (piVar6 = *(int **)(in_ECX + 0x10); piVar6 != piVar1; piVar6 = piVar6 + 7) {
      iVar2 = piVar6[3];
      iVar3 = *piVar6;
      fVar4 = (float)iVar2;
      if (iVar2 < 0) {
        fVar4 = fVar4 + _DAT_0099d104;
      }
      fVar5 = (float)iVar3;
      if (iVar3 < 0) {
        fVar5 = fVar5 + _DAT_0099d104;
      }
      fVar7 = (float10)FUN_005aa2a0((int)ROUND((DAT_0099d080 - fVar4 / fVar5) * DAT_009bf5a0),
                                    iVar3 - iVar2);
      fStack_4 = (float)fVar7;
      fVar4 = (float)piVar6[3];
      if (piVar6[3] < 0) {
        fVar4 = fVar4 + _DAT_0099d104;
      }
      fVar5 = (float)*piVar6;
      if (*piVar6 < 0) {
        fVar5 = fVar5 + _DAT_0099d104;
      }
      iStack_8 = piVar6[2];
      iStack_18 = piVar6[4];
      iStack_14 = piVar6[5];
      iStack_10 = piVar6[6];
      fStack_c = (fVar4 / fVar5 + DAT_0099d080) * (float)piVar6[1] * DAT_0099d0b4;
      FUN_005cfed0(&iStack_18);
    }
  }
  return;
}


// ==== FUN_005cf230 @ 0x005cf230 ====

undefined4 FUN_005cf230(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int in_ECX;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  float10 fVar8;
  int iStack_60;
  float fStack_5c;
  float fStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 local_40 [44];
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (((*(int *)(in_ECX + 0x10) != 0) &&
      ((*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x10)) / 0x1c != 0)) &&
     (puVar6 = *(uint **)(in_ECX + 0x10), puVar6 != *(uint **)(in_ECX + 0x14))) {
    do {
      puVar6[3] = puVar6[3] + param_1;
      if (*puVar6 < puVar6[3]) {
        puVar1 = *(uint **)(in_ECX + 0x14);
        if (puVar6 + 7 != puVar1) {
          puVar2 = puVar6 + 7;
          puVar5 = puVar6;
          do {
            puVar3 = puVar2 + 7;
            puVar7 = puVar5;
            for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar7 = *puVar2;
              puVar2 = puVar2 + 1;
              puVar7 = puVar7 + 1;
            }
            puVar2 = puVar3;
            puVar5 = puVar5 + 7;
          } while (puVar3 != puVar1);
        }
        *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + -0x1c;
      }
      else {
        puVar6 = puVar6 + 7;
      }
    } while (puVar6 != *(uint **)(in_ECX + 0x14));
  }
  if ((*(char *)(in_ECX + 0x40) != '\0') &&
     (*(int *)(in_ECX + 0x3c) = *(int *)(in_ECX + 0x3c) + param_1,
     *(uint *)(in_ECX + 0x38) <= *(uint *)(in_ECX + 0x3c))) {
    (**(code **)(**(int **)(in_ECX + 8) + 0x2c))(local_40);
    fVar8 = (float10)FUN_0040d0a0(0x3f800000,0x40000000);
    uStack_54 = 0;
    uStack_50 = uStack_14;
    uStack_4c = uStack_10;
    iStack_60 = (int)ROUND((float10)DAT_009b012c * fVar8);
    uStack_48 = uStack_c;
    fStack_5c = (float)(fVar8 + fVar8);
    fVar8 = (float10)FUN_0040d0a0(0,0x40490fdb);
    fStack_58 = (float)fVar8;
    FUN_005cff60(&iStack_60);
    *(undefined4 *)(in_ECX + 0x3c) = 0;
  }
  return 1;
}


// ==== FUN_005cf3a0 @ 0x005cf3a0 ====

void FUN_005cf3a0(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009c3120;
  if ((void *)in_ECX[4] == (void *)0x0) {
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    FUN_004b9680(local_4,*(undefined4 *)in_ECX[0x12],(undefined4 *)in_ECX[0x12]);
    _free((void *)in_ECX[0x12]);
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_005cf430 @ 0x005cf430 ====

void FUN_005cf430(undefined4 param_1)

{
  int iVar1;
  undefined4 *in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10 [4];
  void *local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009c3120;
  in_ECX[2] = param_1;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[0xd] = 0xf;
  in_ECX[0xc] = 0;
  *(undefined1 *)(in_ECX + 8) = 0;
  in_ECX[0xe] = 500;
  in_ECX[0xf] = 0;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  iVar1 = FUN_0058b910();
  in_ECX[0x12] = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(undefined4 *)(in_ECX[0x12] + 4) = in_ECX[0x12];
  *(undefined4 *)in_ECX[0x12] = in_ECX[0x12];
  *(undefined4 *)(in_ECX[0x12] + 8) = in_ECX[0x12];
  in_ECX[0x13] = 0;
  local_c = (void *)0x0;
  local_8 = 0;
  local_4 = 0;
  local_18 = 0;
  local_14 = 0;
  FUN_004b9b70(&local_18);
  local_18 = 200;
  local_14 = DAT_0099d080;
  FUN_004b9b70(&local_18);
  local_18 = 800;
  local_14 = DAT_009c16c0;
  FUN_004b9b70(&local_18);
  local_18 = 999;
  local_14 = 0;
  FUN_004b9b70(&local_18);
  FUN_004b9a80(0,1000,local_10);
  if (local_c == (void *)0x0) {
    return;
  }
  _free(local_c);
  return;
}


// ==== FUN_005cf550 @ 0x005cf550 ====

void FUN_005cf550(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  while (param_1 != param_2) {
    puVar1 = param_1 + 7;
    puVar3 = param_3;
    puVar4 = param_1;
    for (iVar2 = 7; param_1 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


// ==== FUN_005cf580 @ 0x005cf580 ====

void FUN_005cf580(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  while (param_1 != param_2) {
    param_2 = param_2 + -7;
    param_3 = param_3 + -7;
    puVar2 = param_2;
    puVar3 = param_3;
    for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}


// ==== FUN_005cf5b0 @ 0x005cf5b0 ====

void FUN_005cf5b0(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}


// ==== FUN_005cf5d0 @ 0x005cf5d0 ====

int FUN_005cf5d0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982bc0;
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


// ==== Catch@005cf636 @ 0x005cf636 ====

void Catch_005cf636(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005cf640 @ 0x005cf640 ====

int FUN_005cf640(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982bd0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x1c) {
    FUN_005cf5b0(param_3,param_1);
    param_3 = param_3 + 0x1c;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@005cf6a6 @ 0x005cf6a6 ====

void Catch_005cf6a6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005cf6b0 @ 0x005cf6b0 ====

void FUN_005cf6b0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982be0;
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


// ==== Catch@005cf716 @ 0x005cf716 ====

void Catch_005cf716(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005cf720 @ 0x005cf720 ====

void FUN_005cf720(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982bf0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_005cf5b0(param_1,param_3);
    param_1 = param_1 + 0x1c;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005cf786 @ 0x005cf786 ====

void Catch_005cf786(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005cf790 @ 0x005cf790 ====

void FUN_005cf790(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005cf5d0(param_1,param_2,param_3);
  return;
}


// ==== FUN_005cf7b0 @ 0x005cf7b0 ====

void FUN_005cf7b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005cf640(param_1,param_2,param_3);
  return;
}


// ==== FUN_005cf7d0 @ 0x005cf7d0 ====

int FUN_005cf7d0(int param_1,int param_2,undefined4 param_3)

{
  FUN_005cf6b0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x18;
}


// ==== FUN_005cf800 @ 0x005cf800 ====

int FUN_005cf800(int param_1,int param_2,undefined4 param_3)

{
  FUN_005cf720(param_1,param_2,param_3);
  return param_1 + param_2 * 0x1c;
}


// ==== FUN_005cf830 @ 0x005cf830 ====

void FUN_005cf830(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00982c00;
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
      local_1c = FUN_005cf790(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_1c = FUN_005cf7d0(local_1c,param_2,&local_50);
      FUN_005cf790(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
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
      FUN_005cf5d0(param_1,local_28,local_24 + param_1);
      local_8 = 2;
      FUN_005cf7d0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x18,&local_50)
      ;
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_24;
      FUN_004dcf10(param_1,*(int *)(in_ECX + 8) - local_24,&local_50);
      ExceptionList = local_10;
      return;
    }
    local_2c = local_28 + param_2 * -0x18;
    uVar4 = FUN_005cf5d0(local_2c,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_0085d5a0(param_1,local_2c,local_28,local_38);
    FUN_004dcf10(param_1,param_2 * 0x18 + param_1,&local_50);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005cf9f1 @ 0x005cf9f1 ====

void Catch_005cf9f1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005cfb00 @ 0x005cfb00 ====

void FUN_005cfb00(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  uint extraout_ECX;
  undefined4 *puVar3;
  undefined4 local_50;
  int local_2c;
  int local_28;
  uint local_24;
  undefined4 local_20;
  void *local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982c10;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x5c);
  puVar3 = &local_50;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_3;
    param_3 = param_3 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x1c;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x1c;
    }
    ExceptionList = &local_10;
    if (0x9249249U - iVar2 < param_2) {
      ExceptionList = &local_10;
      FUN_0085b3b0();
      local_24 = extraout_ECX;
    }
    if (*(int *)(in_ECX + 4) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x1c;
    }
    if (local_24 < iVar2 + param_2) {
      if (0x9249249 - (local_24 >> 1) < local_24) {
        local_24 = 0;
      }
      else {
        local_24 = local_24 + (local_24 >> 1);
      }
      if (*(int *)(in_ECX + 4) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x1c;
      }
      if (local_24 < iVar2 + param_2) {
        iVar2 = FUN_00405820();
        local_24 = iVar2 + param_2;
      }
      local_24 = local_24 * 0x1c;
      local_1c = operator_new(local_24);
      local_8 = 0;
      local_20 = FUN_005cf7b0(*(undefined4 *)(in_ECX + 4),param_1,local_1c);
      local_20 = FUN_005cf800(local_20,param_2,&local_50);
      FUN_005cf7b0(param_1,*(undefined4 *)(in_ECX + 8),local_20);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x1c;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_24 + (int)local_1c;
        *(void **)(in_ECX + 8) = (void *)((int)local_1c + (param_2 + iVar2) * 0x1c);
        *(void **)(in_ECX + 4) = local_1c;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_2c = *(int *)(in_ECX + 8);
    local_28 = local_2c - param_1;
    if ((uint)(local_28 / 0x1c) < param_2) {
      local_18 = param_2 * 0x1c;
      FUN_005cf640(param_1,local_2c,local_18 + param_1);
      local_8 = 2;
      FUN_005cf800(*(undefined4 *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x1c,
                   &local_50);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_18;
      FUN_005cf550(param_1,*(int *)(in_ECX + 8) - local_18,&local_50);
      ExceptionList = local_10;
      return;
    }
    local_18 = param_2 * 0x1c;
    iVar2 = local_2c + param_2 * -0x1c;
    uVar1 = FUN_005cf640(iVar2,local_2c,local_2c);
    *(undefined4 *)(in_ECX + 8) = uVar1;
    FUN_005cf580(param_1,iVar2,local_2c);
    FUN_005cf550(param_1,local_18 + param_1,&local_50);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005cfcc3 @ 0x005cfcc3 ====

void Catch_005cfcc3(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_005cfde0 @ 0x005cfde0 ====

void FUN_005cfde0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x18 != 0) {
      iVar1 = (param_2 - iVar1) / 0x18;
      goto LAB_005cfe25;
    }
  }
  iVar1 = 0;
LAB_005cfe25:
  FUN_005cf830(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x18;
  return;
}


// ==== FUN_005cfe50 @ 0x005cfe50 ====

void FUN_005cfe50(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x1c != 0) {
      iVar1 = (param_2 - iVar1) / 0x1c;
      goto LAB_005cfe99;
    }
  }
  iVar1 = 0;
LAB_005cfe99:
  FUN_005cfb00(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x1c;
  return;
}


// ==== FUN_005cfed0 @ 0x005cfed0 ====

void FUN_005cfed0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x18) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x18))) {
    FUN_005cfde0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_005cf6b0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x18;
  return;
}


// ==== FUN_005cff60 @ 0x005cff60 ====

void FUN_005cff60(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x1c) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x1c))) {
    FUN_005cfe50(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_005cf720(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x1c;
  return;
}


// ==== FUN_005cfff0 @ 0x005cfff0 ====

void FUN_005cfff0(byte param_1)

{
  void *in_ECX;
  
  FUN_005cf3a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


