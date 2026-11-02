// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x8c0000-0x8cffff

// ==== FUN_008c01aa @ 0x008c01aa ====

void FUN_008c01aa(void)

{
  char *pcVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  bool bVar6;
  
  FUN_008f336d(0x100000,0x10000);
  FUN_008bcb44();
  *(undefined4 *)(in_ECX + 0x2a4) = 0;
  FUN_008bf82e();
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 1;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 1;
  *(undefined4 *)(in_ECX + 0x50) = 1;
  *(undefined4 *)(in_ECX + 0x54) = 1;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 0x268) = 0;
  *(undefined4 *)(in_ECX + 0x26c) = 0;
  puVar4 = (undefined4 *)(in_ECX + 0x6c);
  for (iVar3 = 0x7f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)(in_ECX + 0x278);
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 *)(in_ECX + 0x298) = 1;
  pcVar1 = (char *)FUN_008015fc(4,0);
  pcVar1 = __strdup(pcVar1);
  *(char **)(in_ECX + 0x29c) = pcVar1;
  if (pcVar1 != (char *)0x0) {
    iVar3 = 2;
    bVar6 = true;
    pcVar5 = &DAT_009fe224;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar1 == *pcVar5;
      pcVar1 = pcVar1 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) goto LAB_008c0265;
  }
  FUN_008015fc(4,&DAT_009fe224);
LAB_008c0265:
  uVar2 = __controlfp(0,0);
  *(uint *)(in_ECX + 0x2a0) = uVar2;
  __controlfp(0xffffffff,0x8001f);
  __controlfp(0,0x30000);
  FUN_007a42e8();
  return;
}


// ==== FUN_008c0297 @ 0x008c0297 ====

void FUN_008c0297(void)

{
  char *pcVar1;
  int in_ECX;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  bool bVar6;
  
  if (*(int *)(in_ECX + 0x3c) != 0) {
    FUN_008be480(1);
  }
  if (*(int *)(in_ECX + 0x68) != 0) {
    FUN_008be445(1);
  }
  if (*(int *)(in_ECX + 0x268) != 0) {
    FUN_008be180(1);
  }
  piVar2 = (int *)(in_ECX + 0x6c);
  iVar4 = 0x7f;
  do {
    if (*piVar2 != 0) {
      FUN_008bf80d(1);
    }
    piVar2 = piVar2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  pcVar1 = *(char **)(in_ECX + 0x29c);
  if (pcVar1 != (char *)0x0) {
    iVar4 = 2;
    bVar6 = true;
    pcVar3 = pcVar1;
    pcVar5 = &DAT_009fe224;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar6 = *pcVar3 == *pcVar5;
      pcVar3 = pcVar3 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (!bVar6) {
      FUN_008015fc(4,pcVar1);
    }
  }
  if (*(void **)(in_ECX + 0x29c) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x29c));
    return;
  }
  __controlfp(*(uint *)(in_ECX + 0x2a0),0xb001f);
  if (*(int *)(in_ECX + 0x2a4) != 0) {
    FUN_008bf855();
  }
  FUN_008bcb64();
  FUN_008f33c5();
  return;
}


// ==== FUN_008c034d @ 0x008c034d ====

int FUN_008c034d(void)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined4 *puVar10;
  bool bVar11;
  undefined4 local_2c [8];
  int local_c;
  undefined4 local_8;
  
  if ((*(int *)(in_ECX + 0x40) != 0) || (*(int *)(in_ECX + 0x48) != 0)) {
    *(undefined4 *)(in_ECX + 0x278) = 0xc;
    return -1;
  }
  iVar5 = *(int *)(in_ECX + 100);
  if (iVar5 == 0) {
    iVar5 = FUN_008bde0c(*(uint *)(in_ECX + 0x298) | 4,in_ECX + 0x278);
    if (iVar5 < 0) {
      return -1;
    }
  }
  else {
    puVar8 = (undefined4 *)(iVar5 + 0x10);
    puVar10 = (undefined4 *)(in_ECX + 0x278);
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar10 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar10 = puVar10 + 1;
    }
    *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(iVar5 + 0xc);
    *(undefined4 *)(iVar5 + 0xc) = 0;
  }
  iVar5 = *(int *)(in_ECX + 0x278);
  if (iVar5 == 1) {
    cVar1 = *(char *)(in_ECX + 0x281);
    if (cVar1 == '\0') {
      return (int)*(char *)(in_ECX + 0x280);
    }
    if (*(char *)(in_ECX + 0x282) == '\0') {
      if (cVar1 == '=') {
        cVar1 = *(char *)(in_ECX + 0x280);
        if (cVar1 == '!') {
          return 0x113;
        }
        if (cVar1 == '<') {
          return 0x110;
        }
        if (cVar1 == '=') {
          return 0x112;
        }
        if (cVar1 == '>') {
          return 0x111;
        }
      }
      else {
        cVar2 = *(char *)(in_ECX + 0x280);
        if (cVar2 == cVar1) {
          if (cVar2 == '&') {
            return 0x114;
          }
          if (cVar2 == '|') {
            return 0x115;
          }
        }
      }
    }
    return 0x119;
  }
  if (iVar5 < 2) {
    return 0x119;
  }
  if (iVar5 < 5) {
    return 0x117;
  }
  if (iVar5 != 9) {
    if (iVar5 == 10) {
      return 0x118;
    }
    if ((iVar5 == 0xc) || (iVar5 == 0xd)) {
      *(undefined4 *)(in_ECX + 0x40) = 1;
      return -1;
    }
    return 0x119;
  }
  if (*(int *)(in_ECX + 0x4c) == 0) {
    iVar5 = 8;
    bVar11 = true;
    pcVar7 = *(char **)(in_ECX + 0x280);
    pcVar6 = s_defined_00a17b60;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar11 = *pcVar7 == *pcVar6;
      pcVar7 = pcVar7 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar11);
    if (bVar11) {
      *(undefined4 *)(in_ECX + 0x58) = 0;
      return 0x10f;
    }
    if (*(int *)(in_ECX + 0x58) == 0) {
      return 0x116;
    }
    iVar5 = FUN_008bf6b1(*(char **)(in_ECX + 0x280),&local_c,&local_8);
    if (iVar5 == 0) {
      return 0x116;
    }
    iVar5 = *(int *)(in_ECX + 0x44);
    puVar8 = (undefined4 *)(in_ECX + 0x278);
    puVar10 = local_2c;
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar10 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar10 = puVar10 + 1;
    }
    if ((iVar5 == 0) && (iVar5 = FUN_008bfae5(local_2c,local_c,local_8), iVar5 != 0)) {
      iVar5 = 0;
    }
    else {
      iVar5 = 1;
    }
    *(int *)(in_ECX + 0x44) = iVar5;
    if ((iVar5 == 0) && (local_c = FUN_008c034d(), local_c != -1)) {
      iVar5 = 0;
    }
    else {
      iVar5 = 1;
    }
    *(int *)(in_ECX + 0x44) = iVar5;
    if (iVar5 == 0) {
      return local_c;
    }
    *(undefined4 *)(in_ECX + 0x48) = 1;
    puVar8 = local_2c;
    puVar10 = (undefined4 *)(in_ECX + 0x278);
    for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar10 = puVar10 + 1;
    }
    FUN_008bd320(in_ECX + 0x18,(undefined4 *)(in_ECX + 0x278),0x5ee,
                 s_invalid_or_unsupported_integer_c_00a17a70);
    return 0x116;
  }
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  pcVar7 = *(char **)(in_ECX + 0x280);
  if (*(int *)(in_ECX + 0x50) == 0) {
    if (*pcVar7 != 'e') {
      if (*pcVar7 == 'i') {
        iVar5 = 3;
        bVar11 = true;
        pcVar6 = pcVar7;
        pcVar9 = &DAT_009fe794;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar11 = *pcVar6 == *pcVar9;
          pcVar6 = pcVar6 + 1;
          pcVar9 = pcVar9 + 1;
        } while (bVar11);
        if (bVar11) {
          return 0x10c;
        }
        iVar5 = 6;
        bVar11 = true;
        pcVar6 = pcVar7;
        pcVar9 = &DAT_00a17b90;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar11 = *pcVar6 == *pcVar9;
          pcVar6 = pcVar6 + 1;
          pcVar9 = pcVar9 + 1;
        } while (bVar11);
        if (bVar11) {
          return 0x10c;
        }
        iVar5 = 7;
        bVar11 = true;
        pcVar6 = &DAT_00a17b88;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar11 = *pcVar7 == *pcVar6;
          pcVar7 = pcVar7 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar11);
        if (bVar11) {
          return 0x10c;
        }
      }
LAB_008c0666:
      *(undefined4 *)(in_ECX + 0x4c) = 1;
      return 0x116;
    }
    iVar5 = 5;
    bVar11 = true;
    pcVar6 = pcVar7;
    pcVar9 = &DAT_009fe7a4;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar11 = *pcVar6 == *pcVar9;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    } while (bVar11);
    if (bVar11) {
      return 0x10a;
    }
    iVar5 = 6;
    bVar11 = true;
    pcVar6 = pcVar7;
    pcVar9 = s_endif_00a17b70;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar11 = *pcVar6 == *pcVar9;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    } while (bVar11);
    if (bVar11) {
      return 0x10b;
    }
    iVar5 = 5;
    bVar11 = true;
    pcVar6 = &DAT_00a17b78;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar11 = *pcVar7 == *pcVar6;
      pcVar7 = pcVar7 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar11);
    if (!bVar11) goto LAB_008c0666;
    piVar3 = *(int **)(*(int *)(in_ECX + 0x268) + 0x38);
    if (piVar3 != (int *)0x0) {
      if ((piVar3[1] == 0) || (*piVar3 != 0)) {
        return 0x10d;
      }
      *(int *)(in_ECX + 0x50) = piVar3[1];
      *(undefined4 *)(in_ECX + 0x58) = 1;
      return 0x109;
    }
    *(undefined4 *)(in_ECX + 0x50) = 1;
  }
  else {
    cVar1 = *pcVar7;
    if (cVar1 == 'd') {
      iVar5 = 7;
      bVar11 = true;
      pcVar6 = s_define_00a17b68;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar11 = *pcVar7 == *pcVar6;
        pcVar7 = pcVar7 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar11);
      if (bVar11) {
        return 0x101;
      }
      goto LAB_008c0666;
    }
    if (cVar1 != 'e') {
      if (cVar1 != 'i') {
        if (cVar1 == 'l') {
          iVar5 = 5;
          bVar11 = true;
          pcVar6 = &DAT_009fcf68;
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar11 = *pcVar7 == *pcVar6;
            pcVar7 = pcVar7 + 1;
            pcVar6 = pcVar6 + 1;
          } while (bVar11);
          if (bVar11) {
            return 0x103;
          }
        }
        else if (cVar1 == 'p') {
          iVar5 = 7;
          bVar11 = true;
          pcVar6 = s_pragma_00a17b98;
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar11 = *pcVar7 == *pcVar6;
            pcVar7 = pcVar7 + 1;
            pcVar6 = pcVar6 + 1;
          } while (bVar11);
          if (bVar11) {
            return 0x10e;
          }
        }
        else if (cVar1 == 'u') {
          iVar5 = 6;
          bVar11 = true;
          pcVar6 = s_undef_00a17ba0;
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar11 = *pcVar7 == *pcVar6;
            pcVar7 = pcVar7 + 1;
            pcVar6 = pcVar6 + 1;
          } while (bVar11);
          if (bVar11) {
            return 0x102;
          }
        }
        goto LAB_008c0666;
      }
      iVar5 = 3;
      bVar11 = true;
      pcVar6 = pcVar7;
      pcVar9 = &DAT_009fe794;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar11 = *pcVar6 == *pcVar9;
        pcVar6 = pcVar6 + 1;
        pcVar9 = pcVar9 + 1;
      } while (bVar11);
      if (!bVar11) {
        iVar5 = 6;
        bVar11 = true;
        pcVar6 = pcVar7;
        pcVar9 = &DAT_00a17b90;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar11 = *pcVar6 == *pcVar9;
          pcVar6 = pcVar6 + 1;
          pcVar9 = pcVar9 + 1;
        } while (bVar11);
        if (bVar11) {
          return 0x107;
        }
        iVar5 = 7;
        bVar11 = true;
        pcVar6 = pcVar7;
        pcVar9 = &DAT_00a17b88;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar11 = *pcVar6 == *pcVar9;
          pcVar6 = pcVar6 + 1;
          pcVar9 = pcVar9 + 1;
        } while (bVar11);
        if (bVar11) {
          return 0x108;
        }
        iVar5 = 8;
        bVar11 = true;
        pcVar6 = s_include_00a17b80;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar11 = *pcVar7 == *pcVar6;
          pcVar7 = pcVar7 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar11);
        if (bVar11) {
          return 0x104;
        }
        goto LAB_008c0666;
      }
      iVar5 = 0x106;
      goto LAB_008c0630;
    }
    iVar5 = 5;
    bVar11 = true;
    pcVar6 = pcVar7;
    pcVar9 = &DAT_00a17b78;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar11 = *pcVar6 == *pcVar9;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    } while (bVar11);
    if (!bVar11) {
      iVar5 = 5;
      bVar11 = true;
      pcVar6 = pcVar7;
      pcVar9 = &DAT_009fe7a4;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar11 = *pcVar6 == *pcVar9;
        pcVar6 = pcVar6 + 1;
        pcVar9 = pcVar9 + 1;
      } while (bVar11);
      if (bVar11) {
        return 0x10a;
      }
      iVar5 = 6;
      bVar11 = true;
      pcVar6 = pcVar7;
      pcVar9 = s_endif_00a17b70;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar11 = *pcVar6 == *pcVar9;
        pcVar6 = pcVar6 + 1;
        pcVar9 = pcVar9 + 1;
      } while (bVar11);
      if (bVar11) {
        return 0x10b;
      }
      iVar5 = 6;
      bVar11 = true;
      pcVar6 = s_error_009fdc5c;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar11 = *pcVar7 == *pcVar6;
        pcVar7 = pcVar7 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar11);
      if (bVar11) {
        return 0x105;
      }
      goto LAB_008c0666;
    }
  }
  iVar5 = 0x109;
LAB_008c0630:
  *(undefined4 *)(in_ECX + 0x58) = 1;
  return iVar5;
}


// ==== FUN_008c07e2 @ 0x008c07e2 ====

int FUN_008c07e2(int param_1,int *param_2)

{
  byte bVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  int iVar5;
  byte *pbVar6;
  char *pcVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  char *pcVar10;
  undefined4 *puVar11;
  bool bVar12;
  
  pvVar2 = operator_new(0x14);
  if (pvVar2 == (void *)0x0) {
    param_1 = 0;
  }
  else {
    param_1 = FUN_008be075(param_1,0,0);
  }
  if (param_1 != 0) {
    if (((param_2 != (int *)0x0) &&
        (pcVar7 = (char *)**(undefined4 **)(in_ECX + 0x26c),
        pcVar7 < (char *)(*(undefined4 **)(in_ECX + 0x26c))[1])) && (*pcVar7 == '(')) {
      param_2 = (int *)(param_1 + 4);
      iVar3 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),in_ECX + 0x278);
      if (iVar3 < 0) goto LAB_008c0a70;
      do {
        iVar3 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),(int *)(in_ECX + 0x278));
        if (iVar3 < 0) goto LAB_008c0a70;
        if (*(int *)(in_ECX + 0x278) != 9) goto LAB_008c0976;
        for (iVar3 = *(int *)(param_1 + 4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0xc)) {
          pbVar6 = *(byte **)(iVar3 + 0x18);
          pbVar9 = *(byte **)(in_ECX + 0x280);
          do {
            bVar1 = *pbVar9;
            bVar12 = bVar1 < *pbVar6;
            if (bVar1 != *pbVar6) {
LAB_008c08be:
              iVar5 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
              goto LAB_008c08c3;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar9[1];
            bVar12 = bVar1 < pbVar6[1];
            if (bVar1 != pbVar6[1]) goto LAB_008c08be;
            pbVar9 = pbVar9 + 2;
            pbVar6 = pbVar6 + 2;
          } while (bVar1 != 0);
          iVar5 = 0;
LAB_008c08c3:
          if (iVar5 == 0) {
            FUN_008bd320(in_ECX + 0x18,in_ECX + 0x278,0x5e7,
                         s_duplicate_macro_parameter___s__00a17ba8,*(undefined4 *)(in_ECX + 0x280));
            break;
          }
        }
        iVar3 = FUN_008bf738(0x30);
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = FUN_008f378b(in_ECX + 0x278);
        }
        *param_2 = iVar3;
        if (iVar3 == 0) goto LAB_008c0a4c;
        param_2 = (int *)(iVar3 + 0xc);
        iVar3 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),(int *)(in_ECX + 0x278));
        if (iVar3 < 0) goto LAB_008c0a70;
        if (*(int *)(in_ECX + 0x278) != 1) goto LAB_008c0976;
        iVar3 = 2;
        bVar12 = true;
        pcVar7 = &DAT_00a00258;
        pcVar10 = (char *)(in_ECX + 0x280);
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar12 = *pcVar7 == *pcVar10;
          pcVar7 = pcVar7 + 1;
          pcVar10 = pcVar10 + 1;
        } while (bVar12);
      } while (bVar12);
      iVar3 = 2;
      bVar12 = true;
      pcVar7 = &DAT_00a00254;
      pcVar10 = (char *)(in_ECX + 0x280);
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar12 = *pcVar7 == *pcVar10;
        pcVar7 = pcVar7 + 1;
        pcVar10 = pcVar10 + 1;
      } while (bVar12);
      if (!bVar12) {
LAB_008c0976:
        iVar3 = *(int *)(in_ECX + 0x278);
        if ((iVar3 == 0xc) || (iVar3 == 0xd)) {
          *(undefined4 *)(in_ECX + 0x40) = 1;
        }
        FUN_008bd585(0x5dc,(int *)(in_ECX + 0x278));
        *(undefined4 *)(in_ECX + 0x44) = 1;
        iVar3 = -0x7fffbffb;
        goto LAB_008c0a70;
      }
    }
    piVar4 = (int *)(param_1 + 8);
    while( true ) {
      iVar3 = *(int *)(in_ECX + 100);
      if (iVar3 == 0) {
        iVar3 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),in_ECX + 0x278);
        if (iVar3 < 0) goto LAB_008c0a70;
      }
      else {
        puVar8 = (undefined4 *)(iVar3 + 0x10);
        puVar11 = (undefined4 *)(in_ECX + 0x278);
        for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar11 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar11 = puVar11 + 1;
        }
        *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(iVar3 + 0xc);
        *(undefined4 *)(iVar3 + 0xc) = 0;
        *(undefined4 *)(in_ECX + 0x288) = *(undefined4 *)(*(int *)(in_ECX + 0x26c) + 0x18);
        *(undefined4 *)(in_ECX + 0x28c) = *(undefined4 *)(*(int *)(in_ECX + 0x26c) + 0x1c);
      }
      if ((*(int *)(in_ECX + 0x278) == 0xc) || (*(int *)(in_ECX + 0x278) == 0xd)) {
        *(undefined4 *)(in_ECX + 0x40) = 1;
        iVar3 = FUN_008bf987(param_1);
        if (-1 < iVar3) {
          param_1 = 0;
          iVar3 = 0;
        }
        goto LAB_008c0a70;
      }
      iVar3 = FUN_008bf738(0x30);
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_008f378b(in_ECX + 0x278);
      }
      *piVar4 = iVar3;
      if (iVar3 == 0) break;
      piVar4 = (int *)(iVar3 + 0xc);
    }
  }
LAB_008c0a4c:
  iVar3 = -0x7ff8fff2;
LAB_008c0a70:
  if (param_1 != 0) {
    FUN_008bf80d(1);
  }
  return iVar3;
}


// ==== FUN_008c0a87 @ 0x008c0a87 ====

int FUN_008c0a87(int *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined1 local_68 [56];
  undefined4 local_30 [8];
  undefined4 local_10;
  int local_c;
  undefined4 *local_8;
  
  local_10 = *(undefined4 *)(in_ECX + 0x26c);
  puVar5 = local_30;
  local_c = in_ECX;
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  local_8 = operator_new(0x14);
  if (local_8 == (undefined4 *)0x0) {
    local_8 = (undefined4 *)0x0;
  }
  else {
    *local_8 = s_DIRECT3D_00a17bf4;
    local_8[1] = 0;
    local_8[2] = 0;
    local_8[3] = 0;
    local_8[4] = 0;
  }
  if (local_8 != (undefined4 *)0x0) {
    iVar4 = FUN_008bf987(local_8);
    if (iVar4 < 0) goto LAB_008c0c42;
    local_8 = operator_new(0x14);
    if (local_8 == (undefined4 *)0x0) {
      local_8 = (undefined4 *)0x0;
    }
    else {
      *local_8 = &DAT_00a17bec;
      local_8[1] = 0;
      local_8[2] = 0;
      local_8[3] = 0;
      local_8[4] = 0;
    }
    if (local_8 != (undefined4 *)0x0) {
      iVar4 = FUN_008bf987(local_8);
      if (iVar4 < 0) goto LAB_008c0c42;
      local_30[0] = 2;
      local_30[2] = 0x900;
      local_8 = operator_new(0x14);
      if (local_8 == (undefined4 *)0x0) {
        local_8 = (undefined4 *)0x0;
      }
      else {
        *local_8 = s_DIRECT3D_VERSION_00a17bd8;
        local_8[1] = 0;
        local_8[2] = 0;
        local_8[3] = 0;
        local_8[4] = 0;
      }
      if (local_8 != (undefined4 *)0x0) {
        iVar4 = FUN_008bf738(0x30);
        if (iVar4 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_008f378b(local_30);
        }
        local_8[2] = iVar4;
        if (iVar4 != 0) {
          iVar4 = FUN_008bf987(local_8);
          if (iVar4 < 0) goto LAB_008c0c42;
          local_30[0] = 2;
          local_30[2] = 0x902;
          local_8 = operator_new(0x14);
          if (local_8 == (undefined4 *)0x0) {
            local_8 = (undefined4 *)0x0;
          }
          else {
            *local_8 = s_D3DX_VERSION_00a17bc8;
            local_8[1] = 0;
            local_8[2] = 0;
            local_8[3] = 0;
            local_8[4] = 0;
          }
          if (local_8 != (undefined4 *)0x0) {
            iVar4 = FUN_008bf738(0x30);
            if (iVar4 == 0) {
              iVar4 = 0;
            }
            else {
              iVar4 = FUN_008f378b(local_30);
            }
            local_8[2] = iVar4;
            if (iVar4 != 0) {
              iVar4 = FUN_008bf987(local_8);
              if (-1 < iVar4) {
                local_8 = (undefined4 *)0x0;
                if (param_1 != (int *)0x0) {
                  FUN_008bcde7();
                  *(undefined1 **)(local_c + 0x26c) = local_68;
                  iVar4 = *param_1;
                  while (iVar4 != 0) {
                    pcVar2 = (char *)param_1[1];
                    if (pcVar2 == (char *)0x0) {
                      iVar4 = 0;
                    }
                    else {
                      pcVar3 = pcVar2;
                      do {
                        cVar1 = *pcVar3;
                        pcVar3 = pcVar3 + 1;
                      } while (cVar1 != '\0');
                      iVar4 = (int)pcVar3 - (int)(pcVar2 + 1);
                    }
                    iVar4 = FUN_008bce01(pcVar2,iVar4,0,0,local_c,local_c + 0x18);
                    if ((iVar4 < 0) || (iVar4 = FUN_008c07e2(*param_1,0), iVar4 < 0)) {
                      FUN_0095cf1d();
                      goto LAB_008c0c42;
                    }
                    param_1 = param_1 + 2;
                    iVar4 = *param_1;
                  }
                  FUN_0095cf1d();
                }
                iVar4 = 0;
              }
              goto LAB_008c0c42;
            }
          }
        }
      }
    }
  }
  iVar4 = -0x7ff8fff2;
LAB_008c0c42:
  *(undefined4 *)(local_c + 0x26c) = local_10;
  if (local_8 != (undefined4 *)0x0) {
    FUN_008bf80d(1);
  }
  return iVar4;
}


// ==== FUN_008c0cc0 @ 0x008c0cc0 ====

void FUN_008c0cc0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  bool bVar5;
  char *pcVar6;
  int local_44 [16];
  
  iVar4 = 0;
  if (*(int *)(in_ECX + 0x44) != 0) {
    return;
  }
  while (param_2 != 0) {
    iVar3 = *(int *)(in_ECX + 0x5c);
    param_2 = param_2 + -1;
    if (iVar3 == 0) {
      pcVar6 = s_internal_error__stack_underflow_00a17c54;
      goto LAB_008c1007;
    }
    local_44[param_2] = *(int *)(iVar3 + 8);
    *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(iVar3 + 0xc);
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(in_ECX + 0x60);
    *(int *)(in_ECX + 0x60) = iVar3;
  }
  switch(param_1) {
  case 0:
    FUN_008c07e2(*(undefined4 *)(local_44[0] + 0x18),1);
    break;
  case 1:
    FUN_008bf86c(*(undefined4 *)(local_44[0] + 0x18));
    break;
  case 2:
    uVar1 = 0;
    goto LAB_008c0d48;
  case 3:
    uVar1 = *(undefined4 *)(local_44[1] + 0x18);
LAB_008c0d48:
    FUN_008be61e(*(undefined4 *)(local_44[0] + 0x18),uVar1);
    break;
  case 4:
    FUN_008be657();
    break;
  case 5:
    FUN_008be893();
    break;
  case 6:
    uVar2 = *(uint *)(local_44[0] + 0x18);
    goto LAB_008c0d80;
  case 7:
    uVar2 = FUN_008bf6b1(*(undefined4 *)(local_44[0] + 0x18),0,0);
    goto LAB_008c0d80;
  case 8:
    iVar3 = FUN_008bf6b1(*(undefined4 *)(local_44[0] + 0x18),0,0);
    uVar2 = (uint)(iVar3 == 0);
LAB_008c0d80:
    FUN_008be996(uVar2);
    break;
  case 9:
    FUN_008be9f6(*(undefined4 *)(local_44[0] + 0x18));
    break;
  case 10:
    FUN_008bea73();
    break;
  case 0xb:
    FUN_008beadd();
    break;
  case 0xc:
    FUN_008be996(1);
    goto LAB_008c0de7;
  case 0xd:
    FUN_008be9f6(1);
LAB_008c0de7:
    FUN_008bce6b();
    break;
  case 0xe:
    FUN_008bf8e0();
    break;
  case 0xf:
  case 0x10:
  case 0x13:
  case 0x16:
  case 0x17:
  case 0x1a:
  case 0x1d:
  case 0x22:
  case 0x25:
  case 0x27:
  case 0x29:
  case 0x2b:
    iVar4 = local_44[0];
    break;
  case 0x11:
    *(undefined4 *)(local_44[0] + 0x10) = 2;
    uVar2 = FUN_008bfa3e(*(undefined4 *)(local_44[0] + 0x18));
    goto LAB_008c0e8f;
  case 0x12:
    *(undefined4 *)(local_44[0] + 0x10) = 2;
    uVar1 = FUN_008bf6b1(*(undefined4 *)(local_44[0] + 0x18),0,0);
    *(undefined4 *)(local_44[0] + 0x18) = uVar1;
    *(undefined4 *)(in_ECX + 0x58) = 1;
    iVar4 = local_44[0];
    break;
  case 0x14:
    uVar2 = (uint)(*(int *)(local_44[0] + 0x18) == 0);
    goto LAB_008c0e59;
  case 0x15:
    *(int *)(local_44[0] + 0x18) = -*(int *)(local_44[0] + 0x18);
    iVar4 = local_44[0];
    break;
  case 0x18:
    uVar2 = *(int *)(local_44[1] + 0x18) * *(int *)(local_44[0] + 0x18);
    goto LAB_008c0e59;
  case 0x19:
    if (*(uint *)(local_44[1] + 0x18) == 0) {
      FUN_008bd320(in_ECX + 0x18,in_ECX + 0x278,0x5df,s_division_by_zero_in_preprocessor_00a17c28);
      *(undefined4 *)(in_ECX + 0x44) = 1;
      iVar4 = local_44[0];
      break;
    }
    uVar2 = *(uint *)(local_44[0] + 0x18) / *(uint *)(local_44[1] + 0x18);
LAB_008c0e8f:
    *(uint *)(local_44[0] + 0x18) = uVar2;
    iVar4 = local_44[0];
    break;
  case 0x1b:
    *(int *)(local_44[0] + 0x18) = *(int *)(local_44[0] + 0x18) + *(int *)(local_44[1] + 0x18);
    iVar4 = local_44[0];
    break;
  case 0x1c:
    *(int *)(local_44[0] + 0x18) = *(int *)(local_44[0] + 0x18) - *(int *)(local_44[1] + 0x18);
    iVar4 = local_44[0];
    break;
  case 0x1e:
    bVar5 = *(uint *)(local_44[0] + 0x18) < *(uint *)(local_44[1] + 0x18);
    goto LAB_008c0efe;
  case 0x1f:
    bVar5 = *(uint *)(local_44[1] + 0x18) < *(uint *)(local_44[0] + 0x18);
LAB_008c0efe:
    uVar2 = (uint)bVar5;
    goto LAB_008c0e59;
  case 0x20:
    bVar5 = *(uint *)(local_44[1] + 0x18) < *(uint *)(local_44[0] + 0x18);
    goto LAB_008c0f35;
  case 0x21:
    bVar5 = *(uint *)(local_44[0] + 0x18) < *(uint *)(local_44[1] + 0x18);
    goto LAB_008c0f35;
  case 0x23:
    bVar5 = *(int *)(local_44[0] + 0x18) != *(int *)(local_44[1] + 0x18);
LAB_008c0f35:
    uVar2 = 1 - bVar5;
    goto LAB_008c0e59;
  case 0x24:
    *(uint *)(local_44[0] + 0x18) =
         (uint)(*(int *)(local_44[0] + 0x18) != *(int *)(local_44[1] + 0x18));
    iVar4 = local_44[0];
    break;
  case 0x26:
    if (*(int *)(local_44[0] + 0x18) != 0) {
LAB_008c0f5c:
      if (*(int *)(local_44[1] + 0x18) != 0) goto LAB_008c0f64;
    }
    uVar2 = 0;
    goto LAB_008c0e59;
  case 0x28:
    if (*(int *)(local_44[0] + 0x18) == 0) goto LAB_008c0f5c;
LAB_008c0f64:
    uVar2 = 1;
    goto LAB_008c0e59;
  case 0x2a:
    if (*(int *)(local_44[0] + 0x18) == 0) {
      local_44[1] = local_44[2];
    }
    uVar2 = *(uint *)(local_44[1] + 0x18);
LAB_008c0e59:
    *(uint *)(local_44[0] + 0x18) = uVar2;
    iVar4 = local_44[0];
    break;
  case 0x2c:
  case 0x2d:
  case 0x2e:
    iVar4 = FUN_008bf738(0x30);
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_008f378b(in_ECX + 0x278);
    }
    FUN_008bf7b8(iVar4);
  }
  if (*(int *)(in_ECX + 0x44) == 0) {
    iVar3 = *(int *)(in_ECX + 0x60);
    if (iVar3 == 0) {
      iVar3 = FUN_008bf738(0x14);
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_008f3584(iVar4,*(undefined4 *)(in_ECX + 0x5c),s_Stack_00a17c20);
      }
      if (iVar3 == 0) {
        pcVar6 = s_internal_error__out_of_memory_00a17c00;
LAB_008c1007:
        FUN_008bd320(in_ECX + 0x18,in_ECX + 0x278,0,pcVar6);
        *(undefined4 *)(in_ECX + 0x44) = 1;
        return;
      }
    }
    else {
      *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(iVar3 + 0xc);
      *(int *)(iVar3 + 8) = iVar4;
      *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(in_ECX + 0x5c);
    }
    *(int *)(in_ECX + 0x5c) = iVar3;
  }
  return;
}


// ==== FUN_008c10e0 @ 0x008c10e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008c10e0(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar4 = 0;
  _DAT_00b5eac0 = 0;
  DAT_00b5eabc = 0;
  DAT_00b5eab4 = (short *)&DAT_00b5e6c0;
  DAT_00b5eab0 = (undefined4 *)&DAT_00b5def0;
  _DAT_00b5e6c0 = 0;
LAB_008c110e:
  DAT_00b5eab8 = -1;
LAB_008c1116:
  iVar2 = (int)(short)(&DAT_00b540a0)[iVar4];
  if (iVar2 == 0) {
    if ((DAT_00b5eab8 < 0) && (DAT_00b5eab8 = FUN_008c034d(), DAT_00b5eab8 < 0)) {
      DAT_00b5eab8 = 0;
    }
    if (((((short)(&DAT_00b54160)[iVar4] != 0) &&
         (iVar2 = (short)(&DAT_00b54160)[iVar4] + DAT_00b5eab8, -1 < iVar2)) && (iVar2 < 0x172)) &&
       (*(short *)(&DAT_00b545a8 + iVar2 * 2) == DAT_00b5eab8)) {
      if (&DAT_00b5eaa6 <= DAT_00b5eab4) goto LAB_008c152f;
      iVar4 = (int)*(short *)(&DAT_00b542c0 + iVar2 * 2);
      DAT_00b5eab4 = DAT_00b5eab4 + 1;
      *DAT_00b5eab4 = *(short *)(&DAT_00b542c0 + iVar2 * 2);
      DAT_00b5eab0 = DAT_00b5eab0 + 1;
      *DAT_00b5eab0 = DAT_00b5eaa8;
      DAT_00b5eab8 = -1;
      if (0 < DAT_00b5eabc) {
        DAT_00b5eabc = DAT_00b5eabc + -1;
      }
      goto LAB_008c1116;
    }
    if ((((short)(&DAT_00b54200)[iVar4] != 0) &&
        (iVar2 = (short)(&DAT_00b54200)[iVar4] + DAT_00b5eab8, -1 < iVar2)) &&
       ((iVar2 < 0x172 && (*(short *)(&DAT_00b545a8 + iVar2 * 2) == DAT_00b5eab8)))) {
      iVar2 = (int)*(short *)(&DAT_00b542c0 + iVar2 * 2);
      goto LAB_008c11fd;
    }
    if (DAT_00b5eabc == 0) {
      FUN_008be554(DAT_00b5eae8,s_syntax_error_009fea30);
      _DAT_00b5eac0 = _DAT_00b5eac0 + 1;
    }
    if (2 < DAT_00b5eabc) goto LAB_008c1526;
    DAT_00b5eabc = 3;
    while ((((short)(&DAT_00b54160)[*DAT_00b5eab4] == 0 ||
            (iVar4 = (short)(&DAT_00b54160)[*DAT_00b5eab4] + 0x100, iVar4 < 0)) ||
           ((0x171 < iVar4 || (*(short *)(&DAT_00b545a8 + iVar4 * 2) != 0x100))))) {
      if (DAT_00b5eab4 < (short *)0xb5e6c1) {
        DAT_00b5eabc = 3;
        return 1;
      }
      DAT_00b5eab4 = DAT_00b5eab4 + -1;
      DAT_00b5eab0 = DAT_00b5eab0 + -1;
    }
    if ((short *)0xb5eaa5 < DAT_00b5eab4) goto LAB_008c152f;
    sVar1 = *(short *)(&DAT_00b542c0 + iVar4 * 2);
    DAT_00b5eab4 = DAT_00b5eab4 + 1;
    *DAT_00b5eab4 = sVar1;
    uVar6 = DAT_00b5eaa8;
  }
  else {
LAB_008c11fd:
    iVar4 = (int)*(short *)(&DAT_00b54040 + iVar2 * 2);
    DAT_00b5eaac = DAT_00b5eab0[1 - iVar4];
    switch(iVar2) {
    case 1:
      uVar7 = 1;
      uVar6 = 0;
      break;
    case 2:
      uVar7 = 1;
      uVar6 = 1;
      break;
    case 3:
      uVar7 = 1;
      uVar6 = 2;
      break;
    case 4:
      uVar7 = 2;
      uVar6 = 3;
      break;
    case 5:
      uVar7 = 0;
      uVar6 = 4;
      break;
    case 6:
      uVar7 = 0;
      uVar6 = 5;
      break;
    case 7:
      uVar7 = 1;
      uVar6 = 6;
      break;
    case 8:
      uVar7 = 1;
      uVar6 = 7;
      break;
    case 9:
      uVar7 = 1;
      uVar6 = 8;
      break;
    case 10:
      uVar7 = 1;
      uVar6 = 9;
      break;
    case 0xb:
      uVar7 = 0;
      uVar6 = 10;
      break;
    case 0xc:
      uVar7 = 0;
      uVar6 = 0xb;
      break;
    case 0xd:
      uVar7 = 0;
      uVar6 = 0xc;
      break;
    case 0xe:
      uVar7 = 0;
      uVar6 = 0xd;
      break;
    case 0xf:
      uVar7 = 0;
      uVar6 = 0xe;
      break;
    case 0x10:
      uVar7 = 1;
      uVar6 = 0xf;
      break;
    case 0x11:
      uVar7 = 1;
      uVar6 = 0x10;
      break;
    case 0x12:
      uVar7 = 1;
      uVar6 = 0x11;
      break;
    case 0x13:
      uVar7 = 1;
      uVar6 = 0x12;
      break;
    case 0x14:
      uVar7 = 1;
      uVar6 = 0x13;
      break;
    case 0x15:
      uVar7 = 1;
      uVar6 = 0x14;
      break;
    case 0x16:
      uVar7 = 1;
      uVar6 = 0x15;
      break;
    case 0x17:
      uVar7 = 1;
      uVar6 = 0x16;
      break;
    case 0x18:
      uVar7 = 1;
      uVar6 = 0x17;
      break;
    case 0x19:
      uVar7 = 2;
      uVar6 = 0x18;
      break;
    case 0x1a:
      uVar7 = 2;
      uVar6 = 0x19;
      break;
    case 0x1b:
      uVar7 = 1;
      uVar6 = 0x1a;
      break;
    case 0x1c:
      uVar7 = 2;
      uVar6 = 0x1b;
      break;
    case 0x1d:
      uVar7 = 2;
      uVar6 = 0x1c;
      break;
    case 0x1e:
      uVar7 = 1;
      uVar6 = 0x1d;
      break;
    case 0x1f:
      uVar7 = 2;
      uVar6 = 0x1e;
      break;
    case 0x20:
      uVar7 = 2;
      uVar6 = 0x1f;
      break;
    case 0x21:
      uVar7 = 2;
      uVar6 = 0x20;
      break;
    case 0x22:
      uVar7 = 2;
      uVar6 = 0x21;
      break;
    case 0x23:
      uVar7 = 1;
      uVar6 = 0x22;
      break;
    case 0x24:
      uVar7 = 2;
      uVar6 = 0x23;
      break;
    case 0x25:
      uVar7 = 2;
      uVar6 = 0x24;
      break;
    case 0x26:
      uVar7 = 1;
      uVar6 = 0x25;
      break;
    case 0x27:
      uVar7 = 2;
      uVar6 = 0x26;
      break;
    case 0x28:
      uVar7 = 1;
      uVar6 = 0x27;
      break;
    case 0x29:
      uVar7 = 2;
      uVar6 = 0x28;
      break;
    case 0x2a:
      uVar7 = 1;
      uVar6 = 0x29;
      break;
    case 0x2b:
      uVar7 = 3;
      uVar6 = 0x2a;
      break;
    case 0x2c:
      uVar7 = 1;
      uVar6 = 0x2b;
      break;
    case 0x2d:
      uVar7 = 0;
      uVar6 = 0x2c;
      break;
    case 0x2e:
      uVar7 = 0;
      uVar6 = 0x2d;
      break;
    case 0x2f:
      uVar7 = 0;
      uVar6 = 0x2e;
      break;
    default:
      goto switchD_008c1227_default;
    }
    FUN_008c0cc0(uVar6,uVar7);
switchD_008c1227_default:
    DAT_00b5eab4 = DAT_00b5eab4 + -iVar4;
    iVar3 = (int)*DAT_00b5eab4;
    DAT_00b5eab0 = DAT_00b5eab0 + -iVar4;
    if ((iVar3 == 0) && (*(short *)(&DAT_00b53fe0 + iVar2 * 2) == 0)) {
      DAT_00b5eab4 = DAT_00b5eab4 + 1;
      iVar4 = 0xf;
      *DAT_00b5eab4 = 0xf;
      DAT_00b5eab0 = DAT_00b5eab0 + 1;
      *DAT_00b5eab0 = DAT_00b5eaac;
      bVar5 = DAT_00b5eab8 == 0;
      if (DAT_00b5eab8 < 0) {
        DAT_00b5eab8 = FUN_008c034d();
        bVar5 = DAT_00b5eab8 == 0;
        if (DAT_00b5eab8 < 0) {
          DAT_00b5eab8 = 0;
          bVar5 = true;
        }
      }
      if (bVar5) {
        return 0;
      }
      goto LAB_008c1116;
    }
    iVar4 = *(short *)(&DAT_00b53fe0 + iVar2 * 2) * 2;
    if ((((*(short *)(&DAT_00b542a0 + iVar4) == 0) ||
         (iVar2 = *(short *)(&DAT_00b542a0 + iVar4) + iVar3, iVar2 < 0)) || (0x171 < iVar2)) ||
       (*(short *)(&DAT_00b545a8 + iVar2 * 2) != iVar3)) {
      sVar1 = *(short *)(&DAT_00b54140 + iVar4);
    }
    else {
      sVar1 = *(short *)(&DAT_00b542c0 + iVar2 * 2);
    }
    if ((short *)0xb5eaa5 < DAT_00b5eab4) {
LAB_008c152f:
      FUN_008be554(DAT_00b5eae8,s_yacc_stack_overflow_00a17c74);
      return 1;
    }
    DAT_00b5eab4 = DAT_00b5eab4 + 1;
    *DAT_00b5eab4 = sVar1;
    uVar6 = DAT_00b5eaac;
  }
  iVar4 = (int)sVar1;
  DAT_00b5eab0 = DAT_00b5eab0 + 1;
  *DAT_00b5eab0 = uVar6;
  goto LAB_008c1116;
LAB_008c1526:
  if (DAT_00b5eab8 == 0) {
    return 1;
  }
  goto LAB_008c110e;
}


// ==== FUN_008c1604 @ 0x008c1604 ====

int FUN_008c1604(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *pvVar1;
  int iVar2;
  int in_ECX;
  
  pvVar1 = operator_new(0x70);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_008be0f2();
  }
  *(int *)(in_ECX + 0x268) = iVar2;
  if (iVar2 == 0) {
    iVar2 = -0x7ff8fff2;
  }
  else {
    iVar2 = FUN_008be3d5(param_1,param_2,in_ECX,in_ECX + 0x18);
    if (-1 < iVar2) {
      iVar2 = FUN_008c0a87(param_3);
      if (-1 < iVar2) {
        *(undefined4 *)(in_ECX + 0x26c) = *(undefined4 *)(in_ECX + 0x268);
        *(undefined4 *)(in_ECX + 0x270) = param_4;
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}


// ==== FUN_008c1674 @ 0x008c1674 ====

uint FUN_008c1674(int *param_1)

{
  uint uVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  int *piVar6;
  char *pcVar7;
  bool bVar8;
  int local_c;
  int local_8;
  
  local_c = in_ECX;
  local_8 = in_ECX;
LAB_008c18da:
  do {
    if (*(int *)(in_ECX + 0x48) != 0) {
      uVar1 = 0x80004005;
LAB_008c18ed:
      param_1[4] = *(int *)(*(int *)(in_ECX + 0x26c) + 0x18);
      param_1[5] = *(int *)(*(int *)(in_ECX + 0x26c) + 0x1c);
      *param_1 = 0xd;
      return uVar1;
    }
    if ((*(int *)(in_ECX + 0x68) != 0) && (*(int *)(*(int *)(in_ECX + 0x68) + 8) == 0)) {
      uVar1 = 0;
      goto LAB_008c18ed;
    }
    iVar3 = *(int *)(in_ECX + 100);
    if (iVar3 == 0) {
      uVar1 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),param_1);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
    }
    else {
      piVar4 = (int *)(iVar3 + 0x10);
      piVar6 = param_1;
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar6 = *piVar4;
        piVar4 = piVar4 + 1;
        piVar6 = piVar6 + 1;
      }
      *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(*(int *)(in_ECX + 100) + 0xc);
      *(undefined4 *)(iVar3 + 0xc) = 0;
      param_1[4] = *(int *)(*(int *)(in_ECX + 0x26c) + 0x18);
      param_1[5] = *(int *)(*(int *)(in_ECX + 0x26c) + 0x1c);
      *(undefined4 *)(in_ECX + 0x40) = 0;
    }
    if (*param_1 != 1) {
LAB_008c182f:
      if (*param_1 == 0xd) {
        if (*(int *)(*(int *)(in_ECX + 0x268) + 0x38) != 0) {
          FUN_008bd320(in_ECX + 0x18,param_1,0x5de,s_unexpected_end_of_file_00a17c88);
        }
        iVar3 = *(int *)(in_ECX + 0x268);
        if (*(int *)(iVar3 + 0x6c) == 0) {
          return 0;
        }
        *(undefined4 *)(in_ECX + 0x268) = *(undefined4 *)(iVar3 + 0x6c);
        *(undefined4 *)(iVar3 + 0x6c) = 0;
        FUN_008be180(1);
        *(undefined4 *)(in_ECX + 0x26c) = *(undefined4 *)(in_ECX + 0x268);
        *param_1 = 0xc;
        *(undefined4 *)(in_ECX + 0x40) = 1;
        return 0;
      }
      if (((*param_1 != 9) || (iVar3 = FUN_008bf6b1(param_1[2],&local_c,&local_8), iVar3 == 0)) ||
         (iVar3 = FUN_008bfae5(param_1,local_c,local_8), iVar3 == 0)) {
        if (*param_1 == 9) {
          iVar3 = 9;
          bVar8 = true;
          pcVar5 = (char *)param_1[2];
          pcVar7 = s___FILE___00a17ca0;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar8 = *pcVar5 == *pcVar7;
            pcVar5 = pcVar5 + 1;
            pcVar7 = pcVar7 + 1;
          } while (bVar8);
          if (bVar8) {
            *param_1 = 10;
            iVar3 = *(int *)(*(int *)(in_ECX + 0x26c) + 0x18);
            param_1[2] = iVar3;
            if (iVar3 == 0) {
              param_1[2] = (int)&DAT_0099cf70;
            }
          }
          else {
            iVar3 = 9;
            bVar8 = true;
            pcVar5 = (char *)param_1[2];
            pcVar7 = s___LINE___00a17aec;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar8 = *pcVar5 == *pcVar7;
              pcVar5 = pcVar5 + 1;
              pcVar7 = pcVar7 + 1;
            } while (bVar8);
            if (bVar8) {
              *param_1 = 2;
              param_1[2] = *(int *)(*(int *)(in_ECX + 0x26c) + 0x1c);
            }
          }
        }
        *(uint *)(in_ECX + 0x40) = (uint)(*param_1 == 0xc);
        if (*(int *)(in_ECX + 0x50) != 0) {
          iVar3 = *(int *)(in_ECX + 0x68);
          if ((iVar3 != 0) && (*(int *)(iVar3 + 4) != 0)) {
            if ((*param_1 == 1) && (*(char *)((int)param_1 + 9) == '\0')) {
              if ((char)param_1[2] == '{') {
                *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;
              }
              if (((char)param_1[2] == '}') && (*(int *)(*(int *)(in_ECX + 0x68) + 8) != 0)) {
                piVar4 = (int *)(*(int *)(in_ECX + 0x68) + 8);
                *piVar4 = *piVar4 + -1;
              }
            }
            if (*(int *)(*(int *)(in_ECX + 0x68) + 8) == 0) {
              *param_1 = 0xd;
            }
          }
          return 0;
        }
      }
      goto LAB_008c18da;
    }
    iVar3 = 2;
    bVar8 = true;
    pcVar5 = &DAT_00a17b58;
    piVar4 = param_1 + 2;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar8 = *pcVar5 == (char)*piVar4;
      pcVar5 = pcVar5 + 1;
      piVar4 = (int *)((int)piVar4 + 1);
    } while (bVar8);
    if ((!bVar8) || (*(int *)(in_ECX + 0x40) == 0)) goto LAB_008c182f;
    DAT_00b5eae8 = in_ECX;
    *(undefined4 *)(in_ECX + 0x40) = 0;
    *(undefined4 *)(in_ECX + 0x44) = 0;
    *(undefined4 *)(in_ECX + 0x4c) = 1;
    *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(in_ECX + 0x50);
    iVar3 = FUN_008c10e0();
    if (iVar3 != 0) {
      *(undefined4 *)(in_ECX + 0x44) = 1;
    }
    *(undefined4 *)(in_ECX + 0x5c) = 0;
    if ((*(int *)(in_ECX + 0x40) == 0) && (*(int *)(in_ECX + 0x44) == 0)) {
      uVar1 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),(int *)(in_ECX + 0x278));
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      iVar3 = *(int *)(in_ECX + 0x278);
      if ((iVar3 == 0xc) || (iVar3 == 0xd)) {
        *(undefined4 *)(in_ECX + 0x40) = 1;
      }
      else {
        if (*(int *)(in_ECX + 0x50) != 0) {
          FUN_008bd320(in_ECX + 0x18,param_1,0x5dd,s_unexpected_tokens_following_prep_00a17cac);
        }
        *(undefined4 *)(in_ECX + 0x44) = 1;
      }
    }
    if (*(int *)(in_ECX + 0x40) == 0) {
      FUN_008bce6b();
      *(undefined4 *)(in_ECX + 100) = 0;
      uVar1 = FUN_008bde0c(*(undefined4 *)(in_ECX + 0x298),in_ECX + 0x278);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      *(undefined4 *)(in_ECX + 0x40) = 1;
    }
    *(undefined4 *)(in_ECX + 0x26c) = *(undefined4 *)(in_ECX + 0x268);
    *(int *)(in_ECX + 0x50) = *(int *)(in_ECX + 0x54);
    if (*(int *)(in_ECX + 0x54) != 0) {
      piVar4 = (int *)(in_ECX + 0x278);
      piVar6 = param_1;
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar6 = *piVar4;
        piVar4 = piVar4 + 1;
        piVar6 = piVar6 + 1;
      }
      if (*(int *)(*(int *)(in_ECX + 0x268) + 0x6c) != 0) {
        *param_1 = 0xc;
      }
      return -(uint)(*(int *)(in_ECX + 0x48) != 0) & 0x80004005;
    }
  } while( true );
}


// ==== FUN_008c19ba @ 0x008c19ba ====

int FUN_008c19ba(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int local_24 [8];
  
  if (*(int *)(in_ECX + 0x68) == 0) {
    iVar1 = -0x7789f794;
  }
  else {
    do {
      iVar1 = FUN_008c1674(local_24);
      if (iVar1 < 0) {
        return iVar1;
      }
    } while (local_24[0] != 0xd);
    iVar1 = *(int *)(in_ECX + 0x68);
    *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(iVar1 + 4);
    *(undefined4 *)(iVar1 + 4) = 0;
    FUN_008be445(1);
    if (*(undefined4 **)(in_ECX + 0x68) == (undefined4 *)0x0) {
      uVar2 = 1;
    }
    else {
      uVar2 = **(undefined4 **)(in_ECX + 0x68);
    }
    *(undefined4 *)(in_ECX + 0x298) = uVar2;
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_008c1a16 @ 0x008c1a16 ====

void FUN_008c1a16(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  FUN_008bf82e();
  return;
}


// ==== FUN_008c1a41 @ 0x008c1a41 ====

void FUN_008c1a41(byte param_1)

{
  void *in_ECX;
  
  FUN_008c59eb();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008c1a62 @ 0x008c1a62 ====

void FUN_008c1a62(void)

{
  void *_Memory;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    return;
  }
  _Memory = *(void **)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)((int)_Memory + 8);
  *(undefined4 *)((int)_Memory + 8) = 0;
  FUN_008c1a62();
  _free(_Memory);
  return;
}


// ==== FUN_008c1a92 @ 0x008c1a92 ====

void FUN_008c1a92(byte param_1)

{
  void *in_ECX;
  
  FUN_008c1a62();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008c1ab3 @ 0x008c1ab3 ====

void FUN_008c1ab3(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[10] = 0;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = param_4;
  in_ECX[4] = param_5;
  in_ECX[5] = param_6;
  in_ECX[6] = param_7;
  in_ECX[7] = param_8;
  in_ECX[8] = param_9;
  in_ECX[9] = param_10;
  return;
}


// ==== FUN_008c1afd @ 0x008c1afd ====

void FUN_008c1afd(void)

{
  void *_Memory;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x28) == 0) {
    return;
  }
  _Memory = *(void **)(in_ECX + 0x28);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)((int)_Memory + 0x28);
  *(undefined4 *)((int)_Memory + 0x28) = 0;
  FUN_008c1afd();
  _free(_Memory);
  return;
}


// ==== FUN_008c1b2d @ 0x008c1b2d ====

void FUN_008c1b2d(void)

{
  void *_Memory;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x18) == 0) {
    return;
  }
  _Memory = *(void **)(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)((int)_Memory + 0x18);
  *(undefined4 *)((int)_Memory + 0x18) = 0;
  FUN_008c1b2d();
  _free(_Memory);
  return;
}


// ==== FUN_008c1b5d @ 0x008c1b5d ====

void FUN_008c1b5d(byte param_1)

{
  void *in_ECX;
  
  FUN_008c1b2d();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008c1b7e @ 0x008c1b7e ====

void FUN_008c1b7e(void)

{
  undefined4 *in_ECX;
  
  in_ECX[3] = 0;
  in_ECX[2] = 0;
  in_ECX[4] = in_ECX;
  in_ECX[5] = 0;
  in_ECX[1] = 0;
  *in_ECX = 0;
  in_ECX[6] = 0;
  return;
}


// ==== FUN_008c1b97 @ 0x008c1b97 ====

void FUN_008c1b97(void)

{
  void *_Memory;
  int in_ECX;
  
  if (*(void **)(in_ECX + 4) != (void *)0x0) {
    _free(*(void **)(in_ECX + 4));
    return;
  }
  if (*(int *)(in_ECX + 8) == 0) {
    return;
  }
  _Memory = *(void **)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)((int)_Memory + 8);
  *(undefined4 *)((int)_Memory + 8) = 0;
  FUN_008c1b97();
  _free(_Memory);
  return;
}


// ==== FUN_008c1bd9 @ 0x008c1bd9 ====

void FUN_008c1bd9(byte param_1)

{
  void *in_ECX;
  
  FUN_008c1b97();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008c1bfa @ 0x008c1bfa ====

undefined4 FUN_008c1bfa(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  uint uVar5;
  undefined4 local_8;
  
  local_8 = 0;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_008c1b7e();
  }
  if (piVar2 == (int *)0x0) {
    return 0x8007000e;
  }
  if (param_2 != 0) {
    iVar3 = (uint)((param_2 & 3) != 0) + (param_2 >> 2);
    *piVar2 = iVar3;
    puVar4 = operator_new(iVar3 * 4);
    piVar2[1] = (int)puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      local_8 = 0x8007000e;
      goto LAB_008c1c9a;
    }
    for (uVar5 = param_2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar4 = *param_1;
      param_1 = param_1 + 1;
      puVar4 = puVar4 + 1;
    }
    for (param_2 = param_2 & 3; param_2 != 0; param_2 = param_2 - 1) {
      *(undefined1 *)puVar4 = *(undefined1 *)param_1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
  }
  piVar2[3] = *(int *)(in_ECX + 0x10);
  *(int **)(*(int *)(in_ECX + 0x10) + 8) = piVar2;
  *(int **)(in_ECX + 0x10) = piVar2;
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = piVar2;
  }
  piVar2 = (int *)0x0;
LAB_008c1c9a:
  if (piVar2 != (int *)0x0) {
    FUN_008c1bd9(1);
  }
  return local_8;
}


// ==== FUN_008c1cb1 @ 0x008c1cb1 ====

void FUN_008c1cb1(char *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  char *local_8;
  
  local_8 = (char *)0x0;
  if (param_1 != (char *)0x0) {
    local_8 = param_1;
    do {
      cVar1 = *local_8;
      local_8 = local_8 + 1;
    } while (cVar1 != '\0');
    local_8 = local_8 + (1 - (int)(param_1 + 1));
  }
  iVar2 = FUN_008c1bfa(&local_8,4,param_2);
  if ((-1 < iVar2) && (param_1 != (char *)0x0)) {
    FUN_008c1bfa(param_1,local_8,0);
  }
  return;
}


// ==== FUN_008c1d03 @ 0x008c1d03 ====

undefined4 FUN_008c1d03(undefined4 param_1,undefined4 *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_008c1b7e();
  }
  if (puVar2 == (undefined4 *)0x0) {
    local_8 = 0x8007000e;
  }
  else {
    *puVar2 = 1;
    puVar3 = operator_new(4);
    puVar2[1] = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      local_8 = 0x8007000e;
    }
    else {
      *puVar3 = 0xffffffff;
      puVar2[5] = param_1;
      puVar2[3] = *(undefined4 *)(in_ECX + 0x10);
      *(undefined4 **)(*(int *)(in_ECX + 0x10) + 8) = puVar2;
      *(undefined4 **)(in_ECX + 0x10) = puVar2;
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = puVar2;
      }
      puVar2 = (undefined4 *)0x0;
    }
    if (puVar2 != (undefined4 *)0x0) {
      FUN_008c1bd9(1);
    }
  }
  return local_8;
}


// ==== FUN_008c1d8e @ 0x008c1d8e ====

undefined4 FUN_008c1d8e(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(in_ECX + 0x10);
  *(int *)(*(int *)(in_ECX + 0x10) + 8) = param_1;
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 0x10);
  return 0;
}


// ==== FUN_008c1dae @ 0x008c1dae ====

undefined4 FUN_008c1dae(int param_1,uint *param_2)

{
  uint *in_ECX;
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  for (; in_ECX != (uint *)0x0; in_ECX = (uint *)in_ECX[2]) {
    if (param_2 != (uint *)0x0) {
      in_ECX[6] = *param_2;
      *param_2 = *param_2 + *in_ECX * 4;
    }
    if (param_1 != 0) {
      if (in_ECX[5] == 0) {
        puVar3 = (undefined4 *)in_ECX[1];
      }
      else {
        puVar3 = (undefined4 *)(in_ECX[5] + 0x18);
      }
      puVar4 = (undefined4 *)(in_ECX[6] + param_1);
      for (uVar1 = *in_ECX & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined1 *)puVar4 = *(undefined1 *)puVar3;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
    }
  }
  return 0;
}


// ==== FUN_008c1e0d @ 0x008c1e0d ====

undefined4 FUN_008c1e0d(void)

{
  return 0;
}


// ==== FUN_008c1e12 @ 0x008c1e12 ====

int FUN_008c1e12(int param_1,undefined4 *param_2,int *param_3,int *param_4,int *param_5,int *param_6
                ,int *param_7)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  char *pcVar4;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [8];
  int local_8;
  
  piVar2 = param_7;
  piVar1 = param_6;
  local_8 = 0;
  if (param_1 == 0) {
    return -0x7fffbffb;
  }
  iVar3 = *(int *)(param_1 + 4);
  if (iVar3 == 1) {
    *param_6 = 0;
    *param_7 = 0;
    while( true ) {
      if (*(int *)(param_1 + 4) != 1) {
        return -0x7fffbffb;
      }
      iVar3 = *(int *)(param_1 + 8);
      if (iVar3 == 0) {
        return -0x7fffbffb;
      }
      if (*(int *)(iVar3 + 4) != 6) {
        return -0x7fffbffb;
      }
      if (*(int *)(iVar3 + 0x10) != 1) {
        return -0x7fffbffb;
      }
      iVar3 = *(int *)(iVar3 + 0x18);
      if (iVar3 == 0) {
        return -0x7fffbffb;
      }
      if (*(int *)(iVar3 + 4) != 0xb) {
        return -0x7fffbffb;
      }
      if (*(int *)(iVar3 + 0x20) == 0) {
        return -0x7fffbffb;
      }
      local_8 = FUN_008c1e12(*(int *)(iVar3 + 0x20),local_20,local_1c,local_18,local_14,local_10,
                             &param_6);
      if (local_8 < 0) break;
      *param_7 = *param_7 + (int)param_6;
      param_1 = *(int *)(param_1 + 0xc);
      *piVar1 = *piVar1 + 1;
      if (param_1 == 0) {
        *param_2 = 0;
        *param_3 = 0;
        *param_4 = 0;
        *param_5 = 0;
        return local_8;
      }
    }
    return local_8;
  }
  if (iVar3 == 8) {
    if (*(int *)(param_1 + 0x10) == 0) {
      return -0x7fffbffb;
    }
    iVar3 = FUN_008c1e12(*(int *)(param_1 + 0x10),param_2,param_3,param_4,param_5,param_6,param_7);
    if (iVar3 < 0) {
      return iVar3;
    }
    if (*param_5 == 0) {
      *param_5 = 1;
    }
    *param_5 = *(int *)(param_1 + 0x14) * *param_5;
    *piVar2 = *(int *)(param_1 + 0x14) * *piVar2;
    return iVar3;
  }
  if (iVar3 != 9) {
    pcVar4 = s_ID3DXEffectCompiler__Unexpected_n_00a1ae28;
    goto LAB_008c1e53;
  }
  *param_5 = 0;
  *param_6 = 0;
  iVar3 = *(int *)(param_1 + 0x10);
  if (iVar3 == 0) {
LAB_008c1ea8:
    iVar3 = 1;
    *param_3 = 1;
  }
  else if (iVar3 == 1) {
    *param_3 = *(int *)(param_1 + 0x1c);
    iVar3 = *(int *)(param_1 + 0x18);
  }
  else {
    if (iVar3 != 2) {
      if (iVar3 != 3) {
        pcVar4 = s_ID3DXEffectCompiler__Unexpected_t_00a1adf8;
        goto LAB_008c1e53;
      }
      goto LAB_008c1ea8;
    }
    *param_3 = *(int *)(param_1 + 0x18);
    iVar3 = *(int *)(param_1 + 0x1c);
  }
  *param_4 = iVar3;
  switch(*(undefined4 *)(param_1 + 0x14)) {
  case 0:
    *param_2 = 1;
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
    *param_2 = 2;
    break;
  case 9:
  case 10:
  case 0xb:
  case 0xc:
    *param_2 = 3;
    break;
  case 0xe:
    *param_2 = 4;
    *param_7 = 4;
    goto LAB_008c1fbe;
  case 0xf:
    *param_2 = 5;
    break;
  case 0x10:
    *param_2 = 6;
    break;
  case 0x11:
    *param_2 = 7;
    break;
  case 0x12:
    *param_2 = 8;
    break;
  case 0x13:
    *param_2 = 9;
    break;
  case 0x14:
    *param_2 = 10;
    goto LAB_008c1f84;
  case 0x15:
    *param_2 = 0xb;
    goto LAB_008c1f84;
  case 0x16:
    *param_2 = 0xc;
    goto LAB_008c1f84;
  case 0x17:
    *param_2 = 0xd;
    goto LAB_008c1f84;
  case 0x18:
    *param_2 = 0xe;
    goto LAB_008c1f84;
  case 0x19:
    *param_2 = 0xf;
    break;
  case 0x1a:
    *param_2 = 0x10;
    break;
  case 0x1b:
    *param_2 = 0x11;
    break;
  case 0x1c:
    *param_2 = 0x12;
    break;
  case 0x1d:
    *param_2 = 0xf30000;
LAB_008c1f84:
    *param_7 = 0;
    goto LAB_008c1fbe;
  default:
    pcVar4 = s_ID3DXEffectCompiler__Unexpected_c_00a1adc8;
LAB_008c1e53:
    FUN_008bd320(in_ECX + 0x28,0,0,pcVar4);
    return -0x7fffbffb;
  }
  *param_7 = 4;
LAB_008c1fbe:
  *param_7 = *param_3 * *param_4 * *param_7;
  return 0;
}


// ==== FUN_008c2154 @ 0x008c2154 ====

int FUN_008c2154(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_8;
  
  piVar4 = param_3;
  piVar3 = param_2;
  iVar6 = *param_2;
  piVar5 = (int *)(param_1 + iVar6);
  iVar8 = piVar5[4];
  iVar1 = piVar5[1];
  if (iVar8 == 0) {
    iVar8 = 1;
  }
  if (iVar1 < 0) {
LAB_008c222c:
    iVar7 = 0;
  }
  else {
    if (iVar1 < 4) {
      iVar1 = piVar5[6];
      iVar2 = piVar5[5];
      iVar7 = *piVar5;
      if (((iVar7 == 1) || (iVar7 == 2)) || (iVar7 == 3)) {
        iVar7 = 4;
      }
      else {
        iVar7 = 0;
        iVar8 = 0;
      }
      *param_2 = iVar6 + 0x1c;
      iVar7 = iVar1 * iVar2 * iVar7;
      *param_3 = iVar1 * iVar2 * iVar8;
    }
    else if (iVar1 == 4) {
      iVar1 = *piVar5;
      if ((iVar1 < 10) || ((0xe < iVar1 && (iVar1 != 0xf30000)))) {
        iVar7 = 4;
      }
      else {
        iVar7 = 0;
      }
      *param_2 = iVar6 + 0x14;
      *param_3 = iVar8;
    }
    else {
      if (iVar1 != 5) goto LAB_008c222c;
      iVar1 = piVar5[5];
      param_3 = (int *)0x0;
      *param_2 = iVar6 + 0x18;
      *piVar4 = 0;
      if (iVar1 != 0) {
        param_2 = (int *)iVar1;
        do {
          iVar6 = FUN_008c2154(param_1,piVar3,&local_8);
          param_3 = (int *)((int)param_3 + iVar6);
          *piVar4 = *piVar4 + local_8;
          param_2 = (int *)((int)param_2 + -1);
        } while (param_2 != (int *)0x0);
      }
      *piVar4 = *piVar4 * iVar8;
      iVar7 = (int)param_3;
    }
    iVar7 = iVar7 * iVar8;
  }
  return iVar7;
}


// ==== FUN_008c2235 @ 0x008c2235 ====

undefined4 FUN_008c2235(int param_1)

{
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  return *(undefined4 *)(param_1 + 8);
}


// ==== FUN_008c2247 @ 0x008c2247 ====

undefined4 FUN_008c2247(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  
  iVar1 = 4;
  bVar4 = true;
  piVar2 = param_2;
  piVar3 = &DAT_00a24f6c;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *piVar2 == *piVar3;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (bVar4);
  if (!bVar4) {
    iVar1 = 4;
    bVar4 = true;
    piVar2 = &DAT_00a52010;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *param_2 == *piVar2;
      param_2 = param_2 + 1;
      piVar2 = piVar2 + 1;
    } while (bVar4);
    if (!bVar4) {
      return 0x80004002;
    }
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}


// ==== FUN_008c228d @ 0x008c228d ====

int FUN_008c228d(int *param_1,uint param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int local_8;
  
  piVar4 = param_4;
  piVar3 = param_3;
  iVar2 = param_2;
  iVar5 = *(int *)(param_2 + 4);
  local_8 = 0;
  if (iVar5 == 1) {
    *param_3 = 1;
    *param_4 = 0;
    while (((((*(int *)(param_2 + 4) == 1 && (iVar5 = *(int *)(param_2 + 8), iVar5 != 0)) &&
             (*(int *)(iVar5 + 4) == 6)) &&
            ((*(int *)(iVar5 + 0x10) == 1 && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)))) &&
           ((*(int *)(iVar5 + 4) == 0xb && (*(int *)(iVar5 + 0x20) != 0))))) {
      iVar5 = FUN_008c228d(param_1,*(int *)(iVar5 + 0x20),&param_3,&param_4);
      if (iVar5 < 0) {
        return iVar5;
      }
      *piVar4 = *piVar4 + (int)param_3 * (int)param_4;
      param_2 = *(int *)(param_2 + 0xc);
      if (param_2 == 0) {
        return iVar5;
      }
    }
  }
  else {
    if (iVar5 == 8) {
      piVar1 = (int *)(param_2 + 0x14);
      param_2 = 0;
      if (*piVar1 != 0) {
        do {
          local_8 = FUN_008c228d(param_1,*(undefined4 *)(iVar2 + 0x10),piVar3,piVar4);
          if (local_8 < 0) {
            return local_8;
          }
          param_2 = param_2 + 1;
        } while (param_2 < *(uint *)(iVar2 + 0x14));
      }
      *piVar4 = *(int *)(iVar2 + 0x14) * *piVar3 * *piVar4;
      *piVar3 = 1;
      return local_8;
    }
    if ((iVar5 == 9) && (iVar5 = *(int *)(param_2 + 0x10), -1 < iVar5)) {
      if (iVar5 < 3) {
        *param_3 = *(int *)(param_2 + 0x18);
        iVar5 = *(int *)(param_2 + 0x1c);
      }
      else {
        if (iVar5 != 3) {
          return -0x7fffbffb;
        }
        iVar5 = 1;
        *param_3 = 1;
      }
      *param_4 = iVar5;
      iVar5 = *param_3;
      param_3 = (int *)0x0;
      if (iVar5 * *param_4 == 0) {
        return 0;
      }
      do {
        iVar5 = *(int *)(*param_1 + 8);
        *(undefined4 *)(iVar5 + 0x10) = 0;
        *(undefined4 *)(iVar5 + 0x14) = 0;
        *(undefined4 *)(iVar5 + 0x18) = 0;
        *(undefined4 *)(iVar5 + 0x1c) = 0;
        switch(*(undefined4 *)(param_2 + 0x14)) {
        case 0:
          *(undefined4 *)(*(int *)(*param_1 + 8) + 0x10) = 0;
          break;
        case 1:
        case 2:
        case 3:
        case 4:
          *(undefined4 *)(*(int *)(*param_1 + 8) + 0x10) = 1;
          break;
        case 5:
        case 6:
        case 7:
        case 8:
          *(undefined4 *)(*(int *)(*param_1 + 8) + 0x10) = 2;
          break;
        case 9:
        case 10:
        case 0xb:
        case 0xc:
          *(undefined4 *)(*(int *)(*param_1 + 8) + 0x10) = 3;
          break;
        case 0xd:
        case 0xe:
        case 0xf:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x19:
        case 0x1a:
        case 0x1b:
        case 0x1c:
          *(undefined4 *)(*(int *)(*param_1 + 8) + 0x10) = 5;
          break;
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x1d:
          *(undefined4 *)(*(int *)(*param_1 + 8) + 0x10) = 4;
          break;
        default:
          goto LAB_008c2443;
        }
        param_3 = (int *)((int)param_3 + 1);
        *param_1 = *(int *)(*param_1 + 0xc);
        if ((uint)(*piVar3 * *param_4) <= param_3) {
          return 0;
        }
      } while( true );
    }
  }
LAB_008c2443:
  return -0x7fffbffb;
}


// ==== FUN_008c2483 @ 0x008c2483 ====

int FUN_008c2483(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = *(int *)(param_1 + 4);
  if (iVar4 == 1) {
    do {
      iVar4 = FUN_008c2483(*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x18) + 0x20),param_2);
      if (iVar4 < 0) {
        return iVar4;
      }
      param_1 = *(int *)(param_1 + 0xc);
    } while (param_1 != 0);
    return iVar4;
  }
  if (iVar4 == 8) {
    uVar5 = 0;
    if (*(int *)(param_1 + 0x14) == 0) {
      return 0;
    }
    do {
      iVar4 = FUN_008c2483(*(undefined4 *)(param_1 + 0x10),param_2);
      if (iVar4 < 0) {
        return iVar4;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 0x14));
    return iVar4;
  }
  if ((iVar4 == 9) && (iVar4 = *(int *)(param_1 + 0x10), -1 < iVar4)) {
    if (iVar4 < 3) {
      iVar4 = *(int *)(param_1 + 0x1c) * *(int *)(param_1 + 0x18);
    }
    else {
      if (iVar4 != 3) goto switchD_008c24d7_default;
      iVar4 = 1;
    }
    switch(*(undefined4 *)(param_1 + 0x14)) {
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x1d:
      iVar3 = 0;
      break;
    case 0x19:
    case 0x1a:
      *(int *)(in_ECX + 0x334) = *(int *)(in_ECX + 0x334) + 1;
    case 0xe:
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
      piVar1 = (int *)(in_ECX + 0x330);
      *(int *)*param_2 = *piVar1;
      *piVar1 = *piVar1 + 1;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0x1b:
    case 0x1c:
      iVar3 = 4;
      break;
    default:
      goto switchD_008c24d7_default;
    }
    iVar2 = 0;
    *param_2 = *param_2 + iVar3 * iVar4;
  }
  else {
switchD_008c24d7_default:
    iVar2 = -0x7fffbffb;
  }
  return iVar2;
}


// ==== FUN_008c257d @ 0x008c257d ====

int FUN_008c257d(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6,
                int param_7,int param_8)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar5 = param_1;
  iVar3 = *(int *)(param_1 + 4);
  local_c = 0;
  local_8 = 5;
  local_10 = 0;
  if (iVar3 == 1) {
    iVar3 = FUN_008c1bfa(&local_c,4,param_7);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = FUN_008c1bfa(&local_8,4,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    param_7 = 0;
    iVar3 = iVar5;
    do {
      iVar3 = *(int *)(iVar3 + 0xc);
      param_7 = param_7 + 1;
    } while (iVar3 != 0);
    param_1 = iVar5;
    if ((param_2 == 0) || (param_6 == 0)) {
      iVar3 = FUN_008c1bfa(&local_10,4,0);
    }
    else {
      iVar3 = FUN_008c1cb1(*(undefined4 *)(param_2 + 8),&param_2);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar3 = FUN_008c1d03(param_2,0);
    }
    if (iVar3 < 0) {
      return iVar3;
    }
    if ((param_3 == 0) || (param_6 == 0)) {
      iVar3 = FUN_008c1bfa(&local_10,4,0);
    }
    else {
      iVar3 = FUN_008c1cb1(param_3,&param_2);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar3 = FUN_008c1d03(param_2,0);
    }
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = FUN_008c1bfa(&param_4,4,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = FUN_008c1bfa(&param_7,4,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar5 = param_1;
    while( true ) {
      if (iVar5 == 0) {
        return iVar3;
      }
      if (*(int *)(iVar5 + 4) != 1) {
        return -0x7fffbffb;
      }
      iVar3 = *(int *)(iVar5 + 8);
      if (iVar3 == 0) {
        return -0x7fffbffb;
      }
      if (*(int *)(iVar3 + 4) != 6) {
        return -0x7fffbffb;
      }
      iVar1 = *(int *)(iVar3 + 0x14);
      if (iVar1 == 0) {
        return -0x7fffbffb;
      }
      if (*(int *)(iVar1 + 4) != 3) {
        return -0x7fffbffb;
      }
      if (*(int *)(iVar1 + 0x10) != 9) {
        return -0x7fffbffb;
      }
      if (*(int *)(iVar1 + 0x18) == 0) break;
      if (*(int *)(iVar3 + 0x10) != 1) {
        return -0x7fffbffb;
      }
      iVar3 = *(int *)(iVar3 + 0x18);
      if (iVar3 == 0) {
        return -0x7fffbffb;
      }
      if (*(int *)(iVar3 + 4) != 0xb) {
        return -0x7fffbffb;
      }
      if (*(int *)(iVar3 + 0x20) == 0) {
        return -0x7fffbffb;
      }
      iVar2 = *(int *)(iVar3 + 0x2c);
      uVar4 = 0;
      if (iVar2 != 0) {
        if (*(int *)(iVar2 + 4) != 3) {
          return -0x7fffbffb;
        }
        if (*(int *)(iVar2 + 0x10) != 9) {
          return -0x7fffbffb;
        }
        uVar4 = *(undefined4 *)(iVar2 + 0x18);
      }
      iVar3 = FUN_008c257d(*(int *)(iVar3 + 0x20),(int *)(iVar1 + 0x10),uVar4,0,param_5,param_6,0,1)
      ;
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar5 = *(int *)(iVar5 + 0xc);
    }
    return -0x7fffbffb;
  }
  if (iVar3 == 8) {
    iVar3 = param_4;
    if (param_4 == 0) {
      iVar3 = 1;
    }
    iVar3 = FUN_008c257d(*(undefined4 *)(param_1 + 0x10),param_2,param_3,
                         *(int *)(param_1 + 0x14) * iVar3,param_5,param_6,param_7,0);
    return iVar3;
  }
  if (iVar3 != 9) {
    return -0x7fffbffb;
  }
  iVar3 = *(int *)(param_1 + 0x10);
  if (iVar3 != 0) {
    if (iVar3 == 1) {
      local_8 = *(undefined4 *)(param_1 + 0x1c);
      local_c = *(undefined4 *)(param_1 + 0x18);
      param_8 = 1;
      goto LAB_008c2619;
    }
    if (iVar3 == 2) {
      local_8 = *(undefined4 *)(param_1 + 0x18);
      local_c = *(undefined4 *)(param_1 + 0x1c);
      param_8 = 2;
      goto LAB_008c2619;
    }
    if (iVar3 != 3) {
      return -0x7fffbffb;
    }
    if (param_8 == 0) {
      param_8 = 4;
      local_8 = 0;
      local_c = 0;
      goto LAB_008c2619;
    }
    pcVar6 = s_ID3DXEffectCompiler__Only_numeri_00a1aec8;
    goto LAB_008c27f9;
  }
  local_c = 1;
  param_8 = 0;
  local_8 = 1;
LAB_008c2619:
  switch(*(undefined4 *)(param_1 + 0x14)) {
  case 0:
    param_1 = 1;
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
    param_1 = 2;
    break;
  case 9:
  case 10:
  case 0xb:
  case 0xc:
    param_1 = 3;
    break;
  case 0xe:
    param_1 = 4;
    break;
  case 0xf:
    param_1 = 5;
    goto LAB_008c27eb;
  case 0x10:
    param_1 = 6;
    goto LAB_008c27eb;
  case 0x11:
    param_1 = 7;
    goto LAB_008c27eb;
  case 0x12:
    param_1 = 8;
    goto LAB_008c27eb;
  case 0x13:
    param_1 = 9;
    goto LAB_008c27eb;
  case 0x14:
    param_1 = 10;
    break;
  case 0x15:
    param_1 = 0xb;
    break;
  case 0x16:
    param_1 = 0xc;
    break;
  case 0x17:
    param_1 = 0xd;
    break;
  case 0x18:
    param_1 = 0xe;
    break;
  case 0x19:
    param_1 = 0xf;
    break;
  case 0x1a:
    param_1 = 0x10;
    break;
  case 0x1b:
    param_1 = 0x11;
    goto LAB_008c27eb;
  case 0x1c:
    param_1 = 0x12;
    goto LAB_008c27eb;
  case 0x1d:
    param_1 = 0xf30000;
LAB_008c27eb:
    if (param_4 != 0) {
      pcVar6 = s_ID3DXEffectCompiler__Arrays_must_00a1ae78;
LAB_008c27f9:
      FUN_008bd320(in_ECX + 0x28,param_2,0,pcVar6);
LAB_008c280e:
      return -0x7fffbffb;
    }
    break;
  default:
    goto LAB_008c280e;
  }
  iVar3 = FUN_008c1bfa(&param_1,4,param_7);
  if (-1 < iVar3) {
    iVar3 = FUN_008c1bfa(&param_8,4,0);
    iVar5 = param_6;
    if (-1 < iVar3) {
      if ((param_2 == 0) || (param_6 == 0)) {
        iVar3 = FUN_008c1bfa(&local_10,4,0);
      }
      else {
        iVar3 = FUN_008c1cb1(*(undefined4 *)(param_2 + 8),&param_2);
        if (iVar3 < 0) {
          return iVar3;
        }
        iVar3 = FUN_008c1d03(param_2,0);
      }
      if (-1 < iVar3) {
        if ((param_3 == 0) || (iVar5 == 0)) {
          iVar3 = FUN_008c1bfa(&local_10,4,0);
        }
        else {
          iVar3 = FUN_008c1cb1(param_3,&param_2);
          if (iVar3 < 0) {
            return iVar3;
          }
          iVar3 = FUN_008c1d03(param_2,0);
        }
        if ((((-1 < iVar3) && (iVar3 = FUN_008c1bfa(&param_4,4,0), -1 < iVar3)) && (0 < param_1)) &&
           ((param_1 < 4 && (iVar3 = FUN_008c1bfa(&local_8,4,0), -1 < iVar3)))) {
          iVar3 = FUN_008c1bfa(&local_c,4,0);
        }
      }
    }
  }
  return iVar3;
}


// ==== FUN_008c2aa4 @ 0x008c2aa4 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_008c2aa4(int *param_1,uint param_2,int param_3,undefined **param_4,int *param_5,
                undefined4 param_6,undefined4 param_7,float param_8)

{
  float fVar1;
  int *piVar2;
  float *pfVar3;
  float fVar4;
  int extraout_EAX;
  int *piVar5;
  undefined **ppuVar6;
  int extraout_EAX_00;
  int iVar7;
  int in_ECX;
  uint uVar8;
  uint uVar9;
  int iVar10;
  float *pfVar11;
  bool bVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar16;
  float10 extraout_ST0_01;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  char *pcVar17;
  undefined *puVar18;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int *local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  float *local_c;
  int local_8;
  
  piVar2 = param_1;
  piVar5 = (int *)param_1[10];
  iVar10 = 0;
  local_c = (float *)0x0;
  local_20 = (int *)0x0;
  local_10 = 0;
  local_2c = 0;
  if (piVar5 != (int *)0x0) {
    do {
      if (*param_1 == *piVar5) {
        if (param_8 != -NAN) {
          return 0;
        }
        if (param_1[1] == piVar5[1]) {
          return 0;
        }
      }
      piVar5 = (int *)piVar5[10];
    } while (piVar5 != (int *)0x0);
  }
  iVar7 = *param_1;
  uVar9 = param_1[2];
  local_18 = param_1[3];
  local_34 = param_1[1];
  local_24 = param_1[4];
  local_28 = param_1[5];
  local_30 = param_1[6];
  param_8 = (float)param_1[8];
  param_1 = (int *)iVar7;
  local_8 = in_ECX;
  if (*(int *)(uVar9 + 4) == 1) {
    iVar7 = *(int *)(uVar9 + 8);
    if (iVar7 == 0) {
      return -0x7fffbffb;
    }
    if (*(int *)(iVar7 + 4) == 3) {
      if ((*(int *)(iVar7 + 0x10) < 5) || (8 < *(int *)(iVar7 + 0x10))) {
        param_8 = 0.0;
        for (param_2 = uVar9; param_2 != 0; param_2 = *(uint *)(param_2 + 0xc)) {
          if (*(int *)(param_2 + 4) != 1) {
            return -0x7fffbffb;
          }
          iVar10 = *(int *)(param_2 + 8);
          if (iVar10 == 0) {
            return -0x7fffbffb;
          }
          if (*(int *)(iVar10 + 4) != 3) {
            return -0x7fffbffb;
          }
          iVar7 = *(int *)(iVar10 + 0x10);
          if (iVar7 < 2) {
LAB_008c3406:
            puVar18 = (&PTR_s_ZENABLE_00a184b8)[(int)param_1 * 7];
            pcVar17 = s_ID3DXEffectCompiler__State___s__a_00a1b020;
            goto LAB_008c2b39;
          }
          if (iVar7 < 5) {
            uVar9 = *(uint *)(iVar10 + 0x18);
          }
          else {
            if (iVar7 != 9) goto LAB_008c3406;
            if (*(int *)(iVar10 + 0x18) == 0) {
              return -0x7fffbffb;
            }
            param_4 = &PTR_PTR_00a184d0 + (int)param_1 * 7;
            piVar5 = (int *)*param_4;
            if (piVar5 == (int *)0x0) {
LAB_008c33d9:
              FUN_008bd320(local_8 + 0x28,piVar2[9],0,s_ID3DXEffectCompiler__State___s__d_00a1b060,
                           (&PTR_s_ZENABLE_00a184b8)[(int)param_1 * 7],
                           *(undefined4 *)(iVar10 + 0x18));
              return -0x7fffbffb;
            }
            param_3 = 0;
            iVar7 = *piVar5;
            while ((iVar7 != 0 &&
                   (iVar7 = __stricmp((char *)piVar5[param_3 * 2],*(char **)(iVar10 + 0x18)),
                   iVar7 != 0))) {
              param_3 = param_3 + 1;
              piVar5 = (int *)*param_4;
              iVar7 = piVar5[param_3 * 2];
            }
            if (*(int *)(*param_4 + param_3 * 8) == 0) goto LAB_008c33d9;
            uVar9 = *(uint *)((int)(*param_4 + param_3 * 8) + 4);
          }
          param_8 = (float)((uint)param_8 | uVar9);
        }
        iVar10 = (&DAT_00a184cc)[(int)param_1 * 7];
        if (iVar10 == 0x5000000) {
          if (param_8 == 0.0) {
            FUN_008bd320(local_8 + 0x28,piVar2[9],0,s_ID3DXEffectCompiler__FVFs_must_n_00a1af98);
            return -0x7fffbffb;
          }
        }
        else if (iVar10 == 0x9000000) {
LAB_008c3450:
          if (param_8 != 0.0) {
            puVar18 = (&PTR_s_ZENABLE_00a184b8)[(int)param_1 * 7];
            pcVar17 = s_ID3DXEffectCompiler__Dword_expre_00a1afd0;
LAB_008c2b39:
            FUN_008bd320(local_8 + 0x28,piVar2[9],0,pcVar17,puVar18);
            return -0x7fffbffb;
          }
        }
        else if (iVar10 == 0xa000000) {
          if (param_8 != 0.0) {
            param_1 = (int *)0x0;
            if (PTR_s_ZENABLE_00a184b8 != (undefined *)0x0) {
              ppuVar6 = &PTR_s_ZENABLE_00a184b8;
              do {
                if (ppuVar6[5] == (undefined *)0x5000000) break;
                param_1 = (int *)((int)param_1 + 1);
                ppuVar6 = ppuVar6 + 7;
              } while (*ppuVar6 != (undefined *)0x0);
            }
            local_2c = 1;
          }
        }
        else {
          if (iVar10 == 0xb000000) goto LAB_008c3450;
          if (iVar10 == 0xe000000) {
            return 0;
          }
          if (iVar10 == 0xf000000) {
            return 0;
          }
        }
        param_2 = 0;
      }
      else {
        param_8 = (float)*(double *)(iVar7 + 0x18);
      }
      iVar10 = FUN_008c1bfa(&param_8,4,&local_14);
      if (iVar10 < 0) {
        return iVar10;
      }
    }
    else if (*(int *)(iVar7 + 4) == 0xd) {
      pfVar3 = operator_new((uint)param_8);
      local_c = pfVar3;
      if (pfVar3 != (float *)0x0) {
        pfVar11 = pfVar3;
        for (uVar9 = (uint)param_8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
          *pfVar11 = 0.0;
          pfVar11 = pfVar11 + 1;
        }
        for (uVar9 = (uint)param_8 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined1 *)pfVar11 = 0;
          pfVar11 = (float *)((int)pfVar11 + 1);
        }
        param_2 = piVar2[2];
        if (param_2 != 0) {
          do {
            if (((*(int *)(param_2 + 4) != 1) || (iVar10 = *(int *)(param_2 + 8), iVar10 == 0)) ||
               (*(int *)(iVar10 + 4) != 0xd)) goto LAB_008c2ec8;
            param_3 = 0;
            if (((*(int *)(iVar10 + 0x1c) == 5) && (iVar7 = *(int *)(iVar10 + 0x20), iVar7 != 0)) &&
               (*(int *)(iVar7 + 4) == 0xd)) {
              param_3 = 1;
              while ((iVar10 = iVar7, *(int *)(iVar10 + 0x1c) == 0 &&
                     (iVar7 = *(int *)(iVar10 + 0x20), iVar7 != 0))) {
                if ((*(int *)(iVar7 + 4) != 1) ||
                   ((iVar7 = *(int *)(iVar7 + 8), iVar7 == 0 || (*(int *)(iVar7 + 4) != 0xd))))
                break;
              }
            }
            if ((*(int *)(iVar10 + 0x1c) != 0) ||
               ((((iVar10 = *(int *)(iVar10 + 0x20), iVar10 == 0 || (*(int *)(iVar10 + 4) != 1)) ||
                 (iVar10 = *(int *)(iVar10 + 8), iVar10 == 0)) ||
                ((*(int *)(iVar10 + 4) != 0xe || (*(int *)(iVar10 + 0x10) == 6)))))) {
              pcVar17 = s_ID3DXEffectCompiler__Initializer_00a1b0a0;
LAB_008c2eb5:
              FUN_008bd320(local_8 + 0x28,piVar2[9],0,pcVar17);
              goto LAB_008c2ec8;
            }
            iVar7 = *(int *)(&DAT_00a184bc + (int)param_1 * 0x1c);
            if (iVar7 == 1) {
              iVar7 = *(int *)(iVar10 + 0x10);
              if (((iVar7 == 0) || (iVar7 == 1)) || (iVar7 == 2)) {
                *pfVar3 = (float)(uint)(*(int *)(iVar10 + 0x18) != 0);
              }
              else {
                if (iVar7 != 3) {
LAB_008c2ea9:
                  pcVar17 = s_ID3DXEffectCompiler__Unexpected_e_00a1b0fc;
                  goto LAB_008c2eb5;
                }
                *pfVar3 = (float)(uint)(_DAT_0099d098 != *(double *)(iVar10 + 0x18));
              }
            }
            else if (iVar7 == 2) {
              iVar7 = *(int *)(iVar10 + 0x10);
              if (iVar7 == 0) {
                *pfVar3 = (float)(uint)(*(int *)(iVar10 + 0x18) != 0);
              }
              else if ((iVar7 == 1) || (iVar7 == 2)) {
                *pfVar3 = *(float *)(iVar10 + 0x18);
              }
              else {
                if (iVar7 != 3) goto LAB_008c2ea9;
                fVar4 = (float)__ftol();
                *pfVar3 = fVar4;
              }
              if (param_3 != 0) {
                *pfVar3 = (float)-(int)*pfVar3;
              }
            }
            else {
              if ((iVar7 != 3) && (iVar7 != 0xf20000)) {
                pcVar17 = s_ID3DXEffectCompiler__Error_in_ty_00a1b124;
                goto LAB_008c2eb5;
              }
              iVar7 = *(int *)(iVar10 + 0x10);
              if (iVar7 == 0) {
                fVar4 = (float)(*(int *)(iVar10 + 0x18) != 0);
              }
              else if (iVar7 == 1) {
                fVar4 = (float)*(int *)(iVar10 + 0x18);
              }
              else if (iVar7 == 2) {
                fVar4 = (float)*(int *)(iVar10 + 0x18);
                if (*(int *)(iVar10 + 0x18) < 0) {
                  fVar4 = fVar4 + _DAT_0099d104;
                }
              }
              else {
                if (iVar7 != 3) goto LAB_008c2ea9;
                fVar4 = (float)*(double *)(iVar10 + 0x18);
              }
              *pfVar3 = fVar4;
              if (param_3 != 0) {
                *pfVar3 = -*pfVar3;
              }
            }
            param_2 = *(uint *)(param_2 + 0xc);
            pfVar3 = pfVar3 + 1;
          } while (param_2 != 0);
        }
        if (*(int *)(&DAT_00a184bc + (int)param_1 * 0x1c) == 0xf20000) {
          fVar13 = (float10)local_c[3];
          fVar14 = (float10)DAT_0099d080;
          fVar4 = local_c[1];
          fVar1 = local_c[2];
          fVar15 = (float10)DAT_0099cdc8;
          if ((float10)*local_c < fVar14) {
            fVar16 = (float10)*local_c;
            if ((NAN(fVar16) || NAN(fVar15)) || fVar16 < fVar15 == (fVar16 == fVar15)) {
              fVar13 = fVar14;
              param_8 = (float)__ftol();
              fVar15 = extraout_ST0;
              fVar14 = extraout_ST1;
            }
            else {
              param_8 = 0.0;
            }
          }
          else {
            param_8 = 3.57331e-43;
          }
          if ((float10)fVar4 < fVar14) {
            fVar16 = (float10)fVar4;
            if ((NAN(fVar16) || NAN(fVar15)) || fVar16 < fVar15 == (fVar16 == fVar15)) {
              fVar13 = fVar14;
              param_2 = __ftol();
              fVar15 = extraout_ST0_00;
              fVar14 = extraout_ST1_00;
            }
            else {
              param_2 = 0;
            }
          }
          else {
            param_2 = 0xff;
          }
          if ((float10)fVar1 < fVar14) {
            fVar16 = (float10)fVar1;
            if ((NAN(fVar16) || NAN(fVar15)) || fVar16 < fVar15 == (fVar16 == fVar15)) {
              uVar9 = __ftol();
              fVar14 = extraout_ST0_01;
              fVar13 = extraout_ST1_01;
            }
            else {
              uVar9 = 0;
            }
          }
          else {
            uVar9 = 0xff;
          }
          if (fVar13 < fVar14) {
            fVar14 = (float10)DAT_0099cdc8;
            if ((NAN(fVar13) || NAN(fVar14)) || fVar13 < fVar14 == (fVar13 == fVar14)) {
              iVar10 = __ftol();
            }
            else {
              iVar10 = 0;
            }
          }
          else {
            iVar10 = 0xff;
          }
          local_18 = 2;
          param_8 = (float)(((iVar10 << 8 | (uint)param_8) << 8 | param_2) << 8 | uVar9);
          local_24 = 1;
          local_28 = 1;
          iVar10 = FUN_008c1bfa(&param_8,4,&local_14);
        }
        else {
          iVar10 = FUN_008c1bfa(local_c,param_8,&local_14);
        }
        if (-1 < iVar10) {
          _free(local_c);
          return extraout_EAX;
        }
        goto LAB_008c33c1;
      }
LAB_008c2c84:
      iVar10 = -0x7ff8fff2;
      goto LAB_008c33c1;
    }
  }
  else {
    if (*(int *)(uVar9 + 4) != 0xd) {
      puVar18 = (&PTR_s_ZENABLE_00a184b8)[iVar7 * 7];
      pcVar17 = s_ID3DXEffectCompiler__State___s__w_00a1b150;
      goto LAB_008c2b39;
    }
    if (local_18 < 5) {
LAB_008c2b72:
      local_c = operator_new((uint)param_8);
      if (local_c == (float *)0x0) goto LAB_008c2c84;
      pfVar3 = local_c;
      for (uVar8 = (uint)param_8 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pfVar3 = 0.0;
        pfVar3 = pfVar3 + 1;
      }
      for (uVar8 = (uint)param_8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)pfVar3 = 0;
        pfVar3 = (float *)((int)pfVar3 + 1);
      }
      iVar10 = FUN_008c1bfa(local_c,param_8,&local_14);
      if (iVar10 < 0) goto LAB_008c33c1;
    }
    else if (local_18 < 10) {
LAB_008c2bd1:
      iVar10 = FUN_008c1bfa(in_ECX + 0x330,4,&local_14);
      if (iVar10 < 0) {
        return iVar10;
      }
      *(int *)(local_8 + 0x330) = *(int *)(local_8 + 0x330) + 1;
    }
    else if (local_18 < 0xf) {
      iVar10 = FUN_008c1bfa(&local_10,4,&local_14);
      if (iVar10 < 0) {
        return iVar10;
      }
    }
    else {
      if (local_18 < 0x11) {
        *(int *)(in_ECX + 0x334) = *(int *)(in_ECX + 0x334) + 1;
        goto LAB_008c2bd1;
      }
      if (local_18 != 0xf30000) goto LAB_008c2b72;
    }
    local_20 = operator_new(0x24);
    if (local_20 == (int *)0x0) {
      local_20 = (int *)0x0;
    }
    else {
      local_20[6] = 0;
    }
    if (local_20 == (int *)0x0) {
LAB_008c2ec8:
      iVar10 = -0x7fffbffb;
      goto LAB_008c33c1;
    }
    *local_20 = (int)param_1;
    local_20[1] = param_2;
    local_20[2] = param_3;
    local_20[3] = (int)param_4;
    local_20[4] = *param_5;
    local_20[5] = uVar9;
  }
  if (local_18 == 0) {
    iVar7 = FUN_008c257d(*(undefined4 *)(piVar2[2] + 0x10),0,0,0,param_7,0,&local_1c,0);
    if (iVar7 < 0) {
      FUN_008bd320(local_8 + 0x28,piVar2[9],0,s_ID3DXEffectCompiler__Error_initi_00a1af10);
      goto LAB_008c33b3;
    }
LAB_008c3218:
    iVar10 = FUN_008c1bfa(&param_1,4,0);
    if (((-1 < iVar10) && (iVar10 = FUN_008c1bfa(&local_34,4,0), -1 < iVar10)) &&
       (iVar10 = FUN_008c1d03(local_1c,0), -1 < iVar10)) {
      iVar10 = FUN_008c1d03(local_14,0);
      piVar5 = local_20;
      if (-1 < iVar10) {
        if (local_20 != (int *)0x0) {
          local_20[8] = local_1c;
          local_20 = (int *)0x0;
          piVar5[7] = local_14;
          piVar5[6] = *(int *)(local_8 + 0x354);
          *(int *)(local_8 + 0x354) = (int)piVar5;
        }
        *param_5 = *param_5 + 1;
        if (local_2c != 0) {
          param_1 = (int *)0x4;
          local_18 = 0x10;
          iVar10 = FUN_008c1bfa(&local_18,4,&local_1c);
          if (((-1 < iVar10) && (iVar10 = FUN_008c1bfa(&param_1,4,0), -1 < iVar10)) &&
             ((iVar10 = FUN_008c1bfa(&local_10,4,0), -1 < iVar10 &&
              ((iVar10 = FUN_008c1bfa(&local_10,4,0), -1 < iVar10 &&
               (iVar10 = FUN_008c1bfa(&local_10,4,0), -1 < iVar10)))))) {
            param_1 = (int *)0x0;
            if (PTR_s_ZENABLE_00a184b8 != (undefined *)0x0) {
              ppuVar6 = &PTR_s_ZENABLE_00a184b8;
              do {
                if (ppuVar6[5] == (undefined *)0xa000000) break;
                param_1 = (int *)((int)param_1 + 1);
                ppuVar6 = ppuVar6 + 7;
              } while (*ppuVar6 != (undefined *)0x0);
            }
            iVar10 = FUN_008c1bfa(&param_1,4,0);
            if ((((-1 < iVar10) && (iVar10 = FUN_008c1bfa(&local_10,4,0), -1 < iVar10)) &&
                (iVar10 = FUN_008c1d03(local_1c,0), -1 < iVar10)) &&
               (iVar10 = FUN_008c1bfa(&local_10,4,0), -1 < iVar10)) {
              *param_5 = *param_5 + 1;
            }
          }
        }
      }
    }
  }
  else if (local_18 < 1) {
LAB_008c358b:
    FUN_008bd320(local_8 + 0x28,piVar2[9],0,s_ID3DXEffectCompiler__Internal_er_00a1af48);
    iVar10 = -0x7fffbffb;
  }
  else {
    if (local_18 < 4) {
      uVar9 = (&DAT_00a184cc)[(int)param_1 * 7];
      if (uVar9 < 0xd000005) {
        if (uVar9 < 0xd000000) {
          if (uVar9 < 0xc000000) goto LAB_008c34d9;
          if ((0xc000004 < uVar9) && (uVar9 != 0xc010000)) {
            bVar12 = uVar9 == 0xc020000;
            goto LAB_008c34d7;
          }
        }
LAB_008c34e2:
        param_8 = 4.2039e-45;
      }
      else {
        if (uVar9 == 0xd010000) goto LAB_008c34e2;
        bVar12 = uVar9 == 0xd020000;
LAB_008c34d7:
        if (bVar12) goto LAB_008c34e2;
LAB_008c34d9:
        param_8 = 2.8026e-45;
      }
      iVar10 = FUN_008c1bfa(&local_18,4,&local_1c);
      if (((((iVar10 < 0) || (iVar10 = FUN_008c1bfa(&param_8,4,0), iVar10 < 0)) ||
           (iVar10 = FUN_008c1bfa(&local_10,4,0), iVar10 < 0)) ||
          ((iVar10 = FUN_008c1bfa(&local_10,4,0), iVar10 < 0 ||
           (iVar10 = FUN_008c1bfa(&local_30,4,0), iVar10 < 0)))) ||
         (iVar10 = FUN_008c1bfa(&local_24,4,0), iVar10 < 0)) goto LAB_008c33b3;
      piVar5 = &local_28;
    }
    else {
      if ((local_18 < 5) || (0x10 < local_18)) goto LAB_008c358b;
      param_8 = 5.60519e-45;
      iVar10 = FUN_008c1bfa(&local_18,4,&local_1c);
      if ((((iVar10 < 0) || (iVar10 = FUN_008c1bfa(&param_8,4,0), iVar10 < 0)) ||
          (iVar10 = FUN_008c1bfa(&local_10,4,0), iVar10 < 0)) ||
         (iVar10 = FUN_008c1bfa(&local_10,4,0), iVar10 < 0)) goto LAB_008c33b3;
      piVar5 = &local_10;
    }
    iVar10 = FUN_008c1bfa(piVar5,4,0);
    if (-1 < iVar10) goto LAB_008c3218;
  }
LAB_008c33b3:
  if (local_20 != (int *)0x0) {
    FUN_008c1b5d(1);
  }
LAB_008c33c1:
  if (local_c == (float *)0x0) {
    return iVar10;
  }
  _free(local_c);
  return extraout_EAX_00;
}


// ==== FUN_008c35ef @ 0x008c35ef ====

int FUN_008c35ef(int param_1,undefined4 *param_2,int *param_3,int *param_4,int *param_5,int *param_6
                ,int *param_7,int *param_8,undefined4 param_9)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  iVar2 = 0;
  if (*(int *)(param_1 + 4) == 1) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == 0) {
      return -0x7fffbffb;
    }
    if (*(int *)(iVar1 + 4) == 3) {
      if ((*(int *)(iVar1 + 0x10) < 5) || (8 < *(int *)(iVar1 + 0x10))) {
        *param_3 = 2;
      }
      else {
        *param_3 = 3;
      }
      *param_4 = 1;
      *param_5 = 1;
      *param_6 = 0;
      *param_7 = 0;
      *param_8 = 4;
      return 0;
    }
    if (*(int *)(iVar1 + 4) == 0xd) {
      while( true ) {
        if (*(int *)(param_1 + 4) != 1) {
          return -0x7fffbffb;
        }
        iVar1 = *(int *)(param_1 + 8);
        if (iVar1 == 0) {
          return -0x7fffbffb;
        }
        if (*(int *)(iVar1 + 4) != 0xd) {
          return -0x7fffbffb;
        }
        if (*(int *)(iVar1 + 0x10) == 0) {
          return -0x7fffbffb;
        }
        iVar1 = FUN_008c1e12(*(int *)(iVar1 + 0x10),param_3,param_4,param_5,param_6,param_7,param_8)
        ;
        if (iVar1 < 0) {
          return iVar1;
        }
        iVar4 = *param_3;
        if (((((iVar4 != 3) && (iVar4 != 2)) && (iVar4 != 1)) ||
            ((*param_5 != 1 || (*param_4 != 1)))) || ((*param_6 != 0 || (*param_7 != 0)))) break;
        param_1 = *(int *)(param_1 + 0xc);
        iVar2 = iVar2 + 1;
        if (param_1 == 0) {
          if ((param_2[1] == 3) || (param_2[1] == 0xf20000)) {
            iVar4 = 3;
          }
          else {
            iVar4 = 2;
          }
          *param_3 = iVar4;
          *param_4 = iVar2;
          *param_5 = 1;
          *param_6 = 0;
          *param_7 = 0;
          *param_8 = iVar2 * 4;
          return iVar1;
        }
      }
      pcVar3 = s_ID3DXEffectCompiler__Initializer_00a1b194;
      goto LAB_008c366a;
    }
  }
  else if (*(int *)(param_1 + 4) == 0xd) {
    iVar2 = FUN_008c1e12(*(undefined4 *)(param_1 + 0x10),param_3,param_4,param_5,param_6,param_7,
                         param_8);
    if (iVar2 < 0) {
      return iVar2;
    }
    if (*param_3 != 0) {
      return iVar2;
    }
    pcVar3 = s_ID3DXEffectCompiler__Assignment_c_00a1b1d0;
LAB_008c366a:
    FUN_008bd320(in_ECX + 0x28,param_9,0,pcVar3);
    return -0x7fffbffb;
  }
  FUN_008bd320(in_ECX + 0x28,param_9,0,s_ID3DXEffectCompiler__State___s__w_00a1b150,*param_2);
  return -0x7fffbffb;
}


// ==== FUN_008c37bd @ 0x008c37bd ====

undefined4
FUN_008c37bd(undefined4 *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            undefined4 param_7)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  bool bVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  iVar1 = param_1[1];
  if (10 < iVar1) {
    if (iVar1 < 0xf) goto LAB_008c3a91;
    if (iVar1 < 0x11) {
      if ((param_5 == 0) && (param_6 == 0)) {
        if ((iVar1 == param_2) && ((param_3 == 1 && (param_4 == 1)))) {
          return 0;
        }
        if (((param_2 == 2) && (param_3 == 1)) && (param_4 == 1)) {
          return 0;
        }
        uVar5 = *param_1;
        pcVar4 = s_ID3DXEffectCompiler__State___s__w_00a1b258;
        goto LAB_008c3a99;
      }
    }
    else {
      if (iVar1 == 0xf20000) {
        if (param_2 == 3) {
          if (param_3 != 4) {
LAB_008c3a3c:
            if (param_3 != 1) goto LAB_008c3a46;
          }
          if (param_4 == 1) {
            return 0;
          }
        }
        else if ((param_2 == 2) || (param_2 == 1)) goto LAB_008c3a3c;
LAB_008c3a46:
        uVar5 = *param_1;
        pcVar4 = s_ID3DXEffectCompiler__State___s__m_00a1b2a0;
        goto LAB_008c3a99;
      }
      if (iVar1 != 0xf30000) goto LAB_008c3a91;
      if ((param_5 == 0) && (param_6 == 0)) {
        if ((param_3 == 1) && (param_4 == 1)) {
          if (param_2 == 0xf30000) {
            return 0;
          }
          if (param_2 == 2) {
            return 0;
          }
        }
        uVar5 = *param_1;
        pcVar4 = s_ID3DXEffectCompiler__State___s__w_00a1b2f8;
        goto LAB_008c3a99;
      }
    }
LAB_008c3a86:
    uVar5 = *param_1;
    pcVar4 = s_ID3DXEffectCompiler__State___s__c_00a1b460;
    goto LAB_008c3a99;
  }
  if (iVar1 == 10) {
    if ((param_5 == 0) && (param_6 == 0)) {
      if ((param_3 == 1) && (param_4 == 1)) {
        if (param_2 == 10) {
          return 0;
        }
        if (param_2 == 0xb) {
          return 0;
        }
        if (param_2 == 0xc) {
          return 0;
        }
        if (param_2 == 0xd) {
          return 0;
        }
        if (param_2 == 0xe) {
          return 0;
        }
        if (param_2 == 2) {
          return 0;
        }
      }
      uVar5 = *param_1;
      pcVar4 = s_ID3DXEffectCompiler__State___s__w_00a1b340;
      goto LAB_008c3a99;
    }
    goto LAB_008c3a86;
  }
  if (iVar1 < 1) {
LAB_008c3a91:
    uVar5 = *param_1;
    pcVar4 = s_ID3DXEffectCompiler__Unexpected_v_00a1b208;
    goto LAB_008c3a99;
  }
  if (iVar1 < 3) goto LAB_008c3928;
  if (iVar1 != 3) {
    if (iVar1 == 5) {
      if ((param_5 == 0) && (param_6 == 0)) {
        if ((param_3 == 1) && (param_4 == 1)) {
          if (param_2 == 5) {
            return 0;
          }
          if (param_2 == 6) {
            return 0;
          }
          if (param_2 == 7) {
            return 0;
          }
          if (param_2 == 8) {
            return 0;
          }
          if (param_2 == 9) {
            return 0;
          }
          if (param_2 == 2) {
            return 0;
          }
        }
        uVar5 = *param_1;
        pcVar4 = s_ID3DXEffectCompiler__State___s__w_00a1b4b0;
      }
      else {
        uVar5 = *param_1;
        pcVar4 = s_ID3DXEffectCompiler__State___s__c_00a1b460;
      }
      goto LAB_008c3a99;
    }
    goto LAB_008c3a91;
  }
  uVar2 = param_1[5];
  if (uVar2 < 0xd000005) {
    if (uVar2 < 0xd000000) {
      if (uVar2 < 0xc000000) goto LAB_008c38ba;
      if ((0xc000004 < uVar2) && (uVar2 != 0xc010000)) {
        bVar3 = uVar2 == 0xc020000;
        goto LAB_008c38b8;
      }
    }
LAB_008c3928:
    if (param_6 != 0) {
      return 0;
    }
  }
  else {
    if (uVar2 == 0xd010000) goto LAB_008c3928;
    bVar3 = uVar2 == 0xd020000;
LAB_008c38b8:
    if (bVar3) goto LAB_008c3928;
LAB_008c38ba:
    if (param_1[2] != 1) goto LAB_008c3928;
    uVar2 = param_1[3];
    if (uVar2 != 1) {
      if ((2 < uVar2) && (uVar2 < 5)) {
        if ((param_4 == 1) &&
           ((((param_3 == 3 || (param_3 == 4)) && (param_5 == 0)) && (param_6 == 0))))
        goto LAB_008c3932;
        if (((param_2 != 2) || (param_3 != 1)) || (param_4 != 1)) {
          uVar5 = *param_1;
          pcVar4 = s_ID3DXEffectCompiler__State___s__m_00a1b400;
          goto LAB_008c3a99;
        }
      }
      goto LAB_008c3928;
    }
    if (((param_3 != 1) || (param_4 != 1)) || ((param_5 != 0 || (param_6 != 0)))) {
      uVar5 = *param_1;
      pcVar4 = s_ID3DXEffectCompiler__State___s__m_00a1b3c4;
      goto LAB_008c3a99;
    }
  }
LAB_008c3932:
  if (param_2 == 3) {
    return 0;
  }
  if (param_2 == 2) {
    return 0;
  }
  if (param_2 == 1) {
    return 0;
  }
  uVar5 = *param_1;
  pcVar4 = s_ID3DXEffectCompiler__State___s__m_00a1b380;
LAB_008c3a99:
  FUN_008bd320(in_ECX + 0x28,param_7,0,pcVar4,uVar5);
  return 0x80004005;
}


// ==== FUN_008c3ab9 @ 0x008c3ab9 ====

uint FUN_008c3ab9(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  int in_ECX;
  byte *pbVar3;
  int iVar4;
  int *piVar5;
  byte *pbVar6;
  bool bVar7;
  
  if ((byte *)((uint)param_1 & 0x7fffffff) == param_1) {
    for (uVar2 = *(uint *)(in_ECX + 0x34c); uVar2 != 0; uVar2 = *(uint *)(uVar2 + 0x34)) {
      if (param_1 == (byte *)0x0) {
        iVar4 = *(int *)(uVar2 + 0x20);
LAB_008c3b39:
        if (iVar4 == 0) {
          return uVar2;
        }
      }
      else {
        pbVar6 = *(byte **)(uVar2 + 0x20);
        if (pbVar6 != (byte *)0x0) {
          pbVar3 = param_1;
          do {
            bVar1 = *pbVar3;
            bVar7 = bVar1 < *pbVar6;
            if (bVar1 != *pbVar6) {
LAB_008c3b32:
              iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
              goto LAB_008c3b39;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar3[1];
            bVar7 = bVar1 < pbVar6[1];
            if (bVar1 != pbVar6[1]) goto LAB_008c3b32;
            pbVar3 = pbVar3 + 2;
            pbVar6 = pbVar6 + 2;
          } while (bVar1 != 0);
          iVar4 = 0;
          goto LAB_008c3b39;
        }
      }
    }
    uVar2 = 0;
  }
  else {
    piVar5 = (int *)~(uint)param_1;
    if (((*piVar5 == 3) && (piVar5[6] == 0)) && (piVar5[4] == -1)) {
      uVar2 = -(uint)(*(int *)(piVar5[1] + 0x44) != 0) & (uint)piVar5;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


// ==== FUN_008c3b4f @ 0x008c3b4f ====

int FUN_008c3b4f(byte *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  
  if ((byte *)((uint)param_1 & 0x7fffffff) == param_1) {
    for (iVar2 = *(int *)(in_ECX + 0x350); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x28)) {
      if (param_1 == (byte *)0x0) {
        iVar3 = *(int *)(iVar2 + 0x20);
LAB_008c3bba:
        if (iVar3 == 0) {
          return iVar2;
        }
      }
      else {
        pbVar5 = *(byte **)(iVar2 + 0x20);
        if (pbVar5 != (byte *)0x0) {
          pbVar4 = param_1;
          do {
            bVar1 = *pbVar4;
            bVar6 = bVar1 < *pbVar5;
            if (bVar1 != *pbVar5) {
LAB_008c3bb3:
              iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
              goto LAB_008c3bba;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar4[1];
            bVar6 = bVar1 < pbVar5[1];
            if (bVar1 != pbVar5[1]) goto LAB_008c3bb3;
            pbVar4 = pbVar4 + 2;
            pbVar5 = pbVar5 + 2;
          } while (bVar1 != 0);
          iVar3 = 0;
          goto LAB_008c3bba;
        }
      }
    }
    iVar2 = 0;
  }
  else if (*(int *)~(uint)param_1 == 2) {
    iVar2 = ((int *)~(uint)param_1)[1];
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_008c3bd0 @ 0x008c3bd0 ====

int FUN_008c3bd0(byte *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  
  if ((byte *)((uint)param_1 & 0x7fffffff) == param_1) {
    for (iVar2 = *(int *)(in_ECX + 0x348); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x34)) {
      if (param_1 == (byte *)0x0) {
        iVar3 = *(int *)(iVar2 + 0x20);
LAB_008c3c3b:
        if (iVar3 == 0) {
          return iVar2;
        }
      }
      else {
        pbVar5 = *(byte **)(iVar2 + 0x20);
        if (pbVar5 != (byte *)0x0) {
          pbVar4 = param_1;
          do {
            bVar1 = *pbVar4;
            bVar6 = bVar1 < *pbVar5;
            if (bVar1 != *pbVar5) {
LAB_008c3c34:
              iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
              goto LAB_008c3c3b;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar4[1];
            bVar6 = bVar1 < pbVar5[1];
            if (bVar1 != pbVar5[1]) goto LAB_008c3c34;
            pbVar4 = pbVar4 + 2;
            pbVar5 = pbVar5 + 2;
          } while (bVar1 != 0);
          iVar3 = 0;
          goto LAB_008c3c3b;
        }
      }
    }
    iVar2 = 0;
  }
  else if (*(int *)~(uint)param_1 == 0) {
    iVar2 = ((int *)~(uint)param_1)[1];
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_008c3c51 @ 0x008c3c51 ====

int FUN_008c3c51(uint param_1)

{
  int iVar1;
  
  if (((param_1 & 0x7fffffff) == param_1) || (*(int *)~param_1 != 1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = ((int *)~param_1)[1];
  }
  return iVar1;
}


// ==== FUN_008c3c77 @ 0x008c3c77 ====

int FUN_008c3c77(int *param_1,int param_2,undefined4 param_3,uint param_4,undefined4 *param_5,
                int param_6,undefined4 *param_7)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int **ppiVar4;
  int *local_8;
  
  iVar2 = (int)param_1;
  FUN_008c1a16((int)param_1 + 0x10);
  param_1 = (int *)0x0;
  local_8 = (int *)0x0;
  FUN_008f4a60();
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = 0;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  iVar1 = FUN_008c3b4f(param_2);
  if (iVar1 == 0) {
    param_2 = -0x7789f794;
  }
  else {
    param_2 = FUN_008bccd8();
    if (-1 < param_2) {
      param_2 = FUN_00905b5f(iVar2 + 0x10,*(undefined4 *)(iVar2 + 800),*(undefined4 *)(iVar1 + 0x20)
                             ,0,param_3,param_4 | 0x100,&param_1,0);
      if (-1 < param_2) {
        iVar2 = FUN_008bcde3();
        if (iVar2 != 0) {
          param_2 = -0x7789f4a7;
        }
        if (-1 < param_2) {
          ppiVar4 = &local_8;
          uVar3 = (**(code **)(*param_1 + 0xc))(param_1,ppiVar4);
          param_2 = FUN_008f32ec(uVar3,ppiVar4);
          if (-1 < param_2) {
            if (param_5 != (undefined4 *)0x0) {
              *param_5 = param_1;
              param_1 = (int *)0x0;
            }
            if (param_7 != (undefined4 *)0x0) {
              *param_7 = local_8;
              local_8 = (int *)0x0;
            }
          }
        }
      }
    }
  }
  if (param_6 != 0) {
    FUN_008bcd75(param_6);
  }
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
    param_1 = (int *)0x0;
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
    local_8 = (int *)0x0;
  }
  FUN_008f6485();
  FUN_008bf855();
  return param_2;
}


// ==== FUN_008c3db6 @ 0x008c3db6 ====

float FUN_008c3db6(int param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  float *pfVar4;
  int local_14;
  int local_10;
  int *local_c;
  float local_8;
  
  local_8 = 0.0;
  local_c = (int *)0x0;
  FUN_008f4a60();
  local_10 = *(int *)(*(int *)(param_1 + 0x2c) + 0x28);
  if (local_10 != 0) {
    if ((*(int *)(local_10 + 4) == 0xd) && (*(int *)(local_10 + 0x1c) == 0)) {
      do {
        iVar1 = *(int *)(local_10 + 0x20);
        if ((iVar1 == 0) ||
           (((*(int *)(iVar1 + 4) != 1 || (iVar1 = *(int *)(iVar1 + 8), iVar1 == 0)) ||
            (*(int *)(iVar1 + 4) != 0xd)))) break;
        local_10 = iVar1;
      } while (*(int *)(iVar1 + 0x1c) == 0);
      if (((*(int *)(local_10 + 0x1c) == 0) && (local_14 = *(int *)(local_10 + 0x20), local_14 != 0)
          ) && ((*(int *)(local_14 + 4) == 1 &&
                ((*(int *)(local_14 + 8) != 0 && (*(int *)(*(int *)(local_14 + 8) + 4) == 0xe))))))
      {
        pfVar4 = (float *)(*(int *)(in_ECX + 0x344) + *(int *)(param_1 + 0x3c));
        do {
          if (((*(int *)(local_14 + 4) != 1) || (iVar1 = *(int *)(local_14 + 8), iVar1 == 0)) ||
             (*(int *)(iVar1 + 4) != 0xe)) goto LAB_008c3fdf;
          iVar2 = *(int *)(iVar1 + 0x10);
          if (iVar2 == 0) {
            *pfVar4 = (float)(uint)(*(int *)(iVar1 + 0x18) != 0);
LAB_008c3fb0:
            pfVar4 = pfVar4 + 1;
          }
          else {
            if ((iVar2 == 1) || (iVar2 == 2)) {
              *pfVar4 = *(float *)(iVar1 + 0x18);
              goto LAB_008c3fb0;
            }
            if (iVar2 == 3) {
              *pfVar4 = (float)*(double *)(iVar1 + 0x18);
              goto LAB_008c3fb0;
            }
            if (iVar2 != 4) {
              if (iVar2 != 5) {
                FUN_008bd320(in_ECX + 0x28,local_10 + 0x30,0,
                             s_ID3DXEffectCompiler__CompileEffe_00a1b548);
                goto LAB_008c3fdf;
              }
              uVar3 = *(undefined4 *)(iVar1 + 0x18);
              local_8 = *pfVar4;
              param_1 = *(int *)(iVar1 + 0x1c);
LAB_008c3f4a:
              local_8 = (float)FUN_008c1bfa(&local_8,4,0);
              if (((-1 < (int)local_8) &&
                  (local_8 = (float)FUN_008c1bfa(&param_1,4,0), -1 < (int)local_8)) &&
                 (local_8 = (float)FUN_008c1bfa(uVar3,param_1,0), -1 < (int)local_8)) {
                *param_3 = *param_3 + 1;
                goto LAB_008c3fb0;
              }
              break;
            }
            iVar1 = *(int *)(iVar1 + 0x18);
            if (((iVar1 != 0) && (*(int *)(iVar1 + 4) == 0xd)) && (*(int *)(iVar1 + 0x1c) == 0x1b))
            {
              if (local_c != (int *)0x0) {
                (**(code **)(*local_c + 8))(local_c);
                local_c = (int *)0x0;
              }
              local_8 = (float)FUN_00905be7(in_ECX + 0x10,*(undefined4 *)(in_ECX + 800),iVar1,0,
                                            param_4,&local_c,0);
              if (-1 < (int)local_8) {
                if (local_c == (int *)0x0) {
                  uVar3 = 0;
                  param_1 = 0;
                }
                else {
                  uVar3 = (**(code **)(*local_c + 0xc))(local_c);
                  param_1 = (**(code **)(*local_c + 0x10))(local_c);
                }
                local_8 = *pfVar4;
                goto LAB_008c3f4a;
              }
              FUN_008bd320(in_ECX + 0x28,local_10 + 0x30,0,
                           s_ID3DXEffectCompiler__CompileEffe_00a1b4f0);
              break;
            }
          }
          local_14 = *(int *)(local_14 + 0xc);
        } while (local_14 != 0);
        goto LAB_008c3fe6;
      }
    }
LAB_008c3fdf:
    local_8 = -2.29659e-41;
  }
LAB_008c3fe6:
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
    local_c = (int *)0x0;
  }
  FUN_008f6485();
  return local_8;
}


// ==== FUN_008c4026 @ 0x008c4026 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_008c4026(int param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  char cVar1;
  char cVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 *puVar9;
  int *piVar10;
  int iVar11;
  int extraout_EAX;
  uint uVar12;
  uint uVar13;
  undefined4 *puVar14;
  int *piVar15;
  int iVar16;
  undefined4 *puVar17;
  undefined8 uVar18;
  int local_5c;
  int local_58;
  int *local_54;
  int *local_50;
  int *local_4c;
  int *local_48;
  int *local_44;
  int local_40;
  int local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int local_2c;
  char local_28 [32];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  FUN_008c1a16(param_1 + 0x10);
  local_2c = 0;
  local_34 = (int *)0x0;
  local_4c = (int *)0x0;
  local_54 = (int *)0x0;
  local_50 = (int *)0x0;
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  if (*(int *)(param_1 + 0x324) == 0) {
    local_3c = param_1 + 0x28;
    FUN_008bd320(local_3c,0,0,s_>ID3DXEffectCompiler__There_were_00a1b767 + 1);
    iVar16 = -0x7fffbffb;
  }
  else {
    local_3c = param_1 + 0x28;
    iVar16 = FUN_008bccd8();
    if (-1 < iVar16) {
      pvVar3 = operator_new(0x1c);
      if (pvVar3 == (void *)0x0) {
        uVar18 = 0;
      }
      else {
        uVar18 = FUN_008c1b7e();
      }
      iVar16 = (int)((ulonglong)uVar18 >> 0x20);
      local_2c = (int)uVar18;
      if (local_2c == iVar16) {
        iVar16 = -0x7ff8fff2;
      }
      else {
        iVar11 = *(int *)(param_1 + 0x34c);
        if (iVar11 != iVar16) {
          do {
            local_58 = (int)((ulonglong)uVar18 >> 0x20);
            local_2c = (int)uVar18;
            iVar16 = FUN_008c3db6(iVar11,local_2c,&local_58,param_2);
            if (iVar16 < 0) goto LAB_008c46a3;
            for (local_38 = *(int **)(iVar11 + 0x30); uVar18 = CONCAT44(local_58,local_2c),
                local_38 != (int *)0x0; local_38 = (int *)local_38[0xd]) {
              iVar16 = FUN_008c3db6(local_38,local_2c,&local_58,param_2);
              if (iVar16 < 0) goto LAB_008c46a3;
            }
            iVar11 = *(int *)(iVar11 + 0x34);
          } while (iVar11 != 0);
        }
        for (local_38 = *(int **)(param_1 + 0x348); local_38 != (int *)0x0;
            local_38 = (int *)local_38[0xd]) {
          for (iVar11 = local_38[0xc]; local_58 = (int)((ulonglong)uVar18 >> 0x20),
              local_2c = (int)uVar18, iVar11 != 0; iVar11 = *(int *)(iVar11 + 0x34)) {
            iVar16 = FUN_008c3db6(iVar11,local_2c,&local_58,param_2);
            uVar18 = CONCAT44(local_58,local_2c);
            if (iVar16 < 0) goto LAB_008c46a3;
          }
          local_30 = local_38;
          while (local_30 = (int *)local_30[0xb], local_30 != (int *)0x0) {
            for (iVar11 = local_30[10]; local_58 = (int)((ulonglong)uVar18 >> 0x20),
                local_2c = (int)uVar18, iVar11 != 0; iVar11 = *(int *)(iVar11 + 0x34)) {
              iVar16 = FUN_008c3db6(iVar11,local_2c,&local_58,param_2);
              uVar18 = CONCAT44(local_58,local_2c);
              if (iVar16 < 0) goto LAB_008c46a3;
            }
          }
        }
        local_5c = 0;
        local_48 = *(int **)(param_1 + 0x354);
        while (local_58 = (int)((ulonglong)uVar18 >> 0x20), local_2c = (int)uVar18,
              local_48 != (int *)0x0) {
          FUN_008f4a60();
          iVar11 = local_48[5];
          if (((*(int *)(iVar11 + 0x1c) == 0x17) || (*(int *)(iVar11 + 0x1c) == 0x16)) &&
             (((&DAT_00a184cc)[*local_48 * 7] == 0xa000000 ||
              ((&DAT_00a184cc)[*local_48 * 7] == 0xb000000)))) {
            for (iVar16 = *(int *)(iVar11 + 0x20);
                (*(int *)(iVar16 + 4) == 0xd && (*(int *)(iVar16 + 0x1c) == 0));
                iVar16 = *(int *)(iVar16 + 0x20)) {
            }
            if (*(int *)(iVar16 + 4) == 1) {
              piVar15 = *(int **)(iVar16 + 8);
              local_30 = piVar15;
              if (piVar15[4] == 6) {
                iVar16 = *(int *)(iVar11 + 0x24);
                for (iVar4 = iVar16; (*(int *)(iVar4 + 4) == 0xd && (*(int *)(iVar4 + 0x1c) == 0));
                    iVar4 = *(int *)(iVar4 + 0x20)) {
                }
                if (*(int *)(iVar4 + 4) == 0xe) {
                  iVar16 = *(int *)(iVar4 + 0x20);
                  if (1 < iVar16) {
                    if (iVar16 < 5) {
                      uVar5 = *(undefined4 *)(iVar4 + 0x28);
                    }
                    else {
                      if (8 < iVar16) goto LAB_008c4740;
                      uVar5 = __ftol();
                    }
                    _sprintf(local_28,&DAT_009fff54,uVar5);
                    pcVar6 = (char *)piVar15[10];
                    pcVar8 = pcVar6 + 1;
                    do {
                      cVar1 = *pcVar6;
                      pcVar6 = pcVar6 + 1;
                    } while (cVar1 != '\0');
                    pcVar7 = local_28;
                    do {
                      cVar1 = *pcVar7;
                      pcVar7 = pcVar7 + 1;
                    } while (cVar1 != '\0');
                    iVar16 = FUN_008eb3df(pcVar6 + (int)(pcVar7 + ((3 - (int)(local_28 + 1)) -
                                                                  (int)pcVar8)),&local_34);
                    if (-1 < iVar16) {
                      pcVar6 = s__s__s__00a1b754;
                      pcVar8 = (char *)(**(code **)(*local_34 + 0xc))
                                                 (local_34,s__s__s__00a1b754,local_30[10],local_28);
                      _sprintf(pcVar8,pcVar6);
                      local_30 = (int *)0x1;
                      goto LAB_008c4481;
                    }
                    goto LAB_008c475d;
                  }
LAB_008c4740:
                  pcVar8 = s_ID3DXEffectCompiler__CompileEffe_00a1b638;
                }
                else {
                  if (*(int *)(iVar16 + 4) == 0xd) {
                    iVar16 = FUN_00905be7(param_1 + 0x10,*(undefined4 *)(param_1 + 800),iVar16,0,
                                          param_2,&local_34,&local_38);
                    if (iVar16 < 0) goto LAB_008c4747;
                    pcVar6 = (char *)local_30[10];
                    pcVar8 = pcVar6 + 1;
                    pcVar7 = pcVar6;
                    do {
                      cVar1 = *pcVar7;
                      pcVar7 = pcVar7 + 1;
                    } while (cVar1 != '\0');
                    cVar1 = (char)pcVar6;
                    do {
                      cVar2 = *pcVar6;
                      pcVar6 = pcVar6 + 1;
                    } while (cVar2 != '\0');
                    iVar16 = ((uint)((((char)pcVar6 - (cVar1 + '\x01')) + 1U & 3) != 0) +
                             ((uint)(pcVar7 + (1 - (int)pcVar8)) >> 2)) * 4;
                    local_40 = iVar16;
                    iVar11 = (**(code **)(*local_34 + 0x10))(local_34);
                    uVar13 = iVar11 + 4 + iVar16;
                    iVar16 = FUN_008eb3df(uVar13,&local_4c);
                    if (-1 < iVar16) {
                      piVar10 = (int *)(**(code **)(*local_4c + 0xc))(local_4c);
                      piVar15 = piVar10;
                      for (uVar12 = uVar13 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
                        *piVar15 = 0;
                        piVar15 = piVar15 + 1;
                      }
                      for (uVar12 = uVar13 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
                        *(undefined1 *)piVar15 = 0;
                        piVar15 = (int *)((int)piVar15 + 1);
                      }
                      local_44 = piVar10 + 1;
                      *piVar10 = local_40;
                      _strncpy((char *)local_44,(char *)local_30[10],uVar13 - 4);
                      local_30 = (int *)(**(code **)(*local_34 + 0x10))(local_34);
                      pcVar8 = (char *)(**(code **)(*local_34 + 0xc))(local_34);
                      pcVar6 = (char *)((int)local_44 + local_40);
                      for (uVar13 = (uint)local_30 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
                        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar8;
                        pcVar8 = pcVar8 + 4;
                        pcVar6 = pcVar6 + 4;
                      }
                      for (uVar13 = (uint)local_30 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
                        *pcVar6 = *pcVar8;
                        pcVar8 = pcVar8 + 1;
                        pcVar6 = pcVar6 + 1;
                      }
                      if (local_38 != (int *)0x0) {
                        (**(code **)(*local_38 + 8))(local_38);
                        local_38 = (int *)0x0;
                      }
                      if (local_34 != (int *)0x0) {
                        (**(code **)(*local_34 + 8))(local_34);
                      }
                      local_34 = local_4c;
                      local_4c = (int *)0x0;
                      local_30 = (int *)0x2;
                      goto LAB_008c4481;
                    }
                    goto LAB_008c475d;
                  }
                  pcVar8 = s_ID3DXEffectCompiler__CompileEffe_00a1b588;
                }
              }
              else {
                pcVar8 = s_ID3DXEffectCompiler__CompileEffe_00a1b688;
              }
              piVar15 = piVar15 + 8;
            }
            else {
              pcVar8 = s_ID3DXEffectCompiler__CompileEffe_00a1b6e8;
              piVar15 = (int *)(iVar11 + 0x30);
            }
            FUN_008bd320(local_3c,piVar15,0,pcVar8);
            iVar16 = -0x7fffbffb;
            FUN_008f6485();
            goto LAB_008c46a3;
          }
          iVar16 = FUN_00905be7(param_1 + 0x10,*(undefined4 *)(param_1 + 800),iVar11,0,param_2,
                                &local_34,&local_38);
          if (iVar16 < 0) {
LAB_008c4747:
            FUN_008bd320(local_3c,iVar11 + 0x30,0,s_ID3DXEffectCompiler__CompileEffe_00a1b5e8);
LAB_008c475d:
            FUN_008f6485();
            goto LAB_008c4688;
          }
          local_30 = (int *)(uint)(local_38 == (int *)0x1);
          if ((local_38 != (int *)0x1) && (local_38 != (int *)0x0)) {
            (**(code **)(*local_38 + 8))(local_38);
            local_38 = (int *)0x0;
          }
LAB_008c4481:
          local_44 = (int *)(**(code **)(*local_34 + 0xc))(local_34);
          local_40 = (**(code **)(*local_34 + 0x10))(local_34);
          piVar15 = local_48;
          iVar16 = FUN_008c1bfa(local_48 + 1,4,0);
          if (((((iVar16 < 0) || (iVar16 = FUN_008c1bfa(piVar15 + 2,4,0), iVar16 < 0)) ||
               (iVar16 = FUN_008c1bfa(piVar15 + 3,4,0), iVar16 < 0)) ||
              ((iVar16 = FUN_008c1bfa(piVar15 + 4,4,0), iVar16 < 0 ||
               (iVar16 = FUN_008c1bfa(&local_30,4,0), iVar16 < 0)))) ||
             ((iVar16 = FUN_008c1bfa(&local_40,4,0), iVar16 < 0 ||
              (iVar16 = FUN_008c1bfa(local_44,local_40,0), iVar16 < 0)))) goto LAB_008c475d;
          local_5c = local_5c + 1;
          if (local_34 != (int *)0x0) {
            (**(code **)(*local_34 + 8))(local_34);
            local_34 = (int *)0x0;
          }
          FUN_008f6485();
          uVar18 = CONCAT44(local_58,local_2c);
          local_48 = (int *)piVar15[6];
        }
        local_48 = (int *)0x0;
        iVar16 = FUN_008c1dae(0,&local_48);
        piVar15 = local_48;
        if (-1 < iVar16) {
          local_50 = operator_new((uint)local_48);
          if (local_50 != (int *)0x0) {
            iVar16 = FUN_008c1dae(local_50,0);
            if ((iVar16 < 0) ||
               (iVar16 = FUN_008eb3df(*(int *)(param_1 + 0x338) + *(int *)(param_1 + 0x340) + 0x10 +
                                      (int)piVar15,&local_54), local_40 = iVar16, iVar16 < 0))
            goto LAB_008c46a3;
            puVar9 = (undefined4 *)(**(code **)(*local_54 + 0xc))(local_54);
            *puVar9 = 0xfeff0901;
            puVar9[1] = *(undefined4 *)(param_1 + 0x340);
            uVar13 = *(uint *)(param_1 + 0x340);
            puVar14 = *(undefined4 **)(param_1 + 0x344);
            puVar17 = puVar9 + 2;
            for (uVar12 = uVar13 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
              *puVar17 = *puVar14;
              puVar14 = puVar14 + 1;
              puVar17 = puVar17 + 1;
            }
            for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
              *(undefined1 *)puVar17 = *(undefined1 *)puVar14;
              puVar14 = (undefined4 *)((int)puVar14 + 1);
              puVar17 = (undefined4 *)((int)puVar17 + 1);
            }
            puVar9 = (undefined4 *)((int)(puVar9 + 2) + *(int *)(param_1 + 0x340));
            uVar13 = *(uint *)(param_1 + 0x338);
            puVar14 = *(undefined4 **)(param_1 + 0x33c);
            puVar17 = puVar9;
            for (uVar12 = uVar13 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
              *puVar17 = *puVar14;
              puVar14 = puVar14 + 1;
              puVar17 = puVar17 + 1;
            }
            for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
              *(undefined1 *)puVar17 = *(undefined1 *)puVar14;
              puVar14 = (undefined4 *)((int)puVar14 + 1);
              puVar17 = (undefined4 *)((int)puVar17 + 1);
            }
            piVar10 = (int *)((int)puVar9 + *(int *)(param_1 + 0x338));
            *piVar10 = local_58;
            piVar10[1] = local_5c;
            piVar15 = local_50;
            piVar10 = piVar10 + 2;
            for (uVar13 = (uint)local_48 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
              *piVar10 = *piVar15;
              piVar15 = piVar15 + 1;
              piVar10 = piVar10 + 1;
            }
            for (uVar13 = (uint)local_48 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
              *(char *)piVar10 = (char)*piVar15;
              piVar15 = (int *)((int)piVar15 + 1);
              piVar10 = (int *)((int)piVar10 + 1);
            }
            if (param_3 != (undefined4 *)0x0) {
              *param_3 = local_54;
              (**(code **)(*local_54 + 4))(local_54);
            }
            iVar16 = local_40;
          }
LAB_008c4688:
          if (-1 < iVar16) {
            iVar11 = FUN_008bcde3();
            if (iVar11 != 0) {
              iVar16 = -0x7789f4a7;
            }
            if (-1 < iVar16) goto LAB_008c46b7;
          }
        }
      }
    }
  }
LAB_008c46a3:
  FUN_008bd320(local_3c,0,0,s_ID3DXEffectCompiler__Compilation_00a1b72c);
LAB_008c46b7:
  if (param_4 != 0) {
    FUN_008bcd75(param_4);
  }
  if (local_50 != (int *)0x0) {
    _free(local_50);
    return extraout_EAX;
  }
  if (local_2c != 0) {
    FUN_008c1bd9(1);
  }
  if (local_54 != (int *)0x0) {
    (**(code **)(*local_54 + 8))(local_54);
    local_54 = (int *)0x0;
  }
  if (local_34 != (int *)0x0) {
    (**(code **)(*local_34 + 8))(local_34);
    local_34 = (int *)0x0;
  }
  if (local_4c != (int *)0x0) {
    (**(code **)(*local_4c + 8))(local_4c);
    local_4c = (int *)0x0;
  }
  FUN_008bf855();
  return iVar16;
}


// ==== FUN_008c479b @ 0x008c479b ====

undefined4 FUN_008c479b(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x8876086c;
  }
  else {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[1] = *(undefined4 *)(param_1 + 0x328);
    param_2[2] = *(undefined4 *)(param_1 + 0x324);
    param_2[3] = *(undefined4 *)(param_1 + 0x32c);
  }
  return uVar1;
}


// ==== FUN_008c47e0 @ 0x008c47e0 ====

undefined4 FUN_008c47e0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  if ((param_3 == (undefined4 *)0x0) || (iVar1 = FUN_008c3b4f(param_2), iVar1 == 0)) {
    return 0x8876086c;
  }
  *param_3 = 0;
  param_3[1] = 0;
  *param_3 = *(undefined4 *)(iVar1 + 0x20);
  param_3[1] = 0;
  return 0;
}


// ==== FUN_008c4820 @ 0x008c4820 ====

undefined4 FUN_008c4820(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  if ((param_3 == (undefined4 *)0x0) || (iVar1 = FUN_008c3bd0(param_2), iVar1 == 0)) {
    return 0x8876086c;
  }
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  *param_3 = *(undefined4 *)(iVar1 + 0x20);
  param_3[1] = *(undefined4 *)(iVar1 + 0x28);
  param_3[2] = *(undefined4 *)(iVar1 + 0x24);
  return 0;
}


// ==== FUN_008c486a @ 0x008c486a ====

undefined4 FUN_008c486a(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  if (param_3 != 0) {
    uVar3 = FUN_008c3c51(param_2);
    puVar2 = (undefined4 *)((ulonglong)uVar3 >> 0x20);
    iVar1 = (int)uVar3;
    if (iVar1 != 0) {
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      *puVar2 = *(undefined4 *)(iVar1 + 0x20);
      puVar2[1] = *(undefined4 *)(iVar1 + 0x24);
      puVar2[2] = 0;
      puVar2[3] = 0;
      return 0;
    }
  }
  return 0x8876086c;
}


// ==== FUN_008c48b3 @ 0x008c48b3 ====

uint FUN_008c48b3(int param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int in_ECX;
  uint uVar6;
  undefined4 *puVar7;
  int local_8;
  
  uVar5 = (uint)param_2;
  if (param_1 == 0) {
    return 0;
  }
  iVar2 = FUN_008c6759(param_1,param_3);
  if ((((iVar2 == 0) ||
       (uVar1 = *(uint *)(*(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(in_ECX + 0x344) + 0x10 +
                         *(int *)(iVar2 + 0x18)), *(int *)(iVar2 + 0x10) != -1)) || (uVar1 == 0)) ||
     (uVar1 <= param_2)) {
LAB_008c49fa:
    uVar5 = 0;
  }
  else {
    param_2 = (undefined4 *)0x0;
    puVar3 = *(undefined4 **)(iVar2 + 0xc);
    if (*(undefined4 **)(iVar2 + 0xc) == (undefined4 *)0x0) {
LAB_008c4940:
      puVar3 = operator_new(0x20);
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3[4] = 0xffffffff;
        puVar3[7] = 0;
        puVar3[2] = 0;
        puVar3[3] = 0;
      }
      if (puVar3 == (undefined4 *)0x0) goto LAB_008c49fa;
      local_8 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(iVar2 + 0x18);
      uVar4 = FUN_008c2154(*(undefined4 *)(in_ECX + 0x344),&local_8,&param_3);
      *puVar3 = 3;
      puVar3[1] = *(undefined4 *)(iVar2 + 4);
      puVar3[6] = *(undefined4 *)(iVar2 + 0x18);
      puVar3[4] = uVar5;
      uVar6 = 0;
      puVar3[5] = uVar4 / uVar1;
      puVar3[7] = *(undefined4 *)(iVar2 + 0x1c);
      if ((param_3 * uVar5) / uVar1 != 0) {
        do {
          puVar3[7] = *(undefined4 *)(puVar3[7] + 0xc);
          uVar6 = uVar6 + 1;
        } while (uVar6 < (uint)(puVar3[4] * param_3) / uVar1);
      }
      if (param_2 == (undefined4 *)0x0) {
        puVar3[3] = *(undefined4 *)(iVar2 + 0xc);
        *(undefined4 **)(iVar2 + 0xc) = puVar3;
      }
      else {
        puVar3[3] = param_2[3];
        param_2[3] = puVar3;
      }
    }
    else {
      do {
        puVar7 = puVar3;
        puVar3 = puVar7;
        if (uVar5 <= (uint)puVar7[4]) break;
        puVar3 = (undefined4 *)puVar7[3];
        param_2 = puVar7;
      } while (puVar3 != (undefined4 *)0x0);
      if ((puVar3 == (undefined4 *)0x0) || (uVar5 < (uint)puVar3[4])) goto LAB_008c4940;
    }
    uVar5 = ~(uint)puVar3;
  }
  return uVar5;
}


// ==== FUN_008c4a03 @ 0x008c4a03 ====

uint FUN_008c4a03(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = FUN_008c3ab9(param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_008c3bd0(param_2);
    if (iVar1 == 0) {
      iVar1 = FUN_008c3c51(param_2);
      if (iVar1 == 0) {
        return 0;
      }
      uVar3 = *(uint *)(iVar1 + 0x24);
      uVar2 = *(uint *)(iVar1 + 0x28);
      goto LAB_008c4a4d;
    }
    uVar3 = *(uint *)(iVar1 + 0x24);
  }
  else {
    iVar1 = *(int *)(iVar1 + 4);
    uVar3 = *(uint *)(iVar1 + 0x28);
  }
  uVar2 = *(uint *)(iVar1 + 0x30);
LAB_008c4a4d:
  if (uVar3 <= param_3) {
    return 0;
  }
  while (param_3 = param_3 + 1, param_3 < uVar3) {
    uVar2 = *(uint *)(uVar2 + 0x34);
  }
  return ~uVar2;
}


// ==== FUN_008c4a67 @ 0x008c4a67 ====

uint FUN_008c4a67(undefined4 param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  if (*param_2 == '\0') {
    return 0;
  }
  iVar2 = FUN_008c3ab9(param_1);
  if (iVar2 == 0) {
    iVar2 = FUN_008c3bd0(param_1);
    if (iVar2 == 0) {
      iVar2 = FUN_008c3c51(param_1);
      if (iVar2 == 0) {
        return 0;
      }
      uVar4 = *(uint *)(iVar2 + 0x28);
      goto LAB_008c4abc;
    }
  }
  else {
    iVar2 = *(int *)(iVar2 + 4);
  }
  uVar4 = *(uint *)(iVar2 + 0x30);
LAB_008c4abc:
  if (uVar4 != 0) {
    do {
      iVar6 = *(int *)(*(int *)(uVar4 + 4) + 0x40) + *(int *)(uVar4 + 0x18) +
              *(int *)(in_ECX + 0x344);
      iVar2 = *(int *)(iVar6 + 8);
      if (*(int *)(iVar2 + *(int *)(in_ECX + 0x344)) == 0) {
        pcVar5 = (char *)0x0;
      }
      else {
        pcVar5 = (char *)(iVar2 + 4 + *(int *)(in_ECX + 0x344));
      }
      cVar1 = *param_2;
      pcVar7 = param_2;
      while ((cVar1 == *pcVar5 && (cVar1 != '\0'))) {
        pcVar7 = pcVar7 + 1;
        pcVar5 = pcVar5 + 1;
        cVar1 = *pcVar7;
      }
      cVar1 = *pcVar7;
      if (cVar1 == *pcVar5) {
        return ~uVar4;
      }
      if (*pcVar5 == '\0') {
        if (cVar1 == '.') {
          pcVar7 = pcVar7 + 1;
          uVar4 = ~uVar4;
          goto LAB_008c4b82;
        }
        if (cVar1 == '[') {
          pcVar7 = pcVar7 + 1;
          if (*pcVar7 < '0') {
            return 0;
          }
          if ('9' < *pcVar7) {
            return 0;
          }
          uVar3 = _atol(pcVar7);
          if (*(uint *)(iVar6 + 0x10) <= uVar3) {
            return 0;
          }
          for (; ('/' < *pcVar7 && (*pcVar7 < ':')); pcVar7 = pcVar7 + 1) {
          }
          if (*pcVar7 != ']') {
            return 0;
          }
          uVar4 = FUN_008c48b3(~uVar4,uVar3,param_3);
          if (uVar4 == 0) {
            return 0;
          }
          if (pcVar7[1] == '\0') {
            return uVar4;
          }
          if (pcVar7[1] != '.') {
            return 0;
          }
          pcVar7 = pcVar7 + 2;
LAB_008c4b82:
          uVar4 = FUN_008c6294(uVar4,pcVar7,param_3);
          return uVar4;
        }
      }
      uVar4 = *(uint *)(uVar4 + 0x34);
    } while (uVar4 != 0);
  }
  return 0;
}


// ==== FUN_008c4b96 @ 0x008c4b96 ====

uint FUN_008c4b96(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 < *(uint *)(param_1 + 0x324)) {
    uVar1 = *(uint *)(param_1 + 0x348);
    while (param_2 = param_2 + 1, param_2 < *(uint *)(param_1 + 0x324)) {
      uVar1 = *(uint *)(uVar1 + 0x34);
    }
    uVar1 = ~uVar1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_008c4bc5 @ 0x008c4bc5 ====

uint FUN_008c4bc5(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_008c3bd0(param_2);
  uVar2 = 0;
  if (uVar1 != 0) {
    uVar2 = ~uVar1;
  }
  return uVar2;
}


// ==== FUN_008c4bdf @ 0x008c4bdf ====

uint FUN_008c4bdf(undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = FUN_008c3bd0(param_2);
  if ((uVar2 == 0) || (puVar1 = (uint *)(uVar2 + 0x28), *puVar1 <= param_3)) {
    return 0;
  }
  do {
    uVar2 = *(uint *)(uVar2 + 0x2c);
    param_3 = param_3 + 1;
  } while (param_3 < *puVar1);
  return ~uVar2;
}


// ==== FUN_008c4c0f @ 0x008c4c0f ====

uint FUN_008c4c0f(undefined4 param_1,undefined4 param_2,byte *param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  bool bVar6;
  
  iVar2 = FUN_008c3bd0(param_2);
  if (iVar2 != 0) {
    for (uVar5 = *(uint *)(iVar2 + 0x2c); uVar5 != 0; uVar5 = *(uint *)(uVar5 + 0x2c)) {
      if (param_3 == (byte *)0x0) {
        iVar2 = *(int *)(uVar5 + 0x20);
LAB_008c4c69:
        if (iVar2 == 0) {
          return ~uVar5;
        }
      }
      else {
        pbVar4 = *(byte **)(uVar5 + 0x20);
        if (pbVar4 != (byte *)0x0) {
          pbVar3 = param_3;
          do {
            bVar1 = *pbVar3;
            bVar6 = bVar1 < *pbVar4;
            if (bVar1 != *pbVar4) {
LAB_008c4c62:
              iVar2 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
              goto LAB_008c4c69;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar3[1];
            bVar6 = bVar1 < pbVar4[1];
            if (bVar1 != pbVar4[1]) goto LAB_008c4c62;
            pbVar3 = pbVar3 + 2;
            pbVar4 = pbVar4 + 2;
          } while (bVar1 != 0);
          iVar2 = 0;
          goto LAB_008c4c69;
        }
      }
    }
  }
  return 0;
}


// ==== FUN_008c4c80 @ 0x008c4c80 ====

uint FUN_008c4c80(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 < *(uint *)(param_1 + 0x32c)) {
    uVar1 = *(uint *)(param_1 + 0x350);
    while (param_2 = param_2 + 1, param_2 < *(uint *)(param_1 + 0x32c)) {
      uVar1 = *(uint *)(uVar1 + 0x28);
    }
    uVar1 = ~uVar1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_008c4caf @ 0x008c4caf ====

uint FUN_008c4caf(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_008c3b4f(param_2);
  uVar2 = 0;
  if (uVar1 != 0) {
    uVar2 = ~uVar1;
  }
  return uVar2;
}


// ==== FUN_008c4cc9 @ 0x008c4cc9 ====

undefined4 FUN_008c4cc9(int param_1,float param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(iVar1 + 0x10);
  if (iVar2 == 0) {
    if (DAT_0099cdc8 == param_2) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  else {
    if ((iVar2 != 1) && (iVar2 != 2)) {
      if (iVar2 == 3) {
        *(double *)(iVar1 + 0x18) = (double)param_2;
        return 0;
      }
      return 0x8876086c;
    }
    uVar3 = __ftol();
  }
  *(undefined4 *)(iVar1 + 0x18) = uVar3;
  return 0;
}


// ==== FUN_008c4d25 @ 0x008c4d25 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008c4d25(int param_1,float *param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(iVar1 + 0x10);
  if (iVar2 == 0) {
    fVar3 = (float)(*(int *)(iVar1 + 0x18) != 0);
  }
  else if (iVar2 == 1) {
    fVar3 = (float)*(int *)(iVar1 + 0x18);
  }
  else if (iVar2 == 2) {
    fVar3 = (float)*(int *)(iVar1 + 0x18);
    if (*(int *)(iVar1 + 0x18) < 0) {
      fVar3 = fVar3 + _DAT_0099d104;
    }
  }
  else {
    if (iVar2 != 3) {
      return 0x8876086c;
    }
    fVar3 = (float)*(double *)(iVar1 + 0x18);
  }
  *param_2 = fVar3;
  return 0;
}


// ==== FUN_008c4d7f @ 0x008c4d7f ====

int FUN_008c4d7f(uint param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_10 = 0;
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x14);
    uVar2 = *(uint *)(param_1 + 0x18);
    local_c = 4;
    if (uVar1 < 5) {
      local_c = uVar1;
    }
    local_8 = 4;
    if (uVar2 < 5) {
      local_8 = uVar2;
    }
    iVar5 = (int)param_2;
    do {
      param_1 = 0;
      if (local_c != 0) {
        param_2 = param_3;
        do {
          uVar4 = 0;
          if (local_8 != 0) {
            puVar6 = param_2;
            do {
              local_10 = FUN_008c4cc9(iVar5,*puVar6);
              if (local_10 < 0) {
                return local_10;
              }
              iVar5 = *(int *)(iVar5 + 0xc);
              uVar4 = uVar4 + 1;
              puVar6 = puVar6 + 1;
            } while (uVar4 < local_8);
          }
          if (uVar4 < uVar2) {
            iVar3 = uVar2 - uVar4;
            do {
              iVar3 = iVar3 + -1;
              iVar5 = *(int *)(iVar5 + 0xc);
            } while (iVar3 != 0);
          }
          param_1 = param_1 + 1;
          param_2 = param_2 + 4;
        } while (param_1 < local_c);
      }
      if (param_1 < uVar1) {
        iVar3 = uVar1 - param_1;
        do {
          if (uVar2 != 0) {
            uVar4 = uVar2;
            do {
              uVar4 = uVar4 - 1;
              iVar5 = *(int *)(iVar5 + 0xc);
            } while (uVar4 != 0);
          }
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      param_4 = param_4 + -1;
      param_3 = param_3 + 0x10;
    } while (param_4 != 0);
  }
  return local_10;
}


// ==== FUN_008c4e50 @ 0x008c4e50 ====

int FUN_008c4e50(uint param_1,undefined4 *param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_10 = 0;
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x14);
    uVar2 = *(uint *)(param_1 + 0x18);
    local_c = 4;
    if (uVar1 < 5) {
      local_c = uVar1;
    }
    local_8 = 4;
    if (uVar2 < 5) {
      local_8 = uVar2;
    }
    puVar4 = param_3;
    for (iVar3 = (param_4 & 0x3ffffff) << 4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar3 = 0; iVar5 = (int)param_2, iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    do {
      param_1 = 0;
      if (local_c != 0) {
        param_2 = param_3;
        do {
          uVar6 = 0;
          if (local_8 != 0) {
            puVar4 = param_2;
            do {
              local_10 = FUN_008c4d25(iVar5,puVar4);
              if (local_10 < 0) {
                return local_10;
              }
              iVar5 = *(int *)(iVar5 + 0xc);
              uVar6 = uVar6 + 1;
              puVar4 = puVar4 + 1;
            } while (uVar6 < local_8);
          }
          if (uVar6 < uVar2) {
            iVar3 = uVar2 - uVar6;
            do {
              iVar3 = iVar3 + -1;
              iVar5 = *(int *)(iVar5 + 0xc);
            } while (iVar3 != 0);
          }
          param_1 = param_1 + 1;
          param_2 = param_2 + 4;
        } while (param_1 < local_c);
      }
      if (param_1 < uVar1) {
        iVar3 = uVar1 - param_1;
        do {
          if (uVar2 != 0) {
            uVar6 = uVar2;
            do {
              uVar6 = uVar6 - 1;
              iVar5 = *(int *)(iVar5 + 0xc);
            } while (uVar6 != 0);
          }
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      param_4 = param_4 - 1;
      param_3 = param_3 + 0x10;
    } while (param_4 != 0);
  }
  return local_10;
}


// ==== FUN_008c4f30 @ 0x008c4f30 ====

int FUN_008c4f30(uint param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_10 = 0;
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x14);
    uVar2 = *(uint *)(param_1 + 0x18);
    local_c = 4;
    if (uVar1 < 5) {
      local_c = uVar1;
    }
    local_8 = 4;
    if (uVar2 < 5) {
      local_8 = uVar2;
    }
    iVar5 = (int)param_2;
    do {
      param_1 = 0;
      if (local_c != 0) {
        param_2 = param_3;
        do {
          uVar4 = 0;
          if (local_8 != 0) {
            puVar6 = param_2;
            do {
              local_10 = FUN_008c4cc9(iVar5,*puVar6);
              if (local_10 < 0) {
                return local_10;
              }
              iVar5 = *(int *)(iVar5 + 0xc);
              uVar4 = uVar4 + 1;
              puVar6 = puVar6 + 4;
            } while (uVar4 < local_8);
          }
          if (uVar4 < uVar2) {
            iVar3 = uVar2 - uVar4;
            do {
              iVar3 = iVar3 + -1;
              iVar5 = *(int *)(iVar5 + 0xc);
            } while (iVar3 != 0);
          }
          param_1 = param_1 + 1;
          param_2 = param_2 + 1;
        } while (param_1 < local_c);
      }
      if (param_1 < uVar1) {
        iVar3 = uVar1 - param_1;
        do {
          if (uVar2 != 0) {
            uVar4 = uVar2;
            do {
              uVar4 = uVar4 - 1;
              iVar5 = *(int *)(iVar5 + 0xc);
            } while (uVar4 != 0);
          }
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      param_4 = param_4 + -1;
      param_3 = param_3 + 0x10;
    } while (param_4 != 0);
  }
  return local_10;
}


// ==== FUN_008c5001 @ 0x008c5001 ====

int FUN_008c5001(uint param_1,undefined4 *param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_10 = 0;
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x14);
    uVar2 = *(uint *)(param_1 + 0x18);
    local_c = 4;
    if (uVar1 < 5) {
      local_c = uVar1;
    }
    local_8 = 4;
    if (uVar2 < 5) {
      local_8 = uVar2;
    }
    puVar4 = param_3;
    for (iVar3 = (param_4 & 0x3ffffff) << 4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar3 = 0; iVar5 = (int)param_2, iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    do {
      param_1 = 0;
      if (local_c != 0) {
        param_2 = param_3;
        do {
          uVar6 = 0;
          if (local_8 != 0) {
            puVar4 = param_2;
            do {
              local_10 = FUN_008c4d25(iVar5,puVar4);
              if (local_10 < 0) {
                return local_10;
              }
              iVar5 = *(int *)(iVar5 + 0xc);
              uVar6 = uVar6 + 1;
              puVar4 = puVar4 + 4;
            } while (uVar6 < local_8);
          }
          if (uVar6 < uVar2) {
            iVar3 = uVar2 - uVar6;
            do {
              iVar3 = iVar3 + -1;
              iVar5 = *(int *)(iVar5 + 0xc);
            } while (iVar3 != 0);
          }
          param_1 = param_1 + 1;
          param_2 = param_2 + 1;
        } while (param_1 < local_c);
      }
      if (param_1 < uVar1) {
        iVar3 = uVar1 - param_1;
        do {
          if (uVar2 != 0) {
            uVar6 = uVar2;
            do {
              uVar6 = uVar6 - 1;
              iVar5 = *(int *)(iVar5 + 0xc);
            } while (uVar6 != 0);
          }
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      param_4 = param_4 - 1;
      param_3 = param_3 + 0x10;
    } while (param_4 != 0);
  }
  return local_10;
}


// ==== FUN_008c50e1 @ 0x008c50e1 ====

int FUN_008c50e1(uint param_1,uint param_2,int *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int local_c;
  uint local_8;
  
  local_c = 0;
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x14);
    uVar2 = *(uint *)(param_1 + 0x18);
    local_8 = 4;
    if (uVar1 < 5) {
      local_8 = uVar1;
    }
    param_1 = 4;
    if (uVar2 < 5) {
      param_1 = uVar2;
    }
    iVar6 = param_2;
    do {
      if (*param_3 == 0) {
        if (uVar1 != 0) {
          uVar4 = uVar1;
          do {
            if (uVar2 != 0) {
              uVar3 = uVar2;
              do {
                uVar3 = uVar3 - 1;
                iVar6 = *(int *)(iVar6 + 0xc);
              } while (uVar3 != 0);
            }
            uVar4 = uVar4 - 1;
          } while (uVar4 != 0);
        }
      }
      else {
        uVar4 = 0;
        param_2 = 0;
        if (local_8 != 0) {
          do {
            uVar4 = 0;
            if (param_1 != 0) {
              iVar5 = param_2 << 4;
              do {
                local_c = FUN_008c4cc9(iVar6,*(undefined4 *)(iVar5 + *param_3));
                if (local_c < 0) {
                  return local_c;
                }
                iVar6 = *(int *)(iVar6 + 0xc);
                uVar4 = uVar4 + 1;
                iVar5 = iVar5 + 4;
              } while (uVar4 < param_1);
            }
            if (uVar4 < uVar2) {
              iVar5 = uVar2 - uVar4;
              do {
                iVar5 = iVar5 + -1;
                iVar6 = *(int *)(iVar6 + 0xc);
              } while (iVar5 != 0);
            }
            uVar4 = param_2 + 1;
            param_2 = uVar4;
          } while (uVar4 < local_8);
        }
        if (uVar4 < uVar1) {
          iVar5 = uVar1 - uVar4;
          do {
            if (uVar2 != 0) {
              uVar4 = uVar2;
              do {
                uVar4 = uVar4 - 1;
                iVar6 = *(int *)(iVar6 + 0xc);
              } while (uVar4 != 0);
            }
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
      }
      param_4 = param_4 + -1;
      param_3 = param_3 + 1;
    } while (param_4 != 0);
  }
  return local_c;
}


// ==== FUN_008c51cf @ 0x008c51cf ====

int FUN_008c51cf(uint param_1,uint param_2,int *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int local_c;
  uint local_8;
  
  local_c = 0;
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x18);
    uVar2 = *(uint *)(param_1 + 0x14);
    local_8 = 4;
    if (uVar2 < 5) {
      local_8 = uVar2;
    }
    param_1 = 4;
    if (uVar1 < 5) {
      param_1 = uVar1;
    }
    iVar5 = param_2;
    do {
      if ((undefined4 *)*param_3 == (undefined4 *)0x0) {
        if (uVar2 != 0) {
          uVar7 = uVar2;
          do {
            if (uVar1 != 0) {
              uVar3 = uVar1;
              do {
                uVar3 = uVar3 - 1;
                iVar5 = *(int *)(iVar5 + 0xc);
              } while (uVar3 != 0);
            }
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
      }
      else {
        puVar6 = (undefined4 *)*param_3;
        for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        uVar7 = 0;
        param_2 = 0;
        if (local_8 != 0) {
          do {
            uVar7 = 0;
            if (param_1 != 0) {
              iVar4 = param_2 << 4;
              do {
                local_c = FUN_008c4d25(iVar5,*param_3 + iVar4);
                if (local_c < 0) {
                  return local_c;
                }
                iVar5 = *(int *)(iVar5 + 0xc);
                uVar7 = uVar7 + 1;
                iVar4 = iVar4 + 4;
              } while (uVar7 < param_1);
            }
            if (uVar7 < uVar1) {
              iVar4 = uVar1 - uVar7;
              do {
                iVar4 = iVar4 + -1;
                iVar5 = *(int *)(iVar5 + 0xc);
              } while (iVar4 != 0);
            }
            uVar7 = param_2 + 1;
            param_2 = uVar7;
          } while (uVar7 < local_8);
        }
        if (uVar7 < uVar2) {
          iVar4 = uVar2 - uVar7;
          do {
            if (uVar1 != 0) {
              uVar7 = uVar1;
              do {
                uVar7 = uVar7 - 1;
                iVar5 = *(int *)(iVar5 + 0xc);
              } while (uVar7 != 0);
            }
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
      }
      param_4 = param_4 + -1;
      param_3 = param_3 + 1;
    } while (param_4 != 0);
  }
  return local_c;
}


// ==== FUN_008c52bf @ 0x008c52bf ====

int FUN_008c52bf(uint param_1,uint param_2,int *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int local_c;
  uint local_8;
  
  local_c = 0;
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x14);
    uVar2 = *(uint *)(param_1 + 0x18);
    local_8 = 4;
    if (uVar1 < 5) {
      local_8 = uVar1;
    }
    param_1 = 4;
    if (uVar2 < 5) {
      param_1 = uVar2;
    }
    iVar5 = param_2;
    do {
      if (*param_3 == 0) {
        if (uVar1 != 0) {
          uVar4 = uVar1;
          do {
            if (uVar2 != 0) {
              uVar3 = uVar2;
              do {
                uVar3 = uVar3 - 1;
                iVar5 = *(int *)(iVar5 + 0xc);
              } while (uVar3 != 0);
            }
            uVar4 = uVar4 - 1;
          } while (uVar4 != 0);
        }
      }
      else {
        uVar4 = 0;
        param_2 = 0;
        if (local_8 != 0) {
          do {
            uVar4 = 0;
            if (param_1 != 0) {
              iVar6 = param_2 << 2;
              do {
                local_c = FUN_008c4cc9(iVar5,*(undefined4 *)(iVar6 + *param_3));
                if (local_c < 0) {
                  return local_c;
                }
                iVar5 = *(int *)(iVar5 + 0xc);
                uVar4 = uVar4 + 1;
                iVar6 = iVar6 + 0x10;
              } while (uVar4 < param_1);
            }
            if (uVar4 < uVar2) {
              iVar6 = uVar2 - uVar4;
              do {
                iVar6 = iVar6 + -1;
                iVar5 = *(int *)(iVar5 + 0xc);
              } while (iVar6 != 0);
            }
            uVar4 = param_2 + 1;
            param_2 = uVar4;
          } while (uVar4 < local_8);
        }
        if (uVar4 < uVar1) {
          iVar6 = uVar1 - uVar4;
          do {
            if (uVar2 != 0) {
              uVar4 = uVar2;
              do {
                uVar4 = uVar4 - 1;
                iVar5 = *(int *)(iVar5 + 0xc);
              } while (uVar4 != 0);
            }
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
      }
      param_4 = param_4 + -1;
      param_3 = param_3 + 1;
    } while (param_4 != 0);
  }
  return local_c;
}


// ==== FUN_008c53ad @ 0x008c53ad ====

int FUN_008c53ad(uint param_1,uint param_2,int *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int local_c;
  uint local_8;
  
  local_c = 0;
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x18);
    uVar2 = *(uint *)(param_1 + 0x14);
    local_8 = 4;
    if (uVar2 < 5) {
      local_8 = uVar2;
    }
    param_1 = 4;
    if (uVar1 < 5) {
      param_1 = uVar1;
    }
    iVar6 = param_2;
    do {
      if ((undefined4 *)*param_3 == (undefined4 *)0x0) {
        if (uVar2 != 0) {
          uVar5 = uVar2;
          do {
            if (uVar1 != 0) {
              uVar3 = uVar1;
              do {
                uVar3 = uVar3 - 1;
                iVar6 = *(int *)(iVar6 + 0xc);
              } while (uVar3 != 0);
            }
            uVar5 = uVar5 - 1;
          } while (uVar5 != 0);
        }
      }
      else {
        puVar7 = (undefined4 *)*param_3;
        for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
        uVar5 = 0;
        param_2 = 0;
        if (local_8 != 0) {
          do {
            uVar5 = 0;
            if (param_1 != 0) {
              iVar4 = param_2 << 2;
              do {
                local_c = FUN_008c4d25(iVar6,*param_3 + iVar4);
                if (local_c < 0) {
                  return local_c;
                }
                iVar6 = *(int *)(iVar6 + 0xc);
                uVar5 = uVar5 + 1;
                iVar4 = iVar4 + 0x10;
              } while (uVar5 < param_1);
            }
            if (uVar5 < uVar1) {
              iVar4 = uVar1 - uVar5;
              do {
                iVar4 = iVar4 + -1;
                iVar6 = *(int *)(iVar6 + 0xc);
              } while (iVar4 != 0);
            }
            uVar5 = param_2 + 1;
            param_2 = uVar5;
          } while (uVar5 < local_8);
        }
        if (uVar5 < uVar2) {
          iVar4 = uVar2 - uVar5;
          do {
            if (uVar1 != 0) {
              uVar5 = uVar1;
              do {
                uVar5 = uVar5 - 1;
                iVar6 = *(int *)(iVar6 + 0xc);
              } while (uVar5 != 0);
            }
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
      }
      param_4 = param_4 + -1;
      param_3 = param_3 + 1;
    } while (param_4 != 0);
  }
  return local_c;
}


// ==== FUN_008c549f @ 0x008c549f ====

void FUN_008c549f(uint param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x14);
    param_1 = 4;
    if (uVar1 < 5) {
      param_1 = uVar1;
    }
    do {
      uVar3 = 0;
      if (param_1 != 0) {
        do {
          iVar2 = FUN_008c4cc9(param_2,*(undefined4 *)(param_3 + uVar3 * 4));
          if (iVar2 < 0) {
            return;
          }
          param_2 = *(int *)(param_2 + 0xc);
          uVar3 = uVar3 + 1;
        } while (uVar3 < param_1);
      }
      if (uVar3 < uVar1) {
        iVar2 = uVar1 - uVar3;
        do {
          iVar2 = iVar2 + -1;
          param_2 = *(int *)(param_2 + 0xc);
        } while (iVar2 != 0);
      }
      param_4 = param_4 + -1;
      param_3 = param_3 + 0x10;
    } while (param_4 != 0);
  }
  return;
}


// ==== FUN_008c5510 @ 0x008c5510 ====

int FUN_008c5510(uint param_1,int param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  iVar3 = 0;
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x14);
    param_1 = 4;
    if (uVar1 < 5) {
      param_1 = uVar1;
    }
    puVar4 = param_3;
    for (iVar2 = (param_4 & 0xfffffff) << 2; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    do {
      uVar5 = 0;
      if (param_1 != 0) {
        puVar4 = param_3;
        do {
          iVar3 = FUN_008c4d25(param_2,puVar4);
          if (iVar3 < 0) {
            return iVar3;
          }
          param_2 = *(int *)(param_2 + 0xc);
          uVar5 = uVar5 + 1;
          puVar4 = puVar4 + 1;
        } while (uVar5 < param_1);
      }
      if (uVar5 < uVar1) {
        iVar2 = uVar1 - uVar5;
        do {
          iVar2 = iVar2 + -1;
          param_2 = *(int *)(param_2 + 0xc);
        } while (iVar2 != 0);
      }
      param_4 = param_4 - 1;
      param_3 = param_3 + 4;
    } while (param_4 != 0);
  }
  return iVar3;
}


// ==== FUN_008c559b @ 0x008c559b ====

int FUN_008c559b(int *param_1,int *param_2,int *param_3,uint param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  int local_c;
  int local_8;
  
  piVar2 = (int *)*param_1;
  iVar3 = *piVar2;
  local_8 = piVar2[4];
  uVar8 = 0;
  iVar4 = piVar2[1];
  local_c = 0;
  if ((param_4 != 0) || (local_8 == 0)) {
    local_8 = 1;
  }
  if (-1 < iVar4) {
    if (iVar4 < 4) {
      uVar5 = piVar2[6] * piVar2[5] * local_8;
      if (iVar3 == 1) {
        if (uVar5 != 0) {
          do {
            if (*param_2 == 0) break;
            iVar3 = uVar8 * 4;
            uVar8 = uVar8 + 1;
            *(uint *)(*(int *)(*param_2 + 8) + 0x18) = (uint)(*(int *)(*param_3 + iVar3) != 0);
            *param_2 = *(int *)(*param_2 + 0xc);
          } while (uVar8 < uVar5);
        }
        *param_3 = *param_3 + uVar5 * 4;
      }
      else if (iVar3 == 2) {
        uVar8 = 0;
        if (uVar5 != 0) {
          do {
            if (*param_2 == 0) break;
            *(undefined4 *)(*(int *)(*param_2 + 8) + 0x18) = *(undefined4 *)(*param_3 + uVar8 * 4);
            uVar8 = uVar8 + 1;
            *param_2 = *(int *)(*param_2 + 0xc);
          } while (uVar8 < uVar5);
        }
        *param_3 = *param_3 + uVar5 * 4;
      }
      else {
        if (iVar3 != 3) {
          return -0x7fffbffb;
        }
        uVar8 = 0;
        if (uVar5 != 0) {
          do {
            if (*param_2 == 0) break;
            *(double *)(*(int *)(*param_2 + 8) + 0x18) = (double)*(float *)(*param_3 + uVar8 * 4);
            uVar8 = uVar8 + 1;
            *param_2 = *(int *)(*param_2 + 0xc);
          } while (uVar8 < uVar5);
        }
        *param_3 = *param_3 + uVar5 * 4;
      }
      *param_1 = *param_1 + 0x1c;
      return 0;
    }
    if (iVar4 == 4) {
      if (iVar3 == 4) {
        while ((local_8 != 0 && (pcVar7 = (char *)0x0, *param_2 != 0))) {
          pcVar9 = *(char **)*param_3;
          pcVar6 = (char *)0x0;
          if (pcVar9 != (char *)0x0) {
            FUN_008c1a16(in_ECX + 0x10);
            pcVar7 = pcVar9;
            do {
              cVar1 = *pcVar7;
              pcVar7 = pcVar7 + 1;
            } while (cVar1 != '\0');
            pcVar7 = pcVar7 + (1 - (int)(pcVar9 + 1));
            pcVar6 = (char *)FUN_008f33e7(pcVar7,1);
            if (pcVar6 == (char *)0x0) {
              FUN_008bf855();
              return -0x7ff8fff2;
            }
            pcVar10 = pcVar6;
            for (uVar8 = (uint)pcVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
              *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
              pcVar9 = pcVar9 + 4;
              pcVar10 = pcVar10 + 4;
            }
            for (uVar8 = (uint)pcVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
              *pcVar10 = *pcVar9;
              pcVar9 = pcVar9 + 1;
              pcVar10 = pcVar10 + 1;
            }
            FUN_008bf855();
          }
          *(char **)(*(int *)(*param_2 + 8) + 0x18) = pcVar6;
          *(char **)(*(int *)(*param_2 + 8) + 0x1c) = pcVar7;
          *param_3 = *param_3 + 4;
          local_8 = local_8 + -1;
          *param_2 = *(int *)(*param_2 + 0xc);
        }
      }
      else {
        while ((local_8 != 0 && (*param_2 != 0))) {
          *param_3 = *param_3 + 4;
          local_8 = local_8 + -1;
          *param_2 = *(int *)(*param_2 + 0xc);
        }
      }
      *param_1 = *param_1 + 0x14;
      return 0;
    }
    if (iVar4 == 5) {
      uVar8 = piVar2[5];
      *param_1 = (int)(piVar2 + 6);
      do {
        if (local_8 == 0) {
          return local_c;
        }
        param_4 = 0;
        *param_1 = (int)(piVar2 + 6);
        if (uVar8 != 0) {
          do {
            local_c = FUN_008c559b(param_1,param_2,param_3,0);
            if (local_c < 0) {
              return local_c;
            }
            param_4 = param_4 + 1;
          } while (param_4 < uVar8);
        }
        local_8 = local_8 + -1;
      } while( true );
    }
  }
  return -0x7fffbffb;
}


// ==== FUN_008c57ed @ 0x008c57ed ====

void FUN_008c57ed(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4)

{
  FUN_008c559b(&param_1,&param_2,&param_3,param_4);
  return;
}


// ==== FUN_008c580a @ 0x008c580a ====

int FUN_008c580a(int *param_1,int *param_2,int *param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int local_8;
  
  piVar1 = (int *)*param_1;
  local_8 = 0;
  iVar2 = piVar1[1];
  iVar3 = *piVar1;
  iVar6 = piVar1[4];
  if ((param_4 != 0) || (iVar6 == 0)) {
    iVar6 = 1;
  }
  if (-1 < iVar2) {
    if (iVar2 < 4) {
      uVar5 = piVar1[6] * piVar1[5] * iVar6;
      if (iVar3 == 1) {
        uVar4 = 0;
        if (uVar5 != 0) {
          do {
            if (*param_2 == 0) break;
            *(uint *)(*param_3 + uVar4 * 4) = (uint)(*(int *)(*(int *)(*param_2 + 8) + 0x18) != 0);
            uVar4 = uVar4 + 1;
            *param_2 = *(int *)(*param_2 + 0xc);
          } while (uVar4 < uVar5);
        }
        *param_3 = *param_3 + uVar5 * 4;
      }
      else if (iVar3 == 2) {
        uVar4 = 0;
        if (uVar5 != 0) {
          do {
            if (*param_2 == 0) break;
            *(undefined4 *)(*param_3 + uVar4 * 4) = *(undefined4 *)(*(int *)(*param_2 + 8) + 0x18);
            uVar4 = uVar4 + 1;
            *param_2 = *(int *)(*param_2 + 0xc);
          } while (uVar4 < uVar5);
        }
        *param_3 = *param_3 + uVar5 * 4;
      }
      else {
        if (iVar3 != 3) {
          return -0x7fffbffb;
        }
        uVar4 = 0;
        if (uVar5 != 0) {
          do {
            if (*param_2 == 0) break;
            *(float *)(*param_3 + uVar4 * 4) = (float)*(double *)(*(int *)(*param_2 + 8) + 0x18);
            uVar4 = uVar4 + 1;
            *param_2 = *(int *)(*param_2 + 0xc);
          } while (uVar4 < uVar5);
        }
        *param_3 = *param_3 + uVar5 * 4;
      }
      *param_1 = *param_1 + 0x1c;
      return 0;
    }
    if (iVar2 == 4) {
      if (iVar3 == 4) {
        while ((iVar6 != 0 && (*param_2 != 0))) {
          *(undefined4 *)*param_3 = *(undefined4 *)(*(int *)(*param_2 + 8) + 0x18);
          *param_3 = *param_3 + 4;
          iVar6 = iVar6 + -1;
          *param_2 = *(int *)(*param_2 + 0xc);
        }
      }
      else {
        while ((iVar6 != 0 && (*param_2 != 0))) {
          *(undefined4 *)*param_3 = 0;
          *param_3 = *param_3 + 4;
          iVar6 = iVar6 + -1;
          *param_2 = *(int *)(*param_2 + 0xc);
        }
      }
      *param_1 = *param_1 + 0x14;
      return 0;
    }
    if (iVar2 == 5) {
      uVar5 = piVar1[5];
      *param_1 = (int)(piVar1 + 6);
      do {
        if (iVar6 == 0) {
          return local_8;
        }
        param_4 = 0;
        *param_1 = (int)(piVar1 + 6);
        if (uVar5 != 0) {
          do {
            local_8 = FUN_008c580a(param_1,param_2,param_3,0);
            if (local_8 < 0) {
              return local_8;
            }
            param_4 = param_4 + 1;
          } while (param_4 < uVar5);
        }
        iVar6 = iVar6 + -1;
      } while( true );
    }
  }
  return -0x7fffbffb;
}


// ==== FUN_008c59c6 @ 0x008c59c6 ====

void FUN_008c59c6(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4)

{
  FUN_008c580a(&param_1,&param_2,&param_3,param_4);
  return;
}


// ==== FUN_008c59e3 @ 0x008c59e3 ====

undefined4 FUN_008c59e3(void)

{
  return 0x8876086c;
}


// ==== FUN_008c59eb @ 0x008c59eb ====

void FUN_008c59eb(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    FUN_008c5a20(3);
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  while (*(int *)(in_ECX + 0xc) != 0) {
    iVar1 = *(int *)(in_ECX + 0xc);
    *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar1 + 0xc) = 0;
    FUN_008c1a41(1);
  }
  return;
}


// ==== FUN_008c5a20 @ 0x008c5a20 ====

void FUN_008c5a20(byte param_1)

{
  void *in_ECX;
  
  if ((param_1 & 2) == 0) {
    FUN_008c59eb();
    if ((param_1 & 1) != 0) {
      _free(in_ECX);
      return;
    }
  }
  else {
    FUN_0049b480(in_ECX,0x20,*(undefined4 *)((int)in_ECX + -4),FUN_008c59eb);
    if ((param_1 & 1) != 0) {
      _free((undefined4 *)((int)in_ECX + -4));
      return;
    }
  }
  return;
}


// ==== FUN_008c5a6e @ 0x008c5a6e ====

void FUN_008c5a6e(void)

{
  undefined4 *in_ECX;
  
  in_ECX[4] = 0xffffffff;
  in_ECX[7] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[1] = in_ECX;
  *in_ECX = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = 0;
  return;
}


// ==== FUN_008c5a8e @ 0x008c5a8e ====

void FUN_008c5a8e(void)

{
  undefined4 *in_ECX;
  
  in_ECX[4] = 0xffffffff;
  in_ECX[7] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[1] = in_ECX;
  *in_ECX = 1;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  return;
}


// ==== FUN_008c5aaf @ 0x008c5aaf ====

void FUN_008c5aaf(void)

{
  undefined4 *in_ECX;
  
  in_ECX[4] = 0xffffffff;
  in_ECX[7] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[1] = in_ECX;
  *in_ECX = 2;
  in_ECX[10] = 0;
  return;
}


// ==== FUN_008c5acd @ 0x008c5acd ====

void FUN_008c5acd(void)

{
  void *_Memory;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x28) == 0) {
    FUN_008c59eb();
    return;
  }
  _Memory = *(void **)(in_ECX + 0x28);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)((int)_Memory + 0x28);
  *(undefined4 *)((int)_Memory + 0x28) = 0;
  FUN_008c5acd();
  _free(_Memory);
  return;
}


// ==== FUN_008c5b03 @ 0x008c5b03 ====

void FUN_008c5b03(byte param_1)

{
  void *in_ECX;
  
  FUN_008c5acd();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008c5b24 @ 0x008c5b24 ====

void FUN_008c5b24(void)

{
  undefined4 *in_ECX;
  
  in_ECX[4] = 0xffffffff;
  in_ECX[7] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[1] = in_ECX;
  *in_ECX = 3;
  in_ECX[6] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  return;
}


// ==== FUN_008c5b48 @ 0x008c5b48 ====

void FUN_008c5b48(void)

{
  void *pvVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x30) != 0) {
    pvVar1 = *(void **)(in_ECX + 0x30);
    *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)((int)pvVar1 + 0x30);
    *(undefined4 *)((int)pvVar1 + 0x30) = 0;
    FUN_008c5b48();
    _free(pvVar1);
    return;
  }
  if (*(int *)(in_ECX + 0x34) == 0) {
    FUN_008c59eb();
    return;
  }
  pvVar1 = *(void **)(in_ECX + 0x34);
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)((int)pvVar1 + 0x34);
  *(undefined4 *)((int)pvVar1 + 0x34) = 0;
  FUN_008c5b48();
  _free(pvVar1);
  return;
}


// ==== FUN_008c5b9d @ 0x008c5b9d ====

undefined4 FUN_008c5b9d(int param_1,undefined4 param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  iVar3 = FUN_008c3ab9(param_2);
  if (iVar3 == 0) {
    uVar5 = 0x8876086c;
  }
  else {
    iVar2 = *(int *)(*(int *)(iVar3 + 4) + 0x2c);
    if (param_3 == 0) {
      if ((*(uint *)(iVar2 + 0x1c) & 8) != 0) {
        puVar4 = (uint *)(*(int *)(*(int *)(iVar3 + 4) + 0x44) + *(int *)(param_1 + 0x33c));
        *puVar4 = *puVar4 | 1;
      }
      pbVar1 = (byte *)(*(int *)(*(int *)(iVar3 + 4) + 0x2c) + 0x1c);
      *pbVar1 = *pbVar1 & 0x7f;
      puVar4 = (uint *)(*(int *)(*(int *)(iVar3 + 4) + 0x44) + *(int *)(param_1 + 0x33c));
      *puVar4 = *puVar4 & 0xfffffffd;
    }
    else {
      if ((*(uint *)(iVar2 + 0x1c) & 8) != 0) {
        puVar4 = (uint *)(*(int *)(*(int *)(iVar3 + 4) + 0x44) + *(int *)(param_1 + 0x33c));
        *puVar4 = *puVar4 & 0xfffffffe;
      }
      pbVar1 = (byte *)(*(int *)(*(int *)(iVar3 + 4) + 0x2c) + 0x1c);
      *pbVar1 = *pbVar1 | 0x80;
      puVar4 = (uint *)(*(int *)(*(int *)(iVar3 + 4) + 0x44) + *(int *)(param_1 + 0x33c));
      *puVar4 = *puVar4 | 2;
    }
  }
  return uVar5;
}


// ==== FUN_008c5c3d @ 0x008c5c3d ====

undefined4 FUN_008c5c3d(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  
  if ((param_3 == (uint *)0x0) || (iVar1 = FUN_008c3ab9(param_2), iVar1 == 0)) {
    return 0x80004005;
  }
  *param_3 = *(uint *)(*(int *)(*(int *)(iVar1 + 4) + 0x2c) + 0x1c) >> 7 & 1;
  return 0;
}


// ==== FUN_008c5c7c @ 0x008c5c7c ====

int FUN_008c5c7c(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar3 = param_2;
  local_8 = *(undefined4 *)(param_2 + 0x40);
  iVar4 = 0;
  iVar6 = 0;
  uVar2 = FUN_008c2154(param_1,&local_8,&param_1);
  *(undefined4 *)(iVar3 + 0x14) = uVar2;
  if (*(int *)(*(int *)(iVar3 + 0x2c) + 0x28) == 0) {
    iVar6 = FUN_008bf738(0x50);
    if (iVar6 != 0) {
      iVar4 = FUN_008f3e2e();
    }
    if (iVar4 != 0) {
      iVar6 = (**(code **)(**(int **)(*(int *)(iVar3 + 0x2c) + 0x20) + 4))();
      *(int *)(iVar4 + 0x10) = iVar6;
      if (iVar6 != 0) {
        puVar5 = *(undefined4 **)(iVar3 + 0x38);
        puVar7 = (undefined4 *)(iVar4 + 0x30);
        for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar7 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar7 = puVar7 + 1;
        }
        uVar8 = 0;
        if (param_1 != 0) {
          do {
            iVar3 = FUN_008bf738(0x14);
            if (iVar3 == 0) {
              iVar3 = 0;
            }
            else {
              iVar3 = FUN_008f356e();
            }
            if (iVar3 == 0) goto LAB_008c5d7a;
            iVar6 = FUN_008bf738(0x40);
            if (iVar6 == 0) {
              iVar6 = 0;
            }
            else {
              iVar6 = FUN_008f3f35();
            }
            if (iVar6 == 0) goto LAB_008c5d7a;
            *(int *)(iVar3 + 8) = iVar6;
            uVar8 = uVar8 + 1;
            *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar4 + 0x20);
            *(int *)(iVar4 + 0x20) = iVar3;
          } while (uVar8 < param_1);
        }
        iVar3 = param_2;
        local_c = *(undefined4 *)(iVar4 + 0x20);
        iVar6 = FUN_008c228d(&local_c,*(undefined4 *)(*(int *)(param_2 + 0x2c) + 0x20),iVar4 + 0x14,
                             iVar4 + 0x18);
        if (iVar6 < 0) {
          return iVar6;
        }
        *(int *)(*(int *)(iVar3 + 0x2c) + 0x28) = iVar4;
        goto LAB_008c5d6a;
      }
    }
LAB_008c5d7a:
    iVar3 = -0x7ff8fff2;
  }
  else {
LAB_008c5d6a:
    iVar4 = *(int *)(*(int *)(iVar3 + 0x2c) + 0x28);
    if (*(int *)(iVar4 + 4) == 0xd) {
      while ((((*(int *)(iVar4 + 0x1c) == 0 && (iVar1 = *(int *)(iVar4 + 0x20), iVar1 != 0)) &&
              (*(int *)(iVar1 + 4) == 1)) &&
             ((iVar1 = *(int *)(iVar1 + 8), iVar1 != 0 && (*(int *)(iVar1 + 4) == 0xd))))) {
        iVar4 = iVar1;
      }
      if (((*(int *)(iVar4 + 0x1c) == 0) && (iVar4 = *(int *)(iVar4 + 0x20), iVar4 != 0)) &&
         (*(int *)(iVar4 + 4) == 1)) {
        *(int *)(iVar3 + 0x1c) = iVar4;
        return iVar6;
      }
    }
    iVar3 = -0x7fffbffb;
  }
  return iVar3;
}


// ==== FUN_008c5dc7 @ 0x008c5dc7 ====

undefined4 FUN_008c5dc7(int param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined4 uVar4;
  
  uVar4 = 0;
  pvVar2 = operator_new(0x2c);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_008c5aaf();
  }
  if (iVar3 == 0) {
    uVar4 = 0x8007000e;
  }
  else if ((((*(int *)(param_1 + 0x18) == 0) || (*(int *)(*(int *)(param_1 + 0x18) + 4) != 10)) ||
           (iVar1 = *(int *)(param_1 + 0x14), iVar1 == 0)) ||
          (((*(int *)(iVar1 + 4) != 3 || (*(int *)(iVar1 + 0x10) != 9)) ||
           (*(int *)(iVar1 + 0x18) == 0)))) {
    uVar4 = 0x80004005;
    FUN_008c5b03(1);
  }
  else {
    *(int *)(iVar3 + 0x20) = *(int *)(iVar1 + 0x18);
    *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(param_1 + 0x18);
    *(int *)(iVar3 + 0x28) = *(int *)(in_ECX + 0x350);
    *(int *)(in_ECX + 0x32c) = *(int *)(in_ECX + 0x32c) + 1;
    *(int *)(in_ECX + 0x350) = iVar3;
  }
  return uVar4;
}


// ==== FUN_008c5e52 @ 0x008c5e52 ====

int FUN_008c5e52(int param_1,int *param_2,undefined *param_3)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  undefined *puVar8;
  void *pvVar9;
  int in_ECX;
  undefined **ppuVar10;
  byte *pbVar11;
  undefined **ppuVar12;
  undefined4 *puVar13;
  bool bVar14;
  char *pcVar15;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined *local_8;
  
  ppuVar12 = &PTR_s_ZENABLE_00a184b8;
  if (param_3 != (undefined *)0xffffffff) {
    ppuVar12 = &PTR_s_TEXTURE_00a198d0;
  }
  local_14 = *(int *)(param_1 + 8);
  param_1 = 0;
  iVar7 = *(int *)(local_14 + 0x10);
  local_c = in_ECX;
  if (*ppuVar12 != (undefined *)0x0) {
    ppuVar10 = ppuVar12;
    do {
      iVar4 = __stricmp(*ppuVar10,*(char **)(iVar7 + 0x18));
      if (iVar4 == 0) break;
      param_1 = param_1 + 1;
      ppuVar10 = ppuVar10 + 7;
    } while (*ppuVar10 != (undefined *)0x0);
  }
  ppuVar12 = ppuVar12 + param_1 * 7;
  puVar8 = *ppuVar12;
  if (puVar8 == (undefined *)0x0) {
    pcVar15 = s_ID3DXEffectCompiler__Unrecognize_00a1b938;
    puVar8 = *(undefined **)(iVar7 + 0x18);
LAB_008c5ec2:
    FUN_008bd320(local_c + 0x28,iVar7 + 0x10,0,pcVar15,puVar8);
    return -0x7fffbffb;
  }
  local_8 = (undefined *)0x0;
  if (*(int *)(local_14 + 0x14) == 0) {
    if (ppuVar12[4] != (undefined *)0x1) {
      pcVar15 = s_ID3DXEffectCompiler__Index_is_re_00a1b894;
      goto LAB_008c5ec2;
    }
  }
  else {
    puVar2 = ppuVar12[4];
    if (puVar2 == (undefined *)0x1) {
      pcVar15 = s_ID3DXEffectCompiler__State___s__i_00a1b908;
      goto LAB_008c5ec2;
    }
    local_8 = *(undefined **)(*(int *)(local_14 + 0x14) + 0x18);
    if ((puVar2 != (undefined *)0x0) && (puVar2 <= local_8)) {
      FUN_008bd320(local_c + 0x28,iVar7 + 0x10,0,s_ID3DXEffectCompiler__Max_index_f_00a1b8cc,puVar8,
                   puVar2 + -1);
      return -0x7fffbffb;
    }
  }
  if (param_3 != (undefined *)0xffffffff) {
    param_1 = 0;
    if (PTR_s_ZENABLE_00a184b8 != (undefined *)0x0) {
      ppuVar12 = &PTR_s_ZENABLE_00a184b8;
      do {
        iVar4 = __stricmp(*ppuVar12,*(char **)(iVar7 + 0x18));
        if (iVar4 == 0) break;
        param_1 = param_1 + 1;
        ppuVar12 = ppuVar12 + 7;
      } while (*ppuVar12 != (undefined *)0x0);
    }
    local_8 = param_3;
  }
  if (*(int *)(&DAT_00a184c8 + param_1 * 0x1c) == 0x105) {
    if ((((local_8 < (undefined *)0x10) || (local_8 == (undefined *)0x101)) ||
        (local_8 == (undefined *)0x102)) ||
       ((local_8 == (undefined *)0x103 || (local_8 == (undefined *)0x104)))) {
      if ((&DAT_00a184cc)[param_1 * 7] == 0x300000d) {
        pcVar15 = s_ID3DXEffectCompiler__DMAPOFFSET_s_00a1b7f8;
        iVar7 = iVar7 + 0x10;
        local_c = local_c + 0x28;
        goto LAB_008c6152;
      }
    }
    else if (local_8 != (undefined *)0x100) {
      pcVar15 = s_ID3DXEffectCompiler__Invalid_sam_00a1b864;
      puVar8 = local_8;
      goto LAB_008c5ec2;
    }
  }
  iVar7 = iVar7 + 0x10;
  local_28 = iVar7;
  iVar5 = FUN_008c35ef(*(undefined4 *)(local_14 + 0x18),&PTR_s_ZENABLE_00a184b8 + param_1 * 7,
                       &local_10,&local_24,&local_20,&local_1c,&local_18,&local_2c,iVar7);
  iVar4 = local_c;
  if (iVar5 < 0) {
    return iVar5;
  }
  iVar5 = FUN_008c37bd(&PTR_s_ZENABLE_00a184b8 + param_1 * 7,local_10,local_24,local_20,local_1c,
                       local_18,iVar7);
  if (iVar5 < 0) {
    return iVar5;
  }
  if (((local_10 < 10) || ((0xe < local_10 && (local_10 != 0xf30000)))) ||
     (iVar3 = *(int *)(local_14 + 0x18), *(int *)(iVar3 + 4) != 0xd)) {
LAB_008c6161:
    pvVar9 = operator_new(0x2c);
    if (pvVar9 == (void *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_008c1ab3(param_1,local_8,*(undefined4 *)(local_14 + 0x18),local_10,local_24,
                           local_20,local_1c,local_18,local_2c,iVar7);
    }
    if (iVar7 == 0) {
      return -0x7ff8fff2;
    }
    *(int *)(*param_2 + 0x28) = iVar7;
    *param_2 = iVar7;
    return iVar5;
  }
  if ((((*(int *)(iVar3 + 0x1c) == 0) && (iVar3 = *(int *)(iVar3 + 0x20), iVar3 != 0)) &&
      (*(int *)(iVar3 + 4) == 1)) &&
     ((iVar3 = *(int *)(iVar3 + 8), iVar3 != 0 && (*(int *)(iVar3 + 4) == 0xe)))) {
    if (*(int *)(iVar3 + 0x10) != 6) {
      iVar7 = *(int *)(iVar3 + 0x18);
LAB_008c6140:
      while( true ) {
        if (iVar7 == 0) {
          return iVar5;
        }
        if (local_10 == 0xf30000) {
          puVar8 = (undefined *)0xffffffff;
        }
        else {
          puVar8 = local_8;
        }
        iVar5 = FUN_008c5e52(iVar7,param_2,puVar8);
        if (iVar5 < 0) break;
        iVar7 = *(int *)(iVar7 + 0xc);
      }
      return iVar5;
    }
    if (local_10 != 0xf30000) goto LAB_008c6161;
    puVar13 = *(undefined4 **)(iVar4 + 0x358);
    if (puVar13 != (undefined4 *)0x0) {
      do {
        pbVar6 = (byte *)*puVar13;
        pbVar11 = *(byte **)(iVar3 + 0x28);
        do {
          bVar1 = *pbVar11;
          bVar14 = bVar1 < *pbVar6;
          if (bVar1 != *pbVar6) {
LAB_008c60e8:
            iVar7 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
            goto LAB_008c60ed;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar11[1];
          bVar14 = bVar1 < pbVar6[1];
          if (bVar1 != pbVar6[1]) goto LAB_008c60e8;
          pbVar11 = pbVar11 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar1 != 0);
        iVar7 = 0;
LAB_008c60ed:
      } while ((iVar7 != 0) && (puVar13 = (undefined4 *)puVar13[2], puVar13 != (undefined4 *)0x0));
      if (puVar13 != (undefined4 *)0x0) {
        iVar7 = puVar13[1];
        goto LAB_008c6140;
      }
    }
    pcVar15 = s_ID3DXEffectCompiler__Unsupported_00a1b798;
    local_c = local_c + 0x28;
    iVar7 = local_28;
  }
  else {
    pcVar15 = s_ID3DXEffectCompiler__Unsupported_00a1b798;
    local_c = iVar4 + 0x28;
  }
LAB_008c6152:
  FUN_008bd320(local_c,iVar7,0,pcVar15);
  return -0x7fffbffb;
}


// ==== FUN_008c61b5 @ 0x008c61b5 ====

undefined4 FUN_008c61b5(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int local_c;
  int local_8;
  
  iVar1 = param_1;
  piVar5 = (int *)0x0;
  if (*(int *)(param_1 + 8) != 0) {
    FUN_008c5a20(3);
    *(undefined4 *)(iVar1 + 8) = 0;
  }
  iVar7 = param_2;
  piVar2 = operator_new(param_2 * 0x20 + 4);
  if (piVar2 != (int *)0x0) {
    piVar5 = piVar2 + 1;
    *piVar2 = iVar7;
    FUN_0040d030(piVar5,0x20,iVar7,&LAB_008c1a2f);
  }
  *(int **)(iVar1 + 8) = piVar5;
  if (piVar5 == (int *)0x0) {
    uVar3 = 0x8007000e;
  }
  else {
    iVar6 = *(int *)(iVar1 + 0x1c);
    param_1 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + 0x18 + *(int *)(iVar1 + 0x18);
    if (iVar7 != 0) {
      iVar7 = 0;
      do {
        *(undefined4 *)(iVar7 + *(int *)(iVar1 + 8)) = 3;
        *(undefined4 *)(iVar7 + 4 + *(int *)(iVar1 + 8)) = *(undefined4 *)(iVar1 + 4);
        *(int *)(iVar7 + 0x18 + *(int *)(iVar1 + 8)) =
             param_1 - *(int *)(*(int *)(iVar1 + 4) + 0x40);
        uVar3 = FUN_008c2154(*(undefined4 *)(local_8 + 0x344),&param_1,&local_c);
        *(undefined4 *)(iVar7 + 0x14 + *(int *)(iVar1 + 8)) = uVar3;
        *(int *)(iVar7 + 0x1c + *(int *)(iVar1 + 8)) = iVar6;
        for (iVar4 = local_c; iVar4 != 0; iVar4 = iVar4 + -1) {
          iVar6 = *(int *)(iVar6 + 0xc);
        }
        iVar7 = iVar7 + 0x20;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
    uVar3 = 0;
  }
  return uVar3;
}


// ==== FUN_008c6294 @ 0x008c6294 ====

uint FUN_008c6294(uint param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  int local_c;
  
LAB_008c6405:
  if (param_1 == 0) {
    if ((param_2 == (char *)0x0) || (uVar4 = FUN_008c6759(param_2,param_3 + 1), uVar4 == 0)) {
      return 0;
    }
  }
  else {
    uVar4 = FUN_008c6759(param_1,param_3 + 1);
    uVar7 = 0;
    if (uVar4 == 0) {
      return 0;
    }
    if (param_2 != (char *)0x0) {
      iVar2 = *(int *)(*(int *)(uVar4 + 4) + 0x40) + *(int *)(uVar4 + 0x18) +
              *(int *)(in_ECX + 0x344);
      if (*(int *)(iVar2 + 4) != 5) {
        return 0;
      }
      if ((*(int *)(uVar4 + 0x10) == -1) && (*(int *)(iVar2 + 0x10) != 0)) {
        return 0;
      }
      uVar3 = *(uint *)(iVar2 + 0x14);
      if ((*(int *)(uVar4 + 8) == 0) && (iVar2 = FUN_008c61b5(uVar4,uVar3), iVar2 < 0)) {
        return 0;
      }
      local_c = 0;
      do {
        if (uVar3 <= uVar7) {
          return 0;
        }
        iVar2 = *(int *)(uVar4 + 8) + local_c;
        iVar8 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(iVar2 + 0x18) +
                *(int *)(in_ECX + 0x344);
        iVar2 = *(int *)(iVar8 + 8);
        if (*(int *)(iVar2 + *(int *)(in_ECX + 0x344)) == 0) {
          pcVar5 = (char *)0x0;
        }
        else {
          pcVar5 = (char *)(iVar2 + 4 + *(int *)(in_ECX + 0x344));
        }
        cVar1 = *param_2;
        pcVar6 = param_2;
        while ((cVar1 == *pcVar5 && (cVar1 != '\0'))) {
          pcVar6 = pcVar6 + 1;
          pcVar5 = pcVar5 + 1;
          cVar1 = *pcVar6;
        }
        cVar1 = *pcVar6;
        if (cVar1 == *pcVar5) {
          uVar4 = uVar7 * 0x20 + *(int *)(uVar4 + 8);
          break;
        }
        if (*pcVar5 == '\0') {
          if (cVar1 == '.') {
            param_2 = pcVar6 + 1;
            param_1 = ~(uVar7 * 0x20 + *(int *)(uVar4 + 8));
            goto LAB_008c6405;
          }
          if (cVar1 == '@') {
            uVar4 = FUN_008c4a67(~(uVar7 * 0x20 + *(int *)(uVar4 + 8)),pcVar6 + 1,param_3);
            return uVar4;
          }
          if (cVar1 == '[') goto LAB_008c6394;
        }
        uVar7 = uVar7 + 1;
        local_c = local_c + 0x20;
      } while( true );
    }
  }
  return ~uVar4;
LAB_008c6394:
  pcVar6 = pcVar6 + 1;
  if (*pcVar6 < '0') {
    return 0;
  }
  if ('9' < *pcVar6) {
    return 0;
  }
  uVar3 = _atol(pcVar6);
  if (*(uint *)(iVar8 + 0x10) <= uVar3) {
    return 0;
  }
  for (; ('/' < *pcVar6 && (*pcVar6 < ':')); pcVar6 = pcVar6 + 1) {
  }
  if (*pcVar6 != ']') {
    return 0;
  }
  param_1 = FUN_008c48b3(~(uVar7 * 0x20 + *(int *)(uVar4 + 8)),uVar3,param_3);
  if (param_1 == 0) {
    return 0;
  }
  if (pcVar6[1] == '\0') {
    return param_1;
  }
  if (pcVar6[1] != '.') {
    return 0;
  }
  param_2 = pcVar6 + 2;
  goto LAB_008c6405;
}


// ==== FUN_008c6458 @ 0x008c6458 ====

void FUN_008c6458(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_008c48b3(param_2,param_3,0);
  return;
}


// ==== FUN_008c6471 @ 0x008c6471 ====

undefined4 FUN_008c6471(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_008c4a67(param_2,param_3,0);
  }
  return uVar1;
}


// ==== FUN_008c6494 @ 0x008c6494 ====

void FUN_008c6494(byte param_1)

{
  void *in_ECX;
  
  FUN_008c5b48();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008c64b5 @ 0x008c64b5 ====

void FUN_008c64b5(void)

{
  void *_Memory;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x28) != 0) {
    FUN_008c6494(1);
    *(undefined4 *)(in_ECX + 0x28) = 0;
  }
  if (*(int *)(in_ECX + 0x2c) == 0) {
    FUN_008c59eb();
    return;
  }
  _Memory = *(void **)(in_ECX + 0x2c);
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)((int)_Memory + 0x2c);
  *(undefined4 *)((int)_Memory + 0x2c) = 0;
  FUN_008c64b5();
  _free(_Memory);
  return;
}


// ==== FUN_008c64fd @ 0x008c64fd ====

int FUN_008c64fd(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  void *pvVar2;
  int extraout_EAX;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined1 local_3c [4];
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  int local_2c;
  undefined4 *local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  int *local_14;
  undefined4 *local_10;
  int local_c;
  int local_8;
  
  iVar5 = 0;
  local_10 = (undefined4 *)0x0;
  pvVar2 = operator_new(0x1c);
  if (pvVar2 == (void *)0x0) {
    local_c = 0;
  }
  else {
    local_c = FUN_008c1b7e();
  }
  if (local_c == 0) {
    return -0x7ff8fff2;
  }
  iVar1 = *(int *)(param_1 + 0x18);
  if ((((iVar1 == 0) || (*(int *)(iVar1 + 4) != 0xb)) ||
      (iVar3 = *(int *)(param_1 + 0x14), iVar3 == 0)) || (*(int *)(iVar3 + 4) != 3)) {
LAB_008c660a:
    iVar5 = -0x7fffbffb;
  }
  else if ((*(uint *)(iVar1 + 0x1c) & 2) == 0) {
    local_14 = (int *)(iVar3 + 0x10);
    if (((*local_14 != 9) || (local_2c = *(int *)(iVar3 + 0x18), local_2c == 0)) ||
       (*(int *)(iVar1 + 0x20) == 0)) goto LAB_008c660a;
    iVar5 = FUN_008c1e12(*(int *)(iVar1 + 0x20),&local_24,local_3c,local_38,local_34,local_30,
                         &local_18);
    if (iVar5 < 0) {
      pcVar7 = s_ID3DXEffectCompiler__There_was_a_00a1b9f0;
LAB_008c65c2:
      FUN_008bd320(local_8 + 0x28,local_14,0,pcVar7);
    }
    else {
      if (((local_24 != 0) && (local_24 != 4)) &&
         ((local_24 != 3 && ((local_24 != 1 && (local_24 != 2)))))) {
        FUN_008bd320(local_8 + 0x28,local_14,0,s_ID3DXEffectCompiler__Only_numeri_00a1b9a0);
        goto LAB_008c660a;
      }
      local_10 = operator_new(local_18);
      if (local_10 == (undefined4 *)0x0) {
        iVar5 = -0x7ff8fff2;
      }
      else {
        puVar6 = local_10;
        for (uVar4 = local_18 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        for (uVar4 = local_18 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar6 = 0;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
        local_28 = local_10;
        iVar5 = FUN_008c2483(*(undefined4 *)(iVar1 + 0x20),&local_28);
        if ((-1 < iVar5) && (iVar5 = FUN_008c1bfa(local_10,local_18,&local_20), -1 < iVar5)) {
          iVar5 = FUN_008c257d(*(undefined4 *)(iVar1 + 0x20),local_14,0,0,param_3,local_c,&local_1c,
                               0);
          if (iVar5 < 0) {
            pcVar7 = s_ID3DXEffectCompiler__Error_initi_00a1b968;
            goto LAB_008c65c2;
          }
          iVar5 = FUN_008c1d8e(local_c);
          if (-1 < iVar5) {
            iVar5 = FUN_008c1d03(local_1c,0);
            if ((-1 < iVar5) && (iVar5 = FUN_008c1d03(local_20,0), -1 < iVar5)) {
              pvVar2 = operator_new(0x48);
              if (pvVar2 == (void *)0x0) {
                iVar3 = 0;
              }
              else {
                iVar3 = FUN_008c5b24();
              }
              if (iVar3 == 0) {
                iVar5 = -0x7ff8fff2;
              }
              else {
                *(int *)(iVar3 + 0x20) = local_2c;
                *(undefined4 *)(iVar3 + 0x24) = 0;
                *(undefined4 *)(iVar3 + 0x28) = 0;
                *(undefined4 *)(iVar3 + 0x40) = local_1c;
                *(undefined4 *)(iVar3 + 0x3c) = local_20;
                *(undefined4 *)(iVar3 + 0x44) = 0;
                *(int *)(iVar3 + 0x2c) = iVar1;
                *(int *)(iVar3 + 0x34) = *param_4;
                *(int *)(iVar3 + 0x38) = *(int *)(param_1 + 0x14) + 0x10;
                *param_4 = iVar3;
              }
            }
            goto LAB_008c6619;
          }
        }
      }
    }
  }
  FUN_008c1bd9(1);
LAB_008c6619:
  if (local_10 == (undefined4 *)0x0) {
    return iVar5;
  }
  _free(local_10);
  return extraout_EAX;
}


// ==== FUN_008c6759 @ 0x008c6759 ====

uint FUN_008c6759(char *param_1,undefined4 param_2)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  int in_ECX;
  int iVar6;
  char *pcVar7;
  
  if ((char *)((uint)param_1 & 0xffff) == param_1) {
    return 0;
  }
  if ((char *)((uint)param_1 & 0x7fffffff) != param_1) {
    return ~-(uint)(*(int *)~(uint)param_1 != 3) & ~(uint)param_1;
  }
  uVar4 = *(uint *)(in_ECX + 0x34c);
  if (uVar4 != 0) {
    do {
      iVar6 = *(int *)(*(int *)(uVar4 + 4) + 0x40) + *(int *)(uVar4 + 0x18) +
              *(int *)(in_ECX + 0x344);
      iVar1 = *(int *)(iVar6 + 8);
      if (*(int *)(iVar1 + *(int *)(in_ECX + 0x344)) == 0) {
        pcVar2 = (char *)0x0;
      }
      else {
        pcVar2 = (char *)(iVar1 + 4 + *(int *)(in_ECX + 0x344));
      }
      pcVar7 = param_1;
      cVar5 = *param_1;
      while ((cVar5 == *pcVar2 && (cVar5 != '\0'))) {
        pcVar7 = pcVar7 + 1;
        pcVar2 = pcVar2 + 1;
        cVar5 = *pcVar7;
      }
      cVar5 = *pcVar7;
      if (cVar5 == *pcVar2) {
        return uVar4;
      }
      if (*pcVar2 == '\0') {
        if (cVar5 == '.') {
          pcVar7 = pcVar7 + 1;
          uVar4 = ~uVar4;
          goto LAB_008c688a;
        }
        if (cVar5 == '@') {
          uVar4 = FUN_008c4a67(~uVar4,pcVar7 + 1,param_2);
          goto LAB_008c6892;
        }
        if (cVar5 == '[') {
          pcVar7 = pcVar7 + 1;
          if (*pcVar7 < '0') {
            return 0;
          }
          if ('9' < *pcVar7) {
            return 0;
          }
          uVar3 = _atol(pcVar7);
          if (*(uint *)(iVar6 + 0x10) <= uVar3) {
            return 0;
          }
          for (; ('/' < *pcVar7 && (*pcVar7 < ':')); pcVar7 = pcVar7 + 1) {
          }
          if (*pcVar7 != ']') {
            return 0;
          }
          uVar4 = FUN_008c48b3(~uVar4,uVar3,param_2);
          if (uVar4 == 0) {
            return 0;
          }
          if (pcVar7[1] != '\0') {
            if (pcVar7[1] != '.') {
              return 0;
            }
            pcVar7 = pcVar7 + 2;
LAB_008c688a:
            uVar4 = FUN_008c6294(uVar4,pcVar7,param_2);
LAB_008c6892:
            if (uVar4 == 0) {
              return 0;
            }
          }
          return ~uVar4;
        }
      }
      uVar4 = *(uint *)(uVar4 + 0x34);
    } while (uVar4 != 0);
  }
  return 0;
}


// ==== FUN_008c68a1 @ 0x008c68a1 ====

undefined4 FUN_008c68a1(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_3 == (undefined4 *)0x0) {
    return 0x8876086c;
  }
  iVar1 = FUN_008c6759(param_2,1);
  if (iVar1 == 0) {
    return 0x8876086c;
  }
  puVar5 = (undefined4 *)
           (*(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
           *(int *)(iVar1 + 0x18));
  puVar6 = param_3;
  for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  piVar2 = (int *)(puVar5[2] + *(int *)(param_1 + 0x344));
  if (*piVar2 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = piVar2 + 1;
  }
  *param_3 = piVar2;
  piVar2 = (int *)(puVar5[3] + *(int *)(param_1 + 0x344));
  if (*piVar2 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = piVar2 + 1;
  }
  param_3[1] = piVar2;
  param_3[10] = *(undefined4 *)(iVar1 + 0x14);
  iVar4 = *(int *)(*(int *)(iVar1 + 4) + 0x44);
  if (iVar4 == 0) {
    uVar3 = 4;
  }
  else {
    uVar3 = *(undefined4 *)(iVar4 + *(int *)(param_1 + 0x33c));
  }
  param_3[9] = uVar3;
  param_3[3] = *puVar5;
  param_3[2] = puVar5[1];
  if (*(int *)(iVar1 + 0x10) == -1) {
    uVar3 = puVar5[4];
  }
  else {
    uVar3 = 0;
  }
  param_3[6] = uVar3;
  param_3[7] = 0;
  if ((*(int *)(iVar1 + 0x18) == 0) && (*(int *)(iVar1 + 0x10) == -1)) {
    param_3[7] = *(undefined4 *)(*(int *)(iVar1 + 4) + 0x28);
  }
  iVar1 = param_3[2];
  if (iVar1 == 1) {
    param_3[8] = 0;
    param_3[4] = 1;
    uVar3 = puVar5[5];
LAB_008c69c0:
    param_3[5] = uVar3;
  }
  else {
    if (iVar1 == 4) {
      param_3[8] = 0;
    }
    else {
      if (iVar1 != 5) {
        param_3[8] = 0;
        param_3[4] = puVar5[5];
        uVar3 = puVar5[6];
        goto LAB_008c69c0;
      }
      param_3[8] = puVar5[5];
    }
    param_3[4] = 0;
    param_3[5] = 0;
  }
  return 0;
}


// ==== FUN_008c69cd @ 0x008c69cd ====

uint FUN_008c69cd(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 0) {
    if (param_3 < *(uint *)(param_1 + 0x328)) {
      uVar1 = *(uint *)(param_1 + 0x34c);
      while (param_3 = param_3 + 1, param_3 < *(uint *)(param_1 + 0x328)) {
        uVar1 = *(uint *)(uVar1 + 0x34);
      }
      uVar1 = ~uVar1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    iVar2 = FUN_008c6759(param_2,1);
    if (((((iVar2 == 0) ||
          (iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
                   *(int *)(iVar2 + 0x18), *(int *)(iVar3 + 4) != 5)) ||
         ((*(int *)(iVar2 + 0x10) == -1 && (*(int *)(iVar3 + 0x10) != 0)))) ||
        (*(uint *)(iVar3 + 0x14) <= param_3)) ||
       ((*(int *)(iVar2 + 8) == 0 &&
        (iVar3 = FUN_008c61b5(iVar2,*(uint *)(iVar3 + 0x14)), iVar3 < 0)))) {
      uVar1 = 0;
    }
    else {
      uVar1 = ~(param_3 * 0x20 + *(int *)(iVar2 + 8));
    }
  }
  return uVar1;
}


// ==== FUN_008c6a68 @ 0x008c6a68 ====

uint FUN_008c6a68(int param_1,uint param_2,char *param_3)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = 0;
  if (param_2 == 0) {
    uVar5 = *(uint *)(param_1 + 0x34c);
    if (uVar5 != 0) {
      do {
        iVar6 = *(int *)(param_1 + 0x344);
        iVar3 = *(int *)(*(int *)(*(int *)(uVar5 + 4) + 0x40) + *(int *)(uVar5 + 0x18) + iVar6 + 0xc
                        );
        if ((*(int *)(iVar3 + iVar6) == 0) ||
           (pcVar2 = (char *)(iVar3 + 4 + iVar6), pcVar2 == (char *)0x0)) {
          pcVar2 = param_3;
LAB_008c6ac0:
          if (pcVar2 == (char *)0x0) break;
        }
        else if (param_3 != (char *)0x0) {
          pcVar2 = (char *)__stricmp(pcVar2,param_3);
          goto LAB_008c6ac0;
        }
        uVar5 = *(uint *)(uVar5 + 0x34);
      } while (uVar5 != 0);
      if (uVar5 != 0) goto LAB_008c6b94;
    }
  }
  else {
    iVar3 = FUN_008c6759(param_2,1);
    if ((((iVar3 != 0) &&
         (iVar4 = *(int *)(*(int *)(iVar3 + 4) + 0x40) + *(int *)(iVar3 + 0x18) +
                  *(int *)(param_1 + 0x344), *(int *)(iVar4 + 4) == 5)) &&
        ((*(int *)(iVar3 + 0x10) != -1 || (*(int *)(iVar4 + 0x10) == 0)))) &&
       ((uVar5 = *(uint *)(iVar4 + 0x14), *(int *)(iVar3 + 8) != 0 ||
        (iVar4 = FUN_008c61b5(iVar3,uVar5), -1 < iVar4)))) {
      param_2 = 0;
      if (uVar5 != 0) {
        do {
          iVar1 = *(int *)(param_1 + 0x344);
          iVar4 = *(int *)(iVar3 + 8) + iVar6;
          iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 4) + 0x40) + *(int *)(iVar4 + 0x18) + iVar1 +
                          0xc);
          if ((*(int *)(iVar1 + iVar4) == 0) ||
             (pcVar2 = (char *)(iVar4 + 4 + iVar1), pcVar2 == (char *)0x0)) {
            pcVar2 = param_3;
LAB_008c6b72:
            if (pcVar2 == (char *)0x0) break;
          }
          else if (param_3 != (char *)0x0) {
            pcVar2 = (char *)__stricmp(pcVar2,param_3);
            goto LAB_008c6b72;
          }
          param_2 = param_2 + 1;
          iVar6 = iVar6 + 0x20;
        } while (param_2 < uVar5);
      }
      if (param_2 != uVar5) {
        uVar5 = param_2 * 0x20 + *(int *)(iVar3 + 8);
LAB_008c6b94:
        return ~uVar5;
      }
    }
  }
  return 0;
}


// ==== FUN_008c6b9d @ 0x008c6b9d ====

void FUN_008c6b9d(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_008c6294(param_2,param_3,0);
  return;
}


// ==== FUN_008c6bb6 @ 0x008c6bb6 ====

undefined4 FUN_008c6bb6(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_4 == 0) || (param_3 != 0)) {
    iVar2 = FUN_008c6759(param_2,1);
    if ((iVar2 == 0) || ((param_4 != 0xffffffff && (param_4 < *(uint *)(iVar2 + 0x14))))) {
      uVar1 = 0x8876086c;
    }
    else {
      uVar1 = FUN_008c57ed(*(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
                           *(int *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x1c),param_3,
                           *(int *)(iVar2 + 0x10) != -1);
    }
  }
  else {
    uVar1 = 0x8876086c;
  }
  return uVar1;
}


// ==== FUN_008c6c22 @ 0x008c6c22 ====

undefined4 FUN_008c6c22(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_4 == 0) || (param_3 != 0)) {
    iVar2 = FUN_008c6759(param_2,1);
    if ((iVar2 == 0) || ((param_4 != 0xffffffff && (param_4 < *(uint *)(iVar2 + 0x14))))) {
      uVar1 = 0x8876086c;
    }
    else {
      uVar1 = FUN_008c59c6(*(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
                           *(int *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x1c),param_3,
                           *(int *)(iVar2 + 0x10) != -1);
    }
  }
  else {
    uVar1 = 0x8876086c;
  }
  return uVar1;
}


// ==== FUN_008c6c8c @ 0x008c6c8c ====

int FUN_008c6c8c(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint local_10;
  undefined4 *local_c;
  uint local_8;
  
  if (param_3 == (undefined4 *)0x0) {
    return -0x7789f794;
  }
  iVar3 = FUN_008c6759(param_2,1);
  if ((iVar3 != 0) &&
     ((iVar4 = *(int *)(*(int *)(iVar3 + 4) + 0x40) + *(int *)((int)param_1 + 0x344) +
               *(int *)(iVar3 + 0x18), *(int *)(iVar4 + 0x10) == 0 || (*(int *)(iVar3 + 0x10) != -1)
      ))) {
    if (*(int *)(iVar4 + 4) == 2) {
      uVar1 = *(uint *)(iVar4 + 0x14);
      iVar3 = *(int *)(iVar3 + 0x1c);
      local_c = param_3;
      uVar2 = *(uint *)(iVar4 + 0x18);
      iVar4 = 0;
      local_8 = 1;
      local_10 = 4;
      if (uVar1 < 5) {
        local_10 = uVar1;
      }
      param_2 = 4;
      if (uVar2 < 5) {
        param_2 = uVar2;
      }
      do {
        param_3 = (undefined4 *)0x0;
        if (local_10 != 0) {
          param_1 = local_c;
          do {
            uVar6 = 0;
            if (param_2 != 0) {
              puVar7 = param_1;
              do {
                iVar4 = FUN_008c4cc9(iVar3,*puVar7);
                if (iVar4 < 0) {
                  return iVar4;
                }
                iVar3 = *(int *)(iVar3 + 0xc);
                uVar6 = uVar6 + 1;
                puVar7 = puVar7 + 1;
              } while (uVar6 < param_2);
            }
            if (uVar6 < uVar2) {
              iVar5 = uVar2 - uVar6;
              do {
                iVar5 = iVar5 + -1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (iVar5 != 0);
            }
            param_3 = (undefined4 *)((int)param_3 + 1);
            param_1 = param_1 + 4;
          } while (param_3 < local_10);
        }
        if (param_3 < uVar1) {
          iVar5 = uVar1 - (int)param_3;
          do {
            if (uVar2 != 0) {
              uVar6 = uVar2;
              do {
                uVar6 = uVar6 - 1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (uVar6 != 0);
            }
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        local_8 = local_8 + -1;
        local_c = local_c + 0x10;
      } while (local_8 != 0);
      return iVar4;
    }
    if (*(int *)(iVar4 + 4) == 3) {
      uVar1 = *(uint *)(iVar4 + 0x14);
      iVar3 = *(int *)(iVar3 + 0x1c);
      local_c = param_3;
      uVar2 = *(uint *)(iVar4 + 0x18);
      iVar4 = 0;
      local_10 = 1;
      local_8 = 4;
      if (uVar1 < 5) {
        local_8 = uVar1;
      }
      param_2 = 4;
      if (uVar2 < 5) {
        param_2 = uVar2;
      }
      do {
        param_3 = (undefined4 *)0x0;
        if (local_8 != 0) {
          param_1 = local_c;
          do {
            uVar6 = 0;
            if (param_2 != 0) {
              puVar7 = param_1;
              do {
                iVar4 = FUN_008c4cc9(iVar3,*puVar7);
                if (iVar4 < 0) {
                  return iVar4;
                }
                iVar3 = *(int *)(iVar3 + 0xc);
                uVar6 = uVar6 + 1;
                puVar7 = puVar7 + 4;
              } while (uVar6 < param_2);
            }
            if (uVar6 < uVar2) {
              iVar5 = uVar2 - uVar6;
              do {
                iVar5 = iVar5 + -1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (iVar5 != 0);
            }
            param_3 = (undefined4 *)((int)param_3 + 1);
            param_1 = param_1 + 1;
          } while (param_3 < local_8);
        }
        if (param_3 < uVar1) {
          iVar5 = uVar1 - (int)param_3;
          do {
            if (uVar2 != 0) {
              uVar6 = uVar2;
              do {
                uVar6 = uVar6 - 1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (uVar6 != 0);
            }
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        local_10 = local_10 + -1;
        local_c = local_c + 0x10;
      } while (local_10 != 0);
      return iVar4;
    }
  }
  return -0x7789f794;
}


// ==== FUN_008c6e5e @ 0x008c6e5e ====

int FUN_008c6e5e(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int local_14;
  uint local_10;
  undefined4 *local_c;
  uint local_8;
  
  if (param_3 == (undefined4 *)0x0) {
    return -0x7789f794;
  }
  iVar3 = FUN_008c6759(param_2,1);
  if ((iVar3 != 0) &&
     ((iVar4 = *(int *)(*(int *)(iVar3 + 4) + 0x40) + *(int *)((int)param_1 + 0x344) +
               *(int *)(iVar3 + 0x18), *(int *)(iVar4 + 0x10) == 0 || (*(int *)(iVar3 + 0x10) != -1)
      ))) {
    if (*(int *)(iVar4 + 4) == 2) {
      iVar3 = *(int *)(iVar3 + 0x1c);
      uVar1 = *(uint *)(iVar4 + 0x18);
      local_14 = 0;
      uVar2 = *(uint *)(iVar4 + 0x14);
      local_8 = 1;
      local_c = param_3;
      local_10 = 4;
      if (uVar2 < 5) {
        local_10 = uVar2;
      }
      param_2 = 4;
      if (uVar1 < 5) {
        param_2 = uVar1;
      }
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *param_3 = 0;
        param_3 = param_3 + 1;
      }
      do {
        param_3 = (undefined4 *)0x0;
        if (local_10 != 0) {
          param_1 = local_c;
          do {
            uVar6 = 0;
            if (param_2 != 0) {
              puVar5 = param_1;
              do {
                local_14 = FUN_008c4d25(iVar3,puVar5);
                if (local_14 < 0) {
                  return local_14;
                }
                iVar3 = *(int *)(iVar3 + 0xc);
                uVar6 = uVar6 + 1;
                puVar5 = puVar5 + 1;
              } while (uVar6 < param_2);
            }
            if (uVar6 < uVar1) {
              iVar4 = uVar1 - uVar6;
              do {
                iVar4 = iVar4 + -1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (iVar4 != 0);
            }
            param_3 = (undefined4 *)((int)param_3 + 1);
            param_1 = param_1 + 4;
          } while (param_3 < local_10);
        }
        if (param_3 < uVar2) {
          iVar4 = uVar2 - (int)param_3;
          do {
            if (uVar1 != 0) {
              uVar6 = uVar1;
              do {
                uVar6 = uVar6 - 1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (uVar6 != 0);
            }
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        local_8 = local_8 + -1;
        local_c = local_c + 0x10;
      } while (local_8 != 0);
      return local_14;
    }
    if (*(int *)(iVar4 + 4) == 3) {
      iVar3 = *(int *)(iVar3 + 0x1c);
      uVar1 = *(uint *)(iVar4 + 0x18);
      local_14 = 0;
      uVar2 = *(uint *)(iVar4 + 0x14);
      local_10 = 1;
      local_c = param_3;
      local_8 = 4;
      if (uVar2 < 5) {
        local_8 = uVar2;
      }
      param_2 = 4;
      if (uVar1 < 5) {
        param_2 = uVar1;
      }
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *param_3 = 0;
        param_3 = param_3 + 1;
      }
      do {
        param_3 = (undefined4 *)0x0;
        if (local_8 != 0) {
          param_1 = local_c;
          do {
            uVar6 = 0;
            if (param_2 != 0) {
              puVar5 = param_1;
              do {
                local_14 = FUN_008c4d25(iVar3,puVar5);
                if (local_14 < 0) {
                  return local_14;
                }
                iVar3 = *(int *)(iVar3 + 0xc);
                uVar6 = uVar6 + 1;
                puVar5 = puVar5 + 4;
              } while (uVar6 < param_2);
            }
            if (uVar6 < uVar1) {
              iVar4 = uVar1 - uVar6;
              do {
                iVar4 = iVar4 + -1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (iVar4 != 0);
            }
            param_3 = (undefined4 *)((int)param_3 + 1);
            param_1 = param_1 + 1;
          } while (param_3 < local_8);
        }
        if (param_3 < uVar2) {
          iVar4 = uVar2 - (int)param_3;
          do {
            if (uVar1 != 0) {
              uVar6 = uVar1;
              do {
                uVar6 = uVar6 - 1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (uVar6 != 0);
            }
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        local_10 = local_10 + -1;
        local_c = local_c + 0x10;
      } while (local_10 != 0);
      return local_14;
    }
  }
  return -0x7789f794;
}


// ==== FUN_008c7046 @ 0x008c7046 ====

int FUN_008c7046(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint local_10;
  undefined4 *local_c;
  uint local_8;
  
  if (param_3 == (undefined4 *)0x0) {
    return -0x7789f794;
  }
  iVar3 = FUN_008c6759(param_2,1);
  if ((iVar3 != 0) &&
     ((iVar4 = *(int *)(*(int *)(iVar3 + 4) + 0x40) + *(int *)((int)param_1 + 0x344) +
               *(int *)(iVar3 + 0x18), *(int *)(iVar4 + 0x10) == 0 || (*(int *)(iVar3 + 0x10) != -1)
      ))) {
    if (*(int *)(iVar4 + 4) == 2) {
      uVar1 = *(uint *)(iVar4 + 0x14);
      iVar3 = *(int *)(iVar3 + 0x1c);
      local_c = param_3;
      uVar2 = *(uint *)(iVar4 + 0x18);
      iVar4 = 0;
      local_8 = 1;
      local_10 = 4;
      if (uVar1 < 5) {
        local_10 = uVar1;
      }
      param_2 = 4;
      if (uVar2 < 5) {
        param_2 = uVar2;
      }
      do {
        param_3 = (undefined4 *)0x0;
        if (local_10 != 0) {
          param_1 = local_c;
          do {
            uVar6 = 0;
            if (param_2 != 0) {
              puVar7 = param_1;
              do {
                iVar4 = FUN_008c4cc9(iVar3,*puVar7);
                if (iVar4 < 0) {
                  return iVar4;
                }
                iVar3 = *(int *)(iVar3 + 0xc);
                uVar6 = uVar6 + 1;
                puVar7 = puVar7 + 4;
              } while (uVar6 < param_2);
            }
            if (uVar6 < uVar2) {
              iVar5 = uVar2 - uVar6;
              do {
                iVar5 = iVar5 + -1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (iVar5 != 0);
            }
            param_3 = (undefined4 *)((int)param_3 + 1);
            param_1 = param_1 + 1;
          } while (param_3 < local_10);
        }
        if (param_3 < uVar1) {
          iVar5 = uVar1 - (int)param_3;
          do {
            if (uVar2 != 0) {
              uVar6 = uVar2;
              do {
                uVar6 = uVar6 - 1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (uVar6 != 0);
            }
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        local_8 = local_8 + -1;
        local_c = local_c + 0x10;
      } while (local_8 != 0);
      return iVar4;
    }
    if (*(int *)(iVar4 + 4) == 3) {
      uVar1 = *(uint *)(iVar4 + 0x14);
      iVar3 = *(int *)(iVar3 + 0x1c);
      local_c = param_3;
      uVar2 = *(uint *)(iVar4 + 0x18);
      iVar4 = 0;
      local_10 = 1;
      local_8 = 4;
      if (uVar1 < 5) {
        local_8 = uVar1;
      }
      param_2 = 4;
      if (uVar2 < 5) {
        param_2 = uVar2;
      }
      do {
        param_3 = (undefined4 *)0x0;
        if (local_8 != 0) {
          param_1 = local_c;
          do {
            uVar6 = 0;
            if (param_2 != 0) {
              puVar7 = param_1;
              do {
                iVar4 = FUN_008c4cc9(iVar3,*puVar7);
                if (iVar4 < 0) {
                  return iVar4;
                }
                iVar3 = *(int *)(iVar3 + 0xc);
                uVar6 = uVar6 + 1;
                puVar7 = puVar7 + 1;
              } while (uVar6 < param_2);
            }
            if (uVar6 < uVar2) {
              iVar5 = uVar2 - uVar6;
              do {
                iVar5 = iVar5 + -1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (iVar5 != 0);
            }
            param_3 = (undefined4 *)((int)param_3 + 1);
            param_1 = param_1 + 4;
          } while (param_3 < local_8);
        }
        if (param_3 < uVar1) {
          iVar5 = uVar1 - (int)param_3;
          do {
            if (uVar2 != 0) {
              uVar6 = uVar2;
              do {
                uVar6 = uVar6 - 1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (uVar6 != 0);
            }
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        local_10 = local_10 + -1;
        local_c = local_c + 0x10;
      } while (local_10 != 0);
      return iVar4;
    }
  }
  return -0x7789f794;
}


// ==== FUN_008c7218 @ 0x008c7218 ====

int FUN_008c7218(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int local_14;
  uint local_10;
  undefined4 *local_c;
  uint local_8;
  
  if (param_3 == (undefined4 *)0x0) {
    return -0x7789f794;
  }
  iVar3 = FUN_008c6759(param_2,1);
  if ((iVar3 != 0) &&
     ((iVar4 = *(int *)(*(int *)(iVar3 + 4) + 0x40) + *(int *)((int)param_1 + 0x344) +
               *(int *)(iVar3 + 0x18), *(int *)(iVar4 + 0x10) == 0 || (*(int *)(iVar3 + 0x10) != -1)
      ))) {
    if (*(int *)(iVar4 + 4) == 2) {
      iVar3 = *(int *)(iVar3 + 0x1c);
      uVar1 = *(uint *)(iVar4 + 0x18);
      local_14 = 0;
      uVar2 = *(uint *)(iVar4 + 0x14);
      local_8 = 1;
      local_c = param_3;
      local_10 = 4;
      if (uVar2 < 5) {
        local_10 = uVar2;
      }
      param_2 = 4;
      if (uVar1 < 5) {
        param_2 = uVar1;
      }
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *param_3 = 0;
        param_3 = param_3 + 1;
      }
      do {
        param_3 = (undefined4 *)0x0;
        if (local_10 != 0) {
          param_1 = local_c;
          do {
            uVar6 = 0;
            if (param_2 != 0) {
              puVar5 = param_1;
              do {
                local_14 = FUN_008c4d25(iVar3,puVar5);
                if (local_14 < 0) {
                  return local_14;
                }
                iVar3 = *(int *)(iVar3 + 0xc);
                uVar6 = uVar6 + 1;
                puVar5 = puVar5 + 4;
              } while (uVar6 < param_2);
            }
            if (uVar6 < uVar1) {
              iVar4 = uVar1 - uVar6;
              do {
                iVar4 = iVar4 + -1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (iVar4 != 0);
            }
            param_3 = (undefined4 *)((int)param_3 + 1);
            param_1 = param_1 + 1;
          } while (param_3 < local_10);
        }
        if (param_3 < uVar2) {
          iVar4 = uVar2 - (int)param_3;
          do {
            if (uVar1 != 0) {
              uVar6 = uVar1;
              do {
                uVar6 = uVar6 - 1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (uVar6 != 0);
            }
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        local_8 = local_8 + -1;
        local_c = local_c + 0x10;
      } while (local_8 != 0);
      return local_14;
    }
    if (*(int *)(iVar4 + 4) == 3) {
      iVar3 = *(int *)(iVar3 + 0x1c);
      uVar1 = *(uint *)(iVar4 + 0x18);
      local_14 = 0;
      uVar2 = *(uint *)(iVar4 + 0x14);
      local_10 = 1;
      local_c = param_3;
      local_8 = 4;
      if (uVar2 < 5) {
        local_8 = uVar2;
      }
      param_2 = 4;
      if (uVar1 < 5) {
        param_2 = uVar1;
      }
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *param_3 = 0;
        param_3 = param_3 + 1;
      }
      do {
        param_3 = (undefined4 *)0x0;
        if (local_8 != 0) {
          param_1 = local_c;
          do {
            uVar6 = 0;
            if (param_2 != 0) {
              puVar5 = param_1;
              do {
                local_14 = FUN_008c4d25(iVar3,puVar5);
                if (local_14 < 0) {
                  return local_14;
                }
                iVar3 = *(int *)(iVar3 + 0xc);
                uVar6 = uVar6 + 1;
                puVar5 = puVar5 + 1;
              } while (uVar6 < param_2);
            }
            if (uVar6 < uVar1) {
              iVar4 = uVar1 - uVar6;
              do {
                iVar4 = iVar4 + -1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (iVar4 != 0);
            }
            param_3 = (undefined4 *)((int)param_3 + 1);
            param_1 = param_1 + 4;
          } while (param_3 < local_8);
        }
        if (param_3 < uVar2) {
          iVar4 = uVar2 - (int)param_3;
          do {
            if (uVar1 != 0) {
              uVar6 = uVar1;
              do {
                uVar6 = uVar6 - 1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (uVar6 != 0);
            }
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        local_10 = local_10 + -1;
        local_c = local_c + 0x10;
      } while (local_10 != 0);
      return local_14;
    }
  }
  return -0x7789f794;
}


// ==== FUN_008c7400 @ 0x008c7400 ====

undefined4 FUN_008c7400(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_4 != 0) && (param_3 == 0)) {
    return 0x8876086c;
  }
  iVar1 = FUN_008c6759(param_2,1);
  if (iVar1 != 0) {
    iVar3 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
            *(int *)(iVar1 + 0x18);
    if (((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
       (*(int *)(iVar1 + 0x10) == -1)) {
      if (*(int *)(iVar3 + 4) == 2) {
        uVar2 = FUN_008c4d7f(iVar3,*(undefined4 *)(iVar1 + 0x1c),param_3,param_4);
        return uVar2;
      }
      if (*(int *)(iVar3 + 4) == 3) {
        uVar2 = FUN_008c4f30(iVar3,*(undefined4 *)(iVar1 + 0x1c),param_3,param_4);
        return uVar2;
      }
    }
  }
  return 0x8876086c;
}


// ==== FUN_008c7481 @ 0x008c7481 ====

undefined4 FUN_008c7481(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_4 != 0) && (param_3 == 0)) {
    return 0x8876086c;
  }
  iVar1 = FUN_008c6759(param_2,1);
  if (iVar1 != 0) {
    iVar3 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
            *(int *)(iVar1 + 0x18);
    if (((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
       (*(int *)(iVar1 + 0x10) == -1)) {
      if (*(int *)(iVar3 + 4) == 2) {
        uVar2 = FUN_008c4f30(iVar3,*(undefined4 *)(iVar1 + 0x1c),param_3,param_4);
        return uVar2;
      }
      if (*(int *)(iVar3 + 4) == 3) {
        uVar2 = FUN_008c4d7f(iVar3,*(undefined4 *)(iVar1 + 0x1c),param_3,param_4);
        return uVar2;
      }
    }
  }
  return 0x8876086c;
}


// ==== FUN_008c7502 @ 0x008c7502 ====

undefined4 FUN_008c7502(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  if (param_4 != 0) {
    if (param_3 == 0) {
      uVar1 = 0x8876086c;
    }
    else {
      iVar2 = FUN_008c6759(param_2,1);
      if (iVar2 != 0) {
        iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
                *(int *)(iVar2 + 0x18);
        if (((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
           (*(int *)(iVar2 + 0x10) == -1)) {
          if (*(int *)(iVar3 + 4) == 2) {
            uVar1 = FUN_008c4e50(iVar3,*(undefined4 *)(iVar2 + 0x1c),param_3,param_4);
            return uVar1;
          }
          if (*(int *)(iVar3 + 4) == 3) {
            uVar1 = FUN_008c5001(iVar3,*(undefined4 *)(iVar2 + 0x1c),param_3,param_4);
            return uVar1;
          }
        }
      }
      uVar1 = 0x8876086c;
    }
  }
  return uVar1;
}


// ==== FUN_008c7584 @ 0x008c7584 ====

undefined4 FUN_008c7584(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  if (param_4 != 0) {
    if (param_3 == 0) {
      uVar1 = 0x8876086c;
    }
    else {
      iVar2 = FUN_008c6759(param_2,1);
      if (iVar2 != 0) {
        iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
                *(int *)(iVar2 + 0x18);
        if (((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
           (*(int *)(iVar2 + 0x10) == -1)) {
          if (*(int *)(iVar3 + 4) == 2) {
            uVar1 = FUN_008c5001(iVar3,*(undefined4 *)(iVar2 + 0x1c),param_3,param_4);
            return uVar1;
          }
          if (*(int *)(iVar3 + 4) == 3) {
            uVar1 = FUN_008c4e50(iVar3,*(undefined4 *)(iVar2 + 0x1c),param_3,param_4);
            return uVar1;
          }
        }
      }
      uVar1 = 0x8876086c;
    }
  }
  return uVar1;
}


// ==== FUN_008c7606 @ 0x008c7606 ====

undefined4 FUN_008c7606(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_4 != 0) && (param_3 == 0)) {
    return 0x8876086c;
  }
  iVar1 = FUN_008c6759(param_2,1);
  if (iVar1 != 0) {
    iVar3 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
            *(int *)(iVar1 + 0x18);
    if (((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
       (*(int *)(iVar1 + 0x10) == -1)) {
      if (*(int *)(iVar3 + 4) == 2) {
        uVar2 = FUN_008c50e1(iVar3,*(undefined4 *)(iVar1 + 0x1c),param_3,param_4);
        return uVar2;
      }
      if (*(int *)(iVar3 + 4) == 3) {
        uVar2 = FUN_008c52bf(iVar3,*(undefined4 *)(iVar1 + 0x1c),param_3,param_4);
        return uVar2;
      }
    }
  }
  return 0x8876086c;
}


// ==== FUN_008c7687 @ 0x008c7687 ====

undefined4 FUN_008c7687(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_4 != 0) && (param_3 == 0)) {
    return 0x8876086c;
  }
  iVar1 = FUN_008c6759(param_2,1);
  if (iVar1 != 0) {
    iVar3 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
            *(int *)(iVar1 + 0x18);
    if (((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
       (*(int *)(iVar1 + 0x10) == -1)) {
      if (*(int *)(iVar3 + 4) == 2) {
        uVar2 = FUN_008c52bf(iVar3,*(undefined4 *)(iVar1 + 0x1c),param_3,param_4);
        return uVar2;
      }
      if (*(int *)(iVar3 + 4) == 3) {
        uVar2 = FUN_008c50e1(iVar3,*(undefined4 *)(iVar1 + 0x1c),param_3,param_4);
        return uVar2;
      }
    }
  }
  return 0x8876086c;
}


// ==== FUN_008c7708 @ 0x008c7708 ====

undefined4 FUN_008c7708(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  if (param_4 != 0) {
    if (param_3 == 0) {
      uVar1 = 0x8876086c;
    }
    else {
      iVar2 = FUN_008c6759(param_2,1);
      if (iVar2 != 0) {
        iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
                *(int *)(iVar2 + 0x18);
        if (((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
           (*(int *)(iVar2 + 0x10) == -1)) {
          if (*(int *)(iVar3 + 4) == 2) {
            uVar1 = FUN_008c51cf(iVar3,*(undefined4 *)(iVar2 + 0x1c),param_3,param_4);
            return uVar1;
          }
          if (*(int *)(iVar3 + 4) == 3) {
            uVar1 = FUN_008c53ad(iVar3,*(undefined4 *)(iVar2 + 0x1c),param_3,param_4);
            return uVar1;
          }
        }
      }
      uVar1 = 0x8876086c;
    }
  }
  return uVar1;
}


// ==== FUN_008c778a @ 0x008c778a ====

undefined4 FUN_008c778a(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  if (param_4 != 0) {
    if (param_3 == 0) {
      uVar1 = 0x8876086c;
    }
    else {
      iVar2 = FUN_008c6759(param_2,1);
      if (iVar2 != 0) {
        iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
                *(int *)(iVar2 + 0x18);
        if (((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
           (*(int *)(iVar2 + 0x10) == -1)) {
          if (*(int *)(iVar3 + 4) == 2) {
            uVar1 = FUN_008c53ad(iVar3,*(undefined4 *)(iVar2 + 0x1c),param_3,param_4);
            return uVar1;
          }
          if (*(int *)(iVar3 + 4) == 3) {
            uVar1 = FUN_008c51cf(iVar3,*(undefined4 *)(iVar2 + 0x1c),param_3,param_4);
            return uVar1;
          }
        }
      }
      uVar1 = 0x8876086c;
    }
  }
  return uVar1;
}


// ==== FUN_008c780c @ 0x008c780c ====

undefined4 FUN_008c780c(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (((param_4 == 0) || (param_3 != 0)) && (iVar1 = FUN_008c6759(param_2,1), iVar1 != 0)) {
    iVar3 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
            *(int *)(iVar1 + 0x18);
    if (((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
       ((*(int *)(iVar1 + 0x10) == -1 && (*(int *)(iVar3 + 4) == 1)))) {
      uVar2 = FUN_008c549f(iVar3,*(undefined4 *)(iVar1 + 0x1c),param_3,param_4);
      return uVar2;
    }
  }
  return 0x8876086c;
}


// ==== FUN_008c787a @ 0x008c787a ====

undefined4 FUN_008c787a(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  if (param_4 != 0) {
    if (param_3 == 0) {
      uVar1 = 0x8876086c;
    }
    else {
      iVar2 = FUN_008c6759(param_2,1);
      if (iVar2 != 0) {
        iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
                *(int *)(iVar2 + 0x18);
        if ((((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
            (*(int *)(iVar2 + 0x10) == -1)) && (*(int *)(iVar3 + 4) == 1)) {
          uVar1 = FUN_008c5510(iVar3,*(undefined4 *)(iVar2 + 0x1c),param_3,param_4);
          return uVar1;
        }
      }
      uVar1 = 0x8876086c;
    }
  }
  return uVar1;
}


// ==== FUN_008c78e8 @ 0x008c78e8 ====

int FUN_008c78e8(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if (param_3 == 0) {
    iVar2 = -0x7789f794;
  }
  else {
    iVar2 = FUN_008c6759(param_2,1);
    if ((iVar2 == 0) ||
       (((iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
                  *(int *)(iVar2 + 0x18), *(int *)(iVar3 + 0x10) != 0 &&
         (*(int *)(iVar2 + 0x10) == -1)) || (*(int *)(iVar3 + 4) != 1)))) {
      iVar2 = -0x7789f794;
    }
    else {
      iVar5 = *(int *)(iVar2 + 0x1c);
      param_2 = param_3;
      uVar1 = *(uint *)(iVar3 + 0x14);
      iVar2 = 0;
      param_1 = 1;
      param_3 = 4;
      if (uVar1 < 5) {
        param_3 = uVar1;
      }
      do {
        uVar4 = 0;
        if (param_3 != 0) {
          do {
            iVar2 = FUN_008c4cc9(iVar5,*(undefined4 *)(param_2 + uVar4 * 4));
            if (iVar2 < 0) {
              return iVar2;
            }
            iVar5 = *(int *)(iVar5 + 0xc);
            uVar4 = uVar4 + 1;
          } while (uVar4 < param_3);
        }
        if (uVar4 < uVar1) {
          iVar3 = uVar1 - uVar4;
          do {
            iVar3 = iVar3 + -1;
            iVar5 = *(int *)(iVar5 + 0xc);
          } while (iVar3 != 0);
        }
        param_1 = param_1 + -1;
        param_2 = param_2 + 0x10;
      } while (param_1 != 0);
    }
  }
  return iVar2;
}


// ==== FUN_008c799e @ 0x008c799e ====

int FUN_008c799e(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int local_8;
  
  if (param_3 == (undefined4 *)0x0) {
    iVar2 = -0x7789f794;
  }
  else {
    iVar3 = FUN_008c6759(param_2,1);
    iVar2 = 0;
    if ((iVar3 == 0) ||
       (((iVar4 = *(int *)(*(int *)(iVar3 + 4) + 0x40) + *(int *)((int)param_1 + 0x344) +
                  *(int *)(iVar3 + 0x18), *(int *)(iVar4 + 0x10) != 0 &&
         (*(int *)(iVar3 + 0x10) == -1)) || (*(int *)(iVar4 + 4) != 1)))) {
      iVar2 = -0x7789f794;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x1c);
      local_8 = 1;
      uVar1 = *(uint *)(iVar4 + 0x14);
      param_1 = param_3;
      param_2 = 4;
      if (uVar1 < 5) {
        param_2 = uVar1;
      }
      *param_3 = 0;
      param_3[1] = 0;
      param_3[2] = 0;
      param_3[3] = 0;
      do {
        uVar5 = 0;
        if (param_2 != 0) {
          param_3 = param_1;
          do {
            iVar2 = FUN_008c4d25(iVar3,param_3);
            if (iVar2 < 0) {
              return iVar2;
            }
            param_3 = param_3 + 1;
            iVar3 = *(int *)(iVar3 + 0xc);
            uVar5 = uVar5 + 1;
          } while (uVar5 < param_2);
        }
        if (uVar5 < uVar1) {
          iVar4 = uVar1 - uVar5;
          do {
            iVar4 = iVar4 + -1;
            iVar3 = *(int *)(iVar3 + 0xc);
          } while (iVar4 != 0);
        }
        local_8 = local_8 + -1;
        param_1 = param_1 + 4;
      } while (local_8 != 0);
    }
  }
  return iVar2;
}


// ==== FUN_008c7a61 @ 0x008c7a61 ====

undefined4 FUN_008c7a61(int param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 local_8;
  
  pcVar6 = (char *)0x0;
  local_8 = 0;
  iVar2 = FUN_008c6759(param_2,1);
  if (((iVar2 == 0) ||
      (((piVar3 = (int *)(*(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
                         *(int *)(iVar2 + 0x18)), piVar3[4] != 0 && (*(int *)(iVar2 + 0x10) == -1))
       || (piVar3[1] != 4)))) || (*piVar3 != 4)) {
    local_8 = 0x8876086c;
  }
  else {
    iVar2 = *(int *)(*(int *)(iVar2 + 0x1c) + 8);
    pcVar4 = (char *)0x0;
    if (param_3 != (char *)0x0) {
      FUN_008c1a16(param_1 + 0x10);
      pcVar6 = param_3;
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      pcVar6 = pcVar6 + (1 - (int)(param_3 + 1));
      pcVar4 = (char *)FUN_008f33e7(pcVar6,1);
      if (pcVar4 == (char *)0x0) {
        FUN_008bf855();
        return 0x8007000e;
      }
      pcVar7 = pcVar4;
      for (uVar5 = (uint)pcVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)param_3;
        param_3 = param_3 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar5 = (uint)pcVar6 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar7 = *param_3;
        param_3 = param_3 + 1;
        pcVar7 = pcVar7 + 1;
      }
      FUN_008bf855();
    }
    *(char **)(iVar2 + 0x18) = pcVar4;
    *(char **)(iVar2 + 0x1c) = pcVar6;
  }
  return local_8;
}


// ==== FUN_008c7b44 @ 0x008c7b44 ====

undefined4 FUN_008c7b44(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_3 == (undefined4 *)0x0) {
    uVar3 = 0x8876086c;
  }
  else {
    iVar1 = FUN_008c6759(param_2,1);
    if (((iVar1 == 0) ||
        (((piVar2 = (int *)(*(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
                           *(int *)(iVar1 + 0x18)), piVar2[4] != 0 && (*(int *)(iVar1 + 0x10) == -1)
          ) || (piVar2[1] != 4)))) || (*piVar2 != 4)) {
      uVar3 = 0x8876086c;
    }
    else {
      *param_3 = *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x1c) + 8) + 0x18);
    }
  }
  return uVar3;
}


// ==== FUN_008c7bb0 @ 0x008c7bb0 ====

undefined4 FUN_008c7bb0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_008c6759(param_2,1);
  if ((iVar1 != 0) &&
     ((iVar2 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
               *(int *)(iVar1 + 0x18), *(int *)(iVar2 + 0x10) == 0 || (*(int *)(iVar1 + 0x10) != -1)
      ))) {
    if ((-1 < *(int *)(iVar2 + 4)) &&
       (((*(int *)(iVar2 + 4) < 4 && (*(int *)(iVar2 + 0x14) == 1)) && (*(int *)(iVar2 + 0x18) == 1)
        ))) {
      iVar1 = *(int *)(*(int *)(iVar1 + 0x1c) + 8);
      iVar2 = *(int *)(iVar1 + 0x10);
      if (((iVar2 == 0) || (iVar2 == 1)) || (iVar2 == 2)) {
        *(uint *)(iVar1 + 0x18) = (uint)(param_3 != 0);
        return 0;
      }
      if (iVar2 == 3) {
        *(double *)(iVar1 + 0x18) = (double)(param_3 != 0);
        return 0;
      }
    }
  }
  return 0x8876086c;
}


// ==== FUN_008c7c3b @ 0x008c7c3b ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008c7c3b(int param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_3 == (uint *)0x0) {
    return 0x8876086c;
  }
  iVar1 = FUN_008c6759(param_2,1);
  if (((iVar1 != 0) &&
      ((((iVar2 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
                  *(int *)(iVar1 + 0x18), *(int *)(iVar2 + 0x10) == 0 ||
         (*(int *)(iVar1 + 0x10) != -1)) && (-1 < *(int *)(iVar2 + 4))) &&
       ((*(int *)(iVar2 + 4) < 4 && (*(int *)(iVar2 + 0x14) == 1)))))) &&
     (*(int *)(iVar2 + 0x18) == 1)) {
    iVar1 = *(int *)(*(int *)(iVar1 + 0x1c) + 8);
    iVar2 = *(int *)(iVar1 + 0x10);
    if (((iVar2 == 0) || (iVar2 == 1)) || (iVar2 == 2)) {
      *param_3 = (uint)(*(int *)(iVar1 + 0x18) != 0);
      return 0;
    }
    if (iVar2 == 3) {
      *param_3 = (uint)(_DAT_0099d098 != *(double *)(iVar1 + 0x18));
      return 0;
    }
  }
  return 0x8876086c;
}


// ==== FUN_008c7cf1 @ 0x008c7cf1 ====

undefined4 FUN_008c7cf1(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar1 = FUN_008c6759(param_2,1);
  if (((iVar1 == 0) ||
      ((((iVar2 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
                  *(int *)(iVar1 + 0x18), *(int *)(iVar2 + 0x10) != 0 &&
         (*(int *)(iVar1 + 0x10) == -1)) || (*(int *)(iVar2 + 4) < 0)) ||
       ((3 < *(int *)(iVar2 + 4) || (*(int *)(iVar2 + 0x14) != 1)))))) ||
     (*(int *)(iVar2 + 0x18) != 1)) {
LAB_008c7d6f:
    uVar3 = 0x8876086c;
  }
  else {
    iVar1 = *(int *)(*(int *)(iVar1 + 0x1c) + 8);
    iVar2 = *(int *)(iVar1 + 0x10);
    if (iVar2 == 0) {
      param_3 = (uint)(param_3 != 0);
    }
    else if ((iVar2 != 1) && (iVar2 != 2)) {
      if (iVar2 == 3) {
        *(double *)(iVar1 + 0x18) = (double)(int)param_3;
        return 0;
      }
      goto LAB_008c7d6f;
    }
    *(uint *)(iVar1 + 0x18) = param_3;
  }
  return uVar3;
}


// ==== FUN_008c7d7c @ 0x008c7d7c ====

undefined4 FUN_008c7d7c(int param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_3 == (uint *)0x0) {
    return 0x8876086c;
  }
  iVar1 = FUN_008c6759(param_2,1);
  if (((iVar1 == 0) ||
      ((((iVar3 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
                  *(int *)(iVar1 + 0x18), *(int *)(iVar3 + 0x10) != 0 &&
         (*(int *)(iVar1 + 0x10) == -1)) || (*(int *)(iVar3 + 4) < 0)) ||
       ((3 < *(int *)(iVar3 + 4) || (*(int *)(iVar3 + 0x14) != 1)))))) ||
     (*(int *)(iVar3 + 0x18) != 1)) {
LAB_008c7e15:
    local_8 = 0x8876086c;
  }
  else {
    iVar1 = *(int *)(*(int *)(iVar1 + 0x1c) + 8);
    iVar3 = *(int *)(iVar1 + 0x10);
    if (iVar3 == 0) {
      *param_3 = (uint)(*(int *)(iVar1 + 0x18) != 0);
      return 0;
    }
    if ((iVar3 == 1) || (iVar3 == 2)) {
      uVar2 = *(uint *)(iVar1 + 0x18);
    }
    else {
      if (iVar3 != 3) goto LAB_008c7e15;
      uVar2 = __ftol();
    }
    *param_3 = uVar2;
  }
  return local_8;
}


// ==== FUN_008c7e25 @ 0x008c7e25 ====

undefined4 FUN_008c7e25(int param_1,undefined4 param_2,float param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  iVar1 = FUN_008c6759(param_2,1);
  if (((iVar1 == 0) ||
      ((((iVar3 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
                  *(int *)(iVar1 + 0x18), *(int *)(iVar3 + 0x10) != 0 &&
         (*(int *)(iVar1 + 0x10) == -1)) || (*(int *)(iVar3 + 4) < 0)) ||
       ((3 < *(int *)(iVar3 + 4) || (*(int *)(iVar3 + 0x14) != 1)))))) ||
     (*(int *)(iVar3 + 0x18) != 1)) {
LAB_008c7eba:
    uVar4 = 0x8876086c;
  }
  else {
    iVar1 = *(int *)(*(int *)(iVar1 + 0x1c) + 8);
    iVar3 = *(int *)(iVar1 + 0x10);
    if (iVar3 == 0) {
      if (DAT_0099cdc8 == param_3) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      if ((iVar3 != 1) && (iVar3 != 2)) {
        if (iVar3 == 3) {
          *(double *)(iVar1 + 0x18) = (double)param_3;
          return 0;
        }
        goto LAB_008c7eba;
      }
      uVar2 = __ftol();
    }
    *(undefined4 *)(iVar1 + 0x18) = uVar2;
  }
  return uVar4;
}


// ==== FUN_008c7ec7 @ 0x008c7ec7 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008c7ec7(int param_1,undefined4 param_2,float *param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_3 == (float *)0x0) {
    return 0x8876086c;
  }
  iVar2 = FUN_008c6759(param_2,1);
  if (((iVar2 == 0) ||
      (((iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
                 *(int *)(iVar2 + 0x18), *(int *)(iVar3 + 0x10) != 0 &&
        (*(int *)(iVar2 + 0x10) == -1)) || (*(int *)(iVar3 + 4) < 0)))) ||
     (((3 < *(int *)(iVar3 + 4) || (*(int *)(iVar3 + 0x14) != 1)) || (*(int *)(iVar3 + 0x18) != 1)))
     ) {
LAB_008c7f74:
    local_8 = 0x8876086c;
  }
  else {
    iVar2 = *(int *)(*(int *)(iVar2 + 0x1c) + 8);
    iVar3 = *(int *)(iVar2 + 0x10);
    if (iVar3 == 0) {
      fVar1 = (float)(*(int *)(iVar2 + 0x18) != 0);
    }
    else if (iVar3 == 1) {
      fVar1 = (float)*(int *)(iVar2 + 0x18);
    }
    else if (iVar3 == 2) {
      fVar1 = (float)*(int *)(iVar2 + 0x18);
      if (*(int *)(iVar2 + 0x18) < 0) {
        fVar1 = fVar1 + _DAT_0099d104;
      }
    }
    else {
      if (iVar3 != 3) goto LAB_008c7f74;
      fVar1 = (float)*(double *)(iVar2 + 0x18);
    }
    *param_3 = fVar1;
  }
  return local_8;
}


// ==== FUN_008c7f84 @ 0x008c7f84 ====

undefined4 FUN_008c7f84(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = 0;
  if (((param_4 == 0) || (param_3 != 0)) && (iVar1 = FUN_008c6759(param_2,1), iVar1 != 0)) {
    iVar3 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
            *(int *)(iVar1 + 0x18);
    if ((-1 < *(int *)(iVar3 + 4)) && (*(int *)(iVar3 + 4) < 4)) {
      iVar5 = *(int *)(iVar3 + 0x10);
      if ((iVar5 == 0) || (*(int *)(iVar1 + 0x10) != -1)) {
        iVar5 = 1;
      }
      uVar4 = *(int *)(iVar3 + 0x18) * *(int *)(iVar3 + 0x14) * iVar5;
      if (uVar4 <= param_4) {
        param_4 = uVar4;
      }
      iVar1 = *(int *)(iVar1 + 0x1c);
      if (param_4 == 0) {
        return 0;
      }
      do {
        if (iVar1 == 0) {
          return 0;
        }
        iVar3 = *(int *)(iVar1 + 8);
        iVar5 = *(int *)(iVar3 + 0x10);
        if (iVar5 == 0) {
          if (DAT_0099cdc8 == *(float *)(param_3 + uVar6 * 4)) {
            uVar2 = 0;
          }
          else {
            uVar2 = 1;
          }
LAB_008c8059:
          *(undefined4 *)(iVar3 + 0x18) = uVar2;
        }
        else {
          if ((iVar5 == 1) || (iVar5 == 2)) {
            uVar2 = __ftol();
            goto LAB_008c8059;
          }
          if (iVar5 != 3) {
            return 0x8876086c;
          }
          *(double *)(iVar3 + 0x18) = (double)*(float *)(param_3 + uVar6 * 4);
        }
        iVar1 = *(int *)(iVar1 + 0xc);
        uVar6 = uVar6 + 1;
        if (param_4 <= uVar6) {
          return 0;
        }
      } while( true );
    }
  }
  return 0x8876086c;
}


// ==== FUN_008c8078 @ 0x008c8078 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008c8078(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_4 != 0) {
    if (param_3 == 0) {
      local_8 = 0x8876086c;
    }
    else {
      iVar2 = FUN_008c6759(param_2,1);
      if (iVar2 != 0) {
        iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
                *(int *)(iVar2 + 0x18);
        if ((-1 < *(int *)(iVar3 + 4)) && (*(int *)(iVar3 + 4) < 4)) {
          iVar5 = *(int *)(iVar3 + 0x10);
          if ((iVar5 == 0) || (*(int *)(iVar2 + 0x10) != -1)) {
            iVar5 = 1;
          }
          uVar4 = *(int *)(iVar3 + 0x18) * *(int *)(iVar3 + 0x14) * iVar5;
          if (uVar4 <= param_4) {
            param_4 = uVar4;
          }
          iVar2 = *(int *)(iVar2 + 0x1c);
          uVar4 = 0;
          if (param_4 == 0) {
            return 0;
          }
          do {
            if (iVar2 == 0) {
              return 0;
            }
            iVar3 = *(int *)(iVar2 + 8);
            iVar5 = *(int *)(iVar3 + 0x10);
            if (iVar5 == 0) {
              fVar1 = (float)(*(int *)(iVar3 + 0x18) != 0);
            }
            else if (iVar5 == 1) {
              fVar1 = (float)*(int *)(iVar3 + 0x18);
            }
            else if (iVar5 == 2) {
              fVar1 = (float)*(int *)(iVar3 + 0x18);
              if (*(int *)(iVar3 + 0x18) < 0) {
                fVar1 = fVar1 + _DAT_0099d104;
              }
            }
            else {
              if (iVar5 != 3) break;
              fVar1 = (float)*(double *)(iVar3 + 0x18);
            }
            *(float *)(param_3 + uVar4 * 4) = fVar1;
            iVar2 = *(int *)(iVar2 + 0xc);
            uVar4 = uVar4 + 1;
            if (param_4 <= uVar4) {
              return 0;
            }
          } while( true );
        }
      }
      local_8 = 0x8876086c;
    }
  }
  return local_8;
}


// ==== FUN_008c8165 @ 0x008c8165 ====

undefined4 FUN_008c8165(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (((param_4 == 0) || (param_3 != 0)) && (iVar1 = FUN_008c6759(param_2,1), iVar1 != 0)) {
    iVar2 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
            *(int *)(iVar1 + 0x18);
    if ((-1 < *(int *)(iVar2 + 4)) && (*(int *)(iVar2 + 4) < 4)) {
      iVar4 = *(int *)(iVar2 + 0x10);
      if ((iVar4 == 0) || (*(int *)(iVar1 + 0x10) != -1)) {
        iVar4 = 1;
      }
      uVar3 = *(int *)(iVar2 + 0x18) * *(int *)(iVar2 + 0x14) * iVar4;
      if (uVar3 <= param_4) {
        param_4 = uVar3;
      }
      iVar1 = *(int *)(iVar1 + 0x1c);
      uVar3 = 0;
      if (param_4 == 0) {
        return 0;
      }
      do {
        if (iVar1 == 0) {
          return 0;
        }
        iVar2 = *(int *)(iVar1 + 8);
        iVar4 = *(int *)(iVar2 + 0x10);
        if (((iVar4 == 0) || (iVar4 == 1)) || (iVar4 == 2)) {
          *(uint *)(iVar2 + 0x18) = (uint)(*(int *)(param_3 + uVar3 * 4) != 0);
        }
        else {
          if (iVar4 != 3) {
            return 0x8876086c;
          }
          *(double *)(iVar2 + 0x18) = (double)(*(int *)(param_3 + uVar3 * 4) != 0);
        }
        iVar1 = *(int *)(iVar1 + 0xc);
        uVar3 = uVar3 + 1;
      } while (uVar3 < param_4);
      return 0;
    }
  }
  return 0x8876086c;
}


// ==== FUN_008c823a @ 0x008c823a ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008c823a(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_4 != 0) {
    if (param_3 == 0) {
      local_8 = 0x8876086c;
    }
    else {
      iVar1 = FUN_008c6759(param_2,1);
      if (iVar1 != 0) {
        iVar2 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
                *(int *)(iVar1 + 0x18);
        if ((-1 < *(int *)(iVar2 + 4)) && (*(int *)(iVar2 + 4) < 4)) {
          iVar4 = *(int *)(iVar2 + 0x10);
          if ((iVar4 == 0) || (*(int *)(iVar1 + 0x10) != -1)) {
            iVar4 = 1;
          }
          uVar3 = *(int *)(iVar2 + 0x18) * *(int *)(iVar2 + 0x14) * iVar4;
          if (uVar3 <= param_4) {
            param_4 = uVar3;
          }
          iVar1 = *(int *)(iVar1 + 0x1c);
          uVar3 = 0;
          if (param_4 == 0) {
            return 0;
          }
          do {
            if (iVar1 == 0) {
              return 0;
            }
            iVar2 = *(int *)(iVar1 + 8);
            iVar4 = *(int *)(iVar2 + 0x10);
            if (((iVar4 == 0) || (iVar4 == 1)) || (iVar4 == 2)) {
              *(uint *)(param_3 + uVar3 * 4) = (uint)(*(int *)(iVar2 + 0x18) != 0);
            }
            else {
              if (iVar4 != 3) break;
              *(uint *)(param_3 + uVar3 * 4) = (uint)(_DAT_0099d098 != *(double *)(iVar2 + 0x18));
            }
            iVar1 = *(int *)(iVar1 + 0xc);
            uVar3 = uVar3 + 1;
            if (param_4 <= uVar3) {
              return 0;
            }
          } while( true );
        }
      }
      local_8 = 0x8876086c;
    }
  }
  return local_8;
}


// ==== FUN_008c831e @ 0x008c831e ====

undefined4 FUN_008c831e(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if (((param_4 == 0) || (param_3 != 0)) && (iVar1 = FUN_008c6759(param_2,1), iVar1 != 0)) {
    iVar2 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
            *(int *)(iVar1 + 0x18);
    if ((-1 < *(int *)(iVar2 + 4)) && (*(int *)(iVar2 + 4) < 4)) {
      iVar5 = *(int *)(iVar2 + 0x10);
      if ((iVar5 == 0) || (*(int *)(iVar1 + 0x10) != -1)) {
        iVar5 = 1;
      }
      uVar3 = *(int *)(iVar2 + 0x18) * *(int *)(iVar2 + 0x14) * iVar5;
      if (uVar3 <= param_4) {
        param_4 = uVar3;
      }
      iVar1 = *(int *)(iVar1 + 0x1c);
      uVar3 = 0;
      if (param_4 == 0) {
        return 0;
      }
      do {
        if (iVar1 == 0) {
          return 0;
        }
        iVar2 = *(int *)(iVar1 + 8);
        iVar5 = *(int *)(iVar2 + 0x10);
        if (iVar5 == 0) {
          uVar4 = (uint)(*(int *)(param_3 + uVar3 * 4) != 0);
LAB_008c83c9:
          *(uint *)(iVar2 + 0x18) = uVar4;
        }
        else {
          if ((iVar5 == 1) || (iVar5 == 2)) {
            uVar4 = *(uint *)(param_3 + uVar3 * 4);
            goto LAB_008c83c9;
          }
          if (iVar5 != 3) {
            return 0x8876086c;
          }
          *(double *)(iVar2 + 0x18) = (double)*(int *)(param_3 + uVar3 * 4);
        }
        iVar1 = *(int *)(iVar1 + 0xc);
        uVar3 = uVar3 + 1;
        if (param_4 <= uVar3) {
          return 0;
        }
      } while( true );
    }
  }
  return 0x8876086c;
}


// ==== FUN_008c83e7 @ 0x008c83e7 ====

undefined4 FUN_008c83e7(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_4 != 0) {
    if (param_3 == 0) {
      local_8 = 0x8876086c;
    }
    else {
      iVar1 = FUN_008c6759(param_2,1);
      if (iVar1 != 0) {
        iVar3 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x344) +
                *(int *)(iVar1 + 0x18);
        if ((-1 < *(int *)(iVar3 + 4)) && (*(int *)(iVar3 + 4) < 4)) {
          iVar5 = *(int *)(iVar3 + 0x10);
          if ((iVar5 == 0) || (*(int *)(iVar1 + 0x10) != -1)) {
            iVar5 = 1;
          }
          uVar4 = *(int *)(iVar3 + 0x18) * *(int *)(iVar3 + 0x14) * iVar5;
          if (uVar4 <= param_4) {
            param_4 = uVar4;
          }
          iVar1 = *(int *)(iVar1 + 0x1c);
          uVar4 = 0;
          if (param_4 == 0) {
            return 0;
          }
          do {
            if (iVar1 == 0) {
              return 0;
            }
            iVar3 = *(int *)(iVar1 + 8);
            iVar5 = *(int *)(iVar3 + 0x10);
            if (iVar5 == 0) {
              *(uint *)(param_3 + uVar4 * 4) = (uint)(*(int *)(iVar3 + 0x18) != 0);
            }
            else {
              if ((iVar5 == 1) || (iVar5 == 2)) {
                uVar2 = *(undefined4 *)(iVar3 + 0x18);
              }
              else {
                if (iVar5 != 3) break;
                uVar2 = __ftol();
              }
              *(undefined4 *)(param_3 + uVar4 * 4) = uVar2;
            }
            iVar1 = *(int *)(iVar1 + 0xc);
            uVar4 = uVar4 + 1;
            if (param_4 <= uVar4) {
              return 0;
            }
          } while( true );
        }
      }
      local_8 = 0x8876086c;
    }
  }
  return local_8;
}


// ==== FUN_008c84c0 @ 0x008c84c0 ====

void FUN_008c84c0(byte param_1)

{
  void *in_ECX;
  
  FUN_008c64b5();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008c84e1 @ 0x008c84e1 ====

void FUN_008c84e1(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a1ba30;
  FUN_008c01aa();
  FUN_008c97a6();
  in_ECX[200] = 0;
  in_ECX[0xd2] = 0;
  in_ECX[0xd3] = 0;
  in_ECX[0xd4] = 0;
  in_ECX[0xd5] = 0;
  in_ECX[0xd6] = 0;
  in_ECX[0xcf] = 0;
  in_ECX[0xd1] = 0;
  in_ECX[2] = 1;
  return;
}


// ==== FUN_008c853c @ 0x008c853c ====

int FUN_008c853c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int extraout_EAX;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined1 local_94 [40];
  undefined1 *local_6c;
  undefined1 local_68 [4];
  undefined1 local_64 [4];
  undefined1 local_60 [4];
  uint local_5c;
  undefined4 *local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48;
  undefined4 local_44;
  uint local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  undefined4 *local_2c;
  undefined1 *local_28;
  int local_24;
  int *local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_3c = 0;
  local_2c = (undefined4 *)0x0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  iVar6 = 0;
  pvVar2 = operator_new(0x1c);
  if (pvVar2 == (void *)0x0) {
    local_1c = 0;
  }
  else {
    local_1c = FUN_008c1b7e();
  }
  if (local_1c == 0) {
LAB_008c8baf:
    iVar3 = -0x7ff8fff2;
  }
  else {
    pvVar2 = operator_new(0x1c);
    if (pvVar2 == (void *)0x0) {
      local_18 = 0;
    }
    else {
      local_18 = FUN_008c1b7e();
    }
    if (local_18 == 0) goto LAB_008c8baf;
    pvVar2 = operator_new(0x1c);
    if (pvVar2 == (void *)0x0) {
      local_14 = 0;
    }
    else {
      local_14 = FUN_008c1b7e();
    }
    if (local_14 == 0) goto LAB_008c8baf;
    pvVar2 = operator_new(0x1c);
    if (pvVar2 == (void *)0x0) {
      local_10 = 0;
    }
    else {
      local_10 = FUN_008c1b7e();
    }
    if (local_10 == 0) goto LAB_008c8baf;
    pvVar2 = operator_new(0x48);
    if (pvVar2 == (void *)0x0) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_008c5b24();
    }
    iVar7 = local_c;
    if (iVar6 == 0) goto LAB_008c8baf;
    local_24 = *(int *)(param_1 + 0x18);
    if ((((local_24 == 0) || (*(int *)(local_24 + 4) != 0xb)) ||
        (iVar1 = *(int *)(param_1 + 0x14), iVar1 == 0)) || (*(int *)(iVar1 + 4) != 3)) {
LAB_008c8ba8:
      iVar3 = -0x7fffbffb;
    }
    else {
      uVar5 = *(uint *)(local_24 + 0x1c);
      iVar3 = 0;
      if ((uVar5 & 2) == 0) {
        local_20 = (int *)(iVar1 + 0x10);
        if ((*local_20 != 9) || (local_54 = *(int *)(iVar1 + 0x18), local_54 == 0))
        goto LAB_008c8ba8;
        local_4c = 0;
        local_5c = (uVar5 >> 3 & 0x10 | uVar5 & 8) >> 3;
        iVar1 = *(int *)(local_24 + 0x2c);
        if (iVar1 != 0) {
          if ((*(int *)(iVar1 + 4) != 3) || (*(int *)(iVar1 + 0x10) != 9)) goto LAB_008c8ba8;
          local_4c = *(undefined4 *)(iVar1 + 0x18);
        }
        iVar3 = FUN_008c1e12(*(undefined4 *)(local_24 + 0x20),&local_30,local_64,local_68,&local_40,
                             local_60,&local_48);
        iVar1 = local_24;
        if (iVar3 < 0) {
          pcVar9 = s_ID3DXEffectCompiler__There_was_a_00a1b9f0;
          local_c = iVar7;
LAB_008c87b6:
          FUN_008bd320(local_c + 0x28,local_20,0,pcVar9);
        }
        else if ((local_30 != 0x12) && (local_30 != 0x11)) {
          if (local_30 == 0xf30000) {
            iVar7 = *(int *)(local_24 + 0x28);
            if (iVar7 != 0) {
              if ((((*(int *)(iVar7 + 0x1c) != 0) || (iVar7 = *(int *)(iVar7 + 0x20), iVar7 == 0))
                  || (*(int *)(iVar7 + 4) != 1)) ||
                 ((iVar7 = *(int *)(iVar7 + 8), iVar7 == 0 || (*(int *)(iVar7 + 4) != 0xe))))
              goto LAB_008c8ba8;
              piVar4 = operator_new(0xc);
              if (piVar4 == (int *)0x0) {
                piVar4 = (int *)0x0;
              }
              else {
                piVar4[2] = 0;
              }
              if (piVar4 == (int *)0x0) goto LAB_008c8baf;
              *piVar4 = local_54;
              piVar4[1] = *(int *)(iVar7 + 0x18);
              piVar4[2] = *(int *)(local_c + 0x358);
              *(int *)(local_c + 0x358) = (int)piVar4;
            }
          }
          else {
            iVar3 = FUN_008c257d(*(undefined4 *)(local_24 + 0x20),local_20,local_4c,0,param_3,
                                 local_18,&local_50,0);
            if (iVar3 < 0) {
              pcVar9 = s_ID3DXEffectCompiler__Error_initi_00a1bba8;
              goto LAB_008c87b6;
            }
            if ((local_30 < 10) || (0xe < local_30)) {
              local_2c = operator_new(local_48);
              if (local_2c == (undefined4 *)0x0) goto LAB_008c8baf;
              puVar8 = local_2c;
              for (uVar5 = local_48 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                *puVar8 = 0;
                puVar8 = puVar8 + 1;
              }
              for (uVar5 = local_48 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                *(undefined1 *)puVar8 = 0;
                puVar8 = (undefined4 *)((int)puVar8 + 1);
              }
              local_58 = local_2c;
              iVar3 = FUN_008c2483(*(undefined4 *)(local_24 + 0x20),&local_58);
              if ((-1 < iVar3) && (iVar3 = FUN_008c1bfa(local_2c,local_48,&local_44), -1 < iVar3)) {
LAB_008c8a4e:
                iVar1 = local_c;
                *(undefined4 *)(iVar6 + 0x28) = 0;
                iVar7 = *(int *)(param_1 + 0x1c);
                if (iVar7 != 0) {
                  do {
                    if (((*(int *)(iVar7 + 4) != 1) || (iVar3 = *(int *)(iVar7 + 8), iVar3 == 0)) ||
                       (*(int *)(iVar3 + 4) != 6)) goto LAB_008c8ba8;
                    if (*(int *)(iVar3 + 0x10) != 1) {
                      FUN_008bd320(iVar1 + 0x28,local_20,0,
                                   s_ID3DXEffectCompiler__There_was_a_00a1bb2c);
                      goto LAB_008c8ba8;
                    }
                    iVar3 = FUN_008c64fd(iVar3,local_1c,param_3,iVar6 + 0x30);
                    if ((iVar3 < 0) && (-1 < local_3c)) {
                      local_3c = iVar3;
                    }
                    *(int *)(iVar6 + 0x28) = *(int *)(iVar6 + 0x28) + 1;
                    iVar7 = *(int *)(iVar7 + 0xc);
                  } while (iVar7 != 0);
                  iVar3 = local_3c;
                  if (local_3c < 0) goto LAB_008c8bb4;
                }
                iVar3 = FUN_008c1d8e(local_18);
                if (-1 < iVar3) {
                  local_18 = 0;
                  iVar3 = FUN_008c1d03(local_50,0);
                  if (((-1 < iVar3) && (iVar3 = FUN_008c1d03(local_44,0), -1 < iVar3)) &&
                     ((iVar3 = FUN_008c1bfa(&local_5c,4,&param_3), -1 < iVar3 &&
                      ((iVar3 = FUN_008c1bfa(iVar6 + 0x28,4,0), -1 < iVar3 &&
                       (iVar3 = FUN_008c1d8e(local_1c), -1 < iVar3)))))) {
                    *(int *)(iVar6 + 0x20) = local_54;
                    local_1c = 0;
                    *(undefined4 *)(iVar6 + 0x24) = local_4c;
                    *(undefined4 *)(iVar6 + 0x40) = local_50;
                    *(undefined4 *)(iVar6 + 0x44) = param_3;
                    *(int *)(iVar6 + 0x2c) = local_24;
                    *(undefined4 *)(iVar6 + 0x3c) = local_44;
                    *(int *)(iVar6 + 0x34) = *(int *)(local_c + 0x34c);
                    *(int *)(iVar6 + 0x38) = *(int *)(param_1 + 0x14) + 0x10;
                    *(int *)(local_c + 0x34c) = iVar6;
                    iVar6 = 0;
                    *(int *)(local_c + 0x328) = *(int *)(local_c + 0x328) + 1;
                  }
                }
              }
            }
            else {
              iVar7 = *(int *)(iVar1 + 0x28);
              if (iVar7 == 0) {
                local_34 = 0;
                local_8 = 0;
                while( true ) {
                  uVar5 = local_40;
                  if (local_40 == 0) {
                    uVar5 = 1;
                  }
                  if (uVar5 <= local_8) goto LAB_008c8934;
                  iVar3 = FUN_008c1bfa(&local_34,4,~-(uint)(local_8 != 0) & (uint)&local_44);
                  if (iVar3 < 0) break;
                  local_8 = local_8 + 1;
                }
              }
              else {
                if ((((*(int *)(iVar7 + 0x1c) != 0) || (iVar7 = *(int *)(iVar7 + 0x20), iVar7 == 0))
                    || (*(int *)(iVar7 + 4) != 1)) ||
                   ((*(int *)(iVar7 + 8) == 0 || (*(int *)(*(int *)(iVar7 + 8) + 4) != 0xe))))
                goto LAB_008c8ba8;
                local_8 = 0;
                local_38 = iVar7;
                do {
                  uVar5 = local_40;
                  if (local_40 == 0) {
                    uVar5 = 1;
                  }
                  if (uVar5 <= local_8) break;
                  local_6c = (undefined1 *)0x0;
                  local_28 = local_94;
                  for (iVar7 = *(int *)(*(int *)(local_38 + 8) + 0x18); iVar1 = local_c, iVar7 != 0;
                      iVar7 = *(int *)(iVar7 + 0xc)) {
                    iVar3 = FUN_008c5e52(iVar7,&local_28,0x100);
                    if (iVar3 < 0) goto LAB_008c898d;
                  }
                  local_34 = 0;
                  for (local_28 = local_6c; local_28 != (undefined1 *)0x0;
                      local_28 = *(undefined1 **)(local_28 + 0x28)) {
                    iVar3 = FUN_008c2aa4(local_28,0xffffffff,*(undefined4 *)(iVar1 + 0x328),local_8,
                                         &local_34,local_14,param_3,0x100);
                    if (iVar3 < 0) goto LAB_008c898d;
                  }
                  iVar3 = FUN_008c1bfa(&local_34,4,~-(uint)(local_8 != 0) & (uint)&local_44);
                  if ((iVar3 < 0) || (iVar3 = FUN_008c1d8e(local_14), iVar3 < 0)) {
LAB_008c898d:
                    FUN_008c1afd();
                    goto LAB_008c8bb4;
                  }
                  pvVar2 = operator_new(0x1c);
                  if (pvVar2 == (void *)0x0) {
                    local_14 = 0;
                  }
                  else {
                    local_14 = FUN_008c1b7e();
                  }
                  if (local_14 == 0) {
                    iVar3 = -0x7ff8fff2;
                    goto LAB_008c898d;
                  }
                  FUN_008c1afd();
                  local_38 = *(int *)(local_38 + 0xc);
                  local_8 = local_8 + 1;
                } while (local_38 != 0);
LAB_008c8934:
                iVar3 = FUN_008c1d8e(local_10);
                if (-1 < iVar3) {
                  local_10 = 0;
                  if ((local_40 != 0) && (local_40 < local_8)) {
                    FUN_008bd320(local_c + 0x28,local_20,0,
                                 s_ID3DXEffectCompiler__There_was_a_00a1bb6c);
                    iVar3 = -0x7fffbffb;
                    goto LAB_008c8bc2;
                  }
                  *(int *)(local_c + 0x334) = *(int *)(local_c + 0x334) + local_8;
                  goto LAB_008c8a4e;
                }
              }
            }
          }
        }
      }
    }
  }
LAB_008c8bb4:
  if (local_10 != 0) {
    FUN_008c1bd9(1);
  }
LAB_008c8bc2:
  if (local_14 != 0) {
    FUN_008c1bd9(1);
  }
  if (local_1c != 0) {
    FUN_008c1bd9(1);
  }
  if (local_18 != 0) {
    FUN_008c1bd9(1);
  }
  if (iVar6 != 0) {
    FUN_008c6494(1);
  }
  if (local_2c == (undefined4 *)0x0) {
    return iVar3;
  }
  _free(local_2c);
  return extraout_EAX;
}


// ==== FUN_008c8c11 @ 0x008c8c11 ====

int FUN_008c8c11(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_4c [40];
  undefined1 *local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  undefined1 *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_10 = 0;
  local_8 = 0;
  local_24 = (undefined1 *)0x0;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_008c1b7e();
  }
  if (local_18 == 0) {
LAB_008c8e4a:
    iVar4 = -0x7ff8fff2;
  }
  else {
    pvVar1 = operator_new(0x1c);
    if (pvVar1 == (void *)0x0) {
      local_10 = 0;
    }
    else {
      local_10 = FUN_008c1b7e();
    }
    if (local_10 == 0) goto LAB_008c8e4a;
    pvVar1 = operator_new(0x30);
    if (pvVar1 == (void *)0x0) {
      local_8 = 0;
    }
    else {
      local_8 = FUN_008c5a8e();
    }
    iVar4 = param_1;
    if (local_8 == 0) goto LAB_008c8e4a;
    iVar3 = *(int *)(param_1 + 0x14);
    local_20 = 0;
    if (iVar3 == 0) {
LAB_008c8cbc:
      *(undefined4 *)(local_8 + 0x24) = 0;
      for (iVar3 = *(int *)(param_1 + 0x1c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0xc)) {
        if (((*(int *)(iVar3 + 4) != 1) || (iVar2 = *(int *)(iVar3 + 8), iVar2 == 0)) ||
           (*(int *)(iVar2 + 4) != 6)) goto LAB_008c8d34;
        if (*(int *)(iVar2 + 0x10) != 1) {
          FUN_008bd320(local_1c + 0x28,0,0,s_ID3DXEffectCompiler__There_was_a_00a1bb2c);
          goto LAB_008c8d34;
        }
        iVar2 = FUN_008c64fd(iVar2,local_10,param_4,local_8 + 0x28);
        if ((iVar2 < 0) && (-1 < local_c)) {
          local_c = iVar2;
        }
        *(int *)(local_8 + 0x24) = *(int *)(local_8 + 0x24) + 1;
      }
      local_14 = local_4c;
      for (iVar4 = *(int *)(iVar4 + 0x18); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xc)) {
        iVar3 = FUN_008c5e52(iVar4,&local_14,0xffffffff);
        if ((iVar3 < 0) && (-1 < local_c)) {
          local_c = iVar3;
        }
      }
      iVar4 = local_c;
      if (-1 < local_c) {
        param_1 = 0;
        for (local_14 = local_24; local_c = iVar4, local_14 != (undefined1 *)0x0;
            local_14 = *(undefined1 **)(local_14 + 0x28)) {
          iVar4 = FUN_008c2aa4(local_14,*(undefined4 *)(local_1c + 0x324),param_2,0xffffffff,
                               &param_1,local_18,param_4,0xffffffff);
          if ((iVar4 < 0) && (-1 < local_c)) {
            local_c = iVar4;
          }
          iVar4 = local_c;
        }
        if (((((-1 < iVar4) && (iVar4 = FUN_008c1cb1(local_20,&param_4), -1 < iVar4)) &&
             (iVar4 = FUN_008c1d03(param_4,0), -1 < iVar4)) &&
            ((iVar4 = FUN_008c1bfa(local_8 + 0x24,4,0), -1 < iVar4 &&
             (iVar4 = FUN_008c1bfa(&param_1,4,0), -1 < iVar4)))) &&
           (iVar4 = FUN_008c1d8e(local_10), -1 < iVar4)) {
          local_10 = 0;
          iVar4 = FUN_008c1d8e(local_18);
          if (-1 < iVar4) {
            *(undefined4 *)(local_8 + 0x20) = local_20;
            *(int *)(local_8 + 0x2c) = *param_5;
            *param_5 = local_8;
            goto LAB_008c8e79;
          }
        }
      }
    }
    else {
      if ((*(int *)(iVar3 + 4) == 3) && (*(int *)(iVar3 + 0x10) == 9)) {
        local_20 = *(undefined4 *)(iVar3 + 0x18);
        goto LAB_008c8cbc;
      }
LAB_008c8d34:
      iVar4 = -0x7fffbffb;
    }
  }
  if (local_8 != 0) {
    FUN_008c84c0(1);
  }
  if (local_18 != 0) {
    FUN_008c1bd9(1);
  }
  if (local_10 != 0) {
    FUN_008c1bd9(1);
  }
LAB_008c8e79:
  FUN_008c1afd();
  return iVar4;
}


// ==== FUN_008c8e8a @ 0x008c8e8a ====

void FUN_008c8e8a(void)

{
  void *_Memory;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x30) != 0) {
    FUN_008c6494(1);
    *(undefined4 *)(in_ECX + 0x30) = 0;
  }
  if (*(int *)(in_ECX + 0x2c) != 0) {
    FUN_008c84c0(1);
    *(undefined4 *)(in_ECX + 0x2c) = 0;
  }
  if (*(int *)(in_ECX + 0x34) == 0) {
    FUN_008c59eb();
    return;
  }
  _Memory = *(void **)(in_ECX + 0x34);
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)((int)_Memory + 0x34);
  *(undefined4 *)((int)_Memory + 0x34) = 0;
  FUN_008c8e8a();
  _free(_Memory);
  return;
}


// ==== FUN_008c8ee3 @ 0x008c8ee3 ====

void FUN_008c8ee3(byte param_1)

{
  void *in_ECX;
  
  FUN_008c8e8a();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008c8f04 @ 0x008c8f04 ====

void FUN_008c8f04(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a1ba30;
  if (in_ECX[200] != 0) {
    in_ECX[200] = 0;
  }
  if (in_ECX[0xd2] != 0) {
    FUN_008c8ee3(1);
    in_ECX[0xd2] = 0;
  }
  if (in_ECX[0xd3] != 0) {
    FUN_008c6494(1);
    in_ECX[0xd3] = 0;
  }
  if (in_ECX[0xd4] != 0) {
    FUN_008c5b03(1);
    in_ECX[0xd4] = 0;
  }
  if (in_ECX[0xd5] != 0) {
    FUN_008c1b5d(1);
    in_ECX[0xd5] = 0;
  }
  if (in_ECX[0xd6] != 0) {
    FUN_008c1a92(1);
    in_ECX[0xd6] = 0;
  }
  if ((void *)in_ECX[0xcf] != (void *)0x0) {
    _free((void *)in_ECX[0xcf]);
    return;
  }
  if ((void *)in_ECX[0xd1] == (void *)0x0) {
    FUN_0095cf1d();
    FUN_008c0297();
    return;
  }
  _free((void *)in_ECX[0xd1]);
  return;
}


// ==== FUN_008c8fc8 @ 0x008c8fc8 ====

void FUN_008c8fc8(byte param_1)

{
  void *in_ECX;
  
  FUN_008c8f04();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008c8fe9 @ 0x008c8fe9 ====

int FUN_008c8fe9(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_14 = 0;
  local_10 = 0;
  iVar4 = 0;
  pvVar2 = operator_new(0x1c);
  if (pvVar2 == (void *)0x0) {
    local_c = 0;
  }
  else {
    local_c = FUN_008c1b7e();
  }
  if (local_c != 0) {
    pvVar2 = operator_new(0x1c);
    if (pvVar2 == (void *)0x0) {
      local_10 = 0;
    }
    else {
      local_10 = FUN_008c1b7e();
    }
    if (local_10 != 0) {
      pvVar2 = operator_new(0x38);
      if (pvVar2 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_008c5a6e();
      }
      if (iVar4 != 0) {
        iVar5 = *(int *)(param_1 + 0x14);
        local_18 = 0;
        if (iVar5 != 0) {
          if ((*(int *)(iVar5 + 4) != 3) || (*(int *)(iVar5 + 0x10) != 9)) {
LAB_008c9219:
            local_14 = -0x7fffbffb;
            goto LAB_008c9225;
          }
          local_18 = *(undefined4 *)(iVar5 + 0x18);
        }
        *(undefined4 *)(iVar4 + 0x24) = 0;
        for (iVar5 = *(int *)(param_1 + 0x1c); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0xc)) {
          if (((*(int *)(iVar5 + 4) != 1) || (iVar3 = *(int *)(iVar5 + 8), iVar3 == 0)) ||
             (*(int *)(iVar3 + 4) != 6)) goto LAB_008c9219;
          if (*(int *)(iVar3 + 0x10) != 1) {
            pcVar6 = s_ID3DXEffectCompiler__There_was_a_00a1bb2c;
            goto LAB_008c9206;
          }
          iVar3 = FUN_008c64fd(iVar3,local_c,param_3,iVar4 + 0x30);
          if ((iVar3 < 0) && (-1 < local_14)) {
            local_14 = iVar3;
          }
          *(int *)(iVar4 + 0x24) = *(int *)(iVar4 + 0x24) + 1;
        }
        piVar1 = (int *)(iVar4 + 0x28);
        *piVar1 = 0;
        iVar5 = *(int *)(param_1 + 0x18);
LAB_008c914d:
        if (iVar5 != 0) {
          if (((*(int *)(iVar5 + 4) == 1) && (iVar3 = *(int *)(iVar5 + 8), iVar3 != 0)) &&
             (*(int *)(iVar3 + 4) == 6)) {
            if (*(int *)(iVar3 + 0x10) == 4) goto code_r0x008c9126;
            pcVar6 = s_ID3DXEffectCompiler__Only_pass_a_00a1bbe0;
LAB_008c9206:
            FUN_008bd320(in_ECX + 0x28,0,0,pcVar6);
          }
          goto LAB_008c9219;
        }
        *(int *)(in_ECX + 0x334) = *(int *)(in_ECX + 0x334) + *piVar1;
        if (((((-1 < local_14) && (local_14 = FUN_008c1cb1(local_18,&param_3), -1 < local_14)) &&
             (local_14 = FUN_008c1d03(param_3,0), -1 < local_14)) &&
            ((local_14 = FUN_008c1bfa(iVar4 + 0x24,4,0), -1 < local_14 &&
             (local_14 = FUN_008c1bfa(piVar1,4,0), -1 < local_14)))) &&
           (local_14 = FUN_008c1d8e(local_c), -1 < local_14)) {
          local_c = 0;
          local_14 = FUN_008c1d8e(local_10);
          if (-1 < local_14) {
            *(undefined4 *)(iVar4 + 0x20) = local_18;
            *(int *)(iVar4 + 0x34) = *(int *)(in_ECX + 0x348);
            *(int *)(in_ECX + 0x324) = *(int *)(in_ECX + 0x324) + 1;
            *(int *)(in_ECX + 0x348) = iVar4;
            return local_14;
          }
        }
        goto LAB_008c9225;
      }
    }
  }
  local_14 = -0x7ff8fff2;
LAB_008c9225:
  if (iVar4 != 0) {
    FUN_008c8ee3(1);
  }
  if (local_c != 0) {
    FUN_008c1bd9(1);
  }
  if (local_10 != 0) {
    FUN_008c1bd9(1);
  }
  return local_14;
code_r0x008c9126:
  iVar3 = FUN_008c8c11(iVar3,*piVar1,local_10,param_3,iVar4 + 0x2c);
  if ((iVar3 < 0) && (-1 < local_14)) {
    local_14 = iVar3;
  }
  *piVar1 = *piVar1 + 1;
  iVar5 = *(int *)(iVar5 + 0xc);
  goto LAB_008c914d;
}


// ==== FUN_008c9257 @ 0x008c9257 ====

undefined4 FUN_008c9257(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(param_1 + 8);
  *piVar1 = *piVar1 + -1;
  uVar2 = *(undefined4 *)(param_1 + 8);
  if (*piVar1 == 0) {
    FUN_008c8fc8(1);
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_008c9274 @ 0x008c9274 ====

int FUN_008c9274(int param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  char *pcVar6;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar1 = param_1;
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  local_c = 0;
  local_1c = 0;
  pvVar2 = operator_new(0x1c);
  if (pvVar2 == (void *)0x0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_008c1b7e();
  }
  if (local_8 == 0) {
LAB_008c9745:
    iVar3 = -0x7ff8fff2;
LAB_008c974a:
    if (-1 < iVar3) goto LAB_008c9761;
  }
  else {
    pvVar2 = operator_new(0x1c);
    if (pvVar2 == (void *)0x0) {
      local_c = 0;
    }
    else {
      local_c = FUN_008c1b7e();
    }
    if (local_c == 0) goto LAB_008c9745;
    pvVar2 = operator_new(0x1c);
    if (pvVar2 == (void *)0x0) {
      local_14 = 0;
    }
    else {
      local_14 = FUN_008c1b7e();
    }
    if (local_14 == 0) goto LAB_008c9745;
    pvVar2 = operator_new(0x1c);
    if (pvVar2 == (void *)0x0) {
      local_18 = 0;
    }
    else {
      local_18 = FUN_008c1b7e();
    }
    if (local_18 == 0) goto LAB_008c9745;
    iVar3 = FUN_008c1bfa(&local_1c,4,0);
    if (-1 < iVar3) {
      if ((param_1 == 0) || (*(int *)(param_1 + 4) != 4)) {
LAB_008c9407:
        iVar3 = -0x7fffbffb;
        goto LAB_008c974e;
      }
      *(undefined4 *)(in_ECX + 4) = 0;
      *(undefined4 *)(in_ECX + 0x328) = 0;
      *(undefined4 *)(in_ECX + 0x324) = 0;
      *(undefined4 *)(in_ECX + 0x32c) = 0;
      *(undefined4 *)(in_ECX + 0x330) = 1;
      *(undefined4 *)(in_ECX + 0x334) = 0;
      iVar3 = *(int *)(param_1 + 0x1c);
      if (iVar3 == 0) {
LAB_008c9411:
        if (*(int *)(in_ECX + 0x358) != 0) {
          FUN_008c1a92(1);
          *(int *)(in_ECX + 0x358) = 0;
        }
        iVar3 = FUN_008c1bfa(in_ECX + 0x328,4,0);
        if ((((-1 < iVar3) && (iVar3 = FUN_008c1bfa(in_ECX + 0x324,4,0), -1 < iVar3)) &&
            (iVar3 = FUN_008c1bfa(in_ECX + 0x334,4,0), -1 < iVar3)) &&
           ((iVar3 = FUN_008c1bfa(in_ECX + 0x330,4,0), -1 < iVar3 &&
            (iVar3 = FUN_008c1d8e(local_14), -1 < iVar3)))) {
          local_14 = 0;
          iVar3 = FUN_008c1d8e(local_18);
          if (-1 < iVar3) {
            local_18 = 0;
            *(undefined4 *)(in_ECX + 0x338) = 0;
            *(undefined4 *)(in_ECX + 0x340) = 0;
            iVar3 = FUN_008c1dae(0,(undefined4 *)(in_ECX + 0x338));
            if ((-1 < iVar3) && (iVar3 = FUN_008c1dae(0,in_ECX + 0x340), -1 < iVar3)) {
              for (iVar3 = *(int *)(in_ECX + 0x34c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x34)) {
                *(undefined4 *)(iVar3 + 0x40) = *(undefined4 *)(*(int *)(iVar3 + 0x40) + 0x18);
                *(undefined4 *)(iVar3 + 0x3c) = *(undefined4 *)(*(int *)(iVar3 + 0x3c) + 0x18);
                *(undefined4 *)(iVar3 + 0x44) = *(undefined4 *)(*(int *)(iVar3 + 0x44) + 0x18);
                for (iVar4 = *(int *)(iVar3 + 0x30); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x34)) {
                  *(undefined4 *)(iVar4 + 0x40) = *(undefined4 *)(*(int *)(iVar4 + 0x40) + 0x18);
                  *(undefined4 *)(iVar4 + 0x3c) = *(undefined4 *)(*(int *)(iVar4 + 0x3c) + 0x18);
                  *(undefined4 *)(iVar4 + 0x44) = 0;
                }
              }
              for (iVar3 = *(int *)(in_ECX + 0x348); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x34)) {
                for (iVar4 = *(int *)(iVar3 + 0x30); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x34)) {
                  *(undefined4 *)(iVar4 + 0x40) = *(undefined4 *)(*(int *)(iVar4 + 0x40) + 0x18);
                  *(undefined4 *)(iVar4 + 0x3c) = *(undefined4 *)(*(int *)(iVar4 + 0x3c) + 0x18);
                  *(undefined4 *)(iVar4 + 0x44) = 0;
                }
                for (iVar4 = *(int *)(iVar3 + 0x2c); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x2c)) {
                  for (iVar5 = *(int *)(iVar4 + 0x28); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x34)) {
                    *(undefined4 *)(iVar5 + 0x40) = *(undefined4 *)(*(int *)(iVar5 + 0x40) + 0x18);
                    *(undefined4 *)(iVar5 + 0x3c) = *(undefined4 *)(*(int *)(iVar5 + 0x3c) + 0x18);
                    *(undefined4 *)(iVar5 + 0x44) = 0;
                  }
                }
              }
              for (iVar3 = *(int *)(in_ECX + 0x354); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x18)) {
                *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(*(int *)(iVar3 + 0x20) + 0x18);
                *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(*(int *)(iVar3 + 0x1c) + 0x18);
              }
              pvVar2 = operator_new(*(uint *)(in_ECX + 0x338));
              *(void **)(in_ECX + 0x33c) = pvVar2;
              if (pvVar2 != (void *)0x0) {
                pvVar2 = operator_new(*(uint *)(in_ECX + 0x340));
                *(void **)(in_ECX + 0x344) = pvVar2;
                if (pvVar2 != (void *)0x0) {
                  iVar3 = FUN_008c1dae(*(undefined4 *)(in_ECX + 0x33c),0);
                  if ((-1 < iVar3) &&
                     (iVar3 = FUN_008c1dae(*(undefined4 *)(in_ECX + 0x344),0), -1 < iVar3)) {
                    iVar4 = *(int *)(in_ECX + 0x34c);
LAB_008c9676:
                    if (iVar4 == 0) {
                      local_10 = *(int *)(in_ECX + 0x348);
                      while (local_10 != 0) {
                        iVar5 = local_10;
                        for (iVar4 = *(int *)(local_10 + 0x30); local_10 = iVar5, iVar4 != 0;
                            iVar4 = *(int *)(iVar4 + 0x34)) {
                          iVar3 = FUN_008c5c7c(*(undefined4 *)(in_ECX + 0x344),iVar4);
                          if (iVar3 < 0) {
                            pcVar6 = s_ID3DXEffectCompiler__There_was_a_00a1bcb8;
                            goto LAB_008c968d;
                          }
                          iVar5 = local_10;
                        }
                        for (local_1c = *(int *)(iVar5 + 0x2c); local_1c != 0;
                            local_1c = *(int *)(local_1c + 0x2c)) {
                          param_1 = *(int *)(local_1c + 0x28);
                          if (param_1 != 0) {
                            do {
                              iVar3 = FUN_008c5c7c(*(undefined4 *)(in_ECX + 0x344),param_1);
                              if (iVar3 < 0) {
                                pcVar6 = s_ID3DXEffectCompiler__There_was_a_00a1bc68;
                                goto LAB_008c968d;
                              }
                              param_1 = *(int *)(param_1 + 0x34);
                            } while (param_1 != 0);
                            iVar5 = local_10;
                          }
                        }
                        local_10 = *(int *)(iVar5 + 0x34);
                      }
                      *(int *)(in_ECX + 800) = iVar1;
                    }
                    else {
                      iVar3 = FUN_008c5c7c(*(undefined4 *)(in_ECX + 0x344),iVar4);
                      if (-1 < iVar3) goto code_r0x008c9647;
                      pcVar6 = s_ID3DXEffectCompiler__There_was_a_00a1bd68;
LAB_008c968d:
                      FUN_008bd320(in_ECX + 0x28,0,0,pcVar6);
                    }
                    goto LAB_008c974a;
                  }
                  goto LAB_008c974e;
                }
              }
              iVar3 = -0x7ff8fff2;
            }
          }
        }
        goto LAB_008c974e;
      }
      do {
        if ((*(int *)(iVar3 + 4) != 1) || (iVar4 = *(int *)(iVar3 + 8), iVar4 == 0)) {
LAB_008c93f4:
          FUN_008bd320(in_ECX + 0x28,0,0,s_ID3DXEffectCompiler__There_was_a_00a1bdb0);
          goto LAB_008c9407;
        }
        if (*(int *)(iVar4 + 4) != 0xc) {
          if (*(int *)(iVar4 + 4) != 6) goto LAB_008c93f4;
          iVar5 = *(int *)(iVar4 + 0x10);
          if (iVar5 != 0) {
            if (iVar5 == 1) {
              iVar4 = FUN_008c853c(iVar4,local_14,local_c);
            }
            else if (iVar5 == 2) {
              iVar4 = FUN_008c5dc7(iVar4);
            }
            else {
              if (iVar5 != 3) goto LAB_008c9407;
              iVar4 = FUN_008c8fe9(iVar4,local_18,local_c);
            }
            if ((iVar4 < 0) && (-1 < local_10)) {
              local_10 = iVar4;
            }
          }
        }
        iVar3 = *(int *)(iVar3 + 0xc);
      } while (iVar3 != 0);
      if (-1 < local_10) goto LAB_008c9411;
      iVar3 = local_10;
      goto LAB_008c974a;
    }
  }
LAB_008c974e:
  FUN_008bd320(in_ECX + 0x28,0,0,s_ID3DXEffectCompiler__There_was_a_00a1bc20);
LAB_008c9761:
  if (local_14 != 0) {
    FUN_008c1bd9(1);
  }
  if (local_18 != 0) {
    FUN_008c1bd9(1);
  }
  if (local_8 != 0) {
    FUN_008c1bd9(1);
  }
  if (local_c != 0) {
    FUN_008c1bd9(1);
  }
  return iVar3;
code_r0x008c9647:
  for (local_10 = *(int *)(iVar4 + 0x30); local_10 != 0; local_10 = *(int *)(local_10 + 0x34)) {
    iVar3 = FUN_008c5c7c(*(undefined4 *)(in_ECX + 0x344),local_10);
    if (iVar3 < 0) {
      pcVar6 = s_ID3DXEffectCompiler__There_was_a_00a1bd10;
      goto LAB_008c968d;
    }
  }
  iVar4 = *(int *)(iVar4 + 0x34);
  goto LAB_008c9676;
}


// ==== FUN_008c97a6 @ 0x008c97a6 ====

void FUN_008c97a6(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  return;
}


// ==== FUN_008c97ba @ 0x008c97ba ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008c97ba(int param_1,char *param_2,char param_3)

{
  int iVar1;
  char *pcVar2;
  bool bVar3;
  char *pcVar4;
  char local_108 [255];
  undefined1 local_9;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  iVar1 = 0xd;
  bVar3 = true;
  pcVar4 = param_2;
  pcVar2 = s_syntax_error_009fea30;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar3 = *pcVar4 == *pcVar2;
    pcVar4 = pcVar4 + 1;
    pcVar2 = pcVar2 + 1;
  } while (bVar3);
  if (!bVar3) {
    __vsnprintf(local_108,0x100,param_2,&param_3);
    local_9 = 0;
    FUN_008bd320(*(int *)(param_1 + 4) + 0x18,param_1 + 0x20,0,&DAT_009d5e14,local_108);
    goto LAB_008c98e7;
  }
  if (*(int *)(param_1 + 0x40) != 0) goto LAB_008c98e7;
  iVar1 = *(int *)(param_1 + 0x20);
  if (iVar1 < 10) {
    if (iVar1 != 9) {
      if (iVar1 == 0) {
        pcVar4 = s_version_token_00a17798;
      }
      else {
        if (iVar1 == 1) {
          iVar1 = param_1 + 0x28;
          goto LAB_008c9871;
        }
        if (iVar1 < 2) {
LAB_008c9898:
          pcVar4 = s_token_00a176fc;
        }
        else if (iVar1 < 5) {
          pcVar4 = s_integer_constant_00a1fd58;
        }
        else {
          if (8 < iVar1) goto LAB_008c9898;
          pcVar4 = s_float_constant_00a1fd6c;
        }
      }
      goto LAB_008c98b2;
    }
    iVar1 = *(int *)(param_1 + 0x28);
LAB_008c9871:
    __snprintf(local_108,0x100,s_token___s__00a1772c,iVar1);
  }
  else {
    if (iVar1 == 10) {
      pcVar4 = s_string_constant_00a1771c;
    }
    else if (iVar1 == 0xc) {
      pcVar4 = s_end_of_line_00a17710;
    }
    else {
      if (iVar1 != 0xd) goto LAB_008c9898;
      pcVar4 = s_end_of_file_00a17704;
    }
LAB_008c98b2:
    __snprintf(local_108,0x100,pcVar4);
  }
  FUN_008bd320(*(int *)(param_1 + 4) + 0x18,(int *)(param_1 + 0x20),3000,
               s_syntax_error__unexpected__s_00a1fd3c,local_108);
LAB_008c98e7:
  *(undefined4 *)(param_1 + 0x40) = 1;
  return;
}


// ==== FUN_008c98fa @ 0x008c98fa ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008c98fa(int param_1,undefined4 param_2,undefined4 param_3,char *param_4,char param_5)

{
  char local_108 [255];
  undefined1 local_9;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  __vsnprintf(local_108,0x100,param_4,&param_5);
  local_9 = 0;
  FUN_008bd320(*(int *)(param_1 + 4) + 0x18,param_2,param_3,&DAT_009d5e14,local_108);
  *(undefined4 *)(param_1 + 0x40) = 1;
  return;
}


// ==== FUN_008c9960 @ 0x008c9960 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008c9960(int param_1,undefined4 param_2,undefined4 param_3,char *param_4,char param_5)

{
  char local_108 [255];
  undefined1 local_9;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  __vsnprintf(local_108,0x100,param_4,&param_5);
  local_9 = 0;
  FUN_008bd3f7(*(int *)(param_1 + 4) + 0x18,param_2,param_3,&DAT_009d5e14,local_108);
  return;
}


// ==== FUN_008c99bd @ 0x008c99bd ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008c99bd(int param_1,undefined4 param_2,undefined4 param_3,char *param_4,char param_5)

{
  char local_108 [255];
  undefined1 local_9;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  __vsnprintf(local_108,0x100,param_4,&param_5);
  local_9 = 0;
  FUN_008bd320(*(int *)(param_1 + 4) + 0x18,param_2,param_3,&DAT_009d5e14,local_108);
  *(undefined4 *)(param_1 + 0x40) = 1;
  *(undefined4 *)(param_1 + 0x44) = 1;
  return;
}


// ==== FUN_008c9a25 @ 0x008c9a25 ====

int FUN_008c9a25(int param_1)

{
  int in_ECX;
  
  if (param_1 == 0) {
    if (*(int *)(in_ECX + 0x40) == 0) {
      FUN_008c99bd();
    }
    *(undefined4 *)(in_ECX + 0x40) = 1;
    *(undefined4 *)(in_ECX + 0x44) = 1;
  }
  return param_1;
}


// ==== FUN_008c9a5a @ 0x008c9a5a ====

undefined4 FUN_008c9a5a(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x10) != 0) && (param_2 == 0)) {
    param_2 = *(int *)(*(int *)(in_ECX + 0x10) + 0x14);
  }
  iVar1 = FUN_008bf738(0x24);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f3893(param_1,param_2,0,0,*(undefined4 *)(in_ECX + 0x10));
  }
  if (iVar1 == 0) {
    FUN_008c99bd();
    uVar2 = 0x8007000e;
  }
  else {
    *(int *)(in_ECX + 0x10) = iVar1;
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_008c9abe @ 0x008c9abe ====

undefined4 FUN_008c9abe(int param_1,uint param_2)

{
  byte bVar1;
  undefined4 uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int *piVar8;
  uint uVar9;
  int *piVar10;
  bool bVar11;
  
  iVar6 = *(int *)(param_2 + 0x14);
  piVar10 = (int *)(param_1 + 0x1c);
  if (*piVar10 != 0) {
    do {
      iVar5 = *piVar10;
      pbVar7 = *(byte **)(iVar6 + 0x18);
      pbVar3 = *(byte **)(iVar5 + 0x10);
      do {
        bVar1 = *pbVar7;
        bVar11 = bVar1 < *pbVar3;
        if (bVar1 != *pbVar3) {
LAB_008c9b07:
          iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
          goto LAB_008c9b0c;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar7[1];
        bVar11 = bVar1 < pbVar3[1];
        if (bVar1 != pbVar3[1]) goto LAB_008c9b07;
        pbVar7 = pbVar7 + 2;
        pbVar3 = pbVar3 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_008c9b0c:
      if (iVar4 < 0) {
        piVar10 = (int *)(iVar5 + 8);
      }
      else {
        if (iVar4 < 1) break;
        piVar10 = (int *)(iVar5 + 0xc);
      }
    } while (*piVar10 != 0);
    if (*piVar10 != 0) goto LAB_008c9b4e;
  }
  iVar5 = FUN_008bf738(0x18);
  if (iVar5 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = FUN_008f3627(*(undefined4 *)(iVar6 + 0x18),0,0,0);
  }
  *piVar10 = iVar6;
  if (iVar6 == 0) {
    return 0x8007000e;
  }
LAB_008c9b4e:
  iVar6 = FUN_008bf738(0x14);
  uVar9 = 0;
  if (iVar6 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = FUN_008f3584(param_2,*(undefined4 *)(*piVar10 + 0x14),s_Stmts_00a1fda0);
  }
  *(int *)(*piVar10 + 0x14) = iVar6;
  if (iVar6 == 0) {
    return 0x8007000e;
  }
  if (*(int *)(*(int *)(*piVar10 + 0x14) + 0xc) == 0) {
    iVar6 = *piVar10;
    piVar8 = piVar10;
    while (iVar6 != 0) {
      while ((iVar6 = *piVar8, iVar6 != 0 && (iVar5 = *(int *)(iVar6 + 8), iVar5 != 0))) {
        uVar2 = *(undefined4 *)(iVar5 + 0xc);
        *(int *)(iVar5 + 0xc) = iVar6;
        *(undefined4 *)(iVar6 + 8) = uVar2;
        *piVar8 = iVar5;
      }
      piVar8 = (int *)(iVar6 + 0xc);
      uVar9 = uVar9 + 1;
      iVar6 = *piVar8;
    }
    while (uVar9 = uVar9 >> 1, uVar9 != 0) {
      if (uVar9 != 0) {
        piVar8 = piVar10;
        param_2 = uVar9;
        do {
          iVar6 = *piVar8;
          if ((iVar6 != 0) && (iVar5 = *(int *)(iVar6 + 0xc), iVar5 != 0)) {
            uVar2 = *(undefined4 *)(iVar5 + 8);
            *(int *)(iVar5 + 8) = iVar6;
            *(undefined4 *)(iVar6 + 0xc) = uVar2;
            *piVar8 = iVar5;
          }
          piVar8 = (int *)(*piVar8 + 0xc);
          param_2 = param_2 - 1;
        } while (param_2 != 0);
      }
    }
  }
  return 0;
}


// ==== FUN_008c9bf1 @ 0x008c9bf1 ====

undefined4 FUN_008c9bf1(int param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  bool bVar6;
  
  iVar5 = *(int *)(param_2 + 0x1c);
  if (iVar5 != 0) {
    do {
      pbVar2 = *(byte **)(iVar5 + 0x10);
      pbVar4 = *(byte **)(param_1 + 8);
      do {
        bVar1 = *pbVar4;
        bVar6 = bVar1 < *pbVar2;
        if (bVar1 != *pbVar2) {
LAB_008c9c30:
          iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_008c9c35;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar4[1];
        bVar6 = bVar1 < pbVar2[1];
        if (bVar1 != pbVar2[1]) goto LAB_008c9c30;
        pbVar4 = pbVar4 + 2;
        pbVar2 = pbVar2 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_008c9c35:
      if (iVar3 == 0) {
        return *(undefined4 *)(iVar5 + 0x14);
      }
      if (iVar3 < 0) {
        iVar5 = *(int *)(iVar5 + 8);
      }
      else {
        iVar5 = *(int *)(iVar5 + 0xc);
      }
    } while (iVar5 != 0);
  }
  return 0;
}


// ==== FUN_008c9c55 @ 0x008c9c55 ====

undefined4 FUN_008c9c55(int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  
  if (param_1 == param_2) {
    return 0;
  }
  switch(param_1) {
  case 1:
  case 5:
    if (param_2 < 1) {
      return 1;
    }
    bVar3 = SBORROW4(param_2,8);
    bVar2 = param_2 + -8 < 0;
    bVar1 = param_2 == 8;
    break;
  case 2:
  case 6:
    if (param_2 < 1) {
      return 1;
    }
    if (param_2 < 3) {
      return 0;
    }
    if (param_2 < 5) {
      return 1;
    }
    bVar3 = SBORROW4(param_2,6);
    bVar2 = param_2 + -6 < 0;
    bVar1 = param_2 == 6;
    break;
  case 3:
  case 7:
    if (param_2 == 1) {
      return 0;
    }
    if (param_2 == 3) {
      return 0;
    }
    param_2 = param_2 + -5;
    goto LAB_008c9c9d;
  case 4:
  case 8:
    if (param_2 == 1) {
      return 0;
    }
    if (param_2 < 4) {
      return 1;
    }
    if (param_2 < 6) {
      return 0;
    }
    bVar1 = param_2 == 8;
    goto LAB_008c9cd8;
  case 9:
    if (param_2 < 9) {
      return 1;
    }
    bVar3 = SBORROW4(param_2,0xc);
    bVar2 = param_2 + -0xc < 0;
    bVar1 = param_2 == 0xc;
    break;
  case 10:
    if (param_2 < 9) {
      return 1;
    }
    bVar3 = SBORROW4(param_2,10);
    bVar2 = param_2 + -10 < 0;
    bVar1 = param_2 == 10;
    break;
  case 0xb:
    param_2 = param_2 + -9;
LAB_008c9c9d:
    if (param_2 == 0) {
      return 0;
    }
    bVar1 = param_2 == 2;
    goto LAB_008c9cd8;
  case 0xc:
    if (param_2 == 9) {
      return 0;
    }
    bVar1 = param_2 == 0xc;
LAB_008c9cd8:
    if (bVar1) {
      return 0;
    }
  default:
    goto LAB_008c9c7d;
  }
  if (bVar1 || bVar3 != bVar2) {
    return 0;
  }
LAB_008c9c7d:
  return 1;
}


// ==== FUN_008c9d0e @ 0x008c9d0e ====

undefined4 FUN_008c9d0e(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x14);
  if (iVar1 != 0) {
    *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar1 + 0xc) = 0;
  }
  return 0;
}


// ==== FUN_008c9d22 @ 0x008c9d22 ====

undefined4 FUN_008c9d22(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x14) == 0) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(in_ECX + 0x14) + 8);
}


// ==== FUN_008c9d2e @ 0x008c9d2e ====

undefined4 FUN_008c9d2e(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == 1) {
    do {
      if (*(int *)(param_1 + 4) != 1) break;
      FUN_008c9d2e(*(undefined4 *)(param_1 + 8),param_2);
      param_1 = *(int *)(param_1 + 0xc);
    } while (param_1 != 0);
    if (param_1 == 0) {
      return 0;
    }
  }
  else if (iVar1 == 6) {
    param_1 = *(int *)(param_1 + 0x18);
  }
  else if (iVar1 == 8) {
    param_1 = *(int *)(param_1 + 0x10);
  }
  else {
    if (iVar1 == 9) {
      if (param_2 == 0) {
        *(byte *)(param_1 + 0x21) = *(byte *)(param_1 + 0x21) & 0xfd;
        return 0;
      }
      *(byte *)(param_1 + 0x21) = *(byte *)(param_1 + 0x21) | 2;
      return 0;
    }
    if (iVar1 != 0xb) {
      FUN_008c99bd();
      return 0;
    }
    param_1 = *(int *)(param_1 + 0x20);
  }
  FUN_008c9d2e(param_1,param_2);
  return 0;
}


// ==== FUN_008c9dc3 @ 0x008c9dc3 ====

undefined4 FUN_008c9dc3(int param_1,int param_2)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((*(uint *)(param_1 + 0x10) & *(uint *)(param_2 + 0x10)) != 0) {
    FUN_008c98fa();
  }
  if ((*(int *)(param_1 + 0x14) != 0) && (*(int *)(param_2 + 0x14) != 0)) {
    puVar2 = (undefined4 *)(*(int *)(param_2 + 0x14) + 0x10);
    puVar3 = (undefined4 *)(in_ECX + 0x20);
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_008c97ba(in_ECX,s_syntax_error_009fea30);
  }
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | *(uint *)(param_2 + 0x10);
  if ((*(int *)(param_1 + 0x14) == 0) && (*(int *)(param_2 + 0x14) != 0)) {
    iVar1 = FUN_008f352c(*(int *)(param_2 + 0x14));
    *(int *)(param_1 + 0x14) = iVar1;
    if (iVar1 == 0) {
      return 0x8007000e;
    }
  }
  return 0;
}


// ==== FUN_008c9e50 @ 0x008c9e50 ====

uint FUN_008c9e50(int param_1)

{
  int iVar1;
  
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          if (param_1 == 0) {
            return 0;
          }
          iVar1 = *(int *)(param_1 + 4);
          if (iVar1 != 1) break;
          iVar1 = FUN_008c9e50(*(undefined4 *)(param_1 + 8));
          if (iVar1 != 0) {
            return 1;
          }
          param_1 = *(int *)(param_1 + 0xc);
        }
        if (iVar1 != 6) break;
        param_1 = *(int *)(param_1 + 0x18);
      }
      if (iVar1 != 8) break;
      param_1 = *(int *)(param_1 + 0x10);
    }
    if (iVar1 == 9) {
      return *(uint *)(param_1 + 0x20) & 0x200;
    }
    if (iVar1 != 0xb) break;
    param_1 = *(int *)(param_1 + 0x20);
  }
  FUN_008c99bd();
  return 0;
}


// ==== FUN_008c9ec3 @ 0x008c9ec3 ====

bool FUN_008c9ec3(int param_1)

{
  bool bVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 4) != 9)) {
    bVar1 = false;
  }
  else {
    bVar1 = *(int *)(param_1 + 0x10) == 0;
  }
  return bVar1;
}


// ==== FUN_008c9ee7 @ 0x008c9ee7 ====

undefined4 FUN_008c9ee7(int param_1)

{
  int iVar1;
  
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          if (param_1 == 0) {
            return 1;
          }
          iVar1 = *(int *)(param_1 + 4);
          if (iVar1 != 1) break;
          iVar1 = FUN_008c9ee7(*(undefined4 *)(param_1 + 8));
          if (iVar1 == 0) {
            return 0;
          }
          param_1 = *(int *)(param_1 + 0xc);
        }
        if (iVar1 != 6) break;
        param_1 = *(int *)(param_1 + 0x18);
      }
      if (iVar1 != 8) break;
      param_1 = *(int *)(param_1 + 0x10);
    }
    if (iVar1 == 9) break;
    if (iVar1 != 0xb) {
      FUN_008c99bd();
      return 0;
    }
    param_1 = *(int *)(param_1 + 0x20);
  }
  if (*(int *)(param_1 + 0x10) < 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x10) < 3) {
    return 1;
  }
  return 0;
}


// ==== FUN_008c9f5e @ 0x008c9f5e ====

int FUN_008c9f5e(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = 0;
  if (param_1 == 0) {
    return 0;
  }
  do {
    if (*(int *)(param_1 + 4) != 1) break;
    iVar1 = FUN_008c9f5e(*(undefined4 *)(param_1 + 8));
    param_1 = *(int *)(param_1 + 0xc);
    iVar2 = iVar2 + iVar1;
  } while (param_1 != 0);
  if (param_1 == 0) {
    return iVar2;
  }
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == 6) {
    uVar3 = *(undefined4 *)(param_1 + 0x18);
  }
  else {
    if (iVar1 == 8) {
      iVar1 = FUN_008c9f5e(*(undefined4 *)(param_1 + 0x10));
      iVar1 = iVar1 * *(int *)(param_1 + 0x14);
      goto LAB_008c9fe3;
    }
    if (iVar1 == 9) {
      iVar1 = *(int *)(param_1 + 0x1c) * *(int *)(param_1 + 0x18);
      goto LAB_008c9fe3;
    }
    if (iVar1 != 0xb) {
      FUN_008c99bd();
      return 0;
    }
    uVar3 = *(undefined4 *)(param_1 + 0x20);
  }
  iVar1 = FUN_008c9f5e(uVar3);
LAB_008c9fe3:
  return iVar1 + iVar2;
}


// ==== FUN_008c9fec @ 0x008c9fec ====

bool FUN_008c9fec(int param_1,int param_2)

{
  int iVar1;
  
LAB_008c9ffc:
  while( true ) {
    if (param_1 == 0) {
      return param_2 == 0;
    }
    iVar1 = *(int *)(param_1 + 4);
    if (iVar1 != 1) break;
    if (param_2 == 0) {
      return false;
    }
    if (*(int *)(param_2 + 4) != 1) break;
    iVar1 = FUN_008c9fec(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_2 + 8));
    if (iVar1 == 0) {
      return false;
    }
    param_1 = *(int *)(param_1 + 0xc);
    param_2 = *(int *)(param_2 + 0xc);
  }
  if ((param_2 != 0) && (iVar1 == *(int *)(param_2 + 4))) {
    if (iVar1 == 6) {
      param_2 = *(int *)(param_2 + 0x18);
      param_1 = *(int *)(param_1 + 0x18);
      goto LAB_008c9ffc;
    }
    if (iVar1 == 8) {
      if (*(int *)(param_1 + 0x14) == *(int *)(param_2 + 0x14)) {
        param_2 = *(int *)(param_2 + 0x10);
        param_1 = *(int *)(param_1 + 0x10);
        goto LAB_008c9ffc;
      }
    }
    else {
      if (iVar1 == 9) {
        if (*(int *)(param_1 + 0x10) != *(int *)(param_2 + 0x10)) {
          return false;
        }
        if (*(int *)(param_1 + 0x14) != *(int *)(param_2 + 0x14)) {
          return false;
        }
        if (*(int *)(param_1 + 0x18) != *(int *)(param_2 + 0x18)) {
          return false;
        }
        if (*(int *)(param_1 + 0x1c) == *(int *)(param_2 + 0x1c)) {
          return true;
        }
        return false;
      }
      if (iVar1 == 0xb) {
        param_2 = *(int *)(param_2 + 0x20);
        param_1 = *(int *)(param_1 + 0x20);
        goto LAB_008c9ffc;
      }
    }
  }
  return false;
}


// ==== FUN_008ca09e @ 0x008ca09e ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008ca09e(char *param_1,uint param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  char *_Format;
  char *local_10c;
  char local_108 [255];
  undefined1 local_9;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  local_10c = local_108;
  if (param_3 == 0) {
    local_10c = &DAT_00a1fef8;
    goto LAB_008ca2da;
  }
  iVar4 = *(int *)(param_3 + 4);
  if (iVar4 == 1) {
    iVar4 = FUN_008c9e50(param_3);
    pcVar5 = s_const_00a1fee8;
    if (iVar4 == 0) {
      pcVar5 = &DAT_0099cf70;
    }
    pcVar3 = (char *)FUN_008c9f5e(param_3);
    _Format = s__sstruct__u__00a1fde4;
  }
  else {
    if (iVar4 == 8) {
      iVar4 = *(int *)(param_3 + 4);
      iVar2 = param_3;
      while (iVar4 == 8) {
        iVar2 = *(int *)(iVar2 + 0x10);
        iVar4 = *(int *)(iVar2 + 4);
      }
      iVar4 = FUN_008ca09e(local_108,0xff,iVar2);
      for (; *(int *)(param_3 + 4) == 8; param_3 = *(int *)(param_3 + 0x10)) {
        __snprintf(local_108 + iVar4,0xff - iVar4,&DAT_00a1fdf4,*(undefined4 *)(param_3 + 0x14));
        pcVar5 = local_108 + iVar4;
        local_9 = 0;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        iVar4 = (int)pcVar5 - (int)(local_108 + 1);
      }
      goto LAB_008ca2da;
    }
    if (iVar4 != 9) {
      local_10c = s_unknown_00a1fef0;
      goto LAB_008ca2da;
    }
    pcVar5 = s_const_00a1fee8;
    if ((*(byte *)(param_3 + 0x21) & 2) == 0) {
      pcVar5 = &DAT_0099cf70;
    }
    switch(*(undefined4 *)(param_3 + 0x14)) {
    case 0:
      pcVar3 = (char *)&DAT_00a1fee0;
      break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
      pcVar3 = &DAT_009febf0;
      break;
    case 9:
    case 0xb:
      pcVar3 = s_float_00a1fed0;
      break;
    case 10:
      pcVar3 = (char *)&DAT_00a1fed8;
      break;
    case 0xc:
      pcVar3 = s_double_00a1fec8;
      break;
    case 0xd:
      pcVar3 = &DAT_00a00f30;
      break;
    case 0xe:
      pcVar3 = s_string_009fd520;
      break;
    case 0xf:
      pcVar3 = s_texture_00a1fec0;
      break;
    case 0x10:
      pcVar3 = s_texture1D_00a1feb4;
      break;
    case 0x11:
      pcVar3 = s_texture2D_00a1fea8;
      break;
    case 0x12:
      pcVar3 = s_texture3D_00a1fe9c;
      break;
    case 0x13:
      pcVar3 = s_textureCUBE_00a1fe90;
      break;
    case 0x14:
      pcVar3 = s_sampler_00a1fe88;
      break;
    case 0x15:
      pcVar3 = s_sampler1D_00a1fe7c;
      break;
    case 0x16:
      pcVar3 = s_sampler2D_00a1fe70;
      break;
    case 0x17:
      pcVar3 = s_sampler3D_00a1fe64;
      break;
    case 0x18:
      pcVar3 = s_samplerCUBE_00a1fe58;
      break;
    case 0x19:
      pcVar3 = s_pixelshader_00a1fe4c;
      break;
    case 0x1a:
      pcVar3 = s_vertexshader_00a1fe3c;
      break;
    case 0x1b:
      pcVar3 = s_pixelfragment_00a1fe2c;
      break;
    case 0x1c:
      pcVar3 = s_vertexfragment_00a1fe1c;
      break;
    case 0x1d:
      pcVar3 = s_stateblock_00a1fe10;
      break;
    default:
      pcVar3 = s_unknown_00a1fef0;
    }
    if (*(int *)(param_3 + 0x10) == 1) {
      __snprintf(local_108,0xff,s__s_s_u_00a1fdfc,pcVar5,pcVar3,*(undefined4 *)(param_3 + 0x1c));
      goto LAB_008ca2da;
    }
    if (*(int *)(param_3 + 0x10) == 2) {
      __snprintf(local_108,0xff,s__s_s_ux_u_00a1fe04,pcVar5,pcVar3,*(undefined4 *)(param_3 + 0x18),
                 *(undefined4 *)(param_3 + 0x1c));
      goto LAB_008ca2da;
    }
    _Format = &DAT_009ff01c;
  }
  __snprintf(local_108,0xff,_Format,pcVar5,pcVar3);
LAB_008ca2da:
  pcVar5 = local_10c;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar6 = (int)pcVar5 - (int)(local_10c + 1);
  if (param_2 < (uint)((int)pcVar5 - (int)(local_10c + 1))) {
    uVar6 = param_2;
  }
  pcVar5 = param_1;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)local_10c;
    local_10c = local_10c + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pcVar5 = *local_10c;
    local_10c = local_10c + 1;
    pcVar5 = pcVar5 + 1;
  }
  param_1[uVar6] = '\0';
  return;
}


// ==== FUN_008ca399 @ 0x008ca399 ====

undefined4 FUN_008ca399(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 != 0) {
    do {
      iVar1 = *(int *)(param_1 + 4);
      if (iVar1 == 1) {
        uVar2 = FUN_008c9f5e(*(undefined4 *)(param_1 + 8));
        if (param_2 < uVar2) {
          param_1 = *(int *)(param_1 + 8);
        }
        else {
          param_1 = *(int *)(param_1 + 0xc);
          param_2 = param_2 - uVar2;
        }
      }
      else if (iVar1 == 6) {
        param_1 = *(int *)(param_1 + 0x18);
      }
      else if (iVar1 == 8) {
        param_1 = *(int *)(param_1 + 0x10);
        uVar2 = FUN_008c9f5e(param_1);
        if (uVar2 == 0) {
          return 0x80004005;
        }
        param_2 = param_2 % uVar2;
      }
      else {
        if (iVar1 == 9) {
          iVar1 = *(int *)(param_1 + 0x10);
          if (((iVar1 == 0) || (iVar1 == 1)) || (iVar1 == 2)) {
            *(undefined4 *)(param_3 + 0x10) = 0;
          }
          else if (iVar1 == 3) {
            *(undefined4 *)(param_3 + 0x10) = 3;
          }
          *(undefined4 *)(param_3 + 0x14) = *(undefined4 *)(param_1 + 0x14);
          *(undefined4 *)(param_3 + 0x18) = 1;
          *(undefined4 *)(param_3 + 0x1c) = 1;
          *(uint *)(param_3 + 0x20) = *(uint *)(param_1 + 0x20) & 0x200;
          return 0;
        }
        if (iVar1 != 0xb) {
          FUN_008c99bd();
          return 0;
        }
        param_1 = *(int *)(param_1 + 0x20);
      }
    } while (param_1 != 0);
  }
  return 0x80004005;
}


// ==== FUN_008ca464 @ 0x008ca464 ====

undefined4 FUN_008ca464(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  bool bVar9;
  
  if ((((param_1 == 0) || (*(int *)(param_1 + 4) != 9)) || (param_2 == 0)) ||
     (*(int *)(param_2 + 4) != 9)) {
LAB_008ca602:
    uVar4 = 0x80004005;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x14);
    iVar2 = *(int *)(param_2 + 0x14);
    if (iVar1 == iVar2) {
      *param_3 = iVar1;
    }
    else {
      uVar7 = *(uint *)(&DAT_00a1ff00 + iVar2 * 8);
      if (*(uint *)(&DAT_00a1ff00 + iVar2 * 8) < *(uint *)(&DAT_00a1ff00 + iVar1 * 8)) {
        uVar7 = *(uint *)(&DAT_00a1ff00 + iVar1 * 8);
      }
      uVar3 = *(uint *)(&DAT_00a1ff04 + iVar1 * 8) & *(uint *)(&DAT_00a1ff04 + iVar2 * 8);
      iVar6 = 1;
      if ((uVar3 & 1) == 0) {
        if ((uVar3 & 4) == 0) {
          if ((uVar3 & 2) == 0) {
            if ((uVar3 & 8) == 0) {
              if ((uVar3 & 0x10) != 0) {
                uVar7 = 0;
                do {
                  if (uVar7 == 0) {
                    iVar6 = iVar1;
                    iVar5 = iVar2;
                  }
                  else {
                    iVar6 = iVar2;
                    iVar5 = iVar1;
                  }
                  if (iVar5 == 0xd) {
LAB_008ca60e:
                    *param_3 = iVar6;
                    goto LAB_008ca613;
                  }
                  if (iVar5 == 0xf) {
                    if (0xe < iVar6) {
                      bVar9 = SBORROW4(iVar6,0x13);
                      iVar5 = iVar6 + -0x13;
                      bVar8 = iVar6 == 0x13;
LAB_008ca5fa:
                      if (bVar8 || bVar9 != iVar5 < 0) goto LAB_008ca60e;
                    }
                  }
                  else if ((iVar5 == 0x14) && (0x13 < iVar6)) {
                    bVar9 = SBORROW4(iVar6,0x18);
                    iVar5 = iVar6 + -0x18;
                    bVar8 = iVar6 == 0x18;
                    goto LAB_008ca5fa;
                  }
                  uVar7 = uVar7 + 1;
                } while (uVar7 < 2);
              }
              goto LAB_008ca602;
            }
            if (uVar7 == 0) {
              *param_3 = 9;
            }
            else if ((uVar7 == 8) || (uVar7 == 0x10)) {
              *param_3 = 10;
            }
            else if (uVar7 == 0x20) {
              *param_3 = 0xb;
            }
            else if (uVar7 == 0x40) {
              *param_3 = 0xc;
            }
          }
          else if (uVar7 == 0) {
LAB_008ca503:
            *param_3 = iVar6;
          }
          else if (uVar7 == 8) {
            *param_3 = 2;
          }
          else if (uVar7 == 0x10) {
            *param_3 = 3;
          }
          else if ((uVar7 == 0x20) || (uVar7 == 0x40)) {
            *param_3 = 4;
          }
        }
        else if (uVar7 == 0) {
          *param_3 = 5;
        }
        else {
          iVar6 = 8;
          if (uVar7 == 8) {
            *param_3 = 6;
          }
          else if (uVar7 == 0x10) {
            *param_3 = 7;
          }
          else if ((uVar7 == 0x20) || (uVar7 == 0x40)) goto LAB_008ca503;
        }
      }
      else {
        *param_3 = 0;
      }
    }
LAB_008ca613:
    uVar4 = 0;
  }
  return uVar4;
}


// ==== FUN_008ca617 @ 0x008ca617 ====

undefined4 FUN_008ca617(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 0x10);
  while( true ) {
    if (iVar2 == 0) {
      return param_1;
    }
    iVar1 = *(int *)(iVar2 + 0x10);
    if (((iVar1 == 2) || (iVar1 == 3)) || (iVar1 == 4)) break;
    iVar2 = *(int *)(iVar2 + 0x20);
  }
  FUN_008c98fa();
  return 0;
}


// ==== FUN_008ca65c @ 0x008ca65c ====

int FUN_008ca65c(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 0;
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == 1) {
    do {
      if (*(int *)(param_1 + 4) != 1) break;
      iVar1 = FUN_008ca65c(*(undefined4 *)(param_1 + 8),param_2 + iVar3 * 4);
      param_1 = *(int *)(param_1 + 0xc);
      iVar3 = iVar3 + iVar1;
    } while (param_1 != 0);
    if (param_1 == 0) {
      return iVar3;
    }
    iVar1 = FUN_008ca65c(param_1,param_2 + iVar3 * 4);
    return iVar3 + iVar1;
  }
  if (iVar1 == 6) {
    uVar4 = *(undefined4 *)(param_1 + 0x18);
LAB_008ca6a4:
    iVar3 = FUN_008ca65c(uVar4,param_2);
    return iVar3;
  }
  if (iVar1 == 8) {
    uVar2 = 0;
    if (*(int *)(param_1 + 0x14) == 0) {
      return 0;
    }
    do {
      iVar1 = FUN_008ca65c(*(undefined4 *)(param_1 + 0x10),param_2 + iVar3 * 4);
      iVar3 = iVar3 + iVar1;
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(param_1 + 0x14));
    return iVar3;
  }
  if (iVar1 != 9) {
    if (iVar1 != 0xb) {
      return 0;
    }
    uVar4 = *(undefined4 *)(param_1 + 0x20);
    goto LAB_008ca6a4;
  }
  iVar3 = *(int *)(param_1 + 0x1c) * *(int *)(param_1 + 0x18);
  uVar4 = 3;
  switch(*(undefined4 *)(param_1 + 0x14)) {
  case 0:
    uVar4 = 0;
    break;
  case 1:
  case 2:
  case 3:
  case 4:
    uVar4 = 1;
    break;
  case 5:
  case 6:
  case 7:
  case 8:
    uVar4 = 2;
    goto LAB_008ca6e1;
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
    uVar4 = 5;
    break;
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x1d:
    uVar4 = 4;
LAB_008ca6e1:
  }
  if (iVar3 != 0) {
    iVar1 = iVar3;
    do {
      *param_2 = uVar4;
      param_2 = param_2 + 4;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return iVar3;
}


// ==== FUN_008ca7a1 @ 0x008ca7a1 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008ca7a1(double *param_1,int *param_2)

{
  double dVar1;
  int iVar2;
  
  iVar2 = *param_2;
  if (iVar2 == 0) {
    if (param_2[2] == 0) {
      dVar1 = 0.0;
    }
    else {
      dVar1 = 1.0;
    }
    *param_1 = dVar1;
  }
  else {
    if (iVar2 == 1) {
      dVar1 = (double)param_2[2];
    }
    else if (iVar2 == 2) {
      dVar1 = (double)param_2[2];
      if (param_2[2] < 0) {
        dVar1 = dVar1 + _DAT_009c2f50;
      }
    }
    else {
      if (iVar2 != 3) {
        return 0x80004005;
      }
      dVar1 = *(double *)(param_2 + 2);
    }
    *param_1 = dVar1;
  }
  return 0;
}


// ==== FUN_008ca7ff @ 0x008ca7ff ====

bool FUN_008ca7ff(int param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  
  while( true ) {
    while( true ) {
      if (param_1 == 0) {
        return false;
      }
      iVar2 = *(int *)(param_1 + 4);
      if (iVar2 != 1) break;
      iVar2 = FUN_008ca7ff(*(undefined4 *)(param_1 + 8));
      if (iVar2 != 0) {
        return true;
      }
      param_1 = *(int *)(param_1 + 0xc);
    }
    if (iVar2 == 0xe) {
      return *(int *)(param_1 + 0x10) != 6;
    }
    if (iVar2 != 0xd) {
      return false;
    }
    iVar2 = *(int *)(param_1 + 0x1c);
    if (0x17 < iVar2) break;
    if (iVar2 < 0x16) {
      if (iVar2 < 0) {
        return true;
      }
      if (1 < iVar2) {
        if (iVar2 < 0x14) {
          return true;
        }
        bVar4 = SBORROW4(iVar2,0x15);
        iVar1 = iVar2 + -0x15;
        bVar3 = iVar2 == 0x15;
        goto LAB_008ca86c;
      }
    }
    param_1 = *(int *)(param_1 + 0x20);
  }
  if (iVar2 < 0x19) {
    return true;
  }
  bVar4 = SBORROW4(iVar2,0x1a);
  iVar1 = iVar2 + -0x1a;
  bVar3 = iVar2 == 0x1a;
LAB_008ca86c:
  if (bVar3 || bVar4 != iVar1 < 0) {
    return false;
  }
  return true;
}


// ==== FUN_008ca87b @ 0x008ca87b ====

bool FUN_008ca87b(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  while( true ) {
    while( true ) {
      if (param_1 == 0) {
        return true;
      }
      iVar1 = *(int *)(param_1 + 4);
      if (iVar1 != 1) break;
      iVar1 = FUN_008ca87b(*(undefined4 *)(param_1 + 8));
      if (iVar1 == 0) {
        return false;
      }
      param_1 = *(int *)(param_1 + 0xc);
    }
    if (iVar1 == 0xe) {
      return *(int *)(param_1 + 0x10) != 6;
    }
    if (iVar1 != 0xd) {
      return true;
    }
    iVar1 = *(int *)(param_1 + 0x1c);
    if (iVar1 < 0x14) break;
    if (iVar1 < 0x16) {
      return false;
    }
    if (iVar1 == 0x19) {
      return false;
    }
    if (iVar1 == 0x1a) {
      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0x18);
      if (iVar1 < 0x47) {
        if (0x43 < iVar1) {
          return false;
        }
        if (iVar1 == 9) {
          return false;
        }
        if (iVar1 == 0x1a) {
          return false;
        }
        if (iVar1 == 0x28) {
          return false;
        }
        if (iVar1 == 0x3d) {
          return false;
        }
      }
      else if (0x48 < iVar1) {
        if (iVar1 < 0x4c) {
          return false;
        }
        if (0x4d < iVar1) {
          if (iVar1 < 0x51) {
            return false;
          }
          if ((0x52 < iVar1) && (iVar1 < 0x56)) {
            return false;
          }
        }
      }
      iVar1 = FUN_008ca87b(*(undefined4 *)(*(int *)(param_1 + 0x24) + 8));
      if (iVar1 == 0) {
        return false;
      }
      uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x24) + 0xc);
      goto LAB_008ca981;
    }
    if (iVar1 != 0x1b) break;
    iVar1 = *(int *)(param_1 + 0x24);
    if (iVar1 == 0) {
      return false;
    }
    if (*(int *)(iVar1 + 4) != 0xd) {
      return false;
    }
    param_1 = *(int *)(iVar1 + 0x24);
  }
  iVar1 = FUN_008ca87b(*(undefined4 *)(param_1 + 0x20));
  if (iVar1 == 0) {
    return false;
  }
  uVar2 = *(undefined4 *)(param_1 + 0x24);
LAB_008ca981:
  iVar1 = FUN_008ca87b(uVar2);
  if (iVar1 == 0) {
    return false;
  }
  return true;
}


// ==== FUN_008ca999 @ 0x008ca999 ====

void FUN_008ca999(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 4) == 0xd)) {
    iVar1 = *(int *)(param_1 + 0x10);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    else {
      if (*(int *)(iVar1 + 4) == 9) {
        *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar1 + 0x18);
        uVar2 = *(undefined4 *)(iVar1 + 0x1c);
      }
      else {
        *(undefined4 *)(param_1 + 0x14) = 1;
        uVar2 = FUN_008c9f5e(iVar1);
      }
      *(undefined4 *)(param_1 + 0x18) = uVar2;
    }
  }
  return;
}


// ==== FUN_008ca9e1 @ 0x008ca9e1 ====

int FUN_008ca9e1(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_008bf738(0x24);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f3da4();
  }
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0;
    if (param_1 != (int *)0x0) {
      iVar2 = (**(code **)(*param_1 + 4))();
      *(int *)(iVar1 + 0x14) = iVar2;
      if (iVar2 == 0) {
        return 0;
      }
    }
    iVar2 = FUN_008bf738(0x14);
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_008f3584(iVar1,0,s_Stmts_00a1fda0);
    }
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  return 0;
}


// ==== FUN_008caa43 @ 0x008caa43 ====

int FUN_008caa43(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x18) != 0) {
    iVar1 = FUN_008bf738(0x24);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_008f3da4();
    }
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x10) = 6;
      iVar2 = FUN_008bf738(0x50);
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_008f3e67(0,0,0,0,1,in_ECX + 0x20);
      }
      if (iVar2 != 0) {
        *(int *)(iVar1 + 0x18) = iVar2;
        iVar2 = FUN_008bf738(0x14);
        if (iVar2 == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = FUN_008f3584(iVar1,0,s_Stmts_00a1fda0);
        }
        if (iVar1 != 0) {
          return iVar1;
        }
      }
    }
  }
  return 0;
}


// ==== FUN_008caac6 @ 0x008caac6 ====

int FUN_008caac6(int *param_1,int *param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 in_ECX;
  
  if ((param_2 != (int *)0x0) &&
     ((param_2[6] * param_2[5] != 1 || (iVar1 = FUN_008c9ee7(param_2[4]), iVar1 == 0)))) {
    FUN_008c98fa(in_ECX,param_2 + 0xc,0xbcb,s_float_expected_00a20024);
    return 0;
  }
  iVar1 = FUN_008bf738(0x24);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f3da4();
  }
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(iVar1 + 0x10) = 3;
  if (param_3 == 0) {
    if (param_1 == (int *)0x0) {
      *(undefined4 *)(iVar1 + 0x10) = 4;
      goto LAB_008cab71;
    }
    if (param_1 == param_4) {
      *(undefined4 *)(iVar1 + 0x10) = 5;
      param_1 = (int *)0x0;
    }
  }
  if (param_1 != (int *)0x0) {
    iVar2 = (**(code **)(*param_1 + 4))();
    *(int *)(iVar1 + 0x14) = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
  }
LAB_008cab71:
  if (param_2 != (int *)0x0) {
    iVar2 = (**(code **)(*param_2 + 4))();
    *(int *)(iVar1 + 0x18) = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
  }
  if (param_4 != (int *)0x0) {
    iVar2 = (**(code **)(*param_4 + 4))();
    *(int *)(iVar1 + 0x1c) = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
  }
  if (param_3 != 0) {
    iVar2 = FUN_008ca9e1(param_3);
    if (iVar2 == 0) {
      return 0;
    }
    uVar3 = FUN_008f3545(*(undefined4 *)(iVar1 + 0x1c),iVar2);
    *(undefined4 *)(iVar1 + 0x1c) = uVar3;
  }
  iVar2 = FUN_008bf738(0x14);
  if (iVar2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f3584(iVar1,0,s_Stmts_00a1fda0);
  }
  if (iVar1 == 0) {
    return 0;
  }
  return iVar1;
}


// ==== FUN_008cabe1 @ 0x008cabe1 ====

undefined4 FUN_008cabe1(void)

{
  FUN_008be4a1(1);
  FUN_008c19ba();
  return 0;
}


// ==== FUN_008cabfc @ 0x008cabfc ====

void FUN_008cabfc(int param_1)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint *in_ECX;
  uint uVar6;
  undefined4 *puVar7;
  int *local_c;
  void *local_8;
  
  local_c = (int *)0x0;
  local_8 = (void *)0x0;
  FUN_009060fc();
  if (param_1 == 0) {
LAB_008cac48:
    iVar2 = FUN_0090934e(in_ECX[1],*in_ECX & 0xc3,local_8,&local_c);
    if (-1 < iVar2) {
      uVar3 = (**(code **)(*local_c + 0x10))(local_c);
      puVar4 = (undefined4 *)FUN_008f33e7(uVar3,1);
      if (puVar4 != (undefined4 *)0x0) {
        puVar5 = (undefined4 *)(**(code **)(*local_c + 0xc))(local_c);
        puVar7 = puVar4;
        for (uVar6 = uVar3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar7 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar7 = puVar7 + 1;
        }
        for (uVar6 = uVar3 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined1 *)puVar7 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        if (local_c != (int *)0x0) {
          (**(code **)(*local_c + 8))(local_c);
          local_c = (int *)0x0;
        }
        iVar2 = FUN_008bf738(0x38);
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = FUN_008f415d(in_ECX + 8,puVar4,uVar3);
        }
        if (iVar2 != 0) {
          _free(local_8);
          return;
        }
        FUN_0090878b();
        goto LAB_008cacf7;
      }
    }
  }
  else {
    pvVar1 = operator_new(8);
    if (pvVar1 == (void *)0x0) {
      local_8 = (void *)0x0;
    }
    else {
      local_8 = (void *)FUN_00909806(in_ECX,in_ECX[4]);
    }
    if (local_8 != (void *)0x0) goto LAB_008cac48;
  }
  FUN_0090878b();
LAB_008cacf7:
  in_ECX[0x10] = 1;
  _free(local_8);
  return;
}


// ==== FUN_008cad35 @ 0x008cad35 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_008cad35(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  int local_1c;
  char local_18 [15];
  undefined1 local_9;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  if ((((param_1 != 0) && (*(int *)(param_1 + 4) == 3)) && (*(int *)(param_1 + 0x10) == 2)) &&
     (((param_2 != 0 && (*(int *)(param_2 + 4) == 3)) && (*(int *)(param_2 + 0x10) == 9)))) {
    iVar4 = FUN_008bf738(0x30);
    if (iVar4 == 0) {
      local_1c = 0;
    }
    else {
      local_1c = FUN_008f378b((int *)(param_2 + 0x10));
    }
    if (local_1c != 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x18);
      pcVar3 = *(char **)(param_2 + 0x18);
      __snprintf(local_18,0x10,&DAT_00a16908,uVar2);
      pcVar5 = local_18;
      local_9 = 0;
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      pcVar6 = pcVar3;
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      pcVar5 = pcVar5 + (int)(pcVar6 + ((1 - (int)(pcVar3 + 1)) - (int)(local_18 + 1)));
      pcVar6 = (char *)FUN_008f33e7(pcVar5,1);
      if (pcVar6 != (char *)0x0) {
        __snprintf(pcVar6,(size_t)pcVar5,&DAT_00a20034,uVar2,pcVar3);
        pcVar6[(int)(pcVar5 + -1)] = '\0';
        *(char **)(local_1c + 0x18) = pcVar6;
        return local_1c;
      }
    }
  }
  return 0;
}


// ==== FUN_008cae34 @ 0x008cae34 ====

int FUN_008cae34(int param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  
  iVar4 = param_1;
  if ((((param_1 != 0) && (*(int *)(param_1 + 4) == 3)) && (*(int *)(param_1 + 0x10) == 10)) &&
     (((param_2 != 0 && (*(int *)(param_2 + 4) == 3)) && (*(int *)(param_2 + 0x10) == 10)))) {
    iVar5 = FUN_008bf738(0x30);
    if (iVar5 == 0) {
      param_1 = 0;
    }
    else {
      param_1 = FUN_008f378b((int *)(param_1 + 0x10));
    }
    if (param_1 != 0) {
      pcVar2 = *(char **)(iVar4 + 0x18);
      pcVar3 = *(char **)(param_2 + 0x18);
      pcVar6 = pcVar2;
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      pcVar7 = pcVar3;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      pcVar6 = pcVar6 + (int)(pcVar7 + ((1 - (int)(pcVar3 + 1)) - (int)(pcVar2 + 1)));
      pcVar7 = (char *)FUN_008f33e7(pcVar6,1);
      if (pcVar7 != (char *)0x0) {
        __snprintf(pcVar7,(size_t)pcVar6,&DAT_009ff01c,pcVar2,pcVar3);
        pcVar7[(int)(pcVar6 + -1)] = '\0';
        *(char **)(param_1 + 0x18) = pcVar7;
        return param_1;
      }
    }
  }
  return 0;
}


// ==== FUN_008caf04 @ 0x008caf04 ====

void FUN_008caf04(int param_1)

{
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x20)) {
    if (*(int *)(param_1 + 0x10) == 1) {
      FUN_008c98fa();
    }
  }
  return;
}


// ==== FUN_008caf3c @ 0x008caf3c ====

int FUN_008caf3c(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  iVar1 = *(int *)(in_ECX + 0x10);
  if (iVar1 == 0) {
    FUN_008c99bd();
    return -0x7fffbffb;
  }
  if (((*(int *)(iVar1 + 0x10) == 4) && (*(int *)(iVar1 + 0x20) != 0)) &&
     (*(int *)(*(int *)(iVar1 + 0x20) + 0x10) != 4)) {
    for (piVar2 = (int *)(iVar1 + 0x18); *piVar2 != 0; piVar2 = (int *)(*piVar2 + 0xc)) {
      *(undefined4 *)(*(int *)(*piVar2 + 8) + 0x2c) = 1;
      iVar1 = FUN_008c9abe(*(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x20),
                           *(undefined4 *)(*piVar2 + 8));
      if (iVar1 < 0) {
        return iVar1;
      }
    }
    *piVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 0x10) + 0x20) + 0x18);
    *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x10) + 0x20) + 0x18) =
         *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x18);
    *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x18) = 0;
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(iVar1 + 0x20);
  *(undefined4 *)(iVar1 + 0x20) = 0;
  return 0;
}


// ==== FUN_008cafd3 @ 0x008cafd3 ====

int FUN_008cafd3(int param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  if (*(int *)(in_ECX + 0x10) == 0) {
    FUN_008c99bd();
    iVar1 = -0x7fffbffb;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x14) + 0x10;
    for (iVar1 = FUN_008c9bf1(iVar2,*(int *)(in_ECX + 0x10)); iVar1 != 0;
        iVar1 = *(int *)(iVar1 + 0xc)) {
      if ((*(int *)(*(int *)(iVar1 + 8) + 0x2c) == 0) &&
         ((*(int *)(param_1 + 0x10) != 2 || (*(int *)(*(int *)(iVar1 + 8) + 0x10) != 2)))) {
        if ((param_2 != 0) && (iVar1 = FUN_008f350b(param_1,*(undefined4 *)(iVar1 + 8)), iVar1 != 0)
           ) {
          return 0;
        }
        goto LAB_008cb05e;
      }
    }
    iVar1 = *(int *)(*(int *)(in_ECX + 0x10) + 0x20);
    if ((((iVar1 == 0) || (*(int *)(*(int *)(in_ECX + 0x10) + 0x10) != 3)) ||
        (*(int *)(iVar1 + 0x10) != 2)) || (iVar1 = FUN_008c9bf1(iVar2,iVar1), iVar1 == 0)) {
      iVar1 = FUN_008bf738(0x14);
      iVar2 = 0;
      if (iVar1 != 0) {
        iVar2 = FUN_008f3584(0,0,s_Stmts_00a1fda0);
      }
      if (iVar2 != 0) {
        iVar1 = FUN_008f352c(param_1);
        *(int *)(iVar2 + 8) = iVar1;
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x14);
          *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(*(int *)(iVar2 + 8) + 0x20);
          *(undefined4 *)(*(int *)(iVar2 + 8) + 0x24) = *(undefined4 *)(in_ECX + 0x4c);
          *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(*(int *)(iVar2 + 8) + 0x24);
          *(int *)(in_ECX + 0x4c) = *(int *)(in_ECX + 0x4c) + 1;
          *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x18);
          *(int *)(*(int *)(in_ECX + 0x10) + 0x18) = iVar2;
          iVar1 = FUN_008c9abe(*(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(iVar2 + 8));
          if (iVar1 < 0) {
            return iVar1;
          }
          return 0;
        }
      }
      iVar1 = -0x7ff8fff2;
    }
    else {
LAB_008cb05e:
      FUN_008c98fa();
      iVar1 = -0x7fffbffb;
    }
  }
  return iVar1;
}


// ==== FUN_008cb11d @ 0x008cb11d ====

undefined4 FUN_008cb11d(int param_1,int *param_2,uint *param_3,int *param_4)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  byte *pbVar13;
  byte *pbVar14;
  undefined4 *puVar15;
  undefined **ppuVar16;
  bool bVar17;
  uint local_14c [10];
  int local_124 [29];
  undefined1 local_b0 [20];
  undefined4 local_9c;
  undefined1 local_8c [20];
  uint local_78;
  int aiStack_68 [5];
  uint local_54 [16];
  uint local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  if (param_3 != (uint *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
  }
  uVar10 = 0;
  iVar9 = (int)param_2;
  if (param_2 != (int *)0x0) {
    do {
      iVar6 = *(int *)(iVar9 + 8);
      if ((((iVar6 == 0) || (*(int *)(iVar6 + 4) != 0xd)) || (*(int *)(iVar6 + 0x10) == 0)) ||
         (*(int *)(*(int *)(iVar6 + 0x10) + 4) != 9)) break;
      iVar9 = *(int *)(iVar9 + 0xc);
      uVar10 = uVar10 + 1;
    } while (iVar9 != 0);
    if ((iVar9 != 0) || (4 < uVar10)) {
      return 1;
    }
  }
  pbVar2 = *(byte **)(param_1 + 8);
  local_8 = 0x5e;
  uVar10 = 0;
  do {
    local_14 = local_8 + uVar10 >> 1;
    pbVar13 = (&PTR_s_D3DCOLORtoUBYTE4_00a1bedc)[local_14 * 0x29];
    pbVar14 = pbVar2;
    do {
      bVar1 = *pbVar14;
      bVar17 = bVar1 < *pbVar13;
      if (bVar1 != *pbVar13) {
LAB_008cb1c8:
        iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
        goto LAB_008cb1cd;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar14[1];
      bVar17 = bVar1 < pbVar13[1];
      if (bVar1 != pbVar13[1]) goto LAB_008cb1c8;
      pbVar14 = pbVar14 + 2;
      pbVar13 = pbVar13 + 2;
    } while (bVar1 != 0);
    iVar9 = 0;
LAB_008cb1cd:
    if (iVar9 < 1) {
      if (-1 < iVar9) {
        local_8 = local_14 + 1;
        if (local_14 == 0) goto LAB_008cb238;
        puVar15 = (undefined4 *)(local_14 * 0xa4 + 0xa1be38);
        goto LAB_008cb1fd;
      }
      local_8 = local_14;
    }
    else {
      uVar10 = local_14 + 1;
    }
    local_14 = uVar10;
    uVar10 = local_14;
  } while (local_14 < local_8);
  goto LAB_008cb28b;
  while( true ) {
    local_14 = local_14 - 1;
    puVar15 = puVar15 + -0x29;
    if (local_14 == 0) break;
LAB_008cb1fd:
    pbVar13 = (byte *)*puVar15;
    pbVar14 = pbVar2;
    do {
      bVar1 = *pbVar14;
      bVar17 = bVar1 < *pbVar13;
      if (bVar1 != *pbVar13) {
LAB_008cb224:
        iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
        goto LAB_008cb229;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar14[1];
      bVar17 = bVar1 < pbVar13[1];
      if (bVar1 != pbVar13[1]) goto LAB_008cb224;
      pbVar14 = pbVar14 + 2;
      pbVar13 = pbVar13 + 2;
    } while (bVar1 != 0);
    iVar9 = 0;
LAB_008cb229:
    if (iVar9 != 0) break;
  }
LAB_008cb238:
  if (local_8 < 0x5e) {
    ppuVar16 = &PTR_s_D3DCOLORtoUBYTE4_00a1bedc + local_8 * 0x29;
    do {
      pbVar13 = *ppuVar16;
      pbVar14 = pbVar2;
      do {
        bVar1 = *pbVar14;
        bVar17 = bVar1 < *pbVar13;
        if (bVar1 != *pbVar13) {
LAB_008cb273:
          iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
          goto LAB_008cb278;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar14[1];
        bVar17 = bVar1 < pbVar13[1];
        if (bVar1 != pbVar13[1]) goto LAB_008cb273;
        pbVar14 = pbVar14 + 2;
        pbVar13 = pbVar13 + 2;
      } while (bVar1 != 0);
      iVar9 = 0;
LAB_008cb278:
      if (iVar9 != 0) break;
      local_8 = local_8 + 1;
      ppuVar16 = ppuVar16 + 0x29;
    } while (local_8 < 0x5e);
  }
LAB_008cb28b:
  if (local_14 == local_8) {
    return 1;
  }
  if (local_14 < local_8) {
    local_10 = (int *)(&DAT_00a1bed8 + local_14 * 0xa4);
    do {
      piVar12 = local_10;
      local_54[0] = 0xffffffff;
      local_54[1] = 0xffffffff;
      local_54[2] = 0xffffffff;
      local_54[3] = 0xffffffff;
      local_54[4] = 0xffffffff;
      local_54[10] = 0x1e;
      local_54[0xb] = 0x1e;
      local_54[0xc] = 0x1e;
      local_54[0xd] = 0x1e;
      local_54[0xe] = 0x1e;
      local_54[5] = 5;
      local_54[6] = 5;
      local_54[7] = 5;
      local_54[8] = 5;
      local_54[9] = 5;
      FUN_008f3b16();
      FUN_008f3b16();
      local_c = 1;
      if (param_2 == (int *)0x0) {
LAB_008cb43b:
        if (piVar12[2] != 0) {
          if (local_54[piVar12[3] + 5] == 5) {
            local_54[piVar12[3] + 5] = *(uint *)piVar12[4];
          }
          if (local_54[piVar12[5] + 10] == 0x1e) {
            local_54[piVar12[5] + 10] = *(uint *)piVar12[6];
          }
        }
        local_c = 0;
        piVar12 = local_10 + 6;
        do {
          puVar7 = (uint *)piVar12[-2];
          puVar8 = local_54 + local_c + 5;
          uVar10 = *puVar8;
          if (uVar10 == 5) {
            if (puVar7 != (uint *)0x0) {
              *puVar8 = *puVar7;
            }
          }
          else {
            if ((uVar10 == 0) && ((uVar3 = *puVar7, uVar3 == 1 || (uVar3 == 2)))) {
              *puVar8 = uVar3;
            }
            else {
              for (; (*puVar7 != 5 && (uVar10 != *puVar7)); puVar7 = puVar7 + 1) {
              }
            }
            if (*puVar7 == 5) break;
          }
          puVar8 = (uint *)*piVar12;
          uVar10 = local_54[local_c + 10];
          puVar7 = puVar8;
          if (uVar10 == 0x1e) {
            if (puVar8 != (uint *)0x0) {
              uVar10 = *puVar8;
LAB_008cb4cb:
              local_54[local_c + 10] = uVar10;
            }
          }
          else {
            for (; (*puVar7 != 0x1e && (uVar10 != *puVar7)); puVar7 = puVar7 + 1) {
            }
            if (*puVar7 == 0x1e) {
              uVar10 = *puVar8;
              goto LAB_008cb4cb;
            }
          }
          if (local_54[local_c] == 0xffffffff) {
            local_54[local_c] = 1;
          }
          local_c = local_c + 1;
          piVar12 = piVar12 + 8;
        } while (local_c < 5);
        if (local_c == 5) break;
      }
      else {
        piVar12 = piVar12 + 0xb;
        iVar9 = (int)param_2;
        do {
          if ((4 < local_c) || (piVar12[-2] == 0)) break;
          iVar6 = *(int *)(*(int *)(iVar9 + 8) + 0x10);
          uVar10 = local_54[*piVar12 + 5];
          if ((uVar10 == 5) ||
             ((uVar10 == 0 && ((*(int *)(iVar6 + 0x10) == 1 || (*(int *)(iVar6 + 0x10) == 2)))))) {
            iVar5 = *piVar12;
            local_54[iVar5 + 5] = *(uint *)(iVar6 + 0x10);
            aiStack_68[iVar5] = piVar12[1];
          }
          else {
            if (*(uint *)(iVar6 + 0x10) == 0) {
              if ((uVar10 == 0) || (uVar10 == 1)) goto LAB_008cb363;
              bVar17 = uVar10 == 2;
            }
            else {
              bVar17 = *(uint *)(iVar6 + 0x10) == uVar10;
            }
            if (!bVar17) break;
          }
LAB_008cb363:
          iVar5 = piVar12[2];
          if (local_54[iVar5 + 10] == 0x1e) {
            local_54[iVar5 + 10] = *(uint *)(iVar6 + 0x14);
            aiStack_68[iVar5] = piVar12[3];
          }
          else {
            local_78 = local_54[iVar5 + 10];
            local_9c = *(undefined4 *)(iVar6 + 0x14);
            iVar5 = FUN_008ca464(local_8c,local_b0,local_54 + piVar12[2] + 10);
            if (iVar5 < 0) break;
          }
          iVar5 = *(int *)(iVar6 + 0x10);
          if (iVar5 != 0) {
            uVar10 = piVar12[4];
            if ((int)uVar10 < 0) {
              if (*(uint *)(iVar6 + 0x18) < local_54[~uVar10]) {
                local_54[~uVar10] = *(uint *)(iVar6 + 0x18);
              }
            }
            else if (*(uint *)(iVar6 + 0x18) < uVar10) break;
            if (iVar5 != 0) {
              uVar10 = piVar12[5];
              if ((int)uVar10 < 0) {
                if (*(uint *)(iVar6 + 0x1c) < local_54[~uVar10]) {
                  local_54[~uVar10] = *(uint *)(iVar6 + 0x1c);
                }
              }
              else if (*(uint *)(iVar6 + 0x1c) < uVar10) break;
            }
          }
          if (((*(byte *)(piVar12 + -1) & 0x20) != 0) && (iVar6 = FUN_008c9e50(iVar6), iVar6 != 0))
          break;
          iVar9 = *(int *)(iVar9 + 0xc);
          local_c = local_c + 1;
          piVar12 = piVar12 + 8;
        } while (iVar9 != 0);
        if ((iVar9 == 0) && ((piVar12 = local_10, 4 < local_c || (local_10[local_c * 8 + 1] == 0))))
        goto LAB_008cb43b;
      }
      local_14 = local_14 + 1;
      local_10 = local_10 + 0x29;
    } while (local_14 < local_8);
  }
  if (local_14 == local_8) {
    return 1;
  }
  if (param_3 != (uint *)0x0) {
    iVar9 = 5;
    do {
      FUN_008f3b16();
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    uVar10 = 0;
    iVar9 = local_14 * 0xa4;
    puVar8 = local_14c;
    puVar7 = (uint *)(iVar9 + 0xa1bef4);
    do {
      if (puVar7[-6] == 0) break;
      uVar3 = puVar7[-5];
      if (uVar3 != 0) {
        puVar8[-2] = local_54[puVar7[-4] + 5];
        puVar8[-1] = local_54[puVar7[-2] + 10];
        uVar11 = *puVar7;
        if ((int)uVar11 < 0) {
          uVar11 = local_54[~uVar11];
        }
        *puVar8 = uVar11;
        uVar11 = puVar7[1];
        if ((int)uVar11 < 0) {
          uVar11 = local_54[~uVar11];
        }
        puVar8[1] = uVar11;
        puVar8[2] = uVar3 & 0xc00;
        if ((uVar10 == 0) || ((uVar3 & 0x20) == 0)) {
          puVar8[2] = uVar3 & 0xc00 | 0x200;
        }
      }
      uVar10 = uVar10 + 1;
      puVar7 = puVar7 + 8;
      puVar8 = puVar8 + 9;
    } while (uVar10 < 5);
    iVar6 = FUN_008bf738(0x40);
    if (iVar6 == 0) {
      local_8 = 0;
    }
    else {
      local_8 = FUN_008f3bba();
    }
    uVar10 = local_8;
    if (local_8 == 0) {
      return 0x8007000e;
    }
    if (*(int *)(iVar9 + 0xa1bee0) != 0) {
      iVar6 = FUN_008f456a();
      *(int *)(uVar10 + 0x20) = iVar6;
      if (iVar6 == 0) {
        return 0x8007000e;
      }
    }
    local_10 = (int *)(uVar10 + 0x24);
    param_2 = (int *)(iVar9 + 0xa1befc);
    local_c = 1;
    piVar12 = local_124;
    do {
      piVar4 = local_10;
      if (*param_2 == 0) break;
      iVar9 = FUN_008bf738(0x14);
      if (iVar9 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = FUN_008f3584(0,0,s_Decls_00a200ec);
      }
      *piVar4 = iVar9;
      if (iVar9 == 0) {
        return 0x8007000e;
      }
      iVar9 = FUN_008bf738(0x30);
      if (iVar9 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = FUN_008f3958(1,0,0,0);
      }
      if (iVar9 == 0) {
        return 0x8007000e;
      }
      *(int *)(*local_10 + 8) = iVar9;
      iVar6 = FUN_008bf738(0x30);
      if (iVar6 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_008f378b(param_1);
      }
      *(int *)(iVar9 + 0x14) = iVar6;
      if (iVar6 == 0) {
        return 0x8007000e;
      }
      *(int *)(iVar6 + 0x18) = *param_2;
      iVar6 = FUN_008bf738(0x40);
      if (iVar6 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_008f3cb2();
      }
      if (iVar6 == 0) {
        return 0x8007000e;
      }
      *(int *)(iVar9 + 0x18) = iVar6;
      *(undefined4 *)(iVar6 + 0x10) = 0xffffffff;
      *(int *)(iVar6 + 0x14) = piVar12[-1] * *piVar12;
      *(undefined4 *)(iVar6 + 0x18) = 2;
      *(int *)(iVar6 + 0x1c) = param_2[1];
      iVar9 = FUN_008f456a();
      *(int *)(iVar6 + 0x20) = iVar9;
      if (iVar9 == 0) {
        return 0x8007000e;
      }
      param_2 = param_2 + 8;
      local_10 = (int *)(*local_10 + 0xc);
      local_c = local_c + 1;
      piVar12 = piVar12 + 9;
    } while (local_c < 5);
    *param_3 = local_8;
  }
  uVar10 = local_14;
  iVar9 = 0;
  if (param_4 == (int *)0x0) {
    return 0;
  }
  iVar6 = FUN_008bf738(0x14);
  if (iVar6 != 0) {
    iVar9 = FUN_008f3584(0,0,s_Values_00a200e4);
  }
  if (iVar9 != 0) {
    iVar6 = FUN_008bf738(0x40);
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_008f3fb4(2,*(undefined4 *)(&DAT_00a1bed8 + uVar10 * 0xa4),param_1);
    }
    *(int *)(iVar9 + 8) = iVar6;
    if (iVar6 != 0) {
      *param_4 = iVar9;
      return 0;
    }
  }
  return 0x8007000e;
}


// ==== FUN_008cb7d5 @ 0x008cb7d5 ====

undefined4 FUN_008cb7d5(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  undefined8 uVar7;
  undefined1 local_20 [4];
  int local_1c;
  undefined1 local_14 [4];
  int local_10;
  
  if ((param_2 == 0) != (*(int *)(param_1 + 0x1c) == 0)) {
    return 0xffffffff;
  }
  if (param_2 != 0) {
    iVar3 = FUN_008f31ff(*(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x18),0,local_14);
    if ((iVar3 < 0) || (iVar3 = FUN_008f31ff(*(undefined4 *)(param_2 + 0x18),0,local_20), iVar3 < 0)
       ) {
      pbVar5 = *(byte **)(*(int *)(param_1 + 0x1c) + 0x18);
      pbVar4 = *(byte **)(param_2 + 0x18);
      do {
        bVar1 = *pbVar4;
        bVar6 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_008cb868:
          iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_008cb86d;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar4[1];
        bVar6 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_008cb868;
        pbVar4 = pbVar4 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_008cb86d:
      if (iVar3 != 0) {
        return 0xffffffff;
      }
    }
    else if (local_10 != local_1c) {
      return 0xffffffff;
    }
  }
  iVar3 = *(int *)(param_1 + 0x24);
  do {
    if (iVar3 == 0) {
LAB_008cb8d5:
      if (param_3 == 0) {
        return 0;
      }
      return 0xffffffff;
    }
    if (param_3 == 0) {
      if (iVar3 != 0) {
        return 0xffffffff;
      }
      goto LAB_008cb8d5;
    }
    iVar3 = *(int *)(*(int *)(iVar3 + 8) + 0x18);
    iVar2 = *(int *)(*(int *)(param_3 + 8) + 0x18);
    if (*(int *)(iVar3 + 0x1c) != *(int *)(iVar2 + 0x1c)) {
      return 0xffffffff;
    }
    uVar7 = FUN_008c9fec(*(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar2 + 0x20));
    iVar3 = (int)((ulonglong)uVar7 >> 0x20);
    if ((int)uVar7 == 0) {
      return 0xffffffff;
    }
    do {
      iVar3 = *(int *)(iVar3 + 0xc);
      if (iVar3 == 0) break;
    } while (*(int *)(*(int *)(iVar3 + 8) + 4) != 6);
    do {
      param_3 = *(int *)(param_3 + 0xc);
      if (param_3 == 0) break;
    } while (*(int *)(*(int *)(param_3 + 8) + 4) != 6);
  } while( true );
}


// ==== FUN_008cb8e4 @ 0x008cb8e4 ====

int FUN_008cb8e4(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_60 [20];
  undefined4 local_4c;
  undefined1 local_3c [20];
  undefined4 local_28;
  int local_18;
  undefined4 local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  uVar3 = 0;
  local_18 = 0;
  local_c = FUN_008c9f5e(param_1);
  local_10 = FUN_008c9f5e(param_2);
  iVar2 = FUN_008c9fec(param_1,param_2);
  if (iVar2 == 0) {
    bVar1 = false;
    local_8 = 0;
    FUN_008f3b16();
    FUN_008f3b16();
    if (local_c != 0) {
      while (uVar3 < local_10) {
        iVar2 = FUN_008ca399(param_1,uVar3,local_3c);
        if (((iVar2 < 0) || (iVar2 = FUN_008ca399(param_2,uVar3,local_60), iVar2 < 0)) ||
           (iVar2 = FUN_008ca464(local_3c,local_60,&local_14), iVar2 < 0)) {
          bVar1 = true;
          local_8 = 1;
        }
        else {
          iVar2 = FUN_008c9c55(local_28,local_14);
          if (iVar2 != 0) {
            bVar1 = true;
          }
          iVar2 = FUN_008c9c55(local_14,local_4c);
          if (iVar2 != 0) {
            local_8 = 1;
          }
        }
        if (((bVar1) && (local_8 != 0)) || (uVar3 = uVar3 + 1, local_c <= uVar3)) break;
      }
    }
    if (local_10 < local_c) {
      local_18 = 4;
    }
    if (bVar1) {
      local_18 = local_18 + 0x200;
    }
    if (local_8 != 0) {
      local_18 = local_18 + 0x10000;
    }
    if (local_c < local_10) {
      local_18 = local_18 + 0x800000;
    }
  }
  else {
    local_18 = 0;
  }
  return local_18;
}


// ==== FUN_008cba07 @ 0x008cba07 ====

undefined4 FUN_008cba07(int param_1,int param_2)

{
  uint *in_ECX;
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if ((uVar1 & 0x200) != 0) {
    FUN_008c9d2e(param_2,1);
  }
  if (((param_2 == 0) || (*(int *)(param_2 + 4) != 9)) || (*(int *)(param_2 + 0x10) != 2)) {
    if ((uVar1 & 0xc00) != 0) {
      FUN_008c98fa();
      return 0x80004005;
    }
  }
  else {
    if ((uVar1 & 0xc00) == 0) {
      uVar1 = uVar1 | *(uint *)(in_ECX[1] + 0x38);
    }
    if ((uVar1 & 0xc00) == 0) {
      if ((*in_ECX & 8) == 0) {
        if ((*in_ECX & 0x10) != 0) {
          uVar1 = uVar1 | 0x800;
        }
      }
      else {
        uVar1 = uVar1 | 0x400;
      }
    }
    if ((uVar1 & 0x400) != 0) {
      *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffff7ff | 0x400;
    }
    if ((uVar1 & 0x800) != 0) {
      *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffbff | 0x800;
    }
  }
  return 0;
}


// ==== FUN_008cbaba @ 0x008cbaba ====

undefined4 FUN_008cbaba(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined1 *puVar6;
  bool bVar7;
  undefined1 local_50 [16];
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_2c [16];
  undefined4 local_1c;
  undefined4 local_14;
  undefined4 local_10;
  
  if (param_3 == 0) {
    if (param_1 == (undefined1 *)0x0) {
      if (param_2 == (undefined1 *)0x0) {
        return 1;
      }
      return 0;
    }
  }
  else if (param_1 == (undefined1 *)0x0) {
    return 1;
  }
  if (param_2 == (undefined1 *)0x0) {
    return 0;
  }
  FUN_008f3b16();
  FUN_008f3b16();
  if (*(int *)(param_1 + 4) == 9) {
    puVar6 = param_1;
  }
  else {
    puVar6 = local_50;
    local_40 = 4;
    local_38 = 1;
    local_34 = FUN_008c9f5e(param_1);
    if ((param_3 != 0) && (iVar2 = FUN_008c9ee7(param_1), iVar2 != 0)) {
      local_40 = 1;
    }
  }
  if (*(int *)(param_2 + 4) == 9) {
    puVar4 = param_2;
  }
  else {
    puVar4 = local_2c;
    local_1c = 4;
    local_14 = 1;
    local_10 = FUN_008c9f5e(param_2);
    if ((param_3 != 0) && (iVar2 = FUN_008c9ee7(param_2), iVar2 != 0)) {
      local_1c = 1;
    }
  }
  iVar2 = *(int *)(puVar6 + 0x10);
  if ((iVar2 == 4) || (iVar1 = *(int *)(puVar4 + 0x10), iVar1 == 4)) {
    uVar3 = *(int *)(puVar6 + 0x1c) * *(int *)(puVar6 + 0x18);
    if (param_3 == 0) {
      if (iVar2 != *(int *)(puVar4 + 0x10)) {
        return 0;
      }
      if (uVar3 != *(int *)(puVar4 + 0x1c) * *(int *)(puVar4 + 0x18)) {
        return 0;
      }
      uVar5 = 0;
      if (uVar3 == 0) {
        return 1;
      }
      do {
        iVar2 = FUN_008ca399(param_1,uVar5,local_50);
        if (iVar2 < 0) {
          return 0;
        }
        iVar2 = FUN_008ca399(param_2,uVar5,local_2c);
        if (iVar2 < 0) {
          return 0;
        }
        iVar2 = FUN_008c9fec(local_50,local_2c);
        if (iVar2 == 0) {
          return 0;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar3);
      return 1;
    }
    if ((uint)(*(int *)(puVar4 + 0x1c) * *(int *)(puVar4 + 0x18)) < uVar3) {
      return 0;
    }
    uVar5 = 0;
    if (uVar3 != 0) {
      do {
        iVar2 = FUN_008ca399(param_1,uVar5,local_50);
        if (iVar2 < 0) {
          return 0;
        }
        iVar2 = FUN_008ca399(param_2,uVar5,local_2c);
        if (iVar2 < 0) {
          return 0;
        }
        iVar2 = FUN_008cbaba(local_50,local_2c,1);
        if (iVar2 == 0) {
          return 0;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar3);
    }
    return 1;
  }
  if (iVar2 != 0) {
    if (iVar2 != 1) {
      if (iVar2 == 2) {
        if (iVar1 == 0) {
          return 1;
        }
        if (iVar1 != 1) {
          if (iVar1 == 2) {
            if (*(uint *)(puVar4 + 0x18) < *(uint *)(puVar6 + 0x18)) {
              return 0;
            }
            goto LAB_008cbc65;
          }
          goto joined_r0x008cbc79;
        }
        uVar3 = *(uint *)(puVar6 + 0x18);
        if ((uVar3 == 1) && (*(uint *)(puVar4 + 0x1c) < *(uint *)(puVar6 + 0x1c))) {
          return 0;
        }
        iVar2 = *(int *)(puVar6 + 0x1c);
        if ((iVar2 == 1) && (*(uint *)(puVar4 + 0x1c) < uVar3)) {
          return 0;
        }
        if (uVar3 == 1) {
          return 1;
        }
        if (iVar2 == 1) {
          return 1;
        }
        bVar7 = uVar3 * iVar2 == *(int *)(puVar4 + 0x1c);
      }
      else {
        if (iVar2 != 3) {
          return 1;
        }
        if (iVar1 != 3) {
          return 0;
        }
        iVar2 = *(int *)(puVar4 + 0x14);
        if (iVar2 == 0xd) {
          return 1;
        }
        if (iVar2 == 0xf) {
          iVar2 = *(int *)(puVar6 + 0x14);
          if (iVar2 == 0xf) {
            return 1;
          }
          if (iVar2 == 0x10) {
            return 1;
          }
          if (iVar2 == 0x11) {
            return 1;
          }
          if (iVar2 == 0x12) {
            return 1;
          }
          bVar7 = iVar2 == 0x13;
        }
        else if (iVar2 == 0x14) {
          iVar2 = *(int *)(puVar6 + 0x14);
          if (iVar2 == 0x14) {
            return 1;
          }
          if (iVar2 == 0x15) {
            return 1;
          }
          if (iVar2 == 0x16) {
            return 1;
          }
          if (iVar2 == 0x17) {
            return 1;
          }
          bVar7 = iVar2 == 0x18;
        }
        else {
          bVar7 = *(int *)(puVar6 + 0x14) == iVar2;
        }
      }
LAB_008cbd04:
      if (bVar7) {
        return 1;
      }
      return 0;
    }
    if (iVar1 == 0) {
      return 1;
    }
    if (iVar1 == 1) {
LAB_008cbc65:
      if (*(uint *)(puVar4 + 0x1c) < *(uint *)(puVar6 + 0x1c)) {
        return 0;
      }
      return 1;
    }
    if (iVar1 == 2) {
      uVar3 = *(uint *)(puVar4 + 0x18);
      if ((uVar3 == 1) && (*(uint *)(puVar4 + 0x1c) < *(uint *)(puVar6 + 0x1c))) {
        return 0;
      }
      iVar2 = *(int *)(puVar4 + 0x1c);
      if ((iVar2 == 1) && (uVar3 < *(uint *)(puVar6 + 0x1c))) {
        return 0;
      }
      if (uVar3 == 1) {
        return 1;
      }
      if (iVar2 == 1) {
        return 1;
      }
      bVar7 = uVar3 * iVar2 == *(int *)(puVar6 + 0x1c);
      goto LAB_008cbd04;
    }
  }
joined_r0x008cbc79:
  if (iVar1 == 3) {
    return 0;
  }
  return 1;
}


// ==== FUN_008cbdf2 @ 0x008cbdf2 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008cbdf2(undefined4 param_1,int param_2,undefined1 *param_3,undefined1 *param_4,int param_5
                 )

{
  int iVar1;
  int iVar2;
  undefined4 in_ECX;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  char *pcVar6;
  bool bVar7;
  undefined1 local_264 [16];
  undefined4 local_254;
  undefined4 local_24c;
  undefined4 local_248;
  undefined1 local_240 [16];
  undefined4 local_230;
  undefined4 local_228;
  undefined4 local_224;
  int local_21c;
  undefined4 local_218;
  undefined1 *local_214;
  undefined1 *local_210;
  undefined4 local_20c;
  undefined1 local_208 [256];
  undefined1 local_108 [256];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  local_218 = param_1;
  local_21c = param_2;
  local_214 = param_3;
  local_210 = param_4;
  local_20c = in_ECX;
  if ((param_5 != 0) || (param_3 == (undefined1 *)0x0)) goto LAB_008cc19b;
  if (param_4 != (undefined1 *)0x0) {
    FUN_008f3b16();
    FUN_008f3b16();
    if (*(int *)(param_3 + 4) != 9) {
      param_3 = local_240;
      local_230 = 4;
      local_228 = 1;
      local_224 = FUN_008c9f5e(local_214);
      iVar2 = FUN_008c9ee7(local_214);
      if (iVar2 != 0) {
        local_230 = 1;
      }
    }
    puVar5 = local_210;
    if (*(int *)(local_210 + 4) != 9) {
      puVar5 = local_264;
      local_254 = 4;
      local_24c = 1;
      local_248 = FUN_008c9f5e(local_210);
      iVar2 = FUN_008c9ee7(local_210);
      if (iVar2 != 0) {
        local_254 = 1;
      }
    }
    iVar2 = *(int *)(param_3 + 0x10);
    if ((iVar2 == 4) || (iVar1 = *(int *)(puVar5 + 0x10), iVar1 == 4)) {
      uVar3 = *(int *)(param_3 + 0x1c) * *(int *)(param_3 + 0x18);
      if (uVar3 <= (uint)(*(int *)(puVar5 + 0x1c) * *(int *)(puVar5 + 0x18))) {
        uVar4 = 0;
        if (uVar3 != 0) {
          do {
            iVar2 = FUN_008ca399(local_214,uVar4,local_240);
            if (((iVar2 < 0) || (iVar2 = FUN_008ca399(local_210,uVar4,local_264), iVar2 < 0)) ||
               (iVar2 = FUN_008cbaba(local_240,local_264,1), iVar2 == 0)) goto LAB_008cbf50;
            uVar4 = uVar4 + 1;
          } while (uVar4 < uVar3);
        }
        goto LAB_008cc19b;
      }
    }
    else {
      if (iVar2 != 0) {
        if (iVar2 == 1) {
          if (iVar1 != 0) {
            if (iVar1 == 1) {
              if (*(uint *)(param_3 + 0x1c) <= *(uint *)(puVar5 + 0x1c)) goto LAB_008cc19b;
            }
            else {
              if (iVar1 != 2) goto LAB_008cc07c;
              uVar3 = *(uint *)(puVar5 + 0x18);
              if (((uVar3 != 1) || (*(uint *)(param_3 + 0x1c) <= *(uint *)(puVar5 + 0x1c))) &&
                 ((iVar2 = *(int *)(puVar5 + 0x1c), iVar2 != 1 ||
                  (*(uint *)(param_3 + 0x1c) <= uVar3)))) {
                if ((uVar3 != 1) && (iVar2 != 1)) {
                  bVar7 = uVar3 * iVar2 == *(int *)(param_3 + 0x1c);
                  goto LAB_008cc105;
                }
                goto LAB_008cc19b;
              }
            }
            goto LAB_008cbf50;
          }
        }
        else if (iVar2 == 2) {
          if (iVar1 != 0) {
            if (iVar1 == 1) {
              uVar3 = *(uint *)(param_3 + 0x18);
              if (((uVar3 != 1) || (*(uint *)(param_3 + 0x1c) <= *(uint *)(puVar5 + 0x1c))) &&
                 ((iVar2 = *(int *)(param_3 + 0x1c), iVar2 != 1 ||
                  (uVar3 <= *(uint *)(puVar5 + 0x1c))))) {
                if ((uVar3 != 1) && (iVar2 != 1)) {
                  bVar7 = uVar3 * iVar2 == *(int *)(puVar5 + 0x1c);
                  goto LAB_008cc105;
                }
                goto LAB_008cc19b;
              }
            }
            else {
              if (iVar1 != 2) goto LAB_008cc07c;
              if ((*(uint *)(param_3 + 0x18) <= *(uint *)(puVar5 + 0x18)) &&
                 (*(uint *)(param_3 + 0x1c) <= *(uint *)(puVar5 + 0x1c))) goto LAB_008cc19b;
            }
            goto LAB_008cbf50;
          }
        }
        else if (iVar2 == 3) {
          if (iVar1 != 3) goto LAB_008cbf50;
          iVar2 = *(int *)(puVar5 + 0x14);
          if (iVar2 != 0xd) {
            if (iVar2 == 0xf) {
              iVar2 = *(int *)(param_3 + 0x14);
              if (((iVar2 == 0xf) || (iVar2 == 0x10)) || ((iVar2 == 0x11 || (iVar2 == 0x12))))
              goto LAB_008cc19b;
              bVar7 = iVar2 == 0x13;
            }
            else if (iVar2 == 0x14) {
              iVar2 = *(int *)(param_3 + 0x14);
              if (((iVar2 == 0x14) || (iVar2 == 0x15)) || ((iVar2 == 0x16 || (iVar2 == 0x17))))
              goto LAB_008cc19b;
              bVar7 = iVar2 == 0x18;
            }
            else {
              bVar7 = *(int *)(param_3 + 0x14) == iVar2;
            }
LAB_008cc105:
            if (!bVar7) goto LAB_008cbf50;
          }
        }
LAB_008cc19b:
        pcVar6 = &DAT_0099cf70;
        goto LAB_008cbf55;
      }
LAB_008cc07c:
      if (iVar1 != 3) goto LAB_008cc19b;
    }
  }
LAB_008cbf50:
  pcVar6 = s_implicitly_00a2018c;
LAB_008cbf55:
  FUN_008ca09e(local_108,0xff,local_214);
  FUN_008ca09e(local_208,0xff,local_210);
  if (local_21c == 0) {
    FUN_008c98fa(local_20c,local_218,0xbc9,s_cannot__sconvert_from___s__to____00a20168);
  }
  else {
    FUN_008c98fa(local_20c,local_218,0xbc9,s___s___cannot__sconvert_from___s__00a2013c,local_21c,
                 pcVar6,local_208,local_108);
  }
  return;
}


// ==== FUN_008cc1d3 @ 0x008cc1d3 ====

int FUN_008cc1d3(int *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,int *param_5)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  piVar1 = param_2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) {
    return -0x7fffbffb;
  }
  *param_3 = 0;
  *param_4 = 0;
  if (param_5 != (int *)0x0) {
    *param_5 = 0;
  }
  if (param_1 == (int *)0x0) {
    if (param_2 == (int *)0x0) {
      return 0;
    }
    return -0x7fffbffb;
  }
  if (param_2 == (int *)0x0) {
    return -0x7fffbffb;
  }
  uVar2 = FUN_008c9f5e(param_1);
  uVar3 = FUN_008c9f5e(piVar1);
  if ((uVar2 < uVar3) || (iVar4 = FUN_008cbaba(param_1,piVar1,0), iVar4 == 0)) {
    iVar4 = FUN_008cbaba(piVar1,param_1,0);
    if (iVar4 != 0) {
      piVar5 = piVar1;
      goto LAB_008cc26d;
    }
    iVar4 = FUN_008cbaba(param_1,piVar1,0);
    if (iVar4 == 0) {
      return -0x7fffbffb;
    }
  }
  piVar5 = param_1;
LAB_008cc26d:
  iVar4 = FUN_008ca464(param_1,piVar1,&param_2);
  piVar1 = param_2;
  if (iVar4 < 0) {
    return iVar4;
  }
  if ((int *)piVar5[5] != param_2) {
    piVar5 = (int *)(**(code **)(*piVar5 + 4))();
    if (piVar5 == (int *)0x0) {
      return -0x7ff8fff2;
    }
    piVar5[5] = (int)piVar1;
  }
  piVar1 = param_5;
  if (param_5 != (int *)0x0) {
    iVar4 = (**(code **)(*piVar5 + 4))();
    *piVar1 = iVar4;
    if (iVar4 == 0) {
      return -0x7ff8fff2;
    }
    FUN_008c9d2e(iVar4,1);
  }
  *param_3 = piVar5;
  *param_4 = piVar5;
  return 0;
}


// ==== FUN_008cc2d1 @ 0x008cc2d1 ====

int FUN_008cc2d1(int param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  local_8 = 2;
  if (param_1 == 0) {
    local_8 = 0;
  }
  else if (0 < param_1) {
    if (param_1 < 5) {
      local_8 = 1;
    }
    else if (param_1 < 9) {
      local_8 = 2;
    }
    else if (param_1 < 0xd) {
      local_8 = 3;
    }
  }
  iVar1 = FUN_008bf738(0x50);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f3e67(0,0,0,0,1,param_4);
  }
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = FUN_008bf738(0x24);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_008f3b3d(0,param_1,1,1,0x200);
  }
  *(int *)(iVar1 + 0x10) = iVar2;
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = FUN_008bf738(0x40);
  if (local_8 == 3) {
    if (iVar2 != 0) {
      iVar2 = FUN_008f3fe9(3,param_3,param_4);
      goto LAB_008cc3a6;
    }
  }
  else if (iVar2 != 0) {
    iVar2 = FUN_008f3fb4(local_8,param_2,param_4);
    goto LAB_008cc3a6;
  }
  iVar2 = 0;
LAB_008cc3a6:
  *(int *)(iVar1 + 0x20) = iVar2;
  if (iVar2 != 0) {
    iVar2 = FUN_008bf738(0x14);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_008f3584(*(undefined4 *)(iVar1 + 0x20),0,s_Value_00a20198);
    }
    if (iVar2 != 0) {
      *(int *)(iVar1 + 0x20) = iVar2;
      FUN_008ca999(iVar1);
      return iVar1;
    }
  }
  return 0;
}


// ==== FUN_008cc3e9 @ 0x008cc3e9 ====

void FUN_008cc3e9(int param_1)

{
  undefined8 uVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  
  uVar1 = 0;
  uVar4 = 0;
  piVar3 = (int *)(in_ECX + 0x20);
  uVar5 = 5;
  if ((param_1 != 0) && (*(int *)(param_1 + 4) == 3)) {
    piVar3 = (int *)(param_1 + 0x10);
    iVar2 = *piVar3;
    if (iVar2 == 2) {
      uVar4 = *(uint *)(param_1 + 0x18);
      uVar5 = (uVar4 & 0xbfffffff | 0x20000000) >> 0x1d;
    }
    else {
      if (iVar2 == 3) {
        uVar5 = 4;
      }
      else {
        if (iVar2 != 4) {
          if (iVar2 == 5) {
            uVar5 = 9;
          }
          else if (iVar2 == 6) {
            uVar5 = 10;
          }
          else if (iVar2 == 7) {
            uVar5 = 0xb;
          }
          else {
            if (iVar2 != 8) goto LAB_008cc45a;
            uVar5 = 0xc;
          }
          uVar1 = *(undefined8 *)(param_1 + 0x18);
          goto LAB_008cc45a;
        }
        uVar5 = 8;
      }
      uVar4 = *(uint *)(param_1 + 0x18);
    }
  }
LAB_008cc45a:
  FUN_008cc2d1(uVar5,uVar4,uVar1,piVar3);
  return;
}


// ==== FUN_008cc46d @ 0x008cc46d ====

int FUN_008cc46d(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  if (param_1 != 0) {
    iVar3 = FUN_008bf738(0x50);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_008f3e67(0,0,0,0,1,param_1 + 0x10);
    }
    if (iVar3 != 0) {
      iVar4 = FUN_008bf738(0x24);
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_008f3b3d(3,0xe,1,1,0x200);
      }
      *(int *)(iVar3 + 0x10) = iVar4;
      if (iVar4 != 0) {
        iVar4 = FUN_008bf738(0x40);
        if (iVar4 == 0) {
          iVar4 = 0;
        }
        else {
          pcVar2 = *(char **)(param_1 + 0x18);
          pcVar5 = pcVar2;
          do {
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = FUN_008f401e(5,pcVar2,pcVar5 + (1 - (int)(pcVar2 + 1)),param_1 + 0x10);
        }
        *(int *)(iVar3 + 0x20) = iVar4;
        if (iVar4 != 0) {
          iVar4 = FUN_008bf738(0x14);
          if (iVar4 == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = FUN_008f3584(*(undefined4 *)(iVar3 + 0x20),0,s_Value_00a20198);
          }
          if (iVar4 != 0) {
            *(int *)(iVar3 + 0x20) = iVar4;
            FUN_008ca999(iVar3);
            return iVar3;
          }
        }
      }
    }
  }
  return 0;
}


// ==== FUN_008cc553 @ 0x008cc553 ====

int FUN_008cc553(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int local_8;
  
  for (; *(int *)(param_1 + 4) != 3; param_1 = *(int *)(param_1 + 8)) {
  }
  iVar1 = FUN_008bf738(0x50);
  if (iVar1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_008f3e67(0,0,0,0,1,param_1 + 0x10);
  }
  if (local_8 == 0) {
LAB_008cc637:
    local_8 = 0;
  }
  else {
    if (param_2 != (int *)0x0) {
      iVar1 = (**(code **)(*param_2 + 4))();
      *(int *)(local_8 + 0x20) = iVar1;
      if (iVar1 == 0) goto LAB_008cc637;
    }
    param_1 = *(int *)(local_8 + 0x20);
    piVar4 = (int *)(local_8 + 0x10);
    if (param_1 != 0) {
      do {
        iVar1 = *(int *)(param_1 + 8);
        if (((iVar1 != 0) && (*(int *)(iVar1 + 4) == 0xd)) && (*(int *)(iVar1 + 0x10) != 0)) {
          iVar2 = FUN_008bf738(0x14);
          if (iVar2 == 0) {
            iVar2 = 0;
          }
          else {
            iVar2 = FUN_008f3584(0,0,s_Types_00a201a0);
          }
          *piVar4 = iVar2;
          if (iVar2 == 0) goto LAB_008cc637;
          uVar3 = FUN_008f352c(*(undefined4 *)(iVar1 + 0x10));
          *(undefined4 *)(*piVar4 + 8) = uVar3;
          if (*(int *)(*piVar4 + 8) == 0) goto LAB_008cc637;
          piVar4 = (int *)(*piVar4 + 0xc);
        }
        param_1 = *(int *)(param_1 + 0xc);
      } while (param_1 != 0);
    }
    FUN_008ca999(local_8);
  }
  return local_8;
}


// ==== FUN_008cc63b @ 0x008cc63b ====

int FUN_008cc63b(int *param_1,char *param_2)

{
  int iVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  char *pcVar13;
  undefined4 in_ECX;
  int iVar14;
  char *pcVar15;
  byte *pbVar16;
  uint uVar17;
  int *piVar18;
  int *piVar19;
  bool bVar20;
  int *local_1c;
  int local_14;
  uint local_10;
  int local_c;
  char *local_8;
  
  iVar8 = (int)param_2;
  if (param_2 == (char *)0x0) {
    return 0;
  }
  if (*(int *)((int)param_2 + 4) != 3) {
    return 0;
  }
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (param_1[1] != 0xd) {
    return 0;
  }
  iVar12 = param_1[4];
  iVar1 = (int)param_2 + 0x10;
  iVar10 = FUN_008bf738(0x50);
  if (iVar10 == 0) {
    local_c = 0;
  }
  else {
    local_c = FUN_008f3e67(0,0x17,0,0,1,iVar1);
  }
  if (local_c == 0) {
    return 0;
  }
  if (iVar12 != 0) {
    if (*(int *)(iVar12 + 4) == 1) {
      param_2 = (char *)0x0;
      local_1c = (int *)iVar12;
      do {
        iVar12 = *(int *)((int)local_1c + 8);
        if ((iVar12 != 0) && (*(int *)(iVar12 + 4) == 6)) {
          iVar10 = *(int *)(iVar12 + 0x18);
          pbVar16 = *(byte **)(*(int *)(iVar12 + 0x14) + 0x18);
          pbVar11 = *(byte **)(iVar8 + 0x18);
          do {
            bVar2 = *pbVar11;
            bVar20 = bVar2 < *pbVar16;
            if (bVar2 != *pbVar16) {
LAB_008cc6fd:
              iVar12 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
              goto LAB_008cc702;
            }
            if (bVar2 == 0) break;
            bVar2 = pbVar11[1];
            bVar20 = bVar2 < pbVar16[1];
            if (bVar2 != pbVar16[1]) goto LAB_008cc6fd;
            pbVar11 = pbVar11 + 2;
            pbVar16 = pbVar16 + 2;
          } while (bVar2 != 0);
          iVar12 = 0;
LAB_008cc702:
          if (iVar12 == 0) {
            if (*(int *)(iVar10 + 0x20) != 0) {
              iVar12 = (**(code **)(**(int **)(iVar10 + 0x20) + 4))();
              *(int *)(local_c + 0x10) = iVar12;
              if (iVar12 == 0) {
                return 0;
              }
            }
            iVar12 = FUN_008bf738(0x40);
            if (iVar12 == 0) {
              iVar12 = 0;
            }
            else {
              iVar12 = FUN_008f3fb4(2,param_2,iVar1);
            }
            *(int *)(local_c + 0x24) = iVar12;
            goto LAB_008cca9e;
          }
          iVar12 = FUN_008c9f5e(*(undefined4 *)(iVar10 + 0x20));
          param_2 = (char *)((int)param_2 + iVar12);
        }
        local_1c = *(int **)((int)local_1c + 0xc);
      } while (local_1c != (int *)0x0);
    }
    else if (*(int *)(iVar12 + 4) == 9) {
      piVar5 = *(int **)(iVar12 + 0x18);
      pcVar15 = *(char **)((int)param_2 + 0x18);
      piVar6 = *(int **)(iVar12 + 0x1c);
      uVar17 = *(uint *)(iVar12 + 0x20) & 0x200;
      pcVar9 = pcVar15;
      do {
        pcVar13 = pcVar9;
        pcVar9 = pcVar13 + 1;
      } while (*pcVar13 != '\0');
      cVar3 = *pcVar15;
      if (cVar3 == '_') {
        if (*(int *)(iVar12 + 0x10) != 2) goto LAB_008cc723;
        if ((pcVar13 <= pcVar15 + 1) || (local_14 = 3, pcVar15[1] != 'm')) {
          local_14 = 2;
        }
      }
      else {
        if (cVar3 < 'a') goto LAB_008cc723;
        if (((cVar3 < 'c') || (cVar3 == 'g')) || (cVar3 == 'r')) {
          if ((*(int *)(iVar12 + 0x10) != 0) && (*(int *)(iVar12 + 0x10) != 1)) goto LAB_008cc723;
          local_14 = 1;
        }
        else {
          if (((cVar3 < 'w') || ('z' < cVar3)) ||
             ((*(int *)(iVar12 + 0x10) != 0 && (*(int *)(iVar12 + 0x10) != 1)))) goto LAB_008cc723;
          local_14 = 0;
        }
      }
      local_10 = 0;
      local_1c = (int *)(local_c + 0x24);
      if (pcVar15 < pcVar13) {
        param_2 = pcVar15 + 2;
        local_8 = pcVar15 + 3;
        piVar18 = param_1;
        piVar19 = param_1;
        do {
          if (3 < local_10) break;
          if (local_14 == 0) {
            cVar3 = *pcVar15;
            if (cVar3 == 'w') {
LAB_008cc97e:
              piVar19 = (int *)0x3;
            }
            else if (cVar3 == 'x') {
LAB_008cc95c:
              piVar19 = (int *)0x0;
            }
            else {
              if (cVar3 != 'y') {
                if (cVar3 == 'z') goto LAB_008cc97a;
                goto LAB_008cc723;
              }
LAB_008cc960:
              piVar19 = (int *)0x1;
            }
LAB_008cc981:
            piVar18 = (int *)0x0;
            pcVar15 = pcVar15 + 1;
            local_8 = local_8 + 1;
            param_2 = param_2 + 1;
          }
          else {
            if (local_14 == 1) {
              cVar3 = *pcVar15;
              if (cVar3 == 'a') goto LAB_008cc97e;
              if (cVar3 == 'b') {
LAB_008cc97a:
                piVar19 = (int *)0x2;
                goto LAB_008cc981;
              }
              if (cVar3 == 'g') goto LAB_008cc960;
              if (cVar3 == 'r') goto LAB_008cc95c;
              goto LAB_008cc723;
            }
            if (local_14 == 2) {
              if (((((pcVar13 <= param_2) || (*pcVar15 != '_')) || (cVar3 = pcVar15[1], cVar3 < '1')
                   ) || (('9' < cVar3 || (cVar4 = *param_2, cVar4 < '1')))) || ('9' < cVar4))
              goto LAB_008cc723;
              local_8 = local_8 + 3;
              piVar18 = (int *)(cVar3 + -0x31);
              piVar19 = (int *)(cVar4 + -0x31);
              pcVar15 = pcVar15 + 3;
              param_2 = param_2 + 3;
            }
            else if (local_14 == 3) {
              if ((((pcVar13 <= local_8) || (*pcVar15 != '_')) ||
                  ((pcVar15[1] != 'm' ||
                   (((cVar3 = *param_2, cVar3 < '0' || ('9' < cVar3)) ||
                    (cVar4 = *local_8, cVar4 < '0')))))) || ('9' < cVar4)) goto LAB_008cc723;
              local_8 = local_8 + 4;
              piVar18 = (int *)(cVar3 + -0x30);
              piVar19 = (int *)(cVar4 + -0x30);
              pcVar15 = pcVar15 + 4;
              param_2 = param_2 + 4;
            }
          }
          if ((piVar5 <= piVar18) || (piVar6 <= piVar19)) goto LAB_008cc723;
          iVar10 = FUN_008bf738(0x14);
          if (iVar10 == 0) {
            iVar10 = 0;
          }
          else {
            iVar10 = FUN_008f3584(0,0,s_Swizzle_00a201a8);
          }
          *local_1c = iVar10;
          if (iVar10 == 0) {
            return 0;
          }
          iVar10 = FUN_008bf738(0x40);
          if (iVar10 == 0) {
            iVar10 = 0;
          }
          else {
            iVar10 = FUN_008f3fb4(2,(int *)((int)piVar18 * (int)piVar6 + (int)piVar19),iVar1);
          }
          *(int *)(*local_1c + 8) = iVar10;
          if (iVar10 == 0) {
            return 0;
          }
          local_1c = (int *)(*local_1c + 0xc);
          local_10 = local_10 + 1;
        } while (pcVar15 < pcVar13);
        if ((pcVar15 < pcVar13) || (4 < local_10)) goto LAB_008cc723;
      }
      iVar10 = *(int *)(local_c + 0x24);
      while ((iVar10 != 0 && (uVar17 == 0))) {
        iVar7 = *(int *)(iVar10 + 0xc);
        if (iVar7 != 0) {
          iVar14 = iVar7;
          do {
            if (*(int *)(*(int *)(iVar10 + 8) + 0x18) == *(int *)(*(int *)(iVar14 + 8) + 0x18)) {
              uVar17 = 1;
              break;
            }
            iVar14 = *(int *)(iVar14 + 0xc);
          } while (iVar14 != 0);
        }
        iVar10 = iVar7;
      }
      iVar10 = FUN_008bf738(0x24);
      if (iVar10 == 0) {
        iVar12 = 0;
      }
      else {
        iVar12 = FUN_008f3b3d(local_10 != 1,*(undefined4 *)(iVar12 + 0x14),1,local_10,
                              -(uint)(uVar17 != 0) & 0x200);
      }
      *(int *)(local_c + 0x10) = iVar12;
LAB_008cca9e:
      if (iVar12 == 0) {
        return 0;
      }
      iVar12 = (**(code **)(*param_1 + 4))();
      *(int *)(local_c + 0x20) = iVar12;
      if (iVar12 != 0) {
        FUN_008ca999(local_c);
        return local_c;
      }
    }
  }
LAB_008cc723:
  FUN_008c98fa(in_ECX,iVar1,0xbca,s_invalid_subscript___s__00a201b0,*(undefined4 *)(iVar8 + 0x18));
  return 0;
}


// ==== FUN_008ccacc @ 0x008ccacc ====

int FUN_008ccacc(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_1;
  if ((((param_1 != 0) && (*(int *)(param_1 + 4) == 0xf)) &&
      (*(uint **)(param_1 + 0x30) != (uint *)0x0)) && (3 < *(uint *)(param_1 + 0x34))) {
    uVar1 = **(uint **)(param_1 + 0x30) & 0xffff0000;
    if (uVar1 == 0x7ffe0000) {
      param_1 = 0x1c;
    }
    else if (uVar1 == 0x7fff0000) {
      param_1 = 0x1b;
    }
    else if (uVar1 == 0xfffe0000) {
      param_1 = 0x1a;
    }
    else {
      if (uVar1 != 0xffff0000) {
        return 0;
      }
      param_1 = 0x19;
    }
    iVar2 = FUN_008bf738(0x50);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_008f3e67(0,0,0,0,1,iVar4 + 0x10);
    }
    if (iVar2 != 0) {
      iVar3 = FUN_008bf738(0x24);
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_008f3b3d(3,param_1,1,1,0x200);
      }
      *(int *)(iVar2 + 0x10) = iVar3;
      if (iVar3 != 0) {
        iVar3 = FUN_008bf738(0x40);
        if (iVar3 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_008f401e(5,*(undefined4 *)(iVar4 + 0x30),*(undefined4 *)(iVar4 + 0x34),
                               iVar4 + 0x10);
        }
        *(int *)(iVar2 + 0x20) = iVar4;
        if (iVar4 != 0) {
          iVar4 = FUN_008bf738(0x14);
          if (iVar4 == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = FUN_008f3584(*(undefined4 *)(iVar2 + 0x20),0,s_Value_00a20198);
          }
          if (iVar4 != 0) {
            *(int *)(iVar2 + 0x20) = iVar4;
            FUN_008ca999(iVar2);
            return iVar2;
          }
        }
      }
    }
  }
  return 0;
}


// ==== FUN_008ccc06 @ 0x008ccc06 ====

int FUN_008ccc06(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar1 = FUN_008bf738(0x50);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f3e67(0,0,0,0,1,in_ECX + 0x20);
  }
  if (iVar1 != 0) {
    iVar2 = FUN_008bf738(0x24);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_008f3b3d(3,0x14,1,1,0x200);
    }
    *(int *)(iVar1 + 0x10) = iVar2;
    if (iVar2 != 0) {
      iVar2 = FUN_008bf738(0x40);
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_008f3fb4(4,0,in_ECX + 0x20);
      }
      if (iVar2 != 0) {
        *(int *)(iVar1 + 0x20) = iVar2;
        if (param_1 != 0) {
          iVar3 = FUN_008f352c(param_1);
          *(int *)(iVar2 + 0x18) = iVar3;
          if (iVar3 == 0) {
            return 0;
          }
        }
        iVar2 = FUN_008bf738(0x14);
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = FUN_008f3584(*(undefined4 *)(iVar1 + 0x20),0,s_Value_00a20198);
        }
        if (iVar2 != 0) {
          *(int *)(iVar1 + 0x20) = iVar2;
          FUN_008ca999(iVar1);
          return iVar1;
        }
      }
    }
  }
  return 0;
}


// ==== FUN_008ccce0 @ 0x008ccce0 ====

int FUN_008ccce0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar1 = FUN_008bf738(0x50);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f3e67(0,0,0,0,1,in_ECX + 0x20);
  }
  if (iVar1 != 0) {
    iVar2 = FUN_008bf738(0x24);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_008f3b3d(3,0x1d,1,1,0x200);
    }
    *(int *)(iVar1 + 0x10) = iVar2;
    if (iVar2 != 0) {
      iVar2 = FUN_008bf738(0x40);
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_008f3fb4(4,0,in_ECX + 0x20);
      }
      if (iVar2 != 0) {
        *(int *)(iVar1 + 0x20) = iVar2;
        if (param_1 != 0) {
          iVar3 = FUN_008f352c(param_1);
          *(int *)(iVar2 + 0x18) = iVar3;
          if (iVar3 == 0) {
            return 0;
          }
        }
        iVar2 = FUN_008bf738(0x14);
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = FUN_008f3584(*(undefined4 *)(iVar1 + 0x20),0,s_Value_00a20198);
        }
        if (iVar2 != 0) {
          *(int *)(iVar1 + 0x20) = iVar2;
          FUN_008ca999(iVar1);
          return iVar1;
        }
      }
    }
  }
  return 0;
}


// ==== FUN_008ccdba @ 0x008ccdba ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008ccdba(int *param_1,int *param_2)

{
  double dVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *param_1;
  if (iVar2 == 0) {
    iVar2 = *param_2;
    if (((iVar2 == 0) || (iVar2 == 1)) || (iVar2 == 2)) {
      param_1[2] = (uint)(param_2[2] != 0);
      return 0;
    }
    if (iVar2 == 3) {
      param_1[2] = (uint)(_DAT_0099d098 != *(double *)(param_2 + 2));
      return 0;
    }
    return 0x80004005;
  }
  if ((iVar2 == 1) || (iVar2 == 2)) {
    iVar2 = *param_2;
    if (iVar2 == 0) {
      uVar3 = (uint)(param_2[2] != 0);
    }
    else if ((iVar2 == 1) || (iVar2 == 2)) {
      uVar3 = param_2[2];
    }
    else {
      if (iVar2 != 3) {
        return 0x80004005;
      }
      uVar3 = __ftol();
    }
    goto LAB_008cceac;
  }
  if (iVar2 == 3) {
    iVar2 = *param_2;
    if (iVar2 == 0) {
      dVar1 = (double)(param_2[2] != 0);
    }
    else if (iVar2 == 1) {
      dVar1 = (double)param_2[2];
    }
    else if (iVar2 == 2) {
      dVar1 = (double)param_2[2];
      if (param_2[2] < 0) {
        dVar1 = dVar1 + _DAT_009c2f50;
      }
    }
    else {
      if (iVar2 != 3) {
        return 0x80004005;
      }
      dVar1 = *(double *)(param_2 + 2);
    }
    *(double *)(param_1 + 2) = dVar1;
    return 0;
  }
  if (iVar2 == 4) {
    if (*param_2 != 4) goto LAB_008ccdf5;
  }
  else {
    if (iVar2 != 5) {
      return 0x80004005;
    }
LAB_008ccdf5:
    if (*param_2 != 4) {
      if (*param_2 == 5) {
        param_1[2] = param_2[2];
        param_1[3] = param_2[3];
        return 0;
      }
      return 0x80004005;
    }
    *param_1 = 4;
  }
  uVar3 = param_2[2];
LAB_008cceac:
  param_1[2] = uVar3;
  return 0;
}


// ==== FUN_008ccef6 @ 0x008ccef6 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008ccef6(uint *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *param_2;
  if (iVar1 == 0) {
    uVar2 = (uint)(param_2[2] != 0);
  }
  else if ((iVar1 == 1) || (iVar1 == 2)) {
    uVar2 = param_2[2];
  }
  else {
    if (iVar1 != 3) {
      return 0x80004005;
    }
    uVar2 = __ftol();
  }
  *param_1 = uVar2;
  return 0;
}


// ==== FUN_008ccf55 @ 0x008ccf55 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008ccf55(int *param_1,double param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    if (_DAT_0099d098 == param_2) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  else {
    if ((iVar1 != 1) && (iVar1 != 2)) {
      if (iVar1 == 3) {
        *(double *)(param_1 + 2) = param_2;
        return 0;
      }
      return 0x80004005;
    }
    iVar1 = __ftol();
  }
  param_1[2] = iVar1;
  return 0;
}


// ==== FUN_008ccfc8 @ 0x008ccfc8 ====

int FUN_008ccfc8(int param_1,int param_2,int param_3,uint param_4)

{
  int *piVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  bool bVar9;
  undefined1 local_24 [4];
  uint local_20;
  undefined1 local_18 [4];
  uint local_14;
  int local_8;
  
  local_8 = 0;
  if ((param_2 == 0) || (*(int *)(param_1 + 0x1c) == 0)) {
    if ((param_2 == 0) != (*(int *)(param_1 + 0x1c) == 0)) {
      local_8 = 2;
    }
  }
  else {
    iVar4 = FUN_008f31ff(*(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x18),0,local_18);
    if ((iVar4 < 0) || (iVar4 = FUN_008f31ff(*(undefined4 *)(param_2 + 0x18),0,local_24), iVar4 < 0)
       ) {
      pbVar8 = *(byte **)(*(int *)(param_1 + 0x1c) + 0x18);
      pbVar5 = *(byte **)(param_2 + 0x18);
      do {
        bVar2 = *pbVar5;
        bVar9 = bVar2 < *pbVar8;
        if (bVar2 != *pbVar8) {
LAB_008cd07d:
          iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_008cd082;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar5[1];
        bVar9 = bVar2 < pbVar8[1];
        if (bVar2 != pbVar8[1]) goto LAB_008cd07d;
        pbVar5 = pbVar5 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar2 != 0);
      iVar4 = 0;
LAB_008cd082:
      if (iVar4 != 0) {
        return -1;
      }
    }
    else if (local_14 != local_20) {
      if (((local_20 ^ local_14) & 0xffff0000) != 0) {
        return -1;
      }
      if (((local_14 & 0xffff) != 0) && ((local_20 & 0xffff) != 0)) {
        return -1;
      }
      local_8 = 2 - (uint)((local_20 & 0xffff) != 0);
    }
  }
  iVar4 = *(int *)(param_1 + 0x24);
  param_1 = param_3;
  if (iVar4 != 0) {
    do {
      piVar1 = (int *)(iVar4 + 8);
      iVar4 = *(int *)(iVar4 + 0xc);
      bVar9 = false;
      if ((iVar4 != 0) && (*(int *)(*(int *)(iVar4 + 8) + 4) == 0xc)) {
        iVar4 = *(int *)(iVar4 + 0xc);
        bVar9 = true;
      }
      if (((param_4 & 0x10) == 0) || ((*(byte *)(*(int *)(*piVar1 + 0x18) + 0x1c) & 0x40) != 0)) {
        if (param_1 == 0) {
          if (!bVar9) {
            return -1;
          }
        }
        else {
          iVar7 = *(int *)(*piVar1 + 0x18);
          uVar3 = *(undefined4 *)(iVar7 + 0x20);
          if (*(int *)(param_1 + 8) == 0) {
            param_2 = 0;
          }
          else {
            param_2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x10);
          }
          if ((*(byte *)(iVar7 + 0x1c) & 0x10) != 0) {
            iVar6 = FUN_008cbaba(uVar3,param_2,0);
            if (iVar6 == 0) {
              return -1;
            }
            iVar6 = FUN_008cb8e4(uVar3,param_2);
            local_8 = local_8 + iVar6;
          }
          if ((*(byte *)(iVar7 + 0x1c) & 0x20) != 0) {
            iVar7 = FUN_008c9e50(param_2);
            if (iVar7 != 0) {
              return -1;
            }
            iVar7 = FUN_008cbaba(param_2,uVar3,0);
            if (iVar7 == 0) {
              return -1;
            }
            iVar7 = FUN_008cb8e4(param_2,uVar3);
            local_8 = local_8 + iVar7;
          }
          param_1 = *(int *)(param_1 + 0xc);
        }
      }
    } while (iVar4 != 0);
  }
  if (param_1 == 0) {
    return local_8;
  }
  return -1;
}


// ==== FUN_008cd197 @ 0x008cd197 ====

int FUN_008cd197(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_008bf738(0x14);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f3584(0,*(undefined4 *)(in_ECX + 0x14),s_UsageType_00a201c8);
  }
  if (iVar1 == 0) {
LAB_008cd1e9:
    FUN_008c9a25(0);
    iVar1 = -0x7ff8fff2;
  }
  else {
    *(int *)(in_ECX + 0x14) = iVar1;
    if (param_1 != 0) {
      iVar2 = FUN_008f352c(param_1);
      *(int *)(iVar1 + 8) = iVar2;
      if (iVar2 == 0) goto LAB_008cd1e9;
      iVar1 = FUN_008cba07(iVar2,*(undefined4 *)(iVar2 + 0x18));
      if (iVar1 < 0) {
        return iVar1;
      }
      *(byte *)(iVar2 + 0x11) = *(byte *)(iVar2 + 0x11) & 0xf1;
    }
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_008cd20f @ 0x008cd20f ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008cd20f(int param_1,double *param_2)

{
  double *pdVar1;
  uint *puVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  uint uVar8;
  undefined4 *puVar9;
  int iVar10;
  double *pdVar11;
  int iVar12;
  undefined8 *puVar13;
  undefined4 extraout_EAX;
  undefined4 in_ECX;
  undefined4 *puVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  float10 fVar18;
  undefined8 uVar19;
  uint local_68 [8];
  void *local_48;
  int local_44;
  int local_40;
  undefined4 uStack_3c;
  int local_38;
  undefined8 local_34;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  double *local_1c;
  double *local_18;
  double *local_14;
  double *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar17 = (int)param_2;
  if (param_1 == 0) {
    if (param_2 == (double *)0x0) {
      return 0;
    }
    return 0x80004005;
  }
  if (*(int *)(param_1 + 4) != 0xd) {
    return 0x80004005;
  }
  local_8 = *(int *)(param_1 + 0x14) * *(int *)(param_1 + 0x18);
  if (*(int *)(param_1 + 0x1c) != 0x1a) {
    return 0x80004005;
  }
  local_68[4] = 0;
  local_68[5] = 0;
  local_68[6] = 0;
  local_68[7] = 0;
  local_38 = *(int *)(param_1 + 0x24);
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_48 = (void *)0x0;
  local_44 = 0;
  local_18 = *(double **)(local_38 + 8);
  local_40 = 0;
  uStack_3c = 0;
  local_c = in_ECX;
  if (local_18 != (double *)0x0) {
    local_10 = (double *)0x0;
    do {
      pdVar11 = local_10;
      iVar10 = *(int *)(local_18 + 1);
      if ((iVar10 != 0) && (*(int *)(iVar10 + 4) == 0xd)) {
        uVar8 = *(int *)(iVar10 + 0x18) * *(int *)(iVar10 + 0x14);
        puVar2 = (uint *)((int)local_68 + (int)local_10);
        *puVar2 = uVar8;
        *(int *)((int)(local_68 + 4) + (int)pdVar11) = iVar10;
        puVar9 = operator_new(uVar8 * 0x10);
        *(undefined4 **)((int)&local_48 + (int)local_10) = puVar9;
        if ((puVar9 == (undefined4 *)0x0) ||
           (iVar10 = FUN_008cf35c(*(int *)((int)(local_68 + 4) + (int)pdVar11),puVar9), iVar10 < 0))
        goto LAB_008ce493;
        local_14 = (double *)0x0;
        if (*puVar2 != 0) {
          local_34 = (double)CONCAT44(param_1 + 0x30,(undefined4)local_34);
          puVar14 = puVar9 + 2;
          do {
            uVar19 = FUN_008ca7a1(puVar14,puVar9,local_34._4_4_);
            if ((int)uVar19 < 0) goto LAB_008ce493;
            local_14 = (double *)((int)local_14 + 1);
            *puVar9 = 3;
            puVar9 = puVar9 + 4;
            puVar14 = (undefined4 *)((int)((ulonglong)uVar19 >> 0x20) + 0x10);
          } while (local_14 < (double *)*puVar2);
        }
      }
      local_18 = *(double **)((int)local_18 + 0xc);
      local_10 = (double *)((int)local_10 + 4);
    } while (local_18 != (double *)0x0);
  }
  dVar3 = _DAT_00a201d8;
  dVar4 = _DAT_0099d098;
  uVar8 = local_8;
  switch(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0x18)) {
  case 0:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)param_2 + 8);
      uVar16 = local_8;
      do {
        *pdVar11 = ABS(*(double *)(((int)local_48 - (int)param_2) + (int)pdVar11));
        pdVar11 = pdVar11 + 2;
        uVar16 = uVar16 - 1;
      } while (uVar16 != 0);
    }
    break;
  case 1:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)local_48 + 8);
      iVar10 = (int)param_2 - (int)local_48;
      param_2 = (double *)local_8;
      do {
        if ((*pdVar11 < _DAT_009fd350) || (_DAT_0099d0a0 < *pdVar11)) {
          FUN_008c98fa(local_c,param_1 + 0x30,0xbfe,s_indefinite_acos_00a20268);
        }
        fVar18 = (float10)FUN_00801d60();
        *(double *)(iVar10 + (int)pdVar11) = (double)fVar18;
        pdVar11 = pdVar11 + 2;
        param_2 = (double *)((int)param_2 - 1);
      } while (param_2 != (double *)0x0);
LAB_008ce3b3:
      uVar8 = local_8;
    }
    break;
  case 2:
    uVar16 = 0;
    *(undefined8 *)((int)param_2 + 8) = 0x3ff0000000000000;
    if (local_8 != 0) {
      pdVar11 = (double *)((int)local_48 + 8);
      do {
        if (*pdVar11 == _DAT_0099d098) {
          dVar4 = 0.0;
          goto LAB_008cd82b;
        }
        uVar16 = uVar16 + 1;
        pdVar11 = pdVar11 + 2;
      } while (uVar16 < local_8);
    }
    break;
  case 3:
    uVar16 = 0;
    *(undefined8 *)((int)param_2 + 8) = 0;
    if (local_8 != 0) {
      pdVar11 = (double *)((int)local_48 + 8);
      do {
        if (*pdVar11 != _DAT_0099d098) {
          dVar4 = 1.0;
          goto LAB_008cd82b;
        }
        uVar16 = uVar16 + 1;
        pdVar11 = pdVar11 + 2;
      } while (uVar16 < local_8);
    }
    break;
  case 4:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)local_48 + 8);
      iVar10 = (int)param_2 - (int)local_48;
      param_2 = (double *)local_8;
      do {
        if ((*pdVar11 < _DAT_009fd350) || (_DAT_0099d0a0 < *pdVar11)) {
          FUN_008c98fa(local_c,param_1 + 0x30,0xbff,s_L_indefinite_asin_00a20256 + 2);
        }
        fVar18 = (float10)FUN_00801e30();
        *(double *)((int)pdVar11 + iVar10) = (double)fVar18;
        pdVar11 = pdVar11 + 2;
        param_2 = (double *)((int)param_2 - 1);
      } while (param_2 != (double *)0x0);
      goto LAB_008ce3b3;
    }
    break;
  case 5:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)param_2 + 8);
      uVar16 = local_8;
      do {
        fVar18 = (float10)fpatan((float10)*(double *)((int)pdVar11 + ((int)local_48 - (int)param_2))
                                 ,(float10)1);
        *pdVar11 = (double)fVar18;
        pdVar11 = pdVar11 + 2;
        uVar16 = uVar16 - 1;
      } while (uVar16 != 0);
    }
    break;
  case 6:
    if (local_8 != 0) {
      pdVar11 = (double *)(local_44 + 8);
      uVar16 = local_8;
      do {
        fVar18 = (float10)fpatan((float10)*(double *)(((int)local_48 - local_44) + (int)pdVar11),
                                 (float10)*pdVar11);
        *(double *)(((int)param_2 - local_44) + (int)pdVar11) = (double)fVar18;
        pdVar11 = pdVar11 + 2;
        uVar16 = uVar16 - 1;
      } while (uVar16 != 0);
    }
    break;
  case 7:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)param_2 + 8);
      iVar10 = (int)local_48 - (int)param_2;
      param_2 = (double *)local_8;
      do {
        uVar19 = *(undefined8 *)((int)pdVar11 + iVar10);
        fVar18 = (float10)FUN_008043d0((int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
        *pdVar11 = (double)fVar18;
        pdVar11 = pdVar11 + 2;
        param_2 = (double *)((int)param_2 - 1);
      } while (param_2 != (double *)0x0);
      goto LAB_008ce3b3;
    }
    break;
  case 8:
    if (local_8 != 0) {
      local_10 = (double *)((int)local_48 - local_40);
      pdVar11 = (double *)(local_40 + 8);
      local_1c = (double *)local_8;
      do {
        pdVar1 = (double *)((int)local_10 + (int)pdVar11);
        if (*(double *)((local_44 - local_40) + (int)pdVar11) <= *pdVar1) {
          if (*pdVar1 <= *pdVar11) {
            dVar4 = *pdVar1;
          }
          else {
            dVar4 = *pdVar11;
          }
        }
        else {
          dVar4 = *(double *)((local_44 - local_40) + (int)pdVar11);
        }
        *(double *)(((int)param_2 - local_40) + (int)pdVar11) = dVar4;
        pdVar11 = pdVar11 + 2;
        local_1c = (double *)((int)local_1c - 1);
      } while (local_1c != (double *)0x0);
      local_1c = (double *)0x0;
    }
    break;
  default:
    goto switchD_008cd35c_caseD_9;
  case 10:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)param_2 + 8);
      uVar16 = local_8;
      do {
        fVar18 = (float10)fcos((float10)*(double *)((int)pdVar11 + ((int)local_48 - (int)param_2)));
        *pdVar11 = (double)fVar18;
        pdVar11 = pdVar11 + 2;
        uVar16 = uVar16 - 1;
      } while (uVar16 != 0);
    }
    break;
  case 0xb:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)param_2 + 8);
      param_2 = (double *)local_8;
      do {
        fVar18 = (float10)FUN_00977222();
        *pdVar11 = (double)fVar18;
        pdVar11 = pdVar11 + 2;
        param_2 = (double *)((int)param_2 - 1);
      } while (param_2 != (double *)0x0);
      goto LAB_008ce3b3;
    }
    break;
  case 0xc:
    *(double *)((int)param_2 + 8) =
         *(double *)((int)local_48 + 0x18) * *(double *)(local_44 + 0x28) -
         *(double *)((int)local_48 + 0x28) * *(double *)(local_44 + 0x18);
    *(double *)((int)param_2 + 0x18) =
         *(double *)((int)local_48 + 0x28) * *(double *)(local_44 + 8) -
         *(double *)(local_44 + 0x28) * *(double *)((int)local_48 + 8);
    *(double *)((int)param_2 + 0x28) =
         *(double *)(local_44 + 0x18) * *(double *)((int)local_48 + 8) -
         *(double *)((int)local_48 + 0x18) * *(double *)(local_44 + 8);
    break;
  case 0xd:
    if (local_8 != 0) {
      puVar13 = (undefined8 *)((int)param_2 + 8);
      uVar16 = local_8;
      do {
        *puVar13 = 0;
        puVar13 = puVar13 + 2;
        uVar16 = uVar16 - 1;
      } while (uVar16 != 0);
    }
    break;
  case 0xe:
    if (local_8 != 0) {
      puVar13 = (undefined8 *)((int)param_2 + 8);
      uVar16 = local_8;
      do {
        *puVar13 = 0;
        puVar13 = puVar13 + 2;
        uVar16 = uVar16 - 1;
      } while (uVar16 != 0);
    }
    break;
  case 0xf:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)param_2 + 8);
      uVar16 = local_8;
      do {
        *pdVar11 = *(double *)((int)pdVar11 + ((int)local_48 - (int)param_2)) * _DAT_00a20250;
        pdVar11 = pdVar11 + 2;
        uVar16 = uVar16 - 1;
      } while (uVar16 != 0);
    }
    break;
  case 0x10:
    iVar10 = *(int *)(local_68[4] + 0x14);
    if (iVar10 == 1) {
      dVar4 = *(double *)((int)local_48 + 8);
    }
    else if (iVar10 == 2) {
      dVar4 = *(double *)((int)local_48 + 0x38) * *(double *)((int)local_48 + 8) -
              *(double *)((int)local_48 + 0x28) * *(double *)((int)local_48 + 0x18);
    }
    else {
      if (iVar10 != 3) {
        if (iVar10 == 4) {
          dVar4 = *(double *)((int)local_48 + 0xa8) * *(double *)((int)local_48 + 0xf8) -
                  *(double *)((int)local_48 + 0xb8) * *(double *)((int)local_48 + 0xe8);
          dVar6 = *(double *)((int)local_48 + 0xf8) * *(double *)((int)local_48 + 0x98) -
                  *(double *)((int)local_48 + 0xd8) * *(double *)((int)local_48 + 0xb8);
          dVar7 = *(double *)((int)local_48 + 0x98) * *(double *)((int)local_48 + 0xe8) -
                  *(double *)((int)local_48 + 0xa8) * *(double *)((int)local_48 + 0xd8);
          dVar5 = *(double *)((int)local_48 + 0x88) * *(double *)((int)local_48 + 0xf8) -
                  *(double *)((int)local_48 + 200) * *(double *)((int)local_48 + 0xb8);
          dVar3 = *(double *)((int)local_48 + 0x88) * *(double *)((int)local_48 + 0xe8) -
                  *(double *)((int)local_48 + 200) * *(double *)((int)local_48 + 0xa8);
          local_34 = *(double *)((int)local_48 + 0x88) * *(double *)((int)local_48 + 0xd8) -
                     *(double *)((int)local_48 + 200) * *(double *)((int)local_48 + 0x98);
          *(double *)((int)param_2 + 8) =
               ((local_34 * *(double *)((int)local_48 + 0x78) +
                (dVar6 * *(double *)((int)local_48 + 0x48) -
                dVar5 * *(double *)((int)local_48 + 0x58))) * *(double *)((int)local_48 + 0x28) +
               ((dVar7 * *(double *)((int)local_48 + 0x78) +
                (dVar4 * *(double *)((int)local_48 + 0x58) -
                dVar6 * *(double *)((int)local_48 + 0x68))) * *(double *)((int)local_48 + 8) -
               (dVar3 * *(double *)((int)local_48 + 0x78) +
               (dVar4 * *(double *)((int)local_48 + 0x48) -
               dVar5 * *(double *)((int)local_48 + 0x68))) * *(double *)((int)local_48 + 0x18))) -
               (local_34 * *(double *)((int)local_48 + 0x68) +
               (dVar7 * *(double *)((int)local_48 + 0x48) -
               dVar3 * *(double *)((int)local_48 + 0x58))) * *(double *)((int)local_48 + 0x38);
          break;
        }
        goto switchD_008cd35c_caseD_9;
      }
      dVar4 = (*(double *)((int)local_48 + 0x78) * *(double *)((int)local_48 + 0x38) -
              *(double *)((int)local_48 + 0x48) * *(double *)((int)local_48 + 0x68)) *
              *(double *)((int)local_48 + 0x28) +
              ((*(double *)((int)local_48 + 0x88) * *(double *)((int)local_48 + 0x48) -
               *(double *)((int)local_48 + 0x58) * *(double *)((int)local_48 + 0x78)) *
               *(double *)((int)local_48 + 8) -
              (*(double *)((int)local_48 + 0x88) * *(double *)((int)local_48 + 0x38) -
              *(double *)((int)local_48 + 0x58) * *(double *)((int)local_48 + 0x68)) *
              *(double *)((int)local_48 + 0x18));
    }
    goto LAB_008cd82b;
  case 0x11:
    dVar4 = 0.0;
    if (local_8 != 0) {
      pdVar11 = (double *)(local_44 + 8);
      uVar16 = local_8;
      do {
        dVar3 = *(double *)((int)pdVar11 + ((int)local_48 - local_44)) - *pdVar11;
        pdVar11 = pdVar11 + 2;
        uVar16 = uVar16 - 1;
        dVar4 = dVar3 * dVar3 + dVar4;
      } while (uVar16 != 0);
    }
    goto LAB_008cd85e;
  case 0x12:
    *(undefined8 *)((int)param_2 + 8) = 0;
    if (local_8 != 0) {
      pdVar11 = (double *)((int)local_48 + 8);
      uVar16 = local_8;
      do {
        pdVar1 = (double *)((local_44 - (int)local_48) + (int)pdVar11);
        dVar4 = *pdVar11;
        pdVar11 = pdVar11 + 2;
        uVar16 = uVar16 - 1;
        *(double *)((int)param_2 + 8) = *pdVar1 * dVar4 + *(double *)((int)param_2 + 8);
      } while (uVar16 != 0);
    }
    break;
  case 0x13:
    *(undefined8 *)((int)param_2 + 8) = 0x3ff0000000000000;
    *(double *)((int)param_2 + 0x18) =
         *(double *)(local_44 + 0x18) * *(double *)((int)local_48 + 0x18);
    *(undefined8 *)((int)param_2 + 0x28) = *(undefined8 *)((int)local_48 + 0x28);
    *(undefined8 *)((int)param_2 + 0x38) = *(undefined8 *)(local_44 + 0x38);
    break;
  case 0x14:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)param_2 + 8);
      param_2 = (double *)local_8;
      do {
        fVar18 = (float10)FUN_0097726c();
        *pdVar11 = (double)fVar18;
        pdVar11 = pdVar11 + 2;
        param_2 = (double *)((int)param_2 - 1);
      } while (param_2 != (double *)0x0);
      goto LAB_008ce3b3;
    }
    break;
  case 0x15:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)param_2 + 8);
      param_2 = (double *)local_8;
      do {
        fVar18 = (float10)FUN_00801f40();
        *pdVar11 = (double)fVar18;
        pdVar11 = pdVar11 + 2;
        param_2 = (double *)((int)param_2 - 1);
      } while (param_2 != (double *)0x0);
      goto LAB_008ce3b3;
    }
    break;
  case 0x16:
    dVar4 = 0.0;
    if (local_8 != 0) {
      pdVar11 = (double *)(local_44 + 8);
      uVar16 = local_8;
      do {
        pdVar1 = (double *)((local_40 - local_44) + (int)pdVar11);
        dVar3 = *pdVar11;
        pdVar11 = pdVar11 + 2;
        uVar16 = uVar16 - 1;
        dVar4 = *pdVar1 * dVar3 + dVar4;
      } while (uVar16 != 0);
      if (local_8 != 0) {
        pdVar11 = (double *)((int)local_48 + 8);
        uVar16 = local_8;
        do {
          dVar3 = *pdVar11;
          if (_DAT_0099d098 <= dVar4) {
            dVar3 = -dVar3;
          }
          *(double *)((int)pdVar11 + ((int)param_2 - (int)local_48)) = dVar3;
          pdVar11 = pdVar11 + 2;
          uVar16 = uVar16 - 1;
        } while (uVar16 != 0);
      }
    }
    break;
  case 0x17:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)param_2 + 8);
      iVar10 = (int)local_48 - (int)param_2;
      param_2 = (double *)local_8;
      do {
        uVar19 = *(undefined8 *)((int)pdVar11 + iVar10);
        fVar18 = (float10)FUN_008044f0((int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
        *pdVar11 = (double)fVar18;
        pdVar11 = pdVar11 + 2;
        param_2 = (double *)((int)param_2 - 1);
      } while (param_2 != (double *)0x0);
      goto LAB_008ce3b3;
    }
    break;
  case 0x18:
    if (local_8 != 0) {
      iVar15 = (int)param_2 - local_44;
      iVar10 = local_44 + 8;
      local_1c = (double *)local_8;
      do {
        fVar18 = (float10)FUN_0080462a();
        *(double *)(iVar15 + iVar10) = (double)fVar18;
        iVar10 = iVar10 + 0x10;
        local_1c = (double *)((int)local_1c - 1);
      } while (local_1c != (double *)0x0);
      local_1c = (double *)0x0;
      goto LAB_008ce3b3;
    }
    break;
  case 0x19:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)local_48 + 8);
      iVar10 = (int)param_2 - (int)local_48;
      param_2 = (double *)local_8;
      do {
        iVar15 = FUN_00803910(SUB84(*pdVar11,0),(int)((ulonglong)*pdVar11 >> 0x20));
        if (iVar15 == 0) {
          fVar18 = (float10)0;
        }
        else {
          fVar18 = (float10)FUN_008044f0(SUB84(*pdVar11,0),(int)((ulonglong)*pdVar11 >> 0x20));
          fVar18 = (float10)*pdVar11 - fVar18;
        }
        *(double *)((int)pdVar11 + iVar10) = (double)fVar18;
        pdVar11 = pdVar11 + 2;
        param_2 = (double *)((int)param_2 - 1);
      } while (param_2 != (double *)0x0);
      goto LAB_008ce3b3;
    }
    break;
  case 0x1b:
    if (local_8 != 0) {
      puVar13 = (undefined8 *)((int)param_2 + 8);
      uVar16 = local_8;
      do {
        *puVar13 = 0;
        puVar13 = puVar13 + 2;
        uVar16 = uVar16 - 1;
      } while (uVar16 != 0);
    }
    break;
  case 0x1c:
    if (local_8 != 0) {
      puVar13 = (undefined8 *)((int)param_2 + 8);
      iVar10 = (int)local_48 - (int)param_2;
      param_2 = (double *)local_8;
      do {
        uVar19 = *(undefined8 *)((int)puVar13 + iVar10);
        iVar15 = FUN_00803910((int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
        if (iVar15 == 0) {
          uVar19 = 0;
        }
        else {
          uVar19 = 0x3ff0000000000000;
        }
        *puVar13 = uVar19;
        puVar13 = puVar13 + 2;
        param_2 = (double *)((int)param_2 - 1);
      } while (param_2 != (double *)0x0);
      goto LAB_008ce3b3;
    }
    break;
  case 0x1d:
    if (local_8 != 0) {
      puVar13 = (undefined8 *)((int)param_2 + 8);
      iVar10 = (int)local_48 - (int)param_2;
      param_2 = (double *)local_8;
      do {
        uVar19 = *(undefined8 *)((int)puVar13 + iVar10);
        iVar15 = FUN_00803910((int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
        if (iVar15 == 0) {
          uVar19 = 0x3ff0000000000000;
        }
        else {
          uVar19 = 0;
        }
        *puVar13 = uVar19;
        puVar13 = puVar13 + 2;
        param_2 = (double *)((int)param_2 - 1);
      } while (param_2 != (double *)0x0);
      goto LAB_008ce3b3;
    }
    break;
  case 0x1e:
    if (local_8 != 0) {
      puVar13 = (undefined8 *)((int)param_2 + 8);
      iVar10 = (int)local_48 - (int)param_2;
      param_2 = (double *)local_8;
      do {
        iVar15 = __isnan(*(double *)((int)puVar13 + iVar10));
        if (iVar15 == 0) {
          uVar19 = 0;
        }
        else {
          uVar19 = 0x3ff0000000000000;
        }
        *puVar13 = uVar19;
        puVar13 = puVar13 + 2;
        param_2 = (double *)((int)param_2 - 1);
      } while (param_2 != (double *)0x0);
      goto LAB_008ce3b3;
    }
    break;
  case 0x1f:
    if (local_8 != 0) {
      iVar10 = (int)param_2 - (int)local_48;
      pdVar11 = (double *)((int)local_48 + 8);
      local_1c = (double *)local_8;
      do {
        fVar18 = (float10)FUN_00801f40();
        *(double *)((int)pdVar11 + iVar10) = (double)(fVar18 * (float10)*pdVar11);
        pdVar11 = pdVar11 + 2;
        local_1c = (double *)((int)local_1c - 1);
      } while (local_1c != (double *)0x0);
      local_1c = (double *)0x0;
      goto LAB_008ce3b3;
    }
    break;
  case 0x20:
    dVar4 = 0.0;
    if (local_8 != 0) {
      pdVar11 = (double *)((int)local_48 + 8);
      uVar16 = local_8;
      do {
        dVar3 = *pdVar11;
        pdVar11 = pdVar11 + 2;
        uVar16 = uVar16 - 1;
        dVar4 = dVar3 * dVar3 + dVar4;
      } while (uVar16 != 0);
    }
LAB_008cd85e:
    dVar4 = SQRT(dVar4);
LAB_008cd82b:
    *(double *)((int)param_2 + 8) = dVar4;
    break;
  case 0x21:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)local_48 + 8);
      iVar10 = (int)param_2 - (int)local_48;
      param_2 = (double *)local_8;
      do {
        pdVar1 = (double *)((local_40 - (int)local_48) + (int)pdVar11);
        *(double *)((int)pdVar11 + iVar10) =
             (*(double *)((int)pdVar1 + (local_44 - local_40)) - *pdVar11) * *pdVar1 + *pdVar11;
        pdVar11 = pdVar11 + 2;
        param_2 = (double *)((int)param_2 - 1);
      } while (param_2 != (double *)0x0);
      goto LAB_008ce3b3;
    }
    break;
  case 0x22:
    *(undefined8 *)((int)param_2 + 8) = 0x3ff0000000000000;
    *(undefined8 *)((int)param_2 + 0x18) = 0;
    *(undefined8 *)((int)param_2 + 0x28) = 0;
    *(undefined8 *)((int)param_2 + 0x38) = 0x3ff0000000000000;
    if ((_DAT_0099d098 < *(double *)((int)local_48 + 8)) &&
       (*(undefined8 *)((int)param_2 + 0x18) = *(undefined8 *)((int)local_48 + 8),
       _DAT_0099d098 < *(double *)(local_44 + 8))) {
      fVar18 = (float10)FUN_00801f40();
      *(double *)((int)param_2 + 0x28) = (double)fVar18;
      goto LAB_008ce3b3;
    }
    break;
  case 0x23:
    if (local_8 != 0) {
      iVar10 = (int)param_2 - (int)local_48;
      pdVar11 = (double *)((int)local_48 + 8);
      local_1c = (double *)local_8;
      do {
        dVar4 = *pdVar11;
        if ((!NAN(dVar4) && !NAN(_DAT_0099d098)) &&
            dVar4 < _DAT_0099d098 != (dVar4 == _DAT_0099d098)) {
          FUN_008c98fa(local_c,param_1 + 0x30,0xbd8,s_infinite_indefinite_log_00a20234);
          uVar8 = local_8;
        }
        fVar18 = (float10)log2((float10)*pdVar11);
        *(double *)(iVar10 + (int)pdVar11) = (double)((float10)0.6931471805599453 * fVar18);
        pdVar11 = pdVar11 + 2;
        local_1c = (double *)((int)local_1c - 1);
      } while (local_1c != (double *)0x0);
      local_1c = (double *)0x0;
    }
    break;
  case 0x24:
    if (local_8 != 0) {
      iVar10 = (int)param_2 - (int)local_48;
      pdVar11 = (double *)((int)local_48 + 8);
      fVar18 = (float10)log2((float10)_DAT_009fdca8);
      local_34 = (double)((float10)0.6931471805599453 * fVar18);
      local_1c = (double *)local_8;
      do {
        dVar4 = *pdVar11;
        if ((!NAN(dVar4) && !NAN(_DAT_0099d098)) &&
            dVar4 < _DAT_0099d098 != (dVar4 == _DAT_0099d098)) {
          FUN_008c98fa(local_c,param_1 + 0x30,0xbd8,s_infinite_indefinite_log_00a20234);
          uVar8 = local_8;
        }
        fVar18 = (float10)log2((float10)*pdVar11);
        *(double *)(iVar10 + (int)pdVar11) =
             (double)(((float10)0.6931471805599453 * fVar18) / (float10)local_34);
        pdVar11 = pdVar11 + 2;
        local_1c = (double *)((int)local_1c - 1);
      } while (local_1c != (double *)0x0);
      local_1c = (double *)0x0;
    }
    break;
  case 0x25:
    if (local_8 != 0) {
      iVar10 = (int)param_2 - (int)local_48;
      pdVar11 = (double *)((int)local_48 + 8);
      fVar18 = (float10)log2((float10)_DAT_00a0b350);
      local_34 = (double)((float10)0.6931471805599453 * fVar18);
      local_1c = (double *)local_8;
      do {
        dVar4 = *pdVar11;
        if ((!NAN(dVar4) && !NAN(_DAT_0099d098)) &&
            dVar4 < _DAT_0099d098 != (dVar4 == _DAT_0099d098)) {
          FUN_008c98fa(local_c,param_1 + 0x30,0xbd8,s_infinite_indefinite_log_00a20234);
          uVar8 = local_8;
        }
        fVar18 = (float10)log2((float10)*pdVar11);
        *(double *)(iVar10 + (int)pdVar11) =
             (double)(((float10)0.6931471805599453 * fVar18) / (float10)local_34);
        pdVar11 = pdVar11 + 2;
        local_1c = (double *)((int)local_1c - 1);
      } while (local_1c != (double *)0x0);
      local_1c = (double *)0x0;
    }
    break;
  case 0x26:
    if (local_8 != 0) {
      pdVar11 = (double *)(local_44 + 8);
      iVar10 = (int)param_2 - local_44;
      param_2 = (double *)local_8;
      do {
        if (*(double *)(((int)local_48 - local_44) + (int)pdVar11) <= *pdVar11) {
          dVar4 = *pdVar11;
        }
        else {
          dVar4 = *(double *)(((int)local_48 - local_44) + (int)pdVar11);
        }
        *(double *)(iVar10 + (int)pdVar11) = dVar4;
        pdVar11 = pdVar11 + 2;
        param_2 = (double *)((int)param_2 - 1);
      } while (param_2 != (double *)0x0);
    }
    break;
  case 0x27:
    if (local_8 != 0) {
      pdVar11 = (double *)(local_44 + 8);
      iVar10 = (int)param_2 - local_44;
      param_2 = (double *)local_8;
      do {
        if (*pdVar11 <= *(double *)(((int)local_48 - local_44) + (int)pdVar11)) {
          dVar4 = *pdVar11;
        }
        else {
          dVar4 = *(double *)(((int)local_48 - local_44) + (int)pdVar11);
        }
        *(double *)(iVar10 + (int)pdVar11) = dVar4;
        pdVar11 = pdVar11 + 2;
        param_2 = (double *)((int)param_2 - 1);
      } while (param_2 != (double *)0x0);
    }
    break;
  case 0x29:
  case 0x2a:
  case 0x2b:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)param_2 + 8);
      uVar16 = local_8;
      do {
        *pdVar11 = *(double *)((local_44 - (int)param_2) + (int)pdVar11) *
                   *(double *)((int)local_48 + 8);
        pdVar11 = pdVar11 + 2;
        uVar16 = uVar16 - 1;
      } while (uVar16 != 0);
    }
    break;
  case 0x2c:
  case 0x2f:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)param_2 + 8);
      uVar16 = local_8;
      do {
        *pdVar11 = *(double *)((int)pdVar11 + ((int)local_48 - (int)param_2)) *
                   *(double *)(local_44 + 8);
        pdVar11 = pdVar11 + 2;
        uVar16 = uVar16 - 1;
      } while (uVar16 != 0);
    }
    break;
  case 0x2d:
  case 0x2e:
  case 0x30:
  case 0x31:
    iVar10 = *(int *)(local_68[4] + 0x14);
    local_24 = *(int *)(local_68[4] + 0x18);
    if (*(int *)(*(int *)(local_68[5] + 0x10) + 0x10) == 1) {
      iVar15 = *(int *)(local_68[5] + 0x18);
      local_20 = *(int *)(local_68[5] + 0x14);
    }
    else {
      iVar15 = *(int *)(local_68[5] + 0x14);
      local_20 = *(int *)(local_68[5] + 0x18);
    }
    if ((local_24 == iVar15) && (local_20 * iVar10 == local_8)) {
      if (iVar10 != 0) {
        local_1c = (double *)((int)local_48 + 8);
        local_10 = (double *)((int)param_2 + 8);
        local_34 = (double)CONCAT44(iVar10,(undefined4)local_34);
        do {
          if (local_20 != 0) {
            local_18 = (double *)(local_44 + 8);
            local_14 = local_10;
            local_2c = local_20;
            do {
              dVar4 = 0.0;
              if (local_24 != 0) {
                param_2 = local_18;
                pdVar11 = local_1c;
                local_28 = local_24;
                do {
                  dVar3 = *pdVar11;
                  dVar5 = *param_2;
                  param_2 = param_2 + local_20 * 2;
                  pdVar11 = pdVar11 + 2;
                  local_28 = local_28 + -1;
                  dVar4 = dVar3 * dVar5 + dVar4;
                } while (local_28 != 0);
              }
              local_18 = local_18 + 2;
              *local_14 = dVar4;
              local_14 = local_14 + 2;
              local_2c = local_2c + -1;
            } while (local_2c != 0);
          }
          local_10 = local_10 + local_20 * 2;
          local_1c = local_1c + local_24 * 2;
          iVar10 = local_34._4_4_ + -1;
          local_34 = (double)CONCAT44(iVar10,(undefined4)local_34);
        } while (iVar10 != 0);
      }
      break;
    }
    goto switchD_008cd35c_caseD_9;
  case 0x33:
    dVar4 = 0.0;
    if (local_8 == 0) {
LAB_008cdeec:
      dVar4 = 0.0;
    }
    else {
      pdVar11 = (double *)((int)local_48 + 8);
      uVar16 = local_8;
      do {
        dVar3 = *pdVar11;
        pdVar11 = pdVar11 + 2;
        uVar16 = uVar16 - 1;
        dVar4 = dVar3 * dVar3 + dVar4;
      } while (uVar16 != 0);
      if (dVar4 == _DAT_0099d098) goto LAB_008cdeec;
      dVar4 = _DAT_0099d0a0 / SQRT(dVar4);
    }
    if (local_8 != 0) {
      pdVar11 = (double *)((int)param_2 + 8);
      uVar16 = local_8;
      do {
        *pdVar11 = dVar4 * *(double *)((int)pdVar11 + ((int)local_48 - (int)param_2));
        pdVar11 = pdVar11 + 2;
        uVar16 = uVar16 - 1;
      } while (uVar16 != 0);
    }
    break;
  case 0x34:
    if (local_8 != 0) {
      iVar15 = (int)param_2 - local_44;
      iVar10 = local_44 + 8;
      local_34 = (double)CONCAT44(local_8,(undefined4)local_34);
      do {
        fVar18 = (float10)FUN_00801f40();
        *(double *)(iVar10 + iVar15) = (double)fVar18;
        iVar12 = __fpclass((double)fVar18);
        if ((0 < iVar12) && (iVar12 < 3)) {
          FUN_008c98fa(local_c,param_1 + 0x30,0xbd8,s__indefinite_power_00a2021f + 1);
        }
        iVar10 = iVar10 + 0x10;
        iVar12 = local_34._4_4_ + -1;
        local_34 = (double)CONCAT44(iVar12,(undefined4)local_34);
      } while (iVar12 != 0);
      goto LAB_008ce3b3;
    }
    break;
  case 0x35:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)param_2 + 8);
      uVar16 = local_8;
      do {
        *pdVar11 = *(double *)((int)pdVar11 + ((int)local_48 - (int)param_2)) * _DAT_00a20218;
        pdVar11 = pdVar11 + 2;
        uVar16 = uVar16 - 1;
      } while (uVar16 != 0);
    }
    break;
  case 0x36:
    dVar4 = 0.0;
    if (local_8 != 0) {
      pdVar11 = (double *)((int)local_48 + 8);
      local_34 = (double)CONCAT44(local_8,(undefined4)local_34);
      do {
        pdVar1 = (double *)((int)pdVar11 + (local_44 - (int)local_48));
        dVar3 = *pdVar11;
        pdVar11 = pdVar11 + 2;
        iVar10 = local_34._4_4_ + -1;
        local_34 = (double)CONCAT44(iVar10,(undefined4)local_34);
        dVar4 = *pdVar1 * dVar3 + dVar4;
      } while (iVar10 != 0);
      if (local_8 != 0) {
        pdVar11 = (double *)(local_44 + 8);
        uVar16 = local_8;
        do {
          *(double *)(((int)param_2 - local_44) + (int)pdVar11) =
               *(double *)(((int)local_48 - local_44) + (int)pdVar11) -
               (dVar4 * *pdVar11 + dVar4 * *pdVar11);
          pdVar11 = pdVar11 + 2;
          uVar16 = uVar16 - 1;
        } while (uVar16 != 0);
      }
    }
    break;
  case 0x37:
    dVar4 = *(double *)(local_40 + 8);
    dVar3 = 0.0;
    if (local_8 != 0) {
      pdVar11 = (double *)((int)local_48 + 8);
      local_34 = (double)CONCAT44(local_8,(undefined4)local_34);
      do {
        pdVar1 = (double *)((int)pdVar11 + (local_44 - (int)local_48));
        dVar5 = *pdVar11;
        pdVar11 = pdVar11 + 2;
        iVar10 = local_34._4_4_ + -1;
        local_34 = (double)CONCAT44(iVar10,(undefined4)local_34);
        dVar3 = *pdVar1 * dVar5 + dVar3;
      } while (iVar10 != 0);
    }
    dVar5 = _DAT_0099d0a0 - (_DAT_0099d0a0 - dVar3 * dVar3) * dVar4 * dVar4;
    if (_DAT_0099d098 <= dVar5) {
      if (local_8 != 0) {
        pdVar11 = (double *)(local_44 + 8);
        uVar16 = local_8;
        do {
          *(double *)(((int)param_2 - local_44) + (int)pdVar11) =
               dVar4 * *(double *)(((int)local_48 - local_44) + (int)pdVar11) -
               (dVar3 * dVar4 + SQRT(dVar5)) * *pdVar11;
          pdVar11 = pdVar11 + 2;
          uVar16 = uVar16 - 1;
        } while (uVar16 != 0);
      }
    }
    else if (local_8 != 0) {
      puVar13 = (undefined8 *)((int)param_2 + 8);
      uVar16 = local_8;
      do {
        *puVar13 = 0;
        puVar13 = puVar13 + 2;
        uVar16 = uVar16 - 1;
      } while (uVar16 != 0);
    }
    break;
  case 0x38:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)param_2 + 8);
      iVar10 = (int)local_48 - (int)param_2;
      param_2 = (double *)local_8;
      do {
        fVar18 = (float10)FUN_008044f0(*(double *)((int)pdVar11 + iVar10) + _DAT_00a011c0);
        *pdVar11 = (double)fVar18;
        pdVar11 = pdVar11 + 2;
        param_2 = (double *)((int)param_2 - 1);
      } while (param_2 != (double *)0x0);
      goto LAB_008ce3b3;
    }
    break;
  case 0x39:
    if (local_8 != 0) {
      iVar10 = (int)param_2 - (int)local_48;
      pdVar11 = (double *)((int)local_48 + 8);
      local_34 = (double)CONCAT44(local_8,(undefined4)local_34);
      do {
        if (*pdVar11 < _DAT_0099d098) {
          FUN_008c98fa(local_c,param_1 + 0x30,0xbd7,s_imaginary_square_root_00a201fc);
          uVar8 = local_8;
        }
        if (_DAT_0099d098 == *pdVar11) {
          FUN_008c98fa(local_c,param_1 + 0x30,0xbd9,s__division_by_zero_00a201e7 + 1);
          uVar8 = local_8;
        }
        *(double *)((int)pdVar11 + iVar10) = _DAT_0099d0a0 / SQRT(*pdVar11);
        pdVar11 = pdVar11 + 2;
        iVar15 = local_34._4_4_ + -1;
        local_34 = (double)CONCAT44(iVar15,(undefined4)local_34);
      } while (iVar15 != 0);
    }
    break;
  case 0x3a:
    if (local_8 != 0) {
      puVar13 = (undefined8 *)((int)param_2 + 8);
      iVar10 = (int)local_48 - (int)param_2;
      uVar16 = local_8;
      do {
        if (_DAT_0099d098 <= *(double *)((int)puVar13 + iVar10)) {
          if (*(double *)((int)puVar13 + iVar10) <= _DAT_0099d0a0) {
            uVar19 = *(undefined8 *)((int)puVar13 + iVar10);
          }
          else {
            uVar19 = 0x3ff0000000000000;
          }
        }
        else {
          uVar19 = 0;
        }
        *puVar13 = uVar19;
        puVar13 = puVar13 + 2;
        uVar16 = uVar16 - 1;
      } while (uVar16 != 0);
    }
    break;
  case 0x3b:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)param_2 + 8);
      uVar16 = local_8;
      do {
        if (dVar4 <= *(double *)((int)pdVar11 + ((int)local_48 - (int)param_2))) {
          if (*(double *)((int)pdVar11 + ((int)local_48 - (int)param_2)) <= dVar4) {
            dVar3 = 0.0;
          }
          else {
            dVar3 = 1.0;
          }
        }
        else {
          dVar3 = _DAT_009fd350;
        }
        *pdVar11 = dVar3;
        pdVar11 = pdVar11 + 2;
        uVar16 = uVar16 - 1;
      } while (uVar16 != 0);
    }
    break;
  case 0x3c:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)param_2 + 8);
      uVar16 = local_8;
      do {
        fVar18 = (float10)fsin((float10)*(double *)((int)pdVar11 + ((int)local_48 - (int)param_2)));
        *pdVar11 = (double)fVar18;
        pdVar11 = pdVar11 + 2;
        uVar16 = uVar16 - 1;
      } while (uVar16 != 0);
    }
    break;
  case 0x3e:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)param_2 + 8);
      param_2 = (double *)local_8;
      do {
        fVar18 = (float10)FUN_00977218();
        *pdVar11 = (double)fVar18;
        pdVar11 = pdVar11 + 2;
        param_2 = (double *)((int)param_2 - 1);
      } while (param_2 != (double *)0x0);
      goto LAB_008ce3b3;
    }
    break;
  case 0x3f:
    if (local_8 != 0) {
      local_10 = (double *)((int)local_48 - local_40);
      pdVar11 = (double *)(local_40 + 8);
      iVar10 = (int)param_2 - local_40;
      param_2 = (double *)local_8;
      do {
        if (*(double *)((int)pdVar11 + (int)local_10) <= *pdVar11) {
          if (*(double *)((int)pdVar11 + (local_44 - local_40)) <= *pdVar11) {
            uVar19 = 0x3ff0000000000000;
            goto LAB_008ce286;
          }
          dVar4 = (*pdVar11 - *(double *)((int)pdVar11 + (int)local_10)) /
                  (*(double *)((int)pdVar11 + (local_44 - local_40)) -
                  *(double *)((int)pdVar11 + (int)local_10));
          dVar3 = dVar4 * dVar4 * dVar4;
          *(double *)((int)pdVar11 + iVar10) = _DAT_00a201e0 * dVar4 * dVar4 - (dVar3 + dVar3);
        }
        else {
          uVar19 = 0;
LAB_008ce286:
          *(undefined8 *)((int)pdVar11 + iVar10) = uVar19;
        }
        pdVar11 = pdVar11 + 2;
        param_2 = (double *)((int)param_2 - 1);
      } while (param_2 != (double *)0x0);
    }
    break;
  case 0x40:
    if (local_8 != 0) {
      iVar10 = (int)param_2 - (int)local_48;
      pdVar11 = (double *)((int)local_48 + 8);
      local_34 = (double)CONCAT44(local_8,(undefined4)local_34);
      do {
        if (*pdVar11 < _DAT_0099d098) {
          FUN_008c98fa(local_c,param_1 + 0x30,0xbd7,s_imaginary_square_root_00a201fc);
          uVar8 = local_8;
        }
        *(double *)(iVar10 + (int)pdVar11) = SQRT(*pdVar11);
        pdVar11 = pdVar11 + 2;
        iVar15 = local_34._4_4_ + -1;
        local_34 = (double)CONCAT44(iVar15,(undefined4)local_34);
      } while (iVar15 != 0);
    }
    break;
  case 0x41:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)local_48 + 8);
      iVar10 = (int)param_2 - (int)local_48;
      param_2 = (double *)local_8;
      do {
        if (*(double *)((int)pdVar11 + (local_44 - (int)local_48)) < *pdVar11) {
          uVar19 = 0;
        }
        else {
          uVar19 = 0x3ff0000000000000;
        }
        *(undefined8 *)(iVar10 + (int)pdVar11) = uVar19;
        pdVar11 = pdVar11 + 2;
        param_2 = (double *)((int)param_2 - 1);
      } while (param_2 != (double *)0x0);
    }
    break;
  case 0x42:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)param_2 + 8);
      uVar16 = local_8;
      do {
        fVar18 = (float10)fptan((float10)*(double *)((int)pdVar11 + ((int)local_48 - (int)param_2)))
        ;
        *pdVar11 = (double)fVar18;
        pdVar11 = pdVar11 + 2;
        uVar16 = uVar16 - 1;
      } while (uVar16 != 0);
    }
    break;
  case 0x43:
    if (local_8 != 0) {
      pdVar11 = (double *)((int)param_2 + 8);
      param_2 = (double *)local_8;
      do {
        fVar18 = (float10)FUN_00977229();
        *pdVar11 = (double)fVar18;
        pdVar11 = pdVar11 + 2;
        param_2 = (double *)((int)param_2 - 1);
      } while (param_2 != (double *)0x0);
      goto LAB_008ce3b3;
    }
    break;
  case 0x58:
    local_10 = (double *)0x0;
    if (*(int *)(local_68[4] + 0x18) != 0) {
      uVar16 = *(uint *)(local_68[4] + 0x14);
      do {
        param_2 = (double *)0x0;
        if (uVar16 != 0) {
          do {
            iVar10 = *(int *)(local_68[4] + 0x18) * (int)param_2;
            iVar15 = *(int *)(param_1 + 0x18) * (int)local_10 + (int)param_2;
            param_2 = (double *)((int)param_2 + 1);
            *(undefined8 *)(iVar15 * 0x10 + 8 + iVar17) =
                 *(undefined8 *)((int)(iVar10 + (int)local_10) * 0x10 + 8 + (int)local_48);
            uVar16 = *(uint *)(local_68[4] + 0x14);
          } while (param_2 < uVar16);
        }
        local_10 = (double *)((int)local_10 + 1);
      } while (local_10 < *(double **)(local_68[4] + 0x18));
    }
    break;
  case 0x59:
    *(double *)((int)param_2 + 8) = *(double *)((int)local_48 + 0x28) * _DAT_00a201d8;
    *(double *)((int)param_2 + 0x18) = *(double *)((int)local_48 + 0x18) * dVar3;
    *(double *)((int)param_2 + 0x28) = *(double *)((int)local_48 + 8) * dVar3;
    *(double *)((int)param_2 + 0x38) = *(double *)((int)local_48 + 0x38) * dVar3;
  }
  iVar10 = local_38;
  do {
    iVar10 = *(int *)(iVar10 + 0xc);
    if (iVar10 == 0) {
      param_2 = (double *)0x0;
      if (uVar8 == 0) goto LAB_008ce493;
      goto LAB_008ce464;
    }
  } while (*(int *)(iVar10 + 8) == 0);
switchD_008cd35c_caseD_9:
LAB_008ce493:
  _free(local_48);
  return extraout_EAX;
  while( true ) {
    param_2 = (double *)((int)param_2 + 1);
    iVar17 = iVar17 + 0x10;
    if (local_8 <= param_2) break;
LAB_008ce464:
    iVar10 = FUN_008ccf55(iVar17,(int)*(undefined8 *)(iVar17 + 8),
                          (int)((ulonglong)*(undefined8 *)(iVar17 + 8) >> 0x20),param_1 + 0x30);
    if (iVar10 < 0) break;
  }
  goto LAB_008ce493;
}


// ==== FUN_008ce5ff @ 0x008ce5ff ====

undefined4
FUN_008ce5ff(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,uint param_6,
            int *param_7,int *param_8)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 in_ECX;
  uint uVar8;
  int *piVar9;
  char *pcVar10;
  short *psVar11;
  char *pcVar12;
  bool bVar13;
  undefined8 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  int local_114 [64];
  int local_14;
  uint local_10;
  uint local_c;
  undefined4 local_8;
  
  if (param_7 != (int *)0x0) {
    *param_7 = 0;
  }
  if (param_8 != (int *)0x0) {
    *param_8 = 0;
  }
  local_10 = 0xffffffff;
  local_c = 0;
  local_8 = in_ECX;
  if (param_5 != 0) {
    do {
      if (local_10 == 0) break;
      local_14 = FUN_008c9bf1(param_2,param_5);
      while ((local_14 != 0 && (local_10 != 0))) {
        iVar5 = *(int *)(local_14 + 8);
        if (param_1 != *(int *)(iVar5 + 0x10)) {
          if ((param_6 & 5) != 0) {
            FUN_008c98fa(local_8,param_2,0xbbd,s___s___identifier_represents_a__s_00a202cc,
                         *(undefined4 *)(param_2 + 8),(&PTR_DAT_00a202f8)[*(int *)(iVar5 + 0x10)],
                         (&PTR_DAT_00a202f8)[param_1]);
          }
          if (param_7 != (int *)0x0) {
            *param_7 = 0;
          }
          return 0x80004005;
        }
        uVar8 = 0;
        if ((param_6 & 4) != 0) {
          uVar8 = FUN_008ccfc8(*(undefined4 *)(iVar5 + 0x18),param_3,param_4,param_6);
        }
        if ((param_6 & 8) != 0) {
          iVar4 = FUN_008cb7d5(*(undefined4 *)(iVar5 + 0x18),param_3,param_4,param_6);
          uVar8 = uVar8 + iVar4;
        }
        uVar2 = local_10;
        if (uVar8 != 0xffffffff) {
          if (uVar8 < local_10) {
            local_c = 0;
            local_10 = uVar8;
          }
          uVar3 = local_c;
          if ((uVar8 <= uVar2) && (local_c < 0x40)) {
            local_c = local_c + 1;
            local_114[uVar3] = iVar5;
          }
          if (((local_10 == 0) && (*(int *)(iVar5 + 0x2c) != 0)) && (*(int *)(iVar5 + 0x28) == 0)) {
            iVar4 = *(int *)(param_5 + 0x20);
            if ((iVar4 != 0) && (*(int *)(iVar4 + 0x10) == 4)) {
              for (iVar4 = FUN_008c9bf1(param_2,iVar4); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xc)) {
                if (*(int *)(*(int *)(iVar4 + 8) + 0x2c) == 0) {
                  FUN_008c9960(local_8,param_2,0xc06,s___s___loop_control_variable_used_00a20330,
                               *(undefined4 *)(param_2 + 8));
                  *(undefined4 *)(iVar5 + 0x28) = 1;
                  break;
                }
              }
            }
            iVar4 = local_14;
            do {
              iVar4 = *(int *)(iVar4 + 0xc);
              if (iVar4 == 0) goto LAB_008ce776;
            } while (*(int *)(*(int *)(iVar4 + 8) + 0x2c) != 0);
            FUN_008c9960(local_8,param_2,0xc06,s___s___loop_control_variable_used_00a20330,
                         *(undefined4 *)(param_2 + 8));
            *(undefined4 *)(iVar5 + 0x28) = 1;
          }
        }
LAB_008ce776:
        local_14 = *(int *)(local_14 + 0xc);
      }
      param_5 = *(int *)(param_5 + 0x20);
    } while (param_5 != 0);
    if (local_10 == 0xffffffff) goto LAB_008ce914;
    if ((param_6 & 4) != 0) {
      iVar5 = *(int *)(local_114[0] + 0x18);
      uVar8 = 1;
      if (1 < local_c) {
        do {
          uVar14 = FUN_008c9fec(*(undefined4 *)(iVar5 + 0x20),
                                *(undefined4 *)(*(int *)(local_114[uVar8] + 0x18) + 0x20));
          if (((int)uVar14 == 0) ||
             (iVar4 = FUN_008cb7d5(iVar5,*(undefined4 *)(iVar5 + 0x1c),
                                   *(undefined4 *)((int)((ulonglong)uVar14 >> 0x20) + 0x24),0),
             iVar4 == -1)) break;
          uVar8 = uVar8 + 1;
        } while (uVar8 < local_c);
        if (uVar8 < local_c) {
          FUN_008c98fa(local_8,param_2,0xbfb,s___s___ambiguous_function_call_00a2030c,
                       *(undefined4 *)(param_2 + 8));
        }
      }
    }
    if (param_7 != (int *)0x0) {
      if ((param_6 & 2) != 0) {
        *param_7 = *(int *)(local_114[0] + 0x18);
        goto LAB_008ce888;
      }
      if (*(int *)(local_114[0] + 0x18) == 0) goto LAB_008ce888;
      iVar5 = FUN_008f352c(*(int *)(local_114[0] + 0x18));
      *param_7 = iVar5;
      if (iVar5 != 0) goto LAB_008ce888;
      goto LAB_008cec80;
    }
LAB_008ce888:
    uVar8 = 0;
    if (param_8 != (int *)0x0) {
      param_7 = (int *)0x0;
      piVar9 = (int *)&param_7;
      if (local_c != 0) {
        do {
          iVar5 = FUN_008bf738(0x14);
          if (iVar5 == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = FUN_008f3584(0,0,s_Values_00a200e4);
          }
          *piVar9 = iVar5;
          if (iVar5 == 0) goto LAB_008cec80;
          iVar5 = FUN_008bf738(0x40);
          if (iVar5 == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = FUN_008f3fb4(2,*(undefined4 *)(local_114[uVar8] + 0x24),param_2);
          }
          *(int *)(*piVar9 + 8) = iVar5;
          if (iVar5 == 0) goto LAB_008cec80;
          piVar9 = (int *)(*piVar9 + 0xc);
          uVar8 = uVar8 + 1;
        } while (uVar8 < local_c);
      }
      *param_8 = (int)param_7;
    }
    goto LAB_008cec8c;
  }
LAB_008ce914:
  piVar9 = param_7;
  if (((param_6 & 2) != 0) || (param_8 != (int *)0x0)) goto LAB_008cec90;
  if (param_1 == 0) {
    iVar5 = __stricmp(*(char **)(param_2 + 8),s_dword_00a202c4);
    if (iVar5 == 0) {
      uVar7 = 4;
LAB_008ce95c:
      if (piVar9 != (int *)0x0) {
        iVar5 = FUN_008bf738(0x24);
        if (iVar5 == 0) goto LAB_008ce979;
        uVar17 = 1;
        uVar16 = 1;
        uVar15 = 0;
LAB_008ce9ea:
        iVar5 = FUN_008f3b3d(uVar15,uVar7,uVar16,uVar17,0);
LAB_008ce97b:
        *piVar9 = iVar5;
        goto LAB_008ce97f;
      }
    }
    else {
      iVar5 = __stricmp(*(char **)(param_2 + 8),s_float_00a1fed0);
      if (iVar5 == 0) {
        uVar7 = 0xb;
        goto LAB_008ce95c;
      }
      iVar5 = __stricmp(*(char **)(param_2 + 8),s_vector_00a202bc);
      if (iVar5 == 0) {
        if (piVar9 == (int *)0x0) goto LAB_008cec8c;
        iVar5 = FUN_008bf738(0x24);
        if (iVar5 != 0) {
          uVar17 = 4;
          uVar16 = 1;
          uVar7 = 0xb;
          uVar15 = 1;
          goto LAB_008ce9ea;
        }
LAB_008ce979:
        iVar5 = 0;
        goto LAB_008ce97b;
      }
      iVar5 = __stricmp(*(char **)(param_2 + 8),s_matrix_00a202b4);
      if (iVar5 == 0) {
        if (piVar9 == (int *)0x0) goto LAB_008cec8c;
        iVar5 = FUN_008bf738(0x24);
        if (iVar5 == 0) goto LAB_008ce979;
        uVar17 = 4;
        uVar16 = 4;
        uVar7 = 0xb;
        uVar15 = 2;
        goto LAB_008ce9ea;
      }
      iVar5 = __stricmp(*(char **)(param_2 + 8),s_string_009fd520);
      if (iVar5 != 0) {
        iVar5 = __stricmp(*(char **)(param_2 + 8),s_texture_00a1fec0);
        if (iVar5 == 0) {
          uVar7 = 0xf;
          goto LAB_008cea4d;
        }
        iVar5 = __stricmp(*(char **)(param_2 + 8),s_pixelshader_00a1fe4c);
        if (iVar5 == 0) {
          uVar7 = 0x19;
          goto LAB_008cea4d;
        }
        iVar5 = __stricmp(*(char **)(param_2 + 8),s_vertexshader_00a1fe3c);
        if (iVar5 == 0) {
          uVar7 = 0x1a;
          goto LAB_008cea4d;
        }
        piVar9 = *(int **)(param_2 + 8);
        piVar6 = piVar9;
        do {
          iVar5 = *piVar6;
          piVar6 = (int *)((int)piVar6 + 1);
        } while ((char)iVar5 != '\0');
        uVar8 = (int)piVar6 - (int)((int)piVar9 + 1);
        iVar5 = 3;
        if ((uVar8 < 4) || (*piVar9 != DAT_00a1fee0)) {
          if (2 < uVar8) {
            bVar13 = true;
            piVar6 = piVar9;
            pcVar10 = &DAT_009febf0;
            do {
              if (iVar5 == 0) break;
              iVar5 = iVar5 + -1;
              bVar13 = (char)*piVar6 == *pcVar10;
              piVar6 = (int *)((int)piVar6 + 1);
              pcVar10 = pcVar10 + 1;
            } while (bVar13);
            if (bVar13) {
              piVar9 = (int *)((int)piVar9 + 3);
              uVar7 = 4;
              iVar5 = uVar8 - 3;
              goto LAB_008ceb27;
            }
          }
          if ((uVar8 < 4) || (*piVar9 != DAT_00a1fed8)) {
            if (4 < uVar8) {
              iVar5 = 5;
              bVar13 = true;
              piVar6 = piVar9;
              pcVar10 = s_float_00a1fed0;
              do {
                if (iVar5 == 0) break;
                iVar5 = iVar5 + -1;
                bVar13 = (char)*piVar6 == *pcVar10;
                piVar6 = (int *)((int)piVar6 + 1);
                pcVar10 = pcVar10 + 1;
              } while (bVar13);
              if (bVar13) {
                piVar9 = (int *)((int)piVar9 + 5);
                uVar7 = 0xb;
                iVar5 = uVar8 - 5;
                goto LAB_008ceb27;
              }
            }
            if (uVar8 < 6) goto LAB_008cec90;
            iVar5 = 3;
            bVar13 = true;
            piVar6 = piVar9;
            psVar11 = (short *)s_double_00a1fec8;
            do {
              if (iVar5 == 0) break;
              iVar5 = iVar5 + -1;
              bVar13 = (short)*piVar6 == *psVar11;
              piVar6 = (int *)((int)piVar6 + 2);
              psVar11 = psVar11 + 1;
            } while (bVar13);
            if (!bVar13) goto LAB_008cec90;
            piVar9 = (int *)((int)piVar9 + 6);
            uVar7 = 0xc;
            iVar5 = uVar8 - 6;
          }
          else {
            piVar9 = piVar9 + 1;
            uVar7 = 10;
            iVar5 = uVar8 - 4;
          }
        }
        else {
          uVar7 = 0;
          piVar9 = piVar9 + 1;
          iVar5 = uVar8 - 4;
        }
LAB_008ceb27:
        if (iVar5 == 1) {
          if (((char)*piVar9 < '1') || ('4' < (char)*piVar9)) {
LAB_008cec90:
            if ((param_6 & 1) != 0) {
              FUN_008c98fa(local_8,param_2,0xbbc,s_undeclared_identifier___s__00a20298,
                           *(undefined4 *)(param_2 + 8));
            }
            return 1;
          }
          if (param_7 == (int *)0x0) goto LAB_008cec8c;
          iVar5 = FUN_008bf738(0x24);
          if (iVar5 == 0) goto LAB_008cebcd;
          cVar1 = (char)*piVar9;
          iVar5 = 1;
          uVar15 = 1;
LAB_008ceb61:
          iVar5 = FUN_008f3b3d(uVar15,uVar7,iVar5,cVar1 + -0x30,0);
LAB_008cebcf:
          *param_7 = iVar5;
          goto LAB_008ce97f;
        }
        if (((((iVar5 != 3) || ((char)*piVar9 < '1')) || ('4' < (char)*piVar9)) ||
            ((*(char *)((int)piVar9 + 1) != 'x' || (*(char *)((int)piVar9 + 2) < '1')))) ||
           ('4' < *(char *)((int)piVar9 + 2))) goto LAB_008cec90;
        if (param_7 != (int *)0x0) {
          iVar5 = FUN_008bf738(0x24);
          if (iVar5 != 0) {
            cVar1 = *(char *)((int)piVar9 + 2);
            iVar5 = (char)*piVar9 + -0x30;
            uVar15 = 2;
            goto LAB_008ceb61;
          }
LAB_008cebcd:
          iVar5 = 0;
          goto LAB_008cebcf;
        }
        goto LAB_008cec8c;
      }
      uVar7 = 0xe;
LAB_008cea4d:
      piVar9 = param_7;
      if (param_7 == (int *)0x0) goto LAB_008cec8c;
      iVar5 = FUN_008bf738(0x24);
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_008f3b3d(3,uVar7,1,1,0);
      }
      *piVar9 = iVar5;
LAB_008ce97f:
      if (iVar5 == 0) goto LAB_008cec80;
    }
LAB_008cec8c:
    uVar7 = 0;
  }
  else {
    if (param_1 != 1) goto LAB_008cec90;
    iVar5 = 5;
    bVar13 = true;
    pcVar10 = *(char **)(param_2 + 8);
    pcVar12 = &DAT_00a00f30;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar13 = *pcVar10 == *pcVar12;
      pcVar10 = pcVar10 + 1;
      pcVar12 = pcVar12 + 1;
    } while (bVar13);
    if (!bVar13) goto LAB_008cec90;
    if (param_7 == (int *)0x0) goto LAB_008cec8c;
    iVar5 = FUN_008bf738(0x40);
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_008f3cb2();
    }
    if (iVar5 != 0) {
      *(undefined4 *)(iVar5 + 0x14) = 1;
      *(undefined4 *)(iVar5 + 0x18) = 0;
      *(undefined4 *)(iVar5 + 0x1c) = 0x202;
      iVar4 = FUN_008bf738(0x24);
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_008f3b3d(3,0xd,1,1,0x200);
      }
      *(int *)(iVar5 + 0x20) = iVar4;
      if (iVar4 != 0) {
        iVar4 = FUN_008bf738(0x40);
        if (iVar4 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_008f401e(5,0,0,param_2);
        }
        *(int *)(iVar5 + 0x24) = iVar4;
        if (iVar4 != 0) {
          *param_7 = iVar5;
          goto LAB_008cec8c;
        }
      }
    }
LAB_008cec80:
    uVar7 = 0x8007000e;
  }
  return uVar7;
}


// ==== FUN_008cecbc @ 0x008cecbc ====

int FUN_008cecbc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int local_8;
  
  local_8 = 0;
  if ((param_1 == 0) || (*(int *)(param_1 + 4) != 3)) {
    return 0;
  }
  param_1 = param_1 + 0x10;
  iVar1 = param_2;
  if (param_2 == 0) {
    iVar1 = FUN_008ce5ff(1,param_1,0,0,*(undefined4 *)(in_ECX + 0x10),1,&local_8,0);
    if (iVar1 != 0) {
      return 0;
    }
    iVar1 = local_8;
  }
  iVar2 = FUN_008bf738(0x50);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_008f3e67(0,0,0,0,1,param_1);
  }
  if (iVar2 != 0) {
    if (*(int *)(iVar1 + 0x24) == 0) {
      iVar3 = FUN_008bf738(0x40);
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_008f401e(6,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14),param_1);
      }
    }
    else {
      iVar3 = (**(code **)(**(int **)(iVar1 + 0x24) + 4))();
    }
    *(int *)(iVar2 + 0x20) = iVar3;
    if (iVar3 != 0) {
      uVar4 = FUN_008f352c(*(undefined4 *)(iVar1 + 0x20));
      *(undefined4 *)(iVar2 + 0x10) = uVar4;
      if (param_2 != 0) {
        FUN_008c9d2e(uVar4,0);
      }
      iVar1 = FUN_008bf738(0x14);
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_008f3584(*(undefined4 *)(iVar2 + 0x20),0,s_Value_00a20198);
      }
      if (iVar1 != 0) {
        *(int *)(iVar2 + 0x20) = iVar1;
        FUN_008ca999(iVar2);
        return iVar2;
      }
    }
  }
  return 0;
}


// ==== FUN_008cedc3 @ 0x008cedc3 ====

int FUN_008cedc3(int *param_1,int *param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *local_c [2];
  
  piVar1 = param_2;
  local_c[0] = (int *)0x0;
  piVar7 = param_1;
  if ((param_1 != (int *)0x0) && (param_1[1] == 3)) {
    FUN_008ce5ff(0,param_1 + 4,0,0,*(undefined4 *)(in_ECX + 0x10),1,local_c,0);
    piVar7 = local_c[0];
  }
  param_1 = (int *)(in_ECX + 0x20);
  if (param_3 == 0) {
    local_c[0] = (int *)0x0;
    if (param_2 != (int *)0x0) {
      if (param_2[1] != 0xd) {
        return 0;
      }
      local_c[0] = (int *)param_2[4];
      param_1 = param_2 + 0xc;
    }
    iVar2 = FUN_008cbaba(piVar7,local_c[0],param_4);
    if (iVar2 == 0) {
      FUN_008cbdf2(param_1,0,piVar7,local_c[0],param_4);
      return 0;
    }
    iVar2 = FUN_008c9e50(piVar7);
    if ((iVar2 == 0) && (iVar2 = FUN_008c9e50(local_c[0]), iVar2 == 0)) {
      param_2 = (int *)0x0;
    }
    else {
      param_2 = (int *)0x1;
    }
  }
  else {
    if (((piVar7 == (int *)0x0) || (piVar7[1] != 9)) || (iVar2 = FUN_008c9ee7(piVar7), iVar2 == 0))
    goto LAB_008cefce;
    if ((param_2 != (int *)0x0) && (param_2[1] != 1)) {
      return 0;
    }
    param_2 = (int *)FUN_008c9e50(piVar7);
  }
  uVar3 = FUN_008ca7ff(piVar1);
  param_2 = (int *)((uint)param_2 | uVar3);
  iVar2 = FUN_008bf738(0x50);
  iVar6 = 0;
  if (iVar2 != 0) {
    iVar6 = FUN_008f3e67(0,0,0,0,1,param_1);
  }
  if (iVar6 == 0) {
    return 0;
  }
  if (piVar7 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar7 + 4))();
    *(int *)(iVar6 + 0x10) = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
  }
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 4))();
    *(int *)(iVar6 + 0x20) = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
  }
  if (param_3 != 0) {
    for (iVar2 = *(int *)(iVar6 + 0x20); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
      iVar5 = *(int *)(iVar2 + 8);
      if ((iVar5 != 0) && (*(int *)(iVar5 + 4) == 0xd)) {
        iVar5 = FUN_008c9ee7(*(undefined4 *)(iVar5 + 0x10));
        if (iVar5 == 0) goto LAB_008cefce;
        if (param_2 == (int *)0x0) {
          param_2 = (int *)FUN_008c9e50(*(undefined4 *)(*(int *)(iVar2 + 8) + 0x10));
        }
      }
    }
  }
  if (param_2 != (int *)0x0) {
    FUN_008c9d2e(*(undefined4 *)(iVar6 + 0x10),1);
  }
  if (param_3 != 0) {
    iVar5 = 0;
    for (iVar2 = *(int *)(iVar6 + 0x20); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
      iVar4 = *(int *)(iVar2 + 8);
      if ((iVar4 != 0) && (*(int *)(iVar4 + 4) == 0xd)) {
        iVar4 = FUN_008c9f5e(*(undefined4 *)(iVar4 + 0x10));
        iVar5 = iVar5 + iVar4;
      }
    }
    iVar2 = FUN_008c9f5e(*(undefined4 *)(iVar6 + 0x10));
    if (iVar5 != iVar2) {
LAB_008cefce:
      FUN_008c98fa();
      return 0;
    }
  }
  FUN_008ca999(iVar6);
  return iVar6;
}


// ==== FUN_008cefec @ 0x008cefec ====

int FUN_008cefec(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *local_24;
  int *local_20;
  undefined4 local_1c;
  int *local_18;
  int *local_14;
  int local_10;
  int local_c;
  
  if ((((param_1 != 0) && (*(int *)(param_1 + 4) != 0xd)) ||
      ((param_2 != 0 && (*(int *)(param_2 + 4) != 0xd)))) ||
     ((param_3 != 0 && (*(int *)(param_3 + 4) != 0xd)))) {
    return 0;
  }
  local_10 = param_1 + 0x30;
  if (param_1 == 0) {
    local_10 = in_ECX + 0x20;
    local_1c = 0;
  }
  else {
    local_1c = *(undefined4 *)(param_1 + 0x10);
  }
  if (param_2 == 0) {
    local_14 = (int *)0x0;
  }
  else {
    local_14 = *(int **)(param_2 + 0x10);
  }
  if (param_3 == 0) {
    local_18 = (int *)0x0;
  }
  else {
    local_18 = *(int **)(param_3 + 0x10);
  }
  local_20 = local_14;
  local_24 = local_18;
  iVar3 = 0;
  iVar1 = FUN_008bf738(0x50);
  if (iVar1 == 0) {
    local_c = 0;
  }
  else {
    local_c = FUN_008f3e67(0,0x18,0,0,1,local_10);
  }
  if (local_c == 0) {
    return 0;
  }
  iVar1 = FUN_008c9ee7(local_1c);
  if (iVar1 == 0) goto LAB_008cf0b9;
  piVar4 = (int *)(local_c + 0x10);
  iVar1 = FUN_008cc1d3(local_14,local_18,&local_20,&local_24,piVar4);
  if (iVar1 < 0) goto LAB_008cf0b9;
  if (*piVar4 == 0) goto LAB_008cf174;
  if (*(int *)(*piVar4 + 4) == 9) {
    iVar1 = FUN_008bf738(0x24);
    if (iVar1 == 0) goto LAB_008cf144;
    uVar6 = 0x200;
    uVar2 = *(undefined4 *)(*piVar4 + 0x1c);
    uVar5 = *(undefined4 *)(*piVar4 + 0x18);
LAB_008cf138:
    iVar3 = FUN_008f3b3d(2,0,uVar5,uVar2,uVar6);
  }
  else {
    iVar1 = FUN_008bf738(0x24);
    if (iVar1 != 0) {
      uVar6 = 0x200;
      uVar2 = FUN_008c9f5e(*piVar4);
      uVar5 = 1;
      goto LAB_008cf138;
    }
LAB_008cf144:
    iVar3 = 0;
  }
  if (iVar3 == 0) {
    return 0;
  }
  iVar1 = FUN_008cbaba(iVar3,local_1c,0);
  if (iVar1 != 0) {
LAB_008cf174:
    if (param_1 != 0) {
      iVar1 = FUN_008cedc3(iVar3,param_1,0,0);
      *(int *)(local_c + 0x20) = iVar1;
      if (iVar1 == 0) {
        return 0;
      }
    }
    iVar1 = FUN_008bf738(0x50);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_008f3e67(0,0,0,0,1,local_10);
    }
    *(int *)(local_c + 0x24) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
    iVar3 = FUN_008bf738(0x14);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_008f3584(0,0,s_Types_00a201a0);
    }
    piVar4 = local_20;
    *(int *)(iVar1 + 0x10) = iVar3;
    if (iVar3 == 0) {
      return 0;
    }
    if (local_20 != (int *)0x0) {
      uVar2 = (**(code **)(*local_20 + 4))();
      *(undefined4 *)(*(int *)(iVar1 + 0x10) + 8) = uVar2;
      if (*(int *)(*(int *)(iVar1 + 0x10) + 8) == 0) {
        return 0;
      }
    }
    iVar3 = FUN_008bf738(0x14);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_008f3584(0,0,s_Value_00a20198);
    }
    *(int *)(iVar1 + 0x20) = iVar3;
    if (iVar3 == 0) {
      return 0;
    }
    if (param_2 != 0) {
      if ((local_14 == piVar4) || (iVar3 = FUN_008c9fec(local_14,piVar4), iVar3 != 0)) {
        uVar2 = FUN_008f352c(param_2);
      }
      else {
        uVar2 = FUN_008cedc3(piVar4,param_2,0,0);
      }
      *(undefined4 *)(*(int *)(iVar1 + 0x20) + 8) = uVar2;
      if (*(int *)(*(int *)(iVar1 + 0x20) + 8) == 0) {
        return 0;
      }
    }
    iVar3 = FUN_008bf738(0x14);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_008f3584(0,0,s_Types_00a201a0);
    }
    piVar4 = local_24;
    *(int *)(*(int *)(iVar1 + 0x10) + 0xc) = iVar3;
    if (iVar3 == 0) {
      return 0;
    }
    if (local_24 != (int *)0x0) {
      uVar2 = (**(code **)(*local_24 + 4))();
      *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x10) + 0xc) + 8) = uVar2;
      if (*(int *)(*(int *)(*(int *)(iVar1 + 0x10) + 0xc) + 8) == 0) {
        return 0;
      }
    }
    iVar3 = FUN_008bf738(0x14);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_008f3584(0,0,s_Value_00a20198);
    }
    *(int *)(*(int *)(iVar1 + 0x20) + 0xc) = iVar3;
    if (iVar3 == 0) {
      return 0;
    }
    if (param_3 != 0) {
      if ((local_18 == piVar4) || (iVar3 = FUN_008c9fec(local_18,piVar4), iVar3 != 0)) {
        uVar2 = FUN_008f352c(param_3);
      }
      else {
        uVar2 = FUN_008cedc3(piVar4,param_3,0,0);
      }
      *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x20) + 0xc) + 8) = uVar2;
      if (*(int *)(*(int *)(*(int *)(iVar1 + 0x20) + 0xc) + 8) == 0) {
        return 0;
      }
    }
    FUN_008ca999(iVar1);
    FUN_008ca999(local_c);
    return local_c;
  }
LAB_008cf0b9:
  FUN_008c98fa();
  return 0;
}


// ==== FUN_008cf35c @ 0x008cf35c ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008cf35c(undefined4 *param_1,int param_2)

{
  uint *puVar1;
  float10 fVar2;
  double dVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  undefined4 extraout_EAX;
  undefined4 *puVar10;
  uint uVar11;
  uint uVar12;
  double *pdVar13;
  bool bVar14;
  byte bVar15;
  float10 fVar16;
  undefined8 uVar17;
  uint local_2c;
  uint local_28;
  uint local_24;
  undefined8 local_20;
  undefined8 local_18;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined4 local_8;
  
  iVar9 = (int)param_1;
  if ((param_1 == (undefined4 *)0x0) || (*(int *)((int)param_1 + 4) != 0xd)) {
    return 0x80004005;
  }
  uVar12 = *(int *)((int)param_1 + 0x18) * *(int *)((int)param_1 + 0x14);
  uVar4 = FUN_008ca65c(*(undefined4 *)((int)param_1 + 0x10),param_2);
  uVar8 = (uint)local_18;
  if (uVar12 != uVar4) {
    return 0x80004005;
  }
  iVar5 = *(int *)((int)param_1 + 0x1c);
  if (1 < iVar5) {
    if (iVar5 < 4) {
      return 0x80004005;
    }
    if (0x13 < iVar5) {
      if (iVar5 < 0x16) {
        return 0x80004005;
      }
      if (iVar5 == 0x19) {
        return 0x80004005;
      }
      if (iVar5 == 0x1a) {
        uVar6 = FUN_008cd20f(param_1,param_2);
        return uVar6;
      }
      if (iVar5 == 0x1b) {
        return 0x80004005;
      }
    }
  }
  uVar4 = *(uint *)((int)param_1 + 0x20);
  local_2c = 0;
  local_20 = (double)(ulonglong)(uint)local_20;
  local_c = (undefined4 *)0x0;
  local_10 = (undefined4 *)0x0;
  local_18 = (double)(ulonglong)(uint)local_18;
  local_24 = 0;
  uVar11 = 0;
  if ((uVar4 != 0) && (*(int *)(uVar4 + 4) == 0xd)) {
    iVar5 = *(int *)(uVar4 + 0x18) * *(int *)(uVar4 + 0x14);
    local_18 = (double)CONCAT44(iVar5,uVar8);
    local_2c = uVar4;
    local_c = operator_new(iVar5 * 0x10);
    uVar11 = uVar4;
    if (local_c == (undefined4 *)0x0) goto switchD_008cf9c3_default;
  }
  uVar8 = *(uint *)((int)param_1 + 0x24);
  uVar4 = 0;
  if ((uVar8 != 0) && (*(int *)(uVar8 + 4) == 0xd)) {
    local_24 = *(int *)(uVar8 + 0x18) * *(int *)(uVar8 + 0x14);
    local_20 = (double)CONCAT44(uVar8,(uint)local_20);
    local_10 = operator_new(local_24 * 0x10);
    uVar4 = uVar8;
    if (local_10 == (undefined4 *)0x0) goto switchD_008cf9c3_default;
  }
  if (*(int *)((int)param_1 + 0x28) == 0) {
    uVar8 = uVar11;
    if ((uVar4 != 0) && (iVar5 = FUN_008cf35c(), iVar5 < 0)) goto switchD_008cf9c3_default;
  }
  else {
    uVar8 = uVar4;
    if (uVar11 != 0) {
      iVar5 = FUN_008cf35c();
      if (iVar5 < 0) goto switchD_008cf9c3_default;
      uVar8 = local_20._4_4_;
    }
  }
  if ((uVar8 != 0) && (iVar5 = FUN_008cf35c(), iVar5 < 0)) goto switchD_008cf9c3_default;
  puVar10 = local_c;
  iVar5 = *(int *)((int)param_1 + 0x1c);
  if (-1 < iVar5) {
    if (iVar5 < 2) {
      if (uVar11 == 0) {
        iVar9 = *(int *)((int)param_1 + 0x20);
        if (iVar9 != 0) {
          if (*(int *)(iVar9 + 4) == 0xe) {
            if (*(int *)(iVar9 + 0x10) != 6) {
              FUN_008ccdba(param_2,(int *)(iVar9 + 0x10),(int)param_1 + 0x30);
            }
          }
          else if ((iVar9 != 0) && (*(int *)(iVar9 + 4) == 1)) {
            do {
              iVar5 = *(int *)(iVar9 + 8);
              if (iVar5 != 0) {
                if (*(int *)(iVar5 + 4) == 0xe) {
                  if ((*(int *)(iVar5 + 0x10) == 6) ||
                     (iVar5 = FUN_008ccdba(param_2,(int *)(iVar5 + 0x10),(int)param_1 + 0x30),
                     iVar5 < 0)) break;
                  param_2 = param_2 + 0x10;
                }
                else if ((iVar5 != 0) && (*(int *)(iVar5 + 4) == 0xd)) {
                  iVar5 = FUN_008cf35c();
                  if (iVar5 < 0) break;
                  param_2 = param_2 + *(int *)(*(int *)(iVar9 + 8) + 0x18) *
                                      *(int *)(*(int *)(iVar9 + 8) + 0x14) * 0x10;
                }
              }
              iVar9 = *(int *)(iVar9 + 0xc);
            } while (iVar9 != 0);
          }
        }
      }
      else if (local_18._4_4_ == 1) {
        local_24 = 0;
        if (uVar12 != 0) {
          do {
            iVar9 = FUN_008ccdba(param_2,local_c,(int)param_1 + 0x30);
            if (iVar9 < 0) break;
            local_24 = local_24 + 1;
            param_2 = param_2 + 0x10;
          } while (local_24 < uVar12);
        }
      }
      else if (((uVar12 == local_18._4_4_) ||
               (puVar1 = (uint *)((int)param_1 + 0x14), *(uint *)(uVar11 + 0x14) < *puVar1)) ||
              (uVar8 = *(uint *)((int)param_1 + 0x18), *(uint *)(uVar11 + 0x18) < uVar8)) {
        local_24 = 0;
        if (uVar12 != 0) {
          local_20 = (double)CONCAT44((int)param_1 + 0x30,(uint)local_20);
          iVar9 = param_2;
          do {
            iVar5 = FUN_008ccdba(iVar9,(int)puVar10 + (iVar9 - param_2),local_20._4_4_);
            if (iVar5 < 0) break;
            local_24 = local_24 + 1;
            iVar9 = iVar9 + 0x10;
          } while (local_24 < uVar12);
        }
      }
      else {
        param_1 = (undefined4 *)0x0;
        if (*puVar1 != 0) {
          do {
            uVar4 = 0;
            if (uVar8 != 0) {
              do {
                iVar5 = FUN_008ccdba((uVar8 * (int)param_1 + uVar4) * 0x10 + param_2,
                                     local_c + (*(int *)(local_2c + 0x18) * (int)param_1 + uVar4) *
                                               4,iVar9 + 0x30);
                if (iVar5 < 0) goto switchD_008cf9c3_default;
                uVar8 = *(uint *)(iVar9 + 0x18);
                uVar4 = uVar4 + 1;
              } while (uVar4 < uVar8);
            }
            param_1 = (undefined4 *)((int)param_1 + 1);
          } while (param_1 < *(uint *)(iVar9 + 0x14));
        }
      }
      goto switchD_008cf9c3_default;
    }
    if (iVar5 == 0x16) {
      iVar5 = (int)param_1 + 0x30;
      local_20 = (double)CONCAT44(iVar5,(uint)local_20);
      iVar9 = FUN_008ccef6(&local_2c,local_10,iVar5);
      if (-1 < iVar9) {
        if (local_2c * uVar12 < local_18._4_4_) {
          local_24 = 0;
          if (uVar12 != 0) {
            puVar10 = local_c + local_2c * uVar12 * 4;
            do {
              iVar9 = FUN_008ccdba(param_2,puVar10,local_20._4_4_);
              if (iVar9 < 0) break;
              local_24 = local_24 + 1;
              puVar10 = puVar10 + 4;
              param_2 = param_2 + 0x10;
            } while (local_24 < uVar12);
          }
        }
        else {
          FUN_008c98fa(local_8,iVar5,0xbd6,s_array_index_out_of_bounds_00a204dc);
        }
      }
      goto switchD_008cf9c3_default;
    }
    if (iVar5 == 0x17) {
      iVar9 = *(int *)((int)param_1 + 0x24);
      if (*(int *)(iVar9 + 4) == 0xe) {
        iVar9 = FUN_008ccef6(&local_2c,iVar9 + 0x10,(int)param_1 + 0x30);
        if ((-1 < iVar9) && (local_24 = 0, uVar12 != 0)) {
          puVar10 = local_c + local_2c * 4;
          do {
            iVar9 = FUN_008ccdba(param_2,puVar10,(int)param_1 + 0x30);
            if (iVar9 < 0) break;
            local_24 = local_24 + 1;
            param_2 = param_2 + 0x10;
            puVar10 = puVar10 + 4;
          } while (local_24 < uVar12);
        }
      }
      else if ((*(int *)(iVar9 + 4) == 1) && (local_24 = 0, uVar12 != 0)) {
        do {
          iVar5 = FUN_008ccef6(&local_2c,*(int *)(iVar9 + 8) + 0x10,(int)param_1 + 0x30);
          if ((iVar5 < 0) ||
             (iVar5 = FUN_008ccdba(param_2,local_c + local_2c * 4,(int)param_1 + 0x30), iVar5 < 0))
          break;
          local_24 = local_24 + 1;
          param_2 = param_2 + 0x10;
          iVar9 = *(int *)(iVar9 + 0xc);
        } while (local_24 < uVar12);
      }
      goto switchD_008cf9c3_default;
    }
    if (iVar5 == 0x18) {
      local_24 = 0;
      if (local_18._4_4_ != 0) {
        iVar9 = (int)param_1 + 0x30;
        param_1 = local_10 + uVar12 * 4;
        local_2c = (int)local_c - (int)local_10;
        local_28 = param_2 - (int)local_10;
        puVar10 = local_10;
        do {
          iVar5 = FUN_008ca7a1(&local_20,local_2c + (int)puVar10,iVar9);
          if (iVar5 < 0) break;
          puVar7 = puVar10;
          if (local_20 == _DAT_0099d098) {
            puVar7 = param_1;
          }
          iVar5 = FUN_008ccdba(local_28 + (int)puVar10,puVar7,iVar9);
          if (iVar5 < 0) break;
          local_24 = local_24 + 1;
          param_1 = param_1 + 4;
          puVar10 = puVar10 + 4;
        } while (local_24 < local_18._4_4_);
      }
      goto switchD_008cf9c3_default;
    }
  }
  local_28 = 0;
  if (local_18._4_4_ != 0) {
    do {
      uVar17 = FUN_008ca7a1(puVar10 + 2,puVar10,(int)param_1 + 0x30);
      puVar10 = (undefined4 *)((ulonglong)uVar17 >> 0x20);
      if ((int)uVar17 < 0) goto switchD_008cf9c3_default;
      local_28 = local_28 + 1;
      *puVar10 = 3;
      puVar10 = puVar10 + 4;
    } while (local_28 < local_18._4_4_);
  }
  local_28 = 0;
  if (local_24 != 0) {
    puVar10 = local_10;
    do {
      uVar17 = FUN_008ca7a1(puVar10 + 2,puVar10,(int)param_1 + 0x30);
      puVar10 = (undefined4 *)((ulonglong)uVar17 >> 0x20);
      if ((int)uVar17 < 0) goto switchD_008cf9c3_default;
      local_28 = local_28 + 1;
      *puVar10 = 3;
      puVar10 = puVar10 + 4;
    } while (local_28 < local_24);
    uVar11 = local_2c;
  }
  if (((uVar11 == 0) || (local_18._4_4_ == uVar12)) &&
     ((local_20._4_4_ == 0 || (local_24 == uVar12)))) {
    local_24 = 0;
    if (uVar12 != 0) {
      local_2c = (int)local_c - (int)local_10;
      local_28 = param_2 - (int)local_10;
      pdVar13 = (double *)(local_10 + 2);
      do {
        if (local_c == (undefined4 *)0x0) {
          fVar16 = (float10)0;
        }
        else {
          fVar16 = (float10)*(double *)((int)pdVar13 + local_2c);
        }
        local_18 = (double)fVar16;
        if (local_10 == (undefined4 *)0x0) {
          local_20 = 0.0;
        }
        else {
          local_20 = *pdVar13;
        }
        switch(*(undefined4 *)((int)param_1 + 0x1c)) {
        case 4:
          dVar3 = _DAT_0099d098;
          goto LAB_008cf9d0;
        case 5:
          fVar16 = -fVar16;
          break;
        case 6:
          break;
        case 7:
          fVar16 = fVar16 * (float10)local_20;
          break;
        case 8:
          if (_DAT_0099d098 == local_20) {
            FUN_008c98fa(local_8,(int)param_1 + 0x30,0xbd9,s__division_by_zero_00a201e7 + 1);
            fVar16 = (float10)local_18;
          }
          fVar16 = fVar16 / (float10)local_20;
          break;
        case 9:
          if (_DAT_0099d098 == local_20) {
            FUN_008c98fa(local_8,(int)param_1 + 0x30,0xbd9,s__division_by_zero_00a201e7 + 1);
          }
          fVar16 = (float10)FUN_0080462a();
          break;
        case 10:
          fVar16 = fVar16 + (float10)local_20;
          break;
        case 0xb:
          fVar16 = fVar16 - (float10)local_20;
          break;
        case 0xc:
          bVar14 = (float10)local_20 <= fVar16;
          goto LAB_008cf9db;
        case 0xd:
          bVar14 = (float10)local_20 < fVar16;
          goto LAB_008cfaa0;
        case 0xe:
          fVar2 = (float10)local_20;
          bVar14 = (NAN(fVar16) || NAN(fVar2)) || fVar16 < fVar2 == (fVar16 == fVar2);
          goto LAB_008cf9db;
        case 0xf:
          bVar14 = (float10)local_20 <= fVar16;
LAB_008cfaa0:
          if (bVar14) goto LAB_008cfafc;
          goto LAB_008cf9e1;
        case 0x10:
          dVar3 = local_20;
LAB_008cf9d0:
          bVar14 = fVar16 != (float10)dVar3;
LAB_008cf9db:
          if (bVar14) {
LAB_008cf9e1:
            fVar16 = (float10)0;
          }
          else {
LAB_008cfafc:
            fVar16 = (float10)1;
          }
          break;
        case 0x11:
          bVar15 = (byte)((ushort)((ushort)(NAN(fVar16) || NAN((float10)local_20)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar16 == (float10)local_20) << 0xe) >> 8);
LAB_008cfaf1:
          if ((POPCOUNT(bVar15) & 1U) != 0) goto LAB_008cf9e1;
          goto LAB_008cfafc;
        case 0x12:
          if (fVar16 != (float10)_DAT_0099d098) {
LAB_008cfae6:
            bVar15 = (byte)((ushort)((ushort)(NAN(local_20) || NAN(_DAT_0099d098)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(local_20 == _DAT_0099d098) << 0xe) >> 8);
            goto LAB_008cfaf1;
          }
          goto LAB_008cf9e1;
        case 0x13:
          if (fVar16 == (float10)_DAT_0099d098) goto LAB_008cfae6;
          goto LAB_008cfafc;
        default:
          goto switchD_008cf9c3_default;
        }
        local_24 = local_24 + 1;
        *(double *)((int)pdVar13 + local_28) = (double)fVar16;
        pdVar13 = pdVar13 + 2;
      } while (local_24 < uVar12);
    }
    local_2c = 0;
    if (uVar12 != 0) {
      do {
        iVar9 = FUN_008ccf55(param_2,*(undefined8 *)(param_2 + 8),(int)param_1 + 0x30);
        if (iVar9 < 0) break;
        local_2c = local_2c + 1;
        param_2 = param_2 + 0x10;
      } while (local_2c < uVar12);
    }
  }
switchD_008cf9c3_default:
  _free(local_10);
  return extraout_EAX;
}


// ==== FUN_008cfbb9 @ 0x008cfbb9 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_008cfbb9(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined1 local_1c [16];
  double local_c;
  
  if (param_1 != (int *)0x0) {
    if ((param_1[6] * param_1[5] == 1) && (iVar1 = FUN_008c9ee7(param_1[4]), iVar1 != 0)) {
      iVar1 = FUN_008ca87b(param_1);
      if (((iVar1 != 0) && (iVar1 = FUN_008cf35c(param_1,local_1c), -1 < iVar1)) &&
         (iVar1 = FUN_008ca7a1(&local_c,local_1c,param_1 + 0xc), -1 < iVar1)) {
        if (_DAT_0099d098 == local_c) {
          param_2 = param_3;
        }
        iVar1 = FUN_008f352c(param_2);
        return iVar1;
      }
      iVar1 = FUN_008bf738(0x24);
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_008f3da4();
      }
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x10) = 2;
        iVar2 = (**(code **)(*param_1 + 4))();
        *(int *)(iVar1 + 0x18) = iVar2;
        if (iVar2 != 0) {
          if (param_2 != (int *)0x0) {
            iVar2 = (**(code **)(*param_2 + 4))();
            *(int *)(iVar1 + 0x1c) = iVar2;
            if (iVar2 == 0) {
              return 0;
            }
          }
          if (param_3 != (int *)0x0) {
            iVar2 = (**(code **)(*param_3 + 4))();
            *(int *)(iVar1 + 0x20) = iVar2;
            if (iVar2 == 0) {
              return 0;
            }
          }
          iVar2 = FUN_008bf738(0x14);
          if (iVar2 == 0) {
            iVar1 = 0;
          }
          else {
            iVar1 = FUN_008f3584(iVar1,0,s_Stmts_00a1fda0);
          }
          if (iVar1 != 0) {
            return iVar1;
          }
        }
      }
    }
    else {
      FUN_008c98fa();
    }
  }
  return 0;
}


// ==== FUN_008cfce0 @ 0x008cfce0 ====

int FUN_008cfce0(void)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  
  do {
    iVar4 = FUN_008c1674((undefined4 *)(in_ECX + 0x20));
    if (iVar4 < 0) {
      *(undefined4 *)(in_ECX + 0x40) = 1;
      return -1;
    }
    switch(*(undefined4 *)(in_ECX + 0x20)) {
    case 0:
      goto LAB_008cfd09;
    case 1:
      cVar1 = *(char *)(in_ECX + 0x29);
      if (cVar1 == '\0') {
        return (int)*(char *)(in_ECX + 0x28);
      }
      if (*(char *)(in_ECX + 0x2a) != '\0') {
        return 0x151;
      }
      if (cVar1 != '=') {
        cVar2 = *(char *)(in_ECX + 0x28);
        if (cVar2 != cVar1) {
          return 0x151;
        }
        if (cVar2 == '&') {
          return 0x140;
        }
        if (cVar2 == '+') {
          return 0x13a;
        }
        if (cVar2 == '-') {
          return 0x13b;
        }
        if (cVar2 == '|') {
          return 0x141;
        }
        return 0x151;
      }
      cVar1 = *(char *)(in_ECX + 0x28);
      if ('-' < cVar1) {
        if (cVar1 == '/') {
          return 0x143;
        }
        if (cVar1 == '<') {
          return 0x13c;
        }
        if (cVar1 == '=') {
          return 0x13e;
        }
        if (cVar1 == '>') {
          return 0x13d;
        }
        return 0x151;
      }
      if (cVar1 == '-') {
        return 0x146;
      }
      if (cVar1 == '!') {
        return 0x13f;
      }
      if (cVar1 == '%') {
        return 0x144;
      }
      if (cVar1 == '*') {
        return 0x142;
      }
      if (cVar1 == '+') {
        return 0x145;
      }
      return 0x151;
    case 2:
      return 0x147;
    case 3:
      return 0x148;
    case 4:
      return 0x149;
    case 5:
      return 0x14a;
    case 6:
      return 0x14b;
    case 7:
      return 0x14c;
    case 8:
      return 0x14d;
    case 9:
      pcVar3 = *(char **)(in_ECX + 0x28);
      switch((int)*pcVar3) {
      case 0x61:
        iVar4 = 5;
        bVar8 = true;
        pcVar7 = pcVar3;
        pcVar6 = &DAT_00a2070c;
        goto code_r0x008cfe77;
      case 0x62:
        iVar4 = 5;
        bVar8 = true;
        pcVar7 = pcVar3;
        pcVar6 = (char *)&DAT_00a1fee0;
        goto code_r0x008cfea9;
      case 99:
        iVar4 = 5;
        bVar8 = true;
        pcVar7 = pcVar3;
        pcVar6 = &DAT_00a206f4;
        goto code_r0x008cfedc;
      case 100:
        iVar4 = 8;
        bVar8 = true;
        pcVar7 = pcVar3;
        pcVar6 = s_default_00a17a04;
        goto code_r0x008cffb2;
      case 0x65:
        iVar4 = 5;
        bVar8 = true;
        pcVar7 = pcVar3;
        pcVar6 = &DAT_009fe7a4;
        goto code_r0x008d008e;
      case 0x66:
        iVar4 = 6;
        bVar8 = true;
        pcVar7 = pcVar3;
        pcVar6 = s_false_009fde34;
        goto code_r0x008d00ee;
      case 0x67:
        pcVar7 = &DAT_00a20650;
        break;
      case 0x68:
        iVar4 = 5;
        bVar8 = true;
        pcVar7 = pcVar3;
        pcVar6 = (char *)&DAT_00a1fed8;
        goto code_r0x008d0152;
      case 0x69:
        iVar4 = 3;
        bVar8 = true;
        pcVar7 = pcVar3;
        pcVar6 = &DAT_009fe794;
        goto code_r0x008d0170;
      default:
        goto switchD_008cfe64_caseD_6a;
      case 0x6c:
        pcVar7 = &DAT_00a20638;
        break;
      case 0x6d:
        iVar4 = 7;
        bVar8 = true;
        pcVar7 = pcVar3;
        pcVar6 = s_matrix_00a202b4;
        goto code_r0x008d0202;
      case 0x6e:
        iVar4 = 10;
        bVar8 = true;
        pcVar7 = pcVar3;
        pcVar6 = s_namespace_00a20624;
        goto code_r0x008d0228;
      case 0x6f:
        iVar4 = 4;
        bVar8 = true;
        pcVar7 = pcVar3;
        pcVar6 = &DAT_00a20620;
        goto code_r0x008d0248;
      case 0x70:
        iVar4 = 0xe;
        bVar8 = true;
        pcVar7 = pcVar3;
        pcVar6 = s_pixelfragment_00a1fe2c;
        goto code_r0x008d026e;
      case 0x72:
        iVar4 = 9;
        bVar8 = true;
        pcVar7 = pcVar3;
        pcVar6 = s_register_00a205ec;
        goto code_r0x008d02eb;
      case 0x73:
        iVar4 = 10;
        bVar8 = true;
        pcVar7 = pcVar3;
        pcVar6 = s_sampler1D_00a1fe7c;
        goto code_r0x008d0351;
      case 0x74:
        iVar4 = 9;
        bVar8 = true;
        pcVar7 = pcVar3;
        pcVar6 = s_template_00a20564;
        goto code_r0x008d04f9;
      case 0x75:
        iVar4 = 8;
        bVar8 = true;
        pcVar7 = pcVar3;
        pcVar6 = s_uniform_00a20534;
        goto code_r0x008d0620;
      case 0x76:
        iVar4 = 7;
        bVar8 = true;
        pcVar7 = pcVar3;
        pcVar6 = s_vector_00a202bc;
        goto code_r0x008d0664;
      case 0x77:
        iVar4 = 6;
        bVar8 = true;
        pcVar7 = pcVar3;
        pcVar6 = s_while_009fe768;
        goto code_r0x008d070e;
      }
      iVar4 = 5;
      goto LAB_008cfebe;
    case 10:
      return 0x14e;
    case 0xd:
      return -1;
    }
  } while( true );
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
    if (!bVar8) break;
code_r0x008d070e:
    if (iVar4 == 0) break;
  }
  if (bVar8) {
    return 0x139;
  }
  goto switchD_008cfe64_caseD_6a;
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
    if (!bVar8) break;
code_r0x008d0664:
    if (iVar4 == 0) break;
  }
  if (bVar8) {
    return 0x134;
  }
  iVar4 = 0xf;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_vertexfragment_00a1fe1c;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x135;
  }
  iVar4 = 8;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_virtual_00a20510;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  iVar4 = 5;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = &DAT_00a1fef8;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x137;
  }
  iVar4 = 9;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_volatile_00a20504;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x138;
  }
  if (*(int *)(in_ECX + 0x48) != 0) {
    iVar4 = 0xd;
    bVar8 = true;
    pcVar7 = pcVar3;
    pcVar6 = s_vertexshader_00a1fe3c;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar8 = *pcVar7 == *pcVar6;
      pcVar7 = pcVar7 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar8);
    if (bVar8) {
      return 0x136;
    }
  }
  goto switchD_008cfe64_caseD_6a;
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
    if (!bVar8) break;
code_r0x008d0620:
    if (iVar4 == 0) break;
  }
  if (bVar8) {
    return 0x133;
  }
  iVar4 = 6;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_union_00a2052c;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  iVar4 = 9;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_unsigned_00a20520;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  pcVar7 = s_using_00a20518;
  goto LAB_008cfebc;
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
    if (!bVar8) break;
code_r0x008d04f9:
    if (iVar4 == 0) break;
  }
  if (bVar8) {
    return 0x151;
  }
  iVar4 = 10;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_texture1D_00a1feb4;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x12d;
  }
  iVar4 = 10;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_texture2D_00a1fea8;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x12e;
  }
  iVar4 = 10;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_texture3D_00a1fe9c;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x12f;
  }
  iVar4 = 0xc;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_textureCUBE_00a1fe90;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x130;
  }
  iVar4 = 5;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = &DAT_00a2055c;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  iVar4 = 6;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_throw_00a20554;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  iVar4 = 5;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = &DAT_009fde3c;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x131;
  }
  iVar4 = 4;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = &DAT_00a20550;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  iVar4 = 8;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_typedef_00a20548;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x132;
  }
  iVar4 = 9;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_typename_00a2053c;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  if (*(int *)(in_ECX + 0x48) != 0) {
    iVar4 = 8;
    bVar8 = true;
    pcVar7 = pcVar3;
    pcVar6 = s_texture_00a1fec0;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar8 = *pcVar7 == *pcVar6;
      pcVar7 = pcVar7 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar8);
    if (bVar8) {
      return 300;
    }
  }
  goto switchD_008cfe64_caseD_6a;
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
    if (!bVar8) break;
code_r0x008d0351:
    if (iVar4 == 0) break;
  }
  if (bVar8) {
    return 0x120;
  }
  iVar4 = 10;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_sampler2D_00a1fe70;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x121;
  }
  iVar4 = 10;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_sampler3D_00a1fe64;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x122;
  }
  iVar4 = 0xc;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_samplerCUBE_00a1fe58;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x123;
  }
  iVar4 = 0xe;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_sampler_state_00a205c8;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x124;
  }
  iVar4 = 7;
  bVar8 = true;
  iVar5 = iVar4;
  pcVar7 = pcVar3;
  pcVar6 = s_shared_00a205c0;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x125;
  }
  iVar5 = 6;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_short_00a205b8;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  bVar8 = true;
  iVar5 = iVar4;
  pcVar7 = pcVar3;
  pcVar6 = s_signed_00a205b0;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  bVar8 = true;
  iVar5 = iVar4;
  pcVar7 = pcVar3;
  pcVar6 = s_sizeof_00a205a8;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  iVar5 = 0x11;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_stateblock_state_00a20594;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x127;
  }
  bVar8 = true;
  iVar5 = iVar4;
  pcVar7 = pcVar3;
  pcVar6 = s_static_00a2058c;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x128;
  }
  iVar5 = 0xc;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_static_cast_00a20580;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  bVar8 = true;
  iVar5 = iVar4;
  pcVar7 = pcVar3;
  pcVar6 = s_string_009fd520;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x129;
  }
  bVar8 = true;
  iVar5 = iVar4;
  pcVar7 = pcVar3;
  pcVar6 = s_struct_00a20578;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x12a;
  }
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_switch_00a20570;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  if (*(int *)(in_ECX + 0x48) != 0) {
    iVar4 = 8;
    bVar8 = true;
    pcVar7 = pcVar3;
    pcVar6 = s_sampler_00a1fe88;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar8 = *pcVar7 == *pcVar6;
      pcVar7 = pcVar7 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar8);
    if (bVar8) {
      return 0x11f;
    }
    iVar4 = 0xb;
    bVar8 = true;
    pcVar7 = pcVar3;
    pcVar6 = s_stateblock_00a1fe10;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar8 = *pcVar7 == *pcVar6;
      pcVar7 = pcVar7 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar8);
    if (bVar8) {
      return 0x126;
    }
  }
  goto switchD_008cfe64_caseD_6a;
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
    if (!bVar8) break;
code_r0x008d02eb:
    if (iVar4 == 0) break;
  }
  if (bVar8) {
    return 0x11c;
  }
  iVar4 = 0x11;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_reinterpret_cast_00a205d8;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  iVar4 = 10;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_row_major_00a179f0;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x11e;
  }
  iVar4 = 7;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_return_009fcf70;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x11d;
  }
  goto switchD_008cfe64_caseD_6a;
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
    if (!bVar8) break;
code_r0x008d026e:
    if (iVar4 == 0) break;
  }
  if (bVar8) {
    return 0x11a;
  }
  iVar4 = 8;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_private_00a2060c;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  iVar4 = 10;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_protected_00a20600;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  iVar4 = 7;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_public_00a205f8;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  if (*(int *)(in_ECX + 0x48) != 0) {
    iVar4 = 0xc;
    bVar8 = true;
    pcVar7 = pcVar3;
    pcVar6 = s_pixelshader_00a1fe4c;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar8 = *pcVar7 == *pcVar6;
      pcVar7 = pcVar7 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar8);
    if (bVar8) {
      return 0x11b;
    }
  }
  goto switchD_008cfe64_caseD_6a;
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
    if (!bVar8) break;
code_r0x008d0248:
    if (iVar4 == 0) break;
  }
  if (bVar8) {
    return 0x118;
  }
  pcVar7 = s_operator_00a20614;
  goto LAB_008d025b;
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
    if (!bVar8) break;
code_r0x008d0228:
    if (iVar4 == 0) break;
  }
  if (bVar8) {
    return 0x151;
  }
  iVar4 = 4;
  pcVar7 = (char *)&PTR_LAB_00a01d14;
  goto LAB_008cfebe;
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
    if (!bVar8) break;
code_r0x008d0202:
    if (iVar4 == 0) break;
  }
  if (bVar8) {
    return 0x117;
  }
  pcVar7 = s_mutable_00a20630;
  iVar4 = 8;
  goto LAB_008cfebe;
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
    if (!bVar8) break;
code_r0x008d0170:
    if (iVar4 == 0) break;
  }
  if (bVar8) {
    return 0x112;
  }
  iVar4 = 3;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = &DAT_009fe790;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x113;
  }
  iVar4 = 7;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_inline_00a20648;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x114;
  }
  iVar4 = 6;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_inout_00a20640;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x115;
  }
  iVar4 = 4;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = &DAT_009febf0;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x116;
  }
  goto switchD_008cfe64_caseD_6a;
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
    if (!bVar8) break;
code_r0x008d0152:
    if (iVar4 == 0) break;
  }
  if (bVar8) {
    return 0x111;
  }
  goto switchD_008cfe64_caseD_6a;
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
    if (!bVar8) break;
code_r0x008d00ee:
    if (iVar4 == 0) break;
  }
  if (bVar8) {
    return 0x10e;
  }
  iVar4 = 6;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_float_00a1fed0;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x10f;
  }
  iVar4 = 4;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = &DAT_009fe798;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x110;
  }
  pcVar7 = s_friend_00a20658;
  iVar4 = 7;
  goto LAB_008cfebe;
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
    if (!bVar8) break;
code_r0x008d008e:
    if (iVar4 == 0) break;
  }
  if (bVar8) {
    return 0x10c;
  }
  iVar4 = 5;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = &DAT_00a20674;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  iVar4 = 9;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_explicit_00a20668;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  iVar4 = 7;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_extern_00a20660;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x10d;
  }
  goto switchD_008cfe64_caseD_6a;
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
    if (!bVar8) break;
code_r0x008cffb2:
    if (iVar4 == 0) break;
  }
  if (bVar8) {
    return 0x151;
  }
  iVar4 = 7;
  bVar8 = true;
  iVar5 = iVar4;
  pcVar7 = pcVar3;
  pcVar6 = s_delete_00a206a0;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  iVar5 = 8;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_discard_00a20698;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x109;
  }
  iVar5 = 3;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = &DAT_009fe7ac;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x10b;
  }
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_double_00a1fec8;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x10a;
  }
  iVar4 = 0xd;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_dynamic_cast_00a20688;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  goto joined_r0x008d002b;
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
    if (!bVar8) break;
code_r0x008cfedc:
    if (iVar4 == 0) break;
  }
  if (bVar8) {
    return 0x151;
  }
  iVar4 = 6;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_catch_00a206ec;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  iVar4 = 5;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = &DAT_009fd32c;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  iVar4 = 6;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_class_00a206e4;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  iVar4 = 0xd;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_column_major_00a179e0;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x104;
  }
  iVar4 = 8;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_compile_00a206dc;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x105;
  }
  iVar4 = 0x11;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_compile_fragment_00a206c8;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x106;
  }
  iVar4 = 6;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_const_00a206c0;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x107;
  }
  iVar4 = 0xb;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_const_cast_00a206b4;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x151;
  }
  pcVar7 = s_continue_00a206a8;
LAB_008d025b:
  iVar4 = 9;
  goto LAB_008cfebe;
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
    if (!bVar8) break;
code_r0x008cfea9:
    if (iVar4 == 0) break;
  }
  if (bVar8) {
    return 0x103;
  }
  pcVar7 = s_break_009fe7b0;
LAB_008cfebc:
  iVar4 = 6;
LAB_008cfebe:
  bVar8 = true;
  pcVar6 = pcVar3;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar6 == *pcVar7;
    pcVar6 = pcVar6 + 1;
    pcVar7 = (char *)((int)pcVar7 + 1);
  } while (bVar8);
joined_r0x008d002b:
  if (bVar8) {
    return 0x151;
  }
  goto switchD_008cfe64_caseD_6a;
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
    if (!bVar8) break;
code_r0x008cfe77:
    if (iVar4 == 0) break;
  }
  if (bVar8) {
LAB_008cfd09:
    return 0x151;
  }
  iVar4 = 0xd;
  bVar8 = true;
  pcVar7 = pcVar3;
  pcVar6 = s_asm_fragment_00a206fc;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar7 == *pcVar6;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0x102;
  }
switchD_008cfe64_caseD_6a:
  iVar4 = _tolower((int)*pcVar3);
  if (iVar4 == 0x61) {
    iVar4 = __stricmp(*(char **)(in_ECX + 0x28),&DAT_00a204f8);
    if (iVar4 == 0) {
      return 0x101;
    }
  }
  else if (iVar4 == 100) {
    iVar4 = __stricmp(*(char **)(in_ECX + 0x28),&DAT_00a204fc);
    if (iVar4 == 0) {
      return 0x108;
    }
  }
  else if (iVar4 == 0x70) {
    iVar4 = __stricmp(*(char **)(in_ECX + 0x28),&DAT_00a20278);
    if (iVar4 == 0) {
      return 0x119;
    }
  }
  else if ((iVar4 == 0x74) &&
          (iVar4 = __stricmp(*(char **)(in_ECX + 0x28),s_technique_00a2067c), iVar4 == 0)) {
    return 299;
  }
  iVar4 = FUN_008ce5ff(0,in_ECX + 0x20,0,0,*(undefined4 *)(in_ECX + 0x10),0,0,0);
  return (iVar4 != 0) + 0x14f;
}


