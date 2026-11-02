// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x660000-0x66ffff

// ==== FUN_00660170 @ 0x00660170 ====

void FUN_00660170(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_3d0 [3];
  char cStack_3cd;
  undefined1 uStack_3c4;
  undefined4 uStack_3b4;
  undefined4 uStack_3b0;
  undefined1 uStack_3a8;
  undefined4 uStack_398;
  undefined4 uStack_394;
  void *pvStack_38c;
  undefined4 uStack_37c;
  uint uStack_378;
  undefined4 uStack_370;
  undefined4 uStack_36c;
  undefined4 uStack_368;
  undefined1 auStack_2d8 [48];
  undefined1 auStack_2a8 [56];
  undefined1 auStack_270 [120];
  undefined1 auStack_1f8 [76];
  undefined1 auStack_1ac [288];
  undefined1 auStack_8c [76];
  undefined1 auStack_40 [64];
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
  if (piVar1 == (int *)0x0) {
    return;
  }
  if (param_1 == 0) {
    return;
  }
  uStack_3b0 = 0xf;
  uStack_3b4 = 0;
  uStack_3c4 = 0;
  uStack_394 = 0xf;
  uStack_398 = 0;
  uStack_3a8 = 0;
  uStack_378 = 0xf;
  uStack_37c = 0;
  pvStack_38c = (void *)((uint)pvStack_38c & 0xffffff00);
  uStack_370 = 0;
  uStack_36c = 0;
  uStack_368 = 0;
  switch(*(undefined4 *)(param_1 + 4)) {
  case 0:
    cStack_3cd = (**(code **)(*DAT_00b5ad1c + 0x58))();
    if (cStack_3cd == '\0') {
      FUN_00401830(&DAT_009d663b);
      (**(code **)*piVar1)(9,auStack_2d8);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    FUN_00403810(s_<CUR_NUM>_009d661c);
    FUN_00401830(&DAT_009d6628);
    uVar2 = FUN_00404230(auStack_1f8);
    FUN_00401660(uVar2,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 1:
    uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x6e0106);
    FUN_00765c50(uVar2);
    FUN_00403810(s_<NAME>_009d663c);
    FUN_00401660(&uStack_36c,0,0xffffffff);
    FUN_004e6c20(auStack_3d0);
    FUN_00403810(s_<VALUE>_009d6644);
    (**(code **)(*DAT_00b5ad1c + 0x3c))();
    FUN_00401830(&DAT_009d664c);
    uVar2 = FUN_00404230(auStack_270);
    FUN_00401660(uVar2,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 2:
    uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x6e0108);
    FUN_00765c50(uVar2);
    FUN_00403810(s_<NAME>_009d66a4);
    FUN_00401660(&uStack_36c,0,0xffffffff);
    FUN_004e6c20(auStack_3d0);
    FUN_00403810(s_<VALUE>_009d66ac);
    (**(code **)(*DAT_00b5ad1c + 0x40))();
    FUN_00401830(&DAT_009d66b4);
    uVar2 = FUN_00404230(auStack_2a8);
    FUN_00401660(uVar2,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 3:
    uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x6e0107);
    FUN_00765c50(uVar2);
    FUN_00403810(s_<NAME>_009d6670);
    FUN_00401660(&uStack_36c,0,0xffffffff);
    FUN_004e6c20(auStack_3d0);
    FUN_00403810(s_<VALUE>_009d6678);
    (**(code **)(*DAT_00b5ad1c + 0x38))();
    FUN_00401830(&DAT_009d6680);
    uVar2 = FUN_00404230(auStack_40);
    FUN_00401660(uVar2,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 4:
    uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x6e0109);
    FUN_00765c50(uVar2);
    FUN_00403810(s_<NAME>_009d66d8);
    FUN_00401660(&uStack_36c,0,0xffffffff);
    FUN_004e6c20(auStack_3d0);
    FUN_00403810(s_<VALUE>_009d66e0);
    (**(code **)(*DAT_00b5ad1c + 0x44))();
    FUN_00401830(&DAT_009d66e8);
    uVar2 = FUN_00404230(auStack_1ac);
    FUN_00401660(uVar2,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  default:
    goto switchD_006601f8_caseD_5;
  case 7:
    (**(code **)(*DAT_00b5ad1c + 0x7c))();
    FUN_00403810(s_<VALUE>_009d670c);
    FUN_00401830(&DAT_009d6714);
    uVar2 = FUN_00404230(auStack_8c);
    FUN_00401660(uVar2,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 8:
    uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x6e0100);
    FUN_00401660(uVar2,0,0xffffffff);
    (**(code **)*piVar1)(0x10,&uStack_398);
    iVar3 = *piVar1;
    uVar2 = FUN_006ec5b0();
    break;
  case 9:
    uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x6e00fa);
    FUN_00401660(uVar2,0,0xffffffff);
    (**(code **)*piVar1)(0x11,&uStack_398);
    iVar3 = *piVar1;
    uVar2 = FUN_006ec6d0();
    break;
  case 10:
    uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x6e00fb);
    FUN_00401660(uVar2,0,0xffffffff);
    (**(code **)*piVar1)(0x12,&uStack_398);
    iVar3 = *piVar1;
    uVar2 = FUN_006ec640();
  }
  (**(code **)(iVar3 + 4))(uVar2);
  FUN_0065f510();
switchD_006601f8_caseD_5:
  FUN_00406250();
  if (uStack_378 < 0x10) {
    uStack_378 = 0xf;
    uStack_37c = 0;
    pvStack_38c = (void *)((uint)pvStack_38c & 0xffffff00);
    FUN_0040a7d0();
    FUN_004e67a0();
    return;
  }
  _free(pvStack_38c);
  return;
}


// ==== FUN_00660fa0 @ 0x00660fa0 ====

