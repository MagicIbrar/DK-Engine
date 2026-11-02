// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x920000-0x92ffff

// ==== FUN_00920075 @ 0x00920075 ====

undefined4 FUN_00920075(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 extraout_EAX;
  int in_ECX;
  uint uVar6;
  undefined4 *puVar7;
  int local_20;
  int local_1c;
  uint local_18;
  void *local_14;
  uint local_10;
  undefined4 *local_c;
  void *local_8;
  
  local_14 = (void *)0x0;
  local_8 = (void *)0x0;
  local_c = (undefined4 *)0x0;
  iVar3 = FUN_00915e19();
  if ((-1 < iVar3) && (iVar3 = FUN_00919c3e(), -1 < iVar3)) {
    if ((*(uint *)(in_ECX + 0x6c) & 0xc000000) != 0) {
      uVar4 = 0;
      if (*(int *)(in_ECX + 0xc) != 0) {
        do {
          iVar3 = uVar4 * 4;
          uVar4 = uVar4 + 1;
          *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x18) + iVar3) + 0x2c) = 0;
        } while (uVar4 < *(uint *)(in_ECX + 0xc));
      }
      iVar3 = *(int *)(in_ECX + 0xc);
      while (iVar3 != 0) {
        iVar3 = iVar3 + -1;
        puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar3 * 4);
        uVar4 = *puVar1 & 0xfff00000;
        if (uVar4 != 0) {
          uVar6 = puVar1[0xb];
          if (((*puVar1 & 0xf0000000) == 0x60000000) || (uVar4 == 0x11000000)) {
            puVar1[0xb] = uVar6 + 1;
            uVar6 = uVar6 + 2;
          }
          uVar4 = 0;
          if (puVar1[5] != 0) {
            do {
              iVar2 = *(int *)(*(int *)(in_ECX + 0x18) + *(int *)(puVar1[6] + uVar4 * 4) * 4);
              if (*(uint *)(iVar2 + 0x2c) < uVar6) {
                *(uint *)(iVar2 + 0x2c) = uVar6;
              }
              uVar4 = uVar4 + 1;
            } while (uVar4 < puVar1[5]);
          }
        }
      }
    }
    local_1c = 0;
    local_10 = 0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_10 * 4);
        local_18 = *puVar1 & 0xfff00000;
        if (local_18 != 0) {
          uVar4 = *(uint *)puVar1[4];
          local_20 = *(int *)(*(int *)(in_ECX + 0x14) + uVar4 * 4);
          if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(local_20 + 4) * 4) + 4) & 8) ==
              0) {
            if (((local_18 == 0x20700000) || (local_18 == 0x20800000)) || (local_18 == 0x11500000))
            {
              iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar1[2] * 4);
            }
            else {
              iVar3 = local_20;
            }
            uVar4 = *(uint *)(iVar3 + 0x14);
          }
          puVar1[0xd] = uVar4;
          if (uVar4 != 0xffffffff) {
            local_1c = 1;
          }
        }
        local_10 = local_10 + 1;
      } while (local_10 < *(uint *)(in_ECX + 0xc));
    }
    uVar4 = 0;
    if ((*(byte *)(in_ECX + 0xcc) & 4) != 0) {
      return 1;
    }
    uVar6 = *(int *)(in_ECX + 0xc) << 2;
    if (local_1c == 0) {
      local_10 = 0;
      local_14 = operator_new(uVar6);
      if (((local_14 != (void *)0x0) &&
          (local_8 = operator_new(*(int *)(in_ECX + 0xc) << 2), local_8 != (void *)0x0)) &&
         (local_c = operator_new(*(int *)(in_ECX + 0xc) << 2), local_c != (undefined4 *)0x0)) {
        uVar6 = 0;
        if (*(int *)(in_ECX + 0xc) != 0) {
          do {
            iVar3 = *(int *)(*(int *)(in_ECX + 0x18) + uVar6 * 4);
            *(undefined4 *)(iVar3 + 0x38) = 0xffffffff;
            *(undefined4 *)(iVar3 + 0x24) = 0;
            if (((*(ushort *)(iVar3 + 2) & 0xfff0) != 0) && (*(int *)(iVar3 + 0x1c) == 0)) {
              *(uint *)((int)local_14 + local_10 * 4) = uVar6;
              local_10 = local_10 + 1;
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 < *(uint *)(in_ECX + 0xc));
        }
        local_20 = 0;
        if (local_10 != 0) {
          do {
            iVar3 = FUN_00918735(*(undefined4 *)((int)local_14 + uVar4 * 4),local_8,&local_20);
            if (iVar3 < 0) goto LAB_0092038f;
            uVar4 = uVar4 + 1;
          } while (uVar4 < local_10);
        }
        uVar4 = 0;
        if (*(int *)(in_ECX + 0xc) != 0) {
          puVar5 = local_c;
          do {
            *puVar5 = *(undefined4 *)
                       (*(int *)(in_ECX + 0x18) +
                       *(int *)((int)puVar5 + ((int)local_8 - (int)local_c)) * 4);
            uVar4 = uVar4 + 1;
            puVar5 = puVar5 + 1;
          } while (uVar4 < *(uint *)(in_ECX + 0xc));
        }
        puVar5 = local_c;
        puVar7 = *(undefined4 **)(in_ECX + 0x18);
        for (uVar4 = *(uint *)(in_ECX + 0xc) & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar7 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar7 = puVar7 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(undefined1 *)puVar7 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
      }
    }
    else {
      local_8 = operator_new(uVar6);
      if (((local_8 != (void *)0x0) &&
          (local_c = operator_new(*(int *)(in_ECX + 0xc) << 2), local_c != (undefined4 *)0x0)) &&
         (iVar3 = FUN_009198e4(), -1 < iVar3)) {
        uVar4 = 0;
        if (*(int *)(in_ECX + 0xc) != 0) {
          do {
            *(uint *)((int)local_8 + uVar4 * 4) = uVar4;
            uVar4 = uVar4 + 1;
          } while (uVar4 < *(uint *)(in_ECX + 0xc));
        }
        FUN_00915b0e(FUN_00915809,local_8,*(undefined4 *)(in_ECX + 0xc),in_ECX);
        uVar4 = 0;
        if (*(int *)(in_ECX + 0xc) != 0) {
          puVar5 = local_c;
          do {
            *puVar5 = *(undefined4 *)
                       (*(int *)(in_ECX + 0x18) +
                       *(int *)(((int)local_8 - (int)local_c) + (int)puVar5) * 4);
            uVar4 = uVar4 + 1;
            puVar5 = puVar5 + 1;
          } while (uVar4 < *(uint *)(in_ECX + 0xc));
        }
        puVar5 = local_c;
        puVar7 = *(undefined4 **)(in_ECX + 0x18);
        for (uVar4 = *(uint *)(in_ECX + 0xc) & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar7 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar7 = puVar7 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(undefined1 *)puVar7 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        iVar3 = FUN_00919c3e();
        if (-1 < iVar3) {
          (*(code *)PTR_FUN_00a295a4)(1);
        }
      }
    }
  }
LAB_0092038f:
  _free(local_14);
  return extraout_EAX;
}


// ==== FUN_009203b1 @ 0x009203b1 ====

undefined4 FUN_009203b1(void)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  undefined1 local_34 [16];
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  int *local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  FUN_009198e4();
  local_c = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + local_c * 4);
      uVar3 = *puVar2;
      local_8 = uVar3 & 0xfff00000;
      if (local_8 != 0) {
        uVar6 = uVar3 & 0xfffff;
        local_1c = puVar2[1] / uVar6;
        if (local_8 == 0x50000000) {
          FUN_00919678(puVar2[2] + uVar6 * 4,local_34,uVar6,1);
          FUN_00919678(puVar2[2],local_34,uVar6,0);
        }
        else if ((0xfffffff < (uVar3 & 0xf0000000)) && ((uVar3 & 0xf0000000) < 0x40000001)) {
          FUN_00919678(puVar2[4],local_34,uVar6,1);
          local_8 = 0;
          if (local_1c != 0) {
            do {
              FUN_00919678(puVar2[2] + puVar2[3] * local_8 * 4,local_34,uVar6,0);
              local_8 = local_8 + 1;
            } while (local_8 < local_1c);
          }
        }
        if (((*puVar2 & 0xf0000000) == 0x20000000) && (iVar5 = FUN_0091464c(), iVar5 != 0)) {
          iVar5 = *(int *)(in_ECX + 0x14);
          local_24 = *(int *)(iVar5 + *(int *)puVar2[2] * 4);
          iVar4 = *(int *)(iVar5 + ((int *)puVar2[2])[uVar6] * 4);
          local_18 = 0xffffffff;
          local_8 = 0xffffffff;
          if (uVar6 == 0) {
LAB_0092051d:
            local_20 = *(int *)(local_24 + 4) * 4;
            iVar5 = *(int *)(iVar4 + 4) * 4;
            if ((*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + iVar5) + 4) <=
                 *(uint *)(*(int *)(local_20 + *(int *)(in_ECX + 0x10)) + 4)) &&
               ((*(int *)(*(int *)(*(int *)(in_ECX + 0x10) + local_20) + 4) !=
                 *(int *)(*(int *)(*(int *)(in_ECX + 0x10) + iVar5) + 4) ||
                ((*(uint *)(iVar4 + 4) <= *(uint *)(local_24 + 4) &&
                 ((*(uint *)(local_24 + 4) != *(uint *)(iVar4 + 4) ||
                  (*(uint *)(iVar4 + 0xc) <= *(uint *)(local_24 + 0xc))))))))) {
LAB_00920576:
              local_8 = 0;
              if (uVar6 != 0) {
                local_24 = uVar6 << 2;
                do {
                  uVar3 = local_8 + 1;
                  piVar1 = (int *)(puVar2[2] + local_8 * 4);
                  local_20 = *piVar1;
                  *piVar1 = *(int *)(local_24 + puVar2[2]);
                  *(uint *)(local_24 + puVar2[2]) = local_20;
                  local_24 = local_24 + 4;
                  local_8 = uVar3;
                } while (uVar3 < uVar6);
              }
            }
          }
          else {
            local_10 = (int *)puVar2[2];
            local_14 = local_10 + uVar6;
            local_20 = uVar6;
            do {
              uVar3 = *(uint *)(*(int *)(iVar5 + *local_10 * 4) + 0x48);
              if (uVar3 < local_18) {
                local_18 = uVar3;
              }
              uVar3 = *(uint *)(*(int *)(iVar5 + *local_14 * 4) + 0x48);
              if (uVar3 < local_8) {
                local_8 = uVar3;
              }
              local_10 = local_10 + 1;
              local_14 = local_14 + 1;
              local_20 = local_20 - 1;
            } while (local_20 != 0);
            local_20 = 0;
            if (local_8 <= local_18) {
              if (local_18 == local_8) goto LAB_0092051d;
              goto LAB_00920576;
            }
          }
        }
      }
      local_c = local_c + 1;
    } while (local_c < *(uint *)(in_ECX + 0xc));
  }
  return 0;
}


// ==== FUN_009205c9 @ 0x009205c9 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_009205c9(uint *param_1,uint param_2,int param_3,int *param_4,uint *param_5,uint param_6,
            uint param_7)

{
  int *piVar1;
  double *pdVar2;
  double dVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  undefined4 uVar9;
  int in_ECX;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  uint *puVar13;
  bool bVar14;
  uint local_d0 [4];
  double local_c0 [4];
  double adStack_a0 [4];
  undefined8 local_80;
  undefined8 local_78;
  int local_70;
  uint local_6c [4];
  uint *local_5c;
  uint *local_58;
  undefined8 local_54;
  undefined8 local_4c;
  uint *local_44;
  uint local_40 [4];
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  uint *local_1c;
  uint local_18;
  int *local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  if (param_2 == 0) {
    return 1;
  }
  if (4 < param_2) {
    return 0;
  }
  uVar12 = 1;
  if (1 < param_2) {
    do {
      iVar6 = FUN_00918d20(*param_1,param_1[uVar12]);
      if (iVar6 == 0) break;
      uVar12 = uVar12 + 1;
    } while (uVar12 < param_2);
  }
  if (uVar12 != param_2) {
    puVar13 = param_1;
    puVar7 = local_40;
    for (uVar12 = param_2 & 0x3fffffff; uVar12 != 0; uVar12 = uVar12 - 1) {
      *puVar7 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar7 = puVar7 + 1;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(char *)puVar7 = (char)*puVar13;
      puVar13 = (uint *)((int)puVar13 + 1);
      puVar7 = (uint *)((int)puVar7 + 1);
    }
    local_30 = param_2 << 2;
    puVar13 = local_6c;
    for (uVar12 = param_2 & 0x3fffffff; uVar12 != 0; uVar12 = uVar12 - 1) {
      *puVar13 = 0;
      puVar13 = puVar13 + 1;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined1 *)puVar13 = 0;
      puVar13 = (uint *)((int)puVar13 + 1);
    }
    if ((param_3 == 0) || (local_20 = 0, (*param_5 & 0xfff00000) == 0x11200000)) {
      local_20 = 1;
    }
    local_10 = 0;
    local_8 = 0;
    if (param_2 != 0) {
      puVar13 = local_40;
      local_1c = puVar13;
LAB_00920687:
      uVar12 = *puVar13;
      local_1c = puVar13;
LAB_00920689:
      local_24 = uVar12;
      iVar6 = FUN_00918cb6(uVar12,param_5,param_6,param_7);
      if (iVar6 != 0) {
        local_54 = 1.0;
        local_4c = 0.0;
        if (uVar12 != 0xffffffff) {
          piVar11 = *(int **)(in_ECX + 0x14);
          do {
            if (((*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(piVar11[uVar12] + 4) * 4) +
                           4) & 0x100) != 0) && (*(int *)(piVar11[uVar12] + 8) == -1)) {
              if ((_DAT_0099d0a0 == local_54) && (_DAT_0099d098 == local_4c)) goto LAB_0092078b;
              piVar1 = piVar11 + uVar12;
              uVar12 = 0;
              bVar14 = *(int *)(in_ECX + 8) == 0;
              dVar3 = local_54 * *(double *)(*piVar1 + 0x20) + local_4c;
              if (*(int *)(in_ECX + 8) == 0) goto LAB_00920766;
              local_14 = piVar11;
              goto LAB_00920732;
            }
            uVar12 = FUN_00918d73(uVar12,&local_54,&local_4c);
          } while (uVar12 != 0xffffffff);
          puVar13 = local_1c;
        }
      }
      goto LAB_009207b0;
    }
LAB_009207de:
    if (local_10 != param_2) {
      local_c = 0;
      if (param_2 != 0) {
LAB_009207f5:
        local_58 = local_6c + local_c;
        if (local_6c[local_c] == 0) {
          uVar12 = local_40[local_c];
          local_5c = local_40 + local_c;
          iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + uVar12 * 4);
          if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar6 + 4) * 4) + 5) & 1) == 0
              ) || (*(int *)(iVar6 + 8) != -1)) {
            local_18 = 0xffffffff;
            local_1c = (uint *)0x0;
            local_24 = 0;
            local_10 = uVar12;
            do {
              iVar6 = FUN_00918cb6(local_10,param_5,param_6,param_7);
              if (iVar6 != 0) {
                local_4c = 1.0;
                local_54 = 0.0;
                for (local_28 = local_10; local_28 != 0xffffffff;
                    local_28 = FUN_00918d73(local_28,&local_4c,&local_54)) {
                  local_14 = (int *)0x0;
                  local_8 = 0;
                  if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + local_28 * 4) + 0x48) == -1) {
                    local_8 = 0xffffffff;
                  }
                  local_2c = 0;
                  do {
                    if (local_6c[local_2c] == 0) {
                      puVar13 = (uint *)local_40[local_2c];
                      local_44 = puVar13;
                      while (puVar13 != (uint *)0xffffffff) {
                        iVar6 = FUN_00918cb6(puVar13,param_5,param_6,param_7);
                        puVar7 = puVar13;
                        if (iVar6 != 0) {
                          for (; puVar7 != (uint *)0xffffffff;
                              puVar7 = (uint *)FUN_00918d73(puVar7,0,0)) {
                            iVar6 = FUN_00918d20(local_28,puVar7);
                            if (iVar6 != 0) {
                              local_14 = (int *)((int)local_14 + 1);
                              if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + (int)puVar7 * 4) +
                                          0x48) != -1) {
                                iVar6 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + (int)puVar7 * 4)
                                                + 0x48) - param_6;
                                local_8 = local_8 + iVar6 * iVar6;
                              }
LAB_00920915:
                              if (puVar7 != (uint *)0xffffffff) goto LAB_00920933;
                              break;
                            }
                            if (local_20 != 0) {
                              puVar7 = (uint *)0xffffffff;
                              goto LAB_00920915;
                            }
                          }
                        }
                        puVar13 = *(uint **)(*(int *)(*(int *)(in_ECX + 0x14) + (int)puVar13 * 4) +
                                            0x34);
                        if (local_44 == puVar13) break;
                      }
                    }
LAB_00920933:
                    local_2c = local_2c + 1;
                  } while (local_2c < param_2);
                  if ((local_1c < local_14) ||
                     ((local_1c == (uint *)local_14 && (local_24 < local_8)))) {
                    local_78 = local_4c;
                    local_1c = (uint *)local_14;
                    local_80 = local_54;
                    local_18 = local_28;
                    local_24 = local_8;
                  }
                  if (local_20 != 0) break;
                }
              }
              uVar12 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + local_10 * 4) + 0x34);
              if (*local_5c == uVar12) goto LAB_009209ae;
              local_10 = uVar12;
            } while( true );
          }
        }
        goto LAB_00920ab1;
      }
LAB_00920ac2:
      uVar12 = 0;
      bVar14 = false;
      local_14 = (int *)0x0;
      local_1c = (uint *)0x0;
      local_2c = 0;
      if (param_2 != 0) {
        do {
          iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + local_40[uVar12] * 4);
          iVar8 = FUN_00918d20(local_40[uVar12],local_40[0]);
          if (iVar8 == 0) {
            bVar14 = true;
          }
          if (_DAT_0099d0a0 != local_c0[uVar12]) {
            local_14 = (int *)0x1;
          }
          if (_DAT_0099d098 != adStack_a0[uVar12]) {
            local_1c = (uint *)0x1;
          }
          if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar6 + 4) * 4) + 5) & 1) != 0
              ) && (*(int *)(iVar6 + 8) == -1)) {
            local_2c = 1;
          }
          uVar12 = uVar12 + 1;
        } while (uVar12 < param_2);
        if (((local_14 != (int *)0x0) || (local_1c != (uint *)0x0)) || (bVar14)) {
          if (local_20 == 0) {
            param_7 = 0;
            local_c = 0;
            local_10 = (*(int *)(in_ECX + 0x6c) << 0x1d) >> 0x1f;
            param_6 = 0;
            do {
              iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + local_40[local_c] * 4);
              uVar12 = 0;
              if ((local_10 == 0) && ((*(byte *)(in_ECX + 0x6c) & 2) == 0)) {
                iVar8 = *(int *)(iVar6 + 4);
                if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + iVar8 * 4) + 5) & 1) == 0) ||
                   (*(int *)(iVar6 + 8) != -1)) {
                  if (param_6 != 0) {
                    do {
                      iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + local_40[uVar12] * 4);
                      if (((*(double *)((int)local_c0 + param_6) == local_c0[uVar12]) &&
                          (*(double *)((int)adStack_a0 + param_6) == adStack_a0[uVar12])) &&
                         ((iVar8 == *(int *)(iVar4 + 4) &&
                          (((*(int *)(iVar6 + 8) == *(int *)(iVar4 + 8) &&
                            (*(int *)(iVar6 + 0xc) == *(int *)(iVar4 + 0xc))) &&
                           (*(int *)(iVar6 + 0x10) == *(int *)(iVar4 + 0x10))))))) break;
                      uVar12 = uVar12 + 1;
                    } while (uVar12 < local_c);
                  }
                }
                else if (param_6 != 0) {
                  do {
                    iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + local_40[uVar12] * 4);
                    if (((iVar8 == *(int *)(iVar4 + 4)) && (*(int *)(iVar4 + 8) == -1)) &&
                       (*(double *)(iVar6 + 0x20) == *(double *)(iVar4 + 0x20))) break;
                    uVar12 = uVar12 + 1;
                  } while (uVar12 < local_c);
                }
              }
              else {
                uVar12 = local_c;
              }
              local_d0[local_c] = uVar12;
              uVar10 = local_30;
              if (local_c == uVar12) {
                param_7 = param_7 + 1;
              }
              param_6 = param_6 + 8;
              local_c = local_c + 1;
            } while (local_c < param_2);
            local_24 = 0xffffffff;
            bVar14 = true;
            local_8 = 0;
            local_c = 0;
            do {
              if (local_c == local_d0[local_c]) {
                iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + local_40[local_c] * 4);
                if (*(int *)(in_ECX + 0x88) == *(int *)(iVar6 + 4)) {
                  local_18 = param_7;
                  uVar12 = 0;
                  do {
                    if (((uVar12 == local_d0[uVar12]) &&
                        (iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + local_40[uVar12] * 4),
                        *(int *)(in_ECX + 0x88) == *(int *)(iVar8 + 4))) &&
                       ((*(int *)(iVar6 + 0xc) == *(int *)(iVar8 + 0xc) &&
                        ((_DAT_0099d0a0 == local_c0[uVar12] && (_DAT_0099d098 == adStack_a0[uVar12])
                         ))))) {
                      local_18 = local_18 - 1;
                    }
                    uVar12 = uVar12 + 1;
                  } while (uVar12 < param_2);
                  if ((*(int *)(param_3 + *(int *)(iVar6 + 0xc) * 4) + local_18 < 5) &&
                     (local_18 < local_24)) {
                    bVar14 = false;
                    local_24 = local_18;
                    local_8 = local_c;
                  }
                }
              }
              local_c = local_c + 1;
            } while (local_c < param_2);
            if ((((local_10 != 0) || ((*(byte *)(in_ECX + 0x6c) & 2) != 0)) &&
                (0xfffffff < (*param_5 & 0xf0000000))) && ((*param_5 & 0xf0000000) < 0x40000001)) {
              local_10 = 0;
              do {
                if (bVar14) break;
                iVar6 = *(int *)(in_ECX + 0x14);
                iVar8 = *(int *)(iVar6 + local_40[local_10] * 4);
                if ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar8 + 4) * 4) + 5) &
                      1) == 0) || (*(int *)(iVar8 + 8) == -1)) &&
                   (*(int *)(iVar8 + 0x10) !=
                    *(int *)(*(int *)(iVar6 + *(int *)(local_10 * 4 + param_5[4]) * 4) + 0x10))) {
                  local_18 = 0;
                  param_7 = 0;
                  do {
                    iVar4 = *(int *)(iVar6 + local_40[param_7] * 4);
                    if (((*(int *)(iVar4 + 4) == *(int *)(iVar8 + 4)) &&
                        (*(int *)(iVar4 + 0xc) == *(int *)(iVar8 + 0xc))) &&
                       (*(int *)(iVar4 + 8) == *(int *)(iVar8 + 8))) {
                      local_18 = local_18 + 1;
                    }
                    param_7 = param_7 + 1;
                  } while (param_7 < param_2);
                  if (1 < local_18) {
                    bVar14 = true;
                  }
                }
                local_10 = local_10 + 1;
              } while (local_10 < param_2);
            }
            uVar12 = *param_5 & 0xfff00000;
            if (((((uVar12 == 0x10000000) && ((*(byte *)(in_ECX + 0x6c) & 8) == 0)) &&
                 ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                     *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                      *(int *)param_5[4] * 4) + 4) * 4) + 4) & 0x20)
                  != 0)) || ((uVar12 == 0x11200000 || (uVar12 != 0x10000000)))) ||
               ((local_14 != (int *)0x0 || ((local_1c != (uint *)0x0 || (local_2c != 0)))))) {
              local_70 = -1;
              if (bVar14) {
                iVar6 = *param_4;
                *param_4 = iVar6 + 1;
              }
              else {
                iVar6 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + local_40[local_8] * 4) + 0xc);
              }
              iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)param_5[4] * 4);
              local_58 = (uint *)*(uint *)(iVar8 + 0x14);
              local_5c = (uint *)*(uint *)(iVar8 + 0x18);
              puVar13 = local_6c;
              for (uVar12 = local_30 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
                *puVar13 = 0;
                puVar13 = puVar13 + 1;
              }
              for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
                *(undefined1 *)puVar13 = 0;
                puVar13 = (uint *)((int)puVar13 + 1);
              }
              local_1c = (uint *)iVar6;
              uVar12 = 0;
              do {
                if ((uVar12 != local_d0[uVar12]) ||
                   ((((iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + local_40[uVar12] * 4),
                      *(int *)(in_ECX + 0x88) == *(int *)(iVar8 + 4) &&
                      (iVar6 == *(int *)(iVar8 + 0xc))) && (_DAT_0099d0a0 == local_c0[uVar12])) &&
                    (_DAT_0099d098 == adStack_a0[uVar12])))) {
                  local_6c[uVar12] = 1;
                }
                uVar12 = uVar12 + 1;
              } while (uVar12 < param_2);
              if (!bVar14) {
                local_c = 0;
                do {
                  if (local_6c[local_c] == 0) {
                    uVar12 = local_40[local_c];
                    iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + uVar12 * 4);
                    if (*(int *)(in_ECX + 0x88) == *(int *)(iVar6 + 4)) {
                      local_14 = (int *)0x0;
                      local_18 = 0;
                      param_6 = 0;
                      do {
                        if (local_6c[param_6] == 0) {
                          local_14 = (int *)((int)local_14 + 1);
                          iVar8 = FUN_00918d20(uVar12,local_40[param_6]);
                          if ((iVar8 != 0) &&
                             ((local_18 = local_18 + 1, _DAT_0099d0a0 != local_c0[param_6] ||
                              (_DAT_0099d098 != adStack_a0[param_6])))) break;
                        }
                        param_6 = param_6 + 1;
                      } while (param_6 < param_2);
                      if (param_2 <= param_6) {
                        iVar6 = *(int *)(iVar6 + 0xc);
                        piVar11 = (int *)(param_3 + (int)local_1c * 4);
                        if ((*(int *)(param_3 + iVar6 * 4) - local_18) + *piVar11 + (int)local_14 <
                            5) {
                          uVar12 = 0;
                          do {
                            if (((local_6c[uVar12] == 0) &&
                                (iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + local_40[uVar12] * 4),
                                *(int *)(in_ECX + 0x88) == *(int *)(iVar8 + 4))) &&
                               (iVar6 == *(int *)(iVar8 + 0xc))) {
                              local_6c[uVar12] = 1;
                            }
                            uVar12 = uVar12 + 1;
                          } while (uVar12 < param_2);
                          uVar12 = 0;
                          if (*(int *)(in_ECX + 8) != 0) {
                            do {
                              iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + uVar12 * 4);
                              if ((*(int *)(in_ECX + 0x88) == *(int *)(iVar8 + 4)) &&
                                 (iVar6 == *(int *)(iVar8 + 0xc))) {
                                *(uint **)(iVar8 + 0xc) = local_1c;
                                *(int *)(iVar8 + 0x10) = *(int *)(iVar8 + 0x10) + *piVar11;
                              }
                              uVar12 = uVar12 + 1;
                            } while (uVar12 < *(uint *)(in_ECX + 8));
                          }
                          piVar1 = (int *)(param_3 + iVar6 * 4);
                          *piVar11 = *piVar11 + *piVar1;
                          *piVar1 = 0;
                        }
                      }
                    }
                  }
                  local_c = local_c + 1;
                } while (local_c < param_2);
              }
              if ((*(byte *)(in_ECX + 0x6c) & 6) == 0) {
                local_c = 0;
                do {
                  if (local_6c[local_c] == 0) {
                    puVar13 = local_40 + local_c;
                    uVar12 = *puVar13;
                    iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + uVar12 * 4);
                    if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar6 + 4) * 4) + 5)
                         & 1) == 0) || (*(int *)(iVar6 + 8) != -1)) {
                      param_6 = 0;
                      param_7 = 0;
                      do {
                        if ((local_6c[param_7] == 0) &&
                           (iVar6 = FUN_00918d20(uVar12,local_40[param_7]), iVar6 != 0)) {
                          param_6 = param_6 + 1;
                        }
                        param_7 = param_7 + 1;
                      } while (param_7 < param_2);
                      param_7 = 0;
                      do {
                        if (3 < param_6) break;
                        if (local_6c[param_7] == 0) {
                          iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + local_40[param_7] * 4);
                          if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar6 + 4) * 4
                                                  ) + 5) & 1) != 0) && (*(int *)(iVar6 + 8) == -1))
                          {
                            dVar3 = *(double *)(iVar6 + 0x20);
                            local_40[param_7] = *puVar13;
                            param_6 = param_6 + 1;
                            adStack_a0[param_7] = dVar3 * local_c0[param_7] + adStack_a0[param_7];
                            local_c0[param_7] = 0.0;
                          }
                        }
                        param_7 = param_7 + 1;
                      } while (param_7 < param_2);
                    }
                  }
                  local_c = local_c + 1;
                } while (local_c < param_2);
              }
              local_c = 0;
              do {
                uVar12 = 0;
                if (local_6c[local_c] == 0) {
                  uVar10 = local_40[local_c];
                  local_80 = (double)CONCAT44(uVar10,(undefined4)local_80);
                  param_7 = 0;
                  local_28 = 0;
                  local_18 = 1;
                  local_20 = 0;
                  local_30 = 1;
                  do {
                    if ((local_6c[uVar12] == 0) &&
                       (iVar6 = FUN_00918d20(uVar10,local_40[uVar12]), iVar6 != 0)) {
                      param_7 = param_7 + 1;
                      pdVar2 = local_c0 + uVar12;
                      if (_DAT_0099d0a0 != *pdVar2) {
                        local_28 = 1;
                      }
                      if (_DAT_009fd350 != *pdVar2) {
                        local_18 = 0;
                      }
                      if (_DAT_0099d098 != adStack_a0[uVar12]) {
                        local_20 = 1;
                      }
                      if (_DAT_0099d098 != *pdVar2) {
                        local_30 = 0;
                      }
                    }
                    uVar12 = uVar12 + 1;
                  } while (uVar12 < param_2);
                  if (local_30 != 0) {
                    local_28 = 0;
                    local_20 = 0;
                  }
                  if (local_28 == 0) {
LAB_009212a0:
                    if (local_20 != 0) goto LAB_009212a5;
LAB_009212eb:
                    if ((local_28 == 0) && (local_20 == 0)) {
                      local_24 = FUN_00915378(param_7 & 0xfffff | 0x10000000,0xffffffff,0xffffffff);
                      if (local_24 == 0xffffffff) {
                        return 0;
                      }
                      local_2c = *(uint *)(*(int *)(in_ECX + 0x18) + local_24 * 4);
                      local_10 = local_24;
                      local_8 = local_2c;
                      FUN_00914593();
                    }
                  }
                  else {
                    if (local_18 == 0) {
                      uVar12 = param_7 & 0xfffff | 0x20500000;
                    }
                    else {
                      uVar12 = param_7 & 0xfffff | 0x10100000;
                    }
                    uVar12 = FUN_00915378(uVar12,0xffffffff,0xffffffff);
                    if (uVar12 == 0xffffffff) {
                      return 0;
                    }
                    uVar10 = *(uint *)(*(int *)(in_ECX + 0x18) + uVar12 * 4);
                    local_2c = uVar10;
                    local_10 = uVar12;
                    FUN_00914593();
                    if (local_20 == 0) {
                      local_24 = uVar12;
                      local_8 = uVar10;
                      goto LAB_009212a0;
                    }
LAB_009212a5:
                    uVar12 = FUN_00915378(param_7 & 0xfffff | 0x20400000,0xffffffff,0xffffffff);
                    if (uVar12 == 0xffffffff) {
                      return 0;
                    }
                    uVar10 = *(uint *)(*(int *)(in_ECX + 0x18) + uVar12 * 4);
                    local_24 = uVar12;
                    local_8 = uVar10;
                    FUN_00914593();
                    if (local_28 == 0) {
                      local_10 = uVar12;
                      local_2c = uVar10;
                      goto LAB_009212eb;
                    }
                  }
                  local_14 = (int *)(param_7 << 2);
                  iVar6 = 0;
                  param_6 = 0;
                  local_4c = (double)CONCAT44((int)param_1 - (int)local_40,(undefined4)local_4c);
                  do {
                    local_54 = (double)CONCAT44(local_6c + param_6,(undefined4)local_54);
                    if (local_6c[param_6] == 0) {
                      local_44 = local_40 + param_6;
                      uVar12 = *local_44;
                      iVar8 = FUN_00918d20(local_80._4_4_,uVar12);
                      if (iVar8 != 0) {
                        if (local_30 != 0) {
                          uVar12 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,
                                                adStack_a0[param_6]);
                        }
                        uVar10 = local_2c;
                        if (uVar12 == 0xffffffff) {
                          return 0;
                        }
                        iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + uVar12 * 4);
                        *(uint *)(iVar6 + *(int *)(local_2c + 8)) = uVar12;
                        local_78 = (double)CONCAT44(iVar8,(undefined4)local_78);
                        if (local_30 != 0) {
                          *(uint *)(iVar8 + 0x34) = uVar12;
                        }
                        if (local_28 == 0) {
LAB_009214ad:
                          uVar12 = 0;
                          if (local_20 != 0) {
                            bVar14 = *(int *)(in_ECX + 8) == 0;
                            if (*(int *)(in_ECX + 8) != 0) {
                              piVar11 = *(int **)(in_ECX + 0x14);
                              do {
                                iVar8 = *piVar11;
                                if (((*(int *)(in_ECX + 0x78) == *(int *)(iVar8 + 4)) &&
                                    (*(int *)(iVar8 + 8) == -1)) &&
                                   (*(double *)(iVar8 + 0x20) == adStack_a0[param_6])) break;
                                uVar12 = uVar12 + 1;
                                piVar11 = piVar11 + 1;
                              } while (uVar12 < *(uint *)(in_ECX + 8));
                              bVar14 = uVar12 == *(uint *)(in_ECX + 8);
                            }
                            if (bVar14) {
                              uVar12 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,
                                                    adStack_a0[param_6]);
                              if (uVar12 == 0xffffffff) {
                                return 0;
                              }
                              *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar12 * 4) + 0x34) =
                                   uVar12;
                            }
                            *(uint *)((int)local_14 + *(int *)(local_8 + 8)) = uVar12;
                          }
                        }
                        else {
                          if (local_18 == 0) {
                            uVar9 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,
                                                 local_c0[param_6]);
                            *(undefined4 *)((int)local_14 + *(int *)(uVar10 + 8)) = uVar9;
                            if (*(int *)((int)local_14 + *(int *)(uVar10 + 8)) == -1) {
                              return 0;
                            }
                          }
                          if (local_20 != 0) {
                            if (local_70 == -1) {
                              local_70 = *param_4;
                              *param_4 = local_70 + 1;
                            }
                            puVar13 = (uint *)(param_3 + local_70 * 4);
                            uVar12 = *puVar13;
                            *puVar13 = uVar12 + 1;
                            iVar8 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),local_70,uVar12,0);
                            if (iVar8 == -1) {
                              return 0;
                            }
                            if (4 < *puVar13) {
                              FUN_0091a001();
                            }
                            puVar13 = *(uint **)(*(int *)(in_ECX + 0x14) + iVar8 * 4);
                            puVar13[5] = (uint)local_58;
                            puVar13[6] = (uint)local_5c;
                            *puVar13 = *local_78._4_4_ & 0xe000000;
                            puVar13[0x12] = local_10;
                            *(int *)(iVar6 + *(int *)(local_8 + 8)) = iVar8;
                            *(int *)(iVar6 + *(int *)(local_2c + 0x10)) = iVar8;
                            goto LAB_009214ad;
                          }
                        }
                        puVar13 = (uint *)(param_3 + (int)local_1c * 4);
                        uVar12 = *puVar13;
                        *puVar13 = uVar12 + 1;
                        iVar8 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),local_1c,uVar12,0);
                        if (iVar8 == -1) {
                          return 0;
                        }
                        if (4 < *puVar13) {
                          FUN_0091a001();
                        }
                        puVar5 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar8 * 4);
                        puVar5[5] = local_58;
                        puVar5[6] = local_5c;
                        piVar11 = (int *)(local_4c._4_4_ + (int)local_44);
                        *puVar5 = **(undefined4 **)(*(int *)(in_ECX + 0x14) + *piVar11 * 4);
                        puVar5[0x12] = local_24;
                        *(int *)(iVar6 + *(int *)(local_8 + 0x10)) = iVar8;
                        *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar8 * 4) + 0x34) =
                             *(undefined4 *)
                              (*(int *)(*(int *)(in_ECX + 0x14) + *piVar11 * 4) + 0x34);
                        *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar11 * 4) + 0x34) = iVar8;
                        *local_44 = *(uint *)(iVar6 + *(int *)(local_8 + 0x10));
                        iVar6 = iVar6 + 4;
                        local_14 = (int *)((int)local_14 + 4);
                        *local_54._4_4_ = 1;
                      }
                    }
                    param_6 = param_6 + 1;
                  } while (param_6 < param_2);
                }
                local_c = local_c + 1;
                if (param_2 <= local_c) {
                  iVar6 = (int)local_d0 - (int)param_1;
                  uVar12 = param_2;
                  do {
                    *param_1 = local_40[*(int *)(iVar6 + (int)param_1)];
                    param_1 = param_1 + 1;
                    uVar12 = uVar12 - 1;
                  } while (uVar12 != 0);
                  uVar12 = 0;
                  do {
                    if (local_6c[uVar12] == 0) {
                      return 0;
                    }
                    uVar12 = uVar12 + 1;
                  } while (uVar12 < param_2);
                  return 1;
                }
              } while( true );
            }
            puVar13 = local_40;
            for (uVar12 = local_30 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
              *param_1 = *puVar13;
              puVar13 = puVar13 + 1;
              param_1 = param_1 + 1;
            }
            for (local_30 = local_30 & 3; local_30 != 0; local_30 = local_30 - 1) {
              *(char *)param_1 = (char)*puVar13;
              puVar13 = (uint *)((int)puVar13 + 1);
              param_1 = (uint *)((int)param_1 + 1);
            }
          }
          return 0;
        }
      }
    }
    puVar13 = local_40;
    for (uVar12 = local_30 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
      *param_1 = *puVar13;
      puVar13 = puVar13 + 1;
      param_1 = param_1 + 1;
    }
    for (local_30 = local_30 & 3; local_30 != 0; local_30 = local_30 - 1) {
      *(char *)param_1 = (char)*puVar13;
      puVar13 = (uint *)((int)puVar13 + 1);
      param_1 = (uint *)((int)param_1 + 1);
    }
  }
  return 1;
  while( true ) {
    local_14 = local_14 + 1;
    uVar12 = uVar12 + 1;
    if (*(uint *)(in_ECX + 8) <= uVar12) break;
LAB_00920732:
    iVar6 = *local_14;
    if ((((*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar6 + 4) * 4) + 4) & 0x100) != 0)
        && (*(int *)(iVar6 + 8) == -1)) && (dVar3 == *(double *)(iVar6 + 0x20))) break;
  }
  bVar14 = uVar12 == *(uint *)(in_ECX + 8);
LAB_00920766:
  if ((bVar14) &&
     (uVar12 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,dVar3), uVar12 == 0xffffffff)) {
    return 0;
  }
LAB_0092078b:
  uVar10 = local_8;
  puVar13 = local_1c;
  local_10 = local_10 + 1;
  local_c0[local_8] = 1.0;
  adStack_a0[uVar10] = 0.0;
  *puVar13 = uVar12;
  if (uVar12 != 0xffffffff) goto LAB_009207c7;
LAB_009207b0:
  uVar12 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + local_24 * 4) + 0x34);
  if (*puVar13 == uVar12) goto LAB_009207c7;
  goto LAB_00920689;
LAB_009207c7:
  local_8 = local_8 + 1;
  puVar13 = puVar13 + 1;
  local_1c = puVar13;
  if (param_2 <= local_8) goto LAB_009207de;
  goto LAB_00920687;
LAB_009209ae:
  if (local_18 == 0xffffffff) {
    return 0;
  }
  *local_5c = local_18;
  uVar12 = local_c;
  local_8 = 0;
  local_c0[local_c] = local_78;
  adStack_a0[uVar12] = local_80;
  *local_58 = 1;
  do {
    local_44 = local_6c + local_8;
    if (local_6c[local_8] == 0) {
      puVar13 = local_40 + local_8;
      uVar12 = *puVar13;
      while (local_10 = uVar12, uVar12 != 0xffffffff) {
        iVar6 = FUN_00918cb6(uVar12,param_5,param_6,param_7);
        if (iVar6 != 0) {
          local_54 = 1.0;
          local_4c = 0.0;
          for (uVar12 = local_10; uVar12 != 0xffffffff;
              uVar12 = FUN_00918d73(uVar12,&local_54,&local_4c)) {
            iVar6 = FUN_00918d20(local_18,uVar12);
            uVar10 = local_8;
            if (iVar6 != 0) {
              local_c0[local_8] = local_54;
              *puVar13 = uVar12;
              adStack_a0[uVar10] = local_4c;
              *local_44 = 1;
LAB_00920a81:
              if (uVar12 != 0xffffffff) goto LAB_00920aa2;
              break;
            }
            if (local_20 != 0) {
              uVar12 = 0xffffffff;
              goto LAB_00920a81;
            }
          }
        }
        uVar12 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + local_10 * 4) + 0x34);
        if (*puVar13 == uVar12) break;
      }
    }
LAB_00920aa2:
    local_8 = local_8 + 1;
  } while (local_8 < param_2);
LAB_00920ab1:
  local_c = local_c + 1;
  if (param_2 <= local_c) goto LAB_00920ac2;
  goto LAB_009207f5;
}


// ==== FUN_00921641 @ 0x00921641 ====

int FUN_00921641(int *param_1,uint param_2,undefined4 param_3,int param_4,uint param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int in_ECX;
  uint *puVar10;
  int local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int local_30 [4];
  int local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  piVar3 = param_1;
  iVar5 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_2 * 4) + 0x38);
  if (iVar5 != -1) {
    param_2 = iVar5;
  }
  iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + param_2 * 4);
  local_18 = iVar5;
  if (((*param_1 == *(int *)(iVar5 + 4)) &&
      (iVar4 = *(int *)(iVar5 + 0xc) * 4, *(int *)(iVar4 + param_1[4]) == -1)) &&
     (((uint)param_1[1] <= *(uint *)(iVar4 + param_1[2]) ||
      ((uint)param_1[1] <= *(uint *)(iVar4 + param_1[3]))))) {
    local_10 = 0xffffffff;
    local_c = 0xffffffff;
    local_8 = in_ECX;
    if (param_5 == -1) {
      param_5 = 0;
      if (param_1[0xb] != 0) {
        do {
          uVar7 = *(uint *)(piVar3[8] + param_5 * 4);
          param_1 = (int *)0x0;
          iVar5 = *(int *)(local_18 + 0xc) * 4;
          local_1c = *(uint *)(piVar3[0xf] + iVar5);
          local_20 = piVar3[0x11] + *(int *)(piVar3[0x10] + iVar5) * 4;
          local_14 = uVar7;
          if (local_1c == 0) {
LAB_00921726:
            if (param_4 != -1) {
              param_1 = (int *)0x0;
              iVar5 = *(int *)(*(int *)(*(int *)(local_8 + 0x14) + param_4 * 4) + 0xc) * 4;
              uVar6 = *(uint *)(iVar5 + piVar3[0xf]);
              if (uVar6 != 0) {
                do {
                  if (uVar7 == *(uint *)(piVar3[4] +
                                        *(int *)(piVar3[0x11] + *(int *)(iVar5 + piVar3[0x10]) * 4 +
                                                (int)param_1 * 4) * 4)) break;
                  param_1 = (int *)((int)param_1 + 1);
                } while (param_1 < uVar6);
                if (param_1 < uVar6) goto LAB_0092179c;
              }
            }
            uVar6 = FUN_009191b8(piVar3,param_2,uVar7,param_3,&local_40,local_c);
            if (uVar6 < local_c) {
              local_30[0] = local_40;
              local_30[1] = uStack_3c;
              local_30[2] = uStack_38;
              local_30[3] = uStack_34;
              local_10 = uVar7;
              local_c = uVar6;
              if (uVar6 == 0) {
                iVar5 = local_18;
                break;
              }
            }
          }
          else {
            do {
              if (uVar7 == *(uint *)(piVar3[4] + *(int *)(local_20 + (int)param_1 * 4) * 4)) break;
              param_1 = (int *)((int)param_1 + 1);
            } while (param_1 < local_1c);
            if (local_1c <= param_1) goto LAB_00921726;
          }
LAB_0092179c:
          param_5 = param_5 + 1;
          iVar5 = local_18;
        } while (param_5 < (uint)piVar3[0xb]);
        goto LAB_009217d4;
      }
    }
    else {
      local_10 = *(uint *)(param_1[8] + param_5 * 4);
      local_c = FUN_009191b8(param_1,param_2,local_10,param_3,local_30,0xffffffff);
LAB_009217d4:
      if (local_c != 0xffffffff) {
        *(uint *)(piVar3[4] + *(int *)(iVar5 + 0xc) * 4) = local_10;
        if (((*(byte *)(local_8 + 0xcc) & 4) != 0) && (local_10 < (uint)piVar3[9])) {
          uVar7 = 0;
          for (puVar10 = (uint *)piVar3[8]; uVar7 = uVar7 + 1, *puVar10 != local_10;
              puVar10 = puVar10 + 1) {
          }
          if (uVar7 < (uint)piVar3[9]) {
            do {
              puVar1 = (undefined4 *)(piVar3[8] + uVar7 * 4);
              uVar7 = uVar7 + 1;
              puVar1[-1] = *puVar1;
            } while (uVar7 < (uint)piVar3[9]);
          }
          *(uint *)(piVar3[8] + -4 + piVar3[9] * 4) = local_10;
        }
        param_2 = 0;
        do {
          iVar8 = (param_2 + *(int *)(iVar5 + 0xc) * 4) * 4;
          iVar4 = *(int *)(iVar8 + piVar3[6]);
          if (iVar4 != -1) {
            iVar2 = local_30[param_2];
            *(int *)(iVar8 + piVar3[5]) = iVar2;
            piVar9 = (int *)(piVar3[7] + (iVar2 + local_10 * 4) * 4);
            if (*piVar9 != -1) {
              do {
                if (*(uint *)(*(int *)(*(int *)(local_8 + 0x14) + *piVar9 * 4) + 0x58) <=
                    *(uint *)(*(int *)(*(int *)(local_8 + 0x14) + iVar4 * 4) + 0x58)) break;
                piVar9 = (int *)(*(int *)(*piVar9 * 4 + *(int *)(local_8 + 0x14)) + 0x30);
              } while (*piVar9 != -1);
            }
            *(int *)(*(int *)(*(int *)(local_8 + 0x14) + iVar4 * 4) + 0x30) = *piVar9;
            *piVar9 = iVar4;
          }
          param_2 = param_2 + 1;
        } while (param_2 < 4);
        goto LAB_009218e4;
      }
    }
    if ((*(byte *)(piVar3 + 0x18) & 2) != 0) {
      FUN_0091a001(local_8,*(undefined4 *)(piVar3[0x17] + 0x3c),0xfa4,
                   s_program_too_complex__there_are_m_00a297c8);
    }
    iVar5 = -0x7fffbffb;
  }
  else {
LAB_009218e4:
    if ((*(int *)(iVar5 + 8) == -1) ||
       (iVar5 = FUN_00921641(piVar3,*(int *)(iVar5 + 8),0,0xffffffff,0xffffffff), -1 < iVar5)) {
      iVar5 = 0;
    }
  }
  return iVar5;
}


// ==== FUN_00921909 @ 0x00921909 ====

int FUN_00921909(undefined4 param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_2 * 4) + 0x14);
  if ((iVar1 == -1) || (iVar1 = FUN_00921641(param_1,iVar1,0,0xffffffff,0xffffffff), -1 < iVar1)) {
    return 0;
  }
  return iVar1;
}


// ==== FUN_00921938 @ 0x00921938 ====

undefined4 FUN_00921938(int *param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  void *pvVar5;
  int iVar6;
  int in_ECX;
  int iVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint local_24;
  int local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  uint local_c;
  int *local_8;
  
  piVar3 = param_1;
  FUN_009198e4();
  if (param_1 == (int *)0x0) {
    uVar4 = 0x80004005;
  }
  else {
    piVar10 = param_1;
    for (iVar7 = 0x19; iVar7 != 0; iVar7 = iVar7 + -1) {
      *piVar10 = 0;
      piVar10 = piVar10 + 1;
    }
    param_1[0xb] = param_3;
    *param_1 = param_2;
    uVar11 = 0;
    param_1[0x18] = param_1[0x18] ^ ((*(int *)(in_ECX + 0x6c) << 1) >> 0x1f ^ param_1[0x18]) & 1U;
    if (*(int *)(in_ECX + 8) != 0) {
      do {
        iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + uVar11 * 4);
        if ((param_2 == *(int *)(iVar7 + 4)) && (*(int *)(iVar7 + 0x38) == -1)) {
          if ((uint)param_1[10] <= *(uint *)(iVar7 + 0xc)) {
            param_1[10] = *(uint *)(iVar7 + 0xc) + 1;
          }
          *(int *)(iVar7 + 0x74) = param_1[0x12];
          param_1[0x12] = param_1[0x12] + 1;
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < *(uint *)(in_ECX + 8));
    }
    pvVar5 = operator_new(param_1[10] << 2);
    param_1[4] = (int)pvVar5;
    if (pvVar5 != (void *)0x0) {
      pvVar5 = operator_new(param_1[10] << 4);
      param_1[5] = (int)pvVar5;
      if (pvVar5 != (void *)0x0) {
        pvVar5 = operator_new(param_1[10] << 4);
        param_1[6] = (int)pvVar5;
        if (pvVar5 != (void *)0x0) {
          pvVar5 = operator_new(param_1[10] << 2);
          param_1[2] = (int)pvVar5;
          if (pvVar5 != (void *)0x0) {
            pvVar5 = operator_new(param_1[10] << 2);
            param_1[3] = (int)pvVar5;
            if (pvVar5 != (void *)0x0) {
              pvVar5 = operator_new(param_1[0xb] << 4);
              param_1[7] = (int)pvVar5;
              if (pvVar5 != (void *)0x0) {
                pvVar5 = operator_new(param_1[0xb] << 2);
                param_1[8] = (int)pvVar5;
                if (pvVar5 != (void *)0x0) {
                  pvVar5 = operator_new(param_1[10] << 4);
                  param_1[0xc] = (int)pvVar5;
                  if (pvVar5 != (void *)0x0) {
                    pvVar5 = operator_new(param_1[10] << 4);
                    param_1[0xd] = (int)pvVar5;
                    if (pvVar5 != (void *)0x0) {
                      pvVar5 = operator_new(param_1[10] << 2);
                      param_1[0xf] = (int)pvVar5;
                      if (pvVar5 != (void *)0x0) {
                        pvVar5 = operator_new(param_1[10] << 2);
                        param_1[0x10] = (int)pvVar5;
                        if (pvVar5 != (void *)0x0) {
                          pvVar5 = operator_new(param_1[0x12] << 2);
                          param_1[0x13] = (int)pvVar5;
                          if (pvVar5 != (void *)0x0) {
                            pvVar5 = operator_new(param_1[0x12] << 2);
                            param_1[0x14] = (int)pvVar5;
                            if (pvVar5 != (void *)0x0) {
                              local_c = 0;
                              do {
                                puVar12 = (undefined4 *)param_1[0xc];
                                for (iVar7 = (param_1[10] & 0xfffffffU) << 2; iVar7 != 0;
                                    iVar7 = iVar7 + -1) {
                                  *puVar12 = 0;
                                  puVar12 = puVar12 + 1;
                                }
                                for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                                  *(undefined1 *)puVar12 = 0;
                                  puVar12 = (undefined4 *)((int)puVar12 + 1);
                                }
                                local_20 = 0;
                                local_14 = 0;
                                if (*(int *)(in_ECX + 0xc) != 0) {
                                  do {
                                    puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_14 * 4);
                                    iVar7 = FUN_0091467d();
                                    if ((iVar7 != 0) &&
                                       (param_2 ==
                                        *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                         *(int *)puVar1[4] * 4) + 4))) {
                                      uVar11 = *puVar1 & 0xfffff;
                                      local_24 = puVar1[1] / uVar11;
                                      if (local_24 != 0) {
                                        local_1c = 0;
                                        do {
                                          local_8 = (int *)(puVar1[2] + local_1c);
                                          iVar7 = *local_8;
                                          if ((iVar7 == -1) ||
                                             (iVar6 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                                       iVar7 * 4) + 0x38),
                                             iVar6 == -1)) {
                                            iVar6 = iVar7;
                                          }
                                          iVar8 = *(int *)(in_ECX + 0x14);
                                          if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                                                 *(int *)(*(int *)(iVar8 + iVar6 * 4
                                                                                  ) + 4) * 4) + 6) &
                                              2) != 0) {
                                            if ((iVar7 == -1) ||
                                               (iVar6 = *(int *)(*(int *)(iVar8 + iVar7 * 4) + 0x38)
                                               , iVar6 == -1)) {
                                              iVar6 = iVar7;
                                            }
                                            local_8 = *(int **)(*(int *)(*(int *)(in_ECX + 0x18) +
                                                                        *(int *)(*(int *)(iVar8 + 
                                                  iVar6 * 4) + 0x48) * 4) + 8);
                                          }
                                          iVar7 = *local_8;
                                          if ((iVar7 != -1) &&
                                             (iVar6 = *(int *)(*(int *)(iVar8 + iVar7 * 4) + 0x38),
                                             iVar6 != -1)) {
                                            iVar7 = iVar6;
                                          }
                                          if (param_2 == *(int *)(*(int *)(iVar8 + iVar7 * 4) + 4))
                                          {
                                            local_18 = 0;
                                            param_3 = 0;
                                            if (uVar11 != 0) {
                                              do {
                                                iVar7 = local_8[param_3];
                                                if ((iVar7 != -1) &&
                                                   (iVar6 = *(int *)(*(int *)(iVar8 + iVar7 * 4) +
                                                                    0x38), iVar6 != -1)) {
                                                  iVar7 = iVar6;
                                                }
                                                uVar9 = 1 << ((byte)*(undefined4 *)
                                                                     (*(int *)(iVar8 + iVar7 * 4) +
                                                                     0x10) & 0x1f);
                                                if ((local_18 & uVar9) != 0) break;
                                                local_18 = local_18 | uVar9;
                                                param_3 = param_3 + 1;
                                              } while (param_3 < uVar11);
                                              if (param_3 < uVar11) goto LAB_00921cf1;
                                            }
                                            param_3 = 0;
                                            if (uVar11 != 0) {
                                              do {
                                                iVar7 = *(int *)(in_ECX + 0x14);
                                                iVar6 = local_8[param_3];
                                                iVar8 = *(int *)(iVar7 + *(int *)(param_3 * 4 +
                                                                                 puVar1[4]) * 4);
                                                if ((iVar6 != -1) &&
                                                   (iVar2 = *(int *)(*(int *)(iVar7 + iVar6 * 4) +
                                                                    0x38), iVar2 != -1)) {
                                                  iVar6 = iVar2;
                                                }
                                                iVar6 = *(int *)(iVar7 + iVar6 * 4);
                                                iVar7 = *(int *)(iVar8 + 0x10) +
                                                        *(int *)(iVar8 + 0xc) * 4;
                                                iVar6 = *(int *)(iVar6 + 0x10) +
                                                        *(int *)(iVar6 + 0xc) * 4;
                                                if ((iVar7 != iVar6) &&
                                                   (*(int *)(iVar8 + 0x3c) == 0)) {
                                                  if (local_c == 1) {
                                                    *(int *)(param_1[0xe] +
                                                            (*(int *)(param_1[0xc] + iVar7 * 4) +
                                                            *(int *)(param_1[0xd] + iVar7 * 4)) * 4)
                                                         = iVar6;
                                                    *(int *)(param_1[0xe] +
                                                            (*(int *)(param_1[0xc] + iVar6 * 4) +
                                                            *(int *)(param_1[0xd] + iVar6 * 4)) * 4)
                                                         = iVar7;
                                                  }
                                                  piVar10 = (int *)(param_1[0xc] + iVar7 * 4);
                                                  *piVar10 = *piVar10 + 1;
                                                  piVar10 = (int *)(param_1[0xc] + iVar6 * 4);
                                                  *piVar10 = *piVar10 + 1;
                                                  local_20 = local_20 + 2;
                                                }
                                                param_3 = param_3 + 1;
                                              } while (param_3 < uVar11);
                                            }
                                          }
LAB_00921cf1:
                                          local_1c = local_1c + uVar11 * 4;
                                          local_24 = local_24 - 1;
                                        } while (local_24 != 0);
                                      }
                                    }
                                    local_14 = local_14 + 1;
                                  } while (local_14 < *(uint *)(in_ECX + 0xc));
                                }
                                if (local_c == 0) {
                                  iVar7 = 0;
                                  uVar11 = 0;
                                  if ((param_1[10] & 0x3fffffffU) != 0) {
                                    do {
                                      *(int *)(param_1[0xd] + uVar11 * 4) = iVar7;
                                      iVar7 = iVar7 + *(int *)(param_1[0xc] + uVar11 * 4);
                                      uVar11 = uVar11 + 1;
                                    } while (uVar11 < (uint)(param_1[10] << 2));
                                  }
                                  pvVar5 = operator_new(local_20 << 2);
                                  param_1[0xe] = (int)pvVar5;
                                  if (pvVar5 == (void *)0x0) goto LAB_00921ff7;
                                }
                                local_c = local_c + 1;
                              } while (local_c < 2);
                              param_1 = (int *)0x0;
                              do {
                                puVar12 = (undefined4 *)piVar3[0xf];
                                for (uVar11 = piVar3[10] & 0x3fffffff; uVar11 != 0;
                                    uVar11 = uVar11 - 1) {
                                  *puVar12 = 0;
                                  puVar12 = puVar12 + 1;
                                }
                                for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                                  *(undefined1 *)puVar12 = 0;
                                  puVar12 = (undefined4 *)((int)puVar12 + 1);
                                }
                                local_1c = 0;
                                param_3 = 0;
                                if (*(int *)(in_ECX + 0xc) != 0) {
                                  do {
                                    puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + param_3 * 4);
                                    iVar7 = FUN_009146b5();
                                    if (((iVar7 != 0) || ((*(byte *)(in_ECX + 0x6f) & 0x80) != 0))
                                       && (iVar7 = *(int *)(*(int *)(in_ECX + 0x14) +
                                                           *(int *)puVar1[4] * 4),
                                          param_2 == *(int *)(iVar7 + 4))) {
                                      uVar11 = *puVar1;
                                      local_18 = puVar1[1] / (uVar11 & 0xfffff);
                                      iVar7 = *(int *)(iVar7 + 0xc);
                                      if (local_18 != 0) {
                                        local_24 = 0;
                                        do {
                                          iVar6 = *(int *)(local_24 + puVar1[2]);
                                          if ((iVar6 != -1) &&
                                             (iVar8 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                                       iVar6 * 4) + 0x38),
                                             iVar8 != -1)) {
                                            iVar6 = iVar8;
                                          }
                                          iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + iVar6 * 4);
                                          if ((param_2 == *(int *)(iVar6 + 4)) &&
                                             (iVar7 != *(int *)(iVar6 + 0xc))) {
                                            if (param_1 == (int *)0x1) {
                                              *(undefined4 *)
                                               (piVar3[0x11] +
                                               (*(int *)(iVar7 * 4 + piVar3[0x10]) +
                                               *(int *)(piVar3[0xf] + iVar7 * 4)) * 4) =
                                                   *(undefined4 *)(iVar6 + 0xc);
                                              iVar8 = *(int *)(iVar6 + 0xc) * 4;
                                              *(int *)(piVar3[0x11] +
                                                      (*(int *)(iVar8 + piVar3[0x10]) +
                                                      *(int *)(piVar3[0xf] + iVar8)) * 4) = iVar7;
                                            }
                                            piVar10 = (int *)(piVar3[0xf] + iVar7 * 4);
                                            *piVar10 = *piVar10 + 1;
                                            piVar10 = (int *)(piVar3[0xf] +
                                                             *(int *)(iVar6 + 0xc) * 4);
                                            *piVar10 = *piVar10 + 1;
                                            local_1c = local_1c + 2;
                                          }
                                          local_24 = local_24 + (uVar11 & 0xfffff) * 4;
                                          local_18 = local_18 - 1;
                                        } while (local_18 != 0);
                                      }
                                    }
                                    param_3 = param_3 + 1;
                                  } while (param_3 < *(uint *)(in_ECX + 0xc));
                                }
                                uVar11 = 0;
                                if (param_1 == (int *)0x0) {
                                  iVar7 = 0;
                                  if (piVar3[10] != 0) {
                                    do {
                                      *(int *)(piVar3[0x10] + uVar11 * 4) = iVar7;
                                      iVar7 = iVar7 + *(int *)(piVar3[0xf] + uVar11 * 4);
                                      uVar11 = uVar11 + 1;
                                    } while (uVar11 < (uint)piVar3[10]);
                                  }
                                  pvVar5 = operator_new(local_1c << 2);
                                  piVar3[0x11] = (int)pvVar5;
                                  if (pvVar5 == (void *)0x0) goto LAB_00921ff7;
                                }
                                param_1 = (int *)((int)param_1 + 1);
                              } while (param_1 < 2);
                              param_2 = 0;
                              puVar12 = (undefined4 *)piVar3[0x13];
                              for (uVar11 = piVar3[0x12] & 0x3fffffff; uVar11 != 0;
                                  uVar11 = uVar11 - 1) {
                                *puVar12 = 0;
                                puVar12 = puVar12 + 1;
                              }
                              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                                *(undefined1 *)puVar12 = 0;
                                puVar12 = (undefined4 *)((int)puVar12 + 1);
                              }
                              if (*(int *)(in_ECX + 0xc) != 0) {
                                do {
                                  iVar7 = *(int *)(*(int *)(in_ECX + 0x18) + param_2 * 4);
                                  if ((*(ushort *)(iVar7 + 2) & 0xfff0) != 0) {
                                    param_1 = (int *)0x0;
                                    if (*(int *)(iVar7 + 0xc) != 0) {
                                      do {
                                        FUN_009195b1(piVar3,*(undefined4 *)
                                                             (*(int *)(iVar7 + 0x10) +
                                                             (int)param_1 * 4),param_2);
                                        param_1 = (int *)((int)param_1 + 1);
                                      } while (param_1 < *(uint *)(iVar7 + 0xc));
                                    }
                                    param_1 = (int *)0x0;
                                    if (*(int *)(iVar7 + 4) != 0) {
                                      do {
                                        FUN_0091942e(piVar3,*(undefined4 *)
                                                             (*(int *)(iVar7 + 8) + (int)param_1 * 4
                                                             ),param_2);
                                        param_1 = (int *)((int)param_1 + 1);
                                      } while (param_1 < *(uint *)(iVar7 + 4));
                                    }
                                    iVar6 = FUN_009145ef();
                                    if ((iVar6 != 0) &&
                                       (param_1 = (int *)0x0, *(int *)(iVar7 + 0xc) != 0)) {
                                      do {
                                        FUN_0091942e(piVar3,*(undefined4 *)
                                                             (*(int *)(iVar7 + 0x10) +
                                                             (int)param_1 * 4),param_2);
                                        param_1 = (int *)((int)param_1 + 1);
                                      } while (param_1 < *(uint *)(iVar7 + 0xc));
                                    }
                                  }
                                  param_2 = param_2 + 1;
                                } while (param_2 < *(uint *)(in_ECX + 0xc));
                              }
                              uVar11 = 0;
                              iVar7 = 0;
                              if (piVar3[0x12] != 0) {
                                do {
                                  *(int *)(piVar3[0x14] + uVar11 * 4) = iVar7;
                                  iVar7 = iVar7 + *(int *)(piVar3[0x13] + uVar11 * 4);
                                  uVar11 = uVar11 + 1;
                                } while (uVar11 < (uint)piVar3[0x12]);
                              }
                              pvVar5 = operator_new(iVar7 << 2);
                              piVar3[0x15] = (int)pvVar5;
                              if (pvVar5 != (void *)0x0) {
                                pvVar5 = operator_new(iVar7 * 0xc);
                                piVar3[0x16] = (int)pvVar5;
                                if (pvVar5 != (void *)0x0) {
                                  return 0;
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
LAB_00921ff7:
    uVar4 = 0x8007000e;
  }
  return uVar4;
}


// ==== FUN_00922003 @ 0x00922003 ====

int FUN_00922003(int *param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int in_ECX;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  uint local_18;
  int *local_14;
  int *local_10;
  int local_c;
  uint local_8;
  
  piVar5 = param_1;
  *(int **)(in_ECX + 0xbc) = param_1;
  param_1[0x18] = param_1[0x18] ^ (param_2 * 2 ^ param_1[0x18]) & 2;
  FUN_009198e4();
  uVar9 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + uVar9 * 4);
      if (((*param_1 == *(int *)(iVar10 + 4)) && (*(int *)(iVar10 + 0x38) == -1)) &&
         (*(uint *)(iVar10 + 0x58) <= *(uint *)(iVar10 + 0x48))) {
        *(uint *)(iVar10 + 0x58) = *(uint *)(iVar10 + 0x48) + 1;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint *)(in_ECX + 8));
  }
  puVar12 = (undefined4 *)param_1[4];
  for (uVar9 = param_1[10] & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
    *puVar12 = 0xffffffff;
    puVar12 = puVar12 + 1;
  }
  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
    *(undefined1 *)puVar12 = 0xff;
    puVar12 = (undefined4 *)((int)puVar12 + 1);
  }
  puVar12 = (undefined4 *)param_1[5];
  for (iVar10 = (param_1[10] & 0xfffffffU) << 2; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar12 = 0xffffffff;
    puVar12 = puVar12 + 1;
  }
  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
    *(undefined1 *)puVar12 = 0xff;
    puVar12 = (undefined4 *)((int)puVar12 + 1);
  }
  puVar12 = (undefined4 *)param_1[6];
  for (iVar10 = (param_1[10] & 0xfffffffU) << 2; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar12 = 0xffffffff;
    puVar12 = puVar12 + 1;
  }
  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
    *(undefined1 *)puVar12 = 0xff;
    puVar12 = (undefined4 *)((int)puVar12 + 1);
  }
  uVar9 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + uVar9 * 4);
      *(undefined4 *)(iVar10 + 0x30) = 0xffffffff;
      if ((*param_1 == *(int *)(iVar10 + 4)) && (*(int *)(iVar10 + 0x38) == -1)) {
        *(uint *)(param_1[6] + (*(int *)(iVar10 + 0x10) + *(int *)(iVar10 + 0xc) * 4) * 4) = uVar9;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint *)(in_ECX + 8));
  }
  puVar12 = (undefined4 *)param_1[2];
  for (uVar9 = param_1[10] & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
    *(undefined1 *)puVar12 = 0;
    puVar12 = (undefined4 *)((int)puVar12 + 1);
  }
  uVar9 = 0;
  if (param_1[10] != 0) {
    param_1 = (int *)0x0;
    do {
      iVar11 = 0;
      piVar6 = (int *)(piVar5[6] + (int)param_1);
      iVar10 = 4;
      do {
        if (*piVar6 != -1) {
          iVar11 = iVar11 + 1;
        }
        piVar6 = piVar6 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      param_1 = (int *)((int)param_1 + 0x10);
      *(int *)(piVar5[2] + uVar9 * 4) = iVar11;
      uVar9 = uVar9 + 1;
    } while (uVar9 < (uint)piVar5[10]);
  }
  param_1 = (int *)0x0;
  puVar12 = (undefined4 *)piVar5[3];
  for (uVar9 = piVar5[10] & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
    *(undefined1 *)puVar12 = 0;
    puVar12 = (undefined4 *)((int)puVar12 + 1);
  }
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      iVar10 = *(int *)(*(int *)(in_ECX + 0x18) + (int)param_1 * 4);
      iVar11 = FUN_0091467d();
      if ((iVar11 != 0) &&
         (iVar11 = *(int *)(*(int *)(in_ECX + 0x14) + **(int **)(iVar10 + 0x10) * 4),
         *piVar5 == *(int *)(iVar11 + 4))) {
        local_10 = (int *)0x2;
        do {
          local_8 = 0;
          if (*(int *)(iVar10 + 4) != 0) {
            do {
              iVar7 = *(int *)(*(int *)(iVar10 + 8) + local_8 * 4);
              if (iVar7 != -1) {
                iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar7 * 4) + 0x38);
                if (iVar2 != -1) {
                  iVar7 = iVar2;
                }
              }
              iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + iVar7 * 4);
              if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4) + 6) & 2)
                  != 0) {
                iVar7 = *(int *)(*(int *)(in_ECX + 0x14) +
                                **(int **)(*(int *)(*(int *)(in_ECX + 0x18) +
                                                   *(int *)(iVar7 + 0x48) * 4) + 8) * 4);
              }
              if (*piVar5 == *(int *)(iVar7 + 4)) {
                puVar1 = (uint *)(piVar5[3] + *(int *)(iVar7 + 0xc) * 4);
                uVar9 = *(uint *)(piVar5[2] + *(int *)(iVar11 + 0xc) * 4);
                if (*puVar1 < uVar9) {
                  *puVar1 = uVar9;
                }
                puVar1 = (uint *)(piVar5[3] + *(int *)(iVar11 + 0xc) * 4);
                uVar9 = *(uint *)(piVar5[2] + *(int *)(iVar7 + 0xc) * 4);
                if (*puVar1 < uVar9) {
                  *puVar1 = uVar9;
                }
              }
              local_8 = local_8 + *(int *)(iVar10 + 0xc);
            } while (local_8 < *(uint *)(iVar10 + 4));
          }
          local_10 = (int *)((int)local_10 + -1);
        } while (local_10 != (int *)0x0);
      }
      param_1 = (int *)((int)param_1 + 1);
    } while (param_1 < *(uint *)(in_ECX + 0xc));
  }
  param_1 = (int *)0x0;
  puVar12 = (undefined4 *)piVar5[0x13];
  for (uVar9 = piVar5[0x12] & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
    *(undefined1 *)puVar12 = 0;
    puVar12 = (undefined4 *)((int)puVar12 + 1);
  }
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      iVar10 = *(int *)(*(int *)(in_ECX + 0x18) + (int)param_1 * 4);
      if ((*(ushort *)(iVar10 + 2) & 0xfff0) != 0) {
        param_2 = 0;
        if (*(int *)(iVar10 + 0xc) != 0) {
          do {
            FUN_009195b1(piVar5,*(undefined4 *)(*(int *)(iVar10 + 0x10) + param_2 * 4),param_1);
            param_2 = param_2 + 1;
          } while (param_2 < *(uint *)(iVar10 + 0xc));
        }
        param_2 = 0;
        if (*(int *)(iVar10 + 4) != 0) {
          do {
            FUN_0091942e(piVar5,*(undefined4 *)(*(int *)(iVar10 + 8) + param_2 * 4),param_1);
            param_2 = param_2 + 1;
          } while (param_2 < *(uint *)(iVar10 + 4));
        }
        iVar11 = FUN_009145ef();
        if ((iVar11 != 0) && (param_2 = 0, *(int *)(iVar10 + 0xc) != 0)) {
          do {
            FUN_0091942e(piVar5,*(undefined4 *)(*(int *)(iVar10 + 0x10) + param_2 * 4),param_1);
            param_2 = param_2 + 1;
          } while (param_2 < *(uint *)(iVar10 + 0xc));
        }
      }
      param_1 = (int *)((int)param_1 + 1);
    } while (param_1 < *(uint *)(in_ECX + 0xc));
  }
  local_8 = 0;
  if (piVar5[0x12] != 0) {
    do {
      iVar10 = piVar5[0x15] + *(int *)(piVar5[0x14] + local_8 * 4) * 4;
      uVar9 = *(uint *)(piVar5[0x13] + local_8 * 4);
      if (1 < uVar9) {
        FUN_00915b0e(FUN_00915abf,iVar10,uVar9,in_ECX);
        param_1 = (int *)0x1;
        local_10 = (int *)0x1;
        if (1 < uVar9) {
          do {
            uVar3 = *(undefined4 *)(iVar10 + (int)local_10 * 4);
            iVar11 = FUN_00915a46();
            if (iVar11 != 0) {
              *(undefined4 *)(iVar10 + (int)param_1 * 4) = uVar3;
              param_1 = (int *)((int)param_1 + 1);
            }
            local_10 = (int *)((int)local_10 + 1);
          } while (local_10 < uVar9);
        }
        *(int **)(piVar5[0x13] + local_8 * 4) = param_1;
        FUN_00915b0e(FUN_00915a87,iVar10,param_1,in_ECX);
      }
      local_8 = local_8 + 1;
    } while (local_8 < (uint)piVar5[0x12]);
  }
  puVar12 = (undefined4 *)piVar5[7];
  for (iVar10 = (piVar5[0xb] & 0xfffffffU) << 2; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar12 = 0xffffffff;
    puVar12 = puVar12 + 1;
  }
  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
    *(undefined1 *)puVar12 = 0xff;
    puVar12 = (undefined4 *)((int)puVar12 + 1);
  }
  uVar9 = 0;
  if (piVar5[0xb] != 0) {
    do {
      *(uint *)(piVar5[8] + uVar9 * 4) = uVar9;
      uVar9 = uVar9 + 1;
    } while (uVar9 < (uint)piVar5[0xb]);
  }
  piVar5[1] = 0;
  piVar5[9] = (uint)piVar5[0xb] >> 1;
  iVar10 = *(int *)(in_ECX + 0xc);
  do {
    do {
      if (iVar10 == 0) {
        local_c = 4;
        do {
          piVar5[1] = local_c;
          iVar10 = *(int *)(in_ECX + 0xc);
          while (iVar10 != 0) {
            iVar10 = iVar10 + -1;
            puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar10 * 4);
            piVar5[0x17] = (int)puVar1;
            if ((*puVar1 & 0xfff00000) != 0) {
              param_1 = (int *)0x0;
              if (puVar1[3] != 0) {
                do {
                  iVar11 = FUN_00921909(piVar5,*(undefined4 *)(puVar1[4] + (int)param_1 * 4));
                  if (iVar11 < 0) {
                    return iVar11;
                  }
                  param_1 = (int *)((int)param_1 + 1);
                } while (param_1 < puVar1[3]);
              }
              uVar9 = *puVar1;
              uVar8 = puVar1[1] / (uVar9 & 0xfffff);
              param_2 = 0;
              if (puVar1[1] != 0) {
                do {
                  param_1 = (int *)0x0;
                  if (((*(byte *)(in_ECX + 0x70) & 1) != 0) && (uVar8 != 0)) {
                    local_14 = (int *)puVar1[2];
                    local_18 = uVar8;
                    do {
                      iVar11 = *local_14;
                      if (iVar11 != -1) {
                        iVar7 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar11 * 4) + 0x38);
                        if (iVar7 != -1) {
                          iVar11 = iVar7;
                        }
                      }
                      iVar11 = *(int *)(*(int *)(in_ECX + 0x14) + iVar11 * 4);
                      if ((*piVar5 == *(int *)(iVar11 + 4)) &&
                         (uVar4 = *(uint *)(piVar5[4] + *(int *)(iVar11 + 0xc) * 4),
                         uVar4 != 0xffffffff)) {
                        if ((uVar4 & 1) == 0) {
                          param_1 = (int *)((int)param_1 + 1);
                        }
                        else {
                          param_1 = (int *)((int)param_1 + -1);
                        }
                      }
                      local_14 = local_14 + (uVar9 & 0xfffff);
                      local_18 = local_18 - 1;
                    } while (local_18 != 0);
                  }
                  iVar11 = *(int *)(puVar1[2] + param_2 * 4);
                  if (iVar11 != -1) {
                    iVar7 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar11 * 4) + 0x38);
                    if (iVar7 != -1) {
                      iVar11 = iVar7;
                    }
                  }
                  iVar11 = FUN_00921641(piVar5,iVar11,param_1,0xffffffff,0xffffffff);
                  if (iVar11 < 0) {
                    return iVar11;
                  }
                  param_2 = param_2 + 1;
                } while (param_2 < puVar1[1]);
              }
            }
          }
          local_c = local_c + -1;
          if (local_c == 0) {
            if (((*(byte *)(piVar5 + 0x18) & 2) != 0) &&
               (param_1 = (int *)0x0, *(int *)(in_ECX + 8) != 0)) {
              do {
                iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + (int)param_1 * 4);
                if (*piVar5 == *(int *)(iVar10 + 4)) {
                  iVar11 = *(int *)(iVar10 + 0xc) * 4;
                  *(undefined4 *)(iVar10 + 0x10) =
                       *(undefined4 *)(piVar5[5] + (*(int *)(iVar10 + 0x10) + iVar11) * 4);
                  *(undefined4 *)(iVar10 + 0xc) = *(undefined4 *)(iVar11 + piVar5[4]);
                }
                param_1 = (int *)((int)param_1 + 1);
              } while (param_1 < *(uint *)(in_ECX + 8));
            }
            *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x10) + *piVar5 * 4) + 8) = 0xffffffff;
            return 0;
          }
        } while( true );
      }
      iVar10 = iVar10 + -1;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar10 * 4);
    } while (((*puVar1 & 0xfff00000) != 0x20900000) || (param_1 = (int *)0x0, puVar1[3] == 0));
    do {
      piVar5[0x17] = (int)puVar1;
      iVar11 = *(int *)(puVar1[2] + (int)param_1 * 4);
      if (iVar11 != -1) {
        iVar7 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar11 * 4) + 0x38);
        if (iVar7 != -1) {
          iVar11 = iVar7;
        }
      }
      iVar11 = FUN_00921641(piVar5,iVar11,0,0xffffffff,0xffffffff);
      if (iVar11 < 0) {
        return iVar11;
      }
      iVar11 = *(int *)(puVar1[2] + (puVar1[3] + (int)param_1) * 4);
      iVar7 = *(int *)(*(int *)(in_ECX + 0x18) +
                      *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar11 * 4) + 0x48) * 4);
      param_2 = 0;
      if (*(uint *)(iVar7 + 0xc) != 0) {
        local_10 = *(int **)(iVar7 + 0x10);
        do {
          if (*local_10 == iVar11) break;
          param_2 = param_2 + 1;
          local_10 = local_10 + 1;
        } while (param_2 < *(uint *)(iVar7 + 0xc));
      }
      piVar5[0x17] = iVar7;
      iVar11 = FUN_00921641(piVar5,*(undefined4 *)(puVar1[4] + (int)param_1 * 4),0,
                            *(undefined4 *)(param_2 * 4 + *(int *)(iVar7 + 8)),0xffffffff);
      if (iVar11 < 0) {
        return iVar11;
      }
      iVar11 = FUN_00921641(piVar5,*(undefined4 *)(param_2 * 4 + *(int *)(iVar7 + 8)),0,
                            *(undefined4 *)(puVar1[4] + (int)param_1 * 4),0xffffffff);
      if (iVar11 < 0) {
        return iVar11;
      }
      param_1 = (int *)((int)param_1 + 1);
    } while (param_1 < puVar1[3]);
  } while( true );
}


// ==== FUN_009226b6 @ 0x009226b6 ====

int FUN_009226b6(void)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int in_ECX;
  uint uVar11;
  int iVar12;
  int *piVar13;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  if (((*(uint *)(in_ECX + 0xcc) & 0x100) == 0) && ((*(uint *)(in_ECX + 0xcc) & 4) == 0)) {
    iVar5 = FUN_0091c58a();
    if (-1 < iVar5) {
      pvVar6 = operator_new(0x1fc);
      if (pvVar6 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_0093bbf4();
      }
      *(int *)(in_ECX + 0xe0) = iVar5;
      if (iVar5 == 0) {
LAB_00922bb0:
        iVar5 = -0x7ff8fff2;
      }
      else {
        iVar5 = FUN_0091a540(in_ECX,0x46580201,*(uint *)(in_ECX + 0xcc) | 0x100);
        if (((-1 < iVar5) && (iVar5 = FUN_00915eb3(), -1 < iVar5)) &&
           (iVar5 = FUN_009160c4(), -1 < iVar5)) {
          uVar7 = 0;
          if (*(int *)(in_ECX + 8) != 0) {
            do {
              *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar7 * 4) + 0x30) = 0xffffffff;
              *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar7 * 4) + 0x44) = 0xffffffff;
              uVar7 = uVar7 + 1;
            } while (uVar7 < *(uint *)(in_ECX + 8));
          }
          local_10 = -1;
          local_c = 0;
          local_18 = 0;
          if (*(int *)(in_ECX + 0xc) != 0) {
            do {
              puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_18 * 4);
              if ((*puVar1 & 0xfff00000) != 0) {
                uVar7 = puVar1[1];
                uVar11 = *puVar1 & 0xfffff;
                local_24 = 0;
                if (uVar7 / uVar11 != 0) {
                  local_14 = 0;
                  do {
                    local_8 = 0;
                    if (uVar11 != 0) {
                      piVar13 = (int *)(puVar1[2] + local_14);
                      local_20 = uVar11;
                      do {
                        if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                                *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                                 *piVar13 * 4) + 4) * 4) + 4) & 2)
                             != 0) && (iVar5 = FUN_00915e78(), iVar5 == 0)) {
                          local_8 = local_8 + 1;
                        }
                        piVar13 = piVar13 + 1;
                        local_20 = local_20 - 1;
                      } while (local_20 != 0);
                      if (local_8 != 0) {
                        if (((local_10 == -1) &&
                            (local_10 = FUN_009152bf(&DAT_00a1fc10,0x80251,0xffffffff,4),
                            local_10 == -1)) ||
                           (iVar5 = FUN_00915378(local_8 & 0xfffff | 0x10000000,local_8,local_8),
                           iVar5 == -1)) goto LAB_00922bb0;
                        puVar2 = *(uint **)(*(int *)(*(int *)(in_ECX + 0xe0) + 0x18) + iVar5 * 4);
                        FUN_00914593();
                        local_8 = 0;
                        local_1c = 0;
                        iVar5 = local_14;
                        do {
                          uVar3 = puVar1[2];
                          iVar4 = *(int *)(uVar3 + iVar5);
                          iVar12 = iVar4 * 4;
                          iVar9 = *(int *)(iVar12 + *(int *)(in_ECX + 0x14));
                          if ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                                   *(int *)(iVar9 + 4) * 4) + 4) & 2) != 0) &&
                              (iVar8 = FUN_00915e78(), iVar8 == 0)) &&
                             ((*(int *)(iVar9 + 0x48) == -1 ||
                              ((**(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar9 + 0x48) * 4) &
                               0xfff00000) != 0x10100000)))) {
                            if (*(int *)(iVar9 + 0x30) == -1) {
                              iVar9 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 0xe0) + 0x84),
                                                   local_c,local_8,0);
                              if (iVar9 == -1) goto LAB_00922bb0;
                              *(int *)(local_8 * 4 + puVar2[4]) = iVar9;
                              *(int *)(local_8 * 4 + puVar2[2]) = iVar4;
                              uVar10 = FUN_00915318(local_10,local_c,local_8,0);
                              *(undefined4 *)(iVar5 + puVar1[2]) = uVar10;
                              if (*(int *)(iVar5 + puVar1[2]) == -1) goto LAB_00922bb0;
                              iVar4 = *(int *)(*(int *)(in_ECX + 0x14) +
                                              *(int *)(iVar5 + puVar1[2]) * 4);
                              FUN_00914f00();
                              *(undefined4 *)(iVar4 + 0x60) = 0;
                              *(undefined4 *)(iVar4 + 100) = 0;
                              local_8 = local_8 + 1;
                              *(int *)(iVar4 + 0x44) = iVar9;
                              *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar12) + 0x30) =
                                   *(undefined4 *)(iVar5 + puVar1[2]);
                            }
                            else {
                              *(int *)(uVar3 + iVar5) = *(int *)(iVar9 + 0x30);
                            }
                          }
                          local_1c = local_1c + 1;
                          iVar5 = iVar5 + 4;
                        } while (local_1c < uVar11);
                        local_c = local_c + 1;
                        *puVar2 = -(uint)(local_8 != 0) & (local_8 & 0xfffff | 0x10000000);
                        puVar2[3] = local_8;
                        puVar2[1] = local_8;
                      }
                    }
                    local_24 = local_24 + 1;
                    local_14 = local_14 + uVar11 * 4;
                  } while (local_24 < uVar7 / uVar11);
                }
              }
              local_18 = local_18 + 1;
            } while (local_18 < *(uint *)(in_ECX + 0xc));
          }
          local_18 = 0;
          if (*(int *)(in_ECX + 8) != 0) {
            do {
              iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + local_18 * 4);
              if (((*(int *)(iVar5 + 8) != -1) &&
                  (iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar5 + 8) * 4),
                  (*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar4 + 4) * 4) + 4) & 2)
                  != 0)) && (iVar9 = FUN_00915e78(), iVar9 == 0)) {
                if (*(int *)(iVar4 + 0x30) == -1) {
                  if (((local_10 == -1) &&
                      (local_10 = FUN_009152bf(&DAT_00a1fc10,0x80251,0xffffffff,4), local_10 == -1))
                     || (iVar9 = FUN_00915378(0x10000001,1,1), iVar9 == -1)) goto LAB_00922bb0;
                  iVar9 = *(int *)(*(int *)(*(int *)(in_ECX + 0xe0) + 0x18) + iVar9 * 4);
                  FUN_00914593();
                  **(undefined4 **)(iVar9 + 8) = *(undefined4 *)(iVar5 + 8);
                  uVar10 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 0xe0) + 0x84),local_c,0,0)
                  ;
                  **(undefined4 **)(iVar9 + 0x10) = uVar10;
                  if (**(int **)(iVar9 + 0x10) == -1) goto LAB_00922bb0;
                  iVar12 = FUN_00915318(local_10,local_c,0,0);
                  *(int *)(iVar4 + 0x30) = iVar12;
                  if (iVar12 == -1) goto LAB_00922bb0;
                  iVar12 = *(int *)(*(int *)(in_ECX + 0x14) + iVar12 * 4);
                  FUN_00914f00();
                  uVar10 = **(undefined4 **)(iVar9 + 0x10);
                  *(undefined4 *)(iVar12 + 0x60) = 0;
                  *(undefined4 *)(iVar12 + 100) = 0;
                  local_c = local_c + 1;
                  *(undefined4 *)(iVar12 + 0x44) = uVar10;
                }
                *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar4 + 0x30);
              }
              local_18 = local_18 + 1;
            } while (local_18 < *(uint *)(in_ECX + 8));
          }
          iVar5 = FUN_0091ae30();
          if ((iVar5 == 0) || (-1 < iVar5)) {
            iVar5 = FUN_00915e19();
            if ((iVar5 == 0) || (-1 < iVar5)) {
              FUN_009198e4();
              iVar5 = FUN_0091ae30();
              if ((iVar5 == 0) || (-1 < iVar5)) {
                iVar5 = FUN_00915e19();
                if ((iVar5 == 0) || (-1 < iVar5)) {
                  iVar5 = FUN_0091c491();
                  if ((iVar5 == 0) || (-1 < iVar5)) {
                    iVar5 = 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    iVar5 = 1;
  }
  return iVar5;
}


// ==== FUN_00922bb7 @ 0x00922bb7 ====

undefined4 FUN_00922bb7(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  uint uVar3;
  
  uVar3 = 0;
  if (*(int *)(in_ECX + 0xe0) == 0) {
    return 1;
  }
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + uVar3 * 4);
      if (*(int *)(iVar1 + 0x44) != -1) {
        *(undefined4 *)
         (*(int *)(*(int *)(*(int *)(in_ECX + 0xe0) + 0x14) + *(int *)(iVar1 + 0x44) * 4) + 0xc) =
             *(undefined4 *)(iVar1 + 0xc);
        *(uint *)(*(int *)(*(int *)(*(int *)(in_ECX + 0xe0) + 0x14) + *(int *)(iVar1 + 0x44) * 4) +
                 0x44) = uVar3;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 8));
  }
  uVar2 = FUN_0091a9b4();
  return uVar2;
}


// ==== FUN_00922c12 @ 0x00922c12 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00922c12(void)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int in_ECX;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  uint uVar13;
  uint uVar14;
  int local_4c [4];
  uint *local_3c;
  uint *local_38;
  int local_34;
  uint local_30;
  uint *local_2c;
  uint *local_28;
  int local_24;
  uint *local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_8 = 0;
  FUN_00919e76();
  FUN_009198e4();
  local_24 = -1;
  local_14 = -1;
  local_1c = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_1c * 4);
      uVar14 = *puVar1;
      uVar13 = uVar14 & 0xfff00000;
      if (uVar13 != 0) {
        local_10 = *(uint *)(in_ECX + 8);
        if (uVar13 == 0x11000000) {
          uVar14 = 0;
          if (puVar1[1] != 0) {
            piVar12 = (int *)puVar1[2];
            do {
              if ((**(byte **)(*(int *)(in_ECX + 0x14) +
                              *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar12 * 4) + 0x30) * 4)
                  & 4) == 0) break;
              uVar14 = uVar14 + 1;
              piVar12 = piVar12 + 1;
            } while (uVar14 < puVar1[1]);
          }
          if (uVar14 != puVar1[1]) goto LAB_009236e4;
LAB_009236d3:
          uVar14 = 0;
          puVar1[1] = 0;
          puVar1[3] = 0;
LAB_009236db:
          local_8 = 1;
LAB_009236e2:
          *puVar1 = uVar14;
        }
        else {
          uVar9 = uVar14 & 0xf0000000;
          if (uVar9 == 0x10000000) {
            local_c = 0;
            local_10 = 0;
            if (puVar1[3] != 0) {
              do {
                puVar5 = *(uint **)(local_10 * 4 + puVar1[4]);
                iVar7 = *(int *)(in_ECX + 0x14);
                local_2c = *(uint **)(*(int *)(iVar7 + *(int *)(local_10 * 4 + puVar1[2]) * 4) +
                                     0x30);
                if (((*puVar1 & 0xfff00000) == 0x10000000) || ((*puVar1 & 0xfff00000) == 0x10100000)
                   ) {
                  puVar2 = *(uint **)(iVar7 + (int)puVar5 * 4);
                  puVar3 = *(uint **)(iVar7 + (int)local_2c * 4);
                  uVar14 = *puVar2;
                  uVar9 = *puVar3 | uVar14;
                  uVar6 = uVar9 & 0xe000000;
                  uVar13 = 0x2000000;
                  if (((uVar9 & 0x2000000) != 0) ||
                     ((uVar13 = 0x4000000, (uVar9 & 0x4000000) != 0 ||
                      (uVar13 = 0x8000000, (uVar9 & 0x8000000) != 0)))) {
                    uVar6 = uVar13;
                  }
                  if (uVar6 != (uVar14 & 0xe000000)) {
                    *puVar2 = uVar14 & 0xf1ffffff | uVar6;
                    local_8 = 1;
                  }
                  local_30 = *puVar3;
                  if (((uVar6 != (local_30 & 0xe000000)) &&
                      ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + puVar3[1] * 4) + 4) & 2) != 0))
                     && (puVar3[0x17] == 1)) {
                    *puVar3 = local_30 & 0xf1ffffff | uVar6;
                    local_8 = 1;
                  }
                }
                local_28 = puVar5;
                iVar7 = FUN_0091c8fc(puVar1,puVar5,local_2c);
                if (iVar7 < 0) {
                  return iVar7;
                }
                iVar7 = *(int *)(in_ECX + 0x14);
                piVar12 = (int *)(iVar7 + (int)puVar5 * 4);
                puVar2 = *(uint **)(*piVar12 + 0x30);
                if (puVar2 == puVar5) {
                  local_c = local_c + 1;
                }
                else if (*(int *)(*(int *)(iVar7 + (int)puVar2 * 4) + 0x30) == -1) {
                  iVar10 = *(int *)(*piVar12 + 0x30);
                  *(int *)(*(int *)(iVar7 + iVar10 * 4) + 0x30) = iVar10;
                }
                local_10 = local_10 + 1;
              } while (local_10 < puVar1[3]);
            }
            if (local_c == puVar1[3]) goto LAB_009236e4;
            local_c = 0;
            local_8 = 0;
            if (puVar1[3] == 0) {
LAB_00922e78:
              uVar14 = 0;
            }
            else {
              do {
                iVar7 = *(int *)(puVar1[4] + local_8 * 4);
                iVar10 = *(int *)(in_ECX + 0x14);
                if (*(int *)(*(int *)(iVar10 + iVar7 * 4) + 0x30) == iVar7) {
                  iVar10 = local_c * 4;
                  local_c = local_c + 1;
                  *(int *)(iVar10 + puVar1[4]) = iVar7;
                  *(undefined4 *)(iVar10 + puVar1[2]) = *(undefined4 *)(puVar1[2] + local_8 * 4);
                }
                else {
                  iVar7 = *(int *)(iVar10 + iVar7 * 4);
                  iVar10 = *(int *)(iVar10 + *(int *)(iVar7 + 0x30) * 4);
                  if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar10 + 4) * 4) + 4)
                       & 2) != 0) && (*(int *)(iVar10 + 0x60) == 0)) {
                    *(undefined4 *)(iVar10 + 0x60) = *(undefined4 *)(iVar7 + 0x60);
                    *(undefined4 *)(iVar10 + 100) =
                         *(undefined4 *)
                          (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar1[4] + local_8 * 4) * 4)
                          + 100);
                  }
                }
                local_8 = local_8 + 1;
              } while (local_8 < puVar1[3]);
              if (local_c == 0) goto LAB_00922e78;
              uVar14 = (*puVar1 ^ local_c) & 0xfffff ^ *puVar1;
            }
            puVar1[1] = local_c;
            puVar1[3] = local_c;
            goto LAB_009236db;
          }
          if (uVar9 != 0x20000000) {
            if (uVar9 == 0x30000000) {
              local_18 = 0;
              local_c = 0;
              if (puVar1[3] != 0) {
                do {
                  uVar14 = *(uint *)(puVar1[4] + local_c * 4);
                  uVar13 = puVar1[2];
                  iVar7 = *(int *)(in_ECX + 0x14);
                  local_3c = *(uint **)(*(int *)(iVar7 + *(int *)(uVar13 + local_c * 4) * 4) + 0x30)
                  ;
                  local_28 = *(uint **)(*(int *)(iVar7 + *(int *)(uVar13 + (local_c + puVar1[3]) * 4
                                                                 ) * 4) + 0x30);
                  local_34 = *(int *)(*(int *)(iVar7 + *(int *)(uVar13 + (local_c + puVar1[3] * 2) *
                                                                         4) * 4) + 0x30);
                  if ((*puVar1 & 0xfff00000) == 0x30000000) {
                    local_2c = *(uint **)(iVar7 + (int)local_28 * 4);
                    local_20 = *(uint **)(iVar7 + local_34 * 4);
                    uVar13 = *local_2c;
                    uVar6 = *local_20 | uVar13;
                    uVar11 = uVar6 & 0xe000000;
                    uVar9 = 0x8000000;
                    if ((((uVar6 & 0x8000000) != 0) || (uVar9 = 0x4000000, (uVar6 & 0x4000000) != 0)
                        ) || (uVar9 = 0x2000000, (uVar6 & 0x2000000) != 0)) {
                      uVar11 = uVar9;
                    }
                    uVar11 = uVar11 | **(uint **)(iVar7 + uVar14 * 4) & 0xe000000;
                    uVar9 = 0x2000000;
                    if ((((uVar11 & 0x2000000) != 0) ||
                        (uVar9 = 0x4000000, (uVar11 & 0x4000000) != 0)) ||
                       (uVar9 = 0x8000000, (uVar11 & 0x8000000) != 0)) {
                      uVar11 = uVar9;
                    }
                    if (((uVar11 != (uVar13 & 0xe000000)) &&
                        ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + local_2c[1] * 4) + 4) & 2) !=
                         0)) && (local_2c[0x17] == 1)) {
                      *local_2c = uVar13 & 0xf1ffffff | uVar11;
                      local_8 = 1;
                    }
                    local_38 = (uint *)*local_20;
                    if (((uVar11 != ((uint)local_38 & 0xe000000)) &&
                        ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + local_20[1] * 4) + 4) & 2) !=
                         0)) && (local_20[0x17] == 1)) {
                      *local_20 = (uint)local_38 & 0xf1ffffff | uVar11;
                      local_8 = 1;
                    }
                  }
                  local_30 = uVar14;
                  iVar7 = FUN_0091dfaa(puVar1,uVar14,local_3c,local_28,local_34);
                  if (iVar7 < 0) {
                    return iVar7;
                  }
                  iVar7 = *(int *)(in_ECX + 0x14);
                  piVar12 = (int *)(iVar7 + uVar14 * 4);
                  uVar13 = *(uint *)(*piVar12 + 0x30);
                  if (uVar13 == uVar14) {
                    local_18 = local_18 + 1;
                  }
                  else if (*(int *)(*(int *)(iVar7 + uVar13 * 4) + 0x30) == -1) {
                    iVar10 = *(int *)(*piVar12 + 0x30);
                    *(int *)(*(int *)(iVar7 + iVar10 * 4) + 0x30) = iVar10;
                  }
                  local_c = local_c + 1;
                } while (local_c < puVar1[3]);
              }
              uVar14 = puVar1[3];
              if (local_18 != uVar14) {
                if (local_18 == 0) {
                  local_20 = (uint *)0x1;
                  if (1 < uVar14) {
                    piVar12 = (int *)puVar1[4];
                    iVar7 = *(int *)(in_ECX + 0x14);
                    iVar10 = *piVar12;
                    do {
                      piVar12 = piVar12 + 1;
                      if (*(int *)(*(int *)(iVar7 + *(int *)(*(int *)(iVar7 + iVar10 * 4) + 0x30) *
                                                    4) + 4) !=
                          *(int *)(*(int *)(iVar7 + *(int *)(*(int *)(iVar7 + *piVar12 * 4) + 0x30)
                                                    * 4) + 4)) {
                        uVar14 = puVar1[3];
                        if (uVar14 != 0) goto LAB_009233af;
                        break;
                      }
                      local_20 = (uint *)((int)local_20 + 1);
                    } while (local_20 < (uint *)puVar1[3]);
                  }
                  local_10 = 0;
                  if (puVar1[3] != 0) {
                    do {
                      iVar7 = *(int *)(*(int *)(in_ECX + 0x14) +
                                      *(int *)(puVar1[4] + local_10 * 4) * 4);
                      iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar7 + 0x30) * 4);
                      if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar10 + 4) * 4) +
                                     4) & 2) != 0) && (*(int *)(iVar10 + 0x60) == 0)) {
                        *(undefined4 *)(iVar10 + 0x60) = *(undefined4 *)(iVar7 + 0x60);
                        *(undefined4 *)(iVar10 + 100) =
                             *(undefined4 *)
                              (*(int *)(*(int *)(in_ECX + 0x14) +
                                       *(int *)(puVar1[4] + local_10 * 4) * 4) + 100);
                      }
                      local_10 = local_10 + 1;
                    } while (local_10 < puVar1[3]);
                  }
                  goto LAB_009236d3;
                }
LAB_009233af:
                local_18 = 0;
                if (uVar14 != 0) {
                  do {
                    uVar14 = *(uint *)(puVar1[4] + local_18 * 4);
                    local_3c = *(uint **)(*(int *)(in_ECX + 0x14) + uVar14 * 4);
                    if (local_3c[0xc] != uVar14) {
                      uVar13 = **(uint **)(*(int *)(in_ECX + 0x14) + local_3c[0xc] * 4) & 0xf1ffffff
                               | *local_3c;
                      if (*local_3c != uVar13) {
                        *local_3c = uVar13;
                        local_8 = 1;
                      }
                      *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar14 * 4) + 0x30) = uVar14;
                    }
                    local_18 = local_18 + 1;
                  } while (local_18 < puVar1[3]);
                }
                uVar14 = local_10;
                uVar13 = local_10;
                if (local_10 < *(uint *)(in_ECX + 8)) {
                  do {
                    if (*(int *)(*(int *)(in_ECX + 0x14) + uVar13 * 4) != 0) {
                      FUN_008f61e7();
                      uVar14 = local_10;
                    }
                    uVar13 = uVar13 + 1;
                  } while (uVar13 < *(uint *)(in_ECX + 8));
                }
                goto LAB_00923427;
              }
              goto LAB_009236e4;
            }
            if (uVar13 != 0x50000000) {
              if (uVar14 == 0x50100004) {
                iVar7 = *(int *)(in_ECX + 0x14);
                local_4c[2] = -1;
                local_4c[1] = -1;
                local_4c[3] = 1;
                local_4c[0] = 1;
                piVar12 = (int *)puVar1[2];
                iVar10 = *(int *)(iVar7 + *piVar12 * 4);
                local_18 = *(uint *)(iVar7 + piVar12[3] * 4);
                local_20 = *(uint **)(iVar7 + piVar12[1] * 4);
                iVar4 = *(int *)(in_ECX + 0x10);
                if (((*(byte *)(*(int *)(iVar4 + *(int *)(iVar10 + 4) * 4) + 5) & 1) == 0) ||
                   (*(int *)(iVar10 + 8) != -1)) {
                  if (*(int *)(*(int *)(iVar7 + *(int *)(puVar1[4] + 4) * 4) + 0x5c) == 0) {
                    local_4c[1] = 0;
                  }
LAB_009235b4:
                  if (*(int *)(*(int *)(iVar7 + *(int *)(puVar1[4] + 8) * 4) + 0x5c) == 0) {
                    local_4c[2] = 0;
                  }
                  if ((local_4c[1] == -1) || (local_4c[2] == -1)) goto LAB_009236e4;
                }
                else if (*(double *)(iVar10 + 0x20) <= _DAT_0099d098) {
                  local_4c[1] = 0;
LAB_0092359b:
                  local_4c[2] = 0;
                }
                else {
                  local_4c[1] = 2;
                  if (((*(byte *)(*(int *)(iVar4 + local_20[1] * 4) + 5) & 1) == 0) ||
                     (local_20[2] != 0xffffffff)) goto LAB_009235b4;
                  if (*(double *)(local_20 + 8) <= _DAT_0099d098) goto LAB_0092359b;
                  if (((*(byte *)(*(int *)(iVar4 + *(int *)(local_18 + 4) * 4) + 5) & 1) == 0) ||
                     (*(int *)(local_18 + 8) != -1)) goto LAB_009235b4;
                  if (_DAT_0099d098 == *(double *)(local_18 + 0x20)) {
                    local_4c[2] = 1;
                  }
                  else {
                    if (_DAT_0099d0a0 != *(double *)(local_18 + 0x20)) goto LAB_009235b4;
                    local_4c[2] = 3;
                  }
                }
                uVar14 = 0;
                do {
                  iVar7 = *(int *)((int)local_4c + uVar14);
                  if (iVar7 == 0) {
                    if (local_14 == -1) {
                      local_14 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,0);
                      *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + local_14 * 4) + 0x30) = local_14;
                    }
                    iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(uVar14 + puVar1[4]) * 4);
                    iVar10 = local_14;
LAB_0092367f:
                    *(int *)(iVar7 + 0x30) = iVar10;
                  }
                  else {
                    if (iVar7 == 1) {
                      if (local_24 == -1) {
                        local_24 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,
                                                0x3ff0000000000000);
                        *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + local_24 * 4) + 0x30) = local_24
                        ;
                      }
                      iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(uVar14 + puVar1[4]) * 4);
                      iVar10 = local_24;
                      goto LAB_0092367f;
                    }
                    if (iVar7 == 2) {
                      uVar8 = *(undefined4 *)puVar1[2];
LAB_009235f9:
                      *(undefined4 *)
                       (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(uVar14 + puVar1[4]) * 4) + 0x30)
                           = uVar8;
                    }
                    else if (iVar7 == 3) {
                      uVar8 = *(undefined4 *)(puVar1[2] + 4);
                      goto LAB_009235f9;
                    }
                  }
                  local_3c = *(uint **)(*(int *)(in_ECX + 0x14) + *(int *)(uVar14 + puVar1[4]) * 4);
                  iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + local_3c[0xc] * 4);
                  if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4) + 4) &
                       2) != 0) && (*(int *)(iVar7 + 0x60) == 0)) {
                    *(uint *)(iVar7 + 0x60) = local_3c[0x18];
                    *(undefined4 *)(iVar7 + 100) =
                         *(undefined4 *)
                          (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(uVar14 + puVar1[4]) * 4) +
                          100);
                  }
                  uVar14 = uVar14 + 4;
                } while (uVar14 < 0x10);
                goto LAB_009236d3;
              }
              goto LAB_009236e4;
            }
            iVar7 = FUN_0091635e(puVar1,1);
            if (iVar7 < 0) {
              return iVar7;
            }
            if (iVar7 != 1) {
              local_8 = 1;
            }
            iVar7 = *(int *)puVar1[4];
            iVar10 = *(int *)(in_ECX + 0x14);
            if (*(int *)(*(int *)(iVar10 + iVar7 * 4) + 0x30) == iVar7) goto LAB_009236e4;
            iVar7 = *(int *)(iVar10 + iVar7 * 4);
            iVar10 = *(int *)(iVar10 + *(int *)(iVar7 + 0x30) * 4);
            if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar10 + 4) * 4) + 4) & 2)
                 != 0) && (*(int *)(iVar10 + 0x60) == 0)) {
              *(undefined4 *)(iVar10 + 0x60) = *(undefined4 *)(iVar7 + 0x60);
              *(undefined4 *)(iVar10 + 100) =
                   *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar1[4] * 4) + 100);
            }
            uVar14 = 0;
            puVar1[1] = 0;
            puVar1[3] = 0;
            goto LAB_009236e2;
          }
          local_18 = 0;
          local_c = 0;
          if (puVar1[3] != 0) {
            do {
              puVar5 = *(uint **)(local_c * 4 + puVar1[4]);
              iVar7 = *(int *)(in_ECX + 0x14);
              local_2c = *(uint **)(*(int *)(iVar7 + *(int *)(local_c * 4 + puVar1[2]) * 4) + 0x30);
              local_34 = *(int *)(*(int *)(iVar7 + *(int *)(puVar1[2] + (puVar1[3] + local_c) * 4) *
                                                   4) + 0x30);
              if (((*puVar1 & 0xfff00000) == 0x20000000) || ((*puVar1 & 0xfff00000) == 0x20100000))
              {
                local_28 = *(uint **)(iVar7 + (int)local_2c * 4);
                local_20 = *(uint **)(iVar7 + local_34 * 4);
                uVar14 = *local_28;
                uVar9 = *local_20 | uVar14;
                uVar6 = uVar9 & 0xe000000;
                uVar13 = 0x8000000;
                if (((uVar9 & 0x8000000) != 0) ||
                   ((uVar13 = 0x4000000, (uVar9 & 0x4000000) != 0 ||
                    (uVar13 = 0x2000000, (uVar9 & 0x2000000) != 0)))) {
                  uVar6 = uVar13;
                }
                uVar6 = uVar6 | **(uint **)(iVar7 + (int)puVar5 * 4) & 0xe000000;
                uVar13 = 0x2000000;
                if ((((uVar6 & 0x2000000) != 0) || (uVar13 = 0x4000000, (uVar6 & 0x4000000) != 0))
                   || (uVar13 = 0x8000000, (uVar6 & 0x8000000) != 0)) {
                  uVar6 = uVar13;
                }
                if (((uVar6 != (uVar14 & 0xe000000)) &&
                    ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + local_28[1] * 4) + 4) & 2) != 0))
                   && (local_28[0x17] == 1)) {
                  *local_28 = uVar14 & 0xf1ffffff | uVar6;
                  local_8 = 1;
                }
                local_30 = *local_20;
                if (((uVar6 != (local_30 & 0xe000000)) &&
                    ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + local_20[1] * 4) + 4) & 2) != 0))
                   && (local_20[0x17] == 1)) {
                  *local_20 = local_30 & 0xf1ffffff | uVar6;
                  local_8 = 1;
                }
              }
              local_38 = puVar5;
              iVar7 = FUN_0091d02d(puVar1,puVar5,local_2c,local_34);
              if (iVar7 < 0) {
                return iVar7;
              }
              iVar7 = *(int *)(in_ECX + 0x14);
              piVar12 = (int *)(iVar7 + (int)puVar5 * 4);
              puVar2 = *(uint **)(*piVar12 + 0x30);
              if (puVar2 == puVar5) {
                local_18 = local_18 + 1;
              }
              else if (*(int *)(*(int *)(iVar7 + (int)puVar2 * 4) + 0x30) == -1) {
                iVar10 = *(int *)(*piVar12 + 0x30);
                *(int *)(*(int *)(iVar7 + iVar10 * 4) + 0x30) = iVar10;
              }
              local_c = local_c + 1;
            } while (local_c < puVar1[3]);
          }
          uVar14 = puVar1[3];
          if (local_18 != uVar14) {
            if (local_18 == 0) {
              local_20 = (uint *)0x1;
              if (1 < uVar14) {
                piVar12 = (int *)puVar1[4];
                iVar7 = *(int *)(in_ECX + 0x14);
                iVar10 = *piVar12;
                do {
                  piVar12 = piVar12 + 1;
                  if (*(int *)(*(int *)(iVar7 + *(int *)(*(int *)(iVar7 + iVar10 * 4) + 0x30) * 4) +
                              4) !=
                      *(int *)(*(int *)(iVar7 + *(int *)(*(int *)(iVar7 + *piVar12 * 4) + 0x30) * 4)
                              + 4)) {
                    uVar14 = puVar1[3];
                    if (uVar14 != 0) goto LAB_009230d6;
                    break;
                  }
                  local_20 = (uint *)((int)local_20 + 1);
                } while (local_20 < (uint *)puVar1[3]);
              }
              local_c = 0;
              if (puVar1[3] != 0) {
                do {
                  iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar1[4] + local_c * 4) * 4);
                  iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar7 + 0x30) * 4);
                  if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar10 + 4) * 4) + 4)
                       & 2) != 0) && (*(int *)(iVar10 + 0x60) == 0)) {
                    *(undefined4 *)(iVar10 + 0x60) = *(undefined4 *)(iVar7 + 0x60);
                    *(undefined4 *)(iVar10 + 100) =
                         *(undefined4 *)
                          (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar1[4] + local_c * 4) * 4)
                          + 100);
                  }
                  local_c = local_c + 1;
                } while (local_c < puVar1[3]);
              }
              goto LAB_009236d3;
            }
LAB_009230d6:
            local_18 = 0;
            if (uVar14 != 0) {
              do {
                uVar14 = *(uint *)(puVar1[4] + local_18 * 4);
                local_38 = *(uint **)(*(int *)(in_ECX + 0x14) + uVar14 * 4);
                if (local_38[0xc] != uVar14) {
                  uVar13 = **(uint **)(*(int *)(in_ECX + 0x14) + local_38[0xc] * 4) & 0xf1ffffff |
                           *local_38;
                  if (*local_38 != uVar13) {
                    *local_38 = uVar13;
                    local_8 = 1;
                  }
                  *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar14 * 4) + 0x30) = uVar14;
                }
                local_18 = local_18 + 1;
              } while (local_18 < puVar1[3]);
            }
            uVar14 = local_10;
            if (local_10 < *(uint *)(in_ECX + 8)) {
              do {
                if (*(int *)(*(int *)(in_ECX + 0x14) + uVar14 * 4) != 0) {
                  FUN_008f61e7();
                }
                uVar14 = uVar14 + 1;
              } while (uVar14 < *(uint *)(in_ECX + 8));
            }
            uVar14 = local_10;
LAB_00923427:
            *(uint *)(in_ECX + 8) = uVar14;
          }
        }
LAB_009236e4:
        if (puVar1[3] != 0) {
          local_18 = 0;
          piVar12 = (int *)puVar1[4];
          do {
            puVar5 = *(uint **)(*(int *)(in_ECX + 0x14) + *piVar12 * 4);
            local_30 = *puVar5;
            if (((((local_30 & 0x40) != 0) ||
                 ((*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + puVar5[1] * 4) + 4) & 0x11028) != 0)
                 ) || ((local_30 & 4) == 0)) || ((local_30 & 8) == 0)) break;
            local_18 = local_18 + 1;
            piVar12 = piVar12 + 1;
          } while (local_18 < puVar1[3]);
          if (local_18 == puVar1[3]) {
            if (local_14 == -1) {
              local_14 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,0);
              *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + local_14 * 4) + 0x30) = local_14;
            }
            uVar14 = 0;
            if (puVar1[3] != 0) {
              do {
                iVar7 = uVar14 * 4;
                uVar14 = uVar14 + 1;
                *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar1[4] + iVar7) * 4) + 0x30)
                     = local_14;
              } while (uVar14 < puVar1[3]);
            }
            *puVar1 = 0;
            puVar1[1] = 0;
            puVar1[3] = 0;
            local_8 = 1;
          }
        }
      }
      local_1c = local_1c + 1;
    } while (local_1c < *(uint *)(in_ECX + 0xc));
    if (local_8 != 0) {
      FUN_00919e8f();
      return 0;
    }
  }
  return 1;
}


// ==== FUN_009237bb @ 0x009237bb ====

undefined4 FUN_009237bb(void)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  bool bVar4;
  undefined4 *_Memory;
  uint uVar5;
  int iVar6;
  undefined4 extraout_EAX;
  int in_ECX;
  uint uVar7;
  undefined4 *local_14;
  uint local_c;
  uint local_8;
  
  uVar7 = 0;
  FUN_009198e4();
  _Memory = operator_new(*(int *)(in_ECX + 8) << 2);
  if (_Memory == (undefined4 *)0x0) {
    return 0x8007000e;
  }
  uVar5 = 0;
  local_c = 0;
  bVar4 = false;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + uVar5 * 4);
      *(uint *)(iVar6 + 0x30) = uVar5;
      uVar2 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar6 + 4) * 4) + 4);
      if (((uVar2 & 0x100) != 0) && ((uVar2 & 0xc00) == 0)) {
        _Memory[uVar7] = uVar5;
        uVar7 = uVar7 + 1;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(in_ECX + 8));
    local_c = uVar7;
  }
  FUN_00915b0e(FUN_009156d7,_Memory,local_c,in_ECX);
  local_8 = 1;
  if (1 < local_c) {
    do {
      piVar1 = _Memory + local_8;
      iVar6 = FUN_009156d7(*(undefined4 *)
                            (*(int *)(*(int *)(in_ECX + 0x14) + _Memory[local_8 - 1] * 4) + 0x30),
                           *piVar1,in_ECX);
      if (iVar6 == 0) {
        *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar1 * 4) + 4) =
             *(undefined4 *)(in_ECX + 0x74);
        *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar1 * 4) + 0x30) =
             *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + _Memory[local_8 - 1] * 4) + 0x30);
        bVar4 = true;
      }
      local_8 = local_8 + 1;
    } while (local_8 < local_c);
    if (bVar4) {
      FUN_00919e8f();
    }
  }
  uVar7 = 0;
  uVar5 = 0;
  local_c = 0;
  bVar4 = false;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + uVar7 * 4);
      *(uint *)(iVar6 + 0x30) = uVar7;
      iVar6 = *(int *)(iVar6 + 4);
      if ((*(int *)(in_ECX + 0x74) != iVar6) &&
         (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + iVar6 * 4) + 4) & 0x40) != 0 ||
          (*(int *)(in_ECX + 0xdc) != 0)))) {
        _Memory[uVar5] = uVar7;
        uVar5 = uVar5 + 1;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(in_ECX + 8));
    local_c = uVar5;
  }
  FUN_00915b0e(FUN_00915726,_Memory,local_c,in_ECX);
  local_14 = _Memory;
  if (local_c != 0) {
    local_14 = (undefined4 *)*_Memory;
  }
  local_8 = 1;
  if (1 < local_c) {
    do {
      puVar3 = (undefined4 *)_Memory[local_8];
      iVar6 = FUN_00915726(local_14,puVar3,in_ECX);
      if (iVar6 == 0) {
        FUN_0091c89b(local_14,puVar3);
        *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + _Memory[local_8] * 4) + 4) =
             *(undefined4 *)(in_ECX + 0x74);
        bVar4 = true;
      }
      else {
        local_14 = puVar3;
      }
      local_8 = local_8 + 1;
    } while (local_8 < local_c);
    if (bVar4) {
      FUN_00919e8f();
    }
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_00923987 @ 0x00923987 ====

undefined4 FUN_00923987(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint local_38;
  uint local_34;
  int local_24;
  int local_20;
  uint local_1c;
  uint local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  bVar3 = false;
  FUN_00919e76();
  local_34 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      iVar12 = -1;
      puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + local_34 * 4);
      uVar7 = *puVar2 & 0xf0000000;
      if ((0xfffffff < uVar7) && (uVar7 < 0x40000001)) {
        local_14 = *puVar2 & 0xfffff;
        uVar7 = puVar2[1] / local_14;
        iVar4 = FUN_0091464c();
        local_1c = local_14;
        local_c = 1;
        if (1 < local_14) {
          iVar5 = local_14 * 4;
          local_10 = 4;
          local_24 = iVar5;
          do {
            local_24 = local_24 + 4;
            iVar9 = *(int *)(in_ECX + 0x14);
            if (((*(ushort *)
                   (*(int *)(*(int *)(in_ECX + 0x10) +
                            *(int *)(*(int *)(iVar9 + *(int *)(puVar2[4] + local_10) * 4) + 4) * 4)
                   + 4) & 0x1020) == 0) && (local_8 = 0, local_10 != 0)) {
              local_20 = iVar5;
              do {
                iVar10 = *(int *)(puVar2[4] + local_8 * 4);
                if ((iVar10 == -1) ||
                   ((*(ushort *)
                      (*(int *)(*(int *)(in_ECX + 0x10) +
                               *(int *)(*(int *)(iVar9 + iVar10 * 4) + 4) * 4) + 4) & 0x1020) != 0))
                goto LAB_00923d1b;
                if (uVar7 == 1) {
                  iVar10 = *(int *)(puVar2[2] + local_10);
                  if (iVar10 == -1) {
                    iVar10 = iVar12;
                  }
                  else {
                    iVar10 = *(int *)(*(int *)(iVar9 + iVar10 * 4) + 0x30);
                  }
                  iVar6 = *(int *)(puVar2[2] + local_8 * 4);
                  if (iVar6 == -1) {
                    iVar6 = iVar12;
                  }
                  else {
                    iVar6 = *(int *)(*(int *)(iVar9 + iVar6 * 4) + 0x30);
                  }
                  if (iVar10 != iVar6) goto LAB_00923abf;
LAB_00923d33:
                  FUN_0091c89b(*(undefined4 *)(puVar2[4] + local_8 * 4),
                               *(int *)(puVar2[4] + local_10));
                  local_1c = local_1c - 1;
                  *(undefined4 *)(local_10 + puVar2[4]) = 0xffffffff;
                  break;
                }
LAB_00923abf:
                if (uVar7 == 2) {
                  uVar11 = puVar2[2];
                  if (*(int *)(uVar11 + local_10) == -1) {
                    iVar10 = iVar12;
                  }
                  else {
                    iVar10 = *(int *)(*(int *)(iVar9 + *(int *)(uVar11 + local_10) * 4) + 0x30);
                  }
                  iVar6 = *(int *)(uVar11 + local_8 * 4);
                  if (iVar6 == -1) {
                    iVar8 = iVar12;
                  }
                  else {
                    iVar8 = *(int *)(*(int *)(iVar9 + iVar6 * 4) + 0x30);
                  }
                  if (iVar10 == iVar8) {
                    if (*(int *)(uVar11 + local_24) == -1) {
                      iVar10 = iVar12;
                    }
                    else {
                      iVar10 = *(int *)(*(int *)(iVar9 + *(int *)(uVar11 + local_24) * 4) + 0x30);
                    }
                    if (*(int *)(uVar11 + local_20) == -1) {
                      iVar8 = iVar12;
                    }
                    else {
                      iVar8 = *(int *)(*(int *)(iVar9 + *(int *)(uVar11 + local_20) * 4) + 0x30);
                    }
                    if (iVar10 == iVar8) goto LAB_00923d33;
                  }
                  if (iVar4 != 0) {
                    if (*(int *)(uVar11 + local_10) == -1) {
                      iVar10 = iVar12;
                    }
                    else {
                      iVar10 = *(int *)(*(int *)(iVar9 + *(int *)(uVar11 + local_10) * 4) + 0x30);
                    }
                    if (*(int *)(uVar11 + local_20) == -1) {
                      iVar8 = iVar12;
                    }
                    else {
                      iVar8 = *(int *)(*(int *)(iVar9 + *(int *)(uVar11 + local_20) * 4) + 0x30);
                    }
                    if (iVar10 == iVar8) {
                      if (*(int *)(uVar11 + local_24) == -1) {
                        iVar10 = iVar12;
                      }
                      else {
                        iVar10 = *(int *)(*(int *)(iVar9 + *(int *)(uVar11 + local_24) * 4) + 0x30);
                      }
                      if (iVar6 == -1) {
                        iVar6 = iVar12;
                      }
                      else {
                        iVar6 = *(int *)(*(int *)(iVar9 + iVar6 * 4) + 0x30);
                      }
                      if (iVar10 == iVar6) goto LAB_00923d33;
                      goto LAB_00923b92;
                    }
                  }
                }
                else {
LAB_00923b92:
                  if (uVar7 == 3) {
                    uVar11 = puVar2[2];
                    if (*(int *)(uVar11 + local_10) == -1) {
                      iVar10 = iVar12;
                    }
                    else {
                      iVar10 = *(int *)(*(int *)(iVar9 + *(int *)(uVar11 + local_10) * 4) + 0x30);
                    }
                    iVar6 = *(int *)(uVar11 + local_8 * 4);
                    if (iVar6 == -1) {
                      iVar6 = iVar12;
                    }
                    else {
                      iVar6 = *(int *)(*(int *)(iVar9 + iVar6 * 4) + 0x30);
                    }
                    if (iVar10 == iVar6) {
                      if (*(int *)(uVar11 + local_24) == -1) {
                        iVar10 = iVar12;
                      }
                      else {
                        iVar10 = *(int *)(*(int *)(iVar9 + *(int *)(uVar11 + local_24) * 4) + 0x30);
                      }
                      if (*(int *)(uVar11 + local_20) == -1) {
                        iVar6 = iVar12;
                      }
                      else {
                        iVar6 = *(int *)(*(int *)(iVar9 + *(int *)(uVar11 + local_20) * 4) + 0x30);
                      }
                      if (iVar10 == iVar6) {
                        iVar10 = *(int *)(uVar11 + (local_c + local_14 * 2) * 4);
                        if (iVar10 == -1) {
                          local_38 = -1;
                        }
                        else {
                          local_38 = *(int *)(*(int *)(iVar9 + iVar10 * 4) + 0x30);
                        }
                        iVar10 = *(int *)(uVar11 + (local_14 * 2 + local_8) * 4);
                        if (iVar10 == -1) {
                          iVar10 = iVar12;
                        }
                        else {
                          iVar10 = *(int *)(*(int *)(iVar9 + iVar10 * 4) + 0x30);
                        }
                        if (local_38 == iVar10) goto LAB_00923d33;
                        goto LAB_00923c3d;
                      }
                    }
                  }
                  else {
LAB_00923c3d:
                    if (uVar7 == 4) {
                      uVar11 = puVar2[2];
                      if (*(int *)(uVar11 + local_10) == -1) {
                        iVar10 = iVar12;
                      }
                      else {
                        iVar10 = *(int *)(*(int *)(iVar9 + *(int *)(uVar11 + local_10) * 4) + 0x30);
                      }
                      iVar6 = *(int *)(uVar11 + local_8 * 4);
                      if (iVar6 == -1) {
                        iVar6 = iVar12;
                      }
                      else {
                        iVar6 = *(int *)(*(int *)(iVar9 + iVar6 * 4) + 0x30);
                      }
                      if (iVar10 == iVar6) {
                        if (*(int *)(uVar11 + local_24) == -1) {
                          iVar10 = iVar12;
                        }
                        else {
                          iVar10 = *(int *)(*(int *)(iVar9 + *(int *)(uVar11 + local_24) * 4) + 0x30
                                           );
                        }
                        if (*(int *)(uVar11 + local_20) == -1) {
                          iVar6 = iVar12;
                        }
                        else {
                          iVar6 = *(int *)(*(int *)(iVar9 + *(int *)(uVar11 + local_20) * 4) + 0x30)
                          ;
                        }
                        if (iVar10 == iVar6) {
                          iVar10 = *(int *)(uVar11 + (local_c + local_14 * 2) * 4);
                          if (iVar10 == -1) {
                            local_38 = -1;
                          }
                          else {
                            local_38 = *(int *)(*(int *)(iVar9 + iVar10 * 4) + 0x30);
                          }
                          iVar10 = *(int *)(uVar11 + (local_14 * 2 + local_8) * 4);
                          if (iVar10 == -1) {
                            iVar10 = iVar12;
                          }
                          else {
                            iVar10 = *(int *)(*(int *)(iVar9 + iVar10 * 4) + 0x30);
                          }
                          if (local_38 == iVar10) {
                            iVar10 = *(int *)(uVar11 + (local_c + local_14 * 3) * 4);
                            if (iVar10 == -1) {
                              local_38 = -1;
                            }
                            else {
                              local_38 = *(int *)(*(int *)(iVar9 + iVar10 * 4) + 0x30);
                            }
                            iVar10 = *(int *)(uVar11 + (local_14 * 3 + local_8) * 4);
                            if (iVar10 == -1) {
                              iVar10 = iVar12;
                            }
                            else {
                              iVar10 = *(int *)(*(int *)(iVar9 + iVar10 * 4) + 0x30);
                            }
                            if (local_38 == iVar10) goto LAB_00923d33;
                          }
                        }
                      }
                    }
                  }
                }
LAB_00923d1b:
                local_8 = local_8 + 1;
                local_20 = local_20 + 4;
              } while (local_8 < local_c);
            }
            local_c = local_c + 1;
            local_10 = local_10 + 4;
          } while (local_c < local_14);
          if (local_1c < local_14) {
            local_c = 0;
            if (local_14 != 0) {
              iVar12 = 0;
              do {
                iVar9 = local_c * 4;
                iVar4 = *(int *)(puVar2[4] + iVar9);
                if (iVar4 != -1) {
                  *(int *)(puVar2[4] + iVar12) = iVar4;
                  if (uVar7 != 0) {
                    iVar4 = iVar12;
                    uVar11 = uVar7;
                    do {
                      puVar1 = (undefined4 *)(puVar2[2] + iVar9);
                      iVar9 = iVar9 + iVar5;
                      *(undefined4 *)(puVar2[2] + iVar4) = *puVar1;
                      iVar4 = iVar4 + iVar5;
                      uVar11 = uVar11 - 1;
                    } while (uVar11 != 0);
                  }
                  iVar12 = iVar12 + 4;
                }
                local_c = local_c + 1;
              } while (local_c < local_14);
            }
            if (1 < uVar7) {
              iVar4 = uVar7 - 1;
              iVar12 = iVar5;
              local_24 = local_1c * 4;
              do {
                if (local_1c != 0) {
                  local_38 = local_1c;
                  iVar9 = iVar12;
                  iVar10 = local_24;
                  do {
                    *(undefined4 *)(puVar2[2] + iVar10) = *(undefined4 *)(puVar2[2] + iVar9);
                    iVar9 = iVar9 + 4;
                    iVar10 = iVar10 + 4;
                    local_38 = local_38 - 1;
                  } while (local_38 != 0);
                }
                iVar12 = iVar12 + iVar5;
                local_24 = local_24 + local_1c * 4;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            *puVar2 = *puVar2 ^ (*puVar2 ^ local_1c) & 0xfffff;
            puVar2[1] = local_1c * uVar7;
            puVar2[3] = local_1c;
            bVar3 = true;
          }
        }
      }
      local_34 = local_34 + 1;
    } while (local_34 < *(uint *)(in_ECX + 0xc));
    if (bVar3) {
      FUN_00919e8f();
      return 0;
    }
  }
  return 1;
}


// ==== FUN_00923e5f @ 0x00923e5f ====

void FUN_00923e5f(uint param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  bool bVar7;
  uint *_Memory;
  int *piVar8;
  int iVar9;
  uint uVar10;
  int in_ECX;
  uint uVar11;
  bool bVar12;
  uint local_24;
  uint *local_14;
  uint local_10;
  uint local_8;
  
  local_8 = 0;
  _Memory = operator_new(*(int *)(in_ECX + 0xc) << 2);
  if (_Memory != (uint *)0x0) {
    local_10 = 0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        puVar3 = *(uint **)(*(int *)(in_ECX + 0x18) + local_10 * 4);
        uVar11 = *puVar3 & 0xfff00000;
        if ((((uVar11 != 0) &&
             ((((param_1 == 0 || (puVar3[9] == 0)) && (uVar11 != 0x10f00000)) &&
              ((uVar11 != 0x20700000 && (uVar11 != 0x11100000)))))) && (uVar11 != 0x11200000)) &&
           (((uVar11 != 0x11300000 && (uVar11 != 0x11400000)) &&
            ((uVar11 != 0x20800000 && ((uVar11 != 0x20900000 && (uVar11 != 0x11500000)))))))) {
          uVar11 = puVar3[3];
          local_14 = (uint *)0x0;
          if (uVar11 != 0) {
            piVar8 = (int *)puVar3[4];
            do {
              if ((*(ushort *)
                    (*(int *)(*(int *)(in_ECX + 0x10) +
                             *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar8 * 4) + 4) * 4) + 4)
                  & 0x1020) != 0) break;
              local_14 = (uint *)((int)local_14 + 1);
              piVar8 = piVar8 + 1;
            } while (local_14 < uVar11);
          }
          if (uVar11 <= local_14) {
            _Memory[local_8] = local_10;
            local_8 = local_8 + 1;
          }
        }
        local_10 = local_10 + 1;
      } while (local_10 < *(uint *)(in_ECX + 0xc));
    }
    bVar7 = false;
    while( true ) {
      uVar11 = local_8;
      bVar12 = false;
      FUN_00919e76();
      FUN_00915b0e(FUN_0091a2be,_Memory,local_8,in_ECX);
      if (local_8 == 0) break;
      local_10 = 1;
      local_24 = local_8;
      local_14 = _Memory;
      do {
        uVar4 = *local_14;
        if (uVar4 != 0xffffffff) {
          for (uVar10 = local_10; uVar10 < local_8; uVar10 = uVar10 + 1) {
            uVar5 = _Memory[uVar10];
            if (uVar5 != 0xffffffff) {
              if ((uVar5 <= uVar4) || (iVar9 = FUN_0091a11f(uVar5,in_ECX), iVar9 != 0)) break;
              iVar9 = *(int *)(*(int *)(in_ECX + 0x18) + uVar4 * 4);
              puVar6 = *(undefined4 **)(*(int *)(in_ECX + 0x18) + uVar5 * 4);
              param_1 = 0;
              if (*(int *)(iVar9 + 0xc) != 0) {
                do {
                  iVar1 = param_1 * 4;
                  iVar2 = param_1 * 4;
                  param_1 = param_1 + 1;
                  *(undefined4 *)
                   (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar6[4] + iVar1) * 4) + 0x30) =
                       *(undefined4 *)(*(int *)(iVar9 + 0x10) + iVar2);
                } while (param_1 < *(uint *)(iVar9 + 0xc));
              }
              _Memory[uVar10] = 0xffffffff;
              *puVar6 = 0;
              puVar6[1] = 0;
              puVar6[3] = 0;
              bVar7 = true;
              bVar12 = true;
            }
          }
        }
        local_14 = local_14 + 1;
        local_10 = local_10 + 1;
        local_24 = local_24 - 1;
      } while (local_24 != 0);
      if (!bVar12) break;
      bVar12 = local_8 != 0;
      local_8 = 0;
      local_24 = 0;
      if (bVar12) {
        do {
          uVar4 = _Memory[local_24];
          if (uVar4 != 0xffffffff) {
            iVar9 = *(int *)(*(int *)(in_ECX + 0x18) + uVar4 * 4);
            uVar10 = *(uint *)(iVar9 + 4);
            param_1 = 0;
            if (uVar10 != 0) {
              piVar8 = *(int **)(iVar9 + 8);
              do {
                if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar8 * 4) + 0x30) != *piVar8)
                break;
                param_1 = param_1 + 1;
                piVar8 = piVar8 + 1;
              } while (param_1 < uVar10);
            }
            if (param_1 != uVar10) {
              _Memory[local_8] = uVar4;
              local_8 = local_8 + 1;
            }
          }
          local_24 = local_24 + 1;
        } while (local_24 < uVar11);
      }
      FUN_00919e8f();
    }
    if (bVar7) {
      FUN_009237bb();
    }
  }
  _free(_Memory);
  return;
}


// ==== FUN_009240e6 @ 0x009240e6 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_009240e6(void)

{
  double dVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined4 extraout_EAX;
  undefined4 *puVar13;
  uint *puVar14;
  double *pdVar15;
  undefined4 extraout_EAX_00;
  int in_ECX;
  double *pdVar16;
  double *pdVar17;
  uint *puVar18;
  uint *puVar19;
  int iVar20;
  bool bVar21;
  int local_74 [4];
  int *local_64 [4];
  undefined1 local_54 [4];
  uint *local_50;
  int local_4c;
  int *local_48;
  double *local_44;
  uint *local_40;
  int local_3c;
  double *local_38;
  double *local_34;
  double *local_30;
  uint *local_2c;
  double *local_28;
  double *local_24;
  double *local_20;
  int local_1c;
  double *local_18;
  double *local_14;
  double *local_10;
  double *local_c;
  int local_8;
  
  local_3c = -1;
  local_1c = -1;
  local_14 = (double *)0x0;
  local_10 = (double *)0x0;
  local_24 = (double *)0x0;
  FUN_009198e4();
  uVar6 = 0;
  local_8 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar6 * 4) + 0x40) = 0xffffffff;
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(in_ECX + 8));
  }
  local_28 = (double *)0x0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      puVar19 = *(uint **)(*(int *)(in_ECX + 0x18) + (int)local_28 * 4);
      uVar6 = *puVar19 & 0xfff00000;
      local_2c = puVar19;
      if ((((uVar6 != 0) &&
           ((pdVar16 = (double *)puVar19[3], pdVar16 == (double *)0x0 ||
            ((**(byte **)(*(int *)(in_ECX + 0x14) + *(int *)puVar19[4] * 4) & 0x40) == 0)))) &&
          ((uVar6 == 0x20400000 || (uVar6 == 0x20500000)))) &&
         (local_18 = (double *)0x0, pdVar16 != (double *)0x0)) {
        do {
          local_c = (double *)0x0;
          local_64[0] = (int *)(puVar19[2] + (int)local_18 * 4);
          local_64[1] = (int *)(puVar19[2] + ((int)pdVar16 + (int)local_18) * 4);
          do {
            iVar7 = *(int *)(in_ECX + 0x14);
            local_74[0] = *(int *)(iVar7 + *local_64[0] * 4);
            iVar20 = 1 - (int)local_c;
            local_74[1] = *(undefined4 *)(iVar7 + *local_64[1] * 4);
            if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                   *(int *)(local_74[(int)local_c] + 4) * 4) + 4) & 2) != 0) {
              if (*(int *)(local_74[(int)local_c] + 8) == -1) {
                local_44 = *(double **)
                            (*(int *)(in_ECX + 0x18) + *(int *)(local_74[(int)local_c] + 0x48) * 4);
                if (((*(uint *)local_44 ^ *puVar19) & 0xfff00000) == 0) {
                  pdVar16 = *(double **)((int)local_44 + 0xc);
                  pdVar17 = (double *)0x0;
                  local_38 = pdVar16;
                  if (pdVar16 != (double *)0x0) {
                    piVar8 = *(int **)(local_44 + 2);
                    do {
                      if (*piVar8 == *local_64[(int)local_c]) break;
                      pdVar17 = (double *)((int)pdVar17 + 1);
                      piVar8 = piVar8 + 1;
                    } while (pdVar17 < pdVar16);
                  }
                  local_30 = (double *)0x0;
                  local_64[2] = (int *)(*(uint *)(local_44 + 1) + (int)pdVar17 * 4);
                  local_38 = (double *)0xffffffff;
                  iVar3 = *local_64[2];
                  local_64[3] = (int *)(*(uint *)(local_44 + 1) + ((int)pdVar16 + (int)pdVar17) * 4)
                  ;
                  iVar4 = *local_64[3];
                  local_74[3] = *(undefined4 *)(iVar7 + iVar4 * 4);
                  local_74[2] = *(undefined4 *)(iVar7 + iVar3 * 4);
                  local_40 = (uint *)local_74[(int)local_c];
                  if ((((uint *)local_74[(int)local_c])[0x17] == 1) && (iVar3 != iVar4)) {
                    FUN_00916aa5(*local_64[iVar20],&local_38,local_54);
                    local_44 = local_38;
                    iVar7 = FUN_00916aa5(*local_64[(int)local_c],&local_44,local_54);
                    local_30 = (double *)(uint)(-1 < iVar7);
                  }
                  local_20 = (double *)0x2;
                  do {
                    puVar19 = local_2c;
                    local_34 = (double *)(5 - (int)local_20);
                    local_44 = (double *)
                               (*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                                  *(int *)(local_74[(int)local_20] + 4) * 4) + 4) &
                               0x100);
                    if ((((local_44 != (double *)0x0) &&
                         (*(int *)(local_74[(int)local_20] + 8) == -1)) &&
                        ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                            *(int *)(local_74[iVar20] + 4) * 4) + 5) & 1) != 0)) &&
                       (*(int *)(local_74[iVar20] + 8) == -1)) {
                      dVar1 = 0.0;
                      if ((*local_2c & 0xfff00000) == 0x20400000) {
                        dVar1 = *(double *)(local_74[(int)local_20] + 0x20) +
                                *(double *)(local_74[iVar20] + 0x20);
                      }
                      else if ((*local_2c & 0xfff00000) == 0x20500000) {
                        dVar1 = *(double *)(local_74[(int)local_20] + 0x20) *
                                *(double *)(local_74[iVar20] + 0x20);
                      }
                      *local_64[(int)local_c] = *local_64[(int)local_34];
                      iVar7 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,dVar1);
                      *local_64[iVar20] = iVar7;
LAB_00924447:
                      *(undefined4 *)
                       (*(int *)(*(int *)(in_ECX + 0x14) +
                                *(int *)(puVar19[4] + (int)local_18 * 4) * 4) + 0x40) = 0xffffffff;
                      local_8 = 1;
                      goto LAB_00924461;
                    }
                    if (((local_40[0x17] == 1) &&
                        ((*(uint *)(local_74[iVar20] + 0x48) == 0xffffffff ||
                         (*(uint *)(local_74[iVar20] + 0x48) < local_40[0x12])))) &&
                       (*(int *)(local_74[iVar20] + 8) == -1)) {
                      if (((local_44 == (double *)0x0) ||
                          (*(int *)(local_74[(int)local_20] + 8) != -1)) ||
                         ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                             *(int *)(local_74[iVar20] + 4) * 4) + 5) & 1) != 0)) {
                        local_48 = local_64[(int)local_20];
                        iVar7 = *local_64[(int)local_20];
                        if (*local_64[(int)local_34] == iVar7) goto LAB_0092439d;
                        if (local_30 == (double *)0x0) {
                          local_44 = local_38;
                          iVar7 = FUN_00916aa5(iVar7,&local_44,local_54);
                          if (iVar7 < 0) goto LAB_0092438c;
                        }
                        else {
LAB_0092438c:
                          if (*local_64[iVar20] != *local_48) goto LAB_0092439d;
                        }
                        piVar8 = local_64[(int)local_34];
                      }
                      else {
                        piVar8 = local_64[(int)local_20];
                      }
                      iVar7 = *local_64[iVar20];
                      *local_64[iVar20] = *piVar8;
                      *piVar8 = iVar7;
                      iVar7 = local_74[(int)local_c];
                      *(undefined4 *)(iVar7 + 0x60) = 0;
                      *(undefined4 *)(iVar7 + 100) = 0;
                      *(undefined4 *)(iVar7 + 0x40) = 0xffffffff;
                      puVar19 = local_2c;
                      goto LAB_00924447;
                    }
LAB_0092439d:
                    local_20 = (double *)((int)local_20 + 1);
                  } while (local_20 < (double *)0x4);
                  puVar19 = local_2c;
                }
              }
            }
LAB_00924461:
            local_c = (double *)((int)local_c + 1);
          } while (local_c < (byte *)0x2);
          pdVar16 = (double *)puVar19[3];
          local_18 = (double *)((int)local_18 + 1);
        } while (local_18 < pdVar16);
      }
      local_28 = (double *)((int)local_28 + 1);
    } while (local_28 < *(uint *)(in_ECX + 0xc));
    if (local_8 != 0) {
      local_8 = 0;
      local_24 = (double *)0x1;
      FUN_009198e4();
    }
  }
  local_28 = (double *)0x0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      local_20 = *(double **)(*(int *)(in_ECX + 0x18) + (int)local_28 * 4);
      uVar6 = *(uint *)local_20 & 0xfff00000;
      if (((uVar6 != 0) &&
          ((*(uint *)((int)local_20 + 0xc) == 0 ||
           ((**(byte **)(*(int *)(in_ECX + 0x14) + **(int **)(local_20 + 2) * 4) & 0x40) == 0)))) &&
         (((uVar6 == 0x30000000 || (uVar6 == 0x11000000)) &&
          (local_2c = (uint *)0x0, *(uint *)((int)local_20 + 0xc) != 0)))) {
        do {
          local_44 = (double *)(*(uint *)(local_20 + 1) + (int)local_2c * 4);
          local_18 = *(double **)local_44;
          iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + (int)local_18 * 4);
          iVar20 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4);
          while (((*(byte *)(iVar20 + 4) & 2) != 0 && (*(int *)(iVar7 + 8) == -1))) {
            uVar6 = *(uint *)((int)local_20 + 0xc);
            if (uVar6 < *(uint *)((int)local_20 + 4)) {
              piVar8 = (int *)(*(uint *)(local_20 + 1) + uVar6 * 4);
              do {
                if (local_18 == (double *)*piVar8) break;
                uVar6 = uVar6 + 1;
                piVar8 = piVar8 + 1;
                local_48 = piVar8;
              } while (uVar6 < *(uint *)((int)local_20 + 4));
              if (uVar6 < *(uint *)((int)local_20 + 4)) break;
            }
            puVar19 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar7 + 0x48) * 4);
            uVar6 = puVar19[3];
            uVar9 = 0;
            if (uVar6 != 0) {
              puVar13 = (undefined4 *)puVar19[4];
              do {
                if ((double *)*puVar13 == local_18) break;
                uVar9 = uVar9 + 1;
                puVar13 = puVar13 + 1;
              } while (uVar9 < uVar6);
            }
            if ((*puVar19 & 0xfff00000) == 0x20400000) {
              pdVar16 = *(double **)(puVar19[2] + uVar9 * 4);
              if (pdVar16 != *(double **)(puVar19[2] + (uVar6 + uVar9) * 4)) break;
              local_18 = pdVar16;
            }
            else {
              if ((*puVar19 & 0xfff00000) != 0x20500000) break;
              pdVar16 = *(double **)(puVar19[2] + uVar9 * 4);
              local_38 = *(double **)(puVar19[2] + (uVar6 + uVar9) * 4);
              iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + (int)pdVar16 * 4);
              if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4) + 5) & 1)
                   == 0) || (*(double *)(iVar7 + 0x20) <= _DAT_0099d098)) {
                iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + (int)local_38 * 4);
                if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4) + 5) & 1
                     ) == 0) || (*(double *)(iVar7 + 0x20) <= _DAT_0099d098)) break;
                local_18 = pdVar16;
              }
              else {
                local_18 = local_38;
              }
            }
            iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + (int)local_18 * 4);
            iVar20 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4);
          }
          if (*(double **)local_44 != local_18) {
            *(double **)local_44 = local_18;
            local_8 = 1;
          }
          local_2c = (uint *)((int)local_2c + 1);
        } while (local_2c < *(uint **)((int)local_20 + 0xc));
      }
      local_28 = (double *)((int)local_28 + 1);
    } while (local_28 < *(double **)(in_ECX + 0xc));
  }
  if (local_8 != 0) {
    local_8 = 0;
    local_24 = (double *)0x1;
    FUN_009198e4();
  }
  local_2c = (uint *)0x0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      puVar19 = *(uint **)(*(int *)(in_ECX + 0x18) + (int)local_2c * 4);
      if ((((*puVar19 & 0xfff00000) != 0) &&
          (((puVar19[3] == 0 ||
            ((**(byte **)(*(int *)(in_ECX + 0x14) + *(int *)puVar19[4] * 4) & 0x40) == 0)) &&
           ((*puVar19 & 0xfff00000) == 0x30000000)))) && (local_40 = (uint *)0x0, puVar19[3] != 0))
      {
        do {
          local_48 = *(int **)(puVar19[2] + (int)local_40 * 4);
          iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + (int)local_48 * 4);
          if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4) + 4) & 2) != 0
              ) && (*(int *)(iVar7 + 8) == -1)) {
            puVar14 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar7 + 0x48) * 4);
            pdVar16 = (double *)puVar14[3];
            local_20 = (double *)0x0;
            if (pdVar16 != (double *)0x0) {
              local_38 = (double *)puVar14[4];
              do {
                if (*(int **)local_38 == local_48) break;
                local_20 = (double *)((int)local_20 + 1);
                local_38 = (double *)((int)local_38 + 4);
              } while (local_20 < pdVar16);
            }
            local_48 = (int *)(*puVar14 & 0xfff00000);
            if (local_48 == (int *)0x10100000) {
              local_28 = (double *)0x1;
            }
            else {
              if (local_48 != (int *)0x20500000) goto LAB_009249ed;
              local_28 = (double *)0x2;
            }
            local_30 = (double *)0x0;
            if (local_28 != (double *)0x0) {
              local_4c = (int)pdVar16 * 4;
              local_50 = (uint *)((int)pdVar16 * -4);
              local_38 = (double *)(puVar14[2] + (int)local_20 * 4);
              local_34 = (double *)(puVar14[2] + ((int)pdVar16 + (int)local_20) * 4);
              do {
                local_c = *(double **)local_38;
                local_20 = *(double **)(*(int *)(in_ECX + 0x14) + (int)local_c * 4);
                if ((local_48 != (int *)0x20500000) ||
                   (((local_44 = *(double **)(*(int *)(in_ECX + 0x14) + *(uint *)local_34 * 4),
                     (*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(uint *)((int)local_44 + 4) * 4)
                               + 5) & 1) != 0 && (*(uint *)(local_44 + 1) == 0xffffffff)) &&
                    (local_44[4] < _DAT_0099d098)))) {
                  if (local_c ==
                      (double *)*(byte **)(puVar19[2] + ((int)local_40 + puVar19[3] * 2) * 4)) {
                    local_18 = *(double **)(puVar19[2] + (puVar19[3] + (int)local_40) * 4);
                    local_44 = *(double **)(*(int *)(in_ECX + 0x14) + (int)local_18 * 4);
                    if ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                             *(uint *)((int)local_44 + 4) * 4) + 5) & 1) == 0) ||
                        (*(uint *)(local_44 + 1) != 0xffffffff)) || (local_44[4] != _DAT_0099d098))
                    goto LAB_0092483e;
                    *(double **)(puVar19[2] + (int)local_40 * 4) = local_c;
                    *(double **)(puVar19[2] + (puVar19[3] + (int)local_40) * 4) = local_c;
                    *(double **)(puVar19[2] + ((int)local_40 + puVar19[3] * 2) * 4) = local_18;
                  }
                  else {
LAB_0092483e:
                    if ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                             *(uint *)((int)local_20 + 4) * 4) + 4) & 2) == 0) ||
                        (*(uint *)(local_20 + 1) != 0xffffffff)) ||
                       (puVar14 = *(uint **)(*(int *)(in_ECX + 0x18) + *(uint *)(local_20 + 9) * 4),
                       (*puVar14 & 0xfff00000) != 0x30000000)) goto LAB_00924942;
                    local_18 = (double *)0x0;
                    if (puVar14[3] != 0) {
                      pdVar17 = (double *)puVar14[4];
                      do {
                        if ((double *)*(byte **)pdVar17 == local_c) break;
                        local_18 = (double *)((int)local_18 + 1);
                        pdVar17 = (double *)((int)pdVar17 + 4);
                        local_44 = pdVar17;
                      } while (local_18 < (double *)puVar14[3]);
                    }
                    local_20 = *(double **)
                                (*(int *)(in_ECX + 0x14) +
                                *(int *)(puVar14[2] + ((int)local_18 + puVar14[3]) * 4) * 4);
                    local_c = *(double **)
                               (*(int *)(in_ECX + 0x14) +
                               *(int *)(puVar14[2] + ((int)local_18 + puVar14[3] * 2) * 4) * 4);
                    if (((ulonglong)*local_20 & 8) == 0) {
                      if ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                               *(uint *)((int)local_20 + 4) * 4) + 5) & 1) == 0) ||
                          (*(uint *)(local_20 + 1) != 0xffffffff)) || (local_20[4] <= _DAT_0099d098)
                         ) goto LAB_00924942;
                      local_20 = (double *)0x1;
                    }
                    else {
                      local_20 = (double *)0x0;
                    }
                    if ((*(byte *)local_c & 8) == 0) {
                      if ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                               *(int *)((int)local_c + 4) * 4) + 5) & 1) == 0) ||
                          (*(int *)((int)local_c + 8) != -1)) ||
                         (*(double *)((int)local_c + 0x20) <= _DAT_0099d098)) goto LAB_00924942;
                      local_38 = (double *)0x1;
                    }
                    else {
                      local_38 = (double *)0x0;
                    }
                    uVar6 = puVar19[2];
                    local_30 = *(double **)(uVar6 + ((int)local_40 + puVar19[3]) * 4);
                    local_34 = *(double **)(uVar6 + ((int)local_40 + puVar19[3] * 2) * 4);
                    *(undefined4 *)(uVar6 + (int)local_40 * 4) =
                         *(undefined4 *)(puVar14[2] + (int)local_18 * 4);
                    pdVar16 = local_34;
                    if (local_20 == (double *)0x0) {
                      pdVar16 = local_30;
                    }
                    *(double **)(puVar19[2] + (puVar19[3] + (int)local_40) * 4) = pdVar16;
                    pdVar16 = local_34;
                    if (local_38 == (double *)0x0) {
                      pdVar16 = local_30;
                    }
                    *(double **)(puVar19[2] + ((int)local_40 + puVar19[3] * 2) * 4) = pdVar16;
                  }
                  local_8 = 1;
                  break;
                }
LAB_00924942:
                local_38 = (double *)((int)local_38 + local_4c);
                local_30 = (double *)((int)local_30 + 1);
                local_34 = (double *)((int)local_34 + (int)pdVar16 * -4);
              } while (local_30 < local_28);
            }
          }
LAB_009249ed:
          local_40 = (uint *)((int)local_40 + 1);
        } while (local_40 < (uint *)puVar19[3]);
      }
      local_2c = (uint *)((int)local_2c + 1);
    } while (local_2c < *(uint **)(in_ECX + 0xc));
  }
  if (local_8 != 0) {
    local_8 = 0;
    local_24 = (double *)0x1;
    FUN_009198e4();
  }
  local_c = (double *)0x0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      puVar19 = *(uint **)(*(int *)(in_ECX + 0x18) + (int)local_c * 4);
      if ((((*puVar19 & 0xfff00000) != 0) &&
          ((puVar19[3] == 0 ||
           ((**(byte **)(*(int *)(in_ECX + 0x14) + *(int *)puVar19[4] * 4) & 0x40) == 0)))) &&
         ((*puVar19 & 0xfff00000) == 0x10500000)) {
        local_30 = (double *)0xffffffff;
        local_44 = (double *)0xffffffff;
        local_18 = (double *)0x0;
        if (puVar19[1] != 0) {
          do {
            uVar6 = *(uint *)(puVar19[2] + (int)local_18 * 4);
            iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
            if ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4) + 4) & 2)
                  != 0) && (*(int *)(iVar7 + 8) == -1)) &&
               (local_28 = *(double **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar7 + 0x48) * 4),
               ((ulonglong)*local_28 & 0xfff00000) == 0x20500000)) {
              local_20 = (double *)0x0;
              if (*(double **)((int)local_28 + 0xc) != (double *)0x0) {
                local_38 = *(double **)(local_28 + 2);
                do {
                  if (*(uint *)local_38 == uVar6) break;
                  local_20 = (double *)((int)local_20 + 1);
                  local_38 = (double *)((int)local_38 + 4);
                } while (local_20 < *(double **)((int)local_28 + 0xc));
              }
              local_2c = (uint *)0x0;
              local_34 = (double *)0x1;
              do {
                local_50 = *(uint **)(*(uint *)(local_28 + 1) +
                                     (int)(*(uint *)((int)local_28 + 0xc) * (int)local_2c +
                                          (int)local_20) * 4);
                puVar14 = *(uint **)(*(int *)(in_ECX + 0x14) + (int)local_50 * 4);
                if ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + puVar14[1] * 4) + 4) & 2) != 0)
                    && (puVar14[2] == 0xffffffff)) &&
                   (local_40 = *(uint **)(*(int *)(in_ECX + 0x18) + puVar14[0x12] * 4),
                   (*local_40 & 0xfff00000) == 0x10600000)) {
                  if (puVar14[0x17] == 1) {
                    uVar6 = *puVar14;
                    uVar10 = **(uint **)(*(int *)(in_ECX + 0x14) +
                                        *(int *)(puVar19[4] + (int)local_18 * 4) * 4) | uVar6;
                    uVar11 = uVar10 & 0xe000000;
                    uVar9 = 0x8000000;
                    if ((((uVar10 & 0x8000000) != 0) ||
                        (uVar9 = 0x4000000, (uVar10 & 0x4000000) != 0)) ||
                       (uVar9 = 0x2000000, (uVar10 & 0x2000000) != 0)) {
                      uVar11 = uVar9;
                    }
                    if ((uVar6 & 0xe000000) != uVar11) {
                      *puVar14 = uVar6 & 0xf1ffffff | uVar11;
                      local_8 = 1;
                    }
                  }
                  if ((((*(byte *)(in_ECX + 0x6c) & 0x40) != 0) && (puVar19[3] == 1)) &&
                     ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                         *(int *)(puVar19[4] + (int)local_18 * 4) * 4) + 3) & 2) !=
                      0)) {
                    uVar6 = 0;
                    if (local_40[3] != 0) {
                      local_38 = (double *)local_40[4];
                      do {
                        if (*(uint **)local_38 == local_50) break;
                        local_38 = (double *)((int)local_38 + 4);
                        uVar6 = uVar6 + 1;
                      } while (uVar6 < local_40[3]);
                    }
                    local_30 = *(double **)(local_40[2] + uVar6 * 4);
                    local_44 = *(double **)
                                (*(uint *)(local_28 + 1) +
                                (int)(*(uint *)((int)local_28 + 0xc) * (int)local_34 + (int)local_20
                                     ) * 4);
                  }
                }
                local_2c = (uint *)((int)local_2c + 1);
                local_34 = (double *)((int)local_34 + -1);
              } while (local_2c < (uint *)0x2);
            }
            local_18 = (double *)((int)local_18 + 1);
          } while (local_18 < (double *)puVar19[1]);
          if (local_30 != (double *)0xffffffff) {
            iVar7 = FUN_00915378(0x50100004,0xffffffff,0xffffffff);
            if ((iVar7 == -1) ||
               (iVar20 = FUN_00915378(0x10000001,0xffffffff,0xffffffff), iVar20 == -1)) {
              return 0x8007000e;
            }
            iVar7 = *(int *)(*(int *)(in_ECX + 0x18) + iVar7 * 4);
            local_38 = *(double **)(*(int *)(in_ECX + 0x18) + iVar20 * 4);
            FUN_00914593();
            FUN_00914593();
            local_18 = (double *)0x0;
            piVar8 = (int *)(iVar7 + 8);
            *(double **)(*piVar8 + 4) = local_30;
            *(double **)*piVar8 = local_30;
            *(double **)(*piVar8 + 0xc) = local_44;
            *(double **)(*piVar8 + 8) = local_44;
            do {
              uVar12 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0,0,0);
              *(undefined4 *)((int)local_18 + *(int *)(iVar7 + 0x10)) = uVar12;
              if (*(int *)((int)local_18 + *(int *)(iVar7 + 0x10)) == -1) {
                return 0x8007000e;
              }
              *(undefined4 *)
               (*(int *)(*(int *)(in_ECX + 0x14) +
                        *(int *)((int)local_18 + *(int *)(iVar7 + 0x10)) * 4) + 0x14) =
                   *(undefined4 *)
                    (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar19[4] * 4) + 0x14);
              pdVar16 = (double *)((int)local_18 + 4);
              *(undefined4 *)
               (*(int *)(*(int *)(in_ECX + 0x14) +
                        *(int *)((int)local_18 + *(int *)(iVar7 + 0x10)) * 4) + 0x18) =
                   *(undefined4 *)
                    (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar19[4] * 4) + 0x18);
              puVar14 = *(uint **)(*(int *)(in_ECX + 0x14) +
                                  *(int *)((int)local_18 + *(int *)(iVar7 + 0x10)) * 4);
              *puVar14 = *puVar14 |
                         **(uint **)(*(int *)(in_ECX + 0x14) + *(int *)puVar19[4] * 4) & 0xe000000;
              local_18 = pdVar16;
            } while (pdVar16 < (double *)0x10);
            **(undefined4 **)(local_38 + 1) = *(undefined4 *)(*(int *)(iVar7 + 0x10) + 8);
            **(undefined4 **)(local_38 + 2) = *(undefined4 *)puVar19[4];
            FUN_008f4adb();
            *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + -1;
            pdVar16 = *(double **)(in_ECX + 0xc);
            while (pdVar16 = (double *)((int)pdVar16 + -1), local_c < pdVar16) {
              puVar13 = (undefined4 *)(*(int *)(in_ECX + 0x18) + (int)pdVar16 * 4);
              *puVar13 = puVar13[-1];
            }
            *(int *)(*(int *)(in_ECX + 0x18) + (int)local_c * 4) = iVar7;
            *(double **)(*(int *)(in_ECX + 0x18) + 4 + (int)local_c * 4) = local_38;
            FUN_009198e4();
            local_8 = 1;
          }
        }
      }
      local_c = (double *)((int)local_c + 1);
    } while (local_c < *(double **)(in_ECX + 0xc));
  }
  if (local_8 != 0) {
    local_8 = 0;
    local_24 = (double *)0x1;
    FUN_009198e4();
  }
  local_18 = (double *)0x0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      local_40 = *(uint **)(*(int *)(in_ECX + 0x18) + (int)local_18 * 4);
      if (((*local_40 & 0xfff00000) != 0) &&
         ((((local_40[3] == 0 ||
            ((**(byte **)(*(int *)(in_ECX + 0x14) + *(int *)local_40[4] * 4) & 0x40) == 0)) &&
           ((*local_40 & 0xfff00000) == 0x10400000)) && (local_28 = (double *)0x0, local_40[1] != 0)
          ))) {
        do {
          local_50 = (uint *)(local_40[2] + (int)local_28 * 4);
          iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + *local_50 * 4);
          if ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4) + 4) & 2) !=
                0) && (*(int *)(iVar7 + 8) == -1)) &&
             (puVar19 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar7 + 0x48) * 4),
             (*puVar19 & 0xfff00000) == 0x20400000)) {
            local_44 = (double *)puVar19[3];
            local_20 = (double *)0x0;
            if (local_44 != (double *)0x0) {
              local_38 = (double *)puVar19[4];
              do {
                if (*(uint *)local_38 == *local_50) break;
                local_20 = (double *)((int)local_20 + 1);
                local_38 = (double *)((int)local_38 + 4);
              } while (local_20 < local_44);
            }
            local_2c = (uint *)0x0;
            piVar8 = (int *)(puVar19[2] + (int)local_20 * 4);
            do {
              pbVar5 = *(byte **)(*(int *)(in_ECX + 0x14) + *piVar8 * 4);
              if ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(pbVar5 + 4) * 4) + 5) & 1
                    ) != 0) && ((*pbVar5 & 2) != 0)) && (*(int *)(pbVar5 + 8) == -1)) {
                local_8 = 1;
                *local_50 = *(uint *)(puVar19[2] +
                                     (int)((1 - (int)local_2c) * (int)local_44 + (int)local_20) * 4)
                ;
                break;
              }
              local_2c = (uint *)((int)local_2c + 1);
              piVar8 = piVar8 + (int)local_44;
            } while (local_2c < (uint *)0x2);
          }
          local_28 = (double *)((int)local_28 + 1);
        } while (local_28 < (double *)local_40[1]);
      }
      local_18 = (double *)((int)local_18 + 1);
    } while (local_18 < *(double **)(in_ECX + 0xc));
  }
  if ((local_8 == 0) && (local_24 == (double *)0x0)) {
    local_2c = *(uint **)(in_ECX + 0xc);
    local_24 = (double *)0x0;
    if (local_2c != (uint *)0x0) {
      do {
        local_2c = (uint *)((int)local_2c + -1);
        puVar19 = *(uint **)(*(int *)(in_ECX + 0x18) + (int)local_2c * 4);
        pdVar16 = (double *)puVar19[3];
        local_34 = pdVar16;
        if ((pdVar16 == (double *)0x0) ||
           ((**(byte **)(*(int *)(in_ECX + 0x14) + *(int *)puVar19[4] * 4) & 0x40) == 0)) {
          if (((*puVar19 & 0xfff00000) == 0x20400000) || ((*puVar19 & 0xfff00000) == 0x20500000)) {
            if (local_24 < pdVar16) {
              local_24 = pdVar16;
              if (pdVar16 < (double *)0x11) {
                local_24 = (double *)0x10;
              }
              _free(local_14);
              return extraout_EAX;
            }
            local_18 = (double *)0x0;
            if (pdVar16 != (double *)0x0) {
              local_28 = local_14;
              local_38 = local_10;
              do {
                *(uint *)local_28 = 0xffffffff;
                *local_38 = 1.0;
                iVar7 = FUN_00916aa5(*(undefined4 *)(puVar19[4] + (int)local_18 * 4),local_28,
                                     local_38);
                if ((iVar7 < 0) || (*(uint *)local_28 == *(uint *)(puVar19[4] + (int)local_18 * 4)))
                break;
                local_18 = (double *)((int)local_18 + 1);
                local_38 = local_38 + 1;
                local_28 = (double *)((int)local_28 + 4);
              } while (local_18 < pdVar16);
            }
            if (local_18 == pdVar16) {
              pdVar17 = (double *)0x0;
              local_40 = (uint *)0x1;
              local_44 = (double *)0x1;
              if (pdVar16 == (double *)0x0) {
LAB_00925093:
                if (_DAT_00a0b350 == *local_10) {
                  uVar6 = (uint)pdVar16 & 0xfffff | 0x20400000;
                  if (*puVar19 != uVar6) {
                    *puVar19 = uVar6;
                    local_20 = (double *)((int)pdVar16 * 2);
                    local_8 = 1;
                    if ((double *)puVar19[1] < local_20) {
                      puVar13 = (undefined4 *)FUN_009149da();
                      puVar19[2] = (uint)puVar13;
                      if (puVar13 == (undefined4 *)0x0) goto LAB_00925915;
                      puVar19[1] = (uint)local_20;
                      for (pdVar16 = local_20; pdVar16 != (double *)0x0;
                          pdVar16 = (double *)((int)pdVar16 + -1)) {
                        *puVar13 = 0xffffffff;
                        puVar13 = puVar13 + 1;
                      }
                      pdVar16 = local_34;
                    }
                  }
                  local_28 = (double *)0x0;
                  if (pdVar16 != (double *)0x0) {
                    local_38 = (double *)((int)pdVar16 << 2);
                    do {
                      puVar18 = (uint *)((int)local_14 + (int)local_28 * 4);
                      puVar14 = (uint *)(puVar19[2] + (int)local_28 * 4);
                      uVar6 = *puVar18;
                      if (*puVar14 != uVar6) {
                        *puVar14 = uVar6;
                        local_8 = 1;
                      }
                      uVar6 = *puVar18;
                      if (*(uint *)(puVar19[2] + (int)local_38) != uVar6) {
                        *(uint *)(puVar19[2] + (int)local_38) = uVar6;
                        local_8 = 1;
                      }
                      local_28 = (double *)((int)local_28 + 1);
                      local_38 = (double *)((int)local_38 + 4);
                    } while (local_28 < pdVar16);
                  }
                }
                else {
                  if (_DAT_0099d0a0 == *local_10) {
                    local_28 = (double *)0x0;
                    *puVar19 = (uint)pdVar16 & 0xfffff | 0x10000000;
                    puVar19[1] = (uint)pdVar16;
                    if (pdVar16 != (double *)0x0) {
                      do {
                        pdVar17 = (double *)((int)local_28 + 1);
                        *(uint *)((int)local_28 * 4 + puVar19[2]) =
                             *(uint *)((int)local_14 + (int)local_28 * 4);
                        local_28 = pdVar17;
                      } while (pdVar17 < pdVar16);
                    }
                  }
                  else {
                    if (_DAT_0099d098 != *local_10) {
                      if (_DAT_009fd350 != *local_10) goto LAB_0092525b;
                      uVar6 = (uint)pdVar16 & 0xfffff | 0x10100000;
                      if (*puVar19 != uVar6) {
                        *puVar19 = uVar6;
                        puVar19[1] = (uint)pdVar16;
                        local_8 = 1;
                      }
                      local_28 = (double *)0x0;
                      if (pdVar16 != (double *)0x0) {
                        do {
                          puVar14 = (uint *)(puVar19[2] + (int)local_28 * 4);
                          uVar6 = *(uint *)((int)local_14 + (int)local_28 * 4);
                          if (*puVar14 != uVar6) {
                            *puVar14 = uVar6;
                            local_8 = 1;
                          }
                          local_28 = (double *)((int)local_28 + 1);
                        } while (local_28 < pdVar16);
                      }
                      goto LAB_00925371;
                    }
                    *puVar19 = (uint)pdVar16 & 0xfffff | 0x10000000;
                    puVar19[1] = (uint)pdVar16;
                    if ((local_1c == -1) &&
                       (local_1c = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,0),
                       local_1c == -1)) goto LAB_00925915;
                    pdVar17 = (double *)0x0;
                    if (pdVar16 != (double *)0x0) {
                      do {
                        *(int *)(puVar19[2] + (int)pdVar17 * 4) = local_1c;
                        pdVar17 = (double *)((int)pdVar17 + 1);
                      } while (pdVar17 < pdVar16);
                    }
                  }
                  local_8 = 1;
                }
              }
              else {
                do {
                  if ((pdVar17 != (double *)0x0) &&
                     (local_10[(int)pdVar17] != local_10[(int)pdVar17 + -1])) {
                    local_44 = (double *)0x0;
                  }
                  if ((local_10[(int)pdVar17] < _DAT_009fd350) ||
                     (_DAT_0099d0a0 < local_10[(int)pdVar17])) {
                    local_40 = (uint *)0x0;
                  }
                  pdVar17 = (double *)((int)pdVar17 + 1);
                } while (pdVar17 < pdVar16);
                if (local_44 != (double *)0x0) goto LAB_00925093;
LAB_0092525b:
                if (((*(byte *)(in_ECX + 0x6e) & 0x10) == 0) || (local_40 != (uint *)0x0)) {
                  uVar6 = (uint)pdVar16 & 0xfffff | 0x20500000;
                  if (*puVar19 != uVar6) {
                    *puVar19 = uVar6;
                    local_20 = (double *)((int)pdVar16 * 2);
                    local_8 = 1;
                    if ((double *)puVar19[1] < local_20) {
                      puVar13 = (undefined4 *)FUN_009149da();
                      puVar19[2] = (uint)puVar13;
                      if (puVar13 == (undefined4 *)0x0) goto LAB_00925915;
                      puVar19[1] = (uint)local_20;
                      for (pdVar16 = local_20; pdVar16 != (double *)0x0;
                          pdVar16 = (double *)((int)pdVar16 + -1)) {
                        *puVar13 = 0xffffffff;
                        puVar13 = puVar13 + 1;
                      }
                      pdVar16 = local_34;
                    }
                  }
                  local_18 = (double *)0x0;
                  if (pdVar16 != (double *)0x0) {
                    local_28 = (double *)((int)pdVar16 << 2);
                    do {
                      puVar14 = (uint *)(puVar19[2] + (int)local_18 * 4);
                      uVar6 = *(uint *)((int)local_14 + (int)local_18 * 4);
                      if (*puVar14 != uVar6) {
                        *puVar14 = uVar6;
                        local_8 = 1;
                      }
                      if (*(int *)((int)local_28 + puVar19[2]) == -1) {
                        iVar7 = 0;
                      }
                      else {
                        iVar7 = *(int *)(*(int *)(in_ECX + 0x14) +
                                        *(int *)((int)local_28 + puVar19[2]) * 4);
                      }
                      if ((((iVar7 == 0) ||
                           ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4) +
                                      5) & 1) == 0)) || (*(int *)(iVar7 + 8) != -1)) ||
                         (*(double *)(iVar7 + 0x20) != local_10[(int)local_18])) {
                        uVar12 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,
                                              local_10[(int)local_18]);
                        *(undefined4 *)((int)local_28 + puVar19[2]) = uVar12;
                        if (*(int *)((int)local_28 + puVar19[2]) == -1) goto LAB_00925915;
                        local_8 = 1;
                      }
                      local_18 = (double *)((int)local_18 + 1);
                      local_28 = (double *)((int)local_28 + 4);
                    } while (local_18 < pdVar16);
                  }
                }
              }
            }
          }
LAB_00925371:
          if ((*puVar19 & 0xfff00000) == 0x20500000) {
            local_c = (double *)puVar19[3];
            pdVar16 = (double *)0x0;
            local_28 = (double *)0x0;
            local_38 = (double *)0x0;
            if (local_c != (double *)0x0) {
              while( true ) {
                local_18 = (double *)0xffffffff;
                local_20 = (double *)0xffffffff;
                local_34 = (double *)0xffffffff;
                local_30 = (double *)0xffffffff;
                puVar14 = (uint *)((int)local_14 + (int)pdVar16 * 4);
                *puVar14 = 0xffffffff;
                iVar7 = FUN_00916d2f(*(undefined4 *)(puVar19[4] + (int)pdVar16 * 4),puVar14,
                                     &local_18,&local_20,&local_34,&local_30);
                if (iVar7 < 0) break;
                if ((local_18 != (double *)0xffffffff) && (local_20 != (double *)0xffffffff)) {
                  if (*(double *)(*(int *)(*(int *)(in_ECX + 0x14) + (int)local_18 * 4) + 0x20) <
                      *(double *)(*(int *)(*(int *)(in_ECX + 0x14) + (int)local_20 * 4) + 0x20)) {
                    local_18 = (double *)0xffffffff;
                  }
                  else {
                    local_20 = (double *)0xffffffff;
                  }
                }
                if (local_30 == (double *)0xffffffff) {
LAB_00925448:
                  if ((local_34 == (double *)0xffffffff) && (local_18 != (double *)0xffffffff)) {
                    iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + (int)local_18 * 4);
                    pdVar17 = (double *)0x1;
                    goto LAB_009254ba;
                  }
                  if (((local_30 != (double *)0xffffffff) || (local_34 != (double *)0xffffffff)) ||
                     (local_20 == (double *)0xffffffff)) goto LAB_00925487;
                  local_10[(int)pdVar16] =
                       *(double *)(*(int *)(*(int *)(in_ECX + 0x14) + (int)local_20 * 4) + 0x20);
                  pdVar15 = (double *)0x20300000;
                  pdVar17 = (double *)0x0;
                }
                else {
                  if (local_34 != (double *)0xffffffff) {
                    dVar1 = *(double *)
                             (*(int *)(*(int *)(in_ECX + 0x14) + (int)local_30 * 4) + 0x20);
                    dVar2 = *(double *)
                             (*(int *)(*(int *)(in_ECX + 0x14) + (int)local_34 * 4) + 0x20);
                    if ((NAN(dVar1) || NAN(dVar2)) || dVar1 < dVar2 == (dVar1 == dVar2)) {
                      local_30 = (double *)0xffffffff;
                    }
                    else {
                      local_34 = (double *)0xffffffff;
                    }
                  }
                  if (local_30 == (double *)0xffffffff) goto LAB_00925448;
LAB_00925487:
                  if ((local_18 != (double *)0xffffffff) || (local_20 != (double *)0xffffffff))
                  break;
                  if (local_34 == (double *)0xffffffff) {
                    if (local_30 == (double *)0xffffffff) break;
                    iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + (int)local_30 * 4);
                    pdVar17 = (double *)0x0;
LAB_009254ba:
                    local_10[(int)pdVar16] = *(double *)(iVar7 + 0x20);
                    pdVar15 = (double *)0x20200000;
                  }
                  else {
                    local_10[(int)pdVar16] =
                         *(double *)(*(int *)(*(int *)(in_ECX + 0x14) + (int)local_34 * 4) + 0x20);
                    pdVar15 = (double *)0x20300000;
                    pdVar17 = (double *)0x1;
                  }
                }
                if (pdVar16 == (double *)0x0) {
                  local_38 = pdVar17;
                  local_28 = pdVar15;
                }
                else if ((pdVar15 != local_28) || (pdVar17 != local_38)) break;
                pdVar16 = (double *)((int)pdVar16 + 1);
                if (local_c <= pdVar16) break;
              }
            }
            if (pdVar16 == local_c) {
              if ((*(byte *)(in_ECX + 0x6c) & 0x80) == 0) {
                *puVar19 = ((uint)local_28 ^ (uint)local_c) & 0xfffff ^ (uint)local_28;
                local_20 = (double *)0x0;
                if (local_c != (double *)0x0) {
                  uVar6 = puVar19[2];
                  iVar7 = (~-(uint)(local_38 != (double *)0x0) & (uint)local_c) << 2;
                  local_38 = (double *)((-(uint)(local_38 != (double *)0x0) & (uint)local_c) << 2);
                  do {
                    *(uint *)((int)local_38 + uVar6) = *(uint *)((int)local_14 + (int)local_20 * 4);
                    uVar12 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,local_10[(int)local_20]
                                         );
                    *(undefined4 *)(iVar7 + puVar19[2]) = uVar12;
                    uVar6 = puVar19[2];
                    if (*(int *)(iVar7 + uVar6) == -1) goto LAB_00925915;
                    local_20 = (double *)((int)local_20 + 1);
                    local_38 = (double *)((int)local_38 + 4);
                    iVar7 = iVar7 + 4;
                  } while (local_20 < local_c);
                }
              }
              else {
                uVar6 = (uint)local_c & 0xfffff;
                local_44 = (double *)FUN_00915378(uVar6 | 0x10100000,local_c,local_c);
                local_50 = (uint *)FUN_00915378(uVar6 | 0x20400000,(int)local_c * 2,local_c);
                iVar7 = FUN_00915378(uVar6 | 0x30000000,(int)local_c * 3,local_c);
                if (((local_44 == (double *)0xffffffff) || (local_50 == (uint *)0xffffffff)) ||
                   (iVar7 == -1)) goto LAB_00925915;
                iVar20 = *(int *)(in_ECX + 0x18);
                local_20 = *(double **)(iVar20 + (int)local_44 * 4);
                local_18 = *(double **)(iVar20 + (int)local_50 * 4);
                local_8 = *(int *)(iVar20 + iVar7 * 4);
                FUN_00914593();
                FUN_00914593();
                FUN_00914593();
                bVar21 = local_38 == (double *)0x0;
                local_38 = (double *)0x0;
                if (bVar21) {
                  if (local_c != (double *)0x0) {
                    do {
                      pdVar16 = local_38;
                      iVar7 = (int)local_38 * 4;
                      uVar12 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,
                                            local_10[(int)local_38]);
                      *(undefined4 *)(iVar7 + *(uint *)(local_20 + 1)) = uVar12;
                      *(uint *)(iVar7 + *(uint *)(local_18 + 1)) =
                           *(uint *)((int)local_14 + (int)pdVar16 * 4);
                      if (*(int *)(iVar7 + *(uint *)(local_20 + 1)) == -1) goto LAB_00925915;
                      local_38 = (double *)((int)local_38 + 1);
                    } while (local_38 < local_c);
                  }
                }
                else if (local_c != (double *)0x0) {
                  do {
                    iVar7 = (int)local_38 * 4;
                    *(uint *)(iVar7 + *(uint *)(local_20 + 1)) =
                         *(uint *)((int)local_14 + (int)local_38 * 4);
                    uVar12 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,local_10[(int)local_38]
                                         );
                    *(undefined4 *)(iVar7 + *(uint *)(local_18 + 1)) = uVar12;
                    if (*(int *)(iVar7 + *(uint *)(local_18 + 1)) == -1) goto LAB_00925915;
                    local_38 = (double *)((int)local_38 + 1);
                  } while (local_38 < local_c);
                }
                if (((local_3c == -1) &&
                    (local_3c = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,0x3ff0000000000000),
                    local_3c == -1)) ||
                   ((local_1c == -1 &&
                    (local_1c = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,0), local_1c == -1))
                   )) goto LAB_00925915;
                if (local_28 == (double *)0x20300000) {
                  if (local_c != (double *)0x0) {
                    local_44 = local_c;
                    local_38 = (double *)((int)local_c << 2);
                    local_34 = (double *)((int)local_c << 3);
                    do {
                      *(int *)((int)local_38 + *(int *)(local_8 + 8)) = local_3c;
                      pdVar16 = (double *)((int)local_34 + 4);
                      local_44 = (double *)((int)local_44 + -1);
                      *(int *)((int)local_34 + *(int *)(local_8 + 8)) = local_1c;
                      local_38 = (double *)((int)local_38 + 4);
                      local_34 = pdVar16;
                    } while (local_44 != (double *)0x0);
                    local_44 = (double *)0x0;
                  }
                }
                else if (local_c != (double *)0x0) {
                  local_44 = local_c;
                  local_38 = (double *)((int)local_c << 2);
                  local_34 = (double *)((int)local_c << 3);
                  do {
                    *(int *)((int)local_38 + *(int *)(local_8 + 8)) = local_1c;
                    pdVar16 = (double *)((int)local_34 + 4);
                    local_44 = (double *)((int)local_44 + -1);
                    *(int *)((int)local_34 + *(int *)(local_8 + 8)) = local_3c;
                    local_38 = (double *)((int)local_38 + 4);
                    local_34 = pdVar16;
                  } while (local_44 != (double *)0x0);
                }
                local_38 = (double *)0x0;
                if (local_c != (double *)0x0) {
                  local_34 = (double *)((int)local_c << 2);
                  do {
                    iVar7 = (int)local_38 * 4;
                    uVar12 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0,0,0);
                    *(undefined4 *)(iVar7 + *(uint *)(local_20 + 2)) = uVar12;
                    uVar12 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0,0,0);
                    *(undefined4 *)(iVar7 + *(uint *)(local_18 + 2)) = uVar12;
                    *(undefined4 *)(iVar7 + *(int *)(local_8 + 0x10)) =
                         *(undefined4 *)(iVar7 + puVar19[4]);
                    if ((*(int *)(iVar7 + *(uint *)(local_20 + 2)) == -1) ||
                       (*(int *)(iVar7 + *(uint *)(local_18 + 2)) == -1)) goto LAB_00925915;
                    local_38 = (double *)((int)local_38 + 1);
                    pdVar16 = (double *)((int)local_34 + 4);
                    *(int *)((int)local_34 + *(uint *)(local_18 + 1)) =
                         *(int *)(iVar7 + *(uint *)(local_20 + 2));
                    *(undefined4 *)(iVar7 + *(int *)(local_8 + 8)) =
                         *(undefined4 *)(iVar7 + *(uint *)(local_18 + 2));
                    local_34 = pdVar16;
                  } while (local_38 < local_c);
                }
                puVar14 = (uint *)(*(int *)(in_ECX + 0xc) + -3);
                while (local_2c < puVar14) {
                  puVar14 = (uint *)((int)puVar14 + -1);
                  *(undefined4 *)(*(int *)(in_ECX + 0x18) + 0xc + (int)puVar14 * 4) =
                       *(undefined4 *)(*(int *)(in_ECX + 0x18) + (int)puVar14 * 4);
                  local_50 = puVar14;
                }
                *(double **)(*(int *)(in_ECX + 0x18) + 4 + (int)local_2c * 4) = local_20;
                *(double **)(*(int *)(in_ECX + 0x18) + 8 + (int)local_2c * 4) = local_18;
                *(int *)(*(int *)(in_ECX + 0x18) + 0xc + (int)local_2c * 4) = local_8;
                *puVar19 = 0;
              }
              local_8 = 1;
            }
          }
        }
      } while (local_2c != (uint *)0x0);
      if (local_8 != 0) goto LAB_00925915;
    }
    iVar7 = FUN_0091ae30();
    if ((-1 < iVar7) && (iVar7 = FUN_00915e19(), -1 < iVar7)) {
      FUN_0091c491();
    }
  }
LAB_00925915:
  _free(local_14);
  return extraout_EAX_00;
}


// ==== FUN_00925935 @ 0x00925935 ====

undefined4 FUN_00925935(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  int *piVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int in_ECX;
  uint uVar8;
  int *piVar9;
  undefined4 uVar10;
  int *piVar11;
  int local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  int *local_8;
  
  uVar8 = 0;
  bVar4 = false;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + uVar8 * 4);
      iVar6 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4);
      *(undefined4 *)(iVar7 + 0x30) = *(undefined4 *)(iVar7 + 0x14);
      *(undefined4 *)(iVar7 + 0x40) = *(undefined4 *)(iVar7 + 0x18);
      uVar5 = *(uint *)(iVar6 + 4);
      if ((uVar5 & 0x10) == 0) {
        if ((uVar5 & 0x11028) == 0) {
          *(undefined4 *)(iVar7 + 0x18) = 0;
          goto LAB_00925988;
        }
      }
      else {
        *(undefined4 *)(iVar7 + 0x18) = 1;
LAB_00925988:
        *(undefined4 *)(iVar7 + 0x14) = 0xffffffff;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(in_ECX + 8));
  }
  local_10 = *(uint *)(in_ECX + 0xc);
  while (local_10 != 0) {
    local_10 = local_10 - 1;
    puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + local_10 * 4);
    if ((*puVar2 & 0xfff00000) != 0) {
      uVar8 = 1;
      if (1 < puVar2[3]) {
        do {
          FUN_0091c7f0(*(undefined4 *)(*(int *)(in_ECX + 0x14) + *(int *)puVar2[4] * 4),
                       *(undefined4 *)(*(int *)(in_ECX + 0x14) + ((int *)puVar2[4])[uVar8] * 4));
          uVar8 = uVar8 + 1;
        } while (uVar8 < puVar2[3]);
      }
      local_8 = (int *)0x1;
      if (1 < puVar2[3]) {
        do {
          piVar9 = (int *)((int)local_8 + 1);
          *(undefined4 *)
           (*(int *)(*(int *)(in_ECX + 0x14) + ((int *)puVar2[4])[(int)local_8] * 4) + 0x14) =
               *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar2[4] * 4) + 0x14);
          *(undefined4 *)
           (*(int *)(*(int *)(in_ECX + 0x14) + ((int *)puVar2[4])[(int)local_8] * 4) + 0x18) =
               *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar2[4] * 4) + 0x18);
          local_8 = piVar9;
        } while (piVar9 < (int *)puVar2[3]);
      }
      uVar8 = *puVar2;
      uVar5 = uVar8 & 0xfff00000;
      if (((uVar5 == 0x20700000) || (uVar5 == 0x20800000)) || (uVar5 == 0x11500000)) {
        local_c = 0;
        if (puVar2[3] != 0) {
          do {
            iVar7 = *(int *)(in_ECX + 0x14);
            iVar6 = local_c * 4;
            local_c = local_c + 1;
            *(undefined4 *)(*(int *)(iVar7 + *(int *)(iVar6 + puVar2[4]) * 4) + 0x14) =
                 *(undefined4 *)
                  (*(int *)(iVar7 + *(int *)(*(int *)(iVar7 + *(int *)(iVar6 + puVar2[2]) * 4) +
                                            0x14) * 4) + 0x14);
            iVar7 = *(int *)(in_ECX + 0x14);
            *(undefined4 *)(*(int *)(iVar7 + *(int *)(iVar6 + puVar2[4]) * 4) + 0x18) =
                 *(undefined4 *)
                  (*(int *)(iVar7 + *(int *)(*(int *)(iVar7 + *(int *)(iVar6 + puVar2[2]) * 4) +
                                            0x14) * 4) + 0x18);
          } while (local_c < puVar2[3]);
        }
      }
      else if (uVar5 == 0x11200000) {
        local_14 = puVar2[1] / (uVar8 & 0xfffff);
        local_8 = (int *)0x0;
        if (puVar2[3] != 0) {
          do {
            local_c = 0;
            if (local_14 != 0) {
              do {
                for (iVar7 = *(int *)(puVar2[2] + (int)(puVar2[3] * local_c + (int)local_8) * 4);
                    iVar7 != -1; iVar7 = *(int *)(*(int *)(iVar7 * 4 + *(int *)(in_ECX + 0x14)) + 8)
                    ) {
                  iVar6 = *(int *)(in_ECX + 0x14);
                  FUN_0091c7f0(*(undefined4 *)(iVar7 * 4 + iVar6),
                               *(undefined4 *)
                                (iVar6 + *(int *)(*(int *)(iVar6 + *(int *)(puVar2[4] +
                                                                           (int)local_8 * 4) * 4) +
                                                 0x14) * 4));
                }
                local_c = local_c + 1;
              } while (local_c < local_14);
            }
            local_8 = (int *)((int)local_8 + 1);
          } while (local_8 < (int *)puVar2[3]);
        }
      }
      else if (((uVar8 & 0xf0000000) < 0x10000000) || (0x40000000 < (uVar8 & 0xf0000000))) {
        if (puVar2[3] == 0) {
          uVar8 = 0;
          if (puVar2[1] != 0) {
            do {
              *(undefined4 *)
               (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar2[2] + uVar8 * 4) * 4) + 0x14) =
                   0xffffffff;
              iVar7 = uVar8 * 4;
              uVar8 = uVar8 + 1;
              *(undefined4 *)
               (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar2[2] + iVar7) * 4) + 0x18) = 1;
            } while (uVar8 < puVar2[1]);
          }
        }
        else {
          local_c = 0;
          if (puVar2[1] != 0) {
            do {
              for (iVar7 = *(int *)(puVar2[2] + local_c * 4); iVar7 != -1;
                  iVar7 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar7 * 4) + 8)) {
                FUN_0091c7f0(*(undefined4 *)(iVar7 * 4 + *(int *)(in_ECX + 0x14)),
                             *(undefined4 *)(*(int *)(in_ECX + 0x14) + *(int *)puVar2[4] * 4));
              }
              local_c = local_c + 1;
            } while (local_c < puVar2[1]);
          }
        }
      }
      else {
        local_14 = puVar2[1] / (uVar8 & 0xfffff);
        local_8 = (int *)0x0;
        if (puVar2[3] != 0) {
          do {
            local_c = 0;
            if (local_14 != 0) {
              do {
                for (iVar7 = *(int *)(puVar2[2] + (int)(puVar2[3] * local_c + (int)local_8) * 4);
                    iVar7 != -1; iVar7 = *(int *)(*(int *)(iVar7 * 4 + *(int *)(in_ECX + 0x14)) + 8)
                    ) {
                  FUN_0091c7f0(*(undefined4 *)(iVar7 * 4 + *(int *)(in_ECX + 0x14)),
                               *(undefined4 *)
                                (*(int *)(in_ECX + 0x14) +
                                *(int *)(puVar2[4] + (int)local_8 * 4) * 4));
                }
                local_c = local_c + 1;
              } while (local_c < local_14);
            }
            local_8 = (int *)((int)local_8 + 1);
          } while (local_8 < (int *)puVar2[3]);
        }
      }
    }
  }
  FUN_0079e14e();
  local_c = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + local_c * 4);
      uVar8 = *puVar2 & 0xfff00000;
      if (((((uVar8 != 0) && (uVar8 != 0x10f00000)) &&
           ((uVar8 != 0x20700000 &&
            ((((uVar8 != 0x11100000 && (uVar8 != 0x11200000)) && (uVar8 != 0x11300000)) &&
             ((uVar8 != 0x11400000 && (uVar8 != 0x20800000)))))))) && (uVar8 != 0x20900000)) &&
         (uVar8 != 0x11500000)) {
        iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar2[4] * 4);
        if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4) + 5) & 0x10) == 0
           ) {
          local_18 = 0;
          local_10 = 0;
          FUN_00915de8(*(int *)puVar2[4],&local_18);
          for (iVar6 = iVar7; iVar6 = *(int *)(iVar6 + 8), iVar6 != -1;
              iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + iVar6 * 4)) {
            FUN_00915de8(iVar6,&local_10);
          }
          if (puVar2[1] != 0) {
            local_8 = (int *)puVar2[2];
            local_14 = puVar2[1];
            do {
              for (iVar6 = *local_8; iVar6 != -1;
                  iVar6 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar6 * 4) + 8)) {
                FUN_00915de8(iVar6,&local_10);
              }
              local_8 = local_8 + 1;
              local_14 = local_14 - 1;
            } while (local_14 != 0);
          }
          iVar7 = *(int *)(iVar7 + 0x14);
          if (local_10 < local_18) {
            local_18 = local_18 - local_10;
            do {
              iVar7 = iVar7 * 4;
              if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                      *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar7) + 4) * 4) +
                             5) & 0x80) != 0) && (local_8 = (int *)0x0, puVar2[3] != 0)) {
                do {
                  piVar9 = (int *)((int)local_8 + 1);
                  *(undefined4 *)
                   (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar2[4] + (int)local_8 * 4) * 4) +
                   0x18) = *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar7) + 0x18);
                  *(undefined4 *)
                   (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar2[4] + (int)local_8 * 4) * 4) +
                   0x14) = *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar7) + 0x14);
                  local_8 = piVar9;
                } while (piVar9 < (int *)puVar2[3]);
              }
              local_18 = local_18 - 1;
              iVar7 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar7) + 0x14);
            } while (local_18 != 0);
          }
        }
      }
      local_c = local_c + 1;
    } while (local_c < *(uint *)(in_ECX + 0xc));
  }
  iVar7 = *(int *)(in_ECX + 8);
  if (iVar7 != 0) {
    piVar9 = *(int **)(in_ECX + 0x14);
    do {
      iVar6 = *piVar9;
      if ((*(int *)(iVar6 + 0x30) != *(int *)(iVar6 + 0x14)) ||
         (*(int *)(iVar6 + 0x40) != *(int *)(iVar6 + 0x18))) {
        bVar4 = true;
      }
      piVar9 = piVar9 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    if (bVar4) {
      FUN_009198e4();
      piVar9 = *(int **)(in_ECX + 0xc);
      while (piVar9 != (int *)0x0) {
        piVar9 = (int *)((int)piVar9 - 1);
        iVar7 = *(int *)(*(int *)(in_ECX + 0x18) + (int)piVar9 * 4);
        if (((*(ushort *)(iVar7 + 2) & 0xfff0) != 0) &&
           (local_1c = *(int *)(iVar7 + 0xc), local_8 = piVar9, local_1c != 0)) {
          piVar11 = *(int **)(iVar7 + 0x10);
          do {
            iVar6 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar11 * 4) + 0x14);
            if ((iVar6 != -1) &&
               (piVar3 = *(int **)(*(int *)(*(int *)(in_ECX + 0x14) + iVar6 * 4) + 0x48),
               local_8 < piVar3)) {
              local_8 = piVar3;
            }
            piVar11 = piVar11 + 1;
            local_1c = local_1c + -1;
          } while (local_1c != 0);
          piVar11 = piVar9;
          if (piVar9 != local_8) {
            for (; piVar11 < local_8; piVar11 = (int *)((int)piVar11 + 1)) {
              puVar1 = (undefined4 *)(*(int *)(in_ECX + 0x18) + (int)piVar11 * 4);
              *puVar1 = puVar1[1];
            }
            *(int *)(*(int *)(in_ECX + 0x18) + (int)local_8 * 4) = iVar7;
            FUN_009198e4();
          }
        }
      }
      uVar10 = 0;
      goto LAB_00925ed9;
    }
  }
  uVar10 = 1;
LAB_00925ed9:
  FUN_0095cf1d();
  return uVar10;
}


// ==== FUN_00925eeb @ 0x00925eeb ====

int FUN_00925eeb(void)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  int *piVar5;
  int extraout_EAX;
  int in_ECX;
  uint uVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int local_7c [3];
  undefined1 auStack_70 [4];
  int local_6c [4];
  int *local_5c;
  undefined1 *local_58;
  undefined4 *local_54;
  int *local_50;
  int local_4c;
  undefined4 local_48;
  int local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  int *local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  uint *local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  local_44 = -1;
  FUN_009198e4();
  iVar4 = *(int *)(in_ECX + 8);
  uVar6 = 0;
  local_24 = 0;
  if (iVar4 != 0) {
    piVar5 = *(int **)(in_ECX + 0x14);
    do {
      if ((*(int *)(in_ECX + 0x88) == *(int *)(*piVar5 + 4)) &&
         (uVar1 = *(uint *)(*piVar5 + 0xc), uVar6 <= uVar1)) {
        uVar6 = uVar1 + 1;
      }
      piVar5 = piVar5 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    local_24 = uVar6;
  }
  uVar6 = local_24 + *(int *)(in_ECX + 0xc) * 8;
  local_54 = operator_new(uVar6 * 4);
  if (local_54 == (undefined4 *)0x0) {
    return -0x7ff8fff2;
  }
  puVar9 = local_54;
  for (uVar6 = uVar6 & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  uVar6 = 0;
  for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)puVar9 = 0;
    puVar9 = (undefined4 *)((int)puVar9 + 1);
  }
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
      if (*(int *)(in_ECX + 0x88) == *(int *)(iVar4 + 4)) {
        if ((uint)local_54[*(int *)(iVar4 + 0xc)] <= *(uint *)(iVar4 + 0x10)) {
          local_54[*(int *)(iVar4 + 0xc)] = *(uint *)(iVar4 + 0x10) + 1;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(in_ECX + 8));
  }
  local_38 = *(uint *)(in_ECX + 0xc);
  local_34 = 0;
  if (local_38 == 0) {
LAB_0092654f:
    uVar6 = 0;
    if (local_38 != 0) {
      do {
        **(undefined4 **)(*(int *)(in_ECX + 0x18) + uVar6 * 4) = 0;
        uVar6 = uVar6 + 1;
      } while (uVar6 < local_38);
    }
    iVar4 = FUN_0091ae30();
    if ((iVar4 == 0) || (-1 < iVar4)) {
      iVar4 = FUN_00915e19();
      if ((iVar4 == 0) || (-1 < iVar4)) {
        FUN_009237bb();
      }
    }
LAB_00926594:
    _free(local_54);
    return extraout_EAX;
  }
LAB_00925fa1:
  puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + local_34 * 4);
  local_14 = puVar2;
  if ((*puVar2 & 0xfff00000) != 0) {
    iVar7 = 0;
    local_40 = 1;
    iVar4 = FUN_009145b2(0,&local_48);
    if (iVar4 != 0) {
      do {
        iVar4 = FUN_009205c9(local_48,iVar4,local_54,&local_24,puVar2,local_38,0xffffffff);
        if (iVar4 == 0) {
          local_40 = 0;
        }
        iVar7 = iVar7 + 1;
        iVar4 = FUN_009145b2(iVar7,&local_48);
      } while (iVar4 != 0);
      if ((local_40 == 0) && (iVar4 = FUN_009145ef(), iVar4 == 0)) {
        local_8 = 0;
        local_c = FUN_009145b2(0,0);
        puVar3 = local_14;
        if (local_c == 0) {
          local_10 = (int *)0x0;
        }
        else {
          local_10 = (int *)(puVar2[1] / local_c);
        }
        local_6c[0] = 0;
        local_6c[1] = 0;
        local_6c[2] = 0;
        local_6c[3] = 0;
        local_20 = 0;
        if (local_c != 0) {
          local_1c = 0;
          local_58 = auStack_70;
          do {
            if (*(int *)(local_58 + local_1c + 4) == 0) {
              local_3c = local_20 + 1;
              local_18 = 1;
              if (local_3c < local_c) {
                local_30 = (local_1c + 4) - local_1c;
                do {
                  if (local_6c[local_3c] == 0) {
                    local_28 = (int *)0x0;
                    if (local_10 != (int *)0x0) {
                      piVar5 = (int *)(puVar3[2] + local_1c);
                      do {
                        local_40 = *(int *)(local_30 + (int)piVar5) * 4;
                        iVar4 = *piVar5 * 4;
                        if (((*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar4) + 4) !=
                              *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + local_40) + 4)) ||
                            (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar4) + 8) !=
                             *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + local_40) + 8))) ||
                           (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar4) + 0xc) !=
                            *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + local_40) + 0xc))) break;
                        local_28 = (int *)((int)local_28 + 1);
                        piVar5 = piVar5 + local_c;
                      } while (local_28 < local_10);
                    }
                    if (local_28 == local_10) {
                      local_18 = local_18 + 1;
                    }
                  }
                  local_30 = local_30 + 4;
                  local_3c = local_3c + 1;
                } while (local_3c < local_c);
              }
              local_30 = FUN_00915378((*puVar3 ^ local_18) & 0xfffff ^ *puVar3,0xffffffff,0xffffffff
                                     );
              if (local_30 == 0xffffffff) goto LAB_00926594;
              iVar4 = *(int *)(*(int *)(in_ECX + 0x18) + local_30 * 4);
              FUN_00914593();
              if (local_20 < local_c) {
                local_2c = local_18 * 4 - 4;
                local_4c = local_c * 4 - local_1c;
                local_40 = local_c;
                do {
                  local_4c = local_4c + -4;
                  local_40 = local_40 - 1;
                  local_5c = local_6c + local_40;
                  if (*local_5c == 0) {
                    local_28 = (int *)0x0;
                    if (local_10 != (int *)0x0) {
                      local_50 = (int *)(puVar3[2] + local_1c);
                      do {
                        local_3c = *local_50 * 4;
                        iVar7 = *(int *)((int)local_50 + local_4c) * 4;
                        if (((*(int *)(*(int *)(local_3c + *(int *)(in_ECX + 0x14)) + 4) !=
                              *(int *)(*(int *)(iVar7 + *(int *)(in_ECX + 0x14)) + 4)) ||
                            (*(int *)(*(int *)(local_3c + *(int *)(in_ECX + 0x14)) + 8) !=
                             *(int *)(*(int *)(iVar7 + *(int *)(in_ECX + 0x14)) + 8))) ||
                           (*(int *)(*(int *)(local_3c + *(int *)(in_ECX + 0x14)) + 0xc) !=
                            *(int *)(*(int *)(iVar7 + *(int *)(in_ECX + 0x14)) + 0xc))) break;
                        local_28 = (int *)((int)local_28 + 1);
                        local_50 = local_50 + local_c;
                      } while (local_28 < local_10);
                      if (local_28 < local_10) goto LAB_009262a6;
                      local_3c = local_2c;
                      local_28 = (int *)(local_40 * 4);
                      local_50 = local_10;
                      do {
                        *(undefined4 *)(local_3c + *(int *)(iVar4 + 8)) =
                             *(undefined4 *)((int)local_28 + puVar3[2]);
                        local_28 = local_28 + local_c;
                        local_3c = local_3c + local_18 * 4;
                        local_50 = (int *)((int)local_50 + -1);
                      } while (local_50 != (int *)0x0);
                      *local_5c = 1;
                    }
                    if ((*puVar3 & 0xfff00000) != 0x50000000) {
                      *(undefined4 *)(local_2c + *(int *)(iVar4 + 0x10)) =
                           *(undefined4 *)(local_40 * 4 + puVar3[4]);
                      *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                        *(int *)(local_2c + *(int *)(iVar4 + 0x10)) * 4) + 0x48) =
                           local_30;
                    }
                    local_2c = local_2c - 4;
                  }
LAB_009262a6:
                  if (local_40 <= local_20) break;
                } while( true );
              }
              if ((*puVar3 & 0xfff00000) == 0x50000000) {
                if (local_18 == local_c) {
                  **(undefined4 **)(iVar4 + 0x10) = *(undefined4 *)puVar3[4];
                }
                else {
                  iVar7 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),local_24,local_8,0);
                  local_7c[local_8] = iVar7;
                  **(int **)(iVar4 + 0x10) = iVar7;
                  if (**(int **)(iVar4 + 0x10) == -1) goto LAB_00926594;
                  *(undefined4 *)
                   (*(int *)(*(int *)(in_ECX + 0x14) + **(int **)(iVar4 + 0x10) * 4) + 0x14) =
                       *(undefined4 *)
                        (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar3[4] * 4) + 0x14);
                  *(undefined4 *)
                   (*(int *)(*(int *)(in_ECX + 0x14) + **(int **)(iVar4 + 0x10) * 4) + 0x18) =
                       *(undefined4 *)
                        (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar3[4] * 4) + 0x18);
                  iVar7 = FUN_0091635e(iVar4,0);
                  if (iVar7 < 0) {
                    return iVar7;
                  }
                  local_8 = local_8 + 1;
                }
                *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + **(int **)(iVar4 + 0x10) * 4) + 0x48) =
                     local_30;
              }
            }
            local_20 = local_20 + 1;
            local_1c = local_1c + 4;
          } while (local_20 < local_c);
          if (local_8 == 0) goto LAB_00926540;
          if (local_8 == 2) {
            iVar4 = FUN_00915378(0x20400001,0xffffffff,0xffffffff);
            local_30 = 0;
            do {
              iVar7 = local_7c[local_30] * 4;
              if ((**(uint **)(*(int *)(in_ECX + 0x18) +
                              *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar7) + 0x48) * 4) &
                  0xfff00000) == 0x10000000) {
                **(undefined4 **)
                  (*(int *)(in_ECX + 0x18) +
                  *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar7) + 0x48) * 4) = 0;
                local_7c[local_30] =
                     **(int **)(*(int *)(*(int *)(in_ECX + 0x18) +
                                        *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar7) + 0x48) *
                                        4) + 8);
              }
              local_30 = local_30 + 1;
            } while (local_30 < 2);
          }
          else {
            iVar4 = FUN_00915378(local_8 & 0xfffff | 0x50000000,0xffffffff,0xffffffff);
          }
          if (iVar4 == -1) {
            return -0x7ff8fff2;
          }
          piVar5 = *(int **)(*(int *)(in_ECX + 0x18) + iVar4 * 4);
          local_5c = piVar5;
          FUN_00914593();
          *(undefined4 *)piVar5[4] = *(undefined4 *)local_14[4];
          *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)piVar5[4] * 4) + 0x48) = iVar4;
          piVar8 = local_7c;
          piVar5 = (int *)piVar5[2];
          for (uVar6 = local_8 & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
            *piVar5 = *piVar8;
            piVar8 = piVar8 + 1;
            piVar5 = piVar5 + 1;
          }
          for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
            *(char *)piVar5 = (char)*piVar8;
            piVar8 = (int *)((int)piVar8 + 1);
            piVar5 = (int *)((int)piVar5 + 1);
          }
          if (local_8 != 2) {
            if ((local_44 == -1) &&
               (local_44 = FUN_00915318(*(undefined4 *)(in_ECX + 0x78),0,0,0x3ff0000000000000),
               local_44 == -1)) goto LAB_00926594;
            if (local_8 != 0) {
              iVar4 = local_8 << 2;
              uVar6 = local_8;
              do {
                *(int *)(iVar4 + local_5c[2]) = local_44;
                iVar4 = iVar4 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
          }
          local_24 = local_24 + 1;
        }
        goto LAB_00926540;
      }
    }
    local_4c = FUN_00915378(*puVar2,puVar2[1],puVar2[3]);
    puVar2 = local_14;
    if (local_4c == -1) goto LAB_00926594;
    piVar5 = *(int **)(*(int *)(in_ECX + 0x18) + local_4c * 4);
    local_50 = piVar5;
    FUN_00914593();
    puVar9 = (undefined4 *)puVar2[2];
    puVar10 = (undefined4 *)piVar5[2];
    for (uVar6 = puVar2[1] & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    puVar9 = (undefined4 *)local_14[4];
    puVar10 = (undefined4 *)local_50[4];
    for (uVar6 = local_14[3] & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    uVar6 = 0;
    if (local_14[3] != 0) {
      do {
        *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(local_50[4] + uVar6 * 4) * 4) + 0x48) =
             local_4c;
        uVar6 = uVar6 + 1;
      } while (uVar6 < local_14[3]);
    }
  }
LAB_00926540:
  local_34 = local_34 + 1;
  if (local_38 <= local_34) goto LAB_0092654f;
  goto LAB_00925fa1;
}


// ==== FUN_009265b2 @ 0x009265b2 ====

undefined4 FUN_009265b2(void)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  int *piVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  undefined4 *puVar12;
  uint *puVar13;
  undefined4 *puVar14;
  uint *puVar15;
  undefined1 local_bc [16];
  uint local_ac [4];
  uint local_9c [4];
  uint local_8c [4];
  int local_7c;
  uint local_78 [4];
  undefined4 local_68;
  uint *local_64;
  uint local_60;
  int local_5c;
  uint local_58;
  undefined4 *local_54;
  uint local_50 [4];
  uint *local_40;
  uint *local_3c;
  uint *local_38;
  uint *local_34;
  uint *local_30;
  uint *local_2c;
  uint local_28;
  uint *local_24;
  uint *local_20;
  uint *local_1c;
  uint *local_18;
  uint *local_14;
  uint *local_10;
  uint *local_c;
  uint *local_8;
  
  uVar4 = 0;
  if ((*(byte *)(in_ECX + 0xcc) & 4) != 0) {
    return 1;
  }
  local_68 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    do {
      iVar10 = uVar4 * 4;
      uVar4 = uVar4 + 1;
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x10) + iVar10) + 0x10) = 0;
    } while (uVar4 < *(uint *)(in_ECX + 4));
  }
  uVar4 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + uVar4 * 4);
      iVar6 = *(int *)(iVar10 + 4);
      if (*(int *)(in_ECX + 0x74) != iVar6) {
        iVar6 = *(int *)(*(int *)(in_ECX + 0x10) + iVar6 * 4);
        if ((((*(uint *)(iVar6 + 4) & 2) != 0) && ((*(uint *)(iVar6 + 4) & 0x400) == 0)) &&
           (uVar5 = *(int *)(iVar10 + 0xc) + 1, *(uint *)(iVar6 + 0x10) < uVar5)) {
          *(uint *)(iVar6 + 0x10) = uVar5;
        }
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(in_ECX + 8));
  }
  uVar4 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    piVar7 = *(int **)(in_ECX + 0x10);
    iVar10 = *(int *)(in_ECX + 4);
    do {
      uVar4 = uVar4 + *(int *)(*piVar7 + 0x10);
      piVar7 = piVar7 + 1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  local_54 = operator_new(uVar4 << 2);
  if (local_54 != (undefined4 *)0x0) {
    puVar12 = local_54;
    for (uVar4 = uVar4 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
    for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
      *(undefined1 *)puVar12 = 0;
      puVar12 = (undefined4 *)((int)puVar12 + 1);
    }
    uVar4 = 0;
    iVar10 = 0;
    if (*(int *)(in_ECX + 4) != 0) {
      iVar6 = *(int *)(in_ECX + 0x10);
      do {
        iVar6 = *(int *)(iVar6 + uVar4 * 4);
        *(uint *)(iVar6 + 0x1c) = -(uint)(*(int *)(iVar6 + 0x10) != 0) & (uint)(local_54 + iVar10);
        iVar6 = *(int *)(in_ECX + 0x10);
        iVar10 = iVar10 + *(int *)(*(int *)(iVar6 + uVar4 * 4) + 0x10);
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(in_ECX + 4));
    }
    uVar4 = 0;
    if (*(int *)(in_ECX + 8) != 0) {
      do {
        iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + uVar4 * 4);
        if ((*(int *)(in_ECX + 0x74) != *(int *)(iVar10 + 4)) &&
           (iVar6 = *(int *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar10 + 4) * 4) + 0x1c),
           iVar6 != 0)) {
          puVar8 = (uint *)(iVar6 + *(int *)(iVar10 + 0xc) * 4);
          uVar5 = *(int *)(iVar10 + 0x10) + 1;
          if (*puVar8 < uVar5) {
            *puVar8 = uVar5;
          }
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(in_ECX + 8));
    }
    local_1c = (uint *)0x0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        puVar8 = *(uint **)(*(int *)(in_ECX + 0x18) + (int)local_1c * 4);
        if ((((*puVar8 & 0xf0000000) == 0x60000000) || ((*puVar8 & 0xfff00000) == 0x11000000)) &&
           (uVar4 = 0, puVar8[1] != 0)) {
          do {
            iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar8[2] + uVar4 * 4) * 4);
            iVar6 = *(int *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar10 + 4) * 4) + 0x1c);
            if (iVar6 != 0) {
              *(undefined4 *)(iVar6 + *(int *)(iVar10 + 0xc) * 4) = 4;
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < puVar8[1]);
        }
        local_1c = (uint *)((int)local_1c + 1);
      } while (local_1c < *(uint **)(in_ECX + 0xc));
    }
    if ((*(uint *)(in_ECX + 0x6c) & 6) == 0) {
      FUN_009198e4();
      local_c = (uint *)0x0;
      if (*(int *)(in_ECX + 0xc) != 0) {
        do {
          iVar10 = *(int *)(in_ECX + 0x18);
          local_20 = *(uint **)(iVar10 + (int)local_c * 4);
          if (*local_20 == 0x20400001) {
            iVar6 = *(int *)(in_ECX + 0x14);
            local_2c = *(uint **)(iVar6 + ((int *)local_20[2])[1] * 4);
            iVar2 = *(int *)(iVar6 + *(int *)local_20[2] * 4);
            if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar2 + 4) * 4) + 4) & 2) !=
                 0) && ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + local_2c[1] * 4) + 4) & 2) !=
                        0)) {
              local_1c = *(uint **)(iVar10 + *(int *)(iVar2 + 0x48) * 4);
              local_14 = *(uint **)(iVar10 + local_2c[0x12] * 4);
              if (((*local_1c == 0x20500001) || ((*local_1c & 0xfff00000) == 0x50000000)) &&
                 ((*local_14 == 0x20500001 || ((*local_14 & 0xfff00000) == 0x50000000)))) {
                local_2c = (uint *)(local_14[1] >> 1);
                uVar4 = local_1c[1] >> 1;
                local_18 = (uint *)((int)local_2c + uVar4);
                if (((uint *)((~*(uint *)(in_ECX + 0x6c) & 0x20 | 0x40) >> 5) <= local_18) &&
                   ((((local_18 < (uint *)0x5 &&
                      (iVar10 = *(int *)(iVar6 + *(int *)local_1c[4] * 4),
                      local_c == *(uint **)(iVar10 + 0x54))) &&
                     (local_c == *(uint **)(iVar10 + 0x58))) &&
                    ((iVar10 = *(int *)(iVar6 + *(int *)local_14[4] * 4),
                     local_c == *(uint **)(iVar10 + 0x54) && (local_c == *(uint **)(iVar10 + 0x58)))
                    )))) {
                  local_30 = (uint *)local_1c[2];
                  puVar8 = local_30;
                  puVar11 = local_78;
                  for (uVar5 = uVar4 & 0x3fffffff; puVar13 = local_14, uVar5 != 0; uVar5 = uVar5 - 1
                      ) {
                    *puVar11 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar11 = puVar11 + 1;
                  }
                  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(char *)puVar11 = (char)*puVar8;
                    puVar8 = (uint *)((int)puVar8 + 1);
                    puVar11 = (uint *)((int)puVar11 + 1);
                  }
                  local_40 = (uint *)puVar13[2];
                  local_24 = (uint *)((int)local_2c << 2);
                  puVar8 = local_40;
                  puVar11 = local_78 + uVar4;
                  for (uVar5 = (uint)local_2c & 0x3fffffff; puVar13 = local_30, uVar5 != 0;
                      uVar5 = uVar5 - 1) {
                    *puVar11 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar11 = puVar11 + 1;
                  }
                  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(char *)puVar11 = (char)*puVar8;
                    puVar8 = (uint *)((int)puVar8 + 1);
                    puVar11 = (uint *)((int)puVar11 + 1);
                  }
                  puVar8 = puVar13 + uVar4;
                  puVar11 = local_9c;
                  for (uVar5 = uVar4 & 0x3fffffff; puVar13 = local_40, uVar5 != 0; uVar5 = uVar5 - 1
                      ) {
                    *puVar11 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar11 = puVar11 + 1;
                  }
                  for (iVar10 = 0; puVar15 = local_24, iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(char *)puVar11 = (char)*puVar8;
                    puVar8 = (uint *)((int)puVar8 + 1);
                    puVar11 = (uint *)((int)puVar11 + 1);
                  }
                  puVar8 = (uint *)((int)puVar13 + (int)local_24);
                  puVar11 = local_9c + uVar4;
                  local_38 = (uint *)(uVar4 * 4);
                  for (uVar5 = (uint)local_24 >> 2; puVar3 = local_18, puVar13 = local_20,
                      uVar5 != 0; uVar5 = uVar5 - 1) {
                    *puVar11 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar11 = puVar11 + 1;
                  }
                  for (uVar4 = (uint)puVar15 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
                    *(char *)puVar11 = (char)*puVar8;
                    puVar8 = (uint *)((int)puVar8 + 1);
                    puVar11 = (uint *)((int)puVar11 + 1);
                  }
                  iVar10 = FUN_009205c9(local_78,puVar3,0,0,puVar13,0,0xffffffff);
                  if ((iVar10 == 0) ||
                     (iVar10 = FUN_009205c9(local_9c,local_18,0,0,local_20,0,0xffffffff),
                     iVar10 == 0)) {
                    puVar11 = local_38;
                    puVar8 = (uint *)local_1c[2];
                    puVar13 = puVar8;
                    puVar15 = local_50;
                    for (uVar4 = (uint)local_38 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
                      *puVar15 = *puVar13;
                      puVar13 = puVar13 + 1;
                      puVar15 = puVar15 + 1;
                    }
                    for (uVar4 = (uint)puVar11 & 3; puVar11 = local_24, uVar4 != 0;
                        uVar4 = uVar4 - 1) {
                      *(char *)puVar15 = (char)*puVar13;
                      puVar13 = (uint *)((int)puVar13 + 1);
                      puVar15 = (uint *)((int)puVar15 + 1);
                    }
                    local_40 = (uint *)local_14[2];
                    puVar12 = (undefined4 *)((int)local_40 + (int)local_24);
                    puVar14 = (undefined4 *)((int)local_50 + (int)local_38);
                    for (uVar4 = (uint)local_24 >> 2; puVar13 = local_38, uVar4 != 0;
                        uVar4 = uVar4 - 1) {
                      *puVar14 = *puVar12;
                      puVar12 = puVar12 + 1;
                      puVar14 = puVar14 + 1;
                    }
                    for (uVar4 = (uint)puVar11 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
                      *(undefined1 *)puVar14 = *(undefined1 *)puVar12;
                      puVar12 = (undefined4 *)((int)puVar12 + 1);
                      puVar14 = (undefined4 *)((int)puVar14 + 1);
                    }
                    puVar8 = (uint *)((int)puVar8 + (int)puVar13);
                    puVar11 = local_8c;
                    for (uVar4 = (uint)puVar13 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
                      *puVar11 = *puVar8;
                      puVar8 = puVar8 + 1;
                      puVar11 = puVar11 + 1;
                    }
                    for (uVar4 = (uint)puVar13 & 3; puVar15 = local_24, uVar4 != 0;
                        uVar4 = uVar4 - 1) {
                      *(char *)puVar11 = (char)*puVar8;
                      puVar8 = (uint *)((int)puVar8 + 1);
                      puVar11 = (uint *)((int)puVar11 + 1);
                    }
                    puVar8 = local_40;
                    puVar11 = (uint *)((int)local_8c + (int)puVar13);
                    for (uVar4 = (uint)local_24 >> 2; puVar3 = local_18, puVar13 = local_20,
                        uVar4 != 0; uVar4 = uVar4 - 1) {
                      *puVar11 = *puVar8;
                      puVar8 = puVar8 + 1;
                      puVar11 = puVar11 + 1;
                    }
                    for (uVar4 = (uint)puVar15 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
                      *(char *)puVar11 = (char)*puVar8;
                      puVar8 = (uint *)((int)puVar8 + 1);
                      puVar11 = (uint *)((int)puVar11 + 1);
                    }
                    iVar10 = FUN_009205c9(local_50,puVar3,0,0,puVar13,0,0xffffffff);
                    if ((iVar10 == 0) ||
                       (iVar10 = FUN_009205c9(local_8c,local_18,0,0,local_20,0,0xffffffff),
                       iVar10 == 0)) goto LAB_00926acd;
                    local_38 = (uint *)0x1;
                  }
                  else {
                    local_38 = (uint *)0x0;
                  }
                  iVar10 = FUN_009149f7(0x74);
                  if (iVar10 == 0) {
                    local_34 = (uint *)0x0;
                  }
                  else {
                    local_34 = (uint *)FUN_0091455d();
                  }
                  puVar8 = local_34;
                  if (local_34 == (uint *)0x0) goto LAB_00927437;
                  iVar10 = FUN_00914a42((uint)local_18 & 0xfffff | 0x50000000,(int)local_18 * 2,1,0)
                  ;
                  if ((iVar10 < 0) || (iVar10 = FUN_00914593(local_20), iVar10 < 0))
                  goto LAB_00926b91;
                  *(undefined4 *)puVar8[4] = *(undefined4 *)local_20[4];
                  puVar8 = local_78;
                  if (local_38 != (uint *)0x0) {
                    puVar8 = local_50;
                  }
                  puVar11 = (uint *)local_34[2];
                  for (uVar4 = (uint)local_18 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
                    *puVar11 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar11 = puVar11 + 1;
                  }
                  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(char *)puVar11 = (char)*puVar8;
                    puVar8 = (uint *)((int)puVar8 + 1);
                    puVar11 = (uint *)((int)puVar11 + 1);
                  }
                  puVar8 = local_9c;
                  if (local_38 != (uint *)0x0) {
                    puVar8 = local_8c;
                  }
                  puVar11 = (uint *)(local_34[2] + (int)local_18 * 4);
                  for (uVar4 = (uint)local_18 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
                    *puVar11 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar11 = puVar11 + 1;
                  }
                  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(char *)puVar11 = (char)*puVar8;
                    puVar8 = (uint *)((int)puVar8 + 1);
                    puVar11 = (uint *)((int)puVar11 + 1);
                  }
                  *(uint **)(*(int *)(in_ECX + 0x18) + (int)local_c * 4) = local_34;
                  FUN_008f4adb(1);
                  *local_1c = 0;
                  *local_14 = 0;
                }
              }
            }
          }
LAB_00926acd:
          local_c = (uint *)((int)local_c + 1);
        } while (local_c < *(uint **)(in_ECX + 0xc));
      }
    }
    FUN_009198e4();
    local_18 = (uint *)0x0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        puVar8 = *(uint **)(*(int *)(in_ECX + 0x18) + (int)local_18 * 4);
        uVar4 = *puVar8 & 0xf0000000;
        local_2c = puVar8;
        if ((((0xfffffff < uVar4) && (uVar4 < 0x40000001)) &&
            (((*puVar8 & 0xfff00000) == 0x10000000 || ((*(byte *)(in_ECX + 0x6c) & 6) == 0)))) &&
           (iVar10 = FUN_009147e7(), iVar10 == 0)) {
          iVar10 = *(int *)(in_ECX + 0x14);
          local_5c = *(int *)(*(int *)(iVar10 + *(int *)puVar8[4] * 4) + 4);
          local_24 = *(uint **)(*(int *)(*(int *)(in_ECX + 0x10) + local_5c * 4) + 0x1c);
          if (local_24 != (uint *)0x0) {
            local_38 = *(uint **)(in_ECX + 0xc);
            local_34 = (uint *)0x0;
            if (puVar8[1] != 0) {
              local_1c = (uint *)puVar8[2];
              local_30 = (uint *)puVar8[1];
              do {
                uVar4 = *local_1c;
                while (uVar4 != 0xffffffff) {
                  iVar6 = *(int *)(iVar10 + uVar4 * 4);
                  if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar6 + 4) * 4) + 4) &
                       2) != 0) &&
                     (puVar11 = (uint *)(*(int *)(iVar6 + 0x48) + 1), local_34 < puVar11)) {
                    local_34 = puVar11;
                  }
                  uVar4 = *(uint *)(iVar6 + 8);
                }
                local_1c = local_1c + 1;
                local_30 = (uint *)((int)local_30 + -1);
              } while (local_30 != (uint *)0x0);
            }
            local_40 = local_38;
            if (puVar8[3] != 0) {
              local_30 = (uint *)puVar8[3];
              piVar7 = (int *)puVar8[4];
              do {
                iVar6 = *(int *)(iVar10 + *piVar7 * 4);
                if (*(uint **)(iVar6 + 0x54) < local_40) {
                  local_40 = *(uint **)(iVar6 + 0x54);
                }
                while (*(int *)(iVar6 + 8) != -1) {
                  iVar6 = *(int *)(iVar10 + *(int *)(iVar6 + 8) * 4);
                  if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar6 + 4) * 4) + 4) &
                       2) != 0) &&
                     (puVar8 = (uint *)(*(int *)(iVar6 + 0x48) + 1), local_34 < puVar8)) {
                    local_34 = puVar8;
                  }
                }
                piVar7 = piVar7 + 1;
                local_30 = (uint *)((int)local_30 + -1);
              } while (local_30 != (uint *)0x0);
            }
            local_20 = local_34;
LAB_00927122:
            if (local_20 < local_40) {
              if (local_18 == local_20) goto LAB_0092711c;
              local_64 = *(uint **)(*(int *)(in_ECX + 0x18) + (int)local_20 * 4);
              if (local_18 < local_20) {
                local_8 = local_2c;
                local_c = local_64;
              }
              else {
                local_8 = local_64;
                local_c = local_2c;
              }
              local_58 = *local_c;
              local_10 = (uint *)(local_58 & 0xfff00000);
              if (local_10 != (uint *)(*local_8 & 0xfff00000)) goto LAB_0092711c;
              iVar10 = *(int *)(in_ECX + 0x14);
              iVar6 = *(int *)(iVar10 + *(int *)local_8[4] * 4);
              iVar2 = *(int *)(iVar10 + *(int *)local_c[4] * 4);
              local_3c = *(uint **)(iVar2 + 4);
              if ((((local_3c != *(uint **)(iVar6 + 4)) ||
                   (*(int *)(iVar2 + 8) != *(int *)(iVar6 + 8))) ||
                  (*(int *)(iVar2 + 0x14) != *(int *)(iVar6 + 0x14))) ||
                 (*(int *)(iVar2 + 0x18) != *(int *)(iVar6 + 0x18))) goto LAB_0092711c;
              local_7c = local_8[1] + local_c[1];
              local_14 = (uint *)local_c[3];
              uVar4 = local_8[3];
              local_28 = (int)local_14 + uVar4;
              local_60 = uVar4;
              if (4 < local_28) goto LAB_0092711c;
              local_1c = *(uint **)(iVar2 + 0xc);
              local_30 = *(uint **)(iVar6 + 0xc);
              if ((local_1c != local_30) &&
                 ((((*(byte *)(in_ECX + 0x6c) & 6) != 0 ||
                   ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + (int)local_3c * 4) + 4) & 0x20) !=
                    0)) || (4 < (uint)(*(int *)((int)local_24 + (int)local_30 * 4) +
                                      *(int *)((int)local_24 + (int)local_1c * 4))))))
              goto LAB_0092711c;
              local_3c = local_18;
              if (local_20 <= local_18) {
                local_3c = local_20;
              }
              puVar11 = local_3c;
              puVar8 = local_38;
              if ((local_10 != (uint *)0x10000000) && (local_10 != (uint *)0x10100000)) {
                uVar5 = local_58 & 0xf0000000;
                if (uVar5 == 0x10000000) {
                  puVar8 = (uint *)local_8[2];
                  puVar13 = local_50;
                  for (uVar5 = uVar4 & 0x3fffffff; puVar15 = local_c, uVar5 != 0; uVar5 = uVar5 - 1)
                  {
                    *puVar13 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar13 = puVar13 + 1;
                  }
                  for (iVar10 = 0; puVar3 = local_8, iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(char *)puVar13 = (char)*puVar8;
                    puVar8 = (uint *)((int)puVar8 + 1);
                    puVar13 = (uint *)((int)puVar13 + 1);
                  }
                  puVar13 = (uint *)puVar15[2];
                  puVar15 = local_50 + uVar4;
                  for (puVar8 = local_14; puVar8 != (uint *)0x0; puVar8 = (uint *)((int)puVar8 + -1)
                      ) {
                    *puVar15 = *puVar13;
                    puVar13 = puVar13 + 1;
                    puVar15 = puVar15 + 1;
                  }
                  iVar6 = FUN_009205c9(local_50,local_28,0,0,puVar3,0,puVar11);
LAB_00927084:
                  puVar8 = local_38;
                  if (iVar6 != 0) goto LAB_009270dd;
                }
                else if (uVar5 == 0x20000000) {
                  puVar8 = (uint *)local_8[2];
                  puVar11 = local_50;
                  for (uVar5 = uVar4 & 0x3fffffff; puVar13 = local_c, uVar5 != 0; uVar5 = uVar5 - 1)
                  {
                    *puVar11 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar11 = puVar11 + 1;
                  }
                  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(char *)puVar11 = (char)*puVar8;
                    puVar8 = (uint *)((int)puVar8 + 1);
                    puVar11 = (uint *)((int)puVar11 + 1);
                  }
                  local_10 = (uint *)puVar13[2];
                  uVar5 = (uint)local_14 & 0x3fffffff;
                  puVar8 = local_10;
                  puVar11 = local_50 + uVar4;
                  local_14 = (uint *)((int)local_14 << 2);
                  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
                    *puVar11 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar11 = puVar11 + 1;
                  }
                  uVar5 = local_8[2];
                  for (iVar10 = 0; puVar13 = local_3c, iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(char *)puVar11 = (char)*puVar8;
                    puVar8 = (uint *)((int)puVar8 + 1);
                    puVar11 = (uint *)((int)puVar11 + 1);
                  }
                  puVar8 = (uint *)(uVar5 + uVar4 * 4);
                  puVar11 = local_78;
                  for (uVar9 = uVar4 & 0x3fffffff; puVar15 = local_10, uVar9 != 0; uVar9 = uVar9 - 1
                      ) {
                    *puVar11 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar11 = puVar11 + 1;
                  }
                  for (iVar10 = 0; puVar3 = local_14, iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(char *)puVar11 = (char)*puVar8;
                    puVar8 = (uint *)((int)puVar8 + 1);
                    puVar11 = (uint *)((int)puVar11 + 1);
                  }
                  puVar8 = (uint *)((int)puVar15 + (int)local_14);
                  puVar11 = local_78 + uVar4;
                  local_58 = uVar4 * 4;
                  for (uVar5 = (uint)local_14 >> 2; puVar15 = local_8, uVar4 = local_28, uVar5 != 0;
                      uVar5 = uVar5 - 1) {
                    *puVar11 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar11 = puVar11 + 1;
                  }
                  for (uVar5 = (uint)puVar3 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                    *(char *)puVar11 = (char)*puVar8;
                    puVar8 = (uint *)((int)puVar8 + 1);
                    puVar11 = (uint *)((int)puVar11 + 1);
                  }
                  iVar10 = FUN_009205c9(local_50,uVar4,0,0,puVar15,0,puVar13);
                  iVar6 = FUN_009205c9(local_78,local_28,0,0,local_8,0,local_3c);
                  if ((iVar10 != 0) && (iVar6 != 0)) goto LAB_009270dd;
                  iVar10 = FUN_0091464c();
                  uVar4 = local_58;
                  puVar8 = local_38;
                  if (iVar10 != 0) {
                    puVar8 = (uint *)local_8[2];
                    puVar11 = local_8c;
                    for (uVar5 = local_58 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                      *puVar11 = *puVar8;
                      puVar8 = puVar8 + 1;
                      puVar11 = puVar11 + 1;
                    }
                    for (uVar5 = uVar4 & 3; puVar13 = local_14, uVar5 != 0; uVar5 = uVar5 - 1) {
                      *(char *)puVar11 = (char)*puVar8;
                      puVar8 = (uint *)((int)puVar8 + 1);
                      puVar11 = (uint *)((int)puVar11 + 1);
                    }
                    local_10 = (uint *)local_c[2];
                    puVar12 = (undefined4 *)((int)local_10 + (int)local_14);
                    puVar14 = (undefined4 *)((int)local_8c + uVar4);
                    for (uVar5 = (uint)local_14 >> 2; puVar8 = local_3c, uVar5 != 0;
                        uVar5 = uVar5 - 1) {
                      *puVar14 = *puVar12;
                      puVar12 = puVar12 + 1;
                      puVar14 = puVar14 + 1;
                    }
                    uVar5 = local_8[2];
                    for (uVar9 = (uint)puVar13 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                      *(undefined1 *)puVar14 = *(undefined1 *)puVar12;
                      puVar12 = (undefined4 *)((int)puVar12 + 1);
                      puVar14 = (undefined4 *)((int)puVar14 + 1);
                    }
                    puVar11 = (uint *)(uVar5 + uVar4);
                    puVar13 = local_9c;
                    for (uVar9 = uVar4 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
                      *puVar13 = *puVar11;
                      puVar11 = puVar11 + 1;
                      puVar13 = puVar13 + 1;
                    }
                    for (uVar5 = uVar4 & 3; puVar15 = local_14, uVar5 != 0; uVar5 = uVar5 - 1) {
                      *(char *)puVar13 = (char)*puVar11;
                      puVar11 = (uint *)((int)puVar11 + 1);
                      puVar13 = (uint *)((int)puVar13 + 1);
                    }
                    puVar11 = local_10;
                    puVar13 = (uint *)((int)local_9c + uVar4);
                    for (uVar5 = (uint)local_14 >> 2; puVar3 = local_8, uVar4 = local_28, uVar5 != 0
                        ; uVar5 = uVar5 - 1) {
                      *puVar13 = *puVar11;
                      puVar11 = puVar11 + 1;
                      puVar13 = puVar13 + 1;
                    }
                    for (uVar5 = (uint)puVar15 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                      *(char *)puVar13 = (char)*puVar11;
                      puVar11 = (uint *)((int)puVar11 + 1);
                      puVar13 = (uint *)((int)puVar13 + 1);
                    }
                    iVar10 = FUN_009205c9(local_8c,uVar4,0,0,puVar3,0,puVar8);
                    iVar6 = FUN_009205c9(local_9c,local_28,0,0,local_8,0,local_3c);
                    puVar8 = local_38;
                    if ((iVar10 != 0) && (iVar6 != 0)) {
                      local_14 = (uint *)0x1;
                      goto LAB_009270e1;
                    }
                  }
                }
                else if (uVar5 == 0x30000000) {
                  puVar8 = (uint *)local_8[2];
                  puVar11 = local_50;
                  for (uVar5 = uVar4 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
                    *puVar11 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar11 = puVar11 + 1;
                  }
                  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(char *)puVar11 = (char)*puVar8;
                    puVar8 = (uint *)((int)puVar8 + 1);
                    puVar11 = (uint *)((int)puVar11 + 1);
                  }
                  local_10 = (uint *)local_c[2];
                  puVar8 = local_10;
                  puVar11 = local_50 + uVar4;
                  for (uVar5 = (uint)local_14 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
                    *puVar11 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar11 = puVar11 + 1;
                  }
                  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(char *)puVar11 = (char)*puVar8;
                    puVar8 = (uint *)((int)puVar8 + 1);
                    puVar11 = (uint *)((int)puVar11 + 1);
                  }
                  puVar8 = (uint *)(local_8[2] + uVar4 * 4);
                  puVar11 = local_78;
                  for (uVar5 = uVar4 & 0x3fffffff; puVar13 = local_10, uVar5 != 0; uVar5 = uVar5 - 1
                      ) {
                    *puVar11 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar11 = puVar11 + 1;
                  }
                  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(char *)puVar11 = (char)*puVar8;
                    puVar8 = (uint *)((int)puVar8 + 1);
                    puVar11 = (uint *)((int)puVar11 + 1);
                  }
                  puVar8 = puVar13 + (int)local_14;
                  puVar11 = local_78 + uVar4;
                  for (uVar5 = (uint)local_14 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
                    *puVar11 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar11 = puVar11 + 1;
                  }
                  uVar5 = local_8[2];
                  for (iVar10 = 0; puVar13 = local_3c, iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(char *)puVar11 = (char)*puVar8;
                    puVar8 = (uint *)((int)puVar8 + 1);
                    puVar11 = (uint *)((int)puVar11 + 1);
                  }
                  puVar8 = (uint *)(uVar5 + local_60 * 8);
                  puVar11 = local_ac;
                  for (uVar9 = uVar4 & 0x3fffffff; puVar15 = local_14, uVar9 != 0; uVar9 = uVar9 - 1
                      ) {
                    *puVar11 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar11 = puVar11 + 1;
                  }
                  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(char *)puVar11 = (char)*puVar8;
                    puVar8 = (uint *)((int)puVar8 + 1);
                    puVar11 = (uint *)((int)puVar11 + 1);
                  }
                  puVar8 = local_10 + (int)puVar15 * 2;
                  puVar11 = local_ac + uVar4;
                  for (uVar5 = (uint)puVar15 & 0x3fffffff; puVar15 = local_8, uVar4 = local_28,
                      uVar5 != 0; uVar5 = uVar5 - 1) {
                    *puVar11 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar11 = puVar11 + 1;
                  }
                  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(char *)puVar11 = (char)*puVar8;
                    puVar8 = (uint *)((int)puVar8 + 1);
                    puVar11 = (uint *)((int)puVar11 + 1);
                  }
                  iVar10 = FUN_009205c9(local_50,uVar4,0,0,puVar15,0,puVar13);
                  local_60 = FUN_009205c9(local_78,local_28,0,0,local_8,0,local_3c);
                  iVar6 = FUN_009205c9(local_ac,local_28,0,0,local_8,0,local_3c);
                  puVar8 = local_38;
                  if ((iVar10 != 0) && (local_60 != 0)) goto LAB_00927084;
                }
LAB_00927117:
                while (puVar8 < *(uint **)(in_ECX + 0xc)) {
                  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + -1;
                  if (*(int *)(*(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0xc) * 4) != 0) {
                    FUN_008f4adb(1);
                  }
                }
                goto LAB_0092711c;
              }
              local_10 = (uint *)local_c[2];
              iVar6 = *(int *)(iVar10 + *local_10 * 4);
              iVar10 = *(int *)(iVar10 + *(uint *)local_8[2] * 4);
              if (((*(int *)(iVar6 + 4) != *(int *)(iVar10 + 4)) ||
                  (*(int *)(iVar6 + 8) != *(int *)(iVar10 + 8))) ||
                 (*(int *)(iVar6 + 0xc) != *(int *)(iVar10 + 0xc))) goto LAB_00927117;
              puVar8 = (uint *)local_8[2];
              puVar11 = local_50;
              for (uVar5 = uVar4 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
                *puVar11 = *puVar8;
                puVar8 = puVar8 + 1;
                puVar11 = puVar11 + 1;
              }
              for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                *(char *)puVar11 = (char)*puVar8;
                puVar8 = (uint *)((int)puVar8 + 1);
                puVar11 = (uint *)((int)puVar11 + 1);
              }
              puVar11 = local_10;
              puVar13 = local_50 + uVar4;
              for (puVar8 = local_14; puVar8 != (uint *)0x0; puVar8 = (uint *)((int)puVar8 + -1)) {
                *puVar13 = *puVar11;
                puVar11 = puVar11 + 1;
                puVar13 = puVar13 + 1;
              }
LAB_009270dd:
              local_14 = (uint *)0x0;
LAB_009270e1:
              if ((local_1c != local_30) &&
                 (puVar8 = local_38,
                 4 < (uint)(*(int *)((int)local_24 + (int)local_30 * 4) +
                           *(int *)((int)local_24 + (int)local_1c * 4)))) goto LAB_00927117;
              iVar10 = FUN_009149f7(0x74);
              if (iVar10 == 0) {
                local_10 = (uint *)0x0;
              }
              else {
                local_10 = (uint *)FUN_0091455d();
              }
              puVar8 = local_c;
              if (local_10 == (uint *)0x0) break;
              iVar10 = FUN_00914a42((*local_c ^ local_28) & 0xfffff ^ *local_c,local_7c,local_28,0);
              if ((-1 < iVar10) &&
                 (iVar10 = FUN_00914593(puVar8), puVar11 = local_10, puVar8 = local_2c, -1 < iVar10)
                 ) {
                if (local_1c != local_30) {
                  uVar4 = 0;
                  if (*(int *)(in_ECX + 8) != 0) {
                    do {
                      iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + uVar4 * 4);
                      if ((local_5c == *(int *)(iVar10 + 4)) &&
                         (local_1c == *(uint **)(iVar10 + 0xc))) {
                        *(uint **)(iVar10 + 0xc) = local_30;
                        *(int *)(iVar10 + 0x10) =
                             *(int *)(iVar10 + 0x10) + *(int *)((int)local_24 + (int)local_30 * 4);
                      }
                      uVar4 = uVar4 + 1;
                    } while (uVar4 < *(uint *)(in_ECX + 8));
                  }
                  piVar7 = (int *)((int)local_24 + (int)local_30 * 4);
                  piVar1 = (int *)((int)local_24 + (int)local_1c * 4);
                  *piVar7 = *piVar7 + *piVar1;
                  *piVar1 = 0;
                }
                puVar12 = (undefined4 *)local_8[4];
                puVar14 = (undefined4 *)local_10[4];
                for (uVar4 = local_8[3] & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
                  *puVar14 = *puVar12;
                  puVar12 = puVar12 + 1;
                  puVar14 = puVar14 + 1;
                }
                for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                  *(undefined1 *)puVar14 = *(undefined1 *)puVar12;
                  puVar12 = (undefined4 *)((int)puVar12 + 1);
                  puVar14 = (undefined4 *)((int)puVar14 + 1);
                }
                puVar12 = (undefined4 *)local_c[4];
                puVar14 = (undefined4 *)(local_10[4] + local_8[3] * 4);
                for (uVar4 = local_c[3] & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
                  *puVar14 = *puVar12;
                  puVar12 = puVar12 + 1;
                  puVar14 = puVar14 + 1;
                }
                for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                  *(undefined1 *)puVar14 = *(undefined1 *)puVar12;
                  puVar12 = (undefined4 *)((int)puVar12 + 1);
                  puVar14 = (undefined4 *)((int)puVar14 + 1);
                }
                if ((*local_c & 0xf0000000) == 0x10000000) {
                  puVar13 = local_50;
                  puVar15 = (uint *)local_10[2];
                  for (uVar4 = local_28; uVar4 != 0; uVar4 = uVar4 - 1) {
                    *puVar15 = *puVar13;
                    puVar13 = puVar13 + 1;
                    puVar15 = puVar15 + 1;
                  }
                }
                if ((*local_c & 0xf0000000) == 0x20000000) {
                  puVar13 = local_50;
                  if (local_14 != (uint *)0x0) {
                    puVar13 = local_8c;
                  }
                  local_5c = local_28 * 4;
                  puVar15 = (uint *)local_10[2];
                  for (uVar4 = local_28 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
                    *puVar15 = *puVar13;
                    puVar13 = puVar13 + 1;
                    puVar15 = puVar15 + 1;
                  }
                  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(char *)puVar15 = (char)*puVar13;
                    puVar13 = (uint *)((int)puVar13 + 1);
                    puVar15 = (uint *)((int)puVar15 + 1);
                  }
                  puVar13 = local_78;
                  if (local_14 != (uint *)0x0) {
                    puVar13 = local_9c;
                  }
                  puVar15 = (uint *)(local_10[2] + local_28 * 4);
LAB_009272e4:
                  for (uVar4 = local_28 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
                    *puVar15 = *puVar13;
                    puVar13 = puVar13 + 1;
                    puVar15 = puVar15 + 1;
                  }
                  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(char *)puVar15 = (char)*puVar13;
                    puVar13 = (uint *)((int)puVar13 + 1);
                    puVar15 = (uint *)((int)puVar15 + 1);
                  }
                }
                else if ((*local_c & 0xf0000000) == 0x30000000) {
                  puVar13 = local_50;
                  puVar15 = (uint *)local_10[2];
                  for (uVar4 = local_28 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
                    *puVar15 = *puVar13;
                    puVar13 = puVar13 + 1;
                    puVar15 = puVar15 + 1;
                  }
                  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(char *)puVar15 = (char)*puVar13;
                    puVar13 = (uint *)((int)puVar13 + 1);
                    puVar15 = (uint *)((int)puVar15 + 1);
                  }
                  puVar13 = local_78;
                  puVar15 = (uint *)(local_10[2] + local_28 * 4);
                  for (uVar4 = local_28 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
                    *puVar15 = *puVar13;
                    puVar13 = puVar13 + 1;
                    puVar15 = puVar15 + 1;
                  }
                  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(char *)puVar15 = (char)*puVar13;
                    puVar13 = (uint *)((int)puVar13 + 1);
                    puVar15 = (uint *)((int)puVar15 + 1);
                  }
                  puVar13 = local_ac;
                  puVar15 = (uint *)(local_10[2] + local_28 * 8);
                  goto LAB_009272e4;
                }
                local_2c = (uint *)(local_2c[1] / (*local_2c & 0xfffff));
                FUN_00919678(local_10[4],local_bc,local_28,1);
                local_24 = (uint *)0x0;
                if (local_2c != (uint *)0x0) {
                  do {
                    FUN_00919678(puVar11[2] + puVar11[3] * (int)local_24 * 4,local_bc,local_28,0);
                    local_24 = (uint *)((int)local_24 + 1);
                  } while (local_24 < local_2c);
                }
                if (local_64 != (uint *)0x0) {
                  FUN_008f4adb(1);
                }
                local_24 = (uint *)((int)local_20 * 4);
                *(uint **)((int)local_24 + *(int *)(in_ECX + 0x18)) = puVar11;
                *puVar8 = 0;
                puVar8[1] = 0;
                puVar8[3] = 0;
                if (local_38 < *(uint **)(in_ECX + 0xc)) {
                  local_64 = (uint *)((int)*(uint **)(in_ECX + 0xc) - (int)local_38);
                  local_30 = (uint *)((int)local_64 * 4);
                  local_2c = operator_new((uint)local_30);
                  if (local_2c != (uint *)0x0) {
                    puVar8 = (uint *)(*(int *)(in_ECX + 0x18) + (int)local_38 * 4);
                    puVar11 = local_2c;
                    for (uVar4 = (uint)local_30 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
                      *puVar11 = *puVar8;
                      puVar8 = puVar8 + 1;
                      puVar11 = puVar11 + 1;
                    }
                    for (uVar4 = (uint)local_30 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
                      *(char *)puVar11 = (char)*puVar8;
                      puVar8 = (uint *)((int)puVar8 + 1);
                      puVar11 = (uint *)((int)puVar11 + 1);
                    }
                    _memmove((void *)(*(int *)(in_ECX + 0x18) +
                                     (int)((int)local_64 + (int)local_20) * 4),
                             (void *)((int)local_24 + *(int *)(in_ECX + 0x18)),
                             ((int)local_38 - (int)local_20) * 4);
                    puVar8 = local_2c;
                    puVar11 = (uint *)(*(int *)(in_ECX + 0x18) + (int)local_24);
                    for (uVar4 = (uint)local_30 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
                      *puVar11 = *puVar8;
                      puVar8 = puVar8 + 1;
                      puVar11 = puVar11 + 1;
                    }
                    for (uVar4 = (uint)local_30 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
                      *(char *)puVar11 = (char)*puVar8;
                      puVar8 = (uint *)((int)puVar8 + 1);
                      puVar11 = (uint *)((int)puVar11 + 1);
                    }
                    _free(local_2c);
                    return extraout_EAX;
                  }
                  break;
                }
                FUN_009198e4();
                local_18 = (uint *)((int)local_34 - 1);
                local_68 = 1;
                goto LAB_0092741e;
              }
              goto LAB_00926b91;
            }
          }
        }
LAB_0092741e:
        local_18 = (uint *)((int)local_18 + 1);
      } while (local_18 < *(uint **)(in_ECX + 0xc));
    }
  }
LAB_00927437:
  _free(local_54);
  return extraout_EAX_00;
LAB_0092711c:
  local_20 = (uint *)((int)local_20 + 1);
  goto LAB_00927122;
LAB_00926b91:
  FUN_008f4adb(1);
  goto LAB_00927437;
}


// ==== FUN_00927456 @ 0x00927456 ====

undefined4 FUN_00927456(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_EAX;
  byte bVar4;
  int in_ECX;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint *puVar12;
  uint local_68 [3];
  uint auStack_5c [9];
  int *local_38;
  int local_34;
  uint *local_30;
  int local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  int *local_1c;
  uint *local_18;
  uint local_14;
  int local_10;
  uint local_c;
  undefined4 *local_8;
  
  uVar7 = 0;
  local_20 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    piVar5 = *(int **)(in_ECX + 0x10);
    iVar9 = *(int *)(in_ECX + 4);
    do {
      uVar11 = *(uint *)(*piVar5 + 4);
      if (((uVar11 & 0x100) != 0) && ((uVar11 & 0xc00) != 0)) {
        uVar7 = uVar7 + *(int *)(*piVar5 + 8);
      }
      piVar5 = piVar5 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    local_20 = uVar7;
  }
  uVar7 = local_20 + *(int *)(in_ECX + 0xc) * 2;
  local_8 = operator_new(uVar7 * 0x10);
  if (local_8 == (undefined4 *)0x0) {
    return 0x8007000e;
  }
  puVar10 = local_8;
  for (iVar9 = (uVar7 & 0xfffffff) << 2; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar10 = 0xffffffff;
    puVar10 = puVar10 + 1;
  }
  for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
    *(undefined1 *)puVar10 = 0xff;
    puVar10 = (undefined4 *)((int)puVar10 + 1);
  }
  local_34 = 0;
  FUN_00919e76();
  local_14 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    do {
      local_1c = *(int **)(*(int *)(*(int *)(in_ECX + 0x10) + local_14 * 4) + 4);
      if ((((uint)local_1c & 0x100) != 0) && (((uint)local_1c & 0xc00) != 0)) {
        local_c = 0;
        if (local_20 != 0) {
          uVar7 = *(uint *)(in_ECX + 8);
          do {
            uVar11 = 0;
            if (uVar7 != 0) {
              do {
                iVar9 = *(int *)(*(int *)(in_ECX + 0x14) + uVar11 * 4);
                if ((((*(uint *)(iVar9 + 4) == local_14) && (*(int *)(iVar9 + 8) == -1)) &&
                    (local_8[*(int *)(iVar9 + 0x10) + (*(int *)(iVar9 + 0xc) + local_c) * 4] != -1))
                   && ((((uint)local_1c & 0x800) != 0 ||
                       (*(double *)(iVar9 + 0x20) !=
                        *(double *)
                         (*(int *)(*(int *)(in_ECX + 0x14) +
                                  local_8[*(int *)(iVar9 + 0x10) +
                                          (*(int *)(iVar9 + 0xc) + local_c) * 4] * 4) + 0x20)))))
                break;
                uVar11 = uVar11 + 1;
              } while (uVar11 < *(uint *)(in_ECX + 8));
            }
            uVar7 = *(uint *)(in_ECX + 8);
          } while ((uVar11 != uVar7) && (local_c = local_c + 1, local_c < local_20));
        }
        if (((uint)local_1c & 0x800) == 0) {
          uVar7 = 0;
          if (*(int *)(in_ECX + 8) != 0) {
            do {
              iVar9 = *(int *)(*(int *)(in_ECX + 0x14) + uVar7 * 4);
              if (*(uint *)(iVar9 + 4) == local_14) {
                *(int *)(iVar9 + 0xc) = *(int *)(iVar9 + 0xc) + local_c;
                if (*(int *)(iVar9 + 8) == -1) {
                  puVar8 = local_8 + *(int *)(iVar9 + 0x10) + *(int *)(iVar9 + 0xc) * 4;
                  if (*puVar8 == 0xffffffff) {
                    *puVar8 = uVar7;
                  }
                  else {
                    *(undefined4 *)(iVar9 + 4) = *(undefined4 *)(in_ECX + 0x74);
                    *(uint *)(iVar9 + 0x30) = *puVar8;
                    local_34 = 1;
                  }
                }
              }
              uVar7 = uVar7 + 1;
            } while (uVar7 < *(uint *)(in_ECX + 8));
          }
        }
        else {
          uVar7 = 0;
          if (*(int *)(in_ECX + 8) != 0) {
            do {
              iVar9 = *(int *)(*(int *)(in_ECX + 0x14) + uVar7 * 4);
              if (*(uint *)(iVar9 + 4) == local_14) {
                local_8[*(int *)(iVar9 + 0x10) + (*(int *)(iVar9 + 0xc) + local_c) * 4] = uVar7;
              }
              uVar7 = uVar7 + 1;
            } while (uVar7 < *(uint *)(in_ECX + 8));
          }
        }
      }
      local_14 = local_14 + 1;
    } while (local_14 < *(uint *)(in_ECX + 4));
    if (local_34 != 0) {
      FUN_00919e8f();
    }
  }
  uVar7 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar9 = *(int *)(*(int *)(in_ECX + 0x14) + uVar7 * 4);
      uVar11 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar9 + 4) * 4) + 4);
      if (((uVar11 & 0x100) != 0) && ((uVar11 & 0xc00) == 0)) {
        *(undefined4 *)(iVar9 + 0xc) = 0xffffffff;
        *(undefined4 *)(iVar9 + 4) = *(undefined4 *)(in_ECX + 0x78);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(in_ECX + 8));
  }
  local_20 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      local_10 = *(int *)(*(int *)(in_ECX + 0x18) + local_20 * 4);
      if ((*(ushort *)(local_10 + 2) & 0xfff0) != 0) {
        auStack_5c[5] = 0xffffffff;
        auStack_5c[6] = 0xffffffff;
        auStack_5c[7] = 0xffffffff;
        auStack_5c[8] = 0xffffffff;
        auStack_5c[1] = 0;
        auStack_5c[2] = 0;
        auStack_5c[3] = 0;
        auStack_5c[4] = 0;
        local_c = 0;
        local_2c = 0;
        local_24 = 0;
        uVar7 = FUN_009145b2(0,&local_1c);
        local_28 = uVar7;
        if (uVar7 == 0) {
LAB_009277aa:
          iVar9 = FUN_00918a13(local_8,auStack_5c + 5,auStack_5c + 1);
          if (-1 < iVar9) {
            iVar9 = 0;
            iVar3 = FUN_009145b2(0,&local_38);
            while (iVar3 != 0) {
              iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *local_38 * 4);
              if ((*(int *)(in_ECX + 0x78) == *(int *)(iVar2 + 4)) && (*(int *)(iVar2 + 8) == -1)) {
                FUN_00918922(auStack_5c + 5,local_38,iVar3);
              }
              iVar9 = iVar9 + 1;
              iVar3 = FUN_009145b2(iVar9,&local_38);
            }
            goto LAB_009278c5;
          }
        }
        else {
          puVar8 = local_68;
          local_18 = puVar8;
          do {
            iVar9 = *(int *)(in_ECX + 0x14);
            iVar3 = *(int *)(iVar9 + *local_1c * 4);
            local_28 = uVar7;
            if ((*(int *)(in_ECX + 0x78) == *(int *)(iVar3 + 4)) && (*(int *)(iVar3 + 8) == -1)) {
              *puVar8 = (~*(uint *)(in_ECX + 0x6c) & 4) >> 2;
              uVar11 = 1;
              if (1 < uVar7) {
                do {
                  if (*puVar8 == 0) break;
                  if (*(double *)(iVar3 + 0x20) !=
                      *(double *)(*(int *)(iVar9 + local_1c[uVar11] * 4) + 0x20)) {
                    *puVar8 = 0;
                  }
                  uVar11 = uVar11 + 1;
                  uVar7 = local_28;
                } while (uVar11 < local_28);
              }
              local_14 = 0;
              if (uVar7 != 0) {
                do {
                  uVar7 = local_c;
                  uVar11 = 0;
                  if (local_c != 0) {
                    do {
                      if (*(double *)(*(int *)(iVar9 + auStack_5c[uVar11 + 5] * 4) + 0x20) ==
                          *(double *)(*(int *)(iVar9 + local_1c[local_14] * 4) + 0x20)) break;
                      uVar11 = uVar11 + 1;
                    } while (uVar11 < local_c);
                    if (uVar11 == 4) {
                      local_2c = 1;
                      break;
                    }
                  }
                  if (uVar11 == local_c) {
                    local_c = local_c + 1;
                    auStack_5c[uVar7 + 5] = local_1c[local_14];
                  }
                  if (*local_18 == 0) {
                    auStack_5c[uVar11 + 1] = auStack_5c[uVar11 + 1] | 1 << ((byte)local_14 & 0x1f);
                  }
                  local_14 = local_14 + 1;
                } while (local_14 < local_28);
                puVar8 = local_18;
              }
              if (local_2c != 0) goto LAB_00927814;
            }
            local_24 = local_24 + 1;
            puVar8 = puVar8 + 1;
            local_18 = puVar8;
            uVar7 = FUN_009145b2(local_24,&local_1c);
            local_28 = uVar7;
          } while (uVar7 != 0);
          if (local_2c == 0) goto LAB_009277aa;
        }
LAB_00927814:
        local_2c = 0;
        while (uVar7 = FUN_009145b2(local_2c,&local_30), local_14 = uVar7, uVar7 != 0) {
          iVar9 = *(int *)(*(int *)(in_ECX + 0x14) + *local_30 * 4);
          if ((*(int *)(in_ECX + 0x78) == *(int *)(iVar9 + 4)) && (*(int *)(iVar9 + 8) == -1)) {
            uVar11 = 0;
            if (uVar7 != 0) {
              puVar8 = local_30;
              puVar12 = auStack_5c + 5;
              for (uVar6 = uVar7; uVar6 != 0; uVar6 = uVar6 - 1) {
                *puVar12 = *puVar8;
                puVar8 = puVar8 + 1;
                puVar12 = puVar12 + 1;
              }
              do {
                bVar4 = (byte)uVar11;
                uVar11 = uVar11 + 1;
                auStack_5c[uVar11] = 1 << (bVar4 & 0x1f);
              } while (uVar11 < uVar7);
            }
            if (uVar7 < 4) {
              puVar8 = auStack_5c + uVar7 + 1;
              for (uVar11 = 4 - uVar7 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
                *puVar8 = 0;
                puVar8 = puVar8 + 1;
              }
              puVar8 = auStack_5c + uVar7 + 5;
              for (uVar11 = 4 - uVar7 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
                *puVar8 = 0xffffffff;
                puVar8 = puVar8 + 1;
              }
            }
            FUN_00918a13(local_8,auStack_5c + 5,auStack_5c + 1);
            FUN_00918922(auStack_5c + 5,local_30,local_14);
          }
          local_2c = local_2c + 1;
        }
      }
LAB_009278c5:
      local_20 = local_20 + 1;
    } while (local_20 < *(uint *)(in_ECX + 0xc));
  }
  uVar7 = 0;
  local_38 = (int *)0x0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar9 = *(int *)(*(int *)(in_ECX + 0x14) + uVar7 * 4);
      if ((*(int *)(in_ECX + 0x78) == *(int *)(iVar9 + 4)) && (*(int *)(iVar9 + 0xc) == -1)) {
        *(undefined4 *)(iVar9 + 4) = *(undefined4 *)(in_ECX + 0x74);
      }
      else {
        uVar11 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar9 + 4) * 4) + 4);
        if (((uVar11 & 0x100) != 0) &&
           ((((uVar11 & 0x40) != 0 && ((uVar11 & 0x800) == 0)) &&
            (*(int *)(iVar9 + 4) = *(int *)(in_ECX + 0x78), *(int *)(iVar9 + 8) != -1)))) {
          local_38 = (int *)0x1;
        }
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(in_ECX + 8));
  }
  puVar8 = (uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0x78) * 4) + 4);
  *puVar8 = *puVar8 | 0x40;
  if (local_38 != (int *)0x0) {
    pbVar1 = (byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0x78) * 4) + 5);
    *pbVar1 = *pbVar1 | 4;
  }
  *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0x78) * 4) + 8) = 0;
  uVar7 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar9 = *(int *)(*(int *)(in_ECX + 0x14) + uVar7 * 4);
      if ((*(int *)(in_ECX + 0x78) == *(int *)(iVar9 + 4)) && (*(int *)(iVar9 + 8) == -1)) {
        iVar3 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0x78) * 4);
        if (*(uint *)(iVar3 + 8) <= *(uint *)(iVar9 + 0xc)) {
          *(uint *)(iVar3 + 8) = *(uint *)(iVar9 + 0xc) + 1;
        }
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(in_ECX + 8));
  }
  if (local_34 != 0) {
    FUN_009237bb();
  }
  *(undefined4 *)(in_ECX + 0xdc) = 1;
  _free(local_8);
  return extraout_EAX;
}


// ==== FUN_009279b0 @ 0x009279b0 ====

int FUN_009279b0(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int extraout_EAX;
  int in_ECX;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined1 local_7c [100];
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  if ((*(byte *)(in_ECX + 0x6f) & 0xc) == 0) {
    return 1;
  }
  iVar2 = FUN_00915e19();
  if (iVar2 < 0) {
    return iVar2;
  }
  iVar2 = FUN_00921938(local_7c,*(undefined4 *)(in_ECX + 0x88),*(int *)(in_ECX + 0x2c) + -1);
  if ((iVar2 < 0) || (iVar2 = FUN_00922003(local_7c,0), iVar2 < 0)) {
    FUN_009195d7(local_7c);
    iVar2 = FUN_00921938(local_7c,*(undefined4 *)(in_ECX + 0x88),*(undefined4 *)(in_ECX + 0x2c));
    if ((iVar2 < 0) || (iVar2 = FUN_00922003(local_7c,0), iVar2 < 0)) goto LAB_00927bca;
  }
  local_8 = operator_new(*(int *)(in_ECX + 0xc) << 2);
  if (local_8 != (undefined4 *)0x0) {
    puVar6 = *(undefined4 **)(in_ECX + 0x18);
    puVar8 = local_8;
    for (uVar5 = *(uint *)(in_ECX + 0xc) & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    local_10 = FUN_009182b3();
    local_14 = 0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x18) + local_14 * 4) + 0x2c) & 1) != 0) {
          local_c = local_14;
          if (local_14 != 0) {
            do {
              iVar2 = FUN_00918365(local_c);
              if (iVar2 == 0) break;
              local_18 = FUN_009182b3();
              if ((local_18 <= local_10) &&
                 (((local_18 != local_10 ||
                   (((*(byte *)(in_ECX + 0x6f) & 8) == 0 &&
                    (piVar3 = (int *)(*(int *)(in_ECX + 0x18) + local_c * 4),
                    *(int *)(*piVar3 + 0x2c) == *(int *)(piVar3[-1] + 0x2c))))) &&
                  (iVar2 = FUN_00922003(local_7c,0), -1 < iVar2)))) {
                puVar6 = *(undefined4 **)(in_ECX + 0x18);
                puVar8 = local_8;
                for (uVar5 = local_14 * 4 + 4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                  *puVar8 = *puVar6;
                  puVar6 = puVar6 + 1;
                  puVar8 = puVar8 + 1;
                }
                for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
                  *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
                  puVar6 = (undefined4 *)((int)puVar6 + 1);
                  puVar8 = (undefined4 *)((int)puVar8 + 1);
                }
                local_10 = local_18;
              }
              local_c = local_c - 1;
            } while (local_c != 0);
          }
          puVar6 = local_8;
          puVar8 = *(undefined4 **)(in_ECX + 0x18);
          for (uVar5 = local_14 * 4 + 4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar8 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar8 = puVar8 + 1;
          }
          for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
            *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
            puVar8 = (undefined4 *)((int)puVar8 + 1);
          }
        }
        local_14 = local_14 + 1;
      } while (local_14 < *(uint *)(in_ECX + 0xc));
    }
    uVar5 = *(uint *)(in_ECX + 0xc);
    local_14 = 0;
    if (uVar5 != 0) {
      do {
        iVar2 = local_14 * 4;
        if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x18) + iVar2) + 0x2c) & 1) != 0) {
          uVar7 = local_14 + 1;
          if (uVar7 < uVar5) {
            piVar3 = (int *)(*(int *)(in_ECX + 0x18) + uVar7 * 4);
            do {
              if (*(int *)(*(int *)(*(int *)(in_ECX + 0x18) + iVar2) + 0x2c) !=
                  *(int *)(*piVar3 + 0x2c)) break;
              uVar7 = uVar7 + 1;
              piVar3 = piVar3 + 1;
            } while (uVar7 < *(uint *)(in_ECX + 0xc));
          }
          uVar5 = uVar7 - local_14 >> 1;
          if (uVar5 != 0) {
            iVar4 = uVar7 << 2;
            local_14 = iVar2;
            local_10 = uVar5;
            do {
              puVar6 = (undefined4 *)(local_14 + *(int *)(in_ECX + 0x18));
              uVar1 = *puVar6;
              *puVar6 = *(undefined4 *)(iVar4 + -4 + *(int *)(in_ECX + 0x18));
              *(undefined4 *)(iVar4 + -4 + *(int *)(in_ECX + 0x18)) = uVar1;
              iVar4 = iVar4 + -4;
              local_10 = local_10 - 1;
              local_14 = local_14 + 4;
            } while (local_10 != 0);
          }
          local_14 = uVar7 - 1;
        }
        uVar5 = *(uint *)(in_ECX + 0xc);
        local_14 = local_14 + 1;
      } while (local_14 < uVar5);
    }
  }
LAB_00927bca:
  FUN_009195d7(local_7c);
  _free(local_8);
  return extraout_EAX;
}


// ==== FUN_00927be4 @ 0x00927be4 ====

int FUN_00927be4(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  undefined4 uVar6;
  undefined1 local_80 [100];
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar4 = FUN_00918ee0(*(undefined4 *)(in_ECX + 0x88),3,0x20400);
  if (iVar4 < 0) {
    return iVar4;
  }
  iVar4 = FUN_00918ee0(*(undefined4 *)(in_ECX + 0x8c),6,0x401);
  if (iVar4 < 0) {
    return iVar4;
  }
  iVar4 = FUN_00918ee0(*(undefined4 *)(in_ECX + 0x90),10,0x4401);
  if (iVar4 < 0) {
    return iVar4;
  }
  uVar5 = *(uint *)(in_ECX + 200) & 0xffff0000;
  if (((uVar5 == 0x46580000) || (uVar5 == 0x54580000)) &&
     (iVar4 = FUN_00918ee0(*(undefined4 *)(in_ECX + 0x88),2,0x31028), iVar4 < 0)) {
    return iVar4;
  }
  if (((*(uint *)(in_ECX + 200) & 0xffff0000) != 0xfffe0000) &&
     (iVar4 = FUN_00918ee0(*(undefined4 *)(in_ECX + 0x80),0x10,0x200), iVar4 < 0)) {
    return iVar4;
  }
  iVar4 = FUN_00918ee0(*(undefined4 *)(in_ECX + 0x84),0x20,0x42000);
  if (iVar4 < 0) {
    return iVar4;
  }
  iVar4 = FUN_00918ee0(*(undefined4 *)(in_ECX + 0xb4),0x2020,0x40000);
  if (iVar4 < 0) {
    return iVar4;
  }
  iVar4 = FUN_00918ee0(*(undefined4 *)(in_ECX + 0xb8),0x40020,0x2000);
  if (iVar4 < 0) {
    return iVar4;
  }
  if (((*(uint *)(in_ECX + 200) & 0xffff0000) != 0xffff0000) &&
     (iVar4 = FUN_00918ee0(*(undefined4 *)(in_ECX + 0x94),0x80,0), iVar4 < 0)) {
    return iVar4;
  }
  if (*(int *)(in_ECX + 0x30) != 0) {
    iVar4 = FUN_00921938(local_80,*(undefined4 *)(in_ECX + 0x8c),*(int *)(in_ECX + 0x30));
    if (iVar4 < 0) {
      return iVar4;
    }
    iVar4 = FUN_00922003(local_80,0);
    if (iVar4 < 0) {
      iVar4 = FUN_00918ee0(*(undefined4 *)(in_ECX + 0x88),2,0x30028);
      if (iVar4 < 0) goto LAB_00927d67;
    }
    else {
      FUN_00922003(local_80,1);
    }
    iVar4 = FUN_009195d7(local_80);
    if (iVar4 < 0) {
      return iVar4;
    }
  }
  iVar4 = FUN_00921938(local_80,*(undefined4 *)(in_ECX + 0x88),*(undefined4 *)(in_ECX + 0x2c));
  if (((((-1 < iVar4) && (iVar4 = FUN_00922003(local_80,1), -1 < iVar4)) &&
       (iVar4 = FUN_009195d7(local_80), -1 < iVar4)) &&
      ((iVar4 = FUN_00921938(local_80,*(undefined4 *)(in_ECX + 0x90),*(undefined4 *)(in_ECX + 0x34))
       , -1 < iVar4 && (iVar4 = FUN_00922003(local_80,1), -1 < iVar4)))) &&
     (iVar4 = FUN_009195d7(local_80), -1 < iVar4)) {
    if ((*(byte *)(in_ECX + 0xcc) & 4) == 0) {
      local_14 = 0;
      FUN_00919e76();
      local_c = 0;
      if (*(int *)(in_ECX + 0xc) != 0) {
        do {
          puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_c * 4);
          if ((*puVar1 & 0xfff00000) == 0x10000000) {
            local_10 = 0;
            local_8 = 0;
            if (puVar1[3] != 0) {
              do {
                local_1c = local_8 * 4;
                local_18 = *(int *)(puVar1[4] + local_1c);
                iVar4 = *(int *)(local_1c + puVar1[2]);
                iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + local_18 * 4);
                iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4);
                if ((((*(int *)(iVar2 + 4) == *(int *)(iVar3 + 4)) &&
                     (*(int *)(iVar2 + 8) == *(int *)(iVar3 + 8))) &&
                    ((*(int *)(iVar2 + 0xc) == *(int *)(iVar3 + 0xc) &&
                     (((*(int *)(iVar2 + 0x10) == *(int *)(iVar3 + 0x10) &&
                       (*(int *)(iVar2 + 0x14) == *(int *)(iVar3 + 0x14))) &&
                      (*(int *)(iVar2 + 0x18) == *(int *)(iVar3 + 0x18))))))) &&
                   ((*(int *)(iVar2 + 0x3c) == 0 && (*(int *)(iVar3 + 0x3c) == 0)))) {
                  uVar6 = 0xffffffff;
                  if (iVar4 != -1) {
                    uVar6 = *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4) + 0x30);
                  }
                  *(undefined4 *)(iVar2 + 0x30) = uVar6;
                }
                else {
                  *(int *)(puVar1[4] + local_10 * 4) = local_18;
                  *(undefined4 *)(puVar1[2] + local_10 * 4) = *(undefined4 *)(puVar1[2] + local_1c);
                  local_10 = local_10 + 1;
                }
                local_8 = local_8 + 1;
              } while (local_8 < puVar1[3]);
            }
            if (local_10 != puVar1[3]) {
              *puVar1 = -(uint)(local_10 != 0) & (local_10 & 0xfffff | 0x10000000);
              puVar1[1] = local_10;
              puVar1[3] = local_10;
              local_14 = 1;
            }
          }
          local_c = local_c + 1;
        } while (local_c < *(uint *)(in_ECX + 0xc));
        if (local_14 != 0) {
          iVar4 = FUN_00919e8f();
          if (iVar4 < 0) {
            return iVar4;
          }
          iVar4 = FUN_0091c491();
          if (iVar4 < 0) {
            return iVar4;
          }
          iVar4 = FUN_00915e19();
          if (iVar4 < 0) {
            return iVar4;
          }
        }
      }
    }
    return 0;
  }
LAB_00927d67:
  FUN_009195d7(local_80);
  return iVar4;
}


// ==== FUN_00927f7e @ 0x00927f7e ====

int FUN_00927f7e(void)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int in_ECX;
  uint uVar13;
  uint local_8;
  
  iVar4 = FUN_0091a689();
  if ((((-1 < iVar4) && (iVar4 = FUN_0091ae30(), -1 < iVar4)) &&
      (iVar4 = FUN_009237bb(), -1 < iVar4)) &&
     ((iVar4 = FUN_00915e19(), -1 < iVar4 && (iVar4 = FUN_0091c491(), -1 < iVar4)))) {
    uVar13 = 0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar13 * 4);
        if ((*puVar1 & 0xfff00000) == 0x10200000) {
          *puVar1 = puVar1[3] & 0xfffff | 0x10000000;
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 < *(uint *)(in_ECX + 0xc));
    }
    if ((*(byte *)(in_ECX + 0xcc) & 4) == 0) {
      iVar4 = FUN_0091e5fd();
      if ((-1 < iVar4) && (iVar4 = FUN_0091ab4a(), -1 < iVar4)) {
        local_8 = 0;
        do {
          iVar4 = FUN_00922c12();
          if (iVar4 == 0) {
            iVar4 = 0;
          }
          else if (iVar4 < 0) {
            return iVar4;
          }
          iVar5 = FUN_0091ae30();
          if (iVar5 == 0) {
            iVar5 = 0;
          }
          else if (iVar5 < 0) {
            return iVar5;
          }
          iVar6 = FUN_00923987();
          if (iVar6 == 0) {
            iVar6 = 0;
          }
          else if (iVar6 < 0) {
            return iVar6;
          }
          iVar7 = FUN_00923e5f(0);
          if (iVar7 == 0) {
            iVar7 = 0;
          }
          else if (iVar7 < 0) {
            return iVar7;
          }
          iVar8 = FUN_0091b2e2();
          if (iVar8 == 0) {
            iVar8 = 0;
          }
          else if (iVar8 < 0) {
            return iVar8;
          }
          iVar9 = FUN_009240e6();
          if (iVar9 == 0) {
            iVar9 = 0;
          }
          else if (iVar9 < 0) {
            return iVar9;
          }
          iVar10 = FUN_0091b7b3();
          if (iVar10 == 0) {
            iVar10 = 0;
          }
          else if (iVar10 < 0) {
            return iVar10;
          }
          iVar11 = FUN_0091bab7();
          if (iVar11 == 0) {
            iVar11 = 0;
          }
          else if (iVar11 < 0) {
            return iVar11;
          }
          iVar12 = FUN_00925935();
          if (iVar12 == 0) {
            iVar12 = 0;
          }
          else if (iVar12 < 0) {
            return iVar12;
          }
        } while ((iVar12 == 0 ||
                  (((((((iVar4 == 0 || iVar5 == 0) || iVar6 == 0) || iVar7 == 0) || iVar8 == 0) ||
                    iVar9 == 0) || iVar10 == 0) || iVar11 == 0)) &&
                (local_8 = local_8 + 1, local_8 < 0x100));
        if (local_8 == 0x100) {
          FUN_0091a096();
        }
        uVar13 = 0;
        if (*(int *)(in_ECX + 8) != 0) {
          do {
            iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + uVar13 * 4);
            uVar2 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar4 + 4) * 4) + 4);
            if (((uVar2 & 0x100) != 0) && ((uVar2 & 0xc00) == 0)) {
              uVar3 = *(undefined4 *)(in_ECX + 0x78);
              *(undefined4 *)(iVar4 + 0xc) = 0xffffffff;
              *(undefined4 *)(iVar4 + 0x10) = 0xffffffff;
              *(undefined4 *)(iVar4 + 4) = uVar3;
            }
            uVar13 = uVar13 + 1;
          } while (uVar13 < *(uint *)(in_ECX + 8));
        }
        iVar4 = FUN_009226b6();
        if ((((-1 < iVar4) && (iVar4 = FUN_0091c1d9(), -1 < iVar4)) &&
            (iVar4 = FUN_009237bb(), -1 < iVar4)) &&
           ((iVar4 = FUN_00915e19(), -1 < iVar4 && (iVar4 = FUN_0091c491(), -1 < iVar4)))) {
          *(undefined4 *)(in_ECX + 0xd8) = 1;
          iVar4 = 0;
        }
      }
    }
    else {
      *(undefined4 *)(in_ECX + 0xd8) = 1;
      iVar4 = 0;
    }
  }
  return iVar4;
}


// ==== FUN_009281fc @ 0x009281fc ====

int FUN_009281fc(void)

{
  int iVar1;
  int *in_ECX;
  uint uVar2;
  
  iVar1 = FUN_0091e5fd();
  if (((-1 < iVar1) && (iVar1 = FUN_00925eeb(), -1 < iVar1)) &&
     (iVar1 = FUN_0091fe2b(1), -1 < iVar1)) {
    uVar2 = 0;
    do {
      iVar1 = FUN_00923e5f(1);
      if (iVar1 != 0) {
        if (iVar1 < 0) {
          return iVar1;
        }
        if (iVar1 == 1) break;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x100);
    iVar1 = FUN_0091e836();
    if (((-1 < iVar1) && (iVar1 = FUN_009265b2(), -1 < iVar1)) &&
       ((iVar1 = (**(code **)(*in_ECX + 0x10))(), -1 < iVar1 &&
        ((iVar1 = FUN_0091fe2b(0), -1 < iVar1 && (iVar1 = FUN_00927456(), -1 < iVar1)))))) {
      in_ECX[0x37] = 1;
      iVar1 = FUN_00920075();
      if ((-1 < iVar1) &&
         (((((iVar1 = FUN_009279b0(), -1 < iVar1 && (iVar1 = FUN_009184cd(), -1 < iVar1)) &&
            (iVar1 = (**(code **)(*in_ECX + 0x14))(), -1 < iVar1)) &&
           ((iVar1 = (**(code **)(*in_ECX + 0x18))(), -1 < iVar1 &&
            (iVar1 = FUN_00915e19(), -1 < iVar1)))) &&
          ((iVar1 = FUN_0091c491(), -1 < iVar1 &&
           ((iVar1 = FUN_00927be4(), -1 < iVar1 && (iVar1 = FUN_009203b1(), -1 < iVar1)))))))) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


// ==== FUN_00928307 @ 0x00928307 ====

int FUN_00928307(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xd8) = 0;
  *(undefined4 *)(in_ECX + 0xdc) = 0;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
  }
  iVar1 = FUN_00927f7e();
  if (-1 < iVar1) {
    iVar1 = FUN_009281fc();
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ==== FUN_00928344 @ 0x00928344 ====

void FUN_00928344(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_00948a8f();
  in_ECX[0x56] = param_1;
  *in_ECX = &PTR_FUN_00a29900;
  in_ECX[0x3c] = &PTR_s_Position_00b59a00;
  in_ECX[0x3d] = &PTR_s_Tessfactor_00b59c40;
  in_ECX[0x3e] = &PTR_s_Color_00b59ef0;
  return;
}


// ==== FUN_00928385 @ 0x00928385 ====

undefined4 FUN_00928385(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 200);
  *(int *)(in_ECX + 0x108) = iVar1;
  if (iVar1 == -0x1fd00) {
    *(uint *)(in_ECX + 0x6c) = *(uint *)(in_ECX + 0x6c) | 0x40200100;
    *(ushort *)(in_ECX + 0x70) = *(ushort *)(in_ECX + 0x70) | 0xfe4;
    *(undefined4 *)(in_ECX + 0x30) = 1;
    *(undefined4 *)(in_ECX + 0x4c) = 4;
  }
  else {
    if (iVar1 == -0x1fc01) {
      *(uint *)(in_ECX + 0x6c) = *(uint *)(in_ECX + 0x6c) | 0x40200100;
      *(ushort *)(in_ECX + 0x70) = *(ushort *)(in_ECX + 0x70) | 0xfe4;
      *(undefined4 *)(in_ECX + 0x30) = 1;
      *(undefined4 *)(in_ECX + 0x60) = 0x800;
      *(undefined4 *)(in_ECX + 0x40) = 0x800;
      *(undefined4 *)(in_ECX + 0x54) = 0x10;
      *(undefined4 *)(in_ECX + 0x5c) = 4;
      *(undefined4 *)(in_ECX + 0x4c) = 0x10;
      goto LAB_00928456;
    }
    if ((iVar1 != -0xfd00) && (iVar1 != -0xfc01)) {
      FUN_0091a001();
      return 0x80004005;
    }
    *(undefined4 *)(in_ECX + 0x30) = 0;
    *(uint *)(in_ECX + 0x6c) = *(uint *)(in_ECX + 0x6c) | 0x402001a0;
    *(ushort *)(in_ECX + 0x70) = *(ushort *)(in_ECX + 0x70) | 0x534;
    *(undefined4 *)(in_ECX + 0x48) = 4;
    *(undefined4 *)(in_ECX + 0x4c) = 0x10;
  }
  *(undefined4 *)(in_ECX + 0x60) = 0x10;
  *(undefined4 *)(in_ECX + 0x40) = 0x10;
  *(undefined4 *)(in_ECX + 0x54) = 8;
  *(undefined4 *)(in_ECX + 0x5c) = 4;
LAB_00928456:
  *(byte *)(in_ECX + 0x71) = *(byte *)(in_ECX + 0x71) | 0x10;
  *(undefined4 *)(in_ECX + 0x28) = 0x10;
  *(undefined4 *)(in_ECX + 0x44) = 0x10;
  *(undefined4 *)(in_ECX + 0x2c) = 0x20;
  *(undefined4 *)(in_ECX + 0x38) = 0x2000;
  *(undefined4 *)(in_ECX + 0x68) = 0xff;
  *(undefined4 *)(in_ECX + 100) = 1;
  *(undefined4 *)(in_ECX + 0x58) = 0x18;
  *(undefined4 *)(in_ECX + 0x1d0) = 0x20;
  *(undefined4 *)(in_ECX + 0x154) = 1;
  return 0;
}


// ==== FUN_0092848c @ 0x0092848c ====

uint FUN_0092848c(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *in_ECX;
  int iVar5;
  int local_64 [16];
  int local_24 [8];
  
  if (in_ECX[0x56] != 0) {
    return 0;
  }
  local_24[7] = 0;
  local_24[6] = 0;
  local_24[4] = 0;
  if ((*(byte *)(in_ECX + 0x1c) & 0x40) == 0) {
    piVar4 = local_64;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar4 = 0;
      piVar4 = piVar4 + 1;
    }
    local_24[0] = 0;
    local_24[1] = 0;
    local_24[2] = 0;
    local_24[3] = 0;
    if (in_ECX[2] != 0) {
      do {
        iVar5 = *(int *)(in_ECX[5] + local_24[6] * 4);
        if ((*(byte *)(*(int *)(in_ECX[4] + *(int *)(iVar5 + 4) * 4) + 4) & 0x20) != 0) {
          local_24[5] = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(iVar5 + 0x6c));
          uVar3 = (**(code **)(*in_ECX + 0x58))(*(undefined4 *)(iVar5 + 0x6c));
          if (local_24[5] == 0xb) {
            if (uVar3 < 4) {
              local_64[*(int *)(iVar5 + 0x10) + uVar3 * 4] = 1;
              local_24[uVar3] = *(int *)(iVar5 + 0x60);
            }
          }
          else if ((((local_24[5] == 0xd) && (uVar3 == 0)) && (*(int *)(iVar5 + 0x10) != 0)) &&
                  (local_24[4] == 0)) {
            FUN_0091a001();
            local_24[4] = 1;
            local_24[7] = 1;
          }
        }
        local_24[6] = local_24[6] + 1;
      } while ((uint)local_24[6] < (uint)in_ECX[2]);
    }
    local_24[4] = 0;
    local_24[5] = 1;
    uVar3 = 0;
    do {
      iVar1 = 0;
      piVar4 = local_64 + uVar3 * 4;
      iVar5 = 4;
      do {
        iVar2 = *piVar4;
        piVar4 = piVar4 + 1;
        iVar1 = iVar1 + (uint)(iVar2 != 0);
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      if (iVar1 == 0) {
        if (uVar3 == 0) {
          FUN_0091a001();
          local_24[7] = 1;
        }
        local_24[4] = 1;
      }
      else {
        if (iVar1 != 4) {
          FUN_0091a001();
          local_24[7] = 1;
        }
        if (local_24[4] != 0) {
          local_24[5] = 0;
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 4);
    if (local_24[5] != 0) goto LAB_009286ae;
  }
  else {
    local_24[0] = 0;
    local_24[1] = 0;
    local_24[2] = 0;
    local_24[5] = 0;
    local_24[3] = 0;
    if (in_ECX[2] != 0) {
      do {
        iVar5 = *(int *)(in_ECX[5] + local_24[6] * 4);
        if ((*(byte *)(*(int *)(in_ECX[4] + *(int *)(iVar5 + 4) * 4) + 4) & 0x20) != 0) {
          iVar1 = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(iVar5 + 0x6c));
          iVar2 = (**(code **)(*in_ECX + 0x58))(*(undefined4 *)(iVar5 + 0x6c));
          if (iVar1 == 1) {
            if (iVar2 == 0) {
              local_24[*(int *)(iVar5 + 0x10)] = 1;
              local_24[4] = *(int *)(iVar5 + 0x60);
            }
          }
          else if (((iVar1 == 5) && (iVar2 == 0)) &&
                  ((*(int *)(iVar5 + 0x10) != 0 && (local_24[5] == 0)))) {
            FUN_0091a001();
            local_24[5] = 1;
            local_24[7] = 1;
          }
        }
        local_24[6] = local_24[6] + 1;
      } while ((uint)local_24[6] < (uint)in_ECX[2]);
    }
    iVar5 = 0;
    uVar3 = 0;
    do {
      if (local_24[uVar3] != 0) {
        iVar5 = iVar5 + 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 4);
    if (iVar5 == 4) goto LAB_009286ae;
  }
  FUN_0091a001();
  local_24[7] = 1;
LAB_009286ae:
  return -(uint)(local_24[7] != 0) & 0x80004005;
}


// ==== FUN_009286ef @ 0x009286ef ====

undefined4 FUN_009286ef(int param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(param_1 + 0x6c));
  uVar2 = (**(code **)(*in_ECX + 0x58))(*(undefined4 *)(param_1 + 0x6c));
  *param_2 = uVar2;
  if ((*(byte *)(in_ECX + 0x1c) & 0x40) == 0) {
    uVar3 = 0;
    if (iVar1 == 0xb) {
      if (3 < uVar2) {
        return 0x80004005;
      }
      *param_3 = 8;
    }
    else if (iVar1 == 0xd) {
      if (uVar2 != 0) {
        return 0x80004005;
      }
      uVar3 = 1;
      *param_3 = 9;
    }
    else if (iVar1 == 0x11) {
      if (uVar2 != 0) {
        return 0x80004005;
      }
      *param_3 = 0x11;
      *param_2 = 1;
    }
    else if (iVar1 == 0x12) {
      if (uVar2 != 0) {
        return 0x80004005;
      }
      *param_3 = 0x11;
      *param_2 = 0;
    }
    else {
      if (iVar1 != 0xffff) {
        return 0x80004005;
      }
      *param_3 = 0;
      uVar3 = 0;
    }
    if (param_4 == (undefined4 *)0x0) {
      return 0;
    }
    *param_4 = uVar3;
    return 0;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (iVar1 == 5) {
    if ((*param_2 != 0) || (param_4 == (undefined4 *)0x0)) goto LAB_0092874b;
    *param_4 = 1;
  }
  if (iVar1 == 0xffff) {
    *param_3 = 0;
    return 0;
  }
LAB_0092874b:
  *param_3 = 6;
  *param_2 = *(uint *)(param_1 + 0xc);
  return 0;
}


// ==== FUN_009287dd @ 0x009287dd ====

undefined4 FUN_009287dd(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(param_1 + 0x6c));
  if (iVar1 == 0xffff) {
    *param_3 = 0;
    uVar2 = (**(code **)(*in_ECX + 0x58))(*(undefined4 *)(param_1 + 0x6c));
  }
  else {
    if (iVar1 == 0x11) {
      *param_3 = 0x11;
      *param_2 = 1;
      return 0;
    }
    if (iVar1 == 0x12) {
      *param_3 = 0x11;
      *param_2 = 0;
      return 0;
    }
    *param_3 = 1;
    uVar2 = *(undefined4 *)(param_1 + 0xc);
  }
  *param_2 = uVar2;
  return 0;
}


// ==== FUN_00928849 @ 0x00928849 ====

void FUN_00928849(void)

{
  FUN_0094c8d4();
  return;
}


// ==== FUN_00928854 @ 0x00928854 ====

undefined4 FUN_00928854(void)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int in_ECX;
  uint uVar8;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_c = 0xffffffff;
  local_10 = 0xffffffff;
  local_14 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar6 = local_14 * 4;
      iVar7 = *(int *)(iVar6 + *(int *)(in_ECX + 0x14));
      if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4) + 4) & 0x10) != 0)
         && (((iVar7 = *(int *)(iVar7 + 0x6c), iVar7 == 0x11 || (iVar7 == 0x12)) &&
             (puVar2 = *(uint **)(iVar6 + *(int *)(in_ECX + 0x14)), *puVar2 = *puVar2 & 0x40000000,
             **(int **)(iVar6 + *(int *)(in_ECX + 0x14)) == 0)))) {
        iVar7 = *(int *)(iVar6 + *(int *)(in_ECX + 0x14));
        iVar3 = *(int *)(iVar7 + 0x6c);
        if (iVar3 == 0x11) {
          if (local_c != 0xffffffff) goto LAB_0092894a;
          local_c = local_14;
        }
        if (iVar3 == 0x12) {
          if (local_10 == 0xffffffff) {
            local_10 = local_14;
            goto LAB_009288f4;
          }
          iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + iVar6);
          local_8 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + local_10 * 4) + 0xc);
LAB_00928947:
          *(uint *)(iVar7 + 0xc) = local_8;
        }
        else {
LAB_009288f4:
          uVar4 = *(uint *)(iVar7 + 0xc);
          local_8 = 0xffffffff;
          uVar8 = 0;
          if (*(int *)(in_ECX + 8) != 0) {
            do {
              iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + uVar8 * 4);
              if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4) + 4) &
                   0x10) != 0) && (uVar5 = *(uint *)(iVar7 + 0xc), uVar4 < uVar5)) {
                if ((int)local_8 <= (int)uVar5) {
                  local_8 = uVar5;
                }
                piVar1 = (int *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar8 * 4) + 0xc);
                *piVar1 = *piVar1 + -1;
              }
              uVar8 = uVar8 + 1;
            } while (uVar8 < *(uint *)(in_ECX + 8));
            if (local_8 != 0xffffffff) {
              iVar7 = *(int *)(iVar6 + *(int *)(in_ECX + 0x14));
              goto LAB_00928947;
            }
          }
        }
      }
LAB_0092894a:
      local_14 = local_14 + 1;
    } while (local_14 < *(uint *)(in_ECX + 8));
  }
  return 0;
}


// ==== FUN_00928961 @ 0x00928961 ====

int FUN_00928961(void)

{
  uint *puVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  int *in_ECX;
  uint uVar5;
  uint local_c;
  
  if (in_ECX[0x17] != 0) {
    bVar3 = false;
    in_ECX[0x3f] = 0;
    if (in_ECX[3] != 0) {
      do {
        puVar1 = *(uint **)(in_ECX[6] + in_ECX[0x3f] * 4);
        in_ECX[0x40] = (int)puVar1;
        if ((*puVar1 & 0xfff00000) == 0x20800000) {
          iVar4 = FUN_0093e78d();
          if (iVar4 < 0) {
            return iVar4;
          }
          bVar3 = (bool)(bVar3 | iVar4 == 0);
        }
        in_ECX[0x3f] = in_ECX[0x3f] + 1;
      } while ((uint)in_ECX[0x3f] < (uint)in_ECX[3]);
      if (bVar3) {
        FUN_0093e2c8();
      }
    }
  }
  if (in_ECX[0xc] != 0) {
    local_c = 0;
    do {
      if (0xf < local_c) goto LAB_00928a5d;
      uVar2 = in_ECX[3];
      uVar5 = 0;
      bVar3 = true;
      if (uVar2 != 0) {
        do {
          in_ECX[0x40] = *(int *)(in_ECX[6] + uVar5 * 4);
          iVar4 = FUN_0093ec43();
          if (iVar4 < 0) {
            return iVar4;
          }
          if (iVar4 == 0) {
            bVar3 = false;
          }
          iVar4 = FUN_00915471(in_ECX[0x40]);
          if (iVar4 < 0) {
            return iVar4;
          }
          *(undefined4 *)in_ECX[0x40] = 0;
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar2);
      }
      iVar4 = FUN_00915e19();
      if (iVar4 < 0) {
        return iVar4;
      }
      local_c = local_c + 1;
    } while (!bVar3);
    if (0xf < local_c) {
LAB_00928a5d:
      uVar2 = in_ECX[3];
      uVar5 = 0;
      bVar3 = true;
      if (uVar2 != 0) {
        do {
          in_ECX[0x40] = *(int *)(in_ECX[6] + uVar5 * 4);
          iVar4 = FUN_0093ec43();
          if (iVar4 < 0) {
            return iVar4;
          }
          if (iVar4 == 0) {
            FUN_0091a001();
            bVar3 = false;
          }
          iVar4 = FUN_00915471(in_ECX[0x40]);
          if (iVar4 < 0) {
            return iVar4;
          }
          *(undefined4 *)in_ECX[0x40] = 0;
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar2);
      }
      iVar4 = FUN_00915e19();
      if (iVar4 < 0) {
        return iVar4;
      }
      if (!bVar3) {
        return -0x7fffbffb;
      }
    }
  }
  if (((*(byte *)(in_ECX + 0x1c) & 0x40) == 0) &&
     (iVar4 = (**(code **)(*in_ECX + 0x98))(), iVar4 < 0)) {
    return iVar4;
  }
  if (in_ECX[0x18] != 0) {
    iVar4 = FUN_0094b1b7();
    if (iVar4 < 0) {
      return iVar4;
    }
    FUN_0093e2c8();
    iVar4 = FUN_0091c491();
    if (iVar4 < 0) {
      return iVar4;
    }
    iVar4 = FUN_0094679d();
    if (iVar4 < 0) {
      return iVar4;
    }
  }
  return 0;
}


// ==== FUN_00928b2b @ 0x00928b2b ====

undefined4 FUN_00928b2b(void)

{
  uint *puVar1;
  int in_ECX;
  
  puVar1 = (uint *)(*(int *)(in_ECX + 0x10c) + *(int *)(in_ECX + 0x118) * 4);
  *puVar1 = *puVar1 | ((*(int *)(in_ECX + 0x110) - *(int *)(in_ECX + 0x118)) + -1) * 0x1000000;
  return 0;
}


// ==== FUN_00928b4b @ 0x00928b4b ====

int FUN_00928b4b(int param_1)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  
  if (in_ECX[0x56] == 0) {
    iVar1 = FUN_0094d495(0x200001f);
    if (-1 < iVar1) {
      iVar1 = *(int *)(param_1 + 0x3c);
      if (iVar1 == 0x200000) {
        uVar2 = 0x90000000;
      }
      else if (iVar1 == 0x400000) {
        uVar2 = 0xa0000000;
      }
      else {
        if (iVar1 != 0x800000) {
          FUN_0091a001();
          return -0x7fffbffb;
        }
        uVar2 = 0x98000000;
      }
      iVar1 = FUN_0094b4db(uVar2);
      if (((-1 < iVar1) &&
          (iVar1 = (**(code **)(*in_ECX + 100))
                             (*(uint *)(param_1 + 0xc) & 0x7ff | 0xa0000800,0xf0000,0), -1 < iVar1))
         && (iVar1 = FUN_00948616(), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_00928c02 @ 0x00928c02 ====

int FUN_00928c02(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x158) == 0) {
    uVar1 = *(uint *)(in_ECX + 200);
  }
  else {
    uVar1 = *(uint *)(in_ECX + 200) & 0x7fffffff;
  }
  iVar2 = FUN_0094b4db(uVar1);
  if (-1 < iVar2) {
    iVar2 = FUN_00948616();
    if (-1 < iVar2) {
      iVar2 = 0;
    }
  }
  return iVar2;
}


// ==== FUN_00928c3c @ 0x00928c3c ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_00928c3c(int param_1,uint *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  int extraout_EAX;
  int *in_ECX;
  int *piVar7;
  uint uVar8;
  char *pcVar9;
  undefined4 uVar10;
  uint local_5c [7];
  uint *local_40;
  uint local_3c;
  uint local_38;
  char *local_34;
  uint local_30;
  uint local_2c;
  char local_28 [31];
  undefined1 local_9;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  local_40 = param_2;
  local_2c = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(param_1 + 0x6c));
  uVar3 = (**(code **)(*in_ECX + 0x58))(*(undefined4 *)(param_1 + 0x6c));
  if (in_ECX[0x56] != 0) {
    if (*(int *)(param_1 + 0x6c) == -1) {
      return 0;
    }
    if (local_2c != 0xffff) {
      if ((*(byte *)(*(int *)(in_ECX[4] + *(int *)(param_1 + 4) * 4) + 4) & 0x10) == 0) {
        puVar4 = (undefined4 *)FUN_0094c864(local_2c);
        uVar10 = *puVar4;
        pcVar9 = s_o__s_d_00a29b58;
      }
      else {
        puVar4 = (undefined4 *)FUN_0094c864(local_2c);
        uVar10 = *puVar4;
        pcVar9 = s_v__s_d_00a29b60;
      }
      __snprintf(local_28,0x20,pcVar9,uVar10,uVar3);
      local_9 = 0;
      iVar5 = FUN_00907c5b(local_28,*(undefined4 *)(param_1 + 0xc),1);
      if (iVar5 < 0) {
        return iVar5;
      }
      in_ECX[0x7c] = in_ECX[0x7c] + 1;
      if (((((*(byte *)(in_ECX + 0x33) & 1) != 0) && (iVar5 = *(int *)(param_1 + 0x60), iVar5 != 0))
          && (*(int *)(iVar5 + 4) == 6)) &&
         (iVar5 = *(int *)(iVar5 + 0x14), *(int *)(iVar5 + 4) == 3)) {
        pcVar6 = *(char **)(iVar5 + 0x18);
        pcVar9 = pcVar6 + 1;
        do {
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        local_34 = operator_new((uint)(pcVar6 + (3 - (int)pcVar9)));
        if (local_34 == (char *)0x0) {
          return -0x7ff8fff2;
        }
        _sprintf(local_34,&DAT_00a29b50,*(undefined4 *)(iVar5 + 0x18));
        FUN_00907c5b(local_34,*(undefined4 *)(param_1 + 0xc),1);
        _free(local_34);
        return extraout_EAX;
      }
    }
    if (local_40 == (uint *)0x0) {
      return 0;
    }
    *local_40 = *(uint *)(param_1 + 0x6c);
    return 0;
  }
  local_38 = 0;
  switch(local_2c) {
  case 0:
    return 1;
  case 1:
    local_2c = 0;
    break;
  case 2:
    local_2c = 1;
    break;
  case 3:
    local_2c = 2;
    break;
  case 4:
    local_2c = 3;
    break;
  case 5:
    local_2c = 4;
    break;
  case 6:
    local_2c = 5;
    break;
  case 7:
    local_2c = 6;
    break;
  case 8:
    local_2c = 7;
    break;
  case 9:
    local_2c = 8;
    if (uVar3 != 0) {
      return -0x7fffbffb;
    }
    goto LAB_00928dbe;
  case 10:
    local_2c = 9;
    break;
  case 0xb:
    local_2c = 10;
    break;
  case 0xc:
    local_2c = 0xb;
    break;
  case 0xd:
    local_2c = 0xc;
    break;
  case 0xe:
    local_2c = 0xd;
    break;
  default:
    goto LAB_00928ea1;
  case 0x11:
    local_2c = 0x80000000;
    local_38 = 1;
    break;
  case 0x12:
    local_2c = 0x80000000;
  }
  if (0xf < uVar3) {
LAB_00928ea1:
    return -0x7fffbffb;
  }
LAB_00928dbe:
  local_2c = local_2c | (uVar3 | 0xffff8000) << 0x10;
  local_5c[5] = 0;
  if ((*(byte *)(param_1 + 3) & 1) != 0) {
    local_5c[5] = 0x400000;
  }
  iVar5 = FUN_0094d495(0x1f);
  if (iVar5 < 0) {
    return iVar5;
  }
  iVar5 = FUN_0094b4db(local_2c);
  if (iVar5 < 0) {
    return iVar5;
  }
  if ((*(byte *)(*(int *)(in_ECX[4] + *(int *)(param_1 + 4) * 4) + 4) & 0x10) == 0) {
    iVar5 = (**(code **)(*in_ECX + 0x84))(param_1,&local_3c,local_5c + 6,&local_38);
    if (iVar5 < 0) {
      return iVar5;
    }
    local_38 = 0;
  }
  else {
    local_38 = local_38 | (in_ECX[0x1c] << 0x19) >> 0x1f;
    iVar5 = (**(code **)(*in_ECX + 0x88))(param_1,&local_3c,local_5c + 6);
    if (iVar5 < 0) {
      return iVar5;
    }
  }
  local_5c[4] = 0;
  local_34 = (char *)0x0;
  local_5c[0] = 0xffffffff;
  local_5c[1] = 0xffffffff;
  local_5c[2] = 0xffffffff;
  local_5c[3] = 0xffffffff;
  if (in_ECX[2] != 0) {
    iVar5 = *(int *)(param_1 + 4);
    piVar7 = (int *)in_ECX[5];
    do {
      iVar2 = *piVar7;
      if (((iVar5 == *(int *)(iVar2 + 4)) && (*(int *)(param_1 + 8) == *(int *)(iVar2 + 8))) &&
         (*(int *)(param_1 + 0xc) == *(int *)(iVar2 + 0xc))) {
        local_5c[*(int *)(iVar2 + 0x10)] = (uint)local_34;
      }
      local_34 = (char *)((int)local_34 + 1);
      piVar7 = piVar7 + 1;
    } while (local_34 < (uint)in_ECX[2]);
  }
  uVar8 = 0;
  uVar3 = local_5c[4];
  do {
    if (local_5c[uVar8] != 0xffffffff) {
      local_5c[uVar3] = local_5c[uVar8];
      uVar3 = uVar3 + 1;
    }
    uVar8 = uVar8 + 1;
  } while (uVar8 < 4);
  iVar5 = (**(code **)(*in_ECX + 0x70))(local_5c,uVar3,&local_30,local_38);
  if (iVar5 < 0) {
    return iVar5;
  }
  uVar8 = (**(code **)(*in_ECX + 0x50))(4,0);
  uVar3 = local_2c;
  if ((local_2c & 0x7fffffff) == uVar8) {
    local_30 = local_30 | 0xf0000;
  }
  local_30 = local_30 & 0xffefffff;
  if (((*(byte *)(in_ECX + 0x1c) & 0x40) == 0) &&
     (((*(byte *)(in_ECX + 0x33) & 0x20) != 0 || ((*(byte *)(param_1 + 3) & 2) != 0)))) {
    local_30 = local_30 | 0x200000;
  }
  iVar5 = (**(code **)(*in_ECX + 100))
                    (((local_5c[6] | 0xfffffff8) << 0x14 | local_5c[6] & 0x18) << 8 |
                     local_3c & 0x7ff | local_5c[5],local_30,0);
  if (iVar5 < 0) {
    return iVar5;
  }
  iVar5 = (**(code **)(*in_ECX + 0x60))();
  if (iVar5 < 0) {
    return iVar5;
  }
  iVar5 = FUN_00948616();
  if (iVar5 < 0) {
    return iVar5;
  }
  if (local_40 != (uint *)0x0) {
    *local_40 = uVar3;
  }
  return 0;
}


// ==== FUN_009290a1 @ 0x009290a1 ====

int FUN_009290a1(int param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(in_ECX[5] + param_1 * 4);
  if ((in_ECX[0x32] & 0xffffU) < 0x101) {
    FUN_0091a001();
    iVar2 = -0x7fffbfff;
  }
  else {
    iVar2 = *(int *)(iVar1 + 8);
    if ((iVar2 == -1) || (iVar2 = FUN_009290a1(iVar2), -1 < iVar2)) {
      if (in_ECX[0x4e] == param_1) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_0094d495(1);
        if ((((-1 < iVar2) &&
             (iVar2 = (**(code **)(*in_ECX + 100))(0xb0000000,0x10000,0), -1 < iVar2)) &&
            (iVar2 = (**(code **)(*in_ECX + 0x74))(iVar1,&local_10,&local_8), -1 < iVar2)) &&
           (((iVar2 = (**(code **)(*in_ECX + 0x78))(&param_1,1,0x10000,&local_c), -1 < iVar2 &&
             (iVar2 = (**(code **)(*in_ECX + 0x68))(local_10,local_c,local_8), -1 < iVar2)) &&
            ((iVar2 = (**(code **)(*in_ECX + 0x60))(), -1 < iVar2 &&
             (iVar2 = FUN_00948616(), -1 < iVar2)))))) {
          in_ECX[0x4e] = param_1;
          iVar2 = 0;
        }
      }
    }
  }
  return iVar2;
}


// ==== FUN_009291a4 @ 0x009291a4 ====

int FUN_009291a4(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  
  iVar2 = FUN_0094d59b(param_1 | param_2);
  if (-1 < iVar2) {
    if ((((param_1 | param_2) & 0x2000) != 0) && (0x1ff < (*(uint *)(in_ECX + 200) & 0xffff))) {
      if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                             *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_3 * 4) + 4) * 4) + 4)
          & 0x10) == 0) {
        iVar2 = *(int *)(param_3 * 4 + *(int *)(in_ECX + 0x14));
        iVar1 = *(int *)(iVar2 + 0x10);
        uVar4 = *(uint *)(iVar2 + 0xc) & 0x7ff;
        uVar3 = uVar4 | 0xb0000000;
        if (iVar1 != 0) {
          if (iVar1 == 1) {
            uVar3 = uVar4 | 0xb0550000;
          }
          else if (iVar1 == 2) {
            uVar3 = uVar4 | 0xb0aa0000;
          }
          else if (iVar1 == 3) {
            uVar3 = uVar4 | 0xb0ff0000;
          }
        }
      }
      else {
        uVar3 = 0xf0e40800;
      }
      FUN_0094d59b(uVar3);
    }
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_00929240 @ 0x00929240 ====

undefined4 FUN_00929240(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(*(int *)(in_ECX[5] + *param_1 * 4) + 0x6c));
  if (iVar1 == 0x11) {
    *param_4 = 0xe40000;
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00948251(param_1,param_2,param_3,param_4);
  }
  return uVar2;
}


// ==== FUN_00929287 @ 0x00929287 ====

int FUN_00929287(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_00947af9(param_1,param_2,param_3,param_4);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(param_1 + 0x6c));
    if (iVar1 == 0x11) {
      *param_4 = 1;
    }
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_009292c6 @ 0x009292c6 ====

undefined4 FUN_009292c6(int *param_1,uint param_2,uint *param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint local_8;
  
  uVar4 = 0;
  local_8 = 0;
  if (param_4 == 0) {
    if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x14) + *param_1 * 4) + 0x3d) & 2) != 0) {
      local_8 = 0x100000;
    }
    if (param_2 != 0) {
      do {
        iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_1[uVar4] * 4) + 0x10);
        uVar3 = 0;
        if (iVar2 == 0) {
          uVar3 = 0x10000;
        }
        else if (iVar2 == 1) {
          uVar3 = 0x20000;
        }
        else if (iVar2 == 2) {
          uVar3 = 0x40000;
        }
        else if (iVar2 == 3) {
          uVar3 = 0x80000;
        }
        if ((local_8 & uVar3) != 0) {
          FUN_0091a001();
        }
        local_8 = local_8 | uVar3;
        uVar4 = uVar4 + 1;
      } while (uVar4 < param_2);
    }
  }
  else {
    local_8 = 0xf0000;
  }
  if ((*(byte *)(in_ECX + 0x70) & 0x40) == 0) {
    if ((*(byte *)(in_ECX + 0xcc) & 0x20) == 0) {
      uVar4 = 0;
      bVar5 = param_2 == 0;
      if (param_2 != 0) {
        do {
          iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + param_1[uVar4] * 4);
          if (((*(byte *)(iVar2 + 3) & 2) == 0) &&
             ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar2 + 4) * 4) + 4) & 1) ==
                0 || (*(int *)(iVar2 + 0x48) == -1)) || (*(int *)(iVar2 + 0x54) != -1)))) break;
          uVar4 = uVar4 + 1;
        } while (uVar4 < param_2);
        bVar5 = uVar4 == param_2;
      }
      if (!bVar5) goto LAB_009293ba;
    }
    local_8 = local_8 | 0x200000;
  }
LAB_009293ba:
  if ((((*(byte *)(in_ECX + 0xcc) & 1) != 0) && (uVar4 = 0, *(int *)(in_ECX + 0x124) != 0)) &&
     (param_2 != 0)) {
    do {
      piVar1 = param_1 + uVar4;
      iVar2 = uVar4 + *(int *)(in_ECX + 0x128) * 6;
      uVar4 = uVar4 + 1;
      *(int *)(*(int *)(in_ECX + 0x124) + -0x10 + iVar2 * 4) = *piVar1;
    } while (uVar4 < param_2);
  }
  *param_3 = local_8;
  return 0;
}


// ==== FUN_00929405 @ 0x00929405 ====

void FUN_00929405(int param_1,char *param_2,size_t param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  if ((*(int *)(param_1 + 4) == in_ECX[0x20]) || (*(int *)(param_1 + 4) == in_ECX[0x21])) {
    uVar1 = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(param_1 + 0x6c));
    puVar2 = (undefined4 *)FUN_00948a71(&PTR_s_Tessfactor_00b59c40,uVar1);
    if (puVar2[4] != -1) {
      uVar1 = (**(code **)(*in_ECX + 0x58))(*(undefined4 *)(param_1 + 0x6c));
      __snprintf(param_2,param_3,s__s_s_u_00a1fdfc,
                 **(undefined4 **)(in_ECX[4] + *(int *)(param_1 + 4) * 4),*puVar2,uVar1);
      param_2[param_3 - 1] = '\0';
      return;
    }
  }
  FUN_00919f6f(param_1,param_2,param_3);
  return;
}


// ==== FUN_0092948d @ 0x0092948d ====

undefined4 FUN_0092948d(uint *param_1,int param_2)

{
  int in_ECX;
  uint uVar1;
  bool bVar2;
  
  uVar1 = *param_1 & 0xfff00000;
  if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                       *(int *)(param_1[2] + (*param_1 & 0xfffff) * param_2 * 4) * 4) + 0x6c) ==
      0x11) {
    if (uVar1 == 0x30000000) {
      if (param_2 == 0) {
        return 1;
      }
      return 0;
    }
    if (uVar1 < 0x73800001) {
      if (uVar1 == 0x73800000) {
        return 1;
      }
      if (uVar1 == 0x10f00000) {
        return 1;
      }
      if (uVar1 == 0x73500000) {
        return 1;
      }
      if (uVar1 == 0x73600000) {
        return 1;
      }
      bVar2 = uVar1 == 0x73700000;
    }
    else {
      if (uVar1 == 0x74400000) {
        return 1;
      }
      if (uVar1 == 0x74500000) {
        return 1;
      }
      if (uVar1 == 0x74600000) {
        return 1;
      }
      bVar2 = uVar1 == 0x74700000;
    }
    if (bVar2) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00929520 @ 0x00929520 ====

void FUN_00929520(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a29900;
  FUN_00948b75();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00929547 @ 0x00929547 ====

void FUN_00929547(void)

{
  int iVar1;
  
  iVar1 = FUN_0093d907();
  if (iVar1 < 0) {
    return;
  }
  FUN_00928854();
  return;
}


// ==== FUN_0092955f @ 0x0092955f ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0092955f(void)

{
  uint *puVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int *in_ECX;
  int *piVar8;
  int iVar9;
  int iVar10;
  undefined4 local_24;
  uint local_18;
  uint local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  iVar9 = -1;
  local_18 = 0;
  if (in_ECX[3] != 0) {
    do {
      in_ECX[0x3f] = local_18;
      puVar1 = *(uint **)(in_ECX[6] + local_18 * 4);
      in_ECX[0x40] = (int)puVar1;
      if ((*puVar1 & 0xfff00000) != 0) {
        uVar4 = puVar1[1] / (*puVar1 & 0xfffff);
        local_8 = 0;
        if (uVar4 != 0) {
          do {
            uVar5 = FUN_009145b2(local_8,&local_c);
            local_10 = 0;
            if (uVar5 != 0) {
              do {
                iVar10 = local_10 * 4;
                uVar2 = *(uint *)(*(int *)(in_ECX[4] +
                                          *(int *)(*(int *)(in_ECX[5] +
                                                           *(int *)(iVar10 + local_c) * 4) + 4) * 4)
                                 + 4);
                if (((((uVar2 & 0x10) == 0) || ((uVar2 & 0x200) != 0)) ||
                    (iVar6 = (**(code **)(*in_ECX + 0x54))(), iVar6 != 0x11)) ||
                   ((local_8 == 0 && ((*(uint *)in_ECX[0x40] & 0xfff00000) == 0x30000000)))) break;
                if (iVar9 == -1) {
                  local_14 = 0;
                  if (in_ECX[2] != 0) {
                    piVar8 = (int *)in_ECX[5];
                    iVar9 = in_ECX[2];
                    do {
                      if ((in_ECX[0x22] == *(int *)(*piVar8 + 4)) &&
                         (uVar2 = *(uint *)(*piVar8 + 0xc), local_14 <= uVar2)) {
                        local_14 = uVar2 + 1;
                      }
                      piVar8 = piVar8 + 1;
                      iVar9 = iVar9 + -1;
                    } while (iVar9 != 0);
                  }
                  iVar9 = FUN_00915318(in_ECX[0x22],local_14,0,0);
                  if (iVar9 == -1) {
                    return 0x8007000e;
                  }
                  FUN_00914f00();
                  *(undefined4 *)(*(int *)(in_ECX[5] + iVar9 * 4) + 0x6c) = 0xffffffff;
                  local_24 = *(undefined4 *)(iVar10 + local_c);
                }
                local_10 = local_10 + 1;
                *(int *)(iVar10 + local_c) = iVar9;
              } while (local_10 < uVar5);
            }
            local_8 = local_8 + 1;
          } while (local_8 < uVar4);
        }
      }
      local_18 = local_18 + 1;
    } while (local_18 < (uint)in_ECX[3]);
    if (iVar9 != -1) {
      iVar10 = FUN_00915378(0x30000001,3,1);
      if (iVar10 != -1) {
        iVar10 = *(int *)(in_ECX[6] + iVar10 * 4);
        FUN_00914593();
        **(int **)(iVar10 + 0x10) = iVar9;
        **(undefined4 **)(iVar10 + 8) = local_24;
        uVar7 = FUN_00915318(in_ECX[0x1e],0,0,0x3ff0000000000000);
        uVar3 = _DAT_009fd350;
        *(undefined4 *)(*(int *)(iVar10 + 8) + 4) = uVar7;
        uVar7 = FUN_00915318(in_ECX[0x1e],0,0,uVar3);
        *(undefined4 *)(*(int *)(iVar10 + 8) + 8) = uVar7;
        if ((*(int *)(*(int *)(iVar10 + 8) + 4) != -1) && (*(int *)(*(int *)(iVar10 + 8) + 8) != -1)
           ) {
          uVar4 = in_ECX[3];
          while (1 < uVar4) {
            uVar4 = uVar4 - 1;
            piVar8 = (int *)in_ECX[6] + uVar4;
            *piVar8 = piVar8[-1];
          }
          *(int *)in_ECX[6] = iVar10;
          return 0;
        }
      }
      return 0x8007000e;
    }
  }
  return 0;
}


// ==== FUN_009297a7 @ 0x009297a7 ====

undefined4 FUN_009297a7(uint *param_1,uint *param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *in_ECX;
  int *piVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  uint auStack_ac [18];
  uint auStack_64 [18];
  uint local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  if (param_1 == (uint *)0x0) {
    uVar3 = 1;
  }
  else {
    uVar7 = *param_1 & 0xfff00000;
    if ((uVar7 != 0) && (uVar7 != 0x20700000)) {
      local_14 = *param_1 & 0xfffff;
      local_c = param_1[1] / local_14;
      if ((uVar7 == 0x70500000) || ((uVar7 == 0x70600000 || (uVar7 == 0x70700000)))) {
        local_c = 2;
      }
      if (1 < local_c) {
        iVar8 = in_ECX[0x20];
        iVar4 = in_ECX[0x22];
        iVar5 = in_ECX[0x1f];
        auStack_64[iVar8] = 0;
        auStack_64[iVar4] = 0;
        auStack_64[iVar5] = 0;
        iVar2 = in_ECX[0x25];
        auStack_ac[iVar8] = 1;
        auStack_64[iVar2] = 0;
        auStack_ac[iVar4] = 3;
        auStack_ac[iVar5] = 1;
        bVar9 = local_c != 0;
        auStack_ac[iVar2] = 1;
        local_1c = 0;
        local_8 = 0;
        if (bVar9) {
          local_10 = 0;
          do {
            iVar8 = *(int *)(in_ECX[5] + *(int *)(local_10 + param_1[2]) * 4);
            iVar4 = *(int *)(in_ECX[4] + *(int *)(iVar8 + 4) * 4);
            if ((*(int *)(iVar8 + 0x6c) != 0x11) || ((*(byte *)(iVar4 + 4) & 0x10) == 0)) {
              uVar7 = *(uint *)(iVar4 + 4);
              if ((uVar7 & 0x200) == 0) {
                if ((char)uVar7 < '\0') goto LAB_009298cf;
                if (((uVar7 & 0x10) == 0) ||
                   (iVar4 = (**(code **)(*in_ECX + 0x54))(*(int *)(iVar8 + 0x6c)), iVar4 == 0xffff))
                {
                  iVar4 = in_ECX[0x22];
                }
                else {
                  iVar4 = in_ECX[0x20];
                }
              }
              else if ((char)uVar7 < '\0') {
LAB_009298cf:
                iVar4 = in_ECX[0x25];
              }
              else {
                iVar4 = in_ECX[0x1f];
              }
              uVar7 = local_8;
              local_18 = 0;
              if (local_8 != 0) {
                piVar6 = (int *)param_1[2];
                do {
                  iVar5 = *(int *)(in_ECX[5] + *piVar6 * 4);
                  if (((*(int *)(iVar8 + 4) == *(int *)(iVar5 + 4)) &&
                      (*(int *)(iVar8 + 8) == *(int *)(iVar5 + 8))) &&
                     (*(int *)(iVar8 + 0xc) == *(int *)(iVar5 + 0xc))) break;
                  local_18 = local_18 + 1;
                  piVar6 = piVar6 + local_14;
                } while (local_18 < local_8);
              }
              if (local_18 == local_8) {
                puVar1 = auStack_64 + iVar4;
                *puVar1 = *puVar1 + 1;
                if (auStack_ac[iVar4] < *puVar1) {
                  if (param_2 == (uint *)0x0) {
                    return 1;
                  }
                  goto LAB_009299f5;
                }
              }
              if ((in_ECX[0x1f] == iVar4) && (local_1c = local_1c + 1, 2 < local_1c)) {
                if (param_2 == (uint *)0x0) {
                  return 1;
                }
                uVar7 = local_8;
LAB_009299f5:
                *param_2 = uVar7;
                return 1;
              }
            }
            local_8 = local_8 + 1;
            local_10 = local_10 + local_14 * 4;
          } while (local_8 < local_c);
        }
        local_8 = 0;
        if (local_c != 0) {
          iVar8 = 0;
          local_10 = local_14 << 2;
          do {
            if ((*param_1 & 0xf0000000) == 0x60000000) {
              iVar4 = *(int *)(in_ECX[5] + *(int *)(iVar8 + param_1[2]) * 4);
              iVar5 = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(iVar4 + 0x6c));
              if ((iVar5 == 0x12) && (*(int *)(iVar4 + 4) == in_ECX[0x20])) {
                if (param_2 != (uint *)0x0) {
                  *param_2 = local_8;
                }
                return 1;
              }
            }
            local_8 = local_8 + 1;
            iVar8 = iVar8 + local_10;
          } while (local_8 < local_c);
        }
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}


// ==== FUN_00929a18 @ 0x00929a18 ====

int FUN_00929a18(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  
  if ((0x1ff < (*(uint *)(in_ECX + 200) & 0xffff)) ||
     (iVar3 = *(int *)(in_ECX + 0x100), (*(ushort *)(iVar3 + 2) & 0xfff0) == 0)) {
    return 0;
  }
  uVar4 = 0;
  if (*(uint *)(iVar3 + 4) != 0) {
    piVar2 = *(int **)(iVar3 + 8);
    do {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar2 * 4);
      if (*(int *)(iVar1 + 8) != -1) {
        iVar3 = FUN_009290a1(*(undefined4 *)(iVar1 + 8));
        if (iVar3 < 0) {
          return iVar3;
        }
        return 0;
      }
      uVar4 = uVar4 + 1;
      piVar2 = piVar2 + 1;
    } while (uVar4 < *(uint *)(iVar3 + 4));
  }
  return 0;
}


// ==== FUN_00929a3b @ 0x00929a3b ====

int FUN_00929a3b(void)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  
  uVar3 = 0;
  if (*(uint *)(in_EAX + 4) != 0) {
    piVar1 = *(int **)(in_EAX + 8);
    do {
      iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar1 * 4);
      if (*(int *)(iVar2 + 8) != -1) {
        iVar2 = FUN_009290a1(*(undefined4 *)(iVar2 + 8));
        if (iVar2 < 0) {
          return iVar2;
        }
        return 0;
      }
      uVar3 = uVar3 + 1;
      piVar1 = piVar1 + 1;
    } while (uVar3 < *(uint *)(in_EAX + 4));
  }
  return 0;
}


// ==== FUN_00929a74 @ 0x00929a74 ====

int FUN_00929a74(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  uint local_c;
  uint local_8;
  
  if ((*(byte *)(in_ECX + 0x70) & 0x40) == 0) {
    iVar2 = FUN_0092955f();
    if (iVar2 < 0) {
      return iVar2;
    }
  }
  else {
    iVar2 = in_ECX;
  }
  local_8 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = local_8;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_8 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      if ((*puVar1 & 0xfff00000) == 0x11400000) {
        iVar2 = FUN_00942ad6();
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      else {
        iVar2 = 1;
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(in_ECX + 0xc));
  }
  if ((*(byte *)(in_ECX + 0xcc) & 4) != 0) {
    FUN_00919e76();
    local_8 = 0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        *(uint *)(in_ECX + 0xfc) = local_8;
        puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_8 * 4);
        *(uint **)(in_ECX + 0x100) = puVar1;
        if ((*puVar1 & 0xfff00000) == 0x10000000) {
          FUN_0093f3d2();
        }
        local_8 = local_8 + 1;
      } while (local_8 < *(uint *)(in_ECX + 0xc));
    }
    FUN_00919e8f();
    if ((*(byte *)(in_ECX + 0xcc) & 4) != 0) goto LAB_00929f80;
  }
  local_8 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = local_8;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_8 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      uVar3 = *puVar1 & 0xfff00000;
      if (uVar3 == 0x10100000) {
        iVar2 = FUN_00949ac4(1);
LAB_00929ba6:
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      else {
        if (((uVar3 == 0x20000000) || (uVar3 == 0x20100000)) || (uVar3 == 0x30000000)) {
          iVar2 = FUN_0093fdb0();
          FUN_0093e2c8();
          goto LAB_00929ba6;
        }
        iVar2 = 1;
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(in_ECX + 0xc));
  }
  if (((*(byte *)(in_ECX + 0x6c) & 0x80) != 0) && ((*(byte *)(in_ECX + 0x71) & 1) != 0)) {
    local_8 = 0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        *(uint *)(in_ECX + 0xfc) = local_8;
        puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_8 * 4);
        *(uint **)(in_ECX + 0x100) = puVar1;
        if ((*puVar1 & 0xfff00000) == 0x30000000) {
          if (iVar2 < 0) {
            return iVar2;
          }
          iVar2 = FUN_0093f455(0,0,0);
          if (iVar2 < 0) {
            return iVar2;
          }
          iVar2 = FUN_0093fa51(0,0,0);
          if (iVar2 < 0) {
            return iVar2;
          }
        }
        else {
          iVar2 = 1;
        }
        local_8 = local_8 + 1;
      } while (local_8 < *(uint *)(in_ECX + 0xc));
    }
    iVar2 = FUN_0091ae30();
    if (iVar2 < 0) {
      return iVar2;
    }
    FUN_0093e2c8();
    local_8 = 0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        *(uint *)(in_ECX + 0xfc) = local_8;
        puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_8 * 4);
        *(uint **)(in_ECX + 0x100) = puVar1;
        uVar3 = *puVar1 & 0xfff00000;
        if (uVar3 == 0x20000000) {
LAB_00929cab:
          iVar2 = FUN_0093fdb0();
          FUN_0093e2c8();
LAB_00929cbb:
          if (iVar2 < 0) {
            return iVar2;
          }
        }
        else {
          if (uVar3 == 0x30000000) {
            iVar2 = FUN_00944dce();
            if (iVar2 < 0) {
              return iVar2;
            }
            iVar2 = FUN_00944ea0();
            goto LAB_00929cbb;
          }
          if (uVar3 == 0x70b00000) goto LAB_00929cab;
          iVar2 = 1;
        }
        local_8 = local_8 + 1;
      } while (local_8 < *(uint *)(in_ECX + 0xc));
    }
  }
  local_c = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = local_c;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_c * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      uVar3 = *puVar1 & 0xfff00000;
      if (uVar3 == 0x10500000) {
        if ((*(uint *)(in_ECX + 200) & 0xffff) < 0x200) goto LAB_00929d7e;
        iVar2 = FUN_0093ef49();
      }
      else if (uVar3 == 0x10f00000) {
        iVar2 = FUN_00941ed7();
      }
      else if (uVar3 == 0x11400000) {
        iVar2 = FUN_00942ad6();
      }
      else if (uVar3 == 0x20100000) {
        if ((*(uint *)(in_ECX + 200) & 0xffff) < 0x200) goto LAB_00929d7e;
        iVar2 = FUN_00944cdb();
      }
      else if (uVar3 == 0x20400000) {
        if ((*(byte *)(in_ECX + 0x6c) & 0x20) != 0) {
          iVar2 = FUN_00944750();
        }
        if (iVar2 == 1) {
          iVar2 = FUN_00949b7e(1);
        }
      }
      else {
LAB_00929d7e:
        iVar2 = 1;
      }
      local_8 = 0;
      if (*(int *)(in_ECX + 0xc) != 0) {
        iVar2 = 1;
        do {
          *(uint *)(in_ECX + 0xfc) = local_8;
          puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_8 * 4);
          *(uint **)(in_ECX + 0x100) = puVar1;
          if ((*puVar1 & 0xfff00000) == 0x70000000) {
            FUN_00949b04();
          }
          local_8 = local_8 + 1;
        } while (local_8 < *(uint *)(in_ECX + 0xc));
      }
      if (iVar2 < 0) {
        return iVar2;
      }
      local_c = local_c + 1;
    } while (local_c < *(uint *)(in_ECX + 0xc));
  }
  iVar2 = FUN_0091ae30();
  if (iVar2 < 0) {
    return iVar2;
  }
  FUN_0093e2c8();
  local_8 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = local_8;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_8 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      uVar3 = *puVar1 & 0xfff00000;
      if (uVar3 == 0x20500000) {
        iVar2 = FUN_0094414d();
LAB_00929ea2:
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      else {
        if (uVar3 == 0x50000000) {
          if ((*(byte *)(in_ECX + 0x6c) & 0x20) != 0) {
            iVar2 = FUN_00944a10();
          }
          goto LAB_00929ea2;
        }
        if (uVar3 == 0x70300000) {
          iVar2 = FUN_00945449(1);
          goto LAB_00929ea2;
        }
        if ((uVar3 == 0x73500000) || (uVar3 == 0x73600000)) {
          iVar2 = FUN_0094260e();
          if (iVar2 < 0) {
            return iVar2;
          }
          iVar2 = FUN_0094275c();
          goto LAB_00929ea2;
        }
        if ((uVar3 == 0x74600000) || (uVar3 == 0x74700000)) {
          iVar2 = FUN_00943c85();
          if (iVar2 < 0) {
            return iVar2;
          }
          iVar2 = FUN_00943dd3();
          goto LAB_00929ea2;
        }
        iVar2 = 1;
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(in_ECX + 0xc));
  }
  local_c = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = local_c;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_c * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      uVar3 = *puVar1 & 0xfff00000;
      if (uVar3 < 0x74400001) {
        if (uVar3 == 0x74400000) goto LAB_00929f1f;
        if ((((uVar3 != 0x73500000) && (uVar3 != 0x73600000)) && (uVar3 != 0x73700000)) &&
           (uVar3 != 0x73800000)) goto LAB_00929f33;
        iVar2 = FUN_009428be();
LAB_00929f26:
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      else if (((uVar3 == 0x74500000) || (uVar3 == 0x74600000)) || (uVar3 == 0x74700000)) {
LAB_00929f1f:
        iVar2 = FUN_00943f35();
        goto LAB_00929f26;
      }
LAB_00929f33:
      local_c = local_c + 1;
    } while (local_c < *(uint *)(in_ECX + 0xc));
  }
  local_c = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = local_c;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_c * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      if (((*puVar1 & 0xfff00000) == 0x73700000) && (iVar2 = FUN_00942527(), iVar2 < 0)) {
        return iVar2;
      }
      local_c = local_c + 1;
    } while (local_c < *(uint *)(in_ECX + 0xc));
  }
LAB_00929f80:
  FUN_0093e2c8();
  local_c = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = local_c;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_c * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      uVar3 = *puVar1 & 0xfff00000;
      if ((uVar3 == 0x74600000) || (uVar3 == 0x74700000)) {
        iVar2 = FUN_00943c85();
        if (iVar2 < 0) {
          return iVar2;
        }
        iVar2 = FUN_00943dd3();
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      local_c = local_c + 1;
    } while (local_c < *(uint *)(in_ECX + 0xc));
  }
  uVar3 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar3;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar3 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      uVar4 = *puVar1 & 0xfff00000;
      if ((((uVar4 == 0x74400000) || (uVar4 == 0x74500000)) || (uVar4 == 0x74600000)) ||
         (uVar4 == 0x74700000)) {
        FUN_00943f35();
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 0xc));
  }
  local_c = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = local_c;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_c * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      if (((*puVar1 & 0xfff00000) == 0x20900000) && (iVar2 = FUN_00943467(), iVar2 < 0)) {
        return iVar2;
      }
      local_c = local_c + 1;
    } while (local_c < *(uint *)(in_ECX + 0xc));
  }
  FUN_0093e2c8();
  local_c = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = local_c;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_c * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      if (((*puVar1 & 0xfff00000) == 0x20900000) && (iVar2 = FUN_00942f8d(), iVar2 < 0)) {
        return iVar2;
      }
      local_c = local_c + 1;
    } while (local_c < *(uint *)(in_ECX + 0xc));
  }
  local_c = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = local_c;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_c * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      if (((*puVar1 & 0xfff00000) == 0x11400000) && (iVar2 = FUN_0093e625(), iVar2 < 0)) {
        return iVar2;
      }
      local_c = local_c + 1;
    } while (local_c < *(uint *)(in_ECX + 0xc));
  }
  local_c = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = local_c;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_c * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      if (((*puVar1 & 0xfff00000) == 0x70300000) && (iVar2 = FUN_00945449(0), iVar2 < 0)) {
        return iVar2;
      }
      local_c = local_c + 1;
    } while (local_c < *(uint *)(in_ECX + 0xc));
  }
  FUN_0093e2c8();
  local_c = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = local_c;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_c * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      uVar3 = *puVar1 & 0xfff00000;
      if ((((uVar3 == 0x10300000) || (uVar3 == 0x10500000)) || (uVar3 == 0x10600000)) ||
         ((uVar3 == 0x10700000 || (uVar3 == 0x50000000)))) {
        iVar2 = FUN_00941be9();
LAB_0092a1a3:
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      else if (uVar3 == 0x70300000) {
        iVar2 = FUN_0094b02e();
        goto LAB_0092a1a3;
      }
      local_c = local_c + 1;
    } while (local_c < *(uint *)(in_ECX + 0xc));
  }
  FUN_0093e2c8();
  iVar2 = FUN_0091ae30();
  if (((-1 < iVar2) && (iVar2 = FUN_009237bb(), -1 < iVar2)) &&
     ((iVar2 = FUN_00915e19(), -1 < iVar2 && (iVar2 = FUN_0091c491(), -1 < iVar2)))) {
    FUN_0093e2c8();
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_0092a200 @ 0x0092a200 ====

int FUN_0092a200(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  bool bVar4;
  undefined4 uVar5;
  
  uVar3 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar3;
      *(undefined4 *)(in_ECX + 0x100) = *(undefined4 *)(*(int *)(in_ECX + 0x18) + uVar3 * 4);
      FUN_0093eb91();
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 0xc));
  }
  uVar3 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar3;
      iVar1 = *(int *)(*(int *)(in_ECX + 0x18) + uVar3 * 4);
      *(int *)(in_ECX + 0x100) = iVar1;
      iVar1 = *(int *)(iVar1 + 0x3c);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) == 0xd)) {
        *(int *)(in_ECX + 0x104) = iVar1 + 0x30;
      }
      iVar1 = FUN_00929a18();
      if (iVar1 < 0) {
        return iVar1;
      }
      uVar2 = **(uint **)(in_ECX + 0x100) & 0xfff00000;
      if (uVar2 < 0x60f00001) {
        if (uVar2 == 0x60f00000) {
LAB_0092a58d:
          if ((*(byte *)(in_ECX + 0x70) & 0x40) != 0) goto LAB_0092a837;
          iVar1 = FUN_0094dc51();
          goto LAB_0092a7d1;
        }
        if (uVar2 < 0x20700001) {
          if (uVar2 == 0x20700000) {
            iVar1 = FUN_0094e448();
          }
          else if (uVar2 < 0x10f00001) {
            if (uVar2 == 0x10f00000) {
LAB_0092a773:
              iVar1 = FUN_0094e23f();
            }
            else if (uVar2 < 0x10500001) {
              if (uVar2 == 0x10500000) {
                iVar1 = FUN_0094f3ab();
              }
              else if (uVar2 == 0) {
                iVar1 = FUN_00813a93();
              }
              else {
                if (uVar2 == 0x10000000) goto LAB_0092a3d2;
                if (uVar2 == 0x10100000) {
                  iVar1 = FUN_0094e840();
                }
                else if (uVar2 == 0x10300000) {
                  iVar1 = FUN_0094f383();
                }
                else {
                  if (uVar2 != 0x10400000) goto LAB_0092a837;
                  iVar1 = FUN_0094f3a1();
                }
              }
            }
            else if (uVar2 == 0x10600000) {
              iVar1 = FUN_0094f3c9();
            }
            else if (uVar2 == 0x10700000) {
              iVar1 = FUN_0094f3e7();
            }
            else if (uVar2 == 0x10d00000) {
              if ((*(byte *)(in_ECX + 0x70) & 0x10) == 0) {
LAB_0092a35b:
                iVar1 = -0x7fffbfff;
              }
              else {
                iVar1 = FUN_0094f36f();
              }
            }
            else {
              if (uVar2 != 0x10e00000) goto LAB_0092a837;
              if ((*(byte *)(in_ECX + 0x70) & 0x10) == 0) goto LAB_0092a35b;
              iVar1 = FUN_0094f379();
            }
          }
          else if (uVar2 < 0x20100001) {
            if (uVar2 == 0x20100000) {
LAB_0092a6b3:
              iVar1 = FUN_0094f40f();
            }
            else if (uVar2 == 0x11000000) {
              if ((*(byte *)(in_ECX + 0x70) & 0x40) != 0) goto LAB_0092a837;
              iVar1 = FUN_0094e04c();
            }
            else {
              if (uVar2 != 0x11200000) {
                if (uVar2 == 0x11300000) goto LAB_0092a7d5;
                if (uVar2 != 0x11500000) {
                  if (uVar2 != 0x20000000) goto LAB_0092a837;
                  goto LAB_0092a3c6;
                }
              }
LAB_0092a3d2:
              iVar1 = FUN_0094f236();
            }
          }
          else if (uVar2 == 0x20200000) {
            iVar1 = FUN_0094f419();
          }
          else if (uVar2 == 0x20300000) {
            iVar1 = FUN_0094f423();
          }
          else if (uVar2 == 0x20400000) {
            iVar1 = FUN_0094f42d();
          }
          else {
            if (uVar2 != 0x20500000) goto LAB_0092a837;
            iVar1 = FUN_0094f437();
          }
          goto LAB_0092a7d1;
        }
        if (0x60400000 < uVar2) {
          if (uVar2 < 0x60a00001) {
            if ((uVar2 == 0x60a00000) || (uVar2 == 0x60500000)) goto LAB_0092a58d;
            if (uVar2 != 0x60600000) {
              if (uVar2 != 0x60700000) {
                if (uVar2 != 0x60800000) {
                  bVar4 = uVar2 == 0x60900000;
                  goto LAB_0092a571;
                }
                goto LAB_0092a503;
              }
              goto LAB_0092a60b;
            }
          }
          else if (uVar2 != 0x60b00000) {
            if (uVar2 != 0x60c00000) {
              if (uVar2 == 0x60d00000) {
LAB_0092a503:
                if ((*(byte *)(in_ECX + 0x70) & 0x40) != 0) goto LAB_0092a837;
                iVar1 = FUN_0094df4b();
                goto LAB_0092a7d1;
              }
              bVar4 = uVar2 == 0x60e00000;
LAB_0092a571:
              if (!bVar4) goto LAB_0092a837;
              goto LAB_0092a577;
            }
LAB_0092a60b:
            if ((*(byte *)(in_ECX + 0x70) & 0x40) != 0) goto LAB_0092a837;
            iVar1 = FUN_0094dee4();
            goto LAB_0092a7d1;
          }
LAB_0092a621:
          iVar1 = FUN_0094dcb5();
          goto LAB_0092a7d1;
        }
        if (uVar2 == 0x60400000) {
LAB_0092a577:
          if ((*(byte *)(in_ECX + 0x70) & 0x20) == 0) goto LAB_0092a837;
          iVar1 = FUN_0094dfb2();
          goto LAB_0092a7d1;
        }
        if (0x50300000 < uVar2) {
          if (uVar2 == 0x60000000) goto LAB_0092a58d;
          if (uVar2 != 0x60100000) {
            if (uVar2 != 0x60200000) {
              if (uVar2 != 0x60300000) goto LAB_0092a837;
              goto LAB_0092a503;
            }
            goto LAB_0092a60b;
          }
          goto LAB_0092a621;
        }
        if (uVar2 == 0x50300000) {
          iVar1 = FUN_0094e1a1();
          goto LAB_0092a7d1;
        }
        if (uVar2 != 0x20800000) {
          if (uVar2 == 0x20900000) goto LAB_0092a3d2;
          if (uVar2 == 0x30000000) {
            if ((*(byte *)(in_ECX + 0x70) & 0x40) != 0) goto LAB_0092a837;
            iVar1 = FUN_0094f508();
          }
          else if (uVar2 == 0x50000000) {
            iVar1 = FUN_0094f44b();
          }
          else {
            if (uVar2 != 0x50100000) goto LAB_0092a837;
            iVar1 = FUN_0094f4fe();
          }
          goto LAB_0092a7d1;
        }
      }
      else {
        if (uVar2 < 0x73400001) {
          if (uVar2 == 0x73400000) {
            iVar1 = FUN_0094e816();
          }
          else if (uVar2 < 0x70600001) {
            if (uVar2 == 0x70600000) {
LAB_0092a659:
              iVar1 = FUN_0094ecbe();
            }
            else if (uVar2 < 0x70100001) {
              if (uVar2 == 0x70100000) {
                iVar1 = FUN_0094e9bf();
              }
              else {
                if (uVar2 == 0x61000000) goto LAB_0092a621;
                if (uVar2 == 0x61100000) goto LAB_0092a60b;
                if (uVar2 == 0x61200000) goto LAB_0092a503;
                if (uVar2 == 0x61300000) goto LAB_0092a577;
                if (uVar2 != 0x70000000) goto LAB_0092a837;
                iVar1 = FUN_0094f51c();
              }
            }
            else if (uVar2 == 0x70200000) {
              iVar1 = FUN_0094eada();
            }
            else {
              if ((uVar2 != 0x70300000) && (uVar2 != 0x70400000)) {
                if (uVar2 != 0x70500000) goto LAB_0092a837;
                goto LAB_0092a659;
              }
              iVar1 = FUN_0094eb80();
            }
          }
          else if (uVar2 < 0x70d00001) {
            if (uVar2 == 0x70d00000) {
              iVar1 = FUN_0094e94d();
            }
            else {
              if (uVar2 == 0x70700000) goto LAB_0092a659;
              if (uVar2 == 0x70800000) {
                iVar1 = FUN_0094e016();
              }
              else if (uVar2 == 0x70900000) {
                iVar1 = FUN_0094f441();
              }
              else {
                if (uVar2 != 0x70b00000) {
                  if (uVar2 != 0x70c00000) goto LAB_0092a837;
                  goto LAB_0092a6b3;
                }
LAB_0092a3c6:
                iVar1 = FUN_0094f405();
              }
            }
          }
          else {
            if (uVar2 == 0x73000000) {
              uVar5 = 0;
            }
            else {
              if (uVar2 == 0x73100000) goto LAB_0092a703;
              if (uVar2 != 0x73200000) {
                bVar4 = uVar2 == 0x73300000;
                goto LAB_0092a6fd;
              }
              uVar5 = 1;
            }
            iVar1 = FUN_0094e772(uVar5);
          }
        }
        else if (uVar2 < 0x73f00001) {
          if (uVar2 == 0x73f00000) {
LAB_0092a703:
            iVar1 = FUN_0094e7ec();
          }
          else {
            if (uVar2 < 0x73a00001) {
              if (uVar2 != 0x73a00000) {
                if ((((uVar2 == 0x73500000) || (uVar2 == 0x73600000)) || (uVar2 == 0x73700000)) ||
                   (uVar2 == 0x73800000)) goto LAB_0092a773;
                if (uVar2 != 0x73900000) goto LAB_0092a837;
              }
            }
            else if ((uVar2 != 0x73b00000) && (uVar2 != 0x73c00000)) {
              if (uVar2 != 0x73d00000) {
                bVar4 = uVar2 == 0x73e00000;
LAB_0092a6fd:
                if (!bVar4) goto LAB_0092a837;
              }
              goto LAB_0092a703;
            }
            iVar1 = FUN_0094e617();
          }
        }
        else {
          if (uVar2 < 0x74500001) {
            if (uVar2 != 0x74500000) {
              if (uVar2 == 0x74000000) goto LAB_0092a703;
              if (uVar2 == 0x74100000) {
                iVar1 = FUN_0094f1b2();
              }
              else {
                if (uVar2 != 0x74200000) {
                  if (uVar2 != 0x74400000) goto LAB_0092a837;
                  goto LAB_0092a7ca;
                }
                iVar1 = FUN_0094f148();
              }
              goto LAB_0092a7d1;
            }
          }
          else if ((uVar2 != 0x74600000) && (uVar2 != 0x74700000)) {
            if (uVar2 == 0x74a00000) {
              iVar1 = FUN_0094dae1();
            }
            else {
              if (uVar2 != 0x74b00000) goto LAB_0092a837;
              iVar1 = FUN_0094dab7();
            }
            goto LAB_0092a7d1;
          }
LAB_0092a7ca:
          iVar1 = FUN_0094db0b();
        }
LAB_0092a7d1:
        if (iVar1 == -0x7fffbfff) {
LAB_0092a837:
          FUN_0091a001();
          return -0x7fffbfff;
        }
      }
LAB_0092a7d5:
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 0xc));
  }
  return 0;
}


// ==== FUN_0092a852 @ 0x0092a852 ====

undefined4 FUN_0092a852(int param_1)

{
  undefined4 uVar1;
  
  if ((((param_1 == 0x60500000) || (param_1 == 0x60a00000)) || (param_1 == 0x60000000)) ||
     (((param_1 == 0x72e00000 || (param_1 == 0x60700000)) || (param_1 == 0x60f00000)))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0092a8eb @ 0x0092a8eb ====

void FUN_0092a8eb(void)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 0x1f8);
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(in_ECX + 0x218) = 0;
  *(undefined4 *)(in_ECX + 0x21c) = 0;
  *(undefined4 *)(in_ECX + 0x220) = 0;
  *(undefined4 *)(in_ECX + 0x224) = 0;
  _free(*(void **)(in_ECX + 0x22c));
  return;
}


// ==== FUN_0092a94b @ 0x0092a94b ====

undefined4 FUN_0092a94b(void)

{
  uint uVar1;
  int in_ECX;
  uint uVar2;
  
  uVar1 = *(uint *)(in_ECX + 0x6c);
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(byte *)(in_ECX + 0xcd) = *(byte *)(in_ECX + 0xcd) | 1;
  *(uint *)(in_ECX + 0x70) = *(uint *)(in_ECX + 0x70) | 8;
  *(uint *)(in_ECX + 0x108) = *(uint *)(in_ECX + 200);
  uVar2 = *(uint *)(in_ECX + 200) & 0xffff;
  *(undefined4 *)(in_ECX + 0x28) = 2;
  *(undefined4 *)(in_ECX + 0x2c) = 0x18;
  *(undefined4 *)(in_ECX + 0x38) = 8;
  *(undefined4 *)(in_ECX + 0x48) = 1;
  *(undefined4 *)(in_ECX + 100) = 0x40;
  *(uint *)(in_ECX + 0x6c) = uVar1 & 0xffffffde | 0x16712c8a;
  if (uVar2 == 0x104) {
    *(undefined4 *)(in_ECX + 0x50) = 0;
    *(undefined4 *)(in_ECX + 0x3c) = 6;
    *(undefined4 *)(in_ECX + 0x44) = 8;
    *(undefined4 *)(in_ECX + 0x4c) = 6;
    *(uint *)(in_ECX + 0x6c) = uVar1 & 0xff71ffda | 0x1671fc9a;
  }
  else {
    *(undefined4 *)(in_ECX + 0x3c) = 4;
    *(undefined4 *)(in_ECX + 0x44) = 6;
    *(undefined4 *)(in_ECX + 0x4c) = 4;
    *(uint *)(in_ECX + 0x6c) =
         (uint)(uVar2 == 0x101) << 0x11 | uVar1 & 0xfffd2fde | 0x16712c8a | 0x208c0014;
    *(undefined4 *)(in_ECX + 0x50) = 2;
  }
  return 0;
}


// ==== FUN_0092a9fe @ 0x0092a9fe ====

undefined4 FUN_0092a9fe(void)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int *piVar5;
  uint local_10;
  int *local_c;
  uint local_8;
  
  local_10 = *(uint *)(in_ECX + 0x4c);
  if (local_10 < *(uint *)(in_ECX + 0x224)) {
    local_c = (int *)(*(int *)(in_ECX + 0x230) + local_10 * 4);
    do {
      puVar2 = (uint *)*local_c;
      if ((((puVar2 != (uint *)0x0) && (*puVar2 != 0)) &&
          ((iVar3 = *(int *)(in_ECX + 0x14),
           *(int *)(*(int *)(iVar3 + *(int *)puVar2[4] * 4) + 4) != *(int *)(in_ECX + 0x84) ||
           ((*puVar2 & 0xfff00000) != 0x10000000)))) && (local_8 = 0, puVar2[1] != 0)) {
        piVar5 = (int *)puVar2[2];
        do {
          iVar4 = *(int *)(iVar3 + *piVar5 * 4);
          puVar1 = (uint *)(iVar4 + 0x3c);
          for (; *(int *)(iVar4 + 0x38) != -1; iVar4 = *(int *)(iVar3 + *(int *)(iVar4 + 0x38) * 4))
          {
          }
          if ((*(char *)(iVar4 + 0x6c) == '\x03') &&
             (((*(uint *)(iVar4 + 0x3c) | *puVar1) & 0x200) == 0)) {
            FUN_0091a096();
            return 0;
          }
          local_8 = local_8 + 1;
          piVar5 = piVar5 + 1;
        } while (local_8 < puVar2[1]);
      }
      local_10 = local_10 + 1;
      local_c = local_c + 1;
    } while (local_10 < *(uint *)(in_ECX + 0x224));
  }
  return 0;
}


// ==== FUN_0092aadd @ 0x0092aadd ====

undefined4 FUN_0092aadd(void)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  bool bVar7;
  int in_ECX;
  uint uVar8;
  int *piVar9;
  int local_c;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                           *(int *)(*(int *)(*(int *)(in_ECX + 0x100) + 8) + 0x1c) * 4) + 0x48);
  if (iVar1 == -1) {
    return 1;
  }
  puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar1 * 4);
  uVar8 = *puVar2 & 0xfff00000;
  if ((uVar8 != 0x10000000) && (uVar8 != 0x50000000)) {
    return 1;
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0x100) + 8);
  local_c = -1;
  iVar3 = *(int *)(iVar1 + 0x18);
  iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4);
  iVar5 = *(int *)(iVar4 + 0x48);
  if ((((iVar5 != -1) && (*(int *)(iVar4 + 0x3c) == 0)) &&
      (puVar6 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar5 * 4),
      (*puVar6 & 0xfff00000) == 0x10000000)) && (local_8 = 0, puVar6[1] != 0)) {
    do {
      if (*(int *)(puVar6[4] + local_8 * 4) == iVar3) {
        local_c = *(int *)(local_8 * 4 + puVar6[2]);
      }
      local_8 = local_8 + 1;
    } while (local_8 < puVar6[1]);
  }
  bVar7 = false;
  if (uVar8 == 0x10000000) {
    uVar8 = 0;
    if (puVar2[1] == 0) {
      return 1;
    }
    do {
      iVar4 = *(int *)(puVar2[2] + uVar8 * 4);
      if ((iVar4 == iVar3) && (*(int *)(puVar2[4] + uVar8 * 4) == *(int *)(iVar1 + 0x1c))) {
        bVar7 = true;
      }
      if ((iVar4 == local_c) && (*(int *)(puVar2[4] + uVar8 * 4) == *(int *)(iVar1 + 0x1c))) {
        bVar7 = true;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < puVar2[1]);
  }
  else {
    uVar8 = puVar2[1];
    if (uVar8 == 0) {
      return 1;
    }
    piVar9 = (int *)puVar2[4];
    do {
      if (local_c == *piVar9) {
        bVar7 = true;
      }
      piVar9 = piVar9 + 1;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
  }
  if (bVar7) {
    **(undefined4 **)(in_ECX + 0x100) = 0x72e00003;
    *(undefined4 *)(*(int *)(in_ECX + 0x100) + 4) = 6;
    iVar1 = *(int *)(*(int *)(in_ECX + 0x100) + 8);
    *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar1 + 0x10);
    iVar1 = *(int *)(*(int *)(in_ECX + 0x100) + 8);
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 0x14);
    iVar1 = *(int *)(*(int *)(in_ECX + 0x100) + 8);
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar1 + 0x18);
    return 0;
  }
  return 1;
}


// ==== FUN_0092ac61 @ 0x0092ac61 ====

undefined4 FUN_0092ac61(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  bool bVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  int in_ECX;
  uint uVar13;
  uint uVar14;
  uint local_20;
  uint local_18;
  int *local_c;
  uint local_8;
  
  puVar1 = *(uint **)(in_ECX + 0x100);
  if (((*puVar1 & 0xfffff) == 4) && (puVar1[1] == 4)) {
    piVar12 = (int *)puVar1[2];
    iVar2 = piVar12[3];
    local_c = *(int **)(*(int *)(in_ECX + 0x100) + 8);
    local_8 = 0;
    piVar9 = local_c + 3;
    do {
      if (*local_c == *piVar9) goto LAB_0092aded;
      local_8 = local_8 + 1;
      local_c = local_c + 1;
    } while (local_8 < 3);
    iVar3 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar2 * 4) + 0x48);
    local_20 = -1;
    if (((iVar3 != -1) &&
        (puVar4 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar3 * 4),
        (*puVar4 & 0xfff00000) == 0x10000000)) && (local_8 = 0, puVar4[3] != 0)) {
      do {
        if (iVar2 == *(int *)(puVar4[4] + local_8 * 4)) {
          local_20 = *(int *)(local_8 * 4 + puVar4[2]);
        }
        local_8 = local_8 + 1;
      } while (local_8 < puVar4[3]);
    }
    uVar13 = 0;
    piVar9 = piVar12;
    do {
      if (*piVar9 == local_20) {
LAB_0092aded:
        *puVar1 = 0x11000003;
        return 0;
      }
      uVar13 = uVar13 + 1;
      piVar9 = piVar9 + 1;
    } while (uVar13 < 3);
    local_20 = 0;
    local_c = piVar12;
    do {
      iVar5 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *local_c * 4) + 0x48);
      if (iVar5 != -1) {
        puVar4 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar3 * 4);
        puVar6 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar5 * 4);
        if (((*puVar4 ^ *puVar6) & 0xfff00000) == 0) {
          uVar14 = *puVar4 & 0xfffff;
          uVar13 = *puVar6 & 0xfffff;
          if (((uVar14 != 0) && (uVar13 != 0)) &&
             ((uVar10 = puVar4[1] / uVar14, uVar10 == puVar6[1] / uVar13 &&
              ((uVar14 == puVar4[3] && (uVar7 = puVar6[3], uVar13 == uVar7)))))) {
            local_18 = 0xffffffff;
            local_8 = 0;
            if (uVar7 != 0) {
              piVar9 = (int *)puVar6[4];
              do {
                if (*piVar9 == *local_c) {
                  local_18 = local_8;
                  break;
                }
                local_8 = local_8 + 1;
                piVar9 = piVar9 + 1;
              } while (local_8 < uVar7);
            }
            uVar11 = 0;
            if (uVar7 != 0) {
              piVar9 = (int *)puVar4[4];
LAB_0092ae0a:
              if (*piVar9 != iVar2) goto code_r0x0092ae11;
              if ((uVar11 != 0xffffffff) && (local_18 != 0xffffffff)) {
                bVar8 = true;
                if (uVar10 != 0) {
                  piVar9 = (int *)(puVar4[2] + uVar11 * 4);
                  piVar12 = (int *)(puVar6[2] + local_18 * 4);
                  do {
                    if (*piVar9 != *piVar12) {
                      bVar8 = false;
                    }
                    piVar12 = piVar12 + uVar13;
                    piVar9 = piVar9 + uVar14;
                    uVar10 = uVar10 - 1;
                  } while (uVar10 != 0);
                  if (!bVar8) goto LAB_0092ae6c;
                }
                **(undefined4 **)(in_ECX + 0x100) = 0x11000003;
                *(undefined4 *)(*(int *)(in_ECX + 0x100) + 4) = 3;
                *(undefined4 *)(*(int *)(in_ECX + 0x100) + 0xc) = 3;
                return 0;
              }
            }
          }
        }
      }
LAB_0092ae6c:
      local_20 = local_20 + 1;
      local_c = local_c + 1;
    } while (local_20 < 3);
    FUN_0091a001(in_ECX,puVar1[0xf],0x11c0,s_Clip_must_be_from_a_3_vector_in_p_00a2aaac,
                 *(uint *)(in_ECX + 200) & 0xff);
  }
  else {
    FUN_0091a001();
  }
  return 0x80004005;
code_r0x0092ae11:
  uVar11 = uVar11 + 1;
  piVar9 = piVar9 + 1;
  if (puVar6[3] <= uVar11) goto LAB_0092ae6c;
  goto LAB_0092ae0a;
}


// ==== FUN_0092aee9 @ 0x0092aee9 ====

int FUN_0092aee9(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined1 local_58 [64];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_18 = 0;
  iVar2 = 1;
  local_14 = 1;
  local_10 = 2;
  local_c = 3;
  if ((**(uint **)(in_ECX + 0x100) & 0xfffff) == 3) {
    iVar2 = FUN_0093d430(*(uint **)(in_ECX + 0x100),&DAT_00a2a908,local_58,&local_8,&local_f8,
                         &local_18,3,1);
    if (iVar2 == 0) {
      puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x100) + 8);
      *puVar1 = local_f8;
      puVar1[1] = uStack_f4;
      puVar1[2] = uStack_f0;
      iVar2 = 0;
    }
  }
  return iVar2;
}


// ==== FUN_0092af63 @ 0x0092af63 ====

undefined4 FUN_0092af63(void)

{
  byte *pbVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  uint local_c;
  uint local_8;
  
  if (((**(uint **)(in_ECX + 0x100) & 0xfff00000) == 0x10000000) &&
     ((*(uint *)(in_ECX + 200) & 0xffff) < 0x104)) {
    puVar3 = *(uint **)(in_ECX + 0x100);
    uVar4 = *puVar3;
    iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar3[2] * 4);
    iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar3[4] * 4);
    if ((*(int *)(iVar6 + 0x3c) == 0) &&
       ((((*(byte *)(iVar5 + 0x3d) & 2) != 0 && (*(char *)(iVar6 + 0x6c) == '\x03')) &&
        (*(int *)(iVar5 + 4) == *(int *)(in_ECX + 0x88))))) {
      local_c = 0;
      if ((uVar4 & 0xfffff) != 0) {
        do {
          iVar6 = local_c * 4;
          pbVar1 = (byte *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                    *(int *)(iVar6 + *(int *)(*(int *)(in_ECX + 0x100) + 8)) * 4) +
                           0x3d);
          *pbVar1 = *pbVar1 | 2;
          for (uVar7 = *(uint *)(in_ECX + 0xfc); uVar7 < *(uint *)(in_ECX + 0xc); uVar7 = uVar7 + 1)
          {
            iVar5 = *(int *)(*(int *)(in_ECX + 0x18) + uVar7 * 4);
            local_8 = 0;
            if (*(int *)(iVar5 + 4) != 0) {
              do {
                piVar2 = (int *)(*(int *)(iVar5 + 8) + local_8 * 4);
                if (*piVar2 == *(int *)(iVar6 + *(int *)(*(int *)(in_ECX + 0x100) + 0x10))) {
                  *piVar2 = *(int *)(iVar6 + *(int *)(*(int *)(in_ECX + 0x100) + 8));
                }
                local_8 = local_8 + 1;
              } while (local_8 < *(uint *)(iVar5 + 4));
            }
          }
          local_c = local_c + 1;
        } while (local_c < (uVar4 & 0xfffff));
      }
      **(undefined4 **)(in_ECX + 0x100) = 0;
    }
  }
  return 0;
}


// ==== FUN_0092b08f @ 0x0092b08f ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0092b08f(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  bool bVar8;
  uint local_10;
  int *local_c;
  int local_8;
  
  if ((**(uint **)(in_ECX + 0x100) & 0xfff00000) == 0x10100000) {
    iVar1 = *(int *)(in_ECX + 0x14);
    uVar5 = **(uint **)(in_ECX + 0x100) & 0xfffff;
    bVar8 = (*(uint *)(*(int *)(*(int *)(in_ECX + 0x10) +
                               *(int *)(*(int *)(iVar1 + *(int *)(*(uint **)(in_ECX + 0x100))[2] * 4
                                                ) + 4) * 4) + 4) & 0x200) != 0;
    if (((*(byte *)(in_ECX + 0x6e) & 2) != 0) && (uVar5 != 0)) {
      local_c = (int *)(*(uint **)(in_ECX + 0x100))[2];
      local_10 = uVar5;
      do {
        iVar2 = *(int *)(iVar1 + *local_c * 4);
        if ((*(uint *)(iVar2 + 0x3c) & 0x200) != 0) {
          bVar8 = true;
        }
        if (*(int *)(iVar2 + 0x38) != -1) {
          iVar2 = *(int *)(iVar1 + *(int *)(iVar2 + 0x38) * 4);
        }
        if ((*(uint *)(iVar2 + 0x3c) & 0x200) != 0) {
          bVar8 = true;
        }
        local_c = local_c + 1;
        local_10 = local_10 - 1;
      } while (local_10 != 0);
    }
    if (bVar8) {
      iVar1 = FUN_009149f7();
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
        iVar1 = FUN_00914a42(uVar5 | 0x20500000,uVar5 * 2,uVar5,0);
        if ((-1 < iVar1) && (iVar1 = FUN_00914593(), -1 < iVar1)) {
          iVar1 = FUN_009152bf(&DAT_00a1fc10,0x311,1,4);
          if ((iVar1 == -1) || (iVar1 = FUN_00915318(iVar1,0,0,_DAT_009fd350), iVar1 == -1)) {
            iVar1 = -0x7ff8fff2;
          }
          else {
            iVar2 = uVar5 << 2;
            puVar6 = *(undefined4 **)(*(int *)(in_ECX + 0x100) + 8);
            puVar7 = *(undefined4 **)(local_8 + 8);
            for (uVar3 = uVar5; uVar3 != 0; uVar3 = uVar3 - 1) {
              *puVar7 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar7 = puVar7 + 1;
            }
            for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
              *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
              puVar6 = (undefined4 *)((int)puVar6 + 1);
              puVar7 = (undefined4 *)((int)puVar7 + 1);
            }
            puVar6 = *(undefined4 **)(*(int *)(in_ECX + 0x100) + 0x10);
            puVar7 = *(undefined4 **)(local_8 + 0x10);
            for (uVar3 = uVar5; uVar3 != 0; uVar3 = uVar3 - 1) {
              *puVar7 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar7 = puVar7 + 1;
            }
            for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
              *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
              puVar6 = (undefined4 *)((int)puVar6 + 1);
              puVar7 = (undefined4 *)((int)puVar7 + 1);
            }
            for (; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(int *)(iVar2 + *(int *)(local_8 + 8)) = iVar1;
              iVar2 = iVar2 + 4;
            }
            iVar1 = 0;
            if (*(int *)(*(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0xfc) * 4) != 0) {
              FUN_008f4adb();
            }
            *(int *)(*(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0xfc) * 4) = local_8;
            local_8 = 0;
          }
        }
        if (local_8 != 0) {
          FUN_008f4adb();
        }
      }
    }
    else {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_0092b289 @ 0x0092b289 ====

undefined4 FUN_0092b289(void)

{
  int *piVar1;
  bool bVar2;
  bool bVar3;
  int *piVar4;
  int in_ECX;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int local_24;
  int local_20;
  int *local_1c;
  int *local_18;
  uint local_10;
  uint local_c;
  uint local_8;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0x230) + -4 + *(int *)(in_ECX + 0x224) * 4);
  if ((piVar1 != (int *)0x0) && (*piVar1 == 0x10000004)) {
    uVar7 = 0;
    do {
      iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(uVar7 + piVar1[4]) * 4);
      if (*(int *)(iVar8 + 4) != *(int *)(in_ECX + 0x84)) {
        return 0;
      }
      if (*(int *)(iVar8 + 0x3c) != 0) {
        return 0;
      }
      if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(uVar7 + piVar1[2]) * 4) + 0x3e) &
          0x1f) != 0) {
        return 0;
      }
      uVar7 = uVar7 + 4;
    } while (uVar7 < 0x10);
    local_c = 0;
    local_1c = (int *)piVar1[2];
    local_8 = *(int *)(in_ECX + 0x224) - 1;
    bVar3 = true;
    do {
      uVar7 = 0;
      bVar2 = false;
      if (local_8 != 0) {
        local_18 = *(int **)(in_ECX + 0x230);
        do {
          piVar4 = (int *)*local_18;
          if ((piVar4 != (int *)0x0) && (*piVar4 != 0)) {
            iVar8 = piVar4[3];
            if (iVar8 != 0) {
              piVar4 = (int *)piVar4[4];
              do {
                if (*piVar4 == *local_1c) {
                  bVar2 = true;
                }
                piVar4 = piVar4 + 1;
                iVar8 = iVar8 + -1;
              } while (iVar8 != 0);
            }
            if (bVar2) break;
          }
          local_18 = local_18 + 1;
          uVar7 = uVar7 + 1;
        } while (uVar7 < local_8);
      }
      if ((*(uint *)(in_ECX + 200) & 0xffff) == 0x104) {
        if ((uVar7 < *(uint *)(in_ECX + 0x4c)) && (uVar7 != 0)) {
LAB_0092b38e:
          bVar3 = false;
        }
      }
      else if (uVar7 < *(uint *)(in_ECX + 0x4c)) goto LAB_0092b38e;
      if (!bVar2) {
        return 0;
      }
      uVar7 = uVar7 + 1;
      if (uVar7 < local_8) {
        local_18 = (int *)(*(int *)(in_ECX + 0x230) + uVar7 * 4);
        local_24 = local_8 - uVar7;
        do {
          piVar4 = (int *)*local_18;
          if ((piVar4 != (int *)0x0) && (*piVar4 != 0)) {
            local_20 = piVar4[3];
            if (local_20 != 0) {
              piVar5 = (int *)piVar4[4];
              do {
                iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar5 * 4);
                if (((*(int *)(iVar8 + 4) == *(int *)(in_ECX + 0x88)) &&
                    (*(uint *)(iVar8 + 0x10) == local_c)) && (*(int *)(iVar8 + 0xc) == 0)) {
                  bVar3 = false;
                }
                piVar5 = piVar5 + 1;
                local_20 = local_20 + -1;
              } while (local_20 != 0);
            }
            local_20 = piVar4[1];
            if (local_20 != 0) {
              piVar4 = (int *)piVar4[2];
              do {
                iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar4 * 4);
                if (((*(int *)(iVar8 + 4) == *(int *)(in_ECX + 0x88)) &&
                    (*(uint *)(iVar8 + 0x10) == local_c)) && (*(int *)(iVar8 + 0xc) == 0)) {
                  bVar3 = false;
                }
                piVar4 = piVar4 + 1;
                local_20 = local_20 + -1;
              } while (local_20 != 0);
            }
          }
          local_18 = local_18 + 1;
          local_24 = local_24 + -1;
        } while (local_24 != 0);
      }
      local_c = local_c + 1;
      local_1c = local_1c + 1;
    } while (local_c < 4);
    uVar7 = 0;
    if (bVar3) {
      do {
        local_10 = 0;
        if (local_8 != 0) {
          do {
            uVar6 = 0;
            piVar4 = *(int **)(*(int *)(in_ECX + 0x230) + local_10 * 4);
            if (((piVar4 != (int *)0x0) && (*piVar4 != 0)) && (piVar4[3] != 0)) {
              do {
                iVar8 = *(int *)(piVar4[4] + uVar6 * 4);
                if (iVar8 == *(int *)(uVar7 + piVar1[2])) {
                  *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar8 * 4) + 0xc) = 0;
                }
                uVar6 = uVar6 + 1;
              } while (uVar6 < (uint)piVar4[3]);
            }
            local_10 = local_10 + 1;
            local_8 = *(int *)(in_ECX + 0x224) - 1;
          } while (local_10 < local_8);
        }
        uVar7 = uVar7 + 4;
      } while (uVar7 < 0x10);
      *piVar1 = 0;
    }
  }
  return 0;
}


// ==== FUN_0092b4cb @ 0x0092b4cb ====

int FUN_0092b4cb(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  uint local_14;
  int local_10;
  uint local_8;
  
  local_8 = 0;
  if (*(int *)(in_ECX + 0x4c) != 0) {
    do {
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x230) + local_8 * 4);
      if (puVar1 != (uint *)0x0) {
        uVar2 = *puVar1 & 0xfff00000;
        if ((uVar2 != 0x72100000) && (uVar2 != 0)) {
          uVar5 = *puVar1 & 0xfffff;
          local_10 = (-(uint)(uVar2 != 0x11000000) & uVar5) * 4;
          if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                 *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                  *(int *)(local_10 + puVar1[2]) * 4) + 4) * 4) + 5)
              & 2) != 0) {
            iVar3 = FUN_009149f7();
            if (iVar3 == 0) {
              iVar3 = 0;
            }
            else {
              iVar3 = FUN_0091455d();
            }
            if (iVar3 == 0) {
              return -0x7ff8fff2;
            }
            iVar4 = FUN_00914a42(uVar5 | 0x10000000,uVar5,uVar5,0);
            if ((iVar4 < 0) || (iVar4 = FUN_00914593(), iVar4 < 0)) {
LAB_0092b671:
              FUN_008f4adb();
              return iVar4;
            }
            local_14 = 0;
            if (uVar5 != 0) {
              do {
                iVar4 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0,local_14,0);
                *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4) + 0x3c) = 0;
                *(int *)(*(int *)(iVar3 + 0x10) + local_14 * 4) = iVar4;
                *(undefined4 *)(*(int *)(iVar3 + 8) + local_14 * 4) =
                     *(undefined4 *)
                      (local_10 + *(int *)(*(int *)(*(int *)(in_ECX + 0x230) + local_8 * 4) + 8));
                local_14 = local_14 + 1;
                *(int *)(local_10 + *(int *)(*(int *)(*(int *)(in_ECX + 0x230) + local_8 * 4) + 8))
                     = iVar4;
                local_10 = local_10 + 4;
              } while (local_14 < uVar5);
            }
            puVar1 = (uint *)(in_ECX + 0x220);
            if (0x1ff < *puVar1) {
              iVar4 = -0x7ff8fff2;
              goto LAB_0092b671;
            }
            *(int *)(*(int *)(in_ECX + 0x22c) + *puVar1 * 4) = iVar3;
            *puVar1 = *puVar1 + 1;
            iVar4 = FUN_00915205();
            if (iVar4 < 0) goto LAB_0092b671;
          }
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(in_ECX + 0x4c));
  }
  return 0;
}


// ==== FUN_0092b67e @ 0x0092b67e ====

int FUN_0092b67e(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  uint uVar7;
  uint local_10;
  uint local_8;
  
  uVar2 = *(uint *)(in_ECX + 0xc);
  iVar3 = FUN_009149f7(0x74);
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_0091455d();
  }
  if (iVar3 == 0) {
    iVar4 = -0x7ff8fff2;
  }
  else {
    iVar4 = FUN_00914a42(0x10000004,4,4,0);
    if (-1 < iVar4) {
      local_8 = 0xffffffff;
      uVar6 = 0;
      if (*(int *)(in_ECX + 8) != 0) {
        do {
          iVar4 = uVar6 * 4;
          if (*(int *)(*(int *)(iVar4 + *(int *)(in_ECX + 0x14)) + 4) == *(int *)(in_ECX + 0x84)) {
            *(uint *)(*(int *)(iVar3 + 8) +
                     *(int *)(*(int *)(iVar4 + *(int *)(in_ECX + 0x14)) + 0x10) * 4) = uVar6;
            *(undefined4 *)(*(int *)(iVar4 + *(int *)(in_ECX + 0x14)) + 4) =
                 *(undefined4 *)(in_ECX + 0x88);
            *(undefined4 *)(*(int *)(iVar4 + *(int *)(in_ECX + 0x14)) + 0xc) = 0xffffffff;
            local_8 = *(undefined4 *)(*(int *)(iVar4 + *(int *)(in_ECX + 0x14)) + 0x6c);
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < *(uint *)(in_ECX + 8));
      }
      uVar6 = 0;
      do {
        uVar5 = FUN_00915318(*(undefined4 *)(in_ECX + 0x84),0,uVar6,0);
        *(undefined4 *)(*(int *)(iVar3 + 0x10) + uVar6 * 4) = uVar5;
        if (*(int *)(*(int *)(iVar3 + 0x10) + uVar6 * 4) == -1) {
          iVar4 = -0x7ff8fff2;
          goto LAB_0092b77b;
        }
        iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(*(int *)(iVar3 + 0x10) + uVar6 * 4) * 4)
        ;
        *(undefined4 *)(iVar4 + 0x3c) = 0;
        uVar6 = uVar6 + 1;
        *(uint *)(iVar4 + 0x6c) = local_8;
      } while (uVar6 < 4);
      iVar4 = FUN_00915205();
      if (-1 < iVar4) {
        local_10 = 0;
        if (uVar2 != 0) {
          do {
            iVar4 = *(int *)(*(int *)(in_ECX + 0x18) + local_10 * 4);
            if ((((iVar4 != 0) && (uVar6 = *(uint *)(iVar4 + 0xc), uVar6 != 0)) &&
                (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + **(int **)(iVar4 + 0x10) * 4) + 4) ==
                 *(int *)(in_ECX + 0x84))) && (local_8 = 0, uVar6 != 0)) {
              do {
                uVar7 = 0;
                do {
                  piVar1 = (int *)(*(int *)(iVar4 + 0x10) + local_8 * 4);
                  if (*piVar1 == *(int *)(uVar7 + *(int *)(iVar3 + 0x10))) {
                    *piVar1 = *(int *)(uVar7 + *(int *)(iVar3 + 8));
                  }
                  uVar7 = uVar7 + 4;
                } while (uVar7 < 0x10);
                local_8 = local_8 + 1;
              } while (local_8 < uVar6);
            }
            local_10 = local_10 + 1;
          } while (local_10 < uVar2);
        }
        return 0;
      }
    }
LAB_0092b77b:
    FUN_008f4adb();
  }
  return iVar4;
}


// ==== FUN_0092b81e @ 0x0092b81e ====

undefined4 FUN_0092b81e(int *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  param_2 = param_2 - (int)param_1;
  while ((*param_1 == -1 || (*param_1 == *(int *)(param_2 + (int)param_1)))) {
    uVar1 = uVar1 + 1;
    param_1 = param_1 + 1;
    if (3 < uVar1) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0092b84f @ 0x0092b84f ====

undefined4 FUN_0092b84f(int param_1,int *param_2,uint param_3)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint local_8;
  
  local_8 = 0;
  if (param_3 != 0) {
    piVar3 = &DAT_00b59ff8;
    do {
      bVar1 = true;
      iVar4 = 4;
      piVar2 = param_2;
      do {
        if ((*(int *)((param_1 - (int)param_2) + (int)piVar2) != *piVar3) && (*piVar2 != -1)) {
          bVar1 = false;
        }
        piVar3 = piVar3 + 1;
        piVar2 = piVar2 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      if (bVar1) {
        return 1;
      }
      local_8 = local_8 + 1;
    } while (local_8 < param_3);
  }
  return 0;
}


// ==== FUN_0092b8aa @ 0x0092b8aa ====

undefined4 FUN_0092b8aa(int param_1)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  int *piVar5;
  uint uVar6;
  int in_ECX;
  uint uVar7;
  int local_18 [4];
  undefined4 local_8;
  
  local_8 = 0;
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  uVar6 = *(uint *)(param_1 + 0xc);
  uVar7 = 0;
  if (uVar6 != 0) {
    iVar1 = *(int *)(in_ECX + 0x14);
    piVar5 = *(int **)(param_1 + 0x10);
    do {
      uVar2 = *(uint *)(*(int *)(iVar1 + *piVar5 * 4) + 0x10);
      if (3 < uVar2) {
        return 0;
      }
      uVar7 = uVar7 + 1;
      piVar5 = piVar5 + 1;
      local_18[uVar2] = 1;
    } while (uVar7 < uVar6);
  }
  bVar3 = false;
  bVar4 = true;
  uVar6 = 0;
  do {
    if (local_18[uVar6] == 0) {
      bVar3 = true;
    }
    else {
      bVar4 = false;
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 < 3);
  if ((bVar3) && (!bVar4)) {
    local_8 = 1;
  }
  return local_8;
}


// ==== FUN_0092b922 @ 0x0092b922 ====

int FUN_0092b922(void)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint *puVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int in_ECX;
  uint *puVar8;
  undefined4 uVar9;
  uint *puVar10;
  int iVar11;
  bool bVar12;
  int local_ec [20];
  uint local_9c [12];
  int local_6c [4];
  undefined4 local_5c [4];
  int local_4c;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint *local_2c;
  uint local_28;
  uint local_24;
  uint *local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  local_34 = *(uint *)(in_ECX + 0x4c);
  local_3c = *(uint *)(in_ECX + 0x224);
  bVar12 = local_34 < *(uint *)(in_ECX + 0x224);
  do {
    local_c = 0;
    if (!bVar12) {
      iVar11 = 0;
LAB_0092bccd:
      if (local_8 != 0) {
        FUN_008f4adb();
      }
LAB_0092bcdb:
      if (local_c != 0) {
        FUN_008f4adb();
      }
      return iVar11;
    }
    puVar10 = *(uint **)(*(int *)(in_ECX + 0x230) + local_34 * 4);
    local_2c = puVar10;
    if ((puVar10 != (uint *)0x0) && (*puVar10 != 0)) {
      local_14 = *puVar10 & 0xfffff;
      local_38 = puVar10[1] / local_14;
      local_24 = 0;
      if (local_38 != 0) {
        local_18 = 0;
        local_20 = local_9c;
        do {
          puVar4 = local_20;
          puVar8 = local_20 + 1;
          *local_20 = 0xffffffff;
          *puVar8 = 0xffffffff;
          puVar4[2] = 0xffffffff;
          puVar4[3] = 0xffffffff;
          local_ec[0] = -1;
          local_ec[1] = 0xffffffff;
          local_ec[2] = 0xffffffff;
          local_ec[3] = 0xffffffff;
          local_28 = 0;
          local_30 = 0;
          if (local_14 == 0) {
LAB_0092ba92:
            iVar11 = FUN_0092b84f(local_20,local_ec,2);
            if (iVar11 == 0) {
              local_4c = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0,3,0);
              if (local_4c == -1) goto LAB_0092bcf0;
              iVar11 = FUN_009149f7();
              if (iVar11 == 0) {
                local_8 = 0;
              }
              else {
                local_8 = FUN_0091455d();
              }
              if (local_8 == 0) goto LAB_0092bcf0;
              iVar11 = FUN_00914a42(0x50000003,6,1,0);
              if ((iVar11 < 0) || (iVar11 = FUN_00914593(), iVar11 < 0)) goto LAB_0092bccd;
              iVar11 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(local_18 + puVar10[2]) * 4);
              local_28 = *(uint *)(iVar11 + 0x10);
              local_10 = 0;
              do {
                if (local_10 == local_28) {
                  uVar9 = *(undefined4 *)(in_ECX + 0x444);
                }
                else {
                  uVar9 = *(undefined4 *)(in_ECX + 0x440);
                }
                uVar1 = *(undefined8 *)(iVar11 + 0x20);
                uVar2 = *(undefined4 *)(iVar11 + 4);
                local_5c[local_10] = uVar9;
                iVar7 = FUN_00915318(uVar2,0,local_10,uVar1);
                local_6c[local_10] = iVar7;
                if (iVar7 == -1) goto LAB_0092bcf0;
                local_1c = *(uint *)(*(int *)(in_ECX + 0x14) + iVar7 * 4);
                FUN_00914e44();
                iVar7 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                         *(int *)(local_18 + puVar10[2]) * 4) + 0x38);
                if (iVar7 == -1) {
                  *(int *)(local_1c + 0x38) = *(int *)(local_18 + puVar10[2]);
                }
                else {
                  *(int *)(local_1c + 0x38) = iVar7;
                }
                local_10 = local_10 + 1;
              } while (local_10 < 3);
              puVar3 = *(undefined4 **)(local_8 + 8);
              *puVar3 = local_5c[0];
              puVar3[1] = local_5c[1];
              puVar3[2] = local_5c[2];
              iVar11 = *(int *)(local_8 + 8);
              *(int *)(iVar11 + 0xc) = local_6c[0];
              *(int *)(iVar11 + 0x10) = local_6c[1];
              *(int *)(iVar11 + 0x14) = local_6c[2];
              **(int **)(local_8 + 0x10) = local_4c;
              if (local_14 != 0) {
                iVar11 = local_18;
                uVar6 = local_14;
                do {
                  *(int *)(iVar11 + local_2c[2]) = local_4c;
                  iVar11 = iVar11 + 4;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
              }
              if (0x1ff < *(uint *)(in_ECX + 0x224)) goto LAB_0092bcf0;
              *(int *)(*(int *)(in_ECX + 0x230) + *(uint *)(in_ECX + 0x224) * 4) = local_8;
              *(int *)(in_ECX + 0x224) = *(int *)(in_ECX + 0x224) + 1;
              iVar11 = FUN_00915205();
              if (iVar11 < 0) goto LAB_0092bcf0;
              local_8 = 0;
              puVar10 = local_2c;
            }
          }
          else {
            local_1c = *puVar10 & 0xfff00000;
            piVar5 = (int *)(puVar10[2] + local_18);
            do {
              local_10 = *(uint *)(*(int *)(in_ECX + 0x14) + *piVar5 * 4);
              uVar6 = local_30;
              if ((local_1c != 0x50000000) && (local_14 == puVar10[3])) {
                uVar6 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                          *(int *)(puVar10[4] + local_30 * 4) * 4) + 0x10);
              }
              iVar11 = uVar6 + local_24 * 4;
              if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(local_10 + 4) * 4) + 5) & 1
                  ) == 0) {
                local_9c[iVar11] = *(uint *)(local_10 + 0x10);
              }
              else {
                local_9c[iVar11] = uVar6;
              }
              if (uVar6 == 3) {
                local_28 = 1;
              }
              local_ec[uVar6] = 0;
              local_30 = local_30 + 1;
              piVar5 = piVar5 + 1;
            } while (local_30 < local_14);
            if (((local_28 == 0) || (bVar12 = true, local_14 != 1)) ||
               ((local_1c == 0x50000000 && (puVar10[3] == 1)))) goto LAB_0092ba92;
            uVar6 = 0;
            puVar8 = local_20;
            do {
              if ((*puVar8 != *(uint *)((int)&DAT_00b5a038 + uVar6)) &&
                 (*(int *)((int)local_ec + uVar6) != -1)) {
                bVar12 = false;
              }
              uVar6 = uVar6 + 4;
              puVar8 = puVar8 + 1;
            } while (uVar6 < 0x10);
            if (!bVar12) goto LAB_0092ba92;
          }
          local_24 = local_24 + 1;
          local_20 = local_20 + 4;
          local_18 = local_18 + local_14 * 4;
        } while (local_24 < local_38);
      }
      iVar11 = FUN_009149f7();
      if (iVar11 == 0) {
        local_c = 0;
      }
      else {
        local_c = FUN_0091455d();
      }
      if ((local_c != 0) && (iVar11 = FUN_00915205(), -1 < iVar11)) {
        iVar11 = FUN_00914ca1();
        iVar7 = local_c;
        if (iVar11 < 0) goto LAB_0092bcdb;
        if (*(uint *)(in_ECX + 0x224) < 0x200) {
          local_c = 0;
          *(int *)(*(int *)(in_ECX + 0x230) + *(uint *)(in_ECX + 0x224) * 4) = iVar7;
          *(int *)(in_ECX + 0x224) = *(int *)(in_ECX + 0x224) + 1;
          *puVar10 = 0;
          goto LAB_0092bcbb;
        }
      }
LAB_0092bcf0:
      iVar11 = -0x7ff8fff2;
      goto LAB_0092bccd;
    }
LAB_0092bcbb:
    local_34 = local_34 + 1;
    bVar12 = local_34 < local_3c;
  } while( true );
}


// ==== FUN_0092bcf7 @ 0x0092bcf7 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0092bcf7(void)

{
  uint uVar1;
  uint *puVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int *in_ECX;
  int *piVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int local_1c;
  int local_14;
  uint local_c;
  uint local_8;
  
  local_c = 0;
  if (in_ECX[2] != 0) {
    piVar7 = (int *)in_ECX[5];
    iVar10 = in_ECX[2];
    do {
      if ((in_ECX[0x22] == *(int *)(*piVar7 + 4)) &&
         (uVar6 = *(uint *)(*piVar7 + 0xc), local_c <= uVar6)) {
        local_c = uVar6 + 1;
      }
      piVar7 = piVar7 + 1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  uVar1 = in_ECX[0x89];
  uVar6 = in_ECX[0x13];
  do {
    if (uVar1 <= uVar6) {
      for (uVar6 = in_ECX[0x13]; uVar6 < uVar1; uVar6 = uVar6 + 1) {
        **(undefined4 **)(in_ECX[0x8c] + uVar6 * 4) = 0;
      }
      return 0;
    }
    puVar2 = *(uint **)(in_ECX[0x8c] + uVar6 * 4);
    if ((puVar2 != (uint *)0x0) && (uVar9 = *puVar2, uVar9 != 0)) {
      uVar11 = uVar9 & 0xfffff;
      if ((uVar9 & 0xfff00000) == 0x70100000) {
        piVar7 = (int *)puVar2[2];
        iVar10 = in_ECX[5];
        iVar12 = in_ECX[4];
        if ((((*(byte *)(*(int *)(iVar12 + *(int *)(*(int *)(iVar10 + *piVar7 * 4) + 4) * 4) + 5) &
              2) != 0) &&
            ((*(byte *)(*(int *)(iVar12 + *(int *)(*(int *)(iVar10 + piVar7[uVar11] * 4) + 4) * 4) +
                       5) & 2) != 0)) &&
           ((*(byte *)(*(int *)(iVar12 + *(int *)(*(int *)(iVar10 + piVar7[uVar11 * 2] * 4) + 4) * 4
                               ) + 5) & 2) != 0)) {
          iVar10 = FUN_009149f7();
          if (iVar10 == 0) {
            local_14 = 0;
          }
          else {
            local_14 = FUN_0091455d();
          }
          if (local_14 == 0) {
            return -0x7ff8fff2;
          }
          iVar10 = FUN_00914a42(uVar11 | 0x10000000,uVar11,uVar11,0);
          if (iVar10 < 0) {
            return iVar10;
          }
          iVar10 = FUN_00914593();
          if (iVar10 < 0) {
            return iVar10;
          }
          local_8 = 0;
          if (uVar11 != 0) {
            do {
              iVar12 = local_8 * 4;
              iVar10 = *(int *)(in_ECX[5] + *(int *)(iVar12 + puVar2[4]) * 4);
              *(undefined4 *)(iVar12 + *(int *)(local_14 + 8)) = *(undefined4 *)(iVar12 + puVar2[2])
              ;
              uVar4 = FUN_00915318(in_ECX[0x22],local_c,*(undefined4 *)(iVar10 + 0x10),0);
              *(undefined4 *)(iVar12 + *(int *)(local_14 + 0x10)) = uVar4;
              *(undefined4 *)(iVar12 + puVar2[2]) =
                   *(undefined4 *)(iVar12 + *(int *)(local_14 + 0x10));
              if (*(int *)(iVar12 + *(int *)(local_14 + 0x10)) == -1) {
                return -0x7ff8fff2;
              }
              local_8 = local_8 + 1;
            } while (local_8 < uVar11);
          }
          local_c = local_c + 1;
          if (0x1ff < (uint)in_ECX[0x89]) {
            return -0x7ff8fff2;
          }
          iVar10 = FUN_00915205();
          if (iVar10 < 0) {
            return iVar10;
          }
          *(int *)(in_ECX[0x8c] + in_ECX[0x89] * 4) = local_14;
          in_ECX[0x89] = in_ECX[0x89] + 1;
        }
      }
      if (((*puVar2 & 0xfff00000) == 0x30000000) && ((in_ECX[0x32] & 0xffffU) != 0x104)) {
        uVar9 = 1;
        if (1 < uVar11) {
          piVar7 = (int *)puVar2[2];
          iVar10 = *piVar7;
          do {
            piVar7 = piVar7 + 1;
            if (iVar10 != *piVar7) {
              FUN_0091a001();
              return -0x7fffbffb;
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar11);
        }
        iVar10 = FUN_009149f7();
        if (iVar10 == 0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          puVar5 = (undefined4 *)FUN_0091455d();
        }
        if (puVar5 == (undefined4 *)0x0) {
          return -0x7ff8fff2;
        }
        local_8 = FUN_00915205();
        if ((int)local_8 < 0) {
LAB_0092c240:
          FUN_008f4adb();
          return local_8;
        }
        iVar10 = FUN_00914a42(0x70300001,3,1,0);
        if (iVar10 < 0) {
          return iVar10;
        }
        iVar10 = FUN_00914593();
        uVar3 = _DAT_009fd350;
        if (iVar10 < 0) {
          return iVar10;
        }
        *(undefined4 *)puVar5[2] = *(undefined4 *)puVar2[2];
        uVar4 = FUN_00915318(in_ECX[0x1e],0,0,uVar3);
        uVar3 = _DAT_00a011c0;
        *(undefined4 *)(puVar5[2] + 4) = uVar4;
        uVar4 = FUN_00915318(in_ECX[0x1e],0,0,uVar3);
        *(undefined4 *)(puVar5[2] + 8) = uVar4;
        if (*(int *)(puVar5[2] + 4) == -1) {
          return -0x7ff8fff2;
        }
        if (*(int *)(puVar5[2] + 8) == -1) {
          return -0x7ff8fff2;
        }
        uVar4 = FUN_00915318(in_ECX[0x22],local_c,3,0);
        *(undefined4 *)puVar5[4] = uVar4;
        if (*(int *)puVar5[4] == -1) {
          return -0x7ff8fff2;
        }
        local_8 = 0;
        if (uVar11 != 0) {
          local_1c = uVar11 << 3;
          local_14 = uVar11 << 2;
          do {
            *(undefined4 *)(puVar2[2] + local_8 * 4) = *(undefined4 *)puVar5[4];
            puVar8 = (undefined4 *)(local_14 + puVar2[2]);
            uVar4 = *puVar8;
            *puVar8 = *(undefined4 *)(puVar2[2] + local_1c);
            *(undefined4 *)(local_1c + puVar2[2]) = uVar4;
            local_8 = local_8 + 1;
            local_1c = local_1c + 4;
            local_14 = local_14 + 4;
          } while (local_8 < uVar11);
        }
        local_c = local_c + 1;
        if (0x1ff < (uint)in_ECX[0x89]) {
          return -0x7ff8fff2;
        }
        *(undefined4 **)(in_ECX[0x8c] + in_ECX[0x89] * 4) = puVar5;
        in_ECX[0x89] = in_ECX[0x89] + 1;
        iVar10 = (**(code **)(*in_ECX + 0x20))(puVar5);
        if (iVar10 != 0) {
          iVar10 = FUN_009149f7();
          if (iVar10 == 0) {
            local_14 = 0;
          }
          else {
            local_14 = FUN_0091455d();
          }
          local_8 = FUN_00915205();
          if ((int)local_8 < 0) {
            if (local_14 == 0) {
              return local_8;
            }
            goto LAB_0092c240;
          }
          if (local_14 == 0) {
            return -0x7ff8fff2;
          }
          iVar10 = FUN_00914a42(0x20400001,2,1,0);
          if (iVar10 < 0) {
            return iVar10;
          }
          iVar10 = FUN_00914593();
          if (iVar10 < 0) {
            return iVar10;
          }
          **(undefined4 **)(local_14 + 0x10) = *(undefined4 *)puVar5[4];
          **(undefined4 **)(local_14 + 8) = *(undefined4 *)(puVar5[2] + 8);
          uVar4 = FUN_00915318(in_ECX[0x22],0,3,0);
          *(undefined4 *)puVar5[4] = uVar4;
          *(undefined4 *)(*(int *)(local_14 + 8) + 4) = *(undefined4 *)puVar5[4];
          puVar5[1] = 2;
          *puVar5 = 0x20500001;
          if (0x1ff < (uint)in_ECX[0x89]) {
            return -0x7ff8fff2;
          }
          *(int *)(in_ECX[0x8c] + in_ECX[0x89] * 4) = local_14;
          in_ECX[0x89] = in_ECX[0x89] + 1;
        }
        in_ECX[0x113] = 1;
        *puVar2 = uVar11 | 0x70f00000;
      }
      iVar10 = FUN_009149f7();
      if (iVar10 == 0) {
        iVar10 = 0;
      }
      else {
        iVar10 = FUN_0091455d();
      }
      if (iVar10 == 0) {
        return -0x7ff8fff2;
      }
      iVar12 = FUN_00914ca1();
      if (iVar12 < 0) {
        return iVar12;
      }
      if (0x1ff < (uint)in_ECX[0x89]) {
        return -0x7ff8fff2;
      }
      iVar12 = FUN_00915205();
      if (iVar12 < 0) {
        return iVar12;
      }
      *(int *)(in_ECX[0x8c] + in_ECX[0x89] * 4) = iVar10;
      in_ECX[0x89] = in_ECX[0x89] + 1;
    }
    uVar6 = uVar6 + 1;
  } while( true );
}


// ==== FUN_0092c26f @ 0x0092c26f ====

int FUN_0092c26f(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *in_ECX;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  bool bVar11;
  undefined4 uVar12;
  int local_ac [12];
  int local_7c [9];
  int iStack_58;
  int iStack_54;
  int iStack_50;
  int local_4c [9];
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  puVar1 = *(uint **)((int)in_ECX + 0x100);
  uVar8 = *puVar1;
  local_1c = (int *)(uVar8 & 0xfffff);
  if ((puVar1 == (uint *)0x0) || (uVar8 == 0)) {
    return 0;
  }
  local_c = (int *)(puVar1[1] / (uint)local_1c);
  local_18 = (int *)0x0;
  if (((uVar8 & 0xfff00000) == 0x50000000) || ((int *)puVar1[3] != local_1c)) {
    iVar6 = FUN_00915471(puVar1);
    if (iVar6 < 0) {
      return iVar6;
    }
    **(undefined4 **)((int)in_ECX + 0x100) = 0;
    return 0;
  }
  local_4c[8] = 0;
  local_20 = in_ECX;
  if ((((*(uint *)((int)in_ECX + 200) & 0xffff) != 0x104) &&
      (iVar6 = FUN_0092b8aa(puVar1), iVar6 != 0)) && (uVar8 = puVar1[3], uVar8 != 0)) {
    piVar9 = (int *)puVar1[4];
    do {
      if (*(int *)(*(int *)(*(int *)((int)in_ECX + 0x14) + *piVar9 * 4) + 0x10) == 3) {
        local_18 = (int *)0x1;
        local_4c[8] = 1;
      }
      piVar9 = piVar9 + 1;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
  }
  local_14 = (int *)0x0;
  if (local_c != (int *)0x0) {
    local_24 = (int *)0x0;
    local_8 = local_ac;
    do {
      piVar10 = local_8;
      piVar9 = local_8 + 1;
      *local_8 = -1;
      local_10 = (int *)0x0;
      *piVar9 = -1;
      piVar10[2] = -1;
      piVar10[3] = -1;
      local_7c[0] = -1;
      local_7c[1] = -1;
      local_7c[2] = -1;
      local_7c[3] = -1;
      if (local_1c != (int *)0x0) {
        iVar6 = *(int *)((int)in_ECX + 0x100);
        iVar7 = *(int *)((int)in_ECX + 0x14);
        iVar2 = *(int *)((int)in_ECX + 0x10);
        local_28 = local_24;
        do {
          iVar3 = *(int *)(iVar7 + *(int *)((int)local_28 + *(int *)(iVar6 + 8)) * 4);
          iVar4 = *(int *)(*(int *)(iVar7 + *(int *)(*(int *)(iVar6 + 0x10) + (int)local_10 * 4) * 4
                                   ) + 0x10);
          if ((*(byte *)(*(int *)(iVar2 + *(int *)(iVar3 + 4) * 4) + 5) & 1) == 0) {
            local_ac[iVar4 + (int)local_14 * 4] = *(int *)(iVar3 + 0x10);
          }
          else {
            local_ac[iVar4 + (int)local_14 * 4] = iVar4;
          }
          local_7c[iVar4] = 0;
          local_10 = (int *)((int)local_10 + 1);
          local_28 = local_28 + 1;
        } while (local_10 < local_1c);
        in_ECX = local_20;
      }
      iVar6 = FUN_0092b84f(local_8,local_7c,5);
      if (iVar6 == 0) {
        local_18 = (int *)0x1;
      }
      local_14 = (int *)((int)local_14 + 1);
      local_8 = local_8 + 4;
      local_24 = local_24 + (int)local_1c;
    } while (local_14 < local_c);
  }
  uVar8 = 0;
  if (local_18 == (int *)0x0) {
    iVar6 = FUN_00915471(*(undefined4 *)((int)in_ECX + 0x100));
LAB_0092c7fe:
    if (iVar6 < 0) {
      return iVar6;
    }
    goto LAB_0092c802;
  }
  local_14 = (int *)0x0;
  local_20 = (int *)0x0;
  if (local_1c == (int *)0x4) {
    local_8 = (int *)0x1;
    do {
      if (local_8 == (int *)0x0) break;
      local_7c[0] = 0;
      local_7c[1] = 0;
      local_7c[2] = 0;
      local_7c[3] = 0;
      local_7c[4] = 0xffffffff;
      local_7c[5] = 0xffffffff;
      local_7c[6] = 0xffffffff;
      local_7c[7] = 0xffffffff;
      local_7c[uVar8] = -1;
      local_7c[uVar8 + 4] = 0;
      local_8 = (int *)0x0;
      if (local_c != (int *)0x0) {
        piVar9 = local_ac;
        local_18 = local_c;
        do {
          iVar6 = FUN_0092b84f(piVar9,local_7c,5);
          if ((iVar6 == 0) || (iVar6 = FUN_0092b84f(piVar9,local_7c,5), iVar6 == 0)) {
            local_8 = (int *)0x1;
          }
          piVar9 = piVar9 + 4;
          local_18 = (int *)((int)local_18 - 1);
        } while (local_18 != (int *)0x0);
      }
      if ((local_4c[8] != 0) && (uVar8 != 3)) {
        local_8 = (int *)0x1;
      }
      if (local_8 == (int *)0x0) {
        iVar6 = FUN_00947586(local_7c,local_c,4);
        if (iVar6 < 0) {
          return iVar6;
        }
        iVar6 = FUN_00947586(local_7c + 4,local_c,4);
        goto LAB_0092c7fe;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < 4);
    local_8 = (int *)0x1;
    local_10 = (int *)0x0;
    do {
      if (local_8 == (int *)0x0) break;
      local_18 = (int *)0x0;
      do {
        piVar10 = local_10;
        piVar9 = local_18;
        if (local_18 != local_10) {
          local_7c[0] = 0;
          local_7c[1] = 0;
          local_7c[2] = 0;
          local_7c[3] = 0;
          local_7c[4] = 0xffffffff;
          local_7c[5] = 0xffffffff;
          local_7c[6] = 0xffffffff;
          local_7c[7] = 0xffffffff;
          local_7c[(int)local_10] = -1;
          local_7c[(int)piVar9] = -1;
          bVar11 = local_c != (int *)0x0;
          local_7c[(int)(piVar10 + 1)] = 0;
          local_7c[(int)(piVar9 + 1)] = 0;
          local_8 = (int *)0x0;
          local_28 = (int *)0x0;
          if (bVar11) {
            piVar9 = local_ac;
            local_24 = local_c;
            do {
              iVar6 = FUN_0092b84f(piVar9,local_7c,5);
              iVar7 = FUN_0092b84f(piVar9,local_7c + 4,5);
              if (iVar6 == 0) {
                local_28 = (int *)0x1;
LAB_0092c563:
                local_8 = (int *)0x1;
              }
              else if (iVar7 == 0) goto LAB_0092c563;
              piVar9 = piVar9 + 4;
              local_24 = (int *)((int)local_24 - 1);
            } while (local_24 != (int *)0x0);
          }
          if (local_4c[8] != 0) {
            local_8 = (int *)0x1;
          }
          if (local_8 == (int *)0x0) {
            local_14 = (int *)0x1;
            break;
          }
          if ((local_28 == (int *)0x0) && ((local_4c[8] == 0 || (local_7c[3] != 0)))) {
            local_7c[8] = local_7c[0];
            iStack_58 = local_7c[1];
            iStack_54 = local_7c[2];
            iStack_50 = local_7c[3];
            local_4c[0] = -1;
            local_4c[1] = 0xffffffff;
            local_4c[2] = 0xffffffff;
            local_4c[3] = 0xffffffff;
            local_4c[4] = 0xffffffff;
            local_4c[5] = 0xffffffff;
            local_4c[6] = 0xffffffff;
            local_4c[7] = 0xffffffff;
            local_4c[(int)local_10] = 0;
            local_4c[(int)(local_18 + 1)] = 0;
            local_20 = (int *)0x1;
          }
        }
        local_18 = (int *)((int)local_18 + 1);
      } while (local_18 < (int *)0x4);
      local_10 = (int *)((int)local_10 + 1);
    } while (local_10 < (int *)0x4);
    if (local_14 == (int *)0x0) {
      if (local_20 == (int *)0x0) goto LAB_0092c7a9;
      local_14 = (int *)0x1;
      iVar6 = FUN_00947586(local_7c + 8,local_c,4);
      if (iVar6 < 0) {
        return iVar6;
      }
      iVar6 = FUN_00947586(local_4c,local_c,4);
      if (iVar6 < 0) {
        return iVar6;
      }
      uVar12 = 4;
      piVar9 = local_4c;
    }
    else {
      iVar6 = FUN_00947586(local_7c,local_c,4);
      if (iVar6 < 0) {
        return iVar6;
      }
      uVar12 = 4;
LAB_0092c78d:
      piVar9 = local_7c;
    }
    iVar6 = FUN_00947586(piVar9 + 4,local_c,uVar12);
    if (iVar6 < 0) {
      return iVar6;
    }
    if (local_14 != (int *)0x0) goto LAB_0092c802;
  }
  else if (local_1c == (int *)0x3) {
    local_20 = (int *)0xffffffff;
    piVar9 = (int *)0x0;
    do {
      if (local_ac[(int)piVar9] == -1) {
        local_20 = piVar9;
      }
      piVar9 = (int *)((int)piVar9 + 1);
    } while (piVar9 < (int *)0x4);
    local_10 = (int *)0x0;
    do {
      if (local_14 != (int *)0x0) goto LAB_0092c773;
      piVar9 = (int *)0x0;
      do {
        piVar5 = local_10;
        piVar10 = local_20;
        if (local_14 != (int *)0x0) break;
        if (((piVar9 != local_10) && (piVar9 != local_20)) && (local_10 != local_20)) {
          local_7c[0] = -1;
          local_7c[1] = -1;
          local_7c[2] = -1;
          local_7c[3] = -1;
          local_7c[4] = 0;
          local_7c[5] = 0;
          local_7c[6] = 0;
          local_7c[7] = 0;
          local_7c[(int)local_10] = 0;
          local_7c[(int)piVar9] = 0;
          local_7c[(int)(piVar5 + 1)] = -1;
          local_7c[(int)(piVar9 + 1)] = -1;
          local_7c[(int)(piVar10 + 1)] = -1;
          piVar10 = (int *)0x0;
          local_8 = (int *)0x0;
          if (local_c != (int *)0x0) {
            local_18 = local_ac;
            do {
              if (local_8 != (int *)0x0) break;
              iVar6 = FUN_0092b84f(local_18,local_7c,5);
              if (iVar6 == 0) {
                local_8 = (int *)0x1;
              }
              local_18 = local_18 + 4;
              piVar10 = (int *)((int)piVar10 + 1);
            } while (piVar10 < local_c);
          }
          if ((local_7c[3] == 0) &&
             ((((local_7c[0] == 0 || (local_7c[1] == 0)) || (local_7c[2] == 0)) &&
              (local_4c[8] != 0)))) {
            local_8 = (int *)0x1;
          }
          if (local_8 == (int *)0x0) {
            local_14 = (int *)0x1;
          }
        }
        piVar9 = (int *)((int)piVar9 + 1);
      } while (piVar9 < (int *)0x4);
      local_10 = (int *)((int)local_10 + 1);
    } while (local_10 < (int *)0x4);
    if (local_14 != (int *)0x0) {
LAB_0092c773:
      iVar6 = FUN_00947586(local_7c,local_c,3);
      if (iVar6 < 0) {
        return iVar6;
      }
      uVar12 = 3;
      goto LAB_0092c78d;
    }
  }
LAB_0092c7a9:
  piVar9 = (int *)0x0;
  if (local_1c != (int *)0x0) {
    do {
      piVar5 = local_c;
      piVar10 = local_1c;
      local_7c[0] = -1;
      local_7c[1] = 0xffffffff;
      local_7c[2] = 0xffffffff;
      local_7c[3] = 0xffffffff;
      local_7c[*(int *)(*(int *)(*(int *)((int)in_ECX + 0x14) +
                                *(int *)(*(int *)(*(int *)((int)in_ECX + 0x100) + 0x10) +
                                        (int)piVar9 * 4) * 4) + 0x10)] = 0;
      iVar6 = FUN_00947586(local_7c,piVar5,piVar10);
      if (iVar6 < 0) {
        return iVar6;
      }
      piVar9 = (int *)((int)piVar9 + 1);
    } while (piVar9 < local_1c);
  }
LAB_0092c802:
  **(undefined4 **)((int)in_ECX + 0x100) = 0;
  return 0;
}


// ==== FUN_0092c82a @ 0x0092c82a ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0092c82a(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  bool bVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 local_128 [16];
  undefined1 local_e8 [16];
  int aiStack_d8 [4];
  int aiStack_c8 [4];
  int aiStack_b8 [4];
  int aiStack_a8 [4];
  int aiStack_98 [4];
  int aiStack_88 [4];
  int aiStack_78 [12];
  undefined4 local_48;
  int local_44 [9];
  int local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  int *local_c;
  int local_8;
  
  if (0x103 < (*(uint *)(in_ECX + 200) & 0xffff)) {
    return 1;
  }
  uVar6 = 0;
  local_1c = 0;
  local_48 = 0;
  local_44[0] = 1;
  local_44[1] = 2;
  local_44[2] = 3;
  local_8 = in_ECX;
  if ((**(uint **)(in_ECX + 0x100) & 0xfffff) == 3) {
    do {
      iVar1 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),(&PTR_DAT_00b59f78)[uVar6],local_128,
                           &local_1c,local_e8,&local_48,3,0);
      if (iVar1 == 0) break;
      uVar6 = uVar6 + 1;
    } while (uVar6 < 9);
    local_14 = 0;
    local_18 = 0;
    if (4 < uVar6) {
      local_18 = 1;
    }
    local_18 = (uint)(4 < uVar6);
    if (iVar1 != 0) {
      uVar6 = 0;
      do {
        iVar1 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),(&PTR_DAT_00b59f9c)[uVar6],local_128,
                             &local_1c,local_e8,&local_48,3,0);
        if (iVar1 == 0) break;
        uVar6 = uVar6 + 1;
      } while (uVar6 < 3);
      local_18 = 0;
      if (1 < uVar6) {
        local_18 = 1;
      }
      local_18 = (uint)(1 < uVar6);
      local_14 = 1;
      if (iVar1 != 0) goto LAB_0092c923;
    }
    local_10 = 0;
    iVar1 = *(int *)(in_ECX + 0x14);
    local_20 = 0xc - (int)(local_44 + 3);
    do {
      iVar3 = aiStack_d8[local_10];
      iVar2 = *(int *)(iVar1 + iVar3 * 4);
      if (*(uint *)(iVar2 + 0x10) != local_10) {
        return 1;
      }
      if (param_1 == 0) {
        if (local_18 == 0) {
          if (*(int *)(iVar2 + 0x48) == -1) {
            return 1;
          }
          piVar5 = *(int **)(*(int *)(local_8 + 0x18) + *(int *)(iVar2 + 0x48) * 4);
          if (*piVar5 != 0x20500003) {
            return 1;
          }
          iVar3 = piVar5[2];
          local_c = *(int **)(local_10 * 4 + iVar3);
          iVar2 = *(int *)(iVar1 + (int)local_c * 4);
          if ((*(byte *)(*(int *)(*(int *)(local_8 + 0x10) + *(int *)(iVar2 + 4) * 4) + 5) & 2) == 0
             ) {
            return 1;
          }
          if (*(uint *)(iVar2 + 0x10) != local_10) {
            return 1;
          }
          piVar4 = local_44 + local_10 + 3;
          iVar1 = *(int *)(iVar1 + *(int *)((0xc - (int)(local_44 + 3)) + iVar3 + (int)piVar4) * 4);
          if ((*(byte *)(*(int *)(*(int *)(local_8 + 0x10) + *(int *)(iVar1 + 4) * 4) + 5) & 1) == 0
             ) {
            return 1;
          }
          if (*(double *)(iVar1 + 0x20) != _DAT_009fd350) {
            return 1;
          }
          *piVar4 = (int)local_c;
        }
        else {
          if ((*(byte *)(*(int *)(*(int *)(local_8 + 0x10) + *(int *)(iVar2 + 4) * 4) + 5) & 2) == 0
             ) {
            return 1;
          }
          piVar4 = local_44 + local_10 + 3;
          *piVar4 = iVar3;
        }
        piVar5 = aiStack_b8 + local_10;
        local_c = (int *)*piVar4;
        if ((*piVar5 != *piVar4) || (iVar3 = aiStack_c8[local_10], aiStack_a8[local_10] != iVar3)) {
LAB_0092cb2a:
          bVar9 = (int *)aiStack_a8[local_10] == local_c;
          goto LAB_0092cb31;
        }
        piVar4 = aiStack_98 + local_10;
        iVar1 = *piVar4;
        if ((iVar1 != aiStack_88[local_10]) || (aiStack_a8[local_10] != iVar1)) goto LAB_0092cb2a;
      }
      else {
        if (*(int *)(iVar2 + 0x48) != -1) {
          return 1;
        }
        if (*(int *)(iVar2 + 4) != *(int *)(local_8 + 0x80)) {
          return 1;
        }
        if ((uint)*(byte *)(iVar2 + 0x6d) != local_10 + 1) {
          return 1;
        }
        if (*(char *)(iVar2 + 0x6c) != '\x05') {
          return 1;
        }
        local_44[local_10 + 3] = iVar3;
        if (local_18 == 0) {
          if (*(int *)(iVar2 + 0x3c) != 0x80000) {
            return 1;
          }
          piVar5 = aiStack_b8 + local_10;
          local_c = (int *)*(int *)(iVar2 + 0x38);
          if ((*piVar5 == *(int *)(iVar2 + 0x38)) &&
             (iVar3 = aiStack_c8[local_10], aiStack_a8[local_10] == iVar3)) {
            piVar4 = aiStack_98 + local_10;
            iVar1 = *piVar4;
            if ((iVar1 == aiStack_88[local_10]) && (aiStack_a8[local_10] == iVar1))
            goto LAB_0092cb4e;
          }
          goto LAB_0092cb2a;
        }
        if (*(int *)(iVar2 + 0x3c) != 0) {
          return 1;
        }
        piVar5 = aiStack_b8 + local_10;
        if (*piVar5 == iVar3) {
          iVar3 = aiStack_c8[local_10];
          if (aiStack_a8[local_10] == iVar3) {
            piVar4 = aiStack_98 + local_10;
            iVar1 = *piVar4;
            if ((iVar1 == aiStack_88[local_10]) && (aiStack_a8[local_10] == iVar1))
            goto LAB_0092cb4e;
          }
        }
        bVar9 = aiStack_a8[local_10] == aiStack_d8[local_10];
LAB_0092cb31:
        if (!bVar9) {
          return 1;
        }
        iVar3 = piVar5[-4];
        if (*piVar5 != iVar3) {
          return 1;
        }
        piVar4 = aiStack_98 + local_10;
        iVar1 = *piVar4;
        if (iVar1 != piVar5[0xc]) {
          return 1;
        }
        if (*piVar5 != iVar1) {
          return 1;
        }
      }
LAB_0092cb4e:
      local_44[local_10 + 6] = iVar3;
      if (((local_14 != 0) && (iVar1 != piVar4[8])) ||
         (iVar1 = *(int *)(local_8 + 0x14),
         *(uint *)(*(int *)(iVar1 + iVar3 * 4) + 0x10) != local_10)) {
        return 1;
      }
      local_10 = local_10 + 1;
    } while (local_10 < 3);
    uVar6 = 0;
    if (local_1c != 0) {
      do {
        puVar7 = local_128 + uVar6;
        uVar6 = uVar6 + 1;
        *(undefined4 *)*puVar7 = 0;
      } while (uVar6 < local_1c);
    }
    iVar1 = FUN_009149f7(0x74);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_0091455d();
    }
    iVar3 = local_8;
    if (iVar1 == 0) {
      local_14 = -0x7ff8fff2;
    }
    else {
      if (param_1 == 0) {
        uVar11 = 9;
        uVar10 = 0x72d00003;
      }
      else {
        uVar11 = 6;
        uVar10 = 0x72c00003;
      }
      iVar2 = FUN_00914a42(uVar10,uVar11,*(undefined4 *)(*(int *)(local_8 + 0x100) + 0xc),0);
      if (iVar2 < 0) {
        FUN_008f4adb(1);
        local_14 = iVar2;
      }
      else {
        local_14 = FUN_00914593(*(undefined4 *)(iVar3 + 0x100));
        if (local_14 < 0) {
          FUN_008f4adb(1);
        }
        else {
          puVar7 = *(undefined4 **)(*(int *)(local_8 + 0x100) + 0x10);
          puVar8 = *(undefined4 **)(iVar1 + 0x10);
          for (uVar6 = *(uint *)(*(int *)(local_8 + 0x100) + 0xc) & 0x3fffffff; uVar6 != 0;
              uVar6 = uVar6 - 1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
            puVar7 = (undefined4 *)((int)puVar7 + 1);
            puVar8 = (undefined4 *)((int)puVar8 + 1);
          }
          uVar6 = 0xc;
          local_c = local_44;
          do {
            *(undefined4 *)((uVar6 - 0xc) + *(int *)(iVar1 + 8)) =
                 **(undefined4 **)(*(int *)(local_8 + 0x100) + 8);
            *(undefined4 *)(uVar6 + *(int *)(iVar1 + 8)) =
                 *(undefined4 *)((int)local_44 + uVar6 + 0xc);
            if (param_1 == 0) {
              *(undefined4 *)(uVar6 + 0xc + *(int *)(iVar1 + 8)) =
                   *(undefined4 *)((int)local_44 + uVar6);
            }
            uVar6 = uVar6 + 4;
          } while (uVar6 < 0x18);
          piVar5 = (int *)(local_8 + 0xfc);
          if (*(int *)(*(int *)(local_8 + 0x18) + *piVar5 * 4) != 0) {
            FUN_008f4adb(1);
          }
          *(int *)(*(int *)(local_8 + 0x18) + *piVar5 * 4) = iVar1;
        }
      }
    }
  }
  else {
LAB_0092c923:
    local_14 = 1;
  }
  return local_14;
}


// ==== FUN_0092ccb7 @ 0x0092ccb7 ====

undefined4 FUN_0092ccb7(void)

{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  int extraout_ECX;
  uint uVar6;
  int *piVar7;
  int iVar8;
  undefined8 uVar9;
  int *local_10;
  int *local_c;
  uint local_8;
  
  local_8 = 0;
  if (*(int *)(in_ECX + 0xc) == 0) {
LAB_0092cdf2:
    local_8 = 0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      local_10 = *(int **)(in_ECX + 0x18);
      do {
        *(uint *)(in_ECX + 0xfc) = local_8;
        piVar3 = (int *)*local_10;
        *(int **)(in_ECX + 0x100) = piVar3;
        if (((piVar3 != (int *)0x0) && (*piVar3 != 0)) && (local_c = (int *)0x0, piVar3[1] != 0)) {
          piVar7 = (int *)piVar3[2];
          do {
            iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar7 * 4);
            if ((*(int *)(iVar4 + 4) == *(int *)(in_ECX + 0x80)) &&
               (*(char *)(iVar4 + 0x6c) == '\x05')) {
              FUN_0091a001(in_ECX,piVar3[0xf],0x11a0,s_cannot_access_w_component_from_t_00a2ab14);
              goto LAB_0092cefc;
            }
            local_c = (int *)((int)local_c + 1);
            piVar7 = piVar7 + 1;
          } while (local_c < *(uint *)(*(int *)(in_ECX + 0x100) + 4));
        }
        local_8 = local_8 + 1;
        local_10 = local_10 + 1;
      } while (local_8 < *(uint *)(in_ECX + 0xc));
    }
    uVar5 = 0;
  }
  else {
    local_c = *(int **)(in_ECX + 0x18);
    while( true ) {
      *(uint *)(in_ECX + 0xfc) = local_8;
      puVar1 = (uint *)*local_c;
      *(uint **)(in_ECX + 0x100) = puVar1;
      if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) break;
LAB_0092cddf:
      local_8 = local_8 + 1;
      local_c = local_c + 1;
      if (*(uint *)(in_ECX + 0xc) <= local_8) goto LAB_0092cdf2;
    }
    uVar2 = *puVar1;
    uVar6 = uVar2 & 0xfff00000;
    if (0x60c00000 < uVar6) {
      if (uVar6 == 0x60d00000) {
        iVar4 = 2;
      }
      else {
        if (uVar6 == 0x61100000) {
          iVar4 = 3;
          goto LAB_0092ce85;
        }
        if (uVar6 != 0x61200000) goto LAB_0092cd90;
        iVar4 = 3;
      }
      goto LAB_0092ce8d;
    }
    if (uVar6 == 0x60c00000) {
      iVar4 = 2;
LAB_0092ce85:
      iVar8 = 1;
    }
    else {
      if (uVar6 == 0x60200000) {
        iVar4 = 0;
        goto LAB_0092ce85;
      }
      if (uVar6 != 0x60300000) {
        if (uVar6 == 0x60700000) {
          if ((*(uint *)(in_ECX + 200) & 0xffff) != 0x104) {
            iVar8 = 1;
            iVar4 = 1;
            goto LAB_0092ce8f;
          }
        }
        else if (uVar6 == 0x60800000) {
          iVar4 = 1;
          goto LAB_0092ce8d;
        }
LAB_0092cd90:
        uVar9 = FUN_0092a852(uVar6);
        iVar4 = (int)((ulonglong)uVar9 >> 0x20);
        in_ECX = extraout_ECX;
        if (((((int)uVar9 == 0) && (iVar4 != 0x11000000)) ||
            (iVar4 = *(int *)(*(int *)(extraout_ECX + 0x14) +
                             *(int *)(puVar1[2] +
                                     (-(uint)(iVar4 != 0x11000000) & uVar2 & 0xfffff) * 4) * 4),
            *(int *)(iVar4 + 0x3c) == 0)) ||
           (((*(uint *)(extraout_ECX + 200) & 0xffff) == 0x104 ||
            ((*(byte *)(*(int *)(*(int *)(extraout_ECX + 0x10) + *(int *)(iVar4 + 4) * 4) + 4) &
             0x10) == 0)))) goto LAB_0092cddf;
        FUN_0091a001(extraout_ECX,puVar1[0xf],0x11b4,s_dependent_texture_read_not_suppo_00a2ab54,
                     *(uint *)(extraout_ECX + 200) & 0xff);
        goto LAB_0092cefc;
      }
      iVar4 = 0;
LAB_0092ce8d:
      iVar8 = 0;
    }
LAB_0092ce8f:
    FUN_0091a001(in_ECX,puVar1[0xf],0x11b4,s__s_s_is_not_supported_on_ps_1__i_00a2ab84,
                 (&PTR_s_tex1D_00b5a048)[iVar4],(&PTR_DAT_00b5a058)[iVar8],
                 *(uint *)(in_ECX + 200) & 0xff);
LAB_0092cefc:
    uVar5 = 0x80004005;
  }
  return uVar5;
}


// ==== FUN_0092cf06 @ 0x0092cf06 ====

int * FUN_0092cf06(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *in_ECX;
  uint uVar6;
  int local_10c [4];
  int local_fc [4];
  undefined4 auStack_ec [32];
  undefined4 local_6c [16];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  int local_10;
  uint local_c;
  int *local_8;
  
  local_14 = 0;
  local_2c = 0;
  local_28 = 1;
  local_24 = 2;
  local_20 = 3;
  uVar6 = *(uint *)in_ECX[0x40] & 0xfffff;
  local_c = 0;
  iVar2 = FUN_0093d430((uint *)in_ECX[0x40],&DAT_00a29c48,local_6c,&local_14,local_10c,&local_2c,
                       uVar6,0);
  if (iVar2 == 0) {
LAB_0092cfa0:
    local_1c = 0;
    if (local_c != 0) {
      uVar3 = *(uint *)(*(int *)(in_ECX[4] + *(int *)(*(int *)(in_ECX[5] + local_fc[0] * 4) + 4) * 4
                                ) + 4);
      local_1c = (uint)((uVar3 & 0x200) != 0);
      if (((*(uint *)(*(int *)(in_ECX[4] + *(int *)(*(int *)(in_ECX[5] + local_10c[0] * 4) + 4) * 4)
                     + 4) & 0x300) != 0) && ((uVar3 & 0x300) != 0)) {
        return (int *)0x1;
      }
    }
    iVar2 = FUN_009149f7(0x74);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_0091455d();
    }
    if (iVar2 == 0) {
      return (int *)0x8007000e;
    }
    if (local_c == 0) {
      uVar3 = uVar6 | 0x70300000;
    }
    else {
      uVar3 = uVar6 | 0x70400000;
    }
    local_8 = (int *)FUN_00914a42(uVar3,uVar6 * 3,uVar6,0);
    if (((int)local_8 < 0) || (local_8 = (int *)FUN_00914593(in_ECX[0x40]), (int)local_8 < 0))
    goto LAB_0092d13b;
    local_c = 0;
    if (uVar6 != 0) {
      local_18 = uVar6 << 3;
      local_10 = uVar6 << 2;
      do {
        uVar3 = local_c;
        iVar1 = local_10;
        iVar5 = local_18;
        iVar4 = local_c * 4;
        *(undefined4 *)(iVar4 + *(int *)(iVar2 + 0x10)) =
             *(undefined4 *)(iVar4 + *(int *)(in_ECX[0x40] + 0x10));
        local_8 = local_fc + local_c;
        if (local_1c == 0) {
          *(int *)(iVar4 + *(int *)(iVar2 + 8)) = local_10c[local_c];
          iVar4 = *local_8;
        }
        else {
          *(int *)(iVar4 + *(int *)(iVar2 + 8)) = *local_8;
          iVar4 = local_10c[local_c];
        }
        local_c = local_c + 1;
        local_10 = local_10 + 4;
        *(int *)(iVar1 + *(int *)(iVar2 + 8)) = iVar4;
        local_18 = local_18 + 4;
        *(undefined4 *)(iVar5 + *(int *)(iVar2 + 8)) = auStack_ec[uVar3];
      } while (local_c < uVar6);
    }
    iVar5 = (**(code **)(*in_ECX + 0x20))(iVar2,0);
    if (iVar5 != 0) {
      local_8 = (int *)0x1;
      goto LAB_0092d13b;
    }
    uVar6 = 0;
    if (local_14 != 0) {
      do {
        *(undefined4 *)local_6c[uVar6] = 0;
        uVar6 = uVar6 + 1;
      } while (uVar6 < local_14);
    }
    if (in_ECX[0x40] != 0) {
      FUN_008f4adb(1);
    }
    *(int *)(in_ECX[6] + in_ECX[0x3f] * 4) = iVar2;
  }
  else {
    iVar2 = FUN_0093d430(in_ECX[0x40],&DAT_00a29ca8,local_6c,&local_14,local_10c,&local_2c,uVar6,0);
    local_c = 1;
    if (iVar2 == 0) goto LAB_0092cfa0;
  }
  iVar2 = 0;
  local_8 = (int *)0x0;
LAB_0092d13b:
  if (iVar2 != 0) {
    FUN_008f4adb(1);
  }
  return local_8;
}


// ==== FUN_0092d150 @ 0x0092d150 ====

undefined4 FUN_0092d150(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if ((*(uint *)(param_1 + 0x1c) & 7) == 0) {
    puVar1 = (undefined4 *)FUN_009149da(*(uint *)(param_1 + 0x1c) + 8);
    if (puVar1 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
    puVar4 = *(undefined4 **)(param_1 + 0x20);
    puVar5 = puVar1;
    for (uVar2 = *(uint *)(param_1 + 0x1c) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    *(undefined4 **)(param_1 + 0x20) = puVar1;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x1c) * 4) = param_2;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  return 0;
}


// ==== FUN_0092d1aa @ 0x0092d1aa ====

int FUN_0092d1aa(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int local_414 [256];
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  uVar5 = 0;
  if (param_2 != 0) {
    do {
      iVar1 = *(int *)(param_1 + uVar5 * 4);
      if (iVar1 != 0) {
        uVar4 = 0;
        if (*(int *)(iVar1 + 0xc) != 0) {
          do {
            iVar2 = uVar4 * 4;
            uVar4 = uVar4 + 1;
            *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) +
                              *(int *)(*(int *)(iVar1 + 0x10) + iVar2) * 4) + 0x48) = uVar5;
          } while (uVar4 < *(uint *)(iVar1 + 0xc));
        }
        *(undefined4 *)(iVar1 + 0x1c) = 0;
        *(undefined4 *)(iVar1 + 0x14) = 0;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < param_2);
  }
  uVar5 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + uVar5 * 4);
      iVar2 = *(int *)(iVar1 + 0x38);
      if (iVar2 != -1) {
        *(undefined4 *)(iVar1 + 0x48) =
             *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar2 * 4) + 0x48);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(in_ECX + 8));
  }
  local_8 = 0;
  local_14 = in_ECX;
  if (param_2 != 0) {
    do {
      iVar1 = *(int *)(param_1 + local_8 * 4);
      uVar5 = 0;
      if (iVar1 != 0) {
        local_10 = 0;
        local_c = 0;
        if (*(int *)(iVar1 + 4) != 0) {
          do {
            iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                     *(int *)(*(int *)(iVar1 + 8) + local_c * 4) * 4) + 0x48);
            if (iVar2 != -1) {
              uVar4 = 0;
              if (uVar5 != 0) {
                do {
                  if (local_414[uVar4] == iVar2) break;
                  uVar4 = uVar4 + 1;
                } while (uVar4 < uVar5);
              }
              if (uVar4 == uVar5) {
                local_414[uVar5] = iVar2;
                uVar5 = uVar5 + 1;
                local_10 = uVar5;
              }
              iVar2 = FUN_0092d150(*(undefined4 *)(param_1 + iVar2 * 4),local_8);
              if (iVar2 < 0) {
                return iVar2;
              }
            }
            local_c = local_c + 1;
          } while (local_c < *(uint *)(iVar1 + 4));
        }
        piVar3 = (int *)FUN_009149da(uVar5);
        *(int **)(iVar1 + 0x18) = piVar3;
        if (piVar3 == (int *)0x0) {
          return -0x7ff8fff2;
        }
        piVar6 = local_414;
        for (; uVar5 != 0; uVar5 = uVar5 - 1) {
          *piVar3 = *piVar6;
          piVar6 = piVar6 + 1;
          piVar3 = piVar3 + 1;
        }
        *(uint *)(iVar1 + 0x14) = local_10;
        in_ECX = local_14;
      }
      local_8 = local_8 + 1;
    } while (local_8 < param_2);
  }
  return 0;
}


// ==== FUN_0092d2e2 @ 0x0092d2e2 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0092d2e2(void)

{
  int *piVar1;
  uint *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  float fVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  int in_ECX;
  int *piVar11;
  uint *puVar12;
  uint *puVar13;
  uint uVar14;
  undefined4 *puVar15;
  uint uVar16;
  uint local_94 [16];
  int aiStack_54 [4];
  uint local_44 [4];
  int *local_34;
  uint local_30;
  uint local_2c;
  int *local_28;
  float local_24;
  uint local_20;
  uint *local_1c;
  int *local_18;
  undefined4 local_14;
  uint *local_10;
  int *local_c;
  undefined4 *local_8;
  
  local_20 = 0;
  local_14 = 0;
  piVar3 = (int *)(*(uint **)(in_ECX + 0x100))[2];
  uVar14 = **(uint **)(in_ECX + 0x100) & 0xfffff;
  iVar9 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar3 * 4);
  piVar1 = piVar3 + uVar14;
  iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar1 * 4);
  iVar5 = *(int *)(in_ECX + 0x88);
  if (((*(int *)(iVar9 + 4) == iVar5) &&
      ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar4 + 4) * 4) + 5) & 1) != 0)) &&
     ((**(uint **)(in_ECX + 0x100) & 0xfff00000) == 0x20500000)) {
    local_18 = piVar3;
    local_28 = piVar1;
  }
  else {
    if (((*(int *)(iVar4 + 4) != iVar5) ||
        ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar9 + 4) * 4) + 5) & 1) == 0)) ||
       ((**(uint **)(in_ECX + 0x100) & 0xfff00000) != 0x20500000)) {
      if (*(int *)(iVar9 + 4) != iVar5) {
        return 1;
      }
      if (*(int *)(iVar4 + 4) != iVar5) {
        return 1;
      }
      if ((**(uint **)(in_ECX + 0x100) & 0xfff00000) != 0x20400000) {
        return 1;
      }
      local_14 = 1;
      if (uVar14 != 0) {
        piVar11 = piVar3;
        local_10 = (uint *)uVar14;
        do {
          if (*piVar11 != *(int *)(((int)piVar1 - (int)piVar3) + (int)piVar11)) {
            local_14 = 0;
          }
          piVar11 = piVar11 + 1;
          local_10 = (uint *)((int)local_10 - 1);
        } while (local_10 != (uint *)0x0);
      }
      uVar8 = *(uint *)(iVar9 + 0x3c);
      if (uVar8 != *(uint *)(iVar4 + 0x3c)) {
        return 1;
      }
      if (uVar8 == 0x80000) {
        local_24 = DAT_0099d0dc;
      }
      else {
        if ((uVar8 & 0x80000) != 0) {
          return 1;
        }
        local_24 = 1.0;
      }
      local_18 = piVar3;
      if (local_14 == 0) {
        return 1;
      }
      local_24 = local_24 + local_24;
      goto LAB_0092d370;
    }
    local_18 = piVar1;
    local_28 = piVar3;
  }
  local_24 = (float)*(double *)(*(int *)(*(int *)(in_ECX + 0x14) + *local_28 * 4) + 0x20);
LAB_0092d370:
  local_8 = (undefined4 *)0x0;
  if (uVar14 != 0) {
    iVar9 = *(int *)(in_ECX + 0x14);
    local_c = local_28;
    local_1c = (uint *)((int)local_18 - (int)local_28);
    do {
      uVar8 = local_20;
      iVar4 = *(int *)(iVar9 + *(int *)((int)local_1c + (int)local_c) * 4);
      uVar16 = 0;
      if (local_14 == 0) {
        local_10 = (uint *)*(int *)(iVar9 + *local_c * 4);
      }
      else {
        local_10 = (uint *)0x0;
      }
      if (*(int *)(iVar4 + 0x58) != *(int *)(in_ECX + 0xfc)) {
        return 1;
      }
      if (*(int *)(iVar4 + 0x54) != *(int *)(in_ECX + 0xfc)) {
        return 1;
      }
      if ((*(uint *)(iVar4 + 0x3c) & 0x1ffe00) != 0) {
        return 1;
      }
      if (local_20 != 0) {
        do {
          if (*(int *)(iVar4 + 0x48) == aiStack_54[uVar16]) break;
          uVar16 = uVar16 + 1;
        } while (uVar16 < local_20);
      }
      if (uVar16 == local_20) {
        local_20 = local_20 + 1;
        aiStack_54[uVar8] = *(int *)(iVar4 + 0x48);
      }
      if ((local_14 == 0) && ((double)local_24 != *(double *)((int)local_10 + 0x20))) {
        return 1;
      }
      local_8 = (undefined4 *)((int)local_8 + 1);
      local_c = local_c + 1;
    } while (local_8 < uVar14);
  }
  fVar7 = ABS(local_24);
  if (((((float)_DAT_00a0b350 != ABS(fVar7)) ||
       (uVar8 = 0x400, (*(uint *)(in_ECX + 0x6c) & 0x400) == 0)) &&
      (((fVar7 != (float)_DAT_00a2abb0 || (uVar8 = 0x800, (*(uint *)(in_ECX + 0x6c) & 0x800) == 0))
       && ((fVar7 != (float)_DAT_00a24b70 ||
           (uVar8 = 0x1000, (*(uint *)(in_ECX + 0x6c) & 0x1000) == 0)))))) &&
     (((fVar7 != (float)_DAT_00a011c0 || (uVar8 = 0x2000, (*(uint *)(in_ECX + 0x6c) & 0x2000) == 0))
      && (((fVar7 != (float)_DAT_00a255d8 ||
           (uVar8 = 0x4000, (*(uint *)(in_ECX + 0x6c) & 0x4000) == 0)) &&
          ((fVar7 != (float)_DAT_00a2aba8 ||
           (uVar8 = 0x8000, (*(uint *)(in_ECX + 0x6c) & 0x8000) == 0)))))))) {
    return 1;
  }
  local_14 = uVar8;
  if (local_24 < DAT_0099cdc8) {
    local_14 = (uint)CONCAT12(8,(short)uVar8);
  }
  local_44[0] = 0;
  local_44[1] = 0;
  local_44[2] = 0;
  local_44[3] = 0;
  local_c = (int *)0x0;
  if (local_20 != 0) {
    local_1c = local_94;
    local_10 = (uint *)0x0;
    do {
      puVar12 = local_1c;
      puVar13 = *(uint **)(*(int *)(in_ECX + 0x18) + aiStack_54[(int)local_c] * 4);
      if ((*puVar13 & 0xf0000000) == 0x60000000) {
        return 1;
      }
      if ((*puVar13 & 0xff000000) == 0x72000000) {
        return 1;
      }
      local_30 = 0;
      local_8 = (undefined4 *)0x0;
      uVar8 = puVar13[3];
      puVar2 = local_1c + 1;
      *local_1c = 0xffffffff;
      *puVar2 = 0xffffffff;
      puVar12[2] = 0xffffffff;
      puVar12[3] = 0xffffffff;
      if (uVar14 != 0) {
        do {
          local_2c = 0;
          if (uVar8 != 0) {
            local_28 = (int *)local_18[(int)local_8];
            local_34 = (int *)puVar13[4];
            puVar12 = (uint *)((int)local_94 + (int)local_10);
            do {
              puVar15 = local_8;
              if ((int *)*local_34 == local_28) {
                local_44[(int)local_c] = local_44[(int)local_c] + 1;
                iVar9 = *(int *)(*(int *)(in_ECX + 0x100) + 0x10);
                *puVar12 = (uint)puVar15;
                if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                        *(int *)(iVar9 + (int)puVar15 * 4) * 4) + 0x3d) & 2) != 0)
                   && (local_24 < DAT_0099cdc8)) {
                  return 1;
                }
                local_30 = local_30 + 1;
              }
              local_2c = local_2c + 1;
              uVar8 = puVar13[3];
              local_34 = local_34 + 1;
              puVar12 = puVar12 + 1;
            } while (local_2c < uVar8);
          }
          local_8 = (undefined4 *)((int)local_8 + 1);
        } while (local_8 < uVar14);
      }
      if (local_30 != uVar8) {
        return 1;
      }
      local_c = (int *)((int)local_c + 1);
      local_1c = local_1c + 4;
      local_10 = (uint *)((int)local_10 + 0x10);
    } while (local_c < local_20);
  }
  local_10 = (uint *)0x0;
  if (local_20 != 0) {
    local_1c = local_94;
    do {
      uVar14 = local_44[(int)local_10];
      puVar15 = *(undefined4 **)(aiStack_54[(int)local_10] * 4 + *(int *)(in_ECX + 0x18));
      local_28 = (int *)(aiStack_54[(int)local_10] * 4);
      local_18 = puVar15;
      puVar13 = local_10;
      if (uVar14 != puVar15[3]) {
        iVar9 = FUN_009149f7(0x74);
        if (iVar9 == 0) {
          local_8 = (undefined4 *)0x0;
        }
        else {
          local_8 = (undefined4 *)FUN_0091455d();
        }
        if (local_8 == (undefined4 *)0x0) {
          return -0x7ff8fff2;
        }
        iVar9 = FUN_00914a42(*puVar15,puVar15[1],uVar14,0);
        if (iVar9 < 0) {
          FUN_008f4adb(1);
          return iVar9;
        }
        iVar9 = FUN_00914593(puVar15);
        if (iVar9 < 0) {
          FUN_008f4adb(1);
          return iVar9;
        }
        puVar15 = (undefined4 *)local_18[2];
        puVar10 = (undefined4 *)local_8[2];
        for (uVar14 = local_18[1] & 0x3fffffff; uVar14 != 0; uVar14 = uVar14 - 1) {
          *puVar10 = *puVar15;
          puVar15 = puVar15 + 1;
          puVar10 = puVar10 + 1;
        }
        for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
          *(undefined1 *)puVar10 = *(undefined1 *)puVar15;
          puVar15 = (undefined4 *)((int)puVar15 + 1);
          puVar10 = (undefined4 *)((int)puVar10 + 1);
        }
        FUN_008f4adb(1);
        *(undefined4 **)((int)local_28 + *(int *)(in_ECX + 0x18)) = local_8;
        local_18 = local_8;
        puVar13 = local_10;
        puVar15 = local_8;
      }
      local_8 = (undefined4 *)0x0;
      if (local_44[(int)puVar13] != 0) {
        local_10 = local_1c;
        do {
          puVar10 = local_8;
          if (local_8 < 4) {
            puVar12 = local_10;
            do {
              if (*puVar12 != 0xffffffff) break;
              puVar10 = (undefined4 *)((int)puVar10 + 1);
              puVar12 = puVar12 + 1;
            } while (puVar10 < 4);
          }
          local_c = (int *)0x0;
          iVar9 = local_94[(int)puVar10 + (int)puVar13 * 4] * 4;
          *(undefined4 *)(puVar15[4] + (int)local_8 * 4) =
               *(undefined4 *)(iVar9 + *(int *)(*(int *)(in_ECX + 0x100) + 0x10));
          puVar12 = (uint *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                     *(int *)(iVar9 + *(int *)(*(int *)(in_ECX + 0x100) + 0x10)) * 4
                                     ) + 0x3c);
          *puVar12 = *puVar12 | local_14;
          if (*(int *)(in_ECX + 8) != 0) {
            do {
              iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + (int)local_c * 4);
              if (*(int *)(iVar4 + 0x38) ==
                  *(int *)(iVar9 + *(int *)(*(int *)(in_ECX + 0x100) + 0x10))) {
                bVar6 = local_24 < DAT_0099cdc8;
                *(uint *)(iVar4 + 0x3c) = *(uint *)(iVar4 + 0x3c) | local_14 & 0xfff7ffff;
                uVar14 = *(uint *)(iVar4 + 0x3c);
                if (bVar6) {
                  if ((uVar14 & 0x80000) == 0) {
                    uVar14 = uVar14 | 0x80000;
                  }
                  else {
                    uVar14 = uVar14 & 0xfff7ffff;
                  }
                  *(uint *)(iVar4 + 0x3c) = uVar14;
                }
              }
              local_c = (int *)((int)local_c + 1);
            } while (local_c < *(uint *)(in_ECX + 8));
          }
          local_10 = local_10 + 1;
          local_8 = (undefined4 *)((int)local_8 + 1);
        } while (local_8 < local_44[(int)puVar13]);
      }
      local_1c = local_1c + 4;
      local_10 = (uint *)((int)puVar13 + 1U);
    } while ((int)puVar13 + 1U < local_20);
  }
  **(undefined4 **)(in_ECX + 0x100) = 0;
  return 0;
}


// ==== FUN_0092d8b9 @ 0x0092d8b9 ====

undefined4 FUN_0092d8b9(int param_1,uint param_2,uint param_3,uint param_4,uint param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int extraout_ECX;
  uint uVar5;
  undefined8 uVar6;
  uint local_14;
  int local_10;
  uint local_8;
  
  local_14 = 0;
  if (param_2 != 0) {
    do {
      piVar1 = *(int **)(param_1 + local_14 * 4);
      if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
        uVar6 = FUN_0092a852();
        iVar4 = (int)((ulonglong)uVar6 >> 0x20);
        local_10 = (int)uVar6;
        if (extraout_ECX == 0x11000000) {
          local_10 = 1;
        }
        local_8 = 0;
        if (piVar1[1] != 0) {
          do {
            uVar5 = 0;
            iVar2 = *(int *)(*(int *)(iVar4 + 0x14) + *(int *)(piVar1[2] + local_8 * 4) * 4);
            if ((((*(int *)(iVar2 + 4) == *(int *)(iVar4 + 0x80)) &&
                 ((*(uint *)(iVar2 + 0x6c) & 0xff) == param_3)) &&
                (param_4 == *(byte *)(iVar2 + 0x6d))) &&
               ((local_10 == 0 || (*(int *)(iVar2 + 0x3c) != 0)))) {
              if (param_5 != 0) {
                do {
                  if (*(int *)(iVar2 + 0x10) ==
                      *(int *)(*(int *)(*(int *)(iVar4 + 0x14) + *(int *)(param_6 + uVar5 * 4) * 4)
                              + 0x10)) {
                    iVar4 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0,*(int *)(iVar2 + 0x10),0);
                    if (iVar4 == -1) {
                      return 0x8007000e;
                    }
                    iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4);
                    *(undefined4 *)(iVar3 + 0x3c) = *(undefined4 *)(iVar2 + 0x3c);
                    *(undefined4 *)(iVar3 + 0x38) = *(undefined4 *)(param_6 + uVar5 * 4);
                    *(int *)(piVar1[2] + local_8 * 4) = iVar4;
                    break;
                  }
                  uVar5 = uVar5 + 1;
                } while (uVar5 < param_5);
              }
              if (uVar5 == param_5) {
                FUN_0091a001(in_ECX,0,0x12c1,s__internal_error__InputRemap_comp_00a2abb7 + 1);
                return 0x80004005;
              }
              iVar4 = in_ECX;
            }
            local_8 = local_8 + 1;
          } while (local_8 < (uint)piVar1[1]);
        }
      }
      local_14 = local_14 + 1;
    } while (local_14 < param_2);
  }
  return 0;
}


// ==== FUN_0092da10 @ 0x0092da10 ====

undefined4 FUN_0092da10(int param_1,uint param_2,uint param_3,uint param_4,uint param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_10 = 0;
  if (param_2 != 0) {
    do {
      iVar1 = *(int *)(param_1 + local_10 * 4);
      if ((iVar1 != 0) && (local_c = 0, *(int *)(iVar1 + 4) != 0)) {
        do {
          iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(*(int *)(iVar1 + 8) + local_c * 4) * 4
                          );
          if ((*(int *)(iVar2 + 4) == *(int *)(in_ECX + 0x80)) &&
             (((*(int *)(iVar2 + 0x3c) != 0 && ((*(uint *)(iVar2 + 0x6c) & 0xff) == param_3)) &&
              (param_4 == *(byte *)(iVar2 + 0x6d))))) {
            local_8 = 0;
            if (param_5 != 0) {
              do {
                if (*(int *)(iVar2 + 0x10) ==
                    *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(param_6 + local_8 * 4) * 4)
                            + 0x10)) {
                  iVar4 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0,*(int *)(iVar2 + 0x10),0);
                  if (iVar4 == -1) {
                    return 0x8007000e;
                  }
                  iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4);
                  *(undefined4 *)(iVar3 + 0x3c) = *(undefined4 *)(iVar2 + 0x3c);
                  *(undefined4 *)(iVar3 + 0x38) = *(undefined4 *)(param_6 + local_8 * 4);
                  *(int *)(*(int *)(iVar1 + 8) + local_c * 4) = iVar4;
                  break;
                }
                local_8 = local_8 + 1;
              } while (local_8 < param_5);
            }
            if (local_8 == param_5) {
              FUN_0091a001();
              return 0x80004005;
            }
          }
          local_c = local_c + 1;
        } while (local_c < *(uint *)(iVar1 + 4));
      }
      local_10 = local_10 + 1;
    } while (local_10 < param_2);
  }
  return 0;
}


// ==== FUN_0092db3f @ 0x0092db3f ====

int FUN_0092db3f(int param_1,uint param_2,int param_3,int *param_4)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_8 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_8 * 4);
      if (((puVar1 != (uint *)0x0) && (puVar1[9] != 1)) && (*puVar1 != 0)) {
        bVar4 = false;
        local_10 = 0;
        if (puVar1[3] != 0) {
          do {
            local_c = 0;
            if (param_2 != 0) {
              do {
                iVar5 = *(int *)(param_1 + local_c * 4);
                iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + iVar5 * 4);
                if ((*(int *)(iVar2 + 4) == *(int *)(in_ECX + 0x80)) &&
                   (*(char *)(iVar2 + 0x6c) != '\x03')) goto LAB_0092dd1c;
                iVar3 = *(int *)(puVar1[4] + local_10 * 4);
                if ((iVar3 == iVar5) || (iVar3 == *(int *)(iVar2 + 0x38))) {
                  uVar6 = puVar1[1];
                  uVar8 = *puVar1 & 0xfffff;
                  local_18 = 0;
                  if (uVar6 / uVar8 != 0) {
                    local_14 = 0;
                    do {
                      iVar5 = FUN_0092db3f(puVar1[2] + local_14,uVar8,param_3,param_4);
                      if (iVar5 < 0) {
                        return iVar5;
                      }
                      local_18 = local_18 + 1;
                      local_14 = local_14 + uVar8 * 4;
                      bVar4 = true;
                    } while (local_18 < uVar6 / uVar8);
                  }
                }
                local_c = local_c + 1;
              } while (local_c < param_2);
            }
            local_10 = local_10 + 1;
          } while (local_10 < puVar1[3]);
          if (bVar4) {
            uVar6 = *puVar1 & 0xfff00000;
            if ((((uVar6 == 0x60000000) || (uVar6 == 0x60500000)) ||
                ((uVar6 == 0x60a00000 ||
                 ((((uVar6 == 0x60f00000 || (uVar6 == 0x72e00000)) || (uVar6 == 0x60700000)) ||
                  ((uVar6 == 0x72c00000 || (uVar6 == 0x72d00000)))))))) || (uVar6 == 0x11000000)) {
              uVar8 = *puVar1 & 0xfffff;
              uVar6 = uVar8 * 2;
              if (uVar8 < uVar6) {
                piVar7 = (int *)(puVar1[2] + uVar8 * 4);
                do {
                  if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar7 * 4) + 4) ==
                      *(int *)(in_ECX + 0x88)) {
LAB_0092dd1c:
                    FUN_0091a001();
                    return -0x7fffbffb;
                  }
                  uVar8 = uVar8 + 1;
                  piVar7 = piVar7 + 1;
                } while (uVar8 < uVar6);
              }
            }
            *(uint **)(param_3 + *param_4 * 4) = puVar1;
            *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x18) + local_8 * 4) + 0x24) = 1;
            *param_4 = *param_4 + 1;
          }
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(in_ECX + 0xc));
  }
  return 0;
}


// ==== FUN_0092dd2f @ 0x0092dd2f ====

int FUN_0092dd2f(int param_1,int *param_2,int param_3,uint param_4,uint param_5,int *param_6)

{
  uint *puVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  bool bVar9;
  uint local_4c [6];
  int aiStack_34 [4];
  int local_24 [4];
  undefined4 *local_14;
  int *local_10;
  undefined4 *local_c;
  uint local_8;
  
  local_8 = 0;
  puVar3 = local_4c;
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  if (param_4 + (int)param_6 != 0) {
    local_10 = (int *)(param_5 + param_4 * -4);
    do {
      if (local_8 < param_4) {
        puVar3 = *(uint **)(param_3 + local_8 * 4);
      }
      else {
        puVar3 = (uint *)*local_10;
      }
      if ((((puVar3 != (uint *)0x0) && (uVar6 = *puVar3 & 0xfff00000, uVar6 != 0)) &&
          (puVar3[9] != 1)) &&
         ((((((uVar6 != 0x60000000 && (uVar6 != 0x60500000)) &&
             ((uVar6 != 0x60a00000 && ((uVar6 != 0x60f00000 && (uVar6 != 0x11000000)))))) &&
            (uVar6 != 0x72c00000)) && (uVar6 != 0x72d00000)) || (param_4 <= local_8)))) {
        local_14 = (undefined4 *)puVar3[1];
        local_c = (undefined4 *)0x0;
        if (local_14 != (undefined4 *)0x0) {
          piVar8 = (int *)puVar3[2];
          do {
            iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar8 * 4);
            if (*(int *)(iVar5 + 4) == *(int *)(in_ECX + 0x80)) {
              if (5 < *(byte *)(iVar5 + 0x6d)) break;
              if (*(char *)(iVar5 + 0x6c) == '\x03') {
                puVar3 = local_4c + *(byte *)(iVar5 + 0x6d);
                if (local_8 < param_4) {
                  uVar6 = *(int *)(iVar5 + 0x10) + 1;
                  if (*puVar3 < uVar6) {
                    *puVar3 = uVar6;
                  }
                }
                else {
                  uVar6 = *(int *)(iVar5 + 0x10) + 1;
                  if ((*puVar3 < uVar6) && (*(int *)(iVar5 + 0x3c) != 0)) {
                    *puVar3 = uVar6;
                  }
                }
              }
            }
            local_c = (undefined4 *)((int)local_c + 1);
            piVar8 = piVar8 + 1;
          } while (local_c < local_14);
        }
      }
      local_8 = local_8 + 1;
      local_10 = local_10 + 1;
    } while (local_8 < param_4 + (int)param_6);
  }
  local_8 = 0;
  if (*(int *)(in_ECX + 0x3c) != 0) {
    puVar3 = local_4c;
    local_14 = (undefined4 *)(param_1 - (int)puVar3);
    do {
      uVar6 = *puVar3;
      if (uVar6 != 0) {
        iVar5 = FUN_009149f7();
        if (iVar5 == 0) {
          local_c = (undefined4 *)0x0;
        }
        else {
          local_c = (undefined4 *)FUN_0091455d();
        }
        if (local_c == (undefined4 *)0x0) {
          return -0x7ff8fff2;
        }
        iVar5 = FUN_00914a42(uVar6 & 0xfffff | 0x72100000,uVar6,uVar6,0);
        if (iVar5 < 0) goto LAB_0092e02a;
        uVar6 = 0;
        if (*puVar3 != 0) {
          do {
            iVar5 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),local_8,uVar6,0);
            local_24[uVar6] = iVar5;
            if (iVar5 == -1) goto LAB_0092dffd;
            *(int *)(local_c[4] + uVar6 * 4) = iVar5;
            iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + iVar5 * 4);
            *(undefined4 *)(iVar5 + 0x3c) = 0;
            *(undefined4 *)(iVar5 + 0x38) = 0xffffffff;
            uVar6 = uVar6 + 1;
            uVar4 = *puVar3;
            *(uint *)(iVar5 + 0x6c) = local_8 << 8 | 3;
          } while (uVar6 < uVar4);
        }
        uVar6 = *puVar3;
        iVar5 = FUN_0092d8b9(param_3,param_4,3,local_8,uVar6,local_24);
        if ((iVar5 < 0) ||
           (iVar5 = FUN_0092da10(param_5,param_6,3,local_8,uVar6,local_24), iVar5 < 0))
        goto LAB_0092e02a;
        uVar6 = 0;
        if (*puVar3 != 0) {
          do {
            iVar5 = FUN_00915318(*(undefined4 *)(in_ECX + 0x80),local_8,uVar6,0);
            aiStack_34[uVar6] = iVar5;
            if (iVar5 == -1) goto LAB_0092dffd;
            iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + iVar5 * 4);
            *(undefined4 *)(iVar7 + 0x3c) = 0;
            *(uint *)(iVar7 + 0x6c) = local_8 << 8 | 3;
            *(int *)(local_c[2] + uVar6 * 4) = iVar5;
            uVar6 = uVar6 + 1;
          } while (uVar6 < *puVar3);
        }
        puVar1 = (uint *)((int)local_14 + (int)puVar3);
        if (*puVar1 != 0) {
          FUN_0091a001();
          iVar5 = -0x7fffbffb;
          goto LAB_0092e02a;
        }
        iVar5 = FUN_00915205();
        if (iVar5 < 0) {
          return iVar5;
        }
        *puVar1 = (uint)local_c;
      }
      local_8 = local_8 + 1;
      puVar3 = puVar3 + 1;
    } while (local_8 < *(uint *)(in_ECX + 0x3c));
  }
  param_5 = 1;
  do {
    local_8 = 0;
    if (param_4 != 0) {
      local_c = (undefined4 *)(param_3 + param_4 * -4);
      do {
        if (0x1ff < local_8) goto LAB_0092e44f;
        if (local_8 < param_4) {
          puVar3 = *(uint **)(param_3 + local_8 * 4);
        }
        else {
          puVar3 = (uint *)*local_c;
        }
        if ((puVar3 != (uint *)0x0) && (puVar3[9] != 1)) {
          uVar6 = *puVar3 & 0xfff00000;
          if ((((uVar6 == 0x60000000) ||
               (((uVar6 == 0x60500000 || (uVar6 == 0x60a00000)) || (uVar6 == 0x60f00000)))) ||
              (((uVar6 == 0x72e00000 || (uVar6 == 0x60700000)) || (uVar6 == 0x11000000)))) ||
             ((uVar6 == 0x72c00000 || (uVar6 == 0x72d00000)))) {
            uVar4 = *puVar3 & 0xfffff;
            if (uVar6 == 0x11000000) {
              uVar4 = 0;
            }
            iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + ((int *)puVar3[2])[uVar4] * 4);
            iVar7 = 0;
            if (uVar4 != 0) {
              iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar3[2] * 4);
            }
            local_14 = *(undefined4 **)(iVar5 + 4);
            if (((local_14 == *(undefined4 **)(in_ECX + 0x80)) &&
                ((*(uint *)(in_ECX + 200) & 0xffff) != 0x104)) && (param_5 == 1)) {
              uVar6 = (uint)*(byte *)(iVar5 + 0x6d);
              if (5 < uVar6) break;
              if (iVar7 != 0) {
                if ((*(ushort *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4) + 4) &
                    0x840) == 0) {
                  *(uint *)(iVar7 + 0xc) = uVar6;
                }
                else if (uVar6 != *(uint *)(iVar7 + 0xc)) goto LAB_0092e406;
              }
              piVar8 = (int *)(in_ECX + 0x424 + uVar6 * 4);
              if ((*piVar8 != -1) || (local_10 = (int *)(param_1 + uVar6 * 4), *local_10 != 0)) {
LAB_0092e406:
                FUN_0091a001();
                return -0x7fffbffb;
              }
              if (iVar7 != 0) {
                *(undefined4 *)(in_ECX + 0x40c + uVar6 * 4) = *(undefined4 *)(iVar7 + 4);
                *piVar8 = *(int *)puVar3[2];
                iVar5 = FUN_00915318(*(undefined4 *)(iVar7 + 4),*(undefined4 *)(iVar7 + 0xc),
                                     *(undefined4 *)(iVar7 + 0x10),*(undefined8 *)(iVar7 + 0x20));
                uVar4 = 0;
                if ((*puVar3 & 0xfffff) != 0) {
                  do {
                    *(int *)(puVar3[2] + uVar4 * 4) = iVar5;
                    uVar4 = uVar4 + 1;
                  } while (uVar4 < (*puVar3 & 0xfffff));
                }
                local_14 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar5 * 4);
                FUN_00914e44();
                local_14[3] = uVar6;
                *(undefined4 *)(iVar7 + 0x40) = 1;
                local_14[0x10] = 0;
              }
              *local_10 = (int)puVar3;
            }
            else {
              if (param_5 != 2) goto LAB_0092e38d;
              if (iVar7 == 0) {
LAB_0092e29e:
                uVar6 = 0;
                bVar9 = *(int *)(in_ECX + 0x4c) == 0;
                if (*(int *)(in_ECX + 0x4c) != 0) {
                  param_6 = (int *)(in_ECX + 0x424);
                  do {
                    if ((*(int *)(param_1 + uVar6 * 4) == 0) &&
                       ((*param_6 == *(int *)puVar3[2] || (*param_6 == -1)))) break;
                    param_6 = param_6 + 1;
                    uVar6 = uVar6 + 1;
                  } while (uVar6 < *(uint *)(in_ECX + 0x4c));
                  bVar9 = uVar6 == *(uint *)(in_ECX + 0x4c);
                }
                if (bVar9) {
LAB_0092e44f:
                  FUN_0091a001();
                  return -0x7fffbffb;
                }
                if (iVar7 != 0) {
                  if (((*(uint *)(in_ECX + 200) & 0xffff) == 0x104) ||
                     (local_14 == *(undefined4 **)(in_ECX + 0x80))) {
                    *(undefined4 *)(in_ECX + 0x40c + uVar6 * 4) = *(undefined4 *)(iVar7 + 4);
                    *(undefined4 *)(in_ECX + 0x424 + uVar6 * 4) = *(undefined4 *)puVar3[2];
                  }
                  iVar5 = FUN_00915318(*(undefined4 *)(iVar7 + 4),*(undefined4 *)(iVar7 + 0xc),
                                       *(undefined4 *)(iVar7 + 0x10),*(undefined8 *)(iVar7 + 0x20));
                  uVar4 = 0;
                  if ((*puVar3 & 0xfffff) != 0) {
                    do {
                      *(int *)(puVar3[2] + uVar4 * 4) = iVar5;
                      uVar4 = uVar4 + 1;
                    } while (uVar4 < (*puVar3 & 0xfffff));
                  }
                  local_14 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar5 * 4);
                  FUN_00914e44();
                  local_14[3] = uVar6;
                  *(undefined4 *)(iVar7 + 0x40) = 1;
                  local_14[0x10] = 0;
                }
              }
              else {
                local_10 = *(int **)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4);
                uVar6 = *(uint *)(iVar7 + 0xc);
                if (5 < uVar6) break;
                if ((*(ushort *)(local_10 + 1) & 0x840) == 0) goto LAB_0092e29e;
                piVar8 = (int *)(in_ECX + 0x424 + uVar6 * 4);
                iVar5 = *piVar8;
                if ((iVar5 == -1) && (*(int *)(param_1 + uVar6 * 4) == 0)) {
                  *(int *)(in_ECX + 0x40c + uVar6 * 4) = *(int *)(iVar7 + 4);
                  *piVar8 = *(int *)puVar3[2];
                }
                else {
                  if (iVar5 != *(int *)puVar3[2]) goto LAB_0092e44f;
                  if (*(int *)(param_1 + uVar6 * 4) != 0) goto LAB_0092e406;
                }
              }
              *(uint **)(param_1 + uVar6 * 4) = puVar3;
            }
            *(undefined4 *)(*(int *)(param_3 + local_8 * 4) + 0x24) = 1;
          }
        }
LAB_0092e38d:
        local_8 = local_8 + 1;
        local_c = local_c + 1;
      } while (local_8 < param_4);
    }
    param_5 = param_5 + 1;
    if (2 < param_5) {
      local_8 = 0;
      if (*(int *)(in_ECX + 0x3c) != 0) {
        do {
          piVar8 = (int *)(param_1 + local_8 * 4);
          if (*piVar8 == 0) {
            iVar5 = FUN_009149f7();
            if (iVar5 == 0) {
              iVar5 = 0;
            }
            else {
              iVar5 = FUN_0091455d();
            }
            *piVar8 = iVar5;
            if (iVar5 == 0) {
              return -0x7ff8fff2;
            }
            FUN_00914a42(0,0,0,0);
            FUN_00915205();
          }
          local_8 = local_8 + 1;
        } while (local_8 < *(uint *)(in_ECX + 0x3c));
      }
      uVar6 = 0;
      *param_2 = *(int *)(in_ECX + 0x3c);
      if (param_4 != 0) {
        do {
          piVar8 = (int *)(param_3 + uVar6 * 4);
          piVar2 = (int *)*piVar8;
          if (((piVar2 != (int *)0x0) && (piVar2[9] != 1)) && (*piVar2 != 0)) {
            *(int *)(param_1 + *param_2 * 4) = *piVar8;
            *param_2 = *param_2 + 1;
            *(undefined4 *)(*piVar8 + 0x24) = 1;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < param_4);
      }
      return 0;
    }
  } while( true );
LAB_0092dffd:
  iVar5 = -0x7ff8fff2;
LAB_0092e02a:
  FUN_008f4adb();
  return iVar5;
}


// ==== FUN_0092e4dd @ 0x0092e4dd ====

int FUN_0092e4dd(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  void *pvVar5;
  int extraout_EAX;
  int extraout_EAX_00;
  int in_ECX;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  uint *puVar10;
  bool bVar11;
  int local_74 [6];
  int local_5c [6];
  uint local_44 [6];
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  int *local_1c;
  int local_18;
  undefined4 *local_14;
  uint local_10;
  undefined4 *local_c;
  uint local_8;
  
  local_14 = (undefined4 *)0x0;
  local_c = (undefined4 *)0x0;
  iVar7 = 6;
  piVar9 = local_5c;
  for (iVar6 = iVar7; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar9 = 0;
    piVar9 = piVar9 + 1;
  }
  piVar9 = local_74;
  for (iVar6 = iVar7; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar9 = 0;
    piVar9 = piVar9 + 1;
  }
  puVar10 = local_44;
  for (iVar6 = iVar7; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  puVar4 = (undefined4 *)(in_ECX + 0x40c);
  for (iVar6 = iVar7; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar4 = 0xffffffff;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)(in_ECX + 0x424);
  for (; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar4 = 0xffffffff;
    puVar4 = puVar4 + 1;
  }
  local_18 = 1;
  local_20 = 0;
  local_8 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      puVar10 = *(uint **)(*(int *)(in_ECX + 0x18) + local_8 * 4);
      uVar3 = *puVar10;
      uVar8 = uVar3 & 0xfff00000;
      puVar10[9] = 0;
      if (((((uVar8 == 0x60000000) || (uVar8 == 0x60500000)) || (uVar8 == 0x60a00000)) ||
          ((uVar8 == 0x72e00000 || (uVar8 == 0x60700000)))) || (uVar8 == 0x60f00000)) {
LAB_0092e72b:
        if (uVar8 == 0x11000000) {
LAB_0092e733:
          iVar7 = *(int *)puVar10[2];
        }
        else {
          iVar7 = *(int *)(puVar10[2] + (uVar3 & 0xfffff) * 4);
        }
        iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + iVar7 * 4);
        if ((*(int *)(iVar7 + 4) == *(int *)(in_ECX + 0x80)) && (*(int *)(iVar7 + 0x3c) == 0)) {
          if (*(char *)(iVar7 + 0x6c) != '\x03') goto LAB_0092ea12;
          if ((local_5c[*(byte *)(iVar7 + 0x6d)] != 0) &&
             ((*(uint *)(in_ECX + 200) & 0xffff) != 0x104)) {
            local_18 = 0;
          }
          local_5c[*(byte *)(iVar7 + 0x6d)] = 1;
        }
        else {
          local_18 = 0;
        }
      }
      else {
        if (uVar8 == 0x11000000) goto LAB_0092e733;
        if ((uVar8 == 0x72c00000) || (uVar8 == 0x72d00000)) goto LAB_0092e72b;
        uVar8 = uVar3 & 0xfffff;
        local_28 = uVar8;
        if ((uVar8 != 0) && (uVar3 != 0)) {
          local_10 = 0;
          if (puVar10[1] != 0) {
            local_2c = puVar10[1];
            local_1c = (int *)puVar10[2];
            do {
              iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + *local_1c * 4);
              if ((*(int *)(iVar7 + 4) == *(int *)(in_ECX + 0x80)) &&
                 (bVar1 = *(byte *)(iVar7 + 0x6d), *(char *)(iVar7 + 0x6c) == '\x03')) {
                if ((local_5c[bVar1] != 0) &&
                   (((*(uint *)(in_ECX + 200) & 0xffff) != 0x104 && (local_44[bVar1] == 0)))) {
                  local_18 = 0;
                }
                local_5c[bVar1] = 1;
                uVar3 = local_10 + uVar8;
                bVar11 = local_10 < uVar3;
                local_74[bVar1] = 1;
                uVar2 = local_28;
                if (bVar11) {
                  local_24 = uVar3 - local_10;
                  uVar3 = local_44[bVar1];
                  piVar9 = local_1c;
                  do {
                    uVar8 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar9 * 4) + 0x10) + 1;
                    if (uVar3 < uVar8) {
                      uVar3 = uVar8;
                    }
                    piVar9 = piVar9 + 1;
                    local_24 = local_24 - 1;
                  } while (local_24 != 0);
                  local_44[bVar1] = uVar3;
                  uVar8 = uVar2;
                }
              }
              local_10 = local_10 + uVar8;
              local_1c = local_1c + uVar8;
            } while (local_10 < local_2c);
          }
          local_20 = local_20 + 1;
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(in_ECX + 0xc));
    if (0x10 < local_20) {
      local_18 = 0;
    }
  }
  uVar3 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar7 = uVar3 * 4;
      uVar3 = uVar3 + 1;
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar7) + 0x40) = 0;
    } while (uVar3 < *(uint *)(in_ECX + 8));
  }
  uVar3 = *(uint *)(in_ECX + 0xc);
  local_2c = uVar3;
  if (local_18 == 0) {
    pvVar5 = operator_new(0x800);
    *(void **)(in_ECX + 0x22c) = pvVar5;
    if (pvVar5 == (void *)0x0) {
      return -0x7ff8fff2;
    }
    pvVar5 = operator_new(0x800);
    *(void **)(in_ECX + 0x230) = pvVar5;
    if (pvVar5 == (void *)0x0) {
      return -0x7ff8fff2;
    }
    local_14 = operator_new(0x800);
    if (local_14 == (undefined4 *)0x0) {
      return -0x7ff8fff2;
    }
    local_c = operator_new(0x800);
    puVar4 = *(undefined4 **)(in_ECX + 0x22c);
    for (iVar7 = 0x200; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    puVar4 = *(undefined4 **)(in_ECX + 0x230);
    for (iVar7 = 0x200; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    puVar4 = local_14;
    for (iVar7 = 0x200; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    puVar4 = local_c;
    for (iVar7 = 0x200; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    *(undefined4 *)(in_ECX + 0x220) = 0;
    *(undefined4 *)(in_ECX + 0x224) = 0;
    local_10 = 0;
    local_8 = 0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        if (0x1ff < local_8) {
LAB_0092ea12:
          FUN_0091a001();
          return -0x7fffbffb;
        }
        puVar10 = *(uint **)(*(int *)(in_ECX + 0x18) + local_8 * 4);
        uVar3 = *puVar10 & 0xfff00000;
        if (((((uVar3 == 0x60000000) || (uVar3 == 0x60500000)) || (uVar3 == 0x60a00000)) ||
            (((uVar3 == 0x72e00000 || (uVar3 == 0x60700000)) ||
             ((uVar3 == 0x60f00000 || ((uVar3 == 0x11000000 || (uVar3 == 0x72d00000)))))))) ||
           (uVar3 == 0x72c00000)) {
          local_24 = *puVar10 & 0xfffff;
          if (uVar3 == 0x11000000) {
            local_24 = 0;
          }
          piVar9 = (int *)(puVar10[2] + local_24 * 4);
          iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar9 * 4);
          if ((*(int *)(iVar7 + 4) == *(int *)(in_ECX + 0x88)) || (*(int *)(iVar7 + 0x3c) != 0)) {
            iVar7 = FUN_0092db3f(piVar9,puVar10[1] - local_24,local_14,&local_10);
            if (iVar7 < 0) goto LAB_0092e9e1;
          }
          else if ((*(int *)(iVar7 + 4) == *(int *)(in_ECX + 0x80)) &&
                  ((*(char *)(iVar7 + 0x6c) != '\x03' ||
                   ((local_74[*(byte *)(iVar7 + 0x6d)] != 0 &&
                    ((*(uint *)(in_ECX + 200) & 0xffff) != 0x104)))))) {
            FUN_0091a001();
            iVar7 = -0x7fffbffb;
            goto LAB_0092e9e1;
          }
        }
        local_8 = local_8 + 1;
      } while (local_8 < *(uint *)(in_ECX + 0xc));
    }
    uVar3 = 0;
    if (local_10 != 0) {
      puVar4 = local_14;
      do {
        *(undefined4 *)(((int)local_c - (int)local_14) + (int)puVar4) = *puVar4;
        *puVar4 = 0;
        uVar3 = uVar3 + 1;
        puVar4 = puVar4 + 1;
      } while (uVar3 < local_10);
    }
    iVar7 = FUN_0092dd2f(*(undefined4 *)(in_ECX + 0x230),in_ECX + 0x224,
                         *(undefined4 *)(in_ECX + 0x18),local_2c,0,0);
    if (iVar7 < 0) goto LAB_0092e9e1;
    uVar3 = 0;
    if (local_10 != 0) {
      do {
        *(undefined4 *)(local_c[uVar3] + 0x24) = 0;
        uVar3 = uVar3 + 1;
      } while (uVar3 < local_10);
    }
    iVar7 = FUN_0092dd2f(*(undefined4 *)(in_ECX + 0x22c),in_ECX + 0x220,local_c,local_10,
                         *(undefined4 *)(in_ECX + 0x230),*(undefined4 *)(in_ECX + 0x4c));
    if (iVar7 < 0) goto LAB_0092e9e1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x22c) = 0;
    puVar4 = operator_new(0x800);
    *(undefined4 **)(in_ECX + 0x230) = puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      return -0x7ff8fff2;
    }
    for (iVar7 = 0x200; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    iVar7 = FUN_0092dd2f(*(undefined4 *)(in_ECX + 0x230),in_ECX + 0x224,
                         *(undefined4 *)(in_ECX + 0x18),uVar3,0,0);
    if (iVar7 < 0) {
      return iVar7;
    }
  }
  iVar7 = 0;
  uVar3 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + uVar3 * 4);
      if (*(int *)(iVar6 + 0x40) == 1) {
        *(undefined4 *)(iVar6 + 4) = *(undefined4 *)(in_ECX + 0x74);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 8));
  }
LAB_0092e9e1:
  if (local_14 != (undefined4 *)0x0) {
    _free(local_14);
    return extraout_EAX;
  }
  if (local_c == (undefined4 *)0x0) {
    return iVar7;
  }
  _free(local_c);
  return extraout_EAX_00;
}


// ==== FUN_0092ea3e @ 0x0092ea3e ====

uint FUN_0092ea3e(int param_1,uint param_2,uint param_3,int param_4,int param_5,undefined4 *param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  uint local_8;
  
  local_8 = 0;
  *param_6 = 0;
  for (; param_2 < param_3; param_2 = param_2 + 1) {
    iVar1 = *(int *)(param_1 + param_2 * 4);
    uVar4 = 0;
    if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
      do {
        iVar2 = *(int *)(*(int *)(iVar1 + 8) + uVar4 * 4);
        iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + iVar2 * 4);
        if ((iVar2 == param_4) || (*(int *)(iVar3 + 0x38) == param_4)) {
          *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(param_5 + 0xc);
          *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(param_5 + 0x10);
          *param_6 = 1;
          local_8 = param_2;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(iVar1 + 4));
    }
  }
  return local_8;
}


// ==== FUN_0092eabb @ 0x0092eabb ====

int FUN_0092eabb(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  iVar3 = 0;
  pvVar1 = operator_new(*(int *)(in_ECX + 0xc) << 2);
  *(void **)(in_ECX + 0x2b4) = pvVar1;
  pvVar1 = operator_new(*(int *)(in_ECX + 8) << 2);
  *(void **)(in_ECX + 0x2b8) = pvVar1;
  if ((*(int *)(in_ECX + 0x2b4) == 0) || (pvVar1 == (void *)0x0)) {
LAB_0092eba9:
    iVar3 = -0x7ff8fff2;
  }
  else {
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        iVar3 = FUN_009149f7(0x74);
        if (iVar3 == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = FUN_0091455d();
        }
        *(undefined4 *)(*(int *)(in_ECX + 0x2b4) + uVar4 * 4) = uVar2;
        if (*(int *)(*(int *)(in_ECX + 0x2b4) + uVar4 * 4) == 0) goto LAB_0092eba9;
        iVar3 = FUN_00914ca1(*(undefined4 *)(*(int *)(in_ECX + 0x18) + uVar4 * 4));
        if (iVar3 < 0) {
          return iVar3;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(in_ECX + 0xc));
    }
    uVar4 = 0;
    if (*(int *)(in_ECX + 8) != 0) {
      do {
        iVar3 = FUN_00914f55(0x80);
        if (iVar3 == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = FUN_0079e14e();
        }
        *(undefined4 *)(*(int *)(in_ECX + 0x2b8) + uVar4 * 4) = uVar2;
        if (*(int *)(*(int *)(in_ECX + 0x2b8) + uVar4 * 4) == 0) goto LAB_0092eba9;
        iVar3 = FUN_00914e44(*(undefined4 *)(*(int *)(in_ECX + 0x14) + uVar4 * 4));
        if (iVar3 < 0) {
          return iVar3;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(in_ECX + 8));
    }
    *(undefined4 *)(in_ECX + 0x2c0) = *(undefined4 *)(in_ECX + 0xc);
    *(undefined4 *)(in_ECX + 700) = *(undefined4 *)(in_ECX + 8);
  }
  return iVar3;
}


// ==== FUN_0092ebb4 @ 0x0092ebb4 ====

undefined4 FUN_0092ebb4(void)

{
  int in_ECX;
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint local_8;
  
  local_8 = 0;
  if (*(int *)(in_ECX + 0x2c0) != 0) {
    do {
      iVar3 = local_8 * 4;
      iVar2 = *(int *)(iVar3 + *(int *)(in_ECX + 0x2b4));
      puVar4 = *(undefined4 **)(iVar2 + 8);
      puVar5 = *(undefined4 **)(*(int *)(*(int *)(in_ECX + 0x18) + iVar3) + 8);
      for (uVar1 = *(uint *)(iVar2 + 4) & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
      iVar2 = *(int *)(iVar3 + *(int *)(in_ECX + 0x2b4));
      puVar4 = *(undefined4 **)(iVar2 + 0x10);
      puVar5 = *(undefined4 **)(*(int *)(*(int *)(in_ECX + 0x18) + iVar3) + 0x10);
      for (uVar1 = *(uint *)(iVar2 + 0xc) & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      local_8 = local_8 + 1;
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
    } while (local_8 < *(uint *)(in_ECX + 0x2c0));
  }
  uVar1 = 0;
  if (*(int *)(in_ECX + 700) != 0) {
    do {
      iVar2 = uVar1 * 4;
      iVar3 = uVar1 * 4;
      uVar1 = uVar1 + 1;
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar3) + 0x38) =
           *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x2b8) + iVar2) + 0x38);
    } while (uVar1 < *(uint *)(in_ECX + 700));
  }
  return 0;
}


// ==== FUN_0092ec61 @ 0x0092ec61 ====

uint FUN_0092ec61(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  int iVar5;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int *piVar6;
  uint *puVar7;
  uint uVar8;
  undefined8 uVar9;
  uint local_34 [6];
  uint local_1c;
  uint local_18;
  uint local_14;
  int *local_10;
  int *local_c;
  uint *local_8;
  
  puVar7 = local_34;
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  local_18 = *(uint *)(in_ECX + 0xc);
  if (local_18 != 0) {
    local_10 = *(int **)(in_ECX + 0x18);
    local_c = (int *)local_18;
    do {
      puVar7 = (uint *)*local_10;
      if ((puVar7 != (uint *)0x0) && (local_8 = (uint *)*puVar7, local_8 != (uint *)0x0)) {
        local_1c = puVar7[1];
        local_14 = 0;
        if (local_1c != 0) {
          piVar6 = (int *)puVar7[2];
          do {
            iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar6 * 4);
            if (*(int *)(iVar5 + 4) == *(int *)(in_ECX + 0x80)) {
              if (5 < *(byte *)(iVar5 + 0x6d)) break;
              if (*(char *)(iVar5 + 0x6c) == '\x03') {
                uVar8 = (uint)local_8 & 0xfff00000;
                uVar9 = FUN_0092a852();
                iVar5 = (int)((ulonglong)uVar9 >> 0x20);
                if (((int)uVar9 == 0) && (uVar8 != 0x11000000)) {
                  uVar8 = *(int *)(extraout_ECX + 0x10) + 1;
                  if (local_34[iVar5] < uVar8) {
                    local_34[iVar5] = uVar8;
                  }
                }
                else {
                  uVar8 = *(int *)(extraout_ECX + 0x10) + 1;
                  if ((local_34[iVar5] < uVar8) && (*(int *)(extraout_ECX + 0x3c) != 0)) {
                    local_34[iVar5] = uVar8;
                  }
                }
              }
            }
            local_14 = local_14 + 1;
            piVar6 = piVar6 + 1;
          } while (local_14 < local_1c);
        }
      }
      local_10 = local_10 + 1;
      local_c = (int *)((int)local_c - 1);
    } while (local_c != (int *)0x0);
  }
  local_c = (int *)0x0;
  local_8 = local_34;
  do {
    if (*local_8 != 0) {
      iVar5 = FUN_009149f7();
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_0091455d();
      }
      if (iVar5 == 0) {
        return 0x8007000e;
      }
      uVar8 = *local_8;
      uVar8 = FUN_00914a42(uVar8 & 0xfffff | 0x72100000,uVar8,uVar8,0);
      if ((int)uVar8 < 0) {
        return uVar8;
      }
      uVar8 = 0;
      if (*local_8 != 0) {
        do {
          uVar2 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0,uVar8,0);
          *(undefined4 *)(*(int *)(iVar5 + 0x10) + uVar8 * 4) = uVar2;
          if (*(int *)(*(int *)(iVar5 + 0x10) + uVar8 * 4) == -1) {
            FUN_008f4adb();
            return 0x8007000e;
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < *local_8);
      }
      uVar8 = FUN_0092d8b9(*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0xc),3,local_c,
                           *local_8,*(undefined4 *)(iVar5 + 0x10));
      if ((int)uVar8 < 0) {
        FUN_008f4adb();
        return uVar8;
      }
      uVar8 = 0;
      if (*local_8 != 0) {
        do {
          iVar3 = FUN_00915318(*(undefined4 *)(in_ECX + 0x80),local_c,uVar8,0);
          if (iVar3 == -1) {
            FUN_008f4adb();
            return 0x8007000e;
          }
          iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4);
          *(undefined4 *)(iVar1 + 0x3c) = 0;
          *(uint *)(iVar1 + 0x6c) = (int)local_c << 8 | 3;
          *(int *)(*(int *)(iVar5 + 8) + uVar8 * 4) = iVar3;
          uVar8 = uVar8 + 1;
        } while (uVar8 < *local_8);
      }
      local_14 = FUN_00915205();
      if ((int)local_14 < 0) {
        return local_14;
      }
    }
    local_c = (int *)((int)local_c + 1);
    local_8 = local_8 + 1;
  } while (local_c < (int *)0x6);
  local_8 = (uint *)0x0;
  if (local_18 != 0) {
    do {
      puVar7 = *(uint **)(*(int *)(in_ECX + 0x18) + (int)local_8 * 4);
      local_10 = (int *)(*puVar7 & 0xfffff);
      uVar9 = FUN_0092a852();
      iVar5 = (int)((ulonglong)uVar9 >> 0x20);
      if (((int)uVar9 != 0) || (iVar5 == 0x11000000)) {
        if (iVar5 == 0x11000000) {
          iVar5 = *(int *)puVar7[2];
        }
        else {
          iVar5 = ((int *)puVar7[2])[extraout_ECX_00];
        }
        iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + iVar5 * 4);
        if (((*(byte *)(iVar5 + 0x3e) & 0x1f) != 0) &&
           (*(int *)(iVar5 + 4) == *(int *)(in_ECX + 0x88))) {
          iVar5 = FUN_009149f7();
          if (iVar5 == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = FUN_0091455d();
          }
          if (iVar5 == 0) {
            return 0x8007000e;
          }
          local_14 = FUN_00914a42((uint)local_10 & 0xfffff | 0x10000000,local_10,local_10,0);
          if ((int)local_14 < 0) {
            return local_14;
          }
          uVar8 = *puVar7 & 0xfffff;
          if ((*puVar7 & 0xfff00000) == 0x11000000) {
            uVar8 = 0;
          }
          local_c = (int *)0x0;
          if (local_10 != (int *)0x0) {
            local_14 = uVar8 << 2;
            do {
              local_1c = *(uint *)(*(int *)(in_ECX + 0x14) + *(int *)(local_14 + puVar7[2]) * 4);
              *(int *)(*(int *)(iVar5 + 8) + (int)local_c * 4) = *(int *)(local_14 + puVar7[2]);
              uVar2 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0,*(undefined4 *)(local_1c + 0x10)
                                   ,0);
              piVar6 = (int *)((int)local_c + 1);
              *(undefined4 *)(*(int *)(iVar5 + 0x10) + (int)local_c * 4) = uVar2;
              uVar8 = local_14 + 4;
              *(undefined4 *)(local_14 + puVar7[2]) =
                   *(undefined4 *)(*(int *)(iVar5 + 0x10) + (int)local_c * 4);
              local_14 = uVar8;
              local_c = piVar6;
            } while (piVar6 < local_10);
          }
          local_14 = FUN_00915205();
          if ((int)local_14 < 0) {
            return local_14;
          }
        }
      }
      local_8 = (uint *)((int)local_8 + 1);
    } while (local_8 < local_18);
  }
  uVar8 = 0;
  if (local_18 != 0) {
    do {
      uVar4 = FUN_00915471();
      if ((int)uVar4 < 0) {
        return uVar4;
      }
      **(undefined4 **)(*(int *)(in_ECX + 0x18) + uVar8 * 4) = 0;
      uVar8 = uVar8 + 1;
    } while (uVar8 < local_18);
  }
  local_14 = *(uint *)(in_ECX + 0xc);
  local_18 = 0;
  if (local_14 != 0) {
    do {
      puVar7 = *(uint **)(*(int *)(in_ECX + 0x18) + local_18 * 4);
      if (*puVar7 != 0) {
        local_10 = (int *)(*puVar7 & 0xfffff);
        iVar5 = FUN_0092a852();
        if ((iVar5 != 0) || (extraout_ECX_01 == 0x11000000)) {
          local_1c = (-(uint)(extraout_ECX_01 != 0x11000000) & (uint)local_10) * 4;
          iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(local_1c + puVar7[2]) * 4);
          uVar8 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar5 + 4) * 4) + 4);
          if (((uVar8 & 0x200) != 0) ||
             (((uVar8 & 0x10) != 0 && (*(char *)(iVar5 + 0x6c) == '\x01')))) {
            iVar5 = FUN_009149f7();
            if (iVar5 == 0) {
              local_8 = (uint *)0x0;
            }
            else {
              local_8 = (uint *)FUN_0091455d();
            }
            if (local_8 == (uint *)0x0) {
              return 0x8007000e;
            }
            uVar8 = FUN_00914a42((uint)local_10 & 0xfffff | 0x10000000,local_10,local_10,0);
            if ((int)uVar8 < 0) {
              return uVar8;
            }
            uVar8 = FUN_00914593();
            if ((int)uVar8 < 0) {
              return uVar8;
            }
            local_c = (int *)0x0;
            if (local_10 != (int *)0x0) {
              uVar8 = puVar7[2];
              uVar4 = local_1c;
              do {
                *(undefined4 *)(*(int *)((int)local_8 + 8) + (int)local_c * 4) =
                     *(undefined4 *)(uVar8 + uVar4);
                uVar2 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0,local_c,0);
                *(undefined4 *)(*(int *)((int)local_8 + 0x10) + (int)local_c * 4) = uVar2;
                *(undefined4 *)(uVar4 + puVar7[2]) =
                     *(undefined4 *)(*(int *)((int)local_8 + 0x10) + (int)local_c * 4);
                uVar8 = puVar7[2];
                if (*(int *)(uVar8 + uVar4) == -1) {
                  return 0x8007000e;
                }
                local_c = (int *)((int)local_c + 1);
                uVar4 = uVar4 + 4;
              } while (local_c < local_10);
            }
            FUN_00915205();
          }
        }
        FUN_00915471();
        *puVar7 = 0;
      }
      local_18 = local_18 + 1;
    } while (local_18 < local_14);
  }
  uVar8 = FUN_00915e19();
  return uVar8;
}


// ==== FUN_0092f1c1 @ 0x0092f1c1 ====

int FUN_0092f1c1(void)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  undefined4 extraout_ECX;
  undefined8 uVar5;
  uint local_8;
  
  iVar3 = FUN_0092d1aa(*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0xc));
  if (-1 < iVar3) {
    uVar4 = 0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x18) + uVar4 * 4) + 0x28) = 0;
        iVar1 = uVar4 * 4;
        uVar4 = uVar4 + 1;
        *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x18) + iVar1) + 0x24) = 0;
      } while (uVar4 < *(uint *)(in_ECX + 0xc));
    }
    local_8 = 0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + local_8 * 4);
        uVar5 = FUN_0092a852(*puVar2 & 0xfff00000);
        if (((int)uVar5 != 0) || ((int)((ulonglong)uVar5 >> 0x20) == 0x11000000)) {
          uVar4 = puVar2[9];
          FUN_0093dacd(extraout_ECX,puVar2,1);
          puVar2[9] = uVar4;
        }
        local_8 = local_8 + 1;
      } while (local_8 < *(uint *)(in_ECX + 0xc));
    }
  }
  return iVar3;
}


// ==== FUN_0092f24f @ 0x0092f24f ====

int FUN_0092f24f(void)

{
  int in_ECX;
  int extraout_ECX;
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  undefined8 uVar5;
  
  uVar2 = 0;
  uVar3 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    puVar4 = (uint *)(in_ECX + 0x450);
    do {
      uVar5 = FUN_0092a852(**(uint **)(*(int *)(in_ECX + 0x18) + uVar3 * 4) & 0xfff00000);
      iVar1 = (int)((ulonglong)uVar5 >> 0x20);
      if ((((int)uVar5 != 0) || (iVar1 == 0x72100000)) || (iVar1 == 0x11000000)) {
        if (0xb < uVar2) {
          return -1;
        }
        *puVar4 = uVar3;
        uVar2 = uVar2 + 1;
        puVar4 = puVar4 + 1;
      }
      uVar3 = uVar3 + 1;
      in_ECX = extraout_ECX;
    } while (uVar3 < *(uint *)(extraout_ECX + 0xc));
  }
  *(uint *)(in_ECX + 0x480) = uVar2;
  return 1 << ((byte)uVar2 & 0x1f);
}


// ==== FUN_0092f2b2 @ 0x0092f2b2 ====

undefined4 FUN_0092f2b2(uint *param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  
  iVar1 = FUN_0092a852(*param_1 & 0xfff00000);
  uVar2 = 0;
  if (iVar1 != 0) {
    if (param_1[5] == 0) {
      return 1;
    }
    if (param_2 != 0) {
      FUN_0091a001();
      return 0;
    }
    param_2 = 1;
  }
  if (param_1[5] != 0) {
    do {
      iVar1 = FUN_0092f2b2(*(undefined4 *)
                            (*(int *)(in_ECX + 0x18) + *(int *)(param_1[6] + uVar2 * 4) * 4),param_2
                          );
      if (iVar1 == 0) {
        return 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_1[5]);
  }
  return 1;
}


// ==== FUN_0092f329 @ 0x0092f329 ====

undefined4 FUN_0092f329(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  undefined4 local_8;
  
  local_8 = 0;
  if (*(uint *)(in_ECX + 0xc) < 0x41) {
    uVar1 = 0;
    if (*(uint *)(in_ECX + 0xc) != 0) {
      do {
        iVar2 = uVar1 * 4;
        uVar1 = uVar1 + 1;
        *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x18) + iVar2) + 0x28) = 0;
      } while (uVar1 < *(uint *)(in_ECX + 0xc));
    }
    uVar1 = 0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        uVar3 = 0;
        iVar2 = *(int *)(*(int *)(in_ECX + 0x18) + uVar1 * 4);
        *(int *)(in_ECX + 0x100) = iVar2;
        if ((*(int *)(iVar2 + 0x24) != 0) && (*(int *)(iVar2 + 4) != 0)) {
          do {
            if (*(char *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                  *(int *)(*(int *)(*(int *)(in_ECX + 0x100) + 8) + uVar3 * 4) * 4)
                         + 0x6c) == '\x01') {
              FUN_0091a001();
              local_8 = 1;
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < *(uint *)(*(int *)(in_ECX + 0x100) + 4));
        }
        iVar2 = FUN_0092f2b2(*(undefined4 *)(in_ECX + 0x100),0);
        if (iVar2 == 0) {
          local_8 = 1;
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(uint *)(in_ECX + 0xc));
    }
  }
  else {
    FUN_0091a001();
    local_8 = 1;
  }
  return local_8;
}


// ==== FUN_0092f3fc @ 0x0092f3fc ====

undefined4 FUN_0092f3fc(int param_1,int *param_2,int param_3,uint param_4,uint param_5)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  uint uVar6;
  int *piVar7;
  
  if (param_5 == 0) {
    param_5 = 0;
    if (param_4 != 0) {
      do {
        piVar1 = (int *)(param_3 + param_5 * 4);
        puVar2 = (uint *)*piVar1;
        if (((*puVar2 & 0xfff00000) != 0x11000000) && ((*puVar2 & 0xfff00000) != 0x72100000)) {
          iVar3 = *(int *)puVar2[2];
          iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4);
          if ((*(ushort *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar4 + 4) * 4) + 4) & 0x840)
              != 0) {
            uVar6 = *(uint *)(iVar4 + 0xc);
            if ((5 < uVar6) || (piVar7 = (int *)(param_1 + uVar6 * 4), *piVar7 != 0)) {
              return 0;
            }
            piVar5 = param_2 + uVar6;
            if (*piVar5 == -1) {
              *piVar5 = iVar3;
            }
            else if (*piVar5 != iVar3) {
              return 0;
            }
            *piVar7 = (int)puVar2;
            *piVar1 = 0;
            *piVar5 = *(int *)puVar2[2];
          }
        }
        param_5 = param_5 + 1;
      } while (param_5 < param_4);
    }
  }
  else if (param_5 == 1) {
    param_5 = 0;
    if (param_4 != 0) {
      do {
        piVar1 = (int *)(param_3 + param_5 * 4);
        puVar2 = (uint *)*piVar1;
        if (((puVar2 != (uint *)0x0) && ((*puVar2 & 0xfff00000) != 0x11000000)) &&
           ((*puVar2 & 0xfff00000) != 0x72100000)) {
          uVar6 = 0;
          piVar7 = param_2;
          do {
            if ((*(int *)((param_1 - (int)param_2) + (int)piVar7) == 0) &&
               ((*piVar7 == *(int *)puVar2[2] || (*piVar7 == -1)))) break;
            uVar6 = uVar6 + 1;
            piVar7 = piVar7 + 1;
          } while (uVar6 < 6);
          if (uVar6 == 6) {
            return 0;
          }
          param_2[uVar6] = *(int *)puVar2[2];
          *(uint **)(uVar6 * 4 + param_1) = puVar2;
          *piVar1 = 0;
        }
        param_5 = param_5 + 1;
      } while (param_5 < param_4);
    }
  }
  else if ((param_5 == 2) && (param_5 = 0, param_4 != 0)) {
    do {
      piVar1 = (int *)(param_3 + param_5 * 4);
      puVar2 = (uint *)*piVar1;
      if ((puVar2 != (uint *)0x0) &&
         (((*puVar2 & 0xfff00000) == 0x11000000 || ((*puVar2 & 0xfff00000) == 0x72100000)))) {
        uVar6 = 0;
        do {
          if (*(int *)(param_1 + uVar6 * 4) == 0) break;
          uVar6 = uVar6 + 1;
        } while (uVar6 < 6);
        if (uVar6 == 6) {
          return 0;
        }
        param_2[uVar6] = *(int *)puVar2[2];
        *(uint **)(uVar6 * 4 + param_1) = puVar2;
        *piVar1 = 0;
      }
      param_5 = param_5 + 1;
    } while (param_5 < param_4);
  }
  return 1;
}


// ==== FUN_0092f5d2 @ 0x0092f5d2 ====

undefined4 FUN_0092f5d2(uint param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  int local_5c [6];
  int local_44 [6];
  undefined4 local_2c [6];
  int *local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  uVar4 = 0;
  uVar2 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar4 = uVar4 + 1;
    uVar2 = uVar2 & uVar2 - 1;
  } while (uVar4 < 7);
  if ((uVar4 < 7) && (*(int *)(in_ECX + 0x480) - uVar4 < 7)) {
    local_8 = 0;
    local_c = 0;
    local_10 = 0;
    if (*(int *)(in_ECX + 0x480) != 0) {
      local_14 = (int *)(in_ECX + 0x450);
      do {
        puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + *local_14 * 4);
        uVar2 = *puVar1 & 0xfff00000;
        if ((param_1 & 1 << ((byte)local_10 & 0x1f)) == 0) {
          if (uVar2 == 0x11000000) {
            return 0;
          }
          if (uVar2 != 0x72100000) {
            iVar3 = *(int *)(*(int *)(in_ECX + 0x14) +
                            *(int *)(puVar1[2] + (*puVar1 & 0xfffff) * 4) * 4);
            if (*(char *)(iVar3 + 0x6c) != '\x03') {
              return 0;
            }
            if (*(int *)(iVar3 + 0x3c) != 0) {
              return 0;
            }
          }
          piVar7 = local_44 + local_8;
          local_8 = local_8 + 1;
          *piVar7 = (int)puVar1;
        }
        else {
          if (puVar1[9] == 1) {
            return 0;
          }
          piVar7 = local_5c + local_c;
          local_c = local_c + 1;
          *piVar7 = (int)puVar1;
        }
        local_10 = local_10 + 1;
        local_14 = local_14 + 1;
      } while (local_10 < *(uint *)(in_ECX + 0x480));
    }
    iVar3 = local_8;
    puVar6 = local_2c;
    for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar6 = 0xffffffff;
      puVar6 = puVar6 + 1;
    }
    iVar3 = FUN_0092f3fc(*(undefined4 *)(in_ECX + 0x22c),local_2c,local_44,iVar3);
    if (((((iVar3 != 0) &&
          (iVar3 = FUN_0092f3fc(*(undefined4 *)(in_ECX + 0x230),local_2c,local_5c,local_c,0),
          iVar3 != 0)) &&
         (iVar3 = FUN_0092f3fc(*(undefined4 *)(in_ECX + 0x22c),local_2c,local_44,local_8,1),
         iVar3 != 0)) &&
        ((iVar3 = FUN_0092f3fc(*(undefined4 *)(in_ECX + 0x230),local_2c,local_5c,local_c,1),
         iVar3 != 0 &&
         (iVar3 = FUN_0092f3fc(*(undefined4 *)(in_ECX + 0x22c),local_2c,local_44,local_8,2),
         iVar3 != 0)))) &&
       (iVar3 = FUN_0092f3fc(*(undefined4 *)(in_ECX + 0x230),local_2c,local_5c,local_c,2),
       iVar3 != 0)) {
      if (param_2 == 0) {
        piVar7 = local_5c;
        for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar7 = 0;
          piVar7 = piVar7 + 1;
        }
        piVar7 = local_44;
        for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar7 = 0;
          piVar7 = piVar7 + 1;
        }
        param_2 = 0;
        uVar2 = 0;
        do {
          if ((*(int *)(uVar2 + *(int *)(in_ECX + 0x22c)) != 0) ||
             (*(int *)(uVar2 + *(int *)(in_ECX + 0x230)) != 0)) {
            local_14 = (int *)0x0;
            puVar1 = *(uint **)(uVar2 + *(int *)(in_ECX + 0x230));
            if (puVar1 != (uint *)0x0) {
              local_14 = (int *)(*puVar1 & 0xfff00000);
            }
            uVar8 = FUN_0092a852();
            local_10 = (uint)uVar8;
            if (local_10 == 0) {
              uVar9 = FUN_0092a852();
              uVar8 = CONCAT44((int)((ulonglong)uVar9 >> 0x20),local_10);
              if ((int)uVar9 == 0) goto LAB_0092f95f;
            }
            local_10 = (uint)uVar8;
            param_1 = -1;
            if (local_10 != 0) {
              iVar3 = *(int *)(*(int *)(in_ECX + 0x14) +
                              **(int **)((int)((ulonglong)uVar8 >> 0x20) + 8) * 4);
              param_1 = FUN_00915318(*(undefined4 *)(iVar3 + 4),*(undefined4 *)(iVar3 + 0xc),
                                     *(undefined4 *)(iVar3 + 0x10),*(undefined8 *)(iVar3 + 0x20));
              if (param_1 == -1) {
                return 0;
              }
              uVar4 = 0;
              if ((**(uint **)(uVar2 + *(int *)(in_ECX + 0x22c)) & 0xfffff) != 0) {
                do {
                  *(uint *)(*(int *)(*(int *)(uVar2 + *(int *)(in_ECX + 0x22c)) + 8) + uVar4 * 4) =
                       param_1;
                  uVar4 = uVar4 + 1;
                } while (uVar4 < (**(uint **)(uVar2 + *(int *)(in_ECX + 0x22c)) & 0xfffff));
              }
              local_c = *(int *)(*(int *)(in_ECX + 0x14) + param_1 * 4);
              *(int *)((int)local_5c + uVar2) = iVar3;
              FUN_00914e44();
              *(int *)(local_c + 0xc) = param_2;
            }
            iVar3 = FUN_0092a852();
            if (iVar3 != 0) {
              iVar3 = *(int *)(*(int *)(in_ECX + 0x14) +
                              **(int **)(*(int *)(uVar2 + *(int *)(in_ECX + 0x230)) + 8) * 4);
              if ((param_1 == -1) &&
                 (param_1 = FUN_00915318(*(undefined4 *)(iVar3 + 4),*(undefined4 *)(iVar3 + 0xc),
                                         *(undefined4 *)(iVar3 + 0x10),*(undefined8 *)(iVar3 + 0x20)
                                        ), param_1 == -1)) {
                return 0;
              }
              uVar4 = 0;
              if ((**(uint **)(uVar2 + *(int *)(in_ECX + 0x230)) & 0xfffff) != 0) {
                do {
                  *(uint *)(*(int *)(*(int *)(uVar2 + *(int *)(in_ECX + 0x230)) + 8) + uVar4 * 4) =
                       param_1;
                  uVar4 = uVar4 + 1;
                } while (uVar4 < (**(uint **)(uVar2 + *(int *)(in_ECX + 0x230)) & 0xfffff));
              }
              *(int *)((int)local_44 + uVar2) = iVar3;
              if (local_10 == 0) {
                local_14 = *(int **)(*(int *)(in_ECX + 0x14) + param_1 * 4);
                FUN_00914e44();
                *(int *)((int)local_14 + 0xc) = param_2;
              }
            }
            if (param_1 == -1) {
              return 0;
            }
          }
LAB_0092f95f:
          param_2 = param_2 + 1;
          uVar2 = uVar2 + 4;
        } while (uVar2 < 0x18);
        uVar2 = 0;
        do {
          if (*(int *)((int)local_5c + uVar2) != 0) {
            *(undefined4 *)(*(int *)((int)local_5c + uVar2) + 4) = *(undefined4 *)(in_ECX + 0x74);
          }
          if (*(int *)((int)local_44 + uVar2) != 0) {
            *(undefined4 *)(*(int *)((int)local_44 + uVar2) + 4) = *(undefined4 *)(in_ECX + 0x74);
          }
          uVar2 = uVar2 + 4;
        } while (uVar2 < 0x18);
      }
      *(undefined4 *)(in_ECX + 0x220) = 6;
      *(undefined4 *)(in_ECX + 0x224) = 6;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0092f9b1 @ 0x0092f9b1 ====

/* WARNING: Type propagation algorithm not settling */

uint * FUN_0092f9b1(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  int in_ECX;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  uint *puVar11;
  undefined4 auStackY_2ec [128];
  uint local_d0 [16];
  int aiStack_90 [16];
  uint local_50 [5];
  uint local_3c;
  int local_38;
  int local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint *local_24;
  int local_20;
  uint local_1c;
  uint *local_18;
  uint *local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_34 = 0;
  local_20 = 0;
  local_2c = 0;
  do {
    iVar6 = *(int *)(*(int *)(in_ECX + 0x22c) + local_2c * 4);
    if (((iVar6 != 0) && (*(int *)(iVar6 + 0xc) != 0)) &&
       (local_10 = 0, *(int *)(in_ECX + 0x224) != 0)) {
      do {
        local_20 = 0;
        puVar3 = *(uint **)(*(int *)(in_ECX + 0x230) + local_10 * 4);
        local_18 = puVar3;
        if ((puVar3 != (uint *)0x0) && (*puVar3 != 0)) {
          local_28 = 0;
          local_50[4] = (uint)(local_10 < 6);
          local_c = *puVar3 & 0xfffff;
          if (local_c != 0) {
            local_3c = puVar3[1] / local_c;
            uVar10 = *(uint *)(*(int *)(in_ECX + 0x22c) + local_2c * 4);
            local_24 = (uint *)0x0;
            local_1c = 0;
            if (*(int *)(uVar10 + 0xc) != 0) {
              local_30 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x22c) + local_2c * 4) + 0xc);
              do {
                if (local_50[4] < local_3c) {
                  iVar6 = local_c * local_50[4] * 4;
                  local_38 = local_3c - local_50[4];
                  do {
                    if (local_c != 0) {
                      local_14 = *(uint **)(*(int *)(uVar10 + 0x10) + local_1c * 4);
                      puVar5 = (undefined4 *)(puVar3[2] + iVar6);
                      local_8 = local_c;
                      do {
                        if ((((uint *)*puVar5 == local_14) ||
                            (*(uint **)(*(int *)(*(int *)(in_ECX + 0x14) + (int)*puVar5 * 4) + 0x38)
                             == local_14)) &&
                           ((local_2c < local_10 &&
                            (((puVar11 = *(uint **)(*(int *)(in_ECX + 0x230) + local_2c * 4),
                              puVar11 != (uint *)0x0 && (uVar7 = *puVar11, uVar7 != 0)) &&
                             ((uVar7 & 0xfff00000) != 0x11000000)))))) {
                          local_24 = (uint *)0x1;
                          local_28 = uVar10;
                        }
                        puVar5 = puVar5 + 1;
                        local_8 = local_8 - 1;
                      } while (local_8 != 0);
                    }
                    iVar6 = iVar6 + local_c * 4;
                    local_38 = local_38 + -1;
                  } while (local_38 != 0);
                }
                local_1c = local_1c + 1;
              } while (local_1c < local_30);
              if (local_24 != (uint *)0x0) {
                if (param_1 == (int *)0x0) {
                  local_50[0] = 0xffffffff;
                  local_50[1] = 0xffffffff;
                  local_50[2] = 0xffffffff;
                  local_8 = 0;
                  local_50[3] = 0xffffffff;
                  local_c = 0;
                  if (puVar3[1] != 0) {
                    do {
                      if (*(uint **)(local_28 + 0xc) != (uint *)0x0) {
                        puVar11 = *(uint **)(local_28 + 0x10);
                        local_30 = *(uint *)(puVar3[2] + local_c * 4);
                        local_24 = *(uint **)(local_28 + 0xc);
                        do {
                          uVar10 = *puVar11;
                          if ((uVar10 == local_30) ||
                             (uVar10 == *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + local_30 * 4) +
                                                 0x38))) {
                            uVar7 = 0;
                            if (local_8 != 0) {
                              do {
                                if (local_50[uVar7] == uVar10) break;
                                uVar7 = uVar7 + 1;
                              } while (uVar7 < local_8);
                            }
                            if (uVar7 == local_8) {
                              local_50[local_8] = uVar10;
                              local_8 = local_8 + 1;
                            }
                          }
                          puVar11 = puVar11 + 1;
                          local_24 = (uint *)((int)local_24 + -1);
                        } while (local_24 != (uint *)0x0);
                      }
                      local_c = local_c + 1;
                    } while (local_c < puVar3[1]);
                  }
                  iVar6 = FUN_009149f7(0x74);
                  if (iVar6 == 0) {
                    local_20 = 0;
                  }
                  else {
                    local_20 = FUN_0091455d();
                  }
                  if (local_20 != 0) {
                    puVar11 = (uint *)FUN_00914a42(local_8 & 0xfffff | 0x10000000,local_8,local_8,0)
                    ;
                    local_14 = puVar11;
                    if ((int)puVar11 < 0) goto LAB_00930195;
                    puVar5 = *(undefined4 **)(local_20 + 0x10);
                    for (uVar10 = local_8; uVar10 != 0; uVar10 = uVar10 - 1) {
                      *puVar5 = 0xffffffff;
                      puVar5 = puVar5 + 1;
                    }
                    local_1c = 0;
                    if (puVar3[1] != 0) {
                      do {
                        local_c = 0;
                        if (*(int *)(local_28 + 0xc) != 0) {
                          do {
                            uVar10 = *(uint *)(puVar3[2] + local_1c * 4);
                            iVar6 = *(int *)(in_ECX + 0x14);
                            local_14 = *(uint **)(iVar6 + uVar10 * 4);
                            uVar7 = *(uint *)(*(int *)(local_28 + 0x10) + local_c * 4);
                            if ((uVar7 == uVar10) || (uVar7 == local_14[0xe])) {
                              local_30 = *(uint *)(iVar6 + uVar7 * 4);
                              iVar8 = (local_1c % local_8) * 4;
                              iVar4 = *(int *)(iVar8 + *(int *)(local_20 + 0x10));
                              if (iVar4 == -1) {
                                uVar10 = *(uint *)(in_ECX + 0x408);
                                if (0x3f < uVar10) goto LAB_0092fe24;
                                iVar4 = *(int *)(in_ECX + 0x304 + uVar10 * 4);
                                *(uint *)(in_ECX + 0x408) = uVar10 + 1;
                                iVar6 = *(int *)(iVar6 + iVar4 * 4);
                                uVar1 = *(undefined4 *)(in_ECX + 0x88);
                                *(undefined4 *)(iVar6 + 0x3c) = 0;
                                *(undefined4 *)(iVar6 + 0x38) = 0xffffffff;
                                *(undefined4 *)(iVar6 + 4) = uVar1;
                                *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(local_30 + 0x10);
                                if (iVar4 == -1) goto LAB_0092fe24;
                              }
                              if (*(uint *)(*(int *)(local_28 + 0x10) + local_c * 4) ==
                                  local_14[0xe]) {
                                uVar10 = *(uint *)(in_ECX + 0x408);
                                if (0x3f < uVar10) goto LAB_0092fe24;
                                uVar7 = *(uint *)(in_ECX + 0x304 + uVar10 * 4);
                                *(uint *)(in_ECX + 0x408) = uVar10 + 1;
                                iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + uVar7 * 4);
                                *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(local_30 + 0x10);
                                *(uint *)(iVar6 + 0x3c) = local_14[0xf];
                                *(int *)(iVar6 + 0x38) = iVar4;
                                *(undefined4 *)(iVar6 + 4) = *(undefined4 *)(in_ECX + 0x88);
                                local_30 = uVar7;
                                *(uint *)(local_18[2] + local_1c * 4) = uVar7;
                              }
                              else {
                                *(int *)(local_18[2] + local_1c * 4) = iVar4;
                              }
                              *(undefined4 *)(iVar8 + *(int *)(local_20 + 8)) =
                                   *(undefined4 *)(*(int *)(local_28 + 0x10) + local_c * 4);
                              *(int *)(iVar8 + *(int *)(local_20 + 0x10)) = iVar4;
                              *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4) + 0x3c)
                                   = 0;
                              puVar3 = local_18;
                            }
                            local_c = local_c + 1;
                          } while (local_c < *(uint *)(local_28 + 0xc));
                        }
                        local_1c = local_1c + 1;
                      } while (local_1c < puVar3[1]);
                    }
                    piVar9 = (int *)(in_ECX + 0x220);
                    *(int *)(*(int *)(in_ECX + 0x22c) + *piVar9 * 4) = local_20;
                    *piVar9 = *piVar9 + 1;
                    puVar3 = (uint *)(in_ECX + 0x404);
                    if (*puVar3 < 0xc) {
                      *(int *)(in_ECX + 0x2c4 + *puVar3 * 4) = local_20;
                      *puVar3 = *puVar3 + 1;
                      local_20 = 0;
                      goto LAB_0092fb2d;
                    }
                  }
LAB_0092fe24:
                  puVar11 = (uint *)0x8007000e;
                  goto LAB_00930195;
                }
                *param_1 = *param_1 + 1;
                *param_1 = *param_1 + 1;
              }
            }
          }
        }
LAB_0092fb2d:
        local_10 = local_10 + 1;
      } while (local_10 < *(uint *)(in_ECX + 0x224));
    }
    local_20 = 0;
    local_2c = local_2c + 1;
  } while (local_2c < 6);
  local_28 = 0;
  if (*(int *)(in_ECX + 0x220) != 0) {
    do {
      piVar9 = *(int **)(*(int *)(in_ECX + 0x22c) + local_28 * 4);
      if ((piVar9 != (int *)0x0) && (*piVar9 != 0)) {
        iVar6 = piVar9[3];
        local_24 = (uint *)0x0;
        if (iVar6 != 0) {
          puVar3 = (uint *)piVar9[4];
          do {
            if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *puVar3 * 4) + 0x10) == 3) {
              local_24 = (uint *)0x1;
              local_2c = *puVar3;
            }
            puVar3 = puVar3 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
          if (local_24 != (uint *)0x0) {
            local_8 = 0;
            local_10 = 6;
            if (6 < *(uint *)(in_ECX + 0x224)) {
              piVar9 = (int *)(*(int *)(in_ECX + 0x230) + 0x18);
              do {
                piVar2 = (int *)*piVar9;
                if (((piVar2 != (int *)0x0) && (*piVar2 != 0)) &&
                   (local_18 = (uint *)0x0, piVar2[1] != 0)) {
                  local_14 = (uint *)piVar2[2];
                  do {
                    uVar10 = local_8;
                    if ((*(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + *local_14 * 4) + 0x38) ==
                         local_2c) || (*local_14 == local_2c)) {
                      if (0xf < local_8) {
                        return (uint *)0x80004005;
                      }
                      local_8 = local_8 + 1;
                      aiStack_90[uVar10] = (int)piVar2;
                    }
                    local_18 = (uint *)((int)local_18 + 1);
                    local_14 = local_14 + 1;
                  } while (local_18 < (uint *)piVar2[1]);
                }
                local_10 = local_10 + 1;
                piVar9 = piVar9 + 1;
              } while (local_10 < *(uint *)(in_ECX + 0x224));
            }
            if (param_1 != (int *)0x0) {
              local_10 = 0;
              if (*(int *)(in_ECX + 0xc) != 0) {
                local_18 = *(uint **)(in_ECX + 0x18);
                do {
                  piVar9 = (int *)*local_18;
                  if (((piVar9 != (int *)0x0) && (*piVar9 != 0)) && (piVar9[10] != 1)) {
                    local_14 = (uint *)0x0;
                    if ((uint *)piVar9[1] != (uint *)0x0) {
                      puVar3 = (uint *)piVar9[2];
                      do {
                        if ((*(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + *puVar3 * 4) + 0x38) ==
                             local_2c) || (*puVar3 == local_2c)) {
                          if (0xf < local_8) {
                            return (uint *)0x80004005;
                          }
                          local_8 = local_8 + 1;
                        }
                        local_14 = (uint *)((int)local_14 + 1);
                        puVar3 = puVar3 + 1;
                      } while (local_14 < (uint *)piVar9[1]);
                    }
                  }
                  local_10 = local_10 + 1;
                  local_18 = local_18 + 1;
                } while (local_10 < *(uint *)(in_ECX + 0xc));
              }
              if (local_8 == 0) goto LAB_00930107;
              *param_1 = *param_1 + 1;
            }
            if ((local_8 != 0) && (param_1 == (int *)0x0)) {
              if (0xb < *(uint *)(in_ECX + 0x404)) {
                return (uint *)0x1;
              }
              iVar6 = FUN_009149f7(0x74);
              if (iVar6 == 0) {
                iVar6 = 0;
              }
              else {
                iVar6 = FUN_0091455d();
              }
              iVar4 = FUN_009149f7(0x74);
              if (iVar4 == 0) {
                local_c = 0;
              }
              else {
                local_c = FUN_0091455d();
              }
              if (((iVar6 == 0) || (local_c == 0)) ||
                 (uVar10 = *(uint *)(in_ECX + 0x408), 0x40 < uVar10)) {
                return (uint *)0x8007000e;
              }
              local_30 = *(uint *)(in_ECX + 0x308 + uVar10 * 4);
              iVar4 = *(int *)(in_ECX + 0x304 + uVar10 * 4);
              iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + local_30 * 4);
              *(undefined4 *)(iVar8 + 0x38) = 0xffffffff;
              *(undefined4 *)(iVar8 + 0x10) = 3;
              *(undefined4 *)(iVar8 + 0x3c) = 0;
              iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4);
              *(undefined4 *)(iVar8 + 0x38) = 0xffffffff;
              *(undefined4 *)(iVar8 + 0x10) = 4;
              *(undefined4 *)(iVar8 + 0x3c) = 0;
              *(int *)(in_ECX + 0x408) = *(int *)(in_ECX + 0x408) + 2;
              local_10 = 0;
              if (local_8 != 0) {
                do {
                  iVar8 = aiStack_90[local_10];
                  local_18 = (uint *)0x0;
                  if (*(int *)(iVar8 + 4) != 0) {
                    do {
                      local_24 = (uint *)(*(int *)(iVar8 + 8) + (int)local_18 * 4);
                      iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + *local_24 * 4);
                      if (*(uint *)(iVar8 + 0x38) == local_2c) {
                        *(uint *)(iVar8 + 0x38) = local_30;
                      }
                      else if (*local_24 == local_2c) {
                        *local_24 = local_30;
                      }
                      local_18 = (uint *)((int)local_18 + 1);
                      iVar8 = aiStack_90[local_10];
                    } while (local_18 < *(uint **)(iVar8 + 4));
                  }
                  local_10 = local_10 + 1;
                } while (local_10 < local_8);
              }
              local_14 = (uint *)FUN_00914a42(0x10000001,1,1,0);
              if ((int)local_14 < 0) {
                return local_14;
              }
              local_14 = (uint *)FUN_00914a42(0x10000001,1,1,0);
              iVar8 = local_34;
              if ((int)local_14 < 0) {
                return local_14;
              }
              **(int **)(iVar6 + 0x10) = iVar4;
              **(uint **)(iVar6 + 8) = local_2c;
              *(undefined4 *)(iVar6 + 0x28) = 1;
              **(uint **)(local_c + 0x10) = local_30;
              **(int **)(local_c + 8) = iVar4;
              *(undefined4 *)(iVar6 + 0x28) = 2;
              *(int *)(in_ECX + 0x2c4 + *(int *)(in_ECX + 0x404) * 4) = iVar6;
              *(uint *)(in_ECX + 0x2c8 + *(int *)(in_ECX + 0x404) * 4) = local_c;
              *(int *)(in_ECX + 0x404) = *(int *)(in_ECX + 0x404) + 2;
              *(int *)(*(int *)(in_ECX + 0x22c) + *(int *)(in_ECX + 0x220) * 4) = iVar6;
              *(int *)(in_ECX + 0x220) = *(int *)(in_ECX + 0x220) + 1;
              local_34 = local_34 + 1;
              local_d0[iVar8] = local_c;
            }
          }
        }
      }
LAB_00930107:
      local_28 = local_28 + 1;
    } while (local_28 < *(uint *)(in_ECX + 0x220));
  }
  uVar10 = *(uint *)(in_ECX + 0x224);
  if (0x200 < uVar10 + local_34) {
    return (uint *)0x80004005;
  }
  if (5 < uVar10) {
    iVar6 = (uVar10 + local_34) * 4;
    do {
      *(undefined4 *)(*(int *)(in_ECX + 0x230) + iVar6) =
           *(undefined4 *)(*(int *)(in_ECX + 0x230) + uVar10 * 4);
      uVar10 = uVar10 - 1;
      iVar6 = iVar6 + -4;
    } while (5 < uVar10);
  }
  if (local_34 != 0) {
    iVar6 = 0x18;
    iVar4 = local_34;
    do {
      *(undefined4 *)(iVar6 + *(int *)(in_ECX + 0x230)) =
           *(undefined4 *)((int)auStackY_2ec + iVar6 + 0x204);
      iVar6 = iVar6 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  *(int *)(in_ECX + 0x224) = *(int *)(in_ECX + 0x224) + local_34;
  puVar11 = (uint *)0x0;
LAB_00930195:
  if (local_20 != 0) {
    FUN_008f4adb(1);
  }
  return puVar11;
}


