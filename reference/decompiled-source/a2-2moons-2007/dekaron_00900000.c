// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x900000-0x90ffff

// ==== FUN_00901ba8 @ 0x00901ba8 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00901ba8(int *param_1,int *param_2,uint param_3,int *param_4,uint param_5,uint param_6,
                uint *param_7,uint *param_8)

{
  double dVar1;
  double dVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  int in_ECX;
  uint uVar9;
  uint uVar10;
  undefined8 uVar11;
  int local_6c [3];
  undefined4 *local_60;
  int local_5c;
  int *local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  int local_44;
  int local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 local_30;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  int *local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  if (param_5 == 0) goto LAB_009022d1;
  local_8 = 0;
  if (param_3 == 0) {
    local_c = 1;
  }
  else {
    local_c = param_5 / param_3;
  }
  iVar7 = FUN_008f4f7c(*param_7,&local_38);
  if (-1 < iVar7) {
    if (_DAT_0099d098 <= local_38) {
      if (_DAT_0099d098 < local_38) {
        local_38 = local_38 + *(double *)(in_ECX + 0xb0);
      }
      else {
        local_38 = 0.0;
      }
    }
    else {
      local_38 = local_38 - *(double *)(in_ECX + 0xb0);
    }
    if (_DAT_0099d098 <= local_30) {
      if (_DAT_0099d098 < local_30) {
        local_30 = local_30 + *(double *)(in_ECX + 0xb0);
      }
      else {
        local_30 = 0.0;
      }
    }
    else {
      local_30 = local_30 - *(double *)(in_ECX + 0xb0);
    }
    iVar7 = FUN_00803910(local_38);
    if ((iVar7 == 0) || (local_38 < _DAT_0099d098)) {
      local_8 = 0;
    }
    else {
      local_8 = __ftol();
    }
    if ((local_30 < _DAT_0099d098) || (param_5 <= local_8 * param_3)) {
      if (*(int *)(in_ECX + 0x58) == 0) goto LAB_009022d1;
      *(undefined4 *)(in_ECX + 0x5c) = 1;
      if (param_2 == (int *)0x0) {
        return 0;
      }
      goto LAB_00901da3;
    }
    iVar7 = FUN_00803910(local_30);
    if (iVar7 == 0) {
      iVar7 = local_c - 1;
    }
    else {
      iVar7 = __ftol();
    }
    if (iVar7 + 1U < local_c) {
      local_c = iVar7 + 1U;
    }
  }
  if (param_2 == (int *)0x0) {
    return 0;
  }
  if ((param_8 == (uint *)0x0) && (iVar7 = FUN_008f974c(param_6,param_4,param_5), iVar7 < 0)) {
    return iVar7;
  }
  param_6 = 0xffffffff;
  uVar10 = 0;
  local_14 = 0;
  if (param_5 != 0) {
    do {
      uVar9 = *(uint *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) +
                                *(int *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) +
                                                 param_4[uVar10] * 4) + 4) * 4) + 4);
      local_14 = local_14 | uVar9;
      param_6 = param_6 & uVar9;
      uVar10 = uVar10 + 1;
    } while (uVar10 < param_5);
  }
  local_24 = ~(local_14 >> 7) & 1;
  local_20 = param_6 & 2;
  local_28 = param_6 & 0x40;
  param_6 = param_6 & 0x400;
  if ((local_14 & 0x100000) == 0) {
    if ((param_6 == 0) && ((*(byte *)(*(int *)(in_ECX + 8) + 0x71) & 2) == 0)) goto LAB_00901dca;
  }
  else if ((local_8 < *(uint *)(in_ECX + 0x68)) || (*(uint *)(in_ECX + 0x6c) < local_c)) {
    param_6 = 0;
LAB_00901dca:
    *(undefined4 *)(in_ECX + 0x60) = 1;
  }
  if (local_8 + 1 == local_c) {
    param_4 = param_4 + local_8 * param_3;
LAB_00901da3:
    for (; param_3 != 0; param_3 = param_3 - 1) {
      *param_2 = *param_4;
      param_4 = param_4 + 1;
      param_2 = param_2 + 1;
    }
    return 0;
  }
  local_1c = param_3;
  local_14 = local_28;
  local_10 = local_28;
  if (param_3 < param_5) {
    local_18 = param_4;
    do {
      if ((local_10 == 0) && (local_14 == 0)) goto LAB_00901e5b;
      iVar7 = *(int *)(*(int *)(in_ECX + 8) + 0x14);
      iVar3 = *(int *)(iVar7 + *local_18 * 4);
      iVar7 = *(int *)(iVar7 + param_4[local_1c] * 4);
      if ((*(int *)(iVar3 + 4) == *(int *)(iVar7 + 4)) &&
         (*(int *)(iVar3 + 8) == *(int *)(iVar7 + 8))) {
        if (*(int *)(iVar3 + 0xc) != *(int *)(iVar7 + 0xc)) {
          local_10 = 0;
        }
        if (*(int *)(iVar3 + 0x10) != *(int *)(iVar7 + 0x10)) goto LAB_00901e40;
      }
      else {
        local_10 = 0;
LAB_00901e40:
        local_14 = 0;
      }
      local_18 = local_18 + 1;
      local_1c = local_1c + 1;
    } while (local_1c < param_5);
  }
  if (local_14 == 0) {
LAB_00901e5b:
    param_6 = 0;
  }
  if ((local_10 != 0) && (local_14 != 0)) goto LAB_00901da3;
  if (param_6 == 0) {
LAB_00901ee3:
    local_20 = 0;
  }
  else {
    if (local_10 == 0) {
      iVar7 = *(int *)(*(int *)(in_ECX + 8) + 0x14);
      local_14 = 1;
      if (1 < param_3) {
        iVar3 = *(int *)(*(int *)(in_ECX + 8) + 0x14);
        local_18 = param_4 + param_3 + 1;
        do {
          if (*(int *)(*(int *)(iVar7 + param_4[param_3] * 4) + 0xc) -
              *(int *)(*(int *)(iVar7 + *param_4 * 4) + 0xc) !=
              *(int *)(*(int *)(iVar3 + *local_18 * 4) + 0xc) -
              *(int *)(*(int *)(iVar3 + param_4[local_14] * 4) + 0xc)) {
            param_6 = 0;
            break;
          }
          local_14 = local_14 + 1;
          local_18 = local_18 + 1;
        } while (local_14 < param_3);
      }
    }
    if (param_6 == 0) goto LAB_00901ee3;
  }
  if ((param_8 == (uint *)0x0) || (local_20 != 0)) {
    if (param_6 != 0) {
      iVar7 = 1;
      if (param_3 < param_5) {
        iVar7 = *(int *)(*(int *)(in_ECX + 8) + 0x14);
        iVar7 = *(int *)(*(int *)(iVar7 + param_4[param_3] * 4) + 0xc) -
                *(int *)(*(int *)(iVar7 + *param_4 * 4) + 0xc);
      }
      param_5 = *param_7;
      if ((iVar7 != 1) || ((*(byte *)(*(int *)(in_ECX + 8) + 0x6f) & 1) == 0)) {
        dVar1 = (double)iVar7;
        if (iVar7 < 0) {
          dVar1 = dVar1 + _DAT_009c2f50;
        }
        param_7 = (uint *)iVar7;
        param_8 = (uint *)FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,dVar1);
        if (param_8 == (uint *)0xffffffff) {
          return -0x7ff8fff2;
        }
        local_3c = 0xffffffff;
        local_38 = -NAN;
        local_30 = -NAN;
        if ((**(byte **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + param_5 * 4) & 2) == 0) {
          iVar7 = FUN_008f69da(param_1,0x10200001,&local_3c,&param_5,0,4);
          if (iVar7 < 0) {
            return iVar7;
          }
          iVar7 = FUN_008f69da(param_1,0x10400001,&local_38,&local_3c,0,4);
          if (iVar7 < 0) {
            return iVar7;
          }
          iVar7 = FUN_008f69da(param_1,0x10100001,(int)&local_38 + 4,&local_38,0,8);
          if (iVar7 < 0) {
            return iVar7;
          }
          iVar7 = FUN_008f69da(param_1,0x20400001,&local_30,(int)&local_38 + 4,&local_3c,6);
          if (iVar7 < 0) {
            return iVar7;
          }
          param_5 = (uint)local_30;
        }
        iVar7 = FUN_008f69da(param_1,0x20500001,(int)&local_30 + 4,&param_5,&param_8,2);
        if (iVar7 < 0) {
          return iVar7;
        }
        param_5 = local_30._4_4_;
      }
      iVar7 = *(int *)(in_ECX + 8);
      param_7 = *(uint **)(*(int *)(*(int *)(iVar7 + 0x14) + *param_4 * 4) + 8);
      if (param_7 != (uint *)0xffffffff) {
        *(undefined4 *)(*(int *)(*(int *)(iVar7 + 0x14) + (int)param_7 * 4) + 4) =
             *(undefined4 *)(iVar7 + 0x88);
        local_3c = 0xffffffff;
        local_38 = -NAN;
        local_30 = -NAN;
        if ((**(byte **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + (int)param_7 * 4) & 2) == 0) {
          iVar7 = FUN_008f69da(param_1,0x10200001,&local_3c,&param_7,0,4);
          if (iVar7 < 0) {
            return iVar7;
          }
          iVar7 = FUN_008f69da(param_1,0x10400001,&local_38,&local_3c,0,4);
          if (iVar7 < 0) {
            return iVar7;
          }
          iVar7 = FUN_008f69da(param_1,0x10100001,(int)&local_38 + 4,&local_38,0,8);
          if (iVar7 < 0) {
            return iVar7;
          }
          iVar7 = FUN_008f69da(param_1,0x20400001,&local_30,(int)&local_38 + 4,&local_3c,6);
          if (iVar7 < 0) {
            return iVar7;
          }
          param_7 = (uint *)(uint)local_30;
        }
        iVar7 = FUN_008f69da(param_1,0x20400001,(int)&local_30 + 4,&param_7,&param_5,0);
        if (iVar7 < 0) {
          return iVar7;
        }
        param_5 = local_30._4_4_;
      }
      if (*(int *)(*(int *)(in_ECX + 8) + 0x30) != 0) {
        param_8 = (uint *)0xffffffff;
        iVar7 = FUN_008f69da(param_1,0x10000001,&param_8,&param_5,0,4);
        if (iVar7 < 0) {
          return iVar7;
        }
        param_5 = (uint)param_8;
        *(undefined4 *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + (int)param_8 * 4) + 4) =
             *(undefined4 *)(*(int *)(in_ECX + 8) + 0x8c);
      }
      param_8 = (uint *)0x0;
      if (param_3 == 0) {
        return 0;
      }
      param_1 = param_4;
      do {
        iVar7 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x88),0,0,0);
        *(int *)(((int)param_2 - (int)param_4) + (int)param_1) = iVar7;
        if (iVar7 == -1) {
          return -0x7ff8fff2;
        }
        puVar4 = *(uint **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + iVar7 * 4);
        FUN_00914e44();
        puVar4[0xd] = 0xffffffff;
        puVar4[2] = param_5;
        *puVar4 = 0x1f;
        *(undefined8 *)(puVar4 + 8) = *(undefined8 *)(in_ECX + 0xa0);
        *(undefined8 *)(puVar4 + 10) = *(undefined8 *)(in_ECX + 0xa8);
        if (local_8 < local_c) {
          iVar7 = local_c - local_8;
          piVar8 = param_4 + local_8 * param_3 + (int)param_8;
          do {
            puVar5 = *(uint **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *piVar8 * 4);
            *puVar4 = *puVar4 & *puVar5;
            if ((*puVar5 & 0x100) != 0) {
              if (*(double *)(puVar5 + 8) < *(double *)(puVar4 + 8)) {
                *(undefined8 *)(puVar4 + 8) = *(undefined8 *)(puVar5 + 8);
              }
              if (*(double *)(puVar4 + 10) < *(double *)(puVar5 + 10)) {
                *(undefined8 *)(puVar4 + 10) = *(undefined8 *)(puVar5 + 10);
              }
            }
            piVar8 = piVar8 + param_3;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
        dVar1 = *(double *)(puVar4 + 8);
        dVar2 = *(double *)(puVar4 + 10);
        if ((!NAN(dVar1) && !NAN(dVar2)) && dVar1 < dVar2 != (dVar1 == dVar2)) {
          *(byte *)((int)puVar4 + 1) = *(byte *)((int)puVar4 + 1) | 1;
        }
        if (*(double *)(puVar4 + 8) == *(double *)(puVar4 + 10)) {
          *(byte *)puVar4 = (byte)*puVar4 | 0x80;
        }
        param_8 = (uint *)((int)param_8 + 1);
        param_1 = param_1 + 1;
      } while (param_8 < param_3);
      return 0;
    }
    if (local_24 != 0) {
      if ((**(byte **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *param_7 * 4) & 1) != 0) {
        iVar7 = FUN_008f4afb();
        if (iVar7 == 0) {
          return -0x7ff8fff2;
        }
        uVar10 = 0;
        if (param_3 != 0) {
          do {
            *(uint *)(iVar7 + uVar10 * 4) = *param_7;
            uVar10 = uVar10 + 1;
          } while (uVar10 < param_3);
        }
        uVar11 = FUN_008f4c18(param_2,param_3);
        if ((int)uVar11 < 0) {
          return (int)uVar11;
        }
        iVar7 = FUN_008f8aec(param_1,param_2,param_4,param_4 + param_3,
                             (int)((ulonglong)uVar11 >> 0x20),param_3);
        if (iVar7 < 0) {
          return iVar7;
        }
        return 0;
      }
      uVar10 = local_c - local_8;
      param_5 = uVar10;
      if ((4 < uVar10) ||
         (((param_3 != 1 || (local_28 != 0)) && ((4 < param_3 || (local_10 == 0)))))) {
        if (*(int *)(in_ECX + 0x58) != 0) {
          *(undefined4 *)(in_ECX + 0x60) = 1;
        }
        iVar7 = FUN_008f4afb();
        if (iVar7 == 0) {
          return -0x7ff8fff2;
        }
        uVar11 = FUN_008f4c18(iVar7,(param_3 + uVar10 * 3) * 2 + 4);
        iVar7 = (int)((ulonglong)uVar11 >> 0x20);
        if ((int)uVar11 < 0) {
          return (int)uVar11;
        }
        uVar9 = 0;
        do {
          local_6c[uVar9] = iVar7;
          iVar7 = iVar7 + 4;
          uVar9 = uVar9 + 1;
        } while (uVar9 < 4);
        uVar9 = 4;
        do {
          local_6c[uVar9] = iVar7;
          iVar7 = iVar7 + uVar10 * 4;
          uVar9 = uVar9 + 1;
        } while (uVar9 < 10);
        uVar10 = 10;
        do {
          local_6c[uVar10] = iVar7;
          iVar7 = iVar7 + param_3 * 4;
          uVar10 = uVar10 + 1;
        } while (uVar10 < 0xc);
        param_8 = (uint *)*param_7;
        if ((**(byte **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + (int)param_8 * 4) & 2) == 0) {
          iVar7 = FUN_008f69da(param_1,0x10200001,local_6c[0],&param_8,0,4);
          if (iVar7 < 0) {
            return iVar7;
          }
          iVar7 = FUN_008f69da(param_1,0x10400001,local_6c[1],local_6c[0],0,4);
          if (iVar7 < 0) {
            return iVar7;
          }
          iVar7 = FUN_008f69da(param_1,0x10100001,local_6c[2],local_6c[1],0,8);
          if (iVar7 < 0) {
            return iVar7;
          }
          iVar7 = FUN_008f69da(param_1,0x20400001,local_60,local_6c[2],local_6c[0],6);
          if (iVar7 < 0) {
            return iVar7;
          }
          param_8 = (uint *)*local_60;
        }
        if (((*(byte *)(*(int *)(in_ECX + 8) + 0x71) & 2) == 0) || (4 < param_5)) {
          uVar10 = 0;
          if (param_5 != 0) {
            param_7 = (uint *)(local_5c - (int)local_58);
            piVar8 = local_58;
            do {
              *(uint **)((int)param_7 + (int)piVar8) = param_8;
              param_6 = local_8 + uVar10;
              dVar1 = (double)(int)param_6;
              if ((int)param_6 < 0) {
                dVar1 = dVar1 + _DAT_009c2f50;
              }
              iVar7 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,-dVar1);
              *piVar8 = iVar7;
              if (iVar7 == -1) {
                return -0x7ff8fff2;
              }
              uVar10 = uVar10 + 1;
              piVar8 = piVar8 + 1;
            } while (uVar10 < param_5);
          }
          uVar10 = param_5 & 0xfffff;
          iVar7 = FUN_008f69da(param_1,uVar10 | 0x20400000,local_54,local_5c,local_58,2);
          if (iVar7 < 0) {
            return iVar7;
          }
          iVar7 = FUN_008f93f6(param_1,local_50,local_4c,local_54,param_5);
          if (iVar7 < 0) {
            return iVar7;
          }
          iVar7 = FUN_008f69da(param_1,uVar10 | 0x20300000,local_48,local_4c,local_50,0x17);
          if (iVar7 < 0) {
            return iVar7;
          }
        }
        else {
          if (local_8 != 0) {
            param_7 = (uint *)local_8;
            dVar1 = (double)(int)local_8;
            if ((int)local_8 < 0) {
              dVar1 = dVar1 + _DAT_009c2f50;
            }
            param_6 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,-dVar1);
            if (param_6 == 0xffffffff) {
              return -0x7ff8fff2;
            }
            param_7 = (uint *)0xffffffff;
            iVar7 = FUN_008f69da(param_1,0x20400001,&param_7,&param_8,&param_6,4);
            if (iVar7 < 0) {
              return iVar7;
            }
            param_8 = param_7;
          }
          if (*(int *)(*(int *)(in_ECX + 8) + 0x30) != 0) {
            param_7 = (uint *)0xffffffff;
            iVar7 = FUN_008f69da(param_1,0x10000001,&param_7,&param_8,0,4);
            if (iVar7 < 0) {
              return iVar7;
            }
            param_8 = param_7;
            *(undefined4 *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + (int)param_7 * 4) + 4)
                 = *(undefined4 *)(*(int *)(in_ECX + 8) + 0x8c);
          }
          if (*(int *)(in_ECX + 0x48) == -1) {
            iVar7 = FUN_009152bf(&DAT_00a1fc7c,0x751,4,4);
            *(int *)(in_ECX + 0x48) = iVar7;
            if (iVar7 == -1) {
              return -0x7ff8fff2;
            }
            uVar10 = 0;
            do {
              uVar9 = 0;
              do {
                if (uVar10 == uVar9) {
                  uVar11 = 0x3ff0000000000000;
                }
                else {
                  uVar11 = 0;
                }
                iVar7 = FUN_00915318(*(undefined4 *)(in_ECX + 0x48),uVar10,uVar9,uVar11);
                if (iVar7 == -1) {
                  return -0x7ff8fff2;
                }
                uVar9 = uVar9 + 1;
              } while (uVar9 < 4);
              uVar10 = uVar10 + 1;
            } while (uVar10 < 4);
          }
          uVar10 = 0;
          if (param_5 != 0) {
            do {
              iVar7 = FUN_00915318(*(undefined4 *)(in_ECX + 0x48),0,uVar10,0);
              local_48[uVar10] = iVar7;
              if (iVar7 == -1) {
                return -0x7ff8fff2;
              }
              puVar6 = *(undefined4 **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + iVar7 * 4);
              *(undefined8 *)(puVar6 + 8) = 0;
              uVar10 = uVar10 + 1;
              *(undefined8 *)(puVar6 + 10) = 0x3ff0000000000000;
              puVar6[2] = param_8;
              *puVar6 = 0x117;
            } while (uVar10 < param_5);
          }
        }
        uVar10 = 0;
        if (param_3 != 0) {
          do {
            param_2[uVar10] = *(int *)(in_ECX + 0x24);
            uVar10 = uVar10 + 1;
          } while (uVar10 < param_3);
        }
        param_6 = 0;
        if (param_5 == 0) {
          return 0;
        }
        param_7 = local_48;
        param_4 = param_4 + local_8 * param_3;
        while( true ) {
          if (param_3 != 0) {
            piVar8 = param_2;
            uVar10 = param_3;
            do {
              *(uint *)((local_44 - (int)param_2) + (int)piVar8) = *param_7;
              *(int *)((local_40 - (int)param_2) + (int)piVar8) = *piVar8;
              piVar8 = piVar8 + 1;
              uVar10 = uVar10 - 1;
            } while (uVar10 != 0);
          }
          iVar7 = FUN_008f4c18(param_2,param_3);
          if (iVar7 < 0) {
            return iVar7;
          }
          uVar10 = *(uint *)(*(int *)(in_ECX + 8) + 0x6c);
          if (((char)uVar10 < '\0') && ((uVar10 & 4) == 0)) {
            iVar7 = FUN_008f8aec(param_1,param_2,local_40,param_4);
          }
          else {
            iVar7 = FUN_008f69da(param_1,param_3 & 0xfffff | 0x20500000,param_2,local_44,param_4,0);
            if (iVar7 < 0) {
              return iVar7;
            }
            iVar7 = FUN_008f69da(param_1,param_3 & 0xfffff | 0x20400000,param_2,param_2,local_40,0);
          }
          if (iVar7 < 0) break;
          param_6 = param_6 + 1;
          param_7 = param_7 + 1;
          param_4 = param_4 + param_3;
          if (param_5 <= param_6) {
            return 0;
          }
        }
        return iVar7;
      }
      if ((*(int *)(in_ECX + 0x58) != 0) &&
         ((1 < param_3 || ((*(byte *)(*(int *)(in_ECX + 8) + 0x71) & 2) == 0)))) {
        *(undefined4 *)(in_ECX + 0x60) = 1;
      }
      iVar7 = FUN_008f4afb();
      if (iVar7 == 0) {
        return -0x7ff8fff2;
      }
      uVar11 = FUN_008f4c18(iVar7,uVar10 * 7 + 4);
      iVar7 = (int)((ulonglong)uVar11 >> 0x20);
      if ((int)uVar11 < 0) {
        return (int)uVar11;
      }
      uVar9 = 0;
      do {
        local_6c[uVar9] = iVar7;
        iVar7 = iVar7 + 4;
        uVar9 = uVar9 + 1;
      } while (uVar9 < 4);
      uVar9 = 4;
      do {
        local_6c[uVar9] = iVar7;
        iVar7 = iVar7 + uVar10 * 4;
        uVar9 = uVar9 + 1;
      } while (uVar9 < 0xb);
      param_8 = (uint *)*param_7;
      iVar7 = *(int *)(in_ECX + 8);
      if (((**(byte **)(*(int *)(iVar7 + 0x14) + (int)param_8 * 4) & 2) == 0) &&
         (((*(byte *)(iVar7 + 0x71) & 2) == 0 || ((*(byte *)(iVar7 + 0x6f) & 1) == 0)))) {
        iVar7 = FUN_008f69da(param_1,0x10200001,local_6c[0],&param_8,0,4);
        if (iVar7 < 0) {
          return iVar7;
        }
        iVar7 = FUN_008f69da(param_1,0x10400001,local_6c[1],local_6c[0],0,4);
        if (iVar7 < 0) {
          return iVar7;
        }
        iVar7 = FUN_008f69da(param_1,0x10100001,local_6c[2],local_6c[1],0,8);
        if (iVar7 < 0) {
          return iVar7;
        }
        iVar7 = FUN_008f69da(param_1,0x20400001,local_60,local_6c[2],local_6c[0],6);
        if (iVar7 < 0) {
          return iVar7;
        }
        param_8 = (uint *)*local_60;
      }
      if ((*(byte *)(*(int *)(in_ECX + 8) + 0x71) & 2) == 0) {
        uVar10 = 0;
        if (param_5 != 0) {
          param_7 = (uint *)(local_5c - (int)local_58);
          piVar8 = local_58;
          do {
            *(uint **)((int)param_7 + (int)piVar8) = param_8;
            param_6 = local_8 + uVar10;
            dVar1 = (double)(int)param_6;
            if ((int)param_6 < 0) {
              dVar1 = dVar1 + _DAT_009c2f50;
            }
            iVar7 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,-dVar1);
            *piVar8 = iVar7;
            if (iVar7 == -1) {
              return -0x7ff8fff2;
            }
            uVar10 = uVar10 + 1;
            piVar8 = piVar8 + 1;
          } while (uVar10 < param_5);
        }
        uVar10 = param_5 & 0xfffff;
        iVar7 = FUN_008f69da(param_1,uVar10 | 0x20400000,local_54,local_5c,local_58,2);
        if (iVar7 < 0) {
          return iVar7;
        }
        iVar7 = FUN_008f93f6(param_1,local_50,local_4c,local_54,param_5);
        if (iVar7 < 0) {
          return iVar7;
        }
        iVar7 = FUN_008f69da(param_1,uVar10 | 0x20300000,local_48,local_4c,local_50,0x17);
        if (iVar7 < 0) {
          return iVar7;
        }
      }
      else {
        if (local_8 != 0) {
          param_7 = (uint *)local_8;
          dVar1 = (double)(int)local_8;
          if ((int)local_8 < 0) {
            dVar1 = dVar1 + _DAT_009c2f50;
          }
          param_6 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,-dVar1);
          if (param_6 == 0xffffffff) {
            return -0x7ff8fff2;
          }
          param_7 = (uint *)0xffffffff;
          iVar7 = FUN_008f69da(param_1,0x20400001,&param_7,&param_8,&param_6,4);
          if (iVar7 < 0) {
            return iVar7;
          }
          param_8 = param_7;
        }
        if (*(int *)(*(int *)(in_ECX + 8) + 0x30) != 0) {
          param_7 = (uint *)0xffffffff;
          iVar7 = FUN_008f69da(param_1,0x10000001,&param_7,&param_8,0,4);
          if (iVar7 < 0) {
            return iVar7;
          }
          param_8 = param_7;
          *(undefined4 *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + (int)param_7 * 4) + 4) =
               *(undefined4 *)(*(int *)(in_ECX + 8) + 0x8c);
        }
        if (*(int *)(in_ECX + 0x48) == -1) {
          iVar7 = FUN_009152bf(&DAT_00a1fc7c,0x751,4,4);
          *(int *)(in_ECX + 0x48) = iVar7;
          if (iVar7 == -1) {
            return -0x7ff8fff2;
          }
          uVar10 = 0;
          do {
            uVar9 = 0;
            do {
              if (uVar10 == uVar9) {
                uVar11 = 0x3ff0000000000000;
              }
              else {
                uVar11 = 0;
              }
              iVar7 = FUN_00915318(*(undefined4 *)(in_ECX + 0x48),uVar10,uVar9,uVar11);
              if (iVar7 == -1) {
                return -0x7ff8fff2;
              }
              uVar9 = uVar9 + 1;
            } while (uVar9 < 4);
            uVar10 = uVar10 + 1;
          } while (uVar10 < 4);
        }
        uVar10 = 0;
        if (param_5 != 0) {
          do {
            iVar7 = FUN_00915318(*(undefined4 *)(in_ECX + 0x48),0,uVar10,0);
            local_48[uVar10] = iVar7;
            if (iVar7 == -1) {
              return -0x7ff8fff2;
            }
            puVar6 = *(undefined4 **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + iVar7 * 4);
            *(undefined8 *)(puVar6 + 8) = 0;
            uVar10 = uVar10 + 1;
            *(undefined8 *)(puVar6 + 10) = 0x3ff0000000000000;
            puVar6[2] = param_8;
            *puVar6 = 0x117;
          } while (uVar10 < param_5);
        }
      }
      iVar7 = FUN_008f4c18(param_2,param_3);
      if (iVar7 < 0) {
        return iVar7;
      }
      param_7 = (uint *)0x0;
      if (param_3 == 0) {
        return 0;
      }
      uVar10 = param_5 & 0xfffff;
      while( true ) {
        uVar9 = 0;
        if (param_5 != 0) {
          piVar8 = param_4 + local_8 * param_3 + (int)param_7;
          do {
            *(int *)(local_44 + uVar9 * 4) = *piVar8;
            uVar9 = uVar9 + 1;
            piVar8 = piVar8 + param_3;
          } while (uVar9 < param_5);
        }
        iVar7 = FUN_008f69da(param_1,uVar10 | 0x50000000,param_2,local_44,local_48,0);
        if (iVar7 < 0) break;
        param_7 = (uint *)((int)param_7 + 1);
        param_2 = param_2 + 1;
        if (param_3 <= param_7) {
          return 0;
        }
      }
      return iVar7;
    }
    if (*(int *)(in_ECX + 0x58) != 0) {
      *(undefined4 *)(in_ECX + 0x60) = 1;
      return -0x7fffbffb;
    }
  }
  else if ((*(int *)(in_ECX + 0x58) != 0) && (*(int *)(in_ECX + 0x44) != 0)) {
    return -0x7fffbffb;
  }
LAB_009022d1:
  FUN_008f6353();
  return -0x7fffbffb;
}


// ==== FUN_00902bd6 @ 0x00902bd6 ====

int FUN_00902bd6(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *_Memory;
  int extraout_EAX;
  int in_ECX;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  if ((param_2 != 0) &&
     ((param_4 != param_2 || ((*(byte *)(*(int *)(in_ECX + 8) + 0x70) & 4) == 0)))) {
    iVar6 = FUN_00902d04(param_2,0);
    if (iVar6 < 0) {
      return iVar6;
    }
    if ((*(int *)(in_ECX + 0x50) != 0) || (*(int *)(in_ECX + 0x54) != 0)) {
      return 0;
    }
    param_2 = 0;
  }
  uVar7 = *(uint *)(*(int *)(in_ECX + 4) + 0x18);
  uVar1 = *(undefined4 *)(*(int *)(in_ECX + 8) + 8);
  uVar2 = *(undefined4 *)(*(int *)(in_ECX + 8) + 0xc);
  _Memory = operator_new(uVar7 << 2);
  if (_Memory != (undefined4 *)0x0) {
    puVar8 = *(undefined4 **)(in_ECX + 0x18);
    puVar9 = _Memory;
    for (uVar7 = uVar7 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar9 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    if (*(int *)(*(int *)(in_ECX + 8) + 0x5c) != 0) {
      uVar3 = *(undefined4 *)(in_ECX + 0x60);
      uVar4 = *(undefined4 *)(in_ECX + 0x58);
      uVar5 = *(undefined4 *)(in_ECX + 0x5c);
      *(undefined4 *)(in_ECX + 0x58) = 1;
      *(undefined4 *)(in_ECX + 0x5c) = 0;
      *(undefined4 *)(in_ECX + 0x60) = 0;
      iVar6 = FUN_008fa94e(param_1,param_2,param_3,param_4,_Memory);
      *(undefined4 *)(in_ECX + 0x4c) = 0;
      *(undefined4 *)(in_ECX + 0x50) = 0;
      *(undefined4 *)(in_ECX + 0x54) = 0;
      *(undefined4 *)(in_ECX + 0x58) = uVar4;
      *(undefined4 *)(in_ECX + 0x5c) = uVar5;
      *(undefined4 *)(in_ECX + 0x60) = uVar3;
      if (-1 < iVar6) goto LAB_00902cf1;
      FUN_008f693c(uVar1,uVar2,_Memory);
    }
    FUN_008fb78c(param_1,param_2,param_3,param_4,_Memory);
  }
LAB_00902cf1:
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_00902d04 @ 0x00902d04 ====

int FUN_00902d04(int *param_1,undefined4 *param_2)

{
  uint *puVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  uint local_1c;
  int local_18;
  uint local_10;
  int local_8;
  
  iVar7 = (int)param_1;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (*(int *)(in_ECX + 0x50) != 0) {
    return 0;
  }
  if (*(int *)(in_ECX + 0x54) != 0) {
    return 0;
  }
  uVar6 = *(uint *)(*(int *)(in_ECX + 8) + 0xc);
  iVar4 = *(int *)((int)param_1 + 4);
  if (iVar4 == 6) {
    if (*(int *)((int)param_1 + 0x10) == 1) {
      iVar5 = *(int *)((int)param_1 + 0x18);
      iVar4 = *(int *)(iVar5 + 0x10);
      local_10 = *(uint *)(iVar5 + 0x14);
      if ((*(int *)(iVar5 + 0x18) != 0) || (bVar3 = true, (*(byte *)(iVar5 + 0x1c) & 0x40) == 0)) {
        bVar3 = false;
      }
      if ((*(int *)(iVar5 + 0x18) == 0) || (bVar2 = true, (*(byte *)(iVar5 + 0x1c) & 2) == 0)) {
        bVar2 = false;
      }
      local_18 = *(undefined4 *)(iVar5 + 0x20);
      local_1c = *(undefined4 *)(iVar5 + 0x30);
      uVar8 = *(uint *)(iVar5 + 0x1c) & 0x80;
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffff3ff;
      param_1 = (int *)iVar4;
    }
    else {
      if (*(int *)((int)param_1 + 0x10) != 2) {
        return 0;
      }
      iVar5 = *(int *)((int)param_1 + 0x18);
      local_10 = *(uint *)(iVar5 + 0x14);
      iVar4 = *(int *)(iVar5 + 0x10);
      local_18 = *(undefined4 *)(iVar5 + 0x20);
      uVar8 = 0;
      *(byte *)(iVar5 + 0x19) = *(byte *)(iVar5 + 0x19) & 0xf3;
      local_1c = *(undefined4 *)(iVar5 + 0x34);
      bVar3 = false;
      bVar2 = false;
    }
    if (uVar8 != 0) {
      FUN_00903cbd(*(undefined4 *)(*(int *)(iVar7 + 0x18) + 0x28),
                   *(int *)(in_ECX + 0x18) + iVar4 * 4,0);
      goto LAB_00903064;
    }
    param_1 = (int *)0x0;
    if (local_10 != 0) {
      local_8 = iVar4 << 2;
      do {
        if ((!bVar2) || (*(int *)(local_8 + *(int *)(in_ECX + 0x18)) == -1)) {
          if (bVar3) {
            uVar12 = *(undefined4 *)(*(int *)(in_ECX + 8) + 0x7c);
          }
          else {
            uVar12 = *(undefined4 *)(*(int *)(in_ECX + 8) + 0x74);
          }
          uVar8 = FUN_00915318(uVar12,0,0,0);
          if (uVar8 < *(uint *)(*(int *)(in_ECX + 8) + 8)) {
            iVar5 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + uVar8 * 4);
          }
          else {
            iVar5 = 0;
          }
          if (iVar5 != 0) {
            *(int *)(iVar5 + 0x30) = (int)param_1 + iVar4;
            *(int *)(iVar5 + 0x60) = iVar7;
            *(int **)(iVar5 + 100) = param_1;
          }
          *(uint *)(local_8 + *(int *)(in_ECX + 0x18)) = uVar8;
        }
        param_1 = (int *)((int)param_1 + 1);
        local_8 = local_8 + 4;
      } while (param_1 < local_10);
    }
    if (!bVar3) goto LAB_00903064;
    iVar7 = FUN_008f71f0(local_18,*(int *)(in_ECX + 0x18) + iVar4 * 4,local_10);
    if (iVar7 < 0) {
      return iVar7;
    }
    iVar7 = FUN_008f9678(local_18,*(int *)(in_ECX + 0x18) + iVar4 * 4,
                         *(undefined4 *)(*(int *)(in_ECX + 8) + 0x7c),1,0,0,local_1c);
    if (iVar7 < 0) {
      return iVar7;
    }
    iVar7 = FUN_008f4d96();
  }
  else {
    if (iVar4 != 0xc) {
      if (iVar4 != 1) {
        FUN_008f6353();
        return -0x7fffbffb;
      }
      do {
        if ((*(int *)(in_ECX + 0x50) != 0) || (*(int *)(in_ECX + 0x54) != 0)) break;
        iVar4 = FUN_00902d04(*(undefined4 *)(iVar7 + 8),0);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar7 = *(int *)(iVar7 + 0xc);
      } while (iVar7 != 0);
      goto LAB_00903064;
    }
    iVar4 = *(int *)((int)param_1 + 0x10);
    if (iVar4 < 0) goto LAB_00903064;
    if (iVar4 < 2) {
      iVar4 = FUN_00903cbd(*(undefined4 *)((int)param_1 + 0x14),0,0);
      if (iVar4 < 0) {
        return iVar4;
      }
      uVar8 = *(uint *)(*(int *)(in_ECX + 8) + 0xc);
      local_18 = 0;
      local_1c = 0;
      if (uVar6 < uVar8) {
        param_1 = (int *)(*(int *)(*(int *)(in_ECX + 8) + 0x18) + uVar6 * 4);
        iVar4 = *(int *)(*(int *)(in_ECX + 8) + 0xc) - uVar6;
        do {
          if ((((*(int *)(*param_1 + 0x38) == *(int *)(in_ECX + 0x38)) &&
               (iVar5 = *(int *)(*param_1 + 0x3c), iVar5 != 0)) && (*(int *)(iVar5 + 4) == 0xd)) &&
             (local_1c <= *(uint *)(iVar5 + 0x44))) {
            local_1c = *(uint *)(iVar5 + 0x44);
            local_18 = iVar5;
          }
          param_1 = param_1 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      uVar10 = uVar6;
      if (uVar6 < uVar8) {
        do {
          iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x18) + uVar10 * 4);
          if (*(int *)(iVar4 + 0x38) == *(int *)(in_ECX + 0x38)) {
            *(int *)(iVar4 + 0x3c) = local_18;
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < *(uint *)(*(int *)(in_ECX + 8) + 0xc));
      }
      *(uint *)(in_ECX + 0x50) = (uint)(*(int *)(iVar7 + 0x10) == 1);
      goto LAB_00903064;
    }
    if (iVar4 == 2) {
      param_1 = (int *)0xffffffff;
      iVar4 = FUN_00903cbd(*(undefined4 *)(iVar7 + 0x18),&param_1,0);
      if (iVar4 < 0) {
        return iVar4;
      }
      iVar7 = FUN_008f9c0f(*(undefined4 *)(iVar7 + 0x18),param_1,*(undefined4 *)(iVar7 + 0x1c),
                           *(undefined4 *)(iVar7 + 0x20));
    }
    else {
      if (iVar4 == 3) {
        uVar13 = *(undefined8 *)((int)param_1 + 0x18);
        uVar12 = *(undefined4 *)((int)param_1 + 0x14);
      }
      else if (iVar4 == 4) {
        uVar13 = *(undefined8 *)((int)param_1 + 0x18);
        uVar12 = 0;
      }
      else {
        if (iVar4 != 5) {
          if (iVar4 == 6) {
            iVar7 = FUN_008f92c1(*(undefined4 *)((int)param_1 + 0x18),in_ECX + 0x28,1);
            if (iVar7 < 0) {
              return iVar7;
            }
            *(undefined4 *)(in_ECX + 0x54) = 1;
          }
          goto LAB_00903064;
        }
        uVar12 = *(undefined4 *)((int)param_1 + 0x1c);
        uVar13 = *(undefined8 *)((int)param_1 + 0x18);
      }
      iVar7 = FUN_00902bd6(param_1,uVar12,uVar13);
    }
  }
  if (iVar7 < 0) {
    return iVar7;
  }
LAB_00903064:
  if ((*(int *)(in_ECX + 0x54) != 0) && (param_2 != (undefined4 *)0x0)) {
    param_1 = (int *)0x0;
    for (uVar8 = uVar6; iVar7 = *(int *)(in_ECX + 8), uVar8 < *(uint *)(iVar7 + 0xc);
        uVar8 = uVar8 + 1) {
      puVar1 = *(uint **)(*(int *)(iVar7 + 0x18) + uVar8 * 4);
      if ((*puVar1 & 0xfff00000) == 0x11000000) {
        param_1 = (int *)puVar1[0xf];
      }
      FUN_008f4adb();
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 8) + 0x18) + uVar8 * 4) = 0;
    }
    *(uint *)(iVar7 + 0xc) = uVar6;
    puVar9 = param_2;
    puVar11 = *(undefined4 **)(in_ECX + 0x18);
    for (uVar6 = *(uint *)(*(int *)(in_ECX + 4) + 0x18) & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1)
    {
      *puVar11 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
    }
    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    iVar7 = FUN_008f92c1(param_1,in_ECX + 0x28,1);
    if (iVar7 < 0) {
      return iVar7;
    }
  }
  return 0;
}


// ==== FUN_00903102 @ 0x00903102 ====

undefined4
FUN_00903102(undefined4 param_1,uint *param_2,uint param_3,undefined4 *param_4,int param_5,
            int param_6)

{
  int *piVar1;
  char *pcVar2;
  char cVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  void *pvVar9;
  undefined4 *puVar10;
  undefined4 extraout_EAX;
  int iVar11;
  char *pcVar12;
  char *_Dest;
  int in_ECX;
  int iVar13;
  int *piVar14;
  undefined4 *puVar15;
  int local_38;
  undefined4 *local_34;
  undefined4 *local_2c;
  int *local_28;
  uint local_1c;
  uint local_18;
  int *local_14;
  void *local_10;
  uint local_c;
  uint local_8;
  
  local_2c = (undefined4 *)0x0;
  local_14 = (int *)0x0;
  local_c = 0;
  if ((param_2 == (uint *)0x0) || (*(int *)((int)param_2 + 4) != 10)) {
    uVar5 = 0x80004005;
  }
  else {
    if (*(int *)((int)param_2 + 0x38) == 0) {
      if ((param_5 == 0) || (iVar6 = FUN_00915cfa(), -1 < iVar6)) {
        if (param_3 == 0) {
          local_28 = (int *)0x0;
          local_38 = 0;
        }
        else {
          local_28 = *(int **)(param_3 + 8);
          local_38 = *(int *)(param_3 + 0xc);
        }
        iVar6 = *(int *)((int)param_2 + 0x24);
        iVar13 = 0;
        while (iVar6 != 0) {
          piVar14 = (int *)(iVar6 + 8);
          iVar6 = *(int *)(iVar6 + 0xc);
          if (((iVar6 != 0) && (*(int *)(iVar6 + 8) != 0)) &&
             (*(int *)(*(int *)(iVar6 + 8) + 4) == 0xc)) {
            iVar6 = *(int *)(iVar6 + 0xc);
          }
          iVar13 = iVar13 + *(int *)(*(int *)(*piVar14 + 0x18) + 0x14);
        }
        local_10 = operator_new(iVar13 << 2);
        if ((local_10 != (void *)0x0) &&
           ((param_5 == 0 || (local_14 = operator_new(iVar13 << 2), local_14 != (int *)0x0)))) {
          iVar6 = *(int *)((int)param_2 + 0x24);
          param_3 = (uint)local_28;
          pvVar9 = local_10;
          piVar14 = local_28;
          while (iVar6 != 0) {
            piVar1 = (int *)(iVar6 + 8);
            iVar6 = *(int *)(iVar6 + 0xc);
            if (((iVar6 != 0) && (*(int *)(iVar6 + 8) != 0)) &&
               (*(int *)(*(int *)(iVar6 + 8) + 4) == 0xc)) {
              iVar6 = *(int *)(iVar6 + 0xc);
            }
            iVar13 = *(int *)(*piVar1 + 0x18);
            if (((param_5 == 0) || ((param_6 != 0 && ((*(byte *)(iVar13 + 0x1c) & 0x40) != 0)))) &&
               (piVar14 != (int *)0x0)) {
              if (*(int *)((int)piVar14 + 8) != 0) {
                iVar7 = FUN_00903cbd(*(int *)((int)piVar14 + 8),pvVar9,0);
                if (iVar7 < 0) goto LAB_009038e4;
                piVar14 = (int *)param_3;
              }
              piVar14 = *(int **)((int)piVar14 + 0xc);
              param_3 = (uint)piVar14;
            }
            pvVar9 = (void *)((int)pvVar9 + *(int *)(iVar13 + 0x14) * 4);
          }
          local_1c = *(int *)((int)param_2 + 0x24);
          param_3 = (uint)local_28;
          if (local_1c != 0) {
            do {
              iVar6 = *(int *)(local_1c + 8);
              local_1c = *(int *)(local_1c + 0xc);
              local_34 = (undefined4 *)0x0;
              if (local_1c != 0) {
                iVar13 = *(int *)(local_1c + 8);
                if ((iVar13 != 0) && (*(int *)(iVar13 + 4) == 0xc)) {
                  local_1c = *(int *)(local_1c + 0xc);
                  local_34 = (undefined4 *)iVar13;
                }
              }
              iVar13 = *(int *)(iVar6 + 0x18);
              if ((param_5 == 0) || ((param_6 != 0 && ((*(byte *)(iVar13 + 0x1c) & 0x40) != 0)))) {
                iVar6 = FUN_00902d04(iVar6,0);
                if (iVar6 < 0) goto LAB_009038e4;
                if (param_3 == 0) {
                  iVar6 = FUN_00902d04(local_34,0);
                  goto LAB_009034ec;
                }
                if (((*(byte *)(iVar13 + 0x1c) & 0x10) != 0) &&
                   (iVar6 = FUN_008f69da(*(undefined4 *)(param_3 + 8),
                                         *(uint *)(iVar13 + 0x14) & 0xfffff | 0x10000000,
                                         *(int *)(in_ECX + 0x18) + *(int *)(iVar13 + 0x10) * 4,
                                         local_10,0,0), iVar6 < 0)) goto LAB_009038e4;
                param_3 = *(int *)(param_3 + 0xc);
              }
              else {
                iVar7 = *(int *)(in_ECX + 8);
                local_18 = *(int *)(iVar7 + 0x74);
                if ((*(uint *)(iVar13 + 0x1c) & 0x40) == 0) {
                  if ((*(uint *)(iVar13 + 0x1c) & 0x10) != 0) {
                    local_18 = *(int *)(iVar7 + 0x80);
                  }
                }
                else {
                  local_18 = *(int *)(iVar7 + 0x7c);
                }
                local_8 = 0;
                if (*(int *)(iVar13 + 0x14) != 0) {
                  do {
                    iVar7 = *(int *)(iVar13 + 0x10) + local_8;
                    uVar8 = FUN_00915318(local_18,0,0,0);
                    if (uVar8 < *(uint *)(*(int *)(in_ECX + 8) + 8)) {
                      iVar11 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + uVar8 * 4);
                    }
                    else {
                      iVar11 = 0;
                    }
                    if (iVar11 != 0) {
                      *(int *)(iVar11 + 0x30) = iVar7;
                      *(int *)(iVar11 + 0x60) = iVar6;
                      *(uint *)(iVar11 + 100) = local_8;
                    }
                    local_8 = local_8 + 1;
                    *(uint *)(*(int *)(in_ECX + 0x18) + iVar7 * 4) = uVar8;
                  } while (local_8 < *(uint *)(iVar13 + 0x14));
                }
                if ((*(int *)(*(int *)(in_ECX + 8) + 0x74) != local_18) &&
                   (iVar6 = FUN_008f71f0(*(undefined4 *)(iVar13 + 0x20),
                                         *(int *)(in_ECX + 0x18) + *(int *)(iVar13 + 0x10) * 4,
                                         *(undefined4 *)(iVar13 + 0x14)), iVar6 < 0))
                goto LAB_009038e4;
                if (*(int *)(*(int *)(in_ECX + 8) + 0x7c) == local_18) {
                  iVar6 = FUN_008f9678(*(undefined4 *)(iVar13 + 0x20),
                                       *(int *)(in_ECX + 0x18) + *(int *)(iVar13 + 0x10) * 4,
                                       local_18,1,0,0,*(undefined4 *)(iVar13 + 0x30));
                  if (iVar6 < 0) goto LAB_009038e4;
                  iVar6 = FUN_008f4d96();
LAB_009034ec:
                  if (iVar6 < 0) goto LAB_009038e4;
                }
                else if (*(int *)(*(int *)(in_ECX + 8) + 0x80) == local_18) {
                  iVar6 = FUN_008f9678(*(undefined4 *)(iVar13 + 0x20),
                                       *(int *)(in_ECX + 0x18) + *(int *)(iVar13 + 0x10) * 4,
                                       local_18,0,0,*(undefined4 *)(iVar13 + 0x2c),
                                       *(undefined4 *)(iVar13 + 0x30));
                  if (iVar6 < 0) goto LAB_009038e4;
                  iVar6 = FUN_008f5c46(*(int *)(in_ECX + 0x18) + *(int *)(iVar13 + 0x10) * 4,
                                       *(undefined4 *)(iVar13 + 0x14));
                  if (iVar6 == 0) {
                    FUN_008f6353();
                  }
                  else {
                    local_18 = 0;
                    if (*(int *)(iVar13 + 0x14) != 0) {
                      do {
                        iVar6 = *(int *)(iVar13 + 0x10) + local_18;
                        uVar8 = local_c + 1;
                        local_18 = local_18 + 1;
                        local_14[local_c] = iVar6;
                        local_c = uVar8;
                      } while (local_18 < *(uint *)(iVar13 + 0x14));
                    }
                  }
                }
              }
              local_10 = (void *)((int)local_10 + *(int *)(iVar13 + 0x14) * 4);
            } while (local_1c != 0);
          }
          if (param_5 != 0) {
            uVar8 = 0;
            if (local_c != 0) {
              do {
                iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 4))
                                  (*(undefined4 *)
                                    ((*(int **)(in_ECX + 8))[5] +
                                    *(int *)(*(int *)(in_ECX + 0x18) + local_14[uVar8] * 4) * 4));
                if (iVar6 < 0) goto LAB_009038e4;
                uVar8 = uVar8 + 1;
              } while (uVar8 < local_c);
            }
            FUN_00915b0e(FUN_008f642e,local_14,local_c,in_ECX);
            param_3 = 0;
            if (local_c != 0) {
              iVar6 = *(int *)(*(int *)(in_ECX + 8) + 0x14);
              local_28 = *(int **)(iVar6 + *(int *)(*(int *)(in_ECX + 0x18) + *local_14 * 4) * 4);
              local_1c = 1;
              if (1 < local_c) {
                do {
                  piVar14 = *(int **)(iVar6 + *(int *)(*(int *)(in_ECX + 0x18) +
                                                      local_14[local_1c] * 4) * 4);
                  if (((local_28[0x1b] == piVar14[0x1b]) && (local_28[4] == piVar14[4])) &&
                     (*local_28 == *piVar14)) {
                    param_3 = param_3 + 1;
                  }
                  else {
                    local_28 = piVar14;
                  }
                  local_1c = local_1c + 1;
                } while (local_1c < local_c);
                if (param_3 != 0) {
                  pvVar9 = operator_new(param_3 << 2);
                  if ((pvVar9 == (void *)0x0) ||
                     (puVar10 = operator_new(param_3 << 2), puVar10 == (undefined4 *)0x0))
                  goto LAB_009038e4;
                  local_1c = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) +
                                     *(int *)(*(int *)(in_ECX + 0x18) + *local_14 * 4) * 4);
                  uVar8 = 0;
                  param_3 = 0;
                  local_28 = (int *)0x1;
                  iVar6 = *local_14;
                  local_34 = puVar10;
                  do {
                    iVar13 = local_14[(int)local_28];
                    iVar7 = *(int *)(*(int *)(in_ECX + 0x18) + iVar13 * 4);
                    iVar11 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + iVar7 * 4);
                    if ((*(int *)(local_1c + 0x6c) == *(int *)(iVar11 + 0x6c)) &&
                       (*(int *)(local_1c + 0x10) == *(int *)(iVar11 + 0x10))) {
                      *(int *)(((int)pvVar9 - (int)puVar10) + (int)local_34) = iVar7;
                      *local_34 = *(undefined4 *)(*(int *)(in_ECX + 0x18) + iVar6 * 4);
                      uVar8 = param_3 + 1;
                      local_34 = local_34 + 1;
                      iVar13 = iVar6;
                      param_3 = uVar8;
                    }
                    else {
                      local_1c = iVar11;
                    }
                    local_28 = (int *)((int)local_28 + 1);
                    iVar6 = iVar13;
                  } while (local_28 < local_c);
                  iVar6 = FUN_008f69da(param_2,uVar8 & 0xfffff | 0x10000000,pvVar9,puVar10,0,0);
                  if (iVar6 < 0) goto LAB_009038e4;
                }
              }
            }
          }
          uVar8 = *(uint *)(*(int *)(in_ECX + 4) + 0x18);
          if (param_5 != 0) {
            local_2c = operator_new(uVar8 << 2);
            if (local_2c == (undefined4 *)0x0) goto LAB_009038e4;
            puVar10 = *(undefined4 **)(in_ECX + 0x18);
            puVar15 = local_2c;
            for (uVar8 = uVar8 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
              *puVar15 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar15 = puVar15 + 1;
            }
            for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
              *(undefined1 *)puVar15 = *(undefined1 *)puVar10;
              puVar10 = (undefined4 *)((int)puVar10 + 1);
              puVar15 = (undefined4 *)((int)puVar15 + 1);
            }
          }
          uVar5 = *(undefined4 *)(in_ECX + 0x50);
          *(undefined4 *)(in_ECX + 0x50) = 0;
          *(undefined4 *)((int)param_2 + 0x38) = 1;
          iVar6 = FUN_00902d04(*(undefined4 *)((int)param_2 + 0x28),local_2c);
          uVar8 = 0;
          if ((*(int *)(in_ECX + 0x50) == 0) && (*(int *)(in_ECX + 0x54) == 0)) {
            bVar4 = false;
          }
          else {
            bVar4 = true;
          }
          *(undefined4 *)(in_ECX + 0x50) = uVar5;
          *(undefined4 *)((int)param_2 + 0x38) = 0;
          if (-1 < iVar6) {
            if ((bVar4) || (*(int *)((int)param_2 + 0x14) == 0)) {
              if (param_5 == 0) {
                if (param_4 != (undefined4 *)0x0) {
                  if (*(int *)(in_ECX + 0x54) == 0) {
                    puVar10 = (undefined4 *)
                              (*(int *)(in_ECX + 0x18) + *(int *)((int)param_2 + 0x10) * 4);
                    for (uVar8 = *(uint *)((int)param_2 + 0x14) & 0x3fffffff; uVar8 != 0;
                        uVar8 = uVar8 - 1) {
                      *param_4 = *puVar10;
                      puVar10 = puVar10 + 1;
                      param_4 = param_4 + 1;
                    }
                    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
                      *(undefined1 *)param_4 = *(undefined1 *)puVar10;
                      puVar10 = (undefined4 *)((int)puVar10 + 1);
                      param_4 = (undefined4 *)((int)param_4 + 1);
                    }
                  }
                  else if (*(int *)((int)param_2 + 0x14) != 0) {
                    do {
                      param_4[uVar8] = *(undefined4 *)(in_ECX + 0x24);
                      uVar8 = uVar8 + 1;
                    } while (uVar8 < *(uint *)((int)param_2 + 0x14));
                  }
                }
              }
              else if (*(int *)((int)param_2 + 0x14) != 0) {
                if ((*(int *)(in_ECX + 0x54) != 0) && (*(int *)((int)param_2 + 0x14) != 0)) {
                  do {
                    iVar6 = *(int *)((int)param_2 + 0x10) + uVar8;
                    uVar8 = uVar8 + 1;
                    *(undefined4 *)(*(int *)(in_ECX + 0x18) + iVar6 * 4) =
                         *(undefined4 *)(in_ECX + 0x24);
                  } while (uVar8 < *(uint *)((int)param_2 + 0x14));
                }
                iVar6 = *(int *)(in_ECX + 0x18) + *(int *)((int)param_2 + 0x10) * 4;
                uVar8 = 0;
                iVar6 = FUN_008f69da(param_2,*(uint *)((int)param_2 + 0x14) & 0xfffff | 0x10000000,
                                     iVar6,iVar6,0,0);
                if (((iVar6 < 0) ||
                    (iVar6 = FUN_008f71f0(*(undefined4 *)((int)param_2 + 0x20),
                                          *(int *)(in_ECX + 0x18) +
                                          *(int *)((int)param_2 + 0x10) * 4,
                                          *(undefined4 *)((int)param_2 + 0x14)), iVar6 < 0)) ||
                   (iVar6 = FUN_008f9678(*(undefined4 *)((int)param_2 + 0x20),
                                         *(int *)(in_ECX + 0x18) + *(int *)((int)param_2 + 0x10) * 4
                                         ,*(undefined4 *)(*(int *)(in_ECX + 8) + 0x84),0,1,
                                         *(undefined4 *)((int)param_2 + 0x30),0), iVar6 < 0))
                goto LAB_009038e4;
                iVar6 = FUN_008f5c46(*(int *)(in_ECX + 0x18) + *(int *)((int)param_2 + 0x10) * 4,
                                     *(undefined4 *)((int)param_2 + 0x14));
                if (iVar6 == 0) {
                  FUN_008f6353();
                }
                else if (*(int *)((int)param_2 + 0x14) != 0) {
                  do {
                    iVar6 = (**(code **)(**(int **)(in_ECX + 8) + 4))
                                      (*(undefined4 *)
                                        ((*(int **)(in_ECX + 8))[5] +
                                        *(int *)(*(int *)(in_ECX + 0x18) +
                                                (*(int *)((int)param_2 + 0x10) + uVar8) * 4) * 4));
                    if (iVar6 < 0) {
                      *(undefined4 *)(in_ECX + 0x4c) = 1;
                      break;
                    }
                    uVar8 = uVar8 + 1;
                  } while (uVar8 < *(uint *)((int)param_2 + 0x14));
                }
              }
              local_1c = *(int *)((int)param_2 + 0x24);
              param_3 = local_38;
              if (local_1c != 0) {
                do {
                  iVar6 = *(int *)(local_1c + 8);
                  local_1c = *(int *)(local_1c + 0xc);
                  if (((local_1c != 0) && (*(int *)(local_1c + 8) != 0)) &&
                     (*(int *)(*(int *)(local_1c + 8) + 4) == 0xc)) {
                    local_1c = *(int *)(local_1c + 0xc);
                  }
                  iVar13 = *(int *)(iVar6 + 0x18);
                  if ((*(byte *)(iVar13 + 0x1c) & 0x20) == 0) {
LAB_00903aed:
                    if ((param_5 == 0) ||
                       ((param_6 != 0 && ((*(byte *)(iVar13 + 0x1c) & 0x40) != 0)))) {
LAB_00903b56:
                      if (param_3 != 0) {
                        param_3 = *(int *)(param_3 + 0xc);
                      }
                    }
                    else if (((*(byte *)(iVar13 + 0x1c) & 0x40) != 0) &&
                            (pcVar12 = *(char **)(*(int *)(iVar6 + 0x14) + 0x18), *pcVar12 != '$'))
                    {
                      pcVar2 = pcVar12 + 1;
                      do {
                        cVar3 = *pcVar12;
                        pcVar12 = pcVar12 + 1;
                      } while (cVar3 != '\0');
                      _Dest = (char *)FUN_008f33e7(pcVar12 + (2 - (int)pcVar2),1);
                      if (_Dest == (char *)0x0) break;
                      __snprintf(_Dest,(size_t)(pcVar12 + (2 - (int)pcVar2)),&DAT_00a25824);
                      *(char **)(*(int *)(iVar6 + 0x14) + 0x18) = _Dest;
                    }
                  }
                  else {
                    if (*(int *)(in_ECX + 0x54) == 0) {
                      param_4 = (undefined4 *)0x0;
                      if (*(int *)(iVar13 + 0x14) != 0) {
                        iVar7 = *(int *)(in_ECX + 8);
                        param_2 = (uint *)(*(int *)(in_ECX + 0x18) + *(int *)(iVar13 + 0x10) * 4);
                        do {
                          if (*param_2 < *(uint *)(iVar7 + 8)) {
                            iVar11 = *(int *)(*(int *)(iVar7 + 0x14) + *param_2 * 4);
                          }
                          else {
                            iVar11 = 0;
                          }
                          if ((iVar11 != 0) && (*(int *)(iVar7 + 0x74) == *(int *)(iVar11 + 4))) {
                            FUN_008f6353();
                            goto LAB_009038e4;
                          }
                          param_4 = (undefined4 *)((int)param_4 + 1);
                          param_2 = param_2 + 1;
                        } while (param_4 < *(uint *)(iVar13 + 0x14));
                      }
                    }
                    else {
                      param_2 = (uint *)0x0;
                      if (*(int *)(iVar13 + 0x14) != 0) {
                        do {
                          iVar7 = *(int *)(iVar13 + 0x10) + (int)param_2;
                          param_2 = (uint *)((int)param_2 + 1);
                          *(undefined4 *)(*(int *)(in_ECX + 0x18) + iVar7 * 4) =
                               *(undefined4 *)(in_ECX + 0x24);
                        } while (param_2 < *(uint *)(iVar13 + 0x14));
                      }
                    }
                    if (param_5 != 0) {
                      iVar7 = *(int *)(in_ECX + 0x18) + *(int *)(iVar13 + 0x10) * 4;
                      iVar7 = FUN_008f69da(iVar13,*(uint *)(iVar13 + 0x14) & 0xfffff | 0x10000000,
                                           iVar7,iVar7,0,0);
                      if (((-1 < iVar7) &&
                          (iVar7 = FUN_008f71f0(*(undefined4 *)(iVar13 + 0x20),
                                                *(int *)(in_ECX + 0x18) +
                                                *(int *)(iVar13 + 0x10) * 4,
                                                *(undefined4 *)(iVar13 + 0x14)), -1 < iVar7)) &&
                         (iVar7 = FUN_008f9678(*(undefined4 *)(iVar13 + 0x20),
                                               *(int *)(in_ECX + 0x18) + *(int *)(iVar13 + 0x10) * 4
                                               ,*(undefined4 *)(*(int *)(in_ECX + 8) + 0x84),0,1,
                                               *(undefined4 *)(iVar13 + 0x2c),0), -1 < iVar7)) {
                        iVar7 = FUN_008f5c46(*(int *)(in_ECX + 0x18) + *(int *)(iVar13 + 0x10) * 4,
                                             *(undefined4 *)(iVar13 + 0x14));
                        if (iVar7 == 0) {
                          FUN_008f6353();
                        }
                        else {
                          uVar8 = 0;
                          if (*(int *)(iVar13 + 0x14) != 0) {
                            do {
                              iVar7 = (**(code **)(**(int **)(in_ECX + 8) + 4))();
                              if (iVar7 < 0) {
                                *(undefined4 *)(in_ECX + 0x4c) = 1;
                                break;
                              }
                              uVar8 = uVar8 + 1;
                            } while (uVar8 < *(uint *)(iVar13 + 0x14));
                          }
                        }
                        goto LAB_00903aed;
                      }
                      break;
                    }
                    if (param_3 != 0) {
                      if (*(int *)(param_3 + 8) == 0) goto LAB_00903b56;
                      iVar7 = FUN_00903cbd(*(int *)(param_3 + 8),0,0);
                      if (-1 < iVar7) goto LAB_00903aed;
                      break;
                    }
                  }
                } while (local_1c != 0);
              }
            }
            else {
              FUN_008f6353();
            }
          }
        }
      }
LAB_009038e4:
      _free(local_2c);
      return extraout_EAX;
    }
    FUN_008f6353();
    uVar5 = 0x80004001;
  }
  return uVar5;
}


// ==== FUN_00903cbd @ 0x00903cbd ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00903cbd(int param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  int extraout_EAX;
  uint *puVar4;
  int in_ECX;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  uint uVar13;
  float10 fVar14;
  undefined8 uVar15;
  ulonglong uVar16;
  undefined4 uVar17;
  int local_68 [7];
  uint *local_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  uint *puStack_40;
  uint *local_3c [4];
  undefined4 local_2c;
  uint *local_28;
  uint *local_24;
  uint *local_20;
  uint *local_1c;
  uint *local_18;
  uint *local_14;
  uint *local_10;
  uint *local_c;
  uint *local_8;
  
  if (param_1 == 0) {
    if (param_2 == (uint *)0x0) {
      return 0;
    }
    return -0x7fffbffb;
  }
  if (*(int *)(param_1 + 4) != 0xd) {
    return -0x7fffbffb;
  }
  puVar2 = *(uint **)(param_1 + 0x20);
  puVar12 = (uint *)(*(int *)(param_1 + 0x14) * *(int *)(param_1 + 0x18));
  local_1c = (uint *)0x0;
  local_24 = (uint *)0x0;
  local_8 = (uint *)0x0;
  local_c = (uint *)0x0;
  local_14 = (uint *)0x0;
  local_18 = (uint *)0x0;
  if ((puVar2 != (uint *)0x0) && (puVar2[1] == 0xd)) {
    local_1c = (uint *)(puVar2[6] * puVar2[5]);
    local_14 = puVar2;
  }
  puVar2 = *(uint **)(param_1 + 0x24);
  if ((puVar2 != (uint *)0x0) && (puVar2[1] == 0xd)) {
    local_24 = (uint *)(puVar2[6] * puVar2[5]);
    local_18 = puVar2;
  }
  local_10 = puVar12;
  if (((local_14 != (uint *)0x0) && (local_8 = (uint *)FUN_008f4b5e(), local_8 == (uint *)0x0)) ||
     ((local_18 != (uint *)0x0 && (local_c = (uint *)FUN_008f4b5e(), local_c == (uint *)0x0)))) {
LAB_00904f08:
    FUN_008f6353();
    iVar1 = -0x7ff8fff2;
    goto LAB_009052de;
  }
  iVar1 = *(int *)(param_1 + 0x1c);
  local_20 = (uint *)0x0;
  if (-1 < iVar1) {
    if (iVar1 < 4) {
LAB_00903d97:
      local_20 = param_3;
    }
    else if (0x13 < iVar1) {
      if (iVar1 < 0x16) {
        local_20 = (uint *)0x1;
      }
      else if (iVar1 < 0x18) goto LAB_00903d97;
    }
  }
  if (*(int *)(param_1 + 0x28) == 0) {
    if ((local_18 != (uint *)0x0) && (iVar1 = FUN_00903cbd(local_18,local_c,0), iVar1 < 0))
    goto LAB_009052de;
    if (local_14 != (uint *)0x0) {
      uVar16 = CONCAT44(local_20,local_8);
      puVar2 = local_14;
      goto LAB_00903e0d;
    }
  }
  else {
    if ((local_14 != (uint *)0x0) && (iVar1 = FUN_00903cbd(local_14,local_8,local_20), iVar1 < 0))
    goto LAB_009052de;
    if (local_18 != (uint *)0x0) {
      uVar16 = ZEXT48(local_c);
      puVar2 = local_18;
LAB_00903e0d:
      iVar1 = FUN_00903cbd(puVar2,uVar16);
      if (iVar1 < 0) goto LAB_009052de;
    }
  }
  switch(*(undefined4 *)(param_1 + 0x1c)) {
  case 0:
  case 1:
    if (local_14 == (uint *)0x0) {
      iVar1 = FUN_0090536e(*(undefined4 *)(param_1 + 0x20),param_2,puVar12);
      goto LAB_00904116;
    }
    if (param_2 != (uint *)0x0) {
      if (local_1c == (uint *)0x1) {
        puVar2 = (uint *)0x0;
        if (puVar12 != (uint *)0x0) {
          do {
            param_2[(int)puVar2] = *local_8;
            puVar2 = (uint *)((int)puVar2 + 1);
          } while (puVar2 < puVar12);
        }
      }
      else {
        if ((puVar12 == local_1c) ||
           ((uVar7 = *(uint *)(param_1 + 0x14), uVar7 == 1 && (puVar12 < local_1c))))
        goto LAB_00904057;
        if ((local_14[5] < uVar7) || (local_14[6] < *(uint *)(param_1 + 0x18))) break;
        uVar8 = 0;
        if (uVar7 != 0) {
          do {
            iVar11 = local_14[6] * uVar8;
            iVar1 = *(int *)(param_1 + 0x18);
            iVar5 = iVar1 * uVar8;
            uVar8 = uVar8 + 1;
            puVar2 = local_8 + iVar11;
            puVar12 = param_2 + iVar5;
            for (; iVar1 != 0; iVar1 = iVar1 + -1) {
              *puVar12 = *puVar2;
              puVar2 = puVar2 + 1;
              puVar12 = puVar12 + 1;
            }
          } while (uVar8 < *(uint *)(param_1 + 0x14));
          goto LAB_00904a77;
        }
      }
      goto LAB_00903e68;
    }
    goto LAB_009052c3;
  case 2:
    if (local_14 != (uint *)0x0) {
      iVar1 = FUN_008f4afb();
      if (iVar1 == 0) goto LAB_00904f08;
      puVar2 = (uint *)0x0;
      if (puVar12 != (uint *)0x0) {
        do {
          *(undefined4 *)(iVar1 + (int)puVar2 * 4) = *(undefined4 *)(in_ECX + 0x20);
          puVar2 = (uint *)((int)puVar2 + 1);
        } while (puVar2 < puVar12);
      }
LAB_00904023:
      uVar7 = (uint)puVar12 & 0xfffff | 0x20400000;
      puVar2 = local_8;
LAB_00904035:
      iVar1 = FUN_008f69da(param_1,uVar7,local_8,puVar2,iVar1);
      if (iVar1 < 0) goto LAB_009052de;
LAB_0090404d:
      if (param_2 != (uint *)0x0) {
LAB_00904057:
        puVar2 = local_8;
LAB_00904a6f:
        puVar4 = param_2;
        for (puVar12 = local_10; puVar12 != (uint *)0x0; puVar12 = (uint *)((int)puVar12 + -1)) {
          *puVar4 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar4 = puVar4 + 1;
        }
LAB_00904a77:
        puVar12 = local_10;
        goto LAB_00903e68;
      }
      goto LAB_009052c3;
    }
    break;
  case 3:
    if (local_14 != (uint *)0x0) {
      iVar1 = FUN_008f4afb();
      if (iVar1 != 0) {
        puVar2 = (uint *)0x0;
        if (puVar12 != (uint *)0x0) {
          do {
            *(undefined4 *)(iVar1 + (int)puVar2 * 4) = *(undefined4 *)(in_ECX + 0x28);
            puVar2 = (uint *)((int)puVar2 + 1);
          } while (puVar2 < puVar12);
        }
        goto LAB_00904023;
      }
      goto LAB_00904f08;
    }
    break;
  case 4:
    if (local_14 != (uint *)0x0) {
      if (param_2 != (uint *)0x0) {
        puVar2 = (uint *)FUN_008f4afb();
        if (puVar2 != (uint *)0x0) {
          uVar7 = 0;
          do {
            local_3c[uVar7 + 4] = puVar2;
            uVar7 = uVar7 + 1;
            puVar2 = puVar2 + (int)puVar12;
          } while (uVar7 < 2);
          iVar1 = FUN_008f4c18(local_2c,puVar12);
          if ((((iVar1 < 0) || (iVar1 = FUN_008f4c18(local_28,puVar12), iVar1 < 0)) ||
              (iVar1 = FUN_008f4c18(param_2,puVar12), iVar1 < 0)) ||
             (iVar1 = FUN_008f93f6(param_1,local_2c,local_28,local_8), iVar1 < 0))
          goto LAB_009052de;
          uVar16 = CONCAT44(0x17,local_2c);
          puVar2 = local_28;
          goto LAB_009040fc;
        }
        goto LAB_00904f08;
      }
      goto LAB_009052c3;
    }
    break;
  case 5:
    if (local_14 != (uint *)0x0) {
      if (param_2 == (uint *)0x0) goto LAB_009052c3;
      iVar1 = FUN_008f4c18(param_2,puVar12);
      if (iVar1 < 0) goto LAB_009052de;
      uVar16 = 0;
      puVar3 = (uint *)((uint)puVar12 & 0xfffff | 0x10100000);
      puVar2 = local_8;
LAB_00904108:
LAB_0090410c:
      iVar1 = FUN_008f69da(param_1,puVar3,param_2,puVar2,uVar16);
      goto LAB_00904116;
    }
    break;
  case 6:
    if (local_14 != (uint *)0x0) {
      if (param_2 != (uint *)0x0) {
        iVar1 = FUN_008f4c18(param_2,puVar12);
        if (iVar1 < 0) goto LAB_009052de;
        puVar2 = local_8;
LAB_00904bbc:
        uVar16 = 0;
        puVar3 = (uint *)((uint)puVar12 & 0xfffff | 0x10000000);
        goto LAB_00904108;
      }
      goto LAB_009052c3;
    }
    break;
  case 7:
    if ((local_14 != (uint *)0x0) && (local_18 != (uint *)0x0)) {
      if (param_2 != (uint *)0x0) {
        iVar1 = FUN_008f4c18(param_2,puVar12);
        if (iVar1 < 0) goto LAB_009052de;
        uVar17 = 0;
LAB_009047a1:
        uVar16 = CONCAT44(uVar17,local_c);
        puVar3 = (uint *)((uint)puVar12 & 0xfffff);
LAB_009047ab:
        puVar3 = (uint *)((uint)puVar3 | 0x20500000);
        puVar2 = local_8;
        goto LAB_00904108;
      }
      goto LAB_009052c3;
    }
    break;
  case 8:
    if ((local_14 != (uint *)0x0) && (local_18 != (uint *)0x0)) {
      if (param_2 != (uint *)0x0) {
        local_18 = (uint *)FUN_008f4afb();
        if (local_18 == (uint *)0x0) goto LAB_00904f08;
        iVar1 = FUN_008f4c18(local_18,puVar12);
        if ((iVar1 < 0) || (iVar1 = FUN_008f4c18(param_2,puVar12), iVar1 < 0)) goto LAB_009052de;
        param_3 = (uint *)((uint)puVar12 & 0xfffff);
        iVar1 = FUN_008f69da(param_1,(uint)param_3 | 0x10300000,local_18,local_c,0,0);
        if (iVar1 < 0) goto LAB_009052de;
        uVar16 = ZEXT48(local_18);
        puVar3 = param_3;
        goto LAB_009047ab;
      }
      goto LAB_009052c3;
    }
    break;
  case 9:
    if ((local_14 != (uint *)0x0) && (local_18 != (uint *)0x0)) {
      if (param_2 != (uint *)0x0) {
        iVar1 = FUN_008f4afb();
        if (iVar1 == 0) goto LAB_00904f08;
        uVar7 = 0;
        do {
          local_68[uVar7 + 3] = iVar1;
          uVar7 = uVar7 + 1;
          iVar1 = iVar1 + (int)puVar12 * 4;
        } while (uVar7 < 8);
        uVar7 = 0;
        do {
          uVar15 = FUN_008f4c18(local_68[uVar7 + 3],puVar12);
          iVar1 = (int)uVar15;
          if (iVar1 < 0) goto LAB_009052de;
          uVar7 = (int)((ulonglong)uVar15 >> 0x20) + 1;
        } while (uVar7 < 8);
        iVar1 = FUN_008f4c18(param_2,puVar12);
        if (iVar1 < 0) goto LAB_009052de;
        param_3 = (uint *)((uint)puVar12 & 0xfffff);
        local_18 = (uint *)((uint)param_3 | 0x20500000);
        iVar1 = FUN_008f69da(param_1,local_18,local_68[3],local_8,local_c,0);
        if (iVar1 < 0) goto LAB_009052de;
        local_28 = (uint *)((uint)param_3 | 0x10100000);
        iVar1 = FUN_008f69da(param_1,local_28,local_68[4],local_68[3],0,0);
        if ((((iVar1 < 0) ||
             (iVar1 = FUN_008f69da(param_1,(uint)param_3 | 0x20300000,local_68[5],local_68[3],
                                   local_68[4],0x17), iVar1 < 0)) ||
            (iVar1 = FUN_008f69da(param_1,local_28,local_68[6],local_c,0,0), iVar1 < 0)) ||
           (((iVar1 = FUN_008f8aec(param_1,local_4c,local_68[6],local_c,local_68[5]), iVar1 < 0 ||
             (iVar1 = FUN_008f69da(param_1,(uint)param_3 | 0x10300000,uStack_48,local_4c,0,0x40),
             iVar1 < 0)) ||
            ((iVar1 = FUN_008f69da(param_1,local_18,local_44,local_8,uStack_48,0), iVar1 < 0 ||
             (iVar1 = FUN_008f69da(param_1,(uint)param_3 | 0x10400000,puStack_40,local_44,0,4),
             iVar1 < 0)))))) goto LAB_009052de;
        uVar16 = ZEXT48(puStack_40);
        puVar3 = local_18;
        puVar2 = local_4c;
        goto LAB_0090410c;
      }
      goto LAB_009052c3;
    }
    break;
  case 10:
    if ((local_14 != (uint *)0x0) && (local_18 != (uint *)0x0)) {
      if (param_2 != (uint *)0x0) {
        iVar1 = FUN_008f4c18(param_2,puVar12);
        if (iVar1 < 0) goto LAB_009052de;
        puVar3 = (uint *)((uint)puVar12 & 0xfffff);
        puVar2 = local_c;
LAB_009041cf:
        uVar16 = ZEXT48(puVar2);
        puVar3 = (uint *)((uint)puVar3 | 0x20400000);
        puVar2 = local_8;
        goto LAB_00904108;
      }
      goto LAB_009052c3;
    }
    break;
  case 0xb:
    if ((local_14 != (uint *)0x0) && (local_18 != (uint *)0x0)) {
      if (param_2 != (uint *)0x0) {
        local_18 = (uint *)FUN_008f4afb();
        if (local_18 != (uint *)0x0) {
          iVar1 = FUN_008f4c18(local_18,puVar12);
          if ((iVar1 < 0) || (iVar1 = FUN_008f4c18(param_2,puVar12), iVar1 < 0)) goto LAB_009052de;
          param_3 = (uint *)((uint)puVar12 & 0xfffff);
          iVar1 = FUN_008f69da(param_1,(uint)param_3 | 0x10100000,local_18,local_c,0,0);
          if (iVar1 < 0) goto LAB_009052de;
          puVar3 = param_3;
          puVar2 = local_18;
          goto LAB_009041cf;
        }
        goto LAB_00904f08;
      }
      goto LAB_009052c3;
    }
    break;
  case 0xc:
    if ((local_14 != (uint *)0x0) && (local_18 != (uint *)0x0)) {
      if (param_2 != (uint *)0x0) {
        iVar1 = FUN_008f4c18(param_2,puVar12);
        if (iVar1 < 0) goto LAB_009052de;
        puVar2 = local_8;
        puVar4 = local_c;
LAB_009042dd:
        puVar3 = (uint *)((uint)puVar12 & 0xfffff);
LAB_009042e4:
        uVar16 = CONCAT44(0x17,puVar4);
        puVar3 = (uint *)((uint)puVar3 | 0x20200000);
        goto LAB_00904108;
      }
      goto LAB_009052c3;
    }
    break;
  case 0xd:
    if ((local_14 != (uint *)0x0) && (local_18 != (uint *)0x0)) {
      if (param_2 != (uint *)0x0) {
        iVar1 = FUN_008f4c18(param_2,puVar12);
        if (iVar1 < 0) goto LAB_009052de;
        puVar2 = local_c;
        puVar4 = local_8;
        goto LAB_009042dd;
      }
      goto LAB_009052c3;
    }
    break;
  case 0xe:
    if ((local_14 != (uint *)0x0) && (local_18 != (uint *)0x0)) {
      if (param_2 != (uint *)0x0) {
        iVar1 = FUN_008f4c18(param_2,puVar12);
        if (iVar1 < 0) goto LAB_009052de;
        uVar16 = CONCAT44(0x17,local_8);
        puVar2 = local_c;
LAB_009040fc:
        puVar3 = (uint *)((uint)puVar12 & 0xfffff);
LAB_00904103:
        puVar3 = (uint *)((uint)puVar3 | 0x20300000);
        goto LAB_00904108;
      }
      goto LAB_009052c3;
    }
    break;
  case 0xf:
    if ((local_14 != (uint *)0x0) && (local_18 != (uint *)0x0)) {
      if (param_2 != (uint *)0x0) {
        iVar1 = FUN_008f4c18(param_2,puVar12);
        if (iVar1 < 0) goto LAB_009052de;
        uVar16 = CONCAT44(0x17,local_c);
        puVar2 = local_8;
        goto LAB_009040fc;
      }
      goto LAB_009052c3;
    }
    break;
  case 0x10:
    if ((local_14 != (uint *)0x0) && (local_18 != (uint *)0x0)) {
      if (param_2 != (uint *)0x0) {
        puVar2 = (uint *)FUN_008f4afb();
        if (puVar2 == (uint *)0x0) goto LAB_00904f08;
        uVar7 = 0;
        puVar4 = puVar2;
        do {
          local_3c[uVar7] = puVar4;
          uVar7 = uVar7 + 1;
          puVar4 = puVar4 + (int)puVar12;
        } while (uVar7 < 4);
        iVar1 = FUN_008f4c18(puVar2,(int)puVar12 * 4);
        if ((iVar1 < 0) || (iVar1 = FUN_008f4c18(param_2,puVar12), iVar1 < 0)) goto LAB_009052de;
        param_3 = (uint *)((uint)puVar12 & 0xfffff);
        iVar1 = FUN_008f69da(param_1,(uint)param_3 | 0x10100000,local_3c[0],local_c,0,0);
        if ((iVar1 < 0) ||
           ((iVar1 = FUN_008f69da(param_1,(uint)param_3 | 0x20400000,local_3c[1],local_8,local_3c[0]
                                  ,0), iVar1 < 0 ||
            (iVar1 = FUN_008f93f6(param_1,local_3c[2],local_3c[3],local_3c[1]), iVar1 < 0))))
        goto LAB_009052de;
        uVar16 = CONCAT44(0x17,local_3c[2]);
        puVar3 = param_3;
        puVar2 = local_3c[3];
        goto LAB_00904103;
      }
      goto LAB_009052c3;
    }
    break;
  case 0x11:
    if ((local_14 != (uint *)0x0) && (local_18 != (uint *)0x0)) {
      if (param_2 != (uint *)0x0) {
        puVar2 = (uint *)FUN_008f4afb();
        if (puVar2 == (uint *)0x0) goto LAB_00904f08;
        uVar7 = 0;
        puVar4 = puVar2;
        do {
          local_3c[uVar7] = puVar4;
          uVar7 = uVar7 + 1;
          puVar4 = puVar4 + (int)puVar12;
        } while (uVar7 < 4);
        iVar1 = FUN_008f4c18(puVar2,(int)puVar12 * 4);
        if ((iVar1 < 0) || (iVar1 = FUN_008f4c18(param_2,puVar12), iVar1 < 0)) goto LAB_009052de;
        param_3 = (uint *)((uint)puVar12 & 0xfffff);
        iVar1 = FUN_008f69da(param_1,(uint)param_3 | 0x10100000,local_3c[0],local_c,0,0);
        if (iVar1 < 0) goto LAB_009052de;
        uVar7 = (uint)param_3 | 0x20400000;
        puVar2 = local_3c[0];
LAB_009044f5:
        iVar1 = FUN_008f69da(param_1,uVar7,local_3c[1],local_8,puVar2);
        if (iVar1 < 0) goto LAB_009052de;
        iVar1 = FUN_008f93f6(param_1,local_3c[2],local_3c[3],local_3c[1]);
LAB_00904756:
        if (iVar1 < 0) goto LAB_009052de;
        puVar3 = param_3;
        puVar2 = local_3c[3];
        puVar4 = local_3c[2];
        goto LAB_009042e4;
      }
      goto LAB_009052c3;
    }
    break;
  case 0x12:
    if ((local_14 != (uint *)0x0) && (local_18 != (uint *)0x0)) {
      if (param_2 != (uint *)0x0) {
        param_3 = (uint *)0x0;
        if (puVar12 != (uint *)0x0) {
          iVar1 = *(int *)(*(int *)(in_ECX + 8) + 0x14);
          puVar2 = local_c;
LAB_00904559:
          if (((**(byte **)(iVar1 + *(int *)(((int)local_8 - (int)local_c) + (int)puVar2) * 4) & 1)
               != 0) && ((**(byte **)(iVar1 + *puVar2 * 4) & 1) != 0)) goto code_r0x0090456e;
          puVar2 = (uint *)FUN_008f4afb();
          if (puVar2 != (uint *)0x0) {
            uVar7 = 0;
            do {
              local_3c[uVar7 + 1] = puVar2;
              uVar7 = uVar7 + 1;
              puVar2 = puVar2 + (int)puVar12;
            } while (uVar7 < 3);
            iVar1 = FUN_008f4c18(local_3c[1],puVar12);
            if ((((iVar1 < 0) || (iVar1 = FUN_008f4c18(local_3c[2],puVar12), iVar1 < 0)) ||
                (iVar1 = FUN_008f4c18(local_3c[3],puVar12), iVar1 < 0)) ||
               (iVar1 = FUN_008f4c18(param_2,puVar12), iVar1 < 0)) goto LAB_009052de;
            param_3 = (uint *)((uint)puVar12 & 0xfffff);
            uVar7 = (uint)param_3 | 0x20500000;
            puVar2 = local_c;
            goto LAB_009044f5;
          }
          goto LAB_00904f08;
        }
LAB_00904579:
        iVar1 = FUN_008f4c18(param_2,puVar12);
        if (iVar1 < 0) goto LAB_009052de;
        uVar17 = 0x17;
        goto LAB_009047a1;
      }
      goto LAB_009052c3;
    }
    break;
  case 0x13:
    if ((local_14 != (uint *)0x0) && (local_18 != (uint *)0x0)) {
      if (param_2 != (uint *)0x0) {
        puVar2 = (uint *)FUN_008f4afb();
        if (puVar2 != (uint *)0x0) {
          uVar7 = 0;
          do {
            local_3c[uVar7] = puVar2;
            uVar7 = uVar7 + 1;
            puVar2 = puVar2 + (int)puVar12;
          } while (uVar7 < 4);
          iVar1 = FUN_008f4c18(local_3c[0],puVar12);
          if ((((iVar1 < 0) || (iVar1 = FUN_008f4c18(local_3c[1],puVar12), iVar1 < 0)) ||
              (iVar1 = FUN_008f4c18(local_3c[2],puVar12), iVar1 < 0)) ||
             (((iVar1 = FUN_008f4c18(local_3c[3],puVar12), iVar1 < 0 ||
               (iVar1 = FUN_008f4c18(param_2,puVar12), iVar1 < 0)) ||
              ((iVar1 = FUN_008f93f6(param_1,local_3c[0],0,local_8), iVar1 < 0 ||
               (iVar1 = FUN_008f93f6(param_1,local_3c[1],0,local_c), iVar1 < 0))))))
          goto LAB_009052de;
          param_3 = (uint *)((uint)puVar12 & 0xfffff);
          iVar1 = FUN_008f69da(param_1,(uint)param_3 | 0x20400000,local_3c[2],local_3c[0],
                               local_3c[1],4);
          if (iVar1 < 0) goto LAB_009052de;
          iVar1 = FUN_008f69da(param_1,(uint)param_3 | 0x10100000,local_3c[3],local_3c[2],0,8);
          goto LAB_00904756;
        }
        goto LAB_00904f08;
      }
      goto LAB_009052c3;
    }
    break;
  case 0x14:
    if ((local_14 != (uint *)0x0) && (local_18 != (uint *)0x0)) {
      if (puVar12 != (uint *)0x0) {
        iVar1 = *(int *)(in_ECX + 8);
        if (*local_8 < *(uint *)(iVar1 + 8)) {
          iVar5 = *(int *)(*(int *)(iVar1 + 0x14) + *local_8 * 4);
        }
        else {
          iVar5 = 0;
        }
        if ((iVar5 != 0) && (*(int *)(iVar1 + 0x74) == *(int *)(iVar5 + 4))) {
          puVar2 = (uint *)0x0;
          if (puVar12 != (uint *)0x0) {
            do {
              if (*(int *)(*(int *)(*(int *)(iVar1 + 0x14) + local_8[(int)puVar2] * 4) + 0x30) == -1
                 ) goto LAB_009052d0;
              puVar2 = (uint *)((int)puVar2 + 1);
            } while (puVar2 < puVar12);
          }
          goto LAB_00903f6e;
        }
        goto LAB_0090404d;
      }
      goto LAB_00903e68;
    }
    break;
  case 0x15:
    if ((local_14 != (uint *)0x0) && (local_18 != (uint *)0x0)) {
      if (puVar12 != (uint *)0x0) {
        puVar2 = (uint *)0x0;
        if (puVar12 != (uint *)0x0) {
          do {
            if (*(int *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + local_8[(int)puVar2] * 4)
                        + 0x30) == -1) goto LAB_009052d0;
            puVar2 = (uint *)((int)puVar2 + 1);
          } while (puVar2 < puVar12);
        }
LAB_00903f6e:
        iVar1 = 0;
        uVar7 = (uint)puVar12 & 0xfffff | 0x10000000;
        puVar2 = local_c;
        goto LAB_00904035;
      }
      goto LAB_00903e68;
    }
    break;
  case 0x16:
    if (local_18 != (uint *)0x0) {
      iVar1 = FUN_00901ba8(param_1,param_2,puVar12,local_8,local_1c,local_14[4],local_c,param_3);
      goto LAB_00904116;
    }
    break;
  case 0x17:
    if ((local_14 != (uint *)0x0) && (iVar1 = *(int *)(param_1 + 0x24), iVar1 != 0)) {
      if (*(int *)(iVar1 + 4) == 0xe) {
        if (*(int *)(iVar1 + 0x10) != 2) break;
        if (param_2 != (uint *)0x0) {
          puVar2 = local_8 + *(int *)(iVar1 + 0x18);
          goto LAB_00904a6f;
        }
      }
      else {
        if (*(int *)(iVar1 + 4) != 1) break;
        if (param_2 != (uint *)0x0) {
          puVar2 = (uint *)0x0;
          if (puVar12 != (uint *)0x0) {
            do {
              param_2[(int)puVar2] = local_8[*(int *)(*(int *)(iVar1 + 8) + 0x18)];
              iVar1 = *(int *)(iVar1 + 0xc);
              puVar2 = (uint *)((int)puVar2 + 1);
            } while (puVar2 < puVar12);
          }
          goto LAB_00903e68;
        }
      }
      goto LAB_009052c3;
    }
    break;
  case 0x18:
    if ((local_14 != (uint *)0x0) && (local_18 != (uint *)0x0)) {
      if (param_2 == (uint *)0x0) goto LAB_009052c3;
      puVar2 = (uint *)FUN_008f4afb();
      if (puVar2 == (uint *)0x0) goto LAB_00904f08;
      uVar7 = 0;
      do {
        local_3c[uVar7 + 1] = puVar2;
        uVar7 = uVar7 + 1;
        puVar2 = puVar2 + (int)puVar12;
      } while (uVar7 < 3);
      local_20 = (uint *)0x0;
      if (puVar12 != (uint *)0x0) {
        local_1c = local_c + (int)puVar12;
        local_28 = (uint *)((int)local_8 - (int)local_c);
        param_3 = (uint *)((int)local_c - (int)local_3c[1]);
        puVar2 = local_3c[1];
        while (iVar1 = FUN_008f4f7c(*(undefined4 *)((int)param_3 + (int)puVar2 + (int)local_28),
                                    &local_4c), -1 < iVar1) {
          if ((_DAT_0099d098 < (double)CONCAT44(uStack_48,local_4c)) ||
             ((double)CONCAT44(puStack_40,local_44) < _DAT_0099d098)) {
            puVar4 = (uint *)((int)param_3 + (int)puVar2);
          }
          else {
            if (((double)CONCAT44(uStack_48,local_4c) != _DAT_0099d098) ||
               ((double)CONCAT44(puStack_40,local_44) != _DAT_0099d098)) break;
            puVar4 = local_1c;
          }
          local_20 = (uint *)((int)local_20 + 1);
          local_1c = local_1c + 1;
          *puVar2 = *puVar4;
          puVar2 = puVar2 + 1;
          if (puVar12 <= local_20) break;
        }
      }
      if (local_20 == puVar12) {
        iVar1 = FUN_008f4c18(param_2,puVar12);
        if (iVar1 < 0) goto LAB_009052de;
        puVar2 = local_3c[1];
        goto LAB_00904bbc;
      }
      iVar1 = FUN_008f4c18(local_3c[1],puVar12);
      if ((((iVar1 < 0) || (iVar1 = FUN_008f4c18(local_3c[2],puVar12), iVar1 < 0)) ||
          (iVar1 = FUN_008f4c18(local_3c[3],puVar12), iVar1 < 0)) ||
         ((iVar1 = FUN_008f93f6(param_1,local_3c[1],local_3c[2],local_8), iVar1 < 0 ||
          (iVar1 = FUN_008f69da(param_1,(uint)puVar12 & 0xfffff | 0x20200000,local_3c[3],local_3c[2]
                                ,local_3c[1],0x17), iVar1 < 0)))) goto LAB_009052de;
      iVar1 = FUN_008f8aec(param_1,param_2,local_c + (int)puVar12,local_c);
      goto LAB_00904116;
    }
    break;
  case 0x19:
    iVar1 = FUN_008f60cb(*(undefined4 *)(param_1 + 0x20),&param_3);
    if (iVar1 != 0) {
      *(int *)(in_ECX + 0x38) = *(int *)(in_ECX + 0x38) + 1;
      iVar1 = FUN_00903102(param_3,iVar1,*(undefined4 *)(param_1 + 0x24),param_2,0,0);
      *(int *)(in_ECX + 0x38) = *(int *)(in_ECX + 0x38) + -1;
      goto LAB_00904116;
    }
    FUN_008f6353();
    break;
  case 0x1a:
    iVar1 = FUN_008fbe24();
LAB_00904116:
    if (iVar1 < 0) goto LAB_009052de;
LAB_00903e68:
    if (param_2 != (uint *)0x0) {
      puVar2 = *(uint **)(in_ECX + 0x9c);
      if (puVar2 < puVar12) {
        if (puVar2 == (uint *)0x0) {
          puVar2 = (uint *)0x10;
        }
        else {
          puVar2 = (uint *)((int)puVar2 * 2);
        }
        for (; puVar2 < puVar12; puVar2 = (uint *)((int)puVar2 * 2)) {
        }
        param_3 = operator_new((int)puVar2 << 3);
        if (param_3 != (uint *)0x0) {
          _free(*(void **)(in_ECX + 0x98));
          return extraout_EAX;
        }
        goto LAB_00904f08;
      }
      local_10 = *(uint **)(in_ECX + 0x98);
      local_28 = local_10 + (int)puVar12;
      FUN_008f64c5(*(undefined4 *)(param_1 + 0x10),local_28);
      param_3 = (uint *)0x0;
      local_14 = (uint *)0x0;
      local_1c = (uint *)0x0;
      if (puVar12 != (uint *)0x0) {
        local_24 = (uint *)((int)param_2 - (int)local_28);
        local_20 = (uint *)((int)local_28 - (int)local_10);
        local_18 = local_10;
        do {
          pbVar9 = (byte *)((int)local_18 + (int)local_20);
          iVar1 = *(int *)(in_ECX + 8);
          if (*(uint *)(pbVar9 + (int)local_24) < *(uint *)(iVar1 + 8)) {
            pbVar6 = *(byte **)(*(int *)(iVar1 + 0x14) + *(uint *)(pbVar9 + (int)local_24) * 4);
          }
          else {
            pbVar6 = (byte *)0x0;
          }
          if (pbVar6 == (byte *)0x0) goto LAB_009052d0;
          if (*(int *)(iVar1 + 0x74) == *(int *)(pbVar6 + 4)) {
LAB_00904dc0:
            *local_18 = 0;
          }
          else if (((*pbVar9 & 1) == 0) || ((*pbVar6 & 1) != 0)) {
            if ((*(int *)(iVar1 + 0x74) == *(int *)(pbVar6 + 4)) ||
               (((*pbVar9 & 2) == 0 || ((*pbVar6 & 2) != 0)))) goto LAB_00904dc0;
            local_14 = (uint *)((int)local_14 + 1);
            *local_18 = 2;
          }
          else {
            param_3 = (uint *)((int)param_3 + 1);
            *local_18 = 1;
          }
          puVar2 = param_3;
          local_1c = (uint *)((int)local_1c + 1);
          local_18 = local_18 + 1;
        } while (local_1c < puVar12);
        if (param_3 != (uint *)0x0) {
          puVar4 = (uint *)FUN_008f4afb();
          if (puVar4 == (uint *)0x0) goto LAB_00904f08;
          uVar7 = 0;
          do {
            local_3c[uVar7] = puVar4;
            uVar7 = uVar7 + 1;
            puVar4 = puVar4 + (int)puVar2;
          } while (uVar7 < 4);
          iVar1 = FUN_008f4c18(local_3c[1],param_3);
          if ((iVar1 < 0) || (iVar1 = FUN_008f4c18(local_3c[2],param_3), iVar1 < 0))
          goto LAB_009052de;
          local_1c = (uint *)((int)local_10 - (int)param_2);
          local_20 = (uint *)((int)local_3c[0] - (int)local_3c[3]);
          puVar2 = param_2;
          puVar4 = local_3c[3];
          local_24 = puVar12;
          do {
            if (*(int *)((int)local_1c + (int)puVar2) == 1) {
              *(uint *)((int)local_20 + (int)puVar4) = *puVar2;
              if (*(int *)(param_1 + 0x1c) == 0) {
                uVar7 = 0xffffffff;
              }
              else {
                uVar7 = *puVar2;
              }
              *puVar4 = uVar7;
              puVar4 = puVar4 + 1;
            }
            puVar2 = puVar2 + 1;
            local_24 = (uint *)((int)local_24 + -1);
          } while (local_24 != (uint *)0x0);
          iVar1 = FUN_008f93f6(param_1,local_3c[1],local_3c[2],local_3c[0],param_3);
          if ((iVar1 < 0) ||
             (iVar1 = FUN_008f69da(param_1,(uint)param_3 & 0xfffff | 0x20200000,local_3c[3],
                                   local_3c[2],local_3c[1],0x17), iVar1 < 0)) goto LAB_009052de;
          puVar2 = param_2;
          puVar4 = puVar12;
          do {
            if (*(int *)((int)puVar2 + (int)local_1c) == 1) {
              *puVar2 = *local_3c[3];
              local_3c[3] = local_3c[3] + 1;
            }
            puVar2 = puVar2 + 1;
            puVar4 = (uint *)((int)puVar4 + -1);
          } while (puVar4 != (uint *)0x0);
        }
        puVar2 = local_14;
        if (local_14 != (uint *)0x0) {
          iVar1 = FUN_008f4afb();
          if (iVar1 == 0) goto LAB_00904f08;
          uVar7 = 0;
          do {
            local_68[uVar7] = iVar1;
            uVar7 = uVar7 + 1;
            iVar1 = iVar1 + (int)puVar2 * 4;
          } while (uVar7 < 0xb);
          local_1c = (uint *)((int)local_10 - (int)param_2);
          local_18 = (uint *)(local_68[0] - (int)puStack_40);
          puVar2 = param_2;
          puVar4 = puStack_40;
          param_3 = puVar12;
          do {
            if (*(int *)((int)local_1c + (int)puVar2) == 2) {
              *(uint *)((int)local_18 + (int)puVar4) = *puVar2;
              if (*(int *)(param_1 + 0x1c) == 0) {
                uVar7 = 0xffffffff;
              }
              else {
                uVar7 = *puVar2;
              }
              *puVar4 = uVar7;
              puVar4 = puVar4 + 1;
            }
            puVar2 = puVar2 + 1;
            param_3 = (uint *)((int)param_3 + -1);
          } while (param_3 != (uint *)0x0);
          uVar7 = 1;
          param_3 = (uint *)0x0;
          do {
            uVar15 = FUN_008f4c18(local_68[uVar7],local_14);
            iVar1 = (int)uVar15;
            if (iVar1 < 0) goto LAB_009052de;
            uVar7 = (int)((ulonglong)uVar15 >> 0x20) + 1;
          } while (uVar7 < 10);
          param_3 = (uint *)((uint)local_14 & 0xfffff);
          iVar1 = FUN_008f69da(param_1,(uint)param_3 | 0x10200000,local_68[1],local_68[0],0,0);
          if ((iVar1 < 0) ||
             (iVar1 = FUN_008f69da(param_1,(uint)param_3 | 0x10400000,local_68[2],local_68[1],0,0x14
                                  ), iVar1 < 0)) goto LAB_009052de;
          local_24 = (uint *)((uint)param_3 | 0x10100000);
          iVar1 = FUN_008f69da(param_1,local_24,local_68[3],local_68[2],0,0x18);
          if (iVar1 < 0) goto LAB_009052de;
          local_14 = (uint *)((uint)param_3 | 0x20400000);
          iVar1 = FUN_008f69da(param_1,local_14,local_68[4],local_68[3],local_68[1],2);
          if ((iVar1 < 0) ||
             (iVar1 = FUN_008f69da(param_1,local_24,local_68[5],local_68[0],0,0), iVar1 < 0))
          goto LAB_009052de;
          local_20 = (uint *)((uint)param_3 | 0x20200000);
          iVar1 = FUN_008f69da(param_1,local_20,local_68[6],local_68[0],local_68[5],0x17);
          if ((iVar1 < 0) ||
             ((((iVar1 = FUN_008f69da(param_1,local_24,local_4c,local_68[2],0,0), iVar1 < 0 ||
                (iVar1 = FUN_008f69da(param_1,local_20,uStack_48,local_4c,local_68[2],0x17),
                iVar1 < 0)) ||
               (iVar1 = FUN_008f69da(param_1,(uint)param_3 | 0x20500000,local_44,local_68[6],
                                     uStack_48,0x17), iVar1 < 0)) ||
              (iVar1 = FUN_008f69da(param_1,local_14,puStack_40,local_68[4],local_44,2), iVar1 < 0))
             )) goto LAB_009052de;
          local_20 = param_2;
          param_3 = puStack_40;
          local_24 = puVar12;
          do {
            if (*(int *)((int)local_1c + (int)local_20) == 2) {
              iVar1 = *(int *)(*(int *)(in_ECX + 8) + 0x14);
              puVar2 = *(uint **)(iVar1 + *(int *)((int)puStack_40 + (int)local_18) * 4);
              puVar4 = *(uint **)(iVar1 + *puStack_40 * 4);
              if ((char)*puVar2 < '\0') {
                *(undefined8 *)(puVar2 + 10) = *(undefined8 *)(puVar2 + 8);
                *puVar2 = *puVar2 | 0x100;
              }
              if ((*puVar2 & 0x100) != 0) {
                iVar1 = FUN_00803910(*(undefined8 *)(puVar2 + 8));
                fVar14 = (float10)*(double *)(puVar2 + 8);
                if (iVar1 != 0) {
                  if (fVar14 < (float10)_DAT_0099d098) {
                    fVar14 = (float10)FUN_008044f0(*(double *)(in_ECX + 0xb0) -
                                                   *(double *)(puVar2 + 8));
                    fVar14 = -fVar14;
                  }
                  else {
                    fVar14 = (float10)FUN_008044f0(*(double *)(in_ECX + 0xb0) +
                                                   *(double *)(puVar2 + 8));
                  }
                }
                *(double *)(puVar4 + 8) = (double)fVar14;
                iVar1 = FUN_00803910(*(undefined8 *)(puVar2 + 10));
                if (iVar1 == 0) {
                  *(double *)(puVar4 + 10) = *(double *)(puVar2 + 10);
                }
                else {
                  if (*(double *)(puVar2 + 10) < _DAT_0099d098) {
                    fVar14 = (float10)FUN_008044f0(*(double *)(in_ECX + 0xb0) -
                                                   *(double *)(puVar2 + 10));
                    fVar14 = -fVar14;
                  }
                  else {
                    fVar14 = (float10)FUN_008044f0(*(double *)(in_ECX + 0xb0) +
                                                   *(double *)(puVar2 + 10));
                  }
                  *(double *)(puVar4 + 10) = (double)fVar14;
                }
                *(byte *)((int)puVar4 + 1) = *(byte *)((int)puVar4 + 1) | 1;
                if (*(double *)(puVar4 + 8) == *(double *)(puVar4 + 10)) {
                  uVar7 = *puVar4 | 0x80;
                }
                else {
                  uVar7 = *puVar4 & 0xffffff7f;
                }
                *puVar4 = uVar7;
              }
              puStack_40 = param_3 + 1;
              *local_20 = *param_3;
              param_3 = puStack_40;
            }
            local_20 = local_20 + 1;
            local_24 = (uint *)((int)local_24 + -1);
          } while (local_24 != (uint *)0x0);
        }
      }
      if (puVar12 != (uint *)0x0) {
        local_24 = (uint *)((int)param_2 - (int)local_28);
        puVar2 = local_28;
        param_2 = puVar12;
        do {
          puVar12 = *(uint **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) +
                              *(int *)((int)local_24 + (int)puVar2) * 4);
          uVar7 = *puVar2;
          uVar8 = *puVar12;
          *puVar12 = uVar7 & 0xf1ffffff | uVar8;
          uVar10 = *puVar2 & 0xe000000;
          uVar13 = uVar8 & 0xe000000;
          if ((uVar8 & 0xe000000) == 0) {
            uVar13 = uVar10;
          }
          if (puVar12[0x17] == 0) {
            if (uVar13 < uVar10) {
LAB_009052b0:
              uVar10 = uVar13;
            }
          }
          else if (uVar10 < uVar13) goto LAB_009052b0;
          puVar2 = puVar2 + 1;
          param_2 = (uint *)((int)param_2 + -1);
          *puVar12 = uVar7 & 0xf1ffffff | uVar8 & 0xf1ffffff | uVar10;
        } while (param_2 != (uint *)0x0);
      }
    }
LAB_009052c3:
    iVar1 = 0;
    goto LAB_009052de;
  default:
LAB_009052d0:
    FUN_008f6353();
  }
  iVar1 = -0x7fffbffb;
LAB_009052de:
  FUN_008f4bdf();
  FUN_008f4bdf();
  return iVar1;
code_r0x0090456e:
  param_3 = (uint *)((int)param_3 + 1);
  puVar2 = puVar2 + 1;
  if (puVar12 <= param_3) goto LAB_00904579;
  goto LAB_00904559;
}


// ==== FUN_0090536e @ 0x0090536e ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0090536e(int param_1,uint *param_2,uint param_3)

{
  double dVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int in_ECX;
  uint uVar5;
  int iVar6;
  
  puVar4 = param_2;
  if (param_1 == 0) {
    if (param_2 == (uint *)0x0) {
      return 0;
    }
    uVar5 = 0;
    if (param_3 == 0) {
      return 0;
    }
    do {
      uVar2 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x88),0,0,0);
      param_2[uVar5] = uVar2;
      if (uVar2 < *(uint *)(*(int *)(in_ECX + 8) + 8)) {
        iVar3 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + uVar2 * 4);
      }
      else {
        iVar3 = 0;
      }
      if (iVar3 != 0) {
        *(undefined4 *)(iVar3 + 0x30) = 0xffffffff;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < param_3);
    return 0;
  }
  iVar3 = *(int *)(param_1 + 4);
  if (iVar3 != 0xe) {
    if (iVar3 == 0xd) {
      iVar3 = FUN_00903cbd(param_1,param_2,0);
      return iVar3;
    }
    if (iVar3 == 1) {
      while (iVar3 = *(int *)(param_1 + 8), iVar3 != 0) {
        if (*(int *)(iVar3 + 4) == 0xe) {
          iVar6 = 1;
          if (*(int *)(iVar3 + 0x10) == 6) {
            iVar6 = *(int *)(iVar3 + 0x1c);
          }
          iVar3 = FUN_0090536e(iVar3,param_2,iVar6);
        }
        else {
          if ((iVar3 == 0) || (*(int *)(iVar3 + 4) != 0xd)) break;
          iVar6 = *(int *)(iVar3 + 0x18) * *(int *)(iVar3 + 0x14);
          iVar3 = FUN_00903cbd(iVar3,param_2,0);
        }
        if (iVar3 < 0) {
          return iVar3;
        }
        if (param_2 != (uint *)0x0) {
          param_2 = param_2 + iVar6;
        }
        param_1 = *(int *)(param_1 + 0xc);
        if (param_1 == 0) {
          return 0;
        }
      }
    }
    FUN_008f6353();
    return -0x7fffbffb;
  }
  if (param_2 == (uint *)0x0) {
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0x10);
  if (iVar3 == 6) {
    uVar5 = 0;
    if (*(int *)(param_1 + 0x18) != -1) {
      if (param_3 == 0) {
        return 0;
      }
      do {
        param_2[uVar5] = *(uint *)(*(int *)(in_ECX + 0x18) + (*(int *)(param_1 + 0x18) + uVar5) * 4)
        ;
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_3);
      return 0;
    }
    if (param_3 == 0) {
      return 0;
    }
    do {
      param_2[uVar5] = *(uint *)(*(int *)(in_ECX + 0x1c) + uVar5 * 4);
      uVar5 = uVar5 + 1;
    } while (uVar5 < param_3);
    return 0;
  }
  dVar1 = 0.0;
  param_2 = (uint *)0x0;
  if (iVar3 == 0) {
    if (*(int *)(param_1 + 0x18) == 0) {
      dVar1 = 0.0;
    }
    else {
      dVar1 = 1.0;
    }
    param_2 = (uint *)0x17;
  }
  else {
    if (iVar3 == 1) {
      dVar1 = (double)*(int *)(param_1 + 0x18);
    }
    else {
      if (iVar3 != 2) {
        if (iVar3 == 3) {
          dVar1 = *(double *)(param_1 + 0x18);
        }
        goto LAB_0090548f;
      }
      dVar1 = (double)*(int *)(param_1 + 0x18);
      if (*(int *)(param_1 + 0x18) < 0) {
        dVar1 = dVar1 + _DAT_009c2f50;
      }
    }
    param_2 = (uint *)0x2;
  }
LAB_0090548f:
  uVar5 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,dVar1);
  *puVar4 = uVar5;
  if (uVar5 < *(uint *)(*(int *)(in_ECX + 8) + 8)) {
    puVar4 = *(uint **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + uVar5 * 4);
  }
  else {
    puVar4 = (uint *)0x0;
  }
  if (puVar4 != (uint *)0x0) {
    *puVar4 = *puVar4 | (uint)param_2;
    puVar4[0xc] = 0xffffffff;
  }
  return 0;
}


// ==== FUN_0090556f @ 0x0090556f ====

undefined4 FUN_0090556f(int param_1)

{
  uint uVar1;
  void *_Memory;
  int iVar2;
  undefined4 extraout_EAX;
  int in_ECX;
  int iVar3;
  uint uVar4;
  uint local_8;
  
  if (*(int *)(param_1 + 4) != 0xd) {
    return 0;
  }
  uVar4 = *(int *)(param_1 + 0x18) * *(int *)(param_1 + 0x14);
  _Memory = operator_new(uVar4 * 4);
  if ((((_Memory != (void *)0x0) && (iVar2 = FUN_008f4c18(_Memory,uVar4), -1 < iVar2)) &&
      (iVar2 = FUN_00903cbd(param_1,_Memory,0), -1 < iVar2)) &&
     (iVar2 = FUN_008f69da(param_1,uVar4 & 0xfffff | 0x10000000,_Memory,_Memory,0,0), -1 < iVar2)) {
    local_8 = 0;
    if (uVar4 != 0) {
      do {
        uVar1 = *(uint *)((int)_Memory + local_8 * 4);
        iVar2 = *(int *)(in_ECX + 8);
        if (uVar1 < *(uint *)(iVar2 + 8)) {
          iVar3 = *(int *)(*(int *)(iVar2 + 0x14) + uVar1 * 4);
        }
        else {
          iVar3 = 0;
        }
        if (iVar3 != 0) {
          *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar2 + 0x84);
        }
        local_8 = local_8 + 1;
      } while (local_8 < uVar4);
    }
    FUN_008f9678(*(undefined4 *)(param_1 + 0x10),_Memory,
                 *(undefined4 *)(*(int *)(in_ECX + 8) + 0x84),1,1,0,0);
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_00905670 @ 0x00905670 ====

undefined4 FUN_00905670(undefined4 param_1,int param_2)

{
  undefined4 extraout_EAX;
  int in_ECX;
  uint in_stack_00000024;
  int in_stack_00000028;
  
  FUN_008f336d(0x100000,0x10000);
  if (((in_stack_00000024 & 0xfffff800) != 0) ||
     (((param_2 != 0 && ((in_stack_00000024 & 0x18) != 0)) || (in_stack_00000028 == 0)))) {
    FUN_008f33c5();
    return 0x8876086c;
  }
  if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 8))(1);
  }
  _free(*(void **)(in_ECX + 0x18));
  return extraout_EAX;
}


// ==== FUN_00905b5f @ 0x00905b5f ====

undefined4
FUN_00905b5f(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 *param_7,undefined4 *param_8)

{
  undefined4 uVar1;
  
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = 0;
  }
  if (param_8 != (undefined4 *)0x0) {
    *param_8 = 0;
  }
  if (param_3 == 0) {
    uVar1 = 0x8876086c;
  }
  else {
    uVar1 = FUN_00905670(param_1,param_2,param_3,0,0,0,param_4,param_5,param_6,param_7,param_8);
  }
  return uVar1;
}


// ==== FUN_00905ba6 @ 0x00905ba6 ====

void FUN_00905ba6(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,uint param_7,undefined4 *param_8,
                 undefined4 *param_9)

{
  if (param_8 != (undefined4 *)0x0) {
    *param_8 = 0;
  }
  if (param_9 != (undefined4 *)0x0) {
    *param_9 = 0;
  }
  FUN_00905670(param_1,param_2,0,param_3,0,param_4,param_5,param_6,param_7 & 0xffffffe7,param_8,
               param_9);
  return;
}


// ==== FUN_00905be7 @ 0x00905be7 ====

int FUN_00905be7(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5,
                undefined4 *param_6,undefined4 *param_7)

{
  char *pcVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 *in_ECX;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  
LAB_00905bfb:
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = 0;
  }
  param_5 = param_5 & 0xffffffe7;
  *in_ECX = param_1;
  iVar4 = FUN_008f68c1(param_3);
  if (iVar4 == 0) {
    if (*(int *)(param_3 + 4) == 0xd) {
      iVar4 = param_3;
      if ((uint)(*(int *)(param_3 + 0x18) * *(int *)(param_3 + 0x14)) < 2) {
        do {
          if (*(int *)(iVar4 + 0x1c) != 0) goto LAB_00905c4b;
          while (iVar4 = *(int *)(iVar4 + 0x20), *(int *)(iVar4 + 4) != 0xd) {
LAB_00905c4b:
            do {
              if (*(int *)(iVar4 + 4) != 1) break;
              iVar4 = *(int *)(iVar4 + 8);
            } while (iVar4 != 0);
            if ((*(int *)(iVar4 + 4) != 0xd) || (*(int *)(iVar4 + 0x1c) != 0)) {
              if ((*(int *)(iVar4 + 4) == 0xd) && (*(int *)(iVar4 + 0x1c) == 0x1b)) {
                iVar4 = FUN_00905ba6(param_1,param_2,*(undefined4 *)(*(int *)(iVar4 + 0x24) + 0x20),
                                     *(undefined4 *)(*(int *)(iVar4 + 0x24) + 0x24),0,
                                     *(undefined4 *)(*(int *)(iVar4 + 0x20) + 0x18),param_5,param_6,
                                     param_7);
                return iVar4;
              }
              if (*(int *)(iVar4 + 4) == 0xe) {
                if ((*(int *)(iVar4 + 0x10) == 4) && (*(int *)(*(int *)(iVar4 + 0x18) + 4) == 0xd))
                {
                  param_3 = *(int *)(iVar4 + 0x18);
                  goto LAB_00905bfb;
                }
                if (*(int *)(iVar4 + 0x10) == 5) {
                  if (param_6 != (undefined4 *)0x0) {
                    iVar5 = FUN_008eb3df(*(undefined4 *)(iVar4 + 0x1c),param_6);
                    if (iVar5 < 0) {
                      return iVar5;
                    }
                    uVar9 = *(uint *)(iVar4 + 0x1c);
                    puVar10 = *(undefined4 **)(iVar4 + 0x18);
                    puVar6 = (undefined4 *)(**(code **)(*(int *)*param_6 + 0xc))((int *)*param_6);
                    for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                      *puVar6 = *puVar10;
                      puVar10 = puVar10 + 1;
                      puVar6 = puVar6 + 1;
                    }
                    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                      *(undefined1 *)puVar6 = *(undefined1 *)puVar10;
                      puVar10 = (undefined4 *)((int)puVar10 + 1);
                      puVar6 = (undefined4 *)((int)puVar6 + 1);
                    }
                  }
                  if (param_7 != (undefined4 *)0x0) {
                    *param_7 = 0;
                  }
                  return 0;
                }
                if (((*(int *)(iVar4 + 0x10) == 6) && (*(int *)(iVar4 + 0x20) == 9)) &&
                   (pcVar7 = *(char **)(iVar4 + 0x28), pcVar7 != (char *)0x0)) {
                  if (param_6 != (undefined4 *)0x0) {
                    pcVar1 = pcVar7 + 1;
                    do {
                      cVar2 = *pcVar7;
                      pcVar7 = pcVar7 + 1;
                    } while (cVar2 != '\0');
                    iVar5 = FUN_008eb3df(pcVar7 + (1 - (int)pcVar1),param_6);
                    if (iVar5 < 0) {
                      return iVar5;
                    }
                    piVar3 = (int *)*param_6;
                    uVar9 = (**(code **)(*piVar3 + 0x10))(piVar3);
                    puVar10 = *(undefined4 **)(iVar4 + 0x28);
                    puVar6 = (undefined4 *)(**(code **)(*piVar3 + 0xc))(piVar3);
                    for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                      *puVar6 = *puVar10;
                      puVar10 = puVar10 + 1;
                      puVar6 = puVar6 + 1;
                    }
                    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                      *(undefined1 *)puVar6 = *(undefined1 *)puVar10;
                      puVar10 = (undefined4 *)((int)puVar10 + 1);
                      puVar6 = (undefined4 *)((int)puVar6 + 1);
                    }
                  }
                  if (param_7 == (undefined4 *)0x0) {
                    return 0;
                  }
                  *param_7 = 1;
                  return 0;
                }
              }
              pcVar7 = s_non_trivial_object_expressions_n_00a25a38;
              goto LAB_00905dee;
            }
          }
        } while( true );
      }
      pcVar7 = s_expressions_returning_objects_in_00a25a70;
LAB_00905dee:
      FUN_008f6353(in_ECX,param_3,0xdac,pcVar7);
      iVar4 = -0x7fffbfff;
    }
    else {
      FUN_008f6353(in_ECX,param_3,0,s_internal_error__expression_expec_00a25ab8);
      iVar4 = -0x7fffbffb;
    }
  }
  else {
    if ((((param_3 != 0) && (*(int *)(param_3 + 4) == 0xd)) &&
        (iVar4 = *(int *)(param_3 + 0x10), iVar4 != 0)) && (*(int *)(iVar4 + 4) == 9)) {
      *(byte *)(iVar4 + 0x21) = *(byte *)(iVar4 + 0x21) & 0xf3;
    }
    iVar4 = FUN_00905670(param_1,param_2,0,0,param_3,0,0,param_4,param_5,param_6,param_7);
  }
  return iVar4;
}


// ==== FUN_00905e05 @ 0x00905e05 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00905e05(char *param_1,undefined1 *param_2,byte *param_3)

{
  char cVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  byte local_21;
  char local_20 [24];
  undefined4 local_8;
  
  cVar1 = *param_1;
  local_8 = DAT_00b49670;
  pcVar7 = param_1;
  while ((cVar1 != '\0' && (iVar2 = _isalpha((int)*pcVar7), iVar2 != 0))) {
    pcVar7 = pcVar7 + 1;
    cVar1 = *pcVar7;
  }
  if (*pcVar7 == '\0') {
    local_21 = 0;
  }
  else {
    lVar3 = _atol(pcVar7);
    local_21 = (byte)lVar3;
  }
  if (local_21 < 0x10) {
    uVar6 = (int)pcVar7 - (int)param_1;
    if ((uVar6 != 0) && (uVar6 < 0x15)) {
      cVar1 = *pcVar7;
      if (cVar1 != '\0') {
        do {
          iVar2 = _isdigit((int)cVar1);
          if (iVar2 == 0) break;
          pcVar7 = pcVar7 + 1;
          cVar1 = *pcVar7;
        } while (cVar1 != '\0');
        if (*pcVar7 != '\0') {
          return 0x80004005;
        }
      }
      if (*param_1 != '\0') {
        iVar2 = -(int)param_1;
        do {
          iVar4 = _isalpha((int)*param_1);
          if (iVar4 == 0) break;
          iVar4 = _toupper((int)*param_1);
          param_1[(int)(local_20 + iVar2)] = (char)iVar4;
          param_1 = param_1 + 1;
        } while (*param_1 != '\0');
      }
      iVar2 = 9;
      bVar9 = true;
      local_20[uVar6] = '\0';
      iVar4 = iVar2;
      pcVar7 = local_20;
      pcVar8 = s_POSITION_00a27a68;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar9 = *pcVar7 == *pcVar8;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (bVar9);
      if (bVar9) {
        iVar4 = 0;
      }
      else {
        iVar4 = 0xc;
        bVar9 = true;
        pcVar7 = local_20;
        pcVar8 = s_BLENDWEIGHT_00a27a5c;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar9 = *pcVar7 == *pcVar8;
          pcVar7 = pcVar7 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if (bVar9) {
          iVar4 = 1;
        }
        else {
          iVar4 = 0xd;
          bVar9 = true;
          pcVar7 = local_20;
          pcVar8 = s_BLENDINDICES_00a27a4c;
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar9 = *pcVar7 == *pcVar8;
            pcVar7 = pcVar7 + 1;
            pcVar8 = pcVar8 + 1;
          } while (bVar9);
          if (bVar9) {
            iVar4 = 2;
          }
          else {
            iVar4 = 7;
            bVar9 = true;
            pcVar7 = local_20;
            pcVar8 = s_NORMAL_00a1a7a0;
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              bVar9 = *pcVar7 == *pcVar8;
              pcVar7 = pcVar7 + 1;
              pcVar8 = pcVar8 + 1;
            } while (bVar9);
            if (bVar9) {
              iVar4 = 3;
            }
            else {
              iVar4 = 6;
              bVar9 = true;
              iVar5 = iVar4;
              pcVar7 = local_20;
              pcVar8 = s_PSIZE_00a1a798;
              do {
                if (iVar5 == 0) break;
                iVar5 = iVar5 + -1;
                bVar9 = *pcVar7 == *pcVar8;
                pcVar7 = pcVar7 + 1;
                pcVar8 = pcVar8 + 1;
              } while (bVar9);
              if (bVar9) {
                iVar4 = 4;
              }
              else {
                bVar9 = true;
                iVar5 = iVar2;
                pcVar7 = local_20;
                pcVar8 = s_TEXCOORD_00a27a40;
                do {
                  if (iVar5 == 0) break;
                  iVar5 = iVar5 + -1;
                  bVar9 = *pcVar7 == *pcVar8;
                  pcVar7 = pcVar7 + 1;
                  pcVar8 = pcVar8 + 1;
                } while (bVar9);
                if (bVar9) {
                  iVar4 = 5;
                }
                else {
                  iVar5 = 8;
                  bVar9 = true;
                  pcVar7 = local_20;
                  pcVar8 = s_TANGENT_00a27a38;
                  do {
                    if (iVar5 == 0) break;
                    iVar5 = iVar5 + -1;
                    bVar9 = *pcVar7 == *pcVar8;
                    pcVar7 = pcVar7 + 1;
                    pcVar8 = pcVar8 + 1;
                  } while (bVar9);
                  if (!bVar9) {
                    bVar9 = true;
                    iVar4 = iVar2;
                    pcVar7 = local_20;
                    pcVar8 = s_BINORMAL_00a27a2c;
                    do {
                      if (iVar4 == 0) break;
                      iVar4 = iVar4 + -1;
                      bVar9 = *pcVar7 == *pcVar8;
                      pcVar7 = pcVar7 + 1;
                      pcVar8 = pcVar8 + 1;
                    } while (bVar9);
                    if (bVar9) {
                      iVar4 = 7;
                    }
                    else {
                      iVar4 = 0xb;
                      bVar9 = true;
                      iVar5 = iVar4;
                      pcVar7 = local_20;
                      pcVar8 = s_TESSFACTOR_00a27a20;
                      do {
                        if (iVar5 == 0) break;
                        iVar5 = iVar5 + -1;
                        bVar9 = *pcVar7 == *pcVar8;
                        pcVar7 = pcVar7 + 1;
                        pcVar8 = pcVar8 + 1;
                      } while (bVar9);
                      if (bVar9) {
                        iVar4 = 8;
                      }
                      else {
                        iVar5 = 10;
                        bVar9 = true;
                        pcVar7 = local_20;
                        pcVar8 = s_POSITIONT_00a27a14;
                        do {
                          if (iVar5 == 0) break;
                          iVar5 = iVar5 + -1;
                          bVar9 = *pcVar7 == *pcVar8;
                          pcVar7 = pcVar7 + 1;
                          pcVar8 = pcVar8 + 1;
                        } while (bVar9);
                        if (bVar9) {
                          iVar4 = 9;
                        }
                        else {
                          iVar5 = 6;
                          bVar9 = true;
                          pcVar7 = local_20;
                          pcVar8 = s_COLOR_00a27a0c;
                          do {
                            if (iVar5 == 0) break;
                            iVar5 = iVar5 + -1;
                            bVar9 = *pcVar7 == *pcVar8;
                            pcVar7 = pcVar7 + 1;
                            pcVar8 = pcVar8 + 1;
                          } while (bVar9);
                          if (!bVar9) {
                            iVar5 = 4;
                            bVar9 = true;
                            pcVar7 = local_20;
                            pcVar8 = &DAT_00a27a08;
                            do {
                              if (iVar5 == 0) break;
                              iVar5 = iVar5 + -1;
                              bVar9 = *pcVar7 == *pcVar8;
                              pcVar7 = pcVar7 + 1;
                              pcVar8 = pcVar8 + 1;
                            } while (bVar9);
                            if (bVar9) goto LAB_00906047;
                            iVar4 = 6;
                            bVar9 = true;
                            pcVar7 = local_20;
                            pcVar8 = s_DEPTH_00a27a00;
                            do {
                              if (iVar4 == 0) break;
                              iVar4 = iVar4 + -1;
                              bVar9 = *pcVar7 == *pcVar8;
                              pcVar7 = pcVar7 + 1;
                              pcVar8 = pcVar8 + 1;
                            } while (bVar9);
                            if (bVar9) {
                              iVar4 = 0xc;
                              goto LAB_00906047;
                            }
                            iVar4 = 7;
                            bVar9 = true;
                            pcVar7 = local_20;
                            pcVar8 = s_SAMPLE_00a279f8;
                            do {
                              if (iVar4 == 0) break;
                              iVar4 = iVar4 + -1;
                              bVar9 = *pcVar7 == *pcVar8;
                              pcVar7 = pcVar7 + 1;
                              pcVar8 = pcVar8 + 1;
                            } while (bVar9);
                            if (bVar9) {
                              iVar4 = 0xd;
                              goto LAB_00906047;
                            }
                            iVar4 = 8;
                            bVar9 = true;
                            pcVar7 = local_20;
                            pcVar8 = s_DIFFUSE_00a1a8c8;
                            do {
                              if (iVar4 == 0) break;
                              iVar4 = iVar4 + -1;
                              bVar9 = *pcVar7 == *pcVar8;
                              pcVar7 = pcVar7 + 1;
                              pcVar8 = pcVar8 + 1;
                            } while (bVar9);
                            if (bVar9) {
                              local_21 = 0;
                            }
                            else {
                              bVar9 = true;
                              pcVar7 = local_20;
                              pcVar8 = s_SPECULAR_00a1a8a4;
                              do {
                                if (iVar2 == 0) break;
                                iVar2 = iVar2 + -1;
                                bVar9 = *pcVar7 == *pcVar8;
                                pcVar7 = pcVar7 + 1;
                                pcVar8 = pcVar8 + 1;
                              } while (bVar9);
                              if (!bVar9) {
                                return 0x80004005;
                              }
                              local_21 = 1;
                            }
                          }
                          iVar4 = 10;
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
LAB_00906047:
      *param_2 = (char)iVar4;
      *param_3 = local_21;
      return 0;
    }
  }
  else {
    *param_2 = 0;
    *param_3 = 0xff;
  }
  return 0x80004005;
}


// ==== FUN_0090605b @ 0x0090605b ====

uint FUN_0090605b(char *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if ((param_1 == (char *)0x0) || (cVar1 = *param_1, cVar1 == '\0')) {
    uVar3 = 0;
  }
  else {
    do {
      iVar2 = _toupper((int)cVar1);
      uVar3 = uVar3 * 0x13 + iVar2;
      param_1 = param_1 + 1;
      cVar1 = *param_1;
    } while (cVar1 != '\0');
    uVar3 = uVar3 % 7;
  }
  return uVar3;
}


// ==== FUN_0090609c @ 0x0090609c ====

undefined4 * FUN_0090609c(LPCSTR param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  iVar1 = FUN_0090605b(param_1);
  puVar2 = *(undefined4 **)(in_ECX + iVar1 * 4);
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    iVar1 = lstrcmpiA((LPCSTR)*puVar2,param_1);
    if (iVar1 == 0) break;
    puVar2 = (undefined4 *)puVar2[8];
  }
  return puVar2;
}


// ==== FUN_009060d2 @ 0x009060d2 ====

void FUN_009060d2(int param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  uVar3 = 0;
  do {
    for (iVar1 = *(int *)(in_ECX + uVar3 * 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x20)) {
      *(int *)(param_1 + iVar2 * 4) = iVar1;
      iVar2 = iVar2 + 1;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 7);
  return;
}


// ==== FUN_009060fc @ 0x009060fc ====

void FUN_009060fc(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x1e] = 0;
  return;
}


// ==== FUN_00906118 @ 0x00906118 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00906118(undefined4 *param_1,char *param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  char local_1008 [255];
  undefined1 local_f09;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  iVar2 = 0xd;
  bVar5 = true;
  param_1[0x13] = 1;
  pcVar3 = param_2;
  pcVar4 = s_syntax_error_009fea30;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    piVar1 = param_1 + 4;
    FUN_008bd585(2000,piVar1);
    if (*piVar1 == 9) {
      if (param_1[0x15] == 0x7e7) {
        FUN_008bd320(*param_1,piVar1,0x7e7,s___s__is_not_a_valid_instruction_i_00a27aa0,param_1[6]);
      }
      if (param_1[0x15] == 0x7e8) {
        FUN_008bd320(*param_1,piVar1,0x7e8,s_invalid_instruction_modifiers____00a27a7c,param_1[6]);
      }
    }
  }
  else {
    __vsnprintf(local_1008,0x1000,param_2,&param_3);
    local_f09 = 0;
    FUN_008bd320(*param_1,param_1 + 4,0,&DAT_009d5e14,local_1008);
  }
  return;
}


// ==== FUN_009061e8 @ 0x009061e8 ====

undefined4
FUN_009061e8(undefined4 param_1,undefined4 param_2,short param_3,int param_4,undefined4 param_5,
            undefined4 *param_6)

{
  if (param_3 == 1) {
LAB_0090622f:
    FUN_008bd3f7(*param_6,param_6[0xc],param_4 + 5000,&DAT_009d5e14,param_5);
  }
  else {
    if (param_3 != 2) {
      if (param_3 == 5) goto LAB_0090622f;
      if (param_3 != 6) {
        return 0;
      }
    }
    FUN_008bd320(*param_6,param_6[0xc],param_4 + 5000,&DAT_009d5e14,param_5);
    param_6[0x13] = 1;
  }
  return 0;
}


// ==== FUN_00906256 @ 0x00906256 ====

int FUN_00906256(int param_1)

{
  undefined4 *in_ECX;
  
  if (param_1 == 0) {
    if (in_ECX[0x13] == 0) {
      FUN_008bd320(*in_ECX,in_ECX + 4,0,s_internal_error__production_faile_00a17a20);
      in_ECX[0x13] = 1;
    }
    in_ECX[0x14] = 1;
    param_1 = 0;
  }
  return param_1;
}


// ==== FUN_00906290 @ 0x00906290 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_00906290(int param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  int in_ECX;
  uint uVar11;
  uint uVar12;
  int iVar13;
  byte *pbVar14;
  byte *pbVar15;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  int local_5c;
  byte *local_2c;
  uint local_24;
  uint local_20;
  uint local_1c;
  byte local_18 [16];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  local_2c = *(byte **)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x54) = 0;
  local_1c = 0x10d;
  local_5c = 0;
  local_20 = 0;
  local_24 = 0;
  bVar16 = true;
  bVar18 = false;
  bVar1 = false;
  bVar2 = false;
  bVar19 = false;
  bVar4 = false;
  bVar5 = false;
  bVar20 = false;
  bVar3 = false;
  iVar13 = 0;
  if (*local_2c == 0) {
LAB_00906b5d:
    *(uint *)(in_ECX + 0x44) = local_20;
    *(uint *)(in_ECX + 0x48) = local_24;
    *(int *)(in_ECX + 0x40) = iVar13;
    *(undefined4 *)(in_ECX + 0x54) = 0;
  }
  else {
    do {
      pbVar9 = local_2c;
      iVar13 = 3;
      for (; (*local_2c != 0 && (*local_2c != 0x5f)); local_2c = local_2c + 1) {
      }
      uVar8 = (int)local_2c - (int)pbVar9;
      if (0xf < uVar8) goto LAB_00906b56;
      pbVar14 = local_18;
      for (uVar11 = uVar8 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined4 *)pbVar14 = *(undefined4 *)pbVar9;
        pbVar9 = pbVar9 + 4;
        pbVar14 = pbVar14 + 4;
      }
      for (uVar11 = uVar8 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
        *pbVar14 = *pbVar9;
        pbVar9 = pbVar9 + 1;
        pbVar14 = pbVar14 + 1;
      }
      local_18[uVar8] = 0;
      if (*local_2c != 0) {
        local_2c = local_2c + 1;
      }
      if (bVar16) {
        iVar13 = 0;
        uVar8 = 0;
        do {
          pbVar14 = *(byte **)((int)&PTR_DAT_00a25ae0 + uVar8);
          pbVar9 = local_18;
          do {
            bVar7 = *pbVar9;
            bVar16 = bVar7 < *pbVar14;
            if (bVar7 != *pbVar14) {
LAB_0090637c:
              iVar10 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
              goto LAB_00906383;
            }
            if (bVar7 == 0) break;
            bVar7 = pbVar9[1];
            bVar16 = bVar7 < pbVar14[1];
            if (bVar7 != pbVar14[1]) goto LAB_0090637c;
            pbVar9 = pbVar9 + 2;
            pbVar14 = pbVar14 + 2;
          } while (bVar7 != 0);
          iVar10 = 0;
LAB_00906383:
          if (iVar10 == 0) break;
          uVar8 = uVar8 + 0x44;
          iVar13 = iVar13 + 1;
        } while (uVar8 < 0x1650);
        if (iVar13 == 0x54) goto LAB_00906b56;
        iVar10 = *(int *)(in_ECX + 0x38);
        uVar8 = *(uint *)(&DAT_00a25ae8 + (iVar13 * 0x11 + iVar10) * 4);
        if (uVar8 < 0xfffffffb) {
          if (uVar8 == 0xfffffffa) {
            local_1c = 0x10c;
          }
          else if (uVar8 == 0) {
            local_1c = 0x102;
          }
          else if (uVar8 == 1) {
            local_1c = 0x103;
          }
          else if (uVar8 == 2) {
            local_1c = 0x104;
          }
          else if (uVar8 == 3) {
            local_1c = 0x105;
          }
          else if (uVar8 == 4) {
            local_1c = 0x106;
          }
          else if (uVar8 == 5) {
            local_1c = 0x107;
          }
        }
        else if (uVar8 == 0xfffffffb) {
          local_1c = 0x10b;
        }
        else if (uVar8 == 0xfffffffc) {
          local_1c = 0x10a;
        }
        else if (uVar8 == 0xfffffffd) {
          local_1c = 0x108;
        }
        else if (uVar8 == 0xfffffffe) {
          local_1c = 0x109;
        }
        else if (uVar8 == 0xffffffff) {
          *(undefined4 *)(in_ECX + 0x54) = 0x7e7;
          goto LAB_00906b56;
        }
        local_5c = (&DAT_00a25ae4)[iVar13 * 0x11];
        bVar16 = false;
        if ((((5 < iVar10) && (iVar10 < 10)) && (0x102 < local_1c)) && (local_1c < 0x108)) {
          bVar18 = true;
        }
        if (((((3 < iVar10) && (iVar10 < 6)) || ((5 < iVar10 && (iVar10 < 0xf)))) &&
            ((0x102 < local_1c && (local_1c < 0x108)))) && (local_5c != 0x1f)) {
          bVar1 = true;
        }
        if (9 < iVar10) {
          if ((iVar10 < 0xf) && (local_5c == 0x1f)) {
            bVar2 = true;
          }
          if ((((9 < iVar10) && (iVar10 < 0xf)) && (0x102 < local_1c)) && (local_1c < 0x108)) {
            bVar3 = true;
          }
        }
        if ((((3 < iVar10) && (iVar10 < 6)) || ((9 < iVar10 && (iVar10 < 0xf)))) &&
           (local_5c == 0x1f)) {
          bVar19 = true;
        }
        if (((0xc < iVar10) && (iVar10 < 0xf)) && (local_5c == 0x1f)) {
          bVar4 = true;
        }
        if (((-1 < iVar10) && (iVar10 < 6)) && (local_5c == 0x1f)) {
          bVar5 = true;
        }
        if (((local_5c == 0x28) || (local_5c == 0x2c)) || (local_5c == 0x5e)) {
          bVar20 = true;
        }
        *(undefined4 *)(in_ECX + 0x54) = 0x7e8;
      }
      else {
        if (bVar1) {
          iVar10 = 4;
          bVar17 = true;
          pbVar9 = local_18;
          pbVar14 = &DAT_00a27bac;
          do {
            if (iVar10 == 0) break;
            iVar10 = iVar10 + -1;
            bVar17 = *pbVar9 == *pbVar14;
            pbVar9 = pbVar9 + 1;
            pbVar14 = pbVar14 + 1;
          } while (bVar17);
          if (bVar17) {
            local_20 = local_20 | 0x100000;
            bVar18 = false;
            bVar1 = false;
            goto LAB_00906af6;
          }
        }
        if (bVar2) {
          iVar10 = 9;
          bVar17 = true;
          pbVar9 = local_18;
          pbVar14 = (byte *)s_centroid_00a27ba0;
          do {
            if (iVar10 == 0) break;
            iVar10 = iVar10 + -1;
            bVar17 = *pbVar9 == *pbVar14;
            pbVar9 = pbVar9 + 1;
            pbVar14 = pbVar14 + 1;
          } while (bVar17);
          if (bVar17) {
            local_20 = local_20 | 0x400000;
            bVar2 = false;
            goto LAB_00906af6;
          }
        }
        if (bVar18) {
          bVar18 = true;
          iVar10 = iVar13;
          pbVar9 = local_18;
          pbVar14 = &DAT_00a27b9c;
          do {
            if (iVar10 == 0) break;
            iVar10 = iVar10 + -1;
            bVar18 = *pbVar9 == *pbVar14;
            pbVar9 = pbVar9 + 1;
            pbVar14 = pbVar14 + 1;
          } while (bVar18);
          if (bVar18) {
            local_20 = 0x3000000;
          }
          else {
            bVar18 = true;
            iVar10 = iVar13;
            pbVar9 = local_18;
            pbVar14 = &DAT_00a27b98;
            do {
              if (iVar10 == 0) break;
              iVar10 = iVar10 + -1;
              bVar18 = *pbVar9 == *pbVar14;
              pbVar9 = pbVar9 + 1;
              pbVar14 = pbVar14 + 1;
            } while (bVar18);
            if (bVar18) {
              local_20 = 0x2000000;
            }
            else {
              bVar18 = true;
              iVar10 = iVar13;
              pbVar9 = local_18;
              pbVar14 = &DAT_00a27b94;
              do {
                if (iVar10 == 0) break;
                iVar10 = iVar10 + -1;
                bVar18 = *pbVar9 == *pbVar14;
                pbVar9 = pbVar9 + 1;
                pbVar14 = pbVar14 + 1;
              } while (bVar18);
              if (bVar18) {
                local_20 = 0x1000000;
              }
              else {
                bVar18 = true;
                iVar10 = iVar13;
                pbVar9 = local_18;
                pbVar14 = &DAT_00a27b90;
                do {
                  if (iVar10 == 0) break;
                  iVar10 = iVar10 + -1;
                  bVar18 = *pbVar9 == *pbVar14;
                  pbVar9 = pbVar9 + 1;
                  pbVar14 = pbVar14 + 1;
                } while (bVar18);
                if (bVar18) {
                  local_20 = 0xf000000;
                }
                else {
                  bVar18 = true;
                  iVar10 = iVar13;
                  pbVar9 = local_18;
                  pbVar14 = &DAT_00a27b8c;
                  do {
                    if (iVar10 == 0) break;
                    iVar10 = iVar10 + -1;
                    bVar18 = *pbVar9 == *pbVar14;
                    pbVar9 = pbVar9 + 1;
                    pbVar14 = pbVar14 + 1;
                  } while (bVar18);
                  if (bVar18) {
                    local_20 = 0xe000000;
                  }
                  else {
                    bVar18 = true;
                    pbVar9 = local_18;
                    pbVar14 = &DAT_00a27b88;
                    do {
                      if (iVar13 == 0) break;
                      iVar13 = iVar13 + -1;
                      bVar18 = *pbVar9 == *pbVar14;
                      pbVar9 = pbVar9 + 1;
                      pbVar14 = pbVar14 + 1;
                    } while (bVar18);
                    if (!bVar18) goto LAB_00906b56;
                    local_20 = 0xd000000;
                  }
                }
              }
            }
          }
          bVar18 = false;
        }
        else {
          if (bVar19) {
            uVar8 = 0;
            bVar19 = true;
            iVar10 = iVar13;
            pbVar9 = local_18;
            pbVar14 = &DAT_00a27b84;
            do {
              if (iVar10 == 0) break;
              iVar10 = iVar10 + -1;
              bVar19 = *pbVar9 == *pbVar14;
              pbVar9 = pbVar9 + 1;
              pbVar14 = pbVar14 + 1;
            } while (bVar19);
            if (bVar19) {
              uVar8 = 0x10000000;
            }
            else {
              iVar10 = 5;
              bVar19 = true;
              pbVar9 = local_18;
              pbVar14 = &DAT_00a27b7c;
              do {
                if (iVar10 == 0) break;
                iVar10 = iVar10 + -1;
                bVar19 = *pbVar9 == *pbVar14;
                pbVar9 = pbVar9 + 1;
                pbVar14 = pbVar14 + 1;
              } while (bVar19);
              if (bVar19) {
                uVar8 = 0x18000000;
              }
              else {
                iVar10 = 7;
                bVar19 = true;
                pbVar9 = local_18;
                pbVar14 = (byte *)s_volume_00a27b74;
                do {
                  if (iVar10 == 0) break;
                  iVar10 = iVar10 + -1;
                  bVar19 = *pbVar9 == *pbVar14;
                  pbVar9 = pbVar9 + 1;
                  pbVar14 = pbVar14 + 1;
                } while (bVar19);
                if (bVar19) {
                  uVar8 = 0x20000000;
                }
              }
            }
            local_24 = local_24 | uVar8;
            bVar19 = false;
            if (uVar8 != 0) {
              bVar4 = false;
              bVar5 = false;
              goto LAB_00906af6;
            }
          }
          if (bVar3) {
            bVar17 = true;
            pbVar9 = local_18;
            pbVar14 = &DAT_00a27b70;
            do {
              if (iVar13 == 0) break;
              iVar13 = iVar13 + -1;
              bVar17 = *pbVar9 == *pbVar14;
              pbVar9 = pbVar9 + 1;
              pbVar14 = pbVar14 + 1;
            } while (bVar17);
            if (bVar17) {
              local_20 = local_20 | 0x200000;
              bVar3 = false;
              goto LAB_00906af6;
            }
          }
          if (bVar4) {
            pbVar9 = local_18;
            if (local_18[0] == 0) {
LAB_009066f7:
              uVar8 = 0;
            }
            else {
              do {
                iVar13 = _isalpha((int)(char)*pbVar9);
                if (iVar13 == 0) break;
                pbVar9 = pbVar9 + 1;
              } while (*pbVar9 != 0);
              if (*pbVar9 == 0) goto LAB_009066f7;
              uVar8 = _atol((char *)pbVar9);
            }
            if (0xf < uVar8) goto LAB_00906892;
            bVar7 = *pbVar9;
            pbVar14 = pbVar9;
            if (bVar7 != 0) {
              *pbVar9 = 0;
              pbVar14 = pbVar9 + 1;
            }
            bVar6 = *pbVar14;
            if (bVar6 != 0) {
              do {
                iVar13 = _isdigit((int)(char)bVar6);
                if (iVar13 == 0) break;
                pbVar14 = pbVar14 + 1;
                bVar6 = *pbVar14;
              } while (bVar6 != 0);
              if (*pbVar14 == 0) goto LAB_00906736;
LAB_0090688a:
              *pbVar9 = bVar7;
              goto LAB_00906892;
            }
LAB_00906736:
            iVar13 = 9;
            uVar11 = 0;
            bVar17 = true;
            pbVar14 = local_18;
            pbVar15 = (byte *)s_position_00a27b64;
            do {
              if (iVar13 == 0) break;
              iVar13 = iVar13 + -1;
              bVar17 = *pbVar14 == *pbVar15;
              pbVar14 = pbVar14 + 1;
              pbVar15 = pbVar15 + 1;
            } while (bVar17);
            if (bVar17) {
              if (uVar8 == 0) goto LAB_0090688a;
            }
            else {
              iVar13 = 0xc;
              bVar17 = true;
              pbVar14 = local_18;
              pbVar15 = (byte *)s_blendweight_00a27b58;
              do {
                if (iVar13 == 0) break;
                iVar13 = iVar13 + -1;
                bVar17 = *pbVar14 == *pbVar15;
                pbVar14 = pbVar14 + 1;
                pbVar15 = pbVar15 + 1;
              } while (bVar17);
              if (bVar17) {
                uVar11 = 1;
              }
              else {
                iVar13 = 0xd;
                bVar17 = true;
                pbVar14 = local_18;
                pbVar15 = (byte *)s_blendindices_00a27b48;
                do {
                  if (iVar13 == 0) break;
                  iVar13 = iVar13 + -1;
                  bVar17 = *pbVar14 == *pbVar15;
                  pbVar14 = pbVar14 + 1;
                  pbVar15 = pbVar15 + 1;
                } while (bVar17);
                if (bVar17) {
                  uVar11 = 2;
                }
                else {
                  iVar13 = 7;
                  bVar17 = true;
                  pbVar14 = local_18;
                  pbVar15 = (byte *)s_normal_00a27b40;
                  do {
                    if (iVar13 == 0) break;
                    iVar13 = iVar13 + -1;
                    bVar17 = *pbVar14 == *pbVar15;
                    pbVar14 = pbVar14 + 1;
                    pbVar15 = pbVar15 + 1;
                  } while (bVar17);
                  if (bVar17) {
                    uVar11 = 3;
                  }
                  else {
                    uVar11 = 6;
                    bVar17 = true;
                    uVar12 = uVar11;
                    pbVar14 = local_18;
                    pbVar15 = (byte *)s_psize_00a27b38;
                    do {
                      if (uVar12 == 0) break;
                      uVar12 = uVar12 - 1;
                      bVar17 = *pbVar14 == *pbVar15;
                      pbVar14 = pbVar14 + 1;
                      pbVar15 = pbVar15 + 1;
                    } while (bVar17);
                    if (bVar17) {
                      uVar11 = 4;
                    }
                    else {
                      iVar13 = 9;
                      bVar17 = true;
                      pbVar14 = local_18;
                      pbVar15 = (byte *)s_texcoord_00a27948;
                      do {
                        if (iVar13 == 0) break;
                        iVar13 = iVar13 + -1;
                        bVar17 = *pbVar14 == *pbVar15;
                        pbVar14 = pbVar14 + 1;
                        pbVar15 = pbVar15 + 1;
                      } while (bVar17);
                      if (bVar17) {
                        uVar11 = 5;
                      }
                      else {
                        iVar13 = 8;
                        bVar17 = true;
                        pbVar14 = local_18;
                        pbVar15 = (byte *)s_tangent_00a27b30;
                        do {
                          if (iVar13 == 0) break;
                          iVar13 = iVar13 + -1;
                          bVar17 = *pbVar14 == *pbVar15;
                          pbVar14 = pbVar14 + 1;
                          pbVar15 = pbVar15 + 1;
                        } while (bVar17);
                        if (!bVar17) {
                          iVar13 = 9;
                          bVar17 = true;
                          pbVar14 = local_18;
                          pbVar15 = (byte *)s_binormal_00a27b24;
                          do {
                            if (iVar13 == 0) break;
                            iVar13 = iVar13 + -1;
                            bVar17 = *pbVar14 == *pbVar15;
                            pbVar14 = pbVar14 + 1;
                            pbVar15 = pbVar15 + 1;
                          } while (bVar17);
                          if (bVar17) {
                            uVar11 = 7;
                          }
                          else {
                            iVar13 = 0xb;
                            bVar17 = true;
                            pbVar14 = local_18;
                            pbVar15 = (byte *)s_tessfactor_00a27b18;
                            do {
                              if (iVar13 == 0) break;
                              iVar13 = iVar13 + -1;
                              bVar17 = *pbVar14 == *pbVar15;
                              pbVar14 = pbVar14 + 1;
                              pbVar15 = pbVar15 + 1;
                            } while (bVar17);
                            if (bVar17) {
                              uVar11 = 8;
                            }
                            else {
                              uVar11 = 10;
                              bVar17 = true;
                              uVar12 = uVar11;
                              pbVar14 = local_18;
                              pbVar15 = (byte *)s_positiont_00a27b0c;
                              do {
                                if (uVar12 == 0) break;
                                uVar12 = uVar12 - 1;
                                bVar17 = *pbVar14 == *pbVar15;
                                pbVar14 = pbVar14 + 1;
                                pbVar15 = pbVar15 + 1;
                              } while (bVar17);
                              if (bVar17) {
                                uVar11 = 9;
                              }
                              else {
                                iVar13 = 6;
                                bVar17 = true;
                                pbVar14 = local_18;
                                pbVar15 = (byte *)s_color_00a27b04;
                                do {
                                  if (iVar13 == 0) break;
                                  iVar13 = iVar13 + -1;
                                  bVar17 = *pbVar14 == *pbVar15;
                                  pbVar14 = pbVar14 + 1;
                                  pbVar15 = pbVar15 + 1;
                                } while (bVar17);
                                if (!bVar17) {
                                  iVar13 = 4;
                                  bVar17 = true;
                                  pbVar14 = local_18;
                                  pbVar15 = &DAT_00a27b00;
                                  do {
                                    if (iVar13 == 0) break;
                                    iVar13 = iVar13 + -1;
                                    bVar17 = *pbVar14 == *pbVar15;
                                    pbVar14 = pbVar14 + 1;
                                    pbVar15 = pbVar15 + 1;
                                  } while (bVar17);
                                  if (bVar17) {
                                    uVar11 = 0xb;
                                  }
                                  else {
                                    iVar13 = 6;
                                    bVar17 = true;
                                    pbVar14 = local_18;
                                    pbVar15 = (byte *)s_depth_00a27af8;
                                    do {
                                      if (iVar13 == 0) break;
                                      iVar13 = iVar13 + -1;
                                      bVar17 = *pbVar14 == *pbVar15;
                                      pbVar14 = pbVar14 + 1;
                                      pbVar15 = pbVar15 + 1;
                                    } while (bVar17);
                                    if (bVar17) {
                                      uVar11 = 0xc;
                                    }
                                    else {
                                      iVar13 = 7;
                                      bVar17 = true;
                                      pbVar14 = local_18;
                                      pbVar15 = (byte *)s_sample_00a27af0;
                                      do {
                                        if (iVar13 == 0) break;
                                        iVar13 = iVar13 + -1;
                                        bVar17 = *pbVar14 == *pbVar15;
                                        pbVar14 = pbVar14 + 1;
                                        pbVar15 = pbVar15 + 1;
                                      } while (bVar17);
                                      if (!bVar17) goto LAB_0090688a;
                                      uVar11 = 0xd;
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
            local_24 = local_24 | (uVar8 & 0xf) << 0x10 | uVar11;
            bVar4 = false;
          }
          else {
LAB_00906892:
            if (!bVar5) {
              if (bVar20) {
                iVar13 = 3;
                bVar20 = true;
                iVar10 = iVar13;
                pbVar9 = local_18;
                pbVar14 = &DAT_00a27aec;
                do {
                  if (iVar10 == 0) break;
                  iVar10 = iVar10 + -1;
                  bVar20 = *pbVar9 == *pbVar14;
                  pbVar9 = pbVar9 + 1;
                  pbVar14 = pbVar14 + 1;
                } while (bVar20);
                if (bVar20) {
                  local_24 = 1;
                }
                else {
                  bVar20 = true;
                  iVar10 = iVar13;
                  pbVar9 = local_18;
                  pbVar14 = &DAT_00a27ae8;
                  do {
                    if (iVar10 == 0) break;
                    iVar10 = iVar10 + -1;
                    bVar20 = *pbVar9 == *pbVar14;
                    pbVar9 = pbVar9 + 1;
                    pbVar14 = pbVar14 + 1;
                  } while (bVar20);
                  if (bVar20) {
                    local_24 = 2;
                  }
                  else {
                    bVar20 = true;
                    iVar10 = iVar13;
                    pbVar9 = local_18;
                    pbVar14 = &DAT_00a27ae4;
                    do {
                      if (iVar10 == 0) break;
                      iVar10 = iVar10 + -1;
                      bVar20 = *pbVar9 == *pbVar14;
                      pbVar9 = pbVar9 + 1;
                      pbVar14 = pbVar14 + 1;
                    } while (bVar20);
                    if (bVar20) {
                      local_24 = 3;
                    }
                    else {
                      bVar20 = true;
                      iVar10 = iVar13;
                      pbVar9 = local_18;
                      pbVar14 = &DAT_00a27ae0;
                      do {
                        if (iVar10 == 0) break;
                        iVar10 = iVar10 + -1;
                        bVar20 = *pbVar9 == *pbVar14;
                        pbVar9 = pbVar9 + 1;
                        pbVar14 = pbVar14 + 1;
                      } while (bVar20);
                      if (bVar20) {
                        local_24 = 4;
                      }
                      else {
                        bVar20 = true;
                        iVar10 = iVar13;
                        pbVar9 = local_18;
                        pbVar14 = &DAT_00a27adc;
                        do {
                          if (iVar10 == 0) break;
                          iVar10 = iVar10 + -1;
                          bVar20 = *pbVar9 == *pbVar14;
                          pbVar9 = pbVar9 + 1;
                          pbVar14 = pbVar14 + 1;
                        } while (bVar20);
                        if (bVar20) {
                          local_24 = 5;
                        }
                        else {
                          bVar20 = true;
                          pbVar9 = local_18;
                          pbVar14 = &DAT_00a27ad8;
                          do {
                            if (iVar13 == 0) break;
                            iVar13 = iVar13 + -1;
                            bVar20 = *pbVar9 == *pbVar14;
                            pbVar9 = pbVar9 + 1;
                            pbVar14 = pbVar14 + 1;
                          } while (bVar20);
                          if (!bVar20) goto LAB_00906b56;
                          local_24 = 6;
                        }
                      }
                    }
                  }
                }
                bVar20 = false;
                goto LAB_00906af6;
              }
              goto LAB_00906b56;
            }
            pbVar9 = local_18;
            if (local_18[0] == 0) {
LAB_009068c9:
              uVar8 = 0;
            }
            else {
              do {
                iVar13 = _isalpha((int)(char)*pbVar9);
                if (iVar13 == 0) break;
                pbVar9 = pbVar9 + 1;
              } while (*pbVar9 != 0);
              if (*pbVar9 == 0) goto LAB_009068c9;
              uVar8 = _atol((char *)pbVar9);
            }
            if (0xf < uVar8) goto LAB_00906b56;
            if (*pbVar9 != 0) {
              *pbVar9 = 0;
              pbVar9 = pbVar9 + 1;
            }
            bVar7 = *pbVar9;
            if (bVar7 != 0) {
              do {
                iVar13 = _isdigit((int)(char)bVar7);
                if (iVar13 == 0) break;
                pbVar9 = pbVar9 + 1;
                bVar7 = *pbVar9;
              } while (bVar7 != 0);
              if (*pbVar9 != 0) goto LAB_00906b56;
            }
            iVar13 = 9;
            local_24 = 0;
            bVar19 = true;
            pbVar9 = local_18;
            pbVar14 = (byte *)s_position_00a27b64;
            do {
              if (iVar13 == 0) break;
              iVar13 = iVar13 + -1;
              bVar19 = *pbVar9 == *pbVar14;
              pbVar9 = pbVar9 + 1;
              pbVar14 = pbVar14 + 1;
            } while (bVar19);
            if (!bVar19) {
              iVar13 = 0xc;
              bVar19 = true;
              pbVar9 = local_18;
              pbVar14 = (byte *)s_blendweight_00a27b58;
              do {
                if (iVar13 == 0) break;
                iVar13 = iVar13 + -1;
                bVar19 = *pbVar9 == *pbVar14;
                pbVar9 = pbVar9 + 1;
                pbVar14 = pbVar14 + 1;
              } while (bVar19);
              if (bVar19) {
                local_24 = 1;
              }
              else {
                iVar13 = 0xd;
                bVar19 = true;
                pbVar9 = local_18;
                pbVar14 = (byte *)s_blendindices_00a27b48;
                do {
                  if (iVar13 == 0) break;
                  iVar13 = iVar13 + -1;
                  bVar19 = *pbVar9 == *pbVar14;
                  pbVar9 = pbVar9 + 1;
                  pbVar14 = pbVar14 + 1;
                } while (bVar19);
                if (bVar19) {
                  local_24 = 2;
                }
                else {
                  iVar13 = 7;
                  bVar19 = true;
                  pbVar9 = local_18;
                  pbVar14 = (byte *)s_normal_00a27b40;
                  do {
                    if (iVar13 == 0) break;
                    iVar13 = iVar13 + -1;
                    bVar19 = *pbVar9 == *pbVar14;
                    pbVar9 = pbVar9 + 1;
                    pbVar14 = pbVar14 + 1;
                  } while (bVar19);
                  if (bVar19) {
                    local_24 = 3;
                  }
                  else {
                    iVar13 = 6;
                    bVar19 = true;
                    pbVar9 = local_18;
                    pbVar14 = (byte *)s_psize_00a27b38;
                    do {
                      if (iVar13 == 0) break;
                      iVar13 = iVar13 + -1;
                      bVar19 = *pbVar9 == *pbVar14;
                      pbVar9 = pbVar9 + 1;
                      pbVar14 = pbVar14 + 1;
                    } while (bVar19);
                    if (bVar19) {
                      local_24 = 4;
                    }
                    else {
                      iVar13 = 9;
                      bVar19 = true;
                      pbVar9 = local_18;
                      pbVar14 = (byte *)s_texcoord_00a27948;
                      do {
                        if (iVar13 == 0) break;
                        iVar13 = iVar13 + -1;
                        bVar19 = *pbVar9 == *pbVar14;
                        pbVar9 = pbVar9 + 1;
                        pbVar14 = pbVar14 + 1;
                      } while (bVar19);
                      if (bVar19) {
                        local_24 = 5;
                      }
                      else {
                        local_24 = 8;
                        bVar19 = true;
                        uVar11 = local_24;
                        pbVar9 = local_18;
                        pbVar14 = (byte *)s_tangent_00a27b30;
                        do {
                          if (uVar11 == 0) break;
                          uVar11 = uVar11 - 1;
                          bVar19 = *pbVar9 == *pbVar14;
                          pbVar9 = pbVar9 + 1;
                          pbVar14 = pbVar14 + 1;
                        } while (bVar19);
                        if (bVar19) {
                          local_24 = 6;
                        }
                        else {
                          iVar13 = 9;
                          bVar19 = true;
                          pbVar9 = local_18;
                          pbVar14 = (byte *)s_binormal_00a27b24;
                          do {
                            if (iVar13 == 0) break;
                            iVar13 = iVar13 + -1;
                            bVar19 = *pbVar9 == *pbVar14;
                            pbVar9 = pbVar9 + 1;
                            pbVar14 = pbVar14 + 1;
                          } while (bVar19);
                          if (bVar19) {
                            local_24 = 7;
                          }
                          else {
                            iVar13 = 0xb;
                            bVar19 = true;
                            pbVar9 = local_18;
                            pbVar14 = (byte *)s_tessfactor_00a27b18;
                            do {
                              if (iVar13 == 0) break;
                              iVar13 = iVar13 + -1;
                              bVar19 = *pbVar9 == *pbVar14;
                              pbVar9 = pbVar9 + 1;
                              pbVar14 = pbVar14 + 1;
                            } while (bVar19);
                            if (!bVar19) {
                              local_24 = 10;
                              bVar19 = true;
                              uVar11 = local_24;
                              pbVar9 = local_18;
                              pbVar14 = (byte *)s_positiont_00a27b0c;
                              do {
                                if (uVar11 == 0) break;
                                uVar11 = uVar11 - 1;
                                bVar19 = *pbVar9 == *pbVar14;
                                pbVar9 = pbVar9 + 1;
                                pbVar14 = pbVar14 + 1;
                              } while (bVar19);
                              if (bVar19) {
                                local_24 = 9;
                              }
                              else {
                                iVar13 = 6;
                                bVar19 = true;
                                pbVar9 = local_18;
                                pbVar14 = (byte *)s_color_00a27b04;
                                do {
                                  if (iVar13 == 0) break;
                                  iVar13 = iVar13 + -1;
                                  bVar19 = *pbVar9 == *pbVar14;
                                  pbVar9 = pbVar9 + 1;
                                  pbVar14 = pbVar14 + 1;
                                } while (bVar19);
                                if (!bVar19) {
                                  iVar13 = 4;
                                  bVar19 = true;
                                  pbVar9 = local_18;
                                  pbVar14 = &DAT_00a27b00;
                                  do {
                                    if (iVar13 == 0) break;
                                    iVar13 = iVar13 + -1;
                                    bVar19 = *pbVar9 == *pbVar14;
                                    pbVar9 = pbVar9 + 1;
                                    pbVar14 = pbVar14 + 1;
                                  } while (bVar19);
                                  if (bVar19) {
                                    local_24 = 0xb;
                                  }
                                  else {
                                    iVar13 = 6;
                                    bVar19 = true;
                                    pbVar9 = local_18;
                                    pbVar14 = (byte *)s_depth_00a27af8;
                                    do {
                                      if (iVar13 == 0) break;
                                      iVar13 = iVar13 + -1;
                                      bVar19 = *pbVar9 == *pbVar14;
                                      pbVar9 = pbVar9 + 1;
                                      pbVar14 = pbVar14 + 1;
                                    } while (bVar19);
                                    if (bVar19) {
                                      local_24 = 0xc;
                                    }
                                    else {
                                      iVar13 = 7;
                                      bVar19 = true;
                                      pbVar9 = local_18;
                                      pbVar14 = (byte *)s_sample_00a27af0;
                                      do {
                                        if (iVar13 == 0) break;
                                        iVar13 = iVar13 + -1;
                                        bVar19 = *pbVar9 == *pbVar14;
                                        pbVar9 = pbVar9 + 1;
                                        pbVar14 = pbVar14 + 1;
                                      } while (bVar19);
                                      if (!bVar19) goto LAB_00906b56;
                                      local_24 = 0xd;
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
            local_24 = (uVar8 & 0xf) << 0x10 | local_24;
            bVar5 = false;
          }
          bVar19 = false;
        }
      }
LAB_00906af6:
    } while (*local_2c != 0);
    if (local_5c == 0x28) {
      if (bVar20) goto LAB_00906b51;
      if (*(int *)(&DAT_00a27138 + *(int *)(in_ECX + 0x38) * 4) != -1) {
        local_5c = 0x29;
        local_1c = 0x10c;
        goto LAB_00906b26;
      }
    }
    else {
LAB_00906b26:
      if (local_5c == 0x2c) {
        if (bVar20) goto LAB_00906b51;
        if (*(int *)(&DAT_00a27180 + *(int *)(in_ECX + 0x38) * 4) == -1) goto LAB_00906b56;
        local_5c = 0x2d;
        local_1c = 0x10c;
      }
      if ((local_5c != 0x5e) || (!bVar20)) {
LAB_00906b51:
        iVar13 = local_5c;
        if (!bVar5) goto LAB_00906b5d;
      }
    }
LAB_00906b56:
    local_1c = 0x10d;
  }
  return local_1c;
}


// ==== FUN_00906b81 @ 0x00906b81 ====

uint FUN_00906b81(int param_1)

{
  char *pcVar1;
  uint uVar2;
  char cVar3;
  undefined4 *in_ECX;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 *local_8;
  
  pcVar1 = *(char **)(param_1 + 8);
  uVar2 = 0;
  if ((pcVar1 == (char *)0x0) || (cVar3 = *pcVar1, cVar3 == '\0')) {
    uVar2 = 0xf0000;
  }
  else {
    pcVar5 = pcVar1;
    local_8 = in_ECX;
    do {
      if (cVar3 < 'x') {
        if ((cVar3 == 'w') || (cVar3 == 'a')) {
          puVar4 = (undefined4 *)0x3;
          uVar2 = uVar2 | 0x80000;
        }
        else {
          if (cVar3 != 'b') {
            if (cVar3 == 'g') goto LAB_00906bfe;
            if (cVar3 != 'r') goto LAB_00906c08;
            goto LAB_00906bc3;
          }
LAB_00906bf4:
          puVar4 = (undefined4 *)0x2;
          uVar2 = uVar2 | 0x40000;
        }
      }
      else if (cVar3 == 'x') {
LAB_00906bc3:
        puVar4 = (undefined4 *)0x0;
        uVar2 = uVar2 | 0x10000;
      }
      else {
        if (cVar3 != 'y') {
          if (cVar3 != 'z') goto LAB_00906c08;
          goto LAB_00906bf4;
        }
LAB_00906bfe:
        puVar4 = (undefined4 *)0x1;
        uVar2 = uVar2 | 0x20000;
      }
      if ((pcVar5 != pcVar1) && (puVar4 <= local_8)) {
LAB_00906c08:
        FUN_008bd320(*in_ECX,param_1,0x7d3,s_invalid_mask___s__00a27bb0,pcVar1);
        in_ECX[0x13] = 1;
        return 0;
      }
      pcVar5 = pcVar5 + 1;
      cVar3 = *pcVar5;
      local_8 = puVar4;
    } while (cVar3 != '\0');
  }
  return uVar2;
}


// ==== FUN_00906c36 @ 0x00906c36 ====

uint FUN_00906c36(int param_1)

{
  uint uVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 *in_ECX;
  int iVar5;
  uint local_c;
  uint local_8;
  
  pcVar3 = *(char **)(param_1 + 8);
  iVar5 = 0;
  local_c = 0;
  if ((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) {
    local_c = 0xe40000;
  }
  else {
    local_8 = 0x10;
    pcVar4 = pcVar3;
    do {
      cVar2 = *pcVar4;
      if (cVar2 != '\0') {
        if (cVar2 < 'x') {
          if ((cVar2 != 'w') && (cVar2 != 'a')) {
            if (cVar2 == 'b') goto LAB_00906cd8;
            if (cVar2 == 'g') goto LAB_00906cdc;
            if (cVar2 == 'r') goto LAB_00906c89;
            goto LAB_00906ca5;
          }
          iVar5 = 3;
        }
        else if (cVar2 == 'x') {
LAB_00906c89:
          iVar5 = 0;
        }
        else if (cVar2 == 'y') {
LAB_00906cdc:
          iVar5 = 1;
        }
        else {
          if (cVar2 != 'z') goto LAB_00906ca5;
LAB_00906cd8:
          iVar5 = 2;
        }
        pcVar4 = pcVar4 + 1;
      }
      uVar1 = local_8 + 2;
      local_c = local_c | iVar5 << ((byte)local_8 & 0x1f);
      local_8 = uVar1;
    } while (uVar1 < 0x18);
    if (*pcVar4 != '\0') {
LAB_00906ca5:
      FUN_008bd320(*in_ECX,param_1,0x7d4,s_invalid_swizzle___s__00a27bc4,pcVar3);
      in_ECX[0x13] = 1;
      local_c = 0;
    }
  }
  return local_c;
}


// ==== FUN_00906cf2 @ 0x00906cf2 ====

int FUN_00906cf2(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 8);
  if (piVar1 != (int *)0x0) {
    uVar2 = *(uint *)(in_ECX + 100);
    if (uVar2 < *(uint *)(in_ECX + 0x5c)) {
      *(int *)(in_ECX + 0x30) = param_1;
      iVar3 = (**(code **)(*piVar1 + 0x10))
                        (piVar1,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                         *(int *)(in_ECX + 0x58) + uVar2 * 4,*(uint *)(in_ECX + 0x5c) - uVar2);
      if (iVar3 < 0) {
        *(undefined4 *)(in_ECX + 0x4c) = 1;
        *(undefined4 *)(in_ECX + 0x50) = 1;
      }
      *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(in_ECX + 0x5c);
      return iVar3;
    }
  }
  return 0;
}


// ==== FUN_00906d47 @ 0x00906d47 ====

undefined4 FUN_00906d47(uint param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  int in_ECX;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar4 = param_1;
  uVar3 = param_1 + *(int *)(in_ECX + 0x5c);
  param_1 = *(uint *)(in_ECX + 0x60);
  if (param_1 < uVar3) {
    if (param_1 == 0) {
      param_1 = 0x100;
    }
    if (param_1 < uVar3) {
      do {
        param_1 = param_1 * 2;
      } while (param_1 < (uint)(*(int *)(in_ECX + 0x5c) + iVar4));
    }
    puVar1 = operator_new(param_1 << 2);
    if (puVar1 != (undefined4 *)0x0) {
      puVar5 = *(undefined4 **)(in_ECX + 0x58);
      for (uVar3 = *(uint *)(in_ECX + 0x5c) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar1 = puVar1 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar1 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar1 = (undefined4 *)((int)puVar1 + 1);
      }
      _free(*(void **)(in_ECX + 0x58));
      return extraout_EAX;
    }
    uVar2 = 0x8007000e;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_00906dd8 @ 0x00906dd8 ====

int FUN_00906dd8(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00906d47(1);
  if (-1 < iVar1) {
    *(undefined4 *)(*(int *)(in_ECX + 0x58) + *(int *)(in_ECX + 0x5c) * 4) = param_1;
    *(int *)(in_ECX + 0x5c) = *(int *)(in_ECX + 0x5c) + 1;
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_00906e01 @ 0x00906e01 ====

int FUN_00906e01(uint param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *in_ECX;
  uint uVar7;
  int *piVar8;
  bool bVar9;
  bool bVar10;
  undefined4 uVar11;
  char *pcVar12;
  int *local_8;
  
  iVar4 = param_1;
  *(undefined4 *)(param_1 + 0x58) = in_ECX[0x17] << 2;
  iVar5 = *(int *)(param_1 + 0x30);
  local_8 = (int *)0x1;
  bVar9 = false;
  if (iVar5 == 0x1f) {
    local_8 = (int *)0x2;
  }
  if (in_ECX[0x1e] != 0) {
    if ((((iVar5 == 0x1a) || (iVar5 == 0x19)) || (iVar5 == 0x1c)) || (iVar5 == 0x1e)) {
      pcVar12 = s_call__callnz__label__and_ret_ins_00a27e18;
      uVar11 = 0x7e9;
LAB_00906e7b:
      FUN_008bd320(*in_ECX,param_1 + 0x10,uVar11,pcVar12);
      return -0x7fffbffb;
    }
    if (((((iVar5 == 0x14) || (iVar5 == 0x15)) ||
         ((iVar5 == 0x16 || ((iVar5 == 0x17 || (iVar5 == 0x18)))))) &&
        (*(int *)(param_1 + 0x48) != 0)) && (*(int *)(*(int *)(param_1 + 0x48) + 0x10) == 0)) {
      pcVar12 = s_Matrices_cannot_be_specified_in_t_00a27e68;
      uVar11 = 0x7ea;
      goto LAB_00906e7b;
    }
  }
  iVar5 = *(int *)(param_1 + 0x3c);
  piVar8 = local_8;
  if ((iVar5 != 0) && (*(int *)(iVar5 + 4) == 0x13)) {
    bVar9 = *(int *)(iVar5 + 0x10) == -1;
    if (*(int *)(iVar5 + 0x14) != 0) {
      FUN_008bd320(*in_ECX,param_1 + 0x10,0x7de,s_source_modifiers_are_not_allowed_00a27dd8);
      in_ECX[0x13] = 1;
    }
    iVar5 = *(int *)(iVar5 + 0x28);
    piVar8 = (int *)((int)local_8 + 1);
    if (iVar5 != 0) {
      if (((int)in_ECX[0xe] < 4) || (5 < (int)in_ECX[0xe])) {
        FUN_008bd320(*in_ECX,param_1 + 0x10,0x7d8,s_relative_addressing_of_destinati_00a27d30);
        in_ECX[0x13] = 1;
      }
      else {
        bVar9 = *(int *)(iVar5 + 0x10) == -1 || bVar9;
        if (*(int *)(iVar5 + 0x28) != 0) {
          FUN_008bd320(*in_ECX,param_1 + 0x10,0x7d9,s_only_one_address_register_refere_00a27d88);
          in_ECX[0x13] = 1;
        }
        piVar8 = (int *)((int)local_8 + 2);
      }
    }
  }
  local_8 = piVar8;
  if ((*(int *)(param_1 + 0x40) != 0) && (*(int *)(*(int *)(param_1 + 0x40) + 4) == 0x13)) {
    iVar5 = in_ECX[0xe];
    if (((-1 < iVar5) && (iVar5 < 2)) || ((5 < iVar5 && (iVar5 < 0xb)))) {
      FUN_008bd320(*in_ECX,param_1 + 0x10,0x7e5,s_predicates_are_not_supported_in_t_00a27cfc);
      in_ECX[0x13] = 1;
    }
    iVar5 = *(int *)(param_1 + 0x40);
    local_8 = (int *)((int)local_8 + 1);
    if (*(int *)(iVar5 + 0x10) == -1) {
      bVar9 = true;
    }
    if ((*(int *)(iVar5 + 0x14) != 0) && (*(int *)(iVar5 + 0x14) != 0xd000000)) {
      FUN_008bd320(*in_ECX,param_1 + 0x10,0x7e3,s_source_modifiers_are_not_allowed_00a27ccc);
      in_ECX[0x13] = 1;
    }
    if (*(int *)(iVar5 + 0x28) != 0) {
      FUN_008bd320(*in_ECX,param_1 + 0x10,0x7e4,s_relative_addressing_of_predicate_00a27c80);
      in_ECX[0x13] = 1;
    }
  }
  param_1 = 0;
  piVar8 = (int *)(iVar4 + 0x44);
  do {
    iVar5 = *piVar8;
    if (iVar5 == 0) break;
    iVar6 = *(int *)(iVar4 + 0x30);
    piVar1 = (int *)((int)local_8 + 1);
    if (((iVar6 != 0x51) && (iVar6 != 0x30)) && (iVar6 != 0x2f)) {
      if (*(int *)(iVar5 + 0x10) == -1) {
        bVar9 = true;
      }
      iVar5 = *(int *)(iVar5 + 0x28);
      if (iVar5 != 0) {
        if (*(int *)(iVar5 + 0x10) == -1) {
          bVar9 = true;
        }
        if (*(int *)(iVar5 + 0x28) != 0) {
          FUN_008bd320(*in_ECX,iVar4 + 0x10,0x7d9,s_only_one_address_register_refere_00a27d88);
          in_ECX[0x13] = 1;
        }
        if (in_ECX[0xe] != 0) {
          piVar1 = (int *)((int)local_8 + 2);
        }
      }
    }
    local_8 = piVar1;
    param_1 = param_1 + 1;
    piVar8 = piVar8 + 1;
  } while (param_1 < 4);
  iVar5 = FUN_00906d47(local_8);
  if (iVar5 < 0) {
    return iVar5;
  }
  iVar5 = in_ECX[0x17] + (int)local_8;
  uVar7 = *(uint *)(iVar4 + 0x30);
  if ((uVar7 != 3) ||
     (((iVar6 = in_ECX[0xe], iVar6 < 0 || (5 < iVar6)) && ((iVar6 < 10 || (0xe < iVar6))))))
  goto LAB_009071ab;
  iVar6 = *(int *)(iVar4 + 0x48);
  uVar2 = *(uint *)(iVar6 + 0x14);
  uVar11 = 0x7000000;
  uVar7 = 2;
  if (uVar2 < 0x7000001) {
    if (uVar2 == 0x7000000) {
      *(undefined4 *)(iVar6 + 0x14) = 0x8000000;
      goto LAB_009071ab;
    }
    if (uVar2 == 0) {
      *(undefined4 *)(iVar6 + 0x14) = 0x1000000;
      goto LAB_009071ab;
    }
    if (uVar2 == 0x1000000) {
      *(undefined4 *)(iVar6 + 0x14) = 0;
      goto LAB_009071ab;
    }
    uVar11 = 0x2000000;
    if (uVar2 == 0x2000000) {
      *(undefined4 *)(iVar6 + 0x14) = 0x3000000;
      goto LAB_009071ab;
    }
    if (uVar2 != 0x3000000) {
      uVar11 = 0x4000000;
      if (uVar2 == 0x4000000) {
        *(undefined4 *)(iVar6 + 0x14) = 0x5000000;
        goto LAB_009071ab;
      }
      if (uVar2 != 0x5000000) {
        bVar10 = uVar2 == 0x6000000;
        goto LAB_0090711a;
      }
    }
  }
  else if (uVar2 != 0x8000000) {
    if ((uVar2 != 0x9000000) && (uVar2 != 0xa000000)) {
      uVar11 = 0xb000000;
      if (uVar2 == 0xb000000) {
        *(undefined4 *)(iVar6 + 0x14) = 0xc000000;
        goto LAB_009071ab;
      }
      if (uVar2 == 0xc000000) goto LAB_009071a8;
      bVar10 = uVar2 == 0xd000000;
LAB_0090711a:
      if (!bVar10) goto LAB_009071ab;
    }
    FUN_008bd320(*in_ECX,iVar4 + 0x10,0x7dd,s_source_modifiers_incompatible_wi_00a27c48);
    in_ECX[0x13] = 1;
    goto LAB_009071ab;
  }
LAB_009071a8:
  *(undefined4 *)(iVar6 + 0x14) = uVar11;
LAB_009071ab:
  if (*(int *)(iVar4 + 0x54) != 0) {
    uVar7 = uVar7 | 0x40000000;
  }
  if (*(int *)(iVar4 + 0x40) != 0) {
    uVar7 = uVar7 | 0x10000000;
  }
  iVar6 = in_ECX[0xe];
  if (((0 < iVar6) && (iVar6 < 6)) || ((9 < iVar6 && (iVar6 < 0xf)))) {
    uVar7 = uVar7 | ((int)local_8 + -1) * 0x1000000;
  }
  iVar6 = *(int *)(iVar4 + 0x30);
  if (((iVar6 == 0x29) || (iVar6 == 0x2d)) || (iVar6 == 0x5e)) {
    uVar7 = uVar7 | (*(uint *)(iVar4 + 0x38) & 7) << 0x10;
  }
  *(uint *)(in_ECX[0x16] + in_ECX[0x17] * 4) = uVar7;
  in_ECX[0x17] = in_ECX[0x17] + 1;
  iVar6 = in_ECX[0x17];
  if (*(int *)(iVar4 + 0x30) == 0x1f) {
    *(uint *)(in_ECX[0x16] + iVar6 * 4) = *(uint *)(iVar4 + 0x38) | 0x80000000;
    in_ECX[0x17] = in_ECX[0x17] + 1;
    iVar6 = in_ECX[0x17];
  }
  iVar3 = *(int *)(iVar4 + 0x3c);
  if ((iVar3 != 0) && (*(int *)(iVar3 + 4) == 0x13)) {
    if ((in_ECX[0xe] == 0) && (*(int *)(iVar3 + 0x20) == 0xf0000)) {
      iVar6 = *(int *)(iVar4 + 0x30);
      if ((iVar6 == 0x15) || (iVar6 == 0x17)) {
        *(undefined4 *)(iVar3 + 0x20) = 0x70000;
      }
      else if (iVar6 == 0x18) {
        *(undefined4 *)(iVar3 + 0x20) = 0x30000;
      }
    }
    uVar7 = ((*(uint *)(iVar3 + 0x10) | 0xfffffff8) << 0x14 | *(uint *)(iVar3 + 0x10) & 0x18) << 8 |
            *(uint *)(iVar4 + 0x34) & 0xff00000 | *(uint *)(iVar3 + 0x18) & 0x7ff |
            *(uint *)(iVar3 + 0x20) & 0xf0000;
    if (*(int *)(iVar3 + 0x28) != 0) {
      uVar7 = uVar7 | 0x2000;
    }
    *(uint *)(in_ECX[0x16] + in_ECX[0x17] * 4) = uVar7;
    in_ECX[0x17] = in_ECX[0x17] + 1;
    iVar3 = *(int *)(iVar3 + 0x28);
    iVar6 = in_ECX[0x17];
    if (iVar3 != 0) {
      *(uint *)(in_ECX[0x16] + iVar6 * 4) =
           ((*(uint *)(iVar3 + 0x10) | 0xfffffff8) << 0x14 | *(uint *)(iVar3 + 0x10) & 0x18) << 8 |
           *(uint *)(iVar3 + 0x14) & 0xf000000 | *(uint *)(iVar3 + 0x18) & 0x7ff |
           *(uint *)(iVar3 + 0x24) & 0xff0000;
      in_ECX[0x17] = in_ECX[0x17] + 1;
      iVar6 = in_ECX[0x17];
    }
  }
  iVar3 = *(int *)(iVar4 + 0x40);
  if ((iVar3 != 0) && (*(int *)(iVar3 + 4) == 0x13)) {
    *(uint *)(in_ECX[0x16] + iVar6 * 4) =
         ((*(uint *)(iVar3 + 0x10) | 0xfffffff8) << 0x14 | *(uint *)(iVar3 + 0x10) & 0x18) << 8 |
         *(uint *)(iVar3 + 0x14) & 0xf000000 | *(uint *)(iVar3 + 0x18) & 0x7ff |
         *(uint *)(iVar3 + 0x24) & 0xff0000;
    in_ECX[0x17] = in_ECX[0x17] + 1;
    iVar6 = in_ECX[0x17];
  }
  iVar3 = *(int *)(iVar4 + 0x30);
  if (iVar3 == 0x51) {
    param_1 = 0;
    piVar8 = (int *)(iVar4 + 0x44);
    do {
      iVar3 = *piVar8;
      if (iVar3 == 0) break;
      if ((4 < *(int *)(iVar3 + 0x10)) && (*(int *)(iVar3 + 0x10) < 9)) {
        *(float *)(in_ECX[0x16] + iVar6 * 4) = (float)*(double *)(iVar3 + 0x18);
      }
      in_ECX[0x17] = in_ECX[0x17] + 1;
      param_1 = param_1 + 1;
      iVar6 = in_ECX[0x17];
      piVar8 = piVar8 + 1;
    } while (param_1 < 4);
  }
  else if (iVar3 == 0x30) {
    param_1 = 0;
    piVar8 = (int *)(iVar4 + 0x44);
    do {
      iVar3 = *piVar8;
      if (iVar3 == 0) break;
      if ((*(int *)(iVar3 + 0x10) == 2) || (*(int *)(iVar3 + 0x10) == 4)) {
        *(undefined4 *)(in_ECX[0x16] + iVar6 * 4) = *(undefined4 *)(iVar3 + 0x18);
      }
      in_ECX[0x17] = in_ECX[0x17] + 1;
      param_1 = param_1 + 1;
      iVar6 = in_ECX[0x17];
      piVar8 = piVar8 + 1;
    } while (param_1 < 4);
  }
  else if (iVar3 == 0x2f) {
    *(uint *)(in_ECX[0x16] + iVar6 * 4) = (uint)(*(int *)(*(int *)(iVar4 + 0x44) + 0x18) != 0);
    in_ECX[0x17] = in_ECX[0x17] + 1;
  }
  else {
    param_1 = 0;
    local_8 = (int *)(iVar4 + 0x44);
    do {
      iVar6 = *local_8;
      if (iVar6 == 0) break;
      if (((in_ECX[0xe] == 0) && (*(int *)(iVar6 + 0x24) == 0xe40000)) &&
         ((iVar3 = *(int *)(iVar4 + 0x30), iVar3 == 6 ||
          ((((iVar3 == 7 || (iVar3 == 0xe)) || (iVar3 == 0x4e)) ||
           ((iVar3 == 0xf || (iVar3 == 0x4f)))))))) {
        *(undefined4 *)(iVar6 + 0x24) = 0xff0000;
      }
      uVar7 = ((*(uint *)(iVar6 + 0x10) | 0xfffffff8) << 0x14 | *(uint *)(iVar6 + 0x10) & 0x18) << 8
              | *(uint *)(iVar6 + 0x14) & 0xf000000 | *(uint *)(iVar6 + 0x18) & 0x7ff |
              *(uint *)(iVar6 + 0x24) & 0xff0000;
      if (*(int *)(iVar6 + 0x28) != 0) {
        uVar7 = uVar7 | 0x2000;
      }
      *(uint *)(in_ECX[0x16] + in_ECX[0x17] * 4) = uVar7;
      in_ECX[0x17] = in_ECX[0x17] + 1;
      iVar6 = *(int *)(iVar6 + 0x28);
      if (iVar6 != 0) {
        if (in_ECX[0xe] == 0) {
          if (((*(int *)(iVar6 + 0x10) != 3) || (*(int *)(iVar6 + 0x14) != 0)) ||
             ((*(int *)(iVar6 + 0x18) != 0 || (*(int *)(iVar6 + 0x24) != 0)))) {
            FUN_008bd320(*in_ECX,iVar4 + 0x10,0x7d7,s_only_a0_x_is_allowed_as_a_relati_00a27c08);
            in_ECX[0x13] = 1;
          }
        }
        else {
          *(uint *)(in_ECX[0x16] + in_ECX[0x17] * 4) =
               ((*(uint *)(iVar6 + 0x10) | 0xfffffff8) << 0x14 | *(uint *)(iVar6 + 0x10) & 0x18) <<
               8 | *(uint *)(iVar6 + 0x14) & 0xf000000 | *(uint *)(iVar6 + 0x18) & 0x7ff |
               *(uint *)(iVar6 + 0x24) & 0xff0000;
          in_ECX[0x17] = in_ECX[0x17] + 1;
        }
      }
      param_1 = param_1 + 1;
      local_8 = local_8 + 1;
    } while (param_1 < 4);
  }
  if (in_ECX[0x17] != iVar5) {
    FUN_008bd320(*in_ECX,iVar4 + 0x10,0,s_internal_error__instruction_size_00a27bdc);
    in_ECX[0x13] = 1;
  }
  if (bVar9) {
    in_ECX[0x19] = in_ECX[0x17];
  }
  else {
    iVar5 = FUN_00906cf2(iVar4 + 0x10);
    if (iVar5 < 0) {
      in_ECX[0x14] = 1;
    }
  }
  return 0;
}


// ==== FUN_0090757d @ 0x0090757d ====

int FUN_0090757d(undefined4 *param_1,undefined4 *param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  
  pbVar8 = *(byte **)*param_1;
  if ((((DAT_00a27eb8 == *(short *)pbVar8) || (DAT_00a27eb4 == *(short *)pbVar8)) ||
      (DAT_00a27eb0 == *(short *)pbVar8)) ||
     (((pbVar6 = *(byte **)*param_2, DAT_00a27eb8 == *(short *)pbVar6 ||
       (DAT_00a27eb4 == *(short *)pbVar6)) ||
      (pbVar3 = pbVar8, pbVar4 = pbVar6, DAT_00a27eb0 == *(short *)pbVar6)))) {
    pbVar6 = *(byte **)*param_2;
    do {
      bVar1 = *pbVar8;
      bVar9 = bVar1 < *pbVar6;
      if (bVar1 != *pbVar6) goto LAB_00907614;
      if (bVar1 == 0) break;
      bVar1 = pbVar8[1];
      bVar9 = bVar1 < pbVar6[1];
      if (bVar1 != pbVar6[1]) goto LAB_00907614;
      pbVar8 = pbVar8 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
  }
  else {
    do {
      bVar1 = pbVar3[2];
      bVar2 = pbVar4[2];
      bVar9 = bVar1 < bVar2;
      if (bVar1 != bVar2) {
LAB_00907600:
        iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_00907605;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[3];
      bVar9 = bVar1 < pbVar4[3];
      if (bVar1 != pbVar4[3]) goto LAB_00907600;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_00907605:
    if (iVar5 == 0) {
      iVar7 = 2;
      bVar9 = false;
      iVar5 = 0;
      bVar10 = true;
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar9 = *pbVar8 < *pbVar6;
        bVar10 = *pbVar8 == *pbVar6;
        pbVar8 = pbVar8 + 1;
        pbVar6 = pbVar6 + 1;
      } while (bVar10);
      if (!bVar10) {
LAB_00907614:
        iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
      }
    }
  }
  return iVar5;
}


// ==== FUN_00907644 @ 0x00907644 ====

void FUN_00907644(void)

{
  int iVar1;
  void *_Base;
  undefined4 *in_ECX;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 local_40;
  undefined1 local_3c [4];
  undefined4 local_38;
  uint local_34;
  undefined1 local_30 [4];
  uint local_2c;
  undefined1 local_24 [16];
  void *local_14;
  undefined4 *local_10;
  uint local_c;
  undefined4 *local_8;
  
  FUN_0093cc60(0x464e4946);
  iVar1 = in_ECX[0x1e];
  local_14 = (void *)0x0;
  local_8 = (undefined4 *)0x0;
  iVar1 = *(int *)(iVar1 + 0xac) + *(int *)(iVar1 + 0xa8) + *(int *)(iVar1 + 0xa4) +
          *(int *)(iVar1 + 0xa0) + *(int *)(iVar1 + 0x9c);
  if ((iVar1 != 0) && (_Base = operator_new(iVar1 * 4), local_14 = _Base, _Base != (void *)0x0)) {
    FUN_009060d2(_Base);
    iVar1 = *(int *)(in_ECX[0x1e] + 0xac);
    FUN_009060d2((void *)((int)_Base + iVar1 * 4));
    iVar1 = iVar1 + *(int *)(in_ECX[0x1e] + 0xa8);
    FUN_009060d2((void *)((int)_Base + iVar1 * 4));
    iVar1 = iVar1 + *(int *)(in_ECX[0x1e] + 0x9c);
    FUN_009060d2((void *)((int)_Base + iVar1 * 4));
    iVar1 = iVar1 + *(int *)(in_ECX[0x1e] + 0xa0);
    FUN_009060d2((void *)((int)_Base + iVar1 * 4));
    uVar3 = iVar1 + *(int *)(in_ECX[0x1e] + 0xa4);
    _qsort(_Base,uVar3,4,FUN_0090757d);
    local_10 = (undefined4 *)(uVar3 * 0x14);
    local_8 = operator_new((uint)local_10);
    if (local_8 != (undefined4 *)0x0) {
      puVar4 = &local_40;
      for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      local_38 = 0;
      local_2c = in_ECX[0xf] | 4;
      local_40 = 0x1c;
      local_34 = uVar3;
      iVar1 = FUN_0093ccb5(&local_40,0x1c,1,0);
      if (-1 < iVar1) {
        puVar4 = local_8;
        for (uVar2 = (uint)local_10 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
        for (uVar2 = (uint)local_10 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined1 *)puVar4 = 0;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
        iVar1 = FUN_0093ccb5(local_8,local_10,1,local_30);
        if (-1 < iVar1) {
          local_c = 0;
          if (uVar3 != 0) {
            local_10 = local_8;
            do {
              puVar4 = *(undefined4 **)((int)local_14 + local_c * 4);
              iVar1 = FUN_00909af4(local_24,local_10,*puVar4,puVar4[1],*(undefined4 *)in_ECX[0x16]);
              if (iVar1 < 0) goto LAB_00907896;
              local_c = local_c + 1;
              local_10 = local_10 + 5;
            } while (local_c < uVar3);
          }
          iVar1 = FUN_0093ccb5(s_Microsoft__R__D3DX9_Shader_Assem_00a27ee8,0xffffffff,5,local_3c);
          if (-1 < iVar1) {
            uVar3 = FUN_0093cdee();
            if (uVar3 < 0x8001) {
              iVar1 = FUN_00906d47(uVar3);
              if (-1 < iVar1) {
                _memmove((void *)(in_ECX[0x16] + 4 + uVar3 * 4),(void *)(in_ECX[0x16] + 4),
                         in_ECX[0x17] * 4 - 4);
                iVar1 = FUN_0093cdfa(in_ECX[0x16] + 4,uVar3);
                if (-1 < iVar1) {
                  in_ECX[0x17] = in_ECX[0x17] + uVar3;
                  in_ECX[0x1a] = in_ECX[0x1a] + uVar3;
                  in_ECX[0x19] = in_ECX[0x17];
                }
              }
            }
            else {
              FUN_008bd320(*in_ECX,in_ECX + 4,0x7ef,s_fragment_info_exceeds_maximum_co_00a27ebc);
            }
          }
        }
      }
    }
  }
LAB_00907896:
  _free(local_14);
  return;
}


// ==== FUN_009078b6 @ 0x009078b6 ====

void FUN_009078b6(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *in_ECX;
  
  in_ECX[3] = 0;
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[8] = param_4;
  return;
}


// ==== FUN_009078dc @ 0x009078dc ====

void FUN_009078dc(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *in_ECX;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined2 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 local_54;
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  uint local_48;
  undefined1 local_44 [4];
  uint local_40;
  undefined1 local_3c [12];
  undefined1 local_30 [20];
  int local_1c;
  int local_18;
  uint local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  int local_8;
  
  FUN_0093cc60(0x47554244);
  local_54 = 0x28;
  puVar7 = &local_54;
  for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  iVar3 = 0;
  local_10 = (undefined4 *)0x0;
  local_c = (undefined4 *)0x0;
  local_8 = FUN_0093ccb5(&local_54,0x28,1,0);
  if (local_8 < 0) goto LAB_00907ba0;
  for (iVar1 = in_ECX[0xd]; iVar8 = iVar3, iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
    if ((*(int *)(iVar1 + 8) != 0) && (*(int *)(*(int *)(iVar1 + 8) + 4) == 0x12)) {
      iVar3 = *(int *)(iVar1 + 8);
      iVar8 = iVar3;
      break;
    }
  }
  for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0xc)) {
    local_40 = local_40 + 1;
  }
  if (local_40 == 0) {
LAB_00907a7f:
    if ((((in_ECX[0x1d] == 0) ||
         (local_8 = FUN_0093ccb5(in_ECX[0x1d],0xffffffff,7,local_30), -1 < local_8)) &&
        ((in_ECX[0x1b] == 0 ||
         ((iVar3 = FUN_0093ccb5(in_ECX[0x1b],in_ECX[0x1c],5,local_4c), -1 < iVar3 &&
          (iVar3 = FUN_0093ccb5(&DAT_0099cf70,1,5,0), -1 < iVar3)))))) &&
       (iVar3 = FUN_0093ccb5(s_Microsoft__R__D3DX9_Shader_Assem_00a27ee8,0xffffffff,5,local_50),
       -1 < iVar3)) {
      uVar4 = FUN_0093cdee();
      if (uVar4 < 0x8001) {
        local_8 = FUN_00906d47(uVar4);
        if (local_8 < 0) goto LAB_00907ba0;
        _memmove((void *)(in_ECX[0x16] + 4 + uVar4 * 4),(void *)(in_ECX[0x16] + 4),
                 in_ECX[0x17] * 4 - 4);
        uVar5 = 0;
        if (local_40 != 0) {
          piVar2 = local_c + 1;
          do {
            *piVar2 = *piVar2 + (in_ECX[0x1a] + uVar4) * 4;
            uVar5 = uVar5 + 1;
            piVar2 = piVar2 + 2;
          } while (uVar5 < local_40);
        }
        local_8 = FUN_0093cdfa(in_ECX[0x16] + 4,uVar4);
        if (local_8 < 0) goto LAB_00907ba0;
        in_ECX[0x17] = in_ECX[0x17] + uVar4;
        in_ECX[0x1a] = in_ECX[0x1a] + uVar4;
        in_ECX[0x19] = in_ECX[0x17];
      }
      else {
        FUN_008bd3f7(*in_ECX,in_ECX + 4,0x7ee,s_debug_info_exceeds_maximum_comme_00a27f1c);
      }
      local_8 = 0;
    }
  }
  else {
    local_10 = operator_new(local_40 << 2);
    if (local_10 != (undefined4 *)0x0) {
      puVar7 = local_10;
      for (uVar4 = local_40; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      local_c = operator_new(local_40 << 3);
      if (local_c != (undefined4 *)0x0) {
        local_1c = local_40 << 3;
        puVar7 = local_c;
        for (iVar3 = (local_40 & 0x1fffffff) << 1; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(undefined1 *)puVar7 = 0;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        if (iVar8 != 0) {
          puVar6 = (undefined2 *)((int)local_c + local_40 * 8 + -6);
          do {
            *puVar6 = 0xffff;
            puVar6[-1] = *(undefined2 *)(iVar8 + 0x24);
            *(undefined4 *)(puVar6 + 1) = *(undefined4 *)(iVar8 + 0x58);
            if (*(int *)(iVar8 + 0x20) != 0) {
              iVar3 = FUN_0093ccb5(*(int *)(iVar8 + 0x20),0xffffffff,7,&local_18);
              if (iVar3 < 0) goto LAB_00907ba0;
              local_14 = 0;
              if (local_48 != 0) {
                do {
                  if (local_10[local_14] == local_18) break;
                  local_14 = local_14 + 1;
                } while (local_14 < local_48);
              }
              if (local_14 == local_48) {
                local_10[local_48] = local_18;
                local_48 = local_48 + 1;
              }
              *puVar6 = (short)local_14;
            }
            iVar8 = *(int *)(iVar8 + 0xc);
            puVar6 = puVar6 + -4;
          } while (iVar8 != 0);
        }
        if (((local_48 != 0) &&
            (local_8 = FUN_0093ccb5(local_10,local_48 << 2,1,local_44), local_8 < 0)) ||
           (local_8 = FUN_0093ccb5(local_c,local_1c,1,local_3c), local_8 < 0)) goto LAB_00907ba0;
        goto LAB_00907a7f;
      }
    }
    local_8 = -0x7ff8fff2;
  }
LAB_00907ba0:
  _free(local_10);
  return;
}


// ==== FUN_00907bc2 @ 0x00907bc2 ====

void FUN_00907bc2(byte param_1)

{
  void *in_ECX;
  
  FUN_0090876e();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00907be3 @ 0x00907be3 ====

void FUN_00907be3(void)

{
  int in_ECX;
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (*(int *)(in_ECX + uVar1 * 4) != 0) {
      FUN_00907bc2(1);
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 7);
  return;
}


// ==== FUN_00907c02 @ 0x00907c02 ====

int FUN_00907c02(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *in_ECX;
  uint uVar4;
  undefined4 *puVar5;
  int *local_8;
  
  local_8 = in_ECX;
  iVar1 = FUN_008eb37d(in_ECX[0x17] << 2,&local_8);
  if (-1 < iVar1) {
    uVar2 = (**(code **)(*local_8 + 0x10))(local_8);
    puVar5 = (undefined4 *)in_ECX[0x16];
    puVar3 = (undefined4 *)(**(code **)(*local_8 + 0xc))(local_8);
    for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar3 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar3 = puVar3 + 1;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar3 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
    *param_1 = local_8;
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_00907c5b @ 0x00907c5b ====

undefined4 FUN_00907c5b(char *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  void *pvVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  char *pcVar8;
  
  iVar2 = FUN_0090605b(param_1);
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar3 = pcVar3 + (1 - (int)(param_1 + 1));
  pcVar4 = operator_new((uint)pcVar3);
  if (pcVar4 != (char *)0x0) {
    pcVar8 = pcVar4;
    for (uVar7 = (uint)pcVar3 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)param_1;
      param_1 = param_1 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar7 = (uint)pcVar3 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar8 = *param_1;
      param_1 = param_1 + 1;
      pcVar8 = pcVar8 + 1;
    }
    pvVar5 = operator_new(0x24);
    if (pvVar5 == (void *)0x0) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_009078b6(pcVar4,param_2,param_3,*(undefined4 *)(in_ECX + iVar2 * 4));
    }
    if (iVar6 != 0) {
      *(int *)(in_ECX + iVar2 * 4) = iVar6;
      return 0;
    }
  }
  return 0x8007000e;
}


// ==== FUN_00907ceb @ 0x00907ceb ====

void FUN_00907ceb(int param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 7;
  puVar3 = in_ECX;
  for (iVar1 = iVar2; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  puVar3 = in_ECX + 7;
  for (iVar1 = iVar2; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  puVar3 = in_ECX + 0xe;
  for (iVar1 = iVar2; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  puVar3 = in_ECX + 0x15;
  for (iVar1 = iVar2; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  puVar3 = in_ECX + 0x1c;
  for (; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x2a] = 0;
  in_ECX[0x2d] = param_1;
  in_ECX[0x2c] = 0;
  if ((3 < param_1) && (param_1 < 6)) {
    in_ECX[0x2c] = 1;
  }
  return;
}


// ==== FUN_00907d7a @ 0x00907d7a ====

void FUN_00907d7a(void)

{
  FUN_00907be3();
  FUN_00907be3();
  FUN_00907be3();
  FUN_00907be3();
  FUN_00907be3();
  return;
}


// ==== FUN_00907da7 @ 0x00907da7 ====

int FUN_00907da7(undefined4 param_1,undefined4 param_2,undefined4 param_3,short *param_4,int param_5
                ,undefined4 *param_6,undefined4 *param_7,uint *param_8)

{
  undefined4 *puVar1;
  short sVar2;
  short *psVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  uint *puVar7;
  char *pcVar8;
  
  puVar1 = param_6;
  psVar3 = param_4;
  psVar4 = param_4;
  do {
    sVar2 = *psVar4;
    psVar4 = (short *)((int)psVar4 + 1);
  } while ((char)sVar2 != '\0');
  if ((uint)((int)psVar4 - (int)((int)param_4 + 1)) < 3) {
    FUN_008bd320(param_1,param_3,0x7d5,s_invalid_register__input__or_cons_00a281d0,param_4);
    return -0x7fffbffb;
  }
  *param_6 = 0;
  *param_7 = 0;
  *param_8 = 0;
  if (*param_4 != DAT_00a27eb8) {
    if (*param_4 == DAT_00a27eb4) {
      *param_6 = 0;
      iVar5 = FUN_0090609c(param_4);
      if (iVar5 == 0) {
        puVar7 = (uint *)(in_ECX + 0xa4);
        *param_8 = *puVar7;
        FUN_00907c5b(psVar3,*puVar7,1);
        *puVar7 = *puVar7 + 1;
      }
      else {
        *param_8 = *(uint *)(iVar5 + 4);
      }
      if (param_5 == 0) {
        return 0;
      }
      pcVar8 = s_addressing_operations_not_allowe_00a280f4;
    }
    else {
      sVar2 = *param_4;
      if ((((sVar2 == DAT_00a280f0) || (sVar2 == DAT_00a280ec)) || (sVar2 == DAT_00a280e8)) ||
         (sVar2 == DAT_00a280e4)) {
        if (*param_4 == DAT_00a280ec) {
          *param_6 = 0xe;
          iVar5 = 0;
        }
        else if (*param_4 == DAT_00a280e8) {
          *param_6 = 7;
          iVar5 = 1;
        }
        else if (*param_4 == DAT_00a280e4) {
          *param_6 = 10;
          iVar5 = 2;
        }
        else {
          *param_6 = 2;
          iVar5 = 3;
        }
        iVar6 = FUN_0090609c(param_4);
        if (iVar6 == 0) {
          iVar6 = FUN_009098df(param_3,psVar3,&param_7);
          if (iVar6 < 0) {
            return iVar6;
          }
          if (param_7 == (undefined4 *)0x0) {
            FUN_008bd320(param_1,param_3,0x7d5,s_constant_register___s__must_be_d_00a27fb0,psVar3,
                         psVar3 + 1);
            return -0x7fffbffb;
          }
          puVar7 = (uint *)(in_ECX + 0x8c + iVar5 * 4);
          *param_8 = *puVar7;
          FUN_00907c5b(psVar3,*puVar7,param_7);
          *puVar7 = *puVar7 + (int)param_7;
          *(int *)(in_ECX + 0xac) = *(int *)(in_ECX + 0xac) + 1;
        }
        else {
          *param_8 = *(uint *)(iVar6 + 4);
          param_7 = *(undefined4 **)(iVar6 + 8);
        }
        if (param_5 == 0) {
          return 0;
        }
        puVar1 = *(undefined4 **)(param_5 + 0x18);
        if (param_7 < puVar1) {
          FUN_008bd320(param_1,param_3,0x7d5,s_constant_register_address_out_of_00a27f60,psVar3,
                       param_7,puVar1);
          return -0x7fffbffb;
        }
        *param_8 = *param_8 + (int)puVar1;
        return 0;
      }
      if ((*(int *)(in_ECX + 0xb0) == 0) || (sVar2 != DAT_00a27eb0)) {
        pcVar8 = s___s__is_not_a_valid_register_nam_00a27ff0;
      }
      else {
        *param_6 = 6;
        iVar5 = FUN_0090609c(param_4);
        if (iVar5 == 0) {
          iVar5 = FUN_00905e05(psVar3 + 1,(int)&param_6 + 3,(int)&param_4 + 3);
          if (iVar5 < 0) {
            pcVar8 = s_Invalid_output_register___s__spe_00a280bc;
            goto LAB_00907e37;
          }
          puVar7 = (uint *)(in_ECX + 0xa0);
          *param_8 = *puVar7;
          FUN_00907c5b(psVar3,*puVar7,1);
          *puVar7 = *puVar7 + 1;
        }
        else {
          *param_8 = *(uint *)(iVar5 + 4);
        }
        if (param_5 == 0) {
          return 0;
        }
        pcVar8 = s_addressing_operations_are_not_al_00a2807c;
      }
    }
    goto LAB_00907e37;
  }
  if ((*(int *)(in_ECX + 0xb4) < 10) || (0xc < *(int *)(in_ECX + 0xb4))) {
    *param_6 = 1;
    iVar5 = FUN_0090609c(param_4);
    if (iVar5 == 0) {
      iVar5 = FUN_00905e05(psVar3 + 1,(int)&param_6 + 3,(int)&param_4 + 3);
      if (iVar5 < 0) goto LAB_00907e31;
      puVar7 = (uint *)(in_ECX + 0x9c);
      *param_8 = *puVar7;
      FUN_00907c5b(psVar3,*puVar7,1);
      *puVar7 = *puVar7 + 1;
    }
    else {
      *param_8 = *(uint *)(iVar5 + 4);
    }
    if (param_5 == 0) {
      return 0;
    }
    pcVar8 = s_addressing_operations_are_not_al_00a28134;
  }
  else {
    iVar5 = FUN_00905e05(param_4 + 1,(int)&param_5 + 3,(int)&param_4 + 3);
    if (-1 < iVar5) {
      if (param_5._3_1_ == '\x05') {
        *puVar1 = 3;
      }
      else {
        if (param_5._3_1_ != '\n') {
          pcVar8 = s_Invalid_pixel_shader_input_regis_00a28174;
          goto LAB_00907e37;
        }
        *puVar1 = 1;
      }
      *param_8 = (uint)param_4 >> 0x18;
      return 0;
    }
LAB_00907e31:
    pcVar8 = s_Invalid_input_register___s__spec_00a281a8;
  }
LAB_00907e37:
  FUN_008bd320(param_1,param_3,0x7d5,pcVar8,psVar3);
  return -0x7fffbffb;
}


// ==== FUN_00907db2 @ 0x00907db2 ====

int FUN_00907db2(void)

{
  char cVar1;
  short sVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  char *in_EAX;
  int iVar7;
  int iVar8;
  int in_ECX;
  short *unaff_EBX;
  int unaff_EBP;
  int *piVar9;
  char *pcVar10;
  
  pcVar10 = in_EAX + 1;
  do {
    cVar1 = *in_EAX;
    in_EAX = in_EAX + 1;
  } while (cVar1 != '\0');
  if ((uint)((int)in_EAX - (int)pcVar10) < 3) {
    FUN_008bd320(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0x10),0x7d5,
                 s_invalid_register__input__or_cons_00a281d0);
    return -0x7fffbffb;
  }
  puVar3 = *(undefined4 **)(unaff_EBP + 0x20);
  puVar4 = *(undefined4 **)(unaff_EBP + 0x1c);
  *puVar4 = 0;
  *puVar3 = 0;
  **(undefined4 **)(unaff_EBP + 0x24) = 0;
  if (*unaff_EBX != DAT_00a27eb8) {
    if (*unaff_EBX == DAT_00a27eb4) {
      *puVar4 = 0;
      iVar7 = FUN_0090609c(unaff_EBX);
      if (iVar7 == 0) {
        piVar9 = (int *)(in_ECX + 0xa4);
        **(int **)(unaff_EBP + 0x24) = *piVar9;
        FUN_00907c5b(unaff_EBX,*piVar9,1);
        *piVar9 = *piVar9 + 1;
      }
      else {
        **(int **)(unaff_EBP + 0x24) = *(int *)(iVar7 + 4);
      }
      if (*(int *)(unaff_EBP + 0x18) == 0) {
        return 0;
      }
      pcVar10 = s_addressing_operations_not_allowe_00a280f4;
    }
    else {
      sVar2 = *unaff_EBX;
      if ((((sVar2 == DAT_00a280f0) || (sVar2 == DAT_00a280ec)) || (sVar2 == DAT_00a280e8)) ||
         (sVar2 == DAT_00a280e4)) {
        if (*unaff_EBX == DAT_00a280ec) {
          *puVar4 = 0xe;
          iVar7 = 0;
        }
        else if (*unaff_EBX == DAT_00a280e8) {
          *puVar4 = 7;
          iVar7 = 1;
        }
        else if (*unaff_EBX == DAT_00a280e4) {
          *puVar4 = 10;
          iVar7 = 2;
        }
        else {
          *puVar4 = 2;
          iVar7 = 3;
        }
        iVar8 = FUN_0090609c(unaff_EBX);
        if (iVar8 == 0) {
          iVar8 = FUN_009098df(*(undefined4 *)(unaff_EBP + 0x10),unaff_EBX,unaff_EBP + 0x20);
          if (iVar8 < 0) {
            return iVar8;
          }
          if (*(int *)(unaff_EBP + 0x20) == 0) {
            FUN_008bd320(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0x10),0x7d5,
                         s_constant_register___s__must_be_d_00a27fb0);
            return -0x7fffbffb;
          }
          uVar5 = *(undefined4 *)(unaff_EBP + 0x20);
          piVar9 = (int *)(in_ECX + 0x8c + iVar7 * 4);
          **(int **)(unaff_EBP + 0x24) = *piVar9;
          FUN_00907c5b(unaff_EBX,*piVar9,uVar5);
          *piVar9 = *piVar9 + *(int *)(unaff_EBP + 0x20);
          *(int *)(in_ECX + 0xac) = *(int *)(in_ECX + 0xac) + 1;
          piVar9 = *(int **)(unaff_EBP + 0x24);
        }
        else {
          piVar9 = *(int **)(unaff_EBP + 0x24);
          *piVar9 = *(int *)(iVar8 + 4);
          *(undefined4 *)(unaff_EBP + 0x20) = *(undefined4 *)(iVar8 + 8);
        }
        if (*(int *)(unaff_EBP + 0x18) == 0) {
          return 0;
        }
        uVar6 = *(uint *)(*(int *)(unaff_EBP + 0x18) + 0x18);
        if (*(uint *)(unaff_EBP + 0x20) < uVar6) {
          FUN_008bd320(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0x10),0x7d5,
                       s_constant_register_address_out_of_00a27f60);
          return -0x7fffbffb;
        }
        *piVar9 = *piVar9 + uVar6;
        return 0;
      }
      if ((*(int *)(in_ECX + 0xb0) == 0) || (sVar2 != DAT_00a27eb0)) {
        pcVar10 = s___s__is_not_a_valid_register_nam_00a27ff0;
      }
      else {
        *puVar4 = 6;
        iVar7 = FUN_0090609c(unaff_EBX);
        if (iVar7 == 0) {
          iVar7 = FUN_00905e05(unaff_EBX + 1,unaff_EBP + 0x1f,unaff_EBP + 0x17);
          if (iVar7 < 0) {
            pcVar10 = s_Invalid_output_register___s__spe_00a280bc;
            goto LAB_00907e37;
          }
          piVar9 = (int *)(in_ECX + 0xa0);
          **(int **)(unaff_EBP + 0x24) = *piVar9;
          FUN_00907c5b(unaff_EBX,*piVar9,1);
          *piVar9 = *piVar9 + 1;
        }
        else {
          **(undefined4 **)(unaff_EBP + 0x24) = *(undefined4 *)(iVar7 + 4);
        }
        if (*(int *)(unaff_EBP + 0x18) == 0) {
          return 0;
        }
        pcVar10 = s_addressing_operations_are_not_al_00a2807c;
      }
    }
    goto LAB_00907e37;
  }
  if ((*(int *)(in_ECX + 0xb4) < 10) || (0xc < *(int *)(in_ECX + 0xb4))) {
    *puVar4 = 1;
    iVar7 = FUN_0090609c(unaff_EBX);
    if (iVar7 == 0) {
      iVar7 = FUN_00905e05(unaff_EBX + 1,unaff_EBP + 0x1f,unaff_EBP + 0x17);
      if (iVar7 < 0) goto LAB_00907e31;
      piVar9 = (int *)(in_ECX + 0x9c);
      **(int **)(unaff_EBP + 0x24) = *piVar9;
      FUN_00907c5b(unaff_EBX,*piVar9,1);
      *piVar9 = *piVar9 + 1;
    }
    else {
      **(undefined4 **)(unaff_EBP + 0x24) = *(undefined4 *)(iVar7 + 4);
    }
    if (*(int *)(unaff_EBP + 0x18) == 0) {
      return 0;
    }
    pcVar10 = s_addressing_operations_are_not_al_00a28134;
  }
  else {
    iVar7 = FUN_00905e05(unaff_EBX + 1,unaff_EBP + 0x1b,unaff_EBP + 0x17);
    if (-1 < iVar7) {
      if (*(char *)(unaff_EBP + 0x1b) == '\x05') {
        *puVar4 = 3;
      }
      else {
        if (*(char *)(unaff_EBP + 0x1b) != '\n') {
          pcVar10 = s_Invalid_pixel_shader_input_regis_00a28174;
          goto LAB_00907e37;
        }
        *puVar4 = 1;
      }
      **(uint **)(unaff_EBP + 0x24) = (uint)*(byte *)(unaff_EBP + 0x17);
      return 0;
    }
LAB_00907e31:
    pcVar10 = s_Invalid_input_register___s__spec_00a281a8;
  }
LAB_00907e37:
  FUN_008bd320(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0x10),0x7d5,pcVar10);
  return -0x7fffbffb;
}


// ==== FUN_00908119 @ 0x00908119 ====

void FUN_00908119(byte param_1)

{
  void *in_ECX;
  
  FUN_00907d7a();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00908218 @ 0x00908218 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_00908218(int param_1,int param_2)

{
  byte *pbVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  undefined4 *in_ECX;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  int iVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  char *pcVar14;
  undefined4 local_40;
  byte *local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 *local_28;
  int local_24;
  int local_20;
  uint local_1c;
  byte local_18 [16];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  pbVar1 = *(byte **)(param_1 + 8);
  bVar3 = *pbVar1;
  local_20 = 0;
  local_1c = 0;
  local_30 = 0;
  local_40 = 0;
  bVar11 = true;
  bVar2 = false;
  bVar13 = false;
  pbVar9 = pbVar1;
  pbVar8 = pbVar1;
  local_34 = pbVar1;
  local_2c = param_1;
  while( true ) {
    pbVar7 = pbVar9;
    local_24 = param_2;
    if (bVar3 == 0) break;
    while ((*pbVar7 != 0 && (*pbVar7 != 0x5f))) {
      pbVar7 = pbVar7 + 1;
      local_34 = pbVar7;
    }
    uVar4 = (int)pbVar7 - (int)pbVar8;
    if (0xf < uVar4) goto LAB_009085fb;
    pbVar9 = local_18;
    for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pbVar9 = *(undefined4 *)pbVar8;
      pbVar8 = pbVar8 + 4;
      pbVar9 = pbVar9 + 4;
    }
    iVar5 = 3;
    bVar3 = *pbVar7;
    for (uVar6 = uVar4 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pbVar9 = *pbVar8;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    }
    local_18[uVar4] = 0;
    if (bVar3 != 0) {
      pbVar7 = pbVar7 + 1;
      local_34 = pbVar7;
    }
    iVar10 = 0;
    local_28 = in_ECX;
    if (bVar11) {
      pbVar8 = local_18;
      if (local_18[0] == 0) {
LAB_0090832e:
        local_1c = 0xffffffff;
      }
      else {
        do {
          iVar5 = _isalpha((int)(char)*pbVar8);
          if (iVar5 == 0) break;
          pbVar8 = pbVar8 + 1;
        } while (*pbVar8 != 0);
        if (*pbVar8 == 0) goto LAB_0090832e;
        local_1c = _atol((char *)pbVar8);
      }
      if (*pbVar8 != 0) {
        *pbVar8 = 0;
        pbVar8 = pbVar8 + 1;
      }
      bVar3 = *pbVar8;
      if (bVar3 != 0) {
        do {
          iVar5 = _isdigit((int)(char)bVar3);
          if (iVar5 == 0) break;
          pbVar8 = pbVar8 + 1;
          bVar3 = *pbVar8;
        } while (bVar3 != 0);
        in_ECX = local_28;
        if (*pbVar8 != 0) goto LAB_009085fb;
      }
      uVar4 = 0;
      do {
        pbVar9 = *(byte **)((int)&PTR_DAT_00a271c0 + uVar4);
        pbVar8 = local_18;
        do {
          bVar3 = *pbVar8;
          bVar11 = bVar3 < *pbVar9;
          if (bVar3 != *pbVar9) {
LAB_0090838c:
            iVar5 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
            goto LAB_00908391;
          }
          if (bVar3 == 0) break;
          bVar3 = pbVar8[1];
          bVar11 = bVar3 < pbVar9[1];
          if (bVar3 != pbVar9[1]) goto LAB_0090838c;
          pbVar8 = pbVar8 + 2;
          pbVar9 = pbVar9 + 2;
        } while (bVar3 != 0);
        iVar5 = 0;
LAB_00908391:
        if (iVar5 == 0) break;
        uVar4 = uVar4 + 0x48;
        iVar10 = iVar10 + 1;
      } while (uVar4 < 0x5e8);
      in_ECX = local_28;
      if (iVar10 != 0x15) {
        iVar5 = local_28[0xe];
        uVar4 = *(uint *)(&DAT_00a271c8 + (iVar5 + iVar10 * 0x12) * 4);
        if (uVar4 != 0xffffffff) {
          if ((int)uVar4 < 0) {
            if (local_1c == 0xffffffff) {
              if (local_24 == 0) goto LAB_009085fb;
              local_1c = *(uint *)(local_24 + 0x18);
            }
            else if (local_24 != 0) {
              local_1c = local_1c + *(int *)(local_24 + 0x18);
            }
            uVar4 = -uVar4;
          }
          else if (local_24 != 0) goto LAB_009085fb;
          if (local_1c == 0xffffffff) {
            if (uVar4 == 0) {
              local_1c = 0;
              goto LAB_00908421;
            }
          }
          else if (((local_24 != 0) && (*(int *)(local_24 + 0x28) != 0)) || (local_1c < uVar4)) {
LAB_00908421:
            local_20 = (&DAT_00a271c4)[iVar10 * 0x12];
            local_40 = (&DAT_00a27204)[iVar10 * 0x12];
            if (local_20 == 2) {
              uVar4 = local_1c & 0x1fff;
              if (uVar4 < 0x800) {
                local_20 = 2;
              }
              else if (uVar4 < 0x1000) {
                local_20 = 0xb;
              }
              else if (uVar4 < 0x1800) {
                local_20 = 0xc;
              }
              else if (uVar4 < 0x2000) {
                local_20 = 0xd;
              }
              local_1c = local_1c & 0x7ff;
            }
            else if (local_20 == -3) {
              local_20 = 4;
LAB_0090849b:
              local_1c = 0;
            }
            else if (local_20 == -4) {
              local_20 = 4;
              local_1c = 2;
            }
            else {
              if (local_20 == -5) {
                local_20 = 4;
              }
              else {
                if (local_20 == -6) {
                  local_20 = 0x11;
                  goto LAB_0090849b;
                }
                if (local_20 != -7) goto LAB_009084e1;
                local_20 = 0x11;
              }
              local_1c = 1;
            }
LAB_009084e1:
            bVar11 = false;
            if ((5 < iVar5) && (iVar5 < 10)) {
              bVar2 = true;
            }
            if (((3 < iVar5) && (iVar5 < 6)) || ((0xc < iVar5 && (iVar5 < 0xf)))) {
              bVar13 = true;
            }
            pbVar9 = local_34;
            goto LAB_00908514;
          }
        }
      }
LAB_009085fb:
      iVar5 = local_24;
      if (in_ECX[0x1e] != 0) {
        iVar10 = FUN_00907da7(*in_ECX,in_ECX[0x1f],local_2c,pbVar1,local_24,&local_20,&local_30,
                              &local_1c);
        if (-1 < iVar10) {
          iVar10 = FUN_008bf738(0x2c);
          if (iVar10 == 0) {
            iVar10 = 0;
          }
          else {
            iVar10 = FUN_0093cfac(local_20,local_30,local_1c,local_40,0);
          }
          if (iVar10 == 0) {
            return 0;
          }
          if (iVar5 == 0) {
            return iVar10;
          }
          *(undefined4 *)(iVar10 + 0x28) = *(undefined4 *)(iVar5 + 0x28);
          *(undefined4 *)(iVar5 + 0x28) = 0;
          return iVar10;
        }
        goto LAB_00908704;
      }
      if (local_24 == 0) {
        pcVar14 = s_invalid_register___s__00a28258;
      }
      else {
        if (*(int *)(local_24 + 0x28) == 0) {
          FUN_008bd320(*in_ECX,local_2c,0x7d5,s_invalid_register___s__u___00a2828c,pbVar1,
                       *(undefined4 *)(local_24 + 0x18));
          goto LAB_00908704;
        }
        if (*(int *)(*(int *)(local_24 + 0x28) + 0x10) == -1) goto LAB_00908704;
        pcVar14 = s_invalid_register___s_______00a28270;
      }
      FUN_008bd320(*in_ECX,local_2c,0x7d5,pcVar14,pbVar1);
      goto LAB_00908704;
    }
    if (!bVar2) {
LAB_009085c9:
      if (bVar13) {
        iVar5 = 4;
        bVar13 = true;
        pbVar8 = local_18;
        pbVar9 = &DAT_009fd220;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar13 = *pbVar8 == *pbVar9;
          pbVar8 = pbVar8 + 1;
          pbVar9 = pbVar9 + 1;
        } while (bVar13);
        if (bVar13) {
          bVar13 = false;
          local_30 = 0xb000000;
          goto LAB_009085ea;
        }
      }
      goto LAB_009085fb;
    }
    iVar10 = 5;
    bVar12 = true;
    pbVar8 = local_18;
    pbVar9 = &DAT_00a282bc;
    do {
      if (iVar10 == 0) break;
      iVar10 = iVar10 + -1;
      bVar12 = *pbVar8 == *pbVar9;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    } while (bVar12);
    if (bVar12) {
      local_30 = 0x2000000;
    }
    else {
      iVar10 = 4;
      bVar12 = true;
      pbVar8 = local_18;
      pbVar9 = &DAT_00a282b8;
      do {
        if (iVar10 == 0) break;
        iVar10 = iVar10 + -1;
        bVar12 = *pbVar8 == *pbVar9;
        pbVar8 = pbVar8 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar12);
      if (bVar12) {
        local_30 = 0x4000000;
      }
      else {
        bVar12 = true;
        iVar10 = iVar5;
        pbVar8 = local_18;
        pbVar9 = &DAT_00a27b94;
        do {
          if (iVar10 == 0) break;
          iVar10 = iVar10 + -1;
          bVar12 = *pbVar8 == *pbVar9;
          pbVar8 = pbVar8 + 1;
          pbVar9 = pbVar9 + 1;
        } while (bVar12);
        if (bVar12) {
          local_30 = 0x7000000;
        }
        else {
          bVar12 = true;
          iVar10 = iVar5;
          pbVar8 = local_18;
          pbVar9 = &DAT_00a282b4;
          do {
            if (iVar10 == 0) break;
            iVar10 = iVar10 + -1;
            bVar12 = *pbVar8 == *pbVar9;
            pbVar8 = pbVar8 + 1;
            pbVar9 = pbVar9 + 1;
          } while (bVar12);
          if (!bVar12) {
            bVar12 = true;
            iVar10 = iVar5;
            pbVar8 = local_18;
            pbVar9 = &DAT_00a282b0;
            do {
              if (iVar10 == 0) break;
              iVar10 = iVar10 + -1;
              bVar12 = *pbVar8 == *pbVar9;
              pbVar8 = pbVar8 + 1;
              pbVar9 = pbVar9 + 1;
            } while (bVar12);
            if (!bVar12) {
              bVar12 = true;
              iVar10 = iVar5;
              pbVar8 = local_18;
              pbVar9 = &DAT_00a282ac;
              do {
                if (iVar10 == 0) break;
                iVar10 = iVar10 + -1;
                bVar12 = *pbVar8 == *pbVar9;
                pbVar8 = pbVar8 + 1;
                pbVar9 = pbVar9 + 1;
              } while (bVar12);
              if (!bVar12) {
                bVar12 = true;
                pbVar8 = local_18;
                pbVar9 = &DAT_00a282a8;
                do {
                  if (iVar5 == 0) break;
                  iVar5 = iVar5 + -1;
                  bVar12 = *pbVar8 == *pbVar9;
                  pbVar8 = pbVar8 + 1;
                  pbVar9 = pbVar9 + 1;
                } while (bVar12);
                if (!bVar12) goto LAB_009085c9;
              }
              local_30 = 0xa000000;
              goto LAB_009085c0;
            }
          }
          local_30 = 0x9000000;
        }
      }
    }
LAB_009085c0:
    bVar2 = false;
LAB_009085ea:
    pbVar9 = pbVar7;
LAB_00908514:
    bVar3 = *pbVar9;
    pbVar8 = pbVar7;
    in_ECX = local_28;
    param_2 = local_24;
  }
  if (in_ECX[0x1e] == 0) {
LAB_0090872b:
    iVar5 = FUN_008bf738(0x2c);
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_0093cfac(local_20,local_30,local_1c,local_40,0);
    }
    if (iVar5 != 0) {
      if (param_2 == 0) {
        return iVar5;
      }
      *(undefined4 *)(iVar5 + 0x28) = *(undefined4 *)(param_2 + 0x28);
      *(undefined4 *)(param_2 + 0x28) = 0;
      return iVar5;
    }
  }
  else {
    if (*(int *)(in_ECX[0x1e] + 0xb0) == 0) {
      if ((((((local_20 == 3) || (local_20 == 5)) || (local_20 == 6)) ||
           ((local_20 == 8 || (local_20 == 9)))) ||
          ((local_20 == 4 || ((local_20 == 0xf || (local_20 == 0x12)))))) || (local_20 == 0x13))
      goto LAB_0090872b;
      pcVar14 = s_temporary_and_constant_registers_00a28210;
    }
    else {
      if ((((local_20 == 3) || (local_20 == 0xf)) || (local_20 == 0x12)) || (local_20 == 0x13))
      goto LAB_0090872b;
      pcVar14 = s_temporary__constant__and_output_r_00a282c8;
    }
    FUN_008bd320(*in_ECX,local_2c,0x7d5,pcVar14);
LAB_00908704:
    in_ECX[0x13] = 1;
    iVar5 = FUN_008bf738(0x2c);
    if (iVar5 != 0) {
      iVar5 = FUN_0093cfac(0xffffffff,0,0,0,0);
      return iVar5;
    }
  }
  return 0;
}


// ==== FUN_0090876e @ 0x0090876e ====

void FUN_0090876e(void)

{
  undefined4 *in_ECX;
  
  _free((void *)*in_ECX);
  return;
}


// ==== FUN_0090878b @ 0x0090878b ====

void FUN_0090878b(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  _free(*(void **)(in_ECX + 0x58));
  return;
}


// ==== FUN_009087ba @ 0x009087ba ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009087ba(undefined4 param_1,uint param_2)

{
  double dVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *in_ECX;
  uint uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined4 *local_44 [16];
  
  puVar8 = local_44[1];
  puVar3 = local_44[0];
  uVar6 = param_2;
  if (in_ECX[0x14] != 0) {
    return;
  }
  while( true ) {
    local_44[0] = puVar3;
    local_44[1] = puVar8;
    if (uVar6 == 0) break;
    iVar5 = in_ECX[0xd];
    if (iVar5 == 0) {
      FUN_008bd320(*in_ECX,in_ECX + 4,0,s_internal_error__stack_underflow_00a17c54);
      in_ECX[0x13] = 1;
      return;
    }
    local_44[uVar6 - 1] = *(undefined4 **)(iVar5 + 8);
    in_ECX[0xd] = *(undefined4 *)(iVar5 + 0xc);
    *(undefined4 *)(iVar5 + 8) = 0;
    *(undefined4 *)(iVar5 + 0xc) = 0;
    puVar8 = local_44[1];
    puVar3 = local_44[0];
    uVar6 = uVar6 - 1;
  }
  puVar4 = (undefined4 *)0x0;
  puVar2 = in_ECX;
  switch(param_1) {
  case 0:
  case 6:
    puVar4 = (undefined4 *)0x0;
    break;
  case 1:
  case 2:
  case 4:
  case 5:
  case 10:
  case 0x17:
  case 0x19:
  case 0x1d:
  case 0x23:
  case 0x29:
  case 0x2a:
  case 0x2f:
  case 0x30:
    puVar4 = puVar3;
    break;
  case 3:
    puVar4 = (undefined4 *)FUN_008f3545(puVar8,puVar3);
    break;
  case 7:
    puVar4 = (undefined4 *)0x0;
    if (in_ECX[0x1d] == 0) {
      in_ECX[0x1d] = puVar3[6];
    }
    break;
  case 8:
    goto LAB_0090888c;
  case 9:
    if (((int)in_ECX[0xe] < 6) || (9 < (int)in_ECX[0xe])) {
      pcVar9 = s_instruction_coissue_is_not_suppo_00a284d8;
      uVar7 = 0x7eb;
      puVar4 = puVar3;
      puVar2 = puVar3;
      goto LAB_00908a66;
    }
    puVar3[0x15] = 1;
LAB_0090888c:
    FUN_00906e01(puVar3);
    puVar4 = puVar3;
    break;
  case 0xb:
    iVar5 = in_ECX[0xe];
    if (((1 < iVar5) && (iVar5 < 6)) || ((10 < iVar5 && (iVar5 < 0xf)))) {
      puVar8[0x10] = puVar3;
      puVar4 = puVar8;
      break;
    }
    pcVar9 = s_instruction_predication_is_not_s_00a28498;
    uVar7 = 0x7ec;
    puVar4 = puVar8;
    puVar2 = puVar8;
    goto LAB_00908a66;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
    local_44[0] = (undefined4 *)0x0;
    if (1 < param_2) {
      local_44[1] = (undefined4 *)0x0;
      puVar3[0xf] = puVar8;
    }
    uVar6 = 2;
    puVar4 = puVar3;
    if (2 < param_2) {
      puVar8 = puVar3 + 0x11;
      do {
        puVar2 = local_44[uVar6];
        local_44[uVar6] = (undefined4 *)0x0;
        *puVar8 = puVar2;
        uVar6 = uVar6 + 1;
        puVar8 = puVar8 + 1;
      } while (uVar6 < param_2);
    }
    break;
  case 0x15:
  case 0x16:
    local_44[0] = (undefined4 *)0x0;
    uVar6 = 1;
    puVar4 = puVar3;
    if (1 < param_2) {
      puVar8 = puVar3 + 0x11;
      do {
        puVar2 = local_44[uVar6];
        local_44[uVar6] = (undefined4 *)0x0;
        *puVar8 = puVar2;
        uVar6 = uVar6 + 1;
        puVar8 = puVar8 + 1;
      } while (uVar6 < param_2);
    }
    break;
  case 0x18:
    if (puVar3[7] == 0) {
      uVar7 = FUN_00906b81(puVar8 + 4);
      puVar3[8] = uVar7;
      puVar4 = puVar3;
    }
    else {
      FUN_008bd320(*in_ECX,in_ECX + 4,0x7e6,s_scalar_registers_cannot_be_maske_00a28470);
      in_ECX[0x13] = 1;
      puVar3[8] = 0xf0000;
      puVar4 = puVar3;
    }
    break;
  case 0x1a:
    if (puVar3[5] == 0) {
      puVar3[5] = 0xd000000;
      puVar4 = puVar3;
      break;
    }
    pcVar9 = s_not_cannot_be_used_with_other_mo_00a28448;
    uVar7 = 0x7e2;
    puVar4 = puVar3;
    goto LAB_00908a66;
  case 0x1b:
    iVar5 = puVar3[5];
    if (iVar5 == 0) {
      puVar3[5] = 0x1000000;
      puVar4 = puVar3;
      break;
    }
    if (iVar5 == 0x2000000) {
      puVar3[5] = 0x3000000;
      puVar4 = puVar3;
      break;
    }
    if (iVar5 == 0x4000000) {
      puVar3[5] = 0x5000000;
      puVar4 = puVar3;
      break;
    }
    if (iVar5 == 0x7000000) {
      puVar3[5] = 0x8000000;
      puVar4 = puVar3;
      break;
    }
    if ((iVar5 != 0x9000000) && (iVar5 != 0xa000000)) {
      puVar4 = puVar3;
      if (iVar5 == 0xb000000) {
        puVar3[5] = 0xc000000;
      }
      break;
    }
    pcVar9 = s_negate_and_divide_modifiers_cann_00a28418;
    uVar7 = 0x7db;
    puVar4 = puVar3;
    goto LAB_00908a66;
  case 0x1c:
    if (puVar3[6] == 1) {
      if (((int)in_ECX[0xe] < 6) || (9 < (int)in_ECX[0xe])) {
        pcVar9 = s_complement_is_not_supported_in_t_00a28394;
        uVar7 = 0x7ed;
        puVar4 = puVar8;
      }
      else {
        if (puVar8[5] == 0) {
          puVar8[5] = 0x6000000;
          puVar4 = puVar8;
          break;
        }
        pcVar9 = s_complement_cannot_be_used_with_o_00a283c8;
        uVar7 = 0x7dc;
        puVar4 = puVar8;
      }
    }
    else {
      pcVar9 = s_invalid_complement_expression_00a283f8;
      uVar7 = 0x7da;
      puVar4 = puVar8;
    }
    goto LAB_00908a66;
  case 0x1e:
    if (puVar3[7] == 0) {
      uVar7 = FUN_00906c36(puVar8 + 4);
      puVar3[9] = uVar7;
      puVar4 = puVar3;
    }
    else {
      FUN_008bd320(*in_ECX,in_ECX + 4,0x7e6,s_scalar_registers_cannot_be_swizz_00a28370);
      in_ECX[0x13] = 1;
      puVar3[9] = 0xe40000;
      puVar4 = puVar3;
    }
    break;
  case 0x21:
    puVar8 = (undefined4 *)0x0;
    goto LAB_00908adc;
  case 0x22:
LAB_00908adc:
    puVar4 = (undefined4 *)FUN_00908218(puVar3 + 4,puVar8);
    goto LAB_00908c60;
  case 0x24:
    puVar3[6] = puVar3[6] + puVar8[6];
    if (puVar3[10] == 0) {
      puVar3[10] = puVar8[10];
      puVar8[10] = 0;
      puVar4 = puVar3;
      break;
    }
    puVar4 = puVar3;
    if (puVar8[10] == 0) break;
    pcVar9 = s_only_one_address_register_refere_00a28320;
    uVar7 = 0x7d9;
LAB_00908a66:
    FUN_008bd320(*in_ECX,puVar2 + 4,uVar7,pcVar9);
    in_ECX[0x13] = 1;
    break;
  case 0x25:
    iVar5 = FUN_008bf738(0x2c);
    puVar4 = (undefined4 *)0x0;
    if (iVar5 != 0) {
      uVar7 = 0;
      puVar8 = local_44[0];
LAB_00908b43:
      puVar4 = (undefined4 *)FUN_0093cfac(0,0,uVar7,0,puVar8);
    }
    goto LAB_00908c60;
  case 0x26:
    iVar5 = FUN_008bf738(0x2c);
    puVar4 = (undefined4 *)0x0;
    if (iVar5 != 0) {
      uVar7 = local_44[0][6];
      puVar8 = (undefined4 *)0x0;
      goto LAB_00908b43;
    }
    goto LAB_00908c60;
  case 0x27:
    iVar5 = FUN_008bf738(0x30);
    if (iVar5 == 0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = (undefined4 *)FUN_008f378b(in_ECX + 4);
    }
    FUN_00906256(puVar4);
    puVar4[4] = 2;
    puVar4[6] = 1;
    break;
  case 0x28:
    iVar5 = FUN_008bf738(0x30);
    if (iVar5 == 0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = (undefined4 *)FUN_008f378b(in_ECX + 4);
    }
    FUN_00906256(puVar4);
    puVar4[6] = 0;
    puVar4[4] = 2;
    break;
  case 0x2b:
    puVar3[6] = -puVar3[6];
    puVar4 = puVar3;
    break;
  case 0x2c:
  case 0x2d:
    dVar1 = (double)(int)puVar3[6];
    puVar3[4] = 5;
    if ((int)puVar3[6] < 0) {
      dVar1 = dVar1 + _DAT_009c2f50;
    }
    goto LAB_00908bf8;
  case 0x2e:
    dVar1 = (double)(int)puVar3[6];
    puVar3[4] = 5;
    if ((int)puVar3[6] < 0) {
      dVar1 = dVar1 + _DAT_009c2f50;
    }
    goto LAB_00908c1f;
  case 0x31:
    dVar1 = *(double *)(puVar3 + 6);
LAB_00908c1f:
    dVar1 = -dVar1;
LAB_00908bf8:
    *(double *)(puVar3 + 6) = dVar1;
    puVar4 = puVar3;
    break;
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
    iVar5 = FUN_008bf738(0x60);
    if (iVar5 == 0) {
LAB_00908c5e:
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = (undefined4 *)FUN_0093cf25(in_ECX + 4,in_ECX[0x10],in_ECX[0x11],in_ECX[0x12]);
    }
    goto LAB_00908c60;
  case 0x3d:
  case 0x3e:
  case 0x3f:
    iVar5 = FUN_008bf738(0x30);
    if (iVar5 == 0) goto LAB_00908c5e;
    puVar4 = (undefined4 *)FUN_008f378b(in_ECX + 4);
LAB_00908c60:
    FUN_00906256(puVar4);
  }
  if (in_ECX[0x14] == 0) {
    iVar5 = FUN_008bf738(0x14);
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_008f3584(puVar4,in_ECX[0xd],s_Stack_00a17c20);
    }
    if (iVar5 == 0) {
      FUN_008bd320(*in_ECX,in_ECX + 4,0,s_internal_error__out_of_memory_00a17c00);
      in_ECX[0x14] = 1;
      in_ECX[0x13] = 1;
    }
    else {
      in_ECX[0xd] = iVar5;
    }
  }
  return;
}


// ==== FUN_0090934e @ 0x0090934e ====

undefined4 FUN_0090934e(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 extraout_EAX;
  int in_ECX;
  
  if (((param_2 & 0xffffff3c) == 0) && (param_4 != (undefined4 *)0x0)) {
    *param_4 = 0;
    _free(*(void **)(in_ECX + 0x58));
    return extraout_EAX;
  }
  return 0x8876086c;
}


// ==== FUN_00909806 @ 0x00909806 ====

void FUN_00909806(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  return;
}


// ==== FUN_0090981c @ 0x0090981c ====

int FUN_0090981c(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = param_2;
  iVar1 = param_1;
  piVar4 = param_3;
  if (param_3 == (int *)0x0) {
    piVar4 = &param_1;
  }
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 == 9) {
    iVar2 = *(int *)(param_1 + 0x10);
    iVar1 = 1;
    piVar5 = piVar4;
    if ((iVar2 == 1) || (iVar2 == 0)) {
      *param_2 = 1;
      iVar1 = *(int *)(param_1 + 0x1c);
    }
    else if (iVar2 == 2) {
      *param_2 = *(int *)(param_1 + 0x1c);
      iVar1 = *(int *)(param_1 + 0x18);
    }
    else {
      if (iVar2 != 3) {
        return -0x7fffbffb;
      }
      *param_2 = 1;
    }
  }
  else {
    if (iVar2 != 8) {
      if (iVar2 != 1) {
        return -0x7fffbffb;
      }
      *param_2 = 0;
      *piVar4 = 0;
      do {
        iVar2 = FUN_0090981c(*(undefined4 *)(*(int *)(*(int *)(iVar1 + 8) + 0x18) + 0x20),&param_3,
                             &param_2);
        if (iVar2 < 0) {
          return iVar2;
        }
        *piVar5 = *piVar5 + (int)param_3;
        piVar3 = (int *)*piVar4;
        if ((int *)*piVar4 < param_2) {
          piVar3 = param_2;
        }
        *piVar4 = (int)piVar3;
        iVar1 = *(int *)(iVar1 + 0xc);
      } while (iVar1 != 0);
      return 0;
    }
    iVar2 = FUN_0090981c(*(undefined4 *)(param_1 + 0x10),param_2,piVar4);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar1 = *(int *)(iVar1 + 0x14) * *piVar5;
  }
  *piVar5 = iVar1;
  return 0;
}


// ==== FUN_009098df @ 0x009098df ====

int FUN_009098df(undefined4 *param_1,short *param_2,undefined4 *param_3)

{
  short *psVar1;
  int *in_ECX;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  short **ppsVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  char *pcVar8;
  short *local_24 [8];
  
  psVar1 = param_2;
  puVar4 = param_1;
  ppsVar5 = local_24;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppsVar5 = (short *)*puVar4;
    puVar4 = puVar4 + 1;
    ppsVar5 = ppsVar5 + 1;
  }
  local_24[2] = param_2 + 1;
  local_24[0] = (short *)0xa;
  iVar2 = FUN_008ce5ff(1,local_24,0,0,in_ECX[1],2,&param_2,0);
  if (iVar2 == 0) {
    uVar6 = FUN_0090981c(*(undefined4 *)(param_2 + 0x10),param_3,0);
    piVar3 = (int *)((ulonglong)uVar6 >> 0x20);
    if ((int)uVar6 < 0) {
      return (int)uVar6;
    }
    if (*psVar1 == DAT_00a280ec) {
      if (((*piVar3 != 1) || (iVar2 = *(int *)(param_2 + 0x10), *(int *)(iVar2 + 4) != 9)) ||
         ((*(int *)(iVar2 + 0x10) != 0 || (*(int *)(iVar2 + 0x14) != 0)))) {
        pcVar8 = s_boolean_constant_register___s__m_00a28630;
        uVar7 = 0xb54;
LAB_009099bc:
        FUN_008bd320(*(int *)(*in_ECX + 4) + 0x18,param_1,uVar7,pcVar8,psVar1);
        return -0x7fffbffb;
      }
    }
    else if ((*psVar1 == DAT_00a280e8) &&
            ((((*piVar3 != 1 || (iVar2 = *(int *)(param_2 + 0x10), *(int *)(iVar2 + 4) != 9)) ||
              (*(int *)(iVar2 + 0x10) != 1)) ||
             ((*(int *)(iVar2 + 0x14) != 4 || (*(uint *)(iVar2 + 0x1c) < 3)))))) {
      pcVar8 = s_integer_constant_register___s__m_00a285d8;
      uVar7 = 0xb55;
      goto LAB_009099bc;
    }
  }
  else {
    *param_3 = 0;
  }
  return 0;
}


// ==== FUN_009099da @ 0x009099da ====

undefined4
FUN_009099da(undefined4 param_1,float *param_2,int param_3,uint param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 extraout_EAX;
  int iVar2;
  float *pfVar3;
  uint uVar4;
  int iVar5;
  float *local_8;
  
  local_8 = (float *)0x0;
  if (*(int *)(param_4 + 4) != 0xd) {
    return 0;
  }
  iVar5 = *(int *)(param_4 + 0x20);
  if (*(int *)(iVar5 + 4) == 1) {
    uVar4 = (int)param_2 << 4;
    local_8 = operator_new(uVar4);
    if (local_8 != (float *)0x0) {
      pfVar3 = local_8;
      for (iVar2 = ((uint)param_2 & 0xfffffff) << 2; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pfVar3 = 0.0;
        pfVar3 = pfVar3 + 1;
      }
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined1 *)pfVar3 = 0;
        pfVar3 = (float *)((int)pfVar3 + 1);
      }
      if (param_2 != (float *)0x0) {
        param_4 = (uint)param_2;
        param_2 = local_8;
        do {
          if (param_3 != 0) {
            pfVar3 = param_2;
            iVar2 = param_3;
            do {
              iVar1 = *(int *)(iVar5 + 8);
              if (*(int *)(iVar1 + 0x10) == 3) {
                *pfVar3 = (float)*(double *)(iVar1 + 0x18);
              }
              else {
                *pfVar3 = *(float *)(iVar1 + 0x18);
              }
              iVar5 = *(int *)(iVar5 + 0xc);
              pfVar3 = pfVar3 + 1;
              iVar2 = iVar2 + -1;
            } while (iVar2 != 0);
          }
          param_2 = param_2 + 4;
          param_4 = param_4 - 1;
        } while (param_4 != 0);
      }
      FUN_0093ccb5(local_8,uVar4,6,param_5);
    }
  }
  _free(local_8);
  return extraout_EAX;
}


// ==== FUN_00909a9d @ 0x00909a9d ====

void FUN_00909a9d(undefined4 param_1,uint param_2,undefined4 param_3)

{
  undefined4 *_Memory;
  int iVar1;
  undefined4 *puVar2;
  
  _Memory = operator_new(param_2 << 4);
  if (_Memory != (undefined4 *)0x0) {
    puVar2 = _Memory;
    for (iVar1 = (param_2 & 0xfffffff) << 2; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined1 *)puVar2 = 0;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
    FUN_0093ccb5(_Memory,param_2 << 4,6,param_3);
  }
  _free(_Memory);
  return;
}


// ==== FUN_00909af4 @ 0x00909af4 ====

int FUN_00909af4(undefined4 param_1,char *param_2,short *param_3,undefined2 param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *in_ECX;
  int iVar4;
  char *pcVar5;
  undefined4 local_60 [2];
  short *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined2 local_38;
  undefined2 local_36;
  undefined4 local_34;
  undefined1 local_30 [4];
  uint local_2c;
  undefined4 local_24;
  int *local_20;
  short *local_1c;
  char *local_18;
  char *local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  iVar1 = (int)param_2;
  param_5 = param_5 | 0x80000000;
  local_8 = 0;
  if ((((DAT_00a280f0 == *param_3) || (DAT_00a280ec == *param_3)) || (DAT_00a280e8 == *param_3)) ||
     (DAT_00a280e4 == *param_3)) {
    local_58 = param_3 + 1;
    local_60[0] = 10;
    local_50 = 0;
    local_4c = 0;
    local_20 = in_ECX;
    local_1c = local_58;
    FUN_008ce5ff(1,local_60,0,0,in_ECX[1],2,&local_8,0);
    iVar2 = FUN_0090981c(*(undefined4 *)(local_8 + 0x20),&local_c,&local_24);
    if (iVar2 < 0) {
      return iVar2;
    }
    if (*(int *)(local_8 + 0x30) == 0) {
LAB_00909d4d:
      if ((*(byte *)(local_8 + 0x1c) & 2) != 0) {
        *(byte *)(iVar1 + 10) = *(byte *)(iVar1 + 10) | 1;
      }
      iVar2 = *(int *)(local_8 + 0x28);
      if (iVar2 == 0) {
        if (*(int *)(local_8 + 0x24) != 0) {
          iVar2 = *(int *)(local_8 + 0x24);
          goto LAB_00909dc0;
        }
        if ((*(byte *)(iVar1 + 10) & 1) != 0) {
          iVar2 = FUN_00909a9d(param_1,local_c,iVar1 + 0x10);
          goto LAB_00909d7b;
        }
      }
      else {
LAB_00909dc0:
        iVar2 = FUN_009099da(param_1,local_c,local_24,iVar2,iVar1 + 0x10);
LAB_00909d7b:
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      if ((*(int *)(*(int *)(local_8 + 0x20) + 4) != 9) ||
         (*(int *)(*(int *)(local_8 + 0x20) + 0x14) != 0x14)) {
        iVar2 = FUN_00947758(param_1,*(undefined4 *)(local_8 + 0x20),1,0,iVar1 + 0xc);
        if (iVar2 < 0) {
          return iVar2;
        }
        goto LAB_00909deb;
      }
      FUN_008bd320(*(int *)(*local_20 + 4) + 0x18,0,0xb59,
                   s_Sampler_variable___s__does_not_s_00a28680,local_1c);
    }
    else {
      local_10 = *(int *)(local_8 + 0x30);
      param_2 = (char *)0x0;
      local_14 = (char *)0x0;
      local_18 = (char *)0x0;
      if (local_10 == 0) {
LAB_00909cab:
        param_2 = local_14;
        if ((local_14 == (char *)0x0) && (param_2 = local_18, local_18 == (char *)0x0))
        goto LAB_00909d4d;
      }
      else {
        do {
          iVar2 = *(int *)(local_10 + 8);
          if (*(int *)(iVar2 + 4) == 0x11) {
            if (*(int *)(iVar2 + 0x10) == 0) {
              iVar4 = 0;
            }
            else {
              iVar4 = *(int *)(*(int *)(iVar2 + 0x10) + 0x18);
            }
            if (*(int *)(iVar2 + 0x14) == 0) {
              pcVar5 = (char *)0x0;
            }
            else {
              pcVar5 = *(char **)(*(int *)(iVar2 + 0x14) + 0x18);
            }
            if (iVar4 == 0) {
              if ((pcVar5 != (char *)0x0) &&
                 (iVar2 = _tolower((int)*pcVar5), iVar2 == (char)*param_3)) {
                local_18 = pcVar5;
              }
            }
            else {
              iVar2 = FUN_008f31ff(iVar4,0,local_30);
              if (((-1 < iVar2) && (pcVar5 != (char *)0x0)) &&
                 (iVar2 = _tolower((int)*pcVar5), iVar2 == (char)*param_3)) {
                if (param_5 == local_2c) {
                  param_2 = pcVar5;
                }
                else if ((((local_2c ^ param_5) & 0xffff0000) == 0) && ((short)local_2c == 0)) {
                  local_14 = pcVar5;
                }
              }
            }
          }
          local_10 = *(int *)(local_10 + 0xc);
        } while (local_10 != 0);
        local_10 = 0;
        if (param_2 == (char *)0x0) goto LAB_00909cab;
      }
      iVar2 = _tolower((int)*param_2);
      if ((char)*param_3 != iVar2) goto LAB_00909d4d;
      iVar2 = _isdigit((int)param_2[1]);
      if (iVar2 == 0) goto LAB_00909d4d;
      pcVar5 = param_2 + 2;
      while (iVar2 = _isdigit((int)*pcVar5), iVar2 != 0) {
        pcVar5 = pcVar5 + 1;
      }
      if (*pcVar5 != '\0') goto LAB_00909d4d;
      uVar3 = _atol(param_2 + 1);
      if (uVar3 < 0x2000) {
        *(ushort *)(iVar1 + 10) = *(ushort *)(iVar1 + 10) | (ushort)(uVar3 << 2) | 2;
        goto LAB_00909d4d;
      }
      FUN_008bd320(*(int *)(*local_20 + 4) + 0x18,0,0xb56,
                   s_Constant_variable___s__bound_to_r_00a286f0,local_1c,uVar3);
    }
    iVar2 = -0x7fffbffb;
  }
  else {
    local_40 = 1;
    local_3e = 3;
    local_3c = 1;
    local_3a = 4;
    local_38 = 1;
    local_36 = 0;
    local_34 = 0;
    iVar2 = FUN_0093ccb5(&local_40,0x10,6,(int)param_2 + 0xc);
    if (iVar2 < 0) {
      return iVar2;
    }
    local_c = 1;
LAB_00909deb:
    iVar2 = FUN_0093ccb5(param_3,0xffffffff,7,iVar1);
    if (-1 < iVar2) {
      if (DAT_00a280ec == *param_3) {
        *(undefined2 *)(iVar1 + 4) = 0;
      }
      else {
        *(ushort *)(iVar1 + 4) = (DAT_00a280e8 != *param_3) + 1;
      }
      *(undefined2 *)(iVar1 + 6) = param_4;
      *(undefined2 *)(iVar1 + 8) = (undefined2)local_c;
    }
  }
  return iVar2;
}


// ==== FUN_00909e40 @ 0x00909e40 ====

undefined4 FUN_00909e40(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_EDX;
  
  if ((((*(int *)(in_EDX + 0x4c) != 0) || (*(int *)(in_EDX + 0x130) != 0)) ||
      (*(int *)(in_EDX + 0x28) != 3)) ||
     (((*(int *)(in_EDX + 0x24) != 3 || (*(int *)(in_EDX + 0x2c) != 2)) ||
      (*(int *)(in_EDX + 0x78) != 3)))) {
    return 0;
  }
  iVar1 = *(int *)(in_EDX + 0xdc);
  if (((*(int *)(iVar1 + 8) != 2) || (uVar3 = 1, *(int *)(iVar1 + 0x5c) != 1)) ||
     (((*(int *)(iVar1 + 0xb0) != 1 ||
       ((((2 < *(int *)(iVar1 + 0xc) || (*(int *)(iVar1 + 0x60) != 1)) ||
         (*(int *)(iVar1 + 0xb4) != 1)) ||
        ((iVar2 = *(int *)(in_EDX + 0x140), *(int *)(iVar1 + 0x24) != iVar2 ||
         (*(int *)(iVar1 + 0x78) != iVar2)))))) || (*(int *)(iVar1 + 0xcc) != iVar2)))) {
    uVar3 = 0;
  }
  return uVar3;
}


// ==== FUN_00909ec0 @ 0x00909ec0 ====

void FUN_00909ec0(int *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  piVar3 = param_1;
  iVar4 = param_1[5];
  if (iVar4 != 0xca) {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0x14;
    puVar1[6] = iVar4;
    (*(code *)*puVar1)(param_1);
  }
  iVar4 = param_1[0xc];
  uVar2 = param_1[0xd];
  if (uVar2 < (uint)(iVar4 * 8)) {
    if (uVar2 < (uint)(iVar4 * 4)) {
      if (uVar2 < (uint)(iVar4 * 2)) {
        iVar4 = param_1[8];
        param_1[0x1c] = param_1[7];
        param_1[0x50] = 8;
      }
      else {
        iVar4 = FUN_0090b6f0(param_1[7],2);
        param_1[0x1c] = iVar4;
        iVar4 = FUN_0090b6f0(param_1[8],2);
        param_1[0x50] = 4;
      }
    }
    else {
      iVar4 = FUN_0090b6f0(param_1[7],4);
      param_1[0x1c] = iVar4;
      iVar4 = FUN_0090b6f0(param_1[8],4);
      param_1[0x50] = 2;
    }
  }
  else {
    iVar4 = FUN_0090b6f0(param_1[7],8);
    param_1[0x1c] = iVar4;
    iVar4 = FUN_0090b6f0(param_1[8],8);
    param_1[0x50] = 1;
  }
  piVar6 = param_1 + 0x37;
  param_1[0x1d] = iVar4;
  param_1 = (int *)param_1[9];
  if (0 < (int)param_1) {
    piVar6 = (int *)(*piVar6 + 0xc);
    do {
      iVar4 = piVar3[0x50];
      if (iVar4 < 8) {
        iVar7 = piVar3[0x4e] * iVar4;
        do {
          if ((iVar7 < piVar6[-1] * iVar4 * 2) ||
             (piVar3[0x4f] * piVar3[0x50] < *piVar6 * iVar4 * 2)) break;
          iVar4 = iVar4 * 2;
        } while (iVar4 < 8);
      }
      piVar6[6] = iVar4;
      piVar6 = piVar6 + 0x15;
      param_1 = (int *)((int)param_1 + -1);
    } while (param_1 != (int *)0x0);
  }
  iVar4 = 0;
  if (0 < piVar3[9]) {
    piVar6 = (int *)(piVar3[0x37] + 0x24);
    do {
      iVar5 = FUN_0090b6f0(piVar6[-7] * *piVar6 * piVar3[7],piVar3[0x4e] << 3);
      iVar7 = piVar3[0x4f];
      piVar6[1] = iVar5;
      iVar7 = FUN_0090b6f0(piVar6[-6] * piVar3[8] * *piVar6,iVar7 << 3);
      piVar6[2] = iVar7;
      iVar4 = iVar4 + 1;
      piVar6 = piVar6 + 0x15;
    } while (iVar4 < piVar3[9]);
  }
  switch(piVar3[0xb]) {
  case 1:
    piVar3[0x1e] = 1;
    break;
  case 2:
  case 3:
    piVar3[0x1e] = 3;
    break;
  case 4:
  case 5:
    piVar3[0x1e] = 4;
    break;
  default:
    piVar3[0x1e] = piVar3[9];
  }
  iVar4 = 1;
  if (piVar3[0x15] == 0) {
    iVar4 = piVar3[0x1e];
  }
  piVar3[0x1f] = iVar4;
  iVar4 = FUN_00909e40();
  if (iVar4 == 0) {
    piVar3[0x20] = 1;
    return;
  }
  piVar3[0x20] = piVar3[0x4f];
  return;
}


// ==== FUN_0090a0d0 @ 0x0090a0d0 ====

void FUN_0090a0d0(void)

{
  int in_EAX;
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(in_EAX + 4))();
  iVar2 = 0;
  *(undefined4 **)(in_EAX + 0x148) = puVar1 + 0x40;
  puVar4 = puVar1;
  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  do {
    *(char *)(iVar2 + (int)(puVar1 + 0x40)) = (char)iVar2;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x100);
  puVar4 = *(undefined4 **)(in_EAX + 0x148);
  puVar5 = puVar1 + 0x80;
  for (iVar2 = 0x60; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = 0xffffffff;
    puVar5 = puVar5 + 1;
  }
  puVar5 = puVar1 + 0xe0;
  for (iVar2 = 0x60; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  puVar1 = puVar1 + 0x140;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar1 = puVar1 + 1;
  }
  return;
}


// ==== FUN_0090a150 @ 0x0090a150 ====

void FUN_0090a150(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *unaff_ESI;
  
  iVar1 = unaff_ESI[0x6a];
  FUN_00909ec0(unaff_ESI);
  FUN_0090a0d0();
  *(undefined4 *)(iVar1 + 0xc) = 0;
  uVar5 = FUN_00909e40();
  *(undefined4 *)(iVar1 + 0x10) = uVar5;
  iVar2 = unaff_ESI[0x15];
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  if ((iVar2 == 0) || (unaff_ESI[0x10] == 0)) {
    unaff_ESI[0x19] = 0;
    unaff_ESI[0x1a] = 0;
    unaff_ESI[0x1b] = 0;
  }
  if (iVar2 == 0) goto LAB_0090a1ed;
  if (unaff_ESI[0x11] != 0) {
    puVar3 = (undefined4 *)*unaff_ESI;
    puVar3[5] = 0x2f;
    (*(code *)*puVar3)();
  }
  if (unaff_ESI[0x1e] == 3) {
    if (unaff_ESI[0x22] == 0) {
      if (unaff_ESI[0x17] == 0) goto LAB_0090a1bf;
      unaff_ESI[0x1b] = 1;
    }
    else {
      unaff_ESI[0x1a] = 1;
    }
  }
  else {
    unaff_ESI[0x1a] = 0;
    unaff_ESI[0x1b] = 0;
    unaff_ESI[0x22] = 0;
LAB_0090a1bf:
    unaff_ESI[0x19] = 1;
  }
  if (unaff_ESI[0x19] != 0) {
    puVar3 = (undefined4 *)*unaff_ESI;
    puVar3[5] = 0x30;
    (*(code *)*puVar3)();
  }
  if ((unaff_ESI[0x1b] != 0) || (unaff_ESI[0x1a] != 0)) {
    puVar3 = (undefined4 *)*unaff_ESI;
    puVar3[5] = 0x30;
    (*(code *)*puVar3)();
  }
LAB_0090a1ed:
  if (unaff_ESI[0x11] == 0) {
    if (*(int *)(iVar1 + 0x10) == 0) {
      FUN_009546e0(unaff_ESI);
      FUN_00953770(unaff_ESI);
    }
    else {
      FUN_00955370(unaff_ESI);
    }
    FUN_00952880(unaff_ESI,unaff_ESI[0x1b]);
  }
  FUN_009526f0(unaff_ESI);
  if (unaff_ESI[0x39] == 0) {
    if (unaff_ESI[0x38] == 0) {
      FUN_00951720(unaff_ESI);
    }
    else {
      FUN_00952320(unaff_ESI);
    }
  }
  else {
    puVar3 = (undefined4 *)*unaff_ESI;
    puVar3[5] = 1;
    (*(code *)*puVar3)();
  }
  if ((*(int *)(unaff_ESI[0x6e] + 0x10) == 0) && (unaff_ESI[0x10] == 0)) {
    uVar5 = 0;
  }
  else {
    uVar5 = 1;
  }
  FUN_00950af0(unaff_ESI,uVar5);
  if (unaff_ESI[0x11] == 0) {
    FUN_0094fad0(unaff_ESI,0);
  }
  (**(code **)(unaff_ESI[1] + 0x18))();
  (**(code **)(unaff_ESI[0x6e] + 8))();
  iVar2 = unaff_ESI[2];
  if (((iVar2 != 0) && (unaff_ESI[0x10] == 0)) && (*(int *)(unaff_ESI[0x6e] + 0x10) != 0)) {
    iVar6 = unaff_ESI[9];
    if (unaff_ESI[0x38] != 0) {
      iVar6 = iVar6 * 3 + 2;
    }
    iVar4 = unaff_ESI[0x51];
    *(undefined4 *)(iVar2 + 4) = 0;
    *(int *)(iVar2 + 8) = iVar4 * iVar6;
    iVar6 = unaff_ESI[0x1b];
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(uint *)(iVar2 + 0x10) = (iVar6 != 0) + 2;
    *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + 1;
  }
  return;
}


// ==== FUN_0090a300 @ 0x0090a300 ====

void FUN_0090a300(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = param_1[0x6a];
  if (*(int *)(iVar1 + 8) == 0) {
    if ((param_1[0x15] != 0) && (param_1[0x22] == 0)) {
      if ((param_1[0x17] == 0) || (param_1[0x1b] == 0)) {
        if (param_1[0x19] == 0) {
          puVar2 = (undefined4 *)*param_1;
          puVar2[5] = 0x2e;
          (*(code *)*puVar2)(param_1);
        }
        else {
          param_1[0x74] = *(int *)(iVar1 + 0x14);
        }
      }
      else {
        param_1[0x74] = *(int *)(iVar1 + 0x18);
        *(undefined4 *)(iVar1 + 8) = 1;
      }
    }
    (**(code **)param_1[0x71])(param_1);
    (**(code **)(param_1[0x6c] + 8))(param_1);
    if (param_1[0x11] == 0) {
      if (*(int *)(iVar1 + 0x10) == 0) {
        (**(code **)param_1[0x73])(param_1);
      }
      (**(code **)param_1[0x72])(param_1);
      if (param_1[0x15] != 0) {
        (**(code **)param_1[0x74])(param_1,*(undefined4 *)(iVar1 + 8));
      }
      (**(code **)param_1[0x6d])(param_1,-(*(int *)(iVar1 + 8) != 0) & 3);
      (**(code **)param_1[0x6b])(param_1,0);
    }
  }
  else {
    puVar2 = (undefined4 *)*param_1;
    puVar2[5] = 0x30;
    (*(code *)*puVar2)(param_1);
  }
  iVar3 = param_1[2];
  if (iVar3 != 0) {
    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    iVar4 = (*(int *)(iVar1 + 8) != 0) + 1 + *(int *)(iVar1 + 0xc);
    iVar1 = param_1[0x10];
    *(int *)(iVar3 + 0x10) = iVar4;
    if ((iVar1 != 0) && (*(int *)(param_1[0x6e] + 0x14) == 0)) {
      *(uint *)(iVar3 + 0x10) = (param_1[0x1b] != 0) + 1 + iVar4;
    }
  }
  return;
}


// ==== FUN_0090a430 @ 0x0090a430 ====

void FUN_0090a430(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x1a8);
  if (*(int *)(param_1 + 0x54) != 0) {
    (**(code **)(*(int *)(param_1 + 0x1d0) + 8))(param_1);
  }
  piVar1 = (int *)(iVar2 + 0xc);
  *piVar1 = *piVar1 + 1;
  return;
}


// ==== FUN_0090a460 @ 0x0090a460 ====

void FUN_0090a460(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x1c);
  *(undefined4 **)(param_1 + 0x1a8) = puVar1;
  *puVar1 = FUN_0090a300;
  puVar1[1] = FUN_0090a430;
  puVar1[2] = 0;
  FUN_0090a150();
  return;
}


// ==== FUN_0090a4a0 @ 0x0090a4a0 ====

void FUN_0090a4a0(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *unaff_ESI;
  int *piVar5;
  undefined4 *puVar6;
  
  if ((0xffdc < unaff_ESI[8]) || (0xffdc < unaff_ESI[7])) {
    puVar6 = (undefined4 *)*unaff_ESI;
    puVar6[5] = 0x29;
    puVar6[6] = 0xffdc;
    (*(code *)*puVar6)();
  }
  iVar4 = unaff_ESI[0x36];
  if (iVar4 != 8) {
    puVar6 = (undefined4 *)*unaff_ESI;
    puVar6[5] = 0xf;
    puVar6[6] = iVar4;
    (*(code *)*puVar6)();
  }
  iVar4 = unaff_ESI[9];
  if (10 < iVar4) {
    puVar6 = (undefined4 *)*unaff_ESI;
    puVar6[5] = 0x1a;
    puVar6[6] = iVar4;
    puVar6[7] = 10;
    (*(code *)*puVar6)();
  }
  iVar4 = 0;
  unaff_ESI[0x4e] = 1;
  unaff_ESI[0x4f] = 1;
  if (0 < unaff_ESI[9]) {
    piVar5 = (int *)(unaff_ESI[0x37] + 0xc);
    do {
      if ((((piVar5[-1] < 1) || (4 < piVar5[-1])) || (*piVar5 < 1)) || (4 < *piVar5)) {
        puVar6 = (undefined4 *)*unaff_ESI;
        puVar6[5] = 0x12;
        (*(code *)*puVar6)();
      }
      iVar2 = unaff_ESI[0x4e];
      if (unaff_ESI[0x4e] <= piVar5[-1]) {
        iVar2 = piVar5[-1];
      }
      iVar1 = *piVar5;
      unaff_ESI[0x4e] = iVar2;
      iVar2 = unaff_ESI[0x4f];
      if (unaff_ESI[0x4f] <= iVar1) {
        iVar2 = iVar1;
      }
      unaff_ESI[0x4f] = iVar2;
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 0x15;
    } while (iVar4 < unaff_ESI[9]);
  }
  iVar4 = 0;
  unaff_ESI[0x50] = 8;
  if (0 < unaff_ESI[9]) {
    puVar6 = (undefined4 *)(unaff_ESI[0x37] + 0x1c);
    do {
      iVar2 = unaff_ESI[7];
      iVar1 = unaff_ESI[0x4e];
      puVar6[2] = 8;
      uVar3 = FUN_0090b6f0(puVar6[-5] * iVar2,iVar1 << 3);
      iVar2 = unaff_ESI[0x4f];
      *puVar6 = uVar3;
      uVar3 = FUN_0090b6f0(puVar6[-4] * unaff_ESI[8],iVar2 << 3);
      iVar2 = unaff_ESI[7];
      iVar1 = unaff_ESI[0x4e];
      puVar6[1] = uVar3;
      uVar3 = FUN_0090b6f0(puVar6[-5] * iVar2,iVar1);
      iVar2 = unaff_ESI[8];
      puVar6[3] = uVar3;
      uVar3 = FUN_0090b6f0(puVar6[-4] * iVar2,unaff_ESI[0x4f]);
      puVar6[4] = uVar3;
      iVar2 = unaff_ESI[9];
      puVar6[5] = 1;
      puVar6[0xc] = 0;
      iVar4 = iVar4 + 1;
      puVar6 = puVar6 + 0x15;
    } while (iVar4 < iVar2);
  }
  iVar4 = FUN_0090b6f0(unaff_ESI[8],unaff_ESI[0x4f] << 3);
  unaff_ESI[0x51] = iVar4;
  if ((unaff_ESI[0x53] < unaff_ESI[9]) || (unaff_ESI[0x38] != 0)) {
    *(undefined4 *)(unaff_ESI[0x6e] + 0x10) = 1;
    return;
  }
  *(undefined4 *)(unaff_ESI[0x6e] + 0x10) = 0;
  return;
}


// ==== FUN_0090a680 @ 0x0090a680 ====

uint FUN_0090a680(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *unaff_ESI;
  int *local_c;
  uint local_8;
  
  iVar3 = unaff_ESI[0x53];
  if (iVar3 == 1) {
    iVar3 = unaff_ESI[0x54];
    uVar1 = *(undefined4 *)(iVar3 + 0x24);
    uVar4 = *(uint *)(iVar3 + 0xc);
    unaff_ESI[0x58] = *(int *)(iVar3 + 0x1c);
    uVar6 = *(uint *)(iVar3 + 0x20);
    *(undefined4 *)(iVar3 + 0x40) = uVar1;
    unaff_ESI[0x59] = uVar6;
    *(undefined4 *)(iVar3 + 0x34) = 1;
    *(undefined4 *)(iVar3 + 0x38) = 1;
    *(undefined4 *)(iVar3 + 0x3c) = 1;
    *(undefined4 *)(iVar3 + 0x44) = 1;
    uVar5 = uVar6 % uVar4;
    if (uVar6 % uVar4 == 0) {
      uVar5 = uVar4;
    }
    unaff_ESI[0x5a] = 1;
    *(uint *)(iVar3 + 0x48) = uVar5;
    unaff_ESI[0x5b] = 0;
    return uVar6 / uVar4;
  }
  if ((iVar3 < 1) || (4 < iVar3)) {
    puVar2 = (undefined4 *)*unaff_ESI;
    puVar2[5] = 0x1a;
    puVar2[6] = iVar3;
    puVar2[7] = 4;
    (*(code *)*puVar2)();
  }
  iVar3 = FUN_0090b6f0(unaff_ESI[7],unaff_ESI[0x4e] << 3);
  unaff_ESI[0x58] = iVar3;
  uVar4 = FUN_0090b6f0(unaff_ESI[8],unaff_ESI[0x4f] << 3);
  unaff_ESI[0x59] = uVar4;
  unaff_ESI[0x5a] = 0;
  local_8 = 0;
  if (0 < unaff_ESI[0x53]) {
    local_c = unaff_ESI + 0x54;
    do {
      iVar3 = *local_c;
      uVar4 = *(uint *)(iVar3 + 8);
      *(uint *)(iVar3 + 0x40) = *(int *)(iVar3 + 0x24) * uVar4;
      uVar6 = *(uint *)(iVar3 + 0x1c) % uVar4;
      *(int *)(iVar3 + 0x38) = *(int *)(iVar3 + 0xc);
      iVar7 = *(int *)(iVar3 + 0xc) * uVar4;
      *(uint *)(iVar3 + 0x34) = uVar4;
      *(int *)(iVar3 + 0x3c) = iVar7;
      if (uVar6 == 0) {
        uVar6 = uVar4;
      }
      *(uint *)(iVar3 + 0x44) = uVar6;
      uVar4 = *(uint *)(iVar3 + 0x20) % *(uint *)(iVar3 + 0xc);
      if (uVar4 == 0) {
        uVar4 = *(uint *)(iVar3 + 0xc);
      }
      *(uint *)(iVar3 + 0x48) = uVar4;
      if (10 < unaff_ESI[0x5a] + iVar7) {
        puVar2 = (undefined4 *)*unaff_ESI;
        puVar2[5] = 0xd;
        (*(code *)*puVar2)();
      }
      if (0 < iVar7) {
        do {
          unaff_ESI[unaff_ESI[0x5a] + 0x5b] = local_8;
          iVar7 = iVar7 + -1;
          unaff_ESI[0x5a] = unaff_ESI[0x5a] + 1;
        } while (iVar7 != 0);
      }
      uVar4 = local_8 + 1;
      local_c = local_c + 1;
      local_8 = uVar4;
    } while ((int)uVar4 < unaff_ESI[0x53]);
  }
  return uVar4;
}


// ==== FUN_0090a810 @ 0x0090a810 ====

void FUN_0090a810(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *unaff_EBX;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int local_c;
  int *local_8;
  
  local_c = 0;
  if (0 < unaff_EBX[0x53]) {
    local_8 = unaff_EBX + 0x54;
    do {
      iVar1 = *local_8;
      if (*(int *)(iVar1 + 0x4c) == 0) {
        iVar2 = *(int *)(iVar1 + 0x10);
        if (((iVar2 < 0) || (3 < iVar2)) || (unaff_EBX[iVar2 + 0x2a] == 0)) {
          puVar5 = (undefined4 *)*unaff_EBX;
          puVar5[5] = 0x34;
          puVar5[6] = iVar2;
          (*(code *)*puVar5)();
        }
        puVar3 = (undefined4 *)(**(code **)unaff_EBX[1])();
        puVar5 = (undefined4 *)unaff_EBX[iVar2 + 0x2a];
        puVar6 = puVar3;
        for (iVar4 = 0x21; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        *(undefined4 **)(iVar1 + 0x4c) = puVar3;
      }
      local_c = local_c + 1;
      local_8 = local_8 + 1;
    } while (local_c < unaff_EBX[0x53]);
  }
  return;
}


// ==== FUN_0090a8b0 @ 0x0090a8b0 ====

void FUN_0090a8b0(int param_1)

{
  FUN_0090a680();
  FUN_0090a810();
  (*(code *)**(undefined4 **)(param_1 + 0x1c0))(param_1);
  (*(code *)**(undefined4 **)(param_1 + 0x1b0))(param_1);
  **(undefined4 **)(param_1 + 0x1b8) = *(undefined4 *)(*(int *)(param_1 + 0x1b0) + 4);
  return;
}


// ==== FUN_0090a8f0 @ 0x0090a8f0 ====

int FUN_0090a8f0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = param_1[0x6e];
  if (*(int *)(iVar1 + 0x14) != 0) {
    return 2;
  }
  iVar3 = (**(code **)(param_1[0x6f] + 4))(param_1);
  if (iVar3 == 1) {
    if (*(int *)(iVar1 + 0x18) != 0) {
      FUN_0090a4a0();
      *(undefined4 *)(iVar1 + 0x18) = 0;
      return 1;
    }
    if (*(int *)(iVar1 + 0x10) == 0) {
      puVar2 = (undefined4 *)*param_1;
      puVar2[5] = 0x23;
      (*(code *)*puVar2)(param_1);
    }
    FUN_0090a8b0(param_1);
  }
  else if (iVar3 == 2) {
    *(undefined4 *)(iVar1 + 0x14) = 1;
    if (*(int *)(iVar1 + 0x18) == 0) {
      if (param_1[0x25] < param_1[0x27]) {
        param_1[0x27] = param_1[0x25];
        return 2;
      }
    }
    else if (*(int *)(param_1[0x6f] + 0x10) != 0) {
      puVar2 = (undefined4 *)*param_1;
      puVar2[5] = 0x3b;
      (*(code *)*puVar2)(param_1);
      return 2;
    }
  }
  return iVar3;
}


// ==== FUN_0090a9c0 @ 0x0090a9c0 ====

void FUN_0090a9c0(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[0x6e];
  *puVar1 = FUN_0090a8f0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 1;
  (**(code **)(*param_1 + 0x10))(param_1);
  (**(code **)param_1[0x6f])(param_1);
  param_1[0x29] = 0;
  return;
}


// ==== FUN_0090aa10 @ 0x0090aa10 ====

void FUN_0090aa10(int param_1)

{
  **(undefined4 **)(param_1 + 0x1b8) = FUN_0090a8f0;
  return;
}


// ==== FUN_0090aa30 @ 0x0090aa30 ====

void FUN_0090aa30(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x1c);
  *(undefined4 **)(param_1 + 0x1b8) = puVar1;
  *puVar1 = FUN_0090a8f0;
  puVar1[1] = FUN_0090a9c0;
  puVar1[2] = FUN_0090a8b0;
  puVar1[3] = FUN_0090aa10;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 1;
  return;
}


// ==== FUN_0090aa80 @ 0x0090aa80 ====

int FUN_0090aa80(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  
  piVar3 = param_1;
  iVar1 = param_1[1];
  if (0x3b9ac9f0 < param_3) {
    puVar2 = (undefined4 *)*param_1;
    puVar2[5] = 0x36;
    puVar2[6] = 1;
    (*(code *)*puVar2)(param_1);
  }
  if ((param_3 & 7) != 0) {
    param_3 = param_3 + (8 - (param_3 & 7));
  }
  if ((param_2 < 0) || (1 < param_2)) {
    puVar2 = (undefined4 *)*param_1;
    puVar2[5] = 0xe;
    puVar2[6] = param_2;
    (*(code *)*puVar2)(param_1);
  }
  param_1 = (undefined4 *)0x0;
  puVar2 = *(undefined4 **)(iVar1 + 0x34 + param_2 * 4);
  while (puVar4 = puVar2, puVar4 != (undefined4 *)0x0) {
    if (param_3 <= (uint)puVar4[2]) goto LAB_0090ab97;
    param_1 = puVar4;
    puVar2 = (undefined4 *)*puVar4;
  }
  iVar5 = param_3 + 0x10;
  if (param_1 == (undefined4 *)0x0) {
    uVar6 = *(uint *)(&DAT_00a2873c + param_2 * 4);
  }
  else {
    uVar6 = *(uint *)(&DAT_00a28744 + param_2 * 4);
  }
  if (1000000000U - iVar5 < uVar6) {
    uVar6 = 1000000000U - iVar5;
  }
  puVar4 = (undefined4 *)FUN_00955400(piVar3,uVar6 + iVar5);
  while (puVar4 == (undefined4 *)0x0) {
    uVar6 = uVar6 >> 1;
    if (uVar6 < 0x32) {
      puVar2 = (undefined4 *)*piVar3;
      puVar2[5] = 0x36;
      puVar2[6] = 2;
      (*(code *)*puVar2)(piVar3);
    }
    puVar4 = (undefined4 *)FUN_00955400(piVar3,uVar6 + iVar5);
  }
  *(uint *)(iVar1 + 0x4c) = *(int *)(iVar1 + 0x4c) + uVar6 + iVar5;
  *puVar4 = 0;
  puVar4[1] = 0;
  puVar4[2] = uVar6 + param_3;
  if (param_1 == (undefined4 *)0x0) {
    *(undefined4 **)(iVar1 + 0x34 + param_2 * 4) = puVar4;
  }
  else {
    *param_1 = (int)puVar4;
  }
LAB_0090ab97:
  iVar1 = puVar4[1];
  puVar4[1] = iVar1 + param_3;
  puVar4[2] = puVar4[2] - param_3;
  return iVar1 + 0x10 + (int)puVar4;
}


// ==== FUN_0090abc0 @ 0x0090abc0 ====

undefined4 * FUN_0090abc0(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  iVar1 = param_1[1];
  if (0x3b9ac9f0 < param_3) {
    puVar4 = (undefined4 *)*param_1;
    puVar4[5] = 0x36;
    puVar4[6] = 3;
    (*(code *)*puVar4)(param_1);
  }
  if ((param_3 & 7) != 0) {
    param_3 = param_3 + (8 - (param_3 & 7));
  }
  if ((param_2 < 0) || (1 < param_2)) {
    puVar4 = (undefined4 *)*param_1;
    puVar4[5] = 0xe;
    puVar4[6] = param_2;
    (*(code *)*puVar4)(param_1);
  }
  puVar4 = (undefined4 *)FUN_00955400(param_1,param_3 + 0x10);
  if (puVar4 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*param_1;
    puVar2[5] = 0x36;
    puVar2[6] = 4;
    (*(code *)*puVar2)(param_1);
  }
  *(uint *)(iVar1 + 0x4c) = *(int *)(iVar1 + 0x4c) + param_3 + 0x10;
  uVar3 = *(undefined4 *)(iVar1 + 0x3c + param_2 * 4);
  *(undefined4 **)(iVar1 + 0x3c + param_2 * 4) = puVar4;
  puVar4[1] = param_3;
  *puVar4 = uVar3;
  puVar4[2] = 0;
  return puVar4 + 4;
}


// ==== FUN_0090ac70 @ 0x0090ac70 ====

int FUN_0090ac70(int *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = param_1[1];
  uVar2 = (uint)(0x3b9ac9f0 / (ulonglong)param_3);
  if (uVar2 == 0) {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0x46;
    (*(code *)*puVar1)(param_1);
  }
  if ((int)param_4 <= (int)uVar2) {
    uVar2 = param_4;
  }
  *(uint *)(iVar3 + 0x50) = uVar2;
  iVar3 = FUN_0090aa80(param_1,param_2,param_4 * 4);
  uVar6 = 0;
  if (param_4 != 0) {
    do {
      if (param_4 - uVar6 <= uVar2) {
        uVar2 = param_4 - uVar6;
      }
      iVar4 = FUN_0090abc0(param_1,param_2,uVar2 * param_3);
      if (uVar2 != 0) {
        uVar5 = uVar2;
        do {
          *(int *)(iVar3 + uVar6 * 4) = iVar4;
          uVar6 = uVar6 + 1;
          iVar4 = iVar4 + param_3;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
    } while (uVar6 < param_4);
  }
  return iVar3;
}


// ==== FUN_0090ad20 @ 0x0090ad20 ====

int FUN_0090ad20(int *param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = param_1[1];
  uVar2 = (uint)(0x3b9ac9f0 / (ulonglong)(uint)(param_3 * 0x80));
  if (uVar2 == 0) {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0x46;
    (*(code *)*puVar1)(param_1);
  }
  if ((int)param_4 <= (int)uVar2) {
    uVar2 = param_4;
  }
  *(uint *)(iVar3 + 0x50) = uVar2;
  iVar3 = FUN_0090aa80(param_1,param_2,param_4 * 4);
  uVar6 = 0;
  if (param_4 != 0) {
    do {
      if (param_4 - uVar6 <= uVar2) {
        uVar2 = param_4 - uVar6;
      }
      iVar4 = FUN_0090abc0(param_1,param_2,uVar2 * param_3 * 0x80);
      if (uVar2 != 0) {
        uVar5 = uVar2;
        do {
          *(int *)(iVar3 + uVar6 * 4) = iVar4;
          uVar6 = uVar6 + 1;
          iVar4 = iVar4 + param_3 * 0x80;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
    } while (uVar6 < param_4);
  }
  return iVar3;
}


// ==== FUN_0090add0 @ 0x0090add0 ====

void FUN_0090add0(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = param_1[1];
  if (param_2 != 1) {
    puVar3 = (undefined4 *)*param_1;
    puVar3[5] = 0xe;
    puVar3[6] = param_2;
    (*(code *)*puVar3)(param_1);
  }
  puVar3 = (undefined4 *)FUN_0090aa80(param_1,param_2,0x248);
  puVar3[1] = param_5;
  puVar3[3] = param_6;
  uVar2 = *(undefined4 *)(iVar1 + 0x44);
  *(undefined4 **)(iVar1 + 0x44) = puVar3;
  puVar3[2] = param_4;
  *puVar3 = 0;
  puVar3[8] = param_3;
  puVar3[10] = 0;
  puVar3[0xb] = uVar2;
  return;
}


// ==== FUN_0090ae40 @ 0x0090ae40 ====

void FUN_0090ae40(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = param_1[1];
  if (param_2 != 1) {
    puVar3 = (undefined4 *)*param_1;
    puVar3[5] = 0xe;
    puVar3[6] = param_2;
    (*(code *)*puVar3)(param_1);
  }
  puVar3 = (undefined4 *)FUN_0090aa80(param_1,param_2,0x248);
  puVar3[1] = param_5;
  puVar3[3] = param_6;
  uVar2 = *(undefined4 *)(iVar1 + 0x48);
  *(undefined4 **)(iVar1 + 0x48) = puVar3;
  puVar3[2] = param_4;
  *puVar3 = 0;
  puVar3[8] = param_3;
  puVar3[10] = 0;
  puVar3[0xb] = uVar2;
  return;
}


// ==== FUN_0090aeb0 @ 0x0090aeb0 ====

void FUN_0090aeb0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar5 = 0;
  iVar4 = 0;
  for (piVar2 = *(int **)(iVar1 + 0x44); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0xb]) {
    if (*piVar2 == 0) {
      iVar5 = iVar5 + piVar2[3] * piVar2[2];
      iVar4 = iVar4 + piVar2[1] * piVar2[2];
    }
  }
  for (piVar2 = *(int **)(iVar1 + 0x48); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0xb]) {
    if (*piVar2 == 0) {
      iVar5 = iVar5 + piVar2[3] * piVar2[2] * 0x80;
      iVar4 = iVar4 + piVar2[1] * piVar2[2] * 0x80;
    }
  }
  if (0 < iVar5) {
    iVar3 = FUN_00955450(param_1,iVar5,iVar4,*(undefined4 *)(iVar1 + 0x4c));
    if (iVar3 < iVar4) {
      iVar3 = iVar3 / iVar5;
      if (iVar3 < 1) {
        iVar3 = 1;
      }
    }
    else {
      iVar3 = 1000000000;
    }
    for (piVar2 = *(int **)(iVar1 + 0x44); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0xb]) {
      if (*piVar2 == 0) {
        iVar4 = piVar2[1];
        if (iVar3 < (int)((iVar4 - 1U) / (uint)piVar2[3] + 1)) {
          piVar2[4] = piVar2[3] * iVar3;
          FUN_00955550(param_1,piVar2 + 0xc,piVar2[2] * iVar4);
          piVar2[10] = 1;
        }
        else {
          piVar2[4] = iVar4;
        }
        iVar4 = FUN_0090ac70(param_1,1,piVar2[2],piVar2[4]);
        *piVar2 = iVar4;
        piVar2[5] = *(int *)(iVar1 + 0x50);
        piVar2[6] = 0;
        piVar2[7] = 0;
        piVar2[9] = 0;
      }
    }
    for (piVar2 = *(int **)(iVar1 + 0x48); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0xb]) {
      if (*piVar2 == 0) {
        iVar4 = piVar2[1];
        if (iVar3 < (int)((iVar4 - 1U) / (uint)piVar2[3] + 1)) {
          piVar2[4] = piVar2[3] * iVar3;
          FUN_00955550(param_1,piVar2 + 0xc,piVar2[2] * iVar4 * 0x80);
          piVar2[10] = 1;
        }
        else {
          piVar2[4] = iVar4;
        }
        iVar5 = FUN_0090ad20(param_1,1,piVar2[2],piVar2[4]);
        iVar4 = *(int *)(iVar1 + 0x50);
        *piVar2 = iVar5;
        piVar2[5] = iVar4;
        piVar2[6] = 0;
        piVar2[7] = 0;
        piVar2[9] = 0;
      }
    }
  }
  return;
}


// ==== FUN_0090b050 @ 0x0090b050 ====

void FUN_0090b050(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *unaff_ESI;
  int iVar4;
  int local_8;
  
  iVar1 = unaff_ESI[2];
  local_8 = unaff_ESI[6] * iVar1;
  iVar3 = unaff_ESI[4];
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      iVar2 = iVar3 - iVar4;
      if (unaff_ESI[5] < iVar3 - iVar4) {
        iVar2 = unaff_ESI[5];
      }
      iVar3 = unaff_ESI[7] - (unaff_ESI[6] + iVar4);
      if (iVar3 <= iVar2) {
        iVar2 = iVar3;
      }
      iVar3 = unaff_ESI[1] - (unaff_ESI[6] + iVar4);
      if (iVar3 <= iVar2) {
        iVar2 = iVar3;
      }
      if (iVar2 < 1) {
        return;
      }
      iVar2 = iVar2 * iVar1;
      if (param_2 == 0) {
        (*(code *)unaff_ESI[0xc])
                  (param_1,unaff_ESI + 0xc,*(undefined4 *)(*unaff_ESI + iVar4 * 4),local_8,iVar2);
      }
      else {
        (*(code *)unaff_ESI[0xd])(param_1,unaff_ESI + 0xc,*(undefined4 *)(*unaff_ESI + iVar4 * 4));
      }
      local_8 = local_8 + iVar2;
      iVar3 = unaff_ESI[4];
      iVar4 = iVar4 + unaff_ESI[5];
    } while (iVar4 < iVar3);
  }
  return;
}


// ==== FUN_0090b0f0 @ 0x0090b0f0 ====

void FUN_0090b0f0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *unaff_ESI;
  int iVar4;
  int local_8;
  
  iVar1 = unaff_ESI[2];
  local_8 = unaff_ESI[6] * iVar1 * 0x80;
  iVar3 = unaff_ESI[4];
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      iVar2 = iVar3 - iVar4;
      if (unaff_ESI[5] < iVar3 - iVar4) {
        iVar2 = unaff_ESI[5];
      }
      iVar3 = unaff_ESI[7] - (unaff_ESI[6] + iVar4);
      if (iVar3 <= iVar2) {
        iVar2 = iVar3;
      }
      iVar3 = unaff_ESI[1] - (unaff_ESI[6] + iVar4);
      if (iVar3 <= iVar2) {
        iVar2 = iVar3;
      }
      if (iVar2 < 1) {
        return;
      }
      iVar2 = iVar2 * iVar1 * 0x80;
      if (param_2 == 0) {
        (*(code *)unaff_ESI[0xc])
                  (param_1,unaff_ESI + 0xc,*(undefined4 *)(*unaff_ESI + iVar4 * 4),local_8,iVar2);
      }
      else {
        (*(code *)unaff_ESI[0xd])(param_1,unaff_ESI + 0xc,*(undefined4 *)(*unaff_ESI + iVar4 * 4));
      }
      local_8 = local_8 + iVar2;
      iVar3 = unaff_ESI[4];
      iVar4 = iVar4 + unaff_ESI[5];
    } while (iVar4 < iVar3);
  }
  return;
}


// ==== FUN_0090b1a0 @ 0x0090b1a0 ====

int FUN_0090b1a0(int *param_1,int *param_2,uint param_3,uint param_4,int param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar1 = param_3 + param_4;
  if ((((uint)param_2[1] < uVar1) || ((uint)param_2[3] < param_4)) || (*param_2 == 0)) {
    puVar2 = (undefined4 *)*param_1;
    puVar2[5] = 0x16;
    (*(code *)*puVar2)(param_1);
  }
  if ((param_3 < (uint)param_2[6]) || ((uint)(param_2[4] + param_2[6]) < uVar1)) {
    if (param_2[10] == 0) {
      puVar2 = (undefined4 *)*param_1;
      puVar2[5] = 0x45;
      (*(code *)*puVar2)(param_1);
    }
    if (param_2[9] != 0) {
      FUN_0090b050(param_1,1);
      param_2[9] = 0;
    }
    uVar5 = param_3;
    if ((param_3 <= (uint)param_2[6]) && (uVar5 = uVar1 - param_2[4], (int)uVar5 < 0)) {
      uVar5 = 0;
    }
    param_2[6] = uVar5;
    FUN_0090b050(param_1,0);
  }
  uVar5 = param_2[7];
  if (uVar5 < uVar1) {
    if (uVar5 < param_3) {
      if (param_5 != 0) {
        puVar2 = (undefined4 *)*param_1;
        puVar2[5] = 0x16;
        (*(code *)*puVar2)(param_1);
      }
      uVar5 = param_3;
    }
    if (param_5 != 0) {
      param_2[7] = uVar1;
    }
    if (param_2[8] != 0) {
      iVar3 = param_2[2];
      iVar4 = param_2[6];
      for (uVar5 = uVar5 - iVar4; uVar5 < uVar1 - iVar4; uVar5 = uVar5 + 1) {
        FUN_0090b7b0(*(undefined4 *)(*param_2 + uVar5 * 4),iVar3);
      }
      goto LAB_0090b28b;
    }
    if (param_5 == 0) {
      puVar2 = (undefined4 *)*param_1;
      puVar2[5] = 0x16;
      (*(code *)*puVar2)(param_1);
      return *param_2 + (param_3 - param_2[6]) * 4;
    }
  }
  else {
LAB_0090b28b:
    if (param_5 == 0) goto LAB_0090b299;
  }
  param_2[9] = 1;
LAB_0090b299:
  return *param_2 + (param_3 - param_2[6]) * 4;
}


// ==== FUN_0090b2e0 @ 0x0090b2e0 ====

int FUN_0090b2e0(int *param_1,int *param_2,uint param_3,uint param_4,int param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar1 = param_3 + param_4;
  if ((((uint)param_2[1] < uVar1) || ((uint)param_2[3] < param_4)) || (*param_2 == 0)) {
    puVar2 = (undefined4 *)*param_1;
    puVar2[5] = 0x16;
    (*(code *)*puVar2)(param_1);
  }
  if ((param_3 < (uint)param_2[6]) || ((uint)(param_2[4] + param_2[6]) < uVar1)) {
    if (param_2[10] == 0) {
      puVar2 = (undefined4 *)*param_1;
      puVar2[5] = 0x45;
      (*(code *)*puVar2)(param_1);
    }
    if (param_2[9] != 0) {
      FUN_0090b0f0(param_1,1);
      param_2[9] = 0;
    }
    uVar5 = param_3;
    if ((param_3 <= (uint)param_2[6]) && (uVar5 = uVar1 - param_2[4], (int)uVar5 < 0)) {
      uVar5 = 0;
    }
    param_2[6] = uVar5;
    FUN_0090b0f0(param_1,0);
  }
  uVar5 = param_2[7];
  if (uVar5 < uVar1) {
    if (uVar5 < param_3) {
      if (param_5 != 0) {
        puVar2 = (undefined4 *)*param_1;
        puVar2[5] = 0x16;
        (*(code *)*puVar2)(param_1);
      }
      uVar5 = param_3;
    }
    if (param_5 != 0) {
      param_2[7] = uVar1;
    }
    if (param_2[8] != 0) {
      iVar3 = param_2[6];
      iVar4 = param_2[2];
      for (uVar5 = uVar5 - iVar3; uVar5 < uVar1 - iVar3; uVar5 = uVar5 + 1) {
        FUN_0090b7b0(*(undefined4 *)(*param_2 + uVar5 * 4),iVar4 << 7);
      }
      goto LAB_0090b3d4;
    }
    if (param_5 == 0) {
      puVar2 = (undefined4 *)*param_1;
      puVar2[5] = 0x16;
      (*(code *)*puVar2)(param_1);
      return *param_2 + (param_3 - param_2[6]) * 4;
    }
  }
  else {
LAB_0090b3d4:
    if (param_5 == 0) goto LAB_0090b3e2;
  }
  param_2[9] = 1;
LAB_0090b3e2:
  return *param_2 + (param_3 - param_2[6]) * 4;
}


// ==== FUN_0090b420 @ 0x0090b420 ====

void FUN_0090b420(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar1 = param_1[1];
  if ((param_2 < 0) || (1 < param_2)) {
    puVar2 = (undefined4 *)*param_1;
    puVar2[5] = 0xe;
    puVar2[6] = param_2;
    (*(code *)*puVar2)(param_1);
  }
  if (param_2 == 1) {
    for (iVar3 = *(int *)(iVar1 + 0x44); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x2c)) {
      if (*(int *)(iVar3 + 0x28) != 0) {
        *(undefined4 *)(iVar3 + 0x28) = 0;
        (**(code **)(iVar3 + 0x38))(param_1,iVar3 + 0x30);
      }
    }
    iVar3 = *(int *)(iVar1 + 0x48);
    *(undefined4 *)(iVar1 + 0x44) = 0;
    for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x2c)) {
      if (*(int *)(iVar3 + 0x28) != 0) {
        *(undefined4 *)(iVar3 + 0x28) = 0;
        (**(code **)(iVar3 + 0x38))(param_1,iVar3 + 0x30);
      }
    }
    *(undefined4 *)(iVar1 + 0x48) = 0;
  }
  puVar2 = *(undefined4 **)(iVar1 + 0x3c + param_2 * 4);
  *(undefined4 *)(iVar1 + 0x3c + param_2 * 4) = 0;
  while (puVar2 != (undefined4 *)0x0) {
    puVar4 = (undefined4 *)*puVar2;
    iVar3 = puVar2[2] + 0x10 + puVar2[1];
    FUN_00955430(param_1,puVar2,iVar3);
    *(int *)(iVar1 + 0x4c) = *(int *)(iVar1 + 0x4c) - iVar3;
    puVar2 = puVar4;
  }
  puVar2 = *(undefined4 **)(iVar1 + 0x34 + param_2 * 4);
  *(undefined4 *)(iVar1 + 0x34 + param_2 * 4) = 0;
  while (puVar2 != (undefined4 *)0x0) {
    puVar4 = (undefined4 *)*puVar2;
    iVar3 = puVar2[2] + 0x10 + puVar2[1];
    FUN_00955430(param_1,puVar2,iVar3);
    *(int *)(iVar1 + 0x4c) = *(int *)(iVar1 + 0x4c) - iVar3;
    puVar2 = puVar4;
  }
  return;
}


// ==== FUN_0090b520 @ 0x0090b520 ====

void FUN_0090b520(int param_1)

{
  int iVar1;
  
  iVar1 = 1;
  do {
    FUN_0090b420(param_1,iVar1);
    iVar1 = iVar1 + -1;
  } while (-1 < iVar1);
  FUN_00955430(param_1,*(undefined4 *)(param_1 + 4),0x54);
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_004154b0(param_1);
  return;
}


// ==== FUN_0090b560 @ 0x0090b560 ====

void FUN_0090b560(int *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  param_1[1] = 0;
  uVar2 = FUN_009555b0(param_1);
  puVar3 = (undefined4 *)FUN_00955400(param_1,0x54);
  if (puVar3 == (undefined4 *)0x0) {
    FUN_004154b0(param_1);
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0x36;
    puVar1[6] = 0;
    (*(code *)*puVar1)(param_1);
  }
  *puVar3 = FUN_0090aa80;
  puVar3[1] = FUN_0090abc0;
  puVar3[2] = FUN_0090ac70;
  puVar3[3] = FUN_0090ad20;
  puVar3[4] = FUN_0090add0;
  puVar3[5] = FUN_0090ae40;
  puVar3[6] = FUN_0090aeb0;
  puVar3[7] = FUN_0090b1a0;
  puVar3[8] = FUN_0090b2e0;
  puVar3[9] = FUN_0090b420;
  puVar3[10] = FUN_0090b520;
  puVar3[0xc] = 1000000000;
  puVar3[0xb] = uVar2;
  puVar3[0xe] = 0;
  puVar3[0x10] = 0;
  puVar3[0xd] = 0;
  puVar3[0xf] = 0;
  param_1[1] = (int)puVar3;
  puVar3[0x11] = 0;
  puVar3[0x12] = 0;
  puVar3[0x13] = 0x54;
  return;
}


// ==== FUN_0090b620 @ 0x0090b620 ====

void FUN_0090b620(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    (**(code **)(*(int *)(param_1 + 4) + 0x24))(param_1,1);
    if (*(int *)(param_1 + 0x10) != 0) {
      *(undefined4 *)(param_1 + 0x14) = 200;
      *(undefined4 *)(param_1 + 0x134) = 0;
      return;
    }
    *(undefined4 *)(param_1 + 0x14) = 100;
  }
  return;
}


// ==== FUN_0090b660 @ 0x0090b660 ====

void FUN_0090b660(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    (**(code **)(*(int *)(param_1 + 4) + 0x28))(param_1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// ==== FUN_0090b690 @ 0x0090b690 ====

void FUN_0090b690(int param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x84);
  *(undefined4 *)(iVar1 + 0x80) = 0;
  return;
}


// ==== FUN_0090b6c0 @ 0x0090b6c0 ====

void FUN_0090b6c0(int param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x118);
  *(undefined4 *)(iVar1 + 0x114) = 0;
  return;
}


// ==== FUN_0090b6f0 @ 0x0090b6f0 ====

int FUN_0090b6f0(int param_1,int param_2)

{
  return (param_1 + -1 + param_2) / param_2;
}


// ==== FUN_0090b710 @ 0x0090b710 ====

int FUN_0090b710(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1 + -1 + param_2;
  return iVar1 - iVar1 % param_2;
}


// ==== FUN_0090b730 @ 0x0090b730 ====

void FUN_0090b730(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar1 = (undefined4 *)(param_1 + param_2 * 4);
  puVar3 = (undefined4 *)(param_3 + param_4 * 4);
  if (0 < param_5) {
    param_2 = param_5;
    do {
      puVar4 = (undefined4 *)*puVar1;
      puVar5 = (undefined4 *)*puVar3;
      for (uVar2 = param_6 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      for (uVar2 = param_6 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
      puVar1 = puVar1 + 1;
      puVar3 = puVar3 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_0090b780 @ 0x0090b780 ====

void FUN_0090b780(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  
  for (iVar1 = (param_3 & 0x1ffffff) << 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined1 *)param_2 = *(undefined1 *)param_1;
    param_1 = (undefined4 *)((int)param_1 + 1);
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  return;
}


// ==== FUN_0090b7b0 @ 0x0090b7b0 ====

void FUN_0090b7b0(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  
  for (uVar1 = param_2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  for (param_2 = param_2 & 3; param_2 != 0; param_2 = param_2 - 1) {
    *(undefined1 *)param_1 = 0;
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  return;
}


// ==== FUN_0090b7e0 @ 0x0090b7e0 ====

void FUN_0090b7e0(undefined1 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int *piVar4;
  int iVar5;
  int *unaff_ESI;
  
  puVar2 = (undefined4 *)unaff_ESI[6];
  puVar3 = (undefined1 *)*puVar2;
  *puVar3 = 0xff;
  *puVar2 = puVar3 + 1;
  piVar1 = puVar2 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    iVar5 = (*(code *)puVar2[3])();
    if (iVar5 == 0) {
      puVar2 = (undefined4 *)*unaff_ESI;
      puVar2[5] = 0x18;
      (*(code *)*puVar2)();
    }
  }
  piVar4 = (int *)unaff_ESI[6];
  puVar3 = (undefined1 *)*piVar4;
  *puVar3 = param_1;
  *piVar4 = (int)(puVar3 + 1);
  piVar1 = piVar4 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    iVar5 = (*(code *)piVar4[3])();
    if (iVar5 == 0) {
      puVar2 = (undefined4 *)*unaff_ESI;
      puVar2[5] = 0x18;
      (*(code *)*puVar2)();
    }
  }
  return;
}


// ==== FUN_0090b840 @ 0x0090b840 ====

char FUN_0090b840(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  int *piVar5;
  char *pcVar6;
  int *piVar7;
  char cVar8;
  ushort *puVar9;
  int iVar10;
  int *unaff_ESI;
  int *piVar11;
  
  iVar2 = unaff_ESI[param_1 + 0x12];
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)*unaff_ESI;
    puVar3[5] = 0x34;
    puVar3[6] = param_1;
    (*(code *)*puVar3)();
  }
  cVar8 = '\0';
  puVar9 = (ushort *)(iVar2 + 4);
  iVar10 = 0x10;
  do {
    if (0xff < puVar9[-2]) {
      cVar8 = '\x01';
    }
    if (0xff < puVar9[-1]) {
      cVar8 = '\x01';
    }
    if (0xff < *puVar9) {
      cVar8 = '\x01';
    }
    if (0xff < puVar9[1]) {
      cVar8 = '\x01';
    }
    puVar9 = puVar9 + 4;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  if (*(int *)(iVar2 + 0x80) == 0) {
    puVar3 = (undefined4 *)unaff_ESI[6];
    puVar4 = (undefined1 *)*puVar3;
    *puVar4 = 0xff;
    *puVar3 = puVar4 + 1;
    piVar11 = puVar3 + 1;
    *piVar11 = *piVar11 + -1;
    if ((*piVar11 == 0) && (iVar10 = (*(code *)puVar3[3])(), iVar10 == 0)) {
      puVar3 = (undefined4 *)*unaff_ESI;
      puVar3[5] = 0x18;
      (*(code *)*puVar3)();
    }
    puVar3 = (undefined4 *)unaff_ESI[6];
    puVar4 = (undefined1 *)*puVar3;
    *puVar4 = 0xdb;
    *puVar3 = puVar4 + 1;
    piVar11 = puVar3 + 1;
    *piVar11 = *piVar11 + -1;
    if ((*piVar11 == 0) && (iVar10 = (*(code *)puVar3[3])(), iVar10 == 0)) {
      puVar3 = (undefined4 *)*unaff_ESI;
      puVar3[5] = 0x18;
      (*(code *)*puVar3)();
    }
    puVar3 = (undefined4 *)unaff_ESI[6];
    puVar4 = (undefined1 *)*puVar3;
    *puVar4 = 0;
    iVar10 = puVar3[1];
    *puVar3 = puVar4 + 1;
    puVar3[1] = iVar10 + -1;
    if ((iVar10 + -1 == 0) && (iVar10 = (*(code *)puVar3[3])(), iVar10 == 0)) {
      puVar3 = (undefined4 *)*unaff_ESI;
      puVar3[5] = 0x18;
      (*(code *)*puVar3)();
    }
    piVar5 = (int *)unaff_ESI[6];
    pcVar6 = (char *)*piVar5;
    *pcVar6 = (-(cVar8 != '\0') & 0x40U) + 0x43;
    *piVar5 = (int)(pcVar6 + 1);
    piVar11 = piVar5 + 1;
    *piVar11 = *piVar11 + -1;
    if ((*piVar11 == 0) && (iVar10 = (*(code *)piVar5[3])(), iVar10 == 0)) {
      puVar3 = (undefined4 *)*unaff_ESI;
      puVar3[5] = 0x18;
      (*(code *)*puVar3)();
    }
    piVar5 = (int *)unaff_ESI[6];
    pcVar6 = (char *)*piVar5;
    *pcVar6 = cVar8 * '\x10' + (char)param_1;
    *piVar5 = (int)(pcVar6 + 1);
    piVar11 = piVar5 + 1;
    *piVar11 = *piVar11 + -1;
    if ((*piVar11 == 0) && (iVar10 = (*(code *)piVar5[3])(), iVar10 == 0)) {
      puVar3 = (undefined4 *)*unaff_ESI;
      puVar3[5] = 0x18;
      (*(code *)*puVar3)();
    }
    piVar11 = &DAT_00a28750;
    do {
      uVar1 = *(undefined2 *)(iVar2 + *piVar11 * 2);
      if (cVar8 != '\0') {
        piVar7 = (int *)unaff_ESI[6];
        puVar4 = (undefined1 *)*piVar7;
        *puVar4 = (char)((ushort)uVar1 >> 8);
        *piVar7 = (int)(puVar4 + 1);
        piVar5 = piVar7 + 1;
        *piVar5 = *piVar5 + -1;
        if ((*piVar5 == 0) && (iVar10 = (*(code *)piVar7[3])(), iVar10 == 0)) {
          puVar3 = (undefined4 *)*unaff_ESI;
          puVar3[5] = 0x18;
          (*(code *)*puVar3)();
        }
      }
      piVar7 = (int *)unaff_ESI[6];
      puVar4 = (undefined1 *)*piVar7;
      *puVar4 = (char)uVar1;
      *piVar7 = (int)(puVar4 + 1);
      piVar5 = piVar7 + 1;
      *piVar5 = *piVar5 + -1;
      if ((*piVar5 == 0) && (iVar10 = (*(code *)piVar7[3])(), iVar10 == 0)) {
        puVar3 = (undefined4 *)*unaff_ESI;
        puVar3[5] = 0x18;
        (*(code *)*puVar3)();
      }
      piVar11 = piVar11 + 1;
    } while ((int)piVar11 < 0xa28850);
    *(undefined4 *)(iVar2 + 0x80) = 1;
  }
  return cVar8;
}


// ==== FUN_0090ba10 @ 0x0090ba10 ====

void FUN_0090ba10(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined1 *puVar4;
  int in_EAX;
  byte *pbVar5;
  int iVar6;
  int *in_ECX;
  int iVar7;
  int local_c;
  int local_8;
  
  if (in_EAX == 0) {
    local_c = in_ECX[param_1 + 0x16];
  }
  else {
    local_c = in_ECX[param_1 + 0x1a];
    param_1 = param_1 + 0x10;
  }
  if (local_c == 0) {
    puVar2 = (undefined4 *)*in_ECX;
    puVar2[5] = 0x32;
    puVar2[6] = param_1;
    (*(code *)*puVar2)();
  }
  if (*(int *)(local_c + 0x114) == 0) {
    FUN_0090b7e0(0xc4);
    local_8 = 0;
    pbVar5 = (byte *)(local_c + 3);
    iVar7 = 4;
    do {
      local_8 = (uint)*pbVar5 + local_8 + (uint)pbVar5[-2] + (uint)pbVar5[-1] + (uint)pbVar5[1];
      pbVar5 = pbVar5 + 4;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    piVar3 = (int *)in_ECX[6];
    puVar4 = (undefined1 *)*piVar3;
    *puVar4 = (char)((uint)(local_8 + 0x13) >> 8);
    *piVar3 = (int)(puVar4 + 1);
    piVar1 = piVar3 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      iVar7 = (*(code *)piVar3[3])();
      if (iVar7 == 0) {
        puVar2 = (undefined4 *)*in_ECX;
        puVar2[5] = 0x18;
        (*(code *)*puVar2)();
      }
    }
    piVar3 = (int *)in_ECX[6];
    puVar4 = (undefined1 *)*piVar3;
    *puVar4 = (char)(local_8 + 0x13);
    *piVar3 = (int)(puVar4 + 1);
    piVar1 = piVar3 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      iVar7 = (*(code *)piVar3[3])();
      if (iVar7 == 0) {
        puVar2 = (undefined4 *)*in_ECX;
        puVar2[5] = 0x18;
        (*(code *)*puVar2)();
      }
    }
    piVar3 = (int *)in_ECX[6];
    puVar4 = (undefined1 *)*piVar3;
    *puVar4 = (undefined1)param_1;
    *piVar3 = (int)(puVar4 + 1);
    piVar1 = piVar3 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      iVar7 = (*(code *)piVar3[3])();
      if (iVar7 == 0) {
        puVar2 = (undefined4 *)*in_ECX;
        puVar2[5] = 0x18;
        (*(code *)*puVar2)();
      }
    }
    iVar7 = 1;
    do {
      puVar2 = (undefined4 *)in_ECX[6];
      puVar4 = (undefined1 *)*puVar2;
      *puVar4 = *(undefined1 *)(iVar7 + local_c);
      *puVar2 = puVar4 + 1;
      piVar1 = puVar2 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        iVar6 = (*(code *)puVar2[3])();
        if (iVar6 == 0) {
          puVar2 = (undefined4 *)*in_ECX;
          puVar2[5] = 0x18;
          (*(code *)*puVar2)();
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x11);
    iVar7 = 0;
    if (0 < local_8) {
      do {
        puVar2 = (undefined4 *)in_ECX[6];
        puVar4 = (undefined1 *)*puVar2;
        *puVar4 = *(undefined1 *)(local_c + 0x11 + iVar7);
        *puVar2 = puVar4 + 1;
        piVar1 = puVar2 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          iVar6 = (*(code *)puVar2[3])();
          if (iVar6 == 0) {
            puVar2 = (undefined4 *)*in_ECX;
            puVar2[5] = 0x18;
            (*(code *)*puVar2)();
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < local_8);
    }
    *(undefined4 *)(local_c + 0x114) = 1;
  }
  return;
}


// ==== FUN_0090bba0 @ 0x0090bba0 ====

void FUN_0090bba0(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int *piVar3;
  int *piVar4;
  int *in_EAX;
  int iVar5;
  int iVar6;
  
  FUN_0090b7e0(0xdd);
  puVar1 = (undefined4 *)in_EAX[6];
  puVar2 = (undefined1 *)*puVar1;
  *puVar2 = 0;
  *puVar1 = puVar2 + 1;
  piVar4 = puVar1 + 1;
  *piVar4 = *piVar4 + -1;
  if (*piVar4 == 0) {
    iVar5 = (*(code *)puVar1[3])();
    if (iVar5 == 0) {
      puVar1 = (undefined4 *)*in_EAX;
      puVar1[5] = 0x18;
      (*(code *)*puVar1)();
    }
  }
  puVar1 = (undefined4 *)in_EAX[6];
  puVar2 = (undefined1 *)*puVar1;
  *puVar2 = 4;
  *puVar1 = puVar2 + 1;
  piVar4 = puVar1 + 1;
  *piVar4 = *piVar4 + -1;
  if (*piVar4 == 0) {
    iVar5 = (*(code *)puVar1[3])();
    if (iVar5 == 0) {
      puVar1 = (undefined4 *)*in_EAX;
      puVar1[5] = 0x18;
      (*(code *)*puVar1)();
    }
  }
  piVar3 = (int *)in_EAX[6];
  puVar2 = (undefined1 *)*piVar3;
  iVar5 = in_EAX[0x32];
  *puVar2 = (char)((uint)iVar5 >> 8);
  *piVar3 = (int)(puVar2 + 1);
  piVar4 = piVar3 + 1;
  *piVar4 = *piVar4 + -1;
  if (*piVar4 == 0) {
    iVar6 = (*(code *)piVar3[3])();
    if (iVar6 == 0) {
      puVar1 = (undefined4 *)*in_EAX;
      puVar1[5] = 0x18;
      (*(code *)*puVar1)();
    }
  }
  piVar4 = (int *)in_EAX[6];
  puVar2 = (undefined1 *)*piVar4;
  *puVar2 = (char)iVar5;
  *piVar4 = (int)(puVar2 + 1);
  iVar5 = piVar4[1];
  piVar4[1] = iVar5 + -1;
  if (iVar5 + -1 == 0) {
    iVar5 = (*(code *)piVar4[3])();
    if (iVar5 == 0) {
      puVar1 = (undefined4 *)*in_EAX;
      puVar1[5] = 0x18;
      (*(code *)*puVar1)();
    }
  }
  return;
}


// ==== FUN_0090bc50 @ 0x0090bc50 ====

void FUN_0090bc50(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined4 in_EAX;
  int iVar6;
  int iVar7;
  int *in_ECX;
  undefined1 *puVar8;
  int local_8;
  
  FUN_0090b7e0(in_EAX);
  iVar7 = in_ECX[0xf] * 3 + 8;
  piVar2 = (int *)in_ECX[6];
  puVar8 = (undefined1 *)*piVar2;
  *puVar8 = (char)((uint)iVar7 >> 8);
  *piVar2 = (int)(puVar8 + 1);
  piVar1 = piVar2 + 1;
  *piVar1 = *piVar1 + -1;
  if ((*piVar1 == 0) && (iVar6 = (*(code *)piVar2[3])(), iVar6 == 0)) {
    puVar3 = (undefined4 *)*in_ECX;
    puVar3[5] = 0x18;
    (*(code *)*puVar3)();
  }
  piVar2 = (int *)in_ECX[6];
  puVar8 = (undefined1 *)*piVar2;
  *puVar8 = (char)iVar7;
  *piVar2 = (int)(puVar8 + 1);
  piVar1 = piVar2 + 1;
  *piVar1 = *piVar1 + -1;
  if ((*piVar1 == 0) && (iVar7 = (*(code *)piVar2[3])(), iVar7 == 0)) {
    puVar3 = (undefined4 *)*in_ECX;
    puVar3[5] = 0x18;
    (*(code *)*puVar3)();
  }
  if ((0xffff < in_ECX[8]) || (0xffff < in_ECX[7])) {
    puVar3 = (undefined4 *)*in_ECX;
    puVar3[5] = 0x29;
    puVar3[6] = 0xffff;
    (*(code *)*puVar3)();
  }
  puVar3 = (undefined4 *)in_ECX[6];
  puVar8 = (undefined1 *)*puVar3;
  *puVar8 = (char)in_ECX[0xe];
  *puVar3 = puVar8 + 1;
  piVar1 = puVar3 + 1;
  *piVar1 = *piVar1 + -1;
  if ((*piVar1 == 0) && (iVar7 = (*(code *)puVar3[3])(), iVar7 == 0)) {
    puVar3 = (undefined4 *)*in_ECX;
    puVar3[5] = 0x18;
    (*(code *)*puVar3)();
  }
  piVar2 = (int *)in_ECX[6];
  iVar7 = in_ECX[8];
  puVar8 = (undefined1 *)*piVar2;
  *puVar8 = (char)((uint)iVar7 >> 8);
  *piVar2 = (int)(puVar8 + 1);
  piVar1 = piVar2 + 1;
  *piVar1 = *piVar1 + -1;
  if ((*piVar1 == 0) && (iVar6 = (*(code *)piVar2[3])(), iVar6 == 0)) {
    puVar3 = (undefined4 *)*in_ECX;
    puVar3[5] = 0x18;
    (*(code *)*puVar3)();
  }
  piVar2 = (int *)in_ECX[6];
  puVar8 = (undefined1 *)*piVar2;
  *puVar8 = (char)iVar7;
  *piVar2 = (int)(puVar8 + 1);
  piVar1 = piVar2 + 1;
  *piVar1 = *piVar1 + -1;
  if ((*piVar1 == 0) && (iVar7 = (*(code *)piVar2[3])(), iVar7 == 0)) {
    puVar3 = (undefined4 *)*in_ECX;
    puVar3[5] = 0x18;
    (*(code *)*puVar3)();
  }
  piVar2 = (int *)in_ECX[6];
  iVar7 = in_ECX[7];
  puVar8 = (undefined1 *)*piVar2;
  *puVar8 = (char)((uint)iVar7 >> 8);
  *piVar2 = (int)(puVar8 + 1);
  piVar1 = piVar2 + 1;
  *piVar1 = *piVar1 + -1;
  if ((*piVar1 == 0) && (iVar6 = (*(code *)piVar2[3])(), iVar6 == 0)) {
    puVar3 = (undefined4 *)*in_ECX;
    puVar3[5] = 0x18;
    (*(code *)*puVar3)();
  }
  piVar2 = (int *)in_ECX[6];
  puVar8 = (undefined1 *)*piVar2;
  *puVar8 = (char)iVar7;
  *piVar2 = (int)(puVar8 + 1);
  piVar1 = piVar2 + 1;
  *piVar1 = *piVar1 + -1;
  if ((*piVar1 == 0) && (iVar7 = (*(code *)piVar2[3])(), iVar7 == 0)) {
    puVar3 = (undefined4 *)*in_ECX;
    puVar3[5] = 0x18;
    (*(code *)*puVar3)();
  }
  puVar3 = (undefined4 *)in_ECX[6];
  puVar8 = (undefined1 *)*puVar3;
  *puVar8 = (char)in_ECX[0xf];
  *puVar3 = puVar8 + 1;
  piVar1 = puVar3 + 1;
  *piVar1 = *piVar1 + -1;
  if ((*piVar1 == 0) && (iVar7 = (*(code *)puVar3[3])(), iVar7 == 0)) {
    puVar3 = (undefined4 *)*in_ECX;
    puVar3[5] = 0x18;
    (*(code *)*puVar3)();
  }
  puVar8 = (undefined1 *)in_ECX[0x11];
  local_8 = 0;
  if (0 < in_ECX[0xf]) {
    do {
      puVar3 = (undefined4 *)in_ECX[6];
      puVar4 = (undefined1 *)*puVar3;
      *puVar4 = *puVar8;
      *puVar3 = puVar4 + 1;
      piVar1 = puVar3 + 1;
      *piVar1 = *piVar1 + -1;
      if ((*piVar1 == 0) && (iVar7 = (*(code *)puVar3[3])(), iVar7 == 0)) {
        puVar3 = (undefined4 *)*in_ECX;
        puVar3[5] = 0x18;
        (*(code *)*puVar3)();
      }
      piVar2 = (int *)in_ECX[6];
      pcVar5 = (char *)*piVar2;
      *pcVar5 = puVar8[8] * '\x10' + puVar8[0xc];
      *piVar2 = (int)(pcVar5 + 1);
      piVar1 = piVar2 + 1;
      *piVar1 = *piVar1 + -1;
      if ((*piVar1 == 0) && (iVar7 = (*(code *)piVar2[3])(), iVar7 == 0)) {
        puVar3 = (undefined4 *)*in_ECX;
        puVar3[5] = 0x18;
        (*(code *)*puVar3)();
      }
      puVar3 = (undefined4 *)in_ECX[6];
      puVar4 = (undefined1 *)*puVar3;
      *puVar4 = puVar8[0x10];
      *puVar3 = puVar4 + 1;
      piVar1 = puVar3 + 1;
      *piVar1 = *piVar1 + -1;
      if ((*piVar1 == 0) && (iVar7 = (*(code *)puVar3[3])(), iVar7 == 0)) {
        puVar3 = (undefined4 *)*in_ECX;
        puVar3[5] = 0x18;
        (*(code *)*puVar3)();
      }
      local_8 = local_8 + 1;
      puVar8 = puVar8 + 0x54;
    } while (local_8 < in_ECX[0xf]);
  }
  return;
}


// ==== FUN_0090be50 @ 0x0090be50 ====

void FUN_0090be50(void)

{
  int *piVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  char *pcVar5;
  char cVar6;
  int *in_EAX;
  int iVar7;
  int iVar8;
  char cVar9;
  char cVar10;
  int *piVar11;
  int local_8;
  
  FUN_0090b7e0(0xda);
  piVar1 = (int *)in_EAX[6];
  puVar2 = (undefined1 *)*piVar1;
  iVar8 = in_EAX[0x3f] * 2 + 6;
  *puVar2 = (char)((uint)iVar8 >> 8);
  *piVar1 = (int)(puVar2 + 1);
  piVar11 = piVar1 + 1;
  *piVar11 = *piVar11 + -1;
  if ((*piVar11 == 0) && (iVar7 = (*(code *)piVar1[3])(), iVar7 == 0)) {
    puVar3 = (undefined4 *)*in_EAX;
    puVar3[5] = 0x18;
    (*(code *)*puVar3)();
  }
  piVar1 = (int *)in_EAX[6];
  puVar2 = (undefined1 *)*piVar1;
  *puVar2 = (char)iVar8;
  *piVar1 = (int)(puVar2 + 1);
  piVar11 = piVar1 + 1;
  *piVar11 = *piVar11 + -1;
  if ((*piVar11 == 0) && (iVar8 = (*(code *)piVar1[3])(), iVar8 == 0)) {
    puVar3 = (undefined4 *)*in_EAX;
    puVar3[5] = 0x18;
    (*(code *)*puVar3)();
  }
  puVar3 = (undefined4 *)in_EAX[6];
  puVar2 = (undefined1 *)*puVar3;
  *puVar2 = (char)in_EAX[0x3f];
  *puVar3 = puVar2 + 1;
  piVar11 = puVar3 + 1;
  *piVar11 = *piVar11 + -1;
  if ((*piVar11 == 0) && (iVar8 = (*(code *)puVar3[3])(), iVar8 == 0)) {
    puVar3 = (undefined4 *)*in_EAX;
    puVar3[5] = 0x18;
    (*(code *)*puVar3)();
  }
  local_8 = 0;
  if (0 < in_EAX[0x3f]) {
    piVar11 = in_EAX + 0x40;
    do {
      puVar3 = (undefined4 *)in_EAX[6];
      puVar2 = (undefined1 *)*piVar11;
      puVar4 = (undefined1 *)*puVar3;
      *puVar4 = *puVar2;
      *puVar3 = puVar4 + 1;
      piVar1 = puVar3 + 1;
      *piVar1 = *piVar1 + -1;
      if ((*piVar1 == 0) && (iVar8 = (*(code *)puVar3[3])(), iVar8 == 0)) {
        puVar3 = (undefined4 *)*in_EAX;
        puVar3[5] = 0x18;
        (*(code *)*puVar3)();
      }
      cVar9 = (char)*(undefined4 *)(puVar2 + 0x14);
      cVar10 = (char)*(undefined4 *)(puVar2 + 0x18);
      if (in_EAX[0x3b] != 0) {
        cVar6 = cVar10;
        if (in_EAX[0x51] == 0) {
          cVar10 = '\0';
          if ((in_EAX[0x53] == 0) || (cVar6 = '\0', in_EAX[0x2d] != 0)) goto LAB_0090bf50;
        }
        cVar10 = cVar6;
        cVar9 = '\0';
      }
LAB_0090bf50:
      piVar1 = (int *)in_EAX[6];
      pcVar5 = (char *)*piVar1;
      *pcVar5 = cVar9 * '\x10' + cVar10;
      iVar8 = piVar1[1];
      *piVar1 = (int)(pcVar5 + 1);
      piVar1[1] = iVar8 + -1;
      if ((iVar8 + -1 == 0) && (iVar8 = (*(code *)piVar1[3])(), iVar8 == 0)) {
        puVar3 = (undefined4 *)*in_EAX;
        puVar3[5] = 0x18;
        (*(code *)*puVar3)();
      }
      local_8 = local_8 + 1;
      piVar11 = piVar11 + 1;
    } while (local_8 < in_EAX[0x3f]);
  }
  puVar3 = (undefined4 *)in_EAX[6];
  puVar2 = (undefined1 *)*puVar3;
  *puVar2 = (char)in_EAX[0x51];
  *puVar3 = puVar2 + 1;
  piVar11 = puVar3 + 1;
  *piVar11 = *piVar11 + -1;
  if ((*piVar11 == 0) && (iVar8 = (*(code *)puVar3[3])(), iVar8 == 0)) {
    puVar3 = (undefined4 *)*in_EAX;
    puVar3[5] = 0x18;
    (*(code *)*puVar3)();
  }
  puVar3 = (undefined4 *)in_EAX[6];
  puVar2 = (undefined1 *)*puVar3;
  *puVar2 = (char)in_EAX[0x52];
  *puVar3 = puVar2 + 1;
  piVar11 = puVar3 + 1;
  *piVar11 = *piVar11 + -1;
  if ((*piVar11 == 0) && (iVar8 = (*(code *)puVar3[3])(), iVar8 == 0)) {
    puVar3 = (undefined4 *)*in_EAX;
    puVar3[5] = 0x18;
    (*(code *)*puVar3)();
  }
  piVar1 = (int *)in_EAX[6];
  pcVar5 = (char *)*piVar1;
  *pcVar5 = (char)in_EAX[0x53] * '\x10' + (char)in_EAX[0x54];
  *piVar1 = (int)(pcVar5 + 1);
  piVar11 = piVar1 + 1;
  *piVar11 = *piVar11 + -1;
  if ((*piVar11 == 0) && (iVar8 = (*(code *)piVar1[3])(), iVar8 == 0)) {
    puVar3 = (undefined4 *)*in_EAX;
    puVar3[5] = 0x18;
    (*(code *)*puVar3)();
  }
  return;
}


// ==== FUN_0090c020 @ 0x0090c020 ====

void FUN_0090c020(void)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int *piVar4;
  int *piVar5;
  int *in_EAX;
  int iVar6;
  int iVar7;
  
  FUN_0090b7e0(0xe0);
  puVar2 = (undefined4 *)in_EAX[6];
  puVar3 = (undefined1 *)*puVar2;
  *puVar3 = 0;
  *puVar2 = puVar3 + 1;
  piVar5 = puVar2 + 1;
  *piVar5 = *piVar5 + -1;
  if (*piVar5 == 0) {
    iVar6 = (*(code *)puVar2[3])();
    if (iVar6 == 0) {
      puVar2 = (undefined4 *)*in_EAX;
      puVar2[5] = 0x18;
      (*(code *)*puVar2)();
    }
  }
  puVar2 = (undefined4 *)in_EAX[6];
  puVar3 = (undefined1 *)*puVar2;
  *puVar3 = 0x10;
  *puVar2 = puVar3 + 1;
  piVar5 = puVar2 + 1;
  *piVar5 = *piVar5 + -1;
  if (*piVar5 == 0) {
    iVar6 = (*(code *)puVar2[3])();
    if (iVar6 == 0) {
      puVar2 = (undefined4 *)*in_EAX;
      puVar2[5] = 0x18;
      (*(code *)*puVar2)();
    }
  }
  puVar2 = (undefined4 *)in_EAX[6];
  puVar3 = (undefined1 *)*puVar2;
  *puVar3 = 0x4a;
  *puVar2 = puVar3 + 1;
  piVar5 = puVar2 + 1;
  *piVar5 = *piVar5 + -1;
  if (*piVar5 == 0) {
    iVar6 = (*(code *)puVar2[3])();
    if (iVar6 == 0) {
      puVar2 = (undefined4 *)*in_EAX;
      puVar2[5] = 0x18;
      (*(code *)*puVar2)();
    }
  }
  puVar2 = (undefined4 *)in_EAX[6];
  puVar3 = (undefined1 *)*puVar2;
  *puVar3 = 0x46;
  *puVar2 = puVar3 + 1;
  piVar5 = puVar2 + 1;
  *piVar5 = *piVar5 + -1;
  if (*piVar5 == 0) {
    iVar6 = (*(code *)puVar2[3])();
    if (iVar6 == 0) {
      puVar2 = (undefined4 *)*in_EAX;
      puVar2[5] = 0x18;
      (*(code *)*puVar2)();
    }
  }
  puVar2 = (undefined4 *)in_EAX[6];
  puVar3 = (undefined1 *)*puVar2;
  *puVar3 = 0x49;
  *puVar2 = puVar3 + 1;
  piVar5 = puVar2 + 1;
  *piVar5 = *piVar5 + -1;
  if (*piVar5 == 0) {
    iVar6 = (*(code *)puVar2[3])();
    if (iVar6 == 0) {
      puVar2 = (undefined4 *)*in_EAX;
      puVar2[5] = 0x18;
      (*(code *)*puVar2)();
    }
  }
  puVar2 = (undefined4 *)in_EAX[6];
  puVar3 = (undefined1 *)*puVar2;
  *puVar3 = 0x46;
  *puVar2 = puVar3 + 1;
  piVar5 = puVar2 + 1;
  *piVar5 = *piVar5 + -1;
  if (*piVar5 == 0) {
    iVar6 = (*(code *)puVar2[3])();
    if (iVar6 == 0) {
      puVar2 = (undefined4 *)*in_EAX;
      puVar2[5] = 0x18;
      (*(code *)*puVar2)();
    }
  }
  puVar2 = (undefined4 *)in_EAX[6];
  puVar3 = (undefined1 *)*puVar2;
  *puVar3 = 0;
  *puVar2 = puVar3 + 1;
  piVar5 = puVar2 + 1;
  *piVar5 = *piVar5 + -1;
  if (*piVar5 == 0) {
    iVar6 = (*(code *)puVar2[3])();
    if (iVar6 == 0) {
      puVar2 = (undefined4 *)*in_EAX;
      puVar2[5] = 0x18;
      (*(code *)*puVar2)();
    }
  }
  puVar2 = (undefined4 *)in_EAX[6];
  puVar3 = (undefined1 *)*puVar2;
  *puVar3 = (char)in_EAX[0x35];
  *puVar2 = puVar3 + 1;
  piVar5 = puVar2 + 1;
  *piVar5 = *piVar5 + -1;
  if (*piVar5 == 0) {
    iVar6 = (*(code *)puVar2[3])();
    if (iVar6 == 0) {
      puVar2 = (undefined4 *)*in_EAX;
      puVar2[5] = 0x18;
      (*(code *)*puVar2)();
    }
  }
  puVar2 = (undefined4 *)in_EAX[6];
  puVar3 = (undefined1 *)*puVar2;
  *puVar3 = *(undefined1 *)((int)in_EAX + 0xd5);
  *puVar2 = puVar3 + 1;
  piVar5 = puVar2 + 1;
  *piVar5 = *piVar5 + -1;
  if (*piVar5 == 0) {
    iVar6 = (*(code *)puVar2[3])();
    if (iVar6 == 0) {
      puVar2 = (undefined4 *)*in_EAX;
      puVar2[5] = 0x18;
      (*(code *)*puVar2)();
    }
  }
  puVar2 = (undefined4 *)in_EAX[6];
  puVar3 = (undefined1 *)*puVar2;
  *puVar3 = *(undefined1 *)((int)in_EAX + 0xd6);
  *puVar2 = puVar3 + 1;
  piVar5 = puVar2 + 1;
  *piVar5 = *piVar5 + -1;
  if (*piVar5 == 0) {
    iVar6 = (*(code *)puVar2[3])();
    if (iVar6 == 0) {
      puVar2 = (undefined4 *)*in_EAX;
      puVar2[5] = 0x18;
      (*(code *)*puVar2)();
    }
  }
  piVar4 = (int *)in_EAX[6];
  puVar3 = (undefined1 *)*piVar4;
  iVar6 = in_EAX[0x36];
  *puVar3 = (char)((uint)iVar6 >> 8);
  *piVar4 = (int)(puVar3 + 1);
  piVar5 = piVar4 + 1;
  *piVar5 = *piVar5 + -1;
  if (*piVar5 == 0) {
    iVar7 = (*(code *)piVar4[3])();
    if (iVar7 == 0) {
      puVar2 = (undefined4 *)*in_EAX;
      puVar2[5] = 0x18;
      (*(code *)*puVar2)();
    }
  }
  piVar4 = (int *)in_EAX[6];
  puVar3 = (undefined1 *)*piVar4;
  *puVar3 = (char)iVar6;
  *piVar4 = (int)(puVar3 + 1);
  piVar5 = piVar4 + 1;
  *piVar5 = *piVar5 + -1;
  if (*piVar5 == 0) {
    iVar6 = (*(code *)piVar4[3])();
    if (iVar6 == 0) {
      puVar2 = (undefined4 *)*in_EAX;
      puVar2[5] = 0x18;
      (*(code *)*puVar2)();
    }
  }
  uVar1 = *(undefined2 *)((int)in_EAX + 0xda);
  piVar4 = (int *)in_EAX[6];
  puVar3 = (undefined1 *)*piVar4;
  *puVar3 = (char)((ushort)uVar1 >> 8);
  *piVar4 = (int)(puVar3 + 1);
  piVar5 = piVar4 + 1;
  *piVar5 = *piVar5 + -1;
  if (*piVar5 == 0) {
    iVar6 = (*(code *)piVar4[3])();
    if (iVar6 == 0) {
      puVar2 = (undefined4 *)*in_EAX;
      puVar2[5] = 0x18;
      (*(code *)*puVar2)();
    }
  }
  piVar5 = (int *)in_EAX[6];
  puVar3 = (undefined1 *)*piVar5;
  *puVar3 = (char)uVar1;
  *piVar5 = (int)(puVar3 + 1);
  iVar6 = piVar5[1];
  piVar5[1] = iVar6 + -1;
  if (iVar6 + -1 == 0) {
    iVar6 = (*(code *)piVar5[3])();
    if (iVar6 == 0) {
      puVar2 = (undefined4 *)*in_EAX;
      puVar2[5] = 0x18;
      (*(code *)*puVar2)();
    }
  }
  puVar2 = (undefined4 *)in_EAX[6];
  puVar3 = (undefined1 *)*puVar2;
  *puVar3 = 0;
  *puVar2 = puVar3 + 1;
  piVar5 = puVar2 + 1;
  *piVar5 = *piVar5 + -1;
  if (*piVar5 == 0) {
    iVar6 = (*(code *)puVar2[3])();
    if (iVar6 == 0) {
      puVar2 = (undefined4 *)*in_EAX;
      puVar2[5] = 0x18;
      (*(code *)*puVar2)();
    }
  }
  puVar2 = (undefined4 *)in_EAX[6];
  puVar3 = (undefined1 *)*puVar2;
  *puVar3 = 0;
  *puVar2 = puVar3 + 1;
  piVar5 = puVar2 + 1;
  *piVar5 = *piVar5 + -1;
  if (*piVar5 == 0) {
    iVar6 = (*(code *)puVar2[3])();
    if (iVar6 == 0) {
      puVar2 = (undefined4 *)*in_EAX;
      puVar2[5] = 0x18;
      (*(code *)*puVar2)();
    }
  }
  return;
}


// ==== FUN_0090c270 @ 0x0090c270 ====

void FUN_0090c270(void)

{
  int *piVar1;
  int *in_EAX;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  
  FUN_0090b7e0(0xee);
  puVar3 = (undefined4 *)in_EAX[6];
  puVar4 = (undefined1 *)*puVar3;
  *puVar4 = 0;
  *puVar3 = puVar4 + 1;
  piVar1 = puVar3 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    iVar2 = (*(code *)puVar3[3])();
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)*in_EAX;
      puVar3[5] = 0x18;
      (*(code *)*puVar3)();
    }
  }
  puVar3 = (undefined4 *)in_EAX[6];
  puVar4 = (undefined1 *)*puVar3;
  *puVar4 = 0xe;
  *puVar3 = puVar4 + 1;
  piVar1 = puVar3 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    iVar2 = (*(code *)puVar3[3])();
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)*in_EAX;
      puVar3[5] = 0x18;
      (*(code *)*puVar3)();
    }
  }
  puVar3 = (undefined4 *)in_EAX[6];
  puVar4 = (undefined1 *)*puVar3;
  *puVar4 = 0x41;
  *puVar3 = puVar4 + 1;
  piVar1 = puVar3 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    iVar2 = (*(code *)puVar3[3])();
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)*in_EAX;
      puVar3[5] = 0x18;
      (*(code *)*puVar3)();
    }
  }
  puVar3 = (undefined4 *)in_EAX[6];
  puVar4 = (undefined1 *)*puVar3;
  *puVar4 = 100;
  *puVar3 = puVar4 + 1;
  piVar1 = puVar3 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    iVar2 = (*(code *)puVar3[3])();
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)*in_EAX;
      puVar3[5] = 0x18;
      (*(code *)*puVar3)();
    }
  }
  puVar3 = (undefined4 *)in_EAX[6];
  puVar4 = (undefined1 *)*puVar3;
  *puVar4 = 0x6f;
  *puVar3 = puVar4 + 1;
  piVar1 = puVar3 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    iVar2 = (*(code *)puVar3[3])();
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)*in_EAX;
      puVar3[5] = 0x18;
      (*(code *)*puVar3)();
    }
  }
  puVar3 = (undefined4 *)in_EAX[6];
  puVar4 = (undefined1 *)*puVar3;
  *puVar4 = 0x62;
  *puVar3 = puVar4 + 1;
  piVar1 = puVar3 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    iVar2 = (*(code *)puVar3[3])();
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)*in_EAX;
      puVar3[5] = 0x18;
      (*(code *)*puVar3)();
    }
  }
  puVar3 = (undefined4 *)in_EAX[6];
  puVar4 = (undefined1 *)*puVar3;
  *puVar4 = 0x65;
  *puVar3 = puVar4 + 1;
  piVar1 = puVar3 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    iVar2 = (*(code *)puVar3[3])();
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)*in_EAX;
      puVar3[5] = 0x18;
      (*(code *)*puVar3)();
    }
  }
  puVar3 = (undefined4 *)in_EAX[6];
  puVar4 = (undefined1 *)*puVar3;
  *puVar4 = 0;
  *puVar3 = puVar4 + 1;
  piVar1 = puVar3 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    iVar2 = (*(code *)puVar3[3])();
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)*in_EAX;
      puVar3[5] = 0x18;
      (*(code *)*puVar3)();
    }
  }
  puVar3 = (undefined4 *)in_EAX[6];
  puVar4 = (undefined1 *)*puVar3;
  *puVar4 = 100;
  *puVar3 = puVar4 + 1;
  piVar1 = puVar3 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    iVar2 = (*(code *)puVar3[3])();
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)*in_EAX;
      puVar3[5] = 0x18;
      (*(code *)*puVar3)();
    }
  }
  puVar3 = (undefined4 *)in_EAX[6];
  puVar4 = (undefined1 *)*puVar3;
  *puVar4 = 0;
  *puVar3 = puVar4 + 1;
  piVar1 = puVar3 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    iVar2 = (*(code *)puVar3[3])();
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)*in_EAX;
      puVar3[5] = 0x18;
      (*(code *)*puVar3)();
    }
  }
  puVar3 = (undefined4 *)in_EAX[6];
  puVar4 = (undefined1 *)*puVar3;
  *puVar4 = 0;
  *puVar3 = puVar4 + 1;
  piVar1 = puVar3 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    iVar2 = (*(code *)puVar3[3])();
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)*in_EAX;
      puVar3[5] = 0x18;
      (*(code *)*puVar3)();
    }
  }
  puVar3 = (undefined4 *)in_EAX[6];
  puVar4 = (undefined1 *)*puVar3;
  *puVar4 = 0;
  *puVar3 = puVar4 + 1;
  piVar1 = puVar3 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    iVar2 = (*(code *)puVar3[3])();
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)*in_EAX;
      puVar3[5] = 0x18;
      (*(code *)*puVar3)();
    }
  }
  puVar3 = (undefined4 *)in_EAX[6];
  puVar4 = (undefined1 *)*puVar3;
  *puVar4 = 0;
  *puVar3 = puVar4 + 1;
  piVar1 = puVar3 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    iVar2 = (*(code *)puVar3[3])();
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)*in_EAX;
      puVar3[5] = 0x18;
      (*(code *)*puVar3)();
    }
  }
  if (in_EAX[0x10] == 3) {
    puVar3 = (undefined4 *)in_EAX[6];
    puVar4 = (undefined1 *)*puVar3;
    *puVar4 = 1;
  }
  else {
    puVar3 = (undefined4 *)in_EAX[6];
    puVar4 = (undefined1 *)*puVar3;
    if (in_EAX[0x10] == 5) {
      *puVar4 = 2;
    }
    else {
      *puVar4 = 0;
    }
  }
  *puVar3 = puVar4 + 1;
  piVar1 = puVar3 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    iVar2 = (*(code *)puVar3[3])();
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)*in_EAX;
      puVar3[5] = 0x18;
      (*(code *)*puVar3)();
    }
  }
  return;
}


// ==== FUN_0090c470 @ 0x0090c470 ====

void FUN_0090c470(int *param_1,undefined4 param_2,uint param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined1 *puVar3;
  int *piVar4;
  int iVar5;
  
  if (0xfffd < param_3) {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0xb;
    (*(code *)*puVar1)(param_1);
  }
  FUN_0090b7e0(param_2);
  piVar2 = (int *)param_1[6];
  puVar3 = (undefined1 *)*piVar2;
  *puVar3 = (char)(param_3 + 2 >> 8);
  *piVar2 = (int)(puVar3 + 1);
  piVar4 = piVar2 + 1;
  *piVar4 = *piVar4 + -1;
  if (*piVar4 == 0) {
    iVar5 = (*(code *)piVar2[3])(param_1);
    if (iVar5 == 0) {
      puVar1 = (undefined4 *)*param_1;
      puVar1[5] = 0x18;
      (*(code *)*puVar1)(param_1);
    }
  }
  piVar4 = (int *)param_1[6];
  puVar3 = (undefined1 *)*piVar4;
  *puVar3 = (char)(param_3 + 2);
  *piVar4 = (int)(puVar3 + 1);
  iVar5 = piVar4[1];
  piVar4[1] = iVar5 + -1;
  if (iVar5 + -1 == 0) {
    iVar5 = (*(code *)piVar4[3])(param_1);
    if (iVar5 == 0) {
      puVar1 = (undefined4 *)*param_1;
      puVar1[5] = 0x18;
      (*(code *)*puVar1)(param_1);
    }
  }
  return;
}


// ==== FUN_0090c500 @ 0x0090c500 ====

void FUN_0090c500(int *param_1,undefined1 param_2)

{
  int *piVar1;
  int *piVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  piVar2 = (int *)param_1[6];
  puVar3 = (undefined1 *)*piVar2;
  *puVar3 = param_2;
  *piVar2 = (int)(puVar3 + 1);
  piVar1 = piVar2 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    iVar5 = (*(code *)piVar2[3])(param_1);
    if (iVar5 == 0) {
      puVar4 = (undefined4 *)*param_1;
      puVar4[5] = 0x18;
      (*(code *)*puVar4)(param_1);
    }
  }
  return;
}


// ==== FUN_0090c540 @ 0x0090c540 ====

void FUN_0090c540(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x164);
  FUN_0090b7e0(0xd8);
  iVar2 = *(int *)(param_1 + 0xd0);
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  if (iVar2 != 0) {
    FUN_0090c020();
  }
  if (*(int *)(param_1 + 0xdc) != 0) {
    FUN_0090c270();
  }
  return;
}


// ==== FUN_0090c590 @ 0x0090c590 ====

void FUN_0090c590(int *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int local_8;
  
  local_8 = 0;
  if (0 < param_1[0xf]) {
    puVar4 = (undefined4 *)(param_1[0x11] + 0x10);
    iVar5 = 0;
    do {
      iVar2 = FUN_0090b840(*puVar4);
      local_8 = local_8 + iVar2;
      iVar5 = iVar5 + 1;
      puVar4 = puVar4 + 0x15;
    } while (iVar5 < param_1[0xf]);
  }
  if (((param_1[0x2d] == 0) && (param_1[0x3b] == 0)) && (param_1[0xe] == 8)) {
    iVar5 = param_1[0xf];
    bVar1 = true;
    if (0 < iVar5) {
      piVar3 = (int *)(param_1[0x11] + 0x18);
      do {
        if ((1 < piVar3[-1]) || (1 < *piVar3)) {
          bVar1 = false;
        }
        piVar3 = piVar3 + 0x15;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    if ((local_8 != 0) && (bVar1)) {
      iVar5 = *param_1;
      *(undefined4 *)(iVar5 + 0x14) = 0x4b;
      (**(code **)(iVar5 + 4))(param_1,0);
    }
  }
  if (param_1[0x2d] != 0) {
    FUN_0090bc50();
    return;
  }
  if (param_1[0x3b] == 0) {
    FUN_0090bc50();
    return;
  }
  FUN_0090bc50();
  return;
}


// ==== FUN_0090c690 @ 0x0090c690 ====

void FUN_0090c690(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  
  iVar3 = param_1;
  iVar1 = *(int *)(param_1 + 0x164);
  if ((*(int *)(param_1 + 0xb4) == 0) &&
     (piVar4 = (int *)(param_1 + 0xfc), param_1 = 0, 0 < *piVar4)) {
    piVar4 = (int *)(iVar3 + 0x100);
    do {
      iVar2 = *piVar4;
      if (*(int *)(iVar3 + 0xec) == 0) {
        FUN_0090ba10(*(undefined4 *)(iVar2 + 0x14));
        uVar5 = *(undefined4 *)(iVar2 + 0x18);
LAB_0090c70a:
        FUN_0090ba10(uVar5);
      }
      else {
        if (*(int *)(iVar3 + 0x144) != 0) {
          uVar5 = *(undefined4 *)(iVar2 + 0x18);
          goto LAB_0090c70a;
        }
        if (*(int *)(iVar3 + 0x14c) == 0) {
          uVar5 = *(undefined4 *)(iVar2 + 0x14);
          goto LAB_0090c70a;
        }
      }
      param_1 = param_1 + 1;
      piVar4 = piVar4 + 1;
    } while (param_1 < *(int *)(iVar3 + 0xfc));
  }
  if (*(int *)(iVar3 + 200) != *(int *)(iVar1 + 0x1c)) {
    FUN_0090bba0();
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(iVar3 + 200);
  }
  FUN_0090be50();
  return;
}


// ==== FUN_0090c760 @ 0x0090c760 ====

void FUN_0090c760(void)

{
  FUN_0090b7e0(0xd9);
  return;
}


// ==== FUN_0090c780 @ 0x0090c780 ====

void FUN_0090c780(int *param_1)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int *piVar3;
  int iVar4;
  
  FUN_0090b7e0(0xd8);
  iVar4 = 0;
  piVar3 = param_1 + 0x12;
  do {
    if (*piVar3 != 0) {
      FUN_0090b840(iVar4);
    }
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar4 < 4);
  if (param_1[0x2d] == 0) {
    iVar4 = 0;
    piVar3 = param_1 + 0x1a;
    do {
      if (piVar3[-4] != 0) {
        FUN_0090ba10(iVar4);
      }
      if (*piVar3 != 0) {
        FUN_0090ba10(iVar4);
      }
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar4 < 4);
  }
  puVar1 = (undefined4 *)param_1[6];
  puVar2 = (undefined1 *)*puVar1;
  *puVar2 = 0xff;
  *puVar1 = puVar2 + 1;
  piVar3 = puVar1 + 1;
  *piVar3 = *piVar3 + -1;
  if (*piVar3 == 0) {
    iVar4 = (*(code *)puVar1[3])(param_1);
    if (iVar4 == 0) {
      puVar1 = (undefined4 *)*param_1;
      puVar1[5] = 0x18;
      (*(code *)*puVar1)(param_1);
    }
  }
  puVar1 = (undefined4 *)param_1[6];
  puVar2 = (undefined1 *)*puVar1;
  *puVar2 = 0xd9;
  *puVar1 = puVar2 + 1;
  piVar3 = puVar1 + 1;
  *piVar3 = *piVar3 + -1;
  if (*piVar3 == 0) {
    iVar4 = (*(code *)puVar1[3])(param_1);
    if (iVar4 == 0) {
      puVar1 = (undefined4 *)*param_1;
      puVar1[5] = 0x18;
      (*(code *)*puVar1)(param_1);
    }
  }
  return;
}


// ==== FUN_0090c840 @ 0x0090c840 ====

void FUN_0090c840(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x20);
  *(undefined4 **)(param_1 + 0x164) = puVar1;
  *puVar1 = FUN_0090c540;
  puVar1[1] = FUN_0090c590;
  puVar1[2] = FUN_0090c690;
  puVar1[3] = FUN_0090c760;
  puVar1[4] = FUN_0090c780;
  puVar1[5] = FUN_0090c470;
  puVar1[6] = FUN_0090c500;
  puVar1[7] = 0;
  return;
}


// ==== FUN_0090c8a0 @ 0x0090c8a0 ====

void FUN_0090c8a0(int *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  FUN_0095ada0(param_1,0);
  if (param_1[0x2c] == 0) {
    FUN_0095a1e0(param_1);
    FUN_009599a0(param_1);
    FUN_00958ee0(param_1,0);
  }
  FUN_009588d0(param_1);
  if (param_1[0x2d] == 0) {
    if (param_1[0x3b] == 0) {
      FUN_00956e50(param_1);
    }
    else {
      FUN_00957ab0(param_1);
    }
  }
  else {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 1;
    (*(code *)*puVar1)();
  }
  if ((param_1[0x2a] < 2) && (param_1[0x2e] == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  FUN_00955f10(param_1,uVar2);
  FUN_009556d0(param_1,0);
  FUN_0090c840(param_1);
  (**(code **)(param_1[1] + 0x18))(param_1);
  (**(code **)param_1[0x59])(param_1);
  return;
}


// ==== FUN_0090c949 @ 0x0090c949 ====

undefined4 * FUN_0090c949(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_1 == 2) {
    uVar2 = 0x40;
  }
  else {
    if (param_1 != 1) {
      return (undefined4 *)0x0;
    }
    uVar2 = 0x19c;
  }
  puVar1 = _malloc(uVar2);
  if (puVar1 != (undefined4 *)0x0) {
    puVar4 = puVar1;
    for (uVar2 = uVar2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
  }
  return puVar1;
}


// ==== FUN_0090c991 @ 0x0090c991 ====

void FUN_0090c991(void *param_1)

{
  if (param_1 == (void *)0x0) {
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_0090c9a9 @ 0x0090c9a9 ====

void * FUN_0090c9a9(int param_1,size_t param_2)

{
  void *pvVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = _malloc(param_2);
    if (pvVar1 == (void *)0x0) {
      FUN_008ee0f5(param_1,s_Out_of_Memory_00a28890);
    }
  }
  return pvVar1;
}


// ==== FUN_0090c9e2 @ 0x0090c9e2 ====

void FUN_0090c9e2(int param_1,void *param_2)

{
  if ((param_1 == 0) || (param_2 == (void *)0x0)) {
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_0090ca00 @ 0x0090ca00 ====

undefined4 * FUN_0090ca00(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = param_2;
  for (uVar1 = param_4 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = *param_3;
    param_3 = param_3 + 1;
    puVar2 = puVar2 + 1;
  }
  for (param_4 = param_4 & 3; param_4 != 0; param_4 = param_4 - 1) {
    *(undefined1 *)puVar2 = *(undefined1 *)param_3;
    param_3 = (undefined4 *)((int)param_3 + 1);
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  return param_2;
}


// ==== FUN_0090ca28 @ 0x0090ca28 ====

undefined4 * FUN_0090ca28(undefined4 param_1,undefined4 *param_2,undefined1 param_3,uint param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = param_2;
  for (uVar1 = param_4 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = CONCAT22(CONCAT11(param_3,param_3),CONCAT11(param_3,param_3));
    puVar2 = puVar2 + 1;
  }
  for (param_4 = param_4 & 3; param_4 != 0; param_4 = param_4 - 1) {
    *(undefined1 *)puVar2 = param_3;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  return param_2;
}


// ==== FUN_0090ca5e @ 0x0090ca5e ====

uint FUN_0090ca5e(uint param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == (byte *)0x0) {
    param_1 = 0;
  }
  else {
    param_1 = ~param_1;
    if (7 < param_3) {
      uVar2 = param_3 >> 3;
      do {
        param_3 = param_3 - 8;
        uVar1 = param_1 >> 8 ^ *(uint *)(&DAT_00a288a0 + ((*param_2 ^ param_1) & 0xff) * 4);
        uVar1 = uVar1 >> 8 ^ *(uint *)(&DAT_00a288a0 + ((param_2[1] ^ uVar1) & 0xff) * 4);
        uVar1 = uVar1 >> 8 ^ *(uint *)(&DAT_00a288a0 + ((param_2[2] ^ uVar1) & 0xff) * 4);
        uVar1 = uVar1 >> 8 ^ *(uint *)(&DAT_00a288a0 + ((param_2[3] ^ uVar1) & 0xff) * 4);
        uVar1 = uVar1 >> 8 ^ *(uint *)(&DAT_00a288a0 + ((param_2[4] ^ uVar1) & 0xff) * 4);
        uVar1 = uVar1 >> 8 ^ *(uint *)(&DAT_00a288a0 + ((param_2[5] ^ uVar1) & 0xff) * 4);
        uVar1 = uVar1 >> 8 ^ *(uint *)(&DAT_00a288a0 + ((param_2[6] ^ uVar1) & 0xff) * 4);
        param_1 = uVar1 >> 8 ^ *(uint *)(&DAT_00a288a0 + ((param_2[7] ^ uVar1) & 0xff) * 4);
        param_2 = param_2 + 8;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    for (; param_3 != 0; param_3 = param_3 - 1) {
      param_1 = param_1 >> 8 ^ *(uint *)(&DAT_00a288a0 + ((*param_2 ^ param_1) & 0xff) * 4);
      param_2 = param_2 + 1;
    }
    param_1 = ~param_1;
  }
  return param_1;
}


// ==== FUN_0090cb56 @ 0x0090cb56 ====

void FUN_0090cb56(undefined1 *param_1,undefined4 param_2)

{
  *param_1 = (char)((uint)param_2 >> 0x18);
  param_1[1] = (char)((uint)param_2 >> 0x10);
  param_1[2] = (char)((uint)param_2 >> 8);
  param_1[3] = (char)param_2;
  return;
}


// ==== FUN_0090cb7f @ 0x0090cb7f ====

void FUN_0090cb7f(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0090cb56(&param_3,param_3);
  FUN_008eea05(param_1,&param_3,4);
  FUN_008eea05(param_1,param_2,4);
  FUN_008ee244(param_1);
  FUN_008ee260(param_1,param_2,4);
  return;
}


// ==== FUN_0090cbc1 @ 0x0090cbc1 ====

void FUN_0090cbc1(undefined4 param_1,int param_2,int param_3)

{
  if ((param_2 == 0) || (param_3 == 0)) {
    return;
  }
  FUN_008ee260(param_1,param_2,param_3);
  FUN_008eea05();
  return;
}


// ==== FUN_0090cbea @ 0x0090cbea ====

void FUN_0090cbea(int param_1)

{
  int iVar1;
  
  iVar1 = param_1;
  FUN_0090cb56(&param_1,*(undefined4 *)(param_1 + 0x100));
  FUN_008eea05(iVar1,&param_1,4);
  return;
}


// ==== FUN_0090cc13 @ 0x0090cc13 ====

void FUN_0090cc13(int param_1)

{
  FUN_008eea05(param_1,&DAT_00a28d10 + *(byte *)(param_1 + 0x11c),
               8 - (uint)*(byte *)(param_1 + 0x11c));
  return;
}


// ==== FUN_0090cc39 @ 0x0090cc39 ====

void FUN_0090cc39(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  uVar2 = param_3;
  iVar1 = param_1;
  if (((*(char *)(param_1 + 0x198) == '\0') && (param_3 == 0)) || (0x100 < param_3)) {
    if (*(char *)(param_1 + 0x116) != '\x03') {
      FUN_008ee116(param_1,s_Invalid_number_of_colors_in_pale_00a28d38);
      return;
    }
    FUN_008ee0f5();
  }
  *(short *)(iVar1 + 0x108) = (short)uVar2;
  FUN_0090cb7f(iVar1,&DAT_00a28d30,uVar2 * 3);
  if (uVar2 != 0) {
    puVar3 = (undefined1 *)(param_2 + 2);
    do {
      param_1._0_3_ = CONCAT12(*puVar3,*(undefined2 *)(puVar3 + -2));
      FUN_0090cbc1(iVar1,&param_1,3);
      puVar3 = puVar3 + 3;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  FUN_0090cbea(iVar1);
  *(uint *)(iVar1 + 0x58) = *(uint *)(iVar1 + 0x58) | 2;
  return;
}


// ==== FUN_0090cccb @ 0x0090cccb ====

void FUN_0090cccb(int param_1)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = ((uint)*(byte *)(param_1 + 0x11b) * (uint)*(byte *)(param_1 + 0x118) *
           *(int *)(param_1 + 0xb8) + 7 >> 3) + 1;
  puVar1 = (undefined1 *)FUN_0090c9a9(param_1,uVar4);
  *(undefined1 **)(param_1 + 0xdc) = puVar1;
  *puVar1 = 0;
  if ((*(byte *)(param_1 + 0x115) & 0x10) != 0) {
    puVar1 = (undefined1 *)FUN_0090c9a9(param_1,*(int *)(param_1 + 200) + 1);
    *(undefined1 **)(param_1 + 0xe0) = puVar1;
    *puVar1 = 1;
  }
  if ((*(byte *)(param_1 + 0x115) & 0xe0) != 0) {
    puVar2 = (undefined4 *)FUN_0090c9a9(param_1,uVar4);
    *(undefined4 **)(param_1 + 0xd8) = puVar2;
    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar2 = 0;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
    if ((*(byte *)(param_1 + 0x115) & 0x20) != 0) {
      puVar1 = (undefined1 *)FUN_0090c9a9(param_1,*(int *)(param_1 + 200) + 1);
      *(undefined1 **)(param_1 + 0xe4) = puVar1;
      *puVar1 = 2;
    }
    if ((*(byte *)(param_1 + 0x115) & 0x40) != 0) {
      puVar1 = (undefined1 *)FUN_0090c9a9(param_1,*(int *)(param_1 + 200) + 1);
      *(undefined1 **)(param_1 + 0xe8) = puVar1;
      *puVar1 = 3;
    }
    if ((*(byte *)(param_1 + 0x115) & 0x80) != 0) {
      puVar1 = (undefined1 *)FUN_0090c9a9(param_1,*(int *)(param_1 + 200) + 1);
      *(undefined1 **)(param_1 + 0xec) = puVar1;
      *puVar1 = 4;
    }
  }
  if ((*(char *)(param_1 + 0x113) == '\0') || ((*(byte *)(param_1 + 0x60) & 2) != 0)) {
    *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xbc);
    uVar4 = *(uint *)(param_1 + 0xb8);
  }
  else {
    *(uint *)(param_1 + 0xc0) = *(int *)(param_1 + 0xbc) + 7U >> 3;
    uVar4 = *(int *)(param_1 + 0xb8) + 7U >> 3;
  }
  *(uint *)(param_1 + 0xc4) = uVar4;
  *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x9c);
  return;
}


// ==== FUN_0090ce0d @ 0x0090ce0d ====

void FUN_0090ce0d(uint *param_1,undefined4 *param_2,undefined4 *param_3)

{
  byte bVar1;
  uint *puVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  bool bVar11;
  uint local_8;
  
  puVar9 = param_2;
  puVar2 = param_1;
  if (5 < (int)param_3) {
    return;
  }
  bVar1 = *(byte *)((int)param_1 + 0xb);
  iVar4 = (int)param_3 * 4;
  if (bVar1 == 1) {
    local_8 = *(uint *)(&DAT_00a28ca0 + iVar4);
    uVar5 = *param_1;
    param_3 = (undefined4 *)0x0;
    param_1 = param_2;
    param_2 = (undefined4 *)0x7;
    if (uVar5 <= local_8) goto LAB_0090d016;
    do {
      param_3 = (undefined4 *)
                ((uint)param_3 |
                (*(byte *)((local_8 >> 3) + (int)puVar9) >> (7 - ((byte)local_8 & 7) & 0x1f) & 1) <<
                ((byte)param_2 & 0x1f));
      if (param_2 == (undefined4 *)0x0) {
        uVar3 = param_3._0_1_;
        param_3 = (undefined4 *)0x0;
        param_2 = (undefined4 *)0x7;
        *(undefined1 *)param_1 = uVar3;
        param_1 = (undefined4 *)((int)param_1 + 1);
      }
      else {
        param_2 = (undefined4 *)((int)param_2 + -1);
      }
      local_8 = local_8 + *(int *)(&DAT_00a28cbc + iVar4);
    } while (local_8 < uVar5);
    bVar11 = param_2 == (undefined4 *)0x7;
  }
  else if (bVar1 == 2) {
    local_8 = *(uint *)(&DAT_00a28ca0 + iVar4);
    uVar5 = *param_1;
    param_3 = (undefined4 *)0x0;
    param_1 = param_2;
    param_2 = (undefined4 *)0x6;
    if (uVar5 <= local_8) goto LAB_0090d016;
    do {
      param_3 = (undefined4 *)
                ((uint)param_3 |
                (*(byte *)((local_8 >> 2) + (int)puVar9) >>
                 (('\x03' - ((byte)local_8 & 3)) * '\x02' & 0x1f) & 3) << ((byte)param_2 & 0x1f));
      if (param_2 == (undefined4 *)0x0) {
        uVar3 = param_3._0_1_;
        param_3 = (undefined4 *)0x0;
        param_2 = (undefined4 *)0x6;
        *(undefined1 *)param_1 = uVar3;
        param_1 = (undefined4 *)((int)param_1 + 1);
      }
      else {
        param_2 = (undefined4 *)((int)param_2 + -2);
      }
      local_8 = local_8 + *(int *)(&DAT_00a28cbc + iVar4);
    } while (local_8 < uVar5);
    bVar11 = param_2 == (undefined4 *)0x6;
  }
  else {
    if (bVar1 != 4) {
      uVar5 = *param_1;
      uVar6 = (uint)(bVar1 >> 3);
      uVar8 = *(uint *)(&DAT_00a28ca0 + iVar4);
      param_3 = param_2;
      for (; uVar8 < uVar5; uVar8 = uVar8 + *(int *)(&DAT_00a28cbc + iVar4)) {
        puVar9 = (undefined4 *)(uVar8 * uVar6 + (int)param_2);
        if (param_3 != puVar9) {
          puVar10 = param_3;
          for (uVar7 = (uint)(bVar1 >> 5); uVar7 != 0; uVar7 = uVar7 - 1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
            puVar9 = (undefined4 *)((int)puVar9 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
        }
        param_3 = (undefined4 *)((int)param_3 + uVar6);
      }
      goto LAB_0090d016;
    }
    local_8 = *(uint *)(&DAT_00a28ca0 + iVar4);
    uVar5 = *param_1;
    param_3 = (undefined4 *)0x0;
    param_1 = param_2;
    param_2 = (undefined4 *)0x4;
    if (uVar5 <= local_8) goto LAB_0090d016;
    do {
      param_3 = (undefined4 *)
                ((uint)param_3 |
                (*(byte *)((local_8 >> 1) + (int)puVar9) >> (((byte)local_8 & 1) * -4 + 4 & 0x1f) &
                0xf) << ((byte)param_2 & 0x1f));
      if (param_2 == (undefined4 *)0x0) {
        uVar3 = param_3._0_1_;
        param_3 = (undefined4 *)0x0;
        param_2 = (undefined4 *)0x4;
        *(undefined1 *)param_1 = uVar3;
        param_1 = (undefined4 *)((int)param_1 + 1);
      }
      else {
        param_2 = (undefined4 *)((int)param_2 + -4);
      }
      local_8 = local_8 + *(int *)(&DAT_00a28cbc + iVar4);
    } while (local_8 < uVar5);
    bVar11 = param_2 == (undefined4 *)0x4;
  }
  if (!bVar11) {
    *(undefined1 *)param_1 = param_3._0_1_;
  }
LAB_0090d016:
  uVar5 = ((*(uint *)(&DAT_00a28cbc + iVar4) - *(int *)(&DAT_00a28ca0 + iVar4)) + -1 + *puVar2) /
          *(uint *)(&DAT_00a28cbc + iVar4);
  *puVar2 = uVar5;
  puVar2[1] = *(byte *)((int)puVar2 + 0xb) * uVar5 + 7 >> 3;
  return;
}


// ==== FUN_0090d047 @ 0x0090d047 ====

void FUN_0090d047(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0090cb7f(param_1,param_2,param_4);
  FUN_0090cbc1(param_1,param_3,param_4);
  FUN_0090cbea(param_1);
  return;
}


// ==== FUN_0090d074 @ 0x0090d074 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0090d074(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  char *pcVar4;
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  char local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  if (param_5 == 0) {
    if ((0 < param_4) &&
       ((((param_4 < 3 || (param_4 == 4)) || (param_4 == 8)) || (param_4 == 0x10)))) {
LAB_0090d104:
      *(undefined1 *)(param_1 + 0x11a) = 1;
      goto LAB_0090d155;
    }
    pcVar4 = s_Invalid_bit_depth_for_grayscale_i_00a28dc4;
  }
  else {
    if (param_5 == 2) {
      if ((param_4 != 8) && (param_4 != 0x10)) {
        FUN_008ee0f5(param_1,s_Invalid_bit_depth_for_RGB_image_00a28dec);
      }
      *(undefined1 *)(param_1 + 0x11a) = 3;
      goto LAB_0090d155;
    }
    if (param_5 == 3) {
      if ((0 < param_4) && (((param_4 < 3 || (param_4 == 4)) || (param_4 == 8)))) goto LAB_0090d104;
      pcVar4 = s_Invalid_bit_depth_for_paletted_i_00a28e0c;
    }
    else {
      if (param_5 == 4) {
        if ((param_4 != 8) && (param_4 != 0x10)) {
          FUN_008ee0f5(param_1,s_Invalid_bit_depth_for_grayscale__00a28e34);
        }
        *(undefined1 *)(param_1 + 0x11a) = 2;
        goto LAB_0090d155;
      }
      if (param_5 == 6) {
        if ((param_4 != 8) && (param_4 != 0x10)) {
          FUN_008ee0f5(param_1,s_Invalid_bit_depth_for_RGBA_image_00a28e60);
        }
        *(undefined1 *)(param_1 + 0x11a) = 4;
        goto LAB_0090d155;
      }
      pcVar4 = s_Invalid_image_color_type_specifi_00a28e84;
    }
  }
  FUN_008ee0f5(param_1,pcVar4);
LAB_0090d155:
  if (param_6 != 0) {
    FUN_008ee116(param_1,s_Invalid_compression_type_specifi_00a28da0);
    param_6 = 0;
  }
  if (param_7 != 0) {
    FUN_008ee116(param_1,s_Invalid_filter_type_specified_00a28d80);
    param_7 = 0;
  }
  if ((param_8 != 0) && (param_8 != 1)) {
    FUN_008ee116(param_1,s_Invalid_interlace_type_specified_00a28d5c);
    param_8 = 1;
  }
  *(undefined1 *)(param_1 + 0x116) = (undefined1)param_5;
  *(undefined1 *)(param_1 + 0x113) = (undefined1)param_8;
  cVar3 = (char)param_4;
  bVar2 = *(char *)(param_1 + 0x11a) * cVar3;
  *(byte *)(param_1 + 0x119) = bVar2;
  *(uint *)(param_1 + 200) = (bVar2 + 7) * param_2 >> 3;
  *(char *)(param_1 + 0x117) = cVar3;
  *(int *)(param_1 + 0xb8) = param_2;
  *(undefined4 *)(param_1 + 0xbc) = param_3;
  *(int *)(param_1 + 0xc4) = param_2;
  *(char *)(param_1 + 0x118) = cVar3;
  *(char *)(param_1 + 0x11b) = *(char *)(param_1 + 0x11a);
  FUN_0090cb56(local_18,param_2);
  FUN_0090cb56(local_14,param_3);
  local_f = (undefined1)param_5;
  local_e = (undefined1)param_6;
  local_d = (undefined1)param_7;
  local_c = (undefined1)param_8;
  local_10 = cVar3;
  FUN_0090d047(param_1,&DAT_00a28d18,local_18,0xd);
  *(code **)(param_1 + 0x84) = FUN_008ee1e3;
  *(code **)(param_1 + 0x88) = FUN_008ee239;
  *(int *)(param_1 + 0x8c) = param_1;
  if (*(char *)(param_1 + 0x115) == '\0') {
    if ((*(char *)(param_1 + 0x116) == '\x03') || (*(byte *)(param_1 + 0x117) < 8)) {
      *(undefined1 *)(param_1 + 0x115) = 8;
    }
    else {
      *(undefined1 *)(param_1 + 0x115) = 0xf8;
    }
  }
  uVar1 = *(uint *)(param_1 + 0x5c);
  if ((uVar1 & 1) == 0) {
    *(uint *)(param_1 + 0xb4) = (uint)(*(char *)(param_1 + 0x115) != '\b');
  }
  if ((uVar1 & 2) == 0) {
    *(undefined4 *)(param_1 + 0xa4) = 0xffffffff;
  }
  if ((uVar1 & 4) == 0) {
    *(undefined4 *)(param_1 + 0xb0) = 8;
  }
  if ((uVar1 & 8) == 0) {
    *(undefined4 *)(param_1 + 0xac) = 0xf;
  }
  if ((uVar1 & 0x10) == 0) {
    *(undefined4 *)(param_1 + 0xa8) = 8;
  }
  FUN_0090ee4f(param_1 + 100,*(undefined4 *)(param_1 + 0xa4),*(undefined4 *)(param_1 + 0xa8),
               *(undefined4 *)(param_1 + 0xac),*(undefined4 *)(param_1 + 0xb0),
               *(undefined4 *)(param_1 + 0xb4),s_1_1_4_00a24d68,0x38);
  *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x9c);
  *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(param_1 + 0x58) = 1;
  return;
}


// ==== FUN_0090d31d @ 0x0090d31d ====

void FUN_0090d31d(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0090d047(param_1,&DAT_00a28d20,param_2,param_3);
  *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 4;
  return;
}


// ==== FUN_0090d340 @ 0x0090d340 ====

void FUN_0090d340(int param_1)

{
  FUN_0090d047(param_1,&DAT_00a28d28,0,0);
  *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x10;
  return;
}


// ==== FUN_0090d361 @ 0x0090d361 ====

void FUN_0090d361(int param_1)

{
  uint *puVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  undefined4 *puVar7;
  char *pcVar8;
  
  puVar1 = (uint *)(param_1 + 0xd4);
  *puVar1 = *puVar1 + 1;
  if (*(uint *)(param_1 + 0xc0) <= *puVar1) {
    if (*(char *)(param_1 + 0x113) != '\0') {
      *puVar1 = 0;
      if ((*(byte *)(param_1 + 0x60) & 2) == 0) {
        do {
          *(char *)(param_1 + 0x114) = *(char *)(param_1 + 0x114) + '\x01';
          bVar6 = *(byte *)(param_1 + 0x114);
          if (6 < bVar6) goto LAB_0090d454;
          iVar3 = (uint)bVar6 * 4;
          *(uint *)(param_1 + 0xc4) =
               ((*(int *)(param_1 + 0xb8) - *(int *)(&DAT_00a28ca0 + iVar3)) + -1 +
               *(uint *)(&DAT_00a28cbc + iVar3)) / *(uint *)(&DAT_00a28cbc + iVar3);
          uVar5 = ((*(int *)(param_1 + 0xbc) - *(int *)(&DAT_00a28cd8 + iVar3)) + -1 +
                  *(uint *)(&DAT_00a28cf4 + iVar3)) / *(uint *)(&DAT_00a28cf4 + iVar3);
          *(uint *)(param_1 + 0xc0) = uVar5;
        } while ((*(int *)(param_1 + 0xc4) == 0) || (uVar5 == 0));
      }
      else {
        pbVar2 = (byte *)(param_1 + 0x114);
        *pbVar2 = *pbVar2 + 1;
        bVar6 = *pbVar2;
      }
      if (bVar6 < 7) {
        if (*(undefined4 **)(param_1 + 0xd8) == (undefined4 *)0x0) {
          return;
        }
        uVar4 = ((uint)*(byte *)(param_1 + 0x11b) * (uint)*(byte *)(param_1 + 0x118) *
                 *(int *)(param_1 + 0xb8) + 7 >> 3) + 1;
        puVar7 = *(undefined4 **)(param_1 + 0xd8);
        for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar7 = 0;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        return;
      }
    }
LAB_0090d454:
    do {
      iVar3 = FUN_0090e08b(param_1 + 100,4);
      if ((iVar3 != 0) && (iVar3 != 1)) {
        pcVar8 = *(char **)(param_1 + 0x7c);
        if (pcVar8 == (char *)0x0) {
          pcVar8 = s_zlib_error_00a24b60;
        }
        FUN_008ee0f5(param_1,pcVar8);
      }
      if ((*(int *)(param_1 + 0x74) == 0) && (iVar3 == 0)) {
        FUN_0090d31d(param_1,*(undefined4 *)(param_1 + 0x9c),*(undefined4 *)(param_1 + 0xa0));
        *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x9c);
        *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0xa0);
      }
    } while (iVar3 != 1);
    if (*(uint *)(param_1 + 0x74) < *(uint *)(param_1 + 0xa0)) {
      FUN_0090d31d(param_1,*(undefined4 *)(param_1 + 0x9c),
                   *(uint *)(param_1 + 0xa0) - *(uint *)(param_1 + 0x74));
    }
    FUN_0090eddb(param_1 + 100);
  }
  return;
}


// ==== FUN_0090d4e2 @ 0x0090d4e2 ====

void FUN_0090d4e2(int param_1,undefined4 param_2)

{
  uint *puVar1;
  int iVar2;
  char *pcVar3;
  
  *(undefined4 *)(param_1 + 100) = param_2;
  *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0xf4) + 1;
  do {
    iVar2 = FUN_0090e08b(param_1 + 100,0);
    if (iVar2 != 0) {
      pcVar3 = *(char **)(param_1 + 0x7c);
      if (pcVar3 == (char *)0x0) {
        pcVar3 = s_zlib_error_00a24b60;
      }
      FUN_008ee0f5(param_1,pcVar3);
    }
    if (*(int *)(param_1 + 0x74) == 0) {
      FUN_0090d31d(param_1,*(undefined4 *)(param_1 + 0x9c),*(undefined4 *)(param_1 + 0xa0));
      *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x9c);
      *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0xa0);
    }
  } while (*(int *)(param_1 + 0x68) != 0);
  iVar2 = *(int *)(param_1 + 0xd8);
  if (iVar2 != 0) {
    *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xdc);
    *(int *)(param_1 + 0xdc) = iVar2;
  }
  FUN_0090d361(param_1);
  puVar1 = (uint *)(param_1 + 0x128);
  *puVar1 = *puVar1 + 1;
  if ((*(uint *)(param_1 + 0x124) != 0) && (*(uint *)(param_1 + 0x124) <= *puVar1)) {
    FUN_008ee566(param_1);
  }
  return;
}


// ==== FUN_0090d590 @ 0x0090d590 ====

void FUN_0090d590(byte *param_1,byte *param_2)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  byte *pbVar10;
  undefined1 *puVar11;
  char *pcVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  byte *pbVar21;
  char *pcVar22;
  byte *pbVar23;
  int iVar24;
  uint local_30;
  byte *local_2c;
  byte *local_28;
  uint local_24;
  byte *local_18;
  undefined1 *local_14;
  uint local_c;
  
  iVar5 = (int)param_1;
  uVar13 = *(uint *)((int)param_2 + 4);
  uVar14 = (uint)*(byte *)((int)param_1 + 0x181);
  uVar7 = (*(byte *)((int)param_2 + 0xb) + 7) / 8;
  bVar1 = *(byte *)((int)param_1 + 0x115);
  puVar11 = *(undefined1 **)((int)param_1 + 0xdc);
  local_c = 0x7fffffff;
  iVar19 = *(int *)((int)param_1 + 0xd8);
  if (((bVar1 & 8) != 0) && (bVar1 != 8)) {
    local_c = 0;
    uVar20 = 0;
    if (uVar13 != 0) {
      do {
        uVar15 = (uint)(byte)puVar11[uVar20 + 1];
        if (0x7f < uVar15) {
          uVar15 = 0x100 - uVar15;
        }
        local_c = local_c + uVar15;
        uVar20 = uVar20 + 1;
      } while (uVar20 < uVar13);
    }
    if (*(char *)((int)param_1 + 0x180) == '\x02') {
      local_28 = (byte *)(local_c >> 10 & 0x3fffc0);
      iVar16 = 0;
      local_c = local_c & 0xffff;
      if (uVar14 != 0) {
        do {
          if (*(char *)(*(int *)((int)param_1 + 0x184) + iVar16) == '\0') {
            uVar20 = (uint)*(ushort *)(*(int *)((int)param_1 + 0x188) + iVar16 * 2);
            local_c = uVar20 * local_c >> 8;
            local_28 = (byte *)(uVar20 * (int)local_28 >> 8);
          }
          iVar16 = iVar16 + 1;
        } while (iVar16 < (int)uVar14);
      }
      uVar20 = (uint)**(ushort **)((int)param_1 + 400) * (int)local_28 >> 3;
      if (uVar20 < 0x3fffc1) {
        local_c = (**(ushort **)((int)param_1 + 400) * local_c >> 3) + uVar20 * 0x400;
      }
      else {
        local_c = 0x7fffffff;
      }
    }
  }
  if (bVar1 == 0x10) {
    pcVar22 = puVar11 + 1;
    pcVar8 = (char *)(*(int *)((int)param_1 + 0xe0) + 1);
    pcVar12 = pcVar22;
    uVar20 = 0;
    if (uVar7 != 0) {
      param_2 = (byte *)uVar7;
      do {
        cVar2 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        *pcVar8 = cVar2;
        pcVar8 = pcVar8 + 1;
        param_2 = (byte *)((int)param_2 - 1);
        uVar20 = uVar7;
      } while (param_2 != (byte *)0x0);
    }
    if (uVar20 < uVar13) {
      iVar16 = uVar13 - uVar20;
      do {
        cVar2 = *pcVar12;
        cVar3 = *pcVar22;
        pcVar12 = pcVar12 + 1;
        pcVar22 = pcVar22 + 1;
        *pcVar8 = cVar2 - cVar3;
        pcVar8 = pcVar8 + 1;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
    }
    local_14 = *(undefined1 **)((int)param_1 + 0xe0);
LAB_0090d6f0:
    if ((bVar1 & 0x20) != 0) {
      uVar20 = 0;
      local_2c = (byte *)local_c;
      if (*(char *)((int)param_1 + 0x180) == '\x02') {
        uVar17 = local_c & 0xffff;
        uVar15 = local_c >> 10 & 0x3fffc0;
        param_2 = (byte *)0x0;
        if (uVar14 != 0) {
          do {
            if (*(char *)((int)param_2 + *(int *)((int)param_1 + 0x184)) == '\x02') {
              uVar9 = (uint)*(ushort *)(*(int *)((int)param_1 + 0x18c) + (int)param_2 * 2);
              uVar17 = uVar9 * uVar17 >> 8;
              uVar15 = uVar9 * uVar15 >> 8;
            }
            param_2 = (byte *)((int)param_2 + 1);
          } while ((int)param_2 < (int)uVar14);
        }
        uVar9 = (uint)*(ushort *)(*(int *)((int)param_1 + 0x194) + 4);
        uVar15 = uVar9 * uVar15 >> 3;
        if (uVar15 < 0x3fffc1) {
          local_2c = (byte *)((uVar9 * uVar17 >> 3) + uVar15 * 0x400);
        }
        else {
          local_2c = (byte *)0x7fffffff;
        }
      }
      local_28 = (byte *)0x0;
      pbVar10 = *(byte **)((int)param_1 + 0xe4);
      pcVar12 = puVar11 + 1;
      if (uVar13 != 0) {
        iVar16 = (iVar19 + 1) - (int)pcVar12;
        do {
          pbVar10 = pbVar10 + 1;
          cVar2 = *pcVar12;
          cVar3 = pcVar12[iVar16];
          *pbVar10 = cVar2 - cVar3;
          uVar15 = (uint)(byte)(cVar2 - cVar3);
          pcVar12 = pcVar12 + 1;
          if (0x7f < uVar15) {
            uVar15 = 0x100 - uVar15;
          }
          uVar20 = uVar20 + uVar15;
        } while ((uVar20 <= local_2c) && (local_28 = (byte *)((int)local_28 + 1), local_28 < uVar13)
                );
      }
      if (*(char *)((int)param_1 + 0x180) == '\x02') {
        param_2 = (byte *)(uVar20 >> 10 & 0x3fffc0);
        iVar16 = 0;
        uVar20 = uVar20 & 0xffff;
        if (uVar14 != 0) {
          do {
            if (*(char *)(iVar16 + *(int *)((int)param_1 + 0x184)) == '\x02') {
              uVar15 = (uint)*(ushort *)(*(int *)((int)param_1 + 0x188) + iVar16 * 2);
              uVar20 = uVar15 * uVar20 >> 8;
              param_2 = (byte *)(uVar15 * (int)param_2 >> 8);
            }
            iVar16 = iVar16 + 1;
          } while (iVar16 < (int)uVar14);
        }
        uVar17 = (uint)*(ushort *)(*(int *)((int)param_1 + 400) + 4);
        uVar15 = uVar17 * (int)param_2 >> 3;
        if (uVar15 < 0x3fffc1) {
          uVar20 = (uVar17 * uVar20 >> 3) + uVar15 * 0x400;
        }
        else {
          uVar20 = 0x7fffffff;
        }
      }
      if (uVar20 < local_c) {
        local_14 = *(undefined1 **)((int)param_1 + 0xe4);
        local_c = uVar20;
      }
    }
    if (bVar1 != 0x40) goto LAB_0090d97f;
    local_2c = (byte *)0x0;
    local_28 = puVar11 + 1;
    pcVar12 = (char *)(*(int *)((int)param_1 + 0xe8) + 1);
    pbVar10 = (byte *)(iVar19 + 1);
    param_2 = local_28;
    if (uVar7 != 0) {
      local_30 = uVar7;
      do {
        *pcVar12 = *param_2 - (*pbVar10 >> 1);
        pcVar12 = pcVar12 + 1;
        pbVar10 = pbVar10 + 1;
        param_2 = param_2 + 1;
        local_30 = local_30 - 1;
        local_2c = (byte *)uVar7;
      } while (local_30 != 0);
    }
    if (local_2c < uVar13) {
      iVar16 = uVar13 - (int)local_2c;
      do {
        *pcVar12 = *param_2 - (char)(((uint)*pbVar10 + (uint)*local_28) / 2);
        pcVar12 = pcVar12 + 1;
        local_28 = local_28 + 1;
        pbVar10 = pbVar10 + 1;
        param_2 = param_2 + 1;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
    }
    local_14 = *(undefined1 **)((int)param_1 + 0xe8);
LAB_0090db82:
    if ((bVar1 & 0x80) == 0) goto LAB_0090dfd3;
    iVar16 = 0;
    local_28 = (byte *)0x0;
    local_30 = local_c;
    if (*(char *)((int)param_1 + 0x180) == '\x02') {
      uVar15 = local_c & 0xffff;
      uVar20 = local_c >> 10 & 0x3fffc0;
      if (uVar14 != 0) {
        do {
          if (*(char *)(iVar16 + *(int *)((int)param_1 + 0x184)) == '\x04') {
            uVar17 = (uint)*(ushort *)(*(int *)((int)param_1 + 0x18c) + iVar16 * 2);
            uVar15 = uVar17 * uVar15 >> 8;
            uVar20 = uVar17 * uVar20 >> 8;
          }
          iVar16 = iVar16 + 1;
        } while (iVar16 < (int)uVar14);
      }
      uVar17 = (uint)*(ushort *)(*(int *)((int)param_1 + 0x194) + 8);
      uVar20 = uVar17 * uVar20 >> 3;
      if (uVar20 < 0x3fffc1) {
        local_30 = (uVar17 * uVar15 >> 3) + uVar20 * 0x400;
      }
      else {
        local_30 = 0x7fffffff;
      }
    }
    local_24 = 0;
    local_2c = puVar11 + 1;
    pbVar10 = (byte *)(*(int *)((int)param_1 + 0xec) + 1);
    pbVar21 = (byte *)(iVar19 + 1);
    param_1 = pbVar21;
    local_18 = local_2c;
    if (uVar7 != 0) {
      param_2 = (byte *)uVar7;
      do {
        bVar1 = *local_18;
        bVar6 = *param_1;
        *pbVar10 = bVar1 - bVar6;
        pbVar10 = pbVar10 + 1;
        param_1 = param_1 + 1;
        local_18 = local_18 + 1;
        uVar20 = (uint)(byte)(bVar1 - bVar6);
        if (0x7f < uVar20) {
          uVar20 = 0x100 - uVar20;
        }
        local_28 = (byte *)((int)local_28 + uVar20);
        param_2 = (byte *)((int)param_2 - 1);
        local_24 = uVar7;
      } while (param_2 != (byte *)0x0);
    }
    if (local_24 < uVar13) {
      iVar19 = (int)pbVar21 - (int)local_2c;
      pbVar21 = local_28;
      do {
        bVar1 = local_2c[iVar19];
        bVar6 = *param_1;
        bVar4 = *local_2c;
        param_1 = param_1 + 1;
        local_2c = local_2c + 1;
        iVar16 = (uint)bVar6 - (uint)bVar1;
        iVar18 = (uint)bVar4 - (uint)bVar1;
        if (iVar16 < 0) {
          local_28 = (byte *)-iVar16;
        }
        else {
          local_28 = (byte *)iVar16;
        }
        iVar24 = iVar18;
        if (iVar18 < 0) {
          iVar24 = -iVar18;
        }
        iVar16 = iVar16 + iVar18;
        if (iVar16 < 0) {
          iVar16 = -iVar16;
        }
        if ((iVar24 < (int)local_28) || (iVar16 < (int)local_28)) {
          if (iVar16 < iVar24) {
            bVar6 = bVar1;
          }
        }
        else {
          bVar6 = bVar4;
        }
        bVar1 = *local_18;
        *pbVar10 = bVar1 - bVar6;
        uVar7 = (uint)(byte)(bVar1 - bVar6);
        pbVar10 = pbVar10 + 1;
        local_18 = local_18 + 1;
        if (0x7f < uVar7) {
          uVar7 = 0x100 - uVar7;
        }
        local_28 = (byte *)((int)pbVar21 + uVar7);
        if (local_30 < local_28) break;
        local_24 = local_24 + 1;
        pbVar21 = local_28;
      } while (local_24 < uVar13);
    }
    if (*(char *)(iVar5 + 0x180) == '\x02') {
      param_2 = (byte *)((uint)local_28 >> 10 & 0x3fffc0);
      iVar19 = 0;
      uVar13 = (uint)local_28 & 0xffff;
      if (uVar14 != 0) {
        do {
          if (*(char *)(iVar19 + *(int *)(iVar5 + 0x184)) == '\x04') {
            uVar7 = (uint)*(ushort *)(*(int *)(iVar5 + 0x188) + iVar19 * 2);
            uVar13 = uVar7 * uVar13 >> 8;
            param_2 = (byte *)(uVar7 * (int)param_2 >> 8);
          }
          iVar19 = iVar19 + 1;
        } while (iVar19 < (int)uVar14);
      }
      uVar20 = (uint)*(ushort *)(*(int *)(iVar5 + 400) + 8);
      uVar7 = uVar20 * (int)param_2 >> 3;
      if (uVar7 < 0x3fffc1) {
        local_28 = (byte *)((uVar20 * uVar13 >> 3) + uVar7 * 0x400);
      }
      else {
        local_28 = (byte *)0x7fffffff;
      }
    }
    if (local_c <= local_28) goto LAB_0090dfd3;
  }
  else {
    local_14 = puVar11;
    if ((bVar1 & 0x10) != 0) {
      local_28 = (byte *)local_c;
      if (*(char *)((int)param_1 + 0x180) == '\x02') {
        iVar16 = 0;
        uVar15 = local_c & 0xffff;
        uVar20 = local_c >> 10 & 0x3fffc0;
        if (uVar14 != 0) {
          do {
            if (*(char *)(*(int *)((int)param_1 + 0x184) + iVar16) == '\x01') {
              uVar17 = (uint)*(ushort *)(*(int *)((int)param_1 + 0x18c) + iVar16 * 2);
              uVar15 = uVar17 * uVar15 >> 8;
              uVar20 = uVar17 * uVar20 >> 8;
            }
            iVar16 = iVar16 + 1;
          } while (iVar16 < (int)uVar14);
        }
        uVar17 = (uint)*(ushort *)(*(int *)((int)param_1 + 0x194) + 2);
        uVar20 = uVar17 * uVar20 >> 3;
        if (uVar20 < 0x3fffc1) {
          local_28 = (byte *)((uVar17 * uVar15 >> 3) + uVar20 * 0x400);
        }
        else {
          local_28 = (byte *)0x7fffffff;
        }
      }
      uVar20 = 0;
      local_24 = 0;
      local_2c = puVar11 + 1;
      pbVar21 = (byte *)(*(int *)((int)param_1 + 0xe0) + 1);
      pbVar10 = local_2c;
      if (uVar7 != 0) {
        local_30 = uVar7;
        do {
          uVar15 = (uint)*pbVar10;
          *pbVar21 = *pbVar10;
          if (0x7f < uVar15) {
            uVar15 = 0x100 - uVar15;
          }
          uVar20 = uVar20 + uVar15;
          pbVar10 = pbVar10 + 1;
          pbVar21 = pbVar21 + 1;
          local_30 = local_30 - 1;
        } while (local_30 != 0);
        local_24 = uVar7;
      }
      for (; local_24 < *(uint *)((int)param_2 + 4); local_24 = local_24 + 1) {
        bVar6 = *pbVar10;
        bVar4 = *local_2c;
        *pbVar21 = bVar6 - bVar4;
        uVar15 = (uint)(byte)(bVar6 - bVar4);
        if (0x7f < uVar15) {
          uVar15 = 0x100 - uVar15;
        }
        uVar20 = uVar20 + uVar15;
        if (local_28 < uVar20) break;
        pbVar10 = pbVar10 + 1;
        local_2c = local_2c + 1;
        pbVar21 = pbVar21 + 1;
      }
      if (*(char *)((int)param_1 + 0x180) == '\x02') {
        param_2 = (byte *)(uVar20 >> 10 & 0x3fffc0);
        iVar16 = 0;
        uVar20 = uVar20 & 0xffff;
        if (uVar14 != 0) {
          do {
            if (*(char *)(iVar16 + *(int *)((int)param_1 + 0x184)) == '\x01') {
              uVar15 = (uint)*(ushort *)(*(int *)((int)param_1 + 0x18c) + iVar16 * 2);
              uVar20 = uVar15 * uVar20 >> 8;
              param_2 = (byte *)(uVar15 * (int)param_2 >> 8);
            }
            iVar16 = iVar16 + 1;
          } while (iVar16 < (int)uVar14);
        }
        uVar17 = (uint)*(ushort *)(*(int *)((int)param_1 + 0x194) + 2);
        uVar15 = uVar17 * (int)param_2 >> 3;
        if (uVar15 < 0x3fffc1) {
          uVar20 = (uVar17 * uVar20 >> 3) + uVar15 * 0x400;
        }
        else {
          uVar20 = 0x7fffffff;
        }
      }
      if (uVar20 < local_c) {
        local_14 = *(undefined1 **)((int)param_1 + 0xe0);
        local_c = uVar20;
      }
    }
    if (bVar1 != 0x20) goto LAB_0090d6f0;
    param_2 = (byte *)0x0;
    pcVar12 = *(char **)((int)param_1 + 0xe4);
    if (uVar13 != 0) {
      pcVar8 = puVar11 + iVar19 + (1 - (int)puVar11);
      do {
        pcVar12 = pcVar12 + 1;
        iVar16 = (int)param_2 + 1;
        param_2 = (byte *)((int)param_2 + 1);
        *pcVar12 = puVar11[iVar16] - *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (param_2 < uVar13);
    }
    local_14 = *(undefined1 **)((int)param_1 + 0xe4);
LAB_0090d97f:
    if ((bVar1 & 0x40) != 0) {
      param_2 = (byte *)0x0;
      local_28 = (byte *)local_c;
      if (*(char *)((int)param_1 + 0x180) == '\x02') {
        iVar16 = 0;
        uVar15 = local_c & 0xffff;
        uVar20 = local_c >> 10 & 0x3fffc0;
        if (uVar14 != 0) {
          do {
            if (*(char *)(iVar16 + *(int *)((int)param_1 + 0x184)) == '\x03') {
              uVar17 = (uint)*(ushort *)(*(int *)((int)param_1 + 0x18c) + iVar16 * 2);
              uVar15 = uVar17 * uVar15 >> 8;
              uVar20 = uVar17 * uVar20 >> 8;
            }
            iVar16 = iVar16 + 1;
          } while (iVar16 < (int)uVar14);
        }
        uVar17 = (uint)*(ushort *)(*(int *)((int)param_1 + 0x194) + 6);
        uVar20 = uVar17 * uVar20 >> 3;
        if (uVar20 < 0x3fffc1) {
          local_28 = (byte *)((uVar17 * uVar15 >> 3) + uVar20 * 0x400);
        }
        else {
          local_28 = (byte *)0x7fffffff;
        }
      }
      local_24 = 0;
      local_2c = puVar11 + 1;
      pbVar21 = (byte *)(*(int *)((int)param_1 + 0xe8) + 1);
      pbVar23 = (byte *)(iVar19 + 1);
      pbVar10 = local_2c;
      if (uVar7 != 0) {
        local_30 = uVar7;
        do {
          bVar6 = *pbVar10 - (*pbVar23 >> 1);
          *pbVar21 = bVar6;
          pbVar21 = pbVar21 + 1;
          uVar20 = (uint)bVar6;
          pbVar23 = pbVar23 + 1;
          pbVar10 = pbVar10 + 1;
          if (0x7f < uVar20) {
            uVar20 = 0x100 - uVar20;
          }
          param_2 = (byte *)((int)param_2 + uVar20);
          local_30 = local_30 - 1;
        } while (local_30 != 0);
        local_24 = uVar7;
      }
      for (; local_24 < uVar13; local_24 = local_24 + 1) {
        bVar6 = *pbVar10 - (char)(((uint)*local_2c + (uint)*pbVar23) / 2);
        *pbVar21 = bVar6;
        pbVar21 = pbVar21 + 1;
        local_2c = local_2c + 1;
        uVar20 = (uint)bVar6;
        pbVar23 = pbVar23 + 1;
        pbVar10 = pbVar10 + 1;
        if (0x7f < uVar20) {
          uVar20 = 0x100 - uVar20;
        }
        param_2 = (byte *)((int)param_2 + uVar20);
        if (local_28 < param_2) break;
      }
      if (*(char *)((int)param_1 + 0x180) == '\x02') {
        uVar20 = (uint)param_2 >> 10 & 0x3fffc0;
        iVar16 = 0;
        uVar15 = (uint)param_2 & 0xffff;
        param_2 = (byte *)uVar20;
        if (uVar14 != 0) {
          do {
            if (*(char *)(iVar16 + *(int *)((int)param_1 + 0x184)) == '\0') {
              uVar20 = (uint)*(ushort *)(*(int *)((int)param_1 + 0x188) + iVar16 * 2);
              uVar15 = uVar20 * uVar15 >> 8;
              param_2 = (byte *)(uVar20 * (int)param_2 >> 8);
            }
            iVar16 = iVar16 + 1;
          } while (iVar16 < (int)uVar14);
        }
        uVar17 = (uint)*(ushort *)(*(int *)((int)param_1 + 400) + 6);
        uVar20 = uVar17 * (int)param_2 >> 3;
        if (uVar20 < 0x3fffc1) {
          param_2 = (byte *)((uVar17 * uVar15 >> 3) + uVar20 * 0x400);
        }
        else {
          param_2 = (byte *)0x7fffffff;
        }
      }
      if (param_2 < local_c) {
        local_c = (uint)param_2;
        local_14 = *(undefined1 **)((int)param_1 + 0xe8);
      }
    }
    if (bVar1 != 0x80) goto LAB_0090db82;
    local_2c = (byte *)0x0;
    pbVar10 = puVar11 + 1;
    pcVar12 = (char *)(*(int *)((int)param_1 + 0xec) + 1);
    pbVar21 = (byte *)(iVar19 + 1);
    param_1 = pbVar21;
    local_18 = pbVar10;
    if (uVar7 != 0) {
      param_2 = (byte *)uVar7;
      do {
        *pcVar12 = *local_18 - *param_1;
        pcVar12 = pcVar12 + 1;
        param_1 = param_1 + 1;
        local_18 = local_18 + 1;
        param_2 = (byte *)((int)param_2 - 1);
        local_2c = (byte *)uVar7;
      } while (param_2 != (byte *)0x0);
    }
    if (local_2c < uVar13) {
      iVar19 = (int)pbVar21 - (int)pbVar10;
      local_30 = uVar13 - (int)local_2c;
      do {
        bVar1 = pbVar10[iVar19];
        bVar6 = *param_1;
        bVar4 = *pbVar10;
        param_1 = param_1 + 1;
        iVar16 = (uint)bVar6 - (uint)bVar1;
        pbVar10 = pbVar10 + 1;
        iVar18 = (uint)bVar4 - (uint)bVar1;
        if (iVar16 < 0) {
          local_2c = (byte *)-iVar16;
        }
        else {
          local_2c = (byte *)iVar16;
        }
        iVar24 = iVar18;
        if (iVar18 < 0) {
          iVar24 = -iVar18;
        }
        iVar16 = iVar16 + iVar18;
        if (iVar16 < 0) {
          iVar16 = -iVar16;
        }
        if ((iVar24 < (int)local_2c) || (iVar16 < (int)local_2c)) {
          if (iVar16 < iVar24) {
            bVar6 = bVar1;
          }
        }
        else {
          bVar6 = bVar4;
        }
        *pcVar12 = *local_18 - bVar6;
        pcVar12 = pcVar12 + 1;
        local_18 = local_18 + 1;
        local_30 = local_30 + -1;
      } while (local_30 != 0);
    }
  }
  local_14 = *(undefined1 **)(iVar5 + 0xec);
LAB_0090dfd3:
  FUN_0090d4e2(iVar5,local_14);
  if (*(char *)(iVar5 + 0x181) != '\0') {
    iVar19 = 1;
    if (1 < uVar14) {
      do {
        puVar11 = (undefined1 *)(*(int *)(iVar5 + 0x184) + iVar19);
        iVar19 = iVar19 + 1;
        *puVar11 = puVar11[-1];
      } while (iVar19 < (int)uVar14);
    }
    *(undefined1 *)(iVar19 + *(int *)(iVar5 + 0x184)) = *local_14;
  }
  return;
}


// ==== FUN_0090e013 @ 0x0090e013 ====

void FUN_0090e013(void)

{
  int in_EAX;
  undefined4 in_EDX;
  
  *(char *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) = (char)((uint)in_EDX >> 8);
  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
  *(char *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) = (char)in_EDX;
  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
  return;
}


// ==== FUN_0090e037 @ 0x0090e037 ====

void FUN_0090e037(void)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  uVar4 = *(uint *)(*(int *)(in_EAX + 0x1c) + 0x14);
  if (*(uint *)(in_EAX + 0x10) < uVar4) {
    uVar4 = *(uint *)(in_EAX + 0x10);
  }
  if (uVar4 != 0) {
    puVar5 = *(undefined4 **)(*(int *)(in_EAX + 0x1c) + 0x10);
    puVar6 = *(undefined4 **)(in_EAX + 0xc);
    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    *(int *)(in_EAX + 0xc) = *(int *)(in_EAX + 0xc) + uVar4;
    piVar1 = (int *)(*(int *)(in_EAX + 0x1c) + 0x10);
    *piVar1 = *piVar1 + uVar4;
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + uVar4;
    *(int *)(in_EAX + 0x10) = *(int *)(in_EAX + 0x10) - uVar4;
    piVar1 = (int *)(*(int *)(in_EAX + 0x1c) + 0x14);
    *piVar1 = *piVar1 - uVar4;
    iVar2 = *(int *)(in_EAX + 0x1c);
    if (*(int *)(iVar2 + 0x14) == 0) {
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar2 + 8);
    }
  }
  return;
}


// ==== FUN_0090e08b @ 0x0090e08b ====

uint FUN_0090e08b(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  if ((((param_1 == (int *)0x0) || (puVar1 = (undefined4 *)param_1[7], puVar1 == (undefined4 *)0x0))
      || (4 < param_2)) || (param_2 < 0)) {
    return 0xfffffffe;
  }
  if (((param_1[3] == 0) || ((*param_1 == 0 && (param_1[1] != 0)))) ||
     ((puVar1[1] == 0x29a && (param_2 != 4)))) {
    param_1[6] = (int)PTR_s_stream_error_00a2f09c;
    return 0xfffffffe;
  }
  if (param_1[4] == 0) goto LAB_0090e1b7;
  iVar2 = puVar1[8];
  *puVar1 = param_1;
  puVar1[8] = param_2;
  if (puVar1[1] == 0x2a) {
    puVar1[1] = 0x71;
    FUN_0090e013();
    if (puVar1[0x19] != 0) {
      FUN_0090e013();
      FUN_0090e013();
    }
    param_1[0xc] = 1;
  }
  if (puVar1[5] == 0) {
    if (((param_1[1] == 0) && (param_2 <= iVar2)) && (param_2 != 4)) goto LAB_0090e1b7;
LAB_0090e1ab:
    if (puVar1[1] == 0x29a) {
      if (param_1[1] != 0) {
LAB_0090e1b7:
        param_1[6] = (int)PTR_s_buffer_error_00a2f0a8;
        return 0xfffffffb;
      }
LAB_0090e1cb:
      if ((puVar1[0x1b] != 0) || ((param_2 != 0 && (puVar1[1] != 0x29a)))) goto LAB_0090e1e1;
    }
    else {
      if (param_1[1] == 0) goto LAB_0090e1cb;
LAB_0090e1e1:
      iVar2 = (**(code **)(&DAT_00a28ee8 + puVar1[0x1f] * 0xc))(puVar1,param_2);
      if ((iVar2 == 2) || (iVar2 == 3)) {
        puVar1[1] = 0x29a;
      }
      if ((iVar2 == 0) || (iVar2 == 2)) {
        if (param_1[4] != 0) {
          return 0;
        }
        goto LAB_0090e18c;
      }
      if (iVar2 == 1) {
        if (param_2 == 1) {
          FUN_0095c2ea(puVar1);
        }
        else {
          FUN_0095c25c(puVar1,0,0,0);
          if (param_2 == 3) {
            *(undefined2 *)(puVar1[0xf] + -2 + puVar1[0x11] * 2) = 0;
            uVar4 = puVar1[0x11] * 2 - 2;
            puVar5 = (undefined4 *)puVar1[0xf];
            for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
              *puVar5 = 0;
              puVar5 = puVar5 + 1;
            }
            for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
              *(undefined1 *)puVar5 = 0;
              puVar5 = (undefined4 *)((int)puVar5 + 1);
            }
          }
        }
        FUN_0090e037();
        if (param_1[4] == 0) goto LAB_0090e18c;
      }
    }
    if (param_2 == 4) {
      if (puVar1[6] == 0) {
        FUN_0090e013();
        FUN_0090e013();
        FUN_0090e037();
        puVar1[6] = 0xffffffff;
        return (uint)(puVar1[5] == 0);
      }
      return 1;
    }
  }
  else {
    FUN_0090e037();
    if (param_1[4] != 0) goto LAB_0090e1ab;
LAB_0090e18c:
    puVar1[8] = 0xffffffff;
  }
  return 0;
}


// ==== FUN_0090e2ca @ 0x0090e2ca ====

undefined4 FUN_0090e2ca(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (((param_1 == 0) || (iVar1 = *(int *)(param_1 + 0x1c), iVar1 == 0)) ||
     ((iVar2 = *(int *)(iVar1 + 4), iVar2 != 0x2a && ((iVar2 != 0x71 && (iVar2 != 0x29a)))))) {
    uVar3 = 0xfffffffe;
  }
  else {
    if (*(int *)(iVar1 + 8) != 0) {
      (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),*(int *)(iVar1 + 8));
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + 0x3c);
    if (iVar1 != 0) {
      (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),iVar1);
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + 0x38);
    if (iVar1 != 0) {
      (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),iVar1);
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + 0x30);
    if (iVar1 != 0) {
      (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),iVar1);
    }
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x1c));
    *(undefined4 *)(param_1 + 0x1c) = 0;
    if (iVar2 != 0x71) {
      return 0;
    }
    uVar3 = 0xfffffffd;
  }
  return uVar3;
}


// ==== FUN_0090e358 @ 0x0090e358 ====

void FUN_0090e358(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int in_EDX;
  undefined4 *puVar4;
  
  *(int *)(in_EDX + 0x34) = *(int *)(in_EDX + 0x24) << 1;
  *(undefined2 *)(*(int *)(in_EDX + 0x3c) + -2 + *(int *)(in_EDX + 0x44) * 2) = 0;
  uVar3 = *(int *)(in_EDX + 0x44) * 2 - 2;
  puVar4 = *(undefined4 **)(in_EDX + 0x3c);
  for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar4 = 0;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  iVar1 = *(int *)(in_EDX + 0x7c) * 0xc;
  *(uint *)(in_EDX + 0x78) = (uint)*(ushort *)(&DAT_00a28ee2 + iVar1);
  *(uint *)(in_EDX + 0x84) = (uint)*(ushort *)(&DAT_00a28ee0 + iVar1);
  *(uint *)(in_EDX + 0x88) = (uint)*(ushort *)(&DAT_00a28ee4 + iVar1);
  *(uint *)(in_EDX + 0x74) = (uint)*(ushort *)(&DAT_00a28ee6 + iVar1);
  *(undefined4 *)(in_EDX + 100) = 0;
  *(undefined4 *)(in_EDX + 0x54) = 0;
  *(undefined4 *)(in_EDX + 0x6c) = 0;
  *(undefined4 *)(in_EDX + 0x60) = 0;
  *(undefined4 *)(in_EDX + 0x40) = 0;
  *(undefined4 *)(in_EDX + 0x70) = 2;
  *(undefined4 *)(in_EDX + 0x58) = 2;
  return;
}


// ==== FUN_0090e3dd @ 0x0090e3dd ====

char * FUN_0090e3dd(uint param_1)

{
  uint uVar1;
  char *pcVar2;
  int in_ECX;
  char *pcVar3;
  char *pcVar5;
  char *pcVar4;
  char *pcVar6;
  char *pcVar7;
  uint local_14;
  char *local_10;
  uint local_c;
  char local_6;
  char local_5;
  
  local_c = *(uint *)(in_ECX + 0x74);
  uVar1 = *(uint *)(in_ECX + 100);
  pcVar3 = (char *)(*(int *)(in_ECX + 0x30) + uVar1);
  pcVar7 = *(char **)(in_ECX + 0x70);
  if (*(int *)(in_ECX + 0x24) - 0x106U < uVar1) {
    local_14 = (uVar1 - *(int *)(in_ECX + 0x24)) + 0x106;
  }
  else {
    local_14 = 0;
  }
  local_5 = pcVar3[(int)(pcVar7 + -1)];
  local_6 = pcVar3[(int)pcVar7];
  if (*(char **)(in_ECX + 0x84) <= pcVar7) {
    local_c = local_c >> 2;
  }
  pcVar2 = *(char **)(in_ECX + 0x6c);
  local_10 = *(char **)(in_ECX + 0x88);
  if (pcVar2 < *(char **)(in_ECX + 0x88)) {
    local_10 = pcVar2;
  }
  do {
    pcVar6 = (char *)(*(int *)(in_ECX + 0x30) + param_1);
    if ((((pcVar6[(int)pcVar7] == local_6) && (pcVar6[(int)(pcVar7 + -1)] == local_5)) &&
        (*pcVar6 == *pcVar3)) && (pcVar6[1] == pcVar3[1])) {
      pcVar6 = pcVar6 + 2;
      pcVar5 = pcVar3 + 2;
      while (((((pcVar4 = pcVar5 + 1, *pcVar4 == pcVar6[1] &&
                (pcVar4 = pcVar5 + 2, *pcVar4 == pcVar6[2])) &&
               ((pcVar4 = pcVar5 + 3, *pcVar4 == pcVar6[3] &&
                ((pcVar4 = pcVar5 + 4, *pcVar4 == pcVar6[4] &&
                 (pcVar4 = pcVar5 + 5, *pcVar4 == pcVar6[5])))))) &&
              (pcVar4 = pcVar5 + 6, *pcVar4 == pcVar6[6])) &&
             (pcVar4 = pcVar5 + 7, *pcVar4 == pcVar6[7]))) {
        pcVar4 = pcVar5 + 8;
        pcVar6 = pcVar6 + 8;
        if ((*pcVar4 != *pcVar6) || (pcVar5 = pcVar4, pcVar3 + 0x102 <= pcVar4)) break;
      }
      pcVar4 = pcVar4 + (0x102 - (int)(pcVar3 + 0x102));
      if ((int)pcVar7 < (int)pcVar4) {
        *(uint *)(in_ECX + 0x68) = param_1;
        if ((int)local_10 <= (int)pcVar4) break;
        local_5 = (pcVar3 + (int)pcVar4)[-1];
        local_6 = pcVar3[(int)pcVar4];
        pcVar7 = pcVar4;
      }
    }
    pcVar4 = pcVar7;
    param_1 = (uint)*(ushort *)(*(int *)(in_ECX + 0x38) + (*(uint *)(in_ECX + 0x2c) & param_1) * 2);
    if (param_1 <= local_14) break;
    local_c = local_c - 1;
    pcVar7 = pcVar4;
  } while (local_c != 0);
  if (pcVar4 <= pcVar2) {
    pcVar2 = pcVar4;
  }
  return pcVar2;
}


// ==== FUN_0090e529 @ 0x0090e529 ====

void FUN_0090e529(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *unaff_EBX;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uint local_8;
  
  uVar1 = unaff_EBX[9];
  do {
    uVar8 = unaff_EBX[0x19];
    uVar5 = (unaff_EBX[0xd] - uVar8) - unaff_EBX[0x1b];
    if (uVar5 == 0) {
      if ((uVar8 == 0) && (unaff_EBX[0x1b] == 0)) {
        uVar5 = uVar1;
      }
      else {
LAB_0090e561:
        if ((uVar1 - 0x106) + unaff_EBX[9] <= uVar8) {
          puVar10 = (undefined4 *)(unaff_EBX[0xc] + uVar1);
          puVar11 = (undefined4 *)unaff_EBX[0xc];
          for (uVar8 = uVar1 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *puVar11 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar11 = puVar11 + 1;
          }
          for (uVar8 = uVar1 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          iVar9 = unaff_EBX[0x11];
          unaff_EBX[0x1a] = unaff_EBX[0x1a] - uVar1;
          unaff_EBX[0x19] = unaff_EBX[0x19] - uVar1;
          unaff_EBX[0x15] = unaff_EBX[0x15] - uVar1;
          puVar6 = (ushort *)(unaff_EBX[0xf] + iVar9 * 2);
          do {
            puVar6 = puVar6 + -1;
            iVar9 = iVar9 + -1;
            *puVar6 = ~-(ushort)(*puVar6 < uVar1) & *puVar6 - (short)uVar1;
          } while (iVar9 != 0);
          puVar6 = (ushort *)(unaff_EBX[0xe] + uVar1 * 2);
          uVar8 = uVar1;
          do {
            puVar6 = puVar6 + -1;
            uVar8 = uVar8 - 1;
            *puVar6 = ~-(ushort)(*puVar6 < uVar1) & *puVar6 - (short)uVar1;
          } while (uVar8 != 0);
          uVar5 = uVar5 + uVar1;
        }
      }
    }
    else {
      if (uVar5 != 0xffffffff) goto LAB_0090e561;
      uVar5 = 0xfffffffe;
    }
    piVar2 = (int *)*unaff_EBX;
    if (piVar2[1] == 0) {
      return;
    }
    iVar9 = unaff_EBX[0x1b];
    iVar3 = unaff_EBX[0x19];
    uVar8 = piVar2[1];
    iVar4 = unaff_EBX[0xc];
    local_8 = uVar8;
    if (uVar5 < uVar8) {
      local_8 = uVar5;
    }
    if (local_8 == 0) {
      local_8 = 0;
    }
    else {
      piVar2[1] = uVar8 - local_8;
      if (*(int *)(piVar2[7] + 0x18) == 0) {
        iVar7 = FUN_0095ae57(piVar2[0xc],*piVar2,local_8);
        piVar2[0xc] = iVar7;
      }
      puVar10 = (undefined4 *)*piVar2;
      puVar11 = (undefined4 *)(iVar9 + iVar3 + iVar4);
      for (uVar8 = local_8 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar11 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar11 = puVar11 + 1;
      }
      for (uVar8 = local_8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      *piVar2 = *piVar2 + local_8;
      piVar2[2] = piVar2[2] + local_8;
    }
    unaff_EBX[0x1b] = unaff_EBX[0x1b] + local_8;
    if (2 < (uint)unaff_EBX[0x1b]) {
      uVar8 = (uint)*(byte *)(unaff_EBX[0x19] + unaff_EBX[0xc]);
      unaff_EBX[0x10] = uVar8;
      unaff_EBX[0x10] =
           (uVar8 << ((byte)unaff_EBX[0x14] & 0x1f) ^
           (uint)((byte *)(unaff_EBX[0x19] + unaff_EBX[0xc]))[1]) & unaff_EBX[0x13];
    }
    if (0x105 < (uint)unaff_EBX[0x1b]) {
      return;
    }
    if (*(int *)(*unaff_EBX + 4) == 0) {
      return;
    }
  } while( true );
}


// ==== FUN_0090e683 @ 0x0090e683 ====

char FUN_0090e683(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0xffff;
  if (param_1[3] - 5U < 0xffff) {
    uVar5 = param_1[3] - 5U;
  }
  do {
    uVar3 = param_1[0x1b];
    if (uVar3 < 2) {
      FUN_0090e529();
      uVar3 = param_1[0x1b];
      if (uVar3 == 0) {
        if (param_2 == 0) {
          return '\0';
        }
        iVar2 = param_1[0x15];
        if (iVar2 < 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = param_1[0xc] + iVar2;
        }
        FUN_0095c4b8(param_1,iVar4,param_1[0x19] - iVar2,param_2 == 4);
        param_1[0x15] = param_1[0x19];
        FUN_0090e037();
        if (*(int *)(*param_1 + 0x10) != 0) {
          return (param_2 == 4) * '\x02' + '\x01';
        }
        if (param_2 == 4) {
          return '\x02';
        }
        return '\0';
      }
    }
    piVar1 = param_1 + 0x19;
    *piVar1 = *piVar1 + uVar3;
    iVar2 = param_1[0x15];
    param_1[0x1b] = 0;
    uVar3 = iVar2 + uVar5;
    if ((*piVar1 == 0) || (uVar3 <= (uint)param_1[0x19])) {
      param_1[0x1b] = param_1[0x19] - uVar3;
      param_1[0x19] = uVar3;
      if (iVar2 < 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = param_1[0xc] + iVar2;
      }
      FUN_0095c4b8(param_1,iVar4,uVar3 - iVar2,0);
      param_1[0x15] = param_1[0x19];
      FUN_0090e037();
      if (*(int *)(*param_1 + 0x10) == 0) {
        return '\0';
      }
    }
    iVar2 = param_1[0x15];
    if (param_1[9] - 0x106U <= (uint)(param_1[0x19] - iVar2)) {
      if (iVar2 < 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = param_1[0xc] + iVar2;
      }
      FUN_0095c4b8(param_1,iVar4,param_1[0x19] - iVar2,0);
      param_1[0x15] = param_1[0x19];
      FUN_0090e037();
      if (*(int *)(*param_1 + 0x10) == 0) {
        return '\0';
      }
    }
  } while( true );
}


// ==== FUN_0090e7a9 @ 0x0090e7a9 ====

char FUN_0090e7a9(int *param_1,int param_2)

{
  int *piVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  bool bVar9;
  
  uVar8 = 0;
  do {
    uVar5 = param_1[0x1b];
    if (uVar5 < 0x106) {
      FUN_0090e529();
      uVar5 = param_1[0x1b];
      if ((uVar5 < 0x106) && (param_2 == 0)) {
        return '\0';
      }
      if (uVar5 == 0) {
        iVar4 = param_1[0x15];
        if (iVar4 < 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = param_1[0xc] + iVar4;
        }
        FUN_0095c4b8(param_1,iVar6,param_1[0x19] - iVar4,param_2 == 4);
        param_1[0x15] = param_1[0x19];
        FUN_0090e037();
        if (*(int *)(*param_1 + 0x10) != 0) {
          return (param_2 == 4) * '\x02' + '\x01';
        }
        if (param_2 == 4) {
          return '\x02';
        }
        return '\0';
      }
    }
    if (2 < uVar5) {
      uVar8 = (param_1[0x10] << ((byte)param_1[0x14] & 0x1f) ^
              (uint)*(byte *)(param_1[0xc] + 2 + param_1[0x19])) & param_1[0x13];
      param_1[0x10] = uVar8;
      uVar3 = *(ushort *)(param_1[0xf] + uVar8 * 2);
      uVar8 = (uint)uVar3;
      *(ushort *)(param_1[0xe] + (param_1[0xb] & param_1[0x19]) * 2) = uVar3;
      *(short *)(param_1[0xf] + param_1[0x10] * 2) = (short)param_1[0x19];
    }
    if (((uVar8 != 0) && (param_1[0x19] - uVar8 <= param_1[9] - 0x106U)) && (param_1[0x20] != 2)) {
      iVar4 = FUN_0090e3dd(uVar8);
      param_1[0x16] = iVar4;
    }
    if ((uint)param_1[0x16] < 3) {
      bVar7 = *(byte *)(param_1[0x19] + param_1[0xc]);
      *(undefined2 *)(param_1[0x5a7] + param_1[0x5a6] * 2) = 0;
      *(byte *)(param_1[0x5a4] + param_1[0x5a6]) = bVar7;
      param_1[0x5a6] = param_1[0x5a6] + 1;
      *(short *)(param_1 + bVar7 + 0x23) = (short)param_1[bVar7 + 0x23] + 1;
      bVar9 = param_1[0x5a6] == param_1[0x5a5] + -1;
      param_1[0x1b] = param_1[0x1b] + -1;
LAB_0090e9b3:
      param_1[0x19] = param_1[0x19] + 1;
    }
    else {
      sVar2 = (short)param_1[0x19] - (short)param_1[0x1a];
      bVar7 = (char)param_1[0x16] - 3;
      *(short *)(param_1[0x5a7] + param_1[0x5a6] * 2) = sVar2;
      *(byte *)(param_1[0x5a4] + param_1[0x5a6]) = bVar7;
      param_1[0x5a6] = param_1[0x5a6] + 1;
      uVar3 = sVar2 - 1;
      *(short *)(param_1 + (byte)(&DAT_00a2ee60)[bVar7] + 0x124) =
           (short)param_1[(byte)(&DAT_00a2ee60)[bVar7] + 0x124] + 1;
      if (uVar3 < 0x100) {
        bVar7 = (&DAT_00a2ec60)[uVar3];
      }
      else {
        bVar7 = (&DAT_00a2ed60)[uVar3 >> 7];
      }
      *(short *)(param_1 + bVar7 + 0x260) = (short)param_1[bVar7 + 0x260] + 1;
      bVar9 = param_1[0x5a6] == param_1[0x5a5] + -1;
      uVar5 = param_1[0x16];
      param_1[0x1b] = param_1[0x1b] - uVar5;
      if ((uVar5 <= (uint)param_1[0x1e]) && (2 < (uint)param_1[0x1b])) {
        param_1[0x16] = uVar5 - 1;
        do {
          param_1[0x19] = param_1[0x19] + 1;
          uVar8 = ((uint)*(byte *)(param_1[0x19] + 2U + param_1[0xc]) ^
                  param_1[0x10] << ((byte)param_1[0x14] & 0x1f)) & param_1[0x13];
          param_1[0x10] = uVar8;
          uVar3 = *(ushort *)(param_1[0xf] + uVar8 * 2);
          uVar8 = (uint)uVar3;
          *(ushort *)(param_1[0xe] + (param_1[0x19] & param_1[0xb]) * 2) = uVar3;
          *(short *)(param_1[0xf] + param_1[0x10] * 2) = (short)param_1[0x19];
          piVar1 = param_1 + 0x16;
          *piVar1 = *piVar1 + -1;
        } while (*piVar1 != 0);
        goto LAB_0090e9b3;
      }
      param_1[0x19] = param_1[0x19] + uVar5;
      param_1[0x16] = 0;
      uVar5 = (uint)*(byte *)(param_1[0x19] + param_1[0xc]);
      param_1[0x10] = uVar5;
      param_1[0x10] =
           (uVar5 << ((byte)param_1[0x14] & 0x1f) ^
           (uint)((byte *)(param_1[0x19] + param_1[0xc]))[1]) & param_1[0x13];
    }
    if (bVar9) {
      iVar4 = param_1[0x15];
      if (iVar4 < 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = param_1[0xc] + iVar4;
      }
      FUN_0095c4b8(param_1,iVar6,param_1[0x19] - iVar4,0);
      param_1[0x15] = param_1[0x19];
      FUN_0090e037();
      if (*(int *)(*param_1 + 0x10) == 0) {
        return '\0';
      }
    }
  } while( true );
}


// ==== FUN_0090ea55 @ 0x0090ea55 ====

char FUN_0090ea55(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  int iVar10;
  uint local_8;
  
  local_8 = 0;
LAB_0090ea65:
  do {
    uVar6 = param_1[0x1b];
    if (uVar6 < 0x106) {
      FUN_0090e529();
      uVar6 = param_1[0x1b];
      if ((uVar6 < 0x106) && (param_2 == 0)) {
        return '\0';
      }
      if (uVar6 == 0) {
        if (param_1[0x18] != 0) {
          bVar9 = *(byte *)(param_1[0x19] + -1 + param_1[0xc]);
          piVar1 = param_1 + 0x5a6;
          *(undefined2 *)(param_1[0x5a7] + *piVar1 * 2) = 0;
          *(byte *)(param_1[0x5a4] + *piVar1) = bVar9;
          *piVar1 = *piVar1 + 1;
          *(short *)(param_1 + bVar9 + 0x23) = (short)param_1[bVar9 + 0x23] + 1;
          param_1[0x18] = 0;
        }
        iVar7 = param_1[0x15];
        if (iVar7 < 0) {
          iVar10 = 0;
        }
        else {
          iVar10 = param_1[0xc] + iVar7;
        }
        FUN_0095c4b8(param_1,iVar10,param_1[0x19] - iVar7,param_2 == 4);
        param_1[0x15] = param_1[0x19];
        FUN_0090e037();
        if (*(int *)(*param_1 + 0x10) != 0) {
          return (param_2 == 4) * '\x02' + '\x01';
        }
        if (param_2 == 4) {
          return '\x02';
        }
        return '\0';
      }
    }
    if (2 < uVar6) {
      uVar6 = (param_1[0x10] << ((byte)param_1[0x14] & 0x1f) ^
              (uint)*(byte *)(param_1[0xc] + 2 + param_1[0x19])) & param_1[0x13];
      param_1[0x10] = uVar6;
      uVar5 = *(ushort *)(param_1[0xf] + uVar6 * 2);
      local_8 = (uint)uVar5;
      *(ushort *)(param_1[0xe] + (param_1[0xb] & param_1[0x19]) * 2) = uVar5;
      *(short *)(param_1[0xf] + param_1[0x10] * 2) = (short)param_1[0x19];
    }
    param_1[0x1c] = param_1[0x16];
    param_1[0x17] = param_1[0x1a];
    param_1[0x16] = 2;
    if (((local_8 != 0) && ((uint)param_1[0x1c] < (uint)param_1[0x1e])) &&
       (param_1[0x19] - local_8 <= param_1[9] - 0x106U)) {
      if (param_1[0x20] != 2) {
        iVar7 = FUN_0090e3dd(local_8);
        param_1[0x16] = iVar7;
      }
      if (((uint)param_1[0x16] < 6) &&
         ((param_1[0x20] == 1 ||
          ((param_1[0x16] == 3 && (0x1000 < (uint)(param_1[0x19] - param_1[0x1a]))))))) {
        param_1[0x16] = 2;
      }
    }
    if (((uint)param_1[0x1c] < 3) || ((uint)param_1[0x1c] < (uint)param_1[0x16])) {
      if (param_1[0x18] == 0) {
        param_1[0x19] = param_1[0x19] + 1;
        param_1[0x1b] = param_1[0x1b] + -1;
        param_1[0x18] = 1;
        goto LAB_0090ea65;
      }
      bVar9 = *(byte *)(param_1[0x19] + -1 + param_1[0xc]);
      *(undefined2 *)(param_1[0x5a7] + param_1[0x5a6] * 2) = 0;
      *(byte *)(param_1[0x5a4] + param_1[0x5a6]) = bVar9;
      param_1[0x5a6] = param_1[0x5a6] + 1;
      *(short *)(param_1 + bVar9 + 0x23) = (short)param_1[bVar9 + 0x23] + 1;
      if (param_1[0x5a6] == param_1[0x5a5] + -1) {
        iVar7 = param_1[0x15];
        if (iVar7 < 0) {
          iVar10 = 0;
        }
        else {
          iVar10 = param_1[0xc] + iVar7;
        }
        FUN_0095c4b8(param_1,iVar10,param_1[0x19] - iVar7,0);
        param_1[0x15] = param_1[0x19];
        FUN_0090e037();
      }
      param_1[0x19] = param_1[0x19] + 1;
      param_1[0x1b] = param_1[0x1b] + -1;
    }
    else {
      iVar7 = param_1[0x1b];
      iVar10 = param_1[0x19];
      sVar4 = (short)param_1[0x19] - (short)param_1[0x17];
      bVar9 = (char)param_1[0x1c] - 3;
      *(short *)(param_1[0x5a7] + param_1[0x5a6] * 2) = sVar4 + -1;
      *(byte *)(param_1[0x5a4] + param_1[0x5a6]) = bVar9;
      param_1[0x5a6] = param_1[0x5a6] + 1;
      uVar5 = sVar4 - 2;
      *(short *)(param_1 + (byte)(&DAT_00a2ee60)[bVar9] + 0x124) =
           (short)param_1[(byte)(&DAT_00a2ee60)[bVar9] + 0x124] + 1;
      if (uVar5 < 0x100) {
        bVar9 = (&DAT_00a2ec60)[uVar5];
      }
      else {
        bVar9 = (&DAT_00a2ed60)[uVar5 >> 7];
      }
      *(short *)(param_1 + bVar9 + 0x260) = (short)param_1[bVar9 + 0x260] + 1;
      iVar2 = param_1[0x5a5];
      iVar3 = param_1[0x5a6];
      param_1[0x1b] = param_1[0x1b] + (1 - param_1[0x1c]);
      param_1[0x1c] = param_1[0x1c] + -2;
      do {
        param_1[0x19] = param_1[0x19] + 1;
        uVar6 = param_1[0x19];
        if (uVar6 <= (uint)(iVar10 + -3 + iVar7)) {
          uVar8 = (param_1[0x10] << ((byte)param_1[0x14] & 0x1f) ^
                  (uint)*(byte *)(param_1[0xc] + 2 + uVar6)) & param_1[0x13];
          param_1[0x10] = uVar8;
          uVar5 = *(ushort *)(param_1[0xf] + uVar8 * 2);
          local_8 = (uint)uVar5;
          *(ushort *)(param_1[0xe] + (param_1[0xb] & uVar6) * 2) = uVar5;
          *(short *)(param_1[0xf] + param_1[0x10] * 2) = (short)param_1[0x19];
        }
        piVar1 = param_1 + 0x1c;
        *piVar1 = *piVar1 + -1;
      } while (*piVar1 != 0);
      param_1[0x18] = 0;
      param_1[0x19] = param_1[0x19] + 1;
      param_1[0x16] = 2;
      if (iVar3 != iVar2 + -1) goto LAB_0090ea65;
      iVar7 = param_1[0x15];
      if (iVar7 < 0) {
        iVar10 = 0;
      }
      else {
        iVar10 = param_1[0xc] + iVar7;
      }
      FUN_0095c4b8(param_1,iVar10,param_1[0x19] - iVar7,0);
      param_1[0x15] = param_1[0x19];
      FUN_0090e037();
    }
    if (*(int *)(*param_1 + 0x10) == 0) {
      return '\0';
    }
  } while( true );
}


// ==== FUN_0090eddb @ 0x0090eddb ====

undefined4 FUN_0090eddb(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((param_1 == 0) || (iVar1 = *(int *)(param_1 + 0x1c), iVar1 == 0)) ||
      (*(int *)(param_1 + 0x20) == 0)) || (*(int *)(param_1 + 0x24) == 0)) {
    uVar2 = 0xfffffffe;
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 2;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 8);
    if (*(int *)(iVar1 + 0x18) < 0) {
      *(undefined4 *)(iVar1 + 0x18) = 0;
    }
    *(uint *)(iVar1 + 4) = (-(uint)(*(int *)(iVar1 + 0x18) != 0) & 0x47) + 0x2a;
    *(undefined4 *)(param_1 + 0x30) = 1;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    FUN_0095bf2b(iVar1);
    FUN_0090e358();
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_0090ee4f @ 0x0090ee4f ====

undefined4
FUN_0090ee4f(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,char *param_7,
            int param_8)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  uint local_8;
  
  if (((param_7 == (char *)0x0) || (*param_7 != '1')) || (param_8 != 0x38)) {
    uVar4 = 0xfffffffa;
  }
  else {
    if (param_1 != 0) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      if (*(int *)(param_1 + 0x20) == 0) {
        *(code **)(param_1 + 0x20) = FUN_0095c673;
        *(undefined4 *)(param_1 + 0x28) = 0;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(code **)(param_1 + 0x24) = FUN_0095c693;
      }
      if (param_2 == -1) {
        param_2 = 6;
      }
      bVar6 = param_4 < 0;
      if (bVar6) {
        param_4 = -param_4;
      }
      local_8 = (uint)bVar6;
      if (((((0 < param_5) && (param_5 < 10)) &&
           ((param_3 == 8 && ((8 < param_4 && (param_4 < 0x10)))))) && (-1 < param_2)) &&
         (((param_2 < 10 && (-1 < param_6)) && (param_6 < 3)))) {
        piVar1 = (int *)(**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x16b8);
        if (piVar1 != (int *)0x0) {
          piVar1[1] = 0x2a;
          *(int **)(param_1 + 0x1c) = piVar1;
          piVar1[10] = param_4;
          piVar1[6] = local_8;
          iVar5 = 1 << ((byte)param_4 & 0x1f);
          piVar1[0xb] = iVar5 + -1;
          iVar2 = 1 << ((byte)(param_5 + 7) & 0x1f);
          piVar1[0x12] = param_5 + 7;
          *piVar1 = param_1;
          piVar1[0x11] = iVar2;
          piVar1[0x13] = iVar2 + -1;
          piVar1[9] = iVar5;
          piVar1[0x14] = (param_5 + 9U) / 3;
          iVar2 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),iVar5,2);
          piVar1[0xc] = iVar2;
          iVar2 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),piVar1[9],2);
          piVar1[0xe] = iVar2;
          iVar2 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),piVar1[0x11],2);
          piVar1[0xf] = iVar2;
          uVar3 = 1 << ((char)param_5 + 6U & 0x1f);
          piVar1[0x5a5] = uVar3;
          iVar2 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),uVar3,4);
          uVar3 = piVar1[0x5a5];
          piVar1[3] = uVar3 << 2;
          piVar1[2] = iVar2;
          if (((piVar1[0xc] != 0) && (piVar1[0xe] != 0)) && ((piVar1[0xf] != 0 && (iVar2 != 0)))) {
            piVar1[0x5a4] = iVar2 + uVar3 * 3;
            piVar1[0x1f] = param_2;
            piVar1[0x5a7] = iVar2 + (uVar3 & 0xfffffffe);
            piVar1[0x20] = param_6;
            *(undefined1 *)((int)piVar1 + 0x1d) = 8;
            uVar4 = FUN_0090eddb(param_1);
            return uVar4;
          }
          *(undefined **)(param_1 + 0x18) = PTR_s_insufficient_memory_00a2f0a4;
          FUN_0090e2ca(param_1);
        }
        return 0xfffffffc;
      }
    }
    uVar4 = 0xfffffffe;
  }
  return uVar4;
}


// ==== FUN_0090f032 @ 0x0090f032 ====

undefined4 FUN_0090f032(int param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (puVar1 = *(uint **)(param_1 + 0x1c), puVar1 == (uint *)0x0)) {
    uVar2 = 0xfffffffe;
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *puVar1 = -(uint)(puVar1[3] != 0) & 7;
    FUN_0095c6ae(*(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x14),param_1,0);
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_0090f076 @ 0x0090f076 ====

undefined4 FUN_0090f076(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_1 == 0) || (*(int *)(param_1 + 0x1c) == 0)) || (*(int *)(param_1 + 0x24) == 0)) {
    uVar2 = 0xfffffffe;
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + 0x14);
    if (iVar1 != 0) {
      FUN_0095cee6(iVar1,param_1);
    }
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x1c));
    *(undefined4 *)(param_1 + 0x1c) = 0;
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_0090f0b7 @ 0x0090f0b7 ====

undefined4 FUN_0090f0b7(int param_1,int param_2,char *param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_3 == (char *)0x0) || (*param_3 != '1')) || (param_4 != 0x38)) {
    uVar2 = 0xfffffffa;
  }
  else if (param_1 == 0) {
    uVar2 = 0xfffffffe;
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = 0;
    if (*(int *)(param_1 + 0x20) == 0) {
      *(code **)(param_1 + 0x20) = FUN_0095c673;
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
    if (*(int *)(param_1 + 0x24) == 0) {
      *(code **)(param_1 + 0x24) = FUN_0095c693;
    }
    iVar1 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x18);
    *(int *)(param_1 + 0x1c) = iVar1;
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x14) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xc) = 0;
      if (param_2 < 0) {
        param_2 = -param_2;
        *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xc) = 1;
      }
      if ((param_2 < 8) || (0xf < param_2)) {
        uVar2 = 0xfffffffe;
      }
      else {
        *(int *)(*(int *)(param_1 + 0x1c) + 0x10) = param_2;
        uVar2 = FUN_0095c717(param_1,~-(uint)(*(int *)(*(int *)(param_1 + 0x1c) + 0xc) != 0) &
                                     0x95ae57,1 << ((byte)param_2 & 0x1f));
        *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x14) = uVar2;
        if (*(int *)(*(int *)(param_1 + 0x1c) + 0x14) != 0) {
          FUN_0090f032(param_1);
          return 0;
        }
        uVar2 = 0xfffffffc;
      }
      FUN_0090f076(param_1);
      return uVar2;
    }
    uVar2 = 0xfffffffc;
  }
  return uVar2;
}


// ==== FUN_0090f198 @ 0x0090f198 ====

void FUN_0090f198(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0090f0b7(param_1,0xf,param_2,param_3);
  return;
}


// ==== FUN_0090f1b1 @ 0x0090f1b1 ====

int FUN_0090f1b1(int *param_1,int param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (((param_1 == (int *)0x0) || (puVar4 = (undefined4 *)param_1[7], puVar4 == (undefined4 *)0x0))
     || (*param_1 == 0)) {
LAB_0090f3f5:
    return -2;
  }
  iVar3 = -5;
  if (param_2 == 4) {
    param_2 = -5;
  }
  else {
    param_2 = 0;
  }
  do {
    switch(*puVar4) {
    case 0:
      if (param_1[1] == 0) {
        return iVar3;
      }
      param_1[2] = param_1[2] + 1;
      param_1[1] = param_1[1] + -1;
      *(uint *)(param_1[7] + 4) = (uint)*(byte *)*param_1;
      puVar4 = (undefined4 *)param_1[7];
      uVar2 = puVar4[1];
      *param_1 = *param_1 + 1;
      if (((byte)uVar2 & 0xf) == 8) {
        if (((uint)puVar4[1] >> 4) + 8 <= (uint)puVar4[4]) {
          *puVar4 = 1;
          iVar3 = param_2;
          goto switchD_0090f1f2_caseD_1;
        }
        *puVar4 = 0xd;
        param_1[6] = (int)s_invalid_window_size_00a28fa4;
      }
      else {
        *puVar4 = 0xd;
        param_1[6] = (int)s_unknown_compression_method_00a28fb8;
      }
      goto LAB_0090f3db;
    case 1:
switchD_0090f1f2_caseD_1:
      if (param_1[1] == 0) {
        return iVar3;
      }
      param_1[2] = param_1[2] + 1;
      param_1[1] = param_1[1] + -1;
      bVar1 = *(byte *)*param_1;
      *param_1 = (int)((byte *)*param_1 + 1);
      puVar4 = (undefined4 *)param_1[7];
      if ((puVar4[1] * 0x100 + (uint)bVar1) % 0x1f != 0) {
        *puVar4 = 0xd;
        param_1[6] = (int)s_incorrect_header_check_00a28f8c;
        goto LAB_0090f3db;
      }
      if ((bVar1 & 0x20) != 0) {
        *(undefined4 *)param_1[7] = 2;
        iVar3 = param_2;
        goto switchD_0090f1f2_caseD_2;
      }
      *puVar4 = 7;
      iVar3 = param_2;
      break;
    case 2:
switchD_0090f1f2_caseD_2:
      if (param_1[1] != 0) {
        param_1[2] = param_1[2] + 1;
        param_1[1] = param_1[1] + -1;
        *(uint *)(param_1[7] + 8) = (uint)*(byte *)*param_1 << 0x18;
        *param_1 = *param_1 + 1;
        *(undefined4 *)param_1[7] = 3;
        iVar3 = param_2;
switchD_0090f1f2_caseD_3:
        if (param_1[1] != 0) {
          param_1[2] = param_1[2] + 1;
          param_1[1] = param_1[1] + -1;
          *(int *)(param_1[7] + 8) = *(int *)(param_1[7] + 8) + (uint)*(byte *)*param_1 * 0x10000;
          *param_1 = *param_1 + 1;
          *(undefined4 *)param_1[7] = 4;
          iVar3 = param_2;
switchD_0090f1f2_caseD_4:
          if (param_1[1] != 0) {
            param_1[2] = param_1[2] + 1;
            param_1[1] = param_1[1] + -1;
            *(int *)(param_1[7] + 8) = *(int *)(param_1[7] + 8) + (uint)*(byte *)*param_1 * 0x100;
            *param_1 = *param_1 + 1;
            *(undefined4 *)param_1[7] = 5;
            iVar3 = param_2;
switchD_0090f1f2_caseD_5:
            if (param_1[1] != 0) {
              param_1[2] = param_1[2] + 1;
              param_1[1] = param_1[1] + -1;
              *(int *)(param_1[7] + 8) = *(int *)(param_1[7] + 8) + (uint)*(byte *)*param_1;
              *param_1 = *param_1 + 1;
              param_1[0xc] = ((undefined4 *)param_1[7])[2];
              *(undefined4 *)param_1[7] = 6;
              return 2;
            }
          }
        }
      }
      return iVar3;
    case 3:
      goto switchD_0090f1f2_caseD_3;
    case 4:
      goto switchD_0090f1f2_caseD_4;
    case 5:
      goto switchD_0090f1f2_caseD_5;
    case 6:
      *(undefined4 *)param_1[7] = 0xd;
      param_1[6] = (int)s_need_dictionary_00a28f64;
      *(undefined4 *)(param_1[7] + 4) = 0;
      return -2;
    case 7:
      iVar3 = FUN_0095c798(*(undefined4 *)(param_1[7] + 0x14),param_1,iVar3);
      if (iVar3 == -3) {
        *(undefined4 *)param_1[7] = 0xd;
        *(undefined4 *)(param_1[7] + 4) = 0;
        iVar3 = -3;
      }
      else {
        if (iVar3 == 0) {
          iVar3 = param_2;
        }
        if (iVar3 != 1) {
          return iVar3;
        }
        FUN_0095c6ae(*(undefined4 *)(param_1[7] + 0x14),param_1,param_1[7] + 4);
        puVar4 = (undefined4 *)param_1[7];
        if (puVar4[3] == 0) {
          *puVar4 = 8;
          iVar3 = param_2;
          goto switchD_0090f1f2_caseD_8;
        }
        *puVar4 = 0xc;
        iVar3 = param_2;
      }
      break;
    case 8:
switchD_0090f1f2_caseD_8:
      if (param_1[1] == 0) {
        return iVar3;
      }
      param_1[2] = param_1[2] + 1;
      param_1[1] = param_1[1] + -1;
      *(uint *)(param_1[7] + 8) = (uint)*(byte *)*param_1 << 0x18;
      *param_1 = *param_1 + 1;
      *(undefined4 *)param_1[7] = 9;
      iVar3 = param_2;
    case 9:
      if (param_1[1] == 0) {
        return iVar3;
      }
      param_1[2] = param_1[2] + 1;
      param_1[1] = param_1[1] + -1;
      *(int *)(param_1[7] + 8) = *(int *)(param_1[7] + 8) + (uint)*(byte *)*param_1 * 0x10000;
      *param_1 = *param_1 + 1;
      *(undefined4 *)param_1[7] = 10;
      iVar3 = param_2;
switchD_0090f1f2_caseD_a:
      if (param_1[1] == 0) {
        return iVar3;
      }
      param_1[2] = param_1[2] + 1;
      param_1[1] = param_1[1] + -1;
      *(int *)(param_1[7] + 8) = *(int *)(param_1[7] + 8) + (uint)*(byte *)*param_1 * 0x100;
      *param_1 = *param_1 + 1;
      *(undefined4 *)param_1[7] = 0xb;
      iVar3 = param_2;
switchD_0090f1f2_caseD_b:
      if (param_1[1] == 0) {
        return iVar3;
      }
      param_1[2] = param_1[2] + 1;
      param_1[1] = param_1[1] + -1;
      *(int *)(param_1[7] + 8) = *(int *)(param_1[7] + 8) + (uint)*(byte *)*param_1;
      puVar4 = (undefined4 *)param_1[7];
      *param_1 = *param_1 + 1;
      if (puVar4[1] == puVar4[2]) {
        *(undefined4 *)param_1[7] = 0xc;
LAB_0090f3f5:
        return 1;
      }
      *puVar4 = 0xd;
      param_1[6] = (int)s_incorrect_data_check_00a28f74;
LAB_0090f3db:
      *(undefined4 *)(param_1[7] + 4) = 5;
      iVar3 = param_2;
      break;
    case 10:
      goto switchD_0090f1f2_caseD_a;
    case 0xb:
      goto switchD_0090f1f2_caseD_b;
    case 0xc:
      goto LAB_0090f3f5;
    case 0xd:
      return -3;
    default:
      goto LAB_0090f3f5;
    }
    puVar4 = (undefined4 *)param_1[7];
  } while( true );
}


// ==== FUN_0090f524 @ 0x0090f524 ====

undefined4 FUN_0090f524(undefined1 *param_1)

{
  return CONCAT31(CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]),param_1[3]);
}


// ==== FUN_0090f54e @ 0x0090f54e ====

int FUN_0090f54e(byte *param_1)

{
  undefined4 in_EAX;
  
  return CONCAT22((short)((uint)in_EAX >> 0x10),(ushort)*param_1) * 0x100 +
         CONCAT22((short)((uint)param_1 >> 0x10),(ushort)param_1[1]);
}


// ==== FUN_0090f568 @ 0x0090f568 ====

void FUN_0090f568(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_008f0db9(param_1,param_2,param_3);
  FUN_008ee260();
  return;
}


// ==== FUN_0090f581 @ 0x0090f581 ====

bool FUN_0090f581(int param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar1 = param_1;
  bVar3 = true;
  if ((*(byte *)(param_1 + 0x10c) & 0x20) == 0) {
    if ((*(byte *)(param_1 + 0x5d) & 8) == 0) goto LAB_0090f5af;
  }
  else if ((*(uint *)(param_1 + 0x5c) & 0x300) != 0x300) goto LAB_0090f5af;
  bVar3 = false;
LAB_0090f5af:
  FUN_008f0db9(param_1,&param_1,4);
  if (bVar3) {
    iVar2 = FUN_0090f524(&param_1);
    bVar3 = iVar2 != *(int *)(iVar1 + 0x100);
  }
  else {
    bVar3 = false;
  }
  return bVar3;
}


// ==== FUN_0090f5df @ 0x0090f5df ====

void FUN_0090f5df(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  
  bVar1 = *param_2;
  if (((((((bVar1 < 0x29) || (0x7a < bVar1)) || ((0x5a < bVar1 && (bVar1 < 0x61)))) ||
        ((bVar1 = param_2[1], bVar1 < 0x29 || (0x7a < bVar1)))) ||
       ((0x5a < bVar1 && (bVar1 < 0x61)))) ||
      ((((bVar1 = param_2[2], bVar1 < 0x29 || (0x7a < bVar1)) || ((0x5a < bVar1 && (bVar1 < 0x61))))
       || ((bVar1 = param_2[3], bVar1 < 0x29 || (0x7a < bVar1)))))) ||
     ((0x5a < bVar1 && (bVar1 < 0x61)))) {
    FUN_008ee131(param_1,s_invalid_chunk_type_00a2904c);
  }
  return;
}


// ==== FUN_0090f645 @ 0x0090f645 ====

void FUN_0090f645(int param_1,byte *param_2,uint param_3)

{
  int *piVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  int local_8;
  
  pbVar6 = param_2;
  bVar2 = *(byte *)(param_1 + 0xfb);
  uVar4 = (uint)bVar2;
  if (param_3 == 0xff) {
    uVar4 = uVar4 * *(int *)(param_1 + 0xb8) + 7;
    pbVar6 = (byte *)(*(int *)(param_1 + 0xdc) + 1);
    for (uVar5 = uVar4 >> 5; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)param_2 = *(undefined4 *)pbVar6;
      pbVar6 = pbVar6 + 4;
      param_2 = param_2 + 4;
    }
    for (uVar4 = uVar4 >> 3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *param_2 = *pbVar6;
      pbVar6 = pbVar6 + 1;
      param_2 = param_2 + 1;
    }
  }
  else if (uVar4 == 1) {
    piVar1 = (int *)(param_1 + 0xdc);
    param_1 = *(int *)(param_1 + 0xb8);
    pbVar8 = (byte *)(*piVar1 + 1);
    param_2 = (byte *)0x80;
    iVar7 = 7;
    if (param_1 != 0) {
      do {
        if (((uint)param_2 & param_3) != 0) {
          bVar2 = (byte)iVar7;
          *pbVar6 = (byte)(0x7f7f >> (7 - bVar2 & 0x1f)) & *pbVar6 |
                    (*pbVar8 >> (bVar2 & 0x1f) & 1) << (bVar2 & 0x1f);
        }
        if (iVar7 == 0) {
          pbVar8 = pbVar8 + 1;
          iVar7 = 7;
          pbVar6 = pbVar6 + 1;
        }
        else {
          iVar7 = iVar7 + -1;
        }
        if (param_2 == (byte *)0x1) {
          param_2 = (byte *)0x80;
        }
        else {
          param_2 = (byte *)((int)param_2 >> 1);
        }
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
  }
  else if (uVar4 == 2) {
    piVar1 = (int *)(param_1 + 0xdc);
    param_1 = *(int *)(param_1 + 0xb8);
    pbVar8 = (byte *)(*piVar1 + 1);
    param_2 = (byte *)0x80;
    iVar7 = 6;
    if (param_1 != 0) {
      do {
        if (((uint)param_2 & param_3) != 0) {
          bVar2 = (byte)iVar7;
          *pbVar6 = (byte)(0x3f3f >> (6 - bVar2 & 0x1f)) & *pbVar6 |
                    (*pbVar8 >> (bVar2 & 0x1f) & 3) << (bVar2 & 0x1f);
        }
        if (iVar7 == 0) {
          pbVar8 = pbVar8 + 1;
          iVar7 = 6;
          pbVar6 = pbVar6 + 1;
        }
        else {
          iVar7 = iVar7 + -2;
        }
        if (param_2 == (byte *)0x1) {
          param_2 = (byte *)0x80;
        }
        else {
          param_2 = (byte *)((int)param_2 >> 1);
        }
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
  }
  else if (uVar4 == 4) {
    piVar1 = (int *)(param_1 + 0xdc);
    param_1 = *(int *)(param_1 + 0xb8);
    pbVar8 = (byte *)(*piVar1 + 1);
    param_2 = (byte *)0x80;
    iVar7 = 4;
    if (param_1 != 0) {
      do {
        if (((uint)param_2 & param_3) != 0) {
          bVar2 = (byte)iVar7;
          *pbVar6 = (byte)(0xf0f >> (4 - bVar2 & 0x1f)) & *pbVar6 |
                    (*pbVar8 >> (bVar2 & 0x1f) & 0xf) << (bVar2 & 0x1f);
        }
        if (iVar7 == 0) {
          pbVar8 = pbVar8 + 1;
          iVar7 = 4;
          pbVar6 = pbVar6 + 1;
        }
        else {
          iVar7 = iVar7 + -4;
        }
        if (param_2 == (byte *)0x1) {
          param_2 = (byte *)0x80;
        }
        else {
          param_2 = (byte *)((int)param_2 >> 1);
        }
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
  }
  else {
    local_8 = *(int *)(param_1 + 0xb8);
    uVar4 = (uint)(bVar2 >> 3);
    pbVar6 = (byte *)(*(int *)(param_1 + 0xdc) + 1);
    bVar3 = 0x80;
    if (local_8 != 0) {
      do {
        if ((bVar3 & (byte)param_3) != 0) {
          pbVar8 = pbVar6;
          pbVar9 = param_2;
          for (uVar5 = (uint)(bVar2 >> 5); uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined4 *)pbVar9 = *(undefined4 *)pbVar8;
            pbVar8 = pbVar8 + 4;
            pbVar9 = pbVar9 + 4;
          }
          for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *pbVar9 = *pbVar8;
            pbVar8 = pbVar8 + 1;
            pbVar9 = pbVar9 + 1;
          }
        }
        pbVar6 = pbVar6 + uVar4;
        param_2 = param_2 + uVar4;
        if (bVar3 == 1) {
          bVar3 = 0x80;
        }
        else {
          bVar3 = bVar3 >> 1;
        }
        local_8 = local_8 + -1;
      } while (local_8 != 0);
    }
  }
  return;
}


// ==== FUN_0090f85d @ 0x0090f85d ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0090f85d(uint *param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  byte *pbVar10;
  int local_24;
  uint local_20;
  int local_1c;
  undefined4 *local_14;
  undefined4 local_10 [3];
  
  local_10[2] = DAT_00b49670;
  if ((param_2 != 0) && (param_1 != (uint *)0x0)) {
    local_20 = 0;
    iVar2 = *(int *)(&DAT_00a28ff0 + param_3 * 4);
    uVar3 = *param_1;
    uVar4 = uVar3 * iVar2;
    bVar1 = *(byte *)((int)param_1 + 0xb);
    if (bVar1 == 1) {
      pbVar10 = (byte *)((uVar3 - 1 >> 3) + param_2);
      pbVar9 = (byte *)((uVar4 - 1 >> 3) + param_2);
      local_1c = 7 - (uVar3 - 1 & 7);
      local_14 = (undefined4 *)(7 - (uVar4 - 1 & 7));
      if (uVar3 != 0) {
        do {
          bVar1 = *pbVar10;
          if (0 < iVar2) {
            local_24 = iVar2;
            do {
              *pbVar9 = (byte)(0x7f7f >> (7 - (byte)local_14 & 0x1f)) & *pbVar9 |
                        (bVar1 >> ((byte)local_1c & 0x1f) & 1) << ((byte)local_14 & 0x1f);
              if (local_14 == (undefined4 *)0x7) {
                local_14 = (undefined4 *)0x0;
                pbVar9 = pbVar9 + -1;
              }
              else {
                local_14 = (undefined4 *)((int)local_14 + 1);
              }
              local_24 = local_24 + -1;
            } while (local_24 != 0);
          }
          if (local_1c == 7) {
            local_1c = 0;
            pbVar10 = pbVar10 + -1;
          }
          else {
            local_1c = local_1c + 1;
          }
          local_20 = local_20 + 1;
        } while (local_20 < *param_1);
      }
    }
    else if (bVar1 == 2) {
      pbVar10 = (byte *)((uVar3 - 1 >> 2) + param_2);
      pbVar9 = (byte *)((uVar4 - 1 >> 2) + param_2);
      local_1c = (3 - (uVar3 - 1 & 3)) * 2;
      local_14 = (undefined4 *)((3 - (uVar4 - 1 & 3)) * 2);
      if (uVar3 != 0) {
        do {
          bVar1 = *pbVar10;
          if (0 < iVar2) {
            local_24 = iVar2;
            do {
              *pbVar9 = (byte)(0x3f3f >> (6 - (byte)local_14 & 0x1f)) & *pbVar9 |
                        (bVar1 >> ((byte)local_1c & 0x1f) & 3) << ((byte)local_14 & 0x1f);
              if (local_14 == (undefined4 *)0x6) {
                local_14 = (undefined4 *)0x0;
                pbVar9 = pbVar9 + -1;
              }
              else {
                local_14 = (undefined4 *)((int)local_14 + 2);
              }
              local_24 = local_24 + -1;
            } while (local_24 != 0);
          }
          if (local_1c == 6) {
            local_1c = 0;
            pbVar10 = pbVar10 + -1;
          }
          else {
            local_1c = local_1c + 2;
          }
          local_20 = local_20 + 1;
        } while (local_20 < *param_1);
      }
    }
    else if (bVar1 == 4) {
      pbVar10 = (byte *)((uVar3 - 1 >> 1) + param_2);
      pbVar9 = (byte *)((uVar4 - 1 >> 1) + param_2);
      local_1c = (uVar3 - 1 & 1) * -4 + 4;
      local_14 = (undefined4 *)((uVar4 - 1 & 1) * -4 + 4);
      if (uVar3 != 0) {
        do {
          bVar1 = *pbVar10;
          if (0 < iVar2) {
            local_24 = iVar2;
            do {
              *pbVar9 = (byte)(0xf0f >> (4 - (byte)local_14 & 0x1f)) & *pbVar9 |
                        (bVar1 >> ((byte)local_1c & 0x1f) & 0xf) << ((byte)local_14 & 0x1f);
              if (local_14 == (undefined4 *)0x4) {
                local_14 = (undefined4 *)0x0;
                pbVar9 = pbVar9 + -1;
              }
              else {
                local_14 = (undefined4 *)((int)local_14 + 4);
              }
              local_24 = local_24 + -1;
            } while (local_24 != 0);
          }
          if (local_1c == 4) {
            local_1c = 0;
            pbVar10 = pbVar10 + -1;
          }
          else {
            local_1c = local_1c + 4;
          }
          local_20 = local_20 + 1;
        } while (local_20 < *param_1);
      }
    }
    else {
      uVar6 = (uint)(bVar1 >> 3);
      puVar5 = (undefined4 *)((uVar3 - 1) * uVar6 + param_2);
      local_14 = (undefined4 *)((uVar4 - 1) * uVar6 + param_2);
      if (uVar3 != 0) {
        do {
          puVar7 = puVar5;
          puVar8 = local_10;
          for (uVar3 = (uint)(bVar1 >> 5); uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          for (uVar3 = uVar6 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
            puVar7 = (undefined4 *)((int)puVar7 + 1);
            puVar8 = (undefined4 *)((int)puVar8 + 1);
          }
          if (0 < iVar2) {
            local_24 = iVar2;
            do {
              puVar7 = (undefined4 *)((int)local_14 - uVar6);
              puVar8 = local_10;
              for (uVar3 = (uint)(bVar1 >> 5); uVar3 != 0; uVar3 = uVar3 - 1) {
                *local_14 = *puVar8;
                puVar8 = puVar8 + 1;
                local_14 = local_14 + 1;
              }
              local_24 = local_24 + -1;
              for (uVar3 = uVar6 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
                *(undefined1 *)local_14 = *(undefined1 *)puVar8;
                puVar8 = (undefined4 *)((int)puVar8 + 1);
                local_14 = (undefined4 *)((int)local_14 + 1);
              }
              local_14 = puVar7;
            } while (local_24 != 0);
          }
          puVar5 = (undefined4 *)((int)puVar5 - uVar6);
          local_20 = local_20 + 1;
        } while (local_20 < *param_1);
      }
    }
    *param_1 = uVar4;
    param_1[1] = *(byte *)((int)param_1 + 0xb) * uVar4 + 7 >> 3;
  }
  return;
}


// ==== FUN_0090fb34 @ 0x0090fb34 ====

void FUN_0090fb34(int param_1,int param_2,byte *param_3,byte *param_4,byte *param_5)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  
  if (param_5 != (byte *)0x0) {
    if (param_5 == (byte *)0x1) {
      uVar4 = (int)(*(byte *)(param_2 + 0xb) + 7) >> 3;
      param_3 = param_3 + uVar4;
      if (uVar4 < *(uint *)(param_2 + 4)) {
        pbVar9 = param_3 + -uVar4;
        iVar3 = *(uint *)(param_2 + 4) - uVar4;
        do {
          *param_3 = *param_3 + *pbVar9;
          param_3 = param_3 + 1;
          pbVar9 = pbVar9 + 1;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
    else if (param_5 == (byte *)0x2) {
      uVar4 = *(uint *)(param_2 + 4);
      uVar6 = 0;
      if (uVar4 != 0) {
        do {
          *param_3 = *param_3 + param_4[uVar6];
          param_3 = param_3 + 1;
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar4);
      }
    }
    else if (param_5 == (byte *)0x3) {
      iVar3 = (int)(*(byte *)(param_2 + 0xb) + 7) >> 3;
      iVar7 = *(int *)(param_2 + 4) - iVar3;
      pbVar9 = param_3;
      for (; iVar3 != 0; iVar3 = iVar3 + -1) {
        *pbVar9 = *pbVar9 + (*param_4 >> 1);
        param_4 = param_4 + 1;
        pbVar9 = pbVar9 + 1;
      }
      for (; iVar7 != 0; iVar7 = iVar7 + -1) {
        *pbVar9 = *pbVar9 + (char)(((uint)*param_3 + (uint)*param_4) / 2);
        param_3 = param_3 + 1;
        param_4 = param_4 + 1;
        pbVar9 = pbVar9 + 1;
      }
    }
    else if (param_5 == (byte *)0x4) {
      iVar3 = (int)(*(byte *)(param_2 + 0xb) + 7) >> 3;
      param_1 = *(int *)(param_2 + 4) - iVar3;
      param_5 = param_3;
      pbVar9 = param_4;
      if (iVar3 != 0) {
        do {
          *param_5 = *param_5 + *pbVar9;
          pbVar9 = pbVar9 + 1;
          param_5 = param_5 + 1;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      if (param_1 != 0) {
        do {
          bVar5 = *param_3;
          bVar1 = *pbVar9;
          bVar2 = *param_4;
          param_3 = param_3 + 1;
          pbVar9 = pbVar9 + 1;
          param_4 = param_4 + 1;
          iVar3 = (uint)bVar1 - (uint)bVar2;
          iVar7 = (uint)bVar5 - (uint)bVar2;
          if (iVar3 < 0) {
            param_2 = -iVar3;
          }
          else {
            param_2 = iVar3;
          }
          iVar8 = iVar7;
          if (iVar7 < 0) {
            iVar8 = -iVar7;
          }
          iVar3 = iVar3 + iVar7;
          if (iVar3 < 0) {
            iVar3 = -iVar3;
          }
          if (((iVar8 < param_2) || (iVar3 < param_2)) && (bVar5 = bVar1, iVar3 < iVar8)) {
            bVar5 = bVar2;
          }
          *param_5 = *param_5 + bVar5;
          param_5 = param_5 + 1;
          param_1 = param_1 + -1;
        } while (param_1 != 0);
      }
    }
    else {
      FUN_008ee116(param_1,s_Ignoring_bad_adaptive_filter_typ_00a29060);
      *param_3 = 0;
    }
  }
  return;
}


// ==== FUN_0090fcad @ 0x0090fcad ====

void FUN_0090fcad(int param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  *(undefined4 *)(param_1 + 0x68) = 0;
  FUN_008f0b02(param_1);
  uVar3 = *(uint *)(param_1 + 0xbc);
  if (*(char *)(param_1 + 0x113) == '\0') {
    iVar6 = *(int *)(param_1 + 0xb8);
    *(uint *)(param_1 + 0xc0) = uVar3;
    *(int *)(param_1 + 0xd0) = iVar6;
    *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 200) + 1;
  }
  else {
    if ((*(byte *)(param_1 + 0x60) & 2) == 0) {
      uVar3 = uVar3 + 7 >> 3;
    }
    iVar6 = *(int *)(param_1 + 0xb8);
    *(uint *)(param_1 + 0xc0) = uVar3;
    iVar4 = (uint)*(byte *)(param_1 + 0x114) * 4;
    uVar3 = ((iVar6 - *(int *)(&DAT_00a28fd4 + iVar4)) + -1 + *(uint *)(&DAT_00a28ff0 + iVar4)) /
            *(uint *)(&DAT_00a28ff0 + iVar4);
    *(uint *)(param_1 + 0xd0) = uVar3;
    *(uint *)(param_1 + 0xcc) = (*(byte *)(param_1 + 0x119) * uVar3 + 7 >> 3) + 1;
  }
  uVar3 = (uint)*(byte *)(param_1 + 0x119);
  uVar2 = *(uint *)(param_1 + 0x60);
  if (((uVar2 & 4) != 0) && (*(byte *)(param_1 + 0x117) < 8)) {
    uVar3 = 8;
  }
  if ((uVar2 & 0x1000) != 0) {
    cVar1 = *(char *)(param_1 + 0x116);
    if (cVar1 == '\x03') {
      uVar3 = (uint)(*(short *)(param_1 + 0x10a) != 0) * 8 + 0x18;
    }
    else if (cVar1 == '\0') {
      if (uVar3 < 8) {
        uVar3 = 8;
      }
      if (*(short *)(param_1 + 0x10a) != 0) {
        uVar3 = uVar3 * 2;
      }
    }
    else if ((cVar1 == '\x02') && (*(short *)(param_1 + 0x10a) != 0)) {
      uVar3 = (uVar3 << 2) / 3;
    }
  }
  if ((char)(uVar2 >> 8) < '\0') {
    cVar1 = *(char *)(param_1 + 0x116);
    if (cVar1 == '\x03') {
      uVar3 = 0x20;
    }
    else if (cVar1 == '\0') {
      uVar3 = ((8 < uVar3) - 1 & 0xfffffff0) + 0x20;
    }
    else if (cVar1 == '\x02') {
      uVar3 = ((0x20 < uVar3) - 1 & 0xffffffe0) + 0x40;
    }
  }
  uVar5 = FUN_0090c9a9(param_1,((iVar6 + 7U & 0xfffffff8) * uVar3 + 7 >> 3) + 1 +
                               ((int)(uVar3 + 7) >> 3));
  *(undefined4 *)(param_1 + 0xdc) = uVar5;
  uVar5 = FUN_0090c9a9(param_1,*(int *)(param_1 + 200) + 1);
  *(undefined4 *)(param_1 + 0xd8) = uVar5;
  FUN_0090ca28(param_1,uVar5,0,*(int *)(param_1 + 200) + 1);
  *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) | 0x40;
  return;
}


// ==== FUN_0090fe4c @ 0x0090fe4c ====

undefined4 FUN_0090fe4c(int param_1,uint param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = *(uint *)(param_1 + 0xa0);
  for (; uVar1 < param_2; param_2 = param_2 - uVar1) {
    FUN_0090f568(param_1,*(undefined4 *)(param_1 + 0x9c),*(undefined4 *)(param_1 + 0xa0));
  }
  if (param_2 != 0) {
    FUN_0090f568(param_1,*(undefined4 *)(param_1 + 0x9c),param_2);
  }
  iVar3 = FUN_0090f581(param_1);
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    bVar2 = *(byte *)(param_1 + 0x10c) & 0x20;
    if (((bVar2 == 0) || ((*(byte *)(param_1 + 0x5d) & 2) != 0)) &&
       ((bVar2 != 0 || ((*(byte *)(param_1 + 0x5d) & 4) == 0)))) {
      FUN_008ee131(param_1,s_CRC_error_00a29084);
    }
    else {
      FUN_008ee15d(param_1,s_CRC_error_00a29084);
    }
    uVar4 = 1;
  }
  return uVar4;
}


// ==== FUN_0090fed5 @ 0x0090fed5 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0090fed5(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  byte local_10;
  byte local_f;
  char local_e;
  char local_d;
  byte local_c;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  if (*(int *)(param_1 + 0x58) != 0) {
    FUN_008ee0f5(param_1,s_Out_of_place_IHDR_00a29194);
  }
  if (param_3 != 0xd) {
    FUN_008ee0f5(param_1,s_Invalid_IHDR_chunk_00a29180);
  }
  *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 1;
  FUN_0090f568(param_1,local_18,0xd);
  FUN_0090fe4c(param_1,0);
  uVar2 = FUN_0090f524(local_18);
  uVar3 = FUN_0090f524(local_14);
  if ((((uVar2 == 0) || (0x7fffffff < uVar2)) || (uVar3 == 0)) || (0x7fffffff < uVar3)) {
    FUN_008ee0f5(param_1,s_Invalid_image_size_in_IHDR_00a29164);
  }
  if (((local_10 != 1) && (local_10 != 2)) &&
     ((local_10 != 4 && ((local_10 != 8 && (local_10 != 0x10)))))) {
    FUN_008ee0f5(param_1,s_Invalid_bit_depth_in_IHDR_00a29148);
  }
  if (((local_f == 1) || (local_f == 5)) || (6 < local_f)) {
    FUN_008ee0f5(param_1,s_Invalid_color_type_in_IHDR_00a2912c);
  }
  if (((local_f == 3) && (8 < local_10)) ||
     (((local_f == 2 || ((local_f == 4 || (local_f == 6)))) && (local_10 < 8)))) {
    FUN_008ee0f5(param_1,s_Invalid_color_type_bit_depth_com_00a290f8);
  }
  if (1 < local_c) {
    FUN_008ee0f5(param_1,s_Unknown_interlace_method_in_IHDR_00a290d4);
  }
  if (local_e != '\0') {
    FUN_008ee0f5(param_1,s_Unknown_compression_method_in_IH_00a290b0);
  }
  if (local_d != '\0') {
    FUN_008ee0f5(param_1,s_Unknown_filter_method_in_IHDR_00a29090);
  }
  *(byte *)(param_1 + 0x113) = local_c;
  *(uint *)(param_1 + 0xb8) = uVar2;
  *(uint *)(param_1 + 0xbc) = uVar3;
  *(byte *)(param_1 + 0x117) = local_10;
  *(byte *)(param_1 + 0x116) = local_f;
  if (local_f != 0) {
    if (local_f == 2) {
      *(undefined1 *)(param_1 + 0x11a) = 3;
      goto LAB_00910088;
    }
    if (local_f != 3) {
      if (local_f == 4) {
        *(undefined1 *)(param_1 + 0x11a) = 2;
      }
      else if (local_f == 6) {
        *(undefined1 *)(param_1 + 0x11a) = 4;
      }
      goto LAB_00910088;
    }
  }
  *(undefined1 *)(param_1 + 0x11a) = 1;
LAB_00910088:
  bVar1 = *(char *)(param_1 + 0x11a) * local_10;
  *(byte *)(param_1 + 0x119) = bVar1;
  *(uint *)(param_1 + 200) = bVar1 * uVar2 + 7 >> 3;
  FUN_008eeaae(param_1,param_2,uVar2,uVar3,local_10,local_f,local_c,local_e,local_d);
  return;
}