uint FUN_00660fa0(int *param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint extraout_EAX;
  undefined4 uVar8;
  int in_ECX;
  undefined2 extraout_var;
  undefined1 auStack_264 [20];
  undefined4 uStack_250;
  undefined1 *puStack_24c;
  undefined1 auStack_248 [8];
  undefined4 uStack_240;
  int *piStack_23c;
  undefined4 uStack_238;
  undefined4 uStack_234;
  undefined1 *puStack_230;
  int *piStack_22c;
  int iStack_228;
  undefined1 *puStack_224;
  int *piStack_220;
  int *piStack_21c;
  int *piStack_218;
  void *pvStack_1fc;
  uint uStack_1e8;
  undefined1 auStack_1cc [120];
  int aiStack_154 [8];
  undefined1 auStack_134 [304];
  
  uVar4 = (**(code **)(*param_1 + 4))();
  if (0x70320030 < uVar4) {
    if (uVar4 < 0x70450012) {
      if (uVar4 == 0x70450011) {
        (**(code **)(*DAT_00b5a74c + 0xc))();
        (**(code **)(*DAT_00b5a750 + 0xc))();
        return 1;
      }
      if (uVar4 < 0x70380004) {
        if (uVar4 == 0x70380003) {
          FUN_0065e0a0();
          return 1;
        }
        if (uVar4 < 0x70340007) {
          if (uVar4 == 0x70340006) {
            iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
            if (iVar5 != 0) {
              puVar6 = (undefined4 *)FUN_0065deb0();
              *(undefined4 *)(in_ECX + 0x264) = *puVar6;
              *(undefined4 *)(in_ECX + 0x268) = puVar6[1];
            }
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
          if (uVar4 < 0x70320057) {
            if (uVar4 == 0x70320056) {
              (**(code **)(*DAT_00b5a750 + 0xc))();
              return 1;
            }
            switch(uVar4) {
            case 0x70320040:
              piVar7 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
              if (piVar7 != (int *)0x0) {
                (**(code **)(*DAT_00b5a794 + 0xc))();
                piStack_218 = (int *)0x66252b;
                FUN_00765c50();
                piStack_218 = (int *)0x2;
                piStack_21c = (int *)0x66253b;
                (**(code **)*piVar7)();
                iVar5 = *piVar7;
                piStack_21c = (int *)0x662542;
                piStack_21c = (int *)FUN_006ecc70();
                piStack_220 = (int *)0x662548;
                (**(code **)(iVar5 + 4))();
                piStack_220 = (int *)0x66254f;
                FUN_0065f510();
                    /* WARNING: Subroutine does not return */
                piStack_220 = (int *)0x66255b;
                FUN_00446f10();
              }
              return 1;
            case 0x70320050:
              iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
              if (iVar5 == 0) {
                return 1;
              }
              piStack_218 = (int *)0x662598;
              FUN_0050a850();
              piStack_218 = (int *)0x6625a7;
              FUN_0066f680();
              return 1;
            case 0x70320051:
              (**(code **)(*DAT_00b5a750 + 0xc))();
              return 1;
            case 0x70320053:
              iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
              if (iVar5 == 0) {
                return 1;
              }
              piStack_218 = (int *)0x662629;
              FUN_0050a850();
              return 1;
            case 0x70320054:
              (**(code **)(*DAT_00b5a750 + 0xc))();
              return 1;
            case 0x70320055:
              iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
              if (iVar5 == 0) {
                return 1;
              }
              piStack_218 = (int *)0x6625ee;
              FUN_0066f380();
              return 1;
            }
          }
          else if (uVar4 < 0x70340001) {
            if (uVar4 == 0x70340000) {
              (**(code **)(*DAT_00b5a750 + 8))();
              return 1;
            }
            if (uVar4 == 0x70330000) {
              iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
              if (iVar5 == 0) {
                return 1;
              }
              piStack_218 = (int *)0x6626f5;
              FUN_0050a850();
              return 1;
            }
            if (uVar4 == 0x70330001) {
              iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
              if (iVar5 != 0) {
                puVar6 = (undefined4 *)FUN_0065deb0();
                *(undefined4 *)(in_ECX + 0x15c) = *puVar6;
                *(undefined4 *)(in_ECX + 0x160) = puVar6[1];
              }
              (**(code **)(*DAT_00b5a750 + 0xc))();
              return 1;
            }
          }
          else {
            if (uVar4 == 0x70340001) {
              (**(code **)(*DAT_00b5a74c + 0xc))();
              return 1;
            }
            if (uVar4 == 0x70340005) {
              iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
              if (iVar5 == 0) {
                return 1;
              }
              piStack_218 = (int *)0x662752;
              FUN_0050a850();
              return 1;
            }
          }
        }
        else if (uVar4 < 0x70360003) {
          if (uVar4 == 0x70360002) {
            iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
            if (iVar5 == 0) {
              return 1;
            }
            piStack_218 = (int *)0x662934;
            FUN_0050a850();
            return 1;
          }
          if (uVar4 < 0x70340013) {
            if (uVar4 == 0x70340012) {
              piVar7 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
              if (piVar7 != (int *)0x0) {
                (**(code **)*piVar7)();
                iVar5 = *piVar7;
                piStack_218 = (int *)0x662863;
                FUN_006ecb80();
                piStack_218 = (int *)0x662870;
                (**(code **)(iVar5 + 4))();
                FUN_0065f510();
              }
            }
            else {
              if (uVar4 == 0x70340007) {
                iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
                if (iVar5 == 0) {
                  return 1;
                }
                piStack_218 = (int *)0x66282b;
                FUN_0050a850();
                return 1;
              }
              if (uVar4 == 0x70340008) {
                (**(code **)(*DAT_00b5a750 + 0xc))();
                return 1;
              }
            }
          }
          else {
            if (uVar4 == 0x70360000) {
              iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
              if (iVar5 == 0) {
                return 1;
              }
              piStack_218 = (int *)0x6628ff;
              FUN_0050a850();
              return 1;
            }
            if (uVar4 == 0x70360001) {
              iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
              if (iVar5 != 0) {
                puVar6 = (undefined4 *)FUN_0065deb0();
                *(undefined4 *)(in_ECX + 0x294) = *puVar6;
                *(undefined4 *)(in_ECX + 0x298) = puVar6[1];
              }
              (**(code **)(*DAT_00b5a750 + 0xc))();
              return 1;
            }
          }
        }
        else if (uVar4 < 0x70370002) {
          if (uVar4 == 0x70370001) {
            iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
            if (iVar5 != 0) {
              puVar6 = (undefined4 *)FUN_0065deb0();
              *(undefined4 *)(in_ECX + 0x1e4) = *puVar6;
              *(undefined4 *)(in_ECX + 0x1e8) = puVar6[1];
            }
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
          if (uVar4 == 0x70360003) {
            iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
            if (iVar5 != 0) {
              puVar6 = (undefined4 *)FUN_0065deb0();
              *(undefined4 *)(in_ECX + 0x29c) = *puVar6;
              *(undefined4 *)(in_ECX + 0x2a0) = puVar6[1];
            }
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
          if (uVar4 == 0x70370000) {
            iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
            if (iVar5 == 0) {
              return 1;
            }
            piStack_218 = (int *)0x66298c;
            FUN_0050a850();
            return 1;
          }
        }
        else {
          if (uVar4 == 0x70380000) {
            FUN_0065e0a0();
            return 1;
          }
          if (uVar4 == 0x70380001) {
            FUN_0065ed90();
            return 1;
          }
        }
      }
      else if (uVar4 < 0x70420002) {
        if (uVar4 == 0x70420001) {
          puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
          if (puVar6 != (undefined4 *)0x0) {
            if (param_1[1] == 0) {
              FUN_00401830();
              (**(code **)*puVar6)();
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            if (param_1[1] == 1) {
              FUN_00401830();
              (**(code **)*puVar6)();
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
          }
        }
        else if (uVar4 < 0x70390008) {
          if (uVar4 == 0x70390007) {
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
          if (uVar4 < 0x70390001) {
            if (uVar4 == 0x70390000) {
              (**(code **)(*DAT_00b5a750 + 8))();
              return 1;
            }
            if (uVar4 == 0x70380004) {
              FUN_0065ed90();
              iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
              if (iVar5 == 0) {
                return 1;
              }
              FUN_0066e030();
              return 1;
            }
            if (uVar4 == 0x70380011) {
              puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
              if (puVar6 != (undefined4 *)0x0) {
                FUN_00401830();
                (**(code **)*puVar6)();
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
            }
            else if ((uVar4 == 0x70380020) &&
                    (piVar7 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))(), piVar7 != (int *)0x0)) {
              (**(code **)*piVar7)();
              iVar5 = *piVar7;
              FUN_006eca30();
              piStack_218 = (int *)0x662af0;
              (**(code **)(iVar5 + 4))();
              FUN_0065f510();
            }
          }
          else {
            if (uVar4 == 0x70390001) {
              (**(code **)(*DAT_00b5a750 + 0xc))();
              return 1;
            }
            if (uVar4 == 0x70390006) {
              iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
              if (iVar5 == 0) {
                (**(code **)(*DAT_00b5a74c + 0xc))();
              }
              FUN_0066d180();
              FUN_0066cf00();
              return 1;
            }
          }
        }
        else if (uVar4 < 0x70400001) {
          if (uVar4 == 0x70400000) {
            iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
            if (iVar5 == 0) {
              return 1;
            }
            piStack_218 = (int *)0x662cd3;
            FUN_0050a850();
            return 1;
          }
          if (uVar4 == 0x70390008) {
            iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
            if (iVar5 == 0) {
              (**(code **)(*DAT_00b5a74c + 0xc))();
            }
            FUN_0066a630();
            FUN_0066ce00();
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          if (uVar4 == 0x70390009) {
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
        }
        else {
          if (uVar4 == 0x70400001) {
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
          if (uVar4 == 0x70420000) {
            FUN_00660170();
          }
        }
      }
      else if (uVar4 < 0x70440004) {
        if (uVar4 == 0x70440003) {
          (**(code **)(*DAT_00b5a74c + 0xc))();
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        }
        if (uVar4 < 0x70440001) {
          if (uVar4 == 0x70440000) {
            (**(code **)(*DAT_00b5a750 + 8))();
            piStack_218 = (int *)0x662e29;
            FUN_0050a850();
            return 1;
          }
          if (uVar4 == 0x70420005) {
            (**(code **)(*DAT_00b5a750 + 8))();
            return 1;
          }
          if (uVar4 == 0x70420006) {
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
        }
        else {
          if (uVar4 == 0x70440001) {
            (**(code **)(*DAT_00b5a74c + 0xc))();
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
          if (uVar4 == 0x70440002) {
            (**(code **)(*DAT_00b5a750 + 8))();
            piStack_218 = (int *)0x662e66;
            FUN_0050a850();
            return 1;
          }
        }
      }
      else {
        switch(uVar4) {
        case 0x70450000:
          (**(code **)(*DAT_00b5a750 + 8))();
          return 1;
        case 0x70450001:
          (**(code **)(*DAT_00b5a74c + 0xc))();
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        case 0x70450005:
          (**(code **)(*DAT_00b5a750 + 8))();
          return 1;
        case 0x70450006:
          (**(code **)(*DAT_00b5a74c + 0xc))();
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        case 0x70450010:
          iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
          if (iVar5 == 0) {
            return 1;
          }
          piStack_218 = (int *)0x662f7b;
          FUN_0050a850();
          return 1;
        }
      }
    }
    else if (uVar4 < 0x70500001) {
      if (uVar4 == 0x70500000) {
        (**(code **)(*DAT_00b5a750 + 8))();
        return 1;
      }
      if (uVar4 < 0x70480004) {
        if (uVar4 == 0x70480003) {
          (**(code **)(*DAT_00b5a750 + 8))();
          puStack_230 = (undefined1 *)&piStack_22c;
          uStack_234 = 0x663265;
          FUN_00663b40();
          puStack_24c = auStack_248;
          uStack_250 = 0x663270;
          FUN_00663b10();
          FUN_005523a0(auStack_264);
          FUN_0066ab00();
          return 1;
        }
        if (uVar4 < 0x70460001) {
          if (uVar4 == 0x70460000) {
            iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
            if (iVar5 == 0) {
              (**(code **)(*DAT_00b5a750 + 8))();
              piStack_218 = (int *)0x663149;
              FUN_0066bcf0();
              return 1;
            }
            return 1;
          }
          switch(uVar4) {
          case 0x70450014:
            iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
            if (iVar5 == 0) {
              return 1;
            }
            piVar7 = (int *)param_1[2];
            iVar5 = param_1[1];
            piStack_22c = &iStack_228;
            puStack_230 = (undefined1 *)0x663023;
            FUN_00663ae0();
            uStack_234 = 0x66302c;
            puStack_230 = (undefined1 *)iVar5;
            piStack_22c = piVar7;
            FUN_0066c8c0();
            return 1;
          case 0x70450015:
            (**(code **)(*DAT_00b5a74c + 0xc))();
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          case 0x70450019:
            iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
            if (iVar5 == 0) {
              return 1;
            }
            FUN_0066c5c0();
            return 1;
          case 0x70450020:
            (**(code **)(*DAT_00b5a74c + 0xc))();
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          case 0x70450024:
            iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
            if (iVar5 == 0) {
              return 1;
            }
            piStack_218 = (int *)0x6630d8;
            FUN_0050a850();
            piStack_218 = (int *)param_1[3];
            piStack_21c = (int *)0x6630ec;
            FUN_0066c0f0();
            return 1;
          case 0x70450025:
            (**(code **)(*DAT_00b5a74c + 0xc))();
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
        }
        else if (uVar4 < 0x70470002) {
          if (uVar4 == 0x70470001) {
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
          if (uVar4 == 0x70460001) {
            (**(code **)(*DAT_00b5a74c + 0xc))();
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
          if (uVar4 == 0x70470000) {
            iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
            if (iVar5 == 0) {
              return 1;
            }
            piStack_218 = (int *)0x663197;
            FUN_0066b940();
            return 1;
          }
        }
        else {
          if (uVar4 == 0x70480001) {
            iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
            if (iVar5 != 0) {
              piStack_218 = (int *)0x66322f;
              FUN_0050a850();
            }
            FUN_0066b380();
            return 1;
          }
          if (uVar4 == 0x70480002) {
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
        }
      }
      else if (uVar4 < 0x70490006) {
        if (uVar4 == 0x70490005) {
          (**(code **)(*DAT_00b5a750 + 8))();
          return 1;
        }
        if (uVar4 < 0x70490002) {
          if (uVar4 == 0x70490001) {
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
          if (uVar4 == 0x70480004) {
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
          if (uVar4 == 0x70490000) {
            (**(code **)(*DAT_00b5a750 + 8))();
            return 1;
          }
        }
        else {
          if (uVar4 == 0x70490003) {
            (**(code **)(*DAT_00b5a750 + 8))();
            return 1;
          }
          if (uVar4 == 0x70490004) {
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
        }
      }
      else {
        switch(uVar4) {
        case 0x70490006:
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        case 0x70490008:
          (**(code **)(*DAT_00b5a750 + 8))();
          return 1;
        case 0x70490009:
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        case 0x70490010:
          (**(code **)(*DAT_00b5a750 + 8))();
          return 1;
        case 0x70490011:
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        }
      }
    }
    else if (uVar4 < 0x70910014) {
      if (uVar4 == 0x70910013) {
        (**(code **)(*DAT_00b5a750 + 8))();
        return 1;
      }
      if (uVar4 < 0x70800001) {
        if (uVar4 == 0x70800000) {
          FUN_0065e0a0();
          return 1;
        }
        if (uVar4 < 0x70510002) {
          if (uVar4 == 0x70510001) {
            FUN_0065ed90();
            return 1;
          }
          if (uVar4 == 0x70500001) {
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
          if (uVar4 == 0x70510000) {
            FUN_0065e0a0();
            return 1;
          }
        }
        else {
          if (uVar4 == 0x70750001) {
            iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
            if (iVar5 == 0) {
              return 1;
            }
            iVar5 = param_1[8];
            iVar1 = param_1[1];
            iVar2 = param_1[2];
            piStack_218 = (int *)0x6634e8;
            FUN_006640f0();
            puStack_224 = (undefined1 *)0x6634f5;
            piStack_220 = (int *)iVar1;
            piStack_21c = (int *)iVar2;
            piStack_218 = (int *)iVar5;
            FUN_0066a6d0();
            FUN_00406250();
            return 1;
          }
          if (uVar4 == 0x70750002) {
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
        }
      }
      else if (uVar4 < 0x70900002) {
        if (uVar4 == 0x70900001) {
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        }
        if (uVar4 == 0x70800001) {
          FUN_0065ed90();
          return 1;
        }
        if (uVar4 == 0x70900000) {
          (**(code **)(*DAT_00b5a750 + 8))();
          return 1;
        }
      }
      else {
        if (uVar4 == 0x70910003) {
          (**(code **)(*DAT_00b5a750 + 8))();
          return 1;
        }
        if (uVar4 == 0x70910004) {
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        }
      }
    }
    else if (uVar4 < 0x70910024) {
      if (uVar4 == 0x70910023) {
        (**(code **)(*DAT_00b5a750 + 8))();
        return 1;
      }
      switch(uVar4) {
      case 0x70910014:
        (**(code **)(*DAT_00b5a750 + 0xc))();
        return 1;
      case 0x70910015:
        (**(code **)(*DAT_00b5a750 + 8))();
        return 1;
      case 0x70910016:
        (**(code **)(*DAT_00b5a750 + 0xc))();
        return 1;
      case 0x70910020:
        (**(code **)(*DAT_00b5a750 + 8))();
        return 1;
      case 0x70910021:
        (**(code **)(*DAT_00b5a750 + 0xc))();
        return 1;
      }
    }
    else if (uVar4 < 0x70920002) {
      if (uVar4 == 0x70920001) {
        (**(code **)(*DAT_00b5a750 + 0xc))();
        return 1;
      }
      if (uVar4 == 0x70910024) {
        (**(code **)(*DAT_00b5a750 + 0xc))();
        return 1;
      }
      if (uVar4 == 0x70920000) {
        (**(code **)(*DAT_00b5a750 + 8))();
        return 1;
      }
    }
    else {
      if (uVar4 == 0x70940000) {
        FUN_0065def0();
        return 1;
      }
      if (uVar4 == 0x70940001) {
        (**(code **)(*DAT_00b5a750 + 0xc))();
        return 1;
      }
    }
    goto switchD_00662087_caseD_70320002;
  }
  if (uVar4 == 0x70320030) {
    piVar7 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
    if (piVar7 == (int *)0x0) {
      return 1;
    }
    FUN_00401830();
    (**(code **)*piVar7)();
    if (0xf < uStack_1e8) {
      piStack_218 = (int *)0x66243d;
      _free(pvStack_1fc);
      return extraout_EAX;
    }
    uStack_234 = 0xffffffff;
    piStack_21c = (int *)0x0;
    piStack_218 = (int *)0xf;
    uStack_238 = 0;
    piStack_22c = (int *)((uint)piStack_22c & 0xffffff00);
    piStack_23c = param_1 + 2;
    uStack_240 = 0x662471;
    uVar8 = FUN_00401660();
    uStack_234 = CONCAT31((int3)((uint)uVar8 >> 8),(char)param_1[1]);
    uStack_238 = 0x66247a;
    FUN_006ecdc0();
    piStack_218 = (int *)0x662485;
    (**(code **)(*piVar7 + 4))();
LAB_00662485:
    FUN_0065f510();
    return 1;
  }
  if (uVar4 < 0x70160001) {
    if (uVar4 == 0x70160000) {
      iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
      if (iVar5 == 0) {
        return 1;
      }
      piStack_218 = (int *)0x661a34;
      FUN_0050a850();
      return 1;
    }
    if (uVar4 < 0x70070001) {
      if (uVar4 == 0x70070000) {
        (**(code **)(*DAT_00b5a750 + 8))();
        return 1;
      }
      if (uVar4 < 0x70020001) {
        if (uVar4 == 0x70020000) {
          iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
          if (iVar5 == 0) {
            return 1;
          }
          piStack_218 = (int *)0x66123c;
          FUN_0050a850();
          return 1;
        }
        if (uVar4 < 0x70000004) {
          if (uVar4 == 0x70000003) {
            iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
            if (iVar5 == 0) {
              return 1;
            }
            piStack_218 = (int *)0x6610f4;
            FUN_0050a850();
            return 1;
          }
          if (uVar4 < 0x50050003) {
            if (uVar4 == 0x50050002) {
              (**(code **)(*DAT_00b5a750 + 0xc))();
              return 1;
            }
            if (uVar4 == 0x30050010) {
              (**(code **)(*DAT_00b5a750 + 8))();
              return 1;
            }
            if (uVar4 == 0x30050011) {
              (**(code **)(*DAT_00b5a750 + 0xc))();
              return 1;
            }
            if (uVar4 == 0x50050001) {
              (**(code **)(*DAT_00b5a750 + 8))();
              return 1;
            }
          }
          else {
            if (uVar4 == 0x70000000) {
              FUN_0065e0a0();
              return 1;
            }
            if (uVar4 == 0x70000001) {
              FUN_0065ed90();
              return 1;
            }
          }
        }
        else if (uVar4 < 0x70010002) {
          if (uVar4 == 0x70010001) {
            iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
            if (iVar5 != 0) {
              puVar6 = (undefined4 *)FUN_0065deb0();
              *(undefined4 *)(in_ECX + 0x14) = *puVar6;
              *(undefined4 *)(in_ECX + 0x18) = puVar6[1];
              puVar6 = (undefined4 *)FUN_0065deb0();
              *(undefined4 *)(in_ECX + 0x174) = *puVar6;
              *(undefined4 *)(in_ECX + 0x178) = puVar6[1];
            }
            FUN_0065ed90();
            return 1;
          }
          if (uVar4 == 0x70000004) {
            iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
            if (iVar5 != 0) {
              puVar6 = (undefined4 *)FUN_0065deb0();
              *(undefined4 *)(in_ECX + 0x374) = *puVar6;
              *(undefined4 *)(in_ECX + 0x378) = puVar6[1];
            }
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
          if (uVar4 == 0x70010000) {
            FUN_0065e0a0();
            return 1;
          }
        }
        else {
          if (uVar4 == 0x70010002) {
            FUN_0065e0a0();
            return 1;
          }
          if (uVar4 == 0x70010003) {
            FUN_0065ed90();
            return 1;
          }
        }
      }
      else if (uVar4 < 0x70040005) {
        if (uVar4 == 0x70040004) {
          piVar7 = (int *)(**(code **)(*DAT_00b5a750 + 8))();
          if (piVar7 == (int *)0x0) {
            return 1;
          }
          (**(code **)(*piVar7 + 4))();
          return 1;
        }
        if (uVar4 < 0x70030002) {
          if (uVar4 == 0x70030001) {
            FUN_0065e240();
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
          if (uVar4 == 0x70020001) {
            iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
            if (iVar5 != 0) {
              puVar6 = (undefined4 *)FUN_0065deb0();
              *(undefined4 *)(in_ECX + 4) = *puVar6;
              *(undefined4 *)(in_ECX + 8) = puVar6[1];
            }
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
          if (uVar4 == 0x70030000) {
            iVar5 = FUN_0065e8f0();
            if (iVar5 == 0) {
              return 1;
            }
            FUN_0065de10();
            return 1;
          }
        }
        else {
          if (uVar4 == 0x70040000) {
            FUN_0065e0a0();
            return 1;
          }
          if (uVar4 == 0x70040001) {
            FUN_0065ed90();
            return 1;
          }
        }
      }
      else if (uVar4 < 0x70050002) {
        if (uVar4 == 0x70050001) {
          (**(code **)(*DAT_00b5a750 + 0xc))();
          (**(code **)(*DAT_00b5a750 + 0xc))();
          piStack_218 = (int *)0x661496;
          (**(code **)(*DAT_00b5a750 + 0xc))();
          piStack_218 = (int *)0x45;
          piStack_21c = (int *)0x6614a3;
          iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
          if (iVar5 != 0) {
            iVar5 = *DAT_00b5ad54;
            piStack_21c = (int *)auStack_134;
            piStack_220 = (int *)0x6614be;
            piStack_21c = (int *)FUN_0065deb0();
            piStack_220 = (int *)0x6614c4;
            (**(code **)(iVar5 + 0x28))();
          }
          piStack_21c = (int *)0x45;
          piStack_220 = (int *)0x6614d1;
          (**(code **)(*DAT_00b5a750 + 0xc))();
          piStack_220 = (int *)0x46;
          puStack_224 = (undefined1 *)0x6614de;
          iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
          if (iVar5 != 0) {
            iVar5 = *DAT_00b5ad54;
            puStack_224 = auStack_1cc;
            iStack_228 = 0x6614f6;
            puStack_224 = (undefined1 *)FUN_0065deb0();
            iStack_228 = 0x6614fc;
            (**(code **)(iVar5 + 0x2c))();
          }
          puStack_224 = (undefined1 *)0x46;
          iStack_228 = 0x661509;
          (**(code **)(*DAT_00b5a750 + 0xc))();
          iStack_228 = 0x47;
          piStack_22c = (int *)0x661516;
          iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
          if (iVar5 != 0) {
            iVar5 = *DAT_00b5ad54;
            piStack_22c = aiStack_154;
            puStack_230 = (undefined1 *)0x661531;
            piStack_22c = (int *)FUN_0065deb0();
            puStack_230 = (undefined1 *)0x661537;
            (**(code **)(iVar5 + 0x30))();
          }
          piStack_22c = (int *)0x47;
          puStack_230 = (undefined1 *)0x661544;
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        }
        if (uVar4 == 0x70040005) {
          (**(code **)(*DAT_00b5a74c + 0xc))();
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        }
        if (uVar4 == 0x70050000) {
          (**(code **)(*DAT_00b5a750 + 8))();
          (**(code **)(*DAT_00b5a750 + 8))();
          piStack_218 = (int *)0x6613b0;
          (**(code **)(*DAT_00b5a750 + 8))();
          piStack_218 = (int *)0x45;
          piStack_21c = (int *)0x6613bd;
          iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
          if (iVar5 != 0) {
            piStack_21c = (int *)0x6613ce;
            puVar6 = (undefined4 *)(**(code **)(*DAT_00b5ad54 + 0x18))();
            piStack_21c = (int *)puVar6[1];
            piStack_220 = (int *)*puVar6;
            puStack_224 = (undefined1 *)0x6613dc;
            FUN_0050a850();
          }
          piStack_21c = (int *)0x46;
          piStack_220 = (int *)0x6613e9;
          iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
          if (iVar5 != 0) {
            piStack_220 = (int *)0x6613fa;
            puVar6 = (undefined4 *)(**(code **)(*DAT_00b5ad54 + 0x1c))();
            piStack_220 = (int *)puVar6[1];
            puStack_224 = (undefined1 *)*puVar6;
            iStack_228 = 0x661408;
            FUN_0050a850();
          }
          piStack_220 = (int *)0x47;
          puStack_224 = (undefined1 *)0x661415;
          iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
          if (iVar5 == 0) {
            return 1;
          }
          puStack_224 = (undefined1 *)0x66142a;
          piVar7 = (int *)(**(code **)(*DAT_00b5ad54 + 0x20))();
          puStack_224 = (undefined1 *)piVar7[1];
          iStack_228 = *piVar7;
          piStack_22c = (int *)0x661438;
          FUN_0050a850();
          puStack_224 = (undefined1 *)0x66143f;
          FUN_00668970();
          return 1;
        }
      }
      else {
        if (uVar4 == 0x70060000) goto LAB_00662485;
        if (uVar4 == 0x70060001) {
          FUN_0065e2d0();
          return 1;
        }
      }
    }
    else if (uVar4 < 0x70130002) {
      if (uVar4 == 0x70130001) {
        FUN_0065ed90();
        return 1;
      }
      if (uVar4 < 0x70100002) {
        if (uVar4 == 0x70100001) {
          iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
          if (iVar5 != 0) {
            puVar6 = (undefined4 *)FUN_0065deb0();
            *(undefined4 *)(in_ECX + 0x44) = *puVar6;
            *(undefined4 *)(in_ECX + 0x48) = puVar6[1];
          }
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        }
        if (uVar4 < 0x70090001) {
          if (uVar4 == 0x70090000) {
            iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
            if (iVar5 == 0) {
              return 1;
            }
            piStack_218 = (int *)0x661639;
            FUN_0050a850();
            return 1;
          }
          if (uVar4 == 0x70070001) {
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
          if (uVar4 == 0x70080000) {
            FUN_0065e0a0();
            return 1;
          }
          if (uVar4 == 0x70080001) {
            FUN_0065ed90();
            return 1;
          }
        }
        else {
          if (uVar4 == 0x70090001) {
            iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
            if (iVar5 != 0) {
              puVar6 = (undefined4 *)FUN_0065deb0();
              *(undefined4 *)(in_ECX + 0x5c) = *puVar6;
              *(undefined4 *)(in_ECX + 0x60) = puVar6[1];
            }
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
          if (uVar4 == 0x70100000) {
            iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
            if (iVar5 == 0) {
              return 1;
            }
            piStack_218 = (int *)0x66167a;
            FUN_0050a850();
            return 1;
          }
        }
      }
      else if (uVar4 < 0x70120001) {
        if (uVar4 == 0x70120000) {
          FUN_0065e170();
          return 1;
        }
        if (uVar4 == 0x70110000) {
          iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
          if (iVar5 == 0) {
            return 1;
          }
          piStack_218 = (int *)0x661789;
          FUN_0050a850();
          return 1;
        }
        if (uVar4 == 0x70110001) {
          iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
          if (iVar5 != 0) {
            puVar6 = (undefined4 *)FUN_0065deb0();
            *(undefined4 *)(in_ECX + 0x4c) = *puVar6;
            *(undefined4 *)(in_ECX + 0x50) = puVar6[1];
          }
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        }
      }
      else {
        if (uVar4 == 0x70120001) {
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        }
        if (uVar4 == 0x70130000) {
          FUN_0065e0a0();
          return 1;
        }
      }
    }
    else if (uVar4 < 0x70140002) {
      if (uVar4 == 0x70140001) {
        FUN_0065ed90();
        return 1;
      }
      if (uVar4 < 0x70130008) {
        if (uVar4 == 0x70130007) {
          (**(code **)(*DAT_00b5a750 + 8))();
          return 1;
        }
        if (uVar4 == 0x70130003) {
          (**(code **)(*DAT_00b5a750 + 8))();
          piStack_218 = (int *)0x661865;
          FUN_0050a850();
          piStack_218 = (int *)0x661874;
          FUN_006746e0();
          return 1;
        }
        if (uVar4 == 0x70130004) {
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        }
      }
      else {
        if (uVar4 == 0x70130008) {
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        }
        if (uVar4 == 0x70140000) {
          FUN_0065e0a0();
          return 1;
        }
      }
    }
    else if (uVar4 < 0x7014000a) {
      if (uVar4 == 0x70140009) {
        iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
        if (iVar5 != 0) {
          FUN_0050a850();
          piStack_22c = param_1 + 3;
          puStack_230 = (undefined1 *)0x6619ad;
          FUN_00765c50();
          puStack_230 = (undefined1 *)CONCAT22(extraout_var,(short)param_1[2]);
          piStack_22c = (int *)param_1[1];
          uStack_234 = 0x6619bd;
          FUN_00673d40();
          return 1;
        }
      }
      else {
        if (uVar4 == 0x70140007) {
          iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
          if (iVar5 == 0) {
            return 1;
          }
          piStack_218 = (int *)0x66194c;
          FUN_0050a850();
          piStack_218 = (int *)param_1[2];
          piStack_21c = (int *)param_1[1];
          piStack_220 = (int *)0x661963;
          FUN_00674280();
          return 1;
        }
        if (uVar4 == 0x70140008) {
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        }
      }
    }
    else {
      if (uVar4 == 0x70140010) {
        (**(code **)(*DAT_00b5a750 + 0xc))();
        return 1;
      }
      if (uVar4 == 0x70150003) {
        (**(code **)(*DAT_00b5a750 + 0xc))();
        return 1;
      }
    }
switchD_00662087_caseD_70320002:
    cVar3 = (**(code **)(*DAT_00b5a74c + 0x14))();
    if (cVar3 == '\x01') {
      return 1;
    }
    cVar3 = (**(code **)(*DAT_00b5b0c0 + 4))();
    return (uint)(cVar3 == '\x01');
  }
  if (uVar4 < 0x70290006) {
    if (uVar4 == 0x70290005) {
      (**(code **)(*DAT_00b5a750 + 0xc))();
      return 1;
    }
    if (uVar4 < 0x70210005) {
      if (uVar4 == 0x70210004) {
        iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
        if (iVar5 != 0) {
          puVar6 = (undefined4 *)FUN_0065deb0();
          *(undefined4 *)(in_ECX + 0xec) = *puVar6;
          *(undefined4 *)(in_ECX + 0xf0) = puVar6[1];
        }
        (**(code **)(*DAT_00b5a750 + 0xc))();
        return 1;
      }
      if (uVar4 < 0x70190002) {
        if (uVar4 == 0x70190001) {
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        }
        if (uVar4 < 0x70180001) {
          if (uVar4 == 0x70180000) {
            iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
            if (iVar5 == 0) {
              return 1;
            }
            piStack_218 = (int *)0x661b8f;
            FUN_0050a850();
            return 1;
          }
          if (uVar4 == 0x70160001) {
            iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
            if (iVar5 != 0) {
              puVar6 = (undefined4 *)FUN_0065deb0();
              *(undefined4 *)(in_ECX + 0x94) = *puVar6;
              *(undefined4 *)(in_ECX + 0x98) = puVar6[1];
            }
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
          if (uVar4 == 0x70170000) {
            iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
            if (iVar5 == 0) {
              return 1;
            }
            piStack_218 = (int *)0x661b11;
            FUN_0050a850();
            return 1;
          }
          if (uVar4 == 0x70170001) {
            iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
            if (iVar5 != 0) {
              puVar6 = (undefined4 *)FUN_0065deb0();
              *(undefined4 *)(in_ECX + 0xa4) = *puVar6;
              *(undefined4 *)(in_ECX + 0xa8) = puVar6[1];
            }
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
        }
        else {
          if (uVar4 == 0x70180001) {
            iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
            if (iVar5 != 0) {
              puVar6 = (undefined4 *)FUN_0065deb0();
              *(undefined4 *)(in_ECX + 0xbc) = *puVar6;
              *(undefined4 *)(in_ECX + 0xc0) = puVar6[1];
              puVar6 = (undefined4 *)FUN_0065deb0();
              *(undefined4 *)(in_ECX + 0x74) = *puVar6;
              *(undefined4 *)(in_ECX + 0x78) = puVar6[1];
              puVar6 = (undefined4 *)FUN_0065deb0();
              *(undefined4 *)(in_ECX + 0x6c) = *puVar6;
              *(undefined4 *)(in_ECX + 0x70) = puVar6[1];
            }
            (**(code **)(*DAT_00b5a750 + 0xc))();
            return 1;
          }
          if (uVar4 == 0x70190000) {
            (**(code **)(*DAT_00b5a750 + 8))();
            return 1;
          }
        }
      }
      else if (uVar4 < 0x70210001) {
        if (uVar4 == 0x70210000) {
          FUN_0065e0a0();
          return 1;
        }
        if (uVar4 == 0x70200000) {
          return 1;
        }
        if (uVar4 == 0x70200001) {
          return 1;
        }
      }
      else {
        if (uVar4 == 0x70210001) {
          FUN_0065ed90();
          return 1;
        }
        if (uVar4 == 0x70210003) {
          iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
          if (iVar5 == 0) {
            return 1;
          }
          piStack_218 = (int *)0x661cd3;
          FUN_0050a850();
          return 1;
        }
      }
    }
    else if (uVar4 < 0x70260002) {
      if (uVar4 == 0x70260001) {
        (**(code **)(*DAT_00b5a750 + 0xc))();
        return 1;
      }
      if (uVar4 < 0x70240001) {
        if (uVar4 == 0x70240000) {
          (**(code **)(*DAT_00b5a750 + 8))();
          return 1;
        }
        if (uVar4 == 0x70230000) {
          (**(code **)(*DAT_00b5a750 + 8))();
          return 1;
        }
        if (uVar4 == 0x70230001) {
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        }
      }
      else {
        if (uVar4 == 0x70240001) {
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        }
        if (uVar4 == 0x70260000) {
          (**(code **)(*DAT_00b5a750 + 8))();
          return 1;
        }
      }
    }
    else if (uVar4 < 0x70290001) {
      if (uVar4 == 0x70290000) {
        (**(code **)(*DAT_00b5a750 + 8))();
        return 1;
      }
      if (uVar4 == 0x70280000) {
        (**(code **)(*DAT_00b5a750 + 8))();
        return 1;
      }
      if (uVar4 == 0x70280001) {
        (**(code **)(*DAT_00b5a750 + 0xc))();
        return 1;
      }
    }
    else {
      if (uVar4 == 0x70290001) {
        (**(code **)(*DAT_00b5a750 + 0xc))();
        return 1;
      }
      if (uVar4 == 0x70290004) {
        iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
        if (iVar5 == 0) {
          return 1;
        }
        piStack_218 = (int *)0x661ea2;
        FUN_0050a850();
        return 1;
      }
    }
    goto switchD_00662087_caseD_70320002;
  }
  if (uVar4 < 0x70320012) {
    if (uVar4 == 0x70320011) {
      (**(code **)(*DAT_00b5a750 + 0xc))();
      return 1;
    }
    if (uVar4 < 0x70320001) {
      if (uVar4 == 0x70320000) {
        FUN_0065e0a0();
        return 1;
      }
      if (uVar4 < 0x70300002) {
        if (uVar4 == 0x70300001) {
          iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
          if (iVar5 != 0) {
            puVar6 = (undefined4 *)FUN_0065deb0();
            *(undefined4 *)(in_ECX + 0x14c) = *puVar6;
            *(undefined4 *)(in_ECX + 0x150) = puVar6[1];
          }
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        }
        if (uVar4 == 0x70290006) {
          (**(code **)(*DAT_00b5a750 + 8))();
          return 1;
        }
        if (uVar4 == 0x70290007) {
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        }
        if (uVar4 == 0x70300000) {
          iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
          if (iVar5 == 0) {
            return 1;
          }
          piStack_218 = (int *)0x661f4d;
          FUN_0050a850();
          return 1;
        }
      }
      else {
        if (uVar4 == 0x70310000) {
          iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
          if (iVar5 == 0) {
            return 1;
          }
          piStack_218 = (int *)0x662051;
          FUN_0050a850();
          return 1;
        }
        if (uVar4 == 0x70310001) {
          iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
          if (iVar5 != 0) {
            puVar6 = (undefined4 *)FUN_0065deb0();
            *(undefined4 *)(in_ECX + 0x154) = *puVar6;
            *(undefined4 *)(in_ECX + 0x158) = puVar6[1];
          }
          (**(code **)(*DAT_00b5a750 + 0xc))();
          return 1;
        }
      }
      goto switchD_00662087_caseD_70320002;
    }
    switch(uVar4) {
    case 0x70320001:
      iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
      if (iVar5 != 0) {
        FUN_00670410();
        puVar6 = (undefined4 *)FUN_0065deb0();
        *(undefined4 *)(in_ECX + 0x14) = *puVar6;
        *(undefined4 *)(in_ECX + 0x18) = puVar6[1];
        puVar6 = (undefined4 *)FUN_0065deb0();
        *(undefined4 *)(in_ECX + 0x174) = *puVar6;
        *(undefined4 *)(in_ECX + 0x178) = puVar6[1];
      }
      FUN_0065ed90();
      return 1;
    default:
      goto switchD_00662087_caseD_70320002;
    case 0x70320003:
      iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
      if (iVar5 == 0) {
        return 1;
      }
      piStack_218 = (int *)0x6620b8;
      FUN_0050a850();
      return 1;
    case 0x70320004:
      (**(code **)(*DAT_00b5a750 + 0xc))();
      return 1;
    case 0x70320008:
      puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
      if (puVar6 != (undefined4 *)0x0) {
        puVar6 = (undefined4 *)*puVar6;
        FUN_005523a0();
        (*(code *)*puVar6)();
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      return 1;
    case 0x70320010:
    }
    goto LAB_006623ab;
  }
  switch(uVar4) {
  case 0x70320012:
    goto LAB_006623ab;
  case 0x70320013:
    (**(code **)(*DAT_00b5a750 + 0xc))();
    return 1;
  case 0x70320014:
    iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
    if (iVar5 != 0) {
      piStack_218 = (int *)0x66225f;
      FUN_0050a850();
      piStack_218 = param_1 + 0xf;
      piStack_21c = param_1 + 8;
      piStack_220 = param_1 + 1;
      puStack_224 = (undefined1 *)0x66227a;
      FUN_0066feb0();
      return 1;
    }
    break;
  case 0x70320015:
    (**(code **)(*DAT_00b5a750 + 0xc))();
    return 1;
  case 0x70320016:
    iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
    if (iVar5 != 0) {
      piStack_218 = (int *)0x662386;
      FUN_0050a850();
      return 1;
    }
    break;
  case 0x70320017:
    (**(code **)(*DAT_00b5a750 + 0xc))();
    return 1;
  case 0x70320018:
LAB_006623ab:
    iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
    if (iVar5 != 0) {
      piStack_218 = (int *)0x6623d9;
      FUN_0050a850();
      return 1;
    }
    break;
  case 0x70320019:
    (**(code **)(*DAT_00b5a750 + 0xc))();
    return 1;
  default:
    goto switchD_00662087_caseD_70320002;
  case 0x70320021:
    puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
    if (puVar6 != (undefined4 *)0x0) {
      FUN_00401830();
      (**(code **)*puVar6)();
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    break;
  case 0x70320023:
    iVar5 = (**(code **)(*DAT_00b5a750 + 8))();
    if (iVar5 != 0) {
      piStack_218 = (int *)0x6622c9;
      FUN_0050a850();
      piStack_218 = (int *)0x6622d8;
      FUN_0066fc20();
      return 1;
    }
    break;
  case 0x70320024:
    (**(code **)(*DAT_00b5a750 + 0xc))();
    return 1;
  }
  return 1;
}


// ==== FUN_006638a0 @ 0x006638a0 ====

void FUN_006638a0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x21) == '\0') {
    FUN_006638a0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_006638e0 @ 0x006638e0 ====

void * FUN_006638e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c530;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x24);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_0065ddc0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00663955 @ 0x00663955 ====

void Catch_00663955(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00663970 @ 0x00663970 ====

void FUN_00663970(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c540;
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


// ==== Catch@006639fa @ 0x006639fa ====

void Catch_006639fa(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00663a10 @ 0x00663a10 ====

void FUN_00663a10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d69f0;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined2 *)(in_ECX + 8) = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  return;
}


// ==== FUN_00663a40 @ 0x00663a40 ====

undefined4 FUN_00663a40(void)

{
  return 0x70030001;
}


// ==== FUN_00663a50 @ 0x00663a50 ====

void FUN_00663a50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d69f0;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[7] = 0xf;
    in_ECX[6] = 0;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_0099cf40;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00663a90 @ 0x00663a90 ====

void FUN_00663a90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d69f0;
  if (0xf < (uint)in_ECX[7]) {
    _free((void *)in_ECX[2]);
    return;
  }
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *in_ECX = &PTR_FUN_0099cf40;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00663ae0 @ 0x00663ae0 ====

int FUN_00663ae0(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(in_ECX + 0xc,0,0xffffffff);
  return param_1;
}


// ==== FUN_00663b10 @ 0x00663b10 ====

int FUN_00663b10(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(in_ECX + 0x20,0,0xffffffff);
  return param_1;
}


// ==== FUN_00663b40 @ 0x00663b40 ====

int FUN_00663b40(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(in_ECX + 0x3c,0,0xffffffff);
  return param_1;
}


// ==== FUN_00663b90 @ 0x00663b90 ====

void FUN_00663b90(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_006638e0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00663c95:
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
      if ((char)piVar6[8] == '\0') goto LAB_00663c95;
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


// ==== FUN_00663d70 @ 0x00663d70 ====

void FUN_00663d70(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_00663b90(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_004ddea0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00663b90(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00663e30 @ 0x00663e30 ====

undefined4 * FUN_00663e30(undefined4 *param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 local_8 [8];
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_00663b90(param_1,1,*(undefined4 *)(in_ECX + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    if (*param_3 < (uint)param_2[3]) {
      FUN_00663b90(param_1,1,param_2,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    if (*(uint *)(piVar1[2] + 0xc) < *param_3) {
      FUN_00663b90(param_1,0,piVar1[2],param_3);
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
          FUN_00663b90(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_00663b90(param_1,0,param_2,param_3);
        return param_1;
      }
      uVar3 = param_2[3];
    }
    if (uVar3 < uVar2) {
      FUN_004dde50();
      if ((param_2 == *(int **)(in_ECX + 4)) || (uVar2 < (uint)param_2[3])) {
        if (*(char *)(param_2[2] + 0x21) == '\0') {
          FUN_00663b90(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_00663b90(param_1,0,param_2,param_3);
        return param_1;
      }
    }
  }
  puVar4 = (undefined4 *)FUN_00663d70(local_8,param_3);
  *param_1 = *puVar4;
  return param_1;
}


// ==== FUN_00663fa0 @ 0x00663fa0 ====

void FUN_00663fa0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_006638a0(piVar6[1]);
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
    FUN_0057e890(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00664060 @ 0x00664060 ====

undefined4 * FUN_00664060(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int in_ECX;
  undefined4 *puVar4;
  uint local_24;
  uint local_14;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar4 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar4[1] + 0x21) == '\0') {
    puVar1 = (undefined4 *)puVar4[1];
    do {
      if ((uint)puVar1[3] < *param_1) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar4 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x21) == '\0');
  }
  if ((puVar4 == *(undefined4 **)(in_ECX + 4)) || (*param_1 < (uint)puVar4[3])) {
    local_14 = *param_1;
    local_8 = 0;
    local_c = 0;
    local_24 = local_24 & 0xffffff00;
    local_10 = local_24;
    local_4 = 0;
    piVar3 = (int *)FUN_00663e30(&param_1,puVar4,&local_14);
    return (undefined4 *)(*piVar3 + 0x10);
  }
  return puVar4 + 4;
}


// ==== FUN_006640f0 @ 0x006640f0 ====

undefined4 FUN_006640f0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00406600(in_ECX + 0xc);
  return param_1;
}


// ==== FUN_00664110 @ 0x00664110 ====

void FUN_00664110(undefined4 param_1,void *param_2,undefined4 param_3)

{
  void *_Memory;
  
  FUN_0043b3d0(&param_1);
  _Memory = param_2;
  if (param_2 == (void *)0x0) {
    return;
  }
  FUN_00405de0(param_2,param_3,&param_1,param_1);
  _free(_Memory);
  return;
}


// ==== FUN_00664150 @ 0x00664150 ====

void FUN_00664150(byte param_1)

{
  void *in_ECX;
  
  FUN_0065edc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00664170 @ 0x00664170 ====

void FUN_00664170(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d6a60;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00664190 @ 0x00664190 ====

void FUN_00664190(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_00664190(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_006641d0 @ 0x006641d0 ====

void * FUN_006641d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c550;
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


// ==== Catch@00664245 @ 0x00664245 ====

void Catch_00664245(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00664260 @ 0x00664260 ====

void FUN_00664260(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c560;
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


// ==== Catch@006642ea @ 0x006642ea ====

void Catch_006642ea(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00664300 @ 0x00664300 ====

void FUN_00664300(void)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int in_ECX;
  
  puVar8 = *(undefined4 **)(in_ECX + 8);
  puVar2 = (undefined4 *)*puVar8;
  while (puVar2 != puVar8) {
    piVar3 = (int *)puVar2[4];
    iVar6 = (**(code **)(*piVar3 + 0x14))();
    if (((((iVar6 != 0x20) && (iVar6 = (**(code **)(*piVar3 + 0x14))(), iVar6 != 0x4d)) &&
         (iVar6 = (**(code **)(*piVar3 + 0x14))(), iVar6 != 0x4b)) &&
        ((iVar6 = (**(code **)(*piVar3 + 0x14))(), iVar6 != 0x4f &&
         (iVar6 = (**(code **)(*piVar3 + 0x14))(), iVar6 != 0x58)))) &&
       ((iVar6 = (**(code **)(*piVar3 + 0x14))(), iVar6 != 0x4c && ((int *)piVar3[1] != (int *)0x0))
       )) {
      iVar6 = *(int *)piVar3[1];
      uVar7 = (**(code **)(iVar6 + 0x14))();
      (**(code **)(iVar6 + 0x18))(uVar7);
    }
    if (*(char *)((int)puVar2 + 0x15) == '\0') {
      puVar4 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar4 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x15);
        puVar2 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x15);
          puVar2 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x15);
        puVar5 = (undefined4 *)puVar2[1];
        puVar4 = puVar2;
        while ((puVar2 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x15);
          puVar5 = (undefined4 *)puVar2[1];
          puVar4 = puVar2;
        }
      }
    }
  }
  puVar8 = operator_new(4);
  if (puVar8 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar8 = &PTR_FUN_009bb160;
  FUN_00797a20(puVar8);
  return;
}


// ==== FUN_006643f0 @ 0x006643f0 ====

undefined4 FUN_006643f0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char cVar5;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  puVar2 = (undefined4 *)*puVar1;
  while( true ) {
    if (puVar2 == puVar1) {
      return 0;
    }
    cVar5 = (**(code **)(*(int *)puVar2[4] + 8))(param_1);
    if (cVar5 == '\x01') break;
    if (*(char *)((int)puVar2 + 0x15) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x15) == '\0') {
        cVar5 = *(char *)((int)*puVar3 + 0x15);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar5 == '\0') {
          cVar5 = *(char *)((int)*puVar3 + 0x15);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar5 = *(char *)((int)puVar2[1] + 0x15);
        puVar4 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar4, cVar5 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar5 = *(char *)((int)puVar2[1] + 0x15);
          puVar4 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  return 1;
}


// ==== FUN_00664470 @ 0x00664470 ====

undefined4 FUN_00664470(void)

{
  uint in_ECX;
  uint local_4;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    local_4 = in_ECX & 0xffffff00;
    FUN_00409660(**(undefined4 **)(in_ECX + 8),*(undefined4 **)(in_ECX + 8),local_4);
    FUN_00664190(*(undefined4 *)(*(int *)(in_ECX + 8) + 4));
    *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 8);
    *(int *)(*(int *)(in_ECX + 8) + 8) = *(int *)(in_ECX + 8);
  }
  return 1;
}


// ==== FUN_006644c0 @ 0x006644c0 ====

undefined4 FUN_006644c0(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    local_4 = in_ECX;
    FUN_0079bba0(&local_4,&param_1);
    if (local_4 != *(int *)(in_ECX + 8)) {
      return *(undefined4 *)(local_4 + 0x10);
    }
  }
  return 0;
}


// ==== FUN_00664500 @ 0x00664500 ====

undefined4 FUN_00664500(undefined1 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_0079bba0(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 8)) {
    return 0;
  }
  uVar1 = *(undefined4 *)(local_4 + 0x10);
  FUN_0051a2a0(&param_1,local_4);
  return uVar1;
}


// ==== FUN_00664550 @ 0x00664550 ====

undefined4 FUN_00664550(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  undefined4 uStack_10;
  int *piStack_c;
  undefined1 auStack_8 [8];
  
  piVar1 = param_1;
  uVar2 = (**(code **)(*param_1 + 0x14))();
  param_1 = (int *)uVar2;
  piVar3 = (int *)FUN_0079bba0(&uStack_10,&param_1);
  if (*piVar3 == *(int *)(in_ECX + 8)) {
    piStack_c = piVar1;
    uStack_10 = uVar2;
    FUN_00664910(auStack_8,&uStack_10);
    return 1;
  }
  return 0;
}


// ==== FUN_006645c0 @ 0x006645c0 ====

void FUN_006645c0(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009d6a7c;
  DAT_00b5a74c = 0;
  FUN_00664470();
  FUN_00664850(local_4,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00664620 @ 0x00664620 ====

void FUN_00664620(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d6a7c;
  iVar1 = FUN_00664260();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a74c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a74c = in_ECX;
  return;
}


// ==== FUN_00664670 @ 0x00664670 ====

void FUN_00664670(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_006641d0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00664775:
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
      if ((char)piVar6[5] == '\0') goto LAB_00664775;
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


// ==== FUN_00664850 @ 0x00664850 ====

void FUN_00664850(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00664190(piVar6[1]);
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


// ==== FUN_00664910 @ 0x00664910 ====

void FUN_00664910(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_00664670(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00664670(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_006649d0 @ 0x006649d0 ====

void FUN_006649d0(byte param_1)

{
  void *in_ECX;
  
  FUN_006645c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006649f0 @ 0x006649f0 ====

void FUN_006649f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d6b00;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00664a10 @ 0x00664a10 ====

void FUN_00664a10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d6b14;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a750 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a750 = in_ECX;
  return;
}


// ==== FUN_00664a60 @ 0x00664a60 ====

undefined4 FUN_00664a60(undefined4 param_1)

{
  undefined4 *puVar1;
  
  if (DAT_00b5a74c != (int *)0x0) {
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a74c + 8))(param_1);
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
  }
  return 1;
}


// ==== FUN_00664a90 @ 0x00664a90 ====

undefined4 * FUN_00664a90(undefined4 param_1)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  void *pvVar4;
  undefined4 *extraout_EAX;
  undefined4 *puVar5;
  undefined4 *extraout_EAX_00;
  void *unaff_ESI;
  undefined4 uStack_1c;
  uint uStack_c;
  uint uStack_8;
  
  iVar3 = (**(code **)(*DAT_00b5a74c + 0xc))(param_1);
  if (iVar3 != 0) {
    return (undefined4 *)0x0;
  }
  switch(param_1) {
  case 0:
    pvVar4 = operator_new(0x14);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006c7030();
      goto LAB_00665ad8;
    }
    break;
  case 1:
    pvVar4 = operator_new(0x38);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006c6020();
      goto LAB_00665ad8;
    }
    break;
  case 2:
    pvVar4 = operator_new(0x54);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006c5020();
      goto LAB_00665ad8;
    }
    break;
  case 3:
    pvVar4 = operator_new(0x44);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006c2a90();
      goto LAB_00665ad8;
    }
    break;
  case 4:
    pvVar4 = operator_new(0x58);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00668660();
      goto LAB_00665ad8;
    }
    break;
  case 5:
    pvVar4 = operator_new(0xac);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006c12e0();
      goto LAB_00665ad8;
    }
    break;
  default:
    FUN_00401830(s_false_009d6ad0);
    FUN_00406880((int)register0x00000010 + -0x20);
    if (uStack_8 < 0x10) {
      pcVar1 = (code *)swi(3);
      puVar5 = (undefined4 *)(*pcVar1)();
      return puVar5;
    }
    _free(uStack_1c);
    return extraout_EAX;
  case 7:
    pvVar4 = operator_new(0x58);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006bdbc0();
      goto LAB_00665ad8;
    }
    break;
  case 8:
    pvVar4 = operator_new(0x1c);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006bc050();
      goto LAB_00665ad8;
    }
    break;
  case 9:
    pvVar4 = operator_new(0xd0);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006bb060();
      goto LAB_00665ad8;
    }
    break;
  case 10:
    pvVar4 = operator_new(0xc);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006671e0();
      goto LAB_00665ad8;
    }
    break;
  case 0xb:
    pvVar4 = operator_new(0x2c);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006b8240();
      goto LAB_00665ad8;
    }
    break;
  case 0xc:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006b79a0();
      goto LAB_00665ad8;
    }
    break;
  case 0xd:
    pvVar4 = operator_new(0x30);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006afbb0();
      goto LAB_00665ad8;
    }
    break;
  case 0xe:
    pvVar4 = operator_new(0x9c);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006b1e40();
      goto LAB_00665ad8;
    }
    break;
  case 0xf:
    pvVar4 = operator_new(0xc);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006ce0c0();
      goto LAB_00665ad8;
    }
    break;
  case 0x10:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006cf910();
      goto LAB_00665ad8;
    }
    break;
  case 0x12:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006cd690();
      goto LAB_00665ad8;
    }
    break;
  case 0x13:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006aab00();
      goto LAB_00665ad8;
    }
    break;
  case 0x14:
    pvVar4 = operator_new(0x30);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006cf440();
      goto LAB_00665ad8;
    }
    break;
  case 0x17:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006adb10();
      goto LAB_00665ad8;
    }
    break;
  case 0x1b:
    pvVar4 = operator_new(0x14);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006b74a0();
      goto LAB_00665ad8;
    }
    break;
  case 0x1c:
    pvVar4 = operator_new(0x38);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006d6940();
      goto LAB_00665ad8;
    }
    break;
  case 0x1d:
    pvVar4 = operator_new(0x30);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006d2d30();
      goto LAB_00665ad8;
    }
    break;
  case 0x1f:
    pvVar4 = operator_new(0x28);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00666410();
      goto LAB_00665ad8;
    }
    break;
  case 0x20:
    pvVar4 = operator_new(0x118);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006b4a00();
      goto LAB_00665ad8;
    }
    break;
  case 0x21:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006ad050();
      goto LAB_00665ad8;
    }
    break;
  case 0x22:
    pvVar4 = operator_new(0xc);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00678800();
      goto LAB_00665ad8;
    }
    break;
  case 0x23:
    pvVar4 = operator_new(0xc);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006acb30();
      goto LAB_00665ad8;
    }
    break;
  case 0x24:
    pvVar4 = operator_new(0x10);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006ac540();
      goto LAB_00665ad8;
    }
    break;
  case 0x25:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0065dcf0();
      goto LAB_00665ad8;
    }
    break;
  case 0x26:
    pvVar4 = operator_new(0x18);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006aa5c0();
      goto LAB_00665ad8;
    }
    break;
  case 0x27:
    pvVar4 = operator_new(0x24);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006aa250();
      goto LAB_00665ad8;
    }
    break;
  case 0x28:
    pvVar4 = operator_new(0xe0);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006a9b00();
      goto LAB_00665ad8;
    }
    break;
  case 0x29:
    pvVar4 = operator_new(0x18);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006a6360();
      goto LAB_00665ad8;
    }
    break;
  case 0x2a:
    pvVar4 = operator_new(0xc4);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006a5720();
      goto LAB_00665ad8;
    }
    break;
  case 0x2b:
    pvVar4 = operator_new(0xb0);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006a44c0();
      goto LAB_00665ad8;
    }
    break;
  case 0x2c:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00674260();
      goto LAB_00665ad8;
    }
    break;
  case 0x2d:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0069ff20();
      goto LAB_00665ad8;
    }
    break;
  case 0x2e:
    pvVar4 = operator_new(0x34);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00672de0();
      goto LAB_00665ad8;
    }
    break;
  case 0x2f:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0069fb00();
      goto LAB_00665ad8;
    }
    break;
  case 0x30:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0066f360();
      goto LAB_00665ad8;
    }
    break;
  case 0x31:
    pvVar4 = operator_new(0xc);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0069edb0();
      goto LAB_00665ad8;
    }
    break;
  case 0x32:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00670230();
      goto LAB_00665ad8;
    }
    break;
  case 0x33:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0066fa50();
      goto LAB_00665ad8;
    }
    break;
  case 0x34:
    pvVar4 = operator_new(0x18);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0069e600();
      goto LAB_00665ad8;
    }
    break;
  case 0x35:
    pvVar4 = operator_new(0x10);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0066fd10();
      goto LAB_00665ad8;
    }
    break;
  case 0x36:
    pvVar4 = operator_new(0x1c);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0069d2f0();
      goto LAB_00665ad8;
    }
    break;
  case 0x37:
    pvVar4 = operator_new(0x2c);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0069bc80();
      goto LAB_00665ad8;
    }
    break;
  case 0x38:
    pvVar4 = operator_new(0xc);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006a2890();
      goto LAB_00665ad8;
    }
    break;
  case 0x39:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006a23e0();
      goto LAB_00665ad8;
    }
    break;
  case 0x3a:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006746c0();
      goto LAB_00665ad8;
    }
    break;
  case 0x3b:
    pvVar4 = operator_new(0x90);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00690c70();
      goto LAB_00665ad8;
    }
    break;
  case 0x3c:
    pvVar4 = operator_new(0xb0);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006a1f70();
      goto LAB_00665ad8;
    }
    break;
  case 0x3d:
    pvVar4 = operator_new(0x1c);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00692f20();
      goto LAB_00665ad8;
    }
    break;
  case 0x3e:
    pvVar4 = operator_new(0x3c);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00699260();
      goto LAB_00665ad8;
    }
    break;
  case 0x3f:
    pvVar4 = operator_new(0x10);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0066e7c0();
      goto LAB_00665ad8;
    }
    break;
  case 0x40:
    pvVar4 = operator_new(0x60);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00695e60();
      goto LAB_00665ad8;
    }
    break;
  case 0x41:
    pvVar4 = operator_new(0xc);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00673d20();
      goto LAB_00665ad8;
    }
    break;
  case 0x43:
    pvVar4 = operator_new(0x10);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006b6630();
      goto LAB_00665ad8;
    }
    break;
  case 0x45:
    pvVar4 = operator_new(0x30);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006cc9b0();
      goto LAB_00665ad8;
    }
    break;
  case 0x46:
    pvVar4 = operator_new(0xc);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006cb820();
      goto LAB_00665ad8;
    }
    break;
  case 0x47:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006695b0();
      goto LAB_00665ad8;
    }
    break;
  case 0x48:
    pvVar4 = operator_new(0x1c);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006ca4c0();
      goto LAB_00665ad8;
    }
    break;
  case 0x49:
    pvVar4 = operator_new(0x14);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006c8fa0();
      goto LAB_00665ad8;
    }
    break;
  case 0x4a:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006c7500();
      goto LAB_00665ad8;
    }
    break;
  case 0x4c:
    pvVar4 = operator_new(0x10);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0069acf0();
      goto LAB_00665ad8;
    }
    break;
  case 0x4e:
    pvVar4 = operator_new(0x1c);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00699420();
      goto LAB_00665ad8;
    }
    break;
  case 0x4f:
    pvVar4 = operator_new(0x38);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0069a3e0();
      goto LAB_00665ad8;
    }
    break;
  case 0x50:
    pvVar4 = operator_new(0x34);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006929f0();
      goto LAB_00665ad8;
    }
    break;
  case 0x51:
    pvVar4 = operator_new(0xc);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006921f0();
      goto LAB_00665ad8;
    }
    break;
  case 0x52:
    pvVar4 = operator_new(0x18);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006918e0();
      goto LAB_00665ad8;
    }
    break;
  case 0x53:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006915b0();
      goto LAB_00665ad8;
    }
    break;
  case 0x54:
    pvVar4 = operator_new(0x10);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0068f6a0();
      goto LAB_00665ad8;
    }
    break;
  case 0x55:
    pvVar4 = operator_new(0x14);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0066d160();
      goto LAB_00665ad8;
    }
    break;
  case 0x56:
    pvVar4 = operator_new(0x20);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0066ce70();
      goto LAB_00665ad8;
    }
    break;
  case 0x57:
    pvVar4 = operator_new(200);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0068e5b0();
      goto LAB_00665ad8;
    }
    break;
  case 0x58:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006699a0();
      goto LAB_00665ad8;
    }
    break;
  case 0x59:
    pvVar4 = operator_new(0xc);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0068c260();
      goto LAB_00665ad8;
    }
    break;
  case 0x5a:
    pvVar4 = operator_new(0x14);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0068bd50();
      goto LAB_00665ad8;
    }
    break;
  case 0x5b:
    pvVar4 = operator_new(0x14);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0068b6a0();
      goto LAB_00665ad8;
    }
    break;
  case 0x5c:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00687880();
      goto LAB_00665ad8;
    }
    break;
  case 0x5d:
    pvVar4 = operator_new(0xc);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00687020();
      goto LAB_00665ad8;
    }
    break;
  case 0x5e:
    pvVar4 = operator_new(0x10);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00686ac0();
      goto LAB_00665ad8;
    }
    break;
  case 0x5f:
    pvVar4 = operator_new(0x18);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00686560();
      goto LAB_00665ad8;
    }
    break;
  case 0x60:
    pvVar4 = operator_new(0x14);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00685ed0();
      goto LAB_00665ad8;
    }
    break;
  case 0x61:
    pvVar4 = operator_new(0x28);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00684ae0();
      goto LAB_00665ad8;
    }
    break;
  case 0x62:
    pvVar4 = operator_new(0xc);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00683d60();
      goto LAB_00665ad8;
    }
    break;
  case 99:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006824d0();
      goto LAB_00665ad8;
    }
    break;
  case 100:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00682160();
      goto LAB_00665ad8;
    }
    break;
  case 0x65:
    pvVar4 = operator_new(0x14);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006855a0();
      goto LAB_00665ad8;
    }
    break;
  case 0x66:
    pvVar4 = operator_new(0x14);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00682d00();
      goto LAB_00665ad8;
    }
    break;
  case 0x67:
    pvVar4 = operator_new(0xc);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00677ed0();
      goto LAB_00665ad8;
    }
    break;
  case 0x68:
    pvVar4 = operator_new(0x10);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00677aa0();
      goto LAB_00665ad8;
    }
    break;
  case 0x69:
    pvVar4 = operator_new(0x10);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00677750();
      goto LAB_00665ad8;
    }
    break;
  case 0x6a:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00677320();
      goto LAB_00665ad8;
    }
    break;
  case 0x6b:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00677020();
      goto LAB_00665ad8;
    }
    break;
  case 0x6c:
    pvVar4 = operator_new(0x2c);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0068b090();
      goto LAB_00665ad8;
    }
    break;
  case 0x6d:
    pvVar4 = operator_new(0xc);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0068aa10();
      goto LAB_00665ad8;
    }
    break;
  case 0x6e:
    pvVar4 = operator_new(0x28);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00689a10();
      goto LAB_00665ad8;
    }
    break;
  case 0x6f:
    pvVar4 = operator_new(0x30);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00688f40();
      goto LAB_00665ad8;
    }
    break;
  case 0x70:
    pvVar4 = operator_new(0xc);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006885f0();
      goto LAB_00665ad8;
    }
    break;
  case 0x71:
    pvVar4 = operator_new(0xc);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00687cc0();
      goto LAB_00665ad8;
    }
    break;
  case 0x72:
    pvVar4 = operator_new(0x10);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0066c8a0();
      goto LAB_00665ad8;
    }
    break;
  case 0x73:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0066c690();
      goto LAB_00665ad8;
    }
    break;
  case 0x74:
    pvVar4 = operator_new(0x14);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0066c3c0();
      goto LAB_00665ad8;
    }
    break;
  case 0x75:
    pvVar4 = operator_new(0x10);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0066c050();
      goto LAB_00665ad8;
    }
    break;
  case 0x76:
    pvVar4 = operator_new(0x18);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0066bae0();
      goto LAB_00665ad8;
    }
    break;
  case 0x77:
    pvVar4 = operator_new(0x28);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00681850();
      goto LAB_00665ad8;
    }
    break;
  case 0x78:
    pvVar4 = operator_new(0x24);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0066b350();
      goto LAB_00665ad8;
    }
    break;
  case 0x79:
    pvVar4 = operator_new(0xc);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0066aca0();
      goto LAB_00665ad8;
    }
    break;
  case 0x7a:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0066a930();
      goto LAB_00665ad8;
    }
    break;
  case 0x7b:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00666df0();
      goto LAB_00665ad8;
    }
    break;
  case 0x7c:
    pvVar4 = operator_new(0xbc);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00680a50();
      goto LAB_00665ad8;
    }
    break;
  case 0x7d:
    pvVar4 = operator_new(0x80);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0067cf30();
      goto LAB_00665ad8;
    }
    break;
  case 0x7e:
    pvVar4 = operator_new(0x28);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0067b780();
      goto LAB_00665ad8;
    }
    break;
  case 0x7f:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0067a340();
      goto LAB_00665ad8;
    }
    break;
  case 0x81:
    pvVar4 = operator_new(0x24);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0069f710();
      goto LAB_00665ad8;
    }
    break;
  case 0x82:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0069f250();
      goto LAB_00665ad8;
    }
    break;
  case 0x83:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_0067a1a0();
      goto LAB_00665ad8;
    }
    break;
  case 0x84:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00679c90();
      goto LAB_00665ad8;
    }
    break;
  case 0x85:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00679890();
      goto LAB_00665ad8;
    }
    break;
  case 0x86:
    pvVar4 = operator_new(8);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_006796d0();
      goto LAB_00665ad8;
    }
    break;
  case 0x87:
    pvVar4 = operator_new(0x10);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00679270();
      goto LAB_00665ad8;
    }
    break;
  case 0x88:
    pvVar4 = operator_new(0xc);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00678d80();
      goto LAB_00665ad8;
    }
    break;
  case 0x89:
    pvVar4 = operator_new(0x28);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00675d20();
      goto LAB_00665ad8;
    }
    break;
  case 0x8a:
    pvVar4 = operator_new(0x18);
    if (pvVar4 != (void *)0x0) {
      puVar5 = (undefined4 *)FUN_00678230();
      goto LAB_00665ad8;
    }
  }
  puVar5 = (undefined4 *)0x0;
