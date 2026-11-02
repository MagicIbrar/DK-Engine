// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x950000-0x95ffff

// ==== FUN_009500b0 @ 0x009500b0 ====

int FUN_009500b0(int param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int local_1c;
  int local_18;
  uint local_14;
  undefined4 *local_10;
  int local_c;
  uint local_8;
  
  iVar4 = *(int *)(param_1 + 0x1b0);
  iVar1 = *(int *)(param_1 + 0x144);
  while ((*(int *)(param_1 + 0x94) < *(int *)(param_1 + 0x9c) ||
         ((*(int *)(param_1 + 0x94) == *(int *)(param_1 + 0x9c) &&
          (*(uint *)(param_1 + 0x98) <= *(uint *)(param_1 + 0xa0)))))) {
    iVar3 = (*(code *)**(undefined4 **)(param_1 + 0x1b8))(param_1);
    if (iVar3 == 0) {
      return 0;
    }
  }
  iVar3 = *(int *)(param_1 + 0xdc);
  local_1c = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    local_10 = (undefined4 *)(iVar4 + 0x48);
    do {
      if (*(int *)(iVar3 + 0x30) != 0) {
        iVar4 = (**(code **)(*(int *)(param_1 + 4) + 0x20))
                          (param_1,*local_10,*(int *)(param_1 + 0xa0) * *(int *)(iVar3 + 0xc),
                           *(int *)(iVar3 + 0xc),0);
        if ((*(uint *)(param_1 + 0xa0) < iVar1 - 1U) ||
           (local_8 = *(uint *)(iVar3 + 0x20) % *(uint *)(iVar3 + 0xc), local_8 == 0)) {
          local_8 = *(uint *)(iVar3 + 0xc);
        }
        pcVar2 = *(code **)(*(int *)(param_1 + 0x1c4) + 4 + local_1c * 4);
        local_c = *(int *)(param_2 + local_1c * 4);
        local_18 = 0;
        if (0 < (int)local_8) {
          uVar6 = *(uint *)(iVar3 + 0x1c);
          do {
            iVar5 = *(int *)(iVar4 + local_18 * 4);
            iVar7 = 0;
            local_14 = 0;
            if (uVar6 != 0) {
              do {
                (*pcVar2)(param_1,iVar3,iVar5,local_c,iVar7);
                uVar6 = *(uint *)(iVar3 + 0x1c);
                iVar7 = iVar7 + *(int *)(iVar3 + 0x24);
                iVar5 = iVar5 + 0x80;
                local_14 = local_14 + 1;
              } while (local_14 < uVar6);
            }
            local_c = local_c + *(int *)(iVar3 + 0x24) * 4;
            local_18 = local_18 + 1;
          } while (local_18 < (int)local_8);
        }
      }
      local_1c = local_1c + 1;
      local_10 = local_10 + 1;
      iVar3 = iVar3 + 0x54;
    } while (local_1c < *(int *)(param_1 + 0x24));
  }
  uVar6 = *(int *)(param_1 + 0xa0) + 1;
  *(uint *)(param_1 + 0xa0) = uVar6;
  return 4 - (uint)(uVar6 < *(uint *)(param_1 + 0x144));
}


// ==== FUN_00950230 @ 0x00950230 ====

undefined4 FUN_00950230(int param_1)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 local_10;
  undefined4 *local_c;
  int local_8;
  
  iVar8 = *(int *)(param_1 + 0x1b0);
  iVar7 = 0;
  local_10 = 0;
  if ((*(int *)(param_1 + 0xe0) != 0) && (*(int *)(param_1 + 0xa4) != 0)) {
    if (*(int *)(iVar8 + 0x70) == 0) {
      uVar4 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,*(int *)(param_1 + 0x24) * 0x18);
      *(undefined4 *)(iVar8 + 0x70) = uVar4;
    }
    iVar1 = *(int *)(param_1 + 0x24);
    iVar8 = *(int *)(iVar8 + 0x70);
    if (iVar1 < 1) {
      return 0;
    }
    local_c = (undefined4 *)(*(int *)(param_1 + 0xdc) + 0x4c);
    local_8 = 0;
    while (((((psVar2 = (short *)*local_c, psVar2 != (short *)0x0 && (*psVar2 != 0)) &&
             (psVar2[1] != 0)) && ((psVar2[8] != 0 && (psVar2[0x10] != 0)))) &&
           ((psVar2[9] != 0 &&
            ((psVar2[2] != 0 &&
             (piVar5 = (int *)(*(int *)(param_1 + 0xa4) + local_8),
             -1 < *(int *)(*(int *)(param_1 + 0xa4) + local_8)))))))) {
      iVar6 = iVar8 - (int)piVar5;
      iVar9 = 5;
      do {
        piVar5 = piVar5 + 1;
        iVar3 = *piVar5;
        *(int *)(iVar6 + (int)piVar5) = iVar3;
        if (iVar3 != 0) {
          local_10 = 1;
        }
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      iVar8 = iVar8 + 0x18;
      iVar7 = iVar7 + 1;
      local_8 = local_8 + 0x100;
      local_c = local_c + 0x15;
      if (iVar1 <= iVar7) {
        return local_10;
      }
    }
  }
  return 0;
}


// ==== FUN_00950360 @ 0x00950360 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_00950360(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  code *pcVar9;
  bool bVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  int local_fc;
  int local_e8;
  short *local_dc;
  uint local_d8;
  int local_d4;
  short *local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_a8;
  int local_a4;
  undefined4 *local_a0;
  int local_9c;
  short *local_94;
  uint local_8c;
  undefined1 local_88 [2];
  short local_86;
  short local_84;
  short local_78;
  short local_76;
  short local_68;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  iVar6 = *(int *)(param_1 + 0x1b0);
  iVar7 = *(int *)(param_1 + 0x144);
  if (*(int *)(param_1 + 0x94) <= *(int *)(param_1 + 0x9c)) {
    do {
      if (((*(undefined4 **)(param_1 + 0x1b8))[5] != 0) ||
         ((*(int *)(param_1 + 0x94) == *(int *)(param_1 + 0x9c) &&
          ((uint)(*(int *)(param_1 + 0x194) == 0) + *(int *)(param_1 + 0xa0) <
           *(uint *)(param_1 + 0x98))))) break;
      iVar12 = (*(code *)**(undefined4 **)(param_1 + 0x1b8))(param_1);
      if (iVar12 == 0) {
        return 0;
      }
    } while (*(int *)(param_1 + 0x94) <= *(int *)(param_1 + 0x9c));
  }
  local_a4 = *(int *)(param_1 + 0xdc);
  local_cc = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    local_a0 = (undefined4 *)(iVar6 + 0x48);
    local_d4 = 0;
    do {
      if (*(int *)(local_a4 + 0x30) != 0) {
        uVar21 = *(uint *)(param_1 + 0xa0);
        uVar15 = *(uint *)(local_a4 + 0xc);
        if (uVar21 < iVar7 - 1U) {
          bVar10 = false;
          uVar16 = uVar15 * 2;
          local_8c = uVar15;
        }
        else {
          local_8c = *(uint *)(local_a4 + 0x20) % uVar15;
          if (local_8c == 0) {
            local_8c = uVar15;
          }
          bVar10 = true;
          uVar16 = local_8c;
        }
        if (uVar21 == 0) {
          local_fc = (**(code **)(*(int *)(param_1 + 4) + 0x20))(param_1,*local_a0,0,uVar16,0);
        }
        else {
          local_fc = (**(code **)(*(int *)(param_1 + 4) + 0x20))
                               (param_1,*local_a0,(uVar21 - 1) * uVar15,uVar16 + uVar15);
          local_fc = local_fc + *(int *)(local_a4 + 0xc) * 4;
        }
        iVar12 = *(int *)(iVar6 + 0x70) + local_d4;
        puVar8 = *(ushort **)(local_a4 + 0x4c);
        uVar15 = (uint)*puVar8;
        uVar1 = puVar8[1];
        uVar2 = puVar8[8];
        uVar3 = puVar8[0x10];
        uVar4 = puVar8[9];
        uVar5 = puVar8[2];
        pcVar9 = *(code **)((*(int *)(param_1 + 0x1c4) - iVar6) + -0x44 + (int)local_a0);
        local_bc = *(int *)(param_2 + local_cc * 4);
        local_b8 = 0;
        if (0 < (int)local_8c) {
          do {
            local_94 = *(short **)(local_fc + local_b8 * 4);
            if ((uVar21 != 0) || (local_dc = local_94, local_b8 != 0)) {
              local_dc = *(short **)(local_fc + -4 + local_b8 * 4);
            }
            if ((!bVar10) || (local_d0 = local_94, local_b8 != local_8c - 1)) {
              local_d0 = *(short **)(local_fc + 4 + local_b8 * 4);
            }
            local_c0 = (int)*local_94;
            local_e8 = (int)*local_d0;
            local_b4 = (int)*local_dc;
            uVar16 = *(int *)(local_a4 + 0x1c) - 1;
            local_c8 = 0;
            local_d8 = 0;
            iVar22 = local_b4;
            local_a8 = local_e8;
            local_9c = local_c0;
            do {
              iVar11 = local_b4;
              local_d0 = local_d0 + 0x40;
              local_dc = local_dc + 0x40;
              FUN_0090b780(local_94,local_88,1);
              iVar20 = local_9c;
              local_c4 = local_b4;
              local_b0 = local_a8;
              if (local_d8 < uVar16) {
                local_c4 = (int)*local_dc;
                iVar20 = (int)local_94[0x40];
                local_b0 = (int)*local_d0;
              }
              iVar18 = *(int *)(iVar12 + 4);
              if ((iVar18 != 0) && (local_86 == 0)) {
                iVar13 = (local_c0 - iVar20) * uVar15;
                iVar17 = iVar13 * 0x24;
                iVar19 = (uint)uVar1 << 8;
                iVar14 = (uint)uVar1 * 0x80;
                if (iVar17 < 0) {
                  iVar19 = (iVar14 + iVar13 * -0x24) / iVar19;
                  if ((0 < iVar18) && (iVar18 = 1 << ((byte)iVar18 & 0x1f), iVar18 <= iVar19)) {
                    iVar19 = iVar18 + -1;
                  }
                  iVar19 = -iVar19;
                }
                else {
                  iVar19 = (iVar14 + iVar17) / iVar19;
                  if ((0 < iVar18) && (iVar18 = 1 << ((byte)iVar18 & 0x1f), iVar18 <= iVar19)) {
                    iVar19 = iVar18 + -1;
                  }
                }
                local_86 = (short)iVar19;
              }
              iVar18 = *(int *)(iVar12 + 8);
              if ((iVar18 != 0) && (local_78 == 0)) {
                iVar13 = (local_b4 - local_a8) * uVar15;
                iVar17 = iVar13 * 0x24;
                iVar19 = (uint)uVar2 << 8;
                iVar14 = (uint)uVar2 * 0x80;
                if (iVar17 < 0) {
                  iVar19 = (iVar14 + iVar13 * -0x24) / iVar19;
                  if ((0 < iVar18) && (iVar18 = 1 << ((byte)iVar18 & 0x1f), iVar18 <= iVar19)) {
                    iVar19 = iVar18 + -1;
                  }
                  iVar19 = -iVar19;
                }
                else {
                  iVar19 = (iVar14 + iVar17) / iVar19;
                  if ((0 < iVar18) && (iVar18 = 1 << ((byte)iVar18 & 0x1f), iVar18 <= iVar19)) {
                    iVar19 = iVar18 + -1;
                  }
                }
                local_78 = (short)iVar19;
              }
              iVar18 = *(int *)(iVar12 + 0xc);
              if ((iVar18 != 0) && (local_68 == 0)) {
                iVar14 = (local_a8 + local_9c * -2 + local_b4) * uVar15;
                iVar13 = iVar14 * 9;
                iVar19 = (uint)uVar3 << 8;
                iVar17 = (uint)uVar3 * 0x80;
                if (iVar13 < 0) {
                  iVar19 = (iVar17 + iVar14 * -9) / iVar19;
                  if ((0 < iVar18) && (iVar18 = 1 << ((byte)iVar18 & 0x1f), iVar18 <= iVar19)) {
                    iVar19 = iVar18 + -1;
                  }
                  iVar19 = -iVar19;
                }
                else {
                  iVar19 = (iVar17 + iVar13) / iVar19;
                  if ((0 < iVar18) && (iVar18 = 1 << ((byte)iVar18 & 0x1f), iVar18 <= iVar19)) {
                    iVar19 = iVar18 + -1;
                  }
                }
                local_68 = (short)iVar19;
              }
              iVar18 = *(int *)(iVar12 + 0x10);
              if ((iVar18 != 0) && (local_76 == 0)) {
                iVar13 = (((local_b0 - local_e8) - local_c4) + iVar22) * uVar15;
                iVar19 = iVar13 * 5;
                iVar22 = (uint)uVar4 << 8;
                iVar14 = (uint)uVar4 * 0x80;
                if (iVar19 < 0) {
                  iVar22 = (iVar14 + iVar13 * -5) / iVar22;
                  if ((0 < iVar18) && (iVar18 = 1 << ((byte)iVar18 & 0x1f), iVar18 <= iVar22)) {
                    iVar22 = iVar18 + -1;
                  }
                  iVar22 = -iVar22;
                }
                else {
                  iVar22 = (iVar14 + iVar19) / iVar22;
                  if ((0 < iVar18) && (iVar18 = 1 << ((byte)iVar18 & 0x1f), iVar18 <= iVar22)) {
                    iVar22 = iVar18 + -1;
                  }
                }
                local_76 = (short)iVar22;
              }
              iVar22 = *(int *)(iVar12 + 0x14);
              if ((iVar22 != 0) && (local_84 == 0)) {
                iVar13 = (iVar20 + local_9c * -2 + local_c0) * uVar15;
                iVar19 = iVar13 * 9;
                iVar18 = (uint)uVar5 << 8;
                iVar14 = (uint)uVar5 * 0x80;
                if (iVar19 < 0) {
                  iVar18 = (iVar14 + iVar13 * -9) / iVar18;
                  if ((0 < iVar22) && (iVar22 = 1 << ((byte)iVar22 & 0x1f), iVar22 <= iVar18)) {
                    iVar18 = iVar22 + -1;
                  }
                  iVar18 = -iVar18;
                }
                else {
                  iVar18 = (iVar14 + iVar19) / iVar18;
                  if ((0 < iVar22) && (iVar22 = 1 << ((byte)iVar22 & 0x1f), iVar22 <= iVar18)) {
                    iVar18 = iVar22 + -1;
                  }
                }
                local_84 = (short)iVar18;
              }
              (*pcVar9)(param_1,local_a4,local_88,local_bc,local_c8);
              local_b4 = local_c4;
              local_e8 = local_a8;
              local_a8 = local_b0;
              local_94 = local_94 + 0x40;
              local_c0 = local_9c;
              local_c8 = local_c8 + *(int *)(local_a4 + 0x24);
              local_d8 = local_d8 + 1;
              iVar22 = iVar11;
              local_9c = iVar20;
            } while (local_d8 <= uVar16);
            local_bc = local_bc + *(int *)(local_a4 + 0x24) * 4;
            local_b8 = local_b8 + 1;
          } while (local_b8 < (int)local_8c);
        }
      }
      local_d4 = local_d4 + 0x18;
      local_cc = local_cc + 1;
      local_a0 = local_a0 + 1;
      local_a4 = local_a4 + 0x54;
    } while (local_cc < *(int *)(param_1 + 0x24));
  }
  uVar21 = *(int *)(param_1 + 0xa0) + 1;
  *(uint *)(param_1 + 0xa0) = uVar21;
  return 4 - (uint)(uVar21 < *(uint *)(param_1 + 0x144));
}


// ==== FUN_00950a90 @ 0x00950a90 ====

void FUN_00950a90(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x1b0);
  if (*(int *)(iVar1 + 0x10) != 0) {
    if (*(int *)(param_1 + 0x50) != 0) {
      iVar2 = FUN_00950230(param_1);
      if (iVar2 != 0) {
        *(code **)(iVar1 + 0xc) = FUN_00950360;
        *(undefined4 *)(param_1 + 0xa0) = 0;
        return;
      }
    }
    *(code **)(iVar1 + 0xc) = FUN_009500b0;
  }
  *(undefined4 *)(param_1 + 0xa0) = 0;
  return;
}


// ==== FUN_00950af0 @ 0x00950af0 ====

void FUN_00950af0(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  
  iVar7 = param_1;
  puVar4 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x74);
  *(undefined4 **)(param_1 + 0x1b0) = puVar4;
  *puVar4 = FUN_0094fc00;
  puVar4[2] = FUN_00950a90;
  puVar4[0x1c] = 0;
  if (param_2 == (undefined4 *)0x0) {
    iVar7 = (**(code **)(*(int *)(param_1 + 4) + 4))(param_1,1,0x500);
    puVar4[9] = iVar7 + 0x80;
    puVar4[10] = iVar7 + 0x100;
    puVar4[0xb] = iVar7 + 0x180;
    puVar4[0xc] = iVar7 + 0x200;
    puVar4[0xd] = iVar7 + 0x280;
    puVar4[0xe] = iVar7 + 0x300;
    puVar4[8] = iVar7;
    puVar4[0xf] = iVar7 + 0x380;
    puVar4[0x10] = iVar7 + 0x400;
    puVar4[0x11] = iVar7 + 0x480;
    puVar4[4] = 0;
    puVar4[1] = FUN_00454830;
    puVar4[3] = FUN_0094fc20;
    return;
  }
  piVar9 = (int *)(param_1 + 0x24);
  piVar1 = (int *)(param_1 + 0xdc);
  param_1 = 0;
  if (0 < *piVar9) {
    param_2 = puVar4 + 0x12;
    piVar9 = (int *)(*piVar1 + 0xc);
    do {
      iVar2 = *piVar9;
      iVar8 = iVar2;
      if (*(int *)(iVar7 + 0xe0) != 0) {
        iVar8 = iVar2 * 3;
      }
      iVar3 = *(int *)(iVar7 + 4);
      uVar5 = FUN_0090b710(piVar9[5],iVar2);
      uVar6 = FUN_0090b710(piVar9[4],piVar9[-1]);
      uVar5 = (**(code **)(iVar3 + 0x14))(iVar7,1,1,uVar6,uVar5,iVar8);
      *param_2 = uVar5;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
      piVar9 = piVar9 + 0x15;
    } while (param_1 < *(int *)(iVar7 + 0x24));
  }
  puVar4[1] = FUN_0094fe90;
  puVar4[3] = FUN_009500b0;
  puVar4[4] = puVar4 + 0x12;
  return;
}


// ==== FUN_00950c40 @ 0x00950c40 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00950c40(int *param_1,int param_2,int param_3,int *param_4)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined1 *puVar8;
  char cVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  int aiStack_530 [257];
  int local_12c;
  uint local_128;
  int *local_124;
  int local_120;
  int *local_11c;
  int local_118;
  undefined1 *local_114;
  int local_110;
  char local_10c [260];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  local_124 = param_1;
  local_11c = param_4;
  if ((param_3 < 0) || (3 < param_3)) {
    puVar14 = (undefined4 *)*param_1;
    puVar14[5] = 0x32;
    puVar14[6] = param_3;
    (*(code *)*puVar14)(param_1);
  }
  if (param_2 == 0) {
    iVar12 = param_1[param_3 + 0x32];
    local_110 = iVar12;
  }
  else {
    iVar12 = param_1[param_3 + 0x2e];
    local_110 = iVar12;
  }
  local_110 = iVar12;
  if (iVar12 == 0) {
    puVar14 = (undefined4 *)*param_1;
    puVar14[5] = 0x32;
    puVar14[6] = param_3;
    (*(code *)*puVar14)(param_1);
  }
  piVar6 = local_11c;
  if (*local_11c == 0) {
    iVar3 = (**(code **)param_1[1])(param_1,1,0x590);
    *piVar6 = iVar3;
  }
  iVar3 = *piVar6;
  iVar13 = 0;
  local_120 = iVar3;
  *(int *)(iVar3 + 0x8c) = iVar12;
  local_118 = 0;
  local_114 = (undefined1 *)0x1;
  while( true ) {
    puVar8 = local_114;
    bVar1 = local_114[iVar12];
    uVar11 = (uint)bVar1;
    if (0x100 < (int)(uVar11 + iVar13)) {
      puVar14 = (undefined4 *)*local_124;
      puVar14[5] = 8;
      (*(code *)*puVar14)(local_124);
      iVar3 = local_120;
    }
    if (uVar11 != 0) {
      cVar9 = (char)puVar8;
      pcVar4 = local_10c + iVar13;
      for (uVar7 = (uint)(bVar1 >> 2); uVar7 != 0; uVar7 = uVar7 - 1) {
        *(uint *)pcVar4 = CONCAT22(CONCAT11(cVar9,cVar9),CONCAT11(cVar9,cVar9));
        pcVar4 = pcVar4 + 4;
      }
      for (uVar7 = uVar11 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar4 = cVar9;
        pcVar4 = pcVar4 + 1;
      }
      iVar13 = local_118 + uVar11;
      local_118 = iVar13;
      iVar3 = local_120;
      puVar8 = local_114;
    }
    local_114 = puVar8 + 1;
    if (0x10 < (int)(puVar8 + 1)) break;
    iVar12 = local_110;
  }
  local_10c[iVar13] = '\0';
  local_12c = iVar13;
  iVar13 = 0;
  iVar12 = 0;
  iVar10 = (int)local_10c[0];
  if (local_10c[0] != '\0') {
    pcVar4 = local_10c;
    do {
      cVar9 = *pcVar4;
      while (cVar9 == iVar10) {
        cVar9 = local_10c[iVar12 + 1];
        aiStack_530[iVar12] = iVar13;
        iVar12 = iVar12 + 1;
        iVar13 = iVar13 + 1;
      }
      if (1 << ((byte)iVar10 & 0x1f) <= iVar13) {
        puVar14 = (undefined4 *)*local_124;
        puVar14[5] = 8;
        (*(code *)*puVar14)(local_124);
        iVar3 = local_120;
      }
      pcVar4 = local_10c + iVar12;
      iVar13 = iVar13 << 1;
      iVar10 = iVar10 + 1;
    } while (local_10c[iVar12] != '\0');
  }
  iVar12 = local_12c;
  iVar10 = 0;
  iVar13 = 1;
  do {
    bVar1 = *(byte *)(iVar13 + local_110);
    if (bVar1 == 0) {
      *(undefined4 *)(iVar3 + iVar13 * 4) = 0xffffffff;
    }
    else {
      *(int *)(iVar3 + 0x48 + iVar13 * 4) = iVar10 - aiStack_530[iVar10];
      iVar10 = iVar10 + (uint)bVar1;
      *(int *)(iVar3 + iVar13 * 4) = aiStack_530[iVar10 + -1];
    }
    iVar13 = iVar13 + 1;
  } while (iVar13 < 0x11);
  *(undefined4 *)(iVar3 + 0x44) = 0xfffff;
  puVar14 = (undefined4 *)(iVar3 + 0x90);
  for (iVar13 = 0x100; iVar13 != 0; iVar13 = iVar13 + -1) {
    *puVar14 = 0;
    puVar14 = puVar14 + 1;
  }
  iVar3 = 0;
  local_118 = 0;
  iVar13 = 1;
  local_11c = (int *)0x7;
  do {
    if (*(byte *)(iVar13 + local_110) != 0) {
      local_114 = (undefined1 *)(iVar3 + 0x11 + local_110);
      iVar10 = 1 << ((byte)local_11c & 0x1f);
      local_128 = (uint)*(byte *)(iVar13 + local_110);
      do {
        iVar5 = aiStack_530[iVar3] << ((byte)local_11c & 0x1f);
        if (0 < iVar10) {
          uVar2 = *local_114;
          puVar8 = (undefined1 *)(iVar5 + 0x490 + local_120);
          piVar6 = (int *)(local_120 + 0x90 + iVar5 * 4);
          iVar3 = iVar10;
          do {
            *piVar6 = iVar13;
            piVar6 = piVar6 + 1;
            *puVar8 = uVar2;
            puVar8 = puVar8 + 1;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          iVar3 = local_118;
        }
        iVar3 = iVar3 + 1;
        local_114 = local_114 + 1;
        local_128 = local_128 - 1;
        local_118 = iVar3;
      } while (local_128 != 0);
    }
    iVar13 = iVar13 + 1;
    local_11c = (int *)((int)local_11c + -1);
  } while (-1 < (int)local_11c);
  if ((param_2 != 0) && (iVar3 = 0, 0 < local_12c)) {
    do {
      if (0xf < *(byte *)(local_110 + 0x11 + iVar3)) {
        puVar14 = (undefined4 *)*local_124;
        puVar14[5] = 8;
        (*(code *)*puVar14)(local_124);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar12);
  }
  return;
}


// ==== FUN_00950f70 @ 0x00950f70 ====

undefined4 FUN_00950f70(undefined4 *param_1,uint param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  
  piVar1 = (int *)param_1[4];
  pbVar5 = (byte *)*param_1;
  iVar3 = param_1[1];
  if (piVar1[0x69] == 0) {
    for (; param_3 < 0x19; param_3 = param_3 + 8) {
      if (iVar3 == 0) {
        iVar3 = (**(code **)(piVar1[6] + 0xc))(piVar1);
        if (iVar3 == 0) {
          return 0;
        }
        pbVar5 = *(byte **)piVar1[6];
        iVar3 = ((undefined4 *)piVar1[6])[1];
      }
      uVar4 = (uint)*pbVar5;
      iVar3 = iVar3 + -1;
      pbVar5 = pbVar5 + 1;
      if (uVar4 == 0xff) {
        do {
          if (iVar3 == 0) {
            iVar3 = (**(code **)(piVar1[6] + 0xc))(piVar1);
            if (iVar3 == 0) {
              return 0;
            }
            pbVar5 = *(byte **)piVar1[6];
            iVar3 = ((undefined4 *)piVar1[6])[1];
          }
          uVar4 = (uint)*pbVar5;
          iVar3 = iVar3 + -1;
          pbVar5 = pbVar5 + 1;
        } while (uVar4 == 0xff);
        if (uVar4 != 0) {
          piVar1[0x69] = uVar4;
          goto LAB_0095101c;
        }
        uVar4 = 0xff;
      }
      param_2 = param_2 << 8 | uVar4;
    }
  }
  else {
LAB_0095101c:
    if (param_3 < param_4) {
      if (*(int *)(piVar1[0x70] + 8) == 0) {
        iVar2 = *piVar1;
        *(undefined4 *)(iVar2 + 0x14) = 0x75;
        (**(code **)(iVar2 + 4))(piVar1,0xffffffff);
        *(undefined4 *)(piVar1[0x70] + 8) = 1;
      }
      param_2 = param_2 << (0x19U - (char)param_3 & 0x1f);
      param_3 = 0x19;
    }
  }
  param_1[1] = iVar3;
  *param_1 = pbVar5;
  param_1[2] = param_2;
  param_1[3] = param_3;
  return 1;
}


// ==== FUN_00951090 @ 0x00951090 ====

uint FUN_00951090(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int local_8;
  
  local_8 = param_5;
  if (param_3 < param_5) {
    iVar2 = FUN_00950f70(param_1,param_2,param_3,param_5);
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    param_2 = *(int *)(param_1 + 8);
    param_3 = *(int *)(param_1 + 0xc);
  }
  param_3 = param_3 - param_5;
  uVar3 = param_2 >> ((byte)param_3 & 0x1f) & (1 << ((byte)param_5 & 0x1f)) - 1U;
  if (*(int *)(param_4 + param_5 * 4) < (int)uVar3) {
    do {
      if (param_3 < 1) {
        iVar2 = FUN_00950f70(param_1,param_2,param_3,1);
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        param_2 = *(int *)(param_1 + 8);
        param_3 = *(int *)(param_1 + 0xc);
      }
      param_3 = param_3 + -1;
      uVar3 = uVar3 << 1 | param_2 >> ((byte)param_3 & 0x1f) & 1U;
      param_5 = local_8 + 1;
      local_8 = param_5;
    } while (*(int *)(param_4 + param_5 * 4) < (int)uVar3);
  }
  *(int *)(param_1 + 8) = param_2;
  *(int *)(param_1 + 0xc) = param_3;
  if (param_5 < 0x11) {
    return (uint)*(byte *)(*(int *)(param_4 + 0x48 + param_5 * 4) + *(int *)(param_4 + 0x8c) + 0x11
                          + uVar3);
  }
  piVar1 = *(int **)(param_1 + 0x10);
  iVar2 = *piVar1;
  *(undefined4 *)(iVar2 + 0x14) = 0x76;
  (**(code **)(iVar2 + 4))(piVar1,0xffffffff);
  return 0;
}


// ==== FUN_00951180 @ 0x00951180 ====

undefined4 FUN_00951180(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 *puVar3;
  
  iVar2 = *(int *)(unaff_ESI + 0x1bc);
  iVar1 = *(int *)(unaff_ESI + 0x1c0);
  *(int *)(iVar2 + 0x18) =
       *(int *)(iVar2 + 0x18) +
       ((int)(*(int *)(iVar1 + 0x10) + (*(int *)(iVar1 + 0x10) >> 0x1f & 7U)) >> 3);
  *(undefined4 *)(iVar1 + 0x10) = 0;
  iVar2 = (**(code **)(iVar2 + 8))();
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = *(int *)(unaff_ESI + 0x14c);
  if (0 < iVar2) {
    puVar3 = (undefined4 *)(iVar1 + 0x14);
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
  }
  *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(unaff_ESI + 0x118);
  if (*(int *)(unaff_ESI + 0x1a4) == 0) {
    *(undefined4 *)(iVar1 + 8) = 0;
  }
  return 1;
}


// ==== FUN_009511f0 @ 0x009511f0 ====

undefined4 FUN_009511f0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30 [4];
  int local_20;
  int local_1c;
  undefined2 *local_18;
  int *local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  iVar6 = *(int *)(param_1 + 0x1c0);
  local_20 = iVar6;
  if (((*(int *)(param_1 + 0x118) != 0) && (*(int *)(iVar6 + 0x24) == 0)) &&
     (iVar4 = FUN_00951180(), iVar4 == 0)) {
    return 0;
  }
  if (*(int *)(iVar6 + 8) == 0) {
    local_44 = **(undefined4 **)(param_1 + 0x18);
    local_40 = (*(undefined4 **)(param_1 + 0x18))[1];
    iVar4 = *(int *)(iVar6 + 0x10);
    local_30[0] = *(int *)(iVar6 + 0x14);
    local_30[1] = *(undefined4 *)(iVar6 + 0x18);
    local_30[3] = *(undefined4 *)(iVar6 + 0x20);
    iVar8 = *(int *)(iVar6 + 0xc);
    local_34 = param_1;
    local_30[2] = *(undefined4 *)(iVar6 + 0x1c);
    local_10 = 0;
    if (0 < *(int *)(param_1 + 0x168)) {
      local_14 = (int *)(param_1 + 0x16c);
      local_8 = (int *)(iVar6 + 0x70);
      do {
        iVar6 = *local_8;
        local_18 = *(undefined2 **)(param_2 + local_10 * 4);
        iVar10 = local_8[-10];
        local_c = iVar6;
        if (iVar4 < 8) {
          iVar4 = FUN_00950f70(&local_44,iVar8,iVar4,0);
          if (iVar4 == 0) {
            return 0;
          }
          iVar4 = local_38;
          iVar8 = local_3c;
          if (7 < local_38) goto LAB_009512d0;
          uVar7 = 1;
LAB_009512f9:
          uVar5 = FUN_00951090(&local_44,iVar8,iVar4,iVar10,uVar7);
          if ((int)uVar5 < 0) {
            return 0;
          }
          iVar4 = local_38;
          iVar8 = local_3c;
        }
        else {
LAB_009512d0:
          uVar5 = iVar8 >> ((char)iVar4 - 8U & 0x1f) & 0xff;
          iVar1 = *(int *)(iVar10 + 0x90 + uVar5 * 4);
          if (iVar1 == 0) {
            uVar7 = 9;
            goto LAB_009512f9;
          }
          uVar5 = (uint)*(byte *)(uVar5 + 0x490 + iVar10);
          iVar4 = iVar4 - iVar1;
        }
        uVar9 = 0;
        if (uVar5 != 0) {
          if (iVar4 < (int)uVar5) {
            iVar6 = FUN_00950f70(&local_44,iVar8,iVar4,uVar5);
            if (iVar6 == 0) {
              return 0;
            }
            iVar4 = local_38;
            iVar8 = local_3c;
          }
          iVar4 = iVar4 - uVar5;
          uVar9 = (1 << ((byte)uVar5 & 0x1f)) - 1U & iVar8 >> ((byte)iVar4 & 0x1f);
          iVar6 = local_c;
          if ((int)uVar9 < *(int *)(&DAT_00a2e338 + uVar5 * 4)) {
            uVar9 = *(int *)(&DAT_00a2e378 + uVar5 * 4) + uVar9;
          }
        }
        piVar3 = local_8;
        if (local_8[10] != 0) {
          iVar10 = *local_14;
          local_30[iVar10] = local_30[iVar10] + uVar9;
          *local_18 = (short)local_30[iVar10];
        }
        iVar10 = 1;
        if (piVar3[0x14] == 0) {
          do {
            if (iVar4 < 8) {
              iVar4 = FUN_00950f70(&local_44,iVar8,iVar4,0);
              if (iVar4 == 0) {
                return 0;
              }
              iVar4 = local_38;
              iVar8 = local_3c;
              if (7 < local_38) goto LAB_009514bd;
              uVar7 = 1;
LAB_009514e6:
              uVar5 = FUN_00951090(&local_44,iVar8,iVar4,iVar6,uVar7);
              if ((int)uVar5 < 0) {
                return 0;
              }
              iVar4 = local_38;
              iVar8 = local_3c;
            }
            else {
LAB_009514bd:
              uVar5 = iVar8 >> ((char)iVar4 - 8U & 0x1f) & 0xff;
              iVar1 = *(int *)(iVar6 + 0x90 + uVar5 * 4);
              if (iVar1 == 0) {
                uVar7 = 9;
                goto LAB_009514e6;
              }
              uVar5 = (uint)*(byte *)(uVar5 + 0x490 + iVar6);
              iVar4 = iVar4 - iVar1;
            }
            uVar9 = uVar5 & 0xf;
            if (uVar9 == 0) {
              if ((int)uVar5 >> 4 != 0xf) break;
            }
            else {
              if (iVar4 < (int)uVar9) {
                iVar4 = FUN_00950f70(&local_44,iVar8,iVar4,uVar9);
                if (iVar4 == 0) {
                  return 0;
                }
                iVar4 = local_38;
                iVar8 = local_3c;
              }
              iVar4 = iVar4 - uVar9;
            }
            iVar10 = iVar10 + ((int)uVar5 >> 4) + 1;
          } while (iVar10 < 0x40);
        }
        else {
          do {
            if (iVar4 < 8) {
              iVar4 = FUN_00950f70(&local_44,iVar8,iVar4,0);
              if (iVar4 == 0) {
                return 0;
              }
              iVar4 = local_38;
              iVar8 = local_3c;
              if (7 < local_38) goto LAB_009513c2;
              uVar7 = 1;
LAB_009513eb:
              uVar5 = FUN_00951090(&local_44,iVar8,iVar4,iVar6,uVar7);
              if ((int)uVar5 < 0) {
                return 0;
              }
              iVar4 = local_38;
              iVar8 = local_3c;
            }
            else {
LAB_009513c2:
              uVar5 = iVar8 >> ((char)iVar4 - 8U & 0x1f) & 0xff;
              iVar1 = *(int *)(iVar6 + 0x90 + uVar5 * 4);
              if (iVar1 == 0) {
                uVar7 = 9;
                goto LAB_009513eb;
              }
              uVar5 = (uint)*(byte *)(uVar5 + 0x490 + iVar6);
              iVar4 = iVar4 - iVar1;
            }
            uVar9 = uVar5 & 0xf;
            if (uVar9 == 0) {
              if ((int)uVar5 >> 4 != 0xf) break;
              iVar10 = iVar10 + 0xf;
            }
            else {
              local_1c = iVar10 + ((int)uVar5 >> 4);
              if (iVar4 < (int)uVar9) {
                iVar6 = FUN_00950f70(&local_44,iVar8,iVar4,uVar9);
                if (iVar6 == 0) {
                  return 0;
                }
                iVar4 = local_38;
                iVar8 = local_3c;
              }
              iVar4 = iVar4 - uVar9;
              uVar5 = (1 << (sbyte)uVar9) - 1U & iVar8 >> ((byte)iVar4 & 0x1f);
              if ((int)uVar5 < *(int *)(&DAT_00a2e338 + uVar9 * 4)) {
                uVar5 = *(int *)(&DAT_00a2e378 + uVar9 * 4) + uVar5;
              }
              local_18[(&DAT_00a28750)[local_1c]] = (short)uVar5;
              iVar6 = local_c;
              iVar10 = local_1c;
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 < 0x40);
        }
        local_10 = local_10 + 1;
        local_8 = local_8 + 1;
        local_14 = local_14 + 1;
      } while (local_10 < *(int *)(param_1 + 0x168));
      iVar6 = local_20;
    }
    puVar2 = *(undefined4 **)(param_1 + 0x18);
    *puVar2 = local_44;
    *(int *)(iVar6 + 0xc) = iVar8;
    *(int *)(iVar6 + 0x14) = local_30[0];
    *(int *)(iVar6 + 0x10) = iVar4;
    puVar2[1] = local_40;
    *(int *)(iVar6 + 0x18) = local_30[1];
    *(int *)(iVar6 + 0x1c) = local_30[2];
    *(int *)(iVar6 + 0x20) = local_30[3];
  }
  *(int *)(iVar6 + 0x24) = *(int *)(iVar6 + 0x24) + -1;
  return 1;
}


// ==== FUN_009515c0 @ 0x009515c0 ====

void FUN_009515c0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  int *piVar6;
  undefined4 *local_c;
  int local_8;
  
  piVar4 = param_1;
  iVar1 = param_1[0x70];
  if ((((param_1[0x65] != 0) || (param_1[0x66] != 0x3f)) || (param_1[0x67] != 0)) ||
     (param_1[0x68] != 0)) {
    iVar2 = *param_1;
    *(undefined4 *)(iVar2 + 0x14) = 0x7a;
    (**(code **)(iVar2 + 4))(param_1,0xffffffff);
  }
  local_8 = 0;
  if (0 < param_1[0x53]) {
    local_c = (undefined4 *)(iVar1 + 0x14);
    param_1 = param_1 + 0x54;
    do {
      iVar2 = *(int *)(*param_1 + 0x14);
      iVar3 = *(int *)(*param_1 + 0x18);
      FUN_00950c40(piVar4,1,iVar2,iVar1 + 0x28 + iVar2 * 4);
      FUN_00950c40(piVar4,0,iVar3,iVar1 + 0x38 + iVar3 * 4);
      *local_c = 0;
      local_c = local_c + 1;
      local_8 = local_8 + 1;
      param_1 = param_1 + 1;
    } while (local_8 < piVar4[0x53]);
  }
  param_1 = (int *)piVar4[0x5a];
  if (0 < (int)param_1) {
    puVar5 = (uint *)(iVar1 + 0xc0);
    piVar6 = piVar4 + 0x5b;
    do {
      iVar2 = piVar4[*piVar6 + 0x54];
      puVar5[-0x1e] = *(uint *)(iVar1 + 0x28 + *(int *)(iVar2 + 0x14) * 4);
      puVar5[-0x14] = *(uint *)(iVar1 + 0x38 + *(int *)(iVar2 + 0x18) * 4);
      if (*(int *)(iVar2 + 0x30) == 0) {
        *puVar5 = 0;
        puVar5[-10] = 0;
      }
      else {
        puVar5[-10] = 1;
        *puVar5 = (uint)(1 < *(int *)(iVar2 + 0x24));
      }
      piVar6 = piVar6 + 1;
      puVar5 = puVar5 + 1;
      param_1 = (int *)((int)param_1 + -1);
    } while (param_1 != (int *)0x0);
  }
  iVar2 = piVar4[0x46];
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(int *)(iVar1 + 0x24) = iVar2;
  return;
}


// ==== FUN_00951720 @ 0x00951720 ====

void FUN_00951720(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0xe8);
  *puVar1 = FUN_009515c0;
  puVar1[1] = FUN_009511f0;
  *(undefined4 **)(param_1 + 0x1c0) = puVar1;
  puVar1[0xe] = 0;
  puVar1[10] = 0;
  puVar1[0xf] = 0;
  puVar1[0xb] = 0;
  puVar1[0x10] = 0;
  puVar1[0xc] = 0;
  puVar1[0x11] = 0;
  puVar1[0xd] = 0;
  return;
}


// ==== FUN_00951770 @ 0x00951770 ====

undefined4 FUN_00951770(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  undefined4 *puVar3;
  
  iVar2 = *(int *)(unaff_EBX + 0x1bc);
  iVar1 = *(int *)(unaff_EBX + 0x1c0);
  *(int *)(iVar2 + 0x18) =
       *(int *)(iVar2 + 0x18) +
       ((int)(*(int *)(iVar1 + 0x10) + (*(int *)(iVar1 + 0x10) >> 0x1f & 7U)) >> 3);
  *(undefined4 *)(iVar1 + 0x10) = 0;
  iVar2 = (**(code **)(iVar2 + 8))();
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = *(int *)(unaff_EBX + 0x14c);
  if (0 < iVar2) {
    puVar3 = (undefined4 *)(iVar1 + 0x18);
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
  }
  *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(unaff_EBX + 0x118);
  iVar2 = *(int *)(unaff_EBX + 0x1a4);
  *(undefined4 *)(iVar1 + 0x14) = 0;
  if (iVar2 == 0) {
    *(undefined4 *)(iVar1 + 8) = 0;
  }
  return 1;
}


// ==== FUN_009517e0 @ 0x009517e0 ====

undefined4 FUN_009517e0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  int local_40 [4];
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined2 *local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  iVar5 = param_1;
  local_18 = *(undefined4 *)(param_1 + 0x1a0);
  iVar8 = *(int *)(param_1 + 0x1c0);
  local_10 = iVar8;
  if (((*(int *)(param_1 + 0x118) != 0) && (*(int *)(iVar8 + 0x28) == 0)) &&
     (iVar6 = FUN_00951770(), iVar6 == 0)) {
    return 0;
  }
  if (*(int *)(iVar8 + 8) == 0) {
    local_20 = param_1;
    local_30 = **(undefined4 **)(param_1 + 0x18);
    local_2c = (*(undefined4 **)(param_1 + 0x18))[1];
    uVar1 = *(undefined4 *)(iVar8 + 0x14);
    local_40[0] = *(int *)(iVar8 + 0x18);
    local_40[1] = *(undefined4 *)(iVar8 + 0x1c);
    local_40[3] = *(undefined4 *)(iVar8 + 0x24);
    iVar6 = *(int *)(iVar8 + 0x10);
    local_40[2] = *(undefined4 *)(iVar8 + 0x20);
    local_8 = 0;
    iVar2 = *(int *)(iVar8 + 0xc);
    if (0 < *(int *)(param_1 + 0x168)) {
      local_c = (int *)(param_1 + 0x16c);
      param_1 = *(int *)(iVar8 + 0xc);
      do {
        local_1c = *(undefined2 **)(param_2 + local_8 * 4);
        local_14 = *local_c;
        iVar2 = *(int *)(iVar8 + 0x2c + *(int *)(*(int *)(iVar5 + 0x150 + *local_c * 4) + 0x14) * 4)
        ;
        if (iVar6 < 8) {
          iVar6 = FUN_00950f70(&local_30,param_1,iVar6,0);
          if (iVar6 == 0) {
            return 0;
          }
          param_1 = local_28;
          iVar6 = local_24;
          if (7 < local_24) goto LAB_009518d9;
          uVar9 = 1;
LAB_00951903:
          uVar7 = FUN_00951090(&local_30,param_1,iVar6,iVar2,uVar9);
          if ((int)uVar7 < 0) {
            return 0;
          }
          param_1 = local_28;
          iVar6 = local_24;
        }
        else {
LAB_009518d9:
          uVar7 = param_1 >> ((char)iVar6 - 8U & 0x1f) & 0xff;
          iVar3 = *(int *)(iVar2 + 0x90 + uVar7 * 4);
          if (iVar3 == 0) {
            uVar9 = 9;
            goto LAB_00951903;
          }
          uVar7 = (uint)*(byte *)(uVar7 + 0x490 + iVar2);
          iVar6 = iVar6 - iVar3;
        }
        uVar10 = 0;
        if (uVar7 != 0) {
          if (iVar6 < (int)uVar7) {
            iVar8 = FUN_00950f70(&local_30,param_1,iVar6,uVar7);
            if (iVar8 == 0) {
              return 0;
            }
            param_1 = local_28;
            iVar6 = local_24;
          }
          iVar6 = iVar6 - uVar7;
          uVar10 = (1 << ((byte)uVar7 & 0x1f)) - 1U & param_1 >> ((byte)iVar6 & 0x1f);
          iVar8 = local_10;
          if ((int)uVar10 < *(int *)(&DAT_00a2e3b8 + uVar7 * 4)) {
            uVar10 = *(int *)(&DAT_00a2e3f8 + uVar7 * 4) + uVar10;
          }
        }
        iVar2 = local_40[local_14];
        local_40[local_14] = iVar2 + uVar10;
        local_c = local_c + 1;
        *local_1c = (short)(iVar2 + uVar10 << ((byte)local_18 & 0x1f));
        local_8 = local_8 + 1;
        iVar2 = param_1;
      } while (local_8 < *(int *)(iVar5 + 0x168));
    }
    param_1 = iVar2;
    puVar4 = *(undefined4 **)(iVar5 + 0x18);
    *puVar4 = local_30;
    puVar4[1] = local_2c;
    *(int *)(iVar8 + 0x10) = iVar6;
    *(undefined4 *)(iVar8 + 0x14) = uVar1;
    *(int *)(iVar8 + 0x18) = local_40[0];
    *(int *)(iVar8 + 0xc) = param_1;
    *(int *)(iVar8 + 0x1c) = local_40[1];
    *(int *)(iVar8 + 0x20) = local_40[2];
    *(int *)(iVar8 + 0x24) = local_40[3];
  }
  *(int *)(iVar8 + 0x28) = *(int *)(iVar8 + 0x28) + -1;
  return 1;
}


// ==== FUN_00951a10 @ 0x00951a10 ====

undefined4 FUN_00951a10(int param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = *(int *)(param_1 + 0x198);
  iVar3 = *(int *)(param_1 + 0x1c0);
  local_18 = *(undefined4 *)(param_1 + 0x1a0);
  local_14 = iVar3;
  if (((*(int *)(param_1 + 0x118) != 0) && (*(int *)(iVar3 + 0x28) == 0)) &&
     (iVar2 = FUN_00951770(), iVar2 == 0)) {
    return 0;
  }
  if (*(int *)(iVar3 + 8) == 0) {
    if (*(int *)(iVar3 + 0x14) == 0) {
      local_20 = param_1;
      local_30 = **(undefined4 **)(param_1 + 0x18);
      local_1c = *param_2;
      local_2c = (*(undefined4 **)(param_1 + 0x18))[1];
      iVar2 = *(int *)(iVar3 + 0xc);
      iVar5 = *(int *)(iVar3 + 0x10);
      local_c = *(int *)(iVar3 + 0x3c);
      param_2 = *(int **)(param_1 + 0x194);
      local_8 = 0;
      if ((int)param_2 <= local_10) {
        do {
          if (iVar5 < 8) {
            iVar3 = FUN_00950f70(&local_30,iVar2,iVar5,0);
            if (iVar3 == 0) {
              return 0;
            }
            iVar5 = local_24;
            iVar2 = local_28;
            if (7 < local_24) goto LAB_00951adf;
            uVar6 = 1;
LAB_00951b0b:
            uVar4 = FUN_00951090(&local_30,iVar2,iVar5,local_c,uVar6);
            if ((int)uVar4 < 0) {
              return 0;
            }
            iVar5 = local_24;
            iVar2 = local_28;
          }
          else {
LAB_00951adf:
            uVar4 = iVar2 >> ((char)iVar5 - 8U & 0x1f) & 0xff;
            iVar3 = *(int *)(local_c + 0x90 + uVar4 * 4);
            if (iVar3 == 0) {
              uVar6 = 9;
              goto LAB_00951b0b;
            }
            uVar4 = (uint)*(byte *)(uVar4 + 0x490 + local_c);
            iVar5 = iVar5 - iVar3;
          }
          iVar3 = (int)uVar4 >> 4;
          uVar4 = uVar4 & 0xf;
          if (uVar4 == 0) {
            if (iVar3 != 0xf) {
              iVar8 = 1 << ((byte)iVar3 & 0x1f);
              if (iVar3 != 0) {
                if (iVar5 < iVar3) {
                  iVar2 = FUN_00950f70(&local_30,iVar2,iVar5,iVar3);
                  if (iVar2 == 0) {
                    return 0;
                  }
                  iVar5 = local_24;
                  iVar2 = local_28;
                }
                iVar5 = iVar5 - iVar3;
                iVar8 = iVar8 + (iVar2 >> ((byte)iVar5 & 0x1f) & iVar8 - 1U);
              }
              local_8 = iVar8 + -1;
              break;
            }
            param_2 = (int *)((int)param_2 + 0xf);
          }
          else {
            param_2 = (int *)((int)param_2 + iVar3);
            if (iVar5 < (int)uVar4) {
              iVar3 = FUN_00950f70(&local_30,iVar2,iVar5,uVar4);
              if (iVar3 == 0) {
                return 0;
              }
              iVar5 = local_24;
              iVar2 = local_28;
            }
            iVar5 = iVar5 - uVar4;
            uVar7 = (1 << (sbyte)uVar4) - 1U & iVar2 >> ((byte)iVar5 & 0x1f);
            if ((int)uVar7 < *(int *)(&DAT_00a2e3b8 + uVar4 * 4)) {
              uVar7 = *(int *)(&DAT_00a2e3f8 + uVar4 * 4) + uVar7;
            }
            *(short *)(local_1c + (&DAT_00a28750)[(int)param_2] * 2) =
                 (short)(uVar7 << ((byte)local_18 & 0x1f));
          }
          param_2 = (int *)((int)param_2 + 1);
        } while ((int)param_2 <= local_10);
        iVar3 = local_14;
      }
      puVar1 = *(undefined4 **)(param_1 + 0x18);
      *puVar1 = local_30;
      puVar1[1] = local_2c;
      *(int *)(iVar3 + 0xc) = iVar2;
      *(int *)(iVar3 + 0x10) = iVar5;
    }
    else {
      local_8 = *(int *)(iVar3 + 0x14) + -1;
    }
    *(int *)(iVar3 + 0x14) = local_8;
  }
  *(int *)(iVar3 + 0x28) = *(int *)(iVar3 + 0x28) + -1;
  return 1;
}


// ==== FUN_00951c40 @ 0x00951c40 ====

undefined4 FUN_00951c40(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  ushort *local_8;
  
  iVar4 = param_1;
  local_c = 1 << ((byte)*(undefined4 *)(param_1 + 0x1a0) & 0x1f);
  iVar2 = *(int *)(param_1 + 0x1c0);
  if (((*(int *)(param_1 + 0x118) != 0) && (*(int *)(iVar2 + 0x28) == 0)) &&
     (iVar5 = FUN_00951770(), iVar5 == 0)) {
    return 0;
  }
  local_10 = param_1;
  local_20 = **(undefined4 **)(param_1 + 0x18);
  local_1c = (*(undefined4 **)(param_1 + 0x18))[1];
  piVar1 = (int *)(param_1 + 0x168);
  iVar5 = *(int *)(iVar2 + 0x10);
  iVar6 = *(int *)(iVar2 + 0xc);
  param_1 = 0;
  if (0 < *piVar1) {
    do {
      local_8 = *(ushort **)(param_2 + param_1 * 4);
      if (iVar5 < 1) {
        iVar5 = FUN_00950f70(&local_20,iVar6,iVar5,1);
        if (iVar5 == 0) {
          return 0;
        }
        iVar5 = local_14;
        iVar6 = local_18;
      }
      iVar5 = iVar5 + -1;
      if ((iVar6 >> ((byte)iVar5 & 0x1f) & 1U) != 0) {
        *local_8 = *local_8 | (ushort)local_c;
      }
      param_1 = param_1 + 1;
    } while (param_1 < *(int *)(iVar4 + 0x168));
  }
  puVar3 = *(undefined4 **)(iVar4 + 0x18);
  *puVar3 = local_20;
  puVar3[1] = local_1c;
  *(int *)(iVar2 + 0xc) = iVar6;
  *(int *)(iVar2 + 0x28) = *(int *)(iVar2 + 0x28) + -1;
  *(int *)(iVar2 + 0x10) = iVar5;
  return 1;
}


// ==== FUN_00951d30 @ 0x00951d30 ====

undefined4 FUN_00951d30(int *param_1,int *param_2)

{
  short sVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  short *psVar7;
  int iVar8;
  int aiStack_140 [64];
  int local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int *local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  short *local_8;
  
  local_14 = param_1[0x66];
  local_34 = 1 << ((byte)param_1[0x68] & 0x1f);
  local_8 = (short *)param_1[0x70];
  local_38 = -1 << ((byte)param_1[0x68] & 0x1f);
  if (((param_1[0x46] != 0) && (*(int *)((int)local_8 + 0x28) == 0)) &&
     (iVar3 = FUN_00951770(), iVar3 == 0)) {
    return 0;
  }
  psVar7 = local_8;
  if (*(int *)((int)local_8 + 8) == 0) {
    local_20 = param_1;
    local_30 = *(undefined4 *)param_1[6];
    local_2c = ((undefined4 *)param_1[6])[1];
    local_18 = *param_2;
    local_c = *(int *)((int)local_8 + 0x14);
    iVar3 = *(int *)((int)local_8 + 0xc);
    iVar8 = *(int *)((int)local_8 + 0x10);
    local_40 = *(int *)((int)local_8 + 0x3c);
    param_2 = (int *)param_1[0x65];
    local_3c = 0;
    if (local_c == 0) {
      if ((int)param_2 <= local_14) {
        do {
          if (iVar8 < 8) {
            iVar3 = FUN_00950f70(&local_30,iVar3,iVar8,0);
            if (iVar3 == 0) goto joined_r0x009520a9;
            iVar8 = local_24;
            iVar3 = local_28;
            if (7 < local_24) goto LAB_00951e1f;
            uVar4 = 1;
LAB_00951e4d:
            local_10 = FUN_00951090(&local_30,iVar3,iVar8,local_40,uVar4);
            if ((int)local_10 < 0) goto joined_r0x009520a9;
            iVar8 = local_24;
            iVar3 = local_28;
          }
          else {
LAB_00951e1f:
            uVar5 = iVar3 >> ((char)iVar8 - 8U & 0x1f) & 0xff;
            iVar6 = *(int *)(local_40 + 0x90 + uVar5 * 4);
            if (iVar6 == 0) {
              uVar4 = 9;
              goto LAB_00951e4d;
            }
            local_10 = (uint)*(byte *)(uVar5 + 0x490 + local_40);
            iVar8 = iVar8 - iVar6;
          }
          iVar6 = (int)local_10 >> 4;
          local_10 = local_10 & 0xf;
          local_1c = iVar6;
          if (local_10 == 0) {
            if (iVar6 != 0xf) {
              local_1c = 1 << ((byte)iVar6 & 0x1f);
              local_c = local_1c;
              if (iVar6 != 0) {
                if (iVar8 < iVar6) {
                  iVar3 = FUN_00950f70(&local_30,iVar3,iVar8,iVar6);
                  if (iVar3 == 0) goto joined_r0x009520a9;
                  iVar8 = local_24;
                  iVar3 = local_28;
                }
                iVar8 = iVar8 - iVar6;
                local_c = local_c + (iVar3 >> ((byte)iVar8 & 0x1f) & local_1c - 1U);
              }
              psVar7 = local_8;
              goto LAB_00951fe8;
            }
            local_10 = 0;
          }
          else {
            if (local_10 != 1) {
              iVar6 = *param_1;
              *(undefined4 *)(iVar6 + 0x14) = 0x76;
              (**(code **)(iVar6 + 4))(param_1,0xffffffff);
            }
            if (iVar8 < 1) {
              iVar3 = FUN_00950f70(&local_30,iVar3,iVar8,1);
              if (iVar3 == 0) goto joined_r0x009520a9;
              iVar8 = local_24;
              iVar3 = local_28;
            }
            iVar8 = iVar8 + -1;
            if ((iVar3 >> ((byte)iVar8 & 0x1f) & 1U) == 0) {
              local_10 = local_38;
            }
            else {
              local_10 = local_34;
            }
          }
          do {
            psVar7 = (short *)(local_18 + (&DAT_00a28750)[(int)param_2] * 2);
            if (*(short *)(local_18 + (&DAT_00a28750)[(int)param_2] * 2) == 0) {
              local_1c = local_1c + -1;
              if (local_1c < 0) break;
            }
            else {
              if (iVar8 < 1) {
                iVar3 = FUN_00950f70(&local_30,iVar3,iVar8,1);
                if (iVar3 == 0) goto joined_r0x009520a9;
                iVar8 = local_24;
                iVar3 = local_28;
              }
              iVar8 = iVar8 + -1;
              if (((iVar3 >> ((byte)iVar8 & 0x1f) & 1U) != 0) &&
                 (sVar1 = *psVar7, (local_34 & (int)sVar1) == 0)) {
                if (sVar1 < 0) {
                  *psVar7 = sVar1 + (short)local_38;
                }
                else {
                  *psVar7 = sVar1 + (short)local_34;
                }
              }
            }
            param_2 = (int *)((int)param_2 + 1);
          } while ((int)param_2 <= local_14);
          if (local_10 != 0) {
            iVar6 = (&DAT_00a28750)[(int)param_2];
            *(short *)(local_18 + iVar6 * 2) = (short)local_10;
            aiStack_140[local_3c] = iVar6;
            local_3c = local_3c + 1;
          }
          param_2 = (int *)((int)param_2 + 1);
        } while ((int)param_2 <= local_14);
        psVar7 = local_8;
      }
    }
    else {
LAB_00951fe8:
      if (local_c != 0) {
        if ((int)param_2 <= local_14) {
          do {
            local_8 = (short *)(local_18 + (&DAT_00a28750)[(int)param_2] * 2);
            if (*(short *)(local_18 + (&DAT_00a28750)[(int)param_2] * 2) != 0) {
              if (iVar8 < 1) {
                iVar3 = FUN_00950f70(&local_30,iVar3,iVar8,1);
                if (iVar3 == 0) {
joined_r0x009520a9:
                  for (; 0 < local_3c; local_3c = local_3c + -1) {
                    *(undefined2 *)(local_18 + aiStack_140[local_3c + -1] * 2) = 0;
                  }
                  return 0;
                }
                iVar8 = local_24;
                iVar3 = local_28;
              }
              iVar8 = iVar8 + -1;
              if (((iVar3 >> ((byte)iVar8 & 0x1f) & 1U) != 0) && ((local_34 & (int)*local_8) == 0))
              {
                uVar5 = local_34;
                if (*local_8 < 0) {
                  uVar5 = local_38;
                }
                *local_8 = *local_8 + (short)uVar5;
              }
            }
            param_2 = (int *)((int)param_2 + 1);
          } while ((int)param_2 <= local_14);
        }
        local_c = local_c + -1;
      }
    }
    puVar2 = (undefined4 *)param_1[6];
    *puVar2 = local_30;
    puVar2[1] = local_2c;
    *(int *)((int)psVar7 + 0xc) = iVar3;
    *(int *)((int)psVar7 + 0x10) = iVar8;
    *(int *)((int)psVar7 + 0x14) = local_c;
  }
  *(int *)((int)psVar7 + 0x28) = *(int *)((int)psVar7 + 0x28) + -1;
  return 1;
}


// ==== FUN_009520d0 @ 0x009520d0 ====

void FUN_009520d0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  bool bVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  undefined4 *local_10;
  int *local_c;
  
  piVar6 = param_1;
  iVar1 = param_1[0x65];
  iVar8 = param_1[0x66];
  bVar9 = iVar1 != 0;
  iVar2 = param_1[0x70];
  bVar5 = false;
  if (bVar9) {
    if ((iVar8 < iVar1) || (0x3f < iVar8)) {
      bVar5 = true;
    }
    bVar10 = param_1[0x53] == 1;
  }
  else {
    bVar10 = iVar8 == 0;
  }
  if (!bVar10) {
    bVar5 = true;
  }
  iVar3 = param_1[0x67];
  if ((iVar3 != 0) && (param_1[0x68] != iVar3 + -1)) {
    bVar5 = true;
  }
  if ((0xd < param_1[0x68]) || (bVar5)) {
    puVar4 = (undefined4 *)*param_1;
    puVar4[5] = 0x10;
    puVar4[6] = iVar1;
    iVar1 = param_1[0x68];
    puVar4[7] = iVar8;
    puVar4[8] = iVar3;
    puVar4[9] = iVar1;
    (*(code *)*puVar4)(param_1);
  }
  piVar7 = param_1 + 0x53;
  param_1 = (int *)0x0;
  if (0 < *piVar7) {
    local_c = piVar6 + 0x54;
    do {
      iVar1 = *(int *)(*local_c + 4);
      piVar7 = (int *)(iVar1 * 0x100 + piVar6[0x29]);
      if ((bVar9) && (*piVar7 < 0)) {
        iVar8 = *piVar6;
        *(undefined4 *)(iVar8 + 0x14) = 0x73;
        *(int *)(iVar8 + 0x18) = iVar1;
        *(undefined4 *)(iVar8 + 0x1c) = 0;
        (**(code **)(iVar8 + 4))(piVar6,0xffffffff);
      }
      iVar8 = piVar6[0x65];
      if (iVar8 <= piVar6[0x66]) {
        do {
          if (piVar6[0x67] != (piVar7[iVar8] & (piVar7[iVar8] < 0) - 1)) {
            iVar3 = *piVar6;
            *(undefined4 *)(iVar3 + 0x14) = 0x73;
            *(int *)(iVar3 + 0x18) = iVar1;
            *(int *)(iVar3 + 0x1c) = iVar8;
            (**(code **)(iVar3 + 4))(piVar6,0xffffffff);
          }
          piVar7[iVar8] = piVar6[0x68];
          iVar8 = iVar8 + 1;
        } while (iVar8 <= piVar6[0x66]);
      }
      param_1 = (int *)((int)param_1 + 1);
      local_c = local_c + 1;
    } while ((int)param_1 < piVar6[0x53]);
  }
  if (piVar6[0x67] == 0) {
    if (bVar9) {
      *(code **)(iVar2 + 4) = FUN_00951a10;
    }
    else {
      *(code **)(iVar2 + 4) = FUN_009517e0;
    }
  }
  else if (bVar9) {
    *(code **)(iVar2 + 4) = FUN_00951d30;
  }
  else {
    *(code **)(iVar2 + 4) = FUN_00951c40;
  }
  param_1 = (int *)0x0;
  if (0 < piVar6[0x53]) {
    local_10 = (undefined4 *)(iVar2 + 0x18);
    local_c = piVar6 + 0x54;
    do {
      if (bVar9) {
        iVar1 = *(int *)(*local_c + 0x18);
        puVar4 = (undefined4 *)(iVar2 + 0x2c + iVar1 * 4);
        FUN_00950c40(piVar6,0,iVar1,puVar4);
        *(undefined4 *)(iVar2 + 0x3c) = *puVar4;
      }
      else if (piVar6[0x67] == 0) {
        iVar1 = *(int *)(*local_c + 0x14);
        FUN_00950c40(piVar6,1,iVar1,iVar2 + 0x2c + iVar1 * 4);
      }
      *local_10 = 0;
      local_10 = local_10 + 1;
      param_1 = (int *)((int)param_1 + 1);
      local_c = local_c + 1;
    } while ((int)param_1 < piVar6[0x53]);
  }
  iVar1 = piVar6[0x46];
  *(undefined4 *)(iVar2 + 0x10) = 0;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 8) = 0;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  *(int *)(iVar2 + 0x28) = iVar1;
  return;
}


// ==== FUN_00952320 @ 0x00952320 ====

void FUN_00952320(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x40);
  iVar3 = *(int *)(param_1 + 0x24);
  puVar2 = *(undefined4 **)(param_1 + 4);
  *puVar1 = FUN_009520d0;
  *(undefined4 **)(param_1 + 0x1c0) = puVar1;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0;
  puVar2 = (undefined4 *)(*(code *)*puVar2)(param_1,1,iVar3 << 8);
  *(undefined4 **)(param_1 + 0xa4) = puVar2;
  if (0 < (int)*(uint *)(param_1 + 0x24)) {
    for (iVar3 = (*(uint *)(param_1 + 0x24) & 0xffffff) << 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = 0xffffffff;
      puVar2 = puVar2 + 1;
    }
  }
  return;
}


// ==== FUN_00952390 @ 0x00952390 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00952390(int *param_1)

{
  undefined4 *puVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  undefined2 *puVar6;
  double *pdVar7;
  double *pdVar8;
  ushort *puVar9;
  int iVar10;
  short *psVar11;
  undefined4 *local_18;
  int local_14;
  int *local_10;
  int local_c;
  code *local_8;
  
  iVar10 = 0;
  local_c = 0;
  local_8 = (code *)0x0;
  local_14 = 0;
  if (0 < param_1[9]) {
    local_18 = (undefined4 *)(param_1[0x37] + 0x24);
    local_10 = (int *)(param_1[0x71] + 0x2c);
    do {
      switch(*local_18) {
      case 1:
        iVar10 = 0;
        local_8 = FUN_0095fd00;
        local_c = 0;
        break;
      case 2:
        iVar10 = 0;
        local_8 = FUN_0095f850;
        local_c = 0;
        break;
      default:
        puVar1 = (undefined4 *)*param_1;
        puVar1[5] = 7;
        puVar1[6] = *local_18;
LAB_00952487:
        (*(code *)*puVar1)(param_1);
        break;
      case 4:
        iVar10 = 0;
        local_8 = FUN_0095f540;
        local_c = 0;
        break;
      case 8:
        switch(param_1[0x12]) {
        case 0:
          iVar10 = 0;
          local_8 = FUN_0095e420;
          local_c = 0;
          break;
        case 1:
        case 4:
        case 6:
          iVar10 = 1;
          local_8 = FUN_0095dfe0;
          local_c = 1;
          break;
        case 2:
          iVar10 = 2;
          local_8 = FUN_0095dc10;
          local_c = 2;
          break;
        case 3:
          iVar10 = 0;
          local_8 = FUN_0095eda0;
          local_c = 0;
          break;
        case 5:
          iVar10 = 0;
          local_8 = FUN_0095f500;
          local_c = 0;
          break;
        default:
          puVar1 = (undefined4 *)*param_1;
          puVar1[5] = 0x30;
          goto LAB_00952487;
        }
      }
      local_10[-10] = (int)local_8;
      if (((local_18[3] != 0) && (*local_10 != iVar10)) &&
         (puVar2 = (ushort *)local_18[10], puVar2 != (ushort *)0x0)) {
        *local_10 = iVar10;
        if (iVar10 == 0) {
          puVar6 = (undefined2 *)local_18[0xb];
          iVar3 = (int)puVar2 - (int)puVar6;
          iVar4 = 0x40;
          do {
            *puVar6 = *(undefined2 *)(iVar3 + (int)puVar6);
            puVar6 = puVar6 + 1;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        else if (iVar10 == 1) {
          iVar4 = local_18[0xb];
          puVar9 = puVar2 + 3;
          puVar6 = (undefined2 *)(iVar4 + 2);
          psVar11 = &DAT_00a2e570;
          iVar3 = -iVar4;
          do {
            puVar6[-1] = (short)((int)((uint)puVar9[-3] * (int)*psVar11 + 0x800) >> 0xc);
            *puVar6 = (short)((int)((int)*(short *)((int)&DAT_00a2e570 + iVar3 + (int)puVar6) *
                                    (uint)*(ushort *)(((int)puVar2 - iVar4) + (int)puVar6) + 0x800)
                             >> 0xc);
            puVar6[1] = (short)((int)((int)*(short *)((int)&DAT_00a2e572 + iVar3 + (int)puVar6) *
                                      (uint)puVar9[-1] + 0x800) >> 0xc);
            puVar6[2] = (short)((int)((int)*(short *)((int)&DAT_00a2e574 + iVar3 + (int)puVar6) *
                                      (uint)*puVar9 + 0x800) >> 0xc);
            psVar11 = psVar11 + 4;
            puVar6 = puVar6 + 4;
            puVar9 = puVar9 + 4;
            iVar10 = local_c;
          } while ((int)psVar11 < 0xa2e5f0);
        }
        else if (iVar10 == 2) {
          pfVar5 = (float *)local_18[0xb];
          pdVar7 = (double *)&DAT_00a2e468;
          do {
            *pfVar5 = (float)*puVar2 * (float)*pdVar7;
            pdVar8 = pdVar7 + 1;
            pfVar5[1] = (float)puVar2[1] * (float)*pdVar7 * (float)_DAT_00a2e460;
            pfVar5[2] = (float)puVar2[2] * (float)*pdVar7 * (float)_DAT_00a2e458;
            pfVar5[3] = (float)puVar2[3] * (float)*pdVar7 * (float)_DAT_00a2e450;
            pfVar5[4] = (float)puVar2[4] * (float)*pdVar7;
            pfVar5[5] = (float)puVar2[5] * (float)*pdVar7 * (float)_DAT_00a2e448;
            pfVar5[6] = (float)puVar2[6] * (float)*pdVar7 * (float)_DAT_00a2e440;
            pfVar5[7] = (float)puVar2[7] * (float)*pdVar7 * (float)_DAT_00a2e438;
            puVar2 = puVar2 + 8;
            pfVar5 = pfVar5 + 8;
            pdVar7 = pdVar8;
          } while ((int)pdVar8 < 0xa2e4a8);
        }
        else {
          puVar1 = (undefined4 *)*param_1;
          puVar1[5] = 0x30;
          (*(code *)*puVar1)(param_1);
        }
      }
      local_10 = local_10 + 1;
      local_14 = local_14 + 1;
      local_18 = local_18 + 0x15;
    } while (local_14 < param_1[9]);
  }
  return;
}


// ==== FUN_009526f0 @ 0x009526f0 ====

void FUN_009526f0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *local_8;
  
  iVar2 = (int)param_1;
  puVar3 = (undefined4 *)(*(code *)**(undefined4 **)((int)param_1 + 4))(param_1,1,0x54);
  iVar4 = *(int *)((int)param_1 + 0x24);
  iVar1 = *(int *)((int)param_1 + 0xdc);
  iVar5 = 0;
  *(undefined4 **)((int)param_1 + 0x1c4) = puVar3;
  *puVar3 = FUN_00952390;
  if (0 < iVar4) {
    local_8 = (undefined4 *)(iVar1 + 0x50);
    param_1 = puVar3 + 0xb;
    do {
      puVar3 = (undefined4 *)(*(code *)**(undefined4 **)(iVar2 + 4))(iVar2,1,0x100);
      *local_8 = puVar3;
      for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
      *param_1 = 0xffffffff;
      param_1 = param_1 + 1;
      iVar5 = iVar5 + 1;
      local_8 = local_8 + 0x15;
    } while (iVar5 < *(int *)(iVar2 + 0x24));
  }
  return;
}


// ==== FUN_00952780 @ 0x00952780 ====

void FUN_00952780(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int *param_6,int param_7)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  piVar4 = param_6;
  iVar3 = param_1;
  iVar2 = *(int *)(param_1 + 0x1b4);
  uVar5 = param_7 - *param_6;
  if (*(uint *)(iVar2 + 0x10) < (uint)(param_7 - *param_6)) {
    uVar5 = *(uint *)(iVar2 + 0x10);
  }
  piVar1 = (int *)(param_1 + 0x1c8);
  param_1 = 0;
  (**(code **)(*piVar1 + 4))
            (iVar3,param_2,param_3,param_4,*(undefined4 *)(iVar2 + 0xc),&param_1,uVar5);
  (**(code **)(*(int *)(iVar3 + 0x1d0) + 4))
            (iVar3,*(undefined4 *)(iVar2 + 0xc),param_5 + *piVar4 * 4,param_1);
  *piVar4 = *piVar4 + param_1;
  return;
}


// ==== FUN_00952800 @ 0x00952800 ====

void FUN_00952800(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = param_1[0x6d];
  if (param_2 != 0) {
    puVar2 = (undefined4 *)*param_1;
    puVar2[5] = 4;
    (*(code *)*puVar2)(param_1);
    *(undefined4 *)(iVar1 + 0x18) = 0;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    return;
  }
  if (param_1[0x15] == 0) {
    *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(param_1[0x72] + 4);
  }
  else {
    *(code **)(iVar1 + 4) = FUN_00952780;
    if (*(int *)(iVar1 + 0xc) == 0) {
      uVar3 = (**(code **)(param_1[1] + 0x1c))
                        (param_1,*(undefined4 *)(iVar1 + 8),0,*(undefined4 *)(iVar1 + 0x10),1);
      *(undefined4 *)(iVar1 + 0x18) = 0;
      *(undefined4 *)(iVar1 + 0x14) = 0;
      *(undefined4 *)(iVar1 + 0xc) = uVar3;
      return;
    }
  }
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  return;
}


// ==== FUN_00952880 @ 0x00952880 ====

void FUN_00952880(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar2 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x1c);
  iVar1 = param_1[0x15];
  param_1[0x6d] = (int)puVar2;
  *puVar2 = FUN_00952800;
  puVar2[2] = 0;
  puVar2[3] = 0;
  if (iVar1 != 0) {
    iVar1 = param_1[0x4f];
    puVar2[4] = iVar1;
    if (param_2 != 0) {
      puVar2 = (undefined4 *)*param_1;
      puVar2[5] = 4;
      (*(code *)*puVar2)(param_1);
      return;
    }
    uVar3 = (**(code **)(param_1[1] + 8))(param_1,1,param_1[0x1e] * param_1[0x1c],iVar1);
    puVar2[3] = uVar3;
  }
  return;
}


// ==== FUN_009528f0 @ 0x009528f0 ====

void FUN_009528f0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x1c8);
  uVar2 = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)(param_1 + 0x13c);
  *(undefined4 *)(iVar1 + 0x60) = uVar2;
  return;
}


// ==== FUN_00952920 @ 0x00952920 ====

void FUN_00952920(int param_1,int param_2,int *param_3,undefined4 param_4,int param_5,int *param_6,
                 int param_7)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int local_8;
  
  iVar3 = param_1;
  iVar2 = *(int *)(param_1 + 0x1c8);
  if (*(int *)(param_1 + 0x13c) <= *(int *)(iVar2 + 0x5c)) {
    piVar1 = (int *)(param_1 + 0x24);
    local_8 = *(int *)(param_1 + 0xdc);
    param_1 = 0;
    if (0 < *piVar1) {
      iVar6 = iVar2 + 0xc;
      do {
        (**(code **)(iVar6 + 0x28))
                  (iVar3,local_8,
                   *(int *)(param_2 + param_1 * 4) + *(int *)(iVar6 + 0x58) * *param_3 * 4,iVar6);
        param_1 = param_1 + 1;
        local_8 = local_8 + 0x54;
        iVar6 = iVar6 + 4;
      } while (param_1 < *(int *)(iVar3 + 0x24));
    }
    *(undefined4 *)(iVar2 + 0x5c) = 0;
  }
  uVar7 = *(int *)(iVar3 + 0x13c) - *(int *)(iVar2 + 0x5c);
  if (*(uint *)(iVar2 + 0x60) < uVar7) {
    uVar7 = *(uint *)(iVar2 + 0x60);
  }
  uVar4 = param_7 - *param_6;
  if (uVar4 < uVar7) {
    uVar7 = uVar4;
  }
  (**(code **)(*(int *)(iVar3 + 0x1cc) + 4))
            (iVar3,iVar2 + 0xc,*(undefined4 *)(iVar2 + 0x5c),param_5 + *param_6 * 4,uVar7);
  iVar6 = *(int *)(iVar2 + 0x60);
  *param_6 = *param_6 + uVar7;
  iVar3 = *(int *)(iVar3 + 0x13c);
  iVar5 = *(int *)(iVar2 + 0x5c) + uVar7;
  *(uint *)(iVar2 + 0x60) = iVar6 - uVar7;
  *(int *)(iVar2 + 0x5c) = iVar5;
  if (iVar3 <= iVar5) {
    *param_3 = *param_3 + 1;
  }
  return;
}


// ==== FUN_00952a10 @ 0x00952a10 ====

void FUN_00952a10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  *param_4 = param_3;
  return;
}


// ==== FUN_00952a30 @ 0x00952a30 ====

void FUN_00952a30(void)

{
  undefined4 *in_stack_00000010;
  
  *in_stack_00000010 = 0;
  return;
}


// ==== FUN_00952a50 @ 0x00952a50 ====

void FUN_00952a50(int param_1,int param_2,undefined4 *param_3,int *param_4)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  int local_c;
  
  iVar3 = *param_4;
  iVar4 = *(int *)(param_1 + 0x1c8) + *(int *)(param_2 + 4);
  bVar1 = *(byte *)(iVar4 + 0x8c);
  uVar10 = (uint)bVar1;
  uVar5 = (uint)*(byte *)(iVar4 + 0x96);
  local_c = 0;
  if (0 < *(int *)(param_1 + 0x13c)) {
    param_4 = param_3;
    do {
      puVar7 = (undefined1 *)*param_4;
      puVar9 = *(undefined4 **)(iVar3 + local_c * 4);
      puVar6 = (undefined4 *)(*(int *)(param_1 + 0x70) + (int)puVar9);
      while (puVar9 < puVar6) {
        uVar2 = *puVar7;
        puVar7 = puVar7 + 1;
        if (uVar10 != 0) {
          puVar11 = puVar9;
          for (uVar8 = (uint)(bVar1 >> 2); uVar8 != 0; uVar8 = uVar8 - 1) {
            *puVar11 = CONCAT22(CONCAT11(uVar2,uVar2),CONCAT11(uVar2,uVar2));
            puVar11 = puVar11 + 1;
          }
          for (uVar8 = uVar10 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined1 *)puVar11 = uVar2;
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          puVar9 = (undefined4 *)((int)puVar9 + uVar10);
        }
      }
      if (1 < uVar5) {
        FUN_0090b730(iVar3,local_c,iVar3,local_c + 1,uVar5 - 1,*(undefined4 *)(param_1 + 0x70));
      }
      local_c = local_c + uVar5;
      param_4 = param_4 + 1;
    } while (local_c < *(int *)(param_1 + 0x13c));
  }
  return;
}


// ==== FUN_00952b40 @ 0x00952b40 ====

void FUN_00952b40(int param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  
  puVar6 = (undefined4 *)*param_4;
  param_4 = *(undefined4 **)(param_1 + 0x13c);
  if (0 < (int)param_4) {
    iVar3 = *(int *)(param_1 + 0x70);
    param_3 = param_3 - (int)puVar6;
    do {
      puVar4 = (undefined1 *)*puVar6;
      puVar5 = *(undefined1 **)(param_3 + (int)puVar6);
      puVar1 = puVar4 + iVar3;
      for (; puVar4 < puVar1; puVar4 = puVar4 + 2) {
        uVar2 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar4 = uVar2;
        puVar4[1] = uVar2;
      }
      puVar6 = puVar6 + 1;
      param_4 = (undefined4 *)((int)param_4 + -1);
    } while (param_4 != (undefined4 *)0x0);
  }
  return;
}


// ==== FUN_00952ba0 @ 0x00952ba0 ====

void FUN_00952ba0(int param_1,undefined4 param_2,undefined4 *param_3,int *param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  
  iVar2 = *param_4;
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0x13c)) {
    param_4 = param_3;
    do {
      puVar4 = (undefined1 *)*param_4;
      puVar3 = *(undefined1 **)(iVar2 + iVar5 * 4);
      puVar6 = puVar3 + *(int *)(param_1 + 0x70);
      for (; puVar3 < puVar6; puVar3 = puVar3 + 2) {
        uVar1 = *puVar4;
        puVar4 = puVar4 + 1;
        *puVar3 = uVar1;
        puVar3[1] = uVar1;
      }
      FUN_0090b730(iVar2,iVar5,iVar2,iVar5 + 1,1,*(undefined4 *)(param_1 + 0x70));
      param_4 = param_4 + 1;
      iVar5 = iVar5 + 2;
    } while (iVar5 < *(int *)(param_1 + 0x13c));
  }
  return;
}


// ==== FUN_00952c20 @ 0x00952c20 ====

void FUN_00952c20(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 *in_EAX;
  int iVar6;
  int in_ECX;
  int in_EDX;
  int iVar7;
  uint uVar8;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)*in_EAX;
  if (0 < *(int *)(in_ECX + 0x13c)) {
    iVar2 = *(int *)(in_EDX + 0x28);
    iVar6 = param_1 - (int)local_8;
    param_1 = *(int *)(in_ECX + 0x13c);
    do {
      pbVar3 = *(byte **)(iVar6 + (int)local_8);
      bVar1 = *pbVar3;
      uVar8 = (uint)pbVar3[1];
      pbVar4 = (byte *)*local_8;
      *pbVar4 = bVar1;
      pbVar4[1] = (byte)((int)((uint)bVar1 * 3 + 2 + uVar8) >> 2);
      pbVar3 = pbVar3 + 1;
      for (iVar7 = iVar2 + -2; pbVar4 = pbVar4 + 2, iVar7 != 0; iVar7 = iVar7 + -1) {
        iVar5 = uVar8 * 3;
        uVar8 = (uint)pbVar3[1];
        *pbVar4 = (byte)((int)(pbVar3[-1] + 1 + iVar5) >> 2);
        pbVar4[1] = (byte)((int)(uVar8 + 2 + iVar5) >> 2);
        pbVar3 = pbVar3 + 1;
      }
      bVar1 = *pbVar3;
      *pbVar4 = (byte)((int)(pbVar3[-1] + 1 + (uint)bVar1 * 3) >> 2);
      pbVar4[1] = bVar1;
      local_8 = local_8 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}


// ==== FUN_00952ce0 @ 0x00952ce0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00952ce0(int param_1,int param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  int iVar3;
  ulonglong *puVar4;
  undefined8 *puVar5;
  short sVar7;
  short sVar6;
  undefined8 *puVar8;
  int iVar9;
  int *in_EAX;
  int *piVar10;
  int in_ECX;
  int iVar11;
  byte bVar14;
  short sVar12;
  short sVar13;
  byte bVar15;
  byte bVar18;
  short sVar16;
  short sVar17;
  short sVar19;
  short sVar20;
  short sVar21;
  byte bVar23;
  byte bVar24;
  short sVar22;
  ushort uVar25;
  ushort uVar26;
  ushort uVar27;
  ushort uVar28;
  ushort uVar29;
  ushort uVar30;
  byte bVar32;
  ushort uVar31;
  byte bVar33;
  ushort uVar34;
  byte bVar35;
  ulonglong uVar36;
  
  iVar3 = *(int *)(in_ECX + 0x28);
  piVar10 = (int *)*in_EAX;
  iVar11 = 0;
  if (0 < *(int *)(param_1 + 0x13c)) {
    param_2 = param_2 - (int)piVar10;
    do {
      puVar4 = *(ulonglong **)(param_2 + (int)piVar10);
      puVar5 = (undefined8 *)*piVar10;
      uVar1 = *puVar4;
      bVar18 = (byte)(uVar1 >> 0x18);
      uVar26 = (ushort)(((uint7)bVar18 << 0x30) >> 0x28);
      bVar15 = (byte)(uVar1 >> 0x10);
      bVar14 = (byte)(uVar1 >> 8);
      sVar12 = ((ushort)uVar1 & 0xff) * (short)DAT_00a2e4a8;
      sVar16 = (ushort)bVar14 * (short)((ulonglong)DAT_00a2e4a8 >> 0x10);
      sVar19 = (short)CONCAT21(uVar26,bVar15) * (short)((ulonglong)DAT_00a2e4a8 >> 0x20);
      sVar21 = (uVar26 >> 8) * (short)((ulonglong)DAT_00a2e4a8 >> 0x30);
      uVar36 = uVar1 & _DAT_00a2e4f0;
      uVar29 = (ushort)(((uint7)(byte)(bVar15 + (char)(uVar36 >> 0x18)) << 0x30) >> 0x28);
      bVar32 = (byte)(uVar1 >> 0x20);
      uVar26 = (ushort)(((uint7)bVar32 << 0x30) >> 0x28);
      uVar25 = (ushort)(byte)uVar36 + sVar12 + (short)DAT_00a2e4d8;
      uVar27 = (ushort)(byte)((char)uVar1 + (char)(uVar36 >> 8)) + sVar16 +
               (short)((ulonglong)DAT_00a2e4d8 >> 0x10);
      uVar28 = (short)CONCAT21(uVar29,bVar14 + (char)(uVar36 >> 0x10)) + sVar19 +
               (short)((ulonglong)DAT_00a2e4d8 >> 0x20);
      uVar29 = (uVar29 >> 8) + sVar21 + (short)((ulonglong)DAT_00a2e4d8 >> 0x30);
      uVar30 = ((ushort)(uVar1 >> 8) & 0xff) + sVar12 + (short)DAT_00a2e4e0;
      uVar31 = (ushort)bVar15 + sVar16 + (short)((ulonglong)DAT_00a2e4e0 >> 0x10);
      uVar34 = (short)CONCAT21(uVar26,bVar18) + sVar19 + (short)((ulonglong)DAT_00a2e4e0 >> 0x20);
      *puVar5 = CONCAT17((char)((ushort)((uVar26 >> 8) + sVar21 +
                                        (short)((ulonglong)DAT_00a2e4e0 >> 0x30)) >> 2) +
                         (byte)(uVar29 >> 10),
                         CONCAT16((byte)(uVar34 >> 10) + (char)(uVar29 >> 2),
                                  CONCAT15((char)(uVar34 >> 2) + (byte)(uVar28 >> 10),
                                           CONCAT14((byte)(uVar31 >> 10) + (char)(uVar28 >> 2),
                                                    CONCAT13((char)(uVar31 >> 2) +
                                                             (byte)(uVar27 >> 10),
                                                             CONCAT12((byte)(uVar30 >> 10) +
                                                                      (char)(uVar27 >> 2),
                                                                      CONCAT11((char)(uVar30 >> 2) +
                                                                               (byte)(uVar25 >> 10),
                                                                               (char)(uVar25 >> 2)))
                                                            )))));
      bVar14 = (byte)(uVar1 >> 0x28);
      bVar15 = (byte)(uVar1 >> 0x30);
      bVar23 = (byte)(uVar1 >> 0x38);
      sVar12 = (ushort)bVar32 * (short)DAT_00a2e4a8;
      sVar16 = (ushort)bVar14 * (short)((ulonglong)DAT_00a2e4a8 >> 0x10);
      sVar19 = (ushort)bVar15 * (short)((ulonglong)DAT_00a2e4a8 >> 0x20);
      sVar21 = (ushort)bVar23 * (short)((ulonglong)DAT_00a2e4a8 >> 0x30);
      uVar36 = puVar4[1];
      uVar26 = (ushort)bVar18 + sVar12 + (short)DAT_00a2e4d8;
      uVar29 = (ushort)bVar32 + sVar16 + (short)((ulonglong)DAT_00a2e4d8 >> 0x10);
      uVar25 = (ushort)bVar14 + sVar19 + (short)((ulonglong)DAT_00a2e4d8 >> 0x20);
      uVar27 = (ushort)bVar15 + sVar21 + (short)((ulonglong)DAT_00a2e4d8 >> 0x30);
      uVar28 = (ushort)bVar14 + sVar12 + (short)DAT_00a2e4e0;
      uVar30 = (ushort)bVar15 + sVar16 + (short)((ulonglong)DAT_00a2e4e0 >> 0x10);
      uVar31 = (ushort)bVar23 + sVar19 + (short)((ulonglong)DAT_00a2e4e0 >> 0x20);
      puVar5[1] = CONCAT17((char)((ushort)((ushort)(byte)uVar36 + sVar21 +
                                          (short)((ulonglong)DAT_00a2e4e0 >> 0x30)) >> 2) +
                           (byte)(uVar27 >> 10),
                           CONCAT16((byte)(uVar31 >> 10) + (char)(uVar27 >> 2),
                                    CONCAT15((char)(uVar31 >> 2) + (byte)(uVar25 >> 10),
                                             CONCAT14((byte)(uVar30 >> 10) + (char)(uVar25 >> 2),
                                                      CONCAT13((char)(uVar30 >> 2) +
                                                               (byte)(uVar29 >> 10),
                                                               CONCAT12((byte)(uVar28 >> 10) +
                                                                        (char)(uVar29 >> 2),
                                                                        CONCAT11((char)(uVar28 >> 2)
                                                                                 + (byte)(uVar26 >>
                                                                                         10),
                                                                                 (char)(uVar26 >> 2)
                                                                                )))))));
      iVar9 = iVar3;
      while( true ) {
        iVar9 = iVar9 + -8;
        puVar8 = puVar5 + 2;
        bVar14 = (byte)(uVar36 >> 8);
        bVar15 = (byte)(uVar36 >> 0x10);
        bVar18 = (byte)(uVar36 >> 0x18);
        bVar33 = (byte)(uVar36 >> 0x20);
        bVar23 = (byte)(uVar36 >> 0x28);
        bVar32 = (byte)(uVar36 >> 0x30);
        bVar24 = (byte)(uVar36 >> 0x38);
        uVar26 = (ushort)(uVar36 >> 8);
        sVar17 = (short)((ulonglong)DAT_00a2e4a8 >> 0x10);
        sVar20 = (short)((ulonglong)DAT_00a2e4a8 >> 0x20);
        sVar22 = (short)((ulonglong)DAT_00a2e4a8 >> 0x30);
        bVar35 = (byte)(uVar1 >> 0x38);
        sVar12 = (short)((ulonglong)DAT_00a2e4d8 >> 0x10);
        sVar21 = (short)((ulonglong)DAT_00a2e4d8 >> 0x20);
        sVar6 = (short)((ulonglong)DAT_00a2e4d8 >> 0x30);
        sVar16 = (short)((ulonglong)DAT_00a2e4e0 >> 0x10);
        sVar19 = (short)((ulonglong)DAT_00a2e4e0 >> 0x20);
        sVar7 = (short)((ulonglong)DAT_00a2e4e0 >> 0x30);
        if (iVar9 < 9) break;
        uVar29 = (ushort)(((uint7)bVar18 << 0x30) >> 0x28);
        sVar13 = ((ushort)uVar36 & 0xff) * (short)DAT_00a2e4a8;
        sVar17 = (ushort)bVar14 * sVar17;
        sVar20 = (short)CONCAT21(uVar29,bVar15) * sVar20;
        sVar22 = (uVar29 >> 8) * sVar22;
        uVar25 = (ushort)(((uint7)bVar15 << 0x30) >> 0x28);
        uVar29 = (ushort)(((uint7)bVar33 << 0x30) >> 0x28);
        uVar27 = (ushort)bVar35 + sVar13 + (short)DAT_00a2e4d8;
        uVar28 = (ushort)(byte)uVar36 + sVar17 + sVar12;
        uVar30 = (short)CONCAT21(uVar25,bVar14) + sVar20 + sVar21;
        uVar25 = (uVar25 >> 8) + sVar22 + sVar6;
        uVar26 = (uVar26 & 0xff) + sVar13 + (short)DAT_00a2e4e0;
        uVar31 = (ushort)bVar15 + sVar17 + sVar16;
        uVar34 = (short)CONCAT21(uVar29,bVar18) + sVar20 + sVar19;
        *puVar8 = CONCAT17((char)((ushort)((uVar29 >> 8) + sVar22 + sVar7) >> 2) +
                           (byte)(uVar25 >> 10),
                           CONCAT16((byte)(uVar34 >> 10) + (char)(uVar25 >> 2),
                                    CONCAT15((char)(uVar34 >> 2) + (byte)(uVar30 >> 10),
                                             CONCAT14((byte)(uVar31 >> 10) + (char)(uVar30 >> 2),
                                                      CONCAT13((char)(uVar31 >> 2) +
                                                               (byte)(uVar28 >> 10),
                                                               CONCAT12((byte)(uVar26 >> 10) +
                                                                        (char)(uVar28 >> 2),
                                                                        CONCAT11((char)(uVar26 >> 2)
                                                                                 + (byte)(uVar27 >>
                                                                                         10),
                                                                                 (char)(uVar27 >> 2)
                                                                                )))))));
        sVar12 = (ushort)bVar33 * (short)DAT_00a2e4a8;
        sVar16 = (ushort)bVar23 * (short)((ulonglong)DAT_00a2e4a8 >> 0x10);
        sVar19 = (ushort)bVar32 * (short)((ulonglong)DAT_00a2e4a8 >> 0x20);
        sVar21 = (ushort)bVar24 * (short)((ulonglong)DAT_00a2e4a8 >> 0x30);
        uVar2 = puVar4[2];
        uVar26 = (ushort)bVar18 + sVar12 + (short)DAT_00a2e4d8;
        uVar29 = (ushort)bVar33 + sVar16 + (short)((ulonglong)DAT_00a2e4d8 >> 0x10);
        uVar25 = (ushort)bVar23 + sVar19 + (short)((ulonglong)DAT_00a2e4d8 >> 0x20);
        uVar27 = (ushort)bVar32 + sVar21 + (short)((ulonglong)DAT_00a2e4d8 >> 0x30);
        uVar28 = (ushort)bVar23 + sVar12 + (short)DAT_00a2e4e0;
        uVar30 = (ushort)bVar32 + sVar16 + (short)((ulonglong)DAT_00a2e4e0 >> 0x10);
        uVar31 = (ushort)bVar24 + sVar19 + (short)((ulonglong)DAT_00a2e4e0 >> 0x20);
        puVar5[3] = CONCAT17((char)((ushort)((ushort)(byte)uVar2 + sVar21 +
                                            (short)((ulonglong)DAT_00a2e4e0 >> 0x30)) >> 2) +
                             (byte)(uVar27 >> 10),
                             CONCAT16((byte)(uVar31 >> 10) + (char)(uVar27 >> 2),
                                      CONCAT15((char)(uVar31 >> 2) + (byte)(uVar25 >> 10),
                                               CONCAT14((byte)(uVar30 >> 10) + (char)(uVar25 >> 2),
                                                        CONCAT13((char)(uVar30 >> 2) +
                                                                 (byte)(uVar29 >> 10),
                                                                 CONCAT12((byte)(uVar28 >> 10) +
                                                                          (char)(uVar29 >> 2),
                                                                          CONCAT11((char)(uVar28 >>
                                                                                         2) +
                                                                                   (byte)(uVar26 >>
                                                                                         10),
                                                                                   (char)(uVar26 >>
                                                                                         2))))))));
        puVar4 = puVar4 + 1;
        uVar1 = uVar36;
        uVar36 = uVar2;
        puVar5 = puVar8;
      }
      uVar29 = (ushort)(((uint7)bVar18 << 0x30) >> 0x28);
      sVar13 = ((ushort)uVar36 & 0xff) * (short)DAT_00a2e4a8;
      sVar17 = (ushort)bVar14 * sVar17;
      sVar20 = (short)CONCAT21(uVar29,bVar15) * sVar20;
      sVar22 = (uVar29 >> 8) * sVar22;
      uVar25 = (ushort)(((uint7)bVar15 << 0x30) >> 0x28);
      uVar29 = (ushort)(((uint7)bVar33 << 0x30) >> 0x28);
      uVar27 = (ushort)bVar35 + sVar13 + (short)DAT_00a2e4d8;
      uVar28 = (ushort)(byte)uVar36 + sVar17 + sVar12;
      uVar30 = (short)CONCAT21(uVar25,bVar14) + sVar20 + sVar21;
      uVar25 = (uVar25 >> 8) + sVar22 + sVar6;
      uVar26 = (uVar26 & 0xff) + sVar13 + (short)DAT_00a2e4e0;
      uVar31 = (ushort)bVar15 + sVar17 + sVar16;
      uVar34 = (short)CONCAT21(uVar29,bVar18) + sVar20 + sVar19;
      *puVar8 = CONCAT17((char)((ushort)((uVar29 >> 8) + sVar22 + sVar7) >> 2) +
                         (byte)(uVar25 >> 10),
                         CONCAT16((byte)(uVar34 >> 10) + (char)(uVar25 >> 2),
                                  CONCAT15((char)(uVar34 >> 2) + (byte)(uVar30 >> 10),
                                           CONCAT14((byte)(uVar31 >> 10) + (char)(uVar30 >> 2),
                                                    CONCAT13((char)(uVar31 >> 2) +
                                                             (byte)(uVar28 >> 10),
                                                             CONCAT12((byte)(uVar26 >> 10) +
                                                                      (char)(uVar28 >> 2),
                                                                      CONCAT11((char)(uVar26 >> 2) +
                                                                               (byte)(uVar27 >> 10),
                                                                               (char)(uVar27 >> 2)))
                                                            )))));
      if (4 < iVar9) {
        sVar12 = (ushort)bVar33 * (short)DAT_00a2e4a8;
        sVar16 = (ushort)bVar23 * (short)((ulonglong)DAT_00a2e4a8 >> 0x10);
        sVar19 = (ushort)bVar32 * (short)((ulonglong)DAT_00a2e4a8 >> 0x20);
        sVar21 = (ushort)bVar24 * (short)((ulonglong)DAT_00a2e4a8 >> 0x30);
        uVar36 = uVar36 & _DAT_00a2e4e8;
        uVar26 = (ushort)bVar18 + sVar12 + (short)DAT_00a2e4d8;
        uVar29 = (ushort)bVar33 + sVar16 + (short)((ulonglong)DAT_00a2e4d8 >> 0x10);
        uVar25 = (ushort)bVar23 + sVar19 + (short)((ulonglong)DAT_00a2e4d8 >> 0x20);
        uVar27 = (ushort)bVar32 + sVar21 + (short)((ulonglong)DAT_00a2e4d8 >> 0x30);
        uVar28 = (ushort)(byte)(bVar23 + (char)(uVar36 >> 0x20)) + sVar12 + (short)DAT_00a2e4e0;
        uVar30 = (ushort)(byte)(bVar32 + (char)(uVar36 >> 0x28)) + sVar16 +
                 (short)((ulonglong)DAT_00a2e4e0 >> 0x10);
        uVar31 = (ushort)(byte)(bVar24 + (char)(uVar36 >> 0x30)) + sVar19 +
                 (short)((ulonglong)DAT_00a2e4e0 >> 0x20);
        puVar5[3] = CONCAT17((char)((ushort)((ushort)(byte)(uVar36 >> 0x38) + sVar21 +
                                            (short)((ulonglong)DAT_00a2e4e0 >> 0x30)) >> 2) +
                             (byte)(uVar27 >> 10),
                             CONCAT16((byte)(uVar31 >> 10) + (char)(uVar27 >> 2),
                                      CONCAT15((char)(uVar31 >> 2) + (byte)(uVar25 >> 10),
                                               CONCAT14((byte)(uVar30 >> 10) + (char)(uVar25 >> 2),
                                                        CONCAT13((char)(uVar30 >> 2) +
                                                                 (byte)(uVar29 >> 10),
                                                                 CONCAT12((byte)(uVar28 >> 10) +
                                                                          (char)(uVar29 >> 2),
                                                                          CONCAT11((char)(uVar28 >>
                                                                                         2) +
                                                                                   (byte)(uVar26 >>
                                                                                         10),
                                                                                   (char)(uVar26 >>
                                                                                         2))))))));
      }
      iVar11 = iVar11 + 1;
      piVar10 = piVar10 + 1;
    } while (iVar11 < *(int *)(param_1 + 0x13c));
  }
  return;
}


// ==== FUN_00952f70 @ 0x00952f70 ====

void FUN_00952f70(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int *in_EAX;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  int in_EDX;
  byte *pbVar8;
  byte *pbVar9;
  int local_14;
  int local_10;
  int local_c;
  
  iVar1 = *in_EAX;
  iVar2 = *(int *)(in_EDX + 0x13c);
  iVar4 = 0;
  if (0 < iVar2) {
    iVar6 = *(int *)(param_1 + 0x28) + -2;
    do {
      pbVar3 = (byte *)*param_2;
      local_14 = 0;
      do {
        if (local_14 == 0) {
          pbVar9 = (byte *)param_2[-1];
        }
        else {
          pbVar9 = (byte *)param_2[1];
        }
        puVar7 = *(undefined1 **)(iVar1 + iVar4 * 4);
        iVar4 = iVar4 + 1;
        param_1 = (uint)*pbVar3 * 3 + (uint)*pbVar9;
        iVar5 = (uint)pbVar3[1] * 3 + (uint)pbVar9[1];
        *puVar7 = (char)(param_1 * 4 + 8 >> 4);
        pbVar9 = pbVar9 + 2;
        pbVar8 = pbVar3 + 2;
        puVar7[1] = (char)(param_1 * 3 + 7 + iVar5 >> 4);
        puVar7 = puVar7 + 2;
        if (iVar6 != 0) {
          local_10 = iVar6;
          local_c = iVar5;
          do {
            iVar5 = (uint)*pbVar8 * 3 + (uint)*pbVar9;
            *puVar7 = (char)(local_c * 3 + 8 + param_1 >> 4);
            pbVar9 = pbVar9 + 1;
            pbVar8 = pbVar8 + 1;
            param_1 = local_c;
            puVar7[1] = (char)(local_c * 3 + 7 + iVar5 >> 4);
            puVar7 = puVar7 + 2;
            local_10 = local_10 + -1;
            local_c = iVar5;
          } while (local_10 != 0);
        }
        *puVar7 = (char)(iVar5 * 3 + 8 + param_1 >> 4);
        puVar7[1] = (char)(iVar5 * 4 + 7 >> 4);
        local_14 = local_14 + 1;
      } while (local_14 < 2);
      param_2 = param_2 + 1;
    } while (iVar4 < iVar2);
  }
  return;
}


// ==== FUN_009530a0 @ 0x009530a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009530a0(int param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined4 *puVar9;
  int iVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  int *in_EAX;
  undefined8 *puVar17;
  undefined8 *puVar18;
  int in_EDX;
  ulonglong *puVar19;
  int iVar20;
  ulonglong *puVar21;
  ulonglong *puVar22;
  undefined8 *puVar23;
  undefined8 *puVar24;
  undefined1 uVar31;
  short sVar25;
  short sVar26;
  ushort uVar27;
  short sVar28;
  undefined4 uVar29;
  undefined1 uVar32;
  undefined1 uVar34;
  short sVar33;
  short sVar35;
  undefined6 uVar30;
  char cVar36;
  char cVar37;
  short sVar38;
  byte bVar40;
  short sVar39;
  short sVar41;
  short sVar42;
  undefined4 uVar43;
  short sVar45;
  short sVar46;
  undefined6 uVar44;
  short sVar47;
  short sVar48;
  short sVar49;
  short sVar50;
  char cVar59;
  undefined6 uVar51;
  undefined1 uVar53;
  undefined1 uVar54;
  short sVar55;
  undefined1 uVar56;
  short sVar57;
  short sVar58;
  char cVar60;
  short sVar61;
  undefined8 uVar52;
  byte bVar62;
  undefined4 uVar63;
  undefined4 uVar64;
  undefined6 uVar65;
  undefined6 uVar66;
  ulonglong uVar67;
  ulonglong uVar68;
  
  iVar2 = *in_EAX;
  iVar3 = *(int *)(in_EDX + 0x28);
  iVar20 = 0;
  puVar9 = param_2;
  if (0 < *(int *)(param_1 + 0x13c)) {
    do {
      param_2 = puVar9 + 1;
      puVar19 = (ulonglong *)*puVar9;
      puVar21 = (ulonglong *)puVar9[-1];
      puVar22 = (ulonglong *)*param_2;
      puVar23 = *(undefined8 **)(iVar2 + iVar20 * 4);
      puVar24 = *(undefined8 **)(iVar2 + 4 + iVar20 * 4);
      puVar18 = (undefined8 *)((int)puVar23 + iVar3 * 4);
      iVar20 = iVar20 + 2;
      uVar67 = *puVar19;
      uVar68 = *puVar21;
      uVar7 = (undefined1)((uint)(undefined4)DAT_00a2e4f8 >> 0x18);
      uVar34 = (undefined1)(uVar67 >> 0x18);
      sVar4 = CONCAT11(uVar7,uVar34);
      uVar6 = (undefined1)((uint)(undefined4)DAT_00a2e4f8 >> 0x10);
      uVar32 = (undefined1)(uVar67 >> 0x10);
      uVar5 = (undefined1)((uint)(undefined4)DAT_00a2e4f8 >> 8);
      uVar31 = (undefined1)(uVar67 >> 8);
      sVar33 = CONCAT11(uVar5,uVar31);
      sVar35 = CONCAT11((char)(undefined4)DAT_00a2e4f8,(char)uVar67);
      sVar25 = sVar35 * (short)DAT_00a2e4b8;
      sVar38 = (short)CONCAT31(CONCAT21(sVar4,uVar6),uVar32);
      uVar56 = (undefined1)(uVar68 >> 0x18);
      sVar39 = CONCAT11(uVar7,uVar56);
      uVar54 = (undefined1)(uVar68 >> 0x10);
      uVar53 = (undefined1)(uVar68 >> 8);
      sVar41 = CONCAT11(uVar5,uVar53);
      sVar50 = CONCAT11((char)(undefined4)DAT_00a2e4f8,(char)uVar68);
      sVar42 = (short)DAT_00a2e4c0;
      uVar11 = (ulonglong)DAT_00a2e4c0 >> 0x10;
      uVar12 = (ulonglong)DAT_00a2e4c0 >> 0x20;
      sVar57 = (short)CONCAT31(CONCAT21(sVar39,uVar6),uVar54);
      uVar13 = (ulonglong)DAT_00a2e4c0 >> 0x30;
      sVar45 = sVar35 * (short)((ulonglong)DAT_00a2e4a8 >> 0x10) +
               sVar33 * (short)((ulonglong)DAT_00a2e4b8 >> 0x10);
      sVar46 = sVar33 * (short)((ulonglong)DAT_00a2e4a8 >> 0x20) +
               sVar38 * (short)((ulonglong)DAT_00a2e4b8 >> 0x20);
      sVar47 = sVar38 * (short)((ulonglong)DAT_00a2e4a8 >> 0x30) +
               sVar4 * (short)((ulonglong)DAT_00a2e4b8 >> 0x30);
      *puVar18 = CONCAT26(sVar47,CONCAT24(sVar46,CONCAT22(sVar45,sVar25)));
      sVar4 = (short)DAT_00a2e4d0;
      uVar14 = (ulonglong)DAT_00a2e4d0 >> 0x10;
      uVar15 = (ulonglong)DAT_00a2e4d0 >> 0x20;
      uVar16 = (ulonglong)DAT_00a2e4d0 >> 0x30;
      uVar8 = (undefined1)((uint)(undefined4)DAT_00a2e4f8 >> 0x18);
      uVar7 = (undefined1)((uint)(undefined4)DAT_00a2e4f8 >> 0x10);
      uVar6 = (undefined1)((uint)(undefined4)DAT_00a2e4f8 >> 8);
      uVar5 = (undefined1)(undefined4)DAT_00a2e4f8;
      sVar48 = CONCAT11(uVar8,(char)(uVar67 >> 0x20));
      sVar33 = (short)((ulonglong)DAT_00a2e4a8 >> 0x10);
      sVar35 = (short)((ulonglong)DAT_00a2e4a8 >> 0x20);
      sVar38 = (short)((ulonglong)DAT_00a2e4a8 >> 0x30);
      sVar28 = CONCAT11(uVar8,(char)(uVar68 >> 0x20));
      sVar49 = CONCAT11(uVar5,(char)uVar68) * (short)DAT_00a2e4a8;
      sVar55 = CONCAT11(uVar6,uVar53) * sVar33;
      sVar58 = (short)CONCAT31(CONCAT21(CONCAT11(uVar8,uVar56),uVar7),uVar54) * sVar35;
      sVar61 = CONCAT11(uVar8,uVar56) * sVar38;
      uVar52 = CONCAT26(sVar61,CONCAT24(sVar58,CONCAT22(sVar55,sVar49)));
      sVar26 = CONCAT11(uVar5,(char)uVar67) * (short)DAT_00a2e4b0 +
               CONCAT11(uVar5,uVar31) * (short)DAT_00a2e4a8;
      sVar33 = CONCAT11(uVar6,uVar31) * (short)((ulonglong)DAT_00a2e4b0 >> 0x10) +
               CONCAT11(uVar6,uVar32) * sVar33;
      sVar35 = (short)CONCAT31(CONCAT21(CONCAT11(uVar8,uVar34),uVar7),uVar32) *
               (short)((ulonglong)DAT_00a2e4b0 >> 0x20) +
               (short)CONCAT31(CONCAT21(sVar48,uVar7),uVar34) * sVar35;
      sVar38 = CONCAT11(uVar8,uVar34) * (short)((ulonglong)DAT_00a2e4b0 >> 0x30) + sVar48 * sVar38;
      puVar18[1] = CONCAT26(sVar38,CONCAT24(sVar35,CONCAT22(sVar33,sVar26)));
      uVar27 = (ushort)(sVar26 + CONCAT11(uVar5,uVar53) + (short)DAT_00a2e4c8 + sVar49) >> 4;
      uVar29 = CONCAT22((ushort)(sVar33 + CONCAT11(uVar6,uVar54) +
                                 (short)((ulonglong)DAT_00a2e4c8 >> 0x10) + sVar55) >> 4,uVar27);
      uVar30 = CONCAT24((ushort)(sVar35 + (short)CONCAT31(CONCAT21(sVar28,uVar7),uVar56) +
                                 (short)((ulonglong)DAT_00a2e4c8 >> 0x20) + sVar58) >> 4,uVar29);
      *puVar23 = CONCAT26(((ushort)(sVar47 + sVar57 + sVar39 * (short)uVar13 + (short)uVar16) >> 4)
                          + (short)(CONCAT26((ushort)(sVar38 + sVar28 +
                                                      (short)((ulonglong)DAT_00a2e4c8 >> 0x30) +
                                                     sVar61) >> 4,uVar30) >> 0x28),
                          CONCAT24(((ushort)(sVar46 + sVar41 + sVar57 * (short)uVar12 +
                                            (short)uVar15) >> 4) + (short)((uint6)uVar30 >> 0x18),
                                   CONCAT22(((ushort)(sVar45 + sVar50 + sVar41 * (short)uVar11 +
                                                     (short)uVar14) >> 4) +
                                            (short)((uint)uVar29 >> 8),
                                            ((ushort)(sVar25 + sVar50 * sVar42 + sVar4) >> 4) +
                                            uVar27 * 0x100)));
      puVar23 = puVar23 + 1;
      puVar17 = puVar18 + 2;
      iVar10 = iVar3;
      while( true ) {
        iVar10 = iVar10 + -8;
        uVar5 = (undefined1)DAT_00a2e4f8._4_4_;
        uVar6 = (undefined1)((uint)DAT_00a2e4f8._4_4_ >> 8);
        uVar7 = (undefined1)((uint)DAT_00a2e4f8._4_4_ >> 0x10);
        uVar8 = (undefined1)((uint)DAT_00a2e4f8._4_4_ >> 0x18);
        uVar32 = (undefined1)(uVar67 >> 0x18);
        uVar31 = (undefined1)(uVar67 >> 0x20);
        cVar36 = (char)(uVar67 >> 0x28);
        cVar37 = (char)(uVar67 >> 0x30);
        bVar40 = (byte)(uVar67 >> 0x38);
        sVar33 = (short)((ulonglong)DAT_00a2e4b0 >> 0x10);
        sVar38 = (short)((ulonglong)DAT_00a2e4b0 >> 0x20);
        sVar39 = (short)((ulonglong)DAT_00a2e4b0 >> 0x30);
        sVar4 = (short)DAT_00a2e4a8;
        sVar42 = (short)((ulonglong)DAT_00a2e4a8 >> 0x10);
        sVar35 = (short)((ulonglong)DAT_00a2e4a8 >> 0x20);
        sVar48 = (short)((ulonglong)DAT_00a2e4a8 >> 0x30);
        uVar53 = (undefined1)(uVar68 >> 0x18);
        uVar34 = (undefined1)(uVar68 >> 0x20);
        cVar59 = (char)(uVar68 >> 0x28);
        cVar60 = (char)(uVar68 >> 0x30);
        bVar62 = (byte)(uVar68 >> 0x38);
        if (iVar10 < 1) break;
        uVar29 = CONCAT13(uVar6,CONCAT12(cVar36,CONCAT11(uVar5,uVar31)));
        uVar30 = CONCAT15(uVar7,CONCAT14(cVar37,uVar29));
        sVar41 = CONCAT11(uVar5,uVar32);
        uVar43 = CONCAT13(uVar6,CONCAT12(uVar31,sVar41));
        uVar44 = CONCAT15(uVar7,CONCAT14(cVar36,uVar43));
        sVar28 = CONCAT11(uVar5,uVar31) * (short)DAT_00a2e4b0;
        sVar33 = (short)((uint)uVar29 >> 0x10) * sVar33;
        sVar38 = (short)((uint6)uVar30 >> 0x20) * sVar38;
        sVar39 = (short)(CONCAT17(uVar8,CONCAT16(bVar40,uVar30)) >> 0x30) * sVar39;
        uVar29 = CONCAT13(uVar6,CONCAT12(cVar59,CONCAT11(uVar5,uVar34)));
        uVar30 = CONCAT15(uVar7,CONCAT14(cVar60,uVar29));
        sVar50 = CONCAT11(uVar5,uVar53);
        uVar63 = CONCAT13(uVar6,CONCAT12(uVar34,sVar50));
        uVar51 = CONCAT15(uVar7,CONCAT14(cVar59,uVar63));
        sVar26 = CONCAT11(uVar5,uVar34) * sVar4;
        sVar45 = (short)((uint)uVar29 >> 0x10) * sVar42;
        sVar46 = (short)((uint6)uVar30 >> 0x20) * sVar35;
        sVar47 = (short)(CONCAT17(uVar8,CONCAT16(bVar62,uVar30)) >> 0x30) * sVar48;
        sVar41 = sVar41 * sVar4 + sVar28;
        sVar25 = (short)((uint)uVar43 >> 0x10) * sVar42 + sVar33;
        sVar35 = (short)((uint6)uVar44 >> 0x20) * sVar35 + sVar38;
        sVar48 = (short)(CONCAT17(uVar8,CONCAT16(cVar37,uVar44)) >> 0x30) * sVar48 + sVar39;
        *puVar17 = CONCAT26(sVar48,CONCAT24(sVar35,CONCAT22(sVar25,sVar41)));
        sVar4 = (short)DAT_00a2e4d0;
        uVar11 = (ulonglong)DAT_00a2e4d0 >> 0x10;
        uVar12 = (ulonglong)DAT_00a2e4d0 >> 0x20;
        uVar13 = (ulonglong)DAT_00a2e4d0 >> 0x30;
        uVar67 = puVar19[1];
        sVar42 = CONCAT11((char)DAT_00a2e4f8._4_4_,cVar36);
        uVar5 = (undefined1)((uint)DAT_00a2e4f8._4_4_ >> 8);
        uVar29 = CONCAT13(uVar5,CONCAT12(cVar37,sVar42));
        uVar6 = (undefined1)((uint)DAT_00a2e4f8._4_4_ >> 0x10);
        uVar30 = CONCAT15(uVar6,CONCAT14(bVar40,uVar29));
        uVar7 = (undefined1)((uint)DAT_00a2e4f8._4_4_ >> 0x18);
        uVar68 = puVar21[1];
        sVar49 = CONCAT11((char)DAT_00a2e4f8._4_4_,cVar59);
        uVar43 = CONCAT13(uVar5,CONCAT12(cVar60,sVar49));
        uVar44 = CONCAT15(uVar6,CONCAT14(bVar62,uVar43));
        sVar28 = sVar28 + sVar42 * (short)DAT_00a2e4a8;
        sVar33 = sVar33 + (short)((uint)uVar29 >> 0x10) * (short)((ulonglong)DAT_00a2e4a8 >> 0x10);
        sVar38 = sVar38 + (short)((uint6)uVar30 >> 0x20) * (short)((ulonglong)DAT_00a2e4a8 >> 0x20);
        sVar39 = sVar39 + (short)(CONCAT17(uVar7,CONCAT16((char)uVar67,uVar30)) >> 0x30) *
                          (short)((ulonglong)DAT_00a2e4a8 >> 0x30);
        puVar17[1] = CONCAT26(sVar39,CONCAT24(sVar38,CONCAT22(sVar33,sVar28)));
        uVar27 = (ushort)(sVar28 + sVar49 + (short)DAT_00a2e4c8 + sVar26) >> 4;
        uVar29 = CONCAT22((ushort)(sVar33 + (short)((uint)uVar43 >> 0x10) +
                                            (short)((ulonglong)DAT_00a2e4c8 >> 0x10) + sVar45) >> 4,
                          uVar27);
        uVar30 = CONCAT24((ushort)(sVar38 + (short)((uint6)uVar44 >> 0x20) +
                                            (short)((ulonglong)DAT_00a2e4c8 >> 0x20) + sVar46) >> 4,
                          uVar29);
        *puVar23 = CONCAT26(((ushort)(sVar48 + (short)uVar13 +
                                     (short)(CONCAT17(uVar8,CONCAT16(cVar60,uVar51)) >> 0x30) +
                                     sVar47) >> 4) +
                            (short)(CONCAT26((ushort)(sVar39 + (short)(CONCAT17(uVar7,CONCAT16((char
                                                  )uVar68,uVar44)) >> 0x30) +
                                                  (short)((ulonglong)DAT_00a2e4c8 >> 0x30) + sVar47)
                                             >> 4,uVar30) >> 0x28),
                            CONCAT24(((ushort)(sVar35 + (short)uVar12 +
                                              (short)((uint6)uVar51 >> 0x20) + sVar46) >> 4) +
                                     (short)((uint6)uVar30 >> 0x18),
                                     CONCAT22(((ushort)(sVar25 + (short)uVar11 +
                                                       (short)((uint)uVar63 >> 0x10) + sVar45) >> 4)
                                              + (short)((uint)uVar29 >> 8),
                                              ((ushort)(sVar41 + sVar4 + sVar50 + sVar26) >> 4) +
                                              uVar27 * 0x100)));
        uVar7 = (undefined1)((uint)(undefined4)DAT_00a2e4f8 >> 0x18);
        uVar34 = (undefined1)(uVar67 >> 0x18);
        sVar35 = CONCAT11(uVar7,uVar34);
        uVar6 = (undefined1)((uint)(undefined4)DAT_00a2e4f8 >> 0x10);
        uVar32 = (undefined1)(uVar67 >> 0x10);
        uVar5 = (undefined1)((uint)(undefined4)DAT_00a2e4f8 >> 8);
        uVar31 = (undefined1)(uVar67 >> 8);
        sVar39 = CONCAT11(uVar5,uVar31);
        sVar28 = CONCAT11((char)(undefined4)DAT_00a2e4f8,(char)uVar67);
        sVar46 = (short)CONCAT31(CONCAT21(sVar35,uVar6),uVar32);
        sVar41 = sVar28 * (short)DAT_00a2e4b0;
        sVar25 = sVar39 * (short)((ulonglong)DAT_00a2e4b0 >> 0x10);
        sVar26 = sVar46 * (short)((ulonglong)DAT_00a2e4b0 >> 0x20);
        sVar35 = sVar35 * (short)((ulonglong)DAT_00a2e4b0 >> 0x30);
        sVar4 = (short)((ulonglong)DAT_00a2e4a8 >> 0x10);
        sVar42 = (short)((ulonglong)DAT_00a2e4a8 >> 0x20);
        sVar33 = (short)((ulonglong)DAT_00a2e4a8 >> 0x30);
        uVar56 = (undefined1)(uVar68 >> 0x18);
        sVar38 = CONCAT11(uVar7,uVar56);
        uVar54 = (undefined1)(uVar68 >> 0x10);
        uVar53 = (undefined1)(uVar68 >> 8);
        sVar48 = CONCAT11(uVar5,uVar53);
        sVar47 = CONCAT11((char)(undefined4)DAT_00a2e4f8,(char)uVar68);
        sVar57 = (short)CONCAT31(CONCAT21(sVar38,uVar6),uVar54);
        sVar50 = sVar47 * (short)DAT_00a2e4a8;
        sVar49 = sVar48 * sVar4;
        sVar55 = sVar57 * sVar42;
        sVar38 = sVar38 * sVar33;
        uVar52 = CONCAT26(sVar38,CONCAT24(sVar55,CONCAT22(sVar49,sVar50)));
        sVar45 = (ushort)bVar40 * (short)DAT_00a2e4a8 + sVar41;
        sVar28 = sVar28 * sVar4 + sVar25;
        sVar39 = sVar39 * sVar42 + sVar26;
        sVar46 = sVar46 * sVar33 + sVar35;
        puVar17[2] = CONCAT26(sVar46,CONCAT24(sVar39,CONCAT22(sVar28,sVar45)));
        sVar4 = (short)DAT_00a2e4d0;
        uVar11 = (ulonglong)DAT_00a2e4d0 >> 0x10;
        uVar12 = (ulonglong)DAT_00a2e4d0 >> 0x20;
        uVar13 = (ulonglong)DAT_00a2e4d0 >> 0x30;
        uVar8 = (undefined1)((uint)(undefined4)DAT_00a2e4f8 >> 0x18);
        sVar42 = CONCAT11(uVar8,(char)(uVar67 >> 0x20));
        uVar7 = (undefined1)((uint)(undefined4)DAT_00a2e4f8 >> 0x10);
        uVar6 = (undefined1)((uint)(undefined4)DAT_00a2e4f8 >> 8);
        uVar5 = (undefined1)(undefined4)DAT_00a2e4f8;
        sVar33 = CONCAT11(uVar8,(char)(uVar68 >> 0x20));
        sVar41 = sVar41 + CONCAT11(uVar5,uVar31) * (short)DAT_00a2e4a8;
        sVar25 = sVar25 + CONCAT11(uVar6,uVar32) * (short)((ulonglong)DAT_00a2e4a8 >> 0x10);
        sVar26 = sVar26 + (short)CONCAT31(CONCAT21(sVar42,uVar7),uVar34) *
                          (short)((ulonglong)DAT_00a2e4a8 >> 0x20);
        sVar35 = sVar35 + sVar42 * (short)((ulonglong)DAT_00a2e4a8 >> 0x30);
        puVar17[3] = CONCAT26(sVar35,CONCAT24(sVar26,CONCAT22(sVar25,sVar41)));
        uVar27 = (ushort)(sVar41 + CONCAT11(uVar5,uVar53) + (short)DAT_00a2e4c8 + sVar50) >> 4;
        uVar29 = CONCAT22((ushort)(sVar25 + CONCAT11(uVar6,uVar54) +
                                   (short)((ulonglong)DAT_00a2e4c8 >> 0x10) + sVar49) >> 4,uVar27);
        uVar30 = CONCAT24((ushort)(sVar26 + (short)CONCAT31(CONCAT21(sVar33,uVar7),uVar56) +
                                   (short)((ulonglong)DAT_00a2e4c8 >> 0x20) + sVar55) >> 4,uVar29);
        puVar23[1] = CONCAT26(((ushort)(sVar46 + (short)uVar13 + sVar57 + sVar38) >> 4) +
                              (short)(CONCAT26((ushort)(sVar35 + sVar33 +
                                                        (short)((ulonglong)DAT_00a2e4c8 >> 0x30) +
                                                       sVar38) >> 4,uVar30) >> 0x28),
                              CONCAT24(((ushort)(sVar39 + (short)uVar12 + sVar48 + sVar55) >> 4) +
                                       (short)((uint6)uVar30 >> 0x18),
                                       CONCAT22(((ushort)(sVar28 + (short)uVar11 + sVar47 + sVar49)
                                                >> 4) + (short)((uint)uVar29 >> 8),
                                                ((ushort)(sVar45 + sVar4 + (ushort)bVar62 + sVar50)
                                                >> 4) + uVar27 * 0x100)));
        puVar23 = puVar23 + 2;
        puVar19 = puVar19 + 1;
        puVar21 = puVar21 + 1;
        puVar17 = puVar17 + 4;
      }
      uVar29 = CONCAT13(uVar6,CONCAT12(cVar36,CONCAT11(uVar5,uVar31)));
      uVar30 = CONCAT15(uVar7,CONCAT14(cVar37,uVar29));
      sVar41 = CONCAT11(uVar5,uVar32);
      uVar43 = CONCAT13(uVar6,CONCAT12(uVar31,sVar41));
      uVar44 = CONCAT15(uVar7,CONCAT14(cVar36,uVar43));
      sVar28 = CONCAT11(uVar5,uVar31) * (short)DAT_00a2e4b0;
      sVar33 = (short)((uint)uVar29 >> 0x10) * sVar33;
      sVar38 = (short)((uint6)uVar30 >> 0x20) * sVar38;
      sVar39 = (short)(CONCAT17(uVar8,CONCAT16(bVar40,uVar30)) >> 0x30) * sVar39;
      sVar47 = CONCAT11(uVar5,uVar53);
      uVar63 = CONCAT13(uVar6,CONCAT12(uVar34,sVar47));
      uVar51 = CONCAT15(uVar7,CONCAT14(cVar59,uVar63));
      sVar41 = sVar41 * sVar4 + sVar28;
      sVar25 = (short)((uint)uVar43 >> 0x10) * sVar42 + sVar33;
      sVar35 = (short)((uint6)uVar44 >> 0x20) * sVar35 + sVar38;
      sVar48 = (short)(CONCAT17(uVar8,CONCAT16(cVar37,uVar44)) >> 0x30) * sVar48 + sVar39;
      *puVar17 = CONCAT26(sVar48,CONCAT24(sVar35,CONCAT22(sVar25,sVar41)));
      sVar4 = (short)DAT_00a2e4d0;
      uVar11 = (ulonglong)DAT_00a2e4d0 >> 0x10;
      uVar12 = (ulonglong)DAT_00a2e4d0 >> 0x20;
      uVar13 = (ulonglong)DAT_00a2e4d0 >> 0x30;
      sVar26 = (short)((ulonglong)uVar52 >> 0x10);
      sVar45 = (short)((ulonglong)uVar52 >> 0x20);
      sVar46 = (short)((ulonglong)uVar52 >> 0x30);
      uVar67 = uVar67 & _DAT_00a2e4e8;
      sVar42 = CONCAT11((char)DAT_00a2e4f8._4_4_,cVar36 + (char)(uVar67 >> 0x20));
      uVar5 = (undefined1)((uint)DAT_00a2e4f8._4_4_ >> 8);
      uVar29 = CONCAT13(uVar5,CONCAT12(cVar37 + (char)(uVar67 >> 0x28),sVar42));
      uVar6 = (undefined1)((uint)DAT_00a2e4f8._4_4_ >> 0x10);
      uVar30 = CONCAT15(uVar6,CONCAT14(bVar40 + (char)(uVar67 >> 0x30),uVar29));
      uVar7 = (undefined1)((uint)DAT_00a2e4f8._4_4_ >> 0x18);
      uVar68 = uVar68 & _DAT_00a2e4e8;
      sVar50 = CONCAT11((char)DAT_00a2e4f8._4_4_,cVar59 + (char)(uVar68 >> 0x20));
      uVar43 = CONCAT13(uVar5,CONCAT12(cVar60 + (char)(uVar68 >> 0x28),sVar50));
      uVar44 = CONCAT15(uVar6,CONCAT14(bVar62 + (char)(uVar68 >> 0x30),uVar43));
      sVar28 = sVar28 + sVar42 * (short)DAT_00a2e4a8;
      sVar33 = sVar33 + (short)((uint)uVar29 >> 0x10) * (short)((ulonglong)DAT_00a2e4a8 >> 0x10);
      sVar38 = sVar38 + (short)((uint6)uVar30 >> 0x20) * (short)((ulonglong)DAT_00a2e4a8 >> 0x20);
      sVar39 = sVar39 + (short)(CONCAT17(uVar7,CONCAT16((char)(uVar67 >> 0x38),uVar30)) >> 0x30) *
                        (short)((ulonglong)DAT_00a2e4a8 >> 0x30);
      puVar17[1] = CONCAT26(sVar39,CONCAT24(sVar38,CONCAT22(sVar33,sVar28)));
      uVar27 = (ushort)(sVar28 + sVar50 + (short)DAT_00a2e4c8 + (short)uVar52) >> 4;
      uVar29 = CONCAT22((ushort)(sVar33 + (short)((uint)uVar43 >> 0x10) +
                                          (short)((ulonglong)DAT_00a2e4c8 >> 0x10) + sVar26) >> 4,
                        uVar27);
      uVar30 = CONCAT24((ushort)(sVar38 + (short)((uint6)uVar44 >> 0x20) +
                                          (short)((ulonglong)DAT_00a2e4c8 >> 0x20) + sVar45) >> 4,
                        uVar29);
      *puVar23 = CONCAT26(((ushort)(sVar48 + (short)uVar13 +
                                   (short)(CONCAT17(uVar8,CONCAT16(cVar60,uVar51)) >> 0x30) + sVar46
                                   ) >> 4) +
                          (short)(CONCAT26((ushort)(sVar39 + (short)(CONCAT17(uVar7,CONCAT16((char)(
                                                  uVar68 >> 0x38),uVar44)) >> 0x30) +
                                                  (short)((ulonglong)DAT_00a2e4c8 >> 0x30) + sVar46)
                                           >> 4,uVar30) >> 0x28),
                          CONCAT24(((ushort)(sVar35 + (short)uVar12 +
                                            (short)((uint6)uVar51 >> 0x20) + sVar45) >> 4) +
                                   (short)((uint6)uVar30 >> 0x18),
                                   CONCAT22(((ushort)(sVar25 + (short)uVar11 +
                                                     (short)((uint)uVar63 >> 0x10) + sVar26) >> 4) +
                                            (short)((uint)uVar29 >> 8),
                                            ((ushort)(sVar41 + sVar4 + sVar47 + (short)uVar52) >> 4)
                                            + uVar27 * 0x100)));
      uVar67 = *puVar22;
      uVar8 = (undefined1)((uint)(undefined4)DAT_00a2e4f8 >> 0x18);
      uVar34 = (undefined1)(uVar67 >> 0x18);
      uVar7 = (undefined1)((uint)(undefined4)DAT_00a2e4f8 >> 0x10);
      uVar32 = (undefined1)(uVar67 >> 0x10);
      uVar6 = (undefined1)((uint)(undefined4)DAT_00a2e4f8 >> 8);
      uVar31 = (undefined1)(uVar67 >> 8);
      uVar5 = (undefined1)(undefined4)DAT_00a2e4f8;
      sVar42 = CONCAT11(uVar5,(char)uVar67);
      sVar33 = (short)CONCAT31(CONCAT21(CONCAT11(uVar8,uVar34),uVar7),uVar32);
      uVar52 = *puVar18;
      sVar4 = CONCAT11(uVar8,(char)(uVar67 >> 0x20));
      uVar1 = puVar18[1];
      uVar27 = (ushort)((short)uVar1 + CONCAT11(uVar5,uVar31) + (short)DAT_00a2e4c8 +
                       CONCAT11(uVar5,(char)uVar67) * (short)DAT_00a2e4a8) >> 4;
      uVar29 = CONCAT22((ushort)((short)((ulonglong)uVar1 >> 0x10) + CONCAT11(uVar6,uVar32) +
                                 (short)((ulonglong)DAT_00a2e4c8 >> 0x10) +
                                CONCAT11(uVar6,uVar31) * (short)((ulonglong)DAT_00a2e4a8 >> 0x10))
                        >> 4,uVar27);
      uVar30 = CONCAT24((ushort)((short)((ulonglong)uVar1 >> 0x20) +
                                 (short)CONCAT31(CONCAT21(sVar4,uVar7),uVar34) +
                                 (short)((ulonglong)DAT_00a2e4c8 >> 0x20) +
                                (short)CONCAT31(CONCAT21(CONCAT11(uVar8,uVar34),uVar7),uVar32) *
                                (short)((ulonglong)DAT_00a2e4a8 >> 0x20)) >> 4,uVar29);
      *puVar24 = CONCAT26(((ushort)((short)((ulonglong)uVar52 >> 0x30) +
                                    sVar33 + CONCAT11(uVar8,uVar34) *
                                             (short)((ulonglong)DAT_00a2e4c0 >> 0x30) +
                                   (short)((ulonglong)DAT_00a2e4d0 >> 0x30)) >> 4) +
                          (short)(CONCAT26((ushort)((short)((ulonglong)uVar1 >> 0x30) + sVar4 +
                                                    (short)((ulonglong)DAT_00a2e4c8 >> 0x30) +
                                                   CONCAT11(uVar8,uVar34) *
                                                   (short)((ulonglong)DAT_00a2e4a8 >> 0x30)) >> 4,
                                           uVar30) >> 0x28),
                          CONCAT24(((ushort)((short)((ulonglong)uVar52 >> 0x20) +
                                             CONCAT11(uVar6,uVar31) +
                                             sVar33 * (short)((ulonglong)DAT_00a2e4c0 >> 0x20) +
                                            (short)((ulonglong)DAT_00a2e4d0 >> 0x20)) >> 4) +
                                   (short)((uint6)uVar30 >> 0x18),
                                   CONCAT22(((ushort)((short)((ulonglong)uVar52 >> 0x10) +
                                                      sVar42 + CONCAT11(uVar6,uVar31) *
                                                               (short)((ulonglong)DAT_00a2e4c0 >>
                                                                      0x10) +
                                                     (short)((ulonglong)DAT_00a2e4d0 >> 0x10)) >> 4)
                                            + (short)((uint)uVar29 >> 8),
                                            ((ushort)((short)uVar52 + sVar42 * (short)DAT_00a2e4c0 +
                                                     (short)DAT_00a2e4d0) >> 4) + uVar27 * 0x100)));
      puVar24 = puVar24 + 1;
      puVar18 = puVar18 + 2;
      iVar10 = iVar3;
      while( true ) {
        iVar10 = iVar10 + -8;
        uVar5 = (undefined1)DAT_00a2e4f8._4_4_;
        uVar6 = (undefined1)((uint)DAT_00a2e4f8._4_4_ >> 8);
        uVar7 = (undefined1)((uint)DAT_00a2e4f8._4_4_ >> 0x10);
        uVar8 = (undefined1)((uint)DAT_00a2e4f8._4_4_ >> 0x18);
        uVar32 = (undefined1)(uVar67 >> 0x18);
        uVar31 = (undefined1)(uVar67 >> 0x20);
        cVar36 = (char)(uVar67 >> 0x28);
        cVar37 = (char)(uVar67 >> 0x30);
        bVar40 = (byte)(uVar67 >> 0x38);
        sVar48 = (short)DAT_00a2e4a8;
        sVar28 = (short)((ulonglong)DAT_00a2e4a8 >> 0x10);
        sVar41 = (short)((ulonglong)DAT_00a2e4a8 >> 0x20);
        sVar25 = (short)((ulonglong)DAT_00a2e4a8 >> 0x30);
        sVar4 = (short)((ulonglong)DAT_00a2e4d0 >> 0x10);
        sVar35 = (short)((ulonglong)DAT_00a2e4d0 >> 0x20);
        sVar39 = (short)((ulonglong)DAT_00a2e4d0 >> 0x30);
        sVar42 = (short)((ulonglong)DAT_00a2e4c8 >> 0x10);
        sVar33 = (short)((ulonglong)DAT_00a2e4c8 >> 0x20);
        sVar38 = (short)((ulonglong)DAT_00a2e4c8 >> 0x30);
        if (iVar10 < 1) break;
        uVar43 = CONCAT13(uVar6,CONCAT12(cVar36,CONCAT11(uVar5,uVar31)));
        uVar44 = CONCAT15(uVar7,CONCAT14(cVar37,uVar43));
        sVar26 = CONCAT11(uVar5,uVar32);
        uVar63 = CONCAT13(uVar6,CONCAT12(uVar31,sVar26));
        uVar65 = CONCAT15(uVar7,CONCAT14(cVar36,uVar63));
        uVar52 = *puVar18;
        uVar29 = CONCAT13(uVar6,CONCAT12(cVar36,CONCAT11(uVar5,uVar31)));
        uVar51 = CONCAT15(uVar7,CONCAT14(cVar37,uVar29));
        uVar67 = puVar22[1];
        uVar53 = (undefined1)uVar67;
        uVar64 = CONCAT13(uVar6,CONCAT12(cVar37,CONCAT11(uVar5,cVar36)));
        uVar66 = CONCAT15(uVar7,CONCAT14(bVar40,uVar64));
        uVar1 = puVar18[1];
        uVar27 = (ushort)((short)uVar1 + CONCAT11(uVar5,cVar36) + (short)DAT_00a2e4c8 +
                         CONCAT11(uVar5,uVar31) * sVar48) >> 4;
        uVar29 = CONCAT22((ushort)((short)((ulonglong)uVar1 >> 0x10) +
                                   (short)((uint)uVar64 >> 0x10) + sVar42 +
                                  (short)((uint)uVar29 >> 0x10) * sVar28) >> 4,uVar27);
        uVar30 = CONCAT24((ushort)((short)((ulonglong)uVar1 >> 0x20) +
                                   (short)((uint6)uVar66 >> 0x20) + sVar33 +
                                  (short)((uint6)uVar51 >> 0x20) * sVar41) >> 4,uVar29);
        *puVar24 = CONCAT26(((ushort)((short)((ulonglong)uVar52 >> 0x30) + sVar39 +
                                     (short)(CONCAT17(uVar8,CONCAT16(cVar37,uVar65)) >> 0x30) +
                                     (short)(CONCAT17(uVar8,CONCAT16(bVar40,uVar44)) >> 0x30) *
                                     sVar25) >> 4) +
                            (short)(CONCAT26((ushort)((short)((ulonglong)uVar1 >> 0x30) +
                                                      (short)(CONCAT17(uVar8,CONCAT16(uVar53,uVar66)
                                                                      ) >> 0x30) + sVar38 +
                                                     (short)(CONCAT17(uVar8,CONCAT16(bVar40,uVar51))
                                                            >> 0x30) * sVar25) >> 4,uVar30) >> 0x28)
                            ,CONCAT24(((ushort)((short)((ulonglong)uVar52 >> 0x20) + sVar35 +
                                               (short)((uint6)uVar65 >> 0x20) +
                                               (short)((uint6)uVar44 >> 0x20) * sVar41) >> 4) +
                                      (short)((uint6)uVar30 >> 0x18),
                                      CONCAT22(((ushort)((short)((ulonglong)uVar52 >> 0x10) + sVar4
                                                        + (short)((uint)uVar63 >> 0x10) +
                                                          (short)((uint)uVar43 >> 0x10) * sVar28) >>
                                               4) + (short)((uint)uVar29 >> 8),
                                               ((ushort)((short)uVar52 + (short)DAT_00a2e4d0 +
                                                        sVar26 + CONCAT11(uVar5,uVar31) * sVar48) >>
                                               4) + uVar27 * 0x100)));
        uVar8 = (undefined1)((uint)(undefined4)DAT_00a2e4f8 >> 0x18);
        uVar34 = (undefined1)(uVar67 >> 0x18);
        uVar7 = (undefined1)((uint)(undefined4)DAT_00a2e4f8 >> 0x10);
        uVar32 = (undefined1)(uVar67 >> 0x10);
        uVar6 = (undefined1)((uint)(undefined4)DAT_00a2e4f8 >> 8);
        uVar31 = (undefined1)(uVar67 >> 8);
        uVar5 = (undefined1)(undefined4)DAT_00a2e4f8;
        sVar38 = (short)CONCAT31(CONCAT21(CONCAT11(uVar8,uVar34),uVar7),uVar32);
        sVar4 = (short)((ulonglong)DAT_00a2e4a8 >> 0x10);
        sVar42 = (short)((ulonglong)DAT_00a2e4a8 >> 0x20);
        sVar33 = (short)((ulonglong)DAT_00a2e4a8 >> 0x30);
        uVar52 = puVar18[2];
        sVar35 = CONCAT11(uVar8,(char)(uVar67 >> 0x20));
        uVar1 = puVar18[3];
        uVar27 = (ushort)((short)uVar1 + CONCAT11(uVar5,uVar31) + (short)DAT_00a2e4c8 +
                         CONCAT11(uVar5,uVar53) * (short)DAT_00a2e4a8) >> 4;
        uVar29 = CONCAT22((ushort)((short)((ulonglong)uVar1 >> 0x10) + CONCAT11(uVar6,uVar32) +
                                   (short)((ulonglong)DAT_00a2e4c8 >> 0x10) +
                                  CONCAT11(uVar6,uVar31) * sVar4) >> 4,uVar27);
        uVar30 = CONCAT24((ushort)((short)((ulonglong)uVar1 >> 0x20) +
                                   (short)CONCAT31(CONCAT21(sVar35,uVar7),uVar34) +
                                   (short)((ulonglong)DAT_00a2e4c8 >> 0x20) +
                                  (short)CONCAT31(CONCAT21(CONCAT11(uVar8,uVar34),uVar7),uVar32) *
                                  sVar42) >> 4,uVar29);
        puVar24[1] = CONCAT26(((ushort)((short)((ulonglong)uVar52 >> 0x30) +
                                        (short)((ulonglong)DAT_00a2e4d0 >> 0x30) +
                                       sVar38 + CONCAT11(uVar8,uVar34) * sVar33) >> 4) +
                              (short)(CONCAT26((ushort)((short)((ulonglong)uVar1 >> 0x30) + sVar35 +
                                                        (short)((ulonglong)DAT_00a2e4c8 >> 0x30) +
                                                       CONCAT11(uVar8,uVar34) * sVar33) >> 4,uVar30)
                                     >> 0x28),
                              CONCAT24(((ushort)((short)((ulonglong)uVar52 >> 0x20) +
                                                 (short)((ulonglong)DAT_00a2e4d0 >> 0x20) +
                                                CONCAT11(uVar6,uVar31) + sVar38 * sVar42) >> 4) +
                                       (short)((uint6)uVar30 >> 0x18),
                                       CONCAT22(((ushort)((short)((ulonglong)uVar52 >> 0x10) +
                                                          (short)((ulonglong)DAT_00a2e4d0 >> 0x10) +
                                                         CONCAT11(uVar5,uVar53) +
                                                         CONCAT11(uVar6,uVar31) * sVar4) >> 4) +
                                                (short)((uint)uVar29 >> 8),
                                                ((ushort)((short)uVar52 + (short)DAT_00a2e4d0 +
                                                         (ushort)bVar40 +
                                                         CONCAT11(uVar5,uVar53) *
                                                         (short)DAT_00a2e4a8) >> 4) + uVar27 * 0x100
                                               )));
        puVar24 = puVar24 + 2;
        puVar22 = puVar22 + 1;
        puVar18 = puVar18 + 4;
      }
      uVar43 = CONCAT13(uVar6,CONCAT12(cVar36,CONCAT11(uVar5,uVar31)));
      uVar44 = CONCAT15(uVar7,CONCAT14(cVar37,uVar43));
      sVar26 = CONCAT11(uVar5,uVar32);
      uVar63 = CONCAT13(uVar6,CONCAT12(uVar31,sVar26));
      uVar65 = CONCAT15(uVar7,CONCAT14(cVar36,uVar63));
      uVar52 = *puVar18;
      uVar29 = CONCAT13(uVar6,CONCAT12(cVar36,CONCAT11(uVar5,uVar31)));
      uVar51 = CONCAT15(uVar7,CONCAT14(cVar37,uVar29));
      uVar67 = uVar67 & _DAT_00a2e4e8;
      sVar45 = CONCAT11(uVar5,cVar36 + (char)(uVar67 >> 0x20));
      uVar64 = CONCAT13(uVar6,CONCAT12(cVar37 + (char)(uVar67 >> 0x28),sVar45));
      uVar66 = CONCAT15(uVar7,CONCAT14(bVar40 + (char)(uVar67 >> 0x30),uVar64));
      uVar1 = puVar18[1];
      uVar27 = (ushort)((short)uVar1 + sVar45 + (short)DAT_00a2e4c8 +
                       CONCAT11(uVar5,uVar31) * sVar48) >> 4;
      uVar29 = CONCAT22((ushort)((short)((ulonglong)uVar1 >> 0x10) +
                                 (short)((uint)uVar64 >> 0x10) + sVar42 +
                                (short)((uint)uVar29 >> 0x10) * sVar28) >> 4,uVar27);
      uVar30 = CONCAT24((ushort)((short)((ulonglong)uVar1 >> 0x20) +
                                 (short)((uint6)uVar66 >> 0x20) + sVar33 +
                                (short)((uint6)uVar51 >> 0x20) * sVar41) >> 4,uVar29);
      *puVar24 = CONCAT26(((ushort)((short)((ulonglong)uVar52 >> 0x30) + sVar39 +
                                   (short)(CONCAT17(uVar8,CONCAT16(cVar37,uVar65)) >> 0x30) +
                                   (short)(CONCAT17(uVar8,CONCAT16(bVar40,uVar44)) >> 0x30) * sVar25
                                   ) >> 4) +
                          (short)(CONCAT26((ushort)((short)((ulonglong)uVar1 >> 0x30) +
                                                    (short)(CONCAT17(uVar8,CONCAT16((char)(uVar67 >>
                                                                                          0x38),
                                                                                    uVar66)) >> 0x30
                                                           ) + sVar38 +
                                                   (short)(CONCAT17(uVar8,CONCAT16(bVar40,uVar51))
                                                          >> 0x30) * sVar25) >> 4,uVar30) >> 0x28),
                          CONCAT24(((ushort)((short)((ulonglong)uVar52 >> 0x20) + sVar35 +
                                            (short)((uint6)uVar65 >> 0x20) +
                                            (short)((uint6)uVar44 >> 0x20) * sVar41) >> 4) +
                                   (short)((uint6)uVar30 >> 0x18),
                                   CONCAT22(((ushort)((short)((ulonglong)uVar52 >> 0x10) + sVar4 +
                                                     (short)((uint)uVar63 >> 0x10) +
                                                     (short)((uint)uVar43 >> 0x10) * sVar28) >> 4) +
                                            (short)((uint)uVar29 >> 8),
                                            ((ushort)((short)uVar52 + (short)DAT_00a2e4d0 +
                                                     sVar26 + CONCAT11(uVar5,uVar31) * sVar48) >> 4)
                                            + uVar27 * 0x100)));
      puVar9 = param_2;
    } while (iVar20 < *(int *)(param_1 + 0x13c));
  }
  return;
}


// ==== FUN_00953670 @ 0x00953670 ====

void FUN_00953670(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (0x10 < *(uint *)(param_2 + 0x28)) {
    iVar2 = 0;
    if (0 < param_1[0x4f]) {
      do {
        if ((*(byte *)(param_3 + iVar2 * 4) & 7) != 0) {
          iVar1 = *param_1;
          *(undefined4 *)(iVar1 + 0x14) = 2;
          (**(code **)(iVar1 + 4))(param_1,0xffffffff);
          break;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1[0x4f]);
    }
    if ((iVar2 == param_1[0x4f]) && ((param_1[0x12] == 5 || (param_1[0x12] == 6)))) {
      FUN_00952ce0(param_1,param_3);
      return;
    }
  }
  FUN_00952c20(param_3);
  return;
}


// ==== FUN_009536f0 @ 0x009536f0 ====

void FUN_009536f0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (0x10 < *(uint *)(param_2 + 0x28)) {
    iVar2 = 0;
    if (0 < param_1[0x4f]) {
      do {
        if ((*(byte *)(param_3 + iVar2 * 4) & 7) != 0) {
          iVar1 = *param_1;
          *(undefined4 *)(iVar1 + 0x14) = 2;
          (**(code **)(iVar1 + 4))(param_1,0xffffffff);
          break;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1[0x4f]);
    }
    if ((iVar2 == param_1[0x4f]) && ((param_1[0x12] == 5 || (param_1[0x12] == 6)))) {
      FUN_009530a0(param_1,param_3);
      return;
    }
  }
  FUN_00952f70(param_2,param_3);
  return;
}


// ==== FUN_00953770 @ 0x00953770 ====

void FUN_00953770(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  bool bVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined1 local_18;
  int local_10;
  
  piVar5 = param_1;
  puVar6 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0xa0);
  iVar1 = param_1[0x4c];
  param_1[0x72] = (int)puVar6;
  *puVar6 = FUN_009528f0;
  puVar6[1] = FUN_00952920;
  puVar6[2] = 0;
  if (iVar1 != 0) {
    puVar11 = (undefined4 *)*param_1;
    puVar11[5] = 0x19;
    (*(code *)*puVar11)(param_1);
  }
  if ((param_1[0x13] == 0) || (bVar4 = true, param_1[0x50] < 2)) {
    bVar4 = false;
  }
  local_10 = 0;
  if (param_1[9] < 1) {
    return;
  }
  param_1 = (int *)(param_1[0x37] + 0x24);
  puVar11 = puVar6 + 0xd;
  do {
    iVar7 = (param_1[-7] * *param_1) / piVar5[0x50];
    iVar8 = (param_1[-6] * *param_1) / piVar5[0x50];
    iVar1 = param_1[3];
    iVar10 = piVar5[0x4f];
    iVar2 = piVar5[0x4e];
    puVar11[0xc] = iVar8;
    if (iVar1 == 0) {
      *puVar11 = FUN_00952a30;
    }
    else if ((iVar7 == iVar2) && (iVar8 == iVar10)) {
      *puVar11 = FUN_00952a10;
    }
    else {
      if (iVar7 * 2 == iVar2) {
        if (iVar8 == iVar10) {
          if ((!bVar4) || ((uint)param_1[1] < 3)) {
            *puVar11 = FUN_00952b40;
          }
          else {
            *puVar11 = FUN_00953670;
          }
        }
        else {
          if ((iVar7 * 2 != iVar2) || (iVar8 * 2 != iVar10)) goto LAB_009538c3;
          if ((!bVar4) || ((uint)param_1[1] < 3)) {
            *puVar11 = FUN_00952ba0;
          }
          else {
            *puVar11 = FUN_009536f0;
            puVar6[2] = 1;
          }
        }
      }
      else {
LAB_009538c3:
        if ((iVar2 % iVar7 == 0) && (iVar1 = piVar5[0x4f], iVar1 % iVar8 == 0)) {
          local_18 = (undefined1)(iVar2 / iVar7);
          *puVar11 = FUN_00952a50;
          *(undefined1 *)(local_10 + 0x8c + (int)puVar6) = local_18;
          *(char *)(local_10 + 0x96 + (int)puVar6) = (char)(iVar1 / iVar8);
        }
        else {
          puVar3 = (undefined4 *)*piVar5;
          puVar3[5] = 0x26;
          (*(code *)*puVar3)(piVar5);
        }
      }
      iVar1 = piVar5[1];
      iVar10 = piVar5[0x4f] * ((uint)(puVar6[2] == 1) * 2 + 1);
      uVar9 = FUN_0090b710(piVar5[0x1c],piVar5[0x4e]);
      uVar9 = (**(code **)(iVar1 + 8))(piVar5,1,uVar9,iVar10);
      puVar11[-10] = uVar9;
    }
    local_10 = local_10 + 1;
    param_1 = param_1 + 0x15;
    puVar11 = puVar11 + 1;
    if (piVar5[9] <= local_10) {
      return;
    }
  } while( true );
}


// ==== FUN_00953970 @ 0x00953970 ====

void FUN_00953970(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_8;
  
  iVar4 = *(int *)(in_EAX + 0x1cc);
  uVar2 = (*(code *)**(undefined4 **)(in_EAX + 4))();
  puVar1 = *(undefined4 **)(in_EAX + 4);
  *(undefined4 *)(iVar4 + 8) = uVar2;
  uVar2 = (*(code *)*puVar1)();
  puVar1 = *(undefined4 **)(in_EAX + 4);
  *(undefined4 *)(iVar4 + 0xc) = uVar2;
  uVar2 = (*(code *)*puVar1)();
  *(undefined4 *)(iVar4 + 0x10) = uVar2;
  iVar3 = (*(code *)**(undefined4 **)(in_EAX + 4))();
  piVar5 = *(int **)(iVar4 + 0xc);
  *(int *)(iVar4 + 0x14) = iVar3;
  iVar9 = *(int *)(iVar4 + 0x10) - (int)piVar5;
  iVar4 = *(int *)(iVar4 + 8) - (int)piVar5;
  iVar3 = iVar3 - (int)piVar5;
  local_8 = 0x5b6900;
  iVar7 = -0xe25100;
  iVar8 = -0xb2f480;
  iVar6 = 0x2c8d00;
  do {
    *(int *)(iVar4 + (int)piVar5) = iVar8 >> 0x10;
    *piVar5 = iVar7 >> 0x10;
    *(int *)(iVar9 + (int)piVar5) = local_8;
    *(int *)(iVar3 + (int)piVar5) = iVar6;
    local_8 = local_8 + -0xb6d2;
    iVar6 = iVar6 + -0x581a;
    iVar8 = iVar8 + 0x166e9;
    iVar7 = iVar7 + 0x1c5a2;
    piVar5 = piVar5 + 1;
  } while (-0x2b34e7 < iVar6);
  return;
}


// ==== FUN_00953a50 @ 0x00953a50 ====

void FUN_00953a50(int param_1,int *param_2,int param_3,undefined4 *param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  byte *pbVar14;
  undefined1 *puVar15;
  undefined4 *puVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  
  iVar5 = *(int *)(param_1 + 0x70);
  iVar6 = *(int *)(param_1 + 0x1cc);
  iVar7 = *(int *)(param_1 + 0x148);
  iVar8 = *(int *)(iVar6 + 8);
  iVar9 = *(int *)(iVar6 + 0xc);
  iVar10 = *(int *)(iVar6 + 0x10);
  iVar6 = *(int *)(iVar6 + 0x14);
  if (-1 < param_5 + -1) {
    iVar11 = param_2[1];
    iVar12 = *param_2;
    iVar13 = param_2[2];
    puVar16 = (undefined4 *)(iVar11 + param_3 * 4);
    do {
      piVar1 = (int *)((iVar12 - iVar11) + (int)puVar16);
      piVar2 = (int *)((iVar13 - iVar11) + (int)puVar16);
      pbVar14 = (byte *)*puVar16;
      puVar15 = (undefined1 *)*param_4;
      param_4 = param_4 + 1;
      puVar16 = puVar16 + 1;
      if (iVar5 != 0) {
        iVar17 = *piVar1 - (int)pbVar14;
        iVar19 = *piVar2 - (int)pbVar14;
        param_1 = iVar5;
        do {
          bVar3 = pbVar14[iVar19];
          uVar18 = (uint)pbVar14[iVar17];
          *puVar15 = *(undefined1 *)(*(int *)(iVar8 + (uint)bVar3 * 4) + uVar18 + iVar7);
          bVar4 = *pbVar14;
          puVar15[1] = *(undefined1 *)
                        ((*(int *)(iVar6 + (uint)*pbVar14 * 4) + *(int *)(iVar10 + (uint)bVar3 * 4)
                         >> 0x10) + uVar18 + iVar7);
          puVar15[2] = *(undefined1 *)(*(int *)(iVar9 + (uint)bVar4 * 4) + uVar18 + iVar7);
          puVar15 = puVar15 + 3;
          pbVar14 = pbVar14 + 1;
          param_1 = param_1 + -1;
        } while (param_1 != 0);
      }
      param_5 = param_5 + -1;
    } while (param_5 != 0);
  }
  return;
}


// ==== FUN_00953b70 @ 0x00953b70 ====

void FUN_00953b70(int param_1,int *param_2,int param_3,int *param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  byte *pbVar12;
  uint uVar13;
  undefined1 *puVar14;
  uint uVar15;
  int local_c;
  
  iVar2 = *(int *)(param_1 + 0x1cc);
  iVar3 = *(int *)(iVar2 + 0xc);
  iVar4 = *(int *)(param_1 + 0x148);
  uVar5 = *(uint *)(param_1 + 0x70);
  iVar6 = *(int *)(iVar2 + 8);
  iVar7 = *(int *)(iVar2 + 0x10);
  iVar2 = *(int *)(iVar2 + 0x14);
  uVar15 = uVar5 & 0xfffffff8;
  if (-1 < param_5 + -1) {
    param_3 = param_3 << 2;
    local_c = param_5;
    do {
      iVar8 = *(int *)(param_3 + *param_2);
      iVar9 = *(int *)(param_3 + param_2[2]);
      iVar10 = *(int *)(param_3 + param_2[1]);
      iVar11 = *param_4;
      param_3 = param_3 + 4;
      param_4 = param_4 + 1;
      if (uVar15 != 0) {
        FUN_0095fd50(uVar15,iVar8,iVar10,iVar9,iVar11);
      }
      puVar14 = (undefined1 *)(iVar11 + uVar15 * 3);
      if (uVar15 < uVar5) {
        pbVar12 = (byte *)(iVar10 + uVar15);
        param_1 = uVar5 - uVar15;
        do {
          bVar1 = pbVar12[iVar9 - iVar10];
          uVar13 = (uint)pbVar12[iVar8 - iVar10];
          *puVar14 = *(undefined1 *)(*(int *)(iVar6 + (uint)bVar1 * 4) + uVar13 + iVar4);
          puVar14[1] = *(undefined1 *)
                        ((*(int *)(iVar2 + (uint)*pbVar12 * 4) + *(int *)(iVar7 + (uint)bVar1 * 4)
                         >> 0x10) + uVar13 + iVar4);
          puVar14[2] = *(undefined1 *)(*(int *)(iVar3 + (uint)*pbVar12 * 4) + uVar13 + iVar4);
          puVar14 = puVar14 + 3;
          pbVar12 = pbVar12 + 1;
          param_1 = param_1 + -1;
        } while (param_1 != 0);
      }
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  return;
}


// ==== FUN_00953cb0 @ 0x00953cb0 ====

void FUN_00953cb0(int param_1,int param_2,int param_3,int *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = *(int *)(param_1 + 0x24);
  iVar2 = *(int *)(param_1 + 0x70);
  if (-1 < param_5 + -1) {
    param_1 = param_3 << 2;
    do {
      iVar6 = 0;
      if (0 < iVar1) {
        iVar3 = *param_4;
        do {
          puVar4 = *(undefined1 **)(param_1 + *(int *)(param_2 + iVar6 * 4));
          puVar5 = (undefined1 *)(iVar3 + iVar6);
          for (iVar7 = iVar2; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + iVar1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar1);
      }
      param_1 = param_1 + 4;
      param_4 = param_4 + 1;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
  }
  return;
}


// ==== FUN_00953d40 @ 0x00953d40 ====

void FUN_00953d40(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_0090b730(*param_2,param_3,param_4,0,param_5,*(undefined4 *)(param_1 + 0x70));
  return;
}


// ==== FUN_00953d70 @ 0x00953d70 ====

void FUN_00953d70(int param_1,int *param_2,int param_3,undefined4 *param_4,int param_5)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  int *piVar6;
  
  uVar2 = *(uint *)(param_1 + 0x70);
  if (-1 < param_5 + -1) {
    piVar6 = (int *)(*param_2 + param_3 * 4);
    param_1 = param_5;
    do {
      iVar3 = *piVar6;
      puVar4 = (undefined1 *)*param_4;
      param_4 = param_4 + 1;
      piVar6 = piVar6 + 1;
      uVar5 = 0;
      if (uVar2 != 0) {
        do {
          uVar1 = *(undefined1 *)(uVar5 + iVar3);
          puVar4[2] = uVar1;
          puVar4[1] = uVar1;
          *puVar4 = uVar1;
          puVar4 = puVar4 + 3;
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar2);
      }
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}


// ==== FUN_00953dd0 @ 0x00953dd0 ====

void FUN_00953dd0(int param_1,int *param_2,int param_3,undefined4 *param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  byte *pbVar15;
  undefined1 *puVar16;
  undefined4 *puVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  
  iVar5 = *(int *)(param_1 + 0x1cc);
  iVar6 = *(int *)(param_1 + 0x70);
  iVar7 = *(int *)(param_1 + 0x148);
  iVar8 = *(int *)(iVar5 + 8);
  iVar9 = *(int *)(iVar5 + 0xc);
  iVar10 = *(int *)(iVar5 + 0x10);
  iVar5 = *(int *)(iVar5 + 0x14);
  if (-1 < param_5 + -1) {
    iVar11 = param_2[1];
    iVar12 = param_2[2];
    iVar13 = *param_2;
    iVar14 = param_2[3];
    puVar17 = (undefined4 *)(iVar11 + param_3 * 4);
    param_2 = (int *)param_5;
    do {
      piVar1 = (int *)((iVar13 - iVar11) + (int)puVar17);
      piVar2 = (int *)((iVar12 - iVar11) + (int)puVar17);
      piVar3 = (int *)((iVar14 - iVar11) + (int)puVar17);
      pbVar15 = (byte *)*puVar17;
      puVar16 = (undefined1 *)*param_4;
      param_4 = param_4 + 1;
      puVar17 = puVar17 + 1;
      if (iVar6 != 0) {
        iVar18 = *piVar1 - (int)pbVar15;
        iVar21 = *piVar2 - (int)pbVar15;
        iVar19 = *piVar3 - (int)pbVar15;
        param_5 = iVar6;
        while( true ) {
          uVar20 = (uint)pbVar15[iVar18];
          bVar4 = pbVar15[iVar21];
          *puVar16 = *(undefined1 *)(((iVar7 - *(int *)(iVar8 + (uint)bVar4 * 4)) - uVar20) + 0xff);
          puVar16[1] = *(undefined1 *)
                        (((iVar7 - (*(int *)(iVar5 + (uint)*pbVar15 * 4) +
                                    *(int *)(iVar10 + (uint)bVar4 * 4) >> 0x10)) - uVar20) + 0xff);
          puVar16[2] = *(undefined1 *)
                        (((iVar7 - *(int *)(iVar9 + (uint)*pbVar15 * 4)) - uVar20) + 0xff);
          puVar16[3] = pbVar15[iVar19];
          pbVar15 = pbVar15 + 1;
          param_5 = param_5 + -1;
          if (param_5 == 0) break;
          puVar16 = puVar16 + 4;
        }
      }
      param_2 = (int *)((int)param_2 + -1);
    } while (param_2 != (int *)0x0);
  }
  return;
}


// ==== FUN_00953f10 @ 0x00953f10 ====

void FUN_00953f10(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar12 = *(int *)(in_EAX + 0x1cc);
  uVar2 = (*(code *)**(undefined4 **)(in_EAX + 4))();
  puVar1 = *(undefined4 **)(in_EAX + 4);
  *(undefined4 *)(iVar12 + 0x18) = uVar2;
  uVar2 = (*(code *)*puVar1)();
  puVar1 = *(undefined4 **)(in_EAX + 4);
  *(undefined4 *)(iVar12 + 0x1c) = uVar2;
  uVar2 = (*(code *)*puVar1)();
  *(undefined4 *)(iVar12 + 0x20) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(in_EAX + 4))();
  puVar1 = *(undefined4 **)(in_EAX + 4);
  *(undefined4 *)(iVar12 + 0x24) = uVar2;
  uVar2 = (*(code *)*puVar1)();
  puVar1 = *(undefined4 **)(in_EAX + 4);
  *(undefined4 *)(iVar12 + 0x28) = uVar2;
  uVar2 = (*(code *)*puVar1)();
  *(undefined4 *)(iVar12 + 0x2c) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(in_EAX + 4))();
  puVar1 = *(undefined4 **)(in_EAX + 4);
  *(undefined4 *)(iVar12 + 0x30) = uVar2;
  uVar2 = (*(code *)*puVar1)();
  puVar1 = *(undefined4 **)(in_EAX + 4);
  *(undefined4 *)(iVar12 + 0x34) = uVar2;
  uVar2 = (*(code *)*puVar1)();
  *(undefined4 *)(iVar12 + 0x38) = uVar2;
  iVar3 = (*(code *)**(undefined4 **)(in_EAX + 4))();
  puVar5 = *(uint **)(iVar12 + 0x1c);
  iVar14 = 0xfe81;
  *(int *)(iVar12 + 0x3c) = iVar3;
  local_24 = -0x4a24e1;
  local_20 = -0x447a1;
  local_1c = -0x2153e1;
  local_18 = -0x569fe1;
  local_14 = -0x165be1;
  local_10 = -0x8f6e1;
  local_c = -0x1812a1;
  local_8 = -0x4b5fe1;
  iVar13 = -0x41cfe1;
  local_40 = 0xfe81;
  local_3c = 0xfe81;
  local_38 = 0xfe81;
  local_34 = 0xfe81;
  local_30 = 0xfe81;
  iVar6 = *(int *)(iVar12 + 0x18) - (int)puVar5;
  iVar7 = *(int *)(iVar12 + 0x20) - (int)puVar5;
  iVar8 = *(int *)(iVar12 + 0x24) - (int)puVar5;
  iVar9 = *(int *)(iVar12 + 0x28) - (int)puVar5;
  iVar10 = *(int *)(iVar12 + 0x2c) - (int)puVar5;
  iVar11 = *(int *)(iVar12 + 0x30) - (int)puVar5;
  iVar15 = *(int *)(iVar12 + 0x38) - (int)puVar5;
  iVar12 = *(int *)(iVar12 + 0x34) - (int)puVar5;
  local_2c = 0xfe81;
  local_28 = 0xfe81;
  iVar3 = iVar3 - (int)puVar5;
  do {
    if (iVar14 < 0x5742) {
      iVar4 = 0x57c0 - iVar13 / 0x3f;
    }
    else {
      iVar4 = iVar14;
    }
    *(int *)((int)puVar5 + iVar6) = iVar4;
    if (iVar14 < 0x5742) {
      iVar4 = 0x6480 - local_8 / 0x3f;
    }
    else {
      iVar4 = local_28;
    }
    *puVar5 = (uint)(iVar4 * 0x10101) >> 0x10;
    if (iVar14 < 0x5742) {
      iVar4 = 0xb880 - local_c / 0x3f;
    }
    else {
      iVar4 = local_2c;
    }
    *(uint *)((int)puVar5 + iVar7) = (uint)(iVar4 * 0x10101) >> 0x10;
    if (iVar14 < 0x5742) {
      iVar4 = 0xff00 - local_10 / 0x3f;
    }
    else {
      iVar4 = 0xfe81;
    }
    *(uint *)((int)puVar5 + iVar8) = (uint)(iVar4 * 0x10101) >> 0x10;
    if (iVar14 < 0x5742) {
      iVar4 = 0xed00 - local_14 / 0x3f;
    }
    else {
      iVar4 = local_30;
    }
    *(uint *)((int)puVar5 + iVar9) = (uint)(iVar4 * 0x10101) >> 0x10;
    if (iVar14 < 0x5742) {
      iVar4 = 0x7380 - local_18 / 0x3f;
    }
    else {
      iVar4 = local_34;
    }
    *(uint *)((int)puVar5 + iVar10) = (uint)(iVar4 * 0x10101) >> 0x10;
    if (iVar14 < 0x5742) {
      iVar4 = 0x9c00 - local_1c / 0x3f;
    }
    else {
      iVar4 = local_38;
    }
    *(uint *)((int)puVar5 + iVar11) = (uint)(iVar4 * 0x10101) >> 0x10;
    *(uint *)((int)puVar5 + iVar12) =
         (((iVar14 < 0x5742) - 1 & 0xffffff81) + 0xff00) * 0x10101 >> 0x10;
    if (iVar14 < 0x5742) {
      iVar4 = 0xf9c0 - local_20 / 0x3f;
    }
    else {
      iVar4 = local_3c;
    }
    *(uint *)((int)puVar5 + iVar15) = (uint)(iVar4 * 0x10101) >> 0x10;
    if (iVar14 < 0x5742) {
      iVar4 = 0x7ec0 - local_24 / 0x3f;
    }
    else {
      iVar4 = local_40;
    }
    *(uint *)((int)puVar5 + iVar3) = (uint)(iVar4 * 0x10101) >> 0x10;
    local_28 = local_28 + -0xce;
    local_8 = local_8 + 0x6480;
    local_2c = local_2c + -0x5e;
    local_c = local_c + 0x2019;
    local_10 = local_10 + 0xbf4;
    local_30 = local_30 + -0x18;
    local_14 = local_14 + 0x1dd0;
    local_34 = local_34 + -0xba;
    local_18 = local_18 + 0x7380;
    local_38 = local_38 + -0x84;
    local_1c = local_1c + 0x2c70;
    local_3c = local_3c + -7;
    local_20 = local_20 + 0x5b5;
    iVar14 = iVar14 + -0xdf;
    local_40 = local_40 + -0xab;
    local_24 = local_24 + 0x62dc;
    iVar13 = iVar13 + 0x57c0;
    puVar5 = puVar5 + 1;
  } while (0x205f < iVar14);
  return;
}


// ==== FUN_00954330 @ 0x00954330 ====

void FUN_00954330(undefined1 *param_1,int *param_2,int param_3,undefined4 *param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  undefined4 *puVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  byte *pbVar27;
  
  iVar4 = *(int *)((int)param_1 + 0x1cc);
  iVar5 = *(int *)(iVar4 + 0x18);
  iVar6 = *(int *)((int)param_1 + 0x70);
  iVar7 = *(int *)(iVar4 + 0x1c);
  iVar8 = *(int *)(iVar4 + 0x20);
  iVar9 = *(int *)(iVar4 + 0x24);
  iVar10 = *(int *)(iVar4 + 0x28);
  iVar11 = *(int *)(iVar4 + 0x2c);
  iVar12 = *(int *)(iVar4 + 0x30);
  iVar13 = *(int *)(iVar4 + 0x34);
  iVar14 = *(int *)(iVar4 + 0x38);
  iVar4 = *(int *)(iVar4 + 0x3c);
  if (-1 < param_5 + -1) {
    iVar15 = param_2[1];
    iVar16 = param_2[2];
    iVar17 = *param_2;
    iVar18 = param_2[3];
    puVar20 = (undefined4 *)(iVar15 + param_3 * 4);
    param_3 = param_5;
    do {
      piVar1 = (int *)((iVar16 - iVar15) + (int)puVar20);
      piVar2 = (int *)((iVar18 - iVar15) + (int)puVar20);
      param_1 = (undefined1 *)*param_4;
      piVar3 = (int *)((iVar17 - iVar15) + (int)puVar20);
      pbVar27 = (byte *)*puVar20;
      param_4 = param_4 + 1;
      puVar20 = puVar20 + 1;
      if (iVar6 != 0) {
        iVar21 = *piVar3 - (int)pbVar27;
        iVar24 = *piVar1 - (int)pbVar27;
        iVar25 = *piVar2 - (int)pbVar27;
        param_2 = (int *)iVar6;
        while( true ) {
          iVar22 = 0xff - (uint)pbVar27[iVar21];
          iVar23 = 0xff - (uint)*pbVar27;
          iVar26 = 0xff - (uint)pbVar27[iVar24];
          iVar19 = *(int *)(iVar5 + (0xff - (uint)pbVar27[iVar25]) * 4);
          *param_1 = (char)((((uint)(*(int *)(iVar7 + iVar22 * 4) * iVar19) >> 0x10) *
                             *(int *)(iVar10 + iVar23 * 4) >> 0x10) * *(int *)(iVar13 + iVar26 * 4)
                           >> 0x18);
          param_1[1] = (char)((((uint)(*(int *)(iVar11 + iVar23 * 4) * iVar19) >> 0x10) *
                               *(int *)(iVar14 + iVar26 * 4) >> 0x10) * *(int *)(iVar8 + iVar22 * 4)
                             >> 0x18);
          param_1[2] = (char)((((uint)(*(int *)(iVar4 + iVar26 * 4) * iVar19) >> 0x10) *
                               *(int *)(iVar9 + iVar22 * 4) >> 0x10) * *(int *)(iVar12 + iVar23 * 4)
                             >> 0x18);
          pbVar27 = pbVar27 + 1;
          param_2 = (int *)((int)param_2 + -1);
          if (param_2 == (int *)0x0) break;
          param_1 = param_1 + 3;
        }
      }
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}


// ==== FUN_009544e0 @ 0x009544e0 ====

void FUN_009544e0(int param_1,int *param_2,int param_3,int *param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  byte *pbVar25;
  undefined1 *puVar26;
  undefined4 *puVar27;
  int iVar28;
  uint uVar29;
  int iVar30;
  uint uVar31;
  int iVar32;
  uint uVar33;
  int local_8;
  
  iVar4 = *(int *)(param_1 + 0x1cc);
  iVar5 = *(int *)(iVar4 + 0x18);
  iVar6 = *(int *)(iVar4 + 0x1c);
  iVar7 = *(int *)(iVar4 + 0x20);
  iVar8 = *(int *)(iVar4 + 0x24);
  iVar9 = *(int *)(iVar4 + 0x28);
  iVar10 = *(int *)(iVar4 + 0x2c);
  iVar11 = *(int *)(iVar4 + 0x30);
  iVar12 = *(int *)(iVar4 + 0x34);
  iVar13 = *(int *)(iVar4 + 0x38);
  iVar14 = *(int *)(iVar4 + 0x3c);
  iVar15 = *(int *)(iVar4 + 8);
  iVar16 = *(int *)(iVar4 + 0xc);
  iVar17 = *(int *)(iVar4 + 0x10);
  iVar4 = *(int *)(iVar4 + 0x14);
  iVar18 = *(int *)(param_1 + 0x70);
  iVar19 = *(int *)(param_1 + 0x148);
  if (-1 < param_5 + -1) {
    iVar20 = param_2[1];
    iVar21 = param_2[2];
    iVar22 = *param_2;
    iVar23 = param_2[3];
    puVar27 = (undefined4 *)(iVar20 + param_3 * 4);
    local_8 = param_5;
    do {
      piVar1 = (int *)((iVar21 - iVar20) + (int)puVar27);
      piVar2 = (int *)((iVar23 - iVar20) + (int)puVar27);
      pbVar25 = (byte *)*puVar27;
      piVar3 = (int *)((iVar22 - iVar20) + (int)puVar27);
      puVar26 = (undefined1 *)*param_4;
      param_4 = param_4 + 1;
      puVar27 = puVar27 + 1;
      if (iVar18 != 0) {
        iVar28 = *piVar3 - (int)pbVar25;
        iVar30 = *piVar1 - (int)pbVar25;
        iVar32 = *piVar2 - (int)pbVar25;
        param_3 = iVar18;
        do {
          uVar29 = (uint)pbVar25[iVar28];
          uVar33 = (uint)*(byte *)(*(int *)(iVar15 + (uint)pbVar25[iVar30] * 4) + uVar29 + iVar19);
          uVar31 = (uint)*(byte *)((*(int *)(iVar4 + (uint)*pbVar25 * 4) +
                                    *(int *)(iVar17 + (uint)pbVar25[iVar30] * 4) >> 0x10) + uVar29 +
                                  iVar19);
          uVar29 = (uint)*(byte *)(*(int *)(iVar16 + (uint)*pbVar25 * 4) + uVar29 + iVar19);
          iVar24 = *(int *)(iVar5 + (0xff - (uint)pbVar25[iVar32]) * 4);
          *puVar26 = (char)((((uint)(*(int *)(iVar6 + uVar33 * 4) * iVar24) >> 0x10) *
                             *(int *)(iVar9 + uVar31 * 4) >> 0x10) * *(int *)(iVar12 + uVar29 * 4)
                           >> 0x18);
          puVar26[1] = (char)((((uint)(*(int *)(iVar10 + uVar31 * 4) * iVar24) >> 0x10) *
                               *(int *)(iVar13 + uVar29 * 4) >> 0x10) * *(int *)(iVar7 + uVar33 * 4)
                             >> 0x18);
          puVar26[2] = (char)((((uint)(*(int *)(iVar14 + uVar29 * 4) * iVar24) >> 0x10) *
                               *(int *)(iVar8 + uVar33 * 4) >> 0x10) * *(int *)(iVar11 + uVar31 * 4)
                             >> 0x18);
          puVar26 = puVar26 + 3;
          pbVar25 = pbVar25 + 1;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  return;
}


// ==== FUN_009546e0 @ 0x009546e0 ====

void FUN_009546e0(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x40);
  iVar3 = param_1[10];
  param_1[0x73] = (int)puVar2;
  *puVar2 = FUN_004154b0;
  switch(iVar3) {
  case 1:
    if (param_1[9] != 1) {
LAB_00954730:
      puVar1 = (undefined4 *)*param_1;
      puVar1[5] = 10;
      (*(code *)*puVar1)(param_1);
    }
    break;
  case 2:
  case 3:
    if (param_1[9] != 3) goto LAB_00954730;
    break;
  case 4:
  case 5:
    if (param_1[9] != 4) goto LAB_00954730;
    break;
  default:
    if (param_1[9] < 1) goto LAB_00954730;
  }
  iVar3 = param_1[0xb];
  if (iVar3 == 1) {
    param_1[0x1e] = 1;
    if ((param_1[10] == 1) || (param_1[10] == 3)) {
      iVar3 = param_1[9];
      puVar2[1] = FUN_00953d40;
      if (1 < iVar3) {
        puVar2 = (undefined4 *)(param_1[0x37] + 0x84);
        iVar3 = param_1[9] + -1;
        do {
          *puVar2 = 0;
          puVar2 = puVar2 + 0x15;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      goto LAB_0095487d;
    }
  }
  else if (iVar3 == 2) {
    iVar3 = param_1[10];
    param_1[0x1e] = 3;
    if (iVar3 == 3) {
      if ((param_1[0x12] == 5) || (param_1[0x12] == 6)) {
        puVar2[1] = FUN_00953b70;
        FUN_00953970();
      }
      else {
        puVar2[1] = FUN_00953a50;
        FUN_00953970();
      }
      goto LAB_0095487d;
    }
    if (iVar3 == 1) {
      puVar2[1] = FUN_00953d70;
      goto LAB_0095487d;
    }
    if (iVar3 == 2) {
      puVar2[1] = FUN_00953cb0;
      goto LAB_0095487d;
    }
    if (iVar3 == 4) {
      puVar2[1] = FUN_00954330;
      FUN_00953f10();
      goto LAB_0095487d;
    }
    if (iVar3 == 5) {
      puVar2[1] = FUN_009544e0;
      FUN_00953970();
      FUN_00953f10();
      goto LAB_0095487d;
    }
  }
  else if (iVar3 == 4) {
    param_1[0x1e] = 4;
    if (param_1[10] == 5) {
      puVar2[1] = FUN_00953dd0;
      FUN_00953970();
      goto LAB_0095487d;
    }
    if (param_1[10] == 4) {
      puVar2[1] = FUN_00953cb0;
      goto LAB_0095487d;
    }
  }
  else if (iVar3 == param_1[10]) {
    param_1[0x1e] = param_1[9];
    puVar2[1] = FUN_00953cb0;
    goto LAB_0095487d;
  }
  puVar2 = (undefined4 *)*param_1;
  puVar2[5] = 0x1b;
  (*(code *)*puVar2)(param_1);
LAB_0095487d:
  if (param_1[0x15] == 0) {
    param_1[0x1f] = param_1[0x1e];
    return;
  }
  param_1[0x1f] = 1;
  return;
}


// ==== FUN_009548c0 @ 0x009548c0 ====

void FUN_009548c0(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_8;
  
  iVar4 = *(int *)(in_EAX + 0x1c8);
  uVar2 = (*(code *)**(undefined4 **)(in_EAX + 4))();
  puVar1 = *(undefined4 **)(in_EAX + 4);
  *(undefined4 *)(iVar4 + 0x10) = uVar2;
  uVar2 = (*(code *)*puVar1)();
  puVar1 = *(undefined4 **)(in_EAX + 4);
  *(undefined4 *)(iVar4 + 0x14) = uVar2;
  uVar2 = (*(code *)*puVar1)();
  *(undefined4 *)(iVar4 + 0x18) = uVar2;
  iVar3 = (*(code *)**(undefined4 **)(in_EAX + 4))();
  piVar5 = *(int **)(iVar4 + 0x14);
  *(int *)(iVar4 + 0x1c) = iVar3;
  iVar9 = *(int *)(iVar4 + 0x18) - (int)piVar5;
  iVar4 = *(int *)(iVar4 + 0x10) - (int)piVar5;
  iVar3 = iVar3 - (int)piVar5;
  local_8 = 0x5b6900;
  iVar7 = -0xe25100;
  iVar8 = -0xb2f480;
  iVar6 = 0x2c8d00;
  do {
    *(int *)(iVar4 + (int)piVar5) = iVar8 >> 0x10;
    *piVar5 = iVar7 >> 0x10;
    *(int *)(iVar9 + (int)piVar5) = local_8;
    *(int *)(iVar3 + (int)piVar5) = iVar6;
    local_8 = local_8 + -0xb6d2;
    iVar6 = iVar6 + -0x581a;
    iVar8 = iVar8 + 0x166e9;
    iVar7 = iVar7 + 0x1c5a2;
    piVar5 = piVar5 + 1;
  } while (-0x2b34e7 < iVar6);
  return;
}


// ==== FUN_009549a0 @ 0x009549a0 ====

void FUN_009549a0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x1c8);
  uVar2 = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x2c) = uVar2;
  return;
}


// ==== FUN_009549c0 @ 0x009549c0 ====

void FUN_009549c0(int param_1,undefined4 param_2,int *param_3,undefined4 param_4,int param_5,
                 int *param_6,int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(param_1 + 0x1c8);
  if (*(int *)(iVar1 + 0x24) == 0) {
    uVar4 = 2;
    if (*(uint *)(iVar1 + 0x2c) < 2) {
      uVar4 = *(uint *)(iVar1 + 0x2c);
    }
    iVar2 = *param_6;
    if ((uint)(param_7 - iVar2) < uVar4) {
      uVar4 = param_7 - iVar2;
    }
    local_c = *(undefined4 *)(param_5 + iVar2 * 4);
    if (uVar4 < 2) {
      local_8 = *(undefined4 *)(iVar1 + 0x20);
      *(undefined4 *)(iVar1 + 0x24) = 1;
    }
    else {
      local_8 = *(undefined4 *)(param_5 + 4 + iVar2 * 4);
    }
    (**(code **)(iVar1 + 0xc))(param_1,param_2,*param_3,&local_c);
  }
  else {
    FUN_0090b730(iVar1 + 0x20,0,param_5 + *param_6 * 4,0,1,*(undefined4 *)(iVar1 + 0x28));
    uVar4 = 1;
    *(undefined4 *)(iVar1 + 0x24) = 0;
  }
  iVar2 = *param_6;
  iVar3 = *(int *)(iVar1 + 0x24);
  *(uint *)(iVar1 + 0x2c) = *(int *)(iVar1 + 0x2c) - uVar4;
  *param_6 = iVar2 + uVar4;
  if (iVar3 == 0) {
    *param_3 = *param_3 + 1;
  }
  return;
}


// ==== FUN_00954a90 @ 0x00954a90 ====

void FUN_00954a90(int param_1,undefined4 param_2,int *param_3,undefined4 param_4,int param_5,
                 int *param_6)

{
  int iVar1;
  
  (**(code **)(*(int *)(param_1 + 0x1c8) + 0xc))(param_1,param_2,*param_3,param_5 + *param_6 * 4);
  iVar1 = *param_6;
  *param_3 = *param_3 + 1;
  *param_6 = iVar1 + 1;
  return;
}


// ==== FUN_00954ad0 @ 0x00954ad0 ====

void FUN_00954ad0(int param_1,int *param_2,int param_3,undefined4 *param_4)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined1 *puVar12;
  uint uVar13;
  byte *pbVar14;
  byte *pbVar15;
  int iVar16;
  uint uVar17;
  byte *pbVar18;
  
  iVar4 = *(int *)(param_1 + 0x1c8);
  iVar5 = *(int *)(param_1 + 0x148);
  uVar17 = *(uint *)(param_1 + 0x70);
  iVar6 = *(int *)(iVar4 + 0x10);
  iVar7 = *(int *)(iVar4 + 0x14);
  iVar8 = *(int *)(iVar4 + 0x18);
  iVar4 = *(int *)(iVar4 + 0x1c);
  pbVar18 = *(byte **)(*param_2 + param_3 * 4);
  pbVar15 = *(byte **)(param_2[1] + param_3 * 4);
  pbVar14 = *(byte **)(param_2[2] + param_3 * 4);
  puVar12 = (undefined1 *)*param_4;
  param_2 = (int *)(uVar17 >> 1);
  if (param_2 != (int *)0x0) {
    do {
      bVar1 = *pbVar15;
      bVar2 = *pbVar14;
      pbVar15 = pbVar15 + 1;
      pbVar14 = pbVar14 + 1;
      iVar9 = *(int *)(iVar6 + (uint)bVar2 * 4);
      iVar16 = *(int *)(iVar4 + (uint)bVar1 * 4);
      iVar10 = *(int *)(iVar8 + (uint)bVar2 * 4);
      iVar11 = *(int *)(iVar7 + (uint)bVar1 * 4);
      uVar13 = (uint)*pbVar18;
      *puVar12 = *(undefined1 *)(iVar9 + uVar13 + iVar5);
      iVar16 = iVar16 + iVar10 >> 0x10;
      puVar12[1] = *(undefined1 *)(uVar13 + iVar16 + iVar5);
      puVar12[2] = *(undefined1 *)(uVar13 + iVar11 + iVar5);
      uVar13 = (uint)pbVar18[1];
      puVar12[3] = *(undefined1 *)(iVar9 + uVar13 + iVar5);
      uVar3 = *(undefined1 *)(iVar16 + uVar13 + iVar5);
      puVar12[5] = *(undefined1 *)(uVar13 + iVar11 + iVar5);
      puVar12[4] = uVar3;
      pbVar18 = pbVar18 + 2;
      puVar12 = puVar12 + 6;
      param_2 = (int *)((int)param_2 - 1);
    } while (param_2 != (int *)0x0);
  }
  if ((uVar17 & 1) != 0) {
    bVar1 = *pbVar15;
    uVar17 = (uint)*pbVar18;
    bVar2 = *pbVar14;
    *puVar12 = *(undefined1 *)(*(int *)(iVar6 + (uint)bVar2 * 4) + uVar17 + iVar5);
    puVar12[1] = *(undefined1 *)
                  ((*(int *)(iVar4 + (uint)bVar1 * 4) + *(int *)(iVar8 + (uint)bVar2 * 4) >> 0x10) +
                   uVar17 + iVar5);
    puVar12[2] = *(undefined1 *)(*(int *)(iVar7 + (uint)bVar1 * 4) + uVar17 + iVar5);
  }
  return;
}


// ==== FUN_00954c20 @ 0x00954c20 ====

void FUN_00954c20(undefined4 *param_1)

{
  undefined4 *puVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int in_EAX;
  int *in_ECX;
  undefined1 *puVar11;
  int in_EDX;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  undefined1 *puVar15;
  byte *pbVar16;
  int iVar17;
  int iVar18;
  uint local_14;
  byte *local_10;
  byte *local_c;
  
  iVar18 = *(int *)(in_EDX + 0x1c8);
  iVar5 = *(int *)(iVar18 + 0x10);
  iVar6 = *(int *)(iVar18 + 0x14);
  iVar7 = *(int *)(iVar18 + 0x18);
  iVar18 = *(int *)(iVar18 + 0x1c);
  iVar8 = *(int *)(in_EDX + 0x148);
  uVar13 = *(uint *)(in_EDX + 0x70);
  puVar1 = (undefined4 *)(*in_ECX + in_EAX * 8);
  local_c = (byte *)*puVar1;
  local_10 = (byte *)puVar1[1];
  pbVar16 = *(byte **)(in_ECX[1] + in_EAX * 4);
  pbVar14 = *(byte **)(in_ECX[2] + in_EAX * 4);
  puVar11 = (undefined1 *)*param_1;
  puVar15 = (undefined1 *)param_1[1];
  local_14 = uVar13 >> 1;
  if (local_14 != 0) {
    do {
      bVar2 = *pbVar16;
      bVar3 = *pbVar14;
      pbVar16 = pbVar16 + 1;
      pbVar14 = pbVar14 + 1;
      iVar9 = *(int *)(iVar5 + (uint)bVar3 * 4);
      iVar10 = *(int *)(iVar6 + (uint)bVar2 * 4);
      uVar12 = (uint)*local_c;
      iVar17 = *(int *)(iVar18 + (uint)bVar2 * 4) + *(int *)(iVar7 + (uint)bVar3 * 4) >> 0x10;
      *puVar11 = *(undefined1 *)(iVar9 + uVar12 + iVar8);
      puVar11[1] = *(undefined1 *)(uVar12 + iVar17 + iVar8);
      puVar11[2] = *(undefined1 *)(uVar12 + iVar10 + iVar8);
      uVar12 = (uint)local_c[1];
      local_c = local_c + 2;
      puVar11[3] = *(undefined1 *)(iVar9 + uVar12 + iVar8);
      puVar11[4] = *(undefined1 *)(uVar12 + iVar17 + iVar8);
      puVar11[5] = *(undefined1 *)(uVar12 + iVar10 + iVar8);
      uVar12 = (uint)*local_10;
      puVar11 = puVar11 + 6;
      *puVar15 = *(undefined1 *)(iVar9 + uVar12 + iVar8);
      puVar15[1] = *(undefined1 *)(uVar12 + iVar17 + iVar8);
      puVar15[2] = *(undefined1 *)(uVar12 + iVar10 + iVar8);
      uVar12 = (uint)local_10[1];
      local_10 = local_10 + 2;
      puVar15[3] = *(undefined1 *)(iVar9 + uVar12 + iVar8);
      puVar15[4] = *(undefined1 *)(iVar17 + uVar12 + iVar8);
      puVar15[5] = *(undefined1 *)(uVar12 + iVar10 + iVar8);
      puVar15 = puVar15 + 6;
      local_14 = local_14 - 1;
    } while (local_14 != 0);
  }
  if ((uVar13 & 1) != 0) {
    iVar5 = *(int *)(iVar5 + (uint)*pbVar14 * 4);
    iVar18 = *(int *)(iVar18 + (uint)*pbVar16 * 4);
    iVar7 = *(int *)(iVar7 + (uint)*pbVar14 * 4);
    iVar6 = *(int *)(iVar6 + (uint)*pbVar16 * 4);
    uVar13 = (uint)*local_c;
    *puVar11 = *(undefined1 *)(iVar5 + uVar13 + iVar8);
    iVar18 = iVar18 + iVar7 >> 0x10;
    puVar11[1] = *(undefined1 *)(uVar13 + iVar18 + iVar8);
    puVar11[2] = *(undefined1 *)(uVar13 + iVar6 + iVar8);
    uVar13 = (uint)*local_10;
    *puVar15 = *(undefined1 *)(iVar5 + uVar13 + iVar8);
    uVar4 = *(undefined1 *)(uVar13 + iVar6 + iVar8);
    puVar15[1] = *(undefined1 *)(uVar13 + iVar18 + iVar8);
    puVar15[2] = uVar4;
  }
  return;
}


// ==== FUN_00954e10 @ 0x00954e10 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00954e10(byte *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  short sVar13;
  short sVar14;
  short sVar15;
  short sVar16;
  short sVar17;
  short sVar18;
  short sVar19;
  short sVar20;
  int *in_EAX;
  uint uVar21;
  undefined4 *puVar22;
  int iVar23;
  int in_ECX;
  int iVar24;
  undefined4 *puVar25;
  int iVar26;
  int in_EDX;
  undefined8 *puVar27;
  uint uVar28;
  undefined4 *puVar29;
  undefined4 *puVar30;
  undefined8 *puVar31;
  undefined8 *puVar32;
  undefined8 *puVar33;
  byte bVar34;
  undefined1 uVar37;
  undefined8 uVar35;
  ulonglong uVar36;
  undefined1 uVar39;
  undefined8 uVar38;
  ulonglong uVar40;
  byte bVar41;
  byte bVar42;
  byte bVar43;
  undefined8 uVar44;
  ulonglong uVar45;
  undefined8 uVar46;
  byte bVar48;
  byte bVar49;
  undefined8 uVar47;
  int local_20;
  int local_1c;
  byte *local_14;
  byte *local_10;
  byte *local_8;
  
  iVar2 = *(int *)(in_ECX + 0x148);
  iVar23 = *(int *)(in_ECX + 0x1c8);
  iVar3 = *(int *)(iVar23 + 0x10);
  iVar4 = *(int *)(iVar23 + 0x14);
  iVar5 = *(int *)(iVar23 + 0x18);
  iVar23 = *(int *)(iVar23 + 0x1c);
  iVar24 = *(int *)(in_ECX + 0x70) >> 3;
  uVar21 = *(int *)(in_ECX + 0x70) + iVar24 * -8;
  piVar1 = (int *)(*(int *)param_1 + in_EDX * 8);
  puVar6 = (undefined4 *)*piVar1;
  puVar7 = (undefined4 *)piVar1[1];
  puVar8 = *(undefined4 **)(*(int *)((int)param_1 + 4) + in_EDX * 4);
  puVar9 = *(undefined4 **)(*(int *)((int)param_1 + 8) + in_EDX * 4);
  puVar33 = (undefined8 *)in_EAX[1];
  puVar31 = (undefined8 *)*in_EAX;
  puVar22 = puVar7;
  puVar25 = puVar8;
  puVar27 = puVar33;
  puVar29 = puVar9;
  puVar30 = puVar6;
  puVar32 = puVar31;
  local_1c = iVar24;
  do {
    uVar37 = (undefined1)((uint)*puVar29 >> 8);
    bVar34 = (byte)*puVar29;
    uVar35 = psubsw((ulonglong)
                    CONCAT52((int5)(CONCAT43((int)(((uint7)CONCAT21((short)(((uint7)bVar34 << 0x30)
                                                                           >> 0x28),bVar34) << 0x20)
                                                  >> 0x18),CONCAT12(bVar34,CONCAT11(bVar34,bVar34)))
                                   >> 0x10),CONCAT11(bVar34,bVar34)) & 0xffff00ff00ff00ff,
                    0x80008000800080);
    uVar35 = psllw(uVar35,2);
    uVar39 = (undefined1)((uint)*puVar25 >> 8);
    bVar34 = (byte)*puVar25;
    uVar35 = paddsw(uVar35,_DAT_00a2e520);
    uVar35 = pmulhw(uVar35,_DAT_00a2e500);
    uVar38 = psubsw((ulonglong)
                    CONCAT52((int5)(CONCAT43((int)(((uint7)CONCAT21((short)(((uint7)bVar34 << 0x30)
                                                                           >> 0x28),bVar34) << 0x20)
                                                  >> 0x18),CONCAT12(bVar34,CONCAT11(bVar34,bVar34)))
                                   >> 0x10),CONCAT11(bVar34,bVar34)) & 0xffff00ff00ff00ff,
                    0x80008000800080);
    uVar38 = psllw(uVar38,2);
    uVar38 = paddsw(uVar38,_DAT_00a2e528);
    uVar44 = psubsw((ulonglong)
                    CONCAT16(uVar37,(uint6)CONCAT14(uVar37,(uint)(CONCAT12(uVar37,CONCAT11(uVar37,
                                                  uVar37)) & 0xff00ff))),0x80008000800080);
    uVar46 = psubsw((ulonglong)
                    CONCAT16(uVar39,(uint6)CONCAT14(uVar39,(uint)(CONCAT12(uVar39,CONCAT11(uVar39,
                                                  uVar39)) & 0xff00ff))),0x80008000800080);
    uVar38 = pmulhw(uVar38,_DAT_00a2e508);
    uVar44 = psllw(uVar44,2);
    uVar46 = psllw(uVar46,2);
    uVar44 = paddsw(uVar44,_DAT_00a2e530);
    uVar10 = *puVar30;
    uVar44 = pmulhw(uVar44,_DAT_00a2e510);
    bVar49 = (byte)((uint)uVar10 >> 0x18);
    bVar48 = (byte)((uint)uVar10 >> 0x10);
    bVar41 = (byte)((uint)uVar10 >> 8);
    bVar34 = (byte)uVar10;
    uVar46 = paddsw(uVar46,_DAT_00a2e538);
    uVar36 = paddsw(uVar35,uVar38);
    uVar35 = pmulhw(uVar46,_DAT_00a2e518);
    uVar45 = paddsw(uVar44,uVar35);
    uVar38 = paddsw(CONCAT62(CONCAT51((int5)(((ulonglong)
                                              CONCAT31((int3)(((ulonglong)bVar41 << 0x30) >> 0x28),
                                                       bVar34) << 0x20) >> 0x18),bVar34),
                             (ushort)bVar34),uVar36);
    uVar40 = (uVar36 & 0xffffffff0000) >> 0x10 | (uVar45 & 0xffffffff0000) << 0x10;
    uVar10 = *puVar22;
    uVar35 = paddsw(CONCAT62(CONCAT51((int5)(((ulonglong)
                                              CONCAT31((int3)(((ulonglong)bVar48 << 0x30) >> 0x28),
                                                       bVar48) << 0x20) >> 0x18),bVar41),
                             (ushort)bVar41),uVar40);
    sVar13 = (short)uVar38;
    sVar14 = (short)((ulonglong)uVar38 >> 0x10);
    sVar15 = (short)((ulonglong)uVar38 >> 0x20);
    sVar16 = (short)((ulonglong)uVar38 >> 0x30);
    sVar17 = (short)uVar35;
    sVar18 = (short)((ulonglong)uVar35 >> 0x10);
    sVar19 = (short)((ulonglong)uVar35 >> 0x20);
    sVar20 = (short)((ulonglong)uVar35 >> 0x30);
    bVar43 = (byte)((uint)uVar10 >> 0x18);
    bVar42 = (byte)((uint)uVar10 >> 0x10);
    bVar41 = (byte)((uint)uVar10 >> 8);
    bVar34 = (byte)uVar10;
    *puVar32 = CONCAT17((0 < sVar20) * (sVar20 < 0x100) * (char)((ulonglong)uVar35 >> 0x30) -
                        (0xff < sVar20),
                        CONCAT16((0 < sVar19) * (sVar19 < 0x100) * (char)((ulonglong)uVar35 >> 0x20)
                                 - (0xff < sVar19),
                                 CONCAT15((0 < sVar18) * (sVar18 < 0x100) *
                                          (char)((ulonglong)uVar35 >> 0x10) - (0xff < sVar18),
                                          CONCAT14((0 < sVar17) * (sVar17 < 0x100) * (char)uVar35 -
                                                   (0xff < sVar17),
                                                   CONCAT13((0 < sVar16) * (sVar16 < 0x100) *
                                                            (char)((ulonglong)uVar38 >> 0x30) -
                                                            (0xff < sVar16),
                                                            CONCAT12((0 < sVar15) * (sVar15 < 0x100)
                                                                     * (char)((ulonglong)uVar38 >>
                                                                             0x20) - (0xff < sVar15)
                                                                     ,CONCAT11((0 < sVar14) *
                                                                               (sVar14 < 0x100) *
                                                                               (char)((ulonglong)
                                                                                      uVar38 >> 0x10
                                                                                     ) - (0xff < 
                                                  sVar14),(0 < sVar13) * (sVar13 < 0x100) *
                                                          (char)uVar38 - (0xff < sVar13))))))));
    uVar35 = paddsw(CONCAT62(CONCAT51((int5)(((ulonglong)
                                              CONCAT31((int3)(((ulonglong)bVar41 << 0x30) >> 0x28),
                                                       bVar34) << 0x20) >> 0x18),bVar34),
                             (ushort)bVar34),uVar36);
    uVar38 = paddsw(CONCAT62(CONCAT51((int5)(((ulonglong)
                                              CONCAT31((int3)(((ulonglong)bVar42 << 0x30) >> 0x28),
                                                       bVar42) << 0x20) >> 0x18),bVar41),
                             (ushort)bVar41),uVar40);
    sVar13 = (short)uVar35;
    sVar14 = (short)((ulonglong)uVar35 >> 0x10);
    sVar15 = (short)((ulonglong)uVar35 >> 0x20);
    sVar16 = (short)((ulonglong)uVar35 >> 0x30);
    sVar17 = (short)uVar38;
    sVar18 = (short)((ulonglong)uVar38 >> 0x10);
    sVar19 = (short)((ulonglong)uVar38 >> 0x20);
    sVar20 = (short)((ulonglong)uVar38 >> 0x30);
    *puVar27 = CONCAT17((0 < sVar20) * (sVar20 < 0x100) * (char)((ulonglong)uVar38 >> 0x30) -
                        (0xff < sVar20),
                        CONCAT16((0 < sVar19) * (sVar19 < 0x100) * (char)((ulonglong)uVar38 >> 0x20)
                                 - (0xff < sVar19),
                                 CONCAT15((0 < sVar18) * (sVar18 < 0x100) *
                                          (char)((ulonglong)uVar38 >> 0x10) - (0xff < sVar18),
                                          CONCAT14((0 < sVar17) * (sVar17 < 0x100) * (char)uVar38 -
                                                   (0xff < sVar17),
                                                   CONCAT13((0 < sVar16) * (sVar16 < 0x100) *
                                                            (char)((ulonglong)uVar35 >> 0x30) -
                                                            (0xff < sVar16),
                                                            CONCAT12((0 < sVar15) * (sVar15 < 0x100)
                                                                     * (char)((ulonglong)uVar35 >>
                                                                             0x20) - (0xff < sVar15)
                                                                     ,CONCAT11((0 < sVar14) *
                                                                               (sVar14 < 0x100) *
                                                                               (char)((ulonglong)
                                                                                      uVar35 >> 0x10
                                                                                     ) - (0xff < 
                                                  sVar14),(0 < sVar13) * (sVar13 < 0x100) *
                                                          (char)uVar35 - (0xff < sVar13))))))));
    uVar38 = paddsw(CONCAT62(CONCAT51((int5)(((ulonglong)
                                              CONCAT31((int3)(((ulonglong)bVar49 << 0x30) >> 0x28),
                                                       bVar49) << 0x20) >> 0x18),bVar49),
                             (ushort)bVar48),uVar45);
    uVar37 = (undefined1)((uint)*puVar29 >> 0x18);
    bVar34 = (byte)((uint)*puVar29 >> 0x10);
    uVar46 = paddsw(CONCAT62(CONCAT51((int5)(((ulonglong)
                                              CONCAT31((int3)(((ulonglong)bVar43 << 0x30) >> 0x28),
                                                       bVar43) << 0x20) >> 0x18),bVar43),
                             (ushort)bVar42),uVar45);
    uVar35 = psubsw((ulonglong)
                    CONCAT52((int5)(CONCAT43((int)(((uint7)CONCAT21((short)(((uint7)bVar34 << 0x30)
                                                                           >> 0x28),bVar34) << 0x20)
                                                  >> 0x18),CONCAT12(bVar34,CONCAT11(bVar34,bVar34)))
                                   >> 0x10),CONCAT11(bVar34,bVar34)) & 0xffff00ff00ff00ff,
                    0x80008000800080);
    uVar39 = (undefined1)((uint)*puVar25 >> 0x18);
    bVar34 = (byte)((uint)*puVar25 >> 0x10);
    uVar35 = psllw(uVar35,2);
    uVar35 = paddsw(uVar35,_DAT_00a2e520);
    uVar35 = pmulhw(uVar35,_DAT_00a2e500);
    uVar44 = psubsw((ulonglong)
                    CONCAT52((int5)(CONCAT43((int)(((uint7)CONCAT21((short)(((uint7)bVar34 << 0x30)
                                                                           >> 0x28),bVar34) << 0x20)
                                                  >> 0x18),CONCAT12(bVar34,CONCAT11(bVar34,bVar34)))
                                   >> 0x10),CONCAT11(bVar34,bVar34)) & 0xffff00ff00ff00ff,
                    0x80008000800080);
    uVar44 = psllw(uVar44,2);
    uVar44 = paddsw(uVar44,_DAT_00a2e528);
    uVar44 = pmulhw(uVar44,_DAT_00a2e508);
    uVar47 = psubsw((ulonglong)
                    CONCAT16(uVar39,(uint6)CONCAT14(uVar39,(uint)(CONCAT12(uVar39,CONCAT11(uVar39,
                                                  uVar39)) & 0xff00ff))),0x80008000800080);
    uVar36 = paddsw(uVar35,uVar44);
    uVar44 = psllw(uVar47,2);
    uVar35 = psubsw((ulonglong)
                    CONCAT16(uVar37,(uint6)CONCAT14(uVar37,(uint)(CONCAT12(uVar37,CONCAT11(uVar37,
                                                  uVar37)) & 0xff00ff))),0x80008000800080);
    uVar10 = puVar30[1];
    uVar35 = psllw(uVar35,2);
    uVar44 = paddsw(uVar44,_DAT_00a2e538);
    bVar34 = (byte)uVar10;
    uVar35 = paddsw(uVar35,_DAT_00a2e530);
    uVar35 = pmulhw(uVar35,_DAT_00a2e510);
    uVar44 = pmulhw(uVar44,_DAT_00a2e518);
    bVar41 = (byte)((uint)uVar10 >> 8);
    uVar45 = paddsw(uVar35,uVar44);
    uVar35 = paddsw(CONCAT62(CONCAT51((int5)(((ulonglong)
                                              CONCAT31((int3)(((ulonglong)bVar41 << 0x30) >> 0x28),
                                                       bVar34) << 0x20) >> 0x18),bVar34),
                             (ushort)bVar34),uVar36);
    sVar13 = (short)uVar38;
    sVar14 = (short)((ulonglong)uVar38 >> 0x10);
    sVar15 = (short)((ulonglong)uVar38 >> 0x20);
    sVar16 = (short)((ulonglong)uVar38 >> 0x30);
    sVar17 = (short)uVar35;
    sVar18 = (short)((ulonglong)uVar35 >> 0x10);
    sVar19 = (short)((ulonglong)uVar35 >> 0x20);
    sVar20 = (short)((ulonglong)uVar35 >> 0x30);
    uVar11 = puVar22[1];
    puVar32[1] = CONCAT17((0 < sVar20) * (sVar20 < 0x100) * (char)((ulonglong)uVar35 >> 0x30) -
                          (0xff < sVar20),
                          CONCAT16((0 < sVar19) * (sVar19 < 0x100) *
                                   (char)((ulonglong)uVar35 >> 0x20) - (0xff < sVar19),
                                   CONCAT15((0 < sVar18) * (sVar18 < 0x100) *
                                            (char)((ulonglong)uVar35 >> 0x10) - (0xff < sVar18),
                                            CONCAT14((0 < sVar17) * (sVar17 < 0x100) * (char)uVar35
                                                     - (0xff < sVar17),
                                                     CONCAT13((0 < sVar16) * (sVar16 < 0x100) *
                                                              (char)((ulonglong)uVar38 >> 0x30) -
                                                              (0xff < sVar16),
                                                              CONCAT12((0 < sVar15) *
                                                                       (sVar15 < 0x100) *
                                                                       (char)((ulonglong)uVar38 >>
                                                                             0x20) - (0xff < sVar15)
                                                                       ,CONCAT11((0 < sVar14) *
                                                                                 (sVar14 < 0x100) *
                                                                                 (char)((ulonglong)
                                                                                        uVar38 >>
                                                                                       0x10) -
                                                                                 (0xff < sVar14),
                                                                                 (0 < sVar13) *
                                                                                 (sVar13 < 0x100) *
                                                                                 (char)uVar38 -
                                                                                 (0xff < sVar13)))))
                                           )));
    uVar40 = (uVar36 & 0xffffffff0000) >> 0x10 | (uVar45 & 0xffffffff0000) << 0x10;
    uVar37 = (undefined1)uVar11;
    bVar34 = (byte)((uint)uVar11 >> 8);
    uVar35 = paddsw((ulonglong)
                    CONCAT52((int5)(CONCAT43((int)(((uint7)CONCAT21((short)(((uint7)bVar34 << 0x30)
                                                                           >> 0x28),uVar37) << 0x20)
                                                  >> 0x18),CONCAT12(uVar37,CONCAT11(uVar37,uVar37)))
                                   >> 0x10),CONCAT11(uVar37,uVar37)) & 0xffffffff00ff00ff,uVar36);
    sVar13 = (short)uVar46;
    sVar14 = (short)((ulonglong)uVar46 >> 0x10);
    sVar15 = (short)((ulonglong)uVar46 >> 0x20);
    sVar16 = (short)((ulonglong)uVar46 >> 0x30);
    sVar17 = (short)uVar35;
    sVar18 = (short)((ulonglong)uVar35 >> 0x10);
    sVar19 = (short)((ulonglong)uVar35 >> 0x20);
    sVar20 = (short)((ulonglong)uVar35 >> 0x30);
    bVar43 = (byte)((uint)uVar11 >> 0x10);
    puVar27[1] = CONCAT17((0 < sVar20) * (sVar20 < 0x100) * (char)((ulonglong)uVar35 >> 0x30) -
                          (0xff < sVar20),
                          CONCAT16((0 < sVar19) * (sVar19 < 0x100) *
                                   (char)((ulonglong)uVar35 >> 0x20) - (0xff < sVar19),
                                   CONCAT15((0 < sVar18) * (sVar18 < 0x100) *
                                            (char)((ulonglong)uVar35 >> 0x10) - (0xff < sVar18),
                                            CONCAT14((0 < sVar17) * (sVar17 < 0x100) * (char)uVar35
                                                     - (0xff < sVar17),
                                                     CONCAT13((0 < sVar16) * (sVar16 < 0x100) *
                                                              (char)((ulonglong)uVar46 >> 0x30) -
                                                              (0xff < sVar16),
                                                              CONCAT12((0 < sVar15) *
                                                                       (sVar15 < 0x100) *
                                                                       (char)((ulonglong)uVar46 >>
                                                                             0x20) - (0xff < sVar15)
                                                                       ,CONCAT11((0 < sVar14) *
                                                                                 (sVar14 < 0x100) *
                                                                                 (char)((ulonglong)
                                                                                        uVar46 >>
                                                                                       0x10) -
                                                                                 (0xff < sVar14),
                                                                                 (0 < sVar13) *
                                                                                 (sVar13 < 0x100) *
                                                                                 (char)uVar46 -
                                                                                 (0xff < sVar13)))))
                                           )));
    bVar42 = (byte)((uint)uVar10 >> 0x10);
    uVar46 = paddsw((ulonglong)
                    CONCAT52((int5)(CONCAT43((int)(((uint7)CONCAT21((short)(((uint7)bVar43 << 0x30)
                                                                           >> 0x28),bVar43) << 0x20)
                                                  >> 0x18),CONCAT12(bVar34,CONCAT11(bVar34,bVar34)))
                                   >> 0x10),CONCAT11(bVar34,bVar34)) & 0xffffffff00ff00ff,uVar40);
    uVar44 = paddsw((ulonglong)
                    CONCAT52((int5)(CONCAT43((int)(((uint7)CONCAT21((short)(((uint7)bVar42 << 0x30)
                                                                           >> 0x28),bVar42) << 0x20)
                                                  >> 0x18),CONCAT12(bVar41,CONCAT11(bVar41,bVar41)))
                                   >> 0x10),CONCAT11(bVar41,bVar41)) & 0xffffffff00ff00ff,uVar40);
    bVar41 = (byte)((uint)uVar10 >> 0x18);
    puVar30 = puVar30 + 2;
    puVar22 = puVar22 + 2;
    bVar34 = (byte)((uint)uVar11 >> 0x18);
    uVar35 = paddsw(CONCAT62(CONCAT51((int5)(((ulonglong)
                                              CONCAT31((int3)(((ulonglong)bVar41 << 0x30) >> 0x28),
                                                       bVar41) << 0x20) >> 0x18),bVar41),
                             (short)((uint)uVar10 >> 0x10)) & 0xffffffff00ff00ff,uVar45);
    sVar13 = (short)uVar44;
    sVar14 = (short)((ulonglong)uVar44 >> 0x10);
    sVar15 = (short)((ulonglong)uVar44 >> 0x20);
    sVar16 = (short)((ulonglong)uVar44 >> 0x30);
    sVar17 = (short)uVar35;
    sVar18 = (short)((ulonglong)uVar35 >> 0x10);
    sVar19 = (short)((ulonglong)uVar35 >> 0x20);
    sVar20 = (short)((ulonglong)uVar35 >> 0x30);
    puVar29 = puVar29 + 1;
    uVar38 = paddsw(CONCAT62(CONCAT51((int5)(((ulonglong)
                                              CONCAT31((int3)(((ulonglong)bVar34 << 0x30) >> 0x28),
                                                       bVar34) << 0x20) >> 0x18),bVar34),
                             (short)((uint)uVar11 >> 0x10)) & 0xffffffff00ff00ff,uVar45);
    puVar32[2] = CONCAT17((0 < sVar20) * (sVar20 < 0x100) * (char)((ulonglong)uVar35 >> 0x30) -
                          (0xff < sVar20),
                          CONCAT16((0 < sVar19) * (sVar19 < 0x100) *
                                   (char)((ulonglong)uVar35 >> 0x20) - (0xff < sVar19),
                                   CONCAT15((0 < sVar18) * (sVar18 < 0x100) *
                                            (char)((ulonglong)uVar35 >> 0x10) - (0xff < sVar18),
                                            CONCAT14((0 < sVar17) * (sVar17 < 0x100) * (char)uVar35
                                                     - (0xff < sVar17),
                                                     CONCAT13((0 < sVar16) * (sVar16 < 0x100) *
                                                              (char)((ulonglong)uVar44 >> 0x30) -
                                                              (0xff < sVar16),
                                                              CONCAT12((0 < sVar15) *
                                                                       (sVar15 < 0x100) *
                                                                       (char)((ulonglong)uVar44 >>
                                                                             0x20) - (0xff < sVar15)
                                                                       ,CONCAT11((0 < sVar14) *
                                                                                 (sVar14 < 0x100) *
                                                                                 (char)((ulonglong)
                                                                                        uVar44 >>
                                                                                       0x10) -
                                                                                 (0xff < sVar14),
                                                                                 (0 < sVar13) *
                                                                                 (sVar13 < 0x100) *
                                                                                 (char)uVar44 -
                                                                                 (0xff < sVar13)))))
                                           )));
    sVar13 = (short)uVar46;
    sVar14 = (short)((ulonglong)uVar46 >> 0x10);
    sVar15 = (short)((ulonglong)uVar46 >> 0x20);
    sVar16 = (short)((ulonglong)uVar46 >> 0x30);
    sVar17 = (short)uVar38;
    sVar18 = (short)((ulonglong)uVar38 >> 0x10);
    sVar19 = (short)((ulonglong)uVar38 >> 0x20);
    sVar20 = (short)((ulonglong)uVar38 >> 0x30);
    puVar25 = puVar25 + 1;
    puVar27[2] = CONCAT17((0 < sVar20) * (sVar20 < 0x100) * (char)((ulonglong)uVar38 >> 0x30) -
                          (0xff < sVar20),
                          CONCAT16((0 < sVar19) * (sVar19 < 0x100) *
                                   (char)((ulonglong)uVar38 >> 0x20) - (0xff < sVar19),
                                   CONCAT15((0 < sVar18) * (sVar18 < 0x100) *
                                            (char)((ulonglong)uVar38 >> 0x10) - (0xff < sVar18),
                                            CONCAT14((0 < sVar17) * (sVar17 < 0x100) * (char)uVar38
                                                     - (0xff < sVar17),
                                                     CONCAT13((0 < sVar16) * (sVar16 < 0x100) *
                                                              (char)((ulonglong)uVar46 >> 0x30) -
                                                              (0xff < sVar16),
                                                              CONCAT12((0 < sVar15) *
                                                                       (sVar15 < 0x100) *
                                                                       (char)((ulonglong)uVar46 >>
                                                                             0x20) - (0xff < sVar15)
                                                                       ,CONCAT11((0 < sVar14) *
                                                                                 (sVar14 < 0x100) *
                                                                                 (char)((ulonglong)
                                                                                        uVar46 >>
                                                                                       0x10) -
                                                                                 (0xff < sVar14),
                                                                                 (0 < sVar13) *
                                                                                 (sVar13 < 0x100) *
                                                                                 (char)uVar46 -
                                                                                 (0xff < sVar13)))))
                                           )));
    local_1c = local_1c + -1;
    puVar27 = puVar27 + 3;
    puVar32 = puVar32 + 3;
  } while (local_1c != 0);
  local_10 = (byte *)(puVar8 + iVar24);
  local_14 = (byte *)(puVar9 + iVar24);
  param_1 = (byte *)(puVar6 + iVar24 * 2);
  local_8 = (byte *)(puVar7 + iVar24 * 2);
  puVar31 = puVar31 + iVar24 * 3;
  puVar33 = puVar33 + iVar24 * 3;
  local_20 = (int)uVar21 >> 1;
  if (local_20 != 0) {
    do {
      bVar34 = *local_10;
      local_10 = local_10 + 1;
      bVar41 = *local_14;
      local_14 = local_14 + 1;
      iVar24 = *(int *)(iVar3 + (uint)bVar41 * 4);
      iVar12 = *(int *)(iVar4 + (uint)bVar34 * 4);
      uVar28 = (uint)*param_1;
      iVar26 = *(int *)(iVar23 + (uint)bVar34 * 4) + *(int *)(iVar5 + (uint)bVar41 * 4) >> 0x10;
      *(undefined1 *)puVar31 = *(undefined1 *)(uVar28 + iVar24 + iVar2);
      *(undefined1 *)((int)puVar31 + 1) = *(undefined1 *)(uVar28 + iVar26 + iVar2);
      *(undefined1 *)((int)puVar31 + 2) = *(undefined1 *)(uVar28 + iVar12 + iVar2);
      uVar28 = (uint)param_1[1];
      param_1 = param_1 + 2;
      *(undefined1 *)((int)puVar31 + 3) = *(undefined1 *)(uVar28 + iVar24 + iVar2);
      *(undefined1 *)((int)puVar31 + 4) = *(undefined1 *)(uVar28 + iVar26 + iVar2);
      *(undefined1 *)((int)puVar31 + 5) = *(undefined1 *)(uVar28 + iVar12 + iVar2);
      uVar28 = (uint)*local_8;
      puVar31 = (undefined8 *)((int)puVar31 + 6);
      *(undefined1 *)puVar33 = *(undefined1 *)(uVar28 + iVar24 + iVar2);
      *(undefined1 *)((int)puVar33 + 1) = *(undefined1 *)(uVar28 + iVar26 + iVar2);
      *(undefined1 *)((int)puVar33 + 2) = *(undefined1 *)(uVar28 + iVar12 + iVar2);
      uVar28 = (uint)local_8[1];
      local_8 = local_8 + 2;
      *(undefined1 *)((int)puVar33 + 3) = *(undefined1 *)(iVar24 + uVar28 + iVar2);
      *(undefined1 *)((int)puVar33 + 4) = *(undefined1 *)(iVar26 + uVar28 + iVar2);
      *(undefined1 *)((int)puVar33 + 5) = *(undefined1 *)(uVar28 + iVar12 + iVar2);
      puVar33 = (undefined8 *)((int)puVar33 + 6);
      local_20 = local_20 + -1;
    } while (local_20 != 0);
  }
  if ((uVar21 & 1) != 0) {
    iVar3 = *(int *)(iVar3 + (uint)*local_14 * 4);
    iVar23 = *(int *)(iVar23 + (uint)*local_10 * 4);
    iVar5 = *(int *)(iVar5 + (uint)*local_14 * 4);
    iVar4 = *(int *)(iVar4 + (uint)*local_10 * 4);
    uVar21 = (uint)*param_1;
    *(undefined1 *)puVar31 = *(undefined1 *)(uVar21 + iVar3 + iVar2);
    iVar23 = iVar23 + iVar5 >> 0x10;
    *(undefined1 *)((int)puVar31 + 1) = *(undefined1 *)(uVar21 + iVar23 + iVar2);
    *(undefined1 *)((int)puVar31 + 2) = *(undefined1 *)(uVar21 + iVar4 + iVar2);
    uVar21 = (uint)*local_8;
    *(undefined1 *)puVar33 = *(undefined1 *)(iVar3 + uVar21 + iVar2);
    uVar37 = *(undefined1 *)(uVar21 + iVar4 + iVar2);
    *(undefined1 *)((int)puVar33 + 1) = *(undefined1 *)(iVar23 + uVar21 + iVar2);
    *(undefined1 *)((int)puVar33 + 2) = uVar37;
  }
  return;
}


// ==== FUN_00955320 @ 0x00955320 ====

void FUN_00955320(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((*(int *)(param_1 + 0x48) == 5) || (*(int *)(param_1 + 0x48) == 6)) {
    FUN_00954e10(param_2);
    return;
  }
  FUN_00954c20(param_4);
  return;
}


// ==== FUN_00955370 @ 0x00955370 ====

void FUN_00955370(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar2 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x30);
  iVar1 = *(int *)(param_1 + 0x13c);
  iVar3 = *(int *)(param_1 + 0x78) * *(int *)(param_1 + 0x70);
  *(undefined4 **)(param_1 + 0x1c8) = puVar2;
  *puVar2 = FUN_009549a0;
  puVar2[2] = 0;
  puVar2[10] = iVar3;
  if (iVar1 == 2) {
    iVar1 = *(int *)(param_1 + 4);
    puVar2[1] = FUN_009549c0;
    puVar2[3] = FUN_00955320;
    uVar4 = (**(code **)(iVar1 + 4))(param_1,1,iVar3);
    puVar2[8] = uVar4;
    FUN_009548c0();
    return;
  }
  puVar2[1] = FUN_00954a90;
  puVar2[3] = FUN_00954ad0;
  puVar2[8] = 0;
  FUN_009548c0();
  return;
}


// ==== FUN_00955400 @ 0x00955400 ====

void FUN_00955400(undefined4 param_1,int param_2)

{
  void *pvVar1;
  uint uVar2;
  
  pvVar1 = _malloc(param_2 + 0x10);
  if (pvVar1 == (void *)0x0) {
    return;
  }
  uVar2 = (int)pvVar1 + 0x10U & 0xfffffff0;
  *(char *)(uVar2 - 1) = (char)uVar2 - (char)pvVar1;
  return;
}


// ==== FUN_00955430 @ 0x00955430 ====

void FUN_00955430(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    return;
  }
  _free((void *)(param_2 - (uint)*(byte *)(param_2 + -1)));
  return;
}


// ==== FUN_00955450 @ 0x00955450 ====

int FUN_00955450(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  return *(int *)(*(int *)(param_1 + 4) + 0x2c) - param_4;
}


// ==== FUN_00955470 @ 0x00955470 ====

void FUN_00955470(int *param_1,int param_2,void *param_3,long param_4,size_t param_5)

{
  undefined4 *puVar1;
  int iVar2;
  size_t sVar3;
  
  iVar2 = _fseek(*(FILE **)(param_2 + 0xc),param_4,0);
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0x41;
    (*(code *)*puVar1)(param_1);
  }
  sVar3 = _fread(param_3,1,param_5,*(FILE **)(param_2 + 0xc));
  if (sVar3 != param_5) {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0x40;
    (*(code *)*puVar1)(param_1);
  }
  return;
}


// ==== FUN_009554d0 @ 0x009554d0 ====

void FUN_009554d0(int *param_1,int param_2,void *param_3,long param_4,size_t param_5)

{
  undefined4 *puVar1;
  int iVar2;
  size_t sVar3;
  
  iVar2 = _fseek(*(FILE **)(param_2 + 0xc),param_4,0);
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0x41;
    (*(code *)*puVar1)(param_1);
  }
  sVar3 = _fwrite(param_3,1,param_5,*(FILE **)(param_2 + 0xc));
  if (sVar3 != param_5) {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0x42;
    (*(code *)*puVar1)(param_1);
  }
  return;
}


// ==== FUN_00955530 @ 0x00955530 ====

void FUN_00955530(undefined4 param_1,int param_2)

{
  _fclose(*(FILE **)(param_2 + 0xc));
  return;
}


// ==== FUN_00955550 @ 0x00955550 ====

void FUN_00955550(int *param_1,undefined4 *param_2)

{
  int iVar1;
  FILE *pFVar2;
  
  pFVar2 = _tmpfile();
  param_2[3] = pFVar2;
  if (pFVar2 == (FILE *)0x0) {
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x14) = 0x3f;
    _strncpy((char *)(iVar1 + 0x18),&DAT_0099cf70,0x50);
    (**(code **)*param_1)(param_1);
  }
  *param_2 = FUN_00955470;
  param_2[1] = FUN_009554d0;
  param_2[2] = FUN_00955530;
  return;
}


// ==== FUN_009555b0 @ 0x009555b0 ====

undefined4 FUN_009555b0(void)

{
  return 1000000;
}


// ==== FUN_009555c0 @ 0x009555c0 ====

void FUN_009555c0(int param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = *(int *)(param_1 + 0x158);
  if (*(uint *)(iVar2 + 8) < *(uint *)(param_1 + 0xf8)) {
    puVar1 = (uint *)(iVar2 + 0xc);
    while( true ) {
      uVar3 = *puVar1;
      if (uVar3 < 8) {
        (**(code **)(*(int *)(param_1 + 0x15c) + 4))
                  (param_1,param_2,param_3,param_4,iVar2 + 0x18,puVar1,8);
        uVar3 = *puVar1;
      }
      if (uVar3 != 8) {
        return;
      }
      iVar4 = (**(code **)(*(int *)(param_1 + 0x160) + 4))(param_1,iVar2 + 0x18);
      if (iVar4 == 0) break;
      if (*(int *)(iVar2 + 0x10) != 0) {
        *param_3 = *param_3 + 1;
        *(undefined4 *)(iVar2 + 0x10) = 0;
      }
      uVar3 = *(uint *)(param_1 + 0xf8);
      uVar5 = *(int *)(iVar2 + 8) + 1;
      *puVar1 = 0;
      *(uint *)(iVar2 + 8) = uVar5;
      if (uVar3 <= uVar5) {
        return;
      }
    }
    if (*(int *)(iVar2 + 0x10) == 0) {
      *param_3 = *param_3 + -1;
      *(undefined4 *)(iVar2 + 0x10) = 1;
    }
  }
  return;
}


// ==== FUN_00955670 @ 0x00955670 ====

void FUN_00955670(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = param_1[0x56];
  if (param_1[0x2c] == 0) {
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(int *)(iVar1 + 0x14) = param_2;
    if (param_2 != 0) {
      puVar2 = (undefined4 *)*param_1;
      puVar2[5] = 4;
      (*(code *)*puVar2)(param_1);
      return;
    }
    *(code **)(iVar1 + 4) = FUN_009555c0;
  }
  return;
}


// ==== FUN_009556d0 @ 0x009556d0 ====

void FUN_009556d0(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  
  piVar3 = param_1;
  puVar4 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x40);
  iVar2 = param_1[0x2c];
  param_1[0x56] = (int)puVar4;
  *puVar4 = FUN_00955670;
  if (iVar2 == 0) {
    if (param_2 != 0) {
      puVar4 = (undefined4 *)*param_1;
      puVar4[5] = 4;
      (*(code *)*puVar4)(param_1);
      return;
    }
    piVar6 = param_1 + 0xf;
    piVar1 = param_1 + 0x11;
    param_1 = (int *)0x0;
    if (0 < *piVar6) {
      piVar6 = (int *)(*piVar1 + 0x1c);
      puVar4 = puVar4 + 6;
      do {
        uVar5 = (**(code **)(piVar3[1] + 8))(piVar3,1,*piVar6 << 3,piVar6[-4] << 3);
        iVar2 = piVar3[0xf];
        *puVar4 = uVar5;
        param_1 = (int *)((int)param_1 + 1);
        puVar4 = puVar4 + 1;
        piVar6 = piVar6 + 0x15;
      } while ((int)param_1 < iVar2);
    }
  }
  return;
}


// ==== FUN_00955770 @ 0x00955770 ====

undefined4 FUN_00955770(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int *local_2c;
  int local_28;
  undefined4 *local_24;
  int local_1c;
  int local_18;
  undefined4 *local_14;
  uint local_10;
  int local_c;
  
  iVar1 = *(int *)(param_1 + 0xf8);
  uVar8 = *(int *)(param_1 + 0x110) - 1;
  iVar2 = *(int *)(param_1 + 0x160);
  local_c = *(int *)(iVar2 + 0x10);
  if (local_c < *(int *)(iVar2 + 0x14)) {
    do {
      local_10 = *(uint *)(iVar2 + 0xc);
      if (local_10 <= uVar8) {
        do {
          iVar9 = 0;
          local_28 = 0;
          if (0 < *(int *)(param_1 + 0xfc)) {
            local_2c = (int *)(param_1 + 0x100);
            do {
              iVar3 = *local_2c;
              if (local_10 < uVar8) {
                iVar10 = *(int *)(iVar3 + 0x34);
              }
              else {
                iVar10 = *(int *)(iVar3 + 0x44);
              }
              iVar4 = *(int *)(iVar3 + 0x40);
              local_18 = local_c << 3;
              local_1c = 0;
              if (0 < *(int *)(iVar3 + 0x38)) {
                iVar7 = *(int *)(iVar3 + 0x34);
                do {
                  if ((*(uint *)(iVar2 + 8) < iVar1 - 1U) ||
                     (local_1c + local_c < *(int *)(iVar3 + 0x48))) {
                    (**(code **)(*(int *)(param_1 + 0x170) + 4))
                              (param_1,iVar3,*(undefined4 *)(param_2 + *(int *)(iVar3 + 4) * 4),
                               *(undefined4 *)(iVar2 + 0x18 + iVar9 * 4),local_18,iVar4 * local_10,
                               iVar10);
                    iVar7 = *(int *)(iVar3 + 0x34);
                    if (iVar10 < iVar7) {
                      FUN_0090b7b0(*(undefined4 *)(iVar2 + 0x18 + (iVar10 + iVar9) * 4),
                                   (iVar7 - iVar10) * 0x80);
                      iVar7 = *(int *)(iVar3 + 0x34);
                      if (iVar10 < iVar7) {
                        local_24 = (undefined4 *)(iVar2 + 0x18 + (iVar10 + iVar9) * 4);
                        local_14 = (undefined4 *)(iVar7 - iVar10);
                        do {
                          *(undefined2 *)*local_24 = *(undefined2 *)local_24[-1];
                          local_24 = local_24 + 1;
                          local_14 = (undefined4 *)((int)local_14 + -1);
                        } while (local_14 != (undefined4 *)0x0);
                      }
                    }
                  }
                  else {
                    FUN_0090b7b0(*(undefined4 *)(iVar2 + 0x18 + iVar9 * 4),iVar7 << 7);
                    iVar7 = *(int *)(iVar3 + 0x34);
                    if (0 < iVar7) {
                      puVar5 = *(undefined2 **)(iVar2 + 0x14 + iVar9 * 4);
                      local_14 = (undefined4 *)(iVar2 + 0x18 + iVar9 * 4);
                      local_24 = (undefined4 *)iVar7;
                      do {
                        *(undefined2 *)*local_14 = *puVar5;
                        local_14 = local_14 + 1;
                        local_24 = (undefined4 *)((int)local_24 + -1);
                      } while (local_24 != (undefined4 *)0x0);
                    }
                  }
                  local_18 = local_18 + 8;
                  iVar9 = iVar9 + iVar7;
                  local_1c = local_1c + 1;
                } while (local_1c < *(int *)(iVar3 + 0x38));
              }
              local_28 = local_28 + 1;
              local_2c = local_2c + 1;
            } while (local_28 < *(int *)(param_1 + 0xfc));
          }
          iVar9 = (**(code **)(*(int *)(param_1 + 0x174) + 4))(param_1,iVar2 + 0x18);
          if (iVar9 == 0) {
            *(int *)(iVar2 + 0x10) = local_c;
            *(uint *)(iVar2 + 0xc) = local_10;
            return 0;
          }
          local_10 = local_10 + 1;
        } while (local_10 <= uVar8);
      }
      *(undefined4 *)(iVar2 + 0xc) = 0;
      local_c = local_c + 1;
    } while (local_c < *(int *)(iVar2 + 0x14));
  }
  iVar1 = *(int *)(param_1 + 0xfc);
  iVar9 = *(int *)(param_1 + 0x160);
  uVar6 = 1;
  *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;
  if (1 < iVar1) {
    *(undefined4 *)(iVar9 + 0x14) = 1;
    *(undefined4 *)(iVar9 + 0xc) = 0;
    *(undefined4 *)(iVar9 + 0x10) = 0;
    return uVar6;
  }
  if (*(uint *)(iVar9 + 8) < *(int *)(param_1 + 0xf8) - 1U) {
    *(undefined4 *)(iVar9 + 0x14) = *(undefined4 *)(*(int *)(param_1 + 0x100) + 0xc);
    *(undefined4 *)(iVar9 + 0xc) = 0;
    *(undefined4 *)(iVar9 + 0x10) = 0;
    return uVar6;
  }
  *(undefined4 *)(iVar9 + 0x14) = *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x48);
  *(undefined4 *)(iVar9 + 0xc) = 0;
  *(undefined4 *)(iVar9 + 0x10) = 0;
  return uVar6;
}


// ==== FUN_00955a30 @ 0x00955a30 ====

undefined4 FUN_00955a30(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
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
  int local_c;
  int local_8;
  
  iVar5 = *(int *)(param_1 + 0x160);
  iVar6 = 0;
  local_18 = iVar5;
  if (0 < *(int *)(param_1 + 0xfc)) {
    piVar7 = (int *)(param_1 + 0x100);
    iVar2 = iVar5;
    do {
      iVar5 = local_18;
      iVar1 = *(int *)(*piVar7 + 0xc);
      iVar2 = (**(code **)(*(int *)(param_1 + 4) + 0x20))
                        (param_1,*(undefined4 *)(local_18 + 0x40 + *(int *)(*piVar7 + 4) * 4),
                         *(int *)(iVar2 + 8) * iVar1,iVar1,0);
      aiStack_38[iVar6] = iVar2;
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + 1;
      iVar2 = iVar5;
    } while (iVar6 < *(int *)(param_1 + 0xfc));
  }
  local_8 = *(int *)(iVar5 + 0x10);
  if (local_8 < *(int *)(iVar5 + 0x14)) {
    do {
      uVar8 = *(uint *)(iVar5 + 0xc);
      local_20 = uVar8;
      if (uVar8 < *(uint *)(param_1 + 0x110)) {
        do {
          local_28 = *(int *)(param_1 + 0xfc);
          local_c = 0;
          local_10 = 0;
          if (0 < local_28) {
            local_14 = (int *)(param_1 + 0x100);
            do {
              iVar6 = *(int *)(*local_14 + 0x34);
              iVar2 = *(int *)(*local_14 + 0x38);
              if (0 < iVar2) {
                local_24 = iVar6 * uVar8 * 0x80;
                piVar7 = (int *)(aiStack_38[local_10] + local_8 * 4);
                local_1c = iVar2;
                do {
                  iVar2 = *piVar7 + local_24;
                  if (0 < iVar6) {
                    piVar4 = (int *)(iVar5 + 0x18 + local_c * 4);
                    local_c = local_c + iVar6;
                    iVar5 = iVar6;
                    do {
                      *piVar4 = iVar2;
                      piVar4 = piVar4 + 1;
                      iVar2 = iVar2 + 0x80;
                      iVar5 = iVar5 + -1;
                    } while (iVar5 != 0);
                    iVar5 = local_18;
                  }
                  piVar7 = piVar7 + 1;
                  local_1c = local_1c + -1;
                } while (local_1c != 0);
              }
              local_10 = local_10 + 1;
              local_14 = local_14 + 1;
            } while (local_10 < local_28);
          }
          local_20 = uVar8;
          iVar6 = (**(code **)(*(int *)(param_1 + 0x174) + 4))(param_1,iVar5 + 0x18);
          if (iVar6 == 0) {
            *(uint *)(iVar5 + 0xc) = uVar8;
            *(int *)(iVar5 + 0x10) = local_8;
            return 0;
          }
          uVar8 = uVar8 + 1;
          local_20 = uVar8;
        } while (uVar8 < *(uint *)(param_1 + 0x110));
      }
      *(undefined4 *)(iVar5 + 0xc) = 0;
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(iVar5 + 0x14));
  }
  iVar6 = *(int *)(param_1 + 0xfc);
  iVar2 = *(int *)(param_1 + 0x160);
  uVar3 = 1;
  *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) + 1;
  if (1 < iVar6) {
    *(undefined4 *)(iVar2 + 0x14) = 1;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    return uVar3;
  }
  if (*(uint *)(iVar2 + 8) < *(int *)(param_1 + 0xf8) - 1U) {
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(*(int *)(param_1 + 0x100) + 0xc);
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    return uVar3;
  }
  *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x48);
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  return uVar3;
}


// ==== FUN_00955c40 @ 0x00955c40 ====

void FUN_00955c40(int param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined2 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined2 *puVar11;
  int iVar12;
  int local_2c;
  undefined4 *local_20;
  undefined4 *local_1c;
  int local_14;
  uint local_c;
  uint local_8;
  
  uVar8 = *(int *)(param_1 + 0xf8) - 1;
  local_14 = *(int *)(param_1 + 0x44);
  iVar2 = *(int *)(param_1 + 0x160);
  local_2c = 0;
  if (0 < *(int *)(param_1 + 0x3c)) {
    local_1c = (undefined4 *)(iVar2 + 0x40);
    local_20 = param_2;
    do {
      iVar5 = (**(code **)(*(int *)(param_1 + 4) + 0x20))
                        (param_1,*local_1c,*(int *)(iVar2 + 8) * *(int *)(local_14 + 0xc),
                         *(int *)(local_14 + 0xc),1);
      if (*(uint *)(iVar2 + 8) < uVar8) {
        local_c = *(uint *)(local_14 + 0xc);
      }
      else {
        local_c = *(uint *)(local_14 + 0x20) % *(uint *)(local_14 + 0xc);
        if (local_c == 0) {
          local_c = *(uint *)(local_14 + 0xc);
        }
      }
      uVar3 = *(uint *)(local_14 + 0x1c);
      uVar4 = *(uint *)(local_14 + 8);
      uVar9 = uVar3 % uVar4;
      if (0 < (int)uVar9) {
        uVar9 = uVar4 - uVar9;
      }
      local_8 = 0;
      if (0 < (int)local_c) {
        do {
          iVar12 = *(int *)(iVar5 + local_8 * 4);
          (**(code **)(*(int *)(param_1 + 0x170) + 4))
                    (param_1,local_14,*local_20,iVar12,local_8 << 3,0,uVar3);
          if (0 < (int)uVar9) {
            puVar11 = (undefined2 *)(iVar12 + uVar3 * 0x80);
            FUN_0090b7b0(puVar11,uVar9 << 7);
            uVar1 = puVar11[-0x40];
            if (0 < (int)uVar9) {
              uVar6 = uVar9;
              do {
                *puVar11 = uVar1;
                puVar11 = puVar11 + 0x40;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
          }
          local_8 = local_8 + 1;
        } while ((int)local_8 < (int)local_c);
      }
      if (*(uint *)(iVar2 + 8) == uVar8) {
        uVar6 = (uVar3 + uVar9) / uVar4;
        local_8 = local_c;
        if ((int)local_c < *(int *)(local_14 + 0xc)) {
          do {
            puVar11 = *(undefined2 **)(iVar5 + local_8 * 4);
            iVar12 = *(int *)(iVar5 + -4 + local_8 * 4);
            FUN_0090b7b0(puVar11,(uVar3 + uVar9) * 0x80);
            if (uVar6 != 0) {
              local_c = uVar6;
              do {
                uVar1 = *(undefined2 *)(uVar4 * 0x80 + -0x80 + iVar12);
                if (0 < (int)uVar4) {
                  puVar7 = puVar11;
                  uVar10 = uVar4;
                  do {
                    *puVar7 = uVar1;
                    puVar7 = puVar7 + 0x40;
                    uVar10 = uVar10 - 1;
                  } while (uVar10 != 0);
                }
                puVar11 = puVar11 + uVar4 * 0x40;
                iVar12 = iVar12 + uVar4 * 0x80;
                local_c = local_c - 1;
              } while (local_c != 0);
            }
            local_8 = local_8 + 1;
          } while ((int)local_8 < *(int *)(local_14 + 0xc));
        }
      }
      local_1c = local_1c + 1;
      local_20 = local_20 + 1;
      local_2c = local_2c + 1;
      local_14 = local_14 + 0x54;
    } while (local_2c < *(int *)(param_1 + 0x3c));
  }
  FUN_00955a30(param_1,param_2);
  return;
}


// ==== FUN_00955e40 @ 0x00955e40 ====

void FUN_00955e40(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  iVar1 = param_1[0x58];
  iVar2 = param_1[0x3f];
  uVar4 = 1;
  *(undefined4 *)(iVar1 + 8) = 0;
  if (iVar2 < 2) {
    if (param_1[0x3e] == 1) {
      uVar4 = *(undefined4 *)(param_1[0x40] + 0x48);
    }
    else {
      uVar4 = *(undefined4 *)(param_1[0x40] + 0xc);
    }
  }
  *(undefined4 *)(iVar1 + 0x14) = uVar4;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  if (param_2 == 0) {
    if (*(int *)(iVar1 + 0x40) != 0) {
      puVar3 = (undefined4 *)*param_1;
      puVar3[5] = 4;
      (*(code *)*puVar3)(param_1);
    }
    *(code **)(iVar1 + 4) = FUN_00955770;
    return;
  }
  if (param_2 == 2) {
    if (*(int *)(iVar1 + 0x40) == 0) {
      puVar3 = (undefined4 *)*param_1;
      puVar3[5] = 4;
      (*(code *)*puVar3)(param_1);
    }
    *(code **)(iVar1 + 4) = FUN_00955a30;
    return;
  }
  if (param_2 != 3) {
    puVar3 = (undefined4 *)*param_1;
    puVar3[5] = 4;
    (*(code *)*puVar3)(param_1);
    return;
  }
  if (*(int *)(iVar1 + 0x40) == 0) {
    puVar3 = (undefined4 *)*param_1;
    puVar3[5] = 4;
    (*(code *)*puVar3)(param_1);
  }
  *(code **)(iVar1 + 4) = FUN_00955c40;
  return;
}


// ==== FUN_00955f10 @ 0x00955f10 ====

void FUN_00955f10(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  
  iVar8 = param_1;
  puVar4 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x68);
  *(undefined4 **)(param_1 + 0x160) = puVar4;
  *puVar4 = FUN_00955e40;
  if (param_2 == (undefined4 *)0x0) {
    iVar8 = (**(code **)(*(int *)(param_1 + 4) + 4))(param_1,1,0x500);
    puVar4[7] = iVar8 + 0x80;
    puVar4[8] = iVar8 + 0x100;
    puVar4[9] = iVar8 + 0x180;
    puVar4[10] = iVar8 + 0x200;
    puVar4[0xb] = iVar8 + 0x280;
    puVar4[0xc] = iVar8 + 0x300;
    puVar4[6] = iVar8;
    puVar4[0xd] = iVar8 + 0x380;
    puVar4[0xe] = iVar8 + 0x400;
    puVar4[0xf] = iVar8 + 0x480;
    puVar4[0x10] = 0;
  }
  else {
    piVar1 = (int *)(param_1 + 0x3c);
    piVar2 = (int *)(param_1 + 0x44);
    param_1 = 0;
    if (0 < *piVar1) {
      param_2 = puVar4 + 0x10;
      puVar4 = (undefined4 *)(*piVar2 + 0xc);
      do {
        uVar7 = *puVar4;
        iVar3 = *(int *)(iVar8 + 4);
        uVar5 = FUN_0090b710(puVar4[5],uVar7);
        uVar6 = FUN_0090b710(puVar4[4],puVar4[-1]);
        uVar7 = (**(code **)(iVar3 + 0x14))(iVar8,1,0,uVar6,uVar5,uVar7);
        *param_2 = uVar7;
        param_2 = param_2 + 1;
        param_1 = param_1 + 1;
        puVar4 = puVar4 + 0x15;
      } while (param_1 < *(int *)(iVar8 + 0x3c));
      return;
    }
  }
  return;
}


// ==== FUN_00956010 @ 0x00956010 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00956010(int *param_1,int param_2,int param_3,int *param_4)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  int aiStack_524 [257];
  int local_120;
  int *local_11c;
  int local_118;
  int local_114;
  int local_110;
  char local_10c [260];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  local_11c = param_1;
  if ((param_3 < 0) || (3 < param_3)) {
    puVar10 = (undefined4 *)*param_1;
    puVar10[5] = 0x32;
    puVar10[6] = param_3;
    (*(code *)*puVar10)(param_1);
  }
  if (param_2 == 0) {
    local_114 = param_1[param_3 + 0x1a];
  }
  else {
    local_114 = param_1[param_3 + 0x16];
  }
  if (local_114 == 0) {
    puVar10 = (undefined4 *)*param_1;
    puVar10[5] = 0x32;
    puVar10[6] = param_3;
    (*(code *)*puVar10)(param_1);
  }
  if (*param_4 == 0) {
    iVar2 = (**(code **)param_1[1])(param_1,1,0x500);
    *param_4 = iVar2;
  }
  iVar2 = 0;
  local_120 = *param_4;
  local_118 = 0;
  local_110 = 1;
  do {
    iVar9 = local_110;
    bVar1 = *(byte *)(local_110 + local_114);
    uVar8 = (uint)bVar1;
    if (0x100 < (int)(uVar8 + iVar2)) {
      puVar10 = (undefined4 *)*local_11c;
      puVar10[5] = 8;
      (*(code *)*puVar10)(local_11c);
    }
    if (uVar8 != 0) {
      cVar5 = (char)iVar9;
      pcVar3 = local_10c + iVar2;
      for (uVar4 = (uint)(bVar1 >> 2); uVar4 != 0; uVar4 = uVar4 - 1) {
        *(uint *)pcVar3 = CONCAT22(CONCAT11(cVar5,cVar5),CONCAT11(cVar5,cVar5));
        pcVar3 = pcVar3 + 4;
      }
      for (uVar4 = uVar8 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar3 = cVar5;
        pcVar3 = pcVar3 + 1;
      }
      iVar2 = local_118 + uVar8;
      local_118 = iVar2;
      iVar9 = local_110;
    }
    local_110 = iVar9 + 1;
  } while (local_110 < 0x11);
  local_10c[iVar2] = '\0';
  local_110 = iVar2;
  iVar9 = 0;
  iVar2 = 0;
  iVar6 = (int)local_10c[0];
  if (local_10c[0] != '\0') {
    pcVar3 = local_10c;
    do {
      cVar5 = *pcVar3;
      while (cVar5 == iVar6) {
        cVar5 = local_10c[iVar2 + 1];
        aiStack_524[iVar2] = iVar9;
        iVar2 = iVar2 + 1;
        iVar9 = iVar9 + 1;
      }
      if (1 << ((byte)iVar6 & 0x1f) <= iVar9) {
        puVar10 = (undefined4 *)*local_11c;
        puVar10[5] = 8;
        (*(code *)*puVar10)(local_11c);
      }
      pcVar3 = local_10c + iVar2;
      iVar9 = iVar9 << 1;
      iVar6 = iVar6 + 1;
    } while (local_10c[iVar2] != '\0');
  }
  puVar7 = (undefined4 *)(local_120 + 0x400);
  puVar10 = puVar7;
  for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  local_118 = (-(uint)(param_2 != 0) & 0xffffff10) + 0xff;
  iVar2 = 0;
  if (0 < local_110) {
    do {
      uVar8 = (uint)*(byte *)(local_114 + 0x11 + iVar2);
      if ((local_118 < (int)uVar8) || (*(char *)((int)puVar7 + uVar8) != '\0')) {
        puVar10 = (undefined4 *)*local_11c;
        puVar10[5] = 8;
        (*(code *)*puVar10)(local_11c);
      }
      cVar5 = local_10c[iVar2];
      *(int *)(local_120 + uVar8 * 4) = aiStack_524[iVar2];
      *(char *)((int)puVar7 + uVar8) = cVar5;
      iVar2 = iVar2 + 1;
    } while (iVar2 < local_110);
  }
  return;
}


// ==== FUN_00956250 @ 0x00956250 ====

undefined4 FUN_00956250(uint param_1,int param_2)

{
  int *piVar1;
  char *pcVar2;
  undefined1 *puVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int *unaff_ESI;
  uint uVar7;
  
  iVar6 = unaff_ESI[3];
  if (param_2 == 0) {
    piVar1 = (int *)unaff_ESI[8];
    *(undefined4 *)(*piVar1 + 0x14) = 0x28;
    (**(code **)*piVar1)(piVar1);
  }
  iVar6 = iVar6 + param_2;
  uVar7 = ((1 << ((byte)param_2 & 0x1f)) - 1U & param_1) << (0x18U - (char)iVar6 & 0x1f) |
          unaff_ESI[2];
  do {
    if (iVar6 < 8) {
      unaff_ESI[2] = uVar7;
      unaff_ESI[3] = iVar6;
      return 1;
    }
    pcVar2 = (char *)*unaff_ESI;
    cVar4 = (char)(uVar7 >> 0x10);
    *pcVar2 = cVar4;
    *unaff_ESI = (int)(pcVar2 + 1);
    piVar1 = unaff_ESI + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      piVar1 = *(int **)(unaff_ESI[8] + 0x18);
      iVar5 = (*(code *)piVar1[3])(unaff_ESI[8]);
      if (iVar5 == 0) {
        return 0;
      }
      iVar5 = piVar1[1];
      *unaff_ESI = *piVar1;
      unaff_ESI[1] = iVar5;
    }
    if (cVar4 == -1) {
      puVar3 = (undefined1 *)*unaff_ESI;
      *puVar3 = 0;
      *unaff_ESI = (int)(puVar3 + 1);
      piVar1 = unaff_ESI + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        piVar1 = *(int **)(unaff_ESI[8] + 0x18);
        iVar5 = (*(code *)piVar1[3])(unaff_ESI[8]);
        if (iVar5 == 0) {
          return 0;
        }
        iVar5 = piVar1[1];
        *unaff_ESI = *piVar1;
        unaff_ESI[1] = iVar5;
      }
    }
    uVar7 = uVar7 << 8;
    iVar6 = iVar6 + -8;
  } while( true );
}


// ==== FUN_00956330 @ 0x00956330 ====

undefined4 FUN_00956330(int param_1,short *param_2,int param_3,int param_4,undefined4 *param_5)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *local_8;
  
  param_3 = *param_2 - param_3;
  iVar3 = param_3;
  if (param_3 < 0) {
    iVar3 = -param_3;
    param_3 = param_3 + -1;
  }
  iVar4 = 0;
  if (iVar3 != 0) {
    do {
      iVar3 = iVar3 >> 1;
      iVar4 = iVar4 + 1;
    } while (iVar3 != 0);
    if (0xb < iVar4) {
      piVar1 = *(int **)(param_1 + 0x20);
      puVar2 = (undefined4 *)*piVar1;
      puVar2[5] = 6;
      (*(code *)*puVar2)(piVar1);
    }
  }
  iVar3 = FUN_00956250(*(undefined4 *)(param_4 + iVar4 * 4),(int)*(char *)(iVar4 + 0x400 + param_4))
  ;
  if ((iVar3 != 0) && ((iVar4 == 0 || (iVar3 = FUN_00956250(param_3,iVar4), iVar3 != 0)))) {
    iVar3 = 0;
    local_8 = &DAT_00a28754;
    do {
      param_3 = (int)param_2[*local_8];
      if (param_3 == 0) {
        iVar3 = iVar3 + 1;
      }
      else {
        for (; 0xf < iVar3; iVar3 = iVar3 + -0x10) {
          iVar4 = FUN_00956250(param_5[0xf0],(int)*(char *)(param_5 + 0x13c));
          if (iVar4 == 0) {
            return 0;
          }
        }
        iVar4 = param_3;
        if (param_3 < 0) {
          iVar4 = -param_3;
          param_3 = param_3 + -1;
        }
        iVar4 = iVar4 >> 1;
        iVar5 = 1;
        param_4 = 1;
        if (iVar4 != 0) {
          do {
            iVar4 = iVar4 >> 1;
            iVar5 = iVar5 + 1;
          } while (iVar4 != 0);
          param_4 = iVar5;
          if (10 < iVar5) {
            piVar1 = *(int **)(param_1 + 0x20);
            puVar2 = (undefined4 *)*piVar1;
            puVar2[5] = 6;
            (*(code *)*puVar2)(piVar1);
          }
        }
        iVar3 = iVar3 * 0x10 + param_4;
        iVar3 = FUN_00956250(param_5[iVar3],(int)*(char *)(iVar3 + 0x400 + (int)param_5));
        if (iVar3 == 0) {
          return 0;
        }
        iVar3 = FUN_00956250(param_3,param_4);
        if (iVar3 == 0) {
          return 0;
        }
        iVar3 = 0;
      }
      local_8 = local_8 + 1;
    } while ((int)local_8 < 0xa28850);
    if ((iVar3 < 1) || (iVar3 = FUN_00956250(*param_5,(int)*(char *)(param_5 + 0x100)), iVar3 != 0))
    {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_009564c0 @ 0x009564c0 ====

undefined4 FUN_009564c0(char param_1)

{
  undefined1 *puVar1;
  char *pcVar2;
  int *in_EAX;
  int iVar3;
  int *piVar4;
  
  iVar3 = FUN_00956250(0x7f,7);
  if (iVar3 == 0) {
    return 0;
  }
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  puVar1 = (undefined1 *)*in_EAX;
  *puVar1 = 0xff;
  *in_EAX = (int)(puVar1 + 1);
  iVar3 = in_EAX[1];
  in_EAX[1] = iVar3 + -1;
  if (iVar3 + -1 == 0) {
    piVar4 = *(int **)(in_EAX[8] + 0x18);
    iVar3 = (*(code *)piVar4[3])(in_EAX[8]);
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = piVar4[1];
    *in_EAX = *piVar4;
    in_EAX[1] = iVar3;
  }
  pcVar2 = (char *)*in_EAX;
  *pcVar2 = param_1 + -0x30;
  *in_EAX = (int)(pcVar2 + 1);
  piVar4 = in_EAX + 1;
  *piVar4 = *piVar4 + -1;
  if (*piVar4 == 0) {
    piVar4 = *(int **)(in_EAX[8] + 0x18);
    iVar3 = (*(code *)piVar4[3])(in_EAX[8]);
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = piVar4[1];
    *in_EAX = *piVar4;
    in_EAX[1] = iVar3;
  }
  iVar3 = 0;
  if (0 < *(int *)(in_EAX[8] + 0xfc)) {
    piVar4 = in_EAX + 4;
    do {
      *piVar4 = 0;
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar3 < *(int *)(in_EAX[8] + 0xfc));
  }
  return 1;
}


// ==== FUN_00956590 @ 0x00956590 ====

undefined4 FUN_00956590(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20 [4];
  int local_10;
  int *local_c;
  int local_8;
  
  iVar3 = (int)param_1;
  local_30 = **(undefined4 **)((int)param_1 + 0x18);
  local_2c = (*(undefined4 **)((int)param_1 + 0x18))[1];
  iVar1 = *(int *)((int)param_1 + 0x174);
  local_28 = *(undefined4 *)(iVar1 + 0xc);
  local_24 = *(undefined4 *)(iVar1 + 0x10);
  local_20[0] = *(int *)(iVar1 + 0x14);
  local_20[1] = *(undefined4 *)(iVar1 + 0x18);
  local_20[2] = *(undefined4 *)(iVar1 + 0x1c);
  local_20[3] = *(undefined4 *)(iVar1 + 0x20);
  local_10 = (int)param_1;
  local_8 = iVar1;
  if (((*(int *)((int)param_1 + 200) != 0) && (*(int *)(iVar1 + 0x24) == 0)) &&
     (iVar4 = FUN_009564c0(*(undefined4 *)(iVar1 + 0x28)), iVar4 == 0)) {
    return 0;
  }
  iVar4 = 0;
  if (0 < *(int *)((int)param_1 + 0x118)) {
    param_1 = (int *)((int)param_1 + 0x11c);
    do {
      iVar5 = *(int *)(iVar3 + 0x100 + *param_1 * 4);
      local_c = local_20 + *param_1;
      iVar5 = FUN_00956330(&local_30,*(undefined4 *)(param_2 + iVar4 * 4),*local_c,
                           *(undefined4 *)(local_8 + 0x2c + *(int *)(iVar5 + 0x14) * 4),
                           *(undefined4 *)(local_8 + 0x3c + *(int *)(iVar5 + 0x18) * 4));
      if (iVar5 == 0) {
        return 0;
      }
      *local_c = (int)**(short **)(param_2 + iVar4 * 4);
      iVar4 = iVar4 + 1;
      param_1 = param_1 + 1;
    } while (iVar4 < *(int *)(iVar3 + 0x118));
  }
  puVar2 = *(undefined4 **)(iVar3 + 0x18);
  iVar3 = *(int *)(iVar3 + 200);
  *puVar2 = local_30;
  puVar2[1] = local_2c;
  *(undefined4 *)(iVar1 + 0xc) = local_28;
  *(undefined4 *)(iVar1 + 0x10) = local_24;
  *(int *)(iVar1 + 0x14) = local_20[0];
  *(int *)(iVar1 + 0x18) = local_20[1];
  *(int *)(iVar1 + 0x1c) = local_20[2];
  *(int *)(iVar1 + 0x20) = local_20[3];
  if (iVar3 != 0) {
    if (*(int *)(local_8 + 0x24) == 0) {
      *(int *)(local_8 + 0x24) = iVar3;
      *(uint *)(local_8 + 0x28) = *(int *)(local_8 + 0x28) + 1U & 7;
    }
    *(int *)(local_8 + 0x24) = *(int *)(local_8 + 0x24) + -1;
  }
  return 1;
}


// ==== FUN_00956700 @ 0x00956700 ====

void FUN_00956700(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  
  iVar1 = param_1[0x5d];
  uVar2 = *(undefined4 *)param_1[6];
  uVar3 = ((undefined4 *)param_1[6])[1];
  uVar11 = *(undefined4 *)(iVar1 + 0xc);
  uVar10 = *(undefined4 *)(iVar1 + 0x10);
  uVar4 = *(undefined4 *)(iVar1 + 0x14);
  uVar5 = *(undefined4 *)(iVar1 + 0x18);
  uVar6 = *(undefined4 *)(iVar1 + 0x1c);
  uVar7 = *(undefined4 *)(iVar1 + 0x20);
  iVar9 = FUN_00956250(0x7f,7);
  if (iVar9 == 0) {
    puVar8 = (undefined4 *)*param_1;
    puVar8[5] = 0x18;
    (*(code *)*puVar8)(param_1);
  }
  else {
    uVar11 = 0;
    uVar10 = 0;
  }
  puVar8 = (undefined4 *)param_1[6];
  *puVar8 = uVar2;
  puVar8[1] = uVar3;
  *(undefined4 *)(iVar1 + 0xc) = uVar11;
  *(undefined4 *)(iVar1 + 0x10) = uVar10;
  *(undefined4 *)(iVar1 + 0x14) = uVar4;
  *(undefined4 *)(iVar1 + 0x18) = uVar5;
  *(undefined4 *)(iVar1 + 0x1c) = uVar6;
  *(undefined4 *)(iVar1 + 0x20) = uVar7;
  return;
}


// ==== FUN_009567b0 @ 0x009567b0 ====

void FUN_009567b0(int *param_1,short *param_2,int *param_3)

{
  undefined4 *puVar1;
  int in_EAX;
  int iVar2;
  int in_ECX;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar2 = *param_2 - in_ECX;
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  iVar5 = 0;
  if (iVar2 != 0) {
    do {
      iVar2 = iVar2 >> 1;
      iVar5 = iVar5 + 1;
    } while (iVar2 != 0);
    if (0xb < iVar5) {
      puVar1 = (undefined4 *)*param_1;
      puVar1[5] = 6;
      (*(code *)*puVar1)(param_1);
    }
  }
  piVar4 = (int *)(in_EAX + iVar5 * 4);
  *piVar4 = *piVar4 + 1;
  iVar2 = 0;
  piVar4 = &DAT_00a28754;
  do {
    iVar5 = (int)param_2[*piVar4];
    if (iVar5 == 0) {
      iVar2 = iVar2 + 1;
    }
    else {
      if (0xf < iVar2) {
        iVar3 = (iVar2 - 0x10U >> 4) + 1;
        iVar2 = iVar2 + iVar3 * -0x10;
        param_3[0xf0] = iVar3 + param_3[0xf0];
      }
      if (iVar5 < 0) {
        iVar5 = -iVar5;
      }
      iVar5 = iVar5 >> 1;
      iVar3 = 1;
      if (iVar5 != 0) {
        do {
          iVar5 = iVar5 >> 1;
          iVar3 = iVar3 + 1;
        } while (iVar5 != 0);
        if (10 < iVar3) {
          puVar1 = (undefined4 *)*param_1;
          puVar1[5] = 6;
          (*(code *)*puVar1)(param_1);
        }
      }
      iVar3 = iVar2 * 0x10 + iVar3;
      param_3[iVar3] = param_3[iVar3] + 1;
      iVar2 = 0;
    }
    piVar4 = piVar4 + 1;
  } while ((int)piVar4 < 0xa28850);
  if (0 < iVar2) {
    *param_3 = *param_3 + 1;
  }
  return;
}


// ==== FUN_00956890 @ 0x00956890 ====

undefined4 FUN_00956890(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *local_8;
  
  iVar5 = *(int *)(param_1 + 200);
  iVar1 = *(int *)(param_1 + 0x174);
  if (iVar5 != 0) {
    if (*(int *)(iVar1 + 0x24) == 0) {
      iVar3 = *(int *)(param_1 + 0xfc);
      if (0 < iVar3) {
        puVar4 = (undefined4 *)(iVar1 + 0x14);
        for (; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
      }
      *(int *)(iVar1 + 0x24) = iVar5;
    }
    *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + -1;
  }
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0x118)) {
    local_8 = (int *)(param_1 + 0x11c);
    do {
      iVar3 = *local_8;
      FUN_009567b0(param_1,*(undefined4 *)(param_2 + iVar5 * 4),
                   *(undefined4 *)
                    (iVar1 + 0x5c + *(int *)(*(int *)(param_1 + 0x100 + iVar3 * 4) + 0x18) * 4));
      iVar2 = *(int *)(param_1 + 0x118);
      *(int *)(iVar1 + 0x14 + iVar3 * 4) = (int)**(short **)(param_2 + iVar5 * 4);
      iVar5 = iVar5 + 1;
      local_8 = local_8 + 1;
    } while (iVar5 < iVar2);
  }
  return 1;
}


// ==== FUN_00956950 @ 0x00956950 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00956950(int *param_1,undefined4 *param_2,int param_3)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int local_83c [257];
  int local_438 [257];
  undefined4 *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  undefined4 local_8;
  
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_8 = DAT_00b49670;
  local_1c = 0;
  local_34 = param_2;
  local_30 = param_1;
  local_18 = 0;
  piVar9 = local_438;
  for (iVar5 = 0x101; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar9 = 0;
    piVar9 = piVar9 + 1;
  }
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  piVar9 = local_83c;
  for (iVar5 = 0x101; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar9 = -1;
    piVar9 = piVar9 + 1;
  }
  *(undefined4 *)(param_3 + 0x400) = 1;
  while( true ) {
    iVar5 = -1;
    iVar8 = 1000000000;
    iVar6 = 0;
    do {
      iVar7 = *(int *)(param_3 + iVar6 * 4);
      if ((iVar7 != 0) && (iVar7 <= iVar8)) {
        iVar5 = iVar6;
        iVar8 = iVar7;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x101);
    iVar8 = -1;
    iVar6 = 1000000000;
    iVar7 = 0;
    do {
      iVar3 = *(int *)(param_3 + iVar7 * 4);
      if (((iVar3 != 0) && (iVar3 <= iVar6)) && (iVar7 != iVar5)) {
        iVar8 = iVar7;
        iVar6 = iVar3;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x101);
    if (iVar8 < 0) break;
    iVar6 = local_438[iVar5];
    *(int *)(param_3 + iVar5 * 4) = *(int *)(param_3 + iVar5 * 4) + *(int *)(param_3 + iVar8 * 4);
    iVar7 = local_83c[iVar5];
    piVar9 = local_83c + iVar5;
    *(undefined4 *)(param_3 + iVar8 * 4) = 0;
    local_438[iVar5] = iVar6 + 1;
    while (-1 < iVar7) {
      iVar5 = *piVar9;
      iVar7 = local_83c[iVar5];
      piVar9 = local_83c + iVar5;
      local_438[iVar5] = local_438[iVar5] + 1;
    }
    iVar6 = local_438[iVar8];
    local_83c[iVar5] = iVar8;
    iVar5 = local_83c[iVar8];
    piVar9 = local_83c + iVar8;
    local_438[iVar8] = iVar6 + 1;
    while (-1 < iVar5) {
      iVar8 = *piVar9;
      iVar5 = local_83c[iVar8];
      local_438[iVar8] = local_438[iVar8] + 1;
      piVar9 = local_83c + iVar8;
    }
  }
  iVar5 = 0;
  do {
    iVar8 = local_438[iVar5];
    if (iVar8 != 0) {
      if (0x20 < iVar8) {
        puVar4 = (undefined4 *)*local_30;
        puVar4[5] = 0x27;
        (*(code *)*puVar4)(local_30);
      }
      *(char *)((int)&local_2c + iVar8) = *(char *)((int)&local_2c + iVar8) + '\x01';
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x101);
  iVar6 = 0x10;
  iVar8 = 0x1e;
  iVar5 = 0x10;
  do {
    cVar2 = *(char *)((int)&local_2c + iVar8 + 2);
    while (cVar2 != '\0') {
      cVar2 = *(char *)((int)&local_2c + iVar8);
      iVar7 = iVar8;
      while (cVar2 == '\0') {
        iVar3 = iVar7 + 0x40b;
        iVar7 = iVar7 + -1;
        cVar2 = *(char *)((int)local_438 + iVar3);
      }
      pcVar1 = (char *)((int)&local_2c + iVar8 + 2);
      *pcVar1 = *pcVar1 + -2;
      pcVar1 = (char *)((int)&local_2c + iVar8 + 1);
      *pcVar1 = *pcVar1 + '\x01';
      pcVar1 = (char *)((int)&local_2c + iVar7 + 1);
      *pcVar1 = *pcVar1 + '\x02';
      *(char *)((int)&local_2c + iVar7) = *(char *)((int)&local_2c + iVar7) + -1;
      cVar2 = *(char *)((int)&local_2c + iVar8 + 2);
    }
    iVar8 = iVar8 + -1;
    iVar6 = iVar6 + -1;
    cVar2 = (char)local_1c;
  } while (iVar6 != 0);
  while (cVar2 == '\0') {
    iVar8 = iVar5 + 0x40b;
    iVar5 = iVar5 + -1;
    cVar2 = *(char *)((int)local_438 + iVar8);
  }
  *(char *)((int)&local_2c + iVar5) = *(char *)((int)&local_2c + iVar5) + -1;
  *local_34 = local_2c;
  local_34[1] = local_28;
  local_34[2] = local_24;
  local_34[3] = local_20;
  *(char *)(local_34 + 4) = (char)local_1c;
  iVar5 = 0;
  iVar8 = 1;
  do {
    iVar6 = 0;
    do {
      if (local_438[iVar6] == iVar8) {
        *(char *)((int)local_34 + iVar5 + 0x11) = (char)iVar6;
        iVar5 = iVar5 + 1;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x100);
    iVar8 = iVar8 + 1;
  } while (iVar8 < 0x21);
  local_34[0x45] = 0;
  return;
}


// ==== FUN_00956be0 @ 0x00956be0 ====

void FUN_00956be0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_30 [8];
  int *local_10;
  int local_c;
  int local_8;
  
  iVar3 = (int)param_1;
  local_30[4] = 0;
  local_30[0] = 0;
  local_8 = *(int *)((int)param_1 + 0x174);
  local_30[5] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  local_30[3] = 0;
  local_c = 0;
  if (0 < *(int *)((int)param_1 + 0xfc)) {
    param_1 = (int *)((int)param_1 + 0x100);
    do {
      iVar1 = *(int *)(*param_1 + 0x14);
      iVar2 = *(int *)(*param_1 + 0x18);
      local_10 = local_30 + iVar1 + 4;
      if (local_30[iVar1 + 4] == 0) {
        if (*(int *)(iVar3 + 0x58 + iVar1 * 4) == 0) {
          uVar4 = FUN_0090b6c0(iVar3);
          *(undefined4 *)(iVar3 + 0x58 + iVar1 * 4) = uVar4;
        }
        FUN_00956950(iVar3,*(undefined4 *)(iVar3 + 0x58 + iVar1 * 4),
                     *(undefined4 *)(local_8 + 0x4c + iVar1 * 4));
        *local_10 = 1;
      }
      if (local_30[iVar2] == 0) {
        if (*(int *)(iVar3 + 0x68 + iVar2 * 4) == 0) {
          uVar4 = FUN_0090b6c0(iVar3);
          *(undefined4 *)(iVar3 + 0x68 + iVar2 * 4) = uVar4;
        }
        FUN_00956950(iVar3,*(undefined4 *)(iVar3 + 0x68 + iVar2 * 4),
                     *(undefined4 *)(local_8 + 0x5c + iVar2 * 4));
        local_30[iVar2] = 1;
      }
      local_c = local_c + 1;
      param_1 = param_1 + 1;
    } while (local_c < *(int *)(iVar3 + 0xfc));
  }
  return;
}


// ==== FUN_00956ce0 @ 0x00956ce0 ====

void FUN_00956ce0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *local_10;
  int local_c;
  int *local_8;
  
  iVar1 = param_1[0x5d];
  if (param_2 == 0) {
    *(code **)(iVar1 + 4) = FUN_00956590;
    *(code **)(iVar1 + 8) = FUN_00956700;
  }
  else {
    *(code **)(iVar1 + 4) = FUN_00956890;
    *(code **)(iVar1 + 8) = FUN_00956be0;
  }
  local_c = 0;
  if (0 < param_1[0x3f]) {
    local_10 = (undefined4 *)(iVar1 + 0x14);
    local_8 = param_1 + 0x40;
    do {
      iVar2 = *(int *)(*local_8 + 0x18);
      iVar5 = *(int *)(*local_8 + 0x14);
      if (param_2 == 0) {
        FUN_00956010(param_1,1,iVar5,iVar1 + 0x2c + iVar5 * 4);
        FUN_00956010(param_1,0,iVar2,iVar1 + 0x3c + iVar2 * 4);
      }
      else {
        if ((iVar5 < 0) || (3 < iVar5)) {
          puVar6 = (undefined4 *)*param_1;
          puVar6[5] = 0x32;
          puVar6[6] = iVar5;
          (*(code *)*puVar6)(param_1);
        }
        if ((iVar2 < 0) || (3 < iVar2)) {
          puVar6 = (undefined4 *)*param_1;
          puVar6[5] = 0x32;
          puVar6[6] = iVar2;
          (*(code *)*puVar6)(param_1);
        }
        if (*(int *)(iVar1 + 0x4c + iVar5 * 4) == 0) {
          uVar3 = (**(code **)param_1[1])(param_1,1,0x404);
          *(undefined4 *)(iVar1 + 0x4c + iVar5 * 4) = uVar3;
        }
        puVar6 = *(undefined4 **)(iVar1 + 0x4c + iVar5 * 4);
        for (iVar4 = 0x101; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        if (*(int *)(iVar1 + 0x5c + iVar2 * 4) == 0) {
          uVar3 = (**(code **)param_1[1])(param_1,1,0x404);
          *(undefined4 *)(iVar1 + 0x5c + iVar2 * 4) = uVar3;
        }
        puVar6 = *(undefined4 **)(iVar1 + 0x5c + iVar2 * 4);
        for (iVar5 = 0x101; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
      }
      *local_10 = 0;
      local_10 = local_10 + 1;
      local_c = local_c + 1;
      local_8 = local_8 + 1;
    } while (local_c < param_1[0x3f]);
  }
  iVar2 = param_1[0x32];
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(int *)(iVar1 + 0x24) = iVar2;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  return;
}


// ==== FUN_00956e50 @ 0x00956e50 ====

void FUN_00956e50(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x6c);
  *puVar1 = FUN_00956ce0;
  *(undefined4 **)(param_1 + 0x174) = puVar1;
  puVar1[0xf] = 0;
  puVar1[0xb] = 0;
  puVar1[0x17] = 0;
  puVar1[0x13] = 0;
  puVar1[0x10] = 0;
  puVar1[0xc] = 0;
  puVar1[0x18] = 0;
  puVar1[0x14] = 0;
  puVar1[0x11] = 0;
  puVar1[0xd] = 0;
  puVar1[0x19] = 0;
  puVar1[0x15] = 0;
  puVar1[0x12] = 0;
  puVar1[0xe] = 0;
  puVar1[0x1a] = 0;
  puVar1[0x16] = 0;
  return;
}


// ==== FUN_00956eb0 @ 0x00956eb0 ====

void FUN_00956eb0(uint param_1,uint param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  int unaff_ESI;
  
  iVar8 = *(int *)(unaff_ESI + 0x1c);
  if (param_2 == 0) {
    piVar1 = *(int **)(unaff_ESI + 0x20);
    puVar2 = (undefined4 *)*piVar1;
    puVar2[5] = 0x28;
    (*(code *)*puVar2)(piVar1);
  }
  if (*(int *)(unaff_ESI + 0xc) == 0) {
    uVar9 = iVar8 + param_2;
    param_2 = ((1 << ((byte)param_2 & 0x1f)) - 1U & param_1) << (0x18U - (char)uVar9 & 0x1f) |
              *(uint *)(unaff_ESI + 0x18);
    if (7 < (int)uVar9) {
      param_1 = uVar9 >> 3;
      uVar9 = uVar9 + param_1 * -8;
      do {
        pcVar3 = *(char **)(unaff_ESI + 0x10);
        cVar7 = (char)(param_2 >> 0x10);
        *pcVar3 = cVar7;
        *(char **)(unaff_ESI + 0x10) = pcVar3 + 1;
        piVar1 = (int *)(unaff_ESI + 0x14);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          puVar2 = *(undefined4 **)(*(int *)(unaff_ESI + 0x20) + 0x18);
          iVar8 = (*(code *)puVar2[3])(*(int *)(unaff_ESI + 0x20));
          if (iVar8 == 0) {
            piVar1 = *(int **)(unaff_ESI + 0x20);
            puVar4 = (undefined4 *)*piVar1;
            puVar4[5] = 0x18;
            (*(code *)*puVar4)(piVar1);
          }
          uVar5 = puVar2[1];
          *(undefined4 *)(unaff_ESI + 0x10) = *puVar2;
          *(undefined4 *)(unaff_ESI + 0x14) = uVar5;
        }
        if (cVar7 == -1) {
          puVar6 = *(undefined1 **)(unaff_ESI + 0x10);
          *puVar6 = 0;
          *(undefined1 **)(unaff_ESI + 0x10) = puVar6 + 1;
          piVar1 = (int *)(unaff_ESI + 0x14);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            puVar2 = *(undefined4 **)(*(int *)(unaff_ESI + 0x20) + 0x18);
            iVar8 = (*(code *)puVar2[3])(*(int *)(unaff_ESI + 0x20));
            if (iVar8 == 0) {
              piVar1 = *(int **)(unaff_ESI + 0x20);
              puVar4 = (undefined4 *)*piVar1;
              puVar4[5] = 0x18;
              (*(code *)*puVar4)(piVar1);
            }
            uVar5 = puVar2[1];
            *(undefined4 *)(unaff_ESI + 0x10) = *puVar2;
            *(undefined4 *)(unaff_ESI + 0x14) = uVar5;
          }
        }
        param_2 = param_2 << 8;
        param_1 = param_1 - 1;
      } while (param_1 != 0);
    }
    *(uint *)(unaff_ESI + 0x18) = param_2;
    *(uint *)(unaff_ESI + 0x1c) = uVar9;
  }
  return;
}


// ==== FUN_00956fc0 @ 0x00956fc0 ====

void FUN_00956fc0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  if (*(int *)(in_EAX + 0x38) != 0) {
    iVar3 = *(int *)(in_EAX + 0x38) >> 1;
    iVar4 = 0;
    if (iVar3 != 0) {
      do {
        iVar3 = iVar3 >> 1;
        iVar4 = iVar4 + 1;
      } while (iVar3 != 0);
      if (0xe < iVar4) {
        piVar1 = *(int **)(in_EAX + 0x20);
        puVar2 = (undefined4 *)*piVar1;
        puVar2[5] = 0x28;
        (*(code *)*puVar2)(piVar1);
      }
    }
    if (*(int *)(in_EAX + 0xc) == 0) {
      iVar3 = *(int *)(in_EAX + 0x4c + *(int *)(in_EAX + 0x34) * 4);
      FUN_00956eb0(*(undefined4 *)(iVar3 + iVar4 * 0x40),
                   (int)*(char *)(iVar3 + 0x400 + iVar4 * 0x10));
    }
    else {
      piVar1 = (int *)(*(int *)(in_EAX + 0x5c + *(int *)(in_EAX + 0x34) * 4) + iVar4 * 0x40);
      *piVar1 = *piVar1 + 1;
    }
    if (iVar4 != 0) {
      FUN_00956eb0(*(undefined4 *)(in_EAX + 0x38),iVar4);
    }
    iVar3 = *(int *)(in_EAX + 0x3c);
    pcVar5 = *(char **)(in_EAX + 0x40);
    *(undefined4 *)(in_EAX + 0x38) = 0;
    if (*(int *)(in_EAX + 0xc) == 0) {
      for (; iVar3 != 0; iVar3 = iVar3 + -1) {
        FUN_00956eb0((int)*pcVar5,1);
        pcVar5 = pcVar5 + 1;
      }
    }
    *(undefined4 *)(in_EAX + 0x3c) = 0;
  }
  return;
}


// ==== FUN_00957070 @ 0x00957070 ====

void FUN_00957070(char param_1)

{
  undefined1 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  char *pcVar5;
  int in_EAX;
  int iVar6;
  undefined4 *puVar7;
  
  FUN_00956fc0();
  if (*(int *)(in_EAX + 0xc) == 0) {
    FUN_00956eb0(0x7f,7);
    puVar1 = *(undefined1 **)(in_EAX + 0x10);
    *puVar1 = 0xff;
    *(undefined1 **)(in_EAX + 0x10) = puVar1 + 1;
    iVar6 = *(int *)(in_EAX + 0x14) + -1;
    *(undefined4 *)(in_EAX + 0x18) = 0;
    *(undefined4 *)(in_EAX + 0x1c) = 0;
    *(int *)(in_EAX + 0x14) = iVar6;
    if (iVar6 == 0) {
      puVar7 = *(undefined4 **)(*(int *)(in_EAX + 0x20) + 0x18);
      iVar6 = (*(code *)puVar7[3])(*(int *)(in_EAX + 0x20));
      if (iVar6 == 0) {
        piVar2 = *(int **)(in_EAX + 0x20);
        puVar3 = (undefined4 *)*piVar2;
        puVar3[5] = 0x18;
        (*(code *)*puVar3)(piVar2);
      }
      uVar4 = puVar7[1];
      *(undefined4 *)(in_EAX + 0x10) = *puVar7;
      *(undefined4 *)(in_EAX + 0x14) = uVar4;
    }
    pcVar5 = *(char **)(in_EAX + 0x10);
    *pcVar5 = param_1 + -0x30;
    *(char **)(in_EAX + 0x10) = pcVar5 + 1;
    piVar2 = (int *)(in_EAX + 0x14);
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      puVar7 = *(undefined4 **)(*(int *)(in_EAX + 0x20) + 0x18);
      iVar6 = (*(code *)puVar7[3])(*(int *)(in_EAX + 0x20));
      if (iVar6 == 0) {
        piVar2 = *(int **)(in_EAX + 0x20);
        puVar3 = (undefined4 *)*piVar2;
        puVar3[5] = 0x18;
        (*(code *)*puVar3)(piVar2);
      }
      uVar4 = puVar7[1];
      *(undefined4 *)(in_EAX + 0x10) = *puVar7;
      *(undefined4 *)(in_EAX + 0x14) = uVar4;
    }
  }
  if (*(int *)(*(int *)(in_EAX + 0x20) + 0x144) == 0) {
    iVar6 = 0;
    if (0 < *(int *)(*(int *)(in_EAX + 0x20) + 0xfc)) {
      puVar7 = (undefined4 *)(in_EAX + 0x24);
      do {
        *puVar7 = 0;
        iVar6 = iVar6 + 1;
        puVar7 = puVar7 + 1;
      } while (iVar6 < *(int *)(*(int *)(in_EAX + 0x20) + 0xfc));
      return;
    }
  }
  else {
    *(undefined4 *)(in_EAX + 0x38) = 0;
    *(undefined4 *)(in_EAX + 0x3c) = 0;
  }
  return;
}


// ==== FUN_00957160 @ 0x00957160 ====

undefined4 FUN_00957160(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  byte local_10;
  int *local_c;
  int local_8;
  
  piVar5 = param_1;
  puVar1 = (undefined4 *)param_1[6];
  iVar2 = param_1[0x5d];
  *(undefined4 *)(iVar2 + 0x10) = *puVar1;
  iVar6 = param_1[0x32];
  iVar3 = param_1[0x54];
  *(undefined4 *)(iVar2 + 0x14) = puVar1[1];
  if ((iVar6 != 0) && (*(int *)(iVar2 + 0x44) == 0)) {
    FUN_00957070(*(undefined4 *)(iVar2 + 0x48));
  }
  local_8 = 0;
  if (0 < param_1[0x46]) {
    local_c = param_1 + 0x47;
    do {
      iVar6 = *local_c;
      iVar4 = piVar5[iVar6 + 0x40];
      local_10 = (byte)iVar3;
      iVar7 = (int)**(short **)(param_2 + local_8 * 4) >> (local_10 & 0x1f);
      param_1 = (int *)(iVar7 - *(int *)(iVar2 + 0x24 + iVar6 * 4));
      *(int *)(iVar2 + 0x24 + iVar6 * 4) = iVar7;
      iVar6 = (int)param_1;
      if ((int)param_1 < 0) {
        iVar6 = -(int)param_1;
        param_1 = (int *)((int)param_1 + -1);
      }
      iVar7 = 0;
      if (iVar6 != 0) {
        do {
          iVar6 = iVar6 >> 1;
          iVar7 = iVar7 + 1;
        } while (iVar6 != 0);
        if (0xb < iVar7) {
          puVar1 = (undefined4 *)*piVar5;
          puVar1[5] = 6;
          (*(code *)*puVar1)(piVar5);
        }
      }
      if (*(int *)(iVar2 + 0xc) == 0) {
        iVar6 = *(int *)(iVar2 + 0x4c + *(int *)(iVar4 + 0x14) * 4);
        FUN_00956eb0(*(undefined4 *)(iVar6 + iVar7 * 4),(int)*(char *)(iVar6 + 0x400 + iVar7));
      }
      else {
        iVar6 = *(int *)(iVar2 + 0x5c + *(int *)(iVar4 + 0x14) * 4);
        *(int *)(iVar6 + iVar7 * 4) = *(int *)(iVar6 + iVar7 * 4) + 1;
      }
      if (iVar7 != 0) {
        FUN_00956eb0(param_1,iVar7);
      }
      local_8 = local_8 + 1;
      local_c = local_c + 1;
    } while (local_8 < piVar5[0x46]);
  }
  puVar1 = (undefined4 *)piVar5[6];
  iVar6 = piVar5[0x32];
  *puVar1 = *(undefined4 *)(iVar2 + 0x10);
  puVar1[1] = *(undefined4 *)(iVar2 + 0x14);
  if (iVar6 != 0) {
    if (*(int *)(iVar2 + 0x44) == 0) {
      *(int *)(iVar2 + 0x44) = iVar6;
      *(uint *)(iVar2 + 0x48) = *(int *)(iVar2 + 0x48) + 1U & 7;
    }
    *(int *)(iVar2 + 0x44) = *(int *)(iVar2 + 0x44) + -1;
  }
  return 1;
}


// ==== FUN_009572d0 @ 0x009572d0 ====

undefined4 FUN_009572d0(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int local_10;
  uint local_c;
  
  iVar7 = param_1[0x54];
  puVar2 = (undefined4 *)param_1[6];
  iVar3 = param_1[0x5d];
  *(undefined4 *)(iVar3 + 0x10) = *puVar2;
  iVar4 = param_1[0x32];
  iVar5 = param_1[0x52];
  *(undefined4 *)(iVar3 + 0x14) = puVar2[1];
  if ((iVar4 != 0) && (*(int *)(iVar3 + 0x44) == 0)) {
    FUN_00957070(*(undefined4 *)(iVar3 + 0x48));
  }
  iVar4 = *param_2;
  local_10 = param_1[0x51];
  param_2 = (int *)0x0;
  if (local_10 <= iVar5) {
    do {
      iVar8 = (int)*(short *)(iVar4 + (&DAT_00a28750)[local_10] * 2);
      if (iVar8 == 0) {
        param_2 = (int *)((int)param_2 + 1);
      }
      else {
        if (iVar8 < 0) {
          uVar9 = -iVar8 >> ((byte)iVar7 & 0x1f);
          local_c = ~uVar9;
        }
        else {
          uVar9 = iVar8 >> ((byte)iVar7 & 0x1f);
          local_c = uVar9;
        }
        if (uVar9 == 0) {
          param_2 = (int *)((int)param_2 + 1);
        }
        else {
          if (*(int *)(iVar3 + 0x38) != 0) {
            FUN_00956fc0();
          }
          if (0xf < (int)param_2) {
            iVar8 = ((int)param_2 - 0x10U >> 4) + 1;
            param_2 = (int *)((int)param_2 + iVar8 * -0x10);
            do {
              if (*(int *)(iVar3 + 0xc) == 0) {
                iVar10 = *(int *)(iVar3 + 0x4c + *(int *)(iVar3 + 0x34) * 4);
                FUN_00956eb0(*(undefined4 *)(iVar10 + 0x3c0),(int)*(char *)(iVar10 + 0x4f0));
              }
              else {
                piVar1 = (int *)(*(int *)(iVar3 + 0x5c + *(int *)(iVar3 + 0x34) * 4) + 0x3c0);
                *piVar1 = *piVar1 + 1;
              }
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
          iVar10 = (int)uVar9 >> 1;
          iVar8 = 1;
          if (iVar10 != 0) {
            do {
              iVar10 = iVar10 >> 1;
              iVar8 = iVar8 + 1;
            } while (iVar10 != 0);
            if (10 < iVar8) {
              puVar2 = (undefined4 *)*param_1;
              puVar2[5] = 6;
              (*(code *)*puVar2)(param_1);
            }
          }
          iVar10 = (int)param_2 * 0x10 + iVar8;
          if (*(int *)(iVar3 + 0xc) == 0) {
            iVar6 = *(int *)(iVar3 + 0x4c + *(int *)(iVar3 + 0x34) * 4);
            FUN_00956eb0(*(undefined4 *)(iVar6 + iVar10 * 4),(int)*(char *)(iVar6 + 0x400 + iVar10))
            ;
          }
          else {
            piVar1 = (int *)(*(int *)(iVar3 + 0x5c + *(int *)(iVar3 + 0x34) * 4) + iVar10 * 4);
            *piVar1 = *piVar1 + 1;
          }
          FUN_00956eb0(local_c,iVar8);
          param_2 = (int *)0x0;
        }
      }
      local_10 = local_10 + 1;
    } while (local_10 <= iVar5);
    if ((0 < (int)param_2) &&
       (iVar7 = *(int *)(iVar3 + 0x38) + 1, *(int *)(iVar3 + 0x38) = iVar7, iVar7 == 0x7fff)) {
      FUN_00956fc0();
    }
  }
  puVar2 = (undefined4 *)param_1[6];
  iVar7 = param_1[0x32];
  *puVar2 = *(undefined4 *)(iVar3 + 0x10);
  puVar2[1] = *(undefined4 *)(iVar3 + 0x14);
  if (iVar7 != 0) {
    if (*(int *)(iVar3 + 0x44) == 0) {
      *(int *)(iVar3 + 0x44) = iVar7;
      *(uint *)(iVar3 + 0x48) = *(int *)(iVar3 + 0x48) + 1U & 7;
    }
    *(int *)(iVar3 + 0x44) = *(int *)(iVar3 + 0x44) + -1;
  }
  return 1;
}


// ==== FUN_009574c0 @ 0x009574c0 ====

undefined4 FUN_009574c0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  uVar1 = *(undefined4 *)(param_1 + 0x150);
  iVar2 = *(int *)(param_1 + 0x174);
  uVar3 = (*(undefined4 **)(param_1 + 0x18))[1];
  iVar5 = *(int *)(param_1 + 200);
  *(undefined4 *)(iVar2 + 0x10) = **(undefined4 **)(param_1 + 0x18);
  *(undefined4 *)(iVar2 + 0x14) = uVar3;
  if ((iVar5 != 0) && (*(int *)(iVar2 + 0x44) == 0)) {
    FUN_00957070(*(undefined4 *)(iVar2 + 0x48));
  }
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0x118)) {
    do {
      FUN_00956eb0((int)(**(short **)(param_2 + iVar5 * 4) >> ((byte)uVar1 & 0x1f)),1);
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(param_1 + 0x118));
  }
  puVar4 = *(undefined4 **)(param_1 + 0x18);
  iVar5 = *(int *)(param_1 + 200);
  uVar1 = *(undefined4 *)(iVar2 + 0x14);
  *puVar4 = *(undefined4 *)(iVar2 + 0x10);
  puVar4[1] = uVar1;
  if (iVar5 != 0) {
    if (*(int *)(iVar2 + 0x44) == 0) {
      *(int *)(iVar2 + 0x44) = iVar5;
      *(uint *)(iVar2 + 0x48) = *(int *)(iVar2 + 0x48) + 1U & 7;
    }
    *(int *)(iVar2 + 0x44) = *(int *)(iVar2 + 0x44) + -1;
  }
  return 1;
}


// ==== FUN_00957580 @ 0x00957580 ====

undefined4 FUN_00957580(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  int aiStack_118 [64];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = *(int *)(param_1 + 0x148);
  local_10 = *(undefined4 *)(param_1 + 0x150);
  uVar2 = **(undefined4 **)(param_1 + 0x18);
  iVar3 = *(int *)(param_1 + 0x174);
  *(undefined4 *)(iVar3 + 0x14) = (*(undefined4 **)(param_1 + 0x18))[1];
  iVar6 = *(int *)(param_1 + 200);
  *(undefined4 *)(iVar3 + 0x10) = uVar2;
  if ((iVar6 != 0) && (*(int *)(iVar3 + 0x44) == 0)) {
    FUN_00957070(*(undefined4 *)(iVar3 + 0x48));
  }
  iVar6 = *param_2;
  iVar8 = *(int *)(param_1 + 0x144);
  local_18 = iVar6;
  local_14 = 0;
  if (iVar8 <= local_c) {
    do {
      iVar5 = (int)*(short *)(iVar6 + (&DAT_00a28750)[iVar8] * 2);
      if (iVar5 < 0) {
        iVar5 = -iVar5;
      }
      iVar5 = iVar5 >> ((byte)local_10 & 0x1f);
      aiStack_118[iVar8] = iVar5;
      if (iVar5 == 1) {
        local_14 = iVar8;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 <= local_c);
  }
  pcVar9 = (char *)(*(int *)(iVar3 + 0x40) + *(int *)(iVar3 + 0x3c));
  local_8 = *(int *)(param_1 + 0x144);
  iVar6 = 0;
  param_2 = (int *)0x0;
  if (local_8 <= local_c) {
    do {
      local_10 = aiStack_118[local_8];
      if (aiStack_118[local_8] == 0) {
        iVar6 = iVar6 + 1;
      }
      else {
        if (0xf < iVar6) {
          do {
            if (local_14 < local_8) break;
            FUN_00956fc0();
            if (*(int *)(iVar3 + 0xc) == 0) {
              iVar8 = *(int *)(iVar3 + 0x4c + *(int *)(iVar3 + 0x34) * 4);
              FUN_00956eb0(*(undefined4 *)(iVar8 + 0x3c0),(int)*(char *)(iVar8 + 0x4f0));
            }
            else {
              piVar1 = (int *)(*(int *)(iVar3 + 0x5c + *(int *)(iVar3 + 0x34) * 4) + 0x3c0);
              *piVar1 = *piVar1 + 1;
            }
            iVar6 = iVar6 + -0x10;
            if ((*(int *)(iVar3 + 0xc) == 0) && (param_2 != (int *)0x0)) {
              do {
                FUN_00956eb0((int)*pcVar9,1);
                pcVar9 = pcVar9 + 1;
                param_2 = (int *)((int)param_2 + -1);
              } while (param_2 != (int *)0x0);
            }
            pcVar9 = *(char **)(iVar3 + 0x40);
            param_2 = (int *)0x0;
          } while (0xf < iVar6);
        }
        if (local_10 < 2) {
          FUN_00956fc0();
          iVar6 = iVar6 * 0x10 + 1;
          if (*(int *)(iVar3 + 0xc) == 0) {
            iVar8 = *(int *)(iVar3 + 0x4c + *(int *)(iVar3 + 0x34) * 4);
            FUN_00956eb0(*(undefined4 *)(iVar8 + iVar6 * 4),(int)*(char *)(iVar8 + 0x400 + iVar6));
          }
          else {
            iVar8 = *(int *)(iVar3 + 0x5c + *(int *)(iVar3 + 0x34) * 4);
            *(int *)(iVar8 + iVar6 * 4) = *(int *)(iVar8 + iVar6 * 4) + 1;
          }
          FUN_00956eb0(-1 < *(short *)(local_18 + (&DAT_00a28750)[local_8] * 2),1);
          if (*(int *)(iVar3 + 0xc) == 0) {
            for (; param_2 != (int *)0x0; param_2 = (int *)((int)param_2 + -1)) {
              FUN_00956eb0((int)*pcVar9,1);
              pcVar9 = pcVar9 + 1;
            }
          }
          pcVar9 = *(char **)(iVar3 + 0x40);
          iVar6 = 0;
          param_2 = (int *)0x0;
        }
        else {
          pcVar9[(int)param_2] = (byte)local_10 & 1;
          param_2 = (int *)((int)param_2 + 1);
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 <= local_c);
    if ((0 < iVar6) || (param_2 != (int *)0x0)) {
      iVar6 = *(int *)(iVar3 + 0x38) + 1;
      uVar7 = *(int *)(iVar3 + 0x3c) + (int)param_2;
      *(int *)(iVar3 + 0x38) = iVar6;
      *(uint *)(iVar3 + 0x3c) = uVar7;
      if ((iVar6 == 0x7fff) || (0x3a9 < uVar7)) {
        FUN_00956fc0();
      }
    }
  }
  puVar4 = *(undefined4 **)(param_1 + 0x18);
  iVar6 = *(int *)(param_1 + 200);
  *puVar4 = *(undefined4 *)(iVar3 + 0x10);
  puVar4[1] = *(undefined4 *)(iVar3 + 0x14);
  if (iVar6 != 0) {
    if (*(int *)(iVar3 + 0x44) == 0) {
      *(int *)(iVar3 + 0x44) = iVar6;
      *(uint *)(iVar3 + 0x48) = *(int *)(iVar3 + 0x48) + 1U & 7;
    }
    *(int *)(iVar3 + 0x44) = *(int *)(iVar3 + 0x44) + -1;
  }
  return 1;
}


// ==== FUN_00957800 @ 0x00957800 ====

void FUN_00957800(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(param_1 + 0x174);
  uVar2 = (*(undefined4 **)(param_1 + 0x18))[1];
  *(undefined4 *)(iVar1 + 0x10) = **(undefined4 **)(param_1 + 0x18);
  *(undefined4 *)(iVar1 + 0x14) = uVar2;
  FUN_00956fc0();
  FUN_00956eb0(0x7f,7);
  puVar3 = *(undefined4 **)(param_1 + 0x18);
  uVar2 = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *puVar3 = *(undefined4 *)(iVar1 + 0x10);
  puVar3[1] = uVar2;
  return;
}


// ==== FUN_00957850 @ 0x00957850 ====

void FUN_00957850(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int local_24 [5];
  int *local_10;
  int local_c;
  int local_8;
  
  iVar1 = (int)param_1;
  local_c = *(int *)((int)param_1 + 0x174);
  FUN_00956fc0();
  uVar3 = (uint)(*(int *)((int)param_1 + 0x144) == 0);
  local_24[0] = 0;
  local_24[1] = 0;
  local_24[2] = 0;
  local_24[3] = 0;
  local_8 = 0;
  local_24[4] = uVar3;
  if (0 < *(int *)((int)param_1 + 0xfc)) {
    param_1 = (int *)((int)param_1 + 0x100);
    do {
      if (uVar3 == 0) {
        iVar4 = *(int *)(*param_1 + 0x18);
LAB_009578bf:
        local_10 = local_24 + iVar4;
        if (local_24[iVar4] == 0) {
          piVar5 = (int *)(iVar1 + 0x58 + iVar4 * 4);
          if (uVar3 == 0) {
            piVar5 = (int *)(iVar1 + 0x68 + iVar4 * 4);
          }
          if (*piVar5 == 0) {
            iVar2 = FUN_0090b6c0(iVar1);
            *piVar5 = iVar2;
          }
          FUN_00956950(iVar1,*piVar5,*(undefined4 *)(local_c + 0x5c + iVar4 * 4));
          *local_10 = 1;
          uVar3 = local_24[4];
        }
      }
      else if (*(int *)(iVar1 + 0x14c) == 0) {
        iVar4 = *(int *)(*param_1 + 0x14);
        goto LAB_009578bf;
      }
      local_8 = local_8 + 1;
      param_1 = param_1 + 1;
    } while (local_8 < *(int *)(iVar1 + 0xfc));
  }
  return;
}


// ==== FUN_00957930 @ 0x00957930 ====

void FUN_00957930(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  bool bVar7;
  int local_10;
  undefined4 *local_8;
  
  piVar2 = param_1;
  iVar5 = param_1[0x53];
  bVar7 = param_1[0x51] == 0;
  iVar1 = param_1[0x5d];
  *(int **)(iVar1 + 0x20) = param_1;
  *(int *)(iVar1 + 0xc) = param_2;
  if (iVar5 == 0) {
    if (bVar7) {
      *(code **)(iVar1 + 4) = FUN_00957160;
    }
    else {
      *(code **)(iVar1 + 4) = FUN_009572d0;
    }
  }
  else if (bVar7) {
    *(code **)(iVar1 + 4) = FUN_009574c0;
  }
  else {
    *(code **)(iVar1 + 4) = FUN_00957580;
    if (*(int *)(iVar1 + 0x40) == 0) {
      uVar3 = (**(code **)param_1[1])(param_1,1,1000);
      *(undefined4 *)(iVar1 + 0x40) = uVar3;
    }
  }
  if (param_2 == 0) {
    *(code **)(iVar1 + 8) = FUN_00957800;
  }
  else {
    *(code **)(iVar1 + 8) = FUN_00957850;
  }
  local_10 = 0;
  if (0 < param_1[0x3f]) {
    local_8 = (undefined4 *)(iVar1 + 0x24);
    param_1 = param_1 + 0x40;
    do {
      iVar5 = *param_1;
      *local_8 = 0;
      if (bVar7) {
        if (piVar2[0x53] == 0) {
          iVar5 = *(int *)(iVar5 + 0x14);
          goto LAB_00957a05;
        }
      }
      else {
        iVar5 = *(int *)(iVar5 + 0x18);
        *(int *)(iVar1 + 0x34) = iVar5;
LAB_00957a05:
        if (param_2 == 0) {
          FUN_00956010(piVar2,bVar7,iVar5,iVar1 + 0x4c + iVar5 * 4);
        }
        else {
          if ((iVar5 < 0) || (3 < iVar5)) {
            puVar6 = (undefined4 *)*piVar2;
            puVar6[5] = 0x32;
            puVar6[6] = iVar5;
            (*(code *)*puVar6)(piVar2);
          }
          if (*(int *)(iVar1 + 0x5c + iVar5 * 4) == 0) {
            uVar3 = (**(code **)piVar2[1])(piVar2,1,0x404);
            *(undefined4 *)(iVar1 + 0x5c + iVar5 * 4) = uVar3;
          }
          puVar6 = *(undefined4 **)(iVar1 + 0x5c + iVar5 * 4);
          for (iVar4 = 0x101; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar6 = 0;
            puVar6 = puVar6 + 1;
          }
        }
      }
      param_1 = param_1 + 1;
      local_8 = local_8 + 1;
      local_10 = local_10 + 1;
    } while (local_10 < piVar2[0x3f]);
  }
  iVar5 = piVar2[0x32];
  *(undefined4 *)(iVar1 + 0x38) = 0;
  *(undefined4 *)(iVar1 + 0x3c) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(int *)(iVar1 + 0x44) = iVar5;
  *(undefined4 *)(iVar1 + 0x48) = 0;
  return;
}


// ==== FUN_00957ab0 @ 0x00957ab0 ====

void FUN_00957ab0(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x6c);
  *puVar1 = FUN_00957930;
  *(undefined4 **)(param_1 + 0x174) = puVar1;
  puVar1[0x13] = 0;
  puVar1[0x17] = 0;
  puVar1[0x14] = 0;
  puVar1[0x18] = 0;
  puVar1[0x15] = 0;
  puVar1[0x19] = 0;
  puVar1[0x16] = 0;
  puVar1[0x1a] = 0;
  puVar1[0x10] = 0;
  return;
}


// ==== FUN_00957b00 @ 0x00957b00 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00957b00(int *param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined2 *puVar8;
  ushort *puVar9;
  ushort *puVar10;
  float *pfVar11;
  int iVar12;
  double *pdVar13;
  double *pdVar14;
  short *psVar15;
  int local_10;
  int *local_c;
  
  iVar4 = param_1[0x5c];
  local_10 = 0;
  if (0 < param_1[0xf]) {
    local_c = (int *)(param_1[0x11] + 0x10);
    do {
      iVar6 = *local_c;
      if (((iVar6 < 0) || (3 < iVar6)) || (param_1[iVar6 + 0x12] == 0)) {
        puVar5 = (undefined4 *)*param_1;
        puVar5[5] = 0x34;
        puVar5[6] = iVar6;
        (*(code *)*puVar5)(param_1);
      }
      puVar9 = (ushort *)param_1[iVar6 + 0x12];
      switch(param_1[0x31]) {
      case 0:
      case 3:
      case 5:
        if (*(int *)(iVar4 + 0xc + iVar6 * 4) == 0) {
          uVar7 = (**(code **)param_1[1])(param_1,1,0x80);
          *(undefined4 *)(iVar4 + 0xc + iVar6 * 4) = uVar7;
        }
        psVar15 = *(short **)(iVar4 + 0xc + iVar6 * 4);
        iVar12 = (int)puVar9 - (int)psVar15;
        iVar6 = 0x40;
        do {
          *psVar15 = *(short *)(iVar12 + (int)psVar15) << 3;
          psVar15 = psVar15 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        break;
      case 1:
      case 4:
      case 6:
        if (*(int *)(iVar4 + 0xc + iVar6 * 4) == 0) {
          uVar7 = (**(code **)param_1[1])(param_1,1,0x80);
          *(undefined4 *)(iVar4 + 0xc + iVar6 * 4) = uVar7;
        }
        iVar6 = *(int *)(iVar4 + 0xc + iVar6 * 4);
        puVar10 = puVar9 + 3;
        psVar15 = &DAT_00a2e570;
        puVar8 = (undefined2 *)(iVar6 + 2);
        iVar12 = -iVar6;
        do {
          uVar1 = *(ushort *)((int)puVar8 + ((int)puVar9 - iVar6));
          puVar8[-1] = (short)((int)((uint)puVar10[-3] * (int)*psVar15 + 0x400) >> 0xb);
          uVar2 = puVar10[-1];
          *puVar8 = (short)((int)((int)*(short *)((int)&DAT_00a2e570 + iVar12 + (int)puVar8) *
                                  (uint)uVar1 + 0x400) >> 0xb);
          uVar1 = *puVar10;
          puVar8[1] = (short)((int)((int)*(short *)((int)&DAT_00a2e572 + iVar12 + (int)puVar8) *
                                    (uint)uVar2 + 0x400) >> 0xb);
          puVar8[2] = (short)((int)((int)*(short *)((int)&DAT_00a2e574 + iVar12 + (int)puVar8) *
                                    (uint)uVar1 + 0x400) >> 0xb);
          psVar15 = psVar15 + 4;
          puVar8 = puVar8 + 4;
          puVar10 = puVar10 + 4;
        } while ((int)psVar15 < 0xa2e5f0);
        break;
      case 2:
        if (*(int *)(iVar4 + 0x20 + iVar6 * 4) == 0) {
          uVar7 = (**(code **)param_1[1])(param_1,1,0x100);
          *(undefined4 *)(iVar4 + 0x20 + iVar6 * 4) = uVar7;
        }
        pfVar11 = *(float **)(iVar4 + 0x20 + iVar6 * 4);
        pdVar13 = (double *)&DAT_00a2e468;
        do {
          uVar1 = puVar9[1];
          uVar2 = puVar9[2];
          *pfVar11 = (float)_DAT_0099d0a0 /
                     ((float)*puVar9 * (float)*pdVar13 * (float)_DAT_00a24b70);
          uVar3 = puVar9[3];
          pfVar11[1] = (float)_DAT_0099d0a0 /
                       ((float)uVar1 * (float)*pdVar13 * (float)_DAT_00a2e568);
          uVar1 = puVar9[4];
          pfVar11[2] = (float)_DAT_0099d0a0 /
                       ((float)uVar2 * (float)*pdVar13 * (float)_DAT_00a2e560);
          uVar2 = puVar9[5];
          pfVar11[3] = (float)_DAT_0099d0a0 /
                       ((float)uVar3 * (float)*pdVar13 * (float)_DAT_00a2e558);
          uVar3 = puVar9[6];
          pfVar11[4] = (float)_DAT_0099d0a0 /
                       ((float)uVar1 * (float)*pdVar13 * (float)_DAT_00a24b70);
          pfVar11[5] = (float)_DAT_0099d0a0 /
                       ((float)uVar2 * (float)*pdVar13 * (float)_DAT_00a2e550);
          uVar1 = puVar9[7];
          pfVar11[6] = (float)_DAT_0099d0a0 /
                       ((float)uVar3 * (float)*pdVar13 * (float)_DAT_00a2e548);
          pdVar14 = pdVar13 + 1;
          puVar9 = puVar9 + 8;
          pfVar11[7] = (float)_DAT_0099d0a0 /
                       ((float)uVar1 * (float)*pdVar13 * (float)_DAT_00a2e540);
          pfVar11 = pfVar11 + 8;
          pdVar13 = pdVar14;
        } while ((int)pdVar14 < 0xa2e4a8);
        break;
      default:
        puVar5 = (undefined4 *)*param_1;
        puVar5[5] = 0x30;
        (*(code *)*puVar5)(param_1);
      }
      local_10 = local_10 + 1;
      local_c = local_c + 0x15;
    } while (local_10 < param_1[0xf]);
  }
  return;
}


// ==== FUN_00957e10 @ 0x00957e10 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00957e10(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  short *psVar4;
  byte *pbVar5;
  short *psVar6;
  int *piVar7;
  short sVar8;
  int iVar9;
  int local_94;
  int local_90;
  int local_8c;
  short local_88 [64];
  undefined4 local_8;
  
  pcVar2 = *(code **)(*(int *)(param_1 + 0x170) + 8);
  iVar3 = *(int *)(*(int *)(param_1 + 0x170) + 0xc + *(int *)(param_2 + 0x10) * 4);
  local_8 = DAT_00b49670;
  if (param_7 != 0) {
    local_8c = (int)local_88 - param_4;
    psVar6 = (short *)(param_4 + 2);
    local_90 = param_7;
    do {
      psVar4 = local_88;
      iVar9 = 2;
      piVar7 = (int *)(param_3 + 8 + param_5 * 4);
      do {
        pbVar5 = (byte *)(piVar7[-2] + param_6);
        *psVar4 = *pbVar5 - 0x80;
        psVar4[1] = pbVar5[1] - 0x80;
        psVar4[2] = pbVar5[2] - 0x80;
        psVar4[3] = pbVar5[3] - 0x80;
        psVar4[4] = pbVar5[4] - 0x80;
        psVar4[5] = pbVar5[5] - 0x80;
        psVar4[6] = pbVar5[6] - 0x80;
        psVar4[7] = pbVar5[7] - 0x80;
        pbVar5 = (byte *)(piVar7[-1] + param_6);
        psVar4[8] = *pbVar5 - 0x80;
        psVar4[9] = pbVar5[1] - 0x80;
        psVar4[10] = pbVar5[2] - 0x80;
        psVar4[0xb] = pbVar5[3] - 0x80;
        psVar4[0xc] = pbVar5[4] - 0x80;
        psVar4[0xd] = pbVar5[5] - 0x80;
        psVar4[0xe] = pbVar5[6] - 0x80;
        psVar4[0xf] = pbVar5[7] - 0x80;
        pbVar5 = (byte *)(*piVar7 + param_6);
        psVar4[0x10] = *pbVar5 - 0x80;
        psVar4[0x11] = pbVar5[1] - 0x80;
        psVar4[0x12] = pbVar5[2] - 0x80;
        psVar4[0x13] = pbVar5[3] - 0x80;
        psVar4[0x14] = pbVar5[4] - 0x80;
        psVar4[0x15] = pbVar5[5] - 0x80;
        psVar4[0x16] = pbVar5[6] - 0x80;
        psVar4[0x17] = pbVar5[7] - 0x80;
        pbVar5 = (byte *)(piVar7[1] + param_6);
        psVar4[0x18] = *pbVar5 - 0x80;
        psVar4[0x19] = pbVar5[1] - 0x80;
        psVar4[0x1a] = pbVar5[2] - 0x80;
        psVar4[0x1b] = pbVar5[3] - 0x80;
        psVar4[0x1c] = pbVar5[4] - 0x80;
        psVar4[0x1d] = pbVar5[5] - 0x80;
        psVar4[0x1e] = pbVar5[6] - 0x80;
        psVar4[0x1f] = pbVar5[7] - 0x80;
        psVar4 = psVar4 + 0x20;
        piVar7 = piVar7 + 4;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      (*pcVar2)(local_88);
      local_94 = 0;
      psVar4 = (short *)(iVar3 + 6);
      do {
        sVar1 = psVar4[-3];
        sVar8 = local_88[local_94];
        if (sVar8 < 0) {
          sVar8 = (sVar1 >> 1) - sVar8;
          if (sVar8 < sVar1) {
            sVar8 = 0;
          }
          else {
            sVar8 = -(sVar8 / sVar1);
          }
        }
        else {
          sVar8 = sVar8 + (sVar1 >> 1);
          if (sVar8 < sVar1) {
            sVar8 = 0;
          }
          else {
            sVar8 = sVar8 / sVar1;
          }
        }
        psVar6[-1] = sVar8;
        sVar1 = *(short *)((iVar3 - (int)local_88) + local_8c + (int)psVar6);
        sVar8 = *(short *)(local_8c + (int)psVar6);
        if (sVar8 < 0) {
          sVar8 = (sVar1 >> 1) - sVar8;
          if (sVar8 < sVar1) {
            sVar8 = 0;
          }
          else {
            sVar8 = -(sVar8 / sVar1);
          }
        }
        else {
          sVar8 = sVar8 + (sVar1 >> 1);
          if (sVar8 < sVar1) {
            sVar8 = 0;
          }
          else {
            sVar8 = sVar8 / sVar1;
          }
        }
        sVar1 = psVar4[-1];
        *psVar6 = sVar8;
        sVar8 = *(short *)(local_8c + 2 + (int)psVar6);
        if (sVar8 < 0) {
          sVar8 = (sVar1 >> 1) - sVar8;
          if (sVar8 < sVar1) {
            sVar8 = 0;
          }
          else {
            sVar8 = -(sVar8 / sVar1);
          }
        }
        else {
          sVar8 = sVar8 + (sVar1 >> 1);
          if (sVar8 < sVar1) {
            sVar8 = 0;
          }
          else {
            sVar8 = sVar8 / sVar1;
          }
        }
        sVar1 = *psVar4;
        psVar6[1] = sVar8;
        sVar8 = *(short *)(local_8c + 4 + (int)psVar6);
        if (sVar8 < 0) {
          sVar8 = (sVar1 >> 1) - sVar8;
          if (sVar8 < sVar1) {
            sVar8 = 0;
          }
          else {
            sVar8 = -(sVar8 / sVar1);
          }
        }
        else {
          sVar8 = sVar8 + (sVar1 >> 1);
          if (sVar8 < sVar1) {
            sVar8 = 0;
          }
          else {
            sVar8 = sVar8 / sVar1;
          }
        }
        psVar6[2] = sVar8;
        local_94 = local_94 + 4;
        psVar6 = psVar6 + 4;
        psVar4 = psVar4 + 4;
      } while (local_94 < 0x40);
      local_8c = local_8c + -0x80;
      param_6 = param_6 + 8;
      local_90 = local_90 + -1;
    } while (local_90 != 0);
  }
  return;
}


// ==== FUN_009582e0 @ 0x009582e0 ====

void FUN_009582e0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  short sVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
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
  code *local_c;
  undefined4 local_8;
  
  local_c = *(code **)(*(int *)(param_1 + 0x170) + 0x1c);
  local_8 = *(undefined4 *)(*(int *)(param_1 + 0x170) + 0x20 + *(int *)(param_2 + 0x10) * 4);
  if (param_7 != 0) {
    param_1 = param_4;
    param_2 = param_7;
    do {
      iVar5 = *(int *)(param_3 + param_5 * 4);
      iVar2 = iVar5 + param_6;
      local_10c = (float)(int)(*(byte *)(iVar5 + param_6) - 0x80);
      local_108 = (float)(int)(*(byte *)(iVar2 + 1) - 0x80);
      local_104 = (float)(int)(*(byte *)(iVar2 + 2) - 0x80);
      local_100 = (float)(int)(*(byte *)(iVar2 + 3) - 0x80);
      local_fc = (float)(int)(*(byte *)(iVar2 + 4) - 0x80);
      local_f8 = (float)(int)(*(byte *)(iVar2 + 5) - 0x80);
      local_f4 = (float)(int)(*(byte *)(iVar2 + 6) - 0x80);
      pbVar3 = (byte *)(*(int *)(param_3 + 4 + param_5 * 4) + param_6);
      local_f0 = (float)(int)(*(byte *)(iVar2 + 7) - 0x80);
      local_ec = (float)(int)(*pbVar3 - 0x80);
      local_e8 = (float)(int)(pbVar3[1] - 0x80);
      local_e4 = (float)(int)(pbVar3[2] - 0x80);
      local_e0 = (float)(int)(pbVar3[3] - 0x80);
      local_dc = (float)(int)(pbVar3[4] - 0x80);
      local_d8 = (float)(int)(pbVar3[5] - 0x80);
      local_d4 = (float)(int)(pbVar3[6] - 0x80);
      pbVar4 = (byte *)(*(int *)(param_3 + 8 + param_5 * 4) + param_6);
      local_d0 = (float)(int)(pbVar3[7] - 0x80);
      local_cc = (float)(int)(*pbVar4 - 0x80);
      local_c8 = (float)(int)(pbVar4[1] - 0x80);
      local_c4 = (float)(int)(pbVar4[2] - 0x80);
      local_c0 = (float)(int)(pbVar4[3] - 0x80);
      local_bc = (float)(int)(pbVar4[4] - 0x80);
      local_b8 = (float)(int)(pbVar4[5] - 0x80);
      local_b4 = (float)(int)(pbVar4[6] - 0x80);
      pbVar3 = (byte *)(*(int *)(param_3 + 0xc + param_5 * 4) + param_6);
      local_b0 = (float)(int)(pbVar4[7] - 0x80);
      local_ac = (float)(int)(*pbVar3 - 0x80);
      local_a8 = (float)(int)(pbVar3[1] - 0x80);
      local_a4 = (float)(int)(pbVar3[2] - 0x80);
      local_a0 = (float)(int)(pbVar3[3] - 0x80);
      local_9c = (float)(int)(pbVar3[4] - 0x80);
      local_98 = (float)(int)(pbVar3[5] - 0x80);
      local_94 = (float)(int)(pbVar3[6] - 0x80);
      pbVar4 = (byte *)(*(int *)(param_3 + 0x10 + param_5 * 4) + param_6);
      local_90 = (float)(int)(pbVar3[7] - 0x80);
      local_8c = (float)(int)(*pbVar4 - 0x80);
      local_88 = (float)(int)(pbVar4[1] - 0x80);
      local_84 = (float)(int)(pbVar4[2] - 0x80);
      local_80 = (float)(int)(pbVar4[3] - 0x80);
      local_7c = (float)(int)(pbVar4[4] - 0x80);
      local_78 = (float)(int)(pbVar4[5] - 0x80);
      local_74 = (float)(int)(pbVar4[6] - 0x80);
      pbVar3 = (byte *)(*(int *)(param_3 + 0x14 + param_5 * 4) + param_6);
      local_70 = (float)(int)(pbVar4[7] - 0x80);
      local_6c = (float)(int)(*pbVar3 - 0x80);
      local_68 = (float)(int)(pbVar3[1] - 0x80);
      local_64 = (float)(int)(pbVar3[2] - 0x80);
      local_60 = (float)(int)(pbVar3[3] - 0x80);
      local_5c = (float)(int)(pbVar3[4] - 0x80);
      local_58 = (float)(int)(pbVar3[5] - 0x80);
      local_54 = (float)(int)(pbVar3[6] - 0x80);
      pbVar4 = (byte *)(*(int *)(param_3 + 0x18 + param_5 * 4) + param_6);
      local_50 = (float)(int)(pbVar3[7] - 0x80);
      local_4c = (float)(int)(*pbVar4 - 0x80);
      local_48 = (float)(int)(pbVar4[1] - 0x80);
      local_44 = (float)(int)(pbVar4[2] - 0x80);
      local_40 = (float)(int)(pbVar4[3] - 0x80);
      local_3c = (float)(int)(pbVar4[4] - 0x80);
      local_38 = (float)(int)(pbVar4[5] - 0x80);
      local_34 = (float)(int)(pbVar4[6] - 0x80);
      pbVar3 = (byte *)(*(int *)(param_3 + 0x1c + param_5 * 4) + param_6);
      local_30 = (float)(int)(pbVar4[7] - 0x80);
      local_2c = (float)(int)(*pbVar3 - 0x80);
      local_28 = (float)(int)(pbVar3[1] - 0x80);
      local_24 = (float)(int)(pbVar3[2] - 0x80);
      local_20 = (float)(int)(pbVar3[3] - 0x80);
      local_1c = (float)(int)(pbVar3[4] - 0x80);
      local_18 = (float)(int)(pbVar3[5] - 0x80);
      local_14 = (float)(int)(pbVar3[6] - 0x80);
      local_10 = (float)(int)(pbVar3[7] - 0x80);
      (*local_c)(&local_10c);
      iVar5 = 0;
      do {
        sVar1 = __ftol();
        *(short *)(param_1 + iVar5 * 2) = sVar1 + -0x4000;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0x40);
      param_1 = param_1 + 0x80;
      param_6 = param_6 + 8;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_009588d0 @ 0x009588d0 ====

void FUN_009588d0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x30);
  iVar1 = param_1[0x31];
  param_1[0x5c] = (int)puVar3;
  *puVar3 = FUN_00957b00;
  switch(iVar1) {
  case 0:
  case 3:
  case 5:
    puVar3[1] = FUN_00957e10;
    puVar3[2] = FUN_00961130;
    break;
  case 1:
  case 4:
  case 6:
    puVar3[1] = FUN_00957e10;
    puVar3[2] = FUN_00960ee0;
    break;
  case 2:
    puVar3[1] = FUN_009582e0;
    puVar3[7] = FUN_0095fe90;
    break;
  default:
    puVar2 = (undefined4 *)*param_1;
    puVar2[5] = 0x30;
    (*(code *)*puVar2)(param_1);
  }
  puVar3[3] = 0;
  puVar3[8] = 0;
  puVar3[4] = 0;
  puVar3[9] = 0;
  puVar3[5] = 0;
  puVar3[10] = 0;
  puVar3[6] = 0;
  puVar3[0xb] = 0;
  return;
}


// ==== FUN_00958980 @ 0x00958980 ====

void FUN_00958980(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = param_1[0x57];
  if (param_2 != 0) {
    puVar2 = (undefined4 *)*param_1;
    puVar2[5] = 4;
    (*(code *)*puVar2)(param_1);
  }
  iVar3 = param_1[0x3d];
  *(int *)(iVar1 + 0x30) = param_1[8];
  *(undefined4 *)(iVar1 + 0x34) = 0;
  *(undefined4 *)(iVar1 + 0x38) = 0;
  *(int *)(iVar1 + 0x3c) = iVar3 << 1;
  return;
}


// ==== FUN_009589d0 @ 0x009589d0 ====

void FUN_009589d0(int *param_1,int param_2,uint *param_3,uint param_4,int param_5,uint *param_6,
                 uint param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 *local_c;
  int local_8;
  
  iVar4 = (int)param_1;
  iVar1 = *(int *)((int)param_1 + 0x15c);
  if (*param_3 < param_4) {
    while (*param_6 < param_7) {
      uVar5 = param_4 - *param_3;
      uVar9 = *(int *)((int)param_1 + 0xf4) - *(int *)(iVar1 + 0x34);
      if (uVar5 <= uVar9) {
        uVar9 = uVar5;
      }
      (**(code **)(*(int *)((int)param_1 + 0x168) + 4))
                (param_1,param_2 + *param_3 * 4,iVar1 + 8,*(undefined4 *)(iVar1 + 0x34),uVar9);
      iVar8 = *(int *)(iVar1 + 0x34);
      *param_3 = *param_3 + uVar9;
      iVar8 = iVar8 + uVar9;
      iVar7 = *(int *)(iVar1 + 0x30) - uVar9;
      *(int *)(iVar1 + 0x34) = iVar8;
      *(int *)(iVar1 + 0x30) = iVar7;
      if ((iVar7 == 0) && (iVar8 < *(int *)((int)param_1 + 0xf4))) {
        local_8 = 0;
        if (0 < *(int *)((int)param_1 + 0x3c)) {
          local_c = (undefined4 *)(iVar1 + 8);
          do {
            iVar8 = *(int *)((int)param_1 + 0xf4);
            iVar7 = *(int *)(iVar1 + 0x34);
            uVar2 = *(undefined4 *)((int)param_1 + 0x1c);
            uVar3 = *local_c;
            if (iVar7 < iVar8) {
              iVar6 = iVar7 + -1;
              do {
                FUN_0090b730(uVar3,iVar6,uVar3,iVar7,1,uVar2);
                iVar7 = iVar7 + 1;
              } while (iVar7 < iVar8);
            }
            local_c = local_c + 1;
            local_8 = local_8 + 1;
          } while (local_8 < *(int *)((int)param_1 + 0x3c));
        }
        *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)((int)param_1 + 0xf4);
      }
      if (*(int *)(iVar1 + 0x34) == *(int *)((int)param_1 + 0xf4)) {
        (**(code **)(*(int *)((int)param_1 + 0x16c) + 4))(param_1,iVar1 + 8,0,param_5,*param_6);
        uVar9 = *param_6;
        *(undefined4 *)(iVar1 + 0x34) = 0;
        *param_6 = uVar9 + 1;
      }
      if ((*(int *)(iVar1 + 0x30) == 0) && (*param_6 < param_7)) {
        local_8 = 0;
        if (0 < *(int *)((int)param_1 + 0x3c)) {
          param_1 = (int *)(*(int *)((int)param_1 + 0x44) + 0xc);
          do {
            iVar8 = *param_6 * *param_1;
            iVar7 = *param_1 * param_7;
            iVar1 = param_1[4];
            uVar2 = *(undefined4 *)(param_5 + local_8 * 4);
            if (iVar8 < iVar7) {
              iVar6 = iVar8 + -1;
              do {
                FUN_0090b730(uVar2,iVar6,uVar2,iVar8,1,iVar1 << 3);
                iVar8 = iVar8 + 1;
              } while (iVar8 < iVar7);
            }
            local_8 = local_8 + 1;
            param_1 = param_1 + 0x15;
          } while (local_8 < *(int *)(iVar4 + 0x3c));
        }
        *param_6 = param_7;
        return;
      }
      if (param_4 <= *param_3) {
        return;
      }
    }
  }
  return;
}


// ==== FUN_00958bb0 @ 0x00958bb0 ====

void FUN_00958bb0(int param_1,int param_2,uint *param_3,uint param_4,undefined4 param_5,
                 uint *param_6,uint param_7)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *local_10;
  undefined4 *local_c;
  int local_8;
  
  iVar7 = param_1;
  uVar2 = *param_6;
  iVar3 = *(int *)(param_1 + 0x15c);
  iVar6 = *(int *)(param_1 + 0xf4) * 3;
  do {
    if (param_7 <= uVar2) {
      return;
    }
    uVar2 = *param_3;
    if (uVar2 < param_4) {
      local_10 = (undefined4 *)(*(int *)(iVar3 + 0x3c) - *(int *)(iVar3 + 0x34));
      if (param_4 - uVar2 <= local_10) {
        local_10 = (undefined4 *)(param_4 - uVar2);
      }
      (**(code **)(*(int *)(iVar7 + 0x168) + 4))
                (iVar7,param_2 + uVar2 * 4,iVar3 + 8,*(int *)(iVar3 + 0x34),local_10);
      if ((*(int *)(iVar3 + 0x30) == *(int *)(iVar7 + 0x20)) &&
         (param_1 = 0, 0 < *(int *)(iVar7 + 0x3c))) {
        iVar9 = *(int *)(iVar7 + 0xf4);
        local_c = (undefined4 *)(iVar3 + 8);
        do {
          iVar8 = 1;
          if (0 < iVar9) {
            local_8 = -1;
            do {
              FUN_0090b730(*local_c,0,*local_c,local_8,1,*(undefined4 *)(iVar7 + 0x1c));
              iVar9 = *(int *)(iVar7 + 0xf4);
              iVar8 = iVar8 + 1;
              local_8 = local_8 + -1;
            } while (iVar8 <= iVar9);
          }
          param_1 = param_1 + 1;
          local_c = local_c + 1;
        } while (param_1 < *(int *)(iVar7 + 0x3c));
      }
      iVar9 = *(int *)(iVar3 + 0x34);
      *param_3 = *param_3 + (int)local_10;
      *(int *)(iVar3 + 0x34) = iVar9 + (int)local_10;
      *(int *)(iVar3 + 0x30) = *(int *)(iVar3 + 0x30) - (int)local_10;
    }
    else {
      if (*(int *)(iVar3 + 0x30) != 0) {
        return;
      }
      if (*(int *)(iVar3 + 0x34) < *(int *)(iVar3 + 0x3c)) {
        param_1 = 0;
        if (0 < *(int *)(iVar7 + 0x3c)) {
          local_10 = (undefined4 *)(iVar3 + 8);
          do {
            iVar9 = *(int *)(iVar3 + 0x3c);
            iVar8 = *(int *)(iVar3 + 0x34);
            uVar4 = *(undefined4 *)(iVar7 + 0x1c);
            uVar5 = *local_10;
            if (iVar8 < iVar9) {
              iVar1 = iVar8 + -1;
              do {
                FUN_0090b730(uVar5,iVar1,uVar5,iVar8,1,uVar4);
                iVar8 = iVar8 + 1;
              } while (iVar8 < iVar9);
            }
            param_1 = param_1 + 1;
            local_10 = local_10 + 1;
          } while (param_1 < *(int *)(iVar7 + 0x3c));
        }
        *(undefined4 *)(iVar3 + 0x34) = *(undefined4 *)(iVar3 + 0x3c);
      }
    }
    if (*(int *)(iVar3 + 0x34) == *(int *)(iVar3 + 0x3c)) {
      (**(code **)(*(int *)(iVar7 + 0x16c) + 4))
                (iVar7,iVar3 + 8,*(undefined4 *)(iVar3 + 0x38),param_5,*param_6);
      iVar9 = *(int *)(iVar3 + 0x38);
      *param_6 = *param_6 + 1;
      iVar8 = *(int *)(iVar7 + 0xf4);
      iVar9 = iVar9 + iVar8;
      *(int *)(iVar3 + 0x38) = iVar9;
      if (iVar6 <= iVar9) {
        *(undefined4 *)(iVar3 + 0x38) = 0;
      }
      if (iVar6 <= *(int *)(iVar3 + 0x34)) {
        *(undefined4 *)(iVar3 + 0x34) = 0;
      }
      *(int *)(iVar3 + 0x3c) = *(int *)(iVar3 + 0x34) + iVar8;
    }
    uVar2 = *param_6;
  } while( true );
}


// ==== FUN_00958dc0 @ 0x00958dc0 ====

void FUN_00958dc0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *local_1c;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 *local_c;
  int local_8;
  
  iVar1 = *(int *)(param_1 + 0xf4);
  iVar4 = *(int *)(param_1 + 0x15c);
  local_8 = (*(code *)**(undefined4 **)(param_1 + 4))
                      (param_1,1,*(int *)(param_1 + 0x3c) * iVar1 * 0x14);
  local_18 = 0;
  if (0 < *(int *)(param_1 + 0x3c)) {
    local_10 = (int *)(*(int *)(param_1 + 0x44) + 8);
    local_c = (undefined4 *)(local_8 + iVar1 * 4);
    local_1c = (undefined4 *)(iVar4 + 8);
    do {
      puVar2 = (undefined4 *)
               (**(code **)(*(int *)(param_1 + 4) + 8))
                         (param_1,1,(local_10[5] * *(int *)(param_1 + 0xf0) * 8) / *local_10,
                          iVar1 * 3);
      puVar6 = puVar2;
      puVar5 = local_c;
      for (uVar3 = (uint)(iVar1 * 0xc) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar5 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar5 = puVar5 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar5 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
      if (0 < iVar1) {
        puVar5 = (undefined4 *)(iVar1 * 0x10 + local_8);
        puVar6 = puVar2 + iVar1 * 2;
        iVar4 = local_8 - (int)puVar2;
        local_14 = iVar1;
        do {
          *(undefined4 *)(iVar4 + (int)puVar2) = *puVar6;
          *puVar5 = *puVar2;
          puVar6 = puVar6 + 1;
          puVar2 = puVar2 + 1;
          puVar5 = puVar5 + 1;
          local_14 = local_14 + -1;
        } while (local_14 != 0);
      }
      *local_1c = local_c;
      local_c = local_c + iVar1 * 5;
      local_1c = local_1c + 1;
      local_8 = local_8 + iVar1 * 0x14;
      local_18 = local_18 + 1;
      local_10 = local_10 + 0x15;
    } while (local_18 < *(int *)(param_1 + 0x3c));
  }
  return;
}


// ==== FUN_00958ee0 @ 0x00958ee0 ====

void FUN_00958ee0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  
  if (param_2 != 0) {
    puVar3 = (undefined4 *)*param_1;
    puVar3[5] = 4;
    (*(code *)*puVar3)(param_1);
  }
  puVar3 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x40);
  iVar1 = *(int *)(param_1[0x5b] + 8);
  param_1[0x57] = (int)puVar3;
  *puVar3 = FUN_00958980;
  if (iVar1 != 0) {
    puVar3[1] = FUN_00958bb0;
    FUN_00958dc0(param_1);
    return;
  }
  iVar1 = param_1[0xf];
  iVar2 = param_1[0x11];
  puVar3[1] = FUN_009589d0;
  param_2 = 0;
  if (0 < iVar1) {
    piVar5 = (int *)(iVar2 + 8);
    puVar3 = puVar3 + 2;
    do {
      uVar4 = (**(code **)(param_1[1] + 8))
                        (param_1,1,(piVar5[5] * param_1[0x3c] * 8) / *piVar5,param_1[0x3d]);
      iVar1 = param_1[0xf];
      *puVar3 = uVar4;
      param_2 = param_2 + 1;
      puVar3 = puVar3 + 1;
      piVar5 = piVar5 + 0x15;
    } while (param_2 < iVar1);
  }
  return;
}


// ==== FUN_00958fa0 @ 0x00958fa0 ====

void FUN_00958fa0(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  int in_ECX;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  uVar2 = in_ECX - param_3;
  if ((0 < (int)uVar2) && (iVar4 = 0, 0 < param_2)) {
    do {
      puVar5 = (undefined4 *)(*(int *)(param_1 + iVar4 * 4) + param_3);
      uVar1 = *(undefined1 *)((int)puVar5 + -1);
      for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar5 = CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,uVar1));
        puVar5 = puVar5 + 1;
      }
      for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar5 = uVar1;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_2);
  }
  return;
}


// ==== FUN_00959000 @ 0x00959000 ====

void FUN_00959000(undefined4 *param_1,int *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  iVar1 = (int)param_1;
  iVar2 = *(int *)((int)param_1 + 0x44);
  local_8 = 0;
  if (0 < *(int *)((int)param_1 + 0x3c)) {
    param_1 = (undefined4 *)(*(int *)((int)param_1 + 0x16c) + 0xc);
    param_4 = param_4 - (int)param_2;
    do {
      (*(code *)*param_1)(iVar1,iVar2,*param_2 + param_3 * 4,
                          *(int *)(param_4 + (int)param_2) + *(int *)(iVar2 + 0xc) * param_5 * 4);
      param_1 = param_1 + 1;
      local_8 = local_8 + 1;
      param_2 = param_2 + 1;
      iVar2 = iVar2 + 0x54;
    } while (local_8 < *(int *)(iVar1 + 0x3c));
  }
  return;
}


// ==== FUN_009590a0 @ 0x009590a0 ====

void FUN_009590a0(int *param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int local_18;
  int local_10;
  undefined1 *local_c;
  
  iVar2 = *(int *)(param_2 + 0x1c) << 3;
  iVar3 = *(int *)((int)param_1 + 0xf0) / *(int *)(param_2 + 8);
  iVar4 = *(int *)((int)param_1 + 0xf4) / *(int *)(param_2 + 0xc);
  FUN_00958fa0(param_3,*(int *)((int)param_1 + 0xf4),*(undefined4 *)((int)param_1 + 0x1c));
  iVar1 = *(int *)(param_2 + 0xc);
  local_18 = 0;
  if (0 < iVar1) {
    param_1 = param_3;
    do {
      param_2 = 0;
      if (iVar2 != 0) {
        local_10 = iVar2;
        local_c = *(undefined1 **)(param_4 + local_18 * 4);
        do {
          iVar8 = 0;
          if (0 < iVar4) {
            piVar7 = param_1;
            param_3 = (int *)iVar4;
            do {
              pbVar5 = (byte *)(*piVar7 + param_2);
              if (0 < iVar3) {
                iVar6 = iVar3;
                do {
                  iVar8 = iVar8 + (uint)*pbVar5;
                  pbVar5 = pbVar5 + 1;
                  iVar6 = iVar6 + -1;
                } while (iVar6 != 0);
              }
              piVar7 = piVar7 + 1;
              param_3 = (int *)((int)param_3 + -1);
            } while (param_3 != (int *)0x0);
          }
          *local_c = (char)(((iVar4 * iVar3) / 2 + iVar8) / (iVar4 * iVar3));
          param_2 = param_2 + iVar3;
          local_10 = local_10 + -1;
          local_c = local_c + 1;
        } while (local_10 != 0);
      }
      param_1 = param_1 + iVar4;
      local_18 = local_18 + 1;
    } while (local_18 < iVar1);
  }
  return;
}


// ==== FUN_009591c0 @ 0x009591c0 ====

void FUN_009591c0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0090b730(param_3,0,param_4,0,*(undefined4 *)(param_1 + 0xf4),*(undefined4 *)(param_1 + 0x1c));
  FUN_00958fa0(param_4,*(undefined4 *)(param_1 + 0xf4),*(undefined4 *)(param_1 + 0x1c));
  return;
}


// ==== FUN_00959210 @ 0x00959210 ====

void FUN_00959210(int param_1)

{
  int in_EAX;
  byte *pbVar1;
  undefined4 *in_ECX;
  undefined1 *puVar2;
  int in_EDX;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *local_8;
  
  iVar5 = *(int *)(in_EDX + 0x1c) << 3;
  FUN_00958fa0(in_ECX,*(undefined4 *)(in_EAX + 0xf4),*(undefined4 *)(in_EAX + 0x1c));
  if (0 < *(int *)(in_EDX + 0xc)) {
    iVar3 = param_1 - (int)in_ECX;
    param_1 = *(int *)(in_EDX + 0xc);
    local_8 = in_ECX;
    do {
      puVar2 = *(undefined1 **)(iVar3 + (int)local_8);
      pbVar1 = (byte *)*local_8;
      uVar4 = 0;
      if (iVar5 != 0) {
        iVar6 = iVar5;
        do {
          *puVar2 = (char)((int)((uint)*pbVar1 + pbVar1[1] + uVar4) >> 1);
          puVar2 = puVar2 + 1;
          uVar4 = uVar4 ^ 1;
          pbVar1 = pbVar1 + 2;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      local_8 = local_8 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}


// ==== FUN_009592a0 @ 0x009592a0 ====

void FUN_009592a0(int param_1,int param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  int iVar7;
  int in_ECX;
  int in_EDX;
  int iVar8;
  undefined8 *puVar9;
  ulonglong *puVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  ushort uVar14;
  ushort uVar15;
  ushort uVar16;
  ushort uVar17;
  ulonglong uVar18;
  ushort uVar19;
  ushort uVar20;
  ushort uVar21;
  ushort uVar22;
  ulonglong uVar23;
  
  iVar3 = *(int *)(in_ECX + 0x1c);
  iVar4 = *(int *)(in_ECX + 0xc);
  FUN_00958fa0(param_1,*(undefined4 *)(in_EDX + 0xf4),*(undefined4 *)(in_EDX + 0x1c));
  uVar6 = DAT_00a2e608;
  iVar7 = 0;
  do {
    uVar5 = DAT_00a2e5f8;
    puVar9 = *(undefined8 **)(param_2 + iVar7 * 4);
    puVar10 = *(ulonglong **)(param_1 + iVar7 * 4);
    iVar8 = iVar3 << 3;
    do {
      uVar1 = *puVar10;
      uVar2 = puVar10[1];
      uVar18 = uVar1 & uVar6;
      uVar23 = uVar2 & uVar6;
      sVar11 = (short)((ulonglong)uVar5 >> 0x10);
      sVar12 = (short)((ulonglong)uVar5 >> 0x20);
      sVar13 = (short)((ulonglong)uVar5 >> 0x30);
      uVar14 = (ushort)(((ushort)uVar1 >> 8) + (short)uVar18 + (short)uVar5) >> 1;
      uVar15 = (ushort)(((ushort)(uVar1 >> 0x10) >> 8) + (short)(uVar18 >> 0x10) + sVar11) >> 1;
      uVar16 = (ushort)(((ushort)(uVar1 >> 0x20) >> 8) + (short)(uVar18 >> 0x20) + sVar12) >> 1;
      uVar17 = (ushort)((ushort)(uVar1 >> 0x38) + (short)(uVar18 >> 0x30) + sVar13) >> 1;
      uVar19 = (ushort)(((ushort)uVar2 >> 8) + (short)uVar23 + (short)uVar5) >> 1;
      uVar20 = (ushort)(((ushort)(uVar2 >> 0x10) >> 8) + (short)(uVar23 >> 0x10) + sVar11) >> 1;
      uVar21 = (ushort)(((ushort)(uVar2 >> 0x20) >> 8) + (short)(uVar23 >> 0x20) + sVar12) >> 1;
      uVar22 = (ushort)((ushort)(uVar2 >> 0x38) + (short)(uVar23 >> 0x30) + sVar13) >> 1;
      iVar8 = iVar8 + -8;
      puVar10 = puVar10 + 2;
      *puVar9 = CONCAT17((uVar22 != 0) * (uVar22 < 0x100) * (char)uVar22 - (0xff < uVar22),
                         CONCAT16((uVar21 != 0) * (uVar21 < 0x100) * (char)uVar21 - (0xff < uVar21),
                                  CONCAT15((uVar20 != 0) * (uVar20 < 0x100) * (char)uVar20 -
                                           (0xff < uVar20),
                                           CONCAT14((uVar19 != 0) * (uVar19 < 0x100) * (char)uVar19
                                                    - (0xff < uVar19),
                                                    CONCAT13((uVar17 != 0) * (uVar17 < 0x100) *
                                                             (char)uVar17 - (0xff < uVar17),
                                                             CONCAT12((uVar16 != 0) *
                                                                      (uVar16 < 0x100) *
                                                                      (char)uVar16 - (0xff < uVar16)
                                                                      ,CONCAT11((uVar15 != 0) *
                                                                                (uVar15 < 0x100) *
                                                                                (char)uVar15 -
                                                                                (0xff < uVar15),
                                                                                (uVar14 != 0) *
                                                                                (uVar14 < 0x100) *
                                                                                (char)uVar14 -
                                                                                (0xff < uVar14))))))
                                 ));
      puVar9 = puVar9 + 1;
    } while (7 < iVar8);
    iVar7 = iVar7 + 1;
  } while (iVar7 < iVar4);
  return;
}


// ==== FUN_00959350 @ 0x00959350 ====

void FUN_00959350(int param_1)

{
  int iVar1;
  int in_EAX;
  byte *pbVar2;
  undefined4 *in_ECX;
  int iVar3;
  int in_EDX;
  undefined1 *puVar4;
  int iVar5;
  int local_14;
  undefined4 *local_10;
  int local_c;
  uint local_8;
  
  iVar5 = *(int *)(in_EDX + 0x1c) << 3;
  FUN_00958fa0(in_ECX,*(undefined4 *)(in_EAX + 0xf4),*(undefined4 *)(in_EAX + 0x1c));
  iVar1 = *(int *)(in_EDX + 0xc);
  local_14 = 0;
  if (0 < iVar1) {
    local_10 = in_ECX;
    do {
      puVar4 = *(undefined1 **)(param_1 + local_14 * 4);
      pbVar2 = (byte *)*local_10;
      local_8 = 1;
      if (iVar5 != 0) {
        iVar3 = local_10[1] - (int)pbVar2;
        local_c = iVar5;
        do {
          *puVar4 = (char)((int)((uint)*pbVar2 +
                                pbVar2[1] + local_8 + (uint)pbVar2[iVar3 + 1] + (uint)pbVar2[iVar3])
                          >> 2);
          local_8 = local_8 ^ 3;
          puVar4 = puVar4 + 1;
          pbVar2 = pbVar2 + 2;
          local_c = local_c + -1;
        } while (local_c != 0);
      }
      local_10 = local_10 + 2;
      local_14 = local_14 + 1;
    } while (local_14 < iVar1);
  }
  return;
}


// ==== FUN_00959410 @ 0x00959410 ====

void FUN_00959410(int param_1,int param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  int iVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  int iVar9;
  int in_ECX;
  int in_EDX;
  int iVar10;
  ulonglong *puVar11;
  undefined8 *puVar12;
  ulonglong *puVar13;
  short sVar14;
  short sVar15;
  short sVar16;
  ushort uVar17;
  ushort uVar18;
  ushort uVar19;
  ushort uVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  ulonglong uVar23;
  ushort uVar24;
  ushort uVar25;
  ushort uVar26;
  ushort uVar27;
  ulonglong uVar28;
  
  iVar5 = *(int *)(in_ECX + 0x1c);
  iVar6 = *(int *)(in_ECX + 0xc);
  FUN_00958fa0(param_1,*(undefined4 *)(in_EDX + 0xf4),*(undefined4 *)(in_EDX + 0x1c));
  uVar7 = DAT_00a2e608;
  iVar9 = 0;
  do {
    uVar8 = DAT_00a2e610;
    puVar12 = *(undefined8 **)(param_2 + iVar9 * 4);
    puVar13 = *(ulonglong **)(param_1 + iVar9 * 4);
    puVar11 = *(ulonglong **)(param_1 + (iVar9 + 1) * 4);
    iVar10 = iVar5 << 3;
    do {
      uVar1 = *puVar13;
      uVar2 = *puVar11;
      uVar21 = uVar1 & uVar7;
      uVar22 = uVar2 & uVar7;
      uVar3 = puVar13[1];
      uVar4 = puVar11[1];
      uVar28 = uVar3 & uVar7;
      uVar23 = uVar4 & uVar7;
      sVar14 = (short)((ulonglong)uVar8 >> 0x10);
      sVar15 = (short)((ulonglong)uVar8 >> 0x20);
      sVar16 = (short)((ulonglong)uVar8 >> 0x30);
      uVar17 = (ushort)(((ushort)uVar1 >> 8) + (short)uVar21 + (short)uVar22 + ((ushort)uVar2 >> 8)
                       + (short)uVar8) >> 2;
      uVar18 = (ushort)(((ushort)(uVar1 >> 0x10) >> 8) + (short)(uVar21 >> 0x10) +
                        (short)(uVar22 >> 0x10) + ((ushort)(uVar2 >> 0x10) >> 8) + sVar14) >> 2;
      uVar19 = (ushort)(((ushort)(uVar1 >> 0x20) >> 8) + (short)(uVar21 >> 0x20) +
                        (short)(uVar22 >> 0x20) + ((ushort)(uVar2 >> 0x20) >> 8) + sVar15) >> 2;
      uVar20 = (ushort)((ushort)(uVar1 >> 0x38) + (short)(uVar21 >> 0x30) +
                        (short)(uVar22 >> 0x30) + (ushort)(uVar2 >> 0x38) + sVar16) >> 2;
      uVar24 = (ushort)(((ushort)uVar3 >> 8) + (short)uVar28 + ((ushort)uVar4 >> 8) + (short)uVar23
                       + (short)uVar8) >> 2;
      uVar25 = (ushort)(((ushort)(uVar3 >> 0x10) >> 8) + (short)(uVar28 >> 0x10) +
                        ((ushort)(uVar4 >> 0x10) >> 8) + (short)(uVar23 >> 0x10) + sVar14) >> 2;
      uVar26 = (ushort)(((ushort)(uVar3 >> 0x20) >> 8) + (short)(uVar28 >> 0x20) +
                        ((ushort)(uVar4 >> 0x20) >> 8) + (short)(uVar23 >> 0x20) + sVar15) >> 2;
      uVar27 = (ushort)((ushort)(uVar3 >> 0x38) + (short)(uVar28 >> 0x30) +
                        (ushort)(uVar4 >> 0x38) + (short)(uVar23 >> 0x30) + sVar16) >> 2;
      puVar13 = puVar13 + 2;
      puVar11 = puVar11 + 2;
      iVar10 = iVar10 + -8;
      *puVar12 = CONCAT17((uVar27 != 0) * (uVar27 < 0x100) * (char)uVar27 - (0xff < uVar27),
                          CONCAT16((uVar26 != 0) * (uVar26 < 0x100) * (char)uVar26 - (0xff < uVar26)
                                   ,CONCAT15((uVar25 != 0) * (uVar25 < 0x100) * (char)uVar25 -
                                             (0xff < uVar25),
                                             CONCAT14((uVar24 != 0) * (uVar24 < 0x100) *
                                                      (char)uVar24 - (0xff < uVar24),
                                                      CONCAT13((uVar20 != 0) * (uVar20 < 0x100) *
                                                               (char)uVar20 - (0xff < uVar20),
                                                               CONCAT12((uVar19 != 0) *
                                                                        (uVar19 < 0x100) *
                                                                        (char)uVar19 -
                                                                        (0xff < uVar19),
                                                                        CONCAT11((uVar18 != 0) *
                                                                                 (uVar18 < 0x100) *
                                                                                 (char)uVar18 -
                                                                                 (0xff < uVar18),
                                                                                 (uVar17 != 0) *
                                                                                 (uVar17 < 0x100) *
                                                                                 (char)uVar17 -
                                                                                 (0xff < uVar17)))))
                                            )));
      puVar12 = puVar12 + 1;
    } while (7 < iVar10);
    iVar9 = iVar9 + 1;
  } while (iVar9 < iVar6);
  return;
}


// ==== FUN_009594f0 @ 0x009594f0 ====

void FUN_009594f0(int param_1,byte *param_2,int param_3,int param_4)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  byte *pbVar11;
  int local_24;
  undefined4 *local_20;
  int local_1c;
  undefined1 *local_8;
  
  iVar10 = *(int *)((int)param_2 + 0x1c);
  local_20 = (undefined4 *)(param_3 + -4);
  FUN_00958fa0(local_20,*(int *)(param_1 + 0xf4) + 2,*(undefined4 *)(param_1 + 0x1c));
  iVar6 = *(int *)(param_1 + 0xc0) * 0x10;
  iVar8 = *(int *)(param_1 + 0xc0) * -0x50 + 0x4000;
  iVar1 = *(int *)((int)param_2 + 0xc);
  local_24 = 0;
  if (0 < iVar1) {
    iVar10 = iVar10 * 8 + -2;
    do {
      pbVar2 = (byte *)local_20[1];
      local_8 = *(undefined1 **)(param_4 + local_24 * 4);
      pbVar3 = (byte *)local_20[2];
      pbVar4 = (byte *)*local_20;
      pbVar5 = (byte *)local_20[3];
      pbVar9 = pbVar3 + 2;
      pbVar7 = pbVar2 + 2;
      param_2 = pbVar5 + 2;
      pbVar11 = pbVar4 + 2;
      *local_8 = (char)(((uint)*param_2 +
                        (uint)*pbVar11 + (uint)*pbVar4 +
                        ((uint)*pbVar7 +
                         (uint)*pbVar9 + (uint)*pbVar2 + (uint)pbVar5[1] + (uint)pbVar4[1] +
                         (uint)*pbVar3 + (uint)*pbVar4) * 2 + (uint)*pbVar5 * 3) * iVar6 + 0x8000 +
                        ((uint)pbVar2[1] + (uint)pbVar3[1] + (uint)*pbVar2 + (uint)*pbVar3) * iVar8
                       >> 0x10);
      local_8 = local_8 + 1;
      if (iVar10 != 0) {
        local_1c = iVar10;
        do {
          *local_8 = (char)(((uint)param_2[-1] +
                             ((uint)param_2[1] + (uint)pbVar11[1] + (uint)pbVar9[-1] +
                              (uint)pbVar7[-1] + (uint)*param_2 + (uint)pbVar9[2] + (uint)*pbVar11 +
                             (uint)pbVar7[2]) * 2 + (uint)pbVar11[-1] + (uint)pbVar11[2] +
                            (uint)param_2[2]) * iVar6 + 0x8000 +
                            ((uint)pbVar9[1] + (uint)pbVar7[1] + (uint)*pbVar9 + (uint)*pbVar7) *
                            iVar8 >> 0x10);
          local_8 = local_8 + 1;
          param_2 = param_2 + 2;
          pbVar7 = pbVar7 + 2;
          pbVar9 = pbVar9 + 2;
          pbVar11 = pbVar11 + 2;
          local_1c = local_1c + -1;
        } while (local_1c != 0);
      }
      *local_8 = (char)(((uint)pbVar11[-1] +
                        (uint)param_2[-1] + (uint)pbVar11[1] +
                        ((uint)*pbVar11 +
                         (uint)*param_2 + (uint)pbVar7[1] + (uint)pbVar9[-1] + (uint)pbVar7[-1] +
                         (uint)pbVar9[1] + (uint)pbVar11[1]) * 2 + (uint)param_2[1] * 3) * iVar6 +
                        0x8000 + ((uint)*pbVar7 + (uint)*pbVar9 + (uint)pbVar7[1] + (uint)pbVar9[1])
                                 * iVar8 >> 0x10);
      local_20 = local_20 + 2;
      local_24 = local_24 + 1;
    } while (local_24 < iVar1);
  }
  return;
}


// ==== FUN_00959760 @ 0x00959760 ====

void FUN_00959760(int param_1,undefined1 *param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  uint uVar11;
  byte *pbVar12;
  undefined4 *local_1c;
  int local_18;
  int local_14;
  int local_10;
  byte *local_c;
  
  iVar10 = *(int *)((int)param_2 + 0x1c);
  FUN_00958fa0(param_3 + -1,*(int *)(param_1 + 0xf4) + 2,*(undefined4 *)(param_1 + 0x1c));
  iVar3 = *(int *)((int)param_2 + 0xc);
  iVar8 = (0x80 - *(int *)(param_1 + 0xc0)) * 0x200;
  iVar6 = *(int *)(param_1 + 0xc0) * 0x40;
  local_18 = 0;
  if (0 < iVar3) {
    iVar10 = iVar10 * 8 + -2;
    do {
      local_1c = param_3 + 1;
      param_2 = *(undefined1 **)(param_4 + local_18 * 4);
      puVar1 = param_3 + -1;
      pbVar4 = (byte *)*param_3;
      pbVar5 = (byte *)*local_1c;
      uVar11 = (uint)*pbVar4;
      param_3 = (undefined4 *)((uint)*(byte *)*puVar1 + *pbVar5 + uVar11);
      pbVar12 = (byte *)*puVar1 + 1;
      pbVar9 = pbVar4 + 1;
      iVar7 = (uint)*pbVar12 + (uint)pbVar5[1] + (uint)pbVar4[1];
      *param_2 = (char)((((int)param_3 * 2 - uVar11) + iVar7) * iVar6 + 0x8000 + uVar11 * iVar8 >>
                       0x10);
      param_2 = param_2 + 1;
      if (iVar10 != 0) {
        local_14 = iVar10;
        local_10 = (int)param_3;
        do {
          param_3 = (undefined4 *)iVar7;
          local_c = pbVar5 + 1;
          bVar2 = *pbVar9;
          pbVar4 = pbVar9 + 1;
          pbVar9 = pbVar9 + 1;
          pbVar12 = pbVar12 + 1;
          iVar7 = (uint)*pbVar12 + (uint)pbVar5[2] + (uint)*pbVar4;
          *param_2 = (char)(((local_10 - (uint)bVar2) + iVar7 + (int)param_3) * iVar6 + 0x8000 +
                            (uint)bVar2 * iVar8 >> 0x10);
          param_2 = param_2 + 1;
          local_14 = local_14 + -1;
          local_10 = (int)param_3;
          pbVar5 = local_c;
        } while (local_14 != 0);
      }
      *param_2 = (char)(((iVar7 * 2 - (uint)*pbVar9) + (int)param_3) * iVar6 + 0x8000 +
                        (uint)*pbVar9 * iVar8 >> 0x10);
      local_18 = local_18 + 1;
      param_3 = local_1c;
    } while (local_18 < iVar3);
  }
  return;
}


// ==== FUN_009598e0 @ 0x009598e0 ====

void FUN_009598e0(int *param_1,undefined4 param_2,byte *param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((*param_3 & 7) == 0) {
    if ((param_1[0x31] == 5) || (param_1[0x31] == 6)) {
      FUN_009592a0(param_3,param_4);
      return;
    }
  }
  else {
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x14) = 2;
    (**(code **)(iVar1 + 4))(param_1,0xffffffff);
  }
  FUN_00959210(param_4);
  return;
}


// ==== FUN_00959940 @ 0x00959940 ====

void FUN_00959940(int *param_1,undefined4 param_2,byte *param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((*param_3 & 7) == 0) {
    if ((param_1[0x31] == 5) || (param_1[0x31] == 6)) {
      FUN_00959410(param_3,param_4);
      return;
    }
  }
  else {
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x14) = 2;
    (**(code **)(iVar1 + 4))(param_1,0xffffffff);
  }
  FUN_00959350(param_4);
  return;
}


// ==== FUN_009599a0 @ 0x009599a0 ====

void FUN_009599a0(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  bool bVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int local_10;
  
  piVar5 = param_1;
  bVar4 = true;
  puVar6 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x34);
  iVar1 = param_1[0x2f];
  param_1[0x5b] = (int)puVar6;
  *puVar6 = FUN_004154b0;
  puVar6[1] = FUN_00959000;
  puVar6[2] = 0;
  if (iVar1 != 0) {
    puVar7 = (undefined4 *)*param_1;
    puVar7[5] = 0x19;
    (*(code *)*puVar7)(param_1);
  }
  local_10 = 0;
  if (0 < param_1[0xf]) {
    param_1 = (int *)(param_1[0x11] + 0xc);
    puVar7 = puVar6 + 3;
    do {
      iVar1 = param_1[-1];
      iVar2 = piVar5[0x3c];
      if ((iVar1 == iVar2) && (*param_1 == piVar5[0x3d])) {
        if (piVar5[0x30] == 0) {
          *puVar7 = FUN_009591c0;
        }
        else {
          *puVar7 = FUN_00959760;
          puVar6[2] = 1;
        }
      }
      else if (iVar1 * 2 == iVar2) {
        if (*param_1 == piVar5[0x3d]) {
          bVar4 = false;
          *puVar7 = FUN_009598e0;
        }
        else {
          if ((iVar1 * 2 != iVar2) || (*param_1 * 2 != piVar5[0x3d])) goto LAB_00959aa8;
          if (piVar5[0x30] == 0) {
            *puVar7 = FUN_00959940;
          }
          else {
            *puVar7 = FUN_009594f0;
            puVar6[2] = 1;
          }
        }
      }
      else {
LAB_00959aa8:
        if ((iVar2 % iVar1 == 0) && (piVar5[0x3d] % *param_1 == 0)) {
          *puVar7 = FUN_009590a0;
          bVar4 = false;
        }
        else {
          puVar3 = (undefined4 *)*piVar5;
          puVar3[5] = 0x26;
          (*(code *)*puVar3)(piVar5);
        }
      }
      local_10 = local_10 + 1;
      param_1 = param_1 + 0x15;
      puVar7 = puVar7 + 1;
    } while (local_10 < piVar5[0xf]);
  }
  if ((piVar5[0x30] != 0) && (!bVar4)) {
    iVar1 = *piVar5;
    *(undefined4 *)(iVar1 + 0x14) = 99;
    (**(code **)(iVar1 + 4))(piVar5,0);
  }
  return;
}


// ==== FUN_00959b20 @ 0x00959b20 ====

void FUN_00959b20(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_10;
  int local_c;
  int local_8;
  
  iVar3 = *(int *)(param_1 + 0x168);
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x2000);
  iVar4 = 0;
  *(int *)(iVar3 + 8) = iVar1;
  iVar6 = 0;
  iVar5 = 0;
  local_10 = 0;
  local_c = 0;
  param_1 = 0;
  local_8 = 0x807fff;
  iVar3 = 0x8000;
  piVar2 = (int *)(iVar1 + 0x800);
  do {
    piVar2[0x200] = param_1;
    piVar2[0x300] = local_8;
    piVar2[0x400] = local_c;
    piVar2[0x500] = local_10;
    param_1 = param_1 + -0x54cd;
    local_8 = local_8 + 0x8000;
    local_c = local_c + -0x6b2f;
    *piVar2 = iVar3;
    piVar2[-0x200] = iVar4;
    piVar2[-0x100] = iVar5;
    piVar2[0x100] = iVar6;
    iVar3 = iVar3 + 0x1d2f;
    local_10 = local_10 + -0x14d1;
    iVar4 = iVar4 + 0x4c8b;
    piVar2 = piVar2 + 1;
    iVar5 = iVar5 + 0x9646;
    iVar6 = iVar6 + -0x2b33;
  } while (iVar3 < 0x1d91d2);
  return;
}


// ==== FUN_00959bf0 @ 0x00959bf0 ====

void FUN_00959bf0(int param_1,undefined4 *param_2,int *param_3,int param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  int *piVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  int iVar14;
  uint uVar15;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  iVar4 = *(int *)(*(int *)(param_1 + 0x168) + 8);
  if (-1 < param_5 + -1) {
    iVar5 = param_3[1];
    iVar6 = *param_3;
    iVar7 = param_3[2];
    piVar9 = (int *)(iVar5 + param_4 * 4);
    param_3 = (int *)param_5;
    do {
      piVar1 = (int *)((iVar6 - iVar5) + (int)piVar9);
      pbVar13 = (byte *)*param_2;
      piVar2 = (int *)((iVar7 - iVar5) + (int)piVar9);
      param_2 = param_2 + 1;
      puVar8 = (undefined1 *)*piVar9;
      piVar9 = piVar9 + 1;
      if (iVar3 != 0) {
        iVar14 = *piVar1 - (int)puVar8;
        iVar10 = *piVar2 - (int)puVar8;
        param_5 = iVar3;
        do {
          uVar12 = (uint)pbVar13[2];
          uVar11 = (uint)pbVar13[1];
          uVar15 = (uint)*pbVar13;
          puVar8[iVar14] =
               (char)((uint)(*(int *)(iVar4 + 0x800 + uVar12 * 4) +
                             *(int *)(iVar4 + 0x400 + uVar11 * 4) + *(int *)(iVar4 + uVar15 * 4)) >>
                     0x10);
          pbVar13 = pbVar13 + 3;
          *puVar8 = (char)((uint)(*(int *)(iVar4 + 0x1400 + uVar12 * 4) +
                                  *(int *)(iVar4 + 0x1000 + uVar11 * 4) +
                                 *(int *)(iVar4 + 0xc00 + uVar15 * 4)) >> 0x10);
          puVar8[iVar10] =
               (char)((uint)(*(int *)(iVar4 + 0x1c00 + uVar12 * 4) +
                             *(int *)(iVar4 + 0x1800 + uVar11 * 4) +
                            *(int *)(iVar4 + 0x1400 + uVar15 * 4)) >> 0x10);
          puVar8 = puVar8 + 1;
          param_5 = param_5 + -1;
        } while (param_5 != 0);
      }
      param_3 = (int *)((int)param_3 + -1);
    } while (param_3 != (int *)0x0);
  }
  return;
}


// ==== FUN_00959d10 @ 0x00959d10 ====

void FUN_00959d10(int param_1,undefined4 *param_2,int *param_3,int param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  int iVar15;
  uint uVar16;
  
  iVar3 = *(int *)(param_1 + 0x24);
  iVar4 = *(int *)(param_1 + 0x1c);
  iVar5 = *(int *)(*(int *)(param_1 + 0x168) + 8);
  if (-1 < param_5 + -1) {
    iVar6 = param_3[1];
    iVar7 = *param_3;
    iVar8 = param_3[2];
    piVar10 = (int *)(iVar6 + param_4 * 4);
    param_3 = (int *)param_5;
    do {
      piVar1 = (int *)((iVar7 - iVar6) + (int)piVar10);
      pbVar14 = (byte *)*param_2;
      piVar2 = (int *)((iVar8 - iVar6) + (int)piVar10);
      param_2 = param_2 + 1;
      puVar9 = (undefined1 *)*piVar10;
      piVar10 = piVar10 + 1;
      if (iVar4 != 0) {
        iVar15 = *piVar1 - (int)puVar9;
        iVar11 = *piVar2 - (int)puVar9;
        param_5 = iVar4;
        do {
          uVar13 = (uint)*pbVar14;
          uVar12 = (uint)pbVar14[1];
          uVar16 = (uint)pbVar14[2];
          puVar9[iVar15] =
               (char)((uint)(*(int *)(iVar5 + 0x800 + uVar13 * 4) +
                             *(int *)(iVar5 + 0x400 + uVar12 * 4) + *(int *)(iVar5 + uVar16 * 4)) >>
                     0x10);
          pbVar14 = pbVar14 + iVar3;
          *puVar9 = (char)((uint)(*(int *)(iVar5 + 0x1400 + uVar13 * 4) +
                                  *(int *)(iVar5 + 0x1000 + uVar12 * 4) +
                                 *(int *)(iVar5 + 0xc00 + uVar16 * 4)) >> 0x10);
          puVar9[iVar11] =
               (char)((uint)(*(int *)(iVar5 + 0x1c00 + uVar13 * 4) +
                             *(int *)(iVar5 + 0x1800 + uVar12 * 4) +
                            *(int *)(iVar5 + 0x1400 + uVar16 * 4)) >> 0x10);
          puVar9 = puVar9 + 1;
          param_5 = param_5 + -1;
        } while (param_5 != 0);
      }
      param_3 = (int *)((int)param_3 + -1);
    } while (param_3 != (int *)0x0);
  }
  return;
}


// ==== FUN_00959e30 @ 0x00959e30 ====

void FUN_00959e30(int param_1,undefined4 *param_2,int *param_3,int param_4,int param_5)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  int *piVar9;
  
  uVar4 = *(uint *)(param_1 + 0x1c);
  iVar5 = *(int *)(*(int *)(param_1 + 0x168) + 8);
  if (-1 < param_5 + -1) {
    piVar9 = (int *)(*param_3 + param_4 * 4);
    param_1 = param_5;
    do {
      pbVar7 = (byte *)*param_2;
      param_2 = param_2 + 1;
      iVar6 = *piVar9;
      piVar9 = piVar9 + 1;
      uVar8 = 0;
      if (uVar4 != 0) {
        do {
          pbVar1 = pbVar7 + 2;
          pbVar2 = pbVar7 + 1;
          bVar3 = *pbVar7;
          pbVar7 = pbVar7 + 3;
          *(char *)(uVar8 + iVar6) =
               (char)((uint)(*(int *)(iVar5 + 0x800 + (uint)*pbVar1 * 4) +
                             *(int *)(iVar5 + 0x400 + (uint)*pbVar2 * 4) +
                            *(int *)(iVar5 + (uint)bVar3 * 4)) >> 0x10);
          uVar8 = uVar8 + 1;
        } while (uVar8 < uVar4);
      }
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}


// ==== FUN_00959ed0 @ 0x00959ed0 ====

void FUN_00959ed0(int param_1,undefined4 *param_2,int *param_3,int param_4,int param_5)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  int *piVar10;
  
  iVar4 = *(int *)(param_1 + 0x24);
  iVar5 = *(int *)(*(int *)(param_1 + 0x168) + 8);
  uVar6 = *(uint *)(param_1 + 0x1c);
  if (-1 < param_5 + -1) {
    piVar10 = (int *)(*param_3 + param_4 * 4);
    param_1 = param_5;
    do {
      pbVar8 = (byte *)*param_2;
      param_2 = param_2 + 1;
      iVar7 = *piVar10;
      piVar10 = piVar10 + 1;
      uVar9 = 0;
      if (uVar6 != 0) {
        do {
          bVar3 = *pbVar8;
          pbVar1 = pbVar8 + 1;
          pbVar2 = pbVar8 + 2;
          pbVar8 = pbVar8 + iVar4;
          *(char *)(uVar9 + iVar7) =
               (char)((uint)(*(int *)(iVar5 + 0x800 + (uint)bVar3 * 4) +
                             *(int *)(iVar5 + 0x400 + (uint)*pbVar1 * 4) +
                            *(int *)(iVar5 + (uint)*pbVar2 * 4)) >> 0x10);
          uVar9 = uVar9 + 1;
        } while (uVar9 < uVar6);
      }
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}


// ==== FUN_00959f70 @ 0x00959f70 ====

void FUN_00959f70(byte *param_1,undefined4 *param_2,int *param_3,int param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined1 *puVar17;
  
  iVar3 = *(int *)((int)param_1 + 0x1c);
  iVar4 = *(int *)(*(int *)((int)param_1 + 0x168) + 8);
  if (-1 < param_5 + -1) {
    iVar5 = param_3[1];
    iVar6 = *param_3;
    iVar7 = param_3[2];
    iVar8 = param_3[3];
    piVar10 = (int *)(iVar5 + param_4 * 4);
    param_4 = param_5;
    do {
      piVar1 = (int *)((iVar7 - iVar5) + (int)piVar10);
      param_1 = (byte *)*param_2;
      param_2 = param_2 + 1;
      piVar2 = (int *)((iVar8 - iVar5) + (int)piVar10);
      puVar17 = *(undefined1 **)((iVar6 - iVar5) + (int)piVar10);
      iVar15 = *piVar10;
      piVar10 = piVar10 + 1;
      if (iVar3 != 0) {
        iVar11 = *piVar2 - (int)puVar17;
        iVar15 = iVar15 - (int)puVar17;
        iVar12 = *piVar1 - (int)puVar17;
        param_3 = (int *)iVar3;
        do {
          iVar13 = 0xff - (uint)*param_1;
          iVar16 = 0xff - (uint)param_1[1];
          iVar14 = 0xff - (uint)param_1[2];
          puVar17[iVar11] = param_1[3];
          param_1 = param_1 + 4;
          iVar9 = *(int *)(iVar4 + 0x1400 + iVar14 * 4);
          *puVar17 = (char)((uint)(*(int *)(iVar4 + 0x800 + iVar14 * 4) +
                                   *(int *)(iVar4 + 0x400 + iVar16 * 4) +
                                  *(int *)(iVar4 + iVar13 * 4)) >> 0x10);
          puVar17[iVar15] =
               (char)((uint)(iVar9 + *(int *)(iVar4 + 0x1000 + iVar16 * 4) +
                            *(int *)(iVar4 + 0xc00 + iVar13 * 4)) >> 0x10);
          puVar17[iVar12] =
               (char)((uint)(*(int *)(iVar4 + 0x1c00 + iVar14 * 4) +
                             *(int *)(iVar4 + 0x1800 + iVar16 * 4) +
                            *(int *)(iVar4 + 0x1400 + iVar13 * 4)) >> 0x10);
          puVar17 = puVar17 + 1;
          param_3 = (int *)((int)param_3 + -1);
        } while (param_3 != (int *)0x0);
      }
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}


// ==== FUN_0095a0d0 @ 0x0095a0d0 ====

void FUN_0095a0d0(int param_1,undefined4 *param_2,int *param_3,int param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  int *piVar6;
  
  uVar1 = *(uint *)(param_1 + 0x1c);
  iVar2 = *(int *)(param_1 + 0x24);
  if (-1 < param_5 + -1) {
    piVar6 = (int *)(*param_3 + param_4 * 4);
    param_1 = param_5;
    do {
      puVar5 = (undefined1 *)*param_2;
      iVar3 = *piVar6;
      param_2 = param_2 + 1;
      piVar6 = piVar6 + 1;
      uVar4 = 0;
      if (uVar1 != 0) {
        do {
          *(undefined1 *)(uVar4 + iVar3) = *puVar5;
          puVar5 = puVar5 + iVar2;
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar1);
      }
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}


// ==== FUN_0095a140 @ 0x0095a140 ====

void FUN_0095a140(int param_1,int *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  int iVar7;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  uVar2 = *(uint *)(param_1 + 0x1c);
  if (-1 < param_5 + -1) {
    param_1 = param_4 * 4;
    do {
      iVar7 = 0;
      if (0 < iVar1) {
        iVar3 = *param_2;
        do {
          iVar4 = *(int *)(param_1 + *(int *)(param_3 + iVar7 * 4));
          uVar5 = 0;
          if (uVar2 != 0) {
            puVar6 = (undefined1 *)(iVar3 + iVar7);
            do {
              *(undefined1 *)(uVar5 + iVar4) = *puVar6;
              puVar6 = puVar6 + iVar1;
              uVar5 = uVar5 + 1;
            } while (uVar5 < uVar2);
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar1);
      }
      param_2 = param_2 + 1;
      param_1 = param_1 + 4;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
  }
  return;
}


// ==== FUN_0095a1e0 @ 0x0095a1e0 ====

void FUN_0095a1e0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  bool bVar4;
  
  puVar3 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0xc);
  iVar1 = param_1[10];
  param_1[0x5a] = (int)puVar3;
  *puVar3 = FUN_004154b0;
  switch(iVar1) {
  case 1:
    if (param_1[9] != 1) {
LAB_0095a234:
      puVar2 = (undefined4 *)*param_1;
      puVar2[5] = 9;
      (*(code *)*puVar2)(param_1);
    }
    break;
  case 2:
  case 3:
    if (param_1[9] != 3) goto LAB_0095a234;
    break;
  case 4:
  case 5:
    if (param_1[9] != 4) goto LAB_0095a234;
    break;
  default:
    if (param_1[9] < 1) goto LAB_0095a234;
  }
  switch(param_1[0x10]) {
  case 1:
    if (param_1[0xf] != 1) {
      puVar2 = (undefined4 *)*param_1;
      puVar2[5] = 10;
      (*(code *)*puVar2)(param_1);
    }
    iVar1 = param_1[10];
    if (iVar1 == 1) {
LAB_0095a2af:
      puVar3[1] = FUN_0095a0d0;
      return;
    }
    if (iVar1 == 2) {
      *puVar3 = FUN_00959b20;
      puVar3[1] = FUN_00959e30;
      return;
    }
    if ((iVar1 == 6) || (iVar1 == 7)) {
      *puVar3 = FUN_00959b20;
      puVar3[1] = FUN_00959ed0;
      return;
    }
    if (iVar1 == 3) goto LAB_0095a2af;
    goto LAB_0095a370;
  case 2:
    if (param_1[0xf] != 3) {
      puVar2 = (undefined4 *)*param_1;
      puVar2[5] = 10;
      (*(code *)*puVar2)(param_1);
    }
    bVar4 = param_1[10] == 2;
    break;
  case 3:
    if (param_1[0xf] != 3) {
      puVar2 = (undefined4 *)*param_1;
      puVar2[5] = 10;
      (*(code *)*puVar2)(param_1);
    }
    iVar1 = param_1[10];
    if (iVar1 == 2) {
      *puVar3 = FUN_00959b20;
      puVar3[1] = FUN_00959bf0;
      return;
    }
    if ((iVar1 == 6) || (iVar1 == 7)) {
      *puVar3 = FUN_00959b20;
      puVar3[1] = FUN_00959d10;
      return;
    }
    bVar4 = iVar1 == 3;
    break;
  case 4:
    if (param_1[0xf] != 4) {
      puVar2 = (undefined4 *)*param_1;
      puVar2[5] = 10;
      (*(code *)*puVar2)(param_1);
    }
    bVar4 = param_1[10] == 4;
    break;
  case 5:
    if (param_1[0xf] != 4) {
      puVar2 = (undefined4 *)*param_1;
      puVar2[5] = 10;
      (*(code *)*puVar2)(param_1);
    }
    if (param_1[10] == 4) {
      *puVar3 = FUN_00959b20;
      puVar3[1] = FUN_00959f70;
      return;
    }
    bVar4 = param_1[10] == 5;
    break;
  default:
    if ((param_1[0x10] != param_1[10]) || (param_1[0xf] != param_1[9])) {
      puVar2 = (undefined4 *)*param_1;
      puVar2[5] = 0x1b;
      (*(code *)*puVar2)(param_1);
    }
    goto LAB_0095a39c;
  }
  if (bVar4) {
LAB_0095a39c:
    puVar3[1] = FUN_0095a140;
    return;
  }
LAB_0095a370:
  puVar3 = (undefined4 *)*param_1;
  puVar3[5] = 0x1b;
  (*(code *)*puVar3)(param_1);
  return;
}


// ==== FUN_0095a3e0 @ 0x0095a3e0 ====

void FUN_0095a3e0(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *unaff_ESI;
  int *piVar5;
  undefined4 *puVar6;
  
  if ((((unaff_ESI[8] == 0) || (unaff_ESI[7] == 0)) || (unaff_ESI[0xf] < 1)) || (unaff_ESI[9] < 1))
  {
    puVar6 = (undefined4 *)*unaff_ESI;
    puVar6[5] = 0x20;
    (*(code *)*puVar6)();
  }
  if ((0xffdc < unaff_ESI[8]) || (0xffdc < unaff_ESI[7])) {
    puVar6 = (undefined4 *)*unaff_ESI;
    puVar6[5] = 0x29;
    puVar6[6] = 0xffdc;
    (*(code *)*puVar6)();
  }
  iVar4 = unaff_ESI[0xe];
  if (iVar4 != 8) {
    puVar6 = (undefined4 *)*unaff_ESI;
    puVar6[5] = 0xf;
    puVar6[6] = iVar4;
    (*(code *)*puVar6)();
  }
  iVar4 = unaff_ESI[0xf];
  if (10 < iVar4) {
    puVar6 = (undefined4 *)*unaff_ESI;
    puVar6[5] = 0x1a;
    puVar6[6] = iVar4;
    puVar6[7] = 10;
    (*(code *)*puVar6)();
  }
  iVar4 = 0;
  unaff_ESI[0x3c] = 1;
  unaff_ESI[0x3d] = 1;
  if (0 < unaff_ESI[0xf]) {
    piVar5 = (int *)(unaff_ESI[0x11] + 0xc);
    do {
      if (((piVar5[-1] < 1) || (4 < piVar5[-1])) || ((*piVar5 < 1 || (4 < *piVar5)))) {
        puVar6 = (undefined4 *)*unaff_ESI;
        puVar6[5] = 0x12;
        (*(code *)*puVar6)();
      }
      iVar2 = unaff_ESI[0x3c];
      if (unaff_ESI[0x3c] <= piVar5[-1]) {
        iVar2 = piVar5[-1];
      }
      iVar1 = *piVar5;
      unaff_ESI[0x3c] = iVar2;
      iVar2 = unaff_ESI[0x3d];
      if (unaff_ESI[0x3d] <= iVar1) {
        iVar2 = iVar1;
      }
      unaff_ESI[0x3d] = iVar2;
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 0x15;
    } while (iVar4 < unaff_ESI[0xf]);
  }
  if (0 < unaff_ESI[0xf]) {
    puVar6 = (undefined4 *)(unaff_ESI[0x11] + 0x24);
    iVar4 = 0;
    do {
      iVar2 = unaff_ESI[7];
      iVar1 = unaff_ESI[0x3c];
      puVar6[-8] = iVar4;
      *puVar6 = 8;
      uVar3 = FUN_0090b6f0(puVar6[-7] * iVar2,iVar1 << 3);
      iVar2 = unaff_ESI[0x3d];
      puVar6[-2] = uVar3;
      uVar3 = FUN_0090b6f0(puVar6[-6] * unaff_ESI[8],iVar2 << 3);
      iVar2 = unaff_ESI[7];
      iVar1 = unaff_ESI[0x3c];
      puVar6[-1] = uVar3;
      uVar3 = FUN_0090b6f0(puVar6[-7] * iVar2,iVar1);
      iVar2 = unaff_ESI[8];
      puVar6[1] = uVar3;
      uVar3 = FUN_0090b6f0(puVar6[-6] * iVar2,unaff_ESI[0x3d]);
      puVar6[2] = uVar3;
      iVar2 = unaff_ESI[0xf];
      puVar6[3] = 1;
      iVar4 = iVar4 + 1;
      puVar6 = puVar6 + 0x15;
    } while (iVar4 < iVar2);
  }
  iVar4 = FUN_0090b6f0(unaff_ESI[8],unaff_ESI[0x3d] << 3);
  unaff_ESI[0x3e] = iVar4;
  return;
}


// ==== FUN_0095a590 @ 0x0095a590 ====

void FUN_0095a590(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *unaff_ESI;
  bool bVar6;
  int local_a4c [640];
  int local_4c [10];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int local_8;
  
  if (unaff_ESI[0x2a] < 1) {
    puVar2 = (undefined4 *)*unaff_ESI;
    puVar2[5] = 0x13;
    puVar2[6] = 0;
    (*(code *)*puVar2)();
  }
  piVar5 = (int *)unaff_ESI[0x2b];
  local_c = piVar5;
  if ((piVar5[5] == 0) && (piVar5[6] == 0x3f)) {
    iVar4 = unaff_ESI[0xf];
    unaff_ESI[0x3b] = 0;
    if (iVar4 < 1) goto LAB_0095a609;
    iVar1 = 0;
    piVar3 = local_4c;
  }
  else {
    unaff_ESI[0x3b] = 1;
    if (unaff_ESI[0xf] < 1) goto LAB_0095a609;
    iVar4 = (unaff_ESI[0xf] & 0xffffffU) << 6;
    iVar1 = -1;
    piVar3 = local_a4c;
  }
  for (; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar3 = iVar1;
    piVar3 = piVar3 + 1;
  }
LAB_0095a609:
  local_8 = 1;
  if (unaff_ESI[0x2a] < 1) {
LAB_0095a85d:
    iVar4 = 0;
    if (unaff_ESI[0x3b] == 0) {
      if (0 < unaff_ESI[0xf]) {
        do {
          if (local_4c[iVar4] == 0) {
            puVar2 = (undefined4 *)*unaff_ESI;
            puVar2[5] = 0x2d;
            (*(code *)*puVar2)();
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < unaff_ESI[0xf]);
      }
    }
    else if (0 < unaff_ESI[0xf]) {
      piVar5 = local_a4c;
      do {
        if (*piVar5 < 0) {
          puVar2 = (undefined4 *)*unaff_ESI;
          puVar2[5] = 0x2d;
          (*(code *)*puVar2)();
        }
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 0x40;
      } while (iVar4 < unaff_ESI[0xf]);
      return;
    }
    return;
  }
  do {
    iVar4 = local_8;
    local_10 = (int *)*piVar5;
    if (((int)local_10 < 1) || (4 < (int)local_10)) {
      puVar2 = (undefined4 *)*unaff_ESI;
      puVar2[5] = 0x1a;
      puVar2[6] = local_10;
      puVar2[7] = 4;
      (*(code *)*puVar2)();
    }
    iVar1 = 0;
    if (0 < (int)local_10) {
      do {
        iVar4 = local_c[iVar1 + 1];
        if ((iVar4 < 0) || (unaff_ESI[0xf] <= iVar4)) {
          puVar2 = (undefined4 *)*unaff_ESI;
          puVar2[5] = 0x13;
          puVar2[6] = local_8;
          (*(code *)*puVar2)();
        }
        if ((0 < iVar1) && (iVar4 <= local_c[iVar1])) {
          puVar2 = (undefined4 *)*unaff_ESI;
          puVar2[5] = 0x13;
          puVar2[6] = local_8;
          (*(code *)*puVar2)();
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)local_10);
      iVar4 = local_8;
    }
    iVar1 = local_c[5];
    local_18 = local_c[6];
    local_20 = local_c[7];
    local_24 = local_c[8];
    local_1c = iVar1;
    if (unaff_ESI[0x3b] == 0) {
      if ((((iVar1 != 0) || (local_18 != 0x3f)) || (local_20 != 0)) || (local_24 != 0)) {
        puVar2 = (undefined4 *)*unaff_ESI;
        puVar2[5] = 0x11;
        puVar2[6] = iVar4;
        (*(code *)*puVar2)();
      }
      if (0 < (int)local_10) {
        local_14 = local_10;
        piVar5 = local_c;
        do {
          piVar5 = piVar5 + 1;
          iVar4 = *piVar5;
          if (local_4c[iVar4] != 0) {
            puVar2 = (undefined4 *)*unaff_ESI;
            puVar2[5] = 0x13;
            puVar2[6] = local_8;
            (*(code *)*puVar2)();
          }
          piVar3 = (int *)((int)local_14 + -1);
          local_4c[iVar4] = 1;
          local_14 = piVar3;
        } while (piVar3 != (int *)0x0);
        iVar4 = local_8;
      }
    }
    else {
      if (((((iVar1 < 0) || (0x3f < iVar1)) ||
           ((local_18 < iVar1 || ((0x3f < local_18 || (local_20 < 0)))))) || (10 < local_20)) ||
         ((local_24 < 0 || (10 < local_24)))) {
        puVar2 = (undefined4 *)*unaff_ESI;
        puVar2[5] = 0x11;
        puVar2[6] = iVar4;
        (*(code *)*puVar2)();
      }
      if (iVar1 == 0) {
        bVar6 = local_18 == 0;
      }
      else {
        bVar6 = local_10 == (int *)0x1;
      }
      if (!bVar6) {
        puVar2 = (undefined4 *)*unaff_ESI;
        puVar2[5] = 0x11;
        puVar2[6] = iVar4;
        (*(code *)*puVar2)();
      }
      piVar5 = local_10;
      if (0 < (int)local_10) {
        local_10 = local_c + 1;
        local_14 = piVar5;
        do {
          piVar5 = local_a4c + *local_10 * 0x40;
          if ((local_1c != 0) && (*piVar5 < 0)) {
            puVar2 = (undefined4 *)*unaff_ESI;
            puVar2[5] = 0x11;
            puVar2[6] = iVar4;
            (*(code *)*puVar2)();
          }
          iVar4 = local_1c;
          if (local_1c <= local_18) {
            do {
              if (piVar5[iVar4] < 0) {
                if (local_20 != 0) {
                  puVar2 = (undefined4 *)*unaff_ESI;
                  puVar2[5] = 0x11;
                  puVar2[6] = local_8;
                  goto LAB_0095a7ad;
                }
              }
              else if ((local_20 != piVar5[iVar4]) || (local_24 != local_20 + -1)) {
                puVar2 = (undefined4 *)*unaff_ESI;
                puVar2[5] = 0x11;
                puVar2[6] = local_8;
LAB_0095a7ad:
                (*(code *)*puVar2)();
              }
              piVar5[iVar4] = local_24;
              iVar4 = iVar4 + 1;
            } while (iVar4 <= local_18);
          }
          local_14 = (int *)((int)local_14 + -1);
          local_10 = local_10 + 1;
          iVar4 = local_8;
        } while (local_14 != (int *)0x0);
      }
    }
    local_c = local_c + 9;
    local_8 = iVar4 + 1;
    if (unaff_ESI[0x2a] < iVar4 + 1) goto LAB_0095a85d;
    piVar5 = local_c;
  } while( true );
}


// ==== FUN_0095a8d0 @ 0x0095a8d0 ====

void FUN_0095a8d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *unaff_ESI;
  
  if (unaff_ESI[0x2b] != 0) {
    piVar4 = (int *)(unaff_ESI[0x2b] + *(int *)(unaff_ESI[0x55] + 0x20) * 0x24);
    iVar7 = *piVar4;
    unaff_ESI[0x3f] = iVar7;
    if (0 < iVar7) {
      piVar5 = unaff_ESI + 0x40;
      piVar3 = piVar4;
      do {
        piVar3 = piVar3 + 1;
        *piVar5 = *piVar3 * 0x54 + unaff_ESI[0x11];
        piVar5 = piVar5 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    iVar7 = piVar4[6];
    iVar6 = piVar4[7];
    unaff_ESI[0x51] = piVar4[5];
    iVar1 = piVar4[8];
    unaff_ESI[0x52] = iVar7;
    unaff_ESI[0x53] = iVar6;
    unaff_ESI[0x54] = iVar1;
    return;
  }
  iVar7 = unaff_ESI[0xf];
  if (4 < iVar7) {
    puVar2 = (undefined4 *)*unaff_ESI;
    puVar2[5] = 0x1a;
    puVar2[6] = iVar7;
    puVar2[7] = 4;
    (*(code *)*puVar2)();
  }
  iVar7 = 0;
  unaff_ESI[0x3f] = unaff_ESI[0xf];
  if (0 < unaff_ESI[0xf]) {
    iVar6 = 0;
    piVar4 = unaff_ESI + 0x40;
    do {
      *piVar4 = unaff_ESI[0x11] + iVar6;
      iVar7 = iVar7 + 1;
      piVar4 = piVar4 + 1;
      iVar6 = iVar6 + 0x54;
    } while (iVar7 < unaff_ESI[0xf]);
  }
  unaff_ESI[0x51] = 0;
  unaff_ESI[0x53] = 0;
  unaff_ESI[0x54] = 0;
  unaff_ESI[0x52] = 0x3f;
  return;
}


// ==== FUN_0095a9b0 @ 0x0095a9b0 ====

uint FUN_0095a9b0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int *unaff_ESI;
  int *local_c;
  uint local_8;
  
  iVar5 = unaff_ESI[0x3f];
  if (iVar5 == 1) {
    iVar5 = unaff_ESI[0x40];
    uVar7 = *(uint *)(iVar5 + 0xc);
    unaff_ESI[0x44] = *(int *)(iVar5 + 0x1c);
    uVar1 = *(uint *)(iVar5 + 0x20);
    unaff_ESI[0x45] = uVar1;
    uVar4 = uVar1 / uVar7;
    *(undefined4 *)(iVar5 + 0x34) = 1;
    *(undefined4 *)(iVar5 + 0x38) = 1;
    *(undefined4 *)(iVar5 + 0x3c) = 1;
    *(undefined4 *)(iVar5 + 0x40) = 8;
    *(undefined4 *)(iVar5 + 0x44) = 1;
    uVar6 = uVar1 % uVar7;
    if (uVar1 % uVar7 == 0) {
      uVar6 = uVar7;
    }
    *(uint *)(iVar5 + 0x48) = uVar6;
    unaff_ESI[0x46] = 1;
    unaff_ESI[0x47] = 0;
  }
  else {
    if ((iVar5 < 1) || (4 < iVar5)) {
      puVar2 = (undefined4 *)*unaff_ESI;
      puVar2[5] = 0x1a;
      puVar2[6] = iVar5;
      puVar2[7] = 4;
      (*(code *)*puVar2)();
    }
    iVar5 = FUN_0090b6f0(unaff_ESI[7],unaff_ESI[0x3c] << 3);
    unaff_ESI[0x44] = iVar5;
    uVar4 = FUN_0090b6f0(unaff_ESI[8],unaff_ESI[0x3d] << 3);
    unaff_ESI[0x45] = uVar4;
    unaff_ESI[0x46] = 0;
    local_8 = 0;
    if (0 < unaff_ESI[0x3f]) {
      local_c = unaff_ESI + 0x40;
      do {
        iVar5 = *local_c;
        uVar4 = *(uint *)(iVar5 + 8);
        *(uint *)(iVar5 + 0x40) = uVar4 * 8;
        uVar7 = *(uint *)(iVar5 + 0x1c) % uVar4;
        *(int *)(iVar5 + 0x38) = *(int *)(iVar5 + 0xc);
        iVar8 = *(int *)(iVar5 + 0xc) * uVar4;
        *(uint *)(iVar5 + 0x34) = uVar4;
        *(int *)(iVar5 + 0x3c) = iVar8;
        if (uVar7 == 0) {
          uVar7 = uVar4;
        }
        *(uint *)(iVar5 + 0x44) = uVar7;
        uVar4 = *(uint *)(iVar5 + 0x20) % *(uint *)(iVar5 + 0xc);
        if (uVar4 == 0) {
          uVar4 = *(uint *)(iVar5 + 0xc);
        }
        iVar3 = unaff_ESI[0x46];
        *(uint *)(iVar5 + 0x48) = uVar4;
        if (10 < iVar3 + iVar8) {
          puVar2 = (undefined4 *)*unaff_ESI;
          puVar2[5] = 0xd;
          (*(code *)*puVar2)();
        }
        if (0 < iVar8) {
          do {
            unaff_ESI[unaff_ESI[0x46] + 0x47] = local_8;
            iVar8 = iVar8 + -1;
            unaff_ESI[0x46] = unaff_ESI[0x46] + 1;
          } while (iVar8 != 0);
        }
        uVar4 = local_8 + 1;
        local_c = local_c + 1;
        local_8 = uVar4;
      } while ((int)uVar4 < unaff_ESI[0x3f]);
    }
  }
  if (0 < unaff_ESI[0x33]) {
    uVar4 = unaff_ESI[0x44] * unaff_ESI[0x33];
    if (0xfffe < (int)uVar4) {
      uVar4 = 0xffff;
    }
    unaff_ESI[0x32] = uVar4;
  }
  return uVar4;
}


// ==== FUN_0095ab70 @ 0x0095ab70 ====

void FUN_0095ab70(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = param_1[0x55];
  iVar2 = *(int *)(iVar1 + 0x14);
  if (iVar2 == 0) {
    FUN_0095a8d0();
    FUN_0095a9b0();
    if (param_1[0x2c] == 0) {
      (**(code **)param_1[0x5a])(param_1);
      (**(code **)param_1[0x5b])(param_1);
      (**(code **)param_1[0x57])(param_1,0);
    }
    (**(code **)param_1[0x5c])(param_1);
    (**(code **)param_1[0x5d])(param_1,param_1[0x2e]);
    (**(code **)param_1[0x58])(param_1,(*(int *)(iVar1 + 0x1c) < 2) - 1U & 3);
    (**(code **)param_1[0x56])(param_1,0);
    *(uint *)(iVar1 + 0xc) = (uint)(param_1[0x2e] == 0);
  }
  else {
    if (iVar2 == 1) {
      FUN_0095a8d0();
      FUN_0095a9b0();
      if (((param_1[0x51] != 0) || (param_1[0x53] == 0)) || (param_1[0x2d] != 0)) {
        (**(code **)param_1[0x5d])(param_1,1);
        (**(code **)param_1[0x58])(param_1,2);
        *(undefined4 *)(iVar1 + 0xc) = 0;
        goto LAB_0095acc7;
      }
      *(undefined4 *)(iVar1 + 0x14) = 2;
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
    }
    else if (iVar2 != 2) {
      puVar3 = (undefined4 *)*param_1;
      puVar3[5] = 0x30;
      (*(code *)*puVar3)(param_1);
      goto LAB_0095acc7;
    }
    if (param_1[0x2e] == 0) {
      FUN_0095a8d0();
      FUN_0095a9b0();
    }
    (**(code **)param_1[0x5d])(param_1,0);
    (**(code **)param_1[0x58])(param_1,2);
    if (*(int *)(iVar1 + 0x20) == 0) {
      (**(code **)(param_1[0x59] + 4))(param_1);
    }
    (**(code **)(param_1[0x59] + 8))(param_1);
    *(undefined4 *)(iVar1 + 0xc) = 0;
  }
LAB_0095acc7:
  iVar2 = param_1[2];
  *(uint *)(iVar1 + 0x10) = (uint)(*(int *)(iVar1 + 0x18) == *(int *)(iVar1 + 0x1c) + -1);
  if (iVar2 != 0) {
    *(int *)(iVar2 + 0xc) = *(int *)(iVar1 + 0x18);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar1 + 0x1c);
  }
  return;
}


// ==== FUN_0095acf0 @ 0x0095acf0 ====

void FUN_0095acf0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x164);
  *(undefined4 *)(*(int *)(param_1 + 0x154) + 0xc) = 0;
  (**(code **)(iVar1 + 4))(param_1);
  (**(code **)(*(int *)(param_1 + 0x164) + 8))(param_1);
  return;
}


// ==== FUN_0095ad20 @ 0x0095ad20 ====

void FUN_0095ad20(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x154);
  (**(code **)(*(int *)(param_1 + 0x174) + 8))(param_1);
  iVar2 = *(int *)(iVar1 + 0x14);
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 0xb8);
    *(undefined4 *)(iVar1 + 0x14) = 2;
    if (iVar2 != 0) goto LAB_0095ad91;
  }
  else {
    if (iVar2 == 1) {
      *(undefined4 *)(iVar1 + 0x14) = 2;
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
      return;
    }
    if (iVar2 != 2) goto LAB_0095ad91;
    if (*(int *)(param_1 + 0xb8) != 0) {
      *(int *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) + 1;
      *(undefined4 *)(iVar1 + 0x14) = 1;
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
      return;
    }
  }
  *(int *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) + 1;
LAB_0095ad91:
  *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
  return;
}


// ==== FUN_0095ada0 @ 0x0095ada0 ====

void FUN_0095ada0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x24);
  *(undefined4 **)(param_1 + 0x154) = puVar2;
  *puVar2 = FUN_0095ab70;
  puVar2[1] = FUN_0095acf0;
  puVar2[2] = FUN_0095ad20;
  puVar2[4] = 0;
  FUN_0095a3e0();
  if (*(int *)(param_1 + 0xac) == 0) {
    *(undefined4 *)(param_1 + 0xec) = 0;
    *(undefined4 *)(param_1 + 0xa8) = 1;
  }
  else {
    FUN_0095a590();
  }
  if (*(int *)(param_1 + 0xec) != 0) {
    *(undefined4 *)(param_1 + 0xb8) = 1;
  }
  if (param_2 == 0) {
    puVar2[5] = 0;
  }
  else {
    puVar2[5] = (*(int *)(param_1 + 0xb8) == 0) + 1;
  }
  iVar1 = *(int *)(param_1 + 0xb8);
  puVar2[8] = 0;
  puVar2[6] = 0;
  if (iVar1 == 0) {
    puVar2[7] = *(undefined4 *)(param_1 + 0xa8);
    return;
  }
  puVar2[7] = *(int *)(param_1 + 0xa8) << 1;
  return;
}


// ==== FUN_0095ae57 @ 0x0095ae57 ====

uint FUN_0095ae57(uint param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  
  uVar3 = param_1 & 0xffff;
  param_1 = param_1 >> 0x10;
  if (param_2 == (byte *)0x0) {
    uVar3 = 1;
  }
  else {
    while (param_3 != 0) {
      uVar2 = 0x15b0;
      if (param_3 < 0x15b0) {
        uVar2 = param_3;
      }
      param_3 = param_3 - uVar2;
      if (0xf < (int)uVar2) {
        uVar1 = uVar2 >> 4;
        uVar2 = uVar2 + uVar1 * -0x10;
        do {
          iVar4 = uVar3 + *param_2;
          iVar5 = iVar4 + (uint)param_2[1];
          iVar6 = iVar5 + (uint)param_2[2];
          iVar7 = iVar6 + (uint)param_2[3];
          iVar8 = iVar7 + (uint)param_2[4];
          iVar9 = iVar8 + (uint)param_2[5];
          iVar10 = iVar9 + (uint)param_2[6];
          iVar11 = iVar10 + (uint)param_2[7];
          iVar12 = iVar11 + (uint)param_2[8];
          iVar13 = iVar12 + (uint)param_2[9];
          iVar14 = iVar13 + (uint)param_2[10];
          iVar15 = iVar14 + (uint)param_2[0xb];
          iVar16 = iVar15 + (uint)param_2[0xc];
          iVar17 = iVar16 + (uint)param_2[0xd];
          iVar18 = iVar17 + (uint)param_2[0xe];
          uVar3 = iVar18 + (uint)param_2[0xf];
          param_1 = param_1 + iVar4 + iVar5 + iVar6 + iVar7 + iVar8 + iVar9 + iVar10 + iVar11 +
                    iVar12 + iVar13 + iVar14 + iVar15 + iVar16 + iVar17 + iVar18 + uVar3;
          param_2 = param_2 + 0x10;
          uVar1 = uVar1 - 1;
        } while (uVar1 != 0);
      }
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        uVar3 = uVar3 + *param_2;
        param_2 = param_2 + 1;
        param_1 = param_1 + uVar3;
      }
      uVar3 = uVar3 % 0xfff1;
      param_1 = param_1 % 0xfff1;
    }
    uVar3 = param_1 << 0x10 | uVar3;
  }
  return uVar3;
}


// ==== FUN_0095af74 @ 0x0095af74 ====

void FUN_0095af74(void)

{
  int in_EAX;
  undefined2 *puVar1;
  int iVar2;
  
  puVar1 = (undefined2 *)(in_EAX + 0x8c);
  iVar2 = 0x11e;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined2 *)(in_EAX + 0x980);
  iVar2 = 0x1e;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined2 *)(in_EAX + 0xa74);
  iVar2 = 0x13;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined2 *)(in_EAX + 0x48c) = 1;
  *(undefined4 *)(in_EAX + 0x16a4) = 0;
  *(undefined4 *)(in_EAX + 0x16a0) = 0;
  *(undefined4 *)(in_EAX + 0x16a8) = 0;
  *(undefined4 *)(in_EAX + 0x1698) = 0;
  return;
}


// ==== FUN_0095afd4 @ 0x0095afd4 ====

void FUN_0095afd4(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_EAX;
  int iVar6;
  int iVar7;
  int unaff_EDI;
  bool bVar8;
  
  iVar3 = *(int *)(in_EAX + 0xb54 + param_1 * 4);
  iVar6 = *(int *)(in_EAX + 0x1448);
  iVar7 = param_1 * 2;
  bVar8 = SBORROW4(iVar7,iVar6);
  iVar5 = iVar7 - iVar6;
  if (iVar7 <= iVar6) {
    do {
      iVar6 = iVar7;
      if (bVar8 != iVar5 < 0) {
        iVar5 = *(int *)(in_EAX + 0xb58 + iVar7 * 4);
        uVar1 = *(ushort *)(unaff_EDI + iVar5 * 4);
        uVar2 = *(ushort *)(unaff_EDI + *(int *)(in_EAX + 0xb54 + iVar7 * 4) * 4);
        if ((uVar1 < uVar2) ||
           ((uVar1 == uVar2 &&
            (*(byte *)(iVar5 + 0x1450 + in_EAX) <=
             *(byte *)(*(int *)(in_EAX + 0xb54 + iVar7 * 4) + 0x1450 + in_EAX))))) {
          iVar6 = iVar7 + 1;
        }
      }
      iVar5 = *(int *)(in_EAX + 0xb54 + iVar6 * 4);
      uVar1 = *(ushort *)(unaff_EDI + iVar3 * 4);
      uVar2 = *(ushort *)(unaff_EDI + iVar5 * 4);
      if ((uVar1 < uVar2) ||
         ((uVar1 == uVar2 &&
          (*(byte *)(iVar3 + 0x1450 + in_EAX) <= *(byte *)(iVar5 + 0x1450 + in_EAX))))) break;
      *(int *)(in_EAX + 0xb54 + param_1 * 4) = iVar5;
      iVar4 = *(int *)(in_EAX + 0x1448);
      iVar7 = iVar6 * 2;
      bVar8 = SBORROW4(iVar7,iVar4);
      iVar5 = iVar7 - iVar4;
      param_1 = iVar6;
    } while (iVar7 <= iVar4);
  }
  *(int *)(in_EAX + 0xb54 + param_1 * 4) = iVar3;
  return;
}


// ==== FUN_0095b088 @ 0x0095b088 ====

void FUN_0095b088(void)

{
  ushort *puVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *in_EAX;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int in_EDX;
  int *piVar13;
  undefined4 *puVar14;
  short *psVar15;
  int local_20;
  int *local_18;
  ushort *local_14;
  uint local_8;
  
  iVar3 = in_EAX[1];
  local_8 = 0;
  iVar4 = *in_EAX;
  piVar13 = (int *)in_EAX[2];
  iVar12 = *piVar13;
  iVar5 = piVar13[1];
  iVar6 = piVar13[2];
  uVar7 = piVar13[4];
  puVar14 = (undefined4 *)(in_EDX + 0xb34);
  for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar14 = 0;
    puVar14 = puVar14 + 1;
  }
  *(undefined2 *)(iVar4 + 2 + *(int *)(in_EDX + 0xb54 + *(int *)(in_EDX + 0x144c) * 4) * 4) = 0;
  iVar9 = *(int *)(in_EDX + 0x144c) + 1;
  if (iVar9 < 0x23d) {
    local_18 = (int *)(in_EDX + 0xb54 + iVar9 * 4);
    local_20 = 0x23d - iVar9;
    iVar9 = iVar9 + local_20;
    do {
      iVar8 = *local_18;
      iVar10 = iVar8 * 4;
      uVar11 = *(ushort *)(iVar4 + 2 + (uint)*(ushort *)(iVar10 + 2 + iVar4) * 4) + 1;
      if ((int)uVar7 < (int)uVar11) {
        local_8 = local_8 + 1;
        uVar11 = uVar7;
      }
      *(short *)(iVar10 + 2 + iVar4) = (short)uVar11;
      if (iVar8 <= iVar3) {
        psVar15 = (short *)(in_EDX + 0xb34 + uVar11 * 2);
        *psVar15 = *psVar15 + 1;
        local_14 = (ushort *)0x0;
        if (iVar6 <= iVar8) {
          local_14 = *(ushort **)(iVar5 + (iVar8 - iVar6) * 4);
        }
        uVar2 = *(ushort *)(iVar10 + iVar4);
        *(int *)(in_EDX + 0x16a0) =
             *(int *)(in_EDX + 0x16a0) + ((int)local_14 + uVar11) * (uint)uVar2;
        if (iVar12 != 0) {
          *(int *)(in_EDX + 0x16a4) =
               *(int *)(in_EDX + 0x16a4) +
               ((uint)*(ushort *)(iVar10 + 2 + iVar12) + (int)local_14) * (uint)uVar2;
        }
      }
      local_18 = local_18 + 1;
      local_20 = local_20 + -1;
    } while (local_20 != 0);
    if (local_8 != 0) {
      local_14 = (ushort *)(in_EDX + 0xb34 + uVar7 * 2);
      do {
        iVar12 = uVar7 - 1;
        for (psVar15 = (short *)(in_EDX + 0xb34 + iVar12 * 2); *psVar15 == 0; psVar15 = psVar15 + -1
            ) {
          iVar12 = iVar12 + -1;
        }
        psVar15 = (short *)(in_EDX + 0xb34 + iVar12 * 2);
        *psVar15 = *psVar15 + -1;
        local_8 = local_8 + -2;
        psVar15 = (short *)(in_EDX + 0xb36 + iVar12 * 2);
        *psVar15 = *psVar15 + 2;
        *local_14 = *local_14 - 1;
      } while (0 < (int)local_8);
      if (uVar7 != 0) {
        local_8 = uVar7;
        do {
          local_18 = (int *)(uint)*local_14;
          if (local_18 != (int *)0x0) {
            piVar13 = (int *)(in_EDX + 0xb54 + iVar9 * 4);
            do {
              piVar13 = piVar13 + -1;
              iVar9 = iVar9 + -1;
              if (*piVar13 <= iVar3) {
                puVar1 = (ushort *)(iVar4 + *piVar13 * 4);
                if (puVar1[1] != local_8) {
                  *(int *)(in_EDX + 0x16a0) =
                       *(int *)(in_EDX + 0x16a0) + (local_8 - puVar1[1]) * (uint)*puVar1;
                  puVar1[1] = (ushort)local_8;
                }
                local_18 = (int *)((int)local_18 - 1);
              }
            } while (local_18 != (int *)0x0);
          }
          local_8 = local_8 - 1;
          local_14 = local_14 + -1;
        } while (local_8 != 0);
      }
    }
  }
  return;
}


// ==== scan_tree @ 0x0095b242 ====

/* Library Function - Single Match
    _scan_tree@12
   
   Library: Visual Studio 2005 Release
   __stdcall scan_tree,12 */

void scan_tree(int param_1)

{
  short *psVar1;
  ushort uVar2;
  int in_EAX;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iStack_1c;
  uint local_c;
  ushort *local_8;
  
  local_c = 0xffffffff;
  uVar2 = *(ushort *)(in_EAX + 2);
  iVar5 = 7;
  iVar6 = 0;
  iStack_1c = 4;
  if (uVar2 == 0) {
    iVar5 = 0x8a;
    iStack_1c = 3;
  }
  *(undefined2 *)(in_EAX + 6 + in_ECX * 4) = 0xffff;
  if (-1 < in_ECX) {
    local_8 = (ushort *)(in_EAX + 6);
    iVar7 = in_ECX + 1;
    uVar3 = (uint)uVar2;
    do {
      uVar4 = (uint)*local_8;
      iVar6 = iVar6 + 1;
      if ((iVar5 <= iVar6) || (uVar3 != uVar4)) {
        if (iVar6 < iStack_1c) {
          psVar1 = (short *)(param_1 + 0xa74 + uVar3 * 4);
          *psVar1 = *psVar1 + (short)iVar6;
        }
        else if (uVar3 == 0) {
          if (iVar6 < 0xb) {
            *(short *)(param_1 + 0xab8) = *(short *)(param_1 + 0xab8) + 1;
          }
          else {
            *(short *)(param_1 + 0xabc) = *(short *)(param_1 + 0xabc) + 1;
          }
        }
        else {
          if (uVar3 != local_c) {
            psVar1 = (short *)(param_1 + 0xa74 + uVar3 * 4);
            *psVar1 = *psVar1 + 1;
          }
          *(short *)(param_1 + 0xab4) = *(short *)(param_1 + 0xab4) + 1;
        }
        iVar6 = 0;
        if (uVar4 == 0) {
          iVar5 = 0x8a;
LAB_0095b2ea:
          iStack_1c = 3;
        }
        else {
          if (uVar3 == uVar4) {
            iVar5 = 6;
            goto LAB_0095b2ea;
          }
          iVar5 = 7;
          iStack_1c = 4;
        }
        local_c = uVar3;
      }
      local_8 = local_8 + 2;
      iVar7 = iVar7 + -1;
      uVar3 = uVar4;
    } while (iVar7 != 0);
  }
  return;
}


// ==== FUN_0095b302 @ 0x0095b302 ====

void FUN_0095b302(void)

{
  ushort uVar1;
  int in_EAX;
  byte bVar2;
  int in_ECX;
  uint uVar3;
  int in_EDX;
  ushort uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iStack_2c;
  int local_1c;
  uint local_18;
  ushort *local_10;
  uint local_c;
  int local_8;
  
  local_18 = 0xffffffff;
  iVar6 = 7;
  iStack_2c = 4;
  if (*(ushort *)(in_ECX + 2) == 0) {
    iVar6 = 0x8a;
    iStack_2c = 3;
  }
  if (-1 < in_EDX) {
    local_10 = (ushort *)(in_ECX + 6);
    local_1c = in_EDX + 1;
    iVar5 = 0;
    local_c = (uint)*(ushort *)(in_ECX + 2);
    do {
      uVar3 = (uint)*local_10;
      local_8 = iVar5 + 1;
      if ((iVar6 <= local_8) || (local_c != uVar3)) {
        if (local_8 < iStack_2c) {
          do {
            uVar7 = (uint)*(ushort *)(in_EAX + 0xa76 + local_c * 4);
            bVar2 = (byte)*(int *)(in_EAX + 0x16b4);
            if ((int)(0x10 - uVar7) < *(int *)(in_EAX + 0x16b4)) {
              uVar4 = *(ushort *)(in_EAX + 0xa74 + local_c * 4);
              *(ushort *)(in_EAX + 0x16b0) = *(ushort *)(in_EAX + 0x16b0) | uVar4 << (bVar2 & 0x1f);
              *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                   *(undefined1 *)(in_EAX + 0x16b0);
              *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
              *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                   *(undefined1 *)(in_EAX + 0x16b1);
              *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
              iVar6 = *(int *)(in_EAX + 0x16b4) + -0x10;
              *(ushort *)(in_EAX + 0x16b0) =
                   uVar4 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);
            }
            else {
              iVar6 = *(int *)(in_EAX + 0x16b4);
              *(ushort *)(in_EAX + 0x16b0) =
                   *(ushort *)(in_EAX + 0x16b0) |
                   *(short *)(in_EAX + 0xa74 + local_c * 4) << (bVar2 & 0x1f);
            }
            local_8 = local_8 + -1;
            *(uint *)(in_EAX + 0x16b4) = iVar6 + uVar7;
          } while (local_8 != 0);
        }
        else {
          if (local_c == 0) {
            iVar6 = *(int *)(in_EAX + 0x16b4);
            bVar2 = (byte)iVar6;
            if (local_8 < 0xb) {
              uVar4 = *(ushort *)(in_EAX + 0xaba);
              if ((int)(0x10 - (uint)uVar4) < iVar6) {
                uVar1 = *(ushort *)(in_EAX + 0xab8);
                *(ushort *)(in_EAX + 0x16b0) =
                     *(ushort *)(in_EAX + 0x16b0) | uVar1 << (bVar2 & 0x1f);
                *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                     *(undefined1 *)(in_EAX + 0x16b0);
                *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
                *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                     *(undefined1 *)(in_EAX + 0x16b1);
                *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
                iVar6 = *(int *)(in_EAX + 0x16b4) + -0x10;
                *(ushort *)(in_EAX + 0x16b0) =
                     uVar1 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);
              }
              else {
                *(ushort *)(in_EAX + 0x16b0) =
                     *(ushort *)(in_EAX + 0x16b0) | *(short *)(in_EAX + 0xab8) << (bVar2 & 0x1f);
              }
              iVar6 = iVar6 + (uint)uVar4;
              iVar5 = iVar5 + -2;
              *(int *)(in_EAX + 0x16b4) = iVar6;
              if (iVar6 < 0xe) {
                *(ushort *)(in_EAX + 0x16b0) =
                     *(ushort *)(in_EAX + 0x16b0) | (ushort)(iVar5 << ((byte)iVar6 & 0x1f));
                iVar6 = iVar6 + 3;
                goto LAB_0095b766;
              }
              *(ushort *)(in_EAX + 0x16b0) =
                   *(ushort *)(in_EAX + 0x16b0) | (ushort)(iVar5 << ((byte)iVar6 & 0x1f));
              *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                   *(undefined1 *)(in_EAX + 0x16b0);
              *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
              *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                   *(undefined1 *)(in_EAX + 0x16b1);
              *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
              uVar4 = (ushort)iVar5 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);
              iVar6 = *(int *)(in_EAX + 0x16b4) + -0xd;
            }
            else {
              uVar4 = *(ushort *)(in_EAX + 0xabe);
              if ((int)(0x10 - (uint)uVar4) < iVar6) {
                uVar1 = *(ushort *)(in_EAX + 0xabc);
                *(ushort *)(in_EAX + 0x16b0) =
                     *(ushort *)(in_EAX + 0x16b0) | uVar1 << (bVar2 & 0x1f);
                *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                     *(undefined1 *)(in_EAX + 0x16b0);
                *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
                *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                     *(undefined1 *)(in_EAX + 0x16b1);
                *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
                iVar6 = *(int *)(in_EAX + 0x16b4) + -0x10;
                *(ushort *)(in_EAX + 0x16b0) =
                     uVar1 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);
              }
              else {
                *(ushort *)(in_EAX + 0x16b0) =
                     *(ushort *)(in_EAX + 0x16b0) | *(short *)(in_EAX + 0xabc) << (bVar2 & 0x1f);
              }
              iVar6 = iVar6 + (uint)uVar4;
              iVar5 = iVar5 + -10;
              *(int *)(in_EAX + 0x16b4) = iVar6;
              if (iVar6 < 10) {
                *(ushort *)(in_EAX + 0x16b0) =
                     *(ushort *)(in_EAX + 0x16b0) | (ushort)(iVar5 << ((byte)iVar6 & 0x1f));
                iVar6 = iVar6 + 7;
LAB_0095b766:
                *(int *)(in_EAX + 0x16b4) = iVar6;
                goto LAB_0095b76c;
              }
              *(ushort *)(in_EAX + 0x16b0) =
                   *(ushort *)(in_EAX + 0x16b0) | (ushort)(iVar5 << ((byte)iVar6 & 0x1f));
              *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                   *(undefined1 *)(in_EAX + 0x16b0);
              *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
              *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                   *(undefined1 *)(in_EAX + 0x16b1);
              *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
              uVar4 = (ushort)iVar5 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);
              iVar6 = *(int *)(in_EAX + 0x16b4) + -9;
            }
          }
          else {
            if (local_c != local_18) {
              uVar7 = (uint)*(ushort *)(in_EAX + 0xa76 + local_c * 4);
              bVar2 = (byte)*(int *)(in_EAX + 0x16b4);
              if ((int)(0x10 - uVar7) < *(int *)(in_EAX + 0x16b4)) {
                uVar4 = *(ushort *)(in_EAX + 0xa74 + local_c * 4);
                *(ushort *)(in_EAX + 0x16b0) =
                     *(ushort *)(in_EAX + 0x16b0) | uVar4 << (bVar2 & 0x1f);
                *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                     *(undefined1 *)(in_EAX + 0x16b0);
                *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
                *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                     *(undefined1 *)(in_EAX + 0x16b1);
                *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
                iVar6 = *(int *)(in_EAX + 0x16b4) + -0x10;
                *(ushort *)(in_EAX + 0x16b0) =
                     uVar4 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);
              }
              else {
                iVar6 = *(int *)(in_EAX + 0x16b4);
                *(ushort *)(in_EAX + 0x16b0) =
                     *(ushort *)(in_EAX + 0x16b0) |
                     *(short *)(in_EAX + 0xa74 + local_c * 4) << (bVar2 & 0x1f);
              }
              *(uint *)(in_EAX + 0x16b4) = iVar6 + uVar7;
              local_8 = iVar5;
            }
            uVar4 = *(ushort *)(in_EAX + 0xab6);
            iVar6 = *(int *)(in_EAX + 0x16b4);
            if ((int)(0x10 - (uint)uVar4) < iVar6) {
              uVar1 = *(ushort *)(in_EAX + 0xab4);
              *(ushort *)(in_EAX + 0x16b0) =
                   *(ushort *)(in_EAX + 0x16b0) | uVar1 << ((byte)iVar6 & 0x1f);
              *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                   *(undefined1 *)(in_EAX + 0x16b0);
              *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
              *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                   *(undefined1 *)(in_EAX + 0x16b1);
              *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
              iVar6 = *(int *)(in_EAX + 0x16b4) + -0x10;
              *(ushort *)(in_EAX + 0x16b0) =
                   uVar1 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);
            }
            else {
              *(ushort *)(in_EAX + 0x16b0) =
                   *(ushort *)(in_EAX + 0x16b0) | *(short *)(in_EAX + 0xab4) << ((byte)iVar6 & 0x1f)
              ;
            }
            iVar6 = iVar6 + (uint)uVar4;
            local_8 = local_8 + -3;
            *(int *)(in_EAX + 0x16b4) = iVar6;
            if (iVar6 < 0xf) {
              *(ushort *)(in_EAX + 0x16b0) =
                   *(ushort *)(in_EAX + 0x16b0) | (ushort)(local_8 << ((byte)iVar6 & 0x1f));
              iVar6 = iVar6 + 2;
              goto LAB_0095b766;
            }
            *(ushort *)(in_EAX + 0x16b0) =
                 *(ushort *)(in_EAX + 0x16b0) | (ushort)(local_8 << ((byte)iVar6 & 0x1f));
            *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                 *(undefined1 *)(in_EAX + 0x16b0);
            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
            *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                 *(undefined1 *)(in_EAX + 0x16b1);
            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
            uVar4 = (ushort)local_8 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);
            iVar6 = *(int *)(in_EAX + 0x16b4) + -0xe;
          }
          *(ushort *)(in_EAX + 0x16b0) = uVar4;
          *(int *)(in_EAX + 0x16b4) = iVar6;
        }
LAB_0095b76c:
        local_8 = 0;
        local_18 = local_c;
        if (uVar3 == 0) {
          iVar6 = 0x8a;
        }
        else {
          if (local_c != uVar3) {
            iVar6 = 7;
            iStack_2c = 4;
            goto LAB_0095b78f;
          }
          iVar6 = 6;
        }
        iStack_2c = 3;
      }
LAB_0095b78f:
      local_10 = local_10 + 2;
      local_1c = local_1c + -1;
      iVar5 = local_8;
      local_c = uVar3;
    } while (local_1c != 0);
  }
  return;
}


// ==== FUN_0095b7a1 @ 0x0095b7a1 ====

void FUN_0095b7a1(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  
  iVar3 = *(int *)(in_EAX + 0x16b4);
  if (iVar3 < 0xc) {
    *(ushort *)(in_EAX + 0x16b0) =
         *(ushort *)(in_EAX + 0x16b0) | (ushort)(param_1 + -0x101 << ((byte)iVar3 & 0x1f));
    *(int *)(in_EAX + 0x16b4) = iVar3 + 5;
  }
  else {
    *(ushort *)(in_EAX + 0x16b0) =
         *(ushort *)(in_EAX + 0x16b0) | (ushort)(param_1 + -0x101 << ((byte)iVar3 & 0x1f));
    *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
         *(undefined1 *)(in_EAX + 0x16b0);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
         *(undefined1 *)(in_EAX + 0x16b1);
    iVar3 = *(int *)(in_EAX + 0x16b4);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(int *)(in_EAX + 0x16b4) = iVar3 + -0xb;
    *(ushort *)(in_EAX + 0x16b0) = (ushort)(param_1 + -0x101) >> (0x10U - (char)iVar3 & 0x1f);
  }
  iVar3 = *(int *)(in_EAX + 0x16b4);
  if (iVar3 < 0xc) {
    *(ushort *)(in_EAX + 0x16b0) =
         *(ushort *)(in_EAX + 0x16b0) | (ushort)(param_2 + -1 << ((byte)iVar3 & 0x1f));
    *(int *)(in_EAX + 0x16b4) = iVar3 + 5;
  }
  else {
    *(ushort *)(in_EAX + 0x16b0) =
         *(ushort *)(in_EAX + 0x16b0) | (ushort)(param_2 + -1 << ((byte)iVar3 & 0x1f));
    *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
         *(undefined1 *)(in_EAX + 0x16b0);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
         *(undefined1 *)(in_EAX + 0x16b1);
    iVar3 = *(int *)(in_EAX + 0x16b4);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(int *)(in_EAX + 0x16b4) = iVar3 + -0xb;
    *(ushort *)(in_EAX + 0x16b0) = (ushort)(param_2 + -1) >> (0x10U - (char)iVar3 & 0x1f);
  }
  iVar3 = *(int *)(in_EAX + 0x16b4);
  if (iVar3 < 0xd) {
    *(ushort *)(in_EAX + 0x16b0) =
         *(ushort *)(in_EAX + 0x16b0) | (ushort)(param_3 + -4 << ((byte)iVar3 & 0x1f));
    *(int *)(in_EAX + 0x16b4) = iVar3 + 4;
  }
  else {
    *(ushort *)(in_EAX + 0x16b0) =
         *(ushort *)(in_EAX + 0x16b0) | (ushort)(param_3 + -4 << ((byte)iVar3 & 0x1f));
    *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
         *(undefined1 *)(in_EAX + 0x16b0);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
         *(undefined1 *)(in_EAX + 0x16b1);
    iVar3 = *(int *)(in_EAX + 0x16b4);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(int *)(in_EAX + 0x16b4) = iVar3 + -0xc;
    *(ushort *)(in_EAX + 0x16b0) = (ushort)(param_3 + -4) >> (0x10U - (char)iVar3 & 0x1f);
  }
  iVar3 = 0;
  if (0 < param_3) {
    do {
      iVar2 = *(int *)(in_EAX + 0x16b4);
      if (iVar2 < 0xe) {
        *(ushort *)(in_EAX + 0x16b0) =
             *(ushort *)(in_EAX + 0x16b0) |
             *(short *)(in_EAX + 0xa76 + (uint)(byte)(&DAT_00a2e754)[iVar3] * 4) <<
             ((byte)iVar2 & 0x1f);
        *(int *)(in_EAX + 0x16b4) = iVar2 + 3;
      }
      else {
        uVar1 = *(ushort *)(in_EAX + 0xa76 + (uint)(byte)(&DAT_00a2e754)[iVar3] * 4);
        *(ushort *)(in_EAX + 0x16b0) = *(ushort *)(in_EAX + 0x16b0) | uVar1 << ((byte)iVar2 & 0x1f);
        *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
             *(undefined1 *)(in_EAX + 0x16b0);
        *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
        *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
             *(undefined1 *)(in_EAX + 0x16b1);
        iVar2 = *(int *)(in_EAX + 0x16b4);
        *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
        *(int *)(in_EAX + 0x16b4) = iVar2 + -0xd;
        *(ushort *)(in_EAX + 0x16b0) = uVar1 >> (0x10U - (char)iVar2 & 0x1f);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_3);
  }
  FUN_0095b302();
  FUN_0095b302();
  return;
}


// ==== FUN_0095b9de @ 0x0095b9de ====

void FUN_0095b9de(int param_1,int param_2)

{
  ushort *puVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  int in_EAX;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  uVar5 = 0;
  if (*(int *)(in_EAX + 0x1698) != 0) {
    do {
      uVar12 = (uint)*(ushort *)(*(int *)(in_EAX + 0x169c) + uVar5 * 2);
      uVar11 = (uint)*(byte *)(uVar5 + *(int *)(in_EAX + 0x1690));
      uVar5 = uVar5 + 1;
      if (uVar12 == 0) {
        iVar6 = *(int *)(in_EAX + 0x16b4);
        puVar1 = (ushort *)(param_1 + uVar11 * 4);
        uVar11 = (uint)puVar1[1];
        if ((int)(0x10 - uVar11) < iVar6) {
          uVar3 = *puVar1;
          *(ushort *)(in_EAX + 0x16b0) =
               *(ushort *)(in_EAX + 0x16b0) | uVar3 << ((byte)iVar6 & 0x1f);
          *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
               *(undefined1 *)(in_EAX + 0x16b0);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
               *(undefined1 *)(in_EAX + 0x16b1);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          iVar6 = *(int *)(in_EAX + 0x16b4) + -0x10 + uVar11;
          *(ushort *)(in_EAX + 0x16b0) = uVar3 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);
        }
        else {
          *(ushort *)(in_EAX + 0x16b0) =
               *(ushort *)(in_EAX + 0x16b0) | *puVar1 << ((byte)iVar6 & 0x1f);
          iVar6 = iVar6 + uVar11;
        }
LAB_0095bce0:
        *(int *)(in_EAX + 0x16b4) = iVar6;
      }
      else {
        uVar10 = (uint)(byte)(&DAT_00a2ee60)[uVar11];
        iVar7 = uVar10 * 4;
        uVar8 = (uint)*(ushort *)(iVar7 + 0x406 + param_1);
        iVar9 = *(int *)(in_EAX + 0x16b4);
        if ((int)(0x10 - uVar8) < iVar9) {
          uVar3 = *(ushort *)(param_1 + 0x404 + uVar10 * 4);
          *(ushort *)(in_EAX + 0x16b0) =
               *(ushort *)(in_EAX + 0x16b0) | uVar3 << ((byte)iVar9 & 0x1f);
          *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
               *(undefined1 *)(in_EAX + 0x16b0);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
               *(undefined1 *)(in_EAX + 0x16b1);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          iVar9 = *(int *)(in_EAX + 0x16b4) + -0x10;
          *(ushort *)(in_EAX + 0x16b0) = uVar3 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);
        }
        else {
          *(ushort *)(in_EAX + 0x16b0) =
               *(ushort *)(in_EAX + 0x16b0) |
               *(short *)(param_1 + 0x404 + uVar10 * 4) << ((byte)iVar9 & 0x1f);
        }
        *(uint *)(in_EAX + 0x16b4) = iVar9 + uVar8;
        iVar9 = *(int *)(&DAT_00a2e618 + iVar7);
        if (iVar9 != 0) {
          iVar6 = uVar11 - *(int *)(&DAT_00a2ef60 + iVar7);
          iVar7 = *(int *)(in_EAX + 0x16b4);
          if (0x10 - iVar9 < iVar7) {
            *(ushort *)(in_EAX + 0x16b0) =
                 *(ushort *)(in_EAX + 0x16b0) | (ushort)(iVar6 << ((byte)iVar7 & 0x1f));
            *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                 *(undefined1 *)(in_EAX + 0x16b0);
            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
            *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                 *(undefined1 *)(in_EAX + 0x16b1);
            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
            iVar7 = *(int *)(in_EAX + 0x16b4) + -0x10;
            *(ushort *)(in_EAX + 0x16b0) =
                 (ushort)iVar6 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);
          }
          else {
            *(ushort *)(in_EAX + 0x16b0) =
                 *(ushort *)(in_EAX + 0x16b0) | (ushort)(iVar6 << ((byte)iVar7 & 0x1f));
          }
          *(int *)(in_EAX + 0x16b4) = iVar7 + iVar9;
        }
        uVar11 = uVar12 - 1;
        if (uVar11 < 0x100) {
          bVar2 = (&DAT_00a2ec5f)[uVar12];
        }
        else {
          bVar2 = (&DAT_00a2ed60)[uVar11 >> 7];
        }
        iVar7 = (uint)bVar2 * 4;
        puVar1 = (ushort *)(iVar7 + param_2);
        uVar3 = puVar1[1];
        iVar9 = *(int *)(in_EAX + 0x16b4);
        if ((int)(0x10 - (uint)uVar3) < iVar9) {
          uVar4 = *puVar1;
          *(ushort *)(in_EAX + 0x16b0) =
               *(ushort *)(in_EAX + 0x16b0) | uVar4 << ((byte)iVar9 & 0x1f);
          *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
               *(undefined1 *)(in_EAX + 0x16b0);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
               *(undefined1 *)(in_EAX + 0x16b1);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          iVar9 = *(int *)(in_EAX + 0x16b4) + -0x10;
          *(ushort *)(in_EAX + 0x16b0) = uVar4 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);
        }
        else {
          *(ushort *)(in_EAX + 0x16b0) =
               *(ushort *)(in_EAX + 0x16b0) | *puVar1 << ((byte)iVar9 & 0x1f);
        }
        iVar9 = iVar9 + (uint)uVar3;
        *(int *)(in_EAX + 0x16b4) = iVar9;
        iVar6 = *(int *)(&DAT_00a2e690 + iVar7);
        if (iVar6 != 0) {
          iVar7 = uVar11 - *(int *)(&DAT_00a2efd8 + iVar7);
          if (0x10 - iVar6 < iVar9) {
            *(ushort *)(in_EAX + 0x16b0) =
                 *(ushort *)(in_EAX + 0x16b0) | (ushort)(iVar7 << ((byte)iVar9 & 0x1f));
            *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                 *(undefined1 *)(in_EAX + 0x16b0);
            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
            *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                 *(undefined1 *)(in_EAX + 0x16b1);
            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
            iVar6 = *(int *)(in_EAX + 0x16b4) + -0x10 + iVar6;
            *(ushort *)(in_EAX + 0x16b0) =
                 (ushort)iVar7 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);
          }
          else {
            *(ushort *)(in_EAX + 0x16b0) =
                 *(ushort *)(in_EAX + 0x16b0) | (ushort)(iVar7 << ((byte)iVar9 & 0x1f));
            iVar6 = iVar9 + iVar6;
          }
          goto LAB_0095bce0;
        }
      }
    } while (uVar5 < *(uint *)(in_EAX + 0x1698));
  }
  uVar3 = *(ushort *)(param_1 + 0x402);
  iVar9 = *(int *)(in_EAX + 0x16b4);
  if ((int)(0x10 - (uint)uVar3) < iVar9) {
    uVar4 = *(ushort *)(param_1 + 0x400);
    *(ushort *)(in_EAX + 0x16b0) = *(ushort *)(in_EAX + 0x16b0) | uVar4 << ((byte)iVar9 & 0x1f);
    *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
         *(undefined1 *)(in_EAX + 0x16b0);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
         *(undefined1 *)(in_EAX + 0x16b1);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    iVar9 = *(int *)(in_EAX + 0x16b4) + -0x10;
    *(ushort *)(in_EAX + 0x16b0) = uVar4 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);
  }
  else {
    *(ushort *)(in_EAX + 0x16b0) =
         *(ushort *)(in_EAX + 0x16b0) | *(short *)(param_1 + 0x400) << ((byte)iVar9 & 0x1f);
  }
  *(uint *)(in_EAX + 0x16b4) = iVar9 + (uint)uVar3;
  *(uint *)(in_EAX + 0x16ac) = (uint)*(ushort *)(param_1 + 0x402);
  return;
}


// ==== FUN_0095bd94 @ 0x0095bd94 ====

void FUN_0095bd94(void)

{
  ushort *puVar1;
  int in_ECX;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = 0;
  uVar4 = 0;
  puVar1 = (ushort *)(in_ECX + 0x8c);
  iVar3 = 7;
  do {
    uVar4 = uVar4 + *puVar1;
    puVar1 = puVar1 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar1 = (ushort *)(in_ECX + 0xa8);
  iVar3 = 0x79;
  do {
    uVar2 = uVar2 + *puVar1;
    puVar1 = puVar1 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar1 = (ushort *)(in_ECX + 0x28c);
  iVar3 = 0x80;
  do {
    uVar4 = uVar4 + *puVar1;
    puVar1 = puVar1 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(char *)(in_ECX + 0x1c) = '\x01' - (uVar2 >> 2 < uVar4);
  return;
}


// ==== FUN_0095bdeb @ 0x0095bdeb ====

void FUN_0095bdeb(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x16b4) == 0x10) {
    *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
         *(undefined1 *)(in_EAX + 0x16b0);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
         *(undefined1 *)(in_EAX + 0x16b1);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(undefined2 *)(in_EAX + 0x16b0) = 0;
    *(undefined4 *)(in_EAX + 0x16b4) = 0;
    return;
  }
  if (7 < *(int *)(in_EAX + 0x16b4)) {
    *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
         *(undefined1 *)(in_EAX + 0x16b0);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(int *)(in_EAX + 0x16b4) = *(int *)(in_EAX + 0x16b4) + -8;
    *(ushort *)(in_EAX + 0x16b0) = (ushort)*(byte *)(in_EAX + 0x16b1);
  }
  return;
}


// ==== FUN_0095be58 @ 0x0095be58 ====

void FUN_0095be58(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x16b4) < 9) {
    if (*(int *)(in_EAX + 0x16b4) < 1) goto LAB_0095be9e;
    *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
         *(undefined1 *)(in_EAX + 0x16b0);
  }
  else {
    *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
         *(undefined1 *)(in_EAX + 0x16b0);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
         *(undefined1 *)(in_EAX + 0x16b1);
  }
  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
LAB_0095be9e:
  *(undefined2 *)(in_EAX + 0x16b0) = 0;
  *(undefined4 *)(in_EAX + 0x16b4) = 0;
  return;
}


// ==== FUN_0095beaf @ 0x0095beaf ====

void FUN_0095beaf(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined1 *in_EDX;
  byte bVar2;
  
  iVar1 = FUN_0095be58();
  *(undefined4 *)(iVar1 + 0x16ac) = 8;
  if (param_1 != 0) {
    *(byte *)(*(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 8)) = (byte)in_ECX;
    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
    bVar2 = (byte)((uint)in_ECX >> 8);
    *(byte *)(*(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 8)) = bVar2;
    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
    *(byte *)(*(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 8)) = ~(byte)in_ECX;
    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
    *(byte *)(*(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 8)) = ~bVar2;
    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
  }
  for (; in_ECX != 0; in_ECX = in_ECX + -1) {
    *(undefined1 *)(*(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 8)) = *in_EDX;
    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
    in_EDX = in_EDX + 1;
  }
  return;
}


// ==== FUN_0095bf2b @ 0x0095bf2b ====

void FUN_0095bf2b(int param_1)

{
  *(undefined2 *)(param_1 + 0x16b0) = 0;
  *(undefined4 *)(param_1 + 0x16b4) = 0;
  *(int *)(param_1 + 0xb10) = param_1 + 0x8c;
  *(int *)(param_1 + 0xb1c) = param_1 + 0x980;
  *(undefined ***)(param_1 + 0xb18) = &PTR_DAT_00a2f050;
  *(undefined ***)(param_1 + 0xb24) = &PTR_DAT_00a2f064;
  *(int *)(param_1 + 0xb28) = param_1 + 0xa74;
  *(undefined **)(param_1 + 0xb30) = &DAT_00a2f078;
  *(undefined4 *)(param_1 + 0x16ac) = 8;
  FUN_0095af74();
  return;
}


// ==== FUN_0095bf97 @ 0x0095bf97 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0095bf97(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int unaff_EDI;
  ushort auStack_28 [16];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  iVar7 = 0;
  uVar3 = 0;
  iVar5 = 1;
  do {
    uVar3 = (*(short *)(param_2 + iVar5 * 2 + -2) + uVar3) * 2;
    auStack_28[iVar5] = uVar3;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x10);
  if (-1 < param_1) {
    do {
      uVar6 = (uint)*(ushort *)(unaff_EDI + 2 + iVar7 * 4);
      if (uVar6 != 0) {
        uVar3 = auStack_28[uVar6];
        uVar8 = (uint)uVar3;
        auStack_28[uVar6] = uVar3 + 1;
        uVar1 = 0;
        do {
          uVar2 = uVar1;
          uVar4 = uVar8 & 1;
          uVar8 = uVar8 >> 1;
          uVar6 = uVar6 - 1;
          uVar1 = (uVar2 | uVar4) << 1;
        } while (0 < (int)uVar6);
        *(ushort *)(unaff_EDI + iVar7 * 4) = (ushort)uVar2 | (ushort)uVar4;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 <= param_1);
  }
  return;
}


// ==== FUN_0095c01c @ 0x0095c01c ====

void FUN_0095c01c(int *param_1)

{
  short *psVar1;
  short *psVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  byte bVar6;
  int in_EAX;
  int iVar7;
  int iVar8;
  int local_10;
  int local_c;
  
  local_c = -1;
  local_10 = ((int *)param_1[2])[3];
  iVar8 = *(int *)param_1[2];
  iVar7 = 0;
  iVar4 = *param_1;
  *(undefined4 *)(in_EAX + 0x1448) = 0;
  *(undefined4 *)(in_EAX + 0x144c) = 0x23d;
  if (0 < local_10) {
    do {
      if (*(short *)(iVar4 + iVar7 * 4) == 0) {
        *(undefined2 *)(iVar4 + 2 + iVar7 * 4) = 0;
      }
      else {
        *(int *)(in_EAX + 0x1448) = *(int *)(in_EAX + 0x1448) + 1;
        *(int *)(in_EAX + 0xb54 + *(int *)(in_EAX + 0x1448) * 4) = iVar7;
        *(undefined1 *)(iVar7 + 0x1450 + in_EAX) = 0;
        local_c = iVar7;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < local_10);
  }
  while (*(int *)(in_EAX + 0x1448) < 2) {
    if (local_c < 2) {
      iVar7 = local_c + 1;
      local_c = iVar7;
    }
    else {
      iVar7 = 0;
    }
    *(int *)(in_EAX + 0x1448) = *(int *)(in_EAX + 0x1448) + 1;
    *(int *)(in_EAX + 0xb54 + *(int *)(in_EAX + 0x1448) * 4) = iVar7;
    *(undefined2 *)(iVar7 * 4 + iVar4) = 1;
    *(undefined1 *)(in_EAX + 0x1450 + iVar7) = 0;
    *(int *)(in_EAX + 0x16a0) = *(int *)(in_EAX + 0x16a0) + -1;
    if (iVar8 != 0) {
      *(int *)(in_EAX + 0x16a4) =
           *(int *)(in_EAX + 0x16a4) - (uint)*(ushort *)(iVar7 * 4 + 2 + iVar8);
    }
  }
  param_1[1] = local_c;
  for (iVar8 = *(int *)(in_EAX + 0x1448) / 2; 0 < iVar8; iVar8 = iVar8 + -1) {
    FUN_0095afd4(iVar8);
  }
  do {
    uVar5 = *(undefined4 *)(in_EAX + 0xb54 + *(int *)(in_EAX + 0x1448) * 4);
    iVar8 = *(int *)(in_EAX + 0xb58);
    *(int *)(in_EAX + 0x1448) = *(int *)(in_EAX + 0x1448) + -1;
    *(undefined4 *)(in_EAX + 0xb58) = uVar5;
    FUN_0095afd4(1);
    *(int *)(in_EAX + 0x144c) = *(int *)(in_EAX + 0x144c) + -1;
    iVar7 = *(int *)(in_EAX + 0xb58);
    *(int *)(in_EAX + 0xb54 + *(int *)(in_EAX + 0x144c) * 4) = iVar8;
    *(int *)(in_EAX + 0x144c) = *(int *)(in_EAX + 0x144c) + -1;
    *(int *)(in_EAX + 0xb54 + *(int *)(in_EAX + 0x144c) * 4) = iVar7;
    psVar1 = (short *)(iVar4 + iVar7 * 4);
    psVar2 = (short *)(iVar4 + iVar8 * 4);
    *(short *)(iVar4 + local_10 * 4) = *psVar1 + *psVar2;
    bVar3 = *(byte *)(in_EAX + 0x1450 + iVar8);
    bVar6 = *(byte *)(in_EAX + 0x1450 + iVar7);
    if (bVar6 <= bVar3) {
      bVar6 = bVar3;
    }
    *(byte *)(in_EAX + 0x1450 + local_10) = bVar6 + 1;
    psVar1[1] = (short)local_10;
    psVar2[1] = (short)local_10;
    *(int *)(in_EAX + 0xb58) = local_10;
    local_10 = local_10 + 1;
    FUN_0095afd4(1);
  } while (1 < *(int *)(in_EAX + 0x1448));
  *(int *)(in_EAX + 0x144c) = *(int *)(in_EAX + 0x144c) + -1;
  *(undefined4 *)(in_EAX + 0xb54 + *(int *)(in_EAX + 0x144c) * 4) = *(undefined4 *)(in_EAX + 0xb58);
  FUN_0095b088();
  FUN_0095bf97(local_c,in_EAX + 0xb34);
  return;
}


// ==== FUN_0095c204 @ 0x0095c204 ====

void FUN_0095c204(void)

{
  int iVar1;
  int unaff_ESI;
  
  scan_tree(unaff_ESI);
  scan_tree(unaff_ESI);
  FUN_0095c01c(unaff_ESI + 0xb28);
  iVar1 = 0x12;
  do {
    if (*(short *)(unaff_ESI + 0xa76 + (uint)(byte)(&DAT_00a2e754)[iVar1] * 4) != 0) break;
    iVar1 = iVar1 + -1;
  } while (2 < iVar1);
  *(int *)(unaff_ESI + 0x16a0) = *(int *)(unaff_ESI + 0x16a0) + iVar1 * 3 + 0x11;
  return;
}


// ==== FUN_0095c25c @ 0x0095c25c ====

void FUN_0095c25c(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x16b4);
  if (iVar1 < 0xe) {
    *(ushort *)(param_1 + 0x16b0) =
         *(ushort *)(param_1 + 0x16b0) | (ushort)(param_4 << ((byte)iVar1 & 0x1f));
    *(int *)(param_1 + 0x16b4) = iVar1 + 3;
  }
  else {
    *(ushort *)(param_1 + 0x16b0) =
         *(ushort *)(param_1 + 0x16b0) | (ushort)(param_4 << ((byte)iVar1 & 0x1f));
    *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
         *(undefined1 *)(param_1 + 0x16b0);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
         *(undefined1 *)(param_1 + 0x16b1);
    iVar1 = *(int *)(param_1 + 0x16b4);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x16b4) = iVar1 + -0xd;
    *(ushort *)(param_1 + 0x16b0) = (ushort)param_4 >> (0x10U - (char)iVar1 & 0x1f);
  }
  FUN_0095beaf(1);
  return;
}


// ==== FUN_0095c2ea @ 0x0095c2ea ====

void FUN_0095c2ea(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x16b4);
  *(ushort *)(param_1 + 0x16b0) =
       *(ushort *)(param_1 + 0x16b0) | (ushort)(2 << ((byte)iVar1 & 0x1f));
  if (iVar1 < 0xe) {
    *(int *)(param_1 + 0x16b4) = iVar1 + 3;
  }
  else {
    *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
         *(undefined1 *)(param_1 + 0x16b0);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
         *(undefined1 *)(param_1 + 0x16b1);
    iVar1 = *(int *)(param_1 + 0x16b4);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x16b4) = iVar1 + -0xd;
    *(ushort *)(param_1 + 0x16b0) = 2 >> (0x10U - (char)iVar1 & 0x1f);
  }
  iVar1 = *(int *)(param_1 + 0x16b4);
  *(ushort *)(param_1 + 0x16b0) =
       *(ushort *)(param_1 + 0x16b0) | (ushort)(0 << ((byte)iVar1 & 0x1f));
  if (iVar1 < 10) {
    *(int *)(param_1 + 0x16b4) = iVar1 + 7;
  }
  else {
    *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
         *(undefined1 *)(param_1 + 0x16b0);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
         *(undefined1 *)(param_1 + 0x16b1);
    iVar1 = *(int *)(param_1 + 0x16b4);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x16b4) = iVar1 + -9;
    *(ushort *)(param_1 + 0x16b0) = 0 >> (0x10U - (char)iVar1 & 0x1f);
  }
  iVar2 = FUN_0095bdeb();
  iVar1 = *(int *)(iVar2 + 0x16b4);
  if ((*(int *)(iVar2 + 0x16ac) - iVar1) + 0xb < 9) {
    *(ushort *)(iVar2 + 0x16b0) = *(ushort *)(iVar2 + 0x16b0) | (ushort)(2 << ((byte)iVar1 & 0x1f));
    if (iVar1 < 0xe) {
      *(int *)(iVar2 + 0x16b4) = iVar1 + 3;
    }
    else {
      *(undefined1 *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0x14)) =
           *(undefined1 *)(iVar2 + 0x16b0);
      *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + 1;
      *(undefined1 *)(*(int *)(iVar2 + 0x14) + *(int *)(iVar2 + 8)) =
           *(undefined1 *)(iVar2 + 0x16b1);
      iVar1 = *(int *)(iVar2 + 0x16b4);
      *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + 1;
      *(int *)(iVar2 + 0x16b4) = iVar1 + -0xd;
      *(ushort *)(iVar2 + 0x16b0) = 2 >> (0x10U - (char)iVar1 & 0x1f);
    }
    iVar1 = *(int *)(iVar2 + 0x16b4);
    *(ushort *)(iVar2 + 0x16b0) = *(ushort *)(iVar2 + 0x16b0) | (ushort)(0 << ((byte)iVar1 & 0x1f));
    if (iVar1 < 10) {
      *(int *)(iVar2 + 0x16b4) = iVar1 + 7;
    }
    else {
      *(undefined1 *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0x14)) =
           *(undefined1 *)(iVar2 + 0x16b0);
      *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + 1;
      *(undefined1 *)(*(int *)(iVar2 + 0x14) + *(int *)(iVar2 + 8)) =
           *(undefined1 *)(iVar2 + 0x16b1);
      iVar1 = *(int *)(iVar2 + 0x16b4);
      *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + 1;
      *(int *)(iVar2 + 0x16b4) = iVar1 + -9;
      *(ushort *)(iVar2 + 0x16b0) = 0 >> (0x10U - (char)iVar1 & 0x1f);
    }
    iVar2 = FUN_0095bdeb();
  }
  *(undefined4 *)(iVar2 + 0x16ac) = 7;
  return;
}


// ==== FUN_0095c4b8 @ 0x0095c4b8 ====

void FUN_0095c4b8(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined *puVar7;
  undefined *puVar8;
  
  iVar2 = 0;
  if (*(int *)(param_1 + 0x7c) < 1) {
    uVar4 = param_3 + 5;
  }
  else {
    if (*(char *)(param_1 + 0x1c) == '\x02') {
      FUN_0095bd94();
    }
    FUN_0095c01c(param_1 + 0xb10);
    FUN_0095c01c(param_1 + 0xb1c);
    iVar2 = FUN_0095c204();
    uVar5 = *(int *)(param_1 + 0x16a0) + 10U >> 3;
    uVar4 = *(int *)(param_1 + 0x16a4) + 10U >> 3;
    if (uVar5 < uVar4) goto LAB_0095c51d;
  }
  uVar5 = uVar4;
LAB_0095c51d:
  if ((uVar5 < param_3 + 4U) || (param_2 == 0)) {
    iVar1 = *(int *)(param_1 + 0x16b4);
    bVar3 = (byte)iVar1;
    if (uVar4 == uVar5) {
      iVar2 = param_4 + 2;
      if (iVar1 < 0xe) {
        *(ushort *)(param_1 + 0x16b0) =
             *(ushort *)(param_1 + 0x16b0) | (ushort)(iVar2 << (bVar3 & 0x1f));
        *(int *)(param_1 + 0x16b4) = iVar1 + 3;
      }
      else {
        *(ushort *)(param_1 + 0x16b0) =
             *(ushort *)(param_1 + 0x16b0) | (ushort)(iVar2 << (bVar3 & 0x1f));
        *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
             *(undefined1 *)(param_1 + 0x16b0);
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
             *(undefined1 *)(param_1 + 0x16b1);
        iVar1 = *(int *)(param_1 + 0x16b4);
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        *(int *)(param_1 + 0x16b4) = iVar1 + -0xd;
        *(ushort *)(param_1 + 0x16b0) = (ushort)iVar2 >> (0x10U - (char)iVar1 & 0x1f);
      }
      puVar8 = &DAT_00a2ebe8;
      puVar7 = &DAT_00a2e768;
    }
    else {
      iVar6 = param_4 + 4;
      if (iVar1 < 0xe) {
        *(ushort *)(param_1 + 0x16b0) =
             *(ushort *)(param_1 + 0x16b0) | (ushort)(iVar6 << (bVar3 & 0x1f));
        *(int *)(param_1 + 0x16b4) = iVar1 + 3;
      }
      else {
        *(ushort *)(param_1 + 0x16b0) =
             *(ushort *)(param_1 + 0x16b0) | (ushort)(iVar6 << (bVar3 & 0x1f));
        *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
             *(undefined1 *)(param_1 + 0x16b0);
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
             *(undefined1 *)(param_1 + 0x16b1);
        iVar1 = *(int *)(param_1 + 0x16b4);
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        *(int *)(param_1 + 0x16b4) = iVar1 + -0xd;
        *(ushort *)(param_1 + 0x16b0) = (ushort)iVar6 >> (0x10U - (char)iVar1 & 0x1f);
      }
      FUN_0095b7a1(*(int *)(param_1 + 0xb14) + 1,*(int *)(param_1 + 0xb20) + 1,iVar2 + 1);
      puVar8 = (undefined *)(param_1 + 0x980);
      puVar7 = (undefined *)(param_1 + 0x8c);
    }
    FUN_0095b9de(puVar7,puVar8);
  }
  else {
    FUN_0095c25c(param_1,param_2,param_3,param_4);
  }
  FUN_0095af74();
  if (param_4 != 0) {
    FUN_0095be58();
  }
  return;
}


// ==== FUN_0095c673 @ 0x0095c673 ====

void FUN_0095c673(undefined4 param_1,int param_2,int param_3)

{
  SIZE_T dwBytes;
  HANDLE hHeap;
  DWORD dwFlags;
  
  dwBytes = param_2 * param_3;
  dwFlags = 8;
  hHeap = GetProcessHeap();
  HeapAlloc(hHeap,dwFlags,dwBytes);
  return;
}


// ==== FUN_0095c693 @ 0x0095c693 ====

void FUN_0095c693(undefined4 param_1,LPVOID param_2)

{
  HANDLE hHeap;
  DWORD dwFlags;
  
  dwFlags = 0;
  hHeap = GetProcessHeap();
  HeapFree(hHeap,dwFlags,param_2);
  return;
}


// ==== FUN_0095c6ae @ 0x0095c6ae ====

void FUN_0095c6ae(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  
  if (param_3 != (int *)0x0) {
    *param_3 = param_1[0xf];
  }
  if ((*param_1 == 4) || (*param_1 == 5)) {
    (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),param_1[3]);
  }
  if (*param_1 == 6) {
    FUN_009619f9(param_1[1],param_2);
  }
  param_1[0xd] = param_1[10];
  param_1[0xc] = param_1[10];
  *param_1 = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  if ((code *)param_1[0xe] != (code *)0x0) {
    iVar1 = (*(code *)param_1[0xe])(0,0,0);
    param_1[0xf] = iVar1;
    *(int *)(param_2 + 0x30) = iVar1;
  }
  return;
}


// ==== FUN_0095c717 @ 0x0095c717 ====

undefined4 * FUN_0095c717(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x40);
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),8,0x5a0);
    puVar1[9] = iVar2;
    if (iVar2 != 0) {
      iVar2 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,param_3);
      puVar1[10] = iVar2;
      if (iVar2 == 0) {
        (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),puVar1[9]);
        (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),puVar1);
        return (undefined4 *)0x0;
      }
      *puVar1 = 0;
      puVar1[0xb] = iVar2 + param_3;
      puVar1[0xe] = param_2;
      FUN_0095c6ae(puVar1,param_1,0);
      return puVar1;
    }
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),puVar1);
  }
  return (undefined4 *)0x0;
}


// ==== FUN_0095c798 @ 0x0095c798 ====

void FUN_0095c798(uint *param_1,int *param_2,byte *param_3)

{
  uint *puVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  uint *puVar5;
  byte *pbVar6;
  undefined4 uVar7;
  uint uVar8;
  byte *pbVar9;
  undefined4 local_38;
  undefined4 local_34;
  byte *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  byte *local_1c;
  byte *local_18;
  byte *local_14;
  byte *local_10;
  byte *local_c;
  uint local_8;
  
  puVar5 = param_1;
  local_c = (byte *)param_2[1];
  local_8 = param_1[8];
  puVar1 = param_1 + 7;
  local_10 = (byte *)param_1[0xd];
  local_18 = (byte *)*param_2;
  if (local_10 < (byte *)param_1[0xc]) {
    local_14 = (byte *)param_1[0xc] + (-1 - (int)local_10);
  }
  else {
    local_14 = (byte *)(param_1[0xb] - (int)local_10);
  }
  uVar8 = *param_1;
  param_1 = (uint *)*puVar1;
  if (uVar8 < 10) {
    do {
      pbVar9 = local_18;
      switch((&switchD_0095c815::switchdataD_0095cebe)[uVar8]) {
      case (undefined *)0x95c840:
        for (; pbVar9 = local_18, param_1 < (byte *)0x3; param_1 = (uint *)((int)param_1 + 8)) {
          if (local_c == (byte *)0x0) goto LAB_0095ce15;
          param_3 = (byte *)0x0;
          local_c = local_c + -1;
          local_8 = local_8 | (uint)*local_18 << ((byte)param_1 & 0x1f);
          local_18 = local_18 + 1;
        }
        uVar8 = (local_8 & 7) >> 1;
        puVar5[6] = local_8 & 1;
        if (uVar8 == 0) {
          uVar8 = (uint)((int)param_1 + -3) & 7;
          local_8 = (local_8 >> 3) >> (sbyte)uVar8;
          param_1 = (uint *)((byte *)((int)param_1 + -3) + -uVar8);
          *puVar5 = 1;
        }
        else if (uVar8 == 1) {
          FUN_00961f19(&local_2c,&local_28,&local_24,&local_20,param_2);
          uVar8 = FUN_0096146b(local_2c,local_28,local_24,local_20,param_2);
          puVar5[1] = uVar8;
          if (uVar8 == 0) goto LAB_0095ce62;
          local_8 = local_8 >> 3;
          param_1 = (uint *)((int)param_1 + -3);
          *puVar5 = 6;
        }
        else {
          if (uVar8 == 2) {
            local_8 = local_8 >> 3;
            uVar8 = 3;
            param_1 = (uint *)((int)param_1 + -3);
            goto LAB_0095c89b;
          }
          if (uVar8 == 3) {
            *puVar5 = 9;
            param_2[6] = (int)s_invalid_block_type_00a2f1d4;
            puVar5[8] = local_8 >> 3;
            param_1 = (uint *)((int)param_1 + -3);
            param_3 = (byte *)0xfffffffd;
            goto LAB_0095c7ec;
          }
        }
        break;
      case (undefined *)0x95c907:
        for (; pbVar9 = local_18, param_1 < (byte *)0x20; param_1 = (uint *)((int)param_1 + 8)) {
          if (local_c == (byte *)0x0) goto LAB_0095ce15;
          param_3 = (byte *)0x0;
          local_c = local_c + -1;
          local_8 = local_8 | (uint)*local_18 << ((byte)param_1 & 0x1f);
          local_18 = local_18 + 1;
        }
        if (~local_8 >> 0x10 != (local_8 & 0xffff)) {
          *puVar5 = 9;
          param_2[6] = (int)s_invalid_stored_block_lengths_00a2f1b4;
          goto switchD_0095c815_caseD_95cdd8;
        }
        puVar5[1] = local_8 & 0xffff;
        param_1 = (uint *)0x0;
        local_8 = 0;
        if (puVar5[1] == 0) goto LAB_0095ca46;
        uVar8 = 2;
LAB_0095c89b:
        *puVar5 = uVar8;
        break;
      case (undefined *)0x95c968:
        if (local_c == (byte *)0x0) {
LAB_0095ce15:
          puVar5[8] = local_8;
          puVar5[7] = (uint)param_1;
          param_2[1] = 0;
          goto LAB_0095c7f5;
        }
        if (local_14 == (byte *)0x0) {
          if (local_10 == (byte *)puVar5[0xb]) {
            pbVar6 = (byte *)puVar5[0xc];
            pbVar3 = (byte *)puVar5[10];
            if (pbVar3 != pbVar6) {
              if (pbVar3 < pbVar6) {
                local_14 = pbVar6 + (-1 - (int)pbVar3);
              }
              else {
                local_14 = (byte *)puVar5[0xb] + -(int)pbVar3;
              }
              local_10 = pbVar3;
              if (local_14 != (byte *)0x0) goto LAB_0095ca06;
            }
          }
          puVar5[0xd] = (uint)local_10;
          param_3 = (byte *)FUN_00961f48(puVar5,param_2,param_3);
          local_1c = (byte *)puVar5[0xc];
          local_10 = (byte *)puVar5[0xd];
          if (local_10 < local_1c) {
            local_14 = local_1c + (-1 - (int)local_10);
          }
          else {
            local_14 = (byte *)(puVar5[0xb] - (int)local_10);
          }
          local_30 = (byte *)puVar5[0xb];
          if (local_10 == local_30) {
            pbVar6 = (byte *)puVar5[10];
            if (pbVar6 != local_1c) {
              if (pbVar6 < local_1c) {
                local_14 = local_1c + (-1 - (int)pbVar6);
              }
              else {
                local_14 = local_30 + -(int)pbVar6;
              }
              local_10 = pbVar6;
            }
          }
          if (local_14 == (byte *)0x0) {
            puVar5[8] = local_8;
            puVar5[7] = (uint)param_1;
            param_2[1] = (int)local_c;
            param_2[2] = (int)(pbVar9 + (param_2[2] - *param_2));
            goto LAB_0095c7ff;
          }
        }
LAB_0095ca06:
        param_3 = (byte *)0x0;
        pbVar9 = (byte *)puVar5[1];
        if (local_c < (byte *)puVar5[1]) {
          pbVar9 = local_c;
        }
        if (local_14 < pbVar9) {
          pbVar9 = local_14;
        }
        pbVar6 = local_18 + (int)pbVar9;
        local_c = local_c + -(int)pbVar9;
        pbVar3 = local_10 + (int)pbVar9;
        local_14 = local_14 + -(int)pbVar9;
        for (uVar8 = (uint)pbVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *(undefined4 *)local_10 = *(undefined4 *)local_18;
          local_18 = local_18 + 4;
          local_10 = local_10 + 4;
        }
        for (uVar8 = (uint)pbVar9 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *local_10 = *local_18;
          local_18 = local_18 + 1;
          local_10 = local_10 + 1;
        }
        puVar1 = puVar5 + 1;
        *puVar1 = *puVar1 - (int)pbVar9;
        local_18 = pbVar6;
        local_10 = pbVar3;
        if (*puVar1 == 0) {
LAB_0095ca46:
          uVar8 = -(uint)(puVar5[6] != 0) & 7;
          goto LAB_0095c89b;
        }
        break;
      case (undefined *)0x95ca55:
        for (; param_1 < (byte *)0xe; param_1 = (uint *)((int)param_1 + 8)) {
          if (local_c == (byte *)0x0) goto LAB_0095ce15;
          param_3 = (byte *)0x0;
          local_c = local_c + -1;
          local_8 = local_8 | (uint)*pbVar9 << ((byte)param_1 & 0x1f);
          pbVar9 = pbVar9 + 1;
        }
        puVar5[1] = local_8 & 0x3fff;
        if ((0x1d < (local_8 & 0x1f)) || (uVar8 = (local_8 & 0x3fff) >> 5 & 0x1f, 0x1d < uVar8)) {
          *puVar5 = 9;
          param_2[6] = (int)s_too_many_length_or_distance_symb_00a2f190;
          goto switchD_0095c815_caseD_95cdd8;
        }
        uVar8 = (*(code *)param_2[8])(param_2[10],uVar8 + 0x102 + (local_8 & 0x1f),4);
        puVar5[3] = uVar8;
        if (uVar8 != 0) {
          local_8 = local_8 >> 0xe;
          param_1 = (uint *)((int)param_1 + -0xe);
          puVar5[2] = 0;
          *puVar5 = 4;
          goto switchD_0095c815_caseD_95cb21;
        }
LAB_0095ce62:
        param_3 = (byte *)0xfffffffc;
        goto LAB_0095c7e3;
      case (undefined *)0x95cb21:
switchD_0095c815_caseD_95cb21:
        while (puVar5[2] < (puVar5[1] >> 10) + 4) {
          for (; param_1 < (byte *)0x3; param_1 = (uint *)((int)param_1 + 8)) {
            if (local_c == (byte *)0x0) goto LAB_0095ce15;
            param_3 = (byte *)0x0;
            local_c = local_c + -1;
            local_8 = local_8 | (uint)*pbVar9 << ((byte)param_1 & 0x1f);
            pbVar9 = pbVar9 + 1;
          }
          *(uint *)(puVar5[3] + *(int *)(&DAT_00a2f128 + puVar5[2] * 4) * 4) = local_8 & 7;
          puVar5[2] = puVar5[2] + 1;
          param_1 = (uint *)((int)param_1 + -3);
          local_8 = local_8 >> 3;
        }
        while (puVar5[2] < 0x13) {
          *(undefined4 *)(puVar5[3] + *(int *)(&DAT_00a2f128 + puVar5[2] * 4) * 4) = 0;
          puVar5[2] = puVar5[2] + 1;
        }
        puVar5[4] = 7;
        local_14 = (byte *)FUN_00961da2(puVar5[3],puVar5 + 4,puVar5 + 5,puVar5[9],param_2);
        if (local_14 == (byte *)0x0) {
          puVar5[2] = 0;
          *puVar5 = 5;
          goto switchD_0095c815_caseD_95cc9c;
        }
        goto LAB_0095ce49;
      case (undefined *)0x95cc9c:
switchD_0095c815_caseD_95cc9c:
        while (puVar5[2] < (puVar5[1] >> 5 & 0x1f) + 0x102 + (puVar5[1] & 0x1f)) {
          for (; param_1 < (byte *)puVar5[4]; param_1 = (uint *)((int)param_1 + 8)) {
            if (local_c == (byte *)0x0) goto LAB_0095ce15;
            param_3 = (byte *)0x0;
            local_c = local_c + -1;
            local_8 = local_8 | (uint)*pbVar9 << ((byte)param_1 & 0x1f);
            pbVar9 = pbVar9 + 1;
          }
          iVar4 = puVar5[5] + (*(uint *)(&DAT_00a30790 + (int)puVar5[4] * 4) & local_8) * 8;
          bVar2 = *(byte *)(iVar4 + 1);
          local_14 = (byte *)(uint)bVar2;
          local_30 = *(byte **)(iVar4 + 4);
          if (local_30 < (byte *)0x10) {
            local_8 = local_8 >> (bVar2 & 0x1f);
            param_1 = (uint *)((int)param_1 + -(int)local_14);
            *(byte **)(puVar5[3] + puVar5[2] * 4) = local_30;
            puVar5[2] = puVar5[2] + 1;
          }
          else {
            if (local_30 == (byte *)0x12) {
              pbVar6 = (byte *)0x7;
            }
            else {
              pbVar6 = local_30 + -0xe;
            }
            local_18 = (byte *)((uint)(local_30 == (byte *)0x12) * 8 + 3);
            for (; param_1 < pbVar6 + (int)local_14; param_1 = (uint *)((int)param_1 + 8)) {
              if (local_c == (byte *)0x0) goto LAB_0095ce15;
              param_3 = (byte *)0x0;
              local_c = local_c + -1;
              local_8 = local_8 | (uint)*pbVar9 << ((byte)param_1 & 0x1f);
              pbVar9 = pbVar9 + 1;
            }
            local_8 = local_8 >> (bVar2 & 0x1f);
            local_18 = local_18 + (*(uint *)(&DAT_00a30790 + (int)pbVar6 * 4) & local_8);
            local_8 = local_8 >> ((byte)pbVar6 & 0x1f);
            param_1 = (uint *)((int)param_1 + -(int)(pbVar6 + (int)local_14));
            uVar8 = puVar5[2];
            if ((byte *)((puVar5[1] >> 5 & 0x1f) + 0x102 + (puVar5[1] & 0x1f)) < local_18 + uVar8) {
LAB_0095ce2d:
              (*(code *)param_2[9])(param_2[10],puVar5[3]);
              *puVar5 = 9;
              param_2[6] = (int)s_invalid_bit_length_repeat_00a2f174;
              goto switchD_0095c815_caseD_95cdd8;
            }
            if (local_30 == (byte *)0x10) {
              if (uVar8 == 0) goto LAB_0095ce2d;
              uVar7 = *(undefined4 *)((puVar5[3] - 4) + uVar8 * 4);
            }
            else {
              uVar7 = 0;
            }
            do {
              *(undefined4 *)(puVar5[3] + uVar8 * 4) = uVar7;
              uVar8 = uVar8 + 1;
              local_18 = local_18 + -1;
            } while (local_18 != (byte *)0x0);
            puVar5[2] = uVar8;
            local_18 = (byte *)0x0;
          }
        }
        puVar5[5] = 0;
        local_1c = (byte *)0x9;
        local_18 = (byte *)0x6;
        local_14 = (byte *)FUN_00961e1d((puVar5[1] & 0x1f) + 0x101,(puVar5[1] >> 5 & 0x1f) + 1,
                                        puVar5[3],&local_1c,&local_18,&local_38,&local_34,puVar5[9],
                                        param_2);
        if (local_14 == (byte *)0x0) {
          uVar8 = FUN_0096146b(local_1c,local_18,local_38,local_34,param_2);
          if (uVar8 == 0) goto LAB_0095ce62;
          puVar5[1] = uVar8;
          (*(code *)param_2[9])(param_2[10],puVar5[3]);
          *puVar5 = 6;
          goto switchD_0095c815_caseD_95cd35;
        }
LAB_0095ce49:
        if (local_14 == (byte *)0xfffffffd) {
          (*(code *)param_2[9])(param_2[10],puVar5[3]);
          *puVar5 = 9;
        }
        param_3 = local_14;
        goto LAB_0095c7e3;
      case (undefined *)0x95cd35:
switchD_0095c815_caseD_95cd35:
        puVar5[8] = local_8;
        puVar5[7] = (uint)param_1;
        param_2[1] = (int)local_c;
        param_2[2] = (int)(pbVar9 + (param_2[2] - *param_2));
        *param_2 = (int)pbVar9;
        puVar5[0xd] = (uint)local_10;
        param_3 = (byte *)FUN_009614a0(puVar5,param_2,param_3);
        if (param_3 != (byte *)0x1) goto LAB_0095c804;
        param_3 = (byte *)0x0;
        FUN_009619f9(puVar5[1],param_2);
        local_c = (byte *)param_2[1];
        local_10 = (byte *)puVar5[0xd];
        local_18 = (byte *)*param_2;
        local_8 = puVar5[8];
        param_1 = (uint *)puVar5[7];
        if (local_10 < (byte *)puVar5[0xc]) {
          local_14 = (byte *)puVar5[0xc] + (-1 - (int)local_10);
        }
        else {
          local_14 = (byte *)(puVar5[0xb] - (int)local_10);
        }
        if (puVar5[6] != 0) {
          *puVar5 = 7;
          goto switchD_0095c815_caseD_95ce6f;
        }
        *puVar5 = 0;
        break;
      case (undefined *)0x95cdd8:
switchD_0095c815_caseD_95cdd8:
        param_3 = (byte *)0xfffffffd;
        goto LAB_0095c7e3;
      case (undefined *)0x95ce6f:
switchD_0095c815_caseD_95ce6f:
        pbVar9 = local_18;
        puVar5[0xd] = (uint)local_10;
        param_3 = (byte *)FUN_00961f48(puVar5,param_2,param_3);
        local_10 = (byte *)puVar5[0xd];
        if ((byte *)puVar5[0xc] == local_10) {
          *puVar5 = 8;
          goto switchD_0095c815_caseD_95ceb7;
        }
        puVar5[8] = local_8;
        puVar5[7] = (uint)param_1;
        param_2[1] = (int)local_c;
        iVar4 = *param_2;
        *param_2 = (int)pbVar9;
        param_2[2] = (int)(pbVar9 + (param_2[2] - iVar4));
        puVar5[0xd] = (uint)local_10;
        goto LAB_0095c804;
      case (undefined *)0x95ceb7:
switchD_0095c815_caseD_95ceb7:
        param_3 = (byte *)0x1;
        goto LAB_0095c7e3;
      }
      uVar8 = *puVar5;
    } while (uVar8 < 10);
  }
  pbVar9 = local_18;
  param_3 = (byte *)0xfffffffe;
LAB_0095c7e3:
  puVar5[8] = local_8;
LAB_0095c7ec:
  puVar5[7] = (uint)param_1;
  param_2[1] = (int)local_c;
LAB_0095c7f5:
  param_2[2] = (int)(pbVar9 + (param_2[2] - *param_2));
LAB_0095c7ff:
  *param_2 = (int)pbVar9;
  puVar5[0xd] = (uint)local_10;
LAB_0095c804:
  FUN_00961f48(puVar5,param_2,param_3);
  return;
}


// ==== FUN_0095cee6 @ 0x0095cee6 ====

undefined4 FUN_0095cee6(int param_1,int param_2)

{
  FUN_0095c6ae(param_1,param_2,0);
  (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),*(undefined4 *)(param_1 + 0x28));
  (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),*(undefined4 *)(param_1 + 0x24));
  (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),param_1);
  return 0;
}


// ==== FUN_0095cf1d @ 0x0095cf1d ====

void FUN_0095cf1d(void)

{
  return;
}


// ==== FUN_0095cf1e @ 0x0095cf1e ====

void FUN_0095cf1e(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 *in_ECX;
  
  if (4 < param_4) {
    param_4 = 4;
  }
  in_ECX[6] = 0xffffffff;
  in_ECX[9] = 0xffffffff;
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[3] = param_4;
  in_ECX[10] = 0xffffffff;
  in_ECX[2] = param_3;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  return;
}


// ==== FUN_0095cf66 @ 0x0095cf66 ====

undefined4 FUN_0095cf66(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    *in_ECX = *param_1;
    in_ECX[1] = param_1[1];
    in_ECX[2] = param_1[2];
    in_ECX[3] = param_1[3];
    in_ECX[4] = param_1[4];
    in_ECX[5] = param_1[5];
    in_ECX[6] = param_1[6];
    in_ECX[7] = param_1[7];
    in_ECX[8] = param_1[8];
    in_ECX[9] = param_1[9];
    in_ECX[10] = param_1[10];
    in_ECX[0xb] = param_1[0xb];
    in_ECX[0xc] = param_1[0xc];
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0095cfcb @ 0x0095cfcb ====

void FUN_0095cfcb(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  do {
    while( true ) {
      iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x14) + param_2 * 4);
      if (*(int *)(iVar2 + 0x38) == -1) break;
      param_2 = *(int *)(iVar2 + 0x38);
    }
    *(undefined4 *)(iVar2 + 0x30) = 0xffffffff;
    *(int *)(iVar2 + 0x74) = param_1;
    if ((*(byte *)(*(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x10) + *(int *)(iVar2 + 4) * 4) + 4) &
        0x10) == 0) {
      if (*(int *)(in_ECX + 0x10) != 0) {
        *(int *)(*(int *)(in_ECX + 0x10) +
                (*(int *)(*(int *)(in_ECX + 0xc) + param_1 * 4) +
                *(int *)(*(int *)(in_ECX + 8) + param_1 * 4)) * 4) = param_2;
      }
      piVar1 = (int *)(*(int *)(in_ECX + 8) + param_1 * 4);
      *piVar1 = *piVar1 + 1;
    }
    param_2 = *(int *)(iVar2 + 8);
  } while (param_2 != -1);
  return;
}


// ==== FUN_0095d040 @ 0x0095d040 ====

void FUN_0095d040(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x14) + param_2 * 4);
  if (((*(byte *)(*(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x10) + *(int *)(iVar2 + 4) * 4) + 4) &
       0x20) == 0) && (*(int *)(iVar2 + 0x5c) != 0)) {
    if (*(int *)(in_ECX + 0x24) != 0) {
      *(int *)(*(int *)(in_ECX + 0x24) +
              (*(int *)(*(int *)(in_ECX + 0x20) + param_1 * 4) +
              *(int *)(*(int *)(in_ECX + 0x1c) + param_1 * 4)) * 4) = param_2;
    }
    piVar1 = (int *)(*(int *)(in_ECX + 0x1c) + param_1 * 4);
    *piVar1 = *piVar1 + 1;
  }
  if (*(int *)(iVar2 + 0x14) != -1) {
    FUN_0095cfcb(param_1,*(int *)(iVar2 + 0x14));
  }
  return;
}


// ==== FUN_0095d0a9 @ 0x0095d0a9 ====

void FUN_0095d0a9(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  
  uVar4 = param_2 - param_1 >> 1;
  if (uVar4 != 0) {
    param_1 = param_1 << 2;
    iVar3 = param_2 * 4;
    param_2 = uVar4;
    do {
      iVar3 = iVar3 + -4;
      puVar1 = (undefined4 *)(param_1 + *(int *)(in_ECX + 0x3c));
      uVar2 = *puVar1;
      *puVar1 = *(undefined4 *)(iVar3 + *(int *)(in_ECX + 0x3c));
      *(undefined4 *)(iVar3 + *(int *)(in_ECX + 0x3c)) = uVar2;
      param_1 = param_1 + 4;
      param_2 = param_2 - 1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_0095d0f3 @ 0x0095d0f3 ====

uint FUN_0095d0f3(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(*(int *)(param_3 + 0x3c) + param_1 * 4);
  uVar2 = *(uint *)(*(int *)(param_3 + 0x3c) + param_2 * 4);
  if (*(uint *)(*(int *)(param_3 + 0x2c) + uVar1 * 4) <=
      *(uint *)(*(int *)(param_3 + 0x2c) + uVar2 * 4)) {
    if (*(uint *)(*(int *)(param_3 + 0x2c) + uVar1 * 4) <
        *(uint *)(*(int *)(param_3 + 0x2c) + uVar2 * 4)) {
      return 1;
    }
    if (uVar2 <= uVar1) {
      return (uint)(uVar2 < uVar1);
    }
  }
  return 0xffffffff;
}


// ==== FUN_0095d13a @ 0x0095d13a ====

void FUN_0095d13a(int param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (1 < *param_2) {
    FUN_00915b0e(FUN_009157b4,param_1,*param_2,0);
    uVar2 = 1;
    uVar3 = 1;
    if (1 < *param_2) {
      do {
        iVar1 = *(int *)(param_1 + uVar2 * 4);
        if (iVar1 != *(int *)(param_1 + -4 + uVar2 * 4)) {
          *(int *)(param_1 + uVar3 * 4) = iVar1;
          uVar3 = uVar3 + 1;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *param_2);
    }
    *param_2 = uVar3;
  }
  return;
}


// ==== FUN_0095d180 @ 0x0095d180 ====

void FUN_0095d180(int *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  int *piVar7;
  uint local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  uVar6 = 0;
  local_1c = 0;
  local_10 = 0;
  local_14 = 0;
  local_c = 0;
  if (*(int *)(in_ECX + 0x38) != 0) {
    do {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x3c) + local_c * 4);
      iVar5 = iVar1 * 4;
      iVar2 = *(int *)(iVar5 + *(int *)(*(int *)(in_ECX + 4) + 0x18));
      *(uint *)(iVar5 + *(int *)(in_ECX + 0x2c)) = uVar6;
      *(undefined4 *)(iVar5 + *(int *)(in_ECX + 0x28)) = 0;
      if ((*(ushort *)(iVar2 + 2) & 0xfff0) != 0) {
        iVar2 = *(int *)(iVar5 + *(int *)(in_ECX + 0xc));
        iVar3 = *(int *)(in_ECX + 0x10);
        local_8 = 0;
        uVar4 = *(uint *)(iVar5 + *(int *)(in_ECX + 8));
        if (uVar4 != 0) {
          do {
            if (iVar1 == *(int *)(*(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x14) +
                                          *(int *)(iVar3 + iVar2 * 4 + local_8 * 4) * 4) + 0x58)) {
              piVar7 = (int *)(*(int *)(in_ECX + 0x28) + iVar5);
              *piVar7 = *piVar7 + -1;
            }
            local_8 = local_8 + 1;
          } while (local_8 < uVar4);
          uVar6 = local_1c;
        }
        iVar1 = *(int *)(iVar5 + *(int *)(in_ECX + 0x20));
        iVar2 = *(int *)(in_ECX + 0x24);
        uVar4 = *(uint *)(iVar5 + *(int *)(in_ECX + 0x1c));
        local_18 = 0;
        if (uVar4 != 0) {
          do {
            if (*(int *)(*(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x14) +
                                 *(int *)(iVar2 + iVar1 * 4 + local_18 * 4) * 4) + 0x5c) != 0) {
              piVar7 = (int *)(*(int *)(in_ECX + 0x28) + iVar5);
              *piVar7 = *piVar7 + 1;
            }
            local_18 = local_18 + 1;
          } while (local_18 < uVar4);
        }
        local_10 = local_10 + uVar6;
        if (local_14 < uVar6) {
          local_14 = uVar6;
        }
        uVar6 = uVar6 + *(int *)(*(int *)(in_ECX + 0x28) + iVar5);
        local_1c = uVar6;
      }
      local_c = local_c + 1;
    } while (local_c < *(uint *)(in_ECX + 0x38));
  }
  if (param_1 != (int *)0x0) {
    *param_1 = local_10;
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = local_14;
  }
  return;
}


// ==== FUN_0095d29d @ 0x0095d29d ====

undefined4 FUN_0095d29d(uint param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  uint local_54;
  int local_50;
  undefined4 *local_4c;
  int local_48;
  int local_44;
  uint local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  local_44 = 0;
  local_10 = param_1 + 1;
  iVar6 = *(int *)(*(int *)(in_ECX + 0x3c) + param_1 * 4);
  local_14 = param_1;
  iVar2 = iVar6 * 4;
  if (*(int *)(iVar2 + *(int *)(in_ECX + 0x34)) != 0) {
    return 1;
  }
  iVar1 = *(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x14) +
                  **(int **)(*(int *)(iVar2 + *(int *)(*(int *)(in_ECX + 4) + 0x18)) + 0x10) * 4);
  local_28 = *(int *)(iVar1 + 0x14);
  local_38 = *(int *)(iVar1 + 0x18);
  local_18 = *(uint *)(iVar2 + *(int *)(in_ECX + 8));
  puVar9 = (undefined4 *)(*(int *)(in_ECX + 0x10) + *(int *)(iVar2 + *(int *)(in_ECX + 0xc)) * 4);
  puVar11 = *(undefined4 **)(in_ECX + 0x14);
  for (uVar4 = local_18; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar11 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar11 = puVar11 + 1;
  }
LAB_0095d30f:
  local_8 = 0;
  *(int *)(in_ECX + 0x48) = *(int *)(in_ECX + 0x48) + 1;
  for (uVar4 = local_14; uVar4 < local_10; uVar4 = uVar4 + 1) {
    iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x18) +
                    *(int *)(*(int *)(in_ECX + 0x3c) + uVar4 * 4) * 4);
    uVar5 = 0;
    if (*(int *)(iVar2 + 0x14) != 0) {
      do {
        iVar1 = uVar5 * 4;
        uVar5 = uVar5 + 1;
        *(undefined4 *)
         (*(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x18) +
                  *(int *)(*(int *)(iVar2 + 0x18) + iVar1) * 4) + 0x24) =
             *(undefined4 *)(in_ECX + 0x48);
      } while (uVar5 < *(uint *)(iVar2 + 0x14));
    }
    uVar5 = 0;
    if (*(int *)(iVar2 + 0x1c) != 0) {
      do {
        iVar1 = uVar5 * 4;
        uVar5 = uVar5 + 1;
        *(undefined4 *)
         (*(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x18) +
                  *(int *)(*(int *)(iVar2 + 0x20) + iVar1) * 4) + 0x24) =
             *(undefined4 *)(in_ECX + 0x48);
      } while (uVar5 < *(uint *)(iVar2 + 0x1c));
    }
    local_8 = local_8 + *(int *)(*(int *)(in_ECX + 0x28) +
                                *(int *)(*(int *)(in_ECX + 0x3c) + uVar4 * 4) * 4);
  }
  uVar4 = 0;
  if (local_18 != 0) {
    do {
      iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x14) + uVar4 * 4);
      *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(in_ECX + 0x48);
      uVar4 = uVar4 + 1;
      *(uint *)(iVar2 + 0x54) = (uint)(iVar6 == *(int *)(iVar2 + 0x74));
    } while (uVar4 < local_18);
  }
  do {
    if (local_8 < 0) {
      local_2c = -1;
      local_c = local_14;
      local_3c = local_14;
    }
    else {
      if (local_8 < 1) goto LAB_0095d6fa;
      local_3c = local_10 - 1;
      local_c = local_10;
      local_2c = 1;
    }
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    param_1 = local_c;
    do {
      local_3c = local_3c + local_2c;
      if (*(uint *)(in_ECX + 0x38) <= local_3c) break;
      local_48 = *(int *)(*(int *)(in_ECX + 0x3c) + local_3c * 4);
      iVar2 = local_48 * 4;
      if (*(int *)(iVar2 + *(int *)(in_ECX + 0x34)) == 0) {
        iVar1 = *(int *)(in_ECX + 4);
        local_50 = *(int *)(*(int *)(iVar1 + 0x14) +
                           **(int **)(*(int *)(*(int *)(iVar1 + 0x18) + iVar2) + 0x10) * 4);
        iVar10 = *(int *)(local_50 + 0x18);
        for (iVar7 = *(int *)(local_50 + 0x14); iVar7 != -1; iVar7 = *(int *)(iVar7 + 0x14)) {
          if (local_28 == iVar7) goto LAB_0095d441;
          iVar7 = *(int *)(*(int *)(iVar1 + 0x14) + iVar7 * 4);
          iVar10 = *(int *)(iVar7 + 0x18);
        }
        if (local_28 != -1) goto LAB_0095d6fa;
LAB_0095d441:
        if (local_38 != iVar10) goto LAB_0095d6fa;
      }
      if (local_3c < local_c) {
        local_c = local_3c;
      }
      if (param_1 <= local_3c) {
        param_1 = local_3c + 1;
      }
      local_4c = (undefined4 *)
                 (*(int *)(in_ECX + 0x10) + *(int *)(iVar2 + *(int *)(in_ECX + 0xc)) * 4);
      local_34 = *(uint *)(iVar2 + *(int *)(in_ECX + 8));
      puVar9 = local_4c;
      puVar11 = (undefined4 *)(*(int *)(in_ECX + 0x18) + local_24 * 4);
      for (uVar4 = local_34; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar11 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar11 = puVar11 + 1;
      }
      local_24 = local_24 + *(int *)(iVar2 + *(int *)(in_ECX + 8));
      local_20 = local_20 + *(int *)(*(int *)(in_ECX + 0x28) + iVar2);
      local_1c = local_1c |
                 *(int *)(in_ECX + 0x48) ==
                 *(int *)(*(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x18) + iVar2) + 0x24);
      local_30 = 0;
      if (local_34 != 0) {
        do {
          iVar1 = *(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x14) + local_4c[local_30] * 4);
          if ((*(int *)(iVar1 + 0x30) != *(int *)(in_ECX + 0x48)) ||
             (local_48 == *(int *)(iVar1 + 0x74))) {
            *(int *)(iVar1 + 0x30) = *(int *)(in_ECX + 0x48);
            *(uint *)(iVar1 + 0x54) = (local_48 != *(int *)(iVar1 + 0x74)) - 1;
          }
          local_30 = local_30 + 1;
        } while (local_30 < local_34);
      }
    } while (((*(int *)(iVar2 + *(int *)(in_ECX + 0x34)) != 0) ||
             (local_28 != *(int *)(local_50 + 0x14))) || (local_38 != *(int *)(local_50 + 0x18)));
    if (param_1 <= local_c) {
LAB_0095d6fa:
      if (local_44 == 0) {
        return 1;
      }
      puVar9 = *(undefined4 **)(in_ECX + 0x40);
      puVar11 = *(undefined4 **)(in_ECX + 0x3c);
      for (uVar4 = *(uint *)(in_ECX + 0x38) & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar11 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar11 = puVar11 + 1;
      }
      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      FUN_0095d180(0,0);
      return 1;
    }
    if (local_c + 1 < param_1) {
      FUN_0095d13a(*(undefined4 *)(in_ECX + 0x18),&local_24);
    }
    if (local_1c == 0) {
      if (local_8 < 0) {
        local_2c = local_20;
        if (local_24 != 0) {
          piVar3 = *(int **)(in_ECX + 0x18);
          uVar4 = local_24;
          do {
            if (*(int *)(*(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x14) + *piVar3 * 4) + 0x54) == 1)
            {
              local_2c = local_2c + -1;
            }
            piVar3 = piVar3 + 1;
            uVar4 = uVar4 - 1;
          } while (uVar4 != 0);
        }
        if (local_2c < local_8) goto LAB_0095d5ad;
      }
      else {
        local_2c = local_8;
        if (local_18 != 0) {
          piVar3 = *(int **)(in_ECX + 0x14);
          uVar4 = local_18;
          do {
            if (*(int *)(*(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x14) + *piVar3 * 4) + 0x54) == -1
               ) {
              local_2c = local_2c + -1;
            }
            piVar3 = piVar3 + 1;
            uVar4 = uVar4 - 1;
          } while (uVar4 != 0);
        }
        if (local_2c < local_20) {
LAB_0095d5ad:
          local_1c = 1;
        }
      }
    }
    uVar4 = local_14;
    if (local_c <= local_14) {
      uVar4 = local_c;
    }
    uVar5 = local_10;
    if (local_10 <= param_1) {
      uVar5 = param_1;
    }
    if (local_1c == 0) break;
    uVar8 = 0;
    if (local_24 != 0) {
      do {
        iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x14) +
                        *(int *)(*(int *)(in_ECX + 0x18) + uVar8 * 4) * 4);
        uVar8 = uVar8 + 1;
        *(uint *)(iVar2 + 0x54) = (uint)(*(int *)(iVar2 + 0x54) != 0);
      } while (uVar8 < local_24);
    }
    local_8 = local_8 + local_20;
    puVar9 = *(undefined4 **)(in_ECX + 0x18);
    puVar11 = (undefined4 *)(*(int *)(in_ECX + 0x14) + local_18 * 4);
    for (uVar8 = local_24; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar11 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
    }
    local_18 = local_18 + local_24;
    local_14 = uVar4;
    local_10 = uVar5;
    FUN_0095d13a(*(undefined4 *)(in_ECX + 0x14),&local_18);
    uVar4 = local_c;
    do {
      iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x18) +
                      *(int *)(*(int *)(in_ECX + 0x3c) + uVar4 * 4) * 4);
      uVar5 = 0;
      if (*(int *)(iVar2 + 0x14) != 0) {
        do {
          iVar1 = uVar5 * 4;
          uVar5 = uVar5 + 1;
          *(undefined4 *)
           (*(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x18) +
                    *(int *)(*(int *)(iVar2 + 0x18) + iVar1) * 4) + 0x24) =
               *(undefined4 *)(in_ECX + 0x48);
        } while (uVar5 < *(uint *)(iVar2 + 0x14));
      }
      uVar5 = 0;
      if (*(int *)(iVar2 + 0x1c) != 0) {
        do {
          iVar1 = uVar5 * 4;
          uVar5 = uVar5 + 1;
          *(undefined4 *)
           (*(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x18) +
                    *(int *)(*(int *)(iVar2 + 0x20) + iVar1) * 4) + 0x24) =
               *(undefined4 *)(in_ECX + 0x48);
        } while (uVar5 < *(uint *)(iVar2 + 0x1c));
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_1);
  } while( true );
  FUN_0095d0a9(local_14,local_10);
  FUN_0095d0a9(local_c,param_1);
  FUN_0095d0a9(uVar4,uVar5);
  FUN_0095d180(&local_40,&local_54);
  if (((local_40 < *(uint *)(in_ECX + 0x50)) && (local_54 <= *(uint *)(in_ECX + 0x4c))) ||
     ((local_40 <= *(uint *)(in_ECX + 0x50) && (local_54 < *(uint *)(in_ECX + 0x4c))))) {
    return 0;
  }
  if (local_8 < 0) {
    iVar2 = local_c - param_1;
  }
  else {
    iVar2 = param_1 - local_c;
  }
  local_14 = local_14 + iVar2;
  local_10 = local_10 + iVar2;
  local_44 = 1;
  goto LAB_0095d30f;
}


// ==== FUN_0095d72f @ 0x0095d72f ====

int FUN_0095d72f(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  FUN_0095d180(in_ECX + 0x50,in_ECX + 0x4c);
  uVar1 = 0;
  if (*(int *)(in_ECX + 0x38) != 0) {
    do {
      *(uint *)(*(int *)(in_ECX + 0x30) + uVar1 * 4) = uVar1;
      *(undefined4 *)(*(int *)(in_ECX + 0x40) + uVar1 * 4) =
           *(undefined4 *)(*(int *)(in_ECX + 0x3c) + uVar1 * 4);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(in_ECX + 0x38));
  }
  FUN_00915b0e(FUN_0095d0f3,*(undefined4 *)(in_ECX + 0x30),*(undefined4 *)(in_ECX + 0x38),in_ECX);
  uVar1 = 0;
  if (*(int *)(in_ECX + 0x38) != 0) {
    do {
      iVar2 = FUN_0095d29d(*(undefined4 *)(*(int *)(in_ECX + 0x30) + uVar1 * 4));
      if (iVar2 < 0) {
        return iVar2;
      }
      if (iVar2 == 0) {
        return 0;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(in_ECX + 0x38));
  }
  return 1;
}


// ==== FUN_0095d79c @ 0x0095d79c ====

void FUN_0095d79c(int param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint local_c;
  uint local_8;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(*(int *)(in_ECX + 4) + 0xc);
  FUN_009198e4();
  pvVar1 = operator_new(*(int *)(in_ECX + 0x38) << 2);
  *(void **)(in_ECX + 8) = pvVar1;
  if (pvVar1 != (void *)0x0) {
    pvVar1 = operator_new(*(int *)(in_ECX + 0x38) << 2);
    *(void **)(in_ECX + 0x1c) = pvVar1;
    if (pvVar1 != (void *)0x0) {
      puVar8 = *(undefined4 **)(in_ECX + 8);
      for (uVar4 = *(uint *)(in_ECX + 0x38) & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined1 *)puVar8 = 0;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      puVar8 = *(undefined4 **)(in_ECX + 0x1c);
      for (uVar4 = *(uint *)(in_ECX + 0x38) & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined1 *)puVar8 = 0;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      local_8 = 0;
      if (*(int *)(in_ECX + 0x38) != 0) {
        do {
          iVar5 = *(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x18) + local_8 * 4);
          if ((*(ushort *)(iVar5 + 2) & 0xfff0) != 0) {
            local_c = 0;
            if (*(int *)(iVar5 + 0xc) != 0) {
              do {
                FUN_0095d040(local_8,*(undefined4 *)(*(int *)(iVar5 + 0x10) + local_c * 4));
                local_c = local_c + 1;
              } while (local_c < *(uint *)(iVar5 + 0xc));
            }
            local_c = 0;
            if (*(int *)(iVar5 + 4) != 0) {
              do {
                FUN_0095cfcb(local_8,*(undefined4 *)(*(int *)(iVar5 + 8) + local_c * 4));
                local_c = local_c + 1;
              } while (local_c < *(uint *)(iVar5 + 4));
            }
          }
          local_8 = local_8 + 1;
        } while (local_8 < *(uint *)(in_ECX + 0x38));
      }
      pvVar1 = operator_new(*(int *)(in_ECX + 0x38) << 2);
      *(void **)(in_ECX + 0xc) = pvVar1;
      if (pvVar1 != (void *)0x0) {
        pvVar1 = operator_new(*(int *)(in_ECX + 0x38) << 2);
        *(void **)(in_ECX + 0x20) = pvVar1;
        if (pvVar1 != (void *)0x0) {
          iVar5 = 0;
          iVar7 = 0;
          uVar4 = 0;
          if (*(int *)(in_ECX + 0x38) != 0) {
            do {
              iVar2 = uVar4 * 4;
              *(int *)(iVar2 + *(int *)(in_ECX + 0xc)) = iVar5;
              iVar5 = iVar5 + *(int *)(iVar2 + *(int *)(in_ECX + 8));
              *(int *)(iVar2 + *(int *)(in_ECX + 0x20)) = iVar7;
              iVar7 = iVar7 + *(int *)(iVar2 + *(int *)(in_ECX + 0x1c));
              uVar4 = uVar4 + 1;
            } while (uVar4 < *(uint *)(in_ECX + 0x38));
          }
          uVar6 = 0;
          uVar4 = iVar5 << 2;
          pvVar1 = operator_new(uVar4);
          *(void **)(in_ECX + 0x10) = pvVar1;
          if (pvVar1 != (void *)0x0) {
            pvVar1 = operator_new(uVar4);
            *(void **)(in_ECX + 0x14) = pvVar1;
            if (pvVar1 != (void *)0x0) {
              pvVar1 = operator_new(uVar4);
              *(void **)(in_ECX + 0x18) = pvVar1;
              if (pvVar1 != (void *)0x0) {
                pvVar1 = operator_new(iVar7 << 2);
                *(void **)(in_ECX + 0x24) = pvVar1;
                if (pvVar1 != (void *)0x0) {
                  puVar8 = *(undefined4 **)(in_ECX + 8);
                  for (uVar4 = *(uint *)(in_ECX + 0x38) & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1)
                  {
                    *puVar8 = 0;
                    puVar8 = puVar8 + 1;
                  }
                  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
                    *(undefined1 *)puVar8 = 0;
                    puVar8 = (undefined4 *)((int)puVar8 + 1);
                  }
                  puVar8 = *(undefined4 **)(in_ECX + 0x1c);
                  for (uVar4 = *(uint *)(in_ECX + 0x38) & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1)
                  {
                    *puVar8 = 0;
                    puVar8 = puVar8 + 1;
                  }
                  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
                    *(undefined1 *)puVar8 = 0;
                    puVar8 = (undefined4 *)((int)puVar8 + 1);
                  }
                  local_8 = 0;
                  if (*(int *)(in_ECX + 0x38) != 0) {
                    do {
                      iVar5 = *(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x18) + local_8 * 4);
                      if ((*(ushort *)(iVar5 + 2) & 0xfff0) != 0) {
                        local_c = 0;
                        if (*(int *)(iVar5 + 4) != 0) {
                          do {
                            FUN_0095cfcb(local_8,*(undefined4 *)(*(int *)(iVar5 + 8) + local_c * 4))
                            ;
                            local_c = local_c + 1;
                          } while (local_c < *(uint *)(iVar5 + 4));
                        }
                        local_c = 0;
                        if (*(int *)(iVar5 + 0xc) != 0) {
                          do {
                            FUN_0095d040(local_8,*(undefined4 *)
                                                  (*(int *)(iVar5 + 0x10) + local_c * 4));
                            local_c = local_c + 1;
                          } while (local_c < *(uint *)(iVar5 + 0xc));
                        }
                      }
                      local_8 = local_8 + 1;
                    } while (local_8 < *(uint *)(in_ECX + 0x38));
                  }
                  local_c = 0;
                  if (*(int *)(in_ECX + 0x38) != 0) {
                    do {
                      iVar5 = local_c * 4;
                      FUN_0095d13a(*(int *)(in_ECX + 0x10) +
                                   *(int *)(iVar5 + *(int *)(in_ECX + 0xc)) * 4,
                                   *(int *)(in_ECX + 8) + iVar5);
                      FUN_0095d13a(*(int *)(in_ECX + 0x24) +
                                   *(int *)(iVar5 + *(int *)(in_ECX + 0x20)) * 4,
                                   *(int *)(in_ECX + 0x1c) + iVar5);
                      local_c = local_c + 1;
                    } while (local_c < *(uint *)(in_ECX + 0x38));
                  }
                  pvVar1 = operator_new(*(int *)(in_ECX + 0x38) << 2);
                  *(void **)(in_ECX + 0x3c) = pvVar1;
                  if (pvVar1 != (void *)0x0) {
                    pvVar1 = operator_new(*(int *)(in_ECX + 0x38) << 2);
                    *(void **)(in_ECX + 0x40) = pvVar1;
                    if (pvVar1 != (void *)0x0) {
                      pvVar1 = operator_new(*(int *)(in_ECX + 0x38) << 2);
                      *(void **)(in_ECX + 0x44) = pvVar1;
                      if (pvVar1 != (void *)0x0) {
                        pvVar1 = operator_new(*(int *)(in_ECX + 0x38) << 2);
                        *(void **)(in_ECX + 0x34) = pvVar1;
                        if (pvVar1 != (void *)0x0) {
                          if (*(int *)(in_ECX + 0x38) != 0) {
                            do {
                              iVar7 = uVar6 * 4;
                              iVar5 = *(int *)(iVar7 + *(int *)(*(int *)(in_ECX + 4) + 0x18));
                              *(uint *)(iVar7 + *(int *)(in_ECX + 0x3c)) = uVar6;
                              *(int *)(iVar7 + *(int *)(in_ECX + 0x44)) = iVar5;
                              *(undefined4 *)(iVar5 + 0x24) = 0xffffffff;
                              if ((*(ushort *)(iVar5 + 2) & 0xfff0) == 0) {
LAB_0095daec:
                                uVar3 = 1;
                              }
                              else {
                                iVar5 = FUN_009147e7();
                                uVar3 = 0;
                                if (iVar5 != 0) goto LAB_0095daec;
                              }
                              uVar6 = uVar6 + 1;
                              *(undefined4 *)(iVar7 + *(int *)(in_ECX + 0x34)) = uVar3;
                            } while (uVar6 < *(uint *)(in_ECX + 0x38));
                          }
                          *(undefined4 *)(in_ECX + 0x48) = 0;
                          pvVar1 = operator_new(*(int *)(in_ECX + 0x38) << 2);
                          *(void **)(in_ECX + 0x28) = pvVar1;
                          if (pvVar1 != (void *)0x0) {
                            pvVar1 = operator_new(*(int *)(in_ECX + 0x38) << 2);
                            *(void **)(in_ECX + 0x2c) = pvVar1;
                            if (pvVar1 != (void *)0x0) {
                              pvVar1 = operator_new(*(int *)(in_ECX + 0x38) << 2);
                              *(void **)(in_ECX + 0x30) = pvVar1;
                              if ((pvVar1 != (void *)0x0) && (param_1 != 0)) {
                                do {
                                  iVar5 = FUN_0095d72f();
                                  if (iVar5 < 0) {
                                    return;
                                  }
                                } while (iVar5 != 1);
                                uVar4 = 0;
                                if (*(int *)(in_ECX + 0x38) != 0) {
                                  do {
                                    *(undefined4 *)
                                     (*(int *)(*(int *)(in_ECX + 4) + 0x18) + uVar4 * 4) =
                                         *(undefined4 *)
                                          (*(int *)(in_ECX + 0x44) +
                                          *(int *)(*(int *)(in_ECX + 0x3c) + uVar4 * 4) * 4);
                                    uVar4 = uVar4 + 1;
                                  } while (uVar4 < *(uint *)(in_ECX + 0x38));
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
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_0095dc10 @ 0x0095dc10 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0095dc10(int param_1,int param_2,short *param_3,int param_4,int param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  undefined1 *puVar11;
  float local_120 [16];
  float local_e0 [8];
  float local_c0 [8];
  float local_a0 [8];
  float local_80 [8];
  float local_60 [8];
  float local_40 [8];
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  pfVar9 = *(float **)(param_2 + 0x50);
  iVar10 = *(int *)(param_1 + 0x148) + 0x80;
  pfVar7 = local_120;
  local_14 = 1.12104e-44;
  do {
    if ((((param_3[8] == 0) && (param_3[0x10] == 0)) && (param_3[0x18] == 0)) &&
       (((param_3[0x20] == 0 && (param_3[0x28] == 0)) &&
        ((param_3[0x30] == 0 && (param_3[0x38] == 0)))))) {
      fVar1 = (float)(int)*param_3 * *pfVar9;
      *pfVar7 = fVar1;
      pfVar7[8] = fVar1;
      pfVar7[0x10] = fVar1;
      pfVar7[0x18] = fVar1;
      pfVar7[0x20] = fVar1;
      pfVar7[0x28] = fVar1;
      pfVar7[0x30] = fVar1;
      pfVar7[0x38] = fVar1;
    }
    else {
      fVar1 = (float)(int)param_3[0x20] * pfVar9[0x20] + (float)(int)*param_3 * *pfVar9;
      fVar2 = (float)(int)*param_3 * *pfVar9 - (float)(int)param_3[0x20] * pfVar9[0x20];
      fVar4 = (float)(int)param_3[0x30] * pfVar9[0x30] + (float)(int)param_3[0x10] * pfVar9[0x10];
      fVar5 = ((float)(int)param_3[0x10] * pfVar9[0x10] - (float)(int)param_3[0x30] * pfVar9[0x30])
              * _DAT_00a2f1f4 - fVar4;
      fVar3 = fVar4 + fVar1;
      fVar1 = fVar1 - fVar4;
      local_18 = fVar5 + fVar2;
      local_20 = fVar2 - fVar5;
      local_10 = (float)(int)param_3[8] * pfVar9[8];
      local_1c = (float)(int)param_3[0x28] * pfVar9[0x28] + (float)(int)param_3[0x18] * pfVar9[0x18]
      ;
      fVar5 = (float)(int)param_3[0x28] * pfVar9[0x28] - (float)(int)param_3[0x18] * pfVar9[0x18];
      fVar2 = (float)(int)param_3[0x38] * pfVar9[0x38] + local_10;
      local_10 = local_10 - (float)(int)param_3[0x38] * pfVar9[0x38];
      fVar4 = fVar2 + local_1c;
      fVar6 = (local_10 + fVar5) * _DAT_00a2f1f0;
      local_c = (fVar6 - fVar5 * _DAT_00a2f1ec) - fVar4;
      fVar2 = (fVar2 - local_1c) * _DAT_00a2f1f4 - local_c;
      local_8 = (local_10 * _DAT_00a2f1e8 - fVar6) + fVar2;
      *pfVar7 = fVar4 + fVar3;
      pfVar7[0x38] = fVar3 - fVar4;
      pfVar7[8] = local_c + local_18;
      pfVar7[0x30] = local_18 - local_c;
      pfVar7[0x10] = fVar2 + local_20;
      pfVar7[0x28] = local_20 - fVar2;
      pfVar7[0x20] = local_8 + fVar1;
      pfVar7[0x18] = fVar1 - local_8;
    }
    pfVar9 = pfVar9 + 1;
    param_3 = param_3 + 1;
    pfVar7 = pfVar7 + 1;
    local_14 = (float)((int)local_14 + -1);
  } while (local_14 != 0.0);
  local_c = 0.0;
  pfVar7 = local_120 + 2;
  do {
    puVar11 = (undefined1 *)(*(int *)(param_4 + (int)local_c * 4) + param_5);
    local_14 = *pfVar7 + pfVar7[4] + pfVar7[2] + pfVar7[-2];
    local_18 = ((*pfVar7 - pfVar7[4]) * _DAT_00a2f1f4 - (*pfVar7 + pfVar7[4])) +
               (pfVar7[-2] - pfVar7[2]);
    local_10 = pfVar7[-1] - pfVar7[5];
    fVar1 = (local_10 + (pfVar7[3] - pfVar7[1])) * _DAT_00a2f1f0;
    local_8 = (local_10 * _DAT_00a2f1e8 - fVar1) +
              (((pfVar7[5] + pfVar7[-1]) - (pfVar7[3] + pfVar7[1])) * _DAT_00a2f1f4 -
              ((fVar1 - (pfVar7[3] - pfVar7[1]) * _DAT_00a2f1ec) -
              (pfVar7[5] + pfVar7[-1] + pfVar7[3] + pfVar7[1])));
    iVar8 = __ftol();
    *puVar11 = *(undefined1 *)((iVar8 + 4 >> 3 & 0x3ffU) + iVar10);
    iVar8 = __ftol();
    puVar11[7] = *(undefined1 *)((iVar8 + 4 >> 3 & 0x3ffU) + iVar10);
    iVar8 = __ftol();
    puVar11[1] = *(undefined1 *)((iVar8 + 4 >> 3 & 0x3ffU) + iVar10);
    iVar8 = __ftol();
    puVar11[6] = *(undefined1 *)((iVar8 + 4 >> 3 & 0x3ffU) + iVar10);
    iVar8 = __ftol();
    puVar11[2] = *(undefined1 *)((iVar8 + 4 >> 3 & 0x3ffU) + iVar10);
    iVar8 = __ftol();
    puVar11[5] = *(undefined1 *)((iVar8 + 4 >> 3 & 0x3ffU) + iVar10);
    iVar8 = __ftol();
    puVar11[4] = *(undefined1 *)((iVar8 + 4 >> 3 & 0x3ffU) + iVar10);
    iVar8 = __ftol();
    puVar11[3] = *(undefined1 *)((iVar8 + 4 >> 3 & 0x3ffU) + iVar10);
    pfVar7 = pfVar7 + 8;
    local_c = (float)((int)local_c + 1);
  } while ((int)local_c < 8);
  return;
}


// ==== FUN_0095dfe0 @ 0x0095dfe0 ====

void FUN_0095dfe0(int param_1,int param_2,short *param_3,int param_4,int param_5)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  ushort *puVar4;
  short *psVar5;
  undefined1 *puVar6;
  undefined1 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  ushort uVar11;
  int iVar12;
  ushort uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  ushort local_128 [2];
  undefined4 local_124;
  ushort local_120 [2];
  undefined4 local_11c;
  ushort local_118 [2];
  undefined4 local_114;
  ushort local_110 [2];
  undefined4 local_10c [9];
  undefined4 local_e8 [8];
  undefined4 local_c8 [8];
  undefined4 local_a8 [8];
  undefined4 local_88 [8];
  undefined4 local_68 [8];
  undefined4 local_48 [8];
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  short *local_10;
  int local_c;
  int local_8;
  
  psVar5 = *(short **)(param_2 + 0x50);
  iVar14 = *(int *)(param_1 + 0x148) + 0x80;
  local_20 = iVar14;
  puVar4 = local_128;
  local_14 = 8;
  local_10 = param_3;
  do {
    sVar1 = local_10[0x38];
    local_8 = CONCAT22(local_8._2_2_,sVar1);
    sVar2 = local_10[0x28];
    local_c = CONCAT22(local_c._2_2_,sVar2);
    uVar3 = local_10[8];
    uVar11 = local_10[0x10];
    local_28 = (uint)uVar3;
    local_18 = (uint)uVar11;
    if ((((((uVar3 == 0 && uVar11 == 0) && local_10[0x18] == 0) && local_10[0x20] == 0) &&
         sVar2 == 0) && local_10[0x30] == 0) && sVar1 == 0) {
      iVar12 = (int)*local_10 * (int)*psVar5;
      *(int *)puVar4 = iVar12;
      *(int *)(puVar4 + 0x10) = iVar12;
      *(int *)(puVar4 + 0x20) = iVar12;
      *(int *)(puVar4 + 0x30) = iVar12;
      *(int *)(puVar4 + 0x40) = iVar12;
      *(int *)(puVar4 + 0x50) = iVar12;
      *(int *)(puVar4 + 0x60) = iVar12;
      *(int *)(puVar4 + 0x70) = iVar12;
    }
    else {
      iVar12 = CONCAT22((short)((uint)local_10 >> 0x10),*local_10 * *psVar5);
      uVar15 = (uint)(ushort)(psVar5[0x20] * local_10[0x20]);
      iVar9 = uVar15 + iVar12;
      uVar13 = psVar5[0x30] * local_10[0x30];
      iVar12 = iVar12 - uVar15;
      iVar14 = (uint)uVar13 + (uint)(ushort)(psVar5[0x10] * uVar11);
      local_24 = iVar9 + iVar14;
      iVar8 = (((int)(short)(psVar5[0x10] * uVar11) - (int)(short)uVar13) * 0x16a >> 8) - iVar14;
      local_18 = iVar9 - iVar14;
      local_1c = iVar8 + iVar12;
      uVar11 = psVar5[0x18] * local_10[0x18];
      param_1._0_2_ = (short)iVar12 - (short)iVar8;
      iVar9 = (uint)uVar11 + (uint)(ushort)(psVar5[0x28] * sVar2);
      local_c = (uint)(ushort)(psVar5[0x38] * sVar1) +
                CONCAT22((short)((uint)iVar8 >> 0x10),psVar5[8] * uVar3);
      iVar14 = local_c;
      iVar8 = local_c + iVar9;
      iVar10 = (int)(short)(psVar5[8] * uVar3 - psVar5[0x38] * sVar1);
      iVar12 = (int)(short)(psVar5[0x28] * sVar2 - uVar11);
      iVar16 = (iVar12 + iVar10) * 0x1d9;
      param_3._0_2_ = (short)iVar9;
      local_8 = ((iVar12 * -0x29d >> 8) - iVar8) + (iVar16 >> 8);
      sVar2 = (short)local_8;
      sVar1 = (short)((uint)(((int)(short)local_c - (int)(short)param_3) * 0x16a) >> 8) - sVar2;
      param_3._0_2_ = ((short)((uint)(iVar10 * 0x115) >> 8) - (short)((uint)iVar16 >> 8)) + sVar1;
      param_2._0_2_ = (short)iVar8;
      local_c = iVar14;
      *(int *)(puVar4 + 0x70) = (int)(short)local_24 - (int)(short)param_2;
      *(int *)puVar4 = (int)(short)local_24 + (int)(short)param_2;
      *(int *)(puVar4 + 0x60) = (int)(short)local_1c - (int)sVar2;
      *(int *)(puVar4 + 0x50) = (int)(short)param_1 - (int)sVar1;
      *(int *)(puVar4 + 0x20) = (int)(short)param_1 + (int)sVar1;
      *(int *)(puVar4 + 0x40) = (int)(short)param_3 + (int)(short)local_18;
      iVar14 = local_20;
      *(int *)(puVar4 + 0x30) = (int)(short)local_18 - (int)(short)param_3;
      *(int *)(puVar4 + 0x10) = (int)sVar2 + (int)(short)local_1c;
    }
    local_10 = local_10 + 1;
    psVar5 = psVar5 + 1;
    puVar4 = puVar4 + 2;
    local_14 = local_14 + -1;
  } while (local_14 != 0);
  puVar4 = local_128;
  local_10 = (short *)0x0;
  do {
    puVar6 = (undefined1 *)(*(int *)(param_4 + (int)local_10 * 4) + param_5);
    if ((((((*(int *)(puVar4 + 0xc) == 0 && *(int *)(puVar4 + 0xe) == 0) &&
           *(int *)(puVar4 + 10) == 0) && *(int *)(puVar4 + 8) == 0) && *(int *)(puVar4 + 6) == 0)
        && *(int *)(puVar4 + 4) == 0) && *(int *)(puVar4 + 2) == 0) {
      uVar7 = *(undefined1 *)((*(int *)puVar4 >> 5 & 0x3ffU) + iVar14);
      *puVar6 = uVar7;
      puVar6[1] = uVar7;
      puVar6[2] = uVar7;
      puVar6[4] = uVar7;
      puVar6[5] = uVar7;
      puVar6[6] = uVar7;
      puVar6[7] = uVar7;
    }
    else {
      iVar12 = (uint)*puVar4 + (uint)puVar4[8];
      iVar8 = (uint)*puVar4 - (uint)puVar4[8];
      iVar9 = (uint)puVar4[4] + (uint)puVar4[0xc];
      iVar10 = (((int)(short)puVar4[4] - (int)(short)puVar4[0xc]) * 0x16a >> 8) - iVar9;
      local_24 = iVar9 + iVar12;
      local_18 = iVar12 - iVar9;
      local_1c = iVar10 + iVar8;
      param_1._0_2_ = (short)iVar8 - (short)iVar10;
      iVar12 = (uint)puVar4[6] + (uint)puVar4[10];
      local_20 = (uint)puVar4[10] - (uint)puVar4[6];
      local_c = (uint)puVar4[2] + (uint)puVar4[0xe];
      iVar9 = local_c + iVar12;
      iVar8 = (int)(short)(puVar4[2] - puVar4[0xe]);
      iVar10 = ((short)local_20 + iVar8) * 0x1d9;
      local_14 = iVar10 >> 8;
      local_8 = (((short)local_20 * -0x29d >> 8) - iVar9) + local_14;
      param_3._0_2_ = (short)iVar12;
      sVar2 = (short)local_8;
      sVar1 = (short)((uint)(((int)(short)local_c - (int)(short)param_3) * 0x16a) >> 8) - sVar2;
      param_2._0_2_ = (short)iVar9;
      param_3._0_2_ = ((short)((uint)(iVar8 * 0x115) >> 8) - (short)((uint)iVar10 >> 8)) + sVar1;
      *puVar6 = *(undefined1 *)(((int)(short)param_2 + (int)(short)local_24 >> 5 & 0x3ffU) + iVar14)
      ;
      puVar6[7] = *(undefined1 *)
                   (((int)(short)local_24 - (int)(short)param_2 >> 5 & 0x3ffU) + iVar14);
      puVar6[1] = *(undefined1 *)(((int)sVar2 + (int)(short)local_1c >> 5 & 0x3ffU) + iVar14);
      puVar6[6] = *(undefined1 *)(((int)(short)local_1c - (int)sVar2 >> 5 & 0x3ffU) + iVar14);
      uVar7 = *(undefined1 *)(((int)(short)param_1 + (int)sVar1 >> 5 & 0x3ffU) + iVar14);
      puVar6[5] = *(undefined1 *)(((int)(short)param_1 - (int)sVar1 >> 5 & 0x3ffU) + iVar14);
      puVar6[2] = uVar7;
      uVar7 = *(undefined1 *)(((int)(short)local_18 - (int)(short)param_3 >> 5 & 0x3ffU) + iVar14);
      puVar6[4] = *(undefined1 *)
                   (((int)(short)param_3 + (int)(short)local_18 >> 5 & 0x3ffU) + iVar14);
    }
    puVar4 = puVar4 + 0x10;
    local_10 = (short *)((int)local_10 + 1);
    puVar6[3] = uVar7;
  } while ((int)local_10 < 8);
  return;
}


// ==== FUN_0095e420 @ 0x0095e420 ====

void FUN_0095e420(int param_1,short *param_2,short *param_3,int param_4,int param_5)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_138 [16];
  int local_f8 [8];
  int local_d8 [8];
  int local_b8 [8];
  int local_98 [8];
  int local_78 [8];
  int local_58 [8];
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  short *local_8;
  
  param_2 = *(short **)((int)param_2 + 0x50);
  iVar4 = *(int *)(param_1 + 0x148) + 0x80;
  local_30 = iVar4;
  piVar1 = local_138;
  local_18 = 8;
  do {
    if ((((param_3[8] == 0) && (param_3[0x10] == 0)) && (param_3[0x18] == 0)) &&
       (((param_3[0x20] == 0 && (param_3[0x28] == 0)) &&
        ((param_3[0x30] == 0 && (param_3[0x38] == 0)))))) {
      iVar3 = (int)*param_3 * (int)*param_2 * 4;
      *piVar1 = iVar3;
      piVar1[8] = iVar3;
      piVar1[0x10] = iVar3;
      piVar1[0x18] = iVar3;
      piVar1[0x20] = iVar3;
      piVar1[0x28] = iVar3;
      piVar1[0x30] = iVar3;
      piVar1[0x38] = iVar3;
    }
    else {
      iVar4 = ((int)param_2[0x30] * (int)param_3[0x30] + (int)param_2[0x10] * (int)param_3[0x10]) *
              0x1151;
      local_14 = iVar4 + (int)param_2[0x30] * (int)param_3[0x30] * -0x3b21;
      iVar4 = (int)param_2[0x10] * (int)param_3[0x10] * 0x187e + iVar4;
      iVar3 = ((int)param_2[0x20] * (int)param_3[0x20] + (int)*param_3 * (int)*param_2) * 0x2000;
      iVar6 = iVar4 + iVar3;
      local_38 = iVar6;
      iVar9 = ((int)*param_3 * (int)*param_2 - (int)param_2[0x20] * (int)param_3[0x20]) * 0x2000;
      local_34 = iVar3 - iVar4;
      local_2c = iVar9 - local_14;
      iVar4 = (int)param_2[0x38] * (int)param_3[0x38];
      local_28 = iVar9 + local_14;
      iVar9 = (int)param_2[0x28] * (int)param_3[0x28];
      iVar10 = (int)param_2[0x18] * (int)param_3[0x18];
      iVar7 = (int)param_2[8] * (int)param_3[8];
      local_1c = iVar7 + iVar9;
      local_20 = (local_1c + iVar4 + iVar10) * 0x25a1;
      iVar8 = (iVar4 + iVar7) * -0x1ccd;
      local_c = (iVar9 + iVar10) * -0x5203;
      local_10 = local_20 + (iVar4 + iVar10) * -0x3ec5;
      local_20 = local_20 + local_1c * -0xc7c;
      iVar3 = iVar4 * 0x98e + iVar8 + local_10;
      iVar4 = iVar9 * 0x41b3 + local_20 + local_c;
      iVar9 = iVar10 * 0x6254 + local_10 + local_c;
      iVar8 = iVar7 * 0x300b + local_20 + iVar8;
      local_8 = param_3;
      *piVar1 = iVar6 + 0x400 + iVar8 >> 0xb;
      piVar1[0x38] = (iVar6 - iVar8) + 0x400 >> 0xb;
      piVar1[0x30] = (local_28 - iVar9) + 0x400 >> 0xb;
      piVar1[0x28] = (local_2c - iVar4) + 0x400 >> 0xb;
      piVar1[8] = local_28 + 0x400 + iVar9 >> 0xb;
      piVar1[0x10] = local_2c + 0x400 + iVar4 >> 0xb;
      piVar1[0x20] = (local_34 - iVar3) + 0x400 >> 0xb;
      iVar4 = local_30;
      piVar1[0x18] = local_34 + 0x400 + iVar3 >> 0xb;
      param_3 = local_8;
    }
    param_3 = param_3 + 1;
    param_2 = param_2 + 1;
    piVar1 = piVar1 + 1;
    local_18 = local_18 + -1;
    local_8 = param_3;
  } while (local_18 != 0);
  piVar1 = local_138;
  local_24 = 0;
  do {
    puVar2 = (undefined1 *)(*(int *)(param_4 + local_24 * 4) + param_5);
    local_18 = piVar1[1];
    if ((((local_18 == 0) && (piVar1[2] == 0)) &&
        ((piVar1[3] == 0 && (((piVar1[4] == 0 && (piVar1[5] == 0)) && (piVar1[6] == 0)))))) &&
       (piVar1[7] == 0)) {
      uVar5 = *(undefined1 *)((*piVar1 + 0x10 >> 5 & 0x3ffU) + iVar4);
      *puVar2 = uVar5;
      puVar2[1] = uVar5;
      puVar2[2] = uVar5;
      puVar2[3] = uVar5;
      puVar2[5] = uVar5;
      puVar2[6] = uVar5;
      puVar2[7] = uVar5;
    }
    else {
      iVar9 = (piVar1[6] + piVar1[2]) * 0x1151;
      iVar3 = piVar1[2] * 0x187e + iVar9;
      iVar9 = iVar9 + piVar1[6] * -0x3b21;
      local_2c = (*piVar1 - piVar1[4]) * 0x2000;
      iVar10 = (piVar1[4] + *piVar1) * 0x2000;
      iVar4 = iVar10 + iVar3;
      iVar10 = iVar10 - iVar3;
      local_28 = local_2c + iVar9;
      local_2c = local_2c - iVar9;
      iVar3 = piVar1[5];
      local_14 = piVar1[3];
      iVar9 = piVar1[7];
      local_20 = (local_18 + iVar3 + iVar9 + local_14) * 0x25a1;
      iVar6 = (iVar9 + local_18) * -0x1ccd;
      local_c = (iVar3 + local_14) * -0x5203;
      local_10 = local_20 + (iVar9 + local_14) * -0x3ec5;
      local_1c = local_20 + (local_18 + iVar3) * -0xc7c;
      local_8 = (short *)(iVar9 * 0x98e + iVar6 + local_10);
      iVar3 = iVar3 * 0x41b3 + local_1c + local_c;
      local_14 = local_14 * 0x6254 + local_10 + local_c;
      iVar6 = local_18 * 0x300b + local_1c + iVar6;
      *puVar2 = *(undefined1 *)((iVar4 + 0x20000 + iVar6 >> 0x12 & 0x3ffU) + local_30);
      puVar2[7] = *(undefined1 *)(((iVar4 - iVar6) + 0x20000 >> 0x12 & 0x3ffU) + local_30);
      puVar2[1] = *(undefined1 *)((local_28 + 0x20000 + local_14 >> 0x12 & 0x3ffU) + local_30);
      puVar2[6] = *(undefined1 *)(((local_28 - local_14) + 0x20000 >> 0x12 & 0x3ffU) + local_30);
      puVar2[2] = *(undefined1 *)((local_2c + 0x20000 + iVar3 >> 0x12 & 0x3ffU) + local_30);
      puVar2[5] = *(undefined1 *)(((local_2c - iVar3) + 0x20000 >> 0x12 & 0x3ffU) + local_30);
      puVar2[3] = *(undefined1 *)((iVar10 + 0x20000 + (int)local_8 >> 0x12 & 0x3ffU) + local_30);
      uVar5 = *(undefined1 *)(((iVar10 - (int)local_8) + 0x20000 >> 0x12 & 0x3ffU) + local_30);
      iVar4 = local_30;
    }
    piVar1 = piVar1 + 8;
    local_24 = local_24 + 1;
    puVar2[4] = uVar5;
  } while (local_24 < 8);
  return;
}


// ==== FUN_0095e910 @ 0x0095e910 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0095e910(short *param_1,short *param_2,int *param_3,int param_4,int param_5,int param_6)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int *piVar18;
  undefined4 *puVar19;
  short *local_48;
  short *local_44;
  int *local_40;
  int local_3c;
  int local_8;
  
  local_48 = param_1;
  local_44 = param_2;
  local_40 = param_3;
  local_3c = 8;
  do {
    iVar15 = ((int)local_48[0x10] * (int)local_44[0x10] + (int)local_48[0x30] * (int)local_44[0x30])
             * DAT_00a2f200;
    iVar8 = (int)local_48[0x30] * (int)local_44[0x30] * DAT_00a2f214 + iVar15;
    iVar15 = (int)local_48[0x10] * (int)local_44[0x10] * DAT_00a2f204 + iVar15;
    iVar9 = ((int)local_48[0x20] * (int)local_44[0x20] + (int)*local_48 * (int)*local_44) * 0x2000;
    iVar5 = ((int)*local_48 * (int)*local_44 - (int)local_48[0x20] * (int)local_44[0x20]) * 0x2000;
    iVar10 = iVar9 + iVar15;
    iVar6 = iVar5 + iVar8;
    iVar9 = iVar9 - iVar15;
    iVar5 = iVar5 - iVar8;
    iVar15 = (int)local_48[0x38] * (int)local_44[0x38];
    iVar11 = (int)local_48[0x18] * (int)local_44[0x18];
    iVar16 = (int)local_48[8] * (int)local_44[8];
    iVar8 = (int)local_48[0x28] * (int)local_44[0x28];
    iVar7 = (iVar15 + iVar16) * DAT_00a2f208;
    iVar13 = (iVar8 + iVar11) * DAT_00a2f220;
    iVar17 = (iVar15 + iVar11 + iVar8 + iVar16) * DAT_00a2f20c;
    iVar12 = (iVar15 + iVar11) * DAT_00a2f218 + iVar17;
    iVar17 = (iVar8 + iVar16) * DAT_00a2f1fc + iVar17;
    iVar15 = iVar7 + iVar12 + iVar15 * DAT_00a2f1f8;
    iVar14 = iVar13 + iVar17 + iVar8 * DAT_00a2f21c;
    iVar11 = iVar12 + iVar13 + iVar11 * DAT_00a2f224;
    iVar7 = iVar7 + iVar17 + iVar16 * DAT_00a2f210;
    iVar8 = iVar15 + iVar9 + _DAT_00a2f228;
    local_40[0x20] = (iVar9 - iVar15) + _DAT_00a2f228 >> 0xb;
    local_40[0x18] = iVar8 >> 0xb;
    iVar15 = (iVar6 - iVar11) + _DAT_00a2f228;
    iVar8 = iVar14 + iVar5 + _DAT_00a2f228;
    iVar6 = iVar11 + iVar6 + _DAT_00a2f228;
    local_40[0x28] = (iVar5 - iVar14) + _DAT_00a2f228 >> 0xb;
    local_40[0x30] = iVar15 >> 0xb;
    local_40[0x10] = iVar8 >> 0xb;
    local_40[8] = iVar6 >> 0xb;
    iVar15 = iVar10 + iVar7 + _DAT_00a2f228;
    local_40[0x38] = (iVar10 - iVar7) + _DAT_00a2f228 >> 0xb;
    *local_40 = iVar15 >> 0xb;
    local_48 = local_48 + 1;
    local_40 = local_40 + 1;
    local_44 = local_44 + 1;
    local_3c = local_3c + -1;
  } while (local_3c != 0);
  local_3c = 8;
  local_8 = 0;
  local_40 = param_3;
  do {
    piVar18 = (int *)(param_4 + local_8);
    local_8 = local_8 + 4;
    puVar19 = (undefined4 *)(*piVar18 + param_5);
    iVar15 = (local_40[2] + local_40[6]) * DAT_00a2f200;
    iVar5 = local_40[6] * DAT_00a2f214 + iVar15;
    iVar15 = local_40[2] * DAT_00a2f204 + iVar15;
    iVar11 = (local_40[4] + *local_40) * 0x2000;
    iVar7 = (*local_40 - local_40[4]) * 0x2000;
    iVar12 = iVar11 + iVar15;
    iVar9 = iVar7 + iVar5;
    iVar11 = iVar11 - iVar15;
    iVar7 = iVar7 - iVar5;
    iVar15 = local_40[7];
    iVar5 = local_40[3];
    iVar6 = local_40[1];
    iVar8 = local_40[5];
    iVar10 = (iVar15 + iVar6) * DAT_00a2f208;
    iVar14 = (iVar8 + iVar5) * DAT_00a2f220;
    iVar16 = (iVar15 + iVar5 + iVar8 + iVar6) * DAT_00a2f20c;
    iVar13 = (iVar15 + iVar5) * DAT_00a2f218 + iVar16;
    iVar16 = (iVar8 + iVar6) * DAT_00a2f1fc + iVar16;
    iVar15 = iVar10 + iVar13 + iVar15 * DAT_00a2f1f8;
    iVar8 = iVar14 + iVar16 + iVar8 * DAT_00a2f21c;
    iVar5 = iVar13 + iVar14 + iVar5 * DAT_00a2f224;
    iVar6 = iVar10 + iVar16 + iVar6 * DAT_00a2f210;
    uVar1 = *(undefined1 *)(param_6 + ((iVar12 - iVar6) + _DAT_00a2f22c >> 0x12 & _DAT_00a2f230));
    uVar2 = *(undefined1 *)(param_6 + ((iVar9 - iVar5) + _DAT_00a2f22c >> 0x12 & _DAT_00a2f230));
    uVar3 = *(undefined1 *)(param_6 + ((iVar7 - iVar8) + _DAT_00a2f22c >> 0x12 & _DAT_00a2f230));
    uVar4 = *(undefined1 *)(param_6 + ((iVar11 - iVar15) + _DAT_00a2f22c >> 0x12 & _DAT_00a2f230));
    *puVar19 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)
                                           (param_6 +
                                           (iVar11 + iVar15 + _DAT_00a2f22c >> 0x12 & _DAT_00a2f230)
                                           ),*(undefined1 *)
                                              (param_6 +
                                              (iVar7 + iVar8 + _DAT_00a2f22c >> 0x12 & _DAT_00a2f230
                                              ))),
                                 *(undefined1 *)
                                  (param_6 + (iVar9 + iVar5 + _DAT_00a2f22c >> 0x12 & _DAT_00a2f230)
                                  )),
                        *(undefined1 *)
                         (param_6 + (iVar12 + iVar6 + _DAT_00a2f22c >> 0x12 & _DAT_00a2f230)));
    puVar19[1] = CONCAT31(CONCAT21(CONCAT11(uVar1,uVar2),uVar3),uVar4);
    local_40 = local_40 + 8;
    local_3c = local_3c + -1;
  } while (local_3c != 0);
  return;
}


// ==== FUN_0095eda0 @ 0x0095eda0 ====

void FUN_0095eda0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined1 local_124 [288];
  
  FUN_0095e910(param_3,*(undefined4 *)(param_2 + 0x50),local_124,param_4,param_5,
               *(int *)(param_1 + 0x148) + 0x80);
  return;
}


// ==== FUN_0095ede0 @ 0x0095ede0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0095ede0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,int param_4,
                 int param_5,int param_6)

{
  undefined2 uVar1;
  int *piVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short sVar8;
  short sVar9;
  short sVar11;
  undefined8 uVar7;
  int iVar10;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  short sVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  short sVar24;
  short sVar25;
  short sVar29;
  ulonglong uVar21;
  int iVar26;
  int iVar27;
  ulonglong uVar22;
  ulonglong uVar23;
  int iVar28;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  ulonglong uVar34;
  int iVar38;
  int iVar39;
  ulonglong uVar35;
  ulonglong uVar36;
  int iVar40;
  ulonglong uVar37;
  short sVar41;
  int iVar42;
  int iVar43;
  int iVar44;
  short sVar50;
  undefined8 uVar45;
  short sVar49;
  int iVar51;
  int iVar52;
  short sVar54;
  ulonglong uVar46;
  ulonglong uVar47;
  int iVar53;
  undefined8 uVar48;
  int iVar55;
  int iVar56;
  int iVar57;
  undefined8 uVar58;
  int iVar60;
  int iVar61;
  int iVar62;
  undefined8 uVar59;
  short sVar63;
  int iVar64;
  short sVar68;
  undefined8 uVar65;
  short sVar67;
  int iVar69;
  short sVar70;
  ulonglong uVar66;
  int iVar71;
  int iVar72;
  ulonglong uVar73;
  int iVar74;
  int iVar75;
  undefined8 *local_18;
  undefined8 *local_14;
  undefined8 *local_10;
  int local_c;
  int local_8;
  
  local_18 = param_1;
  local_10 = param_2;
  local_8 = 2;
  local_14 = param_3;
  do {
    uVar7 = local_18[4];
    uVar45 = local_10[4];
    uVar58 = local_18[0xc];
    sVar3 = (short)uVar7 * (short)uVar45;
    sVar8 = (short)((ulonglong)uVar7 >> 0x10) * (short)((ulonglong)uVar45 >> 0x10);
    sVar9 = (short)((ulonglong)uVar7 >> 0x20) * (short)((ulonglong)uVar45 >> 0x20);
    sVar11 = (short)((ulonglong)uVar7 >> 0x30) * (short)((ulonglong)uVar45 >> 0x30);
    uVar37 = CONCAT26(sVar11,CONCAT24(sVar9,CONCAT22(sVar8,sVar3)));
    uVar7 = local_10[0xc];
    sVar17 = (short)uVar58 * (short)uVar7;
    sVar24 = (short)((ulonglong)uVar58 >> 0x10) * (short)((ulonglong)uVar7 >> 0x10);
    sVar25 = (short)((ulonglong)uVar58 >> 0x20) * (short)((ulonglong)uVar7 >> 0x20);
    sVar29 = (short)((ulonglong)uVar58 >> 0x30) * (short)((ulonglong)uVar7 >> 0x30);
    uVar34 = CONCAT26(sVar29,CONCAT24(sVar25,CONCAT22(sVar24,sVar17)));
    uVar45 = pmaddwd(uVar37,DAT_00a2f250);
    uVar58 = pmaddwd(uVar37 >> 0x10,DAT_00a2f250);
    uVar37 = CONCAT26(sVar11 + sVar29,
                      CONCAT24(sVar9 + sVar25,CONCAT22(sVar8 + sVar24,sVar3 + sVar17)));
    uVar21 = pmaddwd(uVar34,DAT_00a2f270);
    uVar34 = pmaddwd(uVar34 >> 0x10,DAT_00a2f270);
    uVar7 = pmaddwd(uVar37,DAT_00a2f248);
    uVar65 = pmaddwd(uVar37 >> 0x10,DAT_00a2f248);
    iVar5 = (int)DAT_00a2f2a0;
    iVar6 = (int)((ulonglong)DAT_00a2f2a0 >> 0x20);
    iVar18 = (int)(uVar21 ^ DAT_00a2f298) + iVar5 + (int)uVar7;
    iVar51 = (int)((ulonglong)uVar7 >> 0x20);
    iVar26 = (int)((uVar21 ^ DAT_00a2f298) >> 0x20) + iVar6 + iVar51;
    iVar42 = (int)uVar45 + (int)uVar7;
    iVar51 = (int)((ulonglong)uVar45 >> 0x20) + iVar51;
    uVar7 = *local_18;
    iVar30 = (int)(uVar34 ^ DAT_00a2f298) + iVar5 + (int)uVar65;
    iVar60 = (int)((ulonglong)uVar65 >> 0x20);
    iVar38 = (int)((uVar34 ^ DAT_00a2f298) >> 0x20) + iVar6 + iVar60;
    uVar45 = *local_10;
    iVar55 = (int)uVar58 + (int)uVar65;
    iVar60 = (int)((ulonglong)uVar58 >> 0x20) + iVar60;
    uVar58 = local_18[8];
    sVar3 = (short)uVar7 * (short)uVar45;
    sVar8 = (short)((ulonglong)uVar7 >> 0x10) * (short)((ulonglong)uVar45 >> 0x10);
    sVar9 = (short)((ulonglong)uVar7 >> 0x20) * (short)((ulonglong)uVar45 >> 0x20);
    sVar11 = (short)((ulonglong)uVar7 >> 0x30) * (short)((ulonglong)uVar45 >> 0x30);
    uVar7 = local_10[8];
    sVar17 = (short)uVar58 * (short)uVar7;
    sVar24 = (short)((ulonglong)uVar58 >> 0x10) * (short)((ulonglong)uVar7 >> 0x10);
    sVar25 = (short)((ulonglong)uVar58 >> 0x20) * (short)((ulonglong)uVar7 >> 0x20);
    sVar29 = (short)((ulonglong)uVar58 >> 0x30) * (short)((ulonglong)uVar7 >> 0x30);
    uVar37 = CONCAT26(sVar11 + sVar29,
                      CONCAT24(sVar9 + sVar25,CONCAT22(sVar8 + sVar24,sVar3 + sVar17)));
    uVar34 = CONCAT26(sVar11 - sVar29,
                      CONCAT24(sVar9 - sVar25,CONCAT22(sVar8 - sVar24,sVar3 - sVar17)));
    uVar7 = pmaddwd(uVar37,DAT_00a2f2a8);
    uVar65 = pmaddwd(uVar37 >> 0x10,DAT_00a2f2a8);
    uVar45 = pmaddwd(uVar34,DAT_00a2f2a8);
    uVar58 = pmaddwd(uVar34 >> 0x10,DAT_00a2f2a8);
    iVar4 = (int)uVar7 * 0x2000;
    iVar10 = (int)((ulonglong)uVar7 >> 0x20) * 0x2000;
    iVar64 = (int)uVar65 * 0x2000;
    iVar69 = (int)((ulonglong)uVar65 >> 0x20) * 0x2000;
    iVar43 = iVar42 + iVar4;
    iVar52 = iVar51 + iVar10;
    iVar4 = iVar4 - iVar42;
    iVar10 = iVar10 - iVar51;
    iVar19 = (int)uVar58 * 0x2000;
    iVar27 = (int)((ulonglong)uVar58 >> 0x20) * 0x2000;
    iVar56 = iVar55 + iVar64;
    iVar61 = iVar60 + iVar69;
    iVar64 = iVar64 - iVar55;
    iVar69 = iVar69 - iVar60;
    iVar31 = iVar30 + iVar19;
    iVar39 = iVar38 + iVar27;
    iVar60 = (int)uVar45 * 0x2000;
    iVar14 = (int)((ulonglong)uVar45 >> 0x20) * 0x2000;
    iVar19 = iVar19 - iVar30;
    iVar27 = iVar27 - iVar38;
    uVar7 = local_18[2];
    iVar30 = iVar18 + iVar60;
    iVar38 = iVar26 + iVar14;
    uVar45 = local_10[2];
    iVar60 = iVar60 - iVar18;
    iVar14 = iVar14 - iVar26;
    uVar58 = local_18[0xe];
    sVar63 = (short)uVar7 * (short)uVar45;
    sVar67 = (short)((ulonglong)uVar7 >> 0x10) * (short)((ulonglong)uVar45 >> 0x10);
    sVar68 = (short)((ulonglong)uVar7 >> 0x20) * (short)((ulonglong)uVar45 >> 0x20);
    sVar70 = (short)((ulonglong)uVar7 >> 0x30) * (short)((ulonglong)uVar45 >> 0x30);
    uVar66 = CONCAT26(sVar70,CONCAT24(sVar68,CONCAT22(sVar67,sVar63)));
    uVar7 = local_10[0xe];
    uVar45 = local_18[10];
    sVar3 = (short)uVar58 * (short)uVar7;
    sVar8 = (short)((ulonglong)uVar58 >> 0x10) * (short)((ulonglong)uVar7 >> 0x10);
    sVar9 = (short)((ulonglong)uVar58 >> 0x20) * (short)((ulonglong)uVar7 >> 0x20);
    sVar11 = (short)((ulonglong)uVar58 >> 0x30) * (short)((ulonglong)uVar7 >> 0x30);
    uVar37 = CONCAT26(sVar11,CONCAT24(sVar9,CONCAT22(sVar8,sVar3)));
    uVar7 = local_10[10];
    uVar58 = local_18[6];
    sVar17 = (short)uVar45 * (short)uVar7;
    sVar24 = (short)((ulonglong)uVar45 >> 0x10) * (short)((ulonglong)uVar7 >> 0x10);
    sVar25 = (short)((ulonglong)uVar45 >> 0x20) * (short)((ulonglong)uVar7 >> 0x20);
    sVar29 = (short)((ulonglong)uVar45 >> 0x30) * (short)((ulonglong)uVar7 >> 0x30);
    uVar22 = CONCAT26(sVar29,CONCAT24(sVar25,CONCAT22(sVar24,sVar17)));
    uVar7 = local_10[6];
    sVar41 = (short)uVar58 * (short)uVar7;
    sVar49 = (short)((ulonglong)uVar58 >> 0x10) * (short)((ulonglong)uVar7 >> 0x10);
    sVar50 = (short)((ulonglong)uVar58 >> 0x20) * (short)((ulonglong)uVar7 >> 0x20);
    sVar54 = (short)((ulonglong)uVar58 >> 0x30) * (short)((ulonglong)uVar7 >> 0x30);
    uVar46 = CONCAT26(sVar54,CONCAT24(sVar50,CONCAT22(sVar49,sVar41)));
    uVar34 = CONCAT26(sVar11 + sVar70,
                      CONCAT24(sVar9 + sVar68,CONCAT22(sVar8 + sVar67,sVar3 + sVar63)));
    uVar47 = CONCAT26(sVar29 + sVar54,
                      CONCAT24(sVar25 + sVar50,CONCAT22(sVar24 + sVar49,sVar17 + sVar41)));
    uVar36 = CONCAT26(sVar11 + sVar54,
                      CONCAT24(sVar9 + sVar50,CONCAT22(sVar8 + sVar49,sVar3 + sVar41)));
    uVar35 = CONCAT26(sVar29 + sVar70,
                      CONCAT24(sVar25 + sVar68,CONCAT22(sVar24 + sVar67,sVar17 + sVar63)));
    uVar23 = CONCAT26(sVar11 + sVar54 + sVar29 + sVar70,
                      CONCAT24(sVar9 + sVar50 + sVar25 + sVar68,
                               CONCAT22(sVar8 + sVar49 + sVar24 + sVar67,
                                        sVar3 + sVar41 + sVar17 + sVar63)));
    uVar7 = pmaddwd(uVar23,DAT_00a2f260);
    uVar21 = pmaddwd(uVar34,_DAT_00a2f258);
    uVar45 = pmaddwd(uVar23 >> 0x10,DAT_00a2f260);
    iVar26 = (int)(uVar21 ^ DAT_00a2f298) + iVar5;
    iVar42 = (int)((uVar21 ^ DAT_00a2f298) >> 0x20) + iVar6;
    uVar23 = pmaddwd(uVar47,DAT_00a2f288);
    uVar47 = pmaddwd(uVar47 >> 0x10,DAT_00a2f288);
    uVar73 = pmaddwd(uVar34 >> 0x10,_DAT_00a2f258);
    uVar21 = pmaddwd(uVar36,DAT_00a2f278);
    iVar20 = (int)(uVar23 ^ DAT_00a2f298) + iVar5;
    iVar28 = (int)((uVar23 ^ DAT_00a2f298) >> 0x20) + iVar6;
    uVar23 = pmaddwd(uVar36 >> 0x10,DAT_00a2f278);
    uVar36 = pmaddwd(uVar35,DAT_00a2f240);
    iVar44 = (int)(uVar47 ^ DAT_00a2f298) + iVar5;
    iVar53 = (int)((uVar47 ^ DAT_00a2f298) >> 0x20) + iVar6;
    uVar34 = pmaddwd(uVar35 >> 0x10,DAT_00a2f240);
    iVar71 = (int)(uVar73 ^ DAT_00a2f298) + iVar5;
    iVar74 = (int)((uVar73 ^ DAT_00a2f298) >> 0x20) + iVar6;
    iVar12 = (int)(uVar21 ^ DAT_00a2f298) + iVar5 + (int)uVar7;
    iVar51 = (int)((ulonglong)uVar7 >> 0x20);
    iVar15 = (int)((uVar21 ^ DAT_00a2f298) >> 0x20) + iVar6 + iVar51;
    iVar57 = (int)(uVar23 ^ DAT_00a2f298) + iVar5 + (int)uVar45;
    iVar18 = (int)((ulonglong)uVar45 >> 0x20);
    iVar62 = (int)((uVar23 ^ DAT_00a2f298) >> 0x20) + iVar6 + iVar18;
    iVar32 = (int)(uVar36 ^ DAT_00a2f298) + iVar5 + (int)uVar7;
    iVar51 = (int)((uVar36 ^ DAT_00a2f298) >> 0x20) + iVar6 + iVar51;
    iVar5 = (int)(uVar34 ^ DAT_00a2f298) + iVar5 + (int)uVar45;
    iVar18 = (int)((uVar34 ^ DAT_00a2f298) >> 0x20) + iVar6 + iVar18;
    uVar7 = pmaddwd(uVar37,DAT_00a2f238);
    uVar45 = pmaddwd(uVar37 >> 0x10,DAT_00a2f238);
    uVar65 = pmaddwd(uVar22,DAT_00a2f280);
    uVar58 = pmaddwd(uVar22 >> 0x10,DAT_00a2f280);
    uVar59 = pmaddwd(uVar46,DAT_00a2f290);
    uVar48 = pmaddwd(uVar46 >> 0x10,DAT_00a2f290);
    iVar6 = (int)uVar7 + iVar26 + iVar12;
    iVar55 = (int)((ulonglong)uVar7 >> 0x20) + iVar42 + iVar15;
    iVar13 = (int)uVar45 + iVar71 + iVar57;
    iVar16 = (int)((ulonglong)uVar45 >> 0x20) + iVar74 + iVar62;
    uVar45 = pmaddwd(uVar66,DAT_00a2f268);
    iVar33 = (int)uVar65 + iVar20 + iVar32;
    iVar40 = (int)((ulonglong)uVar65 >> 0x20) + iVar28 + iVar51;
    uVar7 = pmaddwd(uVar66 >> 0x10,DAT_00a2f268);
    iVar72 = (int)uVar45 + iVar32 + iVar26;
    iVar75 = (int)((ulonglong)uVar45 >> 0x20) + iVar51 + iVar42;
    iVar32 = (int)uVar7 + iVar5 + iVar71;
    iVar71 = (int)((ulonglong)uVar7 >> 0x20) + iVar18 + iVar74;
    iVar51 = (int)uVar58 + iVar44 + iVar5;
    iVar18 = (int)((ulonglong)uVar58 >> 0x20) + iVar53 + iVar18;
    iVar26 = (int)DAT_00a2f2b0;
    iVar5 = (int)((ulonglong)DAT_00a2f2b0 >> 0x20);
    iVar20 = (int)uVar59 + iVar12 + iVar20;
    iVar15 = (int)((ulonglong)uVar59 >> 0x20) + iVar15 + iVar28;
    iVar42 = (int)uVar48 + iVar57 + iVar44;
    iVar12 = (int)((ulonglong)uVar48 >> 0x20) + iVar62 + iVar53;
    local_14[0xe] =
         CONCAT44(CONCAT22((short)((iVar61 - iVar71) + iVar5 >> 0xb),
                           (short)((iVar52 - iVar75) + iVar5 >> 0xb)),
                  CONCAT22((short)((iVar56 - iVar32) + iVar26 >> 0xb),
                           (short)((iVar43 - iVar72) + iVar26 >> 0xb)));
    *local_14 = CONCAT44(CONCAT22((short)(iVar71 + iVar61 + iVar5 >> 0xb),
                                  (short)(iVar75 + iVar52 + iVar5 >> 0xb)),
                         CONCAT22((short)(iVar32 + iVar56 + iVar26 >> 0xb),
                                  (short)(iVar72 + iVar43 + iVar26 >> 0xb)));
    local_14[0xc] =
         CONCAT44(CONCAT22((short)((iVar39 - iVar12) + iVar5 >> 0xb),
                           (short)((iVar38 - iVar15) + iVar5 >> 0xb)),
                  CONCAT22((short)((iVar31 - iVar42) + iVar26 >> 0xb),
                           (short)((iVar30 - iVar20) + iVar26 >> 0xb)));
    local_14[2] = CONCAT44(CONCAT22((short)(iVar12 + iVar39 + iVar5 >> 0xb),
                                    (short)(iVar15 + iVar38 + iVar5 >> 0xb)),
                           CONCAT22((short)(iVar42 + iVar31 + iVar26 >> 0xb),
                                    (short)(iVar20 + iVar30 + iVar26 >> 0xb)));
    local_14[4] = CONCAT44(CONCAT22((short)(iVar27 + iVar18 + iVar5 >> 0xb),
                                    (short)(iVar14 + iVar40 + iVar5 >> 0xb)),
                           CONCAT22((short)(iVar19 + iVar51 + iVar26 >> 0xb),
                                    (short)(iVar60 + iVar33 + iVar26 >> 0xb)));
    local_14[10] = CONCAT44(CONCAT22((short)((iVar27 - iVar18) + iVar5 >> 0xb),
                                     (short)((iVar14 - iVar40) + iVar5 >> 0xb)),
                            CONCAT22((short)((iVar19 - iVar51) + iVar26 >> 0xb),
                                     (short)((iVar60 - iVar33) + iVar26 >> 0xb)));
    local_14[6] = CONCAT44(CONCAT22((short)(iVar69 + iVar16 + iVar5 >> 0xb),
                                    (short)(iVar10 + iVar55 + iVar5 >> 0xb)),
                           CONCAT22((short)(iVar64 + iVar13 + iVar26 >> 0xb),
                                    (short)(iVar4 + iVar6 + iVar26 >> 0xb)));
    local_18 = local_18 + 1;
    local_10 = local_10 + 1;
    local_14[8] = CONCAT44(CONCAT22((short)((iVar69 - iVar16) + iVar5 >> 0xb),
                                    (short)((iVar10 - iVar55) + iVar5 >> 0xb)),
                           CONCAT22((short)((iVar64 - iVar13) + iVar26 >> 0xb),
                                    (short)((iVar4 - iVar6) + iVar26 >> 0xb)));
    local_14 = local_14 + 1;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  local_8 = 8;
  local_14 = param_3;
  local_c = 0;
  do {
    uVar7 = *local_14;
    uVar45 = local_14[1];
    sVar3 = (short)uVar45;
    sVar17 = (short)uVar7;
    sVar8 = (short)((ulonglong)uVar45 >> 0x10);
    sVar24 = (short)((ulonglong)uVar7 >> 0x10);
    iVar18 = CONCAT22(sVar24 + sVar8,sVar17 + sVar3);
    sVar9 = (short)((ulonglong)uVar45 >> 0x20);
    sVar25 = (short)((ulonglong)uVar7 >> 0x20);
    sVar29 = (short)((ulonglong)uVar7 >> 0x30);
    sVar11 = (short)((ulonglong)uVar45 >> 0x30);
    uVar65 = pmaddwd(CONCAT44((int)((ulonglong)uVar45 >> 0x20),(int)((ulonglong)uVar7 >> 0x20)),
                     _DAT_00a2f2c8);
    uVar58 = pmaddwd(CONCAT26(sVar29 + sVar11,CONCAT24(sVar25 + sVar9,iVar18)),_DAT_00a2f2d0);
    iVar4 = (int)((ulonglong)uVar58 >> 0x20);
    iVar51 = (int)((ulonglong)DAT_00a2f2a0 >> 0x20);
    iVar5 = (iVar18 << 0x10) >> 3;
    iVar10 = (int)((uint)(ushort)(sVar17 - sVar3) << 0x10) >> 3;
    iVar18 = (int)uVar65 + iVar4;
    iVar4 = ((uint)((ulonglong)uVar65 >> 0x20) ^ (uint)(DAT_00a2f298 >> 0x20)) + iVar51 + iVar4;
    sVar41 = sVar17 + sVar3;
    sVar49 = sVar24 + sVar8;
    iVar6 = iVar5 + iVar18;
    iVar38 = iVar10 + iVar4;
    iVar5 = iVar5 - iVar18;
    iVar10 = iVar10 - iVar4;
    uVar7 = pmaddwd(uVar7,_DAT_00a2f2d8);
    uVar58 = pmaddwd(CONCAT26(sVar49 + sVar29 + sVar11,
                              CONCAT24(sVar41 + sVar25 + sVar9,CONCAT22(sVar49 * 2,sVar41 * 2))),
                     _DAT_00a2f2f8);
    uVar37 = pmaddwd(CONCAT26(sVar29 + sVar11,CONCAT24(sVar25 + sVar9,CONCAT22(sVar49,sVar41))),
                     _DAT_00a2f2f0);
    uVar34 = pmaddwd(CONCAT26(sVar24 + sVar11,
                              CONCAT24(sVar17 + sVar9,CONCAT22(sVar29 + sVar8,sVar25 + sVar3))),
                     _DAT_00a2f2e8);
    uVar45 = pmaddwd(uVar45,_DAT_00a2f2e0);
    iVar26 = (int)((ulonglong)uVar58 >> 0x20);
    iVar42 = (int)(uVar34 ^ DAT_00a2f298) + (int)DAT_00a2f2a0;
    iVar55 = (int)((uVar34 ^ DAT_00a2f298) >> 0x20) + iVar51;
    iVar18 = (int)(uVar37 ^ DAT_00a2f298) + (int)DAT_00a2f2a0 + iVar26;
    iVar26 = (int)((uVar37 ^ DAT_00a2f298) >> 0x20) + iVar51 + iVar26;
    iVar4 = (int)uVar45 + iVar42 + iVar18;
    iVar30 = (int)((ulonglong)uVar45 >> 0x20) + iVar55 + iVar26;
    iVar51 = (int)uVar7 + iVar55 + iVar18;
    iVar18 = (int)((ulonglong)uVar7 >> 0x20) + iVar42 + iVar26;
    iVar26 = (int)DAT_00a2f2b8;
    iVar42 = (int)((ulonglong)DAT_00a2f2b8 >> 0x20);
    uVar34 = CONCAT44(iVar4 + iVar10 + iVar42 >> 0x12,iVar30 + iVar5 + iVar26 >> 0x12) &
             DAT_00a2f2c0;
    piVar2 = (int *)(param_4 + local_c);
    uVar37 = CONCAT44(iVar18 + iVar38 + iVar42 >> 0x12,iVar51 + iVar6 + iVar26 >> 0x12) &
             DAT_00a2f2c0;
    uVar1 = CONCAT11(*(undefined1 *)(param_6 + (int)uVar34),
                     *(undefined1 *)(param_6 + (int)(uVar34 >> 0x20)));
    local_c = local_c + 4;
    uVar21 = CONCAT44((iVar38 - iVar18) + iVar42 >> 0x12,(iVar6 - iVar51) + iVar26 >> 0x12) &
             DAT_00a2f2c0;
    uVar34 = CONCAT44((iVar10 - iVar4) + iVar42 >> 0x12,(iVar5 - iVar30) + iVar26 >> 0x12) &
             DAT_00a2f2c0;
    local_14 = local_14 + 2;
    *(ulonglong *)(*piVar2 + param_5) =
         CONCAT44(CONCAT22((short)CONCAT31(CONCAT21(uVar1,*(undefined1 *)(param_6 + (int)uVar21)),
                                           *(undefined1 *)(param_6 + (int)(uVar21 >> 0x20))),
                           CONCAT11(*(undefined1 *)(param_6 + (int)(uVar34 >> 0x20)),
                                    *(undefined1 *)(param_6 + (int)uVar34))),
                  CONCAT22(uVar1,CONCAT11(*(undefined1 *)(param_6 + (int)(uVar37 >> 0x20)),
                                          *(undefined1 *)(param_6 + (int)uVar37))));
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  return;
}


// ==== FUN_0095f500 @ 0x0095f500 ====

void FUN_0095f500(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined1 local_124 [288];
  
  FUN_0095ede0(param_3,*(undefined4 *)(param_2 + 0x50),local_124,param_4,param_5,
               *(int *)(param_1 + 0x148) + 0x80);
  return;
}


// ==== FUN_0095f540 @ 0x0095f540 ====

void FUN_0095f540(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  short *psVar6;
  int iVar7;
  short *psVar8;
  int local_94 [32];
  int *local_14;
  undefined1 *local_10;
  int local_c;
  int local_8;
  
  local_14 = local_94 + 8;
  psVar8 = (short *)(param_3 + 0x60);
  local_c = *(int *)(param_1 + 0x148) + 0x80;
  local_8 = 8;
  psVar6 = (short *)(*(int *)(param_2 + 0x50) + 0x60);
  do {
    iVar7 = local_8;
    if (local_8 != 4) {
      if ((((psVar8[-0x28] == 0) && (psVar8[-0x20] == 0)) && (psVar8[-0x18] == 0)) &&
         (((psVar8[-8] == 0 && (*psVar8 == 0)) && (psVar8[8] == 0)))) {
        iVar2 = (int)psVar6[-0x30] * (int)psVar8[-0x30] * 4;
        local_14[-8] = iVar2;
        *local_14 = iVar2;
        local_14[0x10] = iVar2;
      }
      else {
        iVar2 = (int)psVar6[-0x30] * (int)psVar8[-0x30] * 0x4000;
        iVar3 = (int)psVar6[-0x20] * (int)psVar8[-0x20] * 0x3b21 +
                (int)*psVar8 * (int)*psVar6 * -0x187e;
        iVar7 = iVar3 + iVar2;
        local_10 = (undefined1 *)(iVar2 - iVar3);
        iVar3 = (int)psVar6[-8] * (int)psVar8[-8] * 0x2e75 +
                (int)psVar6[-0x18] * (int)psVar8[-0x18] * -0x4587 +
                (int)psVar6[-0x28] * (int)psVar8[-0x28] * 0x21f9 +
                (int)psVar6[8] * (int)psVar8[8] * -0x6c2;
        iVar2 = (int)psVar6[-0x28] * (int)psVar8[-0x28] * 0x5203 +
                (int)psVar6[-0x18] * (int)psVar8[-0x18] * 0x1ccd +
                (int)psVar6[-8] * (int)psVar8[-8] * -0x133e +
                (int)psVar6[8] * (int)psVar8[8] * -0x1050;
        local_14[-8] = iVar7 + 0x800 + iVar2 >> 0xc;
        local_14[0x10] = (iVar7 - iVar2) + 0x800 >> 0xc;
        *local_14 = (int)local_10 + 0x800 + iVar3 >> 0xc;
        iVar2 = ((int)local_10 - iVar3) + 0x800 >> 0xc;
        iVar7 = local_8;
      }
      local_14[8] = iVar2;
    }
    psVar8 = psVar8 + 1;
    psVar6 = psVar6 + 1;
    local_8 = iVar7 + -1;
    local_14 = local_14 + 1;
  } while (0 < local_8);
  piVar5 = local_94;
  local_8 = 0;
  do {
    iVar7 = piVar5[1];
    local_10 = (undefined1 *)(*(int *)(param_4 + local_8 * 4) + param_5);
    if (((iVar7 == 0) && (piVar5[2] == 0)) &&
       ((piVar5[3] == 0 && (((piVar5[5] == 0 && (piVar5[6] == 0)) && (piVar5[7] == 0)))))) {
      uVar1 = *(undefined1 *)((*piVar5 + 0x10 >> 5 & 0x3ffU) + local_c);
      *local_10 = uVar1;
      local_10[1] = uVar1;
      local_10[2] = uVar1;
      local_10[3] = uVar1;
    }
    else {
      iVar3 = piVar5[2] * 0x3b21 + piVar5[6] * -0x187e;
      iVar2 = iVar3 + *piVar5 * 0x4000;
      iVar3 = *piVar5 * 0x4000 - iVar3;
      iVar4 = piVar5[5] * 0x2e75 + piVar5[3] * -0x4587 + iVar7 * 0x21f9 + piVar5[7] * -0x6c2;
      iVar7 = iVar7 * 0x5203 + piVar5[3] * 0x1ccd + piVar5[5] * -0x133e + piVar5[7] * -0x1050;
      *local_10 = *(undefined1 *)((iVar2 + 0x40000 + iVar7 >> 0x13 & 0x3ffU) + local_c);
      local_10[3] = *(undefined1 *)(((iVar2 - iVar7) + 0x40000 >> 0x13 & 0x3ffU) + local_c);
      uVar1 = *(undefined1 *)(((iVar3 - iVar4) + 0x40000 >> 0x13 & 0x3ffU) + local_c);
      local_10[1] = *(undefined1 *)((iVar3 + 0x40000 + iVar4 >> 0x13 & 0x3ffU) + local_c);
      local_10[2] = uVar1;
    }
    piVar5 = piVar5 + 8;
    local_8 = local_8 + 1;
  } while (local_8 < 4);
  return;
}


// ==== FUN_0095f850 @ 0x0095f850 ====

void FUN_0095f850(int param_1,int param_2,short *param_3,int *param_4,int param_5)

{
  undefined1 uVar1;
  short *psVar2;
  short *psVar3;
  int *piVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  int local_48 [7];
  int local_2c;
  int local_28 [7];
  int local_c;
  int local_8;
  
  psVar2 = param_3;
  psVar3 = *(short **)(param_2 + 0x50);
  local_8 = *(int *)(param_1 + 0x148) + 0x80;
  piVar4 = local_48;
  param_3 = (short *)0x6;
  do {
    if (((param_3 != (short *)0x4) && (param_3 != (short *)0x2)) && (param_3 != (short *)0x0)) {
      if (((psVar2[8] == 0) && (psVar2[0x18] == 0)) && ((psVar2[0x28] == 0 && (psVar2[0x38] == 0))))
      {
        iVar6 = (int)*psVar2 * (int)*psVar3 * 4;
        *piVar4 = iVar6;
      }
      else {
        iVar6 = (int)*psVar2 * (int)*psVar3 * 0x8000;
        iVar7 = (int)psVar3[0x28] * (int)psVar2[0x28] * 0x1b37 +
                (int)psVar3[0x18] * (int)psVar2[0x18] * -0x28ba +
                (int)psVar3[0x38] * (int)psVar2[0x38] * -0x1712 +
                (int)psVar3[8] * (int)psVar2[8] * 0x73fc;
        *piVar4 = iVar7 + 0x1000 + iVar6 >> 0xd;
        iVar6 = (iVar6 - iVar7) + 0x1000 >> 0xd;
      }
      piVar4[8] = iVar6;
    }
    if (((param_3 != (short *)0x5) && (param_3 != (short *)0x3)) && (param_3 != (short *)0x1)) {
      if ((((psVar2[9] == 0) && (psVar2[0x19] == 0)) && (psVar2[0x29] == 0)) && (psVar2[0x39] == 0))
      {
        iVar6 = (int)psVar2[1] * (int)psVar3[1] * 4;
        piVar4[1] = iVar6;
      }
      else {
        iVar6 = (int)psVar2[1] * (int)psVar3[1] * 0x8000;
        iVar7 = (int)psVar3[0x29] * (int)psVar2[0x29] * 0x1b37 +
                (int)psVar3[0x19] * (int)psVar2[0x19] * -0x28ba +
                (int)psVar3[0x39] * (int)psVar2[0x39] * -0x1712 +
                (int)psVar3[9] * (int)psVar2[9] * 0x73fc;
        piVar4[1] = iVar7 + 0x1000 + iVar6 >> 0xd;
        iVar6 = (iVar6 - iVar7) + 0x1000 >> 0xd;
      }
      piVar4[9] = iVar6;
    }
    if (((param_3 != (short *)0x6) && (param_3 != (short *)0x4)) && (param_3 != (short *)0x2)) {
      if (((psVar2[10] == 0) && (psVar2[0x1a] == 0)) && ((psVar2[0x2a] == 0 && (psVar2[0x3a] == 0)))
         ) {
        iVar6 = (int)psVar2[2] * (int)psVar3[2] * 4;
        piVar4[2] = iVar6;
      }
      else {
        iVar6 = (int)psVar2[2] * (int)psVar3[2] * 0x8000;
        iVar7 = (int)psVar3[0x2a] * (int)psVar2[0x2a] * 0x1b37 +
                (int)psVar3[0x1a] * (int)psVar2[0x1a] * -0x28ba +
                (int)psVar3[0x3a] * (int)psVar2[0x3a] * -0x1712 +
                (int)psVar3[10] * (int)psVar2[10] * 0x73fc;
        piVar4[2] = iVar7 + 0x1000 + iVar6 >> 0xd;
        iVar6 = (iVar6 - iVar7) + 0x1000 >> 0xd;
      }
      piVar4[10] = iVar6;
    }
    if (((param_3 != (short *)0x7) && (param_3 != (short *)0x5)) && (param_3 != (short *)0x3)) {
      if (((psVar2[0xb] == 0) && (psVar2[0x1b] == 0)) &&
         ((psVar2[0x2b] == 0 && (psVar2[0x3b] == 0)))) {
        iVar6 = (int)psVar2[3] * (int)psVar3[3] * 4;
        piVar4[3] = iVar6;
      }
      else {
        iVar6 = (int)psVar2[3] * (int)psVar3[3] * 0x8000;
        iVar7 = (int)psVar3[0x2b] * (int)psVar2[0x2b] * 0x1b37 +
                (int)psVar3[0x1b] * (int)psVar2[0x1b] * -0x28ba +
                (int)psVar3[0x3b] * (int)psVar2[0x3b] * -0x1712 +
                (int)psVar3[0xb] * (int)psVar2[0xb] * 0x73fc;
        piVar4[3] = iVar7 + 0x1000 + iVar6 >> 0xd;
        iVar6 = (iVar6 - iVar7) + 0x1000 >> 0xd;
      }
      piVar4[0xb] = iVar6;
    }
    iVar6 = (int)param_3 + -2;
    psVar2 = psVar2 + 4;
    psVar3 = psVar3 + 4;
    piVar4 = piVar4 + 4;
    param_3 = (short *)((int)param_3 + -4);
  } while (0 < iVar6);
  puVar5 = (undefined1 *)(*param_4 + param_5);
  if (((local_48[1] == 0) && (local_48[3] == 0)) && ((local_48[5] == 0 && (local_2c == 0)))) {
    uVar1 = *(undefined1 *)((local_48[0] + 0x10 >> 5 & 0x3ffU) + local_8);
    *puVar5 = uVar1;
  }
  else {
    iVar6 = local_48[1] * 0x73fc + local_48[3] * -0x28ba + local_48[5] * 0x1b37 + local_2c * -0x1712
    ;
    uVar1 = *(undefined1 *)(((local_48[0] * 0x8000 - iVar6) + 0x80000 >> 0x14 & 0x3ffU) + local_8);
    *puVar5 = *(undefined1 *)((iVar6 + 0x80000 + local_48[0] * 0x8000 >> 0x14 & 0x3ffU) + local_8);
  }
  puVar5[1] = uVar1;
  puVar5 = (undefined1 *)(param_4[1] + param_5);
  if ((((local_28[1] == 0) && (local_28[3] == 0)) && (local_28[5] == 0)) && (local_c == 0)) {
    uVar1 = *(undefined1 *)((local_28[0] + 0x10 >> 5 & 0x3ffU) + local_8);
    *puVar5 = uVar1;
    puVar5[1] = uVar1;
    return;
  }
  iVar6 = local_28[1] * 0x73fc + local_28[5] * 0x1b37 + local_c * -0x1712 + local_28[3] * -0x28ba;
  uVar1 = *(undefined1 *)(((local_28[0] * 0x8000 - iVar6) + 0x80000 >> 0x14 & 0x3ffU) + local_8);
  *puVar5 = *(undefined1 *)((iVar6 + 0x80000 + local_28[0] * 0x8000 >> 0x14 & 0x3ffU) + local_8);
  puVar5[1] = uVar1;
  return;
}


// ==== FUN_0095fd00 @ 0x0095fd00 ====

void FUN_0095fd00(int param_1,int param_2,ushort *param_3,int *param_4,int param_5)

{
  *(undefined1 *)(param_5 + *param_4) =
       *(undefined1 *)
        (((int)((uint)**(ushort **)(param_2 + 0x50) * (uint)*param_3 + 4) >> 3 & 0x3ffU) + 0x80 +
        *(int *)(param_1 + 0x148));
  return;
}


// ==== FUN_0095fd50 @ 0x0095fd50 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0095fd50(uint param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 uint *param_5)

{
  undefined4 uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  undefined2 uVar6;
  undefined2 uVar8;
  uint5 uVar7;
  undefined8 uVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  undefined2 uVar13;
  undefined8 uVar12;
  uint uVar14;
  undefined2 uVar19;
  undefined8 uVar15;
  undefined2 uVar18;
  undefined2 uVar20;
  undefined8 uVar16;
  ulonglong uVar17;
  undefined8 uVar21;
  undefined2 uVar23;
  undefined2 uVar24;
  undefined8 uVar22;
  undefined8 uVar25;
  
  param_1 = param_1 >> 2;
  do {
    uVar10 = *param_2;
    uVar1 = *param_3;
    uVar14 = (uint)(CONCAT34((int3)(CONCAT25((short)(((uint7)(byte)((uint)uVar10 >> 0x18) << 0x30)
                                                    >> 0x28),
                                             CONCAT14((char)((uint)uVar10 >> 0x10),uVar10)) >> 0x20)
                             ,uVar10) >> 0x18);
    uVar7 = (uint5)uVar14 & 0xffffffff00;
    uVar8 = (undefined2)uVar10;
    uVar17 = (ulonglong)CONCAT43(uVar14,CONCAT12((char)((uint)uVar10 >> 8),uVar8)) &
             0xffffffff00ffffff;
    uVar10 = *param_4;
    uVar11 = psubsw((ulonglong)
                    CONCAT52((int5)(CONCAT43((int)(CONCAT34((int3)(CONCAT25((short)(((uint7)(byte)((
                                                  uint)uVar1 >> 0x18) << 0x30) >> 0x28),
                                                  CONCAT14((char)((uint)uVar1 >> 0x10),uVar1)) >>
                                                  0x20),uVar1) >> 0x18),
                                             CONCAT12((char)((uint)uVar1 >> 8),(short)uVar1)) >>
                                   0x10),(short)uVar1) & 0xffffffff00ff00ff,_DAT_00a2f308);
    uVar15 = psubsw((ulonglong)
                    CONCAT52((int5)(CONCAT43((int)(CONCAT34((int3)(CONCAT25((short)(((uint7)(byte)((
                                                  uint)uVar10 >> 0x18) << 0x30) >> 0x28),
                                                  CONCAT14((char)((uint)uVar10 >> 0x10),uVar10)) >>
                                                  0x20),uVar10) >> 0x18),
                                             CONCAT12((char)((uint)uVar10 >> 8),(short)uVar10)) >>
                                   0x10),(short)uVar10) & 0xffffffff00ff00ff,_DAT_00a2f308);
    uVar18 = (undefined2)((ulonglong)uVar15 >> 0x10);
    uVar13 = (undefined2)((ulonglong)uVar11 >> 0x10);
    uVar12 = pmaddwd(CONCAT44(CONCAT22(uVar18,uVar13),CONCAT22((short)uVar15,(short)uVar11)),
                     _DAT_00a2f310);
    uVar9 = psllw(CONCAT62((int6)(uVar17 >> 0x10),uVar8) & 0xffffffffffff00ff,8);
    uVar23 = (undefined2)((ulonglong)uVar11 >> 0x20);
    uVar19 = (undefined2)((ulonglong)uVar15 >> 0x20);
    uVar24 = (undefined2)((ulonglong)uVar11 >> 0x30);
    uVar20 = (undefined2)((ulonglong)uVar15 >> 0x30);
    uVar22 = pmaddwd(CONCAT26(uVar20,CONCAT24(uVar24,CONCAT22(uVar19,uVar23))),_DAT_00a2f310);
    uVar6 = (undefined2)(uVar17 >> 0x10);
    uVar15 = pmaddwd(CONCAT44(CONCAT22(uVar6,uVar18),CONCAT22(uVar8,(short)uVar15)) &
                     0xffffffff00ffffff,_DAT_00a2f318);
    uVar21 = pmaddwd(CONCAT44(CONCAT22(uVar6,uVar13),CONCAT22(uVar8,(short)uVar11)) &
                     0xffffffff00ffffff,_DAT_00a2f320);
    uVar8 = (undefined2)(uVar7 >> 8);
    uVar6 = (undefined2)(uVar7 >> 0x18);
    uVar25 = pmaddwd(CONCAT26(uVar6,CONCAT24(uVar24,CONCAT22(uVar8,uVar23))),_DAT_00a2f320);
    uVar11 = pmaddwd(CONCAT26(uVar6,CONCAT24(uVar20,CONCAT22(uVar8,uVar19))),_DAT_00a2f318);
    uVar16 = packssdw(CONCAT44((int)((int)uVar12 + ((uint)uVar9 & 0xffff)) >> 8,(int)uVar15 >> 8),
                      CONCAT44(DAT_00a2f300,(int)uVar21 >> 8));
    uVar15 = packssdw(CONCAT44((int)((int)((ulonglong)uVar12 >> 0x20) +
                                    (uint)(ushort)((ulonglong)uVar9 >> 0x10)) >> 8,
                               (int)((longlong)uVar15 >> 0x28)),
                      CONCAT44(DAT_00a2f304,(int)((longlong)uVar21 >> 0x28)));
    sVar2 = (short)uVar16;
    sVar3 = (short)((ulonglong)uVar16 >> 0x10);
    sVar4 = (short)((ulonglong)uVar16 >> 0x20);
    sVar5 = (short)((ulonglong)uVar16 >> 0x30);
    uVar14 = CONCAT13((0 < sVar5) * (sVar5 < 0x100) * (char)((ulonglong)uVar16 >> 0x30) -
                      (0xff < sVar5),
                      CONCAT12((0 < sVar4) * (sVar4 < 0x100) * (char)((ulonglong)uVar16 >> 0x20) -
                               (0xff < sVar4),
                               CONCAT11((0 < sVar3) * (sVar3 < 0x100) *
                                        (char)((ulonglong)uVar16 >> 0x10) - (0xff < sVar3),
                                        (0 < sVar2) * (sVar2 < 0x100) * (char)uVar16 -
                                        (0xff < sVar2))));
    sVar2 = (short)uVar15;
    sVar3 = (short)((ulonglong)uVar15 >> 0x10);
    sVar4 = (short)((ulonglong)uVar15 >> 0x20);
    uVar12 = packssdw(CONCAT44((int)((int)uVar22 + (uint)(ushort)((ulonglong)uVar9 >> 0x20)) >> 8,
                               (int)uVar11 >> 8),CONCAT44(DAT_00a2f300,(int)uVar25 >> 8));
    uVar17 = CONCAT16((0 < sVar4) * (sVar4 < 0x100) * (char)((ulonglong)uVar15 >> 0x20) -
                      (0xff < sVar4),
                      CONCAT15((0 < sVar3) * (sVar3 < 0x100) * (char)((ulonglong)uVar15 >> 0x10) -
                               (0xff < sVar3),
                               CONCAT14((0 < sVar2) * (sVar2 < 0x100) * (char)uVar15 -
                                        (0xff < sVar2),uVar14))) & _DAT_00a2f328;
    uVar9 = packssdw(CONCAT44((int)((int)((ulonglong)uVar22 >> 0x20) +
                                   (uint)(ushort)((ulonglong)uVar9 >> 0x30)) >> 8,
                              (int)((longlong)uVar11 >> 0x28)),
                     CONCAT44(DAT_00a2f304,(int)((longlong)uVar25 >> 0x28)));
    sVar2 = (short)uVar12;
    sVar3 = (short)((ulonglong)uVar12 >> 0x10);
    uVar8 = CONCAT11((0 < sVar3) * (sVar3 < 0x100) * (char)((ulonglong)uVar12 >> 0x10) -
                     (0xff < sVar3),(0 < sVar2) * (sVar2 < 0x100) * (char)uVar12 - (0xff < sVar2));
    sVar2 = (short)((ulonglong)uVar12 >> 0x20);
    sVar3 = (short)((ulonglong)uVar12 >> 0x30);
    uVar10 = CONCAT13((0 < sVar3) * (sVar3 < 0x100) * (char)((ulonglong)uVar12 >> 0x30) -
                      (0xff < sVar3),
                      CONCAT12((0 < sVar2) * (sVar2 < 0x100) * (char)((ulonglong)uVar12 >> 0x20) -
                               (0xff < sVar2),uVar8));
    sVar2 = (short)uVar9;
    sVar3 = (short)((ulonglong)uVar9 >> 0x10);
    sVar4 = (short)((ulonglong)uVar9 >> 0x20);
    param_2 = param_2 + 1;
    *param_5 = uVar14 | (uint)(uVar17 >> 8);
    param_4 = param_4 + 1;
    param_5[1] = CONCAT22(uVar8,(short)(uVar17 >> 0x28));
    param_3 = param_3 + 1;
    param_5[2] = (uint)(CONCAT16((0 < sVar4) * (sVar4 < 0x100) * (char)((ulonglong)uVar9 >> 0x20) -
                                 (0xff < sVar4),
                                 CONCAT15((0 < sVar3) * (sVar3 < 0x100) *
                                          (char)((ulonglong)uVar9 >> 0x10) - (0xff < sVar3),
                                          CONCAT14((0 < sVar2) * (sVar2 < 0x100) * (char)uVar9 -
                                                   (0xff < sVar2),uVar10))) >> 0x18) |
                 (uint)(((ulonglong)(ushort)((uint)uVar10 >> 0x10) << 0x30) >> 0x30);
    param_1 = param_1 - 1;
    param_5 = param_5 + 3;
  } while (param_1 != 0);
  return;
}


// ==== FUN_0095fe90 @ 0x0095fe90 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0095fe90(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar7 = *param_1 - param_1[7];
  fVar1 = param_1[6];
  fVar2 = param_1[2];
  fVar3 = param_1[4];
  fVar4 = param_1[3] + param_1[4] + *param_1 + param_1[7];
  fVar5 = (*param_1 + param_1[7]) - (param_1[3] + param_1[4]);
  fVar6 = param_1[2] + param_1[5] + param_1[1] + param_1[6];
  *param_1 = fVar6 + fVar4;
  param_1[4] = fVar4 - fVar6;
  fVar4 = (((param_1[1] + param_1[6]) - (param_1[2] + param_1[5])) + fVar5) * _DAT_00a2f33c;
  param_1[2] = fVar5 + fVar4;
  param_1[6] = fVar5 - fVar4;
  fVar5 = (param_1[3] - fVar3) + (fVar2 - param_1[5]);
  fVar3 = (param_1[1] - fVar1) + fVar7;
  fVar4 = (fVar5 - fVar3) * _DAT_00a2f338;
  fVar5 = fVar5 * _DAT_00a2f334 + fVar4;
  fVar4 = fVar3 * _DAT_00a2f330 + fVar4;
  fVar2 = ((fVar2 - param_1[5]) + (param_1[1] - fVar1)) * _DAT_00a2f33c;
  fVar1 = fVar2 + fVar7;
  fVar7 = fVar7 - fVar2;
  param_1[5] = fVar5 + fVar7;
  param_1[3] = fVar7 - fVar5;
  param_1[1] = fVar1 + fVar4;
  param_1[7] = fVar1 - fVar4;
  fVar7 = param_1[8] - param_1[0xf];
  fVar1 = param_1[0xe];
  fVar2 = param_1[10];
  fVar3 = param_1[0xc];
  fVar4 = param_1[0xb] + param_1[0xc] + param_1[8] + param_1[0xf];
  fVar5 = (param_1[8] + param_1[0xf]) - (param_1[0xb] + param_1[0xc]);
  fVar6 = param_1[10] + param_1[0xd] + param_1[9] + param_1[0xe];
  param_1[8] = fVar6 + fVar4;
  param_1[0xc] = fVar4 - fVar6;
  fVar4 = (((param_1[9] + param_1[0xe]) - (param_1[10] + param_1[0xd])) + fVar5) * _DAT_00a2f33c;
  param_1[10] = fVar5 + fVar4;
  param_1[0xe] = fVar5 - fVar4;
  fVar5 = (param_1[0xb] - fVar3) + (fVar2 - param_1[0xd]);
  fVar3 = (param_1[9] - fVar1) + fVar7;
  fVar4 = (fVar5 - fVar3) * _DAT_00a2f338;
  fVar5 = fVar5 * _DAT_00a2f334 + fVar4;
  fVar4 = fVar3 * _DAT_00a2f330 + fVar4;
  fVar2 = ((fVar2 - param_1[0xd]) + (param_1[9] - fVar1)) * _DAT_00a2f33c;
  fVar1 = fVar2 + fVar7;
  fVar7 = fVar7 - fVar2;
  param_1[0xd] = fVar5 + fVar7;
  param_1[0xb] = fVar7 - fVar5;
  param_1[9] = fVar1 + fVar4;
  param_1[0xf] = fVar1 - fVar4;
  fVar7 = param_1[0x10] - param_1[0x17];
  fVar1 = param_1[0x16];
  fVar2 = param_1[0x12];
  fVar3 = param_1[0x14];
  fVar4 = param_1[0x13] + param_1[0x14] + param_1[0x10] + param_1[0x17];
  fVar5 = (param_1[0x10] + param_1[0x17]) - (param_1[0x13] + param_1[0x14]);
  fVar6 = param_1[0x12] + param_1[0x15] + param_1[0x11] + param_1[0x16];
  param_1[0x10] = fVar6 + fVar4;
  param_1[0x14] = fVar4 - fVar6;
  fVar4 = (((param_1[0x11] + param_1[0x16]) - (param_1[0x12] + param_1[0x15])) + fVar5) *
          _DAT_00a2f33c;
  param_1[0x12] = fVar5 + fVar4;
  param_1[0x16] = fVar5 - fVar4;
  fVar5 = (param_1[0x13] - fVar3) + (fVar2 - param_1[0x15]);
  fVar3 = (param_1[0x11] - fVar1) + fVar7;
  fVar4 = (fVar5 - fVar3) * _DAT_00a2f338;
  fVar5 = fVar5 * _DAT_00a2f334 + fVar4;
  fVar4 = fVar3 * _DAT_00a2f330 + fVar4;
  fVar2 = ((fVar2 - param_1[0x15]) + (param_1[0x11] - fVar1)) * _DAT_00a2f33c;
  fVar1 = fVar2 + fVar7;
  fVar7 = fVar7 - fVar2;
  param_1[0x15] = fVar5 + fVar7;
  param_1[0x13] = fVar7 - fVar5;
  param_1[0x11] = fVar1 + fVar4;
  param_1[0x17] = fVar1 - fVar4;
  fVar7 = param_1[0x18] - param_1[0x1f];
  fVar1 = param_1[0x1e];
  fVar2 = param_1[0x1a];
  fVar3 = param_1[0x1c];
  fVar4 = param_1[0x1b] + param_1[0x1c] + param_1[0x18] + param_1[0x1f];
  fVar5 = (param_1[0x18] + param_1[0x1f]) - (param_1[0x1b] + param_1[0x1c]);
  fVar6 = param_1[0x1a] + param_1[0x1d] + param_1[0x19] + param_1[0x1e];
  param_1[0x18] = fVar6 + fVar4;
  param_1[0x1c] = fVar4 - fVar6;
  fVar4 = (((param_1[0x19] + param_1[0x1e]) - (param_1[0x1a] + param_1[0x1d])) + fVar5) *
          _DAT_00a2f33c;
  param_1[0x1a] = fVar5 + fVar4;
  param_1[0x1e] = fVar5 - fVar4;
  fVar5 = (param_1[0x1b] - fVar3) + (fVar2 - param_1[0x1d]);
  fVar3 = (param_1[0x19] - fVar1) + fVar7;
  fVar4 = (fVar5 - fVar3) * _DAT_00a2f338;
  fVar5 = fVar5 * _DAT_00a2f334 + fVar4;
  fVar4 = fVar3 * _DAT_00a2f330 + fVar4;
  fVar2 = ((fVar2 - param_1[0x1d]) + (param_1[0x19] - fVar1)) * _DAT_00a2f33c;
  fVar1 = fVar2 + fVar7;
  fVar7 = fVar7 - fVar2;
  param_1[0x1d] = fVar5 + fVar7;
  param_1[0x1b] = fVar7 - fVar5;
  param_1[0x19] = fVar1 + fVar4;
  param_1[0x1f] = fVar1 - fVar4;
  fVar7 = param_1[0x20] - param_1[0x27];
  fVar1 = param_1[0x26];
  fVar2 = param_1[0x22];
  fVar3 = param_1[0x24];
  fVar4 = param_1[0x23] + param_1[0x24] + param_1[0x20] + param_1[0x27];
  fVar5 = (param_1[0x20] + param_1[0x27]) - (param_1[0x23] + param_1[0x24]);
  fVar6 = param_1[0x22] + param_1[0x25] + param_1[0x21] + param_1[0x26];
  param_1[0x20] = fVar6 + fVar4;
  param_1[0x24] = fVar4 - fVar6;
  fVar4 = (((param_1[0x21] + param_1[0x26]) - (param_1[0x22] + param_1[0x25])) + fVar5) *
          _DAT_00a2f33c;
  param_1[0x22] = fVar5 + fVar4;
  param_1[0x26] = fVar5 - fVar4;
  fVar5 = (param_1[0x23] - fVar3) + (fVar2 - param_1[0x25]);
  fVar3 = (param_1[0x21] - fVar1) + fVar7;
  fVar4 = (fVar5 - fVar3) * _DAT_00a2f338;
  fVar5 = fVar5 * _DAT_00a2f334 + fVar4;
  fVar4 = fVar3 * _DAT_00a2f330 + fVar4;
  fVar2 = ((fVar2 - param_1[0x25]) + (param_1[0x21] - fVar1)) * _DAT_00a2f33c;
  fVar1 = fVar2 + fVar7;
  fVar7 = fVar7 - fVar2;
  param_1[0x25] = fVar5 + fVar7;
  param_1[0x23] = fVar7 - fVar5;
  param_1[0x21] = fVar1 + fVar4;
  param_1[0x27] = fVar1 - fVar4;
  fVar7 = param_1[0x28] - param_1[0x2f];
  fVar1 = param_1[0x2e];
  fVar2 = param_1[0x2a];
  fVar3 = param_1[0x2c];
  fVar4 = param_1[0x2b] + param_1[0x2c] + param_1[0x28] + param_1[0x2f];
  fVar5 = (param_1[0x28] + param_1[0x2f]) - (param_1[0x2b] + param_1[0x2c]);
  fVar6 = param_1[0x2a] + param_1[0x2d] + param_1[0x29] + param_1[0x2e];
  param_1[0x28] = fVar6 + fVar4;
  param_1[0x2c] = fVar4 - fVar6;
  fVar4 = (((param_1[0x29] + param_1[0x2e]) - (param_1[0x2a] + param_1[0x2d])) + fVar5) *
          _DAT_00a2f33c;
  param_1[0x2a] = fVar5 + fVar4;
  param_1[0x2e] = fVar5 - fVar4;
  fVar5 = (param_1[0x2b] - fVar3) + (fVar2 - param_1[0x2d]);
  fVar3 = (param_1[0x29] - fVar1) + fVar7;
  fVar4 = (fVar5 - fVar3) * _DAT_00a2f338;
  fVar5 = fVar5 * _DAT_00a2f334 + fVar4;
  fVar4 = fVar3 * _DAT_00a2f330 + fVar4;
  fVar2 = ((fVar2 - param_1[0x2d]) + (param_1[0x29] - fVar1)) * _DAT_00a2f33c;
  fVar1 = fVar2 + fVar7;
  fVar7 = fVar7 - fVar2;
  param_1[0x2d] = fVar5 + fVar7;
  param_1[0x2b] = fVar7 - fVar5;
  param_1[0x29] = fVar1 + fVar4;
  param_1[0x2f] = fVar1 - fVar4;
  fVar7 = param_1[0x30] - param_1[0x37];
  fVar1 = param_1[0x36];
  fVar2 = param_1[0x32];
  fVar3 = param_1[0x34];
  fVar4 = param_1[0x33] + param_1[0x34] + param_1[0x30] + param_1[0x37];
  fVar5 = (param_1[0x30] + param_1[0x37]) - (param_1[0x33] + param_1[0x34]);
  fVar6 = param_1[0x32] + param_1[0x35] + param_1[0x31] + param_1[0x36];
  param_1[0x30] = fVar6 + fVar4;
  param_1[0x34] = fVar4 - fVar6;
  fVar4 = (((param_1[0x31] + param_1[0x36]) - (param_1[0x32] + param_1[0x35])) + fVar5) *
          _DAT_00a2f33c;
  param_1[0x32] = fVar5 + fVar4;
  param_1[0x36] = fVar5 - fVar4;
  fVar5 = (param_1[0x33] - fVar3) + (fVar2 - param_1[0x35]);
  fVar3 = (param_1[0x31] - fVar1) + fVar7;
  fVar4 = (fVar5 - fVar3) * _DAT_00a2f338;
  fVar5 = fVar5 * _DAT_00a2f334 + fVar4;
  fVar4 = fVar3 * _DAT_00a2f330 + fVar4;
  fVar2 = ((fVar2 - param_1[0x35]) + (param_1[0x31] - fVar1)) * _DAT_00a2f33c;
  fVar1 = fVar2 + fVar7;
  fVar7 = fVar7 - fVar2;
  param_1[0x35] = fVar5 + fVar7;
  param_1[0x33] = fVar7 - fVar5;
  param_1[0x31] = fVar1 + fVar4;
  param_1[0x37] = fVar1 - fVar4;
  fVar7 = param_1[0x38] - param_1[0x3f];
  fVar1 = param_1[0x3e];
  fVar2 = param_1[0x3a];
  fVar3 = param_1[0x3c];
  fVar4 = param_1[0x3b] + param_1[0x3c] + param_1[0x38] + param_1[0x3f];
  fVar5 = (param_1[0x38] + param_1[0x3f]) - (param_1[0x3b] + param_1[0x3c]);
  fVar6 = param_1[0x3a] + param_1[0x3d] + param_1[0x39] + param_1[0x3e];
  param_1[0x38] = fVar6 + fVar4;
  param_1[0x3c] = fVar4 - fVar6;
  fVar4 = (((param_1[0x39] + param_1[0x3e]) - (param_1[0x3a] + param_1[0x3d])) + fVar5) *
          _DAT_00a2f33c;
  param_1[0x3a] = fVar5 + fVar4;
  param_1[0x3e] = fVar5 - fVar4;
  fVar5 = (param_1[0x3b] - fVar3) + (fVar2 - param_1[0x3d]);
  fVar3 = (param_1[0x39] - fVar1) + fVar7;
  fVar4 = (fVar5 - fVar3) * _DAT_00a2f338;
  fVar5 = fVar5 * _DAT_00a2f334 + fVar4;
  fVar4 = fVar3 * _DAT_00a2f330 + fVar4;
  fVar2 = ((fVar2 - param_1[0x3d]) + (param_1[0x39] - fVar1)) * _DAT_00a2f33c;
  fVar1 = fVar2 + fVar7;
  fVar7 = fVar7 - fVar2;
  param_1[0x3d] = fVar5 + fVar7;
  param_1[0x3b] = fVar7 - fVar5;
  param_1[0x39] = fVar1 + fVar4;
  param_1[0x3f] = fVar1 - fVar4;
  fVar7 = *param_1 - param_1[0x38];
  fVar1 = param_1[0x30];
  fVar2 = param_1[0x10];
  fVar3 = param_1[0x20];
  fVar4 = param_1[0x20] + param_1[0x18] + param_1[0x38] + *param_1;
  fVar5 = (param_1[0x38] + *param_1) - (param_1[0x20] + param_1[0x18]);
  fVar6 = param_1[0x28] + param_1[0x10] + param_1[0x30] + param_1[8];
  *param_1 = fVar6 + fVar4;
  param_1[0x20] = fVar4 - fVar6;
  fVar4 = (((param_1[0x30] + param_1[8]) - (param_1[0x28] + param_1[0x10])) + fVar5) * _DAT_00a2f33c
  ;
  param_1[0x10] = fVar5 + fVar4;
  param_1[0x30] = fVar5 - fVar4;
  fVar5 = (param_1[0x18] - fVar3) + (fVar2 - param_1[0x28]);
  fVar3 = (param_1[8] - fVar1) + fVar7;
  fVar4 = (fVar5 - fVar3) * _DAT_00a2f338;
  fVar5 = fVar5 * _DAT_00a2f334 + fVar4;
  fVar4 = fVar3 * _DAT_00a2f330 + fVar4;
  fVar2 = ((fVar2 - param_1[0x28]) + (param_1[8] - fVar1)) * _DAT_00a2f33c;
  fVar1 = fVar2 + fVar7;
  fVar7 = fVar7 - fVar2;
  param_1[0x28] = fVar5 + fVar7;
  param_1[0x18] = fVar7 - fVar5;
  param_1[8] = fVar1 + fVar4;
  param_1[0x38] = fVar1 - fVar4;
  fVar7 = param_1[1] - param_1[0x39];
  fVar1 = param_1[0x31];
  fVar2 = param_1[0x11];
  fVar3 = param_1[0x21];
  fVar4 = param_1[0x21] + param_1[0x19] + param_1[0x39] + param_1[1];
  fVar5 = (param_1[0x39] + param_1[1]) - (param_1[0x21] + param_1[0x19]);
  fVar6 = param_1[0x29] + param_1[0x11] + param_1[0x31] + param_1[9];
  param_1[1] = fVar6 + fVar4;
  param_1[0x21] = fVar4 - fVar6;
  fVar4 = (((param_1[0x31] + param_1[9]) - (param_1[0x29] + param_1[0x11])) + fVar5) * _DAT_00a2f33c
  ;
  param_1[0x11] = fVar5 + fVar4;
  param_1[0x31] = fVar5 - fVar4;
  fVar5 = (param_1[0x19] - fVar3) + (fVar2 - param_1[0x29]);
  fVar3 = (param_1[9] - fVar1) + fVar7;
  fVar4 = (fVar5 - fVar3) * _DAT_00a2f338;
  fVar5 = fVar5 * _DAT_00a2f334 + fVar4;
  fVar4 = fVar3 * _DAT_00a2f330 + fVar4;
  fVar2 = ((fVar2 - param_1[0x29]) + (param_1[9] - fVar1)) * _DAT_00a2f33c;
  fVar1 = fVar2 + fVar7;
  fVar7 = fVar7 - fVar2;
  param_1[0x29] = fVar5 + fVar7;
  param_1[0x19] = fVar7 - fVar5;
  param_1[9] = fVar1 + fVar4;
  param_1[0x39] = fVar1 - fVar4;
  fVar7 = param_1[2] - param_1[0x3a];
  fVar1 = param_1[0x32];
  fVar2 = param_1[0x12];
  fVar3 = param_1[0x22];
  fVar4 = param_1[0x22] + param_1[0x1a] + param_1[0x3a] + param_1[2];
  fVar5 = (param_1[0x3a] + param_1[2]) - (param_1[0x22] + param_1[0x1a]);
  fVar6 = param_1[0x2a] + param_1[0x12] + param_1[0x32] + param_1[10];
  param_1[2] = fVar6 + fVar4;
  param_1[0x22] = fVar4 - fVar6;
  fVar4 = (((param_1[0x32] + param_1[10]) - (param_1[0x2a] + param_1[0x12])) + fVar5) *
          _DAT_00a2f33c;
  param_1[0x12] = fVar5 + fVar4;
  param_1[0x32] = fVar5 - fVar4;
  fVar5 = (param_1[0x1a] - fVar3) + (fVar2 - param_1[0x2a]);
  fVar3 = (param_1[10] - fVar1) + fVar7;
  fVar4 = (fVar5 - fVar3) * _DAT_00a2f338;
  fVar5 = fVar5 * _DAT_00a2f334 + fVar4;
  fVar4 = fVar3 * _DAT_00a2f330 + fVar4;
  fVar2 = ((fVar2 - param_1[0x2a]) + (param_1[10] - fVar1)) * _DAT_00a2f33c;
  fVar1 = fVar2 + fVar7;
  fVar7 = fVar7 - fVar2;
  param_1[0x2a] = fVar5 + fVar7;
  param_1[0x1a] = fVar7 - fVar5;
  param_1[10] = fVar1 + fVar4;
  param_1[0x3a] = fVar1 - fVar4;
  fVar7 = param_1[3] - param_1[0x3b];
  fVar1 = param_1[0x33];
  fVar2 = param_1[0x13];
  fVar3 = param_1[0x23];
  fVar4 = param_1[0x23] + param_1[0x1b] + param_1[0x3b] + param_1[3];
  fVar5 = (param_1[0x3b] + param_1[3]) - (param_1[0x23] + param_1[0x1b]);
  fVar6 = param_1[0x2b] + param_1[0x13] + param_1[0x33] + param_1[0xb];
  param_1[3] = fVar6 + fVar4;
  param_1[0x23] = fVar4 - fVar6;
  fVar4 = (((param_1[0x33] + param_1[0xb]) - (param_1[0x2b] + param_1[0x13])) + fVar5) *
          _DAT_00a2f33c;
  param_1[0x13] = fVar5 + fVar4;
  param_1[0x33] = fVar5 - fVar4;
  fVar5 = (param_1[0x1b] - fVar3) + (fVar2 - param_1[0x2b]);
  fVar3 = (param_1[0xb] - fVar1) + fVar7;
  fVar4 = (fVar5 - fVar3) * _DAT_00a2f338;
  fVar5 = fVar5 * _DAT_00a2f334 + fVar4;
  fVar4 = fVar3 * _DAT_00a2f330 + fVar4;
  fVar2 = ((fVar2 - param_1[0x2b]) + (param_1[0xb] - fVar1)) * _DAT_00a2f33c;
  fVar1 = fVar2 + fVar7;
  fVar7 = fVar7 - fVar2;
  param_1[0x2b] = fVar5 + fVar7;
  param_1[0x1b] = fVar7 - fVar5;
  param_1[0xb] = fVar1 + fVar4;
  param_1[0x3b] = fVar1 - fVar4;
  fVar7 = param_1[4] - param_1[0x3c];
  fVar1 = param_1[0x34];
  fVar2 = param_1[0x14];
  fVar3 = param_1[0x24];
  fVar4 = param_1[0x24] + param_1[0x1c] + param_1[0x3c] + param_1[4];
  fVar5 = (param_1[0x3c] + param_1[4]) - (param_1[0x24] + param_1[0x1c]);
  fVar6 = param_1[0x2c] + param_1[0x14] + param_1[0x34] + param_1[0xc];
  param_1[4] = fVar6 + fVar4;
  param_1[0x24] = fVar4 - fVar6;
  fVar4 = (((param_1[0x34] + param_1[0xc]) - (param_1[0x2c] + param_1[0x14])) + fVar5) *
          _DAT_00a2f33c;
  param_1[0x14] = fVar5 + fVar4;
  param_1[0x34] = fVar5 - fVar4;
  fVar5 = (param_1[0x1c] - fVar3) + (fVar2 - param_1[0x2c]);
  fVar3 = (param_1[0xc] - fVar1) + fVar7;
  fVar4 = (fVar5 - fVar3) * _DAT_00a2f338;
  fVar5 = fVar5 * _DAT_00a2f334 + fVar4;
  fVar4 = fVar3 * _DAT_00a2f330 + fVar4;
  fVar2 = ((fVar2 - param_1[0x2c]) + (param_1[0xc] - fVar1)) * _DAT_00a2f33c;
  fVar1 = fVar2 + fVar7;
  fVar7 = fVar7 - fVar2;
  param_1[0x2c] = fVar5 + fVar7;
  param_1[0x1c] = fVar7 - fVar5;
  param_1[0xc] = fVar1 + fVar4;
  param_1[0x3c] = fVar1 - fVar4;
  fVar7 = param_1[5] - param_1[0x3d];
  fVar1 = param_1[0x35];
  fVar2 = param_1[0x15];
  fVar3 = param_1[0x25];
  fVar4 = param_1[0x25] + param_1[0x1d] + param_1[0x3d] + param_1[5];
  fVar5 = (param_1[0x3d] + param_1[5]) - (param_1[0x25] + param_1[0x1d]);
  fVar6 = param_1[0x2d] + param_1[0x15] + param_1[0x35] + param_1[0xd];
  param_1[5] = fVar6 + fVar4;
  param_1[0x25] = fVar4 - fVar6;
  fVar4 = (((param_1[0x35] + param_1[0xd]) - (param_1[0x2d] + param_1[0x15])) + fVar5) *
          _DAT_00a2f33c;
  param_1[0x15] = fVar5 + fVar4;
  param_1[0x35] = fVar5 - fVar4;
  fVar5 = (param_1[0x1d] - fVar3) + (fVar2 - param_1[0x2d]);
  fVar3 = (param_1[0xd] - fVar1) + fVar7;
  fVar4 = (fVar5 - fVar3) * _DAT_00a2f338;
  fVar5 = fVar5 * _DAT_00a2f334 + fVar4;
  fVar4 = fVar3 * _DAT_00a2f330 + fVar4;
  fVar2 = ((fVar2 - param_1[0x2d]) + (param_1[0xd] - fVar1)) * _DAT_00a2f33c;
  fVar1 = fVar2 + fVar7;
  fVar7 = fVar7 - fVar2;
  param_1[0x2d] = fVar5 + fVar7;
  param_1[0x1d] = fVar7 - fVar5;
  param_1[0xd] = fVar1 + fVar4;
  param_1[0x3d] = fVar1 - fVar4;
  fVar7 = param_1[6] - param_1[0x3e];
  fVar1 = param_1[0x36];
  fVar2 = param_1[0x16];
  fVar3 = param_1[0x26];
  fVar4 = param_1[0x26] + param_1[0x1e] + param_1[0x3e] + param_1[6];
  fVar5 = (param_1[0x3e] + param_1[6]) - (param_1[0x26] + param_1[0x1e]);
  fVar6 = param_1[0x2e] + param_1[0x16] + param_1[0x36] + param_1[0xe];
  param_1[6] = fVar6 + fVar4;
  param_1[0x26] = fVar4 - fVar6;
  fVar4 = (((param_1[0x36] + param_1[0xe]) - (param_1[0x2e] + param_1[0x16])) + fVar5) *
          _DAT_00a2f33c;
  param_1[0x16] = fVar5 + fVar4;
  param_1[0x36] = fVar5 - fVar4;
  fVar5 = (param_1[0x1e] - fVar3) + (fVar2 - param_1[0x2e]);
  fVar3 = (param_1[0xe] - fVar1) + fVar7;
  fVar4 = (fVar5 - fVar3) * _DAT_00a2f338;
  fVar5 = fVar5 * _DAT_00a2f334 + fVar4;
  fVar4 = fVar3 * _DAT_00a2f330 + fVar4;
  fVar2 = ((fVar2 - param_1[0x2e]) + (param_1[0xe] - fVar1)) * _DAT_00a2f33c;
  fVar1 = fVar2 + fVar7;
  fVar7 = fVar7 - fVar2;
  param_1[0x2e] = fVar5 + fVar7;
  param_1[0x1e] = fVar7 - fVar5;
  param_1[0xe] = fVar1 + fVar4;
  param_1[0x3e] = fVar1 - fVar4;
  fVar7 = param_1[7] - param_1[0x3f];
  fVar1 = param_1[0x37];
  fVar2 = param_1[0x17];
  fVar3 = param_1[0x27];
  fVar4 = param_1[0x27] + param_1[0x1f] + param_1[0x3f] + param_1[7];
  fVar5 = (param_1[0x3f] + param_1[7]) - (param_1[0x27] + param_1[0x1f]);
  fVar6 = param_1[0x2f] + param_1[0x17] + param_1[0x37] + param_1[0xf];
  param_1[7] = fVar6 + fVar4;
  param_1[0x27] = fVar4 - fVar6;
  fVar4 = (((param_1[0x37] + param_1[0xf]) - (param_1[0x2f] + param_1[0x17])) + fVar5) *
          _DAT_00a2f33c;
  param_1[0x17] = fVar5 + fVar4;
  param_1[0x37] = fVar5 - fVar4;
  fVar5 = (param_1[0x1f] - fVar3) + (fVar2 - param_1[0x2f]);
  fVar3 = (param_1[0xf] - fVar1) + fVar7;
  fVar4 = (fVar5 - fVar3) * _DAT_00a2f338;
  fVar5 = fVar5 * _DAT_00a2f334 + fVar4;
  fVar4 = fVar3 * _DAT_00a2f330 + fVar4;
  fVar2 = ((fVar2 - param_1[0x2f]) + (param_1[0xf] - fVar1)) * _DAT_00a2f33c;
  fVar1 = fVar2 + fVar7;
  fVar7 = fVar7 - fVar2;
  param_1[0x2f] = fVar5 + fVar7;
  param_1[0x1f] = fVar7 - fVar5;
  param_1[0xf] = fVar1 + fVar4;
  param_1[0x3f] = fVar1 - fVar4;
  return;
}


