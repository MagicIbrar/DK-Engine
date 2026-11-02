// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x560000-0x56ffff

// ==== FUN_00560170 @ 0x00560170 ====

/* WARNING: Removing unreachable block (ram,0x005603e4) */
/* WARNING: Removing unreachable block (ram,0x00560490) */
/* WARNING: Removing unreachable block (ram,0x005605b6) */

void FUN_00560170(void)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  int *piVar4;
  void *pvVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  undefined4 unaff_EBX;
  void *unaff_ESI;
  byte ****ppppbVar10;
  byte *pbVar11;
  bool bVar12;
  bool bVar13;
  undefined4 in_stack_fffffcd8;
  uint in_stack_fffffcdc;
  undefined4 in_stack_fffffce0;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined1 auStack_2ec [4];
  byte ****appppbStack_2e8 [4];
  uint uStack_2d8;
  uint uStack_2d4;
  int iStack_2d0;
  int *piStack_2cc;
  int *piStack_2c8;
  undefined4 uStack_2c4;
  undefined4 uStack_2c0;
  undefined4 uStack_2bc;
  undefined4 uStack_2b8;
  undefined4 uStack_2b4;
  undefined4 uStack_2b0;
  undefined4 uStack_2ac;
  int *piStack_2a8;
  undefined4 uStack_2a4;
  undefined1 auStack_2a0 [4];
  undefined1 uStack_29c;
  undefined1 auStack_290 [4];
  undefined4 uStack_28c;
  undefined4 uStack_288;
  undefined4 uStack_284;
  undefined4 uStack_280;
  undefined1 uStack_278;
  undefined4 uStack_268;
  undefined4 uStack_264;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  undefined1 uStack_254;
  undefined1 uStack_253;
  undefined1 uStack_24c;
  undefined4 uStack_23c;
  undefined4 uStack_238;
  undefined4 uStack_234;
  undefined4 uStack_230;
  undefined4 uStack_22c;
  int iStack_228;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined1 auStack_218 [6];
  undefined1 uStack_212;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  undefined4 uStack_208;
  undefined4 uStack_204;
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  undefined4 auStack_1f8 [2];
  undefined1 uStack_1f0;
  undefined4 uStack_1e0;
  undefined4 auStack_1dc [2];
  undefined1 auStack_1d4 [8];
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1a0;
  undefined1 uStack_19c;
  undefined1 uStack_19b;
  undefined1 auStack_198 [4];
  void *pvStack_194;
  undefined4 uStack_184;
  uint uStack_180;
  undefined1 auStack_17c [4];
  void *pvStack_178;
  undefined4 uStack_168;
  uint uStack_164;
  undefined1 auStack_160 [4];
  void *pvStack_15c;
  undefined4 uStack_14c;
  uint uStack_148;
  undefined1 auStack_144 [4];
  void *pvStack_140;
  undefined4 uStack_130;
  uint uStack_12c;
  undefined1 auStack_128 [4];
  void *pvStack_124;
  undefined4 uStack_114;
  uint uStack_110;
  undefined1 auStack_10c [4];
  void *pvStack_108;
  undefined4 uStack_f8;
  uint uStack_f4;
  undefined1 auStack_f0 [4];
  void *pvStack_ec;
  undefined4 uStack_dc;
  uint uStack_d8;
  undefined1 auStack_d4 [4];
  void *pvStack_d0;
  undefined4 uStack_c0;
  uint uStack_bc;
  undefined1 auStack_b8 [4];
  void *pvStack_b4;
  undefined4 uStack_a4;
  uint uStack_a0;
  undefined1 auStack_9c [28];
  undefined1 auStack_80 [124];
  int *piStack_4;
  
  piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_212 = 1;
  uStack_210 = 0;
  uStack_20c = 0;
  uStack_208 = 0;
  uStack_204 = 0;
  uStack_200 = 0;
  uStack_1fc = 0;
  auStack_1f8[0] = 0;
  auStack_1dc[0] = 0xf;
  uStack_1e0 = 0;
  uStack_1f0 = 0;
  piStack_2c8 = piVar4;
  uStack_2a4 = (**(code **)(*DAT_00b5a7ac + 8))(1);
  uStack_238 = 0xf;
  uStack_23c = 0;
  uStack_24c = 0;
  uStack_234 = 0;
  uStack_230 = 0;
  uStack_22c = 0;
  uStack_2c0 = 0;
  uStack_2bc = 0;
  uStack_2b8 = 0;
  uStack_2b4 = 0;
  uStack_2b0 = 0;
  uStack_2ac = 0;
  piStack_2a8 = (int *)0x0;
  uStack_2d4 = 0xf;
  uStack_2d8 = 0;
  appppbStack_2e8[0] = (byte ****)((uint)appppbStack_2e8[0] & 0xffffff00);
  uStack_284 = 0;
  uStack_280 = 0;
  uStack_264 = 0xf;
  uStack_268 = 0;
  uStack_278 = 0;
  uStack_260 = 1;
  uStack_25c = 0;
  uStack_258 = 1;
  uStack_254 = 0;
  uStack_253 = 0;
  uStack_288 = 0xf;
  uStack_28c = 0;
  uStack_29c = 0;
  FUN_00401740(s_<_button>_009bc40c,9);
  pvVar5 = operator_new(0x468);
  if (pvVar5 == (void *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = FUN_00505f10();
  }
  *(undefined1 *)(iVar6 + 0x104) = 0;
  *(undefined1 *)(iVar6 + 0x105) = 0;
  *(undefined1 *)(iVar6 + 0x107) = 0;
  *(undefined1 *)(iVar6 + 0x10c) = 0;
  *(undefined4 *)(iVar6 + 0x108) = 0xc;
  *(undefined4 *)(iVar6 + 0x110) = 500;
  *(undefined1 *)(iVar6 + 0x106) = 0;
  *(undefined1 *)(iVar6 + 0x106) = 0;
  piStack_2c8 = (int *)0x1;
  uStack_2c4 = 1;
  cVar2 = FUN_005885f0();
  if (cVar2 != '\0') {
    do {
      uVar7 = FUN_00588600(auStack_b8);
      uVar14 = 0x560361;
      FUN_00401660(uVar7,0,0xffffffff);
      if (0xf < uStack_a0) {
        _free(pvStack_b4);
        return;
      }
      uStack_a0 = 0xf;
      uStack_a4 = 0;
      pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
      cVar2 = FUN_0055cad0(auStack_2ec);
      if (cVar2 != '\0') {
        FUN_00588700(auStack_2ec);
        break;
      }
      uVar16 = 0xf;
      uVar15 = 0;
      in_stack_fffffcdc = in_stack_fffffcdc & 0xffffff00;
      FUN_00401660(auStack_2ec,0,0xffffffff);
      FUN_0055cf30(auStack_218,iVar6,in_stack_fffffcd8,in_stack_fffffcdc,in_stack_fffffce0,uVar14,
                   uVar7,uVar15,uVar16);
      if (uStack_2d8 != 0) {
        uVar9 = uStack_2d8;
        if (3 < uStack_2d8) {
          uVar9 = 4;
        }
        ppppbVar10 = appppbStack_2e8[0];
        if (uStack_2d4 < 0x10) {
          ppppbVar10 = (byte ****)appppbStack_2e8;
        }
        bVar12 = false;
        iVar8 = 0;
        bVar13 = true;
        pbVar11 = &DAT_009bc418;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          bVar12 = *(byte *)ppppbVar10 < *pbVar11;
          bVar13 = *(byte *)ppppbVar10 == *pbVar11;
          ppppbVar10 = (byte ****)((int)ppppbVar10 + 1);
          pbVar11 = pbVar11 + 1;
        } while (bVar13);
        if (!bVar13) {
          iVar8 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        }
        if (((iVar8 == 0) && (3 < uStack_2d8)) && (uStack_2d8 == 4)) {
          uVar7 = FUN_00588600(auStack_198);
          uVar3 = thunk_FUN_00796f50(uVar7);
          *(undefined1 *)(iVar6 + 0x104) = uVar3;
          if (0xf < uStack_180) {
            _free(pvStack_194);
            return;
          }
          uStack_180 = 0xf;
          uStack_184 = 0;
          pvStack_194 = (void *)((uint)pvStack_194 & 0xffffff00);
        }
      }
      if (uStack_2d8 == 0) {
code_r0x005605b9:
        if (uStack_2d8 != 0) {
          uVar9 = uStack_2d8;
          if (4 < uStack_2d8) {
            uVar9 = 5;
          }
          ppppbVar10 = appppbStack_2e8[0];
          if (uStack_2d4 < 0x10) {
            ppppbVar10 = (byte ****)appppbStack_2e8;
          }
          bVar12 = false;
          iVar8 = 0;
          bVar13 = true;
          pbVar11 = (byte *)s_blink_009bc428;
          do {
            if (uVar9 == 0) break;
            uVar9 = uVar9 - 1;
            bVar12 = *(byte *)ppppbVar10 < *pbVar11;
            bVar13 = *(byte *)ppppbVar10 == *pbVar11;
            ppppbVar10 = (byte ****)((int)ppppbVar10 + 1);
            pbVar11 = pbVar11 + 1;
          } while (bVar13);
          if (!bVar13) {
            iVar8 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
          }
          if (((iVar8 == 0) && (4 < uStack_2d8)) && (uStack_2d8 == 5)) {
            iVar8 = FUN_00588600(auStack_144);
            in_stack_fffffce0 = 0x560630;
            iVar8 = FUN_00403620(0,*(undefined4 *)(iVar8 + 0x14),&DAT_009bc430,4);
            if (0xf < uStack_12c) {
              _free(pvStack_140);
              return;
            }
            uStack_12c = 0xf;
            uStack_130 = 0;
            pvStack_140 = (void *)((uint)pvStack_140 & 0xffffff00);
            if (iVar8 == 0) {
              *(undefined1 *)(iVar6 + 0x107) = 1;
            }
            goto LAB_00560b45;
          }
        }
        in_stack_fffffce0 = 0x560696;
        iVar8 = FUN_00403620(0,uStack_2d8,s_blinktime_009bc438,9);
        if (iVar8 == 0) {
          uVar7 = FUN_00588600(auStack_d4);
          uVar7 = thunk_FUN_00796fb0(uVar7);
          *(undefined4 *)(iVar6 + 0x110) = uVar7;
          if (0xf < uStack_bc) {
            _free(pvStack_d0);
            return;
          }
          uStack_bc = 0xf;
          uStack_c0 = 0;
          pvStack_d0 = (void *)((uint)pvStack_d0 & 0xffffff00);
        }
        else {
          iVar8 = FUN_00403620(0,uStack_2d8,s_check_009bc444,5);
          if (iVar8 == 0) {
            iVar8 = FUN_00588600(auStack_17c);
            in_stack_fffffce0 = 0x56073a;
            FUN_00403620(0,*(undefined4 *)(iVar8 + 0x14),&DAT_009bc44c,4);
            if (0xf < uStack_164) {
              _free(pvStack_178);
              return;
            }
            uStack_164 = 0xf;
            uStack_168 = 0;
            pvStack_178 = (void *)((uint)pvStack_178 & 0xffffff00);
          }
          else {
            in_stack_fffffce0 = 0x56079e;
            iVar8 = FUN_00403620(0,uStack_2d8,s_multiline_009bc454,9);
            if (iVar8 == 0) {
              uVar7 = FUN_00588600(auStack_160);
              uVar3 = thunk_FUN_00796fe0(uVar7);
              *(undefined1 *)(iVar6 + 0x105) = uVar3;
              if (0xf < uStack_148) {
                _free(pvStack_15c);
                return;
              }
              uStack_148 = 0xf;
              uStack_14c = 0;
              pvStack_15c = (void *)((uint)pvStack_15c & 0xffffff00);
            }
            else {
              in_stack_fffffce0 = 0x560817;
              iVar8 = FUN_00403620(0,uStack_2d8,s_align_009bc460,5);
              if (iVar8 == 0) {
                uVar7 = FUN_00588600(auStack_128);
                FUN_00401660(uVar7,0,0xffffffff);
                if (0xf < uStack_110) {
                  _free(pvStack_124);
                  return;
                }
                uStack_110 = 0xf;
                uStack_114 = 0;
                pvStack_124 = (void *)((uint)pvStack_124 & 0xffffff00);
                cVar2 = FUN_004036a0(auStack_2ec,s_center_009bc468);
                if (cVar2 == '\0') {
                  cVar2 = FUN_004036a0(auStack_2ec,s_right_009bc470);
                  *(byte *)(iVar6 + 0x106) = -(cVar2 != '\0') & 2;
                }
                else {
                  *(undefined1 *)(iVar6 + 0x106) = 1;
                }
              }
              else {
                cVar2 = FUN_004036a0(auStack_2ec,s_lineheight_009bc478);
                if (cVar2 != '\0') {
                  uVar7 = FUN_00588600(auStack_9c);
                  uVar7 = thunk_FUN_00796e60(uVar7);
                  *(undefined4 *)(iVar6 + 0x108) = uVar7;
                    /* WARNING: Subroutine does not return */
                  FUN_00446f10();
                }
                cVar2 = FUN_004036a0(auStack_2ec,s_sound_009bc484);
                if (cVar2 != '\0') {
                  uVar7 = FUN_00588600(auStack_80);
                  uVar3 = thunk_FUN_00796f50(uVar7);
                  *(undefined1 *)(iVar6 + 0x10c) = uVar3;
                    /* WARNING: Subroutine does not return */
                  FUN_00446f10();
                }
                cVar2 = FUN_004036a0(auStack_2ec,s_<image>_009bc48c);
                if (cVar2 == '\0') {
                  cVar2 = FUN_004036a0(auStack_2ec,s_<title>_009bc494);
                  if (cVar2 == '\0') {
                    cVar2 = FUN_00423420(auStack_2ec,auStack_2a0);
                    if (cVar2 != '\0') {
                      FUN_00588700(auStack_2ec);
                      break;
                    }
                  }
                  else {
                    FUN_00503fe0();
                    uStack_1cc = piStack_2c8;
                    uStack_1c8 = uStack_2c4;
                    iVar8 = FUN_0055e4c0(&uStack_1cc,&uStack_2b4);
                    if (iVar8 == 0) {
                      piStack_2c8 = (int *)uStack_1cc;
                      uStack_2c4 = uStack_1c8;
                    }
                    uStack_19c = *(undefined1 *)(iVar6 + 0x105);
                    uStack_1a0 = *(undefined4 *)(iVar6 + 0x108);
                    uStack_19b = *(undefined1 *)(iVar6 + 0x106);
                    iStack_2d0 = iVar8;
                    uVar7 = FUN_00504640(&iStack_2d0,&uStack_1cc);
                    FUN_00505600(auStack_1dc,uVar7);
                    FUN_00446f40();
                    uVar7 = FUN_0055ca40(&iStack_2d0,&uStack_2b4);
                    FUN_0056ad20(auStack_1d4,uVar7);
                    if (iVar8 == 0) {
                      FUN_005523f0(&uStack_1cc);
                    }
                    FUN_006c1c60();
                  }
                }
                else {
                  iStack_2d0 = FUN_0055d6d0(&uStack_2c0,&uStack_2b4);
                  uStack_224 = uStack_2c0;
                  uStack_220 = uStack_2bc;
                  uStack_21c = uStack_2b8;
                  iStack_228 = iStack_2d0;
                  FUN_0056ac60(auStack_1d4,&iStack_228);
                  uVar7 = FUN_0055ca40(&iStack_2d0,&uStack_2b4);
                  FUN_0056ad20(auStack_1dc,uVar7);
                }
              }
            }
          }
        }
      }
      else {
        uVar9 = uStack_2d8;
        if (6 < uStack_2d8) {
          uVar9 = 7;
        }
        ppppbVar10 = appppbStack_2e8[0];
        if (uStack_2d4 < 0x10) {
          ppppbVar10 = (byte ****)appppbStack_2e8;
        }
        bVar12 = false;
        iVar8 = 0;
        bVar13 = true;
        pbVar11 = (byte *)s_tooltip_009bc420;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          bVar12 = *(byte *)ppppbVar10 < *pbVar11;
          bVar13 = *(byte *)ppppbVar10 == *pbVar11;
          ppppbVar10 = (byte ****)((int)ppppbVar10 + 1);
          pbVar11 = pbVar11 + 1;
        } while (bVar13);
        if (!bVar13) {
          iVar8 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        }
        if (((iVar8 != 0) || (uStack_2d8 < 7)) || (uStack_2d8 != 7)) goto code_r0x005605b9;
        uVar7 = FUN_00588600(auStack_10c);
        iVar8 = thunk_FUN_00796e60(uVar7);
        if (0xf < uStack_f4) {
          _free(pvStack_108);
          return;
        }
        uStack_f4 = 0xf;
        uStack_f8 = 0;
        pvStack_108 = (void *)((uint)pvStack_108 & 0xffffff00);
        uVar7 = FUN_00588600(auStack_f0);
        uVar9 = thunk_FUN_00796e60(uVar7);
        if (0xf < uStack_d8) {
          _free(pvStack_ec);
          return;
        }
        uStack_d8 = 0xf;
        uStack_dc = 0;
        pvStack_ec = (void *)((uint)pvStack_ec & 0xffffff00);
        uVar7 = (**(code **)(*DAT_00b5a794 + 0xc))(0,iVar8 << 0x10 | uVar9);
        FUN_00401660(uVar7,0,0xffffffff);
      }
LAB_00560b45:
      cVar2 = FUN_005885f0();
    } while (cVar2 != '\0');
    piVar4 = piStack_2cc;
  }
  FUN_00401660(auStack_1f8,0,0xffffffff);
  (**(code **)(*piVar4 + 8))(auStack_218);
  if ((piStack_4 != (int *)0x0) && (cVar2 = (**(code **)(*piVar4 + 0x74))(piStack_4), cVar2 != '\0')
     ) {
    cVar2 = (**(code **)(*piStack_4 + 0x78))(piVar4);
    if (cVar2 == '\0') {
      (**(code **)(*piVar4 + 0x74))(0);
    }
    else {
      iVar6 = (**(code **)(*piStack_4 + 0x38))();
      piVar4[1] = iVar6;
    }
  }
  piVar1 = piStack_2a8;
  (**(code **)(*piStack_2a8 + 0x38))(piVar4);
  (**(code **)(*piVar1 + 0x1c))(&uStack_258);
  if ((char)((uint)unaff_EBX >> 0x18) != '\0') {
    (**(code **)(*piVar1 + 8))(auStack_290);
  }
  (**(code **)(*piVar4 + 0x2c))(piVar1);
  FUN_00569460(&uStack_2b0,piVar4);
  (**(code **)(*piVar1 + 0x24))(unaff_ESI);
  if (uStack_22c._1_1_ == '\0') {
    (**(code **)(*piVar4 + 0x44))(0);
  }
  else if ((char)((uint)unaff_ESI >> 0x10) != '\0') {
    FUN_00558730(1);
  }
  FUN_00505d80();
  _free(unaff_ESI);
  return;
}


// ==== FUN_00560d40 @ 0x00560d40 ====

/* WARNING: Removing unreachable block (ram,0x00560f84) */
/* WARNING: Removing unreachable block (ram,0x00561030) */
/* WARNING: Removing unreachable block (ram,0x005610de) */

void FUN_00560d40(void)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  int *piVar4;
  void *pvVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 ****ppppuVar9;
  uint uVar10;
  uint3 unaff_EBX;
  void *unaff_ESI;
  byte ****ppppbVar11;
  undefined4 unaff_EDI;
  byte *pbVar12;
  bool bVar13;
  bool bVar14;
  undefined4 in_stack_fffffe08;
  uint in_stack_fffffe0c;
  undefined4 in_stack_fffffe10;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  void *_Memory;
  int *piStack_1c0;
  int *piStack_1bc;
  byte ****appppbStack_1b8 [4];
  uint uStack_1a8;
  uint uStack_1a4;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined1 auStack_198 [4];
  void *pvStack_194;
  undefined4 uStack_184;
  uint uStack_180;
  void *pvStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 ****appppuStack_15c [4];
  undefined4 uStack_14c;
  int *piStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  uint uStack_134;
  undefined4 uStack_124;
  undefined4 uStack_120;
  void *pvStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined1 uStack_110;
  undefined1 uStack_10f;
  undefined4 uStack_10c;
  uint uStack_108;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  int iStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  void *pvStack_d4;
  undefined4 uStack_c4;
  uint uStack_c0;
  void *pvStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined1 uStack_b0;
  undefined1 uStack_af;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined1 auStack_9c [6];
  undefined1 uStack_96;
  undefined4 uStack_94;
  undefined4 uStack_90;
  void *pvStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  uint uStack_78;
  undefined1 uStack_74;
  undefined4 uStack_64;
  undefined4 auStack_60 [2];
  undefined1 auStack_58 [4];
  void *pvStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 auStack_3c [4];
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  int *piStack_4;
  
  piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_96 = 1;
  uStack_94 = 0;
  uStack_90 = 0;
  pvStack_8c = (void *)0x0;
  uStack_88 = 0;
  uStack_84 = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  auStack_60[0] = 0xf;
  uStack_64 = 0;
  uStack_74 = 0;
  piStack_1bc = piVar4;
  uStack_144 = (**(code **)(*DAT_00b5a7ac + 8))(0x13);
  uStack_f4 = 0xf;
  uStack_f8 = 0;
  uStack_108 = uStack_108 & 0xffffff00;
  uStack_f0 = 0;
  uStack_ec = 0;
  uStack_e8 = 0;
  uStack_16c = 0;
  uStack_168 = 0;
  uStack_164 = 0;
  uStack_1a4 = 0xf;
  uStack_1a8 = 0;
  appppbStack_1b8[0] = (byte ****)((uint)appppbStack_1b8[0] & 0xffffff00);
  _Memory = (void *)(uint)unaff_EBX;
  uStack_140 = 0;
  uStack_13c = 0;
  uStack_120 = 0xf;
  uStack_124 = 0;
  uStack_134 = uStack_134 & 0xffffff00;
  pvStack_11c = (void *)0x1;
  uStack_118 = 0;
  uStack_114 = 1;
  uStack_110 = 0;
  uStack_10f = 0;
  piStack_148 = (int *)0xf;
  uStack_14c = 0;
  appppuStack_15c[0] = (undefined4 ****)((uint)appppuStack_15c[0] & 0xffffff00);
  FUN_00401740(s_<_emoti>_009bc49c,8);
  pvVar5 = operator_new(0x468);
  if (pvVar5 == (void *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = FUN_00505f10();
  }
  *(undefined1 *)(iVar6 + 0x104) = 0;
  *(undefined1 *)(iVar6 + 0x105) = 0;
  *(undefined1 *)(iVar6 + 0x107) = 0;
  *(undefined1 *)(iVar6 + 0x10c) = 0;
  *(undefined4 *)(iVar6 + 0x108) = 0xc;
  *(undefined4 *)(iVar6 + 0x110) = 500;
  *(undefined1 *)(iVar6 + 0x106) = 0;
  cVar2 = FUN_005885f0();
  if (cVar2 != '\0') {
    do {
      uVar7 = FUN_00588600(auStack_20);
      uVar15 = 0x560f01;
      FUN_00401660(uVar7,0,0xffffffff);
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return;
      }
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      cVar2 = FUN_0055cad0(&piStack_1bc);
      if (cVar2 != '\0') {
        FUN_00588700(&piStack_1bc);
        break;
      }
      uVar17 = 0xf;
      uVar16 = 0;
      in_stack_fffffe0c = in_stack_fffffe0c & 0xffffff00;
      FUN_00401660(&piStack_1bc,0,0xffffffff);
      FUN_0055cf30(auStack_9c,iVar6,in_stack_fffffe08,in_stack_fffffe0c,in_stack_fffffe10,uVar15,
                   uVar7,uVar16,uVar17);
      if (uStack_1a8 != 0) {
        uVar10 = uStack_1a8;
        if (3 < uStack_1a8) {
          uVar10 = 4;
        }
        ppppbVar11 = appppbStack_1b8[0];
        if (uStack_1a4 < 0x10) {
          ppppbVar11 = (byte ****)appppbStack_1b8;
        }
        bVar13 = false;
        iVar8 = 0;
        bVar14 = true;
        pbVar12 = &DAT_009bc4a8;
        do {
          if (uVar10 == 0) break;
          uVar10 = uVar10 - 1;
          bVar13 = *(byte *)ppppbVar11 < *pbVar12;
          bVar14 = *(byte *)ppppbVar11 == *pbVar12;
          ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
          pbVar12 = pbVar12 + 1;
        } while (bVar14);
        if (!bVar14) {
          iVar8 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
        }
        if (((iVar8 == 0) && (3 < uStack_1a8)) && (uStack_1a8 == 4)) {
          uVar7 = FUN_00588600(auStack_58);
          uVar3 = thunk_FUN_00796f50(uVar7);
          *(undefined1 *)(iVar6 + 0x104) = uVar3;
          if (0xf < uStack_40) {
            _free(pvStack_54);
            return;
          }
          uStack_40 = 0xf;
          uStack_44 = 0;
          pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
        }
      }
      if (uStack_1a8 == 0) {
code_r0x005610e1:
        if (uStack_1a8 != 0) {
          uVar10 = uStack_1a8;
          if (6 < uStack_1a8) {
            uVar10 = 7;
          }
          ppppbVar11 = appppbStack_1b8[0];
          if (uStack_1a4 < 0x10) {
            ppppbVar11 = (byte ****)appppbStack_1b8;
          }
          bVar13 = false;
          iVar8 = 0;
          bVar14 = true;
          pbVar12 = (byte *)s_<image>_009bc4b8;
          do {
            if (uVar10 == 0) break;
            uVar10 = uVar10 - 1;
            bVar13 = *(byte *)ppppbVar11 < *pbVar12;
            bVar14 = *(byte *)ppppbVar11 == *pbVar12;
            ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
            pbVar12 = pbVar12 + 1;
          } while (bVar14);
          if (!bVar14) {
            iVar8 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
          }
          if (((iVar8 == 0) && (6 < uStack_1a8)) && (uStack_1a8 == 7)) {
            uStack_ac = FUN_0055d1f0(&uStack_16c);
            uStack_a8 = uStack_16c;
            uStack_a0 = uStack_164;
            uStack_a4 = uStack_168;
            FUN_0056ac60(auStack_60,&uStack_ac);
            goto LAB_0056136d;
          }
        }
        in_stack_fffffe10 = 0x561195;
        iVar8 = FUN_00403620(0,uStack_1a8,s_<title>_009bc4c0,7);
        if (iVar8 == 0) {
          uStack_1a0 = 0;
          uStack_19c = 0;
          uStack_180 = 0xf;
          uStack_184 = 0;
          pvStack_194 = (void *)((uint)pvStack_194 & 0xffffff00);
          pvStack_17c = (void *)0x1;
          uStack_178 = 0;
          uStack_174 = 1;
          uStack_170 = (void *)((uint)uStack_170 & 0xffff0000);
          iVar8 = FUN_0055dde0(&uStack_1a0);
          _Memory = (void *)CONCAT13(1,(int3)_Memory);
          uStack_e0 = uStack_1a0;
          uStack_dc = uStack_19c;
          uStack_c0 = 0xf;
          uStack_c4 = 0;
          pvStack_d4 = (void *)((uint)pvStack_d4 & 0xffffff00);
          iStack_e4 = iVar8;
          FUN_00401660(auStack_198,0,0xffffffff);
          uStack_b4 = uStack_174;
          pvStack_bc = pvStack_17c;
          uStack_b0 = (undefined1)uStack_170;
          uStack_b8 = uStack_178;
          uStack_af = uStack_170._1_1_;
          FUN_00505600(auStack_60,&iStack_e4);
          if (0xf < uStack_c0) {
            _free(pvStack_d4);
            return;
          }
          uStack_c0 = 0xf;
          uStack_c4 = 0;
          pvStack_d4 = (void *)((uint)pvStack_d4 & 0xffffff00);
          if (iVar8 == 0) {
            uStack_140 = uStack_1a0;
            uStack_13c = uStack_19c;
            FUN_00401660(auStack_198,0,0xffffffff);
            pvStack_11c = pvStack_17c;
            uStack_118 = uStack_178;
            uStack_114 = uStack_174;
            uStack_110 = (undefined1)uStack_170;
            uStack_10f = uStack_170._1_1_;
          }
          if (0xf < uStack_180) {
            _free(pvStack_194);
            return;
          }
          uStack_180 = 0xf;
          uStack_184 = 0;
          pvStack_194 = (void *)((uint)pvStack_194 & 0xffffff00);
        }
        else {
          ppppuVar9 = appppuStack_15c[0];
          if (piStack_148 < (int *)0x10) {
            ppppuVar9 = appppuStack_15c;
          }
          in_stack_fffffe10 = 0x561369;
          iVar8 = FUN_00403620(0,uStack_1a8,ppppuVar9,uStack_14c);
          if (iVar8 == 0) {
            FUN_00588700(&piStack_1bc);
            break;
          }
        }
      }
      else {
        uVar10 = uStack_1a8;
        if (6 < uStack_1a8) {
          uVar10 = 7;
        }
        ppppbVar11 = appppbStack_1b8[0];
        if (uStack_1a4 < 0x10) {
          ppppbVar11 = (byte ****)appppbStack_1b8;
        }
        bVar13 = false;
        iVar8 = 0;
        bVar14 = true;
        pbVar12 = (byte *)s_tooltip_009bc4b0;
        do {
          if (uVar10 == 0) break;
          uVar10 = uVar10 - 1;
          bVar13 = *(byte *)ppppbVar11 < *pbVar12;
          bVar14 = *(byte *)ppppbVar11 == *pbVar12;
          ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
          pbVar12 = pbVar12 + 1;
        } while (bVar14);
        if (!bVar14) {
          iVar8 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
        }
        if (((iVar8 != 0) || (uStack_1a8 < 7)) || (uStack_1a8 != 7)) goto code_r0x005610e1;
        uVar7 = FUN_00588600(auStack_3c);
        FUN_00401660(uVar7,0,0xffffffff);
        if (0xf < uStack_24) {
          _free(pvStack_38);
          return;
        }
        uStack_24 = 0xf;
        uStack_28 = 0;
        pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
      }
LAB_0056136d:
      cVar2 = FUN_005885f0();
    } while (cVar2 != '\0');
    piVar4 = piStack_1c0;
  }
  FUN_00401660(&uStack_7c,0,0xffffffff);
  (**(code **)(*piVar4 + 8))(auStack_9c);
  if ((piStack_4 != (int *)0x0) && (cVar2 = (**(code **)(*piVar4 + 0x74))(piStack_4), cVar2 != '\0')
     ) {
    cVar2 = (**(code **)(*piStack_4 + 0x78))(piVar4);
    if (cVar2 == '\0') {
      (**(code **)(*piVar4 + 0x74))(0);
    }
    else {
      iVar6 = (**(code **)(*piStack_4 + 0x38))();
      piVar4[1] = iVar6;
    }
  }
  piVar1 = piStack_148;
  (**(code **)(*piStack_148 + 0x38))(piVar4);
  (**(code **)(*piVar1 + 0x1c))(&uStack_114);
  if ((char)((uint)unaff_EDI >> 0x18) != '\0') {
    (**(code **)(*piVar1 + 8))(&uStack_14c);
  }
  (**(code **)(*piVar4 + 0x2c))(piVar1);
  FUN_00569460(&uStack_170,piVar4);
  (**(code **)(*piVar1 + 0x24))(unaff_ESI);
  if (unaff_ESI != (void *)0x0) {
    FUN_00505d80();
    _free(unaff_ESI);
    return;
  }
  if ((undefined4 ****)0xf < appppuStack_15c[0]) {
    _free(uStack_170);
    return;
  }
  appppuStack_15c[0] = (undefined4 ****)0xf;
  uStack_160 = 0;
  uStack_170 = (void *)((uint)uStack_170 & 0xffffff00);
  if (0xf < uStack_134) {
    _free(piStack_148);
    return;
  }
  uStack_134 = 0xf;
  uStack_138 = 0;
  piStack_148 = (int *)((uint)piStack_148 & 0xffffff00);
  if ((byte ****)0xf < appppbStack_1b8[0]) {
    _free(_Memory);
    return;
  }
  appppbStack_1b8[0] = (byte ****)0xf;
  piStack_1bc = (int *)0x0;
  if (0xf < uStack_108) {
    _free(pvStack_11c);
    return;
  }
  uStack_108 = 0xf;
  uStack_10c = 0;
  pvStack_11c = (void *)((uint)pvStack_11c & 0xffffff00);
  if (uStack_78 < 0x10) {
    return;
  }
  _free(pvStack_8c);
  return;
}


// ==== FUN_00561550 @ 0x00561550 ====

/* WARNING: Removing unreachable block (ram,0x0056179c) */
/* WARNING: Removing unreachable block (ram,0x00561852) */

void FUN_00561550(void)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  int *piVar4;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 ****ppppuVar7;
  uint uVar8;
  int iVar9;
  uint3 unaff_EBX;
  void *unaff_ESI;
  byte ****ppppbVar10;
  undefined4 unaff_EDI;
  byte *pbVar11;
  bool bVar12;
  bool bVar13;
  undefined4 in_stack_fffffe24;
  uint in_stack_fffffe28;
  undefined4 in_stack_fffffe2c;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  void *_Memory;
  int local_1a8;
  int *piStack_1a4;
  int *piStack_1a0;
  byte ****appppbStack_19c [4];
  uint uStack_18c;
  uint uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined1 auStack_17c [4];
  void *pvStack_178;
  undefined4 uStack_168;
  uint uStack_164;
  void *pvStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 ****appppuStack_140 [4];
  undefined4 uStack_130;
  int *piStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  uint uStack_118;
  undefined4 uStack_108;
  undefined4 uStack_104;
  void *pvStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined1 uStack_f4;
  undefined1 uStack_f3;
  undefined4 uStack_f0;
  uint uStack_ec;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  int iStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  void *pvStack_b8;
  undefined4 uStack_a8;
  uint uStack_a4;
  void *pvStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined1 uStack_94;
  undefined1 uStack_93;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined1 auStack_80 [6];
  undefined1 uStack_7a;
  undefined4 uStack_78;
  undefined4 uStack_74;
  void *pvStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined1 uStack_58;
  undefined4 uStack_48;
  undefined4 auStack_44 [2];
  undefined1 auStack_3c [4];
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  int *piStack_4;
  
  piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_7a = 1;
  uStack_78 = 0;
  uStack_74 = 0;
  pvStack_70 = (void *)0x0;
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  auStack_44[0] = 0xf;
  uStack_48 = 0;
  uStack_58 = 0;
  piStack_1a0 = piVar4;
  uStack_128 = (**(code **)(*DAT_00b5a7ac + 8))(0xb);
  uStack_d8 = 0xf;
  uStack_dc = 0;
  uStack_ec = uStack_ec & 0xffffff00;
  uStack_d4 = 0;
  uStack_d0 = 0;
  uStack_cc = 0;
  uStack_150 = 0;
  uStack_14c = 0;
  uStack_148 = 0;
  uStack_188 = 0xf;
  uStack_18c = 0;
  appppbStack_19c[0] = (byte ****)((uint)appppbStack_19c[0] & 0xffffff00);
  _Memory = (void *)(uint)unaff_EBX;
  uStack_124 = 0;
  uStack_120 = 0;
  uStack_104 = 0xf;
  uStack_108 = 0;
  uStack_118 = uStack_118 & 0xffffff00;
  pvStack_100 = (void *)0x1;
  uStack_fc = 0;
  uStack_f8 = 1;
  uStack_f4 = 0;
  uStack_f3 = 0;
  piStack_12c = (int *)0xf;
  uStack_130 = 0;
  appppuStack_140[0] = (undefined4 ****)((uint)appppuStack_140[0] & 0xffffff00);
  FUN_00401740(s_<_tab>_009bc4c8,6);
  pvVar5 = operator_new(0x468);
  if (pvVar5 == (void *)0x0) {
    local_1a8 = 0;
  }
  else {
    local_1a8 = FUN_00505f10();
  }
  *(undefined1 *)(local_1a8 + 0x1b0) = 1;
  FUN_00503950(*(undefined4 *)(*(int *)(local_1a8 + 0x1b8) + 4));
  *(int *)(*(int *)(local_1a8 + 0x1b8) + 4) = *(int *)(local_1a8 + 0x1b8);
  *(undefined4 *)(local_1a8 + 0x1bc) = 0;
  *(undefined4 *)*(undefined4 *)(local_1a8 + 0x1b8) = *(undefined4 *)(local_1a8 + 0x1b8);
  *(int *)(*(int *)(local_1a8 + 0x1b8) + 8) = *(int *)(local_1a8 + 0x1b8);
  cVar2 = FUN_005885f0();
  if (cVar2 != '\0') {
    do {
      uVar6 = FUN_00588600(auStack_3c);
      uVar14 = 0x56171d;
      FUN_00401660(uVar6,0,0xffffffff);
      if (0xf < uStack_24) {
        _free(pvStack_38);
        return;
      }
      uStack_24 = 0xf;
      uStack_28 = 0;
      pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
      cVar2 = FUN_0055cad0(&piStack_1a0);
      if (cVar2 != '\0') {
        FUN_00588700(&piStack_1a0);
        break;
      }
      uVar16 = 0xf;
      uVar15 = 0;
      in_stack_fffffe28 = in_stack_fffffe28 & 0xffffff00;
      FUN_00401660(&piStack_1a0,0,0xffffffff);
      FUN_0055cf30(auStack_80,local_1a8,in_stack_fffffe24,in_stack_fffffe28,in_stack_fffffe2c,uVar14
                   ,uVar6,uVar15,uVar16);
      piVar4 = piStack_1a4;
      if (uStack_18c == 0) {
code_r0x00561855:
        if (uStack_18c != 0) {
          uVar8 = uStack_18c;
          if (6 < uStack_18c) {
            uVar8 = 7;
          }
          ppppbVar10 = appppbStack_19c[0];
          if (uStack_188 < 0x10) {
            ppppbVar10 = (byte ****)appppbStack_19c;
          }
          bVar12 = false;
          iVar9 = 0;
          bVar13 = true;
          pbVar11 = (byte *)s_<image>_009bc4d8;
          do {
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            bVar12 = *(byte *)ppppbVar10 < *pbVar11;
            bVar13 = *(byte *)ppppbVar10 == *pbVar11;
            ppppbVar10 = (byte ****)((int)ppppbVar10 + 1);
            pbVar11 = pbVar11 + 1;
          } while (bVar13);
          if (!bVar13) {
            iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
          }
          if (((iVar9 == 0) && (6 < uStack_18c)) && (uStack_18c == 7)) {
            uStack_90 = FUN_0055d1f0(&uStack_150);
            uStack_8c = uStack_150;
            uStack_88 = uStack_14c;
            uStack_84 = uStack_148;
            FUN_0056ac60(auStack_44,&uStack_90);
            goto LAB_00561ae4;
          }
        }
        in_stack_fffffe2c = 0x561911;
        iVar9 = FUN_00403620(0,uStack_18c,s_<title>_009bc4e0,7);
        if (iVar9 == 0) {
          pvStack_160 = (void *)0x1;
          uStack_158 = 1;
          uStack_184 = 0;
          uStack_180 = 0;
          uStack_164 = 0xf;
          uStack_168 = 0;
          pvStack_178 = (void *)((uint)pvStack_178 & 0xffffff00);
          uStack_15c = 0;
          uStack_154 = (void *)((uint)uStack_154 & 0xffff0000);
          iVar9 = FUN_0055dde0(&uStack_184);
          uStack_c4 = uStack_184;
          _Memory = (void *)CONCAT13(1,(int3)_Memory);
          uStack_c0 = uStack_180;
          uStack_a4 = 0xf;
          uStack_a8 = 0;
          pvStack_b8 = (void *)((uint)pvStack_b8 & 0xffffff00);
          iStack_c8 = iVar9;
          FUN_00401660(auStack_17c,0,0xffffffff);
          pvStack_a0 = pvStack_160;
          uStack_98 = uStack_158;
          uStack_94 = (undefined1)uStack_154;
          uStack_9c = uStack_15c;
          uStack_93 = uStack_154._1_1_;
          FUN_00505600(auStack_44,&iStack_c8);
          if (0xf < uStack_a4) {
            _free(pvStack_b8);
            return;
          }
          uStack_a4 = 0xf;
          uStack_a8 = 0;
          pvStack_b8 = (void *)((uint)pvStack_b8 & 0xffffff00);
          if (iVar9 == 0) {
            uStack_120 = uStack_180;
            uStack_124 = uStack_184;
            FUN_00401660(auStack_17c,0,0xffffffff);
            pvStack_100 = pvStack_160;
            uStack_fc = uStack_15c;
            uStack_f8 = uStack_158;
            uStack_f4 = (undefined1)uStack_154;
            uStack_f3 = uStack_154._1_1_;
          }
          if (0xf < uStack_164) {
            _free(pvStack_178);
            return;
          }
          uStack_164 = 0xf;
          uStack_168 = 0;
          pvStack_178 = (void *)((uint)pvStack_178 & 0xffffff00);
        }
        else {
          ppppuVar7 = appppuStack_140[0];
          if (piStack_12c < (int *)0x10) {
            ppppuVar7 = appppuStack_140;
          }
          in_stack_fffffe2c = 0x561ae0;
          iVar9 = FUN_00403620(0,uStack_18c,ppppuVar7,uStack_130);
          if (iVar9 == 0) {
            FUN_00588700(&piStack_1a0);
            break;
          }
        }
      }
      else {
        uVar8 = uStack_18c;
        if (3 < uStack_18c) {
          uVar8 = 4;
        }
        ppppbVar10 = appppbStack_19c[0];
        if (uStack_188 < 0x10) {
          ppppbVar10 = (byte ****)appppbStack_19c;
        }
        bVar12 = false;
        iVar9 = 0;
        bVar13 = true;
        pbVar11 = &DAT_009bc4d0;
        do {
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          bVar12 = *(byte *)ppppbVar10 < *pbVar11;
          bVar13 = *(byte *)ppppbVar10 == *pbVar11;
          ppppbVar10 = (byte ****)((int)ppppbVar10 + 1);
          pbVar11 = pbVar11 + 1;
        } while (bVar13);
        if (!bVar13) {
          iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        }
        if (((iVar9 != 0) || (uStack_18c < 4)) || (uStack_18c != 4)) goto code_r0x00561855;
        uVar6 = FUN_00588600(auStack_20);
        uVar3 = thunk_FUN_00796fe0(uVar6);
        *(undefined1 *)(local_1a8 + 0x1b0) = uVar3;
        if (0xf < uStack_8) {
          _free(pvStack_1c);
          return;
        }
        uStack_8 = 0xf;
        uStack_c = 0;
        pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      }
LAB_00561ae4:
      cVar2 = FUN_005885f0();
    } while (cVar2 != '\0');
  }
  FUN_00401660(&uStack_60,0,0xffffffff);
  (**(code **)(*piVar4 + 8))(auStack_80);
  if ((piStack_4 != (int *)0x0) && (cVar2 = (**(code **)(*piVar4 + 0x74))(piStack_4), cVar2 != '\0')
     ) {
    cVar2 = (**(code **)(*piStack_4 + 0x78))(piVar4);
    if (cVar2 == '\0') {
      (**(code **)(*piVar4 + 0x74))(0);
    }
    else {
      iVar9 = (**(code **)(*piStack_4 + 0x38))();
      piVar4[1] = iVar9;
    }
  }
  piVar1 = piStack_12c;
  (**(code **)(*piStack_12c + 0x38))(piVar4);
  (**(code **)(*piVar1 + 0x1c))(&uStack_f8);
  if ((char)((uint)unaff_EDI >> 0x18) != '\0') {
    (**(code **)(*piVar1 + 8))(&uStack_130);
  }
  (**(code **)(*piVar4 + 0x2c))(piVar1);
  FUN_00569460(&uStack_154,piVar4);
  (**(code **)(*piVar1 + 0x24))(unaff_ESI);
  if (unaff_ESI != (void *)0x0) {
    FUN_00505d80();
    _free(unaff_ESI);
    return;
  }
  if ((undefined4 ****)0xf < appppuStack_140[0]) {
    _free(uStack_154);
    return;
  }
  appppuStack_140[0] = (undefined4 ****)0xf;
  uStack_144 = 0;
  uStack_154 = (void *)((uint)uStack_154 & 0xffffff00);
  if (0xf < uStack_118) {
    _free(piStack_12c);
    return;
  }
  uStack_118 = 0xf;
  uStack_11c = 0;
  piStack_12c = (int *)((uint)piStack_12c & 0xffffff00);
  if ((byte ****)0xf < appppbStack_19c[0]) {
    _free(_Memory);
    return;
  }
  appppbStack_19c[0] = (byte ****)0xf;
  piStack_1a0 = (int *)0x0;
  if (0xf < uStack_ec) {
    _free(pvStack_100);
    return;
  }
  uStack_ec = 0xf;
  uStack_f0 = 0;
  pvStack_100 = (void *)((uint)pvStack_100 & 0xffffff00);
  if (uStack_5c < 0x10) {
    return;
  }
  _free(pvStack_70);
  return;
}


// ==== FUN_00561cc0 @ 0x00561cc0 ====

/* WARNING: Removing unreachable block (ram,0x00561f26) */

void FUN_00561cc0(void)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  void *pvVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int *unaff_EBX;
  int *unaff_EBP;
  int *unaff_ESI;
  byte *****pppppbVar9;
  int *unaff_EDI;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  undefined4 in_stack_fffffe10;
  uint in_stack_fffffe14;
  undefined4 in_stack_fffffe18;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 local_1bc;
  byte *****apppppbStack_1b8 [3];
  void *pvStack_1ac;
  uint uStack_1a8;
  int *piStack_1a4;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  uint uStack_198;
  void *pvStack_190;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  uint uStack_17c;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined1 auStack_158 [6];
  undefined1 uStack_152;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  void *pvStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  uint uStack_134;
  undefined1 uStack_130;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  void *pvStack_118;
  undefined4 uStack_108;
  uint uStack_104;
  undefined1 auStack_100 [4];
  void *pvStack_fc;
  undefined4 uStack_ec;
  uint uStack_e8;
  undefined1 auStack_e4 [4];
  void *pvStack_e0;
  undefined4 uStack_d0;
  uint uStack_cc;
  undefined1 auStack_c8 [4];
  void *pvStack_c4;
  undefined4 uStack_b4;
  uint uStack_b0;
  undefined1 auStack_ac [4];
  void *pvStack_a8;
  undefined4 uStack_98;
  uint uStack_94;
  undefined1 auStack_90 [4];
  void *pvStack_8c;
  undefined4 uStack_7c;
  uint uStack_78;
  undefined1 auStack_74 [4];
  void *pvStack_70;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined1 auStack_58 [28];
  undefined1 auStack_3c [28];
  undefined1 auStack_20 [28];
  int *piStack_4;
  
  (**(code **)(*DAT_00b5a7ac + 4))();
  uStack_152 = 1;
  uStack_150 = 0;
  uStack_14c = 0;
  pvStack_148 = (void *)0x0;
  uStack_144 = 0;
  uStack_140 = 0;
  uStack_13c = 0;
  uStack_138 = 0;
  uStack_11c = 0xf;
  uStack_120 = 0;
  uStack_130 = 0;
  uVar16 = 2;
  uStack_1a0 = (**(code **)(*DAT_00b5a7ac + 8))(2);
  uStack_168 = 0xf;
  uStack_16c = 0;
  uStack_17c = uStack_17c & 0xffffff00;
  uStack_164 = 0;
  uStack_160 = 0;
  uStack_15c = 0;
  piStack_1a4 = (int *)0xf;
  uStack_1a8 = 0;
  apppppbStack_1b8[0] = (byte *****)((uint)apppppbStack_1b8[0] & 0xffffff00);
  uStack_184 = 0xf;
  uStack_188 = 0;
  uStack_198 = uStack_198 & 0xffffff00;
  FUN_00401740(s_<_edit>_009bc4e8,7);
  pvVar5 = operator_new(0x468);
  if (pvVar5 == (void *)0x0) {
    pvVar5 = (void *)0x0;
  }
  else {
    pvVar5 = (void *)FUN_00505f10();
  }
  *(undefined4 *)((int)pvVar5 + 0x10) = 0xff000000;
  *(undefined2 *)((int)pvVar5 + 0x30) = 0xfa;
  *(undefined1 *)((int)pvVar5 + 0x36) = 0;
  *(undefined1 *)((int)pvVar5 + 0x35) = 0;
  *(undefined1 *)((int)pvVar5 + 0x37) = 1;
  *(undefined1 *)((int)pvVar5 + 0x32) = 3;
  *(undefined1 *)((int)pvVar5 + 0x33) = 0;
  *(undefined1 *)((int)pvVar5 + 0x34) = 0;
  cVar2 = FUN_005885f0();
  do {
    if (cVar2 == '\0') {
LAB_0056230b:
      FUN_00401660(&uStack_138,0,0xffffffff);
      (**(code **)(*unaff_EBX + 8))(auStack_158);
      if ((piStack_4 != (int *)0x0) &&
         (cVar2 = (**(code **)(*unaff_EBP + 0x74))(piStack_4), cVar2 != '\0')) {
        cVar2 = (**(code **)(*piStack_4 + 0x78))(unaff_EBP);
        if (cVar2 == '\0') {
          (**(code **)(*unaff_ESI + 0x74))(0);
        }
        else {
          iVar8 = (**(code **)(*piStack_4 + 0x38))();
          unaff_EBP[1] = iVar8;
        }
      }
      piVar1 = piStack_1a4;
      (**(code **)(*piStack_1a4 + 0x38))(unaff_EBP);
      (**(code **)(*piVar1 + 0x1c))(&uStack_188);
      (**(code **)(*unaff_EDI + 0x2c))(piVar1);
      FUN_00569460(&pvStack_1ac,uVar16);
      (**(code **)(*piVar1 + 0x24))(pvVar5);
      if (pvVar5 != (void *)0x0) {
        FUN_00505d80();
        _free(pvVar5);
        return;
      }
      if (0xf < uStack_198) {
        _free(pvStack_1ac);
        return;
      }
      uStack_198 = 0xf;
      uStack_19c = 0;
      pvStack_1ac = (void *)((uint)pvStack_1ac & 0xffffff00);
      if ((byte *****)0xf < apppppbStack_1b8[0]) {
        _free(unaff_ESI);
        return;
      }
      apppppbStack_1b8[0] = (byte *****)0xf;
      local_1bc = 0;
      if (0xf < uStack_17c) {
        _free(pvStack_190);
        return;
      }
      uStack_17c = 0xf;
      uStack_180 = 0;
      pvStack_190 = (void *)((uint)pvStack_190 & 0xffffff00);
      if (uStack_134 < 0x10) {
        return;
      }
      _free(pvStack_148);
      return;
    }
    uVar6 = FUN_00588600(auStack_ac);
    uVar13 = 0x561df1;
    FUN_00401660(uVar6,0,0xffffffff);
    if (0xf < uStack_94) {
      _free(pvStack_a8);
      return;
    }
    uStack_94 = 0xf;
    uStack_98 = 0;
    pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
    cVar2 = FUN_0055cad0(&local_1bc);
    if (cVar2 != '\0') {
LAB_00562303:
      FUN_00588700(&local_1bc);
      goto LAB_0056230b;
    }
    uVar15 = 0xf;
    uVar14 = 0;
    in_stack_fffffe14 = in_stack_fffffe14 & 0xffffff00;
    FUN_00401660(&local_1bc,0,0xffffffff);
    FUN_0055cf30(auStack_158,pvVar5,in_stack_fffffe10,in_stack_fffffe14,in_stack_fffffe18,uVar13,
                 uVar6,uVar14,uVar15);
    if (uStack_1a8 == 0) {
code_r0x00561f29:
      if (uStack_1a8 != 0) {
        uVar7 = uStack_1a8;
        if (8 < uStack_1a8) {
          uVar7 = 9;
        }
        pppppbVar9 = apppppbStack_1b8[0];
        if (piStack_1a4 < (int *)0x10) {
          pppppbVar9 = (byte *****)apppppbStack_1b8;
        }
        bVar11 = false;
        iVar8 = 0;
        bVar12 = true;
        pbVar10 = (byte *)s_font_type_009bc4fc;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          bVar11 = *(byte *)pppppbVar9 < *pbVar10;
          bVar12 = *(byte *)pppppbVar9 == *pbVar10;
          pppppbVar9 = (byte *****)((int)pppppbVar9 + 1);
          pbVar10 = pbVar10 + 1;
        } while (bVar12);
        if (!bVar12) {
          iVar8 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        }
        if (((iVar8 == 0) && (8 < uStack_1a8)) && (uStack_1a8 == 9)) {
          uVar6 = FUN_00588600(auStack_90);
          uVar3 = thunk_FUN_00796f50(uVar6);
          *(undefined1 *)((int)pvVar5 + 0x32) = uVar3;
          if (0xf < uStack_78) {
            _free(pvStack_8c);
            return;
          }
          uStack_78 = 0xf;
          uStack_7c = 0;
          pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
          goto LAB_005622e5;
        }
      }
      in_stack_fffffe18 = 0x561fe7;
      iVar8 = FUN_00403620(0,uStack_1a8,s_input_type_009bc508,10);
      if (iVar8 == 0) {
        uVar6 = FUN_00588600(&uStack_11c);
        uVar3 = thunk_FUN_00796f50(uVar6);
        *(undefined1 *)((int)pvVar5 + 0x33) = uVar3;
        if (0xf < uStack_104) {
          _free(pvStack_118);
          return;
        }
        uStack_104 = 0xf;
        uStack_108 = 0;
        pvStack_118 = (void *)((uint)pvStack_118 & 0xffffff00);
      }
      else {
        iVar8 = FUN_00403620(0,uStack_1a8,s_align_009bc514,5);
        if (iVar8 == 0) {
          uVar6 = FUN_00588600(auStack_c8);
          FUN_00401660(uVar6,0,0xffffffff);
          if (0xf < uStack_b0) {
            _free(pvStack_c4);
            return;
          }
          uStack_b0 = 0xf;
          uStack_b4 = 0;
          pvStack_c4 = (void *)((uint)pvStack_c4 & 0xffffff00);
          in_stack_fffffe18 = 0x5620c1;
          iVar8 = FUN_00403620(0,uStack_1a8,s_center_009bc51c,6);
          if (iVar8 == 0) {
            *(undefined1 *)((int)pvVar5 + 0x34) = 1;
          }
          else {
            in_stack_fffffe18 = 0x5620e4;
            iVar8 = FUN_00403620(0,uStack_1a8,s_right_009bc524,5);
            if (iVar8 == 0) {
              *(undefined1 *)((int)pvVar5 + 0x34) = 2;
            }
            else {
              cVar2 = FUN_004036a0(&local_1bc,&DAT_009bc52c);
              *(byte *)((int)pvVar5 + 0x34) = -(cVar2 != '\0') & 3;
            }
          }
        }
        else {
          in_stack_fffffe18 = 0x562128;
          iVar8 = FUN_00403620(0,uStack_1a8,s_init_text_009bc534,9);
          if (iVar8 == 0) {
            uVar6 = FUN_00588600(auStack_100);
            FUN_00401660(uVar6,0,0xffffffff);
            if (0xf < uStack_e8) {
              _free(pvStack_fc);
              return;
            }
            uStack_e8 = 0xf;
            uStack_ec = 0;
            pvStack_fc = (void *)((uint)pvStack_fc & 0xffffff00);
          }
          else {
            in_stack_fffffe18 = 0x562195;
            iVar8 = FUN_00403620(0,uStack_1a8,s_color_009bc540,5);
            if (iVar8 == 0) {
              uVar6 = FUN_00588600(auStack_e4);
              uVar6 = thunk_FUN_00796e90(uVar6);
              *(undefined4 *)((int)pvVar5 + 0x10) = uVar6;
              if (0xf < uStack_cc) {
                _free(pvStack_e0);
                return;
              }
              uStack_cc = 0xf;
              uStack_d0 = 0;
              pvStack_e0 = (void *)((uint)pvStack_e0 & 0xffffff00);
            }
            else {
              cVar2 = FUN_004036a0(&local_1bc,s_passwd_009bc548);
              if (cVar2 != '\0') {
                uVar16 = FUN_00588600(auStack_58);
                uVar3 = thunk_FUN_00796fe0(uVar16);
                *(undefined1 *)((int)pvVar5 + 0x35) = uVar3;
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              cVar2 = FUN_004036a0(&local_1bc,&DAT_009bc550);
              if (cVar2 != '\0') {
                uVar16 = FUN_00588600(auStack_3c);
                uVar3 = thunk_FUN_00796fe0(uVar16);
                *(undefined1 *)((int)pvVar5 + 0x37) = uVar3;
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              cVar2 = FUN_004036a0(&local_1bc,s_multiline_009bc554);
              if (cVar2 != '\0') {
                uVar16 = FUN_00588600(auStack_20);
                uVar3 = thunk_FUN_00796fe0(uVar16);
                *(undefined1 *)((int)pvVar5 + 0x36) = uVar3;
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              cVar2 = FUN_004036a0(&local_1bc,s_<image>_009bc560);
              if (cVar2 == '\0') {
                cVar2 = FUN_00423420(&local_1bc,&uStack_19c);
                if (cVar2 != '\0') goto LAB_00562303;
              }
              else {
                FUN_0055d1f0(pvVar5);
              }
            }
          }
        }
      }
    }
    else {
      uVar7 = uStack_1a8;
      if (8 < uStack_1a8) {
        uVar7 = 9;
      }
      pppppbVar9 = apppppbStack_1b8[0];
      if (piStack_1a4 < (int *)0x10) {
        pppppbVar9 = (byte *****)apppppbStack_1b8;
      }
      bVar11 = false;
      iVar8 = 0;
      bVar12 = true;
      pbVar10 = (byte *)s_maxlength_009bc4f0;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        bVar11 = *(byte *)pppppbVar9 < *pbVar10;
        bVar12 = *(byte *)pppppbVar9 == *pbVar10;
        pppppbVar9 = (byte *****)((int)pppppbVar9 + 1);
        pbVar10 = pbVar10 + 1;
      } while (bVar12);
      if (!bVar12) {
        iVar8 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      }
      if (((iVar8 != 0) || (uStack_1a8 < 9)) || (uStack_1a8 != 9)) goto code_r0x00561f29;
      uVar6 = FUN_00588600(auStack_74);
      uVar4 = thunk_FUN_00796f80(uVar6);
      *(undefined2 *)((int)pvVar5 + 0x30) = uVar4;
      if (0xf < uStack_5c) {
        _free(pvStack_70);
        return;
      }
      uStack_5c = 0xf;
      uStack_60 = 0;
      pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
    }
LAB_005622e5:
    cVar2 = FUN_005885f0();
  } while( true );
}


// ==== FUN_00562450 @ 0x00562450 ====

/* WARNING: Removing unreachable block (ram,0x0056264a) */
/* WARNING: Removing unreachable block (ram,0x005626fd) */

void FUN_00562450(void)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 ******ppppppuVar6;
  uint uVar7;
  int iVar8;
  void *unaff_ESI;
  byte ******ppppppbVar9;
  undefined4 unaff_EDI;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  undefined4 in_stack_fffffeb4;
  uint in_stack_fffffeb8;
  undefined4 in_stack_fffffebc;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int local_118;
  int *piStack_114;
  int *piStack_110;
  byte ******appppppbStack_10c [3];
  undefined1 auStack_100 [4];
  uint uStack_fc;
  int *piStack_f8;
  undefined4 uStack_f4;
  undefined4 ******appppppuStack_ec [3];
  undefined1 auStack_e0 [4];
  undefined4 uStack_dc;
  uint uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined1 uStack_c8;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined1 uStack_a4;
  undefined1 uStack_a3;
  undefined1 uStack_9c;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined1 auStack_78 [6];
  undefined1 uStack_72;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 auStack_58 [2];
  undefined1 uStack_50;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  int *piStack_4;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_72 = 1;
  uStack_70 = 0;
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  auStack_58[0] = 0;
  uStack_3c = 0xf;
  uStack_40 = 0;
  uStack_50 = 0;
  piStack_110 = piVar3;
  uStack_f4 = (**(code **)(*DAT_00b5a7ac + 8))(3);
  uStack_88 = 0xf;
  uStack_8c = 0;
  uStack_9c = 0;
  uStack_84 = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  piStack_f8 = (int *)0xf;
  uStack_fc = 0;
  appppppbStack_10c[0] = (byte ******)((uint)appppppbStack_10c[0] & 0xffffff00);
  uStack_d4 = 0;
  uStack_d0 = 0;
  uStack_b4 = 0xf;
  uStack_b8 = 0;
  uStack_c8 = 0;
  uStack_b0 = 1;
  uStack_ac = 0;
  uStack_a8 = 1;
  uStack_a4 = 0;
  uStack_a3 = 0;
  uStack_d8 = 0xf;
  uStack_dc = 0;
  appppppuStack_ec[0] = (undefined4 ******)((uint)appppppuStack_ec[0] & 0xffffff00);
  FUN_00401740(s_<_processbar>_009bc568,0xd);
  pvVar4 = operator_new(0x468);
  if (pvVar4 == (void *)0x0) {
    local_118 = 0;
  }
  else {
    local_118 = FUN_00505f10();
  }
  *(undefined4 *)(local_118 + 0x68) = 100;
  cVar2 = FUN_005885f0();
  do {
    if (cVar2 == '\0') {
LAB_005627e3:
      FUN_00401660(auStack_58,0,0xffffffff);
      (**(code **)(*piVar3 + 8))(auStack_78);
      if ((piStack_4 != (int *)0x0) &&
         (cVar2 = (**(code **)(*piVar3 + 0x74))(piStack_4), cVar2 != '\0')) {
        cVar2 = (**(code **)(*piStack_4 + 0x78))(piVar3);
        if (cVar2 == '\0') {
          (**(code **)(*piVar3 + 0x74))(0);
        }
        else {
          iVar8 = (**(code **)(*piStack_4 + 0x38))();
          piVar3[1] = iVar8;
        }
      }
      piVar1 = piStack_f8;
      (**(code **)(*piStack_f8 + 0x38))(piVar3);
      (**(code **)(*piVar1 + 0x1c))(&uStack_a8);
      if ((char)((uint)unaff_EDI >> 0x18) != '\0') {
        (**(code **)(*piVar1 + 8))(auStack_e0);
      }
      (**(code **)(*piVar3 + 0x2c))(piVar1);
      FUN_00569460(auStack_100,piVar3);
      (**(code **)(*piVar1 + 0x24))(unaff_ESI);
      FUN_00505d80();
      _free(unaff_ESI);
      return;
    }
    uVar5 = FUN_00588600(auStack_20);
    uVar13 = 0x5625d0;
    FUN_00401660(uVar5,0,0xffffffff);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    cVar2 = FUN_0055cad0(&piStack_110);
    if (cVar2 != '\0') {
      FUN_00588700(&piStack_110);
      goto LAB_005627e3;
    }
    uVar15 = 0xf;
    uVar14 = 0;
    in_stack_fffffeb8 = in_stack_fffffeb8 & 0xffffff00;
    FUN_00401660(&piStack_110,0,0xffffffff);
    FUN_0055cf30(auStack_78,local_118,in_stack_fffffeb4,in_stack_fffffeb8,in_stack_fffffebc,uVar13,
                 uVar5,uVar14,uVar15);
    piVar3 = piStack_114;
    if (uStack_fc == 0) {
code_r0x00562700:
      if (uStack_fc != 0) {
        uVar7 = uStack_fc;
        if (6 < uStack_fc) {
          uVar7 = 7;
        }
        ppppppbVar9 = appppppbStack_10c[0];
        if (piStack_f8 < (int *)0x10) {
          ppppppbVar9 = (byte ******)appppppbStack_10c;
        }
        bVar11 = false;
        iVar8 = 0;
        bVar12 = true;
        pbVar10 = (byte *)s_<image>_009bc580;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          bVar11 = *(byte *)ppppppbVar9 < *pbVar10;
          bVar12 = *(byte *)ppppppbVar9 == *pbVar10;
          ppppppbVar9 = (byte ******)((int)ppppppbVar9 + 1);
          pbVar10 = pbVar10 + 1;
        } while (bVar12);
        if (!bVar12) {
          iVar8 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        }
        if (((iVar8 == 0) && (6 < uStack_fc)) && (uStack_fc == 7)) {
          FUN_0055d1f0(local_118);
          goto LAB_005627ad;
        }
      }
      in_stack_fffffebc = 0x56276e;
      iVar8 = FUN_00403620(0,uStack_fc,s_<title>_009bc588,7);
      if (iVar8 == 0) {
        FUN_0055dde0(&uStack_d4);
      }
      else {
        ppppppuVar6 = appppppuStack_ec[0];
        if (uStack_d8 < 0x10) {
          ppppppuVar6 = appppppuStack_ec;
        }
        in_stack_fffffebc = 0x5627a9;
        iVar8 = FUN_00403620(0,uStack_fc,ppppppuVar6,uStack_dc);
        if (iVar8 == 0) {
          FUN_00588700(&piStack_110);
          goto LAB_005627e3;
        }
      }
    }
    else {
      uVar7 = uStack_fc;
      if (6 < uStack_fc) {
        uVar7 = 7;
      }
      ppppppbVar9 = appppppbStack_10c[0];
      if (piStack_f8 < (int *)0x10) {
        ppppppbVar9 = (byte ******)appppppbStack_10c;
      }
      bVar11 = false;
      iVar8 = 0;
      bVar12 = true;
      pbVar10 = (byte *)s_maxsize_009bc578;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        bVar11 = *(byte *)ppppppbVar9 < *pbVar10;
        bVar12 = *(byte *)ppppppbVar9 == *pbVar10;
        ppppppbVar9 = (byte ******)((int)ppppppbVar9 + 1);
        pbVar10 = pbVar10 + 1;
      } while (bVar12);
      if (!bVar12) {
        iVar8 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      }
      if (((iVar8 != 0) || (uStack_fc < 7)) || (uStack_fc != 7)) goto code_r0x00562700;
      uVar5 = FUN_00588600(&uStack_3c);
      uVar5 = thunk_FUN_00796e60(uVar5);
      *(undefined4 *)(local_118 + 0x68) = uVar5;
      if (0xf < uStack_24) {
        _free(pvStack_38);
        return;
      }
      uStack_24 = 0xf;
      uStack_28 = 0;
      pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    }
LAB_005627ad:
    cVar2 = FUN_005885f0();
  } while( true );
}


// ==== FUN_00562960 @ 0x00562960 ====

/* WARNING: Removing unreachable block (ram,0x00562b09) */
/* WARNING: Removing unreachable block (ram,0x00562bbc) */
/* WARNING: Removing unreachable block (ram,0x00562d98) */
/* WARNING: Removing unreachable block (ram,0x00562da3) */
/* WARNING: Removing unreachable block (ram,0x00562db0) */
/* WARNING: Removing unreachable block (ram,0x00562dd4) */
/* WARNING: Removing unreachable block (ram,0x00562de6) */
/* WARNING: Removing unreachable block (ram,0x00562df3) */
/* WARNING: Removing unreachable block (ram,0x00562e18) */
/* WARNING: Removing unreachable block (ram,0x00562e08) */
/* WARNING: Removing unreachable block (ram,0x00562dc7) */

void FUN_00562960(void)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  void *pvVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 ******ppppppuVar7;
  int *in_ECX;
  uint uVar8;
  int iVar9;
  byte ******ppppppbVar10;
  byte *pbVar11;
  bool bVar12;
  bool bVar13;
  undefined4 in_stack_fffffed0;
  uint in_stack_fffffed4;
  undefined4 in_stack_fffffed8;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int *piStack_f8;
  byte ******appppppbStack_f4 [2];
  undefined1 auStack_ec [8];
  uint uStack_e4;
  uint uStack_e0;
  undefined4 ******appppppuStack_d8 [4];
  undefined4 uStack_c8;
  int *piStack_c4;
  undefined4 uStack_c0;
  uint uStack_b8;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined1 auStack_94 [6];
  undefined1 uStack_8e;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 auStack_74 [2];
  undefined1 uStack_6c;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  void *pvStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 auStack_3c [4];
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  int *piStack_4;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_8e = 1;
  uStack_8c = 0;
  uStack_88 = 0;
  uStack_84 = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  uStack_78 = 0;
  auStack_74[0] = 0;
  uStack_58 = 0xf;
  uStack_5c = 0;
  uStack_6c = 0;
  piStack_f8 = piVar3;
  uStack_c0 = (**(code **)(*DAT_00b5a7ac + 8))();
  uStack_a4 = 0xf;
  uStack_a8 = 0;
  uStack_b8 = uStack_b8 & 0xffffff00;
  uStack_a0 = 0;
  uStack_9c = 0;
  uStack_98 = 0;
  uStack_e0 = 0xf;
  uStack_e4 = 0;
  appppppbStack_f4[0] = (byte ******)((uint)appppppbStack_f4[0] & 0xffffff00);
  piStack_c4 = (int *)0xf;
  uStack_c8 = 0;
  appppppuStack_d8[0] = (undefined4 ******)((uint)appppppuStack_d8[0] & 0xffffff00);
  FUN_00401740(s_<_vscroll>_009bc590,10);
  pvVar4 = operator_new(0x468);
  if (pvVar4 == (void *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = FUN_00505f10();
  }
  *(undefined4 *)(iVar5 + 0x38) = 0;
  *(undefined4 *)(iVar5 + 0x3c) = 1;
  cVar2 = FUN_005885f0();
  do {
    if (cVar2 == '\0') {
LAB_00562ce6:
      FUN_00401660(auStack_74,0,0xffffffff);
      (**(code **)(*piVar3 + 8))(auStack_94);
      if ((piStack_4 != (int *)0x0) &&
         (cVar2 = (**(code **)(*piVar3 + 0x74))(piStack_4), cVar2 != '\0')) {
        cVar2 = (**(code **)(*piStack_4 + 0x78))(piVar3);
        if (cVar2 == '\0') {
          (**(code **)(*piVar3 + 0x74))(0);
        }
        else {
          iVar5 = (**(code **)(*piStack_4 + 0x38))();
          piVar3[1] = iVar5;
        }
      }
      piVar1 = piStack_c4;
      (**(code **)(*piVar3 + 0x2c))(piStack_c4);
      (**(code **)(*piVar1 + 0x38))(piVar3);
      (**(code **)(*piVar1 + 0x1c))(&uStack_c8);
      FUN_00569460(auStack_ec,piVar3);
      FUN_0055ac40();
      (**(code **)(*piVar1 + 0x24))(4);
      FUN_00505d80();
      _free((void *)0x4);
      return;
    }
    uVar6 = FUN_00588600(auStack_3c);
    uVar14 = 0x562a8f;
    FUN_00401660(uVar6,0,0xffffffff);
    if (0xf < uStack_24) {
      _free(pvStack_38);
      return;
    }
    uStack_24 = 0xf;
    uStack_28 = 0;
    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    cVar2 = FUN_0055cad0(&piStack_f8);
    if (cVar2 != '\0') {
      FUN_00588700(&piStack_f8);
      goto LAB_00562ce6;
    }
    uVar16 = 0xf;
    uVar15 = 0;
    in_stack_fffffed4 = in_stack_fffffed4 & 0xffffff00;
    FUN_00401660(&piStack_f8,0,0xffffffff);
    FUN_0055cf30(auStack_94,iVar5,in_stack_fffffed0,in_stack_fffffed4,in_stack_fffffed8,uVar14,uVar6
                 ,uVar15,uVar16);
    piVar3 = in_ECX;
    if (uStack_e4 == 0) {
code_r0x00562bbf:
      if (uStack_e4 != 0) {
        uVar8 = uStack_e4;
        if (9 < uStack_e4) {
          uVar8 = 10;
        }
        ppppppbVar10 = appppppbStack_f4[0];
        if (uStack_e0 < 0x10) {
          ppppppbVar10 = (byte ******)appppppbStack_f4;
        }
        bVar12 = false;
        iVar9 = 0;
        bVar13 = true;
        pbVar11 = (byte *)s_buttontick_009bc5a8;
        do {
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          bVar12 = *(byte *)ppppppbVar10 < *pbVar11;
          bVar13 = *(byte *)ppppppbVar10 == *pbVar11;
          ppppppbVar10 = (byte ******)((int)ppppppbVar10 + 1);
          pbVar11 = pbVar11 + 1;
        } while (bVar13);
        if (!bVar13) {
          iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        }
        if (((iVar9 == 0) && (9 < uStack_e4)) && (uStack_e4 == 10)) {
          uVar6 = FUN_00588600(auStack_20);
          uVar6 = thunk_FUN_00796e60(uVar6);
          *(undefined4 *)(iVar5 + 0x3c) = uVar6;
          if (0xf < uStack_8) {
            _free(pvStack_1c);
            return;
          }
          uStack_8 = 0xf;
          uStack_c = 0;
          pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
          goto LAB_00562cb4;
        }
      }
      in_stack_fffffed8 = 0x562c7a;
      iVar9 = FUN_00403620(0,uStack_e4,s_<image>_009bc5b4,7);
      if (iVar9 == 0) {
        FUN_0055d1f0(iVar5);
      }
      else {
        ppppppuVar7 = appppppuStack_d8[0];
        if (piStack_c4 < (int *)0x10) {
          ppppppuVar7 = appppppuStack_d8;
        }
        in_stack_fffffed8 = 0x562cb0;
        iVar9 = FUN_00403620(0,uStack_e4,ppppppuVar7,uStack_c8);
        if (iVar9 == 0) {
          FUN_00588700(&piStack_f8);
          goto LAB_00562ce6;
        }
      }
    }
    else {
      uVar8 = uStack_e4;
      if (7 < uStack_e4) {
        uVar8 = 8;
      }
      ppppppbVar10 = appppppbStack_f4[0];
      if (uStack_e0 < 0x10) {
        ppppppbVar10 = (byte ******)appppppbStack_f4;
      }
      bVar12 = false;
      iVar9 = 0;
      bVar13 = true;
      pbVar11 = (byte *)s_maxvalue_009bc59c;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        bVar12 = *(byte *)ppppppbVar10 < *pbVar11;
        bVar13 = *(byte *)ppppppbVar10 == *pbVar11;
        ppppppbVar10 = (byte ******)((int)ppppppbVar10 + 1);
        pbVar11 = pbVar11 + 1;
      } while (bVar13);
      if (!bVar13) {
        iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
      }
      if (((iVar9 != 0) || (uStack_e4 < 8)) || (uStack_e4 != 8)) goto code_r0x00562bbf;
      uVar6 = FUN_00588600(&uStack_58);
      uVar6 = thunk_FUN_00796e60(uVar6);
      *(undefined4 *)(iVar5 + 0x38) = uVar6;
      if (0xf < uStack_40) {
        _free(pvStack_54);
        return;
      }
      uStack_40 = 0xf;
      uStack_44 = 0;
      pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
    }
LAB_00562cb4:
    cVar2 = FUN_005885f0();
  } while( true );
}


// ==== FUN_00562e30 @ 0x00562e30 ====

/* WARNING: Removing unreachable block (ram,0x00563057) */
/* WARNING: Removing unreachable block (ram,0x0056310a) */

void FUN_00562e30(void)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 ******ppppppuVar6;
  uint uVar7;
  int iVar8;
  void *unaff_EBP;
  byte ******ppppppbVar9;
  void *unaff_EDI;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  undefined4 in_stack_fffffdd0;
  uint in_stack_fffffdd4;
  undefined4 in_stack_fffffdd8;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int iStack_200;
  undefined4 local_1f8;
  byte ******appppppbStack_1f4 [4];
  uint uStack_1e4;
  uint uStack_1e0;
  int *piStack_1dc;
  int *piStack_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 ******appppppuStack_1c8 [4];
  undefined4 uStack_1b8;
  int *piStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  void *pvStack_1a0;
  undefined4 uStack_190;
  uint uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  void *pvStack_180;
  undefined1 uStack_17c;
  undefined1 uStack_17b;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  uint uStack_16c;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  void *pvStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined1 uStack_148;
  undefined1 uStack_147;
  undefined4 uStack_144;
  uint uStack_140;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  int *piStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined1 auStack_10c [6];
  undefined1 uStack_106;
  undefined4 uStack_104;
  undefined4 uStack_100;
  void *pvStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  uint uStack_e8;
  undefined1 uStack_e4;
  undefined4 uStack_d4;
  undefined4 auStack_d0 [2];
  undefined1 auStack_c8 [4];
  void *pvStack_c4;
  undefined4 uStack_b4;
  uint uStack_b0;
  undefined1 auStack_ac [4];
  void *pvStack_a8;
  undefined4 uStack_98;
  uint uStack_94;
  undefined1 auStack_90 [4];
  void *pvStack_8c;
  undefined4 uStack_7c;
  uint uStack_78;
  undefined1 auStack_74 [4];
  void *pvStack_70;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined1 auStack_58 [4];
  void *pvStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  int aiStack_3c [4];
  void *pvStack_2c;
  undefined4 uStack_1c;
  uint uStack_18;
  int *piStack_4;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_106 = 1;
  uStack_104 = 0;
  uStack_100 = 0;
  pvStack_fc = (void *)0x0;
  uStack_f8 = 0;
  uStack_f4 = 0;
  uStack_f0 = 0;
  uStack_ec = 0;
  auStack_d0[0] = 0xf;
  uStack_d4 = 0;
  uStack_e4 = 0;
  piStack_1d8 = piVar3;
  uStack_1b0 = (**(code **)(*DAT_00b5a7ac + 8))(5);
  uStack_12c = 0xf;
  uStack_130 = 0;
  uStack_140 = uStack_140 & 0xffffff00;
  uStack_128 = 0;
  uStack_124 = 0;
  uStack_120 = 0;
  piStack_1d8 = (int *)0x0;
  uStack_1d4 = 0;
  uStack_1d0 = 0;
  uStack_178 = 0;
  uStack_174 = 0;
  uStack_158 = 0xf;
  uStack_15c = 0;
  uStack_16c = uStack_16c & 0xffffff00;
  pvStack_154 = (void *)0x1;
  uStack_150 = 0;
  uStack_14c = 1;
  uStack_148 = 0;
  uStack_147 = 0;
  uStack_1e0 = 0xf;
  uStack_1e4 = 0;
  appppppbStack_1f4[0] = (byte ******)((uint)appppppbStack_1f4[0] & 0xffffff00);
  piStack_1b4 = (int *)0xf;
  uStack_1b8 = 0;
  appppppuStack_1c8[0] = (undefined4 ******)((uint)appppppuStack_1c8[0] & 0xffffff00);
  FUN_00401740(s_<_treectrl>_009bc5bc,0xb);
  pvVar4 = operator_new(0x468);
  if (pvVar4 == (void *)0x0) {
    iStack_200 = 0;
  }
  else {
    iStack_200 = FUN_00505f10();
  }
  *(undefined4 *)(iStack_200 + 0x58) = 100;
  *(undefined4 *)(iStack_200 + 0x5c) = 0x14;
  *(undefined4 *)(iStack_200 + 0x60) = 5;
  *(undefined4 *)(iStack_200 + 100) = 0xc;
  cVar2 = FUN_005885f0();
  do {
    if (cVar2 == '\0') {
LAB_0056347e:
      FUN_00401660(&uStack_ec,0,0xffffffff);
      (**(code **)(*piVar3 + 8))(auStack_10c);
      if ((piStack_4 != (int *)0x0) &&
         (cVar2 = (**(code **)(*piVar3 + 0x74))(piStack_4), cVar2 != '\0')) {
        cVar2 = (**(code **)(*piStack_4 + 0x78))(piVar3);
        if (cVar2 == '\0') {
          (**(code **)(*piVar3 + 0x74))(0);
        }
        else {
          iVar8 = (**(code **)(*piStack_4 + 0x38))();
          piVar3[1] = iVar8;
        }
      }
      piVar1 = piStack_1b4;
      (**(code **)(*piStack_1b4 + 0x38))(piVar3);
      (**(code **)(*piVar1 + 0x1c))(&uStack_14c);
      if ((char)((uint)unaff_EDI >> 0x18) != '\0') {
        (**(code **)(*piVar1 + 8))(&uStack_184);
      }
      (**(code **)(*piVar3 + 0x2c))(piVar1);
      FUN_00569460(&piStack_1dc,piVar3);
      FUN_005860f0();
      (**(code **)(*piVar1 + 0x24))(unaff_EDI);
      if (unaff_EDI != (void *)0x0) {
        FUN_00505d80();
        _free(unaff_EDI);
        return;
      }
      if ((undefined4 ******)0xf < appppppuStack_1c8[0]) {
        _free(piStack_1dc);
        return;
      }
      appppppuStack_1c8[0] = (undefined4 ******)0xf;
      uStack_1cc = 0;
      piStack_1dc = (int *)((uint)piStack_1dc & 0xffffff00);
      if ((byte ******)0xf < appppppbStack_1f4[0]) {
        _free(unaff_EBP);
        return;
      }
      appppppbStack_1f4[0] = (byte ******)0xf;
      local_1f8 = 0;
      if (0xf < uStack_16c) {
        _free(pvStack_180);
        return;
      }
      uStack_16c = 0xf;
      uStack_170 = 0;
      pvStack_180 = (void *)((uint)pvStack_180 & 0xffffff00);
      if (0xf < uStack_140) {
        _free(pvStack_154);
        return;
      }
      uStack_140 = 0xf;
      uStack_144 = 0;
      pvStack_154 = (void *)((uint)pvStack_154 & 0xffffff00);
      if (uStack_e8 < 0x10) {
        return;
      }
      _free(pvStack_fc);
      return;
    }
    uVar5 = FUN_00588600(auStack_ac);
    uVar13 = 0x562fdd;
    FUN_00401660(uVar5,0,0xffffffff);
    if (0xf < uStack_94) {
      _free(pvStack_a8);
      return;
    }
    uStack_94 = 0xf;
    uStack_98 = 0;
    pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
    cVar2 = FUN_0055cad0(&local_1f8);
    if (cVar2 != '\0') {
      FUN_00588700(&local_1f8);
      goto LAB_0056347e;
    }
    uVar15 = 0xf;
    uVar14 = 0;
    in_stack_fffffdd4 = in_stack_fffffdd4 & 0xffffff00;
    FUN_00401660(&local_1f8,0,0xffffffff);
    FUN_0055cf30(auStack_10c,iStack_200,in_stack_fffffdd0,in_stack_fffffdd4,in_stack_fffffdd8,uVar13
                 ,uVar5,uVar14,uVar15);
    if (uStack_1e4 == 0) {
code_r0x0056310d:
      if (uStack_1e4 != 0) {
        uVar7 = uStack_1e4;
        if (9 < uStack_1e4) {
          uVar7 = 10;
        }
        ppppppbVar9 = appppppbStack_1f4[0];
        if (uStack_1e0 < 0x10) {
          ppppppbVar9 = (byte ******)appppppbStack_1f4;
        }
        bVar11 = false;
        iVar8 = 0;
        bVar12 = true;
        pbVar10 = (byte *)s_nodeheight_009bc5d4;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          bVar11 = *(byte *)ppppppbVar9 < *pbVar10;
          bVar12 = *(byte *)ppppppbVar9 == *pbVar10;
          ppppppbVar9 = (byte ******)((int)ppppppbVar9 + 1);
          pbVar10 = pbVar10 + 1;
        } while (bVar12);
        if (!bVar12) {
          iVar8 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        }
        if (((iVar8 == 0) && (9 < uStack_1e4)) && (uStack_1e4 == 10)) {
          uVar5 = FUN_00588600(auStack_58);
          uVar5 = thunk_FUN_00796e60(uVar5);
          *(undefined4 *)(iStack_200 + 0x5c) = uVar5;
          if (0xf < uStack_40) {
            _free(pvStack_54);
            return;
          }
          uStack_40 = 0xf;
          uStack_44 = 0;
          pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
          goto LAB_0056344c;
        }
      }
      in_stack_fffffdd8 = 0x5631cb;
      iVar8 = FUN_00403620(0,uStack_1e4,s_offset_009bc5e0,6);
      if (iVar8 == 0) {
        uVar5 = FUN_00588600(auStack_c8);
        uVar5 = thunk_FUN_00796e60(uVar5);
        *(undefined4 *)(iStack_200 + 0x60) = uVar5;
        if (0xf < uStack_b0) {
          _free(pvStack_c4);
          return;
        }
        uStack_b0 = 0xf;
        uStack_b4 = 0;
        pvStack_c4 = (void *)((uint)pvStack_c4 & 0xffffff00);
      }
      else {
        in_stack_fffffdd8 = 0x56323d;
        iVar8 = FUN_00403620(0,uStack_1e4,s_btnsize_009bc5e8,7);
        if (iVar8 == 0) {
          uVar5 = FUN_00588600(auStack_74);
          uVar5 = thunk_FUN_00796e60(uVar5);
          *(undefined4 *)(iStack_200 + 100) = uVar5;
          if (0xf < uStack_5c) {
            _free(pvStack_70);
            return;
          }
          uStack_5c = 0xf;
          uStack_60 = 0;
          pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
        }
        else {
          in_stack_fffffdd8 = 0x5632af;
          iVar8 = FUN_00403620(0,uStack_1e4,s_<image>_009bc5f0,7);
          if (iVar8 == 0) {
            uStack_11c = FUN_0055d1f0(&piStack_1d8);
            piStack_118 = piStack_1d8;
            uStack_114 = uStack_1d4;
            uStack_110 = uStack_1d0;
            FUN_0056ac60(auStack_d0,&uStack_11c);
          }
          else {
            in_stack_fffffdd8 = 0x56331e;
            iVar8 = FUN_00403620(0,uStack_1e4,s_<title>_009bc5f8,7);
            if (iVar8 == 0) {
              uStack_188 = 1;
              pvStack_180 = (void *)0x1;
              uStack_1ac = 0;
              uStack_1a8 = 0;
              uStack_18c = 0xf;
              uStack_190 = 0;
              pvStack_1a0 = (void *)((uint)pvStack_1a0 & 0xffffff00);
              uStack_184 = 0;
              uStack_17c = 0;
              uStack_17b = 0;
              iVar8 = FUN_0055dde0(&uStack_1ac);
              aiStack_3c[0] = iVar8;
              FUN_00504250(&uStack_1ac);
              FUN_00505600(auStack_d0,aiStack_3c);
              if (0xf < uStack_18) {
                _free(pvStack_2c);
                return;
              }
              uStack_18 = 0xf;
              uStack_1c = 0;
              pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
              if (iVar8 == 6) {
                FUN_005523f0(&uStack_1ac);
              }
              if (0xf < uStack_18c) {
                _free(pvStack_1a0);
                return;
              }
              uStack_18c = 0xf;
              uStack_190 = 0;
              pvStack_1a0 = (void *)((uint)pvStack_1a0 & 0xffffff00);
            }
            else {
              ppppppuVar6 = appppppuStack_1c8[0];
              if (piStack_1b4 < (int *)0x10) {
                ppppppuVar6 = appppppuStack_1c8;
              }
              in_stack_fffffdd8 = 0x563448;
              iVar8 = FUN_00403620(0,uStack_1e4,ppppppuVar6,uStack_1b8);
              if (iVar8 == 0) {
                FUN_00588700(&local_1f8);
                piVar3 = piStack_1dc;
                goto LAB_0056347e;
              }
            }
          }
        }
      }
    }
    else {
      uVar7 = uStack_1e4;
      if (8 < uStack_1e4) {
        uVar7 = 9;
      }
      ppppppbVar9 = appppppbStack_1f4[0];
      if (uStack_1e0 < 0x10) {
        ppppppbVar9 = (byte ******)appppppbStack_1f4;
      }
      bVar11 = false;
      iVar8 = 0;
      bVar12 = true;
      pbVar10 = (byte *)s_nodewidth_009bc5c8;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        bVar11 = *(byte *)ppppppbVar9 < *pbVar10;
        bVar12 = *(byte *)ppppppbVar9 == *pbVar10;
        ppppppbVar9 = (byte ******)((int)ppppppbVar9 + 1);
        pbVar10 = pbVar10 + 1;
      } while (bVar12);
      if (!bVar12) {
        iVar8 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      }
      if (((iVar8 != 0) || (uStack_1e4 < 9)) || (uStack_1e4 != 9)) goto code_r0x0056310d;
      uVar5 = FUN_00588600(auStack_90);
      uVar5 = thunk_FUN_00796e60(uVar5);
      *(undefined4 *)(iStack_200 + 0x58) = uVar5;
      if (0xf < uStack_78) {
        _free(pvStack_8c);
        return;
      }
      uStack_78 = 0xf;
      uStack_7c = 0;
      pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
    }
LAB_0056344c:
    cVar2 = FUN_005885f0();
    piVar3 = piStack_1dc;
  } while( true );
}


// ==== FUN_00563620 @ 0x00563620 ====

/* WARNING: Removing unreachable block (ram,0x00563847) */
/* WARNING: Removing unreachable block (ram,0x005638fd) */

void FUN_00563620(void)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 ******ppppppuVar6;
  uint uVar7;
  int iVar8;
  void *unaff_EBP;
  byte ******ppppppbVar9;
  void *unaff_EDI;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  undefined4 in_stack_fffffdd0;
  uint in_stack_fffffdd4;
  undefined4 in_stack_fffffdd8;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int iStack_200;
  undefined4 local_1f8;
  byte ******appppppbStack_1f4 [4];
  uint uStack_1e4;
  uint uStack_1e0;
  int *piStack_1dc;
  int *piStack_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 ******appppppuStack_1c8 [4];
  undefined4 uStack_1b8;
  int *piStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  void *pvStack_1a0;
  undefined4 uStack_190;
  uint uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  void *pvStack_180;
  undefined1 uStack_17c;
  undefined1 uStack_17b;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  uint uStack_16c;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  void *pvStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined1 uStack_148;
  undefined1 uStack_147;
  undefined4 uStack_144;
  uint uStack_140;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  int *piStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined1 auStack_10c [6];
  undefined1 uStack_106;
  undefined4 uStack_104;
  undefined4 uStack_100;
  void *pvStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  uint uStack_e8;
  undefined1 uStack_e4;
  undefined4 uStack_d4;
  undefined4 auStack_d0 [2];
  undefined1 auStack_c8 [4];
  void *pvStack_c4;
  undefined4 uStack_b4;
  uint uStack_b0;
  undefined1 auStack_ac [4];
  void *pvStack_a8;
  undefined4 uStack_98;
  uint uStack_94;
  undefined1 auStack_90 [4];
  void *pvStack_8c;
  undefined4 uStack_7c;
  uint uStack_78;
  undefined1 auStack_74 [4];
  void *pvStack_70;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined1 auStack_58 [4];
  void *pvStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  int aiStack_3c [4];
  void *pvStack_2c;
  undefined4 uStack_1c;
  uint uStack_18;
  int *piStack_4;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_106 = 1;
  uStack_104 = 0;
  uStack_100 = 0;
  pvStack_fc = (void *)0x0;
  uStack_f8 = 0;
  uStack_f4 = 0;
  uStack_f0 = 0;
  uStack_ec = 0;
  auStack_d0[0] = 0xf;
  uStack_d4 = 0;
  uStack_e4 = 0;
  piStack_1d8 = piVar3;
  uStack_1b0 = (**(code **)(*DAT_00b5a7ac + 8))(0x16);
  uStack_12c = 0xf;
  uStack_130 = 0;
  uStack_140 = uStack_140 & 0xffffff00;
  uStack_128 = 0;
  uStack_124 = 0;
  uStack_120 = 0;
  piStack_1d8 = (int *)0x0;
  uStack_1d4 = 0;
  uStack_1d0 = 0;
  uStack_178 = 0;
  uStack_174 = 0;
  uStack_158 = 0xf;
  uStack_15c = 0;
  uStack_16c = uStack_16c & 0xffffff00;
  pvStack_154 = (void *)0x1;
  uStack_150 = 0;
  uStack_14c = 1;
  uStack_148 = 0;
  uStack_147 = 0;
  uStack_1e0 = 0xf;
  uStack_1e4 = 0;
  appppppbStack_1f4[0] = (byte ******)((uint)appppppbStack_1f4[0] & 0xffffff00);
  piStack_1b4 = (int *)0xf;
  uStack_1b8 = 0;
  appppppuStack_1c8[0] = (undefined4 ******)((uint)appppppuStack_1c8[0] & 0xffffff00);
  FUN_00401740(s_<_listbox>_009bc600,10);
  pvVar4 = operator_new(0x468);
  if (pvVar4 == (void *)0x0) {
    iStack_200 = 0;
  }
  else {
    iStack_200 = FUN_00505f10();
  }
  *(undefined4 *)(iStack_200 + 0x274) = 100;
  *(undefined4 *)(iStack_200 + 0x278) = 0x14;
  *(undefined4 *)(iStack_200 + 0x27c) = 5;
  cVar2 = FUN_005885f0();
  do {
    if (cVar2 == '\0') {
LAB_00563cd4:
      FUN_00401660(&uStack_ec,0,0xffffffff);
      (**(code **)(*piVar3 + 8))(auStack_10c);
      if ((piStack_4 != (int *)0x0) &&
         (cVar2 = (**(code **)(*piVar3 + 0x74))(piStack_4), cVar2 != '\0')) {
        cVar2 = (**(code **)(*piStack_4 + 0x78))(piVar3);
        if (cVar2 == '\0') {
          (**(code **)(*piVar3 + 0x74))(0);
        }
        else {
          iVar8 = (**(code **)(*piStack_4 + 0x38))();
          piVar3[1] = iVar8;
        }
      }
      piVar1 = piStack_1b4;
      (**(code **)(*piStack_1b4 + 0x38))(piVar3);
      (**(code **)(*piVar1 + 0x1c))(&uStack_14c);
      if ((char)((uint)unaff_EDI >> 0x18) != '\0') {
        (**(code **)(*piVar1 + 8))(&uStack_184);
      }
      (**(code **)(*piVar3 + 0x2c))(piVar1);
      FUN_00569460(&piStack_1dc,piVar3);
      FUN_005759d0();
      (**(code **)(*piVar1 + 0x24))(unaff_EDI);
      if (unaff_EDI != (void *)0x0) {
        FUN_00505d80();
        _free(unaff_EDI);
        return;
      }
      if ((undefined4 ******)0xf < appppppuStack_1c8[0]) {
        _free(piStack_1dc);
        return;
      }
      appppppuStack_1c8[0] = (undefined4 ******)0xf;
      uStack_1cc = 0;
      piStack_1dc = (int *)((uint)piStack_1dc & 0xffffff00);
      if ((byte ******)0xf < appppppbStack_1f4[0]) {
        _free(unaff_EBP);
        return;
      }
      appppppbStack_1f4[0] = (byte ******)0xf;
      local_1f8 = 0;
      if (0xf < uStack_16c) {
        _free(pvStack_180);
        return;
      }
      uStack_16c = 0xf;
      uStack_170 = 0;
      pvStack_180 = (void *)((uint)pvStack_180 & 0xffffff00);
      if (0xf < uStack_140) {
        _free(pvStack_154);
        return;
      }
      uStack_140 = 0xf;
      uStack_144 = 0;
      pvStack_154 = (void *)((uint)pvStack_154 & 0xffffff00);
      if (uStack_e8 < 0x10) {
        return;
      }
      _free(pvStack_fc);
      return;
    }
    uVar5 = FUN_00588600(auStack_ac);
    uVar13 = 0x5637cd;
    FUN_00401660(uVar5,0,0xffffffff);
    if (0xf < uStack_94) {
      _free(pvStack_a8);
      return;
    }
    uStack_94 = 0xf;
    uStack_98 = 0;
    pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
    cVar2 = FUN_0055cad0(&local_1f8);
    if (cVar2 != '\0') {
      FUN_00588700(&local_1f8);
      goto LAB_00563cd4;
    }
    uVar15 = 0xf;
    uVar14 = 0;
    in_stack_fffffdd4 = in_stack_fffffdd4 & 0xffffff00;
    FUN_00401660(&local_1f8,0,0xffffffff);
    FUN_0055cf30(auStack_10c,iStack_200,in_stack_fffffdd0,in_stack_fffffdd4,in_stack_fffffdd8,uVar13
                 ,uVar5,uVar14,uVar15);
    if (uStack_1e4 == 0) {
code_r0x00563900:
      if (uStack_1e4 != 0) {
        uVar7 = uStack_1e4;
        if (9 < uStack_1e4) {
          uVar7 = 10;
        }
        ppppppbVar9 = appppppbStack_1f4[0];
        if (uStack_1e0 < 0x10) {
          ppppppbVar9 = (byte ******)appppppbStack_1f4;
        }
        bVar11 = false;
        iVar8 = 0;
        bVar12 = true;
        pbVar10 = (byte *)s_nodeheight_009bc618;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          bVar11 = *(byte *)ppppppbVar9 < *pbVar10;
          bVar12 = *(byte *)ppppppbVar9 == *pbVar10;
          ppppppbVar9 = (byte ******)((int)ppppppbVar9 + 1);
          pbVar10 = pbVar10 + 1;
        } while (bVar12);
        if (!bVar12) {
          iVar8 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        }
        if (((iVar8 == 0) && (9 < uStack_1e4)) && (uStack_1e4 == 10)) {
          uVar5 = FUN_00588600(auStack_58);
          uVar5 = thunk_FUN_00796e60(uVar5);
          *(undefined4 *)(iStack_200 + 0x278) = uVar5;
          if (0xf < uStack_40) {
            _free(pvStack_54);
            return;
          }
          uStack_40 = 0xf;
          uStack_44 = 0;
          pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
          goto LAB_00563c9e;
        }
      }
      in_stack_fffffdd8 = 0x5639c1;
      iVar8 = FUN_00403620(0,uStack_1e4,s_offset_009bc624,6);
      if (iVar8 == 0) {
        uVar5 = FUN_00588600(auStack_c8);
        uVar5 = thunk_FUN_00796e60(uVar5);
        *(undefined4 *)(iStack_200 + 0x27c) = uVar5;
        if (0xf < uStack_b0) {
          _free(pvStack_c4);
          return;
        }
        uStack_b0 = 0xf;
        uStack_b4 = 0;
        pvStack_c4 = (void *)((uint)pvStack_c4 & 0xffffff00);
      }
      else {
        iVar8 = FUN_00403620(0,uStack_1e4,s_align_009bc62c,5);
        if (iVar8 == 0) {
          uVar5 = FUN_00588600(auStack_74);
          FUN_00401660(uVar5,0,0xffffffff);
          if (0xf < uStack_5c) {
            _free(pvStack_70);
            return;
          }
          uStack_5c = 0xf;
          uStack_60 = 0;
          pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
          in_stack_fffffdd8 = 0x563aa4;
          iVar8 = FUN_00403620(0,uStack_1e4,s_center_009bc634,6);
          if (iVar8 == 0) {
            *(undefined1 *)(iStack_200 + 0x280) = 1;
          }
          else {
            in_stack_fffffdd8 = 0x563ace;
            iVar8 = FUN_00403620(0,uStack_1e4,s_right_009bc63c,5);
            *(byte *)(iStack_200 + 0x280) = (-(iVar8 != 0) & 0xfeU) + 2;
          }
        }
        else {
          in_stack_fffffdd8 = 0x563afb;
          iVar8 = FUN_00403620(0,uStack_1e4,s_<image>_009bc644,7);
          if (iVar8 == 0) {
            uStack_11c = FUN_0055d1f0(&piStack_1d8);
            piStack_118 = piStack_1d8;
            uStack_114 = uStack_1d4;
            uStack_110 = uStack_1d0;
            FUN_0056ac60(auStack_d0,&uStack_11c);
          }
          else {
            in_stack_fffffdd8 = 0x563b6d;
            iVar8 = FUN_00403620(0,uStack_1e4,s_<title>_009bc64c,7);
            if (iVar8 == 0) {
              uStack_1ac = 0;
              uStack_1a8 = 0;
              uStack_18c = 0xf;
              uStack_190 = 0;
              pvStack_1a0 = (void *)((uint)pvStack_1a0 & 0xffffff00);
              uStack_188 = 1;
              uStack_184 = 0;
              pvStack_180 = (void *)0x1;
              uStack_17c = 0;
              uStack_17b = 0;
              iVar8 = FUN_0055dde0(&uStack_1ac);
              aiStack_3c[0] = iVar8;
              FUN_00504250(&uStack_1ac);
              FUN_00505600(auStack_d0,aiStack_3c);
              if (0xf < uStack_18) {
                _free(pvStack_2c);
                return;
              }
              uStack_18 = 0xf;
              uStack_1c = 0;
              pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
              if (iVar8 == 6) {
                FUN_005523f0(&uStack_1ac);
              }
              if (0xf < uStack_18c) {
                _free(pvStack_1a0);
                return;
              }
              uStack_18c = 0xf;
              uStack_190 = 0;
              pvStack_1a0 = (void *)((uint)pvStack_1a0 & 0xffffff00);
            }
            else {
              ppppppuVar6 = appppppuStack_1c8[0];
              if (piStack_1b4 < (int *)0x10) {
                ppppppuVar6 = appppppuStack_1c8;
              }
              in_stack_fffffdd8 = 0x563c9a;
              iVar8 = FUN_00403620(0,uStack_1e4,ppppppuVar6,uStack_1b8);
              if (iVar8 == 0) {
                FUN_00588700(&local_1f8);
                piVar3 = piStack_1dc;
                goto LAB_00563cd4;
              }
            }
          }
        }
      }
    }
    else {
      uVar7 = uStack_1e4;
      if (8 < uStack_1e4) {
        uVar7 = 9;
      }
      ppppppbVar9 = appppppbStack_1f4[0];
      if (uStack_1e0 < 0x10) {
        ppppppbVar9 = (byte ******)appppppbStack_1f4;
      }
      bVar11 = false;
      iVar8 = 0;
      bVar12 = true;
      pbVar10 = (byte *)s_nodewidth_009bc60c;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        bVar11 = *(byte *)ppppppbVar9 < *pbVar10;
        bVar12 = *(byte *)ppppppbVar9 == *pbVar10;
        ppppppbVar9 = (byte ******)((int)ppppppbVar9 + 1);
        pbVar10 = pbVar10 + 1;
      } while (bVar12);
      if (!bVar12) {
        iVar8 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      }
      if (((iVar8 != 0) || (uStack_1e4 < 9)) || (uStack_1e4 != 9)) goto code_r0x00563900;
      uVar5 = FUN_00588600(auStack_90);
      uVar5 = thunk_FUN_00796e60(uVar5);
      *(undefined4 *)(iStack_200 + 0x274) = uVar5;
      if (0xf < uStack_78) {
        _free(pvStack_8c);
        return;
      }
      uStack_78 = 0xf;
      uStack_7c = 0;
      pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
    }
LAB_00563c9e:
    cVar2 = FUN_005885f0();
    piVar3 = piStack_1dc;
  } while( true );
}


// ==== FUN_00563e70 @ 0x00563e70 ====

/* WARNING: Removing unreachable block (ram,0x00564125) */

void FUN_00563e70(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int *piVar4;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  byte ****ppppbVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  undefined4 in_stack_fffffd54;
  uint in_stack_fffffd58;
  undefined4 in_stack_fffffd5c;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined *puVar16;
  undefined1 auStack_278 [4];
  byte ****appppbStack_274 [2];
  int *piStack_26c;
  undefined4 uStack_268;
  int *piStack_264;
  int *piStack_260;
  undefined4 uStack_25c;
  int *piStack_258;
  int *piStack_254;
  undefined1 auStack_250 [4];
  undefined1 uStack_24c;
  undefined4 uStack_23c;
  undefined4 uStack_238;
  undefined1 uStack_230;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined4 uStack_210;
  undefined1 auStack_20c [6];
  undefined1 uStack_206;
  undefined4 uStack_204;
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  undefined4 uStack_1f8;
  undefined4 uStack_1f4;
  undefined4 uStack_1f0;
  undefined4 auStack_1ec [2];
  undefined1 uStack_1e4;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  void *pvStack_1cc;
  undefined4 uStack_1bc;
  uint uStack_1b8;
  undefined1 auStack_1b4 [4];
  void *pvStack_1b0;
  undefined4 uStack_1a0;
  uint uStack_19c;
  undefined1 auStack_198 [4];
  void *pvStack_194;
  undefined4 uStack_184;
  uint uStack_180;
  undefined1 auStack_17c [4];
  void *pvStack_178;
  undefined4 uStack_168;
  uint uStack_164;
  undefined1 auStack_160 [4];
  void *pvStack_15c;
  undefined4 uStack_14c;
  uint uStack_148;
  undefined1 auStack_144 [4];
  void *pvStack_140;
  undefined4 uStack_130;
  uint uStack_12c;
  undefined1 auStack_128 [8];
  undefined1 auStack_120 [8];
  undefined1 auStack_118 [52];
  undefined1 auStack_e4 [28];
  undefined1 auStack_c8 [28];
  undefined1 auStack_ac [28];
  undefined1 auStack_90 [28];
  undefined1 auStack_74 [28];
  undefined1 auStack_58 [80];
  int *piStack_8;
  int *piStack_4;
  
  piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_206 = 1;
  uStack_204 = 0;
  uStack_200 = 0;
  uStack_1fc = 0;
  uStack_1f8 = 0;
  uStack_1f4 = 0;
  uStack_1f0 = 0;
  auStack_1ec[0] = 0;
  uStack_1d0 = 0xf;
  uStack_1d4 = 0;
  uStack_1e4 = 0;
  piStack_254 = piVar4;
  uStack_25c = (**(code **)(*DAT_00b5a7ac + 8))(6);
  uStack_21c = 0xf;
  uStack_220 = 0;
  uStack_230 = 0;
  uStack_218 = 0;
  uStack_214 = 0;
  uStack_210 = 0;
  piStack_260 = (int *)0xf;
  piStack_264 = (int *)0x0;
  appppbStack_274[0] = (byte ****)((uint)appppbStack_274[0] & 0xffffff00);
  uStack_238 = 0xf;
  uStack_23c = 0;
  uStack_24c = 0;
  FUN_00401740(s_<_textbox>_009bc654,10);
  pvVar5 = operator_new(0x468);
  if (pvVar5 == (void *)0x0) {
    pvVar5 = (void *)0x0;
  }
  else {
    pvVar5 = (void *)FUN_00505f10();
  }
  *(undefined4 *)((int)pvVar5 + 0x9c) = 0x14;
  *(undefined4 *)((int)pvVar5 + 0x94) = 5;
  *(undefined4 *)((int)pvVar5 + 0x98) = 5;
  *(undefined4 *)((int)pvVar5 + 0xa0) = 2;
  *(undefined1 *)((int)pvVar5 + 0xad) = 0;
  *(undefined2 *)((int)pvVar5 + 0xa8) = 0xffff;
  *(undefined4 *)((int)pvVar5 + 0xa4) = 0x32;
  *(undefined4 *)((int)pvVar5 + 0xb0) = 0xff000000;
  *(undefined1 *)((int)pvVar5 + 0xac) = 0;
  *(undefined1 *)((int)pvVar5 + 0xaa) = 0;
  *(undefined1 *)((int)pvVar5 + 0xab) = 0;
  *(undefined2 *)((int)pvVar5 + 0xb4) = 0;
  *(undefined2 *)((int)pvVar5 + 0xb6) = 0x3c;
  cVar1 = FUN_005885f0();
  if (cVar1 != '\0') {
    do {
      uVar6 = FUN_00588600(auStack_144);
      uVar13 = 0x564001;
      FUN_00401660(uVar6,0,0xffffffff);
      if (0xf < uStack_12c) {
        _free(pvStack_140);
        return;
      }
      uStack_12c = 0xf;
      uStack_130 = 0;
      pvStack_140 = (void *)((uint)pvStack_140 & 0xffffff00);
      cVar1 = FUN_0055cad0(auStack_278);
      if (cVar1 != '\0') {
        FUN_00588700(auStack_278);
        break;
      }
      uVar15 = 0xf;
      uVar14 = 0;
      in_stack_fffffd58 = in_stack_fffffd58 & 0xffffff00;
      FUN_00401660(auStack_278,0,0xffffffff);
      FUN_0055cf30(auStack_20c,pvVar5,in_stack_fffffd54,in_stack_fffffd58,in_stack_fffffd5c,uVar13,
                   uVar6,uVar14,uVar15);
      if (piStack_264 == (int *)0x0) {
code_r0x00564128:
        if (piStack_264 != (int *)0x0) {
          piVar4 = piStack_264;
          if ((int *)0x5 < piStack_264) {
            piVar4 = (int *)0x6;
          }
          ppppbVar9 = appppbStack_274[0];
          if (piStack_260 < (int *)0x10) {
            ppppbVar9 = (byte ****)appppbStack_274;
          }
          bVar11 = false;
          iVar8 = 0;
          bVar12 = true;
          pbVar10 = (byte *)s_margin_009bc66c;
          do {
            if (piVar4 == (int *)0x0) break;
            piVar4 = (int *)((int)piVar4 + -1);
            bVar11 = *(byte *)ppppbVar9 < *pbVar10;
            bVar12 = *(byte *)ppppbVar9 == *pbVar10;
            ppppbVar9 = (byte ****)((int)ppppbVar9 + 1);
            pbVar10 = pbVar10 + 1;
          } while (bVar12);
          if (!bVar12) {
            iVar8 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
          }
          if (((iVar8 == 0) && ((int *)0x5 < piStack_264)) && (piStack_264 == (int *)0x6)) {
            puVar7 = (undefined4 *)FUN_0055cec0(auStack_120);
            *(undefined4 *)((int)pvVar5 + 0x94) = *puVar7;
            *(undefined4 *)((int)pvVar5 + 0x98) = puVar7[1];
            goto LAB_005645e8;
          }
        }
        in_stack_fffffd5c = 0x5641a5;
        iVar8 = FUN_00403620(0,piStack_264,s_color_009bc674,5);
        if (iVar8 == 0) {
          uVar6 = FUN_00588600(auStack_17c);
          uVar6 = thunk_FUN_00796e90(uVar6);
          *(undefined4 *)((int)pvVar5 + 0xb0) = uVar6;
          if (0xf < uStack_164) {
            _free(pvStack_178);
            return;
          }
          uStack_164 = 0xf;
          uStack_168 = 0;
          pvStack_178 = (void *)((uint)pvStack_178 & 0xffffff00);
        }
        else {
          in_stack_fffffd5c = 0x56421a;
          iVar8 = FUN_00403620(0,piStack_264,s_fonttype_009bc67c,8);
          if (iVar8 == 0) {
            uVar6 = FUN_00588600(&uStack_1d0);
            uVar6 = thunk_FUN_00796e60(uVar6);
            *(undefined4 *)((int)pvVar5 + 0xa0) = uVar6;
            if (0xf < uStack_1b8) {
              _free(pvStack_1cc);
              return;
            }
            uStack_1b8 = 0xf;
            uStack_1bc = 0;
            pvStack_1cc = (void *)((uint)pvStack_1cc & 0xffffff00);
          }
          else {
            in_stack_fffffd5c = 0x56428f;
            iVar8 = FUN_00403620(0,piStack_264,s_input_type_009bc688,10);
            if (iVar8 == 0) {
              uVar6 = FUN_00588600(auStack_1b4);
              uVar2 = thunk_FUN_00796f50(uVar6);
              *(undefined1 *)((int)pvVar5 + 0xad) = uVar2;
              if (0xf < uStack_19c) {
                _free(pvStack_1b0);
                return;
              }
              uStack_19c = 0xf;
              uStack_1a0 = 0;
              pvStack_1b0 = (void *)((uint)pvStack_1b0 & 0xffffff00);
            }
            else {
              in_stack_fffffd5c = 0x564304;
              iVar8 = FUN_00403620(0,piStack_264,s_autoline_009bc694,8);
              if (iVar8 == 0) {
                uVar6 = FUN_00588600(auStack_198);
                uVar2 = thunk_FUN_00796fe0(uVar6);
                *(undefined1 *)((int)pvVar5 + 0xab) = uVar2;
                if (0xf < uStack_180) {
                  _free(pvStack_194);
                  return;
                }
                uStack_180 = 0xf;
                uStack_184 = 0;
                pvStack_194 = (void *)((uint)pvStack_194 & 0xffffff00);
              }
              else {
                cVar1 = FUN_004036a0(auStack_278,s_widthcut_009bc6a0);
                if (cVar1 != '\0') {
                  uVar6 = FUN_00588600(auStack_ac);
                  uVar3 = thunk_FUN_00796f80(uVar6);
                  *(undefined2 *)((int)pvVar5 + 0xb6) = uVar3;
                    /* WARNING: Subroutine does not return */
                  FUN_00446f10();
                }
                cVar1 = FUN_004036a0(auStack_278,s_inputmode_009bc6ac);
                if (cVar1 != '\0') {
                  uVar6 = FUN_00588600(auStack_c8);
                  uVar2 = thunk_FUN_00796fe0(uVar6);
                  *(undefined1 *)((int)pvVar5 + 0xaa) = uVar2;
                    /* WARNING: Subroutine does not return */
                  FUN_00446f10();
                }
                cVar1 = FUN_004036a0(auStack_278,s_maxlength_009bc6b8);
                if (cVar1 != '\0') {
                  uVar6 = FUN_00588600(auStack_e4);
                  uVar3 = thunk_FUN_00796f80(uVar6);
                  *(undefined2 *)((int)pvVar5 + 0xa8) = uVar3;
                    /* WARNING: Subroutine does not return */
                  FUN_00446f10();
                }
                cVar1 = FUN_004036a0(auStack_278,s_buttonwidth_009bc6c4);
                if (cVar1 != '\0') {
                  uVar6 = FUN_00588600(auStack_74);
                  uVar6 = thunk_FUN_00796e60(uVar6);
                  *(undefined4 *)((int)pvVar5 + 0xa4) = uVar6;
                    /* WARNING: Subroutine does not return */
                  FUN_00446f10();
                }
                cVar1 = FUN_004036a0(auStack_278,s_maxline_009bc6d0);
                if (cVar1 != '\0') {
                  uVar6 = FUN_00588600(auStack_58);
                  uVar3 = thunk_FUN_00796f80(uVar6);
                  *(undefined2 *)((int)pvVar5 + 0xb4) = uVar3;
                    /* WARNING: Subroutine does not return */
                  FUN_00446f10();
                }
                cVar1 = FUN_004036a0(auStack_278,s_chattype_009bc6d8);
                if (cVar1 != '\0') {
                  puVar16 = &DAT_009bc6e4;
                  uVar6 = FUN_00588600(auStack_90);
                  FUN_004036a0(uVar6,puVar16);
                    /* WARNING: Subroutine does not return */
                  FUN_00446f10();
                }
                cVar1 = FUN_004036a0(auStack_278,s_<title>_009bc6e8);
                if (cVar1 == '\0') {
                  cVar1 = FUN_004036a0(auStack_278,s_<image>_009bc6f0);
                  if (cVar1 == '\0') {
                    cVar1 = FUN_00423420(auStack_278,auStack_250);
                    if (cVar1 != '\0') {
                      FUN_00588700(auStack_278);
                      break;
                    }
                  }
                  else {
                    FUN_0055d1f0(pvVar5);
                  }
                }
                else {
                  FUN_00503fe0();
                  piStack_254 = (int *)FUN_0055dde0(auStack_118);
                  uVar6 = FUN_00504640(&piStack_254,auStack_118);
                  FUN_00505600(auStack_128,uVar6);
                  FUN_00446f40();
                  FUN_006c1c60();
                }
              }
            }
          }
        }
      }
      else {
        piVar4 = piStack_264;
        if ((int *)0x9 < piStack_264) {
          piVar4 = (int *)0xa;
        }
        ppppbVar9 = appppbStack_274[0];
        if (piStack_260 < (int *)0x10) {
          ppppbVar9 = (byte ****)appppbStack_274;
        }
        bVar11 = false;
        iVar8 = 0;
        bVar12 = true;
        pbVar10 = (byte *)s_lineheight_009bc660;
        do {
          if (piVar4 == (int *)0x0) break;
          piVar4 = (int *)((int)piVar4 + -1);
          bVar11 = *(byte *)ppppbVar9 < *pbVar10;
          bVar12 = *(byte *)ppppbVar9 == *pbVar10;
          ppppbVar9 = (byte ****)((int)ppppbVar9 + 1);
          pbVar10 = pbVar10 + 1;
        } while (bVar12);
        if (!bVar12) {
          iVar8 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        }
        if (((iVar8 != 0) || (piStack_264 < (int *)0xa)) || (piStack_264 != (int *)0xa))
        goto code_r0x00564128;
        uVar6 = FUN_00588600(auStack_160);
        uVar6 = thunk_FUN_00796e60(uVar6);
        *(undefined4 *)((int)pvVar5 + 0x9c) = uVar6;
        if (0xf < uStack_148) {
          _free(pvStack_15c);
          return;
        }
        uStack_148 = 0xf;
        uStack_14c = 0;
        pvStack_15c = (void *)((uint)pvStack_15c & 0xffffff00);
      }
LAB_005645e8:
      cVar1 = FUN_005885f0();
    } while (cVar1 != '\0');
    piVar4 = piStack_258;
  }
  FUN_00401660(auStack_1ec,0,0xffffffff);
  (**(code **)(*piVar4 + 8))(auStack_20c);
  if ((piStack_4 != (int *)0x0) && (cVar1 = (**(code **)(*piVar4 + 0x74))(piStack_4), cVar1 != '\0')
     ) {
    cVar1 = (**(code **)(*piStack_4 + 0x78))(piVar4);
    if (cVar1 == '\0') {
      (**(code **)(*piVar4 + 0x74))(0);
    }
    else {
      iVar8 = (**(code **)(*piStack_8 + 0x38))();
      piVar4[1] = iVar8;
    }
  }
  (**(code **)(*piStack_260 + 0x38))(piVar4);
  (**(code **)(*piStack_264 + 0x1c))(&uStack_23c);
  (**(code **)(*piVar4 + 0x2c))(uStack_268);
  FUN_00569460(&piStack_260,piVar4);
  FUN_00553050();
  (**(code **)(*piStack_26c + 0x24))(pvVar5);
  if (*(char *)((int)pvVar5 + 0xc) == '\0') {
    puVar7 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      uVar6 = (**(code **)(*piVar4 + 4))();
      *puVar7 = &PTR_FUN_009bcd68;
      puVar7[1] = uVar6;
    }
    *(undefined1 *)(puVar7 + 2) = 0;
    (**(code **)(*DAT_00b5ad24 + 4))(puVar7);
    (**(code **)*puVar7)(1);
  }
  FUN_00505d80();
  _free(pvVar5);
  return;
}


// ==== FUN_005647c0 @ 0x005647c0 ====

/* WARNING: Removing unreachable block (ram,0x0056496b) */

void FUN_005647c0(void)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  void *pvVar4;
  int iVar5;
  undefined4 uVar6;
  int *in_ECX;
  uint uVar7;
  int iVar8;
  byte ******ppppppbVar9;
  byte ******ppppppbVar10;
  byte *pbVar11;
  bool bVar12;
  bool bVar13;
  undefined4 in_stack_ffffff08;
  uint in_stack_ffffff0c;
  undefined4 in_stack_ffffff10;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int *piStack_c0;
  byte ******appppppbStack_bc [2];
  undefined1 auStack_b4 [8];
  uint uStack_ac;
  uint uStack_a8;
  byte ******appppppbStack_a0 [4];
  uint uStack_90;
  int *piStack_8c;
  undefined4 uStack_88;
  undefined1 uStack_80;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined1 auStack_5c [6];
  undefined1 uStack_56;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 auStack_3c [2];
  undefined1 uStack_34;
  undefined4 uStack_24;
  undefined4 uStack_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  int *piStack_4;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_56 = 1;
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  auStack_3c[0] = 0;
  uStack_20 = 0xf;
  uStack_24 = 0;
  uStack_34 = 0;
  piStack_c0 = piVar3;
  uStack_88 = (**(code **)(*DAT_00b5a7ac + 8))();
  uStack_6c = 0xf;
  uStack_70 = 0;
  uStack_80 = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_a8 = 0xf;
  uStack_ac = 0;
  appppppbStack_bc[0] = (byte ******)((uint)appppppbStack_bc[0] & 0xffffff00);
  piStack_8c = (int *)0xf;
  uStack_90 = 0;
  appppppbStack_a0[0] = (byte ******)((uint)appppppbStack_a0[0] & 0xffffff00);
  FUN_00401740(s_<_skilltree>_009bc6f8,0xc);
  pvVar4 = operator_new(0x468);
  if (pvVar4 == (void *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = FUN_00505f10();
  }
  *(undefined4 *)(iVar5 + 700) = 0x14;
  cVar2 = FUN_005885f0();
  do {
    if (cVar2 == '\0') {
LAB_00564a50:
      FUN_00401660(auStack_3c,0,0xffffffff);
      (**(code **)(*piVar3 + 8))(auStack_5c);
      if ((piStack_4 != (int *)0x0) &&
         (cVar2 = (**(code **)(*piVar3 + 0x74))(piStack_4), cVar2 != '\0')) {
        cVar2 = (**(code **)(*piStack_4 + 0x78))(piVar3);
        if (cVar2 == '\0') {
          (**(code **)(*piVar3 + 0x74))(0);
        }
        else {
          iVar5 = (**(code **)(*piStack_4 + 0x38))();
          piVar3[1] = iVar5;
        }
      }
      piVar1 = piStack_8c;
      (**(code **)(*piStack_8c + 0x38))(piVar3);
      (**(code **)(*piVar1 + 0x1c))(&piStack_8c);
      (**(code **)(*piVar3 + 0x2c))(piVar1);
      FUN_00569460(auStack_b4,piVar3);
      (**(code **)(*piVar1 + 0x24))(0xc);
      FUN_00505d80();
      _free((void *)0xc);
      return;
    }
    uVar6 = FUN_00588600(&uStack_20);
    uVar14 = 0x5648f1;
    FUN_00401660(uVar6,0,0xffffffff);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    cVar2 = FUN_0055cad0(&piStack_c0);
    if (cVar2 != '\0') {
LAB_00564a48:
      FUN_00588700(&piStack_c0);
      goto LAB_00564a50;
    }
    uVar16 = 0xf;
    uVar15 = 0;
    in_stack_ffffff0c = in_stack_ffffff0c & 0xffffff00;
    FUN_00401660(&piStack_c0,0,0xffffffff);
    FUN_0055cf30(auStack_5c,iVar5,in_stack_ffffff08,in_stack_ffffff0c,in_stack_ffffff10,uVar14,uVar6
                 ,uVar15,uVar16);
    if (uStack_ac == 0) {
LAB_005649d2:
      ppppppbVar9 = appppppbStack_a0[0];
      if (piStack_8c < (int *)0x10) {
        ppppppbVar9 = (byte ******)appppppbStack_a0;
      }
      if (uStack_ac != 0) {
        uVar7 = uStack_ac;
        if (uStack_90 <= uStack_ac) {
          uVar7 = uStack_90;
        }
        ppppppbVar10 = appppppbStack_bc[0];
        if (uStack_a8 < 0x10) {
          ppppppbVar10 = (byte ******)appppppbStack_bc;
        }
        bVar12 = false;
        iVar8 = 0;
        bVar13 = true;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          bVar12 = *(byte *)ppppppbVar10 < *(byte *)ppppppbVar9;
          bVar13 = *(byte *)ppppppbVar10 == *(byte *)ppppppbVar9;
          ppppppbVar10 = (byte ******)((int)ppppppbVar10 + 1);
          ppppppbVar9 = (byte ******)((int)ppppppbVar9 + 1);
        } while (bVar13);
        if (!bVar13) {
          iVar8 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        }
        piVar3 = in_ECX;
        if (iVar8 != 0) goto LAB_00564a2a;
      }
      if ((uStack_90 <= uStack_ac) && (uStack_ac == uStack_90)) goto LAB_00564a48;
    }
    else {
      uVar7 = uStack_ac;
      if (6 < uStack_ac) {
        uVar7 = 7;
      }
      ppppppbVar9 = appppppbStack_bc[0];
      if (uStack_a8 < 0x10) {
        ppppppbVar9 = (byte ******)appppppbStack_bc;
      }
      bVar12 = false;
      iVar8 = 0;
      bVar13 = true;
      pbVar11 = (byte *)s_<image>_009bc708;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        bVar12 = *(byte *)ppppppbVar9 < *pbVar11;
        bVar13 = *(byte *)ppppppbVar9 == *pbVar11;
        ppppppbVar9 = (byte ******)((int)ppppppbVar9 + 1);
        pbVar11 = pbVar11 + 1;
      } while (bVar13);
      if (!bVar13) {
        iVar8 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
      }
      if (((iVar8 != 0) || (uStack_ac < 7)) || (uStack_ac != 7)) {
        piVar3 = in_ECX;
        goto LAB_005649d2;
      }
      FUN_0055d1f0(iVar5);
      piVar3 = in_ECX;
    }
LAB_00564a2a:
    cVar2 = FUN_005885f0();
  } while( true );
}


// ==== FUN_00564b90 @ 0x00564b90 ====

/* WARNING: Removing unreachable block (ram,0x00564def) */

void FUN_00564b90(void)

{
  int *piVar1;
  char cVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int *unaff_EBX;
  int *unaff_EBP;
  int *unaff_ESI;
  byte ******ppppppbVar8;
  int *unaff_EDI;
  byte *pbVar9;
  bool bVar10;
  bool bVar11;
  undefined4 in_stack_fffffe38;
  uint in_stack_fffffe3c;
  undefined4 in_stack_fffffe40;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 local_194;
  byte ******appppppbStack_190 [4];
  uint uStack_180;
  uint uStack_17c;
  void *pvStack_178;
  undefined4 uStack_174;
  int *piStack_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  uint uStack_164;
  void *pvStack_15c;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  uint uStack_148;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  void *pvStack_120;
  undefined4 uStack_11c;
  int *piStack_118;
  undefined1 auStack_114 [6];
  undefined1 uStack_10e;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  void *pvStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  uint uStack_f0;
  undefined1 uStack_ec;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  void *pvStack_d4;
  undefined4 uStack_c4;
  uint uStack_c0;
  undefined1 auStack_bc [8];
  undefined1 auStack_b4 [28];
  undefined1 auStack_98 [28];
  undefined1 auStack_7c [28];
  undefined1 auStack_60 [28];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  undefined1 auStack_24 [16];
  undefined1 auStack_14 [16];
  int *piStack_4;
  
  (**(code **)(*DAT_00b5a7ac + 4))();
  uStack_10e = 1;
  uStack_10c = 0;
  uStack_108 = 0;
  pvStack_104 = (void *)0x0;
  uStack_100 = 0;
  uStack_fc = 0;
  uStack_f8 = 0;
  uStack_f4 = 0;
  uStack_d8 = 0xf;
  uStack_dc = 0;
  uStack_ec = 0;
  uVar15 = 0x17;
  uStack_16c = (**(code **)(*DAT_00b5a7ac + 8))(0x17);
  uStack_134 = 0xf;
  uStack_138 = 0;
  uStack_148 = uStack_148 & 0xffffff00;
  uStack_130 = 0;
  uStack_12c = 0;
  uStack_128 = 0;
  pvStack_178 = (void *)0x0;
  uStack_174 = 0;
  piStack_170 = (int *)0x0;
  uStack_17c = 0xf;
  uStack_180 = 0;
  appppppbStack_190[0] = (byte ******)((uint)appppppbStack_190[0] & 0xffffff00);
  uStack_150 = 0xf;
  uStack_154 = 0;
  uStack_164 = uStack_164 & 0xffffff00;
  FUN_00401740(s_<_casebox>_009bc710,10);
  pvVar3 = operator_new(0x468);
  if (pvVar3 == (void *)0x0) {
    pvVar3 = (void *)0x0;
  }
  else {
    pvVar3 = (void *)FUN_00505f10();
  }
  FUN_0056b080();
  cVar2 = FUN_005885f0();
  do {
    if (cVar2 == '\0') {
LAB_005650e1:
      FUN_00401660(&uStack_f4,0,0xffffffff);
      (**(code **)(*unaff_EBX + 8))(auStack_114);
      if ((piStack_4 != (int *)0x0) &&
         (cVar2 = (**(code **)(*unaff_EBP + 0x74))(piStack_4), cVar2 != '\0')) {
        cVar2 = (**(code **)(*piStack_4 + 0x78))(unaff_EBP);
        if (cVar2 == '\0') {
          (**(code **)(*unaff_ESI + 0x74))(0);
        }
        else {
          iVar7 = (**(code **)(*piStack_4 + 0x38))();
          unaff_EBP[1] = iVar7;
        }
      }
      piVar1 = piStack_170;
      (**(code **)(*piStack_170 + 0x38))(unaff_EBP);
      (**(code **)(*piVar1 + 0x1c))(&uStack_154);
      (**(code **)(*unaff_EDI + 0x2c))(piVar1);
      FUN_00569460(&pvStack_178,uVar15);
      (**(code **)(*piVar1 + 0x24))(pvVar3);
      if (pvVar3 != (void *)0x0) {
        FUN_00505d80();
        _free(pvVar3);
        return;
      }
      if (0xf < uStack_164) {
        _free(pvStack_178);
        return;
      }
      uStack_164 = 0xf;
      uStack_168 = 0;
      pvStack_178 = (void *)((uint)pvStack_178 & 0xffffff00);
      if ((byte ******)0xf < appppppbStack_190[0]) {
        _free(unaff_ESI);
        return;
      }
      appppppbStack_190[0] = (byte ******)0xf;
      local_194 = 0;
      if (0xf < uStack_148) {
        _free(pvStack_15c);
        return;
      }
      uStack_148 = 0xf;
      uStack_14c = 0;
      pvStack_15c = (void *)((uint)pvStack_15c & 0xffffff00);
      if (uStack_f0 < 0x10) {
        return;
      }
      _free(pvStack_104);
      return;
    }
    uVar4 = FUN_00588600(&uStack_d8);
    uVar12 = 0x564ccd;
    FUN_00401660(uVar4,0,0xffffffff);
    if (0xf < uStack_c0) {
      _free(pvStack_d4);
      return;
    }
    uStack_c0 = 0xf;
    uStack_c4 = 0;
    pvStack_d4 = (void *)((uint)pvStack_d4 & 0xffffff00);
    cVar2 = FUN_0055cad0(&local_194);
    if (cVar2 != '\0') {
LAB_005650d9:
      FUN_00588700(&local_194);
      goto LAB_005650e1;
    }
    uVar14 = 0xf;
    uVar13 = 0;
    in_stack_fffffe3c = in_stack_fffffe3c & 0xffffff00;
    FUN_00401660(&local_194,0,0xffffffff);
    FUN_0055cf30(auStack_114,pvVar3,in_stack_fffffe38,in_stack_fffffe3c,in_stack_fffffe40,uVar12,
                 uVar4,uVar13,uVar14);
    if (uStack_180 == 0) {
code_r0x00564df2:
      if (uStack_180 != 0) {
        uVar6 = uStack_180;
        if (8 < uStack_180) {
          uVar6 = 9;
        }
        ppppppbVar8 = appppppbStack_190[0];
        if (uStack_17c < 0x10) {
          ppppppbVar8 = (byte ******)appppppbStack_190;
        }
        bVar10 = false;
        iVar7 = 0;
        bVar11 = true;
        pbVar9 = (byte *)s_<iconimg>_009bc724;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          bVar10 = *(byte *)ppppppbVar8 < *pbVar9;
          bVar11 = *(byte *)ppppppbVar8 == *pbVar9;
          ppppppbVar8 = (byte ******)((int)ppppppbVar8 + 1);
          pbVar9 = pbVar9 + 1;
        } while (bVar11);
        if (!bVar11) {
          iVar7 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        }
        if (((iVar7 == 0) && (8 < uStack_180)) && (uStack_180 == 9)) {
          FUN_0055d1f0((int)pvVar3 + 0x2c0);
          goto LAB_005650bb;
        }
      }
      in_stack_fffffe40 = 0x564e65;
      iVar7 = FUN_00403620(0,uStack_180,&DAT_009bc730,4);
      if (iVar7 == 0) {
        puVar5 = (undefined4 *)FUN_0055cde0(auStack_14);
        *(undefined4 *)((int)pvVar3 + 0x2d8) = *puVar5;
        *(undefined4 *)((int)pvVar3 + 0x2dc) = puVar5[1];
        *(undefined4 *)((int)pvVar3 + 0x2e0) = puVar5[2];
        *(undefined4 *)((int)pvVar3 + 0x2e4) = puVar5[3];
      }
      else {
        in_stack_fffffe40 = 0x564eb6;
        iVar7 = FUN_00403620(0,uStack_180,s_title_009bc738,5);
        if (iVar7 == 0) {
          puVar5 = (undefined4 *)FUN_0055cde0(auStack_24);
          *(undefined4 *)((int)pvVar3 + 0x2e8) = *puVar5;
          *(undefined4 *)((int)pvVar3 + 0x2ec) = puVar5[1];
          *(undefined4 *)((int)pvVar3 + 0x2f0) = puVar5[2];
          *(undefined4 *)((int)pvVar3 + 0x2f4) = puVar5[3];
        }
        else {
          in_stack_fffffe40 = 0x564f07;
          iVar7 = FUN_00403620(0,uStack_180,&DAT_009bc740,4);
          if (iVar7 == 0) {
            puVar5 = (undefined4 *)FUN_0055cde0(auStack_34);
            *(undefined4 *)((int)pvVar3 + 0x2f8) = *puVar5;
            *(undefined4 *)((int)pvVar3 + 0x2fc) = puVar5[1];
            *(undefined4 *)((int)pvVar3 + 0x300) = puVar5[2];
            *(undefined4 *)((int)pvVar3 + 0x304) = puVar5[3];
          }
          else {
            in_stack_fffffe40 = 0x564f58;
            iVar7 = FUN_00403620(0,uStack_180,s_content_009bc748,7);
            if (iVar7 == 0) {
              puVar5 = (undefined4 *)FUN_0055cde0(auStack_44);
              *(undefined4 *)((int)pvVar3 + 0x308) = *puVar5;
              *(undefined4 *)((int)pvVar3 + 0x30c) = puVar5[1];
              *(undefined4 *)((int)pvVar3 + 0x310) = puVar5[2];
              *(undefined4 *)((int)pvVar3 + 0x314) = puVar5[3];
            }
            else {
              cVar2 = FUN_004036a0(&local_194,s_titlecolor_009bc750);
              if (cVar2 != '\0') {
                uVar15 = FUN_00588600(auStack_b4);
                uVar15 = thunk_FUN_00796e90(uVar15);
                *(undefined4 *)((int)pvVar3 + 0x328) = uVar15;
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              cVar2 = FUN_004036a0(&local_194,s_timecolor_009bc75c);
              if (cVar2 != '\0') {
                uVar15 = FUN_00588600(auStack_60);
                uVar15 = thunk_FUN_00796e90(uVar15);
                *(undefined4 *)((int)pvVar3 + 0x330) = uVar15;
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              cVar2 = FUN_004036a0(&local_194,s_contentcolor_009bc768);
              if (cVar2 != '\0') {
                uVar15 = FUN_00588600(auStack_7c);
                uVar15 = thunk_FUN_00796e90(uVar15);
                *(undefined4 *)((int)pvVar3 + 0x32c) = uVar15;
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              cVar2 = FUN_004036a0(&local_194,s_readcolor_009bc778);
              if (cVar2 != '\0') {
                uVar15 = FUN_00588600(auStack_98);
                uVar15 = thunk_FUN_00796e90(uVar15);
                *(undefined4 *)((int)pvVar3 + 0x334) = uVar15;
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              cVar2 = FUN_00423420(&local_194,&uStack_168);
              if (cVar2 != '\0') goto LAB_005650d9;
            }
          }
        }
      }
    }
    else {
      uVar6 = uStack_180;
      if (6 < uStack_180) {
        uVar6 = 7;
      }
      ppppppbVar8 = appppppbStack_190[0];
      if (uStack_17c < 0x10) {
        ppppppbVar8 = (byte ******)appppppbStack_190;
      }
      bVar10 = false;
      iVar7 = 0;
      bVar11 = true;
      pbVar9 = (byte *)s_<image>_009bc71c;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        bVar10 = *(byte *)ppppppbVar8 < *pbVar9;
        bVar11 = *(byte *)ppppppbVar8 == *pbVar9;
        ppppppbVar8 = (byte ******)((int)ppppppbVar8 + 1);
        pbVar9 = pbVar9 + 1;
      } while (bVar11);
      if (!bVar11) {
        iVar7 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
      }
      if (((iVar7 != 0) || (uStack_180 < 7)) || (uStack_180 != 7)) goto code_r0x00564df2;
      uStack_124 = FUN_0055d1f0(&pvStack_178);
      pvStack_120 = pvStack_178;
      uStack_11c = uStack_174;
      piStack_118 = piStack_170;
      FUN_0056ac60(auStack_bc,&uStack_124);
    }
LAB_005650bb:
    cVar2 = FUN_005885f0();
  } while( true );
}


// ==== FUN_00565230 @ 0x00565230 ====

/* WARNING: Removing unreachable block (ram,0x0056544d) */
/* WARNING: Removing unreachable block (ram,0x00565503) */
/* WARNING: Removing unreachable block (ram,0x00565819) */
/* WARNING: Removing unreachable block (ram,0x00565824) */
/* WARNING: Removing unreachable block (ram,0x00565831) */
/* WARNING: Removing unreachable block (ram,0x00565855) */
/* WARNING: Removing unreachable block (ram,0x0056586a) */
/* WARNING: Removing unreachable block (ram,0x0056587a) */
/* WARNING: Removing unreachable block (ram,0x005658a2) */
/* WARNING: Removing unreachable block (ram,0x005658c7) */
/* WARNING: Removing unreachable block (ram,0x005658b7) */
/* WARNING: Removing unreachable block (ram,0x00565895) */
/* WARNING: Removing unreachable block (ram,0x00565848) */

void FUN_00565230(void)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  void *pvVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 ******ppppppuVar7;
  int *in_ECX;
  uint uVar8;
  int iVar9;
  byte ******ppppppbVar10;
  byte *pbVar11;
  bool bVar12;
  bool bVar13;
  undefined4 in_stack_fffffe48;
  uint in_stack_fffffe4c;
  undefined4 in_stack_fffffe50;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int *piStack_180;
  byte ******appppppbStack_17c [3];
  undefined1 auStack_170 [4];
  uint uStack_16c;
  int *piStack_168;
  undefined4 uStack_164;
  undefined4 ******appppppuStack_15c [4];
  undefined4 uStack_14c;
  uint uStack_148;
  uint uStack_140;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  uint uStack_110;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined1 uStack_ec;
  undefined1 uStack_eb;
  undefined1 auStack_e8 [6];
  undefined1 uStack_e2;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 auStack_c8 [2];
  undefined1 uStack_c0;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  void *pvStack_a8;
  undefined4 uStack_98;
  uint uStack_94;
  undefined1 auStack_90 [4];
  void *pvStack_8c;
  undefined4 uStack_7c;
  uint uStack_78;
  undefined1 auStack_74 [4];
  void *pvStack_70;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined1 auStack_58 [4];
  void *pvStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 auStack_3c [4];
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  int *piStack_4;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_e2 = 1;
  uStack_e0 = 0;
  uStack_dc = 0;
  uStack_d8 = 0;
  uStack_d4 = 0;
  uStack_d0 = 0;
  uStack_cc = 0;
  auStack_c8[0] = 0;
  uStack_ac = 0xf;
  uStack_b0 = 0;
  uStack_c0 = 0;
  piStack_180 = piVar3;
  uStack_164 = (**(code **)(*DAT_00b5a7ac + 8))();
  uStack_12c = 0xf;
  uStack_130 = 0;
  uStack_140 = uStack_140 & 0xffffff00;
  uStack_128 = 0;
  uStack_124 = 0;
  uStack_120 = 0;
  uStack_11c = 0;
  uStack_118 = 0;
  uStack_fc = 0xf;
  uStack_100 = 0;
  uStack_110 = uStack_110 & 0xffffff00;
  uStack_f8 = 1;
  uStack_f4 = 0;
  uStack_f0 = 1;
  uStack_ec = 0;
  uStack_eb = 0;
  piStack_168 = (int *)0xf;
  uStack_16c = 0;
  appppppbStack_17c[0] = (byte ******)((uint)appppppbStack_17c[0] & 0xffffff00);
  uStack_148 = 0xf;
  uStack_14c = 0;
  appppppuStack_15c[0] = (undefined4 ******)((uint)appppppuStack_15c[0] & 0xffffff00);
  FUN_00401740(s_<_maillist>_009bc784,0xb);
  pvVar4 = operator_new(0x468);
  if (pvVar4 == (void *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = FUN_00505f10();
  }
  *(undefined4 *)(iVar5 + 0x338) = 100;
  *(undefined4 *)(iVar5 + 0x33c) = 0x14;
  *(undefined4 *)(iVar5 + 0x340) = 5;
  *(undefined4 *)(iVar5 + 0x344) = 10;
  *(undefined4 *)(iVar5 + 0x348) = 0;
  cVar2 = FUN_005885f0();
  do {
    if (cVar2 == '\0') {
LAB_00565767:
      FUN_00401660(auStack_c8,0,0xffffffff);
      (**(code **)(*piVar3 + 8))(auStack_e8);
      if ((piStack_4 != (int *)0x0) &&
         (cVar2 = (**(code **)(*piVar3 + 0x74))(piStack_4), cVar2 != '\0')) {
        cVar2 = (**(code **)(*piStack_4 + 0x78))(piVar3);
        if (cVar2 == '\0') {
          (**(code **)(*piVar3 + 0x74))(0);
        }
        else {
          iVar5 = (**(code **)(*piStack_4 + 0x38))();
          piVar3[1] = iVar5;
        }
      }
      piVar1 = piStack_168;
      (**(code **)(*piStack_168 + 0x38))(piVar3);
      (**(code **)(*piVar1 + 0x1c))(&uStack_14c);
      (**(code **)(*piVar3 + 0x2c))(piVar1);
      FUN_00569460(auStack_170,piVar3);
      FUN_00570410();
      (**(code **)(*piVar1 + 0x24))(0x18);
      FUN_00505d80();
      _free((void *)0x18);
      return;
    }
    uVar6 = FUN_00588600(auStack_90);
    uVar14 = 0x5653cf;
    FUN_00401660(uVar6,0,0xffffffff);
    if (0xf < uStack_78) {
      _free(pvStack_8c);
      return;
    }
    uStack_78 = 0xf;
    uStack_7c = 0;
    pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
    cVar2 = FUN_0055cad0(&piStack_180);
    if (cVar2 != '\0') {
      FUN_00588700(&piStack_180);
      goto LAB_00565767;
    }
    uVar16 = 0xf;
    uVar15 = 0;
    in_stack_fffffe4c = in_stack_fffffe4c & 0xffffff00;
    FUN_00401660(&piStack_180,0,0xffffffff);
    FUN_0055cf30(auStack_e8,iVar5,in_stack_fffffe48,in_stack_fffffe4c,in_stack_fffffe50,uVar14,uVar6
                 ,uVar15,uVar16);
    piVar3 = in_ECX;
    if (uStack_16c == 0) {
code_r0x00565506:
      if (uStack_16c != 0) {
        uVar8 = uStack_16c;
        if (9 < uStack_16c) {
          uVar8 = 10;
        }
        ppppppbVar10 = appppppbStack_17c[0];
        if (piStack_168 < (int *)0x10) {
          ppppppbVar10 = (byte ******)appppppbStack_17c;
        }
        bVar12 = false;
        iVar9 = 0;
        bVar13 = true;
        pbVar11 = (byte *)s_nodeheight_009bc79c;
        do {
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          bVar12 = *(byte *)ppppppbVar10 < *pbVar11;
          bVar13 = *(byte *)ppppppbVar10 == *pbVar11;
          ppppppbVar10 = (byte ******)((int)ppppppbVar10 + 1);
          pbVar11 = pbVar11 + 1;
        } while (bVar13);
        if (!bVar13) {
          iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        }
        if (((iVar9 == 0) && (9 < uStack_16c)) && (uStack_16c == 10)) {
          uVar6 = FUN_00588600(auStack_58);
          uVar6 = thunk_FUN_00796e60(uVar6);
          *(undefined4 *)(iVar5 + 0x33c) = uVar6;
          if (0xf < uStack_40) {
            _free(pvStack_54);
            return;
          }
          uStack_40 = 0xf;
          uStack_44 = 0;
          pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
          goto LAB_00565735;
        }
      }
      in_stack_fffffe50 = 0x5655c7;
      iVar9 = FUN_00403620(0,uStack_16c,s_offset_009bc7a8,6);
      if (iVar9 == 0) {
        uVar6 = FUN_00588600(auStack_20);
        uVar6 = thunk_FUN_00796e60(uVar6);
        *(undefined4 *)(iVar5 + 0x340) = uVar6;
        if (0xf < uStack_8) {
          _free(pvStack_1c);
          return;
        }
        uStack_8 = 0xf;
        uStack_c = 0;
        pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      }
      else {
        in_stack_fffffe50 = 0x56563c;
        iVar9 = FUN_00403620(0,uStack_16c,s_topmargin_009bc7b0,9);
        if (iVar9 == 0) {
          uVar6 = FUN_00588600(auStack_74);
          uVar6 = thunk_FUN_00796e60(uVar6);
          *(undefined4 *)(iVar5 + 0x344) = uVar6;
          if (0xf < uStack_5c) {
            _free(pvStack_70);
            return;
          }
          uStack_5c = 0xf;
          uStack_60 = 0;
          pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
        }
        else {
          in_stack_fffffe50 = 0x5656b1;
          iVar9 = FUN_00403620(0,uStack_16c,&DAT_009bc7bc,3);
          if (iVar9 == 0) {
            uVar6 = FUN_00588600(auStack_3c);
            uVar6 = thunk_FUN_00796e60(uVar6);
            *(undefined4 *)(iVar5 + 0x348) = uVar6;
            if (0xf < uStack_24) {
              _free(pvStack_38);
              return;
            }
            uStack_24 = 0xf;
            uStack_28 = 0;
            pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
          }
          else {
            ppppppuVar7 = appppppuStack_15c[0];
            if (uStack_148 < 0x10) {
              ppppppuVar7 = appppppuStack_15c;
            }
            in_stack_fffffe50 = 0x565731;
            iVar9 = FUN_00403620(0,uStack_16c,ppppppuVar7,uStack_14c);
            if (iVar9 == 0) {
              FUN_00588700(&piStack_180);
              goto LAB_00565767;
            }
          }
        }
      }
    }
    else {
      uVar8 = uStack_16c;
      if (8 < uStack_16c) {
        uVar8 = 9;
      }
      ppppppbVar10 = appppppbStack_17c[0];
      if (piStack_168 < (int *)0x10) {
        ppppppbVar10 = (byte ******)appppppbStack_17c;
      }
      bVar12 = false;
      iVar9 = 0;
      bVar13 = true;
      pbVar11 = (byte *)s_nodewidth_009bc790;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        bVar12 = *(byte *)ppppppbVar10 < *pbVar11;
        bVar13 = *(byte *)ppppppbVar10 == *pbVar11;
        ppppppbVar10 = (byte ******)((int)ppppppbVar10 + 1);
        pbVar11 = pbVar11 + 1;
      } while (bVar13);
      if (!bVar13) {
        iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
      }
      if (((iVar9 != 0) || (uStack_16c < 9)) || (uStack_16c != 9)) goto code_r0x00565506;
      uVar6 = FUN_00588600(&uStack_ac);
      uVar6 = thunk_FUN_00796e60(uVar6);
      *(undefined4 *)(iVar5 + 0x338) = uVar6;
      if (0xf < uStack_94) {
        _free(pvStack_a8);
        return;
      }
      uStack_94 = 0xf;
      uStack_98 = 0;
      pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
    }
LAB_00565735:
    cVar2 = FUN_005885f0();
  } while( true );
}


// ==== FUN_005658e0 @ 0x005658e0 ====

/* WARNING: Removing unreachable block (ram,0x00565abc) */
/* WARNING: Removing unreachable block (ram,0x00565b22) */

void FUN_005658e0(void)

{
  int *piVar1;
  char cVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 *****pppppuVar5;
  uint uVar6;
  int iVar7;
  int *unaff_EBX;
  int *unaff_EBP;
  int *unaff_ESI;
  byte *****pppppbVar8;
  int *unaff_EDI;
  byte *pbVar9;
  bool bVar10;
  bool bVar11;
  undefined4 in_stack_fffffe78;
  uint in_stack_fffffe7c;
  undefined4 in_stack_fffffe80;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  void *pvStack_158;
  undefined4 local_150;
  byte *****apppppbStack_14c [2];
  void *apvStack_144 [2];
  uint uStack_13c;
  uint uStack_138;
  undefined4 uStack_134;
  undefined4 *****apppppuStack_130 [4];
  undefined4 uStack_120;
  int *piStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined1 auStack_10c [4];
  void *pvStack_108;
  undefined4 uStack_f8;
  uint uStack_f4;
  void *pvStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined1 uStack_e4;
  undefined1 uStack_e3;
  undefined4 uStack_e0;
  uint uStack_dc;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  void *pvStack_a8;
  undefined4 uStack_98;
  uint uStack_94;
  void *pvStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined1 uStack_84;
  undefined1 uStack_83;
  undefined1 auStack_80 [6];
  undefined1 uStack_7a;
  undefined4 uStack_78;
  undefined4 uStack_74;
  void *pvStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined1 uStack_58;
  undefined4 uStack_48;
  undefined4 uStack_44;
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  undefined1 auStack_c [8];
  int *piStack_4;
  
  (**(code **)(*DAT_00b5a7ac + 4))();
  uStack_7a = 1;
  uStack_78 = 0;
  uStack_74 = 0;
  pvStack_70 = (void *)0x0;
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_44 = 0xf;
  uStack_48 = 0;
  uStack_58 = 0;
  uVar15 = 0xe;
  uStack_118 = (**(code **)(*DAT_00b5a7ac + 8))(0xe);
  uStack_c8 = 0xf;
  uStack_cc = 0;
  uStack_dc = uStack_dc & 0xffffff00;
  uStack_c4 = 0;
  uStack_c0 = 0;
  uStack_bc = 0;
  uStack_138 = 0xf;
  uStack_13c = 0;
  apppppbStack_14c[0] = (byte *****)((uint)apppppbStack_14c[0] & 0xffffff00);
  piStack_11c = (int *)0xf;
  uStack_120 = 0;
  apppppuStack_130[0] = (undefined4 *****)((uint)apppppuStack_130[0] & 0xffffff00);
  FUN_00401740(s_<_messengertree>_009bc7c0,0x10);
  pvVar3 = operator_new(0x468);
  if (pvVar3 == (void *)0x0) {
    pvStack_158 = (void *)0x0;
  }
  else {
    pvStack_158 = (void *)FUN_00505f10();
  }
  FUN_00503950(*(undefined4 *)(*(int *)((int)pvStack_158 + 0x11c) + 4));
  *(int *)(*(int *)((int)pvStack_158 + 0x11c) + 4) = *(int *)((int)pvStack_158 + 0x11c);
  *(undefined4 *)((int)pvStack_158 + 0x120) = 0;
  *(undefined4 *)*(undefined4 *)((int)pvStack_158 + 0x11c) =
       *(undefined4 *)((int)pvStack_158 + 0x11c);
  *(int *)(*(int *)((int)pvStack_158 + 0x11c) + 8) = *(int *)((int)pvStack_158 + 0x11c);
  *(undefined1 *)((int)pvStack_158 + 0x114) = 0;
  *(undefined1 *)((int)pvStack_158 + 0x115) = 0;
  cVar2 = FUN_005885f0();
  do {
    if (cVar2 == '\0') {
LAB_00565d92:
      FUN_00401660(&uStack_60,0,0xffffffff);
      (**(code **)(*unaff_EBX + 8))(auStack_80);
      if ((piStack_4 != (int *)0x0) &&
         (cVar2 = (**(code **)(*unaff_EBP + 0x74))(piStack_4), cVar2 != '\0')) {
        cVar2 = (**(code **)(*piStack_4 + 0x78))(unaff_EBP);
        if (cVar2 == '\0') {
          (**(code **)(*unaff_ESI + 0x74))(0);
        }
        else {
          iVar7 = (**(code **)(*piStack_4 + 0x38))();
          unaff_EBP[1] = iVar7;
        }
      }
      piVar1 = piStack_11c;
      (**(code **)(*piStack_11c + 0x38))(unaff_EBP);
      (**(code **)(*piVar1 + 0x1c))(&uStack_e8);
      (**(code **)(*unaff_EDI + 0x2c))(piVar1);
      FUN_00569460(apvStack_144,uVar15);
      (**(code **)(*piVar1 + 0x24))(pvStack_158);
      if (pvStack_158 != (void *)0x0) {
        FUN_00505d80();
        _free(pvStack_158);
        return;
      }
      if ((undefined4 *****)0xf < apppppuStack_130[0]) {
        _free(apvStack_144[0]);
        return;
      }
      apppppuStack_130[0] = (undefined4 *****)0xf;
      uStack_134 = 0;
      apvStack_144[0] = (void *)((uint)apvStack_144[0] & 0xffffff00);
      if ((byte *****)0xf < apppppbStack_14c[0]) {
        _free(unaff_EBP);
        return;
      }
      apppppbStack_14c[0] = (byte *****)0xf;
      local_150 = 0;
      if (0xf < uStack_dc) {
        _free(pvStack_f0);
        return;
      }
      uStack_dc = 0xf;
      uStack_e0 = 0;
      pvStack_f0 = (void *)((uint)pvStack_f0 & 0xffffff00);
      if (uStack_5c < 0x10) {
        return;
      }
      _free(pvStack_70);
      return;
    }
    uVar4 = FUN_00588600(auStack_28);
    uVar12 = 0x565a41;
    FUN_00401660(uVar4,0,0xffffffff);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    cVar2 = FUN_0055cad0(&local_150);
    if (cVar2 != '\0') {
      FUN_00588700(&local_150);
      goto LAB_00565d92;
    }
    uVar14 = 0xf;
    uVar13 = 0;
    in_stack_fffffe7c = in_stack_fffffe7c & 0xffffff00;
    FUN_00401660(&local_150,0,0xffffffff);
    FUN_0055cf30(auStack_80,pvStack_158,in_stack_fffffe78,in_stack_fffffe7c,in_stack_fffffe80,uVar12
                 ,uVar4,uVar13,uVar14);
    if (uStack_13c == 0) {
code_r0x00565b25:
      if (uStack_13c != 0) {
        uVar6 = uStack_13c;
        if (9 < uStack_13c) {
          uVar6 = 10;
        }
        pppppbVar8 = apppppbStack_14c[0];
        if (uStack_138 < 0x10) {
          pppppbVar8 = (byte *****)apppppbStack_14c;
        }
        bVar10 = false;
        iVar7 = 0;
        bVar11 = true;
        pbVar9 = (byte *)s_nodeheight_009bc7dc;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          bVar10 = *(byte *)pppppbVar8 < *pbVar9;
          bVar11 = *(byte *)pppppbVar8 == *pbVar9;
          pppppbVar8 = (byte *****)((int)pppppbVar8 + 1);
          pbVar9 = pbVar9 + 1;
        } while (bVar11);
        if (!bVar11) {
          iVar7 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        }
        if (((iVar7 == 0) && (9 < uStack_13c)) && (uStack_13c == 10)) {
          uVar4 = FUN_00588600(&uStack_44);
          uVar4 = thunk_FUN_00796e60(uVar4);
          *(undefined4 *)((int)pvStack_158 + 700) = uVar4;
          if (0xf < uStack_2c) {
            _free(pvStack_40);
            return;
          }
          uStack_2c = 0xf;
          uStack_30 = 0;
          pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
          goto LAB_00565d5c;
        }
      }
      in_stack_fffffe80 = 0x565be6;
      iVar7 = FUN_00403620(0,uStack_13c,s_<title>_009bc7e8,7);
      if (iVar7 == 0) {
        pvStack_f0 = (void *)0x1;
        uStack_e8 = 1;
        uStack_114 = 0;
        uStack_110 = 0;
        uStack_f4 = 0xf;
        uStack_f8 = 0;
        pvStack_108 = (void *)((uint)pvStack_108 & 0xffffff00);
        uStack_ec = 0;
        uStack_e4 = 0;
        uStack_e3 = 0;
        uStack_b8 = FUN_0055dde0(&uStack_114);
        uStack_b4 = uStack_114;
        uStack_b0 = uStack_110;
        uStack_94 = 0xf;
        uStack_98 = 0;
        pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
        FUN_00401660(auStack_10c,0,0xffffffff);
        pvStack_90 = pvStack_f0;
        uStack_88 = uStack_e8;
        uStack_84 = uStack_e4;
        uStack_8c = uStack_ec;
        uStack_83 = uStack_e3;
        FUN_00505600(auStack_c,&uStack_b8);
        if (0xf < uStack_94) {
          _free(pvStack_a8);
          return;
        }
        uStack_94 = 0xf;
        uStack_98 = 0;
        pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
        if (0xf < uStack_f4) {
          _free(pvStack_108);
          return;
        }
        uStack_f4 = 0xf;
        uStack_f8 = 0;
        pvStack_108 = (void *)((uint)pvStack_108 & 0xffffff00);
      }
      else {
        pppppuVar5 = apppppuStack_130[0];
        if (piStack_11c < (int *)0x10) {
          pppppuVar5 = apppppuStack_130;
        }
        in_stack_fffffe80 = 0x565d58;
        iVar7 = FUN_00403620(0,uStack_13c,pppppuVar5,uStack_120);
        if (iVar7 == 0) {
          FUN_00588700(&local_150);
          goto LAB_00565d92;
        }
      }
    }
    else {
      uVar6 = uStack_13c;
      if (6 < uStack_13c) {
        uVar6 = 7;
      }
      pppppbVar8 = apppppbStack_14c[0];
      if (uStack_138 < 0x10) {
        pppppbVar8 = (byte *****)apppppbStack_14c;
      }
      bVar10 = false;
      iVar7 = 0;
      bVar11 = true;
      pbVar9 = (byte *)s_<image>_009bc7d4;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        bVar10 = *(byte *)pppppbVar8 < *pbVar9;
        bVar11 = *(byte *)pppppbVar8 == *pbVar9;
        pppppbVar8 = (byte *****)((int)pppppbVar8 + 1);
        pbVar9 = pbVar9 + 1;
      } while (bVar11);
      if (!bVar11) {
        iVar7 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
      }
      if (((iVar7 != 0) || (uStack_13c < 7)) || (uStack_13c != 7)) goto code_r0x00565b25;
      FUN_0055d1f0(pvStack_158);
    }
LAB_00565d5c:
    cVar2 = FUN_005885f0();
  } while( true );
}


// ==== FUN_00565ef0 @ 0x00565ef0 ====

/* WARNING: Removing unreachable block (ram,0x005660a5) */
/* WARNING: Removing unreachable block (ram,0x0056610b) */

void FUN_00565ef0(void)

{
  char cVar1;
  void *pvVar2;
  int *_Memory;
  undefined4 uVar3;
  int *piVar4;
  undefined4 ******ppppppuVar5;
  uint uVar6;
  int iVar7;
  int *unaff_EBP;
  int *unaff_ESI;
  byte ******ppppppbVar8;
  undefined4 unaff_EDI;
  byte *pbVar9;
  bool bVar10;
  bool bVar11;
  undefined4 in_stack_fffffec8;
  uint in_stack_fffffecc;
  undefined4 in_stack_fffffed0;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int *piStack_108;
  undefined4 local_100;
  byte ******appppppbStack_fc [3];
  void *pvStack_f0;
  uint uStack_ec;
  int *piStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 ******appppppuStack_dc [2];
  void *pvStack_d4;
  undefined4 uStack_cc;
  uint uStack_c8;
  undefined4 uStack_c4;
  uint uStack_c0;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined1 auStack_9c [6];
  undefined1 uStack_96;
  undefined4 uStack_94;
  undefined4 uStack_90;
  void *pvStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  uint uStack_78;
  undefined1 uStack_74;
  undefined4 uStack_64;
  undefined4 uStack_60;
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  undefined1 auStack_c [8];
  int *piStack_4;
  
  (**(code **)(*DAT_00b5a7ac + 4))();
  uStack_96 = 1;
  uStack_94 = 0;
  uStack_90 = 0;
  pvStack_8c = (void *)0x0;
  uStack_88 = 0;
  uStack_84 = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  uStack_60 = 0xf;
  uStack_64 = 0;
  uStack_74 = 0;
  uStack_e4 = (**(code **)(*DAT_00b5a7ac + 8))(0x14);
  uStack_ac = 0xf;
  uStack_b0 = 0;
  uStack_c0 = uStack_c0 & 0xffffff00;
  uStack_a8 = 0;
  uStack_a4 = 0;
  uStack_a0 = 0;
  piStack_e8 = (int *)0xf;
  uStack_ec = 0;
  appppppbStack_fc[0] = (byte ******)((uint)appppppbStack_fc[0] & 0xffffff00);
  uStack_c8 = 0xf;
  uStack_cc = 0;
  appppppuStack_dc[0] = (undefined4 ******)((uint)appppppuStack_dc[0] & 0xffffff00);
  FUN_00401740(s_<_slidebar>_009bc7f0,0xb);
  pvVar2 = operator_new(0x468);
  if (pvVar2 == (void *)0x0) {
    _Memory = (int *)0x0;
  }
  else {
    _Memory = (int *)FUN_00505f10();
  }
  _Memory[0x83] = 0;
  _Memory[0x84] = 0;
  _Memory[0x85] = 0;
  _Memory[0x86] = 0;
  cVar1 = FUN_005885f0();
  do {
    if (cVar1 == '\0') {
LAB_005662c5:
      FUN_00401660(&uStack_7c,0,0xffffffff);
      (**(code **)(*piStack_108 + 8))(auStack_9c);
      if ((piStack_4 != (int *)0x0) &&
         (cVar1 = (**(code **)(*_Memory + 0x74))(piStack_4), cVar1 != '\0')) {
        cVar1 = (**(code **)(*piStack_4 + 0x78))(_Memory);
        if (cVar1 == '\0') {
          (**(code **)(*unaff_EBP + 0x74))(0);
        }
        else {
          iVar7 = (**(code **)(*piStack_4 + 0x38))();
          _Memory[1] = iVar7;
        }
      }
      piVar4 = piStack_e8;
      (**(code **)(*piStack_e8 + 0x38))(_Memory);
      (**(code **)(*piVar4 + 0x1c))(&uStack_cc);
      (**(code **)(*unaff_ESI + 0x2c))(piVar4);
      FUN_00569460(&pvStack_f0,unaff_EDI);
      (**(code **)(*piVar4 + 0x24))(_Memory);
      if (_Memory != (int *)0x0) {
        FUN_00505d80();
        _free(_Memory);
        return;
      }
      if ((undefined4 ******)0xf < appppppuStack_dc[0]) {
        _free(pvStack_f0);
        return;
      }
      appppppuStack_dc[0] = (undefined4 ******)0xf;
      uStack_e0 = 0;
      pvStack_f0 = (void *)((uint)pvStack_f0 & 0xffffff00);
      if ((byte ******)0xf < appppppbStack_fc[0]) {
        _free(unaff_EBP);
        return;
      }
      appppppbStack_fc[0] = (byte ******)0xf;
      local_100 = 0;
      if (0xf < uStack_c0) {
        _free(pvStack_d4);
        return;
      }
      uStack_c0 = 0xf;
      uStack_c4 = 0;
      pvStack_d4 = (void *)((uint)pvStack_d4 & 0xffffff00);
      if (uStack_78 < 0x10) {
        return;
      }
      _free(pvStack_8c);
      return;
    }
    uVar3 = FUN_00588600(&uStack_60);
    uVar12 = 0x56602f;
    FUN_00401660(uVar3,0,0xffffffff);
    if (0xf < uStack_48) {
      _free(pvStack_5c);
      return;
    }
    uStack_48 = 0xf;
    uStack_4c = 0;
    pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
    cVar1 = FUN_0055cad0(&local_100);
    if (cVar1 != '\0') {
      FUN_00588700(&local_100);
      goto LAB_005662c5;
    }
    uVar14 = 0xf;
    uVar13 = 0;
    in_stack_fffffecc = in_stack_fffffecc & 0xffffff00;
    FUN_00401660(&local_100,0,0xffffffff);
    FUN_0055cf30(auStack_9c,_Memory,in_stack_fffffec8,in_stack_fffffecc,in_stack_fffffed0,uVar12,
                 uVar3,uVar13,uVar14);
    if (uStack_ec == 0) {
code_r0x0056610e:
      if (uStack_ec != 0) {
        uVar6 = uStack_ec;
        if (2 < uStack_ec) {
          uVar6 = 3;
        }
        ppppppbVar8 = appppppbStack_fc[0];
        if (piStack_e8 < (int *)0x10) {
          ppppppbVar8 = (byte ******)appppppbStack_fc;
        }
        bVar10 = false;
        iVar7 = 0;
        bVar11 = true;
        pbVar9 = &DAT_009bc804;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          bVar10 = *(byte *)ppppppbVar8 < *pbVar9;
          bVar11 = *(byte *)ppppppbVar8 == *pbVar9;
          ppppppbVar8 = (byte ******)((int)ppppppbVar8 + 1);
          pbVar9 = pbVar9 + 1;
        } while (bVar11);
        if (!bVar11) {
          iVar7 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        }
        if (((iVar7 == 0) && (2 < uStack_ec)) && (uStack_ec == 3)) {
          uVar3 = FUN_00588600(auStack_44);
          iVar7 = thunk_FUN_00796e60(uVar3);
          _Memory[0x83] = iVar7;
          if (0xf < uStack_2c) {
            _free(pvStack_40);
            return;
          }
          uStack_2c = 0xf;
          uStack_30 = 0;
          pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
          goto LAB_00566293;
        }
      }
      in_stack_fffffed0 = 0x5661cf;
      iVar7 = FUN_00403620(0,uStack_ec,&DAT_009bc808,3);
      if (iVar7 == 0) {
        uVar3 = FUN_00588600(auStack_28);
        iVar7 = thunk_FUN_00796e60(uVar3);
        _Memory[0x84] = iVar7;
        if (0xf < uStack_10) {
          _free(pvStack_24);
          return;
        }
        uStack_10 = 0xf;
        uStack_14 = 0;
        pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
      }
      else {
        in_stack_fffffed0 = 0x566241;
        iVar7 = FUN_00403620(0,uStack_ec,s_minmaxpos_009bc80c,9);
        if (iVar7 == 0) {
          piVar4 = (int *)FUN_0055cec0(auStack_c);
          _Memory[0x85] = *piVar4;
          _Memory[0x86] = piVar4[1];
        }
        else {
          ppppppuVar5 = appppppuStack_dc[0];
          if (uStack_c8 < 0x10) {
            ppppppuVar5 = appppppuStack_dc;
          }
          in_stack_fffffed0 = 0x56628f;
          iVar7 = FUN_00403620(0,uStack_ec,ppppppuVar5,uStack_cc);
          if (iVar7 == 0) {
            FUN_00588700(&local_100);
            goto LAB_005662c5;
          }
        }
      }
    }
    else {
      uVar6 = uStack_ec;
      if (6 < uStack_ec) {
        uVar6 = 7;
      }
      ppppppbVar8 = appppppbStack_fc[0];
      if (piStack_e8 < (int *)0x10) {
        ppppppbVar8 = (byte ******)appppppbStack_fc;
      }
      bVar10 = false;
      iVar7 = 0;
      bVar11 = true;
      pbVar9 = (byte *)s_<image>_009bc7fc;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        bVar10 = *(byte *)ppppppbVar8 < *pbVar9;
        bVar11 = *(byte *)ppppppbVar8 == *pbVar9;
        ppppppbVar8 = (byte ******)((int)ppppppbVar8 + 1);
        pbVar9 = pbVar9 + 1;
      } while (bVar11);
      if (!bVar11) {
        iVar7 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
      }
      if (((iVar7 != 0) || (uStack_ec < 7)) || (uStack_ec != 7)) goto code_r0x0056610e;
      FUN_0055d1f0(_Memory);
    }
LAB_00566293:
    cVar1 = FUN_005885f0();
  } while( true );
}


// ==== FUN_00566410 @ 0x00566410 ====

void FUN_00566410(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  void *pvVar6;
  undefined4 ****ppppuVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  byte ****ppppbVar11;
  int unaff_EDI;
  byte *pbVar12;
  bool bVar13;
  bool bVar14;
  int *unaff_retaddr;
  undefined4 in_stack_fffffcfc;
  uint in_stack_fffffd00;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 *local_2d4;
  int iStack_2d0;
  undefined1 auStack_2cc [4];
  byte ****appppbStack_2c8 [4];
  uint uStack_2b8;
  uint uStack_2b4;
  int *piStack_2b0;
  int *piStack_2ac;
  int *piStack_2a8;
  byte ****appppbStack_2a4 [4];
  uint uStack_294;
  uint uStack_290;
  byte ****ppppbStack_288;
  undefined1 auStack_284 [12];
  uint uStack_278;
  uint uStack_274;
  undefined4 ****appppuStack_26c [4];
  undefined4 uStack_25c;
  uint uStack_258;
  undefined1 auStack_254 [4];
  void *pvStack_250;
  undefined1 auStack_244 [4];
  undefined4 uStack_240;
  uint uStack_23c;
  undefined1 uStack_234;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined1 auStack_210 [4];
  void *pvStack_20c;
  undefined4 uStack_1fc;
  uint uStack_1f8;
  undefined4 uStack_1f4;
  undefined4 uStack_1f0;
  undefined1 uStack_1e8;
  undefined4 uStack_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  undefined1 uStack_1c4;
  undefined1 uStack_1c3;
  undefined1 auStack_1c0 [6];
  undefined1 uStack_1ba;
  undefined4 uStack_1b8;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  undefined4 auStack_1a0 [2];
  undefined1 uStack_198;
  undefined4 uStack_188;
  undefined4 uStack_184;
  void *pvStack_180;
  undefined4 uStack_170;
  uint uStack_16c;
  undefined1 auStack_168 [4];
  void *pvStack_164;
  undefined4 uStack_154;
  uint uStack_150;
  undefined1 auStack_14c [4];
  void *pvStack_148;
  undefined4 uStack_138;
  uint uStack_134;
  undefined1 auStack_130 [4];
  void *pvStack_12c;
  undefined4 uStack_11c;
  uint uStack_118;
  undefined1 auStack_114 [4];
  void *pvStack_110;
  undefined4 uStack_100;
  uint uStack_fc;
  undefined1 auStack_f8 [4];
  void *pvStack_f4;
  undefined4 uStack_e4;
  uint uStack_e0;
  undefined1 auStack_dc [4];
  void *pvStack_d8;
  undefined4 uStack_c8;
  uint uStack_c4;
  undefined1 auStack_c0 [4];
  void *pvStack_bc;
  undefined4 uStack_ac;
  uint uStack_a8;
  undefined1 auStack_a4 [4];
  void *pvStack_a0;
  undefined4 uStack_90;
  uint uStack_8c;
  undefined1 auStack_88 [4];
  void *pvStack_84;
  undefined4 uStack_74;
  uint uStack_70;
  undefined1 auStack_6c [4];
  void *pvStack_68;
  undefined4 uStack_58;
  uint uStack_54;
  undefined1 auStack_50 [4];
  void *pvStack_4c;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined1 auStack_34 [16];
  undefined1 auStack_24 [16];
  undefined1 auStack_14 [8];
  int *piStack_c;
  int *piStack_8;
  undefined4 uStack_4;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_1ba = 1;
  uStack_1b8 = 0;
  uStack_1b4 = 0;
  uStack_1b0 = 0;
  uStack_1ac = 0;
  uStack_1a8 = 0;
  uStack_1a4 = 0;
  auStack_1a0[0] = 0;
  uStack_184 = 0xf;
  uStack_188 = 0;
  uStack_198 = 0;
  piStack_2a8 = piVar2;
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
  uStack_220 = 0xf;
  uStack_224 = 0;
  uStack_234 = 0;
  uStack_21c = 0;
  uStack_218 = 0;
  uStack_214 = 0;
  uStack_2b4 = 0xf;
  uStack_2b8 = 0;
  appppbStack_2c8[0] = (byte ****)((uint)appppbStack_2c8[0] & 0xffffff00);
  uStack_258 = 0xf;
  uStack_25c = 0;
  appppuStack_26c[0] = (undefined4 ****)((uint)appppuStack_26c[0] & 0xffffff00);
  piStack_2b0 = piVar3;
  FUN_00401740(s_<_combobox>_009bc818,0xb);
  uStack_1d0 = 1;
  uStack_1c8 = 1;
  uStack_1f4 = 0;
  uStack_1f0 = 0;
  uStack_1d4 = 0xf;
  uStack_1d8 = 0;
  uStack_1e8 = 0;
  uStack_1cc = 0;
  uStack_1c4 = 0;
  uStack_1c3 = 0;
  uVar4 = (**(code **)(*unaff_retaddr + 0x50))();
  uVar5 = FUN_004022a0(auStack_210,s_Make_ComboBox___009bc824,uVar4);
  uVar4 = 0x566576;
  FUN_00796d50(uVar5);
  if (0xf < uStack_1f8) {
    _free(pvStack_20c);
    return;
  }
  pvVar6 = operator_new(0x468);
  if (pvVar6 == (void *)0x0) {
    iStack_2d0 = 0;
  }
  else {
    iStack_2d0 = FUN_00505f10();
  }
  cVar1 = FUN_005885f0();
  if (cVar1 != '\0') {
    do {
      uVar5 = FUN_00588600(auStack_6c);
      uVar15 = 0x5665f3;
      FUN_00401660(uVar5,0,0xffffffff);
      if (0xf < uStack_54) {
        _free(pvStack_68);
        return;
      }
      uStack_54 = 0xf;
      uStack_58 = 0;
      pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
      cVar1 = FUN_0055cad0(auStack_2cc);
      if (cVar1 != '\0') {
        FUN_00588700(auStack_2cc);
        break;
      }
      uVar17 = 0xf;
      uVar16 = 0;
      in_stack_fffffd00 = in_stack_fffffd00 & 0xffffff00;
      FUN_00401660(auStack_2cc,0,0xffffffff);
      FUN_0055cf30(auStack_1c0,iStack_2d0,in_stack_fffffcfc,in_stack_fffffd00,uVar4,uVar15,uVar5,
                   uVar16,uVar17);
      if (uStack_2b8 == 0) {
LAB_005666ca:
        if (uStack_2b8 != 0) {
          uVar9 = uStack_2b8;
          if (9 < uStack_2b8) {
            uVar9 = 10;
          }
          ppppbVar11 = appppbStack_2c8[0];
          if (uStack_2b4 < 0x10) {
            ppppbVar11 = (byte ****)appppbStack_2c8;
          }
          bVar13 = false;
          iVar10 = 0;
          bVar14 = true;
          pbVar12 = (byte *)s_<nodeinfo>_009bc840;
          do {
            if (uVar9 == 0) break;
            uVar9 = uVar9 - 1;
            bVar13 = *(byte *)ppppbVar11 < *pbVar12;
            bVar14 = *(byte *)ppppbVar11 == *pbVar12;
            ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
            pbVar12 = pbVar12 + 1;
          } while (bVar14);
          if (!bVar14) {
            iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
          }
          if (((iVar10 == 0) && (9 < uStack_2b8)) && (uStack_2b8 == 10)) {
            cVar1 = FUN_005885f0();
            while (cVar1 != '\0') {
              uVar5 = FUN_00588600(&uStack_184);
              FUN_00401660(uVar5,0,0xffffffff);
              if (0xf < uStack_16c) {
                _free(pvStack_180);
                return;
              }
              uStack_16c = 0xf;
              uStack_170 = 0;
              pvStack_180 = (void *)((uint)pvStack_180 & 0xffffff00);
              if (uStack_2b8 == 0) {
LAB_00566813:
                if (uStack_2b8 != 0) {
                  uVar9 = uStack_2b8;
                  if (6 < uStack_2b8) {
                    uVar9 = 7;
                  }
                  ppppbVar11 = appppbStack_2c8[0];
                  if (uStack_2b4 < 0x10) {
                    ppppbVar11 = (byte ****)appppbStack_2c8;
                  }
                  bVar13 = false;
                  iVar10 = 0;
                  bVar14 = true;
                  pbVar12 = (byte *)s_selrect_009bc854;
                  do {
                    if (uVar9 == 0) break;
                    uVar9 = uVar9 - 1;
                    bVar13 = *(byte *)ppppbVar11 < *pbVar12;
                    bVar14 = *(byte *)ppppbVar11 == *pbVar12;
                    ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
                    pbVar12 = pbVar12 + 1;
                  } while (bVar14);
                  if (!bVar14) {
                    iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                  }
                  if (((iVar10 == 0) && (6 < uStack_2b8)) && (uStack_2b8 == 7)) {
                    puVar8 = (undefined4 *)FUN_0055cde0(auStack_24);
                    *(undefined4 *)(iStack_2d0 + 0x24c) = *puVar8;
                    *(undefined4 *)(iStack_2d0 + 0x250) = puVar8[1];
                    *(undefined4 *)(iStack_2d0 + 0x254) = puVar8[2];
                    *(undefined4 *)(iStack_2d0 + 600) = puVar8[3];
                    goto LAB_00566d36;
                  }
                }
                if (uStack_2b8 != 0) {
                  uVar9 = uStack_2b8;
                  if (6 < uStack_2b8) {
                    uVar9 = 7;
                  }
                  ppppbVar11 = appppbStack_2c8[0];
                  if (uStack_2b4 < 0x10) {
                    ppppbVar11 = (byte ****)appppbStack_2c8;
                  }
                  bVar13 = false;
                  iVar10 = 0;
                  bVar14 = true;
                  pbVar12 = (byte *)s_<image>_009bc85c;
                  do {
                    if (uVar9 == 0) break;
                    uVar9 = uVar9 - 1;
                    bVar13 = *(byte *)ppppbVar11 < *pbVar12;
                    bVar14 = *(byte *)ppppbVar11 == *pbVar12;
                    ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
                    pbVar12 = pbVar12 + 1;
                  } while (bVar14);
                  if (!bVar14) {
                    iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                  }
                  if (((iVar10 == 0) && (6 < uStack_2b8)) && (uStack_2b8 == 7)) {
                    uStack_274 = 0xf;
                    uStack_278 = 0;
                    ppppbStack_288 = (byte ****)((uint)ppppbStack_288 & 0xffffff00);
                    uStack_23c = 0xf;
                    uStack_240 = 0;
                    pvStack_250 = (void *)((uint)pvStack_250 & 0xffffff00);
                    local_2d4 = operator_new(0xc);
                    if (local_2d4 == (undefined4 *)0x0) {
                      local_2d4 = (undefined4 *)0x0;
                    }
                    else {
                      *local_2d4 = 0;
                      local_2d4[1] = 0;
                      local_2d4[2] = 0;
                    }
                    *local_2d4 = 0;
                    cVar1 = FUN_005885f0();
                    while (cVar1 != '\0') {
                      uVar5 = FUN_00588600(auStack_88);
                      FUN_00401660(uVar5,0,0xffffffff);
                      if (0xf < uStack_70) {
                        _free(pvStack_84);
                        return;
                      }
                      uStack_70 = 0xf;
                      uStack_74 = 0;
                      pvStack_84 = (void *)((uint)pvStack_84 & 0xffffff00);
                      if (uStack_278 == 0) {
LAB_00566a5a:
                        if (uStack_278 != 0) {
                          uVar9 = uStack_278;
                          if (4 < uStack_278) {
                            uVar9 = 5;
                          }
                          ppppbVar11 = ppppbStack_288;
                          if (uStack_274 < 0x10) {
                            ppppbVar11 = (byte ****)&ppppbStack_288;
                          }
                          bVar13 = false;
                          iVar10 = 0;
                          bVar14 = true;
                          pbVar12 = (byte *)s_color_009bc868;
                          do {
                            if (uVar9 == 0) break;
                            uVar9 = uVar9 - 1;
                            bVar13 = *(byte *)ppppbVar11 < *pbVar12;
                            bVar14 = *(byte *)ppppbVar11 == *pbVar12;
                            ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
                            pbVar12 = pbVar12 + 1;
                          } while (bVar14);
                          if (!bVar14) {
                            iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                          }
                          if (((iVar10 == 0) && (4 < uStack_278)) && (uStack_278 == 5)) {
                            uVar5 = FUN_00588600(auStack_50);
                            uVar5 = thunk_FUN_00796e90(uVar5);
                            *local_2d4 = uVar5;
                            if (0xf < uStack_38) {
                              _free(pvStack_4c);
                              return;
                            }
                            uStack_38 = 0xf;
                            uStack_3c = 0;
                            pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
                            goto LAB_00566c6b;
                          }
                        }
                        if (uStack_278 != 0) {
                          uVar9 = uStack_278;
                          if (5 < uStack_278) {
                            uVar9 = 6;
                          }
                          ppppbVar11 = ppppbStack_288;
                          if (uStack_274 < 0x10) {
                            ppppbVar11 = (byte ****)&ppppbStack_288;
                          }
                          bVar13 = false;
                          iVar10 = 0;
                          bVar14 = true;
                          pbVar12 = (byte *)s_screen_009bc870;
                          do {
                            if (uVar9 == 0) break;
                            uVar9 = uVar9 - 1;
                            bVar13 = *(byte *)ppppbVar11 < *pbVar12;
                            bVar14 = *(byte *)ppppbVar11 == *pbVar12;
                            ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
                            pbVar12 = pbVar12 + 1;
                          } while (bVar14);
                          if (!bVar14) {
                            iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                          }
                          if (((iVar10 == 0) && (5 < uStack_278)) && (uStack_278 == 6)) {
                            iVar10 = *DAT_00b5a7c0;
                            uVar5 = FUN_00588600(auStack_f8);
                            uVar5 = (**(code **)(iVar10 + 8))(uVar5);
                            local_2d4[1] = uVar5;
                            if (0xf < uStack_e0) {
                              _free(pvStack_f4);
                              return;
                            }
                            uStack_e0 = 0xf;
                            uStack_e4 = 0;
                            pvStack_f4 = (void *)((uint)pvStack_f4 & 0xffffff00);
                            goto LAB_00566c6b;
                          }
                        }
                        if (uStack_278 != 0) {
                          uVar9 = uStack_278;
                          if (4 < uStack_278) {
                            uVar9 = 5;
                          }
                          ppppbVar11 = ppppbStack_288;
                          if (uStack_274 < 0x10) {
                            ppppbVar11 = (byte ****)&ppppbStack_288;
                          }
                          bVar13 = false;
                          iVar10 = 0;
                          bVar14 = true;
                          pbVar12 = (byte *)s_index_009bc878;
                          do {
                            if (uVar9 == 0) break;
                            uVar9 = uVar9 - 1;
                            bVar13 = *(byte *)ppppbVar11 < *pbVar12;
                            bVar14 = *(byte *)ppppbVar11 == *pbVar12;
                            ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
                            pbVar12 = pbVar12 + 1;
                          } while (bVar14);
                          if (!bVar14) {
                            iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                          }
                          if (((iVar10 == 0) && (4 < uStack_278)) && (uStack_278 == 5)) {
                            uVar5 = FUN_00588600(auStack_a4);
                            uVar5 = thunk_FUN_00796fb0(uVar5);
                            local_2d4[2] = uVar5;
                            if (0xf < uStack_8c) {
                              _free(pvStack_a0);
                              return;
                            }
                            uStack_8c = 0xf;
                            uStack_90 = 0;
                            pvStack_a0 = (void *)((uint)pvStack_a0 & 0xffffff00);
                            goto LAB_00566c6b;
                          }
                        }
                        uVar4 = 0x566c67;
                        iVar10 = FUN_00403620(0,uStack_278,s_<_image>_009bc880,8);
                        if (iVar10 == 0) break;
                      }
                      else {
                        uVar9 = uStack_278;
                        if (2 < uStack_278) {
                          uVar9 = 3;
                        }
                        ppppbVar11 = ppppbStack_288;
                        if (uStack_274 < 0x10) {
                          ppppbVar11 = (byte ****)&ppppbStack_288;
                        }
                        bVar13 = false;
                        iVar10 = 0;
                        bVar14 = true;
                        pbVar12 = &DAT_009bc864;
                        do {
                          if (uVar9 == 0) break;
                          uVar9 = uVar9 - 1;
                          bVar13 = *(byte *)ppppbVar11 < *pbVar12;
                          bVar14 = *(byte *)ppppbVar11 == *pbVar12;
                          ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
                          pbVar12 = pbVar12 + 1;
                        } while (bVar14);
                        if (!bVar14) {
                          iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                        }
                        if (((iVar10 != 0) || (uStack_278 < 3)) || (uStack_278 != 3))
                        goto LAB_00566a5a;
                        uVar5 = FUN_00588600(auStack_130);
                        FUN_00401660(uVar5,0,0xffffffff);
                        if (0xf < uStack_118) {
                          _free(pvStack_12c);
                          return;
                        }
                        uStack_118 = 0xf;
                        uStack_11c = 0;
                        pvStack_12c = (void *)((uint)pvStack_12c & 0xffffff00);
                      }
LAB_00566c6b:
                      cVar1 = FUN_005885f0();
                    }
                    FUN_005780b0(auStack_254,local_2d4);
                    if (0xf < uStack_23c) {
                      _free(pvStack_250);
                      return;
                    }
                    uStack_23c = 0xf;
                    uStack_240 = 0;
                    pvStack_250 = (void *)((uint)pvStack_250 & 0xffffff00);
                    if (0xf < uStack_274) {
                      _free(ppppbStack_288);
                      return;
                    }
                    uStack_274 = 0xf;
                    uStack_278 = 0;
                    ppppbStack_288 = (byte ****)((uint)ppppbStack_288 & 0xffffff00);
                    goto LAB_00566d36;
                  }
                }
                if (uStack_2b8 != 0) {
                  uVar9 = uStack_2b8;
                  if (10 < uStack_2b8) {
                    uVar9 = 0xb;
                  }
                  ppppbVar11 = appppbStack_2c8[0];
                  if (uStack_2b4 < 0x10) {
                    ppppbVar11 = (byte ****)appppbStack_2c8;
                  }
                  bVar13 = false;
                  iVar10 = 0;
                  bVar14 = true;
                  pbVar12 = (byte *)s_<_nodeinfo>_009bc88c;
                  do {
                    if (uVar9 == 0) break;
                    uVar9 = uVar9 - 1;
                    bVar13 = *(byte *)ppppbVar11 < *pbVar12;
                    bVar14 = *(byte *)ppppbVar11 == *pbVar12;
                    ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
                    pbVar12 = pbVar12 + 1;
                  } while (bVar14);
                  if (!bVar14) {
                    iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                  }
                  if (((iVar10 == 0) && (10 < uStack_2b8)) && (uStack_2b8 == 0xb)) break;
                }
              }
              else {
                uVar9 = uStack_2b8;
                if (6 < uStack_2b8) {
                  uVar9 = 7;
                }
                ppppbVar11 = appppbStack_2c8[0];
                if (uStack_2b4 < 0x10) {
                  ppppbVar11 = (byte ****)appppbStack_2c8;
                }
                bVar13 = false;
                iVar10 = 0;
                bVar14 = true;
                pbVar12 = (byte *)s_btnrect_009bc84c;
                do {
                  if (uVar9 == 0) break;
                  uVar9 = uVar9 - 1;
                  bVar13 = *(byte *)ppppbVar11 < *pbVar12;
                  bVar14 = *(byte *)ppppbVar11 == *pbVar12;
                  ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
                  pbVar12 = pbVar12 + 1;
                } while (bVar14);
                if (!bVar14) {
                  iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                }
                if (((iVar10 != 0) || (uStack_2b8 < 7)) || (uStack_2b8 != 7)) goto LAB_00566813;
                puVar8 = (undefined4 *)FUN_0055cde0(auStack_34);
                *(undefined4 *)(iStack_2d0 + 0x23c) = *puVar8;
                *(undefined4 *)(iStack_2d0 + 0x240) = puVar8[1];
                *(undefined4 *)(iStack_2d0 + 0x244) = puVar8[2];
                *(undefined4 *)(iStack_2d0 + 0x248) = puVar8[3];
              }
LAB_00566d36:
              cVar1 = FUN_005885f0();
            }
            goto LAB_0056737c;
          }
        }
        uVar4 = 0x566d62;
        iVar10 = FUN_00403620(0,uStack_2b8,s_<iteminfo>_009bc898,10);
        if (iVar10 == 0) {
          cVar1 = FUN_005885f0();
          while (cVar1 != '\0') {
            uVar5 = FUN_00588600(auStack_c0);
            FUN_00401660(uVar5,0,0xffffffff);
            if (0xf < uStack_a8) {
              _free(pvStack_bc);
              return;
            }
            uStack_a8 = 0xf;
            uStack_ac = 0;
            pvStack_bc = (void *)((uint)pvStack_bc & 0xffffff00);
            if (uStack_2b8 == 0) {
LAB_00566e63:
              if (uStack_2b8 != 0) {
                uVar9 = uStack_2b8;
                if (5 < uStack_2b8) {
                  uVar9 = 6;
                }
                ppppbVar11 = appppbStack_2c8[0];
                if (uStack_2b4 < 0x10) {
                  ppppbVar11 = (byte ****)appppbStack_2c8;
                }
                bVar13 = false;
                iVar10 = 0;
                bVar14 = true;
                pbVar12 = &DAT_009bc8ac;
                do {
                  if (uVar9 == 0) break;
                  uVar9 = uVar9 - 1;
                  bVar13 = *(byte *)ppppbVar11 < *pbVar12;
                  bVar14 = *(byte *)ppppbVar11 == *pbVar12;
                  ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
                  pbVar12 = pbVar12 + 1;
                } while (bVar14);
                if (!bVar14) {
                  iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                }
                if (((iVar10 == 0) && (5 < uStack_2b8)) && (uStack_2b8 == 6)) {
                  local_2d4 = operator_new(0x24);
                  if (local_2d4 == (undefined4 *)0x0) {
                    local_2d4 = (undefined4 *)0x0;
                  }
                  else {
                    local_2d4[8] = 0xf;
                    local_2d4[7] = 0;
                    *(undefined1 *)(local_2d4 + 3) = 0;
                  }
                  cVar1 = FUN_005885f0();
                  while (cVar1 != '\0') {
                    FUN_00588600(&piStack_2a8);
                    if (uStack_294 == 0) {
LAB_00566fb2:
                      if (uStack_294 != 0) {
                        uVar9 = uStack_294;
                        if (3 < uStack_294) {
                          uVar9 = 4;
                        }
                        ppppbVar11 = appppbStack_2a4[0];
                        if (uStack_290 < 0x10) {
                          ppppbVar11 = (byte ****)appppbStack_2a4;
                        }
                        bVar13 = false;
                        iVar10 = 0;
                        bVar14 = true;
                        pbVar12 = &DAT_009bc8bc;
                        do {
                          if (uVar9 == 0) break;
                          uVar9 = uVar9 - 1;
                          bVar13 = *(byte *)ppppbVar11 < *pbVar12;
                          bVar14 = *(byte *)ppppbVar11 == *pbVar12;
                          ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
                          pbVar12 = pbVar12 + 1;
                        } while (bVar14);
                        if (!bVar14) {
                          iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                        }
                        if (((iVar10 == 0) && (3 < uStack_294)) && (uStack_294 == 4)) {
                          uVar5 = FUN_00588600(auStack_14c);
                          uVar5 = thunk_FUN_00796e60(uVar5);
                          *local_2d4 = uVar5;
                          if (0xf < uStack_134) {
                            _free(pvStack_148);
                            return;
                          }
                          uStack_134 = 0xf;
                          uStack_138 = 0;
                          pvStack_148 = (void *)((uint)pvStack_148 & 0xffffff00);
                          goto LAB_00567245;
                        }
                      }
                      if (uStack_294 != 0) {
                        uVar9 = uStack_294;
                        if (5 < uStack_294) {
                          uVar9 = 6;
                        }
                        ppppbVar11 = appppbStack_2a4[0];
                        if (uStack_290 < 0x10) {
                          ppppbVar11 = (byte ****)appppbStack_2a4;
                        }
                        bVar13 = false;
                        iVar10 = 0;
                        bVar14 = true;
                        pbVar12 = (byte *)s_string_009bc8c4;
                        do {
                          if (uVar9 == 0) break;
                          uVar9 = uVar9 - 1;
                          bVar13 = *(byte *)ppppbVar11 < *pbVar12;
                          bVar14 = *(byte *)ppppbVar11 == *pbVar12;
                          ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
                          pbVar12 = pbVar12 + 1;
                        } while (bVar14);
                        if (!bVar14) {
                          iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                        }
                        if (((iVar10 == 0) && (5 < uStack_294)) && (uStack_294 == 6)) {
                          uVar5 = FUN_00588600(auStack_114);
                          iVar10 = thunk_FUN_00796e60(uVar5);
                          if (0xf < uStack_fc) {
                            _free(pvStack_110);
                            return;
                          }
                          uStack_fc = 0xf;
                          uStack_100 = 0;
                          pvStack_110 = (void *)((uint)pvStack_110 & 0xffffff00);
                          uVar5 = FUN_00588600(auStack_dc);
                          uVar9 = thunk_FUN_00796e60(uVar5);
                          if (0xf < uStack_c4) {
                            _free(pvStack_d8);
                            return;
                          }
                          uStack_c4 = 0xf;
                          uStack_c8 = 0;
                          pvStack_d8 = (void *)((uint)pvStack_d8 & 0xffffff00);
                          uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,iVar10 << 0x10 | uVar9);
                          FUN_00401660(uVar5,0,0xffffffff);
                          goto LAB_00567245;
                        }
                      }
                      if (uStack_294 != 0) {
                        uVar9 = uStack_294;
                        if (3 < uStack_294) {
                          uVar9 = 4;
                        }
                        ppppbVar11 = appppbStack_2a4[0];
                        if (uStack_290 < 0x10) {
                          ppppbVar11 = (byte ****)appppbStack_2a4;
                        }
                        bVar13 = false;
                        iVar10 = 0;
                        bVar14 = true;
                        pbVar12 = &DAT_009bc8cc;
                        do {
                          if (uVar9 == 0) break;
                          uVar9 = uVar9 - 1;
                          bVar13 = *(byte *)ppppbVar11 < *pbVar12;
                          bVar14 = *(byte *)ppppbVar11 == *pbVar12;
                          ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
                          pbVar12 = pbVar12 + 1;
                        } while (bVar14);
                        if (!bVar14) {
                          iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                        }
                        if (((iVar10 == 0) && (3 < uStack_294)) && (uStack_294 == 4)) {
                          uVar5 = FUN_00588600(auStack_210);
                          FUN_00401660(uVar5,0,0xffffffff);
                          if (0xf < uStack_1f8) {
                            _free(pvStack_20c);
                            return;
                          }
                          uStack_1f8 = 0xf;
                          uStack_1fc = 0;
                          pvStack_20c = (void *)((uint)pvStack_20c & 0xffffff00);
                          goto LAB_00567245;
                        }
                      }
                      uVar4 = 0x567238;
                      iVar10 = FUN_00403620(0,uStack_294,s_<_item>_009bc8d4,7);
                      if (iVar10 == 0) {
                        if (0xf < uStack_290) {
                          _free(appppbStack_2a4[0]);
                          return;
                        }
                        uStack_290 = 0xf;
                        uStack_294 = 0;
                        appppbStack_2a4[0] = (byte ****)((uint)appppbStack_2a4[0] & 0xffffff00);
                        break;
                      }
                    }
                    else {
                      uVar9 = uStack_294;
                      if (4 < uStack_294) {
                        uVar9 = 5;
                      }
                      ppppbVar11 = appppbStack_2a4[0];
                      if (uStack_290 < 0x10) {
                        ppppbVar11 = (byte ****)appppbStack_2a4;
                      }
                      bVar13 = false;
                      iVar10 = 0;
                      bVar14 = true;
                      pbVar12 = (byte *)s_index_009bc8b4;
                      do {
                        if (uVar9 == 0) break;
                        uVar9 = uVar9 - 1;
                        bVar13 = *(byte *)ppppbVar11 < *pbVar12;
                        bVar14 = *(byte *)ppppbVar11 == *pbVar12;
                        ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
                        pbVar12 = pbVar12 + 1;
                      } while (bVar14);
                      if (!bVar14) {
                        iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                      }
                      if (((iVar10 != 0) || (uStack_294 < 5)) || (uStack_294 != 5))
                      goto LAB_00566fb2;
                      uVar5 = FUN_00588600(auStack_168);
                      uVar5 = thunk_FUN_00796fb0(uVar5);
                      local_2d4[1] = uVar5;
                      if (0xf < uStack_150) {
                        _free(pvStack_164);
                        return;
                      }
                      uStack_150 = 0xf;
                      uStack_154 = 0;
                      pvStack_164 = (void *)((uint)pvStack_164 & 0xffffff00);
                    }
LAB_00567245:
                    if (0xf < uStack_290) {
                      _free(appppbStack_2a4[0]);
                      return;
                    }
                    uStack_290 = 0xf;
                    uStack_294 = 0;
                    appppbStack_2a4[0] = (byte ****)((uint)appppbStack_2a4[0] & 0xffffff00);
                    cVar1 = FUN_005885f0();
                  }
                  iVar10 = *(int *)(iStack_2d0 + 0x230);
                  if ((iVar10 == 0) ||
                     ((uint)(*(int *)(iStack_2d0 + 0x238) - iVar10 >> 2) <=
                      (uint)(*(int *)(iStack_2d0 + 0x234) - iVar10 >> 2))) {
                    FUN_0056ade0(*(undefined4 *)(iStack_2d0 + 0x234),1,&local_2d4);
                  }
                  else {
                    puVar8 = *(undefined4 **)(iStack_2d0 + 0x234);
                    *puVar8 = local_2d4;
                    *(undefined4 **)(iStack_2d0 + 0x234) = puVar8 + 1;
                  }
                  goto LAB_00567337;
                }
              }
              if (uStack_2b8 != 0) {
                uVar9 = uStack_2b8;
                if (10 < uStack_2b8) {
                  uVar9 = 0xb;
                }
                ppppbVar11 = appppbStack_2c8[0];
                if (uStack_2b4 < 0x10) {
                  ppppbVar11 = (byte ****)appppbStack_2c8;
                }
                bVar13 = false;
                iVar10 = 0;
                bVar14 = true;
                pbVar12 = (byte *)s_<_iteminfo>_009bc8dc;
                do {
                  if (uVar9 == 0) break;
                  uVar9 = uVar9 - 1;
                  bVar13 = *(byte *)ppppbVar11 < *pbVar12;
                  bVar14 = *(byte *)ppppbVar11 == *pbVar12;
                  ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
                  pbVar12 = pbVar12 + 1;
                } while (bVar14);
                if (!bVar14) {
                  iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                }
                if (((iVar10 == 0) && (10 < uStack_2b8)) && (uStack_2b8 == 0xb)) break;
              }
            }
            else {
              uVar9 = uStack_2b8;
              if (3 < uStack_2b8) {
                uVar9 = 4;
              }
              ppppbVar11 = appppbStack_2c8[0];
              if (uStack_2b4 < 0x10) {
                ppppbVar11 = (byte ****)appppbStack_2c8;
              }
              bVar13 = false;
              iVar10 = 0;
              bVar14 = true;
              pbVar12 = &DAT_009bc8a4;
              do {
                if (uVar9 == 0) break;
                uVar9 = uVar9 - 1;
                bVar13 = *(byte *)ppppbVar11 < *pbVar12;
                bVar14 = *(byte *)ppppbVar11 == *pbVar12;
                ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
                pbVar12 = pbVar12 + 1;
              } while (bVar14);
              if (!bVar14) {
                iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
              }
              if (((iVar10 != 0) || (uStack_2b8 < 4)) || (uStack_2b8 != 4)) goto LAB_00566e63;
              puVar8 = (undefined4 *)FUN_0055cde0(auStack_14);
              *(undefined4 *)(iStack_2d0 + 0x21c) = *puVar8;
              *(undefined4 *)(iStack_2d0 + 0x220) = puVar8[1];
              *(undefined4 *)(iStack_2d0 + 0x224) = puVar8[2];
              *(undefined4 *)(iStack_2d0 + 0x228) = puVar8[3];
            }
LAB_00567337:
            cVar1 = FUN_005885f0();
          }
        }
        else {
          ppppuVar7 = appppuStack_26c[0];
          if (uStack_258 < 0x10) {
            ppppuVar7 = appppuStack_26c;
          }
          uVar4 = 0x567378;
          iVar10 = FUN_00403620(0,uStack_2b8,ppppuVar7,uStack_25c);
          if (iVar10 == 0) {
            FUN_00588700(auStack_2cc);
            break;
          }
        }
      }
      else {
        uVar9 = uStack_2b8;
        if (6 < uStack_2b8) {
          uVar9 = 7;
        }
        ppppbVar11 = appppbStack_2c8[0];
        if (uStack_2b4 < 0x10) {
          ppppbVar11 = (byte ****)appppbStack_2c8;
        }
        bVar13 = false;
        iVar10 = 0;
        bVar14 = true;
        pbVar12 = (byte *)s_<image>_009bc838;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          bVar13 = *(byte *)ppppbVar11 < *pbVar12;
          bVar14 = *(byte *)ppppbVar11 == *pbVar12;
          ppppbVar11 = (byte ****)((int)ppppbVar11 + 1);
          pbVar12 = pbVar12 + 1;
        } while (bVar14);
        if (!bVar14) {
          iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
        }
        if (((iVar10 != 0) || (uStack_2b8 < 7)) || (uStack_2b8 != 7)) goto LAB_005666ca;
        FUN_0055d1f0(iStack_2d0);
      }
LAB_0056737c:
      cVar1 = FUN_005885f0();
    } while (cVar1 != '\0');
    piVar2 = piStack_2ac;
    piVar3 = piStack_2b0;
  }
  FUN_00401660(auStack_1a0,0,0xffffffff);
  (**(code **)(*piVar2 + 8))(auStack_1c0);
  cVar1 = (**(code **)(*piVar2 + 0x74))(uStack_4);
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*piStack_8 + 0x78))(piVar2);
    if (cVar1 == '\0') {
      (**(code **)(*piVar2 + 0x74))(0);
    }
    else {
      iVar10 = (**(code **)(*piStack_c + 0x38))();
      piVar2[1] = iVar10;
    }
  }
  (**(code **)(*piVar3 + 0x38))(piVar2);
  (**(code **)(*piVar3 + 0x1c))(auStack_244);
  (**(code **)(*piVar2 + 0x2c))(piVar3);
  FUN_00569460(auStack_284,piVar2);
  (**(code **)(*piVar3 + 0x24))(unaff_EDI);
  if (*(char *)(unaff_EDI + 0xc) == '\0') {
    puVar8 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar8 == (undefined4 *)0x0) {
      puVar8 = (undefined4 *)0x0;
    }
    else {
      uVar4 = (**(code **)(*piVar2 + 4))();
      *puVar8 = &PTR_FUN_009bcd68;
      puVar8[1] = uVar4;
    }
    *(undefined1 *)(puVar8 + 2) = 0;
    (**(code **)(*DAT_00b5ad24 + 4))(puVar8);
    (**(code **)*puVar8)(1);
  }
  FUN_00505d80();
  _free((void *)0x15);
  return;
}


// ==== FUN_00567590 @ 0x00567590 ====

/* WARNING: Removing unreachable block (ram,0x00567737) */

void FUN_00567590(void)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  void *pvVar4;
  undefined4 uVar5;
  int *in_ECX;
  uint uVar6;
  int iVar7;
  byte ******ppppppbVar8;
  void *unaff_EBP;
  void *unaff_ESI;
  byte ******ppppppbVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  undefined4 in_stack_ffffff08;
  uint in_stack_ffffff0c;
  undefined4 in_stack_ffffff10;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  byte ******appppppbStack_bc [2];
  void *apvStack_b4 [2];
  uint uStack_ac;
  uint uStack_a8;
  undefined4 uStack_a4;
  byte ******appppppbStack_a0 [3];
  void *pvStack_94;
  uint uStack_90;
  int *piStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  uint uStack_80;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined1 auStack_5c [6];
  undefined1 uStack_56;
  undefined4 uStack_54;
  undefined4 uStack_50;
  void *pvStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined1 uStack_34;
  undefined4 uStack_24;
  undefined4 uStack_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  int *piStack_4;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_56 = 1;
  uStack_54 = 0;
  uStack_50 = 0;
  pvStack_4c = (void *)0x0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_20 = 0xf;
  uStack_24 = 0;
  uStack_34 = 0;
  uStack_88 = (**(code **)(*DAT_00b5a7ac + 8))(0x19);
  uStack_6c = 0xf;
  uStack_70 = 0;
  uStack_80 = uStack_80 & 0xffffff00;
  uStack_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_a8 = 0xf;
  uStack_ac = 0;
  appppppbStack_bc[0] = (byte ******)((uint)appppppbStack_bc[0] & 0xffffff00);
  piStack_8c = (int *)0xf;
  uStack_90 = 0;
  appppppbStack_a0[0] = (byte ******)((uint)appppppbStack_a0[0] & 0xffffff00);
  FUN_00401740(s_<_noticectrl>_009bc8e8,0xd);
  pvVar4 = operator_new(0x468);
  if (pvVar4 == (void *)0x0) {
    uStack_c4 = 0;
  }
  else {
    uStack_c4 = FUN_00505f10();
  }
  cVar2 = FUN_005885f0();
  do {
    if (cVar2 == '\0') {
LAB_0056781c:
      FUN_00401660(&uStack_3c,0,0xffffffff);
      (**(code **)(*piVar3 + 8))(auStack_5c);
      if ((piStack_4 != (int *)0x0) &&
         (cVar2 = (**(code **)(*piVar3 + 0x74))(piStack_4), cVar2 != '\0')) {
        cVar2 = (**(code **)(*piStack_4 + 0x78))(piVar3);
        if (cVar2 == '\0') {
          (**(code **)(*piVar3 + 0x74))(0);
        }
        else {
          iVar7 = (**(code **)(*piStack_4 + 0x38))();
          piVar3[1] = iVar7;
        }
      }
      piVar1 = piStack_8c;
      (**(code **)(*piStack_8c + 0x38))(piVar3);
      (**(code **)(*piVar1 + 0x1c))(&piStack_8c);
      (**(code **)(*piVar3 + 0x2c))(piVar1);
      FUN_00569460(apvStack_b4,piVar3);
      (**(code **)(*piVar1 + 0x24))(unaff_ESI);
      if (unaff_ESI != (void *)0x0) {
        FUN_00505d80();
        _free(unaff_ESI);
        return;
      }
      if ((byte ******)0xf < appppppbStack_a0[0]) {
        _free(apvStack_b4[0]);
        return;
      }
      appppppbStack_a0[0] = (byte ******)0xf;
      uStack_a4 = 0;
      apvStack_b4[0] = (void *)((uint)apvStack_b4[0] & 0xffffff00);
      if ((byte ******)0xf < appppppbStack_bc[0]) {
        _free(unaff_EBP);
        return;
      }
      appppppbStack_bc[0] = (byte ******)0xf;
      uStack_c0 = 0;
      if (0xf < uStack_80) {
        _free(pvStack_94);
        return;
      }
      uStack_80 = 0xf;
      uStack_84 = 0;
      pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
      if (uStack_38 < 0x10) {
        return;
      }
      _free(pvStack_4c);
      return;
    }
    uVar5 = FUN_00588600(&uStack_20);
    uVar13 = 0x5676bd;
    FUN_00401660(uVar5,0,0xffffffff);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    cVar2 = FUN_0055cad0(&uStack_c0);
    if (cVar2 != '\0') {
LAB_00567814:
      FUN_00588700(&uStack_c0);
      goto LAB_0056781c;
    }
    uVar15 = 0xf;
    uVar14 = 0;
    in_stack_ffffff0c = in_stack_ffffff0c & 0xffffff00;
    FUN_00401660(&uStack_c0,0,0xffffffff);
    FUN_0055cf30(auStack_5c,uStack_c4,in_stack_ffffff08,in_stack_ffffff0c,in_stack_ffffff10,uVar13,
                 uVar5,uVar14,uVar15);
    if (uStack_ac == 0) {
LAB_0056779e:
      ppppppbVar8 = appppppbStack_a0[0];
      if (piStack_8c < (int *)0x10) {
        ppppppbVar8 = (byte ******)appppppbStack_a0;
      }
      if (uStack_ac != 0) {
        uVar6 = uStack_ac;
        if (uStack_90 <= uStack_ac) {
          uVar6 = uStack_90;
        }
        ppppppbVar9 = appppppbStack_bc[0];
        if (uStack_a8 < 0x10) {
          ppppppbVar9 = (byte ******)appppppbStack_bc;
        }
        bVar11 = false;
        iVar7 = 0;
        bVar12 = true;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          bVar11 = *(byte *)ppppppbVar9 < *(byte *)ppppppbVar8;
          bVar12 = *(byte *)ppppppbVar9 == *(byte *)ppppppbVar8;
          ppppppbVar9 = (byte ******)((int)ppppppbVar9 + 1);
          ppppppbVar8 = (byte ******)((int)ppppppbVar8 + 1);
        } while (bVar12);
        if (!bVar12) {
          iVar7 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        }
        piVar3 = in_ECX;
        if (iVar7 != 0) goto LAB_005677f6;
      }
      if ((uStack_90 <= uStack_ac) && (uStack_ac == uStack_90)) goto LAB_00567814;
    }
    else {
      uVar6 = uStack_ac;
      if (6 < uStack_ac) {
        uVar6 = 7;
      }
      ppppppbVar8 = appppppbStack_bc[0];
      if (uStack_a8 < 0x10) {
        ppppppbVar8 = (byte ******)appppppbStack_bc;
      }
      bVar11 = false;
      iVar7 = 0;
      bVar12 = true;
      pbVar10 = (byte *)s_<image>_009bc8f8;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        bVar11 = *(byte *)ppppppbVar8 < *pbVar10;
        bVar12 = *(byte *)ppppppbVar8 == *pbVar10;
        ppppppbVar8 = (byte ******)((int)ppppppbVar8 + 1);
        pbVar10 = pbVar10 + 1;
      } while (bVar12);
      if (!bVar12) {
        iVar7 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      }
      if (((iVar7 != 0) || (uStack_ac < 7)) || (uStack_ac != 7)) {
        piVar3 = in_ECX;
        goto LAB_0056779e;
      }
      FUN_0055d1f0(uStack_c4);
      piVar3 = in_ECX;
    }
LAB_005677f6:
    cVar2 = FUN_005885f0();
  } while( true );
}


// ==== FUN_00567960 @ 0x00567960 ====

void FUN_00567960(void)

{
  char cVar1;
  undefined1 uVar2;
  int *piVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 ******ppppppuVar8;
  int iVar9;
  void *unaff_ESI;
  byte ******ppppppbVar10;
  byte *pbVar11;
  bool bVar12;
  bool bVar13;
  undefined4 in_stack_fffffe38;
  uint in_stack_fffffe3c;
  undefined4 in_stack_fffffe40;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined1 auStack_190 [4];
  byte ******appppppbStack_18c [4];
  uint uStack_17c;
  uint uStack_178;
  int *piStack_174;
  int *piStack_170;
  int *piStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  byte ******appppppbStack_160 [4];
  uint uStack_150;
  void *pvStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 ******appppppuStack_138 [2];
  void *pvStack_130;
  undefined4 uStack_128;
  uint uStack_124;
  undefined4 uStack_120;
  uint uStack_11c;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined1 auStack_e8 [6];
  undefined1 uStack_e2;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  void *pvStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  uint uStack_c4;
  undefined1 uStack_c0;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  void *pvStack_a8;
  undefined4 uStack_98;
  uint uStack_94;
  undefined1 auStack_90 [4];
  void *pvStack_8c;
  undefined4 uStack_7c;
  uint uStack_78;
  undefined1 auStack_74 [4];
  void *pvStack_70;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined1 auStack_58 [4];
  void *pvStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 auStack_3c [4];
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  int *piStack_4;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_e2 = 1;
  uStack_e0 = 0;
  uStack_dc = 0;
  pvStack_d8 = (void *)0x0;
  uStack_d4 = 0;
  uStack_d0 = 0;
  uStack_cc = 0;
  uStack_c8 = 0;
  uStack_ac = 0xf;
  uStack_b0 = 0;
  uStack_c0 = 0;
  piStack_170 = piVar3;
  uStack_168 = (**(code **)(*DAT_00b5a7ac + 8))(7);
  uStack_108 = 0xf;
  uStack_10c = 0;
  uStack_11c = uStack_11c & 0xffffff00;
  uStack_104 = 0;
  uStack_100 = 0;
  uStack_fc = 0;
  uStack_148 = 0;
  uStack_144 = 0;
  uStack_140 = 0;
  pvStack_14c = (void *)0xf;
  uStack_150 = 0;
  appppppbStack_160[0] = (byte ******)((uint)appppppbStack_160[0] & 0xffffff00);
  uStack_124 = 0xf;
  uStack_128 = 0;
  appppppuStack_138[0] = (undefined4 ******)((uint)appppppuStack_138[0] & 0xffffff00);
  FUN_00401740(s_<_slotctrl>_009bc900,0xb);
  pvVar4 = operator_new(0x468);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_00505f10();
  }
  FUN_0056a7b0();
  cVar1 = FUN_005885f0();
  if (cVar1 != '\0') {
    do {
      uVar6 = FUN_00588600(auStack_20);
      uVar14 = 0x567ab3;
      FUN_00401660(uVar6,0,0xffffffff);
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return;
      }
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      cVar1 = FUN_0055cad0(&uStack_164);
      if (cVar1 != '\0') {
        FUN_00588700(&uStack_164);
        break;
      }
      uVar16 = 0xf;
      uVar15 = 0;
      in_stack_fffffe3c = in_stack_fffffe3c & 0xffffff00;
      FUN_00401660(&uStack_164,0,0xffffffff);
      FUN_0055cf30(auStack_e8,uVar5,in_stack_fffffe38,in_stack_fffffe3c,in_stack_fffffe40,uVar14,
                   uVar6,uVar15,uVar16);
      if (uStack_150 == 0) {
LAB_00567bd2:
        if (uStack_150 != 0) {
          uVar7 = uStack_150;
          if (0xb < uStack_150) {
            uVar7 = 0xc;
          }
          ppppppbVar10 = appppppbStack_160[0];
          if (pvStack_14c < (void *)0x10) {
            ppppppbVar10 = (byte ******)appppppbStack_160;
          }
          bVar12 = false;
          iVar9 = 0;
          bVar13 = true;
          pbVar11 = (byte *)s_<classimage>_009bc914;
          do {
            if (uVar7 == 0) break;
            uVar7 = uVar7 - 1;
            bVar12 = *(byte *)ppppppbVar10 < *pbVar11;
            bVar13 = *(byte *)ppppppbVar10 == *pbVar11;
            ppppppbVar10 = (byte ******)((int)ppppppbVar10 + 1);
            pbVar11 = pbVar11 + 1;
          } while (bVar13);
          if (!bVar13) {
            iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
          }
          if (((iVar9 == 0) && (0xb < uStack_150)) && (uStack_150 == 0xc)) {
            uStack_178 = 0xf;
            uStack_17c = 0;
            appppppbStack_18c[0] = (byte ******)((uint)appppppbStack_18c[0] & 0xffffff00);
            uVar2 = 0;
            piStack_170 = operator_new(0xc);
            if (piStack_170 == (int *)0x0) {
              piStack_170 = (int *)0x0;
            }
            else {
              *piStack_170 = 0;
              piStack_170[1] = 0;
              piStack_170[2] = 0;
            }
            *piStack_170 = 0;
            cVar1 = FUN_005885f0();
            while (cVar1 != '\0') {
              uVar6 = FUN_00588600(auStack_58);
              FUN_00401660(uVar6,0,0xffffffff);
              if (0xf < uStack_40) {
                _free(pvStack_54);
                return;
              }
              uStack_40 = 0xf;
              uStack_44 = 0;
              pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
              if (uStack_17c == 0) {
LAB_00567efa:
                if (uStack_17c != 0) {
                  uVar7 = uStack_17c;
                  if (4 < uStack_17c) {
                    uVar7 = 5;
                  }
                  ppppppbVar10 = appppppbStack_18c[0];
                  if (uStack_178 < 0x10) {
                    ppppppbVar10 = (byte ******)appppppbStack_18c;
                  }
                  bVar12 = false;
                  iVar9 = 0;
                  bVar13 = true;
                  pbVar11 = (byte *)s_color_009bc96c;
                  do {
                    if (uVar7 == 0) break;
                    uVar7 = uVar7 - 1;
                    bVar12 = *(byte *)ppppppbVar10 < *pbVar11;
                    bVar13 = *(byte *)ppppppbVar10 == *pbVar11;
                    ppppppbVar10 = (byte ******)((int)ppppppbVar10 + 1);
                    pbVar11 = pbVar11 + 1;
                  } while (bVar13);
                  if (!bVar13) {
                    iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
                  }
                  if (((iVar9 == 0) && (4 < uStack_17c)) && (uStack_17c == 5)) {
                    uVar6 = FUN_00588600(auStack_74);
                    iVar9 = thunk_FUN_00796e90(uVar6);
                    *piStack_170 = iVar9;
                    if (0xf < uStack_5c) {
                      _free(pvStack_70);
                      return;
                    }
                    uStack_5c = 0xf;
                    uStack_60 = 0;
                    pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
                    goto LAB_00568101;
                  }
                }
                if (uStack_17c != 0) {
                  uVar7 = uStack_17c;
                  if (5 < uStack_17c) {
                    uVar7 = 6;
                  }
                  ppppppbVar10 = appppppbStack_18c[0];
                  if (uStack_178 < 0x10) {
                    ppppppbVar10 = (byte ******)appppppbStack_18c;
                  }
                  bVar12 = false;
                  iVar9 = 0;
                  bVar13 = true;
                  pbVar11 = (byte *)s_screen_009bc974;
                  do {
                    if (uVar7 == 0) break;
                    uVar7 = uVar7 - 1;
                    bVar12 = *(byte *)ppppppbVar10 < *pbVar11;
                    bVar13 = *(byte *)ppppppbVar10 == *pbVar11;
                    ppppppbVar10 = (byte ******)((int)ppppppbVar10 + 1);
                    pbVar11 = pbVar11 + 1;
                  } while (bVar13);
                  if (!bVar13) {
                    iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
                  }
                  if (((iVar9 == 0) && (5 < uStack_17c)) && (uStack_17c == 6)) {
                    iVar9 = *DAT_00b5a7c0;
                    uVar6 = FUN_00588600(auStack_3c);
                    iVar9 = (**(code **)(iVar9 + 8))(uVar6);
                    piStack_170[1] = iVar9;
                    if (0xf < uStack_24) {
                      _free(pvStack_38);
                      return;
                    }
                    uStack_24 = 0xf;
                    uStack_28 = 0;
                    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
                    goto LAB_00568101;
                  }
                }
                if (uStack_17c != 0) {
                  uVar7 = uStack_17c;
                  if (4 < uStack_17c) {
                    uVar7 = 5;
                  }
                  ppppppbVar10 = appppppbStack_18c[0];
                  if (uStack_178 < 0x10) {
                    ppppppbVar10 = (byte ******)appppppbStack_18c;
                  }
                  bVar12 = false;
                  iVar9 = 0;
                  bVar13 = true;
                  pbVar11 = (byte *)s_index_009bc97c;
                  do {
                    if (uVar7 == 0) break;
                    uVar7 = uVar7 - 1;
                    bVar12 = *(byte *)ppppppbVar10 < *pbVar11;
                    bVar13 = *(byte *)ppppppbVar10 == *pbVar11;
                    ppppppbVar10 = (byte ******)((int)ppppppbVar10 + 1);
                    pbVar11 = pbVar11 + 1;
                  } while (bVar13);
                  if (!bVar13) {
                    iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
                  }
                  if (((iVar9 == 0) && (4 < uStack_17c)) && (uStack_17c == 5)) {
                    uVar6 = FUN_00588600(auStack_90);
                    iVar9 = thunk_FUN_00796fb0(uVar6);
                    piStack_170[2] = iVar9;
                    if (0xf < uStack_78) {
                      _free(pvStack_8c);
                      return;
                    }
                    uStack_78 = 0xf;
                    uStack_7c = 0;
                    pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
                    goto LAB_00568101;
                  }
                }
                in_stack_fffffe40 = 0x5680fd;
                iVar9 = FUN_00403620(0,uStack_17c,s_<_classimage>_009bc984,0xd);
                if (iVar9 == 0) break;
              }
              else {
                uVar7 = uStack_17c;
                if (2 < uStack_17c) {
                  uVar7 = 3;
                }
                ppppppbVar10 = appppppbStack_18c[0];
                if (uStack_178 < 0x10) {
                  ppppppbVar10 = (byte ******)appppppbStack_18c;
                }
                bVar12 = false;
                iVar9 = 0;
                bVar13 = true;
                pbVar11 = &DAT_009bc924;
                do {
                  if (uVar7 == 0) break;
                  uVar7 = uVar7 - 1;
                  bVar12 = *(byte *)ppppppbVar10 < *pbVar11;
                  bVar13 = *(byte *)ppppppbVar10 == *pbVar11;
                  ppppppbVar10 = (byte ******)((int)ppppppbVar10 + 1);
                  pbVar11 = pbVar11 + 1;
                } while (bVar13);
                if (!bVar13) {
                  iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
                }
                if (((iVar9 != 0) || (uStack_17c < 3)) || (uStack_17c != 3)) goto LAB_00567efa;
                uVar6 = FUN_00588600(&uStack_ac);
                FUN_00401660(uVar6,0,0xffffffff);
                if (0xf < uStack_94) {
                  _free(pvStack_a8);
                  return;
                }
                uStack_94 = 0xf;
                uStack_98 = 0;
                pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
                if (uStack_17c == 0) {
LAB_00567dd3:
                  if (uStack_17c != 0) {
                    uVar7 = uStack_17c;
                    if (8 < uStack_17c) {
                      uVar7 = 9;
                    }
                    ppppppbVar10 = appppppbStack_18c[0];
                    if (uStack_178 < 0x10) {
                      ppppppbVar10 = (byte ******)appppppbStack_18c;
                    }
                    bVar12 = false;
                    iVar9 = 0;
                    bVar13 = true;
                    pbVar11 = (byte *)s_archeress_009bc934;
                    do {
                      if (uVar7 == 0) break;
                      uVar7 = uVar7 - 1;
                      bVar12 = *(byte *)ppppppbVar10 < *pbVar11;
                      bVar13 = *(byte *)ppppppbVar10 == *pbVar11;
                      ppppppbVar10 = (byte ******)((int)ppppppbVar10 + 1);
                      pbVar11 = pbVar11 + 1;
                    } while (bVar13);
                    if (!bVar13) {
                      iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
                    }
                    if (((iVar9 == 0) && (8 < uStack_17c)) && (uStack_17c == 9)) {
                      uVar2 = 1;
                      goto LAB_00568101;
                    }
                  }
                  if (uStack_17c != 0) {
                    uVar7 = uStack_17c;
                    if (8 < uStack_17c) {
                      uVar7 = 9;
                    }
                    ppppppbVar10 = appppppbStack_18c[0];
                    if (uStack_178 < 0x10) {
                      ppppppbVar10 = (byte ******)appppppbStack_18c;
                    }
                    bVar12 = false;
                    iVar9 = 0;
                    bVar13 = true;
                    pbVar11 = (byte *)s_sorceress_009bc940;
                    do {
                      if (uVar7 == 0) break;
                      uVar7 = uVar7 - 1;
                      bVar12 = *(byte *)ppppppbVar10 < *pbVar11;
                      bVar13 = *(byte *)ppppppbVar10 == *pbVar11;
                      ppppppbVar10 = (byte ******)((int)ppppppbVar10 + 1);
                      pbVar11 = pbVar11 + 1;
                    } while (bVar13);
                    if (!bVar13) {
                      iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
                    }
                    if (((iVar9 == 0) && (8 < uStack_17c)) && (uStack_17c == 9)) {
                      uVar2 = 2;
                      goto LAB_00568101;
                    }
                  }
                  in_stack_fffffe40 = 0x567e80;
                  iVar9 = FUN_00403620(0,uStack_17c,s_summoner_009bc94c,8);
                  if (iVar9 == 0) {
                    uVar2 = 3;
                  }
                  else {
                    in_stack_fffffe40 = 0x567ea8;
                    iVar9 = FUN_00403620(0,uStack_17c,s_segnalle_009bc958,8);
                    if (iVar9 == 0) {
                      uVar2 = 4;
                    }
                    else {
                      in_stack_fffffe40 = 0x567ed0;
                      iVar9 = FUN_00403620(0,uStack_17c,s_warrior_009bc964,7);
                      if (iVar9 == 0) {
                        uVar2 = 5;
                      }
                      else {
                        uVar2 = thunk_FUN_00796f50(auStack_190);
                      }
                    }
                  }
                }
                else {
                  uVar7 = uStack_17c;
                  if (7 < uStack_17c) {
                    uVar7 = 8;
                  }
                  ppppppbVar10 = appppppbStack_18c[0];
                  if (uStack_178 < 0x10) {
                    ppppppbVar10 = (byte ******)appppppbStack_18c;
                  }
                  bVar12 = false;
                  iVar9 = 0;
                  bVar13 = true;
                  pbVar11 = (byte *)s_swordman_009bc928;
                  do {
                    if (uVar7 == 0) break;
                    uVar7 = uVar7 - 1;
                    bVar12 = *(byte *)ppppppbVar10 < *pbVar11;
                    bVar13 = *(byte *)ppppppbVar10 == *pbVar11;
                    ppppppbVar10 = (byte ******)((int)ppppppbVar10 + 1);
                    pbVar11 = pbVar11 + 1;
                  } while (bVar13);
                  if (!bVar13) {
                    iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
                  }
                  if (((iVar9 != 0) || (uStack_17c < 8)) || (uStack_17c != 8)) goto LAB_00567dd3;
                  uVar2 = 0;
                }
              }
LAB_00568101:
              cVar1 = FUN_005885f0();
            }
            FUN_00584590(uVar2,piStack_170);
            if (0xf < uStack_178) {
              _free(appppppbStack_18c[0]);
              return;
            }
            uStack_178 = 0xf;
            uStack_17c = 0;
            appppppbStack_18c[0] = (byte ******)((uint)appppppbStack_18c[0] & 0xffffff00);
            goto LAB_0056817e;
          }
        }
        ppppppuVar8 = appppppuStack_138[0];
        if (uStack_124 < 0x10) {
          ppppppuVar8 = appppppuStack_138;
        }
        in_stack_fffffe40 = 0x56817a;
        iVar9 = FUN_00403620(0,uStack_150,ppppppuVar8,uStack_128);
        if (iVar9 == 0) {
          FUN_00588700(&uStack_164);
          break;
        }
      }
      else {
        uVar7 = uStack_150;
        if (6 < uStack_150) {
          uVar7 = 7;
        }
        ppppppbVar10 = appppppbStack_160[0];
        if (pvStack_14c < (void *)0x10) {
          ppppppbVar10 = (byte ******)appppppbStack_160;
        }
        bVar12 = false;
        iVar9 = 0;
        bVar13 = true;
        pbVar11 = (byte *)s_<image>_009bc90c;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          bVar12 = *(byte *)ppppppbVar10 < *pbVar11;
          bVar13 = *(byte *)ppppppbVar10 == *pbVar11;
          ppppppbVar10 = (byte ******)((int)ppppppbVar10 + 1);
          pbVar11 = pbVar11 + 1;
        } while (bVar13);
        if (!bVar13) {
          iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        }
        if (((iVar9 != 0) || (uStack_150 < 7)) || (uStack_150 != 7)) goto LAB_00567bd2;
        uStack_f8 = FUN_0055d1f0(&uStack_148);
        uStack_f4 = uStack_148;
        uStack_f0 = uStack_144;
        uStack_ec = uStack_140;
        FUN_0056ac60(&piStack_170,&uStack_f8);
      }
LAB_0056817e:
      cVar1 = FUN_005885f0();
    } while (cVar1 != '\0');
    piVar3 = piStack_174;
  }
  FUN_00401660(&uStack_c8,0,0xffffffff);
  (**(code **)(*piVar3 + 8))(auStack_e8);
  if ((piStack_4 != (int *)0x0) && (cVar1 = (**(code **)(*piVar3 + 0x74))(piStack_4), cVar1 != '\0')
     ) {
    cVar1 = (**(code **)(*piStack_4 + 0x78))(piVar3);
    if (cVar1 == '\0') {
      (**(code **)(*piVar3 + 0x74))(0);
    }
    else {
      iVar9 = (**(code **)(*piStack_4 + 0x38))();
      piVar3[1] = iVar9;
    }
  }
  (**(code **)(*piStack_16c + 0x38))(piVar3);
  (**(code **)(*piStack_16c + 0x1c))(&uStack_128);
  (**(code **)(*piVar3 + 0x2c))(piStack_16c);
  FUN_00569460(&pvStack_14c,piVar3);
  (**(code **)(*piStack_16c + 0x24))(unaff_ESI);
  if (unaff_ESI != (void *)0x0) {
    FUN_00505d80();
    _free(unaff_ESI);
    return;
  }
  if ((undefined4 ******)0xf < appppppuStack_138[0]) {
    _free(pvStack_14c);
    return;
  }
  appppppuStack_138[0] = (undefined4 ******)0xf;
  uStack_13c = 0;
  pvStack_14c = (void *)((uint)pvStack_14c & 0xffffff00);
  if ((byte ******)0xf < appppppbStack_160[0]) {
    _free(piStack_174);
    return;
  }
  appppppbStack_160[0] = (byte ******)0xf;
  uStack_164 = 0;
  piStack_174 = (int *)((uint)piStack_174 & 0xffffff00);
  if (0xf < uStack_11c) {
    _free(pvStack_130);
    return;
  }
  uStack_11c = 0xf;
  uStack_120 = 0;
  pvStack_130 = (void *)((uint)pvStack_130 & 0xffffff00);
  if (uStack_c4 < 0x10) {
    return;
  }
  _free(pvStack_d8);
  return;
}


// ==== FUN_00568320 @ 0x00568320 ====

/* WARNING: Removing unreachable block (ram,0x0056857b) */

void FUN_00568320(void)

{
  int *piVar1;
  char cVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int *unaff_EBX;
  int *unaff_EBP;
  int *unaff_ESI;
  byte *****pppppbVar8;
  int *unaff_EDI;
  byte *pbVar9;
  bool bVar10;
  bool bVar11;
  undefined4 in_stack_fffffe5c;
  uint in_stack_fffffe60;
  undefined4 in_stack_fffffe64;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uStack_174;
  byte *****apppppbStack_170 [4];
  uint uStack_160;
  uint uStack_15c;
  void *pvStack_158;
  undefined4 uStack_154;
  int *piStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  uint uStack_144;
  void *pvStack_13c;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  uint uStack_128;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  void *pvStack_100;
  undefined4 uStack_fc;
  int *piStack_f8;
  undefined1 auStack_f4 [6];
  undefined1 uStack_ee;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  void *pvStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  uint uStack_d0;
  undefined1 uStack_cc;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  void *pvStack_b4;
  undefined4 uStack_a4;
  uint uStack_a0;
  undefined1 auStack_9c [4];
  void *pvStack_98;
  undefined4 uStack_88;
  uint uStack_84;
  undefined1 auStack_80 [4];
  void *pvStack_7c;
  undefined4 uStack_6c;
  uint uStack_68;
  undefined1 auStack_64 [8];
  undefined1 auStack_5c [8];
  undefined1 auStack_54 [8];
  undefined1 auStack_4c [8];
  undefined1 auStack_44 [8];
  undefined1 auStack_3c [8];
  undefined1 auStack_34 [8];
  undefined1 auStack_2c [8];
  undefined1 auStack_24 [16];
  undefined1 auStack_14 [16];
  int *piStack_4;
  
  uStack_174 = (**(code **)(*DAT_00b5a7ac + 4))();
  uStack_ee = 1;
  uStack_ec = 0;
  uStack_e8 = 0;
  pvStack_e4 = (void *)0x0;
  uStack_e0 = 0;
  uStack_dc = 0;
  uStack_d8 = 0;
  uStack_d4 = 0;
  uStack_b8 = 0xf;
  uStack_bc = 0;
  uStack_cc = 0;
  uVar15 = 0x1a;
  uStack_14c = (**(code **)(*DAT_00b5a7ac + 8))(0x1a);
  uStack_114 = 0xf;
  uStack_118 = 0;
  uStack_128 = uStack_128 & 0xffffff00;
  uStack_110 = 0;
  uStack_10c = 0;
  uStack_108 = 0;
  pvStack_158 = (void *)0x0;
  uStack_154 = 0;
  piStack_150 = (int *)0x0;
  uStack_15c = 0xf;
  uStack_160 = 0;
  apppppbStack_170[0] = (byte *****)((uint)apppppbStack_170[0] & 0xffffff00);
  uStack_130 = 0xf;
  uStack_134 = 0;
  uStack_144 = uStack_144 & 0xffffff00;
  FUN_00401740(s_<_buttonlist>_009bc994,0xd);
  pvVar3 = operator_new(0x468);
  if (pvVar3 == (void *)0x0) {
    pvVar3 = (void *)0x0;
  }
  else {
    pvVar3 = (void *)FUN_00505f10();
  }
  FUN_0056a730();
  cVar2 = FUN_005885f0();
  do {
    if (cVar2 == '\0') {
LAB_00568946:
      FUN_00401660(&uStack_d4,0,0xffffffff);
      (**(code **)(*unaff_EBX + 8))(auStack_f4);
      if ((piStack_4 != (int *)0x0) &&
         (cVar2 = (**(code **)(*unaff_EBP + 0x74))(piStack_4), cVar2 != '\0')) {
        cVar2 = (**(code **)(*piStack_4 + 0x78))(unaff_EBP);
        if (cVar2 == '\0') {
          (**(code **)(*unaff_ESI + 0x74))(0);
        }
        else {
          iVar7 = (**(code **)(*piStack_4 + 0x38))();
          unaff_EBP[1] = iVar7;
        }
      }
      piVar1 = piStack_150;
      (**(code **)(*piStack_150 + 0x38))(unaff_EBP);
      (**(code **)(*piVar1 + 0x1c))(&uStack_134);
      (**(code **)(*unaff_EDI + 0x2c))(piVar1);
      FUN_00569460(&pvStack_158,uVar15);
      (**(code **)(*piVar1 + 0x58))();
      (**(code **)(*piVar1 + 0x24))(pvVar3);
      if (pvVar3 != (void *)0x0) {
        FUN_00505d80();
        _free(pvVar3);
        return;
      }
      if (0xf < uStack_144) {
        _free(pvStack_158);
        return;
      }
      uStack_144 = 0xf;
      uStack_148 = 0;
      pvStack_158 = (void *)((uint)pvStack_158 & 0xffffff00);
      if ((byte *****)0xf < apppppbStack_170[0]) {
        _free(unaff_EDI);
        return;
      }
      apppppbStack_170[0] = (byte *****)0xf;
      uStack_174 = 0;
      if (0xf < uStack_128) {
        _free(pvStack_13c);
        return;
      }
      uStack_128 = 0xf;
      uStack_12c = 0;
      pvStack_13c = (void *)((uint)pvStack_13c & 0xffffff00);
      if (uStack_d0 < 0x10) {
        return;
      }
      _free(pvStack_e4);
      return;
    }
    uVar4 = FUN_00588600(&uStack_b8);
    uVar12 = 0x568450;
    FUN_00401660(uVar4,0,0xffffffff);
    if (0xf < uStack_a0) {
      _free(pvStack_b4);
      return;
    }
    uStack_a0 = 0xf;
    uStack_a4 = 0;
    pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
    cVar2 = FUN_0055cad0(&uStack_174);
    if (cVar2 != '\0') {
LAB_0056893e:
      FUN_00588700(&uStack_174);
      goto LAB_00568946;
    }
    uVar14 = 0xf;
    uVar13 = 0;
    in_stack_fffffe60 = in_stack_fffffe60 & 0xffffff00;
    FUN_00401660(&uStack_174,0,0xffffffff);
    FUN_0055cf30(auStack_f4,pvVar3,in_stack_fffffe5c,in_stack_fffffe60,in_stack_fffffe64,uVar12,
                 uVar4,uVar13,uVar14);
    if (uStack_160 == 0) {
code_r0x0056857e:
      if (uStack_160 != 0) {
        uVar6 = uStack_160;
        if (8 < uStack_160) {
          uVar6 = 9;
        }
        pppppbVar8 = apppppbStack_170[0];
        if (uStack_15c < 0x10) {
          pppppbVar8 = (byte *****)apppppbStack_170;
        }
        bVar10 = false;
        iVar7 = 0;
        bVar11 = true;
        pbVar9 = (byte *)s_topmargin_009bc9ac;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          bVar10 = *(byte *)pppppbVar8 < *pbVar9;
          bVar11 = *(byte *)pppppbVar8 == *pbVar9;
          pppppbVar8 = (byte *****)((int)pppppbVar8 + 1);
          pbVar9 = pbVar9 + 1;
        } while (bVar11);
        if (!bVar11) {
          iVar7 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        }
        if (((iVar7 == 0) && (8 < uStack_160)) && (uStack_160 == 9)) {
          uVar4 = FUN_00588600(auStack_80);
          uVar4 = thunk_FUN_00796e60(uVar4);
          *(undefined4 *)((int)pvVar3 + 0x3b0) = uVar4;
          if (0xf < uStack_68) {
            _free(pvStack_7c);
            return;
          }
          uStack_68 = 0xf;
          uStack_6c = 0;
          pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
          goto LAB_00568920;
        }
      }
      in_stack_fffffe64 = 0x56863a;
      iVar7 = FUN_00403620(0,uStack_160,s_overbacksize_009bc9b8,0xc);
      if (iVar7 == 0) {
        uVar4 = FUN_00588600(auStack_9c);
        uVar4 = thunk_FUN_00796e60(uVar4);
        *(undefined4 *)((int)pvVar3 + 0x3b4) = uVar4;
        if (0xf < uStack_84) {
          _free(pvStack_98);
          return;
        }
        uStack_84 = 0xf;
        uStack_88 = 0;
        pvStack_98 = (void *)((uint)pvStack_98 & 0xffffff00);
      }
      else {
        in_stack_fffffe64 = 0x5686ab;
        iVar7 = FUN_00403620(0,uStack_160,s_count_009bc9c8,5);
        if (iVar7 == 0) {
          puVar5 = (undefined4 *)FUN_0055cec0(auStack_3c);
          *(undefined4 *)((int)pvVar3 + 0x3b8) = *puVar5;
          *(undefined4 *)((int)pvVar3 + 0x3bc) = puVar5[1];
        }
        else {
          in_stack_fffffe64 = 0x5686ea;
          iVar7 = FUN_00403620(0,uStack_160,s_distance_009bc9d0,8);
          if (iVar7 == 0) {
            puVar5 = (undefined4 *)FUN_0055cec0(auStack_4c);
            *(undefined4 *)((int)pvVar3 + 0x3c0) = *puVar5;
            *(undefined4 *)((int)pvVar3 + 0x3c4) = puVar5[1];
          }
          else {
            in_stack_fffffe64 = 0x568729;
            iVar7 = FUN_00403620(0,uStack_160,s_textpos_size_009bc9dc,0xc);
            if (iVar7 == 0) {
              puVar5 = (undefined4 *)FUN_0055cde0(auStack_14);
              *(undefined4 *)((int)pvVar3 + 0x3c8) = *puVar5;
              *(undefined4 *)((int)pvVar3 + 0x3cc) = puVar5[1];
              *(undefined4 *)((int)pvVar3 + 0x3d0) = puVar5[2];
              *(undefined4 *)((int)pvVar3 + 0x3d4) = puVar5[3];
            }
            else {
              cVar2 = FUN_004036a0(&uStack_174,s_normal_009bc9ec);
              if (cVar2 == '\0') {
                cVar2 = FUN_004036a0(&uStack_174,&DAT_009bc9f4);
                if (cVar2 == '\0') {
                  cVar2 = FUN_004036a0(&uStack_174,s_click_009bc9fc);
                  if (cVar2 == '\0') {
                    cVar2 = FUN_004036a0(&uStack_174,s_check_009bca04);
                    if (cVar2 == '\0') {
                      cVar2 = FUN_004036a0(&uStack_174,&DAT_009bca0c);
                      if (cVar2 == '\0') {
                        cVar2 = FUN_004036a0(&uStack_174,s_decoresize_009bca14);
                        if (cVar2 == '\0') {
                          cVar2 = FUN_004036a0(&uStack_174,s_<iconimage>_009bca20);
                          if (cVar2 == '\0') {
                            cVar2 = FUN_004036a0(&uStack_174,s_<icontext>_009bca2c);
                            if (cVar2 == '\0') {
                              cVar2 = FUN_00423420(&uStack_174,&uStack_148);
                              if (cVar2 != '\0') goto LAB_0056893e;
                            }
                            else {
                              FUN_0055dde0((int)pvVar3 + 0x434);
                            }
                          }
                          else {
                            FUN_0055d1f0((int)pvVar3 + 0x41c);
                          }
                        }
                        else {
                          puVar5 = (undefined4 *)FUN_0055cec0(auStack_5c);
                          *(undefined4 *)((int)pvVar3 + 1000) = *puVar5;
                          *(undefined4 *)((int)pvVar3 + 0x3ec) = puVar5[1];
                        }
                      }
                      else {
                        uVar4 = FUN_0055cde0(auStack_24);
                        FUN_004e9a10(uVar4);
                      }
                    }
                    else {
                      puVar5 = (undefined4 *)FUN_0055cec0(auStack_54);
                      *(undefined4 *)((int)pvVar3 + 0x408) = *puVar5;
                      *(undefined4 *)((int)pvVar3 + 0x40c) = puVar5[1];
                    }
                  }
                  else {
                    puVar5 = (undefined4 *)FUN_0055cec0(auStack_64);
                    *(undefined4 *)((int)pvVar3 + 0x400) = *puVar5;
                    *(undefined4 *)((int)pvVar3 + 0x404) = puVar5[1];
                  }
                }
                else {
                  puVar5 = (undefined4 *)FUN_0055cec0(auStack_2c);
                  *(undefined4 *)((int)pvVar3 + 0x3f8) = *puVar5;
                  *(undefined4 *)((int)pvVar3 + 0x3fc) = puVar5[1];
                }
              }
              else {
                puVar5 = (undefined4 *)FUN_0055cec0(auStack_44);
                *(undefined4 *)((int)pvVar3 + 0x3f0) = *puVar5;
                *(undefined4 *)((int)pvVar3 + 0x3f4) = puVar5[1];
              }
            }
          }
        }
      }
    }
    else {
      uVar6 = uStack_160;
      if (6 < uStack_160) {
        uVar6 = 7;
      }
      pppppbVar8 = apppppbStack_170[0];
      if (uStack_15c < 0x10) {
        pppppbVar8 = (byte *****)apppppbStack_170;
      }
      bVar10 = false;
      iVar7 = 0;
      bVar11 = true;
      pbVar9 = (byte *)s_<image>_009bc9a4;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        bVar10 = *(byte *)pppppbVar8 < *pbVar9;
        bVar11 = *(byte *)pppppbVar8 == *pbVar9;
        pppppbVar8 = (byte *****)((int)pppppbVar8 + 1);
        pbVar9 = pbVar9 + 1;
      } while (bVar11);
      if (!bVar11) {
        iVar7 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
      }
      if (((iVar7 != 0) || (uStack_160 < 7)) || (uStack_160 != 7)) goto code_r0x0056857e;
      uStack_104 = FUN_0055d1f0(&pvStack_158);
      pvStack_100 = pvStack_158;
      uStack_fc = uStack_154;
      piStack_f8 = piStack_150;
      FUN_0056ac60(auStack_34,&uStack_104);
    }
LAB_00568920:
    cVar2 = FUN_005885f0();
  } while( true );
}


// ==== FUN_00568aa0 @ 0x00568aa0 ====

/* WARNING: Removing unreachable block (ram,0x00568ccd) */
/* WARNING: Removing unreachable block (ram,0x00568d83) */

void FUN_00568aa0(void)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  int *piVar4;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 ******ppppppuVar7;
  undefined4 *puVar8;
  int *in_ECX;
  uint uVar9;
  int iVar10;
  byte ******ppppppbVar11;
  void *unaff_EDI;
  byte *pbVar12;
  bool bVar13;
  bool bVar14;
  undefined4 in_stack_fffffe80;
  uint in_stack_fffffe84;
  undefined4 in_stack_fffffe88;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 *puStack_150;
  int *piStack_144;
  byte ******appppppbStack_140 [3];
  undefined1 auStack_134 [4];
  uint uStack_130;
  int *piStack_12c;
  undefined4 uStack_128;
  undefined4 ******appppppuStack_120 [3];
  undefined1 auStack_114 [4];
  undefined4 uStack_110;
  uint uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined1 uStack_fc;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined1 uStack_d8;
  undefined1 uStack_d7;
  undefined1 uStack_d0;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined1 auStack_9c [6];
  undefined1 uStack_96;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 auStack_7c [2];
  undefined1 uStack_74;
  undefined4 uStack_64;
  undefined4 uStack_60;
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  undefined1 auStack_c [8];
  int *piStack_4;
  
  piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_96 = 1;
  uStack_94 = 0;
  uStack_90 = 0;
  uStack_8c = 0;
  uStack_88 = 0;
  uStack_84 = 0;
  uStack_80 = 0;
  auStack_7c[0] = 0;
  uStack_60 = 0xf;
  uStack_64 = 0;
  uStack_74 = 0;
  piStack_144 = piVar4;
  uStack_128 = (**(code **)(*DAT_00b5a7ac + 8))(0);
  uStack_bc = 0xf;
  uStack_c0 = 0;
  uStack_d0 = 0;
  uStack_b8 = 0;
  uStack_b4 = 0;
  uStack_b0 = 0;
  piStack_12c = (int *)0xf;
  uStack_130 = 0;
  appppppbStack_140[0] = (byte ******)((uint)appppppbStack_140[0] & 0xffffff00);
  uStack_10c = 0xf;
  uStack_110 = 0;
  appppppuStack_120[0] = (undefined4 ******)((uint)appppppuStack_120[0] & 0xffffff00);
  FUN_00401740(s_<_panel>_009bc2f0,8);
  uStack_108 = 0;
  uStack_104 = 0;
  uStack_e8 = 0xf;
  uStack_ec = 0;
  uStack_fc = 0;
  uStack_e4 = 1;
  uStack_e0 = 0;
  uStack_dc = 1;
  uStack_d8 = 0;
  uStack_d7 = 0;
  pvVar5 = operator_new(0x468);
  if (pvVar5 == (void *)0x0) {
    puStack_150 = (undefined4 *)0x0;
  }
  else {
    puStack_150 = (undefined4 *)FUN_00505f10();
  }
  FUN_00503950(*(undefined4 *)(puStack_150[0x47] + 4));
  *(undefined4 *)(puStack_150[0x47] + 4) = puStack_150[0x47];
  puStack_150[0x48] = 0;
  *(undefined4 *)puStack_150[0x47] = puStack_150[0x47];
  *(undefined4 *)(puStack_150[0x47] + 8) = puStack_150[0x47];
  *(undefined1 *)(puStack_150 + 0x45) = 0;
  *(undefined1 *)((int)puStack_150 + 0x115) = 0;
  cVar2 = FUN_005885f0();
  do {
    if (cVar2 == '\0') {
LAB_00568f25:
      FUN_00401660(auStack_7c,0,0xffffffff);
      (**(code **)(*piVar4 + 8))(auStack_9c);
      if ((piStack_4 != (int *)0x0) &&
         (cVar2 = (**(code **)(*piVar4 + 0x74))(piStack_4), cVar2 != '\0')) {
        cVar2 = (**(code **)(*piStack_4 + 0x78))(piVar4);
        if (cVar2 == '\0') {
          (**(code **)(*piVar4 + 0x74))(0);
        }
        else {
          iVar10 = (**(code **)(*piStack_4 + 0x38))();
          piVar4[1] = iVar10;
        }
      }
      piVar1 = piStack_12c;
      (**(code **)(*piStack_12c + 0x38))(piVar4);
      (**(code **)(*piVar1 + 0x1c))(&uStack_dc);
      if ((char)((uint)unaff_EDI >> 0x18) != '\0') {
        (**(code **)(*piVar1 + 8))(auStack_114);
      }
      (**(code **)(*piVar4 + 0x2c))(piVar1);
      FUN_00569460(auStack_134,piVar4);
      (**(code **)(*piVar1 + 0x24))(unaff_EDI);
      if (*(char *)((int)unaff_EDI + 0xc) == '\0') {
        puVar8 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
        if (puVar8 == (undefined4 *)0x0) {
          puVar8 = (undefined4 *)0x0;
        }
        else {
          uVar6 = (**(code **)(*piVar4 + 4))();
          *puVar8 = &PTR_FUN_009bcd68;
          puVar8[1] = uVar6;
        }
        *(undefined1 *)(puVar8 + 2) = 0;
        (**(code **)(*DAT_00b5ad24 + 4))(puVar8);
        (**(code **)*puVar8)(1);
      }
      FUN_00505d80();
      _free(unaff_EDI);
      return;
    }
    uVar6 = FUN_00588600(&uStack_60);
    uVar15 = 0x568c4f;
    FUN_00401660(uVar6,0,0xffffffff);
    if (0xf < uStack_48) {
      _free(pvStack_5c);
      return;
    }
    uStack_48 = 0xf;
    uStack_4c = 0;
    pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
    cVar2 = FUN_0055cad0(&piStack_144);
    if (cVar2 != '\0') {
      FUN_00588700(&piStack_144);
      goto LAB_00568f25;
    }
    uVar17 = 0xf;
    uVar16 = 0;
    in_stack_fffffe84 = in_stack_fffffe84 & 0xffffff00;
    FUN_00401660(&piStack_144,0,0xffffffff);
    FUN_0055cf30(auStack_9c,puStack_150,in_stack_fffffe80,in_stack_fffffe84,in_stack_fffffe88,uVar15
                 ,uVar6,uVar16,uVar17);
    piVar4 = in_ECX;
    if (uStack_130 == 0) {
code_r0x00568d86:
      if (uStack_130 != 0) {
        uVar9 = uStack_130;
        if (8 < uStack_130) {
          uVar9 = 9;
        }
        ppppppbVar11 = appppppbStack_140[0];
        if (piStack_12c < (int *)0x10) {
          ppppppbVar11 = (byte ******)appppppbStack_140;
        }
        bVar13 = false;
        iVar10 = 0;
        bVar14 = true;
        pbVar12 = (byte *)s_noneimage_009bc308;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          bVar13 = *(byte *)ppppppbVar11 < *pbVar12;
          bVar14 = *(byte *)ppppppbVar11 == *pbVar12;
          ppppppbVar11 = (byte ******)((int)ppppppbVar11 + 1);
          pbVar12 = pbVar12 + 1;
        } while (bVar14);
        if (!bVar14) {
          iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
        }
        if (((iVar10 == 0) && (8 < uStack_130)) && (uStack_130 == 9)) {
          uVar6 = FUN_00588600(auStack_28);
          uVar3 = thunk_FUN_00796fe0(uVar6);
          *(undefined1 *)((int)puStack_150 + 0x115) = uVar3;
          if (0xf < uStack_10) {
            _free(pvStack_24);
            return;
          }
          uStack_10 = 0xf;
          uStack_14 = 0;
          pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
          goto LAB_00568eef;
        }
      }
      in_stack_fffffe88 = 0x568e47;
      iVar10 = FUN_00403620(0,uStack_130,s_<image>_009bc314,7);
      if (iVar10 == 0) {
        uStack_ac = FUN_0055d1f0(puStack_150);
        uStack_a8 = *puStack_150;
        uStack_a4 = puStack_150[1];
        uStack_a0 = puStack_150[2];
        FUN_0056ac60(auStack_c,&uStack_ac);
      }
      else {
        in_stack_fffffe88 = 0x568eb0;
        iVar10 = FUN_00403620(0,uStack_130,s_<title>_009bc31c,7);
        if (iVar10 == 0) {
          FUN_0055dde0(&uStack_108);
        }
        else {
          ppppppuVar7 = appppppuStack_120[0];
          if (uStack_10c < 0x10) {
            ppppppuVar7 = appppppuStack_120;
          }
          in_stack_fffffe88 = 0x568eeb;
          iVar10 = FUN_00403620(0,uStack_130,ppppppuVar7,uStack_110);
          if (iVar10 == 0) {
            FUN_00588700(&piStack_144);
            goto LAB_00568f25;
          }
        }
      }
    }
    else {
      uVar9 = uStack_130;
      if (7 < uStack_130) {
        uVar9 = 8;
      }
      ppppppbVar11 = appppppbStack_140[0];
      if (piStack_12c < (int *)0x10) {
        ppppppbVar11 = (byte ******)appppppbStack_140;
      }
      bVar13 = false;
      iVar10 = 0;
      bVar14 = true;
      pbVar12 = (byte *)s_moveable_009bc2fc;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        bVar13 = *(byte *)ppppppbVar11 < *pbVar12;
        bVar14 = *(byte *)ppppppbVar11 == *pbVar12;
        ppppppbVar11 = (byte ******)((int)ppppppbVar11 + 1);
        pbVar12 = pbVar12 + 1;
      } while (bVar14);
      if (!bVar14) {
        iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
      }
      if (((iVar10 != 0) || (uStack_130 < 8)) || (uStack_130 != 8)) goto code_r0x00568d86;
      uVar6 = FUN_00588600(auStack_44);
      uVar3 = thunk_FUN_00796fe0(uVar6);
      *(undefined1 *)(puStack_150 + 0x45) = uVar3;
      if (0xf < uStack_2c) {
        _free(pvStack_40);
        return;
      }
      uStack_2c = 0xf;
      uStack_30 = 0;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    }
LAB_00568eef:
    cVar2 = FUN_005885f0();
  } while( true );
}


// ==== FUN_005690f0 @ 0x005690f0 ====

void FUN_005690f0(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_<panel>_009bc160,7);
  if (iVar2 == 0) {
    FUN_00568aa0(param_1);
    return;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_<button>_009bc168,8);
  if (iVar2 == 0) {
    FUN_00560170(param_1);
    return;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_<edit>_009bc174,6);
  if (iVar2 == 0) {
    FUN_00561cc0(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<label>_009bc17c);
  if (cVar1 != '\0') {
    FUN_0055fa00(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<processbar>_009bc184);
  if (cVar1 != '\0') {
    FUN_00562450(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<vscroll>_009bc194);
  if (cVar1 != '\0') {
    FUN_00562960(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<treectrl>_009bc1a0);
  if (cVar1 != '\0') {
    FUN_00562e30(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<textbox>_009bc1ac);
  if (cVar1 != '\0') {
    FUN_00563e70(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<slotctrl>_009bc1b8);
  if (cVar1 != '\0') {
    FUN_00567960(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<partystate>_009bc1c4);
  if (cVar1 != '\0') {
    FUN_00569580(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<skilltree>_009bc1d4);
  if (cVar1 != '\0') {
    FUN_005647c0(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<tab>_009bc1e0);
  if (cVar1 != '\0') {
    FUN_00561550(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<item>_009bc1e8);
  if (cVar1 != '\0') {
    FUN_0055f3f0(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<itemslot>_009bc1f0);
  if (cVar1 != '\0') {
    FUN_0055ec70(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<quickslot>_009bc1fc);
  if (cVar1 != '\0') {
    FUN_0055f0a0(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<emoti>_009bc208);
  if (cVar1 != '\0') {
    FUN_00560d40(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<slidebar>_009bc210);
  if (cVar1 != '\0') {
    FUN_00565ef0(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<combobox>_009bc21c);
  if (cVar1 != '\0') {
    FUN_00566410(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<listbox>_009bc228);
  if (cVar1 != '\0') {
    FUN_00563620(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<messengertree>_009bc234);
  if (cVar1 != '\0') {
    FUN_005658e0(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<casebox>_009bc244);
  if (cVar1 != '\0') {
    FUN_00564b90(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<maillist>_009bc250);
  if (cVar1 != '\0') {
    FUN_00565230(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<noticectrl>_009bc25c);
  if (cVar1 != '\0') {
    FUN_00567590(param_1);
    return;
  }
  cVar1 = FUN_004036a0(param_2,s_<buttonlist>_009bc26c);
  if (cVar1 != '\0') {
    FUN_00568320(param_1);
  }
  return;
}


// ==== FUN_00569460 @ 0x00569460 ====

void FUN_00569460(int param_1,undefined4 param_2)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  byte *****pppppbVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  undefined1 local_38 [4];
  byte *****local_34 [4];
  uint local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = (byte *****)((uint)local_34[0] & 0xffffff00);
  cVar2 = FUN_005885f0();
  while (cVar2 != '\0') {
    uVar3 = FUN_00588600(local_1c);
    FUN_00401660(uVar3,0,0xffffffff);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    uVar1 = *(uint *)(param_1 + 0x14);
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      pbVar7 = (byte *)(param_1 + 4);
    }
    else {
      pbVar7 = *(byte **)(param_1 + 4);
    }
    if (local_24 == 0) {
LAB_00569522:
      if ((uVar1 <= local_24) && (local_24 == uVar1)) break;
    }
    else {
      uVar5 = local_24;
      if (uVar1 <= local_24) {
        uVar5 = uVar1;
      }
      pppppbVar6 = local_34[0];
      if (local_20 < 0x10) {
        pppppbVar6 = (byte *****)local_34;
      }
      bVar8 = false;
      iVar4 = 0;
      bVar9 = true;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        bVar8 = *(byte *)pppppbVar6 < *pbVar7;
        bVar9 = *(byte *)pppppbVar6 == *pbVar7;
        pppppbVar6 = (byte *****)((int)pppppbVar6 + 1);
        pbVar7 = pbVar7 + 1;
      } while (bVar9);
      if (!bVar9) {
        iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      }
      if (iVar4 == 0) goto LAB_00569522;
    }
    cVar2 = FUN_0055cad0(local_38);
    if (cVar2 != '\0') {
      FUN_005690f0(param_2,local_38);
    }
    cVar2 = FUN_005885f0();
  }
  if (local_20 < 0x10) {
    return;
  }
  _free(local_34[0]);
  return;
}


// ==== FUN_00569580 @ 0x00569580 ====

void FUN_00569580(void)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  int *piVar4;
  void *pvVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *****pppppuVar8;
  undefined4 *puVar9;
  uint uVar10;
  int iVar11;
  byte *****pppppbVar12;
  void *unaff_EDI;
  byte *pbVar13;
  bool bVar14;
  bool bVar15;
  undefined4 in_stack_fffffe18;
  uint in_stack_fffffe1c;
  undefined4 in_stack_fffffe20;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int *piStack_1b4;
  int *piStack_1b0;
  byte *****apppppbStack_1ac [4];
  uint uStack_19c;
  uint uStack_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  int *piStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  byte *****apppppbStack_17c [2];
  undefined1 auStack_174 [8];
  uint uStack_16c;
  uint uStack_168;
  undefined4 *****apppppuStack_160 [4];
  undefined4 uStack_150;
  uint uStack_14c;
  undefined1 uStack_144;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined1 auStack_120 [6];
  undefined1 uStack_11a;
  void *pvStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  uint uStack_104;
  undefined4 auStack_100 [2];
  undefined1 uStack_f8;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  void *pvStack_e0;
  undefined4 uStack_d0;
  uint uStack_cc;
  undefined1 auStack_c8 [4];
  void *pvStack_c4;
  undefined4 uStack_b4;
  uint uStack_b0;
  undefined1 auStack_ac [4];
  void *pvStack_a8;
  undefined4 uStack_98;
  uint uStack_94;
  undefined1 auStack_90 [4];
  void *pvStack_8c;
  undefined4 uStack_7c;
  uint uStack_78;
  undefined1 auStack_74 [4];
  void *pvStack_70;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined1 auStack_58 [4];
  void *pvStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 auStack_3c [4];
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  int *piStack_4;
  
  piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_11a = 1;
  pvStack_118 = (void *)0x0;
  uStack_114 = 0;
  uStack_110 = 0;
  uStack_10c = 0;
  uStack_108 = 0;
  uStack_104 = 0;
  auStack_100[0] = 0;
  uStack_e4 = 0xf;
  uStack_e8 = 0;
  uStack_f8 = 0;
  piStack_1b0 = piVar4;
  uStack_188 = (**(code **)(*DAT_00b5a7ac + 8))(9);
  uStack_130 = 0xf;
  uStack_134 = 0;
  uStack_144 = 0;
  uStack_12c = 0;
  uStack_128 = 0;
  uStack_124 = 0;
  uStack_198 = 0xf;
  uStack_19c = 0;
  apppppbStack_1ac[0] = (byte *****)((uint)apppppbStack_1ac[0] & 0xffffff00);
  uStack_14c = 0xf;
  uStack_150 = 0;
  apppppuStack_160[0] = (undefined4 *****)((uint)apppppuStack_160[0] & 0xffffff00);
  FUN_00401740(s_<_partystate>_009bca38,0xd);
  pvVar5 = operator_new(0x468);
  if (pvVar5 == (void *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = FUN_00505f10();
  }
  *(undefined1 *)(iVar6 + 0x1a5) = 0;
  *(undefined1 *)(iVar6 + 0x1a4) = 0;
  cVar2 = FUN_005885f0();
  if (cVar2 != '\0') {
    do {
      uVar7 = FUN_00588600(&uStack_e4);
      uVar16 = 0x5696c1;
      FUN_00401660(uVar7,0,0xffffffff);
      if (0xf < uStack_cc) {
        _free(pvStack_e0);
        return;
      }
      uStack_cc = 0xf;
      uStack_d0 = 0;
      pvStack_e0 = (void *)((uint)pvStack_e0 & 0xffffff00);
      cVar2 = FUN_0055cad0(&piStack_1b0);
      if (cVar2 != '\0') {
        FUN_00588700(&piStack_1b0);
        break;
      }
      uVar18 = 0xf;
      uVar17 = 0;
      in_stack_fffffe1c = in_stack_fffffe1c & 0xffffff00;
      FUN_00401660(&piStack_1b0,0,0xffffffff);
      FUN_0055cf30(auStack_120,iVar6,in_stack_fffffe18,in_stack_fffffe1c,in_stack_fffffe20,uVar16,
                   uVar7,uVar17,uVar18);
      if (uStack_19c == 0) {
LAB_00569797:
        if (uStack_19c != 0) {
          uVar10 = uStack_19c;
          if (7 < uStack_19c) {
            uVar10 = 8;
          }
          pppppbVar12 = apppppbStack_1ac[0];
          if (uStack_198 < 0x10) {
            pppppbVar12 = (byte *****)apppppbStack_1ac;
          }
          bVar14 = false;
          iVar11 = 0;
          bVar15 = true;
          pbVar13 = (byte *)s_maxstate_009bca50;
          do {
            if (uVar10 == 0) break;
            uVar10 = uVar10 - 1;
            bVar14 = *(byte *)pppppbVar12 < *pbVar13;
            bVar15 = *(byte *)pppppbVar12 == *pbVar13;
            pppppbVar12 = (byte *****)((int)pppppbVar12 + 1);
            pbVar13 = pbVar13 + 1;
          } while (bVar15);
          if (!bVar15) {
            iVar11 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
          }
          if (((iVar11 == 0) && (7 < uStack_19c)) && (uStack_19c == 8)) {
            uVar7 = FUN_00588600(auStack_58);
            uVar3 = thunk_FUN_00796f50(uVar7);
            *(undefined1 *)(iVar6 + 0x1a4) = uVar3;
            if (0xf < uStack_40) {
              _free(pvStack_54);
              return;
            }
            uStack_40 = 0xf;
            uStack_44 = 0;
            pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
            goto LAB_00569c38;
          }
        }
        in_stack_fffffe20 = 0x569850;
        iVar11 = FUN_00403620(0,uStack_19c,s_hideheight_009bca5c,10);
        if (iVar11 == 0) {
          uVar7 = FUN_00588600(auStack_20);
          uVar3 = thunk_FUN_00796f50(uVar7);
          *(undefined1 *)(iVar6 + 0x1a5) = uVar3;
          if (0xf < uStack_8) {
            _free(pvStack_1c);
            return;
          }
          uStack_8 = 0xf;
          uStack_c = 0;
          pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
        }
        else {
          iVar11 = FUN_00403620(0,uStack_19c,s_<stateimage>_009bca68,0xc);
          if (iVar11 == 0) {
            uStack_168 = 0xf;
            uStack_16c = 0;
            apppppbStack_17c[0] = (byte *****)((uint)apppppbStack_17c[0] & 0xffffff00);
            uStack_184 = 0;
            uStack_190 = 0;
            piStack_18c = (int *)0x0;
            uStack_194 = 0;
            cVar2 = FUN_005885f0();
            while (cVar2 != '\0') {
              uVar7 = FUN_00588600(auStack_ac);
              FUN_00401660(uVar7,0,0xffffffff);
              if (0xf < uStack_94) {
                _free(pvStack_a8);
                return;
              }
              uStack_94 = 0xf;
              uStack_98 = 0;
              pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
              if (uStack_16c == 0) {
LAB_00569a0d:
                if (uStack_16c != 0) {
                  uVar10 = uStack_16c;
                  if (4 < uStack_16c) {
                    uVar10 = 5;
                  }
                  pppppbVar12 = apppppbStack_17c[0];
                  if (uStack_168 < 0x10) {
                    pppppbVar12 = (byte *****)apppppbStack_17c;
                  }
                  bVar14 = false;
                  iVar11 = 0;
                  bVar15 = true;
                  pbVar13 = (byte *)s_color_009bca7c;
                  do {
                    if (uVar10 == 0) break;
                    uVar10 = uVar10 - 1;
                    bVar14 = *(byte *)pppppbVar12 < *pbVar13;
                    bVar15 = *(byte *)pppppbVar12 == *pbVar13;
                    pppppbVar12 = (byte *****)((int)pppppbVar12 + 1);
                    pbVar13 = pbVar13 + 1;
                  } while (bVar15);
                  if (!bVar15) {
                    iVar11 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
                  }
                  if (((iVar11 == 0) && (4 < uStack_16c)) && (uStack_16c == 5)) {
                    uVar7 = FUN_00588600(auStack_74);
                    uStack_194 = thunk_FUN_00796e90(uVar7);
                    if (0xf < uStack_5c) {
                      _free(pvStack_70);
                      return;
                    }
                    uStack_5c = 0xf;
                    uStack_60 = 0;
                    pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
                    goto LAB_00569bac;
                  }
                }
                iVar11 = FUN_00403620(0,uStack_16c,s_screen_009bca84,6);
                if (iVar11 == 0) {
                  iVar11 = *DAT_00b5a7c0;
                  uVar7 = FUN_00588600(auStack_c8);
                  uStack_190 = (**(code **)(iVar11 + 8))(uVar7);
                  if (0xf < uStack_b0) {
                    _free(pvStack_c4);
                    return;
                  }
                  uStack_b0 = 0xf;
                  uStack_b4 = 0;
                  pvStack_c4 = (void *)((uint)pvStack_c4 & 0xffffff00);
                }
                else {
                  iVar11 = FUN_00403620(0,uStack_16c,s_index_009bca8c,5);
                  if (iVar11 == 0) {
                    uVar7 = FUN_00588600(auStack_90);
                    piStack_18c = (int *)thunk_FUN_00796fb0(uVar7);
                    if (0xf < uStack_78) {
                      _free(pvStack_8c);
                      return;
                    }
                    uStack_78 = 0xf;
                    uStack_7c = 0;
                    pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
                  }
                  else {
                    iVar11 = FUN_00403620(0,uStack_16c,s_<_stateimage>_009bca94,0xd);
                    if (iVar11 == 0) break;
                  }
                }
              }
              else {
                uVar10 = uStack_16c;
                if (2 < uStack_16c) {
                  uVar10 = 3;
                }
                pppppbVar12 = apppppbStack_17c[0];
                if (uStack_168 < 0x10) {
                  pppppbVar12 = (byte *****)apppppbStack_17c;
                }
                bVar14 = false;
                iVar11 = 0;
                bVar15 = true;
                pbVar13 = &DAT_009bca78;
                do {
                  if (uVar10 == 0) break;
                  uVar10 = uVar10 - 1;
                  bVar14 = *(byte *)pppppbVar12 < *pbVar13;
                  bVar15 = *(byte *)pppppbVar12 == *pbVar13;
                  pppppbVar12 = (byte *****)((int)pppppbVar12 + 1);
                  pbVar13 = pbVar13 + 1;
                } while (bVar15);
                if (!bVar15) {
                  iVar11 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
                }
                if (((iVar11 != 0) || (uStack_16c < 3)) || (uStack_16c != 3)) goto LAB_00569a0d;
                uVar7 = FUN_00588600(auStack_3c);
                uStack_184 = thunk_FUN_00796fb0(uVar7);
                if (0xf < uStack_24) {
                  _free(pvStack_38);
                  return;
                }
                uStack_24 = 0xf;
                uStack_28 = 0;
                pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
              }
LAB_00569bac:
              cVar2 = FUN_005885f0();
            }
            in_stack_fffffe20 = 0x569be7;
            FUN_00582910(uStack_184,uStack_194,uStack_190,piStack_18c);
            if (0xf < uStack_168) {
              _free(apppppbStack_17c[0]);
              return;
            }
            uStack_168 = 0xf;
            uStack_16c = 0;
            apppppbStack_17c[0] = (byte *****)((uint)apppppbStack_17c[0] & 0xffffff00);
          }
          else {
            pppppuVar8 = apppppuStack_160[0];
            if (uStack_14c < 0x10) {
              pppppuVar8 = apppppuStack_160;
            }
            in_stack_fffffe20 = 0x569c34;
            iVar11 = FUN_00403620(0,uStack_19c,pppppuVar8,uStack_150);
            if (iVar11 == 0) {
              FUN_00588700(&piStack_1b0);
              break;
            }
          }
        }
      }
      else {
        uVar10 = uStack_19c;
        if (6 < uStack_19c) {
          uVar10 = 7;
        }
        pppppbVar12 = apppppbStack_1ac[0];
        if (uStack_198 < 0x10) {
          pppppbVar12 = (byte *****)apppppbStack_1ac;
        }
        bVar14 = false;
        iVar11 = 0;
        bVar15 = true;
        pbVar13 = (byte *)s_<image>_009bca48;
        do {
          if (uVar10 == 0) break;
          uVar10 = uVar10 - 1;
          bVar14 = *(byte *)pppppbVar12 < *pbVar13;
          bVar15 = *(byte *)pppppbVar12 == *pbVar13;
          pppppbVar12 = (byte *****)((int)pppppbVar12 + 1);
          pbVar13 = pbVar13 + 1;
        } while (bVar15);
        if (!bVar15) {
          iVar11 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
        }
        if (((iVar11 != 0) || (uStack_19c < 7)) || (uStack_19c != 7)) goto LAB_00569797;
        FUN_0055d1f0(iVar6);
      }
LAB_00569c38:
      cVar2 = FUN_005885f0();
    } while (cVar2 != '\0');
    piVar4 = piStack_1b4;
  }
  FUN_00401660(auStack_100,0,0xffffffff);
  (**(code **)(*piVar4 + 8))(auStack_120);
  if ((piStack_4 != (int *)0x0) && (cVar2 = (**(code **)(*piVar4 + 0x74))(piStack_4), cVar2 != '\0')
     ) {
    cVar2 = (**(code **)(*piStack_4 + 0x78))(piVar4);
    if (cVar2 == '\0') {
      (**(code **)(*piVar4 + 0x74))(0);
    }
    else {
      iVar6 = (**(code **)(*piStack_4 + 0x38))();
      piVar4[1] = iVar6;
    }
  }
  piVar1 = piStack_18c;
  (**(code **)(*piStack_18c + 0x38))(piVar4);
  (**(code **)(*piVar1 + 0x1c))(&uStack_150);
  (**(code **)(*piVar4 + 0x2c))(piVar1);
  FUN_00569460(auStack_174,piVar4);
  (**(code **)(*piVar1 + 0x24))(unaff_EDI);
  if (unaff_EDI != (void *)0x0) {
    FUN_00505d80();
    _free(unaff_EDI);
    return;
  }
  puVar9 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar9 == (undefined4 *)0x0) {
    puVar9 = (undefined4 *)0x0;
  }
  else {
    uVar7 = (**(code **)(*piVar4 + 4))();
    *puVar9 = &PTR_FUN_009bcd68;
    puVar9[1] = uVar7;
  }
  *(undefined1 *)(puVar9 + 2) = 0;
  (**(code **)(*DAT_00b5ad24 + 4))(puVar9);
  (**(code **)*puVar9)(1);
  if (0xf < uStack_168) {
    _free(apppppbStack_17c[0]);
    return;
  }
  uStack_168 = 0xf;
  uStack_16c = 0;
  apppppbStack_17c[0] = (byte *****)((uint)apppppbStack_17c[0] & 0xffffff00);
  if ((int *)0xf < piStack_1b4) {
    _free((void *)0x0);
    return;
  }
  if (0xf < uStack_14c) {
    _free(apppppuStack_160[0]);
    return;
  }
  uStack_14c = 0xf;
  uStack_150 = 0;
  apppppuStack_160[0] = (undefined4 *****)((uint)apppppuStack_160[0] & 0xffffff00);
  if (uStack_104 < 0x10) {
    return;
  }
  _free(pvStack_118);
  return;
}


// ==== FUN_00569e10 @ 0x00569e10 ====

int * FUN_00569e10(undefined4 param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int *extraout_EAX;
  int iVar4;
  int *extraout_EAX_00;
  int *extraout_EAX_01;
  int *extraout_EAX_02;
  int *extraout_EAX_03;
  int *extraout_EAX_04;
  int *extraout_EAX_05;
  undefined4 *puVar5;
  int *extraout_EAX_06;
  int *extraout_EAX_07;
  int *extraout_EAX_08;
  int *extraout_EAX_09;
  uint uVar6;
  void *unaff_EBX;
  byte *****pppppbVar7;
  byte ****ppppbVar8;
  byte *pbVar9;
  bool bVar10;
  bool bVar11;
  byte ****local_1f0;
  byte *****local_1ec [2];
  undefined4 uStack_1e4;
  uint uStack_1e0;
  uint local_1dc;
  int *local_1d8;
  void *pvStack_1d4;
  void *pvStack_1d0;
  undefined4 uStack_1c4;
  uint uStack_1c0;
  uint uStack_1bc;
  void *apvStack_1b8 [4];
  undefined4 uStack_1a8;
  uint uStack_1a4;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  char cStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined1 uStack_17c;
  undefined1 uStack_17b;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  undefined1 auStack_164 [4];
  undefined1 local_160 [4];
  void *local_15c;
  undefined4 local_14c;
  uint local_148;
  void *pvStack_144;
  undefined4 uStack_134;
  uint uStack_130;
  undefined1 auStack_12c [4];
  void *pvStack_128;
  undefined4 uStack_118;
  uint uStack_114;
  undefined1 auStack_110 [4];
  void *pvStack_10c;
  undefined4 uStack_fc;
  uint uStack_f8;
  undefined1 auStack_f4 [4];
  void *pvStack_f0;
  undefined4 uStack_e0;
  uint uStack_dc;
  undefined1 auStack_d8 [4];
  void *pvStack_d4;
  undefined4 uStack_c4;
  uint uStack_c0;
  undefined1 auStack_bc [28];
  undefined1 auStack_a0 [28];
  undefined1 auStack_84 [28];
  undefined1 auStack_68 [28];
  undefined1 auStack_4c [56];
  undefined1 auStack_14 [20];
  
  local_1d8 = (int *)0xf;
  local_1dc = 0;
  local_1ec[0] = (byte *****)((uint)local_1ec[0] & 0xffffff00);
  cVar2 = FUN_005885f0();
  while (cVar2 != '\0') {
    uVar3 = FUN_00588600(local_160);
    FUN_00401660(uVar3,0,0xffffffff);
    if (0xf < local_148) {
      _free(local_15c);
      return extraout_EAX;
    }
    local_148 = 0xf;
    local_14c = 0;
    local_15c = (void *)((uint)local_15c & 0xffffff00);
    if (local_1dc != 0) {
      uVar6 = local_1dc;
      if (7 < local_1dc) {
        uVar6 = 8;
      }
      pppppbVar7 = local_1ec[0];
      if (local_1d8 < (int *)0x10) {
        pppppbVar7 = (byte *****)local_1ec;
      }
      bVar10 = false;
      iVar4 = 0;
      bVar11 = true;
      pbVar9 = (byte *)s_<window>_009bbf88;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        bVar10 = *(byte *)pppppbVar7 < *pbVar9;
        bVar11 = *(byte *)pppppbVar7 == *pbVar9;
        pppppbVar7 = (byte *****)((int)pppppbVar7 + 1);
        pbVar9 = pbVar9 + 1;
      } while (bVar11);
      if (!bVar11) {
        iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
      }
      if (((iVar4 == 0) && (7 < local_1dc)) && (local_1dc == 8)) break;
    }
    cVar2 = FUN_005885f0();
  }
  iVar4 = FUN_00403620(0,local_1dc,s_<window>_009bbf94,8);
  if (iVar4 != 0) {
    if (local_1d8 < (int *)0x10) {
      return (int *)0x0;
    }
    _free(local_1ec[0]);
    return extraout_EAX_09;
  }
  local_1d8 = (int *)(**(code **)(*DAT_00b5a7a4 + 4))(param_1);
  FUN_0056a840();
  cVar2 = FUN_005885f0();
  while (cVar2 != '\0') {
    uVar3 = FUN_00588600(auStack_12c);
    FUN_00401660(uVar3,0,0xffffffff);
    if (0xf < uStack_114) {
      _free(pvStack_128);
      return extraout_EAX_00;
    }
    uStack_114 = 0xf;
    uStack_118 = 0;
    pvStack_128 = (void *)((uint)pvStack_128 & 0xffffff00);
    if (uStack_1e0 == 0) {
LAB_0056a035:
      iVar4 = FUN_00403620(0,uStack_1e0,s_enable_009bbfa8,6);
      if (iVar4 == 0) {
        uVar3 = FUN_00588600(auStack_f4);
        uStack_17b = thunk_FUN_00796fe0(uVar3);
        if (0xf < uStack_dc) {
          _free(pvStack_f0);
          return extraout_EAX_02;
        }
        uStack_dc = 0xf;
        uStack_e0 = 0;
        pvStack_f0 = (void *)((uint)pvStack_f0 & 0xffffff00);
      }
      else {
        iVar4 = FUN_00403620(0,uStack_1e0,s_visible_009bbfb0,7);
        if (iVar4 == 0) {
          uVar3 = FUN_00588600(auStack_d8);
          uStack_17c = thunk_FUN_00796fe0(uVar3);
          if (0xf < uStack_c0) {
            _free(pvStack_d4);
            return extraout_EAX_03;
          }
          uStack_c0 = 0xf;
          uStack_c4 = 0;
          pvStack_d4 = (void *)((uint)pvStack_d4 & 0xffffff00);
        }
        else {
          iVar4 = FUN_00403620(0,uStack_1e0,s_modal_009bbfb8,5);
          if (iVar4 == 0) {
            uVar3 = FUN_00588600(&local_148);
            cStack_18c = thunk_FUN_00796fe0(uVar3);
            if (0xf < uStack_130) {
              _free(pvStack_144);
              return extraout_EAX_04;
            }
            uStack_130 = 0xf;
            uStack_134 = 0;
            pvStack_144 = (void *)((uint)pvStack_144 & 0xffffff00);
            if (cStack_18c == '\x01') {
              uStack_188 = 0x20000000;
            }
          }
          else {
            iVar4 = FUN_00403620(0,uStack_1e0,s_layer_009bbfc0,5);
            if (iVar4 == 0) {
              uVar3 = FUN_00588600(&pvStack_1d4);
              uStack_178 = thunk_FUN_00796fb0(uVar3);
              if (0xf < uStack_1bc) {
                _free(pvStack_1d0);
                return extraout_EAX_05;
              }
              uStack_1bc = 0xf;
              uStack_1c0 = 0;
              pvStack_1d0 = (void *)((uint)pvStack_1d0 & 0xffffff00);
            }
            else {
              cVar2 = FUN_004036a0(local_1ec + -2,s_alwaysontop_009bbfc8);
              if (cVar2 != '\0') {
                uVar3 = FUN_00588600(auStack_a0);
                thunk_FUN_00796fe0(uVar3);
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              cVar2 = FUN_004036a0(local_1ec + -2,s_position_009bbfd4);
              if (cVar2 != '\0') {
                uVar3 = FUN_00588600(auStack_68);
                uStack_184 = FUN_0055cd00(uVar3);
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              cVar2 = FUN_004036a0(local_1ec + -2,s_layertype_009bbfe0);
              if (cVar2 != '\0') {
                uVar3 = FUN_00588600(auStack_84);
                FUN_004041d0(auStack_bc,uVar3);
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              cVar2 = FUN_004036a0(local_1ec + -2,&DAT_009bc000);
              if (cVar2 == '\0') {
                cVar2 = FUN_004036a0(local_1ec + -2,s_titlerect_009bc008);
                if (cVar2 == '\0') {
                  cVar2 = FUN_004036a0(local_1ec + -2,s_loadchild_009bc014);
                  if (cVar2 != '\0') {
                    uVar3 = FUN_00588600(auStack_4c);
                    FUN_0055dd10(uVar3);
                    /* WARNING: Subroutine does not return */
                    FUN_00446f10();
                  }
                  cVar2 = FUN_0055cad0(local_1ec + -2);
                  if (cVar2 != '\0') {
                    FUN_00588700(local_1ec + -2);
                    break;
                  }
                  cVar2 = FUN_004036a0(local_1ec + -2,s_<_window>_009bc020);
                  if (cVar2 != '\0') break;
                }
                else {
                  puVar5 = (undefined4 *)FUN_0055cde0(auStack_164);
                  uStack_19c = *puVar5;
                  uStack_198 = puVar5[1];
                  uStack_194 = puVar5[2];
                  uStack_190 = puVar5[3];
                }
              }
              else {
                puVar5 = (undefined4 *)FUN_0055cde0(auStack_14);
                uStack_174 = *puVar5;
                uStack_170 = puVar5[1];
                uStack_16c = puVar5[2];
                uStack_168 = puVar5[3];
              }
            }
          }
        }
      }
    }
    else {
      uVar6 = uStack_1e0;
      if (3 < uStack_1e0) {
        uVar6 = 4;
      }
      ppppbVar8 = local_1f0;
      if (local_1dc < 0x10) {
        ppppbVar8 = (byte ****)&local_1f0;
      }
      bVar10 = false;
      iVar4 = 0;
      bVar11 = true;
      pbVar9 = &DAT_009bbfa0;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        bVar10 = *(byte *)ppppbVar8 < *pbVar9;
        bVar11 = *(byte *)ppppbVar8 == *pbVar9;
        ppppbVar8 = (byte ****)((int)ppppbVar8 + 1);
        pbVar9 = pbVar9 + 1;
      } while (bVar11);
      if (!bVar11) {
        iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
      }
      if (((iVar4 != 0) || (uStack_1e0 < 4)) || (uStack_1e0 != 4)) goto LAB_0056a035;
      uVar3 = FUN_00588600(auStack_110);
      FUN_00401660(uVar3,0,0xffffffff);
      if (0xf < uStack_f8) {
        _free(pvStack_10c);
        return extraout_EAX_01;
      }
      uStack_f8 = 0xf;
      uStack_fc = 0;
      pvStack_10c = (void *)((uint)pvStack_10c & 0xffffff00);
    }
    cVar2 = FUN_005885f0();
  }
  piVar1 = local_1d8;
  (**(code **)(*local_1d8 + 8))(apvStack_1b8);
  do {
    while( true ) {
      cVar2 = FUN_005885f0();
      if (cVar2 == '\0') goto LAB_0056a55a;
      uVar3 = FUN_00588600(&local_1d8);
      FUN_00401660(uVar3,0,0xffffffff);
      if (0xf < uStack_1c0) {
        _free(pvStack_1d4);
        return extraout_EAX_06;
      }
      uStack_1c0 = 0xf;
      uStack_1c4 = 0;
      pvStack_1d4 = (void *)((uint)pvStack_1d4 & 0xffffff00);
      cVar2 = FUN_0055cad0(local_1ec + -3);
      pppppbVar7 = (byte *****)(local_1ec + -3);
      if (cVar2 == '\0') break;
      uVar3 = (**(code **)(*piVar1 + 0x2c))(pppppbVar7);
      FUN_005690f0(uVar3,pppppbVar7);
    }
    iVar4 = FUN_00403620(0,uStack_1e4,s_<_window>_009bc02c,9);
  } while (iVar4 == 0);
LAB_0056a55a:
  if (0xf < uStack_1a4) {
    _free(apvStack_1b8[0]);
    return extraout_EAX_07;
  }
  uStack_1a4 = 0xf;
  uStack_1a8 = 0;
  apvStack_1b8[0] = (void *)((uint)apvStack_1b8[0] & 0xffffff00);
  if (uStack_1e0 < 0x10) {
    return piVar1;
  }
  _free(unaff_EBX);
  return extraout_EAX_08;
}


// ==== FUN_0056a5d0 @ 0x0056a5d0 ====

/* WARNING: Removing unreachable block (ram,0x0056a657) */
/* WARNING: Removing unreachable block (ram,0x0056a607) */

undefined4 FUN_0056a5d0(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  int in_ECX;
  
  FUN_00401740(s_new_Tokenizer_i_uiScript__009bbf5c,0x19);
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00588850(param_1);
  }
  *(undefined4 *)(in_ECX + 4) = uVar2;
  FUN_00401740(s_MakeWindow___009bbf78,0xc);
  uVar2 = FUN_00569e10(param_2);
  pvVar1 = *(void **)(in_ECX + 4);
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    return uVar2;
  }
  FUN_00588780();
  _free(pvVar1);
  return extraout_EAX;
}


// ==== FUN_0056a6a0 @ 0x0056a6a0 ====

void FUN_0056a6a0(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5a798 = 0;
  *in_ECX = &PTR_FUN_009bcd5c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0056a6d0 @ 0x0056a6d0 ====

void FUN_0056a6d0(void)

{
  int in_ECX;
  
  FUN_00503950(*(undefined4 *)(*(int *)(in_ECX + 4) + 4));
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  FUN_00503950(*(undefined4 *)(*(int *)(in_ECX + 0x10) + 4));
  *(int *)(*(int *)(in_ECX + 0x10) + 4) = *(int *)(in_ECX + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x10);
  *(int *)(*(int *)(in_ECX + 0x10) + 8) = *(int *)(in_ECX + 0x10);
  return;
}


// ==== FUN_0056a730 @ 0x0056a730 ====

void FUN_0056a730(void)

{
  undefined4 *in_ECX;
  
  in_ECX[2] = 0;
  in_ECX[4] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0xe] = 0;
  in_ECX[3] = 0;
  in_ECX[5] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0xf] = 0;
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  FUN_00503950(*(undefined4 *)(in_ECX[0x19] + 4));
  *(undefined4 *)(in_ECX[0x19] + 4) = in_ECX[0x19];
  in_ECX[0x1a] = 0;
  *(undefined4 *)in_ECX[0x19] = in_ECX[0x19];
  *(undefined4 *)(in_ECX[0x19] + 8) = in_ECX[0x19];
  return;
}


// ==== FUN_0056a7b0 @ 0x0056a7b0 ====

void FUN_0056a7b0(void)

{
  undefined4 *in_ECX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 local_4 [4];
  
  *(undefined1 *)((int)in_ECX + 0x6e) = 1;
  *(undefined1 *)((int)in_ECX + 0x6f) = 1;
  *(undefined1 *)(in_ECX + 0x13) = 1;
  *(undefined1 *)(in_ECX + 0x1b) = 0;
  *(undefined1 *)((int)in_ECX + 0x6d) = 0;
  *in_ECX = 0;
  in_ECX[2] = 0;
  in_ECX[0x12] = 0;
  in_ECX[3] = 0;
  puVar2 = in_ECX + 5;
  if ((uint)in_ECX[10] < 0x10) {
    puVar1 = puVar2;
  }
  else {
    puVar1 = (undefined4 *)*puVar2;
  }
  if (0xf < (uint)in_ECX[10]) {
    puVar2 = (undefined4 *)*puVar2;
  }
  FUN_004bdb30(local_4,puVar2,in_ECX[9] + (int)puVar1);
  puVar2 = in_ECX + 0xc;
  if ((uint)in_ECX[0x11] < 0x10) {
    puVar1 = puVar2;
  }
  else {
    puVar1 = (undefined4 *)*puVar2;
  }
  if (0xf < (uint)in_ECX[0x11]) {
    puVar2 = (undefined4 *)*puVar2;
  }
  FUN_004bdb30(local_4,puVar2,in_ECX[0x10] + (int)puVar1);
  return;
}


// ==== FUN_0056a840 @ 0x0056a840 ====

void FUN_0056a840(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401740(&DAT_0099cf70,0);
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0x10000000;
  *(undefined1 *)(in_ECX + 0x3c) = 1;
  *(undefined1 *)(in_ECX + 0x3d) = 1;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  return;
}


// ==== FUN_0056a8a0 @ 0x0056a8a0 ====

void FUN_0056a8a0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0xffffffd < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00503c00(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x1c);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x1c) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[7] == '\0') {
LAB_0056a9a5:
        *(undefined1 *)(*piVar5 + 0x1c) = 1;
        *(undefined1 *)(piVar6 + 7) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x1c) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0046a370(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x1c) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x1c) = 0;
        FUN_004e1270(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[7] == '\0') goto LAB_0056a9a5;
      if (piVar7 == (int *)*piVar2) {
        FUN_004e1270(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x1c) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x1c) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x1d) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x1c);
  } while( true );
}


// ==== FUN_0056aa80 @ 0x0056aa80 ====

void FUN_0056aa80(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_00503d70(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_0056ab85:
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
      if ((char)piVar6[8] == '\0') goto LAB_0056ab85;
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


// ==== FUN_0056ac60 @ 0x0056ac60 ====

void FUN_0056ac60(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x1d) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x1d) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_0056a8a0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0046a3c0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_0056a8a0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0056ad20 @ 0x0056ad20 ====

void FUN_0056ad20(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_0056aa80(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_004ddea0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_0056aa80(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0056ade0 @ 0x0056ade0 ====

void FUN_0056ade0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00981fa0;
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


// ==== Catch@0056af41 @ 0x0056af41 ====

void Catch_0056af41(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0056b030 @ 0x0056b030 ====

void FUN_0056b030(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_0056ade0(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_0056b080 @ 0x0056b080 ====

void FUN_0056b080(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x5c) == 0) {
    *(undefined4 *)(in_ECX + 0x5c) = 0;
    *(undefined4 *)(in_ECX + 0x60) = 0;
    *(undefined4 *)(in_ECX + 100) = 0;
    FUN_00503950(*(undefined4 *)(*(int *)(in_ECX + 0x10) + 4));
    *(int *)(*(int *)(in_ECX + 0x10) + 4) = *(int *)(in_ECX + 0x10);
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x10);
    *(int *)(*(int *)(in_ECX + 0x10) + 8) = *(int *)(in_ECX + 0x10);
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined4 *)(in_ECX + 0x28) = 0;
    *(undefined4 *)(in_ECX + 0x2c) = 0;
    *(undefined4 *)(in_ECX + 0x30) = 0;
    *(undefined4 *)(in_ECX + 0x34) = 0;
    *(undefined4 *)(in_ECX + 0x38) = 0;
    *(undefined4 *)(in_ECX + 0x3c) = 0;
    *(undefined4 *)(in_ECX + 0x40) = 0;
    *(undefined4 *)(in_ECX + 0x44) = 0;
    *(undefined4 *)(in_ECX + 0x48) = 0;
    *(undefined4 *)(in_ECX + 0x4c) = 0;
    *(undefined4 *)(in_ECX + 0x50) = 0;
    *(undefined4 *)(in_ECX + 0x54) = 0;
    *(undefined4 *)(in_ECX + 0x68) = 0xffffa800;
    *(undefined4 *)(in_ECX + 0x6c) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x70) = 0xff00ff36;
    *(undefined4 *)(in_ECX + 0x74) = 0xff969696;
    return;
  }
  FUN_00405de0(*(int *)(in_ECX + 0x5c),*(undefined4 *)(in_ECX + 0x60),in_ECX + 0x58);
  _free(*(void **)(in_ECX + 0x5c));
  return;
}


// ==== FUN_0056b130 @ 0x0056b130 ====

void FUN_0056b130(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bcddc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0056b150 @ 0x0056b150 ====

void FUN_0056b150(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bcdec;
  in_ECX[1] = 0x800000;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a7a4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a7a4 = in_ECX;
  return;
}


// ==== FUN_0056b180 @ 0x0056b180 ====

undefined4 FUN_0056b180(char param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (param_1 == '\x01') {
    pvVar1 = operator_new(0x90);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_0065a880(*(undefined4 *)(in_ECX + 4));
      *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
      return uVar2;
    }
  }
  else {
    pvVar1 = operator_new(0x74);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00589270(*(undefined4 *)(in_ECX + 4));
      *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
      return uVar2;
    }
  }
  *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
  return 0;
}


// ==== FUN_0056b1e0 @ 0x0056b1e0 ====

undefined4 FUN_0056b1e0(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(1);
  }
  return 1;
}


// ==== FUN_0056b220 @ 0x0056b220 ====

void FUN_0056b220(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5a7a4 = 0;
  *in_ECX = &PTR_FUN_009bcddc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0056b250 @ 0x0056b250 ====

void FUN_0056b250(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bce7c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0056b270 @ 0x0056b270 ====

undefined4 FUN_0056b270(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_0056b280 @ 0x0056b280 ====

void FUN_0056b280(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_0056b290 @ 0x0056b290 ====

undefined4 FUN_0056b290(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0056b2a0 @ 0x0056b2a0 ====

void FUN_0056b2a0(void)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x30))();
                    /* WARNING: Could not recover jumptable at 0x0056b2a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x18))();
  return;
}


// ==== FUN_0056b2b0 @ 0x0056b2b0 ====

undefined4 FUN_0056b2b0(int *param_1)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = (**(code **)(*in_ECX + 0x3c))();
  iVar2 = in_ECX[9];
  iVar4 = in_ECX[8];
  if (iVar1 == 0) {
    iVar4 = iVar4 - in_ECX[6];
    iVar2 = iVar2 - in_ECX[7];
  }
  if (iVar4 < *param_1) {
    iVar3 = iVar2;
    iVar4 = *param_1;
  }
  else {
    iVar3 = param_1[1];
    if (iVar3 <= iVar2) {
      return 0;
    }
  }
  if (iVar1 == 0) {
    in_ECX[8] = in_ECX[6] + iVar4;
    in_ECX[9] = in_ECX[7] + iVar3;
    (**(code **)(*in_ECX + 0xc))(in_ECX + 4);
    return 1;
  }
  in_ECX[9] = iVar3;
  in_ECX[8] = iVar4;
  (**(code **)(*in_ECX + 0xc))(in_ECX + 4);
  return 1;
}


// ==== FUN_0056b330 @ 0x0056b330 ====

int FUN_0056b330(void)

{
  int in_ECX;
  
  return in_ECX + 0x10;
}


// ==== FUN_0056b340 @ 0x0056b340 ====

int FUN_0056b340(void)

{
  int in_ECX;
  
  return in_ECX + 0x4c;
}


// ==== FUN_0056b350 @ 0x0056b350 ====

undefined1 FUN_0056b350(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x11);
}


// ==== FUN_0056b360 @ 0x0056b360 ====

void FUN_0056b360(undefined1 param_1)

{
  int *in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = param_1;
  (**(code **)(*in_ECX + 0x20))();
  return;
}


// ==== FUN_0056b370 @ 0x0056b370 ====

undefined1 FUN_0056b370(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x10);
}


// ==== FUN_0056b380 @ 0x0056b380 ====

undefined4 FUN_0056b380(int *param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0xc) == '\0') {
    return 0;
  }
  *(int **)(in_ECX + 0x90) = param_1;
  (**(code **)(*param_1 + 0xc))(in_ECX + 0x4c);
  return 1;
}


// ==== FUN_0056b3b0 @ 0x0056b3b0 ====

undefined4 FUN_0056b3b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x90);
}


// ==== FUN_0056b3c0 @ 0x0056b3c0 ====

undefined4 FUN_0056b3c0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x94);
}


// ==== FUN_0056b3d0 @ 0x0056b3d0 ====

undefined4 FUN_0056b3d0(int param_1)

{
  int *in_ECX;
  
  if ((char)in_ECX[3] == '\0') {
    return 0;
  }
  in_ECX[0x25] = param_1;
  (**(code **)(*in_ECX + 0x20))();
  return 1;
}


// ==== FUN_0056b3f0 @ 0x0056b3f0 ====

undefined1 FUN_0056b3f0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0xd);
}


// ==== FUN_0056b400 @ 0x0056b400 ====

void FUN_0056b400(int *param_1,int *param_2)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(in_ECX + 0x28);
  if (iVar1 == 1) {
    iVar1 = (param_2[2] + *param_2) / 2;
LAB_0056b439:
    iVar3 = *(int *)(in_ECX + 0x20) + iVar1;
  }
  else {
    if (iVar1 == 2) {
      iVar1 = param_2[2];
      goto LAB_0056b439;
    }
    if (iVar1 != 3) {
      iVar1 = *param_2;
      goto LAB_0056b439;
    }
    iVar1 = *param_2;
    iVar3 = param_2[2] - *(int *)(in_ECX + 0x20);
  }
  iVar4 = *(int *)(in_ECX + 0x2c);
  if (iVar4 == 1) {
    iVar4 = (param_2[3] + param_2[1]) / 2;
LAB_0056b475:
    iVar2 = *(int *)(in_ECX + 0x1c);
  }
  else {
    if (iVar4 == 2) {
      iVar4 = param_2[3];
      goto LAB_0056b475;
    }
    iVar2 = *(int *)(in_ECX + 0x1c);
    if (iVar4 == 3) {
      iVar2 = iVar2 + param_2[1];
      iVar4 = param_2[3] - *(int *)(in_ECX + 0x24);
      goto LAB_0056b47f;
    }
    iVar4 = param_2[1];
  }
  iVar2 = iVar2 + iVar4;
  iVar4 = *(int *)(in_ECX + 0x24) + iVar4;
LAB_0056b47f:
  *param_1 = *(int *)(in_ECX + 0x18) + iVar1;
  param_1[1] = iVar2;
  param_1[2] = iVar3;
  param_1[3] = iVar4;
  return;
}


// ==== FUN_0056b4c0 @ 0x0056b4c0 ====

undefined4 FUN_0056b4c0(void)

{
  int *in_ECX;
  
  if ((char)in_ECX[3] == '\0') {
    return 0;
  }
  (**(code **)(*in_ECX + 0x70))();
  (**(code **)(*DAT_00b5a7ac + 0x10))(in_ECX[0x24]);
  *(undefined1 *)(in_ECX + 3) = 0;
  return 1;
}


// ==== FUN_0056b4f0 @ 0x0056b4f0 ====

uint FUN_0056b4f0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x30))();
  uVar4 = 0;
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*in_ECX + 0x3c))();
    uVar4 = 0;
    if (iVar1 != 0) {
      piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
      iVar1 = *piVar2;
      uVar3 = (**(code **)(*in_ECX + 0x50))(param_1,param_2);
      uVar3 = (**(code **)(*in_ECX + 0x54))(uVar3);
      uVar4 = (**(code **)(iVar1 + 0x88))(uVar3);
      if ((char)uVar4 == '\x01') {
        return uVar4;
      }
    }
  }
  return uVar4 & 0xffffff00;
}


// ==== FUN_0056b550 @ 0x0056b550 ====

undefined4 FUN_0056b550(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  iVar2 = (**(code **)(*in_ECX + 0x30))();
  if (iVar2 != 0) {
    piVar3 = (int *)(**(code **)(*in_ECX + 0x30))();
    cVar1 = (**(code **)(*piVar3 + 0x14))(param_1,param_2,param_3,param_4);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  iVar2 = (**(code **)(*in_ECX + 0x3c))();
  if (iVar2 != 0) {
    piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
    cVar1 = (**(code **)(*piVar3 + 0x88))(param_1,param_2,param_3,param_4);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  iVar2 = (**(code **)(*in_ECX + 0x38))();
  if (iVar2 != 0) {
    piVar3 = (int *)(**(code **)(*in_ECX + 0x38))();
    cVar1 = (**(code **)(*piVar3 + 0x3c))(param_1,param_2,param_3,param_4);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0056b5f0 @ 0x0056b5f0 ====

undefined4 FUN_0056b5f0(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x30))();
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x30))();
    uVar3 = (**(code **)(*piVar2 + 0x10))(param_1);
    if ((char)uVar3 == '\x01') {
      return uVar3;
    }
  }
  iVar1 = (**(code **)(*in_ECX + 0x3c))();
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
    uVar3 = (**(code **)(*piVar2 + 0x84))(param_1);
    return uVar3;
  }
  iVar1 = (**(code **)(*in_ECX + 0x38))();
  if (iVar1 == 0) {
    return 0;
  }
  piVar2 = (int *)(**(code **)(*in_ECX + 0x38))();
  uVar3 = (**(code **)(*piVar2 + 0x38))(param_1);
  return uVar3;
}


// ==== FUN_0056b660 @ 0x0056b660 ====

void FUN_0056b660(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xd) = 1;
  (**(code **)(*DAT_00b5a7a8 + 0x14))(*(undefined4 *)(in_ECX + 8));
  return;
}


// ==== FUN_0056b680 @ 0x0056b680 ====

void FUN_0056b680(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xd) = 0;
  (**(code **)(*DAT_00b5a7a8 + 0x14))(*(undefined4 *)(in_ECX + 8));
  return;
}


// ==== FUN_0056b6a0 @ 0x0056b6a0 ====

void FUN_0056b6a0(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  *(char *)(in_ECX + 0x11) = (char)param_1;
  if (*(int **)(in_ECX + 0x90) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x90) + 0x28))(param_1);
  }
  puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x98) + 8);
  for (puVar2 = *(undefined4 **)(*(int *)(in_ECX + 0x98) + 4); puVar2 != puVar1; puVar2 = puVar2 + 1
      ) {
    (**(code **)(*(int *)*puVar2 + 0x44))(param_1);
  }
  return;
}


// ==== FUN_0056b6f0 @ 0x0056b6f0 ====

undefined4 FUN_0056b6f0(undefined4 param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int *piVar3;
  char *pcVar4;
  int in_ECX;
  undefined4 *puVar5;
  
  if (*(char *)(in_ECX + 0x11) == '\0') {
    return 0;
  }
  if (*(int *)(in_ECX + 0x90) != 0) {
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0x90) + 0x3c))();
    pcVar4 = (char *)(**(code **)(*piVar3 + 0x10))();
    if ((*pcVar4 == '\x01') &&
       (cVar2 = (**(code **)(**(int **)(in_ECX + 0x90) + 4))(param_1), cVar2 != '\0')) {
      return 1;
    }
  }
  puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x98) + 8);
  puVar5 = *(undefined4 **)(*(int *)(in_ECX + 0x98) + 4);
  while( true ) {
    if (puVar5 == puVar1) {
      return 0;
    }
    piVar3 = (int *)*puVar5;
    pcVar4 = (char *)(**(code **)(*piVar3 + 0x14))();
    if ((*pcVar4 != '\0') && (cVar2 = (**(code **)(*piVar3 + 0x1c))(param_1), cVar2 != '\0')) break;
    puVar5 = puVar5 + 1;
  }
  return 1;
}


// ==== FUN_0056b790 @ 0x0056b790 ====

void FUN_0056b790(void)

{
  undefined4 *puVar1;
  int *piVar2;
  byte *pbVar3;
  int iVar4;
  int *in_ECX;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined1 auStack_38 [16];
  byte bStack_28;
  byte bStack_27;
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  if (piVar2 == (int *)0x0) {
    iStack_18 = *(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xa0);
    iStack_4 = *(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x9c);
    bStack_27 = 1;
    bStack_28 = 1;
    iStack_24 = 0;
    uStack_20 = 0;
    uStack_1c = 0;
    iStack_10 = 0;
    iStack_c = 0;
    iStack_14 = iStack_4;
    iStack_8 = iStack_18;
  }
  else {
    pbVar3 = (byte *)(**(code **)(*piVar2 + 0x14))();
    bStack_28 = *pbVar3;
    bStack_27 = pbVar3[1];
    iStack_24 = *(int *)(pbVar3 + 4);
    uStack_20 = *(undefined4 *)(pbVar3 + 8);
    uStack_1c = *(undefined4 *)(pbVar3 + 0xc);
    iStack_18 = *(int *)(pbVar3 + 0x10);
    iStack_10 = *(int *)(pbVar3 + 0x18);
    iStack_c = *(int *)(pbVar3 + 0x1c);
    iStack_8 = *(int *)(pbVar3 + 0x20);
    iStack_4 = *(int *)(pbVar3 + 0x24);
    iStack_14 = *(int *)(pbVar3 + 0x14);
  }
  if (*(char *)((int)in_ECX + 0x12) == '\0') {
    iStack_8 = *(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xa0);
    iStack_4 = *(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x9c);
    iStack_10 = 0;
    iStack_c = 0;
  }
  in_ECX[0x14] = in_ECX[5] + iStack_24;
  *(byte *)((int)in_ECX + 0x4d) = *(byte *)((int)in_ECX + 0x11) & bStack_27;
  *(byte *)(in_ECX + 0x13) = *(byte *)(in_ECX + 4) & bStack_28;
  piVar2 = (int *)(**(code **)(*in_ECX + 0x6c))(auStack_38,&uStack_20);
  in_ECX[0x15] = *piVar2;
  iVar5 = piVar2[1];
  in_ECX[0x16] = iVar5;
  iVar6 = piVar2[2];
  in_ECX[0x17] = iVar6;
  in_ECX[0x18] = piVar2[3];
  iVar4 = in_ECX[0x15];
  if (in_ECX[0x15] <= iStack_18) {
    iVar4 = iStack_18;
  }
  if (iVar5 <= iStack_14) {
    iVar5 = iStack_14;
  }
  if (iStack_10 < iVar6) {
    iVar6 = iStack_10;
  }
  iVar7 = in_ECX[0x18];
  if (iStack_c < in_ECX[0x18]) {
    iVar7 = iStack_c;
  }
  in_ECX[0x19] = iVar4;
  in_ECX[0x1a] = iVar5;
  in_ECX[0x1b] = iVar6;
  in_ECX[0x1c] = iVar7;
  if ((int *)in_ECX[0x24] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x24] + 0xc))(in_ECX + 0x13);
  }
  puVar1 = *(undefined4 **)(in_ECX[0x26] + 8);
  for (puVar8 = *(undefined4 **)(in_ECX[0x26] + 4); puVar8 != puVar1; puVar8 = puVar8 + 1) {
    (**(code **)(*(int *)*puVar8 + 0x20))();
  }
  return;
}


// ==== FUN_0056b920 @ 0x0056b920 ====

int * FUN_0056b920(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x98) + 8);
  puVar4 = *(undefined4 **)(*(int *)(in_ECX + 0x98) + 4);
  while( true ) {
    if (puVar4 == puVar1) {
      return (int *)0x0;
    }
    piVar3 = (int *)*puVar4;
    iVar2 = (**(code **)(*piVar3 + 4))();
    if (iVar2 == *param_1) break;
    piVar3 = (int *)(**(code **)(*piVar3 + 0x48))(param_1);
    if (piVar3 != (int *)0x0) {
      return piVar3;
    }
    puVar4 = puVar4 + 1;
  }
  return piVar3;
}


// ==== FUN_0056b970 @ 0x0056b970 ====

int FUN_0056b970(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  iVar2 = param_1;
  FUN_0041ec50(&param_1,param_1);
  if (param_1 != *(int *)(in_ECX + 0xa4)) {
    return *(int *)(param_1 + 0x24);
  }
  puVar4 = *(undefined4 **)(*(int *)(in_ECX + 0x98) + 4);
  puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x98) + 8);
  while( true ) {
    if (puVar4 == puVar1) {
      return 0;
    }
    iVar3 = (**(code **)(*(int *)*puVar4 + 0x4c))(iVar2);
    if (iVar3 != 0) break;
    puVar4 = puVar4 + 1;
  }
  return iVar3;
}


// ==== FUN_0056b9d0 @ 0x0056b9d0 ====

undefined4 FUN_0056b9d0(undefined4 param_1)

{
  int *in_ECX;
  
  if ((char)in_ECX[3] == '\0') {
    return 0;
  }
  FUN_004fed70(param_1);
  (**(code **)(*in_ECX + 0x20))();
  return 1;
}


// ==== FUN_0056ba00 @ 0x0056ba00 ====

uint FUN_0056ba00(undefined4 param_1)

{
  uint in_EAX;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0xc) == '\0') {
    FUN_004fed70(param_1);
    *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(in_ECX + 0x14);
    *(undefined1 *)(in_ECX + 0x4d) = *(undefined1 *)(in_ECX + 0x11);
    *(undefined1 *)(in_ECX + 0x4c) = *(undefined1 *)(in_ECX + 0x10);
    *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(in_ECX + 0x18);
    *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(in_ECX + 0x1c);
    *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(in_ECX + 0x20);
    *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(in_ECX + 0x24);
    *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(in_ECX + 0x18);
    *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(in_ECX + 0x1c);
    *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(in_ECX + 0x20);
    *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(in_ECX + 0x24);
    *(undefined1 *)(in_ECX + 0xc) = 1;
    *(undefined1 *)(in_ECX + 0xd) = 0;
    return CONCAT31((int3)((uint)*(undefined4 *)(in_ECX + 0x1c) >> 8),1);
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_0056ba70 @ 0x0056ba70 ====

undefined4 FUN_0056ba70(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  
  iVar2 = param_1;
  puVar1 = (undefined4 *)**(undefined4 **)(in_ECX + 0xa4);
  do {
    if (puVar1 == *(undefined4 **)(in_ECX + 0xa4)) {
LAB_0056baa3:
      piVar3 = *(int **)(*(int *)(in_ECX + 0x98) + 4);
      while( true ) {
        if (piVar3 == *(int **)(*(int *)(in_ECX + 0x98) + 8)) {
          return 0;
        }
        if (*piVar3 == iVar2) break;
        piVar3 = piVar3 + 1;
      }
      (**(code **)(*DAT_00b5a7ac + 0xc))(*piVar3);
      iVar2 = *(int *)(in_ECX + 0x98);
      _memmove(piVar3,piVar3 + 1,(*(int *)(iVar2 + 8) - (int)(piVar3 + 1) >> 2) * 4);
      piVar3 = (int *)(iVar2 + 8);
      *piVar3 = *piVar3 + -4;
      return 1;
    }
    if (puVar1[9] == param_1) {
      FUN_0056c560(&param_1,puVar1);
      goto LAB_0056baa3;
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}


// ==== FUN_0056bb00 @ 0x0056bb00 ====

void FUN_0056bb00(undefined4 param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  
  in_ECX[2] = param_1;
  *in_ECX = &PTR_FUN_009bcf0c;
  *(undefined1 *)(in_ECX + 3) = 0;
  *(undefined1 *)((int)in_ECX + 0x12) = 1;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0xf;
  *(undefined1 *)(in_ECX + 0xd) = 0;
  in_ECX[0x23] = 0xf;
  in_ECX[0x22] = 0;
  *(undefined1 *)(in_ECX + 0x1e) = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  *(undefined1 *)(in_ECX + 0x27) = (undefined1)param_1;
  uVar1 = FUN_0056c030();
  in_ECX[0x29] = uVar1;
  in_ECX[0x2a] = 0;
  param_1 = in_ECX[0x29];
  FUN_0056c4b0(9,&param_1);
  in_ECX[0x2f] = 1;
  in_ECX[0x30] = 1;
  in_ECX[1] = 0;
  pvVar2 = operator_new(0x10);
  if (pvVar2 == (void *)0x0) {
    in_ECX[0x26] = 0;
    return;
  }
  *(undefined4 *)((int)pvVar2 + 4) = 0;
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0;
  in_ECX[0x26] = pvVar2;
  return;
}


// ==== FUN_0056bbe0 @ 0x0056bbe0 ====

void FUN_0056bbe0(void)

{
  int iVar1;
  void *_Memory;
  undefined4 *in_ECX;
  undefined4 uStack_4;
  
  *in_ECX = &PTR_FUN_009bcf0c;
  if (*(char *)(in_ECX + 3) == '\x01') {
    (*(code *)PTR_FUN_009bcf7c)();
    (**(code **)(*DAT_00b5a7ac + 0x10))(in_ECX[0x24]);
    *(undefined1 *)(in_ECX + 3) = 0;
  }
  iVar1 = in_ECX[0x26];
  if (*(void **)(iVar1 + 4) != (void *)0x0) {
    _free(*(void **)(iVar1 + 4));
    return;
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  FUN_0059c2f0();
  uStack_4 = in_ECX[0x29];
  FUN_0056c680(9,&uStack_4);
  in_ECX[0x2f] = 1;
  in_ECX[0x30] = 1;
  _Memory = (void *)in_ECX[0x26];
  if (_Memory == (void *)0x0) {
    in_ECX[0x26] = 0;
    if ((void *)in_ECX[0x2c] == (void *)0x0) {
      in_ECX[0x2c] = 0;
      in_ECX[0x2d] = 0;
      in_ECX[0x2e] = 0;
      FUN_0059c2f0();
      _free((void *)in_ECX[0x29]);
      return;
    }
    _free((void *)in_ECX[0x2c]);
    return;
  }
  if (*(void **)((int)_Memory + 4) == (void *)0x0) {
    *(undefined4 *)((int)_Memory + 4) = 0;
    *(undefined4 *)((int)_Memory + 8) = 0;
    *(undefined4 *)((int)_Memory + 0xc) = 0;
    _free(_Memory);
    return;
  }
  _free(*(void **)((int)_Memory + 4));
  return;
}


// ==== FUN_0056bd30 @ 0x0056bd30 ====

/* WARNING: Removing unreachable block (ram,0x0056be0b) */
/* WARNING: Removing unreachable block (ram,0x0056be10) */

void FUN_0056bd30(void)

{
  int iVar1;
  code *pcVar2;
  int in_ECX;
  int *piVar3;
  int *local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  piVar3 = *(int **)(*(int *)(in_ECX + 0x98) + 4);
  local_20 = *(int **)(*(int *)(in_ECX + 0x98) + 8);
  if (piVar3 != local_20) {
    do {
      if (*piVar3 == 0) {
        local_4 = 0xf;
        local_8 = 0;
        local_18 = (void *)((uint)local_18 & 0xffffff00);
        FUN_00401740(s_pComposite_009bce44,10);
        FUN_00406880(local_1c);
        if (local_4 < 0x10) {
          local_4 = 0xf;
          local_8 = 0;
          local_18 = (void *)((uint)local_18 & 0xffffff00);
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        _free(local_18);
        return;
      }
      (**(code **)(*DAT_00b5a7ac + 0xc))(*piVar3);
      piVar3 = piVar3 + 1;
    } while (piVar3 != local_20);
  }
  iVar1 = *(int *)(in_ECX + 0x98);
  if (*(void **)(iVar1 + 4) != (void *)0x0) {
    _free(*(void **)(iVar1 + 4));
    return;
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  FUN_0059c2f0();
  local_20 = *(int **)(in_ECX + 0xa4);
  if (*(int *)(in_ECX + 0xb0) != *(int *)(in_ECX + 0xb4)) {
    *(int *)(in_ECX + 0xb4) = *(int *)(in_ECX + 0xb0);
  }
  FUN_0056c1d0(*(undefined4 *)(in_ECX + 0xb0),9,&local_20);
  *(undefined4 *)(in_ECX + 0xbc) = 1;
  *(undefined4 *)(in_ECX + 0xc0) = 1;
  return;
}


// ==== FUN_0056be50 @ 0x0056be50 ====

undefined4 FUN_0056be50(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int *in_ECX;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  int *piStack_4;
  
  if ((char)in_ECX[3] == '\0') {
    return 0;
  }
  FUN_00558010(&param_1);
  piVar1 = param_1;
  piVar3 = (int *)in_ECX[0x29];
  uVar2 = (**(code **)(*param_1 + 0x50))();
  FUN_0041ec50(&param_1,uVar2);
  if (param_1 != piVar3) {
    piVar3 = (int *)(**(code **)(*in_ECX + 0x38))();
    (**(code **)(*piVar1 + 0x50))();
    (**(code **)(*piVar3 + 0x10))();
    FUN_00401740(s__Same___s__s_009bce34,0xc);
    uVar2 = FUN_00404230(auStack_20);
    FUN_00403e50(uVar2);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return extraout_EAX;
    }
  }
  uVar2 = (**(code **)(*piVar1 + 0x50))();
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  FUN_00401660(uVar2,0,0xffffffff);
  piStack_4 = piVar1;
  FUN_0056c6f0(auStack_28,auStack_20);
  if (uStack_8 < 0x10) {
    return 1;
  }
  _free(pvStack_1c);
  return extraout_EAX_00;
}


// ==== FUN_0056bf90 @ 0x0056bf90 ====

void FUN_0056bf90(int param_1,int param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_2 = param_2 + -4) {
    param_3 = param_3 + -1;
    *param_3 = *(undefined4 *)(param_2 + -4);
  }
  return;
}


// ==== FUN_0056bfc0 @ 0x0056bfc0 ====

int FUN_0056bfc0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981fb0;
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


// ==== Catch@0056c026 @ 0x0056c026 ====

void Catch_0056c026(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0056c030 @ 0x0056c030 ====

void FUN_0056c030(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981fc0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x28);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0056c09f @ 0x0056c09f ====

void Catch_0056c09f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0056c0c0 @ 0x0056c0c0 ====

void FUN_0056c0c0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981fd0;
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


// ==== Catch@0056c126 @ 0x0056c126 ====

void Catch_0056c126(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0056c130 @ 0x0056c130 ====

void FUN_0056c130(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0056bfc0(param_1,param_2,param_3);
  return;
}


// ==== FUN_0056c150 @ 0x0056c150 ====

int FUN_0056c150(int param_1,int param_2,undefined4 param_3)

{
  FUN_0056c0c0(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_0056c180 @ 0x0056c180 ====

void FUN_0056c180(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  FUN_00401660(param_3,0,0xffffffff);
  in_ECX[9] = *(undefined4 *)(param_3 + 0x1c);
  return;
}


// ==== FUN_0056c1d0 @ 0x0056c1d0 ====

void FUN_0056c1d0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00981fe0;
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
      uVar5 = FUN_0056c130(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_0056c150(uVar5,param_2,&local_18);
      FUN_0056c130(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_0056bfc0(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_0056c150(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_0056bfc0(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0056c331 @ 0x0056c331 ====

void Catch_0056c331(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0056c420 @ 0x0056c420 ====

void * FUN_0056c420(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981ff0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x28);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_0056c180(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@0056c48d @ 0x0056c48d ====

void Catch_0056c48d(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0056c4b0 @ 0x0056c4b0 ====

void FUN_0056c4b0(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982000;
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
    uVar2 = FUN_0056c150(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0056c544 @ 0x0056c544 ====

void Catch_0056c544(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0056c560 @ 0x0056c560 ====

void FUN_0056c560(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  
  uVar3 = *(uint *)(in_ECX + 0x20);
  uVar5 = FUN_0041e6e0(param_2 + 2);
  uVar5 = uVar5 & uVar3;
  if (*(uint *)(in_ECX + 0x24) <= uVar5) {
    uVar5 = uVar5 + (-1 - (uVar3 >> 1));
  }
  iVar4 = *(int *)(in_ECX + 0x14);
  iVar1 = uVar5 * 4;
  piVar2 = *(int **)(iVar1 + iVar4);
  while ((param_2 == piVar2 &&
         (*(undefined4 *)(iVar1 + iVar4) = **(undefined4 **)(iVar1 + iVar4), uVar5 != 0))) {
    iVar4 = *(int *)(in_ECX + 0x14);
    uVar5 = uVar5 - 1;
    iVar1 = uVar5 * 4;
    piVar2 = *(int **)(iVar1 + iVar4);
  }
  if (param_2 == *(int **)(in_ECX + 8)) {
    *param_1 = *param_2;
    return;
  }
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  if ((uint)param_2[8] < 0x10) {
    param_2[8] = 0xf;
    param_2[7] = 0;
    *(undefined1 *)(param_2 + 3) = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[3]);
  return;
}


// ==== FUN_0056c610 @ 0x0056c610 ====

void FUN_0056c610(uint param_1,undefined1 param_2)

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
    FUN_0056c1d0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_0056c680 @ 0x0056c680 ====

/* WARNING: Removing unreachable block (ram,0x0056c69b) */
/* WARNING: Removing unreachable block (ram,0x0056c6a0) */
/* WARNING: Removing unreachable block (ram,0x0056c6ae) */

void FUN_0056c680(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_0056c1d0(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_0056c6d0 @ 0x0056c6d0 ====

int FUN_0056c6d0(void)

{
  int in_ECX;
  
  return in_ECX + 0x30;
}


// ==== FUN_0056c6e0 @ 0x0056c6e0 ====

undefined4 FUN_0056c6e0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x98);
}


// ==== FUN_0056c6f0 @ 0x0056c6f0 ====

/* WARNING: Removing unreachable block (ram,0x0056c80b) */
/* WARNING: Removing unreachable block (ram,0x0056c9ff) */

void FUN_0056c6f0(int *param_1,int param_2)

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
      FUN_0056c610(iVar4 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
LAB_0056c954:
        if ((uint)piVar11[7] <= uVar9) {
          bVar15 = false;
          goto LAB_0056c964;
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
        if (iVar6 == 0) goto LAB_0056c954;
LAB_0056c964:
        if (!bVar15) {
          if (*(uint *)(param_2 + 0x18) < 0x10) {
            pbVar14 = (byte *)(param_2 + 4);
          }
          else {
            pbVar14 = *(byte **)(param_2 + 4);
          }
          uVar9 = piVar11[7];
          if (uVar9 == 0) goto LAB_0056ca2c;
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
          goto code_r0x0056ca1f;
        }
      }
    } while (piVar11 != *(int **)(*(int *)(in_ECX + 0x14) + iVar4));
  }
  goto LAB_0056c975;
  while( true ) {
    uVar7 = uVar7 - 1;
    bVar15 = *pbVar13 < *pbVar14;
    bVar16 = *pbVar13 == *pbVar14;
    pbVar13 = pbVar13 + 1;
    pbVar14 = pbVar14 + 1;
    if (!bVar16) break;
code_r0x0056ca1f:
    if (uVar7 == 0) break;
  }
  if (!bVar16) {
    iVar6 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
  }
  bVar15 = iVar6 < 0;
  if (iVar6 == 0) {
LAB_0056ca2c:
    if (uVar5 <= uVar9) {
      bVar15 = false;
      goto LAB_0056ca3d;
    }
  }
  else {
LAB_0056ca3d:
    if (!bVar15) {
      *param_1 = (int)piVar11;
      *(undefined1 *)(param_1 + 1) = 0;
      return;
    }
  }
  piVar11 = (int *)*piVar11;
LAB_0056c975:
  iVar6 = FUN_0056c420(piVar11,piVar11[1],param_2);
  FUN_0059c010(1);
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


// ==== FUN_0056ca60 @ 0x0056ca60 ====

void FUN_0056ca60(byte param_1)

{
  void *in_ECX;
  
  FUN_0056bbe0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0056cac0 @ 0x0056cac0 ====

void FUN_0056cac0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa4) = param_1;
  return;
}


// ==== FUN_0056cae0 @ 0x0056cae0 ====

void FUN_0056cae0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(param_1,0);
  }
  return;
}


// ==== FUN_0056cb00 @ 0x0056cb00 ====

undefined4 FUN_0056cb00(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) == '\0') {
    return 0;
  }
  *(undefined1 *)(in_ECX + 0x44) = 0;
  if (*(undefined4 **)(in_ECX + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x40))(1);
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  return 1;
}


// ==== FUN_0056cb30 @ 0x0056cb30 ====

void FUN_0056cb30(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  
  if (param_2 == 0) {
    param_2 = 0;
    iVar4 = 0;
  }
  else {
    iVar4 = param_2 / *(int *)(in_ECX + 0xa0);
    param_2 = param_2 % *(int *)(in_ECX + 0xa0);
  }
  iVar1 = *(int *)(in_ECX + 0xd8);
  iVar2 = *(int *)(in_ECX + 0xdc);
  iVar3 = *(int *)(in_ECX + 0xac) * iVar4 + *(int *)(in_ECX + 0x98);
  iVar4 = *(int *)(in_ECX + 0xa8) * param_2 + *(int *)(in_ECX + 0x98);
  *param_1 = iVar4;
  param_1[1] = iVar3;
  param_1[2] = iVar1 + iVar4;
  param_1[3] = iVar2 + iVar3;
  return;
}


// ==== FUN_0056cba0 @ 0x0056cba0 ====

void FUN_0056cba0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  
  if (param_2 == 0) {
    param_2 = 0;
    iVar2 = 0;
  }
  else {
    iVar2 = param_2 / *(int *)(in_ECX + 0xa0);
    param_2 = param_2 % *(int *)(in_ECX + 0xa0);
  }
  iVar1 = *(int *)(in_ECX + 0xb8);
  iVar3 = *(int *)(in_ECX + 0xa8) * param_2 + *(int *)(in_ECX + 0xb0);
  iVar4 = *(int *)(in_ECX + 0xac) * iVar2 + *(int *)(in_ECX + 0xb4);
  iVar2 = *(int *)(in_ECX + 0xbc);
  *param_1 = iVar3;
  param_1[1] = iVar4;
  param_1[2] = iVar1 + iVar3;
  param_1[3] = iVar2 + iVar4;
  return;
}


// ==== FUN_0056cc20 @ 0x0056cc20 ====

void FUN_0056cc20(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  
  if (param_2 == 0) {
    param_2 = 0;
    iVar4 = 0;
  }
  else {
    iVar4 = param_2 / *(int *)(in_ECX + 0xa0);
    param_2 = param_2 % *(int *)(in_ECX + 0xa0);
  }
  iVar1 = *(int *)(in_ECX + 200);
  iVar3 = *(int *)(in_ECX + 0xa8) * param_2 + *(int *)(in_ECX + 0xc0);
  iVar4 = *(int *)(in_ECX + 0xac) * iVar4;
  iVar2 = *(int *)(in_ECX + 0xcc);
  *param_1 = iVar3;
  param_1[1] = iVar4;
  param_1[2] = iVar1 + iVar3;
  param_1[3] = iVar2 + iVar4;
  return;
}


// ==== FUN_0056cc80 @ 0x0056cc80 ====

void FUN_0056cc80(undefined1 *param_1)

{
  int in_ECX;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
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
  
  *(undefined1 *)(in_ECX + 0x48) = *param_1;
  *(undefined1 *)(in_ECX + 0x49) = param_1[1];
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x24);
  if ((*(int *)(in_ECX + 0x40) != 0) && (*(int *)(in_ECX + 4) != 0)) {
    local_34[0] = *(undefined1 *)(in_ECX + 0x48);
    local_c = *(undefined4 *)(in_ECX + 0x150);
    local_8 = *(undefined4 *)(in_ECX + 0x154);
    local_4 = *(undefined4 *)(in_ECX + 0x158);
    local_30 = *(undefined4 *)(in_ECX + 0x4c);
    local_28 = *(undefined4 *)(in_ECX + 0x54);
    local_2c = *(undefined4 *)(in_ECX + 0x50);
    local_20 = *(undefined4 *)(in_ECX + 0x5c);
    local_24 = *(undefined4 *)(in_ECX + 0x58);
    local_18 = *(undefined4 *)(in_ECX + 100);
    local_1c = *(undefined4 *)(in_ECX + 0x60);
    local_10 = *(undefined4 *)(in_ECX + 0x6c);
    local_14 = *(undefined4 *)(in_ECX + 0x68);
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x1c))(local_34);
  }
  return;
}


// ==== FUN_0056ce00 @ 0x0056ce00 ====

void FUN_0056ce00(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined1 auStack_78 [8];
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  int iStack_64;
  void *pvStack_54;
  undefined4 uStack_44;
  uint auStack_40 [3];
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  piVar1 = *(int **)(in_ECX + 0x80);
  piVar8 = *(int **)(in_ECX + 0x7c);
  do {
    if (piVar8 == piVar1) {
      return;
    }
    piVar2 = (int *)(**(code **)(*(int *)*piVar8 + 0x3c))();
    uVar3 = (**(code **)(*piVar2 + 0x10))();
    FUN_005041e0(uVar3);
    piVar2 = (int *)(**(code **)(*(int *)piVar8[2] + 0x3c))();
    uVar3 = (**(code **)(*piVar2 + 0x10))();
    FUN_005041e0(uVar3);
    if (*(char *)(*piVar8 + 0x72) == '\x01') {
LAB_0056cffa:
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      if (0xf < auStack_40[0]) {
        _free(pvStack_54);
        return;
      }
    }
    else {
      iVar6 = (iStack_68 - iStack_70) + -2;
      iVar7 = (iStack_64 - iStack_6c) + -2;
      piVar2 = (int *)(**(code **)(*(int *)*piVar8 + 0x3c))();
      iVar4 = (**(code **)(*piVar2 + 0x50))();
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        iVar5 = param_1 + 4;
      }
      else {
        iVar5 = *(int *)(param_1 + 4);
      }
      iVar4 = FUN_00403620(0,*(undefined4 *)(iVar4 + 0x14),iVar5,*(undefined4 *)(param_1 + 0x14));
      if (iVar4 == 0) {
        if ((iVar6 == param_2) && (iVar7 == param_3)) {
          if (0xf < uStack_4) {
            _free(pvStack_18);
            return;
          }
          uStack_4 = 0xf;
          uStack_8 = 0;
          pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
          if (0xf < auStack_40[0]) {
            _free(pvStack_54);
            return;
          }
          goto LAB_0056d0ea;
        }
        iStack_68 = param_2 + iStack_70;
        iStack_64 = param_3 + iStack_6c;
        if ((param_2 == *(int *)(in_ECX + 0xd8)) && (param_3 == *(int *)(in_ECX + 0xdc))) {
          iStack_70 = iStack_70 + *(int *)(in_ECX + 0xd0);
          iStack_6c = iStack_6c + *(int *)(in_ECX + 0xd4);
          iStack_68 = iStack_68 + *(int *)(in_ECX + 0xd0);
          iStack_64 = iStack_64 + *(int *)(in_ECX + 0xd4);
          iStack_34 = iStack_70;
          iStack_30 = iStack_6c;
          iStack_2c = iStack_68;
          iStack_28 = iStack_64;
          FUN_005880a0(0);
        }
        else {
          iStack_6c = iStack_6c - *(int *)(in_ECX + 0xd4);
          iStack_70 = iStack_70 - *(int *)(in_ECX + 0xd0);
          iStack_64 = iStack_64 - *(int *)(in_ECX + 0xd4);
          iStack_28 = *(int *)(in_ECX + 0x9c);
          iStack_34 = iStack_70 - iStack_28;
          iStack_68 = iStack_68 - *(int *)(in_ECX + 0xd0);
          iStack_2c = iStack_68 + iStack_28;
          iStack_30 = iStack_6c - iStack_28;
          iStack_28 = iStack_64 + iStack_28;
          FUN_005880a0(1);
        }
      }
      else {
        if ((iVar6 == *(int *)(in_ECX + 0xd8)) && (iVar7 == *(int *)(in_ECX + 0xdc)))
        goto LAB_0056cffa;
        iStack_34 = iStack_70;
        iStack_2c = iStack_68;
        iStack_30 = iStack_6c;
        iStack_28 = iStack_64;
        FUN_005880a0(0);
      }
      piVar2 = (int *)(**(code **)(*(int *)*piVar8 + 0x3c))();
      (**(code **)(*piVar2 + 0xc))(auStack_78);
      piVar2 = (int *)(**(code **)(*(int *)piVar8[2] + 0x3c))();
      (**(code **)(*piVar2 + 0xc))(auStack_40);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      if (0xf < auStack_40[0]) {
        _free(pvStack_54);
        return;
      }
    }
LAB_0056d0ea:
    uStack_4 = 0xf;
    uStack_8 = 0;
    uStack_44 = 0;
    piVar8 = piVar8 + 4;
    auStack_40[0] = 0xf;
    pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
  } while( true );
}


// ==== FUN_0056d120 @ 0x0056d120 ====

undefined4 FUN_0056d120(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int *in_ECX;
  
  if ((char)in_ECX[0x11] != '\0') {
    return 0;
  }
  FUN_00401660(param_1,0,0xffffffff);
  piVar3 = (int *)(**(code **)(*DAT_00b5a7bc + 4))();
  in_ECX[0x10] = (int)piVar3;
  if (piVar3 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar3 + 4))(param_1 + 0x1c);
    if (cVar2 != '\0') {
      iVar1 = *(int *)in_ECX[0x10];
      uVar4 = (**(code **)(*(int *)in_ECX[1] + 4))();
      cVar2 = (**(code **)(iVar1 + 0x18))(uVar4);
      if (cVar2 != '\0') {
        *(undefined1 *)(in_ECX + 0x11) = 1;
        (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
        return 1;
      }
    }
    (**(code **)(*DAT_00b5a7bc + 8))(in_ECX[0x10]);
    in_ECX[0x10] = 0;
  }
  return 0;
}


// ==== FUN_0056d1e0 @ 0x0056d1e0 ====

void FUN_0056d1e0(void)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  int in_ECX;
  int *unaff_ESI;
  int *local_10c;
  int local_108;
  int local_100;
  int *piStack_f8;
  int local_f4;
  undefined1 uStack_f0;
  int iStack_e4;
  int iStack_dc;
  void *pvStack_cc;
  undefined4 uStack_bc;
  uint uStack_b8;
  undefined1 uStack_b4;
  int iStack_a8;
  int iStack_a0;
  void *pvStack_90;
  undefined1 auStack_84 [4];
  undefined4 uStack_80;
  uint uStack_7c;
  undefined1 uStack_78;
  int iStack_6c;
  int iStack_64;
  void *pvStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 auStack_3c [12];
  int iStack_30;
  int iStack_28;
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  if (*(int *)(in_ECX + 0x15c) != 0) {
    iVar8 = *(int *)(in_ECX + 0xa4);
    uVar2 = iVar8 - *(int *)(in_ECX + 0x70);
    local_f4 = iVar8;
    FUN_0055aac0(uVar2 & ((int)uVar2 < 1) - 1);
    iVar1 = *(int *)(*(int *)(in_ECX + 0x15c) + 0x88);
    piVar5 = *(int **)(in_ECX + 0x7c);
    if (0 < iVar8) {
      local_108 = -iVar1;
      local_10c = piVar5;
      do {
        local_100 = 0;
        if (0 < *(int *)(in_ECX + 0xa0)) {
          do {
            if ((((piVar5 == *(int **)(in_ECX + 0x80)) || ((int *)*piVar5 == (int *)0x0)) ||
                (piVar5[1] == 0)) || ((piVar5[2] == 0 || (piVar5[3] == 0)))) break;
            piVar3 = (int *)(**(code **)(*(int *)*piVar5 + 0x3c))();
            piVar4 = (int *)(**(code **)(*(int *)piVar5[1] + 0x3c))();
            piVar5 = (int *)(**(code **)(*(int *)piVar5[2] + 0x3c))();
            piStack_f8 = piVar5;
            piVar6 = (int *)(**(code **)(*(int *)local_10c[3] + 0x3c))();
            uVar7 = (**(code **)(*piVar3 + 0x10))();
            FUN_005041e0(uVar7);
            uVar7 = (**(code **)(*piVar4 + 0x10))();
            FUN_005041e0(uVar7);
            uVar7 = (**(code **)(*piVar5 + 0x10))();
            FUN_005041e0(uVar7);
            uVar7 = (**(code **)(*piVar6 + 0x10))();
            FUN_005041e0(uVar7);
            if ((local_108 + iVar1 < iVar1) ||
               (*(int *)(in_ECX + 0x70) + iVar1 <= local_108 + iVar1)) {
              auStack_3c[0] = 0;
              uStack_b4 = 0;
              uStack_f0 = 0;
              uStack_78 = 0;
            }
            else {
              iVar8 = *(int *)(in_ECX + 0xac) * local_108;
              iStack_28 = iStack_28 - iStack_30;
              iStack_30 = *(int *)(in_ECX + 0x98) + iVar8;
              iStack_28 = iStack_28 + iStack_30;
              iStack_a0 = iStack_a0 - iStack_a8;
              iStack_a8 = *(int *)(in_ECX + 0xb4) + iVar8;
              iStack_a0 = iStack_a8 + iStack_a0;
              iStack_dc = iStack_30 + (iStack_dc - iStack_e4);
              iStack_64 = iVar8 + (iStack_64 - iStack_6c);
              auStack_3c[0] = 1;
              uStack_b4 = 1;
              uStack_f0 = 1;
              uStack_78 = 1;
              piVar5 = piStack_f8;
              iStack_e4 = iStack_30;
              iStack_6c = iVar8;
            }
            (**(code **)(*piVar3 + 0xc))(auStack_3c);
            (**(code **)(*piVar4 + 0xc))(&uStack_b8);
            (**(code **)(*piVar5 + 0xc))(&piStack_f8);
            (**(code **)(*unaff_ESI + 0xc))(auStack_84);
            piVar5 = local_10c + 4;
            if (0xf < uStack_40) {
              _free(pvStack_54);
              return;
            }
            uStack_40 = 0xf;
            uStack_44 = 0;
            pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
            if (0xf < uStack_b8) {
              _free(pvStack_cc);
              return;
            }
            uStack_b8 = 0xf;
            uStack_bc = 0;
            pvStack_cc = (void *)((uint)pvStack_cc & 0xffffff00);
            if (0xf < uStack_7c) {
              _free(pvStack_90);
              return;
            }
            uStack_7c = 0xf;
            uStack_80 = 0;
            pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
            if (0xf < uStack_4) {
              _free(pvStack_18);
              return;
            }
            local_100 = local_100 + 1;
            uStack_4 = 0xf;
            uStack_8 = 0;
            pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
            local_10c = piVar5;
          } while (local_100 < *(int *)(in_ECX + 0xa0));
        }
        local_108 = local_108 + 1;
      } while (local_108 + iVar1 < local_f4);
    }
  }
  return;
}


// ==== FUN_0056d520 @ 0x0056d520 ====

void FUN_0056d520(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar4 = *(undefined4 **)(in_ECX + 0x7c);
  if (puVar4 != *(undefined4 **)(in_ECX + 0x80)) {
    do {
      piVar1 = (int *)(**(code **)(*(int *)*puVar4 + 0x3c))();
      iVar2 = (**(code **)(*piVar1 + 0x3c))();
      if (iVar2 != 0) {
        piVar3 = (int *)(**(code **)(*piVar1 + 0x3c))();
        (**(code **)(*piVar3 + 0x7c))(piVar1);
      }
      piVar1 = (int *)(**(code **)(*(int *)puVar4[1] + 0x3c))();
      iVar2 = (**(code **)(*piVar1 + 0x3c))();
      if (iVar2 != 0) {
        piVar3 = (int *)(**(code **)(*piVar1 + 0x3c))();
        (**(code **)(*piVar3 + 0x7c))(piVar1);
      }
      piVar1 = (int *)(**(code **)(*(int *)puVar4[2] + 0x3c))();
      iVar2 = (**(code **)(*piVar1 + 0x3c))();
      if (iVar2 != 0) {
        piVar3 = (int *)(**(code **)(*piVar1 + 0x3c))();
        (**(code **)(*piVar3 + 0x7c))(piVar1);
      }
      piVar1 = (int *)(**(code **)(*(int *)puVar4[3] + 0x3c))();
      iVar2 = (**(code **)(*piVar1 + 0x3c))();
      if (iVar2 != 0) {
        piVar3 = (int *)(**(code **)(*piVar1 + 0x3c))();
        (**(code **)(*piVar3 + 0x7c))(piVar1);
      }
      puVar4 = puVar4 + 4;
    } while (puVar4 != *(undefined4 **)(in_ECX + 0x80));
  }
  if (*(void **)(in_ECX + 0x7c) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x7c) = 0;
    *(undefined4 *)(in_ECX + 0x80) = 0;
    *(undefined4 *)(in_ECX + 0x84) = 0;
                    /* WARNING: Could not recover jumptable at 0x0056d5fb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 4) + 0x20))();
    return;
  }
  _free(*(void **)(in_ECX + 0x7c));
  return;
}


// ==== FUN_0056d600 @ 0x0056d600 ====

void FUN_0056d600(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  int unaff_retaddr;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_lbl_listcontent_009bd054,0xf);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x4c))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    *(undefined4 *)(unaff_retaddr + 0x194) = *(undefined4 *)(iVar2 + 0x7c);
    *(undefined4 *)(unaff_retaddr + 0x198) = *(undefined4 *)(iVar2 + 0x80);
    *(undefined4 *)(unaff_retaddr + 0x19c) = *(undefined4 *)(iVar2 + 0x84);
    *(undefined4 *)(unaff_retaddr + 0x1a0) = *(undefined4 *)(iVar2 + 0x88);
  }
  return;
}


// ==== FUN_0056d6a0 @ 0x0056d6a0 ====

void FUN_0056d6a0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  void *apvStack_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar2 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__scroll_009bcff8);
  FUN_00402220(apvStack_1c,uVar2);
  piVar1 = (int *)(**(code **)(*piVar1 + 0x4c))(apvStack_1c);
  if (0xf < uStack_8) {
    _free(apvStack_1c[0]);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x30))
                      (0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                       &Framework::UI::Control::VScroll::RTTI_Type_Descriptor,0);
    iVar3 = FUN_00803725(uVar2);
    in_ECX[0x57] = iVar3;
  }
  return;
}


// ==== FUN_0056d730 @ 0x0056d730 ====

undefined4 FUN_0056d730(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 extraout_EAX;
  int *in_ECX;
  void *apvStack_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  iVar1 = param_1;
  iVar4 = *(int *)(param_1 + 0xc);
  iVar3 = (**(code **)(*piVar2 + 4))();
  if (iVar4 != iVar3) {
    param_1 = iVar4;
    piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
    iVar4 = (**(code **)(*piVar2 + 0x48))(&param_1);
    if (iVar4 == 0) {
      return 0;
    }
  }
  piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  if (piVar2 != (int *)0x0) {
    uVar5 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__scroll_009bcff8);
    FUN_00402220(apvStack_1c,uVar5);
    piVar2 = (int *)(**(code **)(*piVar2 + 0x4c))(apvStack_1c);
    if (0xf < uStack_8) {
      _free(apvStack_1c[0]);
      return extraout_EAX;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
    if (piVar2 != (int *)0x0) {
      uVar5 = (**(code **)(*piVar2 + 0x30))();
      iVar4 = FUN_00803725(uVar5,0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                           &Framework::UI::Control::VScroll::RTTI_Type_Descriptor,0);
      if (iVar4 != 0) {
        if (0 < *(short *)(iVar1 + 4)) {
          FUN_0055aa00();
          return 1;
        }
        if (*(short *)(iVar1 + 4) < 0) {
          FUN_0055aa60();
        }
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_0056d830 @ 0x0056d830 ====

undefined4 FUN_0056d830(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x40) != 0) &&
     (cVar1 = (**(code **)(**(int **)(in_ECX + 0x40) + 0x10))(param_1), cVar1 != '\0')) {
    return 1;
  }
  iVar2 = (**(code **)(*param_1 + 4))();
  if ((iVar2 == 0x10010) && (cVar1 = FUN_0056d730(param_1), cVar1 != '\0')) {
    return 1;
  }
  return 0;
}


// ==== FUN_0056d880 @ 0x0056d880 ====

void FUN_0056d880(void)

{
  undefined4 *in_ECX;
  
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009bd094;
  in_ECX[0x1c] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  FUN_00505280();
  in_ECX[0x54] = 0;
  in_ECX[0x55] = 0;
  in_ECX[0x56] = 0;
  in_ECX[0x57] = 0;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  FUN_0056a730();
  return;
}


// ==== FUN_0056d910 @ 0x0056d910 ====

void FUN_0056d910(void)

{
  undefined4 *in_ECX;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_009bd094;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    if ((void *)in_ECX[0x1f] != (void *)0x0) {
      _free((void *)in_ECX[0x1f]);
      return;
    }
    in_ECX[0x1f] = 0;
    in_ECX[0x20] = 0;
    in_ECX[0x21] = 0;
    if (*(char *)(in_ECX + 0x11) == '\0') {
      FUN_0044a580(local_100,&DAT_009bd084,s_VScroll_Close_Fail_009bcfd4);
      FUN_00797b80(local_100);
    }
    else {
      *(undefined1 *)(in_ECX + 0x11) = 0;
      if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)in_ECX[0x10])(1);
      }
      in_ECX[0x10] = 0;
    }
  }
  FUN_00505310();
  if ((void *)in_ECX[0x23] != (void *)0x0) {
    _free((void *)in_ECX[0x23]);
    return;
  }
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  if ((void *)in_ECX[0x1f] == (void *)0x0) {
    in_ECX[0x1f] = 0;
    in_ECX[0x20] = 0;
    in_ECX[0x21] = 0;
    FUN_00552170();
    return;
  }
  _free((void *)in_ECX[0x1f]);
  return;
}


// ==== FUN_0056d9e0 @ 0x0056d9e0 ====

void FUN_0056d9e0(int param_1)

{
  int iVar1;
  int *in_ECX;
  int *local_4;
  
  local_4 = in_ECX;
  FUN_0056f250(param_1 + 0x3b0);
  param_1 = 0;
  FUN_00558e00(&local_4,&param_1);
  if (local_4 != (int *)in_ECX[0x3f]) {
    in_ECX[0x54] = local_4[4];
    in_ECX[0x55] = local_4[5];
    in_ECX[0x56] = local_4[6];
  }
  iVar1 = (**(code **)(*(int *)in_ECX[1] + 0x14))();
  in_ECX[0x1c] = ((in_ECX[0x26] * -2 - *(int *)(iVar1 + 0xc)) + *(int *)(iVar1 + 0x14)) /
                 in_ECX[0x2a];
  (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  return;
}


// ==== FUN_0056da80 @ 0x0056da80 ====

void FUN_0056da80(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *in_ECX;
  undefined1 uStack00000000;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_listcontent_009bd064,0xf);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x4c))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    *(undefined1 *)(_uStack00000000 + 0x45) = *(undefined1 *)(iVar2 + 0x7c);
    *(undefined1 *)((int)_uStack00000000 + 0x115) = *(undefined1 *)(iVar2 + 0x7d);
    if (_uStack00000000 + 0x46 != (undefined4 *)(iVar2 + 0x80)) {
      FUN_00504490(&uStack00000000,*(undefined4 *)_uStack00000000[0x47],
                   (undefined4 *)_uStack00000000[0x47]);
      FUN_005040e0((undefined4 *)(iVar2 + 0x80));
    }
    puVar3 = (undefined4 *)FUN_0056f1d0(&uStack00000000);
    *_uStack00000000 = *puVar3;
    _uStack00000000[1] = puVar3[1];
    _uStack00000000[2] = puVar3[2];
  }
  return;
}


// ==== FUN_0056db60 @ 0x0056db60 ====

void FUN_0056db60(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *in_ECX;
  undefined1 uStack00000000;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_listdeco_009bd074,0xc);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x4c))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    *(undefined1 *)(_uStack00000000 + 0x45) = *(undefined1 *)(iVar2 + 0x7c);
    *(undefined1 *)((int)_uStack00000000 + 0x115) = *(undefined1 *)(iVar2 + 0x7d);
    if (_uStack00000000 + 0x46 != (undefined4 *)(iVar2 + 0x80)) {
      FUN_00504490(&uStack00000000,*(undefined4 *)_uStack00000000[0x47],
                   (undefined4 *)_uStack00000000[0x47]);
      FUN_005040e0((undefined4 *)(iVar2 + 0x80));
    }
    puVar3 = (undefined4 *)FUN_0056f1d0(&uStack00000000);
    *_uStack00000000 = *puVar3;
    _uStack00000000[1] = puVar3[1];
    _uStack00000000[2] = puVar3[2];
  }
  return;
}


// ==== FUN_0056dc40 @ 0x0056dc40 ====

undefined4 FUN_0056dc40(int param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 ****ppppuVar3;
  int iVar4;
  undefined4 extraout_EAX;
  int in_ECX;
  bool bVar5;
  undefined1 auStack_38 [4];
  undefined4 ****local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_24;
  uint local_20;
  undefined1 auStack_1c [28];
  
  bVar5 = false;
  if (param_1 == 4) {
    bVar5 = true;
    uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__scroll_009bcff8);
    FUN_00402220(auStack_38,uVar2);
    ppppuVar3 = local_34;
    if (local_20 < 0x10) {
      ppppuVar3 = &local_34;
    }
    iVar4 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),ppppuVar3,uStack_24);
    if ((iVar4 == 0) && (bVar1 = true, param_3 == 6)) goto LAB_0056dcb3;
  }
  bVar1 = false;
LAB_0056dcb3:
  if ((bVar5) && (0xf < local_20)) {
    _free(local_34);
    return extraout_EAX;
  }
  if (bVar1) {
    FUN_0056d1e0();
    return 1;
  }
  if (param_1 == 1) {
    if (param_3 == 1) {
      local_34 = (undefined4 ****)0x0;
      uStack_30 = 0;
      uStack_2c = 0;
      FUN_00401830(&DAT_009bcfe8);
      FUN_00405300(param_2,auStack_1c,auStack_38);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    if (param_3 == 4) {
      FUN_0056ce00(param_2,*(undefined4 *)(in_ECX + 0xe0),*(undefined4 *)(in_ECX + 0xe4));
      return 1;
    }
    if (param_3 == 5) {
      FUN_0056ce00(param_2,*(undefined4 *)(in_ECX + 0xd8),*(undefined4 *)(in_ECX + 0xdc));
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0056de10 @ 0x0056de10 ====

int * FUN_0056de10(void)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  int *extraout_EAX;
  undefined4 *puVar7;
  int *extraout_EAX_00;
  int *extraout_EAX_01;
  int *extraout_EAX_02;
  int *extraout_EAX_03;
  int in_ECX;
  char *pcVar8;
  int *unaff_EBX;
  int unaff_retaddr;
  undefined1 uStack_b8;
  undefined1 uStack_b7;
  undefined1 uStack_b6;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  void *pvStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  uint uStack_98;
  undefined1 uStack_94;
  void *pvStack_90;
  undefined4 uStack_84;
  undefined4 uStack_80;
  uint uStack_7c;
  undefined1 uStack_78;
  undefined4 uStack_68;
  undefined4 uStack_64;
  void *pvStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  uint uStack_8;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  (**(code **)(*DAT_00b5a7ac + 8))(8);
  uStack_b6 = 1;
  uStack_b4 = 0;
  uStack_b0 = 0;
  pvStack_ac = (void *)0x0;
  uStack_a8 = 0;
  uStack_a4 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  uStack_80 = 0xf;
  uStack_84 = 0;
  uStack_94 = 0;
  uStack_64 = 0xf;
  uStack_68 = 0;
  uStack_78 = 0;
  pvStack_60 = (void *)0x0;
  uStack_5c = 0;
  uStack_58 = 0;
  pvVar4 = operator_new(0x468);
  if (pvVar4 == (void *)0x0) {
    pvVar4 = (void *)0x0;
  }
  else {
    pvVar4 = (void *)FUN_00505f10();
  }
  *(undefined4 *)((int)pvVar4 + 0x19c) = 5;
  *(undefined4 *)((int)pvVar4 + 0x198) = 5;
  *(undefined1 *)((int)pvVar4 + 0x194) = 0;
  *(undefined1 *)((int)pvVar4 + 0x195) = 0;
  *(undefined1 *)((int)pvVar4 + 0x196) = 0;
  *(undefined4 *)((int)pvVar4 + 0x1a0) = 0xc;
  FUN_0056d600(pvVar4);
  FUN_00504250(in_ECX + 0x11c);
  FUN_00401660(unaff_retaddr + 4,0,0xffffffff);
  FUN_00401740(s_lbl_listcontent__x_009bd010,0x12);
  iVar5 = FUN_00404230(auStack_20);
  if (*(uint *)(iVar5 + 0x18) < 0x10) {
    pcVar8 = (char *)(iVar5 + 4);
  }
  else {
    pcVar8 = *(char **)(iVar5 + 4);
  }
  pcVar6 = pcVar8;
  do {
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  FUN_00401740(pcVar8,(int)pcVar6 - (int)(pcVar8 + 1));
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return extraout_EAX;
  }
  FUN_00401660(&uStack_7c,0,0xffffffff);
  puVar7 = (undefined4 *)FUN_0056cba0(auStack_20,unaff_EBX);
  uStack_b0 = *puVar7;
  pvStack_ac = (void *)puVar7[1];
  uStack_a8 = puVar7[2];
  uStack_a4 = puVar7[3];
  uStack_b4 = 0x32;
  uStack_b8 = 1;
  uStack_b7 = 1;
  (**(code **)(*piVar3 + 8))(&uStack_b8);
  piVar1 = *(int **)(in_ECX + 4);
  if ((piVar1 != (int *)0x0) && (cVar2 = (**(code **)(*piVar3 + 0x74))(piVar1), cVar2 != '\0')) {
    cVar2 = (**(code **)(*piVar1 + 0x78))(piVar3);
    if (cVar2 == '\0') {
      (**(code **)(*piVar3 + 0x74))(0);
    }
    else {
      iVar5 = (**(code **)(*piVar1 + 0x38))();
      piVar3[1] = iVar5;
    }
  }
  (**(code **)(*unaff_EBX + 0x38))(piVar3);
  (**(code **)(*unaff_EBX + 0x1c))(&uStack_84);
  (**(code **)(*unaff_EBX + 0x24))(pvVar4);
  (**(code **)(*unaff_EBX + 8))(&uStack_64);
  (**(code **)(*piVar3 + 0x2c))(unaff_EBX);
  if (pvVar4 != (void *)0x0) {
    FUN_00505d80();
    _free(pvVar4);
    return extraout_EAX_00;
  }
  if (0xf < uStack_4c) {
    _free(pvStack_60);
    return extraout_EAX_01;
  }
  uStack_4c = 0xf;
  uStack_50 = 0;
  pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
  if (0xf < uStack_7c) {
    _free(pvStack_90);
    return extraout_EAX_02;
  }
  uStack_7c = 0xf;
  uStack_80 = 0;
  pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
  if (uStack_98 < 0x10) {
    return unaff_EBX;
  }
  _free(pvStack_ac);
  return extraout_EAX_03;
}


// ==== FUN_0056e100 @ 0x0056e100 ====

int * FUN_0056e100(void)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  void *pvVar5;
  int iVar6;
  char *pcVar7;
  int *extraout_EAX;
  int *extraout_EAX_00;
  int *extraout_EAX_01;
  int *extraout_EAX_02;
  int *extraout_EAX_03;
  int in_ECX;
  char *pcVar8;
  undefined4 unaff_EBX;
  int local_c0;
  undefined1 uStack_b8;
  undefined1 uStack_b7;
  undefined1 uStack_b6;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  void *pvStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  uint uStack_98;
  undefined1 uStack_94;
  void *pvStack_90;
  undefined4 uStack_84;
  undefined4 uStack_80;
  uint uStack_7c;
  undefined1 uStack_78;
  undefined4 uStack_68;
  undefined4 uStack_64;
  void *pvStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined1 uStack_48;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined4 uStack_20;
  void *pvStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  uint uStack_8;
  
  if (*(int *)(in_ECX + 0x7c) == 0) {
    local_c0 = 0;
  }
  else {
    local_c0 = *(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c) >> 4;
  }
  piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  (**(code **)(*DAT_00b5a7ac + 8))(0);
  uStack_b6 = 1;
  uStack_b4 = 0;
  uStack_b0 = 0;
  pvStack_ac = (void *)0x0;
  uStack_a8 = 0;
  uStack_a4 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  uStack_80 = 0xf;
  uStack_84 = 0;
  uStack_94 = 0;
  uStack_64 = 0xf;
  uStack_68 = 0;
  uStack_78 = 0;
  pvStack_60 = (void *)0x0;
  uStack_5c = 0;
  uStack_58 = 0;
  pvVar5 = operator_new(0x468);
  if (pvVar5 == (void *)0x0) {
    pvVar5 = (void *)0x0;
  }
  else {
    pvVar5 = (void *)FUN_00505f10();
  }
  FUN_00503950(*(undefined4 *)(*(int *)((int)pvVar5 + 0x11c) + 4));
  *(int *)(*(int *)((int)pvVar5 + 0x11c) + 4) = *(int *)((int)pvVar5 + 0x11c);
  *(undefined4 *)((int)pvVar5 + 0x120) = 0;
  *(undefined4 *)*(undefined4 *)((int)pvVar5 + 0x11c) = *(undefined4 *)((int)pvVar5 + 0x11c);
  *(int *)(*(int *)((int)pvVar5 + 0x11c) + 8) = *(int *)((int)pvVar5 + 0x11c);
  *(undefined1 *)((int)pvVar5 + 0x114) = 0;
  *(undefined1 *)((int)pvVar5 + 0x115) = 0;
  FUN_0056da80(pvVar5);
  uStack_30 = 1;
  uStack_28 = 1;
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_34 = 0xf;
  uStack_38 = 0;
  uStack_48 = 0;
  uStack_2c = 0;
  uStack_24 = 0;
  uStack_23 = 0;
  FUN_00401740(s_pan_listcontent__x_009bd024,0x12);
  iVar6 = FUN_00404230(&uStack_20);
  if (*(uint *)(iVar6 + 0x18) < 0x10) {
    pcVar8 = (char *)(iVar6 + 4);
  }
  else {
    pcVar8 = *(char **)(iVar6 + 4);
  }
  piVar1 = (int *)(pcVar8 + 1);
  pcVar7 = pcVar8;
  do {
    cVar3 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar3 != '\0');
  FUN_00401740(pcVar8,(int)pcVar7 - (int)piVar1);
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return extraout_EAX;
  }
  FUN_00401660(&uStack_7c,0,0xffffffff);
  FUN_0056cb30(&uStack_20,unaff_EBX);
  uStack_b0 = uStack_20;
  uStack_a4 = uStack_14;
  pvStack_ac = pvStack_1c;
  uStack_a8 = uStack_18;
  uStack_b4 = 10;
  uStack_b8 = 1;
  uStack_b7 = 1;
  (**(code **)(*piVar4 + 8))(&uStack_b8);
  piVar2 = *(int **)(local_c0 + 4);
  if (piVar2 != (int *)0x0) {
    cVar3 = (**(code **)(*piVar4 + 0x74))(piVar2);
    if (cVar3 != '\0') {
      cVar3 = (**(code **)(*piVar2 + 0x78))(piVar4);
      if (cVar3 == '\0') {
        (**(code **)(*piVar4 + 0x74))(0);
      }
      else {
        iVar6 = (**(code **)(*piVar2 + 0x38))();
        piVar4[1] = iVar6;
      }
    }
  }
  (**(code **)(*piVar1 + 0x38))(piVar4);
  (**(code **)(*piVar1 + 0x1c))(&uStack_84);
  (**(code **)(*piVar1 + 8))(&pvStack_60);
  (**(code **)(*piVar4 + 0x2c))(piVar1);
  (**(code **)(*piVar1 + 0x24))(pvVar5);
  if (pvVar5 != (void *)0x0) {
    FUN_00505d80();
    _free(pvVar5);
    return extraout_EAX_00;
  }
  if (0xf < uStack_4c) {
    _free(pvStack_60);
    return extraout_EAX_01;
  }
  uStack_4c = 0xf;
  uStack_50 = 0;
  pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
  if (0xf < uStack_7c) {
    _free(pvStack_90);
    return extraout_EAX_02;
  }
  uStack_7c = 0xf;
  uStack_80 = 0;
  pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
  if (uStack_98 < 0x10) {
    return piVar1;
  }
  _free(pvStack_ac);
  return extraout_EAX_03;
}


// ==== FUN_0056e430 @ 0x0056e430 ====

void FUN_0056e430(void)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  void *pvVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined4 unaff_EBX;
  int unaff_retaddr;
  undefined4 local_c4;
  int iStack_c0;
  undefined1 uStack_b8;
  undefined1 uStack_b7;
  undefined1 uStack_b6;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined1 uStack_94;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined1 auStack_7c [4];
  undefined1 uStack_78;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 uStack_48;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  uint uStack_8;
  
  piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  (**(code **)(*DAT_00b5a7ac + 8))(0);
  uStack_80 = 0xf;
  uStack_64 = 0xf;
  uStack_b6 = 1;
  uStack_b4 = 0;
  uStack_b0 = 0;
  uStack_ac = 0;
  uStack_a8 = 0;
  uStack_a4 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  uStack_84 = 0;
  uStack_94 = 0;
  uStack_68 = 0;
  uStack_78 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  if (*(char *)(unaff_retaddr + 0x22) == '\x01') {
    local_c4 = 0x12;
  }
  else if (*(char *)(unaff_retaddr + 0x22) == '\x02') {
    local_c4 = 0x13;
  }
  else {
    local_c4 = 0x15;
  }
  pvVar5 = operator_new(0x468);
  if (pvVar5 == (void *)0x0) {
    pvVar5 = (void *)0x0;
  }
  else {
    pvVar5 = (void *)FUN_00505f10();
  }
  FUN_00503950(*(undefined4 *)(*(int *)((int)pvVar5 + 0x11c) + 4));
  *(int *)(*(int *)((int)pvVar5 + 0x11c) + 4) = *(int *)((int)pvVar5 + 0x11c);
  *(undefined4 *)((int)pvVar5 + 0x120) = 0;
  *(undefined4 *)*(undefined4 *)((int)pvVar5 + 0x11c) = *(undefined4 *)((int)pvVar5 + 0x11c);
  *(int *)(*(int *)((int)pvVar5 + 0x11c) + 8) = *(int *)((int)pvVar5 + 0x11c);
  *(undefined1 *)((int)pvVar5 + 0x114) = 0;
  *(undefined1 *)((int)pvVar5 + 0x115) = 0;
  FUN_0056db60(pvVar5);
  *(undefined4 *)((int)pvVar5 + 8) = local_c4;
  uStack_30 = 1;
  uStack_28 = 1;
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_34 = 0xf;
  uStack_38 = 0;
  uStack_48 = 0;
  uStack_2c = 0;
  uStack_24 = 0;
  uStack_23 = 0;
  FUN_00401740(s_pan_listdeco__x_009bd038,0xf);
  iVar6 = FUN_00404230(auStack_20);
  if (*(uint *)(iVar6 + 0x18) < 0x10) {
    pcVar9 = (char *)(iVar6 + 4);
  }
  else {
    pcVar9 = *(char **)(iVar6 + 4);
  }
  piVar1 = (int *)(pcVar9 + 1);
  pcVar7 = pcVar9;
  do {
    cVar3 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar3 != '\0');
  FUN_00401740(pcVar9,(int)pcVar7 - (int)piVar1);
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return;
  }
  FUN_00401660(auStack_7c,0,0xffffffff);
  puVar8 = (undefined4 *)FUN_0056cc20(auStack_20,unaff_EBX);
  uStack_b0 = *puVar8;
  uStack_ac = puVar8[1];
  uStack_a8 = puVar8[2];
  uStack_a4 = puVar8[3];
  uStack_b4 = 100;
  uStack_b8 = 1;
  uStack_b7 = 1;
  (**(code **)(*piVar4 + 8))(&uStack_b8);
  piVar2 = *(int **)(iStack_c0 + 4);
  if ((piVar2 != (int *)0x0) && (cVar3 = (**(code **)(*piVar4 + 0x74))(piVar2), cVar3 != '\0')) {
    cVar3 = (**(code **)(*piVar2 + 0x78))(piVar4);
    if (cVar3 == '\0') {
      (**(code **)(*piVar4 + 0x74))(0);
    }
    else {
      iVar6 = (**(code **)(*piVar2 + 0x38))();
      piVar4[1] = iVar6;
    }
  }
  (**(code **)(*piVar1 + 0x38))(piVar4);
  (**(code **)(*piVar1 + 0x1c))(&uStack_84);
  (**(code **)(*piVar1 + 8))(&uStack_60);
  (**(code **)(*piVar4 + 0x2c))(piVar1);
  (**(code **)(*piVar1 + 0x24))(pvVar5);
  FUN_00505d80();
  _free(pvVar5);
  return;
}


// ==== FUN_0056e780 @ 0x0056e780 ====

void FUN_0056e780(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_listcontent_009bd048,0xb);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x4c))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    FUN_00505cc0(iVar2 + 200);
  }
  return;
}


// ==== FUN_0056e810 @ 0x0056e810 ====

void FUN_0056e810(void)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  void *pvVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int in_ECX;
  char *pcVar10;
  int unaff_EBX;
  int *unaff_ESI;
  undefined4 *unaff_retaddr;
  int local_c8;
  undefined4 local_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined1 uStack_a0;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined1 auStack_88 [4];
  undefined1 uStack_84;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  char *apcStack_60 [2];
  undefined4 uStack_58;
  undefined4 uStack_54;
  void *pvStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_44 [8];
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined1 uStack_2c;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  if (*(int *)(in_ECX + 0x7c) == 0) {
    local_c8 = 0;
  }
  else {
    local_c8 = *(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c) >> 4;
  }
  local_c4 = in_ECX;
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 8))(1);
  local_c4._0_3_ = CONCAT12(1,(undefined2)local_c4);
  uStack_c0 = 0;
  uStack_bc = 0;
  uStack_b8 = 0;
  uStack_b4 = 0;
  uStack_b0 = 0;
  uStack_ac = 0;
  uStack_a8 = 0;
  uStack_8c = 0xf;
  uStack_90 = 0;
  uStack_a0 = 0;
  uStack_70 = 0xf;
  uStack_74 = 0;
  uStack_84 = 0;
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  pvVar5 = operator_new(0x468);
  if (pvVar5 == (void *)0x0) {
    pvVar5 = (void *)0x0;
  }
  else {
    pvVar5 = (void *)FUN_00505f10();
  }
  *(undefined1 *)((int)pvVar5 + 0x104) = 0;
  *(undefined1 *)((int)pvVar5 + 0x105) = 0;
  *(undefined1 *)((int)pvVar5 + 0x107) = 0;
  *(undefined1 *)((int)pvVar5 + 0x10c) = 0;
  *(undefined4 *)((int)pvVar5 + 0x108) = 0xc;
  *(undefined4 *)((int)pvVar5 + 0x110) = 500;
  *(undefined1 *)((int)pvVar5 + 0x106) = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_18 = 0xf;
  uStack_1c = 0;
  uStack_2c = 0;
  uStack_14 = 1;
  iStack_10 = 0;
  uStack_c = 1;
  uStack_8 = 0;
  uStack_7 = 0;
  FUN_0056e780(pvVar5);
  pvStack_50 = *(void **)(local_c8 + 0x104);
  uStack_4c = *(undefined4 *)(local_c8 + 0x108);
  uStack_58 = *(undefined4 *)(local_c8 + 0x10c);
  uStack_48 = *unaff_retaddr;
  uStack_54 = 0;
  FUN_0056ac60(apcStack_60,&uStack_54);
  *(undefined1 *)((int)pvVar5 + 0xc) = 1;
  FUN_00401740(s_listcontent__d_009bd000,0xe);
  iVar6 = FUN_00404230(&uStack_54);
  if (*(uint *)(iVar6 + 0x18) < 0x10) {
    pcVar10 = (char *)(iVar6 + 4);
  }
  else {
    pcVar10 = *(char **)(iVar6 + 4);
  }
  apcStack_60[0] = pcVar10 + 1;
  pcVar7 = pcVar10;
  do {
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  FUN_00401740(pcVar10,(int)pcVar7 - (int)apcStack_60[0]);
  if (0xf < uStack_3c) {
    _free(pvStack_50);
    return;
  }
  FUN_00401660(auStack_88,0,0xffffffff);
  puVar8 = (undefined4 *)FUN_0056cb30(&uStack_54,unaff_EBX);
  uStack_bc = *puVar8;
  uStack_b8 = puVar8[1];
  uStack_b4 = puVar8[2];
  uStack_b0 = puVar8[3];
  uStack_c0 = 0x32;
  local_c4 = CONCAT22(local_c4._2_2_,0x101);
  (**(code **)(*piVar3 + 8))(&local_c4);
  piVar1 = *(int **)(unaff_EBX + 4);
  if (piVar1 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar3 + 0x74))(piVar1);
    if (cVar2 != '\0') {
      cVar2 = (**(code **)(*piVar1 + 0x78))(piVar3);
      if (cVar2 == '\0') {
        (**(code **)(*piVar3 + 0x74))(0);
      }
      else {
        iVar6 = (**(code **)(*unaff_ESI + 0x38))();
        piVar3[1] = iVar6;
      }
    }
  }
  (**(code **)(*piVar4 + 0x38))(piVar3);
  (**(code **)(*piVar4 + 0x1c))(&uStack_90);
  (**(code **)(*piVar4 + 8))(auStack_44);
  uVar9 = (**(code **)(*DAT_00b5a794 + 0xc))(0,*(ushort *)(iStack_10 + 0x20) | 0x38e0000);
  FUN_00401660(uVar9,0,0xffffffff);
  (**(code **)(*piVar3 + 0x2c))(piVar4);
  (**(code **)(*piVar4 + 0x24))(pvVar5);
  FUN_00505d80();
  _free(pvVar5);
  return;
}


// ==== FUN_0056ebb0 @ 0x0056ebb0 ====

void FUN_0056ebb0(undefined4 param_1)

{
  undefined1 auStack_e [14];
  
  FUN_0056e810(param_1);
  FUN_0056de10(param_1);
  FUN_0056e100(param_1);
  FUN_0056e430(param_1);
  FUN_0056f3b0(auStack_e + -10);
  return;
}


// ==== FUN_0056ec00 @ 0x0056ec00 ====

void FUN_0056ec00(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_4;
  
  FUN_0056d520();
  iVar1 = *(int *)(param_1 + 8);
  iVar3 = *(int *)(param_1 + 4);
  if (iVar3 != iVar1) {
    do {
      FUN_0056e810(iVar3);
      uStack_10 = FUN_0056de10(iVar3);
      uStack_c = FUN_0056e100(iVar3);
      uStack_4 = FUN_0056e430(iVar3);
      iVar2 = *(int *)(in_ECX + 0x7c);
      if ((iVar2 == 0) ||
         ((uint)(*(int *)(in_ECX + 0x84) - iVar2 >> 4) <=
          (uint)(*(int *)(in_ECX + 0x80) - iVar2 >> 4))) {
        FUN_0056ef70(*(undefined4 *)(in_ECX + 0x80),1,&uStack_10);
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x80);
        FUN_0056ed40(iVar2,1,&uStack_10,in_ECX + 0x78,iVar1);
        *(int *)(in_ECX + 0x80) = iVar2 + 0x10;
      }
      iVar3 = iVar3 + 0x24;
    } while (iVar3 != iVar1);
  }
  FUN_0056d1e0();
  return;
}


// ==== FUN_0056ecd0 @ 0x0056ecd0 ====

int FUN_0056ecd0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982010;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x10) {
    FUN_00680ae0(param_3,param_1);
    param_3 = param_3 + 0x10;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0056ed36 @ 0x0056ed36 ====

void Catch_0056ed36(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0056ed40 @ 0x0056ed40 ====

void FUN_0056ed40(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982020;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_00680ae0(param_1,param_3);
    param_1 = param_1 + 0x10;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0056eda6 @ 0x0056eda6 ====

void Catch_0056eda6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0056edb0 @ 0x0056edb0 ====

void FUN_0056edb0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0056ecd0(param_1,param_2,param_3);
  return;
}


// ==== FUN_0056edd0 @ 0x0056edd0 ====

int FUN_0056edd0(int param_1,int param_2,undefined4 param_3)

{
  FUN_0056ed40(param_1,param_2,param_3);
  return param_2 * 0x10 + param_1;
}


// ==== FUN_0056ee00 @ 0x0056ee00 ====

undefined4 * FUN_0056ee00(undefined4 *param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 local_8 [8];
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_0056a8a0(param_1,1,*(undefined4 *)(in_ECX + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    if (*param_3 < (uint)param_2[3]) {
      FUN_0056a8a0(param_1,1,param_2,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    if (*(uint *)(piVar1[2] + 0xc) < *param_3) {
      FUN_0056a8a0(param_1,0,piVar1[2],param_3);
      return param_1;
    }
  }
  else {
    uVar2 = *param_3;
    uVar3 = param_2[3];
    if (uVar2 < uVar3) {
      FUN_0046a3c0();
      if ((uint)param_2[3] < uVar2) {
        if (*(char *)(param_2[2] + 0x1d) == '\0') {
          FUN_0056a8a0(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_0056a8a0(param_1,0,param_2,param_3);
        return param_1;
      }
      uVar3 = param_2[3];
    }
    if (uVar3 < uVar2) {
      FUN_005038e0();
      if ((param_2 == *(int **)(in_ECX + 4)) || (uVar2 < (uint)param_2[3])) {
        if (*(char *)(param_2[2] + 0x1d) == '\0') {
          FUN_0056a8a0(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_0056a8a0(param_1,0,param_2,param_3);
        return param_1;
      }
    }
  }
  puVar4 = (undefined4 *)FUN_0056ac60(local_8,param_3);
  *param_1 = *puVar4;
  return param_1;
}


// ==== FUN_0056ef70 @ 0x0056ef70 ====

void FUN_0056ef70(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  undefined8 uVar6;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
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
  puStack_c = &LAB_00982030;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x50);
  local_44 = *param_3;
  local_40 = param_3[1];
  local_3c = param_3[2];
  local_38 = param_3[3];
  iVar5 = *(int *)(in_ECX + 4);
  if (iVar5 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(in_ECX + 0xc) - iVar5 >> 4;
  }
  uVar6 = CONCAT44(iVar5,iVar2);
  if (param_2 != 0) {
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 8) - iVar5 >> 4;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x50);
    if (0xfffffffU - iVar5 < param_2) {
      ExceptionList = &local_10;
      uVar6 = FUN_0085b3b0();
      puVar1 = local_14;
    }
    local_14 = puVar1;
    iVar5 = (int)((ulonglong)uVar6 >> 0x20);
    local_20 = (uint)uVar6;
    if (iVar5 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar5 >> 4;
    }
    if (local_20 < iVar2 + param_2) {
      if (0xfffffff - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar5 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(in_ECX + 8) - iVar5 >> 4;
      }
      if (local_20 < iVar2 + param_2) {
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(in_ECX + 8) - iVar5 >> 4;
        }
        local_20 = iVar5 + param_2;
      }
      local_20 = local_20 << 4;
      pvVar3 = operator_new(local_20);
      local_8 = 0;
      local_24 = pvVar3;
      local_1c = FUN_0056edb0(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      local_1c = FUN_0056edd0(local_1c,param_2,&local_44);
      FUN_0056edb0(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - (int)_Memory >> 4;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)pvVar3;
        *(void **)(in_ECX + 8) = (void *)((param_2 + iVar5) * 0x10 + (int)pvVar3);
        *(void **)(in_ECX + 4) = pvVar3;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_28 = *(int *)(in_ECX + 8);
    if ((uint)(local_28 - param_1 >> 4) < param_2) {
      local_18 = param_2 * 0x10;
      FUN_0056ecd0(param_1,local_28,local_18 + param_1);
      local_8 = 2;
      FUN_0056edd0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 4),&local_44);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_18;
      FUN_004be040(param_1,*(int *)(in_ECX + 8) - local_18,&local_44);
      ExceptionList = local_10;
      return;
    }
    local_18 = param_2 * 0x10;
    iVar5 = local_28 + param_2 * -0x10;
    uVar4 = FUN_0056ecd0(iVar5,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_004be080(param_1,iVar5,local_28,local_34);
    FUN_004be040(param_1,local_18 + param_1,&local_44);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0056f0e1 @ 0x0056f0e1 ====

void Catch_0056f0e1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x20));
  return;
}


// ==== FUN_0056f1d0 @ 0x0056f1d0 ====

undefined4 * FUN_0056f1d0(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int in_ECX;
  undefined4 *puVar4;
  uint local_10 [4];
  
  puVar4 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar4[1] + 0x1d) == '\0') {
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
    } while (*(char *)((int)puVar2 + 0x1d) == '\0');
  }
  if ((puVar4 == *(undefined4 **)(in_ECX + 4)) || (*param_1 < (uint)puVar4[3])) {
    local_10[0] = *param_1;
    local_10[2] = 0;
    local_10[1] = 0;
    local_10[3] = 0;
    piVar3 = (int *)FUN_0056ee00(&param_1,puVar4,local_10);
    return (undefined4 *)(*piVar3 + 0x10);
  }
  return puVar4 + 4;
}


// ==== FUN_0056f250 @ 0x0056f250 ====

void FUN_0056f250(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  
  puVar2 = param_1;
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
  in_ECX[0xd] = param_1[0xd];
  in_ECX[0xe] = param_1[0xe];
  in_ECX[0xf] = param_1[0xf];
  in_ECX[0x10] = param_1[0x10];
  in_ECX[0x11] = param_1[0x11];
  in_ECX[0x12] = param_1[0x12];
  in_ECX[0x13] = param_1[0x13];
  in_ECX[0x14] = param_1[0x14];
  in_ECX[0x15] = param_1[0x15];
  in_ECX[0x16] = param_1[0x16];
  puVar1 = param_1 + 0x18;
  in_ECX[0x17] = param_1[0x17];
  if (in_ECX + 0x18 != puVar1) {
    FUN_00504490(&param_1,*(undefined4 *)in_ECX[0x19],(undefined4 *)in_ECX[0x19]);
    FUN_005040e0(puVar1);
  }
  in_ECX[0x1b] = puVar2[0x1b];
  in_ECX[0x1c] = puVar2[0x1c];
  in_ECX[0x1d] = puVar2[0x1d];
  in_ECX[0x1e] = puVar2[0x1e];
  in_ECX[0x1f] = puVar2[0x1f];
  in_ECX[0x20] = puVar2[0x20];
  in_ECX[0x21] = puVar2[0x21];
  in_ECX[0x22] = puVar2[0x22];
  FUN_00401660(puVar2 + 0x23,0,0xffffffff);
  in_ECX[0x2a] = puVar2[0x2a];
  in_ECX[0x2b] = puVar2[0x2b];
  in_ECX[0x2c] = puVar2[0x2c];
  *(undefined1 *)(in_ECX + 0x2d) = *(undefined1 *)(puVar2 + 0x2d);
  *(undefined1 *)((int)in_ECX + 0xb5) = *(undefined1 *)((int)puVar2 + 0xb5);
  return;
}


// ==== FUN_0056f3b0 @ 0x0056f3b0 ====

void FUN_0056f3b0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 4) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 4))) {
    FUN_0056ef70(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0056ed40(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x10;
  return;
}


// ==== FUN_0056f420 @ 0x0056f420 ====

void FUN_0056f420(undefined1 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined1 *)(in_ECX + 0x7c);
  param_1[1] = *(undefined1 *)(in_ECX + 0x7d);
  if (param_1 + 4 != (undefined1 *)(in_ECX + 0x80)) {
    FUN_00504490(&param_1,**(undefined4 **)(param_1 + 8),*(undefined4 **)(param_1 + 8));
    FUN_005040e0((undefined1 *)(in_ECX + 0x80));
  }
  return;
}


// ==== FUN_0056f460 @ 0x0056f460 ====

void FUN_0056f460(byte param_1)

{
  void *in_ECX;
  
  FUN_0056d910();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0056f480 @ 0x0056f480 ====

undefined1 FUN_0056f480(void)

{
  return 0;
}


// ==== FUN_0056f490 @ 0x0056f490 ====

undefined4 FUN_0056f490(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) == '\0') {
    return 0;
  }
  *(undefined1 *)(in_ECX + 0x44) = 0;
  if (*(undefined4 **)(in_ECX + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x40))(1);
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  return 1;
}


// ==== FUN_0056f4c0 @ 0x0056f4c0 ====

void FUN_0056f4c0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(param_1,0);
  }
  return;
}


// ==== FUN_0056f4e0 @ 0x0056f4e0 ====

void FUN_0056f4e0(undefined1 *param_1)

{
  int in_ECX;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
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
  
  *(undefined1 *)(in_ECX + 0x48) = *param_1;
  *(undefined1 *)(in_ECX + 0x49) = param_1[1];
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x24);
  if ((*(int *)(in_ECX + 0x40) != 0) && (*(int *)(in_ECX + 4) != 0)) {
    local_34[0] = *(undefined1 *)(in_ECX + 0x48);
    local_c = *(undefined4 *)(in_ECX + 0x70);
    local_8 = *(undefined4 *)(in_ECX + 0x74);
    local_4 = *(undefined4 *)(in_ECX + 0x78);
    local_30 = *(undefined4 *)(in_ECX + 0x4c);
    local_28 = *(undefined4 *)(in_ECX + 0x54);
    local_2c = *(undefined4 *)(in_ECX + 0x50);
    local_20 = *(undefined4 *)(in_ECX + 0x5c);
    local_24 = *(undefined4 *)(in_ECX + 0x58);
    local_18 = *(undefined4 *)(in_ECX + 100);
    local_1c = *(undefined4 *)(in_ECX + 0x60);
    local_10 = *(undefined4 *)(in_ECX + 0x6c);
    local_14 = *(undefined4 *)(in_ECX + 0x68);
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x1c))(local_34);
  }
  return;
}


// ==== FUN_0056f5b0 @ 0x0056f5b0 ====

void FUN_0056f5b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bd1a4;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    *(undefined1 *)(in_ECX + 0x11) = 0;
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
    *(undefined1 *)(in_ECX + 0x11) = 0;
  }
  FUN_00504010();
  FUN_00552170();
  return;
}


// ==== FUN_0056f5f0 @ 0x0056f5f0 ====

undefined4 FUN_0056f5f0(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) == '\x01') {
    return 0;
  }
  FUN_00401660(param_1,0,0xffffffff);
  piVar3 = (int *)(**(code **)(*DAT_00b5a7bc + 4))();
  *(int **)(in_ECX + 0x40) = piVar3;
  if (piVar3 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar3 + 4))(param_1 + 0x1c);
    if (cVar2 != '\0') {
      iVar1 = **(int **)(in_ECX + 0x40);
      uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      cVar2 = (**(code **)(iVar1 + 0x18))(uVar4);
      if (cVar2 != '\0') {
        *(undefined1 *)(in_ECX + 0x44) = 1;
        return 1;
      }
    }
    (**(code **)(*DAT_00b5a7bc + 8))(*(undefined4 *)(in_ECX + 0x40));
    *(undefined4 *)(in_ECX + 0x40) = 0;
  }
  return 0;
}


// ==== FUN_0056f680 @ 0x0056f680 ====

uint FUN_0056f680(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  
  uVar3 = *(uint *)(in_ECX + 0x80);
  if (uVar3 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (int)(*(int *)(in_ECX + 0x84) - uVar3) >> 2;
  }
  uVar4 = 0;
  if (uVar5 != 0) {
    iVar1 = *(int *)(in_ECX + 0x80);
    do {
      if (iVar1 == 0) {
LAB_0056f6d4:
                    /* WARNING: Subroutine does not return */
        FUN_0042f370();
      }
      iVar2 = *(int *)(in_ECX + 0x84) - iVar1;
      uVar3 = iVar2 >> 2;
      if (uVar3 <= uVar4) goto LAB_0056f6d4;
      if (*(int *)(iVar1 + uVar4 * 4) == param_1) {
        return CONCAT31((int3)(iVar2 >> 10),1);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar5);
  }
  return uVar3 & 0xffffff00;
}


// ==== FUN_0056f6f0 @ 0x0056f6f0 ====

int FUN_0056f6f0(int param_1,int param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int extraout_EAX;
  int iVar3;
  int extraout_EAX_00;
  int in_ECX;
  char *pcVar4;
  undefined1 auStack_38 [4];
  void *pvStack_34;
  undefined4 uStack_24;
  uint uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))();
  uStack_20 = 0xf;
  uStack_24 = 0;
  pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
  FUN_00401660(uVar2,0,0xffffffff);
  if (param_2 == 0) {
    uVar2 = 0xd;
    pcVar4 = s__result_label_009bd160;
  }
  else if (param_2 == 1) {
    uVar2 = 0xf;
    pcVar4 = s__subtitle_label_009bd170;
  }
  else {
    if (param_2 != 2) {
      FUN_00401830(s_FALSE_009bd190);
      FUN_00406880(auStack_1c);
      if (uStack_4 < 0x10) {
        uStack_4 = 0xf;
        uStack_8 = 0;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
        pcVar1 = (code *)swi(3);
        iVar3 = (*pcVar1)();
        return iVar3;
      }
      _free(pvStack_18);
      return extraout_EAX;
    }
    uVar2 = 0xf;
    pcVar4 = s__npctitle_label_009bd180;
  }
  FUN_004020e0(pcVar4,uVar2);
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(auStack_38,0,0xffffffff);
  if (uStack_20 < 0x10) {
    return param_1;
  }
  _free(pvStack_34);
  return extraout_EAX_00;
}


// ==== FUN_0056f7d0 @ 0x0056f7d0 ====

void FUN_0056f7d0(void)

{
  undefined4 *in_ECX;
  
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009bd1a4;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x29] = 0xf;
  in_ECX[0x28] = 0;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  in_ECX[0x30] = 0xf;
  in_ECX[0x2f] = 0;
  *(undefined1 *)(in_ECX + 0x2b) = 0;
  in_ECX[0x37] = 0xf;
  in_ECX[0x36] = 0;
  *(undefined1 *)(in_ECX + 0x32) = 0;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  return;
}


// ==== FUN_0056f850 @ 0x0056f850 ====

/* WARNING: Removing unreachable block (ram,0x0056f945) */

void FUN_0056f850(int param_1)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  undefined1 auStack_52 [26];
  void *local_38 [5];
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  FUN_0056f6f0(local_38,param_1);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))(local_38);
  if (piVar2 == (int *)0x0) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_FALSE_009bd158,5);
    FUN_00406880(auStack_20);
    if (uStack_8 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_1c);
    return;
  }
  (**(code **)(*piVar2 + 0x30))();
  if (param_1 == 0) {
    iVar3 = in_ECX + 0x8c;
  }
  else if (param_1 == 1) {
    iVar3 = in_ECX + 0xa8;
  }
  else {
    if (param_1 != 2) goto LAB_0056f92d;
    iVar3 = in_ECX + 0xc4;
  }
  FUN_00401660(iVar3,0,0xffffffff);
LAB_0056f92d:
  FUN_0055a260(auStack_52 + -6);
  if (uStack_24 < 0x10) {
    return;
  }
  _free(local_38[0]);
  return;
}


// ==== FUN_0056f9a0 @ 0x0056f9a0 ====

void FUN_0056f9a0(int *param_1)

{
  code *pcVar1;
  int *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  int *local_8;
  uint local_4;
  
  if (param_1 != (int *)0x0) {
    FUN_00430ad0(param_1 + 0xd3);
    FUN_00401660(param_1 + 0xd7,0,0xffffffff);
    FUN_00401660(param_1 + 0xde,0,0xffffffff);
    FUN_00401660(param_1 + 0xe5,0,0xffffffff);
    in_ECX[0x1c] = *param_1;
    in_ECX[0x1d] = param_1[1];
    in_ECX[0x1e] = param_1[2];
    FUN_0056f850(0);
    FUN_0056f850(1);
    FUN_0056f850(2);
    (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
    return;
  }
  local_4 = 0xf;
  local_8 = param_1;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_i_pProperty_009bd144,0xb);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0056fa80 @ 0x0056fa80 ====

void FUN_0056fa80(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int *unaff_retaddr;
  undefined1 auStack_53a [2];
  uint uStack_538;
  undefined1 auStack_514 [4];
  undefined4 uStack_510;
  uint uStack_50c;
  undefined1 uStack_508;
  void *pvStack_4f8;
  undefined4 uStack_4f4;
  undefined4 uStack_4f0;
  undefined4 uStack_4ec;
  undefined4 uStack_4e8;
  uint auStack_4e4 [2];
  void *pvStack_4dc;
  uint uStack_4c8;
  undefined1 auStack_4c4 [24];
  undefined1 auStack_4ac [12];
  void *pvStack_4a0;
  undefined4 uStack_490;
  uint uStack_48c;
  undefined1 auStack_480 [4];
  undefined4 uStack_47c;
  undefined4 uStack_478;
  undefined4 uStack_474;
  undefined4 uStack_2e8;
  undefined4 uStack_2e4;
  undefined4 uStack_2e0;
  undefined4 uStack_2dc;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 8))(8);
  piVar4 = (int *)(**(code **)(*unaff_retaddr + 0x3c))();
  FUN_0056f6f0(auStack_4c4,param_1);
  piVar5 = (int *)(**(code **)(*piVar4 + 0x4c))(auStack_4c4);
  FUN_0056f6f0(auStack_4e4,unaff_retaddr);
  uVar6 = (**(code **)(*piVar5 + 0x10))();
  FUN_005041e0(uVar6);
  FUN_00401660(auStack_4e4,0,0xffffffff);
  uStack_4f4 = 0xf;
  pvStack_4f8 = (void *)0x0;
  uStack_508 = 0;
  uStack_4f0 = 0;
  uStack_4ec = 0;
  uStack_4e8 = 0;
  FUN_00401660(auStack_4e4,0,0xffffffff);
  (**(code **)(*piVar2 + 8))(auStack_4ac);
  piVar4 = piVar2;
  (**(code **)(*piVar3 + 0x38))();
  (**(code **)(*piVar3 + 0x1c))(auStack_514);
  FUN_00505f10();
  uStack_2e4 = 5;
  uStack_2e0 = 5;
  uStack_2e8 = (uint)uStack_2e8._3_1_ << 0x18;
  uStack_2dc = 0xc;
  iVar7 = (**(code **)(*piVar5 + 0x30))();
  FUN_0056fe50(auStack_53a + -0x12);
  uStack_2e8 = *(undefined4 *)(iVar7 + 0x7c);
  uStack_2e4 = *(undefined4 *)(iVar7 + 0x80);
  uStack_2e0 = *(undefined4 *)(iVar7 + 0x84);
  uStack_2dc = *(undefined4 *)(iVar7 + 0x88);
  uStack_47c = *(undefined4 *)(iVar7 + 0x8c);
  uStack_478 = *(undefined4 *)(iVar7 + 0x90);
  uStack_474 = *(undefined4 *)(iVar7 + 0x94);
  (**(code **)(*piVar3 + 8))(auStack_53a + -0x12);
  (**(code **)(*piVar3 + 0x24))(auStack_480);
  (**(code **)(*piVar2 + 0x2c))(piVar3);
  piVar4 = (int *)piVar4[1];
  if (piVar4 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 0x74))(piVar4);
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(*piVar4 + 0x78))(piVar2);
      if (cVar1 == '\0') {
        (**(code **)(*piVar2 + 0x74))(0);
      }
      else {
        iVar7 = (**(code **)(*piVar4 + 0x38))();
        piVar2[1] = iVar7;
      }
    }
  }
  if (0xf < uStack_538) {
    _free((void *)0x0);
    return;
  }
  FUN_00505d80();
  if (0xf < uStack_50c) {
    _free((void *)0x1);
    return;
  }
  uStack_50c = 0xf;
  uStack_510 = 0;
  if (0xf < uStack_48c) {
    _free(pvStack_4a0);
    return;
  }
  uStack_48c = 0xf;
  uStack_490 = 0;
  pvStack_4a0 = (void *)((uint)pvStack_4a0 & 0xffffff00);
  if (0xf < auStack_4e4[0]) {
    _free(pvStack_4f8);
    return;
  }
  auStack_4e4[0] = 0xf;
  uStack_4e8 = 0;
  pvStack_4f8 = (void *)((uint)pvStack_4f8 & 0xffffff00);
  if (uStack_4c8 < 0x10) {
    return;
  }
  _free(pvStack_4dc);
  return;
}


// ==== FUN_0056fd80 @ 0x0056fd80 ====

void FUN_0056fd80(int param_1)

{
  code *pcVar1;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (param_1 != 0) {
    FUN_0056fa80(param_1,0);
    FUN_0056fa80(param_1,1);
    FUN_0056fa80(param_1,2);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_FALSE_009bd150,5);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0056fe00 @ 0x0056fe00 ====

void FUN_0056fe00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bd1a4;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    *(undefined1 *)(in_ECX + 0x11) = 0;
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
    *(undefined1 *)(in_ECX + 0x11) = 0;
  }
  FUN_00504010();
  FUN_00552170();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0056fe50 @ 0x0056fe50 ====

void FUN_0056fe50(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x98);
  param_1[1] = *(undefined4 *)(in_ECX + 0x9c);
  FUN_00401660(in_ECX + 0xa0,0,0xffffffff);
  param_1[9] = *(undefined4 *)(in_ECX + 0xbc);
  param_1[10] = *(undefined4 *)(in_ECX + 0xc0);
  param_1[0xb] = *(undefined4 *)(in_ECX + 0xc4);
  *(undefined1 *)(param_1 + 0xc) = *(undefined1 *)(in_ECX + 200);
  *(undefined1 *)((int)param_1 + 0x31) = *(undefined1 *)(in_ECX + 0xc9);
  return;
}


// ==== FUN_0056feb0 @ 0x0056feb0 ====

void FUN_0056feb0(int param_1)

{
  FUN_00430ad0(param_1);
  FUN_00401660(param_1 + 0x10,0,0xffffffff);
  FUN_00401660(param_1 + 0x2c,0,0xffffffff);
  FUN_00401660(param_1 + 0x48,0,0xffffffff);
  return;
}


// ==== FUN_0056ff00 @ 0x0056ff00 ====

uint FUN_0056ff00(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  uVar2 = (**(code **)(*param_1 + 0x10))();
  if (((uVar2 != uVar1) || (uVar2 = 1, param_1[2] != 1)) || (param_1[6] != 1)) {
    uVar2 = uVar2 & 0xffffff00;
  }
  return uVar2;
}


// ==== FUN_0056ff60 @ 0x0056ff60 ====

void FUN_0056ff60(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(param_1,0);
  }
  return;
}


// ==== FUN_0056ff80 @ 0x0056ff80 ====

undefined4 FUN_0056ff80(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) == '\0') {
    return 0;
  }
  *(undefined1 *)(in_ECX + 0x44) = 0;
  if (*(undefined4 **)(in_ECX + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x40))(1);
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  return 1;
}


// ==== FUN_0056ffb0 @ 0x0056ffb0 ====

uint FUN_0056ffb0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  uVar2 = (**(code **)(*param_1 + 0x10))();
  if (uVar2 == uVar1) {
    uVar2 = param_1[2] - 1;
    switch(uVar2) {
    case 0:
    case 1:
    case 4:
    case 5:
    case 6:
    case 7:
      return CONCAT31((int3)(uVar2 >> 8),1);
    }
  }
  return uVar2 & 0xffffff00;
}