LAB_00665ad8:
  cVar2 = (**(code **)(*DAT_00b5a74c + 4))(puVar5);
  if (cVar2 != '\0') {
    return puVar5;
  }
  if (puVar5 != (undefined4 *)0x0) {
    (**(code **)*puVar5)(1);
  }
  FUN_00401830(s_false_009d6ad8);
  FUN_00406880((int)register0x00000010 + -0x24);
  if (uStack_c < 0x10) {
    pcVar1 = (code *)swi(3);
    puVar5 = (undefined4 *)(*pcVar1)();
    return puVar5;
  }
  _free(unaff_ESI);
  return extraout_EAX_00;
}


// ==== FUN_00665d60 @ 0x00665d60 ====

undefined4 * FUN_00665d60(int param_1)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  void *pvVar4;
  undefined4 *extraout_EAX;
  void *unaff_ESI;
  undefined4 *puVar5;
  undefined1 auStack_1a [14];
  uint uStack_c;
  
  puVar5 = (undefined4 *)0x0;
  iVar3 = (**(code **)(*DAT_00b5a74c + 0xc))(param_1);
  if (iVar3 != 0) {
    return (undefined4 *)0x0;
  }
  if (param_1 == 0x80) {
    pvVar4 = operator_new(0xa0);
    if (pvVar4 == (void *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5 = (undefined4 *)FUN_006d8220(0x80);
    }
  }
  cVar2 = (**(code **)(*DAT_00b5a74c + 4))(puVar5);
  if (cVar2 != '\0') {
    return puVar5;
  }
  if (puVar5 != (undefined4 *)0x0) {
    (**(code **)*puVar5)(1);
  }
  FUN_00401830(s_false_009d6ae0);
  FUN_00406880(auStack_1a + -10);
  if (uStack_c < 0x10) {
    pcVar1 = (code *)swi(3);
    puVar5 = (undefined4 *)(*pcVar1)();
    return puVar5;
  }
  _free(unaff_ESI);
  return extraout_EAX;
}


// ==== FUN_00665e10 @ 0x00665e10 ====

void FUN_00665e10(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5a750 = 0;
  *in_ECX = &PTR_FUN_009d6b00;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00665e40 @ 0x00665e40 ====

void FUN_00665e40(void)

{
  void *pvVar1;
  
  if (DAT_00b5a7bc == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_006d9f80();
      return;
    }
  }
  return;
}


// ==== FUN_00665e60 @ 0x00665e60 ====

void FUN_00665e60(void)

{
  if (DAT_00b5a7bc != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a7bc)(1);
  }
  return;
}


// ==== FUN_00665e80 @ 0x00665e80 ====

void FUN_00665e80(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
  (**(code **)(*piVar1 + 0x24))(param_1);
  *(char *)(in_ECX + 0x24) = (char)param_1;
  *(undefined4 *)(in_ECX + 0x14) = 1;
  return;
}


// ==== FUN_00665eb0 @ 0x00665eb0 ====

undefined1 FUN_00665eb0(void)

{
  return 0;
}


// ==== FUN_00665ed0 @ 0x00665ed0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00665ed0(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  float fVar5;
  float local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  void *local_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  FUN_004d8980(&local_2c,(int *)(in_ECX + 0x14));
  if (local_2c != *(float *)(in_ECX + 0xc)) {
    uVar1 = *(uint *)((int)local_2c + 0x10);
    uVar2 = *(uint *)(in_ECX + 0x18);
    if (uVar2 <= uVar1) {
      local_2c = (float)(int)uVar2;
      if ((int)uVar2 < 0) {
        local_2c = local_2c + _DAT_0099d104;
      }
      fVar5 = (float)(int)uVar1;
      if ((int)uVar1 < 0) {
        fVar5 = fVar5 + _DAT_0099d104;
      }
      local_2c = local_2c / fVar5;
      iVar3 = *(int *)(in_ECX + 0x14);
      if (iVar3 == 1) {
        iVar3 = FUN_00802534();
        fVar5 = (float)(iVar3 << 0x18);
      }
      else if (iVar3 == 2) {
        fVar5 = -1.7014118e+38;
      }
      else {
        if (iVar3 != 3) {
          return;
        }
        iVar3 = FUN_00802534();
        fVar5 = (float)(iVar3 << 0x18);
        if (fVar5 == 0.0) {
          return;
        }
      }
      FUN_00401830(s_pan_maptitle_009d6bbc);
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_1c);
      if (0xf < uStack_8) {
        _free(local_1c[0]);
        return;
      }
      uStack_8 = 0xf;
      uStack_c = 0;
      local_1c[0] = (void *)((uint)local_1c[0] & 0xffffff00);
      if ((piVar4 != (int *)0x0) && (iVar3 = (**(code **)(*piVar4 + 0x30))(), iVar3 != 0)) {
        uStack_28 = *(undefined4 *)(iVar3 + 0x90);
        uStack_24 = *(undefined4 *)(iVar3 + 0x94);
        local_2c = fVar5;
        FUN_00587d40(&local_2c);
      }
    }
  }
  return;
}


// ==== FUN_00666010 @ 0x00666010 ====

void FUN_00666010(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int in_ECX;
  int unaff_retaddr;
  void *pvStack_58;
  uint uStack_54;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  uint uStack_44;
  undefined4 auStack_40 [2];
  int iStack_38;
  undefined4 uStack_34;
  int iStack_30;
  int iStack_2c;
  void *pvStack_20;
  uint uStack_c;
  
  iVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  iVar1 = *(int *)(iVar3 + 0x14);
  iVar2 = *(int *)(iVar3 + 0x1c);
  uStack_4c = *(undefined4 *)(iVar3 + 0x20);
  auStack_40[0] = 0xf;
  uStack_44 = 0;
  uStack_54 = *(uint *)(iVar3 + 0x18) & 0xffffff00;
  FUN_00401740(s_pan_maptitle_009d6bdc,0xc);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_58);
  if (0xf < uStack_44) {
    _free(pvStack_58);
    return;
  }
  uStack_44 = 0xf;
  uStack_48 = 0;
  pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
  uVar5 = (**(code **)(*piVar4 + 0x10))();
  FUN_005041e0(uVar5);
  iStack_38 = (iVar2 - iVar1) / 2 - (param_2 - unaff_retaddr) / 2;
  iStack_30 = (iStack_38 - unaff_retaddr) + param_2;
  iStack_2c = param_3 - param_1;
  uStack_34 = 0;
  (**(code **)(*piVar4 + 0xc))(auStack_40);
  if (uStack_c < 0x10) {
    return;
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_00666100 @ 0x00666100 ====

void FUN_00666100(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_24 [8];
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *(undefined4 *)(in_ECX + 0x14) = 0;
  local_2c = 0;
  local_28 = 0xffffffff;
  FUN_006667b0(local_24,&local_2c);
  local_2c = 1;
  local_28 = 3000;
  FUN_006667b0(local_24,&local_2c);
  local_2c = 2;
  local_28 = 5000;
  FUN_006667b0(local_24,&local_2c);
  local_2c = 3;
  local_28 = 8000;
  FUN_006667b0(local_24,&local_2c);
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_maptitlewnd_txt_009d6ba0,0x1b);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00666200 @ 0x00666200 ====

void FUN_00666200(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  
  in_ECX[6] = in_ECX[6] + *(int *)(param_1 + 4);
  uVar2 = in_ECX[6];
  piVar1 = in_ECX + 5;
  FUN_004d8980(&param_1,piVar1);
  if (param_1 != in_ECX[3]) {
    if (uVar2 <= *(uint *)(param_1 + 0x10)) {
      FUN_00665ed0();
      return;
    }
    iVar3 = *piVar1;
    if (2 < iVar3) {
      *piVar1 = 0;
      (**(code **)(*in_ECX + 0xc))(0);
      return;
    }
    if (iVar3 == 0) {
      *piVar1 = 1;
      in_ECX[6] = 0;
      return;
    }
    if (iVar3 == 1) {
      *piVar1 = 2;
      in_ECX[6] = 0;
      return;
    }
    if (iVar3 == 2) {
      *piVar1 = 3;
    }
    in_ECX[6] = 0;
  }
  return;
}


// ==== FUN_006662a0 @ 0x006662a0 ====

void FUN_006662a0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined1 auStack_2e [2];
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 auStack_24 [8];
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_maptitle_009d6bcc,0xc);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      uStack_2c = *(undefined4 *)(iVar2 + 0x8c);
      uStack_28 = *(undefined4 *)(iVar2 + 0x90);
      FUN_00587d40(&uStack_2c);
      puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a7c4 + 0xc))(auStack_24,auStack_2e + -10);
      FUN_00666010(*puVar3,puVar3[1],puVar3[2],puVar3[3]);
    }
  }
  return;
}


// ==== FUN_00666390 @ 0x00666390 ====

uint FUN_00666390(int *param_1)

