// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x930000-0x93ffff

// ==== FUN_009301b3 @ 0x009301b3 ====

undefined4 FUN_009301b3(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int in_ECX;
  int extraout_ECX;
  int iVar5;
  undefined8 uVar6;
  int local_28;
  uint local_20;
  uint local_1c;
  int *local_18;
  int *local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  piVar3 = *(int **)(in_ECX + 0x230);
  local_20 = 0x12;
  iVar5 = 6;
  do {
    if (((uint *)*piVar3 != (uint *)0x0) && ((*(uint *)*piVar3 & 0xfff00000) != 0x11000000)) {
      local_20 = local_20 - 3;
    }
    piVar3 = piVar3 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  local_28 = *(int *)(in_ECX + 0x220);
  local_1c = 0;
  if (local_28 != 0) {
    local_14 = *(int **)(in_ECX + 0x22c);
    do {
      if (*local_14 != 0) {
        uVar1 = *(uint *)(*local_14 + 0xc);
        local_10 = 0;
        if (uVar1 != 0) {
          uVar4 = *(uint *)(in_ECX + 0xc);
          do {
            local_c = 0;
            if (uVar4 != 0) {
              local_18 = *(int **)(in_ECX + 0x18);
              do {
                if (((uint *)*local_18)[10] != 1) {
                  uVar6 = FUN_0092a852(*(uint *)*local_18 & 0xfff00000);
                  iVar5 = (int)((ulonglong)uVar6 >> 0x20);
                  in_ECX = extraout_ECX;
                  if ((int)uVar6 == 0) {
                    local_8 = 0;
                    uVar4 = *(uint *)(iVar5 + 4);
                    if (uVar4 != 0) {
                      iVar2 = *(int *)(*(int *)(*local_14 + 0x10) + local_10 * 4);
                      piVar3 = *(int **)(iVar5 + 8);
                      do {
                        if ((*(int *)(*(int *)(*(int *)(extraout_ECX + 0x14) + *piVar3 * 4) + 0x38)
                             == iVar2) || (*piVar3 == iVar2)) break;
                        local_8 = local_8 + 1;
                        piVar3 = piVar3 + 1;
                      } while (local_8 < uVar4);
                    }
                    if (local_8 != uVar4) break;
                  }
                }
                local_c = local_c + 1;
                local_18 = local_18 + 1;
              } while (local_c < *(uint *)(in_ECX + 0xc));
            }
            uVar4 = *(uint *)(in_ECX + 0xc);
            if (local_c != uVar4) {
              local_1c = local_1c + 1;
            }
            local_10 = local_10 + 1;
          } while (local_10 < uVar1);
        }
      }
      local_14 = local_14 + 1;
      local_28 = local_28 + -1;
    } while (local_28 != 0);
    if (local_20 < local_1c) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_009302e7 @ 0x009302e7 ====

undefined4 FUN_009302e7(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  
  uVar1 = 1;
  if (*(int *)(param_1 + 0x28) == 1) {
    uVar3 = 0;
    if (*(int *)(param_1 + 0x14) != 0) {
      do {
        iVar2 = FUN_009302e7(*(undefined4 *)
                              (*(int *)(in_ECX + 0x18) +
                              *(int *)(*(int *)(param_1 + 0x18) + uVar3 * 4) * 4));
        if (iVar2 != 0) {
          return 1;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(param_1 + 0x14));
    }
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0093032e @ 0x0093032e ====

undefined4
FUN_0093032e(int param_1,uint param_2,uint param_3,int param_4,uint param_5,int param_6,
            uint *param_7)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  int in_ECX;
  int *piVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint local_10;
  uint local_c;
  int local_8;
  
  uVar6 = param_2;
  do {
    if (param_3 <= uVar6) {
      return 0;
    }
    puVar1 = *(uint **)(param_1 + uVar6 * 4);
    if ((puVar1 != (uint *)0x0) && (uVar8 = *puVar1 & 0xfffff, *puVar1 != 0)) {
      uVar2 = puVar1[1];
      local_10 = 0;
      if (uVar2 / uVar8 != 0) {
        param_2 = 0;
        do {
          bVar4 = false;
          if (uVar8 != 0) {
            piVar7 = (int *)(puVar1[2] + param_2);
            local_c = uVar8;
            do {
              iVar9 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar7 * 4);
              uVar5 = 0;
              if (param_5 != 0) {
                do {
                  iVar3 = *(int *)(param_4 + uVar5 * 4);
                  if (((*piVar7 == iVar3) || (*(int *)(iVar9 + 0x38) == iVar3)) &&
                     (*(int *)(iVar9 + 0xc) == -1)) {
                    bVar4 = true;
                  }
                  uVar5 = uVar5 + 1;
                } while (uVar5 < param_5);
              }
              piVar7 = piVar7 + 1;
              local_c = local_c - 1;
            } while (local_c != 0);
            if (bVar4) {
              local_c = 0;
              local_8 = param_2;
              do {
                iVar9 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                         *(int *)(local_8 + puVar1[2]) * 4) + 0x38);
                if (iVar9 == -1) {
                  iVar9 = *(int *)(local_8 + puVar1[2]);
                }
                uVar5 = *param_7;
                uVar10 = 0;
                if (uVar5 != 0) {
                  do {
                    if (*(int *)(param_6 + uVar10 * 4) == iVar9) break;
                    uVar10 = uVar10 + 1;
                  } while (uVar10 < *param_7);
                }
                if (uVar10 == uVar5) {
                  if (uVar10 == 0x20) {
                    FUN_0091a001();
                    return 0x80004005;
                  }
                  *(int *)(param_6 + uVar5 * 4) = iVar9;
                  *param_7 = *param_7 + 1;
                }
                local_c = local_c + 1;
                local_8 = local_8 + 4;
              } while (local_c < uVar8);
            }
          }
          local_10 = local_10 + 1;
          param_2 = param_2 + uVar8 * 4;
        } while (local_10 < uVar2 / uVar8);
      }
    }
    uVar6 = uVar6 + 1;
  } while( true );
}


// ==== FUN_0093048d @ 0x0093048d ====

undefined4 FUN_0093048d(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + uVar3 * 4);
      if (*(int *)(iVar1 + 0x38) != -1) {
        iVar2 = *(int *)(iVar1 + 0x38) * 4;
        *(undefined4 *)(iVar1 + 0xc) =
             *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar2) + 0xc);
        *(undefined4 *)(iVar1 + 0x10) =
             *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar2) + 0x10);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 8));
  }
  return 0;
}


// ==== FUN_009304cc @ 0x009304cc ====

undefined4
FUN_009304cc(int param_1,uint param_2,uint param_3,int *param_4,int param_5,uint *param_6,
            undefined4 *param_7,undefined4 *param_8)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  uint uVar6;
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_14;
  uint local_10;
  int *local_c;
  int local_8;
  
  *param_7 = 0;
  *param_8 = 0;
  local_10 = 0;
  for (uVar5 = param_2; uVar5 < param_3; uVar5 = uVar5 + 1) {
    puVar1 = *(uint **)(param_1 + uVar5 * 4);
    if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
      uVar3 = *puVar1 & 0xfffff;
      uVar2 = puVar1[1];
      local_14 = 0;
      if (param_5 != 0) {
        local_c = param_4;
        local_24 = param_5;
        do {
          if (uVar2 / uVar3 != 0) {
            local_8 = 0;
            local_20 = uVar2 / uVar3;
            do {
              param_2 = 0;
              if (uVar3 != 0) {
                iVar4 = local_8;
                local_1c = uVar3;
                do {
                  if ((*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar4 + puVar1[2]) * 4)
                               + 0x38) == *local_c) || (*(int *)(iVar4 + puVar1[2]) == *local_c)) {
                    param_2 = param_2 + 1;
                    local_14 = local_14 + 1;
                    if (local_10 < local_14) {
                      local_10 = local_14;
                    }
                    if ((puVar1[3] == 1) &&
                       (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)puVar1[4] * 4) + 0x10)
                        == 3)) {
                      *param_7 = 1;
                    }
                    if (((*puVar1 & 0xfff00000) != 0x50000000) && (uVar6 = 0, puVar1[3] != 0)) {
                      do {
                        if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                             *(int *)(puVar1[4] + uVar6 * 4) * 4) + 0x10) == 3) {
                          *param_7 = 1;
                        }
                        uVar6 = uVar6 + 1;
                      } while (uVar6 < puVar1[3]);
                    }
                  }
                  iVar4 = iVar4 + 4;
                  local_1c = local_1c - 1;
                } while (local_1c != 0);
              }
              if ((param_2 != uVar3) && (param_2 != 0)) {
                *param_8 = 1;
              }
              local_8 = local_8 + uVar3 * 4;
              local_20 = local_20 - 1;
            } while (local_20 != 0);
          }
          local_c = local_c + 1;
          local_24 = local_24 + -1;
        } while (local_24 != 0);
      }
    }
  }
  *param_6 = local_10;
  return 0;
}


// ==== FUN_00930645 @ 0x00930645 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00930645(void)

{
  float fVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  float *pfVar12;
  int *piVar13;
  float local_170 [32];
  int local_f0 [32];
  int local_70 [8];
  float local_50 [4];
  int local_40 [5];
  undefined4 local_2c;
  uint local_28;
  uint *local_24;
  uint *local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  uint *local_c;
  uint *local_8;
  
  uVar10 = *(uint *)(in_ECX + 8);
  iVar7 = 0x20;
  pfVar12 = local_170;
  for (iVar6 = 0x20; iVar6 != 0; iVar6 = iVar6 + -1) {
    *pfVar12 = 0.0;
    pfVar12 = pfVar12 + 1;
  }
  iVar6 = 8;
  piVar13 = local_f0;
  for (; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar13 = 0;
    piVar13 = piVar13 + 1;
  }
  piVar13 = local_70;
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar13 = 0;
    piVar13 = piVar13 + 1;
  }
  local_1c = uVar10;
  local_2c = FUN_009152bf(&DAT_00a1fc10,0x311,0x400000008);
  local_14 = 0;
  if (uVar10 != 0) {
    iVar7 = *(int *)(in_ECX + 0x10);
    piVar13 = *(int **)(in_ECX + 0x14);
    do {
      uVar10 = *(uint *)(*(int *)(iVar7 + *(int *)(*piVar13 + 4) * 4) + 4);
      if (((uVar10 & 0x200) != 0) && ((uVar10 & 0x180) == 0)) {
        uVar10 = *(uint *)(*piVar13 + 0xc);
        if (*(uint *)(in_ECX + 0x38) < uVar10) {
LAB_00930b1e:
          FUN_0091a001();
          return 0x80004005;
        }
        local_f0[uVar10 * 4] = 1;
        local_f0[uVar10 * 4 + 1] = 1;
        local_f0[uVar10 * 4 + 2] = 1;
        local_f0[uVar10 * 4 + 3] = 1;
        local_70[uVar10] = 1;
      }
      local_14 = local_14 + 1;
      piVar13 = piVar13 + 1;
    } while (local_14 < local_1c);
  }
  uVar10 = *(uint *)(in_ECX + 0x224);
  uVar9 = *(uint *)(in_ECX + 0x220);
  local_10 = 0;
  if (uVar9 + uVar10 != 0) {
    do {
      if (local_10 < uVar9) {
        local_24 = *(uint **)(*(int *)(in_ECX + 0x22c) + local_10 * 4);
      }
      else {
        local_24 = *(uint **)(*(int *)(in_ECX + 0x230) + (local_10 - uVar9) * 4);
      }
      local_18 = 0;
      if ((((local_24 != (uint *)0x0) && (local_24[3] != 0)) && (*(int *)local_24[4] != -1)) &&
         ((*local_24 & 0xfff00000) != 0)) {
        if (((*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)local_24[4] * 4) + 0x10) != 3) &&
            (local_24[3] != 4)) && (uVar9 <= local_10)) {
          iVar7 = 1;
          if ((local_10 - uVar9) + 1 < uVar10) {
            uVar8 = (local_10 - uVar9) + 1;
            uVar10 = (local_10 - uVar9) + 1;
            do {
              iVar6 = *(int *)(*(int *)(in_ECX + 0x230) + uVar10 * 4);
              if ((iVar6 != 0) && ((*(ushort *)(iVar6 + 2) & 0xfff0) != 0)) break;
              iVar7 = iVar7 + 1;
              uVar8 = uVar8 + 1;
              uVar10 = uVar8;
            } while (uVar8 < *(uint *)(in_ECX + 0x224));
          }
          uVar10 = (iVar7 - uVar9) + local_10;
          if (uVar10 < *(uint *)(in_ECX + 0x224)) {
            local_18 = *(int *)(*(int *)(in_ECX + 0x230) + uVar10 * 4);
            if ((*(int *)(local_18 + 0xc) != 1) ||
               (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + **(int **)(local_18 + 0x10) * 4) + 0x10)
                != 3)) {
              local_18 = 0;
            }
          }
        }
        local_20 = (uint *)(*local_24 & 0xfffff);
        local_40[4] = local_24[1] / (uint)local_20;
        local_28 = 0;
        if (local_40[4] != 0) {
          local_14 = 0;
          puVar11 = local_24;
          do {
            puVar3 = local_24;
            local_40[0] = 0;
            local_40[1] = 0;
            local_40[2] = 0;
            local_40[3] = 0;
            puVar11 = (uint *)(puVar11[2] + local_14);
            iVar7 = *(int *)(in_ECX + 0x14);
            if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                    *(int *)(*(int *)(iVar7 + *puVar11 * 4) + 4) * 4) + 5) & 1) != 0
                ) && (*puVar11 < local_1c)) {
              local_c = (uint *)0x0;
              if (local_20 != (uint *)0x0) {
                local_8 = (uint *)(*local_24 & 0xfff00000);
                do {
                  puVar4 = local_c;
                  if (local_8 != (uint *)0x50000000) {
                    puVar4 = *(uint **)(*(int *)(iVar7 + *(int *)(puVar3[4] + (int)local_c * 4) * 4)
                                       + 0x10);
                  }
                  local_50[(int)puVar4] = (float)*(double *)(*(int *)(iVar7 + *puVar11 * 4) + 0x20);
                  local_40[(int)puVar4] = 1;
                  local_c = (uint *)((int)local_c + 1);
                  puVar11 = puVar11 + 1;
                } while (local_c < local_20);
              }
              iVar6 = local_18;
              if ((local_18 != 0) && (local_c = *(uint **)(local_18 + 4), local_c != (uint *)0x0)) {
                local_8 = *(uint **)(local_18 + 8);
                do {
                  iVar2 = *(int *)(iVar7 + *local_8 * 4);
                  if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar2 + 4) * 4) + 5) &
                       1) != 0) && (*local_8 < local_1c)) {
                    local_40[3] = 1;
                    local_50[3] = (float)*(double *)(iVar2 + 0x20);
                  }
                  local_c = (uint *)((int)local_c + -1);
                  local_8 = local_8 + 1;
                } while (local_c != (uint *)0x0);
              }
              local_c = (uint *)0x0;
              uVar10 = 0;
              do {
                uVar9 = 0;
                if (local_70[(int)local_c] == 0) {
                  local_8 = (uint *)0x1;
                  do {
                    if (((*(int *)((int)local_40 + uVar9) != 0) &&
                        (*(float *)((int)local_50 + uVar9) !=
                         *(float *)((int)local_170 + uVar10 + uVar9))) &&
                       (*(int *)((int)local_f0 + uVar10 + uVar9) != 0)) {
                      local_8 = (uint *)0x0;
                    }
                    uVar9 = uVar9 + 4;
                  } while (uVar9 < 0x10);
                  if (local_8 != (uint *)0x0) break;
                }
                local_c = (uint *)((int)local_c + 1);
                uVar10 = uVar10 + 0x10;
              } while (uVar10 < 0x80);
              if (local_c == (uint *)0x8) goto LAB_00930b1e;
              uVar10 = 0;
              local_8 = (uint *)0x0;
              do {
                if (local_40[uVar10] != 0) {
                  iVar7 = uVar10 + (int)local_c * 4;
                  pfVar12 = local_50 + uVar10;
                  fVar1 = *pfVar12;
                  local_f0[iVar7] = 1;
                  local_170[iVar7] = fVar1;
                  if (((float)_DAT_0099d0a0 < *pfVar12) || (*pfVar12 < DAT_0099d0dc)) {
                    local_8 = (uint *)0x1;
                  }
                }
                uVar10 = uVar10 + 1;
              } while (uVar10 < 4);
              if (local_8 != (uint *)0x0) {
                FUN_0091a096();
              }
              local_8 = (uint *)0x0;
              if (local_20 != (uint *)0x0) {
                uVar10 = local_14;
                do {
                  if ((*puVar3 & 0xfff00000) == 0x50000000) {
                    puVar11 = local_8;
                  }
                  else {
                    puVar11 = *(uint **)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                 *(int *)(puVar3[4] + (int)local_8 * 4) * 4) + 0x10)
                    ;
                  }
                  iVar7 = FUN_00915318(local_2c,local_c,puVar11,
                                       *(undefined8 *)
                                        (*(int *)(*(int *)(in_ECX + 0x14) +
                                                 *(int *)(uVar10 + puVar3[2]) * 4) + 0x20));
                  *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar7 * 4) + 0x3c) = 0;
                  local_8 = (uint *)((int)local_8 + 1);
                  *(int *)(uVar10 + puVar3[2]) = iVar7;
                  uVar10 = uVar10 + 4;
                } while (local_8 < local_20);
                iVar6 = local_18;
              }
              if ((iVar6 != 0) && (local_8 = (uint *)0x0, *(int *)(iVar6 + 4) != 0)) {
                do {
                  uVar10 = *(uint *)(*(int *)(iVar6 + 8) + (int)local_8 * 4);
                  iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + uVar10 * 4);
                  if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4) + 5) &
                       1) != 0) && (uVar10 < local_1c)) {
                    uVar5 = FUN_00915318(local_2c,local_c,3,*(undefined8 *)(iVar7 + 0x20));
                    *(undefined4 *)(*(int *)(local_18 + 8) + (int)local_8 * 4) = uVar5;
                  }
                  local_8 = (uint *)((int)local_8 + 1);
                  iVar6 = local_18;
                } while (local_8 < *(uint **)(local_18 + 4));
              }
            }
            local_28 = local_28 + 1;
            local_14 = local_14 + (int)local_20 * 4;
            puVar11 = puVar3;
          } while (local_28 < (uint)local_40[4]);
        }
      }
      uVar10 = *(uint *)(in_ECX + 0x224);
      uVar9 = *(uint *)(in_ECX + 0x220);
      local_10 = local_10 + 1;
    } while (local_10 < uVar9 + uVar10);
  }
  uVar10 = 0;
  if (local_1c != 0) {
    do {
      iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + uVar10 * 4);
      if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar7 + 4) * 4) + 5) & 1) != 0) {
        *(undefined4 *)(iVar7 + 4) = *(undefined4 *)(in_ECX + 0x74);
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < local_1c);
  }
  return 0;
}


// ==== FUN_00930b35 @ 0x00930b35 ====

undefined4 FUN_00930b35(uint param_1,int param_2,uint param_3,int param_4,uint param_5)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  int in_ECX;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  uint local_18;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_8 = 0;
  if (param_3 != 0) {
    do {
      puVar1 = *(uint **)(param_2 + local_8 * 4);
      uVar8 = 0;
      if ((puVar1 != (uint *)0x0) && (uVar5 = *puVar1, uVar5 != 0)) {
        uVar6 = uVar5 & 0xfff00000;
        uVar5 = uVar5 & 0xfffff;
        if ((uVar6 == 0x60000000) ||
           ((((uVar6 == 0x60500000 || (uVar6 == 0x60a00000)) || (uVar6 == 0x60f00000)) ||
            ((uVar6 == 0x72e00000 || (uVar6 == 0x60700000)))))) {
          if (uVar6 == 0x72100000) goto LAB_00930c44;
        }
        else {
          if (uVar6 != 0x72100000) {
            if (param_5 != 0) {
              uVar5 = puVar1[1];
              do {
                local_c = 0;
                if (uVar5 != 0) {
                  iVar2 = *(int *)(param_4 + uVar8 * 4);
                  piVar7 = (int *)puVar1[2];
                  do {
                    if (((*piVar7 == iVar2) ||
                        (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar7 * 4) + 0x38) == iVar2))
                       && ((puVar3 = *(uint **)(param_2 + param_1 * 4), puVar3 != (uint *)0x0 &&
                           (((param_1 < local_8 && (uVar5 = *puVar3, uVar5 != 0)) &&
                            ((uVar5 & 0xfff00000) != 0x11000000)))))) {
                      return 1;
                    }
                    local_c = local_c + 1;
                    uVar5 = puVar1[1];
                    piVar7 = piVar7 + 1;
                  } while (local_c < uVar5);
                }
                uVar8 = uVar8 + 1;
              } while (uVar8 < param_5);
            }
            goto LAB_00930cbc;
          }
LAB_00930c44:
          uVar5 = 0;
        }
        local_18 = 0;
        if (param_5 != 0) {
          uVar8 = puVar1[1];
          do {
            if (uVar5 < uVar8) {
              piVar7 = (int *)(puVar1[2] + uVar5 * 4);
              local_10 = uVar5;
              do {
                if (((*piVar7 == *(int *)(param_4 + local_18 * 4)) &&
                    (piVar4 = *(int **)(param_2 + param_1 * 4), piVar4 != (int *)0x0)) &&
                   ((param_1 < local_8 && (*piVar4 != 0)))) {
                  return 1;
                }
                iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar7 * 4);
                if (((*(byte *)(iVar2 + 0x3e) & 0x1f) != 0) || (*(int *)(iVar2 + 0x38) != -1)) {
                  FUN_0091a001();
                  return 0x80004005;
                }
                local_10 = local_10 + 1;
                uVar8 = puVar1[1];
                piVar7 = piVar7 + 1;
              } while (local_10 < uVar8);
            }
            local_18 = local_18 + 1;
          } while (local_18 < param_5);
        }
      }
LAB_00930cbc:
      local_8 = local_8 + 1;
    } while (local_8 < param_3);
  }
  return 0;
}


// ==== FUN_00930cf8 @ 0x00930cf8 ====

int FUN_00930cf8(int param_1,uint param_2,int param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int in_ECX;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  int local_24;
  uint local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  
  puVar10 = (uint *)0x0;
  local_14 = 0;
  if (param_2 == 0) {
LAB_00930d8f:
    FUN_0091a001();
    return -0x7fffbffb;
  }
  do {
    puVar1 = *(uint **)(param_1 + local_14 * 4);
    if (puVar1 != (uint *)0x0) {
      if (((*puVar1 & 0xfff00000) != 0) && ((*puVar1 & 0xfffff) != 0)) {
        uVar11 = puVar1[3];
        if (uVar11 != 0) {
          piVar6 = (int *)puVar1[4];
          iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar6 * 4);
          if ((*(int *)(iVar5 + 0xc) == param_3) && (*(int *)(iVar5 + 4) == *(int *)(in_ECX + 0x88))
             ) {
            local_18 = local_14;
            uVar4 = 0;
            puVar10 = puVar1;
            if (uVar11 != 0) {
              do {
                if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar6 * 4) + 0x10) == 2) {
                  return 0;
                }
                uVar4 = uVar4 + 1;
                piVar6 = piVar6 + 1;
              } while (uVar4 < uVar11);
            }
          }
        }
      }
    }
    local_14 = local_14 + 1;
  } while (local_14 < param_2);
  if (puVar10 == (uint *)0x0) goto LAB_00930d8f;
  uVar11 = *puVar10 & 0xfffff;
  if ((*puVar10 & 0xfff00000) == 0x50000000) {
    iVar5 = FUN_009149f7();
    if (iVar5 == 0) {
      param_2 = 0;
    }
    else {
      param_2 = FUN_0091455d();
    }
    if (param_2 == 0) {
      return -0x7ff8fff2;
    }
    iVar5 = FUN_00914a42(*puVar10,puVar10[1],puVar10[3] + 1,0);
    if ((iVar5 < 0) || (iVar5 = FUN_00914593(), iVar5 < 0)) goto LAB_009310be;
    iVar5 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),param_3,2,0);
    if (iVar5 == -1) {
LAB_00930e59:
      iVar5 = -0x7ff8fff2;
      goto LAB_009310be;
    }
    puVar12 = (undefined4 *)puVar10[2];
    puVar13 = *(undefined4 **)(param_2 + 8);
    for (uVar11 = *(uint *)(param_2 + 4) & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
      *puVar13 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar13 = puVar13 + 1;
    }
    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined1 *)puVar13 = *(undefined1 *)puVar12;
      puVar12 = (undefined4 *)((int)puVar12 + 1);
      puVar13 = (undefined4 *)((int)puVar13 + 1);
    }
    puVar12 = (undefined4 *)puVar10[4];
    puVar13 = *(undefined4 **)(param_2 + 0x10);
    for (uVar11 = puVar10[3] & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
      *puVar13 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar13 = puVar13 + 1;
    }
    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined1 *)puVar13 = *(undefined1 *)puVar12;
      puVar12 = (undefined4 *)((int)puVar12 + 1);
      puVar13 = (undefined4 *)((int)puVar13 + 1);
    }
    *(int *)(*(int *)(param_2 + 0x10) + puVar10[3] * 4) = iVar5;
  }
  else {
    iVar5 = FUN_009149f7();
    if (iVar5 == 0) {
      param_2 = 0;
    }
    else {
      param_2 = FUN_0091455d();
    }
    if (param_2 == 0) {
      return -0x7ff8fff2;
    }
    uVar4 = puVar10[1] / uVar11;
    iVar5 = FUN_00914a42((uVar11 + 1 ^ *puVar10) & 0xfffff ^ *puVar10,puVar10[1] + uVar4,
                         puVar10[3] + 1,0);
    if ((iVar5 < 0) || (iVar5 = FUN_00914593(), iVar5 < 0)) goto LAB_009310be;
    local_1c = 0;
    if (uVar4 != 0) {
      local_14 = uVar11 * 4;
      local_10 = 0;
      local_c = 0;
      iVar7 = local_14 + 4;
      do {
        bVar3 = true;
        if (1 < uVar11) {
          piVar6 = (int *)(puVar10[2] + local_c);
          iVar5 = *piVar6;
          local_24 = uVar11 - 1;
          do {
            piVar6 = piVar6 + 1;
            if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar6 * 4) + 0x10) !=
                *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar5 * 4) + 0x10)) {
              bVar3 = false;
            }
            local_24 = local_24 + -1;
          } while (local_24 != 0);
        }
        puVar12 = (undefined4 *)(puVar10[2] + local_c);
        puVar13 = (undefined4 *)(*(int *)(param_2 + 8) + local_10);
        for (uVar8 = uVar11; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar13 = *puVar12;
          puVar12 = puVar12 + 1;
          puVar13 = puVar13 + 1;
        }
        for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
          *(undefined1 *)puVar13 = *(undefined1 *)puVar12;
          puVar12 = (undefined4 *)((int)puVar12 + 1);
          puVar13 = (undefined4 *)((int)puVar13 + 1);
        }
        if (bVar3) {
          *(undefined4 *)(local_14 + *(int *)(param_2 + 8)) = *(undefined4 *)(local_c + puVar10[2]);
        }
        else {
          iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(local_10 + *(int *)(param_2 + 8)) * 4)
          ;
          uVar2 = *(undefined4 *)(iVar5 + 0xc);
          iVar9 = FUN_00915318(*(undefined4 *)(iVar5 + 4),uVar2,2,0);
          if (iVar9 == -1) goto LAB_00930e59;
          *(int *)(local_14 + *(int *)(param_2 + 8)) = iVar9;
          if ((*(int *)(iVar5 + 4) == *(int *)(in_ECX + 0x88)) &&
             (iVar5 = FUN_00930cf8(param_1,local_18,uVar2), iVar5 < 0)) goto LAB_009310be;
        }
        iVar5 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),param_3,2,0);
        if (iVar5 == -1) goto LAB_00930e59;
        puVar12 = (undefined4 *)puVar10[4];
        puVar13 = *(undefined4 **)(param_2 + 0x10);
        for (uVar8 = puVar10[3] & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar13 = *puVar12;
          puVar12 = puVar12 + 1;
          puVar13 = puVar13 + 1;
        }
        local_1c = local_1c + 1;
        for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
          *(undefined1 *)puVar13 = *(undefined1 *)puVar12;
          puVar12 = (undefined4 *)((int)puVar12 + 1);
          puVar13 = (undefined4 *)((int)puVar13 + 1);
        }
        *(int *)(*(int *)(param_2 + 0x10) + puVar10[3] * 4) = iVar5;
        local_c = local_c + uVar11 * 4;
        local_10 = local_10 + iVar7;
        local_14 = local_14 + iVar7;
      } while (local_1c < uVar4);
    }
  }
  FUN_00914ca1();
  FUN_008f4adb();
  param_2 = 0;
  iVar5 = 0;
LAB_009310be:
  if (param_2 != 0) {
    FUN_008f4adb();
  }
  return iVar5;
}


// ==== FUN_009310d5 @ 0x009310d5 ====

int FUN_009310d5(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  
  uVar4 = 0;
  if (*(int *)(in_ECX + 0x4c) != 0) {
    do {
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x230) + uVar4 * 4);
      if (((puVar1 != (uint *)0x0) &&
          (((uVar2 = **(uint **)(*(int *)(in_ECX + 0x230) + uVar4 * 4),
            (uVar2 & 0xfff00000) == 0x60500000 || ((*puVar1 & 0xfff00000) == 0x60000000)) &&
           (iVar3 = *(int *)(*(int *)(in_ECX + 0x14) +
                            *(int *)(puVar1[2] + (uVar2 & 0xfffff) * 4) * 4),
           *(int *)(iVar3 + 4) == *(int *)(in_ECX + 0x88))))) &&
         (iVar3 = FUN_00930cf8(*(undefined4 *)(in_ECX + 0x22c),*(undefined4 *)(in_ECX + 0x220),
                               *(undefined4 *)(iVar3 + 0xc)), iVar3 < 0)) {
        return iVar3;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(in_ECX + 0x4c));
  }
  return 0;
}


// ==== FUN_00931153 @ 0x00931153 ====

/* WARNING: Type propagation algorithm not settling */

int FUN_00931153(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  uint *puVar12;
  uint uVar13;
  bool bVar14;
  int local_26c [32];
  int local_1ec [32];
  int local_16c [8];
  uint local_14c [24];
  undefined4 auStack_ec [6];
  uint local_d4 [7];
  undefined4 local_b8 [17];
  uint local_74 [6];
  uint local_5c [6];
  int local_44;
  uint *local_40;
  int local_3c;
  uint *local_38;
  int local_34;
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
  
  puVar6 = local_14c;
  for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  puVar6 = local_74;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  puVar6 = local_d4;
  for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  puVar6 = local_5c;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  uVar4 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + uVar4 * 4);
      if (*(int *)(iVar3 + 4) == *(int *)(in_ECX + 0x88)) {
        *(undefined4 *)(iVar3 + 0xc) = 0xffffffff;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(in_ECX + 8));
  }
  if ((*(int *)(in_ECX + 0x22c) != 0) && (local_14 = (uint *)0x0, *(int *)(in_ECX + 0x220) != 0)) {
    iVar3 = 0;
    do {
      puVar6 = *(uint **)(iVar3 + *(int *)(in_ECX + 0x22c));
      if (((puVar6 != (uint *)0x0) && (uVar4 = *puVar6 & 0xfff00000, uVar4 != 0)) &&
         (uVar4 != 0x11000000)) {
        if (((((uVar4 == 0x60000000) || (uVar4 == 0x60500000)) ||
             ((uVar4 == 0x60a00000 || ((uVar4 == 0x72e00000 || (uVar4 == 0x60700000)))))) ||
            (uVar4 == 0x60f00000)) || (uVar4 == 0x72100000)) {
          iVar8 = *(int *)(iVar3 + *(int *)(in_ECX + 0x22c));
          local_28 = 0;
          local_18 = (uint *)0x0;
          local_c = (uint *)0x0;
          FUN_0093032e(*(undefined4 *)(in_ECX + 0x230),0,*(undefined4 *)(in_ECX + 0x224),
                       *(undefined4 *)(iVar8 + 0x10),*(undefined4 *)(iVar8 + 0xc),local_1ec,&local_c
                      );
          local_8 = (uint *)0x0;
          if (*(int *)(*(int *)(*(int *)(in_ECX + 0x22c) + iVar3) + 0xc) != 0) {
            local_38 = local_14;
            do {
              iVar8 = *(int *)(*(int *)(in_ECX + 0x14) +
                              *(int *)(*(int *)(*(int *)(*(int *)(in_ECX + 0x22c) + iVar3) + 0x10) +
                                      (int)local_8 * 4) * 4);
              *(uint **)(iVar8 + 0xc) = local_14;
              local_20 = (uint *)FUN_0092ea3e(*(int *)(in_ECX + 0x22c),(int)local_14 + 1,
                                              *(undefined4 *)(in_ECX + 0x220),
                                              *(undefined4 *)
                                               (*(int *)(*(int *)(*(int *)(in_ECX + 0x22c) + iVar3)
                                                        + 0x10) + (int)local_8 * 4),iVar8,&local_1c)
              ;
              uVar4 = FUN_0092ea3e(*(undefined4 *)(in_ECX + 0x230),0,*(undefined4 *)(in_ECX + 0x224)
                                   ,*(undefined4 *)
                                     (*(int *)(*(int *)(*(int *)(in_ECX + 0x22c) + iVar3) + 0x10) +
                                     (int)local_8 * 4),iVar8,&local_1c);
              if (local_28 < uVar4) {
                local_28 = uVar4;
              }
              if (local_1c == (uint *)0x0) {
                puVar6 = local_20;
              }
              else {
                puVar6 = (uint *)0xffffffff;
              }
              if (local_18 < puVar6) {
                local_18 = puVar6;
              }
              iVar10 = *(int *)(iVar8 + 0x10) + iVar3;
              local_8 = (uint *)((int)local_8 + 1);
              local_d4[iVar10] = uVar4;
              iVar8 = *(int *)(*(int *)(in_ECX + 0x22c) + iVar3);
              local_14c[iVar10] = (uint)puVar6;
            } while (local_8 < *(uint *)(iVar8 + 0xc));
          }
          puVar6 = local_38;
          local_8 = (uint *)0x0;
          bVar14 = local_c != (uint *)0x0;
          local_74[(int)local_38] = (uint)local_18;
          local_5c[(int)puVar6] = local_28;
          if (bVar14) {
            local_38 = local_14;
            do {
              iVar8 = local_1ec[(int)local_8];
              iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + iVar8 * 4);
              *(uint **)(iVar10 + 0xc) = local_14;
              uVar4 = FUN_0092ea3e(*(undefined4 *)(in_ECX + 0x230),0,*(undefined4 *)(in_ECX + 0x224)
                                   ,iVar8,iVar10,&local_1c);
              if (local_28 < uVar4) {
                local_28 = uVar4;
              }
              local_8 = (uint *)((int)local_8 + 1);
              local_d4[*(int *)(iVar10 + 0x10) + iVar3] = uVar4;
            } while (local_8 < local_c);
          }
          local_5c[(int)local_38] = local_28;
        }
        else {
          uVar4 = puVar6[3];
          local_20 = (uint *)0x0;
          local_c = (uint *)0x0;
          if (uVar4 != 0) {
            piVar1 = (int *)puVar6[4];
            do {
              if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar1 * 4) + 0xc) == -1) {
                local_20 = (uint *)0x1;
              }
              else {
                local_c = (uint *)0x1;
              }
              piVar1 = piVar1 + 1;
              uVar4 = uVar4 - 1;
            } while (uVar4 != 0);
            if (local_c != (uint *)0x0) {
              if (local_20 == (uint *)0x0) goto LAB_00931665;
              goto LAB_00931292;
            }
          }
          iVar8 = *(int *)(*(int *)(in_ECX + 0x22c) + iVar3);
          local_24 = (uint *)0x0;
          local_3c = (int)local_14 + 1;
          FUN_0093032e(*(int *)(in_ECX + 0x22c),local_3c,*(undefined4 *)(in_ECX + 0x220),
                       *(undefined4 *)(iVar8 + 0x10),*(undefined4 *)(iVar8 + 0xc),local_26c,
                       &local_24);
          iVar8 = *(int *)(iVar3 + *(int *)(in_ECX + 0x22c));
          iVar10 = 0;
          FUN_0093032e(*(undefined4 *)(in_ECX + 0x230),0,*(undefined4 *)(in_ECX + 0x224),
                       *(undefined4 *)(iVar8 + 0x10),*(undefined4 *)(iVar8 + 0xc),local_26c,
                       &local_24);
          iVar8 = *(int *)(iVar3 + *(int *)(in_ECX + 0x22c));
          if ((*(int *)(iVar8 + 0xc) == 1) &&
             (iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + **(int **)(iVar8 + 0x10) * 4),
             *(int *)(iVar10 + 0x10) != 4)) {
            iVar10 = 0;
          }
          local_10 = (uint *)0x0;
          local_c = local_14c;
          do {
            iVar8 = *(int *)(iVar3 + *(int *)(in_ECX + 0x22c));
            iVar8 = FUN_00930b35(local_10,*(undefined4 *)(in_ECX + 0x230),
                                 *(undefined4 *)(in_ECX + 0x224),*(undefined4 *)(iVar8 + 0x10),
                                 *(undefined4 *)(iVar8 + 0xc));
            if (iVar8 < 0) {
              return iVar8;
            }
            if (iVar8 != 1) {
              puVar6 = (uint *)0x0;
              if (iVar10 == 0) {
                if ((uint *)local_74[(int)local_10] <= local_14) goto LAB_009313b0;
              }
              else {
                puVar5 = local_c;
                do {
                  if ((uint *)*puVar5 <= local_14) {
                    local_30 = puVar6;
                    break;
                  }
                  puVar6 = (uint *)((int)puVar6 + 1);
                  puVar5 = puVar5 + 1;
                } while (puVar6 < (uint *)0x3);
                if (puVar6 != (uint *)0x3) break;
              }
            }
            local_10 = (uint *)((int)local_10 + 1);
            local_c = local_c + 4;
          } while (local_10 < (uint *)0x6);
          if (iVar10 != 0) {
            *(uint **)(iVar10 + 0x10) = local_30;
          }
LAB_009313b0:
          if (local_10 == (uint *)0x6) goto joined_r0x0093187b;
          local_18 = (uint *)0x0;
          local_28 = 0;
          local_8 = (uint *)0x0;
          if (local_24 != (uint *)0x0) {
            local_38 = local_10;
            do {
              piVar1 = local_26c + (int)local_8;
              iVar8 = *piVar1;
              local_c = *(uint **)(*(int *)(in_ECX + 0x14) + iVar8 * 4);
              local_c[3] = (uint)local_10;
              local_20 = (uint *)FUN_0092ea3e(*(undefined4 *)(in_ECX + 0x22c),local_3c,
                                              *(undefined4 *)(in_ECX + 0x220),iVar8,local_c,
                                              &local_1c);
              uVar4 = FUN_0092ea3e(*(undefined4 *)(in_ECX + 0x230),0,*(undefined4 *)(in_ECX + 0x224)
                                   ,*piVar1,local_c,&local_1c);
              if (local_28 < uVar4) {
                local_28 = uVar4;
              }
              if ((*(uint *)(in_ECX + 0x4c) <= uVar4) && (local_c[4] == 3)) {
                auStack_ec[(int)local_10] = 1;
              }
              if (local_1c != (uint *)0x0) {
                auStack_ec[(int)local_10] = 1;
              }
              if ((local_28 == 0) && (local_1c == (uint *)0x0)) {
                puVar6 = local_20;
              }
              else {
                puVar6 = (uint *)0xffffffff;
              }
              if (local_18 < puVar6) {
                local_18 = puVar6;
              }
              iVar8 = local_c[4] + (int)local_10 * 4;
              local_8 = (uint *)((int)local_8 + 1);
              local_d4[iVar8] = uVar4;
              bVar14 = local_8 < local_24;
              local_14c[iVar8] = (uint)puVar6;
            } while (bVar14);
          }
          puVar6 = local_10;
          local_74[(int)local_10] = (uint)local_18;
          local_5c[(int)puVar6] = local_28;
          FUN_0093048d();
        }
      }
LAB_00931665:
      local_14 = (uint *)((int)local_14 + 1);
      iVar3 = iVar3 + 4;
    } while (local_14 < *(uint **)(in_ECX + 0x220));
  }
  if ((*(int *)(in_ECX + 0x230) != 0) && (local_14 = (uint *)0x0, *(int *)(in_ECX + 0x224) != 0)) {
    do {
      puVar5 = local_14;
      local_30 = (uint *)((int)local_14 * 4);
      puVar6 = *(uint **)((int)local_30 + *(int *)(in_ECX + 0x230));
      if ((puVar6 != (uint *)0x0) &&
         ((uVar4 = *puVar6 & 0xfff00000, uVar4 != 0 && (uVar4 != 0x11000000)))) {
        if (((uVar4 == 0x60000000) ||
            (((((uVar4 == 0x60500000 || (uVar4 == 0x60a00000)) || (uVar4 == 0x60f00000)) ||
              (((uVar4 == 0x72e00000 || (uVar4 == 0x60700000)) ||
               ((uVar4 == 0x72300000 || ((uVar4 == 0x72500000 || (uVar4 == 0x72100000)))))))) ||
             (uVar4 == 0x72600000)))) ||
           ((((uVar4 == 0x72700000 || (uVar4 == 0x72800000)) || (uVar4 == 0x72a00000)) ||
            ((uVar4 == 0x72900000 || (uVar4 == 0x72b00000)))))) {
          local_10 = (uint *)0x0;
          local_8 = (uint *)0x0;
          if (puVar6[3] != 0) {
            do {
              local_40 = (uint *)((int)local_8 * 4);
              iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)((int)local_40 + puVar6[4]) * 4);
              if ((*(uint *)(in_ECX + 200) & 0xffff) == 0x104) {
                *(uint **)(iVar3 + 0xc) = local_14;
                local_38 = local_14;
              }
              else {
                local_38 = (uint *)((int)local_14 + 2);
                *(uint **)(iVar3 + 0xc) = local_38;
              }
              puVar5 = (uint *)FUN_0092ea3e(*(int *)(in_ECX + 0x230),(int)local_14 + 1,
                                            *(undefined4 *)(in_ECX + 0x224),
                                            *(undefined4 *)
                                             (*(int *)(*(int *)((int)local_30 +
                                                               *(int *)(in_ECX + 0x230)) + 0x10) +
                                             (int)local_40),iVar3,&local_1c);
              puVar6 = local_38;
              if (local_10 < puVar5) {
                local_10 = puVar5;
              }
              iVar8 = *(int *)(in_ECX + 0x230);
              local_d4[*(int *)(iVar3 + 0x10) + (int)local_38 * 4] = (uint)puVar5;
              iVar3 = *(int *)((int)local_30 + iVar8);
              local_20 = (uint *)0x0;
              FUN_0093032e(iVar8,(int)local_14 + 1,*(undefined4 *)(in_ECX + 0x224),
                           *(undefined4 *)(iVar3 + 0x10),*(undefined4 *)(iVar3 + 0xc),local_1ec,
                           &local_20);
              local_c = (uint *)0x0;
              if (local_20 != (uint *)0x0) {
                do {
                  iVar3 = local_1ec[(int)local_c];
                  iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4);
                  *(uint **)(iVar8 + 0xc) = puVar6;
                  puVar5 = (uint *)FUN_0092ea3e(*(undefined4 *)(in_ECX + 0x230),(int)local_14 + 1,
                                                *(undefined4 *)(in_ECX + 0x224),iVar3,iVar8,
                                                &local_1c);
                  if (local_10 < puVar5) {
                    local_10 = puVar5;
                  }
                  local_c = (uint *)((int)local_c + 1);
                  local_d4[*(int *)(iVar8 + 0x10) + (int)puVar6 * 4] = (uint)puVar5;
                } while (local_c < local_20);
              }
              FUN_0093048d();
              local_8 = (uint *)((int)local_8 + 1);
              local_30 = (uint *)((int)local_14 * 4);
              puVar6 = *(uint **)((int)local_30 + *(int *)(in_ECX + 0x230));
            } while (local_8 < (uint *)puVar6[3]);
          }
          if ((uint *)local_5c[(int)local_38] < local_10) {
            local_5c[(int)local_38] = (uint)local_10;
          }
        }
        else if ((uVar4 != 0x72200000) && (uVar4 != 0x72400000)) {
          if ((*(uint *)(in_ECX + 200) & 0xffff) == 0x101) {
            puVar7 = *(uint **)((int)local_30 + *(int *)(in_ECX + 0x230));
            uVar4 = *puVar7 & 0xfffff;
            local_30 = (uint *)(puVar7[1] / uVar4);
            local_20 = (uint *)0x0;
            local_2c = (uint *)0x0;
            if (local_30 != (uint *)0x0) {
              local_18 = (uint *)puVar6[2];
              local_34 = uVar4 * 4;
              do {
                local_24 = (uint *)0x0;
                iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + *local_18 * 4);
                if (local_2c != (uint *)0x0) {
                  local_c = (uint *)puVar6[2];
                  do {
                    iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + *local_c * 4);
                    if (((*(int *)(iVar3 + 4) == *(int *)(iVar8 + 4)) &&
                        (*(int *)(iVar3 + 8) == *(int *)(iVar8 + 8))) &&
                       (*(int *)(iVar3 + 0xc) == *(int *)(iVar8 + 0xc))) break;
                    local_24 = (uint *)((int)local_24 + 1);
                    local_c = local_c + uVar4;
                  } while (local_24 < local_2c);
                }
                if (((local_2c == local_24) && (*(int *)(iVar3 + 4) == *(int *)(in_ECX + 0x88))) &&
                   (1 < *(uint *)(iVar3 + 0xc))) {
                  local_20 = (uint *)((int)local_20 + 1);
                }
                local_2c = (uint *)((int)local_2c + 1);
                local_18 = local_18 + uVar4;
              } while (local_2c < local_30);
              if ((uint *)0x2 < local_20) {
                if (param_1 != 0) {
                  return -0x7fffbffb;
                }
                if (param_2 != 0) {
                  return -0x7fffbffb;
                }
                goto LAB_00931292;
              }
            }
          }
          uVar4 = puVar6[3];
          bVar14 = false;
          local_c = (uint *)0x0;
          if (uVar4 != 0) {
            piVar1 = (int *)puVar6[4];
            do {
              if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar1 * 4) + 0xc) == -1) {
                local_c = (uint *)0x1;
              }
              else {
                bVar14 = true;
              }
              piVar1 = piVar1 + 1;
              uVar4 = uVar4 - 1;
            } while (uVar4 != 0);
            if (bVar14) {
              if (local_c == (uint *)0x0) goto LAB_0093202c;
              goto LAB_00931292;
            }
          }
          iVar3 = *(int *)(*(int *)(in_ECX + 0x230) + (int)local_14 * 4);
          local_2c = (uint *)0x0;
          FUN_0093032e(*(int *)(in_ECX + 0x230),(int)local_14 + 1,*(undefined4 *)(in_ECX + 0x224),
                       *(undefined4 *)(iVar3 + 0x10),*(undefined4 *)(iVar3 + 0xc),local_16c,
                       &local_2c);
          local_1c = (uint *)0xffffffff;
          local_10 = (uint *)0xffffffff;
          local_8 = (uint *)(*(uint *)(in_ECX + 200) & 0xffff);
          if (((local_8 == (uint *)0x102) || (local_8 == (uint *)0x103)) &&
             (piVar1 = *(int **)(*(int *)(in_ECX + 0x230) + (int)puVar5 * 4), *piVar1 == 0x50000004)
             ) {
            piVar1 = (int *)piVar1[2];
            iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar1 * 4);
            if (*(int *)(iVar3 + 4) == *(int *)(in_ECX + 0x88)) {
              local_1c = *(uint **)(iVar3 + 0xc);
            }
            iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + piVar1[4] * 4);
            if (*(int *)(iVar3 + 4) == *(int *)(in_ECX + 0x88)) {
              local_10 = *(uint **)(iVar3 + 0xc);
            }
          }
          local_34 = 0;
          local_24 = (uint *)0x0;
          if (local_2c == (uint *)0x0) {
LAB_009319df:
            local_18 = (uint *)0x1;
            if (*(int *)(in_ECX + 0x44c) == 0) goto LAB_009319ee;
          }
          else {
            do {
              uVar4 = (int)puVar5 + 1;
              if (uVar4 < *(uint *)(in_ECX + 0x224)) {
                local_c = (uint *)(*(int *)(in_ECX + 0x230) + uVar4 * 4);
                iVar3 = *(uint *)(in_ECX + 0x224) - uVar4;
                do {
                  puVar6 = (uint *)*local_c;
                  if (((puVar6 != (uint *)0x0) && ((*puVar6 & 0xfff00000) == 0x70f00000)) &&
                     (puVar7 = (uint *)(*puVar6 & 0xfffff), puVar7 != (uint *)0x0)) {
                    piVar1 = (int *)puVar6[2];
                    local_20 = puVar7;
                    do {
                      if (*piVar1 == local_16c[(int)local_24]) {
                        local_34 = 1;
                      }
                      piVar1 = piVar1 + 1;
                      local_20 = (uint *)((int)local_20 - 1);
                    } while (local_20 != (uint *)0x0);
                  }
                  local_c = local_c + 1;
                  iVar3 = iVar3 + -1;
                } while (iVar3 != 0);
              }
              local_24 = (uint *)((int)local_24 + 1);
            } while (local_24 < local_2c);
            if (local_34 == 0) goto LAB_009319df;
LAB_009319ee:
            local_18 = (uint *)0x0;
          }
          local_30 = *(uint **)((int)puVar5 * 4 + *(int *)(in_ECX + 0x230));
          uVar4 = *local_30;
          if ((((uVar4 & 0xfffff) == 1) && ((uVar4 & 0xfff00000) != 0x50000000)) &&
             ((local_2c == (uint *)0x1 &&
              ((*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + local_16c[0] * 4) + 0x10) == 3 &&
               (local_18 != (uint *)0x0)))))) {
            local_24 = (uint *)0x1;
            puVar9 = local_b8;
            do {
              if ((local_14 < (uint *)local_5c[(int)local_24]) && ((uint *)*puVar9 <= local_14))
              break;
              local_24 = (uint *)((int)local_24 + 1);
              puVar9 = puVar9 + 4;
            } while (local_24 < (uint *)0x6);
            if (local_24 == (uint *)0x6) goto LAB_00931a6d;
          }
          else {
LAB_00931a6d:
            for (local_24 = (uint *)(uint)(local_18 != (uint *)0x0);
                (local_24 < (uint *)0x6 &&
                (((local_14 < (uint *)local_5c[(int)local_24] || (local_24 == local_1c)) ||
                 (local_24 == local_10)))); local_24 = (uint *)((int)local_24 + 1)) {
            }
          }
          if (((local_24 != (uint *)0x0) && (local_18 == (uint *)0x0)) &&
             (*(int *)(in_ECX + 0x44c) != 0)) goto joined_r0x0093187b;
          if (local_24 == (uint *)0x6) {
            if ((*(uint *)(in_ECX + 200) & 0xffff) != 0x104) goto LAB_00931292;
            goto joined_r0x00931884;
          }
          local_3c = 0;
          if ((((uVar4 & 0xfff00000) == 0x50000000) && (local_8 < (uint *)0x104)) &&
             (local_30[3] == 1)) {
            iVar8 = (int)local_14 * 4;
            iVar3 = *(int *)(iVar8 + *(int *)(in_ECX + 0x230));
            FUN_009304cc(*(int *)(in_ECX + 0x230),(int)local_14 + 1,*(undefined4 *)(in_ECX + 0x224),
                         *(undefined4 *)(iVar3 + 0x10),*(undefined4 *)(iVar3 + 0xc),&local_28,
                         &local_44,&local_40);
            if (local_44 != 0) {
              local_28 = 4;
            }
            bVar14 = local_28 < 4;
            if (bVar14) {
              local_28 = 3;
            }
            if (!bVar14 && local_28 != 4) {
              local_28 = 4;
            }
            iVar3 = FUN_009149f7();
            if (iVar3 == 0) {
              local_8 = (uint *)0x0;
            }
            else {
              local_8 = (uint *)FUN_0091455d();
            }
            if (local_8 == (uint *)0x0) {
              return -0x7ff8fff2;
            }
            puVar9 = *(undefined4 **)(iVar8 + *(int *)(in_ECX + 0x230));
            iVar3 = FUN_00914a42(*puVar9,puVar9[1],local_28,0);
            if (iVar3 < 0) {
              return iVar3;
            }
            iVar3 = FUN_00914593();
            puVar6 = local_8;
            if (iVar3 < 0) {
              return iVar3;
            }
            iVar3 = (int)local_14 * 4;
            puVar9 = *(undefined4 **)(*(int *)(*(int *)(in_ECX + 0x230) + iVar3) + 8);
            puVar11 = (undefined4 *)local_8[2];
            for (uVar4 = local_8[1] & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
              *puVar11 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar11 = puVar11 + 1;
            }
            for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
              *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
              puVar9 = (undefined4 *)((int)puVar9 + 1);
              puVar11 = (undefined4 *)((int)puVar11 + 1);
            }
            iVar8 = *(int *)(iVar3 + *(int *)(in_ECX + 0x230));
            puVar5 = *(uint **)(iVar8 + 0xc);
            puVar7 = *(uint **)(iVar8 + 0x10);
            puVar12 = local_74 + 2;
            local_30 = puVar5;
            for (; puVar5 != (uint *)0x0; puVar5 = (uint *)((int)puVar5 + -1)) {
              *puVar12 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar12 = puVar12 + 1;
            }
            *(uint **)(iVar3 + *(int *)(in_ECX + 0x230)) = puVar6;
            iVar3 = FUN_00915205();
            if (iVar3 < 0) {
              return iVar3;
            }
            puVar6 = (uint *)0x0;
            local_10 = (uint *)0x0;
            local_c = (uint *)0x0;
            if (local_30 != (uint *)0x0) {
              do {
                local_18 = (uint *)0x0;
                if (*(int *)(in_ECX + 8) != 0) {
                  do {
                    uVar4 = 0;
                    iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + (int)local_18 * 4);
                    if ((local_18 == (uint *)local_74[(int)local_c + 2]) ||
                       (*(uint **)(iVar3 + 0x38) == (uint *)local_74[(int)local_c + 2])) {
                      if (local_28 != 0) {
                        do {
                          uVar2 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),local_24,uVar4,0);
                          *(undefined4 *)(local_8[4] + uVar4 * 4) = uVar2;
                          if (*(int *)(local_8[4] + uVar4 * 4) == -1) {
                            return -0x7ff8fff2;
                          }
                          iVar8 = *(int *)(*(int *)(in_ECX + 0x14) +
                                          *(int *)(local_8[4] + uVar4 * 4) * 4);
                          *(undefined4 *)(iVar8 + 0x48) = *(undefined4 *)(iVar3 + 0x48);
                          *(undefined4 *)(iVar8 + 0x54) = *(undefined4 *)(iVar3 + 0x54);
                          *(undefined4 *)(iVar8 + 0x58) = *(undefined4 *)(iVar3 + 0x58);
                          uVar4 = uVar4 + 1;
                          *(undefined4 *)(iVar8 + 0x3c) = *(undefined4 *)(iVar3 + 0x3c);
                        } while (uVar4 < local_28);
                      }
                      local_1c = (uint *)((int)local_14 + 1);
                      while (local_1c < *(uint **)(in_ECX + 0x224)) {
                        puVar6 = *(uint **)(*(int *)(in_ECX + 0x230) + (int)local_1c * 4);
                        if ((puVar6 != (uint *)0x0) && (*puVar6 != 0)) {
                          uVar4 = *puVar6 & 0xfffff;
                          local_40 = (uint *)(puVar6[1] / uVar4);
                          local_20 = (uint *)0x0;
                          if (local_40 != (uint *)0x0) {
                            local_34 = 0;
                            do {
                              if (uVar4 < 3) {
                                if (uVar4 == 1) {
                                  puVar5 = (uint *)(puVar6[2] + (int)local_20 * 4);
                                  if ((uint *)*puVar5 == local_18) {
                                    if (local_28 == 4) {
                                      uVar13 = ((uint *)local_8[4])[3];
                                    }
                                    else {
                                      uVar13 = *(uint *)local_8[4];
                                    }
                                    *puVar5 = uVar13;
                                    if (local_10 < local_1c) {
                                      local_10 = local_1c;
                                    }
                                  }
                                }
                                else {
                                  uVar13 = 0;
                                  if (uVar4 != 0) {
                                    iVar3 = local_34;
                                    do {
                                      if ((*(uint **)(puVar6[2] + iVar3) == local_18) &&
                                         (*(uint *)(puVar6[2] + iVar3) =
                                               *(uint *)(local_8[4] + uVar13 * 4),
                                         local_10 < local_1c)) {
                                        local_10 = local_1c;
                                      }
                                      uVar13 = uVar13 + 1;
                                      iVar3 = iVar3 + 4;
                                    } while (uVar13 < uVar4);
                                  }
                                }
                              }
                              else {
                                uVar13 = 0;
                                if (uVar4 != 0) {
                                  iVar3 = local_34;
                                  do {
                                    if ((*(uint **)(puVar6[2] + iVar3) == local_18) &&
                                       (*(uint *)(puVar6[2] + iVar3) =
                                             *(uint *)(local_8[4] + uVar13 * 4), local_10 < local_1c
                                       )) {
                                      local_10 = local_1c;
                                    }
                                    uVar13 = uVar13 + 1;
                                    iVar3 = iVar3 + 4;
                                  } while (uVar13 < uVar4);
                                }
                              }
                              local_20 = (uint *)((int)local_20 + 1);
                              local_34 = local_34 + uVar4 * 4;
                            } while (local_20 < local_40);
                          }
                        }
                        local_1c = (uint *)((int)local_1c + 1);
                      }
                      local_3c = 1;
                      puVar6 = local_10;
                    }
                    local_18 = (uint *)((int)local_18 + 1);
                  } while (local_18 < *(uint **)(in_ECX + 8));
                }
                local_c = (uint *)((int)local_c + 1);
              } while (local_c < local_30);
            }
            puVar5 = local_24;
            if ((uint *)local_5c[(int)local_24] < puVar6) {
              local_5c[(int)local_24] = (uint)puVar6;
            }
            if ((uint *)local_d4[(int)puVar5 * 4] < puVar6) {
              local_d4[(int)puVar5 * 4] = (uint)puVar6;
            }
            if ((uint *)local_d4[(int)puVar5 * 4 + 1] < puVar6) {
              local_d4[(int)puVar5 * 4 + 1] = (uint)puVar6;
            }
            if ((uint *)local_d4[(int)puVar5 * 4 + 2] < puVar6) {
              local_d4[(int)puVar5 * 4 + 2] = (uint)puVar6;
            }
            if ((uint *)local_d4[(int)puVar5 * 4 + 3] < puVar6) {
              local_d4[(int)puVar5 * 4 + 3] = (uint)puVar6;
            }
            if (local_3c != 0) goto LAB_0093202c;
          }
          puVar6 = local_24;
          local_10 = (uint *)0x0;
          if (local_2c == (uint *)0x0) {
            **(undefined4 **)((int)local_14 * 4 + *(int *)(in_ECX + 0x230)) = 0;
          }
          else {
            local_8 = (uint *)0x0;
            if (local_2c != (uint *)0x0) {
              do {
                iVar3 = local_16c[(int)local_8];
                iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4);
                *(uint **)(iVar8 + 0xc) = puVar6;
                puVar5 = (uint *)FUN_0092ea3e(*(undefined4 *)(in_ECX + 0x230),(int)local_14 + 1,
                                              *(undefined4 *)(in_ECX + 0x224),iVar3,iVar8,&local_1c)
                ;
                if (local_10 < puVar5) {
                  local_10 = puVar5;
                }
                local_8 = (uint *)((int)local_8 + 1);
                local_d4[*(int *)(iVar8 + 0x10) + (int)puVar6 * 4] = (uint)puVar5;
              } while (local_8 < local_2c);
            }
            if ((uint *)local_5c[(int)puVar6] < local_10) {
              local_5c[(int)puVar6] = (uint)local_10;
            }
            FUN_0093048d();
          }
        }
      }
LAB_0093202c:
      local_14 = (uint *)((int)local_14 + 1);
    } while (local_14 < *(uint **)(in_ECX + 0x224));
  }
  if ((((*(int *)(in_ECX + 0x22c) == 0) || ((*(uint *)(in_ECX + 200) & 0xffff) != 0x104)) ||
      (param_1 != 0)) || (iVar3 = FUN_009310d5(), -1 < iVar3)) {
    iVar3 = 0;
  }
  return iVar3;
joined_r0x0093187b:
  if (param_1 == 0) {
joined_r0x00931884:
    if (param_2 == 0) {
LAB_00931292:
      FUN_0091a001();
    }
  }
  return -0x7fffbffb;
}


// ==== FUN_009320f4 @ 0x009320f4 ====

undefined4 FUN_009320f4(int param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  int in_ECX;
  uint uVar6;
  int *piVar7;
  bool bVar8;
  uint local_18;
  uint local_c;
  
  local_c = 0;
  if (param_2 != 0) {
    do {
      iVar1 = *(int *)(param_1 + local_c * 4);
      if ((iVar1 != 0) && (param_4 <= *(uint *)(iVar1 + 0xc))) {
        bVar5 = true;
        local_18 = 0;
        if (param_4 == 0) {
LAB_009321e1:
          return *(undefined4 *)(param_1 + local_c * 4);
        }
        do {
          iVar2 = *(int *)(param_3 + local_18 * 4);
          iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + iVar2 * 4);
          uVar6 = 0;
          if (param_5 == 0) {
            bVar8 = *(int *)(iVar1 + 0xc) == 0;
            if (*(int *)(iVar1 + 0xc) != 0) {
              piVar7 = *(int **)(iVar1 + 0x10);
              do {
                iVar4 = *piVar7;
                if (((iVar4 == iVar2) && (*(int *)(iVar3 + 0x3c) == 0)) ||
                   ((iVar4 == *(int *)(iVar3 + 0x38) &&
                    (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4) + 0x3c) == 0)))) break;
                uVar6 = uVar6 + 1;
                piVar7 = piVar7 + 1;
              } while (uVar6 < *(uint *)(iVar1 + 0xc));
              goto LAB_009321ad;
            }
          }
          else {
            bVar8 = *(int *)(iVar1 + 0xc) == 0;
            if (*(int *)(iVar1 + 0xc) != 0) {
              piVar7 = *(int **)(iVar1 + 0x10);
              do {
                if ((*piVar7 == iVar2) || (*piVar7 == *(int *)(iVar3 + 0x38))) break;
                uVar6 = uVar6 + 1;
                piVar7 = piVar7 + 1;
              } while (uVar6 < *(uint *)(iVar1 + 0xc));
LAB_009321ad:
              bVar8 = uVar6 == *(uint *)(iVar1 + 0xc);
            }
          }
          if (bVar8) {
            bVar5 = false;
          }
          local_18 = local_18 + 1;
        } while (local_18 < param_4);
        if (bVar5) goto LAB_009321e1;
      }
      local_c = local_c + 1;
    } while (local_c < param_2);
  }
  return 0;
}


// ==== FUN_009321ec @ 0x009321ec ====

undefined4
FUN_009321ec(undefined4 param_1,undefined4 param_2,uint *param_3,uint *param_4,int *param_5,
            undefined4 *param_6,int param_7,uint param_8)

{
  bool bVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  int iVar7;
  int in_ECX;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  puVar2 = param_3;
  uVar9 = *param_3 & 0xfffff;
  *param_6 = 0;
  *param_5 = 0;
  *param_4 = 0;
  if (uVar9 == 0) {
    uVar3 = 0x80004005;
  }
  else {
    uVar4 = param_3[1] / uVar9;
    if ((param_8 == 0) && (param_8 = 0, uVar4 != 0)) {
      param_3 = (uint *)0x0;
      do {
        uVar8 = 0;
        if (uVar9 != 0) {
          piVar5 = (int *)(puVar2[2] + (int)param_3);
          do {
            if (*(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar5 * 4) + 0x10) != uVar8) {
              return 1;
            }
            uVar8 = uVar8 + 1;
            piVar5 = piVar5 + 1;
          } while (uVar8 < uVar9);
        }
        param_8 = param_8 + 1;
        param_3 = (uint *)((int)param_3 + uVar9 * 4);
      } while (param_8 < uVar4);
    }
    iVar10 = 0;
    bVar1 = false;
    param_3 = (uint *)0x0;
    if (uVar4 != 0) {
      do {
        puVar6 = (uint *)FUN_009320f4(param_1,param_2,puVar2[2] + iVar10 * 4,uVar9,param_7);
        if (puVar6 != (uint *)0x0) {
          uVar8 = *puVar6 & 0xfff00000;
          if (param_7 == 0) {
            if (uVar8 == 0x72100000) goto LAB_009322db;
          }
          else if ((((uVar8 == 0x60000000) || (uVar8 == 0x60500000)) || (uVar8 == 0x60a00000)) ||
                  (uVar8 == 0x60f00000)) {
LAB_009322db:
            if (bVar1) {
              *param_5 = 0;
              *param_4 = 0;
              *param_6 = 0;
              return 1;
            }
            *param_6 = puVar6;
            bVar1 = true;
            *param_5 = iVar10;
            if (param_7 == 0) {
              iVar7 = *(int *)puVar6[2];
            }
            else {
              iVar7 = *(int *)(puVar6[2] + (*puVar6 & 0xfffff) * 4);
            }
            *param_4 = (uint)*(byte *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar7 * 4) + 0x6d);
          }
        }
        param_3 = (uint *)((int)param_3 + 1);
        iVar10 = iVar10 + uVar9;
      } while (param_3 < uVar4);
    }
    uVar3 = 0;
  }
  return uVar3;
}


// ==== FUN_0093234d @ 0x0093234d ====

int FUN_0093234d(int *param_1,uint param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  uint uVar7;
  int local_50 [5];
  int local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  int *local_c;
  int local_8;
  
  local_8 = 0;
  local_10 = 0;
  if (param_2 != 0) {
    local_c = param_1;
    do {
      puVar1 = (uint *)*local_c;
      if (puVar1 != (uint *)0x0) {
        local_24 = *puVar1;
        uVar7 = local_24 & 0xfffff;
        local_1c = uVar7;
        FUN_009321ec(param_3,4,puVar1,&local_18,&local_28,&local_14,1,1);
        if (local_14 == 0) {
          if (uVar7 == 2) {
            uVar7 = puVar1[2];
            local_20 = FUN_009320f4(*(undefined4 *)(in_ECX + 0x22c),*(undefined4 *)(in_ECX + 0x220),
                                    uVar7 + 8,1,0);
            local_30 = FUN_009320f4(*(undefined4 *)(in_ECX + 0x22c),*(undefined4 *)(in_ECX + 0x220),
                                    uVar7 + 0xc,1,0);
            if ((((local_20 != 0) && (local_30 != 0)) &&
                (FUN_009321ec(param_3,4,local_20,&local_18,&local_28,&local_2c,1,1), local_2c != 0))
               && (FUN_009321ec(param_3,4,local_30,&local_18,&local_28,&local_14,1,1),
                  local_2c == local_14)) {
              uVar7 = local_1c;
              goto LAB_00932470;
            }
          }
        }
        else if (uVar7 != 2) {
LAB_00932470:
          if (local_14 != 0) {
            uVar6 = 0;
            local_8 = 0;
            if (uVar7 == 3) {
              if (((local_24 & 0xfff00000) == 0x60f00000) || ((local_24 & 0xfff00000) == 0x60a00000)
                 ) {
                local_28 = 1;
                piVar4 = (int *)(puVar1[2] + 0xc);
                do {
                  iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar4 * 4);
                  if (*(uint *)(iVar5 + 0x10) != uVar6) {
                    local_28 = 0;
                  }
                  iVar5 = *(int *)(iVar5 + 0x3c);
                  if ((iVar5 != 0) && (iVar5 != 0x60000)) goto LAB_009327f9;
                  uVar6 = uVar6 + 1;
                  piVar4 = piVar4 + 1;
                } while (uVar6 < 3);
                if (local_28 != 0) {
                  if ((*(uint *)(in_ECX + 200) & 0xffff) < 0x102) {
                    FUN_0091a001();
                    return -0x7fffbffb;
                  }
                  iVar5 = FUN_009149f7();
                  if (iVar5 == 0) {
                    local_8 = 0;
                  }
                  else {
                    local_8 = FUN_0091455d();
                  }
                  if (local_8 == 0) {
LAB_0093281a:
                    iVar5 = -0x7ff8fff2;
                  }
                  else {
                    iVar5 = FUN_00914a42(0x72600003,6,4,0);
                    if (-1 < iVar5) goto LAB_0093260f;
                  }
                  goto LAB_009327a9;
                }
              }
            }
            else if ((uVar7 == 2) && ((local_24 & 0xfff00000) == 0x60500000)) {
              uVar7 = 0;
              bVar3 = true;
              local_50[2] = 3;
              local_50[3] = 0;
              local_50[0] = 1;
              local_50[1] = 2;
              local_28 = 1;
              do {
                iVar5 = local_20;
                if (uVar7 != 0) {
                  iVar5 = local_30;
                }
                iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + **(int **)(iVar5 + 8) * 4);
                iVar2 = *(int *)(iVar5 + 0x10);
                if (iVar2 != local_50[uVar7 + 2]) {
                  local_28 = 0;
                }
                if (iVar2 != local_50[uVar7]) {
                  bVar3 = false;
                }
                if (*(int *)(iVar5 + 0x3c) != 0) {
LAB_009327f9:
                  FUN_0091a001();
                  return -0x7fffbffb;
                }
                uVar7 = uVar7 + 1;
              } while (uVar7 < 2);
              if ((local_28 != 0) || (bVar3)) {
                iVar5 = FUN_009149f7();
                if (iVar5 == 0) {
                  local_8 = 0;
                }
                else {
                  local_8 = FUN_0091455d();
                }
                if (local_8 == 0) goto LAB_0093281a;
                iVar5 = FUN_00914a42((-(uint)bVar3 & 0x100000) + 0x72700002,4,4,0);
                if (iVar5 < 0) goto LAB_009327a9;
LAB_0093260f:
                uVar7 = 0;
                do {
                  *(undefined4 *)(uVar7 + *(int *)(local_8 + 0x10)) =
                       *(undefined4 *)(uVar7 + *(int *)(*local_c + 0x10));
                  uVar7 = uVar7 + 4;
                } while (uVar7 < 0x10);
                iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + **(int **)(*local_c + 8) * 4);
                local_34 = *(undefined4 *)
                            (*(int *)(in_ECX + 0x14) + *(int *)(*(int *)(local_14 + 8) + 0xc) * 4);
                if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar5 + 4) * 4) + 5) & 8)
                    == 0) {
                  for (uVar7 = local_18; (uVar7 < 4 && (*(int *)(param_3 + uVar7 * 4) != 0));
                      uVar7 = uVar7 + 1) {
                  }
                  if (uVar7 == 4) goto LAB_0093266e;
                  *(uint *)(iVar5 + 0xc) = uVar7;
                  local_28 = uVar7;
                }
                else {
                  local_28 = *(uint *)(iVar5 + 0xc);
                  if ((3 < local_28) || (*(int *)(param_3 + local_28 * 4) != 0)) {
LAB_0093266e:
                    iVar5 = -0x7fffbffb;
                    goto LAB_009327a9;
                  }
                }
                uVar7 = local_28;
                local_3c = FUN_00915318(*(undefined4 *)(in_ECX + 0x80),local_28,0,0);
                if (local_3c == -1) goto LAB_0093281a;
                iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + local_3c * 4);
                FUN_00914e44();
                *(uint *)(iVar5 + 0x6c) = uVar7 << 8 | 3;
                *(uint *)(iVar5 + 0xc) = uVar7;
                uVar6 = 0;
                if (local_1c != 0) {
                  local_24 = local_1c << 2;
                  do {
                    local_50[4] = FUN_00915318(*(undefined4 *)(in_ECX + 0x80),local_18,uVar6,0);
                    if (local_50[4] == -1) goto LAB_0093281a;
                    iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + local_50[4] * 4);
                    local_38 = *(int *)(*(int *)(in_ECX + 0x14) +
                                       *(int *)(local_1c * 4 + *(int *)(*local_c + 8)) * 4);
                    FUN_00914e44();
                    *(uint *)(iVar5 + 0xc) = local_18;
                    *(uint *)(iVar5 + 0x10) = uVar6;
                    *(undefined4 *)(iVar5 + 0x3c) = *(undefined4 *)(local_38 + 0x3c);
                    *(int *)(*(int *)(local_8 + 8) + uVar6 * 4) = local_3c;
                    uVar7 = local_24 + 4;
                    uVar6 = uVar6 + 1;
                    *(int *)(local_24 + *(int *)(local_8 + 8)) = local_50[4];
                    local_24 = uVar7;
                  } while (uVar6 < local_1c);
                  uVar7 = local_28;
                }
                *(int *)(param_3 + uVar7 * 4) = local_8;
                iVar5 = FUN_00915205();
                if (iVar5 < 0) goto LAB_009327a9;
                *local_c = 0;
                local_8 = 0;
              }
            }
          }
        }
      }
      local_10 = local_10 + 1;
      local_c = local_c + 1;
    } while (local_10 < param_2);
  }
  iVar5 = 0;
LAB_009327a9:
  if (local_8 != 0) {
    FUN_008f4adb();
  }
  return iVar5;
}


// ==== FUN_00932821 @ 0x00932821 ====

/* WARNING: Type propagation algorithm not settling */

int FUN_00932821(int *param_1,uint param_2,int param_3,uint param_4)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  uint auStack_88 [6];
  uint auStack_70 [9];
  uint local_4c [4];
  uint auStack_3c [4];
  uint local_2c;
  uint *local_28;
  uint local_24;
  uint local_20;
  uint *local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  local_2c = 0;
  local_4c[0] = 0;
  local_4c[1] = 0;
  local_4c[2] = 0;
  if (param_2 != 0) {
    local_18 = param_1;
    do {
      puVar1 = (uint *)*local_18;
      if (puVar1 != (uint *)0x0) {
        uVar5 = *puVar1 & 0xfffff;
        uVar6 = uVar5;
        if ((*puVar1 & 0xfff00000) == 0x60000000) {
          uVar6 = 1;
        }
        if ((uVar6 == param_4) && ((*puVar1 & 0xfff00000) != 0x11000000)) {
          local_c = 0;
          local_8 = 0;
          if (param_4 != 0) {
            local_10 = (int *)(puVar1[2] + uVar5 * 4);
            do {
              piVar3 = (int *)FUN_009320f4(*(undefined4 *)(in_ECX + 0x22c),
                                           *(undefined4 *)(in_ECX + 0x220),local_10,1,0);
              uVar6 = local_8;
              local_14 = piVar3;
              auStack_70[local_8 + 6] = (uint)piVar3;
              if ((piVar3 == (int *)0x0) || (*piVar3 != 0x50000003)) {
                local_c = 1;
              }
              else {
                FUN_009321ec(*(undefined4 *)(in_ECX + 0x22c),*(undefined4 *)(in_ECX + 0x220),
                             local_14,auStack_70 + uVar6 + 0xd,auStack_70 + uVar6,auStack_88 + uVar6
                             ,0,0);
                local_1c = auStack_88 + uVar6 + 3;
                FUN_009321ec(param_3,4,local_14,local_1c,auStack_70 + uVar6 + 3,local_4c + 3,1,0);
                if (((auStack_88[uVar6] == 0) || (*local_1c != auStack_88[3])) || (local_4c[3] == 0)
                   ) {
                  local_c = 1;
                }
              }
              local_8 = local_8 + 1;
              local_10 = local_10 + 1;
            } while (local_8 < param_4);
            if (local_c != 0) goto LAB_00932d97;
          }
          local_8 = 0;
          if (param_4 != 0) {
            do {
              uVar6 = local_8;
              local_20 = *(uint *)(in_ECX + 0x4c);
              if (local_20 < *(uint *)(in_ECX + 0x224)) {
                local_14 = (int *)(*(int *)(in_ECX + 0x230) + local_20 * 4);
                do {
                  local_10 = (int *)*local_14;
                  if (((local_10 != (int *)0x0) &&
                      (puVar1 = (uint *)*local_18, puVar1 != (uint *)0x0)) && (*local_10 != 0)) {
                    local_c = *puVar1 & 0xfffff;
                    local_24 = puVar1[1];
                    if (*puVar1 == 0x72d00003) {
                      local_24 = 6;
                    }
                    if (local_c < local_24) {
                      local_1c = (uint *)local_10[1];
                      do {
                        local_28 = (uint *)0x0;
                        if (local_1c != (uint *)0x0) {
                          iVar4 = *(int *)(puVar1[2] + local_c * 4);
                          piVar3 = (int *)local_10[2];
                          do {
                            if ((*piVar3 == iVar4) ||
                               (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar3 * 4) + 0x38) ==
                                iVar4)) goto LAB_00932dd9;
                            local_28 = (uint *)((int)local_28 + 1);
                            piVar3 = piVar3 + 1;
                            local_1c = (uint *)local_10[1];
                          } while (local_28 < (uint *)local_10[1]);
                        }
                        local_c = local_c + 1;
                      } while (local_c < local_24);
                    }
                  }
                  local_14 = local_14 + 1;
                  local_20 = local_20 + 1;
                } while (local_20 < *(uint *)(in_ECX + 0x224));
              }
              if ((local_8 != 0) &&
                 ((auStack_70[local_8 + 0xc] <= auStack_88[3] ||
                  (auStack_70[local_8 + 0xd] != auStack_70[local_8 + 0xc] + 1)))) goto LAB_00932e42;
              if ((*(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                    *(int *)(*(int *)(auStack_70[local_8 + 6] + 8) +
                                            auStack_70[local_8] * 4) * 4) + 0x3c) != 0) ||
                 ((iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                            *(int *)(*(int *)(auStack_70[local_8 + 6] + 8) +
                                                    auStack_70[local_8 + 3] * 4) * 4) + 0x3c),
                  iVar4 != 0 && (iVar4 != 0x60000)))) goto LAB_00932dd9;
              iVar4 = FUN_009149f7();
              if (iVar4 == 0) {
                uVar5 = 0;
              }
              else {
                uVar5 = FUN_0091455d();
              }
              auStack_70[uVar6 + 9] = uVar5;
              if (uVar5 == 0) {
                iVar4 = -0x7ff8fff2;
                goto LAB_00932dac;
              }
              if (local_8 == param_4 - 1) {
                if (*(int *)*local_18 == 0x72d00003) {
                  if (param_4 != 3) {
LAB_00932e22:
                    iVar4 = 1;
                    goto LAB_00932dac;
                  }
                  uVar8 = 4;
                  uVar7 = 9;
                  iVar4 = 0x72a00003;
                }
                else if (*(int *)*local_18 == 0x72c00003) {
                  if (param_4 != 3) goto LAB_00932e22;
                  uVar8 = 4;
                  uVar7 = 6;
                  iVar4 = 0x72900003;
                }
                else {
                  uVar8 = 4;
                  uVar7 = 6;
                  if (param_4 != 1) {
                    iVar4 = ((param_4 != 3) - 1 & 0x200000) + 0x72300003;
                    goto LAB_00932b5f;
                  }
                  iVar4 = 0x72b00003;
                }
              }
              else {
                uVar8 = 0;
                iVar4 = ((param_4 != 3) - 1 & 0x200000) + 0x72200003;
LAB_00932b5f:
                uVar7 = 6;
              }
              iVar4 = FUN_00914a42(iVar4,uVar7,uVar8);
              if (iVar4 < 0) goto LAB_00932dac;
              local_8 = local_8 + 1;
            } while (local_8 < param_4);
          }
          local_8 = 0;
          if (param_4 != 0) {
            do {
              local_14 = (int *)0x0;
              uVar6 = auStack_70[local_8 + 9];
              local_1c = (uint *)auStack_70[local_8 + 6];
              local_10 = (int *)auStack_88[local_8];
              local_24 = auStack_70[local_8 + 3] << 2;
              local_20 = auStack_70[local_8] << 2;
              uVar5 = 0xc;
              do {
                *(undefined4 *)((uVar5 - 0xc) + *(int *)(uVar6 + 8)) =
                     *(undefined4 *)(local_20 + local_1c[2]);
                *(undefined4 *)(uVar5 + *(int *)(uVar6 + 8)) =
                     *(undefined4 *)(local_24 + local_1c[2]);
                local_c = *(uint *)(*(int *)(in_ECX + 0x14) +
                                   *(int *)(*(int *)(uVar6 + 8) + -0xc + uVar5) * 4);
                auStack_3c[3] =
                     *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(uVar5 + *(int *)(uVar6 + 8)) * 4);
                iVar4 = FUN_00915318(*(undefined4 *)(in_ECX + 0x80),0,0,0);
                local_28 = *(uint **)(*(int *)(in_ECX + 0x14) + iVar4 * 4);
                *(int *)(uVar5 + *(int *)(uVar6 + 8)) = iVar4;
                FUN_00914e44();
                auStack_3c[3] = *(uint *)(auStack_3c[3] + 0x3c);
                FUN_00914e44();
                local_28[4] = (uint)local_14;
                local_28[0xf] = auStack_3c[3];
                if ((*(int *)*local_18 == 0x72d00003) && (local_8 == param_4 - 1)) {
                  *(undefined4 *)(uVar5 + 0xc + *(int *)(uVar6 + 8)) =
                       *(undefined4 *)(uVar5 + 0xc + ((int *)*local_18)[2]);
                }
                local_14 = (int *)((int)local_14 + 1);
                local_20 = local_20 + 4;
                local_24 = local_24 + 4;
                uVar5 = uVar5 + 4;
              } while (uVar5 < 0x18);
              local_8 = local_8 + 1;
            } while (local_8 < param_4);
          }
          uVar6 = auStack_70[param_4 + 8];
          uVar5 = 0;
          do {
            *(undefined4 *)(uVar5 + *(int *)(uVar6 + 0x10)) =
                 *(undefined4 *)(uVar5 + *(int *)(*local_18 + 0x10));
            uVar5 = uVar5 + 4;
          } while (uVar5 < 0x10);
          uVar6 = 0;
          if (param_4 != 0) {
            do {
              if (*(int *)(param_3 + auStack_70[uVar6 + 0xd] * 4) != 0) goto LAB_00932de2;
              uVar6 = uVar6 + 1;
            } while (uVar6 < param_4);
          }
          iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + **(int **)(*local_18 + 8) * 4);
          uVar6 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar4 + 4) * 4) + 4);
          if (-1 < (char)uVar6) {
LAB_00932dd9:
            FUN_0091a001();
LAB_00932de2:
            iVar4 = -0x7fffbffb;
            goto LAB_00932dac;
          }
          if ((uVar6 & 0x840) == 0) {
            *(uint *)(iVar4 + 0xc) = auStack_70[param_4 + 0xc];
          }
          else if (auStack_70[param_4 + 0xc] != *(uint *)(iVar4 + 0xc)) {
LAB_00932e42:
            FUN_0091a001();
            goto LAB_00932de2;
          }
          local_8 = 0;
          if (param_4 != 0) {
            do {
              iVar2 = local_8 + 9;
              *(uint *)(param_3 + auStack_70[local_8 + 0xd] * 4) = auStack_70[iVar2];
              iVar4 = FUN_00915205();
              if (iVar4 < 0) goto LAB_00932dac;
              *local_18 = 0;
              auStack_70[iVar2] = 0;
              local_8 = local_8 + 1;
            } while (local_8 < param_4);
          }
        }
      }
LAB_00932d97:
      local_2c = local_2c + 1;
      local_18 = local_18 + 1;
    } while (local_2c < param_2);
  }
  iVar4 = 0;
LAB_00932dac:
  uVar6 = 0;
  do {
    if (auStack_70[uVar6 + 9] != 0) {
      FUN_008f4adb();
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 < 3);
  return iVar4;
}


// ==== FUN_00932e4d @ 0x00932e4d ====

uint FUN_00932e4d(void)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  uint *puVar5;
  int in_ECX;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  int local_24 [8];
  
  local_24[0] = 0;
  local_24[1] = 0;
  local_24[2] = 0;
  local_24[3] = 0;
  *(undefined4 *)(in_ECX + 0x218) = 0;
  *(undefined4 *)(in_ECX + 0x21c) = 0;
  bVar3 = 0;
  puVar8 = (undefined4 *)(in_ECX + 0x1f8);
  for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  local_24[6] = 0;
  local_24[5] = 0;
  local_24[4] = 0;
  local_24[7] = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar6 = *(int *)(*(int *)(in_ECX + 0x14) + local_24[7] * 4);
      iVar2 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar6 + 4) * 4);
      if ((*(int *)(iVar6 + 8) != -1) && (local_24[6] == 0)) {
        FUN_0091a001();
        local_24[6] = 1;
        bVar3 = 1;
      }
      uVar4 = *(uint *)(iVar2 + 4);
      if ((uVar4 & 0x20) == 0) {
        if (((uVar4 & 0x10) != 0) && ((uVar4 & 0x200) == 0)) {
          uVar4 = (uint)*(byte *)(iVar6 + 0x6d);
          uVar7 = *(uint *)(iVar6 + 0x6c) & 0xff;
          if (uVar7 == 1) {
            if (uVar4 < 2) {
              puVar5 = (uint *)(in_ECX + 0x218 + uVar4 * 4);
              goto LAB_00932f76;
            }
          }
          else if ((uVar7 == 3) && (uVar4 < 8)) {
            puVar5 = (uint *)(in_ECX + 0x1f8 + uVar4 * 4);
LAB_00932f76:
            uVar4 = *(int *)(iVar6 + 0x10) + 1;
            if (*puVar5 < uVar4) {
              *puVar5 = uVar4;
            }
          }
        }
      }
      else {
        bVar1 = *(byte *)(iVar6 + 0x6d);
        if (3 < bVar1) break;
        uVar4 = *(uint *)(iVar6 + 0x6c) & 0xff;
        if (uVar4 == 1) {
          if (bVar1 == 0) {
            local_24[*(int *)(iVar6 + 0x10)] = 1;
            local_24[4] = *(undefined4 *)(iVar6 + 0x60);
          }
        }
        else if ((((uVar4 == 2) && (bVar1 == 0)) && (*(int *)(iVar6 + 0x10) != 0)) &&
                (local_24[5] == 0)) {
          FUN_0091a001();
          local_24[5] = 1;
          bVar3 = 1;
        }
      }
      local_24[7] = local_24[7] + 1;
    } while ((uint)local_24[7] < *(uint *)(in_ECX + 8));
  }
  iVar6 = 0;
  uVar4 = 0;
  do {
    iVar6 = iVar6 + (uint)(local_24[uVar4] != 0);
    uVar4 = uVar4 + 1;
  } while (uVar4 < 4);
  if (iVar6 != 4) {
    FUN_0091a001();
    bVar3 = 1;
  }
  return -(uint)bVar3 & 0x80004005;
}


// ==== FUN_00932fd4 @ 0x00932fd4 ====

int FUN_00932fd4(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 local_48 [4];
  undefined4 local_38 [4];
  undefined1 local_28 [16];
  int *local_18;
  undefined1 *local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  iVar5 = *(int *)(in_ECX + 0x100);
  local_18 = *(int **)(*(int *)(in_ECX + 0x100) + 0x10);
  local_8 = *(int *)(*(int *)(in_ECX + 0x100) + 0xc);
  uVar4 = 0;
  do {
    *(undefined4 *)((int)local_48 + uVar4) = *(undefined4 *)(*(int *)(iVar5 + 8) + 0xc);
    *(undefined4 *)((int)local_38 + uVar4) = *(undefined4 *)(*(int *)(iVar5 + 8) + 0x1c);
    uVar4 = uVar4 + 4;
  } while (uVar4 < 0x10);
  iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + *local_18 * 4);
  if (*(int *)(iVar5 + 4) == *(int *)(in_ECX + 0x84)) {
    iVar2 = local_8;
    if (*(int *)(iVar5 + 0x6c) != 1) {
      FUN_0091a001();
      return -0x7fffbffb;
    }
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + *local_18 * 4) + 0xc) = 0;
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + *local_18 * 4) + 4) =
           *(undefined4 *)(in_ECX + 0x88);
    }
  }
  if (local_8 != 0) {
    local_14 = local_28 + -(int)local_18;
    local_10 = local_8;
    local_c = local_18;
    do {
      piVar3 = local_c;
      iVar5 = FUN_00915318(0,0,0,0);
      local_c = local_c + 1;
      *(int *)(local_14 + (int)piVar3) = iVar5;
      puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar5 * 4);
      puVar6 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + *piVar3 * 4);
      puVar7 = puVar1;
      for (iVar5 = 0x20; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar1[0xf] = 0;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
    local_10 = 0;
  }
  piVar3 = local_18;
  iVar5 = *(int *)(*(int *)(in_ECX + 0x100) + 8);
  iVar5 = FUN_0094d663(8,local_28,local_8,iVar5,iVar5 + 0x10,0,2,0,0,0,0);
  if (-1 < iVar5) {
    iVar5 = FUN_0094d663(4,piVar3,local_8,local_48,local_38,local_28,local_8,0,0,0,0);
  }
  return iVar5;
}


// ==== FUN_00933121 @ 0x00933121 ====

int FUN_00933121(uint param_1)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *in_ECX;
  uint uVar5;
  int *piVar6;
  undefined4 local_c;
  uint local_8;
  
  puVar1 = (uint *)in_ECX[0x40];
  piVar2 = (int *)puVar1[2];
  uVar5 = *puVar1 & 0xfffff;
  piVar6 = (int *)(-(uint)(uVar5 != puVar1[1]) & (uint)(piVar2 + uVar5));
  piVar3 = (int *)(-(uint)(uVar5 * 2 < *(uint *)(in_ECX[0x40] + 4)) & (uint)(piVar2 + uVar5 * 2));
  iVar4 = FUN_0094d495(param_1);
  if (-1 < iVar4) {
    param_1 = (uint)*(byte *)(*(int *)(in_ECX[5] + *piVar2 * 4) + 0x6d);
    local_8 = param_1 | 0xb0000000;
    iVar4 = (**(code **)(*in_ECX + 100))(local_8,0xf0000,0);
    if (-1 < iVar4) {
      if (piVar6 != (int *)0x0) {
        iVar4 = (**(code **)(*in_ECX + 0x74))
                          (*(undefined4 *)(in_ECX[5] + *piVar6 * 4),&local_8,&param_1);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = (**(code **)(*in_ECX + 0x78))(piVar6,uVar5,0xf0000,&local_c);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = (**(code **)(*in_ECX + 0x68))(local_8,local_c,param_1);
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      if (piVar3 != (int *)0x0) {
        iVar4 = (**(code **)(*in_ECX + 0x74))
                          (*(undefined4 *)(in_ECX[5] + *piVar3 * 4),&local_8,&param_1);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = (**(code **)(*in_ECX + 0x78))(piVar3,uVar5,0xf0000,&local_c);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = (**(code **)(*in_ECX + 0x68))(local_8,local_c,param_1);
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      iVar4 = (**(code **)(*in_ECX + 0x60))();
      if ((-1 < iVar4) && (iVar4 = FUN_00948616(), -1 < iVar4)) {
        iVar4 = 0;
      }
    }
  }
  return iVar4;
}


// ==== FUN_00933266 @ 0x00933266 ====

int FUN_00933266(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar2 = *(uint *)in_ECX[0x40];
  iVar3 = FUN_0094d495(0x42);
  if (-1 < iVar3) {
    iVar3 = (**(code **)(*in_ECX + 0x6c))
                      (*(undefined4 *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 0x10) * 4),&local_8,0,0
                      );
    if (-1 < iVar3) {
      iVar3 = (**(code **)(*in_ECX + 100))(local_8,0xf0000,0);
      if (-1 < iVar3) {
        piVar1 = (int *)(*(int *)(in_ECX[0x40] + 8) + (uVar2 & 0xfffff) * 4);
        iVar3 = (**(code **)(*in_ECX + 0x74))
                          (*(undefined4 *)(in_ECX[5] + *piVar1 * 4),&local_8,&local_c);
        if (-1 < iVar3) {
          iVar3 = (**(code **)(*in_ECX + 0x78))(piVar1,uVar2 & 0xfffff,0xf0000,&local_10);
          if (-1 < iVar3) {
            iVar3 = (**(code **)(*in_ECX + 0x68))(local_8,local_10 | 0x9000000,local_c);
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
  return iVar3;
}


// ==== FUN_00933341 @ 0x00933341 ====

int FUN_00933341(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  undefined1 local_10 [4];
  undefined4 local_c;
  undefined4 local_8;
  
  uVar2 = *(uint *)in_ECX[0x40];
  iVar3 = FUN_0094d495(0x42);
  if (-1 < iVar3) {
    iVar3 = (**(code **)(*in_ECX + 0x6c))
                      (*(undefined4 *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 0x10) * 4),&local_8,0,0
                      );
    if (-1 < iVar3) {
      iVar3 = (**(code **)(*in_ECX + 100))(local_8,0xf0000,0);
      if (-1 < iVar3) {
        piVar1 = (int *)(*(int *)(in_ECX[0x40] + 8) + (uVar2 & 0xfffff) * 4);
        iVar3 = (**(code **)(*in_ECX + 0x74))
                          (*(undefined4 *)(in_ECX[5] + *piVar1 * 4),&local_8,&local_c);
        if (-1 < iVar3) {
          iVar3 = (**(code **)(*in_ECX + 0x78))(piVar1,uVar2 & 0xfffff,0xf0000,local_10);
          if (-1 < iVar3) {
            iVar3 = (**(code **)(*in_ECX + 0x68))(local_8,0xaf40000,local_c);
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
  return iVar3;
}


// ==== FUN_00933413 @ 0x00933413 ====

int FUN_00933413(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  uint uVar3;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  undefined4 local_8;
  
  uVar3 = *(uint *)in_ECX[0x40] & 0xfffff;
  local_c = uVar3;
  if ((in_ECX[0x32] & 0xffffU) == 0x104) {
    iVar2 = FUN_0094d495(0x42);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*in_ECX + 0x6c))
                      (*(undefined4 *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 0x10) * 4),&local_8,0,0
                      );
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*in_ECX + 100))(local_8,0xf0000,0);
    if (iVar2 < 0) {
      return iVar2;
    }
    piVar1 = (int *)(*(int *)(in_ECX[0x40] + 8) + uVar3 * 4);
    iVar2 = (**(code **)(*in_ECX + 0x74))
                      (*(undefined4 *)(in_ECX[5] + *piVar1 * 4),&local_8,&local_10);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*in_ECX + 0x78))(piVar1,local_c,0xf0000,&local_14);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*in_ECX + 0x68))(local_8,local_14,local_10);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*in_ECX + 0x60))();
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_00948616();
  }
  else {
    iVar2 = FUN_0094d495(0x42);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*in_ECX + 0x6c))
                      (*(undefined4 *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 0x10) * 4),&local_8,0,0
                      );
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*in_ECX + 100))(local_8,0xf0000,0);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*in_ECX + 0x60))();
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_00948616();
  }
  if (-1 < iVar2) {
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_00933564 @ 0x00933564 ====

int FUN_00933564(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  uint uVar4;
  undefined1 local_18 [4];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = *(undefined4 *)(in_ECX[5] + *(int *)((uint *)in_ECX[0x40])[4] * 4);
  uVar4 = *(uint *)in_ECX[0x40] & 0xfffff;
  if ((in_ECX[0x32] & 0xffffU) == 0x104) {
    iVar3 = FUN_0094d495(0x40);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(*in_ECX + 0x6c))(uVar1,&local_8,0,&local_c);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(*in_ECX + 0x70))
                      (*(undefined4 *)(in_ECX[0x40] + 0x10),uVar4,&local_10,local_c);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(*in_ECX + 100))(local_8,0x70000,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    piVar2 = *(int **)(in_ECX[0x40] + 8);
    iVar3 = (**(code **)(*in_ECX + 0x74))
                      (*(undefined4 *)(in_ECX[5] + *piVar2 * 4),&local_8,&local_14);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(*in_ECX + 0x78))(piVar2,uVar4,local_10,local_18);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(*in_ECX + 0x68))(local_8,0xe40000,local_14);
  }
  else {
    iVar3 = FUN_0094d495(0x40);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(*in_ECX + 0x6c))(uVar1,&local_8,0,&local_c);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(*in_ECX + 0x70))
                      (*(undefined4 *)(in_ECX[0x40] + 0x10),uVar4,&local_10,local_c);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(*in_ECX + 100))(local_8,0xf0000,0);
  }
  if (((-1 < iVar3) && (iVar3 = (**(code **)(*in_ECX + 0x60))(), -1 < iVar3)) &&
     (iVar3 = FUN_00948616(), -1 < iVar3)) {
    iVar3 = 0;
  }
  return iVar3;
}


// ==== FUN_009336b5 @ 0x009336b5 ====

uint FUN_009336b5(uint param_1)

{
  int in_ECX;
  
  if (*(int *)(*(int *)(in_ECX + 0x100) + 0x24) == 1) {
    param_1 = param_1 | 0x40000000;
  }
  return param_1;
}


// ==== FUN_009336d2 @ 0x009336d2 ====

int FUN_009336d2(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_0094b4db(*(undefined4 *)(in_ECX + 200));
  if (-1 < iVar1) {
    iVar1 = FUN_00948616();
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ==== FUN_009336f5 @ 0x009336f5 ====

undefined4 FUN_009336f5(int param_1,uint *param_2)

{
  uint uVar1;
  int in_ECX;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)(param_1 + 0x6d);
  uVar1 = *(uint *)(param_1 + 0x6c) & 0xff;
  if (uVar1 == 1) {
    if (*(uint *)(in_ECX + 0x28) <= uVar2) {
      return 0x80004005;
    }
  }
  else {
    if (uVar1 != 3) {
      if (uVar1 == 5) {
        *param_2 = 0xc;
        return 0;
      }
      return 0x80004005;
    }
    if (*(uint *)(in_ECX + 0x3c) <= uVar2) {
      return 0x80004005;
    }
    uVar2 = uVar2 + 2;
  }
  *param_2 = uVar2;
  return 0;
}


// ==== FUN_00933744 @ 0x00933744 ====

undefined4 FUN_00933744(int param_1,uint *param_2,undefined4 *param_3)

{
  byte bVar1;
  uint uVar2;
  int in_ECX;
  undefined4 uVar3;
  
  uVar2 = *(uint *)(param_1 + 0x6c);
  bVar1 = *(byte *)(param_1 + 0x6d);
  *param_2 = (uint)bVar1;
  uVar2 = uVar2 & 0xff;
  uVar3 = 1;
  if (uVar2 == 1) {
    uVar2 = *(uint *)(in_ECX + 0x28);
  }
  else {
    uVar3 = 3;
    if (uVar2 != 3) {
      return 0x80004005;
    }
    uVar2 = *(uint *)(in_ECX + 0x3c);
  }
  if (bVar1 < uVar2) {
    *param_3 = uVar3;
    return 0;
  }
  return 0x80004005;
}


// ==== FUN_00933789 @ 0x00933789 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_00933789(ushort *param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int in_ECX;
  char *_Source;
  char *pcVar5;
  uint uVar6;
  bool bVar7;
  undefined4 uVar8;
  char *pcVar9;
  uint local_30;
  char *local_2c;
  char local_28 [31];
  undefined1 local_9;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  _Source = *(char **)(*(int *)(param_1 + 0x34) + 0x18);
  uVar6 = 0;
  bVar2 = false;
  local_30 = 0;
  _strncpy(local_28,_Source,0x1f);
  local_9 = 0;
  pcVar5 = local_28;
  if (local_28[0] == '\0') {
LAB_009337f4:
    local_2c = (char *)0x0;
  }
  else {
    do {
      iVar4 = _isalpha((int)*pcVar5);
      if (iVar4 == 0) break;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar5 != '\0');
    if (*pcVar5 == '\0') goto LAB_009337f4;
    local_2c = (char *)_atol(pcVar5);
  }
  if (*pcVar5 != '\0') {
    *pcVar5 = '\0';
    pcVar5 = pcVar5 + 1;
  }
  cVar3 = *pcVar5;
  if (cVar3 == '\0') {
LAB_00933827:
    local_2c = (char *)((int)local_2c + (*(uint *)(param_1 + 0x38) >> 2));
  }
  else {
    do {
      iVar4 = _isdigit((int)cVar3);
      if (iVar4 == 0) break;
      pcVar5 = pcVar5 + 1;
      cVar3 = *pcVar5;
    } while (cVar3 != '\0');
    if (*pcVar5 == '\0') goto LAB_00933827;
    local_2c = (char *)0xffffffff;
  }
  if (*(uint *)(param_1 + 0x36) == 0xffffffff) {
    iVar4 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(param_1 + 2) * 4);
    pcVar5 = (char *)FUN_009154c0(param_1);
    uVar6 = *(uint *)(iVar4 + 4);
    if (((uVar6 & 0x10) != 0) && ((uVar6 & 0x200) == 0)) {
      iVar4 = __stricmp(local_28,s_color_00a27b04);
      if (iVar4 == 0) {
        local_30 = 1;
        if (param_2 == 0) {
          pcVar9 = *(char **)(in_ECX + 0x28);
        }
        else {
          pcVar9 = (char *)0x2;
        }
LAB_009338dd:
        bVar7 = local_2c < pcVar9;
LAB_00933956:
        uVar6 = 1 - bVar7;
      }
      else {
        iVar4 = __stricmp(local_28,s_texcoord_00a27948);
        if (iVar4 == 0) {
          local_30 = 3;
          if (param_2 == 0) {
            pcVar9 = *(char **)(in_ECX + 0x3c);
          }
          else {
            pcVar9 = (char *)0x8;
          }
          goto LAB_009338dd;
        }
        iVar4 = __stricmp(local_28,s_position_00a27b64);
        if (((iVar4 == 0) || (iVar4 = __stricmp(local_28,&DAT_00a27b00), iVar4 == 0)) ||
           (iVar4 = __stricmp(local_28,s_psize_00a27b38), iVar4 == 0)) {
          bVar7 = local_2c == (char *)0x0;
          local_30 = 4;
          goto LAB_00933956;
        }
        iVar4 = __stricmp(local_28,s_diffuse_00a2b6f0);
        if (iVar4 == 0) {
          local_30 = 1;
          uVar6 = (uint)(local_2c != (char *)0x0);
          bVar2 = true;
          if (uVar6 == 0) {
            local_2c = (char *)0x0;
          }
        }
        else {
          iVar4 = __stricmp(local_28,s_specular_00a2b6e4);
          if (iVar4 == 0) {
            local_30 = 1;
            uVar6 = (uint)(local_2c != (char *)0x0);
            bVar2 = true;
            if (uVar6 == 0) {
              local_2c = (char *)0x1;
            }
          }
          else {
            local_30 = 0;
            uVar6 = 1;
          }
        }
      }
      if ((param_2 == 0) || (*(int *)(param_1 + 8) == 0)) {
        if (uVar6 == 0) {
          if (bVar2) {
            FUN_0091a096(in_ECX,*(undefined4 *)(param_1 + 0x34),0x1261,
                         s__s_semantic___s__has_been_deprec_00a2b68c,pcVar5,_Source,
                         *(undefined4 *)(local_30 * 4 + 0xb59f60),local_2c);
          }
        }
        else {
          FUN_0091a001(in_ECX,*(undefined4 *)(param_1 + 0x34),0x1196,
                       s_invalid__s_semantic___s__00a2b6c8,pcVar5,_Source);
        }
      }
      if (((local_30 == 4) || (uVar6 != 0)) && ((*(int *)(in_ECX + 0x448) == 0 && (param_2 == 0))))
      {
        *(int *)(in_ECX + 0x448) = 1;
        FUN_0091a001(in_ECX,*(undefined4 *)(param_1 + 0x34),0x1196,
                     s_invalid_reference_to__s_semantic_00a2b664,pcVar5,_Source);
        uVar6 = 1;
      }
      goto LAB_00933b0a;
    }
    if ((uVar6 & 0x20) != 0) {
      iVar4 = __stricmp(local_28,s_color_00a27b04);
      if (iVar4 == 0) {
        local_30 = 1;
        uVar6 = (uint)(*(char **)(in_ECX + 0x48) <= local_2c);
LAB_00933ab6:
        if (uVar6 != 0) goto LAB_00933aba;
      }
      else {
        iVar4 = __stricmp(local_28,s_depth_00a27af8);
        if (iVar4 != 0) {
          local_30 = 0;
          uVar6 = 1;
          goto LAB_00933ab6;
        }
        local_30 = 4;
        uVar6 = 1;
LAB_00933aba:
        if ((param_2 == 0) || (*(int *)(param_1 + 8) == 0)) {
          FUN_0091a001(in_ECX,*(undefined4 *)(param_1 + 0x34),0x1196,
                       s_invalid__s_semantic___s__00a2b6c8,pcVar5,_Source);
        }
      }
      if (local_30 == 4) {
        if (param_2 != 0) goto LAB_00933bd4;
        pcVar9 = s__s_semantic___s__not_yet_impleme_00a2b634;
        uVar8 = *(undefined4 *)(param_1 + 0x34);
        goto LAB_00933b02;
      }
      goto LAB_00933b0a;
    }
  }
  else {
    _Source = (char *)(uint)*(byte *)((int)param_1 + 0x6d);
    local_30 = *(uint *)(param_1 + 0x36) & 0xff;
    local_2c = _Source;
    if (local_30 == 4) {
      if ((*(int *)(in_ECX + 0x448) != 0) || (param_2 != 0)) goto LAB_00933bd4;
      uVar6 = 1;
      *(int *)(in_ECX + 0x448) = 1;
      pcVar5 = local_28;
      pcVar9 = s_invalid_reference_to_input_seman_00a2b6f8;
      uVar8 = *(undefined4 *)(param_1 + 0x34);
LAB_00933b02:
      FUN_0091a001(in_ECX,uVar8,0x1196,pcVar9,pcVar5,_Source);
    }
LAB_00933b0a:
    if (local_30 == 3) {
      if ((((local_2c != (char *)0x0) && (local_2c < (char *)0x4)) && (*(int *)(param_1 + 8) == 3))
         && ((*(uint *)(in_ECX + 200) & 0xffff) < 0x104)) {
        piVar1 = (int *)(in_ECX + 0x43c);
        if (*piVar1 == -1) {
          iVar4 = FUN_009152bf(&DAT_00a2b62c,0x51,0xffffffff,4);
          *piVar1 = iVar4;
        }
        iVar4 = *piVar1;
        if (iVar4 == -1) {
          return 0x8007000e;
        }
        param_1[6] = 0;
        param_1[7] = 0;
        local_30 = 5;
        *(int *)(param_1 + 2) = iVar4;
        *(char **)(param_1 + 8) = local_2c + -1;
        goto LAB_00933bd4;
      }
      if (((local_2c < *(char **)(in_ECX + 0x3c)) || (param_2 != 0)) ||
         (*(int *)(in_ECX + 0x448) != 0)) goto LAB_00933bd4;
      uVar6 = 1;
      *(int *)(in_ECX + 0x448) = 1;
      FUN_0091a001(in_ECX,*(undefined4 *)(param_1 + 0x34),0x1196,
                   s__texcoord__reference_exceeds_val_00a2b5e0,*(char **)(in_ECX + 0x3c));
    }
    if (local_30 == 1) {
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
    if (local_30 != 0) goto LAB_00933bd4;
  }
  uVar6 = 1;
LAB_00933bd4:
  if ((char *)0xffff < local_2c) {
    uVar6 = 1;
  }
  *(uint *)(param_1 + 0x36) = local_30 | (int)local_2c << 8;
  return -(uint)(uVar6 != 0) & 0x80004005;
}


// ==== FUN_00933c0c @ 0x00933c0c ====

undefined4 FUN_00933c0c(int param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x6c);
  uVar2 = (uint)*(byte *)(param_1 + 0x6d);
  *param_2 = uVar2;
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 1) {
    if (uVar2 != 0) {
      return 0x80004005;
    }
    *param_3 = 0;
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0;
    }
  }
  else {
    if (uVar1 != 2) {
      return 0x80004005;
    }
    if (uVar2 != 0) {
      return 0x80004005;
    }
    *param_3 = 9;
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 1;
    }
  }
  return 0;
}


// ==== FUN_00933c6a @ 0x00933c6a ====

undefined4 FUN_00933c6a(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  int *piVar3;
  uint local_8;
  
  local_8 = 0;
  if (*(uint *)(param_1 + 4) != 0) {
    piVar3 = *(int **)(param_1 + 8);
    do {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar3 * 4);
      if (((*(int *)(in_ECX + 0x88) == *(int *)(iVar1 + 4)) &&
          (uVar2 = *(uint *)(iVar1 + 0x50), uVar2 < param_2)) &&
         ((*(ushort *)(*(int *)(*(int *)(in_ECX + 0x18) + uVar2 * 4) + 2) & 0xfff0) != 0)) {
        return 1;
      }
      local_8 = local_8 + 1;
      piVar3 = piVar3 + 1;
    } while (local_8 < *(uint *)(param_1 + 4));
  }
  return 0;
}


// ==== FUN_00933ccc @ 0x00933ccc ====

undefined4 FUN_00933ccc(uint *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  char cVar7;
  undefined4 uVar8;
  int *piVar9;
  uint uVar10;
  int in_ECX;
  uint uVar11;
  bool bVar12;
  uint auStack_b0 [18];
  uint auStack_68 [19];
  uint local_1c;
  int *local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  if (param_1 == (uint *)0x0) {
    uVar8 = 1;
  }
  else {
    uVar11 = *param_1 & 0xfff00000;
    if ((uVar11 == 0) || (uVar11 == 0x20700000)) {
      uVar8 = 0;
    }
    else {
      local_c = *param_1 & 0xfffff;
      local_1c = param_1[1] / local_c;
      if (1 < local_1c) {
        iVar1 = *(int *)(in_ECX + 0x80);
        iVar2 = *(int *)(in_ECX + 0x88);
        iVar3 = *(int *)(in_ECX + 0x7c);
        iVar4 = *(int *)(in_ECX + 0x94);
        local_8 = 0;
        auStack_68[iVar1] = 0;
        auStack_68[iVar2] = 0;
        auStack_68[iVar3] = 0;
        auStack_68[iVar4] = 0;
        auStack_b0[iVar1] = 2;
        auStack_b0[iVar2] = 3;
        auStack_b0[iVar3] = 2;
        bVar12 = local_1c != 0;
        auStack_b0[iVar4] = 1;
        local_10 = 0;
        if (bVar12) {
          piVar5 = (int *)param_1[2];
          local_14 = piVar5;
          do {
            iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + *local_14 * 4);
            param_1 = (uint *)0x0;
            uVar11 = *(uint *)(iVar1 + 4);
            if (local_10 != 0) {
              piVar9 = piVar5;
              do {
                iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar9 * 4);
                if ((((uVar11 == *(uint *)(iVar2 + 4)) &&
                     (*(int *)(iVar1 + 8) == *(int *)(iVar2 + 8))) &&
                    (*(int *)(iVar1 + 0xc) == *(int *)(iVar2 + 0xc))) &&
                   ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + uVar11 * 4) + 5) & 1) == 0 ||
                     ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar2 + 4) * 4) + 5) &
                      1) == 0)) || (*(double *)(iVar1 + 0x20) == *(double *)(iVar2 + 0x20)))))
                break;
                param_1 = (uint *)((int)param_1 + 1);
                piVar9 = piVar9 + local_c;
              } while (param_1 < local_10);
            }
            if (param_1 == (uint *)local_10) {
              if (uVar11 == *(uint *)(in_ECX + 0x80)) {
                uVar10 = *(uint *)(in_ECX + 0x80);
                if (*(char *)(iVar1 + 0x6c) == '\x03') {
                  if ((((*(uint *)(in_ECX + 200) & 0xffff) == 0x101) &&
                      (local_8 = local_8 + 1, 2 < local_8)) && (param_2 == (uint *)0x0)) {
                    return 1;
                  }
                  uVar10 = *(uint *)(in_ECX + 0x88);
                }
              }
              else {
                uVar10 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + uVar11 * 4) + 4);
                cVar7 = (char)uVar10;
                if ((uVar10 & 0x200) == 0) {
                  if (cVar7 < '\0') goto LAB_00933e76;
                  uVar10 = uVar11;
                }
                else if (cVar7 < '\0') {
LAB_00933e76:
                  uVar10 = *(uint *)(in_ECX + 0x94);
                }
                else {
                  uVar10 = *(uint *)(in_ECX + 0x7c);
                }
              }
              if (((*(int *)(iVar1 + 0x48) != -1) && (uVar11 == *(uint *)(in_ECX + 0x88))) &&
                 ((*(uint *)(in_ECX + 200) & 0xffff) == 0x101)) {
                puVar6 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(iVar1 + 0x48) * 4);
                if ((puVar6 != (uint *)0x0) &&
                   ((((uVar11 = *puVar6 & 0xfff00000, uVar11 == 0x60f00000 || (uVar11 == 0x60500000)
                      ) || ((uVar11 == 0x60a00000 || (uVar11 == 0x60000000)))) &&
                    ((local_8 = local_8 + 1, 2 < local_8 && (param_2 == (uint *)0x0)))))) {
                  return 1;
                }
                uVar10 = *(uint *)(in_ECX + 0x88);
              }
              if (uVar10 < 0x12) {
                puVar6 = auStack_68 + uVar10;
                *puVar6 = *puVar6 + 1;
                if (auStack_b0[uVar10] < *puVar6) {
                  if (param_2 != (uint *)0x0) {
                    *param_2 = local_10;
                  }
                  return 1;
                }
              }
            }
            local_14 = local_14 + local_c;
            local_10 = local_10 + 1;
          } while (local_10 < local_1c);
        }
      }
      uVar8 = 0;
    }
  }
  return uVar8;
}


// ==== FUN_00933f2e @ 0x00933f2e ====

undefined4 FUN_00933f2e(int param_1,int *param_2,uint param_3,int *param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *in_ECX;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint *puVar11;
  uint local_18;
  uint local_14;
  int *local_c;
  
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
  }
  if (param_3 != 0) {
    uVar7 = (uint)param_2;
    if (param_4 == (int *)0x0) {
      for (; uVar7 < param_3; uVar7 = uVar7 + 1) {
        iVar4 = *(int *)(param_1 + uVar7 * 4);
        if (iVar4 != 0) {
          *(undefined4 *)(iVar4 + 0x24) = 0;
        }
      }
    }
    uVar7 = (uint)param_2;
    if (param_2 < param_3 - 1) {
      do {
        puVar11 = *(uint **)(param_1 + uVar7 * 4);
        uVar8 = uVar7;
        if (puVar11 != (uint *)0x0) {
          puVar9 = (uint *)0x0;
          if (param_4 != (int *)0x0) {
            *param_4 = *param_4 + 1;
          }
          do {
            if (param_3 - 1 <= uVar7) break;
            uVar7 = uVar7 + 1;
            puVar9 = *(uint **)(param_1 + uVar7 * 4);
          } while (puVar9 == (uint *)0x0);
          bVar3 = false;
          uVar8 = uVar7 - 1;
          if (puVar9 != (uint *)0x0) {
            bVar1 = false;
            if (param_4 == (int *)0x0) {
              puVar11[9] = 0;
              puVar9[9] = 0;
            }
            if (((*puVar11 & 0xfffff) == 1) && ((*puVar9 & 0xfffff) < 4)) {
              bVar1 = true;
              puVar10 = puVar11;
              puVar11 = puVar9;
LAB_00934002:
              if ((in_ECX[0x32] & 0xffffU) != 0x104) {
                iVar4 = (**(code **)(*in_ECX + 0xa4))(puVar11,puVar10);
                if (iVar4 != 0) goto LAB_0093419e;
              }
              uVar5 = *puVar11 & 0xfff00000;
              if ((((((uVar5 != 0x72100000) && (uVar5 != 0x72000000)) && (uVar5 != 0x72e00000)) &&
                   (((uVar5 != 0x60700000 && (uVar5 != 0x60500000)) &&
                    ((uVar5 != 0x60a00000 && ((uVar5 != 0x60000000 && (uVar5 != 0x60f00000))))))))
                  && (uVar5 != 0x11000000)) && (uVar5 != 0)) {
                bVar2 = false;
                if (puVar11[3] != 0) {
                  local_c = (int *)puVar11[4];
                  local_18 = puVar11[3];
                  do {
                    iVar4 = *local_c;
                    if (*(int *)(*(int *)(in_ECX[5] + iVar4 * 4) + 0x10) == 3) {
                      bVar3 = true;
                    }
                    if (puVar10[1] != 0) {
                      param_2 = (int *)puVar10[2];
                      local_14 = puVar10[1];
                      do {
                        if ((*(int *)(*(int *)(in_ECX[5] + *param_2 * 4) + 0x38) == iVar4) ||
                           (*param_2 == iVar4)) {
                          bVar2 = true;
                        }
                        param_2 = param_2 + 1;
                        local_14 = local_14 - 1;
                      } while (local_14 != 0);
                    }
                    local_c = local_c + 1;
                    local_18 = local_18 - 1;
                  } while (local_18 != 0);
                }
                param_2 = (int *)0x0;
                if (puVar10[3] != 0) {
                  do {
                    if (puVar11[1] != 0) {
                      local_18 = puVar11[1];
                      iVar4 = *(int *)(puVar10[4] + (int)param_2 * 4);
                      piVar6 = (int *)puVar11[2];
                      do {
                        if ((*(int *)(*(int *)(in_ECX[5] + *piVar6 * 4) + 0x38) == iVar4) ||
                           (*piVar6 == iVar4)) {
                          bVar2 = true;
                        }
                        piVar6 = piVar6 + 1;
                        local_18 = local_18 - 1;
                      } while (local_18 != 0);
                    }
                    param_2 = (int *)((int)param_2 + 1);
                  } while (param_2 < puVar10[3]);
                }
                if ((((!bVar2) && (!bVar3)) &&
                    (*(int *)(*(int *)(in_ECX[5] + *(int *)puVar10[4] * 4) + 0x10) == 3)) &&
                   (uVar8 = uVar7, param_4 == (int *)0x0)) {
                  if (bVar1) {
                    puVar11[9] = 1;
                  }
                  else {
                    puVar10[9] = 1;
                  }
                }
              }
            }
            else if ((*puVar11 & 0xfffff) != 4) {
              puVar10 = puVar9;
              if ((*puVar9 & 0xfffff) == 1) goto LAB_00934002;
            }
          }
        }
LAB_0093419e:
        uVar7 = uVar8 + 1;
      } while (uVar7 < param_3 - 1);
    }
    if ((uVar7 != param_3) && (param_4 != (int *)0x0)) {
      *param_4 = *param_4 + 1;
    }
  }
  return 0;
}


// ==== FUN_009341c0 @ 0x009341c0 ====

undefined4 FUN_009341c0(uint *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  bool bVar10;
  uint auStack_cc [18];
  uint auStack_84 [18];
  int local_3c;
  uint local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  if (param_1 == (uint *)0x0) {
    uVar3 = 1;
  }
  else if ((*param_1 & 0xfff00000) == 0) {
    uVar3 = 0;
  }
  else {
    local_10 = *param_1 & 0xfffff;
    local_8 = 0;
    local_c = 0;
    local_1c = 0;
    local_20 = param_1[1] / local_10;
    uVar8 = param_2[1];
    uVar7 = *param_2 & 0xfffff;
    iVar4 = *(int *)(in_ECX + 0x80);
    iVar1 = *(int *)(in_ECX + 0x88);
    auStack_84[iVar4] = 0;
    auStack_84[iVar1] = 0;
    iVar5 = *(int *)(in_ECX + 0x7c);
    auStack_84[iVar5] = 0;
    auStack_cc[iVar4] = 2;
    uVar2 = local_20;
    auStack_cc[iVar1] = 5;
    auStack_cc[iVar5] = 3;
    local_38 = uVar8 / uVar7 + uVar2;
    if (local_38 != 0) {
      local_18 = 0;
      local_28 = local_10 << 2;
      local_2c = uVar7 * uVar2 * -4;
      local_30 = uVar7 << 2;
      local_3c = local_2c;
      do {
        if (local_8 < local_20) {
          iVar4 = *(int *)(local_18 + param_1[2]);
        }
        else {
          iVar4 = *(int *)(local_2c + param_2[2]);
        }
        iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4);
        iVar1 = *(int *)(iVar4 + 4);
        local_34 = *(int *)(*(int *)(in_ECX + 0x10) + iVar1 * 4);
        local_14 = 0;
        if (local_8 != 0) {
          local_10 = 0;
          local_24 = local_3c;
          do {
            if (local_14 < local_20) {
              puVar6 = param_1;
              uVar8 = local_10;
            }
            else {
              puVar6 = param_2;
              uVar8 = local_24;
            }
            iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(uVar8 + puVar6[2]) * 4);
            if (((iVar1 == *(int *)(iVar5 + 4)) && (*(int *)(iVar4 + 8) == *(int *)(iVar5 + 8))) &&
               (*(int *)(iVar4 + 0xc) == *(int *)(iVar5 + 0xc))) break;
            local_24 = local_24 + local_30;
            local_14 = local_14 + 1;
            local_10 = local_10 + local_28;
          } while (local_14 < local_8);
        }
        if (local_14 == local_8) {
          if (((iVar1 == *(int *)(in_ECX + 0x88)) && (1 < *(uint *)(iVar4 + 0xc))) &&
             (local_c = local_c + 1, 3 < local_c)) {
            return 1;
          }
          iVar5 = *(int *)(in_ECX + 0x80);
          if (iVar1 == iVar5) {
            if (*(char *)(iVar4 + 0x6c) == '\x03') {
              if (((*(uint *)(in_ECX + 200) & 0xffff) == 0x101) &&
                 (local_c = local_c + 1, 3 < local_c)) {
                return 1;
              }
              iVar5 = *(int *)(in_ECX + 0x88);
            }
            puVar6 = auStack_84 + iVar5;
            *puVar6 = *puVar6 + 1;
            bVar9 = *puVar6 < auStack_cc[iVar5];
            bVar10 = *puVar6 == auStack_cc[iVar5];
          }
          else {
            uVar8 = *(uint *)(local_34 + 4);
            if ((char)uVar8 < '\0') break;
            if ((uVar8 & 0x200) == 0) {
              iVar4 = *(int *)(iVar4 + 4);
              puVar6 = auStack_84 + iVar4;
              *puVar6 = *puVar6 + 1;
              bVar9 = *puVar6 < auStack_cc[iVar4];
              bVar10 = *puVar6 == auStack_cc[iVar4];
            }
            else {
              local_1c = local_1c + 1;
              bVar9 = local_1c < 3;
              bVar10 = local_1c == 3;
            }
          }
          if (!bVar9 && !bVar10) {
            return 1;
          }
        }
        local_8 = local_8 + 1;
        local_18 = local_18 + local_28;
        local_2c = local_2c + local_30;
      } while (local_8 < local_38);
    }
    uVar3 = 0;
  }
  return uVar3;
}


// ==== FUN_009343ec @ 0x009343ec ====

undefined4 FUN_009343ec(int param_1,uint param_2,uint param_3,uint *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  undefined4 *puVar7;
  int *piVar8;
  bool bVar9;
  int local_28 [8];
  int local_8;
  
  bVar9 = (param_3 & 0x10000) != 0;
  if (bVar9) {
    local_28[4] = 0;
  }
  uVar3 = (uint)bVar9;
  if ((param_3 & 0x20000) != 0) {
    local_28[uVar3 + 4] = 1;
    uVar3 = uVar3 + 1;
  }
  if ((param_3 & 0x40000) != 0) {
    local_28[uVar3 + 4] = 2;
    uVar3 = uVar3 + 1;
  }
  if ((param_3 & 0x80000) != 0) {
    local_28[uVar3 + 4] = 3;
    uVar3 = uVar3 + 1;
  }
  if (uVar3 < param_2) {
    param_2 = uVar3;
  }
  local_28[0] = -1;
  local_28[1] = 0xffffffff;
  local_28[2] = 0xffffffff;
  uVar3 = 0;
  local_28[3] = 0xffffffff;
  local_8 = in_ECX;
  if (param_2 != 0) {
    iVar4 = *(int *)(in_ECX + 0x14);
    do {
      iVar2 = uVar3 + 4;
      iVar1 = uVar3 * 4;
      uVar3 = uVar3 + 1;
      local_28[local_28[iVar2]] = *(int *)(*(int *)(iVar4 + *(int *)(param_1 + iVar1) * 4) + 0x10);
    } while (uVar3 < param_2);
  }
  if ((*(uint *)(local_8 + 200) & 0xffff) == 0x104) {
    uVar3 = 0;
    puVar7 = &DAT_00b59fa8;
    do {
      iVar4 = FUN_0092b81e(local_28,puVar7);
      if (iVar4 != 0) {
        piVar8 = &DAT_00b59fa8 + uVar3 * 4;
        if (piVar8 != (int *)0x0) goto LAB_00934535;
        break;
      }
      uVar3 = uVar3 + 1;
      puVar7 = puVar7 + 4;
    } while (uVar3 < 5);
    FUN_0091a001(local_8,*(undefined4 *)(*(int *)(local_8 + 0x100) + 0x3c),0x11b5,
                 s_cannot_map_swizzle_to_ps_1_4_00a2b724);
    uVar5 = 0x80004005;
  }
  else {
    piVar8 = &DAT_00b59fd8;
    iVar4 = FUN_0092b81e(local_28,&DAT_00b59fd8);
    if (iVar4 == 0) {
      piVar8 = &DAT_00b59fe8;
      iVar4 = FUN_0092b81e(local_28,&DAT_00b59fe8);
      if (((iVar4 == 0) && (iVar4 = FUN_0092b81e(local_28,&DAT_00b59fc8), iVar4 != 0)) &&
         ((param_3 & 0xf0000) == 0x80000)) {
        piVar8 = &DAT_00b59fc8;
      }
    }
LAB_00934535:
    uVar6 = 0;
    uVar3 = 0x10;
    do {
      iVar4 = *piVar8;
      piVar8 = piVar8 + 1;
      uVar6 = uVar6 | iVar4 << ((byte)uVar3 & 0x1f);
      uVar3 = uVar3 + 2;
    } while (uVar3 < 0x18);
    *param_4 = uVar6;
    uVar5 = 0;
  }
  return uVar5;
}


// ==== FUN_0093455a @ 0x0093455a ====

void FUN_0093455a(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a2a958;
  _free((void *)in_ECX[0x8b]);
  return;
}


// ==== FUN_009346db @ 0x009346db ====

int FUN_009346db(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  int local_108 [32];
  int aiStack_88 [4];
  int aiStack_78 [4];
  int local_68 [9];
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  uint local_30;
  int local_2c;
  uint local_28;
  int *local_24;
  uint *local_20;
  int local_1c;
  uint local_18;
  uint *local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  uVar6 = 0;
  local_24 = (int *)0x0;
  local_1c = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
      *(undefined4 *)(iVar3 + 0x30) = 0;
      if (*(int *)(iVar3 + 4) == *(int *)(in_ECX + 0x88)) {
        *(undefined4 *)(iVar3 + 0xc) = 0xffffffff;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(in_ECX + 8));
  }
  for (uVar6 = *(uint *)(in_ECX + 0x4c); uVar9 = 0, uVar6 < *(uint *)(in_ECX + 0x224);
      uVar6 = uVar6 + 1) {
    piVar5 = *(int **)(*(int *)(in_ECX + 0x230) + uVar6 * 4);
    if (((piVar5 != (int *)0x0) && (*piVar5 != 0)) && (piVar5[3] != 0)) {
      do {
        iVar3 = uVar9 * 4;
        uVar9 = uVar9 + 1;
        *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(piVar5[4] + iVar3) * 4) + 0x48) =
             uVar6;
      } while (uVar9 < (uint)piVar5[3]);
    }
  }
  local_30 = *(uint *)(in_ECX + 0x224);
  local_28 = *(uint *)(in_ECX + 0x4c);
  if (local_28 < local_30) {
    do {
      local_14 = *(uint **)(*(int *)(in_ECX + 0x230) + local_28 * 4);
      if ((local_14 != (uint *)0x0) && (*local_14 != 0)) {
        iVar3 = FUN_009149f7();
        if (iVar3 == 0) {
          local_1c = 0;
        }
        else {
          local_1c = FUN_0091455d();
        }
        if (local_1c != 0) {
          local_18 = FUN_00914ca1();
          puVar7 = local_14;
          if ((int)local_18 < 0) goto LAB_00934fd3;
          if (*(uint *)(in_ECX + 0x224) < 0x200) {
            local_34 = 0;
            local_40 = 0;
            if (((*local_14 & 0xfff00000) == 0x50000000) && (local_14[3] == 1)) {
              local_20 = *(uint **)(*(int *)(in_ECX + 0x14) + *(int *)local_14[4] * 4);
              if (local_20[4] != 3) goto LAB_00934955;
              FUN_009304cc(*(undefined4 *)(in_ECX + 0x230),local_28,local_30,(int *)local_14[4],1,
                           &local_2c,&local_3c,local_68 + 8);
              if (local_68[8] == 0) goto LAB_00934998;
              iVar3 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0,3,0);
              if (iVar3 == -1) goto LAB_00934fa8;
              iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4);
              FUN_00914e44();
              uVar1 = *(undefined4 *)(in_ECX + 0x88);
              *(undefined4 *)(iVar4 + 0x3c) = 0;
              *(undefined4 *)(iVar4 + 4) = uVar1;
              *(undefined4 *)(iVar4 + 0x10) = 3;
              iVar4 = FUN_009149f7();
              if (iVar4 == 0) {
                iVar4 = 0;
              }
              else {
                iVar4 = FUN_0091455d();
              }
              if (iVar4 == 0) goto LAB_00934fa8;
              local_18 = FUN_00914a42(0x10000001,1,1,0);
              if (((int)local_18 < 0) || (local_18 = FUN_00914593(), (int)local_18 < 0))
              goto LAB_00934fcc;
              **(undefined4 **)(iVar4 + 0x10) = *(undefined4 *)local_14[4];
              **(int **)(iVar4 + 8) = iVar3;
              **(int **)(local_1c + 0x10) = iVar3;
              *(int *)(*(int *)(in_ECX + 0x230) + *(int *)(in_ECX + 0x224) * 4) = local_1c;
              *(int *)(in_ECX + 0x224) = *(int *)(in_ECX + 0x224) + 1;
              local_2c = local_1c;
              iVar3 = FUN_00915205();
              if ((iVar3 < 0) || (0x1ff < *(uint *)(in_ECX + 0x224))) goto LAB_00934fa8;
              *(int *)(*(int *)(in_ECX + 0x230) + *(uint *)(in_ECX + 0x224) * 4) = iVar4;
              *(int *)(in_ECX + 0x224) = *(int *)(in_ECX + 0x224) + 1;
              iVar3 = FUN_00915205();
              if (iVar3 < 0) goto LAB_00934fa8;
LAB_0093494d:
              puVar7 = local_14;
            }
            else {
LAB_00934955:
              if (((*local_14 & 0xfff00000) != 0x10000000) || (iVar3 = FUN_0092b8aa(), iVar3 == 0))
              {
LAB_00934998:
                iVar3 = FUN_00915205();
                if (iVar3 < 0) goto LAB_00934fa8;
                *(int *)(*(int *)(in_ECX + 0x230) + *(int *)(in_ECX + 0x224) * 4) = local_1c;
                *(int *)(in_ECX + 0x224) = *(int *)(in_ECX + 0x224) + 1;
                local_2c = local_1c;
                goto LAB_0093494d;
              }
              uVar6 = puVar7[3];
              local_34 = 1;
              if (uVar6 != 0) {
                piVar5 = (int *)puVar7[4];
                do {
                  if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar5 * 4) + 0x3c) != 0) {
                    local_34 = 0;
                  }
                  piVar5 = piVar5 + 1;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
                if (local_34 == 0) goto LAB_00934998;
              }
              FUN_008f4adb();
              local_2c = 0;
            }
            local_1c = 0;
            iVar3 = FUN_0092b8aa();
            if (iVar3 != 0) {
              local_20 = (uint *)0x0;
              local_10 = 0;
              local_68[4] = 0xffffffff;
              local_68[5] = 0xffffffff;
              local_68[6] = 0xffffffff;
              local_68[7] = 0xffffffff;
              uVar6 = 0;
              if (puVar7[3] != 0) {
                iVar3 = *(int *)(in_ECX + 0x14);
                do {
                  iVar8 = local_10 * 4;
                  iVar4 = *(int *)(iVar8 + puVar7[4]);
                  iVar2 = *(int *)(iVar3 + iVar4 * 4);
                  if (*(int *)(iVar2 + 0x30) != 0) {
                    iVar2 = *(int *)(iVar2 + 0x10);
                    local_68[iVar2 + 4] = iVar4;
                    aiStack_88[iVar2] = *(int *)(iVar8 + puVar7[2]);
                    local_20 = (uint *)0x1;
                  }
                  uVar6 = puVar7[3];
                  local_10 = local_10 + 1;
                } while (local_10 < uVar6);
              }
              uVar9 = 0;
              local_10 = 0;
              FUN_0093032e(*(undefined4 *)(in_ECX + 0x230),local_28,local_30,puVar7[4],uVar6,
                           local_108,&local_10);
              if (local_20 != (uint *)0x0) {
                local_68[0] = -1;
                local_68[1] = 0xffffffff;
                local_68[2] = 0xffffffff;
                local_68[3] = 0xffffffff;
                local_18 = 0;
                if (local_10 != 0) {
                  do {
                    iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + local_108[local_18] * 4);
                    local_c = local_108[local_18];
                    if (*(int *)(iVar3 + 0x38) != -1) {
                      local_c = *(int *)(iVar3 + 0x38);
                      iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar3 + 0x38) * 4);
                    }
                    uVar6 = *(uint *)(iVar3 + 0x48);
                    if (((local_30 <= uVar6) || (uVar6 < local_28)) && (uVar6 != 0xffffffff)) {
                      local_8 = uVar6 * 4;
                      local_20 = *(uint **)(local_8 + *(int *)(in_ECX + 0x230));
                      iVar4 = FUN_0092b8aa();
                      if (iVar4 != 0) {
                        if ((((*local_20 & 0xfff00000) == 0x10000000) &&
                            (*(int *)(iVar3 + 0x38) == -1)) && (uVar6 = 0, local_20[3] != 0)) {
                          piVar5 = (int *)local_20[4];
                          while (local_c != *piVar5) {
                            local_24 = piVar5 + 1;
                            uVar6 = uVar6 + 1;
                            if (*(uint *)(*(int *)(local_8 + *(int *)(in_ECX + 0x230)) + 0xc) <=
                                uVar6) goto LAB_00934b40;
                            piVar5 = local_24;
                          }
                          aiStack_78[*(int *)(iVar3 + 0x10)] = *(int *)(local_20[2] + uVar6 * 4);
                          local_40 = 1;
                        }
LAB_00934b40:
                        iVar4 = local_68[*(int *)(iVar3 + 0x10)];
                        if (iVar4 == -1) {
                          local_68[*(int *)(iVar3 + 0x10)] = local_c;
                        }
                        else if (iVar4 != local_c) goto LAB_00934f59;
                      }
                    }
                    local_18 = local_18 + 1;
                  } while (local_18 < local_10);
                }
                uVar9 = 0;
                uVar6 = 0;
                local_10 = 0;
                do {
                  if (*(int *)((int)local_68 + uVar6) == -1) {
LAB_00934b8e:
                    if (*(int *)((int)local_68 + uVar6 + 0x10) != -1) goto LAB_00934b94;
                  }
                  else {
                    if (*(int *)((int)local_68 + uVar6 + 0x10) != -1) {
LAB_00934f59:
                      FUN_0091a001();
                      return -0x7fffbffb;
                    }
                    if (*(int *)((int)local_68 + uVar6) == -1) goto LAB_00934b8e;
LAB_00934b94:
                    uVar9 = uVar9 + 1;
                    local_10 = uVar9;
                  }
                  uVar6 = uVar6 + 4;
                } while (uVar6 < 0x10);
                iVar3 = FUN_009149f7();
                if (iVar3 == 0) {
                  local_24 = (int *)0x0;
                }
                else {
                  local_24 = (int *)FUN_0091455d();
                }
                if (local_24 == (int *)0x0) {
                  return -0x7ff8fff2;
                }
                local_18 = FUN_00914a42(uVar9 & 0xfffff | 0x70100000,uVar9 * 3,uVar9,0);
                if (-1 < (int)local_18) {
                  local_18 = FUN_00914593();
                  if (-1 < (int)local_18) {
                    local_8 = 0;
                    local_20 = (uint *)0x0;
                    local_c = local_10 << 2;
                    do {
                      iVar3 = *(int *)((int)(local_68 + 4) + (int)local_20);
                      if (iVar3 == -1) {
                        iVar3 = *(int *)((int)local_68 + (int)local_20);
                        if (iVar3 != -1) {
                          local_38 = local_8 * 4;
                          *(int *)(local_38 + local_24[4]) = iVar3;
                          if (local_40 == 0) {
                            iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4);
                            iVar4 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0,
                                                 *(undefined4 *)(iVar2 + 0x10),0);
                            if (iVar4 == -1) goto LAB_00934fa8;
                            *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4) + 0x3c) =
                                 *(undefined4 *)(iVar2 + 0x3c);
                            iVar8 = *(int *)(iVar2 + 0x48);
                            *(undefined4 *)(iVar2 + 0x3c) = 0;
                            if ((iVar8 == -1) || (iVar8 == *(int *)(in_ECX + 0x224))) {
                              FUN_0091a001();
                              goto LAB_00934fc5;
                            }
                            local_3c = *(int *)(*(int *)(in_ECX + 0x230) + iVar8 * 4);
                            uVar6 = 0;
                            if (*(int *)(local_3c + 0xc) != 0) {
                              do {
                                piVar5 = (int *)(*(int *)(local_3c + 0x10) + uVar6 * 4);
                                if (*piVar5 == iVar3) {
                                  *piVar5 = iVar4;
                                }
                                uVar6 = uVar6 + 1;
                              } while (uVar6 < *(uint *)(local_3c + 0xc));
                            }
                            *(undefined4 *)(iVar2 + 0x48) = *(undefined4 *)(in_ECX + 0x224);
                          }
                          else {
                            iVar4 = *(int *)((int)aiStack_78 + (int)local_20);
                            *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4) + 0x48) =
                                 *(undefined4 *)(in_ECX + 0x224);
                          }
                          *(undefined4 *)(local_38 + local_24[2]) = *(undefined4 *)(in_ECX + 0x440);
                          local_38 = iVar4;
                          *(int *)(local_24[2] + (local_8 + local_10 * 2) * 4) = iVar4;
                          goto LAB_00934dab;
                        }
                      }
                      else {
                        *(int *)(local_24[4] + local_8 * 4) = iVar3;
                        if (local_34 == 0) {
                          iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4);
                          iVar4 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0,
                                               *(undefined4 *)(iVar2 + 0x10),0);
                          if (iVar4 == -1) goto LAB_00934fa8;
                          *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4) + 0x3c) =
                               *(undefined4 *)(iVar2 + 0x3c);
                          *(undefined4 *)(iVar2 + 0x3c) = 0;
                          *(undefined4 *)(iVar2 + 0x48) = *(undefined4 *)(in_ECX + 0x224);
                          uVar6 = 0;
                          if (*(int *)(local_2c + 0xc) != 0) {
                            do {
                              piVar5 = (int *)(*(int *)(local_2c + 0x10) + uVar6 * 4);
                              if (*piVar5 == iVar3) {
                                *piVar5 = iVar4;
                              }
                              uVar6 = uVar6 + 1;
                            } while (uVar6 < *(uint *)(local_2c + 0xc));
                          }
                        }
                        else {
                          iVar4 = *(int *)((int)aiStack_88 + (int)local_20);
                          *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4) + 0x48) =
                               *(undefined4 *)(in_ECX + 0x224);
                        }
                        *(int *)(local_c + local_24[2]) = iVar4;
                        local_44 = iVar4;
                        *(undefined4 *)(local_24[2] + local_8 * 4) = *(undefined4 *)(in_ECX + 0x444)
                        ;
LAB_00934dab:
                        local_8 = local_8 + 1;
                        local_c = local_c + 4;
                      }
                      piVar5 = local_24;
                      local_20 = local_20 + 1;
                    } while (local_20 < (uint *)0x10);
                    local_8 = 0;
                    local_14 = (uint *)0x0;
                    local_c = local_10 << 2;
                    do {
                      if (*(int *)((int)(local_68 + 4) + (int)local_14) == -1) {
                        if (*(int *)((int)local_68 + (int)local_14) != -1) {
                          iVar3 = *(int *)(*(int *)(in_ECX + 0x14) +
                                          *(int *)((int)local_68 + (int)local_14) * 4);
                          iVar4 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0,
                                               *(undefined4 *)(iVar3 + 0x10),0);
                          if (iVar4 != -1) {
                            iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4);
                            *(int *)(iVar2 + 0x38) = local_44;
                            *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(iVar3 + 0x3c);
                            if (local_44 != -1) {
                              *(undefined4 *)(iVar2 + 4) =
                                   *(undefined4 *)
                                    (*(int *)(*(int *)(in_ECX + 0x14) + local_44 * 4) + 4);
                            }
                            *(int *)(local_c + piVar5[2]) = iVar4;
                            goto LAB_00934ea0;
                          }
                          goto LAB_00934fa8;
                        }
                      }
                      else {
                        iVar3 = *(int *)(*(int *)(in_ECX + 0x14) +
                                        *(int *)((int)(local_68 + 4) + (int)local_14) * 4);
                        iVar4 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0,
                                             *(undefined4 *)(iVar3 + 0x10),0);
                        if (iVar4 == -1) goto LAB_00934fa8;
                        iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4);
                        *(int *)(iVar2 + 0x38) = local_38;
                        *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(iVar3 + 0x3c);
                        if (local_38 != -1) {
                          *(undefined4 *)(iVar2 + 4) =
                               *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + local_38 * 4) + 4)
                          ;
                        }
                        *(int *)(piVar5[2] + (local_8 + local_10 * 2) * 4) = iVar4;
LAB_00934ea0:
                        local_8 = local_8 + 1;
                        local_c = local_c + 4;
                      }
                      local_14 = local_14 + 1;
                    } while (local_14 < (uint *)0x10);
                    if (*(uint *)(in_ECX + 0x224) < 0x200) {
                      *(int **)(*(int *)(in_ECX + 0x230) + *(uint *)(in_ECX + 0x224) * 4) = piVar5;
                      *(int *)(in_ECX + 0x224) = *(int *)(in_ECX + 0x224) + 1;
                      iVar3 = FUN_00915205();
                      if (-1 < iVar3) {
                        local_24 = (int *)0x0;
                        goto LAB_00934f15;
                      }
                    }
                    goto LAB_00934fa8;
                  }
                }
                goto LAB_00934fc5;
              }
              if (local_10 != 0) {
                do {
                  iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + local_108[uVar9] * 4);
                  if (*(int *)(iVar3 + 0x38) != -1) {
                    iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar3 + 0x38) * 4);
                  }
                  uVar9 = uVar9 + 1;
                  *(undefined4 *)(iVar3 + 0x30) = 1;
                } while (uVar9 < local_10);
              }
            }
LAB_00934f15:
            uVar6 = 0;
            if ((local_2c != 0) && (*(int *)(local_2c + 0xc) != 0)) {
              do {
                iVar3 = uVar6 * 4;
                uVar6 = uVar6 + 1;
                *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                 *(int *)(*(int *)(local_2c + 0x10) + iVar3) * 4) + 0x48) =
                     *(int *)(in_ECX + 0x224) + -1;
              } while (uVar6 < *(uint *)(local_2c + 0xc));
            }
            goto LAB_00934f3f;
          }
        }
LAB_00934fa8:
        local_18 = -0x7ff8fff2;
        goto LAB_00934fc5;
      }
LAB_00934f3f:
      local_28 = local_28 + 1;
    } while (local_28 < local_30);
  }
  for (uVar6 = *(uint *)(in_ECX + 0x4c); uVar6 < local_30; uVar6 = uVar6 + 1) {
    **(undefined4 **)(*(int *)(in_ECX + 0x230) + uVar6 * 4) = 0;
  }
  local_18 = 0;
LAB_00934fc5:
  if (local_24 != (int *)0x0) {
LAB_00934fcc:
    FUN_008f4adb();
  }
LAB_00934fd3:
  if (local_1c != 0) {
    FUN_008f4adb();
  }
  return local_18;
}


// ==== FUN_00934fe9 @ 0x00934fe9 ====

int FUN_00934fe9(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  undefined4 extraout_ECX_03;
  uint uVar5;
  bool bVar6;
  undefined8 uVar7;
  uint local_18;
  uint local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  uVar2 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x18) + uVar2 * 4) + 0x28) = 0;
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(in_ECX + 0xc));
  }
  uVar2 = 0;
  do {
    iVar3 = *(int *)(uVar2 + *(int *)(in_ECX + 0x230));
    if (iVar3 != 0) {
      FUN_0093db13(*(undefined4 *)(in_ECX + 0x18),iVar3,1);
      FUN_0093db59(*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(uVar2 + *(int *)(in_ECX + 0x230)),
                   2);
    }
    iVar3 = *(int *)(uVar2 + *(int *)(in_ECX + 0x22c));
    if (iVar3 != 0) {
      *(undefined4 *)(iVar3 + 0x28) = 1;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x18);
  uVar2 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      uVar7 = FUN_0092a852(**(uint **)(*(int *)(in_ECX + 0x18) + uVar2 * 4) & 0xfff00000);
      iVar3 = (int)((ulonglong)uVar7 >> 0x20);
      if ((((int)uVar7 == 0) && (extraout_ECX != 0x72100000)) && (extraout_ECX != 0x11000000)) {
        puVar1 = (uint *)(in_ECX + 0x220);
        if (0x1ff < *puVar1) {
          return -0x7fffbffb;
        }
        if (*(int *)(iVar3 + 0x28) == 1) {
          *(int *)(*(int *)(in_ECX + 0x22c) + *puVar1 * 4) = iVar3;
          *puVar1 = *puVar1 + 1;
        }
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(in_ECX + 0xc));
  }
  piVar4 = *(int **)(in_ECX + 0x22c);
  local_10 = 1;
  if ((piVar4 != (int *)0x0) && (*(int *)(in_ECX + 0x220) != 0)) {
    iVar3 = *(int *)(in_ECX + 0x220);
    do {
      if (*piVar4 != 0) {
        local_10 = 0;
      }
      piVar4 = piVar4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  local_c = 0;
  do {
    local_8 = 0;
    iVar3 = FUN_0092f9b1(&local_8);
    if (iVar3 < 0) {
      return iVar3;
    }
    FUN_00933f2e(*(undefined4 *)(in_ECX + 0x22c),6,*(undefined4 *)(in_ECX + 0x220),&local_14);
    uVar5 = 0;
    uVar2 = 0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar5 * 4);
        if (puVar1 != (uint *)0x0) {
          if ((puVar1[10] == 2) || (puVar1[10] == 0)) {
            uVar7 = FUN_0092a852(*puVar1 & 0xfff00000);
            if (((int)uVar7 == 0) &&
               ((extraout_ECX_00 != 0x11000000 && (extraout_ECX_00 != 0x72100000)))) {
              (&DAT_00b602c0)[uVar2] = (int)((ulonglong)uVar7 >> 0x20);
              uVar2 = uVar2 + 1;
            }
          }
          if (0x1ff < uVar2) {
            return -0x7ff8fff2;
          }
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(in_ECX + 0xc));
    }
    while ((FUN_00933f2e(&DAT_00b602c0,0,uVar2,&local_18), 7 < local_8 + local_18 ||
           (((local_14 < local_18 && (local_c == 0)) && (local_10 == 0))))) {
      local_8 = 0;
      if (*(int *)(in_ECX + 0xc) != 0) {
        do {
          puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_8 * 4);
          if (puVar1[10] == 0) {
            uVar7 = FUN_0092a852(*puVar1 & 0xfff00000);
            uVar2 = (uint)((ulonglong)uVar7 >> 0x20);
            if (((int)uVar7 == 0) && (extraout_ECX_01 != 0x72100000)) {
              bVar6 = uVar2 == puVar1[1];
              if (uVar2 < puVar1[1]) {
                piVar4 = (int *)puVar1[2];
                do {
                  if (*(char *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar4 * 4) + 0x6c) == '\x01')
                  break;
                  uVar2 = uVar2 + 1;
                  piVar4 = piVar4 + 1;
                } while (uVar2 < puVar1[1]);
                bVar6 = uVar2 == puVar1[1];
              }
              if (bVar6) {
                uVar2 = 0;
                if (local_c == 0) {
                  bVar6 = puVar1[3] == 0;
                  if (puVar1[3] != 0) {
                    piVar4 = (int *)puVar1[4];
                    do {
                      if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar4 * 4) + 0x10) == 3)
                      break;
                      uVar2 = uVar2 + 1;
                      piVar4 = piVar4 + 1;
                    } while (uVar2 < puVar1[3]);
                    bVar6 = uVar2 == puVar1[3];
                  }
                  if (!bVar6) goto LAB_00935274;
                }
                if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                       *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                        *(int *)puVar1[4] * 4) + 4) * 4) + 4) & 0x20
                    ) == 0) {
                  puVar1[10] = 1;
                  iVar3 = FUN_009301b3();
                  if ((iVar3 == 0) && (iVar3 = FUN_009302e7(puVar1), iVar3 == 0)) {
                    if (0x1ff < *(uint *)(in_ECX + 0x220)) {
                      return -0x7ff8fff2;
                    }
                    *(uint **)(*(int *)(in_ECX + 0x22c) + *(uint *)(in_ECX + 0x220) * 4) = puVar1;
                    *(int *)(in_ECX + 0x220) = *(int *)(in_ECX + 0x220) + 1;
                    break;
                  }
                  puVar1[10] = 0;
                }
              }
            }
          }
LAB_00935274:
          local_8 = local_8 + 1;
        } while (local_8 < *(uint *)(in_ECX + 0xc));
      }
      if (local_8 == *(uint *)(in_ECX + 0xc)) break;
      local_8 = 0;
      iVar3 = FUN_0092f9b1(&local_8);
      if (iVar3 < 0) {
        return iVar3;
      }
      FUN_00933f2e(*(undefined4 *)(in_ECX + 0x22c),6,*(undefined4 *)(in_ECX + 0x220),&local_14);
      uVar5 = 0;
      uVar2 = 0;
      if (*(int *)(in_ECX + 0xc) != 0) {
        do {
          puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar5 * 4);
          if (puVar1 != (uint *)0x0) {
            if ((puVar1[10] == 2) || (puVar1[10] == 0)) {
              uVar7 = FUN_0092a852(*puVar1 & 0xfff00000);
              if (((int)uVar7 == 0) &&
                 ((extraout_ECX_02 != 0x11000000 && (extraout_ECX_02 != 0x72100000)))) {
                (&DAT_00b602c0)[uVar2] = (int)((ulonglong)uVar7 >> 0x20);
                uVar2 = uVar2 + 1;
              }
            }
            if (0x1ff < uVar2) {
              return -0x7ff8fff2;
            }
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint *)(in_ECX + 0xc));
      }
    }
    local_c = local_c + 1;
    if (1 < local_c) {
      uVar2 = 0;
      if (*(int *)(in_ECX + 0xc) != 0) {
        do {
          puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar2 * 4);
          if (puVar1[10] == 0) {
            puVar1[10] = 2;
          }
          uVar5 = *(uint *)(in_ECX + 0x224);
          if (0x1ff < uVar5) {
            return -0x7fffbffb;
          }
          if (puVar1[10] == 2) {
            uVar7 = FUN_0092a852(*puVar1 & 0xfff00000);
            iVar3 = (int)((ulonglong)uVar7 >> 0x20);
            if ((((int)uVar7 == 0) && (iVar3 != 0x11000000)) && (iVar3 != 0x72100000)) {
              *(undefined4 *)(*(int *)(in_ECX + 0x230) + uVar5 * 4) = extraout_ECX_03;
              *(int *)(in_ECX + 0x224) = *(int *)(in_ECX + 0x224) + 1;
            }
          }
          uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint *)(in_ECX + 0xc));
      }
      return 0;
    }
  } while( true );
}


// ==== FUN_009353cc @ 0x009353cc ====

int FUN_009353cc(void)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int extraout_EAX;
  int in_ECX;
  int iVar5;
  uint uVar6;
  int local_30 [11];
  
  local_30[8] = 0;
  if (*(int *)(in_ECX + 0x4c) == 4) {
    local_30[4] = 0;
    local_30[5] = 0;
    local_30[6] = 0;
    local_30[7] = 0;
    local_30[0] = 0;
    local_30[1] = 0;
    local_30[2] = 0;
    local_30[10] = 0;
    local_30[3] = 0;
    local_30[9] = 0;
    do {
      iVar4 = local_30[10];
      piVar1 = (int *)(*(int *)(in_ECX + 0x230) + local_30[9] * 4);
      puVar2 = (uint *)*piVar1;
      if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
        if ((*puVar2 & 0xfff00000) == 0x72100000) {
          iVar5 = *piVar1;
LAB_00935471:
          local_30[local_30[9] + 4] = iVar5;
        }
        else {
          uVar6 = 0;
          if ((*puVar2 & 0xfff00000) != 0x11000000) {
            uVar6 = *puVar2 & 0xfffff;
          }
          iVar5 = *piVar1;
          if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(puVar2[2] + uVar6 * 4) * 4) + 4)
              != *(int *)(in_ECX + 0x88)) goto LAB_00935471;
          local_30[10] = local_30[10] + 1;
          local_30[iVar4] = iVar5;
        }
        *piVar1 = 0;
      }
      local_30[9] = local_30[9] + 1;
    } while ((uint)local_30[9] < *(uint *)(in_ECX + 0x4c));
    uVar6 = 0;
    if (*(int *)(in_ECX + 0x4c) != 0) {
      do {
        piVar1 = (int *)(*(int *)(in_ECX + 0x22c) + uVar6 * 4);
        if ((((uint *)*piVar1 != (uint *)0x0) && (uVar3 = *(uint *)*piVar1, uVar3 != 0)) &&
           ((uVar3 & 0xfff00000) != 0x72100000)) {
          if (local_30[uVar6 + 4] != 0) {
            iVar4 = -0x7fffbffb;
            goto LAB_009355e3;
          }
          local_30[uVar6 + 4] = *piVar1;
          *piVar1 = 0;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(in_ECX + 0x4c));
    }
    if ((((*(uint *)(in_ECX + 200) & 0xffff) < 0x102) ||
        (iVar4 = FUN_00932821(local_30,local_30[10],local_30 + 4,1), -1 < iVar4)) &&
       ((iVar4 = FUN_00932821(local_30,local_30[10],local_30 + 4,2), -1 < iVar4 &&
        ((iVar4 = FUN_00932821(local_30,local_30[10],local_30 + 4,3), -1 < iVar4 &&
         (iVar4 = FUN_0093234d(local_30,local_30[10],local_30 + 4), -1 < iVar4)))))) {
      local_30[9] = 0;
      if (*(int *)(in_ECX + 0x4c) != 0) {
        do {
          if (local_30[local_30[9]] != 0) {
            iVar4 = -0x7fffbffb;
            FUN_0091a001();
            local_30[8] = 1;
          }
          local_30[9] = local_30[9] + 1;
        } while ((uint)local_30[9] < *(uint *)(in_ECX + 0x4c));
      }
      if (iVar4 != -0x7fffbffb) {
        uVar6 = 0;
        if (*(int *)(in_ECX + 0x4c) != 0) {
          do {
            *(int *)(*(int *)(in_ECX + 0x230) + uVar6 * 4) = local_30[uVar6 + 4];
            uVar6 = uVar6 + 1;
          } while (uVar6 < *(uint *)(in_ECX + 0x4c));
        }
        _free(*(void **)(in_ECX + 0x22c));
        return extraout_EAX;
      }
      iVar4 = -0x7fffbffb;
    }
LAB_009355e3:
    if (local_30[8] == 0) {
      FUN_0091a001();
    }
  }
  else {
    iVar4 = -0x7fffbffb;
  }
  return iVar4;
}


// ==== FUN_00935616 @ 0x00935616 ====

int FUN_00935616(int param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  undefined4 uVar10;
  
  uVar8 = 0;
  if (param_2 != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar8;
      iVar6 = *(int *)(param_1 + uVar8 * 4);
      *(int *)(in_ECX + 0x100) = iVar6;
      if (iVar6 != 0) {
        iVar6 = *(int *)(iVar6 + 0x3c);
        if ((iVar6 != 0) && (*(int *)(iVar6 + 4) == 0xd)) {
          *(int *)(in_ECX + 0x104) = iVar6 + 0x30;
        }
        puVar1 = *(uint **)(in_ECX + 0x100);
        uVar7 = *puVar1;
        if (uVar7 != 0) {
          iVar6 = *(int *)(in_ECX + 0x14);
          if (*(int *)(*(int *)(iVar6 + *(int *)puVar1[2] * 4) + 8) != -1) {
            FUN_0091a001();
            return -0x7fffbffb;
          }
          uVar5 = uVar7 & 0xfff00000;
          if (uVar5 < 0x70300001) {
            if (uVar5 == 0x70300000) {
LAB_009358bc:
              iVar6 = FUN_0094eb80();
            }
            else if (uVar5 < 0x50000001) {
              if (uVar5 == 0x50000000) {
                uVar7 = uVar7 & 0xfffff;
                if (uVar7 == 2) goto LAB_00935956;
                if ((uVar7 == 4) && ((*(uint *)(in_ECX + 200) & 0xffff) == 0x101)) {
LAB_009357f0:
                  iVar6 = FUN_00932fd4();
                }
                else {
                  uVar5 = *(uint *)(in_ECX + 200) & 0xffff;
                  if (((uVar5 == 0x102) || (uVar5 == 0x103)) && (uVar7 == 4)) {
                    iVar2 = *(int *)(iVar6 + *(int *)puVar1[4] * 4);
                    iVar3 = *(int *)(iVar6 + *(int *)puVar1[2] * 4);
                    iVar6 = *(int *)(iVar6 + ((int *)puVar1[2])[4] * 4);
                    iVar4 = *(int *)(iVar2 + 4);
                    if (iVar4 == *(int *)(in_ECX + 0x84)) {
                      if (((*(int *)(iVar3 + 4) == *(int *)(in_ECX + 0x88)) &&
                          (*(int *)(iVar3 + 0xc) == 0)) ||
                         ((*(int *)(iVar6 + 4) == *(int *)(in_ECX + 0x88) &&
                          (*(int *)(iVar6 + 0xc) == 0)))) {
                        bVar9 = (*(uint *)(iVar2 + 0x6c) & 0xff) == 1;
LAB_009357ee:
                        if (bVar9) goto LAB_009357f0;
                      }
                    }
                    else {
                      if ((*(int *)(iVar3 + 4) == iVar4) &&
                         (*(int *)(iVar3 + 0xc) == *(int *)(iVar2 + 0xc))) goto LAB_009357f0;
                      if (*(int *)(iVar6 + 4) == iVar4) {
                        bVar9 = *(int *)(iVar6 + 0xc) == *(int *)(iVar2 + 0xc);
                        goto LAB_009357ee;
                      }
                    }
                  }
                  iVar6 = FUN_0094f44b();
                }
              }
              else {
                if (uVar5 == 0) goto LAB_00935920;
                if (uVar5 == 0x10000000) {
                  iVar6 = FUN_0094f236();
                }
                else if (uVar5 == 0x10100000) {
                  iVar6 = FUN_0094e840();
                }
                else if (uVar5 == 0x11000000) {
                  iVar6 = FUN_0094e04c();
                }
                else if (uVar5 == 0x20400000) {
                  iVar6 = FUN_0094f42d();
                }
                else if (uVar5 == 0x20500000) {
                  iVar6 = FUN_0094f437();
                }
                else {
                  if (uVar5 != 0x30000000) goto LAB_00935956;
                  if ((*(uint *)(in_ECX + 200) & 0xffff) == 0x104) {
                    iVar6 = FUN_0094f508();
                  }
                  else {
                    iVar6 = -0x7fffbfff;
                  }
                }
              }
            }
            else if ((uVar5 == 0x60000000) || (uVar5 == 0x60500000)) {
LAB_0093584e:
              iVar6 = FUN_00933413();
            }
            else if (uVar5 == 0x60700000) {
              iVar6 = FUN_00933341();
            }
            else {
              if ((uVar5 == 0x60a00000) || (uVar5 == 0x60f00000)) goto LAB_0093584e;
              if (uVar5 != 0x70100000) goto LAB_00935956;
              iVar6 = FUN_0094e9bf();
            }
          }
          else {
            if (uVar5 < 0x72600001) {
              if (uVar5 != 0x72600000) {
                if (uVar5 == 0x70400000) goto LAB_009358bc;
                if (uVar5 == 0x70f00000) {
                  iVar6 = FUN_0094f512();
                }
                else {
                  if (uVar5 != 0x72100000) {
                    if (uVar5 == 0x72200000) {
                      uVar10 = 0x47;
                    }
                    else if (uVar5 == 0x72300000) {
                      uVar10 = 0x48;
                    }
                    else if (uVar5 == 0x72400000) {
                      uVar10 = 0x49;
                    }
                    else {
                      if (uVar5 != 0x72500000) goto LAB_00935956;
                      uVar10 = 0x4a;
                    }
                    goto LAB_0093590e;
                  }
                  iVar6 = FUN_00933564();
                }
                goto LAB_00935915;
              }
              uVar10 = 0x52;
            }
            else if (uVar5 == 0x72700000) {
              uVar10 = 0x45;
            }
            else if (uVar5 == 0x72800000) {
              uVar10 = 0x46;
            }
            else if (uVar5 == 0x72900000) {
              uVar10 = 0x4d;
            }
            else if (uVar5 == 0x72a00000) {
              uVar10 = 0x4c;
            }
            else {
              if (uVar5 != 0x72b00000) {
                if (uVar5 != 0x72e00000) goto LAB_00935956;
                iVar6 = FUN_00933266();
                goto LAB_00935915;
              }
              uVar10 = 0x53;
            }
LAB_0093590e:
            iVar6 = FUN_00933121(uVar10);
          }
LAB_00935915:
          if (iVar6 == -0x7fffbfff) {
LAB_00935956:
            FUN_0091a001();
            return -0x7fffbfff;
          }
          if (iVar6 < 0) {
            return iVar6;
          }
        }
      }
LAB_00935920:
      uVar8 = uVar8 + 1;
    } while (uVar8 < param_2);
  }
  return 0;
}


// ==== FUN_009359e6 @ 0x009359e6 ====

void FUN_009359e6(byte param_1)

{
  void *in_ECX;
  
  FUN_0093455a();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00935a07 @ 0x00935a07 ====

int FUN_00935a07(void)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  int in_ECX;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  uVar2 = FUN_009152bf(&DAT_00a1fc10,0x311,1,4);
  uVar3 = FUN_00915318(uVar2,0,0,0);
  *(undefined4 *)(in_ECX + 0x440) = uVar3;
  uVar2 = FUN_00915318(uVar2,0,1,0x3ff0000000000000);
  *(undefined4 *)(in_ECX + 0x444) = uVar2;
  *(undefined4 *)(in_ECX + 0x44c) = 0;
  if ((*(uint *)(in_ECX + 200) & 0xffff) == 0x104) {
    uVar9 = 0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        *(uint *)(in_ECX + 0xfc) = uVar9;
        puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar9 * 4);
        *(uint **)(in_ECX + 0x100) = puVar1;
        if (((*puVar1 & 0xfff00000) == 0x60700000) && (iVar4 = FUN_0092aadd(), iVar4 < 0)) {
          return iVar4;
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(uint *)(in_ECX + 0xc));
    }
    FUN_0093e2c8();
    FUN_0091ae30();
  }
  local_10 = 0;
  local_c = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + local_c * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      local_8 = 0;
      if (puVar1[1] != 0) {
        piVar6 = (int *)puVar1[2];
        do {
          iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar6 * 4);
          uVar9 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar4 + 4) * 4) + 4);
          if (((((uVar9 & 0x10) != 0) && ((uVar9 & 0x200) == 0)) && (*(int *)(iVar4 + 0x10) == 3))
             && ((*(char *)(iVar4 + 0x6c) == '\x03' &&
                 (((*puVar1 & 0xfff00000) != 0x60700000 || (local_8 != 7)))))) {
            local_10 = 1;
            FUN_0091a001();
            break;
          }
          local_8 = local_8 + 1;
          piVar6 = piVar6 + 1;
        } while (local_8 < *(uint *)(*(int *)(in_ECX + 0x100) + 4));
      }
      uVar9 = **(uint **)(in_ECX + 0x100) & 0xfff00000;
      if (((uVar9 == 0x60600000) || (uVar9 == 0x60b00000)) ||
         ((uVar9 == 0x60100000 || (uVar9 == 0x61000000)))) {
        FUN_0091a001();
        local_10 = 1;
      }
      local_c = local_c + 1;
    } while (local_c < *(uint *)(in_ECX + 0xc));
    if (local_10 != 0) {
      return -0x7fffbffb;
    }
  }
  uVar9 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar9 * 4) + 0x38) = 0xffffffff;
      puVar10 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar9 * 4);
      if (puVar10[1] == *(int *)(in_ECX + 0x80)) {
        if (*(char *)(puVar10 + 0x1b) == '\x01') {
          *puVar10 = 0x14;
        }
        if (((*(uint *)(in_ECX + 200) & 0xffff) < 0x104) &&
           (puVar10 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar9 * 4),
           *(char *)(puVar10 + 0x1b) == '\x03')) {
          *puVar10 = 0x14;
        }
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint *)(in_ECX + 8));
  }
  uVar9 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar9;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar9 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      uVar7 = *puVar1 & 0xfff00000;
      if (((((uVar7 == 0x60000000) || (uVar7 == 0x60500000)) || (uVar7 == 0x60a00000)) ||
          (uVar7 == 0x60f00000)) && (uVar7 = 0, puVar1[3] != 0)) {
        do {
          **(undefined4 **)
            (*(int *)(in_ECX + 0x14) +
            *(int *)(*(int *)(*(int *)(in_ECX + 0x100) + 0x10) + uVar7 * 4) * 4) = 0x14;
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(uint *)(*(int *)(in_ECX + 0x100) + 0xc));
      }
      uVar9 = uVar9 + 1;
      *(undefined4 *)(*(int *)(in_ECX + 0x100) + 0x24) = 0;
    } while (uVar9 < *(uint *)(in_ECX + 0xc));
  }
  uVar9 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar9;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar9 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      uVar7 = *puVar1 & 0xfff00000;
      if ((((uVar7 == 0x20000000) || (uVar7 == 0x20100000)) || (uVar7 == 0x30000000)) &&
         (iVar4 = FUN_0093fdb0(), iVar4 < 0)) {
        return iVar4;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint *)(in_ECX + 0xc));
  }
  uVar9 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar9;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar9 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      uVar7 = *puVar1 & 0xfff00000;
      if (uVar7 == 0x10000000) {
        iVar4 = FUN_0092af63();
LAB_00935d32:
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      else if (uVar7 == 0x10100000) {
        iVar4 = FUN_0092b08f();
        goto LAB_00935d32;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint *)(in_ECX + 0xc));
  }
  FUN_0093e2c8();
  uVar9 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar9;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar9 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      uVar7 = *puVar1 & 0xfff00000;
      if (uVar7 == 0x10100000) {
        FUN_00949ac4();
LAB_00935dc6:
        iVar4 = FUN_0094adf1();
LAB_00935dcd:
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      else {
        if (uVar7 == 0x20400000) {
          FUN_0094ae91();
          FUN_0094a80a();
          FUN_0094ac69();
          iVar4 = FUN_0094ab07();
          goto LAB_00935dcd;
        }
        if (uVar7 == 0x20500000) {
          FUN_0094ab07();
          goto LAB_00935dc6;
        }
        if (uVar7 == 0x50000000) {
          iVar4 = FUN_00941be9();
          goto LAB_00935dcd;
        }
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint *)(in_ECX + 0xc));
  }
  FUN_0093e2c8();
  uVar9 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar9;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar9 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      uVar7 = *puVar1 & 0xfff00000;
      if (((uVar7 == 0x20400000) || (uVar7 == 0x20500000)) && (iVar4 = FUN_0092d2e2(), iVar4 < 0)) {
        return iVar4;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint *)(in_ECX + 0xc));
  }
  FUN_0093e2c8();
  uVar9 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar9;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar9 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      if ((*puVar1 & 0xfff00000) == 0x60f00000) {
        iVar4 = FUN_0092c82a();
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = FUN_0092c82a();
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint *)(in_ECX + 0xc));
  }
  FUN_0093e2c8();
  uVar9 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar9;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar9 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      if (((*puVar1 & 0xfff00000) == 0x20400000) && (iVar4 = FUN_0092cf06(), iVar4 < 0)) {
        return iVar4;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint *)(in_ECX + 0xc));
  }
  FUN_0093e2c8();
  uVar9 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar9;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar9 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      if ((*puVar1 & 0xfff00000) == 0x70300000) {
        FUN_0094b02e();
        iVar4 = FUN_00945449();
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint *)(in_ECX + 0xc));
  }
  uVar9 = *(uint *)(in_ECX + 0xc);
  uVar7 = 0;
  if (uVar9 != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar7;
      *(undefined4 *)(in_ECX + 0x100) = *(undefined4 *)(*(int *)(in_ECX + 0x18) + uVar7 * 4);
      iVar4 = FUN_0092c26f();
      if (iVar4 < 0) {
        return iVar4;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar9);
  }
  FUN_0093e2c8();
  iVar4 = FUN_0094601a();
  if (iVar4 < 0) {
    return iVar4;
  }
  iVar4 = FUN_0092ccb7();
  if (iVar4 < 0) {
    return iVar4;
  }
  iVar4 = FUN_0092b67e();
  if (iVar4 < 0) {
    return iVar4;
  }
  if ((*(uint *)(in_ECX + 200) & 0xffff) == 0x104) {
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
    *(undefined4 *)(in_ECX + 0x224) = 0;
    *(undefined4 *)(in_ECX + 0x220) = 0;
    puVar10 = *(undefined4 **)(in_ECX + 0x22c);
    for (iVar4 = 0x200; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    puVar10 = *(undefined4 **)(in_ECX + 0x230);
    for (iVar4 = 0x200; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    iVar4 = FUN_0092ec61();
    if (iVar4 < 0) {
      return iVar4;
    }
    iVar4 = FUN_0092f1c1();
    if (iVar4 < 0) {
      return iVar4;
    }
    iVar4 = FUN_0092f329();
    if (iVar4 == 0) {
      uVar9 = FUN_0092f24f();
      if (uVar9 != 0xffffffff) {
        FUN_0092eabb();
        local_10 = 0;
        piVar6 = (int *)(in_ECX + 0x304);
        do {
          iVar4 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),0,0,0);
          *piVar6 = iVar4;
          if (iVar4 == -1) {
            return -0x7ff8fff2;
          }
          local_10 = local_10 + 1;
          piVar6 = piVar6 + 1;
          *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4) + 0x3c) = 0;
        } while (local_10 < 0x40);
        local_14 = 0xffffffff;
        local_20 = 0xffffffff;
        puVar10 = (undefined4 *)(in_ECX + 0x2c4);
        for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar10 = 0;
          puVar10 = puVar10 + 1;
        }
        local_8 = 0;
        if (uVar9 != 0) {
          do {
            puVar10 = *(undefined4 **)(in_ECX + 0x22c);
            for (iVar4 = 0x200; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar10 = 0;
              puVar10 = puVar10 + 1;
            }
            puVar10 = *(undefined4 **)(in_ECX + 0x230);
            for (iVar4 = 0x200; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar10 = 0;
              puVar10 = puVar10 + 1;
            }
            *(undefined4 *)(in_ECX + 0x220) = 0;
            *(undefined4 *)(in_ECX + 0x224) = 0;
            iVar4 = FUN_0092f5d2(local_8,1);
            if (iVar4 != 0) {
              *(undefined4 *)(in_ECX + 0x408) = 0;
              *(undefined4 *)(in_ECX + 0x404) = 0;
              FUN_0092ebb4();
              FUN_00933f2e(*(undefined4 *)(in_ECX + 0x22c),6,*(undefined4 *)(in_ECX + 0x220),
                           &local_1c);
              FUN_00933f2e(*(undefined4 *)(in_ECX + 0x230),6,*(undefined4 *)(in_ECX + 0x224),
                           &local_10);
              piVar6 = (int *)(in_ECX + 0x2c4);
              local_c = 0x10;
              do {
                if (*piVar6 != 0) {
                  FUN_008f4adb();
                }
                *piVar6 = 0;
                piVar6 = piVar6 + 1;
                local_c = local_c - 1;
              } while (local_c != 0);
              iVar4 = FUN_00934fe9();
              if (iVar4 < 0) {
                return iVar4;
              }
              if (((iVar4 != 1) && (iVar4 = FUN_0092f9b1(), -1 < iVar4)) &&
                 (iVar4 = FUN_00931153(1,1), -1 < iVar4)) {
                FUN_00933f2e(*(undefined4 *)(in_ECX + 0x22c),6,*(undefined4 *)(in_ECX + 0x220),
                             &local_1c);
                FUN_00933f2e(*(undefined4 *)(in_ECX + 0x230),6,*(undefined4 *)(in_ECX + 0x224),
                             &local_10);
                piVar6 = *(int **)(in_ECX + 0x230);
                iVar8 = 0;
                local_c = 0;
                iVar4 = *(int *)(in_ECX + 0x22c) - (int)piVar6;
                local_18 = 6;
                do {
                  if (*(int *)(iVar4 + (int)piVar6) != 0) {
                    iVar8 = iVar8 + 1;
                  }
                  if (*piVar6 != 0) {
                    local_c = local_c + 1;
                  }
                  piVar6 = piVar6 + 1;
                  local_18 = local_18 + -1;
                } while (local_18 != 0);
                local_18 = local_1c;
                if (local_1c <= (uint)(iVar8 * 2)) {
                  local_18 = iVar8 * 2;
                }
                uVar7 = local_10;
                if (local_10 <= local_c * 2) {
                  uVar7 = local_c * 2;
                }
                uVar7 = (-(uint)(iVar8 + local_1c != 0) & 10) + uVar7 + local_18;
                if (8 < local_1c) {
                  uVar7 = uVar7 + 0x14;
                }
                if (8 < local_10) {
                  uVar7 = uVar7 + 0x14;
                }
                if (uVar7 < local_20) {
                  local_14 = local_8;
                  local_20 = uVar7;
                }
                *(undefined4 *)(in_ECX + 0x404) = 0;
              }
            }
            local_8 = local_8 + 1;
          } while (local_8 < uVar9);
        }
        puVar10 = *(undefined4 **)(in_ECX + 0x22c);
        for (iVar4 = 0x200; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar10 = 0;
          puVar10 = puVar10 + 1;
        }
        puVar10 = *(undefined4 **)(in_ECX + 0x230);
        for (iVar4 = 0x200; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar10 = 0;
          puVar10 = puVar10 + 1;
        }
        *(undefined4 *)(in_ECX + 0x220) = 0;
        *(undefined4 *)(in_ECX + 0x224) = 0;
        piVar6 = (int *)(in_ECX + 0x2c4);
        local_24 = 0xc;
        do {
          if (*piVar6 != 0) {
            FUN_008f4adb();
          }
          *piVar6 = 0;
          piVar6 = piVar6 + 1;
          local_24 = local_24 + -1;
        } while (local_24 != 0);
        if (local_14 != 0xffffffff) {
          FUN_0092f5d2(local_14,0);
          FUN_0092ebb4();
          FUN_00934fe9();
          iVar4 = FUN_0092f9b1();
          if (iVar4 < 0) {
            return iVar4;
          }
          iVar4 = FUN_00931153(0,0);
          if (iVar4 < 0) {
            return iVar4;
          }
          piVar6 = *(int **)(in_ECX + 0x22c);
          uVar9 = 0;
          do {
            if (*piVar6 != 0) break;
            uVar9 = uVar9 + 1;
            piVar6 = piVar6 + 1;
          } while (uVar9 < 6);
          if ((*(int *)(in_ECX + 0x220) == 6) && (uVar9 == 6)) {
            *(undefined4 *)(in_ECX + 0x220) = 0;
          }
          goto LAB_00936422;
        }
      }
      FUN_0091a001();
      return -0x7fffbffb;
    }
  }
  else {
    if (*(uint *)(in_ECX + 0xc) < 0x81) {
      iVar4 = FUN_0092e4dd();
      if (iVar4 < 0) {
        return iVar4;
      }
      if (*(int *)(in_ECX + 0x22c) != 0) {
        iVar4 = FUN_0092b4cb();
        if (iVar4 < 0) {
          return iVar4;
        }
        if (((*(int *)(in_ECX + 0x22c) != 0) && ((*(uint *)(in_ECX + 200) & 0xffff) != 0x104)) &&
           (iVar4 = FUN_009353cc(), iVar4 < 0)) {
          return iVar4;
        }
      }
      if ((*(int *)(in_ECX + 0x230) != 0) && ((*(uint *)(in_ECX + 200) & 0xffff) != 0x104)) {
        iVar4 = FUN_0092b922();
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = FUN_009346db();
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = FUN_0092bcf7();
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      *(undefined4 *)(in_ECX + 0xdc) = 0;
      iVar4 = FUN_00931153(0,0);
      if (iVar4 < 0) {
        return iVar4;
      }
LAB_00936422:
      *(undefined4 *)(in_ECX + 0xdc) = 1;
      iVar4 = FUN_00930645();
      if (iVar4 < 0) {
        return iVar4;
      }
      iVar4 = FUN_00933f2e(*(undefined4 *)(in_ECX + 0x22c),0,*(undefined4 *)(in_ECX + 0x220),0);
      if (iVar4 < 0) {
        return iVar4;
      }
      iVar4 = FUN_00933f2e(*(undefined4 *)(in_ECX + 0x230),0,*(undefined4 *)(in_ECX + 0x224),0);
      if (iVar4 < 0) {
        return iVar4;
      }
      iVar4 = FUN_0092b289();
      if (iVar4 < 0) {
        return iVar4;
      }
      if (((*(int *)(in_ECX + 0x230) == 0) || ((*(uint *)(in_ECX + 200) & 0xffff) == 0x104)) ||
         (iVar4 = FUN_0092a9fe(), -1 < iVar4)) {
        return 0;
      }
      return iVar4;
    }
    FUN_0091a001();
  }
  return -0x7fffbffb;
}


// ==== FUN_009364aa @ 0x009364aa ====

void FUN_009364aa(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_00948a8f();
  in_ECX[0x8a] = 0;
  in_ECX[0x56] = param_1;
  *in_ECX = &PTR_FUN_00a2b998;
  in_ECX[0x3d] = &PTR_s_Position_00b5a060;
  in_ECX[0x3e] = &PTR_s_Color_00b5a180;
  return;
}


// ==== FUN_009364e8 @ 0x009364e8 ====

void FUN_009364e8(void)

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
  FUN_0094c8d4();
  return;
}


// ==== FUN_009365fb @ 0x009365fb ====

int FUN_009365fb(void)

{
  uint *puVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  
  uVar3 = 0;
  if ((*(byte *)(in_ECX + 0xcc) & 4) != 0) {
    FUN_00919e76();
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        *(uint *)(in_ECX + 0xfc) = uVar3;
        puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar3 * 4);
        *(uint **)(in_ECX + 0x100) = puVar1;
        if ((*puVar1 & 0xfff00000) == 0x10000000) {
          FUN_0093f3d2();
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(in_ECX + 0xc));
    }
    FUN_00919e8f();
    if ((*(byte *)(in_ECX + 0xcc) & 4) != 0) goto LAB_0093695b;
  }
  uVar3 = 0;
  if (*(int *)(in_ECX + 0xc) == 0) {
    iVar4 = in_ECX;
  }
  else {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar3;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar3 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      uVar2 = *puVar1 & 0xfff00000;
      if (uVar2 == 0x10100000) {
        iVar4 = FUN_00949ac4(1);
LAB_009366ba:
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      else {
        if (((uVar2 == 0x20000000) || (uVar2 == 0x20100000)) || (uVar2 == 0x30000000)) {
          iVar4 = FUN_0093fdb0();
          FUN_0093e2c8();
          goto LAB_009366ba;
        }
        iVar4 = 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 0xc));
  }
  uVar3 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar3;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar3 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      if ((*puVar1 & 0xfff00000) == 0x30000000) {
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = FUN_0093f455(0,0,0);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = FUN_0093fa51(0,0,0);
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      else {
        iVar4 = 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 0xc));
  }
  iVar4 = FUN_0091ae30();
  if (iVar4 < 0) {
    return iVar4;
  }
  FUN_0093e2c8();
  uVar3 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar3;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar3 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      uVar2 = *puVar1 & 0xfff00000;
      if ((uVar2 == 0x20000000) || (uVar2 == 0x70b00000)) {
        iVar4 = FUN_0093fdb0();
        FUN_0093e2c8();
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 0xc));
  }
  uVar3 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar3;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar3 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      uVar2 = *puVar1 & 0xfff00000;
      if (uVar2 == 0x10500000) {
        iVar4 = FUN_0093ef49();
LAB_00936815:
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      else {
        if (uVar2 == 0x10f00000) {
          iVar4 = FUN_009422cd();
          goto LAB_00936815;
        }
        if (uVar2 == 0x20400000) {
          iVar4 = FUN_00944750();
          if (iVar4 != 0) {
            iVar4 = FUN_00949b7e(1);
            goto LAB_00936815;
          }
        }
        else if ((uVar2 == 0x30000000) && (iVar4 = FUN_00944dce(), iVar4 != 0)) {
          iVar4 = FUN_00944ea0();
          goto LAB_00936815;
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 0xc));
  }
  iVar4 = FUN_0091ae30();
  if (iVar4 < 0) {
    return iVar4;
  }
  FUN_0093e2c8();
  uVar3 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar3;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar3 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      uVar2 = *puVar1 & 0xfff00000;
      if (uVar2 == 0x20500000) {
        iVar4 = FUN_0094414d();
LAB_009368a8:
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      else {
        if (uVar2 == 0x50000000) {
          iVar4 = FUN_00944a10();
          goto LAB_009368a8;
        }
        if (uVar2 == 0x70300000) {
          iVar4 = FUN_00945449(0);
          goto LAB_009368a8;
        }
        if ((uVar2 == 0x73500000) || (uVar2 == 0x73600000)) {
          iVar4 = FUN_0094260e();
          goto LAB_009368a8;
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 0xc));
  }
  FUN_0093e2c8();
  uVar3 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar3;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar3 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      if ((*puVar1 & 0xfff00000) == 0x70300000) {
        FUN_0094b02e();
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 0xc));
  }
  FUN_0093e2c8();
  uVar3 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar3;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar3 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      uVar2 = *puVar1 & 0xfff00000;
      if (uVar2 == 0x70300000) {
        iVar4 = FUN_00945449(0);
LAB_0093694f:
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      else if ((((uVar2 == 0x73500000) || (uVar2 == 0x73600000)) || (uVar2 == 0x73700000)) ||
              (uVar2 == 0x73800000)) {
        iVar4 = FUN_009428be();
        goto LAB_0093694f;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 0xc));
  }
LAB_0093695b:
  uVar3 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar3;
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar3 * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      if (((*puVar1 & 0xfff00000) == 0x50300000) && (iVar4 = FUN_0093e986(), iVar4 < 0)) {
        return iVar4;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 0xc));
  }
  iVar4 = FUN_0091ae30();
  if (((-1 < iVar4) && (iVar4 = FUN_009237bb(), -1 < iVar4)) &&
     ((iVar4 = FUN_00915e19(), -1 < iVar4 && (iVar4 = FUN_0091c491(), -1 < iVar4)))) {
    FUN_0093e2c8();
    iVar4 = 0;
  }
  return iVar4;
}


// ==== FUN_009369d9 @ 0x009369d9 ====

int FUN_009369d9(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int in_ECX;
  uint uVar7;
  uint uVar8;
  int local_8;
  
  *(undefined4 *)(in_ECX + 0x220) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x224) = 0xffffffff;
  uVar8 = 0;
  local_8 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      puVar1 = (undefined4 *)(*(int *)(in_ECX + 0x18) + uVar8 * 4);
      *(uint *)(in_ECX + 0xfc) = uVar8;
      *(undefined4 *)(in_ECX + 0x100) = *puVar1;
      *(uint *)(in_ECX + 0xfc) = uVar8;
      puVar2 = (uint *)*puVar1;
      *(uint **)(in_ECX + 0x100) = puVar2;
      uVar4 = *puVar2 & 0xfff00000;
      if (((uVar4 == 0x20300000) || (uVar4 == 0x20200000)) && (*(int *)(in_ECX + 0x220) == -1)) {
        uVar5 = FUN_009152bf(&DAT_00a1fc10,0x311,1,4);
        uVar6 = FUN_00915318(uVar5,0,0,0);
        *(undefined4 *)(in_ECX + 0x220) = uVar6;
        uVar5 = FUN_00915318(uVar5,0,1,0x3ff0000000000000);
        *(undefined4 *)(in_ECX + 0x224) = uVar5;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(in_ECX + 0xc));
  }
  FUN_0093e2c8();
  if (((*(byte *)(in_ECX + 0xcc) & 4) == 0) && (uVar8 = 0, *(int *)(in_ECX + 0xc) != 0)) {
    do {
      *(uint *)(in_ECX + 0xfc) = uVar8;
      puVar2 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar8 * 4);
      *(uint **)(in_ECX + 0x100) = puVar2;
      uVar4 = *puVar2;
      uVar7 = uVar4 & 0xfff00000;
      if (((uVar7 == 0x10300000) || ((uVar7 == 0x10500000 || (uVar7 == 0x10600000)))) ||
         (uVar7 == 0x10700000)) {
LAB_00936b03:
        local_8 = FUN_00941be9();
LAB_00936b0d:
        if (local_8 < 0) {
          return local_8;
        }
      }
      else {
        if (uVar7 == 0x50000000) {
          if (2 < (uVar4 & 0xfffff)) goto LAB_00936b03;
          goto LAB_00936b0d;
        }
        local_8 = 1;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(in_ECX + 0xc));
  }
  FUN_0093e2c8();
  uVar8 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + uVar8 * 4);
      if ((((*(int *)(iVar3 + 0x54) == -1) &&
           ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar3 + 4) * 4) + 5) & 1) != 0))
          && (*(uint *)(in_ECX + 0x224) != uVar8)) && (*(uint *)(in_ECX + 0x220) != uVar8)) {
        *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(in_ECX + 0x74);
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(in_ECX + 8));
  }
  return 0;
}


// ==== FUN_00936b6a @ 0x00936b6a ====

undefined4 FUN_00936b6a(int *param_1,uint param_2,uint *param_3,int param_4)

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
  if ((*(uint *)(in_ECX + 0xcc) & 0x20) == 0) {
    uVar4 = 0;
    bVar5 = param_2 == 0;
    if (param_2 != 0) {
      do {
        iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + param_1[uVar4] * 4);
        if (((*(byte *)(iVar2 + 3) & 2) == 0) &&
           ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar2 + 4) * 4) + 4) & 1) == 0
             || (*(int *)(iVar2 + 0x48) == -1)) || (*(int *)(iVar2 + 0x54) != -1)))) break;
        uVar4 = uVar4 + 1;
      } while (uVar4 < param_2);
      bVar5 = uVar4 == param_2;
    }
    if (!bVar5) goto LAB_00936c59;
  }
  local_8 = local_8 | 0x200000;
LAB_00936c59:
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


// ==== FUN_00936ca4 @ 0x00936ca4 ====

uint FUN_00936ca4(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  int iVar4;
  int local_64 [16];
  int local_24 [8];
  
  uVar1 = 0;
  if (in_ECX[0x56] == 0) {
    piVar3 = local_64;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar3 = 0;
      piVar3 = piVar3 + 1;
    }
    local_24[0] = 0;
    local_24[1] = 0;
    local_24[2] = 0;
    local_24[3] = 0;
    in_ECX[0x86] = 0;
    in_ECX[0x87] = 0;
    piVar3 = in_ECX + 0x7e;
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar3 = 0;
      piVar3 = piVar3 + 1;
    }
    local_24[7] = 0;
    local_24[5] = 0;
    local_24[6] = 0;
    if (in_ECX[2] != 0) {
      do {
        iVar4 = *(int *)(in_ECX[5] + local_24[6] * 4);
        uVar1 = *(uint *)(*(int *)(in_ECX[4] + *(int *)(iVar4 + 4) * 4) + 4);
        if ((uVar1 & 0x20) == 0) {
          if (((uVar1 & 0x10) != 0) && ((uVar1 & 0x200) == 0)) {
            iVar2 = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(iVar4 + 0x6c));
            uVar1 = (**(code **)(*in_ECX + 0x58))(*(undefined4 *)(iVar4 + 0x6c));
            if (iVar2 == 6) {
              if (uVar1 < 8) {
                iVar2 = uVar1 + 0x7e;
                goto LAB_00936dd3;
              }
            }
            else if ((iVar2 == 0xb) && (uVar1 < 2)) {
              iVar2 = uVar1 + 0x86;
LAB_00936dd3:
              uVar1 = *(int *)(iVar4 + 0x10) + 1;
              if ((uint)in_ECX[iVar2] < uVar1) {
                in_ECX[iVar2] = uVar1;
              }
            }
          }
        }
        else {
          iVar2 = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(iVar4 + 0x6c));
          uVar1 = (**(code **)(*in_ECX + 0x58))(*(undefined4 *)(iVar4 + 0x6c));
          if (iVar2 == 0xb) {
            if (uVar1 < 4) {
              local_64[*(int *)(iVar4 + 0x10) + uVar1 * 4] = 1;
              local_24[uVar1] = *(int *)(iVar4 + 0x60);
            }
          }
          else if ((((iVar2 == 0xd) && (uVar1 == 0)) && (*(int *)(iVar4 + 0x10) != 0)) &&
                  (local_24[5] == 0)) {
            FUN_0091a001();
            local_24[5] = 1;
            local_24[7] = 1;
          }
        }
        local_24[6] = local_24[6] + 1;
      } while ((uint)local_24[6] < (uint)in_ECX[2]);
    }
    local_24[6] = 0;
    local_24[4] = 1;
    uVar1 = 0;
    do {
      iVar4 = 0;
      piVar3 = local_64 + uVar1 * 4;
      local_24[5] = 4;
      do {
        iVar2 = *piVar3;
        piVar3 = piVar3 + 1;
        iVar4 = iVar4 + (uint)(iVar2 != 0);
        local_24[5] = local_24[5] + -1;
      } while (local_24[5] != 0);
      if (iVar4 == 0) {
        if (uVar1 == 0) {
          FUN_0091a001();
          local_24[7] = 1;
        }
        local_24[6] = 1;
      }
      else {
        if (iVar4 != 4) {
          FUN_0091a001();
          local_24[7] = 1;
        }
        if (local_24[6] != 0) {
          local_24[4] = 0;
        }
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < 4);
    if (local_24[4] == 0) {
      FUN_0091a001();
      local_24[7] = 1;
    }
    uVar1 = -(uint)(local_24[7] != 0) & 0x80004005;
  }
  return uVar1;
}


// ==== FUN_00936ea3 @ 0x00936ea3 ====

void FUN_00936ea3(void)

{
  uint *puVar1;
  int iVar2;
  int *in_ECX;
  uint uVar3;
  int local_54 [4];
  int local_44 [4];
  undefined4 local_34 [4];
  undefined4 local_24 [4];
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar1 = (uint *)in_ECX[0x40];
  local_c = puVar1[3];
  local_14 = puVar1[4];
  local_10 = puVar1[2];
  uVar3 = *puVar1 & 0xfffff;
  iVar2 = (**(code **)(*in_ECX + 0x80))(in_ECX[0x3f],local_34,4,0,0);
  if (-1 < iVar2) {
    local_8 = 0;
    do {
      local_44[local_8] = in_ECX[0x88];
      local_54[local_8] = in_ECX[0x89];
      if (local_8 < local_c) {
        local_24[local_8] =
             local_34[*(int *)(*(int *)(in_ECX[5] + *(int *)(local_8 * 4 + local_14) * 4) + 0x10)];
      }
      local_8 = local_8 + 1;
    } while (local_8 < 4);
    FUN_0094d663(2,local_24,local_c,local_10,local_10 + uVar3 * 4,0,uVar3,0,0x1000000,0,0);
    FUN_0094d663(0x58,local_14,local_c,local_24,local_54,local_44,uVar3,0,0,0,0);
  }
  return;
}


// ==== FUN_00936f7f @ 0x00936f7f ====

void FUN_00936f7f(void)

{
  uint *puVar1;
  int iVar2;
  int *in_ECX;
  uint uVar3;
  int local_54 [4];
  int local_44 [4];
  undefined4 local_34 [4];
  undefined4 local_24 [4];
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar1 = (uint *)in_ECX[0x40];
  local_c = puVar1[3];
  local_14 = puVar1[4];
  local_10 = puVar1[2];
  uVar3 = *puVar1 & 0xfffff;
  iVar2 = (**(code **)(*in_ECX + 0x80))(in_ECX[0x3f],local_34,4,0,0);
  if (-1 < iVar2) {
    local_8 = 0;
    do {
      local_54[local_8] = in_ECX[0x88];
      local_44[local_8] = in_ECX[0x89];
      if (local_8 < local_c) {
        local_24[local_8] =
             local_34[*(int *)(*(int *)(in_ECX[5] + *(int *)(local_8 * 4 + local_14) * 4) + 0x10)];
      }
      local_8 = local_8 + 1;
    } while (local_8 < 4);
    FUN_0094d663(2,local_24,local_c,local_10,local_10 + uVar3 * 4,0,uVar3,0,0x1000000,0,0);
    FUN_0094d663(0x58,local_14,local_c,local_24,local_54,local_44,uVar3,0,0,0,0);
  }
  return;
}


// ==== FUN_0093705b @ 0x0093705b ====

void FUN_0093705b(void)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int *in_ECX;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  int local_38 [4];
  int local_28 [4];
  int local_18;
  int *local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  puVar1 = (uint *)in_ECX[0x40];
  local_8 = puVar1[3];
  piVar2 = (int *)puVar1[2];
  local_14 = (int *)puVar1[4];
  uVar6 = *puVar1 & 0xfffff;
  piVar9 = piVar2 + uVar6;
  iVar4 = in_ECX[5];
  local_c = *(uint *)(iVar4 + *piVar2 * 4);
  iVar5 = *(int *)(iVar4 + *local_14 * 4);
  local_18 = *(int *)(iVar4 + *piVar9 * 4);
  local_10 = piVar9;
  if (((*(int *)(iVar5 + 4) == *(int *)(local_c + 4)) &&
      (*(int *)(iVar5 + 0xc) == *(int *)(local_c + 0xc))) ||
     ((*(int *)(iVar5 + 4) == *(int *)(local_18 + 4) &&
      (*(int *)(iVar5 + 0xc) == *(int *)(local_18 + 0xc))))) {
    iVar4 = (**(code **)(*in_ECX + 0x80))(in_ECX[0x3f],local_38,4,0,0);
    if (iVar4 < 0) {
      return;
    }
    local_c = 0;
    if (local_8 != 0) {
      iVar4 = in_ECX[5];
      local_18 = (int)local_14 - (int)local_28;
      do {
        uVar3 = local_c;
        iVar5 = local_c * 4;
        local_c = local_c + 1;
        local_28[uVar3] =
             local_38[*(int *)(*(int *)(iVar4 + *(int *)((int)local_28 + local_18 + iVar5) * 4) +
                              0x10)];
      } while (local_c < local_8);
    }
    FUN_0094d663(2,local_28,local_8,piVar2,local_10,0,uVar6,0,0x1000000,0,0);
    uVar7 = 0x58;
    piVar8 = local_28;
    piVar9 = piVar2;
    piVar10 = local_10;
  }
  else {
    piVar10 = (int *)0x0;
    uVar7 = 0xb;
    piVar8 = piVar2;
  }
  FUN_0094d663(uVar7,local_14,local_8,piVar8,piVar9,piVar10,uVar6,0,0,0,0);
  return;
}


// ==== FUN_00937191 @ 0x00937191 ====

void FUN_00937191(void)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int *in_ECX;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  int local_38 [4];
  int local_28 [4];
  int local_18;
  int *local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  puVar1 = (uint *)in_ECX[0x40];
  local_8 = puVar1[3];
  piVar2 = (int *)puVar1[2];
  local_14 = (int *)puVar1[4];
  uVar6 = *puVar1 & 0xfffff;
  local_10 = piVar2 + uVar6;
  iVar4 = in_ECX[5];
  local_c = *(uint *)(iVar4 + *piVar2 * 4);
  iVar5 = *(int *)(iVar4 + *local_14 * 4);
  local_18 = *(int *)(iVar4 + *local_10 * 4);
  if (((*(int *)(iVar5 + 4) == *(int *)(local_c + 4)) &&
      (*(int *)(iVar5 + 0xc) == *(int *)(local_c + 0xc))) ||
     ((*(int *)(iVar5 + 4) == *(int *)(local_18 + 4) &&
      (*(int *)(iVar5 + 0xc) == *(int *)(local_18 + 0xc))))) {
    iVar4 = (**(code **)(*in_ECX + 0x80))(in_ECX[0x3f],local_38,4,0,0);
    if (iVar4 < 0) {
      return;
    }
    local_c = 0;
    if (local_8 != 0) {
      iVar4 = in_ECX[5];
      local_18 = (int)local_14 - (int)local_28;
      do {
        uVar3 = local_c;
        iVar5 = local_c * 4;
        local_c = local_c + 1;
        local_28[uVar3] =
             local_38[*(int *)(*(int *)(iVar4 + *(int *)((int)local_28 + local_18 + iVar5) * 4) +
                              0x10)];
      } while (local_c < local_8);
    }
    FUN_0094d663(2,local_28,local_8,piVar2,local_10,0,uVar6,0,0x1000000,0,0);
    uVar7 = 0x58;
    piVar8 = local_28;
    piVar9 = piVar2;
  }
  else {
    piVar9 = (int *)0x0;
    uVar7 = 10;
    piVar8 = piVar2;
  }
  FUN_0094d663(uVar7,local_14,local_8,piVar8,local_10,piVar9,uVar6,0,0,0,0);
  return;
}


// ==== FUN_009372c7 @ 0x009372c7 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_009372c7(int param_1,uint *param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  char *pcVar7;
  int extraout_EAX;
  uint uVar8;
  int *in_ECX;
  int *piVar9;
  uint uVar10;
  int local_3c;
  uint local_38;
  char *local_34;
  uint local_30;
  uint *local_2c;
  char local_28 [16];
  uint local_18 [5];
  
  local_18[4] = DAT_00b49670;
  local_2c = param_2;
  local_30 = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(param_1 + 0x6c));
  uVar4 = (**(code **)(*in_ECX + 0x58))(*(undefined4 *)(param_1 + 0x6c));
  uVar10 = 0;
  if (in_ECX[0x56] == 0) {
    if (local_30 == 0xb) {
      if ((uint)in_ECX[10] <= uVar4) {
        return -0x7fffbffb;
      }
      *local_2c = uVar4;
      uVar8 = in_ECX[uVar4 + 0x86];
      local_34 = (char *)0x1;
    }
    else {
      if (local_30 != 6) {
        return -0x7fffbffb;
      }
      if (7 < uVar4) {
        return -0x7fffbffb;
      }
      *local_2c = uVar4 + 2;
      uVar8 = in_ECX[uVar4 + 0x7e];
      local_34 = (char *)0x3;
    }
    local_2c = (uint *)0x0;
    if (uVar8 != 0) {
      do {
        if (uVar10 == 0) {
          local_2c = (uint *)((uint)local_2c | 0x10000);
        }
        else if (uVar10 == 1) {
          local_2c = (uint *)((uint)local_2c | 0x20000);
        }
        else if (uVar10 == 2) {
          local_2c = (uint *)((uint)local_2c | 0x40000);
        }
        else if (uVar10 == 3) {
          local_2c = (uint *)((uint)local_2c | 0x80000);
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < uVar8);
    }
    if ((local_34 != (char *)0x1) &&
       (((*(byte *)(in_ECX + 0x33) & 0x20) != 0 ||
        ((local_30 == 6 && ((*(byte *)(param_1 + 3) & 2) != 0)))))) {
      local_2c = (uint *)((uint)local_2c | 0x200000);
    }
    local_38 = 0;
    if ((*(byte *)(param_1 + 3) & 1) != 0) {
      local_38 = 0x400000;
    }
    iVar6 = FUN_0094d495(0x200001f);
    if (iVar6 < 0) {
      return iVar6;
    }
    iVar6 = FUN_0094b4db(0x80000000);
    if (iVar6 < 0) {
      return iVar6;
    }
    if ((*(byte *)(in_ECX + 0x33) & 1) != 0) {
      local_3c = 0;
      local_30 = 0;
      local_18[0] = 0xffffffff;
      local_18[1] = 0xffffffff;
      local_18[2] = 0xffffffff;
      local_18[3] = 0xffffffff;
      if (in_ECX[2] != 0) {
        iVar6 = *(int *)(param_1 + 4);
        piVar9 = (int *)in_ECX[5];
        do {
          iVar3 = *piVar9;
          if (((iVar6 == *(int *)(iVar3 + 4)) && (*(int *)(param_1 + 8) == *(int *)(iVar3 + 8))) &&
             (*(int *)(param_1 + 0xc) == *(int *)(iVar3 + 0xc))) {
            local_18[*(int *)(iVar3 + 0x10)] = local_30;
          }
          local_30 = local_30 + 1;
          piVar9 = piVar9 + 1;
        } while (local_30 < (uint)in_ECX[2]);
      }
      uVar10 = 0;
      iVar6 = local_3c;
      do {
        if (local_18[uVar10] != 0xffffffff) {
          local_18[iVar6] = local_18[uVar10];
          iVar6 = iVar6 + 1;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < 4);
      iVar6 = (**(code **)(*in_ECX + 0x70))(local_18,iVar6,&local_3c,1);
      if (iVar6 < 0) {
        return iVar6;
      }
    }
    iVar6 = (**(code **)(*in_ECX + 100))
                      ((((uint)local_34 | 0xfffffff8) << 0x14 | (uint)local_34 & 0x18) << 8 |
                       uVar4 & 0x7ff | local_38,local_2c,0);
    if (iVar6 < 0) {
      return iVar6;
    }
    iVar6 = FUN_00948616();
    if (iVar6 < 0) {
      return iVar6;
    }
  }
  else if (*(int *)(param_1 + 0x6c) != -1) {
    if (local_30 != 0xffff) {
      puVar5 = (undefined4 *)FUN_0094c864(local_30);
      __snprintf(local_28,0x20,s_v__s_d_00a29b60,*puVar5,uVar4);
      local_18[3] = local_18[3] & 0xffffff;
      iVar6 = FUN_00907c5b(local_28,*(undefined4 *)(param_1 + 0xc),1);
      if (iVar6 < 0) {
        return iVar6;
      }
      in_ECX[0x7c] = in_ECX[0x7c] + 1;
      if ((((*(byte *)(in_ECX + 0x33) & 1) != 0) && (iVar6 = *(int *)(param_1 + 0x60), iVar6 != 0))
         && ((*(int *)(iVar6 + 4) == 6 && (iVar6 = *(int *)(iVar6 + 0x14), *(int *)(iVar6 + 4) == 3)
             ))) {
        pcVar7 = *(char **)(iVar6 + 0x18);
        pcVar1 = pcVar7 + 1;
        do {
          cVar2 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar2 != '\0');
        local_34 = operator_new((uint)(pcVar7 + (3 - (int)pcVar1)));
        if (local_34 == (char *)0x0) {
          return -0x7ff8fff2;
        }
        _sprintf(local_34,&DAT_00a29b50,*(undefined4 *)(iVar6 + 0x18));
        FUN_00907c5b(local_34,*(undefined4 *)(param_1 + 0xc),1);
        _free(local_34);
        return extraout_EAX;
      }
    }
    if (local_2c != (uint *)0x0) {
      *local_2c = *(uint *)(param_1 + 0x6c);
    }
  }
  return 0;
}


// ==== FUN_009375bd @ 0x009375bd ====

undefined4 FUN_009375bd(int param_1,uint *param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(param_1 + 0x6c));
  uVar2 = (**(code **)(*in_ECX + 0x58))(*(undefined4 *)(param_1 + 0x6c));
  *param_2 = uVar2;
  if (iVar1 == 0xb) {
    if ((uint)in_ECX[10] <= uVar2) {
      return 0x80004005;
    }
    *param_3 = 1;
  }
  else if (iVar1 == 6) {
    if (7 < uVar2) {
      return 0x80004005;
    }
    *param_3 = 3;
  }
  else {
    if (iVar1 != 0xffff) {
      return 0x80004005;
    }
    *param_3 = 0;
  }
  return 0;
}


// ==== FUN_0093762b @ 0x0093762b ====

undefined4 FUN_0093762b(int param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  undefined4 local_8;
  
  local_8 = 1;
  iVar1 = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(param_1 + 0x6c));
  uVar2 = (**(code **)(*in_ECX + 0x58))(*(undefined4 *)(param_1 + 0x6c));
  *param_2 = uVar2;
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
    *param_3 = 9;
  }
  else {
    if (iVar1 != 0xffff) {
      return 0x80004005;
    }
    *param_3 = 0;
    local_8 = 0;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = local_8;
  }
  return 0;
}


// ==== FUN_009376b0 @ 0x009376b0 ====

undefined4 FUN_009376b0(uint param_1,int *param_2)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_1 - (int)param_2;
  param_1 = 0;
  piVar3 = &DAT_00b5a1f0;
  while( true ) {
    bVar1 = true;
    iVar5 = 4;
    piVar2 = param_2;
    do {
      if ((*(int *)(iVar4 + (int)piVar2) != *piVar3) && (*piVar2 != -1)) {
        bVar1 = false;
      }
      piVar3 = piVar3 + 1;
      piVar2 = piVar2 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    if (bVar1) break;
    param_1 = param_1 + 0x10;
    if (0x7f < param_1) {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_00937706 @ 0x00937706 ====

int FUN_00937706(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  int local_30 [4];
  int local_20 [5];
  int local_c;
  int local_8;
  
  uVar4 = 0;
  bVar6 = param_3 == 0;
  if (param_3 != 0) {
    local_c = *(int *)(in_ECX[0x40] + 8);
    local_20[4] = *(int *)(*(int *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 0x10) * 4) + 4);
    local_8 = 0;
    do {
      if ((local_20[4] == *(int *)(*(int *)(in_ECX[5] + *(int *)(local_8 + local_c) * 4) + 4)) &&
         (*(int *)(*(int *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 0x10) * 4) + 0xc) ==
          *(int *)(*(int *)(in_ECX[5] + *(int *)(local_8 + *(int *)(in_ECX[0x40] + 8)) * 4) + 0xc)))
      break;
      local_8 = local_8 + param_2 * 4;
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_3);
    bVar6 = uVar4 == param_3;
  }
  if (!bVar6) {
    iVar1 = *(int *)(in_ECX[0x40] + 8) + uVar4 * param_2 * 4;
    local_20[0] = -1;
    local_20[1] = 0xffffffff;
    local_20[2] = 0xffffffff;
    uVar4 = 0;
    uVar5 = 0;
    local_20[3] = 0xffffffff;
    if (param_2 != 0) {
      do {
        iVar3 = *(int *)(iVar1 + uVar4 * 4);
        uVar4 = uVar4 + 1;
        local_20[*(int *)(*(int *)(in_ECX[5] + iVar3 * 4) + 0x10)] = iVar3;
      } while (uVar4 < param_2);
    }
    uVar4 = 0;
    do {
      uVar5 = uVar5 + (local_20[uVar4] != -1);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 4);
    iVar3 = (**(code **)(*in_ECX + 0x80))(in_ECX[0x3f],local_30,4,0,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = FUN_009149f7(0x74);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_0091455d();
    }
    *param_1 = iVar3;
    if (iVar3 == 0) {
      return -0x7ff8fff2;
    }
    iVar3 = FUN_00914a42(uVar5 & 0xfffff | 0x10000000,uVar5,uVar5,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = FUN_00914593(in_ECX[0x40]);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = 0;
    uVar4 = 0;
    do {
      if (*(int *)((int)local_20 + uVar4) != -1) {
        *(undefined4 *)(iVar3 + *(int *)(*param_1 + 0x10)) = *(undefined4 *)((int)local_30 + uVar4);
        *(undefined4 *)(iVar3 + *(int *)(*param_1 + 8)) = *(undefined4 *)((int)local_20 + uVar4);
        iVar3 = iVar3 + 4;
      }
      uVar4 = uVar4 + 4;
    } while (uVar4 < 0x10);
    uVar4 = 0;
    if (param_2 != 0) {
      do {
        piVar2 = (int *)(iVar1 + uVar4 * 4);
        uVar4 = uVar4 + 1;
        *piVar2 = local_30[*(int *)(*(int *)(in_ECX[5] + *piVar2 * 4) + 0x10)];
      } while (uVar4 < param_2);
    }
  }
  return 0;
}


// ==== FUN_009378ae @ 0x009378ae ====

int * FUN_009378ae(int *param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int aiStack_14 [4];
  
  piVar1 = param_1;
  iVar5 = *(int *)(in_ECX + 8);
  uVar4 = 0;
  if (iVar5 != 0) {
    piVar3 = *(int **)(in_ECX + 0x14);
    do {
      if ((*(int *)(in_ECX + 0x88) == *(int *)(*piVar3 + 4)) &&
         (uVar6 = *(uint *)(*piVar3 + 0xc), uVar4 <= uVar6)) {
        uVar4 = uVar6 + 1;
      }
      piVar3 = piVar3 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  uVar6 = 0;
  do {
    iVar5 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),uVar4,uVar6,0);
    aiStack_14[uVar6] = iVar5;
    if (iVar5 == -1) goto LAB_0093792c;
    uVar6 = uVar6 + 1;
  } while (uVar6 < 4);
  iVar5 = FUN_009149f7();
  if (iVar5 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = FUN_0091455d();
  }
  *param_1 = iVar5;
  if (iVar5 == 0) {
LAB_0093792c:
    param_1 = (int *)0x8007000e;
  }
  else {
    iVar2 = FUN_00914a42(param_2 & 0xfffff | 0x10000000,param_2,param_2,0);
    iVar5 = *param_1;
    if (-1 < iVar2) {
      iVar2 = FUN_00914593();
      if (-1 < iVar2) {
        param_1 = (int *)0x0;
        if (param_2 != 0) {
          do {
            iVar2 = (int)param_1 * 4;
            iVar5 = aiStack_14[(int)param_1];
            *(int *)(iVar2 + *(int *)(*piVar1 + 8)) = iVar5;
            *(undefined4 *)(iVar2 + *(int *)(*piVar1 + 0x10)) =
                 *(undefined4 *)(iVar2 + *(int *)(*(int *)(in_ECX + 0x100) + 0x10));
            *(int *)(iVar2 + *(int *)(*(int *)(in_ECX + 0x100) + 0x10)) = iVar5;
            param_1 = (int *)((int)param_1 + 1);
          } while (param_1 < param_2);
        }
        return (int *)0;
      }
      iVar5 = *param_1;
    }
    param_1 = (int *)iVar2;
    if (iVar5 != 0) {
      FUN_008f4adb();
    }
  }
  return param_1;
}


// ==== FUN_009379cd @ 0x009379cd ====

int FUN_009379cd(void)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 *puVar12;
  int *piVar13;
  bool bVar14;
  undefined4 uVar16;
  undefined8 uVar15;
  int local_d4 [16];
  int local_94 [4];
  uint local_84 [9];
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  uint local_54 [9];
  int local_30;
  int *local_2c;
  int local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  local_30 = 0;
  local_28 = 0;
  local_14 = (int *)(*(uint *)in_ECX[0x40] & 0xfff00000);
  if (local_14 == (int *)0x0) {
    return 0;
  }
  uVar7 = *(uint *)in_ECX[0x40];
  uVar11 = ((uint *)in_ECX[0x40])[1];
  piVar9 = (int *)(uVar7 & 0xfffff);
  local_10 = (int *)(uVar11 / (uint)piVar9);
  local_24 = piVar9;
  local_54[8] = uVar11 % (uint)piVar9;
  if ((((uVar7 & 0xfff00000) == 0x50000000) || (local_14 == (int *)0x50200000)) ||
     (local_14 == (int *)0x70800000)) {
    bVar14 = true;
  }
  else {
    bVar14 = false;
  }
  local_8 = (int *)0x0;
  if (((local_14 == (int *)0x60500000) || (local_14 == (int *)0x60a00000)) ||
     ((local_14 == (int *)0x60f00000 || (local_14 == (int *)0x11000000)))) {
    iVar4 = FUN_00915471();
    if (iVar4 < 0) {
      return iVar4;
    }
    *(undefined4 *)in_ECX[0x40] = 0;
    goto LAB_009385d1;
  }
  if (bVar14) {
    if ((local_14 == (int *)0x50200000) || (local_14 == (int *)0x70800000)) {
      iVar4 = FUN_00915471();
      if (iVar4 < 0) {
        return iVar4;
      }
      *(undefined4 *)in_ECX[0x40] = 0;
      return iVar4;
    }
    if (*(int *)(*(int *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 0x10) * 4) + 4) == in_ECX[0x21]) {
      FUN_0091a001();
      return -0x7fffbffb;
    }
    local_c = (int *)0x0;
    if (local_10 != (int *)0x0) {
      local_2c = (int *)0x0;
      local_8 = local_d4;
      local_14 = (int *)((int)piVar9 << 2);
      do {
        piVar8 = local_8;
        piVar5 = local_8 + 1;
        *local_8 = -1;
        *piVar5 = -1;
        piVar8[2] = -1;
        piVar8[3] = -1;
        if (piVar9 != (int *)0x0) {
          piVar5 = (int *)(*(int *)(in_ECX[0x40] + 8) + (int)local_2c);
          local_20 = piVar9;
          do {
            *piVar8 = *(int *)(*(int *)(in_ECX[5] + *piVar5 * 4) + 0x10);
            piVar5 = piVar5 + 1;
            piVar8 = piVar8 + 1;
            local_20 = (int *)((int)local_20 - 1);
          } while (local_20 != (int *)0x0);
        }
        local_18 = (int *)0x0;
        puVar10 = &DAT_00b5a1f0;
        while (iVar4 = FUN_0092b81e(local_8,puVar10), iVar4 == 0) {
          local_18 = local_18 + 4;
          puVar10 = puVar10 + 4;
          if ((int *)0x7f < local_18) {
            if ((*(byte *)(in_ECX + 0x1b) & 2) == 0) goto LAB_00938389;
            iVar4 = FUN_00937706(&local_28,piVar9,local_10);
            if (iVar4 < 0) goto LAB_009385e1;
            if (local_28 != 0) {
              iVar4 = FUN_00915205();
              if (iVar4 < 0) goto LAB_009385e1;
              local_28 = 0;
            }
            iVar4 = FUN_009149f7();
            if (iVar4 == 0) {
              iVar6 = 0;
            }
            else {
              iVar6 = FUN_0091455d();
            }
            if (iVar6 != 0) {
              local_8 = (int *)0x0;
              if ((int *)in_ECX[2] != (int *)0x0) {
                piVar9 = (int *)in_ECX[5];
                local_20 = (int *)in_ECX[2];
                do {
                  uVar7 = *(uint *)(*(int *)(in_ECX[4] + *(int *)(*piVar9 + 4) * 4) + 4);
                  if ((((uVar7 & 1) != 0) && ((uVar7 & 2) != 0)) &&
                     (piVar5 = (int *)(*(int *)(*piVar9 + 0xc) + 1), local_8 < piVar5)) {
                    local_8 = piVar5;
                  }
                  piVar9 = piVar9 + 1;
                  local_20 = (int *)((int)local_20 - 1);
                } while (local_20 != (int *)0x0);
              }
              iVar4 = FUN_00914a42(0x20500001,2,1,0);
              if ((iVar4 < 0) || (iVar4 = FUN_00914593(), iVar4 < 0)) goto LAB_009385e1;
              local_20 = (int *)FUN_00915318(in_ECX[0x22],local_8,0,0);
              local_8 = (int *)((int)local_8 + 1);
              if (local_20 != (int *)0xffffffff) {
                **(uint **)(iVar6 + 0x10) = (uint)local_20;
                **(undefined4 **)(iVar6 + 8) = **(undefined4 **)(in_ECX[0x40] + 8);
                *(undefined4 *)(*(int *)(iVar6 + 8) + 4) =
                     *(undefined4 *)((int)local_14 + *(int *)(in_ECX[0x40] + 8));
                iVar4 = FUN_00915205();
                if (iVar4 < 0) goto LAB_009385e1;
                local_1c = (int *)0x1;
                if ((int *)0x1 < local_24) {
                  local_14 = local_14 + 1;
                  do {
                    iVar4 = FUN_009149f7();
                    if (iVar4 == 0) {
                      iVar6 = 0;
                    }
                    else {
                      iVar6 = FUN_0091455d();
                    }
                    if (iVar6 == 0) goto LAB_00938557;
                    iVar4 = FUN_00914a42(0x70300001,3,1,0);
                    if ((iVar4 < 0) || (iVar4 = FUN_00914593(), iVar4 < 0)) goto LAB_009385e1;
                    **(undefined4 **)(iVar6 + 8) =
                         *(undefined4 *)(*(int *)(in_ECX[0x40] + 8) + (int)local_1c * 4);
                    *(undefined4 *)(*(int *)(iVar6 + 8) + 4) =
                         *(undefined4 *)((int)local_14 + *(int *)(in_ECX[0x40] + 8));
                    *(int **)(*(int *)(iVar6 + 8) + 8) = local_20;
                    if (local_1c == (int *)((int)local_24 - 1U)) {
                      piVar9 = (int *)**(uint **)(in_ECX[0x40] + 0x10);
                    }
                    else {
                      piVar9 = (int *)FUN_00915318(in_ECX[0x22],local_8,0,0);
                      local_8 = (int *)((int)local_8 + 1);
                      local_20 = piVar9;
                      if (piVar9 == (int *)0xffffffff) goto LAB_00938557;
                    }
                    **(uint **)(iVar6 + 0x10) = (uint)piVar9;
                    iVar4 = FUN_00915205();
                    if (iVar4 < 0) goto LAB_009385e1;
                    local_1c = (int *)((int)local_1c + 1);
                    local_14 = local_14 + 1;
                  } while (local_1c < local_24);
                }
                goto LAB_009383a0;
              }
            }
LAB_00938557:
            iVar4 = -0x7ff8fff2;
            goto LAB_009385e1;
          }
        }
        local_c = (int *)((int)local_c + 1);
        local_2c = (int *)((int)local_2c + (int)local_14);
        local_8 = local_8 + 4;
      } while (local_c < local_10);
    }
LAB_00938389:
    iVar4 = FUN_00915471();
    if (iVar4 < 0) {
      return iVar4;
    }
  }
  else {
    local_c = (int *)0x0;
    if (local_10 != (int *)0x0) {
      local_18 = (int *)0x0;
      local_2c = local_d4;
      do {
        piVar5 = local_2c;
        bVar14 = local_24 != (int *)0x0;
        piVar9 = local_2c + 1;
        *local_2c = -1;
        *piVar9 = -1;
        piVar5[2] = -1;
        piVar5[3] = -1;
        if (bVar14) {
          local_1c = *(int **)(in_ECX[0x40] + 0x10);
          iVar4 = in_ECX[5];
          iVar6 = (int)local_c * 4;
          piVar9 = (int *)(*(int *)(in_ECX[0x40] + 8) + (int)local_18);
          local_14 = local_24;
          do {
            iVar1 = *local_1c;
            iVar2 = *piVar9;
            local_1c = local_1c + 1;
            piVar9 = piVar9 + 1;
            piVar5 = (int *)((int)local_14 + -1);
            local_14 = piVar5;
            local_d4[*(int *)(*(int *)(iVar4 + iVar1 * 4) + 0x10) + iVar6] =
                 *(int *)(*(int *)(iVar4 + iVar2 * 4) + 0x10);
          } while (piVar5 != (int *)0x0);
        }
        local_c = (int *)((int)local_c + 1);
        local_2c = local_2c + 4;
        local_18 = local_18 + (int)local_24;
      } while (local_c < local_10);
    }
    if ((*(byte *)(*(int *)(in_ECX[4] +
                           *(int *)(*(int *)(in_ECX[5] + **(int **)(in_ECX[0x40] + 0x10) * 4) + 4) *
                           4) + 4) & 0x20) == 0) {
      local_c = (int *)0x0;
      if (local_10 != (int *)0x0) {
        local_18 = local_d4;
        do {
          puVar10 = &DAT_00b5a1f0;
          uVar7 = 0;
          while (iVar4 = FUN_0092b81e(local_18,puVar10), iVar4 == 0) {
            uVar7 = uVar7 + 0x10;
            puVar10 = puVar10 + 4;
            if (0x7f < uVar7) {
              local_8 = (int *)0x1;
              goto LAB_00937c9f;
            }
          }
          local_c = (int *)((int)local_c + 1);
          local_18 = local_18 + 4;
        } while (local_c < local_10);
      }
    }
    else {
      local_20 = *(int **)(in_ECX[5] + **(int **)(in_ECX[0x40] + 8) * 4);
      local_18 = (int *)(**(code **)(*in_ECX + 0x54))();
      if (local_18 != (int *)0xffff) {
        if (local_18 == (int *)0xb) {
          piVar9 = (int *)FUN_0092b81e(local_d4,&DAT_00b5a230);
LAB_00937bbe:
          local_8 = (int *)(uint)(piVar9 == (int *)0x0);
          if (local_8 == (int *)0x0) goto LAB_00937bc2;
LAB_00937bcb:
          iVar4 = FUN_009378ae(&local_30,local_24);
          if (iVar4 < 0) goto LAB_009385d1;
        }
        else {
          if (local_18 == (int *)0xd) {
            uVar7 = 0;
            local_14 = (int *)0x0;
            puVar10 = &DAT_00b5a1f0;
            do {
              iVar4 = FUN_0092b81e(local_d4,puVar10);
              if (iVar4 != 0) {
                local_14 = (int *)0x1;
                piVar9 = local_14;
                break;
              }
              uVar7 = uVar7 + 0x10;
              puVar10 = puVar10 + 4;
              piVar9 = local_14;
            } while (uVar7 < 0x40);
            goto LAB_00937bbe;
          }
LAB_00937bc2:
          if ((*(byte *)((int)local_20 + 0x3e) & 0x1f) != 0) goto LAB_00937bcb;
        }
        local_84[0] = 0;
        local_84[1] = 0;
        local_84[2] = 0;
        local_84[3] = 0;
        iVar4 = FUN_009376b0(local_d4,local_84);
        if ((iVar4 != 0) || ((local_18 == (int *)0xd && (local_d4[0] == 0)))) {
          iVar4 = FUN_00947586(local_84,local_10,local_24);
          if (-1 < iVar4) {
            *(undefined4 *)in_ECX[0x40] = 0;
            if (local_30 == 0) {
              return iVar4;
            }
            iVar4 = FUN_00915205();
            if (-1 < iVar4) {
              return iVar4;
            }
          }
          goto LAB_009385d1;
        }
      }
    }
LAB_00937c9f:
    puVar3 = (uint *)in_ECX[0x40];
    if (((*puVar3 & 0xfff00000) == 0x10d00000) || ((*puVar3 & 0xfff00000) == 0x10e00000)) {
      uVar7 = puVar3[1];
      bVar14 = false;
      if (uVar7 != 0) {
        piVar9 = (int *)in_ECX[5];
        piVar5 = (int *)puVar3[2];
        do {
          if ((*(byte *)(piVar9[*piVar5] + 0x3e) & 0x1f) != 0) {
            bVar14 = true;
          }
          piVar5 = piVar5 + 1;
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
        if (bVar14) {
          iVar4 = in_ECX[2];
          uVar7 = 0;
          if (iVar4 != 0) {
            do {
              if ((in_ECX[0x22] == *(int *)(*piVar9 + 4)) &&
                 (uVar11 = *(uint *)(*piVar9 + 0xc), uVar7 <= uVar11)) {
                uVar7 = uVar11 + 1;
              }
              piVar9 = piVar9 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          uVar11 = 0;
          do {
            iVar4 = FUN_00915318(in_ECX[0x22],uVar7,uVar11,0);
            local_94[uVar11] = iVar4;
            if (iVar4 == -1) goto LAB_00937d73;
            uVar11 = uVar11 + 1;
          } while (uVar11 < 4);
          iVar4 = FUN_009149f7();
          if (iVar4 == 0) {
            local_28 = 0;
          }
          else {
            local_28 = FUN_0091455d();
          }
          if (local_28 == 0) {
LAB_00937d73:
            iVar4 = -0x7ff8fff2;
            goto LAB_009385d1;
          }
          uVar7 = *(uint *)(in_ECX[0x40] + 4);
          iVar4 = FUN_00914a42(uVar7 & 0xfffff | 0x10000000,uVar7,
                               *(undefined4 *)(in_ECX[0x40] + 0xc),0);
          if ((iVar4 < 0) || (iVar4 = FUN_00914593(), iVar4 < 0)) goto LAB_009385d1;
          piVar9 = local_94;
          piVar5 = *(int **)(local_28 + 0x10);
          for (uVar7 = *(uint *)(in_ECX[0x40] + 0xc) & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
            *piVar5 = *piVar9;
            piVar9 = piVar9 + 1;
            piVar5 = piVar5 + 1;
          }
          for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
            *(char *)piVar5 = (char)*piVar9;
            piVar9 = (int *)((int)piVar9 + 1);
            piVar5 = (int *)((int)piVar5 + 1);
          }
          puVar10 = *(undefined4 **)(in_ECX[0x40] + 8);
          puVar12 = *(undefined4 **)(local_28 + 8);
          for (uVar7 = *(uint *)(in_ECX[0x40] + 4) & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
            *puVar12 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar12 = puVar12 + 1;
          }
          for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
            *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
          piVar9 = local_94;
          piVar5 = *(int **)(in_ECX[0x40] + 8);
          for (uVar7 = *(uint *)(in_ECX[0x40] + 4) & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
            *piVar5 = *piVar9;
            piVar9 = piVar9 + 1;
            piVar5 = piVar5 + 1;
          }
          for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
            *(char *)piVar5 = (char)*piVar9;
            piVar9 = (int *)((int)piVar9 + 1);
            piVar5 = (int *)((int)piVar5 + 1);
          }
          iVar4 = FUN_00915205();
          if (iVar4 < 0) goto LAB_009385d1;
          local_28 = 0;
        }
      }
    }
    if ((local_8 == (int *)0x0) || ((*(byte *)(in_ECX + 0x1b) & 2) == 0)) {
      iVar4 = FUN_00915471();
      if (iVar4 < 0) goto LAB_009385d1;
    }
    else {
      local_8 = (int *)0x0;
      local_20 = (int *)0x0;
      if (local_24 == (int *)0x4) {
        local_c = (int *)0x1;
        uVar7 = 0;
        do {
          if (local_c == (int *)0x0) break;
          local_84[0] = 0;
          local_84[1] = 0;
          local_84[2] = 0;
          local_84[3] = 0;
          local_84[4] = 0xffffffff;
          local_84[5] = 0xffffffff;
          local_84[6] = 0xffffffff;
          local_84[7] = 0xffffffff;
          local_84[uVar7] = 0xffffffff;
          local_84[uVar7 + 4] = 0;
          local_c = (int *)0x0;
          if (local_10 == (int *)0x0) {
LAB_00937f00:
            iVar4 = FUN_00947586(local_84,local_10,4);
            if ((iVar4 < 0) || (iVar4 = FUN_00947586(local_84 + 4,local_10,4), iVar4 < 0))
            goto LAB_009385d1;
            goto LAB_00938207;
          }
          piVar9 = local_d4;
          local_14 = local_10;
          do {
            iVar4 = FUN_009376b0(piVar9,local_84);
            if ((iVar4 == 0) || (iVar4 = FUN_009376b0(piVar9,local_84), iVar4 == 0)) {
              local_c = (int *)0x1;
            }
            piVar9 = piVar9 + 4;
            local_14 = (int *)((int)local_14 + -1);
          } while (local_14 != (int *)0x0);
          local_14 = (int *)0x0;
          if (local_c == (int *)0x0) goto LAB_00937f00;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 4);
        local_1c = (int *)0x0;
        local_c = (int *)0x1;
        do {
          if (local_c == (int *)0x0) break;
          local_18 = (int *)0x0;
          do {
            piVar5 = local_18;
            piVar9 = local_1c;
            if (local_18 != local_1c) {
              local_84[0] = 0;
              local_84[1] = 0;
              local_84[2] = 0;
              local_84[3] = 0;
              local_84[4] = 0xffffffff;
              local_84[5] = 0xffffffff;
              local_84[6] = 0xffffffff;
              local_84[7] = 0xffffffff;
              local_84[(int)local_1c] = 0xffffffff;
              local_84[(int)piVar5] = 0xffffffff;
              bVar14 = local_10 != (int *)0x0;
              local_84[(int)(piVar9 + 1)] = 0;
              local_84[(int)(piVar5 + 1)] = 0;
              local_c = (int *)0x0;
              local_2c = (int *)0x0;
              if (bVar14) {
                piVar9 = local_d4;
                local_14 = local_10;
                do {
                  local_54[8] = FUN_009376b0(piVar9,local_84);
                  iVar4 = FUN_009376b0(piVar9,local_84 + 4);
                  if (local_54[8] == 0) {
                    local_2c = (int *)0x1;
LAB_00937fb1:
                    local_c = (int *)0x1;
                  }
                  else if (iVar4 == 0) goto LAB_00937fb1;
                  piVar9 = piVar9 + 4;
                  local_14 = (int *)((int)local_14 + -1);
                } while (local_14 != (int *)0x0);
                if (local_c != (int *)0x0) {
                  if (local_2c == (int *)0x0) {
                    local_84[8] = local_84[0];
                    uStack_60 = local_84[1];
                    uStack_5c = local_84[2];
                    uStack_58 = local_84[3];
                    local_54[0] = 0xffffffff;
                    local_54[1] = 0xffffffff;
                    local_54[2] = 0xffffffff;
                    local_54[3] = 0xffffffff;
                    local_54[4] = 0xffffffff;
                    local_54[5] = 0xffffffff;
                    local_54[6] = 0xffffffff;
                    local_54[7] = 0xffffffff;
                    local_54[(int)local_1c] = 0;
                    local_54[(int)(local_18 + 1)] = 0;
                    local_20 = (int *)0x1;
                    piVar5 = local_18;
                  }
                  goto LAB_00938003;
                }
              }
              local_8 = (int *)0x1;
              break;
            }
LAB_00938003:
            local_18 = (int *)((int)piVar5 + 1);
          } while (local_18 < (int *)0x4);
          local_1c = (int *)((int)local_1c + 1);
        } while (local_1c < (int *)0x4);
        if (local_8 == (int *)0x0) {
          if (local_20 == (int *)0x0) goto LAB_009381bb;
          local_8 = (int *)0x1;
          iVar4 = FUN_00947586(local_84 + 8,local_10,4);
          if ((iVar4 < 0) || (iVar4 = FUN_00947586(local_54,local_10,4), iVar4 < 0))
          goto LAB_009385d1;
          uVar16 = 4;
          puVar3 = local_54;
        }
        else {
          iVar4 = FUN_00947586(local_84,local_10,4);
          if (iVar4 < 0) goto LAB_009385d1;
          uVar16 = 4;
LAB_0093819d:
          puVar3 = local_84;
        }
        iVar4 = FUN_00947586(puVar3 + 4,local_10,uVar16);
        if (iVar4 < 0) goto LAB_009385d1;
        if (local_8 == (int *)0x0) goto LAB_009381bb;
      }
      else {
        if (local_24 == (int *)0x3) {
          local_20 = (int *)0xffffffff;
          piVar9 = (int *)0x0;
          do {
            if (local_d4[(int)piVar9] == -1) {
              local_20 = piVar9;
            }
            piVar9 = (int *)((int)piVar9 + 1);
          } while (piVar9 < (int *)0x4);
          local_1c = (int *)0x0;
          do {
            if (local_8 != (int *)0x0) goto LAB_00938181;
            piVar9 = (int *)0x0;
            do {
              piVar8 = local_1c;
              piVar5 = local_20;
              if (local_8 != (int *)0x0) break;
              if (((piVar9 != local_1c) && (piVar9 != local_20)) && (local_1c != local_20)) {
                local_84[0] = 0xffffffff;
                local_84[1] = 0xffffffff;
                local_84[2] = 0xffffffff;
                local_84[3] = 0xffffffff;
                local_84[4] = 0;
                local_84[5] = 0;
                local_84[6] = 0;
                local_84[7] = 0;
                piVar13 = (int *)0x0;
                local_84[(int)local_1c] = 0;
                local_84[(int)piVar9] = 0;
                local_84[(int)(piVar8 + 1)] = 0xffffffff;
                local_84[(int)(piVar9 + 1)] = 0xffffffff;
                local_84[(int)(piVar5 + 1)] = 0xffffffff;
                local_c = (int *)0x0;
                if (local_10 != (int *)0x0) {
                  local_18 = local_d4;
                  do {
                    if (local_c != (int *)0x0) goto LAB_00938164;
                    iVar4 = FUN_009376b0(local_18,local_84);
                    if (iVar4 == 0) {
                      local_c = (int *)0x1;
                    }
                    local_18 = local_18 + 4;
                    piVar13 = (int *)((int)piVar13 + 1);
                  } while (piVar13 < local_10);
                  if (local_c != (int *)0x0) goto LAB_00938164;
                }
                local_8 = (int *)0x1;
              }
LAB_00938164:
              piVar9 = (int *)((int)piVar9 + 1);
            } while (piVar9 < (int *)0x4);
            local_1c = (int *)((int)local_1c + 1);
          } while (local_1c < (int *)0x4);
          if (local_8 != (int *)0x0) {
LAB_00938181:
            iVar4 = FUN_00947586(local_84,local_10,3);
            if (iVar4 < 0) goto LAB_009385d1;
            uVar16 = 3;
            goto LAB_0093819d;
          }
        }
LAB_009381bb:
        piVar9 = (int *)0x0;
        if (local_24 != (int *)0x0) {
          do {
            uVar15 = CONCAT44(local_24,local_10);
            local_84[0] = 0xffffffff;
            local_84[1] = 0xffffffff;
            local_84[2] = 0xffffffff;
            local_84[3] = 0xffffffff;
            local_84[*(int *)(*(int *)(in_ECX[5] +
                                      *(int *)(*(int *)(in_ECX[0x40] + 0x10) + (int)piVar9 * 4) * 4)
                             + 0x10)] = 0;
            iVar4 = FUN_00947586(local_84,uVar15);
            if (iVar4 < 0) goto LAB_009385d1;
            piVar9 = (int *)((int)piVar9 + 1);
          } while (piVar9 < local_24);
        }
      }
LAB_00938207:
      if (local_30 != 0) {
        iVar4 = FUN_00915205();
        if (iVar4 < 0) goto LAB_009385d1;
        local_30 = 0;
      }
    }
  }
LAB_009383a0:
  *(undefined4 *)in_ECX[0x40] = 0;
  iVar4 = 0;
LAB_009385d1:
  if (local_30 != 0) {
    FUN_008f4adb();
  }
LAB_009385e1:
  if (local_28 != 0) {
    FUN_008f4adb();
  }
  return iVar4;
}


// ==== FUN_009385f6 @ 0x009385f6 ====

undefined4 FUN_009385f6(int *param_1,undefined4 *param_2,uint param_3,uint *param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  int in_ECX;
  uint uVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  uint local_28 [4];
  int local_18 [4];
  int local_8;
  
  iVar5 = *param_1;
  iVar3 = *(int *)(in_ECX + 0x14);
  local_8 = *(int *)(iVar3 + iVar5 * 4);
  if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(local_8 + 4) * 4) + 4) & 0x80) != 0) {
    *param_4 = 0xe40000;
    return 0;
  }
  bVar10 = (param_3 & 0x10000) != 0;
  if (bVar10) {
    local_18[0] = 0;
  }
  uVar7 = (uint)bVar10;
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
    param_2 = (undefined4 *)uVar7;
  }
  iVar8 = *(int *)(in_ECX + 0x6c) << 0x1e;
  if (iVar8 < 0) {
    local_28[0] = 0xffffffff;
  }
  else {
    uVar7 = 0;
    if (param_2 != (undefined4 *)0x0) {
      do {
        if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar5 * 4) + 0x10) !=
            *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + param_1[uVar7] * 4) + 0x10)) break;
        uVar7 = uVar7 + 1;
      } while (uVar7 < param_2);
      if (uVar7 < param_2) {
        uVar7 = 0;
        do {
          local_28[uVar7] = uVar7;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 4);
        goto LAB_009386d5;
      }
    }
    local_28[0] = *(uint *)(local_8 + 0x10);
  }
  local_28[1] = local_28[0];
  local_28[2] = local_28[0];
  local_28[3] = local_28[0];
LAB_009386d5:
  uVar7 = 0;
  if (param_2 != (undefined4 *)0x0) {
    do {
      piVar2 = local_18 + uVar7;
      piVar1 = param_1 + uVar7;
      uVar7 = uVar7 + 1;
      local_28[*piVar2] = *(uint *)(*(int *)(iVar3 + *piVar1 * 4) + 0x10);
    } while (uVar7 < param_2);
  }
  uVar7 = 0;
  if (-1 < iVar8) {
    puVar6 = local_28;
LAB_0093875b:
    uVar9 = 0;
    uVar7 = 0x10;
    do {
      uVar4 = *puVar6;
      puVar6 = puVar6 + 1;
      uVar9 = uVar9 | uVar4 << ((byte)uVar7 & 0x1f);
      uVar7 = uVar7 + 2;
    } while (uVar7 < 0x18);
    *param_4 = uVar9;
    return 0;
  }
  param_2 = &DAT_00b5a1f0;
  do {
    iVar5 = FUN_0092b81e(local_28,param_2);
    if (iVar5 != 0) {
      puVar6 = &DAT_00b5a1f0 + uVar7 * 4;
      if (puVar6 != (uint *)0x0) goto LAB_0093875b;
      break;
    }
    param_2 = param_2 + 4;
    uVar7 = uVar7 + 1;
  } while (uVar7 < 8);
  FUN_0091a001();
  return 0x80004005;
}


// ==== FUN_0093877e @ 0x0093877e ====

void FUN_0093877e(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a2b998;
  FUN_00948b75();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_009387a5 @ 0x009387a5 ====

int FUN_009387a5(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  
  iVar2 = FUN_00948e39();
  if (-1 < iVar2) {
    FUN_0093e2c8();
    uVar1 = *(uint *)(in_ECX + 0xc);
    uVar3 = 0;
    if (uVar1 != 0) {
      do {
        iVar2 = *(int *)(*(int *)(in_ECX + 0x18) + uVar3 * 4);
        *(int *)(in_ECX + 0x100) = iVar2;
        *(uint *)(in_ECX + 0xfc) = uVar3;
        if (((*(ushort *)(iVar2 + 2) & 0xfff0) != 0) && (iVar2 = FUN_009379cd(), iVar2 < 0)) {
          return iVar2;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar1);
    }
    iVar2 = FUN_0091ae30();
    if (((-1 < iVar2) && (iVar2 = FUN_0091c491(), -1 < iVar2)) &&
       (iVar2 = FUN_00915e19(), -1 < iVar2)) {
      FUN_0093e2c8();
      iVar2 = 0;
    }
  }
  return iVar2;
}


// ==== FUN_0093881d @ 0x0093881d ====

undefined4 FUN_0093881d(uint *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  uint local_28 [5];
  int local_14;
  uint local_10;
  int local_c;
  undefined4 *local_8;
  
  uVar6 = *param_1 & 0xfffff;
  if (uVar6 == 0) {
    uVar2 = 1;
  }
  else {
    local_28[4] = param_1[1] / uVar6;
    local_10 = 0;
    if (local_28[4] != 0) {
      iVar1 = *(int *)(in_ECX + 0x6c);
      local_c = 0;
      local_14 = in_ECX;
      do {
        local_28[0] = 0xffffffff;
        local_28[1] = 0xffffffff;
        local_28[2] = 0xffffffff;
        uVar5 = 0;
        local_28[3] = 0xffffffff;
        if (uVar6 != 0) {
          iVar4 = *(int *)(local_14 + 0x14);
          piVar3 = (int *)(param_1[2] + local_c);
          do {
            local_28[uVar5] = *(uint *)(*(int *)(iVar4 + *piVar3 * 4) + 0x10);
            uVar5 = uVar5 + 1;
            piVar3 = piVar3 + 1;
          } while (uVar5 < uVar6);
        }
        if (iVar1 << 0x1e < 0) {
          uVar5 = 0;
          local_8 = &DAT_00b5a1f0;
          do {
            iVar4 = FUN_0092b81e(local_28,local_8);
            if (iVar4 != 0) break;
            local_8 = local_8 + 4;
            uVar5 = uVar5 + 1;
          } while (uVar5 < 8);
          if (uVar5 == 8) {
            return 1;
          }
        }
        local_10 = local_10 + 1;
        local_c = local_c + uVar6 * 4;
      } while (local_10 < local_28[4]);
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_009388e6 @ 0x009388e6 ====

undefined4 FUN_009388e6(void)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  bool bVar7;
  uint *puVar8;
  undefined4 local_38 [8];
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  local_18 = in_ECX[3];
  uVar3 = 0;
  iVar5 = 0;
  local_8 = 0;
  if (local_18 != 0) {
    do {
      in_ECX[0x3f] = uVar3;
      in_ECX[0x40] = *(int *)(in_ECX[6] + uVar3 * 4);
      FUN_0093eb91();
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)in_ECX[3]);
  }
  local_14 = 0;
  if (local_18 != 0) {
    do {
      in_ECX[0x3f] = local_14;
      puVar8 = *(uint **)(in_ECX[6] + local_14 * 4);
      in_ECX[0x40] = (int)puVar8;
      uVar3 = *puVar8 & 0xfff00000;
      if (((((((uVar3 == 0x60500000) || (uVar3 == 0x60f00000)) || (uVar3 == 0x60a00000)) ||
            ((uVar3 == 0x60200000 || (uVar3 == 0x60700000)))) || (uVar3 == 0x60c00000)) ||
          (((uVar3 == 0x61100000 || (uVar3 == 0x60300000)) ||
           ((uVar3 == 0x60800000 ||
            (((uVar3 == 0x60d00000 || (uVar3 == 0x61200000)) || (uVar3 == 0x60000000)))))))) ||
         (uVar3 == 0x11000000)) {
        uVar3 = *puVar8 & 0xfffff;
        local_10 = uVar3;
        if ((*puVar8 & 0xfff00000) == 0x11000000) {
          local_10 = 0;
        }
        local_c = 0;
        if (uVar3 != 0) {
          iVar5 = local_10 << 2;
          do {
            iVar1 = *(int *)(in_ECX[5] + *(int *)(iVar5 + *(int *)(in_ECX[0x40] + 8)) * 4);
            if ((*(uint *)(iVar1 + 0x10) != local_c) || ((*(byte *)(iVar1 + 0x3e) & 0x1f) != 0))
            break;
            if (*(int *)(iVar1 + 4) == in_ECX[0x20]) {
              iVar1 = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(iVar1 + 0x6c));
              bVar7 = iVar1 == 6;
            }
            else {
              bVar7 = *(int *)(iVar1 + 4) == in_ECX[0x22];
            }
            if (!bVar7) break;
            local_c = local_c + 1;
            iVar5 = iVar5 + 4;
          } while (local_c < uVar3);
        }
        if (((*(uint *)in_ECX[0x40] & 0xfff00000) == 0x60000000) && (uVar3 == 1)) {
          iVar5 = (**(code **)(*in_ECX + 0x80))(in_ECX[0x3f],local_38 + 4,4,0,0);
          if (iVar5 < 0) {
            return 0;
          }
          iVar5 = FUN_009149f7(0x74);
          if (iVar5 == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = FUN_0091455d();
          }
          if (iVar5 == 0) {
            return 0x8007000e;
          }
          local_8 = iVar5;
          iVar1 = FUN_00914a42(0x10000002,2,2,0);
          if ((iVar1 < 0) || (iVar1 = FUN_00914593(in_ECX[0x40]), iVar1 < 0)) goto LAB_00939143;
          **(undefined4 **)(iVar5 + 8) = *(undefined4 *)(*(int *)(in_ECX[0x40] + 8) + 4);
          *(undefined4 *)(*(int *)(iVar5 + 8) + 4) = *(undefined4 *)(*(int *)(in_ECX[0x40] + 8) + 4)
          ;
          **(undefined4 **)(iVar5 + 0x10) = local_38[4];
          *(undefined4 *)(*(int *)(iVar5 + 0x10) + 4) = local_38[5];
          iVar5 = FUN_00915205(iVar5);
          if (iVar5 < 0) goto LAB_00939143;
          iVar5 = FUN_009149f7(0x74);
          if (iVar5 == 0) {
            uVar3 = 0;
          }
          else {
            uVar3 = FUN_0091455d();
          }
          if (uVar3 == 0) {
            return 0;
          }
          local_c = uVar3;
          iVar5 = FUN_00914a42(0x60500002,4,*(undefined4 *)(in_ECX[0x40] + 0xc),0);
          if ((iVar5 < 0) || (iVar5 = FUN_00914593(in_ECX[0x40]), iVar5 < 0)) goto LAB_0093914a;
          uVar2 = 8;
          do {
            *(undefined4 *)((uVar2 - 8) + *(int *)(uVar3 + 8)) = **(undefined4 **)(in_ECX[0x40] + 8)
            ;
            *(undefined4 *)(uVar2 + *(int *)(uVar3 + 8)) =
                 *(undefined4 *)((int)local_38 + uVar2 + 8);
            uVar2 = uVar2 + 4;
          } while (uVar2 < 0x10);
          puVar4 = *(undefined4 **)(in_ECX[0x40] + 0x10);
          puVar6 = *(undefined4 **)(local_c + 0x10);
          for (uVar3 = *(uint *)(in_ECX[0x40] + 0xc) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar6 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar6 = puVar6 + 1;
          }
          for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
            *(undefined1 *)puVar6 = *(undefined1 *)puVar4;
            puVar4 = (undefined4 *)((int)puVar4 + 1);
            puVar6 = (undefined4 *)((int)puVar6 + 1);
          }
          if (in_ECX[0x40] != 0) {
            FUN_008f4adb(1);
          }
          *(uint *)(in_ECX[6] + local_14 * 4) = local_c;
          in_ECX[0x40] = local_c;
LAB_00938cc1:
          local_8 = 0;
        }
        else if (local_c != uVar3) {
          iVar5 = (**(code **)(*in_ECX + 0x80))(in_ECX[0x3f],local_38,4,0,0);
          if (iVar5 < 0) {
            return 0;
          }
          iVar5 = FUN_009149f7(0x74);
          if (iVar5 == 0) {
            local_8 = 0;
          }
          else {
            local_8 = FUN_0091455d();
          }
          if (local_8 == 0) {
            return 0x8007000e;
          }
          iVar5 = FUN_00914a42(uVar3 | 0x10000000,uVar3,uVar3,0);
          if ((-1 < iVar5) && (iVar5 = FUN_00914593(in_ECX[0x40]), -1 < iVar5)) {
            local_c = 0;
            if (uVar3 != 0) {
              iVar5 = local_10 << 2;
              do {
                uVar2 = local_c;
                iVar1 = local_c * 4;
                local_c = local_c + 1;
                *(undefined4 *)(iVar1 + *(int *)(local_8 + 8)) =
                     *(undefined4 *)(iVar5 + *(int *)(in_ECX[0x40] + 8));
                *(undefined4 *)(iVar1 + *(int *)(local_8 + 0x10)) = local_38[uVar2];
                *(undefined4 *)(iVar5 + *(int *)(in_ECX[0x40] + 8)) =
                     *(undefined4 *)(iVar1 + *(int *)(local_8 + 0x10));
                iVar5 = iVar5 + 4;
              } while (local_c < uVar3);
            }
            iVar5 = FUN_00915205(local_8);
            if (-1 < iVar5) goto LAB_00938cc1;
          }
          goto LAB_00939143;
        }
        puVar8 = (uint *)in_ECX[0x40];
      }
      iVar5 = FUN_00915471(puVar8);
      if (iVar5 < 0) {
        return 0;
      }
      *(undefined4 *)in_ECX[0x40] = 0;
      local_14 = local_14 + 1;
    } while (local_14 < local_18);
  }
  FUN_0093e2c8();
  local_18 = in_ECX[3];
  uVar3 = 0;
  if (local_18 != 0) {
    do {
      in_ECX[0x3f] = uVar3;
      iVar1 = *(int *)(in_ECX[6] + uVar3 * 4);
      in_ECX[0x40] = iVar1;
      iVar1 = *(int *)(iVar1 + 0x3c);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) == 0xd)) {
        in_ECX[0x41] = iVar1 + 0x30;
      }
      puVar8 = (uint *)in_ECX[0x40];
      uVar2 = *puVar8 & 0xfff00000;
      if (((uVar2 != 0) && (puVar8[1] != 0)) &&
         (*(int *)(*(int *)(in_ECX[5] + *(int *)puVar8[2] * 4) + 8) != -1)) goto LAB_00939113;
      if (uVar2 < 0x60500001) {
        if (uVar2 == 0x60500000) {
LAB_0093902e:
          iVar5 = FUN_0094dc51();
        }
        else if (uVar2 < 0x20100001) {
          if (uVar2 == 0x20100000) goto LAB_009390e0;
          if (uVar2 < 0x10600001) {
            if (uVar2 == 0x10600000) {
              iVar5 = FUN_0094f3c9();
            }
            else if (uVar2 != 0) {
              if (uVar2 == 0x10000000) {
                iVar5 = FUN_0094f236();
              }
              else if (uVar2 == 0x10100000) {
                iVar5 = FUN_0094e840();
              }
              else if (uVar2 == 0x10300000) {
                iVar5 = FUN_0094f383();
              }
              else if (uVar2 == 0x10400000) {
                iVar5 = FUN_0094f3a1();
              }
              else {
                if (uVar2 != 0x10500000) goto LAB_00939127;
                iVar5 = FUN_0094f3ab();
              }
            }
          }
          else if (uVar2 == 0x10700000) {
            iVar5 = FUN_0094f3e7();
          }
          else if (uVar2 == 0x10d00000) {
            if ((*(byte *)(in_ECX + 0x1c) & 0x10) == 0) {
LAB_00938e77:
              iVar5 = -0x7fffbfff;
            }
            else {
              iVar5 = FUN_0094f36f();
            }
          }
          else if (uVar2 == 0x10e00000) {
            if ((*(byte *)(in_ECX + 0x1c) & 0x10) == 0) goto LAB_00938e77;
            iVar5 = FUN_0094f379();
          }
          else {
            if (uVar2 == 0x10f00000) goto LAB_009390ce;
            if (uVar2 != 0x11000000) {
              if (uVar2 != 0x20000000) goto LAB_00939127;
              goto LAB_00938e4d;
            }
            iVar5 = FUN_0094e04c();
          }
        }
        else if (uVar2 < 0x50000001) {
          if (uVar2 == 0x50000000) {
            iVar5 = FUN_0094f44b();
          }
          else if (uVar2 == 0x20200000) {
            iVar5 = FUN_00936f7f();
          }
          else if (uVar2 == 0x20300000) {
            iVar5 = FUN_00936ea3();
          }
          else if (uVar2 == 0x20400000) {
            iVar5 = FUN_0094f42d();
          }
          else if (uVar2 == 0x20500000) {
            iVar5 = FUN_0094f437();
          }
          else if (uVar2 == 0x20700000) {
            iVar5 = FUN_0094e448();
          }
          else {
            if (uVar2 != 0x30000000) goto LAB_00939127;
            iVar5 = FUN_0094f508();
          }
        }
        else {
          if (uVar2 != 0x50300000) {
            if (uVar2 != 0x60000000) {
              if (uVar2 == 0x60100000) goto LAB_00938fd8;
              if (uVar2 == 0x60200000) goto LAB_00939022;
              if (uVar2 == 0x60300000) goto LAB_00939016;
              if (uVar2 != 0x60400000) goto LAB_00939127;
              goto LAB_00938f6e;
            }
            goto LAB_0093902e;
          }
          iVar5 = FUN_0094e1a1();
        }
      }
      else {
        if (0x61300000 < uVar2) {
          if (uVar2 < 0x70b00001) {
            if (uVar2 == 0x70b00000) {
LAB_00938e4d:
              iVar5 = FUN_00937191();
            }
            else if (uVar2 == 0x70000000) {
              iVar5 = FUN_0094f51c();
            }
            else if (uVar2 == 0x70100000) {
              iVar5 = FUN_0094e9bf();
            }
            else if (uVar2 == 0x70200000) {
              iVar5 = FUN_0094eada();
            }
            else if ((uVar2 == 0x70300000) || (uVar2 == 0x70400000)) {
              iVar5 = FUN_0094eb80();
            }
            else {
              if (uVar2 != 0x70800000) goto LAB_00939127;
              iVar5 = FUN_0094e016();
            }
          }
          else if (uVar2 == 0x70c00000) {
LAB_009390e0:
            iVar5 = FUN_0093705b();
          }
          else if (uVar2 == 0x70d00000) {
            iVar5 = FUN_0094e94d();
          }
          else {
            if (((uVar2 != 0x73500000) && (uVar2 != 0x73600000)) &&
               ((uVar2 != 0x73700000 && (uVar2 != 0x73800000)))) goto LAB_00939127;
LAB_009390ce:
            iVar5 = FUN_0094e23f();
          }
          goto LAB_009390e9;
        }
        if (uVar2 == 0x61300000) {
LAB_00938f6e:
          if ((*(byte *)(in_ECX + 0x1c) & 0x20) == 0) {
LAB_00939113:
            FUN_0091a001();
            return 0;
          }
          iVar5 = FUN_0094dfb2();
        }
        else if (uVar2 < 0x60c00001) {
          if (uVar2 == 0x60c00000) {
LAB_00939022:
            iVar5 = FUN_0094dee4();
          }
          else {
            if (uVar2 != 0x60600000) {
              if (uVar2 == 0x60700000) goto LAB_00939022;
              if (uVar2 == 0x60800000) goto LAB_00939016;
              if (uVar2 == 0x60900000) goto LAB_00938f6e;
              if (uVar2 == 0x60a00000) goto LAB_0093902e;
              if (uVar2 != 0x60b00000) goto LAB_00939127;
            }
LAB_00938fd8:
            iVar5 = FUN_0094dcb5();
          }
        }
        else {
          if (uVar2 != 0x60d00000) {
            if (uVar2 == 0x60e00000) goto LAB_00938f6e;
            if (uVar2 == 0x60f00000) goto LAB_0093902e;
            if (uVar2 == 0x61000000) goto LAB_00938fd8;
            if (uVar2 == 0x61100000) goto LAB_00939022;
            if (uVar2 != 0x61200000) goto LAB_00939127;
          }
LAB_00939016:
          iVar5 = FUN_0094df4b();
        }
      }
LAB_009390e9:
      if (iVar5 == -0x7fffbfff) {
LAB_00939127:
        FUN_0091a001();
LAB_00939143:
        if (local_8 == 0) {
          return 0;
        }
LAB_0093914a:
        FUN_008f4adb(1);
        return 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < local_18);
  }
  return 0;
}


// ==== FUN_00939158 @ 0x00939158 ====

undefined4 FUN_00939158(uint *param_1,uint *param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *in_ECX;
  int *piVar7;
  uint uVar8;
  bool bVar9;
  uint auStack_b4 [18];
  uint auStack_6c [18];
  int local_24;
  uint local_20;
  int local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  if (param_1 == (uint *)0x0) {
    uVar5 = 1;
  }
  else {
    uVar8 = *param_1 & 0xfff00000;
    if ((uVar8 == 0) || (uVar8 == 0x20700000)) {
      uVar5 = 0;
    }
    else {
      local_8 = *param_1 & 0xfffff;
      local_20 = param_1[1] / local_8;
      if (1 < local_20) {
        iVar2 = in_ECX[0x20];
        iVar6 = in_ECX[0x22];
        iVar3 = in_ECX[0x1f];
        auStack_6c[iVar2] = 0;
        auStack_6c[iVar6] = 0;
        auStack_6c[iVar3] = 0;
        iVar4 = in_ECX[0x25];
        auStack_b4[iVar2] = 1;
        auStack_6c[iVar4] = 0;
        bVar9 = local_20 != 0;
        auStack_b4[iVar6] = 3;
        auStack_b4[iVar3] = 1;
        auStack_b4[iVar4] = 1;
        local_14 = 0;
        local_10 = 0;
        if (bVar9) {
          local_18 = local_8 << 2;
          local_1c = 0;
          do {
            iVar2 = *(int *)(in_ECX[5] + *(int *)(local_1c + param_1[2]) * 4);
            local_24 = *(int *)(in_ECX[4] + *(int *)(iVar2 + 4) * 4);
            uVar8 = *(uint *)(local_24 + 4);
            if ((uVar8 & 0x200) == 0) {
              if ((char)uVar8 < '\0') goto LAB_00939256;
              if (((uVar8 & 0x10) == 0) ||
                 (iVar6 = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(iVar2 + 0x6c)),
                 iVar6 == 0xffff)) {
                local_c = in_ECX[0x22];
              }
              else {
                local_c = in_ECX[0x20];
              }
            }
            else if ((char)uVar8 < '\0') {
LAB_00939256:
              local_c = in_ECX[0x25];
            }
            else {
              local_c = in_ECX[0x1f];
            }
            local_8 = 0;
            if (local_10 != 0) {
              piVar7 = (int *)param_1[2];
              do {
                iVar6 = *(int *)(in_ECX[5] + *piVar7 * 4);
                if (((*(int *)(iVar2 + 4) == *(int *)(iVar6 + 4)) &&
                    (*(int *)(iVar2 + 8) == *(int *)(iVar6 + 8))) &&
                   (*(int *)(iVar2 + 0xc) == *(int *)(iVar6 + 0xc))) break;
                local_8 = local_8 + 1;
                piVar7 = (int *)((int)piVar7 + local_18);
              } while (local_8 < local_10);
            }
            if ((local_8 == local_10) && (local_c < 0x12)) {
              puVar1 = auStack_6c + local_c;
              *puVar1 = *puVar1 + 1;
              if (auStack_b4[local_c] < *puVar1) goto LAB_00939320;
            }
            if (((*(byte *)(local_24 + 5) & 2) != 0) && (local_14 = local_14 + 1, 2 < local_14)) {
LAB_00939320:
              if (param_2 != (uint *)0x0) {
                *param_2 = local_10;
              }
              return 1;
            }
            local_1c = local_1c + local_18;
            local_10 = local_10 + 1;
          } while (local_10 < local_20);
        }
      }
      uVar5 = 0;
    }
  }
  return uVar5;
}


// ==== FUN_0093932d @ 0x0093932d ====

void FUN_0093932d(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_00948a8f();
  in_ECX[0x56] = param_1;
  *in_ECX = &PTR_FUN_00a2bb10;
  in_ECX[0x3c] = &PTR_s_Position_00b5a270;
  in_ECX[0x3d] = &PTR_s_Position_00b5a4b0;
  return;
}


// ==== FUN_00939364 @ 0x00939364 ====

undefined4 FUN_00939364(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 200);
  *(uint *)(in_ECX + 0x70) = *(uint *)(in_ECX + 0x70) | 0x40;
  uVar2 = *(uint *)(in_ECX + 0x70);
  *(int *)(in_ECX + 0x108) = iVar1;
  if (iVar1 == -0x1feff) {
    *(byte *)(in_ECX + 0x6f) = *(byte *)(in_ECX + 0x6f) | 1;
    *(undefined4 *)(in_ECX + 100) = 10;
    uVar2 = uVar2 | 0x2002;
  }
  else {
    if (iVar1 != -0x1fe00) {
      if (iVar1 == -0x1fdfe) {
        uVar2 = uVar2 | 4;
        *(uint *)(in_ECX + 0x6c) = *(uint *)(in_ECX + 0x6c) | 0x40200100;
        *(undefined4 *)(in_ECX + 0x2c) = 0xd;
        *(undefined4 *)(in_ECX + 0x30) = 1;
        *(undefined4 *)(in_ECX + 0x60) = 0x10;
        *(undefined4 *)(in_ECX + 0x40) = 0x10;
        *(undefined4 *)(in_ECX + 0x68) = 0xff;
        *(undefined4 *)(in_ECX + 100) = 1;
        *(undefined4 *)(in_ECX + 0x54) = 8;
        *(undefined4 *)(in_ECX + 0x58) = 0x18;
        *(undefined4 *)(in_ECX + 0x5c) = 1;
        *(undefined4 *)(in_ECX + 200) = 0xfffe0201;
      }
      else {
        if (iVar1 != -0x1fd01) {
          FUN_0091a001();
          return 0x80004005;
        }
        uVar2 = uVar2 | 4;
        *(uint *)(in_ECX + 0x6c) = *(uint *)(in_ECX + 0x6c) | 0x40200100;
        *(undefined4 *)(in_ECX + 0x2c) = 0x20;
        *(undefined4 *)(in_ECX + 0x30) = 1;
        *(undefined4 *)(in_ECX + 0x60) = 0x800;
        *(undefined4 *)(in_ECX + 0x40) = 0x800;
        *(undefined4 *)(in_ECX + 0x68) = 0xff;
        *(undefined4 *)(in_ECX + 100) = 1;
        *(undefined4 *)(in_ECX + 0x54) = 0x10;
        *(undefined4 *)(in_ECX + 0x58) = 0x18;
        *(undefined4 *)(in_ECX + 0x5c) = 4;
      }
      goto LAB_00939491;
    }
    uVar2 = uVar2 | 2;
    *(uint *)(in_ECX + 0x6c) = *(uint *)(in_ECX + 0x6c) | 0x200100;
    *(undefined4 *)(in_ECX + 0x30) = 1;
    *(undefined4 *)(in_ECX + 0x60) = 0x10;
    *(undefined4 *)(in_ECX + 0x40) = 0x10;
    *(undefined4 *)(in_ECX + 0x68) = 0xff;
    *(undefined4 *)(in_ECX + 100) = 1;
    *(undefined4 *)(in_ECX + 0x54) = 8;
    *(undefined4 *)(in_ECX + 0x5c) = 1;
  }
  *(undefined4 *)(in_ECX + 0x2c) = 0xc;
LAB_00939491:
  *(uint *)(in_ECX + 0x6c) = *(uint *)(in_ECX + 0x6c) | 0x40;
  *(uint *)(in_ECX + 0x70) = uVar2;
  *(byte *)(in_ECX + 0x71) = *(byte *)(in_ECX + 0x71) | 3;
  *(undefined4 *)(in_ECX + 0x1d0) = *(undefined4 *)(in_ECX + 0x2c);
  *(undefined4 *)(in_ECX + 0x28) = 0x10;
  *(undefined4 *)(in_ECX + 0x38) = 0x2000;
  *(undefined4 *)(in_ECX + 0x44) = 0x10;
  return 0;
}


// ==== FUN_009394b6 @ 0x009394b6 ====

uint FUN_009394b6(void)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  int local_2c [5];
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  uVar1 = 0;
  if (in_ECX[0x56] == 0) {
    local_2c[0] = 0;
    local_2c[1] = 0;
    local_2c[2] = 0;
    local_10 = 0;
    local_14 = 0;
    local_c = 0;
    local_18 = 0;
    local_2c[3] = 0;
    local_8 = 0;
    if (in_ECX[2] != 0) {
      do {
        iVar3 = *(int *)(in_ECX[5] + local_8 * 4);
        if ((*(byte *)(*(int *)(in_ECX[4] + *(int *)(iVar3 + 4) * 4) + 4) & 0x20) != 0) {
          local_2c[4] = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(iVar3 + 0x6c));
          iVar2 = (**(code **)(*in_ECX + 0x58))(*(undefined4 *)(iVar3 + 0x6c));
          if (local_2c[4] == 1) {
            if (iVar2 == 0) {
              local_2c[*(int *)(iVar3 + 0x10)] = 1;
              local_18 = *(undefined4 *)(iVar3 + 0x60);
            }
          }
          else if (local_2c[4] == 5) {
            if (((iVar2 == 0) && (*(int *)(iVar3 + 0x10) != 0)) && (local_14 == 0)) {
              FUN_0091a001();
              local_14 = 1;
              goto LAB_00939560;
            }
          }
          else if (((local_2c[4] == 0xc) && (iVar2 == 0)) &&
                  ((*(int *)(iVar3 + 0x10) != 0 && (local_10 == 0)))) {
            FUN_0091a001();
            local_10 = 1;
LAB_00939560:
            local_c = 1;
          }
        }
        local_8 = local_8 + 1;
      } while (local_8 < (uint)in_ECX[2]);
    }
    iVar3 = 0;
    uVar1 = 0;
    do {
      if (local_2c[uVar1] != 0) {
        iVar3 = iVar3 + 1;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < 4);
    if (iVar3 != 4) {
      FUN_0091a001();
      local_c = 1;
    }
    uVar1 = -(uint)(local_c != 0) & 0x80004005;
  }
  return uVar1;
}


// ==== FUN_009395f7 @ 0x009395f7 ====

undefined4 FUN_009395f7(int param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(param_1 + 0x6c));
  uVar2 = (**(code **)(*in_ECX + 0x58))(*(undefined4 *)(param_1 + 0x6c));
  *param_2 = uVar2;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (iVar1 == 1) {
    if (*param_2 == 0) {
      *param_3 = 4;
      *param_2 = 0;
      return 0;
    }
    return 0x80004005;
  }
  if (iVar1 == 5) {
    if (*param_2 != 0) {
      return 0x80004005;
    }
    *param_3 = 4;
    *param_2 = 2;
  }
  else {
    if (iVar1 != 0xc) {
      if (iVar1 == 0xb) {
        if (*param_2 < 2) {
          *param_3 = 5;
          return 0;
        }
        return 0x80004005;
      }
      if (iVar1 == 6) {
        if (*param_2 < 8) {
          *param_3 = 6;
          return 0;
        }
        return 0x80004005;
      }
      if (iVar1 == 0xffff) {
        *param_3 = 0;
        return 0;
      }
      return 0x80004005;
    }
    if (*param_2 != 0) {
      return 0x80004005;
    }
    *param_3 = 4;
    *param_2 = 1;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 1;
  }
  return 0;
}


// ==== FUN_009396b9 @ 0x009396b9 ====

undefined4 FUN_009396b9(int param_1,undefined4 *param_2,undefined4 *param_3)

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
    *param_3 = 1;
    uVar2 = *(undefined4 *)(param_1 + 0xc);
  }
  *param_2 = uVar2;
  return 0;
}


// ==== FUN_009396fc @ 0x009396fc ====

void FUN_009396fc(void)

{
  int in_ECX;
  
  *(uint *)(in_ECX + 0x154) = (uint)(0x100 < (*(uint *)(in_ECX + 200) & 0xffff));
  FUN_0094c8d4();
  return;
}


// ==== FUN_00939c35 @ 0x00939c35 ====

int FUN_00939c35(void)

{
  int iVar1;
  
  iVar1 = FUN_00948e39();
  if (-1 < iVar1) {
    iVar1 = FUN_0091ae30();
    if (-1 < iVar1) {
      iVar1 = FUN_0091c491();
      if (-1 < iVar1) {
        iVar1 = FUN_00915e19();
        if (-1 < iVar1) {
          FUN_0093e2c8();
          iVar1 = 0;
        }
      }
    }
  }
  return iVar1;
}


// ==== FUN_00939c6f @ 0x00939c6f ====

undefined4 FUN_00939c6f(void)

{
  uint *puVar1;
  int in_ECX;
  
  if (0x1ff < (*(uint *)(in_ECX + 200) & 0xffff)) {
    puVar1 = (uint *)(*(int *)(in_ECX + 0x10c) + *(int *)(in_ECX + 0x118) * 4);
    *puVar1 = *puVar1 | ((*(int *)(in_ECX + 0x110) - *(int *)(in_ECX + 0x118)) + -1) * 0x1000000;
  }
  return 0;
}


// ==== FUN_00939ca1 @ 0x00939ca1 ====

int FUN_00939ca1(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint *puVar5;
  int *in_ECX;
  int *piVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  int *piVar11;
  undefined4 *puVar12;
  bool bVar13;
  uint local_1c;
  int local_14;
  uint *local_10;
  int local_c;
  int *local_8;
  
  puVar5 = (uint *)in_ECX[0x40];
  uVar9 = *puVar5 & 0xfffff;
  if (uVar9 < 3) {
    return 0;
  }
  local_10 = puVar5;
  local_8 = in_ECX;
  puVar1 = (uint *)FUN_00947158(0x10000002,puVar5,0,2,1);
  if ((((puVar1 == (uint *)0x0) &&
       (puVar1 = (uint *)FUN_00947158(0x10000003,puVar5,0,2,1), puVar1 == (uint *)0x0)) &&
      (puVar1 = (uint *)FUN_00947158(0x10000004,puVar5,0,2,1), puVar1 == (uint *)0x0)) ||
     (local_c = local_8[5], *(int *)(*(int *)(local_c + *(int *)puVar1[4] * 4) + 4) != local_8[0x21]
     )) {
LAB_00939e55:
    if ((uVar9 == 3) && (0x1ff < (local_8[0x32] & 0xffffU))) {
      local_10 = (uint *)local_8[0x40];
      iVar2 = 3;
      bVar13 = true;
      piVar6 = (int *)local_10[2];
      piVar11 = (int *)local_10[2] + 3;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar13 = *piVar6 == *piVar11;
        piVar6 = piVar6 + 1;
        piVar11 = piVar11 + 1;
      } while (bVar13);
      if (((bVar13) &&
          (puVar4 = (undefined4 *)FUN_00947158(0x10700001,local_10,0,2,1),
          puVar4 != (undefined4 *)0x0)) &&
         ((puVar5 = (uint *)FUN_00947158(0x20500003,puVar4,&local_14,2,1), puVar5 != (uint *)0x0 ||
          (puVar5 = (uint *)FUN_00947158(0x20500004,puVar4,&local_14,2,1), puVar5 != (uint *)0x0))))
      {
        local_c = local_8[5];
        iVar2 = *(int *)(local_c + *(int *)local_10[2] * 4);
        iVar3 = *(int *)(local_c + *(int *)puVar5[4] * 4);
        uVar9 = *puVar5 & 0xfffff;
        iVar7 = 3;
        bVar13 = true;
        piVar6 = (int *)(puVar5[2] + uVar9 * 4);
        piVar11 = (int *)local_10[2];
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar13 = *piVar6 == *piVar11;
          piVar6 = piVar6 + 1;
          piVar11 = piVar11 + 1;
        } while (bVar13);
        if (bVar13) {
          uVar8 = 0;
          if (uVar9 != 0) {
            piVar6 = (int *)puVar5[4];
            do {
              if (*(uint *)(*(int *)(local_c + *piVar6 * 4) + 0x10) != uVar8) {
                return 0;
              }
              uVar8 = uVar8 + 1;
              piVar6 = piVar6 + 1;
            } while (uVar8 < uVar9);
          }
          if ((*(int *)(iVar2 + 4) != *(int *)(iVar3 + 4)) ||
             (*(int *)(iVar2 + 0xc) != *(int *)(iVar3 + 0xc))) {
            iVar2 = FUN_009149f7(0x74);
            if (iVar2 == 0) {
              local_c = 0;
            }
            else {
              local_c = FUN_0091455d();
            }
            iVar2 = local_c;
            if (local_c == 0) {
              return -0x7ff8fff2;
            }
            iVar3 = FUN_00914a42(uVar9 | 0x70200000,uVar9,uVar9,0);
            if (iVar3 < 0) {
              return iVar3;
            }
            iVar3 = FUN_00914593(puVar5);
            if (iVar3 < 0) {
              return iVar3;
            }
            puVar10 = (undefined4 *)puVar5[4];
            puVar12 = *(undefined4 **)(iVar2 + 0x10);
            for (uVar8 = uVar9; uVar8 != 0; uVar8 = uVar8 - 1) {
              *puVar12 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar12 = puVar12 + 1;
            }
            for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
              *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
              puVar10 = (undefined4 *)((int)puVar10 + 1);
              puVar12 = (undefined4 *)((int)puVar12 + 1);
            }
            puVar10 = (undefined4 *)(puVar5[2] + uVar9 * 4);
            puVar12 = *(undefined4 **)(local_c + 8);
            for (uVar8 = uVar9; uVar8 != 0; uVar8 = uVar8 - 1) {
              *puVar12 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar12 = puVar12 + 1;
            }
            for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
              *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
              puVar10 = (undefined4 *)((int)puVar10 + 1);
              puVar12 = (undefined4 *)((int)puVar12 + 1);
            }
            iVar2 = (**(code **)(*local_8 + 0x20))(local_c,0);
            if (iVar2 == 0) {
              *local_10 = 0;
              *puVar4 = 0;
              *puVar5 = 0;
              iVar2 = (**(code **)(*local_8 + 0x34))(local_c,local_14);
              if (iVar2 == 0) {
                if (*(int *)(local_8[6] + local_14 * 4) != 0) {
                  FUN_008f4adb(1);
                }
                *(int *)(local_8[6] + local_14 * 4) = local_c;
                return 0;
              }
              *local_10 = 0x50000003;
              *puVar4 = 0x10700001;
              *puVar5 = uVar9 | 0x20500000;
            }
            FUN_008f4adb(1);
          }
        }
      }
    }
  }
  else {
    local_1c = *puVar1 & 0xfffff;
    bVar13 = true;
    if (local_1c != 0) {
      local_14 = *(int *)puVar5[4];
      piVar6 = (int *)puVar1[2];
      do {
        if ((*piVar6 != local_14) ||
           ((*(uint *)(*(int *)(local_c + *piVar6 * 4) + 0x34) & 0x1ffe00) != 0)) {
          bVar13 = false;
        }
        piVar6 = piVar6 + 1;
        local_1c = local_1c - 1;
      } while (local_1c != 0);
      if (!bVar13) goto LAB_00939e55;
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
    iVar3 = FUN_00914a42(uVar9 | 0x50000000,puVar5[1],puVar1[3],0);
    iVar2 = local_c;
    if ((iVar3 < 0) || (iVar3 = FUN_00914593(puVar5), iVar3 < 0)) {
      FUN_008f4adb(1);
      return iVar3;
    }
    puVar4 = (undefined4 *)puVar1[4];
    puVar10 = *(undefined4 **)(iVar2 + 0x10);
    for (uVar9 = *(uint *)(iVar2 + 0xc) & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
      *puVar10 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar10 = puVar10 + 1;
    }
    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined1 *)puVar10 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    puVar4 = (undefined4 *)local_10[2];
    puVar10 = *(undefined4 **)(local_c + 8);
    for (uVar9 = *(uint *)(local_c + 4) & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
      *puVar10 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar10 = puVar10 + 1;
    }
    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined1 *)puVar10 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    *puVar1 = 0;
    if (local_8[0x40] != 0) {
      FUN_008f4adb(1);
    }
    *(int *)(local_8[6] + local_8[0x3f] * 4) = local_c;
    local_8[0x40] = local_c;
  }
  return 0;
}


// ==== FUN_0093a086 @ 0x0093a086 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_0093a086(int param_1,uint *param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  char *pcVar7;
  int extraout_EAX;
  int *in_ECX;
  int *piVar8;
  uint local_40;
  uint local_3c;
  uint *local_38;
  int local_34;
  char *local_30;
  uint local_2c;
  char local_28 [16];
  uint local_18 [5];
  
  local_18[4] = DAT_00b49670;
  local_38 = param_2;
  local_30 = (char *)(**(code **)(*in_ECX + 0x54))(*(undefined4 *)(param_1 + 0x6c));
  uVar4 = (**(code **)(*in_ECX + 0x58))(*(undefined4 *)(param_1 + 0x6c));
  if (in_ECX[0x56] != 0) {
    if (*(int *)(param_1 + 0x6c) == -1) {
      return 0;
    }
    if (local_30 != (char *)0xffff) {
      puVar5 = (undefined4 *)FUN_0094c864(local_30);
      __snprintf(local_28,0x20,s_v__s_d_00a29b60,*puVar5,uVar4);
      local_18[3] = local_18[3] & 0xffffff;
      iVar6 = FUN_00907c5b(local_28,*(undefined4 *)(param_1 + 0xc),1);
      if (iVar6 < 0) {
        return iVar6;
      }
      in_ECX[0x7c] = in_ECX[0x7c] + 1;
      if (((((*(byte *)(in_ECX + 0x33) & 1) != 0) && (iVar6 = *(int *)(param_1 + 0x60), iVar6 != 0))
          && (*(int *)(iVar6 + 4) == 6)) &&
         (iVar6 = *(int *)(iVar6 + 0x14), *(int *)(iVar6 + 4) == 3)) {
        pcVar7 = *(char **)(iVar6 + 0x18);
        pcVar1 = pcVar7 + 1;
        do {
          cVar2 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar2 != '\0');
        local_30 = operator_new((uint)(pcVar7 + (3 - (int)pcVar1)));
        if (local_30 == (char *)0x0) {
          return -0x7ff8fff2;
        }
        _sprintf(local_30,&DAT_00a29b50,*(undefined4 *)(iVar6 + 0x18));
        FUN_00907c5b(local_30,*(undefined4 *)(param_1 + 0xc),1);
        _free(local_30);
        return extraout_EAX;
      }
    }
    if (local_38 == (uint *)0x0) {
      return 0;
    }
    local_2c = *(uint *)(param_1 + 0x6c);
    goto LAB_0093a314;
  }
  switch(local_30) {
  case (char *)0x0:
    return 1;
  case (char *)0x1:
    local_2c = 0;
    break;
  case (char *)0x2:
    local_2c = 1;
    break;
  case (char *)0x3:
    local_2c = 2;
    break;
  case (char *)0x4:
    local_2c = 3;
    break;
  case (char *)0x5:
    local_2c = 4;
    break;
  case (char *)0x6:
    local_2c = 5;
    break;
  case (char *)0x7:
    local_2c = 6;
    break;
  case (char *)0x8:
    local_2c = 7;
    break;
  case (char *)0x9:
    local_2c = 8;
    if (uVar4 != 0) {
      return -0x7fffbffb;
    }
    goto LAB_0093a1e5;
  case (char *)0xa:
    local_2c = 9;
    break;
  case (char *)0xb:
    local_2c = 10;
    break;
  case (char *)0xc:
    local_2c = 0xb;
    break;
  case (char *)0xd:
    local_2c = 0xc;
    break;
  case (char *)0xe:
    local_2c = 0xd;
    break;
  default:
    goto LAB_0093a382;
  }
  if (0xf < uVar4) {
LAB_0093a382:
    return -0x7fffbffb;
  }
LAB_0093a1e5:
  local_2c = local_2c | (uVar4 | 0xffff8000) << 0x10;
  iVar6 = FUN_0094d495(0x1f);
  if (iVar6 < 0) {
    return iVar6;
  }
  iVar6 = FUN_0094b4db(local_2c);
  if (iVar6 < 0) {
    return iVar6;
  }
  if ((*(byte *)(in_ECX + 0x33) & 1) != 0) {
    local_34 = 0;
    local_30 = (char *)0x0;
    local_18[0] = 0xffffffff;
    local_18[1] = 0xffffffff;
    local_18[2] = 0xffffffff;
    local_18[3] = 0xffffffff;
    if (in_ECX[2] != 0) {
      iVar6 = *(int *)(param_1 + 4);
      piVar8 = (int *)in_ECX[5];
      do {
        iVar3 = *piVar8;
        if (((iVar6 == *(int *)(iVar3 + 4)) && (*(int *)(param_1 + 8) == *(int *)(iVar3 + 8))) &&
           (*(int *)(param_1 + 0xc) == *(int *)(iVar3 + 0xc))) {
          local_18[*(int *)(iVar3 + 0x10)] = (uint)local_30;
        }
        local_30 = (char *)((int)local_30 + 1);
        piVar8 = piVar8 + 1;
      } while (local_30 < (uint)in_ECX[2]);
    }
    uVar4 = 0;
    iVar6 = local_34;
    do {
      if (local_18[uVar4] != 0xffffffff) {
        local_18[iVar6] = local_18[uVar4];
        iVar6 = iVar6 + 1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 4);
    iVar6 = (**(code **)(*in_ECX + 0x70))(local_18,iVar6,&local_34,1);
    if (iVar6 < 0) {
      return iVar6;
    }
  }
  iVar6 = (**(code **)(*in_ECX + 0x88))(param_1,&local_3c,&local_40);
  if (iVar6 < 0) {
    return iVar6;
  }
  iVar6 = (**(code **)(*in_ECX + 100))
                    (((local_40 | 0xfffffff8) << 0x14 | local_40 & 0x18) << 8 | local_3c & 0x7ff,
                     0xf0000,0);
  if (iVar6 < 0) {
    return iVar6;
  }
  iVar6 = (**(code **)(*in_ECX + 0x60))();
  if (iVar6 < 0) {
    return iVar6;
  }
  iVar6 = FUN_00948616();
  if (iVar6 < 0) {
    return iVar6;
  }
  if (local_38 == (uint *)0x0) {
    return 0;
  }
LAB_0093a314:
  *local_38 = local_2c;
  return 0;
}


// ==== FUN_0093a40e @ 0x0093a40e ====

int FUN_0093a40e(void)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 local_30 [4];
  int local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_18 = 0;
  if (*(uint *)(in_ECX[0x40] + 4) < *(uint *)(in_ECX[0x40] + 0xc)) {
    iVar1 = (**(code **)(*in_ECX + 0x80))(in_ECX[0x3f],local_30,4,0,0);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_0094d663(0x4e,local_30 + 1,1,*(undefined4 *)(in_ECX[0x40] + 8),0,0,1,0,0,0,0);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = in_ECX[0x40];
    uVar3 = 0;
    if (*(int *)(iVar1 + 0xc) != 0) {
      do {
        local_30[uVar3] = local_30[1];
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(iVar1 + 0xc));
    }
    uVar6 = *(undefined4 *)(in_ECX[0x40] + 0xc);
    iVar1 = FUN_0094d663(1,*(undefined4 *)(in_ECX[0x40] + 0x10),uVar6,local_30,0,0,uVar6,0,0,0,0);
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  else {
    local_14 = 0;
    do {
      iVar1 = in_ECX[0x40];
      local_1c = *(uint *)(iVar1 + 0xc);
      local_8 = 0;
      if (local_1c != 0) {
        local_10 = 1;
        local_c = 2;
        do {
          iVar5 = local_8 * 4;
          piVar2 = (int *)(*(int *)(iVar1 + 0x10) + iVar5);
          local_20 = *(int *)(*(int *)(in_ECX[5] + *piVar2 * 4) + 0x10);
          if ((local_20 == 1) && (local_c < local_1c)) {
            if (local_14 == 1) {
              iVar1 = *(int *)(in_ECX[0x40] + 0x10);
              puVar4 = (undefined4 *)(*(int *)(in_ECX[0x40] + 8) + iVar5);
              uVar6 = 0x4e;
LAB_0093a5c5:
              iVar1 = FUN_0094d663(uVar6,iVar1 + iVar5,1,puVar4,0,0,1,0,0,0,0);
              if (iVar1 < 0) {
                return iVar1;
              }
            }
LAB_0093a5d4:
            local_8 = local_8 + 1;
            local_c = local_c + 1;
            local_10 = local_10 + 1;
          }
          else {
            if (local_1c <= local_10) {
              if (local_14 == 0) {
                if (local_18 == 0) {
                  iVar1 = (**(code **)(*in_ECX + 0x80))(in_ECX[0x3f],local_30,4,0,0);
                  if (iVar1 < 0) {
                    return iVar1;
                  }
                  local_18 = 1;
                }
                iVar1 = FUN_0094d663(0x4e,local_30 + 1,1,*(int *)(in_ECX[0x40] + 8) + iVar5,0,0,1,0,
                                     0,0,0);
                if (iVar1 < 0) {
                  return iVar1;
                }
                puVar4 = local_30 + 1;
                iVar1 = *(int *)(in_ECX[0x40] + 0x10);
                uVar6 = 1;
                goto LAB_0093a5c5;
              }
              goto LAB_0093a5d4;
            }
            if ((local_20 == 0) && (*(int *)(*(int *)(in_ECX[5] + piVar2[1] * 4) + 0x10) == 1)) {
              if (local_14 == 1) {
                iVar1 = *(int *)(in_ECX[0x40] + 0x10);
                puVar4 = (undefined4 *)(*(int *)(in_ECX[0x40] + 8) + iVar5);
                uVar6 = 0x13;
LAB_0093a694:
                iVar1 = FUN_0094d663(uVar6,iVar1 + iVar5,2,puVar4,0,0,2,0,0,0,0);
                if (iVar1 < 0) {
                  return iVar1;
                }
              }
            }
            else if (local_14 == 0) {
              if (local_18 == 0) {
                iVar1 = (**(code **)(*in_ECX + 0x80))(in_ECX[0x3f],local_30,4,0,0);
                if (iVar1 < 0) {
                  return iVar1;
                }
                local_18 = 1;
              }
              iVar1 = FUN_0094d663(0x13,local_30,2,*(int *)(in_ECX[0x40] + 8) + iVar5,0,0,2,0,0,0,0)
              ;
              if (iVar1 < 0) {
                return iVar1;
              }
              puVar4 = local_30;
              iVar1 = *(int *)(in_ECX[0x40] + 0x10);
              uVar6 = 1;
              goto LAB_0093a694;
            }
            local_c = local_c + 2;
            local_8 = local_8 + 2;
            local_10 = local_10 + 2;
          }
          iVar1 = in_ECX[0x40];
          local_1c = *(uint *)(iVar1 + 0xc);
        } while (local_8 < local_1c);
      }
      local_14 = local_14 + 1;
    } while (local_14 < 2);
  }
  return 0;
}


// ==== FUN_0093a6d4 @ 0x0093a6d4 ====

int FUN_0093a6d4(void)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 local_1c [4];
  int local_c;
  uint local_8;
  
  uVar4 = *(uint *)(in_ECX[0x40] + 0xc);
  local_8 = 0;
  if (uVar4 != 0) {
    piVar2 = *(int **)(in_ECX[0x40] + 0x10);
    do {
      if ((*(byte *)(*(int *)(in_ECX[5] + *piVar2 * 4) + 3) & 2) == 0) break;
      local_8 = local_8 + 1;
      piVar2 = piVar2 + 1;
    } while (local_8 < uVar4);
  }
  if (local_8 < uVar4) {
    iVar3 = in_ECX[0x40];
    uVar7 = *(undefined4 *)(iVar3 + 4);
    uVar11 = *(undefined4 *)(iVar3 + 0xc);
    uVar10 = *(undefined4 *)(iVar3 + 8);
    uVar9 = *(undefined4 *)(iVar3 + 0x10);
    uVar8 = 0xe;
  }
  else {
    iVar3 = in_ECX[0x40];
    if ((in_ECX[0x32] & 0xffffU) < 0x200) {
      local_c = 0;
      if (*(uint *)(iVar3 + 4) < *(uint *)(iVar3 + 0xc)) {
        iVar3 = (**(code **)(*in_ECX + 0x80))(in_ECX[0x3f],local_1c,4,0,0);
        if (iVar3 < 0) {
          return iVar3;
        }
        iVar3 = FUN_0094d663(0x4e,local_1c + 2,1,*(undefined4 *)(in_ECX[0x40] + 8),0,0,1,0,0,0,0);
        if (iVar3 < 0) {
          return iVar3;
        }
        iVar3 = in_ECX[0x40];
        uVar4 = 0;
        if (*(int *)(iVar3 + 0xc) != 0) {
          do {
            local_1c[uVar4] = local_1c[2];
            uVar4 = uVar4 + 1;
          } while (uVar4 < *(uint *)(iVar3 + 0xc));
        }
        uVar7 = *(undefined4 *)(in_ECX[0x40] + 0xc);
        iVar3 = FUN_0094d663(1,*(undefined4 *)(in_ECX[0x40] + 0x10),uVar7,local_1c,0,0,uVar7,0,0,0,0
                            );
        if (iVar3 < 0) {
          return iVar3;
        }
      }
      else {
        local_8 = 0;
        if (uVar4 != 0) {
          do {
            iVar6 = local_8 * 4;
            iVar3 = *(int *)(*(int *)(in_ECX[5] +
                                     *(int *)(iVar6 + *(int *)(in_ECX[0x40] + 0x10)) * 4) + 0x10);
            puVar1 = *(uint **)(in_ECX[5] + *(int *)(iVar6 + *(int *)(in_ECX[0x40] + 8)) * 4);
            if ((((iVar3 == 0) && ((*puVar1 & 2) != 0)) || (iVar3 == 2)) ||
               (((iVar3 == 3 && (uVar4 = *puVar1, (uVar4 & 4) != 0)) && ((uVar4 & 8) != 0)))) {
              iVar3 = *(int *)(in_ECX[0x40] + 0x10);
              puVar5 = (undefined4 *)(*(int *)(in_ECX[0x40] + 8) + iVar6);
              uVar7 = 0x4e;
            }
            else {
              if (local_c == 0) {
                iVar3 = (**(code **)(*in_ECX + 0x80))(in_ECX[0x3f],local_1c,4,0,0);
                if (iVar3 < 0) {
                  return iVar3;
                }
                local_c = 1;
              }
              iVar3 = FUN_0094d663(0x4e,local_1c + 2,1,*(int *)(in_ECX[0x40] + 8) + iVar6,0,0,1,0,0,
                                   0,0);
              if (iVar3 < 0) {
                return iVar3;
              }
              puVar5 = local_1c + 2;
              iVar3 = *(int *)(in_ECX[0x40] + 0x10);
              uVar7 = 1;
            }
            iVar3 = FUN_0094d663(uVar7,iVar3 + iVar6,1,puVar5,0,0,1,0,0,0,0);
            if (iVar3 < 0) {
              return iVar3;
            }
            local_8 = local_8 + 1;
          } while (local_8 < *(uint *)(in_ECX[0x40] + 0xc));
        }
      }
      return 0;
    }
    uVar7 = *(undefined4 *)(iVar3 + 4);
    uVar11 = *(undefined4 *)(iVar3 + 0xc);
    uVar10 = *(undefined4 *)(iVar3 + 8);
    uVar9 = *(undefined4 *)(iVar3 + 0x10);
    uVar8 = 0x4e;
  }
  iVar3 = FUN_0094ef49(uVar8,uVar9,uVar10,uVar11,uVar7,0,0);
  return iVar3;
}


// ==== FUN_0093a90b @ 0x0093a90b ====

int FUN_0093a90b(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 local_1c [4];
  int local_c;
  uint local_8;
  
  uVar3 = *(uint *)(in_ECX[0x40] + 0xc);
  local_8 = 0;
  if (uVar3 != 0) {
    piVar1 = *(int **)(in_ECX[0x40] + 0x10);
    do {
      if ((*(byte *)(*(int *)(in_ECX[5] + *piVar1 * 4) + 3) & 2) == 0) break;
      local_8 = local_8 + 1;
      piVar1 = piVar1 + 1;
    } while (local_8 < uVar3);
  }
  if (local_8 < uVar3) {
    iVar2 = in_ECX[0x40];
    uVar5 = *(undefined4 *)(iVar2 + 4);
    uVar9 = *(undefined4 *)(iVar2 + 0xc);
    uVar8 = *(undefined4 *)(iVar2 + 8);
    uVar7 = *(undefined4 *)(iVar2 + 0x10);
    uVar6 = 0xf;
  }
  else {
    iVar2 = in_ECX[0x40];
    if ((in_ECX[0x32] & 0xffffU) < 0x200) {
      local_c = 0;
      if (*(uint *)(iVar2 + 4) < *(uint *)(iVar2 + 0xc)) {
        iVar2 = (**(code **)(*in_ECX + 0x80))(in_ECX[0x3f],local_1c,4,0,0);
        if (iVar2 < 0) {
          return iVar2;
        }
        iVar2 = FUN_0094d663(0x4f,local_1c + 2,1,*(undefined4 *)(in_ECX[0x40] + 8),0,0,1,0,0,0,0);
        if (iVar2 < 0) {
          return iVar2;
        }
        iVar2 = in_ECX[0x40];
        uVar3 = 0;
        if (*(int *)(iVar2 + 0xc) != 0) {
          do {
            local_1c[uVar3] = local_1c[2];
            uVar3 = uVar3 + 1;
          } while (uVar3 < *(uint *)(iVar2 + 0xc));
        }
        uVar5 = *(undefined4 *)(in_ECX[0x40] + 0xc);
        iVar2 = FUN_0094d663(1,*(undefined4 *)(in_ECX[0x40] + 0x10),uVar5,local_1c,0,0,uVar5,0,0,0,0
                            );
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      else {
        local_8 = 0;
        if (uVar3 != 0) {
          do {
            iVar2 = local_8 * 4;
            if (*(int *)(*(int *)(in_ECX[5] + *(int *)(iVar2 + *(int *)(in_ECX[0x40] + 0x10)) * 4) +
                        0x10) == 2) {
              puVar4 = (undefined4 *)(*(int *)(in_ECX[0x40] + 8) + iVar2);
              iVar2 = *(int *)(in_ECX[0x40] + 0x10) + iVar2;
              uVar5 = 0x4f;
            }
            else {
              if (local_c == 0) {
                iVar2 = (**(code **)(*in_ECX + 0x80))(in_ECX[0x3f],local_1c,4,0,0);
                if (iVar2 < 0) {
                  return iVar2;
                }
                local_c = 1;
              }
              iVar2 = FUN_0094d663(0x4f,local_1c + 2,1,*(int *)(in_ECX[0x40] + 8) + local_8 * 4,0,0,
                                   1,0,0,0,0);
              if (iVar2 < 0) {
                return iVar2;
              }
              puVar4 = local_1c + 2;
              iVar2 = *(int *)(in_ECX[0x40] + 0x10) + local_8 * 4;
              uVar5 = 1;
            }
            iVar2 = FUN_0094d663(uVar5,iVar2,1,puVar4,0,0,1,0,0,0,0);
            if (iVar2 < 0) {
              return iVar2;
            }
            local_8 = local_8 + 1;
          } while (local_8 < *(uint *)(in_ECX[0x40] + 0xc));
        }
      }
      return 0;
    }
    uVar5 = *(undefined4 *)(iVar2 + 4);
    uVar9 = *(undefined4 *)(iVar2 + 0xc);
    uVar8 = *(undefined4 *)(iVar2 + 8);
    uVar7 = *(undefined4 *)(iVar2 + 0x10);
    uVar6 = 0x4f;
  }
  iVar2 = FUN_0094ef49(uVar6,uVar7,uVar8,uVar9,uVar5,0,0);
  return iVar2;
}


// ==== FUN_0093ab15 @ 0x0093ab15 ====

int FUN_0093ab15(int param_1)

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
    if ((iVar2 == -1) || (iVar2 = FUN_0093ab15(iVar2), -1 < iVar2)) {
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


// ==== FUN_0093ac18 @ 0x0093ac18 ====

void FUN_0093ac18(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a2bb10;
  FUN_00948b75();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0093ac3f @ 0x0093ac3f ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0093ac3f(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int aiStack_64 [4];
  uint local_54 [5];
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int *local_30;
  uint *local_2c;
  uint *local_28;
  int local_24;
  int *local_20;
  int *local_1c;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_14 = **(uint **)(in_ECX + 0x100) & 0xfffff;
  if (local_14 == 0) {
    return 1;
  }
  local_54[4] = (*(uint **)(in_ECX + 0x100))[1] / local_14;
  local_40 = 0;
  if (local_54[4] != 0) {
    local_34 = 0;
    local_24 = in_ECX;
    do {
      iVar9 = -1;
      local_54[0] = 0xffffffff;
      local_54[1] = 0xffffffff;
      local_54[2] = 0xffffffff;
      local_8 = 0;
      local_20 = (int *)0x0;
      local_1c = (int *)0x0;
      local_28 = (uint *)0x0;
      local_2c = (uint *)0x0;
      local_54[3] = 0xffffffff;
      local_10 = -1;
      local_c = -1;
      if (local_14 != 0) {
        local_30 = (int *)(*(int *)(*(int *)(in_ECX + 0x100) + 8) + local_34);
        local_3c = local_14;
        do {
          uVar3 = local_8;
          iVar10 = *local_30;
          iVar7 = *(int *)(*(int *)(in_ECX + 0x14) + iVar10 * 4);
          iVar1 = *(int *)(iVar7 + 0x10);
          if (iVar1 == 0) {
            if ((*(int *)(iVar7 + 0x48) != -1) && (local_20 == (int *)0x0)) {
              uVar6 = *(uint *)(iVar7 + 0x48);
              local_20 = *(int **)(*(int *)(in_ECX + 0x18) + uVar6 * 4);
LAB_0093ae0f:
              local_54[local_8] = uVar6;
              aiStack_64[uVar3] = iVar10;
              iVar10 = iVar9;
              goto LAB_0093ae1d;
            }
          }
          else if (iVar1 == 1) {
            if ((*(int *)(iVar7 + 0x48) != -1) && (local_1c == (int *)0x0)) {
              uVar6 = *(uint *)(iVar7 + 0x48);
              local_1c = *(int **)(*(int *)(in_ECX + 0x18) + uVar6 * 4);
              goto LAB_0093ae0f;
            }
          }
          else if (iVar1 == 2) {
            if (iVar9 == -1) {
              iVar9 = *(int *)(iVar7 + 0x48);
              local_54[local_8] = 0xffffffff;
              local_10 = iVar10;
              aiStack_64[uVar3] = iVar10;
              if (iVar9 != -1) {
                local_28 = *(uint **)(*(int *)(in_ECX + 0x18) + iVar9 * 4);
                if ((*local_28 & 0xfff00000) == 0x10000000) {
                  uVar6 = 0;
                  uVar3 = *local_28 & 0xfffff;
                  if (uVar3 != 0) {
                    piVar4 = (int *)local_28[4];
                    do {
                      if (*piVar4 == iVar10) {
                        local_10 = *(int *)(local_28[2] + uVar6 * 4);
                        iVar10 = local_10;
                        break;
                      }
                      uVar6 = uVar6 + 1;
                      piVar4 = piVar4 + 1;
                    } while (uVar6 < uVar3);
                  }
                }
                else {
                  local_28 = (uint *)0x0;
                }
              }
              goto LAB_0093ae1d;
            }
          }
          else if ((iVar1 == 3) && (local_c == -1)) {
            iVar7 = *(int *)(iVar7 + 0x48);
            local_54[local_8] = 0xffffffff;
            local_c = iVar10;
            aiStack_64[uVar3] = iVar10;
            iVar10 = iVar9;
            if (iVar7 != -1) {
              local_2c = *(uint **)(*(int *)(in_ECX + 0x18) + iVar7 * 4);
              if ((*local_2c & 0xfff00000) == 0x10000000) {
                uVar6 = 0;
                uVar3 = *local_2c & 0xfffff;
                if (uVar3 != 0) {
                  piVar4 = (int *)local_2c[4];
                  do {
                    if (*piVar4 == local_c) {
                      local_c = *(int *)(local_2c[2] + uVar6 * 4);
                      break;
                    }
                    uVar6 = uVar6 + 1;
                    piVar4 = piVar4 + 1;
                  } while (uVar6 < uVar3);
                  iVar10 = local_10;
                }
              }
              else {
                local_2c = (uint *)0x0;
              }
            }
LAB_0093ae1d:
            local_8 = local_8 + 1;
            iVar9 = iVar10;
          }
          local_30 = local_30 + 1;
          local_3c = local_3c - 1;
        } while (local_3c != 0);
      }
      if ((local_8 == local_14) && (1 < local_8)) {
        bVar2 = false;
        if (local_1c != (int *)0x0) {
          if (*local_1c != 0x20500001) goto LAB_0093ae96;
          if (((iVar9 != -1) && (iVar9 != *(int *)local_1c[2])) &&
             (iVar9 != ((int *)local_1c[2])[1])) {
            bVar2 = true;
          }
          if (local_c != -1) {
            if ((local_c != *(int *)local_1c[2]) && (local_c != ((int *)local_1c[2])[1])) {
              bVar2 = true;
            }
            if (iVar9 != -1) {
              piVar4 = (int *)local_1c[2];
              if (local_c == iVar9) {
                if (*piVar4 != piVar4[1]) goto LAB_0093ae96;
              }
              else if (*piVar4 == piVar4[1]) {
LAB_0093ae96:
                bVar2 = true;
              }
            }
          }
        }
        if (local_20 != (int *)0x0) {
          if (*local_20 != 0x10000001) goto LAB_0093affd;
          iVar9 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)local_20[2] * 4);
          if (((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar9 + 4) * 4) + 5) & 1) == 0
              ) || (*(double *)(iVar9 + 0x20) != _DAT_0099d0a0)) {
            bVar2 = true;
          }
        }
        if ((!bVar2) && (local_3c = 0, local_8 != 0)) {
          do {
            local_38 = local_54[local_3c];
            if (local_38 != 0xffffffff) {
              local_18 = 1;
              local_20 = (int *)local_14;
              if (local_14 != 0) {
                piVar4 = (int *)(*(int *)(*(int *)(in_ECX + 0x100) + 8) + local_34);
                local_30 = (int *)local_14;
                do {
                  iVar9 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar4 * 4);
                  if (*(uint *)(iVar9 + 0x50) < *(uint *)(in_ECX + 0xfc)) {
                    local_18 = 0;
                  }
                  if (local_38 < *(uint *)(iVar9 + 0x4c)) {
                    local_18 = 0;
                  }
                  if (((local_28 == (uint *)0x0) && (*(int *)(iVar9 + 0x10) == 2)) ||
                     ((local_2c == (uint *)0x0 && (*(int *)(iVar9 + 0x10) == 3)))) {
                    local_20 = (int *)((int)local_20 - 1);
                  }
                  else if (*(uint *)(iVar9 + 0x54) < local_38) {
                    local_18 = 0;
                  }
                  piVar4 = piVar4 + 1;
                  local_30 = (int *)((int)local_30 - 1);
                } while (local_30 != (int *)0x0);
              }
              piVar4 = local_20;
              local_30 = (int *)0x0;
              do {
                if (local_54[(int)local_30] != 0xffffffff) {
                  iVar9 = *(int *)(*(int *)(in_ECX + 0x18) + local_54[(int)local_30] * 4);
                  iVar10 = *(int *)(iVar9 + 4);
                  if (iVar10 != 0) {
                    piVar5 = *(int **)(iVar9 + 8);
                    do {
                      iVar9 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar5 * 4);
                      uVar3 = *(uint *)(iVar9 + 0x48);
                      if (((local_38 < uVar3) && (uVar3 != 0xffffffff)) ||
                         (*(uint *)(iVar9 + 0x50) < local_38)) {
                        local_18 = 0;
                      }
                      piVar5 = piVar5 + 1;
                      iVar10 = iVar10 + -1;
                    } while (iVar10 != 0);
                    in_ECX = local_24;
                  }
                }
                local_30 = (int *)((int)local_30 + 1);
              } while (local_30 < local_8);
              if (local_18 != 0) {
                local_3c = local_54[local_3c];
                if ((local_3c != 0xffffffff) && (1 < local_20)) {
                  iVar9 = FUN_009149f7(0x74);
                  if (iVar9 == 0) {
                    iVar9 = 0;
                  }
                  else {
                    iVar9 = FUN_0091455d();
                  }
                  if (iVar9 == 0) {
                    return -0x7ff8fff2;
                  }
                  iVar10 = FUN_00914a42((uint)piVar4 & 0xfffff | 0x70900000,(int)piVar4 * 2,piVar4,0
                                       );
                  if ((iVar10 < 0) ||
                     (iVar10 = FUN_00914593(*(undefined4 *)(in_ECX + 0x100)), iVar10 < 0))
                  goto LAB_0093b22a;
                  uVar3 = 0;
                  if (piVar4 == (int *)0x0) goto LAB_0093b0ee;
                  iVar10 = (int)piVar4 << 2;
                  goto LAB_0093b082;
                }
                break;
              }
            }
            local_3c = local_3c + 1;
          } while (local_3c < local_8);
        }
      }
LAB_0093affd:
      local_40 = local_40 + 1;
      local_34 = local_34 + local_14 * 4;
    } while (local_40 < local_54[4]);
  }
  return 1;
LAB_0093b082:
  do {
    if (local_1c == (int *)0x0) {
      if (local_c == -1) {
        iVar7 = local_10;
        if (local_10 != -1) goto LAB_0093b0d9;
      }
      else {
        iVar7 = local_c;
        if (local_10 == -1) {
LAB_0093b0d9:
          *(int *)(*(int *)(iVar9 + 8) + uVar3 * 4) = iVar7;
          goto LAB_0093b0df;
        }
      }
      uVar12 = 0x12d9;
      uVar11 = *(undefined4 *)(*(int *)(in_ECX + 0x100) + 0x3c);
      local_24 = in_ECX;
      goto LAB_0093b0c3;
    }
    *(undefined4 *)(*(int *)(iVar9 + 8) + uVar3 * 4) = *(undefined4 *)local_1c[2];
    iVar7 = *(int *)(local_1c[2] + 4);
LAB_0093b0df:
    *(int *)(iVar10 + *(int *)(iVar9 + 8)) = iVar7;
    uVar3 = uVar3 + 1;
    iVar10 = iVar10 + 4;
  } while (uVar3 < local_20);
LAB_0093b0ee:
  uVar3 = 0;
  uVar6 = 0;
  if (local_8 != 0) {
    do {
      iVar10 = *(int *)(*(int *)(in_ECX + 0x14) + aiStack_64[uVar3] * 4);
      if (((local_28 != (uint *)0x0) || (*(int *)(iVar10 + 0x10) != 2)) &&
         ((local_2c != (uint *)0x0 || (*(int *)(iVar10 + 0x10) != 3)))) {
        *(int *)(*(int *)(iVar9 + 0x10) + uVar6 * 4) = aiStack_64[uVar3];
        uVar6 = uVar6 + 1;
      }
      if (local_20 < uVar6) {
        uVar12 = 0x12da;
        uVar11 = *(undefined4 *)(*(int *)(local_24 + 0x100) + 0x3c);
LAB_0093b0c3:
        FUN_0091a001(local_24,uVar11,uVar12,s_internal_error__DST_test_failure_00a2bc44);
        iVar10 = 1;
LAB_0093b22a:
        FUN_008f4adb(1);
        return iVar10;
      }
      uVar3 = uVar3 + 1;
      in_ECX = local_24;
    } while (uVar3 < local_8);
  }
  uVar3 = *(uint *)(iVar9 + 0xc);
  local_14 = 0;
  if (uVar3 != 0) {
    local_40 = 1;
    do {
      local_34 = local_40;
      if (local_40 < uVar3) {
        do {
          iVar10 = *(int *)(*(int *)(in_ECX + 0x14) +
                           *(int *)(*(int *)(iVar9 + 0x10) + local_14 * 4) * 4);
          iVar7 = *(int *)(*(int *)(in_ECX + 0x14) +
                          *(int *)(local_34 * 4 + *(int *)(iVar9 + 0x10)) * 4);
          if (*(uint *)(iVar7 + 0x10) < *(uint *)(iVar10 + 0x10)) {
            puVar8 = (uint *)(local_34 * 4 + *(int *)(iVar9 + 0x10));
            local_54[4] = *puVar8;
            *puVar8 = *(uint *)(*(int *)(iVar9 + 0x10) + local_14 * 4);
            *(uint *)(*(int *)(iVar9 + 0x10) + local_14 * 4) = local_54[4];
            in_ECX = local_24;
          }
          if (*(int *)(iVar10 + 0x10) == *(int *)(iVar7 + 0x10)) {
            FUN_0091a001(in_ECX,*(undefined4 *)(*(int *)(in_ECX + 0x100) + 0x3c),0x12db,
                         s_internal_error__multiple_write_t_00a2bc14);
            iVar10 = -0x7fffbffb;
            goto LAB_0093b22a;
          }
          local_34 = local_34 + 1;
        } while (local_34 < *(uint *)(iVar9 + 0xc));
      }
      local_14 = local_14 + 1;
      uVar3 = *(uint *)(iVar9 + 0xc);
      local_40 = local_40 + 1;
    } while (local_14 < uVar3);
  }
  uVar3 = 0;
  if (local_8 != 0) {
    do {
      if (local_54[uVar3] != 0xffffffff) {
        **(undefined4 **)(*(int *)(in_ECX + 0x18) + local_54[uVar3] * 4) = 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < local_8);
  }
  if (local_28 != (uint *)0x0) {
    if (*local_28 == 0x10000001) {
      *local_28 = 0;
    }
    else if (*local_28 == 0x10000002) {
      piVar4 = (int *)local_28[2];
      if ((*piVar4 == local_10) && (piVar4[1] == local_c)) {
        *local_28 = 0;
      }
      if ((piVar4[1] == local_10) && (*piVar4 == local_c)) {
        *local_28 = 0;
      }
    }
  }
  if (local_2c == (uint *)0x0) goto LAB_0093b29d;
  if (*local_2c != 0x10000001) {
    if (*local_2c != 0x10000002) goto LAB_0093b29d;
    piVar4 = (int *)local_2c[2];
    if ((*piVar4 == local_10) && (piVar4[1] == local_c)) {
      *local_2c = 0;
    }
    if ((piVar4[1] != local_10) || (*piVar4 != local_c)) goto LAB_0093b29d;
  }
  *local_2c = 0;
LAB_0093b29d:
  iVar10 = local_3c * 4;
  if (*(int *)(iVar10 + *(int *)(in_ECX + 0x18)) != 0) {
    FUN_008f4adb(1);
  }
  *(int *)(iVar10 + *(int *)(in_ECX + 0x18)) = iVar9;
  return 0;
}


// ==== FUN_0093b2c1 @ 0x0093b2c1 ====

int FUN_0093b2c1(void)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  uint local_c;
  
  bVar2 = false;
  if ((*(int *)(in_ECX + 0x5c) != 0) &&
     (*(undefined4 *)(in_ECX + 0xfc) = 0, *(int *)(in_ECX + 0xc) != 0)) {
    do {
      puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0xfc) * 4);
      *(uint **)(in_ECX + 0x100) = puVar1;
      if ((*puVar1 & 0xfff00000) == 0x20800000) {
        iVar3 = FUN_0093e78d();
        if (iVar3 < 0) {
          return iVar3;
        }
        bVar2 = (bool)(bVar2 | iVar3 == 0);
      }
      *(int *)(in_ECX + 0xfc) = *(int *)(in_ECX + 0xfc) + 1;
    } while (*(uint *)(in_ECX + 0xfc) < *(uint *)(in_ECX + 0xc));
    if (bVar2) {
      FUN_0093e2c8();
    }
  }
  if ((*(byte *)(in_ECX + 0xcc) & 4) == 0) {
    uVar5 = 0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        *(uint *)(in_ECX + 0xfc) = uVar5;
        *(undefined4 *)(in_ECX + 0x100) = *(undefined4 *)(*(int *)(in_ECX + 0x18) + uVar5 * 4);
        iVar3 = FUN_0093ac3f();
        if (iVar3 == 0) {
          FUN_0093e2c8();
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(in_ECX + 0xc));
    }
    uVar5 = 0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        *(uint *)(in_ECX + 0xfc) = uVar5;
        puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar5 * 4);
        *(uint **)(in_ECX + 0x100) = puVar1;
        if (((*puVar1 & 0xfff00000) == 0x50000000) && (iVar3 = FUN_00939ca1(), iVar3 < 0)) {
          return iVar3;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(in_ECX + 0xc));
    }
    FUN_0093e2c8();
    uVar5 = 0;
    if (*(int *)(in_ECX + 0xc) != 0) {
      do {
        *(uint *)(in_ECX + 0xfc) = uVar5;
        puVar1 = *(uint **)(*(int *)(in_ECX + 0x18) + uVar5 * 4);
        *(uint **)(in_ECX + 0x100) = puVar1;
        uVar4 = *puVar1 & 0xfff00000;
        if (((((uVar4 == 0x10300000) || (uVar4 == 0x10500000)) || (uVar4 == 0x10600000)) ||
            ((uVar4 == 0x10700000 || (uVar4 == 0x50000000)))) && (iVar3 = FUN_00941be9(), iVar3 < 0)
           ) {
          return iVar3;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(in_ECX + 0xc));
    }
  }
  if (*(int *)(in_ECX + 0x30) != 0) {
    local_c = 0;
    do {
      if (0xf < local_c) goto LAB_0093b492;
      uVar5 = *(uint *)(in_ECX + 0xc);
      uVar4 = 0;
      bVar2 = true;
      if (uVar5 != 0) {
        do {
          *(undefined4 *)(in_ECX + 0x100) = *(undefined4 *)(*(int *)(in_ECX + 0x18) + uVar4 * 4);
          iVar3 = FUN_0093ec43();
          if (iVar3 < 0) {
            return iVar3;
          }
          if (iVar3 == 0) {
            bVar2 = false;
          }
          iVar3 = FUN_00915471(*(undefined4 *)(in_ECX + 0x100));
          if (iVar3 < 0) {
            return iVar3;
          }
          **(undefined4 **)(in_ECX + 0x100) = 0;
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar5);
      }
      iVar3 = FUN_00915e19();
      if (iVar3 < 0) {
        return iVar3;
      }
      local_c = local_c + 1;
    } while (!bVar2);
    if (0xf < local_c) {
LAB_0093b492:
      uVar5 = *(uint *)(in_ECX + 0xc);
      uVar4 = 0;
      bVar2 = true;
      if (uVar5 != 0) {
        do {
          *(undefined4 *)(in_ECX + 0x100) = *(undefined4 *)(*(int *)(in_ECX + 0x18) + uVar4 * 4);
          iVar3 = FUN_0093ec43();
          if (iVar3 < 0) {
            return iVar3;
          }
          if (iVar3 == 0) {
            FUN_0091a001();
            bVar2 = false;
          }
          iVar3 = FUN_00915471(*(undefined4 *)(in_ECX + 0x100));
          if (iVar3 < 0) {
            return iVar3;
          }
          **(undefined4 **)(in_ECX + 0x100) = 0;
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar5);
      }
      iVar3 = FUN_00915e19();
      if (iVar3 < 0) {
        return iVar3;
      }
      if (!bVar2) {
        return -0x7fffbffb;
      }
    }
  }
  if (*(int *)(in_ECX + 0x60) != 0) {
    iVar3 = FUN_0094b1b7();
    if (iVar3 < 0) {
      return iVar3;
    }
    FUN_0093e2c8();
    iVar3 = FUN_0091c491();
    if (iVar3 < 0) {
      return iVar3;
    }
  }
  return 0;
}


// ==== FUN_0093b53c @ 0x0093b53c ====

undefined4 FUN_0093b53c(uint *param_1,uint *param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int *in_ECX;
  uint uVar7;
  int *piVar8;
  bool bVar9;
  uint auStack_b0 [18];
  uint auStack_68 [18];
  int local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  if (param_1 == (uint *)0x0) {
    uVar4 = 1;
  }
  else {
    uVar7 = *param_1 & 0xfff00000;
    if ((uVar7 == 0) || (uVar7 == 0x20700000)) {
      uVar4 = 0;
    }
    else {
      uVar5 = *param_1 & 0xfffff;
      local_14 = param_1[1] / uVar5;
      if (((uVar7 == 0x70500000) || (uVar7 == 0x70600000)) || (uVar7 == 0x70700000)) {
        local_14 = 2;
      }
      if (1 < local_14) {
        iVar2 = in_ECX[0x20];
        iVar6 = in_ECX[0x22];
        iVar3 = in_ECX[0x1f];
        auStack_68[iVar2] = 0;
        auStack_68[iVar6] = 0;
        auStack_68[iVar3] = 0;
        auStack_b0[iVar2] = 1;
        bVar9 = local_14 != 0;
        auStack_b0[iVar6] = 3;
        auStack_b0[iVar3] = 1;
        local_18 = 0;
        local_10 = 0;
        if (bVar9) {
          local_1c = 0;
          local_20 = uVar5 << 2;
          do {
            iVar2 = *(int *)(in_ECX[5] + *(int *)(local_1c + param_1[2]) * 4);
            uVar7 = *(uint *)(*(int *)(in_ECX[4] + *(int *)(iVar2 + 4) * 4) + 4);
            if ((uVar7 & 0x200) == 0) {
              if ((char)uVar7 < '\0') goto LAB_0093b643;
              if (((uVar7 & 0x10) == 0) ||
                 (iVar6 = (**(code **)(*in_ECX + 0x54))(*(undefined4 *)(iVar2 + 0x6c)),
                 iVar6 == 0xffff)) {
                iVar6 = in_ECX[0x22];
              }
              else {
                iVar6 = in_ECX[0x20];
              }
            }
            else if ((char)uVar7 < '\0') {
LAB_0093b643:
              iVar6 = in_ECX[0x25];
            }
            else {
              iVar6 = in_ECX[0x1f];
            }
            local_c = 0;
            local_8 = iVar6;
            if (local_10 != 0) {
              piVar8 = (int *)param_1[2];
              do {
                iVar3 = *(int *)(in_ECX[5] + *piVar8 * 4);
                if (((*(int *)(iVar2 + 4) == *(int *)(iVar3 + 4)) &&
                    (*(int *)(iVar2 + 8) == *(int *)(iVar3 + 8))) &&
                   (*(int *)(iVar2 + 0xc) == *(int *)(iVar3 + 0xc))) break;
                local_c = local_c + 1;
                piVar8 = (int *)((int)piVar8 + local_20);
              } while (local_c < local_10);
            }
            if (local_c == local_10) {
              puVar1 = auStack_68 + iVar6;
              *puVar1 = *puVar1 + 1;
              if (auStack_b0[iVar6] < *puVar1) goto LAB_0093b714;
            }
            if (((0x1ff < (in_ECX[0x32] & 0xffffU)) && (in_ECX[0x1f] == local_8)) &&
               (local_18 = local_18 + 1, 2 < local_18)) {
LAB_0093b714:
              if (param_2 != (uint *)0x0) {
                *param_2 = local_10;
              }
              return 1;
            }
            local_10 = local_10 + 1;
            local_1c = local_1c + local_20;
          } while (local_10 < local_14);
        }
      }
      uVar4 = 0;
    }
  }
  return uVar4;
}


// ==== FUN_0093b722 @ 0x0093b722 ====

int FUN_0093b722(void)

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
        iVar3 = FUN_0093ab15(*(undefined4 *)(iVar1 + 8));
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


// ==== FUN_0093b745 @ 0x0093b745 ====

int FUN_0093b745(void)

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
        iVar2 = FUN_0093ab15(*(undefined4 *)(iVar2 + 8));
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


// ==== FUN_0093b77e @ 0x0093b77e ====

int FUN_0093b77e(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  undefined4 uVar4;
  
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
      iVar1 = FUN_0093b722();
      if (iVar1 < 0) {
        return iVar1;
      }
      uVar2 = **(uint **)(in_ECX + 0x100) & 0xfff00000;
      if (uVar2 < 0x70600001) {
        if (uVar2 == 0x70600000) {
LAB_0093b9f0:
          iVar1 = FUN_0094ecbe();
          goto LAB_0093bbba;
        }
        if (0x20300000 < uVar2) {
          if (uVar2 < 0x50300001) {
            if (uVar2 == 0x50300000) {
              iVar1 = FUN_0094e1a1();
            }
            else if (uVar2 == 0x20400000) {
              iVar1 = FUN_0094f42d();
            }
            else if (uVar2 == 0x20500000) {
              iVar1 = FUN_0094f437();
            }
            else if (uVar2 == 0x20700000) {
              iVar1 = FUN_0094e448();
            }
            else {
              if (uVar2 == 0x20800000) goto LAB_0093bbc1;
              if (uVar2 == 0x20900000) goto LAB_0093b91a;
              if (uVar2 == 0x50000000) {
                iVar1 = FUN_0094f44b();
              }
              else {
                if (uVar2 != 0x50100000) goto LAB_0093bbd1;
                iVar1 = FUN_0094f4fe();
              }
            }
          }
          else if (uVar2 == 0x70000000) {
            iVar1 = FUN_0094f51c();
          }
          else if (uVar2 == 0x70100000) {
            iVar1 = FUN_0094e9bf();
          }
          else if (uVar2 == 0x70200000) {
            iVar1 = FUN_0094eada();
          }
          else {
            if ((uVar2 != 0x70300000) && (uVar2 != 0x70400000)) {
              if (uVar2 != 0x70500000) goto LAB_0093bbd1;
              goto LAB_0093b9f0;
            }
            iVar1 = FUN_0094eb80();
          }
          goto LAB_0093bbba;
        }
        if (uVar2 == 0x20300000) {
          iVar1 = FUN_0094f423();
          goto LAB_0093bbba;
        }
        if (uVar2 < 0x10700001) {
          if (uVar2 == 0x10700000) {
            iVar1 = FUN_0094f3e7();
          }
          else if (uVar2 == 0) {
            iVar1 = FUN_00813a93();
          }
          else {
            if (uVar2 == 0x10000000) goto LAB_0093b91a;
            if (uVar2 == 0x10100000) {
              iVar1 = FUN_0094e840();
            }
            else if (uVar2 == 0x10300000) {
              iVar1 = FUN_0094f383();
            }
            else if (uVar2 == 0x10400000) {
              iVar1 = FUN_0094f3a1();
            }
            else if (uVar2 == 0x10500000) {
              iVar1 = FUN_0093a6d4();
            }
            else {
              if (uVar2 != 0x10600000) goto LAB_0093bbd1;
              iVar1 = FUN_0093a90b();
            }
          }
          goto LAB_0093bbba;
        }
        if (uVar2 == 0x10f00000) {
LAB_0093baf7:
          iVar1 = FUN_0094e23f();
          goto LAB_0093bbba;
        }
        if (uVar2 == 0x11200000) {
LAB_0093b91a:
          iVar1 = FUN_0094f236();
          goto LAB_0093bbba;
        }
        if (uVar2 != 0x11300000) {
          if (uVar2 != 0x11500000) {
            if (uVar2 == 0x20000000) {
              iVar1 = FUN_0094f405();
            }
            else if (uVar2 == 0x20100000) {
              iVar1 = FUN_0094f40f();
            }
            else {
              if (uVar2 != 0x20200000) goto LAB_0093bbd1;
              iVar1 = FUN_0094f419();
            }
            goto LAB_0093bbba;
          }
          goto LAB_0093b91a;
        }
      }
      else {
        if (uVar2 < 0x73a00001) {
          if (uVar2 == 0x73a00000) {
LAB_0093baeb:
            iVar1 = FUN_0094e617();
          }
          else if (uVar2 < 0x73300001) {
            if (uVar2 == 0x73300000) {
LAB_0093bb58:
              iVar1 = FUN_0094e7ec();
            }
            else {
              if (uVar2 == 0x70700000) goto LAB_0093b9f0;
              if (uVar2 == 0x70900000) {
                iVar1 = FUN_0094f441();
              }
              else if (uVar2 == 0x70d00000) {
                iVar1 = FUN_0094e94d();
              }
              else if (uVar2 == 0x71000000) {
                iVar1 = FUN_0093a40e();
              }
              else {
                if (uVar2 == 0x73000000) {
                  uVar4 = 0;
                }
                else {
                  if (uVar2 == 0x73100000) goto LAB_0093bb58;
                  if (uVar2 != 0x73200000) goto LAB_0093bbd1;
                  uVar4 = 1;
                }
                iVar1 = FUN_0094e772(uVar4);
              }
            }
          }
          else {
            if (uVar2 != 0x73400000) {
              if ((((uVar2 == 0x73500000) || (uVar2 == 0x73600000)) || (uVar2 == 0x73700000)) ||
                 (uVar2 == 0x73800000)) goto LAB_0093baf7;
              if (uVar2 != 0x73900000) goto LAB_0093bbd1;
              goto LAB_0093baeb;
            }
            iVar1 = FUN_0094e816();
          }
        }
        else if (uVar2 < 0x74200001) {
          if (uVar2 == 0x74200000) {
            iVar1 = FUN_0094f148();
          }
          else {
            if ((uVar2 == 0x73b00000) || (uVar2 == 0x73c00000)) goto LAB_0093baeb;
            if (((uVar2 == 0x73d00000) || (uVar2 == 0x73e00000)) ||
               ((uVar2 == 0x73f00000 || (uVar2 == 0x74000000)))) goto LAB_0093bb58;
            if (uVar2 != 0x74100000) goto LAB_0093bbd1;
            iVar1 = FUN_0094f1b2();
          }
        }
        else if ((((uVar2 == 0x74400000) || (uVar2 == 0x74500000)) || (uVar2 == 0x74600000)) ||
                (uVar2 == 0x74700000)) {
          if ((*(byte *)(in_ECX + 0x70) & 4) == 0) {
            iVar1 = -0x7fffbfff;
          }
          else {
            iVar1 = FUN_0094db0b();
          }
        }
        else if (uVar2 == 0x74a00000) {
          iVar1 = FUN_0094dae1();
        }
        else {
          if (uVar2 != 0x74b00000) goto LAB_0093bbd1;
          iVar1 = FUN_0094dab7();
        }
LAB_0093bbba:
        if (iVar1 == -0x7fffbfff) {
LAB_0093bbd1:
          FUN_0091a001();
          return -0x7fffbfff;
        }
      }
LAB_0093bbc1:
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 0xc));
  }
  return 0;
}


// ==== FUN_0093bbf4 @ 0x0093bbf4 ====

void FUN_0093bbf4(void)

{
  undefined4 *in_ECX;
  
  FUN_00948a8f();
  in_ECX[0x7e] = 0;
  *in_ECX = &PTR_FUN_00a2bc68;
  return;
}


// ==== FUN_0093bc0f @ 0x0093bc0f ====

undefined4 FUN_0093bc0f(void)

{
  int in_ECX;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  FUN_008f31ff(&DAT_00a25394,0,local_10);
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(byte *)(in_ECX + 0x71) = *(byte *)(in_ECX + 0x71) | 2;
  *(undefined4 *)(in_ECX + 0x108) = local_c;
  *(undefined4 *)(in_ECX + 0x28) = 0x40;
  *(undefined4 *)(in_ECX + 0x2c) = 0x40;
  *(uint *)(in_ECX + 0x6c) = *(uint *)(in_ECX + 0x6c) & 0xfffffefe | 0x80000202;
  *(undefined4 *)(in_ECX + 0x38) = 0x2000;
  return 0;
}


// ==== FUN_0093bc60 @ 0x0093bc60 ====

undefined4 FUN_0093bc60(void)

{
  return 1;
}


// ==== FUN_0093bc64 @ 0x0093bc64 ====

undefined4 FUN_0093bc64(int param_1)

{
  uint uVar1;
  int in_ECX;
  undefined4 uVar2;
  
  uVar1 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(param_1 + 4) * 4) + 4);
  if ((uVar1 & 0x100) == 0) {
    if (((uVar1 & 0x200) == 0) || (-1 < (char)uVar1)) {
      if ((uVar1 & 0x200) == 0) {
        if ((uVar1 & 0x10) == 0) {
          if ((uVar1 & 0x2020) == 0x2020) {
            uVar2 = 5;
          }
          else if ((uVar1 & 0x40020) == 0x40020) {
            uVar2 = 6;
          }
          else if ((uVar1 & 0x20) == 0) {
            if ((uVar1 & 1) == 0) {
              if (((uVar1 & 2) == 0) || ((uVar1 & 4) == 0)) goto LAB_0093bcf4;
              uVar2 = 8;
            }
            else {
              if ((uVar1 & 2) == 0) {
LAB_0093bcf4:
                if ((uVar1 & 0x10000) != 0) {
                  FUN_0091a001();
                }
                return 0x80004005;
              }
              uVar2 = 7;
            }
          }
          else {
            uVar2 = 4;
          }
          uVar2 = FUN_0094b4db(uVar2);
          return uVar2;
        }
        uVar2 = 3;
      }
      else {
        uVar2 = 2;
      }
    }
    else {
      uVar2 = 9;
    }
  }
  else {
    uVar2 = 1;
  }
  uVar2 = FUN_0094b4db(uVar2);
  return uVar2;
}


// ==== FUN_0093bd25 @ 0x0093bd25 ====

int FUN_0093bd25(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar3 = FUN_00947a51(2);
  if (-1 < iVar3) {
    iVar3 = *(int *)(in_ECX + 0x10c);
    piVar1 = (int *)(in_ECX + 0x110);
    iVar2 = *piVar1;
    *(undefined4 *)(iVar3 + iVar2 * 4) = param_1;
    *(undefined4 *)(iVar3 + 4 + iVar2 * 4) = param_2;
    *piVar1 = *piVar1 + 2;
    iVar3 = 0;
  }
  return iVar3;
}


// ==== FUN_0093bd5d @ 0x0093bd5d ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_0093bd5d(int param_1)

{
  uint uVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  long lVar5;
  uint uVar6;
  char *pcVar7;
  bool bVar8;
  bool bVar9;
  uint local_2c;
  char local_28 [31];
  undefined1 local_9;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  lVar5 = 0;
  local_2c = 0;
  if ((*(uint *)(in_ECX + 200) & 0xffff0000) == 0x46580000) {
    if (*(int *)(param_1 + 0x6c) == -1) {
      piVar3 = (int *)(in_ECX + 0x1f8);
      *(int *)(param_1 + 0x6c) = *piVar3;
      *piVar3 = *piVar3 + 1;
    }
    return 0;
  }
  if (*(int *)(param_1 + 0x6c) != -1) {
    return 0;
  }
  _strncpy(local_28,*(char **)(*(int *)(param_1 + 0x68) + 0x18),0x20);
  local_9 = 0;
  pcVar7 = local_28;
  if (local_28[0] == '\0') {
LAB_0093bdf5:
    if (*pcVar7 != '\0') {
      *pcVar7 = '\0';
      pcVar7 = pcVar7 + 1;
    }
  }
  else {
    do {
      iVar4 = _isalpha((int)*pcVar7);
      if (iVar4 == 0) break;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar7 != '\0');
    if (*pcVar7 != '\0') {
      lVar5 = _atol(pcVar7);
      goto LAB_0093bdf5;
    }
  }
  cVar2 = *pcVar7;
  if (cVar2 == '\0') {
LAB_0093be23:
    uVar6 = lVar5 + (*(uint *)(param_1 + 0x70) >> 2);
  }
  else {
    do {
      iVar4 = _isdigit((int)cVar2);
      if (iVar4 == 0) break;
      pcVar7 = pcVar7 + 1;
      cVar2 = *pcVar7;
    } while (cVar2 != '\0');
    if (*pcVar7 == '\0') goto LAB_0093be23;
    uVar6 = 0xffffffff;
  }
  uVar1 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(param_1 + 4) * 4) + 4);
  if (((uVar1 & 0x10) == 0) || ((uVar1 & 0x200) != 0)) {
    if ((uVar1 & 0x20) != 0) {
      iVar4 = __stricmp(local_28,s_color_00a27b04);
      bVar9 = iVar4 != 0;
      bVar8 = bVar9 || uVar6 != 0;
      local_2c = (uint)!bVar9;
      if ((bVar9 || uVar6 != 0) && (*(int *)(param_1 + 0x10) == 0)) {
        pcVar7 = s_invalid_reference_to_output_sema_00a2bd34;
        goto LAB_0093bede;
      }
      goto LAB_0093bef1;
    }
  }
  else {
    iVar4 = __stricmp(local_28,s_position_00a27b64);
    if (iVar4 == 0) {
      local_2c = 2;
LAB_0093be5e:
      bVar8 = uVar6 != 0;
    }
    else {
      iVar4 = __stricmp(local_28,s_psize_00a27b38);
      if (iVar4 == 0) {
        local_2c = 3;
        goto LAB_0093be5e;
      }
      local_2c = 0;
      bVar8 = true;
    }
    if ((bVar8) && (*(int *)(param_1 + 0x10) == 0)) {
      pcVar7 = s_invalid_reference_to_input_seman_00a2b6f8;
LAB_0093bede:
      FUN_0091a001(in_ECX,*(undefined4 *)(param_1 + 0x68),0x1196,pcVar7,local_28,uVar6);
    }
LAB_0093bef1:
    if (local_2c != 0) goto LAB_0093befe;
  }
  bVar8 = true;
LAB_0093befe:
  if (0xffff < uVar6) {
    bVar8 = true;
  }
  *(uint *)(param_1 + 0x6c) = (uVar6 | 0xffffff00) << 8 | local_2c;
  return -(uint)bVar8 & 0x80004005;
}


// ==== FUN_0093bf36 @ 0x0093bf36 ====

void FUN_0093bf36(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a2bc68;
  FUN_00948b75();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0093bf5d @ 0x0093bf5d ====

undefined4 FUN_0093bf5d(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + param_1 * 4);
  if ((((*(int *)(iVar3 + 8) == -1) ||
       (iVar2 = FUN_0093bf5d(*(int *)(iVar3 + 8),param_2), -1 < iVar2)) &&
      (iVar2 = FUN_0093bc64(iVar3), -1 < iVar2)) &&
     (iVar3 = FUN_0094b4db(*(int *)(iVar3 + 0x10) + *(int *)(iVar3 + 0xc) * 4), -1 < iVar3)) {
    piVar1 = (int *)(*(int *)(in_ECX + 0x10c) + param_2 * 4);
    *piVar1 = *piVar1 + 1;
    return 0;
  }
  return 0x8007000e;
}


// ==== FUN_0093bfc4 @ 0x0093bfc4 ====

undefined4 FUN_0093bfc4(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 *puVar5;
  undefined4 extraout_EAX_01;
  int in_ECX;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  undefined4 *puVar10;
  bool bVar11;
  undefined4 uVar12;
  undefined4 auStack_98 [4];
  int *local_88;
  uint local_84 [5];
  int local_70 [13];
  int *local_3c;
  int local_38;
  uint local_34;
  undefined4 *local_30;
  int *local_2c;
  uint local_28;
  int local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  int local_c;
  int *local_8;
  
  local_30 = (undefined4 *)0x0;
  local_70[10] = 0;
  local_70[0xb] = 0;
  local_70[0xc] = 0;
  local_70[3] = 0;
  local_70[4] = 0;
  local_70[5] = 0;
  if (*(int *)(in_ECX + 0xc) == 0) {
    return 1;
  }
  local_c = FUN_00928307(param_1);
  if (-1 < local_c) {
    local_c = FUN_0093dc46(*(undefined4 *)(in_ECX + 0x7c),*(undefined4 *)(in_ECX + 0x38),0x200,
                           0x42080,99);
    if (-1 < local_c) {
      local_28 = 0;
      local_1c = (int *)0x0;
      local_70[6] = 0xffffffff;
      local_70[7] = 0xffffffff;
      local_70[8] = 0xffffffff;
      local_70[9] = 0xffffffff;
      local_84[0] = 0;
      local_84[1] = 0;
      local_84[2] = 0;
      local_84[3] = 0;
      if (*(int **)(in_ECX + 8) != (int *)0x0) {
        piVar9 = *(int **)(in_ECX + 0x14);
        local_14 = *(int **)(in_ECX + 8);
        do {
          iVar8 = *piVar9;
          iVar2 = *(int *)(iVar8 + 4);
          if ((*(int *)(in_ECX + 0x78) == iVar2) &&
             (uVar6 = *(int *)(iVar8 + 0xc) + 1, local_28 < uVar6)) {
            local_28 = uVar6;
          }
          else if ((*(int *)(in_ECX + 0x88) == iVar2) &&
                  (piVar4 = (int *)(*(int *)(iVar8 + 0xc) + 1), local_1c < piVar4)) {
            local_1c = piVar4;
          }
          if (*(int *)(in_ECX + 0x84) == iVar2) {
            if (local_84[0] < *(uint *)(iVar8 + 0xc)) {
              local_84[0] = *(uint *)(iVar8 + 0xc);
            }
            if ((*(int *)(in_ECX + 0x84) == iVar2) && (*(uint *)(iVar8 + 0xc) < (uint)local_70[6]))
            {
              local_70[6] = *(uint *)(iVar8 + 0xc);
            }
          }
          if (*(int *)(in_ECX + 0xb4) == iVar2) {
            if (local_84[1] < *(uint *)(iVar8 + 0xc)) {
              local_84[1] = *(uint *)(iVar8 + 0xc);
            }
            if ((*(int *)(in_ECX + 0xb4) == iVar2) && (*(uint *)(iVar8 + 0xc) < (uint)local_70[7]))
            {
              local_70[7] = *(uint *)(iVar8 + 0xc);
            }
          }
          if (*(int *)(in_ECX + 0xb8) == iVar2) {
            if (local_84[2] < *(uint *)(iVar8 + 0xc)) {
              local_84[2] = *(uint *)(iVar8 + 0xc);
            }
            if ((*(int *)(in_ECX + 0xb8) == iVar2) && (*(uint *)(iVar8 + 0xc) < (uint)local_70[8]))
            {
              local_70[8] = *(uint *)(iVar8 + 0xc);
            }
          }
          piVar9 = piVar9 + 1;
          local_14 = (int *)((int)local_14 + -1);
        } while (local_14 != (int *)0x0);
      }
      uVar6 = local_28;
      local_20 = (int *)0x0;
      local_70[0] = *(int *)(in_ECX + 0x84);
      local_70[1] = *(int *)(in_ECX + 0xb4);
      local_70[2] = *(undefined4 *)(in_ECX + 0xb8);
      do {
        if (*(int *)((int)(local_70 + 6) + (int)local_20) != -1) {
          uVar6 = (*(int *)((int)local_84 + (int)local_20) -
                  *(int *)((int)(local_70 + 6) + (int)local_20)) + 1;
          local_8 = operator_new(uVar6);
          if (local_8 != (int *)0x0) {
            piVar9 = local_8;
            for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
              *piVar9 = 0;
              piVar9 = piVar9 + 1;
            }
            for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
              *(undefined1 *)piVar9 = 0;
              piVar9 = (int *)((int)piVar9 + 1);
            }
            uVar7 = 0;
            if (*(int *)(in_ECX + 8) != 0) {
              iVar8 = *(int *)((int)local_70 + (int)local_20);
              do {
                iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + uVar7 * 4);
                if (iVar8 == *(int *)(iVar2 + 4)) {
                  *(undefined1 *)
                   ((*(int *)(iVar2 + 0xc) - *(int *)((int)(local_70 + 6) + (int)local_20)) +
                   (int)local_8) = 1;
                }
                uVar7 = uVar7 + 1;
              } while (uVar7 < *(uint *)(in_ECX + 8));
            }
            uVar7 = 0;
            local_10 = (int *)0x0;
            if (uVar6 != 0) {
              do {
                if (uVar7 < uVar6) goto LAB_0093c1a2;
                do {
                  local_10 = (int *)((int)local_10 + 1);
                  for (; (uVar7 < uVar6 && (*(char *)(uVar7 + (int)local_8) != '\0'));
                      uVar7 = uVar7 + 1) {
                  }
                  uVar7 = uVar7 + 1;
                  if (uVar6 <= uVar7) goto LAB_0093c1c2;
LAB_0093c1a2:
                } while (*(char *)(uVar7 + (int)local_8) != '\0');
                uVar7 = uVar7 + 1;
              } while( true );
            }
LAB_0093c1c2:
            piVar4 = operator_new((int)local_10 << 3);
            piVar9 = local_20;
            *(int **)((int)(local_70 + 3) + (int)local_20) = piVar4;
            if (piVar4 == (int *)0x0) {
              _free(local_8);
              return extraout_EAX_00;
            }
            uVar7 = 0;
            if (uVar6 == 0) {
LAB_0093c222:
              _free(local_8);
              return extraout_EAX;
            }
            do {
              if (uVar7 < uVar6) goto LAB_0093c1e6;
              do {
                *piVar4 = *(int *)((int)(local_70 + 6) + (int)piVar9) + uVar7;
                for (; (uVar7 < uVar6 && (*(char *)(uVar7 + (int)local_8) != '\0'));
                    uVar7 = uVar7 + 1) {
                }
                piVar4[1] = (*(int *)((int)(local_70 + 6) + (int)piVar9) - *piVar4) + uVar7;
                piVar4 = piVar4 + 2;
                uVar7 = uVar7 + 1;
                if (uVar6 <= uVar7) goto LAB_0093c222;
LAB_0093c1e6:
              } while (*(char *)(uVar7 + (int)local_8) != '\0');
              uVar7 = uVar7 + 1;
            } while( true );
          }
          goto LAB_0093c2e7;
        }
        local_20 = local_20 + 1;
      } while (local_20 < (int *)0xc);
      local_30 = operator_new(local_28 << 5);
      if (local_30 == (undefined4 *)0x0) {
LAB_0093c2e7:
        local_c = -0x7ff8fff2;
      }
      else if (local_1c < (int *)0x41) {
        puVar10 = local_30;
        for (iVar8 = (uVar6 & 0x7ffffff) << 3; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar10 = 0;
          puVar10 = puVar10 + 1;
        }
        for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
          *(undefined1 *)puVar10 = 0;
          puVar10 = (undefined4 *)((int)puVar10 + 1);
        }
        uVar6 = 0;
        if (*(int *)(in_ECX + 8) != 0) {
          do {
            iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
            if ((*(int *)(in_ECX + 0x78) == *(int *)(iVar8 + 4)) && (*(int *)(iVar8 + 8) == -1)) {
              *(undefined8 *)(local_30 + (*(int *)(iVar8 + 0x10) + *(int *)(iVar8 + 0xc) * 4) * 2) =
                   *(undefined8 *)(iVar8 + 0x20);
            }
            if (*(int *)(in_ECX + 200) == 0x54580100) {
              if (*(int *)(in_ECX + 0x80) == *(int *)(iVar8 + 4)) {
                if (*(uint *)(iVar8 + 0xc) < 2) {
                  uVar7 = *(uint *)(iVar8 + 0x6c) & 0xff;
                  if (uVar7 == 2) {
                    *(undefined4 *)(iVar8 + 0xc) = 0;
                  }
                  else if (uVar7 == 3) {
                    *(undefined4 *)(iVar8 + 0xc) = 1;
                  }
                  goto LAB_0093c2ff;
                }
              }
              else {
LAB_0093c2ff:
                if ((*(int *)(in_ECX + 0x84) != *(int *)(iVar8 + 4)) || (*(int *)(iVar8 + 0xc) == 0)
                   ) goto LAB_0093c310;
              }
              FUN_0091a001();
              goto LAB_0093cc34;
            }
LAB_0093c310:
            uVar6 = uVar6 + 1;
          } while (uVar6 < *(uint *)(in_ECX + 8));
        }
        local_3c = *(int **)(in_ECX + 0xc);
        local_1c = (int *)0x0;
        if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
          do {
            puVar3 = *(uint **)(*(int *)(in_ECX + 0x18) + (int)local_1c * 4);
            local_24 = 0;
            puVar3[10] = 0;
            local_34 = *puVar3 & 0xfff00000;
            piVar9 = (int *)(*puVar3 & 0xfffff);
            if (piVar9 == (int *)0x0) {
LAB_0093c5e4:
              FUN_00915471();
            }
            else {
              local_10 = (int *)0x0;
              local_20 = (int *)(puVar3[1] / (uint)piVar9);
              piVar4 = (int *)puVar3[4];
              local_84[4] = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar4 * 4) + 0x10);
              if ((int *)(puVar3[1] / (uint)piVar9) != (int *)0x0) {
                local_8 = (int *)puVar3[2];
                do {
                  piVar1 = local_70 + (int)local_10;
                  local_10 = (int *)((int)local_10 + 1);
                  *piVar1 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *local_8 * 4) + 0x10);
                  local_8 = local_8 + (int)piVar9;
                } while (local_10 < local_20);
              }
              if ((piVar9 == (int *)puVar3[3]) && ((int *)0x1 < piVar9)) {
                local_10 = (int *)(local_84[4] + 1);
                local_14 = (int *)((int)piVar9 + -1);
                do {
                  piVar4 = piVar4 + 1;
                  if (*(int **)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar4 * 4) + 0x10) == local_10)
                  {
                    local_84[4] = local_84[4] + 1;
                    local_10 = (int *)((int)local_10 + 1);
                  }
                  else {
                    local_24 = 1;
                  }
                  local_14 = (int *)((int)local_14 + -1);
                } while (local_14 != (int *)0x0);
              }
              if ((local_20 == (int *)0x2) && (local_24 == 0)) {
                local_8 = (int *)(local_70[1] + 1);
                local_c = 1;
                if ((int *)0x1 < piVar9) {
                  piVar4 = (int *)puVar3[2];
                  local_38 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar4 * 4) + 0x10);
                  local_88 = piVar4 + 1;
                  local_2c = piVar4 + (int)piVar9 + 1;
                  local_18 = (int *)((int)piVar9 + -1);
                  local_14 = local_2c;
                  local_10 = local_88;
                  do {
                    if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *local_10 * 4) + 0x10) !=
                        local_38) {
                      local_c = 0;
                    }
                    if (*(int **)(*(int *)(*(int *)(in_ECX + 0x14) + *local_14 * 4) + 0x10) ==
                        local_8) {
                      local_8 = (int *)((int)local_8 + 1);
                    }
                    else {
                      local_c = 0;
                    }
                    local_10 = local_10 + 1;
                    local_14 = local_14 + 1;
                    local_18 = (int *)((int)local_18 + -1);
                  } while (local_18 != (int *)0x0);
                  local_18 = (int *)0x0;
                  if (local_c == 0) {
                    local_8 = (int *)(local_70[0] + 1);
                    local_38 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + piVar4[(int)piVar9] * 4)
                                       + 0x10);
                    local_18 = (int *)((int)piVar9 + -1);
                    local_c = 1;
                    local_14 = local_2c;
                    local_10 = local_88;
                    do {
                      if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *local_14 * 4) + 0x10) !=
                          local_38) {
                        local_c = 0;
                      }
                      if (*(int **)(*(int *)(*(int *)(in_ECX + 0x14) + *local_10 * 4) + 0x10) ==
                          local_8) {
                        local_8 = (int *)((int)local_8 + 1);
                      }
                      else {
                        local_c = 0;
                      }
                      local_14 = local_14 + 1;
                      local_10 = local_10 + 1;
                      local_18 = (int *)((int)local_18 + -1);
                    } while (local_18 != (int *)0x0);
                    if (local_c == 0) goto LAB_0093c568;
                    local_10 = (int *)0x0;
                    if (piVar9 != (int *)0x0) {
                      local_18 = (int *)((int)piVar9 << 2);
                      do {
                        piVar4 = (int *)((int)local_10 + 1);
                        puVar10 = (undefined4 *)(puVar3[2] + (int)local_10 * 4);
                        local_2c = (int *)*puVar10;
                        *puVar10 = *(undefined4 *)((int)local_18 + puVar3[2]);
                        *(int **)((int)local_18 + puVar3[2]) = local_2c;
                        local_18 = local_18 + 1;
                        local_10 = piVar4;
                      } while (piVar4 < piVar9);
                    }
                  }
                }
                puVar3[10] = 1;
                goto LAB_0093c5e4;
              }
LAB_0093c568:
              local_8 = (int *)0x1;
              if ((int *)0x1 < piVar9) {
                do {
                  local_10 = (int *)0x0;
                  if (local_20 != (int *)0x0) {
                    local_14 = (int *)(puVar3[2] + (int)local_8 * 4);
                    do {
                      local_2c = (int *)(local_70[(int)local_10] + 1);
                      if (*(int **)(*(int *)(*(int *)(in_ECX + 0x14) + *local_14 * 4) + 0x10) ==
                          local_2c) {
                        local_70[(int)local_10] = (int)local_2c;
                      }
                      else {
                        local_24 = 1;
                      }
                      local_10 = (int *)((int)local_10 + 1);
                      local_14 = local_14 + (int)piVar9;
                    } while (local_10 < local_20);
                  }
                  local_8 = (int *)((int)local_8 + 1);
                } while (local_8 < piVar9);
              }
              if (local_24 == 0) goto LAB_0093c5e4;
              if (local_34 == 0x50000000) {
                *puVar3 = 0x70e00001;
                goto LAB_0093c5e4;
              }
              if (local_34 == 0x50300000) {
                local_8 = (int *)0x0;
                if (piVar9 != (int *)0x0) {
                  do {
                    if (*(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                         *(int *)(puVar3[4] + (int)local_8 * 4) * 4) + 0x5c) != 0) {
                      if (local_8 == (int *)0x0) {
                        uVar12 = 0x10900001;
                      }
                      else {
                        uVar12 = 0x10800001;
                      }
                      iVar8 = FUN_00915378(uVar12,1,1);
                      if (iVar8 == -1) goto LAB_0093c2e7;
                      local_18 = *(int **)(*(int *)(in_ECX + 0x18) + iVar8 * 4);
                      local_c = FUN_00914593();
                      if (local_c < 0) goto LAB_0093cc34;
                      *(undefined4 *)local_18[4] = *(undefined4 *)(puVar3[4] + (int)local_8 * 4);
                      *(undefined4 *)local_18[2] = *(undefined4 *)(puVar3[2] + (int)local_8 * 4);
                    }
                    local_8 = (int *)((int)local_8 + 1);
                  } while (local_8 < piVar9);
                }
              }
              else {
                local_10 = (int *)0x0;
                if (piVar9 != (int *)0x0) {
                  do {
                    iVar8 = FUN_009149f7();
                    if (iVar8 == 0) {
                      local_8 = (int *)0x0;
                    }
                    else {
                      local_8 = (int *)FUN_0091455d();
                    }
                    bVar11 = local_8 == (int *)0x0;
                    auStack_98[(int)local_10] = local_8;
                    if (bVar11) goto LAB_0093c2e7;
                    local_c = FUN_00914a42(local_34 | 1,local_20,1,0);
                    if ((local_c < 0) || (local_c = FUN_00914593(), local_c < 0)) goto LAB_0093cc34;
                    local_18 = (int *)0x0;
                    *(undefined4 *)local_8[4] = *(undefined4 *)((int)local_10 * 4 + puVar3[4]);
                    if (local_20 != (int *)0x0) {
                      local_14 = (int *)((int)local_10 * 4);
                      do {
                        *(undefined4 *)(local_8[2] + (int)local_18 * 4) =
                             *(undefined4 *)((int)local_14 + puVar3[2]);
                        local_14 = local_14 + (int)piVar9;
                        local_18 = (int *)((int)local_18 + 1);
                      } while (local_18 < local_20);
                    }
                    FUN_00915471();
                    FUN_008f4adb();
                    local_10 = (int *)((int)local_10 + 1);
                  } while (local_10 < piVar9);
                }
              }
            }
            *puVar3 = 0;
            local_1c = (int *)((int)local_1c + 1);
          } while (local_1c < local_3c);
        }
        FUN_00915e19();
        local_c = FUN_0094b4db();
        iVar8 = local_70[10];
        if (-1 < local_c) {
          if (*(int *)(in_ECX + 200) == 0x46580201) {
            FUN_0094b4db();
            local_c = FUN_0094b4db();
            if (local_c < 0) goto LAB_0093cc34;
            uVar6 = 0;
            do {
              FUN_0094b4db();
              uVar6 = uVar6 + 1;
            } while (uVar6 < 3);
            uVar6 = 0;
            do {
              FUN_0094b4db();
              uVar6 = uVar6 + 4;
            } while (uVar6 < 0xc);
            FUN_0094b4db();
            uVar6 = 0;
            if (iVar8 != 0) {
              do {
                FUN_0094b4db();
                FUN_0094b4db();
                uVar6 = uVar6 + 1;
              } while (uVar6 < (uint)iVar8);
            }
            FUN_0094b4db();
            uVar6 = 0;
            if (local_70[0xb] != 0) {
              do {
                FUN_0094b4db();
                FUN_0094b4db();
                uVar6 = uVar6 + 1;
              } while (uVar6 < (uint)local_70[0xb]);
            }
            FUN_0094b4db();
            uVar6 = 0;
            if (local_70[0xc] != 0) {
              do {
                FUN_0094b4db();
                FUN_0094b4db();
                uVar6 = uVar6 + 1;
              } while (uVar6 < (uint)local_70[0xc]);
            }
          }
          local_c = FUN_0094b633();
          if (((-1 < local_c) && (local_c = FUN_0094b4db(), -1 < local_c)) &&
             (local_c = FUN_0094b4db(), -1 < local_c)) {
            uVar6 = local_28 << 2;
            local_c = FUN_0094b4db();
            if (-1 < local_c) {
              uVar7 = 0;
              if (uVar6 != 0) {
                do {
                  local_c = FUN_0093bd25(*(undefined8 *)(local_30 + uVar7 * 2));
                  if (local_c < 0) goto LAB_0093cc34;
                  uVar7 = uVar7 + 1;
                } while (uVar7 < uVar6);
              }
              local_24 = *(int *)(in_ECX + 0x110);
              local_c = FUN_0094b4db();
              if (((-1 < local_c) && (local_c = FUN_0094b4db(), -1 < local_c)) &&
                 (local_c = FUN_0094b4db(), -1 < local_c)) {
                local_28 = 0;
                if (*(int *)(in_ECX + 0xc) != 0) {
                  local_8 = (int *)0x0;
                  do {
                    local_c = FUN_0094b4db();
                    if (local_c < 0) goto LAB_0093cc34;
                    puVar3 = *(uint **)((int)local_8 + *(int *)(in_ECX + 0x18));
                    uVar6 = *puVar3 & 0xfffff;
                    local_18 = (int *)(puVar3[1] / uVar6);
                    local_c = FUN_0094b4db();
                    if (local_c < 0) goto LAB_0093cc34;
                    local_1c = (int *)0x0;
                    piVar9 = (int *)(*(int *)(in_ECX + 0x10c) + local_24 * 4);
                    *piVar9 = *piVar9 + 2;
                    if (local_18 != (int *)0x0) {
                      local_14 = (int *)0x0;
                      local_3c = (int *)(uVar6 << 2);
                      do {
                        iVar8 = *(int *)(*(int *)(in_ECX + 0x14) +
                                        *(int *)((int)local_14 +
                                                *(int *)(*(int *)(*(int *)(in_ECX + 0x18) +
                                                                 (int)local_8) + 8)) * 4);
                        iVar2 = *(int *)(in_ECX + 0x110);
                        local_c = FUN_0094b4db();
                        if ((((local_c < 0) ||
                             ((iVar8 = *(int *)(iVar8 + 8), iVar8 != -1 &&
                              (local_c = FUN_0093bf5d(iVar8,iVar2), local_c < 0)))) ||
                            (local_c = FUN_0093bc64(), local_c < 0)) ||
                           (local_c = FUN_0094b4db(), local_c < 0)) goto LAB_0093cc34;
                        piVar9 = (int *)(*(int *)(in_ECX + 0x10c) + local_24 * 4);
                        *piVar9 = *piVar9 + *(int *)(*(int *)(in_ECX + 0x10c) + iVar2 * 4) * 2 + 3;
                        local_1c = (int *)((int)local_1c + 1);
                        local_14 = (int *)((int)local_14 + (int)local_3c);
                      } while (local_1c < local_18);
                    }
                    local_1c = (int *)0x0;
                    do {
                      iVar8 = *(int *)(*(int *)(in_ECX + 0x14) +
                                      *(int *)((int)local_1c +
                                              *(int *)(*(int *)(*(int *)(in_ECX + 0x18) +
                                                               (int)local_8) + 0x10)) * 4);
                      iVar2 = *(int *)(in_ECX + 0x110);
                      local_c = FUN_0094b4db();
                      if ((local_c < 0) ||
                         ((((iVar8 = *(int *)(iVar8 + 8), iVar8 != -1 &&
                            (local_c = FUN_0093bf5d(iVar8,iVar2), local_c < 0)) ||
                           (local_c = FUN_0093bc64(), local_c < 0)) ||
                          (local_c = FUN_0094b4db(), local_c < 0)))) goto LAB_0093cc34;
                      local_1c = local_1c + 1;
                      piVar9 = (int *)(*(int *)(in_ECX + 0x10c) + local_24 * 4);
                      *piVar9 = *piVar9 + *(int *)(*(int *)(in_ECX + 0x10c) + iVar2 * 4) * 2 + 3;
                    } while (local_1c < (int *)0x4);
                    local_28 = local_28 + 1;
                    local_8 = local_8 + 1;
                  } while (local_28 < *(uint *)(in_ECX + 0xc));
                }
                local_c = FUN_0094b4db();
                if ((-1 < local_c) && (local_c = FUN_0094b4db(), -1 < local_c)) {
                  puVar3 = (uint *)(*(int *)(in_ECX + 0x10c) + local_24 * 4);
                  *puVar3 = (*puVar3 + 4) * 0x10000 & 0x7fff0000 | 0xfffe;
                  local_c = FUN_0094b4db();
                  if (-1 < local_c) {
                    if (param_1 != (undefined4 *)0x0) {
                      local_c = FUN_008eb37d(*(int *)(in_ECX + 0x110) << 2,&local_18);
                      if (local_c < 0) goto LAB_0093cc34;
                      uVar6 = *(uint *)(in_ECX + 0x110);
                      puVar10 = *(undefined4 **)(in_ECX + 0x10c);
                      puVar5 = (undefined4 *)(**(code **)(*local_18 + 0xc))();
                      for (uVar6 = uVar6 & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
                        *puVar5 = *puVar10;
                        puVar10 = puVar10 + 1;
                        puVar5 = puVar5 + 1;
                      }
                      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
                        *(undefined1 *)puVar5 = *(undefined1 *)puVar10;
                        puVar10 = (undefined4 *)((int)puVar10 + 1);
                        puVar5 = (undefined4 *)((int)puVar5 + 1);
                      }
                      *param_1 = local_18;
                    }
                    local_c = 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0093cc34:
  _free(local_30);
  return extraout_EAX_01;
}


// ==== FUN_0093cc60 @ 0x0093cc60 ====

void FUN_0093cc60(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = 0;
  *in_ECX = param_1;
  in_ECX[2] = 0;
  in_ECX[3] = in_ECX + 2;
  return;
}


// ==== FUN_0093cc7d @ 0x0093cc7d ====

void FUN_0093cc7d(void)

{
  undefined4 *_Memory;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    return;
  }
  _Memory = *(undefined4 **)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 8) = _Memory[4];
  if (((_Memory[2] & 8) == 0) && ((_Memory[2] & 1) != 0)) {
    _free(_Memory);
    return;
  }
  _free((void *)*_Memory);
  return;
}


// ==== FUN_0093ccb5 @ 0x0093ccb5 ====

undefined4 FUN_0093ccb5(char *param_1,char *param_2,uint param_3,undefined4 *param_4)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 extraout_EAX;
  char *pcVar4;
  undefined4 extraout_EAX_00;
  int in_ECX;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  
  if ((param_2 == (char *)0x0) || (param_1 != (char *)0x0)) {
    if (param_2 == (char *)0xffffffff) {
      param_2 = param_1;
      do {
        cVar1 = *param_2;
        param_2 = param_2 + 1;
      } while (cVar1 != '\0');
      param_2 = param_2 + (1 - (int)(param_1 + 1));
    }
    if ((param_3 & 1) == 0) {
      param_3 = param_3 | 2;
    }
    if ((param_3 & 2) != 0) {
      for (puVar3 = *(undefined4 **)(in_ECX + 8); puVar3 != (undefined4 *)0x0;
          puVar3 = (undefined4 *)puVar3[4]) {
        if (((*(byte *)(puVar3 + 2) & 2) != 0) && (param_2 == (char *)puVar3[1])) {
          bVar8 = true;
          pcVar4 = param_2;
          pcVar6 = param_1;
          pcVar7 = (char *)*puVar3;
          do {
            if (pcVar4 == (char *)0x0) break;
            pcVar4 = pcVar4 + -1;
            bVar8 = *pcVar6 == *pcVar7;
            pcVar6 = pcVar6 + 1;
            pcVar7 = pcVar7 + 1;
          } while (bVar8);
          if (bVar8) {
            if (param_4 != (undefined4 *)0x0) {
              *param_4 = puVar3[3];
            }
            if (((param_3 & 1) == 0) || ((param_3 & 8) == 0)) {
              return 0;
            }
            _free(param_1);
            return extraout_EAX;
          }
        }
      }
    }
    puVar3 = operator_new(0x14);
    if (puVar3 == (undefined4 *)0x0) {
      uVar2 = 0x8007000e;
    }
    else {
      if ((param_3 & 1) == 0) {
        pcVar4 = operator_new((uint)param_2);
        *puVar3 = pcVar4;
        if (pcVar4 == (char *)0x0) {
          _free(puVar3);
          return extraout_EAX_00;
        }
        for (uVar5 = (uint)param_2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined4 *)pcVar4 = *(undefined4 *)param_1;
          param_1 = param_1 + 4;
          pcVar4 = pcVar4 + 4;
        }
        for (uVar5 = (uint)param_2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar4 = *param_1;
          param_1 = param_1 + 1;
          pcVar4 = pcVar4 + 1;
        }
      }
      else {
        *puVar3 = param_1;
      }
      if ((param_3 & 4) == 0) {
        *(uint *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 3U & 0xfffffffc;
      }
      uVar2 = *(undefined4 *)(in_ECX + 4);
      puVar3[2] = param_3;
      puVar3[4] = 0;
      puVar3[3] = uVar2;
      puVar3[1] = param_2;
      *(int *)(in_ECX + 4) = (int)(param_2 + *(int *)(in_ECX + 4));
      **(undefined4 **)(in_ECX + 0xc) = puVar3;
      *(undefined4 **)(in_ECX + 0xc) = puVar3 + 4;
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = puVar3[3];
      }
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0x80004005;
  }
  return uVar2;
}


// ==== FUN_0093cdee @ 0x0093cdee ====

int FUN_0093cdee(void)

{
  int in_ECX;
  
  return (*(int *)(in_ECX + 4) + 3U >> 2) + 2;
}


// ==== FUN_0093cdfa @ 0x0093cdfa ====

undefined4 FUN_0093cdfa(uint *param_1,uint *param_2)

{
  undefined4 *puVar1;
  uint *in_ECX;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  puVar5 = param_1;
  if (param_2 == (uint *)0xffffffff) {
    uVar4 = (in_ECX[1] + 3 >> 2) + 2;
  }
  else {
    uVar4 = (uint)param_2;
    if (param_2 < (in_ECX[1] + 3 >> 2) + 2) {
      return 0x80004005;
    }
  }
  if (0x8000 < uVar4) {
    return 0x80004005;
  }
  param_1 = (uint *)0x0;
  *puVar5 = (uVar4 - 1 & 0x7fff) << 0x10 | 0xfffe;
  puVar5[1] = *in_ECX;
  param_2 = puVar5 + 2;
  for (puVar1 = (undefined4 *)in_ECX[2]; puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[4]) {
    if ((*(byte *)(puVar1 + 2) & 4) == 0) {
      uVar2 = ((int)param_1 + 3U & 0xfffffffc) - (int)param_1;
      puVar5 = param_2;
      for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar5 = 0xabababab;
        puVar5 = puVar5 + 1;
      }
      for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar5 = 0xab;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      param_2 = (uint *)((int)param_2 + uVar2);
      param_1 = (uint *)((int)param_1 + uVar2);
    }
    uVar2 = puVar1[1];
    puVar5 = (uint *)*puVar1;
    puVar6 = param_2;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(char *)puVar6 = (char)*puVar5;
      puVar5 = (uint *)((int)puVar5 + 1);
      puVar6 = (uint *)((int)puVar6 + 1);
    }
    param_2 = (uint *)((int)param_2 + puVar1[1]);
    param_1 = (uint *)((int)param_1 + puVar1[1]);
  }
  uVar2 = (uVar4 * 4 + -8) - (int)param_1;
  for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *param_2 = 0xabababab;
    param_2 = param_2 + 1;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)param_2 = 0xab;
    param_2 = (uint *)((int)param_2 + 1);
  }
  return 0;
}


// ==== FUN_0093cee7 @ 0x0093cee7 ====

void FUN_0093cee7(void)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  FUN_008f34d1(0x12);
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  *in_ECX = &PTR_FUN_00a2bda0;
  puVar2 = in_ECX + 4;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  return;
}


// ==== FUN_0093cf25 @ 0x0093cf25 ====

void FUN_0093cf25(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  FUN_008f34d1(0x12);
  *in_ECX = &PTR_FUN_00a2bda0;
  puVar2 = in_ECX + 4;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  in_ECX[0xc] = param_2;
  in_ECX[0xd] = param_3;
  in_ECX[0xe] = param_4;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  return;
}


// ==== FUN_0093cf77 @ 0x0093cf77 ====

void FUN_0093cf77(void)

{
  undefined4 *in_ECX;
  
  FUN_008f34d1(0x13);
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[10] = 0;
  *in_ECX = &PTR_FUN_00a2bdac;
  in_ECX[8] = 0xf0000;
  in_ECX[9] = 0xe40000;
  return;
}


// ==== FUN_0093cfac @ 0x0093cfac ====

void FUN_0093cfac(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 *in_ECX;
  
  FUN_008f34d1(0x13);
  in_ECX[4] = param_1;
  in_ECX[5] = param_2;
  in_ECX[6] = param_3;
  in_ECX[7] = param_4;
  in_ECX[10] = param_5;
  *in_ECX = &PTR_FUN_00a2bdac;
  in_ECX[8] = 0xf0000;
  in_ECX[9] = 0xe40000;
  return;
}


// ==== FUN_0093cff4 @ 0x0093cff4 ====

int FUN_0093cff4(void)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint local_c;
  int local_8;
  
  iVar1 = FUN_008bf738(0x60);
  if (iVar1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_0093cee7();
  }
  if (local_8 == 0) {
    return 0;
  }
  puVar2 = (undefined4 *)(in_ECX + 0x10);
  puVar4 = (undefined4 *)(local_8 + 0x10);
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 *)(local_8 + 0x30) = *(undefined4 *)(in_ECX + 0x30);
  *(undefined4 *)(local_8 + 0x34) = *(undefined4 *)(in_ECX + 0x34);
  *(undefined4 *)(local_8 + 0x38) = *(undefined4 *)(in_ECX + 0x38);
  *(undefined4 *)(local_8 + 0x54) = *(undefined4 *)(in_ECX + 0x54);
  *(undefined4 *)(local_8 + 0x58) = *(undefined4 *)(in_ECX + 0x58);
  if (*(int *)(in_ECX + 0x3c) == 0) {
LAB_0093d06a:
    if (*(int *)(in_ECX + 0x40) != 0) {
      iVar1 = (**(code **)(**(int **)(in_ECX + 0x40) + 4))();
      *(int *)(local_8 + 0x40) = iVar1;
      if (iVar1 == 0) goto LAB_0093d0b1;
    }
    local_c = 0;
    piVar3 = (int *)(in_ECX + 0x44);
    do {
      if (*piVar3 != 0) {
        iVar1 = (**(code **)(*(int *)*piVar3 + 4))();
        *(int *)((local_8 - in_ECX) + (int)piVar3) = iVar1;
        if (iVar1 == 0) goto LAB_0093d0b1;
      }
      local_c = local_c + 1;
      piVar3 = piVar3 + 1;
    } while (local_c < 4);
  }
  else {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x3c) + 4))();
    *(int *)(local_8 + 0x3c) = iVar1;
    if (iVar1 != 0) goto LAB_0093d06a;
LAB_0093d0b1:
    local_8 = 0;
  }
  return local_8;
}


// ==== FUN_0093d0b8 @ 0x0093d0b8 ====

int FUN_0093d0b8(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_008bf738(0x2c);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0093cf77();
  }
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(in_ECX + 0x10);
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(in_ECX + 0x14);
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(in_ECX + 0x18);
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(in_ECX + 0x1c);
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(in_ECX + 0x20);
    *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(in_ECX + 0x24);
    if (*(int *)(in_ECX + 0x28) == 0) goto LAB_0093d119;
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x28) + 4))();
    *(int *)(iVar1 + 0x28) = iVar2;
    if (iVar2 != 0) goto LAB_0093d119;
  }
  iVar1 = 0;
LAB_0093d119:
  return iVar1;
}


// ==== FUN_0093d11c @ 0x0093d11c ====

int FUN_0093d11c(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(*(int *)(*(int *)(param_3 + 0x10) + param_1 * 4) + 8);
  uVar2 = *(uint *)(*(int *)(*(int *)(param_3 + 0x10) + param_2 * 4) + 8);
  if (uVar2 <= uVar1) {
    if (uVar2 < uVar1) {
      return -1;
    }
    if (param_1 <= param_2) {
      return -(uint)(param_1 < param_2);
    }
  }
  return 1;
}


// ==== FUN_0093d155 @ 0x0093d155 ====

uint FUN_0093d155(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  
  iVar2 = *(int *)(*(int *)(param_3 + 0x14) + param_1 * 4);
  iVar3 = *(int *)(*(int *)(param_3 + 0x14) + param_2 * 4);
  uVar4 = *(uint *)(iVar2 + 0x60);
  pbVar5 = *(byte **)(uVar4 + 0x20);
  if (pbVar5 == (byte *)0x0) {
    pbVar5 = &DAT_0099cf70;
  }
  pbVar7 = *(byte **)(*(int *)(iVar3 + 0x60) + 0x20);
  pbVar8 = &DAT_0099cf70;
  if (pbVar7 != (byte *)0x0) {
    pbVar8 = pbVar7;
  }
  do {
    bVar1 = *pbVar5;
    bVar9 = bVar1 < *pbVar8;
    if (bVar1 != *pbVar8) {
LAB_0093d1b1:
      iVar6 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
      goto LAB_0093d1b6;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar5[1];
    bVar9 = bVar1 < pbVar8[1];
    if (bVar1 != pbVar8[1]) goto LAB_0093d1b1;
    pbVar5 = pbVar5 + 2;
    pbVar8 = pbVar8 + 2;
  } while (bVar1 != 0);
  iVar6 = 0;
LAB_0093d1b6:
  if (iVar6 < 1) {
    if (-1 < iVar6) {
      pbVar5 = *(byte **)(*(int *)(*(int *)(iVar3 + 0x60) + 0x14) + 0x18);
      pbVar7 = *(byte **)(*(int *)(uVar4 + 0x14) + 0x18);
      do {
        bVar1 = *pbVar7;
        bVar9 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_0093d1fa:
          iVar6 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_0093d1ff;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar7[1];
        bVar9 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_0093d1fa;
        pbVar7 = pbVar7 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar6 = 0;
LAB_0093d1ff:
      if (0 < iVar6) goto LAB_0093d1ba;
      if (-1 < iVar6) {
        if (*(uint *)(iVar3 + 0x60) < uVar4) goto LAB_0093d1ba;
        if (*(uint *)(iVar3 + 0x60) <= uVar4) {
          if (*(uint *)(iVar3 + 0x74) <= *(uint *)(iVar2 + 0x74)) {
            if (*(uint *)(iVar3 + 0x74) < *(uint *)(iVar2 + 0x74)) goto LAB_0093d1ba;
            if (*(uint *)(iVar3 + 0x10) <= *(uint *)(iVar2 + 0x10)) {
              return (uint)(*(uint *)(iVar3 + 0x10) < *(uint *)(iVar2 + 0x10));
            }
          }
        }
      }
    }
    uVar4 = 0xffffffff;
  }
  else {
LAB_0093d1ba:
    uVar4 = 1;
  }
  return uVar4;
}


// ==== FUN_0093d232 @ 0x0093d232 ====

uint FUN_0093d232(uint param_1,int param_2)

{
  int in_ECX;
  
  return param_2 << ((byte)*(undefined4 *)(in_ECX + 0xec) & 0x1f) |
         *(uint *)(in_ECX + 0xe4) & param_1;
}


// ==== FUN_0093d253 @ 0x0093d253 ====

uint FUN_0093d253(uint param_1)

{
  int in_ECX;
  
  return *(uint *)(in_ECX + 0xe4) & param_1;
}


// ==== FUN_0093d265 @ 0x0093d265 ====

uint FUN_0093d265(uint param_1)

{
  int in_ECX;
  
  return (*(uint *)(in_ECX + 0xe8) & param_1) >> ((byte)*(undefined4 *)(in_ECX + 0xec) & 0x1f);
}


// ==== FUN_0093d27f @ 0x0093d27f ====

undefined4
FUN_0093d27f(uint *param_1,int param_2,uint param_3,uint *param_4,uint *param_5,int param_6,
            int param_7)

{
  uint uVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint auStack_44 [4];
  int local_34 [5];
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  uint *local_8;
  
  uVar4 = *param_1;
  local_34[0] = 0;
  local_34[1] = 0;
  local_34[2] = 0;
  local_34[3] = 0;
  local_34[4] = uVar4;
  if (((uVar4 & 0xfff00000) == 0x50000000) || ((uVar4 & 0xfff00000) == 0x70800000)) {
    uVar5 = 0;
    uVar1 = 0;
    do {
      if (uVar1 < (uVar4 & 0xfffff)) {
        param_5[uVar1] = uVar1;
      }
      else {
        param_5[uVar1] = 0xff;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < 4);
    if (param_3 != 0) {
      do {
        iVar2 = *(int *)(param_2 + uVar5 * 4);
        iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + iVar2 * 4);
        if ((iVar2 != *(int *)param_1[4]) || (*(int *)(iVar3 + 0x3c) != param_6)) {
          if (*(int *)(iVar3 + 0x38) != *(int *)param_1[4]) {
            return 1;
          }
          if (*(int *)(iVar3 + 0x3c) != param_6) {
            return 1;
          }
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_3);
    }
  }
  else {
    local_14 = 0;
    if (param_3 != 0) {
      local_18 = *(int *)(in_ECX + 0x14);
      iVar2 = param_2 - (int)param_4;
      local_8 = param_4;
      local_20 = iVar2;
      do {
        local_10 = 0;
        local_c = *(int *)(local_18 + *(int *)(iVar2 + (int)local_8) * 4);
        uVar1 = local_14;
        if ((param_7 == 0) || (uVar1 = *local_8, uVar1 < 4)) {
          uVar4 = 0;
          if (param_1[3] == 0) {
            return 1;
          }
          local_1c = param_1[4] - (int)local_34;
          do {
            if (((*(int *)(uVar1 * 4 + param_2) == *(int *)(local_1c + (int)(local_34 + uVar4))) &&
                (*(int *)(local_c + 0x3c) == param_6)) ||
               ((*(int *)(local_c + 0x38) == *(int *)(param_1[4] + uVar4 * 4) &&
                (*(int *)(local_c + 0x3c) == param_6)))) {
              local_10 = 1;
              auStack_44[uVar1] = uVar4;
              local_34[uVar4] = 1;
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < param_1[3]);
          if (local_10 == 0) {
            return 1;
          }
          iVar2 = local_20;
          uVar4 = local_34[4];
        }
        local_8 = local_8 + 1;
        local_14 = local_14 + 1;
      } while (local_14 < param_3);
    }
    if (param_7 == 0) {
      uVar1 = 0;
      if ((uVar4 & 0xfffff) != 0) {
        do {
          if (local_34[uVar1] == 0) {
            return 1;
          }
          uVar1 = uVar1 + 1;
        } while (uVar1 < (uVar4 & 0xfffff));
      }
    }
    iVar3 = (int)param_4 - (int)param_5;
    iVar2 = 4;
    do {
      uVar4 = *(uint *)(iVar3 + (int)param_5);
      if (uVar4 < 4) {
        *param_5 = auStack_44[uVar4];
      }
      else {
        *param_5 = 0xff;
      }
      param_5 = param_5 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return 0;
}


// ==== FUN_0093d430 @ 0x0093d430 ====

int FUN_0093d430(uint *param_1,int *param_2,int *param_3,uint *param_4,int param_5,uint *param_6,
                uint param_7,int param_8)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  int local_1c8 [40];
  int local_128 [40];
  undefined1 local_88 [16];
  int local_78 [16];
  uint local_38;
  int local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  undefined4 *local_1c;
  int local_18;
  uint local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_20 = *param_1 & 0xfffff;
  local_10 = 0;
  local_14 = 0;
  if ((param_7 < local_20) && (param_8 == 0)) {
    local_10 = 1;
  }
  else if ((*param_1 & 0xfff00000) == param_2[1]) {
    local_30 = 1;
    if ((*param_2 == 0) && (param_8 != 0)) {
      local_30 = 2;
    }
    local_2c = 0;
    local_18 = in_ECX;
    if (local_30 == 0) {
LAB_0093d82d:
      piVar7 = local_78;
      piVar10 = param_3;
      for (uVar9 = local_14 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
        *piVar10 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar10 = piVar10 + 1;
      }
      for (iVar11 = 0; iVar11 != 0; iVar11 = iVar11 + -1) {
        *(char *)piVar10 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar10 = (int *)((int)piVar10 + 1);
      }
      param_3[local_14] = (int)param_1;
      *param_4 = local_14 + 1;
      uVar9 = 0;
      do {
        iVar11 = *(int *)((int)local_128 + uVar9);
        if ((iVar11 != -1) || (iVar11 = *(int *)((int)local_1c8 + uVar9), iVar11 != -1)) {
          *(int *)(uVar9 + param_5) = iVar11;
        }
        uVar9 = uVar9 + 4;
      } while (uVar9 < 0xa0);
      local_10 = 0;
    }
    else {
      do {
        local_24 = 0;
        if (param_2[7] != -1) {
          do {
            iVar11 = 0x28;
            uVar9 = *param_4;
            piVar7 = param_3;
            piVar10 = local_78;
            for (uVar6 = uVar9; uVar6 != 0; uVar6 = uVar6 - 1) {
              *piVar10 = *piVar7;
              piVar7 = piVar7 + 1;
              piVar10 = piVar10 + 1;
            }
            piVar7 = local_128;
            for (; iVar11 != 0; iVar11 = iVar11 + -1) {
              *piVar7 = -1;
              piVar7 = piVar7 + 1;
            }
            piVar7 = local_1c8;
            for (iVar11 = 0x28; iVar11 != 0; iVar11 = iVar11 + -1) {
              *piVar7 = -1;
              piVar7 = piVar7 + 1;
            }
            local_14 = uVar9;
            local_10 = 0;
            local_c = 0;
            if (param_2[2] != 0) {
              local_8 = 0;
              do {
                uVar9 = local_8;
                if (local_24 == 0) {
                  uVar6 = local_c;
                }
                else {
                  uVar6 = 1 - local_c;
                }
                if (3 < *param_6) {
                  return 1;
                }
                uVar1 = param_1[2];
                iVar11 = *(int *)(*(int *)(local_18 + 0x14) +
                                 *(int *)(uVar1 + (*param_6 + local_8) * 4) * 4);
                uVar6 = param_2[uVar6 + 3];
                if (uVar6 < 0x10) {
                  iVar5 = *(int *)(iVar11 + 0x48);
                  if (iVar5 != -1) {
                    iVar2 = *param_2;
                    iVar3 = *(int *)(local_18 + 0x18);
                    iVar5 = FUN_0093d27f(*(undefined4 *)(iVar3 + iVar5 * 4),uVar1 + local_8 * 4,
                                         local_20,param_6,local_88,
                                         (param_2 + (uVar6 - iVar2) * 8)[6],param_8);
                    if (iVar5 == 0) {
                      local_10 = FUN_0093d430(*(undefined4 *)(iVar3 + *(int *)(iVar11 + 0x48) * 4),
                                              param_2 + (uVar6 - iVar2) * 8,local_78,&local_14,
                                              local_1c8,local_88,param_7,param_8);
                      goto LAB_0093d5d2;
                    }
                  }
                  local_10 = 1;
                  break;
                }
                uVar8 = 0;
                piVar7 = local_128 + (uVar6 - 0x10) * 4;
                do {
                  if (param_6[uVar8] < local_20) {
                    *piVar7 = *(int *)(uVar1 + (param_6[uVar8] + uVar9) * 4);
                  }
                  else {
                    *piVar7 = -1;
                  }
                  uVar8 = uVar8 + 1;
                  piVar7 = piVar7 + 1;
                } while (uVar8 < 4);
LAB_0093d5d2:
                if (local_10 == 1) break;
                local_c = local_c + 1;
                local_8 = local_8 + local_20;
              } while (local_c < (uint)param_2[2]);
            }
            local_c = 0;
            if (param_2[2] != 0) {
              local_1c = (undefined4 *)0x0;
              do {
                if (local_24 == 0) {
                  uVar9 = local_c;
                }
                else {
                  uVar9 = 1 - local_c;
                }
                if ((0xf < (uint)param_2[uVar9 + 3]) && (local_28 = 0, local_14 != 0)) {
                  do {
                    uVar9 = 0;
                    if (local_20 != 0) {
                      uVar6 = *(uint *)(local_78[local_28] + 0xc);
                      do {
                        local_8 = 0;
                        if (uVar6 != 0) {
                          piVar7 = *(int **)(local_78[local_28] + 0x10);
                          do {
                            if (*(int *)(param_1[2] + ((int)local_1c + uVar9) * 4) == *piVar7) {
                              local_10 = 1;
                              goto LAB_0093d676;
                            }
                            local_8 = local_8 + 1;
                            piVar7 = piVar7 + 1;
                          } while (local_8 < uVar6);
                        }
                        uVar9 = uVar9 + 1;
                      } while (uVar9 < local_20);
                    }
LAB_0093d676:
                    local_28 = local_28 + 1;
                  } while (local_28 < local_14);
                }
                local_c = local_c + 1;
                local_1c = (undefined4 *)((int)local_1c + local_20);
              } while (local_c < (uint)param_2[2]);
            }
            if (local_10 == 0) {
              if ((local_2c != 0) || (*param_2 != 0)) goto LAB_0093d82d;
              local_c = 0;
              if (local_14 != 0) {
                do {
                  local_38 = *(uint *)(local_78[local_c] + 0xc);
                  local_8 = 0;
                  if (local_38 != 0) {
                    do {
                      if (*(int *)(local_18 + 0xc) != 0) {
                        local_1c = *(undefined4 **)(local_18 + 0x18);
                        local_34 = *(int *)(local_18 + 0xc);
                        do {
                          puVar4 = (uint *)*local_1c;
                          if ((puVar4 != (uint *)0x0) && (*puVar4 != 0)) {
                            uVar9 = puVar4[1];
                            local_28 = 0;
                            if (uVar9 != 0) {
                              iVar11 = *(int *)(*(int *)(local_78[local_c] + 0x10) + local_8 * 4);
                              piVar7 = (int *)puVar4[2];
                              do {
                                if ((*piVar7 == iVar11) ||
                                   (*(int *)(*(int *)(*(int *)(local_18 + 0x14) + *piVar7 * 4) +
                                            0x38) == iVar11)) {
                                  local_28 = 1;
                                }
                                piVar7 = piVar7 + 1;
                                uVar9 = uVar9 - 1;
                              } while (uVar9 != 0);
                            }
                            if (puVar4 == param_1) {
                              uVar9 = 0;
                            }
                            else {
                              uVar9 = local_28;
                            }
                            if (uVar9 != 0) {
                              uVar6 = 0;
                              do {
                                if (puVar4 == (uint *)local_78[uVar6]) {
                                  uVar9 = 0;
                                }
                                uVar6 = uVar6 + 1;
                              } while (uVar6 < local_14);
                              if (uVar9 != 0) {
                                local_10 = 1;
                              }
                            }
                          }
                          local_1c = local_1c + 1;
                          local_34 = local_34 + -1;
                        } while (local_34 != 0);
                      }
                      local_8 = local_8 + 1;
                    } while (local_8 < local_38);
                  }
                  local_c = local_c + 1;
                } while (local_c < local_14);
              }
              local_8 = 0;
              do {
                iVar11 = local_128[local_8];
                if ((iVar11 != -1) && (uVar9 = 0, local_14 != 0)) {
                  do {
                    iVar5 = *(int *)(local_78[uVar9] + 0xc);
                    if (iVar5 != 0) {
                      piVar7 = *(int **)(local_78[uVar9] + 0x10);
                      do {
                        if ((iVar11 == *piVar7) ||
                           (*(int *)(*(int *)(*(int *)(local_18 + 0x14) + iVar11 * 4) + 0x38) ==
                            *piVar7)) {
                          local_10 = 1;
                        }
                        piVar7 = piVar7 + 1;
                        iVar5 = iVar5 + -1;
                      } while (iVar5 != 0);
                    }
                    uVar9 = uVar9 + 1;
                  } while (uVar9 < local_14);
                }
                local_8 = local_8 + 1;
              } while (local_8 < 0x28);
              if (local_10 == 0) goto LAB_0093d82d;
            }
            local_24 = local_24 + 1;
          } while (local_24 < param_2[7] + 1U);
        }
        if (local_10 == 0) goto LAB_0093d82d;
        local_2c = local_2c + 1;
      } while (local_2c < local_30);
    }
  }
  else {
    local_10 = 1;
  }
  return local_10;
}


// ==== FUN_0093d892 @ 0x0093d892 ====

undefined4 FUN_0093d892(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  int *piVar5;
  
  uVar4 = *param_1 + 1;
  piVar5 = (int *)(*(int *)(in_ECX + 0x14) + uVar4 * 4);
  iVar1 = *piVar5;
  if (uVar4 < *(uint *)(in_ECX + 8)) {
    while( true ) {
      uVar2 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(*piVar5 + 4) * 4) + 4);
      if ((((uVar2 & 0x10) == 0) || ((uVar2 & 0x200) != 0)) && ((uVar2 & 0x20) == 0)) break;
      iVar3 = *(int *)(*piVar5 + 0x68);
      if ((*(int *)(*(int *)(iVar1 + 0x68) + 0x24) != *(int *)(iVar3 + 0x24)) ||
         (*(int *)(*(int *)(iVar1 + 0x68) + 0x20) != *(int *)(iVar3 + 0x20))) break;
      uVar4 = uVar4 + 1;
      piVar5 = piVar5 + 1;
      if (*(uint *)(in_ECX + 8) <= uVar4) break;
    }
  }
  *param_1 = uVar4 - 1;
  return 0;
}


// ==== FUN_0093d907 @ 0x0093d907 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_0093d907(void)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  bool bVar4;
  int iVar5;
  int *piVar6;
  int *in_ECX;
  char cVar7;
  uint local_214;
  uint local_210;
  char local_209;
  undefined1 local_208 [256];
  undefined1 local_108 [256];
  undefined4 local_8;
  
  bVar4 = false;
  local_8 = DAT_00b49670;
  local_209 = '\0';
  local_210 = 0;
  if (in_ECX[2] != 0) {
    do {
      iVar5 = *(int *)(in_ECX[5] + local_210 * 4);
      uVar1 = *(uint *)(*(int *)(in_ECX[4] + *(int *)(iVar5 + 4) * 4) + 4);
      if (((((uVar1 & 0x10) != 0) && ((uVar1 & 0x200) == 0)) || ((uVar1 & 0x20) != 0)) &&
         (iVar5 = (**(code **)(*in_ECX + 4))(iVar5,0), iVar5 < 0)) {
        FUN_0093d892(&local_210);
        local_209 = '\x01';
        bVar4 = true;
      }
      local_210 = local_210 + 1;
    } while (local_210 < (uint)in_ECX[2]);
    if (bVar4) {
      return 0x80004005;
    }
  }
  cVar7 = '\0';
  local_210 = 0;
  if (in_ECX[2] != 0) {
    do {
      puVar2 = *(uint **)(in_ECX[5] + local_210 * 4);
      uVar1 = *(uint *)(*(int *)(in_ECX[4] + puVar2[1] * 4) + 4);
      if (((((uVar1 & 0x10) != 0) && ((uVar1 & 0x200) == 0)) || ((uVar1 & 0x20) != 0)) &&
         (local_214 = local_210 + 1, local_214 < (uint)in_ECX[2])) {
        piVar6 = (int *)(in_ECX[5] + local_214 * 4);
        do {
          puVar3 = (uint *)*piVar6;
          if (((puVar3[1] == puVar2[1]) && (puVar3[0x1c] == puVar2[0x1c])) &&
             ((puVar3[0x1b] == puVar2[0x1b] && (((*puVar3 ^ *puVar2) & 0x1000000) != 0)))) {
            FUN_0091564e(puVar2,local_108,0x100);
            FUN_0091564e(puVar3,local_208,0x100);
            FUN_0091a001();
            FUN_0093d892(&local_210);
            local_209 = '\x01';
            break;
          }
          local_214 = local_214 + 1;
          piVar6 = piVar6 + 1;
        } while (local_214 < (uint)in_ECX[2]);
        cVar7 = local_209;
      }
      local_210 = local_210 + 1;
    } while (local_210 < (uint)in_ECX[2]);
  }
  return -(uint)(cVar7 != '\0') & 0x80004005;
}


// ==== FUN_0093dacd @ 0x0093dacd ====

undefined4 FUN_0093dacd(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if (*(int *)(param_2 + 0x24) != param_3) {
    uVar1 = 0;
    *(int *)(param_2 + 0x24) = param_3;
    if (*(int *)(param_2 + 0x14) != 0) {
      do {
        FUN_0093dacd(param_1,*(undefined4 *)
                              (param_1 + *(int *)(*(int *)(param_2 + 0x18) + uVar1 * 4) * 4),param_3
                    );
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(uint *)(param_2 + 0x14));
    }
  }
  return 0;
}


// ==== FUN_0093db13 @ 0x0093db13 ====

undefined4 FUN_0093db13(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if (*(int *)(param_2 + 0x28) != param_3) {
    uVar1 = 0;
    *(int *)(param_2 + 0x28) = param_3;
    if (*(int *)(param_2 + 0x14) != 0) {
      do {
        FUN_0093db13(param_1,*(undefined4 *)
                              (param_1 + *(int *)(*(int *)(param_2 + 0x18) + uVar1 * 4) * 4),param_3
                    );
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(uint *)(param_2 + 0x14));
    }
  }
  return 0;
}


// ==== FUN_0093db59 @ 0x0093db59 ====

undefined4 FUN_0093db59(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if (*(int *)(param_2 + 0x28) != param_3) {
    uVar1 = 0;
    *(int *)(param_2 + 0x28) = param_3;
    if (*(int *)(param_2 + 0x1c) != 0) {
      do {
        FUN_0093db59(param_1,*(undefined4 *)
                              (param_1 + *(int *)(*(int *)(param_2 + 0x20) + uVar1 * 4) * 4),param_3
                    );
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(uint *)(param_2 + 0x1c));
    }
  }
  return 0;
}


// ==== FUN_0093db9f @ 0x0093db9f ====

undefined4 FUN_0093db9f(char *param_1,int *param_2,char param_3)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  *param_2 = 0;
  while( true ) {
    cVar1 = *param_1;
    if (cVar1 == '\0') {
      return 0x80004005;
    }
    while (iVar2 = _isalnum((int)cVar1), iVar2 == 0) {
      param_1 = param_1 + 1;
      cVar1 = *param_1;
    }
    iVar2 = _tolower((int)*param_1);
    if (iVar2 == param_3) break;
    while (iVar2 = _isalnum((int)*param_1), iVar2 != 0) {
      param_1 = param_1 + 1;
    }
  }
  if (*param_2 == 0) {
    *param_2 = (int)param_1;
    return 0;
  }
  iVar2 = *(int *)(in_ECX + 8);
  if (iVar2 != 0) {
    do {
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_0091a001();
  return 0x80004005;
}


// ==== FUN_0093dc46 @ 0x0093dc46 ====

void FUN_0093dc46(int param_1,char *param_2,uint param_3,uint param_4,undefined4 param_5)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  long lVar5;
  int *piVar6;
  undefined4 *puVar7;
  int in_ECX;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  char *pcVar12;
  uint uVar13;
  undefined4 *puVar14;
  char *local_18;
  int *local_14;
  int *local_10;
  undefined4 *local_c;
  char *local_8;
  
  uVar11 = 0;
  local_14 = (int *)0x0;
  if (*(int *)(in_ECX + 4) != 0) {
    do {
      iVar9 = *(int *)(*(int *)(in_ECX + 0x10) + uVar11 * 4);
      uVar2 = *(uint *)(iVar9 + 4);
      *(undefined4 *)(iVar9 + 0x10) = 0;
      if ((uVar2 & 0x400) == 0) {
        uVar13 = 0;
        *(undefined4 *)(iVar9 + 8) = 0;
        if (*(int *)(in_ECX + 8) != 0) {
          do {
            iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + uVar13 * 4);
            if ((*(uint *)(iVar3 + 4) == uVar11) &&
               (uVar8 = *(int *)(iVar3 + 0xc) + 1, *(uint *)(iVar9 + 8) < uVar8)) {
              *(uint *)(iVar9 + 8) = uVar8;
            }
            uVar13 = uVar13 + 1;
          } while (uVar13 < *(uint *)(in_ECX + 8));
        }
        if (((uVar2 & 0x100) != 0) && ((uVar2 & 0x800) == 0)) {
          *(uint *)(iVar9 + 4) = uVar2 & 0xffffffbf;
        }
        uVar2 = *(uint *)(iVar9 + 4);
        if (((uVar2 & 0x10) != 0) && ((uVar2 & 0xa00) == 0)) {
          *(uint *)(iVar9 + 4) = uVar2 & 0xffffffbf;
        }
        uVar2 = *(uint *)(iVar9 + 4);
        if ((((char)uVar2 < '\0') && ((uVar2 & 0x800) == 0)) && (*(int *)(iVar9 + 8) == 1)) {
          *(uint *)(iVar9 + 4) = uVar2 & 0xffffffbf;
        }
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 < *(uint *)(in_ECX + 4));
  }
  local_c = operator_new((int)param_2 << 3);
  if (local_c != (undefined4 *)0x0) {
    local_8 = (char *)0x0;
    puVar7 = local_c;
    for (iVar9 = ((uint)param_2 & 0x1fffffff) << 1; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)puVar7 = 0;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    if (*(int *)(in_ECX + 4) != 0) {
      do {
        puVar7 = *(undefined4 **)(*(int *)(in_ECX + 0x10) + (int)local_8 * 4);
        uVar11 = puVar7[1];
        if ((((uVar11 & param_3) == param_3) && ((param_4 & uVar11) == 0)) &&
           (((uVar11 & 0x40) != 0 && (((uVar11 & 0x800) != 0 && (puVar7[2] != 0)))))) {
          puVar7[4] = 0xffffffff;
          iVar9 = FUN_0093db9f(*puVar7,&local_18,param_5,local_8);
          pcVar12 = local_18;
          if (iVar9 < 0) goto LAB_0093e2a4;
          if ((local_18 != (char *)0x0) &&
             (iVar9 = _tolower((int)*local_18), (char)param_5 == iVar9)) {
            local_10 = (int *)(pcVar12 + 1);
            iVar9 = _isdigit((int)(char)*local_10);
            if (iVar9 != 0) {
              pcVar12 = pcVar12 + 2;
              while (iVar9 = _isdigit((int)*pcVar12), iVar9 != 0) {
                pcVar12 = pcVar12 + 1;
              }
              if ((*pcVar12 == '\0') || (*pcVar12 == ';')) {
                lVar5 = _atol((char *)local_10);
                puVar7[4] = lVar5;
              }
            }
          }
          if (param_2 <= (char *)puVar7[4]) {
            param_2 = *(char **)(in_ECX + 8);
            if (param_2 != (char *)0x0) {
              do {
                param_2 = (char *)((int)param_2 + -1);
              } while (param_2 != (char *)0x0);
            }
            FUN_0091a001();
            goto LAB_0093e2a4;
          }
          local_10 = (int *)0x0;
          if (puVar7[2] != 0) {
            do {
              if (param_2 <= (char *)(puVar7[4] + (int)local_10)) {
                if (((((char)param_5 == 'b') || ((char)param_5 == 'c')) || ((char)param_5 == 'i'))
                   || (((char)param_5 == 's' || ((char)param_5 == 'v')))) goto LAB_0093e242;
                goto LAB_0093e2a4;
              }
              puVar1 = local_c + (puVar7[4] + (int)local_10) * 2;
              if (*puVar1 != 0) {
                FUN_0091a001();
              }
              *puVar1 = (uint)local_8;
              puVar1[1] = (uint)local_10;
              local_10 = (int *)((int)local_10 + 1);
            } while (local_10 < (int *)puVar7[2]);
          }
        }
        local_8 = local_8 + 1;
      } while (local_8 < *(char **)(in_ECX + 4));
    }
    iVar9 = *(int *)(in_ECX + 4);
    local_8 = (char *)0x0;
    if (iVar9 != 0) {
      piVar6 = *(int **)(in_ECX + 0x10);
      do {
        uVar11 = *(uint *)(*piVar6 + 4);
        if ((((uVar11 & param_3) == param_3) && ((param_4 & uVar11) == 0)) &&
           (((uVar11 & 0x40) != 0 && (((uVar11 & 0x800) == 0 && (*(int *)(*piVar6 + 8) != 0)))))) {
          local_8 = local_8 + 1;
        }
        piVar6 = piVar6 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    piVar6 = operator_new((int)local_8 << 2);
    uVar11 = 0;
    local_14 = piVar6;
    if (piVar6 != (int *)0x0) {
      local_8 = (char *)0x0;
      if (*(int *)(in_ECX + 4) != 0) {
        do {
          iVar9 = *(int *)(*(int *)(in_ECX + 0x10) + uVar11 * 4);
          uVar2 = *(uint *)(iVar9 + 4);
          if (((((uVar2 & param_3) == param_3) && ((param_4 & uVar2) == 0)) && ((uVar2 & 0x40) != 0)
              ) && (((uVar2 & 0x800) == 0 && (*(int *)(iVar9 + 8) != 0)))) {
            piVar6[(int)local_8] = uVar11;
            local_8 = local_8 + 1;
          }
          uVar11 = uVar11 + 1;
        } while (uVar11 < *(uint *)(in_ECX + 4));
      }
      FUN_00915b0e(FUN_0093d11c,piVar6,local_8,in_ECX);
      local_18 = (char *)0x0;
      if (local_8 != (char *)0x0) {
        local_10 = piVar6;
        do {
          iVar9 = *(int *)(*(int *)(in_ECX + 0x10) + *local_10 * 4);
          pcVar12 = (char *)0x0;
          if (param_2 != (char *)0x0) {
            do {
              for (; (pcVar4 = pcVar12, pcVar12 < param_2 && (local_c[(int)pcVar12 * 2] != 0));
                  pcVar12 = pcVar12 + 1) {
              }
              for (; (pcVar4 < param_2 && (local_c[(int)pcVar4 * 2] == 0)); pcVar4 = pcVar4 + 1) {
              }
            } while (((uint)((int)pcVar4 - (int)pcVar12) < *(uint *)(iVar9 + 8)) &&
                    (pcVar12 = pcVar4, pcVar4 < param_2));
          }
          if (param_2 < pcVar12 + *(int *)(iVar9 + 8)) {
            if (((((char)param_5 == 'v') || ((char)param_5 == 'c')) || ((char)param_5 == 's')) ||
               ((char)param_5 == 'b')) goto LAB_0093e242;
            goto joined_r0x0093e1de;
          }
          uVar11 = 0;
          if (*(int *)(iVar9 + 8) != 0) {
            piVar6 = local_c + (int)pcVar12 * 2;
            do {
              iVar3 = *local_10;
              piVar6[1] = uVar11;
              *piVar6 = iVar3;
              uVar11 = uVar11 + 1;
              piVar6 = piVar6 + 2;
            } while (uVar11 < *(uint *)(iVar9 + 8));
          }
          local_18 = local_18 + 1;
          local_10 = local_10 + 1;
          *(char **)(iVar9 + 0x10) = pcVar12;
        } while (local_18 < local_8);
      }
      uVar11 = 0;
      if (*(int *)(in_ECX + 8) != 0) {
        do {
          iVar9 = *(int *)(*(int *)(in_ECX + 0x14) + uVar11 * 4);
          piVar6 = (int *)(iVar9 + 0xc);
          *piVar6 = *piVar6 + *(int *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar9 + 4) * 4) +
                                      0x10);
          uVar11 = uVar11 + 1;
        } while (uVar11 < *(uint *)(in_ECX + 8));
      }
      uVar11 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        do {
          iVar9 = *(int *)(*(int *)(in_ECX + 0x10) + uVar11 * 4);
          *(int *)(iVar9 + 8) = *(int *)(iVar9 + 8) + *(int *)(iVar9 + 0x10);
          uVar11 = uVar11 + 1;
          *(undefined4 *)(iVar9 + 0x10) = 0;
        } while (uVar11 < *(uint *)(in_ECX + 4));
      }
      local_8 = (char *)0x0;
      if (*(int *)(in_ECX + 4) != 0) {
        do {
          iVar9 = *(int *)(*(int *)(in_ECX + 0x10) + (int)local_8 * 4);
          uVar11 = *(uint *)(iVar9 + 4);
          if ((((uVar11 & param_3) == param_3) && ((param_4 & uVar11) == 0)) &&
             (((uVar11 & 0x40) == 0 && (((uVar11 & 0x800) == 0 && (*(int *)(iVar9 + 8) != 0)))))) {
            puVar7 = operator_new(*(int *)(iVar9 + 8) << 2);
            if (puVar7 != (undefined4 *)0x0) {
              puVar14 = puVar7;
              for (uVar11 = *(uint *)(iVar9 + 8) & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
                *puVar14 = 0xffffffff;
                puVar14 = puVar14 + 1;
              }
              for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                *(undefined1 *)puVar14 = 0xff;
                puVar14 = (undefined4 *)((int)puVar14 + 1);
              }
              local_10 = (int *)0x0;
              if (*(int *)(in_ECX + 8) == 0) goto LAB_0093e14b;
              do {
                iVar9 = *(int *)(*(int *)(in_ECX + 0x14) + (int)local_10 * 4);
                if (*(char **)(iVar9 + 4) == local_8) {
                  if (puVar7[*(int *)(iVar9 + 0xc)] == -1) {
                    pcVar12 = (char *)0x0;
                    if (param_2 != (char *)0x0) {
                      do {
                        if (local_c[(int)pcVar12 * 2] == 0) break;
                        pcVar12 = pcVar12 + 1;
                      } while (pcVar12 < param_2);
                      if (pcVar12 < param_2) {
                        local_c[(int)pcVar12 * 2] = local_8;
                        (local_c + (int)pcVar12 * 2)[1] = *(uint *)(iVar9 + 0xc);
                        puVar7[*(int *)(iVar9 + 0xc)] = pcVar12;
                        goto LAB_0093e135;
                      }
                    }
                    if (((((char)param_5 != 'v') && ((char)param_5 != 'c')) &&
                        ((char)param_5 != 's')) && ((char)param_5 != 'b')) {
joined_r0x0093e1de:
                      if ((char)param_5 != 'i') break;
                    }
LAB_0093e242:
                    FUN_0091a001();
                    break;
                  }
LAB_0093e135:
                  *(undefined4 *)(iVar9 + 0xc) = puVar7[*(int *)(iVar9 + 0xc)];
                }
                local_10 = (int *)((int)local_10 + 1);
                if (*(int **)(in_ECX + 8) <= local_10) {
LAB_0093e14b:
                  _free(puVar7);
                  return;
                }
              } while( true );
            }
            goto LAB_0093e2a4;
          }
          local_8 = local_8 + 1;
        } while (local_8 < *(char **)(in_ECX + 4));
      }
      if (param_1 != -1) {
        uVar11 = 0;
        if (*(int *)(in_ECX + 8) != 0) {
          do {
            iVar9 = *(int *)(*(int *)(in_ECX + 0x14) + uVar11 * 4);
            uVar2 = *(uint *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar9 + 4) * 4) + 4);
            if (((uVar2 & param_3) == param_3) && ((param_4 & uVar2) == 0)) {
              if ((uVar2 & 0x100) == 0) {
                *(int *)(iVar9 + 4) = param_1;
              }
              else {
                if ((uVar2 & 0x40000) == 0) {
                  if ((uVar2 & 0x800) != 0) goto LAB_0093e264;
                  uVar10 = *(undefined4 *)(in_ECX + 0x78);
                }
                else {
                  uVar10 = *(undefined4 *)(in_ECX + 0x184);
                }
                *(undefined4 *)(iVar9 + 4) = uVar10;
              }
            }
LAB_0093e264:
            uVar11 = uVar11 + 1;
          } while (uVar11 < *(uint *)(in_ECX + 8));
        }
        *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x10) + param_1 * 4) + 0x10) = 0;
        *(char **)(*(int *)(*(int *)(in_ECX + 0x10) + param_1 * 4) + 8) = param_2;
        if (param_1 == *(int *)(in_ECX + 0x7c)) {
          *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0x78) * 4) + 0x10) =
               0;
          *(char **)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0x78) * 4) + 8) = param_2;
        }
      }
    }
  }
LAB_0093e2a4:
  _free(local_c);
  return;
}


// ==== FUN_0093e2c8 @ 0x0093e2c8 ====

int FUN_0093e2c8(void)

{
  int iVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x138) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x13c) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x140) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x144) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x148) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x14c) = 0;
  *(undefined4 *)(in_ECX + 0x150) = 0;
  iVar1 = FUN_009198e4();
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_0093e2f9 @ 0x0093e2f9 ====

undefined4 FUN_0093e2f9(void)

{
  return 0x80004005;
}


// ==== FUN_0093e2ff @ 0x0093e2ff ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_0093e2ff(uint *param_1,undefined4 *param_2,ushort param_3,int *param_4)

{
  int *piVar1;
  char *_Source;
  bool bVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 in_ECX;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint local_4c;
  char local_48 [63];
  undefined1 local_9;
  undefined4 local_8;
  
  bVar2 = false;
  local_8 = DAT_00b49670;
  *param_4 = 0;
  *(byte *)((int)param_1 + 3) = *(byte *)((int)param_1 + 3) & 0xbf;
  _Source = *(char **)(param_1[0x1a] + 0x18);
  _strncpy(local_48,_Source,0x3f);
  local_9 = 0;
  pcVar4 = local_48;
  cVar3 = local_48[0];
  while (cVar3 != '\0') {
    if (*pcVar4 == '_') goto LAB_0093e35e;
    pcVar4 = pcVar4 + 1;
    cVar3 = *pcVar4;
  }
  if (*pcVar4 == '_') {
LAB_0093e35e:
    *pcVar4 = '\0';
    iVar5 = __stricmp(pcVar4 + 1,s_centroid_00a27ba0);
    if (iVar5 != 0) {
      *param_4 = 1;
      param_1[0x1b] = 0;
      FUN_0091a001(in_ECX,param_1[0x1a],0x1196,s_invalid_input_semantic___s___onl_00a2dad4,_Source);
      goto LAB_0093e527;
    }
    bVar2 = true;
  }
  pcVar4 = local_48;
  if (local_48[0] == '\0') {
LAB_0093e3d3:
    local_4c = 0;
  }
  else {
    do {
      iVar5 = _isalpha((int)*pcVar4);
      if (iVar5 == 0) break;
      pcVar4 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    if (*pcVar4 == '\0') goto LAB_0093e3d3;
    local_4c = _atol(pcVar4);
  }
  if (*pcVar4 != '\0') {
    *pcVar4 = '\0';
    pcVar4 = pcVar4 + 1;
  }
  cVar3 = *pcVar4;
  if (cVar3 == '\0') {
LAB_0093e406:
    local_4c = local_4c + (param_1[0x1c] >> 2);
  }
  else {
    do {
      iVar5 = _isdigit((int)cVar3);
      if (iVar5 == 0) break;
      pcVar4 = pcVar4 + 1;
      cVar3 = *pcVar4;
    } while (cVar3 != '\0');
    if (*pcVar4 == '\0') goto LAB_0093e406;
    local_4c = 0xffffffff;
  }
  uVar6 = FUN_009154c0(param_1);
  puVar8 = (undefined4 *)0x0;
  if (param_2[4] != -1) {
    do {
      iVar5 = __stricmp((char *)*param_2,local_48);
      if ((iVar5 == 0) &&
         (puVar7 = param_2, puVar8 = param_2, (*(ushort *)(param_2 + 1) & param_3) != 0)) break;
      puVar7 = param_2 + 9;
      piVar1 = param_2 + 0xd;
      param_2 = puVar7;
    } while (*piVar1 != -1);
    if ((puVar8 != (undefined4 *)0x0) && (puVar7[4] != -1)) {
      if ((bVar2) && ((*(byte *)(puVar8 + 2) & 1) == 0)) {
        *param_1 = *param_1 | 0x40000000;
      }
      if (puVar8[3] != 0) {
        FUN_0091a096(in_ECX,param_1[0x1a],0x1261,s__s_semantics___s__has_been_depre_00a2da98,uVar6,
                     local_48,puVar8[3],local_4c);
      }
      if ((local_4c < (uint)puVar7[5]) || ((uint)puVar7[6] <= local_4c)) {
        *param_1 = *param_1 | 0x40000000;
      }
      if (param_1[4] < (uint)puVar7[8]) {
        if ((*(ushort *)(puVar8 + 1) & param_3) == 0) {
          *param_1 = *param_1 | 0x40000000;
        }
        param_1[0x1b] = (puVar8[7] + local_4c) * 0x10000 | puVar8[4] & 0xffff;
        if (bVar2) {
          *(byte *)((int)param_1 + 3) = *(byte *)((int)param_1 + 3) | 1;
        }
      }
      else {
        *param_1 = *param_1 | 0x40000000;
        *param_4 = 1;
        FUN_0091a001(in_ECX,param_1[0x1a],0x11cb,s_invalid_type_used_for___s___s_se_00a2da70,
                     local_48,uVar6);
      }
      goto LAB_0093e527;
    }
  }
  *(byte *)((int)param_1 + 3) = *(byte *)((int)param_1 + 3) | 0x40;
  param_1[0x1b] = 0;
LAB_0093e527:
  return *param_4 != 0;
}


// ==== FUN_0093e540 @ 0x0093e540 ====

undefined4 FUN_0093e540(void)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  uint *puVar5;
  int in_ECX;
  uint uVar6;
  int local_14;
  int *local_c;
  uint local_8;
  
  do {
    bVar4 = false;
    local_8 = 0;
    if (*(int *)(in_ECX + 0xc) == 0) break;
    do {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x18) + local_8 * 4);
      local_14 = *(int *)(iVar1 + 4);
      bVar3 = false;
      if (local_14 != 0) {
        local_c = *(int **)(iVar1 + 8);
        do {
          puVar5 = *(uint **)(*(int *)(in_ECX + 0x14) + *local_c * 4);
          if ((*puVar5 & 0x1000000) != 0) {
            bVar3 = true;
          }
          if (puVar5[0xe] != 0xffffffff) {
            puVar5 = *(uint **)(*(int *)(in_ECX + 0x14) + puVar5[0xe] * 4);
          }
          if ((*puVar5 & 0x1000000) != 0) {
            bVar3 = true;
          }
          local_c = local_c + 1;
          local_14 = local_14 + -1;
        } while (local_14 != 0);
        uVar6 = 0;
        if ((bVar3) && (*(int *)(iVar1 + 0xc) != 0)) {
          do {
            puVar5 = *(uint **)(*(int *)(in_ECX + 0x14) +
                               *(int *)(*(int *)(iVar1 + 0x10) + uVar6 * 4) * 4);
            uVar2 = *puVar5;
            if ((uVar2 & 0x1000000) == 0) {
              *puVar5 = uVar2 | 0x1000000;
              bVar4 = true;
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 < *(uint *)(iVar1 + 0xc));
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(in_ECX + 0xc));
  } while (bVar4);
  uVar6 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      puVar5 = *(uint **)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
      if ((puVar5[0xe] != 0xffffffff) &&
         ((**(uint **)(*(int *)(in_ECX + 0x14) + puVar5[0xe] * 4) & 0x1000000) != 0)) {
        *puVar5 = *puVar5 | 0x1000000;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(in_ECX + 8));
  }
  return 0;
}


// ==== FUN_0093e625 @ 0x0093e625 ====

int FUN_0093e625(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int local_8;
  
  if (((**(uint **)(in_ECX + 0x100) & 0xfff00000) == 0x11400000) &&
     ((**(uint **)(in_ECX + 0x100) & 0xfffff) == 1)) {
    if ((*(byte *)(in_ECX + 0x70) & 4) == 0) {
      FUN_0091a001();
      local_8 = -0x7fffbffb;
    }
    else {
      iVar3 = FUN_009149f7();
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_0091455d();
      }
      if (iVar3 == 0) {
        local_8 = -0x7ff8fff2;
      }
      else {
        local_8 = FUN_00914a42(0x74500001,2,1,0);
        if (((local_8 < 0) || (local_8 = FUN_00914593(), local_8 < 0)) ||
           (iVar4 = FUN_00915318(0,0,0,0), iVar4 == -1)) {
          FUN_008f4adb();
        }
        else {
          iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4);
          FUN_00914e44();
          **(undefined4 **)(iVar3 + 0x10) = **(undefined4 **)(*(int *)(in_ECX + 0x100) + 0x10);
          **(undefined4 **)(iVar3 + 8) = **(undefined4 **)(*(int *)(in_ECX + 0x100) + 8);
          *(int *)(*(int *)(iVar3 + 8) + 4) = iVar4;
          if (*(int *)(iVar1 + 0x38) == -1) {
            uVar2 = **(undefined4 **)(*(int *)(in_ECX + 0x100) + 8);
            *(byte *)(iVar1 + 0x3e) = *(byte *)(iVar1 + 0x3e) | 8;
            *(undefined4 *)(iVar1 + 0x38) = uVar2;
          }
          else {
            *(uint *)(iVar1 + 0x3c) = *(uint *)(iVar1 + 0x3c) ^ 0x80000;
          }
          local_8 = FUN_00914ca1();
          FUN_008f4adb();
        }
      }
    }
  }
  else {
    local_8 = 1;
  }
  return local_8;
}


// ==== FUN_0093e78d @ 0x0093e78d ====

uint FUN_0093e78d(void)

{
  undefined4 *puVar1;
  int iVar2;
  bool bVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  int in_ECX;
  uint uVar7;
  int iVar8;
  uint local_14;
  int local_10;
  int *local_c;
  uint local_8;
  
  uVar7 = **(uint **)(in_ECX + 0x100) & 0xfffff;
  if ((**(uint **)(in_ECX + 0x100) & 0xfff00000) == 0x20800000) {
    bVar3 = false;
    local_14 = 0;
    local_10 = 0;
    do {
      local_8 = 0;
      if (uVar7 != 0) {
        local_c = *(int **)(*(int *)(in_ECX + 0x100) + 0x10);
        piVar4 = (int *)(*(int *)(*(int *)(in_ECX + 0x100) + 8) + local_10);
        do {
          iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + *local_c * 4);
          iVar8 = *(int *)(*(int *)(in_ECX + 0x14) + *piVar4 * 4);
          if ((((*(int *)(iVar8 + 4) != *(int *)(iVar2 + 4)) ||
               (*(int *)(iVar8 + 8) != *(int *)(iVar2 + 8))) ||
              (*(int *)(iVar8 + 0xc) != *(int *)(iVar2 + 0xc))) ||
             (*(int *)(iVar8 + 0x10) != *(int *)(iVar2 + 0x10))) break;
          local_8 = local_8 + 1;
          local_c = local_c + 1;
          piVar4 = piVar4 + 1;
        } while (local_8 < uVar7);
      }
      if (local_8 != uVar7) {
        uVar5 = FUN_00915378(uVar7 | 0x10000000,uVar7,uVar7);
        if (uVar5 == 0xffffffff) {
          return 0x8007000e;
        }
        local_c = (int *)0x0;
        iVar2 = *(int *)(*(int *)(in_ECX + 0x18) + uVar5 * 4);
        if (uVar7 != 0) {
          local_8 = local_10;
          do {
            iVar8 = (int)local_c * 4;
            *(undefined4 *)(iVar8 + *(int *)(iVar2 + 8)) =
                 *(undefined4 *)(local_8 + *(int *)(*(int *)(in_ECX + 0x100) + 8));
            uVar6 = FUN_0091541f(*(undefined4 *)
                                  (*(int *)(in_ECX + 0x14) +
                                  *(int *)(iVar8 + *(int *)(*(int *)(in_ECX + 0x100) + 0x10)) * 4));
            *(undefined4 *)(local_8 + *(int *)(*(int *)(in_ECX + 0x100) + 8)) = uVar6;
            *(undefined4 *)(iVar8 + *(int *)(iVar2 + 0x10)) =
                 *(undefined4 *)(local_8 + *(int *)(*(int *)(in_ECX + 0x100) + 8));
            if (*(int *)(iVar8 + *(int *)(iVar2 + 0x10)) == -1) {
              return 0x8007000e;
            }
            local_c = (int *)((int)local_c + 1);
            local_8 = local_8 + 4;
            *(undefined4 *)
             (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar8 + *(int *)(iVar2 + 0x10)) * 4) +
             0x14) = *(undefined4 *)
                      (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar8 + *(int *)(iVar2 + 8)) * 4)
                      + 0x14);
            *(undefined4 *)
             (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar8 + *(int *)(iVar2 + 0x10)) * 4) +
             0x18) = *(undefined4 *)
                      (*(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar8 + *(int *)(iVar2 + 8)) * 4)
                      + 0x18);
          } while (local_c < uVar7);
        }
        while ((*(uint *)(in_ECX + 0xfc) < uVar5 ||
               ((uVar5 != 0 &&
                ((**(uint **)(*(int *)(in_ECX + 0x18) + -4 + uVar5 * 4) & 0xfff00000) == 0x20800000)
                )))) {
          puVar1 = (undefined4 *)(*(int *)(in_ECX + 0x18) + uVar5 * 4);
          *puVar1 = puVar1[-1];
          uVar5 = uVar5 - 1;
        }
        *(int *)(*(int *)(in_ECX + 0x18) + uVar5 * 4) = iVar2;
        *(int *)(in_ECX + 0xfc) = *(int *)(in_ECX + 0xfc) + 1;
        bVar3 = true;
      }
      local_14 = local_14 + 1;
      local_10 = local_10 + uVar7 * 4;
    } while (local_14 < 2);
    uVar7 = (uint)!bVar3;
  }
  else {
    uVar7 = 1;
  }
  return uVar7;
}


// ==== FUN_0093e986 @ 0x0093e986 ====

int FUN_0093e986(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int in_ECX;
  int iVar7;
  int iVar8;
  uint local_c;
  uint local_8;
  
  piVar2 = *(int **)(*(int *)(in_ECX + 0x100) + 0x10);
  piVar3 = *(int **)(in_ECX + 0x14);
  if ((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(piVar3[*piVar2] + 4) * 4) + 4) & 1)
        == 0) || (*(int *)(piVar3[*piVar2] + 0x3c) != 0)) ||
     (*(int *)(piVar3[piVar2[1]] + 0x3c) != 0)) {
    local_c = 0;
    if (*(int *)(in_ECX + 8) != 0) {
      iVar7 = *(int *)(in_ECX + 8);
      do {
        if ((*(int *)(in_ECX + 0x88) == *(int *)(*piVar3 + 4)) &&
           (uVar6 = *(uint *)(*piVar3 + 0xc), local_c <= uVar6)) {
          local_c = uVar6 + 1;
        }
        piVar3 = piVar3 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    iVar7 = FUN_00915378(0x10000004,4,4);
    if (iVar7 == -1) {
      return -0x7ff8fff2;
    }
    iVar7 = *(int *)(*(int *)(in_ECX + 0x18) + iVar7 * 4);
    iVar4 = FUN_00914593();
    if (iVar4 < 0) {
      return iVar4;
    }
    local_8 = 0;
    do {
      iVar4 = FUN_00915318(*(undefined4 *)(in_ECX + 0x88),local_c,local_8,0);
      if (iVar4 == -1) {
        return -0x7ff8fff2;
      }
      iVar8 = local_8 * 4;
      iVar5 = FUN_00914f00();
      if (iVar5 < 0) {
        return iVar5;
      }
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4) + 0x18) =
           *(undefined4 *)
            (*(int *)(*(int *)(in_ECX + 0x14) +
                     *(int *)(iVar8 + *(int *)(*(int *)(in_ECX + 0x100) + 0x10)) * 4) + 0x18);
      local_8 = local_8 + 1;
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar4 * 4) + 0x14) =
           *(undefined4 *)
            (*(int *)(*(int *)(in_ECX + 0x14) +
                     *(int *)(iVar8 + *(int *)(*(int *)(in_ECX + 0x100) + 0x10)) * 4) + 0x14);
      *(undefined4 *)(iVar8 + *(int *)(iVar7 + 0x10)) =
           *(undefined4 *)(iVar8 + *(int *)(*(int *)(in_ECX + 0x100) + 0x10));
      *(int *)(iVar8 + *(int *)(*(int *)(in_ECX + 0x100) + 0x10)) = iVar4;
      *(int *)(iVar8 + *(int *)(iVar7 + 8)) = iVar4;
    } while (local_8 < 4);
    uVar6 = *(int *)(in_ECX + 0xc) - 1;
    while (uVar6 = uVar6 - 1, *(uint *)(in_ECX + 0xfc) < uVar6) {
      puVar1 = (undefined4 *)(*(int *)(in_ECX + 0x18) + uVar6 * 4);
      puVar1[1] = *puVar1;
    }
    *(int *)(*(int *)(in_ECX + 0x18) + 4 + *(uint *)(in_ECX + 0xfc) * 4) = iVar7;
  }
  *(undefined4 *)(in_ECX + 0x18c) = 1;
  return 0;
}


// ==== FUN_0093eb26 @ 0x0093eb26 ====

void FUN_0093eb26(uint *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar3 = param_1;
  uVar1 = *param_1;
  param_1 = (uint *)(param_1[1] / (uVar1 & 0xfffff));
  if (param_1 != (uint *)0x0) {
    iVar5 = param_2 << 2;
    do {
      puVar4 = (undefined4 *)(puVar3[2] + iVar5);
      uVar2 = *puVar4;
      *puVar4 = puVar4[1];
      *(undefined4 *)(puVar3[2] + 4 + iVar5) = uVar2;
      iVar5 = iVar5 + (uVar1 & 0xfffff) * 4;
      param_1 = (uint *)((int)param_1 - 1);
    } while (param_1 != (uint *)0x0);
  }
  puVar4 = (undefined4 *)(puVar3[4] + param_2 * 4);
  uVar2 = *puVar4;
  *puVar4 = puVar4[1];
  *(undefined4 *)(puVar3[4] + 4 + param_2 * 4) = uVar2;
  return;
}


// ==== FUN_0093eb91 @ 0x0093eb91 ====

undefined4 FUN_0093eb91(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  uint local_8;
  
  uVar5 = **(uint **)(in_ECX + 0x100) & 0xfffff;
  if ((((uVar5 == (*(uint **)(in_ECX + 0x100))[3]) && (iVar2 = FUN_009145ef(), iVar2 == 0)) &&
      ((iVar2 = FUN_009147e7(), iVar2 == 0 || (iVar2 = FUN_0091467d(), iVar2 != 0)))) &&
     ((uVar5 < 5 && (uVar5 != 0)))) {
    local_8 = 0;
    if (uVar5 != 0) {
      do {
        uVar4 = 0;
        if (uVar5 - local_8 != 1) {
          do {
            piVar1 = (int *)(*(int *)(*(int *)(in_ECX + 0x100) + 0x10) + uVar4 * 4);
            if (*(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + piVar1[1] * 4) + 0x10) <
                *(uint *)(*(int *)(*(int *)(in_ECX + 0x14) + *piVar1 * 4) + 0x10)) {
              FUN_0093eb26(*(undefined4 *)(in_ECX + 0x100),uVar4);
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < (uVar5 - local_8) - 1);
        }
        local_8 = local_8 + 1;
      } while (local_8 < uVar5);
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


// ==== FUN_0093ec43 @ 0x0093ec43 ====

int FUN_0093ec43(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int local_4c [4];
  int local_3c [4];
  int local_2c;
  int local_28;
  uint local_24;
  undefined4 local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  puVar1 = *(uint **)(in_ECX + 0x100);
  uVar8 = *puVar1 & 0xfffff;
  if (((uVar8 != 0) && (puVar1[1] != 0)) && (puVar1[3] != 0)) {
    local_24 = puVar1[1] / uVar8;
    local_8 = 0;
    if (local_24 != 0) {
      iVar3 = *(int *)(in_ECX + 0x14);
      piVar6 = (int *)puVar1[2];
      local_1c = local_24;
      local_10 = uVar8;
      do {
        iVar5 = *(int *)(*(int *)(iVar3 + *piVar6 * 4) + 8);
        if ((iVar5 != -1) &&
           (uVar8 = local_10,
           (*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                              *(int *)(*(int *)(iVar3 + iVar5 * 4) + 4) * 4) + 4) & 4) == 0)) {
          piVar9 = local_4c + local_8;
          local_8 = local_8 + 1;
          *piVar9 = iVar5;
        }
        piVar6 = piVar6 + uVar8;
        local_1c = local_1c - 1;
      } while (local_1c != 0);
      uVar7 = 0;
      if (local_8 != 0) {
        local_1c = 0;
        if (local_8 != 0) {
          do {
            if (local_8 == 1) {
              uVar2 = 3;
            }
            else {
              uVar2 = uVar7;
            }
            iVar3 = FUN_00915318(*(undefined4 *)(in_ECX + 0x8c),0,uVar2,0);
            local_3c[uVar7] = iVar3;
            if (iVar3 == -1) {
              return -0x7ff8fff2;
            }
            iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4);
            *(undefined4 *)(iVar3 + 0x14) =
                 *(undefined4 *)
                  (*(int *)(*(int *)(in_ECX + 0x14) +
                           **(int **)(*(int *)(in_ECX + 0x100) + 0x10) * 4) + 0x14);
            uVar7 = uVar7 + 1;
            *(undefined4 *)(iVar3 + 0x18) =
                 *(undefined4 *)
                  (*(int *)(*(int *)(in_ECX + 0x14) +
                           **(int **)(*(int *)(in_ECX + 0x100) + 0x10) * 4) + 0x18);
          } while (uVar7 < local_8);
        }
        local_8 = 0;
        local_1c = 0;
        local_14 = 0;
        do {
          iVar3 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                   *(int *)(local_14 + *(int *)(*(int *)(in_ECX + 0x100) + 8)) * 4)
                          + 8);
          if ((iVar3 != -1) &&
             ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                                 *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4) + 4) * 4) +
                        4) & 4) == 0)) {
            local_18 = 0;
            if (uVar8 != 0) {
              local_c = local_14;
              do {
                local_20 = *(undefined4 *)
                            (*(int *)(in_ECX + 0x14) +
                            *(int *)(local_c + *(int *)(*(int *)(in_ECX + 0x100) + 8)) * 4);
                iVar3 = FUN_00915318(0,0,0,0);
                if (iVar3 == -1) {
                  return -0x7ff8fff2;
                }
                iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4);
                local_2c = iVar3;
                iVar4 = FUN_00914e44();
                if (iVar4 < 0) {
                  return iVar4;
                }
                if (*(int *)(iVar5 + 0x38) != -1) {
                  iVar3 = FUN_00915318(0,0,0,0);
                  if (iVar3 == -1) {
                    return -0x7ff8fff2;
                  }
                  local_28 = *(int *)(*(int *)(in_ECX + 0x14) + iVar3 * 4);
                  FUN_00914e44();
                  iVar4 = local_3c[local_8];
                  *(int *)(iVar5 + 0x38) = iVar3;
                  *(int *)(local_28 + 8) = iVar4;
                  iVar3 = local_2c;
                }
                local_18 = local_18 + 1;
                iVar4 = local_c + 4;
                *(int *)(iVar5 + 8) = local_3c[local_8];
                *(int *)(local_c + *(int *)(*(int *)(in_ECX + 0x100) + 8)) = iVar3;
                local_c = iVar4;
              } while (local_18 < local_10);
              uVar8 = local_10;
            }
            local_8 = local_8 + 1;
          }
          local_1c = local_1c + 1;
          local_14 = local_14 + uVar8 * 4;
          if (local_24 <= local_1c) {
            iVar3 = FUN_009149f7();
            if (iVar3 == 0) {
              local_14 = 0;
            }
            else {
              local_14 = FUN_0091455d();
            }
            iVar3 = local_14;
            if (local_14 == 0) {
              return -0x7ff8fff2;
            }
            iVar5 = FUN_00914a42(local_8 & 0xfffff | 0x10000000,local_8,local_8,0);
            if ((-1 < iVar5) && (iVar5 = FUN_00914593(), -1 < iVar5)) {
              piVar6 = local_3c;
              piVar9 = *(int **)(iVar3 + 0x10);
              for (uVar8 = local_8 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
                *piVar9 = *piVar6;
                piVar6 = piVar6 + 1;
                piVar9 = piVar9 + 1;
              }
              for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                *(char *)piVar9 = (char)*piVar6;
                piVar6 = (int *)((int)piVar6 + 1);
                piVar9 = (int *)((int)piVar9 + 1);
              }
              piVar6 = local_4c;
              piVar9 = *(int **)(local_14 + 8);
              for (uVar8 = local_8 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
                *piVar9 = *piVar6;
                piVar6 = piVar6 + 1;
                piVar9 = piVar9 + 1;
              }
              for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                *(char *)piVar9 = (char)*piVar6;
                piVar6 = (int *)((int)piVar6 + 1);
                piVar9 = (int *)((int)piVar9 + 1);
              }
              iVar5 = FUN_00915205();
              if (-1 < iVar5) {
                return 0;
              }
            }
            FUN_008f4adb();
            return iVar5;
          }
        } while( true );
      }
    }
  }
  return 1;
}


// ==== FUN_0093ef49 @ 0x0093ef49 ====

int FUN_0093ef49(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  int in_ECX;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  int local_278 [40];
  int local_1d8 [40];
  int local_138 [40];
  undefined1 local_98 [16];
  int local_88 [16];
  uint local_48 [5];
  int local_34;
  undefined4 *local_30;
  int local_2c;
  int local_28;
  uint *local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_48[0] = 0;
  local_24 = *(uint **)(in_ECX + 0x100);
  local_48[1] = 1;
  local_48[2] = 2;
  local_48[3] = 3;
  if (((*local_24 & 0xfffff) == 1) &&
     ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                         *(int *)(*(int *)(*(int *)(in_ECX + 0x14) + *(int *)local_24[4] * 4) + 4) *
                         4) + 4) & 0x20) == 0)) {
    local_18 = *local_24 & 0xfffff;
    if ((local_18 < 2) && ((*local_24 & 0xfff00000) == 0x10500000)) {
      local_28 = 0;
      local_10 = in_ECX;
      do {
        local_20 = 0;
        do {
          piVar5 = local_1d8;
          for (iVar4 = 0x28; iVar4 != 0; iVar4 = iVar4 + -1) {
            *piVar5 = -1;
            piVar5 = piVar5 + 1;
          }
          iVar6 = 0;
          piVar5 = local_278;
          for (iVar4 = 0x28; iVar4 != 0; iVar4 = iVar4 + -1) {
            *piVar5 = -1;
            piVar5 = piVar5 + 1;
          }
          local_14 = 0;
          local_c = 0;
          local_8 = 0;
          do {
            if (local_20 == 0) {
              uVar9 = local_8;
            }
            else {
              uVar9 = 1 - local_8;
            }
            uVar1 = local_24[2];
            uVar9 = *(uint *)(&DAT_00a2cec4 + uVar9 * 4);
            piVar5 = (int *)(uVar1 + iVar6 * 4);
            if (uVar9 < 0x10) {
              iVar4 = *(int *)(*(int *)(*(int *)(local_10 + 0x14) + *piVar5 * 4) + 0x48);
              if (iVar4 != -1) {
                uVar2 = *(undefined4 *)(*(int *)(local_10 + 0x18) + iVar4 * 4);
                iVar4 = FUN_0093d27f(uVar2,piVar5,local_18,local_48,local_98,
                                     *(undefined4 *)(&DAT_00a2ced0 + uVar9 * 0x20),0);
                if (iVar4 == 0) {
                  local_c = FUN_0093d430(uVar2,&DAT_00a2ceb8 + uVar9 * 0x20,local_88,&local_14,
                                         local_278,local_98,1,0);
                  goto LAB_0093f0d2;
                }
              }
              local_c = 1;
              break;
            }
            uVar8 = 0;
            piVar5 = local_1d8 + (uVar9 - 0x10) * 4;
            do {
              if (local_48[uVar8] < local_18) {
                *piVar5 = *(int *)(uVar1 + (local_48[uVar8] + iVar6) * 4);
              }
              else {
                *piVar5 = -1;
              }
              uVar8 = uVar8 + 1;
              piVar5 = piVar5 + 1;
            } while (uVar8 < 4);
LAB_0093f0d2:
            if (local_c == 1) break;
            local_8 = local_8 + 1;
            iVar6 = iVar6 + local_18;
          } while (local_8 == 0);
          if ((0xf < *(uint *)(&DAT_00a2cec4 + (uint)(local_20 != 0) * 4)) &&
             (local_8 = 0, local_14 != 0)) {
            do {
              uVar9 = 0;
              if (local_18 != 0) {
                uVar1 = *(uint *)(local_88[local_8] + 0xc);
                do {
                  local_1c = 0;
                  if (uVar1 != 0) {
                    piVar5 = *(int **)(local_88[local_8] + 0x10);
                    do {
                      if (*(int *)(local_24[2] + uVar9 * 4) == *piVar5) {
                        local_c = 1;
                        goto LAB_0093f153;
                      }
                      local_1c = local_1c + 1;
                      piVar5 = piVar5 + 1;
                    } while (local_1c < uVar1);
                  }
                  uVar9 = uVar9 + 1;
                } while (uVar9 < local_18);
              }
LAB_0093f153:
              local_8 = local_8 + 1;
            } while (local_8 < local_14);
          }
          if (local_c == 0) {
            if (local_28 != 0) goto LAB_0093f2df;
            local_1c = 0;
            if (local_14 != 0) {
              do {
                local_48[4] = *(uint *)(local_88[local_1c] + 0xc);
                local_8 = 0;
                if (local_48[4] != 0) {
                  do {
                    if (*(int *)(local_10 + 0xc) != 0) {
                      local_30 = *(undefined4 **)(local_10 + 0x18);
                      local_34 = *(int *)(local_10 + 0xc);
                      do {
                        puVar3 = (uint *)*local_30;
                        if ((puVar3 != (uint *)0x0) && (*puVar3 != 0)) {
                          uVar9 = puVar3[1];
                          local_2c = 0;
                          if (uVar9 != 0) {
                            iVar4 = *(int *)(*(int *)(local_88[local_1c] + 0x10) + local_8 * 4);
                            piVar5 = (int *)puVar3[2];
                            do {
                              if ((*piVar5 == iVar4) ||
                                 (*(int *)(*(int *)(*(int *)(local_10 + 0x14) + *piVar5 * 4) + 0x38)
                                  == iVar4)) {
                                local_2c = 1;
                              }
                              piVar5 = piVar5 + 1;
                              uVar9 = uVar9 - 1;
                            } while (uVar9 != 0);
                          }
                          if (puVar3 == local_24) {
                            iVar4 = 0;
                          }
                          else {
                            iVar4 = local_2c;
                          }
                          if (iVar4 != 0) {
                            uVar9 = 0;
                            do {
                              if (puVar3 == (uint *)local_88[uVar9]) {
                                iVar4 = 0;
                              }
                              uVar9 = uVar9 + 1;
                            } while (uVar9 < local_14);
                            if (iVar4 != 0) {
                              local_c = 1;
                            }
                          }
                        }
                        local_30 = local_30 + 1;
                        local_34 = local_34 + -1;
                      } while (local_34 != 0);
                    }
                    local_8 = local_8 + 1;
                  } while (local_8 < local_48[4]);
                }
                local_1c = local_1c + 1;
              } while (local_1c < local_14);
            }
            local_8 = 0;
            do {
              iVar4 = local_1d8[local_8];
              if ((iVar4 != -1) && (uVar9 = 0, local_14 != 0)) {
                do {
                  iVar6 = *(int *)(local_88[uVar9] + 0xc);
                  if (iVar6 != 0) {
                    piVar5 = *(int **)(local_88[uVar9] + 0x10);
                    do {
                      if ((iVar4 == *piVar5) ||
                         (*(int *)(*(int *)(*(int *)(local_10 + 0x14) + iVar4 * 4) + 0x38) ==
                          *piVar5)) {
                        local_c = 1;
                      }
                      piVar5 = piVar5 + 1;
                      iVar6 = iVar6 + -1;
                    } while (iVar6 != 0);
                  }
                  uVar9 = uVar9 + 1;
                } while (uVar9 < local_14);
              }
              local_8 = local_8 + 1;
            } while (local_8 < 0x28);
            if (local_c == 0) goto LAB_0093f2df;
          }
          local_20 = local_20 + 1;
        } while (local_20 == 0);
        if (local_c == 0) {
LAB_0093f2df:
          local_88[local_14] = (int)local_24;
          uVar9 = 0;
          do {
            iVar4 = *(int *)((int)local_1d8 + uVar9);
            if ((iVar4 != -1) || (iVar4 = *(int *)((int)local_278 + uVar9), iVar4 != -1)) {
              *(int *)((int)local_138 + uVar9) = iVar4;
            }
            uVar9 = uVar9 + 4;
          } while (uVar9 < 0xa0);
          local_c = 0;
LAB_0093f31b:
          if (local_c != 0) {
            return local_c;
          }
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
          iVar6 = FUN_00914a42(0x70d00001,2,1,0);
          if ((-1 < iVar6) && (iVar6 = FUN_00914593(*(undefined4 *)(local_10 + 0x100)), -1 < iVar6))
          {
            puVar7 = *(undefined4 **)(*(int *)(local_10 + 0x100) + 0x10);
            puVar10 = *(undefined4 **)(iVar4 + 0x10);
            for (uVar9 = *(uint *)(*(int *)(local_10 + 0x100) + 0xc) & 0x3fffffff; uVar9 != 0;
                uVar9 = uVar9 - 1) {
              *puVar10 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar10 = puVar10 + 1;
            }
            for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
              *(undefined1 *)puVar10 = *(undefined1 *)puVar7;
              puVar7 = (undefined4 *)((int)puVar7 + 1);
              puVar10 = (undefined4 *)((int)puVar10 + 1);
            }
            **(undefined4 **)(iVar4 + 8) = local_138[4];
            *(int *)(*(int *)(iVar4 + 8) + 4) = local_138[0];
            iVar6 = FUN_00914ca1(iVar4);
          }
          FUN_008f4adb(1);
          return iVar6;
        }
        local_28 = local_28 + 1;
        if (local_28 != 0) goto LAB_0093f31b;
      } while( true );
    }
  }
  return 1;
}


// ==== FUN_0093f3d2 @ 0x0093f3d2 ====

undefined4 FUN_0093f3d2(void)

{
  undefined4 uVar1;
  int in_ECX;
  uint uVar2;
  int iVar3;
  uint local_8;
  
  uVar2 = **(uint **)(in_ECX + 0x100) & 0xfffff;
  if ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) +
                         *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                          *(int *)(*(int *)(*(int *)(in_ECX + 0x14) +
                                                           *(int *)(*(uint **)(in_ECX + 0x100))[2] *
                                                           4) + 0x30) * 4) + 4) * 4) + 4) & 0x80) ==
      0) {
    uVar1 = 1;
  }
  else {
    local_8 = 0;
    if (uVar2 != 0) {
      do {
        iVar3 = local_8 * 4;
        local_8 = local_8 + 1;
        *(undefined4 *)
         (*(int *)(*(int *)(in_ECX + 0x14) +
                  *(int *)(iVar3 + *(int *)(*(int *)(in_ECX + 0x100) + 0x10)) * 4) + 0x30) =
             *(undefined4 *)
              (*(int *)(*(int *)(in_ECX + 0x14) +
                       *(int *)(iVar3 + *(int *)(*(int *)(in_ECX + 0x100) + 8)) * 4) + 0x30);
      } while (local_8 < uVar2);
    }
    **(undefined4 **)(in_ECX + 0x100) = 0;
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0093f455 @ 0x0093f455 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0093f455(int *param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  uint *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int *piVar11;
  uint *puVar12;
  undefined4 local_128 [16];
  int local_e8 [4];
  uint local_d8 [4];
  int aiStack_c8 [4];
  uint auStack_b8 [28];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  uint local_30;
  int local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  uVar5 = **(uint **)(in_ECX + 0x100) & 0xfffff;
  local_10 = 0;
  local_38 = 0;
  local_48 = 0;
  local_44 = 1;
  local_40 = 2;
  local_3c = 3;
  if ((**(uint **)(in_ECX + 0x100) & 0xfff00000) != 0x30000000) {
    return 1;
  }
  local_1c = 0;
  local_28 = 0;
  local_24 = 0;
  local_2c = 0;
  local_c = 0;
  if (uVar5 == 0) {
LAB_0093f6ef:
    uVar6 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2c378,local_128,&local_38,local_e8,
                         &local_48,uVar5,param_1 == (int *)0x0);
    if (uVar6 != 0) {
      return uVar6;
    }
    bVar2 = false;
    local_1c = 0;
    local_c = 0;
LAB_0093f734:
    local_8 = 0;
LAB_0093f738:
    local_30 = 0;
    if (uVar5 != 0) {
      iVar3 = *(int *)(in_ECX + 0x14);
      do {
        local_24 = local_e8[local_c * 4 + local_30];
        local_18 = local_d8[local_30 + local_c * -4];
        local_28 = auStack_b8[local_30 - local_8];
        iVar4 = aiStack_c8[local_8 + local_30];
        local_14 = *(uint *)(iVar3 + local_28 * 4);
        local_20 = *(uint *)(*(int *)(in_ECX + 0x10) +
                            *(int *)(*(int *)(iVar3 + local_18 * 4) + 4) * 4);
        local_34 = *(int *)(*(int *)(in_ECX + 0x10) + *(int *)(local_14 + 4) * 4);
        local_2c = *(int *)(*(int *)(iVar3 + local_24 * 4) + 0x38);
        if ((((local_2c == iVar4) ||
             (iVar1 = *(int *)(*(int *)(iVar3 + iVar4 * 4) + 0x38), iVar1 == local_24)) ||
            ((local_2c != -1 && (local_2c == iVar1)))) &&
           (((*(uint *)(*(int *)(iVar3 + local_24 * 4) + 0x3c) ^ 0x80000) ==
             *(uint *)(*(int *)(iVar3 + iVar4 * 4) + 0x3c) && (local_18 == local_28)))) {
          bVar2 = true;
LAB_0093f856:
          iVar4 = 0;
        }
        else {
          if (local_24 != iVar4) {
LAB_0093f854:
            bVar2 = false;
            goto LAB_0093f856;
          }
          iVar4 = *(int *)(iVar3 + local_18 * 4);
          uVar6 = *(uint *)(iVar4 + 0x38);
          if (((((uVar6 != local_28) && (*(uint *)(local_14 + 0x38) != local_18)) &&
               ((uVar6 == 0xffffffff || (uVar6 != *(uint *)(local_14 + 0x38))))) ||
              ((*(uint *)(iVar4 + 0x3c) ^ 0x80000) != *(uint *)(local_14 + 0x3c))) &&
             ((((*(uint *)(local_20 + 4) & 0x100) == 0 || ((*(uint *)(local_34 + 4) & 0x100) == 0))
              || (*(double *)(local_14 + 0x20) != -*(double *)(iVar4 + 0x20))))) goto LAB_0093f854;
          iVar4 = 1;
          bVar2 = true;
        }
        if (local_30 == 0) {
          local_1c = iVar4;
        }
        else if (local_1c != iVar4) {
          bVar2 = false;
        }
        if (!bVar2) goto LAB_0093f87f;
        local_30 = local_30 + 1;
      } while (local_30 < uVar5);
    }
    if (!bVar2) goto LAB_0093f87f;
    iVar3 = FUN_009149f7(0x74);
    if (iVar3 == 0) {
      local_10 = 0;
    }
    else {
      local_10 = FUN_0091455d();
    }
    if (local_10 == 0) {
      return 0x8007000e;
    }
    if (local_1c == 0) {
      if (local_c == 0) goto LAB_0093fa14;
LAB_0093fa42:
      if (local_c == 1) goto LAB_0093f8fb;
    }
    else {
      if (local_c == 1) {
LAB_0093fa14:
        local_8 = FUN_00914a42(uVar5 | 0x70b00000,uVar5 * 2,uVar5,0);
        if ((int)local_8 < 0) goto LAB_0093f8a1;
        if (local_1c == 0) goto LAB_0093fa42;
      }
      if (local_c == 0) {
LAB_0093f8fb:
        local_8 = FUN_00914a42(uVar5 | 0x70c00000,uVar5 * 2,uVar5,0);
        if ((int)local_8 < 0) goto LAB_0093f8a1;
      }
    }
    local_8 = FUN_00914593(*(undefined4 *)(in_ECX + 0x100));
    if (-1 < (int)local_8) {
      local_14 = uVar5 * 4;
      puVar9 = *(undefined4 **)(*(int *)(in_ECX + 0x100) + 0x10);
      puVar10 = *(undefined4 **)(local_10 + 0x10);
      for (uVar6 = uVar5; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      local_20 = local_c * 0x10;
      piVar7 = local_e8 + local_c * 4;
      piVar11 = *(int **)(local_10 + 8);
      for (uVar6 = uVar5; uVar6 != 0; uVar6 = uVar6 - 1) {
        *piVar11 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar11 = piVar11 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(char *)piVar11 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar11 = (int *)((int)piVar11 + 1);
      }
      puVar8 = local_d8 + local_c * -4;
      puVar12 = (uint *)(*(int *)(local_10 + 8) + uVar5 * 4);
      for (uVar6 = uVar5; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar12 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar12 = puVar12 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(char *)puVar12 = (char)*puVar8;
        puVar8 = (uint *)((int)puVar8 + 1);
        puVar12 = (uint *)((int)puVar12 + 1);
      }
      iVar3 = *(int *)(in_ECX + 0x14);
      local_20 = *(uint *)(iVar3 + (*(int **)(local_10 + 8))[uVar5] * 4);
      iVar4 = *(int *)(iVar3 + **(int **)(local_10 + 8) * 4);
      iVar3 = *(int *)(iVar3 + **(int **)(local_10 + 0x10) * 4);
      if (((*(int *)(iVar3 + 4) == *(int *)(iVar4 + 4)) &&
          (*(int *)(iVar3 + 0xc) == *(int *)(iVar4 + 0xc))) ||
         ((*(int *)(iVar3 + 4) == *(int *)(local_20 + 4) &&
          (*(int *)(iVar3 + 0xc) == *(int *)(local_20 + 0xc))))) goto LAB_0093f89a;
      if (param_1 != (int *)0x0) {
        *param_1 = local_10;
        if (local_38 != 0) {
          puVar9 = local_128;
          for (iVar3 = local_38; iVar3 != 0; iVar3 = iVar3 + -1) {
            *param_2 = *puVar9;
            puVar9 = puVar9 + 1;
            param_2 = param_2 + 1;
          }
        }
        *param_3 = local_38;
        return local_8;
      }
      goto LAB_0093f6d3;
    }
    goto LAB_0093f8a1;
  }
  iVar3 = *(int *)(*(int *)(in_ECX + 0x100) + 8);
  local_14 = uVar5 << 2;
  local_20 = uVar5 << 3;
  local_18 = local_14;
  local_8 = local_20;
  do {
    iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar3 + local_18) * 4);
    local_34 = *(int *)(*(int *)(in_ECX + 0x14) + *(int *)(iVar3 + local_8) * 4);
    local_30 = *(uint *)(*(int *)(in_ECX + 0x10) + *(int *)(local_34 + 4) * 4);
    if (((((*(byte *)(*(int *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar4 + 4) * 4) + 5) & 1) == 0) ||
         (*(double *)(iVar4 + 0x20) != _DAT_0099d098)) || (*(int *)(iVar4 + 8) != -1)) ||
       (iVar4 = *(int *)(*(int *)(in_ECX + 0x100) + 8),
       *(int *)(iVar4 + local_8) != *(int *)(iVar4 + local_c * 4))) {
      local_24 = 1;
    }
    else {
      local_1c = 1;
    }
    if ((((*(byte *)(local_30 + 5) & 1) == 0) || (*(double *)(local_34 + 0x20) != _DAT_0099d098)) ||
       ((*(int *)(local_34 + 8) != -1 ||
        (iVar4 = *(int *)(*(int *)(in_ECX + 0x100) + 8),
        *(int *)(iVar4 + local_18) != *(int *)(iVar4 + local_c * 4))))) {
      local_2c = 1;
    }
    else {
      local_28 = 1;
    }
    local_c = local_c + 1;
    local_8 = local_8 + 4;
    local_18 = local_18 + 4;
  } while (local_c < uVar5);
  if ((local_1c == 0) || (local_24 != 0)) {
    if ((local_28 == 0) || (local_2c != 0)) goto LAB_0093f6ef;
    if (param_1 != (int *)0x0) {
      return 1;
    }
    iVar3 = FUN_009149f7(0x74);
    if (iVar3 == 0) {
      local_10 = 0;
    }
    else {
      local_10 = FUN_0091455d();
    }
    if (local_10 == 0) {
      return 0x8007000e;
    }
    uVar6 = uVar5 | 0x70c00000;
  }
  else {
    iVar3 = FUN_009149f7(0x74);
    if (iVar3 == 0) {
      local_10 = 0;
    }
    else {
      local_10 = FUN_0091455d();
    }
    if (local_10 == 0) {
      return 0x8007000e;
    }
    uVar6 = uVar5 | 0x70b00000;
  }
  local_8 = FUN_00914a42(uVar6,uVar5 * 2,uVar5,0);
  if ((-1 < (int)local_8) &&
     (local_8 = FUN_00914593(*(undefined4 *)(in_ECX + 0x100)), -1 < (int)local_8)) {
    puVar9 = *(undefined4 **)(*(int *)(in_ECX + 0x100) + 0x10);
    puVar10 = *(undefined4 **)(local_10 + 0x10);
    for (uVar5 = local_14 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    for (uVar5 = local_14 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    puVar9 = *(undefined4 **)(*(int *)(in_ECX + 0x100) + 8);
    puVar10 = *(undefined4 **)(local_10 + 8);
    for (uVar5 = local_14 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    for (uVar5 = local_14 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    uVar5 = local_14;
    if (local_1c == 0) {
      uVar5 = local_20;
    }
    puVar9 = (undefined4 *)(*(int *)(*(int *)(in_ECX + 0x100) + 8) + uVar5);
    puVar10 = (undefined4 *)(*(int *)(local_10 + 8) + local_14);
    for (uVar6 = local_14 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    for (uVar5 = local_14 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
LAB_0093f6d3:
    local_8 = FUN_00914ca1(local_10);
  }
LAB_0093f8a1:
  if (local_10 != 0) {
    FUN_008f4adb(1);
  }
  return local_8;
LAB_0093f87f:
  local_8 = local_8 + 4;
  if (7 < local_8) goto code_r0x0093f88d;
  goto LAB_0093f738;
code_r0x0093f88d:
  local_c = local_c + 1;
  if (1 < local_c) goto LAB_0093f89a;
  goto LAB_0093f734;
LAB_0093f89a:
  local_8 = 1;
  goto LAB_0093f8a1;
}


// ==== FUN_0093fa51 @ 0x0093fa51 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0093fa51(int *param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *piVar10;
  undefined4 *puVar11;
  undefined4 local_138 [16];
  int local_f8 [4];
  int local_e8 [4];
  int local_d8 [4];
  int local_c8 [4];
  int local_b8 [24];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  int local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int local_2c;
  int *local_28;
  int local_24;
  int *local_20;
  int *local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  uVar7 = **(uint **)(in_ECX + 0x100) & 0xfffff;
  local_2c = 0;
  local_58 = 0;
  local_8 = 0;
  local_24 = 0;
  local_54 = 1;
  local_50 = 2;
  local_4c = 3;
  local_14 = in_ECX;
  iVar4 = FUN_0093d430(*(uint **)(in_ECX + 0x100),&DAT_00a2c3d8,local_138,&local_2c,local_f8,
                       &local_58,uVar7,param_1 == (int *)0x0);
  if (iVar4 != 0) {
    local_24 = 1;
    iVar4 = FUN_0093d430(*(undefined4 *)(in_ECX + 0x100),&DAT_00a2c458,local_138,&local_2c,local_f8,
                         &local_58,uVar7,param_1 == (int *)0x0);
    if (iVar4 != 0) {
      return iVar4;
    }
  }
  local_c = 0;
  local_3c = local_e8;
  local_40 = local_d8;
LAB_0093fb17:
  local_18 = 0;
  local_38 = local_c8;
  local_28 = local_b8;
LAB_0093fb2d:
  local_10 = 0;
  if (uVar7 != 0) {
    iVar4 = *(int *)(in_ECX + 0x14);
    local_34 = local_40;
    local_20 = local_28;
    local_1c = local_38;
    local_30 = local_3c;
    do {
      local_48 = *(int *)(iVar4 + local_f8[local_10] * 4);
      iVar1 = *(int *)(iVar4 + *local_30 * 4);
      local_44 = *(int *)(iVar4 + *local_1c * 4);
      if (((((*(int *)(iVar1 + 8) != -1) || (*(int *)(local_48 + 8) != -1)) ||
           (*(int *)(local_44 + 8) != -1)) ||
          ((iVar2 = *(int *)(in_ECX + 0x10),
           (*(byte *)(*(int *)(iVar2 + *(int *)(iVar1 + 4) * 4) + 5) & 1) == 0 ||
           ((*(byte *)(*(int *)(iVar2 + *(int *)(local_44 + 4) * 4) + 5) & 1) == 0)))) ||
         (((*(byte *)(*(int *)(iVar2 + *(int *)(local_48 + 4) * 4) + 5) & 1) == 0 ||
          ((_DAT_00a2db38 <
            ABS((*(double *)(local_44 + 0x20) - *(double *)(iVar1 + 0x20)) -
                *(double *)(local_48 + 0x20)) || (*local_34 != *local_20)))))) break;
      local_10 = local_10 + 1;
      local_30 = local_30 + 1;
      local_1c = local_1c + 1;
      local_20 = local_20 + 1;
      local_34 = local_34 + 1;
    } while (local_10 < uVar7);
  }
  if (local_10 != uVar7) goto code_r0x0093fc00;
  iVar4 = FUN_009149f7(0x74);
  if (iVar4 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_0091455d();
  }
  if (local_8 == 0) {
    return -0x7ff8fff2;
  }
  if (local_24 == 0) {
    uVar5 = uVar7 | 0x70b00000;
  }
  else {
    if (param_1 != (int *)0x0) goto LAB_0093fc29;
    uVar5 = uVar7 | 0x70c00000;
  }
  iVar4 = FUN_00914a42(uVar5,uVar7 * 2,uVar7,0);
  if ((-1 < iVar4) &&
     (iVar4 = FUN_00914593(*(undefined4 *)(in_ECX + 0x100)), iVar1 = local_8, -1 < iVar4)) {
    uVar5 = uVar7 * 4;
    local_c = uVar5;
    puVar11 = *(undefined4 **)(*(int *)(in_ECX + 0x100) + 0x10);
    puVar9 = *(undefined4 **)(local_8 + 0x10);
    for (uVar6 = uVar7; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar9 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar9 = puVar9 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar9 = *(undefined1 *)puVar11;
      puVar11 = (undefined4 *)((int)puVar11 + 1);
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    piVar8 = local_f8;
    piVar10 = *(int **)(local_8 + 8);
    for (uVar6 = uVar7; uVar6 != 0; uVar6 = uVar6 - 1) {
      *piVar10 = *piVar8;
      piVar8 = piVar8 + 1;
      piVar10 = piVar10 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(char *)piVar10 = (char)*piVar8;
      piVar8 = (int *)((int)piVar8 + 1);
      piVar10 = (int *)((int)piVar10 + 1);
    }
    puVar11 = (undefined4 *)(*(int *)(local_8 + 8) + uVar5);
    if (local_24 == 0) {
      uVar5 = uVar7 * 8;
    }
    puVar9 = (undefined4 *)(*(int *)(*(int *)(local_14 + 0x100) + 8) + uVar5);
    for (uVar6 = uVar7; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar11 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    iVar4 = *(int *)(local_14 + 0x14);
    iVar2 = *(int *)(iVar4 + (*(int **)(local_8 + 8))[uVar7] * 4);
    iVar3 = *(int *)(iVar4 + **(int **)(local_8 + 8) * 4);
    iVar4 = *(int *)(iVar4 + **(int **)(local_8 + 0x10) * 4);
    if (((*(int *)(iVar4 + 4) != *(int *)(iVar3 + 4)) ||
        (*(int *)(iVar4 + 0xc) != *(int *)(iVar3 + 0xc))) &&
       ((*(int *)(iVar4 + 4) != *(int *)(iVar2 + 4) ||
        (*(int *)(iVar4 + 0xc) != *(int *)(iVar2 + 0xc))))) {
      if (param_1 == (int *)0x0) {
        FUN_00914ca1(local_8);
      }
      else {
        local_8 = 0;
        *param_1 = iVar1;
        if (local_2c != 0) {
          puVar11 = local_138;
          for (iVar4 = local_2c; iVar4 != 0; iVar4 = iVar4 + -1) {
            *param_2 = *puVar11;
            puVar11 = puVar11 + 1;
            param_2 = param_2 + 1;
          }
        }
        *param_3 = local_2c;
      }
      iVar4 = 0;
      goto LAB_0093fc2c;
    }
    goto LAB_0093fc29;
  }
  goto LAB_0093fc2c;
code_r0x0093fc00:
  local_18 = local_18 + 1;
  local_28 = local_28 + -4;
  local_38 = local_38 + 4;
  if (1 < local_18) goto code_r0x0093fc16;
  goto LAB_0093fb2d;
code_r0x0093fc16:
  local_c = local_c + 1;
  local_40 = local_40 + -4;
  local_3c = local_3c + 4;
  if (1 < local_c) {
LAB_0093fc29:
    iVar4 = 1;
LAB_0093fc2c:
    if (local_8 != 0) {
      FUN_008f4adb(1);
    }
    return iVar4;
  }
  goto LAB_0093fb17;
}


// ==== FUN_0093fdb0 @ 0x0093fdb0 ====

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0093fdb0(void)

{
  byte *pbVar1;
  undefined4 uVar2;
  int iVar3;
  byte bVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int in_ECX;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  int *piVar11;
  uint *puVar12;
  uint *puVar13;
  uint *puVar14;
  uint **ppuVar15;
  undefined4 *puVar16;
  uint uVar17;
  uint uVar18;
  undefined4 *puVar19;
  bool bVar20;
  int local_2d0 [40];
  uint local_230 [40];
  uint auStack_190 [40];
  uint *local_f0 [16];
  uint local_b0 [16];
  uint local_70 [4];
  int local_60 [4];
  uint *local_50;
  int local_4c;
  uint local_48;
  uint *local_44;
  uint local_40;
  uint *local_3c;
  uint *local_38;
  uint *local_34;
  uint *local_30;
  uint *local_2c;
  uint *local_28;
  uint *local_24;
  uint *local_20;
  uint *local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint *local_c;
  uint *local_8;
  
  puVar14 = *(uint **)(in_ECX + 0x100);
  local_c = (uint *)(*puVar14 & 0xfffff);
  local_30 = (uint *)(*puVar14 & 0xfffff);
  local_1c = (uint *)0x0;
  local_48 = 0;
  local_44 = (uint *)0x0;
  local_60[0] = 0;
  local_60[1] = 1;
  local_60[2] = 2;
  local_60[3] = 3;
  local_4c = 0;
  local_18 = in_ECX;
  if ((local_c <= (uint *)(*puVar14 & 0xfffff)) && ((*puVar14 & 0xfff00000) == 0x20000000)) {
    local_2c = (uint *)0x0;
LAB_0093fe1d:
    local_10 = 0;
    do {
      puVar12 = local_230;
      for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar12 = 0xffffffff;
        puVar12 = puVar12 + 1;
      }
      piVar11 = local_2d0;
      for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
        *piVar11 = -1;
        piVar11 = piVar11 + 1;
      }
      local_20 = (uint *)0x0;
      local_14 = 0;
      local_40 = 0;
      local_28 = (uint *)0x0;
      do {
        if (local_10 == 0) {
          uVar17 = local_40;
        }
        else {
          uVar17 = 1 - local_40;
        }
        uVar10 = puVar14[2];
        uVar17 = *(uint *)(&DAT_00a2c324 + uVar17 * 4);
        piVar11 = (int *)(uVar10 + (int)local_28 * 4);
        if (uVar17 < 0x10) {
          iVar8 = *(int *)(*(int *)(*(int *)(local_18 + 0x14) + *piVar11 * 4) + 0x48);
          if (iVar8 != -1) {
            uVar2 = *(undefined4 *)(*(int *)(local_18 + 0x18) + iVar8 * 4);
            iVar8 = FUN_0093d27f(uVar2,piVar11,local_c,local_60,local_70,
                                 *(undefined4 *)(&DAT_00a2c330 + uVar17 * 0x20),0);
            if (iVar8 == 0) {
              local_14 = FUN_0093d430(uVar2,&DAT_00a2c318 + uVar17 * 0x20,local_b0,&local_20,
                                      local_2d0,local_70,local_30,0);
              goto LAB_0093ff20;
            }
          }
          local_14 = 1;
          break;
        }
        uVar18 = 0;
        puVar12 = local_230 + (uVar17 - 0x10) * 4;
        do {
          if ((uint *)local_60[uVar18] < local_c) {
            *puVar12 = *(uint *)(uVar10 + (local_60[uVar18] + (int)local_28) * 4);
          }
          else {
            *puVar12 = 0xffffffff;
          }
          uVar18 = uVar18 + 1;
          puVar12 = puVar12 + 1;
        } while (uVar18 < 4);
LAB_0093ff20:
        if (local_14 == 1) break;
        local_40 = local_40 + 1;
        local_28 = (uint *)((int)local_28 + (int)local_c);
      } while (local_40 < 2);
      puVar12 = local_20;
      local_40 = 0;
      local_38 = (uint *)0x0;
      do {
        if (local_10 == 0) {
          uVar17 = local_40;
        }
        else {
          uVar17 = 1 - local_40;
        }
        if ((0xf < *(uint *)(&DAT_00a2c324 + uVar17 * 4)) &&
           (local_28 = (uint *)0x0, local_20 != (uint *)0x0)) {
          do {
            puVar13 = (uint *)0x0;
            if (local_c != (uint *)0x0) {
              uVar17 = local_b0[(int)local_28];
              puVar5 = *(uint **)(uVar17 + 0xc);
              do {
                local_8 = (uint *)0x0;
                if (puVar5 != (uint *)0x0) {
                  piVar11 = *(int **)(uVar17 + 0x10);
                  do {
                    if (*(int *)(puVar14[2] + ((int)local_38 + (int)puVar13) * 4) == *piVar11) {
                      local_14 = 1;
                      goto LAB_0093ffbb;
                    }
                    local_8 = (uint *)((int)local_8 + 1);
                    puVar5 = *(uint **)(uVar17 + 0xc);
                    piVar11 = piVar11 + 1;
                  } while (local_8 < puVar5);
                }
                puVar13 = (uint *)((int)puVar13 + 1);
              } while (puVar13 < local_c);
            }
LAB_0093ffbb:
            local_28 = (uint *)((int)local_28 + 1);
          } while (local_28 < local_20);
        }
        local_40 = local_40 + 1;
        local_38 = (uint *)((int)local_38 + (int)local_c);
      } while (local_40 < 2);
      if (local_14 == 0) {
        if (local_2c != (uint *)0x0) goto LAB_0094016e;
        local_28 = (uint *)0x0;
        if (local_20 != (uint *)0x0) {
          do {
            local_3c = *(uint **)(local_b0[(int)local_28] + 0xc);
            local_38 = (uint *)0x0;
            if (local_3c != (uint *)0x0) {
              do {
                if (*(uint **)(local_18 + 0xc) != (uint *)0x0) {
                  local_8 = *(uint **)(local_18 + 0x18);
                  local_34 = *(uint **)(local_18 + 0xc);
                  do {
                    puVar13 = (uint *)*local_8;
                    if ((puVar13 != (uint *)0x0) && (*puVar13 != 0)) {
                      local_40 = 0;
                      if ((uint *)puVar13[1] != (uint *)0x0) {
                        iVar8 = *(int *)(*(int *)(local_b0[(int)local_28] + 0x10) +
                                        (int)local_38 * 4);
                        piVar11 = (int *)puVar13[2];
                        local_24 = (uint *)puVar13[1];
                        do {
                          if ((*piVar11 == iVar8) ||
                             (*(int *)(*(int *)(*(int *)(local_18 + 0x14) + *piVar11 * 4) + 0x38) ==
                              iVar8)) {
                            local_40 = 1;
                          }
                          piVar11 = piVar11 + 1;
                          local_24 = (uint *)((int)local_24 + -1);
                        } while (local_24 != (uint *)0x0);
                      }
                      if (puVar13 == puVar14) {
                        local_40 = 0;
                      }
                      if (local_40 != 0) {
                        puVar5 = (uint *)0x0;
                        do {
                          if (puVar13 == (uint *)local_b0[(int)puVar5]) {
                            local_40 = 0;
                          }
                          puVar5 = (uint *)((int)puVar5 + 1);
                        } while (puVar5 < local_20);
                        if (local_40 != 0) {
                          local_14 = 1;
                        }
                      }
                    }
                    local_8 = local_8 + 1;
                    local_34 = (uint *)((int)local_34 + -1);
                  } while (local_34 != (uint *)0x0);
                }
                local_38 = (uint *)((int)local_38 + 1);
              } while (local_38 < local_3c);
            }
            local_28 = (uint *)((int)local_28 + 1);
          } while (local_28 < local_20);
        }
        local_38 = (uint *)0x0;
        do {
          uVar17 = local_230[(int)local_38];
          if ((uVar17 != 0xffffffff) && (puVar13 = (uint *)0x0, local_20 != (uint *)0x0)) {
            local_3c = *(uint **)(*(int *)(local_18 + 0x14) + uVar17 * 4);
            do {
              puVar5 = *(uint **)(local_b0[(int)puVar13] + 0xc);
              if (puVar5 != (uint *)0x0) {
                puVar9 = *(uint **)(local_b0[(int)puVar13] + 0x10);
                local_34 = puVar5;
                do {
                  if ((uVar17 == *puVar9) || (local_3c[0xe] == *puVar9)) {
                    local_14 = 1;
                  }
                  puVar9 = puVar9 + 1;
                  local_34 = (uint *)((int)local_34 + -1);
                } while (local_34 != (uint *)0x0);
              }
              puVar13 = (uint *)((int)puVar13 + 1);
            } while (puVar13 < local_20);
          }
          local_38 = (uint *)((int)local_38 + 1);
        } while (local_38 < (uint *)0x28);
        if (local_14 == 0) goto LAB_0094016e;
      }
      local_10 = local_10 + 1;
    } while (local_10 < 2);
    if (local_14 != 0) goto code_r0x0094015f;
LAB_0094016e:
    puVar13 = local_b0;
    ppuVar15 = local_f0;
    for (uVar17 = (uint)local_20 & 0x3fffffff; uVar17 != 0; uVar17 = uVar17 - 1) {
      *ppuVar15 = (uint *)*puVar13;
      puVar13 = puVar13 + 1;
      ppuVar15 = ppuVar15 + 1;
    }
    for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(char *)ppuVar15 = (char)*puVar13;
      puVar13 = (uint *)((int)puVar13 + 1);
      ppuVar15 = (uint **)((int)ppuVar15 + 1);
    }
    local_f0[(int)puVar12] = puVar14;
    local_44 = (uint *)((int)local_20 + 1);
    uVar17 = 0;
    do {
      iVar8 = *(int *)((int)local_230 + uVar17);
      if ((iVar8 != -1) || (iVar8 = *(int *)((int)local_2d0 + uVar17), iVar8 != -1)) {
        *(int *)((int)auStack_190 + uVar17) = iVar8;
      }
      uVar17 = uVar17 + 4;
    } while (uVar17 < 0xa0);
    local_14 = 0;
LAB_009401cd:
    iVar8 = local_14;
    if (local_14 == 1) goto LAB_009401d9;
    goto LAB_009405ca;
  }
LAB_009401d9:
  local_8 = *(uint **)(local_18 + 0x100);
  uVar17 = **(uint **)(local_18 + 0x100);
  local_20 = (uint *)(uVar17 & 0xfffff);
  if ((local_20 <= local_30) && ((uVar17 & 0xfff00000) == 0x20100000)) {
    local_38 = (uint *)0x0;
    local_40 = (int)local_44 << 2;
LAB_00940218:
    local_28 = (uint *)0x0;
    do {
      uVar17 = local_40;
      ppuVar15 = local_f0;
      puVar14 = local_b0;
      for (uVar10 = local_40 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *puVar14 = (uint)*ppuVar15;
        ppuVar15 = ppuVar15 + 1;
        puVar14 = puVar14 + 1;
      }
      for (uVar17 = uVar17 & 3; uVar17 != 0; uVar17 = uVar17 - 1) {
        *(undefined1 *)puVar14 = *(undefined1 *)ppuVar15;
        ppuVar15 = (uint **)((int)ppuVar15 + 1);
        puVar14 = (uint *)((int)puVar14 + 1);
      }
      puVar14 = local_230;
      for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar14 = 0xffffffff;
        puVar14 = puVar14 + 1;
      }
      piVar11 = local_2d0;
      for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
        *piVar11 = -1;
        piVar11 = piVar11 + 1;
      }
      iVar8 = 0;
      local_c = local_44;
      local_14 = 0;
      local_10 = 0;
      do {
        if (local_28 == (uint *)0x0) {
          uVar17 = local_10;
        }
        else {
          uVar17 = 1 - local_10;
        }
        uVar10 = local_8[2];
        uVar17 = *(uint *)(&DAT_00a2c2c4 + uVar17 * 4);
        piVar11 = (int *)(uVar10 + iVar8 * 4);
        if (uVar17 < 0x10) {
          iVar7 = *(int *)(*(int *)(*(int *)(local_18 + 0x14) + *piVar11 * 4) + 0x48);
          if (iVar7 != -1) {
            uVar2 = *(undefined4 *)(*(int *)(local_18 + 0x18) + iVar7 * 4);
            iVar7 = FUN_0093d27f(uVar2,piVar11,local_20,local_60,local_70,
                                 *(undefined4 *)(&DAT_00a2c2d0 + uVar17 * 0x20),0);
            if (iVar7 == 0) {
              local_14 = FUN_0093d430(uVar2,&DAT_00a2c2b8 + uVar17 * 0x20,local_b0,&local_c,
                                      local_2d0,local_70,local_30,0);
              goto LAB_00940329;
            }
          }
          local_14 = 1;
          break;
        }
        uVar18 = 0;
        puVar14 = local_230 + (uVar17 - 0x10) * 4;
        do {
          if ((uint *)local_60[uVar18] < local_20) {
            *puVar14 = *(uint *)(uVar10 + (iVar8 + local_60[uVar18]) * 4);
          }
          else {
            *puVar14 = 0xffffffff;
          }
          uVar18 = uVar18 + 1;
          puVar14 = puVar14 + 1;
        } while (uVar18 < 4);
LAB_00940329:
        if (local_14 == 1) break;
        local_10 = local_10 + 1;
        iVar8 = iVar8 + (int)local_20;
      } while (local_10 < 2);
      local_10 = 0;
      local_1c = (uint *)0x0;
      do {
        if (local_28 == (uint *)0x0) {
          uVar17 = local_10;
        }
        else {
          uVar17 = 1 - local_10;
        }
        if ((0xf < *(uint *)(&DAT_00a2c2c4 + uVar17 * 4)) &&
           (local_2c = (uint *)0x0, local_c != (uint *)0x0)) {
          do {
            puVar14 = (uint *)0x0;
            if (local_20 != (uint *)0x0) {
              puVar12 = *(uint **)(local_b0[(int)local_2c] + 0xc);
              do {
                local_24 = (uint *)0x0;
                if (puVar12 != (uint *)0x0) {
                  piVar11 = *(int **)(local_b0[(int)local_2c] + 0x10);
                  do {
                    if (*(int *)(local_8[2] + ((int)local_1c + (int)puVar14) * 4) == *piVar11) {
                      local_14 = 1;
                      goto LAB_009403c0;
                    }
                    local_24 = (uint *)((int)local_24 + 1);
                    piVar11 = piVar11 + 1;
                  } while (local_24 < puVar12);
                }
                puVar14 = (uint *)((int)puVar14 + 1);
              } while (puVar14 < local_20);
            }
LAB_009403c0:
            local_2c = (uint *)((int)local_2c + 1);
          } while (local_2c < local_c);
        }
        local_10 = local_10 + 1;
        local_1c = (uint *)((int)local_1c + (int)local_20);
      } while (local_10 < 2);
      if (local_14 == 0) {
        if (local_38 != (uint *)0x0) goto LAB_0094055f;
        local_1c = (uint *)0x0;
        if (local_c != (uint *)0x0) {
          do {
            local_3c = *(uint **)(local_b0[(int)local_1c] + 0xc);
            local_2c = (uint *)0x0;
            if (local_3c != (uint *)0x0) {
              do {
                if (*(uint *)(local_18 + 0xc) != 0) {
                  local_24 = *(uint **)(local_18 + 0x18);
                  local_10 = *(uint *)(local_18 + 0xc);
                  do {
                    puVar14 = (uint *)*local_24;
                    if ((puVar14 != (uint *)0x0) && (*puVar14 != 0)) {
                      uVar17 = puVar14[1];
                      local_34 = (uint *)0x0;
                      if (uVar17 != 0) {
                        iVar8 = *(int *)(*(int *)(local_b0[(int)local_1c] + 0x10) +
                                        (int)local_2c * 4);
                        piVar11 = (int *)puVar14[2];
                        do {
                          if ((*piVar11 == iVar8) ||
                             (*(int *)(*(int *)(*(int *)(local_18 + 0x14) + *piVar11 * 4) + 0x38) ==
                              iVar8)) {
                            local_34 = (uint *)0x1;
                          }
                          piVar11 = piVar11 + 1;
                          uVar17 = uVar17 - 1;
                        } while (uVar17 != 0);
                      }
                      if (puVar14 == local_8) {
                        puVar12 = (uint *)0x0;
                      }
                      else {
                        puVar12 = local_34;
                      }
                      if (puVar12 != (uint *)0x0) {
                        puVar13 = (uint *)0x0;
                        do {
                          if (puVar14 == (uint *)local_b0[(int)puVar13]) {
                            puVar12 = (uint *)0x0;
                          }
                          puVar13 = (uint *)((int)puVar13 + 1);
                        } while (puVar13 < local_c);
                        if (puVar12 != (uint *)0x0) {
                          local_14 = 1;
                        }
                      }
                    }
                    local_24 = local_24 + 1;
                    local_10 = local_10 - 1;
                  } while (local_10 != 0);
                }
                local_2c = (uint *)((int)local_2c + 1);
              } while (local_2c < local_3c);
            }
            local_1c = (uint *)((int)local_1c + 1);
          } while (local_1c < local_c);
        }
        local_2c = (uint *)0x0;
        do {
          uVar17 = local_230[(int)local_2c];
          if ((uVar17 != 0xffffffff) && (puVar14 = (uint *)0x0, local_c != (uint *)0x0)) {
            do {
              iVar8 = *(int *)(local_b0[(int)puVar14] + 0xc);
              if (iVar8 != 0) {
                puVar12 = *(uint **)(local_b0[(int)puVar14] + 0x10);
                do {
                  if ((uVar17 == *puVar12) ||
                     (*(uint *)(*(int *)(*(int *)(local_18 + 0x14) + uVar17 * 4) + 0x38) == *puVar12
                     )) {
                    local_14 = 1;
                  }
                  puVar12 = puVar12 + 1;
                  iVar8 = iVar8 + -1;
                } while (iVar8 != 0);
              }
              puVar14 = (uint *)((int)puVar14 + 1);
            } while (puVar14 < local_c);
          }
          local_2c = (uint *)((int)local_2c + 1);
        } while (local_2c < (uint *)0x28);
        if (local_14 == 0) goto LAB_0094055f;
      }
      local_28 = (uint *)((int)local_28 + 1);
    } while (local_28 < (uint *)0x2);
    if (local_14 != 0) goto code_r0x00940550;
LAB_0094055f:
    puVar14 = local_b0;
    ppuVar15 = local_f0;
    for (uVar17 = (uint)local_c & 0x3fffffff; uVar17 != 0; uVar17 = uVar17 - 1) {
      *ppuVar15 = (uint *)*puVar14;
      puVar14 = puVar14 + 1;
      ppuVar15 = ppuVar15 + 1;
    }
    for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(char *)ppuVar15 = (char)*puVar14;
      puVar14 = (uint *)((int)puVar14 + 1);
      ppuVar15 = (uint **)((int)ppuVar15 + 1);
    }
    local_f0[(int)local_c] = local_8;
    local_44 = (uint *)((int)local_c + 1);
    uVar17 = 0;
    do {
      iVar8 = *(int *)((int)local_230 + uVar17);
      if ((iVar8 != -1) || (iVar8 = *(int *)((int)local_2d0 + uVar17), iVar8 != -1)) {
        *(int *)((int)auStack_190 + uVar17) = iVar8;
      }
      uVar17 = uVar17 + 4;
    } while (uVar17 < 0xa0);
    local_14 = 0;
LAB_009405c0:
    iVar8 = local_14;
    goto LAB_009405c3;
  }
  iVar8 = 1;
LAB_009405c3:
  local_1c = (uint *)0x1;
LAB_009405ca:
  if (iVar8 == 0) {
    local_8 = (uint *)0x0;
    local_c = (uint *)0x0;
    puVar14 = auStack_190;
    do {
      puVar14 = puVar14 + 4;
      local_24 = (uint *)0x0;
      if (local_30 == (uint *)0x0) {
LAB_00940645:
        local_8 = auStack_190 + (int)local_c * -4 + 8;
        break;
      }
      local_34 = local_30;
      puVar12 = puVar14;
      do {
        iVar8 = *(int *)(*(int *)(local_18 + 0x14) + *puVar12 * 4);
        if ((((*(byte *)(*(int *)(*(int *)(local_18 + 0x10) + *(int *)(iVar8 + 4) * 4) + 5) & 1) ==
              0) || (*(int *)(iVar8 + 8) != -1)) ||
           (*(double *)(iVar8 + 0x20) != (double)(int)local_1c)) {
          local_24 = (uint *)0x1;
        }
        puVar12 = puVar12 + 1;
        local_34 = (uint *)((int)local_34 + -1);
      } while (local_34 != (uint *)0x0);
      if (local_24 == (uint *)0x0) goto LAB_00940645;
      local_c = (uint *)((int)local_c + 1);
    } while (local_c < (uint *)0x2);
    puVar14 = (uint *)0x0;
    local_34 = (uint *)0x0;
    if (local_30 != (uint *)0x0) {
      do {
        iVar8 = *(int *)(*(int *)(local_18 + 0x14) + auStack_190[(int)puVar14] * 4);
        if ((((*(byte *)(*(int *)(*(int *)(local_18 + 0x10) + *(int *)(iVar8 + 4) * 4) + 5) & 1) !=
              0) && (*(int *)(iVar8 + 8) == -1)) &&
           (*(double *)(iVar8 + 0x20) == (double)(int)local_1c)) {
          local_34 = (uint *)0x1;
        }
        puVar14 = (uint *)((int)puVar14 + 1);
      } while (puVar14 < local_30);
      if (local_34 != (uint *)0x0) {
        local_8 = (uint *)0x0;
      }
    }
    puVar14 = (uint *)0x0;
    if (local_8 == (uint *)0x0) goto LAB_009419f7;
    puVar12 = local_8;
    if (local_30 != (uint *)0x0) {
      iVar8 = *(int *)(local_18 + 0x14);
      uVar17 = local_48;
      do {
        iVar7 = *(int *)(iVar8 + puVar12[(int)puVar14] * 4);
        uVar10 = 0;
        if (uVar17 != 0) {
          do {
            if (*(int *)(iVar7 + 0x48) == local_60[uVar10]) break;
            uVar10 = uVar10 + 1;
          } while (uVar10 < uVar17);
          puVar12 = local_8;
        }
        if (uVar10 == uVar17) {
          local_60[uVar17] = *(int *)(iVar7 + 0x48);
          uVar17 = uVar17 + 1;
        }
        puVar14 = (uint *)((int)puVar14 + 1);
      } while (puVar14 < local_30);
      local_48 = uVar17;
    }
    local_20 = puVar12;
LAB_00941888:
    local_8 = (uint *)0x0;
    if (local_48 != 0) {
      do {
        if ((local_60[(int)local_8] == -1) ||
           (puVar14 = *(uint **)(*(int *)(local_18 + 0x18) + local_60[(int)local_8] * 4),
           (*puVar14 & 0xf0000000) == 0x60000000)) goto LAB_009419db;
        puVar12 = (uint *)puVar14[3];
        puVar13 = (uint *)0x0;
        local_1c = (uint *)0x0;
        if (local_30 != (uint *)0x0) {
          do {
            if (puVar12 != (uint *)0x0) {
              puVar5 = (uint *)puVar14[4];
              local_3c = puVar12;
              do {
                if (*puVar5 == local_20[(int)puVar13]) {
                  local_1c = (uint *)((int)local_1c + 1);
                }
                puVar5 = puVar5 + 1;
                local_3c = (uint *)((int)local_3c + -1);
              } while (local_3c != (uint *)0x0);
            }
            puVar13 = (uint *)((int)puVar13 + 1);
          } while (puVar13 < local_30);
        }
        if (local_1c != puVar12) {
          local_4c = 1;
          break;
        }
        local_8 = (uint *)((int)local_8 + 1);
      } while (local_8 < local_48);
    }
    puVar14 = (uint *)0x0;
    if (local_4c == 0) {
      uVar10 = 0;
      uVar17 = 0xffffffff;
      if (local_30 != (uint *)0x0) {
        do {
          iVar8 = *(int *)(*(int *)(local_18 + 0x14) + local_20[(int)puVar14] * 4);
          uVar18 = *(uint *)(iVar8 + 0x58);
          if (uVar10 < uVar18) {
            uVar10 = uVar18;
          }
          uVar18 = *(uint *)(iVar8 + 0x54);
          if (uVar18 < uVar17) {
            uVar17 = uVar18;
          }
          puVar14 = (uint *)((int)puVar14 + 1);
        } while (puVar14 < local_30);
      }
      if (*(uint **)(local_18 + 0xc) != (uint *)0x0) {
        local_1c = *(uint **)(local_18 + 0x18);
        local_34 = *(uint **)(local_18 + 0xc);
        do {
          puVar14 = (uint *)*local_1c;
          if (*puVar14 != 0) {
            puVar12 = (uint *)0x0;
            bVar20 = local_44 == (uint *)0x0;
            if (local_44 != (uint *)0x0) {
              do {
                if (puVar14 == local_f0[(int)puVar12]) break;
                puVar12 = (uint *)((int)puVar12 + 1);
              } while (puVar12 < local_44);
              bVar20 = puVar12 == local_44;
            }
            if ((bVar20) && ((uint *)puVar14[1] != (uint *)0x0)) {
              puVar12 = (uint *)puVar14[2];
              local_3c = (uint *)puVar14[1];
              do {
                puVar14 = (uint *)0x0;
                if (local_30 != (uint *)0x0) {
                  do {
                    if ((local_20[(int)puVar14] == *puVar12) ||
                       (*(uint *)(*(int *)(*(int *)(local_18 + 0x14) + *puVar12 * 4) + 0x38) ==
                        local_20[(int)puVar14])) {
                      local_4c = 1;
                    }
                    puVar14 = (uint *)((int)puVar14 + 1);
                  } while (puVar14 < local_30);
                }
                puVar12 = puVar12 + 1;
                local_3c = (uint *)((int)local_3c + -1);
              } while (local_3c != (uint *)0x0);
            }
          }
          local_1c = local_1c + 1;
          local_34 = (uint *)((int)local_34 + -1);
        } while (local_34 != (uint *)0x0);
        if (local_4c != 0) goto LAB_009419db;
      }
      local_3c = (uint *)0x0;
      if (local_48 != 0) {
        do {
          iVar8 = *(int *)(*(int *)(local_18 + 0x18) + local_60[(int)local_3c] * 4);
          local_50 = *(uint **)(*(int *)(local_18 + 0x100) + 0xc);
          local_c = (uint *)0x0;
          if (local_50 != (uint *)0x0) {
            do {
              local_1c = (uint *)0x0;
              if (*(int *)(iVar8 + 0xc) != 0) {
                do {
                  if (*(uint *)(*(int *)(iVar8 + 0x10) + (int)local_1c * 4) ==
                      local_20[(int)local_c]) {
                    *(undefined4 *)(*(int *)(iVar8 + 0x10) + (int)local_1c * 4) =
                         *(undefined4 *)
                          (*(int *)(*(int *)(local_18 + 0x100) + 0x10) + (int)local_c * 4);
                    pbVar1 = (byte *)(*(int *)(*(int *)(local_18 + 0x14) +
                                              *(int *)(*(int *)(iVar8 + 0x10) + (int)local_1c * 4) *
                                              4) + 0x3d);
                    *pbVar1 = *pbVar1 | 2;
                  }
                  local_1c = (uint *)((int)local_1c + 1);
                } while (local_1c < *(uint *)(iVar8 + 0xc));
              }
              local_c = (uint *)((int)local_c + 1);
            } while (local_c < local_50);
          }
          local_3c = (uint *)((int)local_3c + 1);
        } while (local_3c < local_48);
      }
      puVar14 = (uint *)0x0;
      if (local_44 != (uint *)0x0) {
        do {
          *local_f0[(int)puVar14] = 0;
          puVar14 = (uint *)((int)puVar14 + 1);
        } while (puVar14 < local_44);
      }
    }
    else {
LAB_009419db:
      iVar8 = FUN_009149f7(0x74);
      if (iVar8 == 0) {
        iVar8 = 0;
      }
      else {
        iVar8 = FUN_0091455d();
      }
      if (iVar8 == 0) goto LAB_009419f7;
      iVar7 = FUN_00914a42((uint)local_30 & 0xfffff | 0x10000000,local_30,local_30,0);
      if ((iVar7 < 0) || (iVar7 = FUN_00914593(*(undefined4 *)(local_18 + 0x100)), iVar7 < 0)) {
        FUN_008f4adb(1);
        return iVar7;
      }
      puVar14 = local_20;
      puVar12 = *(uint **)(iVar8 + 8);
      for (uVar17 = (uint)local_30 & 0x3fffffff; uVar17 != 0; uVar17 = uVar17 - 1) {
        *puVar12 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar12 = puVar12 + 1;
      }
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(char *)puVar12 = (char)*puVar14;
        puVar14 = (uint *)((int)puVar14 + 1);
        puVar12 = (uint *)((int)puVar12 + 1);
      }
      puVar16 = *(undefined4 **)(*(int *)(local_18 + 0x100) + 0x10);
      puVar19 = *(undefined4 **)(iVar8 + 0x10);
      for (uVar17 = (uint)local_30 & 0x3fffffff; uVar17 != 0; uVar17 = uVar17 - 1) {
        *puVar19 = *puVar16;
        puVar16 = puVar16 + 1;
        puVar19 = puVar19 + 1;
      }
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(undefined1 *)puVar19 = *(undefined1 *)puVar16;
        puVar16 = (undefined4 *)((int)puVar16 + 1);
        puVar19 = (undefined4 *)((int)puVar19 + 1);
      }
      puVar14 = (uint *)0x0;
      if (local_30 != (uint *)0x0) {
        do {
          pbVar1 = (byte *)(*(int *)(*(int *)(local_18 + 0x14) +
                                    *(int *)(*(int *)(iVar8 + 0x10) + (int)puVar14 * 4) * 4) + 0x3d)
          ;
          *pbVar1 = *pbVar1 | 2;
          puVar14 = (uint *)((int)puVar14 + 1);
        } while (puVar14 < local_30);
      }
      puVar14 = (uint *)0x0;
      if (local_44 != (uint *)0x0) {
        do {
          ppuVar15 = local_f0 + (int)puVar14;
          puVar14 = (uint *)((int)puVar14 + 1);
          **ppuVar15 = 0;
        } while (puVar14 < local_44);
      }
      piVar11 = (int *)(local_18 + 0xfc);
      if (*(int *)(*(int *)(local_18 + 0x18) + *piVar11 * 4) != 0) {
        FUN_008f4adb(1);
      }
      *(int *)(*(int *)(local_18 + 0x18) + *piVar11 * 4) = iVar8;
    }
    iVar8 = 0;
  }
  else {
    local_38 = *(uint **)(local_18 + 0x100);
    local_c = (uint *)(*local_38 & 0xfffff);
    local_30 = (uint *)(*local_38 & 0xfffff);
    local_3c = (uint *)0x1;
    if ((local_c <= (uint *)(*local_38 & 0xfffff)) && ((*local_38 & 0xfff00000) == 0x30000000)) {
      local_2c = (uint *)0x0;
      local_40 = (int)local_44 << 2;
LAB_0094074b:
      local_28 = (uint *)0x0;
      do {
        uVar17 = local_40;
        ppuVar15 = local_f0;
        puVar14 = local_b0;
        for (uVar10 = local_40 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *puVar14 = (uint)*ppuVar15;
          ppuVar15 = ppuVar15 + 1;
          puVar14 = puVar14 + 1;
        }
        for (uVar17 = uVar17 & 3; uVar17 != 0; uVar17 = uVar17 - 1) {
          *(undefined1 *)puVar14 = *(undefined1 *)ppuVar15;
          ppuVar15 = (uint **)((int)ppuVar15 + 1);
          puVar14 = (uint *)((int)puVar14 + 1);
        }
        puVar14 = local_230;
        for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar14 = 0xffffffff;
          puVar14 = puVar14 + 1;
        }
        piVar11 = local_2d0;
        for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
          *piVar11 = -1;
          piVar11 = piVar11 + 1;
        }
        iVar8 = 0;
        local_20 = local_44;
        local_14 = 0;
        local_10 = 0;
        do {
          if (local_28 == (uint *)0x0) {
            uVar17 = local_10;
          }
          else {
            uVar17 = 1 - local_10;
          }
          uVar10 = local_38[2];
          uVar17 = *(uint *)(&DAT_00a2c0c4 + uVar17 * 4);
          piVar11 = (int *)(uVar10 + iVar8 * 4);
          if (uVar17 < 0x10) {
            iVar7 = *(int *)(*(int *)(*(int *)(local_18 + 0x14) + *piVar11 * 4) + 0x48);
            if (iVar7 != -1) {
              uVar2 = *(undefined4 *)(*(int *)(local_18 + 0x18) + iVar7 * 4);
              iVar7 = FUN_0093d27f(uVar2,piVar11,local_c,local_60,local_70,
                                   *(undefined4 *)(&DAT_00a2c0d0 + uVar17 * 0x20),0);
              if (iVar7 == 0) {
                local_14 = FUN_0093d430(uVar2,&DAT_00a2c0b8 + uVar17 * 0x20,local_b0,&local_20,
                                        local_2d0,local_70,local_30,0);
                goto LAB_0094085c;
              }
            }
            local_14 = 1;
            break;
          }
          uVar18 = 0;
          puVar14 = local_230 + (uVar17 - 0x10) * 4;
          do {
            if ((uint *)local_60[uVar18] < local_c) {
              *puVar14 = *(uint *)(uVar10 + (iVar8 + local_60[uVar18]) * 4);
            }
            else {
              *puVar14 = 0xffffffff;
            }
            uVar18 = uVar18 + 1;
            puVar14 = puVar14 + 1;
          } while (uVar18 < 4);
LAB_0094085c:
          if (local_14 == 1) break;
          local_10 = local_10 + 1;
          iVar8 = iVar8 + (int)local_c;
        } while (local_10 < 3);
        puVar14 = local_20;
        local_10 = 0;
        local_24 = (uint *)0x0;
        do {
          if (local_28 == (uint *)0x0) {
            uVar17 = local_10;
          }
          else {
            uVar17 = 1 - local_10;
          }
          if ((0xf < *(uint *)(&DAT_00a2c0c4 + uVar17 * 4)) &&
             (local_8 = (uint *)0x0, local_20 != (uint *)0x0)) {
            do {
              puVar12 = (uint *)0x0;
              if (local_c != (uint *)0x0) {
                puVar13 = *(uint **)(local_b0[(int)local_8] + 0xc);
                do {
                  local_1c = (uint *)0x0;
                  if (puVar13 != (uint *)0x0) {
                    piVar11 = *(int **)(local_b0[(int)local_8] + 0x10);
                    do {
                      if (*(int *)(local_38[2] + ((int)local_24 + (int)puVar12) * 4) == *piVar11) {
                        local_14 = 1;
                        goto LAB_009408f3;
                      }
                      local_1c = (uint *)((int)local_1c + 1);
                      piVar11 = piVar11 + 1;
                    } while (local_1c < puVar13);
                  }
                  puVar12 = (uint *)((int)puVar12 + 1);
                } while (puVar12 < local_c);
              }
LAB_009408f3:
              local_8 = (uint *)((int)local_8 + 1);
            } while (local_8 < local_20);
          }
          local_10 = local_10 + 1;
          local_24 = (uint *)((int)local_24 + (int)local_c);
        } while (local_10 < 3);
        if (local_14 == 0) {
          if (local_2c != (uint *)0x0) goto LAB_00940a92;
          local_1c = (uint *)0x0;
          if (local_20 != (uint *)0x0) {
            do {
              local_50 = *(uint **)(local_b0[(int)local_1c] + 0xc);
              local_8 = (uint *)0x0;
              if (local_50 != (uint *)0x0) {
                do {
                  if (*(uint *)(local_18 + 0xc) != 0) {
                    local_24 = *(uint **)(local_18 + 0x18);
                    local_10 = *(uint *)(local_18 + 0xc);
                    do {
                      puVar12 = (uint *)*local_24;
                      if ((puVar12 != (uint *)0x0) && (*puVar12 != 0)) {
                        uVar17 = puVar12[1];
                        local_34 = (uint *)0x0;
                        if (uVar17 != 0) {
                          iVar8 = *(int *)(*(int *)(local_b0[(int)local_1c] + 0x10) +
                                          (int)local_8 * 4);
                          piVar11 = (int *)puVar12[2];
                          do {
                            if ((*piVar11 == iVar8) ||
                               (*(int *)(*(int *)(*(int *)(local_18 + 0x14) + *piVar11 * 4) + 0x38)
                                == iVar8)) {
                              local_34 = (uint *)0x1;
                            }
                            piVar11 = piVar11 + 1;
                            uVar17 = uVar17 - 1;
                          } while (uVar17 != 0);
                        }
                        if (puVar12 == local_38) {
                          puVar13 = (uint *)0x0;
                        }
                        else {
                          puVar13 = local_34;
                        }
                        if (puVar13 != (uint *)0x0) {
                          puVar5 = (uint *)0x0;
                          do {
                            if (puVar12 == (uint *)local_b0[(int)puVar5]) {
                              puVar13 = (uint *)0x0;
                            }
                            puVar5 = (uint *)((int)puVar5 + 1);
                          } while (puVar5 < local_20);
                          if (puVar13 != (uint *)0x0) {
                            local_14 = 1;
                          }
                        }
                      }
                      local_24 = local_24 + 1;
                      local_10 = local_10 - 1;
                    } while (local_10 != 0);
                  }
                  local_8 = (uint *)((int)local_8 + 1);
                } while (local_8 < local_50);
              }
              local_1c = (uint *)((int)local_1c + 1);
            } while (local_1c < local_20);
          }
          local_8 = (uint *)0x0;
          do {
            uVar17 = local_230[(int)local_8];
            if ((uVar17 != 0xffffffff) && (puVar12 = (uint *)0x0, local_20 != (uint *)0x0)) {
              do {
                iVar8 = *(int *)(local_b0[(int)puVar12] + 0xc);
                if (iVar8 != 0) {
                  puVar13 = *(uint **)(local_b0[(int)puVar12] + 0x10);
                  do {
                    if ((uVar17 == *puVar13) ||
                       (*(uint *)(*(int *)(*(int *)(local_18 + 0x14) + uVar17 * 4) + 0x38) ==
                        *puVar13)) {
                      local_14 = 1;
                    }
                    puVar13 = puVar13 + 1;
                    iVar8 = iVar8 + -1;
                  } while (iVar8 != 0);
                }
                puVar12 = (uint *)((int)puVar12 + 1);
              } while (puVar12 < local_20);
            }
            local_8 = (uint *)((int)local_8 + 1);
          } while (local_8 < (uint *)0x28);
          if (local_14 == 0) goto LAB_00940a92;
        }
        local_28 = (uint *)((int)local_28 + 1);
      } while (local_28 == (uint *)0x0);
      if (local_14 != 0) goto code_r0x00940a83;
LAB_00940a92:
      puVar12 = local_b0;
      ppuVar15 = local_f0;
      for (uVar17 = (uint)local_20 & 0x3fffffff; uVar17 != 0; uVar17 = uVar17 - 1) {
        *ppuVar15 = (uint *)*puVar12;
        puVar12 = puVar12 + 1;
        ppuVar15 = ppuVar15 + 1;
      }
      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(char *)ppuVar15 = (char)*puVar12;
        puVar12 = (uint *)((int)puVar12 + 1);
        ppuVar15 = (uint **)((int)ppuVar15 + 1);
      }
      local_f0[(int)puVar14] = local_38;
      local_44 = (uint *)((int)puVar14 + 1);
      uVar17 = 0;
      do {
        iVar8 = *(int *)((int)local_230 + uVar17);
        if ((iVar8 != -1) || (iVar8 = *(int *)((int)local_2d0 + uVar17), iVar8 != -1)) {
          *(int *)((int)auStack_190 + uVar17) = iVar8;
        }
        uVar17 = uVar17 + 4;
      } while (uVar17 < 0xa0);
      local_14 = 0;
LAB_00940af3:
      iVar8 = local_14;
      if (local_14 == 1) goto LAB_00940aff;
      goto LAB_00940eec;
    }
LAB_00940aff:
    local_38 = *(uint **)(local_18 + 0x100);
    uVar17 = **(uint **)(local_18 + 0x100);
    local_20 = (uint *)(uVar17 & 0xfffff);
    if ((local_20 <= local_30) && ((uVar17 & 0xfff00000) == 0x30000000)) {
      local_2c = (uint *)0x0;
      local_40 = (int)local_44 << 2;
LAB_00940b3e:
      local_28 = (uint *)0x0;
      do {
        uVar17 = local_40;
        ppuVar15 = local_f0;
        puVar14 = local_b0;
        for (uVar10 = local_40 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *puVar14 = (uint)*ppuVar15;
          ppuVar15 = ppuVar15 + 1;
          puVar14 = puVar14 + 1;
        }
        for (uVar17 = uVar17 & 3; uVar17 != 0; uVar17 = uVar17 - 1) {
          *(undefined1 *)puVar14 = *(undefined1 *)ppuVar15;
          ppuVar15 = (uint **)((int)ppuVar15 + 1);
          puVar14 = (uint *)((int)puVar14 + 1);
        }
        puVar14 = local_230;
        for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar14 = 0xffffffff;
          puVar14 = puVar14 + 1;
        }
        piVar11 = local_2d0;
        for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
          *piVar11 = -1;
          piVar11 = piVar11 + 1;
        }
        iVar8 = 0;
        local_c = local_44;
        local_14 = 0;
        local_10 = 0;
        do {
          if (local_28 == (uint *)0x0) {
            uVar17 = local_10;
          }
          else {
            uVar17 = 1 - local_10;
          }
          uVar10 = local_38[2];
          uVar17 = *(uint *)(&DAT_00a2c224 + uVar17 * 4);
          piVar11 = (int *)(uVar10 + iVar8 * 4);
          if (uVar17 < 0x10) {
            iVar7 = *(int *)(*(int *)(*(int *)(local_18 + 0x14) + *piVar11 * 4) + 0x48);
            if (iVar7 != -1) {
              uVar2 = *(undefined4 *)(*(int *)(local_18 + 0x18) + iVar7 * 4);
              iVar7 = FUN_0093d27f(uVar2,piVar11,local_20,local_60,local_70,
                                   *(undefined4 *)(&DAT_00a2c230 + uVar17 * 0x20),0);
              if (iVar7 == 0) {
                local_14 = FUN_0093d430(uVar2,&DAT_00a2c218 + uVar17 * 0x20,local_b0,&local_c,
                                        local_2d0,local_70,local_30,0);
                goto LAB_00940c4e;
              }
            }
            local_14 = 1;
            break;
          }
          uVar18 = 0;
          puVar14 = local_230 + (uVar17 - 0x10) * 4;
          do {
            if ((uint *)local_60[uVar18] < local_20) {
              *puVar14 = *(uint *)(uVar10 + (local_60[uVar18] + iVar8) * 4);
            }
            else {
              *puVar14 = 0xffffffff;
            }
            uVar18 = uVar18 + 1;
            puVar14 = puVar14 + 1;
          } while (uVar18 < 4);
LAB_00940c4e:
          if (local_14 == 1) break;
          local_10 = local_10 + 1;
          iVar8 = iVar8 + (int)local_20;
        } while (local_10 < 3);
        puVar14 = local_c;
        local_10 = 0;
        local_24 = (uint *)0x0;
        do {
          if (local_28 == (uint *)0x0) {
            uVar17 = local_10;
          }
          else {
            uVar17 = 1 - local_10;
          }
          if ((0xf < *(uint *)(&DAT_00a2c224 + uVar17 * 4)) &&
             (local_8 = (uint *)0x0, local_c != (uint *)0x0)) {
            do {
              puVar12 = (uint *)0x0;
              if (local_20 != (uint *)0x0) {
                puVar13 = *(uint **)(local_b0[(int)local_8] + 0xc);
                do {
                  local_1c = (uint *)0x0;
                  if (puVar13 != (uint *)0x0) {
                    piVar11 = *(int **)(local_b0[(int)local_8] + 0x10);
                    do {
                      if (*(int *)(local_38[2] + ((int)local_24 + (int)puVar12) * 4) == *piVar11) {
                        local_14 = 1;
                        goto LAB_00940ce5;
                      }
                      local_1c = (uint *)((int)local_1c + 1);
                      piVar11 = piVar11 + 1;
                    } while (local_1c < puVar13);
                  }
                  puVar12 = (uint *)((int)puVar12 + 1);
                } while (puVar12 < local_20);
              }
LAB_00940ce5:
              local_8 = (uint *)((int)local_8 + 1);
            } while (local_8 < local_c);
          }
          local_10 = local_10 + 1;
          local_24 = (uint *)((int)local_24 + (int)local_20);
        } while (local_10 < 3);
        if (local_14 == 0) {
          if (local_2c != (uint *)0x0) goto LAB_00940e84;
          local_1c = (uint *)0x0;
          if (local_c != (uint *)0x0) {
            do {
              local_50 = *(uint **)(local_b0[(int)local_1c] + 0xc);
              local_8 = (uint *)0x0;
              if (local_50 != (uint *)0x0) {
                do {
                  if (*(uint *)(local_18 + 0xc) != 0) {
                    local_24 = *(uint **)(local_18 + 0x18);
                    local_10 = *(uint *)(local_18 + 0xc);
                    do {
                      puVar12 = (uint *)*local_24;
                      if ((puVar12 != (uint *)0x0) && (*puVar12 != 0)) {
                        uVar17 = puVar12[1];
                        local_34 = (uint *)0x0;
                        if (uVar17 != 0) {
                          iVar8 = *(int *)(*(int *)(local_b0[(int)local_1c] + 0x10) +
                                          (int)local_8 * 4);
                          piVar11 = (int *)puVar12[2];
                          do {
                            if ((*piVar11 == iVar8) ||
                               (*(int *)(*(int *)(*(int *)(local_18 + 0x14) + *piVar11 * 4) + 0x38)
                                == iVar8)) {
                              local_34 = (uint *)0x1;
                            }
                            piVar11 = piVar11 + 1;
                            uVar17 = uVar17 - 1;
                          } while (uVar17 != 0);
                        }
                        if (puVar12 == local_38) {
                          puVar13 = (uint *)0x0;
                        }
                        else {
                          puVar13 = local_34;
                        }
                        if (puVar13 != (uint *)0x0) {
                          puVar5 = (uint *)0x0;
                          do {
                            if (puVar12 == (uint *)local_b0[(int)puVar5]) {
                              puVar13 = (uint *)0x0;
                            }
                            puVar5 = (uint *)((int)puVar5 + 1);
                          } while (puVar5 < local_c);
                          if (puVar13 != (uint *)0x0) {
                            local_14 = 1;
                          }
                        }
                      }
                      local_24 = local_24 + 1;
                      local_10 = local_10 - 1;
                    } while (local_10 != 0);
                  }
                  local_8 = (uint *)((int)local_8 + 1);
                } while (local_8 < local_50);
              }
              local_1c = (uint *)((int)local_1c + 1);
            } while (local_1c < local_c);
          }
          local_8 = (uint *)0x0;
          do {
            uVar17 = local_230[(int)local_8];
            if ((uVar17 != 0xffffffff) && (puVar12 = (uint *)0x0, local_c != (uint *)0x0)) {
              do {
                iVar8 = *(int *)(local_b0[(int)puVar12] + 0xc);
                if (iVar8 != 0) {
                  puVar13 = *(uint **)(local_b0[(int)puVar12] + 0x10);
                  do {
                    if ((uVar17 == *puVar13) ||
                       (*(uint *)(*(int *)(*(int *)(local_18 + 0x14) + uVar17 * 4) + 0x38) ==
                        *puVar13)) {
                      local_14 = 1;
                    }
                    puVar13 = puVar13 + 1;
                    iVar8 = iVar8 + -1;
                  } while (iVar8 != 0);
                }
                puVar12 = (uint *)((int)puVar12 + 1);
              } while (puVar12 < local_c);
            }
            local_8 = (uint *)((int)local_8 + 1);
          } while (local_8 < (uint *)0x28);
          if (local_14 == 0) goto LAB_00940e84;
        }
        local_28 = (uint *)((int)local_28 + 1);
      } while (local_28 == (uint *)0x0);
      if (local_14 != 0) goto code_r0x00940e75;
LAB_00940e84:
      puVar12 = local_b0;
      ppuVar15 = local_f0;
      for (uVar17 = (uint)local_c & 0x3fffffff; uVar17 != 0; uVar17 = uVar17 - 1) {
        *ppuVar15 = (uint *)*puVar12;
        puVar12 = puVar12 + 1;
        ppuVar15 = ppuVar15 + 1;
      }
      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(char *)ppuVar15 = (char)*puVar12;
        puVar12 = (uint *)((int)puVar12 + 1);
        ppuVar15 = (uint **)((int)ppuVar15 + 1);
      }
      local_f0[(int)puVar14] = local_38;
      local_44 = (uint *)((int)puVar14 + 1);
      uVar17 = 0;
      do {
        iVar8 = *(int *)((int)local_230 + uVar17);
        if ((iVar8 != -1) || (iVar8 = *(int *)((int)local_2d0 + uVar17), iVar8 != -1)) {
          *(int *)((int)auStack_190 + uVar17) = iVar8;
        }
        uVar17 = uVar17 + 4;
      } while (uVar17 < 0xa0);
      local_14 = 0;
LAB_00940ee5:
      iVar8 = local_14;
      goto LAB_00940ee8;
    }
    iVar8 = 1;
LAB_00940ee8:
    local_3c = (uint *)0x0;
LAB_00940eec:
    if (iVar8 == 0) {
      local_8 = (uint *)0x0;
      if (local_30 != (uint *)0x0) {
        do {
          iVar8 = *(int *)(*(int *)(local_18 + 0x14) + auStack_190[(int)local_8] * 4);
          uVar17 = auStack_190[(int)(local_8 + 2)];
          local_34 = *(uint **)(*(int *)(local_18 + 0x14) + auStack_190[(int)(local_8 + 1)] * 4);
          if ((((uVar17 != auStack_190[(int)(local_8 + 5)]) ||
               (auStack_190[(int)(local_8 + 3)] != auStack_190[(int)(local_8 + 6)])) ||
              (auStack_190[(int)(local_8 + 4)] != auStack_190[(int)(local_8 + 7)])) ||
             (uVar17 != auStack_190[(int)(local_8 + 3)])) goto LAB_009419f7;
          iVar7 = *(int *)(local_18 + 0x10);
          iVar6 = *(int *)(*(int *)(local_18 + 0x14) + auStack_190[(int)(local_8 + 4)] * 4);
          if (((((*(byte *)(*(int *)(iVar7 + *(int *)(iVar8 + 4) * 4) + 5) & 1) == 0) ||
               ((*(byte *)(*(int *)(iVar7 + local_34[1] * 4) + 5) & 1) == 0)) ||
              (((*(byte *)(*(int *)(iVar7 + *(int *)(iVar6 + 4) * 4) + 5) & 1) == 0 ||
               ((*(double *)(iVar8 + 0x20) != _DAT_0099d0a0 ||
                (local_50 = (uint *)((uint)(local_3c == (uint *)0x0) * 2 - 1),
                *(double *)(local_34 + 8) != (double)(int)local_50)))))) ||
             (*(double *)(iVar6 + 0x20) != _DAT_0099d098)) goto LAB_009419f7;
          iVar8 = *(int *)(*(int *)(local_18 + 0x14) + uVar17 * 4);
          if (*(int *)(iVar8 + 4) != *(int *)(local_18 + 0x88)) {
            local_4c = 1;
          }
          uVar17 = 0;
          if (local_48 != 0) {
            do {
              if (*(int *)(iVar8 + 0x48) == local_60[uVar17]) break;
              uVar17 = uVar17 + 1;
            } while (uVar17 < local_48);
          }
          if ((uVar17 == local_48) && (local_4c == 0)) {
            local_60[local_48] = *(int *)(iVar8 + 0x48);
            local_48 = local_48 + 1;
          }
          local_8 = (uint *)((int)local_8 + 1);
        } while (local_8 < local_30);
      }
      local_20 = auStack_190 + 8;
      goto LAB_00941888;
    }
    if (iVar8 != 1) {
LAB_00941880:
      if (iVar8 != 0) {
        return iVar8;
      }
      goto LAB_00941888;
    }
    local_38 = *(uint **)(local_18 + 0x100);
    uVar17 = **(uint **)(local_18 + 0x100);
    local_20 = (uint *)(uVar17 & 0xfffff);
    if ((local_30 < local_20) || ((uVar17 & 0xfff00000) != 0x30000000)) {
      iVar8 = 1;
LAB_0094108d:
      iVar7 = local_18;
      local_c = (uint *)0x0;
      local_34 = (uint *)0x0;
      if (((*(byte *)(local_18 + 0x6e) & 0x40) == 0) ||
         ((iVar6 = FUN_0093f455(&local_c,local_f0,&local_44), iVar6 != 0 &&
          (iVar6 = FUN_0093fa51(&local_c,local_f0,&local_44), iVar6 != 0)))) {
        local_44 = (uint *)0x1;
        local_f0[0] = *(uint **)(iVar7 + 0x100);
        local_c = *(uint **)(iVar7 + 0x100);
      }
      else {
        local_34 = local_c;
      }
      if ((local_c != (uint *)0x0) && ((*local_c & 0xfff00000) == 0x70b00000)) {
        local_30 = (uint *)(*local_c & 0xfffff);
        local_3c = (uint *)((int)local_30 << 2);
        local_10 = 0;
        local_8 = (uint *)0x0;
        local_2c = (uint *)((int)local_30 * -4);
        do {
          local_24 = (uint *)0x0;
          if (local_30 != (uint *)0x0) {
            uVar17 = local_c[2];
            iVar8 = *(int *)(local_18 + 0x14);
            local_1c = (uint *)((int)local_3c + uVar17);
            puVar14 = local_8;
            do {
              pbVar1 = *(byte **)(iVar8 + *(int *)((int)puVar14 + uVar17) * 4);
              local_50 = *(uint **)(iVar8 + *local_1c * 4);
              if ((pbVar1[0x3e] & 8) == 0) {
                bVar4 = *pbVar1 & 4;
              }
              else {
                bVar4 = *pbVar1 & 8;
              }
              if ((((bVar4 == 0) ||
                   ((*(byte *)(*(int *)(*(int *)(local_18 + 0x10) + *(int *)((int)local_50 + 4) * 4)
                              + 5) & 1) == 0)) ||
                  (*(double *)((int)local_50 + 0x20) != _DAT_0099d0a0)) ||
                 (*(int *)((int)local_50 + 8) != -1)) break;
              iVar7 = *(int *)(pbVar1 + 4);
              local_70[(int)local_24] = *(uint *)((int)puVar14 + local_c[2]);
              if (iVar7 != *(int *)(local_18 + 0x88)) {
                local_4c = 1;
              }
              local_1c = local_1c + 1;
              local_24 = (uint *)((int)local_24 + 1);
              puVar14 = puVar14 + 1;
            } while (local_24 < local_30);
          }
          if (local_24 == local_30) {
            if (local_30 != (uint *)0x0) {
              iVar8 = *(int *)(local_18 + 0x14);
              piVar11 = (int *)(local_c[2] + local_10 * (int)local_30 * 4);
              puVar14 = local_30;
              do {
                uVar17 = local_48;
                iVar7 = *(int *)(iVar8 + *piVar11 * 4);
                if (*(int *)(iVar7 + 0x38) == -1) {
                  uVar10 = 0;
                  if (local_48 != 0) {
                    do {
                      if (*(int *)(iVar7 + 0x48) == local_60[uVar10]) break;
                      uVar10 = uVar10 + 1;
                    } while (uVar10 < local_48);
                  }
                  if ((uVar10 == local_48) && (local_4c == 0)) {
                    local_48 = local_48 + 1;
                    local_60[uVar17] = *(int *)(iVar7 + 0x48);
                  }
                }
                else {
                  local_4c = 1;
                }
                piVar11 = piVar11 + 1;
                puVar14 = (uint *)((int)puVar14 + -1);
              } while (puVar14 != (uint *)0x0);
            }
            break;
          }
          local_10 = local_10 + 1;
          local_8 = local_8 + (int)local_30;
          local_3c = (uint *)((int)local_3c + (int)local_2c);
        } while (local_10 < 2);
        if (local_10 == 2) goto LAB_009419f7;
        local_20 = local_70;
        iVar8 = 0;
      }
      if (local_34 != (uint *)0x0) {
        FUN_008f4adb(1);
      }
      goto LAB_00941880;
    }
    local_2c = (uint *)0x0;
LAB_009410e8:
    local_28 = (uint *)0x0;
    do {
      puVar14 = local_44;
      ppuVar15 = local_f0;
      puVar12 = local_b0;
      for (uVar17 = (uint)local_44 & 0x3fffffff; uVar17 != 0; uVar17 = uVar17 - 1) {
        *puVar12 = (uint)*ppuVar15;
        ppuVar15 = ppuVar15 + 1;
        puVar12 = puVar12 + 1;
      }
      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined1 *)puVar12 = *(undefined1 *)ppuVar15;
        ppuVar15 = (uint **)((int)ppuVar15 + 1);
        puVar12 = (uint *)((int)puVar12 + 1);
      }
      puVar12 = local_230;
      for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar12 = 0xffffffff;
        puVar12 = puVar12 + 1;
      }
      iVar7 = 0;
      piVar11 = local_2d0;
      for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
        *piVar11 = -1;
        piVar11 = piVar11 + 1;
      }
      local_c = puVar14;
      local_14 = 0;
      local_10 = 0;
      do {
        if (local_28 == (uint *)0x0) {
          uVar17 = local_10;
        }
        else {
          uVar17 = 1 - local_10;
        }
        uVar10 = local_38[2];
        uVar17 = *(uint *)(&DAT_00a2c164 + uVar17 * 4);
        piVar11 = (int *)(uVar10 + iVar7 * 4);
        if (uVar17 < 0x10) {
          iVar8 = *(int *)(*(int *)(*(int *)(local_18 + 0x14) + *piVar11 * 4) + 0x48);
          if (iVar8 != -1) {
            uVar2 = *(undefined4 *)(*(int *)(local_18 + 0x18) + iVar8 * 4);
            iVar8 = FUN_0093d27f(uVar2,piVar11,local_20,local_60,local_70,
                                 *(undefined4 *)(&DAT_00a2c170 + uVar17 * 0x20),0);
            if (iVar8 == 0) {
              local_14 = FUN_0093d430(uVar2,&DAT_00a2c158 + uVar17 * 0x20,local_b0,&local_c,
                                      local_2d0,local_70,local_30,0);
              goto LAB_009411fa;
            }
          }
          local_14 = 1;
          break;
        }
        uVar18 = 0;
        puVar14 = local_230 + (uVar17 - 0x10) * 4;
        do {
          if ((uint *)local_60[uVar18] < local_20) {
            *puVar14 = *(uint *)(uVar10 + (local_60[uVar18] + iVar7) * 4);
          }
          else {
            *puVar14 = 0xffffffff;
          }
          uVar18 = uVar18 + 1;
          puVar14 = puVar14 + 1;
        } while (uVar18 < 4);
LAB_009411fa:
        if (local_14 == 1) break;
        local_10 = local_10 + 1;
        iVar7 = iVar7 + (int)local_20;
      } while (local_10 < 3);
      puVar14 = local_c;
      local_10 = 0;
      local_24 = (uint *)0x0;
      do {
        if (local_28 == (uint *)0x0) {
          uVar17 = local_10;
        }
        else {
          uVar17 = 1 - local_10;
        }
        if ((0xf < *(uint *)(&DAT_00a2c164 + uVar17 * 4)) &&
           (local_8 = (uint *)0x0, local_c != (uint *)0x0)) {
          do {
            puVar12 = (uint *)0x0;
            if (local_20 != (uint *)0x0) {
              puVar13 = *(uint **)(local_b0[(int)local_8] + 0xc);
              do {
                local_1c = (uint *)0x0;
                if (puVar13 != (uint *)0x0) {
                  piVar11 = *(int **)(local_b0[(int)local_8] + 0x10);
                  do {
                    if (*(int *)(local_38[2] + ((int)local_24 + (int)puVar12) * 4) == *piVar11) {
                      local_14 = 1;
                      goto LAB_00941291;
                    }
                    local_1c = (uint *)((int)local_1c + 1);
                    piVar11 = piVar11 + 1;
                  } while (local_1c < puVar13);
                }
                puVar12 = (uint *)((int)puVar12 + 1);
              } while (puVar12 < local_20);
            }
LAB_00941291:
            local_8 = (uint *)((int)local_8 + 1);
          } while (local_8 < local_c);
        }
        local_10 = local_10 + 1;
        local_24 = (uint *)((int)local_24 + (int)local_20);
      } while (local_10 < 3);
      if (local_14 == 0) {
        if (local_2c != (uint *)0x0) goto LAB_00941430;
        local_1c = (uint *)0x0;
        if (local_c != (uint *)0x0) {
          do {
            local_50 = *(uint **)(local_b0[(int)local_1c] + 0xc);
            local_8 = (uint *)0x0;
            if (local_50 != (uint *)0x0) {
              do {
                if (*(uint **)(local_18 + 0xc) != (uint *)0x0) {
                  local_34 = *(uint **)(local_18 + 0x18);
                  local_24 = *(uint **)(local_18 + 0xc);
                  do {
                    puVar12 = (uint *)*local_34;
                    if ((puVar12 != (uint *)0x0) && (*puVar12 != 0)) {
                      uVar17 = puVar12[1];
                      local_3c = (uint *)0x0;
                      if (uVar17 != 0) {
                        iVar8 = *(int *)(*(int *)(local_b0[(int)local_1c] + 0x10) + (int)local_8 * 4
                                        );
                        piVar11 = (int *)puVar12[2];
                        do {
                          if ((*piVar11 == iVar8) ||
                             (*(int *)(*(int *)(*(int *)(local_18 + 0x14) + *piVar11 * 4) + 0x38) ==
                              iVar8)) {
                            local_3c = (uint *)0x1;
                          }
                          piVar11 = piVar11 + 1;
                          uVar17 = uVar17 - 1;
                        } while (uVar17 != 0);
                      }
                      if (puVar12 == local_38) {
                        puVar13 = (uint *)0x0;
                      }
                      else {
                        puVar13 = local_3c;
                      }
                      if (puVar13 != (uint *)0x0) {
                        puVar5 = (uint *)0x0;
                        do {
                          if (puVar12 == (uint *)local_b0[(int)puVar5]) {
                            puVar13 = (uint *)0x0;
                          }
                          puVar5 = (uint *)((int)puVar5 + 1);
                        } while (puVar5 < local_c);
                        if (puVar13 != (uint *)0x0) {
                          local_14 = 1;
                        }
                      }
                    }
                    local_34 = local_34 + 1;
                    local_24 = (uint *)((int)local_24 + -1);
                  } while (local_24 != (uint *)0x0);
                }
                local_8 = (uint *)((int)local_8 + 1);
              } while (local_8 < local_50);
            }
            local_1c = (uint *)((int)local_1c + 1);
          } while (local_1c < local_c);
        }
        local_8 = (uint *)0x0;
        do {
          uVar17 = local_230[(int)local_8];
          if ((uVar17 != 0xffffffff) && (puVar12 = (uint *)0x0, local_c != (uint *)0x0)) {
            do {
              iVar8 = *(int *)(local_b0[(int)puVar12] + 0xc);
              if (iVar8 != 0) {
                puVar13 = *(uint **)(local_b0[(int)puVar12] + 0x10);
                do {
                  if ((uVar17 == *puVar13) ||
                     (*(uint *)(*(int *)(*(int *)(local_18 + 0x14) + uVar17 * 4) + 0x38) == *puVar13
                     )) {
                    local_14 = 1;
                  }
                  puVar13 = puVar13 + 1;
                  iVar8 = iVar8 + -1;
                } while (iVar8 != 0);
              }
              puVar12 = (uint *)((int)puVar12 + 1);
            } while (puVar12 < local_c);
          }
          local_8 = (uint *)((int)local_8 + 1);
        } while (local_8 < (uint *)0x28);
        if (local_14 == 0) goto LAB_00941430;
      }
      local_28 = (uint *)((int)local_28 + 1);
    } while (local_28 == (uint *)0x0);
    if (local_14 != 0) goto code_r0x00941421;
LAB_00941430:
    puVar12 = local_b0;
    ppuVar15 = local_f0;
    for (uVar17 = (uint)local_c & 0x3fffffff; uVar17 != 0; uVar17 = uVar17 - 1) {
      *ppuVar15 = (uint *)*puVar12;
      puVar12 = puVar12 + 1;
      ppuVar15 = ppuVar15 + 1;
    }
    for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(char *)ppuVar15 = (char)*puVar12;
      puVar12 = (uint *)((int)puVar12 + 1);
      ppuVar15 = (uint **)((int)ppuVar15 + 1);
    }
    local_f0[(int)puVar14] = local_38;
    local_44 = (uint *)((int)puVar14 + 1);
    uVar17 = 0;
    do {
      iVar8 = *(int *)((int)local_230 + uVar17);
      if ((iVar8 != -1) || (iVar8 = *(int *)((int)local_2d0 + uVar17), iVar8 != -1)) {
        *(int *)((int)auStack_190 + uVar17) = iVar8;
      }
      uVar17 = uVar17 + 4;
    } while (uVar17 < 0xa0);
    local_14 = 0;
LAB_00941491:
    iVar8 = local_14;
    if (local_14 != 0) goto LAB_0094108d;
    local_24 = (uint *)0x0;
    if (local_30 == (uint *)0x0) goto LAB_00941888;
    while( true ) {
      local_8 = (uint *)0x0;
      local_34 = (uint *)auStack_190[(int)(local_24 + 1)];
      if (local_34 != (uint *)auStack_190[(int)(local_24 + 3)]) break;
      local_1c = (uint *)auStack_190[(int)(local_24 + 2)];
      if (((local_1c != (uint *)auStack_190[(int)(local_24 + 4)]) ||
          (puVar14 = (uint *)auStack_190[(int)(local_24 + 5)],
          puVar14 != (uint *)auStack_190[(int)(local_24 + 7)])) ||
         (puVar12 = (uint *)auStack_190[(int)(local_24 + 6)],
         puVar12 != (uint *)auStack_190[(int)(local_24 + 8)])) break;
      iVar8 = *(int *)(*(int *)(local_18 + 0x14) + (int)puVar14 * 4);
      iVar7 = *(int *)(*(int *)(local_18 + 0x14) + (int)puVar12 * 4);
      local_3c = *(uint **)(*(int *)(local_18 + 0x10) + *(int *)(iVar8 + 4) * 4);
      local_c = (uint *)0x0;
      iVar6 = *(int *)(*(int *)(local_18 + 0x10) + *(int *)(iVar7 + 4) * 4);
      if ((((puVar14 == local_1c) && ((*(byte *)(iVar6 + 5) & 1) != 0)) &&
          (*(double *)(iVar7 + 0x20) == _DAT_009fd350)) ||
         (((puVar12 == local_1c && ((*(byte *)((int)local_3c + 5) & 1) != 0)) &&
          (*(double *)(iVar8 + 0x20) == _DAT_009fd350)))) {
        local_c = (uint *)0x1;
      }
      local_20 = auStack_190 + 8;
      if (local_c == (uint *)0x0) {
        iVar3 = *(int *)(*(int *)(local_18 + 0x14) + (int)local_34 * 4);
        puVar14 = *(uint **)(iVar8 + 0x38);
        if ((((puVar14 == local_34) ||
             ((puVar14 != (uint *)0xffffffff && (*(uint **)(iVar3 + 0x38) == puVar14)))) &&
            (*(uint *)(iVar8 + 0x3c) == (*(uint *)(iVar3 + 0x3c) ^ 0x80000))) &&
           (((*(byte *)(iVar6 + 5) & 1) != 0 && (*(double *)(iVar7 + 0x20) == _DAT_0099d0a0)))) {
          local_c = (uint *)0x1;
        }
        puVar14 = *(uint **)(iVar7 + 0x38);
        if (((puVar14 == local_34) ||
            ((puVar14 != (uint *)0xffffffff && (*(uint **)(iVar3 + 0x38) == puVar14)))) &&
           ((*(uint *)(iVar7 + 0x3c) == (*(uint *)(iVar3 + 0x3c) ^ 0x80000) &&
            (((*(byte *)((int)local_3c + 5) & 1) != 0 &&
             (*(double *)(iVar8 + 0x20) == _DAT_0099d0a0)))))) {
          local_c = (uint *)0x1;
        }
        local_8 = (uint *)0x1;
        if (local_c == (uint *)0x0) {
          return 1;
        }
        local_20 = auStack_190 + 4;
      }
      iVar8 = *(int *)(local_18 + 0x14);
      iVar7 = *(int *)(iVar8 + auStack_190[(int)local_24] * 4);
      if (local_8 == (uint *)0x0) {
        iVar6 = *(int *)(iVar8 + (int)local_34 * 4);
      }
      else {
        iVar6 = *(int *)(iVar8 + (int)local_1c * 4);
      }
      if (((((*(byte *)(*(int *)(*(int *)(local_18 + 0x10) + *(int *)(iVar7 + 4) * 4) + 5) & 1) == 0
            ) || (*(double *)(iVar7 + 0x20) != _DAT_0099d098)) ||
          ((*(byte *)(*(int *)(*(int *)(local_18 + 0x10) + *(int *)(iVar6 + 4) * 4) + 5) & 1) == 0))
         || (*(double *)(iVar6 + 0x20) != _DAT_0099d0a0)) break;
      iVar8 = *(int *)(iVar8 + local_20[(int)local_24] * 4);
      if (*(int *)(iVar8 + 4) != *(int *)(local_18 + 0x88)) {
        local_4c = 1;
      }
      uVar17 = 0;
      if (local_48 != 0) {
        do {
          if (*(int *)(iVar8 + 0x48) == local_60[uVar17]) break;
          uVar17 = uVar17 + 1;
        } while (uVar17 < local_48);
      }
      if ((uVar17 == local_48) && (local_4c == 0)) {
        local_60[local_48] = *(int *)(iVar8 + 0x48);
        local_48 = local_48 + 1;
      }
      local_24 = (uint *)((int)local_24 + 1);
      if (local_30 <= local_24) goto LAB_00941888;
    }
LAB_009419f7:
    iVar8 = 1;
  }
  return iVar8;
code_r0x0094015f:
  local_2c = (uint *)((int)local_2c + 1);
  if (local_2c != (uint *)0x0) goto LAB_009401cd;
  goto LAB_0093fe1d;
code_r0x00940550:
  local_38 = (uint *)((int)local_38 + 1);
  if (local_38 != (uint *)0x0) goto LAB_009405c0;
  goto LAB_00940218;
code_r0x00940a83:
  local_2c = (uint *)((int)local_2c + 1);
  if (local_2c != (uint *)0x0) goto LAB_00940af3;
  goto LAB_0094074b;
code_r0x00940e75:
  local_2c = (uint *)((int)local_2c + 1);
  if (local_2c != (uint *)0x0) goto LAB_00940ee5;
  goto LAB_00940b3e;
code_r0x00941421:
  local_2c = (uint *)((int)local_2c + 1);
  if (local_2c != (uint *)0x0) goto LAB_00941491;
  goto LAB_009410e8;
}


