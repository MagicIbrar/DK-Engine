// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x940000-0x94ffff

// ==== FUN_00941b98 @ 0x00941b98 ====

undefined4 FUN_00941b98(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + uVar5 * 4);
      iVar2 = *(int *)(iVar1 + 0x38);
      if (iVar2 != -1) {
        iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + iVar2 * 4);
        iVar4 = iVar2;
        while (*(int *)(iVar3 + 0x38) != -1) {
          *(uint *)(iVar1 + 0x3c) = *(uint *)(iVar1 + 0x3c) | *(uint *)(iVar3 + 0x3c);
          iVar4 = *(int *)(iVar3 + 0x38);
          iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4);
        }
        if (iVar2 != iVar4) {
          *(int *)(iVar1 + 0x38) = iVar4;
          FUN_00914f00(iVar3);
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(in_ECX + 8));
  }
  return 0;
}


// ==== FUN_00941be9 @ 0x00941be9 ====

int FUN_00941be9(void)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  int *piVar6;
  int iVar7;
  int in_ECX;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar1 = *(uint **)(in_ECX + 0x100);
  uVar8 = *puVar1 & 0xfff00000;
  if (((((uVar8 == 0x50000000) || (uVar8 == 0x10500000)) || (uVar8 == 0x10600000)) ||
      ((uVar8 == 0x10300000 || (uVar8 == 0x10700000)))) && (puVar1[3] == 1)) {
    iVar7 = *(int *)(in_ECX + 0x14);
    bVar5 = false;
    iVar9 = *(int *)(iVar7 + *(int *)puVar1[4] * 4);
    if (*(int *)(iVar9 + 0x54) != -1) {
      local_c = 0;
      puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar9 + 0x54) * 4);
      local_10 = puVar2[3];
      if (local_10 != 0) {
        piVar6 = (int *)puVar2[4];
        do {
          uVar8 = *(uint *)(*(int *)(iVar7 + *piVar6 * 4) + 0x4c);
          if (local_c < uVar8) {
            local_c = uVar8;
          }
          piVar6 = piVar6 + 1;
          local_10 = local_10 - 1;
        } while (local_10 != 0);
      }
      iVar3 = *(int *)(iVar7 + *(int *)puVar2[4] * 4);
      if (((*(int *)(iVar3 + 4) == *(int *)(iVar9 + 4)) &&
          (*(int *)(iVar3 + 0xc) == *(int *)(iVar9 + 0xc))) &&
         ((*(int *)(iVar3 + 8) == *(int *)(iVar9 + 8) &&
          (*(int *)(iVar9 + 0x54) != *(int *)(iVar9 + 0x58))))) {
        bVar5 = true;
      }
      if ((((local_c <= *(uint *)(in_ECX + 0xfc)) &&
           ((bVar5 || (*(int *)(iVar9 + 0x54) == *(int *)(iVar9 + 0x58))))) &&
          (((*(byte *)(in_ECX + 0x6c) & 1) == 0 ||
           ((puVar2[3] != 0 &&
            (*(int *)(*(int *)(iVar7 + *(int *)puVar2[4] * 4) + 4) != *(int *)(in_ECX + 0x84)))))))
         && (((*puVar2 & 0xfff00000) == 0x10000000 &&
             ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar3 + 4) * 4) + 4) & 4) == 0)
             ))) {
        uVar8 = 0;
        if (puVar2[1] != 0) {
          piVar6 = (int *)puVar2[2];
          do {
            if (*piVar6 != *(int *)puVar1[4]) {
              return 1;
            }
            uVar8 = uVar8 + 1;
            piVar6 = piVar6 + 1;
          } while (uVar8 < puVar2[1]);
        }
        iVar9 = 0;
        if (*(int *)(*(int *)(iVar7 + *(int *)puVar2[2] * 4) + 0x3c) == 0) {
          iVar7 = FUN_009149f7(0x74);
          if (iVar7 != 0) {
            iVar9 = FUN_0091455d();
          }
          if (iVar9 == 0) {
            return -0x7ff8fff2;
          }
          iVar7 = FUN_00914a42(**(undefined4 **)(in_ECX + 0x100),
                               (*(undefined4 **)(in_ECX + 0x100))[1],(uint)bVar5 + puVar2[3],1);
          if (iVar7 < 0) {
            FUN_008f4adb(1);
            return iVar7;
          }
          puVar10 = (undefined4 *)puVar2[4];
          puVar11 = *(undefined4 **)(iVar9 + 0x10);
          for (uVar8 = puVar2[3] & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
            *puVar11 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar11 = puVar11 + 1;
          }
          for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          if (bVar5) {
            *(undefined4 *)(*(int *)(iVar9 + 0x10) + puVar2[3] * 4) =
                 **(undefined4 **)(*(int *)(in_ECX + 0x100) + 0x10);
          }
          uVar8 = *(uint *)(iVar9 + 0xc);
          local_8 = 0;
          if (uVar8 != 0) {
            local_10 = 1;
            do {
              local_c = local_10;
              if (local_10 < uVar8) {
                do {
                  iVar7 = *(int *)(*(int *)(in_ECX + 0x14) +
                                  *(int *)(*(int *)(iVar9 + 0x10) + local_8 * 4) * 4);
                  iVar3 = *(int *)(*(int *)(in_ECX + 0x14) +
                                  *(int *)(local_c * 4 + *(int *)(iVar9 + 0x10)) * 4);
                  if (*(uint *)(iVar3 + 0x10) < *(uint *)(iVar7 + 0x10)) {
                    puVar10 = (undefined4 *)(local_c * 4 + *(int *)(iVar9 + 0x10));
                    uVar4 = *puVar10;
                    *puVar10 = *(undefined4 *)(*(int *)(iVar9 + 0x10) + local_8 * 4);
                    *(undefined4 *)(*(int *)(iVar9 + 0x10) + local_8 * 4) = uVar4;
                  }
                  if (*(int *)(iVar7 + 0x10) == *(int *)(iVar3 + 0x10)) {
                    FUN_0091a001(in_ECX,*(undefined4 *)(*(int *)(in_ECX + 0x100) + 0x3c),0x12d6,
                                 s_internal_error__multiple_write_t_00a2bc14);
                    FUN_008f4adb(1);
                    return -0x7fffbffb;
                  }
                  local_c = local_c + 1;
                } while (local_c < *(uint *)(iVar9 + 0xc));
              }
              local_8 = local_8 + 1;
              uVar8 = *(uint *)(iVar9 + 0xc);
              local_10 = local_10 + 1;
            } while (local_8 < uVar8);
          }
          puVar10 = *(undefined4 **)(*(int *)(in_ECX + 0x100) + 8);
          puVar11 = *(undefined4 **)(iVar9 + 8);
          for (uVar8 = *(uint *)(*(int *)(in_ECX + 0x100) + 4) & 0x3fffffff; uVar8 != 0;
              uVar8 = uVar8 - 1) {
            *puVar11 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar11 = puVar11 + 1;
          }
          for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          if (*(int *)(*(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0xfc) * 4) != 0) {
            FUN_008f4adb(1);
          }
          *(int *)(*(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0xfc) * 4) = iVar9;
          *puVar2 = 0;
          return 0;
        }
      }
      return 1;
    }
  }
  return 1;
}


// ==== FUN_00941ed7 @ 0x00941ed7 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00941ed7(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined1 local_114 [64];
  int local_d4 [4];
  int local_c4 [4];
  int local_b4 [4];
  int local_a4 [28];
  int local_34 [4];
  int local_24 [5];
  int local_10;
  uint local_c;
  int local_8;
  
  local_10 = 0;
  local_24[0] = 0;
  uVar5 = **(uint **)(in_ECX + 0x100) & 0xfffff;
  local_24[1] = 1;
  local_24[2] = 2;
  local_24[3] = 3;
  local_24[4] = in_ECX;
  iVar2 = FUN_0093d430(*(uint **)(in_ECX + 0x100),&DAT_00a2c8f8,local_114,&local_10,local_d4,
                       local_24,uVar5,1);
  if (iVar2 == 0) {
    iVar2 = FUN_009149f7(0x74);
    if (iVar2 == 0) {
      local_c = 0;
    }
    else {
      local_c = FUN_0091455d();
    }
    if (local_c == 0) {
      return -0x7ff8fff2;
    }
    uVar3 = uVar5 | 0x73600000;
  }
  else {
    iVar2 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2c958,local_114,&local_10,local_d4,
                         local_24,uVar5,1);
    if (iVar2 != 0) {
      iVar2 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2c9b8,local_114,&local_10,
                           local_d4,local_24,uVar5,1);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = *(int *)(in_ECX + 0x14);
      if (*(int *)(*(int *)(iVar2 + local_b4[0] * 4) + 0x3c) == 0x80000) {
        uVar3 = 0;
        if (uVar5 != 0) {
          piVar7 = local_a4;
          piVar9 = local_24;
          for (uVar4 = uVar5; uVar4 != 0; uVar4 = uVar4 - 1) {
            *piVar9 = *piVar7;
            piVar7 = piVar7 + 1;
            piVar9 = piVar9 + 1;
          }
          do {
            local_34[uVar3] = *(int *)(*(int *)(iVar2 + local_b4[uVar3] * 4) + 0x38);
            uVar3 = uVar3 + 1;
          } while (uVar3 < uVar5);
LAB_00942106:
          in_ECX = local_24[4];
        }
      }
      else {
        if (*(int *)(*(int *)(iVar2 + local_a4[0] * 4) + 0x3c) != 0x80000) {
          return 1;
        }
        uVar3 = 0;
        if (uVar5 != 0) {
          piVar7 = local_b4;
          piVar9 = local_24;
          for (uVar4 = uVar5; uVar4 != 0; uVar4 = uVar4 - 1) {
            *piVar9 = *piVar7;
            piVar7 = piVar7 + 1;
            piVar9 = piVar9 + 1;
          }
          do {
            local_34[uVar3] = *(int *)(*(int *)(iVar2 + local_a4[uVar3] * 4) + 0x38);
            uVar3 = uVar3 + 1;
          } while (uVar3 < uVar5);
          goto LAB_00942106;
        }
      }
      local_c = 0;
      local_10 = 1;
      local_8 = 1;
      if (uVar5 != 0) {
        do {
          iVar1 = *(int *)(iVar2 + local_d4[local_c] * 4);
          if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar1 + 4) * 4) + 5) & 1) == 0)
          {
            local_8 = 0;
            local_10 = 0;
          }
          if (*(double *)(iVar1 + 0x20) != _DAT_0099d098) {
            local_8 = 0;
          }
          if (*(double *)(iVar1 + 0x20) != _DAT_0099d0a0) {
            local_10 = 0;
          }
          iVar1 = *(int *)(iVar2 + local_c4[local_c] * 4);
          if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar1 + 4) * 4) + 5) & 1) == 0)
          {
            local_8 = 0;
            local_10 = 0;
          }
          if (*(double *)(iVar1 + 0x20) != _DAT_0099d0a0) {
            local_8 = 0;
          }
          if (*(double *)(iVar1 + 0x20) != _DAT_0099d098) {
            local_10 = 0;
          }
          local_c = local_c + 1;
        } while (local_c < uVar5);
        if ((local_8 == 0) && (local_10 == 0)) {
          return 1;
        }
      }
      iVar2 = FUN_009149f7(0x74);
      if (iVar2 == 0) {
        local_c = 0;
      }
      else {
        local_c = FUN_0091455d();
      }
      uVar3 = local_c;
      if (local_c == 0) {
        return -0x7ff8fff2;
      }
      if (local_8 == 0) {
        uVar4 = uVar5 | 0x73500000;
      }
      else {
        uVar4 = uVar5 | 0x73600000;
      }
      local_8 = FUN_00914a42(uVar4,uVar5 * 2,uVar5,0);
      if (-1 < local_8) {
        local_8 = FUN_00914593(*(undefined4 *)(in_ECX + 0x100));
        if (local_8 < 0) goto LAB_0094224e;
        puVar6 = *(undefined4 **)(*(int *)(in_ECX + 0x100) + 0x10);
        puVar8 = *(undefined4 **)(uVar3 + 0x10);
        for (uVar4 = uVar5; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar8 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar8 = puVar8 + 1;
        }
        for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
          *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        }
        piVar7 = local_24;
        piVar9 = *(int **)(local_c + 8);
        for (uVar3 = uVar5; uVar3 != 0; uVar3 = uVar3 - 1) {
          *piVar9 = *piVar7;
          piVar7 = piVar7 + 1;
          piVar9 = piVar9 + 1;
        }
        for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
          *(char *)piVar9 = (char)*piVar7;
          piVar7 = (int *)((int)piVar7 + 1);
          piVar9 = (int *)((int)piVar9 + 1);
        }
        piVar7 = local_34;
        goto LAB_00942295;
      }
      goto LAB_0094224e;
    }
    iVar2 = FUN_009149f7(0x74);
    if (iVar2 == 0) {
      local_c = 0;
    }
    else {
      local_c = FUN_0091455d();
    }
    if (local_c == 0) {
      return -0x7ff8fff2;
    }
    uVar3 = uVar5 | 0x73500000;
  }
  uVar4 = local_c;
  local_8 = FUN_00914a42(uVar3,uVar5 * 2,uVar5,0);
  if (-1 < local_8) {
    local_8 = FUN_00914593(*(undefined4 *)(in_ECX + 0x100));
    if (-1 < local_8) {
      puVar6 = *(undefined4 **)(*(int *)(in_ECX + 0x100) + 0x10);
      puVar8 = *(undefined4 **)(uVar4 + 0x10);
      for (uVar3 = uVar5; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      piVar7 = local_d4;
      piVar9 = *(int **)(local_c + 8);
      for (uVar3 = uVar5; uVar3 != 0; uVar3 = uVar3 - 1) {
        *piVar9 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar9 = piVar9 + 1;
      }
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(char *)piVar9 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar9 = (int *)((int)piVar9 + 1);
      }
      piVar7 = local_c4;
LAB_00942295:
      piVar9 = (int *)(*(int *)(local_c + 8) + uVar5 * 4);
      for (; uVar5 != 0; uVar5 = uVar5 - 1) {
        *piVar9 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar9 = piVar9 + 1;
      }
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(char *)piVar9 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar9 = (int *)((int)piVar9 + 1);
      }
      iVar2 = FUN_00914ca1(local_c);
      FUN_008f4adb(1);
      return iVar2;
    }
  }
LAB_0094224e:
  FUN_008f4adb(1);
  return local_8;
}


// ==== FUN_009422cd @ 0x009422cd ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_009422cd(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 local_10c [64];
  undefined4 local_cc [4];
  int local_bc;
  int local_ac;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_28 = 1;
  uVar4 = **(uint **)(in_ECX + 0x100) & 0xfffff;
  local_c = 0;
  local_2c = 0;
  local_24 = 2;
  local_20 = 3;
  local_1c = in_ECX;
  iVar1 = FUN_0093d430(*(uint **)(in_ECX + 0x100),&DAT_00a2c558,local_10c,&local_c,local_cc,
                       &local_2c,uVar4,1);
  if (iVar1 != 0) {
    return iVar1;
  }
  local_c = 0;
  local_10 = 0;
  local_14 = 0;
  local_8 = 0;
  if (uVar4 != 0) {
    iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + local_bc * 4);
    iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + local_ac * 4);
    local_18 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar1 + 4) * 4) + 4) & 0x100;
    do {
      if (local_18 == 0) {
        return 1;
      }
      if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar3 + 4) * 4) + 5) & 1) == 0) {
        return 1;
      }
      if (*(int *)(iVar1 + 8) != -1) {
        return 1;
      }
      if (*(int *)(iVar3 + 8) != -1) {
        return 1;
      }
      if ((*(double *)(iVar1 + 0x20) == _DAT_0099d0a0) &&
         (*(double *)(iVar3 + 0x20) == _DAT_0099d098)) {
        local_c = 1;
      }
      else {
        if (*(double *)(iVar3 + 0x20) != _DAT_0099d0a0) {
          return 1;
        }
        if (*(double *)(iVar1 + 0x20) != _DAT_0099d098) {
          return 1;
        }
        local_10 = 1;
      }
      local_8 = local_8 + 1;
    } while (local_8 < uVar4);
    if (local_c != 0) {
      if (local_10 != 0) {
        return 1;
      }
      local_14 = uVar4 | 0x73500000;
    }
    if (local_10 != 0) {
      local_14 = uVar4 | 0x73600000;
    }
  }
  iVar1 = FUN_009149f7();
  if (iVar1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_0091455d();
  }
  if (local_8 == 0) {
    return -0x7ff8fff2;
  }
  iVar1 = FUN_00914a42(local_14,uVar4 * 2,uVar4,0);
  if ((-1 < iVar1) && (iVar1 = FUN_00914593(), -1 < iVar1)) {
    puVar5 = *(undefined4 **)(*(int *)(in_ECX + 0x100) + 0x10);
    puVar6 = *(undefined4 **)(local_8 + 0x10);
    for (uVar2 = uVar4; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    puVar5 = local_cc;
    puVar6 = *(undefined4 **)(local_8 + 8);
    for (uVar2 = uVar4; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    iVar1 = FUN_00915318(*(undefined4 *)(local_1c + 0x78),0,0,0);
    if (iVar1 == -1) {
      iVar1 = -0x7ff8fff2;
    }
    else {
      if (uVar4 != 0) {
        iVar3 = uVar4 << 2;
        do {
          *(int *)(iVar3 + *(int *)(local_8 + 8)) = iVar1;
          iVar3 = iVar3 + 4;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      iVar1 = FUN_00914ca1();
    }
  }
  FUN_008f4adb();
  return iVar1;
}


// ==== FUN_00942527 @ 0x00942527 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00942527(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  if ((**(uint **)(in_ECX + 0x100) & 0xfffff) == 1) {
    iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)((*(uint **)(in_ECX + 0x100))[2] + 4) * 4);
    if ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar2 + 4) * 4) + 5) & 1) == 0) ||
        (*(int *)(iVar2 + 8) != -1)) || (*(double *)(iVar2 + 0x20) != _DAT_0099d098)) {
      iVar2 = 1;
    }
    else {
      iVar3 = FUN_00915318(0,0,0,0);
      if (iVar3 == -1) {
        iVar2 = -0x7ff8fff2;
      }
      else {
        iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4);
        iVar2 = FUN_00914e44();
        if ((-1 < iVar2) && (iVar2 = FUN_00914f00(), -1 < iVar2)) {
          *(uint *)(iVar1 + 0x3c) = *(uint *)(iVar1 + 0x3c) ^ 0x80000;
          if (*(int *)(iVar1 + 0x38) == -1) {
            *(undefined4 *)(iVar1 + 0x38) = **(undefined4 **)(*(int *)(in_ECX + 0x100) + 8);
          }
          *(int *)(*(int *)(*(int *)(in_ECX + 0x100) + 8) + 4) = iVar3;
          iVar2 = 0;
        }
      }
    }
  }
  else {
    iVar2 = 1;
  }
  return iVar2;
}


// ==== FUN_0094260e @ 0x0094260e ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0094260e(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  undefined1 local_100 [16];
  int aiStack_f0 [4];
  int aiStack_e0 [32];
  undefined1 local_60 [64];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  local_8 = 0;
  local_20 = 0;
  local_10 = 0;
  uVar4 = **(uint **)(in_ECX + 0x100) & 0xfffff;
  local_1c = 1;
  local_18 = 2;
  local_14 = 3;
  iVar1 = FUN_0093d430(*(uint **)(in_ECX + 0x100),&DAT_00a2c738,local_60,&local_8,local_100,
                       &local_20,uVar4,1);
  if (iVar1 == 1) {
    local_10 = 1;
    iVar1 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2c798,local_60,&local_8,local_100,
                         &local_20,uVar4,1);
  }
  if (iVar1 == 0) {
    local_c = 0;
    if (uVar4 != 0) {
      local_8 = uVar4 << 2;
      do {
        if ((((aiStack_f0[local_c] != aiStack_e0[local_c]) ||
             (iVar1 = *(int *)(*(int *)(in_ECX + 0x14) +
                              *(int *)(local_8 + *(int *)(*(int *)(in_ECX + 0x100) + 8)) * 4),
             (*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar1 + 4) * 4) + 5) & 1) == 0))
            || (*(double *)(iVar1 + 0x20) != _DAT_0099d098)) || (*(int *)(iVar1 + 8) != -1)) {
          return 1;
        }
        local_c = local_c + 1;
        local_8 = local_8 + 4;
      } while (local_c < uVar4);
    }
    uVar2 = 0;
    if (local_10 == 0) {
      uVar3 = uVar4 | 0x73800000;
    }
    else {
      uVar3 = uVar4 | 0x73700000;
    }
    **(uint **)(in_ECX + 0x100) = uVar3;
    if (uVar4 != 0) {
      do {
        *(int *)(*(int *)(*(int *)(in_ECX + 0x100) + 8) + uVar2 * 4) = aiStack_f0[uVar2];
        uVar2 = uVar2 + 1;
      } while (uVar2 < uVar4);
    }
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_0094275c @ 0x0094275c ====

int FUN_0094275c(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  undefined1 local_fc [64];
  int local_bc [4];
  int aiStack_ac [4];
  int aiStack_9c [4];
  int aiStack_8c [28];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  local_8 = 0;
  local_1c = 0;
  local_c = 0;
  uVar4 = **(uint **)(in_ECX + 0x100) & 0xfffff;
  local_18 = 1;
  local_14 = 2;
  local_10 = 3;
  iVar2 = FUN_0093d430(*(uint **)(in_ECX + 0x100),&DAT_00a2c7f8,local_fc,&local_8,local_bc,&local_1c
                       ,uVar4,1);
  if (iVar2 == 1) {
    local_c = 1;
    iVar2 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2c878,local_fc,&local_8,local_bc,
                         &local_1c,uVar4,1);
  }
  if (iVar2 == 0) {
    local_8 = 0;
    if (uVar4 != 0) {
      do {
        if (((local_bc[local_8] != aiStack_ac[local_8]) ||
            (aiStack_ac[local_8] != aiStack_9c[local_8])) ||
           (local_bc[local_8] != aiStack_8c[local_8])) {
          return 1;
        }
        local_8 = local_8 + 1;
      } while (local_8 < uVar4);
    }
    if (local_c == 0) {
      uVar3 = uVar4 | 0x73800000;
    }
    else {
      uVar3 = uVar4 | 0x73700000;
    }
    **(uint **)(in_ECX + 0x100) = uVar3;
    local_c = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,0);
    if (local_c == -1) {
      iVar2 = -0x7ff8fff2;
    }
    else {
      uVar3 = 0;
      if (uVar4 != 0) {
        local_8 = uVar4 << 2;
        do {
          uVar1 = local_8;
          local_8 = local_8 + 4;
          *(int *)(*(int *)(*(int *)(in_ECX + 0x100) + 8) + uVar3 * 4) = local_bc[uVar3];
          uVar3 = uVar3 + 1;
          *(int *)(uVar1 + *(int *)(*(int *)(in_ECX + 0x100) + 8)) = local_c;
        } while (uVar3 < uVar4);
      }
      iVar2 = 0;
    }
  }
  return iVar2;
}


// ==== FUN_009428be @ 0x009428be ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_009428be(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  uint uVar3;
  undefined1 local_100 [16];
  undefined4 auStack_f0 [4];
  int local_e0 [32];
  undefined1 local_60 [64];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_20 = 0;
  local_1c = 1;
  local_18 = 2;
  local_14 = 3;
  if ((**(uint **)(in_ECX + 0x100) & 0xfffff) == 1) {
    iVar1 = FUN_0093d430(*(uint **)(in_ECX + 0x100),&DAT_00a2c5b8,local_60,&local_8,local_100,
                         &local_20,1,1);
    if (((iVar1 == 1) &&
        (iVar1 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2c618,local_60,&local_8,
                              local_100,&local_20,1,1), iVar1 == 1)) &&
       (iVar1 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2c678,local_60,&local_8,
                             local_100,&local_20,1,1), iVar1 == 1)) {
      iVar1 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2c6d8,local_60,&local_8,local_100
                           ,&local_20,1,1);
    }
    if (iVar1 == 0) {
      piVar2 = *(int **)(*(int *)(in_ECX + 0x100) + 8);
      local_8 = 0;
      do {
        piVar2 = piVar2 + 1;
        iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar2 * 4);
        if ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar1 + 4) * 4) + 5) & 1) == 0)
            || (*(double *)(iVar1 + 0x20) != _DAT_0099d098)) || (*(int *)(iVar1 + 8) != -1)) {
          return 1;
        }
        local_8 = local_8 + 1;
      } while (local_8 == 0);
      iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + local_e0[0] * 4);
      local_8 = 0;
      if ((*(int *)(iVar1 + 8) == -1) &&
         ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar1 + 4) * 4) + 5) & 1) != 0)) {
        local_8 = 1;
      }
      uVar3 = 0;
      do {
        *(undefined4 *)(uVar3 + *(int *)(*(int *)(in_ECX + 0x100) + 8)) =
             *(undefined4 *)((int)auStack_f0 + uVar3);
        iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)((int)local_e0 + uVar3) * 4);
        local_10 = FUN_00915318(*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 0xc),
                                *(undefined4 *)(iVar1 + 0x10),*(undefined8 *)(iVar1 + 0x20));
        if (local_10 == -1) {
          return -0x7ff8fff2;
        }
        local_c = *(int *)(*(int *)(in_ECX + 0x14) + local_10 * 4);
        FUN_00914e44();
        if (local_8 == 0) {
          if (*(int *)(local_c + 0x38) == -1) {
            *(undefined4 *)(local_c + 0x38) = *(undefined4 *)((int)local_e0 + uVar3);
          }
          *(uint *)(local_c + 0x3c) = *(uint *)(local_c + 0x3c) ^ 0x80000;
        }
        else {
          *(double *)(local_c + 0x20) = *(double *)(local_c + 0x20) * _DAT_009fd350;
        }
        *(int *)(*(int *)(*(int *)(in_ECX + 0x100) + 8) + 4 + uVar3) = local_10;
        uVar3 = uVar3 + 4;
      } while (uVar3 < 4);
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}


// ==== FUN_00942ad6 @ 0x00942ad6 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00942ad6(void)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined1 local_114 [64];
  int local_d4 [4];
  int local_c4 [4];
  int local_b4 [4];
  int local_a4 [28];
  int local_34 [4];
  int local_24;
  int local_20 [7];
  
  local_20[5] = 0;
  local_20[0] = 0;
  uVar5 = **(uint **)(in_ECX + 0x100) & 0xfffff;
  local_20[1] = 1;
  local_20[2] = 2;
  local_20[3] = 3;
  local_20[4] = uVar5;
  iVar3 = FUN_0093d430(*(uint **)(in_ECX + 0x100),&DAT_00a2cdd8,local_114,local_20 + 5,local_d4,
                       local_20,uVar5,1);
  if (iVar3 == 0) {
    iVar3 = FUN_009149f7(0x74);
    if (iVar3 == 0) {
      local_20[6] = 0;
    }
    else {
      local_20[6] = FUN_0091455d();
    }
    if (local_20[6] == 0) {
      return -0x7ff8fff2;
    }
    uVar4 = uVar5 | 0x74600000;
  }
  else {
    iVar3 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2cd78,local_114,local_20 + 5,
                         local_d4,local_20,uVar5,1);
    if (iVar3 != 0) {
      iVar3 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2ce38,local_114,local_20 + 5,
                           local_d4,local_20,uVar5,1);
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar3 = *(int *)(in_ECX + 0x14);
      iVar1 = *(int *)(iVar3 + local_b4[0] * 4);
      local_20[5] = *(int *)(iVar1 + 0x3c);
      if (local_20[5] == 0x80000) {
        uVar4 = 0;
        if (uVar5 != 0) {
          piVar7 = local_a4;
          piVar9 = local_20;
          for (; uVar5 != 0; uVar5 = uVar5 - 1) {
            *piVar9 = *piVar7;
            piVar7 = piVar7 + 1;
            piVar9 = piVar9 + 1;
          }
          do {
            local_34[uVar4] = *(int *)(*(int *)(iVar3 + local_b4[uVar4] * 4) + 0x38);
            uVar4 = uVar4 + 1;
          } while (uVar4 < (uint)local_20[4]);
LAB_00942d1a:
          uVar5 = local_20[4];
        }
      }
      else {
        local_20[6] = *(int *)(iVar3 + local_a4[0] * 4);
        local_24 = *(int *)(local_20[6] + 0x3c);
        if (local_24 == 0x80000) {
          uVar4 = 0;
          if (uVar5 != 0) {
            piVar7 = local_b4;
            piVar9 = local_20;
            for (; uVar5 != 0; uVar5 = uVar5 - 1) {
              *piVar9 = *piVar7;
              piVar7 = piVar7 + 1;
              piVar9 = piVar9 + 1;
            }
            do {
              local_34[uVar4] = *(int *)(*(int *)(iVar3 + local_a4[uVar4] * 4) + 0x38);
              uVar4 = uVar4 + 1;
            } while (uVar4 < (uint)local_20[4]);
            goto LAB_00942d1a;
          }
        }
        else {
          if (uVar5 != 1) {
            return 1;
          }
          iVar3 = *(int *)(iVar1 + 0x48);
          if (iVar3 == -1) {
LAB_00942d72:
            if (*(int *)(local_20[6] + 0x48) == -1) {
              return 1;
            }
            puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(local_20[6] + 0x48) * 4);
            uVar4 = *puVar2;
            if ((uVar4 & 0xfff00000) != 0x10100000) {
              return 1;
            }
            if ((uVar4 & 0xfffff) != 1) {
              return 1;
            }
            if (local_24 != 0) {
              return 1;
            }
            local_34[0] = *(int *)puVar2[2];
            local_a4[0] = local_b4[0];
          }
          else {
            puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar3 * 4);
            uVar4 = *puVar2;
            if ((((uVar4 & 0xfff00000) != 0x10100000) || ((uVar4 & 0xfffff) != 1)) ||
               (local_20[5] != 0)) goto LAB_00942d72;
            local_34[0] = *(int *)puVar2[2];
          }
          local_20[0] = local_a4[0];
        }
      }
      local_20[6] = 0;
      local_20[4] = 1;
      local_20[5] = 1;
      if (uVar5 != 0) {
        do {
          iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + local_d4[local_20[6]] * 4);
          if ((*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar3 + 4) * 4) + 4) & 0x100)
              == 0) {
            local_20[5] = 0;
            local_20[4] = 0;
          }
          if (*(double *)(iVar3 + 0x20) != _DAT_0099d0a0) {
            local_20[5] = 0;
          }
          if (*(double *)(iVar3 + 0x20) != _DAT_0099d098) {
            local_20[4] = 0;
          }
          iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + local_c4[local_20[6]] * 4);
          if ((*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar3 + 4) * 4) + 4) & 0x100)
              == 0) {
            local_20[5] = 0;
            local_20[4] = 0;
          }
          if (*(double *)(iVar3 + 0x20) != _DAT_0099d098) {
            local_20[5] = 0;
          }
          if (*(double *)(iVar3 + 0x20) != _DAT_0099d0a0) {
            local_20[4] = 0;
          }
          local_20[6] = local_20[6] + 1;
        } while ((uint)local_20[6] < uVar5);
        if ((local_20[5] == 0) && (local_20[4] == 0)) {
          return 1;
        }
      }
      iVar3 = FUN_009149f7(0x74);
      if (iVar3 == 0) {
        local_20[6] = 0;
      }
      else {
        local_20[6] = FUN_0091455d();
      }
      iVar3 = local_20[6];
      if (local_20[6] == 0) {
        return -0x7ff8fff2;
      }
      if (local_20[5] == 0) {
        uVar4 = uVar5 & 0xfffff | 0x74700000;
      }
      else {
        uVar4 = uVar5 & 0xfffff | 0x74600000;
      }
      local_20[5] = FUN_00914a42(uVar4,uVar5 * 2,uVar5,0);
      if (-1 < local_20[5]) {
        local_20[5] = FUN_00914593(*(undefined4 *)(in_ECX + 0x100));
        if (local_20[5] < 0) goto LAB_00942f0a;
        puVar6 = *(undefined4 **)(*(int *)(in_ECX + 0x100) + 0x10);
        puVar8 = *(undefined4 **)(iVar3 + 0x10);
        for (uVar4 = uVar5 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar8 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar8 = puVar8 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        }
        piVar7 = local_20;
        piVar9 = *(int **)(local_20[6] + 8);
        for (uVar4 = uVar5 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
          *piVar9 = *piVar7;
          piVar7 = piVar7 + 1;
          piVar9 = piVar9 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(char *)piVar9 = (char)*piVar7;
          piVar7 = (int *)((int)piVar7 + 1);
          piVar9 = (int *)((int)piVar9 + 1);
        }
        piVar7 = local_34;
        goto LAB_00942f53;
      }
      goto LAB_00942f0a;
    }
    iVar3 = FUN_009149f7(0x74);
    if (iVar3 == 0) {
      local_20[6] = 0;
    }
    else {
      local_20[6] = FUN_0091455d();
    }
    if (local_20[6] == 0) {
      return -0x7ff8fff2;
    }
    uVar4 = uVar5 | 0x74700000;
  }
  iVar3 = local_20[6];
  local_20[5] = FUN_00914a42(uVar4,uVar5 * 2,uVar5,0);
  if (-1 < local_20[5]) {
    local_20[5] = FUN_00914593(*(undefined4 *)(in_ECX + 0x100));
    if (-1 < local_20[5]) {
      puVar6 = *(undefined4 **)(*(int *)(in_ECX + 0x100) + 0x10);
      puVar8 = *(undefined4 **)(iVar3 + 0x10);
      for (uVar4 = uVar5; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      piVar7 = local_d4;
      piVar9 = *(int **)(local_20[6] + 8);
      for (uVar4 = uVar5; uVar4 != 0; uVar4 = uVar4 - 1) {
        *piVar9 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar9 = piVar9 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(char *)piVar9 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar9 = (int *)((int)piVar9 + 1);
      }
      piVar7 = local_c4;
LAB_00942f53:
      piVar9 = (int *)(*(int *)(local_20[6] + 8) + uVar5 * 4);
      for (uVar4 = uVar5 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *piVar9 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar9 = piVar9 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(char *)piVar9 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar9 = (int *)((int)piVar9 + 1);
      }
      iVar3 = FUN_00914ca1(local_20[6]);
      FUN_008f4adb(1);
      return iVar3;
    }
  }
LAB_00942f0a:
  FUN_008f4adb(1);
  return local_20[5];
}


// ==== FUN_00942f8d @ 0x00942f8d ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00942f8d(void)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int in_ECX;
  undefined4 *puVar8;
  int *piVar9;
  undefined1 local_21c [64];
  undefined1 local_1dc [64];
  int local_19c [4];
  int local_18c;
  int local_fc [4];
  int local_ec;
  int local_dc;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 *local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_58 = 0xffffffff;
  local_54 = 0xffffffff;
  local_50 = 0xffffffff;
  local_48 = 0xffffffff;
  local_44 = 0xffffffff;
  local_40 = 0xffffffff;
  local_3c = **(uint **)(in_ECX + 0x100) & 0xfffff;
  local_5c = 0;
  local_4c = 0;
  if ((**(uint **)(in_ECX + 0x100) & 0xfff00000) == 0x20900000) {
    iVar4 = FUN_009149f7(0x74);
    if (iVar4 == 0) {
      local_24 = (undefined4 *)0x0;
    }
    else {
      local_24 = (undefined4 *)FUN_0091455d();
    }
    puVar8 = local_24;
    if (local_24 == (undefined4 *)0x0) {
LAB_00943002:
      iVar4 = -0x7ff8fff2;
    }
    else {
      iVar4 = FUN_00914ca1();
      if (iVar4 < 0) {
        FUN_008f4adb();
      }
      else {
        puVar8[3] = 1;
        puVar8[1] = 2;
        *puVar8 = 0x20900001;
        local_38 = 0;
        if (local_3c != 0) {
          local_2c = local_3c << 2;
          do {
            *(undefined4 *)puVar8[4] =
                 *(undefined4 *)(local_38 * 4 + *(int *)(*(int *)(in_ECX + 0x100) + 0x10));
            *(undefined4 *)puVar8[2] =
                 *(undefined4 *)(local_38 * 4 + *(int *)(*(int *)(in_ECX + 0x100) + 8));
            local_10 = 0;
            *(undefined4 *)(puVar8[2] + 4) =
                 *(undefined4 *)(local_2c + *(int *)(*(int *)(in_ECX + 0x100) + 8));
            piVar9 = local_fc;
            for (iVar4 = 0x28; iVar4 != 0; iVar4 = iVar4 + -1) {
              *piVar9 = -1;
              piVar9 = piVar9 + 1;
            }
            iVar5 = FUN_0093d430(puVar8,&DAT_00a2d5b8,local_1dc,&local_10,local_fc,&local_5c,
                                 0x100000001);
            iVar4 = local_ec;
            if ((iVar5 == 0) && (local_ec == local_dc)) {
              local_10 = 0;
              FUN_0093d430(puVar8,&DAT_00a2d678,local_21c,&local_10,local_19c,&local_4c,1,1);
              if (local_19c[0] == local_fc[0]) {
                local_14 = local_18c;
              }
              else {
                local_14 = local_fc[0];
              }
              if ((((local_14 != -1) &&
                   (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar8[4] * 4) + 0x14) != -1
                   )) && (iVar5 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                   *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                                    *(int *)puVar8[4] * 4) + 0x14) *
                                                   4) + 0x48), iVar5 != -1)) &&
                 (local_18 = *(int **)(*(int *)(in_ECX + 0x18) + iVar5 * 4), *local_18 == 0x11100001
                 )) {
                local_1c = *(int *)(*(int *)(in_ECX + 0x14) + local_fc[0] * 4);
                iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4);
                while ((*(int *)(iVar5 + 0x48) != -1 && (*(int *)(iVar5 + 8) == -1))) {
                  puVar3 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar5 + 0x48) * 4);
                  if ((*puVar3 & 0xfff00000) != 0x10000000) break;
                  local_8 = 0;
                  local_c = *puVar3 & 0xfffff;
                  if (local_c == 0) break;
                  piVar9 = (int *)puVar3[4];
                  while (*piVar9 != iVar4) {
                    local_8 = local_8 + 1;
                    piVar9 = piVar9 + 1;
                    if (local_c <= local_8) goto LAB_009431ec;
                  }
                  iVar4 = *(int *)(puVar3[2] + local_8 * 4);
                  iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4);
                }
LAB_009431ec:
                if ((((*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(local_1c + 4) * 4) + 4)
                      & 0x100) != 0) &&
                    ((*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar5 + 4) * 4) + 4) &
                     0x100) != 0)) &&
                   ((*(double *)(local_1c + 0x20) == _DAT_0099d0a0 &&
                    (*(double *)(iVar5 + 0x20) == _DAT_0099d098)))) {
                  iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + local_14 * 4);
                  local_10 = *(uint *)(iVar4 + 0x54);
                  iVar5 = -1;
                  local_30 = -1;
                  local_1c = iVar4;
                  if (local_10 <= *(uint *)(iVar4 + 0x58)) {
                    do {
                      iVar7 = *(int *)(*(int *)(in_ECX + 0x18) + local_10 * 4);
                      local_28 = iVar7;
                      if ((*(int *)(iVar7 + 0xc) != 0) && (local_c = 0, *(int *)(iVar7 + 4) != 0)) {
                        do {
                          iVar4 = *(int *)(*(int *)(in_ECX + 0x14) +
                                          *(int *)(*(int *)(iVar7 + 8) + local_c * 4) * 4);
                          iVar1 = *(int *)(iVar4 + 8);
                          local_20 = -1;
                          if (iVar1 == -1) {
LAB_009432fd:
                            if (local_20 == local_14) {
                              if (local_30 == -1) {
                                uVar6 = FUN_009152bf(&DAT_00a2db40,0x15,0xffffffff,4);
                                local_30 = FUN_00915318(uVar6,0,0,0);
                                *(int *)(iVar4 + 8) = local_30;
                              }
                              *(int *)(iVar4 + 8) = local_30;
                              if (*(int *)(iVar4 + 0x38) != -1) {
                                *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                 *(int *)(iVar4 + 0x38) * 4) + 8) = local_30;
                              }
                            }
                            iVar7 = local_28;
                            iVar5 = local_30;
                          }
                          else {
                            iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar1 * 4) + 0x48);
                            if (iVar2 != -1) {
                              puVar3 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar2 * 4);
                              if ((*puVar3 & 0xfff00000) == 0x10000000) {
                                local_8 = 0;
                                local_34 = *puVar3 & 0xfffff;
                                if (local_34 != 0) {
                                  piVar9 = (int *)puVar3[4];
                                  do {
                                    if (*piVar9 == iVar1) {
                                      local_20 = *(int *)(puVar3[2] + local_8 * 4);
                                      break;
                                    }
                                    local_8 = local_8 + 1;
                                    piVar9 = piVar9 + 1;
                                  } while (local_8 < local_34);
                                }
                              }
                              else {
                                local_20 = iVar1;
                              }
                              goto LAB_009432fd;
                            }
                          }
                          local_c = local_c + 1;
                        } while (local_c < *(uint *)(iVar7 + 4));
                        iVar4 = local_1c;
                      }
                      local_10 = local_10 + 1;
                    } while (local_10 <= *(uint *)(iVar4 + 0x58));
                    if (iVar5 != -1) {
                      iVar4 = FUN_009149f7();
                      if (iVar4 == 0) {
                        iVar4 = 0;
                      }
                      else {
                        iVar4 = FUN_0091455d();
                      }
                      if (iVar4 == 0) goto LAB_00943002;
                      iVar5 = FUN_00914a42(0x74100001,3,1,0);
                      if ((iVar5 < 0) || (iVar5 = FUN_00914593(), iVar5 < 0)) {
                        FUN_008f4adb();
                        return iVar5;
                      }
                      **(undefined4 **)(iVar4 + 0x10) = *(undefined4 *)local_18[4];
                      **(undefined4 **)(iVar4 + 8) = *(undefined4 *)local_18[2];
                      iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)local_18[2] * 4);
                      uVar6 = FUN_00915318(*(undefined4 *)(iVar5 + 4),*(undefined4 *)(iVar5 + 0xc),2
                                           ,0);
                      *(undefined4 *)(*(int *)(iVar4 + 8) + 4) = uVar6;
                      uVar6 = FUN_00915318(*(undefined4 *)(iVar5 + 4),*(undefined4 *)(iVar5 + 0xc),2
                                           ,0x3ff0000000000000);
                      *(undefined4 *)(*(int *)(iVar4 + 8) + 8) = uVar6;
                      iVar4 = FUN_00914ca1();
                      FUN_008f4adb();
                      if (iVar4 < 0) {
                        return iVar4;
                      }
                    }
                  }
                }
              }
            }
            local_2c = local_2c + 4;
            local_38 = local_38 + 1;
            if (local_3c <= local_38) break;
            puVar8 = local_24;
          } while( true );
        }
        iVar4 = 0;
      }
    }
  }
  else {
    iVar4 = 1;
  }
  return iVar4;
}


// ==== FUN_00943467 @ 0x00943467 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00943467(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int in_ECX;
  uint uVar8;
  uint *puVar9;
  byte *pbVar10;
  uint *puVar11;
  undefined4 *puVar12;
  int *piVar13;
  undefined *puVar14;
  int local_218 [4];
  int local_208;
  int local_178 [4];
  uint local_168;
  uint local_158;
  undefined1 local_d8 [64];
  int local_98 [16];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint *local_38;
  int *local_34;
  undefined4 *local_30;
  uint local_2c;
  uint *local_28;
  uint *local_24;
  uint local_20;
  byte *local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  int local_c;
  int *local_8;
  
  local_44 = 0xffffffff;
  local_40 = 0xffffffff;
  local_3c = 0xffffffff;
  local_54 = 0xffffffff;
  local_50 = 0xffffffff;
  local_4c = 0xffffffff;
  puVar12 = (undefined4 *)0x0;
  puVar9 = (uint *)(**(uint **)(in_ECX + 0x100) & 0xfffff);
  local_48 = 0;
  local_58 = 0;
  if ((**(uint **)(in_ECX + 0x100) & 0xfff00000) != 0x20900000) {
    return 1;
  }
  local_38 = puVar9;
  iVar5 = FUN_009149f7();
  if (iVar5 != 0) {
    puVar12 = (undefined4 *)FUN_0091455d();
  }
  if (puVar12 == (undefined4 *)0x0) {
    return -0x7ff8fff2;
  }
  local_30 = puVar12;
  local_c = FUN_00914ca1();
  if (-1 < local_c) {
    local_24 = (uint *)0x0;
    puVar12[3] = 1;
    puVar12[1] = 2;
    *puVar12 = 0x20900001;
    if (puVar9 != (uint *)0x0) {
      local_2c = (int)local_38 << 2;
LAB_0094351b:
      puVar12 = local_30;
      *(undefined4 *)local_30[4] =
           *(undefined4 *)((int)local_24 * 4 + *(int *)(*(int *)(in_ECX + 0x100) + 0x10));
      *(undefined4 *)local_30[2] =
           *(undefined4 *)((int)local_24 * 4 + *(int *)(*(int *)(in_ECX + 0x100) + 8));
      *(undefined4 *)(local_30[2] + 4) =
           *(undefined4 *)(local_2c + *(int *)(*(int *)(in_ECX + 0x100) + 8));
      piVar13 = local_178;
      for (iVar5 = 0x28; iVar5 != 0; iVar5 = iVar5 + -1) {
        *piVar13 = -1;
        piVar13 = piVar13 + 1;
      }
      local_8 = (int *)0x0;
      local_18 = 0;
      local_28 = (uint *)0x0;
      local_10 = 0;
      local_c = FUN_0093d430(puVar12,&DAT_00a2cf38,local_98,&local_8,local_178,&local_48,1,1);
      if (local_c != 0) {
        local_8 = (int *)0x0;
        local_c = FUN_0093d430(puVar12,&DAT_00a2d098,local_98,&local_8,local_178,&local_48,1,1);
        if (local_c == 0) {
          local_18 = 1;
          local_c = 0;
        }
        else {
          local_8 = (int *)0x0;
          local_c = FUN_0093d430(puVar12,&DAT_00a2d238,local_98,&local_8,local_178,&local_48,1,1);
          if (local_c == 0) {
            local_28 = (uint *)0x1;
            local_c = 0;
          }
          else {
            local_8 = (int *)0x0;
            local_c = FUN_0093d430(puVar12,&DAT_00a2d3d8,local_98,&local_8,local_178,&local_48,1,1);
            if (local_c == 0) {
              local_10 = 1;
            }
          }
        }
      }
      if ((local_168 == local_158) && (local_c == 0)) {
        iVar5 = *(int *)(in_ECX + 0x14);
        iVar7 = *(int *)(*(int *)(iVar5 + **(int **)(local_98[0] + 0x10) * 4) + 0x14);
        if (iVar7 != -1) {
          piVar13 = *(int **)(*(int *)(in_ECX + 0x18) +
                             *(int *)(*(int *)(iVar5 + iVar7 * 4) + 0x48) * 4);
          local_8 = (int *)0x0;
          if (*piVar13 == 0x11100001) {
            iVar7 = *(int *)piVar13[4];
            iVar1 = *(int *)(iVar5 + iVar7 * 4);
            pbVar10 = *(byte **)(iVar1 + 0x54);
            local_1c = *(byte **)(iVar1 + 0x58);
            if (pbVar10 <= local_1c) {
              local_34 = (int *)(*(int *)(in_ECX + 0x18) + (int)pbVar10 * 4);
              do {
                piVar13 = (int *)*local_34;
                if ((*(int *)(*(int *)(iVar5 + *(int *)piVar13[4] * 4) + 0x14) == iVar7) &&
                   (*piVar13 == 0x74700001)) {
                  if (local_8 != (int *)0x0) {
                    FUN_0091a001();
                    return -0x7fffbffb;
                  }
                  local_8 = piVar13;
                }
                piVar13 = local_8;
                pbVar10 = pbVar10 + 1;
                local_34 = local_34 + 1;
              } while (pbVar10 <= local_1c);
              if (local_8 != (int *)0x0) {
                local_14 = 0;
                if (local_10 == 0) {
                  if (local_28 == (uint *)0x0) {
                    if (local_18 == 0) {
                      puVar12 = &local_58;
                      puVar14 = &DAT_00a2d018;
                    }
                    else {
                      puVar12 = &local_48;
                      puVar14 = &DAT_00a2d198;
                    }
                  }
                  else {
                    puVar12 = &local_48;
                    puVar14 = &DAT_00a2d338;
                  }
                }
                else {
                  puVar12 = &local_48;
                  puVar14 = &DAT_00a2d4f8;
                }
                local_c = FUN_0093d430(local_30,puVar14,local_d8,&local_14,local_218,puVar12,1,1);
                iVar5 = local_178[0];
                if (local_218[0] == local_178[0]) {
                  iVar5 = local_208;
                }
                if (((iVar5 != -1) && (piVar2 = (int *)piVar13[2], *piVar2 == iVar5)) &&
                   (iVar5 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)piVar13[4] * 4) +
                                    0x14), iVar5 != -1)) {
                  local_34 = *(int **)(*(int *)(in_ECX + 0x18) +
                                      *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar5 * 4) + 0x48)
                                      * 4);
                  iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)local_34[2] * 4);
                  if ((*local_34 == 0x11100001) &&
                     ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar5 + 4) * 4) + 5) &
                      1) != 0)) {
                    fVar4 = (float)*(int *)(in_ECX + 0x68);
                    if (*(int *)(in_ECX + 0x68) < 0) {
                      fVar4 = fVar4 + _DAT_0099d104;
                    }
                    if ((float)*(double *)(iVar5 + 0x20) == fVar4) {
                      iVar5 = *(int *)(in_ECX + 0x14);
                      local_1c = *(byte **)(iVar5 + piVar2[1] * 4);
                      local_14 = *(int *)(iVar5 + local_178[0] * 4);
                      iVar7 = *(int *)(iVar5 + local_168 * 4);
                      iVar5 = *(int *)(iVar7 + 0x48);
                      local_10 = local_168;
                      if (iVar5 != -1) {
                        while ((*(int *)(iVar7 + 8) == -1 &&
                               (puVar9 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar5 * 4),
                               (*puVar9 & 0xfff00000) == 0x10000000))) {
                          local_20 = 0;
                          local_18 = *puVar9 & 0xfffff;
                          if (local_18 == 0) break;
                          puVar11 = (uint *)puVar9[4];
                          while (*puVar11 != local_10) {
                            local_20 = local_20 + 1;
                            puVar11 = puVar11 + 1;
                            local_28 = puVar11;
                            if (local_18 <= local_20) goto LAB_009438c7;
                          }
                          local_10 = *(uint *)(puVar9[2] + local_20 * 4);
                          iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + local_10 * 4);
                          iVar5 = *(int *)(iVar7 + 0x48);
                          if (iVar5 == -1) break;
                        }
                      }
LAB_009438c7:
                      iVar5 = *(int *)(in_ECX + 0x10);
                      if ((((((*(byte *)(*(int *)(iVar5 + *(int *)(local_14 + 4) * 4) + 5) & 1) != 0
                             ) && ((*(byte *)(*(int *)(iVar5 + *(int *)(iVar7 + 4) * 4) + 5) & 1) !=
                                   0)) && (*(double *)(local_14 + 0x20) == _DAT_0099d0a0)) &&
                          ((*(double *)(iVar7 + 0x20) == _DAT_0099d098 &&
                           ((*(byte *)(*(int *)(iVar5 + *(int *)(local_1c + 4) * 4) + 5) & 2) != 0))
                          )) && (((*local_1c & 2) != 0 &&
                                 ((*(int *)(local_1c + 0x10) == 0 && (*(int *)(local_1c + 8) == -1))
                                 )))) {
                        local_18 = 0xffffffff;
                        *(undefined4 *)local_34[2] = *(undefined4 *)(local_8[2] + 4);
                        *local_8 = 0;
                        local_14 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)local_34[4] * 4);
                        local_1c = *(byte **)(local_14 + 0x54);
                        if (*(byte **)(local_14 + 0x58) < local_1c) goto LAB_00943be2;
                        do {
                          uVar8 = *(uint *)(*(int *)(in_ECX + 0x18) + (int)local_1c * 4);
                          local_20 = uVar8;
                          if (((*(int *)(uVar8 + 0xc) != 0) &&
                              (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                **(int **)(uVar8 + 0x10) * 4) + 0x14) ==
                               *(int *)local_8[4])) && (local_2c = 0, *(int *)(uVar8 + 4) != 0)) {
                            do {
                              iVar5 = *(int *)(*(int *)(in_ECX + 0x14) +
                                              *(int *)(*(int *)(uVar8 + 8) + local_2c * 4) * 4);
                              uVar3 = *(uint *)(iVar5 + 8);
                              local_10 = 0xffffffff;
                              if (uVar3 == 0xffffffff) {
LAB_00943a50:
                                if (local_10 == *(uint *)local_8[2]) {
                                  if (local_18 == 0xffffffff) {
                                    uVar6 = FUN_009152bf(&DAT_00a2db40,0x15,0xffffffff,4);
                                    local_18 = FUN_00915318(uVar6,0,0,0);
                                    *(uint *)(iVar5 + 8) = local_18;
                                  }
                                  *(uint *)(iVar5 + 8) = local_18;
                                  if (*(int *)(iVar5 + 0x38) != -1) {
                                    *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                      *(int *)(iVar5 + 0x38) * 4) + 8) = local_18;
                                  }
                                }
                              }
                              else {
                                iVar7 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar3 * 4) +
                                                0x48);
                                if (iVar7 != -1) {
                                  puVar9 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar7 * 4);
                                  if ((*puVar9 & 0xfff00000) == 0x10000000) {
                                    local_24 = (uint *)0x0;
                                    local_28 = (uint *)(*puVar9 & 0xfffff);
                                    if (local_28 != (uint *)0x0) {
                                      puVar11 = (uint *)puVar9[4];
                                      do {
                                        if (*puVar11 == uVar3) {
                                          local_10 = *(uint *)(puVar9[2] + (int)local_24 * 4);
                                          break;
                                        }
                                        local_24 = (uint *)((int)local_24 + 1);
                                        puVar11 = puVar11 + 1;
                                      } while (local_24 < local_28);
                                    }
                                  }
                                  else {
                                    local_10 = uVar3;
                                  }
                                  uVar8 = local_20;
                                  goto LAB_00943a50;
                                }
                              }
                              local_2c = local_2c + 1;
                            } while (local_2c < *(uint *)(uVar8 + 4));
                          }
                          local_1c = local_1c + 1;
                        } while (local_1c <= *(byte **)(local_14 + 0x58));
                        if (local_18 != 0xffffffff) {
                          iVar5 = FUN_00915318(0,0,0,0);
                          iVar7 = FUN_00915318(0,0,0,0);
                          if ((iVar5 == -1) || (iVar7 == -1)) {
                            return -0x7ff8fff2;
                          }
                          iVar1 = *(int *)(in_ECX + 0x14);
                          local_38 = *(uint **)(iVar1 + *(int *)local_34[2] * 4);
                          iVar5 = *(int *)(iVar1 + iVar5 * 4);
                          iVar7 = *(int *)(iVar1 + iVar7 * 4);
                          FUN_00914e44();
                          FUN_00914e44();
                          *(undefined4 *)(iVar5 + 0x10) = 1;
                          *(undefined4 *)(iVar7 + 0x10) = 2;
                          iVar5 = FUN_009149f7();
                          if (iVar5 == 0) {
                            iVar5 = 0;
                          }
                          else {
                            iVar5 = FUN_0091455d();
                          }
                          if (iVar5 == 0) {
                            return -0x7ff8fff2;
                          }
                          iVar7 = FUN_00914a42(0x74100001,3,1,0);
                          piVar13 = local_34;
                          if (iVar7 < 0) {
                            FUN_008f4adb();
                            return iVar7;
                          }
                          local_c = FUN_00914593();
                          if (local_c < 0) goto LAB_00943c76;
                          **(undefined4 **)(iVar5 + 0x10) = *(undefined4 *)piVar13[4];
                          **(undefined4 **)(iVar5 + 8) = *(undefined4 *)piVar13[2];
                          *(undefined4 *)(*(int *)(iVar5 + 8) + 4) = *(undefined4 *)piVar13[2];
                          *(undefined4 *)(*(int *)(iVar5 + 8) + 8) = *(undefined4 *)piVar13[2];
                          local_c = FUN_00914ca1();
                          FUN_008f4adb();
                          if (local_c < 0) {
                            return local_c;
                          }
                        }
LAB_00943be2:
                        local_10 = *(uint *)(local_14 + 0x54);
                        if (local_10 <= *(uint *)(local_14 + 0x58)) {
                          do {
                            puVar9 = *(uint **)(*(int *)(in_ECX + 0x18) + local_10 * 4);
                            if (((*puVar9 & 0xfff00000) == 0x20800000) &&
                               (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar9[2] * 4) +
                                        0x14) == *(int *)local_8[4])) {
                              uVar8 = *puVar9 & 0xfffff;
                              *puVar9 = uVar8 | 0x10000000;
                              puVar9[3] = uVar8;
                              puVar9[1] = uVar8;
                            }
                            local_10 = local_10 + 1;
                          } while (local_10 <= *(uint *)(local_14 + 0x58));
                        }
                        uVar8 = 0;
                        if (*(int *)(in_ECX + 8) != 0) {
                          do {
                            iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + uVar8 * 4);
                            if (*(int *)(iVar5 + 0x14) == *(int *)local_8[4]) {
                              *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)local_34[4];
                            }
                            uVar8 = uVar8 + 1;
                          } while (uVar8 < *(uint *)(in_ECX + 8));
                        }
                        goto LAB_00943c76;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      local_24 = (uint *)((int)local_24 + 1);
      local_2c = local_2c + 4;
      if (local_38 <= local_24) goto LAB_00943c76;
      goto LAB_0094351b;
    }
  }
LAB_00943c76:
  FUN_008f4adb();
  return local_c;
}


// ==== FUN_00943c85 @ 0x00943c85 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00943c85(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  undefined1 local_100 [16];
  int aiStack_f0 [4];
  int aiStack_e0 [32];
  undefined1 local_60 [64];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  local_8 = 0;
  local_20 = 0;
  local_10 = 0;
  uVar4 = **(uint **)(in_ECX + 0x100) & 0xfffff;
  local_1c = 1;
  local_18 = 2;
  local_14 = 3;
  iVar1 = FUN_0093d430(*(uint **)(in_ECX + 0x100),&DAT_00a2cbb8,local_60,&local_8,local_100,
                       &local_20,uVar4,1);
  if (iVar1 == 1) {
    local_10 = 1;
    iVar1 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2cc18,local_60,&local_8,local_100,
                         &local_20,uVar4,1);
  }
  if (iVar1 == 0) {
    local_c = 0;
    if (uVar4 != 0) {
      local_8 = uVar4 << 2;
      do {
        if ((((aiStack_f0[local_c] != aiStack_e0[local_c]) ||
             (iVar1 = *(int *)(*(int *)(in_ECX + 0x14) +
                              *(int *)(local_8 + *(int *)(*(int *)(in_ECX + 0x100) + 8)) * 4),
             (*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar1 + 4) * 4) + 5) & 1) == 0))
            || (*(double *)(iVar1 + 0x20) != _DAT_0099d098)) || (*(int *)(iVar1 + 8) != -1)) {
          return 1;
        }
        local_c = local_c + 1;
        local_8 = local_8 + 4;
      } while (local_c < uVar4);
    }
    uVar2 = 0;
    if (local_10 == 0) {
      uVar3 = uVar4 | 0x74500000;
    }
    else {
      uVar3 = uVar4 | 0x74400000;
    }
    **(uint **)(in_ECX + 0x100) = uVar3;
    if (uVar4 != 0) {
      do {
        *(int *)(*(int *)(*(int *)(in_ECX + 0x100) + 8) + uVar2 * 4) = aiStack_f0[uVar2];
        uVar2 = uVar2 + 1;
      } while (uVar2 < uVar4);
    }
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_00943dd3 @ 0x00943dd3 ====

int FUN_00943dd3(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  undefined1 local_fc [64];
  int local_bc [4];
  int aiStack_ac [4];
  int aiStack_9c [4];
  int aiStack_8c [28];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  local_8 = 0;
  local_1c = 0;
  local_c = 0;
  uVar4 = **(uint **)(in_ECX + 0x100) & 0xfffff;
  local_18 = 1;
  local_14 = 2;
  local_10 = 3;
  iVar2 = FUN_0093d430(*(uint **)(in_ECX + 0x100),&DAT_00a2cc78,local_fc,&local_8,local_bc,&local_1c
                       ,uVar4,1);
  if (iVar2 == 1) {
    local_c = 1;
    iVar2 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2ccf8,local_fc,&local_8,local_bc,
                         &local_1c,uVar4,1);
  }
  if (iVar2 == 0) {
    local_8 = 0;
    if (uVar4 != 0) {
      do {
        if (((local_bc[local_8] != aiStack_ac[local_8]) ||
            (aiStack_ac[local_8] != aiStack_9c[local_8])) ||
           (local_bc[local_8] != aiStack_8c[local_8])) {
          return 1;
        }
        local_8 = local_8 + 1;
      } while (local_8 < uVar4);
    }
    if (local_c == 0) {
      uVar3 = uVar4 | 0x74500000;
    }
    else {
      uVar3 = uVar4 | 0x74400000;
    }
    **(uint **)(in_ECX + 0x100) = uVar3;
    local_c = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,0);
    if (local_c == -1) {
      iVar2 = -0x7ff8fff2;
    }
    else {
      uVar3 = 0;
      if (uVar4 != 0) {
        local_8 = uVar4 << 2;
        do {
          uVar1 = local_8;
          local_8 = local_8 + 4;
          *(int *)(*(int *)(*(int *)(in_ECX + 0x100) + 8) + uVar3 * 4) = local_bc[uVar3];
          uVar3 = uVar3 + 1;
          *(int *)(uVar1 + *(int *)(*(int *)(in_ECX + 0x100) + 8)) = local_c;
        } while (uVar3 < uVar4);
      }
      iVar2 = 0;
    }
  }
  return iVar2;
}


// ==== FUN_00943f35 @ 0x00943f35 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00943f35(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  uint uVar3;
  undefined1 local_100 [16];
  undefined4 auStack_f0 [4];
  int local_e0 [32];
  undefined1 local_60 [64];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_20 = 0;
  local_1c = 1;
  local_18 = 2;
  local_14 = 3;
  if ((**(uint **)(in_ECX + 0x100) & 0xfffff) == 1) {
    iVar1 = FUN_0093d430(*(uint **)(in_ECX + 0x100),&DAT_00a2ca38,local_60,&local_8,local_100,
                         &local_20,1,1);
    if (((iVar1 == 1) &&
        (iVar1 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2ca98,local_60,&local_8,
                              local_100,&local_20,1,1), iVar1 == 1)) &&
       (iVar1 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2caf8,local_60,&local_8,
                             local_100,&local_20,1,1), iVar1 == 1)) {
      iVar1 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2cb58,local_60,&local_8,local_100
                           ,&local_20,1,1);
    }
    if (iVar1 == 0) {
      piVar2 = *(int **)(*(int *)(in_ECX + 0x100) + 8);
      local_8 = 0;
      do {
        piVar2 = piVar2 + 1;
        iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar2 * 4);
        if ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar1 + 4) * 4) + 5) & 1) == 0)
            || (*(double *)(iVar1 + 0x20) != _DAT_0099d098)) || (*(int *)(iVar1 + 8) != -1)) {
          return 1;
        }
        local_8 = local_8 + 1;
      } while (local_8 == 0);
      iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + local_e0[0] * 4);
      local_8 = 0;
      if ((*(int *)(iVar1 + 8) == -1) &&
         ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar1 + 4) * 4) + 5) & 1) != 0)) {
        local_8 = 1;
      }
      uVar3 = 0;
      do {
        *(undefined4 *)(uVar3 + *(int *)(*(int *)(in_ECX + 0x100) + 8)) =
             *(undefined4 *)((int)auStack_f0 + uVar3);
        iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)((int)local_e0 + uVar3) * 4);
        local_10 = FUN_00915318(*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 0xc),
                                *(undefined4 *)(iVar1 + 0x10),*(undefined8 *)(iVar1 + 0x20));
        if (local_10 == -1) {
          return -0x7ff8fff2;
        }
        local_c = *(int *)(*(int *)(in_ECX + 0x14) + local_10 * 4);
        FUN_00914e44();
        if (local_8 == 0) {
          if (*(int *)(local_c + 0x38) == -1) {
            *(undefined4 *)(local_c + 0x38) = *(undefined4 *)((int)local_e0 + uVar3);
          }
          *(uint *)(local_c + 0x3c) = *(uint *)(local_c + 0x3c) ^ 0x80000;
        }
        else {
          *(double *)(local_c + 0x20) = *(double *)(local_c + 0x20) * _DAT_009fd350;
        }
        *(int *)(*(int *)(*(int *)(in_ECX + 0x100) + 8) + 4 + uVar3) = local_10;
        uVar3 = uVar3 + 4;
      } while (uVar3 < 4);
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}


// ==== FUN_0094414d @ 0x0094414d ====

int FUN_0094414d(void)

{
  uint *puVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  int *piVar9;
  int local_27c [40];
  int local_1dc [40];
  int local_13c [40];
  undefined1 local_9c [16];
  int local_8c [16];
  uint local_4c [5];
  uint local_38;
  int local_34;
  undefined4 *local_30;
  uint local_2c;
  uint local_28;
  uint *local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_4c[0] = 0;
  piVar2 = local_13c;
  for (iVar3 = 0x28; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar2 = -1;
    piVar2 = piVar2 + 1;
  }
  local_24 = *(uint **)(in_ECX + 0x100);
  local_28 = *local_24 & 0xfffff;
  local_4c[1] = 1;
  local_4c[2] = 2;
  local_4c[3] = 3;
  local_1c = *local_24 & 0xfffff;
  if (((*local_24 & 0xfffff) < local_28) || ((*local_24 & 0xfff00000) != 0x20500000)) {
    local_10 = 1;
LAB_00944550:
    if (local_1c < 3) {
      return 1;
    }
    local_18 = 0;
    if (local_1c != 0) {
      piVar2 = *(int **)(*(int *)(in_ECX + 0x100) + 0x10);
      do {
        iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar2 * 4);
        if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar3 + 4) * 4) + 4) & 0x20) != 0
           ) {
          return 1;
        }
        if (*(uint *)(iVar3 + 0x10) != local_18) {
          return 1;
        }
        local_18 = local_18 + 1;
        piVar2 = piVar2 + 1;
      } while (local_18 < local_1c);
    }
    if (local_10 == 0) {
      uVar5 = 0;
      do {
        iVar3 = local_13c[uVar5];
        if (iVar3 != local_13c[uVar5 + 4]) {
          return 1;
        }
        if (iVar3 != local_13c[uVar5 + 8]) {
          return 1;
        }
        if ((*(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4) + 0x10) != uVar5) &&
           ((*(byte *)(in_ECX + 0x6c) & 2) != 0)) {
          return 1;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < 3);
      if ((local_13c[7] != -1) || (local_13c[0xb] != -1)) {
        return 1;
      }
      iVar3 = FUN_009149f7(0x74);
      if (iVar3 == 0) {
        local_24 = (uint *)0x0;
      }
      else {
        local_24 = (uint *)FUN_0091455d();
      }
      if (local_24 == (uint *)0x0) {
        return -0x7ff8fff2;
      }
      iVar3 = FUN_00914a42(local_1c & 0xfffff | 0x70200000,local_1c,local_1c,0);
      if ((iVar3 < 0) || (iVar3 = FUN_00914593(*(undefined4 *)(in_ECX + 0x100)), iVar3 < 0)) {
        FUN_008f4adb(1);
        return iVar3;
      }
      puVar6 = *(undefined4 **)(*(int *)(in_ECX + 0x100) + 0x10);
      puVar8 = *(undefined4 **)((int)local_24 + 0x10);
      for (uVar5 = local_1c & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      piVar2 = local_13c;
      piVar9 = *(int **)((int)local_24 + 8);
      for (uVar5 = local_1c & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *piVar9 = *piVar2;
        piVar2 = piVar2 + 1;
        piVar9 = piVar9 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(char *)piVar9 = (char)*piVar2;
        piVar2 = (int *)((int)piVar2 + 1);
        piVar9 = (int *)((int)piVar9 + 1);
      }
      uVar5 = 0;
      if (local_1c != 0) {
        do {
          if ((*(byte *)(in_ECX + 0x6c) & 2) != 0) {
            puVar1 = *(uint **)(*(int *)(in_ECX + 0x14) +
                               *(int *)(*(int *)(*(int *)(in_ECX + 0x100) + 8) + uVar5 * 4) * 4);
            *puVar1 = *puVar1 | 0x80000000;
            iVar3 = *(int *)(in_ECX + 0x14);
            if (*(int *)(*(int *)(iVar3 + *(int *)(*(int *)(*(int *)(in_ECX + 0x100) + 8) +
                                                  uVar5 * 4) * 4) + 0x38) != -1) {
              puVar1 = *(uint **)(iVar3 + *(int *)(*(int *)(iVar3 + *(int *)(*(int *)(*(int *)(
                                                  in_ECX + 0x100) + 8) + uVar5 * 4) * 4) + 0x38) * 4
                                 );
              *puVar1 = *puVar1 | 0x80000000;
            }
          }
          puVar1 = *(uint **)(*(int *)(in_ECX + 0x14) +
                             *(int *)(*(int *)(*(int *)(in_ECX + 0x100) + 0x10) + uVar5 * 4) * 4);
          *puVar1 = *puVar1 | 0x80000000;
          uVar5 = uVar5 + 1;
        } while (uVar5 < local_1c);
      }
      local_10 = FUN_00914ca1(local_24);
      FUN_008f4adb(1);
    }
    return local_10;
  }
  local_34 = 0;
  do {
    local_10 = 0;
    do {
      piVar2 = local_1dc;
      for (iVar3 = 0x28; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar2 = -1;
        piVar2 = piVar2 + 1;
      }
      piVar2 = local_27c;
      for (iVar3 = 0x28; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar2 = -1;
        piVar2 = piVar2 + 1;
      }
      local_2c = 0;
      local_20 = 0;
      local_8 = 0;
      local_c = 0;
      do {
        if (local_10 == 0) {
          uVar5 = local_8;
        }
        else {
          uVar5 = 1 - local_8;
        }
        uVar7 = local_24[2];
        uVar5 = *(uint *)(&DAT_00a2c4e4 + uVar5 * 4);
        piVar2 = (int *)(uVar7 + local_c * 4);
        if (uVar5 < 0x10) {
          iVar3 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar2 * 4) + 0x48);
          if (iVar3 != -1) {
            local_18 = *(undefined4 *)(*(int *)(in_ECX + 0x18) + iVar3 * 4);
            iVar3 = FUN_0093d27f(local_18,piVar2,local_28,local_4c,local_9c,
                                 *(undefined4 *)(&DAT_00a2c4f0 + uVar5 * 0x20),0);
            if (iVar3 == 0) {
              local_20 = FUN_0093d430(local_18,&DAT_00a2c4d8 + uVar5 * 0x20,local_8c,&local_2c,
                                      local_27c,local_9c,local_1c,0);
              goto LAB_009442ca;
            }
          }
          local_20 = 1;
          break;
        }
        uVar4 = 0;
        piVar2 = local_1dc + (uVar5 - 0x10) * 4;
        do {
          if (local_4c[uVar4] < local_28) {
            *piVar2 = *(int *)(uVar7 + (local_4c[uVar4] + local_c) * 4);
          }
          else {
            *piVar2 = -1;
          }
          uVar4 = uVar4 + 1;
          piVar2 = piVar2 + 1;
        } while (uVar4 < 4);
LAB_009442ca:
        if (local_20 == 1) break;
        local_8 = local_8 + 1;
        local_c = local_c + local_28;
      } while (local_8 < 2);
      local_8 = 0;
      local_30 = (undefined4 *)0x0;
      do {
        if (local_10 == 0) {
          uVar5 = local_8;
        }
        else {
          uVar5 = 1 - local_8;
        }
        if ((0xf < *(uint *)(&DAT_00a2c4e4 + uVar5 * 4)) && (local_14 = 0, local_2c != 0)) {
          do {
            uVar5 = 0;
            if (local_28 != 0) {
              iVar3 = local_8c[local_14];
              uVar7 = *(uint *)(iVar3 + 0xc);
              do {
                local_c = 0;
                if (uVar7 != 0) {
                  piVar2 = *(int **)(iVar3 + 0x10);
                  do {
                    if (*(int *)(local_24[2] + ((int)local_30 + uVar5) * 4) == *piVar2) {
                      local_20 = 1;
                      goto LAB_00944365;
                    }
                    local_c = local_c + 1;
                    uVar7 = *(uint *)(iVar3 + 0xc);
                    piVar2 = piVar2 + 1;
                  } while (local_c < uVar7);
                }
                uVar5 = uVar5 + 1;
              } while (uVar5 < local_28);
            }
LAB_00944365:
            local_14 = local_14 + 1;
          } while (local_14 < local_2c);
        }
        local_8 = local_8 + 1;
        local_30 = (undefined4 *)((int)local_30 + local_28);
      } while (local_8 < 2);
      if (local_20 == 0) {
        if (local_34 != 0) goto LAB_00944510;
        local_14 = 0;
        if (local_2c != 0) {
          do {
            local_38 = *(uint *)(local_8c[local_14] + 0xc);
            local_c = 0;
            if (local_38 != 0) {
              do {
                if (*(int *)(in_ECX + 0xc) != 0) {
                  local_30 = *(undefined4 **)(in_ECX + 0x18);
                  local_18 = *(int *)(in_ECX + 0xc);
                  do {
                    puVar1 = (uint *)*local_30;
                    if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
                      local_8 = 0;
                      if (puVar1[1] != 0) {
                        iVar3 = *(int *)(*(int *)(local_8c[local_14] + 0x10) + local_c * 4);
                        piVar2 = (int *)puVar1[2];
                        local_4c[4] = puVar1[1];
                        do {
                          if ((*piVar2 == iVar3) ||
                             (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar2 * 4) + 0x38) ==
                              iVar3)) {
                            local_8 = 1;
                          }
                          piVar2 = piVar2 + 1;
                          local_4c[4] = local_4c[4] - 1;
                        } while (local_4c[4] != 0);
                      }
                      if (puVar1 == local_24) {
                        local_8 = 0;
                      }
                      if (local_8 != 0) {
                        uVar5 = 0;
                        do {
                          if (puVar1 == (uint *)local_8c[uVar5]) {
                            local_8 = 0;
                          }
                          uVar5 = uVar5 + 1;
                        } while (uVar5 < local_2c);
                        if (local_8 != 0) {
                          local_20 = 1;
                        }
                      }
                    }
                    local_30 = local_30 + 1;
                    local_18 = local_18 + -1;
                  } while (local_18 != 0);
                }
                local_c = local_c + 1;
              } while (local_c < local_38);
            }
            local_14 = local_14 + 1;
          } while (local_14 < local_2c);
        }
        local_c = 0;
        do {
          iVar3 = local_1dc[local_c];
          if ((iVar3 != -1) && (uVar5 = 0, local_2c != 0)) {
            local_38 = *(uint *)(*(int *)(in_ECX + 0x14) + iVar3 * 4);
            do {
              local_18 = *(int *)(local_8c[uVar5] + 0xc);
              if (local_18 != 0) {
                piVar2 = *(int **)(local_8c[uVar5] + 0x10);
                do {
                  if ((iVar3 == *piVar2) || (*(int *)(local_38 + 0x38) == *piVar2)) {
                    local_20 = 1;
                  }
                  piVar2 = piVar2 + 1;
                  local_18 = local_18 + -1;
                } while (local_18 != 0);
              }
              uVar5 = uVar5 + 1;
            } while (uVar5 < local_2c);
          }
          local_c = local_c + 1;
        } while (local_c < 0x28);
        if (local_20 == 0) goto LAB_00944510;
      }
      local_10 = local_10 + 1;
    } while (local_10 < 2);
    if (local_20 == 0) {
LAB_00944510:
      local_8c[local_2c] = (int)local_24;
      uVar5 = 0;
      do {
        iVar3 = *(int *)((int)local_1dc + uVar5);
        if ((iVar3 != -1) || (iVar3 = *(int *)((int)local_27c + uVar5), iVar3 != -1)) {
          *(int *)((int)local_13c + uVar5) = iVar3;
        }
        uVar5 = uVar5 + 4;
      } while (uVar5 < 0xa0);
      local_10 = 0;
LAB_0094454a:
      goto LAB_00944550;
    }
    local_34 = local_34 + 1;
    local_10 = local_20;
    if (local_34 != 0) goto LAB_0094454a;
  } while( true );
}


// ==== FUN_00944750 @ 0x00944750 ====

int FUN_00944750(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *local_108 [16];
  undefined4 local_c8;
  undefined4 local_c4;
  uint local_b8;
  uint local_b4;
  undefined4 local_a8;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_c = 0;
  local_28 = 0;
  local_10 = 0;
  uVar5 = *(uint *)in_ECX[0x40] & 0xfffff;
  local_24 = 1;
  local_20 = 2;
  local_1c = 3;
  iVar2 = FUN_0093d430((uint *)in_ECX[0x40],&DAT_00a2d6d8,local_108,&local_c,&local_c8,&local_28,
                       uVar5,1);
  if (iVar2 != 0) {
    iVar2 = FUN_0093d430(in_ECX[0x40],&DAT_00a2d738,local_108,&local_c,&local_c8,&local_28,uVar5,1);
    if (iVar2 != 0) {
      return iVar2;
    }
    local_10 = 1;
  }
  if (*local_108[0] != 0x50000002) {
    return 1;
  }
  local_8 = 1;
  if (1 < uVar5) {
    piVar4 = *(int **)(in_ECX[0x40] + 8);
    local_14 = *piVar4;
    iVar2 = uVar5 * 4;
    do {
      piVar4 = piVar4 + 1;
      iVar2 = iVar2 + 4;
      if (*piVar4 != local_14) {
        return 1;
      }
      if (*(int *)(iVar2 + *(int *)(in_ECX[0x40] + 8)) !=
          *(int *)(*(int *)(in_ECX[0x40] + 8) + uVar5 * 4)) {
        return 1;
      }
      local_8 = local_8 + 1;
    } while (local_8 < uVar5);
  }
  iVar2 = FUN_009149f7();
  if (iVar2 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_0091455d();
  }
  iVar2 = FUN_00914a42(0x70800002,6,uVar5,0);
  if ((-1 < iVar2) && (iVar2 = FUN_00914593(), uVar1 = local_8, -1 < iVar2)) {
    puVar6 = *(undefined4 **)(in_ECX[0x40] + 0x10);
    puVar7 = *(undefined4 **)(local_8 + 0x10);
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    puVar6 = *(undefined4 **)(local_8 + 8);
    *puVar6 = local_c8;
    puVar6[1] = local_c4;
    if (local_10 == 0) {
      iVar2 = *(int *)(local_8 + 8);
      *(uint *)(iVar2 + 8) = local_b8;
    }
    else {
      iVar2 = *(int *)(in_ECX[5] + local_b4 * 4);
      local_18 = local_b8;
      iVar3 = *(int *)(in_ECX[5] + local_b8 * 4);
      uVar5 = *(uint *)(iVar3 + 0x38);
      local_10 = local_b4;
      if (uVar5 != 0xffffffff) {
        iVar3 = *(int *)(in_ECX[5] + uVar5 * 4);
        local_18 = uVar5;
      }
      uVar5 = *(uint *)(iVar2 + 0x38);
      if (uVar5 != 0xffffffff) {
        iVar2 = *(int *)(in_ECX[5] + uVar5 * 4);
        local_10 = uVar5;
      }
      local_14 = FUN_00915318(*(undefined4 *)(iVar3 + 4),*(undefined4 *)(iVar3 + 0xc),
                              *(undefined4 *)(iVar3 + 0x10),0);
      local_b4 = FUN_00915318(*(undefined4 *)(iVar2 + 4),*(undefined4 *)(iVar2 + 0xc),
                              *(undefined4 *)(iVar2 + 0x10),0);
      local_c = local_b4;
      if ((local_14 == -1) || (local_b4 == 0xffffffff)) {
        iVar2 = -0x7ff8fff2;
        goto LAB_009449fb;
      }
      *(uint *)(*(int *)(local_14 * 4 + in_ECX[5]) + 0x3c) = local_18 ^ 0x80000;
      *(uint *)(*(int *)(local_b4 * 4 + in_ECX[5]) + 0x3c) = local_10 ^ 0x80000;
      *(uint *)(*(int *)(local_14 * 4 + in_ECX[5]) + 0x38) = local_18;
      *(uint *)(*(int *)(local_b4 * 4 + in_ECX[5]) + 0x38) = local_10;
      *(int *)(*(int *)(uVar1 + 8) + 8) = local_14;
      iVar2 = *(int *)(uVar1 + 8);
    }
    *(uint *)(iVar2 + 0xc) = local_b4;
    *(undefined4 *)(*(int *)(uVar1 + 8) + 0x10) = local_a8;
    *(undefined4 *)(*(int *)(uVar1 + 8) + 0x14) = local_a8;
    iVar2 = (**(code **)(*in_ECX + 0x30))();
    if (iVar2 == 0) {
      iVar2 = FUN_00914ca1();
    }
    else {
      iVar2 = 1;
    }
  }
LAB_009449fb:
  if (local_8 != 0) {
    FUN_008f4adb();
  }
  return iVar2;
}


// ==== FUN_00944a10 @ 0x00944a10 ====

int FUN_00944a10(void)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  int iVar3;
  
  if (*(int *)in_ECX[0x40] != 0x50000002) {
    return 1;
  }
  iVar1 = FUN_009149f7(0x74);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0091455d();
  }
  if (iVar1 == 0) {
    iVar3 = -0x7ff8fff2;
  }
  else {
    iVar3 = FUN_00914a42(0x70800002,6,1,0);
    if ((-1 < iVar3) && (iVar3 = FUN_00914593(), -1 < iVar3)) {
      **(undefined4 **)(iVar1 + 0x10) = **(undefined4 **)(in_ECX[0x40] + 0x10);
      uVar2 = 0;
      do {
        *(undefined4 *)(uVar2 + *(int *)(iVar1 + 8)) =
             *(undefined4 *)(uVar2 + *(int *)(in_ECX[0x40] + 8));
        uVar2 = uVar2 + 4;
      } while (uVar2 < 0x10);
      iVar3 = FUN_00915318(in_ECX[0x1e],0,0,0);
      if (iVar3 == -1) {
        return -0x7ff8fff2;
      }
      *(int *)(*(int *)(iVar1 + 8) + 0x10) = iVar3;
      *(int *)(*(int *)(iVar1 + 8) + 0x14) = iVar3;
      iVar1 = (**(code **)(*in_ECX + 0x30))();
      if (iVar1 == 0) {
        iVar3 = FUN_00914ca1();
      }
      else {
        iVar3 = 1;
      }
    }
    FUN_008f4adb();
  }
  return iVar3;
}


// ==== FUN_00944b06 @ 0x00944b06 ====

undefined4 FUN_00944b06(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int local_18;
  int *local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  iVar2 = param_1;
  iVar3 = (**(code **)(*in_ECX + 0x20))(param_1,0);
  if (iVar3 == 0) {
    local_8 = 0;
    local_14 = *(int **)(param_1 + 0xc);
    param_1 = 0xffffffff;
    if (local_14 != (int *)0x0) {
      piVar4 = *(int **)(iVar2 + 0x10);
      do {
        iVar3 = *(int *)(in_ECX[5] + *piVar4 * 4);
        uVar5 = *(uint *)(iVar3 + 0x4c);
        if (local_8 < uVar5) {
          local_8 = uVar5;
        }
        uVar5 = *(uint *)(iVar3 + 0x48);
        if (uVar5 < param_1) {
          param_1 = uVar5;
        }
        piVar4 = piVar4 + 1;
        local_14 = (int *)((int)local_14 + -1);
      } while (local_14 != (int *)0x0);
    }
    local_18 = *(int *)(iVar2 + 4);
    if (local_18 != 0) {
      local_14 = *(int **)(iVar2 + 8);
      do {
        iVar3 = *(int *)(in_ECX[5] + *local_14 * 4);
        if (((*(byte *)(*(int *)(in_ECX[4] + *(int *)(iVar3 + 4) * 4) + 4) & 2) != 0) &&
           (*(int *)(iVar3 + 0x48) != -1)) {
          uVar5 = *(int *)(iVar3 + 0x48) + 1;
          if (local_8 < uVar5) {
            local_8 = uVar5;
          }
          while (uVar5 = *(uint *)(iVar3 + 0x50), uVar5 <= param_1) {
            if ((uVar5 == 0xffffffff) || (uVar6 = 0, param_3 == 0)) {
LAB_00944c21:
              param_1 = *(int *)(iVar3 + 0x50) - 1;
              break;
            }
            do {
              if (*(int *)(param_2 + uVar6 * 4) == *(int *)(in_ECX[6] + uVar5 * 4)) break;
              uVar6 = uVar6 + 1;
            } while (uVar6 < param_3);
            if (param_3 <= uVar6) goto LAB_00944c21;
            iVar1 = *(int *)(param_2 + uVar6 * 4);
            local_c = 0;
            if (*(int *)(iVar1 + 0xc) != 0) {
              local_10 = *(int **)(iVar1 + 0x10);
              do {
                if (*(int *)(iVar3 + 0x10) == *(int *)(*(int *)(in_ECX[5] + *local_10 * 4) + 0x10))
                break;
                local_c = local_c + 1;
                local_10 = local_10 + 1;
              } while (local_c < *(uint *)(iVar1 + 0xc));
            }
            if (*(uint *)(iVar1 + 0xc) <= local_c) goto LAB_00944c21;
            iVar3 = *(int *)(in_ECX[5] + *(int *)(*(int *)(iVar1 + 0x10) + local_c * 4) * 4);
          }
        }
        local_14 = local_14 + 1;
        local_18 = local_18 + -1;
      } while (local_18 != 0);
    }
    uVar5 = 0;
    if (param_3 == 0) {
      uVar6 = 0;
    }
    else {
      do {
        uVar6 = *(uint *)(*(int *)(in_ECX[5] + **(int **)(*(int *)(param_2 + uVar5 * 4) + 0x10) * 4)
                         + 0x48);
        if ((local_8 <= uVar6) && (uVar6 <= param_1)) break;
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_3);
    }
    if ((uVar5 != param_3) && (iVar3 = (**(code **)(*in_ECX + 0x34))(iVar2,uVar6), iVar3 == 0)) {
      uVar5 = 0;
      if (param_3 != 0) {
        do {
          **(undefined4 **)(param_2 + uVar5 * 4) = 0;
          uVar5 = uVar5 + 1;
        } while (uVar5 < param_3);
      }
      if (*(int *)(in_ECX[6] + uVar6 * 4) != 0) {
        FUN_008f4adb(1);
      }
      *(int *)(in_ECX[6] + uVar6 * 4) = iVar2;
      uVar5 = 0;
      if (*(int *)(iVar2 + 0xc) != 0) {
        do {
          iVar3 = uVar5 * 4;
          uVar5 = uVar5 + 1;
          *(uint *)(*(int *)(in_ECX[5] + *(int *)(*(int *)(iVar2 + 0x10) + iVar3) * 4) + 0x48) =
               uVar6;
        } while (uVar5 < *(uint *)(iVar2 + 0xc));
      }
      return 0;
    }
  }
  if (iVar2 != 0) {
    FUN_008f4adb(1);
  }
  return 1;
}


// ==== FUN_00944cdb @ 0x00944cdb ====

undefined4 FUN_00944cdb(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint local_10;
  int *local_c;
  int *local_8;
  
  uVar2 = **(uint **)(in_ECX + 0x100) & 0xfffff;
  local_10 = 0;
  if (uVar2 != 0) {
    local_8 = *(int **)(*(int *)(in_ECX + 0x100) + 8);
    local_c = local_8 + uVar2;
    do {
      iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + *local_8 * 4);
      iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + *local_c * 4);
      if ((((*(int *)(iVar3 + 4) != *(int *)(iVar1 + 4)) ||
           (*(int *)(iVar3 + 8) != *(int *)(iVar1 + 8))) ||
          (*(int *)(iVar3 + 0xc) != *(int *)(iVar1 + 0xc))) ||
         ((*(int *)(iVar3 + 0x10) != *(int *)(iVar1 + 0x10) ||
          ((*(uint *)(iVar1 + 0x3c) ^ *(uint *)(iVar3 + 0x3c)) != 0x80000)))) {
        return 1;
      }
      local_10 = local_10 + 1;
      local_8 = local_8 + 1;
      local_c = local_c + 1;
    } while (local_10 < uVar2);
  }
  **(uint **)(in_ECX + 0x100) = uVar2 | 0x70000000;
  *(uint *)(*(int *)(in_ECX + 0x100) + 4) = uVar2;
  if ((uVar2 != 0) &&
     ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x14) + **(int **)(*(int *)(in_ECX + 0x100) + 8) * 4) +
                0x3e) & 8) != 0)) {
    puVar5 = *(undefined4 **)(*(int *)(in_ECX + 0x100) + 8);
    puVar4 = puVar5 + uVar2;
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
  }
  return 0;
}


// ==== FUN_00944dce @ 0x00944dce ====

undefined4 FUN_00944dce(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  int *local_10;
  int *local_c;
  uint local_8;
  
  uVar5 = **(uint **)(in_ECX + 0x100) & 0xfffff;
  local_8 = 0;
  if (uVar5 != 0) {
    uVar1 = (*(uint **)(in_ECX + 0x100))[2];
    local_10 = (int *)(uVar1 + uVar5 * 4);
    local_c = (int *)(uVar1 + uVar5 * 8);
    do {
      iVar2 = *(int *)(uVar1 + local_8 * 4);
      iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + iVar2 * 4);
      iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *local_c * 4);
      if ((iVar2 != *local_10) ||
         (((iVar2 = *(int *)(iVar4 + 0x38),
           iVar2 != *(int *)(local_8 * 4 + *(int *)(*(int *)(in_ECX + 0x100) + 8)) &&
           ((iVar2 == -1 || (iVar2 != *(int *)(iVar3 + 0x38))))) ||
          ((*(uint *)(iVar4 + 0x3c) ^ 0x80000) != *(uint *)(iVar3 + 0x3c))))) {
        return 1;
      }
      local_8 = local_8 + 1;
      local_c = local_c + 1;
      local_10 = local_10 + 1;
    } while (local_8 < uVar5);
  }
  **(uint **)(in_ECX + 0x100) = uVar5 | 0x70000000;
  *(uint *)(*(int *)(in_ECX + 0x100) + 4) = uVar5;
  return 0;
}


// ==== FUN_00944ea0 @ 0x00944ea0 ====

undefined4 FUN_00944ea0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int in_ECX;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int *local_14;
  uint local_c;
  int local_8;
  
  uVar8 = **(uint **)(in_ECX + 0x100) & 0xfffff;
  local_c = 0;
  if (uVar8 != 0) {
    iVar1 = *(int *)(in_ECX + 0x14);
    iVar2 = *(int *)(*(int *)(in_ECX + 0x100) + 8);
    local_8 = uVar8 << 3;
    local_14 = (int *)(iVar2 + uVar8 * 4);
    do {
      iVar3 = *(int *)(iVar2 + local_c * 4);
      iVar4 = *(int *)(iVar1 + iVar3 * 4);
      iVar5 = *(int *)(iVar1 + *local_14 * 4);
      iVar6 = *(int *)(iVar1 + *(int *)(local_8 + iVar2) * 4);
      if (iVar3 != *local_14) {
        return 1;
      }
      iVar3 = *(int *)(local_8 + *(int *)(*(int *)(in_ECX + 0x100) + 8));
      iVar7 = *(int *)(iVar5 + 0x38);
      if (iVar7 != iVar3) {
        if (iVar7 == -1) {
          return 1;
        }
        if (iVar7 != *(int *)(iVar6 + 0x38)) {
          return 1;
        }
      }
      if ((*(uint *)(iVar5 + 0x3c) ^ 0x80000) != *(uint *)(iVar6 + 0x3c)) {
        return 1;
      }
      iVar5 = *(int *)(iVar4 + 0x38);
      if (iVar5 != iVar3) {
        if (iVar5 == -1) {
          return 1;
        }
        if (iVar5 != *(int *)(iVar6 + 0x38)) {
          return 1;
        }
      }
      if ((*(uint *)(iVar4 + 0x3c) ^ 0x80000) != *(uint *)(iVar6 + 0x3c)) {
        return 1;
      }
      local_c = local_c + 1;
      local_14 = local_14 + 1;
      local_8 = local_8 + 4;
    } while (local_c < uVar8);
  }
  **(uint **)(in_ECX + 0x100) = uVar8 | 0x70000000;
  *(uint *)(*(int *)(in_ECX + 0x100) + 4) = uVar8;
  puVar10 = *(undefined4 **)(*(int *)(in_ECX + 0x100) + 8);
  puVar9 = puVar10 + uVar8 * 2;
  for (; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar10 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar10 = puVar10 + 1;
  }
  return 0;
}


// ==== FUN_00944fd2 @ 0x00944fd2 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00944fd2(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  int in_ECX;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  uint local_8;
  
  iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + param_1 * 4);
  if ((*(int *)(iVar2 + 0x58) == *(int *)(iVar2 + 0x54)) &&
     (uVar4 = 0xffffffff, *(int *)(iVar2 + 0x48) != -1)) {
    puVar3 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar2 + 0x48) * 4);
    if ((*puVar3 & 0xfff00000) == 0x20400000) {
      local_8 = 0;
      if (puVar3[3] != 0) {
        piVar6 = (int *)puVar3[4];
        do {
          if (*piVar6 == param_1) {
            uVar4 = local_8;
          }
          local_8 = local_8 + 1;
          piVar6 = piVar6 + 1;
        } while (local_8 < puVar3[3]);
        if (uVar4 != 0xffffffff) {
          piVar6 = (int *)(puVar3[2] + uVar4 * 4);
          piVar1 = (int *)(puVar3[2] + (uVar4 + (*puVar3 & 0xfffff)) * 4);
          if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                 *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar1 * 4) + 4) * 4)
                        + 5) & 1) == 0) {
            if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                   *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar6 * 4) + 4) * 4
                                   ) + 5) & 1) == 0) {
              return 1;
            }
            piVar5 = piVar1;
          }
          else {
            piVar5 = piVar6;
            piVar6 = piVar1;
          }
          if ((*(double *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar6 * 4) + 0x20) == _DAT_0099d0a0)
             && ((*(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar5 * 4) + 0x3c) & 0x1f0000) ==
                 0x80000)) {
            *param_3 = *piVar5;
            *param_2 = (int)puVar3;
            return 0;
          }
        }
      }
    }
  }
  return 1;
}


// ==== FUN_009450e9 @ 0x009450e9 ====

int FUN_009450e9(int param_1,undefined4 *param_2,int *param_3,undefined4 *param_4,uint *param_5,
                int param_6)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int *in_ECX;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  uint uVar12;
  undefined4 *puVar13;
  int local_34 [4];
  undefined4 *local_24 [4];
  uint local_14;
  int local_10;
  int *local_c;
  uint local_8;
  
  local_24[0] = (undefined4 *)0x0;
  local_24[1] = (undefined4 *)0x0;
  local_24[2] = (undefined4 *)0x0;
  uVar10 = *param_5 & 0xfffff;
  local_14 = uVar10;
  local_24[3] = (undefined4 *)0x0;
  local_c = in_ECX;
  if ((*(byte *)((int)in_ECX + 0x6f) & 2) == 0) {
    uVar12 = 0;
    if (uVar10 != 0) {
      do {
        iVar6 = FUN_00944fd2(*(undefined4 *)(param_1 + uVar12 * 4),local_24 + uVar12,
                             local_34 + uVar12);
        if (iVar6 != 0) {
          return iVar6;
        }
        uVar12 = uVar12 + 1;
      } while (uVar12 < uVar10);
    }
    local_8 = 0;
    if (uVar10 != 0) {
      local_10 = (int)local_24 - (int)param_3;
      piVar7 = param_3;
      do {
        if (((*(int *)(*(int *)(in_ECX[5] +
                               *(int *)(((int)local_34 - (int)param_3) + (int)piVar7) * 4) + 0x38)
              != *piVar7) || ((*(byte *)(*(int *)(in_ECX[5] + *piVar7 * 4) + 0x3e) & 0x1f) != 0)) ||
           (*(undefined4 **)(((int)local_24 - (int)param_3) + (int)piVar7) != local_24[0]))
        goto LAB_009453cf;
        local_8 = local_8 + 1;
        piVar7 = piVar7 + 1;
      } while (local_8 < uVar10);
    }
    uVar12 = 0;
    if (local_24[0][3] != 0) {
      do {
        uVar9 = 0;
        local_8 = 1;
        if (uVar10 == 0) goto LAB_009453cf;
        do {
          if (*(int *)(local_24[0][4] + uVar12 * 4) == *(int *)(param_1 + uVar9 * 4)) {
            local_8 = 0;
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 < uVar10);
        if (local_8 != 0) goto LAB_009453cf;
        uVar12 = uVar12 + 1;
      } while (uVar12 < (uint)local_24[0][3]);
    }
  }
  else {
    local_8 = 0;
    if (uVar10 != 0) {
      piVar7 = param_3;
      do {
        iVar6 = *(int *)(in_ECX[5] + *(int *)((int)piVar7 + (param_1 - (int)param_3)) * 4);
        if ((*(int *)(iVar6 + 0x38) != *piVar7) || ((*(uint *)(iVar6 + 0x3c) & 0x1f0000) != 0x10000)
           ) goto LAB_009453cf;
        puVar1 = *(uint **)(in_ECX[5] + *piVar7 * 4);
        uVar12 = puVar1[0xf];
        if (((uVar12 & 0x1f0000) != 0) ||
           (((uVar12 & 0x200) == 0 &&
            ((uVar12 = *puVar1, (uVar12 & 4) == 0 || ((uVar12 & 0x10) == 0)))))) goto LAB_009453cf;
        local_8 = local_8 + 1;
        piVar7 = piVar7 + 1;
      } while (local_8 < uVar10);
    }
  }
  iVar6 = FUN_009149f7(0x74);
  if (iVar6 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = FUN_0091455d();
  }
  if (iVar6 == 0) {
    iVar8 = -0x7ff8fff2;
  }
  else {
    iVar8 = FUN_00914a42(uVar10 | 0x70100000,uVar10 * 3,uVar10,0);
    if ((-1 < iVar8) && (iVar8 = FUN_00914593(param_5), -1 < iVar8)) {
      puVar11 = *(undefined4 **)(param_6 + 0x10);
      puVar13 = *(undefined4 **)(iVar6 + 0x10);
      for (uVar12 = uVar10; uVar12 != 0; uVar12 = uVar12 - 1) {
        *puVar13 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar13 = puVar13 + 1;
      }
      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined1 *)puVar13 = *(undefined1 *)puVar11;
        puVar11 = (undefined4 *)((int)puVar11 + 1);
        puVar13 = (undefined4 *)((int)puVar13 + 1);
      }
      piVar7 = *(int **)(iVar6 + 8);
      for (uVar12 = uVar10; uVar12 != 0; uVar12 = uVar12 - 1) {
        *piVar7 = *param_3;
        param_3 = param_3 + 1;
        piVar7 = piVar7 + 1;
      }
      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(char *)piVar7 = (char)*param_3;
        param_3 = (int *)((int)param_3 + 1);
        piVar7 = (int *)((int)piVar7 + 1);
      }
      puVar11 = (undefined4 *)(*(int *)(iVar6 + 8) + local_14 * 8);
      for (uVar12 = uVar10; uVar12 != 0; uVar12 = uVar12 - 1) {
        *puVar11 = *param_2;
        param_2 = param_2 + 1;
        puVar11 = puVar11 + 1;
      }
      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined1 *)puVar11 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      puVar11 = (undefined4 *)(*(int *)(iVar6 + 8) + uVar10 * 4);
      for (; uVar10 != 0; uVar10 = uVar10 - 1) {
        *puVar11 = *param_4;
        param_4 = param_4 + 1;
        puVar11 = puVar11 + 1;
      }
      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined1 *)puVar11 = *(undefined1 *)param_4;
        param_4 = (undefined4 *)((int)param_4 + 1);
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      iVar8 = local_c[5];
      iVar2 = *(int *)(iVar8 + **(int **)(iVar6 + 0x10) * 4);
      iVar3 = *(int *)(iVar8 + **(int **)(iVar6 + 8) * 4);
      iVar8 = *(int *)(iVar8 + (*(int **)(iVar6 + 8))[local_14 * 2] * 4);
      iVar4 = *(int *)(iVar2 + 4);
      bVar5 = false;
      if (((((iVar4 == *(int *)(iVar3 + 4)) && (*(int *)(iVar2 + 0xc) == *(int *)(iVar3 + 0xc))) ||
           ((iVar4 == *(int *)(iVar8 + 4) && (*(int *)(iVar2 + 0xc) == *(int *)(iVar8 + 0xc))))) ||
          (iVar4 != local_c[0x22])) && ((*(byte *)((int)local_c + 0x6f) & 2) == 0)) {
        bVar5 = true;
      }
      iVar8 = (**(code **)(*local_c + 0x20))(iVar6,0);
      if ((iVar8 != 0) ||
         ((((*(byte *)(*(int *)(local_c[4] + *(int *)(iVar2 + 4) * 4) + 4) & 0x20) != 0 || (bVar5))
          && ((*(byte *)((int)local_c + 0x6f) & 2) == 0)))) {
        FUN_008f4adb(1);
LAB_009453cf:
        iVar8 = 1;
      }
      else {
        iVar8 = FUN_00914ca1(iVar6);
        if (-1 < iVar8) {
          FUN_008f4adb(1);
          *param_5 = 0;
          if (local_24[0] != (undefined4 *)0x0) {
            *local_24[0] = 0;
          }
          iVar8 = 0;
        }
      }
    }
  }
  return iVar8;
}


// ==== FUN_009453d9 @ 0x009453d9 ====

undefined4 FUN_009453d9(int param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int *piVar4;
  int in_ECX;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + param_1 * 4);
  uVar6 = *(uint *)(iVar1 + 0x54);
  if (((uVar6 != 0xffffffff) && ((*(byte *)(in_ECX + 0x6f) & 0x20) == 0)) &&
     (uVar2 = *(uint *)(iVar1 + 0x58), uVar6 <= uVar2)) {
    piVar4 = (int *)(*(int *)(in_ECX + 0x18) + uVar6 * 4);
    do {
      puVar3 = (uint *)*piVar4;
      if ((*puVar3 & 0xf0000000) == 0x60000000) {
        uVar7 = 0;
        if (puVar3[1] != 0) {
          piVar5 = (int *)puVar3[2];
          do {
            if (*piVar5 == param_1) {
              return 1;
            }
            uVar7 = uVar7 + 1;
            piVar5 = piVar5 + 1;
          } while (uVar7 < puVar3[1]);
        }
      }
      uVar6 = uVar6 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar6 <= uVar2);
  }
  return 0;
}


// ==== FUN_00945449 @ 0x00945449 ====

int FUN_00945449(int param_1)

{
  int **ppiVar1;
  uint *puVar2;
  int *piVar3;
  int iVar4;
  int *in_ECX;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined4 *puVar10;
  int *piVar11;
  bool bVar12;
  int local_118 [4];
  undefined4 local_108 [4];
  undefined4 local_f8 [4];
  int local_e8 [28];
  int *local_78 [16];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  int *local_24;
  undefined4 *local_20;
  int local_1c;
  int *local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  int *local_8;
  
  local_10 = 0;
  local_38 = 0;
  uVar7 = *(uint *)in_ECX[0x40] & 0xfffff;
  local_34 = 1;
  local_30 = 2;
  local_2c = 3;
  local_28 = uVar7;
  local_24 = in_ECX;
  iVar4 = FUN_0093d430((uint *)in_ECX[0x40],&DAT_00a2bff8,local_78,&local_10,local_118,&local_38,
                       uVar7,param_1);
  if ((iVar4 == 0) ||
     (iVar4 = FUN_0093d430(in_ECX[0x40],&DAT_00a2c058,local_78,&local_10,local_118,&local_38,uVar7,
                           param_1), iVar4 == 0)) {
    local_14 = 0;
    local_18 = local_118;
    local_20 = local_108;
    do {
      local_c = 0;
      if (uVar7 != 0) {
        local_1c = (in_ECX[0x1b] << 6) >> 0x1f;
        local_8 = local_18;
        do {
          iVar4 = *(int *)(in_ECX[5] + *local_8 * 4);
          iVar6 = *(int *)(in_ECX[5] + local_e8[local_c] * 4);
          if (in_ECX[0x1b] << 6 < 0) {
            if ((*(uint *)(iVar6 + 0x3c) ^ *(uint *)(iVar4 + 0x3c)) != 0x80000) break;
            bVar12 = *(int *)(iVar6 + 0x38) == *local_8;
          }
          else {
            if ((((*(int *)(iVar4 + 4) != *(int *)(iVar6 + 4)) ||
                 (*(int *)(iVar4 + 8) != *(int *)(iVar6 + 8))) ||
                (*(int *)(iVar4 + 0xc) != *(int *)(iVar6 + 0xc))) ||
               (*(int *)(iVar4 + 0x10) != *(int *)(iVar6 + 0x10))) break;
            bVar12 = (*(uint *)(iVar6 + 0x3c) ^ *(uint *)(iVar4 + 0x3c)) == 0x80000;
          }
          if (!bVar12) break;
          local_c = local_c + 1;
          local_8 = local_8 + 1;
        } while (local_c < uVar7);
      }
      if (local_c == uVar7) {
        iVar4 = FUN_009149f7(0x74);
        if (iVar4 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_0091455d();
        }
        if (iVar4 == 0) {
          return -0x7ff8fff2;
        }
        local_8 = (int *)FUN_00914a42(uVar7 & 0xfffff | 0x70100000,uVar7 * 3,uVar7,0);
        if ((int)local_8 < 0) {
LAB_00945712:
          FUN_008f4adb(1);
          return (int)local_8;
        }
        local_8 = (int *)FUN_00914593(in_ECX[0x40]);
        piVar3 = local_24;
        if ((int)local_8 < 0) goto LAB_00945712;
        puVar8 = *(undefined4 **)(in_ECX[0x40] + 0x10);
        puVar10 = *(undefined4 **)(iVar4 + 0x10);
        for (uVar5 = uVar7 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar10 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar10 = puVar10 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
          puVar8 = (undefined4 *)((int)puVar8 + 1);
          puVar10 = (undefined4 *)((int)puVar10 + 1);
        }
        puVar8 = local_f8;
        puVar10 = *(undefined4 **)(iVar4 + 8);
        for (uVar5 = uVar7 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar10 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar10 = puVar10 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
          puVar8 = (undefined4 *)((int)puVar8 + 1);
          puVar10 = (undefined4 *)((int)puVar10 + 1);
        }
        puVar8 = local_20;
        puVar10 = (undefined4 *)(*(int *)(iVar4 + 8) + uVar7 * 4);
        for (uVar5 = uVar7 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar10 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar10 = puVar10 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
          puVar8 = (undefined4 *)((int)puVar8 + 1);
          puVar10 = (undefined4 *)((int)puVar10 + 1);
        }
        local_c = 0;
        piVar9 = local_e8;
        piVar11 = (int *)(*(int *)(iVar4 + 8) + local_28 * 8);
        for (uVar7 = uVar7 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
          *piVar11 = *piVar9;
          piVar9 = piVar9 + 1;
          piVar11 = piVar11 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(char *)piVar11 = (char)*piVar9;
          piVar9 = (int *)((int)piVar9 + 1);
          piVar11 = (int *)((int)piVar11 + 1);
        }
        iVar6 = local_24[5];
        local_8 = *(int **)(iVar6 + **(int **)(iVar4 + 0x10) * 4);
        puVar2 = *(uint **)(iVar6 + **(int **)(iVar4 + 8) * 4);
        iVar6 = *(int *)(iVar6 + (*(int **)(iVar4 + 8))[local_28 * 2] * 4);
        uVar7 = local_8[1];
        if (((((uVar7 == puVar2[1]) && (local_8[3] == puVar2[3])) ||
             ((uVar7 == *(uint *)(iVar6 + 4) && (local_8[3] == *(int *)(iVar6 + 0xc))))) ||
            (uVar7 != local_24[0x22])) && ((*(byte *)((int)local_24 + 0x6f) & 2) == 0)) {
          local_c = 1;
        }
        iVar6 = (**(code **)(*local_24 + 0x20))(iVar4,0);
        if ((iVar6 == 0) &&
           ((((*(byte *)(*(int *)(piVar3[4] + local_8[1] * 4) + 4) & 0x20) == 0 && (local_c == 0))
            || ((*(byte *)((int)piVar3 + 0x6f) & 2) != 0)))) {
          if (param_1 == 0) {
            local_1c = *local_78[0];
            *local_78[0] = 0;
          }
          if ((((*(byte *)((int)piVar3 + 0x6f) & 2) != 0) &&
              ((*(byte *)((int)puVar2 + 0x3d) & 2) == 0)) &&
             (((*puVar2 & 4) == 0 || ((*puVar2 & 0x10) == 0)))) {
            FUN_008f4adb(1);
            FUN_0091a096(piVar3,*(undefined4 *)(piVar3[0x40] + 0x3c),0x125f,
                         s_cannot_match_lerp_because_lerp_f_00a2db6c);
            *local_78[0] = local_1c;
            return 1;
          }
          if (param_1 == 0) {
            uVar7 = 0;
            if (local_10 != 0) {
              do {
                ppiVar1 = local_78 + uVar7;
                uVar7 = uVar7 + 1;
                **ppiVar1 = 0;
              } while (uVar7 < local_10);
            }
            if (*(int *)(piVar3[6] + piVar3[0x3f] * 4) != 0) {
              FUN_008f4adb(1);
            }
            *(int *)(piVar3[6] + piVar3[0x3f] * 4) = iVar4;
          }
          else {
            iVar4 = FUN_00914ca1(iVar4);
            FUN_008f4adb(1);
            if (iVar4 < 0) {
              return iVar4;
            }
            iVar4 = FUN_00914593(piVar3[0x40]);
            if (iVar4 < 0) {
              return iVar4;
            }
          }
          return 0;
        }
        FUN_008f4adb(1);
        uVar7 = local_28;
        in_ECX = local_24;
      }
      local_14 = local_14 + 1;
      local_18 = local_18 + 4;
      local_20 = local_20 + -4;
    } while (local_14 < 2);
  }
  return 1;
}


// ==== FUN_009457ec @ 0x009457ec ====

undefined4 FUN_009457ec(int param_1,int *param_2,uint param_3,int param_4)

{
  uint *puVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  int in_ECX;
  int *piVar5;
  uint local_c;
  int local_8;
  
  if (param_3 < 0x1f) {
    if (*(uint *)(in_ECX + 0xfc) < *(uint *)(in_ECX + 0xc)) {
      do {
        puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0xfc) * 4);
        uVar4 = *puVar1 & 0xfff00000;
        if ((uVar4 == 0x73400000) ||
           ((param_4 != 0 && ((uVar4 == 0x73100000 || (uVar4 == 0x73300000)))))) break;
        if ((uVar4 == 0x73000000) ||
           (((uVar4 == 0x73300000 || (uVar4 == 0x73100000)) || (uVar4 == 0x73200000)))) {
          local_8 = 1;
          if ((uVar4 == 0x73100000) || (uVar4 == 0x73200000)) {
            local_8 = 0;
          }
          bVar2 = false;
          if (param_3 != 0) {
            local_c = param_3;
            piVar5 = param_2;
            do {
              piVar5 = piVar5 + 1;
              if ((*(int *)puVar1[4] == *(int *)((param_1 - (int)param_2) + (int)piVar5)) &&
                 (*piVar5 == local_8)) {
                bVar2 = true;
              }
              local_c = local_c - 1;
            } while (local_c != 0);
            if (bVar2) {
              if ((uVar4 == 0x73000000) || (uVar4 == 0x73200000)) {
                *puVar1 = 0;
              }
              else {
                *puVar1 = 0x73400000;
              }
              *(int *)(in_ECX + 0xfc) = *(int *)(in_ECX + 0xfc) + 1;
              *(undefined4 *)(param_1 + 4 + param_3 * 4) = *(undefined4 *)(param_1 + param_3 * 4);
              (param_2 + param_3)[1] = param_2[param_3];
              FUN_009457ec(param_1,param_2,param_3 + 1,1);
              puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0xfc) * 4);
              uVar4 = *puVar1 & 0xfff00000;
              if (uVar4 == 0x73400000) {
                *puVar1 = 0;
              }
              else if (uVar4 == 0x73100000) {
                *puVar1 = 0x73200001;
              }
              else if (uVar4 == 0x73300000) {
                *puVar1 = 0x73000001;
              }
              goto LAB_009459a4;
            }
          }
          if ((uVar4 == 0x73000000) || (uVar4 == 0x73200000)) {
            *(int *)(in_ECX + 0xfc) = *(int *)(in_ECX + 0xfc) + 1;
            *(undefined4 *)(param_1 + 4 + param_3 * 4) = *(undefined4 *)puVar1[4];
            param_2[param_3 + 1] = local_8;
            FUN_009457ec(param_1,param_2,param_3 + 1,0);
          }
        }
LAB_009459a4:
        if (*(uint *)(in_ECX + 0xc) <= *(uint *)(in_ECX + 0xfc)) {
          return 0x80004005;
        }
        uVar4 = **(uint **)(*(int *)(in_ECX + 0x18) + *(uint *)(in_ECX + 0xfc) * 4) & 0xfff00000;
        if ((uVar4 == 0x73100000) || (uVar4 == 0x73300000)) {
          param_2[param_3] = (uint)(param_2[param_3] == 0);
        }
        *(int *)(in_ECX + 0xfc) = *(int *)(in_ECX + 0xfc) + 1;
      } while (*(uint *)(in_ECX + 0xfc) < *(uint *)(in_ECX + 0xc));
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0x80004005;
  }
  return uVar3;
}


// ==== FUN_009459fa @ 0x009459fa ====

undefined4 FUN_009459fa(uint param_1,uint param_2,int param_3,int *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined4 uVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int in_ECX;
  int *piVar10;
  uint local_c;
  
  if (*(int *)(param_3 + 0x30) == -1) {
    puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x10) + *(int *)(param_3 + 4) * 4);
    if ((puVar1[1] & 0x800) != 0) {
      param_1 = *puVar1;
    }
    iVar7 = FUN_009152bf(param_1,puVar1[1] | param_2 | 0x40,0xffffffff,4);
    if (iVar7 == -1) {
      return 0x8007000e;
    }
    if ((*(byte *)((int)puVar1 + 5) & 1) != 0) {
      iVar7 = FUN_00915318(iVar7,*(undefined4 *)(param_3 + 100),0,*(undefined8 *)(param_3 + 0x20));
      *(int *)(param_3 + 0x30) = iVar7;
      if (iVar7 == -1) {
        return 0x8007000e;
      }
      *param_4 = iVar7;
      FUN_00914f00();
      return 0;
    }
    uVar2 = *(uint *)(in_ECX + 8);
    bVar6 = false;
    param_1 = 0;
    if (uVar2 != 0) {
      do {
        iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + param_1 * 4);
        if (((((*(int *)(iVar3 + 4) == *(int *)(param_3 + 4)) &&
              (*(int *)(iVar3 + 0x60) == *(int *)(param_3 + 0x60))) && (*(int *)(iVar3 + 0x60) != 0)
             ) && (*(int *)(iVar3 + 8) == -1)) || (param_3 == iVar3)) {
          iVar8 = FUN_00915318(iVar7,*(undefined4 *)(iVar3 + 100),0,*(undefined8 *)(iVar3 + 0x20));
          *(int *)(iVar3 + 0x30) = iVar8;
          if (iVar8 == -1) {
            return 0x8007000e;
          }
          iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + iVar8 * 4);
          FUN_00914f00();
          *(int *)(iVar8 + 0x70) = *(int *)(iVar8 + 100) << 2;
          if (*(int *)(iVar3 + 0x44) != -1) {
            bVar6 = true;
          }
        }
        param_1 = param_1 + 1;
      } while (param_1 < uVar2);
    }
    iVar7 = *(int *)(in_ECX + 0xe0);
    if ((iVar7 != 0) && (bVar6)) {
      if ((param_2 & 0x2000) == 0) {
        iVar7 = *(int *)(iVar7 + 0xb8);
      }
      else {
        iVar7 = *(int *)(iVar7 + 0xb4);
      }
      if (iVar7 == -1) {
        return 0x8007000e;
      }
      local_c = 0;
      if (uVar2 != 0) {
        do {
          iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + local_c * 4);
          if ((((*(int *)(iVar3 + 4) == *(int *)(param_3 + 4)) &&
               (*(int *)(iVar3 + 0x60) == *(int *)(param_3 + 0x60))) &&
              ((*(int *)(iVar3 + 0x60) != 0 && (*(int *)(iVar3 + 8) == -1)))) || (param_3 == iVar3))
          {
            iVar8 = FUN_00915318(iVar7,*(undefined4 *)(iVar3 + 100),0,*(undefined8 *)(iVar3 + 0x20))
            ;
            if (iVar8 == -1) {
              return 0x8007000e;
            }
            if (*(int *)(iVar3 + 0x44) != -1) {
              iVar9 = *(int *)(*(int *)(*(int *)(*(int *)(in_ECX + 0xe0) + 0x14) +
                                       *(int *)(iVar3 + 0x44) * 4) + 0x48);
              if ((iVar9 != -1) &&
                 (puVar4 = *(uint **)(*(int *)(*(int *)(in_ECX + 0xe0) + 0x18) + iVar9 * 4),
                 (*puVar4 & 0xfff00000) == 0x10000000)) {
                param_2 = 0;
                if (puVar4[3] != 0) {
                  piVar10 = (int *)puVar4[4];
                  do {
                    if (*piVar10 == *(int *)(iVar3 + 0x44)) break;
                    param_2 = param_2 + 1;
                    piVar10 = piVar10 + 1;
                  } while (param_2 < puVar4[3]);
                }
                uVar5 = *(undefined4 *)(puVar4[2] + param_2 * 4);
                iVar9 = FUN_00915378(0x10000001,1,1);
                if (iVar9 == -1) {
                  return 0x8007000e;
                }
                iVar9 = *(int *)(*(int *)(*(int *)(in_ECX + 0xe0) + 0x18) + iVar9 * 4);
                FUN_00914593();
                **(int **)(iVar9 + 0x10) = iVar8;
                **(undefined4 **)(iVar9 + 8) = uVar5;
                *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar3 + 0x30) * 4) + 0x44) =
                     iVar8;
              }
            }
          }
          local_c = local_c + 1;
        } while (local_c < uVar2);
      }
    }
  }
  *param_4 = *(int *)(param_3 + 0x30);
  return 0;
}


// ==== FUN_00945c94 @ 0x00945c94 ====

undefined4 FUN_00945c94(uint param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  
  uVar2 = *(undefined4 *)(*(int *)(in_ECX + 0x18) + param_2 * 4);
  if (param_2 < param_1) {
    do {
      puVar1 = (undefined4 *)(*(int *)(in_ECX + 0x18) + param_2 * 4);
      param_2 = param_2 + 1;
      *puVar1 = puVar1[1];
    } while (param_2 < param_1);
  }
  else {
    for (; param_1 < param_2; param_2 = param_2 - 1) {
      puVar1 = (undefined4 *)(*(int *)(in_ECX + 0x18) + param_2 * 4);
      *puVar1 = puVar1[-1];
    }
  }
  *(undefined4 *)(*(int *)(in_ECX + 0x18) + param_1 * 4) = uVar2;
  return 0;
}


// ==== FUN_00945ce1 @ 0x00945ce1 ====

int FUN_00945ce1(int param_1,undefined4 *param_2,undefined4 param_3,uint param_4,uint param_5,
                int param_6)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_EDX;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint local_18;
  int local_14;
  int local_c;
  uint local_8;
  
  iVar3 = 1;
  local_14 = 1;
  if (param_4 != 0) {
    puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + -4 + param_4 * 4);
    iVar3 = FUN_009147e7();
    if (((iVar3 == 0) && (uVar5 = *puVar1, (uVar5 & 0xf0000000) != 0x60000000)) &&
       (iVar3 = local_14, uVar2 = param_4, (uVar5 & 0xfff00000) != 0x11000000)) {
      while (uVar2 = uVar2 - 1, -1 < (int)uVar2) {
        puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar2 * 4);
        if (puVar1[9] != param_4) {
          uVar5 = *puVar1 & 0xfff00000;
          if (uVar5 != 0) {
            if ((*puVar1 & 0xf0000000) == 0x60000000) {
              return iVar3;
            }
            if (uVar5 == 0x11000000) {
              return iVar3;
            }
            FUN_0093dacd(param_3,puVar1,param_4);
            local_c = 0;
            local_8 = (uint)((*puVar1 & extraout_EDX) == 0x50000000);
            local_18 = puVar1[3];
            if (local_18 != 0) {
              piVar6 = (int *)puVar1[4];
              do {
                iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar6 * 4);
                if (*(int *)(in_ECX + 0x6c) << 3 < 0) {
                  iVar4 = *(int *)(iVar4 + 0x10);
                }
                else {
                  iVar4 = *(int *)(*(int *)(param_1 + 0x14) +
                                  (*(int *)(iVar4 + 0x10) + *(int *)(iVar4 + 0xc) * 4) * 4);
                }
                if (iVar4 == 3) {
                  local_c = 1;
                }
                else {
                  local_8 = 1;
                }
                piVar6 = piVar6 + 1;
                local_18 = local_18 - 1;
              } while (local_18 != 0);
            }
            if ((local_8 != param_5) && (local_c != param_6)) {
              iVar3 = FUN_00945c94(param_4 - 1,uVar2);
              if (iVar3 < 0) {
                return iVar3;
              }
              if ((*(byte *)(in_ECX + 0x6f) & 0x10) != 0) {
                return 0;
              }
              iVar4 = FUN_00922003(param_1,0);
              if (-1 < iVar4) {
                local_18 = puVar1[3];
                if (local_18 != 0) {
                  piVar6 = (int *)puVar1[4];
                  do {
                    iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar6 * 4);
                    if (*(int *)(*(int *)(param_1 + 0x14) +
                                (*(int *)(iVar4 + 0x10) + *(int *)(iVar4 + 0xc) * 4) * 4) == 3) {
                      local_c = 1;
                    }
                    else {
                      local_8 = 1;
                    }
                    piVar6 = piVar6 + 1;
                    local_18 = local_18 - 1;
                  } while (local_18 != 0);
                }
                if ((local_8 != param_5) && (local_c != param_6)) {
                  return 0;
                }
              }
              puVar7 = param_2;
              puVar8 = *(undefined4 **)(in_ECX + 0x18);
              for (uVar5 = *(uint *)(in_ECX + 0xc) & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
                *puVar8 = *puVar7;
                puVar7 = puVar7 + 1;
                puVar8 = puVar8 + 1;
              }
              for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
                puVar7 = (undefined4 *)((int)puVar7 + 1);
                puVar8 = (undefined4 *)((int)puVar8 + 1);
              }
            }
          }
        }
      }
    }
    else {
      iVar3 = 1;
    }
  }
  return iVar3;
}


// ==== FUN_00945edd @ 0x00945edd ====

undefined4
FUN_00945edd(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            uint param_5,int param_6)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  
  if (param_5 != 0) {
    puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + -4 + param_5 * 4);
    iVar4 = FUN_009147e7();
    if ((iVar4 == 0) && (uVar1 = param_5, (*puVar2 & 0xf0000000) != 0x60000000)) {
      while (uVar1 != 0) {
        uVar1 = uVar1 - 1;
        puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar1 * 4);
        if ((puVar2[9] != param_5) && ((*puVar2 & 0xfff00000) != 0)) {
          if ((*puVar2 & 0xf0000000) == 0x60000000) {
            return 1;
          }
          iVar4 = FUN_009147e7();
          if (iVar4 != 0) {
            return 1;
          }
          FUN_0093dacd(param_4,puVar2,param_5);
          iVar4 = *(int *)(*(int *)(in_ECX + 0x18) + -4 + param_5 * 4);
          iVar3 = *(int *)(*(int *)(in_ECX + 0x18) + uVar1 * 4);
          if ((*(int *)(iVar4 + 0xc) != 0) && (*(int *)(iVar3 + 0xc) != 0)) {
            iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + **(int **)(iVar4 + 0x10) * 4);
            iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + **(int **)(iVar3 + 0x10) * 4);
            if (*(int *)(iVar4 + 0x14) != *(int *)(iVar3 + 0x14)) {
              return 1;
            }
            if (*(int *)(iVar4 + 0x18) != *(int *)(iVar3 + 0x18)) {
              return 1;
            }
            FUN_00945c94(param_5 - 1,uVar1);
            if ((((*(byte *)(in_ECX + 0x6f) & 0x10) != 0) ||
                (iVar4 = FUN_00922003(param_1,0), -1 < iVar4)) &&
               ((param_6 == 0 || (iVar4 = FUN_00922003(param_2,0), -1 < iVar4)))) {
              return 0;
            }
            FUN_00945c94(uVar1,param_5 - 1);
            FUN_0093dacd(param_4,puVar2,param_5);
          }
        }
      }
    }
  }
  return 1;
}


// ==== FUN_0094601a @ 0x0094601a ====

int FUN_0094601a(void)

{
  byte bVar1;
  uint *puVar2;
  int iVar3;
  int *piVar4;
  int extraout_EAX;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 local_ec [25];
  int local_88 [5];
  int local_74;
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  uint local_8;
  
  if ((*(byte *)(in_ECX + 0xcc) & 4) != 0) {
    return 1;
  }
  iVar3 = FUN_00915e19();
  if (iVar3 < 0) {
    return iVar3;
  }
  iVar3 = FUN_00919c3e();
  if (iVar3 < 0) {
    return iVar3;
  }
  uVar5 = *(uint *)(in_ECX + 0xc);
  local_c = (undefined4 *)0x0;
  local_10 = (undefined4 *)0x0;
  local_20 = 0;
  bVar1 = *(byte *)(in_ECX + 0x6f);
  piVar4 = local_88;
  for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  puVar7 = local_ec;
  local_18 = uVar5;
  for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  if ((bVar1 & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x30) != 0) {
      iVar3 = FUN_00921938(local_ec,*(undefined4 *)(in_ECX + 0x8c),*(int *)(in_ECX + 0x30));
      if (iVar3 < 0) goto LAB_0094633e;
      iVar3 = FUN_00922003(local_ec,0);
      local_20 = (uint)(-1 < iVar3);
    }
    iVar3 = FUN_00921938(local_88,*(undefined4 *)(in_ECX + 0x88),*(int *)(in_ECX + 0x2c) + -1);
    if ((iVar3 < 0) || (iVar3 = FUN_00922003(local_88,0), iVar3 < 0)) {
      FUN_009195d7(local_88);
      iVar3 = FUN_00921938(local_88,*(undefined4 *)(in_ECX + 0x88),*(undefined4 *)(in_ECX + 0x2c));
      if ((iVar3 < 0) || (iVar3 = FUN_00922003(local_88,0), iVar3 < 0)) goto LAB_0094633e;
    }
  }
  uVar6 = uVar5 << 2;
  local_14 = uVar6;
  local_c = operator_new(uVar6);
  if ((local_c != (undefined4 *)0x0) &&
     (local_10 = operator_new(uVar6), local_10 != (undefined4 *)0x0)) {
    puVar7 = *(undefined4 **)(in_ECX + 0x18);
    puVar8 = local_10;
    for (uVar5 = uVar5 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    puVar7 = *(undefined4 **)(in_ECX + 0x18);
    puVar8 = local_c;
    for (uVar5 = local_14 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    for (uVar5 = local_14 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    uVar5 = 0;
    local_8 = local_18;
    if (local_18 != 0) {
      do {
        iVar3 = *(int *)(*(int *)(in_ECX + 0x18) + uVar5 * 4);
        *(int *)(in_ECX + 0x100) = iVar3;
        *(undefined4 *)(iVar3 + 0x24) = 0xffffffff;
        uVar5 = uVar5 + 1;
      } while (uVar5 < local_18);
    }
joined_r0x009461d0:
    uVar5 = local_8 - 1;
    local_8 = uVar5;
    if (-1 < (int)uVar5) {
      puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar5 * 4);
      *(uint **)(in_ECX + 0x100) = puVar2;
      uVar6 = *puVar2;
      if (((uVar6 & 0xfff00000) != 0) && ((uVar6 & 0xf0000000) != 0x60000000)) {
        iVar3 = FUN_009147e7();
        if (iVar3 == 0) {
          if ((**(uint **)(in_ECX + 0x100) & 0xfff00000) != 0x11000000) {
            FUN_0093dacd(local_10,*(uint **)(in_ECX + 0x100),uVar5);
            if ((*(byte *)(in_ECX + 0x70) & 8) == 0) {
              iVar3 = FUN_00945edd(local_88,local_ec,local_c,local_10,uVar5,local_20);
            }
            else {
              puVar2 = *(uint **)(in_ECX + 0x100);
              local_18 = 0;
              local_1c = (uint)((*puVar2 & 0xfff00000) == 0x50000000);
              if (puVar2[3] != 0) {
                local_24 = *(int *)(*(int *)(in_ECX + 0x100) + 0xc);
                piVar4 = (int *)puVar2[4];
                do {
                  iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar4 * 4);
                  if ((*(int *)(in_ECX + 0x6c) << 3 < 0) || (local_88[0] != *(int *)(iVar3 + 4))) {
                    iVar3 = *(int *)(iVar3 + 0x10);
                  }
                  else {
                    iVar3 = *(int *)(local_74 +
                                    (*(int *)(iVar3 + 0x10) + *(int *)(iVar3 + 0xc) * 4) * 4);
                  }
                  if (iVar3 == 3) {
                    local_18 = 1;
                  }
                  else {
                    local_1c = 1;
                  }
                  piVar4 = piVar4 + 1;
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
              }
              if (local_1c == 0) {
                uVar10 = 1;
                uVar9 = 0;
              }
              else {
                if (local_18 != 0) goto joined_r0x009461d0;
                uVar10 = 0;
                uVar9 = 1;
              }
              iVar3 = FUN_00945ce1(local_88,local_c,local_10,local_8,uVar9,uVar10);
            }
            if (iVar3 < 0) goto LAB_0094633e;
            if (iVar3 == 0) {
              local_8 = local_8 - 1;
              puVar7 = *(undefined4 **)(in_ECX + 0x18);
              puVar8 = local_c;
              for (uVar5 = local_14 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                *puVar8 = *puVar7;
                puVar7 = puVar7 + 1;
                puVar8 = puVar8 + 1;
              }
              for (uVar5 = local_14 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
                puVar7 = (undefined4 *)((int)puVar7 + 1);
                puVar8 = (undefined4 *)((int)puVar8 + 1);
              }
            }
          }
        }
      }
      goto joined_r0x009461d0;
    }
  }
LAB_0094633e:
  if (((*(byte *)(in_ECX + 0x6f) & 0x10) == 0) &&
     (FUN_009195d7(local_88), *(int *)(in_ECX + 0x30) != 0)) {
    FUN_009195d7(local_ec);
  }
  _free(local_10);
  return extraout_EAX;
}


// ==== FUN_0094637f @ 0x0094637f ====

undefined4 FUN_0094637f(int param_1)

{
  undefined4 uVar1;
  
  if ((((param_1 == 0x73500000) || (param_1 == 0x73600000)) || (param_1 == 0x73700000)) ||
     ((param_1 == 0x73800000 || (param_1 == 0x10f00000)))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_009463b5 @ 0x009463b5 ====

undefined4 FUN_009463b5(int param_1)

{
  undefined4 uVar1;
  
  if ((((param_1 == 0x74700000) || (param_1 == 0x74600000)) || (param_1 == 0x74400000)) ||
     ((param_1 == 0x74500000 || (param_1 == 0x74300000)))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_009463eb @ 0x009463eb ====

int FUN_009463eb(uint *param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int local_8;
  
  bVar2 = false;
  uVar6 = *param_1 & 0xfffff;
  uVar8 = *param_1 & 0xfff00000;
  if (param_2 == 0) {
    if (uVar8 != 0x10f00000) {
      if (uVar8 == 0x73500000) {
        uVar9 = uVar6 | 0x73d00000;
      }
      else if (uVar8 == 0x73600000) {
        uVar9 = uVar6 | 0x73e00000;
      }
      else if (uVar8 == 0x73700000) {
        uVar9 = uVar6 | 0x73f00000;
      }
      else {
        if (uVar8 != 0x73800000) {
          return 0;
        }
        uVar9 = uVar6 | 0x74000000;
      }
      goto LAB_0094661c;
    }
    puVar10 = *(undefined4 **)
               (*(int *)(in_ECX + 0x10) +
               *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)param_1[2] * 4) + 4) * 4);
    uVar9 = uVar6 | 0x73100000;
    if ((((*(ushort *)(puVar10 + 1) & 0x208) != 0) &&
        ((((((char *)*puVar10 == (char *)0x0 ||
            (pcVar3 = _strchr((char *)*puVar10,0x69), pcVar3 != (char *)0x0)) ||
           (pcVar3 = _strchr((char *)*puVar10,0x49), pcVar3 != (char *)0x0)) ||
          ((pcVar3 = _strchr((char *)*puVar10,0x62), pcVar3 != (char *)0x0 ||
           (pcVar3 = _strchr((char *)*puVar10,0x42), pcVar3 != (char *)0x0)))) ||
         ((*(byte *)((int)puVar10 + 5) & 8) == 0)))) &&
       (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)param_1[2] * 4) + 8) == -1))
    goto LAB_0094661c;
    uVar9 = uVar6 | 0x73f00000;
  }
  else {
    if (uVar8 != 0x10f00000) {
      if (uVar8 == 0x73500000) {
        uVar9 = uVar6 | 0x73900000;
      }
      else if (uVar8 == 0x73600000) {
        uVar9 = uVar6 | 0x73a00000;
      }
      else if (uVar8 == 0x73700000) {
        uVar9 = uVar6 | 0x73b00000;
      }
      else {
        if (uVar8 != 0x73800000) {
          return 0;
        }
        uVar9 = uVar6 | 0x73c00000;
      }
      goto LAB_0094661c;
    }
    puVar10 = *(undefined4 **)
               (*(int *)(in_ECX + 0x10) +
               *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)param_1[2] * 4) + 4) * 4);
    uVar9 = uVar6 | 0x73000000;
    if ((((*(ushort *)(puVar10 + 1) & 0x208) != 0) &&
        ((((char *)*puVar10 == (char *)0x0 ||
          (pcVar3 = _strchr((char *)*puVar10,0x69), pcVar3 != (char *)0x0)) ||
         ((pcVar3 = _strchr((char *)*puVar10,0x49), pcVar3 != (char *)0x0 ||
          (((pcVar3 = _strchr((char *)*puVar10,0x62), pcVar3 != (char *)0x0 ||
            (pcVar3 = _strchr((char *)*puVar10,0x42), pcVar3 != (char *)0x0)) ||
           ((*(byte *)((int)puVar10 + 5) & 8) == 0)))))))) &&
       (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)param_1[2] * 4) + 8) == -1))
    goto LAB_0094661c;
    uVar9 = uVar6 | 0x73b00000;
  }
  bVar2 = true;
LAB_0094661c:
  iVar4 = FUN_009149f7();
  if (iVar4 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_0091455d();
  }
  if (local_8 != 0) {
    if ((uVar8 != 0x10f00000) || (bVar2)) {
      uVar8 = uVar6 * 2;
    }
    else {
      uVar8 = uVar6;
    }
    iVar4 = FUN_00914a42(uVar9,uVar8,uVar6);
    if ((-1 < iVar4) && (iVar4 = FUN_00914593(), -1 < iVar4)) {
      if (param_2 == 0) {
        uVar5 = FUN_00915318(*(undefined4 *)(in_ECX + 0xa8),0,0,0);
        **(undefined4 **)(local_8 + 0x10) = uVar5;
        if (**(int **)(local_8 + 0x10) == -1) {
          return 0;
        }
        iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + **(int **)(local_8 + 0x10) * 4);
        iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)param_1[4] * 4);
        *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(iVar1 + 0x18);
        *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
      }
      else {
        puVar10 = (undefined4 *)param_1[4];
        puVar11 = *(undefined4 **)(local_8 + 0x10);
        for (uVar6 = param_1[3] & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar11 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar11 = puVar11 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
          puVar10 = (undefined4 *)((int)puVar10 + 1);
          puVar11 = (undefined4 *)((int)puVar11 + 1);
        }
      }
      puVar10 = (undefined4 *)param_1[2];
      puVar11 = *(undefined4 **)(local_8 + 8);
      for (uVar6 = param_1[1] & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar11 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar11 = puVar11 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      if (!bVar2) {
        return local_8;
      }
      param_1 = (uint *)0x0;
      if (*(int *)(in_ECX + 8) != 0) {
        piVar7 = *(int **)(in_ECX + 0x14);
        iVar4 = *(int *)(in_ECX + 8);
        do {
          if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(*piVar7 + 4) * 4) + 5) & 1) !=
               0) && (uVar6 = *(uint *)(*piVar7 + 0xc), param_1 <= uVar6)) {
            param_1 = (uint *)(uVar6 + 1);
          }
          piVar7 = piVar7 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      if (*(int *)(in_ECX + 0x188) == -1) {
        uVar5 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),param_1,0,0);
        *(undefined4 *)(in_ECX + 0x188) = uVar5;
      }
      if (*(int *)(in_ECX + 0x188) != -1) {
        *(int *)(*(int *)(local_8 + 8) + 4) = *(int *)(in_ECX + 0x188);
        return local_8;
      }
    }
    FUN_008f4adb();
  }
  return 0;
}


// ==== FUN_0094679d @ 0x0094679d ====

undefined4 FUN_0094679d(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  uint local_18;
  uint local_14;
  uint local_10;
  int *local_8;
  
  do {
    bVar5 = false;
    local_10 = 0;
    if (*(int *)(in_ECX + 0xc) == 0) {
      return 0;
    }
    do {
      iVar6 = FUN_00914793();
      if (iVar6 != 0) {
        local_18 = local_10 + 1;
        bVar4 = true;
        if (local_18 < *(uint *)(in_ECX + 0xc)) {
          do {
            puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_18 * 4);
            iVar6 = FUN_009147cb();
            if (iVar6 != 0) break;
            if ((*puVar1 & 0xfff00000) != 0x10000000) {
              bVar4 = false;
              break;
            }
            local_14 = puVar1[3];
            if (local_14 != 0) {
              local_8 = (int *)puVar1[2];
              iVar6 = puVar1[4] - (int)local_8;
              do {
                iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar6 + (int)local_8) * 4);
                iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + *local_8 * 4);
                if ((((*(int *)(iVar2 + 0x38) != *(int *)(iVar3 + 0x38)) ||
                     (*(int *)(iVar2 + 0x3c) != *(int *)(iVar3 + 0x3c))) ||
                    (*(int *)(iVar2 + 4) != *(int *)(iVar3 + 4))) ||
                   (((*(int *)(iVar2 + 0xc) != *(int *)(iVar3 + 0xc) ||
                     (*(int *)(iVar2 + 8) != *(int *)(iVar3 + 8))) ||
                    (*(int *)(iVar2 + 0x10) != *(int *)(iVar3 + 0x10))))) {
                  bVar4 = false;
                }
                local_8 = local_8 + 1;
                local_14 = local_14 - 1;
              } while (local_14 != 0);
            }
            local_18 = local_18 + 1;
          } while (local_18 < *(uint *)(in_ECX + 0xc));
          if (!bVar4) goto LAB_009468b5;
        }
        bVar5 = true;
        uVar7 = local_10;
        if (local_10 < *(uint *)(in_ECX + 0xc)) {
          do {
            iVar6 = FUN_009147cb();
            if (iVar6 != 0) break;
            **(undefined4 **)(*(int *)(in_ECX + 0x18) + uVar7 * 4) = 0;
            uVar7 = uVar7 + 1;
          } while (uVar7 < *(uint *)(in_ECX + 0xc));
        }
      }
LAB_009468b5:
      local_10 = local_10 + 1;
    } while (local_10 < *(uint *)(in_ECX + 0xc));
    if (!bVar5) {
      return 0;
    }
  } while( true );
}


// ==== FUN_009468d3 @ 0x009468d3 ====

int * FUN_009468d3(int param_1,int param_2,uint *param_3,int param_4,int param_5,int *param_6,
                  uint param_7,int *param_8,int param_9,undefined4 param_10,undefined4 param_11)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  int extraout_ECX;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  char *pcVar12;
  undefined4 local_83c [128];
  int local_63c [128];
  undefined4 local_43c [128];
  int local_23c [128];
  uint local_3c;
  uint local_38;
  int *local_34;
  uint local_30;
  uint local_2c;
  int local_28;
  int *local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  int *local_14;
  int *local_10;
  uint local_c;
  int *local_8;
  
  uVar4 = *param_3;
  local_28 = in_ECX;
joined_r0x009468f1:
  local_c = uVar4;
  if (param_7 <= local_c) {
    return (int *)0x0;
  }
  piVar3 = (int *)0x0;
  puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_c * 4);
  local_18 = *puVar1 & 0xfff00000;
  local_14 = (int *)(*puVar1 & 0xfffff);
  if (puVar1[3] == 0) {
    uVar10 = 0xa2dc78000012df;
    goto LAB_00947105;
  }
  local_10 = *(int **)(*(int *)(in_ECX + 0x14) + *(int *)puVar1[4] * 4);
  if (local_10[5] != param_1) {
    if (local_18 != 0x20700000) {
LAB_00947147:
      *param_3 = local_c;
      return (int *)0x0;
    }
    if (param_9 == 0) {
      piVar8 = (int *)puVar1[2];
      local_18 = *(uint *)(*(int *)(in_ECX + 0x14) + *piVar8 * 4);
      if (*(int *)(local_18 + 0x14) !=
          *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + piVar8[(int)local_14] * 4) + 0x14)) {
        pcVar12 = s_internal_error__if_block_with_no_00a2dbe8;
        goto LAB_009470f4;
      }
      if (((param_4 == 0) || (param_5 == 0)) || (param_6 == (int *)0x0)) {
        pcVar12 = s_internal_error__unexpected_endif_00a2dba0;
LAB_009470ca:
        uVar10 = CONCAT44(pcVar12,0x12e1);
LAB_00947105:
        FUN_0091a001(in_ECX,puVar1[0xf],uVar10);
        return (int *)0x80004005;
      }
      if (*(int *)(local_18 + 0x14) != param_1) goto LAB_00947147;
      if (param_8 == (int *)0x0) goto LAB_00946c0a;
      local_20 = 1;
      local_24 = (int *)0x0;
      if (*(int *)(local_18 + 0x18) != param_2) {
        local_24 = local_14;
      }
      if (local_14 != (int *)0x0) {
        local_10 = (int *)puVar1[4];
        local_8 = piVar8 + (int)local_24;
        local_34 = local_14;
        do {
          iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *local_10 * 4);
          iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + *local_8 * 4);
          if (((*(int *)(iVar2 + 0xc) != *(int *)(iVar6 + 0xc)) ||
              (*(int *)(iVar2 + 0x10) != *(int *)(iVar6 + 0x10))) ||
             ((*(int *)(iVar2 + 8) != *(int *)(iVar6 + 8) ||
              ((*(int *)(iVar2 + 4) != *(int *)(iVar6 + 4) ||
               (*(int *)(iVar2 + 0x3c) != *(int *)(iVar6 + 0x3c))))))) {
            local_20 = 0;
          }
          local_10 = local_10 + 1;
          local_8 = local_8 + 1;
          local_34 = (int *)((int)local_34 + -1);
        } while (local_34 != (int *)0x0);
      }
      if (0x7f < (uint)(*param_6 + (int)local_14)) {
        uVar10 = 0xa2dbc800001194;
        goto LAB_00947105;
      }
      if (local_20 == 0) {
        iVar2 = FUN_009149f7();
        if (iVar2 == 0) {
          local_8 = (int *)0x0;
        }
        else {
          local_8 = (int *)FUN_0091455d();
        }
        if (local_8 == (int *)0x0) {
          return (int *)0x8007000e;
        }
        piVar3 = (int *)FUN_00914a42((uint)local_14 & 0xfffff | 0x10000000,local_14,local_14,0);
        if ((((int)piVar3 < 0) || (piVar3 = (int *)FUN_00914593(), (int)piVar3 < 0)) ||
           (piVar3 = (int *)FUN_00915205(), (int)piVar3 < 0)) {
LAB_00947121:
          FUN_008f4adb();
          return piVar3;
        }
        if (*(int *)(local_18 + 0x18) == param_2) {
          puVar7 = (undefined4 *)puVar1[2];
          puVar9 = (undefined4 *)local_8[2];
          for (uVar4 = (uint)local_14 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar9 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar9 = puVar9 + 1;
          }
        }
        else {
          puVar7 = (undefined4 *)puVar1[2] + (int)local_14;
          puVar9 = (undefined4 *)local_8[2];
          for (uVar4 = (uint)local_14 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar9 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar9 = puVar9 + 1;
          }
        }
        local_10 = (int *)0x0;
        for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
          *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
        if (local_14 != (int *)0x0) {
          local_18 = (int)local_14 << 2;
          do {
            uVar11 = FUN_00915318(*(undefined4 *)(local_28 + 0x88),0,0,0);
            *(undefined4 *)(param_4 + (*param_6 + (int)local_10) * 4) = uVar11;
            iVar2 = *(int *)(param_4 + (*param_6 + (int)local_10) * 4);
            if (iVar2 == -1) {
              piVar3 = (int *)0x8007000e;
              goto LAB_00947121;
            }
            local_34 = *(int **)(*(int *)(local_28 + 0x14) + iVar2 * 4);
            iVar6 = (int)local_10 * 4;
            local_20 = *(uint *)(*(int *)(local_28 + 0x14) + *(int *)(iVar6 + puVar1[4]) * 4);
            iVar2 = FUN_00914e44();
            if ((iVar2 < 0) || (iVar2 = FUN_00914f00(), iVar2 < 0)) {
              FUN_008f4adb();
              return (int *)0x8007000e;
            }
            *(undefined4 *)(iVar6 + local_8[4]) =
                 *(undefined4 *)(param_4 + (*param_6 + (int)local_10) * 4);
            *(undefined4 *)(param_5 + (*param_6 + (int)local_10) * 4) =
                 *(undefined4 *)(iVar6 + puVar1[4]);
            iVar2 = *(int *)(puVar1[2] + iVar6);
            if (*(int *)(*(int *)(*(int *)(local_28 + 0x14) + iVar2 * 4) + 0x18) == param_2) {
              *(int *)(iVar6 + local_8[2]) = iVar2;
            }
            else {
              *(undefined4 *)(iVar6 + local_8[2]) = *(undefined4 *)(puVar1[2] + local_18);
            }
            local_10 = (int *)((int)local_10 + 1);
            local_18 = local_18 + 4;
          } while (local_10 < local_14);
        }
      }
      else if (local_14 != (int *)0x0) {
        local_24 = (int *)((int)local_24 << 2);
        do {
          puVar7 = (undefined4 *)((int)local_24 + puVar1[2]);
          local_24 = local_24 + 1;
          *(undefined4 *)(param_4 + (*param_6 + (int)piVar3) * 4) = *puVar7;
          iVar2 = (int)piVar3 * 4;
          iVar6 = *param_6 + (int)piVar3;
          piVar3 = (int *)((int)piVar3 + 1);
          *(undefined4 *)(param_5 + iVar6 * 4) = *(undefined4 *)(puVar1[4] + iVar2);
        } while (piVar3 < local_14);
      }
      *param_6 = *param_6 + (int)local_14;
      uVar4 = local_c + 1;
      in_ECX = local_28;
      goto joined_r0x009468f1;
    }
LAB_00946c0a:
    uVar4 = local_c + 1;
    goto joined_r0x009468f1;
  }
  if ((param_9 != 0) && (local_18 != 0x11200000)) goto LAB_00946c0a;
  local_8 = param_8;
  if ((param_8 != (int *)0x0) && (local_10[6] != param_2)) {
    local_8 = (int *)0x0;
  }
  iVar2 = FUN_0094637f();
  if (iVar2 != 0) {
    if (local_14 != (int *)0x1) {
      pcVar12 = s_internal_error__IF_with_size_gre_00a2dc44;
LAB_009470f4:
      uVar10 = CONCAT44(pcVar12,0x12e0);
      goto LAB_00947105;
    }
    if (local_8 != (int *)0x0) {
      iVar2 = FUN_009463eb(puVar1,1);
      if (iVar2 == 0) {
        return (int *)0x8007000e;
      }
      piVar3 = (int *)FUN_00915205();
      if ((int)piVar3 < 0) {
        return piVar3;
      }
    }
    local_30 = local_c + 1;
    local_38 = 0;
    local_1c = 0;
    local_c = local_30;
    piVar3 = (int *)FUN_009468d3(*(undefined4 *)puVar1[4],1,&local_30,local_43c,local_23c,&local_1c,
                                 param_7,local_8,0,0,0);
    if ((int)piVar3 < 0) {
      return piVar3;
    }
    if (local_8 != (int *)0x0) {
      iVar2 = FUN_009463eb(puVar1,0);
      if (iVar2 == 0) {
        return (int *)0x8007000e;
      }
      piVar3 = (int *)FUN_00915205();
      if ((int)piVar3 < 0) {
        return piVar3;
      }
    }
    local_30 = local_c;
    piVar3 = (int *)FUN_009468d3(*(undefined4 *)puVar1[4],0,&local_30,local_83c,local_63c,&local_38,
                                 param_7,local_8,0,0,0);
    if ((int)piVar3 < 0) {
      return piVar3;
    }
    if (local_8 != (int *)0x0) {
      local_18 = 1;
      if (local_1c != local_38) {
LAB_009470c5:
        pcVar12 = s_internal_error__endif_mismatch_00a2dc24;
        goto LAB_009470ca;
      }
      uVar4 = 0;
      if (local_38 != 0) {
        do {
          if (local_63c[uVar4] != local_23c[uVar4]) {
            local_18 = 0;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < local_38);
        if (local_18 == 0) goto LAB_009470c5;
      }
      iVar2 = FUN_009149f7();
      if (iVar2 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = FUN_0091455d();
      }
      if (uVar4 == 0) {
        return (int *)0x8007000e;
      }
      local_18 = uVar4;
      local_8 = (int *)FUN_00914a42(local_38 & 0xfffff | 0x73400000,local_38 * 2,local_38,0);
      if ((int)local_8 < 0) {
LAB_009470d5:
        FUN_008f4adb();
        return local_8;
      }
      piVar3 = (int *)FUN_00914593();
      if ((int)piVar3 < 0) {
LAB_009470e4:
        FUN_008f4adb();
        return piVar3;
      }
      piVar3 = local_63c;
      piVar8 = *(int **)(uVar4 + 0x10);
      for (uVar5 = local_1c; uVar5 != 0; uVar5 = uVar5 - 1) {
        *piVar8 = *piVar3;
        piVar3 = piVar3 + 1;
        piVar8 = piVar8 + 1;
      }
      puVar7 = local_43c;
      puVar9 = *(undefined4 **)(uVar4 + 8);
      for (uVar5 = local_1c; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
      puVar7 = local_83c;
      puVar9 = (undefined4 *)(*(int *)(uVar4 + 8) + local_1c * 4);
      for (uVar5 = local_1c & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      piVar3 = (int *)FUN_00915205();
      if ((int)piVar3 < 0) {
        return piVar3;
      }
      in_ECX = local_28;
    }
    local_10[1] = *(int *)(in_ECX + 0x74);
    uVar4 = local_30;
    goto joined_r0x009468f1;
  }
  uVar10 = FUN_009463b5();
  if ((int)uVar10 == 0) {
    if ((extraout_ECX != 0x11100000) && (extraout_ECX != 0x74100000)) {
      if (extraout_ECX == 0x11200000) {
        if ((local_8 != (int *)0x0) && (param_9 != 0)) {
          piVar3 = (int *)0x0;
          if (local_14 != (int *)0x0) {
            do {
              iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar1[4] + (int)piVar3 * 4) * 4);
              *(undefined4 *)(iVar2 + 0x34) = param_11;
              piVar3 = (int *)((int)piVar3 + 1);
              *(undefined4 *)(iVar2 + 0x30) = param_10;
            } while (piVar3 < local_14);
          }
          goto LAB_00946bfa;
        }
      }
      else if ((param_8 != (int *)0x0) &&
              (*(int *)((int)((ulonglong)uVar10 >> 0x20) + 0x18) == param_2)) {
LAB_00946bfa:
        piVar3 = (int *)FUN_00915471();
        if ((int)piVar3 < 0) {
          return piVar3;
        }
      }
      goto LAB_00946c0a;
    }
    local_2c = local_c + 1;
    local_1c = 0;
    local_c = local_2c;
    piVar3 = (int *)FUN_009468d3(*(undefined4 *)puVar1[4],1,&local_2c,local_43c,local_23c,&local_1c,
                                 param_7,local_8,1,param_1,param_2);
    if ((int)piVar3 < 0) {
      return piVar3;
    }
    if (local_8 != (int *)0x0) {
      if (local_18 == 0x11100000) {
        local_20 = (uint)local_14 & 0xfffff;
        *puVar1 = local_20 | 0x74200000;
        piVar3 = (int *)FUN_00915471();
        if ((int)piVar3 < 0) {
          return piVar3;
        }
        *puVar1 = local_20 | 0x11100000;
      }
      else {
        piVar3 = (int *)FUN_00915471();
        if ((int)piVar3 < 0) {
          return piVar3;
        }
      }
      local_10[1] = *(int *)(in_ECX + 0x74);
    }
    local_2c = local_c;
    piVar3 = (int *)FUN_009468d3(*(undefined4 *)puVar1[4],1,&local_2c,local_43c,local_23c,&local_1c,
                                 param_7,local_8,0,0,0);
    if ((int)piVar3 < 0) {
      return piVar3;
    }
    uVar4 = local_2c;
    if (local_8 == (int *)0x0) goto joined_r0x009468f1;
    local_20 = FUN_00915318(*(undefined4 *)(in_ECX + 0xa8),0,0,0);
    if (local_20 == 0xffffffff) {
      return (int *)0x8007000e;
    }
    iVar2 = FUN_009149f7();
    if (iVar2 == 0) {
      local_10 = (int *)0x0;
    }
    else {
      local_10 = (int *)FUN_0091455d();
    }
    if (local_10 == (int *)0x0) {
      return (int *)0x8007000e;
    }
    if (local_18 == 0x11100000) {
      uVar11 = 0x74b00001;
    }
    else {
      uVar11 = 0x74a00001;
    }
    local_8 = (int *)FUN_00914a42(uVar11,0,1,0);
    if ((int)local_8 < 0) goto LAB_009470d5;
    piVar3 = (int *)FUN_00914593();
    if ((int)piVar3 < 0) goto LAB_009470e4;
    *(uint *)local_10[4] = local_20;
    piVar3 = (int *)FUN_00915205();
    uVar4 = local_2c;
  }
  else {
    local_3c = local_c + 1;
    local_1c = 0;
    if (local_8 != (int *)0x0) {
      piVar3 = (int *)FUN_00915471();
      if ((int)piVar3 < 0) {
        return piVar3;
      }
      local_10[1] = *(int *)(in_ECX + 0x74);
    }
    piVar3 = (int *)FUN_009468d3(*(undefined4 *)puVar1[4],1,&local_3c,local_43c,local_23c,&local_1c,
                                 param_7,local_8,0,0,0);
    uVar4 = local_3c;
  }
  if ((int)piVar3 < 0) {
    return piVar3;
  }
  goto joined_r0x009468f1;
}


// ==== FUN_00947158 @ 0x00947158 ====

uint * FUN_00947158(uint param_1,int param_2,uint *param_3,int *param_4,uint param_5)

{
  uint *puVar1;
  undefined4 uVar2;
  int in_ECX;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  bool bVar10;
  undefined4 local_24 [4];
  uint local_14;
  int *local_10;
  uint local_c;
  undefined4 *local_8;
  
  iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + **(int **)(param_2 + 0x10) * 4);
  local_14 = *(uint *)(iVar6 + 0x48);
  local_c = *(uint *)(iVar6 + 0x54);
  if (local_c != 0xffffffff) {
    local_8 = (undefined4 *)0x0;
    if (*(int *)(param_2 + 4) != 0) {
      piVar3 = *(int **)(param_2 + 8);
      do {
        iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar3 * 4);
        if (((*(int *)(in_ECX + 0x88) == *(int *)(iVar6 + 4)) &&
            (uVar8 = *(uint *)(iVar6 + 0x50), local_14 < uVar8)) && (uVar8 < local_c)) {
          return (uint *)0x0;
        }
        local_8 = (undefined4 *)((int)local_8 + 1);
        piVar3 = piVar3 + 1;
      } while (local_8 < *(uint *)(param_2 + 4));
    }
    puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_c * 4);
    if (param_1 == *puVar1) {
      local_8 = (undefined4 *)0x0;
      if (*(int *)(param_2 + 0xc) != 0) {
        local_10 = *(int **)(param_2 + 0x10);
        do {
          iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + *local_10 * 4);
          if (*(uint *)(iVar6 + 0x54) != local_c) {
            return (uint *)0x0;
          }
          if (*(uint *)(iVar6 + 0x58) != local_c) {
            return (uint *)0x0;
          }
          if (*(int *)(param_2 + 0xc) == 1) {
            bVar10 = *(int *)(iVar6 + 0x5c) == (param_1 & 0xfffff) * param_5;
          }
          else {
            bVar10 = *(int *)(iVar6 + 0x5c) == param_5;
          }
          if (!bVar10) {
            return (uint *)0x0;
          }
          local_8 = (undefined4 *)((int)local_8 + 1);
          local_10 = local_10 + 1;
        } while (local_8 < *(uint *)(param_2 + 0xc));
      }
      uVar8 = *puVar1 & 0xfffff;
      if ((puVar1[3] == uVar8) && (puVar1[1] <= uVar8 * (int)param_4)) {
        local_8 = (undefined4 *)0x0;
        uVar4 = 0;
        if (puVar1[1] != 0) {
          piVar3 = (int *)puVar1[2];
          do {
            iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar3 * 4);
            if ((*(int *)(in_ECX + 0x88) == *(int *)(iVar6 + 4)) &&
               (local_14 < *(uint *)(iVar6 + 0x48))) {
              return (uint *)0x0;
            }
            local_8 = (undefined4 *)((int)local_8 + 1);
            uVar4 = puVar1[1];
            piVar3 = piVar3 + 1;
          } while (local_8 < uVar4);
        }
        local_8 = (undefined4 *)0x0;
        if (uVar4 != 0) {
          piVar3 = (int *)puVar1[2];
          do {
            if (*piVar3 == **(int **)(param_2 + 0x10)) break;
            local_8 = (undefined4 *)((int)local_8 + 1);
            piVar3 = piVar3 + 1;
          } while (local_8 < uVar4);
        }
        if (local_8 != (undefined4 *)uVar4) {
          if ((uVar8 <= local_8) && (uVar4 = 0, uVar8 != 0)) {
            iVar6 = uVar8 << 2;
            do {
              puVar5 = (undefined4 *)(puVar1[2] + uVar4 * 4);
              uVar2 = *puVar5;
              *puVar5 = *(undefined4 *)(iVar6 + puVar1[2]);
              *(undefined4 *)(iVar6 + puVar1[2]) = uVar2;
              uVar4 = uVar4 + 1;
              iVar6 = iVar6 + 4;
            } while (uVar4 < uVar8);
          }
          if (1 < *(uint *)(param_2 + 0xc)) {
            puVar5 = *(undefined4 **)(param_2 + 8);
            local_8 = puVar5 + *(int *)(param_2 + 4);
            if (puVar5 < puVar5 + *(int *)(param_2 + 4)) {
              do {
                if (uVar8 != 0) {
                  local_10 = *(int **)(param_2 + 0x10);
                  uVar4 = puVar1[2];
                  puVar7 = puVar5;
                  local_14 = uVar8;
                  do {
                    param_5 = 0;
                    param_4 = local_10;
                    do {
                      if (*param_4 == *(int *)((uVar4 - (int)puVar5) + (int)puVar7)) {
                        local_24[param_5] = *puVar7;
                        break;
                      }
                      param_5 = param_5 + 1;
                      param_4 = param_4 + 1;
                    } while (param_5 < uVar8);
                    puVar7 = puVar7 + 1;
                    local_14 = local_14 - 1;
                  } while (local_14 != 0);
                }
                puVar7 = local_24;
                puVar9 = puVar5;
                for (uVar4 = uVar8; uVar4 != 0; uVar4 = uVar4 - 1) {
                  *puVar9 = *puVar7;
                  puVar7 = puVar7 + 1;
                  puVar9 = puVar9 + 1;
                }
                for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
                  *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
                  puVar7 = (undefined4 *)((int)puVar7 + 1);
                  puVar9 = (undefined4 *)((int)puVar9 + 1);
                }
                puVar5 = puVar5 + uVar8;
              } while (puVar5 < local_8);
            }
          }
          if (param_3 == (uint *)0x0) {
            return puVar1;
          }
          *param_3 = local_c;
          return puVar1;
        }
      }
    }
  }
  return (uint *)0x0;
}


// ==== FUN_009473b3 @ 0x009473b3 ====

undefined4 FUN_009473b3(uint param_1,uint *param_2,int *param_3,int param_4)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  int iVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  uint local_18;
  uint local_14;
  int local_10;
  
  uVar7 = *param_2 & 0xfffff;
  if (uVar7 != 0) {
    uVar3 = param_2[1] / uVar7;
    if (uVar3 != 0) {
      local_10 = 0;
      piVar9 = param_3;
      local_18 = uVar3;
      do {
        iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(local_10 + param_2[2]) * 4);
        uVar4 = *(uint *)(iVar5 + 0x54);
        uVar8 = *(uint *)(iVar5 + 0x48);
        if (uVar8 == 0xffffffff) {
LAB_00947547:
          *piVar9 = 0;
        }
        else {
          puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar8 * 4);
          *piVar9 = (int)puVar1;
          if (uVar7 != 0) {
            iVar5 = local_10;
            local_14 = uVar7;
            do {
              iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar5 + param_2[2]) * 4);
              if (*(int *)(in_ECX + 0x88) != *(int *)(iVar2 + 4)) {
                *piVar9 = 0;
              }
              if (*(int *)(iVar2 + 0x3c) != 0) {
                *piVar9 = 0;
              }
              if ((uVar8 < *(uint *)(iVar2 + 0x50)) && (*(uint *)(iVar2 + 0x50) < uVar4)) {
                *piVar9 = 0;
              }
              if (*(int *)(iVar2 + 0x54) != *(int *)(iVar2 + 0x58)) {
                *piVar9 = 0;
              }
              iVar5 = iVar5 + 4;
              local_14 = local_14 - 1;
            } while (local_14 != 0);
          }
          if (*piVar9 != 0) {
            if (param_1 == *puVar1) {
              if (uVar7 != 0) {
                iVar5 = local_10;
                local_14 = uVar7;
                do {
                  if (*(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar5 + param_2[2]) * 4)
                               + 0x48) != uVar8) {
                    *piVar9 = 0;
                  }
                  iVar5 = iVar5 + 4;
                  local_14 = local_14 - 1;
                } while (local_14 != 0);
              }
              if (*piVar9 == 0) goto LAB_0094754a;
              if ((puVar1[3] == (*puVar1 & 0xfffff)) && (puVar1[1] <= (*puVar1 & 0xfffff) * param_4)
                 ) {
                uVar4 = param_2[1];
                uVar8 = 0;
                if (uVar4 != 0) {
                  piVar6 = (int *)param_2[2];
                  do {
                    if (*piVar6 == *(int *)puVar1[4]) break;
                    uVar8 = uVar8 + 1;
                    piVar6 = piVar6 + 1;
                  } while (uVar8 < uVar4);
                }
                if (uVar8 != uVar4) {
                  if (1 < puVar1[3]) {
                    if ((puVar1[3] != uVar7) || (uVar4 < uVar8 + uVar7)) {
                      *piVar9 = 0;
                    }
                    uVar4 = 0;
                    if (uVar7 != 0) {
                      iVar5 = uVar8 << 2;
                      do {
                        if (*(int *)(puVar1[4] + uVar4 * 4) != *(int *)(iVar5 + param_2[2])) {
                          *piVar9 = 0;
                        }
                        uVar4 = uVar4 + 1;
                        iVar5 = iVar5 + 4;
                      } while (uVar4 < uVar7);
                    }
                  }
                  goto LAB_0094754a;
                }
              }
            }
            goto LAB_00947547;
          }
        }
LAB_0094754a:
        local_10 = local_10 + uVar7 * 4;
        piVar9 = piVar9 + 1;
        local_18 = local_18 - 1;
      } while (local_18 != 0);
    }
    uVar7 = 0;
    if (uVar3 != 0) {
      do {
        if (param_3[uVar7] != 0) {
          return 0;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar3);
    }
  }
  return 1;
}


// ==== FUN_00947586 @ 0x00947586 ====

int FUN_00947586(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  uint uVar3;
  int local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  iVar1 = FUN_009149f7(0x74);
  if (iVar1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_0091455d();
  }
  if (local_8 == 0) {
    iVar1 = -0x7ff8fff2;
  }
  else {
    local_c = 0;
    if (param_3 != 0) {
      piVar2 = *(int **)(*(int *)(in_ECX + 0x100) + 0x10);
      uVar3 = param_3;
      do {
        if (*(int *)(param_1 + *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar2 * 4) + 0x10) * 4)
            != -1) {
          local_c = local_c + 1;
        }
        piVar2 = piVar2 + 1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    iVar1 = FUN_00914a42(**(uint **)(in_ECX + 0x100) & 0xfff00000 | local_c,local_c * param_2,
                         local_c,0);
    if ((-1 < iVar1) && (iVar1 = FUN_00914593(*(undefined4 *)(in_ECX + 0x100)), -1 < iVar1)) {
      local_10 = 0;
      if (param_2 != 0) {
        do {
          uVar3 = 0;
          local_14 = 0;
          if (param_3 != 0) {
            do {
              if (*(int *)(param_1 +
                          *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                           *(int *)(*(int *)(*(int *)(in_ECX + 0x100) + 0x10) +
                                                   uVar3 * 4) * 4) + 0x10) * 4) != -1) {
                *(undefined4 *)(*(int *)(local_8 + 8) + (local_10 * local_c + local_14) * 4) =
                     *(undefined4 *)
                      (*(int *)(*(int *)(in_ECX + 0x100) + 8) + (local_10 * param_3 + uVar3) * 4);
                if (local_10 == 0) {
                  *(undefined4 *)(*(int *)(local_8 + 0x10) + local_14 * 4) =
                       *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x100) + 0x10) + uVar3 * 4);
                }
                local_14 = local_14 + 1;
              }
              uVar3 = uVar3 + 1;
            } while (uVar3 < param_3);
          }
          local_10 = local_10 + 1;
        } while (local_10 < param_2);
      }
      iVar1 = FUN_00915205(local_8);
      if (-1 < iVar1) {
        local_8 = 0;
        iVar1 = 0;
      }
    }
    if (local_8 != 0) {
      FUN_008f4adb(1);
    }
  }
  return iVar1;
}


// ==== FUN_009476e9 @ 0x009476e9 ====

undefined4 FUN_009476e9(undefined4 param_1)

{
  return param_1;
}


// ==== FUN_009476f5 @ 0x009476f5 ====

int FUN_009476f5(int param_1)

{
  int iVar1;
  int iVar2;
  
  while( true ) {
    while( true ) {
      if (param_1 == 0) {
        return 0;
      }
      iVar1 = *(int *)(param_1 + 4);
      if (iVar1 == 1) {
        iVar1 = FUN_009476f5(*(undefined4 *)(param_1 + 0xc));
        iVar2 = FUN_009476f5(*(undefined4 *)(param_1 + 8));
        return iVar2 + iVar1;
      }
      if (iVar1 != 6) break;
      param_1 = *(int *)(param_1 + 0x18);
    }
    if (iVar1 == 8) {
      iVar1 = FUN_009476f5(*(undefined4 *)(param_1 + 0x10));
      return iVar1 * *(int *)(param_1 + 0x14);
    }
    if (iVar1 == 9) break;
    if (iVar1 != 0xb) {
      return 0;
    }
    param_1 = *(int *)(param_1 + 0x20);
  }
  return *(int *)(param_1 + 0x1c) * *(int *)(param_1 + 0x18);
}


// ==== FUN_00947758 @ 0x00947758 ====

int FUN_00947758(undefined4 param_1,int param_2,uint param_3,uint param_4,int param_5)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  void *_Memory;
  int iVar4;
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  void *pvVar5;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_5 == 0) {
    iVar3 = 0;
  }
  else {
    for (; iVar3 = *(int *)(param_2 + 4), iVar3 != 1; param_2 = *(int *)(param_2 + 0x10)) {
      if (iVar3 != 8) {
        if (iVar3 != 9) {
          return -0x7fffbffb;
        }
        uVar1 = 0;
        local_8 = 0;
        iVar3 = *(int *)(param_2 + 0x10);
        if (iVar3 == 0) {
          uVar1 = 0;
        }
        else if (iVar3 == 1) {
          uVar1 = 1;
        }
        else if (iVar3 == 2) {
          uVar1 = (byte)~(byte)(*(uint *)(param_2 + 0x20) >> 10) & 1 | 2;
        }
        else if (iVar3 == 3) {
          uVar1 = 4;
        }
        switch(*(undefined4 *)(param_2 + 0x14)) {
        case 0:
          local_14 = CONCAT22(1,uVar1);
          break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 0xd:
          local_14 = CONCAT22(2,uVar1);
          break;
        case 9:
        case 10:
        case 0xb:
        case 0xc:
          local_14 = CONCAT22(3,uVar1);
          break;
        case 0xe:
          local_14 = CONCAT22(4,uVar1);
          break;
        case 0xf:
          local_14 = CONCAT22(5,uVar1);
          break;
        case 0x10:
          local_14 = CONCAT22(6,uVar1);
          break;
        case 0x11:
          local_14 = CONCAT22(7,uVar1);
          break;
        case 0x12:
          local_14 = CONCAT22(8,uVar1);
          break;
        case 0x13:
          local_14 = CONCAT22(9,uVar1);
          break;
        case 0x14:
          if ((param_4 & 0x200000) != 0) goto switchD_009477ed_caseD_16;
          if ((param_4 & 0x400000) == 0) {
            local_14 = CONCAT22((ushort)(param_4 >> 0x16),uVar1) & 0x2ffff | 0xc0000;
            break;
          }
        case 0x17:
          local_14 = CONCAT22(0xd,uVar1);
          break;
        case 0x15:
          local_14 = CONCAT22(0xb,uVar1);
          break;
        case 0x16:
switchD_009477ed_caseD_16:
          local_14 = CONCAT22(0xc,uVar1);
          break;
        case 0x18:
          local_14 = CONCAT22(0xe,uVar1);
          break;
        case 0x19:
          local_14 = CONCAT22(0xf,uVar1);
          break;
        case 0x1a:
          local_14 = CONCAT22(0x10,uVar1);
          break;
        case 0x1b:
          local_14 = CONCAT22(0x11,uVar1);
          break;
        case 0x1c:
          local_14 = CONCAT22(0x12,uVar1);
          break;
        default:
          local_14 = (uint)uVar1;
        }
        local_10 = CONCAT22(*(undefined2 *)(param_2 + 0x1c),*(undefined2 *)(param_2 + 0x18));
        local_c = param_3 & 0xffff;
        iVar3 = FUN_0093ccb5(&local_14,0x10,2,param_5);
        if (iVar3 < 0) {
          return iVar3;
        }
        return 0;
      }
      param_3 = param_3 * *(int *)(param_2 + 0x14);
    }
    local_c = 0;
    local_8 = 0;
    local_14 = 5;
    local_10 = 1;
    uVar2 = FUN_009476f5(param_2);
    local_10 = CONCAT22(uVar2,(undefined2)local_10);
    iVar3 = param_2;
    do {
      local_c._2_2_ = local_c._2_2_ + 1;
      iVar3 = *(int *)(iVar3 + 0xc);
    } while (iVar3 != 0);
    _Memory = operator_new((uint)local_c._2_2_ << 3);
    pvVar5 = _Memory;
    if (_Memory != (void *)0x0) {
      while( true ) {
        iVar3 = *(int *)(*(int *)(param_2 + 8) + 0x18);
        iVar4 = FUN_0093ccb5(*(undefined4 *)(*(int *)(*(int *)(param_2 + 8) + 0x14) + 0x18),
                             0xffffffff,7,pvVar5);
        if (iVar4 < 0) {
          _free(_Memory);
          return extraout_EAX_00;
        }
        iVar3 = FUN_00947758(param_1,*(undefined4 *)(iVar3 + 0x20),1,param_4,(int)pvVar5 + 4);
        if (iVar3 < 0) break;
        param_2 = *(int *)(param_2 + 0xc);
        pvVar5 = (void *)((int)pvVar5 + 8);
        if (param_2 == 0) {
          FUN_0093ccb5(_Memory,(uint)local_c._2_2_ << 3,2,&local_8);
          _free(_Memory);
          return extraout_EAX;
        }
      }
      _free(_Memory);
      return extraout_EAX_01;
    }
    iVar3 = -0x7ff8fff2;
  }
  return iVar3;
}


// ==== FUN_00947a51 @ 0x00947a51 ====

undefined4 FUN_00947a51(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  int in_ECX;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint local_8;
  
  uVar3 = *(uint *)(in_ECX + 0x114);
  local_8 = uVar3;
  if (uVar3 == 0) {
    local_8 = 0x400;
  }
  if (local_8 < (uint)(*(int *)(in_ECX + 0x110) + param_1)) {
    do {
      local_8 = local_8 * 2;
    } while (local_8 < (uint)(param_1 + *(int *)(in_ECX + 0x110)));
  }
  if (local_8 == uVar3) {
    uVar2 = 0;
  }
  else {
    puVar1 = operator_new(local_8 << 2);
    if (puVar1 != (undefined4 *)0x0) {
      puVar5 = *(undefined4 **)(in_ECX + 0x10c);
      for (uVar3 = *(uint *)(in_ECX + 0x110) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar1 = puVar1 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar1 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar1 = (undefined4 *)((int)puVar1 + 1);
      }
      _free(*(void **)(in_ECX + 0x10c));
      return extraout_EAX;
    }
    uVar2 = 0x8007000e;
  }
  return uVar2;
}


// ==== FUN_00947af9 @ 0x00947af9 ====

int FUN_00947af9(int param_1,uint *param_2,undefined4 param_3,undefined4 *param_4)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  uint local_c;
  uint local_8;
  
  local_c = 0;
  local_8 = 0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  iVar2 = *(int *)(param_1 + 4);
  if (in_ECX[0x22] == iVar2) {
    local_8 = *(uint *)(param_1 + 0xc);
    local_c = 0;
    if ((uint)in_ECX[0xb] <= local_8) {
LAB_00947bd9:
      FUN_0091a001();
      return -0x7789f4a7;
    }
    uVar1 = in_ECX[0x14];
    if ((uVar1 != 0) && (uVar1 <= local_8)) {
      local_8 = local_8 - uVar1;
      local_c = 3;
    }
  }
  else if (in_ECX[0x23] == iVar2) {
    local_8 = *(uint *)(param_1 + 0xc);
    local_c = 3;
    if (local_8 != 0) goto LAB_00947bd9;
  }
  else if (in_ECX[0x21] == iVar2) {
    iVar2 = (**(code **)(*in_ECX + 0x84))(param_1,&local_8,&local_c,param_4);
    if (iVar2 < 0) {
      return -0x7fffbffb;
    }
  }
  else {
    if (in_ECX[0x24] != iVar2) {
      FUN_0091a001();
      return -0x7fffbffb;
    }
    local_8 = *(uint *)(param_1 + 0xc);
    local_c = 0x13;
    if ((uint)in_ECX[0xd] <= local_8) goto LAB_00947bd9;
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = ((local_c | 0xfffffff8) << 0x14 | local_c & 0x18) << 8 | local_8 & 0x7ff;
  }
  iVar2 = (**(code **)(*in_ECX + 0x7c))(param_1,param_3);
  if (-1 < iVar2) {
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_00947c46 @ 0x00947c46 ====

undefined4 FUN_00947c46(void)

{
  return 0x80004005;
}


// ==== FUN_00947c4e @ 0x00947c4e ====

undefined4 FUN_00947c4e(int *param_1,uint param_2,uint *param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  uint local_c;
  uint local_8;
  
  uVar3 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + *param_1 * 4) + 0x3c);
  local_c = 0;
  local_8 = 0;
  if ((uVar3 & 0x400) == 0) {
    if ((uVar3 & 0x800) == 0) {
      if ((uVar3 & 0x1000) == 0) {
        if ((uVar3 & 0x2000) == 0) {
          if ((uVar3 & 0x4000) == 0) {
            if ((char)(uVar3 >> 8) < '\0') {
              local_8 = 0xd000000;
            }
          }
          else {
            local_8 = 0xe000000;
          }
        }
        else {
          local_8 = 0xf000000;
        }
      }
      else {
        local_8 = 0x3000000;
      }
    }
    else {
      local_8 = 0x2000000;
    }
  }
  else {
    local_8 = 0x1000000;
  }
  if ((uVar3 & 0x200) != 0) {
    local_8 = CONCAT13(local_8._3_1_,0x100000);
  }
  if (param_4 == 0) {
    uVar3 = 0;
    if (param_2 != 0) {
      do {
        iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_1[uVar3] * 4) + 0x10);
        uVar4 = 0;
        if (iVar2 == 0) {
          uVar4 = 0x10000;
        }
        else if (iVar2 == 1) {
          uVar4 = 0x20000;
        }
        else if (iVar2 == 2) {
          uVar4 = 0x40000;
        }
        else if (iVar2 == 3) {
          uVar4 = 0x80000;
        }
        if ((local_c & uVar4) != 0) {
          FUN_0091a001();
        }
        local_c = local_c | uVar4;
        uVar3 = uVar3 + 1;
      } while (uVar3 < param_2);
    }
  }
  else {
    local_c = 0xf0000;
  }
  uVar3 = 0;
  if ((*(byte *)(in_ECX + 0x6e) & 0x80) != 0) {
    if ((local_c & 0x80000) == 0) {
      local_c = 0x70000;
    }
    else if ((local_c & 0x70000) != 0) {
      local_c = 0xf0000;
    }
  }
  if ((((*(byte *)(in_ECX + 0xcc) & 1) != 0) && (*(int *)(in_ECX + 0x124) != 0)) && (param_2 != 0))
  {
    do {
      piVar1 = param_1 + uVar3;
      iVar2 = uVar3 + *(int *)(in_ECX + 0x128) * 6;
      uVar3 = uVar3 + 1;
      *(int *)(*(int *)(in_ECX + 0x124) + -0x10 + iVar2 * 4) = *piVar1;
    } while (uVar3 < param_2);
  }
  *param_3 = local_8 | local_c;
  return 0;
}


// ==== FUN_00947db0 @ 0x00947db0 ====

undefined4 FUN_00947db0(int param_1,uint *param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  *param_3 = 1;
  uVar1 = *(uint *)(param_1 + 0xc);
  *param_2 = uVar1;
  if (uVar1 < *(uint *)(in_ECX + 0x28)) {
    uVar2 = 0;
  }
  else {
    FUN_0091a001();
    uVar2 = 0x80004005;
  }
  return uVar2;
}


// ==== FUN_00947df7 @ 0x00947df7 ====

int FUN_00947df7(uint param_1,uint *param_2,undefined4 *param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  uint uVar4;
  int *local_c;
  int *local_8;
  
  uVar2 = param_1;
  if (in_ECX[0x22] == *(int *)(param_1 + 4)) {
    local_c = *(int **)(param_1 + 0xc);
    param_1 = 0;
    if ((int *)in_ECX[0xb] <= local_c) goto LAB_00947fc5;
    piVar1 = (int *)in_ECX[0x14];
    if ((piVar1 != (int *)0x0) && (piVar1 <= local_c)) {
      local_c = (int *)((int)local_c - (int)piVar1);
      param_1 = 3;
    }
LAB_00947e9b:
    local_8 = (int *)0x0;
    uVar4 = *(uint *)(uVar2 + 0x3c) & 0x1f0000;
    if (uVar4 == 0x100000) {
      local_8 = (int *)0xb000000;
    }
    else if (uVar4 == 0x180000) {
      local_8 = (int *)0xc000000;
    }
    else if (uVar4 == 0x80000) {
      local_8 = (int *)0x1000000;
    }
    else if (uVar4 == 0x20000) {
      local_8 = (int *)0x2000000;
    }
    else if (uVar4 == 0xa0000) {
      local_8 = (int *)0x3000000;
    }
    else if (uVar4 == 0x60000) {
      local_8 = (int *)0x4000000;
    }
    else if (uVar4 == 0xe0000) {
      local_8 = (int *)0x5000000;
    }
    else if (uVar4 == 0x10000) {
      local_8 = (int *)0x6000000;
    }
    else if (uVar4 == 0x40000) {
      local_8 = (int *)0x7000000;
    }
    else if (uVar4 == 0xc0000) {
      local_8 = (int *)0x8000000;
    }
    if (param_2 != (uint *)0x0) {
      *param_2 = ((param_1 | 0xfffffff8) << 0x14 | param_1 & 0x18) << 8 | (uint)local_c & 0x7ff |
                 (uint)local_8;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(uVar2 + 8);
    }
    if (*(int *)(uVar2 + 8) != -1) {
      if (in_ECX[0x55] == 0) goto LAB_009480db;
      *(byte *)((int)param_2 + 1) = *(byte *)((int)param_2 + 1) | 0x20;
    }
    iVar3 = 0;
  }
  else {
    uVar4 = *(uint *)(*(int *)(in_ECX[4] + *(int *)(param_1 + 4) * 4) + 4);
    if (((uVar4 & 0x10) != 0) && ((uVar4 & 4) != 0)) {
      param_1 = 0xf;
      local_c = (int *)0x0;
      goto LAB_00947e9b;
    }
    local_c = in_ECX;
    if (((uVar4 & 0x10) != 0) && ((uVar4 & 0x200) == 0)) {
      iVar3 = (**(code **)(*in_ECX + 0x88))(param_1,&local_c,&param_1);
      if (iVar3 < 0) {
        return iVar3;
      }
      goto LAB_00947e9b;
    }
    if (((uVar4 & 0x200) != 0) && ((uVar4 & 0x42080) == 0)) {
      local_c = *(int **)(param_1 + 0xc);
      if ((int *)in_ECX[0xe] <= local_c) goto LAB_00947fc5;
      if (local_c < (int *)0x800) {
        param_1 = 2;
      }
      else if (local_c < (int *)0x1000) {
        param_1 = 0xb;
      }
      else {
        param_1 = 0xd - (local_c < (int *)0x1800);
      }
      local_c = (int *)((uint)local_c & 0x7ff);
      goto LAB_00947e9b;
    }
    if ((uVar4 & 0x200) != 0) {
      if (-1 < (char)uVar4) {
        if ((uVar4 & 0x2000) != 0) {
          local_c = *(int **)(param_1 + 0xc);
          param_1 = 0xe;
          if ((int *)in_ECX[0x18] <= local_c) goto LAB_00947fc5;
          goto LAB_00947e9b;
        }
        goto LAB_00947f4e;
      }
LAB_00947f52:
      local_c = *(int **)(param_1 + 0xc);
      param_1 = 10;
      if ((int *)in_ECX[0x13] <= local_c) {
LAB_00947fc5:
        FUN_0091a001();
        return -0x7789f4a7;
      }
      goto LAB_00947e9b;
    }
LAB_00947f4e:
    if ((char)uVar4 < '\0') goto LAB_00947f52;
    if ((uVar4 & 0x40000) != 0) {
      local_c = *(int **)(param_1 + 0xc);
      param_1 = 7;
      if ((int *)in_ECX[0x10] <= local_c) goto LAB_00947fc5;
      goto LAB_00947e9b;
    }
    local_8 = in_ECX;
    if (in_ECX[0x24] == *(int *)(param_1 + 4)) {
      local_c = *(int **)(param_1 + 0xc);
      param_1 = 0x13;
      if ((int *)in_ECX[0xd] <= local_c) goto LAB_00947fc5;
      goto LAB_00947e9b;
    }
LAB_009480db:
    FUN_0091a001();
    iVar3 = -0x7fffbffb;
  }
  return iVar3;
}


// ==== FUN_009480f0 @ 0x009480f0 ====

undefined4 FUN_009480f0(void)

{
  uint *puVar1;
  int iVar2;
  bool bVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0;
  bVar3 = false;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar5;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar5 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      uVar4 = *puVar1 & 0xfff00000;
      if (uVar4 != 0) {
        iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar1[2] * 4);
        if (((((((uVar4 == 0x60500000) || (uVar4 == 0x60700000)) || (uVar4 == 0x60800000)) ||
              ((uVar4 == 0x60900000 || (uVar4 == 0x60600000)))) ||
             ((uVar4 == 0x60000000 || ((uVar4 == 0x60200000 || (uVar4 == 0x60300000)))))) ||
            (uVar4 == 0x60400000)) || (uVar4 == 0x60100000)) {
          if ((*(byte *)(iVar2 + 0x3e) & 0xc0) != 0) {
            bVar3 = true;
          }
          *(undefined4 *)(iVar2 + 0x3c) = 0x200000;
        }
        else if ((((uVar4 == 0x60a00000) || (uVar4 == 0x60c00000)) || (uVar4 == 0x60d00000)) ||
                ((uVar4 == 0x60e00000 || (uVar4 == 0x60b00000)))) {
          if ((*(byte *)(iVar2 + 0x3e) & 0xa0) != 0) {
            bVar3 = true;
          }
          *(undefined4 *)(iVar2 + 0x3c) = 0x400000;
        }
        else if (((uVar4 == 0x60f00000) || (uVar4 == 0x61100000)) ||
                ((uVar4 == 0x61200000 || ((uVar4 == 0x61300000 || (uVar4 == 0x61000000)))))) {
          if ((*(byte *)(iVar2 + 0x3e) & 0x60) != 0) {
            bVar3 = true;
          }
          *(undefined4 *)(iVar2 + 0x3c) = 0x800000;
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(in_ECX + 0xc));
    if (bVar3) {
      FUN_0091a001();
      return 0x80004005;
    }
  }
  return 0;
}


// ==== FUN_00948251 @ 0x00948251 ====

undefined4 FUN_00948251(int *param_1,uint param_2,uint param_3,uint *param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int in_ECX;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  uint local_28 [4];
  int local_18 [4];
  int local_8;
  
  iVar3 = *param_1;
  iVar4 = *(int *)(in_ECX + 0x14);
  local_8 = *(int *)(iVar4 + iVar3 * 4);
  if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(local_8 + 4) * 4) + 4) & 0x80) != 0) {
    *param_4 = 0xe40000;
    return 0;
  }
  bVar9 = (param_3 & 0x10000) != 0;
  if (bVar9) {
    local_18[0] = 0;
  }
  uVar7 = (uint)bVar9;
  if ((param_3 & 0x20000) != 0) {
    local_18[uVar7] = 1;
    uVar7 = uVar7 + 1;
  }
  if ((param_3 & 0x40000) != 0) {
    local_18[uVar7] = 2;
    uVar7 = uVar7 + 1;
  }
  if ((param_3 & 0x80000) != 0) {
    local_18[uVar7] = 3;
    uVar7 = uVar7 + 1;
  }
  if (uVar7 < param_2) {
    param_2 = uVar7;
  }
  uVar7 = 0;
  if (param_2 != 0) {
    do {
      if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4) + 0x10) !=
          *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_1[uVar7] * 4) + 0x10)) break;
      uVar7 = uVar7 + 1;
    } while (uVar7 < param_2);
    if (uVar7 < param_2) {
      uVar7 = 0;
      do {
        local_28[uVar7] = uVar7;
        uVar7 = uVar7 + 1;
      } while (uVar7 < 4);
      goto LAB_00948319;
    }
  }
  local_28[0] = *(uint *)(local_8 + 0x10);
  local_28[1] = local_28[0];
  local_28[2] = local_28[0];
  local_28[3] = local_28[0];
LAB_00948319:
  uVar7 = 0;
  if (param_2 != 0) {
    do {
      piVar2 = local_18 + uVar7;
      piVar1 = param_1 + uVar7;
      uVar7 = uVar7 + 1;
      local_28[*piVar2] = *(uint *)(*(int *)(iVar4 + *piVar1 * 4) + 0x10);
    } while (uVar7 < param_2);
  }
  uVar8 = 0;
  uVar7 = 0x10;
  puVar6 = local_28;
  do {
    uVar5 = *puVar6;
    puVar6 = puVar6 + 1;
    uVar8 = uVar8 | uVar5 << ((byte)uVar7 & 0x1f);
    uVar7 = uVar7 + 2;
  } while (uVar7 < 0x18);
  *param_4 = uVar8;
  return 0;
}


// ==== FUN_00948367 @ 0x00948367 ====

undefined4 FUN_00948367(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0x14) != -1) {
    iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(param_1 + 0x14) * 4);
    if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar1 + 4) * 4) + 4) & 8) != 0) {
      iVar2 = *(int *)(iVar1 + 0x10);
      uVar4 = *(uint *)(iVar1 + 0xc) & 0x7ff;
      uVar3 = uVar4 | 0xb0001000;
      if (iVar2 != 0) {
        if (iVar2 == 1) {
          uVar3 = uVar4 | 0xb0551000;
        }
        else if (iVar2 == 2) {
          uVar3 = uVar4 | 0xb0aa1000;
        }
        else if (iVar2 == 3) {
          uVar3 = uVar4 | 0xb0ff1000;
        }
      }
      if (*(int *)(param_1 + 0x18) == 0) {
        uVar3 = uVar3 | 0xd000000;
      }
    }
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = uVar3;
  }
  return 0;
}


// ==== FUN_009483dd @ 0x009483dd ====

void FUN_009483dd(uint param_1,int param_2,uint param_3,uint param_4,int *param_5)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  uVar3 = 0;
  bVar2 = false;
  if (param_5 != (int *)0x0) {
    do {
      if (*(int *)(in_ECX + 0x150) == *(int *)(param_4 + uVar3 * 4)) {
        bVar2 = true;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < param_5);
  }
  if ((*(uint *)(in_ECX + 0x14c) <= param_1) || (bVar2)) {
    *(undefined4 *)(in_ECX + 0x13c) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x140) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x144) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x148) = 0xffffffff;
    local_8 = operator_new(*(int *)(in_ECX + 0x2c) << 2);
    if (local_8 == (undefined4 *)0x0) goto LAB_009485fd;
    puVar7 = local_8;
    for (uVar3 = *(uint *)(in_ECX + 0x2c) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar7 = 0xffffffff;
      puVar7 = puVar7 + 1;
    }
    uVar3 = 0;
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar7 = 0xff;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    if (*(int *)(in_ECX + 8) != 0) {
      do {
        iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + uVar3 * 4);
        if (((*(int *)(in_ECX + 0x88) == *(int *)(iVar5 + 4)) && (*(int *)(iVar5 + 8) == -1)) &&
           (*(uint *)(iVar5 + 0xc) < *(uint *)(in_ECX + 0x2c))) {
          if ((*(uint *)(iVar5 + 0x48) < param_1) && (param_1 <= *(uint *)(iVar5 + 0x58))) {
            local_8[*(uint *)(iVar5 + 0xc)] = 0;
          }
          uVar6 = *(uint *)(iVar5 + 0x48);
          if ((param_1 <= uVar6) && (uVar6 < (uint)local_8[*(int *)(iVar5 + 0xc)])) {
            local_8[*(int *)(iVar5 + 0xc)] = uVar6;
          }
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(in_ECX + 8));
    }
    uVar3 = 0;
    *(undefined4 *)(in_ECX + 0x150) = 0;
    *(undefined4 *)(in_ECX + 0x14c) = 0;
    if (*(int *)(in_ECX + 0x2c) != 0) {
      do {
        uVar6 = 0;
        if (param_5 == (int *)0x0) {
LAB_009484df:
          if (*(uint *)(in_ECX + 0x14c) < (uint)local_8[uVar3]) {
            *(uint *)(in_ECX + 0x150) = uVar3;
            *(undefined4 *)(in_ECX + 0x14c) = local_8[uVar3];
          }
        }
        else {
          do {
            if (uVar3 == *(uint *)(param_4 + uVar6 * 4)) break;
            uVar6 = uVar6 + 1;
          } while (uVar6 < param_5);
          if (param_5 <= uVar6) goto LAB_009484df;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(in_ECX + 0x2c));
    }
    if (*(uint *)(in_ECX + 0x14c) <= param_1) {
      *(undefined4 *)(in_ECX + 0x14c) = 0xffffffff;
      *(int *)(in_ECX + 0x150) = *(int *)(in_ECX + 0x2c);
    }
  }
  param_4 = 0;
  iVar5 = (-(uint)(param_3 != 1) & 0xfffffffd) + 3;
  if (param_3 != 0) {
    param_5 = (int *)(in_ECX + 0x13c + iVar5 * 4);
    do {
      if (*param_5 != -1) {
        *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + *param_5 * 4) + 0x50) = param_1;
      }
      iVar4 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),*(undefined4 *)(in_ECX + 0x150),iVar5,0);
      *param_5 = iVar4;
      if (iVar4 == -1) break;
      iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4);
      *(undefined4 *)(iVar4 + 0x3c) = 0;
      *(undefined4 *)(iVar4 + 0x30) = 0;
      *(uint *)(iVar4 + 0x48) = param_1;
      *(undefined4 *)(iVar4 + 0x50) = *(undefined4 *)(in_ECX + 0x14c);
      *(uint *)(iVar4 + 0x54) = param_1;
      *(uint *)(iVar4 + 0x58) = param_1;
      *(undefined4 *)(iVar4 + 0x5c) = 1;
      iVar1 = *(int *)(*(int *)(in_ECX + 0x18) + param_1 * 4);
      if (*(int *)(iVar1 + 0xc) != 0) {
        *(undefined4 *)(iVar4 + 0x18) =
             *(undefined4 *)
              (*(int *)(*(int *)(in_ECX + 0x14) + **(int **)(iVar1 + 0x10) * 4) + 0x18);
        *(undefined4 *)(iVar4 + 0x14) =
             *(undefined4 *)
              (*(int *)(*(int *)(in_ECX + 0x14) +
                       **(int **)(*(int *)(*(int *)(in_ECX + 0x18) + param_1 * 4) + 0x10) * 4) +
              0x14);
      }
      if (param_2 != 0) {
        *(int *)(param_2 + param_4 * 4) = *param_5;
      }
      param_5 = param_5 + 1;
      iVar5 = iVar5 + 1;
      param_4 = param_4 + 1;
    } while (param_4 < param_3);
  }
LAB_009485fd:
  _free(local_8);
  return;
}


// ==== FUN_00948616 @ 0x00948616 ====

undefined4 FUN_00948616(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar1 = *(int **)(in_ECX + 0x1b0);
  if (piVar1 != (int *)0x0) {
    uVar2 = *(uint *)(in_ECX + 0x11c);
    if ((uVar2 < *(uint *)(in_ECX + 0x110)) && (*(int *)(in_ECX + 0xd4) == 0)) {
      local_c = 0;
      local_8 = 0;
      if ((*(int *)(in_ECX + 0x100) != 0) &&
         ((iVar3 = *(int *)(*(int *)(in_ECX + 0x100) + 0x3c), iVar3 != 0 &&
          (*(int *)(iVar3 + 4) == 0xd)))) {
        local_c = *(undefined4 *)(iVar3 + 0x40);
        local_8 = *(undefined4 *)(iVar3 + 0x44);
      }
      uVar4 = (**(code **)(*piVar1 + 0x10))
                        (piVar1,local_c,local_8,*(int *)(in_ECX + 0x10c) + uVar2 * 4,
                         *(uint *)(in_ECX + 0x110) - uVar2);
      *(undefined4 *)(in_ECX + 0x11c) = *(undefined4 *)(in_ECX + 0x110);
      return uVar4;
    }
  }
  return 0;
}


// ==== FUN_0094869f @ 0x0094869f ====

undefined4
FUN_0094869f(undefined4 param_1,int param_2,short param_3,int param_4,undefined4 param_5,int param_6
            )

{
  int iVar1;
  undefined1 local_24 [16];
  undefined4 local_14;
  int local_10;
  
  if (param_2 == -1) {
    if (((*(int *)(param_6 + 0x100) != 0) &&
        (iVar1 = *(int *)(*(int *)(param_6 + 0x100) + 0x3c), iVar1 != 0)) &&
       (*(int *)(iVar1 + 4) == 0xd)) {
      param_1 = *(undefined4 *)(iVar1 + 0x40);
      param_2 = *(int *)(iVar1 + 0x44);
      if (param_2 != -1) goto LAB_009486dc;
    }
    param_2 = 0;
  }
LAB_009486dc:
  local_14 = param_1;
  if ((param_3 == 2) || (param_3 == 6)) {
    local_10 = param_2;
    FUN_008bd320(*(undefined4 *)(param_6 + 0xc4),local_24,param_4 + 5000,&DAT_009d5e14,param_5);
    *(undefined4 *)(param_6 + 0xd4) = 1;
  }
  return 0;
}


// ==== FUN_0094872a @ 0x0094872a ====

int FUN_0094872a(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x158) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 500) + *(int *)(in_ECX + 0x1f0) + *(int *)(in_ECX + 0x1d0);
}


// ==== FUN_00948749 @ 0x00948749 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00948749(undefined4 param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 extraout_EAX;
  int in_ECX;
  void *_Base;
  uint uVar3;
  undefined2 local_48;
  undefined2 local_46;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  undefined2 local_3e;
  undefined4 local_3c;
  undefined4 local_38;
  void *local_34;
  uint local_30;
  int local_2c;
  char local_28 [32];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  uVar3 = 0;
  local_38 = param_1;
  local_30 = param_2;
  local_2c = 0;
  local_34 = (void *)0x0;
  if (*(int *)(in_ECX + 0x158) == 0) {
    return 0;
  }
  iVar2 = *(int *)(in_ECX + 0x1d0) + *(int *)(in_ECX + 0x1f0) + *(int *)(in_ECX + 500);
  if (iVar2 != 0) {
    local_34 = operator_new(iVar2 * 4);
    if (local_34 == (void *)0x0) {
      local_2c = -0x7ff8fff2;
    }
    else {
      if (*(int *)(in_ECX + 0x2c) != 0) {
        do {
          _sprintf(local_28,s_r__Int_d_00a2de2c,uVar3);
          local_2c = FUN_00907c5b(local_28,uVar3,1);
          if (local_2c < 0) goto LAB_00948905;
          uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint *)(in_ECX + 0x2c));
      }
      _Base = local_34;
      FUN_009060d2(local_34);
      iVar2 = *(int *)(in_ECX + 0x1d0) + *(int *)(in_ECX + 500);
      FUN_009060d2((void *)((int)_Base + iVar2 * 4));
      uVar3 = iVar2 + *(int *)(in_ECX + 0x1f0);
      _qsort(_Base,uVar3,4,FUN_0090757d);
      local_48 = 1;
      local_46 = 3;
      local_44 = 1;
      local_42 = 4;
      local_40 = 1;
      local_3e = 0;
      local_3c = 0;
      iVar2 = local_30 + param_3 * 0x14;
      local_30 = 0;
      if (uVar3 == 0) {
LAB_00948900:
        local_2c = 0;
      }
      else {
        while( true ) {
          piVar1 = (int *)((int)_Base + local_30 * 4);
          local_2c = FUN_0093ccb5(*(undefined4 *)*piVar1,0xffffffff,7,iVar2);
          if ((local_2c < 0) ||
             (local_2c = FUN_0093ccb5(&local_48,0x10,6,iVar2 + 0xc), local_2c < 0)) break;
          if (*(int *)(*piVar1 + 0xc) != 0) {
            *(byte *)(iVar2 + 10) = *(byte *)(iVar2 + 10) | 1;
            local_2c = FUN_0093ccb5(*piVar1 + 0x10,0x10,7,iVar2 + 0x10);
            if (local_2c < 0) break;
          }
          local_30 = local_30 + 1;
          *(undefined2 *)(iVar2 + 4) = 2;
          *(undefined2 *)(iVar2 + 6) = *(undefined2 *)(*piVar1 + 4);
          *(undefined2 *)(iVar2 + 8) = 1;
          iVar2 = iVar2 + 0x14;
          if (uVar3 <= local_30) goto LAB_00948900;
          _Base = local_34;
        }
      }
    }
  }
LAB_00948905:
  _free(local_34);
  return extraout_EAX;
}


// ==== FUN_0094891f @ 0x0094891f ====

undefined4 FUN_0094891f(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  undefined1 local_1c [4];
  uint local_18;
  int local_10;
  char *local_c;
  char *local_8;
  
  pcVar6 = (char *)0x0;
  local_8 = (char *)0x0;
  local_c = (char *)0x0;
  if (*(int *)(in_ECX + 0x158) == 0) {
    return 0;
  }
  iVar2 = *(int *)(param_1 + 0x30);
  local_10 = in_ECX;
  if (iVar2 != 0) {
    do {
      iVar1 = *(int *)(iVar2 + 8);
      if (*(int *)(iVar1 + 4) == 0x11) {
        iVar4 = 0;
        if (*(int *)(iVar1 + 0x10) != 0) {
          iVar4 = *(int *)(*(int *)(iVar1 + 0x10) + 0x18);
        }
        if (*(int *)(iVar1 + 0x14) == 0) {
          pcVar5 = (char *)0x0;
        }
        else {
          pcVar5 = *(char **)(*(int *)(iVar1 + 0x14) + 0x18);
        }
        if (iVar4 == 0) {
          if ((pcVar5 != (char *)0x0) && (iVar1 = _tolower((int)*pcVar5), iVar1 == 99)) {
            local_c = pcVar5;
          }
        }
        else if (((pcVar5 != (char *)0x0) && (iVar1 = FUN_008f31ff(iVar4,0,local_1c), -1 < iVar1))
                && (iVar1 = _tolower((int)*pcVar5), iVar1 == 99)) {
          if (*(uint *)(local_10 + 200) == local_18) {
            pcVar6 = pcVar5;
          }
          else if ((((*(uint *)(local_10 + 200) ^ local_18) & 0xffff0000) == 0) &&
                  ((short)local_18 == 0)) {
            local_8 = pcVar5;
          }
        }
      }
      iVar2 = *(int *)(iVar2 + 0xc);
    } while (iVar2 != 0);
    if (pcVar6 != (char *)0x0) goto LAB_009489f6;
  }
  pcVar6 = local_8;
  if ((local_8 == (char *)0x0) && (pcVar6 = local_c, local_c == (char *)0x0)) {
    return 0;
  }
LAB_009489f6:
  iVar2 = _tolower((int)*pcVar6);
  if (iVar2 == 99) {
    iVar2 = _isdigit((int)pcVar6[1]);
    if (iVar2 != 0) {
      pcVar5 = pcVar6 + 2;
      while (iVar2 = _isdigit((int)*pcVar5), iVar2 != 0) {
        pcVar5 = pcVar5 + 1;
      }
      if (*pcVar5 == '\0') {
        uVar3 = _atol(pcVar6 + 1);
        if (0x1fff < uVar3) {
          FUN_0091a001(local_10,0,0,s_Constant_variable___s__bound_to_r_00a286f0,pcVar6 + 2,uVar3);
          return 0x80004005;
        }
        *(ushort *)(param_2 + 10) = *(ushort *)(param_2 + 10) | (ushort)(uVar3 << 2) | 2;
      }
    }
  }
  return 0;
}


// ==== FUN_00948a71 @ 0x00948a71 ====

void FUN_00948a71(int param_1,int param_2)

{
  for (; (*(int *)(param_1 + 0x10) != -1 && (*(int *)(param_1 + 0x10) != param_2));
      param_1 = param_1 + 0x24) {
  }
  return;
}


// ==== FUN_00948a8f @ 0x00948a8f ====

void FUN_00948a8f(void)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  FUN_00915c25();
  *in_ECX = &PTR_FUN_00a2de38;
  puVar2 = in_ECX + 0x6d;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = in_ECX + 0x75;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  in_ECX[0x58] = 0xffffffff;
  in_ECX[0x3f] = 0;
  in_ECX[0x40] = 0;
  in_ECX[0x41] = 0;
  in_ECX[0x59] = 0xffffffff;
  in_ECX[0x5a] = 0xffffffff;
  in_ECX[0x5b] = 0xffffffff;
  in_ECX[0x62] = 0xffffffff;
  in_ECX[0x43] = 0;
  in_ECX[0x44] = 0;
  in_ECX[0x45] = 0;
  in_ECX[0x49] = 0;
  in_ECX[0x4a] = 0;
  in_ECX[0x4b] = 0;
  in_ECX[0x4c] = 0;
  in_ECX[0x4d] = 0;
  in_ECX[0x42] = 0;
  in_ECX[0x6c] = 0;
  in_ECX[0x56] = 0;
  in_ECX[0x7c] = 0;
  in_ECX[0x74] = 0;
  in_ECX[0x7d] = 0;
  in_ECX[0x3a] = 0xffff0000;
  in_ECX[0x3b] = 0x10;
  in_ECX[0x39] = 0xffff;
  in_ECX[0x3e] = 0;
  in_ECX[0x3c] = 0;
  in_ECX[0x3d] = 0;
  in_ECX[99] = 0;
  return;
}


// ==== FUN_00948b75 @ 0x00948b75 ====

void FUN_00948b75(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a2de38;
  _free((void *)in_ECX[0x43]);
  return;
}


// ==== FUN_00948bcd @ 0x00948bcd ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_00948bcd(ushort *param_1,int param_2)

{
  short *psVar1;
  short sVar2;
  undefined4 uVar3;
  short *psVar4;
  int iVar5;
  uint uVar6;
  int *in_ECX;
  uint local_20c;
  undefined1 local_208 [512];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  local_20c = 0;
  if (*(int *)(param_1 + 0x34) == 0) {
    *(byte *)((int)param_1 + 3) = *(byte *)((int)param_1 + 3) | 0x40;
    uVar3 = (**(code **)(*in_ECX + 0x50))(0,0);
    *(undefined4 *)(param_1 + 0x36) = uVar3;
    return 0;
  }
  psVar1 = *(short **)(*(int *)(param_1 + 0x34) + 0x18);
  if (in_ECX[0x56] != 0) {
    psVar4 = psVar1;
    do {
      sVar2 = *psVar4;
      psVar4 = (short *)((int)psVar4 + 1);
    } while ((char)sVar2 != '\0');
    if ((2 < (uint)((int)psVar4 - (int)((int)psVar1 + 1))) && (DAT_00a27eb4 == *psVar1)) {
      uVar6 = *(uint *)(param_1 + 0x38);
      if (4 < uVar6) {
        FUN_0091a001();
      }
      local_20c = (uint)(4 < uVar6);
      iVar5 = FUN_0090609c(psVar1);
      if (iVar5 == 0) {
        uVar6 = FUN_00907c5b(psVar1,in_ECX[0x74],1);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
        iVar5 = in_ECX[0x74];
        in_ECX[0x74] = iVar5 + 1;
      }
      else {
        iVar5 = *(int *)(iVar5 + 4);
      }
      uVar3 = (**(code **)(*in_ECX + 0x50))(0xffff,iVar5);
      *(undefined4 *)(param_1 + 0x36) = uVar3;
      goto LAB_00948cd0;
    }
  }
  if (((*(int *)(param_1 + 0x36) == -1) || ((*(byte *)((int)param_1 + 3) & 0x40) == 0)) ||
     (param_2 != 0)) {
    uVar6 = *(uint *)(*(int *)(in_ECX[4] + *(int *)(param_1 + 2) * 4) + 4);
    if ((*(byte *)(in_ECX + 0x1c) & 0x40) == 0) {
      if (((uVar6 & 0x10) != 0) && ((uVar6 & 0x200) == 0)) {
        uVar6 = FUN_0093e2ff(param_1,in_ECX[0x3d],1,&local_20c);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
        if ((in_ECX[10] == 2) &&
           (iVar5 = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(param_1 + 0x36)), iVar5 == 0xb)) {
          *param_1 = *param_1 | 0x114;
          param_1[0x10] = 0;
          param_1[0x11] = 0;
          param_1[0x12] = 0;
          param_1[0x13] = 0;
          param_1[0x14] = 0;
          param_1[0x15] = 0;
          param_1[0x16] = 0;
          param_1[0x17] = 0x3ff0;
        }
        goto LAB_00948cd0;
      }
      if ((uVar6 & 0x20) == 0) goto LAB_00948cd0;
      uVar3 = 1;
      iVar5 = in_ECX[0x3e];
    }
    else {
      if (((uVar6 & 0x10) != 0) && ((uVar6 & 0x200) == 0)) {
        uVar6 = FUN_0093e2ff(param_1,in_ECX[0x3c],2,&local_20c);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
        if ((*(int *)(param_1 + 0x36) != 10) || (*(int *)(param_1 + 8) != 0)) goto LAB_00948cd0;
        FUN_009154c0(param_1);
        goto LAB_00948d26;
      }
      if ((uVar6 & 0x20) == 0) goto LAB_00948cd0;
      uVar3 = 2;
      iVar5 = in_ECX[0x3d];
    }
    uVar6 = FUN_0093e2ff(param_1,iVar5,uVar3,&local_20c);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
  }
  else {
    FUN_0091564e(param_1,local_208,0x200);
LAB_00948d26:
    FUN_0091a001();
    local_20c = 1;
  }
LAB_00948cd0:
  return -(uint)(local_20c != 0) & 0x80004005;
}


// ==== FUN_00948e39 @ 0x00948e39 ====

int FUN_00948e39(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *in_ECX;
  int *piVar7;
  uint *puVar8;
  uint uVar9;
  uint local_68 [8];
  uint local_48;
  uint *local_44;
  int local_40;
  int local_3c;
  uint *local_38;
  int local_34;
  int local_30;
  uint local_2c;
  int local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  int *local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar3 = FUN_0093e2c8();
  if (-1 < iVar3) {
    iVar3 = in_ECX[2];
    local_10 = 0;
    if (iVar3 != 0) {
      piVar7 = (int *)in_ECX[5];
      do {
        if ((in_ECX[0x22] == *(int *)(*piVar7 + 4)) &&
           (uVar9 = *(uint *)(*piVar7 + 0xc), local_10 <= uVar9)) {
          local_10 = uVar9 + 1;
        }
        piVar7 = piVar7 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    local_48 = in_ECX[3];
    local_20 = 0;
    if (local_48 != 0) {
      do {
        puVar8 = *(uint **)(in_ECX[6] + local_20 * 4);
        if ((*puVar8 & 0xfff00000) != 0) {
          local_c = *puVar8 & 0xfffff;
          local_2c = puVar8[1] / local_c;
          iVar3 = *(int *)(in_ECX[5] + *(int *)puVar8[4] * 4);
          local_24 = *(int *)(iVar3 + 0x14);
          local_28 = *(int *)(iVar3 + 0x18);
          local_44 = puVar8;
          while ((iVar3 = (**(code **)(*in_ECX + 0x20))(puVar8,&local_1c), iVar3 != 0 &&
                 ((*puVar8 & 0xfff00000) != 0x74100000))) {
            local_34 = *(int *)(in_ECX[4] +
                               *(int *)(*(int *)(in_ECX[5] +
                                                *(int *)(puVar8[2] + local_1c * local_c * 4) * 4) +
                                       4) * 4);
            if ((*(byte *)(local_34 + 4) & 2) != 0) {
LAB_009492b9:
              FUN_0091a001();
              return -0x7fffbffb;
            }
            local_18 = 0;
            local_8 = 0;
            if (local_2c != 0) {
              local_14 = (int *)0x0;
              do {
                iVar3 = *(int *)(in_ECX[4] +
                                *(int *)(*(int *)(in_ECX[5] +
                                                 *(int *)((int)local_14 + puVar8[2]) * 4) + 4) * 4);
                iVar4 = (**(code **)(*in_ECX + 0x9c))(puVar8);
                if ((((iVar4 != 1) && (uVar9 = *(uint *)(iVar3 + 4), (uVar9 & 0x40) != 0)) &&
                    (((*(uint *)(local_34 + 4) ^ uVar9) & 0x12bf) == 0)) && (local_c != 0)) {
                  piVar7 = local_14;
                  uVar9 = local_c;
                  do {
                    uVar1 = *(uint *)(*(int *)(in_ECX[5] + *(int *)((int)piVar7 + puVar8[2]) * 4) +
                                     0x5c);
                    if (local_18 < uVar1) {
                      local_1c = local_8;
                      local_18 = uVar1;
                    }
                    piVar7 = (int *)((int)piVar7 + 4);
                    uVar9 = uVar9 - 1;
                  } while (uVar9 != 0);
                }
                local_8 = local_8 + 1;
                local_14 = (int *)((int)local_14 + local_c * 4);
              } while (local_8 < local_2c);
            }
            iVar3 = *(int *)(in_ECX[5] + *(int *)(puVar8[2] + local_1c * local_c * 4) * 4);
            iVar4 = *(int *)(iVar3 + 4);
            local_34 = *(int *)(iVar3 + 8);
            local_3c = iVar4;
            local_30 = *(int *)(iVar3 + 0xc);
            if ((*(byte *)(*(int *)(in_ECX[4] + iVar4 * 4) + 4) & 0x40) == 0) goto LAB_009492b9;
            local_68[0] = 0xffffffff;
            local_68[1] = 0xffffffff;
            local_18 = 0;
            local_68[2] = 0xffffffff;
            uVar9 = 0;
            local_68[3] = 0xffffffff;
            if (in_ECX[2] != 0) {
              local_14 = (int *)in_ECX[5];
              do {
                uVar1 = local_18;
                iVar3 = *local_14;
                if ((((*(int *)(iVar3 + 4) == iVar4) && (*(int *)(iVar3 + 0xc) == local_30)) &&
                    ((*(int *)(iVar3 + 8) == local_34 &&
                     ((*(int *)(iVar3 + 0x38) == -1 &&
                      (uVar2 = *(uint *)(iVar3 + 0x58), local_20 <= uVar2)))))) &&
                   (local_68[*(int *)(iVar3 + 0x10)] = uVar9, uVar1 <= uVar2)) {
                  local_18 = uVar2 + 1;
                }
                local_14 = local_14 + 1;
                uVar9 = uVar9 + 1;
              } while (uVar9 < (uint)in_ECX[2]);
            }
            uVar9 = 0;
            local_14 = (int *)0x0;
            local_8 = 0;
            do {
              uVar1 = local_8;
              local_38 = (uint *)local_68[local_8];
              if ((uint *)local_68[local_8] != (uint *)0xffffffff) {
                uVar9 = FUN_00915318(in_ECX[0x22],local_10,local_8,0);
                local_68[uVar1 + 4] = uVar9;
                if (uVar9 == 0xffffffff) {
                  return -0x7ff8fff2;
                }
                iVar3 = *(int *)(in_ECX[5] + uVar9 * 4);
                iVar4 = FUN_00914f00();
                if (iVar4 < 0) {
                  return iVar4;
                }
                *(undefined4 *)(iVar3 + 0x68) = 0;
                *(undefined4 *)(iVar3 + 0x6c) = 0xffffffff;
                *(undefined4 *)(iVar3 + 0x70) = 0;
                uVar9 = (int)local_14 + 1;
                local_14 = (int *)uVar9;
                *(int *)(iVar3 + 0x14) = local_24;
                *(int *)(iVar3 + 0x18) = local_28;
              }
              local_8 = local_8 + 1;
            } while (local_8 < 4);
            iVar3 = FUN_00915378(uVar9 & 0xfffff | 0x10000000,uVar9,uVar9);
            if (iVar3 == -1) {
              return -0x7ff8fff2;
            }
            iVar3 = *(int *)(in_ECX[6] + iVar3 * 4);
            iVar4 = FUN_00914593();
            if (iVar4 < 0) {
              return iVar4;
            }
            iVar4 = 0;
            local_8 = 0;
            do {
              if (*(int *)((int)local_68 + local_8) != -1) {
                *(int *)(iVar4 + *(int *)(iVar3 + 8)) = *(int *)((int)local_68 + local_8);
                *(undefined4 *)(iVar4 + *(int *)(iVar3 + 0x10)) =
                     *(undefined4 *)((int)local_68 + local_8 + 0x10);
                iVar4 = iVar4 + 4;
              }
              local_8 = local_8 + 4;
            } while (local_8 < 0x10);
            local_10 = local_10 + 1;
            for (local_8 = local_20; local_8 < local_18; local_8 = local_8 + 1) {
              iVar3 = *(int *)(in_ECX[6] + local_8 * 4);
              if ((*(ushort *)(iVar3 + 2) & 0xfff0) != 0) {
                iVar4 = *(int *)(in_ECX[5] + **(int **)(iVar3 + 0x10) * 4);
                iVar6 = *(int *)(iVar4 + 0x14);
                for (iVar4 = *(int *)(iVar4 + 0x18);
                    (iVar6 != -1 && ((iVar6 != local_24 || (iVar4 != local_28))));
                    iVar4 = *(int *)(iVar4 + 0x18)) {
                  iVar4 = *(int *)(in_ECX[5] + iVar6 * 4);
                  iVar6 = *(int *)(iVar4 + 0x14);
                }
                if ((((iVar6 == local_24) && (iVar4 == local_28)) &&
                    (iVar4 = (**(code **)(*in_ECX + 0x20))(), iVar4 != 0)) &&
                   (local_14 = (int *)0x0, *(int *)(iVar3 + 4) != 0)) {
                  do {
                    iVar4 = (int)local_14 * 4;
                    local_38 = (uint *)(*(int *)(iVar3 + 8) + iVar4);
                    local_40 = *(int *)(in_ECX[5] + *local_38 * 4);
                    if (((*(int *)(local_40 + 4) == local_3c) &&
                        (*(int *)(local_40 + 0xc) == local_30)) &&
                       (*(int *)(local_40 + 8) == local_34)) {
                      if (*(int *)(local_40 + 0x38) == -1) {
                        *local_38 = local_68[*(int *)(local_40 + 0x10) + 4];
                      }
                      else {
                        local_38 = *(uint **)(in_ECX[5] +
                                             local_68[*(int *)(local_40 + 0x10) + 4] * 4);
                        uVar5 = FUN_00915318(in_ECX[0x22],local_38[3],local_38[4],0);
                        *(undefined4 *)(iVar4 + *(int *)(iVar3 + 8)) = uVar5;
                        if (*(int *)(iVar4 + *(int *)(iVar3 + 8)) == -1) {
                          return -0x7ff8fff2;
                        }
                        iVar4 = *(int *)(in_ECX[5] + *(int *)(iVar4 + *(int *)(iVar3 + 8)) * 4);
                        iVar6 = FUN_00914f00();
                        if (iVar6 < 0) {
                          return iVar6;
                        }
                        *(uint *)(iVar4 + 0x38) = local_68[*(int *)(local_40 + 0x10) + 4];
                        *(undefined4 *)(iVar4 + 0x3c) = *(undefined4 *)(local_40 + 0x3c);
                      }
                    }
                    local_14 = (int *)((int)local_14 + 1);
                  } while (local_14 < *(uint *)(iVar3 + 4));
                  puVar8 = local_44;
                }
              }
            }
          }
          iVar3 = FUN_00915471();
          if (iVar3 < 0) {
            return iVar3;
          }
          *puVar8 = 0;
        }
        local_20 = local_20 + 1;
      } while (local_20 < local_48);
    }
    iVar3 = 0;
  }
  return iVar3;
}


// ==== FUN_009492d3 @ 0x009492d3 ====

int FUN_009492d3(void)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int *piVar6;
  char *pcVar7;
  int *piVar8;
  char *pcVar9;
  bool bVar10;
  undefined4 local_64 [4];
  char local_54 [16];
  int local_44 [5];
  uint local_30;
  uint local_2c;
  int local_28;
  int local_24;
  uint local_20;
  char *local_1c;
  uint local_18;
  int local_14;
  int local_10;
  uint local_c;
  uint *local_8;
  
  iVar1 = FUN_0093e2c8();
  if (-1 < iVar1) {
    local_c = 0;
    uVar3 = in_ECX[3];
    local_2c = uVar3;
    if (uVar3 != 0) {
      do {
        puVar5 = *(uint **)(in_ECX[6] + local_c * 4);
        if ((*puVar5 & 0xfff00000) != 0) {
          local_10 = 0;
          local_18 = *puVar5 & 0xfffff;
          local_8 = puVar5;
          iVar1 = (**(code **)(*in_ECX + 0x20))(puVar5,&local_28);
          while ((uVar4 = local_18, iVar1 != 0 && ((*puVar5 & 0xfff00000) != 0x74100000))) {
            if ((uint)in_ECX[0x53] <= local_c) {
              local_44[0] = -1;
              local_44[1] = 0xffffffff;
              local_44[2] = 0xffffffff;
              local_44[3] = 0xffffffff;
              local_54[0] = -1;
              local_54[1] = -1;
              local_54[2] = -1;
              local_54[3] = -1;
              local_54[4] = -1;
              local_54[5] = -1;
              local_54[6] = -1;
              local_54[7] = -1;
              local_54[8] = -1;
              local_54[9] = -1;
              local_54[10] = -1;
              local_54[0xb] = -1;
              local_54[0xc] = -1;
              local_54[0xd] = -1;
              local_54[0xe] = -1;
              local_54[0xf] = -1;
            }
            local_20 = (-(uint)(local_18 != 1) & 0xfffffffd) + 3;
            iVar1 = local_20 * 4;
            local_1c = (char *)(puVar5[2] + local_28 * local_18 * 4);
            iVar2 = local_18 << 2;
            bVar10 = true;
            pcVar7 = local_1c;
            pcVar9 = local_54 + iVar1;
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar10 = *pcVar7 == *pcVar9;
              pcVar7 = pcVar7 + 1;
              pcVar9 = pcVar9 + 1;
            } while (bVar10);
            local_14 = iVar1;
            if ((!bVar10) ||
               ((puVar5 = local_8, local_8[3] != 0 &&
                (*(int *)(*(int *)(in_ECX[5] + *(int *)local_8[4] * 4) + 0x14) != -1)))) {
              iVar1 = FUN_00915378(local_18 & 0xfffff | 0x10000000,0xffffffff,0xffffffff);
              if (iVar1 == -1) {
                return -0x7ff8fff2;
              }
              local_24 = *(int *)(in_ECX[6] + iVar1 * 4);
              iVar1 = FUN_00914593(local_8);
              if (iVar1 < 0) {
                return iVar1;
              }
              piVar6 = (int *)((int)local_44 + local_14);
              iVar2 = (**(code **)(*in_ECX + 0x80))(local_c,piVar6,uVar4,local_64,local_10);
              iVar1 = local_24;
              if (iVar2 < 0) {
                return iVar2;
              }
              local_44[4] = *(int *)(in_ECX[5] + *piVar6 * 4);
              local_30 = local_20 + uVar4;
              for (; local_20 < local_30; local_20 = local_20 + 1) {
                iVar2 = *(int *)(in_ECX[5] + local_44[local_20] * 4);
                if (local_8[3] != 0) {
                  *(undefined4 *)(iVar2 + 0x14) =
                       *(undefined4 *)(*(int *)(in_ECX[5] + *(int *)local_8[4] * 4) + 0x14);
                  *(undefined4 *)(iVar2 + 0x18) =
                       *(undefined4 *)(*(int *)(in_ECX[5] + *(int *)local_8[4] * 4) + 0x18);
                }
              }
              local_64[local_10] = *(undefined4 *)(local_44[4] + 0xc);
              puVar5 = local_8;
              piVar8 = *(int **)(iVar1 + 0x10);
              for (uVar3 = uVar4 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                *piVar8 = *piVar6;
                piVar6 = piVar6 + 1;
                piVar8 = piVar8 + 1;
              }
              for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
                *(char *)piVar8 = (char)*piVar6;
                piVar6 = (int *)((int)piVar6 + 1);
                piVar8 = (int *)((int)piVar8 + 1);
              }
              pcVar7 = local_1c;
              pcVar9 = *(char **)(local_24 + 8);
              for (uVar3 = uVar4 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
                pcVar7 = pcVar7 + 4;
                pcVar9 = pcVar9 + 4;
              }
              local_10 = local_10 + 1;
              for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
                *pcVar9 = *pcVar7;
                pcVar7 = pcVar7 + 1;
                pcVar9 = pcVar9 + 1;
              }
              pcVar7 = local_1c;
              pcVar9 = local_54 + local_14;
              for (uVar4 = uVar4 & 0x3fffffff; iVar1 = local_14, uVar4 != 0; uVar4 = uVar4 - 1) {
                *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
                pcVar7 = pcVar7 + 4;
                pcVar9 = pcVar9 + 4;
              }
              for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
                *pcVar9 = *pcVar7;
                pcVar7 = pcVar7 + 1;
                pcVar9 = pcVar9 + 1;
              }
            }
            pcVar7 = (char *)((int)local_44 + iVar1);
            pcVar9 = local_1c;
            for (uVar3 = local_18 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
              *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
              pcVar7 = pcVar7 + 4;
              pcVar9 = pcVar9 + 4;
            }
            for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
              *pcVar9 = *pcVar7;
              pcVar7 = pcVar7 + 1;
              pcVar9 = pcVar9 + 1;
            }
            iVar1 = (**(code **)(*in_ECX + 0x20))(puVar5,&local_28);
            puVar5 = local_8;
            uVar3 = local_2c;
          }
          iVar1 = FUN_00915471(puVar5);
          if (iVar1 == -1) {
            return -0x7ff8fff2;
          }
          FUN_008f4adb(1);
          *(undefined4 *)(in_ECX[6] + local_c * 4) = 0;
        }
        local_c = local_c + 1;
      } while (local_c < uVar3);
    }
    if (uVar3 < (uint)in_ECX[3]) {
      iVar1 = 0;
      uVar4 = uVar3;
      do {
        *(undefined4 *)(iVar1 + in_ECX[6]) = *(undefined4 *)(in_ECX[6] + uVar4 * 4);
        uVar4 = uVar4 + 1;
        iVar1 = iVar1 + 4;
      } while (uVar4 < (uint)in_ECX[3]);
    }
    in_ECX[3] = in_ECX[3] - uVar3;
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_0094956d @ 0x0094956d ====

undefined4
FUN_0094956d(int *param_1,int *param_2,int *param_3,uint param_4,uint param_5,uint param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  int in_ECX;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  undefined4 auStack_a8 [4];
  undefined4 auStack_98 [4];
  undefined4 auStack_88 [4];
  uint auStack_78 [4];
  undefined4 auStack_68 [4];
  int local_58 [4];
  int local_48 [4];
  int local_38 [4];
  int local_28;
  int local_24;
  uint local_20;
  int *local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  int *local_c;
  int *local_8;
  
  if (param_5 == 0) {
    param_5 = *(int *)(in_ECX + 0x100);
  }
  iVar6 = param_5;
  piVar8 = *(int **)(param_5 + 0x10);
  iVar7 = *(int *)(in_ECX + 0x14);
  if (*(int *)(in_ECX + 0x88) == *(int *)(*(int *)(iVar7 + *piVar8 * 4) + 4)) {
    uVar10 = **(uint **)(in_ECX + 0x100);
    uVar9 = (*(uint **)(in_ECX + 0x100))[3];
    local_10 = 0;
    if ((uVar10 & 0xfffff) == uVar9) {
      local_8 = (int *)0x0;
      if (uVar9 != 0) {
        local_14 = (int)param_3 - (int)piVar8;
        local_c = piVar8;
        do {
          iVar7 = *(int *)(iVar7 + *(int *)(((int)param_3 - (int)piVar8) + (int)local_c) * 4);
          local_24 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4);
          if (((*(int *)(in_ECX + 0x6c) << 0xe < 0) && ((*(byte *)(iVar7 + 0x3d) & 2) != 0)) &&
             (param_1 == (int *)0x80000)) {
            local_10 = 1;
          }
          if (((*(uint *)(iVar7 + 0x3c) & 0x1f0000) != 0) &&
             ((~(uint)param_2 & *(uint *)(iVar7 + 0x3c) & 0x1f0000) != 0)) {
            if (param_1 != (int *)0x80000) {
              return 1;
            }
            local_10 = 1;
          }
          iVar7 = *(int *)(in_ECX + 0x14);
          if ((*(byte *)(*(int *)(iVar7 + *local_c * 4) + 0x3d) & 0xfe) != 0) {
            return 1;
          }
          if (((*(byte *)(in_ECX + 0x6c) & 0x10) != 0) && ((*(byte *)(local_24 + 5) & 2) != 0)) {
            if ((uVar10 & 0xfff00000) != 0x10100000) {
              return 1;
            }
            local_10 = 1;
          }
          local_8 = (int *)((int)local_8 + 1);
          local_c = local_c + 1;
        } while (local_8 < *(uint *)(*(int *)(in_ECX + 0x100) + 0xc));
      }
      param_1 = (int *)0x0;
      if (*(int *)(param_5 + 0xc) != 0) {
        local_18 = (int)param_3 - (int)local_38;
        do {
          bVar12 = local_10 == 0;
          iVar7 = *(int *)(*(int *)(in_ECX + 0x14) +
                          *(int *)((int)param_1 * 4 + *(int *)(param_5 + 0x10)) * 4);
          iVar2 = *(int *)(*(int *)(in_ECX + 0x14) +
                          *(int *)((int)(local_38 + (int)param_1) + local_18) * 4);
          local_38[(int)param_1] = *(int *)(iVar7 + 8);
          uVar3 = *(undefined4 *)(iVar7 + 0x48);
          local_58[(int)param_1] = *(int *)(iVar7 + 0xc);
          local_48[(int)param_1] = *(int *)(iVar7 + 0x10);
          auStack_98[(int)param_1] = *(undefined4 *)(iVar7 + 0x14);
          auStack_68[(int)param_1] = *(undefined4 *)(iVar7 + 0x18);
          uVar10 = *(uint *)(iVar7 + 0x3c);
          auStack_88[(int)param_1] = uVar3;
          uVar3 = *(undefined4 *)(iVar7 + 0x68);
          auStack_78[(int)param_1] = uVar10;
          auStack_a8[(int)param_1] = uVar3;
          if (bVar12) {
            *(undefined4 *)(iVar7 + 4) = *(undefined4 *)(iVar2 + 4);
            *(undefined4 *)(iVar7 + 8) = *(undefined4 *)(iVar2 + 8);
            *(undefined4 *)(iVar7 + 0xc) = *(undefined4 *)(iVar2 + 0xc);
            *(undefined4 *)(iVar7 + 0x10) = *(undefined4 *)(iVar2 + 0x10);
            *(undefined4 *)(iVar7 + 0x14) = *(undefined4 *)(iVar2 + 0x14);
            *(undefined4 *)(iVar7 + 0x18) = *(undefined4 *)(iVar2 + 0x18);
            *(undefined4 *)(iVar7 + 0x48) = *(undefined4 *)(iVar2 + 0x48);
            *(undefined4 *)(iVar7 + 0x68) = *(undefined4 *)(iVar2 + 0x68);
            uVar10 = *(uint *)(iVar2 + 0x3c) ^ param_4 | *(uint *)(iVar2 + 0x3c) & ~param_4 | uVar10
            ;
          }
          else {
            uVar10 = uVar10 ^ param_4 | ~param_4 & uVar10;
          }
          param_1 = (int *)((int)param_1 + 1);
          *(uint *)(iVar7 + 0x3c) = uVar10;
        } while (param_1 < *(uint *)(param_5 + 0xc));
      }
      uVar10 = *(uint *)(param_5 + 0xc);
      param_2 = (int *)0x0;
      local_18 = uVar10;
      if (uVar10 != 0) {
        param_1 = *(int **)(param_5 + 0x10);
        do {
          iVar7 = FUN_009453d9(*param_1);
          if (iVar7 == 1) goto LAB_009499c4;
          param_2 = (int *)((int)param_2 + 1);
          param_1 = param_1 + 1;
        } while (param_2 < uVar10);
      }
      local_8 = (int *)0xffffffff;
      param_2 = (int *)0x0;
      param_1 = (int *)0xffffffff;
      if (uVar10 != 0) {
        local_28 = (int)local_38 - (int)param_3;
        local_20 = (int)local_58 - (int)param_3;
        local_24 = *(int *)(param_5 + 0x10) - (int)param_3;
        local_1c = (int *)((int)local_48 - (int)param_3);
        local_14 = local_18;
        piVar8 = param_3;
        do {
          local_c = *(int **)(*(int *)(in_ECX + 0x14) + *(int *)(local_24 + (int)piVar8) * 4);
          iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar8 * 4);
          if (*(int **)((int)local_c + 0x54) < local_8) {
            local_8 = *(int **)((int)local_c + 0x54);
          }
          if (param_2 < *(int **)((int)local_c + 0x58)) {
            param_2 = *(int **)((int)local_c + 0x58);
          }
          if ((((*(int *)(in_ECX + 0x88) == *(int *)(iVar7 + 4)) &&
               (*(int *)(((int)local_38 - (int)param_3) + (int)piVar8) == *(int *)(iVar7 + 8))) &&
              (*(int *)(((int)local_58 - (int)param_3) + (int)piVar8) == *(int *)(iVar7 + 0xc))) &&
             (*(int *)(((int)local_48 - (int)param_3) + (int)piVar8) == *(int *)(iVar7 + 0x10))) {
            iVar7 = (int)local_c;
          }
          if (*(int **)(iVar7 + 0x50) < param_1) {
            param_1 = *(int **)(iVar7 + 0x50);
          }
          piVar8 = piVar8 + 1;
          local_14 = local_14 - 1;
        } while (local_14 != 0);
      }
      if (((param_6 != 0) || (param_2 <= param_1)) || ((*(uint *)(in_ECX + 0x6c) & 0x10000000) != 0)
         ) {
        if (local_10 != 0) {
          **(uint **)(in_ECX + 0x100) = **(uint **)(in_ECX + 0x100) & 0xfffff | 0x10000000;
          return 0;
        }
        local_c = local_8;
        if (local_8 <= param_2) {
          local_8 = (int *)(*(int *)(in_ECX + 0x18) + (int)local_8 * 4);
          do {
            puVar4 = (uint *)*local_8;
            local_10 = *puVar4;
            if (local_10 != 0) {
              uVar10 = puVar4[2];
              local_14 = 0;
              local_20 = uVar10 + puVar4[1] * 4;
              uVar9 = local_10 & 0xfffff;
              if (uVar10 < local_20) {
                do {
                  param_1 = (int *)0x0;
                  param_5 = 0;
                  if (uVar9 != 0) {
                    do {
                      param_6 = 0;
                      if (*(int *)(iVar6 + 0xc) != 0) {
                        piVar8 = *(int **)(iVar6 + 0x10);
                        while (*piVar8 != *(int *)(uVar10 + param_5 * 4)) {
                          param_6 = param_6 + 1;
                          local_1c = piVar8 + 1;
                          if (*(uint *)(iVar6 + 0xc) <= param_6) goto LAB_00949917;
                          piVar8 = local_1c;
                        }
                        param_1 = (int *)((int)param_1 + 1);
                      }
LAB_00949917:
                      param_5 = param_5 + 1;
                    } while (param_5 < uVar9);
                    if (param_1 != (int *)0x0) {
                      if (((param_1 != (int *)uVar9) ||
                          (uVar11 = local_10 & 0xfff00000, uVar11 == 0x70500000)) ||
                         ((uVar11 == 0x70600000 || (uVar11 == 0x70700000)))) goto LAB_009499c4;
                      local_14 = 1;
                    }
                  }
                  uVar10 = uVar10 + uVar9 * 4;
                } while (uVar10 < local_20);
                if (((local_14 != 0) &&
                    (((((local_10 & 0xf0000000) == 0x60000000 ||
                       (uVar10 = local_10 & 0xfff00000, uVar10 == 0x10d00000)) ||
                      (uVar10 == 0x10e00000)) || (uVar10 == 0x11000000)))) &&
                   ((*(byte *)(in_ECX + 0x6e) & 0x80) == 0)) goto LAB_009499c4;
              }
            }
            local_c = (int *)((int)local_c + 1);
            local_8 = local_8 + 1;
          } while (local_c <= param_2);
        }
        if (*(int *)(in_ECX + 0x15c) == 0) {
          param_5 = 0;
          if (*(int *)(iVar6 + 0xc) != 0) {
            do {
              puVar4 = *(uint **)(*(int *)(in_ECX + 0x14) +
                                 *(int *)(param_5 * 4 + *(int *)(iVar6 + 0x10)) * 4);
              puVar5 = *(uint **)(*(int *)(in_ECX + 0x14) + param_3[param_5] * 4);
              if (puVar5[0xe] == 0xffffffff) {
                puVar4[0xe] = param_3[param_5];
              }
              else {
                puVar4[0xe] = puVar5[0xe];
              }
              uVar10 = *puVar5;
              *puVar4 = uVar10;
              if (param_4 == 0x80000) {
                if ((uVar10 & 4) != 0) {
                  *puVar4 = uVar10 & 0xfffffffb | 8;
                  goto LAB_00949a81;
                }
              }
              else {
LAB_00949a81:
                if (param_4 == 0x100000) {
                  *puVar4 = *puVar4 | 4;
                }
              }
              FUN_00914f00(puVar5);
              param_5 = param_5 + 1;
            } while (param_5 < *(uint *)(iVar6 + 0xc));
          }
          **(undefined4 **)(in_ECX + 0x100) = 0;
          return 0;
        }
        *(int *)(in_ECX + 0x15c) = 2;
      }
LAB_009499c4:
      uVar10 = 0;
      if (*(int *)(iVar6 + 0xc) != 0) {
        do {
          iVar7 = *(int *)(*(int *)(in_ECX + 0x14) +
                          *(int *)(uVar10 * 4 + *(int *)(iVar6 + 0x10)) * 4);
          *(undefined4 *)(iVar7 + 4) = *(undefined4 *)(in_ECX + 0x88);
          *(int *)(iVar7 + 8) = local_38[uVar10];
          *(int *)(iVar7 + 0xc) = local_58[uVar10];
          *(int *)(iVar7 + 0x10) = local_48[uVar10];
          *(undefined4 *)(iVar7 + 0x14) = auStack_98[uVar10];
          *(undefined4 *)(iVar7 + 0x18) = auStack_68[uVar10];
          *(uint *)(iVar7 + 0x3c) = auStack_78[uVar10];
          puVar1 = auStack_88 + uVar10;
          uVar3 = auStack_a8[uVar10];
          uVar10 = uVar10 + 1;
          *(undefined4 *)(iVar7 + 0x48) = *puVar1;
          *(undefined4 *)(iVar7 + 0x68) = uVar3;
        } while (uVar10 < *(uint *)(iVar6 + 0xc));
      }
    }
  }
  return 1;
}


// ==== FUN_00949ac4 @ 0x00949ac4 ====

void FUN_00949ac4(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x15c) = 0;
  iVar1 = FUN_0094956d(0x80000,0xe0000,*(undefined4 *)(*(int *)(in_ECX + 0x100) + 8),0x80000,0,
                       param_1);
  if (-1 < iVar1) {
    FUN_00941b98();
  }
  return;
}


// ==== FUN_00949b04 @ 0x00949b04 ====

int FUN_00949b04(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  uint local_8;
  
  iVar1 = *(int *)(in_ECX + 0x100);
  local_8 = 0;
  if (*(int *)(iVar1 + 4) != 0) {
    piVar2 = *(int **)(iVar1 + 8);
    do {
      if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                             *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar2 * 4) + 4) * 4) + 5)
          & 2) != 0) {
        return 1;
      }
      local_8 = local_8 + 1;
      piVar2 = piVar2 + 1;
    } while (local_8 < *(uint *)(*(int *)(in_ECX + 0x100) + 4));
  }
  *(undefined4 *)(in_ECX + 0x15c) = 0;
  iVar1 = FUN_0094956d(0x100000,0,*(undefined4 *)(iVar1 + 8),0x100000,0,0);
  if (-1 < iVar1) {
    iVar1 = FUN_00941b98();
  }
  return iVar1;
}


// ==== FUN_00949b7e @ 0x00949b7e ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00949b7e(int param_1)

{
  bool bVar1;
  uint *puVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  int local_2c8 [40];
  int local_228 [40];
  int local_188 [40];
  uint local_e8 [16];
  uint local_a8 [16];
  undefined1 local_68 [16];
  int local_58;
  uint local_54 [5];
  int local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  uint *local_30;
  uint local_2c;
  uint local_28;
  uint *local_24;
  uint *local_20;
  uint *local_1c;
  uint local_18;
  uint local_14;
  uint *local_10;
  uint *local_c;
  int local_8;
  
  local_c = *(uint **)(in_ECX + 0x100);
  local_28 = *local_c & 0xfffff;
  local_58 = 0;
  local_30 = (uint *)0x0;
  local_54[0] = 0;
  local_54[1] = 1;
  local_54[2] = 2;
  local_54[3] = 3;
  local_40 = 0;
  local_34 = *local_c & 0xfffff;
  if ((local_28 <= (*local_c & 0xfffff)) && ((*local_c & 0xfff00000) == 0x20400000)) {
    local_38 = 0;
LAB_00949bec:
    local_14 = 0;
    do {
      piVar4 = local_228;
      for (iVar6 = 0x28; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar4 = -1;
        piVar4 = piVar4 + 1;
      }
      piVar4 = local_2c8;
      for (iVar6 = 0x28; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar4 = -1;
        piVar4 = piVar4 + 1;
      }
      local_20 = (uint *)0x0;
      local_8 = 0;
      local_18 = 0;
      local_1c = (uint *)0x0;
      do {
        if (local_14 == 0) {
          uVar9 = local_18;
        }
        else {
          uVar9 = 1 - local_18;
        }
        uVar7 = local_c[2];
        uVar9 = *(uint *)(&DAT_00a2bdc4 + uVar9 * 4);
        piVar4 = (int *)(uVar7 + (int)local_1c * 4);
        if (uVar9 < 0x10) {
          iVar6 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar4 * 4) + 0x48);
          if (iVar6 != -1) {
            local_2c = *(uint *)(*(int *)(in_ECX + 0x18) + iVar6 * 4);
            iVar6 = FUN_0093d27f(local_2c,piVar4,local_28,local_54,local_68,
                                 *(undefined4 *)(&DAT_00a2bdd0 + uVar9 * 0x20),0);
            if (iVar6 == 0) {
              local_8 = FUN_0093d430(local_2c,&DAT_00a2bdb8 + uVar9 * 0x20,local_a8,&local_20,
                                     local_2c8,local_68,local_34,0);
              goto LAB_00949ced;
            }
          }
          local_8 = 1;
          break;
        }
        uVar8 = 0;
        piVar4 = local_228 + (uVar9 - 0x10) * 4;
        do {
          if (local_54[uVar8] < local_28) {
            *piVar4 = *(int *)(uVar7 + ((int)local_1c + local_54[uVar8]) * 4);
          }
          else {
            *piVar4 = -1;
          }
          uVar8 = uVar8 + 1;
          piVar4 = piVar4 + 1;
        } while (uVar8 < 4);
LAB_00949ced:
        if (local_8 == 1) break;
        local_18 = local_18 + 1;
        local_1c = (uint *)((int)local_1c + local_28);
      } while (local_18 < 2);
      puVar2 = local_20;
      local_18 = 0;
      local_10 = (uint *)0x0;
      do {
        if (local_14 == 0) {
          uVar9 = local_18;
        }
        else {
          uVar9 = 1 - local_18;
        }
        if ((0xf < *(uint *)(&DAT_00a2bdc4 + uVar9 * 4)) &&
           (local_24 = (uint *)0x0, local_20 != (uint *)0x0)) {
          do {
            uVar9 = 0;
            if (local_28 != 0) {
              uVar7 = local_a8[(int)local_24];
              puVar10 = *(uint **)(uVar7 + 0xc);
              do {
                local_1c = (uint *)0x0;
                if (puVar10 != (uint *)0x0) {
                  piVar4 = *(int **)(uVar7 + 0x10);
                  do {
                    if (*(int *)(local_c[2] + ((int)local_10 + uVar9) * 4) == *piVar4) {
                      local_8 = 1;
                      goto LAB_00949d8d;
                    }
                    local_1c = (uint *)((int)local_1c + 1);
                    puVar10 = *(uint **)(uVar7 + 0xc);
                    piVar4 = piVar4 + 1;
                  } while (local_1c < puVar10);
                }
                uVar9 = uVar9 + 1;
              } while (uVar9 < local_28);
            }
LAB_00949d8d:
            local_24 = (uint *)((int)local_24 + 1);
          } while (local_24 < local_20);
        }
        local_18 = local_18 + 1;
        local_10 = (uint *)((int)local_10 + local_28);
      } while (local_18 < 2);
      if (local_8 == 0) {
        if (local_38 != 0) goto LAB_00949f36;
        local_24 = (uint *)0x0;
        if (local_20 != (uint *)0x0) {
          do {
            local_3c = *(uint *)(local_a8[(int)local_24] + 0xc);
            local_1c = (uint *)0x0;
            if (local_3c != 0) {
              do {
                if (*(int *)(in_ECX + 0xc) != 0) {
                  local_10 = *(uint **)(in_ECX + 0x18);
                  local_2c = *(uint *)(in_ECX + 0xc);
                  do {
                    puVar10 = (uint *)*local_10;
                    if ((puVar10 != (uint *)0x0) && (*puVar10 != 0)) {
                      local_18 = 0;
                      if (puVar10[1] != 0) {
                        iVar6 = *(int *)(*(int *)(local_a8[(int)local_24] + 0x10) +
                                        (int)local_1c * 4);
                        piVar4 = (int *)puVar10[2];
                        local_54[4] = puVar10[1];
                        do {
                          if ((*piVar4 == iVar6) ||
                             (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar4 * 4) + 0x38) ==
                              iVar6)) {
                            local_18 = 1;
                          }
                          piVar4 = piVar4 + 1;
                          local_54[4] = local_54[4] - 1;
                        } while (local_54[4] != 0);
                      }
                      if (puVar10 == local_c) {
                        local_18 = 0;
                      }
                      if (local_18 != 0) {
                        puVar3 = (uint *)0x0;
                        do {
                          if (puVar10 == (uint *)local_a8[(int)puVar3]) {
                            local_18 = 0;
                          }
                          puVar3 = (uint *)((int)puVar3 + 1);
                        } while (puVar3 < local_20);
                        if (local_18 != 0) {
                          local_8 = 1;
                        }
                      }
                    }
                    local_10 = local_10 + 1;
                    local_2c = local_2c - 1;
                  } while (local_2c != 0);
                }
                local_1c = (uint *)((int)local_1c + 1);
              } while (local_1c < local_3c);
            }
            local_24 = (uint *)((int)local_24 + 1);
          } while (local_24 < local_20);
        }
        local_1c = (uint *)0x0;
        do {
          iVar6 = local_228[(int)local_1c];
          if ((iVar6 != -1) && (puVar10 = (uint *)0x0, local_20 != (uint *)0x0)) {
            local_3c = *(uint *)(*(int *)(in_ECX + 0x14) + iVar6 * 4);
            do {
              uVar9 = *(uint *)(local_a8[(int)puVar10] + 0xc);
              if (uVar9 != 0) {
                piVar4 = *(int **)(local_a8[(int)puVar10] + 0x10);
                local_2c = uVar9;
                do {
                  if ((iVar6 == *piVar4) || (*(int *)(local_3c + 0x38) == *piVar4)) {
                    local_8 = 1;
                  }
                  piVar4 = piVar4 + 1;
                  local_2c = local_2c - 1;
                } while (local_2c != 0);
              }
              puVar10 = (uint *)((int)puVar10 + 1);
            } while (puVar10 < local_20);
          }
          local_1c = (uint *)((int)local_1c + 1);
        } while (local_1c < (uint *)0x28);
        if (local_8 == 0) goto LAB_00949f36;
      }
      local_14 = local_14 + 1;
    } while (local_14 < 2);
    if (local_8 != 0) goto code_r0x00949f27;
LAB_00949f36:
    puVar10 = local_a8;
    puVar3 = local_e8;
    for (uVar9 = (uint)local_20 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
      *puVar3 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar3 = puVar3 + 1;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(char *)puVar3 = (char)*puVar10;
      puVar10 = (uint *)((int)puVar10 + 1);
      puVar3 = (uint *)((int)puVar3 + 1);
    }
    local_e8[(int)puVar2] = (uint)local_c;
    local_30 = (uint *)((int)local_20 + 1);
    uVar9 = 0;
    do {
      iVar6 = *(int *)((int)local_228 + uVar9);
      if ((iVar6 != -1) || (iVar6 = *(int *)((int)local_2c8 + uVar9), iVar6 != -1)) {
        *(int *)((int)local_188 + uVar9) = iVar6;
      }
      uVar9 = uVar9 + 4;
    } while (uVar9 < 0xa0);
    local_8 = 0;
LAB_00949f98:
    if (local_8 != 0) goto LAB_00949faa;
    goto LAB_0094a6f2;
  }
LAB_00949faa:
  local_1c = *(uint **)(in_ECX + 0x100);
  uVar9 = **(uint **)(in_ECX + 0x100);
  local_28 = uVar9 & 0xfffff;
  if ((local_28 <= local_34) && ((uVar9 & 0xfff00000) == 0x20400000)) {
    local_38 = 0;
LAB_00949fda:
    local_18 = 0;
    do {
      puVar2 = local_30;
      puVar10 = local_e8;
      puVar3 = local_a8;
      for (uVar9 = (uint)local_30 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar3 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar3 = puVar3 + 1;
      }
      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(char *)puVar3 = (char)*puVar10;
        puVar10 = (uint *)((int)puVar10 + 1);
        puVar3 = (uint *)((int)puVar3 + 1);
      }
      piVar4 = local_228;
      for (iVar6 = 0x28; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar4 = -1;
        piVar4 = piVar4 + 1;
      }
      piVar4 = local_2c8;
      for (iVar6 = 0x28; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar4 = -1;
        piVar4 = piVar4 + 1;
      }
      local_20 = puVar2;
      local_8 = 0;
      local_14 = 0;
      local_10 = (uint *)0x0;
      do {
        if (local_18 == 0) {
          uVar9 = local_14;
        }
        else {
          uVar9 = 1 - local_14;
        }
        uVar7 = local_1c[2];
        uVar9 = *(uint *)(&DAT_00a2be24 + uVar9 * 4);
        piVar4 = (int *)(uVar7 + (int)local_10 * 4);
        if (uVar9 < 0x10) {
          iVar6 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar4 * 4) + 0x48);
          if (iVar6 != -1) {
            local_3c = *(uint *)(*(int *)(in_ECX + 0x18) + iVar6 * 4);
            iVar6 = FUN_0093d27f(local_3c,piVar4,local_28,local_54,local_68,
                                 *(undefined4 *)(&DAT_00a2be30 + uVar9 * 0x20),0);
            if (iVar6 == 0) {
              local_8 = FUN_0093d430(local_3c,&DAT_00a2be18 + uVar9 * 0x20,local_a8,&local_20,
                                     local_2c8,local_68,local_34,0);
              goto LAB_0094a0ef;
            }
          }
          local_8 = 1;
          break;
        }
        uVar8 = 0;
        piVar4 = local_228 + (uVar9 - 0x10) * 4;
        do {
          if (local_54[uVar8] < local_28) {
            *piVar4 = *(int *)(uVar7 + (local_54[uVar8] + (int)local_10) * 4);
          }
          else {
            *piVar4 = -1;
          }
          uVar8 = uVar8 + 1;
          piVar4 = piVar4 + 1;
        } while (uVar8 < 4);
LAB_0094a0ef:
        if (local_8 == 1) break;
        local_14 = local_14 + 1;
        local_10 = (uint *)((int)local_10 + local_28);
      } while (local_14 < 2);
      puVar2 = local_20;
      local_14 = 0;
      local_24 = (uint *)0x0;
      do {
        if (local_18 == 0) {
          uVar9 = local_14;
        }
        else {
          uVar9 = 1 - local_14;
        }
        if ((0xf < *(uint *)(&DAT_00a2be24 + uVar9 * 4)) &&
           (local_c = (uint *)0x0, local_20 != (uint *)0x0)) {
          do {
            uVar9 = 0;
            if (local_28 != 0) {
              uVar7 = local_a8[(int)local_c];
              puVar10 = *(uint **)(uVar7 + 0xc);
              do {
                local_10 = (uint *)0x0;
                if (puVar10 != (uint *)0x0) {
                  piVar4 = *(int **)(uVar7 + 0x10);
                  do {
                    if (*(int *)(local_1c[2] + ((int)local_24 + uVar9) * 4) == *piVar4) {
                      local_8 = 1;
                      goto LAB_0094a18a;
                    }
                    local_10 = (uint *)((int)local_10 + 1);
                    puVar10 = *(uint **)(uVar7 + 0xc);
                    piVar4 = piVar4 + 1;
                  } while (local_10 < puVar10);
                }
                uVar9 = uVar9 + 1;
              } while (uVar9 < local_28);
            }
LAB_0094a18a:
            local_c = (uint *)((int)local_c + 1);
          } while (local_c < local_20);
        }
        local_14 = local_14 + 1;
        local_24 = (uint *)((int)local_24 + local_28);
      } while (local_14 < 2);
      if (local_8 == 0) {
        if (local_38 != 0) goto LAB_0094a335;
        local_24 = (uint *)0x0;
        if (local_20 != (uint *)0x0) {
          do {
            local_3c = *(uint *)(local_a8[(int)local_24] + 0xc);
            local_c = (uint *)0x0;
            if (local_3c != 0) {
              do {
                if (*(int *)(in_ECX + 0xc) != 0) {
                  local_10 = *(uint **)(in_ECX + 0x18);
                  local_54[4] = *(uint *)(in_ECX + 0xc);
                  do {
                    puVar10 = (uint *)*local_10;
                    if ((puVar10 != (uint *)0x0) && (*puVar10 != 0)) {
                      local_14 = 0;
                      if (puVar10[1] != 0) {
                        iVar6 = *(int *)(*(int *)(local_a8[(int)local_24] + 0x10) + (int)local_c * 4
                                        );
                        piVar4 = (int *)puVar10[2];
                        local_2c = puVar10[1];
                        do {
                          if ((*piVar4 == iVar6) ||
                             (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar4 * 4) + 0x38) ==
                              iVar6)) {
                            local_14 = 1;
                          }
                          piVar4 = piVar4 + 1;
                          local_2c = local_2c - 1;
                        } while (local_2c != 0);
                      }
                      if (puVar10 == local_1c) {
                        local_14 = 0;
                      }
                      if (local_14 != 0) {
                        puVar3 = (uint *)0x0;
                        do {
                          if (puVar10 == (uint *)local_a8[(int)puVar3]) {
                            local_14 = 0;
                          }
                          puVar3 = (uint *)((int)puVar3 + 1);
                        } while (puVar3 < local_20);
                        if (local_14 != 0) {
                          local_8 = 1;
                        }
                      }
                    }
                    local_10 = local_10 + 1;
                    local_54[4] = local_54[4] - 1;
                  } while (local_54[4] != 0);
                }
                local_c = (uint *)((int)local_c + 1);
              } while (local_c < local_3c);
            }
            local_24 = (uint *)((int)local_24 + 1);
          } while (local_24 < local_20);
        }
        local_c = (uint *)0x0;
        do {
          iVar6 = local_228[(int)local_c];
          if ((iVar6 != -1) && (puVar10 = (uint *)0x0, local_20 != (uint *)0x0)) {
            local_3c = *(uint *)(*(int *)(in_ECX + 0x14) + iVar6 * 4);
            do {
              uVar9 = *(uint *)(local_a8[(int)puVar10] + 0xc);
              if (uVar9 != 0) {
                piVar4 = *(int **)(local_a8[(int)puVar10] + 0x10);
                local_2c = uVar9;
                do {
                  if ((iVar6 == *piVar4) || (*(int *)(local_3c + 0x38) == *piVar4)) {
                    local_8 = 1;
                  }
                  piVar4 = piVar4 + 1;
                  local_2c = local_2c - 1;
                } while (local_2c != 0);
              }
              puVar10 = (uint *)((int)puVar10 + 1);
            } while (puVar10 < local_20);
          }
          local_c = (uint *)((int)local_c + 1);
        } while (local_c < (uint *)0x28);
        if (local_8 == 0) goto LAB_0094a335;
      }
      local_18 = local_18 + 1;
    } while (local_18 < 2);
    if (local_8 != 0) goto code_r0x0094a326;
LAB_0094a335:
    puVar10 = local_a8;
    puVar3 = local_e8;
    for (uVar9 = (uint)local_20 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
      *puVar3 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar3 = puVar3 + 1;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(char *)puVar3 = (char)*puVar10;
      puVar10 = (uint *)((int)puVar10 + 1);
      puVar3 = (uint *)((int)puVar3 + 1);
    }
    local_e8[(int)puVar2] = (uint)local_1c;
    local_30 = (uint *)((int)local_20 + 1);
    uVar9 = 0;
    do {
      iVar6 = *(int *)((int)local_228 + uVar9);
      if ((iVar6 != -1) || (iVar6 = *(int *)((int)local_2c8 + uVar9), iVar6 != -1)) {
        *(int *)((int)local_188 + uVar9) = iVar6;
      }
      uVar9 = uVar9 + 4;
    } while (uVar9 < 0xa0);
    local_8 = 0;
LAB_0094a397:
    iVar6 = local_8;
    goto LAB_0094a39a;
  }
  iVar6 = 1;
LAB_0094a39a:
  local_40 = 1;
  if (iVar6 == 0) {
LAB_0094a6f2:
    iVar6 = FUN_009149f7();
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_0091455d();
    }
    uVar9 = local_34;
    if (iVar6 == 0) {
      return -0x7ff8fff2;
    }
    if (local_40 == 0) {
      uVar7 = local_34 & 0xfffff | 0x70300000;
    }
    else {
      uVar7 = local_34 & 0xfffff | 0x70400000;
    }
    local_8 = FUN_00914a42(uVar7,local_34 * 3,local_34,0);
    if (local_8 < 0) goto LAB_0094a59c;
    local_8 = FUN_00914593();
    if (local_8 < 0) goto LAB_0094a59c;
    local_2c = 0;
    if (uVar9 != 0) {
      local_c = (uint *)(uVar9 << 3);
      local_10 = (uint *)(uVar9 << 2);
      do {
        puVar10 = local_c;
        puVar2 = local_10;
        iVar5 = local_2c * 4;
        *(undefined4 *)(iVar5 + *(int *)(iVar6 + 0x10)) =
             *(undefined4 *)(iVar5 + *(int *)(*(int *)(in_ECX + 0x100) + 0x10));
        *(int *)(iVar5 + *(int *)(iVar6 + 8)) = local_188[local_2c];
        iVar5 = local_188[local_2c + 8];
        local_10 = local_10 + 1;
        *(int *)((int)puVar2 + *(int *)(iVar6 + 8)) = local_188[local_2c + 4];
        local_c = local_c + 1;
        *(int *)((int)puVar10 + *(int *)(iVar6 + 8)) = iVar5;
        local_2c = local_2c + 1;
      } while (local_2c < local_34);
    }
    if (param_1 == 0) {
      iVar6 = FUN_00944b06(iVar6,local_e8,local_30);
      return iVar6;
    }
    local_8 = FUN_00914ca1();
    if (local_8 < 0) goto LAB_0094a59c;
  }
  else {
    if (param_1 != 0) {
      local_40 = 0;
      iVar6 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2bdb8,local_e8,&local_30,
                           local_188,local_54,local_34,param_1);
      if (iVar6 == 0) goto LAB_0094a6f2;
      iVar6 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2be18,local_e8,&local_30,
                           local_188,local_54,local_34,param_1);
    }
    uVar9 = local_34;
    local_40 = 1;
    if (iVar6 == 0) goto LAB_0094a6f2;
    local_40 = 0;
    iVar6 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2be78,local_e8,&local_30,local_188,
                         local_54,local_34,param_1);
    uVar7 = 0;
    if (uVar9 != 0) {
      do {
        if (local_188[uVar7] != local_188[uVar7 + 4]) {
          iVar6 = 1;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar9);
    }
    if (iVar6 == 0) {
LAB_0094a5b6:
      bVar1 = true;
      uVar7 = 0;
      if (uVar9 != 0) {
        do {
          if (local_188[uVar7] != local_188[uVar7 + 4]) {
            return 1;
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar9);
      }
      if (*(int *)(in_ECX + 0x160) == -1) {
        iVar6 = FUN_009152bf(&DAT_00a1fc10,0x311,1,4);
        *(int *)(in_ECX + 0x170) = iVar6;
        if (iVar6 == -1) {
          return -0x7ff8fff2;
        }
        iVar6 = FUN_00915318(iVar6,0,0,_DAT_00a0b350);
        *(int *)(in_ECX + 0x160) = iVar6;
        if (iVar6 == -1) {
          return -0x7ff8fff2;
        }
      }
      uVar7 = 0;
      if (uVar9 != 0) {
        iVar6 = *(int *)(in_ECX + 0x160);
        do {
          local_188[uVar7] = iVar6;
          if (local_188[uVar7 + 8] != local_188[8]) {
            bVar1 = false;
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar9);
      }
      iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + local_188[8] * 4);
      if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar6 + 4) * 4) + 5) & 1) != 0) &&
         (bVar1)) {
        uVar9 = 0;
        piVar4 = (int *)(in_ECX + 0x164);
        do {
          if ((*piVar4 == -1) ||
             (*(double *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar4 * 4) + 0x20) ==
              *(double *)(iVar6 + 0x20))) break;
          uVar9 = uVar9 + 1;
          piVar4 = piVar4 + 1;
        } while (uVar9 < 3);
        if (uVar9 != 3) {
          piVar4 = (int *)(in_ECX + 0x164 + uVar9 * 4);
          if (*piVar4 == -1) {
            iVar6 = FUN_00915318(*(undefined4 *)(in_ECX + 0x170),0,uVar9 + 1,
                                 *(undefined8 *)(iVar6 + 0x20));
            *piVar4 = iVar6;
            if (iVar6 == -1) {
              return -0x7ff8fff2;
            }
          }
          if (local_34 != 0) {
            iVar6 = *piVar4;
            piVar4 = local_188 + 8;
            for (uVar9 = local_34; uVar9 != 0; uVar9 = uVar9 - 1) {
              *piVar4 = iVar6;
              piVar4 = piVar4 + 1;
            }
          }
        }
      }
      goto LAB_0094a6f2;
    }
    local_30 = (uint *)0x0;
    local_8 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2bed8,local_e8,&local_30,
                           local_188,local_54,uVar9,param_1);
    uVar7 = 0;
    local_40 = 1;
    if (uVar9 != 0) {
      do {
        if (local_188[uVar7] != local_188[uVar7 + 4]) {
          local_8 = 1;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar9);
    }
    if (local_8 == 0) goto LAB_0094a5b6;
    local_40 = 0;
    local_30 = (uint *)0x0;
    local_8 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2bf38,local_e8,&local_30,
                           local_188,local_54,uVar9,param_1);
    uVar7 = 0;
    if (uVar9 != 0) {
      do {
        if (local_188[uVar7] != local_188[uVar7 + 4]) {
          local_8 = 1;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar9);
    }
    if (local_8 == 0) goto LAB_0094a5b6;
    local_30 = (uint *)0x0;
    local_8 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2bf98,local_e8,&local_30,
                           local_188,local_54,uVar9,param_1);
    uVar7 = 0;
    local_40 = 1;
    if (uVar9 != 0) {
      do {
        if (local_188[uVar7] != local_188[uVar7 + 4]) {
          local_8 = 1;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar9);
    }
    if (local_8 == 0) goto LAB_0094a5b6;
    iVar6 = local_58;
  }
  local_8 = 0;
LAB_0094a59c:
  if (iVar6 != 0) {
    FUN_008f4adb();
  }
  return local_8;
code_r0x00949f27:
  local_38 = local_38 + 1;
  if (local_38 != 0) goto LAB_00949f98;
  goto LAB_00949bec;
code_r0x0094a326:
  local_38 = local_38 + 1;
  if (local_38 != 0) goto LAB_0094a397;
  goto LAB_00949fda;
}


// ==== FUN_0094a80a @ 0x0094a80a ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0094a80a(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int in_ECX;
  int *piVar9;
  uint auStack_30 [4];
  int local_20 [4];
  int *local_10;
  uint local_c;
  int *local_8;
  
  uVar4 = **(uint **)(in_ECX + 0x100);
  if ((uVar4 & 0xfff00000) != 0x20400000) {
    return 1;
  }
  uVar4 = uVar4 & 0xfffff;
  piVar9 = (int *)(*(uint **)(in_ECX + 0x100))[2];
  local_8 = piVar9 + uVar4;
  iVar6 = *(int *)(in_ECX + 0x14);
  if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(*(int *)(iVar6 + *local_8 * 4) + 4) * 4
                         ) + 5) & 1) == 0) {
    if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                           *(int *)(*(int *)(iVar6 + *piVar9 * 4) + 4) * 4) + 5) & 1) == 0) {
      return 1;
    }
    local_20[3] = 1;
    piVar5 = piVar9;
  }
  else {
    local_20[3] = 0;
    piVar5 = local_8;
    local_8 = piVar9;
  }
  *(undefined4 *)(in_ECX + 0x15c) = 0;
  local_10 = (int *)0x0;
  if (uVar4 != 0) {
    piVar9 = local_8;
    do {
      if (*(double *)
           (*(int *)(iVar6 + *(int *)(((int)piVar5 - (int)local_8) + (int)piVar9) * 4) + 0x20) !=
          _DAT_00a2e000) {
        return 1;
      }
      pbVar1 = *(byte **)(iVar6 + *piVar9 * 4);
      if ((((pbVar1[0x3d] & 2) == 0) && ((*pbVar1 & 4) == 0)) &&
         ((*(byte *)(in_ECX + 0x6e) & 4) != 0)) {
        *(undefined4 *)(in_ECX + 0x15c) = 1;
      }
      local_10 = (int *)((int)local_10 + 1);
      piVar9 = piVar9 + 1;
    } while (local_10 < uVar4);
  }
  iVar7 = *(int *)(*(int *)(iVar6 + **(int **)(*(int *)(in_ECX + 0x100) + 0x10) * 4) + 4);
  local_c = uVar4;
  if (iVar7 == *(int *)(in_ECX + 0x88)) {
    iVar6 = FUN_0094956d(0x20000,0,local_8,0x20000,0,0);
    if (*(int *)(in_ECX + 0x15c) == 2) {
      FUN_0091a096();
      return iVar6;
    }
    return iVar6;
  }
  if (iVar7 == *(int *)(in_ECX + 0x84)) {
    iVar7 = FUN_009473b3(uVar4 | 0x20400000,*(int *)(in_ECX + 0x100),local_20,2);
    if (iVar7 != 0) {
      return iVar7;
    }
    local_10 = local_20 + local_20[3];
    if (*local_10 != 0) {
      local_8 = (int *)0x0;
      if (uVar4 != 0) {
        piVar9 = *(int **)(*local_10 + 8);
        do {
          pbVar1 = *(byte **)(iVar6 + *piVar9 * 4);
          if ((pbVar1[0x3e] & 0x1f) != 0) break;
          if (((*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(pbVar1 + 4) * 4) + 4) & 0x200)
               != 0) || (((*(uint *)(pbVar1 + 0x3c) & 0x200) == 0 && ((*pbVar1 & 4) == 0)))) {
            uVar4 = local_c;
            break;
          }
          local_20[3] = 0;
          local_8 = (int *)((int)local_8 + 1);
          piVar9 = piVar9 + 1;
          uVar4 = local_c;
        } while (local_8 < local_c);
      }
      if (local_8 == (int *)uVar4) {
        uVar8 = local_20[3];
      }
      else {
        local_8 = (int *)0x0;
        if (uVar4 != 0) {
          piVar9 = (int *)(*(int *)(*local_10 + 8) + uVar4 * 4);
          do {
            pbVar1 = *(byte **)(iVar6 + *piVar9 * 4);
            if ((pbVar1[0x3e] & 0x1f) != 0) break;
            if (((*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(pbVar1 + 4) * 4) + 4) &
                 0x200) != 0) || (((*(uint *)(pbVar1 + 0x3c) & 0x200) == 0 && ((*pbVar1 & 4) == 0)))
               ) {
              uVar4 = local_c;
              break;
            }
            local_8 = (int *)((int)local_8 + 1);
            piVar9 = piVar9 + 1;
            uVar4 = local_c;
          } while (local_8 < local_c);
        }
        if (local_8 == (int *)uVar4) {
          return 1;
        }
        uVar8 = uVar4;
      }
      local_8 = (int *)0x0;
      if (uVar4 != 0) {
        iVar6 = uVar8 << 2;
        do {
          iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar6 + *(int *)(*local_10 + 8)) * 4);
          uVar4 = FUN_00915318(*(undefined4 *)(iVar7 + 4),*(undefined4 *)(iVar7 + 0xc),
                               *(undefined4 *)(iVar7 + 0x10),*(undefined8 *)(iVar7 + 0x20));
          local_20[3] = uVar4;
          auStack_30[(int)local_8] = uVar4;
          if (uVar4 == 0xffffffff) {
            return -0x7ff8fff2;
          }
          iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + uVar4 * 4);
          iVar3 = *local_10;
          *(undefined4 *)(iVar2 + 0x38) = *(undefined4 *)(iVar6 + *(int *)(iVar3 + 8));
          *(undefined4 *)(iVar2 + 0x48) = *(undefined4 *)(iVar7 + 0x48);
          *(undefined4 *)(iVar2 + 0x50) = *(undefined4 *)(iVar7 + 0x50);
          *(undefined4 *)(iVar2 + 0x54) = *(undefined4 *)(iVar7 + 0x54);
          *(undefined4 *)(iVar2 + 0x58) = *(undefined4 *)(iVar7 + 0x54);
          *(uint *)(iVar2 + 0x3c) = *(uint *)(iVar7 + 0x3c) | 0x20000;
          *(int *)(iVar6 + *(int *)(iVar3 + 8)) = local_20[3];
          *(undefined4 *)(*(int *)(iVar3 + 0x10) + (int)local_8 * 4) =
               *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x100) + 0x10) + (int)local_8 * 4);
          local_8 = (int *)((int)local_8 + 1);
          iVar6 = iVar6 + 4;
        } while (local_8 < local_c);
      }
      **(undefined4 **)(in_ECX + 0x100) = 0;
      return 0;
    }
  }
  return 1;
}


// ==== FUN_0094ab07 @ 0x0094ab07 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0094ab07(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int in_ECX;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  uint local_c;
  
  *(undefined4 *)(in_ECX + 0x15c) = 0;
  puVar1 = *(uint **)(in_ECX + 0x100);
  uVar3 = *puVar1;
  if ((uVar3 & 0xfff00000) == 0x20500000) {
    uVar3 = uVar3 & 0xfffff;
    piVar7 = (int *)puVar1[2];
    piVar6 = piVar7 + uVar3;
    iVar2 = *(int *)(in_ECX + 0x14);
    if ((*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) +
                           *(int *)(*(int *)(iVar2 + *piVar7 * 4) + 4) * 4) + 4) & 0x100) == 0) {
      if ((*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) +
                             *(int *)(*(int *)(iVar2 + *piVar6 * 4) + 4) * 4) + 4) & 0x100) == 0) {
        return 1;
      }
      piVar4 = piVar7;
    }
    else {
      piVar4 = piVar6;
      piVar6 = piVar7;
    }
    if (uVar3 != 0) {
      uVar8 = 0;
      piVar7 = piVar6;
      do {
        if (*(double *)
             (*(int *)(iVar2 + *(int *)(((int)piVar4 - (int)piVar6) + (int)piVar7) * 4) + 0x20) !=
            _DAT_00a0b350) {
          return 1;
        }
        if (((*(uint *)(*(int *)(iVar2 + *piVar7 * 4) + 0x3c) & 0x1f0000) != 0x20000) &&
           ((*(byte *)(in_ECX + 0x6e) & 8) != 0)) {
          return 1;
        }
        uVar8 = uVar8 + 1;
        piVar7 = piVar7 + 1;
      } while (uVar8 < uVar3);
    }
  }
  else {
    if ((uVar3 & 0xfff00000) != 0x20400000) {
      return 1;
    }
    piVar6 = (int *)puVar1[2];
    uVar3 = uVar3 & 0xfffff;
    local_c = 0;
    if (uVar3 != 0) {
      piVar7 = piVar6;
      do {
        if (*piVar7 != piVar7[uVar3]) {
          return 1;
        }
        if (((*(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar7 * 4) + 0x3c) & 0x1f0000) !=
             0x20000) && ((*(byte *)(in_ECX + 0x6e) & 8) != 0)) {
          return 1;
        }
        local_c = local_c + 1;
        piVar7 = piVar7 + 1;
      } while (local_c < uVar3);
    }
  }
  uVar5 = FUN_0094956d(0x40000,0x20000,piVar6,0x40000,0,0);
  return uVar5;
}


// ==== FUN_0094ac69 @ 0x0094ac69 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0094ac69(uint *param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint uVar6;
  int *piVar7;
  int in_ECX;
  int *piVar8;
  bool bVar9;
  undefined4 uVar10;
  int *local_14;
  uint local_10;
  
  bVar9 = param_1 == (uint *)0x0;
  if (bVar9) {
    param_1 = *(uint **)(in_ECX + 0x100);
  }
  if ((*param_1 & 0xfff00000) == 0x20400000) {
    uVar6 = *param_1 & 0xfffff;
    piVar8 = (int *)param_1[2];
    local_14 = piVar8 + uVar6;
    iVar2 = *(int *)(in_ECX + 0x14);
    if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                           *(int *)(*(int *)(iVar2 + *local_14 * 4) + 4) * 4) + 5) & 1) == 0) {
      if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                             *(int *)(*(int *)(iVar2 + *piVar8 * 4) + 4) * 4) + 5) & 1) == 0) {
        return 1;
      }
      piVar7 = piVar8;
    }
    else {
      piVar7 = local_14;
      local_14 = piVar8;
    }
    puVar3 = *(uint **)(in_ECX + 0x100);
    piVar8 = local_14;
    if (puVar3 != param_1) {
      piVar8 = (int *)puVar3[2];
    }
    *(undefined4 *)(in_ECX + 0x15c) = 0;
    local_10 = 0;
    if (uVar6 != 0) {
      iVar1 = (int)piVar7 - (int)piVar8;
      do {
        if (*(double *)(*(int *)(iVar2 + *(int *)(iVar1 + (int)piVar8) * 4) + 0x20) != _DAT_0099d0a0
           ) {
          return 1;
        }
        if ((bVar9) && ((*(uint *)(*(int *)(iVar2 + *piVar8 * 4) + 0x3c) & 0x1f0000) != 0x80000)) {
          return 1;
        }
        puVar4 = *(uint **)(iVar2 + *piVar8 * 4);
        if (((*(byte *)((int)puVar4 + 0x3d) & 2) == 0) && ((*puVar4 & (uint)bVar9 * 4 + 0x14) == 0))
        {
          *(undefined4 *)(in_ECX + 0x15c) = 1;
        }
        local_10 = local_10 + 1;
        piVar8 = piVar8 + 1;
      } while (local_10 < uVar6);
    }
    if (bVar9) {
      param_1 = (uint *)0x0;
      uVar10 = 0x90000;
      uVar5 = 0x80000;
    }
    else {
      uVar10 = 0x10000;
      local_14 = (int *)puVar3[2];
      uVar5 = 0;
    }
    uVar5 = FUN_0094956d(0x10000,uVar5,local_14,uVar10,param_1,0);
    if (*(int *)(in_ECX + 0x15c) == 2) {
      FUN_0091a096();
    }
  }
  else {
    uVar5 = 1;
  }
  return uVar5;
}


// ==== FUN_0094adf1 @ 0x0094adf1 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0094adf1(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  int local_8;
  
  local_8 = 1;
  if (((**(uint **)(in_ECX + 0x100) & 0xfff00000) == 0x20500000) &&
     ((iVar1 = *(int *)(*(int *)(in_ECX + 0x14) +
                       *(int *)((*(uint **)(in_ECX + 0x100))[2] +
                               (**(uint **)(in_ECX + 0x100) & 0xfffff) * 4) * 4),
      (*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar1 + 4) * 4) + 5) & 1) == 0 ||
      (*(double *)(iVar1 + 0x20) != _DAT_009fd350)))) {
    return 1;
  }
  puVar2 = (undefined4 *)
           FUN_00947158(**(uint **)(in_ECX + 0x100) & 0xfffff | 0x20400000,
                        *(uint **)(in_ECX + 0x100),0,2,1);
  if ((puVar2 != (undefined4 *)0x0) && (local_8 = FUN_0094ac69(puVar2), local_8 == 0)) {
    *puVar2 = 0;
  }
  return local_8;
}


// ==== FUN_0094ae91 @ 0x0094ae91 ====

int FUN_0094ae91(void)

{
  float fVar1;
  bool bVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  int *piVar7;
  uint *local_14;
  int *local_10;
  uint local_c;
  
  *(undefined4 *)(in_ECX + 0x15c) = 0;
  puVar3 = *(uint **)(in_ECX + 0x100);
  if ((*puVar3 & 0xfff00000) == 0x20400000) {
    uVar6 = *puVar3 & 0xfffff;
    bVar2 = true;
    if (uVar6 == 0) {
LAB_0094aef4:
      puVar3 = (uint *)FUN_00947158(uVar6 | 0x20400000,puVar3,0,2,1);
      if (puVar3 == (uint *)0x0) goto LAB_0094b026;
      local_14 = puVar3;
      fVar1 = DAT_0099d0dc;
    }
    else {
      piVar4 = (int *)puVar3[2];
      piVar7 = piVar4 + uVar6;
      local_c = uVar6;
      do {
        if (*piVar4 != *piVar7) {
          bVar2 = false;
        }
        piVar7 = piVar7 + 1;
        piVar4 = piVar4 + 1;
        local_c = local_c - 1;
      } while (local_c != 0);
      if (bVar2) goto LAB_0094aef4;
      fVar1 = DAT_009b0318;
    }
    piVar7 = (int *)puVar3[2];
    iVar5 = *(int *)(in_ECX + 0x14);
    local_c = *puVar3 & 0xfffff;
    local_10 = piVar7 + local_c;
    if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                           *(int *)(*(int *)(iVar5 + *local_10 * 4) + 4) * 4) + 5) & 1) == 0) {
      if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                             *(int *)(*(int *)(iVar5 + *piVar7 * 4) + 4) * 4) + 5) & 1) == 0)
      goto LAB_0094b026;
      piVar4 = piVar7;
    }
    else {
      piVar4 = local_10;
      local_10 = piVar7;
    }
    uVar6 = 0;
    if (local_c != 0) {
      do {
        if ((float)*(double *)(*(int *)(iVar5 + piVar4[uVar6] * 4) + 0x20) != fVar1)
        goto LAB_0094b026;
        uVar6 = uVar6 + 1;
      } while (uVar6 < local_c);
    }
    if (bVar2) {
      local_10 = *(int **)(*(int *)(in_ECX + 0x100) + 8);
    }
    else {
      local_14 = (uint *)FUN_00947158(**(uint **)(in_ECX + 0x100) & 0xfffff | 0x20400000,
                                      *(uint **)(in_ECX + 0x100),0,2,2);
      if (local_14 == (uint *)0x0) goto LAB_0094b026;
      bVar2 = true;
      if (local_c != 0) {
        piVar4 = (int *)local_14[2];
        piVar7 = piVar4 + local_c;
        do {
          if (*piVar4 != *piVar7) {
            bVar2 = false;
          }
          piVar7 = piVar7 + 1;
          piVar4 = piVar4 + 1;
          local_c = local_c - 1;
        } while (local_c != 0);
        if (!bVar2) goto LAB_0094b026;
      }
    }
    iVar5 = FUN_0094956d(0x60000,0,local_10,0x60000,local_14,0);
    if (iVar5 == 0) {
      *local_14 = 0;
    }
  }
  else {
LAB_0094b026:
    iVar5 = 1;
  }
  return iVar5;
}


// ==== FUN_0094b02e @ 0x0094b02e ====

undefined4 FUN_0094b02e(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int in_ECX;
  int *piVar9;
  uint uVar10;
  undefined1 local_1c [8];
  int local_14;
  uint local_10;
  undefined4 local_8;
  
  uVar10 = **(uint **)(in_ECX + 0x100) & 0xfffff;
  if ((**(uint **)(in_ECX + 0x100) & 0xfff00000) == 0x70300000) {
    local_8 = *(undefined4 *)(in_ECX + 0xfc);
    iVar2 = *(int *)(in_ECX + 0x100);
    FUN_009473b3(uVar10 | 0x20500000,iVar2,local_1c,2);
    if (local_14 == 0) {
LAB_0094b1af:
      uVar5 = 1;
    }
    else {
      local_10 = 0;
      if (uVar10 != 0) {
        piVar9 = *(int **)(local_14 + 0x10);
        piVar6 = (int *)(*(int *)(iVar2 + 8) + uVar10 * 8);
        do {
          if (*piVar6 != *piVar9) goto LAB_0094b1af;
          local_10 = local_10 + 1;
          piVar6 = piVar6 + 1;
          piVar9 = piVar9 + 1;
        } while (local_10 < uVar10);
      }
      iVar3 = *(int *)(iVar2 + 8);
      iVar4 = *(int *)(local_14 + 8);
      iVar1 = uVar10 * 4 + iVar3;
      iVar7 = uVar10 * 4 + iVar4;
      iVar8 = FUN_009450e9(iVar3,iVar1,iVar4,iVar7,local_14,iVar2,local_8);
      if ((((iVar8 == 0) ||
           (iVar8 = FUN_009450e9(iVar1,iVar3,iVar4,iVar7,local_14,iVar2,local_8), iVar8 == 0)) ||
          (iVar8 = FUN_009450e9(iVar3,iVar1,iVar7,iVar4,local_14,iVar2,local_8), iVar8 == 0)) ||
         (((iVar8 = FUN_009450e9(iVar1,iVar3,iVar7,iVar4,local_14,iVar2,local_8), iVar8 == 0 ||
           (iVar8 = FUN_009450e9(iVar4,iVar7,iVar3,iVar1,local_14,iVar2,local_8), iVar8 == 0)) ||
          ((iVar8 = FUN_009450e9(iVar7,iVar4,iVar3,iVar1,local_14,iVar2,local_8), iVar8 == 0 ||
           (iVar8 = FUN_009450e9(iVar4,iVar7,iVar1,iVar3,local_14,iVar2,local_8), iVar8 == 0)))))) {
        uVar5 = 0;
      }
      else {
        uVar5 = FUN_009450e9(iVar7,iVar4,iVar1,iVar3,local_14,iVar2,local_8);
      }
    }
  }
  else {
    uVar5 = 1;
  }
  return uVar5;
}


// ==== FUN_0094b1b7 @ 0x0094b1b7 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0094b1b7(void)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int in_ECX;
  int iVar7;
  int *piVar8;
  uint uVar9;
  undefined1 local_110 [128];
  undefined1 local_90 [128];
  undefined4 local_10;
  uint local_c;
  uint local_8;
  
  uVar9 = 0;
  uVar3 = 0;
  local_10 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar3 * 4) + 0x30) = 0xffffffff;
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar3 * 4) + 0x34) = 0xffffffff;
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 8));
  }
  local_c = *(uint *)(in_ECX + 0xc);
  iVar4 = FUN_009468d3(0xffffffff,1,&local_10,0,0,0,local_c,1,0,0,0);
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar7 = uVar9 * 4;
      piVar8 = (int *)(*(int *)(in_ECX + 0x14) + iVar7);
      iVar5 = *piVar8;
      if ((*(int *)(iVar5 + 0x30) != -1) || (*(int *)(iVar5 + 0x34) != -1)) {
        iVar5 = *piVar8;
        *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar5 + 0x30);
        iVar5 = *(int *)(iVar7 + *(int *)(in_ECX + 0x14));
        *(undefined4 *)(iVar5 + 0x18) = *(undefined4 *)(iVar5 + 0x34);
      }
      *(undefined4 *)(*(int *)(iVar7 + *(int *)(in_ECX + 0x14)) + 0x30) = 0xffffffff;
      *(undefined4 *)(*(int *)(iVar7 + *(int *)(in_ECX + 0x14)) + 0x34) = 0xffffffff;
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint *)(in_ECX + 8));
  }
  uVar3 = 0;
  if (local_c != 0) {
    do {
      iVar5 = uVar3 * 4;
      uVar3 = uVar3 + 1;
      **(undefined4 **)(*(int *)(in_ECX + 0x18) + iVar5) = 0;
    } while (uVar3 < local_c);
  }
  if (-1 < iVar4) {
    *(undefined4 *)(in_ECX + 0xfc) = 0;
    FUN_009457ec(local_110,local_90,0,0);
    local_c = 0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + local_c * 4);
        uVar3 = *puVar2 & 0xfff00000;
        if ((*puVar2 & 0xfffff) == 1) {
          local_10 = 0xffffffff;
          local_8 = 0xffffffff;
          if ((((uVar3 == 0x73000000) || (uVar3 == 0x73200000)) || (uVar3 == 0x73100000)) ||
             (uVar3 == 0x73300000)) {
            iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar2[2] * 4);
            uVar3 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar4 + 4) * 4) + 4);
            if (((uVar3 & 0x200) != 0) && ((uVar3 & 0x2000) == 0)) {
              iVar4 = FUN_009459fa(&DAT_00a1fd04,0x2000,iVar4,&local_10);
              if (iVar4 < 0) {
                return iVar4;
              }
              *(undefined4 *)puVar2[2] = local_10;
            }
          }
          else if (uVar3 == 0x73b00000) {
            iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar2[2] + 4) * 4);
            if ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar4 + 4) * 4) + 5) & 1)
                  != 0) && (*(int *)(iVar4 + 8) == -1)) &&
               (*(double *)(iVar4 + 0x20) == _DAT_0099d098)) {
              local_8 = FUN_00915318(0,0,0,0);
              if (local_8 == 0xffffffff) {
                return -0x7ff8fff2;
              }
              local_10 = *(undefined4 *)(*(int *)(in_ECX + 0x14) + *(int *)puVar2[2] * 4);
              iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + local_8 * 4);
              iVar5 = FUN_00914e44();
              if (iVar5 < 0) {
                return iVar5;
              }
              iVar5 = FUN_00914f00();
              if (iVar5 < 0) {
                return iVar5;
              }
              puVar1 = (uint *)(iVar4 + 0x3c);
              *puVar1 = *puVar1 ^ 0x80000;
              *(undefined4 *)(iVar4 + 0x38) = *(undefined4 *)puVar2[2];
              *(uint *)(puVar2[2] + 4) = local_8;
            }
          }
          else if ((uVar3 == 0x74200000) || (uVar3 == 0x74100000)) {
            iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar2[2] * 4);
            uVar3 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar4 + 4) * 4) + 4);
            if (((uVar3 & 0x200) != 0) && ((uVar3 & 0x40000) == 0)) {
              iVar4 = FUN_009459fa(&DAT_00a1fc44,0x40000,iVar4,&local_8);
              if (iVar4 < 0) {
                return iVar4;
              }
              *(uint *)puVar2[2] = local_8;
              iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + local_8 * 4);
              local_8 = 1;
              if (1 < puVar2[1]) {
                do {
                  iVar5 = *(int *)(puVar2[2] + local_8 * 4);
                  if (iVar5 == -1) {
                    iVar5 = iVar4;
                  }
                  else {
                    iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + iVar5 * 4);
                  }
                  uVar6 = FUN_00915318(*(undefined4 *)(iVar4 + 4),*(undefined4 *)(iVar4 + 0xc),
                                       local_8,*(undefined8 *)(iVar5 + 0x20));
                  uVar3 = local_8 + 1;
                  *(undefined4 *)(puVar2[2] + local_8 * 4) = uVar6;
                  local_8 = uVar3;
                } while (uVar3 < puVar2[1]);
              }
            }
          }
        }
        local_c = local_c + 1;
      } while (local_c < *(uint *)(in_ECX + 0xc));
    }
    iVar4 = FUN_0091c491();
    if (-1 < iVar4) {
      iVar4 = 0;
    }
  }
  return iVar4;
}


// ==== FUN_0094b4db @ 0x0094b4db ====

int FUN_0094b4db(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = FUN_00947a51(1);
  if (-1 < iVar2) {
    piVar1 = (int *)(in_ECX + 0x110);
    *(undefined4 *)(*(int *)(in_ECX + 0x10c) + *piVar1 * 4) = param_1;
    *piVar1 = *piVar1 + 1;
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_0094b50b @ 0x0094b50b ====

int FUN_0094b50b(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_ECX;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *local_8;
  
  local_8 = (int *)0x0;
  FUN_0093cc60(0x53455250);
  iVar1 = FUN_00922bb7();
  if (-1 < iVar1) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0xe0) + 8))(&local_8);
    if (-1 < iVar1) {
      if (iVar1 == 0) {
        uVar6 = 0;
        uVar5 = 1;
        piVar4 = local_8;
        uVar2 = (**(code **)(*local_8 + 0x10))(local_8,1,0);
        uVar2 = (**(code **)(*local_8 + 0xc))(local_8,uVar2);
        iVar1 = FUN_0093ccb5(uVar2,piVar4,uVar5,uVar6);
        if (iVar1 < 0) goto LAB_0094b614;
      }
      uVar3 = FUN_0093cdee();
      if (uVar3 < 0x8001) {
        iVar1 = FUN_00947a51(uVar3);
        if (-1 < iVar1) {
          _memmove((void *)(*(int *)(in_ECX + 0x10c) + 4 + uVar3 * 4),
                   (void *)(*(int *)(in_ECX + 0x10c) + 4),*(int *)(in_ECX + 0x110) * 4 - 4);
          iVar1 = FUN_0093cdfa(*(int *)(in_ECX + 0x10c) + 4,uVar3);
          if (-1 < iVar1) {
            *(int *)(in_ECX + 0x110) = *(int *)(in_ECX + 0x110) + uVar3;
            *(int *)(in_ECX + 0x120) = *(int *)(in_ECX + 0x120) + uVar3;
            *(undefined4 *)(in_ECX + 0x11c) = *(undefined4 *)(in_ECX + 0x110);
            iVar1 = 0;
          }
        }
      }
      else {
        FUN_0091a001();
        iVar1 = -0x7fffbffb;
      }
    }
  }
LAB_0094b614:
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
    local_8 = (int *)0x0;
  }
  FUN_0093cc7d();
  return iVar1;
}


// ==== FUN_0094b633 @ 0x0094b633 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0094b633(void)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  short sVar5;
  uint uVar6;
  char *_Format;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *in_ECX;
  int iVar9;
  byte *pbVar10;
  uint uVar11;
  byte *pbVar12;
  int iVar13;
  byte *pbVar14;
  bool bVar15;
  char *pcVar16;
  undefined4 uVar17;
  undefined4 local_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 local_178;
  undefined1 local_174 [4];
  int local_170;
  int local_16c;
  undefined1 local_168 [4];
  int local_164;
  undefined1 local_160 [4];
  int local_15c;
  undefined1 local_158 [16];
  undefined4 *local_148;
  undefined4 *local_144;
  undefined4 *local_140;
  uint local_13c;
  int *local_138;
  undefined4 *local_134;
  byte *local_130;
  int local_12c;
  byte *local_128;
  uint local_124;
  byte *local_120;
  byte *local_11c;
  byte *local_118;
  undefined4 *local_114;
  uint local_110;
  byte *local_10c;
  char local_108 [254];
  undefined1 local_a;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  local_138 = in_ECX;
  FUN_0093cc60((-(uint)(in_ECX[0x56] != 0) & 0x40cf503) + 0x42415443);
  local_178 = 0x1c;
  puVar7 = &local_178;
  for (iVar9 = 7; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  local_170 = in_ECX[0x32];
  local_164 = in_ECX[0x33];
  local_134 = (undefined4 *)0x0;
  local_114 = (undefined4 *)0x0;
  local_148 = (undefined4 *)0x0;
  local_140 = (undefined4 *)0x0;
  local_144 = (undefined4 *)0x0;
  local_130 = (byte *)0x0;
  iVar9 = FUN_0093ccb5(&local_178,0x1c,1,0);
  piVar3 = local_138;
  if (-1 < iVar9) {
    pbVar14 = (byte *)0x0;
    pbVar10 = (byte *)0x0;
    local_11c = (byte *)0x0;
    local_10c = (byte *)0x0;
    if (local_138[2] != 0) {
      local_118 = (byte *)local_138[5];
      local_120 = (byte *)local_138[2];
      do {
        local_110 = *(uint *)(*(int *)(local_138[4] + *(int *)(*(int *)local_118 + 4) * 4) + 4);
        if (((local_110 & 0x200) != 0) && ((local_110 & 0x100) == 0)) {
          pbVar12 = *(byte **)(*(int *)local_118 + 0xc);
          if ((local_110 & 0x80) == 0) {
            if ((local_110 & 0x2000) == 0) {
              if ((local_110 & 0x40000) == 0) {
                if (pbVar10 <= pbVar12) {
                  pbVar10 = pbVar12 + 1;
                }
              }
              else if (local_10c <= pbVar12) {
                local_10c = pbVar12 + 1;
              }
            }
            else if (local_11c <= pbVar12) {
              local_11c = pbVar12 + 1;
            }
          }
          else if (pbVar14 <= pbVar12) {
            pbVar14 = pbVar12 + 1;
          }
        }
        local_118 = (byte *)((int)local_118 + 4);
        local_120 = local_120 + -1;
      } while (local_120 != (byte *)0x0);
    }
    local_128 = pbVar10 + (int)local_11c;
    local_118 = pbVar14 + (int)pbVar10 + (int)local_11c;
    pbVar14 = local_10c + (int)pbVar14 + (int)pbVar10 + (int)local_11c;
    local_114 = operator_new((int)pbVar14 * 4);
    if ((local_114 != (undefined4 *)0x0) &&
       (local_130 = operator_new((int)pbVar14 * 4), local_130 != (byte *)0x0)) {
      local_110 = 0;
      puVar7 = local_114;
      for (uVar11 = (uint)pbVar14 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
        *(undefined1 *)puVar7 = 0;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      if (piVar3[2] != 0) {
        do {
          iVar9 = *(int *)(piVar3[5] + local_110 * 4);
          if ((((*(int *)(iVar9 + 0x60) != 0) && (*(int *)(iVar9 + 8) == -1)) &&
              (uVar11 = *(uint *)(*(int *)(piVar3[4] + *(int *)(iVar9 + 4) * 4) + 4),
              (uVar11 & 0x200) != 0)) && ((uVar11 & 0x100) == 0)) {
            if ((char)uVar11 < '\0') {
              pbVar10 = local_128;
            }
            else if ((uVar11 & 0x2000) == 0) {
              pbVar10 = local_118;
              if ((uVar11 & 0x40000) == 0) {
                pbVar10 = local_11c;
              }
            }
            else {
              pbVar10 = (byte *)0x0;
            }
            iVar13 = *(int *)(iVar9 + 0xc);
            uVar11 = *(uint *)(iVar9 + 0x70);
            pbVar12 = pbVar10 + iVar13 + 1;
            while (pbVar10 + (iVar13 - (uVar11 >> 2)) < pbVar12) {
              pbVar12 = pbVar12 + -1;
              if (local_114[(int)pbVar12] != 0) break;
              local_114[(int)pbVar12] = iVar9;
            }
          }
          local_110 = local_110 + 1;
        } while (local_110 < (uint)piVar3[2]);
      }
      pbVar12 = (byte *)0x0;
      pbVar10 = (byte *)0x0;
      local_120 = (byte *)0x0;
      if (pbVar14 != (byte *)0x0) {
        do {
          if (local_114[(int)pbVar10] != 0) {
            local_114[(int)local_120] = local_114[(int)pbVar10];
            local_120 = local_120 + 1;
          }
          pbVar10 = pbVar10 + 1;
        } while (pbVar10 < pbVar14);
      }
      iVar9 = 0;
      local_124 = 0;
      if (local_120 != (byte *)0x0) {
        do {
          if (((((iVar9 == 0) || (*(int *)(local_114[(int)pbVar12] + 4) != *(int *)(iVar9 + 4))) ||
               ((*(int *)(local_114[(int)pbVar12] + 0x60) != *(int *)(iVar9 + 0x60) ||
                (*(int *)(local_114[(int)pbVar12] + 0xc) -
                 (*(uint *)(local_114[(int)pbVar12] + 0x70) >> 2) !=
                 *(int *)(iVar9 + 0xc) - (*(uint *)(iVar9 + 0x70) >> 2))))) &&
              (((iVar9 = local_114[(int)pbVar12], iVar9 != 0 &&
                (iVar13 = *(int *)(iVar9 + 0x60), *(int *)(iVar13 + 4) == 6)) &&
               ((iVar2 = *(int *)(iVar13 + 0x14), iVar2 != 0 &&
                (((*(int *)(iVar2 + 4) == 3 && (*(int *)(iVar13 + 0x18) != 0)) &&
                 (*(int *)(*(int *)(iVar13 + 0x18) + 4) == 0xb)))))))) &&
             ((*(int *)(iVar2 + 0x10) == 9 && (*(int *)(iVar2 + 0x18) != 0)))) {
            *(byte **)(local_130 + local_124 * 4) = pbVar12;
            local_124 = local_124 + 1;
          }
          pbVar12 = pbVar12 + 1;
        } while (pbVar12 < local_120);
      }
      local_110 = 0;
      if (local_124 != 0) {
        do {
          local_10c = *(byte **)(local_130 + local_110 * 4);
          local_118 = (byte *)local_114[(int)local_10c];
          local_128 = *(byte **)(*(int *)(*(int *)(local_118 + 0x60) + 0x14) + 0x18);
          uVar11 = 0;
          if (local_110 != 0) {
            do {
              pbVar14 = *(byte **)(*(int *)(*(int *)(local_114[*(int *)(local_130 + uVar11 * 4)] +
                                                    0x60) + 0x14) + 0x18);
              pbVar10 = local_128;
              do {
                bVar1 = *pbVar10;
                bVar15 = bVar1 < *pbVar14;
                if (bVar1 != *pbVar14) {
LAB_0094ba17:
                  iVar9 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
                  goto LAB_0094ba1c;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar10[1];
                bVar15 = bVar1 < pbVar14[1];
                if (bVar1 != pbVar14[1]) goto LAB_0094ba17;
                pbVar10 = pbVar10 + 2;
                pbVar14 = pbVar14 + 2;
              } while (bVar1 != 0);
              iVar9 = 0;
LAB_0094ba1c:
            } while (((-1 < iVar9) &&
                     ((0 < iVar9 ||
                      (*(uint *)(local_114[*(int *)(local_130 + uVar11 * 4)] + 4) <=
                       *(uint *)(local_118 + 4))))) && (uVar11 = uVar11 + 1, uVar11 < local_110));
            if (uVar11 < local_110) {
              uVar6 = local_110;
              do {
                *(undefined4 *)(local_130 + uVar6 * 4) = *(undefined4 *)(local_130 + uVar6 * 4 + -4)
                ;
                uVar6 = uVar6 - 1;
              } while (uVar11 < uVar6);
              *(byte **)(local_130 + uVar11 * 4) = local_10c;
            }
          }
          local_110 = local_110 + 1;
        } while (local_110 < local_124);
      }
      iVar9 = (**(code **)(*local_138 + 0x8c))();
      iVar9 = iVar9 + local_124;
      if (iVar9 != 0) {
        uVar11 = iVar9 * 0x14;
        local_134 = operator_new(uVar11);
        if (local_134 == (undefined4 *)0x0) goto LAB_0094c181;
        puVar7 = local_134;
        for (uVar6 = uVar11 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
        for (iVar13 = 0; iVar13 != 0; iVar13 = iVar13 + -1) {
          *(undefined1 *)puVar7 = 0;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        iVar13 = FUN_0093ccb5(local_134,uVar11,1,local_168);
        if (iVar13 < 0) goto LAB_0094c181;
        local_110 = 0;
        local_16c = iVar9;
        if (local_124 != 0) {
          local_11c = (byte *)(local_134 + 1);
          pbVar14 = local_130;
          do {
            pbVar10 = local_11c;
            iVar9 = *(int *)(local_114[*(int *)pbVar14] + 0x60);
            local_12c = *(int *)(iVar9 + 0x18);
            pcVar16 = *(char **)(*(int *)(iVar9 + 0x14) + 0x18);
            local_13c = *(uint *)(local_138[4] + *(int *)(local_114[*(int *)pbVar14] + 4) * 4);
            local_118 = pbVar14;
            if (local_138[0x56] == 0) {
              uVar17 = 7;
            }
            else {
              uVar11 = *(uint *)(local_13c + 4);
              _Format = &DAT_00a2e0d4;
              if ((uVar11 & 0x2000) == 0) {
                if ((uVar11 & 0x40000) == 0) {
                  if ((char)uVar11 < '\0') {
                    _Format = &DAT_00a2e0bc;
                  }
                }
                else {
                  _Format = &DAT_00a2e0c4;
                }
              }
              else {
                _Format = &DAT_00a2e0cc;
              }
              __snprintf(local_108,0xff,_Format,pcVar16);
              uVar17 = 6;
              pcVar16 = local_108;
              local_a = 0;
            }
            iVar9 = FUN_0093ccb5(pcVar16,0xffffffff,uVar17,pbVar10 + -4);
            if (iVar9 < 0) goto LAB_0094c181;
            pbVar12 = (byte *)(*(int *)pbVar14 + 1);
            iVar9 = 1;
            if (pbVar12 < local_120) {
              local_15c = *(int *)(local_114[*(int *)pbVar14] + 4);
              local_128 = (byte *)(local_114 + *(int *)pbVar14 + 1);
              local_10c = pbVar12;
              do {
                if (((local_15c != *(int *)(*(int *)local_128 + 4)) ||
                    (*(int *)(local_114[*(int *)pbVar14] + 0x60) !=
                     *(int *)(local_114[*(int *)pbVar14 + iVar9] + 0x60))) ||
                   (*(int *)(local_114[*(int *)pbVar14] + 0xc) -
                    (*(uint *)(local_114[*(int *)pbVar14] + 0x70) >> 2) !=
                    *(int *)(local_114[*(int *)pbVar14 + iVar9] + 0xc) -
                    (*(uint *)(local_114[*(int *)pbVar14 + iVar9] + 0x70) >> 2))) break;
                local_128 = local_128 + 4;
                iVar9 = iVar9 + 1;
                local_10c = local_10c + 1;
              } while (local_10c < local_120);
            }
            uVar11 = *(uint *)(local_13c + 4);
            if ((char)uVar11 < '\0') {
              sVar5 = 3;
            }
            else if ((uVar11 & 0x2000) == 0) {
              sVar5 = 2 - (ushort)((uVar11 & 0x40000) != 0);
            }
            else {
              sVar5 = 0;
            }
            *(short *)pbVar10 = sVar5;
            *(short *)(pbVar10 + 2) =
                 *(short *)(local_114[*(int *)pbVar14] + 0xc) -
                 (short)(*(uint *)(local_114[*(int *)pbVar14] + 0x70) >> 2);
            *(short *)(pbVar10 + 4) = (short)iVar9;
            if (((*(int *)(local_12c + 0x20) != 0) &&
                (iVar9 = FUN_00947758(local_158,*(int *)(local_12c + 0x20),1,
                                      *(uint *)(local_114[*(int *)pbVar14] + 0x3c) & 0xe00000,
                                      pbVar10 + 8), iVar9 < 0)) ||
               ((*(int *)(local_12c + 0x30) != 0 &&
                (iVar9 = (**(code **)(*local_138 + 0x94))(local_12c,pbVar10 + -4), iVar9 < 0))))
            goto LAB_0094c181;
            iVar9 = *(int *)(local_12c + 0x34);
            if (iVar9 != 0) {
              sVar5 = *(short *)pbVar10;
              if (sVar5 == 1) {
                local_128 = (byte *)((iVar9 + 3U & 0xfffffffc) << 2);
                puVar7 = operator_new((uint)local_128);
                local_144 = puVar7;
                if (puVar7 == (undefined4 *)0x0) goto LAB_0094c181;
                puVar8 = puVar7;
                for (uVar11 = (uint)local_128 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
                  *puVar8 = 0;
                  puVar8 = puVar8 + 1;
                }
                uVar6 = iVar9 + 3U >> 2;
                for (uVar11 = (uint)local_128 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
                  *(undefined1 *)puVar8 = 0;
                  puVar8 = (undefined4 *)((int)puVar8 + 1);
                }
                if (uVar6 != 0) {
                  puVar8 = puVar7 + 2;
                  do {
                    *puVar8 = 1;
                    puVar8 = puVar8 + 4;
                    uVar6 = uVar6 - 1;
                  } while (uVar6 != 0);
                }
                local_10c = (byte *)0x0;
                iVar9 = local_12c;
                if (*(int *)(local_12c + 0x34) != 0) {
                  do {
                    pbVar14 = local_10c;
                    piVar3 = *(int **)((int)local_10c * 4 + *(int *)(iVar9 + 0x38));
                    if (piVar3 != (int *)0x0) {
                      iVar13 = *piVar3;
                      if (iVar13 == 0) {
                        puVar7[(int)local_10c] = (uint)(piVar3[2] != 0);
                      }
                      else if ((iVar13 == 1) || (iVar13 == 2)) {
                        puVar7[(int)local_10c] = piVar3[2];
                      }
                      else if (iVar13 == 3) {
                        uVar17 = __ftol();
                        puVar7[(int)pbVar14] = uVar17;
                        iVar9 = local_12c;
                      }
                    }
                    local_10c = local_10c + 1;
                  } while (local_10c < *(byte **)(iVar9 + 0x34));
                }
                iVar9 = FUN_0093ccb5(puVar7,local_128,0xb,local_11c + 0xc);
                if (iVar9 < 0) goto LAB_0094c181;
                local_144 = (undefined4 *)0x0;
              }
              else if (sVar5 == 2) {
                local_13c = (iVar9 + 3U & 0xfffffffc) << 2;
                local_148 = operator_new(local_13c);
                if (local_148 == (undefined4 *)0x0) goto LAB_0094c181;
                puVar7 = local_148;
                for (uVar11 = iVar9 + 3U & 0x3ffffffc; uVar11 != 0; uVar11 = uVar11 - 1) {
                  *puVar7 = 0;
                  puVar7 = puVar7 + 1;
                }
                for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                  *(undefined1 *)puVar7 = 0;
                  puVar7 = (undefined4 *)((int)puVar7 + 1);
                }
                uVar11 = 0;
                if (*(int *)(local_12c + 0x34) != 0) {
                  do {
                    piVar3 = *(int **)(uVar11 * 4 + *(int *)(local_12c + 0x38));
                    if (piVar3 != (int *)0x0) {
                      iVar9 = *piVar3;
                      if (iVar9 == 0) {
                        if (piVar3[2] == 0) {
                          fVar4 = 0.0;
                        }
                        else {
                          fVar4 = 1.0;
                        }
                      }
                      else if (iVar9 == 1) {
                        fVar4 = (float)piVar3[2];
                      }
                      else if (iVar9 == 2) {
                        local_15c = piVar3[2];
                        fVar4 = (float)local_15c;
                        if (local_15c < 0) {
                          fVar4 = fVar4 + _DAT_0099d104;
                        }
                      }
                      else {
                        if (iVar9 != 3) goto LAB_0094bee7;
                        fVar4 = (float)*(double *)(piVar3 + 2);
                      }
                      local_148[uVar11] = fVar4;
                    }
LAB_0094bee7:
                    uVar11 = uVar11 + 1;
                  } while (uVar11 < *(uint *)(local_12c + 0x34));
                }
                iVar9 = FUN_0093ccb5(local_148,local_13c,0xb,local_11c + 0xc);
                if (iVar9 < 0) goto LAB_0094c181;
                local_148 = (undefined4 *)0x0;
              }
              else {
                if (sVar5 != 0) goto LAB_0094c011;
                uVar11 = *(uint *)(local_12c + 0x14);
                local_13c = uVar11 << 2;
                local_140 = operator_new(local_13c);
                if (local_140 == (undefined4 *)0x0) goto LAB_0094c181;
                puVar7 = local_140;
                for (uVar11 = uVar11 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
                  *puVar7 = 0;
                  puVar7 = puVar7 + 1;
                }
                for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                  *(undefined1 *)puVar7 = 0;
                  puVar7 = (undefined4 *)((int)puVar7 + 1);
                }
                local_10c = (byte *)0x0;
                if (*(int *)(local_12c + 0x14) != 0) {
                  do {
                    piVar3 = *(int **)((int)local_10c * 4 + *(int *)(local_12c + 0x3c));
                    if (piVar3 != (int *)0x0) {
                      iVar9 = *piVar3;
                      if (((iVar9 == 0) || (iVar9 == 1)) || (iVar9 == 2)) {
                        local_140[(int)local_10c] = (uint)(piVar3[2] != 0);
                      }
                      else if (iVar9 == 3) {
                        local_140[(int)local_10c] = (uint)(*(double *)(piVar3 + 2) != _DAT_0099d098)
                        ;
                      }
                    }
                    local_10c = local_10c + 1;
                  } while (local_10c < *(byte **)(local_12c + 0x14));
                }
                iVar9 = FUN_0093ccb5(local_140,local_13c,0xb,local_11c + 0xc);
                if (iVar9 < 0) goto LAB_0094c181;
                local_140 = (undefined4 *)0x0;
              }
              pbVar10 = local_11c;
              pbVar14 = local_118;
            }
LAB_0094c011:
            local_110 = local_110 + 1;
            pbVar14 = pbVar14 + 4;
            local_11c = pbVar10 + 0x14;
            local_118 = pbVar14;
          } while (local_110 < local_124);
        }
      }
      iVar9 = (**(code **)(*local_138 + 0x90))(local_158,local_134,local_124);
      if (-1 < iVar9) {
        local_184 = 0;
        uStack_180 = 0;
        uStack_17c = 0;
        iVar9 = FUN_008f329d(local_138[0x42],0,&local_184);
        if (((-1 < iVar9) && (iVar9 = FUN_0093ccb5(local_184,0xffffffff,5,local_160), -1 < iVar9))
           && (iVar9 = FUN_0093ccb5(s_Microsoft__R__D3DX9_Shader_Compi_00a2e088,0xffffffff,5,
                                    local_174), -1 < iVar9)) {
          uVar11 = FUN_0093cdee();
          if (uVar11 < 0x8001) {
            iVar9 = FUN_00947a51(uVar11);
            if (-1 < iVar9) {
              _memmove((void *)(local_138[0x43] + 4 + uVar11 * 4),(void *)(local_138[0x43] + 4),
                       local_138[0x44] * 4 - 4);
              iVar9 = FUN_0093cdfa(local_138[0x43] + 4,uVar11);
              if (-1 < iVar9) {
                local_138[0x44] = local_138[0x44] + uVar11;
                local_138[0x48] = local_138[0x48] + uVar11;
                local_138[0x47] = local_138[0x44];
              }
            }
          }
          else {
            FUN_0091a001(local_138,0,0x11c4,s_constant_table_info_exceeds_maxi_00a2e054);
          }
        }
      }
    }
  }
LAB_0094c181:
  _free(local_134);
  return;
}


// ==== FUN_0094c1e0 @ 0x0094c1e0 ====

void FUN_0094c1e0(void)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined4 *puVar7;
  undefined4 local_70;
  undefined1 local_6c [4];
  undefined1 local_68 [4];
  uint local_64;
  undefined1 local_60 [4];
  int *local_5c;
  undefined1 local_58 [4];
  uint local_54;
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  undefined1 local_48 [16];
  uint local_38;
  int local_34;
  int local_30;
  uint local_2c;
  int *local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  uint local_10;
  int *local_c;
  int *local_8;
  
  FUN_0093cc60(0x47554244);
  local_70 = 0x28;
  iVar5 = 0;
  puVar7 = &local_70;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  local_20 = (undefined4 *)0x0;
  local_18 = (undefined4 *)0x0;
  local_24 = (undefined4 *)0x0;
  local_1c = (undefined4 *)0x0;
  local_14 = (undefined4 *)0x0;
  local_8 = (int *)0x0;
  local_10 = FUN_0093ccb5(&local_70,0x28,1,0);
  if ((int)local_10 < 0) goto LAB_0094c829;
  local_5c = *(int **)(in_ECX + 0x128);
  if (local_5c == (int *)0x0) goto LAB_0094c6e0;
  local_20 = operator_new((int)local_5c << 2);
  if (local_20 != (undefined4 *)0x0) {
    puVar7 = local_20;
    for (piVar3 = local_5c; piVar3 != (int *)0x0; piVar3 = (int *)((int)piVar3 + -1)) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    local_18 = operator_new((int)local_5c << 3);
    if (local_18 != (undefined4 *)0x0) {
      local_34 = (int)local_5c << 3;
      puVar7 = local_18;
      for (iVar2 = ((uint)local_5c & 0x1fffffff) << 1; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined1 *)puVar7 = 0;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      local_14 = operator_new((int)local_5c << 4);
      if (local_14 != (undefined4 *)0x0) {
        puVar7 = local_14;
        for (iVar2 = ((uint)local_5c & 0xfffffff) << 2; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
        for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
          *(undefined1 *)puVar7 = 0;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        local_c = (int *)0x0;
        if (local_5c != (int *)0x0) {
          puVar6 = (undefined2 *)((int)local_18 + 2);
          do {
            *puVar6 = 0xffff;
            puVar6[-1] = 0;
            local_2c = iVar5 + 8;
            *(undefined4 *)(puVar6 + 1) = *(undefined4 *)(*(int *)(in_ECX + 0x124) + 4 + iVar5);
            local_28 = (int *)0x4;
            do {
              iVar2 = *(int *)(local_2c + *(int *)(in_ECX + 0x124));
              if (iVar2 != -1) {
                iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + iVar2 * 4);
                *(int **)(iVar2 + 0x74) = local_c;
                if (*(int *)(iVar2 + 0x60) != 0) {
                  local_14[(int)local_8] = *(undefined4 *)(local_2c + *(int *)(in_ECX + 0x124));
                  local_8 = (int *)((int)local_8 + 1);
                }
              }
              local_2c = local_2c + 4;
              local_28 = (int *)((int)local_28 + -1);
            } while (local_28 != (int *)0x0);
            iVar2 = *(int *)(iVar5 + *(int *)(in_ECX + 0x124));
            if (iVar2 != 0) {
              puVar6[-1] = *(undefined2 *)(iVar2 + 0x14);
              iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 0x124) + iVar5) + 0x10);
              if (iVar2 != 0) {
                iVar2 = FUN_0093ccb5(iVar2,0xffffffff,7,&local_30);
                if (iVar2 < 0) goto LAB_0094c829;
                local_2c = 0;
                if (local_64 != 0) {
                  do {
                    if (local_20[local_2c] == local_30) break;
                    local_2c = local_2c + 1;
                  } while (local_2c < local_64);
                }
                if (local_2c == local_64) {
                  local_20[local_64] = local_30;
                  local_64 = local_64 + 1;
                }
                *puVar6 = (short)local_2c;
              }
            }
            local_c = (int *)((int)local_c + 1);
            iVar5 = iVar5 + 0x18;
            puVar6 = puVar6 + 4;
          } while (local_c < local_5c);
        }
        if ((local_64 != 0) &&
           (local_10 = FUN_0093ccb5(local_20,local_64 << 2,1,local_60), (int)local_10 < 0))
        goto LAB_0094c829;
        local_10 = FUN_0093ccb5(local_18,local_34,1,local_58);
        puVar7 = local_14;
        if ((int)local_10 < 0) goto LAB_0094c829;
        if (local_8 != (int *)0x0) {
          FUN_00915b0e(FUN_0093d155,local_14,local_8,in_ECX);
          local_54 = 1;
          piVar3 = (int *)0x1;
          if ((int *)0x1 < local_8) {
            do {
              if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + puVar7[(int)((int)piVar3 + -1)] * 4) +
                          0x60) !=
                  *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + puVar7[(int)piVar3] * 4) + 0x60)) {
                local_54 = local_54 + 1;
              }
              piVar3 = (int *)((int)piVar3 + 1);
            } while (piVar3 < local_8);
          }
          local_24 = operator_new(local_54 * 0x14);
          if (local_24 == (undefined4 *)0x0) goto LAB_0094c809;
          local_38 = local_54 * 0x14;
          puVar7 = local_24;
          for (uVar4 = local_38 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
          }
          for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
            *(undefined1 *)puVar7 = 0;
            puVar7 = (undefined4 *)((int)puVar7 + 1);
          }
          local_c = (int *)0x0;
          local_2c = 0;
          if (local_54 != 0) {
            piVar3 = local_24 + 3;
            do {
              local_28 = local_14 + (int)local_c;
              iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *local_28 * 4) + 0x60);
              local_30 = iVar2;
              if ((((*(int *)(iVar2 + 0x20) != 0) &&
                   (local_10 = FUN_0093ccb5(*(int *)(iVar2 + 0x20),0xffffffff,7,piVar3 + -3),
                   (int)local_10 < 0)) ||
                  ((iVar5 = *(int *)(*(int *)(iVar2 + 0x14) + 0x18), iVar5 != 0 &&
                   (local_10 = FUN_0093ccb5(iVar5,0xffffffff,7,piVar3 + -2), (int)local_10 < 0))))
                 || (((*(int *)(iVar2 + 0x10) == 1 || (*(int *)(iVar2 + 0x10) == 2)) &&
                     (local_10 = FUN_00947758(local_48,*(undefined4 *)
                                                        (*(int *)(iVar2 + 0x18) + 0x20),1,
                                              *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                                *local_28 * 4) + 0x3c) & 0xe00000,
                                              piVar3 + -1), (int)local_10 < 0)))) goto LAB_0094c829;
              local_28 = local_c;
              while (local_c < local_8) {
                iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + local_14[(int)local_c] * 4);
                if (iVar2 != *(int *)(iVar5 + 0x60)) break;
                local_34 = *(int *)(iVar5 + 0x74);
                while (((local_c < local_8 &&
                        (iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + local_14[(int)local_c] * 4),
                        iVar2 == *(int *)(iVar5 + 0x60))) && (local_34 == *(int *)(iVar5 + 0x74))))
                {
                  local_c = (int *)((int)local_c + 1);
                }
                *piVar3 = *piVar3 + 1;
              }
              local_1c = operator_new(*piVar3 * 0xc);
              if (local_1c == (undefined4 *)0x0) goto LAB_0094c809;
              local_10 = *piVar3 * 0xc;
              puVar7 = local_1c;
              for (uVar4 = local_10 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
                *puVar7 = 0;
                puVar7 = puVar7 + 1;
              }
              for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
                *(undefined1 *)puVar7 = 0;
                puVar7 = (undefined4 *)((int)puVar7 + 1);
              }
              *piVar3 = 0;
              local_c = local_28;
              while ((local_c < local_8 &&
                     (iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + local_14[(int)local_c] * 4),
                     local_30 == *(int *)(iVar2 + 0x60)))) {
                local_34 = *(int *)(iVar2 + 0x74);
                local_1c[*piVar3 * 3] = local_34;
                iVar2 = *piVar3;
                local_1c[iVar2 * 3 + 1] = 0xffffffff;
                (local_1c + iVar2 * 3 + 1)[1] = 0xffffffff;
                for (; local_c < local_8; local_c = (int *)((int)local_c + 1)) {
                  local_28 = local_14 + (int)local_c;
                  iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *local_28 * 4);
                  if ((local_30 != *(int *)(iVar2 + 0x60)) || (local_34 != *(int *)(iVar2 + 0x74)))
                  break;
                  iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *local_28 * 4);
                  *(undefined2 *)((int)local_1c + (*(int *)(iVar2 + 0x10) + *piVar3 * 6) * 2 + 4) =
                       *(undefined2 *)(iVar2 + 100);
                }
                *piVar3 = *piVar3 + 1;
              }
              local_10 = FUN_0093ccb5(local_1c,local_10,0xb,piVar3 + 1);
              if ((int)local_10 < 0) goto LAB_0094c829;
              local_1c = (undefined4 *)0x0;
              local_2c = local_2c + 1;
              piVar3 = piVar3 + 5;
            } while (local_2c < local_54);
          }
          local_10 = FUN_0093ccb5(local_24,local_38,1,local_50);
          if ((int)local_10 < 0) goto LAB_0094c829;
        }
LAB_0094c6e0:
        if ((((*(int *)(in_ECX + 0xd0) != 0) &&
             (local_10 = FUN_0093ccb5(*(int *)(in_ECX + 0xd0),0xffffffff,7,local_4c),
             (int)local_10 < 0)) ||
            ((*(int *)(in_ECX + 0x130) != 0 &&
             ((iVar2 = FUN_0093ccb5(*(int *)(in_ECX + 0x130),*(undefined4 *)(in_ECX + 0x134),5,
                                    local_68), iVar2 < 0 ||
              (iVar2 = FUN_0093ccb5(&DAT_0099cf70,1,5,0), iVar2 < 0)))))) ||
           (iVar2 = FUN_0093ccb5(s_Microsoft__R__D3DX9_Shader_Compi_00a2e088,0xffffffff,5,local_6c),
           iVar2 < 0)) goto LAB_0094c829;
        uVar4 = FUN_0093cdee();
        if (uVar4 < 0x8001) {
          local_10 = FUN_00947a51(uVar4);
          if ((int)local_10 < 0) goto LAB_0094c829;
          _memmove((void *)(*(int *)(in_ECX + 0x10c) + 4 + uVar4 * 4),
                   (void *)(*(int *)(in_ECX + 0x10c) + 4),*(int *)(in_ECX + 0x110) * 4 - 4);
          piVar3 = (int *)0x0;
          if (local_5c != (int *)0x0) {
            piVar1 = local_18 + 1;
            do {
              *piVar1 = *piVar1 + (*(int *)(in_ECX + 0x120) + uVar4) * 4;
              piVar3 = (int *)((int)piVar3 + 1);
              piVar1 = piVar1 + 2;
            } while (piVar3 < local_5c);
          }
          local_10 = FUN_0093cdfa(*(int *)(in_ECX + 0x10c) + 4,uVar4);
          if ((int)local_10 < 0) goto LAB_0094c829;
          *(int *)(in_ECX + 0x110) = *(int *)(in_ECX + 0x110) + uVar4;
          *(int *)(in_ECX + 0x120) = *(int *)(in_ECX + 0x120) + uVar4;
          *(undefined4 *)(in_ECX + 0x11c) = *(undefined4 *)(in_ECX + 0x110);
        }
        else {
          FUN_0091a096();
        }
        local_10 = 0;
        goto LAB_0094c829;
      }
    }
  }
LAB_0094c809:
  local_10 = -0x7ff8fff2;
LAB_0094c829:
  _free(local_20);
  return;
}


// ==== FUN_0094c864 @ 0x0094c864 ====

int FUN_0094c864(int param_1)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  int local_10 [3];
  
  local_10[0] = *(int *)(in_ECX + 0xf4);
  local_10[1] = *(undefined4 *)(in_ECX + 0xf0);
  local_10[2] = *(undefined4 *)(in_ECX + 0xf8);
  uVar2 = 0;
  iVar1 = param_1;
  while ((local_10[uVar2] == 0 ||
         (iVar1 = FUN_00948a71(local_10[uVar2],param_1), *(int *)(iVar1 + 0x10) == -1))) {
    uVar2 = uVar2 + 1;
    if (2 < uVar2) {
      return iVar1;
    }
  }
  return iVar1;
}


// ==== FUN_0094c8b3 @ 0x0094c8b3 ====

void FUN_0094c8b3(byte param_1)

{
  void *in_ECX;
  
  FUN_00948b75();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0094c8d4 @ 0x0094c8d4 ====

void FUN_0094c8d4(uint *param_1)

{
  int iVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  int *piVar3;
  void *pvVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  int *in_ECX;
  int *piVar9;
  uint uVar10;
  undefined4 *puVar11;
  bool bVar12;
  undefined1 local_4c [12];
  void *local_40;
  int *local_3c;
  undefined4 *local_38;
  undefined4 *local_34;
  int *local_30;
  undefined4 *local_2c;
  uint local_28;
  undefined4 *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  undefined4 *local_c;
  uint local_8;
  
  in_ECX[0x41] = 0;
  local_14 = (int *)0x0;
  local_10 = (int *)0x0;
  local_3c = (int *)0x0;
  local_28 = 0;
  local_38 = (undefined4 *)0x0;
  local_24 = (undefined4 *)0x0;
  local_1c = (int *)0x0;
  local_18 = (int *)0x0;
  local_30 = (int *)0x0;
  local_40 = (void *)0x0;
  local_20 = (int *)0x0;
  local_2c = (undefined4 *)0x0;
  local_34 = (undefined4 *)0x0;
  iVar1 = FUN_00928307();
  if (-1 < iVar1) {
    iVar1 = FUN_009152bf(&DAT_00a1fc44,0x40311,0xffffffff,4);
    in_ECX[0x61] = iVar1;
    if ((iVar1 != -1) && (iVar1 = (**(code **)(*in_ECX + 0xa0))(), iVar1 == 0)) {
      in_ECX[0x43] = 0;
      in_ECX[0x44] = 0;
      in_ECX[0x45] = 0;
      in_ECX[0x47] = 0;
      in_ECX[0x48] = 0;
      if ((int *)in_ECX[0x6c] != (int *)0x0) {
        (**(code **)(*(int *)in_ECX[0x6c] + 8))();
        in_ECX[0x6c] = 0;
      }
      if (((*(byte *)(in_ECX + 0x33) & 2) == 0) &&
         (((hModule = GetModuleHandleA(s_d3d9_dll_009fc98c), hModule != (HMODULE)0x0 ||
           (hModule = LoadLibraryA(s_d3d9_dll_009fc98c), hModule != (HMODULE)0x0)) &&
          (pFVar2 = GetProcAddress(hModule,s_Direct3DShaderValidatorCreate9_00a28514),
          pFVar2 != (FARPROC)0x0)))) {
        piVar3 = (int *)(*pFVar2)();
        in_ECX[0x6c] = (int)piVar3;
        if ((piVar3 != (int *)0x0) &&
           (iVar1 = (**(code **)(*piVar3 + 0xc))(piVar3,FUN_0094869f), iVar1 < 0))
        goto LAB_0094d3e4;
      }
      if ((*(byte *)(in_ECX + 0x33) & 1) != 0) {
        pvVar4 = operator_new(in_ECX[3] * 0x30);
        in_ECX[0x49] = (int)pvVar4;
        if (pvVar4 == (void *)0x0) goto LAB_0094d3e4;
        in_ECX[0x4a] = 0;
        in_ECX[0x4b] = in_ECX[3] << 1;
      }
      in_ECX[0x4e] = -1;
      uVar5 = 0;
      in_ECX[0x53] = 0;
      if (in_ECX[2] != 0) {
        do {
          iVar1 = uVar5 * 4;
          uVar5 = uVar5 + 1;
          *(undefined4 *)(*(int *)(in_ECX[5] + iVar1) + 0x30) = 0;
        } while (uVar5 < (uint)in_ECX[2]);
      }
      local_8 = 0;
      local_c = (undefined4 *)0x0;
      if (in_ECX[2] != 0) {
        do {
          iVar1 = *(int *)(in_ECX[5] + (int)local_c * 4);
          iVar7 = *(int *)(in_ECX[4] + *(int *)(iVar1 + 4) * 4);
          uVar5 = *(uint *)(iVar7 + 4);
          if ((((uVar5 & 0x10) != 0) && ((uVar5 & 0x200) == 0)) || ((uVar5 & 0x20) != 0)) {
            (**(code **)(*in_ECX + 4))(iVar1);
          }
          if ((*(byte *)(iVar7 + 4) & 0x80) != 0) {
            local_8 = local_8 + 1;
          }
          local_c = (undefined4 *)((int)local_c + 1);
        } while (local_c < (undefined4 *)in_ECX[2]);
      }
      if ((uint)in_ECX[0x13] < local_8) {
        iVar1 = FUN_008f329d(in_ECX[0x32],0,local_4c);
        if (-1 < iVar1) {
          if (in_ECX[0x13] == 0) {
            FUN_0091a001();
          }
          else {
            FUN_0091a001();
          }
        }
      }
      else if ((((in_ECX[0x32] & 0xffff0000U) != 0xfffe0000) ||
               (iVar1 = FUN_0093dc46(in_ECX[0x20],in_ECX[10],0x10,0x204), -1 < iVar1)) &&
              (((in_ECX[0x32] & 0xffff0000U) != 0xffff0000 ||
               (iVar1 = FUN_0093dc46(0xffffffff,in_ECX[0x13],0x80,0), -1 < iVar1)))) {
        if (in_ECX[2] != 0) {
          local_1c = (int *)in_ECX[2];
          piVar3 = (int *)in_ECX[5];
          do {
            iVar1 = *piVar3;
            iVar7 = *(int *)(iVar1 + 4);
            if ((in_ECX[0x22] == iVar7) &&
               (piVar9 = (int *)(*(int *)(iVar1 + 0xc) + 1), local_3c < piVar9)) {
              local_3c = piVar9;
            }
            else if ((in_ECX[0x20] == iVar7) &&
                    (piVar9 = (int *)(*(int *)(iVar1 + 0xc) + 1), local_14 < piVar9)) {
              local_14 = piVar9;
            }
            else if ((in_ECX[0x21] == iVar7) &&
                    (piVar9 = (int *)(*(int *)(iVar1 + 0xc) + 1), local_10 < piVar9)) {
              local_10 = piVar9;
            }
            else if (((*(byte *)(*(int *)(in_ECX[4] + iVar7 * 4) + 4) & 0x80) != 0) &&
                    (uVar5 = *(int *)(iVar1 + 0xc) + 1, local_28 < uVar5)) {
              local_28 = uVar5;
            }
            piVar3 = piVar3 + 1;
            local_1c = (int *)((int)local_1c + -1);
          } while (local_1c != (int *)0x0);
        }
        local_8 = (int)local_14 << 2;
        local_1c = operator_new(local_8);
        if (local_1c != (int *)0x0) {
          piVar3 = (int *)((int)local_10 << 2);
          local_3c = piVar3;
          local_18 = operator_new((uint)piVar3);
          if (local_18 != (int *)0x0) {
            local_c = (undefined4 *)(local_28 << 2);
            local_30 = operator_new((uint)local_c);
            if (((local_30 != (int *)0x0) &&
                (local_40 = operator_new(local_8), local_40 != (void *)0x0)) &&
               (local_20 = operator_new((uint)piVar3), local_20 != (int *)0x0)) {
              piVar3 = local_1c;
              for (uVar5 = local_8 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                *piVar3 = 0;
                piVar3 = piVar3 + 1;
              }
              for (uVar5 = local_8 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                *(undefined1 *)piVar3 = 0;
                piVar3 = (int *)((int)piVar3 + 1);
              }
              piVar3 = local_18;
              for (uVar5 = (uint)local_3c >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                *piVar3 = 0;
                piVar3 = piVar3 + 1;
              }
              for (uVar5 = (uint)local_3c & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                *(undefined1 *)piVar3 = 0;
                piVar3 = (int *)((int)piVar3 + 1);
              }
              piVar3 = local_30;
              for (uVar5 = (uint)local_c >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                *piVar3 = 0;
                piVar3 = piVar3 + 1;
              }
              for (uVar5 = (uint)local_c & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                *(undefined1 *)piVar3 = 0;
                piVar3 = (int *)((int)piVar3 + 1);
              }
              uVar5 = 0;
              if (in_ECX[2] != 0) {
                do {
                  iVar1 = *(int *)(in_ECX[5] + uVar5 * 4);
                  iVar7 = *(int *)(iVar1 + 4);
                  if (in_ECX[0x21] == iVar7) {
                    if (*(int *)(iVar1 + 0x6c) == -1) goto LAB_0094d487;
                    piVar3 = local_18;
LAB_0094ccd3:
                    piVar3[*(int *)(iVar1 + 0xc)] = iVar1;
                  }
                  else {
                    if (in_ECX[0x20] == iVar7) {
                      if (*(int *)(iVar1 + 0x6c) != -1) {
                        piVar3 = local_1c;
                        goto LAB_0094ccd3;
                      }
                      goto LAB_0094d487;
                    }
                    if ((*(byte *)(*(int *)(in_ECX[4] + iVar7 * 4) + 4) & 0x80) != 0) {
                      piVar3 = local_30;
                      goto LAB_0094ccd3;
                    }
                  }
                  uVar5 = uVar5 + 1;
                } while (uVar5 < (uint)in_ECX[2]);
              }
              local_c = (undefined4 *)0x0;
              if (in_ECX[2] != 0) {
                do {
                  iVar1 = *(int *)(in_ECX[5] + (int)local_c * 4);
                  if ((in_ECX[0x20] == *(int *)(iVar1 + 4)) &&
                     (piVar3 = (int *)0x0, local_14 != (int *)0x0)) {
                    do {
                      if ((local_1c[(int)piVar3] != 0) &&
                         (*(int *)(iVar1 + 0x6c) == *(int *)(local_1c[(int)piVar3] + 0x6c))) {
                        *(int **)(iVar1 + 0xc) = piVar3;
                      }
                      piVar3 = (int *)((int)piVar3 + 1);
                    } while (piVar3 < local_14);
                  }
                  local_c = (undefined4 *)((int)local_c + 1);
                } while (local_c < (undefined4 *)in_ECX[2]);
              }
              piVar3 = local_1c;
              for (uVar5 = local_8 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                *piVar3 = 0;
                piVar3 = piVar3 + 1;
              }
              uVar10 = 0;
              for (uVar5 = local_8 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                *(undefined1 *)piVar3 = 0;
                piVar3 = (int *)((int)piVar3 + 1);
              }
              if (in_ECX[2] != 0) {
                do {
                  iVar1 = *(int *)(in_ECX[5] + uVar10 * 4);
                  uVar5 = *(uint *)(*(int *)(in_ECX[4] + *(int *)(iVar1 + 4) * 4) + 4);
                  if (((uVar5 & 0x10) != 0) && ((uVar5 & 0x204) == 0)) {
                    local_1c[*(int *)(iVar1 + 0xc)] = iVar1;
                  }
                  uVar10 = uVar10 + 1;
                } while (uVar10 < (uint)in_ECX[2]);
              }
              piVar3 = (int *)0x0;
              local_3c = (int *)0x0;
              if (local_14 != (int *)0x0) {
                do {
                  if (local_1c[(int)piVar3] != 0) {
                    local_3c = (int *)((int)local_3c + 1);
                  }
                  piVar3 = (int *)((int)piVar3 + 1);
                } while (piVar3 < local_14);
              }
              iVar1 = FUN_009492d3();
              if (((-1 < iVar1) && (iVar1 = (**(code **)(*in_ECX + 0x2c))(), -1 < iVar1)) &&
                 ((((*(byte *)(in_ECX + 0x33) & 4) != 0 &&
                   ((*(byte *)((int)in_ECX + 0x6e) & 0x20) == 0)) ||
                  ((iVar1 = FUN_0093e2c8(), -1 < iVar1 &&
                   (iVar1 = (**(code **)(*in_ECX + 0x28))(), -1 < iVar1)))))) {
                if (in_ECX[99] != 0) {
                  local_c = (undefined4 *)FUN_009152bf(&DAT_00a1fc7c,0x351,0xffffffff,4);
                  if (local_c == (undefined4 *)0xffffffff) goto LAB_0094d3e4;
                  uVar5 = 0;
                  piVar3 = in_ECX + 100;
                  do {
                    iVar1 = FUN_00915318(local_c,uVar5 >> 2,uVar5 & 3,(&DAT_00a2e188)[uVar5]);
                    *piVar3 = iVar1;
                    if (iVar1 == -1) goto LAB_0094d3e4;
                    uVar5 = uVar5 + 1;
                    piVar3 = piVar3 + 1;
                  } while (uVar5 < 8);
                }
                iVar1 = FUN_0093dc46(in_ECX[0x1f],in_ECX[0xe],0x200,0x42080);
                if (((-1 < iVar1) &&
                    (iVar1 = FUN_0093dc46(in_ECX[0x27],in_ECX[0x18],0x2200,0x80), -1 < iVar1)) &&
                   (iVar1 = FUN_0093dc46(in_ECX[0x2c],in_ECX[0x10],0x40200,0x80), -1 < iVar1)) {
                  uVar5 = 0;
                  in_ECX[0x41] = 0;
                  if (in_ECX[3] == 0) {
                    iVar1 = 0;
                  }
                  else {
                    iVar1 = *(int *)in_ECX[6];
                  }
                  in_ECX[0x40] = iVar1;
                  in_ECX[0x3f] = 0;
                  iVar1 = (**(code **)(*in_ECX + 0x38))();
                  if (-1 < iVar1) {
                    local_8 = 0;
                    if (in_ECX[2] != 0) {
                      local_2c = (undefined4 *)in_ECX[2];
                      piVar3 = (int *)in_ECX[5];
                      do {
                        uVar10 = *(uint *)(*(int *)(in_ECX[4] + *(int *)(*piVar3 + 4) * 4) + 4);
                        if ((((uVar10 & 0x100) != 0) && (*(int *)(*piVar3 + 8) == -1)) &&
                           (((uVar10 & 0x800) == 0 || (in_ECX[0x56] != 0)))) {
                          uVar5 = uVar5 + 1;
                        }
                        piVar3 = piVar3 + 1;
                        local_2c = (undefined4 *)((int)local_2c + -1);
                      } while (local_2c != (undefined4 *)0x0);
                    }
                    local_2c = operator_new(uVar5 << 4);
                    if ((local_2c != (undefined4 *)0x0) &&
                       (local_38 = operator_new(uVar5 << 2), local_38 != (undefined4 *)0x0)) {
                      puVar11 = local_2c;
                      for (iVar1 = (uVar5 & 0xfffffff) << 2; iVar1 != 0; iVar1 = iVar1 + -1) {
                        *puVar11 = 0;
                        puVar11 = puVar11 + 1;
                      }
                      for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
                        *(undefined1 *)puVar11 = 0;
                        puVar11 = (undefined4 *)((int)puVar11 + 1);
                      }
                      puVar11 = local_38;
                      for (uVar5 = uVar5 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
                        *puVar11 = 0;
                        puVar11 = puVar11 + 1;
                      }
                      for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
                        *(undefined1 *)puVar11 = 0;
                        puVar11 = (undefined4 *)((int)puVar11 + 1);
                      }
                      uVar5 = 0;
                      if (in_ECX[2] != 0) {
                        do {
                          iVar1 = *(int *)(in_ECX[5] + uVar5 * 4);
                          uVar10 = *(uint *)(*(int *)(in_ECX[4] + *(int *)(iVar1 + 4) * 4) + 4);
                          if ((((((uVar10 & 0x100) != 0) && (*(int *)(iVar1 + 8) == -1)) &&
                               (*(int *)(iVar1 + 0x38) == -1)) && ((uVar10 & 0x40000) == 0)) &&
                             (((uVar10 & 0x800) == 0 || (in_ECX[0x56] != 0)))) {
                            uVar10 = 0;
                            if (local_8 != 0) {
                              do {
                                if (local_38[uVar10] == *(int *)(iVar1 + 0xc)) break;
                                uVar10 = uVar10 + 1;
                              } while (uVar10 < local_8);
                            }
                            if (uVar10 == local_8) {
                              local_8 = local_8 + 1;
                              local_38[uVar10] = *(undefined4 *)(iVar1 + 0xc);
                            }
                            local_2c[*(int *)(iVar1 + 0x10) + uVar10 * 4] =
                                 (float)*(double *)(iVar1 + 0x20);
                          }
                          uVar5 = uVar5 + 1;
                        } while (uVar5 < (uint)in_ECX[2]);
                      }
                      uVar5 = 0;
                      if (local_8 != 0) {
                        local_c = local_2c;
                        do {
                          iVar1 = (**(code **)(*in_ECX + 0x3c))(local_38[uVar5]);
                          if (iVar1 < 0) goto LAB_0094d3e4;
                          local_c = local_c + 4;
                          uVar5 = uVar5 + 1;
                        } while (uVar5 < local_8);
                      }
                      local_34 = (undefined4 *)0x0;
                      local_8 = 0;
                      if (in_ECX[2] != 0) {
                        piVar3 = (int *)in_ECX[5];
                        iVar1 = in_ECX[2];
                        do {
                          if (((*(byte *)(*(int *)(in_ECX[4] + *(int *)(*piVar3 + 4) * 4) + 5) & 1)
                               != 0) && (*(int *)(*piVar3 + 8) == -1)) {
                            local_34 = (undefined4 *)((int)local_34 + 1);
                          }
                          piVar3 = piVar3 + 1;
                          iVar1 = iVar1 + -1;
                        } while (iVar1 != 0);
                      }
                      puVar11 = local_34;
                      local_34 = operator_new((int)local_34 << 4);
                      if ((local_34 != (undefined4 *)0x0) &&
                         (local_24 = operator_new((int)puVar11 << 2), local_24 != (undefined4 *)0x0)
                         ) {
                        local_c = (undefined4 *)0x0;
                        puVar8 = local_34;
                        for (iVar1 = ((uint)puVar11 & 0xfffffff) << 2; iVar1 != 0;
                            iVar1 = iVar1 + -1) {
                          *puVar8 = 0;
                          puVar8 = puVar8 + 1;
                        }
                        for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
                          *(undefined1 *)puVar8 = 0;
                          puVar8 = (undefined4 *)((int)puVar8 + 1);
                        }
                        uVar5 = (uint)puVar11 & 0x3fffffff;
                        puVar11 = local_24;
                        for (; uVar5 != 0; uVar5 = uVar5 - 1) {
                          *puVar11 = 0;
                          puVar11 = puVar11 + 1;
                        }
                        for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
                          *(undefined1 *)puVar11 = 0;
                          puVar11 = (undefined4 *)((int)puVar11 + 1);
                        }
                        if (in_ECX[2] != 0) {
                          do {
                            iVar1 = *(int *)(in_ECX[5] + (int)local_c * 4);
                            uVar5 = *(uint *)(*(int *)(in_ECX[4] + *(int *)(iVar1 + 4) * 4) + 4);
                            if (((((uVar5 & 0x100) != 0) && (*(int *)(iVar1 + 8) == -1)) &&
                                (*(int *)(iVar1 + 0x38) == -1)) && ((uVar5 & 0x40000) != 0)) {
                              uVar5 = 0;
                              bVar12 = local_8 == 0;
                              if (local_8 != 0) {
                                do {
                                  if (local_24[uVar5] == *(int *)(iVar1 + 0xc)) break;
                                  uVar5 = uVar5 + 1;
                                } while (uVar5 < local_8);
                                bVar12 = uVar5 == local_8;
                              }
                              if (bVar12) {
                                local_8 = local_8 + 1;
                                local_24[uVar5] = *(undefined4 *)(iVar1 + 0xc);
                              }
                              uVar6 = __ftol();
                              local_34[*(int *)(iVar1 + 0x10) + uVar5 * 4] = uVar6;
                            }
                            local_c = (undefined4 *)((int)local_c + 1);
                          } while (local_c < (undefined4 *)in_ECX[2]);
                        }
                        uVar5 = 0;
                        if (local_8 != 0) {
                          local_c = local_34;
                          do {
                            iVar1 = (**(code **)(*in_ECX + 0x40))(local_24[uVar5]);
                            if (iVar1 < 0) goto LAB_0094d3e4;
                            local_c = local_c + 4;
                            uVar5 = uVar5 + 1;
                          } while (uVar5 < local_8);
                        }
                        if ((int *)in_ECX[0x11] < local_3c) {
LAB_0094d487:
                          FUN_0091a001();
                        }
                        else {
                          local_c = (undefined4 *)0x0;
                          if (local_14 != (int *)0x0) {
                            local_3c = local_14;
                            piVar3 = local_1c;
                            do {
                              if ((*piVar3 != 0) &&
                                 (iVar1 = (**(code **)(*in_ECX + 0x44))(*piVar3), iVar1 < 0)) {
                                local_c = (undefined4 *)0x1;
                              }
                              piVar3 = piVar3 + 1;
                              local_3c = (int *)((int)local_3c - 1);
                            } while (local_3c != (int *)0x0);
                          }
                          iVar1 = (**(code **)(*in_ECX + 0x4c))();
                          uVar5 = 0;
                          if (-1 < iVar1) {
                            if (local_28 != 0) {
                              do {
                                if ((local_30[uVar5] != 0) &&
                                   (iVar1 = (**(code **)(*in_ECX + 0x48))(), iVar1 < 0)) {
                                  local_c = (undefined4 *)0x1;
                                }
                                uVar5 = uVar5 + 1;
                              } while (uVar5 < local_28);
                            }
                            if ((*(byte *)(in_ECX + 0x1c) & 0x80) == 0) {
                              if (local_10 != (int *)0x0) {
                                iVar1 = (int)local_20 - (int)local_18;
                                local_3c = local_10;
                                piVar3 = local_18;
                                do {
                                  if ((*piVar3 != 0) &&
                                     (iVar7 = (**(code **)(*in_ECX + 0x6c))
                                                        (*piVar3,(undefined1 *)((int)piVar3 + iVar1)
                                                         ,0), iVar7 < 0)) {
                                    local_c = (undefined4 *)0x1;
                                  }
                                  piVar3 = piVar3 + 1;
                                  local_3c = (int *)((int)local_3c - 1);
                                } while (local_3c != (int *)0x0);
                              }
                            }
                            else if (local_10 != (int *)0x0) {
                              local_3c = local_10;
                              piVar3 = local_18;
                              do {
                                if ((*piVar3 != 0) &&
                                   (iVar1 = (**(code **)(*in_ECX + 0x44))(*piVar3), iVar1 < 0)) {
                                  local_c = (undefined4 *)0x1;
                                }
                                piVar3 = piVar3 + 1;
                                local_3c = (int *)((int)local_3c - 1);
                              } while (local_3c != (int *)0x0);
                              local_3c = (int *)0x0;
                            }
                            iVar1 = 0;
                            if (local_c == (undefined4 *)0x0) {
                              piVar3 = (int *)0x0;
                              if (local_10 != (int *)0x0) {
                                do {
                                  if ((*(int *)(iVar1 + (int)local_18) != 0) &&
                                     (local_3c = (int *)0x0, iVar1 != 0)) {
                                    piVar9 = local_20;
                                    do {
                                      if ((*(int *)(((int)local_18 - (int)local_20) + (int)piVar9)
                                           != 0) && (*(int *)(iVar1 + (int)local_20) == *piVar9))
                                      goto LAB_0094d487;
                                      local_3c = (int *)((int)local_3c + 1);
                                      piVar9 = piVar9 + 1;
                                    } while (local_3c < piVar3);
                                  }
                                  piVar3 = (int *)((int)piVar3 + 1);
                                  iVar1 = iVar1 + 4;
                                } while (piVar3 < local_10);
                              }
                              if (((((*(byte *)((int)in_ECX + 0x6e) & 0x40) != 0) ||
                                   (iVar1 = FUN_0093e2c8(), -1 < iVar1)) &&
                                  (iVar1 = (**(code **)(*in_ECX + 0x24))(), -1 < iVar1)) &&
                                 (((((in_ECX[0x38] == 0 || (iVar1 = FUN_0094b50b(), -1 < iVar1)) &&
                                    ((iVar1 = FUN_0094b633(), -1 < iVar1 &&
                                     (((*(byte *)(in_ECX + 0x33) & 1) == 0 ||
                                      (iVar1 = FUN_0094c1e0(), -1 < iVar1)))))) &&
                                   (iVar1 = FUN_0094b4db(), -1 < iVar1)) &&
                                  ((iVar1 = FUN_00948616(), -1 < iVar1 &&
                                   (((((int *)in_ECX[0x6c] == (int *)0x0 || (in_ECX[0x35] != 0)) ||
                                     (iVar1 = (**(code **)(*(int *)in_ECX[0x6c] + 0x14))(),
                                     -1 < iVar1)) &&
                                    ((param_1 != (uint *)0x0 &&
                                     (iVar1 = FUN_008eb37d(in_ECX[0x44] << 2,&local_3c), -1 < iVar1)
                                     ))))))))) {
                                puVar11 = (undefined4 *)in_ECX[0x43];
                                local_28 = in_ECX[0x44] << 2;
                                puVar8 = (undefined4 *)(**(code **)(*local_3c + 0xc))();
                                for (uVar5 = local_28 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                                  *puVar8 = *puVar11;
                                  puVar11 = puVar11 + 1;
                                  puVar8 = puVar8 + 1;
                                }
                                for (uVar5 = local_28 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                                  *(undefined1 *)puVar8 = *(undefined1 *)puVar11;
                                  puVar11 = (undefined4 *)((int)puVar11 + 1);
                                  puVar8 = (undefined4 *)((int)puVar8 + 1);
                                }
                                *param_1 = (uint)local_3c;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0094d3e4:
  _free(local_1c);
  return;
}


// ==== FUN_0094d495 @ 0x0094d495 ====

undefined4 FUN_0094d495(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 extraout_EAX;
  int in_ECX;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (((*(byte *)(in_ECX + 0xcc) & 1) != 0) && (*(int *)(in_ECX + 0x124) != 0)) {
    if (*(uint *)(in_ECX + 300) <= *(uint *)(in_ECX + 0x128)) {
      puVar1 = operator_new(*(uint *)(in_ECX + 300) * 0x30);
      if (puVar1 == (undefined4 *)0x0) {
        return 0x8007000e;
      }
      puVar4 = *(undefined4 **)(in_ECX + 0x124);
      for (uVar2 = (uint)(*(int *)(in_ECX + 0x128) * 0x18) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar1 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar1 = puVar1 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar1 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar1 = (undefined4 *)((int)puVar1 + 1);
      }
      _free(*(void **)(in_ECX + 0x124));
      return extraout_EAX;
    }
    *(undefined4 *)(*(int *)(in_ECX + 0x124) + *(int *)(in_ECX + 0x128) * 0x18) =
         *(undefined4 *)(in_ECX + 0x104);
    *(int *)(*(int *)(in_ECX + 0x124) + 4 + *(int *)(in_ECX + 0x128) * 0x18) =
         *(int *)(in_ECX + 0x110) << 2;
    uVar2 = 0;
    do {
      *(undefined4 *)(*(int *)(in_ECX + 0x124) + 8 + (uVar2 + *(int *)(in_ECX + 0x128) * 6) * 4) =
           0xffffffff;
      uVar2 = uVar2 + 1;
    } while (uVar2 < 4);
    *(int *)(in_ECX + 0x128) = *(int *)(in_ECX + 0x128) + 1;
  }
  *(undefined4 *)(in_ECX + 0x118) = *(undefined4 *)(in_ECX + 0x110);
  FUN_0094b4db(param_1);
  return 0;
}


// ==== FUN_0094d59b @ 0x0094d59b ====

int FUN_0094d59b(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0094b4db(param_1);
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_0094d5b2 @ 0x0094d5b2 ====

int FUN_0094d5b2(uint param_1,uint param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = FUN_0094d59b(param_1 | param_2);
  if (-1 < iVar2) {
    if (param_3 != 0) {
      iVar2 = FUN_0094d59b(param_3);
      if (iVar2 < 0) {
        return iVar2;
      }
      pbVar1 = (byte *)(*(int *)(in_ECX + 0x10c) + *(int *)(in_ECX + 0x118) * 4 + 3);
      *pbVar1 = *pbVar1 | 0x10;
    }
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_0094d5f8 @ 0x0094d5f8 ====

int FUN_0094d5f8(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  
  iVar2 = FUN_0094d59b(param_1 | param_2);
  if (-1 < iVar2) {
    if (((param_1 | param_2) & 0x2000) != 0) {
      iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + param_3 * 4);
      iVar1 = *(int *)(iVar2 + 0x10);
      uVar3 = *(uint *)(iVar2 + 0xc) & 0x7ff;
      uVar4 = uVar3 | 0xb0000000;
      if (iVar1 != 0) {
        if (iVar1 == 1) {
          uVar4 = uVar3 | 0xb0550000;
        }
        else if (iVar1 == 2) {
          uVar4 = uVar3 | 0xb0aa0000;
        }
        else if (iVar1 == 3) {
          uVar4 = uVar3 | 0xb0ff0000;
        }
      }
      FUN_0094d59b(uVar4);
    }
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_0094d663 @ 0x0094d663 ====

int FUN_0094d663(int param_1,int *param_2,undefined4 param_3,int *param_4,int *param_5,int *param_6,
                undefined4 param_7,uint param_8,uint param_9,uint param_10,int param_11)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar4 = param_1;
  uVar2 = (**(code **)(*in_ECX + 0x5c))(param_1);
  iVar3 = FUN_0094d495(uVar2);
  piVar1 = param_2;
  if (iVar3 < 0) {
    return iVar3;
  }
  iVar3 = (**(code **)(*in_ECX + 0x6c))
                    (*(undefined4 *)(in_ECX[5] + *param_2 * 4),&local_8,&local_18,&local_14);
  if (iVar3 < 0) {
    return iVar3;
  }
  iVar3 = (**(code **)(*in_ECX + 0x70))(piVar1,param_3,&param_1,local_14);
  if (iVar3 < 0) {
    return iVar3;
  }
  iVar3 = (**(code **)(*in_ECX + 100))(-(uint)(param_11 != 0) & 0x400000 | local_8,param_1,local_18)
  ;
  piVar1 = param_4;
  if (iVar3 < 0) {
    return iVar3;
  }
  if (iVar4 == 8) {
    param_1 = 0x70000;
    goto LAB_0094d739;
  }
  if (iVar4 != 9) {
    if (iVar4 == 0x5a) {
      param_1 = 0x30000;
      goto LAB_0094d739;
    }
    if ((((iVar4 == 6) || (iVar4 == 0xe)) || (iVar4 == 0xf)) || (iVar4 == 7)) {
      param_1 = 0x10000;
      goto LAB_0094d739;
    }
    if (iVar4 != 0x25) goto LAB_0094d739;
  }
  param_1 = 0xf0000;
LAB_0094d739:
  if (((param_4 == (int *)0x0) ||
      (((iVar4 = (**(code **)(*in_ECX + 0x74))
                           (*(undefined4 *)(in_ECX[5] + *param_4 * 4),&local_8,&local_c), -1 < iVar4
        && (iVar4 = (**(code **)(*in_ECX + 0x78))(piVar1,param_7,param_1,&local_10), -1 < iVar4)) &&
       (iVar4 = (**(code **)(*in_ECX + 0x68))(local_8 ^ param_8,local_10,local_c), -1 < iVar4)))) &&
     (((piVar1 = param_5, param_5 == (int *)0x0 ||
       (((iVar4 = (**(code **)(*in_ECX + 0x74))
                            (*(undefined4 *)(in_ECX[5] + *param_5 * 4),&local_8,&local_c),
         -1 < iVar4 &&
         (iVar4 = (**(code **)(*in_ECX + 0x78))(piVar1,param_7,param_1,&local_10), -1 < iVar4)) &&
        (iVar4 = (**(code **)(*in_ECX + 0x68))(local_8 ^ param_9,local_10,local_c), -1 < iVar4))))
      && (((piVar1 = param_6, param_6 == (int *)0x0 ||
           (((iVar4 = (**(code **)(*in_ECX + 0x74))
                                (*(undefined4 *)(in_ECX[5] + *param_6 * 4),&local_8,&local_c),
             -1 < iVar4 &&
             (iVar4 = (**(code **)(*in_ECX + 0x78))(piVar1,param_7,param_1,&local_10), -1 < iVar4))
            && (iVar4 = (**(code **)(*in_ECX + 0x68))(local_8 ^ param_10,local_10,local_c),
               -1 < iVar4)))) &&
          ((iVar4 = (**(code **)(*in_ECX + 0x60))(), -1 < iVar4 &&
           (iVar4 = FUN_00948616(), -1 < iVar4)))))))) {
    iVar4 = 0;
  }
  return iVar4;
}


// ==== FUN_0094d85c @ 0x0094d85c ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_0094d85c(uint param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  char local_28 [32];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  if (in_ECX[0x56] == 0) {
    if (param_1 < 0x800) {
      uVar1 = param_1 & 0x7ff | 0xa0000000;
    }
    else if (param_1 < 0x1000) {
      uVar1 = param_1 & 0x7ff | 0xb0000800;
    }
    else if (param_1 < 0x1800) {
      uVar1 = param_1 & 0x7ff | 0xc0000800;
    }
    else {
      uVar1 = param_1 & 0x7ff | 0xd0000800;
    }
    iVar2 = FUN_0094d495(0x51);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*in_ECX + 100))(uVar1,0xf0000,0);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_0094b4db(*param_2);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_0094b4db(param_2[1]);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_0094b4db(param_2[2]);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_0094b4db(param_2[3]);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*in_ECX + 0x60))();
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_00948616();
    if (iVar2 < 0) {
      return iVar2;
    }
  }
  else {
    _sprintf(local_28,s_c__zz_d_00a2e24c,param_1);
    iVar2 = FUN_00907c5b(local_28,param_1,1);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_0090609c(local_28);
    *(undefined4 *)(iVar2 + 0xc) = 1;
    *(undefined4 *)(iVar2 + 0x10) = *param_2;
    *(undefined4 *)(iVar2 + 0x14) = param_2[1];
    *(undefined4 *)(iVar2 + 0x18) = param_2[2];
    *(undefined4 *)(iVar2 + 0x1c) = param_2[3];
    in_ECX[0x7d] = in_ECX[0x7d] + 1;
  }
  return 0;
}


// ==== FUN_0094d9a6 @ 0x0094d9a6 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_0094d9a6(uint param_1,undefined4 *param_2)

{
  int iVar1;
  int *in_ECX;
  char local_28 [32];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  if (in_ECX[0x56] == 0) {
    iVar1 = FUN_0094d495(0x30);
    if (((((-1 < iVar1) &&
          (iVar1 = (**(code **)(*in_ECX + 100))(param_1 & 0x7ff | 0xf0000000,0xf0000,0), -1 < iVar1)
          ) && (iVar1 = FUN_0094b4db(*param_2), -1 < iVar1)) &&
        ((iVar1 = FUN_0094b4db(param_2[1]), -1 < iVar1 &&
         (iVar1 = FUN_0094b4db(param_2[2]), -1 < iVar1)))) &&
       ((iVar1 = FUN_0094b4db(param_2[3]), -1 < iVar1 &&
        ((iVar1 = (**(code **)(*in_ECX + 0x60))(), -1 < iVar1 &&
         (iVar1 = FUN_00948616(), -1 < iVar1)))))) {
      iVar1 = 0;
    }
  }
  else {
    _sprintf(local_28,s_i__zz_d_00a2e254,param_1);
    iVar1 = FUN_00907c5b(local_28,param_1,1);
    if (-1 < iVar1) {
      iVar1 = FUN_0090609c(local_28);
      *(undefined4 *)(iVar1 + 0xc) = 1;
      *(undefined4 *)(iVar1 + 0x10) = *param_2;
      *(undefined4 *)(iVar1 + 0x14) = param_2[1];
      *(undefined4 *)(iVar1 + 0x18) = param_2[2];
      *(undefined4 *)(iVar1 + 0x1c) = param_2[3];
      in_ECX[0x7d] = in_ECX[0x7d] + 1;
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ==== FUN_0094dab7 @ 0x0094dab7 ====

int FUN_0094dab7(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_0094d495(0x27);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*in_ECX + 0x60))();
    if (-1 < iVar1) {
      iVar1 = FUN_00948616();
      if (-1 < iVar1) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


// ==== FUN_0094dae1 @ 0x0094dae1 ====

int FUN_0094dae1(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_0094d495(0x1d);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*in_ECX + 0x60))();
    if (-1 < iVar1) {
      iVar1 = FUN_00948616();
      if (-1 < iVar1) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


// ==== FUN_0094db0b @ 0x0094db0b ====

int FUN_0094db0b(void)

{
  uint uVar1;
  int *in_ECX;
  int iVar2;
  uint uVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = *(uint *)in_ECX[0x40] & 0xfff00000;
  iVar2 = 0;
  uVar3 = *(uint *)in_ECX[0x40] & 0xfffff;
  if (uVar1 != 0x74300000) {
    if (uVar1 == 0x74400000) {
      iVar2 = 5;
      goto LAB_0094db61;
    }
    if (uVar1 != 0x74500000) {
      if (uVar1 == 0x74600000) {
        iVar2 = 4;
      }
      else if (uVar1 == 0x74700000) {
        iVar2 = 3;
      }
      goto LAB_0094db61;
    }
  }
  iVar2 = 2;
LAB_0094db61:
  iVar2 = FUN_0094d495(iVar2 << 0x10 | 0x2d);
  if ((((-1 < iVar2) &&
       (iVar2 = (**(code **)(*in_ECX + 0x74))
                          (*(undefined4 *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 8) * 4),&local_10,
                           &local_8), -1 < iVar2)) &&
      (iVar2 = (**(code **)(*in_ECX + 0x78))
                         (*(undefined4 *)(in_ECX[0x40] + 8),uVar3,0xf0000,&local_c), -1 < iVar2)) &&
     (iVar2 = (**(code **)(*in_ECX + 0x68))(local_10,local_c,local_8), -1 < iVar2)) {
    iVar2 = (**(code **)(*in_ECX + 0x74))
                      (*(undefined4 *)
                        (in_ECX[5] + *(int *)(uVar3 * 4 + *(int *)(in_ECX[0x40] + 8)) * 4),&local_10
                       ,&local_8);
    if (((-1 < iVar2) &&
        (iVar2 = (**(code **)(*in_ECX + 0x78))
                           (*(int *)(in_ECX[0x40] + 8) + uVar3 * 4,uVar3,0xf0000,&local_c),
        -1 < iVar2)) &&
       ((iVar2 = (**(code **)(*in_ECX + 0x68))(local_10,local_c,local_8), -1 < iVar2 &&
        ((iVar2 = (**(code **)(*in_ECX + 0x60))(), -1 < iVar2 &&
         (iVar2 = FUN_00948616(), -1 < iVar2)))))) {
      iVar2 = 0;
    }
  }
  return iVar2;
}


// ==== FUN_0094dc51 @ 0x0094dc51 ====

void FUN_0094dc51(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar1 = *(uint **)(in_ECX + 0x100);
  uVar2 = puVar1[3];
  uVar3 = *puVar1;
  uVar4 = puVar1[4];
  FUN_009145b2(0,&local_8);
  FUN_009145b2(1,&local_c);
  FUN_0094d663(0x42,uVar4,uVar2,local_c,local_8,0,uVar3 & 0xfffff,0,0,0,0);
  return;
}


// ==== FUN_0094dcb5 @ 0x0094dcb5 ====

int FUN_0094dcb5(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  uint uVar4;
  undefined4 local_30;
  uint local_2c;
  undefined4 local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_2c = ((uint *)in_ECX[0x40])[3];
  uVar4 = *(uint *)in_ECX[0x40] & 0xfffff;
  FUN_009145b2(0,&local_1c);
  FUN_009145b2(1,&local_18);
  FUN_009145b2(2,&local_20);
  FUN_009145b2(3,&local_24);
  piVar1 = *(int **)(in_ECX[0x40] + 0x10);
  uVar2 = (**(code **)(*in_ECX + 0x5c))(0x5d);
  iVar3 = FUN_0094d495(uVar2);
  if (-1 < iVar3) {
    iVar3 = (**(code **)(*in_ECX + 0x6c))
                      (*(undefined4 *)(in_ECX[5] + *piVar1 * 4),&local_8,&local_30,&local_28);
    if (-1 < iVar3) {
      iVar3 = (**(code **)(*in_ECX + 0x70))(piVar1,local_2c,&local_14,local_28);
      if (-1 < iVar3) {
        iVar3 = (**(code **)(*in_ECX + 100))(local_8,local_14,local_30);
        if (-1 < iVar3) {
          iVar3 = (**(code **)(*in_ECX + 0x74))
                            (*(undefined4 *)(in_ECX[5] + *local_18 * 4),&local_8,&local_c);
          if (-1 < iVar3) {
            iVar3 = (**(code **)(*in_ECX + 0x78))(local_18,uVar4,local_14,&local_10);
            if (-1 < iVar3) {
              iVar3 = (**(code **)(*in_ECX + 0x68))(local_8,local_10,local_c);
              if (-1 < iVar3) {
                iVar3 = (**(code **)(*in_ECX + 0x74))
                                  (*(undefined4 *)(in_ECX[5] + *local_1c * 4),&local_8,&local_c);
                if (-1 < iVar3) {
                  iVar3 = (**(code **)(*in_ECX + 0x78))(local_1c,uVar4,local_14,&local_10);
                  if (-1 < iVar3) {
                    iVar3 = (**(code **)(*in_ECX + 0x68))(local_8,local_10,local_c);
                    if (-1 < iVar3) {
                      iVar3 = (**(code **)(*in_ECX + 0x74))
                                        (*(undefined4 *)(in_ECX[5] + *local_20 * 4),&local_8,
                                         &local_c);
                      if (-1 < iVar3) {
                        iVar3 = (**(code **)(*in_ECX + 0x78))(local_20,uVar4,local_14,&local_10);
                        if (-1 < iVar3) {
                          iVar3 = (**(code **)(*in_ECX + 0x68))(local_8,local_10,local_c);
                          if (-1 < iVar3) {
                            iVar3 = (**(code **)(*in_ECX + 0x74))
                                              (*(undefined4 *)(in_ECX[5] + *local_24 * 4),&local_8,
                                               &local_c);
                            if (-1 < iVar3) {
                              iVar3 = (**(code **)(*in_ECX + 0x78))
                                                (local_24,uVar4,local_14,&local_10);
                              if (-1 < iVar3) {
                                iVar3 = (**(code **)(*in_ECX + 0x68))(local_8,local_10,local_c);
                                if (-1 < iVar3) {
                                  iVar3 = (**(code **)(*in_ECX + 0x60))();
                                  if (-1 < iVar3) {
                                    iVar3 = FUN_00948616();
                                    if (-1 < iVar3) {
                                      iVar3 = 0;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return iVar3;
}


// ==== FUN_0094dee4 @ 0x0094dee4 ====

void FUN_0094dee4(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar1 = *(uint **)(in_ECX + 0x100);
  uVar2 = puVar1[3];
  uVar3 = *puVar1;
  uVar4 = puVar1[4];
  FUN_009145b2(0,&local_8);
  FUN_009145b2(1,&local_c);
  FUN_0094d663(0x10042,uVar4,uVar2,local_c,local_8,0,uVar3 & 0xfffff,0,0,0,0);
  return;
}


// ==== FUN_0094df4b @ 0x0094df4b ====

void FUN_0094df4b(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar1 = *(uint **)(in_ECX + 0x100);
  uVar2 = puVar1[3];
  uVar3 = *puVar1;
  uVar4 = puVar1[4];
  FUN_009145b2(0,&local_8);
  FUN_009145b2(1,&local_c);
  FUN_0094d663(0x20042,uVar4,uVar2,local_c,local_8,0,uVar3 & 0xfffff,0,0,0,0);
  return;
}


// ==== FUN_0094dfb2 @ 0x0094dfb2 ====

void FUN_0094dfb2(void)

{
  uint *puVar1;
  uint uVar2;
  int in_ECX;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  uint local_8;
  
  puVar1 = *(uint **)(in_ECX + 0x100);
  local_8 = puVar1[3];
  uVar2 = *puVar1;
  local_c = puVar1[4];
  FUN_009145b2(0,&local_14);
  FUN_009145b2(1,&local_10);
  FUN_0094d663(0x5f,local_c,local_8,local_10,local_14,0,uVar2 & 0xfffff,0,0,0,0);
  return;
}


// ==== FUN_0094e016 @ 0x0094e016 ====

void FUN_0094e016(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int in_ECX;
  
  puVar1 = *(uint **)(in_ECX + 0x100);
  uVar2 = puVar1[2];
  uVar3 = *puVar1 & 0xfffff;
  FUN_0094d663(0x5a,puVar1[4],puVar1[3],uVar2,uVar2 + uVar3 * 4,uVar2 + uVar3 * 8,uVar3,0,0,0,0);
  return;
}


// ==== FUN_0094e04c @ 0x0094e04c ====

int FUN_0094e04c(void)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  undefined4 local_10;
  uint local_c;
  uint local_8;
  
  iVar1 = in_ECX[0x40];
  if ((*(byte *)((int)in_ECX + 0x6e) & 0x40) == 0) {
    if (*(int *)(iVar1 + 4) != 4) goto LAB_0094e18e;
  }
  else {
    uVar4 = 0;
    uVar2 = 0;
    if (*(int *)(iVar1 + 4) != 0) {
      piVar3 = *(int **)(iVar1 + 8);
      do {
        if (*(uint *)(*(int *)(in_ECX[5] + *piVar3 * 4) + 0x10) != uVar4) goto LAB_0094e18e;
        uVar2 = *(uint *)(iVar1 + 4);
        uVar4 = uVar4 + 1;
        piVar3 = piVar3 + 1;
      } while (uVar4 < uVar2);
    }
    if (uVar2 != 3) goto LAB_0094e18e;
  }
  iVar1 = *(int *)(in_ECX[5] + **(int **)(iVar1 + 8) * 4);
  if (*(int *)(iVar1 + 4) == in_ECX[0x20]) {
    iVar1 = (**(code **)(*in_ECX + 0x88))(iVar1,&local_c,&local_8);
    if (-1 < iVar1) goto LAB_0094e10f;
  }
  else if (*(int *)(iVar1 + 4) == in_ECX[0x22]) {
    local_8 = 0;
    local_c = *(uint *)(iVar1 + 0xc);
LAB_0094e10f:
    uVar5 = local_8 | 0xfffffff8;
    uVar4 = local_8 & 0x18;
    uVar2 = local_c & 0x7ff;
    iVar1 = FUN_0094d495(0x41);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*in_ECX + 0x7c))
                      (*(undefined4 *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 0x10) * 4),&local_10);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*in_ECX + 100))((uVar5 << 0x14 | uVar4) << 8 | uVar2,0xf0000,local_10);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*in_ECX + 0x60))();
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_00948616();
    if (iVar1 < 0) {
      return iVar1;
    }
    return 0;
  }
LAB_0094e18e:
  FUN_0091a001();
  return -0x7fffbffb;
}


// ==== FUN_0094e1a1 @ 0x0094e1a1 ====

undefined4 FUN_0094e1a1(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int in_ECX;
  int local_14 [4];
  
  local_14[3] = 0;
  iVar2 = *(int *)(in_ECX + 0x100);
  local_14[2] = 0;
  iVar3 = *(int *)(in_ECX + 0x10);
  do {
    iVar4 = *(int *)(local_14[2] + *(int *)(iVar2 + 0x10));
    iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4);
    if (((*(byte *)(*(int *)(iVar3 + *(int *)(iVar5 + 4) * 4) + 4) & 1) == 0) ||
       (*(int *)(iVar5 + 0x5c) != 0)) {
      piVar1 = local_14 + local_14[3];
      local_14[3] = local_14[3] + 1;
      *piVar1 = iVar4;
    }
    local_14[2] = local_14[2] + 4;
  } while ((uint)local_14[2] < 8);
  if (local_14[3] == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_0094d663(0x25,local_14,local_14[3],*(undefined4 *)(iVar2 + 8),
                         -(uint)(*(int *)(in_ECX + 0x18c) != 0) & in_ECX + 400U,
                         -(uint)(*(int *)(in_ECX + 0x18c) != 0) & in_ECX + 0x1a0U,4,0,0,0,0);
  }
  return uVar6;
}


// ==== FUN_0094e23f @ 0x0094e23f ====

int FUN_0094e23f(void)

{
  uint uVar1;
  int *in_ECX;
  int iVar2;
  uint uVar3;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar2 = 0;
  if (in_ECX[0xd] == 0) {
    return -0x7fffbfff;
  }
  uVar1 = *(uint *)in_ECX[0x40] & 0xfff00000;
  uVar3 = *(uint *)in_ECX[0x40] & 0xfffff;
  if (uVar1 != 0x10f00000) {
    if (uVar1 == 0x73500000) {
      iVar2 = 3;
      goto LAB_0094e2a6;
    }
    if (uVar1 == 0x73600000) {
      iVar2 = 4;
      goto LAB_0094e2a6;
    }
    if (uVar1 != 0x73700000) {
      if (uVar1 == 0x73800000) {
        iVar2 = 2;
      }
      goto LAB_0094e2a6;
    }
  }
  iVar2 = 5;
LAB_0094e2a6:
  iVar2 = FUN_0094d495(iVar2 << 0x10 | 0x5e);
  if (iVar2 < 0) {
    return iVar2;
  }
  iVar2 = (**(code **)(*in_ECX + 0x6c))
                    (*(undefined4 *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 0x10) * 4),&local_8,0,
                     &local_18);
  if (iVar2 < 0) {
    return iVar2;
  }
  iVar2 = (**(code **)(*in_ECX + 0x70))
                    (*(undefined4 *)(in_ECX[0x40] + 0x10),*(undefined4 *)(in_ECX[0x40] + 0xc),
                     &local_14,local_18);
  if (iVar2 < 0) {
    return iVar2;
  }
  iVar2 = (**(code **)(*in_ECX + 100))(local_8,local_14,0);
  if (iVar2 < 0) {
    return iVar2;
  }
  if ((*(uint *)in_ECX[0x40] & 0xfff00000) == 0x10f00000) {
    iVar2 = (**(code **)(*in_ECX + 0x74))();
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*in_ECX + 0x78))
                      (*(undefined4 *)(in_ECX[0x40] + 8),*(undefined4 *)(in_ECX[0x40] + 0xc),
                       local_14,&local_10);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*in_ECX + 0x68))(local_8,local_10,local_c);
    if (iVar2 < 0) {
      return iVar2;
    }
    local_10 = local_10 ^ 0x1000000;
  }
  else {
    iVar2 = (**(code **)(*in_ECX + 0x74))
                      (*(undefined4 *)(in_ECX[5] + *(int *)((uint *)in_ECX[0x40])[2] * 4),&local_8,
                       &local_c);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*in_ECX + 0x78))
                      (*(undefined4 *)(in_ECX[0x40] + 8),uVar3,local_14,&local_10);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*in_ECX + 0x68))(local_8,local_10,local_c);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*in_ECX + 0x74))
                      (*(undefined4 *)
                        (in_ECX[5] + *(int *)(uVar3 * 4 + *(int *)(in_ECX[0x40] + 8)) * 4),&local_8,
                       &local_c);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*in_ECX + 0x78))
                      (*(int *)(in_ECX[0x40] + 8) + uVar3 * 4,uVar3,local_14,&local_10);
    if (iVar2 < 0) {
      return iVar2;
    }
  }
  iVar2 = (**(code **)(*in_ECX + 0x68))(local_8,local_10,local_c);
  if (((-1 < iVar2) && (iVar2 = (**(code **)(*in_ECX + 0x60))(), -1 < iVar2)) &&
     (iVar2 = FUN_00948616(), -1 < iVar2)) {
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_0094e448 @ 0x0094e448 ====

int FUN_0094e448(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  uint uVar5;
  uint uVar6;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  if (in_ECX[0xd] == 0) {
    iVar2 = -0x7fffbfff;
  }
  else if (*(int *)(in_ECX[0x40] + 0xc) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 0x10) * 4);
    local_8 = 0;
    do {
      iVar4 = *(int *)(in_ECX[5] +
                      *(int *)(*(int *)(in_ECX[0x40] + 8) +
                              *(int *)(in_ECX[0x40] + 0xc) * local_8 * 4) * 4);
      if ((((*(int *)(iVar4 + 4) != *(int *)(iVar2 + 4)) ||
           (*(int *)(iVar4 + 8) != *(int *)(iVar2 + 8))) ||
          (*(int *)(iVar4 + 0xc) != *(int *)(iVar2 + 0xc))) ||
         (*(int *)(iVar4 + 0x10) != *(int *)(iVar2 + 0x10))) {
        iVar3 = FUN_0094d495(1);
        if (iVar3 < 0) {
          return iVar3;
        }
        iVar3 = *(int *)(in_ECX[5] + *(int *)(iVar4 + 0x14) * 4);
        iVar1 = *(int *)(iVar3 + 0x10);
        uVar5 = *(uint *)(iVar3 + 0xc) & 0x7ff;
        uVar6 = uVar5 | 0xb0001000;
        if (iVar1 != 0) {
          if (iVar1 == 1) {
            uVar6 = uVar5 | 0xb0551000;
          }
          else if (iVar1 == 2) {
            uVar6 = uVar5 | 0xb0aa1000;
          }
          else if (iVar1 == 3) {
            uVar6 = uVar5 | 0xb0ff1000;
          }
        }
        if (*(int *)(iVar4 + 0x18) == 0) {
          uVar6 = uVar6 | 0xd000000;
        }
        iVar4 = (**(code **)(*in_ECX + 0x6c))
                          (*(undefined4 *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 0x10) * 4),&local_c
                           ,0,&local_14);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = (**(code **)(*in_ECX + 0x70))
                          (*(undefined4 *)(in_ECX[0x40] + 0x10),*(undefined4 *)(in_ECX[0x40] + 0xc),
                           &local_10,local_14);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = (**(code **)(*in_ECX + 100))(local_c,local_10,uVar6);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = (**(code **)(*in_ECX + 0x74))
                          (*(undefined4 *)
                            (in_ECX[5] +
                            *(int *)(*(int *)(in_ECX[0x40] + 8) +
                                    *(int *)(in_ECX[0x40] + 0xc) * local_8 * 4) * 4),&local_c,
                           &local_18);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = *(int *)(in_ECX[0x40] + 0xc);
        iVar4 = (**(code **)(*in_ECX + 0x78))
                          (*(int *)(in_ECX[0x40] + 8) + iVar4 * local_8 * 4,iVar4,local_10,&local_1c
                          );
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = (**(code **)(*in_ECX + 0x68))(local_c,local_1c,local_18);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = (**(code **)(*in_ECX + 0x60))();
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = FUN_00948616();
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < 2);
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_0094e617 @ 0x0094e617 ====

int FUN_0094e617(void)

{
  uint uVar1;
  int *in_ECX;
  int iVar2;
  uint uVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = *(uint *)in_ECX[0x40] & 0xfff00000;
  iVar2 = 0;
  uVar3 = *(uint *)in_ECX[0x40] & 0xfffff;
  if (uVar1 != 0x73000000) {
    if (uVar1 == 0x73900000) {
      iVar2 = 3;
      goto LAB_0094e66d;
    }
    if (uVar1 == 0x73a00000) {
      iVar2 = 4;
      goto LAB_0094e66d;
    }
    if (uVar1 == 0x73b00000) {
      iVar2 = 5;
      goto LAB_0094e66d;
    }
    if (uVar1 != 0x73c00000) goto LAB_0094e66d;
  }
  iVar2 = 2;
LAB_0094e66d:
  iVar2 = FUN_0094d495(iVar2 << 0x10 | 0x29);
  if ((((-1 < iVar2) &&
       (iVar2 = (**(code **)(*in_ECX + 0x74))
                          (*(undefined4 *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 8) * 4),&local_10,
                           &local_8), -1 < iVar2)) &&
      (iVar2 = (**(code **)(*in_ECX + 0x78))
                         (*(undefined4 *)(in_ECX[0x40] + 8),uVar3,0xf0000,&local_c), -1 < iVar2)) &&
     (iVar2 = (**(code **)(*in_ECX + 0x68))(local_10,local_c,local_8), -1 < iVar2)) {
    iVar2 = (**(code **)(*in_ECX + 0x74))
                      (*(undefined4 *)
                        (in_ECX[5] + *(int *)(uVar3 * 4 + *(int *)(in_ECX[0x40] + 8)) * 4),&local_10
                       ,&local_8);
    if (((-1 < iVar2) &&
        (iVar2 = (**(code **)(*in_ECX + 0x78))
                           (*(int *)(in_ECX[0x40] + 8) + uVar3 * 4,uVar3,0xf0000,&local_c),
        -1 < iVar2)) &&
       ((iVar2 = (**(code **)(*in_ECX + 0x68))(local_10,local_c,local_8), -1 < iVar2 &&
        ((iVar2 = (**(code **)(*in_ECX + 0x60))(), -1 < iVar2 &&
         (iVar2 = FUN_00948616(), -1 < iVar2)))))) {
      iVar2 = 0;
    }
  }
  return iVar2;
}


// ==== FUN_0094e772 @ 0x0094e772 ====

int FUN_0094e772(int param_1)

{
  int iVar1;
  int *in_ECX;
  int *local_c;
  int *local_8;
  
  local_c = in_ECX;
  local_8 = in_ECX;
  iVar1 = FUN_0094d495(0x28);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*in_ECX + 0x74))
                      (*(undefined4 *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 8) * 4),&local_c,
                       &local_8);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*in_ECX + 0x68))
                        (-(uint)(param_1 != 0) & 0xd000000 | (uint)local_c,0xe40000,local_8);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*in_ECX + 0x60))();
        if (-1 < iVar1) {
          iVar1 = FUN_00948616();
          if (-1 < iVar1) {
            iVar1 = 0;
          }
        }
      }
    }
  }
  return iVar1;
}


// ==== FUN_0094e7ec @ 0x0094e7ec ====

int FUN_0094e7ec(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_0094d495(0x2a);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*in_ECX + 0x60))();
    if (-1 < iVar1) {
      iVar1 = FUN_00948616();
      if (-1 < iVar1) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


// ==== FUN_0094e816 @ 0x0094e816 ====

int FUN_0094e816(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_0094d495(0x2b);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*in_ECX + 0x60))();
    if (-1 < iVar1) {
      iVar1 = FUN_00948616();
      if (-1 < iVar1) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


// ==== FUN_0094e840 @ 0x0094e840 ====

int FUN_0094e840(void)

{
  int iVar1;
  int *in_ECX;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = FUN_0094d495(1);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*in_ECX + 0x6c))
                      (*(undefined4 *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 0x10) * 4),&local_8,
                       &local_1c,&local_18);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*in_ECX + 0x70))
                        (*(undefined4 *)(in_ECX[0x40] + 0x10),*(undefined4 *)(in_ECX[0x40] + 0xc),
                         &local_c,local_18);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*in_ECX + 100))(local_8,local_c,local_1c);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*in_ECX + 0x74))
                            (*(undefined4 *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 8) * 4),&local_8,
                             &local_10);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*in_ECX + 0x78))
                              (*(undefined4 *)(in_ECX[0x40] + 8),*(undefined4 *)(in_ECX[0x40] + 0xc)
                               ,local_c,&local_14);
            if (-1 < iVar1) {
              if ((local_8 & 0xb000000) == 0) {
                local_14 = local_14 | 0x1000000;
              }
              else {
                local_14 = local_14 | 0xc000000;
                local_8 = local_8 & 0xf4ffffff;
              }
              iVar1 = (**(code **)(*in_ECX + 0x68))(local_8,local_14,local_10);
              if (-1 < iVar1) {
                iVar1 = (**(code **)(*in_ECX + 0x60))();
                if (-1 < iVar1) {
                  iVar1 = FUN_00948616();
                  if (-1 < iVar1) {
                    iVar1 = 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return iVar1;
}


// ==== FUN_0094e94d @ 0x0094e94d ====

int FUN_0094e94d(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  int local_c;
  uint local_8;
  
  uVar2 = **(uint **)(in_ECX + 0x100) & 0xfffff;
  local_8 = 0;
  if (uVar2 != 0) {
    local_c = uVar2 << 2;
    do {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x100) + 8);
      iVar1 = FUN_0094d663(0x20,*(int *)(*(int *)(in_ECX + 0x100) + 0x10) + local_8 * 4,1,
                           iVar1 + local_8 * 4,local_c + iVar1,0,uVar2,0,0,0,0);
      if (iVar1 < 0) {
        return iVar1;
      }
      local_8 = local_8 + 1;
      local_c = local_c + 4;
    } while (local_8 < uVar2);
  }
  return 0;
}


// ==== FUN_0094e9bf @ 0x0094e9bf ====

int FUN_0094e9bf(void)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  uint uVar3;
  int *piVar4;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  int local_c;
  undefined4 local_8;
  
  uVar3 = *(uint *)in_ECX[0x40] & 0xfffff;
  uVar1 = (**(code **)(*in_ECX + 0x5c))(0x12);
  iVar2 = FUN_0094d495(uVar1);
  if ((((-1 < iVar2) &&
       (iVar2 = (**(code **)(*in_ECX + 0x6c))
                          (*(undefined4 *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 0x10) * 4),&local_8
                           ,&local_1c,&local_18), -1 < iVar2)) &&
      (iVar2 = (**(code **)(*in_ECX + 0x70))
                         (*(undefined4 *)(in_ECX[0x40] + 0x10),uVar3,&local_14,local_18), -1 < iVar2
      )) && (iVar2 = (**(code **)(*in_ECX + 100))(local_8,local_14,local_1c), -1 < iVar2)) {
    local_10 = 0;
    local_c = 0;
    do {
      piVar4 = (int *)(*(int *)(in_ECX[0x40] + 8) + local_c);
      iVar2 = (**(code **)(*in_ECX + 0x74))
                        (*(undefined4 *)(in_ECX[5] + *piVar4 * 4),&local_8,&local_20);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = (**(code **)(*in_ECX + 0x78))(piVar4,uVar3,local_14,&local_24);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = (**(code **)(*in_ECX + 0x68))(local_8,local_24,local_20);
      if (iVar2 < 0) {
        return iVar2;
      }
      local_10 = local_10 + 1;
      local_c = local_c + uVar3 * 4;
    } while (local_10 < 3);
    iVar2 = (**(code **)(*in_ECX + 0x60))();
    if ((-1 < iVar2) && (iVar2 = FUN_00948616(), -1 < iVar2)) {
      iVar2 = 0;
    }
  }
  return iVar2;
}


// ==== FUN_0094eada @ 0x0094eada ====

int FUN_0094eada(void)

{
  int iVar1;
  int *in_ECX;
  uint uVar2;
  int local_18 [4];
  int *local_8;
  
  local_8 = (int *)((uint *)in_ECX[0x40])[4];
  uVar2 = *(uint *)in_ECX[0x40] & 0xfffff;
  if (in_ECX[0x22] != *(int *)(*(int *)(in_ECX[5] + *local_8 * 4) + 4)) {
    iVar1 = (**(code **)(*in_ECX + 0x80))(in_ECX[0x3f],local_18,uVar2,0,0);
    if (iVar1 < 0) {
      return iVar1;
    }
    local_8 = local_18;
  }
  iVar1 = FUN_0094d663(0x24,local_8,uVar2,*(undefined4 *)(in_ECX[0x40] + 8),0,0,uVar2,0,0,0,0);
  if (-1 < iVar1) {
    if ((local_8 == local_18) &&
       (iVar1 = FUN_0094d663(1,*(undefined4 *)(in_ECX[0x40] + 0x10),uVar2,local_18,0,0,uVar2,0,0,0,0
                            ), iVar1 < 0)) {
      return iVar1;
    }
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_0094eb80 @ 0x0094eb80 ====

int FUN_0094eb80(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  uint uVar4;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  uint local_c;
  uint local_8;
  
  uVar4 = *(uint *)in_ECX[0x40] & 0xfffff;
  uVar2 = (**(code **)(*in_ECX + 0x5c))(4);
  iVar3 = FUN_0094d495(uVar2);
  if ((((-1 < iVar3) &&
       (iVar3 = (**(code **)(*in_ECX + 0x6c))
                          (*(undefined4 *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 0x10) * 4),&local_c
                           ,&local_1c,&local_18), -1 < iVar3)) &&
      (iVar3 = (**(code **)(*in_ECX + 0x70))
                         (*(undefined4 *)(in_ECX[0x40] + 0x10),uVar4,&local_10,local_18), -1 < iVar3
      )) && (iVar3 = (**(code **)(*in_ECX + 100))(local_c,local_10,local_1c), -1 < iVar3)) {
    local_8 = 0;
    do {
      piVar1 = (int *)(((uint *)in_ECX[0x40])[2] + local_8 * uVar4 * 4);
      if ((local_8 == 1) && ((*(uint *)in_ECX[0x40] & 0xfff00000) == 0x70400000)) {
        local_14 = 0x1000000;
      }
      else {
        local_14 = 0;
      }
      iVar3 = (**(code **)(*in_ECX + 0x74))
                        (*(undefined4 *)(in_ECX[5] + *piVar1 * 4),&local_c,&local_20);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar3 = (**(code **)(*in_ECX + 0x78))(piVar1,uVar4,local_10,&local_24);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar3 = (**(code **)(*in_ECX + 0x68))(local_14 ^ local_c,local_24,local_20);
      if (iVar3 < 0) {
        return iVar3;
      }
      local_8 = local_8 + 1;
    } while (local_8 < 3);
    iVar3 = (**(code **)(*in_ECX + 0x60))();
    if ((-1 < iVar3) && (iVar3 = FUN_00948616(), -1 < iVar3)) {
      iVar3 = 0;
    }
  }
  return iVar3;
}


// ==== FUN_0094ecbe @ 0x0094ecbe ====

int FUN_0094ecbe(void)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  uVar1 = *(uint *)in_ECX[0x40];
  uVar3 = uVar1 & 0xfffff;
  if (uVar1 == 0x70500003) {
    uVar4 = 0x18;
  }
  else if (uVar1 == 0x70600003) {
    uVar4 = 0x17;
  }
  else if (uVar1 == 0x70600004) {
    uVar4 = 0x15;
  }
  else if (uVar1 == 0x70700003) {
    uVar4 = 0x16;
  }
  else {
    if (uVar1 != 0x70700004) {
      uVar4 = local_1c;
      goto LAB_0094ed0e;
    }
    uVar4 = 0x14;
  }
LAB_0094ed0e:
  iVar2 = FUN_0094d495(uVar4);
  if (-1 < iVar2) {
    iVar2 = (**(code **)(*in_ECX + 0x6c))
                      (*(undefined4 *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 0x10) * 4),&local_8,
                       &local_1c,&local_18);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*in_ECX + 0x70))
                        (*(undefined4 *)(in_ECX[0x40] + 0x10),*(undefined4 *)(in_ECX[0x40] + 0xc),
                         &local_c,local_18);
      if (-1 < iVar2) {
        iVar2 = (**(code **)(*in_ECX + 100))(local_8,local_c,local_1c);
        if (-1 < iVar2) {
          local_c = ((uVar3 != 3) - 1 & 0xfff80000) + 0xf0000;
          iVar2 = (**(code **)(*in_ECX + 0x74))
                            (*(undefined4 *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 8) * 4),&local_8,
                             &local_10);
          if (-1 < iVar2) {
            iVar2 = (**(code **)(*in_ECX + 0x78))
                              (*(undefined4 *)(in_ECX[0x40] + 8),uVar3,local_c,&local_14);
            if (-1 < iVar2) {
              iVar2 = (**(code **)(*in_ECX + 0x68))(local_8,local_14,local_10);
              if (-1 < iVar2) {
                iVar2 = (**(code **)(*in_ECX + 0x74))
                                  (*(undefined4 *)
                                    (in_ECX[5] +
                                    *(int *)(uVar3 * 4 + *(int *)(in_ECX[0x40] + 8)) * 4),&local_8,
                                   &local_10);
                if (-1 < iVar2) {
                  iVar2 = (**(code **)(*in_ECX + 0x78))
                                    (*(int *)(in_ECX[0x40] + 8) + uVar3 * 4,uVar3,local_c,&local_14)
                  ;
                  if (-1 < iVar2) {
                    iVar2 = (**(code **)(*in_ECX + 0x68))(local_8,local_14,local_10);
                    if (-1 < iVar2) {
                      iVar2 = (**(code **)(*in_ECX + 0x60))();
                      if (-1 < iVar2) {
                        iVar2 = FUN_00948616();
                        if (-1 < iVar2) {
                          iVar2 = 0;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return iVar2;
}


// ==== FUN_0094ee70 @ 0x0094ee70 ====

void FUN_0094ee70(undefined4 param_1,uint param_2)

{
  uint *puVar1;
  int in_ECX;
  int iVar2;
  uint uVar3;
  int local_24 [4];
  uint local_14;
  int local_10;
  uint local_c;
  int *local_8;
  
  puVar1 = *(uint **)(in_ECX + 0x100);
  local_14 = puVar1[3];
  local_24[3] = puVar1[4];
  uVar3 = *puVar1 & 0xfffff;
  FUN_009145b2(0,local_24);
  FUN_009145b2(1,local_24 + 1);
  FUN_009145b2(2,local_24 + 2);
  local_10 = 0;
  if (param_2 != 0) {
    param_2 = 0;
    do {
      if (local_10 != 0) break;
      if (((int *)local_24[param_2] != (int *)0x0) && (local_c = 0, uVar3 != 0)) {
        iVar2 = 0;
        local_8 = (int *)local_24[param_2];
        do {
          if ((*(byte *)(iVar2 + 3 + *(int *)(*(int *)(in_ECX + 0x14) + *local_8 * 4)) & 1) != 0) {
            local_10 = 1;
            break;
          }
          local_c = local_c + 1;
          local_8 = local_8 + 1;
          iVar2 = iVar2 + 0x80;
        } while (local_c < uVar3);
      }
      param_2 = param_2 + 1;
    } while (param_2 < 3);
  }
  FUN_0094d663(param_1,local_24[3],local_14,local_24[0],local_24[1],local_24[2],uVar3,0,0,0,local_10
              );
  return;
}


// ==== FUN_0094ef49 @ 0x0094ef49 ====

int FUN_0094ef49(undefined4 param_1,int *param_2,int *param_3,uint param_4,uint param_5,
                undefined4 param_6)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  bool bVar7;
  int local_34 [4];
  int local_24 [4];
  int *local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  if (((param_5 < param_4) && (param_5 == 1)) && (**(int **)(in_ECX[0x40] + 8) == *param_3)) {
    iVar2 = FUN_0094ee70(param_1,0);
  }
  else {
    iVar3 = *param_3 * 4;
    iVar2 = *param_2 * 4;
    if (((*(int *)(*(int *)(in_ECX[5] + iVar2) + 4) == *(int *)(*(int *)(iVar3 + in_ECX[5]) + 4)) &&
        (*(int *)(*(int *)(in_ECX[5] + iVar2) + 8) == *(int *)(*(int *)(in_ECX[5] + iVar3) + 8))) &&
       (*(int *)(*(int *)(in_ECX[5] + iVar2) + 0xc) == *(int *)(*(int *)(in_ECX[5] + iVar3) + 0xc)))
    {
      uVar6 = 0;
      bVar7 = false;
      if (param_4 != 0) {
        do {
          param_5 = 0;
          if (uVar6 != 0) {
            do {
              if (*(int *)(*(int *)(in_ECX[5] + param_3[uVar6] * 4) + 0x10) ==
                  *(int *)(*(int *)(in_ECX[5] + param_2[param_5] * 4) + 0x10)) break;
              param_5 = param_5 + 1;
            } while (param_5 < uVar6);
            if (param_5 < uVar6) break;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < param_4);
        bVar7 = uVar6 < param_4;
      }
      local_c = (uint)bVar7;
      if (local_c != 0) {
        uVar4 = 0;
        uVar6 = 0;
        if (param_4 != 0) {
          do {
            uVar1 = *(uint *)(*(int *)(in_ECX[5] + param_2[uVar4] * 4) + 0x10);
            if (uVar6 <= uVar1) {
              uVar6 = uVar1 + 1;
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < param_4);
        }
        iVar2 = (**(code **)(*in_ECX + 0x80))(in_ECX[0x3f],local_34,uVar6,0,0);
        uVar6 = 0;
        if (iVar2 < 0) {
          return iVar2;
        }
        if (param_4 != 0) {
          iVar2 = in_ECX[5];
          do {
            local_24[uVar6] = local_34[*(int *)(*(int *)(iVar2 + param_2[uVar6] * 4) + 0x10)];
            uVar6 = uVar6 + 1;
          } while (uVar6 < param_4);
        }
        local_14 = param_2;
        param_2 = local_24;
      }
    }
    else {
      local_c = 0;
    }
    uVar6 = 0;
    if (param_4 != 0) {
      do {
        param_5 = 1;
        if (uVar6 + 1 < param_4) {
          piVar5 = param_3 + uVar6;
          local_10 = *(int *)(*(int *)(in_ECX[5] + *piVar5 * 4) + 0x10);
          local_8 = uVar6 + 1;
          do {
            piVar5 = piVar5 + 1;
            if (*(int *)(*(int *)(in_ECX[5] + *piVar5 * 4) + 0x10) != local_10) break;
            param_5 = param_5 + 1;
            local_8 = local_8 + 1;
          } while (local_8 < param_4);
        }
        iVar2 = FUN_0094d663(param_1,param_2 + uVar6,param_5,param_3 + uVar6,0,0,param_5,param_6,
                             param_6,param_6,0);
        if (iVar2 < 0) {
          return iVar2;
        }
        uVar6 = uVar6 + param_5;
      } while (uVar6 < param_4);
    }
    if ((local_c == 0) ||
       (iVar2 = FUN_0094d663(1,local_14,param_4,param_2,0,0,param_4,0,0,0,0), -1 < iVar2)) {
      iVar2 = 0;
    }
  }
  return iVar2;
}


// ==== FUN_0094f148 @ 0x0094f148 ====

int FUN_0094f148(void)

{
  int iVar1;
  int *in_ECX;
  int *local_c;
  int *local_8;
  
  local_c = in_ECX;
  local_8 = in_ECX;
  iVar1 = FUN_0094d495(0x26);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*in_ECX + 0x74))
                      (*(undefined4 *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 8) * 4),&local_c,
                       &local_8);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*in_ECX + 0x68))(local_c,0xe40000,local_8);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*in_ECX + 0x60))();
        if (-1 < iVar1) {
          iVar1 = FUN_00948616();
          if (-1 < iVar1) {
            iVar1 = 0;
          }
        }
      }
    }
  }
  return iVar1;
}


// ==== FUN_0094f1b2 @ 0x0094f1b2 ====

int FUN_0094f1b2(void)

{
  int iVar1;
  int *in_ECX;
  int *local_c;
  undefined4 local_8;
  
  local_c = in_ECX;
  iVar1 = FUN_0094d495(0x1b);
  if (-1 < iVar1) {
    local_8 = 0;
    iVar1 = (**(code **)(*in_ECX + 0x68))(0xf0000800,0xe40000,0);
    if ((((-1 < iVar1) &&
         (iVar1 = (**(code **)(*in_ECX + 0x74))
                            (*(undefined4 *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 8) * 4),&local_8,
                             &local_c), -1 < iVar1)) &&
        (iVar1 = (**(code **)(*in_ECX + 0x68))(local_8,0xe40000,local_c), -1 < iVar1)) &&
       ((iVar1 = (**(code **)(*in_ECX + 0x60))(), -1 < iVar1 && (iVar1 = FUN_00948616(), -1 < iVar1)
        ))) {
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ==== FUN_0094f236 @ 0x0094f236 ====

undefined4 FUN_0094f236(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  undefined4 uVar5;
  int iVar6;
  int in_ECX;
  int *piVar7;
  uint local_8;
  
  if (*(int *)(in_ECX + 0x8c) ==
      *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + **(int **)(*(int *)(in_ECX + 0x100) + 0x10) * 4) +
              4)) {
    uVar5 = FUN_0094ee70(0x2e,0);
  }
  else {
    if ((*(byte *)(in_ECX + 0x6e) & 0x10) == 0) {
      uVar1 = *(uint *)(*(int *)(in_ECX + 0x100) + 0xc);
      local_8 = 0;
      if (uVar1 != 0) {
        piVar7 = *(int **)(*(int *)(in_ECX + 0x100) + 0x10);
        iVar6 = *(int *)(*(int *)(in_ECX + 0x100) + 8) - (int)piVar7;
        do {
          iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar6 + (int)piVar7) * 4);
          iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar7 * 4);
          if ((((*(int *)(iVar3 + 4) != *(int *)(iVar2 + 4)) ||
               (*(int *)(iVar3 + 8) != *(int *)(iVar2 + 8))) ||
              (*(int *)(iVar3 + 0xc) != *(int *)(iVar2 + 0xc))) ||
             (((*(int *)(iVar3 + 0x10) != *(int *)(iVar2 + 0x10) ||
               (*(int *)(iVar3 + 0x3c) != *(int *)(iVar2 + 0x3c))) ||
              (((*(byte *)(in_ECX + 0xcc) & 4) != 0 && (*(int *)(iVar3 + 0x60) != 0)))))) break;
          local_8 = local_8 + 1;
          piVar7 = piVar7 + 1;
        } while (local_8 < uVar1);
      }
      if (local_8 == uVar1) {
        return 0;
      }
    }
    local_8 = 0;
    if (*(int *)(*(int *)(in_ECX + 0x100) + 0xc) != 0) {
      do {
        puVar4 = *(uint **)(*(int *)(in_ECX + 0x14) +
                           *(int *)(*(int *)(*(int *)(in_ECX + 0x100) + 0x10) + local_8 * 4) * 4);
        if ((*puVar4 & 0xe000000) == 0) {
          *puVar4 = **(uint **)(*(int *)(in_ECX + 0x14) +
                               *(int *)(*(int *)(*(int *)(in_ECX + 0x100) + 8) + local_8 * 4) * 4) &
                    0xe000000 | *puVar4;
        }
        local_8 = local_8 + 1;
      } while (local_8 < *(uint *)(*(int *)(in_ECX + 0x100) + 0xc));
    }
    iVar6 = *(int *)(in_ECX + 0x100);
    uVar5 = FUN_0094d663(1,*(undefined4 *)(iVar6 + 0x10),*(undefined4 *)(iVar6 + 0xc),
                         *(undefined4 *)(iVar6 + 8),0,0,*(undefined4 *)(iVar6 + 0xc),0,0,0,0);
  }
  return uVar5;
}


// ==== FUN_0094f36f @ 0x0094f36f ====

void FUN_0094f36f(void)

{
  FUN_0094ee70(0x5b,0);
  return;
}


// ==== FUN_0094f379 @ 0x0094f379 ====

void FUN_0094f379(void)

{
  FUN_0094ee70(0x5c,0);
  return;
}


// ==== FUN_0094f383 @ 0x0094f383 ====

void FUN_0094f383(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x100);
  FUN_0094ef49(6,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 8),
               *(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 4),0,0);
  return;
}


// ==== FUN_0094f3a1 @ 0x0094f3a1 ====

void FUN_0094f3a1(void)

{
  FUN_0094ee70(0x13,0);
  return;
}


// ==== FUN_0094f3ab @ 0x0094f3ab ====

void FUN_0094f3ab(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x100);
  FUN_0094ef49(0xe,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 8),
               *(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 4),0,0);
  return;
}


// ==== FUN_0094f3c9 @ 0x0094f3c9 ====

void FUN_0094f3c9(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x100);
  FUN_0094ef49(0xf,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 8),
               *(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 4),0,0);
  return;
}


// ==== FUN_0094f3e7 @ 0x0094f3e7 ====

void FUN_0094f3e7(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x100);
  FUN_0094ef49(7,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 8),
               *(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 4),0,0);
  return;
}


// ==== FUN_0094f405 @ 0x0094f405 ====

void FUN_0094f405(void)

{
  FUN_0094ee70(10,0);
  return;
}


// ==== FUN_0094f40f @ 0x0094f40f ====

void FUN_0094f40f(void)

{
  FUN_0094ee70(0xb,0);
  return;
}


// ==== FUN_0094f419 @ 0x0094f419 ====

void FUN_0094f419(void)

{
  FUN_0094ee70(0xc,0);
  return;
}


// ==== FUN_0094f423 @ 0x0094f423 ====

void FUN_0094f423(void)

{
  FUN_0094ee70(0xd,0);
  return;
}


// ==== FUN_0094f42d @ 0x0094f42d ====

void FUN_0094f42d(void)

{
  FUN_0094ee70(2,0);
  return;
}


// ==== FUN_0094f437 @ 0x0094f437 ====

void FUN_0094f437(void)

{
  FUN_0094ee70(5,0);
  return;
}


// ==== FUN_0094f441 @ 0x0094f441 ====

void FUN_0094f441(void)

{
  FUN_0094ee70(0x11,0);
  return;
}


// ==== FUN_0094f44b @ 0x0094f44b ====

int FUN_0094f44b(void)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  undefined4 uVar3;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  uVar1 = *(uint *)in_ECX[0x40] & 0xfffff;
  if (uVar1 == 1) {
    uVar3 = 5;
  }
  else if (uVar1 == 3) {
    uVar3 = 8;
  }
  else {
    if (uVar1 != 4) {
      iVar2 = (**(code **)(*in_ECX + 0x80))(in_ECX[0x3f],local_c,2,0,0);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = FUN_0094d663(5,local_c,2,*(int *)(in_ECX[0x40] + 8),*(int *)(in_ECX[0x40] + 8) + 8,0,2
                           ,0,0,0,0);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = FUN_0094d663(2,*(undefined4 *)(in_ECX[0x40] + 0x10),
                           *(undefined4 *)(in_ECX[0x40] + 0xc),local_c,local_8,0,1,0,0,0,0);
      if (iVar2 < 0) {
        return iVar2;
      }
      return 0;
    }
    uVar3 = 9;
  }
  iVar2 = FUN_0094ee70(uVar3,0);
  return iVar2;
}


// ==== FUN_0094f4fe @ 0x0094f4fe ====

void FUN_0094f4fe(void)

{
  FUN_0094ee70(0x10,0);
  return;
}


// ==== FUN_0094f508 @ 0x0094f508 ====

void FUN_0094f508(void)

{
  FUN_0094ee70(0x58,0);
  return;
}


// ==== FUN_0094f512 @ 0x0094f512 ====

void FUN_0094f512(void)

{
  FUN_0094ee70(0x50,0);
  return;
}


// ==== FUN_0094f51c @ 0x0094f51c ====

void FUN_0094f51c(void)

{
  FUN_0094ee70(0x23,0);
  return;
}


// ==== FUN_0094f530 @ 0x0094f530 ====

void FUN_0094f530(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_ESI;
  int *local_8;
  
  iVar1 = *(int *)(unaff_ESI + 0x1ac);
  iVar2 = *(int *)(unaff_ESI + 0x140);
  iVar4 = (*(code *)**(undefined4 **)(unaff_ESI + 4))();
  iVar6 = *(int *)(unaff_ESI + 0x24);
  *(int *)(iVar1 + 0x38) = iVar4;
  iVar3 = *(int *)(unaff_ESI + 0xdc);
  *(int *)(iVar1 + 0x3c) = iVar4 + iVar6 * 4;
  iVar4 = 0;
  if (0 < iVar6) {
    local_8 = (int *)(iVar3 + 0xc);
    do {
      iVar5 = (local_8[6] * *local_8) / *(int *)(unaff_ESI + 0x140);
      iVar6 = (*(code *)**(undefined4 **)(unaff_ESI + 4))();
      iVar6 = iVar6 + iVar5 * 4;
      iVar3 = *(int *)(iVar1 + 0x3c);
      *(int *)(*(int *)(iVar1 + 0x38) + iVar4 * 4) = iVar6;
      *(int *)(iVar3 + iVar4 * 4) = iVar6 + (iVar2 + 4) * iVar5 * 4;
      iVar4 = iVar4 + 1;
      local_8 = local_8 + 0x15;
    } while (iVar4 < *(int *)(unaff_ESI + 0x24));
  }
  return;
}


// ==== FUN_0094f5e0 @ 0x0094f5e0 ====

void FUN_0094f5e0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int local_20;
  int local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  
  iVar9 = *(int *)(in_ECX + 0x1ac);
  iVar1 = *(int *)(in_ECX + 0x140);
  local_20 = *(int *)(in_ECX + 0x24);
  if (0 < local_20) {
    local_c = *(int **)(iVar9 + 0x3c);
    local_10 = (int *)(iVar9 + 8);
    local_14 = (int *)(*(int *)(in_ECX + 0xdc) + 0xc);
    iVar9 = *(int *)(iVar9 + 0x38) - (int)local_c;
    do {
      iVar5 = (local_14[6] * *local_14) / iVar1;
      puVar2 = *(undefined4 **)(iVar9 + (int)local_c);
      iVar3 = *local_10;
      puVar6 = (undefined4 *)*local_c;
      local_18 = (iVar1 + 2) * iVar5;
      if (0 < local_18) {
        puVar7 = puVar6;
        do {
          uVar4 = *(undefined4 *)((iVar3 - (int)puVar6) + (int)puVar7);
          *puVar7 = uVar4;
          *(undefined4 *)(((int)puVar2 - (int)puVar6) + (int)puVar7) = uVar4;
          puVar7 = puVar7 + 1;
          local_18 = local_18 + -1;
        } while (local_18 != 0);
      }
      if (0 < iVar5 * 2) {
        puVar7 = puVar6 + iVar5 * iVar1;
        puVar8 = (undefined4 *)(iVar3 + (iVar1 + -2) * iVar5 * 4);
        local_18 = iVar5 * 2;
        do {
          *(undefined4 *)(((int)puVar6 - iVar3) + (int)puVar8) =
               *(undefined4 *)((int)puVar7 + (iVar3 - (int)puVar6));
          *puVar7 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar7 = puVar7 + 1;
          local_18 = local_18 + -1;
        } while (local_18 != 0);
      }
      if (0 < iVar5) {
        puVar6 = puVar2 + -iVar5;
        do {
          *puVar6 = *puVar2;
          puVar6 = puVar6 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      local_c = local_c + 1;
      local_10 = local_10 + 1;
      local_14 = local_14 + 0x15;
      local_20 = local_20 + -1;
    } while (local_20 != 0);
  }
  return;
}


// ==== FUN_0094f720 @ 0x0094f720 ====

void FUN_0094f720(void)

{
  int iVar1;
  int in_EAX;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int local_14;
  int *local_10;
  int *local_c;
  int local_8;
  
  iVar1 = *(int *)(in_EAX + 0x140);
  local_14 = *(int *)(in_EAX + 0x24);
  if (0 < local_14) {
    local_c = *(int **)(*(int *)(in_EAX + 0x1ac) + 0x3c);
    local_10 = (int *)(*(int *)(in_EAX + 0xdc) + 0xc);
    iVar5 = *(int *)(*(int *)(in_EAX + 0x1ac) + 0x38) - (int)local_c;
    do {
      local_8 = (local_10[6] * *local_10) / iVar1;
      puVar6 = (undefined4 *)*local_c;
      if (0 < local_8) {
        puVar2 = puVar6 + (iVar1 + 2) * local_8;
        puVar4 = puVar6 + -local_8;
        puVar7 = puVar6 + (iVar1 + 1) * local_8;
        iVar3 = *(int *)(iVar5 + (int)local_c) - (int)puVar6;
        do {
          *(undefined4 *)(iVar3 + (int)puVar4) = *(undefined4 *)(iVar3 + (int)puVar7);
          *puVar4 = *puVar7;
          *(undefined4 *)(iVar3 + (int)puVar2) = *(undefined4 *)(iVar3 + (int)puVar6);
          *puVar2 = *puVar6;
          puVar7 = puVar7 + 1;
          puVar4 = puVar4 + 1;
          puVar6 = puVar6 + 1;
          puVar2 = puVar2 + 1;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
      }
      local_c = local_c + 1;
      local_10 = local_10 + 0x15;
      local_14 = local_14 + -1;
    } while (local_14 != 0);
  }
  return;
}


// ==== FUN_0094f800 @ 0x0094f800 ====

void FUN_0094f800(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_EAX;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  int local_8;
  
  iVar2 = *(int *)(in_EAX + 0x24);
  iVar3 = *(int *)(in_EAX + 0x1ac);
  local_8 = 0;
  if (0 < iVar2) {
    iVar4 = *(int *)(in_EAX + 0x140);
    iVar5 = *(int *)(iVar3 + 0x40);
    piVar9 = (int *)(*(int *)(in_EAX + 0xdc) + 0xc);
    do {
      uVar8 = piVar9[6] * *piVar9;
      iVar6 = (int)uVar8 / iVar4;
      uVar10 = (uint)piVar9[8] % uVar8;
      if ((uint)piVar9[8] % uVar8 == 0) {
        uVar10 = uVar8;
      }
      if (local_8 == 0) {
        *(int *)(iVar3 + 0x48) = (int)(uVar10 - 1) / iVar6 + 1;
      }
      iVar6 = iVar6 * 2;
      if (0 < iVar6) {
        puVar1 = (undefined4 *)
                 (*(int *)(*(int *)(iVar3 + 0x38 + iVar5 * 4) + local_8 * 4) + uVar10 * 4);
        puVar7 = puVar1;
        do {
          *puVar7 = puVar1[-1];
          puVar7 = puVar7 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      local_8 = local_8 + 1;
      piVar9 = piVar9 + 0x15;
    } while (local_8 < iVar2);
  }
  return;
}


// ==== FUN_0094f8b0 @ 0x0094f8b0 ====

void FUN_0094f8b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x1ac);
  if (*(int *)(iVar2 + 0x30) == 0) {
    iVar4 = (**(code **)(*(int *)(param_1 + 0x1b0) + 0xc))(param_1,iVar2 + 8);
    if (iVar4 == 0) {
      return;
    }
    *(undefined4 *)(iVar2 + 0x30) = 1;
  }
  uVar3 = *(uint *)(param_1 + 0x140);
  puVar1 = (uint *)(iVar2 + 0x34);
  (**(code **)(*(int *)(param_1 + 0x1b4) + 4))
            (param_1,iVar2 + 8,puVar1,uVar3,param_2,param_3,param_4);
  if (uVar3 <= *puVar1) {
    *(undefined4 *)(iVar2 + 0x30) = 0;
    *puVar1 = 0;
  }
  return;
}


// ==== FUN_0094f930 @ 0x0094f930 ====

void FUN_0094f930(int param_1,undefined4 param_2,uint *param_3,uint param_4)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x1ac);
  if (*(int *)(iVar2 + 0x30) == 0) {
    iVar4 = (**(code **)(*(int *)(param_1 + 0x1b0) + 0xc))
                      (param_1,*(undefined4 *)(iVar2 + 0x38 + *(int *)(iVar2 + 0x40) * 4));
    if (iVar4 == 0) {
      return;
    }
    *(undefined4 *)(iVar2 + 0x30) = 1;
    *(int *)(iVar2 + 0x4c) = *(int *)(iVar2 + 0x4c) + 1;
  }
  iVar4 = *(int *)(iVar2 + 0x44);
  if (iVar4 != 0) {
    if (iVar4 == 1) goto LAB_0094f9f2;
    if (iVar4 != 2) {
      return;
    }
    (**(code **)(*(int *)(param_1 + 0x1b4) + 4))
              (param_1,*(undefined4 *)(iVar2 + 0x38 + *(int *)(iVar2 + 0x40) * 4),
               (uint *)(iVar2 + 0x34),*(undefined4 *)(iVar2 + 0x48),param_2,param_3,param_4);
    if (*(uint *)(iVar2 + 0x34) < *(uint *)(iVar2 + 0x48)) {
      return;
    }
    uVar3 = *param_3;
    *(undefined4 *)(iVar2 + 0x44) = 0;
    if (param_4 <= uVar3) {
      return;
    }
  }
  *(int *)(iVar2 + 0x48) = *(int *)(param_1 + 0x140) + -1;
  iVar4 = *(int *)(param_1 + 0x144);
  *(undefined4 *)(iVar2 + 0x34) = 0;
  if (*(int *)(iVar2 + 0x4c) == iVar4) {
    FUN_0094f800();
  }
  *(undefined4 *)(iVar2 + 0x44) = 1;
LAB_0094f9f2:
  puVar1 = (uint *)(iVar2 + 0x34);
  (**(code **)(*(int *)(param_1 + 0x1b4) + 4))
            (param_1,*(undefined4 *)(iVar2 + 0x38 + *(int *)(iVar2 + 0x40) * 4),puVar1,
             *(undefined4 *)(iVar2 + 0x48),param_2,param_3,param_4);
  if (*(uint *)(iVar2 + 0x48) <= *puVar1) {
    if (*(int *)(iVar2 + 0x4c) == 1) {
      FUN_0094f720();
    }
    iVar4 = *(int *)(param_1 + 0x140);
    *(uint *)(iVar2 + 0x40) = *(uint *)(iVar2 + 0x40) ^ 1;
    *(undefined4 *)(iVar2 + 0x30) = 0;
    *puVar1 = iVar4 + 1;
    *(int *)(iVar2 + 0x48) = iVar4 + 2;
    *(undefined4 *)(iVar2 + 0x44) = 2;
  }
  return;
}


// ==== FUN_0094fa60 @ 0x0094fa60 ====

void FUN_0094fa60(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = param_1[0x6b];
  if (param_2 != 0) {
    puVar2 = (undefined4 *)*param_1;
    puVar2[5] = 4;
    (*(code *)*puVar2)(param_1);
    return;
  }
  if (*(int *)(param_1[0x72] + 8) == 0) {
    *(undefined4 *)(iVar1 + 0x30) = 0;
    *(undefined4 *)(iVar1 + 0x34) = 0;
    *(code **)(iVar1 + 4) = FUN_0094f8b0;
    return;
  }
  *(code **)(iVar1 + 4) = FUN_0094f930;
  FUN_0094f5e0();
  *(undefined4 *)(iVar1 + 0x40) = 0;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x4c) = 0;
  *(undefined4 *)(iVar1 + 0x30) = 0;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  return;
}


// ==== FUN_0094fad0 @ 0x0094fad0 ====

void FUN_0094fad0(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  
  piVar3 = param_1;
  puVar4 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x50);
  param_1[0x6b] = (int)puVar4;
  *puVar4 = FUN_0094fa60;
  if (param_2 != 0) {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 4;
    (*(code *)*puVar1)(param_1);
  }
  if (*(int *)(param_1[0x72] + 8) == 0) {
    param_1 = (int *)param_1[0x50];
  }
  else {
    if (param_1[0x50] < 2) {
      puVar1 = (undefined4 *)*param_1;
      puVar1[5] = 0x2f;
      (*(code *)*puVar1)(param_1);
    }
    FUN_0094f530();
    param_1 = (int *)(param_1[0x50] + 2);
  }
  param_2 = 0;
  if (0 < piVar3[9]) {
    piVar6 = (int *)(piVar3[0x37] + 0x24);
    puVar4 = puVar4 + 2;
    do {
      uVar5 = (**(code **)(piVar3[1] + 8))
                        (piVar3,1,piVar6[-2] * *piVar6,
                         ((piVar6[-6] * *piVar6) / piVar3[0x50]) * (int)param_1);
      iVar2 = piVar3[9];
      *puVar4 = uVar5;
      param_2 = param_2 + 1;
      puVar4 = puVar4 + 1;
      piVar6 = piVar6 + 0x15;
    } while (param_2 < iVar2);
  }
  return;
}


// ==== FUN_0094fbb0 @ 0x0094fbb0 ====

void FUN_0094fbb0(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  
  iVar1 = *(int *)(in_ECX + 0x1b0);
  uVar2 = 1;
  if (*(int *)(in_ECX + 0x14c) < 2) {
    if (*(uint *)(in_ECX + 0x98) < *(int *)(in_ECX + 0x144) - 1U) {
      *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(*(int *)(in_ECX + 0x150) + 0xc);
      *(undefined4 *)(iVar1 + 0x14) = 0;
      *(undefined4 *)(iVar1 + 0x18) = 0;
      return;
    }
    uVar2 = *(undefined4 *)(*(int *)(in_ECX + 0x150) + 0x48);
  }
  *(undefined4 *)(iVar1 + 0x1c) = uVar2;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  return;
}


// ==== FUN_0094fc00 @ 0x0094fc00 ====

void FUN_0094fc00(int param_1)

{
  *(undefined4 *)(param_1 + 0x98) = 0;
  FUN_0094fbb0();
  return;
}


// ==== FUN_0094fc20 @ 0x0094fc20 ====

undefined4 FUN_0094fc20(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 *puVar11;
  int local_30;
  int local_2c;
  int local_28;
  int *local_1c;
  int local_18;
  int local_14;
  uint local_c;
  int local_8;
  
  iVar1 = *(int *)(param_1 + 0x144);
  uVar8 = *(int *)(param_1 + 0x160) - 1;
  iVar2 = *(int *)(param_1 + 0x1b0);
  local_8 = *(int *)(iVar2 + 0x18);
  if (local_8 < *(int *)(iVar2 + 0x1c)) {
    do {
      local_c = *(uint *)(iVar2 + 0x14);
      if (local_c <= uVar8) {
        do {
          FUN_0090b7b0(*(undefined4 *)(iVar2 + 0x20),*(int *)(param_1 + 0x168) << 7);
          iVar6 = (**(code **)(*(int *)(param_1 + 0x1c0) + 4))(param_1,iVar2 + 0x20);
          if (iVar6 == 0) {
            *(uint *)(iVar2 + 0x14) = local_c;
            *(int *)(iVar2 + 0x18) = local_8;
            return 0;
          }
          iVar6 = 0;
          local_14 = 0;
          local_30 = 0;
          if (0 < *(int *)(param_1 + 0x14c)) {
            local_1c = (int *)(param_1 + 0x150);
            do {
              iVar3 = *local_1c;
              if (*(int *)(iVar3 + 0x30) == 0) {
                iVar6 = iVar6 + *(int *)(iVar3 + 0x3c);
                local_14 = iVar6;
              }
              else {
                iVar7 = *(int *)(iVar3 + 4) * 4;
                pcVar4 = *(code **)(*(int *)(param_1 + 0x1c4) + 4 + iVar7);
                if (local_c < uVar8) {
                  iVar10 = *(int *)(iVar3 + 0x34);
                }
                else {
                  iVar10 = *(int *)(iVar3 + 0x44);
                }
                iVar5 = *(int *)(iVar3 + 0x40);
                local_18 = *(int *)(iVar7 + param_2) + *(int *)(iVar3 + 0x24) * local_8 * 4;
                local_2c = 0;
                if (0 < *(int *)(iVar3 + 0x38)) {
                  do {
                    if (((*(uint *)(param_1 + 0x98) < iVar1 - 1U) ||
                        (local_8 + local_2c < *(int *)(iVar3 + 0x48))) && (0 < iVar10)) {
                      puVar11 = (undefined4 *)(iVar2 + 0x20 + iVar6 * 4);
                      iVar6 = iVar5 * local_c;
                      local_28 = iVar10;
                      do {
                        (*pcVar4)(param_1,iVar3,*puVar11,local_18,iVar6);
                        iVar6 = iVar6 + *(int *)(iVar3 + 0x24);
                        puVar11 = puVar11 + 1;
                        local_28 = local_28 + -1;
                      } while (local_28 != 0);
                      iVar6 = local_14;
                    }
                    iVar6 = iVar6 + *(int *)(iVar3 + 0x34);
                    local_18 = local_18 + *(int *)(iVar3 + 0x24) * 4;
                    local_2c = local_2c + 1;
                    local_14 = iVar6;
                  } while (local_2c < *(int *)(iVar3 + 0x38));
                }
              }
              local_30 = local_30 + 1;
              local_1c = local_1c + 1;
            } while (local_30 < *(int *)(param_1 + 0x14c));
          }
          local_c = local_c + 1;
        } while (local_c <= uVar8);
      }
      *(undefined4 *)(iVar2 + 0x14) = 0;
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(iVar2 + 0x1c));
  }
  *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + 1;
  uVar8 = *(int *)(param_1 + 0x98) + 1;
  *(uint *)(param_1 + 0x98) = uVar8;
  if (*(uint *)(param_1 + 0x144) <= uVar8) {
    (**(code **)(*(int *)(param_1 + 0x1b8) + 0xc))(param_1);
    return 4;
  }
  iVar1 = *(int *)(param_1 + 0x1b0);
  if (1 < *(int *)(param_1 + 0x14c)) {
    *(undefined4 *)(iVar1 + 0x1c) = 1;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(iVar1 + 0x18) = 0;
    return 3;
  }
  if (uVar8 < *(uint *)(param_1 + 0x144) - 1) {
    uVar9 = *(undefined4 *)(*(int *)(param_1 + 0x150) + 0xc);
  }
  else {
    uVar9 = *(undefined4 *)(*(int *)(param_1 + 0x150) + 0x48);
  }
  *(undefined4 *)(iVar1 + 0x1c) = uVar9;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  return 3;
}


// ==== FUN_0094fe90 @ 0x0094fe90 ====

undefined4 FUN_0094fe90(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int aiStack_38 [4];
  int local_28;
  int local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int *local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  local_8 = *(int *)(param_1 + 0x1b0);
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x14c)) {
    local_c = (int *)(param_1 + 0x150);
    do {
      iVar1 = *(int *)(*local_c + 0xc);
      iVar1 = (**(code **)(*(int *)(param_1 + 4) + 0x20))
                        (param_1,*(undefined4 *)(local_8 + 0x48 + *(int *)(*local_c + 4) * 4),
                         *(int *)(param_1 + 0x98) * iVar1,iVar1,1);
      aiStack_38[iVar6] = iVar1;
      iVar6 = iVar6 + 1;
      local_c = local_c + 1;
    } while (iVar6 < *(int *)(param_1 + 0x14c));
  }
  local_c = *(int **)(local_8 + 0x18);
  if ((int)local_c < *(int *)(local_8 + 0x1c)) {
    do {
      uVar8 = *(uint *)(local_8 + 0x14);
      local_20 = uVar8;
      if (uVar8 < *(uint *)(param_1 + 0x160)) {
        do {
          iVar6 = *(int *)(param_1 + 0x14c);
          local_10 = 0;
          local_1c = 0;
          if (0 < iVar6) {
            local_28 = iVar6;
            local_14 = (int *)(param_1 + 0x150);
            do {
              iVar1 = *(int *)(*local_14 + 0x34);
              iVar2 = *(int *)(*local_14 + 0x38);
              if (0 < iVar2) {
                local_24 = iVar1 * uVar8 * 0x80;
                piVar7 = (int *)(aiStack_38[local_1c] + (int)local_c * 4);
                local_18 = iVar2;
                do {
                  iVar2 = *piVar7 + local_24;
                  if (0 < iVar1) {
                    piVar3 = (int *)(local_8 + 0x20 + local_10 * 4);
                    local_10 = local_10 + iVar1;
                    iVar4 = iVar1;
                    do {
                      *piVar3 = iVar2;
                      piVar3 = piVar3 + 1;
                      iVar2 = iVar2 + 0x80;
                      iVar4 = iVar4 + -1;
                    } while (iVar4 != 0);
                  }
                  piVar7 = piVar7 + 1;
                  local_18 = local_18 + -1;
                } while (local_18 != 0);
              }
              local_1c = local_1c + 1;
              local_14 = local_14 + 1;
            } while (local_1c < iVar6);
          }
          local_20 = uVar8;
          iVar6 = (**(code **)(*(int *)(param_1 + 0x1c0) + 4))(param_1,local_8 + 0x20);
          if (iVar6 == 0) {
            *(uint *)(local_8 + 0x14) = uVar8;
            *(int **)(local_8 + 0x18) = local_c;
            return 0;
          }
          uVar8 = uVar8 + 1;
          local_20 = uVar8;
        } while (uVar8 < *(uint *)(param_1 + 0x160));
      }
      *(undefined4 *)(local_8 + 0x14) = 0;
      local_c = (int *)((int)local_c + 1);
    } while ((int)local_c < *(int *)(local_8 + 0x1c));
  }
  uVar8 = *(int *)(param_1 + 0x98) + 1;
  *(uint *)(param_1 + 0x98) = uVar8;
  if (*(uint *)(param_1 + 0x144) <= uVar8) {
    (**(code **)(*(int *)(param_1 + 0x1b8) + 0xc))(param_1);
    return 4;
  }
  iVar6 = *(int *)(param_1 + 0x1b0);
  if (1 < *(int *)(param_1 + 0x14c)) {
    *(undefined4 *)(iVar6 + 0x1c) = 1;
    *(undefined4 *)(iVar6 + 0x14) = 0;
    *(undefined4 *)(iVar6 + 0x18) = 0;
    return 3;
  }
  if (uVar8 < *(uint *)(param_1 + 0x144) - 1) {
    uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x150) + 0xc);
  }
  else {
    uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x150) + 0x48);
  }
  *(undefined4 *)(iVar6 + 0x1c) = uVar5;
  *(undefined4 *)(iVar6 + 0x14) = 0;
  *(undefined4 *)(iVar6 + 0x18) = 0;
  return 3;
}