{
  uint in_EAX;
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x24) == '\x01') &&
     (in_EAX = (**(code **)(*param_1 + 4))(), in_EAX == 0x40001)) {
    in_EAX = FUN_00666200(param_1);
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_006663c0 @ 0x006663c0 ====

void FUN_006663c0(void)

{
  undefined4 *in_ECX;
  undefined1 auStack_2 [2];
  
  *in_ECX = &PTR_FUN_009d6bf4;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  FUN_00666870(auStack_2 + -6,*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3]);
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00666410 @ 0x00666410 ====

void FUN_00666410(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d6bf4;
  iVar1 = FUN_006664f0();
  in_ECX[3] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  *(undefined4 *)in_ECX[3] = in_ECX[3];
  *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  in_ECX[4] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  in_ECX[1] = 0;
  FUN_00666100();
  return;
}


// ==== FUN_00666460 @ 0x00666460 ====

void * FUN_00666460(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c570;
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


// ==== Catch@006664d5 @ 0x006664d5 ====

void Catch_006664d5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_006664f0 @ 0x006664f0 ====

void FUN_006664f0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c580;
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


// ==== Catch@0066657a @ 0x0066657a ====

void Catch_0066657a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00666590 @ 0x00666590 ====

void FUN_00666590(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_00666590(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_006665d0 @ 0x006665d0 ====

void FUN_006665d0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_00666460(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_006666d5:
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
      if ((char)piVar6[5] == '\0') goto LAB_006666d5;
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


// ==== FUN_006667b0 @ 0x006667b0 ====

void FUN_006667b0(undefined4 *param_1,int *param_2)

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
      puVar5 = (undefined4 *)FUN_006665d0(&param_2,1,puVar5,piVar3);
      uVar1 = *puVar5;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *piVar3) {
    puVar5 = (undefined4 *)FUN_006665d0(&param_2,bVar2,puVar5,piVar3);
    *param_1 = *puVar5;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00666870 @ 0x00666870 ====

void FUN_00666870(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00666590(piVar6[1]);
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


// ==== FUN_00666930 @ 0x00666930 ====

undefined4 FUN_00666930(void)

{
  return 0x1f;
}


// ==== FUN_00666940 @ 0x00666940 ====

void FUN_00666940(byte param_1)

{
  void *in_ECX;
  
  FUN_006663c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006669a0 @ 0x006669a0 ====

void FUN_006669a0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d6d08;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_006669c0 @ 0x006669c0 ====

undefined4 FUN_006669c0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x20001) {
    if (param_1[1] == 9) {
      FUN_0065c550();
      return 1;
    }
    if (param_1[1] == 0xd) {
      FUN_0065cc80();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00666a20 @ 0x00666a20 ====

undefined1 FUN_00666a20(void)

{
  return 0;
}


// ==== FUN_00666a30 @ 0x00666a30 ====

void FUN_00666a30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d6da0;
  (**(code **)(*DAT_00b5a750 + 0xc))(0x7b);
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00666a60 @ 0x00666a60 ====

void FUN_00666a60(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
  (**(code **)(*piVar1 + 0x24))(param_1);
  if ((char)param_1 != '\0') {
    return;
  }
  piVar1 = (int *)(**(code **)(*DAT_00b5a74c + 0xc))(0x7b);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)(**(code **)(*DAT_00b5a750 + 8))(0x7b);
  }
                    /* WARNING: Could not recover jumptable at 0x00666aa4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0xc))(1);
  return;
}


// ==== FUN_00666ab0 @ 0x00666ab0 ====

uint FUN_00666ab0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  return uVar1 & 0xffffff00;
}


// ==== FUN_00666ac0 @ 0x00666ac0 ====

void FUN_00666ac0(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *in_ECX;
  int iVar5;
  void *unaff_EBX;
  undefined4 *puVar6;
  int iVar7;
  int unaff_retaddr;
  void *local_80;
  undefined1 auStack_7c [8];
  undefined4 uStack_74;
  uint uStack_70;
  uint uStack_6c;
  undefined4 uStack_68;
  undefined4 auStack_60 [4];
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int aiStack_44 [4];
  int iStack_34;
  int iStack_30;
  void *pvStack_28;
  void *pvStack_20;
  uint uStack_14;
  uint uStack_c;
  
  iVar2 = *(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xa0);
  local_80 = *(void **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x9c);
  puVar1 = (undefined4 *)(**(code **)(*(int *)in_ECX[1] + 0x14))();
  puVar6 = auStack_60;
  for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar6 = puVar6 + 1;
  }
  (**(code **)(*(int *)in_ECX[1] + 0x18))(auStack_60);
  if (in_ECX[1] == 0) {
    iVar5 = 0;
    iVar7 = 0;
  }
  else {
    iVar7 = (**(code **)(*(int *)in_ECX[1] + 0x14))();
    iVar5 = *(int *)(iVar7 + 0x14);
    iVar7 = *(int *)(iVar7 + 0x18);
  }
  if ((iVar5 <= unaff_retaddr) || (iVar7 <= param_1)) {
    iVar5 = (iVar2 - unaff_retaddr) - param_3;
    iVar2 = (int)unaff_EBX + (-param_2 - param_1);
    if (iVar5 < 0) {
      iVar5 = iVar5 + unaff_retaddr;
    }
    else {
      iVar5 = unaff_retaddr;
    }
    iVar7 = iVar2 + param_1;
    if (-1 < iVar2) {
      iVar7 = param_1;
    }
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    else if (iVar7 < 0) {
      iVar7 = 0;
    }
  }
  if (in_ECX[1] != 0) {
    iVar2 = (**(code **)(*in_ECX + 0x14))();
    if (iVar2 != 10) {
      iVar2 = (**(code **)(*in_ECX + 0x14))();
      if (iVar2 != 0x7b) {
        (**(code **)(*(int *)in_ECX[1] + 0x54))(iVar5,iVar7,1);
        goto LAB_00666ba9;
      }
    }
    (**(code **)(*(int *)in_ECX[1] + 0x54))(iVar5,iVar7,0);
  }
LAB_00666ba9:
  iStack_48 = param_3 + 6 + iStack_50;
  aiStack_44[0] = iStack_4c + 6 + param_2;
  uStack_68 = 0xf;
  uStack_6c = 0;
  auStack_7c[0] = 0;
  FUN_00401740(s_pan_back_009d6d64,8);
  piVar3 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(&local_80);
  if (0xf < uStack_6c) {
    _free(local_80);
    return;
  }
  uStack_6c = 0xf;
  uStack_70 = 0;
  local_80 = (void *)((uint)local_80 & 0xffffff00);
  if (piVar3 != (int *)0x0) {
    uVar4 = (**(code **)(*piVar3 + 0x10))();
    FUN_005041e0(uVar4);
    iStack_34 = param_2 + 6 + aiStack_44[2];
    iStack_30 = aiStack_44[3] + 6 + param_1;
    (**(code **)(*piVar3 + 0xc))(aiStack_44);
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return;
    }
  }
  uStack_6c = 0xf;
  uStack_70 = 0;
  local_80 = (void *)((uint)local_80 & 0xffffff00);
  FUN_00401740(s_pan_ppl_009d6d70,7);
  piVar3 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(auStack_60 + -9);
  if (0xf < uStack_70) {
    _free(unaff_EBX);
    return;
  }
  uStack_70 = 0xf;
  uStack_74 = 0;
  if (piVar3 != (int *)0x0) {
    uVar4 = (**(code **)(*piVar3 + 0x10))();
    FUN_005041e0(uVar4);
    aiStack_44[3] = param_1 + 3;
    iStack_34 = unaff_retaddr + 3;
    aiStack_44[1] = 3;
    aiStack_44[2] = 3;
    (**(code **)(*piVar3 + 0xc))(&iStack_48);
    if (0xf < uStack_14) {
      _free(pvStack_28);
      return;
    }
  }
  return;
}


// ==== FUN_00666d50 @ 0x00666d50 ====

void FUN_00666d50(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_pplwnd_txt_009d6d4c,0x16);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00666dd0 @ 0x00666dd0 ====

void FUN_00666dd0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00666ac0(param_1,param_2,param_4,param_3);
  return;
}


// ==== FUN_00666df0 @ 0x00666df0 ====

void FUN_00666df0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d6da0;
  in_ECX[1] = 0;
  FUN_00666d50();
  return;
}


// ==== FUN_00666e10 @ 0x00666e10 ====

undefined4 FUN_00666e10(void)

{
  return 0x7b;
}


// ==== FUN_00666e20 @ 0x00666e20 ====

void FUN_00666e20(void)

{
  undefined4 *in_ECX;
  uint unaff_ESI;
  
  *in_ECX = &PTR_FUN_009d6da0;
  (**(code **)(*DAT_00b5a750 + 0xc))(0x7b);
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_ESI & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00666e70 @ 0x00666e70 ====

void FUN_00666e70(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) == '\0') {
    *(undefined1 *)(in_ECX + 8) = 1;
  }
  return;
}


// ==== FUN_00666e80 @ 0x00666e80 ====

undefined1 FUN_00666e80(void)

{
  return 0;
}


// ==== FUN_00666e90 @ 0x00666e90 ====

undefined1 FUN_00666e90(void)

{
  return 0;
}


// ==== FUN_00666ea0 @ 0x00666ea0 ====

void FUN_00666ea0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d6e5c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00666ec0 @ 0x00666ec0 ====

void FUN_00666ec0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_tooltip_txt_009d6e0c,0x17);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00666f40 @ 0x00666f40 ====

void FUN_00666f40(uint param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                 undefined4 param_6,int param_7,undefined4 param_8,int param_9)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  int *in_ECX;
  int iVar6;
  void *unaff_EBX;
  uint *puVar7;
  int iVar8;
  undefined1 auStack_7e [2];
  void *local_7c;
  undefined1 local_78;
  uint auStack_74 [6];
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  undefined1 auStack_48 [8];
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  void *pvStack_30;
  int iStack_2c;
  undefined4 uStack_20;
  uint uStack_1c;
  void *apvStack_10 [4];
  
  auStack_74[4] = 0xf;
  auStack_74[3] = 0;
  local_78 = 0;
  FUN_00401740(s_pan_tooltip_009d6e40,0xb);
  piVar1 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(&local_7c);
  if (0xf < auStack_74[3]) {
    _free(local_7c);
    return;
  }
  auStack_74[3] = 0xf;
  auStack_74[2] = 0;
  local_7c = (void *)((uint)local_7c & 0xffffff00);
  uVar2 = (**(code **)(*piVar1 + 0x10))();
  FUN_005041e0(uVar2);
  pvStack_30 = (void *)(param_9 + 0x23 + iStack_38);
  iStack_2c = iStack_34 + 0xf + param_7;
  (**(code **)(*piVar1 + 0xc))(&iStack_40);
  auStack_74[2] = 0xf;
  auStack_74[1] = 0;
  FUN_00401740(s_textbox_009d6e4c,7);
  piVar1 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(auStack_7e + -6);
  if (0xf < auStack_74[1]) {
    _free(unaff_EBX);
    return;
  }
  auStack_74[1] = 0xf;
  auStack_74[0] = 0;
  piVar3 = (int *)(**(code **)(*piVar1 + 0x30))();
  uVar2 = (**(code **)(*piVar1 + 0x10))();
  FUN_004fed70(uVar2);
  iStack_38 = iStack_40 + 0x14 + param_9;
  iStack_34 = iStack_3c + param_5;
  (**(code **)(*piVar1 + 0xc))(auStack_48);
  iVar6 = *piVar3;
  uVar2 = (**(code **)(*piVar1 + 0x14))();
  (**(code **)(iVar6 + 0xc))(uVar2);
  FUN_005569f0(apvStack_10,0);
  puVar4 = (uint *)(**(code **)(*(int *)in_ECX[1] + 0x14))();
  puVar7 = auStack_74;
  for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar7 = puVar7 + 1;
  }
  iStack_58 = param_9 + 0x23 + auStack_74[5];
  iStack_54 = iStack_5c + 0xf + param_3;
  (**(code **)(*(int *)in_ECX[1] + 0x18))(auStack_74);
  if (in_ECX[1] == 0) {
    iVar8 = 0;
    iVar6 = 0;
LAB_006670f4:
    iVar6 = iVar6 + 0x1e;
    iVar8 = iVar8 + 0x14;
  }
  else {
    iVar8 = (**(code **)(*(int *)in_ECX[1] + 0x14))();
    iVar6 = *(int *)(iVar8 + 0x18);
    iVar8 = *(int *)(iVar8 + 0x14);
    if (iVar6 < 0x181) {
      if (iVar8 < 0x201) goto LAB_006670f4;
      iVar8 = iVar8 + (auStack_74[4] - iStack_5c);
    }
    else {
      iVar6 = iVar6 + (auStack_74[5] - iStack_58);
      if (0x200 < iVar8) {
        iVar8 = iVar8 + (auStack_74[4] - iStack_5c);
      }
    }
  }
  if (in_ECX[1] != 0) {
    iVar5 = (**(code **)(*in_ECX + 0x14))();
    if (iVar5 != 10) {
      iVar5 = (**(code **)(*in_ECX + 0x14))();
      if (iVar5 != 0x7b) {
        (**(code **)(*(int *)in_ECX[1] + 0x54))(iVar8,iVar6,1);
        goto LAB_00667186;
      }
    }
    (**(code **)(*(int *)in_ECX[1] + 0x54))(iVar8,iVar6,0);
  }
LAB_00667186:
  if (0xf < uStack_1c) {
    _free(pvStack_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
  if (param_1 < 0x10) {
    return;
  }
  _free(apvStack_10[0]);
  return;
}


// ==== FUN_006671e0 @ 0x006671e0 ====

void FUN_006671e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d6e5c;
  FUN_00666ec0();
  return;
}


// ==== FUN_00667200 @ 0x00667200 ====

/* WARNING: Removing unreachable block (ram,0x0066753e) */

void FUN_00667200(undefined4 param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  byte *****pppppbVar4;
  uint *puVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  char local_13c [4];
  uint local_138;
  int local_134;
  int local_130;
  uint local_12c;
  int local_128;
  undefined1 local_124 [4];
  uint *local_120;
  uint *local_11c;
  undefined4 local_118;
  undefined1 local_114 [4];
  int local_110;
  int local_10c;
  undefined4 local_108;
  undefined1 local_104 [4];
  byte *****local_100 [3];
  undefined4 uStack_f4;
  uint local_f0;
  uint local_ec;
  uint local_e8;
  undefined4 local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  undefined4 local_d0;
  undefined1 local_cc [4];
  void *local_c8;
  undefined4 local_b8;
  uint local_b4;
  undefined4 local_b0;
  int local_ac;
  byte *****local_a4 [4];
  int local_94;
  uint local_90;
  byte *****local_88 [4];
  uint local_78;
  uint local_74;
  undefined1 local_70 [4];
  void *local_6c;
  void *pvStack_60;
  undefined4 local_5c;
  uint local_58;
  undefined1 local_54 [4];
  uint local_50;
  uint uStack_4c;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 uStack_c;
  undefined4 local_8;
  uint local_4;
  
  local_138 = 0;
  local_110 = 0;
  local_10c = 0;
  local_108 = 0;
  local_b4 = 0xf;
  local_b8 = 0;
  local_c8 = (void *)((uint)local_c8 & 0xffffff00);
  FUN_00401740(&DAT_009d6e24,1);
  FUN_00405300(param_1,local_cc,local_114);
  if (0xf < local_b4) {
    _free(local_c8);
    return;
  }
  if (local_110 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (local_10c - local_110) / 0x1c;
  }
  local_ac = iVar3 * 0x10 + 10;
  local_dc = 0;
  local_d0 = 0;
  local_3c = 0xf;
  local_40 = 0;
  local_50 = local_50 & 0xffffff00;
  local_d4 = iVar3;
  FUN_00401740(&DAT_009d6e26,0);
  local_e8 = 0;
  if (0 < iVar3) {
    local_128 = 0;
    do {
      uVar2 = local_e8;
      if ((local_110 == 0) || ((uint)((local_10c - local_110) / 0x1c) <= local_e8)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      local_b4 = 0xf;
      local_b8 = 0;
      local_c8 = (void *)((uint)local_c8 & 0xffffff00);
      FUN_00401660(local_128 + local_110,0,0xffffffff);
      local_120 = (uint *)0x0;
      local_11c = (uint *)0x0;
      local_118 = 0;
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      FUN_00401740(&DAT_009d6e28,2);
      FUN_00405160(local_cc,local_1c,local_124);
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      if (local_120 == (uint *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = ((int)local_11c - (int)local_120) / 0x1c;
      }
      local_134 = 0;
      local_58 = 0xf;
      local_5c = 0;
      local_6c = (void *)((uint)local_6c & 0xffffff00);
      local_d8 = iVar3;
      FUN_00401740(&DAT_009d6e2b,0);
      local_12c = 0;
      if (0 < iVar3) {
        local_130 = 0;
        do {
          if ((local_120 == (uint *)0x0) ||
             ((uint)(((int)local_11c - (int)local_120) / 0x1c) <= local_12c)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          local_ec = 0xf;
          local_f0 = 0;
          local_100[0] = (byte *****)((uint)local_100[0] & 0xffffff00);
          FUN_00401660(local_130 + (int)local_120,0,0xffffffff);
          local_13c[0] = '=';
          iVar3 = FUN_00405850(local_13c,0,1);
          if (iVar3 == -1) {
            local_138 = local_138 | 1;
            local_90 = 0xf;
            local_94 = 0;
            local_a4[0] = (byte *****)((uint)local_a4[0] & 0xffffff00);
            FUN_00401660(local_104,0,1);
            if (local_94 != 0) {
              uVar2 = (uint)(local_94 != 0);
              pppppbVar4 = local_a4[0];
              if (local_90 < 0x10) {
                pppppbVar4 = (byte *****)local_a4;
              }
              bVar7 = false;
              iVar3 = 0;
              bVar8 = true;
              pbVar6 = &DAT_009d6e2c;
              do {
                if (uVar2 == 0) break;
                uVar2 = uVar2 - 1;
                bVar7 = *(byte *)pppppbVar4 < *pbVar6;
                bVar8 = *(byte *)pppppbVar4 == *pbVar6;
                pppppbVar4 = (byte *****)((int)pppppbVar4 + 1);
                pbVar6 = pbVar6 + 1;
              } while (bVar8);
              if (!bVar8) {
                iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
              }
              if (((iVar3 == 0) && (local_94 != 0)) && (local_94 == 1)) goto LAB_00667590;
            }
            if (local_f0 != 0) {
              uVar2 = local_f0;
              if (5 < local_f0) {
                uVar2 = 6;
              }
              pppppbVar4 = local_100[0];
              if (local_ec < 0x10) {
                pppppbVar4 = (byte *****)local_100;
              }
              bVar7 = false;
              iVar3 = 0;
              bVar8 = true;
              pbVar6 = (byte *)s_center_009d6e30;
              do {
                if (uVar2 == 0) break;
                uVar2 = uVar2 - 1;
                bVar7 = *(byte *)pppppbVar4 < *pbVar6;
                bVar8 = *(byte *)pppppbVar4 == *pbVar6;
                pppppbVar4 = (byte *****)((int)pppppbVar4 + 1);
                pbVar6 = pbVar6 + 1;
              } while (bVar8);
              if (!bVar8) {
                iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
              }
              if (((iVar3 == 0) && (5 < local_f0)) && (local_f0 == 6)) goto LAB_00667590;
            }
            local_13c[0] = '\x01';
          }
          else {
LAB_00667590:
            local_13c[0] = '\0';
          }
          if ((local_138 & 1) != 0) {
            local_138 = local_138 & 0xfffffffe;
            if (0xf < local_90) {
              _free(local_a4[0]);
              return;
            }
            local_90 = 0xf;
            local_94 = 0;
            local_a4[0] = (byte *****)((uint)local_a4[0] & 0xffffff00);
          }
          if (local_13c[0] == '\0') {
            local_74 = 0xf;
            local_78 = 0;
            local_88[0] = (byte *****)((uint)local_88[0] & 0xffffff00);
            FUN_00401660(local_104,0,3);
            if (local_78 == 0) {
LAB_00667678:
              uVar2 = 0xffffffff;
LAB_00667685:
              local_13c[0] = uVar2 == 0;
            }
            else {
              uVar2 = local_78;
              if (2 < local_78) {
                uVar2 = 3;
              }
              pppppbVar4 = local_88[0];
              if (local_74 < 0x10) {
                pppppbVar4 = (byte *****)local_88;
              }
              bVar7 = false;
              iVar3 = 0;
              bVar8 = true;
              pbVar6 = &DAT_009d6e38;
              do {
                if (uVar2 == 0) break;
                uVar2 = uVar2 - 1;
                bVar7 = *(byte *)pppppbVar4 < *pbVar6;
                bVar8 = *(byte *)pppppbVar4 == *pbVar6;
                pppppbVar4 = (byte *****)((int)pppppbVar4 + 1);
                pbVar6 = pbVar6 + 1;
              } while (bVar8);
              if (!bVar8) {
                iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
              }
              local_13c[0] = false;
              if (iVar3 == 0) {
                if (local_78 < 3) goto LAB_00667678;
                uVar2 = (uint)(local_78 != 3);
                goto LAB_00667685;
              }
            }
            if (0xf < local_74) {
              _free(local_88[0]);
              return;
            }
            local_74 = 0xf;
            local_78 = 0;
            local_88[0] = (byte *****)((uint)local_88[0] & 0xffffff00);
            if ((bool)local_13c[0] != false) {
              local_134 = 0;
              FUN_00401740(&DAT_009d6e3c,0);
              local_20 = 0xf;
              local_24 = 0;
              local_34 = (void *)((uint)local_34 & 0xffffff00);
              FUN_00401660(local_104,4,local_f0);
              local_d0 = thunk_FUN_00796fb0(local_38);
              if (0xf < local_20) {
                _free(local_34);
                return;
              }
              local_20 = 0xf;
              local_24 = 0;
              local_34 = (void *)((uint)local_34 & 0xffffff00);
            }
          }
          else {
            local_134 = local_134 + local_f0;
            FUN_00401ff0(local_104,0,0xffffffff);
          }
          if (0xf < local_ec) {
            _free(local_100[0]);
            return;
          }
          local_130 = local_130 + 0x1c;
          local_12c = local_12c + 1;
          local_ec = 0xf;
          local_f0 = 0;
          local_100[0] = (byte *****)((uint)local_100[0] & 0xffffff00);
        } while ((int)local_12c < local_d8);
        uVar2 = local_e8;
      }
      if (local_dc < local_134) {
        local_dc = local_134;
        FUN_00401660(local_70,0,0xffffffff);
      }
      if (0xf < local_58) {
        _free(local_6c);
        return;
      }
      local_58 = 0xf;
      local_5c = 0;
      local_6c = (void *)((uint)local_6c & 0xffffff00);
      if (local_120 != (uint *)0x0) {
        if (local_120 != local_11c) {
          puVar5 = local_120 + 6;
          do {
            if (0xf < *puVar5) {
              _free((void *)puVar5[-5]);
              return;
            }
            *puVar5 = 0xf;
            puVar5[-1] = 0;
            *(undefined1 *)(puVar5 + -5) = 0;
            puVar1 = puVar5 + 1;
            puVar5 = puVar5 + 7;
          } while (puVar1 != local_11c);
        }
        _free(local_120);
        return;
      }
      local_120 = (void *)0x0;
      local_11c = (uint *)0x0;
      local_118 = 0;
      if (0xf < local_b4) {
        _free(local_c8);
        return;
      }
      local_128 = local_128 + 0x1c;
      local_e8 = uVar2 + 1;
      local_b4 = 0xf;
      local_b8 = 0;
      local_c8 = (void *)((uint)local_c8 & 0xffffff00);
    } while ((int)local_e8 < local_d4);
  }
  local_e0 = 0;
  local_b0 = 0;
  (**(code **)(*DAT_00b5a688 + 0x34))(2,local_54,&local_e0,&local_b0);
  FUN_00401660(uStack_c,0,0xffffffff);
  FUN_00666f40();
  if (0xf < uStack_4c) {
    _free(pvStack_60);
    return;
  }
  uStack_4c = 0xf;
  local_50 = 0;
  pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
  if (local_120 == (void *)0x0) {
    return;
  }
  FUN_00405de0(local_120,local_11c,local_124,uStack_f4);
  _free(local_120);
  return;
}


// ==== FUN_00667970 @ 0x00667970 ====

void FUN_00667970(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d6e5c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006679b0 @ 0x006679b0 ====

void FUN_006679b0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) == '\0') {
    *(undefined1 *)(in_ECX + 8) = 1;
  }
  return;
}


// ==== FUN_006679f0 @ 0x006679f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_006679f0(uint param_1)

{
  float fVar1;
  float fVar2;
  uint in_EAX;
  uint uVar3;
  int in_ECX;
  uint uVar4;
  
  if (*(int *)(in_ECX + 0x50) != 0) {
    if (*(char *)(in_ECX + 0x44) == '\0') {
      in_EAX = *(int *)(in_ECX + 0x54) + param_1;
      *(undefined1 *)(in_ECX + 0x44) = 1;
      *(uint *)(in_ECX + 0x4c) = in_EAX;
    }
    else {
      uVar3 = *(uint *)(in_ECX + 0x4c);
      if (uVar3 < param_1) {
        return CONCAT31((int3)(uVar3 >> 8),1);
      }
      in_EAX = *(uint *)(in_ECX + 0x54);
      uVar4 = uVar3 - param_1;
      if (in_EAX < uVar3 - param_1) {
        uVar4 = in_EAX;
      }
      fVar1 = (float)(int)(in_EAX - uVar4);
      if ((int)(in_EAX - uVar4) < 0) {
        fVar1 = fVar1 + _DAT_0099d104;
      }
      fVar2 = (float)(int)in_EAX;
      if ((int)in_EAX < 0) {
        fVar2 = fVar2 + _DAT_0099d104;
      }
      *(float *)(in_ECX + 0x48) = fVar1 / fVar2;
      if (*(int *)(in_ECX + 0x50) != 0) {
        uVar3 = FUN_00587ba0((fVar1 / fVar2) * DAT_0099de78);
        return uVar3 & 0xffffff00;
      }
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_00667a90 @ 0x00667a90 ====

undefined4 FUN_00667a90(void *param_1)

{
  int *piVar1;
  undefined4 extraout_EAX;
  undefined4 uVar2;
  undefined4 extraout_EAX_00;
  int in_ECX;
  uint in_stack_00000018;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&param_1);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x30))();
    if (in_stack_00000018 < 0x10) {
      return uVar2;
    }
    _free(param_1);
    return extraout_EAX_00;
  }
  if (in_stack_00000018 < 0x10) {
    return 0;
  }
  _free(param_1);
  return extraout_EAX;
}


// ==== FUN_00667ae0 @ 0x00667ae0 ====

undefined4 FUN_00667ae0(void *param_1)

{
  int *piVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int iVar2;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  int in_ECX;
  undefined1 uStack00000000;
  uint in_stack_00000018;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_textbox_009d6ee4,7);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (piVar1 == (int *)0x0) {
    if (0xf < local_8) {
      _free(local_1c);
      return extraout_EAX;
    }
  }
  else {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x30))();
    if (0xf < local_8) {
      _free(local_1c);
      return extraout_EAX_00;
    }
    local_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x18))();
      if (iVar2 == 6) {
        FUN_005569f0(&uStack00000000,0);
        if (in_stack_00000018 < 0x10) {
          return 1;
        }
        _free(param_1);
        return extraout_EAX_03;
      }
      if (in_stack_00000018 < 0x10) {
        return 0;
      }
      _free(param_1);
      return extraout_EAX_02;
    }
  }
  if (in_stack_00000018 < 0x10) {
    return 0;
  }
  _free(param_1);
  return extraout_EAX_01;
}


// ==== FUN_00667be0 @ 0x00667be0 ====

undefined4 FUN_00667be0(void *param_1)

{
  int *piVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int iVar2;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  int in_ECX;
  undefined1 uStack00000000;
  uint in_stack_00000018;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_lbl_text_009d6eec,8);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (piVar1 == (int *)0x0) {
    if (0xf < local_8) {
      _free(local_1c);
      return extraout_EAX;
    }
  }
  else {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x30))();
    if (0xf < local_8) {
      _free(local_1c);
      return extraout_EAX_00;
    }
    local_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x18))();
      if (iVar2 == 8) {
        FUN_0055a260(&uStack00000000);
        if (in_stack_00000018 < 0x10) {
          return 1;
        }
        _free(param_1);
        return extraout_EAX_03;
      }
      if (in_stack_00000018 < 0x10) {
        return 0;
      }
      _free(param_1);
      return extraout_EAX_02;
    }
  }
  if (in_stack_00000018 < 0x10) {
    return 0;
  }
  _free(param_1);
  return extraout_EAX_01;
}


// ==== FUN_00667ce0 @ 0x00667ce0 ====

undefined4 FUN_00667ce0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined1 local_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar4 = *(int *)(in_ECX + 0x2c);
  iVar1 = *(int *)(in_ECX + 0x30);
  do {
    if (iVar4 == iVar1) {
      return CONCAT31((int3)((uint)iVar4 >> 8),1);
    }
    FUN_00401740(s_multilbl__d_009d6ef8,0xb);
    FUN_00404230(local_1c);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_1c);
    if (piVar2 == (int *)0x0) {
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return extraout_EAX;
      }
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    }
    else {
      piVar2 = (int *)(**(code **)(*piVar2 + 0x30))();
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return extraout_EAX_00;
      }
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x18))(), iVar3 == 8)) {
        FUN_0055a260(iVar4);
      }
    }
    iVar4 = iVar4 + 0x1c;
  } while( true );
}


// ==== FUN_00667dd0 @ 0x00667dd0 ====

uint FUN_00667dd0(void *param_1)

{
  int *piVar1;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint uVar2;
  uint extraout_EAX_02;
  uint extraout_EAX_03;
  int in_ECX;
  uint in_stack_00000018;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_edit_text_009d6f04,9);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (piVar1 == (int *)0x0) {
    if (0xf < local_8) {
      _free(local_1c);
      return extraout_EAX;
    }
  }
  else {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x30))();
    if (0xf < local_8) {
      _free(local_1c);
      return extraout_EAX_00;
    }
    local_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    if (piVar1 != (int *)0x0) {
      uVar2 = (**(code **)(*piVar1 + 0x18))();
      if (uVar2 == 2) {
        if (in_stack_00000018 < 0x10) {
          return 1;
        }
        _free(param_1);
        return extraout_EAX_03;
      }
      if (0xf < in_stack_00000018) {
        _free(param_1);
        return extraout_EAX_02;
      }
      goto LAB_00667e97;
    }
  }
  uVar2 = 0;
  if (0xf < in_stack_00000018) {
    _free(param_1);
    return extraout_EAX_01;
  }
LAB_00667e97:
  return uVar2 & 0xffffff00;
}


// ==== FUN_00667ec0 @ 0x00667ec0 ====

void FUN_00667ec0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  void *unaff_EBX;
  undefined4 local_1c;
  undefined1 local_18;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  *(undefined4 *)(in_ECX + 0x40) = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_lbl_text_009d6f10,8);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (piVar1 == (int *)0x0) {
    if (0xf < local_8) {
      _free(local_1c);
      return;
    }
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (0xf < local_8) {
      _free(local_1c);
      return;
    }
    if (iVar2 != 0) {
      *(undefined4 *)(in_ECX + 0x40) = 1;
      goto LAB_00667f98;
    }
  }
  FUN_00401740(s_textbox_009d6f1c,7);
  iVar2 = FUN_00667a90();
  if (iVar2 == 0) {
    FUN_00401740(s_multilbl_0_009d6f24,10);
    iVar2 = FUN_00667a90();
    if (iVar2 != 0) {
      *(undefined4 *)(in_ECX + 0x40) = 4;
    }
  }
  else {
    *(undefined4 *)(in_ECX + 0x40) = 2;
  }
LAB_00667f98:
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(s_edit_text_009d6f30,9);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x20);
  if (piVar1 == (int *)0x0) {
    if (0xf < uStack_c) {
      _free(unaff_EBX);
      return;
    }
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (0xf < uStack_c) {
      _free(unaff_EBX);
      return;
    }
    if (iVar2 != 0) {
      *(uint *)(in_ECX + 0x40) = *(uint *)(in_ECX + 0x40) | 8;
    }
  }
  return;
}


// ==== FUN_00668010 @ 0x00668010 ====

void FUN_00668010(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_processbar_009d6f3c,10);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      FUN_00587ba0(0);
      *(int *)(in_ECX + 0x50) = iVar2;
    }
  }
  return;
}


// ==== FUN_00668090 @ 0x00668090 ====

int FUN_00668090(int param_1)

{
  int *piVar1;
  int iVar2;
  int extraout_EAX;
  int extraout_EAX_00;
  int in_ECX;
  undefined1 local_3c [4];
  undefined1 local_38 [4];
  void *local_34 [4];
  undefined4 local_24;
  uint local_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = (void *)((uint)local_34[0] & 0xffffff00);
  FUN_004bdb30(local_3c,local_34,local_34);
  if ((*(byte *)(in_ECX + 0x40) & 2) != 0) {
    FUN_00401740(s_textbox_009d6f48,7);
    piVar1 = (int *)FUN_00667a90();
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x18))();
      if (iVar2 == 6) {
        uStack_4 = 0xf;
        uStack_8 = 0;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
        FUN_00401660(piVar1 + 0x32,0,0xffffffff);
        FUN_00401660(auStack_1c,0,0xffffffff);
        if (0xf < uStack_4) {
          _free(pvStack_18);
          return extraout_EAX;
        }
      }
    }
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_38,0,0xffffffff);
  if (local_20 < 0x10) {
    return param_1;
  }
  _free(local_34[0]);
  return extraout_EAX_00;
}


// ==== FUN_00668180 @ 0x00668180 ====

int FUN_00668180(int param_1)

{
  int *piVar1;
  int iVar2;
  int extraout_EAX;
  int in_ECX;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  void *local_18 [4];
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18[0] = (void *)((uint)local_18[0] & 0xffffff00);
  FUN_004bdb30(local_20,local_18,local_18);
  if ((*(byte *)(in_ECX + 0x40) & 8) != 0) {
    FUN_00401740(s_edit_text_009d6f50,9);
    piVar1 = (int *)FUN_00667a90();
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x18))();
      if (iVar2 == 2) {
        FUN_00550970(local_1c);
      }
    }
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_1c,0,0xffffffff);
  if (local_4 < 0x10) {
    return param_1;
  }
  _free(local_18[0]);
  return extraout_EAX;
}


// ==== FUN_00668240 @ 0x00668240 ====

/* WARNING: Removing unreachable block (ram,0x0066832b) */
/* WARNING: Removing unreachable block (ram,0x00668293) */

void FUN_00668240(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 unaff_retaddr;
  undefined1 auStack_48 [12];
  undefined4 uStack_3c;
  undefined1 *puStack_38;
  undefined4 uStack_34;
  undefined1 auStack_1a [26];
  
  if ((*(char *)(in_ECX + 9) != '\0') && (*(char *)(in_ECX + 10) != '\x01')) {
    uStack_34 = 0x66827d;
    FUN_00401740();
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x60))();
    }
    uStack_34 = 0x6682c2;
    puVar2 = operator_new(0x2c);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009d69f0;
      puVar2[7] = 0xf;
      puVar2[6] = 0;
      *(undefined1 *)(puVar2 + 2) = 0;
      *(undefined2 *)(puVar2 + 8) = 0;
      puVar2[9] = 0;
      puVar2[10] = 0;
    }
    puVar2[9] = *(undefined4 *)(in_ECX + 0x3c);
    *(undefined2 *)(puVar2 + 8) = *(undefined2 *)(in_ECX + 0x38);
    puVar2[10] = unaff_retaddr;
    if ((*(uint *)(in_ECX + 0x40) & 8) == 0) {
      if ((*(uint *)(in_ECX + 0x40) & 2) != 0) {
        FUN_00668090(auStack_48);
        FUN_00668890();
      }
    }
    else {
      uStack_34 = 0x668314;
      FUN_00668180();
      uStack_34 = 0;
      puStack_38 = auStack_1a + -6;
      uStack_3c = 0x668324;
      FUN_00401660();
    }
    uStack_34 = 0x668356;
    FUN_00797a20();
    *(undefined1 *)(in_ECX + 10) = 1;
  }
  return;
}


// ==== FUN_00668370 @ 0x00668370 ====

void FUN_00668370(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_btn_yes_009d6f68,7);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (piVar1 == (int *)0x0) {
    if (0xf < local_8) {
      _free(local_1c);
      return;
    }
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (0xf < local_8) {
      _free(local_1c);
      return;
    }
    if (iVar2 != 0) {
      FUN_00668240(1);
    }
  }
  return;
}


// ==== FUN_00668400 @ 0x00668400 ====

undefined4 FUN_00668400(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  if (param_1 == 1) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_yes_009d6f70,7);
    if (iVar2 == 0) {
      if (param_3 == 1) {
        FUN_00668240(1);
        return 1;
      }
    }
    else {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_no_009d6f78,6);
      if ((iVar2 != 0) && (cVar1 = FUN_004036a0(param_2,s_btn_exit_009d6f80), cVar1 == '\0')) {
        return 0;
      }
      if (param_3 == 1) {
        FUN_00668240(0);
        return 1;
      }
    }
  }
  else if (((param_1 == 2) && (param_3 == 4)) &&
          (cVar1 = FUN_004036a0(param_2,s_edit_text_009d6f8c), cVar1 != '\0')) {
    FUN_00668370();
  }
  return 0;
}


// ==== FUN_006684c0 @ 0x006684c0 ====

undefined1 FUN_006684c0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  FUN_00668240(0);
  return 1;
}


// ==== FUN_006684e0 @ 0x006684e0 ====

void FUN_006684e0(int param_1)

{
  char cVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 9) != '\0') {
    cVar1 = FUN_006679f0(*(undefined4 *)(param_1 + 0xc));
    if (cVar1 == '\x01') {
      FUN_00668240(1);
    }
  }
  return;
}


// ==== FUN_00668510 @ 0x00668510 ====

uint FUN_00668510(undefined1 param_1,void *param_2)

