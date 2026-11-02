// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x7e0000-0x7effff

// ==== FUN_007e38a0 @ 0x007e38a0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_007e38a0(code *param_1,undefined4 param_2,int param_3,byte *param_4,double *param_5)

{
  byte *pbVar1;
  double dVar2;
  undefined1 uVar3;
  char *pcVar4;
  double dVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  char cVar11;
  byte bVar12;
  byte *pbVar13;
  uint uVar14;
  char *pcVar15;
  int extraout_ECX;
  int iVar16;
  int iVar17;
  uint uVar18;
  byte *pbVar19;
  int iVar20;
  undefined4 *puVar21;
  int *piVar22;
  bool bVar23;
  longlong lVar24;
  char cStack_429;
  byte bStack_428;
  byte *pbStack_424;
  byte *pbStack_420;
  byte *pbStack_418;
  byte *pbStack_410;
  int iStack_40c;
  undefined1 *puStack_408;
  byte *pbStack_404;
  byte bStack_3f8;
  undefined4 auStack_3f7 [249];
  byte abStack_11 [5];
  undefined4 local_c;
  
  local_c = DAT_00b49670;
  (*param_1)(param_2,&DAT_0099cf70,0);
  bVar12 = *param_4;
  pbStack_418 = (byte *)0x0;
  iStack_40c = 0;
  pbStack_420 = (byte *)0x0;
  do {
    if (bVar12 == 0) {
      return iStack_40c;
    }
    pbVar13 = param_4;
    if (bVar12 != 0x25) {
      iVar20 = 1;
      bVar12 = param_4[1];
      pbVar19 = param_4;
      while ((pbVar13 = pbVar19 + 1, bVar12 != 0x25 && (bVar23 = bVar12 != 0, bVar12 = 0, bVar23)))
      {
        iVar20 = iVar20 + 1;
        bVar12 = pbVar19[2];
        pbVar19 = pbVar13;
      }
      (*param_1)(param_2,param_4,iVar20);
      iStack_40c = iStack_40c + iVar20;
      pbStack_420 = param_4;
      if (bVar12 == 0) {
        return iStack_40c;
      }
    }
    iVar20 = (int)(char)pbVar13[1];
    param_4 = pbVar13 + 1;
    if (iVar20 == 0) {
      (*param_1)(param_2,&DAT_009fe618,1);
      return -1;
    }
    bVar7 = false;
    bVar8 = false;
    bVar6 = false;
    bVar23 = false;
    bVar9 = false;
    do {
      switch(iVar20) {
      case 0x20:
        bVar6 = true;
        break;
      default:
        if (iVar20 != 0) goto LAB_007e39a6;
        break;
      case 0x23:
        bVar8 = true;
        break;
      case 0x2b:
        bVar23 = true;
        break;
      case 0x2d:
        bVar9 = true;
        break;
      case 0x30:
        bVar7 = true;
      }
      iVar20 = (int)(char)param_4[1];
      param_4 = param_4 + 1;
    } while (iVar20 != 0);
LAB_007e39a6:
    pbVar13 = (byte *)0x0;
    pbStack_410 = (byte *)0x0;
    if (iVar20 == 0x2a) {
      pbStack_410 = *(byte **)param_5;
      param_5 = (double *)((int)param_5 + 4);
      if ((int)pbStack_410 < 0) {
        pbStack_410 = (byte *)-(int)pbStack_410;
        bVar9 = true;
      }
      iVar20 = (int)(char)param_4[1];
      param_4 = param_4 + 1;
LAB_007e39fc:
      if (0x3de < (int)pbStack_410) {
        pbStack_410 = (byte *)0x3de;
      }
    }
    else if (0x2f < iVar20) {
      do {
        if (0x39 < iVar20) break;
        param_4 = param_4 + 1;
        pbVar13 = (byte *)(iVar20 + -0x30 + (int)pbVar13 * 10);
        iVar20 = (int)(char)*param_4;
      } while (0x2f < iVar20);
      pbStack_410 = pbVar13;
      goto LAB_007e39fc;
    }
    if (iVar20 == 0x2e) {
      iVar20 = (int)(char)param_4[1];
      pbVar13 = (byte *)0x0;
      pbVar19 = param_4 + 1;
      pbStack_424 = (byte *)0x0;
      if (iVar20 == 0x2a) {
        pbStack_424 = *(byte **)param_5;
        param_5 = (double *)((int)param_5 + 4);
        if ((int)pbStack_424 < 0) {
          pbStack_424 = (byte *)-(int)pbStack_424;
        }
        iVar20 = (int)(char)param_4[2];
        pbVar19 = param_4 + 2;
      }
      else {
        param_4 = pbVar19;
        if (iVar20 < 0x30) goto LAB_007e3a6c;
        do {
          if (0x39 < iVar20) break;
          pbVar19 = pbVar19 + 1;
          pbVar13 = (byte *)(iVar20 + -0x30 + (int)pbVar13 * 10);
          iVar20 = (int)(char)*pbVar19;
        } while (0x2f < iVar20);
        pbStack_424 = pbVar13;
      }
      param_4 = pbVar19;
    }
    else {
      pbStack_424 = (byte *)0xffffffff;
    }
LAB_007e3a6c:
    pbVar13 = param_4;
    if (iVar20 == 0x6c) {
      iVar20 = (int)(char)param_4[1];
      pbVar13 = param_4 + 1;
      if (iVar20 != 0x6c) goto LAB_007e3aa1;
      iVar20 = (int)(char)param_4[2];
      param_4 = param_4 + 2;
      bVar10 = true;
    }
    else {
LAB_007e3aa1:
      param_4 = pbVar13;
      bVar10 = false;
    }
    uVar14 = 0;
    puStack_408 = (undefined1 *)0x0;
    cStack_429 = '\n';
    iVar16 = 0;
    do {
      if (iVar20 == (char)(&DAT_00a010d0)[uVar14]) {
        iVar16 = iVar16 * 6;
        puStack_408 = &DAT_00a010d0 + iVar16;
        if ((param_3 != 0) || (((&DAT_00a010d2)[iVar16] & 2) == 0)) {
          cStack_429 = (&DAT_00a010d3)[iVar16];
        }
        break;
      }
      uVar14 = uVar14 + 6;
      iVar16 = iVar16 + 1;
    } while (uVar14 < 0x7e);
    pbStack_404 = (byte *)0x0;
    if ((0x3c0 < (int)pbStack_424) && ((puStack_408[2] & 4) == 0)) {
      pbStack_424 = (byte *)0x3c0;
    }
    switch(cStack_429) {
    case '\x01':
      goto LAB_007e3b32;
    case '\x02':
    case '\x03':
    case '\x04':
      dVar2 = *param_5;
      param_5 = param_5 + 1;
      if ((int)pbStack_424 < 0) {
        pbStack_424 = (byte *)0x6;
      }
      else if (0x3de < (int)pbStack_424) {
        pbStack_424 = (byte *)0x3de;
      }
      if (_DAT_0099d098 <= dVar2) {
        if (bVar23) {
          bStack_428 = 0x2b;
        }
        else {
          bStack_428 = !bVar6 - 1U & 0x20;
        }
      }
      else {
        dVar2 = -dVar2;
        bStack_428 = 0x2d;
      }
      if ((puStack_408[3] == '\x04') && (0 < (int)pbStack_424)) {
        pbStack_424 = pbStack_424 + -1;
      }
      pbVar13 = pbStack_424;
      dVar5 = _DAT_00a011c0;
      if (7 < (int)pbStack_424) {
        iVar20 = ((uint)(pbStack_424 + -8) >> 3) + 1;
        pbVar13 = pbStack_424 + iVar20 * -8;
        do {
          iVar20 = iVar20 + -1;
          dVar5 = dVar5 * _DAT_00a011b8 * _DAT_00a011b8 * _DAT_00a011b8 * _DAT_00a011b8 *
                  _DAT_00a011b8 * _DAT_00a011b8 * _DAT_00a011b8 * _DAT_00a011b8;
        } while (iVar20 != 0);
      }
      if (0 < (int)pbVar13) {
        do {
          pbVar13 = pbVar13 + -1;
          dVar5 = dVar5 * _DAT_00a011b8;
        } while (pbVar13 != (byte *)0x0);
      }
      if (puStack_408[3] == '\x02') {
        dVar2 = dVar5 + dVar2;
      }
      iVar20 = 0;
      if (_DAT_0099d098 < dVar2) {
        for (; (_DAT_00a011b0 <= dVar2 && (iVar20 < 0x15f)); iVar20 = iVar20 + 8) {
          dVar2 = dVar2 * _DAT_0099d0a8;
        }
        for (; (_DAT_009fdca8 <= dVar2 && (iVar20 < 0x15f)); iVar20 = iVar20 + 1) {
          dVar2 = dVar2 * _DAT_00a011b8;
        }
        for (; (dVar2 < _DAT_0099d0a8 && (-0x15f < iVar20)); iVar20 = iVar20 + -8) {
          dVar2 = dVar2 * _DAT_00a011b0;
        }
        for (; (dVar2 < _DAT_0099d0a0 && (-0x15f < iVar20)); iVar20 = iVar20 + -1) {
          dVar2 = dVar2 * _DAT_009fdca8;
        }
        if ((0x15e < iVar20) || (iVar20 < -0x15e)) {
          pbStack_420 = &DAT_00a011a8;
          pbStack_418 = (byte *)0x3;
          break;
        }
      }
      bVar23 = cStack_429 == '\x03';
      pbVar13 = &bStack_3f8;
      if ((cStack_429 != '\x02') && (_DAT_009fdca8 <= dVar5 + dVar2)) {
        iVar20 = iVar20 + 1;
      }
      if (cStack_429 == '\x04') {
        bVar6 = !bVar8;
        if ((iVar20 < -4) || ((int)pbStack_424 < iVar20)) {
          cStack_429 = '\x03';
        }
        else {
          pbStack_424 = pbStack_424 + -iVar20;
          cStack_429 = '\x02';
        }
      }
      else {
        bVar6 = false;
      }
      pbStack_418 = (byte *)0x0;
      if ((cStack_429 == '\x02') && ((int)(pbStack_424 + iVar20) < 0x3ca)) {
        if ((0 < (int)pbStack_424) || (bVar23 = false, bVar8)) {
          bVar23 = true;
        }
        if (bStack_428 != 0) {
          bStack_3f8 = bStack_428;
          pbVar13 = (byte *)auStack_3f7;
        }
        if (iVar20 < 0) {
          *pbVar13 = 0x30;
          pbVar13 = pbVar13 + 1;
        }
        else {
          iVar16 = iVar20 + 1;
          iVar20 = iVar20 - iVar16;
          do {
            iVar17 = (int)pbStack_418 + 1;
            if ((int)pbStack_418 < 0x10) {
              cVar11 = FUN_00802534();
              bVar12 = cVar11 + 0x30;
            }
            else {
              bVar12 = 0x30;
            }
            *pbVar13 = bVar12;
            pbVar13 = pbVar13 + 1;
            iVar16 = iVar16 + -1;
            pbStack_418 = (byte *)iVar17;
          } while (iVar16 != 0);
        }
        if (bVar23) {
          *pbVar13 = 0x2e;
          pbVar13 = pbVar13 + 1;
        }
        iVar20 = iVar20 + 1;
        if (iVar20 < 0) {
          do {
            if ((int)pbStack_424 < 1) goto LAB_007e4009;
            *pbVar13 = 0x30;
            pbVar13 = pbVar13 + 1;
            pbStack_424 = pbStack_424 + -1;
            iVar20 = iVar20 + 1;
          } while (iVar20 < 0);
        }
        if (0 < (int)pbStack_424) {
          do {
            if ((int)pbStack_418 < 0x10) {
              cVar11 = FUN_00802534();
              bVar12 = cVar11 + 0x30;
            }
            else {
              bVar12 = 0x30;
            }
            *pbVar13 = bVar12;
            pbVar13 = pbVar13 + 1;
            pbStack_424 = pbStack_424 + -1;
            pbStack_418 = (byte *)((int)pbStack_418 + 1);
          } while (pbStack_424 != (byte *)0x0);
        }
LAB_007e4009:
        *pbVar13 = 0;
        pbVar13 = pbVar13 + -1;
        if (((bVar6) && (bVar23)) && (&bStack_3f8 <= pbVar13)) {
          do {
            if (*pbVar13 != 0x30) {
              if ((&bStack_3f8 <= pbVar13) && (*pbVar13 == 0x2e)) {
                *pbVar13 = 0;
                pbVar13 = pbVar13 + -1;
              }
              break;
            }
            *pbVar13 = 0;
            pbVar13 = pbVar13 + -1;
          } while (&bStack_3f8 <= pbVar13);
        }
LAB_007e4191:
        pbVar13 = pbVar13 + 1;
      }
      else {
        if ((0 < (int)pbStack_424) || (bVar10 = false, bVar8)) {
          bVar10 = true;
        }
        if (bStack_428 != 0) {
          bStack_3f8 = bStack_428;
          pbVar13 = (byte *)auStack_3f7;
        }
        cVar11 = FUN_00802534();
        *pbVar13 = cVar11 + 0x30;
        pbVar19 = pbVar13 + 1;
        if (bVar10) {
          *pbVar19 = 0x2e;
          pbVar19 = pbVar13 + 2;
        }
        if (0 < (int)pbStack_424) {
          pbStack_418 = pbStack_424;
          iVar16 = 1;
          do {
            if (iVar16 < 0x10) {
              cVar11 = FUN_00802534();
              bVar12 = cVar11 + 0x30;
            }
            else {
              bVar12 = 0x30;
            }
            *pbVar19 = bVar12;
            pbVar19 = pbVar19 + 1;
            pbStack_418 = pbStack_418 + -1;
            iVar16 = iVar16 + 1;
          } while (pbStack_418 != (byte *)0x0);
        }
        pbVar19 = pbVar19 + -1;
        if (((bVar6) && (bVar10)) && (&bStack_3f8 <= pbVar19)) {
          do {
            if (*pbVar19 != 0x30) {
              if ((&bStack_3f8 <= pbVar19) && (*pbVar19 == 0x2e)) {
                *pbVar19 = 0;
                pbVar19 = pbVar19 + -1;
              }
              break;
            }
            *pbVar19 = 0;
            pbVar19 = pbVar19 + -1;
          } while (&bStack_3f8 <= pbVar19);
        }
        pbVar13 = pbVar19 + 1;
        if ((iVar20 != 0) || (bVar23)) {
          *pbVar13 = s_0123456789ABCDEF0123456789abcdef_00a010a0[(byte)puStack_408[4]];
          if (iVar20 < 0) {
            pbVar19[2] = 0x2d;
            iVar20 = -iVar20;
          }
          else {
            pbVar19[2] = 0x2b;
          }
          pbVar13 = pbVar19 + 3;
          if (99 < iVar20) {
            iVar16 = iVar20 / 100;
            iVar20 = iVar20 % 100;
            *pbVar13 = (char)iVar16 + 0x30;
            pbVar13 = pbVar19 + 4;
          }
          *pbVar13 = (char)(iVar20 / 10) + 0x30;
          pbVar13 = pbVar13 + 1;
          *pbVar13 = (char)(iVar20 % 10) + 0x30;
          goto LAB_007e4191;
        }
      }
      pbStack_420 = &bStack_3f8;
      pbStack_418 = pbVar13 + -(int)pbStack_420;
      if (!bVar7) break;
      if (!bVar9) {
        if ((int)pbStack_418 < (int)pbStack_410) {
          uVar14 = (int)pbStack_410 - (int)pbStack_418;
          if ((int)uVar14 <= (int)pbStack_410) {
            pbVar13 = pbStack_410;
            do {
              *(byte *)((int)auStack_3f7 + (int)(pbVar13 + -1)) = pbStack_420[(int)pbVar13 - uVar14]
              ;
              pbVar13 = pbVar13 + -1;
            } while ((int)uVar14 <= (int)pbVar13);
          }
          if (uVar14 != 0) {
            puVar21 = (undefined4 *)((int)auStack_3f7 + ((bStack_428 != 0) - 1));
            for (uVar18 = uVar14 >> 2; uVar18 != 0; uVar18 = uVar18 - 1) {
              *puVar21 = 0x30303030;
              puVar21 = puVar21 + 1;
            }
            for (uVar14 = uVar14 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
              *(undefined1 *)puVar21 = 0x30;
              puVar21 = (undefined4 *)((int)puVar21 + 1);
            }
          }
          pbStack_418 = pbStack_410;
        }
        goto LAB_007e44bb;
      }
      goto LAB_007e4517;
    case '\x05':
      piVar22 = *(int **)param_5;
      param_5 = (double *)((int)param_5 + 4);
      *piVar22 = iStack_40c;
      pbStack_410 = (byte *)0x0;
      pbStack_418 = (byte *)0x0;
      break;
    case '\x06':
    case '\a':
      pbStack_420 = *(byte **)param_5;
      if (pbStack_420 == (byte *)0x0) {
        pbStack_420 = &DAT_0099cf70;
      }
      else if (cStack_429 == '\a') {
        pbStack_404 = pbStack_420;
      }
      pbStack_418 = pbStack_420;
      do {
        bVar12 = *pbStack_418;
        pbStack_418 = pbStack_418 + 1;
      } while (bVar12 != 0);
      pbStack_418 = pbStack_418 + -(int)(pbStack_420 + 1);
      goto LAB_007e43b3;
    case '\b':
      pbStack_420 = &bStack_3f8;
      bStack_3f8 = 0x25;
      pbStack_418 = (byte *)0x1;
      break;
    case '\t':
    case '\v':
      if (cStack_429 == '\t') {
        bStack_3f8 = *(byte *)param_5;
        param_5 = (double *)((int)param_5 + 4);
      }
      else {
        bStack_3f8 = param_4[1];
        param_4 = param_4 + 1;
      }
      if ((int)pbStack_424 < 0) {
        pbStack_420 = &bStack_3f8;
        pbStack_418 = (byte *)0x1;
      }
      else {
        if (1 < (int)pbStack_424) {
          pbVar13 = (byte *)auStack_3f7;
          for (uVar14 = (uint)(pbStack_424 + -1) >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
            *(uint *)pbVar13 =
                 CONCAT22(CONCAT11(bStack_3f8,bStack_3f8),CONCAT11(bStack_3f8,bStack_3f8));
            pbVar13 = pbVar13 + 4;
          }
          for (uVar14 = (uint)(pbStack_424 + -1) & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
            *pbVar13 = bStack_3f8;
            pbVar13 = pbVar13 + 1;
          }
        }
        pbStack_420 = &bStack_3f8;
        pbStack_418 = pbStack_424;
      }
      break;
    case '\n':
      bStack_3f8 = 0x25;
      auStack_3f7[0]._0_1_ = (byte)iVar20;
      iVar16 = (iVar20 != 0) + 1;
      (*param_1)(param_2,&DAT_009fe618,iVar16);
      iStack_40c = iStack_40c + iVar16;
      if (iVar20 == 0) {
        param_4 = param_4 + -1;
      }
      break;
    case '\f':
    case '\r':
      pbVar13 = *(byte **)param_5;
      bVar23 = pbVar13 == (byte *)0x0;
      if ((bVar23) && (pbVar13 = &DAT_00a00f30, cStack_429 != '\r')) {
        pbVar13 = &DAT_00a011a0;
      }
      iVar20 = 0;
      iVar16 = 0;
      bVar12 = *pbVar13;
      while (bVar12 != 0) {
        if (bVar12 == 0x27) {
          iVar20 = iVar20 + 1;
        }
        iVar17 = iVar16 + 1;
        iVar16 = iVar16 + 1;
        bVar12 = pbVar13[iVar17];
      }
      if ((bVar23) || (cStack_429 != '\r')) {
        iVar17 = 0;
      }
      else {
        iVar17 = 1;
      }
      iVar20 = iVar20 + 1 + iVar16 + iVar17 * 2;
      if (iVar20 < 0x3e9) {
        pbStack_420 = &bStack_3f8;
      }
      else {
        pbStack_420 = (byte *)FUN_007d0550(iVar20);
        pbStack_404 = pbStack_420;
        if (pbStack_420 == (byte *)0x0) {
          return -1;
        }
      }
      if (iVar17 != 0) {
        *pbStack_420 = 0x27;
      }
      bVar12 = *pbVar13;
      pbStack_418 = (byte *)(uint)(iVar17 != 0);
      while (bVar12 != 0) {
        pbStack_420[(int)pbStack_418] = bVar12;
        pbVar19 = pbStack_418 + 1;
        if (bVar12 == 0x27) {
          pbStack_420[(int)pbVar19] = 0x27;
          pbVar19 = pbStack_418 + 2;
        }
        pbVar1 = pbVar13 + 1;
        pbVar13 = pbVar13 + 1;
        pbStack_418 = pbVar19;
        bVar12 = *pbVar1;
      }
      if (iVar17 != 0) {
        pbStack_420[(int)pbStack_418] = 0x27;
        pbStack_418 = pbStack_418 + 1;
      }
      pbStack_420[(int)pbStack_418] = 0;
LAB_007e43b3:
      param_5 = (double *)((int)param_5 + 4);
      if ((-1 < (int)pbStack_424) && ((int)pbStack_424 < (int)pbStack_418)) {
        pbStack_418 = pbStack_424;
      }
      break;
    case '\x0e':
      piVar22 = *(int **)param_5;
      param_5 = (double *)((int)param_5 + 4);
      if ((piVar22 != (int *)0x0) && (*piVar22 != 0)) {
        (*param_1)(param_2,*piVar22,(uint)piVar22[1] >> 1);
      }
      pbStack_410 = (byte *)0x0;
      pbStack_418 = (byte *)0x0;
      break;
    case '\x0f':
      iVar20 = *(int *)param_5;
      piVar22 = (int *)((int)param_5 + 4);
      param_5 = param_5 + 1;
      puVar21 = (undefined4 *)(iVar20 + 4 + *piVar22 * 0x28);
      pcVar4 = (char *)*puVar21;
      if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {
        pcVar15 = pcVar4;
        do {
          cVar11 = *pcVar15;
          pcVar15 = pcVar15 + 1;
        } while (cVar11 != '\0');
        (*param_1)(param_2,pcVar4,(int)pcVar15 - (int)(pcVar4 + 1));
        (*param_1)(param_2,&DAT_00a0119c,1);
      }
      pcVar4 = (char *)puVar21[1];
      pcVar15 = pcVar4;
      do {
        cVar11 = *pcVar15;
        pcVar15 = pcVar15 + 1;
      } while (cVar11 != '\0');
      (*param_1)(param_2,pcVar4,(int)pcVar15 - (int)(pcVar4 + 1));
      pbStack_410 = (byte *)0x0;
      pbStack_418 = (byte *)0x0;
      break;
    case '\x10':
      bVar10 = false;
LAB_007e3b32:
      if ((puStack_408[2] & 1) == 0) {
        if (bVar10) {
          iVar20 = *(int *)param_5;
          iVar16 = *(int *)((int)param_5 + 4);
          param_5 = param_5 + 1;
        }
        else {
          iVar20 = *(int *)param_5;
          param_5 = (double *)((int)param_5 + 4);
          iVar16 = 0;
        }
        bStack_428 = 0;
      }
      else {
        if (bVar10) {
          iVar20 = *(int *)param_5;
          iVar16 = *(int *)((int)param_5 + 4);
          param_5 = param_5 + 1;
        }
        else {
          iVar20 = *(int *)param_5;
          param_5 = (double *)((int)param_5 + 4);
          iVar16 = iVar20 >> 0x1f;
        }
        if ((iVar16 < 1) && (iVar16 < 0)) {
          bVar23 = iVar20 != 0;
          iVar20 = -iVar20;
          iVar16 = -(iVar16 + (uint)bVar23);
          bStack_428 = 0x2d;
        }
        else if (bVar23) {
          bStack_428 = 0x2b;
        }
        else {
          bStack_428 = !bVar6 - 1U & 0x20;
        }
      }
      lVar24 = CONCAT44(iVar16,iVar20);
      if (iVar20 == 0 && iVar16 == 0) {
        bVar8 = false;
      }
      if (bVar7) {
        if ((int)pbStack_424 < (int)(pbStack_410 + -(uint)(bStack_428 != 0))) {
          pbStack_424 = pbStack_410 + -(uint)(bStack_428 != 0);
        }
      }
      bVar12 = puStack_408[4];
      uVar3 = puStack_408[1];
      pbStack_420 = abStack_11;
      do {
        pbStack_420 = pbStack_420 + -1;
        lVar24 = __aulldvrm(lVar24,uVar3,0);
        *pbStack_420 = s_0123456789ABCDEF0123456789abcdef_00a010a0[extraout_ECX + (uint)bVar12];
      } while (lVar24 != 0);
      pbVar13 = pbStack_420 + ((int)pbStack_424 - (int)abStack_11);
      if (0 < (int)pbVar13) {
        do {
          pbStack_420 = pbStack_420 + -1;
          pbVar13 = pbVar13 + -1;
          *pbStack_420 = 0x30;
        } while (pbVar13 != (byte *)0x0);
      }
      if (bStack_428 != 0) {
        pbStack_420 = pbStack_420 + -1;
        *pbStack_420 = bStack_428;
      }
      if ((bVar8) && (puStack_408[5] != 0)) {
        pbVar13 = &DAT_00a010c4 + (byte)puStack_408[5];
        bVar12 = *pbVar13;
        if ((*pbStack_420 != bVar12) && (bVar12 != 0)) {
          do {
            pbStack_420 = pbStack_420 + -1;
            pbVar13 = pbVar13 + 1;
            *pbStack_420 = bVar12;
            bVar12 = *pbVar13;
          } while (bVar12 != 0);
        }
      }
      pbStack_418 = abStack_11 + -(int)pbStack_420;
    }
    if (!bVar9) {
LAB_007e44bb:
      uVar14 = (int)pbStack_410 - (int)pbStack_418;
      if (0 < (int)uVar14) {
        iStack_40c = iStack_40c + uVar14;
        if (0x48 < uVar14) {
          uVar18 = uVar14 / 0x49;
          uVar14 = uVar14 % 0x49;
          do {
            (*param_1)(param_2,s__00a01150,0x49);
            uVar18 = uVar18 - 1;
          } while (uVar18 != 0);
        }
        if (0 < (int)uVar14) {
          (*param_1)(param_2,s__00a01150,uVar14);
        }
      }
    }
LAB_007e4517:
    if (0 < (int)pbStack_418) {
      (*param_1)(param_2,pbStack_420,pbStack_418);
      iStack_40c = iStack_40c + (int)pbStack_418;
    }
    if ((bVar9) && (uVar14 = (int)pbStack_410 - (int)pbStack_418, 0 < (int)uVar14)) {
      iStack_40c = iStack_40c + uVar14;
      if (0x48 < uVar14) {
        uVar18 = uVar14 / 0x49;
        uVar14 = uVar14 % 0x49;
        do {
          (*param_1)(param_2,s__00a01150,0x49);
          uVar18 = uVar18 - 1;
        } while (uVar18 != 0);
      }
      if (0 < (int)uVar14) {
        (*param_1)(param_2,s__00a01150,uVar14);
      }
    }
    if (pbStack_404 != (byte *)0x0) {
      FUN_007d05b0(pbStack_404);
    }
    param_4 = param_4 + 1;
    bVar12 = *param_4;
  } while( true );
}


// ==== FUN_007e4670 @ 0x007e4670 ====

void FUN_007e4670(int *param_1,undefined4 *param_2,uint param_3)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  iVar3 = param_1[2];
  param_1[3] = param_1[3] + param_3;
  if (param_1[4] < (int)(iVar3 + 1 + param_3)) {
    pcVar1 = (code *)param_1[5];
    if (pcVar1 == (code *)0x0) {
      param_3 = (param_1[4] - iVar3) - 1;
    }
    else {
      iVar3 = iVar3 + 1 + param_3 * 2;
      param_1[4] = iVar3;
      if (param_1[1] == *param_1) {
        puVar2 = (undefined4 *)(*pcVar1)(0,iVar3);
        param_1[1] = (int)puVar2;
        if ((puVar2 != (undefined4 *)0x0) && (uVar5 = param_1[2], uVar5 != 0)) {
          puVar6 = (undefined4 *)*param_1;
          for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar2 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar2 = puVar2 + 1;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined1 *)puVar2 = *(undefined1 *)puVar6;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
            puVar2 = (undefined4 *)((int)puVar2 + 1);
          }
        }
      }
      else {
        iVar3 = (*pcVar1)(param_1[1],iVar3);
        param_1[1] = iVar3;
      }
    }
  }
  if (param_1[1] != 0) {
    if (0 < (int)param_3) {
      puVar2 = (undefined4 *)(param_1[2] + param_1[1]);
      for (uVar5 = param_3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar2 = *param_2;
        param_2 = param_2 + 1;
        puVar2 = puVar2 + 1;
      }
      for (uVar5 = param_3 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)puVar2 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        puVar2 = (undefined4 *)((int)puVar2 + 1);
      }
      param_1[2] = param_1[2] + param_3;
    }
    *(undefined1 *)(param_1[2] + param_1[1]) = 0;
  }
  return;
}


// ==== FUN_007e4720 @ 0x007e4720 ====

undefined4 * FUN_007e4720(code *param_1,undefined4 param_2,int param_3)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *local_18;
  undefined4 *local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  code *local_4;
  
  local_8 = param_3;
  local_c = 0;
  local_10 = 0;
  local_4 = param_1;
  local_18 = in_EAX;
  local_14 = in_EAX;
  FUN_007e38a0(FUN_007e4670,&local_18,param_2);
  if (param_1 != (code *)0x0) {
    if (local_14 == local_18) {
      puVar1 = (undefined4 *)(*param_1)(0,local_10 + 1);
      local_14 = (undefined4 *)0x0;
      if (puVar1 != (undefined4 *)0x0) {
        puVar3 = puVar1;
        for (uVar2 = local_10 + 1U >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar3 = *local_18;
          local_18 = local_18 + 1;
          puVar3 = puVar3 + 1;
        }
        for (uVar2 = local_10 + 1U & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined1 *)puVar3 = *(undefined1 *)local_18;
          local_18 = (undefined4 *)((int)local_18 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + 1);
        }
        return puVar1;
      }
    }
    else if (local_10 + 10 < local_8) {
      local_14 = (undefined4 *)(*param_1)(local_14,local_10 + 1);
    }
  }
  return local_14;
}


// ==== FUN_007e47e0 @ 0x007e47e0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007e47e0(void)

{
  FUN_007e4720(&LAB_007e47d0,1,1000);
  return;
}


// ==== FUN_007e4830 @ 0x007e4830 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007e4830(void)

{
  FUN_007e4720(&LAB_007e47d0,1,1000);
  return;
}


// ==== FUN_007e4880 @ 0x007e4880 ====

undefined4 FUN_007e4880(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = param_1;
  local_14 = param_2;
  local_18 = param_2;
  local_c = 0;
  local_10 = 0;
  local_4 = 0;
  FUN_007e38a0(FUN_007e4670,&local_18,0,param_3,&param_4);
  return local_14;
}


// ==== FUN_007e48d0 @ 0x007e48d0 ====

undefined1 FUN_007e48d0(void)

{
  byte bVar1;
  int iVar2;
  byte *unaff_EBX;
  uint uVar3;
  uint unaff_EDI;
  
  if ((int)unaff_EDI < 2) {
    return 0x1b;
  }
  bVar1 = (&DAT_00a013d0)
          [(int)((uint)(byte)(&DAT_009fffc0)[unaff_EBX[unaff_EDI - 1]] * 3 ^
                 (uint)(byte)(&DAT_009fffc0)[*unaff_EBX] << 2 ^ unaff_EDI) % 0x7f];
  while( true ) {
    uVar3 = (uint)bVar1;
    if ((int)(uVar3 - 1) < 0) {
      return 0x1b;
    }
    if (((byte)(&DAT_00a014bf)[uVar3] == unaff_EDI) &&
       (iVar2 = FUN_007d0930(s__ABORTABLEFTEMPORARYADDATABASELE_00a011c7 +
                             *(ushort *)(&DAT_00a01530 + (uVar3 - 1) * 2) + 1), iVar2 == 0)) break;
    bVar1 = (&DAT_00a0144f)[uVar3];
  }
  return (&DAT_00a0160f)[uVar3];
}


// ==== FUN_007e4960 @ 0x007e4960 ====

void FUN_007e4960(void)

{
  FUN_007e48d0();
  return;
}


// ==== FUN_007e4980 @ 0x007e4980 ====

uint FUN_007e4980(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  byte *unaff_ESI;
  uint uVar6;
  bool bVar7;
  
  bVar4 = *unaff_ESI;
  uVar5 = (uint)bVar4;
  switch(bVar4) {
  case 9:
  case 10:
  case 0xc:
  case 0xd:
  case 0x20:
    uVar5 = 1;
    for (iVar3 = _isspace((uint)unaff_ESI[1]); iVar3 != 0; iVar3 = _isspace((uint)unaff_ESI[iVar3]))
    {
      iVar3 = uVar5 + 1;
      uVar5 = uVar5 + 1;
    }
    *param_1 = 3;
    return uVar5;
  case 0x21:
    if (unaff_ESI[1] == 0x3d) {
      *param_1 = 0x46;
      return 2;
    }
    *param_1 = 2;
    return 2;
  case 0x22:
  case 0x27:
    uVar6 = (uint)unaff_ESI[1];
    uVar2 = 1;
    if (uVar6 == 0) {
LAB_007e4c48:
      *param_1 = 0x5a;
      return uVar2;
    }
    do {
      if (uVar6 == uVar5) {
        if (unaff_ESI[uVar2 + 1] != uVar5) {
          if (uVar6 != 0) {
            uVar2 = uVar2 + 1;
          }
          goto LAB_007e4c48;
        }
        uVar2 = uVar2 + 1;
      }
      uVar6 = (uint)unaff_ESI[uVar2 + 1];
      uVar2 = uVar2 + 1;
      if (uVar6 == 0) {
        *param_1 = 0x5a;
        return uVar2;
      }
    } while( true );
  case 0x23:
    uVar5 = 1;
    while ((iVar3 = _isdigit((uint)unaff_ESI[uVar5]), iVar3 != 0 ||
           ((uVar5 == 1 && (unaff_ESI[1] == 0x2d))))) {
      uVar5 = uVar5 + 1;
    }
    *param_1 = 0x82;
    return uVar5;
  case 0x24:
    *param_1 = 0x83;
    if (unaff_ESI[1] == 0x7b) {
      bVar4 = unaff_ESI[2];
      iVar3 = 1;
      uVar6 = 2;
      if (bVar4 != 0) {
        while (iVar3 != 0) {
          if (bVar4 == 0x7b) {
            iVar3 = iVar3 + 1;
          }
          else if (bVar4 == 0x7d) {
            iVar3 = iVar3 + -1;
          }
          bVar4 = unaff_ESI[uVar6 + 1];
          uVar6 = uVar6 + 1;
          if (bVar4 == 0) {
            *param_1 = 2;
            return uVar6;
          }
        }
        if (bVar4 != 0) {
          return uVar6;
        }
      }
LAB_007e4e44:
      *param_1 = 2;
      return uVar6;
    }
    uVar2 = (uint)unaff_ESI[1];
    iVar3 = 0;
    uVar5 = 1;
    if (uVar2 == 0) goto LAB_007e4ecf;
    do {
      iVar1 = _isalnum(uVar2);
      if ((iVar1 == 0) && (uVar2 != 0x5f)) {
        if (uVar2 == 0x28) {
          if (0 < iVar3) goto LAB_007e4e96;
          break;
        }
        if ((uVar2 != 0x3a) || (unaff_ESI[uVar5 + 1] != 0x3a)) break;
        uVar5 = uVar5 + 1;
      }
      else {
        iVar3 = iVar3 + 1;
      }
      uVar2 = (uint)unaff_ESI[uVar5 + 1];
      uVar5 = uVar5 + 1;
    } while (uVar2 != 0);
    goto LAB_007e4ec9;
  case 0x25:
    *param_1 = 0x55;
    return 1;
  case 0x26:
    *param_1 = 0x4d;
    return 1;
  case 0x28:
    *param_1 = 0x17;
    return 1;
  case 0x29:
    *param_1 = 0x18;
    return 1;
  case 0x2a:
    *param_1 = 0x53;
    return 1;
  case 0x2b:
    *param_1 = 0x51;
    return 1;
  case 0x2c:
    *param_1 = 0x1a;
    return 1;
  case 0x2d:
    if (unaff_ESI[1] != 0x2d) {
      *param_1 = 0x52;
      return 1;
    }
    uVar5 = 2;
    bVar4 = unaff_ESI[2];
    while ((bVar4 != 0 && (bVar4 != 10))) {
      iVar3 = uVar5 + 1;
      uVar5 = uVar5 + 1;
      bVar4 = unaff_ESI[iVar3];
    }
    *param_1 = 5;
    return uVar5;
  case 0x2e:
    *param_1 = 0x73;
    return 1;
  case 0x2f:
    if ((unaff_ESI[1] != 0x2a) || (bVar4 = unaff_ESI[2], bVar4 == 0)) {
      *param_1 = 0x54;
      return 1;
    }
    for (uVar5 = 3; (bVar4 != 0x2a || (unaff_ESI[uVar5] != 0x2f)); uVar5 = uVar5 + 1) {
      bVar4 = unaff_ESI[uVar5];
      if (bVar4 == 0) goto LAB_007e4a99;
    }
    uVar5 = uVar5 + 1;
LAB_007e4a99:
    *param_1 = 5;
    return uVar5;
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
    *param_1 = 0x7f;
    uVar5 = 1;
    for (iVar3 = _isdigit((uint)unaff_ESI[1]); iVar3 != 0; iVar3 = _isdigit((uint)unaff_ESI[iVar3]))
    {
      iVar3 = uVar5 + 1;
      uVar5 = uVar5 + 1;
    }
    if ((unaff_ESI[uVar5] == 0x2e) && (iVar3 = _isdigit((uint)unaff_ESI[uVar5 + 1]), iVar3 != 0)) {
      iVar3 = uVar5 + 2;
      uVar5 = uVar5 + 2;
      for (iVar3 = _isdigit((uint)unaff_ESI[iVar3]); iVar3 != 0;
          iVar3 = _isdigit((uint)unaff_ESI[iVar3])) {
        iVar3 = uVar5 + 1;
        uVar5 = uVar5 + 1;
      }
      *param_1 = 0x80;
    }
    if (((unaff_ESI[uVar5] == 0x65) || (unaff_ESI[uVar5] == 0x45)) &&
       ((iVar3 = _isdigit((uint)unaff_ESI[uVar5 + 1]), iVar3 != 0 ||
        (((unaff_ESI[uVar5 + 1] == 0x2b || (unaff_ESI[uVar5 + 1] == 0x2d)) &&
         (iVar3 = _isdigit((uint)unaff_ESI[uVar5 + 2]), iVar3 != 0)))))) {
      uVar2 = uVar5 + 2;
      for (iVar3 = _isdigit((uint)unaff_ESI[uVar5 + 2]); iVar3 != 0;
          iVar3 = _isdigit((uint)unaff_ESI[iVar3])) {
        iVar3 = uVar2 + 1;
        uVar2 = uVar2 + 1;
      }
      *param_1 = 0x80;
      return uVar2;
    }
    break;
  case 0x3a:
    uVar5 = 1;
    while ((bVar4 = unaff_ESI[uVar5], (char)bVar4 < '\0' ||
           ((0x1f < bVar4 && ((&DAT_00a01660)[bVar4] != '\0'))))) {
      uVar5 = uVar5 + 1;
    }
    *param_1 = (((int)uVar5 < 2) - 1 & 0x81) + 2;
    return uVar5;
  case 0x3b:
    *param_1 = 10;
    return 1;
  case 0x3c:
    bVar4 = unaff_ESI[1];
    if (bVar4 == 0x3d) {
      *param_1 = 0x49;
      return 2;
    }
    if (bVar4 == 0x3e) {
      *param_1 = 0x46;
      return 2;
    }
    if (bVar4 == 0x3c) {
      *param_1 = 0x4f;
      return 2;
    }
    *param_1 = 0x4a;
    return 1;
  case 0x3d:
    *param_1 = 0x47;
    return (unaff_ESI[1] == 0x3d) + 1;
  case 0x3e:
    if (unaff_ESI[1] == 0x3d) {
      *param_1 = 0x4b;
      return 2;
    }
    if (unaff_ESI[1] == 0x3e) {
      *param_1 = 0x50;
      return 2;
    }
    *param_1 = 0x48;
    return 1;
  case 0x3f:
    *param_1 = 0x83;
    uVar5 = 1;
    iVar3 = _isdigit((uint)unaff_ESI[1]);
    if (iVar3 != 0) {
      do {
        iVar3 = uVar5 + 1;
        uVar5 = uVar5 + 1;
        iVar3 = _isdigit((uint)unaff_ESI[iVar3]);
      } while (iVar3 != 0);
      return uVar5;
    }
    break;
  case 0x58:
  case 0x78:
    uVar2 = (uint)unaff_ESI[1];
    if ((uVar2 == 0x27) || (uVar2 == 0x22)) {
      *param_1 = 0x81;
      uVar5 = (uint)unaff_ESI[2];
      uVar6 = 2;
      if (uVar5 == 0) {
        return 2;
      }
      while( true ) {
        if (uVar5 == uVar2) {
          uVar2 = uVar6 & 0x80000001;
          bVar7 = uVar2 == 0;
          if ((int)uVar2 < 0) {
            bVar7 = (uVar2 - 1 | 0xfffffffe) == 0xffffffff;
          }
          if (!bVar7) {
            *param_1 = 2;
          }
          if (uVar5 == 0) {
            return uVar6;
          }
          return uVar6 + 1;
        }
        iVar3 = _isxdigit(uVar5);
        if (iVar3 == 0) break;
        uVar5 = (uint)unaff_ESI[uVar6 + 1];
        uVar6 = uVar6 + 1;
        if (uVar5 == 0) {
          return uVar6;
        }
      }
      goto LAB_007e4e44;
    }
  default:
    if ((-1 < (char)bVar4) && ((uVar5 < 0x20 || ((&DAT_00a01660)[uVar5] == '\0')))) {
      *param_1 = 2;
      return 1;
    }
    uVar5 = 1;
    while ((bVar4 = unaff_ESI[uVar5], (char)bVar4 < '\0' ||
           ((0x1f < bVar4 && ((&DAT_00a01660)[bVar4] != '\0'))))) {
      uVar5 = uVar5 + 1;
    }
    iVar3 = FUN_007e48d0();
    *param_1 = iVar3;
    break;
  case 0x5b:
    for (uVar5 = 1; (bVar4 != 0x5d && (bVar4 = unaff_ESI[uVar5], bVar4 != 0)); uVar5 = uVar5 + 1) {
    }
    *param_1 = 0x1b;
    return uVar5;
  case 0x7c:
    if (unaff_ESI[1] == 0x7c) {
      *param_1 = 0x56;
      return 2;
    }
    *param_1 = 0x4e;
    return 1;
  case 0x7e:
    *param_1 = 0x59;
    return 1;
  }
  return uVar5;
  while (uVar2 != 0x29) {
LAB_007e4e96:
    uVar6 = uVar5;
    uVar2 = (uint)unaff_ESI[uVar6 + 1];
    uVar5 = uVar6 + 1;
    if ((uVar2 == 0) || (iVar1 = _isspace(uVar2), iVar1 != 0)) {
      if (uVar2 == 0x29) {
        uVar5 = uVar6 + 2;
      }
      else {
        *param_1 = 2;
      }
      goto LAB_007e4ec9;
    }
  }
  uVar5 = uVar6 + 2;
LAB_007e4ec9:
  if (iVar3 != 0) {
    return uVar5;
  }
LAB_007e4ecf:
  *param_1 = 2;
  return uVar5;
}


// ==== FUN_007e5090 @ 0x007e5090 ====

void FUN_007e5090(undefined4 param_1,undefined4 param_2)

{
  FUN_007e4980(param_2);
  return;
}


// ==== FUN_007e50b0 @ 0x007e50b0 ====

int FUN_007e50b0(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  local_4 = *param_1;
  iVar5 = 0;
  *(uint *)(local_4 + 8) = *(uint *)(local_4 + 8) & 0xfffffffb;
  local_10 = 0;
  local_c = -1;
  param_1[1] = 0;
  iVar1 = FUN_007f40c0(FUN_007d0550);
  if (iVar1 == 0) {
    FUN_007d0700(param_3,s_out_of_memory_009ffbcc,0);
    return 7;
  }
  param_1[0x24] = param_2;
  param_1[0x25] = param_2;
  do {
    if ((DAT_00b5c4c4 != 0) || (*(char *)(param_2 + iVar5) == '\0')) goto LAB_007e5217;
    param_1[0x22] = param_2 + iVar5;
    uVar2 = FUN_007e4980(&local_8);
    iVar3 = local_8;
    param_1[0x23] = uVar2 * 2 | param_1[0x23] & 1U;
    iVar5 = iVar5 + (uVar2 & 0x7fffffff);
    switch(local_8) {
    case 2:
      if (param_3 != (int *)0x0) {
        FUN_007d05b0(*param_3);
        iVar3 = FUN_007e4830(s_unrecognized_token____T__00a01718,param_1 + 0x22);
        *param_3 = iVar3;
      }
      local_10 = 1;
      goto LAB_007e5217;
    case 3:
    case 5:
      if ((*(byte *)(local_4 + 8) & 4) != 0) {
        param_1[1] = 9;
        FUN_007d0700(param_3,s_interrupt_00a01734,0);
        goto LAB_007e5217;
      }
      break;
    case 10:
      param_1[0x25] = param_2 + iVar5;
    default:
      FUN_007f5ca0(iVar1,local_8,param_1[0x22],param_1[0x23],param_1);
      local_c = iVar3;
      if (param_1[1] != 0) {
LAB_007e5217:
        if (((*(char *)(param_2 + iVar5) == '\0') && (local_10 == 0)) && (param_1[1] == 0)) {
          if (local_c != 10) {
            FUN_007f5ca0(iVar1,10,param_1[0x22],param_1[0x23],param_1);
            param_1[0x25] = param_2 + iVar5;
          }
          FUN_007f5ca0(iVar1,0,param_1[0x22],param_1[0x23],param_1);
        }
        FUN_007f41e0(iVar1,FUN_007d05b0);
        if (DAT_00b5c4c4 != 0) {
          param_1[1] = 7;
        }
        iVar5 = param_1[1];
        if (((iVar5 != 0) && (iVar5 != 0x65)) && (param_1[2] == 0)) {
          uVar4 = FUN_007cd3a0(iVar5,0);
          FUN_007d0700(param_1 + 2,uVar4);
        }
        iVar5 = param_1[2];
        if (iVar5 != 0) {
          if ((param_3 == (int *)0x0) || (*param_3 != 0)) {
            FUN_007d05b0(iVar5);
          }
          else {
            *param_3 = iVar5;
          }
          param_1[2] = 0;
          if (local_10 == 0) {
            local_10 = 1;
          }
        }
        if (((param_1[3] != 0) && (0 < param_1[6])) && (*(char *)((int)param_1 + 0x13) == '\0')) {
          FUN_007ddfe0(param_1[3]);
          param_1[3] = 0;
        }
        FUN_007d25e0(*param_1,param_1[0x26]);
        FUN_007ed8e0(param_1[0x27]);
        FUN_007d05b0(param_1[0x1c]);
        if ((local_10 != 0) && ((param_1[1] == 0 || (param_1[1] == 0x65)))) {
          param_1[1] = 1;
        }
        return local_10;
      }
    }
  } while( true );
}


// ==== FUN_007e5380 @ 0x007e5380 ====

uint FUN_007e5380(byte *param_1)

{
  byte *pbVar1;
  uint uVar2;
  byte *pbVar3;
  
  uVar2 = (uint)*param_1;
  pbVar1 = &DAT_00a01748 + uVar2;
  pbVar3 = param_1 + 1;
  switch(*pbVar1) {
  case 3:
    uVar2 = uVar2 * 0x40 + (uint)*pbVar3;
    pbVar3 = param_1 + 2;
  case 2:
    uVar2 = uVar2 * 0x40 + (uint)*pbVar3;
    pbVar3 = pbVar3 + 1;
  case 1:
    return (uVar2 * 0x40 - *(int *)(&DAT_00a01848 + (uint)*pbVar1 * 4)) + (uint)*pbVar3;
  default:
    return uVar2;
  case 0xff:
    return 0xfffd;
  }
}


// ==== FUN_007e54f0 @ 0x007e54f0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007e54f0(uint param_1,char param_2)

{
  ushort *puVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte bVar8;
  undefined1 *puVar9;
  int iVar10;
  uint uVar11;
  byte bVar12;
  ushort *puVar13;
  ushort *puVar14;
  byte *local_2c;
  byte local_24 [32];
  undefined4 local_4;
  
  iVar4 = param_1;
  local_4 = DAT_00b49670;
  if (*(char *)(param_1 + 0xf) == '\x01') {
    if (param_2 == '\x01') goto LAB_007e555c;
    iVar10 = *(int *)(param_1 + 8);
    param_1 = iVar10 * 2 + 2;
  }
  else {
    if (param_2 != '\x01') {
      iVar4 = FUN_007cf890(param_1);
      if (iVar4 != 0) {
        return 7;
      }
      puVar5 = *(undefined1 **)(param_1 + 0x18);
      puVar9 = puVar5 + *(int *)(param_1 + 8);
      for (; puVar5 < puVar9; puVar5 = puVar5 + 2) {
        uVar2 = *puVar5;
        *puVar5 = puVar5[1];
        puVar5[1] = uVar2;
      }
      *(char *)(param_1 + 0xf) = param_2;
      return 0;
    }
LAB_007e555c:
    iVar10 = *(int *)(param_1 + 8);
    param_1 = (iVar10 / 2) * 3 + 1;
  }
  puVar13 = *(ushort **)(iVar4 + 0x18);
  puVar1 = (ushort *)(iVar10 + (int)puVar13);
  if ((int)param_1 < 0x21) {
    local_2c = local_24;
  }
  else {
    local_2c = (byte *)FUN_007d0590(param_1);
    if (local_2c == (byte *)0x0) {
      return 7;
    }
  }
  if (*(char *)(iVar4 + 0xf) == '\x01') {
    pbVar7 = local_2c;
    if (param_2 == '\x02') {
      pbVar6 = local_2c;
      if (puVar13 < puVar1) {
        do {
          pbVar7 = pbVar6;
          uVar11 = (uint)(byte)*puVar13;
          pbVar6 = &DAT_00a01748 + uVar11;
          puVar14 = (ushort *)((int)puVar13 + 1);
          switch(*pbVar6) {
          case 3:
            uVar11 = uVar11 * 0x40 + (uint)*(byte *)puVar14;
            puVar14 = puVar13 + 1;
          case 2:
            uVar11 = uVar11 * 0x40 + (uint)(byte)*puVar14;
            puVar14 = (ushort *)((int)puVar14 + 1);
          case 1:
            uVar3 = *puVar14;
            puVar14 = (ushort *)((int)puVar14 + 1);
            uVar11 = (uVar11 * 0x40 + (uint)(byte)uVar3) -
                     *(int *)(&DAT_00a01848 + (uint)*pbVar6 * 4);
          default:
            bVar8 = (byte)(uVar11 >> 8);
            if ((int)uVar11 < 0x10000) {
              *pbVar7 = (byte)uVar11;
            }
            else {
              bVar12 = (byte)((int)(uVar11 - 0x10000) >> 10);
              *pbVar7 = ((byte)((int)uVar11 >> 10) ^ bVar12) & 0x3f ^ bVar12;
              pbVar7[1] = ((byte)((int)(uVar11 - 0x10000) >> 0x12) & 3) - 0x28;
              pbVar7 = pbVar7 + 2;
              *pbVar7 = (byte)uVar11;
              bVar8 = (bVar8 & 3) - 0x24;
            }
            break;
          case 0xff:
            *pbVar7 = 0xfd;
            bVar8 = 0xff;
          }
          pbVar7[1] = bVar8;
          pbVar6 = pbVar7 + 2;
          puVar13 = puVar14;
        } while (puVar14 < puVar1);
        *(int *)(iVar4 + 8) = (int)pbVar6 - (int)local_2c;
        *pbVar6 = 0;
        pbVar7 = pbVar7 + 3;
        goto LAB_007e58f6;
      }
    }
    else {
      while (puVar13 < puVar1) {
        uVar11 = (uint)(byte)*puVar13;
        pbVar6 = &DAT_00a01748 + uVar11;
        puVar14 = (ushort *)((int)puVar13 + 1);
        switch(*pbVar6) {
        case 3:
          uVar11 = uVar11 * 0x40 + (uint)*(byte *)puVar14;
          puVar14 = puVar13 + 1;
        case 2:
          uVar11 = uVar11 * 0x40 + (uint)(byte)*puVar14;
          puVar14 = (ushort *)((int)puVar14 + 1);
        case 1:
          uVar3 = *puVar14;
          puVar14 = (ushort *)((int)puVar14 + 1);
          uVar11 = (uVar11 * 0x40 + (uint)(byte)uVar3) - *(int *)(&DAT_00a01848 + (uint)*pbVar6 * 4)
          ;
        default:
          bVar8 = (byte)(uVar11 >> 8);
          if (0xffff < (int)uVar11) {
            *pbVar7 = ((byte)((int)(uVar11 - 0x10000) >> 0x12) & 3) - 0x28;
            bVar12 = (byte)((int)(uVar11 - 0x10000) >> 10);
            pbVar7[1] = ((byte)((int)uVar11 >> 10) ^ bVar12) & 0x3f ^ bVar12;
            pbVar7 = pbVar7 + 2;
            bVar8 = (bVar8 & 3) - 0x24;
          }
          break;
        case 0xff:
          uVar11 = 0xfffd;
          bVar8 = 0xff;
        }
        *pbVar7 = bVar8;
        pbVar7[1] = (byte)uVar11;
        puVar13 = puVar14;
        pbVar7 = pbVar7 + 2;
      }
    }
    *(int *)(iVar4 + 8) = (int)pbVar7 - (int)local_2c;
    *pbVar7 = 0;
    pbVar7 = pbVar7 + 1;
  }
  else {
    pbVar7 = local_2c;
    if (*(char *)(iVar4 + 0xf) == '\x02') {
      while (puVar13 < puVar1) {
        uVar11 = (uint)*puVar13;
        puVar14 = puVar13 + 1;
        if ((0xd7ff < uVar11) && (uVar11 < 0xe001)) {
          uVar3 = *puVar14;
          puVar14 = puVar13 + 2;
          uVar11 = ((uVar11 & 0x3c0) + 0x40 + (uVar11 & 0x3f)) * 0x400 + (uVar3 & 0x3ff);
        }
        if (0x7f < uVar11) {
          bVar8 = (byte)((int)uVar11 >> 6);
          if (uVar11 < 0x800) {
            bVar8 = (bVar8 & 0x1f) - 0x40;
          }
          else {
            bVar12 = (byte)((int)uVar11 >> 0xc);
            if (uVar11 < 0x10000) {
              bVar12 = (bVar12 & 0xf) - 0x20;
            }
            else {
              *pbVar7 = (char)((int)uVar11 >> 0x12) - 0x10;
              pbVar7 = pbVar7 + 1;
              bVar12 = (bVar12 & 0x3f) + 0x80;
            }
            *pbVar7 = bVar12;
            pbVar7 = pbVar7 + 1;
            bVar8 = (bVar8 & 0x3f) + 0x80;
          }
          *pbVar7 = bVar8;
          pbVar7 = pbVar7 + 1;
          uVar11 = (uint)(byte)(((byte)uVar11 & 0x3f) + 0x80);
        }
        *pbVar7 = (byte)uVar11;
        puVar13 = puVar14;
        pbVar7 = pbVar7 + 1;
      }
    }
    else {
      while (puVar13 < puVar1) {
        uVar11 = (uint)CONCAT11((byte)*puVar13,*(byte *)((int)puVar13 + 1));
        puVar14 = puVar13 + 1;
        if ((0xd7ff < uVar11) && (uVar11 < 0xe001)) {
          uVar3 = *puVar14;
          puVar14 = puVar13 + 2;
          uVar11 = ((uVar11 & 0x3c0) + 0x40 + (uVar11 & 0x3f)) * 0x400 +
                   (CONCAT11((byte)uVar3,*(byte *)((int)puVar13 + 3)) & 0x3ff);
        }
        if (0x7f < uVar11) {
          bVar8 = (byte)((int)uVar11 >> 6);
          if (uVar11 < 0x800) {
            bVar8 = (bVar8 & 0x1f) - 0x40;
          }
          else {
            bVar12 = (byte)((int)uVar11 >> 0xc);
            if (uVar11 < 0x10000) {
              bVar12 = (bVar12 & 0xf) - 0x20;
            }
            else {
              *pbVar7 = (char)((int)uVar11 >> 0x12) - 0x10;
              pbVar7 = pbVar7 + 1;
              bVar12 = (bVar12 & 0x3f) + 0x80;
            }
            *pbVar7 = bVar12;
            pbVar7 = pbVar7 + 1;
            bVar8 = (bVar8 & 0x3f) + 0x80;
          }
          *pbVar7 = bVar8;
          pbVar7 = pbVar7 + 1;
          uVar11 = (uint)(byte)(((byte)uVar11 & 0x3f) + 0x80);
        }
        *pbVar7 = (byte)uVar11;
        puVar13 = puVar14;
        pbVar7 = pbVar7 + 1;
      }
    }
    *(int *)(iVar4 + 8) = (int)pbVar7 - (int)local_2c;
  }
LAB_007e58f6:
  *pbVar7 = 0;
  FUN_007cf9b0(iVar4);
  *(ushort *)(iVar4 + 0xc) = *(ushort *)(iVar4 + 0xc) & 0xfc3f;
  *(char *)(iVar4 + 0xf) = param_2;
  if (local_2c == local_24) {
    pbVar7 = (byte *)(iVar4 + 0x20);
    for (uVar11 = param_1 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
      *(undefined4 *)pbVar7 = *(undefined4 *)local_2c;
      local_2c = local_2c + 4;
      pbVar7 = pbVar7 + 4;
    }
    for (param_1 = param_1 & 3; param_1 != 0; param_1 = param_1 - 1) {
      *pbVar7 = *local_2c;
      local_2c = local_2c + 1;
      pbVar7 = pbVar7 + 1;
    }
    *(ushort *)(iVar4 + 0xc) = *(ushort *)(iVar4 + 0xc) | 0x220;
    local_2c = (byte *)(iVar4 + 0x20);
  }
  else {
    *(ushort *)(iVar4 + 0xc) = *(ushort *)(iVar4 + 0xc) | 0x60;
  }
  *(byte **)(iVar4 + 0x18) = local_2c;
  return 0;
}


// ==== FUN_007e5b90 @ 0x007e5b90 ====

undefined4 FUN_007e5b90(int param_1)

{
  int iVar1;
  char *pcVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = param_1;
  iVar1 = *(int *)(param_1 + 8);
  if ((-1 < iVar1) && (iVar1 < 2)) {
    return 0;
  }
  pcVar2 = *(char **)(param_1 + 0x18);
  if (*pcVar2 == -2) {
    if (pcVar2[1] != -1) {
      return 0;
    }
    param_1 = 3;
  }
  else {
    if (*pcVar2 != -1) {
      return 0;
    }
    if (pcVar2[1] != -2) {
      return 0;
    }
    param_1 = 2;
  }
  if ((*(byte *)(iVar4 + 0xc) & 0x40) == 0) {
    uVar5 = FUN_007cfbe0(iVar4,pcVar2 + 2,iVar1 + -2,param_1,0xffffffff);
    return uVar5;
  }
  pcVar3 = *(code **)(iVar4 + 0x1c);
  *(undefined4 *)(iVar4 + 0x18) = 0;
  *(undefined4 *)(iVar4 + 0x1c) = 0;
  uVar5 = FUN_007cfbe0(iVar4,pcVar2 + 2,iVar1 + -2,param_1,0xffffffff);
  (*pcVar3)(pcVar2);
  return uVar5;
}


// ==== FUN_007e5c30 @ 0x007e5c30 ====

int FUN_007e5c30(byte *param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  byte *pbVar3;
  
  iVar1 = 0;
  if (param_2 < 0) {
    pbVar3 = (byte *)0xffffffff;
  }
  else {
    pbVar3 = param_1 + param_2;
  }
  bVar2 = *param_1;
  if (bVar2 != 0) {
    do {
      if (pbVar3 <= param_1) {
        return iVar1;
      }
      param_1 = param_1 + (byte)(&DAT_00a01748)[bVar2] + 1;
      bVar2 = *param_1;
      iVar1 = iVar1 + 1;
    } while (bVar2 != 0);
  }
  return iVar1;
}


// ==== FUN_007e5c70 @ 0x007e5c70 ====

char * FUN_007e5c70(char *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  uVar4 = 1;
  pcVar3 = param_1;
  pcVar2 = param_1;
  if (DAT_009ff8b0 == '\0') {
    while ((param_2 < 0 || (iVar5 < param_2))) {
      uVar4 = *pcVar3 * 0x100 + (int)pcVar3[1];
      pcVar2 = pcVar3 + 2;
      if ((0xd7ff < (int)uVar4) && ((int)uVar4 < 0xe001)) {
        cVar1 = *pcVar2;
        pcVar2 = pcVar3 + 4;
        uVar4 = ((uVar4 & 0x3c0) + 0x40 + (uVar4 & 0x3f)) * 0x400 +
                (cVar1 * 0x100 + (int)pcVar3[3] & 0x3ffU);
      }
      iVar5 = iVar5 + 1;
      pcVar3 = pcVar2;
      if (uVar4 == 0) {
        return pcVar2 + (-2 - (int)param_1);
      }
    }
  }
  else {
    do {
      if ((-1 < param_2) && (pcVar3 = pcVar2, param_2 <= iVar5)) break;
      uVar4 = (int)*pcVar2 + pcVar2[1] * 0x100;
      pcVar3 = pcVar2 + 2;
      if ((0xd7ff < (int)uVar4) && ((int)uVar4 < 0xe001)) {
        cVar1 = *pcVar3;
        pcVar3 = pcVar2 + 4;
        uVar4 = ((uVar4 & 0x3c0) + 0x40 + (uVar4 & 0x3f)) * 0x400 +
                ((int)cVar1 + pcVar2[3] * 0x100 & 0x3ffU);
      }
      iVar5 = iVar5 + 1;
      pcVar2 = pcVar3;
    } while (uVar4 != 0);
  }
  return pcVar3 + (-(int)param_1 - ((uVar4 != 0) - 1 & 2));
}


// ==== FUN_007e5d70 @ 0x007e5d70 ====

void FUN_007e5d70(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  
  pbVar2 = (byte *)FUN_007cdf60(*param_3);
  iVar3 = FUN_007cdf10(*param_3);
  pbVar5 = pbVar2 + iVar3;
  iVar3 = thunk_FUN_007cff80(param_3[1]);
  param_3 = (undefined4 *)thunk_FUN_007cff80(param_3[2]);
  if (iVar3 < 1) {
    pbVar4 = pbVar5;
    if (DAT_009ff8b0 == '\0') {
      for (; iVar3 < 0; iVar3 = iVar3 + 1) {
        if (pbVar4 <= pbVar2) goto LAB_007e5e88;
        bVar1 = pbVar4[-1];
        if ((bVar1 < 0xd8) || ((0xdf < bVar1 && ((bVar1 != 0xe0 || (*pbVar4 != 0)))))) {
          pbVar4 = pbVar4 + -2;
        }
        else {
          pbVar4 = pbVar4 + -4;
        }
      }
    }
    else {
      for (; iVar3 < 0; iVar3 = iVar3 + 1) {
        if (pbVar4 <= pbVar2) goto LAB_007e5e88;
        bVar1 = *pbVar4;
        if ((bVar1 < 0xd8) || ((0xdf < bVar1 && ((bVar1 != 0xe0 || (pbVar4[-1] != 0)))))) {
          pbVar4 = pbVar4 + -2;
        }
        else {
          pbVar4 = pbVar4 + -4;
        }
      }
    }
  }
  else {
    iVar3 = iVar3 + -1;
    iVar6 = 0;
    pbVar4 = pbVar2;
    if (DAT_009ff8b0 == '\0') {
      if (0 < iVar3) {
        do {
          if (pbVar5 <= pbVar4) break;
          bVar1 = *pbVar4;
          if ((bVar1 < 0xd8) || ((0xdf < bVar1 && ((bVar1 != 0xe0 || (pbVar4[1] != 0)))))) {
            pbVar4 = pbVar4 + 2;
          }
          else {
            pbVar4 = pbVar4 + 4;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar3);
      }
    }
    else if (0 < iVar3) {
      do {
        pbVar4 = pbVar2;
        if (pbVar5 <= pbVar2) break;
        bVar1 = pbVar2[1];
        if ((bVar1 < 0xd8) || ((0xdf < bVar1 && ((bVar1 != 0xe0 || (*pbVar2 != 0)))))) {
          pbVar2 = pbVar2 + 2;
        }
        else {
          pbVar2 = pbVar2 + 4;
        }
        iVar6 = iVar6 + 1;
        pbVar4 = pbVar2;
      } while (iVar6 < iVar3);
    }
  }
LAB_007e5e90:
  iVar3 = 0;
  pbVar2 = pbVar4;
  if (DAT_009ff8b0 == '\0') {
    if (0 < (int)param_3) {
      do {
        if (pbVar5 <= pbVar2) break;
        bVar1 = *pbVar2;
        if ((bVar1 < 0xd8) || ((0xdf < bVar1 && ((bVar1 != 0xe0 || (pbVar2[1] != 0)))))) {
          pbVar2 = pbVar2 + 2;
        }
        else {
          pbVar2 = pbVar2 + 4;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)param_3);
    }
  }
  else if (0 < (int)param_3) {
    do {
      if (pbVar5 <= pbVar2) break;
      bVar1 = pbVar2[1];
      if ((bVar1 < 0xd8) || ((0xdf < bVar1 && ((bVar1 != 0xe0 || (*pbVar2 != 0)))))) {
        pbVar2 = pbVar2 + 2;
      }
      else {
        pbVar2 = pbVar2 + 4;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_3);
  }
  FUN_007ce060(param_1,pbVar4,(int)pbVar2 - (int)pbVar4,0xffffffff);
  return;
LAB_007e5e88:
  if (iVar3 < 0) {
    param_3 = (undefined4 *)((int)param_3 + iVar3);
  }
  goto LAB_007e5e90;
}


// ==== FUN_007e5f10 @ 0x007e5f10 ====

undefined4 FUN_007e5f10(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((param_1[1] != iVar1) && (0 < iVar1)) {
    iVar1 = FUN_00806326(param_1[3],iVar1 * 4);
    if (iVar1 == 0) {
      return 0xfffffffe;
    }
    param_1[3] = iVar1;
    param_1[1] = *param_1;
  }
  return 0;
}


// ==== FUN_007e5f50 @ 0x007e5f50 ====

int FUN_007e5f50(int *param_1,byte *param_2,int param_3)

{
  int iVar1;
  
  if ((1 < param_1[1]) || (iVar1 = FUN_007f6030(param_1,2), iVar1 == 0)) {
    FUN_007f5ff0(param_1);
    if (0 < param_3) {
      do {
        param_3 = param_3 + -1;
        iVar1 = FUN_007f5ef0(param_1,8,param_1);
        if (iVar1 != 0) {
          return iVar1;
        }
        *(uint *)param_1[3] = *(uint *)param_1[3] | (uint)*param_2;
        *param_1 = *param_1 + 1;
        param_2 = param_2 + 1;
      } while (0 < param_3);
    }
    FUN_007f5ec0(param_1);
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_007e5fc0 @ 0x007e5fc0 ====

undefined4 FUN_007e5fc0(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = param_2 & 0x8000001f;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xffffffe0) + 1;
  }
  iVar4 = param_2 + (0x40 - uVar1);
  pvVar2 = _malloc(iVar4 * 4);
  param_1[3] = pvVar2;
  if (pvVar2 == (void *)0x0) {
    return 0xfffffffe;
  }
  iVar3 = 0;
  *param_1 = 0;
  param_1[1] = iVar4;
  param_1[2] = 0;
  if (0 < iVar4) {
    do {
      *(undefined4 *)(param_1[3] + iVar3 * 4) = 0;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar4);
  }
  return 0;
}


// ==== FUN_007e6040 @ 0x007e6040 ====

void FUN_007e6040(int param_1)

{
  undefined1 *puVar1;
  
  if (param_1 != 0) {
    puVar1 = (undefined1 *)register0x00000010;
    do {
      FUN_007f60a0(param_1);
      param_1 = *(int *)(puVar1 + 8);
      puVar1 = puVar1 + 4;
    } while (param_1 != 0);
  }
  return;
}


// ==== FUN_007e6100 @ 0x007e6100 ====

int FUN_007e6100(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int local_10 [3];
  undefined1 *local_4;
  
  iVar1 = FUN_007f62a0(local_10,param_1);
  if (iVar1 == 0) {
    iVar1 = 0;
    while (local_10[0] != 0) {
      *(undefined1 *)(iVar1 + param_2) = *local_4;
      iVar1 = iVar1 + 1;
      iVar2 = FUN_007f6120(local_10,8,local_10,0);
      if (iVar2 != 0) {
        FUN_007f60a0(local_10);
        return iVar2;
      }
    }
    if (iVar1 < param_3) {
      _memset((void *)(iVar1 + param_2),0,param_3 - iVar1);
      iVar1 = iVar1 + (param_3 - iVar1);
    }
    FUN_007f60f0(param_2,iVar1);
    FUN_007f60a0(local_10);
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_007e61b0 @ 0x007e61b0 ====

int FUN_007e61b0(undefined4 param_1,int param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  if (param_3[2] == 1) {
    return -3;
  }
  if (*(int *)(param_2 + 8) != 1) {
    iVar1 = FUN_007f6e60(param_3);
    if (iVar1 == 1) {
      uVar2 = 1;
    }
    else {
      iVar1 = FUN_007f6e20(param_3);
      if (iVar1 == 0) {
        iVar1 = FUN_007f6db0(param_3);
        iVar1 = iVar1 * 2;
      }
      if (((0 < *param_3) && ((*(byte *)param_3[3] & 1) != 0)) || (iVar1 != 0)) {
        iVar1 = FUN_007f62d0(param_1,param_2,param_3,param_4,iVar1);
        return iVar1;
      }
      uVar2 = 0;
    }
    iVar1 = FUN_007f6860(param_1,param_2,param_3,param_4,uVar2);
    return iVar1;
  }
  iVar1 = FUN_007f6f20(local_20);
  if (iVar1 == 0) {
    iVar1 = FUN_007f6ee0(param_1,param_3,local_20);
    if (iVar1 == 0) {
      iVar1 = FUN_007f6f20(local_10);
      if (iVar1 != 0) {
        FUN_007f60a0(local_20);
        return iVar1;
      }
      iVar1 = FUN_007f6eb0(param_2,local_10);
      if (iVar1 == 0) {
        iVar1 = FUN_007e61b0(local_20,local_10,param_3,param_4);
        FUN_007e6040(local_20,local_10,0);
        return iVar1;
      }
      FUN_007e6040(local_20,local_10,0);
      return iVar1;
    }
    FUN_007f60a0(local_20);
  }
  return iVar1;
}


// ==== FUN_007e6310 @ 0x007e6310 ====

int FUN_007e6310(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 != *(int *)(param_2 + 8)) {
    return (uint)(iVar1 != 1) * 2 + -1;
  }
  if (iVar1 == 1) {
    iVar1 = FUN_007f6f70();
    return iVar1;
  }
  iVar1 = FUN_007f6f70();
  return iVar1;
}


// ==== FUN_007e6350 @ 0x007e6350 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 FUN_007e6350(void)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  char local_104 [256];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  if (DAT_00b5c4e8 == '\0') {
    DAT_00b5c4ea = 0;
    DAT_00b5c4e9 = '\0';
    FUN_007d1ac0(local_104);
    iVar3 = 0;
    do {
      (&DAT_00b5c4eb)[iVar3] = (char)iVar3;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x100);
    iVar3 = 0;
    do {
      DAT_00b5c4ea = DAT_00b5c4ea + local_104[iVar3] + (&DAT_00b5c4eb)[iVar3];
      uVar1 = (&DAT_00b5c4eb)[DAT_00b5c4ea];
      (&DAT_00b5c4eb)[DAT_00b5c4ea] = (&DAT_00b5c4eb)[iVar3];
      (&DAT_00b5c4eb)[iVar3] = uVar1;
      DAT_00b5c4ea = DAT_00b5c4ea + local_104[iVar3 + 1] + (&DAT_00b5c4ec)[iVar3];
      uVar1 = (&DAT_00b5c4eb)[DAT_00b5c4ea];
      (&DAT_00b5c4eb)[DAT_00b5c4ea] = (&DAT_00b5c4ec)[iVar3];
      (&DAT_00b5c4ec)[iVar3] = uVar1;
      DAT_00b5c4ea = DAT_00b5c4ea + local_104[iVar3 + 2] + (&DAT_00b5c4ed)[iVar3];
      uVar1 = (&DAT_00b5c4eb)[DAT_00b5c4ea];
      (&DAT_00b5c4eb)[DAT_00b5c4ea] = (&DAT_00b5c4ed)[iVar3];
      (&DAT_00b5c4ed)[iVar3] = uVar1;
      DAT_00b5c4ea = DAT_00b5c4ea + local_104[iVar3 + 3] + (&DAT_00b5c4ee)[iVar3];
      uVar1 = (&DAT_00b5c4eb)[DAT_00b5c4ea];
      (&DAT_00b5c4eb)[DAT_00b5c4ea] = (&DAT_00b5c4ee)[iVar3];
      (&DAT_00b5c4ee)[iVar3] = uVar1;
      iVar3 = iVar3 + 4;
    } while (iVar3 < 0x100);
    DAT_00b5c4e8 = '\x01';
  }
  DAT_00b5c4e9 = DAT_00b5c4e9 + 1;
  cVar2 = (&DAT_00b5c4eb)[DAT_00b5c4e9];
  DAT_00b5c4ea = DAT_00b5c4ea + cVar2;
  (&DAT_00b5c4eb)[DAT_00b5c4e9] = (&DAT_00b5c4eb)[DAT_00b5c4ea];
  (&DAT_00b5c4eb)[DAT_00b5c4ea] = cVar2;
  return (&DAT_00b5c4eb)[(byte)((&DAT_00b5c4eb)[DAT_00b5c4e9] + cVar2)];
}


// ==== FUN_007e6500 @ 0x007e6500 ====

void FUN_007e6500(int param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  FUN_007d1ae0();
  for (; param_1 != 0; param_1 = param_1 + -1) {
    uVar1 = FUN_007e6350();
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  FUN_007d1af0();
  return;
}


// ==== FUN_007e6530 @ 0x007e6530 ====

int * FUN_007e6530(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                  undefined1 param_7,int param_8,int param_9)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)FUN_007d0550(0x38);
  if (piVar1 == (int *)0x0) {
    FUN_007ea740(param_1);
    FUN_007d3a10(param_2);
    FUN_007eabc0(param_3);
    FUN_007ea740(param_4);
    FUN_007eabc0(param_5);
    FUN_007ea740(param_6);
    FUN_007eabc0(param_8);
    FUN_007eabc0(param_9);
    return (int *)0x0;
  }
  if (param_1 == 0) {
    uVar2 = FUN_007eb130(0x6e,0,0,0,0);
    param_1 = FUN_007eadd0(0,uVar2);
  }
  *piVar1 = param_1;
  piVar1[3] = param_3;
  piVar1[6] = param_6;
  piVar1[2] = param_2;
  piVar1[9] = param_9;
  piVar1[4] = param_4;
  piVar1[5] = param_5;
  piVar1[10] = -1;
  piVar1[0xb] = -1;
  *(undefined1 *)((int)piVar1 + 5) = param_7;
  *(undefined1 *)(piVar1 + 1) = 0x71;
  piVar1[8] = param_8;
  return piVar1;
}


// ==== FUN_007e6600 @ 0x007e6600 ====

byte FUN_007e6600(undefined4 param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined *puVar3;
  undefined *puVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  int local_c [3];
  
  bVar5 = 0;
  local_c[0] = param_2;
  local_c[1] = param_3;
  local_c[2] = param_4;
  iVar6 = 0;
  do {
    puVar1 = (undefined4 *)local_c[iVar6];
    if (puVar1 == (undefined4 *)0x0) break;
    uVar7 = 0;
    while (((uint)puVar1[1] >> 1 != (uint)(byte)(&DAT_00a0185c)[uVar7 * 8] ||
           (iVar2 = FUN_007d0930(*puVar1,(&PTR_s_natural_00a01858)[uVar7 * 2],(uint)puVar1[1] >> 1),
           iVar2 != 0))) {
      uVar7 = uVar7 + 1;
      if (6 < uVar7) goto LAB_007e665f;
    }
    bVar5 = bVar5 | (&DAT_00a0185d)[uVar7 * 8];
    if (6 < uVar7) {
LAB_007e665f:
      bVar5 = bVar5 | 0x20;
      break;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 3);
  if (((bVar5 & 0x11) != 0x11) && ((bVar5 & 0x20) == 0)) {
    if ((bVar5 & 8) == 0) {
      return bVar5;
    }
    FUN_007d0820(param_1,s_RIGHT_and_FULL_OUTER_JOINs_are_n_00a018fc);
    return 1;
  }
  puVar4 = &DAT_00a018f8;
  puVar3 = &DAT_00a018f8;
  if (param_3 == 0) {
    puVar4 = &DAT_00a018f9;
  }
  if (param_4 == 0) {
    puVar3 = &DAT_00a018f9;
  }
  FUN_007d0820(param_1,s_unknown_or_unsupported_join_type_00a018c8,param_2,puVar4,param_3,puVar3,
               param_4);
  return 1;
}


// ==== FUN_007e6710 @ 0x007e6710 ====

int FUN_007e6710(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  
  iVar3 = 0;
  if (0 < *(int *)(unaff_EDI + 4)) {
    iVar2 = 0;
    do {
      iVar1 = FUN_007d08e0(*(undefined4 *)(*(int *)(unaff_EDI + 8) + iVar2),param_1);
      if (iVar1 == 0) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x14;
    } while (iVar3 < *(int *)(unaff_EDI + 4));
  }
  return -1;
}


// ==== FUN_007e6750 @ 0x007e6750 ====

void FUN_007e6750(undefined4 *param_1,undefined4 *param_2,char *param_3,undefined4 *param_4)

{
  char cVar1;
  char *in_EAX;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  char *in_ECX;
  char *local_8;
  int local_4;
  
  pcVar4 = in_EAX + 1;
  do {
    cVar1 = *in_EAX;
    in_EAX = in_EAX + 1;
  } while (cVar1 != '\0');
  local_4 = ((int)in_EAX - (int)pcVar4) * 2;
  uVar2 = FUN_007eb130(0x1b,0,0,&local_8);
  uVar3 = FUN_007eb130(0x1b,0,0,&local_8);
  if (in_ECX == (char *)0x0) {
    in_ECX = (char *)*param_1;
  }
  pcVar4 = in_ECX;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  local_4 = ((int)pcVar4 - (int)(in_ECX + 1)) * 2;
  local_8 = in_ECX;
  uVar5 = FUN_007eb130(0x1b,0,0,&local_8);
  if (param_3 == (char *)0x0) {
    param_3 = (char *)*param_2;
  }
  pcVar4 = param_3;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  local_4 = ((int)pcVar4 - (int)(param_3 + 1)) * 2;
  local_8 = param_3;
  uVar6 = FUN_007eb130(0x1b,0,0,&local_8);
  uVar2 = FUN_007eb130(0x73,uVar5,uVar2,0);
  uVar3 = FUN_007eb130(0x73,uVar6,uVar3,0);
  iVar7 = FUN_007eb130(0x47,uVar2,uVar3,0);
  *(byte *)(iVar7 + 3) = *(byte *)(iVar7 + 3) | 1;
  uVar2 = FUN_007eb2a0(*param_4,iVar7);
  *param_4 = uVar2;
  return;
}


// ==== FUN_007e6860 @ 0x007e6860 ====

void FUN_007e6860(int param_1)

{
  if (param_1 != 0) {
    do {
      *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 1;
      FUN_007e6860(*(undefined4 *)(param_1 + 8));
      param_1 = *(int *)(param_1 + 0xc);
    } while (param_1 != 0);
  }
  return;
}


// ==== FUN_007e6890 @ 0x007e6890 ====

undefined4 FUN_007e6890(undefined4 param_1,int param_2)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int local_1c;
  short *local_18;
  int *local_14;
  int local_4;
  
  psVar1 = *(short **)(param_2 + 8);
  local_4 = 0;
  if (0 < *psVar1 + -1) {
    local_18 = psVar1 + 0x1a;
    local_14 = (int *)(psVar1 + 0x10);
    do {
      iVar2 = local_14[-4];
      iVar3 = *(int *)(local_18 + 2);
      if ((iVar2 != 0) && (iVar3 != 0)) {
        if ((*(byte *)(local_14 + -2) & 2) != 0) {
          if ((*local_14 != 0) || (local_14[1] != 0)) {
            FUN_007d0820(param_1,s_a_NATURAL_join_may_not_have_an_O_00a0196c,0);
            return 1;
          }
          local_1c = 0;
          if (0 < *(int *)(iVar2 + 4)) {
            iVar8 = 0;
            do {
              iVar5 = FUN_007e6710(*(undefined4 *)(*(int *)(iVar2 + 8) + iVar8));
              if (-1 < iVar5) {
                FUN_007e6750(iVar2,iVar3,*(undefined4 *)local_18,param_2 + 0xc);
              }
              local_1c = local_1c + 1;
              iVar8 = iVar8 + 0x14;
            } while (local_1c < *(int *)(iVar2 + 4));
          }
        }
        if (*local_14 != 0) {
          if (local_14[1] != 0) {
            FUN_007d0820(param_1,s_cannot_have_both_ON_and_USING_cl_00a01934);
            return 1;
          }
          FUN_007e6860(*local_14);
          uVar6 = FUN_007eb2a0(*(undefined4 *)(param_2 + 0xc),*local_14);
          *(undefined4 *)(param_2 + 0xc) = uVar6;
          *local_14 = 0;
        }
        piVar4 = (int *)local_14[1];
        if ((piVar4 != (int *)0x0) && (local_1c = 0, 0 < *piVar4)) {
          do {
            uVar6 = *(undefined4 *)(piVar4[2] + local_1c * 8);
            iVar8 = 0;
            if (*(int *)(iVar2 + 4) < 1) {
LAB_007e69ff:
              FUN_007d0820(param_1,s_cannot_join_using_column__s___co_00a019a0,uVar6);
              return 1;
            }
            iVar5 = 0;
            while (iVar7 = FUN_007d08e0(*(undefined4 *)(iVar5 + *(int *)(iVar2 + 8)),uVar6),
                  iVar7 != 0) {
              iVar8 = iVar8 + 1;
              iVar5 = iVar5 + 0x14;
              if (*(int *)(iVar2 + 4) <= iVar8) goto LAB_007e69ff;
            }
            if ((iVar8 < 0) || (iVar8 = FUN_007e6710(uVar6), iVar8 < 0)) goto LAB_007e69ff;
            FUN_007e6750(iVar2,iVar3,*(undefined4 *)local_18,param_2 + 0xc);
            local_1c = local_1c + 1;
          } while (local_1c < *piVar4);
        }
      }
      local_4 = local_4 + 1;
      local_18 = local_18 + 0x14;
      local_14 = local_14 + 10;
    } while (local_4 < *psVar1 + -1);
  }
  return 0;
}


// ==== FUN_007e6af0 @ 0x007e6af0 ====

void FUN_007e6af0(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_007ea740(*param_1);
    FUN_007d3a10(param_1[2]);
    FUN_007eabc0(param_1[3]);
    FUN_007ea740(param_1[4]);
    FUN_007eabc0(param_1[5]);
    FUN_007ea740(param_1[6]);
    FUN_007e6af0(param_1[7]);
    FUN_007eabc0(param_1[8]);
    FUN_007eabc0(param_1[9]);
    FUN_007d05b0(param_1);
  }
  return;
}


// ==== FUN_007e6b60 @ 0x007e6b60 ====

void FUN_007e6b60(undefined4 param_1,undefined4 param_2)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *in_EAX) {
    iVar1 = 0;
    do {
      FUN_007ec010(param_1,*(undefined4 *)(iVar1 + in_EAX[2]));
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0xc;
    } while (iVar2 < *in_EAX);
  }
  FUN_007dc140(param_2,0x5b,*in_EAX,0);
  FUN_007dc140(param_2,0x15,0,0);
  return;
}


// ==== FUN_007e6bc0 @ 0x007e6bc0 ====

void FUN_007e6bc0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int in_EAX;
  
  if (-1 < *(int *)(in_EAX + 0x2c)) {
    FUN_007dc320();
    FUN_007dc140();
    FUN_007dc140();
    if (0 < param_3) {
      FUN_007dc140();
    }
    FUN_007dc140();
  }
  if (-1 < *(int *)(in_EAX + 0x28)) {
    FUN_007dc140();
  }
  return;
}


// ==== FUN_007e6c50 @ 0x007e6c50 ====

undefined4
FUN_007e6c50(int param_1,int param_2,int *param_3,undefined4 param_4,int param_5,int param_6,
            undefined4 param_7,uint param_8,undefined4 param_9,undefined4 param_10,
            undefined4 param_11)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined1 uVar4;
  int in_EAX;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  
  iVar9 = param_5;
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 != 0) {
    if (((param_6 < 0) || (param_3 == (int *)0x0)) || (bVar2 = true, *param_3 < 1)) {
      bVar2 = false;
    }
    if ((param_5 == 0) && (!bVar2)) {
      if (-1 < *(int *)(param_2 + 0x2c)) {
        iVar5 = FUN_007dc320(iVar1);
        FUN_007dc140(iVar1,0x2f,*(undefined4 *)(param_2 + 0x2c),0);
        FUN_007dc140(iVar1,4,*(undefined4 *)(param_2 + 0x2c),iVar5 + 3);
        FUN_007dc140(iVar1,0x61,0,param_9);
      }
      if (-1 < *(int *)(param_2 + 0x28)) {
        FUN_007dc140(iVar1,0x2f,*(int *)(param_2 + 0x28),param_10);
      }
    }
    iVar5 = 0;
    if (in_EAX < 1) {
      in_EAX = *param_3;
      if (0 < in_EAX) {
        iVar9 = 0;
        do {
          FUN_007ec010(param_1,*(undefined4 *)(param_3[2] + iVar9));
          iVar5 = iVar5 + 1;
          iVar9 = iVar9 + 0xc;
        } while (iVar5 < *param_3);
        iVar9 = param_5;
      }
    }
    else {
      do {
        FUN_007dc140(iVar1,2,param_4,iVar5);
        iVar5 = iVar5 + 1;
      } while (iVar5 < in_EAX);
    }
    if (bVar2) {
      FUN_007dc140(iVar1,0x5b,-*param_3,0);
      iVar6 = FUN_007dc320(iVar1);
      iVar5 = param_6;
      FUN_007dc140(iVar1,0x6f,param_6,iVar6 + 3);
      FUN_007dc140(iVar1,0xb,*param_3 + 1,0);
      FUN_007dc140(iVar1,0x61,0,param_9);
      FUN_007dc140(iVar1,0x6e,iVar5,0);
      if (iVar9 == 0) {
        FUN_007e6bc0(param_9,param_10,in_EAX);
      }
    }
    switch(param_7) {
    case 1:
    case 10:
      if (iVar9 == 0) {
        FUN_007dc140(iVar1,0x39,in_EAX,0);
        return 0;
      }
      FUN_007dc140(iVar1,0x5b,in_EAX,0);
      FUN_007e6b60(param_1,iVar1);
      return 0;
    case 2:
    case 0xc:
      if (iVar9 == 0) {
        FUN_007dc140(iVar1,0x78,param_8,1);
        FUN_007dc140(iVar1,0x61,0,param_10);
        return 0;
      }
      FUN_007e6b60(param_1,iVar1);
      return 0;
    case 3:
      iVar5 = FUN_007dc320(iVar1);
      FUN_007dc140(iVar1,0x45,0xffffffff,iVar5 + 3);
      FUN_007dc140(iVar1,0xb,1,0);
      uVar7 = FUN_007dc140(iVar1,0x61,0,0);
      uVar3 = param_8;
      if (iVar9 == 0) {
        param_1 = CONCAT31(param_1._1_3_,(char)(param_8 >> 0x10));
        uVar4 = FUN_007ea1b0(*(undefined4 *)param_3[2],param_1);
        param_1 = CONCAT31(param_1._1_3_,uVar4);
        FUN_007dda80(iVar1,0x5b,1,0,&param_1,1);
        FUN_007dc140(iVar1,0x6e,uVar3 & 0xffff,0);
        uVar8 = FUN_007dc320(iVar1);
        FUN_007dc400(iVar1,uVar7,uVar8);
        return 0;
      }
      FUN_007e6b60(param_1,iVar1);
      uVar8 = FUN_007dc320(iVar1);
      FUN_007dc400(iVar1,uVar7,uVar8);
      return 0;
    default:
      FUN_007dc140(iVar1,0xb,in_EAX,0);
      break;
    case 5:
      FUN_007dc140(iVar1,0x5b,in_EAX,0);
      FUN_007dc430(iVar1,0xffffffff,param_11,0xfffffffe);
      FUN_007dc140(iVar1,0x6e,param_8,0);
      return 0;
    case 6:
      iVar9 = FUN_007dc140(iVar1,0x5b,in_EAX,0);
      FUN_007dc430(iVar1,0xffffffff,param_11,0xfffffffe);
      uVar3 = param_8;
      FUN_007dc140(iVar1,0x23,param_8,iVar9 + 3);
      FUN_007dc140(iVar1,0x5c,uVar3,0);
      return 0;
    case 7:
    case 8:
      FUN_007dc140(iVar1,0x5b,in_EAX,0);
      uVar3 = param_8;
      if (iVar9 == 0) {
        FUN_007dc140(iVar1,0x19,param_8,0);
        FUN_007dc140(iVar1,0x66,1,0);
        FUN_007dc140(iVar1,0x71,uVar3,0);
        return 0;
      }
      FUN_007e6b60(param_1,iVar1);
      return 0;
    case 0xb:
      if (iVar9 == 0) {
        FUN_007dc140(iVar1,0x30,0,param_8);
        return 0;
      }
      FUN_007dc140(iVar1,0x5b,in_EAX,0);
      FUN_007e6b60(param_1,iVar1);
      return 0;
    }
  }
  return 0;
}


// ==== FUN_007e7090 @ 0x007e7090 ====

void FUN_007e7090(int *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *local_10;
  
  FUN_007dc190();
  FUN_007dc190();
  iVar7 = *param_1;
  if (param_4 != 10) {
    piVar1 = *(int **)(param_2 + 0x18);
    iVar2 = *piVar1;
    iVar3 = FUN_007d0550(iVar2 * 5 + 0x10);
    if (iVar3 != 0) {
      *(int *)(iVar3 + 8) = iVar3 + 0xc + iVar2 * 4;
      *(int *)(iVar3 + 4) = iVar2;
      iVar6 = 0;
      if (0 < iVar2) {
        local_10 = (int *)(iVar3 + 0xc);
        iVar5 = 0;
        do {
          iVar4 = FUN_007ea170(param_1,*(undefined4 *)(iVar5 + piVar1[2]));
          *local_10 = iVar4;
          if (iVar4 == 0) {
            *local_10 = *(int *)(iVar7 + 0x18);
          }
          *(undefined1 *)(*(int *)(iVar3 + 8) + iVar6) = *(undefined1 *)(iVar5 + 8 + piVar1[2]);
          iVar6 = iVar6 + 1;
          local_10 = local_10 + 1;
          iVar5 = iVar5 + 0xc;
        } while (iVar6 < iVar2);
      }
      FUN_007dda80();
      FUN_007dc140();
      if (-1 < *(int *)(param_2 + 0x2c)) {
        FUN_007dc320();
        FUN_007dc140();
        FUN_007dc140();
        FUN_007dc140();
        FUN_007dc140();
      }
      if (-1 < *(int *)(param_2 + 0x28)) {
        FUN_007dc140();
      }
      switch(param_4) {
      case 1:
      case 0xb:
        FUN_007dc140();
        FUN_007dc140();
        iVar7 = 0;
        if (0 < param_3) {
          do {
            FUN_007dc140();
            iVar7 = iVar7 + 1;
          } while (iVar7 < param_3);
        }
        FUN_007dc140();
        FUN_007dc140();
        break;
      case 2:
      case 0xc:
        FUN_007dc140();
        FUN_007dc140();
        break;
      case 3:
        FUN_007dc320();
        FUN_007dc140();
        FUN_007dc140();
        FUN_007dc320();
        FUN_007dc140();
        FUN_007dda80();
        FUN_007dc140();
        break;
      case 7:
      case 8:
        FUN_007dc140();
        FUN_007dc140();
        FUN_007dc140();
      }
      FUN_007dc140();
      FUN_007dc1e0();
      FUN_007dc140();
      FUN_007dc1e0();
      FUN_007dc140();
    }
  }
  return;
}


// ==== FUN_007e7390 @ 0x007e7390 ====

char * FUN_007e7390(int param_1,char *param_2)

{
  short *psVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int local_24;
  undefined1 local_20 [4];
  int local_1c;
  int local_4;
  
  if ((param_2 != (char *)0x0) && (*(int *)(param_1 + 4) != 0)) {
    if (*param_2 == '\a') {
      local_24 = *(int *)(param_2 + 0x28);
      iVar6 = 0;
      do {
        if (iVar6 != 0) goto LAB_007e743c;
        psVar1 = *(short **)(param_1 + 4);
        iVar5 = (int)*psVar1;
        iVar3 = 0;
        if (0 < iVar5) {
          piVar4 = (int *)(psVar1 + 0xe);
          do {
            if (*piVar4 == *(int *)(param_2 + 0x24)) break;
            iVar3 = iVar3 + 1;
            piVar4 = piVar4 + 10;
          } while (iVar3 < iVar5);
        }
        if (iVar3 < iVar5) {
          iVar6 = *(int *)(psVar1 + iVar3 * 0x14 + 8);
        }
        else {
          param_1 = *(int *)(param_1 + 0x1c);
        }
      } while (param_1 != 0);
      if (iVar6 == 0) {
        return &DAT_00a019e0;
      }
LAB_007e743c:
      if ((local_24 < 0) && (local_24 = *(int *)(iVar6 + 0xc), local_24 < 0)) {
        return s_INTEGER_00a00858;
      }
      return *(char **)(*(int *)(iVar6 + 8) + 8 + local_24 * 0x14);
    }
    if (*param_2 == 'q') {
      local_1c = (*(int **)(param_2 + 0x34))[2];
      local_4 = param_1;
      pcVar2 = (char *)FUN_007e7390(local_20,**(undefined4 **)(**(int **)(param_2 + 0x34) + 8));
      return pcVar2;
    }
  }
  return (char *)0x0;
}


// ==== FUN_007e7480 @ 0x007e7480 ====

void FUN_007e7480(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_EAX;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  undefined1 local_20 [32];
  
  piVar3 = param_1;
  uVar2 = *(undefined4 *)(in_EAX + 0xc);
  iVar6 = *param_1;
  iVar7 = 0;
  if (0 < iVar6) {
    param_1 = (int *)0x0;
    do {
      pcVar4 = (char *)FUN_007e7390(local_20,*(undefined4 *)(piVar3[2] + (int)param_1));
      if (pcVar4 != (char *)0x0) {
        pcVar5 = pcVar4;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        FUN_007dcd30(uVar2,iVar6 + iVar7,pcVar4,(int)pcVar5 - (int)(pcVar4 + 1));
      }
      iVar6 = *piVar3;
      iVar7 = iVar7 + 1;
      param_1 = (int *)((int)param_1 + 0xc);
    } while (iVar7 < iVar6);
  }
  return;
}


// ==== FUN_007e7500 @ 0x007e7500 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007e7500(int *param_1,short *param_2,int *param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  int *piVar10;
  int local_34;
  undefined4 local_30;
  int local_2c;
  uint local_28;
  char local_24 [32];
  undefined4 local_4;
  
  iVar8 = param_1[3];
  local_4 = DAT_00b49670;
  if (((((char)param_1[0x1d] == '\0') && ((char)param_1[4] == '\0')) && (iVar8 != 0)) &&
     (DAT_00b5c4c4 == 0)) {
    *(undefined1 *)(param_1 + 4) = 1;
    local_28 = *(uint *)(*param_1 + 8) >> 6 & 1;
    uVar6 = *(uint *)(*param_1 + 8) >> 5 & 1;
    local_2c = iVar8;
    FUN_007dccf0(iVar8,*param_3);
    iVar7 = 0;
    if (0 < *param_3) {
      local_34 = 0;
      do {
        pcVar3 = *(char **)(local_34 + param_3[2]);
        if (pcVar3 != (char *)0x0) {
          pcVar9 = *(char **)(local_34 + param_3[2] + 4);
          if (pcVar9 == (char *)0x0) {
            if ((*pcVar3 == '\a') && (param_2 != (short *)0x0)) {
              iVar5 = *(int *)(pcVar3 + 0x28);
              iVar4 = 0;
              if (0 < *param_2) {
                piVar10 = (int *)(param_2 + 0xe);
                do {
                  if (*piVar10 == *(int *)(pcVar3 + 0x24)) break;
                  iVar4 = iVar4 + 1;
                  piVar10 = piVar10 + 10;
                } while (iVar4 < *param_2);
                iVar8 = local_2c;
              }
              piVar10 = *(int **)(param_2 + iVar4 * 0x14 + 8);
              if ((iVar5 < 0) && (iVar5 = piVar10[3], iVar5 < 0)) {
                pcVar9 = s_rowid_00a019f4;
              }
              else {
                pcVar9 = *(char **)(piVar10[2] + iVar5 * 0x14);
              }
              if (local_28 == 0) {
                if (uVar6 == 0) {
                  pcVar2 = *(char **)(pcVar3 + 0x1c);
                  if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
                    FUN_007dcd30(iVar8,iVar7,pcVar2,*(uint *)(pcVar3 + 0x20) >> 1);
                    goto LAB_007e76fb;
                  }
                  if (*param_2 < 2) goto LAB_007e769c;
                }
              }
              else if (uVar6 == 0) {
LAB_007e769c:
                pcVar3 = pcVar9;
                do {
                  cVar1 = *pcVar3;
                  pcVar3 = pcVar3 + 1;
                } while (cVar1 != '\0');
                FUN_007dcd30(iVar8,iVar7,pcVar9,(int)pcVar3 - (int)(pcVar9 + 1));
                goto LAB_007e76fb;
              }
              iVar5 = *(int *)(param_2 + iVar4 * 0x14 + 6);
              local_30 = 0;
              if ((uVar6 != 0) || (iVar5 == 0)) {
                iVar5 = *piVar10;
              }
              FUN_007d0700(&local_30,iVar5,&DAT_00a0119c,pcVar9,0);
              FUN_007dcd30(iVar8,iVar7,local_30,0xffffffff);
            }
            else {
              pcVar9 = *(char **)(pcVar3 + 0x1c);
              if ((pcVar9 == (char *)0x0) || (*pcVar9 == '\0')) {
                _sprintf(local_24,s_column_d_00a019e8,iVar7 + 1);
                FUN_007dcd30(iVar8,iVar7,local_24,0);
              }
              else {
                FUN_007dcd30(iVar8,iVar7,pcVar9,*(uint *)(pcVar3 + 0x20) >> 1);
              }
            }
          }
          else {
            pcVar3 = pcVar9;
            do {
              cVar1 = *pcVar3;
              pcVar3 = pcVar3 + 1;
            } while (cVar1 != '\0');
            FUN_007dcd30(iVar8,iVar7,pcVar9,(int)pcVar3 - (int)(pcVar9 + 1));
          }
        }
LAB_007e76fb:
        iVar7 = iVar7 + 1;
        local_34 = local_34 + 0xc;
      } while (iVar7 < *param_3);
    }
    FUN_007e7480(param_3);
  }
  return;
}


// ==== FUN_007e7740 @ 0x007e7740 ====

char * FUN_007e7740(void)

{
  int in_EAX;
  
  if (in_EAX == 0x6e) {
    return s_UNION_ALL_00a019fc;
  }
  if (in_EAX == 0x6f) {
    return s_INTERSECT_00a01a08;
  }
  if (in_EAX == 0x70) {
    return s_EXCEPT_00a01a14;
  }
  return s_UNION_00a01a1c;
}


// ==== FUN_007e7770 @ 0x007e7770 ====

undefined4 * FUN_007e7770(int *param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  char *pcVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  char *pcVar14;
  int local_3c;
  int local_38;
  int *local_30;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar5 = FUN_007e79d0(param_1,param_3);
  if (iVar5 != 0) {
    return (undefined4 *)0x0;
  }
  iVar5 = FUN_007e9090(param_1,param_3,0);
  if ((iVar5 != 0) || (puVar6 = (undefined4 *)FUN_007d0550(0x38), puVar6 == (undefined4 *)0x0)) {
    return (undefined4 *)0x0;
  }
  puVar6[9] = 1;
  if (param_2 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = FUN_007d0640(param_2);
  }
  *puVar6 = uVar7;
  piVar2 = (int *)*param_3;
  iVar5 = *piVar2;
  puVar6[1] = iVar5;
  iVar5 = FUN_007d0550(iVar5 * 0x14);
  puVar6[2] = iVar5;
  local_3c = 0;
  if (0 < (int)puVar6[1]) {
    local_30 = (int *)(iVar5 + 0xc);
    local_38 = 0;
    do {
      puVar1 = (undefined4 *)(piVar2[2] + local_38);
      pcVar3 = (char *)*puVar1;
      iVar8 = puVar1[1];
      if (iVar8 == 0) {
        if ((*pcVar3 == 's') && (iVar8 = *(int *)(pcVar3 + 0xc), iVar8 != 0)) {
          pcVar9 = (char *)(iVar8 + 0x14);
          if ((*(char **)(iVar8 + 0x14) == (char *)0x0) || (**(char **)(iVar8 + 0x14) == '\0'))
          goto LAB_007e7867;
          pcVar14 = &DAT_00a01a2c;
        }
        else {
LAB_007e7867:
          pcVar9 = pcVar3 + 0x1c;
          if ((*(char **)pcVar9 == (char *)0x0) || (**(char **)pcVar9 == '\0')) {
            pcVar9 = (char *)(local_3c + 1);
            pcVar14 = s_column_d_00a019e8;
          }
          else {
            pcVar14 = &DAT_00a01a2c;
          }
        }
        iVar8 = FUN_007e4830(pcVar14,pcVar9);
      }
      else {
        iVar8 = FUN_007d0640(iVar8);
      }
      FUN_007d0860(iVar8);
      if (DAT_00b5c4c4 != 0) {
        FUN_007d05b0(iVar8);
        FUN_007d25e0(0,puVar6);
        return (undefined4 *)0x0;
      }
      iVar12 = 0;
      iVar13 = 0;
      iVar11 = iVar8;
      if (0 < local_38) {
        do {
          iVar10 = FUN_007d08e0(*(undefined4 *)(iVar5 + iVar13 * 0x14),iVar11);
          if (iVar10 == 0) {
            iVar12 = iVar12 + 1;
            iVar11 = FUN_007e4830(s__s__d_00a01a24,iVar8,iVar12);
            iVar13 = -1;
            if (iVar11 == 0) break;
          }
          iVar13 = iVar13 + 1;
        } while (iVar13 < local_3c);
        if (iVar8 != iVar11) {
          FUN_007d05b0(iVar8);
        }
      }
      local_20 = 0;
      local_18 = 0;
      local_14 = 0;
      local_10 = 0;
      local_c = 0;
      local_30[-3] = iVar11;
      local_1c = param_3[2];
      local_8 = 0;
      local_4 = 0;
      uVar7 = FUN_007e7390(&local_20,pcVar3);
      iVar8 = FUN_007d0640(uVar7);
      local_30[-1] = iVar8;
      uVar4 = FUN_007ea140(pcVar3);
      *(undefined1 *)((int)local_30 + 6) = uVar4;
      iVar8 = FUN_007ea170(param_1,pcVar3);
      *local_30 = iVar8;
      if (iVar8 == 0) {
        *local_30 = *(int *)(*param_1 + 0x18);
      }
      local_30 = local_30 + 5;
      local_3c = local_3c + 1;
      local_38 = local_38 + 0xc;
    } while (local_3c < (int)puVar6[1]);
  }
  puVar6[3] = 0xffffffff;
  return puVar6;
}


// ==== FUN_007e79d0 @ 0x007e79d0 ====

undefined4 FUN_007e79d0(int *param_1,int *param_2)

{
  char cVar1;
  short *psVar2;
  int *piVar3;
  char *pcVar4;
  bool bVar5;
  bool bVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  short *psVar14;
  undefined4 *puVar15;
  int *piVar16;
  undefined4 *puVar17;
  int local_44;
  int *local_40;
  int local_3c;
  int *local_38;
  char *local_30;
  int local_28;
  short *local_24;
  int local_1c;
  int local_10;
  undefined4 *local_c;
  undefined4 local_8;
  
  if (((param_2 == (int *)0x0) || (psVar2 = (short *)param_2[2], psVar2 == (short *)0x0)) ||
     (DAT_00b5c4c4 != 0)) {
    return 1;
  }
  piVar3 = (int *)*param_2;
  FUN_007d38e0(param_1,psVar2);
  local_44 = 0;
  psVar14 = psVar2 + 2;
  if (0 < *psVar2) {
    do {
      if (*(int *)(psVar14 + 6) != 0) {
        return 0;
      }
      if (*(int *)(psVar14 + 2) == 0) {
        if (*(int *)(psVar14 + 4) == 0) {
          uVar7 = FUN_007e4830(s_sqlite_subquery__p__00a01a4c,*(undefined4 *)(psVar14 + 8));
          *(undefined4 *)(psVar14 + 4) = uVar7;
        }
        iVar8 = FUN_007e7770(param_1,*(undefined4 *)(psVar14 + 4),*(undefined4 *)(psVar14 + 8));
        *(int *)(psVar14 + 6) = iVar8;
        if (iVar8 == 0) {
          return 1;
        }
        *(undefined1 *)(iVar8 + 0x1e) = 1;
      }
      else {
        iVar8 = FUN_007d2330(param_1,*(int *)(psVar14 + 2),*(undefined4 *)psVar14);
        *(int *)(psVar14 + 6) = iVar8;
        if (iVar8 == 0) {
          return 1;
        }
        *(int *)(iVar8 + 0x24) = *(int *)(iVar8 + 0x24) + 1;
        if (*(int *)(iVar8 + 0x18) != 0) {
          iVar12 = FUN_007d45e0(param_1,iVar8);
          if (iVar12 != 0) {
            return 1;
          }
          if (*(int *)(psVar14 + 8) == 0) {
            uVar7 = FUN_007ead10(*(undefined4 *)(iVar8 + 0x18));
            *(undefined4 *)(psVar14 + 8) = uVar7;
          }
        }
      }
      local_44 = local_44 + 1;
      psVar14 = psVar14 + 0x14;
    } while (local_44 < *psVar2);
  }
  iVar8 = FUN_007e6890(param_1,param_2);
  if (iVar8 != 0) {
    return 1;
  }
  iVar8 = *piVar3;
  iVar12 = 0;
  if (0 < iVar8) {
    puVar15 = (undefined4 *)piVar3[2];
    do {
      pcVar4 = (char *)*puVar15;
      if ((*pcVar4 == 'n') ||
         (((*pcVar4 == 's' && (*(char **)(pcVar4 + 0xc) != (char *)0x0)) &&
          ((**(char **)(pcVar4 + 0xc) == 'n' &&
           ((*(char **)(pcVar4 + 8) != (char *)0x0 && (**(char **)(pcVar4 + 8) == '\x1b'))))))))
      break;
      iVar12 = iVar12 + 1;
      puVar15 = puVar15 + 3;
    } while (iVar12 < iVar8);
  }
  local_8 = 0;
  if (iVar12 < iVar8) {
    local_c = (undefined4 *)piVar3[2];
    local_40 = (int *)0x0;
    if (((*(uint *)(*param_1 + 8) & 0x20) == 0) ||
       (bVar5 = true, (*(uint *)(*param_1 + 8) & 0x40) != 0)) {
      bVar5 = false;
    }
    local_10 = 0;
    piVar16 = (int *)0x0;
    if (0 < iVar8) {
      do {
        pcVar4 = (char *)*local_c;
        cVar1 = *pcVar4;
        if ((cVar1 == 'n') ||
           (((cVar1 == 's' && (*(char **)(pcVar4 + 0xc) != (char *)0x0)) &&
            (**(char **)(pcVar4 + 0xc) == 'n')))) {
          bVar6 = false;
          if ((cVar1 == 's') && (*(int *)(pcVar4 + 8) != 0)) {
            local_3c = FUN_007d2730(*(int *)(pcVar4 + 8) + 0x14);
          }
          else {
            local_3c = 0;
          }
          local_44 = 0;
          if (*psVar2 < 1) {
LAB_007e7e6d:
            if (local_3c == 0) {
              FUN_007d0820(param_1,s_no_tables_specified_00a01a30);
            }
            else {
              FUN_007d0820(param_1,s__t_no_such_table___s_00a00115 + 3,local_3c);
            }
            local_8 = 1;
          }
          else {
            local_24 = psVar2 + 6;
            local_38 = (int *)(psVar2 + -0xc);
            do {
              local_30 = *(char **)local_24;
              puVar15 = *(undefined4 **)(local_24 + 2);
              if ((local_30 == (char *)0x0) || (*local_30 == '\0')) {
                local_30 = (char *)*puVar15;
              }
              if ((local_3c == 0) ||
                 (((local_30 != (char *)0x0 && (*local_30 != '\0')) &&
                  (iVar8 = FUN_007d08e0(local_3c,local_30), iVar8 == 0)))) {
                bVar6 = true;
                local_1c = 0;
                if (0 < (int)puVar15[1]) {
                  local_28 = 0;
                  do {
                    pcVar4 = *(char **)(local_28 + puVar15[2]);
                    if (local_44 < 1) {
LAB_007e7d16:
                      iVar8 = FUN_007eb130(0x1b,0,0,0);
                      if (iVar8 == 0) break;
                      puVar17 = (undefined4 *)(iVar8 + 0x14);
                      *puVar17 = pcVar4;
                      pcVar10 = pcVar4;
                      do {
                        cVar1 = *pcVar10;
                        pcVar10 = pcVar10 + 1;
                      } while (cVar1 != '\0');
                      *(int *)(iVar8 + 0x18) = ((int)pcVar10 - (int)(pcVar4 + 1)) * 2;
                      if ((local_30 == (char *)0x0) || ((!bVar5 && (*psVar2 < 2)))) {
                        puVar11 = (undefined4 *)(iVar8 + 0x1c);
                        *puVar11 = *puVar17;
                        *(undefined4 *)(iVar8 + 0x20) = *(undefined4 *)(iVar8 + 0x18);
                      }
                      else {
                        iVar12 = FUN_007eb130(0x1b,0,0,0);
                        iVar8 = FUN_007eb130(0x73,iVar12,iVar8,0);
                        if (iVar8 == 0) break;
                        *(char **)(iVar12 + 0x14) = local_30;
                        pcVar10 = local_30;
                        do {
                          cVar1 = *pcVar10;
                          pcVar10 = pcVar10 + 1;
                        } while (cVar1 != '\0');
                        *(int *)(iVar12 + 0x18) = ((int)pcVar10 - (int)(local_30 + 1)) * 2;
                        pcVar10 = (char *)FUN_007e4830(s__s__s_00a01a44,local_30,pcVar4);
                        puVar11 = (undefined4 *)(iVar8 + 0x1c);
                        *puVar11 = pcVar10;
                        pcVar4 = pcVar10 + 1;
                        do {
                          cVar1 = *pcVar10;
                          pcVar10 = pcVar10 + 1;
                        } while (cVar1 != '\0');
                        *(int *)(iVar8 + 0x20) = ((int)pcVar10 - (int)pcVar4) * 2;
                        *(uint *)(iVar8 + 0x20) = *(uint *)(iVar8 + 0x20) | 1;
                        *(undefined4 *)(iVar8 + 0x14) = 0;
                        *(undefined4 *)(iVar8 + 0x18) = 0;
                      }
                      if (bVar5) {
                        puVar17 = puVar11;
                      }
                      local_40 = (int *)FUN_007eadd0(local_40,iVar8,puVar17);
                    }
                    else {
                      if ((*(byte *)(local_38 + 2) & 2) != 0) {
                        iVar8 = *local_38;
                        iVar12 = 0;
                        if (0 < *(int *)(iVar8 + 4)) {
                          iVar13 = 0;
                          do {
                            iVar9 = FUN_007d08e0(*(undefined4 *)(*(int *)(iVar8 + 8) + iVar13),
                                                 pcVar4);
                            if (iVar9 == 0) {
                              if (-1 < iVar12) goto LAB_007e7e11;
                              break;
                            }
                            iVar12 = iVar12 + 1;
                            iVar13 = iVar13 + 0x14;
                          } while (iVar12 < *(int *)(iVar8 + 4));
                        }
                      }
                      iVar8 = FUN_007d39c0(local_38[5],pcVar4);
                      if (iVar8 < 0) goto LAB_007e7d16;
                    }
LAB_007e7e11:
                    local_1c = local_1c + 1;
                    local_28 = local_28 + 0x14;
                  } while (local_1c < (int)puVar15[1]);
                }
              }
              local_38 = local_38 + 10;
              local_24 = local_24 + 0x14;
              local_44 = local_44 + 1;
            } while (local_44 < *psVar2);
            if (!bVar6) goto LAB_007e7e6d;
          }
          FUN_007d05b0(local_3c);
        }
        else {
          local_40 = (int *)FUN_007eadd0(local_40,pcVar4,0);
          *(undefined4 *)(local_40[2] + -8 + *local_40 * 0xc) = local_c[1];
          *local_c = 0;
          local_c[1] = 0;
        }
        local_10 = local_10 + 1;
        local_c = local_c + 3;
        piVar16 = local_40;
      } while (local_10 < *piVar3);
    }
    FUN_007ea740(piVar3);
    *param_2 = (int)piVar16;
  }
  return local_8;
}


// ==== FUN_007e7f10 @ 0x007e7f10 ====

undefined4
FUN_007e7f10(undefined4 param_1,undefined4 *param_2,int *param_3,undefined4 param_4,int param_5)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int local_14;
  int local_c;
  int local_8;
  
  piVar8 = param_3;
  puVar4 = param_2;
  if ((param_2 == (undefined4 *)0x0) || (param_3 == (int *)0x0)) {
    return 1;
  }
  if ((param_5 != 0) && (iVar5 = 0, 0 < *param_3)) {
    iVar7 = 0;
    do {
      *(undefined1 *)(param_3[2] + 10 + iVar7) = 0;
      iVar5 = iVar5 + 1;
      iVar7 = iVar7 + 0xc;
    } while (iVar5 < *param_3);
  }
  iVar5 = FUN_007e79d0(param_1,param_2);
  if ((iVar5 != 0) ||
     ((iVar5 = puVar4[7], iVar5 != 0 &&
      (iVar5 = FUN_007e7f10(param_1,iVar5,piVar8,param_4,0), iVar5 != 0)))) {
    return 1;
  }
  piVar1 = (int *)*puVar4;
  local_8 = 0;
  if (*piVar8 < 1) {
    return 0;
  }
  local_14 = 0;
  do {
    pcVar2 = *(char **)(local_14 + piVar8[2]);
    param_2 = (undefined4 *)0xffffffff;
    if (*(char *)(local_14 + piVar8[2] + 10) == '\0') {
      iVar5 = FUN_007ea890(pcVar2,&param_2);
      if (iVar5 != 0) {
        if (((int)param_2 < 1) || (*piVar1 < (int)param_2)) {
          FUN_007d0820(param_1,s_ORDER_BY_position__d_should_be_b_00a01a9c,param_2,*piVar1);
          return 1;
        }
        if (param_5 == 0) goto LAB_007e80fb;
        param_2 = (undefined4 *)((int)param_2 + -1);
      }
      local_c = 0;
      if ((int)param_2 < 0) {
        iVar7 = 0;
        iVar5 = (int)param_2;
        do {
          if (*piVar1 <= local_c) {
            if (iVar5 < 0) goto LAB_007e80f3;
            break;
          }
          iVar3 = *(int *)(iVar7 + 4 + piVar1[2]);
          if ((iVar3 != 0) && ((*pcVar2 == '\x1b' || (*pcVar2 == 'Z')))) {
            uVar6 = FUN_007d2730(pcVar2 + 0x14);
            iVar5 = FUN_007d08e0(iVar3,uVar6);
            if (iVar5 == 0) {
              param_2 = (undefined4 *)local_c;
            }
            FUN_007d05b0(uVar6);
            iVar5 = (int)param_2;
          }
          if (iVar5 < 0) {
            iVar5 = FUN_007ea9f0(pcVar2,*(undefined4 *)(iVar7 + piVar1[2]));
            if (iVar5 == 0) {
              iVar5 = (int)param_2;
            }
            else {
              iVar5 = local_c;
              param_2 = (undefined4 *)local_c;
            }
          }
          local_c = local_c + 1;
          iVar7 = iVar7 + 0xc;
          piVar8 = param_3;
        } while (iVar5 < 0);
      }
      *pcVar2 = '\a';
      *(undefined4 **)(pcVar2 + 0x28) = param_2;
      *(undefined4 *)(pcVar2 + 0x24) = param_4;
      pcVar2[0x2c] = -1;
      pcVar2[0x2d] = -1;
      pcVar2[0x2e] = -1;
      pcVar2[0x2f] = -1;
      *(undefined1 *)(piVar8[2] + 10 + local_14) = 1;
      if ((int)param_2 < 0) {
LAB_007e80f3:
        if (param_5 != 0) {
          FUN_007d0820(param_1,s_ORDER_BY_term_number__d_does_not_00a01a60,local_8 + 1);
          return 1;
        }
      }
    }
LAB_007e80fb:
    local_8 = local_8 + 1;
    local_14 = local_14 + 0xc;
    if (*piVar8 <= local_8) {
      return 0;
    }
  } while( true );
}


// ==== FUN_007e8190 @ 0x007e8190 ====

void FUN_007e8190(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[3] == 0) {
    uVar1 = FUN_007dc070(*param_1);
    param_1[3] = uVar1;
  }
  return;
}


// ==== FUN_007e81b0 @ 0x007e81b0 ====

void FUN_007e81b0(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  undefined4 *unaff_ESI;
  
  if (*(int *)(unaff_EBX + 0x20) != 0) {
    iVar1 = unaff_ESI[8];
    iVar2 = unaff_ESI[3];
    unaff_ESI[8] = iVar1 + 1;
    if (iVar2 == 0) {
      iVar2 = FUN_007dc070(*unaff_ESI);
      unaff_ESI[3] = iVar2;
      if (iVar2 == 0) {
        return;
      }
    }
    FUN_007ec010();
    FUN_007dc140(iVar2,0x24,0,0);
    FUN_007dc140(iVar2,0x57,0,0);
    FUN_007dc140(iVar2,0x78,iVar1,1);
    *(int *)(unaff_EBX + 0x28) = iVar1;
  }
  if (*(int *)(unaff_EBX + 0x24) != 0) {
    iVar1 = unaff_ESI[8];
    iVar2 = unaff_ESI[3];
    unaff_ESI[8] = iVar1 + 1;
    if (iVar2 == 0) {
      iVar2 = FUN_007dc070(*unaff_ESI);
      unaff_ESI[3] = iVar2;
      if (iVar2 == 0) {
        return;
      }
    }
    FUN_007ec010();
    FUN_007dc140(iVar2,0x24,0,0);
    FUN_007dc140(iVar2,0x57,0,0);
    FUN_007dc140(iVar2,0x78,iVar1,1);
    *(int *)(unaff_EBX + 0x2c) = iVar1;
  }
  return;
}


// ==== FUN_007e8280 @ 0x007e8280 ====

undefined4 FUN_007e8280(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  
  iVar1 = param_1[3];
  iVar2 = *param_1;
  iVar3 = FUN_007e79d0(param_1,param_2);
  if (iVar3 != 0) {
    return 0;
  }
  iVar3 = *(int *)*param_2;
  puVar4 = (undefined1 *)FUN_007d0550(iVar3 * 4 + 0x10);
  if (puVar4 == (undefined1 *)0x0) {
    return 0;
  }
  *puVar4 = *(undefined1 *)(iVar2 + 0x10);
  *(int *)(puVar4 + 4) = iVar3;
  if (0 < iVar3) {
    iVar8 = 0;
    piVar7 = (int *)(puVar4 + 0xc);
    do {
      iVar5 = FUN_007ea170(param_1,*(undefined4 *)(*(int *)(*param_2 + 8) + iVar8));
      *piVar7 = iVar5;
      if (iVar5 == 0) {
        *piVar7 = *(int *)(iVar2 + 0x18);
      }
      piVar7 = piVar7 + 1;
      iVar8 = iVar8 + 0xc;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  uVar6 = FUN_007dda80(iVar1,0x2e,param_3,0,puVar4,0xfffffff7);
  return uVar6;
}


// ==== FUN_007e8340 @ 0x007e8340 ====

undefined4 FUN_007e8340(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  uVar2 = FUN_007d5280(**(undefined4 **)(unaff_ESI + 0x30),0);
  **(undefined4 **)(unaff_ESI + 0x30) = uVar2;
  piVar1 = (int *)**(int **)(unaff_ESI + 0x30);
  if (piVar1 == (int *)0x0) {
    return 7;
  }
  *(undefined4 *)(piVar1[2] + -4 + *piVar1 * 8) = param_1;
  return 0;
}


// ==== FUN_007e8380 @ 0x007e8380 ====

void FUN_007e8380(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  
  if ((param_2[7] == 0) || (iVar1 = FUN_007e8380(param_1,param_2[7],param_3), iVar1 == 0)) {
    FUN_007ea170(param_1,*(undefined4 *)(*(int *)(*param_2 + 8) + param_3 * 0xc));
    return;
  }
  return;
}


// ==== FUN_007e83c0 @ 0x007e83c0 ====

int FUN_007e83c0(int *param_1,int *param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *in_EAX;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined4 uVar9;
  int *extraout_ECX;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  char *pcVar15;
  uint local_30;
  int *local_28;
  int *local_24;
  int *local_20;
  int local_1c;
  undefined4 local_18 [6];
  
  iVar10 = 0;
  local_24 = (int *)0x0;
  if ((in_EAX == (undefined4 *)0x0) ||
     (puVar2 = (undefined4 *)in_EAX[7], puVar2 == (undefined4 *)0x0)) {
    in_EAX[0xc] = 0;
    return 1;
  }
  if (puVar2[6] != 0) {
    cVar1 = *(char *)(in_EAX + 1);
    if (cVar1 == 'n') {
      pcVar4 = s_UNION_ALL_00a019fc;
    }
    else if (cVar1 == 'o') {
      pcVar4 = s_INTERSECT_00a01a08;
    }
    else if (cVar1 == 'p') {
      pcVar4 = s_EXCEPT_00a01a14;
    }
    else {
      pcVar4 = s_UNION_00a01a1c;
    }
    pcVar15 = s_ORDER_BY_clause_should_come_afte_00a01b54;
LAB_007e8425:
    FUN_007d0820(param_1,pcVar15,pcVar4);
LAB_007e842d:
    iVar10 = 1;
    goto LAB_007e8432;
  }
  if (puVar2[8] != 0) {
    pcVar4 = (char *)FUN_007e7740();
    pcVar15 = s_LIMIT_clause_should_come_after___00a01b24;
    param_1 = extraout_ECX;
    goto LAB_007e8425;
  }
  iVar5 = FUN_007e8190(param_1);
  if (iVar5 == 0) goto LAB_007e842d;
  if (in_EAX[0xc] == 0) {
    in_EAX[0xc] = &local_24;
  }
  bVar14 = param_2 == (int *)0x8;
  puVar2[0xc] = in_EAX[0xc];
  if (bVar14) {
    FUN_007dc140(iVar5,0x2e,param_3,0);
    local_18[1] = FUN_007dc140(iVar5,0x67,param_3,0);
    param_2 = (int *)0x7;
  }
  local_30 = (uint)bVar14;
  uVar11 = (uint)bVar14;
  switch(*(char *)(in_EAX + 1)) {
  case 'm':
  case 'p':
switchD_007e84d9_caseD_6d:
    local_1c = 0;
    local_20 = (int *)((uint)(*(char *)(in_EAX + 1) == 'n') * 2 + 5);
    if ((((param_2 == local_20) && (in_EAX[6] == 0)) && (in_EAX[8] == 0)) && (in_EAX[9] == 0)) {
      local_28 = (int *)param_3;
    }
    else {
      local_28 = (int *)param_1[7];
      param_1[7] = (int)local_28 + 1;
      if ((in_EAX[6] != 0) && (iVar10 = FUN_007e7f10(param_1), iVar10 != 0)) goto LAB_007e842d;
      uVar9 = FUN_007dc140(iVar5,0x2e,local_28,0);
      if ((*(char *)(in_EAX + 1) != 'n') && (iVar10 = FUN_007e8340(uVar9), iVar10 != 0)) break;
      uVar9 = FUN_007dc140(iVar5,0x67,local_28,0);
      local_18[bVar14 + 1] = uVar9;
      local_30 = bVar14 + 1;
    }
    iVar10 = FUN_007e9760(param_1,puVar2,local_20,local_28,0,0,0,param_4);
    if (iVar10 == 0) {
      local_1c = in_EAX[8];
      uVar9 = in_EAX[6];
      local_18[0] = in_EAX[9];
      in_EAX[7] = 0;
      in_EAX[6] = 0;
      in_EAX[8] = 0;
      in_EAX[9] = 0;
      iVar10 = FUN_007e9760(param_1);
      in_EAX[7] = puVar2;
      in_EAX[6] = uVar9;
      FUN_007eabc0(in_EAX[8]);
      in_EAX[8] = local_1c;
      in_EAX[9] = local_18[0];
      in_EAX[10] = 0xffffffff;
      in_EAX[0xb] = 0xffffffff;
      if (iVar10 == 0) {
        if ((param_2 != local_20) || (local_28 != (int *)param_3)) {
          if (param_2 == (int *)0x1) {
            FUN_007e7500(param_1,0,*in_EAX);
          }
          uVar9 = FUN_007dc190(iVar5);
          local_18[0] = uVar9;
          local_20 = (int *)FUN_007dc190(iVar5);
          FUN_007dc140(iVar5,0x79,local_28,uVar9);
          FUN_007e81b0();
          uVar9 = FUN_007dc320(iVar5);
          iVar10 = FUN_007e6c50(param_1);
          if (iVar10 != 0) goto LAB_007e842d;
          FUN_007dc1e0(iVar5,local_20);
          FUN_007dc140(iVar5,0x6c,local_28,uVar9);
          FUN_007dc1e0(iVar5,local_18[0]);
          FUN_007dc140(iVar5,0x1e,local_28,0);
          iVar10 = 0;
        }
LAB_007e89d1:
        uVar11 = local_30;
        goto switchD_007e84d9_default;
      }
    }
    break;
  case 'n':
    if (in_EAX[6] != 0) goto switchD_007e84d9_caseD_6d;
    puVar2[8] = in_EAX[8];
    puVar2[9] = in_EAX[9];
    iVar10 = FUN_007e9760(param_1,puVar2,param_2,param_3,0,0,0,param_4);
    if (iVar10 == 0) {
      in_EAX[7] = 0;
      in_EAX[10] = puVar2[10];
      in_EAX[0xb] = puVar2[0xb];
      in_EAX[8] = 0;
      in_EAX[9] = 0;
      iVar10 = FUN_007e9760(param_1);
      in_EAX[7] = puVar2;
      if (iVar10 != 0) break;
      goto LAB_007e89d1;
    }
    break;
  case 'o':
    iVar13 = param_1[7];
    param_1[7] = iVar13 + 2;
    if ((in_EAX[6] == 0) || (iVar10 = FUN_007e7f10(param_1), iVar10 == 0)) {
      uVar9 = FUN_007dc140(iVar5,0x2e,iVar13,0);
      iVar10 = FUN_007e8340(uVar9);
      if (iVar10 == 0) {
        uVar9 = FUN_007dc140(iVar5,0x67,iVar13,0);
        local_18[local_30 + 1] = uVar9;
        iVar10 = FUN_007e9760(param_1,puVar2,5,iVar13,0,0,0,param_4);
        if (iVar10 == 0) {
          uVar9 = FUN_007dc140(iVar5,0x2e,iVar13 + 1,0);
          iVar10 = FUN_007e8340(uVar9);
          if (iVar10 == 0) {
            uVar6 = FUN_007dc140(iVar5,0x67,iVar13 + 1,0);
            uVar9 = in_EAX[8];
            local_18[local_30 + 2] = uVar6;
            local_30 = local_30 + 2;
            local_18[0] = in_EAX[9];
            in_EAX[8] = 0;
            in_EAX[9] = 0;
            in_EAX[7] = 0;
            iVar10 = FUN_007e9760(param_1);
            in_EAX[7] = puVar2;
            FUN_007eabc0(in_EAX[8]);
            in_EAX[8] = uVar9;
            in_EAX[9] = local_18[0];
            if (iVar10 == 0) {
              if (param_2 == (int *)0x1) {
                FUN_007e7500(param_1,0,*in_EAX);
              }
              iVar10 = FUN_007dc190(iVar5);
              local_1c = iVar10;
              local_20 = (int *)FUN_007dc190(iVar5);
              FUN_007dc140(iVar5,0x79,iVar13,iVar10);
              FUN_007e81b0();
              local_18[0] = FUN_007dc140(iVar5,7,iVar13,0);
              piVar3 = local_20;
              FUN_007dc140(iVar5,0x23,iVar13 + 1,local_20);
              iVar10 = FUN_007e6c50(param_1);
              if (iVar10 == 0) {
                FUN_007dc1e0(iVar5,piVar3);
                FUN_007dc140(iVar5,0x6c,iVar13,local_18[0]);
                FUN_007dc1e0(iVar5,local_1c);
                FUN_007dc140(iVar5,0x1e,iVar13 + 1,0);
                FUN_007dc140(iVar5,0x1e,iVar13,0);
                iVar10 = 0;
                goto LAB_007e89d1;
              }
              goto LAB_007e842d;
            }
          }
        }
      }
      break;
    }
    goto LAB_007e842d;
  default:
switchD_007e84d9_default:
    iVar13 = *(int *)*in_EAX;
    if (iVar13 != *(int *)*puVar2) {
      pcVar4 = (char *)FUN_007e7740();
      pcVar15 = s_SELECTs_to_the_left_and_right_of_00a01ad0;
      goto LAB_007e8425;
    }
    bVar14 = uVar11 != 0;
    while (bVar14) {
      puVar2 = local_18 + uVar11;
      uVar11 = uVar11 - 1;
      FUN_007dc400(iVar5,*puVar2,iVar13);
      bVar14 = 0 < (int)uVar11;
    }
    if (in_EAX[6] == 0) {
      if (local_24 == (int *)0x0) goto LAB_007e8443;
      if (*local_24 < 1) break;
    }
    puVar7 = (undefined1 *)FUN_007d0550(iVar13 * 4 + 0x10);
    if (puVar7 == (undefined1 *)0x0) {
      iVar10 = 7;
      break;
    }
    iVar12 = 0;
    *puVar7 = *(undefined1 *)(*param_1 + 0x10);
    *(int *)(puVar7 + 4) = iVar13;
    if (0 < iVar13) {
      local_28 = (int *)(puVar7 + 0xc);
      do {
        iVar8 = FUN_007e8380(param_1);
        *local_28 = iVar8;
        if (iVar8 == 0) {
          *local_28 = *(int *)(*param_1 + 0x18);
        }
        iVar12 = iVar12 + 1;
        local_28 = local_28 + 1;
      } while (iVar12 < iVar13);
    }
    for (iVar13 = 0; (local_24 != (int *)0x0 && (iVar13 < *local_24)); iVar13 = iVar13 + 1) {
      FUN_007dc430(iVar5,*(undefined4 *)(local_24[2] + 4 + iVar13 * 8),puVar7,
                   (-(uint)(iVar13 != 0) & 3) - 9);
    }
    piVar3 = (int *)in_EAX[6];
    if (piVar3 != (int *)0x0) {
      local_20 = (int *)piVar3[2];
      local_1c = 0;
      if (0 < *piVar3) {
        do {
          iVar5 = *local_20;
          if (local_20[1] == 0) {
            *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(puVar7 + *(int *)(iVar5 + 0x28) * 4 + 0xc);
          }
          else {
            uVar9 = FUN_007d2c50(param_1,local_20[1],0xffffffff);
            *(undefined4 *)(iVar5 + 4) = uVar9;
          }
          local_1c = local_1c + 1;
          local_20 = local_20 + 3;
        } while (local_1c < *(int *)in_EAX[6]);
      }
      FUN_007e7090(param_1);
    }
    if (local_24 == (int *)0x0) {
      FUN_007d05b0(puVar7);
      break;
    }
    goto LAB_007e843a;
  }
LAB_007e8432:
  if (local_24 != (int *)0x0) {
LAB_007e843a:
    FUN_007d3980(local_24);
  }
LAB_007e8443:
  in_EAX[0xc] = 0;
  return iVar10;
}


// ==== FUN_007e8bc0 @ 0x007e8bc0 ====

void FUN_007e8bc0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int local_4;
  
  iVar2 = 0;
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)*param_1;
    if ((piVar1 != (int *)0x0) && (0 < *piVar1)) {
      local_4 = 0;
      do {
        FUN_007e9250(*(undefined4 *)(local_4 + piVar1[2]));
        iVar2 = iVar2 + 1;
        local_4 = local_4 + 0xc;
      } while (iVar2 < *piVar1);
    }
    piVar1 = (int *)param_1[4];
    iVar2 = 0;
    if ((piVar1 != (int *)0x0) && (0 < *piVar1)) {
      local_4 = 0;
      do {
        FUN_007e9250(*(undefined4 *)(local_4 + piVar1[2]));
        iVar2 = iVar2 + 1;
        local_4 = local_4 + 0xc;
      } while (iVar2 < *piVar1);
    }
    piVar1 = (int *)param_1[6];
    iVar2 = 0;
    if ((piVar1 != (int *)0x0) && (0 < *piVar1)) {
      local_4 = 0;
      do {
        FUN_007e9250(*(undefined4 *)(local_4 + piVar1[2]));
        iVar2 = iVar2 + 1;
        local_4 = local_4 + 0xc;
      } while (iVar2 < *piVar1);
    }
    FUN_007e9250(param_1[5]);
    FUN_007e9250(param_1[3]);
  }
  return;
}


// ==== FUN_007e8cb0 @ 0x007e8cb0 ====

undefined4 FUN_007e8cb0(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  short *psVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int local_2c;
  char *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c [2];
  char **local_4;
  
  if (((param_2[4] != 0) || (param_2[5] != 0)) || (param_2[3] != 0)) {
    return 0;
  }
  psVar1 = (short *)param_2[2];
  if ((*psVar1 != 1) || (*(int *)*param_2 != 1)) {
    return 0;
  }
  pcVar2 = *(char **)((int *)*param_2)[2];
  if (*pcVar2 != '\b') {
    return 0;
  }
  piVar3 = *(int **)(pcVar2 + 0x10);
  if (((piVar3 != (int *)0x0) && (*piVar3 == 1)) && ((*(uint *)(pcVar2 + 0x18) & 0xfffffffe) == 6))
  {
    iVar6 = FUN_007d0930(*(undefined4 *)(pcVar2 + 0x14),&DAT_009fd1c4,3);
    if (iVar6 == 0) {
      local_2c = 0x79;
    }
    else {
      iVar6 = FUN_007d0930(*(undefined4 *)(pcVar2 + 0x14),&DAT_009fd1c0,3);
      if (iVar6 != 0) {
        return 0;
      }
      local_2c = 0x36;
    }
    pcVar2 = *(char **)piVar3[2];
    if (*pcVar2 == '\a') {
      iVar6 = *(int *)(pcVar2 + 0x28);
      iVar4 = *(int *)(psVar1 + 8);
      if (iVar6 < 0) {
        iVar9 = 0;
LAB_007e8d8f:
        iVar6 = FUN_007e8190(param_1);
        if (iVar6 != 0) {
          if (param_3 == 8) {
            FUN_007dc140(iVar6,0x2e,param_4,0);
            FUN_007dc140(iVar6,0x67,param_4,1);
          }
          FUN_007d3cc0(param_1,*(undefined1 *)(iVar4 + 0x1d));
          uVar5 = *(undefined4 *)(psVar1 + 0xe);
          FUN_007e81b0();
          if (*(int *)(psVar1 + 10) == 0) {
            FUN_007ecd00(iVar6,uVar5,iVar4);
          }
          uVar7 = FUN_007dc190(iVar6);
          if (iVar9 == 0) {
            FUN_007dc140(iVar6,local_2c,uVar5,0);
          }
          else {
            iVar4 = *(int *)(param_1 + 0x1c);
            *(int *)(param_1 + 0x1c) = iVar4 + 1;
            FUN_007dc140(iVar6,0x32,*(undefined1 *)(iVar9 + 0x16),0);
            FUN_007dda80(iVar6,0xe,iVar4,*(undefined4 *)(iVar9 + 0x10),iVar9 + 0x20,0xfffffffa);
            if (local_2c == 0x79) {
              FUN_007dc140(iVar6,0x76,0,0);
              FUN_007dc140(iVar6,0x5b,1,0);
              local_2c = 5;
            }
            FUN_007dc140(iVar6,local_2c,iVar4,0);
            FUN_007dc140(iVar6,0x37,iVar4,0);
            FUN_007dc140(iVar6,0x1e,iVar4,0);
            FUN_007dc140(iVar6,0x7a,uVar5,0);
          }
          local_14 = 0;
          local_10 = 0;
          local_4 = &local_18;
          local_c[0] = 1;
          local_18 = pcVar2;
          FUN_007e6c50(param_1,param_2,local_c,0,0,0xffffffff,param_3,param_4,uVar7,uVar7,0);
          FUN_007dc1e0(iVar6,uVar7);
          FUN_007dc140(iVar6,0x1e,uVar5,0);
          return 1;
        }
      }
      else {
        iVar8 = FUN_007ea170(param_1,pcVar2);
        for (iVar9 = *(int *)(iVar4 + 0x10); iVar9 != 0; iVar9 = *(int *)(iVar9 + 0x1c)) {
          if ((**(int **)(iVar9 + 8) == iVar6) && (*(int *)(iVar9 + 0x2c) == iVar8))
          goto LAB_007e8d8f;
        }
      }
      return 0;
    }
  }
  return 0;
}


// ==== FUN_007e8f80 @ 0x007e8f80 ====

undefined4 FUN_007e8f80(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *unaff_ESI;
  int local_c;
  int local_8;
  undefined4 local_4;
  
  piVar1 = (int *)param_1[2];
  local_4 = *param_1;
  iVar4 = 0;
  if (unaff_ESI == (int *)0x0) {
    return 0;
  }
  local_8 = 0;
  if (0 < *unaff_ESI) {
    do {
      uVar3 = *(undefined4 *)(iVar4 + unaff_ESI[2]);
      iVar2 = FUN_007ea890(uVar3,&local_c);
      if (iVar2 != 0) {
        if ((local_c < 1) || (*piVar1 < local_c)) {
          FUN_007d0820(local_4,s__s_BY_column_number__d_out_of_ra_00a01bb8,param_2,local_c,*piVar1);
          return 1;
        }
        FUN_007eabc0(uVar3);
        uVar3 = FUN_007eb2d0(*(undefined4 *)(piVar1[2] + -0xc + local_c * 0xc));
        *(undefined4 *)(iVar4 + unaff_ESI[2]) = uVar3;
        uVar3 = *(undefined4 *)(iVar4 + unaff_ESI[2]);
      }
      iVar2 = FUN_007ebc80(param_1,uVar3);
      if (iVar2 != 0) {
        return 1;
      }
      iVar2 = FUN_007eaee0(uVar3);
      if (iVar2 != 0) {
        FUN_007d0820(local_4,s__s_BY_terms_must_not_be_non_inte_00a01b84,param_2);
        return 1;
      }
      local_8 = local_8 + 1;
      iVar4 = iVar4 + 0xc;
    } while (local_8 < *unaff_ESI);
  }
  return 0;
}


// ==== FUN_007e9090 @ 0x007e9090 ====

undefined4 FUN_007e9090(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  char local_b;
  int local_8;
  int local_4;
  
  if ((char)param_2[0xd] != '\0') {
    return 0;
  }
  *(undefined1 *)(param_2 + 0xd) = 1;
  iVar4 = 0;
  if ((*(int *)(param_1 + 0x18) < 1) && (iVar2 = FUN_007e79d0(param_1,param_2), iVar2 == 0)) {
    local_b = '\0';
    local_c = 0;
    local_20 = param_1;
    local_10 = 0;
    local_14 = 0;
    local_18 = 0;
    local_1c = 0;
    local_4 = 0;
    iVar2 = FUN_007ebc80(&local_20,param_2[8]);
    if ((iVar2 == 0) && (iVar2 = FUN_007ebc80(&local_20,param_2[9]), iVar2 == 0)) {
      local_1c = param_2[2];
      local_c = 1;
      local_4 = param_3;
      if (param_3 == 0) {
        local_8 = 1;
      }
      else {
        local_8 = *(int *)(param_3 + 0x18) + 1;
      }
      if (*(int *)(param_1 + 0xb0) < local_8) {
        *(int *)(param_1 + 0xb0) = local_8;
      }
      piVar1 = (int *)*param_2;
      if (piVar1 != (int *)0x0) {
        if (0 < *piVar1) {
          iVar2 = 0;
          do {
            iVar3 = FUN_007ebc80(&local_20,*(undefined4 *)(iVar2 + piVar1[2]));
            if (iVar3 != 0) {
              return 1;
            }
            iVar4 = iVar4 + 1;
            iVar2 = iVar2 + 0xc;
          } while (iVar4 < *piVar1);
        }
        if ((param_2[4] == 0) && (local_b == '\0')) {
          local_c = 0;
        }
        else {
          *(undefined1 *)((int)param_2 + 0x35) = 1;
        }
        if ((param_2[5] == 0) || (param_2[4] != 0)) {
          local_18 = *param_2;
          iVar4 = FUN_007ebc80(&local_20,param_2[3]);
          if ((iVar4 == 0) &&
             (((iVar4 = FUN_007ebc80(&local_20,param_2[5]), iVar4 == 0 &&
               (iVar4 = FUN_007e8f80(&local_20,s_ORDER_00a01c04), iVar4 == 0)) &&
              (iVar4 = FUN_007e8f80(&local_20,s_GROUP_00a01bfc), iVar4 == 0)))) {
            return 0;
          }
        }
        else {
          FUN_007d0820(param_1,s_a_GROUP_BY_clause_is_required_be_00a01c0c);
        }
      }
      return 1;
    }
  }
  return 1;
}


// ==== FUN_007e9250 @ 0x007e9250 ====

void FUN_007e9250(char *param_1,int param_2,int param_3)

{
  char *pcVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 != (char *)0x0) {
    if ((*param_1 == '\a') && (*(int *)(param_1 + 0x24) == param_2)) {
      if (*(int *)(param_1 + 0x28) < 0) {
        *param_1 = '^';
        return;
      }
      pcVar1 = *(char **)(*(int *)(param_3 + 8) + *(int *)(param_1 + 0x28) * 0xc);
      *param_1 = *pcVar1;
      uVar3 = FUN_007eb2d0(*(undefined4 *)(pcVar1 + 8));
      *(undefined4 *)(param_1 + 8) = uVar3;
      uVar3 = FUN_007eb2d0(*(undefined4 *)(pcVar1 + 0xc));
      *(undefined4 *)(param_1 + 0xc) = uVar3;
      uVar3 = FUN_007ea5c0(*(undefined4 *)(pcVar1 + 0x10));
      *(undefined4 *)(param_1 + 0x10) = uVar3;
      *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(pcVar1 + 0x24);
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(pcVar1 + 0x28);
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(pcVar1 + 0x2c);
      FUN_007ea560(param_1 + 0x14,pcVar1 + 0x14);
      FUN_007ea560(param_1 + 0x1c,pcVar1 + 0x1c);
      uVar3 = FUN_007ead10(*(undefined4 *)(pcVar1 + 0x34));
      *(undefined4 *)(param_1 + 0x34) = uVar3;
      param_1[3] = pcVar1[3];
      return;
    }
    FUN_007e9250(*(undefined4 *)(param_1 + 8),param_2,param_3);
    FUN_007e9250(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
    FUN_007e8bc0(*(undefined4 *)(param_1 + 0x34));
    piVar2 = *(int **)(param_1 + 0x10);
    if ((piVar2 != (int *)0x0) && (iVar4 = 0, 0 < *piVar2)) {
      iVar5 = 0;
      do {
        FUN_007e9250(*(undefined4 *)(piVar2[2] + iVar5),param_2,param_3);
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 0xc;
      } while (iVar4 < *piVar2);
    }
  }
  return;
}


// ==== FUN_007e9360 @ 0x007e9360 ====

void FUN_007e9360(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *unaff_ESI;
  int iVar2;
  
  if ((unaff_ESI != (int *)0x0) && (iVar2 = 0, 0 < *unaff_ESI)) {
    iVar1 = 0;
    do {
      FUN_007e9250(*(undefined4 *)(unaff_ESI[2] + iVar1),param_1,param_2);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0xc;
    } while (iVar2 < *unaff_ESI);
  }
  return;
}


// ==== FUN_007e93a0 @ 0x007e93a0 ====

undefined4 FUN_007e93a0(int *param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined1 uVar5;
  short *psVar6;
  short *psVar7;
  short *psVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  short *psVar14;
  short *psVar15;
  short *local_14;
  
  piVar4 = param_1;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  psVar6 = (short *)param_1[2];
  puVar2 = *(undefined4 **)(psVar6 + param_2 * 0x14 + 10);
  if (param_3 == 0) {
    if ((param_4 != 0) && (1 < *psVar6)) {
      return 0;
    }
  }
  else if (param_4 != 0) {
    return 0;
  }
  psVar8 = (short *)puVar2[2];
  if ((((((puVar2[8] == 0) || (param_1[8] == 0)) && (puVar2[9] == 0)) &&
       ((puVar2[8] == 0 || (param_3 == 0)))) && (sVar1 = *psVar8, sVar1 != 0)) &&
     ((((*(char *)((int)puVar2 + 5) == '\0' || ((*psVar6 < 2 && (param_3 == 0)))) &&
       ((*(char *)((int)param_1 + 5) == '\0' || (param_4 == 0)))) &&
      ((param_1[6] == 0 || (puVar2[6] == 0)))))) {
    if (1 < sVar1) {
      if (param_2 < 1) goto LAB_007e947c;
      if ((*(byte *)(psVar6 + param_2 * 0x14 + -8) & 0x10) != 0) {
        return 0;
      }
    }
    if (((param_2 < 1) || ((*(byte *)(psVar6 + param_2 * 0x14 + -8) & 0x10) == 0)) ||
       (puVar2[3] == 0)) {
LAB_007e947c:
      uVar10 = *(undefined4 *)(psVar6 + param_2 * 0x14 + 0xe);
      uVar9 = *(undefined4 *)(psVar6 + param_2 * 0x14 + 0xc);
      iVar13 = (int)sVar1;
      FUN_007d25e0(0,*(undefined4 *)(psVar6 + param_2 * 0x14 + 8));
      FUN_007d05b0(*(undefined4 *)(psVar6 + param_2 * 0x14 + 2));
      FUN_007d05b0(*(undefined4 *)(psVar6 + param_2 * 0x14 + 4));
      FUN_007d05b0(*(undefined4 *)(psVar6 + param_2 * 0x14 + 6));
      if (1 < iVar13) {
        local_14 = (short *)(iVar13 + -1);
        do {
          psVar6 = (short *)FUN_007d5320(psVar6,0,0);
          local_14 = (short *)((int)local_14 + -1);
        } while (local_14 != (short *)0x0);
        param_1[2] = (int)psVar6;
        iVar11 = (*psVar6 + -1) - (iVar13 + -1);
        if (param_2 <= iVar11) {
          local_14 = psVar6 + iVar11 * 0x14 + 2;
          psVar7 = psVar6 + (*psVar6 + -1) * 0x14 + 2;
          do {
            psVar14 = local_14;
            psVar15 = psVar7;
            for (iVar12 = 10; iVar12 != 0; iVar12 = iVar12 + -1) {
              *(undefined4 *)psVar15 = *(undefined4 *)psVar14;
              psVar14 = psVar14 + 2;
              psVar15 = psVar15 + 2;
            }
            psVar7 = psVar7 + -0x14;
            iVar11 = iVar11 + -1;
            local_14 = local_14 + -0x14;
          } while (param_2 <= iVar11);
        }
      }
      if (0 < iVar13) {
        psVar7 = psVar6 + param_2 * 0x14 + 2;
        psVar8 = psVar8 + 2;
        iVar11 = iVar13;
        do {
          psVar14 = psVar8;
          psVar15 = psVar7;
          for (iVar12 = 10; iVar12 != 0; iVar12 = iVar12 + -1) {
            *(undefined4 *)psVar15 = *(undefined4 *)psVar14;
            psVar14 = psVar14 + 2;
            psVar15 = psVar15 + 2;
          }
          psVar8[0] = 0;
          psVar8[1] = 0;
          psVar8[2] = 0;
          psVar8[3] = 0;
          psVar8[4] = 0;
          psVar8[5] = 0;
          psVar8[6] = 0;
          psVar8[7] = 0;
          psVar8[8] = 0;
          psVar8[9] = 0;
          psVar8[10] = 0;
          psVar8[0xb] = 0;
          psVar8[0xc] = 0;
          psVar8[0xd] = 0;
          psVar8[0xe] = 0;
          psVar8[0xf] = 0;
          psVar8[0x10] = 0;
          psVar8[0x11] = 0;
          psVar7 = psVar7 + 0x14;
          iVar11 = iVar11 + -1;
          psVar8[0x12] = 0;
          psVar8[0x13] = 0;
          psVar8 = psVar8 + 0x14;
        } while (iVar11 != 0);
      }
      *(undefined4 *)(psVar6 + (iVar13 + param_2) * 0x14 + -8) = uVar9;
      FUN_007e9360(uVar10,*puVar2);
      piVar3 = (int *)*param_1;
      param_1 = (int *)0x0;
      if (0 < *piVar3) {
        iVar13 = 0;
        do {
          if (*(int *)(piVar3[2] + 4 + iVar13) == 0) {
            iVar11 = *(int *)(piVar3[2] + iVar13);
            iVar12 = *(int *)(iVar11 + 0x1c);
            if (iVar12 != 0) {
              uVar9 = FUN_007d06a0(iVar12,*(uint *)(iVar11 + 0x20) >> 1);
              *(undefined4 *)(piVar3[2] + 4 + iVar13) = uVar9;
            }
          }
          param_1 = (int *)((int)param_1 + 1);
          iVar13 = iVar13 + 0xc;
        } while ((int)param_1 < *piVar3);
      }
      if (param_3 != 0) {
        piVar3 = (int *)piVar4[4];
        uVar9 = *puVar2;
        if ((piVar3 != (int *)0x0) && (iVar13 = 0, 0 < *piVar3)) {
          param_1 = (int *)0x0;
          do {
            FUN_007e9250(*(undefined4 *)((int)param_1 + piVar3[2]),uVar10,uVar9);
            iVar13 = iVar13 + 1;
            param_1 = (int *)((int)param_1 + 0xc);
          } while (iVar13 < *piVar3);
        }
        FUN_007e9250(piVar4[5],uVar10,*puVar2);
      }
      if (puVar2[6] == 0) {
        if (piVar4[6] != 0) {
          FUN_007e9360(uVar10,*puVar2);
        }
      }
      else {
        piVar4[6] = puVar2[6];
        puVar2[6] = 0;
      }
      if (puVar2[3] == 0) {
        iVar13 = 0;
      }
      else {
        iVar13 = FUN_007eb2d0(puVar2[3]);
      }
      if (param_4 == 0) {
        FUN_007e9250(piVar4[3],uVar10,*puVar2);
        iVar13 = FUN_007eb2a0(piVar4[3],iVar13);
        piVar4[3] = iVar13;
      }
      else {
        iVar11 = piVar4[3];
        piVar4[5] = iVar11;
        piVar4[3] = iVar13;
        FUN_007e9250(iVar11,uVar10,*puVar2);
        uVar10 = FUN_007eb2d0(puVar2[5]);
        iVar13 = FUN_007eb2a0(piVar4[5],uVar10);
        piVar4[5] = iVar13;
        iVar13 = FUN_007ea5c0(puVar2[4]);
        piVar4[4] = iVar13;
      }
      if ((*(char *)((int)piVar4 + 5) == '\0') && (*(char *)((int)puVar2 + 5) == '\0')) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
      }
      *(undefined1 *)((int)piVar4 + 5) = uVar5;
      if (puVar2[8] != 0) {
        piVar4[8] = puVar2[8];
        puVar2[8] = 0;
      }
      FUN_007e6af0(puVar2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007e9760 @ 0x007e9760 ====

undefined4
FUN_007e9760(int *param_1,int *param_2,int param_3,undefined4 param_4,int param_5,int param_6,
            undefined4 *param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 *puVar6;
  short *psVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int *local_58;
  int *local_54;
  int local_50;
  uint local_4c;
  int *local_48;
  short *local_44;
  int local_40;
  undefined1 *local_3c;
  int local_38;
  undefined4 local_34;
  int *local_30;
  int local_2c;
  int local_28;
  int local_24;
  int *local_20;
  short *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_34 = 1;
  if ((((DAT_00b5c4c4 != 0) || (param_1[6] != 0)) || (param_2 == (int *)0x0)) ||
     (iVar1 = FUN_007ed5e0(param_1,0x15,0,0,0), iVar1 != 0)) {
    return 1;
  }
  if (param_2[7] != 0) {
    uVar2 = FUN_007e83c0(param_1,param_3,param_4,param_8);
    return uVar2;
  }
  local_24 = param_1[0x2b];
  local_28 = param_1[0x2a];
  param_1[0x2b] = 0;
  param_1[0x2a] = 0;
  local_54 = (int *)param_2[6];
  if (((param_3 == 5) || (param_3 == 6)) || (param_3 == 9)) {
    param_2[6] = 0;
  }
  iVar1 = FUN_007e9090(param_1,param_2,0);
  if (iVar1 == 0) {
    local_2c = param_2[3];
    local_58 = (int *)param_2[4];
    psVar7 = (short *)param_2[2];
    param_2[6] = (int)local_54;
    local_40 = param_2[5];
    local_4c = (uint)*(byte *)((int)param_2 + 0x35);
    local_30 = (int *)(uint)*(byte *)((int)param_2 + 5);
    local_48 = (int *)*param_2;
    local_44 = psVar7;
    if ((local_48 != (int *)0x0) && (param_1[6] < 1)) {
      if (((param_3 == 2) || (param_3 == 3)) && (1 < *local_48)) {
        FUN_007d0820(param_1,s_only_a_single_result_allowed_for_00a01c38);
      }
      else {
        if ((4 < param_3) && ((param_3 < 7 || (param_3 == 9)))) {
          local_54 = (int *)0x0;
        }
        iVar1 = FUN_007e8190(param_1);
        if (iVar1 != 0) {
          if (param_3 == 1) {
            FUN_007e7500(param_1,psVar7,local_48);
          }
          local_50 = 0;
          if (0 < *psVar7) {
            iVar5 = 0;
            do {
              local_38 = 0;
              if (*(int *)(iVar5 + 0x14 + (int)psVar7) != 0) {
                iVar8 = *(int *)(iVar5 + 8 + (int)psVar7);
                if (iVar8 != 0) {
                  local_38 = param_1[0x29];
                  param_1[0x29] = iVar8;
                }
                FUN_007e9760(param_1,*(undefined4 *)(iVar5 + 0x14 + (int)psVar7),8,
                             *(undefined4 *)(iVar5 + 0x1c + (int)local_44),param_2,local_50,
                             &local_4c,0);
                if (iVar8 != 0) {
                  param_1[0x29] = local_38;
                }
                local_2c = param_2[3];
                psVar7 = (short *)param_2[2];
                if (((param_3 != 5) && (param_3 != 6)) && (param_3 != 9)) {
                  local_54 = (int *)param_2[6];
                }
                local_30 = (int *)(uint)*(byte *)((int)param_2 + 5);
                local_58 = (int *)param_2[4];
                local_40 = param_2[5];
                local_44 = psVar7;
              }
              local_50 = local_50 + 1;
              iVar5 = iVar5 + 0x28;
            } while (local_50 < *psVar7);
          }
          iVar5 = FUN_007e8cb0(param_1,param_2,param_3,param_4);
          if (iVar5 == 0) {
            if (((param_5 == 0) || (param_7 == (undefined4 *)0x0)) ||
               (iVar5 = FUN_007e93a0(param_5,param_6,*param_7,local_4c), iVar5 == 0)) {
              if (local_54 != (int *)0x0) {
                iVar5 = 0;
                if (0 < *local_54) {
                  iVar8 = 0;
                  piVar9 = local_54;
                  do {
                    iVar3 = *(int *)(piVar9[2] + 4 + iVar8);
                    if (iVar3 != 0) {
                      uVar2 = FUN_007d2c50(param_1,iVar3,0xffffffff);
                      *(undefined4 *)(*(int *)(local_54[2] + iVar8) + 4) = uVar2;
                      piVar9 = local_54;
                    }
                    iVar5 = iVar5 + 1;
                    iVar8 = iVar8 + 0xc;
                  } while (iVar5 < *piVar9);
                }
                if (param_1[6] != 0) goto LAB_007ea0fa;
              }
              FUN_007e81b0();
              if (param_3 == 8) {
                FUN_007dc140(iVar1,0x2e,param_4,0);
                FUN_007dc140(iVar1,0x67,param_4,*local_48);
              }
              if ((local_4c != 0) || (local_58 != (int *)0x0)) {
                local_18 = 0;
                local_14 = 0;
                local_10 = 0;
                local_c = 0;
                local_8 = 0;
                local_4 = 0;
                local_4c = 1;
                iVar5 = 0;
                local_20 = param_1;
                local_1c = local_44;
                if (0 < *local_48) {
                  iVar8 = 0;
                  do {
                    iVar3 = FUN_007eb100(&local_20,*(undefined4 *)(local_48[2] + iVar8));
                    if (iVar3 != 0) goto LAB_007ea0fa;
                    iVar5 = iVar5 + 1;
                    iVar8 = iVar8 + 0xc;
                  } while (iVar5 < *local_48);
                }
                if ((local_58 != (int *)0x0) && (iVar5 = 0, 0 < *local_58)) {
                  iVar8 = 0;
                  do {
                    iVar3 = FUN_007eb100(&local_20,*(undefined4 *)(local_58[2] + iVar8));
                    if (iVar3 != 0) goto LAB_007ea0fa;
                    iVar5 = iVar5 + 1;
                    iVar8 = iVar8 + 0xc;
                  } while (iVar5 < *local_58);
                }
                if ((local_40 != 0) && (iVar5 = FUN_007eb100(&local_20,local_40), iVar5 != 0))
                goto LAB_007ea0fa;
                if ((local_54 != (int *)0x0) && (iVar5 = 0, 0 < *local_54)) {
                  iVar8 = 0;
                  do {
                    iVar3 = FUN_007eb100(&local_20,*(undefined4 *)(local_54[2] + iVar8));
                    if (iVar3 != 0) goto LAB_007ea0fa;
                    iVar5 = iVar5 + 1;
                    iVar8 = iVar8 + 0xc;
                  } while (iVar5 < *local_54);
                }
                if (local_4c != 0) {
                  local_38 = FUN_007dc140(iVar1,0x70,local_58 == (int *)0x0,param_1[0x2a]);
                  iVar5 = 0;
                  if (0 < param_1[0x2a]) {
                    local_50 = 0;
                    do {
                      iVar8 = *(int *)(param_1[0x2b] + 8 + local_50);
                      if ((iVar8 != 0) && (*(int *)(iVar8 + 0x1c) != 0)) {
                        FUN_007dda80(iVar1,0x6d,0,iVar5,iVar8,0xfffffffb);
                      }
                      iVar5 = iVar5 + 1;
                      local_50 = local_50 + 0xc;
                    } while (iVar5 < param_1[0x2a]);
                  }
                  if (local_58 != (int *)0x0) {
                    local_3c = (undefined1 *)FUN_007d0550(*local_58 * 4 + 0x10);
                    if (local_3c == (undefined1 *)0x0) goto LAB_007ea0fa;
                    *local_3c = *(undefined1 *)(*param_1 + 0x10);
                    *(int *)(local_3c + 4) = *local_58;
                    local_50 = 0;
                    if (0 < *local_58) {
                      iVar5 = 0;
                      piVar9 = (int *)(local_3c + 0xc);
                      do {
                        iVar8 = FUN_007ea170(param_1,*(undefined4 *)(local_58[2] + iVar5));
                        *piVar9 = iVar8;
                        if (iVar8 == 0) {
                          *piVar9 = *(int *)(*param_1 + 0x18);
                        }
                        local_50 = local_50 + 1;
                        piVar9 = piVar9 + 1;
                        iVar5 = iVar5 + 0xc;
                      } while (local_50 < *local_58);
                    }
                    FUN_007dc430(iVar1,local_38,local_3c,0xfffffff7);
                  }
                }
              }
              if ((param_3 == 2) || (param_3 == 0xc)) {
                FUN_007dc140(iVar1,((param_3 != 2) - 1U & 0x44) + 0x32,0,0);
                FUN_007dc140(iVar1,0x78,param_4,1);
              }
              if (local_30 == (int *)0x0) {
                local_38 = -1;
              }
              else {
                local_38 = param_1[7];
                param_1[7] = local_38 + 1;
                FUN_007e8280(param_1,param_2,local_38);
              }
              local_44 = (short *)FUN_007f7600(param_1,local_44,local_2c,
                                               (local_58 != (int *)0x0) - 1 & (uint)&local_54);
              if (local_44 != (short *)0x0) {
                if (local_4c == 0) {
                  iVar5 = FUN_007e6c50(param_1,param_2,local_48,0,local_54,local_38,param_3,param_4,
                                       *(undefined4 *)(local_44 + 6),*(undefined4 *)(local_44 + 8),
                                       param_8);
                  if (iVar5 != 0) goto LAB_007ea0fa;
                }
                else {
                  local_3c = (undefined1 *)0x0;
                  *(undefined1 *)(param_1 + 5) = 1;
                  if (local_58 != (int *)0x0) {
                    if (0 < *local_58) {
                      local_3c = (undefined1 *)0x0;
                      iVar5 = 0;
                      do {
                        FUN_007ec010(param_1,*(undefined4 *)(local_3c + local_58[2]));
                        iVar5 = iVar5 + 1;
                        local_3c = local_3c + 0xc;
                      } while (iVar5 < *local_58);
                    }
                    FUN_007dc140(iVar1,0x5b,*local_58,0);
                    local_3c = (undefined1 *)FUN_007dc190(iVar1);
                    FUN_007dc140(iVar1,6,0,local_3c);
                  }
                  piVar9 = (int *)param_1[0x2b];
                  iVar5 = 0;
                  if (0 < param_1[0x2a]) {
                    do {
                      if (*piVar9 == 0) {
                        FUN_007ec010(param_1,piVar9[1]);
                        FUN_007dc140(iVar1,0x31,0,iVar5);
                      }
                      iVar5 = iVar5 + 1;
                      piVar9 = piVar9 + 3;
                    } while (iVar5 < param_1[0x2a]);
                  }
                  *(undefined1 *)(param_1 + 5) = 0;
                  if ((int)local_3c < 0) {
                    FUN_007dc1e0(iVar1,local_3c);
                  }
                  local_30 = (int *)param_1[0x2b];
                  local_50 = 0;
                  if (0 < param_1[0x2a]) {
                    do {
                      piVar9 = local_30;
                      if (*local_30 != 0) {
                        iVar5 = local_30[1];
                        puVar6 = (undefined1 *)local_30[2];
                        local_3c = puVar6;
                        local_2c = FUN_007ea9a0(param_1,*(undefined4 *)(iVar5 + 0x10));
                        FUN_007dc140(iVar1,0x32,local_50,0);
                        if (puVar6[0x20] != '\0') {
                          iVar8 = 0;
                          iVar3 = 0;
                          iVar10 = 0;
                          do {
                            if (local_2c <= iVar3) {
                              if (iVar8 == 0) {
                                iVar8 = *(int *)(*param_1 + 0x18);
                              }
                              break;
                            }
                            iVar8 = FUN_007ea170(param_1,*(undefined4 *)
                                                          (*(int *)(*(int *)(iVar5 + 0x10) + 8) +
                                                          iVar10));
                            iVar3 = iVar3 + 1;
                            iVar10 = iVar10 + 0xc;
                          } while (iVar8 == 0);
                          FUN_007dda80(iVar1,0xd,0,0,iVar8,0xfffffffc);
                          puVar6 = local_3c;
                          piVar9 = local_30;
                        }
                        FUN_007dda80(iVar1,0x1d,0,local_2c,puVar6,0xfffffffb);
                      }
                      local_50 = local_50 + 1;
                      local_30 = piVar9 + 3;
                    } while (local_50 < param_1[0x2a]);
                  }
                }
                FUN_007f71d0(local_44);
                if (local_4c != 0) {
                  uVar2 = FUN_007dc190(iVar1);
                  uVar4 = FUN_007dc140(iVar1,8,0,uVar2);
                  if (local_40 != 0) {
                    FUN_007eca30(param_1,local_40,uVar4,1);
                  }
                  iVar5 = FUN_007e6c50(param_1,param_2,local_48,0,local_54,local_38,param_3,param_4,
                                       uVar4,uVar2,param_8);
                  if (iVar5 != 0) goto LAB_007ea0fa;
                  FUN_007dc140(iVar1,0x61,0,uVar4);
                  FUN_007dc1e0(iVar1,uVar2);
                  FUN_007dc140(iVar1,0x17,0,0);
                }
                if (local_54 != (int *)0x0) {
                  FUN_007e7090(param_1,param_2,*local_48,param_3,param_4);
                }
                if (param_5 != 0) {
                  FUN_007ea740(*param_2);
                  FUN_007d3a10(param_2[2]);
                  FUN_007eabc0(param_2[3]);
                  FUN_007ea740(param_2[4]);
                  FUN_007eabc0(param_2[5]);
                  FUN_007ea740(param_2[6]);
                  FUN_007e6af0(param_2[7]);
                  FUN_007eabc0(param_2[8]);
                  FUN_007eabc0(param_2[9]);
                  FUN_007d05b0(param_2);
                  *(undefined4 *)(*(int *)(param_5 + 8) + 0x14 + param_6 * 0x28) = 0;
                }
                local_34 = 0;
              }
            }
            else if (local_4c != 0) {
              *param_7 = 1;
            }
          }
          else {
            local_34 = 0;
          }
        }
      }
    }
  }
LAB_007ea0fa:
  FUN_007d05b0(param_1[0x2b]);
  param_1[0x2b] = local_24;
  param_1[0x2a] = local_28;
  return local_34;
}


// ==== FUN_007ea140 @ 0x007ea140 ====

char FUN_007ea140(char *param_1)

{
  while( true ) {
    while( true ) {
      if (*param_1 != '\x19') break;
      param_1 = *(char **)(param_1 + 8);
    }
    if (*param_1 != 'q') break;
    param_1 = (char *)**(undefined4 **)(**(int **)(param_1 + 0x34) + 8);
  }
  return param_1[1];
}


// ==== FUN_007ea170 @ 0x007ea170 ====

int FUN_007ea170(undefined4 param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (; ((param_2 != (char *)0x0 && (iVar2 = *(int *)(param_2 + 4), *param_2 == '\x19')) &&
         (iVar2 == 0)); param_2 = *(char **)(param_2 + 8)) {
  }
  iVar1 = FUN_007de5b0(param_1,iVar2);
  if (iVar1 == 0) {
    return iVar2;
  }
  return 0;
}


// ==== FUN_007ea1b0 @ 0x007ea1b0 ====

char FUN_007ea1b0(char *param_1,char param_2)

{
  char cVar1;
  
  if (*param_1 == '\x19') {
    cVar1 = FUN_007ea140(*(undefined4 *)(param_1 + 8));
  }
  else if (*param_1 == 'q') {
    cVar1 = FUN_007ea140(**(undefined4 **)(**(int **)(param_1 + 0x34) + 8));
  }
  else {
    cVar1 = param_1[1];
  }
  if (cVar1 == '\0') {
    if (param_2 != '\0') goto LAB_007ea211;
  }
  else {
    if (param_2 == '\0') {
LAB_007ea211:
      return cVar1 + param_2;
    }
    if ((cVar1 == 'i') || (param_2 == 'i')) {
      return 'i';
    }
    if ((cVar1 == 'n') || (param_2 == 'n')) {
      return 'n';
    }
  }
  return 'o';
}


// ==== FUN_007ea220 @ 0x007ea220 ====

char FUN_007ea220(void)

{
  char *pcVar1;
  char cVar2;
  int unaff_ESI;
  
  pcVar1 = *(char **)(unaff_ESI + 8);
  if (*pcVar1 == '\x19') {
    cVar2 = FUN_007ea140(*(undefined4 *)(pcVar1 + 8));
  }
  else if (*pcVar1 == 'q') {
    cVar2 = FUN_007ea140(**(undefined4 **)(**(int **)(pcVar1 + 0x34) + 8));
  }
  else {
    cVar2 = pcVar1[1];
  }
  if (*(int *)(unaff_ESI + 0xc) != 0) {
    cVar2 = FUN_007ea1b0(*(int *)(unaff_ESI + 0xc),cVar2);
    return cVar2;
  }
  if (*(int **)(unaff_ESI + 0x34) != (int *)0x0) {
    cVar2 = FUN_007ea1b0(**(undefined4 **)(**(int **)(unaff_ESI + 0x34) + 8),cVar2);
    return cVar2;
  }
  if (cVar2 == '\0') {
    cVar2 = 'n';
  }
  return cVar2;
}


// ==== FUN_007ea2a0 @ 0x007ea2a0 ====

undefined4 FUN_007ea2a0(undefined4 param_1,char param_2)

{
  char cVar1;
  bool bVar2;
  
  cVar1 = FUN_007ea220();
  if (cVar1 == 'o') {
    return 1;
  }
  if (cVar1 == 'n') {
    bVar2 = param_2 == 'i';
  }
  else {
    if (cVar1 != 'i') goto LAB_007ea2c5;
    bVar2 = param_2 == 'n';
  }
  if (bVar2) {
    return 1;
  }
LAB_007ea2c5:
  if (cVar1 == param_2) {
    return 1;
  }
  return 0;
}


// ==== FUN_007ea2e0 @ 0x007ea2e0 ====

int FUN_007ea2e0(undefined4 param_1)

{
  char cVar1;
  int in_EAX;
  char *in_ECX;
  
  if (*in_ECX == '\x19') {
    cVar1 = FUN_007ea140(*(undefined4 *)(in_ECX + 8));
  }
  else if (*in_ECX == 'q') {
    cVar1 = FUN_007ea140(**(undefined4 **)(**(int **)(in_ECX + 0x34) + 8));
  }
  else {
    cVar1 = in_ECX[1];
  }
  cVar1 = FUN_007ea1b0(param_1,cVar1);
  return (int)cVar1 + (-(uint)(in_EAX != 0) & 0x100);
}


// ==== FUN_007ea350 @ 0x007ea350 ====

void FUN_007ea350(void)

{
  int iVar1;
  
  iVar1 = FUN_007ea170();
  if (iVar1 == 0) {
    FUN_007ea170();
  }
  return;
}


// ==== FUN_007ea370 @ 0x007ea370 ====

void FUN_007ea370(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EDI;
  
  uVar1 = FUN_007ea2e0();
  iVar2 = FUN_007ea170();
  if (iVar2 == 0) {
    iVar2 = FUN_007ea170();
  }
  FUN_007dda80(*(undefined4 *)(unaff_EDI + 0xc),param_2,uVar1,param_3,iVar2,0xfffffffc);
  return;
}


// ==== FUN_007ea3c0 @ 0x007ea3c0 ====

void FUN_007ea3c0(int param_1,int *param_2,int *param_3)

{
  if (((DAT_00b5c4c4 == 0) && (*param_3 != 0)) && (*param_2 != 0)) {
    if (((*(byte *)(param_2 + 1) & 1) == 0) && ((*(byte *)(param_3 + 1) & 1) == 0)) {
      *(int *)(param_1 + 0x1c) = *param_2;
      *(uint *)(param_1 + 0x20) =
           (param_3[1] & 0xfffffffeU) + (*param_3 - *param_2) * 2 ^ *(uint *)(param_1 + 0x20) & 1;
      return;
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return;
}


// ==== FUN_007ea420 @ 0x007ea420 ====

void FUN_007ea420(int param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  bool bVar10;
  int *local_c;
  
  if (param_2 != 0) {
    uVar5 = *(uint *)(param_2 + 0x18) >> 1;
    if (uVar5 == 1) {
      iVar6 = *(int *)(param_1 + 100) + 1;
      *(int *)(param_1 + 100) = iVar6;
      *(int *)(param_2 + 0x24) = iVar6;
      return;
    }
    pcVar1 = *(char **)(param_2 + 0x14);
    if (*pcVar1 == '?') {
      lVar3 = _atol(pcVar1 + 1);
      *(long *)(param_2 + 0x24) = lVar3;
      if ((lVar3 < 1) || (999 < lVar3)) {
        FUN_007d0820(param_1,s_variable_number_must_be_between___00a01c88,999);
      }
      if (*(int *)(param_1 + 100) < lVar3) {
        *(long *)(param_1 + 100) = lVar3;
        return;
      }
    }
    else {
      iVar6 = 0;
      if (0 < *(int *)(param_1 + 0x68)) {
        local_c = *(int **)(param_1 + 0x70);
        do {
          iVar2 = *local_c;
          if ((iVar2 != 0) && (*(uint *)(iVar2 + 0x18) >> 1 == uVar5)) {
            bVar10 = true;
            uVar7 = uVar5;
            pcVar8 = *(char **)(iVar2 + 0x14);
            pcVar9 = pcVar1;
            do {
              if (uVar7 == 0) break;
              uVar7 = uVar7 - 1;
              bVar10 = *pcVar8 == *pcVar9;
              pcVar8 = pcVar8 + 1;
              pcVar9 = pcVar9 + 1;
            } while (bVar10);
            if (bVar10) {
              *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(iVar2 + 0x24);
              break;
            }
          }
          iVar6 = iVar6 + 1;
          local_c = local_c + 1;
        } while (iVar6 < *(int *)(param_1 + 0x68));
      }
      if (*(int *)(param_1 + 0x68) <= iVar6) {
        iVar6 = *(int *)(param_1 + 100) + 1;
        *(int *)(param_1 + 100) = iVar6;
        *(int *)(param_2 + 0x24) = iVar6;
        if (*(int *)(param_1 + 0x6c) + -1 <= *(int *)(param_1 + 0x68)) {
          iVar6 = *(int *)(param_1 + 0x6c) * 2 + 10;
          *(int *)(param_1 + 0x6c) = iVar6;
          uVar4 = FUN_007d05d0(*(undefined4 *)(param_1 + 0x70),iVar6 * 4);
          *(undefined4 *)(param_1 + 0x70) = uVar4;
        }
        if (DAT_00b5c4c4 == 0) {
          *(int *)(*(int *)(param_1 + 0x70) + *(int *)(param_1 + 0x68) * 4) = param_2;
          *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 1;
        }
      }
    }
  }
  return;
}


// ==== FUN_007ea560 @ 0x007ea560 ====

void FUN_007ea560(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((*(byte *)(param_1 + 1) & 1) != 0) {
    FUN_007d05b0(*param_1);
  }
  if (*param_2 == 0) {
    *param_1 = 0;
    return;
  }
  param_1[1] = (param_2[1] ^ param_1[1]) & 1U ^ param_2[1];
  uVar1 = FUN_007d06a0(*param_2,(uint)param_2[1] >> 1);
  *param_1 = uVar1;
  param_1[1] = param_1[1] | 1;
  return;
}


// ==== FUN_007ea5c0 @ 0x007ea5c0 ====

int * FUN_007ea5c0(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  piVar2 = param_1;
  if (param_1 == (int *)0x0) {
    return (int *)0x0;
  }
  piVar3 = (int *)FUN_007d0550(0xc);
  if (piVar3 == (int *)0x0) {
    return (int *)0x0;
  }
  iVar6 = *param_1;
  piVar3[1] = iVar6;
  *piVar3 = iVar6;
  piVar4 = (int *)FUN_007d0550(*param_1 * 0xc);
  piVar3[2] = (int)piVar4;
  if (piVar4 == (int *)0x0) {
    FUN_007d05b0(piVar3);
    return (int *)0x0;
  }
  iVar6 = *param_1;
  piVar7 = (int *)param_1[2];
  param_1 = (int *)0x0;
  if (0 < iVar6) {
    do {
      iVar6 = *piVar7;
      iVar5 = FUN_007eb2d0(iVar6);
      piVar1 = (int *)(iVar6 + 0x1c);
      *piVar4 = iVar5;
      if ((*piVar1 != 0) && (iVar5 != 0)) {
        FUN_007ea560(iVar5 + 0x1c,piVar1);
      }
      iVar6 = FUN_007d0640(piVar7[1]);
      piVar4[1] = iVar6;
      *(char *)(piVar4 + 2) = (char)piVar7[2];
      *(undefined1 *)((int)piVar4 + 9) = *(undefined1 *)((int)piVar7 + 9);
      *(undefined1 *)((int)piVar4 + 10) = 0;
      param_1 = (int *)((int)param_1 + 1);
      piVar4 = piVar4 + 3;
      piVar7 = piVar7 + 3;
    } while ((int)param_1 < *piVar2);
  }
  return piVar3;
}


// ==== FUN_007ea6a0 @ 0x007ea6a0 ====

int * FUN_007ea6a0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  
  if (param_1 == (int *)0x0) {
    return (int *)0x0;
  }
  piVar4 = (int *)FUN_007d0590(0xc);
  if (piVar4 != (int *)0x0) {
    iVar5 = *param_1;
    piVar4[1] = iVar5;
    *piVar4 = iVar5;
    iVar5 = FUN_007d0590(*param_1 << 3);
    piVar4[2] = iVar5;
    if (iVar5 != 0) {
      iVar5 = 0;
      if (0 < *param_1) {
        do {
          iVar2 = param_1[2];
          iVar3 = piVar4[2];
          iVar1 = iVar5 * 8;
          uVar6 = FUN_007d0640(*(undefined4 *)(iVar2 + iVar1));
          *(undefined4 *)(iVar3 + iVar1) = uVar6;
          ((undefined4 *)(iVar3 + iVar1))[1] = *(undefined4 *)(iVar2 + iVar1 + 4);
          iVar5 = iVar5 + 1;
        } while (iVar5 < *param_1);
      }
      return piVar4;
    }
    FUN_007d05b0(piVar4);
  }
  return (int *)0x0;
}


// ==== FUN_007ea740 @ 0x007ea740 ====

void FUN_007ea740(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    puVar1 = (undefined4 *)param_1[2];
    iVar2 = 0;
    if (0 < *param_1) {
      do {
        FUN_007eabc0(*puVar1);
        FUN_007d05b0(puVar1[1]);
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 3;
      } while (iVar2 < *param_1);
    }
    FUN_007d05b0(param_1[2]);
    FUN_007d05b0(param_1);
  }
  return;
}


// ==== FUN_007ea790 @ 0x007ea790 ====

undefined4 FUN_007ea790(undefined4 param_1)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (in_EAX == (int *)0x0) {
    return 0;
  }
  iVar2 = *in_EAX;
  puVar3 = (undefined4 *)in_EAX[2];
  while( true ) {
    if (iVar2 < 1) {
      return 0;
    }
    iVar1 = FUN_007eae70(*puVar3,param_1);
    if (iVar1 != 0) break;
    iVar2 = iVar2 + -1;
    puVar3 = puVar3 + 3;
  }
  return 1;
}


// ==== FUN_007ea890 @ 0x007ea890 ====

undefined4 FUN_007ea890(char *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  pcVar3 = param_1;
  while( true ) {
    cVar1 = *pcVar3;
    if (cVar1 == 'W') {
      iVar2 = FUN_007ea890(*(undefined4 *)(pcVar3 + 8),&param_1);
      if (iVar2 == 0) {
        return 0;
      }
      *param_2 = -(int)param_1;
      return 1;
    }
    if (cVar1 != 'X') break;
    pcVar3 = *(char **)(pcVar3 + 8);
  }
  if (cVar1 != '\x7f') {
    return 0;
  }
  iVar2 = FUN_007d0dd0(*(undefined4 *)(pcVar3 + 0x14),param_2);
  if (iVar2 == 0) {
    return 0;
  }
  return 1;
}


// ==== FUN_007ea8f0 @ 0x007ea8f0 ====

bool FUN_007ea8f0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_007d08e0(param_1,s__ROWID__00a01cc0);
  if (iVar1 != 0) {
    iVar1 = FUN_007d08e0(param_1,s_ROWID_00a01cb8);
    if (iVar1 != 0) {
      iVar1 = FUN_007d08e0(param_1,&PTR___break_00a01cb4);
      return iVar1 == 0;
    }
  }
  return true;
}


// ==== FUN_007ea940 @ 0x007ea940 ====

void FUN_007ea940(void)

{
  int iVar1;
  
  iVar1 = FUN_007d0dd0();
  if (iVar1 != 0) {
    FUN_007dc140();
    return;
  }
  iVar1 = FUN_007d0e00();
  if (iVar1 == 0) {
    FUN_007dda80();
    return;
  }
  FUN_007dda80();
  return;
}


// ==== FUN_007ea9a0 @ 0x007ea9a0 ====

int FUN_007ea9a0(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_2 == (int *)0x0) {
    return 0;
  }
  FUN_007e8190(param_1);
  iVar1 = *param_2;
  puVar3 = (undefined4 *)param_2[2];
  if (0 < iVar1) {
    iVar2 = iVar1;
    do {
      FUN_007ec010(param_1,*puVar3);
      puVar3 = puVar3 + 3;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return iVar1;
}


// ==== FUN_007ea9f0 @ 0x007ea9f0 ====

bool FUN_007ea9f0(char *param_1,char *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == (char *)0x0) {
    return param_2 == (char *)0x0;
  }
  if ((((param_2 == (char *)0x0) || (*param_1 != *param_2)) ||
      (iVar1 = FUN_007ea9f0(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_2 + 8)), iVar1 == 0))
     || (iVar1 = FUN_007ea9f0(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_2 + 0xc)),
        iVar1 == 0)) {
    return false;
  }
  piVar2 = *(int **)(param_1 + 0x10);
  if (piVar2 == (int *)0x0) {
    if (*(int *)(param_2 + 0x10) != 0) {
      return false;
    }
  }
  else {
    if (*(int **)(param_2 + 0x10) == (int *)0x0) {
      return false;
    }
    if (*piVar2 != **(int **)(param_2 + 0x10)) {
      return false;
    }
    iVar1 = 0;
    if (0 < *piVar2) {
      iVar4 = 0;
      do {
        iVar3 = FUN_007ea9f0(*(undefined4 *)(piVar2[2] + iVar4),
                             *(undefined4 *)(*(int *)(*(int *)(param_2 + 0x10) + 8) + iVar4));
        if (iVar3 == 0) {
          return false;
        }
        piVar2 = *(int **)(param_1 + 0x10);
        iVar1 = iVar1 + 1;
        iVar4 = iVar4 + 0xc;
      } while (iVar1 < *piVar2);
    }
  }
  if ((((*(int *)(param_1 + 0x34) == 0) && (*(int *)(param_2 + 0x34) == 0)) &&
      ((*(int *)(param_1 + 0x24) == *(int *)(param_2 + 0x24) &&
       (*(int *)(param_1 + 0x28) == *(int *)(param_2 + 0x28))))) &&
     ((*(int *)(param_1 + 0x14) == 0 ||
      (((*(int *)(param_2 + 0x14) != 0 &&
        (*(uint *)(param_2 + 0x18) >> 1 == *(uint *)(param_1 + 0x18) >> 1)) &&
       (iVar1 = FUN_007d0930(*(int *)(param_1 + 0x14),*(int *)(param_2 + 0x14),
                             *(uint *)(param_2 + 0x18) >> 1), iVar1 == 0)))))) {
    return true;
  }
  return false;
}


// ==== FUN_007eab00 @ 0x007eab00 ====

int FUN_007eab00(void)

{
  undefined4 *puVar1;
  int iVar2;
  int unaff_ESI;
  
  if ((*(uint *)(unaff_ESI + 0xa8) & 7) == 0) {
    iVar2 = FUN_007d05d0(*(undefined4 *)(unaff_ESI + 0xac),
                         (*(uint *)(unaff_ESI + 0xa8) * 3 + 0x18) * 4);
    if (iVar2 == 0) {
      return -1;
    }
    *(int *)(unaff_ESI + 0xac) = iVar2;
  }
  puVar1 = (undefined4 *)(*(int *)(unaff_ESI + 0xac) + *(int *)(unaff_ESI + 0xa8) * 0xc);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  iVar2 = *(int *)(unaff_ESI + 0xa8);
  *(int *)(unaff_ESI + 0xa8) = iVar2 + 1;
  return iVar2;
}


// ==== FUN_007eab60 @ 0x007eab60 ====

undefined1 * FUN_007eab60(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  puVar3 = (undefined1 *)FUN_007d0550(0x3c);
  if (puVar3 == (undefined1 *)0x0) {
    FUN_007ea740(param_1);
    return (undefined1 *)0x0;
  }
  *(undefined4 *)(puVar3 + 0x10) = param_1;
  *puVar3 = 6;
  if (param_2 == (undefined4 *)0x0) {
    *(undefined4 *)(puVar3 + 0x14) = 0;
    *(undefined4 *)(puVar3 + 0x1c) = *(undefined4 *)(puVar3 + 0x14);
    *(undefined4 *)(puVar3 + 0x20) = *(undefined4 *)(puVar3 + 0x18);
    return puVar3;
  }
  uVar1 = *param_2;
  *(undefined4 *)(puVar3 + 0x14) = uVar1;
  uVar2 = param_2[1];
  *(undefined4 *)(puVar3 + 0x18) = uVar2;
  *(undefined4 *)(puVar3 + 0x1c) = uVar1;
  *(undefined4 *)(puVar3 + 0x20) = uVar2;
  return puVar3;
}


// ==== FUN_007eabc0 @ 0x007eabc0 ====

void FUN_007eabc0(int param_1)

{
  if (param_1 != 0) {
    if ((*(byte *)(param_1 + 0x20) & 1) != 0) {
      FUN_007d05b0(*(undefined4 *)(param_1 + 0x1c));
    }
    if ((*(byte *)(param_1 + 0x18) & 1) != 0) {
      FUN_007d05b0(*(undefined4 *)(param_1 + 0x14));
    }
    FUN_007eabc0(*(undefined4 *)(param_1 + 8));
    FUN_007eabc0(*(undefined4 *)(param_1 + 0xc));
    FUN_007ea740(*(undefined4 *)(param_1 + 0x10));
    FUN_007e6af0(*(undefined4 *)(param_1 + 0x34));
    FUN_007d05b0(param_1);
  }
  return;
}


// ==== FUN_007eac20 @ 0x007eac20 ====

short * FUN_007eac20(short *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  undefined4 uVar5;
  short *psVar6;
  short *psVar7;
  
  if (param_1 != (short *)0x0) {
    if (*param_1 < 1) {
      iVar3 = 0;
    }
    else {
      iVar3 = (*param_1 + -1) * 0x28;
    }
    psVar4 = (short *)FUN_007d0590(iVar3 + 0x2c);
    if (psVar4 != (short *)0x0) {
      sVar1 = *param_1;
      iVar3 = 0;
      psVar4[1] = sVar1;
      *psVar4 = sVar1;
      if (0 < *param_1) {
        psVar7 = param_1 + 0xc;
        psVar6 = psVar4 + 4;
        do {
          uVar5 = FUN_007d0640(*(undefined4 *)(psVar7 + -10));
          *(undefined4 *)(psVar6 + -2) = uVar5;
          uVar5 = FUN_007d0640(*(undefined4 *)(((int)param_1 - (int)psVar4) + (int)psVar6));
          *(undefined4 *)psVar6 = uVar5;
          uVar5 = FUN_007d0640(*(undefined4 *)(psVar7 + -6));
          *(undefined4 *)(psVar6 + 2) = uVar5;
          *(undefined4 *)(psVar6 + 8) = *(undefined4 *)psVar7;
          *(undefined4 *)(psVar6 + 10) = *(undefined4 *)(psVar7 + 2);
          iVar2 = *(int *)(psVar7 + -4);
          *(int *)(psVar6 + 4) = iVar2;
          if (iVar2 != 0) {
            *(int *)(iVar2 + 0x24) = *(int *)(iVar2 + 0x24) + 1;
          }
          uVar5 = FUN_007ead10(*(undefined4 *)(psVar7 + -2));
          *(undefined4 *)(psVar6 + 6) = uVar5;
          uVar5 = FUN_007eb2d0(*(undefined4 *)(psVar7 + 4));
          *(undefined4 *)(psVar6 + 0xc) = uVar5;
          uVar5 = FUN_007ea6a0(*(undefined4 *)(psVar7 + 6));
          *(undefined4 *)(psVar6 + 0xe) = uVar5;
          *(undefined4 *)(psVar6 + 0x10) = *(undefined4 *)(psVar7 + 8);
          iVar3 = iVar3 + 1;
          psVar6 = psVar6 + 0x14;
          psVar7 = psVar7 + 0x14;
        } while (iVar3 < *param_1);
      }
      return psVar4;
    }
  }
  return (short *)0x0;
}


// ==== FUN_007ead10 @ 0x007ead10 ====

undefined4 * FUN_007ead10(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar1 = (undefined4 *)FUN_007d0590(0x38);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *(undefined1 *)((int)puVar1 + 5) = *(undefined1 *)((int)param_1 + 5);
  uVar2 = FUN_007ea5c0(*param_1);
  *puVar1 = uVar2;
  uVar2 = FUN_007eac20(param_1[2]);
  puVar1[2] = uVar2;
  uVar2 = FUN_007eb2d0(param_1[3]);
  puVar1[3] = uVar2;
  uVar2 = FUN_007ea5c0(param_1[4]);
  puVar1[4] = uVar2;
  uVar2 = FUN_007eb2d0(param_1[5]);
  puVar1[5] = uVar2;
  uVar2 = FUN_007ea5c0(param_1[6]);
  puVar1[6] = uVar2;
  *(undefined1 *)(puVar1 + 1) = *(undefined1 *)(param_1 + 1);
  uVar2 = FUN_007ead10(param_1[7]);
  puVar1[7] = uVar2;
  uVar2 = FUN_007eb2d0(param_1[8]);
  puVar1[8] = uVar2;
  uVar2 = FUN_007eb2d0(param_1[9]);
  puVar1[9] = uVar2;
  puVar1[10] = 0xffffffff;
  puVar1[0xb] = 0xffffffff;
  puVar1[0xc] = 0;
  *(undefined1 *)(puVar1 + 0xd) = *(undefined1 *)(param_1 + 0xd);
  *(undefined1 *)((int)puVar1 + 0x35) = *(undefined1 *)((int)param_1 + 0x35);
  return puVar1;
}


// ==== FUN_007eadd0 @ 0x007eadd0 ====

int * FUN_007eadd0(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == (int *)0x0) {
    param_1 = (int *)FUN_007d0550(0xc);
    if (param_1 == (int *)0x0) goto LAB_007eae0c;
  }
  if (param_1[1] <= *param_1) {
    iVar3 = param_1[1] * 2 + 4;
    iVar2 = FUN_007d05d0(param_1[2],iVar3 * 0xc);
    if (iVar2 == 0) {
LAB_007eae0c:
      FUN_007eabc0(param_2);
      FUN_007ea740(param_1);
      return (int *)0x0;
    }
    param_1[2] = iVar2;
    param_1[1] = iVar3;
  }
  if ((param_2 != 0) || (param_3 != 0)) {
    piVar1 = (int *)(param_1[2] + *param_1 * 0xc);
    *param_1 = *param_1 + 1;
    *piVar1 = 0;
    piVar1[1] = 0;
    piVar1[2] = 0;
    iVar3 = FUN_007d2730(param_3);
    piVar1[1] = iVar3;
    *piVar1 = param_2;
  }
  return param_1;
}


// ==== FUN_007eae70 @ 0x007eae70 ====

bool FUN_007eae70(int param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return false;
  }
  iVar1 = (*param_2)(param_3,param_1);
  if (iVar1 != 0) {
LAB_007eaed3:
    return 1 < iVar1;
  }
  iVar2 = FUN_007eae70(*(undefined4 *)(param_1 + 8),param_2,param_3);
  if (iVar2 == 0) {
    iVar2 = FUN_007eae70(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
    if (iVar2 == 0) {
      iVar2 = FUN_007ea790(param_2);
      if (iVar2 == 0) goto LAB_007eaed3;
    }
  }
  return true;
}


// ==== FUN_007eaee0 @ 0x007eaee0 ====

undefined4 FUN_007eaee0(undefined4 param_1)

{
  undefined4 local_4;
  
  local_4 = 1;
  FUN_007eae70(param_1,&LAB_007ea7d0,&local_4);
  return local_4;
}


// ==== FUN_007eaf10 @ 0x007eaf10 ====

undefined4 FUN_007eaf10(int *param_1,char *param_2)

{
  undefined1 uVar1;
  short *psVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  
  psVar2 = (short *)param_1[1];
  piVar3 = (int *)*param_1;
  if (*param_2 != '\a') {
    if ((*param_2 != '\b') || (param_1[6] != 0)) {
      if (*(int *)(param_2 + 0x34) != 0) {
        param_1[6] = param_1[6] + 1;
        iVar7 = *(int *)(param_2 + 0x34);
        FUN_007ea790(FUN_007eaf10);
        FUN_007eae70(*(undefined4 *)(iVar7 + 0xc),FUN_007eaf10,param_1);
        FUN_007ea790(FUN_007eaf10);
        FUN_007eae70(*(undefined4 *)(iVar7 + 0x14),FUN_007eaf10,param_1);
        FUN_007ea790(FUN_007eaf10);
        param_1[6] = param_1[6] + -1;
      }
      return 0;
    }
    piVar6 = (int *)piVar3[0x2b];
    iVar7 = 0;
    if (0 < piVar3[0x2a]) {
      do {
        if ((*piVar6 != 0) && (iVar4 = FUN_007ea9f0(piVar6[1],param_2), iVar4 != 0)) break;
        iVar7 = iVar7 + 1;
        piVar6 = piVar6 + 3;
      } while (iVar7 < piVar3[0x2a]);
    }
    if (piVar3[0x2a] <= iVar7) {
      uVar1 = *(undefined1 *)(*piVar3 + 0x10);
      iVar7 = FUN_007eab00();
      if (iVar7 < 0) {
        return 1;
      }
      iVar4 = iVar7 * 0xc;
      *(undefined4 *)(iVar4 + piVar3[0x2b]) = 1;
      *(char **)(iVar4 + 4 + piVar3[0x2b]) = param_2;
      if (*(undefined4 **)(param_2 + 0x10) == (undefined4 *)0x0) {
        uVar5 = 0;
      }
      else {
        uVar5 = **(undefined4 **)(param_2 + 0x10);
      }
      uVar5 = FUN_007de2e0(*piVar3,*(undefined4 *)(param_2 + 0x14),*(uint *)(param_2 + 0x18) >> 1,
                           uVar5,uVar1,0);
      *(undefined4 *)(iVar4 + 8 + piVar3[0x2b]) = uVar5;
    }
    *(int *)(param_2 + 0x2c) = iVar7;
    return 1;
  }
  iVar7 = 0;
  if (psVar2 == (short *)0x0) {
    return 1;
  }
  piVar6 = (int *)(psVar2 + 0xe);
  while( true ) {
    if (*psVar2 <= iVar7) {
      return 1;
    }
    if (*(int *)(param_2 + 0x24) == *piVar6) break;
    iVar7 = iVar7 + 1;
    piVar6 = piVar6 + 10;
  }
  iVar7 = 0;
  if (0 < piVar3[0x2a]) {
    piVar6 = (int *)(piVar3[0x2b] + 4);
    do {
      if (((piVar6[-1] == 0) && (*(int *)(*piVar6 + 0x24) == *(int *)(param_2 + 0x24))) &&
         (*(int *)(*piVar6 + 0x28) == *(int *)(param_2 + 0x28))) break;
      iVar7 = iVar7 + 1;
      piVar6 = piVar6 + 3;
    } while (iVar7 < piVar3[0x2a]);
  }
  if (piVar3[0x2a] <= iVar7) {
    iVar7 = FUN_007eab00();
    if (iVar7 < 0) {
      return 1;
    }
    *(undefined4 *)(iVar7 * 0xc + piVar3[0x2b]) = 0;
    *(char **)(iVar7 * 0xc + 4 + piVar3[0x2b]) = param_2;
  }
  *(int *)(param_2 + 0x2c) = iVar7;
  *(int *)(param_2 + 0x30) = param_1[6];
  return 1;
}


// ==== FUN_007eb100 @ 0x007eb100 ====

int FUN_007eb100(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*param_1 + 0x18);
  FUN_007eae70(param_2,FUN_007eaf10,param_1);
  return *(int *)(*param_1 + 0x18) - iVar1;
}


// ==== FUN_007eb130 @ 0x007eb130 ====

undefined1 * FUN_007eb130(undefined1 param_1,int param_2,int param_3,undefined4 *param_4)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_007d0550(0x3c);
  if (puVar1 == (undefined1 *)0x0) {
    FUN_007eabc0(param_2);
    FUN_007eabc0(param_3);
    return (undefined1 *)0x0;
  }
  *puVar1 = param_1;
  *(int *)(puVar1 + 8) = param_2;
  *(int *)(puVar1 + 0xc) = param_3;
  *(undefined4 *)(puVar1 + 0x2c) = 0xffffffff;
  if (param_4 != (undefined4 *)0x0) {
    *(undefined4 *)(puVar1 + 0x14) = *param_4;
    *(undefined4 *)(puVar1 + 0x18) = param_4[1];
    *(undefined4 *)(puVar1 + 0x1c) = *param_4;
    *(undefined4 *)(puVar1 + 0x20) = param_4[1];
    return puVar1;
  }
  if ((param_2 != 0) && (param_3 != 0)) {
    FUN_007ea3c0(puVar1,param_2 + 0x1c,param_3 + 0x1c);
  }
  return puVar1;
}


// ==== FUN_007eb1c0 @ 0x007eb1c0 ====

undefined1 * FUN_007eb1c0(int param_1,int *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  long lVar3;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 != 0) {
    if (*(char *)(param_1 + 0x13) != '\0') {
      puVar2 = (undefined1 *)FUN_007d0550(0x3c);
      if (puVar2 == (undefined1 *)0x0) {
        FUN_007eabc0(0);
        FUN_007eabc0(0);
        return (undefined1 *)0x0;
      }
      *puVar2 = 0x82;
      *(undefined4 *)(puVar2 + 8) = 0;
      *(undefined4 *)(puVar2 + 0xc) = 0;
      *(undefined4 *)(puVar2 + 0x2c) = 0xffffffff;
      if (param_2 != (int *)0x0) {
        *(int *)(puVar2 + 0x14) = *param_2;
        *(int *)(puVar2 + 0x18) = param_2[1];
        *(int *)(puVar2 + 0x1c) = *param_2;
        *(int *)(puVar2 + 0x20) = param_2[1];
      }
      lVar3 = _atol((char *)(*param_2 + 1));
      if (lVar3 < 0) {
        *(int *)(puVar2 + 0x24) = -1 - lVar3;
        return puVar2;
      }
      *(undefined4 *)(puVar2 + 0x24) = *(undefined4 *)(param_1 + 0x20);
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
      FUN_007dc140(iVar1,0x60,lVar3,0);
      FUN_007dc140(iVar1,0x78,*(undefined4 *)(puVar2 + 0x24),1);
      return puVar2;
    }
    FUN_007d0820(param_1,s_near___T___syntax_error_00a01cc8,param_2);
  }
  return (undefined1 *)0x0;
}


// ==== FUN_007eb2a0 @ 0x007eb2a0 ====

int FUN_007eb2a0(int param_1,int param_2)

{
  if (param_1 == 0) {
    return param_2;
  }
  if (param_2 != 0) {
    param_1 = FUN_007eb130(0x3f,param_1,param_2,0);
  }
  return param_1;
}


// ==== FUN_007eb2d0 @ 0x007eb2d0 ====

undefined4 * FUN_007eb2d0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar1 = (undefined4 *)FUN_007d0590(0x3c);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar4 = param_1;
  puVar5 = puVar1;
  for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  if (param_1[5] != 0) {
    uVar2 = FUN_007d06a0(param_1[5],(uint)param_1[6] >> 1);
    puVar1[5] = uVar2;
    puVar1[6] = puVar1[6] | 1;
  }
  puVar1[7] = 0;
  uVar2 = FUN_007eb2d0(param_1[2]);
  puVar1[2] = uVar2;
  uVar2 = FUN_007eb2d0(param_1[3]);
  puVar1[3] = uVar2;
  uVar2 = FUN_007ea5c0(param_1[4]);
  puVar1[4] = uVar2;
  uVar2 = FUN_007ead10(param_1[0xd]);
  puVar1[0xd] = uVar2;
  puVar1[0xe] = param_1[0xe];
  return puVar1;
}


// ==== FUN_007eb370 @ 0x007eb370 ====

undefined4
FUN_007eb370(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,int param_5,
            undefined1 *param_6)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  short *psVar9;
  short *psVar10;
  char *pcVar11;
  int iVar12;
  int local_2c;
  int local_20;
  int local_1c;
  int local_18;
  short *local_14;
  int local_10;
  int local_c;
  short *local_8;
  int *local_4;
  
  local_c = *param_1;
  local_2c = 0;
  local_1c = 0;
  local_14 = (short *)0x0;
  local_10 = param_5;
  local_18 = FUN_007d2730(param_2);
  iVar2 = FUN_007d2730(param_3);
  uVar3 = FUN_007d2730(param_4);
  if (DAT_00b5c4c4 != 0) goto LAB_007eb891;
  *(undefined4 *)(param_6 + 0x24) = 0xffffffff;
  if (param_5 == 0) {
LAB_007eb76f:
    if ((iVar2 == 0) && (*(char *)*param_4 == '\"')) {
      FUN_007d05b0(uVar3);
      return 0;
    }
LAB_007eb7c9:
    local_1c = 0;
    pcVar11 = s_no_such_column___s_00a01cfc;
    if (local_2c != 0) {
      pcVar11 = s_ambiguous_column_name___s_00a01ce0;
    }
    if (local_18 == 0) {
      if (iVar2 == 0) {
        local_1c = FUN_007d0640(uVar3);
      }
      else {
        FUN_007d0700(&local_1c,iVar2,&DAT_00a0119c,uVar3,0);
      }
    }
    else {
      FUN_007d0700(&local_1c,local_18,&DAT_00a0119c,iVar2,&DAT_00a0119c,uVar3,0);
    }
    FUN_007d0820(param_1,pcVar11,local_1c);
    FUN_007d05b0(local_1c);
    *(int *)(local_10 + 0x10) = *(int *)(local_10 + 0x10) + 1;
  }
  else {
    do {
      if (local_2c != 0) goto LAB_007eb7be;
      local_8 = *(short **)(param_5 + 4);
      local_4 = *(int **)(param_5 + 8);
      if (local_8 != (short *)0x0) {
        local_20 = 0;
        psVar9 = local_8 + 2;
        if (0 < *local_8) {
LAB_007eb42b:
          iVar4 = local_18;
          piVar1 = *(int **)(psVar9 + 6);
          psVar10 = psVar9;
          if (piVar1 != (int *)0x0) {
            if (iVar2 != 0) {
              iVar12 = *(int *)(psVar9 + 4);
              if (iVar12 == 0) {
                if ((*piVar1 == 0) || (iVar12 = FUN_007d08e0(*piVar1,iVar2), iVar12 != 0))
                goto LAB_007eb579;
                if (iVar4 == 0) goto LAB_007eb490;
                iVar12 = *(int *)((uint)*(byte *)((int)piVar1 + 0x1d) * 0x70 + *(int *)(local_c + 4)
                                 );
              }
              else {
                iVar4 = iVar2;
              }
              iVar4 = FUN_007d08e0(iVar12,iVar4);
              if (iVar4 != 0) goto LAB_007eb579;
            }
LAB_007eb490:
            iVar4 = local_1c + 1;
            if (local_1c == 0) {
              *(undefined4 *)(param_6 + 0x24) = *(undefined4 *)(psVar9 + 0xc);
              param_6[2] = *(undefined1 *)((int)piVar1 + 0x1d);
              local_14 = psVar9;
            }
            puVar8 = (undefined4 *)piVar1[2];
            iVar12 = 0;
            local_1c = iVar4;
            if (0 < piVar1[1]) {
              do {
                iVar4 = FUN_007d08e0(*puVar8,uVar3);
                if (iVar4 == 0) {
                  local_2c = local_2c + 1;
                  *(undefined4 *)(param_6 + 0x24) = *(undefined4 *)(psVar9 + 0xc);
                  param_6[2] = *(undefined1 *)((int)piVar1 + 0x1d);
                  if (iVar12 == piVar1[3]) {
                    iVar4 = -1;
                  }
                  else {
                    iVar4 = iVar12;
                  }
                  *(int *)(param_6 + 0x28) = iVar4;
                  param_6[1] = *(undefined1 *)(iVar12 * 0x14 + 0x12 + piVar1[2]);
                  *(undefined4 *)(param_6 + 4) = *(undefined4 *)(iVar12 * 0x14 + 0xc + piVar1[2]);
                  if ((*(byte *)(psVar9 + 10) & 2) != 0) {
                    psVar10 = psVar9 + 0x14;
                    local_20 = local_20 + 1;
                  }
                  piVar1 = *(int **)(psVar10 + 0x10);
                  local_14 = psVar9;
                  if ((piVar1 != (int *)0x0) && (iVar4 = 0, 0 < *piVar1)) goto LAB_007eb550;
                  break;
                }
                iVar12 = iVar12 + 1;
                puVar8 = puVar8 + 5;
              } while (iVar12 < piVar1[1]);
            }
          }
          goto LAB_007eb579;
        }
      }
LAB_007eb598:
      if ((local_18 == 0) && (iVar2 != 0)) {
        if (local_2c == 0) {
          piVar1 = (int *)param_1[0x28];
          if (piVar1 != (int *)0x0) {
            if ((piVar1[1] == -1) || (iVar4 = FUN_007d08e0(&PTR_LAB_00a01d14,iVar2), iVar4 != 0)) {
              if ((piVar1[2] == -1) || (iVar4 = FUN_007d08e0(&DAT_00a01d10,iVar2), iVar4 != 0))
              goto LAB_007eb6a7;
              *(int *)(param_6 + 0x24) = piVar1[2];
            }
            else {
              *(int *)(param_6 + 0x24) = piVar1[1];
            }
            iVar4 = *piVar1;
            if (iVar4 != 0) {
              puVar8 = *(undefined4 **)(iVar4 + 8);
              param_6[2] = *(undefined1 *)(iVar4 + 0x1d);
              local_1c = local_1c + 1;
              iVar12 = 0;
              if (0 < *(int *)(iVar4 + 4)) {
                do {
                  iVar5 = FUN_007d08e0(*puVar8,uVar3);
                  if (iVar5 == 0) {
                    local_2c = 1;
                    if (iVar12 == *(int *)(iVar4 + 0xc)) {
                      iVar5 = -1;
                    }
                    else {
                      iVar5 = iVar12;
                    }
                    *(int *)(param_6 + 0x28) = iVar5;
                    param_6[1] = *(undefined1 *)(iVar12 * 0x14 + 0x12 + *(int *)(iVar4 + 8));
                    *(undefined4 *)(param_6 + 4) =
                         *(undefined4 *)(iVar12 * 0x14 + 0xc + *(int *)(iVar4 + 8));
                    *(int *)(param_6 + 0x38) = iVar4;
                    goto LAB_007eb75b;
                  }
                  iVar12 = iVar12 + 1;
                  puVar8 = puVar8 + 5;
                } while (iVar12 < *(int *)(iVar4 + 4));
              }
            }
          }
LAB_007eb6a7:
          if ((local_1c == 1) &&
             (((iVar4 = FUN_007d08e0(uVar3,s__ROWID__00a01cc0), iVar4 == 0 ||
               (iVar4 = FUN_007d08e0(uVar3,s_ROWID_00a01cb8), iVar4 == 0)) ||
              (iVar4 = FUN_007d08e0(uVar3,&PTR___break_00a01cb4), iVar4 == 0)))) {
            local_2c = 1;
            *(undefined4 *)(param_6 + 0x28) = 0xffffffff;
            param_6[1] = 0x69;
          }
          else {
            piVar1 = local_4;
            if (((local_4 != (int *)0x0) && (iVar2 == 0)) && (iVar4 = 0, 0 < *local_4)) {
              iVar12 = 0;
              do {
                iVar5 = *(int *)(piVar1[2] + 4 + iVar12);
                if ((iVar5 != 0) && (iVar5 = FUN_007d08e0(iVar5,uVar3), iVar5 == 0)) {
                  *param_6 = 0x19;
                  *(int *)(param_6 + 0x28) = iVar4;
                  uVar6 = FUN_007eb2d0(*(undefined4 *)(piVar1[2] + iVar4 * 0xc));
                  *(undefined4 *)(param_6 + 8) = uVar6;
                  local_2c = 1;
                  goto LAB_007eb967;
                }
                iVar4 = iVar4 + 1;
                iVar12 = iVar12 + 0xc;
              } while (iVar4 < *piVar1);
              if (local_2c != 0) goto LAB_007eb75b;
            }
            param_5 = *(int *)(param_5 + 0x1c);
          }
        }
      }
      else if (local_2c == 0) goto LAB_007eb6a7;
LAB_007eb75b:
    } while (param_5 != 0);
    if (local_2c == 0) goto LAB_007eb76f;
LAB_007eb7be:
    if (local_2c != 1) goto LAB_007eb7c9;
  }
  uVar7 = *(uint *)(param_6 + 0x28);
  if ((-1 < (int)uVar7) && (local_14 != (short *)0x0)) {
    if (0x1f < uVar7) {
      uVar7 = 0x1f;
    }
    *(uint *)(local_14 + 0x12) = *(uint *)(local_14 + 0x12) | 1 << ((byte)uVar7 & 0x1f);
  }
LAB_007eb891:
  FUN_007d05b0(local_18);
  FUN_007d05b0(iVar2);
  iVar2 = *(int *)(param_6 + 8);
  if (iVar2 != 0) {
    if ((*(byte *)(iVar2 + 0x20) & 1) != 0) {
      FUN_007d05b0(*(undefined4 *)(iVar2 + 0x1c));
    }
    if ((*(byte *)(iVar2 + 0x18) & 1) != 0) {
      FUN_007d05b0(*(undefined4 *)(iVar2 + 0x14));
    }
    FUN_007eabc0(*(undefined4 *)(iVar2 + 8));
    FUN_007eabc0(*(undefined4 *)(iVar2 + 0xc));
    FUN_007ea740(*(undefined4 *)(iVar2 + 0x10));
    FUN_007e6af0(*(undefined4 *)(iVar2 + 0x34));
    FUN_007d05b0(iVar2);
  }
  iVar2 = *(int *)(param_6 + 0xc);
  *(undefined4 *)(param_6 + 8) = 0;
  if (iVar2 != 0) {
    if ((*(byte *)(iVar2 + 0x20) & 1) != 0) {
      FUN_007d05b0(*(undefined4 *)(iVar2 + 0x1c));
    }
    if ((*(byte *)(iVar2 + 0x18) & 1) != 0) {
      FUN_007d05b0(*(undefined4 *)(iVar2 + 0x14));
    }
    FUN_007eabc0(*(undefined4 *)(iVar2 + 8));
    FUN_007eabc0(*(undefined4 *)(iVar2 + 0xc));
    FUN_007ea740(*(undefined4 *)(iVar2 + 0x10));
    FUN_007e6af0(*(undefined4 *)(iVar2 + 0x34));
    FUN_007d05b0(iVar2);
  }
  *(undefined4 *)(param_6 + 0xc) = 0;
  *param_6 = 7;
LAB_007eb967:
  FUN_007d05b0(uVar3);
  if (local_2c != 1) {
    return 1;
  }
  FUN_007ed490(param_1,param_6,*(undefined4 *)(param_5 + 4));
  if ((local_14 != (short *)0x0) && (*(int *)(local_14 + 8) == 0)) {
    *(undefined4 *)(param_6 + 0x38) = *(undefined4 *)(local_14 + 6);
  }
  *(int *)(local_10 + 0xc) = *(int *)(local_10 + 0xc) + 1;
  while (local_10 != param_5) {
    local_10 = *(int *)(local_10 + 0x1c);
    *(int *)(local_10 + 0xc) = *(int *)(local_10 + 0xc) + 1;
  }
  return 0;
  while (iVar4 = iVar4 + 1, iVar4 < *piVar1) {
LAB_007eb550:
    iVar12 = FUN_007d08e0(*(undefined4 *)(piVar1[2] + iVar4 * 8),uVar3);
    if (iVar12 == 0) {
      local_20 = local_20 + 1;
      psVar10 = psVar10 + 0x14;
      break;
    }
  }
LAB_007eb579:
  local_20 = local_20 + 1;
  psVar9 = psVar10 + 0x14;
  if (*local_8 <= local_20) goto LAB_007eb598;
  goto LAB_007eb42b;
}


// ==== FUN_007eb9e0 @ 0x007eb9e0 ====

bool FUN_007eb9e0(undefined4 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  char *pcVar10;
  
  puVar5 = param_2;
  iVar6 = 0;
  if (param_2 == (undefined1 *)0x0) {
    return true;
  }
  piVar2 = (int *)*param_1;
  if ((param_2[3] & 4) != 0) {
    return true;
  }
  param_2[3] = param_2[3] | 4;
  switch(*param_2) {
  case 6:
  case 9:
    piVar3 = *(int **)(param_2 + 0x10);
    if (piVar3 == (int *)0x0) {
      param_2 = (undefined1 *)0x0;
    }
    else {
      param_2 = (undefined1 *)*piVar3;
    }
    uVar4 = *(undefined4 *)(puVar5 + 0x14);
    bVar9 = false;
    uVar1 = *(undefined1 *)(*piVar2 + 0x10);
    uVar7 = *(uint *)(puVar5 + 0x18) >> 1;
    iVar6 = FUN_007de2e0(*piVar2,uVar4,uVar7,param_2,uVar1,0);
    if (iVar6 == 0) {
      iVar6 = FUN_007de2e0(*piVar2,uVar4,uVar7,0xffffffff,uVar1,0);
      if (iVar6 == 0) {
        pcVar10 = s_no_such_function_____s_00a01d18;
      }
      else {
        pcVar10 = s_wrong_number_of_arguments_to_fun_00a01d54;
      }
      FUN_007d0820(piVar2,pcVar10,uVar7,uVar4);
      param_1[4] = param_1[4] + 1;
    }
    else {
      bVar9 = *(int *)(iVar6 + 0x14) == 0;
      if (bVar9) {
        if (*(char *)(param_1 + 5) == '\0') {
          FUN_007d0820(piVar2,s_misuse_of_aggregate_function_____00a01d30,uVar7,uVar4);
          param_1[4] = param_1[4] + 1;
          bVar9 = false;
        }
        else {
          *puVar5 = 8;
          *(undefined1 *)((int)param_1 + 0x15) = 1;
          *(undefined1 *)(param_1 + 5) = 0;
        }
      }
    }
    iVar6 = 0;
    if (param_1[4] == 0) {
      iVar8 = 0;
      do {
        if ((int)param_2 <= iVar6) break;
        FUN_007eae70(*(undefined4 *)(piVar3[2] + iVar8),FUN_007eb9e0,param_1);
        iVar6 = iVar6 + 1;
        iVar8 = iVar8 + 0xc;
      } while (param_1[4] == 0);
    }
    if (bVar9 == false) {
      return false;
    }
    *(undefined1 *)(param_1 + 5) = 1;
    return bVar9;
  case 0x1b:
switchD_007eba33_caseD_1b:
    FUN_007eb370(piVar2,0,0,param_2 + 0x14,param_1,param_2);
    return true;
  case 0x43:
  case 0x71:
  case 0x84:
    if ((*(int *)(param_2 + 0x34) != 0) &&
       (iVar6 = param_1[3], FUN_007e9090(piVar2,*(int *)(param_2 + 0x34),param_1),
       iVar6 != param_1[3])) {
      param_2[3] = param_2[3] | 0x20;
    }
    break;
  case 0x5a:
    if (**(char **)(param_2 + 0x14) != '\'') goto switchD_007eba33_caseD_1b;
    break;
  case 0x73:
    pcVar10 = *(char **)(param_2 + 0xc);
    if (*pcVar10 == '\x1b') {
      iVar8 = *(int *)(param_2 + 8);
    }
    else {
      iVar8 = *(int *)(pcVar10 + 8);
      pcVar10 = *(char **)(pcVar10 + 0xc);
      iVar6 = *(int *)(param_2 + 8) + 0x14;
    }
    FUN_007eb370(piVar2,iVar6,iVar8 + 0x14,pcVar10 + 0x14,param_1,param_2);
    return true;
  }
  return false;
}


// ==== FUN_007ebc80 @ 0x007ebc80 ====

bool FUN_007ebc80(int param_1,int param_2)

{
  if (param_2 == 0) {
    return false;
  }
  FUN_007eae70(param_2,FUN_007eb9e0,param_1);
  if (0 < *(int *)(param_1 + 0x10)) {
    *(byte *)(param_2 + 3) = *(byte *)(param_2 + 3) | 8;
  }
  return (*(byte *)(param_2 + 3) & 8) == 8;
}


// ==== FUN_007ebcc0 @ 0x007ebcc0 ====

void FUN_007ebcc0(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  char local_25;
  int local_24;
  undefined4 *local_20;
  int *local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_18 = 0;
  iVar2 = FUN_007e8190(param_1);
  if (iVar2 == 0) {
    return;
  }
  if (((param_2[3] & 0x20U) == 0) && (*(int *)(param_1 + 0xa0) == 0)) {
    iVar4 = *(int *)(param_1 + 0x20);
    *(int *)(param_1 + 0x20) = iVar4 + 1;
    FUN_007dc140(iVar2,1,iVar4,0);
    local_18 = FUN_007dc190(iVar2);
    FUN_007dc140(iVar2,10,0,local_18);
    FUN_007dc140(iVar2,0x32,1,0);
    FUN_007dc140(iVar2,0x78,iVar4,1);
  }
  if (*(int *)(param_2 + 0x34) != 0) {
    FUN_007dc140(iVar2,0xc,0,0);
  }
  cVar1 = *param_2;
  if (cVar1 == 'C') {
    local_25 = FUN_007ea140(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(param_1 + 0x1c);
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    local_14 = FUN_007dc140(iVar2,0x2e,*(undefined4 *)(param_2 + 0x24),0);
    local_10 = 0;
    local_8 = 0;
    local_4 = 0;
    local_c = 1;
    FUN_007dc140(iVar2,0x67,*(undefined4 *)(param_2 + 0x24),1);
    if (*(int *)(param_2 + 0x34) == 0) {
      if (*(int **)(param_2 + 0x10) != (int *)0x0) {
        if (local_25 == '\0') {
          local_25 = 'n';
        }
        local_4 = *(undefined4 *)(*(int *)(param_2 + 8) + 4);
        local_1c = (int *)0x0;
        if (0 < **(int **)(param_2 + 0x10)) {
          local_24 = 0;
          do {
            uVar5 = *(undefined4 *)(local_24 + *(int *)(*(int *)(param_2 + 0x10) + 8));
            local_20 = (undefined4 *)0x1;
            FUN_007eae70(uVar5,&LAB_007ea7d0,&local_20);
            if (local_20 == (undefined4 *)0x0) {
              FUN_007d0820(param_1,s_right_hand_side_of_IN_operator_m_00a01d84);
              return;
            }
            FUN_007ec010(param_1,uVar5);
            FUN_007dda80(iVar2,0x5b,1,0,&local_25,1);
            FUN_007dc140(iVar2,0x6e,*(undefined4 *)(param_2 + 0x24),0);
            local_1c = (int *)((int)local_1c + 1);
            local_24 = local_24 + 0xc;
          } while ((int)local_1c < **(int **)(param_2 + 0x10));
        }
      }
    }
    else {
      FUN_007e9760(param_1,*(int *)(param_2 + 0x34),3,local_25 * 0x10000 + *(int *)(param_2 + 0x24),
                   0,0,0,0);
      piVar3 = (int *)**(int **)(param_2 + 0x34);
      if ((piVar3 != (int *)0x0) && (0 < *piVar3)) {
        local_4 = FUN_007ea350(*(undefined4 *)piVar3[2]);
      }
    }
    FUN_007dc430(iVar2,local_14,&local_10,0xfffffffa);
    goto LAB_007ebf1a;
  }
  if ((cVar1 != 'q') && (cVar1 != -0x7c)) goto LAB_007ebf1a;
  *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_1 + 0x20);
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  local_20 = *(undefined4 **)(param_2 + 0x34);
  if (*param_2 == 'q') {
    uVar5 = 2;
  }
  else {
    local_14 = 0xc;
    FUN_007ea740(*local_20);
    local_24 = FUN_007eb130(0x7f,0,0,&PTR_DAT_00a01c80);
    piVar3 = (int *)FUN_007d0550(0xc);
    if (piVar3 == (int *)0x0) {
LAB_007ebde5:
      FUN_007eabc0(local_24);
      FUN_007ea740(piVar3);
      piVar3 = (int *)0x0;
    }
    else {
      if (piVar3[1] <= *piVar3) {
        local_1c = (int *)(piVar3[1] * 2 + 4);
        iVar4 = FUN_007d05d0(piVar3[2],(int)local_1c * 0xc);
        if (iVar4 == 0) goto LAB_007ebde5;
        piVar3[2] = iVar4;
        piVar3[1] = (int)local_1c;
      }
      if (local_24 != 0) {
        iVar4 = *piVar3;
        *piVar3 = iVar4 + 1;
        local_1c = (int *)(piVar3[2] + iVar4 * 0xc);
        *local_1c = 0;
        local_1c[1] = 0;
        local_1c[2] = 0;
        iVar4 = FUN_007d2730(0);
        local_1c[1] = iVar4;
        *local_1c = local_24;
      }
    }
    *local_20 = piVar3;
    uVar5 = local_14;
  }
  FUN_007e9760(param_1,local_20,uVar5,*(undefined4 *)(param_2 + 0x28),0,0,0,0);
LAB_007ebf1a:
  if (*(int *)(param_2 + 0x34) != 0) {
    FUN_007dc140(iVar2,0x5d,0,0);
  }
  if (local_18 < 0) {
    FUN_007dc1e0(iVar2,local_18);
  }
  return;
}


// ==== FUN_007ec010 @ 0x007ec010 ====

void FUN_007ec010(int *param_1,undefined1 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined1 uVar3;
  int iVar4;
  char *_Dest;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined1 *puVar13;
  undefined4 local_10;
  uint local_c;
  int local_4;
  
  piVar2 = param_1;
  iVar1 = param_1[3];
  if (iVar1 == 0) {
    return;
  }
LAB_007ec030:
  puVar13 = param_2;
  if (param_2 == (undefined1 *)0x0) {
switchD_007ec052_caseD_5e:
    FUN_007dc140(iVar1,0x76,0,0);
    return;
  }
  uVar3 = *param_2;
  switch(uVar3) {
  case 6:
  case 9:
    puVar11 = *(undefined4 **)(param_2 + 0x10);
    if (puVar11 == (undefined4 *)0x0) {
      local_10 = 0;
    }
    else {
      local_10 = *puVar11;
    }
    iVar4 = *param_1;
    local_c = 0;
    param_1 = (int *)0x0;
    iVar4 = FUN_007de2e0(iVar4,*(undefined4 *)(param_2 + 0x14),*(uint *)(param_2 + 0x18) >> 1,
                         local_10,*(undefined1 *)(iVar4 + 0x10),0);
    iVar5 = FUN_007ea9a0(piVar2,puVar11);
    iVar12 = 0;
    if (iVar5 < 1) goto LAB_007ec3a3;
    iVar10 = 0;
    goto LAB_007ec340;
  case 7:
    if (((char)param_1[5] == '\0') && (-1 < *(int *)(param_2 + 0x2c))) {
      FUN_007dc140(iVar1,0x6a,*(undefined4 *)(param_2 + 0x30),*(int *)(param_2 + 0x2c));
      return;
    }
    if (*(int *)(param_2 + 0x28) < 0) {
      FUN_007dc140(iVar1,0x26,*(undefined4 *)(param_2 + 0x24),0);
      return;
    }
    FUN_007dc140(iVar1,2,*(undefined4 *)(param_2 + 0x24),*(int *)(param_2 + 0x28));
    FUN_007f8be0(iVar1,*(undefined4 *)(puVar13 + 0x38),*(undefined4 *)(puVar13 + 0x28));
    return;
  case 8:
    FUN_007dc140(iVar1,0x6a,0,*(undefined4 *)(param_2 + 0x2c));
    return;
  case 0x19:
  case 0x58:
    goto switchD_007ec052_caseD_19;
  case 0x32:
    if (param_1[0x28] == 0) {
      FUN_007d0820(param_1,s_RAISE___may_only_be_used_within_a_00a01db4);
      return;
    }
    if (*(int *)(param_2 + 0x28) != 4) {
      FUN_007dda80(iVar1,0x25,0x13,*(int *)(param_2 + 0x28),*(undefined4 *)(param_2 + 0x14),
                   *(uint *)(param_2 + 0x18) >> 1);
      FUN_007dc550(iVar1,0xffffffff);
      return;
    }
    FUN_007dc140(iVar1,0x6b,0,0);
    FUN_007dc140(iVar1,0x61,0,*(undefined4 *)(piVar2[0x28] + 0x10));
    break;
  case 0x3e:
  case 0x3f:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
    FUN_007ec010(param_1,*(undefined4 *)(param_2 + 8));
    FUN_007ec010(piVar2,*(undefined4 *)(puVar13 + 0xc));
    FUN_007dc140(iVar1,uVar3,0,0);
    return;
  case 0x40:
  case 0x59:
    goto switchD_007ec052_caseD_40;
  case 0x42:
    param_1 = *(int **)(*(int *)(param_2 + 0x10) + 8);
    uVar7 = *param_1;
    FUN_007ec010(piVar2,*(undefined4 *)(param_2 + 8));
    FUN_007dc140(iVar1,0x60,0,0);
    FUN_007ec010(piVar2,uVar7);
    FUN_007ea370(uVar7,0x4b,0);
    FUN_007dc140(iVar1,0x66,1,0);
    uVar7 = param_1[3];
    FUN_007ec010(piVar2,uVar7);
    FUN_007ea370(uVar7,0x49,0);
    FUN_007dc140(iVar1,0x3f,0,0);
    return;
  case 0x43:
    FUN_007ebcc0(param_1,param_2);
    uVar3 = FUN_007ea220();
    param_1 = (int *)CONCAT31(param_1._1_3_,uVar3);
    FUN_007dc140(iVar1,0x32,1,0);
    FUN_007ec010(piVar2,*(undefined4 *)(puVar13 + 8));
    iVar4 = FUN_007dc320(iVar1);
    FUN_007dc140(iVar1,0x45,0xffffffff,iVar4 + 4);
    FUN_007dc140(iVar1,0xb,2,0);
    FUN_007dc140(iVar1,0x76,0,0);
    FUN_007dc140(iVar1,0x61,0,iVar4 + 7);
    FUN_007dda80(iVar1,0x5b,1,0,&param_1,1);
    FUN_007dc140(iVar1,0x7b,*(undefined4 *)(puVar13 + 0x24),iVar4 + 7);
    FUN_007dc140(iVar1,0x28,0xffffffff,0);
    return;
  case 0x44:
  case 0x45:
    FUN_007dc140(iVar1,0x32,1,0);
    FUN_007ec010(piVar2,*(undefined4 *)(puVar13 + 8));
    iVar4 = FUN_007dc320(iVar1);
    FUN_007dc140(iVar1,uVar3,1,iVar4 + 2);
    FUN_007dc140(iVar1,0x28,0xffffffff,0);
    return;
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4b:
    FUN_007ec010(param_1,*(undefined4 *)(param_2 + 8));
    FUN_007ec010(piVar2,*(undefined4 *)(puVar13 + 0xc));
    FUN_007ea370(*(undefined4 *)(puVar13 + 0xc),uVar3,0);
    return;
  case 0x57:
    param_1 = *(int **)(param_2 + 8);
    if (((char)*param_1 == -0x80) || ((char)*param_1 == '\x7f')) {
      _Dest = (char *)FUN_007d0550(((uint)param_1[6] >> 1) + 2);
      piVar2 = param_1;
      _sprintf(_Dest,s_____s_00a01de8,(uint)param_1[6] >> 1,param_1[5]);
      if ((char)*piVar2 == -0x80) {
        FUN_007dda80(iVar1,0x80,0,0,_Dest,((uint)piVar2[6] >> 1) + 1);
        FUN_007d05b0(_Dest);
        return;
      }
      FUN_007ea940();
      FUN_007d05b0(_Dest);
      return;
    }
switchD_007ec052_caseD_40:
    FUN_007ec010(piVar2,*(undefined4 *)(param_2 + 8));
    FUN_007dc140(iVar1,uVar3,0,0);
    return;
  case 0x5a:
  case 0x80:
    iVar4 = *(int *)(param_2 + 0x14);
    uVar9 = *(uint *)(param_2 + 0x18) >> 1;
    goto LAB_007ec117;
  case 0x5e:
    goto switchD_007ec052_caseD_5e;
  case 0x71:
  case 0x84:
    FUN_007ebcc0(param_1,param_2);
    FUN_007dc140(iVar1,1,*(undefined4 *)(puVar13 + 0x28),0);
    return;
  case 0x7f:
    FUN_007ea940();
    return;
  case 0x81:
    uVar9 = (*(uint *)(param_2 + 0x18) >> 1) - 1;
    iVar4 = *(int *)(param_2 + 0x14) + 1;
LAB_007ec117:
    FUN_007dda80(iVar1,uVar3,0,0,iVar4,uVar9);
    FUN_007dc550(iVar1,0xffffffff);
    return;
  case 0x82:
    FUN_007dc140(iVar1,1,*(undefined4 *)(param_2 + 0x24),0);
    return;
  case 0x83:
    FUN_007dc140(iVar1,0x1a,*(undefined4 *)(param_2 + 0x24),0);
    if (1 < *(uint *)(puVar13 + 0x18) >> 1) {
      FUN_007dc430(iVar1,0xffffffff,*(undefined4 *)(puVar13 + 0x14),*(uint *)(puVar13 + 0x18) >> 1);
      return;
    }
    break;
  case 0x85:
    param_1 = (int *)**(int **)(param_2 + 0x10);
    puVar11 = (undefined4 *)(*(int **)(param_2 + 0x10))[2];
    uVar7 = FUN_007dc190(iVar1);
    if (*(int *)(puVar13 + 8) != 0) {
      FUN_007ec010(piVar2,*(int *)(puVar13 + 8));
    }
    if (0 < (int)param_1) {
      local_4 = ((int)param_1 - 1U >> 1) + 1;
      do {
        FUN_007ec010(piVar2,*puVar11);
        if (*(int *)(puVar13 + 8) == 0) {
          param_1 = (int *)FUN_007dc140(iVar1,0x4c,1,0);
        }
        else {
          FUN_007dc140(iVar1,0x60,1,1);
          param_1 = (int *)FUN_007ea370(*puVar11,0x46,0);
          FUN_007dc140(iVar1,0xb,1,0);
          puVar13 = param_2;
        }
        FUN_007ec010(piVar2,puVar11[3]);
        FUN_007dc140(iVar1,0x61,0,uVar7);
        uVar8 = FUN_007dc320(iVar1);
        FUN_007dc400(iVar1,param_1,uVar8);
        puVar11 = puVar11 + 6;
        local_4 = local_4 + -1;
      } while (local_4 != 0);
    }
    if (*(int *)(puVar13 + 8) != 0) {
      FUN_007dc140(iVar1,0xb,1,0);
    }
    if (*(int *)(puVar13 + 0xc) == 0) {
      FUN_007dc140(iVar1,0x76,0,0);
      FUN_007dc1e0(iVar1,uVar7);
      return;
    }
    FUN_007ec010(piVar2,*(int *)(puVar13 + 0xc));
    FUN_007dc1e0(iVar1,uVar7);
    return;
  }
  return;
switchD_007ec052_caseD_19:
  param_2 = *(undefined1 **)(param_2 + 8);
  if (iVar1 == 0) {
    return;
  }
  goto LAB_007ec030;
  while( true ) {
    iVar6 = FUN_007eaee0(*(undefined4 *)(iVar10 + puVar11[2]));
    if (iVar6 != 0) {
      local_c = local_c | 1 << ((byte)iVar12 & 0x1f);
    }
    if ((*(char *)(iVar4 + 0x20) != '\0') && (param_1 == (int *)0x0)) {
      param_1 = (int *)FUN_007ea170(piVar2,*(undefined4 *)(iVar10 + puVar11[2]));
    }
    iVar12 = iVar12 + 1;
    iVar10 = iVar10 + 0xc;
    if (iVar5 <= iVar12) break;
LAB_007ec340:
    if (0x17f < iVar10) break;
  }
LAB_007ec3a3:
  if (*(char *)(iVar4 + 0x20) != '\0') {
    if (param_1 == (int *)0x0) {
      param_1 = *(int **)(*piVar2 + 0x18);
    }
    FUN_007dda80(iVar1,0xd,0,0,param_1,0xfffffffc);
  }
  FUN_007dda80(iVar1,0x16,iVar5,local_c,iVar4,0xfffffffb);
  return;
}


// ==== FUN_007ec7c0 @ 0x007ec7c0 ====

void FUN_007ec7c0(int param_1,undefined1 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 != 0) {
    iVar3 = FUN_007dc320(iVar1);
    FUN_007ec010(param_1,param_2);
    iVar4 = FUN_007dc320(iVar1);
    if ((iVar3 + 1 < iVar4) || (pcVar5 = (char *)FUN_007dc5b0(iVar1,iVar3), *pcVar5 == '\x16')) {
      uVar2 = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(param_2 + 0x24) = uVar2;
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
      FUN_007dc140(iVar1,0x78,uVar2,0);
      *param_2 = 0x82;
    }
  }
  return;
}


// ==== FUN_007ec830 @ 0x007ec830 ====

void FUN_007ec830(int param_1,undefined1 *param_2,undefined4 param_3,int param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0xc);
  if (iVar4 == 0) {
    return;
  }
LAB_007ec847:
  if (param_2 == (undefined1 *)0x0) {
    return;
  }
  uVar1 = *param_2;
  switch(uVar1) {
  case 0x3e:
    break;
  case 0x3f:
    uVar3 = FUN_007dc190(iVar4);
    FUN_007eca30(param_1,*(undefined4 *)(param_2 + 8),uVar3,param_4 == 0);
    FUN_007ec830(param_1,*(undefined4 *)(param_2 + 0xc),param_3,param_4);
    FUN_007dc1e0(iVar4,uVar3);
    return;
  case 0x40:
    FUN_007eca30(param_1,*(undefined4 *)(param_2 + 8),param_3,param_4);
    return;
  default:
    FUN_007ec010(param_1,param_2);
    FUN_007dc140(iVar4,10,param_4,param_3);
    return;
  case 0x42:
    uVar3 = **(undefined4 **)(*(int *)(param_2 + 0x10) + 8);
    FUN_007ec010(param_1,*(undefined4 *)(param_2 + 8));
    FUN_007dc140(iVar4,0x60,0,0);
    FUN_007ec010(param_1,uVar3);
    uVar2 = FUN_007ea370(uVar3,0x4a,0);
    uVar3 = *(undefined4 *)(*(int *)(*(int *)(param_2 + 0x10) + 8) + 0xc);
    FUN_007ec010(param_1,uVar3);
    FUN_007ea370(uVar3,0x49,param_3);
    FUN_007dc140(iVar4,0x32,0,0);
    uVar3 = FUN_007dc320(iVar4);
    FUN_007dc400(iVar4,uVar2,uVar3);
    FUN_007dc140(iVar4,0xb,1,0);
    return;
  case 0x44:
  case 0x45:
    FUN_007ec010(param_1,*(undefined4 *)(param_2 + 8));
    FUN_007dc140(iVar4,uVar1,1,param_3);
    return;
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4b:
    FUN_007ec010(param_1,*(undefined4 *)(param_2 + 8));
    FUN_007ec010(param_1,*(undefined4 *)(param_2 + 0xc));
    FUN_007ea370(*(undefined4 *)(param_2 + 0xc),uVar1,param_3);
    return;
  }
  FUN_007ec830(param_1,*(undefined4 *)(param_2 + 8),param_3,param_4);
  iVar4 = *(int *)(param_1 + 0xc);
  param_2 = *(undefined1 **)(param_2 + 0xc);
  if (iVar4 == 0) {
    return;
  }
  goto LAB_007ec847;
}


// ==== FUN_007eca30 @ 0x007eca30 ====

void FUN_007eca30(int param_1,byte *param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  
  iVar3 = *(int *)(param_1 + 0xc);
  if (iVar3 == 0) {
    return;
  }
LAB_007eca47:
  if (param_2 == (byte *)0x0) {
    return;
  }
  bVar4 = *param_2 ^ 1;
  switch(*param_2) {
  case 0x3e:
    uVar1 = FUN_007dc190(iVar3);
    FUN_007ec830(param_1,*(undefined4 *)(param_2 + 8),uVar1,param_4 == 0);
    FUN_007eca30(param_1,*(undefined4 *)(param_2 + 0xc),param_3,param_4);
    FUN_007dc1e0(iVar3,uVar1);
    return;
  case 0x3f:
    break;
  case 0x40:
    FUN_007ec830(param_1,*(undefined4 *)(param_2 + 8),param_3,param_4);
    return;
  default:
    FUN_007ec010(param_1,param_2);
    FUN_007dc140(iVar3,0x4c,param_4,param_3);
    return;
  case 0x42:
    uVar1 = **(undefined4 **)(*(int *)(param_2 + 0x10) + 8);
    FUN_007ec010(param_1,*(undefined4 *)(param_2 + 8));
    FUN_007dc140(iVar3,0x60,0,0);
    FUN_007ec010(param_1,uVar1);
    iVar2 = FUN_007dc320(iVar3);
    FUN_007ea370(uVar1,0x4b,iVar2 + 3);
    FUN_007dc140(iVar3,0xb,1,0);
    FUN_007dc140(iVar3,0x61,0,param_3);
    uVar1 = *(undefined4 *)(*(int *)(*(int *)(param_2 + 0x10) + 8) + 0xc);
    FUN_007ec010(param_1,uVar1);
    FUN_007ea370(uVar1,0x48,param_3);
    return;
  case 0x44:
  case 0x45:
    FUN_007ec010(param_1,*(undefined4 *)(param_2 + 8));
    FUN_007dc140(iVar3,bVar4,1,param_3);
    return;
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4b:
    FUN_007ec010(param_1,*(undefined4 *)(param_2 + 8));
    FUN_007ec010(param_1,*(undefined4 *)(param_2 + 0xc));
    FUN_007ea370(*(undefined4 *)(param_2 + 0xc),bVar4,param_3);
    return;
  }
  FUN_007eca30(param_1,*(undefined4 *)(param_2 + 8),param_3,param_4);
  iVar3 = *(int *)(param_1 + 0xc);
  param_2 = *(byte **)(param_2 + 0xc);
  if (iVar3 == 0) {
    return;
  }
  goto LAB_007eca47;
}


// ==== FUN_007ecc30 @ 0x007ecc30 ====

int FUN_007ecc30(undefined4 *param_1,short *param_2)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  
  iVar2 = 0;
  iVar1 = 0;
  psVar3 = param_2 + 2;
  if (0 < *param_2) {
    do {
      iVar1 = FUN_007d2330(param_1,*(undefined4 *)(psVar3 + 2),*(undefined4 *)psVar3);
      FUN_007d25e0(*param_1,*(undefined4 *)(psVar3 + 6));
      *(int *)(psVar3 + 6) = iVar1;
      if (iVar1 != 0) {
        *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + 1;
      }
      iVar2 = iVar2 + 1;
      psVar3 = psVar3 + 0x14;
    } while (iVar2 < *param_2);
  }
  return iVar1;
}


// ==== FUN_007ecc90 @ 0x007ecc90 ====

undefined4 FUN_007ecc90(int *param_1,undefined4 *param_2,int param_3)

{
  if (((*(char *)(param_2 + 7) != '\0') && ((*(uint *)(*param_1 + 8) & 0x800) == 0)) &&
     (*(char *)((int)param_1 + 0x13) == '\0')) {
    FUN_007d0820(param_1,s_table__s_may_not_be_modified_00a01e18,*param_2);
    return 1;
  }
  if ((param_3 == 0) && (param_2[6] != 0)) {
    FUN_007d0820(param_1,s_cannot_modify__s_because_it_is_a_00a01df0,*param_2);
    return 1;
  }
  return 0;
}


// ==== FUN_007ecd00 @ 0x007ecd00 ====

void FUN_007ecd00(undefined4 param_1,undefined4 param_2,int param_3)

{
  FUN_007dc140(param_1,0x32,*(undefined1 *)(param_3 + 0x1d),0);
  FUN_007dc140(param_1,0xe,param_2,*(undefined4 *)(param_3 + 0x14));
  FUN_007dc140(param_1,0x67,param_2,*(undefined4 *)(param_3 + 4));
  return;
}


// ==== FUN_007ecd40 @ 0x007ecd40 ====

void FUN_007ecd40(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_2 + 0xc);
  FUN_007dc140(param_1,0x26,param_3,0);
  iVar3 = 0;
  if (0 < *(int *)(param_2 + 4)) {
    do {
      iVar2 = *(int *)(*(int *)(param_2 + 8) + iVar3 * 4);
      if (iVar2 == *(int *)(iVar1 + 0xc)) {
        FUN_007dc140(param_1,0x60,iVar3,0);
      }
      else {
        FUN_007dc140(param_1,2,param_3,iVar2);
        FUN_007f8be0(param_1,iVar1,iVar2);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_2 + 4));
  }
  FUN_007dc140(param_1,0x5b,*(undefined4 *)(param_2 + 4),0x1000000);
  FUN_007f97c0(param_1,param_2);
  return;
}


// ==== FUN_007ecde0 @ 0x007ecde0 ====

void FUN_007ecde0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_3 + 0x10);
  iVar2 = 1;
  if (iVar1 != 0) {
    do {
      if ((param_5 == 0) || (*(char *)(iVar2 + -1 + param_5) != '\0')) {
        FUN_007ecd40(param_2,iVar1,param_4);
        FUN_007dc140(param_2,0x41,iVar2 + param_4,0);
      }
      iVar1 = *(int *)(iVar1 + 0x1c);
      iVar2 = iVar2 + 1;
    } while (iVar1 != 0);
  }
  return;
}


// ==== FUN_007ece40 @ 0x007ece40 ====

void FUN_007ece40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_007dc140(param_2,0x2d,param_4,0);
  FUN_007ecde0(param_1,param_2,param_3,param_4,0);
  FUN_007dc140(param_2,0x5c,param_4,param_5 != 0);
  uVar2 = FUN_007dc320(param_2);
  FUN_007dc400(param_2,uVar1,uVar2);
  return;
}


// ==== FUN_007ecea0 @ 0x007ecea0 ====

void FUN_007ecea0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  int local_3c;
  undefined4 local_38;
  undefined1 local_28 [4];
  undefined4 local_24;
  int *local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar2 = param_1;
  local_38 = 0;
  local_3c = -1;
  local_24 = 0;
  if ((param_1[6] == 0) && (DAT_00b5c4c4 == 0)) {
    iVar1 = *param_1;
    puVar3 = (undefined4 *)FUN_007ecc30(param_1,param_2);
    if (puVar3 != (undefined4 *)0x0) {
      iVar4 = FUN_007edb60(param_1,puVar3,0x66,0);
      bVar11 = puVar3[6] != 0;
      iVar5 = FUN_007ecc90(param_1,puVar3,iVar4);
      if (((iVar5 == 0) &&
          (iVar5 = FUN_007ed5e0(param_1,9,*puVar3,0,
                                *(undefined4 *)
                                 ((uint)*(byte *)((int)puVar3 + 0x1d) * 0x70 + *(int *)(iVar1 + 4)))
          , iVar5 == 0)) && ((!bVar11 || (iVar5 = FUN_007d45e0(param_1,puVar3), iVar5 == 0)))) {
        if (iVar4 != 0) {
          local_3c = param_1[7];
          param_1[7] = local_3c + 1;
        }
        iVar5 = param_1[7];
        *(int *)(param_2 + 0x1c) = iVar5;
        param_1[7] = param_1[7] + 1;
        local_18 = 0;
        local_14 = 0;
        local_10 = 0;
        local_1c = param_2;
        local_c = 0;
        local_8 = 0;
        local_4 = 0;
        local_20 = param_1;
        iVar6 = FUN_007ebc80(&local_20,param_3);
        if (iVar6 == 0) {
          if (bVar11) {
            FUN_007ed660(param_1,local_28,*puVar3);
          }
          iVar6 = FUN_007e8190(param_1);
          if (iVar6 != 0) {
            if (*(char *)((int)param_1 + 0x13) == '\0') {
              FUN_007dda40(iVar6);
            }
            FUN_007d3d30(param_1,iVar4,*(undefined1 *)((int)puVar3 + 0x1d));
            if (bVar11) {
              uVar7 = FUN_007ead10(puVar3[6]);
              FUN_007e9760(param_1,uVar7,8,iVar5,0,0,0,0);
              FUN_007e6af0(uVar7);
            }
            if (*(char *)(iVar1 + 8) < '\0') {
              FUN_007dc140(iVar6,0x32,0,0);
            }
            if ((param_3 == 0) && (iVar4 == 0)) {
              if (*(char *)(iVar1 + 8) < '\0') {
                uVar7 = FUN_007dc190(iVar6);
                if (!bVar11) {
                  FUN_007ecd00(iVar6,iVar5,puVar3);
                }
                iVar4 = FUN_007dc320(iVar6);
                FUN_007dc140(iVar6,0x79,iVar5,iVar4 + 2);
                uVar8 = FUN_007dc140(iVar6,0x28,1,0);
                FUN_007dc140(iVar6,0x6c,iVar5,uVar8);
                FUN_007dc1e0(iVar6,uVar7);
                FUN_007dc140(iVar6,0x1e,iVar5,0);
              }
              if (!bVar11) {
                FUN_007dc140(iVar6,0x62,puVar3[5],*(undefined1 *)((int)puVar3 + 0x1d));
                for (iVar4 = puVar3[4]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x1c)) {
                  FUN_007dc140(iVar6,0x62,*(undefined4 *)(iVar4 + 0x10),
                               *(undefined1 *)(iVar4 + 0x16));
                }
              }
            }
            else {
              for (iVar10 = puVar3[4]; iVar10 != 0; iVar10 = *(int *)(iVar10 + 0x1c)) {
                iVar9 = FUN_007d2c00(param_1,iVar10);
                if (iVar9 != 0) goto LAB_007ed446;
              }
              iVar10 = FUN_007f7600(param_1,param_2,param_3,0);
              if (iVar10 == 0) goto LAB_007ed446;
              FUN_007dc140(iVar6,0x26,iVar5,0);
              FUN_007dc140(iVar6,0x1f,0,0);
              if (*(char *)(iVar1 + 8) < '\0') {
                FUN_007dc140(iVar6,0x28,1,0);
              }
              FUN_007f71d0(iVar10);
              if (iVar4 != 0) {
                FUN_007dc140(iVar6,0x75,local_3c,0);
                FUN_007dc140(iVar6,0x67,local_3c,puVar3[1]);
              }
              FUN_007dc140(iVar6,0x13,0,0);
              uVar7 = FUN_007dc190(iVar6);
              if (iVar4 != 0) {
                local_38 = FUN_007dc140(iVar6,0x5e,0,uVar7);
                if (!bVar11) {
                  FUN_007dc140(iVar6,0x60,0,0);
                  FUN_007ecd00(iVar6,iVar5,puVar3);
                }
                FUN_007dc140(iVar6,0x7a,iVar5,0);
                FUN_007dc140(iVar6,0x26,iVar5,0);
                FUN_007dc140(iVar6,0x2a,iVar5,0);
                FUN_007dc140(iVar6,0x71,local_3c,0);
                if (!bVar11) {
                  FUN_007dc140(iVar6,0x1e,iVar5,0);
                }
                if (param_1[0x28] == 0) {
                  uVar8 = 99;
                }
                else {
                  uVar8 = *(undefined4 *)(param_1[0x28] + 0xc);
                }
                FUN_007ede00(param_1,0x66,0,1,puVar3,0xffffffff,local_3c,uVar8,local_38);
              }
              if (!bVar11) {
                FUN_007fa110(param_1,puVar3,iVar5,9);
                if (iVar4 == 0) {
                  local_38 = FUN_007dc140(iVar6,0x5e,0,uVar7);
                }
                FUN_007ece40(iVar1,iVar6,puVar3,iVar5,*(char *)((int)param_1 + 0x13) == '\0');
              }
              if (iVar4 != 0) {
                if (!bVar11) {
                  iVar10 = puVar3[4];
                  if (iVar10 != 0) {
                    param_1 = (int *)iVar5;
                    do {
                      param_1 = (int *)((int)param_1 + 1);
                      FUN_007dc140(iVar6,0x1e,param_1,*(undefined4 *)(iVar10 + 0x10));
                      iVar10 = *(int *)(iVar10 + 0x1c);
                    } while (iVar10 != 0);
                  }
                  FUN_007dc140(iVar6,0x1e,iVar5,0);
                }
                if (piVar2[0x28] == 0) {
                  uVar8 = 99;
                }
                else {
                  uVar8 = *(undefined4 *)(piVar2[0x28] + 0xc);
                }
                FUN_007ede00(piVar2,0x66,0,2,puVar3,0xffffffff,local_3c,uVar8,local_38);
              }
              FUN_007dc140(iVar6,0x61,0,local_38);
              FUN_007dc1e0(iVar6,uVar7);
              FUN_007dc140(iVar6,0x5f,0,0);
              if (iVar4 == 0) {
                iVar10 = iVar5;
                for (iVar4 = puVar3[4]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x1c)) {
                  iVar10 = iVar10 + 1;
                  FUN_007dc140(iVar6,0x1e,iVar10,*(undefined4 *)(iVar4 + 0x10));
                }
                FUN_007dc140(iVar6,0x1e,iVar5,0);
              }
            }
            if (((*(char *)(iVar1 + 8) < '\0') && (*(char *)((int)piVar2 + 0x13) == '\0')) &&
               (piVar2[0x28] == 0)) {
              FUN_007dc140(iVar6,0x39,1,0);
              FUN_007dccf0(iVar6,1);
              FUN_007dcd30(iVar6,0,s_rows_deleted_00a01e38,0xfffffffe);
            }
          }
        }
      }
    }
  }
LAB_007ed446:
  FUN_007ed690(local_28);
  FUN_007d3a10(param_2);
  FUN_007eabc0(param_3);
  return;
}


// ==== FUN_007ed470 @ 0x007ed470 ====

void FUN_007ed470(void)

{
  int unaff_ESI;
  
  FUN_007d0820();
  *(undefined4 *)(unaff_ESI + 4) = 1;
  return;
}


// ==== FUN_007ed490 @ 0x007ed490 ====

void FUN_007ed490(int *param_1,undefined1 *param_2,short *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  char *pcVar6;
  
  piVar1 = (int *)*param_1;
  if (piVar1[0x1f] == 0) {
    return;
  }
  iVar3 = 0;
  if (param_3 != (short *)0x0) {
    for (piVar4 = (int *)(param_3 + 0xe);
        (iVar3 < *param_3 && (*(int *)(param_2 + 0x24) != *piVar4)); piVar4 = piVar4 + 10) {
      iVar3 = iVar3 + 1;
    }
    if ((-1 < iVar3) && (iVar3 < *param_3)) {
      puVar5 = *(undefined4 **)(param_3 + iVar3 * 0x14 + 8);
      goto LAB_007ed4f6;
    }
  }
  if ((undefined4 *)param_1[0x28] == (undefined4 *)0x0) {
    return;
  }
  puVar5 = *(undefined4 **)param_1[0x28];
LAB_007ed4f6:
  if (puVar5 != (undefined4 *)0x0) {
    if (*(int *)(param_2 + 0x28) < 0) {
      if ((int)puVar5[3] < 0) {
        pcVar6 = s_ROWID_00a01cb8;
      }
      else {
        pcVar6 = *(char **)(puVar5[2] + puVar5[3] * 0x14);
      }
    }
    else {
      pcVar6 = *(char **)(puVar5[2] + *(int *)(param_2 + 0x28) * 0x14);
    }
    uVar2 = *(undefined4 *)((uint)(byte)param_2[2] * 0x70 + piVar1[1]);
    iVar3 = (*(code *)piVar1[0x1f])(piVar1[0x20],0x14,*puVar5,pcVar6,uVar2,param_1[0x29]);
    if (iVar3 == 2) {
      *param_2 = 0x5e;
      return;
    }
    if (iVar3 == 1) {
      if ((*piVar1 < 3) && (param_2[2] == '\0')) {
        FUN_007d0820(param_1,s_access_to__s__s_is_prohibited_00a01edc,*puVar5,pcVar6);
        param_1[1] = 0x17;
        return;
      }
      FUN_007d0820(param_1,s_access_to__s__s__s_is_prohibited_00a01eb8,uVar2,*puVar5,pcVar6);
      param_1[1] = 0x17;
      return;
    }
    if (iVar3 != 0) {
      FUN_007d0820(param_1,s_illegal_return_value___d__from_t_00a01e48,iVar3);
      param_1[1] = 1;
    }
  }
  return;
}


// ==== FUN_007ed5e0 @ 0x007ed5e0 ====

int FUN_007ed5e0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((*(char *)(iVar1 + 0x44) != '\0') || (*(code **)(iVar1 + 0x7c) == (code *)0x0)) {
    return 0;
  }
  iVar1 = (**(code **)(iVar1 + 0x7c))
                    (*(undefined4 *)(iVar1 + 0x80),param_2,param_3,param_4,param_5,param_1[0x29]);
  if (iVar1 == 1) {
    FUN_007d0820(param_1,s_not_authorized_00a01efc);
    param_1[1] = 0x17;
    return 1;
  }
  if ((iVar1 != 0) && (iVar1 != 2)) {
    iVar1 = 1;
    FUN_007ed470();
  }
  return iVar1;
}


// ==== FUN_007ed660 @ 0x007ed660 ====

void FUN_007ed660(int param_1,undefined4 *param_2,undefined4 param_3)

{
  param_2[1] = param_1;
  if (param_1 != 0) {
    *param_2 = *(undefined4 *)(param_1 + 0xa4);
    *(undefined4 *)(param_1 + 0xa4) = param_3;
  }
  return;
}


// ==== FUN_007ed690 @ 0x007ed690 ====

void FUN_007ed690(undefined4 *param_1)

{
  if (param_1[1] != 0) {
    *(undefined4 *)(param_1[1] + 0xa4) = *param_1;
    param_1[1] = 0;
  }
  return;
}


// ==== FUN_007ed6b0 @ 0x007ed6b0 ====

void FUN_007ed6b0(int param_1)

{
  int iVar1;
  
  while (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x24);
    if ((*(byte *)(param_1 + 0x14) & 1) != 0) {
      FUN_007d05b0(*(undefined4 *)(param_1 + 0x10));
    }
    FUN_007eabc0(*(undefined4 *)(param_1 + 0x18));
    FUN_007ea740(*(undefined4 *)(param_1 + 0x1c));
    FUN_007e6af0(*(undefined4 *)(param_1 + 0xc));
    FUN_007d3980(*(undefined4 *)(param_1 + 0x20));
    FUN_007d05b0(param_1);
    param_1 = iVar1;
  }
  return;
}


// ==== FUN_007ed710 @ 0x007ed710 ====

void FUN_007ed710(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x10) != 0) {
    uVar1 = FUN_007d06a0(*(int *)(unaff_ESI + 0x10),*(uint *)(unaff_ESI + 0x14) >> 1);
    *(undefined4 *)(unaff_ESI + 0x10) = uVar1;
    *(uint *)(unaff_ESI + 0x14) = *(uint *)(unaff_ESI + 0x14) | 1;
  }
  if (*(int *)(unaff_ESI + 0xc) != 0) {
    uVar1 = FUN_007ead10(*(int *)(unaff_ESI + 0xc));
    FUN_007e6af0(*(undefined4 *)(unaff_ESI + 0xc));
    *(undefined4 *)(unaff_ESI + 0xc) = uVar1;
  }
  if (*(int *)(unaff_ESI + 0x18) != 0) {
    uVar1 = FUN_007eb2d0(*(int *)(unaff_ESI + 0x18));
    FUN_007eabc0(*(undefined4 *)(unaff_ESI + 0x18));
    *(undefined4 *)(unaff_ESI + 0x18) = uVar1;
  }
  if (*(int *)(unaff_ESI + 0x1c) != 0) {
    uVar1 = FUN_007ea5c0(*(int *)(unaff_ESI + 0x1c));
    FUN_007ea740(*(undefined4 *)(unaff_ESI + 0x1c));
    *(undefined4 *)(unaff_ESI + 0x1c) = uVar1;
  }
  if (*(int *)(unaff_ESI + 0x20) != 0) {
    uVar1 = FUN_007ea6a0(*(int *)(unaff_ESI + 0x20));
    FUN_007d3980(*(undefined4 *)(unaff_ESI + 0x20));
    *(undefined4 *)(unaff_ESI + 0x20) = uVar1;
  }
  return;
}


// ==== FUN_007ed7b0 @ 0x007ed7b0 ====

undefined4 * FUN_007ed7b0(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_007d0550(0x28);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = 0x71;
  puVar1[3] = param_1;
  puVar1[1] = 99;
  FUN_007ed710();
  return puVar1;
}


// ==== FUN_007ed7e0 @ 0x007ed7e0 ====

undefined4 *
FUN_007ed7e0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_007d0550(0x28);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_007d3980(param_2);
    FUN_007ea740(param_3);
    FUN_007ead10(param_4);
    return (undefined4 *)0x0;
  }
  puVar1[3] = param_4;
  *puVar1 = 0x68;
  puVar1[4] = *param_1;
  puVar1[5] = param_1[1];
  puVar1[8] = param_2;
  puVar1[7] = param_3;
  puVar1[1] = param_5;
  FUN_007ed710();
  return puVar1;
}


// ==== FUN_007ed850 @ 0x007ed850 ====

undefined4 *
FUN_007ed850(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_007d0550(0x28);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = 0x67;
  puVar1[4] = *param_1;
  puVar1[5] = param_1[1];
  puVar1[7] = param_2;
  puVar1[6] = param_3;
  puVar1[1] = param_4;
  FUN_007ed710();
  return puVar1;
}


// ==== FUN_007ed8a0 @ 0x007ed8a0 ====

undefined4 * FUN_007ed8a0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_007d0550(0x28);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = 0x66;
  puVar1[4] = *param_1;
  puVar1[5] = param_1[1];
  puVar1[6] = param_2;
  puVar1[1] = 99;
  FUN_007ed710();
  return puVar1;
}


// ==== FUN_007ed8e0 @ 0x007ed8e0 ====

void FUN_007ed8e0(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_007ed6b0(param_1[8]);
    FUN_007d05b0(*param_1);
    FUN_007d05b0(param_1[1]);
    FUN_007eabc0(param_1[3]);
    FUN_007d3980(param_1[4]);
    if ((*(byte *)(param_1 + 7) & 1) != 0) {
      FUN_007d05b0(param_1[6]);
    }
    FUN_007d05b0(param_1);
  }
  return;
}


// ==== FUN_007ed940 @ 0x007ed940 ====

void FUN_007ed940(int *param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  
  puVar3 = (undefined4 *)param_2;
  iVar1 = *param_1;
  uVar8 = (uint)*(byte *)((int)param_2 + 8);
  puVar4 = (undefined4 *)
           FUN_007d22b0(iVar1,*(undefined4 *)((int)param_2 + 4),
                        *(undefined4 *)
                         ((uint)*(byte *)((int)param_2 + 9) * 0x70 + *(int *)(iVar1 + 4)));
  uVar2 = *(undefined4 *)(uVar8 * 0x70 + *(int *)(iVar1 + 4));
  uVar7 = 0x10;
  if (uVar8 == 1) {
    param_2 = s_sqlite_temp_master_009fff68;
    uVar7 = 0xe;
  }
  else {
    param_2 = s_sqlite_master_009fff58;
  }
  iVar5 = FUN_007ed5e0(param_1,uVar7,*puVar3,*puVar4,uVar2);
  if (iVar5 == 0) {
    iVar5 = FUN_007ed5e0(param_1,9,param_2,0,uVar2);
    if (iVar5 == 0) {
      iVar5 = FUN_007e8190(param_1);
      if (iVar5 != 0) {
        FUN_007d3d30(param_1,0,uVar8);
        FUN_007d2760(iVar5,uVar8);
        iVar6 = FUN_007dc330(iVar5,9,&DAT_00a01f60);
        FUN_007dc430(iVar5,iVar6 + 1,*puVar3,0);
        FUN_007d2ce0(iVar1,iVar5,uVar8);
        FUN_007dc140(iVar5,0x1e,0,0);
        FUN_007dda80(iVar5,0x3b,uVar8,0,*puVar3,0);
      }
    }
  }
  return;
}


// ==== FUN_007eda60 @ 0x007eda60 ====

void FUN_007eda60(int param_1,int param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
  pcVar3 = param_3;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  iVar4 = FUN_007d1f20(param_2 * 0x70 + 0x34 + *(int *)(param_1 + 4),param_3,
                       pcVar3 + (1 - (int)(param_3 + 1)),0);
  if (iVar4 != 0) {
    iVar5 = FUN_007d22b0(param_1,*(undefined4 *)(iVar4 + 4),
                         *(undefined4 *)((uint)*(byte *)(iVar4 + 9) * 0x70 + *(int *)(param_1 + 4)))
    ;
    iVar2 = *(int *)(iVar5 + 0x28);
    if (*(int *)(iVar5 + 0x28) == iVar4) {
      *(undefined4 *)(iVar5 + 0x28) = *(undefined4 *)(iVar4 + 0x24);
    }
    else {
      do {
        iVar5 = iVar2;
        if (iVar5 == 0) goto LAB_007edae8;
        iVar2 = *(int *)(iVar5 + 0x24);
      } while (*(int *)(iVar5 + 0x24) != iVar4);
      *(undefined4 *)(iVar5 + 0x24) = *(undefined4 *)(*(int *)(iVar5 + 0x24) + 0x24);
    }
LAB_007edae8:
    FUN_007ed8e0(iVar4);
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x10;
  }
  return;
}


// ==== FUN_007edb00 @ 0x007edb00 ====

undefined4 FUN_007edb00(int param_1)

{
  int iVar1;
  int iVar2;
  int *unaff_ESI;
  int iVar3;
  
  if ((param_1 == 0) || (unaff_ESI == (int *)0x0)) {
    return 1;
  }
  iVar2 = 0;
  if (0 < *unaff_ESI) {
    iVar3 = 0;
    do {
      iVar1 = FUN_007d39c0(param_1,*(undefined4 *)(unaff_ESI[2] + 4 + iVar3));
      if (-1 < iVar1) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xc;
    } while (iVar2 < *unaff_ESI);
  }
  return 0;
}


// ==== FUN_007edb60 @ 0x007edb60 ====

byte FUN_007edb60(int param_1,int param_2,uint param_3)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 0x28);
  bVar2 = 0;
  if (iVar3 != 0) {
    do {
      if ((*(byte *)(iVar3 + 10) == param_3) &&
         (iVar1 = FUN_007edb00(*(undefined4 *)(iVar3 + 0x10)), iVar1 != 0)) {
        iVar1 = *(int *)(param_1 + 0xa0);
        if (iVar1 != 0) {
          do {
            if (*(int *)(iVar1 + 0x14) == *(int *)(param_2 + 0x28)) goto LAB_007edbc2;
            iVar1 = *(int *)(iVar1 + 0x18);
          } while (iVar1 != 0);
        }
        bVar2 = bVar2 | *(byte *)(iVar3 + 0xb);
      }
LAB_007edbc2:
      iVar3 = *(int *)(iVar3 + 0x24);
    } while (iVar3 != 0);
  }
  return bVar2;
}


// ==== FUN_007edbd0 @ 0x007edbd0 ====

void FUN_007edbd0(int *param_1)

{
  char cVar1;
  int in_EAX;
  uint uVar2;
  char *pcVar3;
  char *local_8;
  uint local_4;
  
  uVar2 = (uint)*(byte *)(*(int *)(in_EAX + 8) + 8);
  if ((uVar2 != 0) && (uVar2 < 2)) {
    FUN_007d5320(0,in_EAX + 0x10,0);
    return;
  }
  local_8 = *(char **)(uVar2 * 0x70 + *(int *)(*param_1 + 4));
  pcVar3 = local_8;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_4 = ((int)pcVar3 - (int)(local_8 + 1)) * 2 | local_4 & 1;
  FUN_007d5320(0,&local_8,in_EAX + 0x10);
  return;
}


// ==== FUN_007edc50 @ 0x007edc50 ====

undefined4 FUN_007edc50(int param_1)

{
  undefined4 uVar1;
  undefined4 *in_EAX;
  undefined4 uVar2;
  int iVar3;
  int unaff_EDI;
  
  uVar1 = *(undefined4 *)(unaff_EDI + 0xc);
  FUN_007dc140(uVar1,0x3a,0,0);
  for (; in_EAX != (undefined4 *)0x0; in_EAX = (undefined4 *)in_EAX[9]) {
    iVar3 = param_1;
    if (param_1 == 99) {
      iVar3 = in_EAX[1];
    }
    *(int *)(*(int *)(unaff_EDI + 0xa0) + 0xc) = iVar3;
    switch(*in_EAX) {
    case 0x66:
      FUN_007dc140(uVar1,0x38,0,0);
      FUN_007edbd0();
      FUN_007eb2d0(in_EAX[6]);
      FUN_007ecea0();
      FUN_007dc140(uVar1,0x38,1,0);
      break;
    case 0x67:
      FUN_007edbd0();
      FUN_007dc140(uVar1,0x38,0,0);
      uVar2 = FUN_007eb2d0(in_EAX[6],iVar3);
      FUN_007ea5c0(in_EAX[7],uVar2);
      FUN_007f8c40();
      FUN_007dc140(uVar1,0x38,1,0);
      break;
    case 0x68:
      FUN_007edbd0();
      FUN_007dc140(uVar1,0x38,0,0);
      uVar2 = FUN_007ea6a0(in_EAX[8],iVar3);
      uVar2 = FUN_007ead10(in_EAX[3],uVar2);
      FUN_007ea5c0(in_EAX[7],uVar2);
      FUN_007fa1b0();
      FUN_007dc140(uVar1,0x38,1,0);
      break;
    case 0x71:
      uVar2 = FUN_007ead10(in_EAX[3]);
      FUN_007e9090();
      FUN_007e9760();
      FUN_007e6af0(uVar2);
    }
  }
  FUN_007dc140(uVar1,0x6b,0,0);
  return 0;
}


// ==== FUN_007ede00 @ 0x007ede00 ====

undefined4
FUN_007ede00(int param_1,uint param_2,undefined4 param_3,uint param_4,int param_5,undefined4 param_6
            ,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined1 local_44 [8];
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_24;
  int local_20 [8];
  
  puVar5 = *(undefined4 **)(param_5 + 0x28);
  if (puVar5 != (undefined4 *)0x0) {
    do {
      if ((*(byte *)((int)puVar5 + 10) == param_2) && (*(byte *)((int)puVar5 + 0xb) == param_4)) {
        bVar1 = true;
        for (iVar2 = *(int *)(param_1 + 0xa0); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x18)) {
          if (*(undefined4 **)(iVar2 + 0x14) == puVar5) {
            bVar1 = false;
          }
        }
        if ((((param_2 != 0x67) || (puVar5[4] == 0)) ||
            (iVar2 = FUN_007edb00(puVar5[4]), iVar2 != 0)) && (bVar1)) {
          local_20[1] = 0;
          local_20[2] = 0;
          local_20[3] = 0;
          local_20[4] = 0;
          local_20[5] = 0;
          local_20[6] = 0;
          local_20[7] = 0;
          local_34 = param_7;
          local_38 = param_6;
          local_24 = *(undefined4 *)(param_1 + 0xa0);
          local_3c = param_5;
          local_2c = param_9;
          *(int **)(param_1 + 0xa0) = &local_3c;
          local_20[0] = param_1;
          local_28 = puVar5;
          FUN_007ed660(param_1,local_44,*puVar5);
          uVar3 = FUN_007dc190(*(undefined4 *)(param_1 + 0xc));
          uVar4 = FUN_007eb2d0(puVar5[3]);
          iVar2 = FUN_007ebc80(local_20,uVar4);
          if (iVar2 != 0) {
            *(undefined4 *)(param_1 + 0xa0) = local_24;
            FUN_007eabc0(uVar4);
            return 1;
          }
          FUN_007eca30(param_1,uVar4,uVar3,1);
          FUN_007eabc0(uVar4);
          FUN_007edc50(param_8);
          *(undefined4 *)(param_1 + 0xa0) = local_24;
          FUN_007ed690(local_44);
          FUN_007dc1e0(*(undefined4 *)(param_1 + 0xc),uVar3);
        }
      }
      puVar5 = (undefined4 *)puVar5[9];
    } while (puVar5 != (undefined4 *)0x0);
  }
  return 0;
}


// ==== FUN_007edfa0 @ 0x007edfa0 ====

void FUN_007edfa0(int *param_1,int *param_2,int param_3,int param_4,undefined1 param_5,
                 undefined4 param_6,int param_7,int param_8,undefined4 param_9,int param_10)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int *piVar11;
  int local_1c;
  undefined1 local_10 [16];
  
  iVar4 = param_3;
  piVar2 = param_1;
  iVar8 = *param_1;
  piVar11 = (int *)0x0;
  iVar10 = 0;
  if (param_10 == 0) {
    local_1c = FUN_007d2850(param_1,param_2,param_3,&param_1);
    if (local_1c < 0) goto LAB_007ee2bd;
  }
  else {
    if ((param_3 != 0) && ((*(uint *)(param_3 + 4) & 0xfffffffe) != 0)) {
      FUN_007d0820(param_1,s_temporary_trigger_may_not_have_q_00a0206c);
      goto LAB_007ee2bd;
    }
    local_1c = 1;
    param_1 = param_2;
  }
  if ((param_7 == 0) || (DAT_00b5c4c4 != 0)) goto LAB_007ee2bd;
  iVar3 = FUN_007ecc30(piVar2,param_7);
  if (((*(uint *)(iVar4 + 4) & 0xfffffffe) == 0) &&
     ((iVar3 != 0 && (*(char *)(iVar3 + 0x1d) == '\x01')))) {
    local_1c = 1;
  }
  if ((DAT_00b5c4c4 != 0) ||
     ((((iVar4 = FUN_007ee9a0(local_10,piVar2,local_1c,s_trigger_00a01740,param_1), iVar4 != 0 &&
        (iVar4 = FUN_007eea70(local_10,param_7), iVar4 != 0)) ||
       (puVar5 = (undefined4 *)FUN_007ecc30(piVar2,param_7), puVar5 == (undefined4 *)0x0)) ||
      ((iVar10 = FUN_007d2730(param_1), iVar10 == 0 ||
       (iVar4 = FUN_007d28b0(piVar2,iVar10), iVar4 != 0)))))) goto LAB_007ee2bd;
  iVar4 = FUN_007d1ed0(local_1c * 0x70 + 0x34 + *(int *)(iVar8 + 4),iVar10,
                       ((uint)param_1[1] >> 1) + 1);
  if (iVar4 != 0) {
    FUN_007d0820(piVar2,s_trigger__T_already_exists_00a02050,param_1);
    goto LAB_007ee2bd;
  }
  iVar4 = FUN_007d0930(*puVar5,s_sqlite__00a001a8,7);
  if (iVar4 == 0) {
    FUN_007d0820(piVar2,s_cannot_create_trigger_on_system_t_00a02028);
    piVar2[6] = piVar2[6] + 1;
    goto LAB_007ee2bd;
  }
  if (puVar5[6] == 0) {
LAB_007ee190:
    if (param_4 == 0x2b) {
      FUN_007d0820(piVar2,s_cannot_create_INSTEAD_OF_trigger_00a01fc0,param_7,0);
      goto LAB_007ee2bd;
    }
  }
  else {
    if (param_4 != 0x2b) {
      pcVar6 = s_BEFORE_00a02020;
      if (param_4 != 0x20) {
        pcVar6 = s_AFTER_00a02018;
      }
      FUN_007d0820(piVar2,s_cannot_create__s_trigger_on_view_00a01ff0,pcVar6,param_7,0);
      goto LAB_007ee2bd;
    }
    if (puVar5[6] == 0) goto LAB_007ee190;
  }
  iVar8 = *(int *)(iVar8 + 4);
  uVar1 = *(undefined4 *)((uint)*(byte *)((int)puVar5 + 0x1d) * 0x70 + iVar8);
  uVar9 = 7;
  if (param_10 == 0) {
    uVar7 = uVar1;
  }
  else {
    uVar7 = *(undefined4 *)(iVar8 + 0x70);
  }
  if ((*(byte *)((int)puVar5 + 0x1d) == 1) || (param_10 != 0)) {
    uVar9 = 5;
  }
  iVar8 = FUN_007ed5e0(piVar2,uVar9,iVar10,*puVar5,uVar7);
  if (iVar8 == 0) {
    pcVar6 = s_sqlite_temp_master_009fff68;
    if (*(char *)((int)puVar5 + 0x1d) != '\x01') {
      pcVar6 = s_sqlite_master_009fff58;
    }
    iVar8 = FUN_007ed5e0(piVar2,0x12,pcVar6,0,uVar1);
    if (iVar8 == 0) {
      if (param_4 == 0x2b) {
        param_4 = 0x20;
      }
      piVar11 = (int *)FUN_007d0550(0x28);
      if (piVar11 != (int *)0x0) {
        *piVar11 = iVar10;
        iVar10 = 0;
        iVar8 = FUN_007d0640(*(undefined4 *)(param_7 + 8));
        piVar11[1] = iVar8;
        *(undefined1 *)(piVar11 + 2) = (undefined1)local_1c;
        *(undefined1 *)((int)piVar11 + 9) = *(undefined1 *)((int)puVar5 + 0x1d);
        *(undefined1 *)((int)piVar11 + 10) = param_5;
        *(char *)((int)piVar11 + 0xb) = (param_4 != 0x20) + '\x01';
        iVar8 = FUN_007eb2d0(param_9);
        piVar11[3] = iVar8;
        iVar8 = FUN_007ea6a0(param_6);
        piVar11[4] = iVar8;
        piVar11[5] = param_8;
        FUN_007ea560(piVar11 + 6,param_1);
        piVar2[0x27] = (int)piVar11;
      }
    }
  }
LAB_007ee2bd:
  FUN_007d05b0(iVar10);
  FUN_007d3a10(param_7);
  FUN_007d3980(param_6);
  FUN_007eabc0(param_9);
  if (piVar2[0x27] == 0) {
    FUN_007ed8e0(piVar11);
  }
  return;
}


// ==== FUN_007ee300 @ 0x007ee300 ====

void FUN_007ee300(int *param_1,int param_2,undefined4 *param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined1 local_10 [16];
  
  puVar8 = (undefined4 *)param_1[0x27];
  iVar7 = *param_1;
  param_1[0x27] = 0;
  if ((param_1[6] == 0) && (puVar8 != (undefined4 *)0x0)) {
    puVar8[8] = param_2;
    for (; param_2 != 0; param_2 = *(int *)(param_2 + 0x24)) {
      *(undefined4 **)(param_2 + 8) = puVar8;
    }
    iVar3 = FUN_007ee9a0(local_10,param_1,*(undefined1 *)(puVar8 + 2),s_trigger_00a01740,puVar8 + 6)
    ;
    param_2 = 0;
    if ((iVar3 == 0) || (iVar3 = FUN_007eebb0(local_10,puVar8[8]), iVar3 == 0)) {
      if (*(char *)(iVar7 + 0x44) == '\0') {
        iVar3 = FUN_007e8190(param_1);
        if (iVar3 == 0) goto LAB_007ee4b9;
        FUN_007d3d30(param_1,0,*(undefined1 *)(puVar8 + 2));
        FUN_007d2760(iVar3,*(undefined1 *)(puVar8 + 2));
        iVar4 = FUN_007dc330(iVar3,10,&DAT_00a01f10);
        FUN_007dc430(iVar3,iVar4 + 2,*puVar8,0);
        FUN_007dc430(iVar3,iVar4 + 3,puVar8[1],0);
        FUN_007dc430(iVar3,iVar4 + 6,*param_3,(uint)param_3[1] >> 1);
        FUN_007d2ce0(iVar7,iVar3,*(undefined1 *)(puVar8 + 2));
        FUN_007dc140(iVar3,0x1e,0,0);
        uVar5 = FUN_007e4830(s_type__trigger__AND_name___q__00a0209c,*puVar8,0xffffffff);
        FUN_007dda80(iVar3,0x1c,*(undefined1 *)(puVar8 + 2),0,uVar5);
        if (*(char *)(iVar7 + 0x44) == '\0') goto LAB_007ee4b9;
      }
      pcVar2 = (char *)*puVar8;
      pcVar6 = pcVar2;
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      iVar3 = FUN_007d1f20((uint)*(byte *)(puVar8 + 2) * 0x70 + 0x34 + *(int *)(iVar7 + 4),pcVar2,
                           pcVar6 + (1 - (int)(pcVar2 + 1)),puVar8);
      if (iVar3 == 0) {
        iVar7 = FUN_007d2330(param_1,puVar8[1],
                             *(undefined4 *)
                              ((uint)*(byte *)((int)puVar8 + 9) * 0x70 + *(int *)(iVar7 + 4)));
        puVar8[9] = *(undefined4 *)(iVar7 + 0x28);
        *(undefined4 **)(iVar7 + 0x28) = puVar8;
        puVar8 = (undefined4 *)0x0;
      }
    }
  }
LAB_007ee4b9:
  FUN_007ed8e0(puVar8);
  FUN_007ed6b0(param_2);
  return;
}


// ==== FUN_007ee4d0 @ 0x007ee4d0 ====

void FUN_007ee4d0(int *param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  iVar8 = 0;
  piVar2 = (int *)*param_1;
  if ((DAT_00b5c4c4 != 0) || (iVar4 = FUN_007ce9f0(param_1), iVar4 != 0)) {
LAB_007ee5c5:
    FUN_007d3a10(param_2);
    return;
  }
  iVar4 = *(int *)(param_2 + 4);
  pcVar3 = *(char **)(param_2 + 8);
  pcVar5 = pcVar3;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar7 = 0;
  if (0 < *piVar2) {
    do {
      uVar9 = uVar7;
      if ((int)uVar7 < 2) {
        uVar9 = uVar7 ^ 1;
      }
      if (((iVar4 == 0) ||
          (iVar6 = FUN_007d08e0(*(undefined4 *)(uVar9 * 0x70 + piVar2[1]),iVar4), iVar6 == 0)) &&
         (iVar8 = FUN_007d1ed0(uVar9 * 0x70 + 0x34 + piVar2[1],pcVar3,
                               pcVar5 + (1 - (int)(pcVar3 + 1))), iVar8 != 0)) goto LAB_007ee5b4;
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < *piVar2);
    if (iVar8 != 0) {
LAB_007ee5b4:
      FUN_007ed940(param_1,iVar8,0);
      goto LAB_007ee5c5;
    }
  }
  FUN_007d0820(param_1,s_no_such_trigger___S_00a020bc,param_2,0);
  FUN_007d3a10(param_2);
  return;
}


// ==== FUN_007ee5e0 @ 0x007ee5e0 ====

void FUN_007ee5e0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  int local_8;
  
  local_8 = 0;
  iVar2 = FUN_007e8190(param_1);
  if (iVar2 == 0) {
    return;
  }
  FUN_007dc140(iVar2,0xf,1,0);
  FUN_007dc140(iVar2,0x25,0,0);
  if ((char)param_1[0x1d] != '\0') {
    return;
  }
  piVar1 = (int *)*param_1;
  if (0xb < *piVar1) {
    FUN_007d0820(param_1,s_too_many_attached_databases___ma_00a02138,10);
    param_1[1] = 1;
    return;
  }
  if (*(char *)((int)piVar1 + 0x11) == '\0') {
    FUN_007d0820(param_1,s_cannot_ATTACH_database_within_tr_00a0210c);
    param_1[1] = 1;
    return;
  }
  iVar2 = FUN_007d2730(param_2);
  if (((iVar2 == 0) || (iVar3 = FUN_007ed5e0(param_1,0x18,iVar2,0,0), iVar3 != 0)) ||
     (local_8 = FUN_007d2730(param_3), local_8 == 0)) goto LAB_007ee84f;
  iVar3 = 0;
  if (0 < *piVar1) {
    iVar8 = 0;
    do {
      if ((*(int *)(iVar8 + piVar1[1]) != 0) &&
         (iVar4 = FUN_007d08e0(*(int *)(iVar8 + piVar1[1]),local_8), iVar4 == 0)) {
        FUN_007d0820(param_1,s_database__s_is_already_in_use_00a020ec,local_8);
        param_1[1] = 1;
        goto LAB_007ee84f;
      }
      iVar3 = iVar3 + 1;
      iVar8 = iVar8 + 0x70;
    } while (iVar3 < *piVar1);
  }
  if ((int *)piVar1[1] == piVar1 + 0x32) {
    puVar5 = (undefined4 *)FUN_007d0550(0x150);
    if (puVar5 == (undefined4 *)0x0) goto LAB_007ee84f;
    puVar7 = (undefined4 *)piVar1[1];
    puVar9 = puVar5;
    for (iVar3 = 0x38; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
  }
  else {
    puVar5 = (undefined4 *)FUN_007d05d0((int *)piVar1[1],(*piVar1 + 1) * 0x70);
    if (puVar5 == (undefined4 *)0x0) goto LAB_007ee84f;
  }
  piVar1[1] = (int)puVar5;
  piVar6 = puVar5 + *piVar1 * 0x1c;
  *piVar1 = *piVar1 + 1;
  piVar10 = piVar6;
  for (iVar3 = 0x1c; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar10 = 0;
    piVar10 = piVar10 + 1;
  }
  FUN_007d1b60(piVar6 + 3,3,0);
  FUN_007d1b60(piVar6 + 8,3,0);
  FUN_007d1b60(piVar6 + 0xd,3,0);
  FUN_007d1b60(piVar6 + 0x12,3,1);
  *piVar6 = local_8;
  *(undefined1 *)((int)piVar6 + 0x5f) = 3;
  local_8 = 0;
  iVar3 = FUN_007cd6c0(piVar1,iVar2,0,2000,piVar6 + 1);
  if (iVar3 != 0) {
    FUN_007d0820(param_1,s_unable_to_open_database___s_00a020d0,iVar2);
  }
  piVar1[2] = piVar1[2] & 0xfffffffd;
  if (param_1[6] == 0) {
    if (iVar3 == 0) {
      iVar3 = FUN_007ce9f0(param_1);
      goto LAB_007ee808;
    }
  }
  else {
LAB_007ee808:
    if (iVar3 == 0) goto LAB_007ee84f;
  }
  iVar8 = (*piVar1 + -1) * 0x70;
  iVar3 = *(int *)(iVar8 + 4 + piVar1[1]);
  if (iVar3 != 0) {
    FUN_007db2b0(iVar3);
    *(undefined4 *)(iVar8 + 4 + piVar1[1]) = 0;
  }
  FUN_007d3fc0(piVar1,0);
  if (param_1[6] == 0) {
    param_1[6] = 1;
    param_1[1] = 1;
  }
LAB_007ee84f:
  FUN_007d05b0(iVar2);
  FUN_007d05b0(local_8);
  return;
}


// ==== FUN_007ee870 @ 0x007ee870 ====

void FUN_007ee870(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  puVar6 = (undefined4 *)0x0;
  iVar2 = FUN_007e8190(param_1);
  if (iVar2 != 0) {
    FUN_007dc140(iVar2,0xf,0,0);
    FUN_007dc140(iVar2,0x25,0,0);
    if (*(char *)(param_1 + 0x1d) == '\0') {
      piVar1 = (int *)*param_1;
      iVar2 = FUN_007d2730(param_2);
      if (iVar2 != 0) {
        iVar4 = 0;
        if (0 < *piVar1) {
          iVar5 = 0;
          do {
            puVar6 = (undefined4 *)(piVar1[1] + iVar5);
            if ((*(int *)(piVar1[1] + 4 + iVar5) != 0) &&
               (iVar3 = FUN_007d08e0(*puVar6,iVar2), iVar3 == 0)) break;
            iVar4 = iVar4 + 1;
            iVar5 = iVar5 + 0x70;
          } while (iVar4 < *piVar1);
        }
        if (*piVar1 <= iVar4) {
          FUN_007d0820(param_1,s_no_such_database___z_00a021a8);
          return;
        }
        if (iVar4 < 2) {
          FUN_007d0820(param_1,s_cannot_detach_database__z_00a0218c);
          return;
        }
        FUN_007d05b0(iVar2);
        if (*(char *)((int)piVar1 + 0x11) == '\0') {
          FUN_007d0820(param_1,s_cannot_DETACH_database_within_tr_00a02160);
          param_1[1] = 1;
          return;
        }
        iVar2 = FUN_007ed5e0(param_1,0x19,*(undefined4 *)(iVar4 * 0x70 + piVar1[1]),0,0);
        if (iVar2 == 0) {
          FUN_007db2b0(puVar6[1]);
          puVar6[1] = 0;
          FUN_007d3fc0(piVar1,0);
        }
      }
    }
  }
  return;
}


// ==== FUN_007ee9a0 @ 0x007ee9a0 ====

undefined4
FUN_007ee9a0(undefined4 *param_1,int *param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  if ((param_3 < 0) || (param_3 == 1)) {
    return 0;
  }
  iVar1 = *param_2;
  *param_1 = param_2;
  param_1[1] = *(undefined4 *)(param_3 * 0x70 + *(int *)(iVar1 + 4));
  param_1[2] = param_4;
  param_1[3] = param_5;
  return 1;
}


// ==== FUN_007ee9e0 @ 0x007ee9e0 ====

undefined4 FUN_007ee9e0(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_2 != 0) {
    do {
      iVar2 = FUN_007eeb20(param_1,*(undefined4 *)(param_2 + 0x34));
      if (iVar2 != 0) {
        return 1;
      }
      piVar1 = *(int **)(param_2 + 0x10);
      if (piVar1 != (int *)0x0) {
        puVar4 = (undefined4 *)piVar1[2];
        iVar2 = 0;
        if (0 < *piVar1) {
          do {
            iVar3 = FUN_007ee9e0(param_1,*puVar4);
            if (iVar3 != 0) {
              return 1;
            }
            iVar2 = iVar2 + 1;
            puVar4 = puVar4 + 3;
          } while (iVar2 < *piVar1);
        }
      }
      iVar2 = FUN_007ee9e0(param_1,*(undefined4 *)(param_2 + 0xc));
      if (iVar2 != 0) {
        return 1;
      }
      param_2 = *(int *)(param_2 + 8);
    } while (param_2 != 0);
  }
  return 0;
}


// ==== FUN_007eea70 @ 0x007eea70 ====

undefined4 FUN_007eea70(undefined4 *param_1,short *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (param_2 == (short *)0x0) {
    return 0;
  }
  uVar1 = param_1[1];
  iVar4 = 0;
  piVar3 = (int *)(param_2 + 2);
  if (*param_2 < 1) {
    return 0;
  }
  do {
    if (*piVar3 == 0) {
      iVar2 = FUN_007d0640();
      *piVar3 = iVar2;
    }
    else {
      iVar2 = FUN_007d08e0(*piVar3,uVar1);
      if (iVar2 != 0) {
        FUN_007d0820(*param_1,s__s__T_cannot_reference_objects_i_00a021c0,param_1[2],param_1[3],
                     *piVar3);
        return 1;
      }
    }
    iVar2 = FUN_007eeb20(param_1,piVar3[4]);
    if (iVar2 != 0) {
      return 1;
    }
    iVar2 = FUN_007ee9e0(param_1,piVar3[7]);
    if (iVar2 != 0) {
      return 1;
    }
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 10;
  } while (iVar4 < *param_2);
  return 0;
}


// ==== FUN_007eeb20 @ 0x007eeb20 ====

undefined4 FUN_007eeb20(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (param_2 != (int *)0x0) {
    do {
      piVar1 = (int *)*param_2;
      if (piVar1 != (int *)0x0) {
        puVar3 = (undefined4 *)piVar1[2];
        iVar4 = 0;
        if (0 < *piVar1) {
          do {
            iVar2 = FUN_007ee9e0(param_1,*puVar3);
            if (iVar2 != 0) {
              return 1;
            }
            iVar4 = iVar4 + 1;
            puVar3 = puVar3 + 3;
          } while (iVar4 < *piVar1);
        }
      }
      iVar4 = FUN_007eea70(param_1,param_2[2]);
      if (iVar4 != 0) {
        return 1;
      }
      iVar4 = FUN_007ee9e0(param_1,param_2[3]);
      if (iVar4 != 0) {
        return 1;
      }
      iVar4 = FUN_007ee9e0(param_1,param_2[5]);
      if (iVar4 != 0) {
        return 1;
      }
      param_2 = (int *)param_2[7];
    } while (param_2 != (int *)0x0);
  }
  return 0;
}


// ==== FUN_007eebb0 @ 0x007eebb0 ====

undefined4 FUN_007eebb0(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_2 != 0) {
    do {
      iVar2 = FUN_007eeb20(param_1,*(undefined4 *)(param_2 + 0xc));
      if (iVar2 != 0) {
        return 1;
      }
      iVar2 = FUN_007ee9e0(param_1,*(undefined4 *)(param_2 + 0x18));
      if (iVar2 != 0) {
        return 1;
      }
      piVar1 = *(int **)(param_2 + 0x1c);
      if (piVar1 != (int *)0x0) {
        puVar4 = (undefined4 *)piVar1[2];
        iVar2 = 0;
        if (0 < *piVar1) {
          do {
            iVar3 = FUN_007ee9e0(param_1,*puVar4);
            if (iVar3 != 0) {
              return 1;
            }
            iVar2 = iVar2 + 1;
            puVar4 = puVar4 + 3;
          } while (iVar2 < *piVar1);
        }
      }
      param_2 = *(int *)(param_2 + 0x24);
    } while (param_2 != 0);
  }
  return 0;
}


// ==== FUN_007eec30 @ 0x007eec30 ====

void FUN_007eec30(void)

{
  int iVar1;
  uint in_ECX;
  uint *unaff_ESI;
  
  iVar1 = FUN_007d1550();
  if (iVar1 == 0) {
    *unaff_ESI = in_ECX >> 0x18 |
                 (((in_ECX & 0xff) << 8 | in_ECX >> 8 & 0xff) << 8 | in_ECX >> 0x10 & 0xff) << 8;
    return;
  }
  *unaff_ESI = in_ECX;
  return;
}


// ==== FUN_007eec70 @ 0x007eec70 ====

void FUN_007eec70(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  _local_4 = CONCAT13((char)in_EAX,
                      CONCAT12((char)((uint)in_EAX >> 8),
                               CONCAT11((char)((uint)in_EAX >> 0x10),(char)((uint)in_EAX >> 0x18))))
  ;
  FUN_007d15a0(param_1,&local_4,4);
  return;
}


// ==== FUN_007eecb0 @ 0x007eecb0 ====

void FUN_007eecb0(void)

{
  int in_EAX;
  int in_ECX;
  undefined4 in_EDX;
  
  *(char *)(in_ECX + 0x30 + in_EAX) = (char)((uint)in_EDX >> 0x18);
  *(char *)(in_ECX + 0x31 + in_EAX) = (char)((uint)in_EDX >> 0x10);
  *(char *)(in_ECX + 0x32 + in_EAX) = (char)((uint)in_EDX >> 8);
  *(char *)(in_ECX + 0x33 + in_EAX) = (char)in_EDX;
  return;
}


// ==== FUN_007eece0 @ 0x007eece0 ====

undefined4 FUN_007eece0(void)

{
  byte bVar1;
  undefined4 uVar2;
  int in_ECX;
  
  bVar1 = *(byte *)(in_ECX + 10);
  uVar2 = 0;
  if ((bVar1 & 4) != 0) {
    uVar2 = 0xf;
  }
  if ((bVar1 & 0x10) != 0) {
    uVar2 = 10;
  }
  if ((bVar1 & 1) != 0) {
    uVar2 = 0xd;
  }
  if ((bVar1 & 2) != 0) {
    uVar2 = 7;
  }
  if ((bVar1 & 8) != 0) {
    uVar2 = 0xb;
  }
  return uVar2;
}


// ==== FUN_007eed20 @ 0x007eed20 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007eed20(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  bool bVar6;
  uint local_18;
  int local_14;
  uint local_10;
  int local_c [3];
  
  local_c[2] = DAT_00b49670;
  *param_1 = 0;
  iVar1 = FUN_007d1690();
  if ((((iVar1 == 0) && (-1 < local_14)) && ((0 < local_14 || (0xf < local_18)))) &&
     ((((iVar1 = FUN_007d1600(), iVar1 == 0 && (iVar1 = FUN_007eec30(), iVar1 == 0)) &&
       (iVar1 = FUN_007eec30(), iVar1 == 0)) && (iVar1 = FUN_007d1550(), iVar1 == 0)))) {
    iVar3 = 2;
    bVar6 = true;
    piVar4 = local_c;
    piVar5 = &DAT_00a021f0;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *piVar4 == *piVar5;
      piVar4 = piVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (bVar6);
    if ((bVar6) && (iVar1 = FUN_007d1600(), iVar1 == 0)) {
      iVar1 = FUN_007d0550(local_10 + 1);
      *param_1 = iVar1;
      if (iVar1 == 0) {
        return 7;
      }
      iVar1 = FUN_007d1550();
      if (iVar1 != 0) {
        FUN_007d05b0(*param_1);
        *param_1 = 0;
        return iVar1;
      }
      uVar2 = 0;
      piVar4 = param_1;
      if (local_10 != 0) {
        do {
          piVar4 = (int *)((int)piVar4 - (int)*(char *)(*param_1 + uVar2));
          uVar2 = uVar2 + 1;
        } while (uVar2 < local_10);
      }
      if (piVar4 != (int *)0x0) {
        FUN_007d05b0(*param_1);
        *param_1 = 0;
        return 0;
      }
      *(undefined1 *)(local_10 + *param_1) = 0;
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ==== FUN_007eeec0 @ 0x007eeec0 ====

void FUN_007eeec0(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  longlong lVar3;
  undefined8 uVar4;
  
  iVar1 = *(int *)(in_EAX + 0x88);
  uVar4 = 0;
  if (iVar1 != 0 || *(int *)(in_EAX + 0x8c) != 0) {
    iVar2 = *(int *)(in_EAX + 0xb0);
    lVar3 = __alldiv(iVar1 + -1,*(int *)(in_EAX + 0x8c) - (uint)(iVar1 == 0),iVar2,iVar2 >> 0x1f);
    uVar4 = __allmul(lVar3 + 1,iVar2,iVar2 >> 0x1f);
  }
  *(undefined8 *)(in_EAX + 0x88) = uVar4;
  FUN_007d1600(in_EAX + 0x60,uVar4);
  return;
}


// ==== FUN_007eef30 @ 0x007eef30 ====

void FUN_007eef30(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int unaff_ESI;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  iVar5 = FUN_007eeec0();
  if (iVar5 == 0) {
    uVar2 = *(uint *)(unaff_ESI + 0x88);
    iVar5 = *(int *)(unaff_ESI + 0x8c);
    *(uint *)(unaff_ESI + 0x90) = uVar2;
    *(int *)(unaff_ESI + 0x94) = iVar5;
    if (*(int *)(unaff_ESI + 0x98) == 0 && *(int *)(unaff_ESI + 0x9c) == 0) {
      *(uint *)(unaff_ESI + 0x98) = uVar2;
      *(int *)(unaff_ESI + 0x9c) = iVar5;
    }
    uVar3 = *(uint *)(unaff_ESI + 0xb0);
    iVar1 = unaff_ESI + 0x60;
    *(uint *)(unaff_ESI + 0x88) = uVar3 + uVar2;
    *(uint *)(unaff_ESI + 0x8c) = ((int)uVar3 >> 0x1f) + iVar5 + (uint)CARRY4(uVar3,uVar2);
    iVar5 = FUN_007d15a0(iVar1,&DAT_00a021f0,8);
    if (iVar5 == 0) {
      iVar5 = -(uint)(*(char *)(unaff_ESI + 7) != '\0');
      _local_4 = CONCAT11((char)((uint)iVar5 >> 0x10),(char)((uint)iVar5 >> 0x18));
      _local_4 = CONCAT12((char)((uint)iVar5 >> 8),_local_4);
      _local_4 = CONCAT13((char)iVar5,_local_4);
      iVar5 = FUN_007d15a0(iVar1,&local_4,4);
      if (iVar5 == 0) {
        FUN_007e6500(4,(undefined4 *)(unaff_ESI + 0x24));
        uVar4 = *(undefined4 *)(unaff_ESI + 0x24);
        _local_4 = CONCAT11((char)((uint)uVar4 >> 0x10),(char)((uint)uVar4 >> 0x18));
        _local_4 = CONCAT12((char)((uint)uVar4 >> 8),_local_4);
        _local_4 = CONCAT13((char)uVar4,_local_4);
        iVar5 = FUN_007d15a0(iVar1,&local_4,4);
        if (iVar5 == 0) {
          uVar4 = *(undefined4 *)(unaff_ESI + 0x14);
          _local_4 = CONCAT11((char)((uint)uVar4 >> 0x10),(char)((uint)uVar4 >> 0x18));
          _local_4 = CONCAT12((char)((uint)uVar4 >> 8),_local_4);
          _local_4 = CONCAT13((char)uVar4,_local_4);
          iVar5 = FUN_007d15a0(iVar1,&local_4,4);
          if (iVar5 == 0) {
            uVar4 = *(undefined4 *)(unaff_ESI + 0xb0);
            _local_4 = CONCAT11((char)((uint)uVar4 >> 0x10),(char)((uint)uVar4 >> 0x18));
            _local_4 = CONCAT12((char)((uint)uVar4 >> 8),_local_4);
            _local_4 = CONCAT13((char)uVar4,_local_4);
            iVar5 = FUN_007d15a0(iVar1,&local_4,4);
            if (iVar5 == 0) {
              FUN_007d1600(iVar1,*(int *)(unaff_ESI + 0x88) + -1,
                           *(int *)(unaff_ESI + 0x8c) - (uint)(*(int *)(unaff_ESI + 0x88) == 0));
              FUN_007d15a0(iVar1,&DAT_00a021f8,1);
            }
          }
        }
      }
    }
  }
  return;
}


// ==== FUN_007ef0d0 @ 0x007ef0d0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007ef0d0(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int unaff_EBX;
  int *piVar4;
  int *piVar5;
  bool bVar6;
  int local_c [3];
  
  local_c[2] = DAT_00b49670;
  iVar2 = FUN_007eeec0();
  if (iVar2 == 0) {
    uVar1 = *(uint *)(unaff_EBX + 0xb0);
    iVar2 = ((int)uVar1 >> 0x1f) + *(int *)(unaff_EBX + 0x8c) +
            (uint)CARRY4(uVar1,*(uint *)(unaff_EBX + 0x88));
    if ((param_2 <= iVar2) && ((param_2 < iVar2 || (param_1 < uVar1 + *(uint *)(unaff_EBX + 0x88))))
       ) {
      return 0x65;
    }
    iVar2 = FUN_007d1550(unaff_EBX + 0x60,local_c,8);
    if (iVar2 == 0) {
      iVar2 = 2;
      bVar6 = true;
      piVar4 = local_c;
      piVar5 = &DAT_00a021f0;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *piVar4 == *piVar5;
        piVar4 = piVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (bVar6);
      if (!bVar6) {
        return 0x65;
      }
      iVar2 = FUN_007eec30();
      if (((iVar2 == 0) && (iVar2 = FUN_007eec30(), iVar2 == 0)) &&
         (iVar2 = FUN_007eec30(), iVar2 == 0)) {
        iVar2 = FUN_007eec30();
        if (iVar2 == 0) {
          uVar1 = *(uint *)(unaff_EBX + 0xb0);
          iVar3 = *(uint *)(unaff_EBX + 0x88) + uVar1;
          iVar2 = *(int *)(unaff_EBX + 0x8c) + ((int)uVar1 >> 0x1f) +
                  (uint)CARRY4(*(uint *)(unaff_EBX + 0x88),uVar1);
          *(int *)(unaff_EBX + 0x88) = iVar3;
          *(int *)(unaff_EBX + 0x8c) = iVar2;
          iVar2 = FUN_007d1600(unaff_EBX + 0x60,iVar3,iVar2);
        }
      }
    }
  }
  return iVar2;
}


// ==== FUN_007ef1f0 @ 0x007ef1f0 ====

int FUN_007ef1f0(char *param_1)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  int unaff_ESI;
  
  pcVar5 = param_1;
  if ((param_1 == (char *)0x0) || (*(char *)(unaff_ESI + 0x11) != '\0')) {
    return 0;
  }
  *(undefined1 *)(unaff_ESI + 0x11) = 1;
  pcVar7 = param_1;
  do {
    cVar3 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar3 != '\0');
  iVar8 = (int)pcVar7 - (int)(param_1 + 1);
  iVar6 = 0;
  if (0 < iVar8) {
    do {
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar8);
  }
  if ((*(char *)(unaff_ESI + 8) == '\0') || (iVar6 = FUN_007eeec0(), iVar6 == 0)) {
    uVar4 = *(uint *)(unaff_ESI + 0x88);
    uVar1 = iVar8 + 0x14;
    *(uint *)(unaff_ESI + 0x88) = uVar4 + uVar1;
    *(uint *)(unaff_ESI + 0x8c) =
         *(int *)(unaff_ESI + 0x8c) + ((int)uVar1 >> 0x1f) + (uint)CARRY4(uVar4,uVar1);
    iVar2 = unaff_ESI + 0x60;
    iVar6 = (int)(0x40000000 / (longlong)*(int *)(unaff_ESI + 0x30)) + 1;
    param_1._0_2_ = CONCAT11((char)((uint)iVar6 >> 0x10),(char)((uint)iVar6 >> 0x18));
    param_1._0_3_ = CONCAT12((char)((uint)iVar6 >> 8),param_1._0_2_);
    param_1 = (char *)CONCAT13((char)iVar6,param_1._0_3_);
    iVar6 = FUN_007d15a0(iVar2,&param_1,4);
    if ((iVar6 == 0) && (iVar6 = FUN_007d15a0(iVar2,pcVar5,iVar8), iVar6 == 0)) {
      param_1._0_2_ = CONCAT11((char)((uint)iVar8 >> 0x10),(char)((uint)iVar8 >> 0x18));
      param_1._0_3_ = CONCAT12((char)((uint)iVar8 >> 8),param_1._0_2_);
      param_1 = (char *)CONCAT13((char)iVar8,param_1._0_3_);
      iVar6 = FUN_007d15a0(iVar2,&param_1,4);
      if ((iVar6 == 0) && (iVar6 = FUN_007eec70(iVar2), iVar6 == 0)) {
        iVar6 = FUN_007d15a0(iVar2,&DAT_00a021f0,8);
        *(undefined1 *)(unaff_ESI + 0xd) = 1;
      }
    }
  }
  return iVar6;
}


// ==== FUN_007ef330 @ 0x007ef330 ====

void FUN_007ef330(void)

{
  int iVar1;
  int *in_EAX;
  
  iVar1 = *in_EAX;
  if (*(char *)((int)in_EAX + 0x25) == '\0') {
    in_EAX[8] = 0;
    if (*(int *)(iVar1 + 0x84) != 0) {
      *(int **)(*(int *)(iVar1 + 0x84) + 0x20) = in_EAX;
    }
    in_EAX[7] = *(int *)(iVar1 + 0x84);
    *(int **)(iVar1 + 0x84) = in_EAX;
    *(undefined1 *)((int)in_EAX + 0x25) = 1;
  }
  return;
}


// ==== FUN_007ef370 @ 0x007ef370 ====

void FUN_007ef370(void)

{
  int *in_EAX;
  
  if (*(char *)((int)in_EAX + 0x25) != '\0') {
    if (in_EAX[8] == 0) {
      *(int *)(*in_EAX + 0x84) = in_EAX[7];
    }
    else {
      *(int *)(in_EAX[8] + 0x1c) = in_EAX[7];
    }
    if (in_EAX[7] != 0) {
      *(int *)(in_EAX[7] + 0x20) = in_EAX[8];
    }
    in_EAX[7] = 0;
    in_EAX[8] = 0;
    *(undefined1 *)((int)in_EAX + 0x25) = 0;
  }
  return;
}


// ==== FUN_007ef3b0 @ 0x007ef3b0 ====

void FUN_007ef3b0(void)

{
  int iVar1;
  uint in_ECX;
  int in_EDX;
  
  for (iVar1 = *(int *)(in_EDX + 0xc4 + (in_ECX & 0x7ff) * 4);
      (iVar1 != 0 && (*(uint *)(iVar1 + 4) != in_ECX)); iVar1 = *(int *)(iVar1 + 8)) {
  }
  return;
}


// ==== FUN_007ef3d0 @ 0x007ef3d0 ====

int FUN_007ef3d0(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int in_EDX;
  
  iVar2 = *(int *)(in_ECX + 0x24);
  iVar1 = *(int *)(in_ECX + 0x30);
  while (iVar1 = iVar1 + -200, 0 < iVar1) {
    iVar2 = iVar2 + *(char *)(iVar1 + in_EDX);
  }
  return iVar2;
}


// ==== FUN_007ef400 @ 0x007ef400 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007ef400(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  uint local_200c;
  int local_2008;
  undefined4 local_2004 [2048];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  iVar2 = FUN_007d1550();
  if (iVar2 != 0) {
    return iVar2;
  }
  uVar4 = (((local_200c & 0xff) << 8 | local_200c >> 8 & 0xff) << 8 | local_200c >> 0x10 & 0xff) <<
          8 | local_200c >> 0x18;
  iVar2 = FUN_007d1550();
  if (iVar2 != 0) {
    return iVar2;
  }
  uVar1 = *(uint *)(param_1 + 0x88);
  uVar3 = *(int *)(param_1 + 0x30) + 4;
  *(uint *)(param_1 + 0x88) = uVar1 + uVar3;
  *(uint *)(param_1 + 0x8c) =
       *(int *)(param_1 + 0x8c) + ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar1,uVar3);
  if ((uVar4 == 0) || (uVar4 == (int)(0x40000000 / (longlong)*(int *)(param_1 + 0x30)) + 1U)) {
    return 0x65;
  }
  if (*(uint *)(param_1 + 0x14) < uVar4) {
    return 0;
  }
  if (param_2 != 0) {
    iVar2 = FUN_007eec30();
    if (iVar2 != 0) {
      return iVar2;
    }
    *(uint *)(param_1 + 0x8c) =
         *(int *)(param_1 + 0x8c) + (uint)(0xfffffffb < *(uint *)(param_1 + 0x88));
    *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) + 4;
    iVar2 = FUN_007ef3d0();
    if (iVar2 != local_2008) {
      return 0x65;
    }
  }
  local_200c = 0;
  iVar2 = FUN_007ef3b0();
  if ((3 < *(byte *)(param_1 + 9)) && ((iVar2 == 0 || (*(char *)(iVar2 + 0x27) == '\0')))) {
    uVar7 = __allmul(uVar4 - 1,0,*(int *)(param_1 + 0x30),*(int *)(param_1 + 0x30) >> 0x1f);
    FUN_007d1600(param_1 + 0x58,uVar7);
    local_200c = FUN_007d15a0(param_1 + 0x58,local_2004,*(undefined4 *)(param_1 + 0x30));
    if (iVar2 == 0) {
      return local_200c;
    }
    *(undefined1 *)(iVar2 + 0x26) = 0;
  }
  if (iVar2 != 0) {
    uVar4 = *(uint *)(param_1 + 0x30);
    puVar5 = local_2004;
    puVar6 = (undefined4 *)(iVar2 + 0x30);
    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    if (*(code **)(param_1 + 0xb4) != (code *)0x0) {
      (**(code **)(param_1 + 0xb4))((undefined4 *)(iVar2 + 0x30),*(undefined4 *)(param_1 + 0x30));
    }
  }
  return local_200c;
}


// ==== FUN_007ef5f0 @ 0x007ef5f0 ====

int FUN_007ef5f0(byte *param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  char *pcVar6;
  byte *pbVar7;
  bool bVar8;
  char *local_20;
  byte *local_1c;
  uint local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0;
  local_20 = (char *)0x0;
  local_c = 0;
  iVar3 = FUN_007d13a0(param_1,&local_10);
  if (iVar3 != 0) {
    return iVar3;
  }
  iVar3 = FUN_007d1690(&local_10,&local_18);
  if (iVar3 != 0) goto LAB_007ef7a9;
  if ((local_14 < 0) || ((local_14 < 1 && (local_18 == 0)))) {
LAB_007ef78e:
    FUN_007d12a0(param_1);
  }
  else {
    local_1c = (byte *)0x0;
    local_20 = (char *)FUN_007d0550(local_18);
    if (local_20 == (char *)0x0) {
      iVar3 = 7;
    }
    else {
      iVar3 = FUN_007d1550(&local_10,local_20,local_18);
      if (iVar3 == 0) {
        if ((-1 < local_14) && ((pcVar6 = local_20, 0 < local_14 || (local_18 != 0)))) {
          do {
            iVar4 = FUN_007d12b0(pcVar6);
            if (iVar4 != 0) {
              local_8 = 0;
              local_4 = 0;
              iVar3 = FUN_007d13a0(pcVar6,&local_8);
              if (iVar3 != 0) goto LAB_007ef797;
              iVar3 = FUN_007eed20(&local_1c);
              FUN_007d1530(&local_8);
              if (iVar3 != 0) goto LAB_007ef797;
              if (local_1c == (byte *)0x0) {
LAB_007ef746:
                bVar8 = false;
              }
              else {
                pbVar5 = local_1c;
                pbVar7 = param_1;
                do {
                  bVar1 = *pbVar5;
                  bVar8 = bVar1 < *pbVar7;
                  if (bVar1 != *pbVar7) {
LAB_007ef736:
                    iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                    goto LAB_007ef73b;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar5[1];
                  bVar8 = bVar1 < pbVar7[1];
                  if (bVar1 != pbVar7[1]) goto LAB_007ef736;
                  pbVar5 = pbVar5 + 2;
                  pbVar7 = pbVar7 + 2;
                } while (bVar1 != 0);
                iVar4 = 0;
LAB_007ef73b:
                if (iVar4 != 0) goto LAB_007ef746;
                bVar8 = true;
              }
              FUN_007d05b0(local_1c);
              if (bVar8) goto LAB_007ef797;
            }
            do {
              cVar2 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar2 != '\0');
            iVar4 = (int)pcVar6 - (int)local_20 >> 0x1f;
          } while ((iVar4 < local_14) ||
                  ((iVar4 <= local_14 && ((uint)((int)pcVar6 - (int)local_20) < local_18))));
        }
        goto LAB_007ef78e;
      }
    }
  }
LAB_007ef797:
  if (local_20 != (char *)0x0) {
    FUN_007d05b0(local_20);
  }
LAB_007ef7a9:
  FUN_007d1530(&local_10);
  return iVar3;
}


// ==== FUN_007ef7c0 @ 0x007ef7c0 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007ef7c0(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int unaff_EBX;
  char *pcVar5;
  char *pcVar6;
  undefined4 *puVar7;
  bool bVar8;
  undefined8 uVar9;
  int local_2014;
  char local_2010 [8196];
  undefined4 local_c;
  
  iVar1 = *(int *)(unaff_EBX + 0x80);
  iVar2 = 0;
  local_2014 = 0;
  local_c = DAT_00b49670;
  do {
    if (iVar1 == 0) {
      return iVar2;
    }
    if (*(char *)(iVar1 + 0x26) != '\0') {
      if (*(int *)(unaff_EBX + 0x18) < *(int *)(iVar1 + 4)) {
        uVar4 = *(uint *)(unaff_EBX + 0x30);
        pcVar5 = local_2010;
        for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          pcVar5[0] = '\0';
          pcVar5[1] = '\0';
          pcVar5[2] = '\0';
          pcVar5[3] = '\0';
          pcVar5 = pcVar5 + 4;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *pcVar5 = '\0';
          pcVar5 = pcVar5 + 1;
        }
      }
      else {
        uVar9 = __allmul(*(int *)(iVar1 + 4) + -1,0,*(int *)(unaff_EBX + 0x30),
                         *(int *)(unaff_EBX + 0x30) >> 0x1f);
        FUN_007d1600(unaff_EBX + 0x58,uVar9);
        local_2014 = FUN_007d1550(unaff_EBX + 0x58,local_2010,*(undefined4 *)(unaff_EBX + 0x30));
        if (local_2014 != 0) {
          return local_2014;
        }
      }
      if (*(short *)(iVar1 + 0x2a) == 0) {
LAB_007ef881:
        uVar4 = *(uint *)(unaff_EBX + 0x30);
        pcVar5 = local_2010;
        pcVar6 = (char *)(iVar1 + 0x30);
        for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          pcVar6 = pcVar6 + 4;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *pcVar6 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          pcVar6 = pcVar6 + 1;
        }
        if (*(code **)(unaff_EBX + 0xb8) == (code *)0x0) {
          uVar4 = *(uint *)(unaff_EBX + 0x2c);
          puVar7 = (undefined4 *)(*(int *)(unaff_EBX + 0x30) + 0x30 + iVar1);
          for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
          }
          for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar7 = 0;
            puVar7 = (undefined4 *)((int)puVar7 + 1);
          }
        }
        else {
          (**(code **)(unaff_EBX + 0xb8))((char *)(iVar1 + 0x30),*(int *)(unaff_EBX + 0x30));
        }
      }
      else {
        iVar2 = *(int *)(unaff_EBX + 0x30);
        bVar8 = true;
        pcVar5 = local_2010;
        pcVar6 = (char *)(iVar1 + 0x30);
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar8 = *pcVar5 == *pcVar6;
          pcVar5 = pcVar5 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar8);
        if (!bVar8) goto LAB_007ef881;
      }
      *(undefined1 *)(iVar1 + 0x27) = 0;
      *(undefined1 *)(iVar1 + 0x26) = 0;
      iVar2 = local_2014;
    }
    iVar1 = *(int *)(iVar1 + 0x18);
  } while( true );
}


// ==== FUN_007ef900 @ 0x007ef900 ====

void FUN_007ef900(int param_1)

{
  int in_ECX;
  
  FUN_007d1650(in_ECX + 0x58,(longlong)*(int *)(in_ECX + 0x30) * (longlong)param_1);
  return;
}


// ==== FUN_007ef920 @ 0x007ef920 ====

undefined4 FUN_007ef920(void)

{
  int in_EAX;
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int local_10;
  int local_c;
  uint local_8;
  int local_4;
  
  local_8 = *(uint *)(in_EAX + 0x88);
  local_4 = *(int *)(in_EAX + 0x8c);
  iVar4 = *(int *)(in_EAX + 0x9c);
  uVar5 = *(uint *)(in_EAX + 0x98);
  if (*(uint *)(in_EAX + 0x98) == 0 && *(int *)(in_EAX + 0x9c) == 0) {
    iVar4 = local_4;
    uVar5 = local_8;
  }
  if (3 < *(byte *)(in_EAX + 9)) {
    FUN_007d1650(in_EAX + 0x58,(longlong)*(int *)(in_EAX + 0x30) * (longlong)*(int *)(in_EAX + 0x1c)
                );
  }
  *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x1c);
  FUN_007d1600(in_EAX + 0x68,0,0);
  local_10 = *(int *)(in_EAX + 0x28);
  do {
    local_10 = local_10 + -1;
    if (local_10 < 0) {
      iVar1 = FUN_007d1600(in_EAX + 0x60,*(undefined4 *)(in_EAX + 0xa8),
                           *(undefined4 *)(in_EAX + 0xac));
      if (iVar1 == 0) {
        *(undefined4 *)(in_EAX + 0x8c) = *(undefined4 *)(in_EAX + 0xac);
        uVar2 = *(int *)(in_EAX + 0x30) + 8;
        *(undefined4 *)(in_EAX + 0x88) = *(undefined4 *)(in_EAX + 0xa8);
        *(undefined4 *)(in_EAX + 0x24) = *(undefined4 *)(in_EAX + 0xa0);
        iVar1 = (iVar4 - ((int)uVar2 >> 0x1f)) - (uint)(uVar5 < uVar2);
        if ((iVar1 < *(int *)(in_EAX + 0x8c)) ||
           ((iVar1 <= *(int *)(in_EAX + 0x8c) && (uVar5 - uVar2 < *(uint *)(in_EAX + 0x88)))))
        goto LAB_007efa52;
        goto LAB_007efa15;
      }
      break;
    }
    iVar1 = FUN_007ef400();
  } while (iVar1 == 0);
LAB_007efb43:
  *(byte *)(in_EAX + 10) = *(byte *)(in_EAX + 10) | 8;
  return 0xb;
  while( true ) {
    uVar2 = *(int *)(in_EAX + 0x30) + 8;
    iVar1 = (iVar4 - ((int)uVar2 >> 0x1f)) - (uint)(uVar5 < uVar2);
    if ((iVar1 <= *(int *)(in_EAX + 0x8c)) &&
       ((iVar1 < *(int *)(in_EAX + 0x8c) || (uVar5 - uVar2 < *(uint *)(in_EAX + 0x88))))) break;
LAB_007efa15:
    iVar1 = FUN_007ef400();
    if (iVar1 != 0) goto LAB_007efb43;
  }
LAB_007efa52:
  uVar5 = local_8;
  iVar4 = local_4;
  if (*(int *)(in_EAX + 0x8c) <= local_4) {
    if (*(int *)(in_EAX + 0x8c) < local_4) goto LAB_007efa80;
    uVar2 = *(uint *)(in_EAX + 0x88);
    while (uVar2 < uVar5) {
LAB_007efa80:
      do {
        iVar1 = FUN_007ef0d0(uVar5,iVar4,&local_c,&local_10);
        if (iVar1 != 0) goto LAB_007efb43;
        iVar1 = local_c;
        if (local_c == 0) {
          iVar1 = *(int *)(in_EAX + 0x30) + 8;
          local_c = __alldiv(uVar5 - *(uint *)(in_EAX + 0x88),
                             (iVar4 - *(int *)(in_EAX + 0x8c)) -
                             (uint)(uVar5 < *(uint *)(in_EAX + 0x88)),iVar1,iVar1 >> 0x1f);
          iVar1 = local_c;
          iVar4 = local_4;
        }
        while (((local_10 = iVar1 + -1, -1 < local_10 && (*(int *)(in_EAX + 0x8c) <= iVar4)) &&
               ((*(int *)(in_EAX + 0x8c) < iVar4 || (*(uint *)(in_EAX + 0x88) < uVar5))))) {
          iVar3 = FUN_007ef400();
          iVar1 = local_10;
          if (iVar3 != 0) goto LAB_007efb43;
        }
      } while (*(int *)(in_EAX + 0x8c) < iVar4);
      if (iVar4 < *(int *)(in_EAX + 0x8c)) break;
      uVar2 = *(uint *)(in_EAX + 0x88);
    }
  }
  *(uint *)(in_EAX + 0x88) = uVar5;
  *(uint *)(in_EAX + 0x88) = uVar5;
  *(int *)(in_EAX + 0x8c) = iVar4;
  *(int *)(in_EAX + 0x8c) = iVar4;
  return 0;
}


// ==== FUN_007efb60 @ 0x007efb60 ====

void FUN_007efb60(int param_1,int param_2)

{
  if (param_2 < 0xb) {
    *(undefined4 *)(param_1 + 0x40) = 10;
    return;
  }
  *(int *)(param_1 + 0x40) = param_2;
  return;
}


// ==== FUN_007efb80 @ 0x007efb80 ====

void FUN_007efb80(int param_1,int param_2)

{
  undefined1 uVar1;
  char cVar2;
  
  if ((param_2 == 1) || (*(char *)(param_1 + 0xb) != '\0')) {
    cVar2 = '\x01';
  }
  else {
    cVar2 = '\0';
  }
  *(char *)(param_1 + 7) = cVar2;
  if ((param_2 == 3) && (*(char *)(param_1 + 0xb) == '\0')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  *(undefined1 *)(param_1 + 8) = uVar1;
  if (cVar2 != '\0') {
    *(undefined1 *)(param_1 + 0xd) = 0;
  }
  return;
}


// ==== FUN_007efbd0 @ 0x007efbd0 ====

void FUN_007efbd0(void)

{
  int iVar1;
  int iVar2;
  
  DAT_00b5c618 = DAT_00b5c618 + 1;
  iVar2 = 8;
  while( true ) {
    iVar2 = iVar2 + -1;
    FUN_007d13e0();
    iVar1 = FUN_007d1350();
    if (iVar2 < 1) {
      return;
    }
    if (iVar1 == 0) break;
    if (iVar1 == 7) {
      return;
    }
  }
  return;
}


// ==== FUN_007efc10 @ 0x007efc10 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007efc10(undefined4 *param_1,char *param_2,int param_3,uint param_4)

{
  undefined1 uVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  undefined4 *puVar9;
  bool bVar10;
  undefined4 local_158;
  undefined4 local_154;
  int local_150;
  int local_14c;
  undefined4 local_148;
  uint local_144;
  uint local_140;
  undefined1 local_13c [312];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  local_140 = param_4 >> 1 & 1;
  local_144 = ~param_4 & 1;
  *param_1 = 0;
  local_158 = 0;
  local_148 = 0;
  local_14c = 0;
  local_150 = 0;
  local_154 = 0;
  if (DAT_00b5c4c4 != 0) {
    return 7;
  }
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
    iVar7 = FUN_007efbd0();
    pcVar3 = (char *)FUN_007d1a70(local_13c);
    if (iVar7 == 0) {
      local_148 = 1;
    }
  }
  else {
    iVar7 = 9;
    bVar10 = true;
    pcVar3 = param_2;
    pcVar4 = s__memory__009ffce0;
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar10 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar10);
    if (bVar10) {
      local_14c = 1;
      pcVar3 = (char *)FUN_007d0640(&DAT_0099cf70);
      iVar7 = 0;
    }
    else {
      pcVar3 = (char *)FUN_007d1a70(param_2);
      if (pcVar3 == (char *)0x0) goto LAB_007efd13;
      iVar7 = FUN_007d12d0(pcVar3,&local_158,&local_150);
    }
  }
  if (pcVar3 != (char *)0x0) {
    if (iVar7 != 0) {
      FUN_007d1530(&local_158);
      FUN_007d05b0(pcVar3);
      return iVar7;
    }
    pcVar4 = pcVar3;
    do {
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    iVar7 = (int)pcVar4 - (int)(pcVar3 + 1);
    puVar5 = (undefined1 *)FUN_007d0550(iVar7 * 3 + 0x20e6);
    if (puVar5 == (undefined1 *)0x0) {
      FUN_007d1530(&local_158);
      FUN_007d05b0(pcVar3);
      return 7;
    }
    *(undefined1 **)(puVar5 + 0x4c) = puVar5 + 0x20c8;
    *(undefined1 **)(puVar5 + 0x54) = puVar5 + iVar7 + 0x20c9;
    *(undefined1 **)(puVar5 + 0x50) = puVar5 + iVar7 + 0x20c9 + iVar7 + 1;
    pcVar4 = pcVar3;
    do {
      cVar2 = *pcVar4;
      pcVar4[(int)(puVar5 + 0x20c8) - (int)pcVar3] = cVar2;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    pcVar4 = *(char **)(puVar5 + 0x54);
    pcVar8 = pcVar3;
    do {
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      *pcVar4 = cVar2;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    if (0 < iVar7) {
      pcVar4 = (char *)(*(int *)(puVar5 + 0x54) + -1 + iVar7);
      iVar6 = iVar7;
      do {
        if (*pcVar4 == '/') {
          if (0 < iVar6) {
            *(undefined1 *)(*(int *)(puVar5 + 0x54) + -1 + iVar6) = 0;
          }
          break;
        }
        iVar6 = iVar6 + -1;
        pcVar4 = pcVar4 + -1;
      } while (0 < iVar6);
    }
    pcVar4 = *(char **)(puVar5 + 0x50);
    pcVar8 = pcVar3;
    do {
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      *pcVar4 = cVar2;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    FUN_007d05b0(pcVar3);
    pcVar3 = (char *)(*(int *)(puVar5 + 0x50) + iVar7);
    *(undefined4 *)pcVar3 = s__journal_00a021fc._0_4_;
    *(undefined4 *)(pcVar3 + 4) = s__journal_00a021fc._4_4_;
    pcVar3[8] = s__journal_00a021fc[8];
    *(undefined4 *)(puVar5 + 0x58) = local_158;
    *(undefined4 *)(puVar5 + 0x5c) = local_154;
    *puVar5 = 0;
    if ((local_144 == 0) || (local_14c != 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    puVar5[2] = uVar1;
    if ((local_140 == 0) || (local_150 == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    puVar5[3] = uVar1;
    puVar5[4] = 0;
    puVar5[5] = 0;
    *(undefined4 *)(puVar5 + 0x3c) = 0;
    *(int *)(puVar5 + 0x14) = local_14c + -1;
    *(undefined4 *)(puVar5 + 0x30) = 0x400;
    *(undefined4 *)(puVar5 + 0x1c) = 0;
    *(undefined4 *)(puVar5 + 0xa8) = 0;
    *(undefined4 *)(puVar5 + 0xac) = 0;
    *(undefined4 *)(puVar5 + 0x34) = 0;
    *(undefined4 *)(puVar5 + 0x38) = 0;
    *(undefined4 *)(puVar5 + 0x40) = 100;
    puVar5[9] = 0;
    puVar5[10] = 0;
    puVar5[0xb] = (char)local_148;
    puVar5[0x10] = (char)local_14c;
    puVar5[0xc] = (undefined1)local_150;
    puVar5[0xd] = 0;
    if (((char)local_148 == '\0') && (local_144 != 0)) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
    puVar5[7] = cVar2;
    *(uint *)(puVar5 + 0x2c) = param_3 + 7U & 0xfffffff8;
    *(undefined4 *)(puVar5 + 0x74) = 0;
    *(undefined4 *)(puVar5 + 0x7c) = 0;
    *(undefined4 *)(puVar5 + 0x78) = 0;
    *(undefined4 *)(puVar5 + 0x70) = 0;
    puVar5[8] = cVar2 == '\0';
    *(undefined4 *)(puVar5 + 0xb0) = 0x200;
    puVar9 = (undefined4 *)(puVar5 + 0xc4);
    for (iVar7 = 0x800; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    *param_1 = puVar5;
    return 0;
  }
LAB_007efd13:
  FUN_007d1530(&local_158);
  return 7;
}


// ==== FUN_007eff60 @ 0x007eff60 ====

void FUN_007eff60(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x70) = param_2;
  return;
}


// ==== FUN_007eff70 @ 0x007eff70 ====

void FUN_007eff70(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xb4) = param_2;
  return;
}


// ==== FUN_007eff80 @ 0x007eff80 ====

void FUN_007eff80(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xb8) = param_2;
  return;
}


// ==== FUN_007eff90 @ 0x007eff90 ====

undefined4 FUN_007eff90(int param_1,undefined4 param_2)

{
  if (*(char *)(param_1 + 0x10) == '\0') {
    *(undefined4 *)(param_1 + 0x30) = param_2;
  }
  return *(undefined4 *)(param_1 + 0x30);
}


// ==== FUN_007effb0 @ 0x007effb0 ====

void FUN_007effb0(int param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = param_3;
  for (uVar1 = param_2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  for (uVar1 = param_2 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  if (*(char *)(param_1 + 0x10) == '\0') {
    FUN_007d1600(param_1 + 0x58,0,0);
    FUN_007d1550(param_1 + 0x58,param_3,param_2);
  }
  return;
}


// ==== __break @ 0x007effff ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