{
  uint in_EAX;
  uint extraout_EAX;
  uint uVar1;
  uint extraout_EAX_00;
  int in_ECX;
  uint in_stack_0000001c;
  
  if (*(char *)(in_ECX + 9) == '\0') {
    if (in_stack_0000001c < 0x10) {
      return in_EAX & 0xffffff00;
    }
    _free(param_2);
    return extraout_EAX;
  }
  FUN_00667ec0();
  FUN_00668010();
  uVar1 = *(uint *)(in_ECX + 0x40);
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 2) == 0) {
      if ((uVar1 & 4) != 0) {
        FUN_00667ce0();
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      if (uVar1 == 8) {
        FUN_00765c50(&param_1);
        FUN_00667dd0();
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    FUN_00401660(&param_1,0,0xffffffff);
    uVar1 = FUN_00667ae0();
  }
  else {
    FUN_00401660(&param_1,0,0xffffffff);
    uVar1 = FUN_00667be0();
  }
  if (in_stack_0000001c < 0x10) {
    return uVar1;
  }
  _free(param_2);
  return extraout_EAX_00;
}


// ==== FUN_00668620 @ 0x00668620 ====

uint FUN_00668620(int *param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if ((uVar1 == 0x40001) && (*(char *)(in_ECX + 9) != '\0')) {
    uVar1 = FUN_006679f0(param_1[3]);
    if ((char)uVar1 == '\x01') {
      uVar1 = FUN_00668240(1);
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00668660 @ 0x00668660 ====

void FUN_00668660(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d6fa0;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  *(undefined2 *)(in_ECX + 0xe) = 0;
  in_ECX[0xf] = 0;
  *(undefined1 *)((int)in_ECX + 10) = 0;
  *(undefined1 *)((int)in_ECX + 9) = 0;
  in_ECX[0x10] = 0;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_006686a0 @ 0x006686a0 ====

void FUN_006686a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d6fa0;
  if (*(char *)((int)in_ECX + 9) != '\0') {
    *(undefined1 *)((int)in_ECX + 9) = 0;
    (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
    (**(code **)(*DAT_00b5a9e0 + 0x20))(0);
  }
  if (in_ECX[0xb] != 0) {
    FUN_00405de0(in_ECX[0xb],in_ECX[0xc],in_ECX + 10,in_ECX);
    _free((void *)in_ECX[0xb]);
    return;
  }
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  if ((uint)in_ECX[9] < 0x10) {
    in_ECX[8] = 0;
    in_ECX[9] = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_00668730 @ 0x00668730 ====

void FUN_00668730(int param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined4 uStack_38;
  void *pvStack_28;
  uint uStack_24;
  undefined1 auStack_20 [12];
  uint uStack_14;
  
  if ((*(char *)(in_ECX + 9) != '\x01') && (param_1 != 0)) {
    *(undefined1 *)(in_ECX + 9) = 1;
    *(undefined1 *)(in_ECX + 0x44) = 0;
    *(undefined4 *)(in_ECX + 0x48) = 0;
    *(undefined4 *)(in_ECX + 0x4c) = 0;
    *(undefined4 *)(in_ECX + 0x50) = 0;
    (**(code **)(*DAT_00b5a9e0 + 0x20))(1);
    FUN_004022a0(auStack_20,s_UI_Game2_MsgBox__009d6ec8,param_1 + 4);
    iVar2 = FUN_00410500(auStack_20);
    if (iVar2 == 0) {
      FUN_00401830(&DAT_009d6edc);
      FUN_00406880(auStack_20 + -0x1c);
      if (uStack_24 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(uStack_38);
      return;
    }
    piVar3 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar2 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar3;
    (**(code **)(*piVar3 + 0x40))();
    *(undefined2 *)(in_ECX + 0x38) = *(undefined2 *)(param_1 + 0x4c);
    *(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)(param_1 + 0x50);
    *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0x54);
    FUN_00406600(param_1 + 0x3c);
    FUN_0043b3d0(auStack_20 + -0x28);
    FUN_00406250();
    FUN_00401660(param_1 + 0x20,0,0xffffffff);
    FUN_00668510();
    if (0xf < uStack_14) {
      _free(pvStack_28);
      return;
    }
  }
  return;
}


// ==== FUN_00668860 @ 0x00668860 ====

int FUN_00668860(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(in_ECX + 200,0,0xffffffff);
  return param_1;
}


// ==== FUN_00668890 @ 0x00668890 ====

void FUN_00668890(undefined1 param_1,void *param_2)

{
  uint in_stack_0000001c;
  
  FUN_00401660(&param_1,0,0xffffffff);
  if (in_stack_0000001c < 0x10) {
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_006688c0 @ 0x006688c0 ====

void FUN_006688c0(byte param_1)

{
  void *in_ECX;
  
  FUN_006686a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006688e0 @ 0x006688e0 ====

void FUN_006688e0(void)

{
  return;
}


// ==== FUN_006688f0 @ 0x006688f0 ====

void FUN_006688f0(float param_1,float param_2)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  (**(code **)(*piVar1 + 0x30))();
  if (param_1 < DAT_009d70cc) {
    FUN_00587ba0(0);
    return;
  }
  FUN_00587ba0((param_2 / param_1) * DAT_0099de78);
  return;
}


// ==== FUN_00668950 @ 0x00668950 ====

void FUN_00668950(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d70d8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00668970 @ 0x00668970 ====

void FUN_00668970(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_24 [4];
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  puVar3 = auStack_24;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar2 = (**(code **)(*DAT_00b5a74c + 0xc))(0x48);
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0xc) = uStack_14;
    *(undefined4 *)(iVar2 + 0x10) = uStack_10;
    *(undefined4 *)(iVar2 + 0x14) = uStack_c;
    *(undefined4 *)(iVar2 + 0x18) = uStack_8;
    FUN_006c9b00();
  }
  return;
}


// ==== FUN_00668a00 @ 0x00668a00 ====

void FUN_00668a00(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uStack_10;
  
  uVar3 = (**(code **)(*DAT_00b5a97c + 0xc))();
  piVar4 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar5 = (undefined4 *)(**(code **)(*piVar4 + 0x28))();
  uVar1 = *puVar5;
  uVar2 = puVar5[1];
  puVar5 = operator_new(0x18);
  if (puVar5 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  puVar5[1] = 1;
  puVar5[2] = uStack_10;
  puVar5[3] = uVar3;
  puVar5[4] = uVar1;
  *puVar5 = &PTR_FUN_009b62fc;
  puVar5[5] = uVar2;
  FUN_00797a20(puVar5);
  return;
}


// ==== FUN_00668a80 @ 0x00668a80 ====

undefined4 FUN_00668a80(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  if ((param_1 != 3) || (param_3 != 1)) {
    return 0;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),&DAT_009d70bc,2);
  if ((iVar2 == 0) ||
     ((cVar1 = FUN_004036a0(param_2,&DAT_009d70c0), cVar1 != '\0' ||
      (cVar1 = FUN_004036a0(param_2,s_shield_009d70c4), cVar1 != '\0')))) {
    FUN_00668a00();
    return 1;
  }
  return 0;
}


// ==== FUN_00668af0 @ 0x00668af0 ====

undefined4 FUN_00668af0(void)

{
  int *piVar1;
  undefined4 extraout_EAX;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int *unaff_retaddr;
  undefined1 auStack_22 [6];
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_bg_009d7044,6);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return extraout_EAX;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 4))();
    iVar3 = (**(code **)(*unaff_retaddr + 0x10))();
    if (iVar3 == iVar2) {
      (**(code **)(**(int **)(in_ECX + 4) + 0x1c))(unaff_retaddr);
      FUN_00668970();
      iVar2 = (**(code **)(*DAT_00b5a74c + 0xc))(0x47);
      if (iVar2 != 0) {
        iVar2 = *DAT_00b5ad54;
        uVar4 = FUN_0065deb0(auStack_22 + -0xe);
        (**(code **)(iVar2 + 0x30))(uVar4);
      }
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00668bc0 @ 0x00668bc0 ====

void FUN_00668bc0(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int in_ECX;
  float unaff_EDI;
  float fVar5;
  float local_24;
  void *pvStack_1c;
  undefined1 uStack_18;
  uint uStack_8;
  undefined4 uStack_4;
  
  local_24 = 0.0;
  cVar1 = (**(code **)(*DAT_00b5ac1c + 0x24))();
  if (cVar1 == '\x01') {
    iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar2 == 0) {
      return;
    }
    iVar2 = **(int **)(iVar2 + 0x50);
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    piVar4 = (int *)(**(code **)(iVar2 + 0x14))(uVar3);
    (**(code **)(*piVar4 + 0x18))();
    iVar2 = (**(code **)(*piVar4 + 0x18))();
    local_24 = *(float *)(iVar2 + 0x14);
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  FUN_00401740(s_shield_009d704c,6);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1c);
  (**(code **)(*piVar4 + 0x30))();
  if (DAT_009d70cc <= unaff_EDI) {
    fVar5 = (local_24 / unaff_EDI) * DAT_0099de78;
  }
  else {
    fVar5 = 0.0;
  }
  FUN_00587ba0(fVar5);
  if (uStack_8 < 0x10) {
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_00668cc0 @ 0x00668cc0 ====

void FUN_00668cc0(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  int in_ECX;
  void *apvStack_3c [4];
  undefined4 uStack_2c;
  uint uStack_28;
  undefined1 auStack_24 [4];
  void *apvStack_20 [5];
  uint uStack_c;
  
  iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x50) != (int *)0x0)) {
    iVar1 = **(int **)(iVar1 + 0x50);
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    piVar3 = (int *)(**(code **)(iVar1 + 0x14))(uVar2);
    if (piVar3 != (int *)0x0) {
      FUN_00401830(s_lbl_hp_009d705c);
      (**(code **)(*piVar3 + 0x18))();
      (**(code **)(*piVar3 + 0x18))();
      FUN_00401830(s__d____d_009d7054);
      uVar2 = FUN_00404230(apvStack_3c);
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_20);
      if (piVar4 != (int *)0x0) {
        iVar1 = (**(code **)(*piVar4 + 0x30))();
        if (iVar1 != 0) {
          FUN_0055a260(uVar2);
        }
      }
      if (0xf < uStack_28) {
        _free(apvStack_3c[0]);
        return;
      }
      uStack_28 = 0xf;
      uStack_2c = 0;
      apvStack_3c[0] = (void *)((uint)apvStack_3c[0] & 0xffffff00);
      if (0xf < uStack_c) {
        _free(apvStack_20[0]);
        return;
      }
      FUN_00401830(&DAT_009d7064);
      puVar5 = (undefined4 *)(**(code **)(*piVar3 + 0x18))();
      uVar2 = *puVar5;
      iVar1 = (**(code **)(*piVar3 + 0x18))(uVar2);
      FUN_006688f0(auStack_24,*(undefined4 *)(iVar1 + 0xc),uVar2);
      if (0xf < uStack_c) {
        _free(apvStack_20[0]);
        return;
      }
    }
  }
  return;
}


// ==== FUN_00668e40 @ 0x00668e40 ====

void FUN_00668e40(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int in_ECX;
  void *apvStack_3c [4];
  undefined4 uStack_2c;
  uint uStack_28;
  undefined1 auStack_24 [4];
  void *apvStack_20 [5];
  uint uStack_c;
  
  iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x50) != (int *)0x0)) {
    iVar1 = **(int **)(iVar1 + 0x50);
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    piVar3 = (int *)(**(code **)(iVar1 + 0x14))(uVar2);
    if (piVar3 != (int *)0x0) {
      FUN_00401830(s_lbl_mp_009d7070);
      iVar1 = (**(code **)(*piVar3 + 0x18))();
      (**(code **)(*piVar3 + 0x18))((int)ROUND(*(float *)(iVar1 + 0x10)));
      FUN_00401830(s__d____d_009d7068);
      uVar2 = FUN_00404230(apvStack_3c);
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_20);
      if (piVar4 != (int *)0x0) {
        iVar1 = (**(code **)(*piVar4 + 0x30))();
        if (iVar1 != 0) {
          FUN_0055a260(uVar2);
        }
      }
      if (0xf < uStack_28) {
        _free(apvStack_3c[0]);
        return;
      }
      uStack_28 = 0xf;
      uStack_2c = 0;
      apvStack_3c[0] = (void *)((uint)apvStack_3c[0] & 0xffffff00);
      if (0xf < uStack_c) {
        _free(apvStack_20[0]);
        return;
      }
      FUN_00401830(&DAT_009d7078);
      iVar1 = (**(code **)(*piVar3 + 0x18))();
      uVar2 = *(undefined4 *)(iVar1 + 4);
      iVar1 = (**(code **)(*piVar3 + 0x18))(uVar2);
      FUN_006688f0(auStack_24,*(undefined4 *)(iVar1 + 0x10),uVar2);
      if (0xf < uStack_c) {
        _free(apvStack_20[0]);
        return;
      }
    }
  }
  return;
}


// ==== FUN_00668fc0 @ 0x00668fc0 ====

void FUN_00668fc0(void)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  char *pcVar6;
  undefined1 auStack_42 [6];
  void *pvStack_3c;
  void *pvStack_38;
  undefined1 uStack_34;
  undefined4 uStack_2c;
  uint uStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  void *pvStack_1c;
  undefined1 uStack_18;
  uint uStack_8;
  undefined4 uStack_4;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5ac1c + 0x14))();
  if (piVar2 != (int *)0x0) {
    pcVar3 = (char *)(**(code **)(*piVar2 + 0x70))();
    uStack_4 = 0xf;
    uStack_8 = 0;
    uStack_18 = 0;
    pcVar6 = pcVar3;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(pcVar3,(int)pcVar6 - (int)(pcVar3 + 1));
    uStack_20 = 0xf;
    uStack_24 = 0;
    uStack_34 = 0;
    FUN_00401740(s_lbl_pcname_009d707c,10);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_38);
    if ((piVar4 != (int *)0x0) && (iVar5 = (**(code **)(*piVar4 + 0x30))(), iVar5 != 0)) {
      FUN_0055a260(&uStack_20);
    }
    if (0xf < uStack_24) {
      _free(pvStack_38);
      return;
    }
    uStack_24 = 0xf;
    uStack_28 = 0;
    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    if (((int *)piVar2[1] != (int *)0x0) &&
       (piVar2 = (int *)(**(code **)(*(int *)piVar2[1] + 0x18))(), piVar2 != (int *)0x0)) {
      uStack_24 = 0xf;
      uStack_28 = 0;
      pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
      FUN_00401740(s_pan_class_009d7088,9);
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_3c);
      if (0xf < uStack_28) {
        _free(pvStack_3c);
        return;
      }
      uStack_28 = 0xf;
      uStack_2c = 0;
      pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
      if ((piVar4 != (int *)0x0) && (iVar5 = (**(code **)(*piVar4 + 0x30))(), iVar5 != 0)) {
        (**(code **)(*piVar2 + 8))();
        FUN_00587d40(auStack_42 + -10);
      }
    }
  }
  return;
}


// ==== FUN_00669160 @ 0x00669160 ====

void FUN_00669160(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  void *pvStack_38;
  undefined1 uStack_34;
  uint uStack_24;
  undefined4 uStack_20;
  void *apvStack_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if (iVar1 != 0) {
    piVar2 = *(int **)(iVar1 + 0x48);
    uStack_20 = 0xf;
    uStack_24 = 0;
    uStack_34 = 0;
    FUN_00401740(s_lbl_pclevel_009d709c,0xb);
    piVar2 = (int *)(**(code **)(*piVar2 + 0x24))();
    (**(code **)(*piVar2 + 8))();
    FUN_00401740(s_Lv__d_009d7094,5);
    uVar3 = FUN_00404230(apvStack_1c);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_38);
    if (piVar2 != (int *)0x0) {
      iVar1 = (**(code **)(*piVar2 + 0x30))();
      if (iVar1 != 0) {
        FUN_0055a260(uVar3);
      }
    }
    if (0xf < uStack_8) {
      _free(apvStack_1c[0]);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
    if (0xf < uStack_24) {
      _free(pvStack_38);
      return;
    }
  }
  return;
}


// ==== FUN_00669250 @ 0x00669250 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00669250(void)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  void *pvStack_3c;
  undefined1 uStack_38;
  uint uStack_28;
  undefined4 uStack_24;
  void *apvStack_20 [4];
  undefined4 uStack_10;
  uint uStack_c;
  
  iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if (iVar1 != 0) {
    piVar5 = *(int **)(iVar1 + 0x48);
    piVar2 = (int *)(**(code **)(*piVar5 + 0x24))();
    puVar3 = (undefined2 *)(**(code **)(*piVar2 + 8))();
    piVar2 = (int *)(**(code **)(*DAT_00b5abb0 + 8))(*puVar3);
    (**(code **)(*piVar5 + 0x14))();
    (**(code **)(*piVar2 + 4))();
    uStack_24 = 0xf;
    uStack_28 = 0;
    uStack_38 = 0;
    FUN_00401740(s_lbl_exp_009d70b4,7);
    FUN_00401740(s_EXP__d___009d70a8,8);
    uVar4 = FUN_00404230(apvStack_20);
    piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_3c);
    if ((piVar5 != (int *)0x0) && (iVar1 = (**(code **)(*piVar5 + 0x30))(), iVar1 != 0)) {
      FUN_0055a260(uVar4);
    }
    if (0xf < uStack_c) {
      _free(apvStack_20[0]);
      return;
    }
    uStack_c = 0xf;
    uStack_10 = 0;
    apvStack_20[0] = (void *)((uint)apvStack_20[0] & 0xffffff00);
    if (0xf < uStack_28) {
      _free(pvStack_3c);
      return;
    }
  }
  return;
}


// ==== FUN_006693a0 @ 0x006693a0 ====

void FUN_006693a0(void)

{
  FUN_00668cc0();
  FUN_00668e40();
  FUN_00669250();
  FUN_00668bc0();
  FUN_00669160();
  FUN_00668fc0();
  return;
}


// ==== FUN_006693d0 @ 0x006693d0 ====

void FUN_006693d0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_Mainbar_ui_hpwnd_txt_009d700c,0x1d);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_00668cc0();
    FUN_00668e40();
    FUN_00669250();
    FUN_00668bc0();
    FUN_00669160();
    FUN_00668fc0();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00669470 @ 0x00669470 ====

undefined4 FUN_00669470(int *param_1)

{
  char cVar1;
  uint uVar2;
  undefined1 auStack_1c [28];
  
  uVar2 = (**(code **)(*param_1 + 4))();
  if (uVar2 < 0x70050004) {
    if (uVar2 == 0x70050003) {
      FUN_00668cc0();
      return 1;
    }
    if (uVar2 == 0x10003) {
      cVar1 = FUN_00668af0(param_1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
    else {
      if (uVar2 == 0x40001) {
        if (DAT_00b5a97c == 0) {
          FUN_00401830(s_User_Available_FALSE_009d702c);
          FUN_00796d50(auStack_1c);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        FUN_00668cc0();
        FUN_00668e40();
        FUN_00669250();
        FUN_00668bc0();
        FUN_00669160();
        return 0;
      }
      if (uVar2 == 0x70050002) {
        FUN_006693a0();
        *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 4;
        if ((char)param_1[1] == '\x0f') {
          return 1;
        }
      }
    }
  }
  else {
    if (uVar2 == 0x70050004) {
      FUN_00668e40();
      return 1;
    }
    if (uVar2 == 0x70050005) {
      FUN_00669250();
      return 1;
    }
    if (uVar2 == 0x70050009) {
      FUN_00668bc0();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006695b0 @ 0x006695b0 ====

void FUN_006695b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d70d8;
  in_ECX[1] = 0;
  FUN_006693d0();
  return;
}


// ==== FUN_006695d0 @ 0x006695d0 ====

undefined4 FUN_006695d0(void)

{
  return 0x47;
}


// ==== FUN_006695e0 @ 0x006695e0 ====

void FUN_006695e0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d70d8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00669620 @ 0x00669620 ====

void FUN_00669620(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7214;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00669640 @ 0x00669640 ====

void FUN_00669640(void)

{
  return;
}


// ==== FUN_00669650 @ 0x00669650 ====

undefined1 FUN_00669650(void)

{
  return 0;
}


// ==== FUN_00669660 @ 0x00669660 ====

undefined1 FUN_00669660(void)

{
  return 0;
}


// ==== FUN_00669670 @ 0x00669670 ====

void FUN_00669670(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7228;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b0c0 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5b0c0 = in_ECX;
  }
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  (**(code **)(*DAT_00b5a750 + 8))(0x58);
  return;
}


// ==== FUN_006696b0 @ 0x006696b0 ====

void FUN_006696b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d723c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006696d0 @ 0x006696d0 ====

undefined4 FUN_006696d0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  if (param_1 != iVar1) {
    return 0;
  }
  iVar1 = (**(code **)(*DAT_00b5b0c0 + 8))();
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = (**(code **)(*DAT_00b5b0c0 + 8))();
  if (param_3 == 1) {
    if (iVar1 != 1) {
      iVar1 = (**(code **)(*DAT_00b5b0c0 + 8))();
      if (iVar1 == 2) {
        piVar2 = (int *)(**(code **)(*DAT_00b5ad98 + 8))();
        iVar1 = (**(code **)(*piVar2 + 0xc))();
        if (iVar1 == 3) {
          FUN_006ed290();
          (**(code **)(*DAT_00b5b0c0 + 0xc))(0);
          return 1;
        }
        return 1;
      }
LAB_006697cb:
      (**(code **)(*DAT_00b5b0c0 + 0xc))(0);
      return 1;
    }
  }
  else if (iVar1 != 1) {
    iVar1 = (**(code **)(*DAT_00b5b0c0 + 8))();
    if (iVar1 == 2) {
      piVar2 = (int *)(**(code **)(*DAT_00b5ad98 + 8))();
      iVar1 = (**(code **)(*piVar2 + 0xc))();
      if (iVar1 != 3) {
        return 1;
      }
      FUN_006ed370();
      iVar1 = *DAT_00b5ad98;
      uVar3 = FUN_006ea910();
      (**(code **)(iVar1 + 4))(uVar3);
    }
    goto LAB_006697cb;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5ad98 + 8))();
  iVar1 = (**(code **)(*piVar2 + 0xc))();
  if (iVar1 == 2) {
    FUN_006ed7c0();
    (**(code **)(*DAT_00b5b0c0 + 0xc))(0);
    return 1;
  }
  return 1;
}


// ==== FUN_006697e0 @ 0x006697e0 ====

void FUN_006697e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7228;
  if (DAT_00b5a750 != (int *)0x0) {
    (**(code **)(*DAT_00b5a750 + 0xc))(0x58);
  }
  DAT_00b5b0c0 = 0;
  *in_ECX = &PTR_FUN_009d7214;
  return;
}


// ==== FUN_00669810 @ 0x00669810 ====

void FUN_00669810(void)

{
  ushort uVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int in_ECX;
  int unaff_retaddr;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_back_009d7200,8);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar2 != (int *)0x0) {
    uVar1 = *(ushort *)(unaff_retaddr + 4);
    puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      uVar4 = (**(code **)(*piVar2 + 4))();
      *puVar3 = &PTR_FUN_009bba08;
      puVar3[1] = uVar4;
      puVar3[3] = 1;
      puVar3[5] = 0;
      *(undefined1 *)(puVar3 + 6) = 0;
    }
    *(undefined1 *)((int)puVar3 + 0x19) = 1;
    puVar3[2] = (uint)uVar1;
    puVar3[3] = *(undefined4 *)(unaff_retaddr + 8);
    puVar3[4] = *(undefined4 *)(unaff_retaddr + 0xc);
    *(undefined1 *)(puVar3 + 6) = 1;
    (**(code **)(*DAT_00b5ad24 + 4))(puVar3);
    (**(code **)*puVar3)(1);
  }
  return;
}


// ==== FUN_006698f0 @ 0x006698f0 ====

void FUN_006698f0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_PVPBattleWnd_ui_basewnd_009d71d8,0x24);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00669970 @ 0x00669970 ====

undefined4 FUN_00669970(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70430009) {
    FUN_00669810(param_1);
    return 1;
  }
  return 0;
}


// ==== FUN_006699a0 @ 0x006699a0 ====

void FUN_006699a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d723c;
  FUN_006698f0();
  return;
}


// ==== FUN_006699c0 @ 0x006699c0 ====

void FUN_006699c0(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  ushort uVar2;
  undefined4 *puVar3;
  ushort uVar4;
  int in_ECX;
  undefined1 local_10 [4];
  void *local_c;
  undefined4 local_8;
  
  puVar3 = operator_new(0x58);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = &PTR_FUN_009b5340;
    puVar3[6] = 0;
    puVar3[7] = 0xf;
    *(undefined1 *)(puVar3 + 2) = 0;
    puVar3[0xe] = 0xf;
    puVar3[0xd] = 0;
    *(undefined1 *)(puVar3 + 9) = 0;
    puVar3[0x10] = 0;
    puVar3[0x11] = 0;
    puVar3[0x12] = 0;
    *(undefined2 *)(puVar3 + 0x13) = 0;
    puVar3[0x14] = 0;
    puVar3[0x15] = 10000;
  }
  puVar3[0x14] = 0x58;
  FUN_00401660(param_1,0,0xffffffff);
  if (*(int *)(param_2 + 0x14) != 0) {
    FUN_00401660(param_2,0,0xffffffff);
  }
  if (param_4 != 0) {
    puVar3[0x15] = param_4;
  }
  if (*(int *)(param_3 + 4) != 0) {
    iVar1 = (*(int *)(param_3 + 8) - *(int *)(param_3 + 4)) / 0x1c;
    if (iVar1 != 0) {
      FUN_00406600(param_3);
      FUN_0043b3d0(local_10);
      if (local_c != (void *)0x0) {
        FUN_00405de0(local_c,local_8,local_10,iVar1);
        _free(local_c);
        return;
      }
    }
  }
  uVar2 = *(ushort *)(in_ECX + 4);
  uVar4 = *(ushort *)(in_ECX + 8);
  if (0xff < uVar2) {
    uVar2 = 0xff;
  }
  if (0xff < uVar4) {
    uVar4 = 0xff;
  }
  *(ushort *)(puVar3 + 0x13) = uVar4 << 8 | uVar2;
  FUN_00797a20(puVar3);
  return;
}


// ==== FUN_00669af0 @ 0x00669af0 ====

undefined4 FUN_00669af0(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 uVar6;
  undefined2 extraout_var_02;
  int iVar7;
  undefined1 *puVar8;
  undefined4 uVar9;
  undefined1 auStack_210 [4];
  undefined4 uStack_20c;
  undefined4 uStack_208;
  undefined4 uStack_204;
  undefined1 auStack_200 [4];
  undefined4 uStack_1fc;
  undefined4 uStack_1f8;
  int iStack_1f4;
  undefined1 uStack_1e8;
  undefined4 uStack_1d8;
  undefined4 uStack_1d4;
  undefined1 uStack_1cc;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  undefined1 auStack_1b4 [40];
  undefined1 auStack_18c [32];
  undefined1 auStack_16c [28];
  undefined1 auStack_150 [28];
  undefined1 auStack_134 [28];
  undefined1 auStack_118 [28];
  undefined1 auStack_fc [28];
  undefined1 auStack_e0 [24];
  undefined1 auStack_c8 [60];
  undefined1 auStack_8c [52];
  undefined1 auStack_58 [88];
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 < 0x7091000a) {
    if (uVar1 == 0x70910009) {
      (**(code **)(*DAT_00b5a750 + 8))(0x65);
      return 1;
    }
    if (uVar1 < 0x70430008) {
      if (uVar1 == 0x70430007) {
        (**(code **)(*DAT_00b5a750 + 0xc))(0x5a);
        return 1;
      }
      if (uVar1 < 0x70430003) {
        if (uVar1 == 0x70430002) {
          pvVar3 = operator_new(0x2c);
          if (pvVar3 == (void *)0x0) {
            iVar4 = 0;
            uVar6 = extraout_var_00;
          }
          else {
            iVar4 = FUN_00663a10();
            uVar6 = extraout_var_01;
          }
          FUN_0065dd80(*(undefined2 *)(in_ECX + 8),CONCAT22(uVar6,*(undefined2 *)(in_ECX + 4)));
          *(undefined4 *)(iVar4 + 0x28) = 0;
          FUN_00797a20(iVar4);
          *(undefined4 *)(in_ECX + 4) = 0;
          *(undefined4 *)(in_ECX + 8) = 0;
          return 1;
        }
        if (uVar1 < 0x70430001) {
          if (uVar1 == 0x70430000) {
            *(undefined4 *)(in_ECX + 4) = 1;
            *(undefined4 *)(in_ECX + 8) = 0x23;
            uStack_20c = 0;
            uStack_208 = 0;
            uStack_204 = 0;
            FUN_00406250();
            FUN_00401830(&DAT_009d7142);
            FUN_00401830(s_ui_pvpacceptwait_txt_009d7144);
            FUN_006699c0(auStack_118,auStack_16c,auStack_210,10000);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          if (uVar1 == 0x70020003) {
            (**(code **)(*DAT_00b5a750 + 8))(0x8a);
            iVar4 = param_1[8];
            iVar7 = param_1[9];
            uVar2 = FUN_005523a0(auStack_c8);
            FUN_00678380(uVar2,iVar4,iVar7);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          if (uVar1 == 0x70020004) {
            (**(code **)(*DAT_00b5a750 + 0xc))(0x8a);
            return 1;
          }
        }
        else if (uVar1 == 0x70430001) {
          *(undefined4 *)(in_ECX + 4) = 2;
          *(undefined4 *)(in_ECX + 8) = 0x24;
          FUN_00401830(&DAT_009d7159);
          FUN_00401830(s_ui_pvpask_txt_009d715c);
          uVar9 = 0;
          uVar2 = FUN_0066a660(auStack_1b4);
          FUN_006699c0(auStack_150,auStack_fc,uVar2,uVar9);
          FUN_00406250();
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
      }
      else {
        switch(uVar1 + 0x8fbcfffd) {
        case 0:
          (**(code **)(*DAT_00b5a750 + 8))(0x5b);
          return 1;
        case 1:
          (**(code **)(*DAT_00b5a750 + 0xc))(0x5b);
          return 1;
        case 2:
          iVar4 = (**(code **)(*DAT_00b5a750 + 8))(0x5a);
          if (iVar4 != 0) {
            FUN_0068b9c0((char)param_1[9]);
            uVar2 = FUN_0066a630(auStack_58);
            FUN_0068bb60(uVar2);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          return 1;
        case 3:
          iVar4 = (**(code **)(*DAT_00b5a750 + 8))(0x59);
          if (iVar4 != 0) {
            FUN_0068bf50((char)param_1[1]);
          }
          return 1;
        }
      }
    }
    else if (uVar1 < 0x70910006) {
      if (uVar1 == 0x70910005) {
        iVar4 = (**(code **)(*DAT_00b5a750 + 8))(0x5d);
        if (iVar4 != 0) {
          FUN_00687000(param_1[1],(char)param_1[2]);
        }
        return 1;
      }
      if (uVar1 < 0x70910002) {
        if (uVar1 == 0x70910001) {
          (**(code **)(*DAT_00b5a750 + 0xc))(0x5c);
          return 1;
        }
        if (uVar1 == 0x70430008) {
          (**(code **)(*DAT_00b5a750 + 0xc))(0x59);
          return 1;
        }
        if (uVar1 == 0x70910000) {
          iVar4 = (**(code **)(*DAT_00b5a750 + 8))(0x5c);
          if (iVar4 != 0) {
            FUN_006878a0(CONCAT22(extraout_var,(short)param_1[1]),
                         CONCAT22(extraout_var_02,*(undefined2 *)((int)param_1 + 6)),
                         CONCAT22(extraout_var,(short)param_1[2]));
          }
          return 1;
        }
      }
      else if (uVar1 == 0x70910002) {
        uStack_20c = 0;
        uStack_208 = 0;
        uStack_204 = 0;
        uStack_1d4 = 0xf;
        uStack_1d8 = 0;
        uStack_1e8 = 0;
        uStack_1b8 = 0xf;
        uStack_1bc = 0;
        uStack_1cc = 0;
        FUN_00403810(s_<YEAR>_009d7190);
        FUN_00401830(&DAT_009d7198);
        uVar2 = FUN_00404230(auStack_e0);
        FUN_00401660(uVar2,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    else {
      if (uVar1 == 0x70910006) {
        (**(code **)(*DAT_00b5a750 + 0xc))(0x5d);
        return 1;
      }
      if (uVar1 == 0x70910007) {
        iVar4 = (**(code **)(*DAT_00b5a750 + 8))(0x5e);
        if (iVar4 != 0) {
          FUN_00686a90(param_1[2],param_1[1]);
        }
        return 1;
      }
      if (uVar1 == 0x70910008) {
        (**(code **)(*DAT_00b5a750 + 0xc))(0x5e);
        return 1;
      }
    }
  }
  else if (uVar1 < 0x70930005) {
    if (uVar1 == 0x70930004) {
      (**(code **)(*DAT_00b5a750 + 0xc))(0x84);
      return 1;
    }
    if (uVar1 < 0x70920005) {
      if (uVar1 == 0x70920004) {
        return 1;
      }
      if (uVar1 < 0x70910013) {
        if (uVar1 == 0x70910012) {
          (**(code **)(*DAT_00b5a750 + 0xc))(0x5f);
          return 1;
        }
        if (uVar1 == 0x70910010) {
          (**(code **)(*DAT_00b5a750 + 0xc))(0x65);
          return 1;
        }
        if (uVar1 == 0x70910011) {
          iStack_1f4 = (**(code **)(*DAT_00b5a750 + 8))(0x5f);
          if (iStack_1f4 != 0) {
            uVar1 = 0;
            do {
              puVar5 = (undefined4 *)FUN_0066a580(uVar1);
              if (puVar5 == (undefined4 *)0x0) {
                FUN_00401830(s_pMsgStock_009d7184);
                FUN_00406880(auStack_18c);
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              FUN_00686600(puVar5[1],*puVar5);
              uVar1 = uVar1 + 1;
            } while (uVar1 < 3);
            FUN_00686030();
          }
          return 1;
        }
      }
      else if (uVar1 == 0x70920003) {
        *(undefined4 *)(in_ECX + 4) = 6;
        *(undefined4 *)(in_ECX + 8) = 0x28;
        uStack_1fc = 0;
        uStack_1f8 = 0;
        iStack_1f4 = 0;
        FUN_00406250();
        FUN_00401830(s_ui_autocheckresult_txt_009d716c);
        uVar9 = 20000;
        puVar8 = auStack_200;
        uVar2 = FUN_005523a0(auStack_8c);
        FUN_006699c0(auStack_134,uVar2,puVar8,uVar9);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    else {
      if (uVar1 == 0x70930000) {
        (**(code **)(*DAT_00b5a750 + 8))(0x83);
        return 1;
      }
      if (uVar1 == 0x70930001) {
        (**(code **)(*DAT_00b5a750 + 0xc))(0x83);
        return 1;
      }
      if (uVar1 == 0x70930003) {
        (**(code **)(*DAT_00b5a750 + 8))(0x84);
        return 1;
      }
    }
  }
  else {
    switch(uVar1 + 0x8f6cfffb) {
    case 0:
      (**(code **)(*DAT_00b5a750 + 8))(0x85);
      return 1;
    case 1:
      (**(code **)(*DAT_00b5a750 + 0xc))(0x85);
      return 1;
    case 2:
      (**(code **)(*DAT_00b5a750 + 8))(0x86);
      return 1;
    case 3:
      (**(code **)(*DAT_00b5a750 + 0xc))(0x86);
      return 1;
    case 4:
      (**(code **)(*DAT_00b5a750 + 8))(0x87);
      return 1;
    case 0xb:
      (**(code **)(*DAT_00b5a750 + 0xc))(0x87);
      return 1;
    case 0xc:
      (**(code **)(*DAT_00b5a750 + 8))(0x88);
      return 1;
    case 0xd:
      (**(code **)(*DAT_00b5a750 + 0xc))(0x88);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0066a580 @ 0x0066a580 ====

int FUN_0066a580(uint param_1)

{
  int in_ECX;
  
  if (param_1 < 3) {
    return in_ECX + 4 + param_1 * 8;
  }
  return 0;
}


// ==== FUN_0066a5a0 @ 0x0066a5a0 ====

undefined4 FUN_0066a5a0(void)

{
  return 0x58;
}


// ==== FUN_0066a5b0 @ 0x0066a5b0 ====

void FUN_0066a5b0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d723c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0066a5f0 @ 0x0066a5f0 ====

void FUN_0066a5f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7228;
  if (DAT_00b5a750 != (int *)0x0) {
    (**(code **)(*DAT_00b5a750 + 0xc))(0x58);
  }
  DAT_00b5b0c0 = 0;
  *in_ECX = &PTR_FUN_009d7214;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0066a630 @ 0x0066a630 ====

int FUN_0066a630(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(in_ECX + 8,0,0xffffffff);
  return param_1;
}


// ==== FUN_0066a660 @ 0x0066a660 ====

undefined4 FUN_0066a660(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00406600(in_ECX + 4);
  return param_1;
}


// ==== FUN_0066a680 @ 0x0066a680 ====

void FUN_0066a680(void)

{
  return;
}


// ==== FUN_0066a690 @ 0x0066a690 ====

undefined1 FUN_0066a690(void)

{
  return 0;
}


// ==== FUN_0066a6a0 @ 0x0066a6a0 ====

undefined1 FUN_0066a6a0(void)

{
  return 0;
}


// ==== FUN_0066a6b0 @ 0x0066a6b0 ====

void FUN_0066a6b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d731c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0066a6d0 @ 0x0066a6d0 ====

void FUN_0066a6d0(int param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint unaff_retaddr;
  void *local_74;
  undefined1 local_70;
  undefined4 uStack_64;
  uint local_60;
  void *local_5c;
  undefined1 uStack_58;
  undefined4 uStack_4c;
  uint uStack_48;
  undefined4 auStack_44 [2];
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  void *pvStack_24;
  uint uStack_10;
  int iStack_4;
  
  local_5c = (void *)0xf;
  local_60 = 0;
  local_70 = 0;
  FUN_00401740(s_pan_candidate_009d72d4,0xd);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_74);
  if (0xf < local_60) {
    _free(local_74);
    return;
  }
  local_60 = 0xf;
  uStack_64 = 0;
  local_74 = (void *)((uint)local_74 & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    auStack_44[0] = 0xf;
    uStack_48 = 0;
    uStack_58 = 0;
    FUN_00401740(s_list_candidate_009d72e4,0xe);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_5c);
    if (0xf < uStack_48) {
      _free(local_5c);
      return;
    }
    uStack_48 = 0xf;
    uStack_4c = 0;
    local_5c = (void *)((uint)local_5c & 0xffffff00);
    if (piVar2 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar2 + 0x30))();
      iStack_38 = *(int *)(iVar3 + 0xa4);
      if (*(int *)(param_2 + 4) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x1c;
      }
      iVar3 = iVar3 * iStack_38 + 0x14;
      uVar4 = (**(code **)(*piVar1 + 0x10))();
      FUN_005041e0(uVar4);
      if ((uint)(*(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x9c) - iVar3) <= unaff_retaddr) {
        iStack_38 = -iVar3;
      }
      iStack_38 = iStack_38 + unaff_retaddr;
      iStack_3c = iStack_4;
      iStack_34 = iStack_4 + 0x14 + param_1;
      iStack_30 = iStack_38 + iVar3;
      (**(code **)(*piVar1 + 0xc))(auStack_44);
      FUN_00576750(param_2);
      if ((*(int *)(param_2 + 4) != 0) &&
         (param_2 < (uint)((*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x1c))) {
        FUN_00575690(param_2);
      }
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
    }
  }
  return;
}


// ==== FUN_0066a8a0 @ 0x0066a8a0 ====

void FUN_0066a8a0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_CandidateWnd_ui_candida_009d72a8,0x29);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
  }
  return;
}


// ==== FUN_0066a930 @ 0x0066a930 ====

void FUN_0066a930(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d731c;
  FUN_0066a8a0();
  return;
}


// ==== FUN_0066a950 @ 0x0066a950 ====

undefined4 FUN_0066a950(void)

{
  return 0x7a;
}


// ==== FUN_0066a960 @ 0x0066a960 ====

void FUN_0066a960(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d731c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0066a9a0 @ 0x0066a9a0 ====

void FUN_0066a9a0(void)

{
  return;
}


// ==== FUN_0066a9b0 @ 0x0066a9b0 ====

undefined1 FUN_0066a9b0(void)

{
  return 0;
}


// ==== FUN_0066a9c0 @ 0x0066a9c0 ====

void FUN_0066a9c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7404;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0066a9e0 @ 0x0066a9e0 ====

undefined4 FUN_0066a9e0(void)

{
  (**(code **)(*DAT_00b5b128 + 0x14))();
  return 1;
}


// ==== FUN_0066a9f0 @ 0x0066a9f0 ====

undefined4 FUN_0066a9f0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_close_009d73e0,9);
    if (iVar2 == 0) {
      uVar3 = (**(code **)(*in_ECX + 0x10))();
      return uVar3;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_no_009d73ec);
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5b128 + 0x14))();
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_yes_009d73f4);
    if (cVar1 != '\0') {
      if (in_ECX[2] != -1) {
        (**(code **)(*DAT_00b5b12c + 0xc))((short)in_ECX[2]);
      }
      (**(code **)(*DAT_00b5b128 + 0x14))();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0066aaa0 @ 0x0066aaa0 ====

void FUN_0066aaa0(void *param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 in_stack_00000014;
  uint in_stack_00000018;
  undefined1 uStack0000001c;
  void *in_stack_00000020;
  uint in_stack_00000034;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&param_1);
  (**(code **)(*piVar1 + 0x30))();
  FUN_0055a260(&uStack0000001c);
  if (0xf < in_stack_00000018) {
    _free(param_1);
    return;
  }
  in_stack_00000018 = 0xf;
  in_stack_00000014 = 0;
  param_1 = (void *)((uint)param_1 & 0xffffff00);
  if (in_stack_00000034 < 0x10) {
    return;
  }
  _free(in_stack_00000020);
  return;
}


// ==== FUN_0066ab00 @ 0x0066ab00 ====

void FUN_0066ab00(undefined1 param_1,void *param_2)

{
  int in_ECX;
  uint in_stack_0000001c;
  undefined1 uStack00000020;
  void *in_stack_00000024;
  uint in_stack_00000038;
  undefined1 uStack0000003c;
  void *in_stack_00000040;
  uint in_stack_00000054;
  ushort in_stack_00000058;
  
  FUN_00401660(&param_1,0,0xffffffff);
  FUN_00401740(s_lbl_exchangename_009d73b0,0x10);
  FUN_0066aaa0();
  FUN_00401660(&uStack00000020,0,0xffffffff);
  FUN_00401740(s_lbl_payname_009d73c4,0xb);
  FUN_0066aaa0();
  FUN_00401660(&uStack0000003c,0,0xffffffff);
  FUN_00401740(s_lbl_paycount_009d73d0,0xc);
  FUN_0066aaa0();
  *(uint *)(in_ECX + 8) = (uint)in_stack_00000058;
  if (0xf < in_stack_0000001c) {
    _free(param_2);
    return;
  }
  if (0xf < in_stack_00000038) {
    _free(in_stack_00000024);
    return;
  }
  if (in_stack_00000054 < 0x10) {
    return;
  }
  _free(in_stack_00000040);
  return;
}


// ==== FUN_0066ac10 @ 0x0066ac10 ====

void FUN_0066ac10(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ExchangeShop_ui_confirm_009d7388,0x27);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
  }
  *(undefined4 *)(in_ECX + 8) = 0xffffffff;
  return;
}


// ==== FUN_0066aca0 @ 0x0066aca0 ====

void FUN_0066aca0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7404;
  FUN_0066ac10();
  return;
}


// ==== FUN_0066acc0 @ 0x0066acc0 ====

undefined4 FUN_0066acc0(void)

{
  return 0x79;
}


// ==== FUN_0066acd0 @ 0x0066acd0 ====

void FUN_0066acd0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d7404;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0066ad10 @ 0x0066ad10 ====

void FUN_0066ad10(void)

{
  return;
}


// ==== FUN_0066ad20 @ 0x0066ad20 ====

undefined1 FUN_0066ad20(void)

{
  return 0;
}


// ==== FUN_0066ad30 @ 0x0066ad30 ====

undefined4 FUN_0066ad30(void)

{
  (**(code **)(*DAT_00b5b12c + 8))();
  return 1;
}


// ==== FUN_0066ad60 @ 0x0066ad60 ====

void FUN_0066ad60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d75a4;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_0066ae00 @ 0x0066ae00 ====

void FUN_0066ae00(void *param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 in_stack_00000014;
  uint in_stack_00000018;
  undefined1 uStack0000001c;
  void *in_stack_00000020;
  uint in_stack_00000034;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&param_1);
  (**(code **)(*piVar1 + 0x30))();
  FUN_0055a260(&uStack0000001c);
  if (0xf < in_stack_00000018) {
    _free(param_1);
    return;
  }
  in_stack_00000018 = 0xf;
  in_stack_00000014 = 0;
  param_1 = (void *)((uint)param_1 & 0xffffff00);
  if (in_stack_00000034 < 0x10) {
    return;
  }
  _free(in_stack_00000020);
  return;
}


// ==== FUN_0066aee0 @ 0x0066aee0 ====

void FUN_0066aee0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  void *pvStack_20;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_list_price_009d7554,10);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
    local_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    FUN_00401740(s_list_menu_009d7560,9);
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return;
    }
    uStack_c = 0xf;
    uStack_10 = 0;
    pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x30))();
      uVar2 = FUN_005754e0();
      FUN_00575500(uVar2);
    }
  }
  return;
}


// ==== FUN_0066afc0 @ 0x0066afc0 ====

/* WARNING: Removing unreachable block (ram,0x0066b0d7) */

void FUN_0066afc0(void)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  int *unaff_EDI;
  undefined4 unaff_retaddr;
  undefined1 auStack_3a [18];
  void *pvStack_28;
  undefined1 uStack_24;
  void *pvStack_20;
  void *local_1c;
  uint local_18;
  uint uStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  uint local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = local_18 & 0xffffff00;
  FUN_00401740(s_list_menu_009d756c,9);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  (**(code **)(*piVar2 + 0x30))();
  FUN_00575690(unaff_retaddr);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(s_list_price_009d7578,10);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
  (**(code **)(*piVar2 + 0x30))();
  FUN_00575690(local_4);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  cVar1 = (**(code **)(*DAT_00b5b128 + 0x18))();
  if (cVar1 != '\x01') {
    uVar4 = local_4 & 0xff;
    pvStack_28 = (void *)0xf;
    FUN_00401740(s_list_price_009d7584,10);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_3a + -6,uVar4);
    (**(code **)(*piVar2 + 0x30))();
    uVar3 = FUN_00575790();
    FUN_00401660(uVar3,0,0xffffffff);
    FUN_00401660(in_ECX + 8,0,0xffffffff);
    uStack_10 = 0xf;
    uStack_14 = 0;
    uStack_24 = 0;
    FUN_00401740(s_list_menu_009d7590,9);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_28);
    (**(code **)(*piVar2 + 0x30))();
    uVar3 = FUN_00575790();
    if (0xf < uStack_14) {
      _free(pvStack_28);
      return;
    }
    uStack_14 = 0xf;
    local_18 = 0;
    pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
    FUN_00401660(uVar3,0,0xffffffff);
    (**(code **)(*unaff_EDI + 0x10))();
  }
  return;
}


// ==== FUN_0066b1c0 @ 0x0066b1c0 ====

void FUN_0066b1c0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ExchangeShop_ui_exchang_009d7470,0x2c);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
  }
  return;
}


// ==== FUN_0066b250 @ 0x0066b250 ====

undefined4 FUN_0066b250(int param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_close_009d74a0,9);
      if (iVar2 == 0) {
        uVar3 = (**(code **)(*in_ECX + 0x10))();
        return uVar3;
      }
      cVar1 = FUN_004036a0(param_2,s_list_price_scroll_upbtn_009d74ac);
      if ((cVar1 == '\0') &&
         (cVar1 = FUN_004036a0(param_2,s_list_price_scroll_downbtn_009d74c4), cVar1 == '\0')) {
        return 0;
      }
      FUN_0066aee0();
      return 1;
    }
  }
  else if (param_1 == 0) {
    if ((param_3 == 7) &&
       (iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_list_price_scroll_bar_009d74e0,0x15
                            ), iVar2 == 0)) {
      FUN_0066aee0();
      return 1;
    }
  }
  else if ((param_1 == 0x16) && (param_3 == 1)) {
    cVar1 = FUN_004036a0(param_2,s_list_menu_009d74f8);
    if ((cVar1 == '\0') && (cVar1 = FUN_004036a0(param_2,s_list_price_009d7504), cVar1 == '\0')) {
      return 0;
    }
    FUN_0066afc0(param_4);
    return 1;
  }
  return 0;
}


// ==== FUN_0066b350 @ 0x0066b350 ====

void FUN_0066b350(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d75a4;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  FUN_0066b1c0();
  return;
}


// ==== FUN_0066b380 @ 0x0066b380 ====

void FUN_0066b380(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 uVar7;
  int in_ECX;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar8;
  int unaff_EBX;
  ushort uVar9;
  void *unaff_EBP;
  int unaff_EDI;
  undefined4 uVar10;
  uint in_stack_ffffff74;
  undefined1 auStack_5a [2];
  undefined4 uStack_58;
  void *pvStack_54;
  undefined4 uStack_50;
  undefined1 auStack_4c [4];
  void *pvStack_48;
  void *pvStack_44;
  void *pvStack_40;
  void *pvStack_3c;
  void *pvStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  void *pvStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  undefined4 uStack_c;
  uint uStack_8;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5aa24 + 8))(param_1);
  if (piVar3 != (int *)0x0) {
    iVar4 = (**(code **)(*piVar3 + 4))();
    pcVar5 = (char *)(iVar4 + 2);
    do {
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    FUN_00401740((char *)(iVar4 + 2),(int)pcVar5 - (iVar4 + 3));
    uVar10 = 0xf;
    FUN_00401740(s_lbl_title_009d7510,9);
    FUN_0066ae00();
    pvStack_48 = (void *)0x0;
    pvStack_44 = (void *)0x0;
    pvStack_40 = (void *)0x0;
    uStack_58 = 0;
    pvStack_54 = (void *)0x0;
    uStack_50 = 0;
    uVar9 = 0;
    if (*(short *)(iVar4 + 0x2a) != 0) {
      do {
        iVar1 = (uint)uVar9 * 0x30 + iVar4;
        pcVar5 = (char *)(iVar1 + 0x34);
        uStack_24 = 0xf;
        pvStack_28 = (void *)0x0;
        pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
        pcVar6 = pcVar5;
        do {
          cVar2 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar2 != '\0');
        FUN_00401740(pcVar5,(int)pcVar6 - (iVar1 + 0x35));
        FUN_00406720(&pvStack_3c);
        if (0xf < uStack_24) {
          _free(pvStack_38);
          return;
        }
        uStack_24 = 0xf;
        pvStack_28 = (void *)0x0;
        pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
        in_stack_ffffff74 = in_stack_ffffff74 & 0xffffff00;
        FUN_00401740(&DAT_009d751c,2);
        uVar7 = FUN_00404230(auStack_20,uVar10,in_stack_ffffff74);
        FUN_00406720(uVar7);
        if (0xf < uStack_8) {
          _free(pvStack_1c);
          return;
        }
        uVar9 = uVar9 + 1;
        uStack_8 = 0xf;
        uStack_c = 0;
        pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      } while (uVar9 < *(ushort *)(iVar4 + 0x2a));
      in_ECX = unaff_EBX;
    }
    uStack_24 = 0xf;
    pvStack_28 = (void *)0x0;
    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    FUN_00401740(s_list_menu_009d7520,9);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_3c);
    if (piVar3 == (int *)0x0) {
      if (0xf < pvStack_28) goto LAB_0066b57d;
    }
    else {
      (**(code **)(*piVar3 + 0x30))();
      FUN_00576750(&uStack_50);
      if (0xf < pvStack_28) {
LAB_0066b57d:
        _free(pvStack_3c);
        return;
      }
    }
    pvStack_28 = (void *)0xf;
    uStack_2c = 0;
    pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
    FUN_00401740(s_list_price_009d752c,10);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_40);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x30))();
      FUN_00576750(auStack_5a + -10);
    }
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    FUN_00401740(s_list_menu_009d7538,9);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_44);
    if (0xf < uStack_30) {
      _free(pvStack_44);
      return;
    }
    uStack_30 = 0xf;
    uStack_34 = 0;
    pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
    if (piVar3 != (int *)0x0) {
      uStack_c = (**(code **)(*piVar3 + 0x30))();
      uVar9 = 0;
      uVar8 = extraout_var;
      if (*(short *)(iVar4 + 0x2a) != 0) {
        do {
          uVar10 = (**(code **)(*DAT_00b5a794 + 0xc))
                             (0,*(ushort *)((uint)uVar9 * 0x30 + 0x5c + iVar4) | 0x7d70000);
          FUN_00575960((uint)uVar9,uVar10);
          uVar9 = uVar9 + 1;
        } while (uVar9 < *(ushort *)(iVar4 + 0x2a));
        in_ECX = unaff_EDI;
        uVar8 = extraout_var_00;
      }
      piVar3 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))
                                (CONCAT22(uVar8,*(undefined2 *)(iVar4 + 0x2c)));
      iVar4 = (**(code **)(*piVar3 + 4))();
      uStack_34 = 0xf;
      pvStack_38 = (void *)0x0;
      pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
      pcVar5 = (char *)(iVar4 + 0x36);
      do {
        cVar2 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar2 != '\0');
      FUN_00401740((char *)(iVar4 + 0x36),(int)pcVar5 - (iVar4 + 0x37));
      FUN_00401660(auStack_4c,0,0xffffffff);
      if (0xf < uStack_34) {
        _free(pvStack_48);
        return;
      }
      uStack_18 = 0xf;
      pvStack_1c = (void *)0x0;
      uStack_2c = uStack_2c & 0xffffff00;
      FUN_00401660(in_ECX + 8,0,0xffffffff);
      uStack_34 = 0xf;
      pvStack_38 = (void *)0x0;
      pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
      FUN_00401740(s_lbl_pay_name_009d7544,0xc);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_4c);
      (**(code **)(*piVar3 + 0x30))();
      FUN_0055a260(&uStack_2c);
      if (0xf < uStack_30) {
        _free(pvStack_44);
        return;
      }
      uStack_30 = 0xf;
      uStack_34 = 0;
      pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
      if (0xf < uStack_14) {
        _free(pvStack_28);
        return;
      }
    }
    uStack_30 = 0xf;
    uStack_34 = 0;
    if (unaff_EBP != (void *)0x0) {
      FUN_00405de0(unaff_EBP,unaff_EBX,auStack_5a + -0xe,uStack_c);
      _free(unaff_EBP);
      return;
    }
    if (pvStack_54 != (void *)0x0) {
      FUN_00405de0(pvStack_54,uStack_50,&uStack_58,uStack_c);
      _free(pvStack_54);
      return;
    }
  }
  return;
}


// ==== FUN_0066b800 @ 0x0066b800 ====

undefined4 FUN_0066b800(void)

{
  return 0x78;
}


// ==== FUN_0066b810 @ 0x0066b810 ====

void FUN_0066b810(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d75a4;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if (0xf < (uint)in_ECX[8]) {
    _free((void *)in_ECX[3]);
    return;
  }
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0066b870 @ 0x0066b870 ====

void FUN_0066b870(void)

{
  return;
}


// ==== FUN_0066b880 @ 0x0066b880 ====

undefined1 FUN_0066b880(void)

{
  return 0;
}


// ==== FUN_0066b890 @ 0x0066b890 ====

void FUN_0066b890(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7668;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0066b8b0 @ 0x0066b8b0 ====

void FUN_0066b8b0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_vehicle_ui_delaywnd_txt_009d7610,0x20);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
  }
  return;
}


// ==== FUN_0066b940 @ 0x0066b940 ====

void FUN_0066b940(undefined1 param_1,uint param_2)

{
  int *piVar1;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  *(uint *)(in_ECX + 0xc) = param_2;
  *(uint *)(in_ECX + 0x14) = param_2 / 1000;
  *(undefined1 *)(in_ECX + 8) = param_1;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_waittime_009d7634,0xc);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(1);
  }
  return;
}


// ==== FUN_0066b9d0 @ 0x0066b9d0 ====

void FUN_0066b9d0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  void *local_38;
  undefined1 local_34;
  undefined4 uStack_28;
  void *local_24;
  undefined4 local_20;
  uint uStack_10;
  
  uVar4 = (uint)(*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 0x10)) / 1000;
  if (*(uint *)(in_ECX + 0x14) != uVar4) {
    *(uint *)(in_ECX + 0x14) = uVar4;
    local_20 = 0xf;
    local_24 = (void *)0x0;
    local_34 = 0;
    FUN_00401740(s_lbl_waittime_009d7650,0xc);
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
    if (0xf < local_24) {
      _free(local_38);
    }
    local_24 = (void *)0xf;
    uStack_28 = 0;
    local_38 = (void *)((uint)local_38 & 0xffffff00);
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x30))();
      if (iVar2 != 0) {
        if (*(char *)(in_ECX + 8) == '\x02') {
          iVar2 = 0x7d50008;
        }
        else {
          iVar2 = (*(char *)(in_ECX + 8) == '\x03') + 0x7d50007;
        }
        uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,iVar2,*(undefined4 *)(in_ECX + 0x14));
        FUN_00401660(uVar3,0,0xffffffff);
        FUN_00404230(&uStack_28);
        FUN_0055a260(&uStack_28);
        if (0xf < uStack_10) {
          _free(local_24);
        }
      }
    }
  }
  return;
}


// ==== FUN_0066bae0 @ 0x0066bae0 ====

void FUN_0066bae0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7668;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  FUN_0066b8b0();
  return;
}


// ==== FUN_0066bb00 @ 0x0066bb00 ====

void FUN_0066bb00(int param_1)

{
  char cVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  undefined1 local_1c [28];
  
  cVar1 = *(char *)(in_ECX + 8);
  if (((cVar1 != '\0') && (uVar2 = *(uint *)(in_ECX + 0xc), uVar2 != 0)) &&
     (*(uint *)(in_ECX + 0x10) < uVar2)) {
    uVar3 = *(uint *)(in_ECX + 0x10) + *(int *)(param_1 + 4);
    *(uint *)(in_ECX + 0x10) = uVar3;
    if (uVar2 < uVar3) {
      *(uint *)(in_ECX + 0x10) = uVar2;
    }
    if (*(uint *)(in_ECX + 0x10) < uVar2) {
      FUN_00401830(s_processbar_009d7644);
      (**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_1c);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    if (cVar1 == '\x01') {
      (**(code **)(*DAT_00b5ad8c + 0xc))();
      *(undefined1 *)(in_ECX + 8) = 0;
      return;
    }
    if (cVar1 == '\x02') {
      (**(code **)(*DAT_00b5ad8c + 0x14))();
      *(undefined1 *)(in_ECX + 8) = 0;
      return;
    }
    if (cVar1 == '\x03') {
      (**(code **)(*DAT_00b5b130 + 8))();
    }
    *(undefined1 *)(in_ECX + 8) = 0;
  }
  return;
}


// ==== FUN_0066bc20 @ 0x0066bc20 ====

uint FUN_0066bc20(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_0066bb00(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0066bc50 @ 0x0066bc50 ====

undefined4 FUN_0066bc50(void)

{
  return 0x76;
}


// ==== FUN_0066bc60 @ 0x0066bc60 ====

void FUN_0066bc60(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d7668;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0066bca0 @ 0x0066bca0 ====

undefined4 FUN_0066bca0(void)

{
  return 0x70460001;
}


// ==== FUN_0066bcb0 @ 0x0066bcb0 ====

undefined4 FUN_0066bcb0(void)

{
  return 0x60100001;
}


// ==== FUN_0066bcc0 @ 0x0066bcc0 ====

undefined1 FUN_0066bcc0(void)

{
  return 0;
}


// ==== FUN_0066bcd0 @ 0x0066bcd0 ====

void FUN_0066bcd0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0066bcdc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_0066bce0 @ 0x0066bce0 ====

undefined1 FUN_0066bce0(void)

{
  return 0;
}


// ==== FUN_0066bcf0 @ 0x0066bcf0 ====

void FUN_0066bcf0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  (**(code **)(*DAT_00b5a97c + 0x3c))(param_1,1);
  return;
}


// ==== FUN_0066bd10 @ 0x0066bd10 ====

void FUN_0066bd10(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7768;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  (**(code **)(*DAT_00b5b0d4 + 0x70))(0);
  if (DAT_00b5a97c != (int *)0x0) {
    (**(code **)(*DAT_00b5a97c + 0x3c))(0,0);
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 0;
      puVar1[2] = 0;
      *puVar1 = &PTR_FUN_009d7754;
      *(undefined1 *)(puVar1 + 4) = 0;
      puVar1[3] = 0;
      FUN_00797a20(puVar1);
      *in_ECX = &PTR_FUN_009b1764;
      return;
    }
    FUN_00797a20(0);
  }
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0066bdc0 @ 0x0066bdc0 ====

undefined4 FUN_0066bdc0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009d770c,8);
      if ((iVar2 != 0) && (cVar1 = FUN_004036a0(param_2,s_btn_ok_009d7718), cVar1 == '\0')) {
        return 0;
      }
      puVar3 = operator_new(4);
      if (puVar3 == (undefined4 *)0x0) {
        FUN_00797a20(0);
        *(undefined1 *)(in_ECX + 8) = 0;
        return 1;
      }
      *puVar3 = &PTR_FUN_009d7740;
      FUN_00797a20(puVar3);
      *(undefined1 *)(in_ECX + 8) = 0;
      return 1;
    }
    if (param_3 == 0) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_left_009d7720,8);
      if (iVar2 == 0) {
        (**(code **)(*DAT_00b5a97c + 0x40))(1);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_right_009d772c);
      if (cVar1 != '\0') {
        (**(code **)(*DAT_00b5a97c + 0x40))(2);
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_0066beb0 @ 0x0066beb0 ====

void FUN_0066beb0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int in_ECX;
  float10 fVar7;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_PreViewPlayer_ui_previe_009d76d4,0x2e);
  iVar4 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  if (iVar4 == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_FALSE_009d7704,5);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    _free(local_18);
    return;
  }
  (**(code **)(*DAT_00b5b0d4 + 0x70))(1);
  piVar5 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar6 = (undefined4 *)(**(code **)(*piVar5 + 0x28))();
  uVar1 = *puVar6;
  uVar2 = puVar6[1];
  piVar5 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  fVar7 = (float10)(**(code **)(*piVar5 + 0x30))();
  puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    puVar6[1] = 0;
    puVar6[2] = 0;
    *puVar6 = &PTR_FUN_009d7754;
    *(undefined1 *)(puVar6 + 4) = 1;
    puVar6[3] = 0;
  }
  puVar6[1] = uVar1;
  puVar6[2] = (float)fVar7;
  puVar6[3] = uVar2;
  FUN_00797a20(puVar6);
  piVar5 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar4 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar5;
  (**(code **)(*piVar5 + 0x40))();
  (**(code **)(*DAT_00b5a7cc + 0x14))(iVar4);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined1 *)(in_ECX + 8) = 1;
  return;
}


// ==== FUN_0066c050 @ 0x0066c050 ====

void FUN_0066c050(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7768;
  FUN_0066beb0();
  return;
}


// ==== FUN_0066c070 @ 0x0066c070 ====

undefined4 FUN_0066c070(void)

{
  return 0x75;
}


// ==== FUN_0066c080 @ 0x0066c080 ====

void FUN_0066c080(byte param_1)

{
  void *in_ECX;
  
  FUN_0066bd10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0066c0a0 @ 0x0066c0a0 ====

void FUN_0066c0a0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 9) == '\0') {
    *(undefined1 *)(in_ECX + 9) = 1;
  }
  return;
}


// ==== FUN_0066c0b0 @ 0x0066c0b0 ====

undefined1 FUN_0066c0b0(void)

{
  return 0;
}


// ==== FUN_0066c0c0 @ 0x0066c0c0 ====

undefined1 FUN_0066c0c0(void)

{
  return 0;
}


// ==== FUN_0066c0f0 @ 0x0066c0f0 ====

void FUN_0066c0f0(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 10) = param_3;
  *(undefined4 *)(in_ECX + 0x10) = param_1;
  *(undefined4 *)(in_ECX + 0xc) = param_2;
  return;
}


// ==== FUN_0066c110 @ 0x0066c110 ====

void FUN_0066c110(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) != '\0') {
    (**(code **)(*DAT_00b5a7a4 + 8))(*(undefined4 *)(in_ECX + 4));
    *(undefined1 *)(in_ECX + 8) = 0;
  }
  return;
}


// ==== FUN_0066c130 @ 0x0066c130 ====

void FUN_0066c130(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d783c;
  if (*(char *)(in_ECX + 2) != '\0') {
    (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
    *(undefined1 *)(in_ECX + 2) = 0;
  }
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0066c160 @ 0x0066c160 ====

void FUN_0066c160(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(char *)(in_ECX + 8) != '\x01') {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_UI_Game2_Dungeon_ui_VanishTimeWn_009d77d4,0x25);
    iVar1 = FUN_00410500(local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    *(undefined1 *)(in_ECX + 8) = 1;
    if (iVar1 != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
    }
  }
  return;
}


// ==== FUN_0066c1f0 @ 0x0066c1f0 ====

void FUN_0066c1f0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  void *unaff_EBX;
  undefined4 uStack_58;
  void *local_54;
  undefined1 local_50;
  undefined4 uStack_4c;
  void *pvStack_48;
  uint uStack_44;
  uint local_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  uint uStack_34;
  undefined1 auStack_30 [4];
  void *pvStack_2c;
  undefined4 uStack_1c;
  uint uStack_18;
  uint uStack_8;
  
  local_3c = 0xf;
  local_40 = 0;
  local_50 = 0;
  FUN_00401740(s_pan_time_009d77fc,8);
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_54);
  if (0xf < local_40) {
    _free(local_54);
    return;
  }
  if (iVar1 != 0) {
    local_40 = 0xf;
    uStack_44 = 0;
    local_54 = (void *)((uint)local_54 & 0xffffff00);
    FUN_00401740(s_pan_time_009d7808,8);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_58);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(1);
    }
    if (0xf < uStack_44) {
      _free(uStack_58);
      return;
    }
    uStack_44 = 0xf;
    pvStack_48 = (void *)0x0;
    uStack_58 = (void *)((uint)uStack_58 & 0xffffff00);
    FUN_00401740(s_textbox_time_009d7814,0xc);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_30 + -0x2c);
    if (0xf < pvStack_48) {
      _free(unaff_EBX);
      return;
    }
    pvStack_48 = (void *)0xf;
    uStack_4c = 0;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x30))();
      uStack_8 = uStack_8 % 0x3c;
      uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(7,*(int *)(in_ECX + 0x10) << 0x10 | 0x27);
      uStack_34 = 0xf;
      uStack_38 = 0;
      pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
      FUN_00401660(uVar3,0,0xffffffff);
      FUN_00401740(s__s__02d__02d_009d7824,0xc);
      FUN_00404230(auStack_30);
      FUN_005569f0(auStack_30,1);
      if (0xf < uStack_18) {
        _free(pvStack_2c);
        return;
      }
      uStack_18 = 0xf;
      uStack_1c = 0;
      pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
      if (0xf < uStack_34) {
        _free(pvStack_48);
        return;
      }
    }
  }
  return;
}


// ==== FUN_0066c3c0 @ 0x0066c3c0 ====

void FUN_0066c3c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d783c;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[4] = 0;
  in_ECX[1] = 0;
  FUN_0066c160();
  return;
}


// ==== FUN_0066c3e0 @ 0x0066c3e0 ====

void FUN_0066c3e0(int param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (uint)*(ushort *)(in_ECX + 10) -
          (uint)(*(int *)(param_1 + 0xc) - *(int *)(in_ECX + 0xc)) / 1000;
  if ((uint)*(ushort *)(in_ECX + 10) < uVar1 + 3) {
    (**(code **)(*DAT_00b5ae64 + 0x38))();
    return;
  }
  if (*(ushort *)(in_ECX + 10) < uVar1) {
    FUN_0066c1f0();
    return;
  }
  FUN_0066c1f0();
  return;
}


// ==== FUN_0066c440 @ 0x0066c440 ====

uint FUN_0066c440(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_0066c3e0(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0066c470 @ 0x0066c470 ====

undefined4 FUN_0066c470(void)

{
  return 0x74;
}


// ==== FUN_0066c480 @ 0x0066c480 ====

void FUN_0066c480(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d783c;
  if (*(char *)(in_ECX + 2) != '\0') {
    (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
    *(undefined1 *)(in_ECX + 2) = 0;
  }
  *in_ECX = &PTR_FUN_009b1764;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0066c4c0 @ 0x0066c4c0 ====

void FUN_0066c4c0(void)

{
  return;
}


// ==== FUN_0066c4d0 @ 0x0066c4d0 ====

undefined1 FUN_0066c4d0(void)

{
  return 0;
}


// ==== FUN_0066c4e0 @ 0x0066c4e0 ====

void FUN_0066c4e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d78dc;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0066c500 @ 0x0066c500 ====

undefined4 FUN_0066c500(int param_1,undefined4 param_2,int param_3)

{
  if ((param_1 == 1) && (param_3 == 1)) {
    (**(code **)(*DAT_00b5ae64 + 0x30))();
    return 1;
  }
  return 0;
}


// ==== FUN_0066c530 @ 0x0066c530 ====

void FUN_0066c530(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_Dungeon_ui_dungeonrecv__009d78a8,0x23);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
  }
  return;
}


// ==== FUN_0066c5c0 @ 0x0066c5c0 ====

void FUN_0066c5c0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  uint unaff_retaddr;
  void *local_38;
  undefined1 local_34;
  void *pvStack_28;
  uint local_24;
  undefined4 local_20;
  uint uStack_14;
  undefined4 uStack_10;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_textbox_009d78cc,7);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = 0xf;
  pvStack_28 = (void *)0x0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  (**(code **)(*piVar1 + 0x30))();
  uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,unaff_retaddr | 0x7d40000);
  uStack_10 = 0xf;
  uStack_14 = 0;
  local_24 = local_24 & 0xffffff00;
  FUN_00401660(uVar2,0,0xffffffff);
  FUN_005569f0(&pvStack_28,1);
  (**(code **)(*DAT_00b5acd4 + 4))(0);
  if (uStack_14 < 0x10) {
    return;
  }
  _free(pvStack_28);
  return;
}


// ==== FUN_0066c690 @ 0x0066c690 ====

void FUN_0066c690(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d78dc;
  FUN_0066c530();
  return;
}


// ==== FUN_0066c6b0 @ 0x0066c6b0 ====

undefined4 FUN_0066c6b0(void)

{
  return 0x73;
}


// ==== FUN_0066c6c0 @ 0x0066c6c0 ====

void FUN_0066c6c0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d78dc;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0066c700 @ 0x0066c700 ====

void FUN_0066c700(void)

{
  return;
}


// ==== FUN_0066c710 @ 0x0066c710 ====

undefined1 FUN_0066c710(void)

{
  return 0;
}


// ==== FUN_0066c720 @ 0x0066c720 ====

void FUN_0066c720(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d79a4;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0066c740 @ 0x0066c740 ====

undefined4 FUN_0066c740(int param_1,int param_2,int param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_yes_009d7984,7);
  if (iVar1 == 0) {
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = 0;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x526000d;
    *(undefined2 *)((int)pvVar2 + 6) = 0x18;
    iVar1 = FUN_004244d0();
    *(undefined2 *)(iVar1 + 0x10) = *(undefined2 *)(in_ECX + 8);
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(in_ECX + 0xc);
    FUN_004d8570(iVar1);
    (**(code **)(*DAT_00b5ae64 + 0x28))();
    return 1;
  }
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x5260010;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar3 = FUN_004244d0();
  FUN_004d8570(uVar3);
  (**(code **)(*DAT_00b5ae64 + 0x28))();
  return 1;
}


// ==== FUN_0066c810 @ 0x0066c810 ====

void FUN_0066c810(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_Dungeon_ui_dungeonsend__009d7948,0x23);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
  }
  return;
}


// ==== FUN_0066c8a0 @ 0x0066c8a0 ====

void FUN_0066c8a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d79a4;
  FUN_0066c810();
  return;
}


// ==== FUN_0066c8c0 @ 0x0066c8c0 ====

void FUN_0066c8c0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 unaff_EBP;
  void *unaff_ESI;
  uint in_stack_00000010;
  void **ppvVar3;
  undefined1 auStack_84 [2];
  undefined1 auStack_82 [2];
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined1 auStack_74 [4];
  void *local_70;
  undefined1 local_6c;
  void *pvStack_64;
  undefined4 uStack_60;
  uint local_5c;
  undefined4 local_58;
  uint uStack_54;
  uint uStack_50;
  void *pvStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  uint uStack_38;
  uint uStack_34;
  undefined1 auStack_30 [4];
  void *pvStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined1 auStack_20 [4];
  undefined4 uStack_1c;
  uint uStack_18;
  undefined4 uStack_10;
  undefined4 uStack_c;
  void *pvStack_4;
  
  local_58 = 0xf;
  local_5c = 0;
  local_6c = 0;
  FUN_00401740(s_textbox_009d796c,7);
  ppvVar3 = &local_70;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(ppvVar3);
  if (0xf < local_5c) {
    _free(local_70);
    return;
  }
  local_5c = 0xf;
  uStack_60 = 0;
  local_70 = (void *)((uint)local_70 & 0xffffff00);
  (**(code **)(*piVar1 + 0x30))();
  uStack_80 = 0;
  uStack_7c = 0;
  uStack_78 = 0;
  uStack_40 = 0xf;
  uStack_44 = 0;
  uStack_54 = uStack_54 & 0xffffff00;
  uStack_24 = 0xf;
  uStack_28 = 0;
  uStack_38 = uStack_38 & 0xffffff00;
  FUN_00401740(s_<MAPNAME>_009d7974,9);
  FUN_00401740(&DAT_009d7980,2);
  uVar2 = FUN_00404230(auStack_74);
  FUN_00401660(uVar2,0,0xffffffff);
  if (0xf < local_5c) {
    _free(local_70);
    return;
  }
  FUN_004e6c20(&local_58);
  (**(code **)(*DAT_00b5a794 + 8))(auStack_20,0,0x7d40064,auStack_84);
  FUN_005569f0(auStack_30,1);
  *(undefined4 *)(in_ECX + 8) = uStack_10;
  *(undefined4 *)(in_ECX + 0xc) = uStack_c;
  if (0xf < uStack_18) {
    _free(pvStack_2c);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
  if (0xf < uStack_34) {
    _free(pvStack_48);
    return;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
  if (0xf < uStack_50) {
    _free(pvStack_64);
    return;
  }
  uStack_50 = 0xf;
  uStack_54 = 0;
  pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
  if (unaff_ESI != (void *)0x0) {
    FUN_004e65b0(unaff_ESI,unaff_EBP,auStack_84 + -0x10,ppvVar3);
    _free(unaff_ESI);
    return;
  }
  if (in_stack_00000010 < 0x10) {
    return;
  }
  _free(pvStack_4);
  return;
}


// ==== FUN_0066cae0 @ 0x0066cae0 ====

undefined4 FUN_0066cae0(void)

{
  return 0x72;
}


// ==== FUN_0066caf0 @ 0x0066caf0 ====

void FUN_0066caf0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d79a4;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0066cb30 @ 0x0066cb30 ====

undefined4 FUN_0066cb30(void)

{
  return 0x70390009;
}


// ==== FUN_0066cb40 @ 0x0066cb40 ====

void FUN_0066cb40(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0066cb4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_0066cb50 @ 0x0066cb50 ====

undefined1 FUN_0066cb50(void)

{
  return 0;
}


// ==== FUN_0066cb70 @ 0x0066cb70 ====

undefined1 FUN_0066cb70(void)

{
  return 0;
}


// ==== FUN_0066cb80 @ 0x0066cb80 ====

void FUN_0066cb80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7a70;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0066cba0 @ 0x0066cba0 ====

void FUN_0066cba0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  if (*(uint *)(in_ECX + 0xc) < (uint)(iVar1 - *(int *)(in_ECX + 8))) {
    puVar2 = operator_new(4);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = &PTR_FUN_009d7a5c;
      FUN_00797a20(puVar2);
      return;
    }
    FUN_00797a20(0);
  }
  return;
}


// ==== FUN_0066cbf0 @ 0x0066cbf0 ====

uint FUN_0066cbf0(int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    iVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    uVar1 = iVar2 - *(int *)(in_ECX + 8);
    if (*(uint *)(in_ECX + 0xc) < uVar1) {
      puVar3 = operator_new(4);
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = &PTR_FUN_009d7a5c;
        uVar1 = FUN_00797a20(puVar3);
        return uVar1 & 0xffffff00;
      }
      uVar1 = FUN_00797a20(0);
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0066cc50 @ 0x0066cc50 ====

void FUN_0066cc50(int *param_1,uint param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 auStack_3c [8];
  int iStack_34;
  int iStack_2c;
  void *pvStack_1c;
  uint uStack_8;
  
  if (param_1 != (int *)0x0) {
    uVar1 = (**(code **)(*param_1 + 0x10))();
    FUN_005041e0(uVar1);
    iStack_34 = (*(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x10)) / 2 - (param_2 >> 1);
    iStack_2c = iStack_34 + 5 + param_2;
    (**(code **)(*param_1 + 0xc))(auStack_3c);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
  }
  return;
}


// ==== FUN_0066ccc0 @ 0x0066ccc0 ====

void FUN_0066ccc0(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  void *unaff_ESI;
  undefined1 local_1c [2];
  undefined1 auStack_1a [2];
  void *local_18;
  uint uStack_10;
  undefined4 uStack_c;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_SystemWnd_ui_systemmess_009d7a10,0x2a);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  uVar2 = (**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(undefined4 *)(in_ECX + 4) = uVar2;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 10000;
  uStack_c = 0xf;
  uStack_10 = 0;
  FUN_00401740(s_lbl_message_009d7a3c,0xb);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_1c + -8);
  iVar1 = (**(code **)(*piVar3 + 0x10))();
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(iVar1 + 8);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(iVar1 + 0xc);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(iVar1 + 0x10);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(iVar1 + 0x14);
  if (uStack_10 < 0x10) {
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_0066cda0 @ 0x0066cda0 ====

void FUN_0066cda0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined1 uStack00000000;
  undefined4 uVar2;
  undefined1 auStack_2 [2];
  
  uVar2 = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
    FUN_0055a260(param_1);
    (**(code **)(*DAT_00b5a688 + 0x34))(4,param_1,auStack_2 + -6,&uStack00000000);
    FUN_0066cc50(piVar1,register0x00000010,uVar2);
  }
  return;
}


// ==== FUN_0066ce00 @ 0x0066ce00 ====

void FUN_0066ce00(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_lbl_message_009d7a48,0xb);
  FUN_0066cda0(local_1c,param_1);
  if (local_4 < 0x10) {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    *(undefined4 *)(in_ECX + 8) = uVar1;
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0066ce70 @ 0x0066ce70 ====

void FUN_0066ce70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7a70;
  FUN_0066ccc0();
  return;
}


// ==== FUN_0066ce90 @ 0x0066ce90 ====

undefined4 FUN_0066ce90(void)

{
  return 0x56;
}


// ==== FUN_0066cea0 @ 0x0066cea0 ====

void FUN_0066cea0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d7a70;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0066cee0 @ 0x0066cee0 ====

void FUN_0066cee0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0066ceec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_0066cef0 @ 0x0066cef0 ====

undefined1 FUN_0066cef0(void)

{
  return 0;
}


// ==== FUN_0066cf00 @ 0x0066cf00 ====

void FUN_0066cf00(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_0066cf10 @ 0x0066cf10 ====

undefined1 FUN_0066cf10(void)

{
  return 0;
}


// ==== FUN_0066cf20 @ 0x0066cf20 ====

void FUN_0066cf20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7b5c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if (in_ECX[4] != 0) {
    (**(code **)(*DAT_00b5a730 + 0x10))(1,in_ECX[4]);
  }
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0066cf60 @ 0x0066cf60 ====

void FUN_0066cf60(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  if (*(uint *)(in_ECX + 0xc) < (uint)(iVar1 - *(int *)(in_ECX + 8))) {
    (**(code **)(*DAT_00b5aeec + 0x34))();
  }
  return;
}


// ==== FUN_0066cf90 @ 0x0066cf90 ====

uint FUN_0066cf90(int *param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    iVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    uVar1 = iVar2 - *(int *)(in_ECX + 8);
    if (*(uint *)(in_ECX + 0xc) < uVar1) {
      uVar1 = (**(code **)(*DAT_00b5aeec + 0x34))();
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0066cfd0 @ 0x0066cfd0 ====

void FUN_0066cfd0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_Fishing_ui_fishgiveitem_009d7adc,0x27);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    uVar2 = (**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(undefined4 *)(in_ECX + 4) = uVar2;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 10000;
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0066d050 @ 0x0066d050 ====

void FUN_0066d050(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  char *pcVar4;
  void *unaff_EDI;
  undefined1 auStack_52 [6];
  uint uStack_4c;
  undefined1 auStack_40 [4];
  undefined1 uStack_3c;
  uint uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  
  uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(5,0x82000f);
  uStack_28 = 0xf;
  uStack_2c = 0;
  uStack_3c = 0;
  FUN_00401660(uVar2,0,0xffffffff);
  iVar3 = (**(code **)(**(int **)(in_ECX + 0x10) + 0x2c))();
  pcVar4 = (char *)(iVar3 + 0x32);
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar3 + 0x32),(int)pcVar4 - (iVar3 + 0x33));
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  FUN_00401740(s__SLANG__009d7b4c,7);
  FUN_00404440(auStack_40,auStack_24,auStack_52 + -10);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  (**(code **)(*DAT_00b5aeec + 0x2c))(5000,auStack_40);
  if (0xf < uStack_4c) {
    _free(unaff_EDI);
    return;
  }
  if (uStack_30 < 0x10) {
    return;
  }
  _free((void *)0xf);
  return;
}


// ==== FUN_0066d160 @ 0x0066d160 ====

void FUN_0066d160(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7b5c;
  in_ECX[4] = 0;
  FUN_0066cfd0();
  return;
}


// ==== FUN_0066d180 @ 0x0066d180 ====

void FUN_0066d180(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  void *unaff_EBX;
  char *pcVar5;
  char *pcStack_44;
  undefined1 auStack_32 [2];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  uint uStack_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  void *pvStack_4;
  
  uStack_2c = *(void **)(in_ECX + 0x10);
  if (uStack_2c != (void *)0x0) {
    uStack_30 = 1;
    (**(code **)(*DAT_00b5a730 + 0x10))();
  }
  uStack_2c = (void *)0x0;
  uStack_30 = 1;
  piVar2 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))();
  *(int **)(in_ECX + 0x10) = piVar2;
  cVar1 = (**(code **)(*piVar2 + 8))();
  if ((cVar1 != '\0') && (*(int **)(in_ECX + 0x10) != (int *)0x0)) {
    pcStack_44 = (char *)0x66d1d4;
    iVar3 = (**(code **)(**(int **)(in_ECX + 0x10) + 0x2c))();
    if (*(byte *)(iVar3 + 0x31) < 3) {
      pcStack_44 = s_pan_item_4_009d7b04;
      FUN_00401830();
      pcStack_44 = auStack_32 + 10;
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
      (**(code **)(*piVar2 + 0x24))(0);
      if (0xf < uStack_18) {
        _free(uStack_2c);
        return;
      }
      FUN_00401830(s_pan_item_2_009d7b10);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_30);
      (**(code **)(*piVar2 + 0x24))(1);
      if (0xf < uStack_20) {
        _free(pvStack_4);
        return;
      }
      pcVar5 = s_giveitem_2_009d7b1c;
    }
    else {
      pcStack_44 = s_pan_item_2_009d7b28;
      FUN_00401830();
      pcStack_44 = auStack_32 + 10;
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
      (**(code **)(*piVar2 + 0x24))(0);
      if (0xf < uStack_18) {
        _free(uStack_2c);
        return;
      }
      FUN_00401830(s_pan_item_4_009d7b34);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_30);
      (**(code **)(*piVar2 + 0x24))(1);
      if (0xf < uStack_20) {
        _free(pvStack_4);
        return;
      }
      pcVar5 = s_giveitem_4_009d7b40;
    }
    FUN_00401830(pcVar5);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_32 + -6);
    if (0xf < uStack_24) {
      _free(unaff_EBX);
      return;
    }
    (**(code **)(*piVar2 + 0x30))();
    uStack_1c = (**(code **)(**(int **)(in_ECX + 0x10) + 0x1c))();
    pcStack_44 = (char *)(uint)*(byte *)(iVar3 + 0x30);
    uStack_1c = uStack_1c & 0xffff;
    FUN_005802c0(&uStack_1c,&pcStack_44);
    FUN_00580870(*(undefined4 *)(in_ECX + 0x10),1);
    uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_0066d050();
  }
  return;
}


// ==== FUN_0066d370 @ 0x0066d370 ====

undefined4 FUN_0066d370(void)

{
  return 0x55;
}


// ==== FUN_0066d380 @ 0x0066d380 ====

void FUN_0066d380(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d7b5c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if (in_ECX[4] != 0) {
    (**(code **)(*DAT_00b5a730 + 0x10))(1,in_ECX[4]);
  }
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0066d3d0 @ 0x0066d3d0 ====

void FUN_0066d3d0(void)

{
  return;
}


// ==== FUN_0066d3e0 @ 0x0066d3e0 ====

void FUN_0066d3e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7d7c;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0066d420 @ 0x0066d420 ====

undefined4 FUN_0066d420(void)

{
  (**(code **)(*DAT_00b5ae74 + 0x50))();
  return 1;
}


// ==== FUN_0066d430 @ 0x0066d430 ====

void FUN_0066d430(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) &&
     (*(char *)(iVar2 + 0x10b) != (char)param_1)) {
    FUN_00558130(param_1);
    FUN_005586a0();
  }
  return;
}


// ==== FUN_0066d470 @ 0x0066d470 ====

void FUN_0066d470(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 8))(1);
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  switch(param_1) {
  case 0:
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_006da380(*(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar2;
      return;
    }
    break;
  case 1:
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_006da2c0(*(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar2;
      return;
    }
    break;
  case 2:
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_006da200(*(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar2;
      return;
    }
    break;
  case 3:
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_006da140(*(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar2;
      return;
    }
    break;
  case 4:
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_006da080(*(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar2;
      return;
    }
    break;
  default:
    goto switchD_0066d494_default;
  }
  *(undefined4 *)(in_ECX + 8) = 0;
switchD_0066d494_default:
  return;
}


// ==== FUN_0066d5e0 @ 0x0066d5e0 ====

void FUN_0066d5e0(void)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  char *pcVar5;
  void *pvStack_94;
  void *pvStack_90;
  undefined4 uStack_84;
  uint uStack_80;
  uint uStack_7c;
  uint uStack_78;
  void *pvStack_58;
  uint uStack_44;
  undefined1 auStack_40 [4];
  uint uStack_3c;
  
  cVar1 = (**(code **)(*DAT_00b5ae74 + 0x2c))();
  if (cVar1 == '\0') {
    if (*(char *)(in_ECX + 0xd) == '\0') {
      if (*(char *)(in_ECX + 0xc) == '\0') {
        pcVar5 = s_btnlist_1_009d7c10;
      }
      else {
        pcVar5 = s_btnlist_2_009d7c1c;
      }
      FUN_00401830(pcVar5);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_94);
      if (0xf < uStack_80) {
        _free(pvStack_94);
        return;
      }
      uStack_80 = 0xf;
      uStack_84 = 0;
      pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x44))(1);
      }
      *(undefined1 *)(in_ECX + 0xd) = 1;
      return;
    }
  }
  else {
    if (*(char *)(in_ECX + 0xd) != '\0') {
      if (*(char *)(in_ECX + 0xc) == '\0') {
        FUN_00401830(s_btnlist_1_009d7c28);
        piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_94);
        if (0xf < uStack_7c) goto LAB_0066d6c7;
      }
      else {
        FUN_00401830(s_btnlist_2_009d7c34);
        piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_94);
        if (0xf < uStack_7c) {
LAB_0066d6c7:
          _free(pvStack_90);
          return;
        }
      }
      uStack_7c = 0xf;
      uStack_80 = 0;
      pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x44))(0);
      }
      *(undefined1 *)(in_ECX + 0xd) = 0;
    }
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
    if (piVar2 != (int *)0x0) {
      uVar3 = (**(code **)(*piVar2 + 0x10))();
      FUN_005041e0(uVar3);
      iVar4 = (**(code **)(*DAT_00b5a74c + 0xc))(0x40);
      if (iVar4 == 0) {
        if (0xf < uStack_44) {
          _free(pvStack_58);
          return;
        }
      }
      else {
        if ((*(int **)(iVar4 + 4) != (int *)0x0) &&
           (piVar2 = (int *)(**(code **)(**(int **)(iVar4 + 4) + 0x2c))(), piVar2 != (int *)0x0)) {
          uVar3 = (**(code **)(*piVar2 + 0x10))();
          FUN_005041e0(uVar3);
          if (uStack_3c < uStack_78) {
            uStack_3c = uStack_78 + 1000;
          }
          (**(code **)(*piVar2 + 0xc))(auStack_40);
          FUN_00713830();
        }
        FUN_00713830();
      }
    }
  }
  return;
}


// ==== FUN_0066d7a0 @ 0x0066d7a0 ====

void FUN_0066d7a0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_btnlist_2_scroll_009d7ce0,0x10);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  uVar2 = (**(code **)(*piVar1 + 0x30))
                    (0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                     &Framework::UI::Control::VScroll::RTTI_Type_Descriptor,0);
  iVar3 = FUN_00803725(uVar2);
  if (iVar3 != 0) {
    FUN_0055ab10(0);
  }
  return;
}


// ==== FUN_0066d830 @ 0x0066d830 ====

void FUN_0066d830(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  void *in_ECX;
  int iVar5;
  undefined4 unaff_retaddr;
  void **ppvVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  int local_40;
  void *local_3c;
  undefined1 local_38 [4];
  undefined1 local_34;
  uint uStack_28;
  undefined4 local_24;
  void *local_20;
  void *local_1c;
  void *local_18;
  uint uStack_c;
  uint local_8;
  uint local_4;
  
  local_20 = (void *)0xf;
  local_24 = 0;
  local_34 = 0;
  iVar5 = 0;
  local_40 = 5;
  local_3c = in_ECX;
  do {
    uVar7 = 0;
    FUN_00401740(s_btn_tab__d_009d7cf4,10);
    uVar2 = FUN_00404230(&local_1c);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    piVar3 = (int *)(**(code **)(**(int **)((int)local_3c + 4) + 0x34))(local_38);
    if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
      FUN_00558730(iVar5 == param_1);
    }
    iVar5 = iVar5 + 1;
    local_40 = local_40 + -1;
  } while (local_40 != 0);
  uVar8 = 0;
  FUN_00401740(s_pan_goods1_009d7d00,10);
  ppvVar6 = &local_1c;
  uVar2 = FUN_00404230(ppvVar6,uVar7,uVar8);
  FUN_00401660(uVar2,0,0xffffffff);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401660(local_38,0,0xffffffff);
  pvVar1 = local_3c;
  piVar3 = (int *)(**(code **)(**(int **)((int)local_3c + 4) + 0x34))(&local_1c);
  if (piVar3 == (int *)0x0) {
    if (0xf < local_8) goto LAB_0066d99a;
  }
  else {
    (**(code **)(*piVar3 + 0x24))(unaff_retaddr);
    if (0xf < local_8) {
LAB_0066d99a:
      _free(local_1c);
      return;
    }
  }
  uVar7 = 0;
  FUN_00401740(s_pan_goods2_009d7d0c,10);
  uVar2 = FUN_00404230(&local_20,ppvVar6,uVar7);
  FUN_00401660(uVar2,0,0xffffffff);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401660(&local_3c,0,0xffffffff);
  piVar3 = (int *)(**(code **)(**(int **)((int)pvVar1 + 4) + 0x34))(&local_20);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x24))((char)local_4 == '\0');
  }
  if (0xf < uStack_c) {
    _free(local_20);
    return;
  }
  if (uStack_28 < 0x10) {
    return;
  }
  _free(local_3c);
  return;
}


// ==== FUN_0066da70 @ 0x0066da70 ====

undefined4 FUN_0066da70(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 extraout_EAX;
  int *in_ECX;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar2 = (**(code **)(*in_ECX + 0x14))();
  if (param_1 == iVar2) {
    if ((short)param_2 == 9) {
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      FUN_00401740(s_btn_buyInfo_009d7d18,0xb);
      iVar2 = (**(code **)(*DAT_00b5ae74 + 0x44))();
      FUN_0066d430(auStack_1c,iVar2 == 0);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return extraout_EAX;
      }
    }
    return 1;
  }
  if ((in_ECX[2] == 0) ||
     (cVar1 = (**(code **)(*(int *)in_ECX[2] + 0xc))(param_1,param_2,param_3,param_4), cVar1 == '\0'
     )) {
    return 0;
  }
  return 1;
}


// ==== FUN_0066db20 @ 0x0066db20 ====

void FUN_0066db20(void)

{
  uint uVar1;
  uint *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined4 uVar6;
  undefined1 auStack_3a [22];
  void *pvStack_24;
  void *pvStack_20;
  void *pvStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  puVar2 = (uint *)(**(code **)(*DAT_00b5ae78 + 0x34))();
  uVar1 = *puVar2;
  pvStack_24 = (void *)puVar2[3];
  pvStack_20 = (void *)puVar2[4];
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  FUN_00401740(s_textbox_notice_009d7d3c,0xe);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1c);
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  if (piVar3 != (int *)0x0) {
    iVar4 = (**(code **)(*piVar3 + 0x30))();
    if (iVar4 == 0) {
      return;
    }
    uVar6 = 0;
    uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,uVar1 & 0xffff | 0x3840000,0);
    FUN_005569f0(uVar5,uVar6);
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  FUN_00401740(s_btn_banner1_009d7d4c,0xb);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x30))();
    FUN_005581c0(auStack_3a + -10);
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  FUN_00401740(s_btn_banner2_009d7d58,0xb);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_24);
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x30))();
    FUN_005581c0(auStack_3a + -0xe);
  }
  return;
}


// ==== FUN_0066dcf0 @ 0x0066dcf0 ====

undefined4 FUN_0066dcf0(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x40001) {
    FUN_0066d5e0();
    FUN_0066db20();
  }
  if (*(int *)(in_ECX + 8) != 0) {
    cVar1 = (**(code **)(**(int **)(in_ECX + 8) + 4))(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0066dd40 @ 0x0066dd40 ====

void FUN_0066dd40(undefined4 param_1)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  void *in_ECX;
  void *unaff_EBX;
  undefined4 unaff_EBP;
  void *_Memory;
  undefined2 *puVar6;
  void *pvVar7;
  undefined2 *puVar8;
  int unaff_retaddr;
  undefined1 auStack_7e [14];
  undefined1 auStack_70 [4];
  void *pvStack_6c;
  undefined2 *puStack_68;
  int iStack_64;
  uint uStack_58;
  void *pvStack_54;
  undefined2 *puStack_50;
  undefined2 *puStack_4c;
  void *pvStack_44;
  undefined1 uStack_40;
  undefined4 uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  void *pvStack_24;
  undefined1 uStack_20;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  undefined2 uStack_8;
  undefined1 uStack_6;
  
  uVar2 = (**(code **)(*DAT_00b5ae78 + 8))(param_1);
  FUN_0066f030(uVar2);
  *(char *)((int)in_ECX + 0xc) = (char)param_1;
  _Memory = (void *)0x0;
  puVar8 = (undefined2 *)0x0;
  uStack_28 = 0;
  uStack_c = 0xf;
  uStack_10 = 0;
  uStack_20 = 0;
  pvStack_6c = (void *)0x0;
  puStack_68 = (undefined2 *)0x0;
  iStack_64 = 0;
  pvVar7 = in_ECX;
  if (puStack_4c != puStack_50) {
    puVar6 = puStack_50 + 0x14;
    do {
      uStack_28 = *(undefined4 *)(puVar6 + -0x14);
      FUN_00401660(puVar6 + -0x12,0,0xffffffff);
      uStack_8 = *puVar6;
      uStack_6 = *(undefined1 *)(puVar6 + 1);
      if ((_Memory == (void *)0x0) ||
         ((uint)(iStack_64 - (int)_Memory >> 1) <= (uint)((int)puVar8 - (int)_Memory >> 1))) {
        FUN_00427290(puVar8,1,puVar6);
        _Memory = pvStack_6c;
      }
      else {
        *puVar8 = *puVar6;
        puStack_68 = puVar8 + 1;
      }
      puVar8 = puStack_68;
      FUN_0066f190(&uStack_28);
      puVar1 = puVar6 + 2;
      puVar6 = puVar6 + 0x16;
    } while (puVar1 != puStack_4c);
    pvVar7 = unaff_EBX;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  uStack_40 = 0;
  if (unaff_retaddr == 0) {
    FUN_00401740(s_btnlist_1_009d7d24,9);
    uVar2 = FUN_00404230(auStack_70);
    FUN_00401660(uVar2,0,0xffffffff);
  }
  else {
    FUN_00401740(s_btnlist_2_009d7d30,9);
    uVar2 = FUN_00404230(auStack_70);
    FUN_00401660(uVar2,0,0xffffffff);
  }
  if (0xf < uStack_58) {
    _free(pvStack_6c);
    return;
  }
  piVar3 = (int *)(**(code **)(**(int **)((int)pvVar7 + 4) + 0x34))(&pvStack_44);
  if (piVar3 != (int *)0x0) {
    unaff_EBP = (**(code **)(*piVar3 + 0x30))();
    if (in_ECX == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = -(int)in_ECX / 0x24;
    }
    if (in_ECX == (void *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = -(int)in_ECX / 0x24;
    }
    uVar5 = uVar5 >> 2;
    if ((uVar4 & 3) != 0) {
      uVar5 = uVar5 + 1;
    }
    FUN_0056cac0(uVar5);
    FUN_0056ec00(auStack_7e + -6);
  }
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  if (_Memory != (void *)0x0) {
    _free(_Memory);
    return;
  }
  if (in_ECX != (void *)0x0) {
    FUN_0066e900(in_ECX,0,auStack_7e + -6,unaff_EBP);
    _free(in_ECX);
    return;
  }
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  if (pvStack_54 == (void *)0x0) {
    return;
  }
  FUN_0066e9a0(pvStack_54,puStack_50,&uStack_58,unaff_EBP);
  _free(pvStack_54);
  return;
}


// ==== FUN_0066e030 @ 0x0066e030 ====

void FUN_0066e030(void)

{
  int in_ECX;
  
  FUN_0066dd40(*(undefined1 *)(in_ECX + 0xc));
  return;
}


// ==== FUN_0066e040 @ 0x0066e040 ====

void FUN_0066e040(void)

{
  int *piVar1;
  int *piVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  undefined4 unaff_EDI;
  undefined1 local_54 [4];
  void *local_50;
  void *pvStack_48;
  void *pvStack_44;
  uint local_40;
  uint local_3c;
  uint uStack_34;
  uint uStack_30;
  void *apvStack_2c [4];
  undefined4 uStack_1c;
  uint uStack_18;
  
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  FUN_00401740(s_UI_Game2_NewCashShop_ui_newcashs_009d7bc8,0x2a);
  piVar1 = (int *)FUN_00410500(local_54);
  if (0xf < local_3c) {
    _free(local_50);
    return;
  }
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(piVar1 + 0xf,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 8))(1);
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  pvVar3 = operator_new(8);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_006da380(*(undefined4 *)(in_ECX + 4));
  }
  *(undefined4 *)(in_ECX + 8) = uVar4;
  FUN_0066d830(0);
  FUN_0066dd40(0);
  apvStack_2c[0] = (void *)0xf;
  uStack_30 = 0;
  local_40 = local_40 & 0xffffff00;
  FUN_00401740(s_btn_buyInfo_009d7bf4,0xb);
  (**(code **)(*DAT_00b5ae74 + 0x44))();
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_44);
  if (((piVar2 != (int *)0x0) && (iVar5 = (**(code **)(*piVar2 + 0x30))(), iVar5 != 0)) &&
     (*(char *)(iVar5 + 0x10b) != (char)unaff_EDI)) {
    FUN_00558130(unaff_EDI);
    FUN_005586a0();
  }
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_lbl_curMycash_009d7c00,0xd);
  uVar4 = (**(code **)(*DAT_00b5ae74 + 0x44))();
  uVar4 = FUN_004041a0(apvStack_2c,uVar4);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_48);
  if ((piVar2 != (int *)0x0) && (iVar5 = (**(code **)(*piVar2 + 0x30))(), iVar5 != 0)) {
    FUN_0055a260(uVar4);
  }
  if (0xf < uStack_18) {
    _free(apvStack_2c[0]);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  apvStack_2c[0] = (void *)((uint)apvStack_2c[0] & 0xffffff00);
  if (0xf < uStack_34) {
    _free(pvStack_48);
    return;
  }
  FUN_0066db20();
  if (piVar1 != (int *)0x0) {
    iVar5 = (**(code **)(*piVar1 + 4))();
    *(undefined4 *)(iVar5 + 0x28) = 0;
    (**(code **)(*DAT_00b5a7cc + 0x2c))(piVar1);
  }
  return;
}


// ==== FUN_0066e240 @ 0x0066e240 ====

undefined4 FUN_0066e240(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  void *pvVar6;
  int *in_ECX;
  uint uVar7;
  int unaff_retaddr;
  void *pvStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_34;
  undefined4 uStack_30;
  void *apvStack_2c [4];
  undefined4 uStack_1c;
  uint uStack_18;
  
  cVar1 = (**(code **)(*DAT_00b5ae74 + 0x2c))();
  if (cVar1 != '\0') {
    return 1;
  }
  FUN_0066db20();
  if (((int *)in_ECX[2] != (int *)0x0) &&
     (cVar1 = (**(code **)(*(int *)in_ECX[2] + 0x10))(param_1,param_2,param_3,param_4),
     cVar1 != '\0')) {
    return 1;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  uStack_44 = uStack_44 & 0xffffff00;
  FUN_00401740(s_lbl_curMycash_009d7c40,0xd);
  uVar3 = (**(code **)(*DAT_00b5ae74 + 0x44))();
  uVar3 = FUN_004041a0(apvStack_2c,uVar3);
  piVar4 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(&pvStack_48);
  if ((piVar4 != (int *)0x0) && (iVar5 = (**(code **)(*piVar4 + 0x30))(), iVar5 != 0)) {
    FUN_0055a260(uVar3);
  }
  if (0xf < uStack_18) {
    _free(apvStack_2c[0]);
    return extraout_EAX;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  apvStack_2c[0] = (void *)((uint)apvStack_2c[0] & 0xffffff00);
  if (0xf < uStack_34) {
    _free(pvStack_48);
    return extraout_EAX_00;
  }
  if (unaff_retaddr == 1) {
    if (param_2 == 1) {
      cVar1 = FUN_004036a0(1,s_btn_exit_009d7c50);
      if (cVar1 == '\0') {
        cVar1 = FUN_004036a0(1,s_btn_banner1_009d7c5c);
        if (cVar1 == '\0') {
          cVar1 = FUN_004036a0(1,s_btn_banner2_009d7c68);
          if (cVar1 == '\0') {
            cVar1 = FUN_004036a0(1,s_btn_buyInfo_009d7c74);
            if (cVar1 != '\0') {
              FUN_00401830(s_btn_buyInfo_009d7c80);
              FUN_0066d430(&uStack_30,0);
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            cVar1 = FUN_004036a0(1,s_btn_tab_0_009d7ca4);
            if (cVar1 != '\0') {
              if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
                (*(code *)**(undefined4 **)in_ECX[2])(1);
              }
              in_ECX[2] = 0;
              pvVar6 = operator_new(8);
              if (pvVar6 == (void *)0x0) {
                in_ECX[2] = 0;
                FUN_0066d830(0);
                FUN_0066dd40(0);
                return 1;
              }
              iVar5 = FUN_006da380(in_ECX[1]);
              in_ECX[2] = iVar5;
              FUN_0066d830(0);
              FUN_0066dd40(0);
              return 1;
            }
            cVar1 = FUN_004036a0(1,s_btn_tab_1_009d7cb0);
            if (cVar1 != '\0') {
              if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
                (*(code *)**(undefined4 **)in_ECX[2])(1);
              }
              in_ECX[2] = 0;
              pvVar6 = operator_new(8);
              if (pvVar6 == (void *)0x0) {
                iVar5 = 0;
              }
              else {
                iVar5 = FUN_006da2c0(in_ECX[1]);
              }
              in_ECX[2] = iVar5;
              FUN_0066d830(1);
              FUN_0066dd40(1);
              FUN_0066d7a0();
              return 1;
            }
            cVar1 = FUN_004036a0(1,s_btn_tab_2_009d7cbc);
            if (cVar1 != '\0') {
              if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
                (*(code *)**(undefined4 **)in_ECX[2])(1);
              }
              in_ECX[2] = 0;
              pvVar6 = operator_new(8);
              if (pvVar6 == (void *)0x0) {
                iVar5 = 0;
              }
              else {
                iVar5 = FUN_006da200(in_ECX[1]);
              }
              in_ECX[2] = iVar5;
              FUN_0066d830(2);
              FUN_0066dd40(2);
              FUN_0066d7a0();
              return 1;
            }
            cVar1 = FUN_004036a0(1,s_btn_tab_3_009d7cc8);
            if (cVar1 != '\0') {
              if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
                (*(code *)**(undefined4 **)in_ECX[2])(1);
              }
              in_ECX[2] = 0;
              pvVar6 = operator_new(8);
              if (pvVar6 == (void *)0x0) {
                iVar5 = 0;
              }
              else {
                iVar5 = FUN_006da140(in_ECX[1]);
              }
              in_ECX[2] = iVar5;
              FUN_0066d830(3);
              FUN_0066dd40(3);
              FUN_0066d7a0();
              return 1;
            }
            cVar1 = FUN_004036a0(1,s_btn_tab_4_009d7cd4);
            if (cVar1 == '\0') {
              return 0;
            }
            if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
              (*(code *)**(undefined4 **)in_ECX[2])(1);
            }
            in_ECX[2] = 0;
            pvVar6 = operator_new(8);
            if (pvVar6 == (void *)0x0) {
              iVar5 = 0;
            }
            else {
              iVar5 = FUN_006da080(in_ECX[1]);
            }
            in_ECX[2] = iVar5;
            FUN_0066d830(4);
            FUN_0066dd40(4);
            FUN_0066d7a0();
            return 1;
          }
          iVar5 = (**(code **)(*DAT_00b5ae78 + 0x34))();
          pvStack_48 = *(void **)(iVar5 + 4);
          uStack_44 = *(uint *)(iVar5 + 8);
          uStack_40 = *(undefined4 *)(iVar5 + 0xc);
          uVar7 = *(uint *)(iVar5 + 0x10);
          bVar2 = (byte)uVar7;
        }
        else {
          iVar5 = (**(code **)(*DAT_00b5ae78 + 0x34))();
          pvStack_48 = *(void **)(iVar5 + 4);
          uVar7 = *(uint *)(iVar5 + 8);
          bVar2 = (byte)uVar7;
          uStack_40 = *(undefined4 *)(iVar5 + 0xc);
          uStack_3c = *(undefined4 *)(iVar5 + 0x10);
        }
        if ((bVar2 != 0) && (bVar2 < 6)) {
          uVar7 = uVar7 & 0xff;
          FUN_0066d470(uVar7);
          FUN_0066d830(uVar7);
          FUN_0066dd40(uVar7);
        }
        return 1;
      }
      (**(code **)(*in_ECX + 0x10))();
    }
  }
  else if ((unaff_retaddr == 0x1a) && (param_2 == 1)) {
    uVar3 = (**(code **)(*DAT_00b5ae78 + 8))((char)in_ECX[3]);
    FUN_0066f030(uVar3);
    uVar7 = FUN_0066e800();
    if (1 < uVar7) {
      uVar3 = FUN_00696050(1);
      FUN_0066e880(uVar3);
      (**(code **)(*DAT_00b5ae78 + 0x18))(uStack_34);
      (**(code **)(*DAT_00b5ae74 + 0x10))();
      FUN_00446ee0();
    }
    FUN_0066f0e0();
    return 1;
  }
  return 0;
}


// ==== FUN_0066e7c0 @ 0x0066e7c0 ====

void FUN_0066e7c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7d7c;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  *(undefined1 *)((int)in_ECX + 0xd) = 1;
  FUN_0066e040();
  return;
}


// ==== FUN_0066e7e0 @ 0x0066e7e0 ====

int FUN_0066e7e0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x24;
}


// ==== FUN_0066e800 @ 0x0066e800 ====

int FUN_0066e800(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x2c;
}


// ==== FUN_0066e820 @ 0x0066e820 ====

undefined4 FUN_0066e820(void)

{
  return 0x3f;
}


// ==== FUN_0066e830 @ 0x0066e830 ====

void FUN_0066e830(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d7d7c;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0066e880 @ 0x0066e880 ====

void FUN_0066e880(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401660(param_1 + 1,0,0xffffffff);
  in_ECX[8] = param_1[8];
  in_ECX[9] = param_1[9];
  *(undefined2 *)(in_ECX + 10) = *(undefined2 *)(param_1 + 10);
  *(undefined1 *)((int)in_ECX + 0x2a) = *(undefined1 *)((int)param_1 + 0x2a);
  return;
}


// ==== FUN_0066e8d0 @ 0x0066e8d0 ====

void FUN_0066e8d0(int param_1)

{
  if (*(uint *)(param_1 + 0x1c) < 0x10) {
    *(undefined4 *)(param_1 + 0x1c) = 0xf;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined1 *)(param_1 + 8) = 0;
    return;
  }
  _free(*(void **)(param_1 + 8));
  return;
}


// ==== FUN_0066e900 @ 0x0066e900 ====

void FUN_0066e900(int param_1,int param_2)

{
  uint *puVar1;
  
  if (param_1 != param_2) {
    puVar1 = (uint *)(param_1 + 0x1c);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      param_1 = param_1 + 0x24;
      puVar1 = puVar1 + 9;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_0066e950 @ 0x0066e950 ====

undefined4 * FUN_0066e950(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x24;
    puVar2 = param_3 + -9;
    *puVar2 = *(undefined4 *)(param_2 + -0x24);
    FUN_00401660(param_2 + -0x20,0,0xffffffff);
    *(undefined2 *)(param_3 + -1) = *(undefined2 *)(param_2 + -4);
    *(undefined1 *)((int)param_3 + -2) = *(undefined1 *)(param_2 + -2);
    param_2 = iVar1;
    param_3 = puVar2;
  } while (iVar1 != param_1);
  return puVar2;
}


// ==== FUN_0066e9a0 @ 0x0066e9a0 ====

void FUN_0066e9a0(int param_1,int param_2)

{
  uint *puVar1;
  
  if (param_1 != param_2) {
    puVar1 = (uint *)(param_1 + 0x1c);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      param_1 = param_1 + 0x2c;
      puVar1 = puVar1 + 0xb;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_0066e9f0 @ 0x0066e9f0 ====

void FUN_0066e9f0(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[7] = 0xf;
    param_1[6] = 0;
    *(undefined1 *)(param_1 + 2) = 0;
    FUN_00401660(param_2 + 1,0,0xffffffff);
    *(undefined2 *)(param_1 + 8) = *(undefined2 *)(param_2 + 8);
    *(undefined1 *)((int)param_1 + 0x22) = *(undefined1 *)((int)param_2 + 0x22);
  }
  return;
}


// ==== FUN_0066ea40 @ 0x0066ea40 ====

int FUN_0066ea40(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c590;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x24) {
    FUN_0066e9f0(param_3,param_1);
    param_3 = param_3 + 0x24;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0066eaaa @ 0x0066eaaa ====

void Catch_0066eaaa(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x24) {
    FUN_0066e8d0(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0066ead0 @ 0x0066ead0 ====

void FUN_0066ead0(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    FUN_0066e880(param_2);
  }
  return;
}


// ==== FUN_0066eaf0 @ 0x0066eaf0 ====

void FUN_0066eaf0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_1 = *param_3;
      FUN_00401660(param_3 + 1,0,0xffffffff);
      *(undefined2 *)(param_1 + 8) = *(undefined2 *)(param_3 + 8);
      *(undefined1 *)((int)param_1 + 0x22) = *(undefined1 *)((int)param_3 + 0x22);
      param_1 = param_1 + 9;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_0066eb40 @ 0x0066eb40 ====

void FUN_0066eb40(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c5a0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_0066e9f0(param_1,param_3);
    param_1 = param_1 + 0x24;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0066ebaa @ 0x0066ebaa ====

void Catch_0066ebaa(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x24) {
    FUN_0066e8d0(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0066ebd0 @ 0x0066ebd0 ====

int FUN_0066ebd0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c5b0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x2c) {
    FUN_0066ead0(param_3,param_1);
    param_3 = param_3 + 0x2c;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0066ec3a @ 0x0066ec3a ====

void Catch_0066ec3a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x2c) {
    FUN_0066e8d0(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0066ec60 @ 0x0066ec60 ====

void FUN_0066ec60(undefined4 param_1,undefined4 param_2)

{
  FUN_0066e900(param_1,param_2);
  return;
}


// ==== FUN_0066ec80 @ 0x0066ec80 ====

void FUN_0066ec80(undefined4 param_1,undefined4 param_2)

{
  FUN_0066e9a0(param_1,param_2);
  return;
}


// ==== FUN_0066eca0 @ 0x0066eca0 ====

void FUN_0066eca0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0066ea40(param_1,param_2,param_3);
  return;
}


// ==== FUN_0066ecc0 @ 0x0066ecc0 ====

int FUN_0066ecc0(int param_1,int param_2,undefined4 param_3)

{
  FUN_0066eb40(param_1,param_2,param_3);
  return param_1 + param_2 * 0x24;
}


// ==== FUN_0066ecf0 @ 0x0066ecf0 ====

void FUN_0066ecf0(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint extraout_ECX;
  undefined4 local_64;
  void *local_5c;
  undefined4 local_4c;
  uint local_48;
  undefined2 local_44;
  undefined1 local_42;
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
  puStack_c = &LAB_0098c5c0;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x70);
  local_64 = *param_3;
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3 + 1,0,0xffffffff);
  local_44 = *(undefined2 *)(param_3 + 8);
  local_42 = *(undefined1 *)((int)param_3 + 0x22);
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
      local_18 = (void *)FUN_0066eca0(*(undefined4 *)(in_ECX + 4),param_1,local_1c);
      local_18 = (void *)FUN_0066ecc0(local_18,param_2,&local_64);
      FUN_0066eca0(param_1,*(undefined4 *)(in_ECX + 8),local_18);
      local_8 = 0xffffffff;
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
      }
      if (iVar2 != 0) {
        FUN_0066e900(iVar2,*(undefined4 *)(in_ECX + 8));
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
        FUN_0066ea40(param_1,local_2c,local_28 + param_1);
        local_8 = 2;
        FUN_0066ecc0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x24,
                     &local_64);
        local_8 = 0xffffffff;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_28;
        FUN_0066eaf0(param_1,*(int *)(in_ECX + 8) - local_28,&local_64);
      }
      else {
        local_30 = local_2c + param_2 * -0x24;
        uVar3 = FUN_0066ea40(local_30,local_2c,local_2c);
        *(undefined4 *)(in_ECX + 8) = uVar3;
        FUN_0066e950(param_1,local_30,local_2c,local_40);
        FUN_0066eaf0(param_1,param_2 * 0x24 + param_1,&local_64);
      }
    }
  }
  if (local_48 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_5c);
  return;
}


// ==== Catch@0066eecb @ 0x0066eecb ====

void Catch_0066eecb(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_0066ec60(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@0066ef7f @ 0x0066ef7f ====

void Catch_0066ef7f(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x24;
  FUN_0066ec60(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x1c) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0066f010 @ 0x0066f010 ====

void FUN_0066f010(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0066ebd0(param_1,param_2,param_3);
  return;
}


// ==== FUN_0066f030 @ 0x0066f030 ====

void FUN_0066f030(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c5d0;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x2c;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_00696090(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_0066f010(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0066f0c7 @ 0x0066f0c7 ====

void Catch_0066f0c7(void)

{
  FUN_0066f0e0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0066f0e0 @ 0x0066f0e0 ====

void FUN_0066f0e0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  FUN_0066e9a0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0066f120 @ 0x0066f120 ====

void FUN_0066f120(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x24 != 0) {
      iVar1 = (param_2 - iVar1) / 0x24;
      goto LAB_0066f165;
    }
  }
  iVar1 = 0;
LAB_0066f165:
  FUN_0066ecf0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x24;
  return;
}


// ==== FUN_0066f190 @ 0x0066f190 ====

void FUN_0066f190(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x24) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x24))) {
    FUN_0066f120(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0066eb40(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x24;
  return;
}


// ==== FUN_0066f220 @ 0x0066f220 ====

void FUN_0066f220(void)

{
  return;
}


// ==== FUN_0066f230 @ 0x0066f230 ====

undefined1 FUN_0066f230(void)

{
  return 0;
}


// ==== FUN_0066f240 @ 0x0066f240 ====

void FUN_0066f240(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7e78;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0066f260 @ 0x0066f260 ====

undefined4 FUN_0066f260(void)

{
  (**(code **)(*DAT_00b5aca8 + 0xa0))();
  return 1;
}


// ==== FUN_0066f280 @ 0x0066f280 ====

undefined4 FUN_0066f280(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *in_ECX;
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_yes_009d7e68,7);
  if (iVar1 == 0) {
    (**(code **)(*DAT_00b5aca8 + 0x100))();
    return 1;
  }
  (**(code **)(*in_ECX + 0x10))();
  return 1;
}


// ==== FUN_0066f2e0 @ 0x0066f2e0 ====

void FUN_0066f2e0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_Guild_ui_LevelUpWnd_txt_009d7de8,0x20);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0066f360 @ 0x0066f360 ====

void FUN_0066f360(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7e78;
  FUN_0066f2e0();
  return;
}


// ==== FUN_0066f380 @ 0x0066f380 ====

void FUN_0066f380(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 auStack_7e [10];
  undefined1 auStack_74 [4];
  void *local_70;
  undefined1 local_6c;
  undefined1 auStack_68 [4];
  void *pvStack_64;
  undefined4 uStack_60;
  uint local_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  uint uStack_50;
  undefined1 auStack_3c [4];
  undefined1 uStack_38;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined1 uStack_1c;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  local_58 = 0xf;
  local_5c = 0;
  local_6c = 0;
  FUN_00401740(s_textbox_009d7e0c,7);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_70);
  if (0xf < local_5c) {
    _free(local_70);
    return;
  }
  local_5c = 0xf;
  uStack_60 = 0;
  local_70 = (void *)((uint)local_70 & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      uStack_24 = 0xf;
      uStack_28 = 0;
      uStack_38 = 0;
      uStack_8 = 0xf;
      uStack_c = 0;
      uStack_1c = 0;
      FUN_00401740(s_<GUILD_LEV>_009d7e14,0xb);
      FUN_00401740(s_<color_f4be3d>_dLv<_color>_009d7e20,0x1a);
      uVar3 = FUN_00404230(auStack_74);
      FUN_00401660(uVar3,0,0xffffffff);
      if (0xf < local_5c) {
        _free(local_70);
        return;
      }
      FUN_004e6c20(auStack_3c);
      FUN_00401740(s_<GUILD_POINT>_009d7e3c,0xd);
      FUN_00401740(s_<color_f4be3d>_d<_color>_009d7e4c,0x18);
      uVar3 = FUN_00404230(auStack_74);
      FUN_00401660(uVar3,0,0xffffffff);
      if (0xf < local_5c) {
        _free(local_70);
        return;
      }
      FUN_004e6c20(auStack_3c);
      (**(code **)(*DAT_00b5a794 + 8))(&local_58,0,0x8200b9,auStack_7e + -6);
      FUN_005569f0(auStack_68,0);
      if (0xf < uStack_50) {
        _free(pvStack_64);
        return;
      }
      uStack_50 = 0xf;
      uStack_54 = 0;
      pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
      FUN_0040a7d0();
      FUN_004e67a0();
    }
  }
  return;
}


// ==== FUN_0066f570 @ 0x0066f570 ====

undefined4 FUN_0066f570(void)

{
  return 0x30;
}


// ==== FUN_0066f580 @ 0x0066f580 ====

void FUN_0066f580(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d7e78;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0066f5c0 @ 0x0066f5c0 ====

undefined4 FUN_0066f5c0(void)

{
  return 0x70320007;
}


// ==== FUN_0066f5d0 @ 0x0066f5d0 ====

undefined4 FUN_0066f5d0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar1 = &PTR_FUN_009d7f70;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_0066f600 @ 0x0066f600 ====

void FUN_0066f600(void)

{
  return;
}


// ==== FUN_0066f610 @ 0x0066f610 ====

undefined1 FUN_0066f610(void)

{
  return 0;
}


// ==== FUN_0066f620 @ 0x0066f620 ====

void FUN_0066f620(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7f84;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0066f680 @ 0x0066f680 ====

void FUN_0066f680(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  void *unaff_EBX;
  undefined4 local_38;
  uint uStack_28;
  uint uStack_24;
  void *pvStack_20;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_lbl_guildPoint_009d7f08,0xe);
  FUN_004041a0(&local_38,param_1);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x30))();
    if (iVar3 != 0) {
      FUN_0055a260((int)register0x00000010 + -0x3c);
    }
  }
  if (0xf < uStack_24) {
    _free(local_38);
    return;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  uVar1 = (uint)local_38 >> 8;
  local_38 = (void *)(uVar1 << 8);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  local_38 = (void *)(uVar1 << 8);
  FUN_00401740(s_lbl_advan_009d7f1c,9);
  FUN_00401740(&DAT_009d7f18,2);
  FUN_00404230(&pvStack_20);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x3c);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x30))();
    if (iVar3 != 0) {
      FUN_0055a260(&uStack_24);
    }
  }
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
  _free(unaff_EBX);
  return;
}


// ==== FUN_0066f7d0 @ 0x0066f7d0 ====

void FUN_0066f7d0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_edit_point_009d7f28,10);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    puVar2 = operator_new(8);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009b1798;
    }
    uVar3 = (**(code **)(*piVar1 + 4))();
    puVar2[1] = uVar3;
    FUN_00797a20(puVar2);
    (**(code **)(*piVar1 + 0x5c))();
  }
  return;
}


// ==== FUN_0066f870 @ 0x0066f870 ====

undefined4 FUN_0066f870(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined1 local_1c [28];
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009d7f34,8);
  if ((iVar2 != 0) && (cVar1 = FUN_004036a0(param_2,s_btn_cancel_009d7f40), cVar1 == '\0')) {
    cVar1 = FUN_004036a0(param_2,s_btn_givePoint_009d7f4c);
    if (cVar1 != '\0') {
      FUN_00401830(s_edit_point_009d7f5c);
      (**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_1c);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    return 0;
  }
  puVar3 = operator_new(4);
  if (puVar3 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar3 = &PTR_FUN_009d7f70;
  FUN_00797a20(puVar3);
  return 1;
}


// ==== FUN_0066f9d0 @ 0x0066f9d0 ====

void FUN_0066f9d0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_Guild_ui_givepointwnd_t_009d7ee4,0x22);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_0066f7d0();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0066fa50 @ 0x0066fa50 ====

void FUN_0066fa50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d7f84;
  FUN_0066f9d0();
  return;
}


// ==== FUN_0066fa70 @ 0x0066fa70 ====

undefined4 FUN_0066fa70(void)

{
  return 0x33;
}


// ==== FUN_0066fa80 @ 0x0066fa80 ====

void FUN_0066fa80(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d7f84;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0066fac0 @ 0x0066fac0 ====

void FUN_0066fac0(void)

{
  return;
}


// ==== FUN_0066fad0 @ 0x0066fad0 ====

undefined1 FUN_0066fad0(void)

{
  return 0;
}


// ==== FUN_0066fae0 @ 0x0066fae0 ====

void FUN_0066fae0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d8058;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0066fb00 @ 0x0066fb00 ====

undefined4 FUN_0066fb00(void)

{
  (**(code **)(*DAT_00b5aca8 + 0x48))();
  return 1;
}


// ==== FUN_0066fb10 @ 0x0066fb10 ====

undefined4 FUN_0066fb10(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009d8034,8);
  if (iVar2 != 0) {
    cVar1 = FUN_004036a0(param_2,s_btn_yes_009d8040);
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5aca8 + 0xe0))(*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc))
      ;
      (**(code **)(*DAT_00b5aca8 + 0x58))();
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_no_009d8048);
    if (cVar1 == '\0') {
      return 0;
    }
  }
  (**(code **)(*DAT_00b5aca8 + 0x58))();
  return 1;
}


// ==== FUN_0066fbb0 @ 0x0066fbb0 ====

void FUN_0066fbb0(void *param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  uint in_stack_00000018;
  undefined4 in_stack_0000001c;
  undefined4 *puStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puStack_10 = &param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      puStack_10 = *(undefined4 **)(iVar2 + 0x8c);
      uStack_c = *(undefined4 *)(iVar2 + 0x90);
      uStack_8 = in_stack_0000001c;
      FUN_00587d40(&puStack_10);
    }
  }
  if (in_stack_00000018 < 0x10) {
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_0066fc20 @ 0x0066fc20 ====

void FUN_0066fc20(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_2;
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  FUN_00401740(s_pan_markBg_009d8018,10);
  FUN_0066fbb0();
  FUN_00401740(s_pan_markIcon_009d8024,0xc);
  FUN_0066fbb0();
  return;
}


// ==== FUN_0066fc90 @ 0x0066fc90 ====

void FUN_0066fc90(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_Guild_ui_markconfirmwnd_009d7ff0,0x24);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0066fd10 @ 0x0066fd10 ====

void FUN_0066fd10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d8058;
  FUN_0066fc90();
  return;
}


// ==== FUN_0066fd30 @ 0x0066fd30 ====

undefined4 FUN_0066fd30(void)

{
  return 0x35;
}


// ==== FUN_0066fd40 @ 0x0066fd40 ====

void FUN_0066fd40(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d8058;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0066fd80 @ 0x0066fd80 ====

undefined4 FUN_0066fd80(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar1 = &PTR_FUN_009d7f70;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_0066fdb0 @ 0x0066fdb0 ====

void FUN_0066fdb0(void)

{
  return;
}


// ==== FUN_0066fdc0 @ 0x0066fdc0 ====

undefined1 FUN_0066fdc0(void)

{
  return 0;
}


// ==== FUN_0066fdd0 @ 0x0066fdd0 ====

void FUN_0066fdd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d8144;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0066fdf0 @ 0x0066fdf0 ====

undefined4 FUN_0066fdf0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009d8128,8);
  if ((iVar2 != 0) && (cVar1 = FUN_004036a0(param_2,s_btn_yes_009d8134), cVar1 == '\0')) {
    return 0;
  }
  puVar3 = operator_new(4);
  if (puVar3 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar3 = &PTR_FUN_009d7f70;
  FUN_00797a20(puVar3);
  return 1;
}


// ==== FUN_0066feb0 @ 0x0066feb0 ====

/* WARNING: Removing unreachable block (ram,0x00670178) */
/* WARNING: Removing unreachable block (ram,0x006700e5) */

void FUN_0066feb0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  undefined4 uStack_4c;
  undefined4 local_38;
  void *pvStack_2c;
  void *pvStack_28;
  void *local_24;
  void *local_20;
  void *local_1c;
  uint local_18;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  uStack_4c = (void **)0xe;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = local_18 & 0xffffff00;
  FUN_00401740(s_lbl_memberName_009d80e8);
  uStack_4c = (void **)0xffffffff;
  local_20 = (void *)0xf;
  local_24 = (void *)0x0;
  FUN_00401660(param_1,0);
  uStack_4c = &local_1c;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    FUN_0055a260((int)register0x00000010 + -0x3c);
  }
  if ((void *)0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = (void *)0xf;
  pvStack_28 = (void *)0x0;
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(s_lbl_class_009d80f8,9);
  local_24 = (void *)0xf;
  pvStack_28 = (void *)0x0;
  FUN_00401660(param_1,0,0xffffffff);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_20);
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    FUN_0055a260((int)register0x00000010 + -0x40);
  }
  if ((void *)0xf < pvStack_28) {
    _free(unaff_EBX);
    return;
  }
  pvStack_28 = (void *)0xf;
  pvStack_2c = (void *)0x0;
  if (0xf < uStack_c) {
    _free(local_20);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(s_lbl_grade_009d8104,9);
  pvStack_28 = (void *)0xf;
  pvStack_2c = (void *)0x0;
  FUN_00401660(param_1,0,0xffffffff);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_24);
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    FUN_0055a260((int)register0x00000010 + -0x44);
  }
  if ((void *)0xf < pvStack_2c) {
    _free(unaff_EBP);
    return;
  }
  pvStack_2c = (void *)0xf;
  if (0xf < uStack_10) {
    _free(local_24);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_lbl_peerage_009d8110,0xb);
  pvStack_2c = (void *)0xf;
  FUN_00401660(param_1,0,0xffffffff);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_28);
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    FUN_0055a260((int)register0x00000010 + -0x48);
  }
  if (0xf < uStack_14) {
    _free(pvStack_28);
    return;
  }
  uStack_14 = 0xf;
  local_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  FUN_00401740(s_lbl_level_009d811c,9);
  FUN_00401660(param_1,0,0xffffffff);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_2c);
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    FUN_0055a260(&uStack_4c);
  }
  if (local_18 < 0x10) {
    return;
  }
  _free(pvStack_2c);
  return;
}


