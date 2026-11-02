// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x6d0000-0x6dffff

// ==== FUN_006d01e0 @ 0x006d01e0 ====

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_006d01e0(int param_1)

{
  code *pcVar1;
  char cVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  void *in_ECX;
  int *piVar7;
  undefined1 auStack_f2 [2];
  undefined1 local_de [10];
  void *pvStack_d4;
  void *pvStack_d0;
  void *local_cc;
  uint uStack_c0;
  uint uStack_bc;
  uint uStack_b8;
  float fStack_b4;
  float fStack_b0;
  undefined1 local_ac [4];
  undefined4 local_a8;
  undefined4 local_a4;
  int local_a0;
  void *pvStack_9c;
  int iStack_98;
  int iStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  uint uStack_88;
  undefined1 uStack_80;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  void *pvStack_64;
  void *local_60;
  undefined1 local_5c [8];
  undefined4 uStack_54;
  uint uStack_50;
  uint local_4c;
  undefined4 local_48;
  void *pvStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [8];
  int aiStack_20 [8];
  
  local_cc = (void *)0x0;
  if (param_1 == 0) {
    local_cc = (void *)0x0;
  }
  else if (param_1 == 1) {
    local_cc = (void *)0x1;
  }
  puVar3 = (undefined4 *)FUN_004f5730();
  local_a8 = *puVar3;
  local_a4 = puVar3[1];
  local_a0 = puVar3[2];
  local_48 = 0xf;
  local_4c = 0;
  local_5c[0] = 0;
  FUN_00401740();
  (**(code **)(**(int **)((int)in_ECX + 4) + 0x34))();
  if (0xf < local_4c) {
    _free(local_60);
    return;
  }
  local_4c = 0xf;
  uStack_50 = 0;
  local_60 = (void *)((uint)local_60 & 0xffffff00);
  FUN_00401740(s_con_creature__d_009e4524,0xf);
  FUN_00404230(aiStack_20);
  piVar7 = aiStack_20;
  piVar4 = (int *)(**(code **)(**(int **)((int)in_ECX + 4) + 0x34))();
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
    local_a4._0_3_ = CONCAT12(1,(undefined2)local_a4);
    local_a0 = 0;
    pvStack_9c = (void *)0x0;
    iStack_98 = 0;
    iStack_94 = 0;
    uStack_90 = 0;
    uStack_8c = 0;
    uStack_88 = 0;
    uStack_6c = 0xf;
    uStack_70 = 0;
    uStack_80 = 0;
    piVar5 = (int *)(**(code **)(*DAT_00b5a7ac + 8))(0);
    uStack_38 = 0xf;
    uStack_3c = 0;
    local_4c = local_4c & 0xffffff00;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    FUN_00401660(auStack_28,0,0xffffffff);
    FUN_00401660(&uStack_50,0,0xffffffff);
    pvStack_9c = (void *)((int)fStack_b4 + -5);
    local_a0 = (int)fStack_b0 + -5;
    iStack_94 = (int)fStack_b4 + 5;
    iStack_98 = (int)fStack_b0 + 5;
    local_a4 = 100;
    local_a8 = CONCAT22(local_a8._2_2_,0x101);
    uStack_bc = 0xf;
    uStack_c0 = 0;
    pvStack_d0 = (void *)((uint)pvStack_d0 & 0xffffff00);
    FUN_00401740(s_mainbar_minimap_009e4534,0xf);
    (**(code **)(*DAT_00b5a7c0 + 8))(&pvStack_d4);
    if (0xf < uStack_c0) {
      _free(pvStack_d4);
      return;
    }
    (**(code **)(*piVar4 + 8))(local_ac);
    if (&local_60 != (void **)0x0) {
      cVar2 = (**(code **)(*piVar4 + 0x74))(&local_60);
      if (cVar2 != '\0') {
        cVar2 = (**(code **)((int)local_60 + 0x78))(piVar4);
        if (cVar2 == '\0') {
          (**(code **)(*piVar4 + 0x74))(0);
        }
        else {
          iVar6 = (**(code **)(*piVar7 + 0x38))();
          piVar4[1] = iVar6;
        }
      }
    }
    (**(code **)(*piVar5 + 0x38))(piVar4);
    (**(code **)(*piVar5 + 0x1c))(local_5c);
    (**(code **)(*piVar4 + 0x2c))(piVar5);
    FUN_00587d40(auStack_f2 + -6);
    if (0xf < uStack_50) {
      _free(pvStack_64);
      return;
    }
    uStack_50 = 0xf;
    uStack_54 = 0;
    pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
    if (0xf < uStack_88) {
      _free(pvStack_9c);
      return;
    }
    uStack_88 = 0xf;
    uStack_8c = 0;
    pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
    in_ECX = pvStack_d0;
  }
  else {
    iVar6 = (**(code **)(*piVar4 + 0x30))();
    if (iVar6 == 0) {
      uStack_b8 = 0xf;
      uStack_bc = 0;
      local_cc = (void *)((uint)local_cc._1_3_ << 8);
      FUN_00401740(s_pPanel____NULL_009e4544,0xe);
      FUN_00406880(&pvStack_d0);
      if (uStack_b8 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(local_cc);
      return;
    }
    uStack_b8 = 0xf;
    uStack_bc = 0;
    local_cc = (void *)((uint)local_cc._1_3_ << 8);
    FUN_00401740(s_mainbar_minimap_009e4554,0xf);
    (**(code **)(*DAT_00b5a7c0 + 8))(&pvStack_d0);
    if (0xf < uStack_bc) {
      _free(pvStack_d0);
      return;
    }
    FUN_00587d40(local_de + -6);
  }
  (**(code **)(*piVar4 + 0x24))(1);
  *(int *)((int)in_ECX + 0x24U) = *(int *)((int)in_ECX + 0x24U) + 1;
  if (uStack_2c < 0x10) {
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_006d0620 @ 0x006d0620 ====

void FUN_006d0620(void)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  undefined1 local_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar2 = 0;
  if (0 < *(int *)(in_ECX + 0x24)) {
    do {
      FUN_00401740(s_con_creature__d_009e4564,0xf);
      FUN_00404230(local_1c);
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_1c);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x24))(0);
      }
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
      iVar2 = iVar2 + 1;
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    } while (iVar2 < *(int *)(in_ECX + 0x24));
  }
  *(undefined4 *)(in_ECX + 0x24) = 0;
  return;
}


// ==== FUN_006d06b0 @ 0x006d06b0 ====

/* WARNING: Removing unreachable block (ram,0x006d0839) */

undefined4 FUN_006d06b0(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 extraout_EAX;
  undefined4 uVar4;
  undefined4 extraout_EAX_00;
  int *piVar5;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  int *piVar6;
  undefined4 extraout_EAX_03;
  void *unaff_EBX;
  undefined4 uStack_38;
  undefined4 uStack_2c;
  void *pvStack_28;
  uint uStack_24;
  void *pvStack_20;
  undefined4 uStack_18;
  uint uStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  
  cVar2 = (**(code **)(*DAT_00b5add0 + 0x34))();
  if (cVar2 != '\x01') {
    return 0;
  }
  (**(code **)(*DAT_00b5add0 + 0x14))();
  iVar3 = (**(code **)(*DAT_00b5a74c + 0xc))(0x1c);
  if (iVar3 == 0) {
    uStack_24 = 0xf;
    pvStack_28 = (void *)0x0;
    uStack_38 = (void *)((uint)uStack_38 & 0xffffff00);
    FUN_00401740(s_pUIHandler____NULL_009e4574,0x12);
    FUN_00406880((int)register0x00000010 + -0x3c);
    if (uStack_24 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
    _free(uStack_38);
    return extraout_EAX;
  }
  piVar6 = *(int **)(iVar3 + 4);
  if (piVar6 == (int *)0x0) {
    uStack_24 = 0xf;
    pvStack_28 = (void *)0x0;
    uStack_38 = (void *)((uint)uStack_38 & 0xffffff00);
    FUN_00401740(s_pWindow____NULL_009e4588,0xf);
    FUN_00406880((int)register0x00000010 + -0x3c);
    if (uStack_24 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
    _free(uStack_38);
    return extraout_EAX_00;
  }
  uStack_24 = 0xf;
  pvStack_28 = (void *)0x0;
  FUN_00401740(s_btn_bigmap_show_009e4598,0xf);
  piVar5 = (int *)(**(code **)(*piVar6 + 0x34))((int)register0x00000010 + -0x3c);
  if (0xf < pvStack_28) {
    _free(unaff_EBX);
    return extraout_EAX_01;
  }
  pvStack_28 = (void *)0xf;
  uStack_2c = 0;
  if (piVar5 == (int *)0x0) {
    uStack_c = 0xf;
    uStack_10 = 0;
    pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e45a8,0x12);
    FUN_00406880(&uStack_24);
    if (uStack_c < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
    _free(pvStack_20);
    return extraout_EAX_02;
  }
  (**(code **)(*piVar5 + 0x24))(1);
  uStack_2c = 0xf;
  FUN_00401740(s_btn_bigmap_hide_009e45bc,0xf);
  piVar6 = (int *)(**(code **)(*piVar6 + 0x34))((int)register0x00000010 + -0x44);
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 0x24))(0);
    return 1;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  FUN_00401740(s_pComposite____NULL_009e45cc,0x12);
  FUN_00406880(&uStack_2c);
  if (uStack_14 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar4 = (*pcVar1)();
    return uVar4;
  }
  _free(pvStack_28);
  return extraout_EAX_03;
}


// ==== FUN_006d08b0 @ 0x006d08b0 ====

void FUN_006d08b0(int param_1)

{
  uint *puVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  void *unaff_EBX;
  uint *puVar4;
  void *pvStack_80;
  undefined1 auStack_7c [8];
  undefined4 uStack_74;
  uint uStack_70;
  uint auStack_6c [22];
  undefined4 uStack_13;
  undefined4 uStack_f;
  byte bStack_b;
  
  if (DAT_00b5a6e4 != (int *)0x0) {
    puVar1 = (uint *)(**(code **)(*DAT_00b5a6e4 + 8))();
    puVar4 = auStack_6c + 2;
    for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar4 = puVar4 + 1;
    }
    param_1 = (uint)bStack_b + param_1;
    if (param_1 < 0x100) {
      if (param_1 < 0x3c) {
        param_1 = 0x3c;
      }
    }
    else {
      param_1 = 0xff;
    }
    bStack_b = (byte)param_1;
    auStack_6c[1] = 0xf;
    auStack_6c[0] = 0;
    auStack_7c[0] = 0;
    FUN_00401740(s_pan_map_bg_009e4670,10);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_80);
    if (0xf < auStack_6c[0]) {
      _free(pvStack_80);
      return;
    }
    auStack_6c[0] = 0xf;
    uStack_70 = 0;
    pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
    if (piVar2 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar2 + 0x30))();
      if (iVar3 != 0) {
        FUN_00587d10(uStack_f);
      }
    }
    auStack_6c[0] = 0xf;
    uStack_70 = 0;
    pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
    FUN_00401740(s_pan_map_009e467c,7);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_6c + -6);
    if (0xf < uStack_70) {
      _free(unaff_EBX);
      return;
    }
    uStack_70 = 0xf;
    uStack_74 = 0;
    if (piVar2 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar2 + 0x30))();
      if (iVar3 != 0) {
        FUN_00587d10(uStack_13);
      }
    }
    (**(code **)(*DAT_00b5a6e4 + 0x10))(auStack_6c);
  }
  return;
}


// ==== FUN_006d0a00 @ 0x006d0a00 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d0a00(void)

{
  code *pcVar1;
  char cVar2;
  undefined1 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int in_ECX;
  float10 fVar8;
  undefined1 auStack_82 [6];
  undefined1 auStack_7c [4];
  void *pvStack_78;
  undefined4 uStack_68;
  uint uStack_64;
  float fStack_60;
  void *local_58;
  undefined1 local_54;
  undefined4 uStack_48;
  uint local_44;
  int local_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  void *pvStack_28;
  uint uStack_14;
  
  local_40 = 0xf;
  local_44 = 0;
  local_54 = 0;
  FUN_00401740(s_pan_pointArrow_009e4694,0xe);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_58);
  if (0xf < local_44) {
    _free(local_58);
    return;
  }
  local_44 = 0xf;
  uStack_48 = 0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  if (piVar4 == (int *)0x0) {
    uStack_64 = 0xf;
    uStack_68 = 0;
    pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e46a4,0x12);
    FUN_00406880(auStack_7c);
    if (uStack_64 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_78);
    return;
  }
  cVar2 = (**(code **)(*DAT_00b5ae58 + 8))();
  if (cVar2 != *(char *)(in_ECX + 0x18)) {
    iVar5 = (**(code **)(*piVar4 + 0x30))();
    if (iVar5 == 0) {
      uStack_64 = 0xf;
      uStack_68 = 0;
      pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
      FUN_00401740(s_pPanel____NULL_009e46b8,0xe);
      FUN_00406880(auStack_7c);
      if (uStack_64 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_78);
      return;
    }
    (**(code **)(*DAT_00b5ae58 + 8))();
    FUN_00587d40(auStack_82 + -6);
    uVar3 = (**(code **)(*DAT_00b5ae58 + 8))();
    *(undefined1 *)(in_ECX + 0x18) = uVar3;
  }
  fVar8 = (float10)FUN_0040d5f0(in_ECX + 0x10);
  fStack_60 = (float)-(fVar8 - (float10)_DAT_00b32ee4);
  puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    uVar7 = (**(code **)(*piVar4 + 4))();
    *puVar6 = &PTR_FUN_009e46fc;
    puVar6[1] = uVar7;
  }
  puVar6[2] = fStack_60;
  (**(code **)(*DAT_00b5ad24 + 4))(puVar6);
  (**(code **)*puVar6)(1);
  uVar7 = (**(code **)(*piVar4 + 0x10))();
  FUN_005041e0(uVar7);
  local_40 = *(int *)(in_ECX + 0xc) + -7;
  iStack_3c = *(int *)(in_ECX + 8) + -10;
  iStack_38 = *(int *)(in_ECX + 0xc) + 7;
  iStack_34 = *(int *)(in_ECX + 8) + 0xb;
  (**(code **)(*piVar4 + 0xc))(&uStack_48);
  if (uStack_14 < 0x10) {
    return;
  }
  _free(pvStack_28);
  return;
}


// ==== FUN_006d0c10 @ 0x006d0c10 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d0c10(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 ***pppuVar8;
  int iVar9;
  int in_ECX;
  char *pcVar10;
  uint uStack_7c;
  undefined4 ***pppuStack_74;
  undefined1 uStack_70;
  undefined4 uStack_64;
  uint uStack_60;
  undefined4 uStack_5c;
  void *apvStack_58 [4];
  undefined4 uStack_48;
  uint uStack_44;
  undefined1 auStack_40 [8];
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  
  if (DAT_00b5a7b4 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a7b4 + 0x58))();
    piVar3 = (int *)(**(code **)(*DAT_00b5ac1c + 0x14))();
    pcVar4 = (char *)(**(code **)(*piVar3 + 0x70))();
    uStack_5c = 0xf;
    uStack_60 = 0;
    uStack_70 = 0;
    pcVar10 = pcVar4;
    do {
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(pcVar4,(int)pcVar10 - (int)(pcVar4 + 1));
    uStack_7c = 0;
    do {
      piVar3 = *(int **)(in_ECX + 4);
      FUN_00401740(s_pan_party__d_009e46c8,0xc);
      uVar5 = FUN_00404230(apvStack_58);
      piVar3 = (int *)(**(code **)(*piVar3 + 0x34))(uVar5);
      if (0xf < uStack_44) {
        _free(apvStack_58[0]);
        return;
      }
      uStack_44 = 0xf;
      uStack_48 = 0;
      apvStack_58[0] = (void *)((uint)apvStack_58[0] & 0xffffff00);
      if (piVar2 == (int *)0x0) {
        (**(code **)(*piVar3 + 0x24))(0);
        (**(code **)(_DAT_00000000 + 0xc))();
      }
      else {
        uVar6 = (**(code **)(*piVar2 + 0x10))();
        if (uStack_7c < uVar6) {
          iVar7 = (**(code **)(*piVar2 + 4))();
          if (iVar7 == 0) {
            (**(code **)(*piVar3 + 0x24))(0);
            (**(code **)(*piVar2 + 0xc))();
            goto LAB_006d0e02;
          }
          if (*(char *)(iVar7 + 0x4c) != '\0') {
            pppuVar8 = pppuStack_74;
            if (uStack_60 < 0x10) {
              pppuVar8 = &pppuStack_74;
            }
            iVar9 = FUN_00403620(0,*(undefined4 *)(iVar7 + 0x24),pppuVar8,uStack_64);
            if (iVar9 != 0) {
              uVar5 = (**(code **)(*piVar3 + 0x10))();
              FUN_005041e0(uVar5);
              iStack_30 = iStack_30 - iStack_38;
              iStack_2c = iStack_2c - iStack_34;
              iStack_38 = (int)(*(float *)(iVar7 + 0x54) - (float)(iStack_30 / 2));
              iStack_34 = (int)(*(float *)(iVar7 + 0x50) - (float)(iStack_2c / 2));
              iStack_30 = iStack_38 + iStack_30;
              iStack_2c = iStack_34 + iStack_2c;
              auStack_40[0] = 1;
              (**(code **)(*piVar3 + 0xc))(auStack_40);
              (**(code **)(*piVar2 + 0xc))();
              FUN_00713830();
              goto LAB_006d0e02;
            }
          }
        }
        (**(code **)(*piVar3 + 0x24))(0);
        (**(code **)(*piVar2 + 0xc))();
      }
LAB_006d0e02:
      uStack_7c = uStack_7c + 1;
    } while (uStack_7c < 6);
    (**(code **)(*DAT_00b5a7b4 + 0x5c))(piVar2);
    if (0xf < uStack_60) {
      _free(pppuStack_74);
      return;
    }
  }
  return;
}


// ==== FUN_006d0e40 @ 0x006d0e40 ====

undefined4 FUN_006d0e40(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined1 auStack_1c [28];
  
  iVar1 = (**(code **)(*DAT_00b5a6b0 + 8))();
  if (iVar1 == 1) {
    iVar1 = (**(code **)(*DAT_00b5ac1c + 0x20))();
    if ((iVar1 != 2) && (iVar1 = (**(code **)(*DAT_00b5ac1c + 0x20))(), iVar1 != 1)) {
      return 0;
    }
  }
  else {
    iVar1 = (**(code **)(*DAT_00b5ac1c + 0x20))();
    if (((iVar1 != 2) && (iVar1 = (**(code **)(*DAT_00b5ac1c + 0x20))(), iVar1 != 4)) &&
       (iVar1 = (**(code **)(*DAT_00b5ac1c + 0x20))(), iVar1 != 3)) {
      return 0;
    }
  }
  iVar1 = FUN_005897d0();
  iVar1 = FUN_00403620(0,*(undefined4 *)(iVar1 + 0x14),s_pan_map_009e46d8,7);
  if (iVar1 != 0) {
    return 0;
  }
  piVar2 = (int *)FUN_005897e0();
  if (((0 < *piVar2) && (0 < piVar2[1])) && ((*piVar2 < 0x200 && (piVar2[1] < 0x200)))) {
    FUN_00401830(s_setposition__d__d_009e46e0);
    uVar3 = FUN_00404230(auStack_1c);
    FUN_00459340(uVar3);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  return 1;
}


// ==== FUN_006d0f30 @ 0x006d0f30 ====

void FUN_006d0f30(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_10 = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    uStack_10 = *(undefined4 *)(iVar2 + 0x8c);
    uStack_c = *(undefined4 *)(iVar2 + 0x90);
    uStack_8 = param_1;
    FUN_00587d40(&uStack_10);
    FUN_00401660(param_1,0,0xffffffff);
  }
  return;
}


// ==== FUN_006d0fa0 @ 0x006d0fa0 ====

void FUN_006d0fa0(int param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  undefined1 auStack_9e [2];
  undefined4 uStack_88;
  undefined1 uStack_84;
  undefined1 uStack_83;
  undefined4 uStack_80;
  int iStack_7c;
  void *pvStack_78;
  int iStack_74;
  int iStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  uint uStack_64;
  undefined1 uStack_5c;
  undefined4 uStack_4c;
  void *pvStack_48;
  void *pvStack_44;
  void *pvStack_40;
  undefined1 auStack_38 [4];
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined1 uStack_28;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int *piStack_c;
  int *piStack_8;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_80._0_3_ = CONCAT12(1,(undefined2)uStack_80);
  iStack_7c = 0;
  pvStack_78 = (void *)0x0;
  iStack_74 = 0;
  iStack_70 = 0;
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  pvStack_48 = (void *)0xf;
  uStack_4c = 0;
  uStack_5c = 0;
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
  FUN_00401660(param_3,0);
  uStack_14 = 0xf;
  uStack_18 = 0;
  uStack_28 = 0;
  uStack_10 = 0;
  piStack_c = (int *)0x0;
  piStack_8 = (int *)0x0;
  FUN_00401740(s_pan_checkpoint__d_009e439c,0x11);
  uVar4 = FUN_00404230(&pvStack_48);
  FUN_00401660(uVar4,0);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  FUN_00401660(&uStack_2c,0);
  pvStack_78 = (void *)(param_1 + -5);
  iStack_7c = param_2 + -5;
  iStack_70 = param_1 + 5;
  iStack_74 = param_2 + 5;
  uStack_80 = 200;
  uStack_84 = 1;
  uStack_83 = 1;
  uStack_88 = 0;
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_pcpop_009e43b0);
  (**(code **)(*DAT_00b5a7c0 + 8))();
  if (0xf < uStack_34) {
    _free(pvStack_48);
    return;
  }
  (**(code **)(*piVar2 + 8))(&uStack_88);
  if (piStack_8 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 0x74))(piStack_8);
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(*piStack_8 + 0x78))(piVar2);
      if (cVar1 == '\0') {
        (**(code **)(*piVar2 + 0x74))(0);
      }
      else {
        iVar5 = (**(code **)(*piStack_c + 0x38))();
        piVar2[1] = iVar5;
      }
    }
  }
  (**(code **)(*piVar3 + 0x38))(piVar2);
  (**(code **)(*piVar3 + 0x1c))(auStack_38);
  (**(code **)(*piVar2 + 0x2c))(piVar3);
  FUN_00587d40(auStack_9e + -6);
  *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + 1;
  if (0xf < uStack_2c) {
    _free(pvStack_40);
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  if (uStack_64 < 0x10) {
    return;
  }
  _free(pvStack_78);
  return;
}


// ==== FUN_006d1210 @ 0x006d1210 ====

/* WARNING: Removing unreachable block (ram,0x006d13e6) */
/* WARNING: Removing unreachable block (ram,0x006d1520) */
/* WARNING: Removing unreachable block (ram,0x006d1365) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d1210(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 uVar5;
  void **ppvVar6;
  undefined4 uStack_118;
  undefined1 auStack_102 [10];
  int *piStack_f8;
  float fStack_ec;
  float fStack_e8;
  undefined4 uStack_e4;
  undefined1 auStack_e0 [4];
  uint uStack_dc;
  uint uStack_d8;
  undefined4 uStack_cc;
  void *pvStack_c8;
  undefined4 uStack_c4;
  int iStack_c0;
  int iStack_bc;
  int iStack_b8;
  uint uStack_b4;
  undefined1 uStack_aa;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  void *pvStack_8c;
  undefined1 uStack_88;
  uint uStack_78;
  undefined4 uStack_74;
  void *pvStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined1 auStack_64 [4];
  void *pvStack_60;
  uint uStack_5c;
  undefined4 uStack_50;
  uint uStack_4c;
  ushort uStack_38;
  undefined1 auStack_30 [16];
  undefined4 uStack_20;
  void *pvStack_1c;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  
  uStack_118 = 0x6d1229;
  (**(code **)(*DAT_00b5a7ac + 4))();
  uStack_aa = 1;
  uStack_a8 = 0;
  uStack_a4 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  uStack_98 = 0;
  uStack_94 = 0;
  uStack_90 = 0;
  uStack_74 = 0xf;
  uStack_78 = 0;
  uStack_88 = 0;
  uStack_118 = param_3;
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))();
  if ((piVar1 == (int *)0x0) || (iVar2 = (**(code **)(*piVar1 + 0xc))(), iVar2 != 5)) {
    if (uStack_78 < 0x10) {
      return;
    }
  }
  else {
    uStack_e4 = (**(code **)(*piVar1 + 0x14))();
    (**(code **)(*DAT_00b5ac98 + 0x78))(auStack_30);
    puVar3 = (uint *)(**(code **)(*piVar1 + 0x28))();
    uStack_dc = *puVar3;
    uStack_d8 = puVar3[1];
    piVar1 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
    uVar4 = uStack_38 | 0x1400000;
    uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,uVar4);
    pvStack_c8 = (void *)0xf;
    uStack_cc = 0;
    uStack_dc = uStack_dc & 0xffffff00;
    FUN_00401660(uVar5,0,0xffffffff);
    FUN_00401740(s__GUILDNAME__009e43b8,0xb);
    FUN_00404440(auStack_e0,auStack_102 + -0x12,uStack_10);
    FUN_00401740(s__ZEOLITENAME__009e43c4,0xd);
    ppvVar6 = &pvStack_60;
    uVar5 = (**(code **)(*piStack_f8 + 0x40))();
    FUN_00404440(&uStack_e4,&uStack_118,uVar5);
    if (0xf < uStack_4c) {
      _free(pvStack_60);
      return;
    }
    uStack_4c = 0xf;
    uStack_50 = 0;
    pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
    FUN_00401660(&uStack_e4,0,0xffffffff);
    uStack_74 = 0xf;
    uStack_78 = 0;
    uStack_88 = 0;
    pvStack_70 = (void *)0x0;
    uStack_6c = 0;
    uStack_68 = 0;
    FUN_00401740(s_pan_brick__d_009e43d4,0xc);
    uVar5 = FUN_00404230(auStack_64);
    FUN_00401660(uVar5,0,0xffffffff);
    if (0xf < uStack_4c) {
      _free(pvStack_60);
      return;
    }
    FUN_00401660(&pvStack_8c,0,0xffffffff);
    iStack_bc = (int)fStack_ec + -5;
    iStack_c0 = (int)fStack_e8 + -5;
    uStack_b4 = (int)fStack_ec + 6;
    iStack_b8 = (int)fStack_e8 + 6;
    pvStack_c8 = (void *)CONCAT31(pvStack_c8._1_3_,1);
    uStack_c4 = 200;
    FUN_00401740(s_war_occpuy_009e43e4,10);
    (**(code **)(*DAT_00b5a7c0 + 8))(&uStack_118);
    (**(code **)(_DAT_00000000 + 8))(&uStack_cc);
    FUN_00557b50(uStack_20);
    (**(code **)(*piVar1 + 0x38))(uVar4);
    (**(code **)(*piVar1 + 0x1c))(&uStack_98);
    (**(code **)((int)*ppvVar6 + 0x2c))(piVar1);
    FUN_00587d40(auStack_102 + -10);
    iRam00000028 = iRam00000028 + 1;
    if (0xf < uStack_5c) {
      _free(pvStack_70);
      return;
    }
    uStack_5c = 0xf;
    pvStack_60 = (void *)0x0;
    pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
    if (0xf < uStack_b4) {
      _free(pvStack_c8);
      return;
    }
    uStack_b4 = 0xf;
    iStack_b8 = 0;
    pvStack_c8 = (void *)((uint)pvStack_c8 & 0xffffff00);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    if (uStack_78 < 0x10) {
      return;
    }
  }
  _free(pvStack_8c);
  return;
}


// ==== FUN_006d1640 @ 0x006d1640 ====

void FUN_006d1640(undefined4 param_1,int *param_2)

{
  ushort uVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int *unaff_ESI;
  undefined4 *puVar8;
  undefined1 *puStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_ac;
  undefined1 uStack_a8;
  undefined1 uStack_a7;
  undefined4 uStack_a4;
  int iStack_a0;
  undefined4 uStack_9c;
  int iStack_98;
  int iStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  uint uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined1 uStack_78;
  void *pvStack_6c;
  void *pvStack_68;
  void *pvStack_64;
  undefined1 auStack_5c [4];
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  undefined1 uStack_4c;
  void *pvStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  uint auStack_28 [3];
  undefined1 auStack_1c [12];
  int *piStack_10;
  
  piVar6 = DAT_00b5ae14;
  uStack_c4 = 0x6d1662;
  iVar4 = (**(code **)(*param_2 + 8))();
  uStack_c4 = 0x6d166b;
  sVar3 = (**(code **)(*piVar6 + 0x18))();
  if (sVar3 == *(short *)(iVar4 + 6)) {
    uStack_c4 = 0x6d1680;
    uStack_ac = (**(code **)(*DAT_00b5a7ac + 4))();
    uStack_9c._0_3_ = CONCAT12(1,(undefined2)uStack_9c);
    iStack_98 = 0;
    iStack_94 = 0;
    uStack_90 = 0;
    uStack_8c = 0;
    uStack_88 = 0;
    uStack_84 = 0;
    uStack_80 = 0;
    pvStack_64 = (void *)0xf;
    pvStack_68 = (void *)0x0;
    uStack_78 = 0;
    iVar4 = *DAT_00b5b180;
    uStack_c4 = 0x6d16c6;
    iVar5 = (**(code **)(*param_2 + 8))();
    uStack_c4 = CONCAT22((short)((uint)iVar5 >> 0x10),*(undefined2 *)(iVar5 + 4));
    puStack_c8 = auStack_1c;
    (**(code **)(iVar4 + 0xc))();
    piVar6 = (int *)(**(code **)(*DAT_00b5a7ac + 8))(0);
    FUN_00401660(auStack_28,0,0xffffffff);
    uStack_38 = 0xf;
    pvStack_3c = (void *)0x0;
    uStack_4c = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    FUN_00401740(s_pan_sentry__d_009e43f0,0xd);
    uVar7 = FUN_00404230(&pvStack_6c);
    FUN_00401660(uVar7,0,0xffffffff);
    if (0xf < uStack_54) {
      _free(pvStack_68);
      return;
    }
    FUN_00401660(&uStack_50,0,0xffffffff);
    iVar4 = (**(code **)(*param_2 + 8))();
    uVar1 = *(ushort *)(iVar4 + 8);
    iVar4 = (**(code **)(*param_2 + 8))();
    iStack_a0 = (int)((float)*(ushort *)(iVar4 + 10) * DAT_009b3508 - DAT_009b0120);
    uStack_9c = (void *)(int)((float)uVar1 * DAT_009b3508 - DAT_009b0120);
    iStack_94 = (int)uStack_9c + 10;
    iStack_98 = iStack_a0 + 10;
    uStack_a4 = 100;
    uStack_a8 = 1;
    uStack_a7 = 1;
    uStack_ac = 0;
    uStack_54 = 0xf;
    uStack_58 = 0;
    pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
    FUN_00401740(s_mainbar_minimap_009e4400,0xf);
    (**(code **)(*DAT_00b5a7c0 + 8))(&pvStack_6c);
    if (0xf < uStack_58) {
      _free(pvStack_6c);
      return;
    }
    puVar8 = &uStack_ac;
    (**(code **)(*unaff_ESI + 8))();
    if (piStack_10 != (int *)0x0) {
      cVar2 = (**(code **)(*unaff_ESI + 0x74))(piStack_10);
      if (cVar2 != '\0') {
        cVar2 = (**(code **)(*piStack_10 + 0x78))(unaff_ESI);
        if (cVar2 == '\0') {
          (**(code **)(*unaff_ESI + 0x74))(0);
        }
        else {
          iVar4 = (**(code **)(*piStack_10 + 0x38))();
          unaff_ESI[1] = iVar4;
        }
      }
    }
    (**(code **)(*piVar6 + 0x38))(unaff_ESI);
    (**(code **)(*piVar6 + 0x1c))(auStack_5c);
    (**(code **)(*unaff_ESI + 0x2c))(piVar6);
    FUN_00587d40(&puStack_c8);
    puVar8[8] = puVar8[8] + 1;
    if (0xf < uStack_50) {
      _free(pvStack_64);
      return;
    }
    uStack_50 = 0xf;
    uStack_54 = 0;
    pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
    if (0xf < auStack_28[0]) {
      _free(pvStack_3c);
      return;
    }
    auStack_28[0] = 0xf;
    uStack_2c = 0;
    pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
    if (0xf < uStack_88) {
      _free(uStack_9c);
      return;
    }
  }
  return;
}


// ==== FUN_006d1970 @ 0x006d1970 ====

void FUN_006d1970(undefined4 param_1,int param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uStack_c0;
  undefined4 uStack_a4;
  undefined1 uStack_a0;
  undefined1 uStack_9f;
  undefined4 uStack_9c;
  int iStack_98;
  void *pvStack_94;
  int iStack_90;
  int iStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  uint uStack_80;
  void *pvStack_78;
  undefined4 uStack_68;
  uint auStack_64 [2];
  undefined1 uStack_5c;
  undefined4 uStack_4c;
  void *pvStack_48;
  void *pvStack_44;
  void *pvStack_40;
  undefined1 auStack_38 [4];
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined1 uStack_28;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int *piStack_c;
  int *piStack_8;
  
  uStack_c0 = 0x6d1989;
  piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_c0 = 0xffffffff;
  uStack_9c._0_3_ = CONCAT12(1,(undefined2)uStack_9c);
  iStack_98 = 0;
  pvStack_94 = (void *)0x0;
  iStack_90 = 0;
  iStack_8c = 0;
  uStack_88 = 0;
  uStack_84 = 0;
  uStack_80 = 0;
  auStack_64[0] = 0xf;
  uStack_68 = 0;
  pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
  pvStack_48 = (void *)0xf;
  uStack_4c = 0;
  uStack_5c = 0;
  FUN_00401660(param_2 + 0x34,0);
  uStack_c0 = 0;
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
  FUN_00401660(auStack_64,0,0xffffffff);
  uStack_14 = 0xf;
  uStack_18 = 0;
  uStack_28 = 0;
  uStack_10 = 0;
  piStack_c = (int *)0x0;
  piStack_8 = (int *)0x0;
  FUN_00401740(s_pan_npc__d_009e4410,10);
  uVar4 = FUN_00404230(&pvStack_48);
  FUN_00401660(uVar4,0,0xffffffff);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  FUN_00401660(&uStack_2c,0,0xffffffff);
  pvStack_94 = (void *)(param_2 + -5);
  iStack_98 = param_3 + -5;
  iStack_8c = param_2 + 5;
  iStack_90 = param_3 + 5;
  uStack_9c = 100;
  uStack_a0 = 1;
  uStack_9f = 1;
  uStack_a4 = 0;
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_mainbar_minimap_009e441c,0xf);
  (**(code **)(*DAT_00b5a7c0 + 8))(&pvStack_48);
  if (0xf < uStack_34) {
    _free(pvStack_48);
    return;
  }
  puVar6 = &uStack_a4;
  (**(code **)(*piVar2 + 8))();
  if (piStack_8 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 0x74))(piStack_8);
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(*piStack_8 + 0x78))(piVar2);
      if (cVar1 == '\0') {
        (**(code **)(*piVar2 + 0x74))(0);
      }
      else {
        iVar5 = (**(code **)(*piStack_c + 0x38))();
        piVar2[1] = iVar5;
      }
    }
  }
  (**(code **)(*piVar3 + 0x38))(piVar2);
  (**(code **)(*piVar3 + 0x1c))(auStack_38);
  (**(code **)(*piVar2 + 0x2c))(piVar3);
  FUN_00587d40(&uStack_c0);
  puVar6[7] = puVar6[7] + 1;
  if (0xf < uStack_2c) {
    _free(pvStack_40);
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  if (0xf < auStack_64[0]) {
    _free(pvStack_78);
    return;
  }
  auStack_64[0] = 0xf;
  uStack_68 = 0;
  pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
  if (uStack_80 < 0x10) {
    return;
  }
  _free(pvStack_94);
  return;
}


// ==== FUN_006d1c40 @ 0x006d1c40 ====

void FUN_006d1c40(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  void *unaff_ESI;
  undefined1 auStack_1a [10];
  uint uStack_10;
  
  iVar3 = *DAT_00b5add0;
  uVar2 = (**(code **)(*DAT_00b5ae14 + 0x18))();
  cVar1 = (**(code **)(iVar3 + 0x3c))(uVar2);
  if (cVar1 != '\0') {
    iVar3 = *DAT_00b5acac;
    uVar2 = (**(code **)(*DAT_00b5a97c + 0xc))();
    cVar1 = (**(code **)(iVar3 + 0x44))(uVar2);
    if ((cVar1 != '\0') && (cVar1 = (**(code **)(*DAT_00b5add0 + 0x40))(), cVar1 != '\0')) {
      FUN_00401830(s_pan_map_009e443c);
      iVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1a + -10);
      if (0xf < uStack_10) {
        _free(unaff_ESI);
        return;
      }
      if (iVar3 != 0) {
        iVar4 = (**(code **)(*DAT_00b5adc8 + 4))();
        *(undefined4 *)(in_ECX + 0x20) = 0;
        FUN_006cfa00();
        while (iVar4 != 0) {
          FUN_006d1640(iVar3,iVar4);
          iVar4 = (**(code **)(*DAT_00b5adc8 + 8))();
        }
        FUN_006cfd00();
      }
    }
  }
  return;
}


// ==== FUN_006d1d20 @ 0x006d1d20 ====

undefined4 FUN_006d1d20(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 extraout_EAX;
  int *piVar4;
  undefined4 extraout_EAX_00;
  void *unaff_EBX;
  void *unaff_EDI;
  undefined1 auStack_36 [6];
  uint uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined1 auStack_24 [36];
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_close_009e45e0,9);
    if (iVar2 == 0) {
      (**(code **)(*DAT_00b5add0 + 0x14))();
      iVar2 = (**(code **)(*DAT_00b5a74c + 0xc))(0x1c);
      if (iVar2 == 0) {
        FUN_00401830(s_pUIHandler____NULL_009e45ec);
        FUN_00406880(auStack_36 + -6);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      piVar4 = *(int **)(iVar2 + 4);
      if (piVar4 == (int *)0x0) {
        FUN_00401830(s_pWindow____NULL_009e4600);
        FUN_00406880(auStack_36 + -6);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      FUN_00401830(s_btn_bigmap_show_009e4610);
      piVar3 = (int *)(**(code **)(*piVar4 + 0x34))(auStack_36 + -6);
      if (0xf < uStack_28) {
        _free(unaff_EBX);
        return extraout_EAX;
      }
      uStack_28 = 0xf;
      uStack_2c = 0;
      if (piVar3 == (int *)0x0) {
        FUN_00401830(s_pComposite____NULL_009e4620);
        FUN_00406880(auStack_24);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      (**(code **)(*piVar3 + 0x24))(1);
      FUN_00401830(s_btn_bigmap_hide_009e4634);
      piVar4 = (int *)(**(code **)(*piVar4 + 0x34))(auStack_36 + -0xe);
      if (0xf < uStack_30) {
        _free(unaff_EDI);
        return extraout_EAX_00;
      }
      if (piVar4 == (int *)0x0) {
        FUN_00401830(s_pComposite____NULL_009e4644);
        FUN_00406880(&uStack_2c);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      (**(code **)(*piVar4 + 0x24))(0);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_plus_009e4658);
    if (cVar1 != '\0') {
      FUN_006d08b0(0x14);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_minus_009e4664);
    if (cVar1 != '\0') {
      FUN_006d08b0(0xffffffec);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006d1f20 @ 0x006d1f20 ====

uint FUN_006d1f20(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0) {
    uVar1 = FUN_006d0e40(param_1);
    if ((char)uVar1 == '\x01') {
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006d1f50 @ 0x006d1f50 ====

void FUN_006d1f50(void)

{
  code *pcVar1;
  int *piVar2;
  float *pfVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5add0 + 0x48))();
  if (piVar2 != (int *)0x0) {
    pfVar3 = (float *)(**(code **)(*piVar2 + 0x28))();
    *(int *)(in_ECX + 8) = (int)*pfVar3;
    *(int *)(in_ECX + 0xc) = (int)pfVar3[1];
    puVar4 = (undefined4 *)(**(code **)(*piVar2 + 0x2c))();
    *(undefined4 *)(in_ECX + 0x10) = *puVar4;
    *(undefined4 *)(in_ECX + 0x14) = puVar4[1];
    FUN_006d0a00();
    FUN_006d0c10();
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_pActor____NULL_009e4684,0xe);
  FUN_00406880(auStack_1c);
  if (uStack_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_18);
  return;
}


// ==== FUN_006d1ff0 @ 0x006d1ff0 ====

/* WARNING: Removing unreachable block (ram,0x006d20bc) */

void FUN_006d1ff0(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined1 auStack_36 [22];
  void *pvStack_20;
  undefined1 uStack_1c;
  uint uStack_c;
  undefined4 uStack_8;
  
  iVar3 = *DAT_00b5add0;
  uVar2 = (**(code **)(*DAT_00b5ae14 + 0x18))();
  cVar1 = (**(code **)(iVar3 + 0x3c))(uVar2);
  if (cVar1 != '\0') {
    FUN_006cfb20();
    *(undefined4 *)(in_ECX + 0x28) = 0;
    uStack_8 = 0xf;
    uStack_c = 0;
    uStack_1c = 0;
    FUN_00401740(s_pan_map_009e4300,7);
    iVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return;
    }
    if (iVar3 != 0) {
      iVar4 = (**(code **)(*DAT_00b5ac98 + 0x7c))(auStack_36 + -10);
      while (iVar4 != 0) {
        FUN_006d1210(iVar3,auStack_36 + -0xe,iVar4);
        iVar4 = (**(code **)(*DAT_00b5ac98 + 0x80))(auStack_36 + -0xe);
      }
    }
  }
  return;
}


// ==== FUN_006d20d0 @ 0x006d20d0 ====

/* WARNING: Removing unreachable block (ram,0x006d2339) */

void FUN_006d20d0(void)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  uint uVar11;
  undefined1 auStack_be [34];
  short local_9c;
  undefined2 uStack_9a;
  undefined2 uStack_98;
  undefined1 auStack_94 [4];
  void *pvStack_90;
  undefined4 uStack_80;
  uint uStack_7c;
  undefined1 auStack_64 [28];
  undefined1 auStack_48 [72];
  
  uVar2 = (**(code **)(*DAT_00b5ae14 + 0x18))();
  cVar1 = (**(code **)(*DAT_00b5add0 + 0x44))(uVar2);
  if ((cVar1 != '\0') &&
     (piVar3 = (int *)(**(code **)(*DAT_00b5aaf4 + 4))(uVar2), piVar3 != (int *)0x0)) {
    uVar4 = (**(code **)(*piVar3 + 0x14))();
    uVar11 = 0;
    if (uVar4 != 0) {
      do {
        iVar7 = *DAT_00b5aaf0;
        uVar2 = (**(code **)(*piVar3 + 0x10))(uVar11);
        piVar5 = (int *)(**(code **)(iVar7 + 4))(uVar2);
        if (piVar5 != (int *)0x0) {
          puVar6 = (undefined4 *)(**(code **)(*piVar5 + 8))();
          uVar2 = *puVar6;
          local_9c = (short)uVar2;
          uStack_9a = (undefined2)((uint)uVar2 >> 0x10);
          uStack_98 = (undefined2)puVar6[1];
          iVar7 = (**(code **)(*DAT_00b5adcc + 0x10))(uVar2);
          if (iVar7 != 0) {
            iVar8 = (**(code **)(*DAT_00b5ada8 + 0x14))(CONCAT22(uStack_98,uStack_9a));
            if ((iVar8 != 0) && (*(char *)(iVar8 + 2) != '\0')) {
              if (local_9c == *(short *)(iVar8 + 4)) {
                uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(9,0x12c000c);
                FUN_00401660(uVar2,0,0xffffffff);
                FUN_00401830(s_<CHECKPOINT>_009e4308);
                FUN_00404440(auStack_be + -0xe,auStack_48,iVar7 + 0x34);
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(9,0x12c000b);
              FUN_00401660(uVar2,0,0xffffffff);
              FUN_00401830(s_<CHECKPOINT>_009e4324);
              FUN_00404440(auStack_be + -0xe,auStack_64,iVar7 + 0x34);
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            FUN_00401660(iVar7 + 0x34,0,0xffffffff);
            puVar10 = auStack_be + -6;
            uVar9 = 0x6e;
            FUN_00401740(s_pan_checkpoint__d_009e4334,0x11);
            uVar2 = FUN_00404230(auStack_94);
            FUN_006d0f30(uVar2,uVar9,puVar10);
            if (0xf < uStack_7c) {
              _free(pvStack_90);
              return;
            }
            uStack_7c = 0xf;
            uStack_80 = 0;
            pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
          }
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar4);
    }
  }
  return;
}


// ==== FUN_006d2380 @ 0x006d2380 ====

void FUN_006d2380(void)

{
  uint uVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  int in_ECX;
  uint uVar9;
  undefined4 uStack_b0;
  void *pvStack_ac;
  undefined1 uStack_a8;
  undefined4 uStack_a0;
  uint uStack_9c;
  uint uStack_98;
  int iStack_94;
  int *piStack_8c;
  uint local_88;
  undefined4 uStack_84;
  short sStack_80;
  undefined2 uStack_7e;
  undefined2 uStack_7c;
  undefined2 uStack_7a;
  undefined1 auStack_64 [100];
  
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  uVar3 = (**(code **)(*DAT_00b5ae14 + 0x18))();
  iStack_94 = 0xf;
  uStack_98 = 0;
  uStack_a8 = 0;
  FUN_00401740(s_pan_map_009e4348,7);
  iVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_ac);
  sStack_80 = (short)iVar4;
  uStack_7e = (undefined2)((uint)iVar4 >> 0x10);
  if (0xf < uStack_98) {
    _free(pvStack_ac);
    return;
  }
  if ((iVar4 != 0) &&
     (piVar5 = (int *)(**(code **)(*DAT_00b5aaf4 + 4))(uVar3), piVar5 != (int *)0x0)) {
    piStack_8c = piVar5;
    local_88 = (**(code **)(*piVar5 + 0x14))();
    uVar9 = 0;
    if (local_88 != 0) {
      do {
        iVar4 = *DAT_00b5aaf0;
        uVar3 = (**(code **)(*piVar5 + 0x10))(uVar9);
        piVar6 = (int *)(**(code **)(iVar4 + 4))(uVar3);
        if (piVar6 != (int *)0x0) {
          puVar7 = (undefined4 *)(**(code **)(*piVar6 + 8))();
          uVar3 = *puVar7;
          sStack_80 = (short)uVar3;
          sVar2 = sStack_80;
          uStack_7e = (undefined2)((uint)uVar3 >> 0x10);
          uStack_7c = (undefined2)puVar7[1];
          uStack_7a = (undefined2)((uint)puVar7[1] >> 0x10);
          iVar4 = (**(code **)(*DAT_00b5adcc + 0x10))(uVar3);
          if (iVar4 != 0) {
            uStack_98 = (uint)*(float *)(iVar4 + 8);
            iStack_94 = (int)*(float *)(iVar4 + 0xc);
            iVar8 = (**(code **)(*DAT_00b5ada8 + 0x14))(CONCAT22(uStack_7c,uStack_7e));
            uStack_9c = 0xf;
            uStack_a0 = 0;
            uVar1 = (uint)uStack_b0 >> 8;
            uStack_b0 = (void *)(uVar1 << 8);
            if ((iVar8 != 0) && (*(char *)(iVar8 + 2) != '\0')) {
              if (sVar2 == *(short *)(iVar8 + 4)) {
                uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(9,0x12c000c);
                FUN_00401660(uVar3,0,0xffffffff);
                FUN_00401830(s_<CHECKPOINT>_009e4350);
                FUN_00404440(auStack_64 + -0x58,&sStack_80,iVar4 + 0x34);
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(9,0x12c000b);
              FUN_00401660(uVar3,0,0xffffffff);
              FUN_00401830(s_<CHECKPOINT>_009e436c);
              FUN_00404440(auStack_64 + -0x58,auStack_64,iVar4 + 0x34);
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            FUN_00401660(iVar4 + 0x34,0,0xffffffff);
            FUN_006d0fa0(uStack_84,uStack_98,iStack_94,auStack_64 + -0x50,0x6e);
            if (0xf < uStack_9c) {
              _free(uStack_b0);
              return;
            }
            uStack_9c = 0xf;
            uStack_a0 = 0;
            uStack_b0 = (void *)(uVar1 << 8);
            piVar5 = piStack_8c;
          }
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < local_88);
    }
  }
  return;
}


// ==== FUN_006d2640 @ 0x006d2640 ====

undefined4 FUN_006d2640(int *param_1)

{
  uint uVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 < 0x70210012) {
    if (uVar1 == 0x70210011) {
      FUN_006d1c40();
      return 1;
    }
    if (uVar1 == 0x40001) {
      FUN_006d1f50(param_1);
      return 0;
    }
    if (uVar1 == 0x70210008) {
      FUN_006d01e0(param_1[1],CONCAT22(extraout_var_00,(short)param_1[2]),
                   CONCAT22(extraout_var,*(undefined2 *)((int)param_1 + 10)));
      return 1;
    }
    if (uVar1 == 0x70210009) {
      FUN_006d0620();
      return 1;
    }
  }
  else {
    if (uVar1 == 0x70210013) {
      FUN_006d1ff0();
      return 1;
    }
    if (uVar1 == 0x70210015) {
      FUN_006d20d0();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006d26f0 @ 0x006d26f0 ====

/* WARNING: Removing unreachable block (ram,0x006d2a6c) */
/* WARNING: Removing unreachable block (ram,0x006d2aba) */
/* WARNING: Removing unreachable block (ram,0x006d2b1c) */
/* WARNING: Removing unreachable block (ram,0x006d2940) */
/* WARNING: Removing unreachable block (ram,0x006d28f0) */
/* WARNING: Removing unreachable block (ram,0x006d299f) */
/* WARNING: Removing unreachable block (ram,0x006d280b) */

void FUN_006d26f0(void)

{
  float fVar1;
  code *pcVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  void *pvVar7;
  undefined4 *puVar8;
  undefined2 *puVar9;
  undefined4 uVar10;
  int in_ECX;
  uint unaff_ESI;
  undefined1 auStackY_100 [8];
  undefined1 auStack_ba [6];
  undefined1 *puStack_a8;
  undefined1 auStack_a4 [8];
  void *pvStack_80;
  uint uStack_7c;
  void *pvStack_78;
  undefined1 auStack_74 [4];
  void *pvStack_70;
  uint uStack_6c;
  undefined4 uStack_68;
  uint uStack_64;
  int local_60;
  void *local_5c;
  void *pvStack_58;
  void *pvStack_50;
  int *local_4c;
  uint local_48;
  uint uStack_44;
  uint uStack_3c;
  int iStack_38;
  int iStack_20;
  
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined1 *)(in_ECX + 0x18) = 0;
  local_48 = 0xf;
  local_4c = (int *)0x0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  FUN_00401740();
  FUN_00410500();
  if (0xf < local_48) {
    _free(local_5c);
    return;
  }
  piVar4 = (int *)(**(code **)(*DAT_00b5a798 + 4))();
  *(int **)(in_ECX + 4) = piVar4;
  (**(code **)(*piVar4 + 0x40))();
  (**(code **)(*DAT_00b5ae14 + 0xc))();
  if (iStack_20 != 0) {
    pvStack_58 = (void *)0xf;
    local_5c = (void *)0x0;
    uStack_6c = uStack_6c & 0xffffff00;
    FUN_00401740();
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if (0xf < local_5c) {
      _free(pvStack_70);
      return;
    }
    local_5c = (void *)0xf;
    local_60 = 0;
    pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
    if (piVar4 == (int *)0x0) {
      FUN_00401740();
      FUN_00406880();
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    iVar5 = (**(code **)(*piVar4 + 0x30))();
    if (iVar5 == 0) {
      pvStack_80 = (void *)0xf;
      FUN_00401740();
      FUN_00406880();
      if (pvStack_80 < (void *)0x10) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      _free((void *)(unaff_ESI & 0xffffff00));
      return;
    }
    FUN_0055a260();
  }
  pvStack_58 = (void *)0xf;
  local_5c = (void *)0x0;
  uStack_6c = uStack_6c & 0xffffff00;
  FUN_00401740();
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (0xf < local_5c) {
    _free(pvStack_70);
    return;
  }
  local_5c = (void *)0xf;
  local_60 = 0;
  pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
  if (piVar4 == (int *)0x0) {
    FUN_00401740();
    FUN_00406880();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  uStack_3c = (**(code **)(*piVar4 + 0x30))();
  if (uStack_3c == 0) {
    FUN_00401740();
    FUN_00406880();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  pvStack_80 = *(void **)(uStack_3c + 0x8c);
  uStack_7c = *(uint *)(uStack_3c + 0x90);
  pvStack_78 = *(void **)(uStack_3c + 0x94);
  FUN_00401740();
  pvStack_80 = (void *)(**(code **)(*DAT_00b5a7c0 + 8))();
  iVar5 = *DAT_00b5add0;
  (**(code **)(*DAT_00b5ae14 + 0x18))();
  uVar6 = (**(code **)(iVar5 + 0x4c))();
  pvStack_80 = (void *)(uVar6 & 0xffff);
  FUN_00587d40();
  uStack_68 = 0xf;
  uStack_6c = 0;
  uStack_7c = uStack_7c & 0xffffff00;
  FUN_00401740();
  local_4c = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (0xf < uStack_6c) {
    _free(pvStack_80);
    return;
  }
  uStack_6c = 0xf;
  pvStack_70 = (void *)0x0;
  pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
  if (local_4c == (int *)0x0) {
    FUN_00401740(s_pComposite____NULL_009e42a0);
    FUN_00406880();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  iVar5 = (**(code **)(*local_4c + 0x30))();
  if (iVar5 == 0) {
    FUN_00401740(s_pPanel____NULL_009e42b4);
    FUN_00406880();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  puStack_a8 = auStackY_100;
  FUN_00401740(s_minimap_009e42c4);
  (**(code **)(*DAT_00b5a7c0 + 8))();
  (**(code **)(*DAT_00b5ae14 + 0x18))();
  FUN_00587d40(auStack_a4 + 0x10);
  FUN_006d08b0(0);
  (**(code **)(*DAT_00b5ae14 + 0x10))(&pvStack_70);
  if (local_60 != 0) {
    pvVar7 = operator_new(0x10);
    if (pvVar7 == (void *)0x0) {
      puVar8 = (undefined4 *)0x0;
    }
    else {
      puVar8 = (undefined4 *)FUN_0081d3a0(auStack_74);
    }
    (**(code **)(*DAT_00b5adcc + 4))(puVar8);
    if (puVar8 != (undefined4 *)0x0) {
      (**(code **)*puVar8)(1);
    }
    puVar9 = (undefined2 *)(**(code **)(*DAT_00b5adcc + 8))();
    while (puVar9 != (undefined2 *)0x0) {
      iStack_38 = (int)*(float *)(puVar9 + 6);
      fVar1 = *(float *)(puVar9 + 4);
      piVar4 = (int *)(**(code **)(*DAT_00b5a770 + 8))
                                (CONCAT22((short)((uint)iStack_38 >> 0x10),*puVar9));
      if (piVar4 == (int *)0x0) {
        FUN_00401740(s_NotFound_NPC__d_009e42cc,0x10);
        uVar10 = FUN_00404230(auStack_ba + -6);
        FUN_00403e50(uVar10);
        if ((undefined1 *)0xf < puStack_a8) {
          _free(&pvStack_80);
          return;
        }
        if (0xf < uStack_64) {
          _free(pvStack_78);
          return;
        }
        uStack_64 = 0xf;
        uStack_68 = 0;
        pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
        if (uStack_44 < 0x10) {
          return;
        }
        _free(pvStack_58);
        return;
      }
      iVar5 = (**(code **)(*piVar4 + 4))();
      if (*(char *)(iVar5 + 0x11b) == '\x01') {
        FUN_006d1970(local_60,puVar9,(int)fVar1,uStack_3c);
      }
      puVar9 = (undefined2 *)(**(code **)(*DAT_00b5adcc + 0xc))();
    }
    uVar10 = (**(code **)(*DAT_00b5ae14 + 0x18))();
    cVar3 = (**(code **)(*DAT_00b5add0 + 0x44))(uVar10);
    if (cVar3 == '\0') {
      FUN_006d1c40();
      FUN_006cfc20(uVar10);
      FUN_006d1ff0();
    }
    else {
      FUN_006d2380();
    }
  }
  if (0xf < local_5c) {
    _free(pvStack_70);
    return;
  }
  local_5c = (void *)0xf;
  local_60 = 0;
  pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
  if (uStack_3c < 0x10) {
    return;
  }
  _free(pvStack_50);
  return;
}


// ==== FUN_006d2d30 @ 0x006d2d30 ====

void FUN_006d2d30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e4714;
  FUN_006d26f0();
  return;
}


// ==== FUN_006d2d50 @ 0x006d2d50 ====

undefined4 FUN_006d2d50(void)

{
  return 0x60000041;
}


// ==== FUN_006d2d60 @ 0x006d2d60 ====

undefined4 FUN_006d2d60(void)

{
  return 0x1d;
}


// ==== FUN_006d2d70 @ 0x006d2d70 ====

void FUN_006d2d70(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009e4714;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006d2db0 @ 0x006d2db0 ====

void FUN_006d2db0(void)

{
  return;
}


// ==== FUN_006d2dd0 @ 0x006d2dd0 ====

void FUN_006d2dd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e4e7c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006d2df0 @ 0x006d2df0 ====

void FUN_006d2df0(void)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 unaff_retaddr;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_sentry_009e494c,10);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar3 != (int *)0x0) {
    cVar2 = (**(code **)(*DAT_00b5add0 + 0x3c))(unaff_retaddr);
    if (cVar2 != '\0') {
      iVar1 = *DAT_00b5acac;
      uVar4 = (**(code **)(*DAT_00b5a97c + 0xc))();
      cVar2 = (**(code **)(iVar1 + 0x44))(uVar4);
      if (cVar2 != '\0') {
        cVar2 = (**(code **)(*DAT_00b5add0 + 0x40))();
        if (cVar2 == '\0') {
          (**(code **)(*piVar3 + 0x24))(0);
          return;
        }
        (**(code **)(*piVar3 + 0x24))(1);
        return;
      }
    }
    (**(code **)(*piVar3 + 0x24))(0);
  }
  return;
}


// ==== FUN_006d2ed0 @ 0x006d2ed0 ====

void FUN_006d2ed0(void)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int in_ECX;
  void **ppvVar7;
  undefined1 uVar8;
  void *apvStack_38 [4];
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  piVar4 = DAT_00b5ae14;
  sVar1 = (**(code **)(*DAT_00b5ae14 + 0x18))();
  sVar2 = (**(code **)(*piVar4 + 0x18))();
  if (sVar1 == sVar2) {
    FUN_00401740(s_pan_sentry__d_009e4a14,0xd);
    ppvVar7 = apvStack_38;
    uVar3 = FUN_00404230(ppvVar7);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar3);
    if (0xf < uStack_24) {
      _free(apvStack_38[0]);
      return;
    }
    uStack_24 = 0xf;
    uStack_28 = 0;
    apvStack_38[0] = (void *)((uint)apvStack_38[0] & 0xffffff00);
    while (piVar4 != (int *)0x0) {
      iVar5 = (**(code **)(*piVar4 + 0x3c))();
      if (iVar5 != 0) {
        piVar6 = (int *)(**(code **)(*piVar4 + 0x3c))();
        (**(code **)(*piVar6 + 0x7c))(piVar4);
      }
      uVar8 = 0;
      FUN_00401740(s_pan_sentry__d_009e4a24,0xd);
      uVar3 = FUN_00404230(auStack_20,ppvVar7,uVar8);
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar3);
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return;
      }
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    }
  }
  return;
}


// ==== FUN_006d2ff0 @ 0x006d2ff0 ====

void FUN_006d2ff0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  void **ppvVar5;
  undefined1 uVar6;
  void *local_38 [4];
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  FUN_00401740(s_pan_brick__d_009e4a34,0xc);
  ppvVar5 = local_38;
  uVar1 = FUN_00404230(ppvVar5);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar1);
  if (0xf < uStack_24) {
    _free(local_38[0]);
    return;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  local_38[0] = (void *)((uint)local_38[0] & 0xffffff00);
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return;
    }
    iVar3 = (**(code **)(*piVar2 + 0x3c))();
    if (iVar3 != 0) {
      piVar4 = (int *)(**(code **)(*piVar2 + 0x3c))();
      (**(code **)(*piVar4 + 0x7c))(piVar2);
    }
    uVar6 = 0;
    FUN_00401740(s_pan_brick__d_009e4a44,0xc);
    uVar1 = FUN_00404230(auStack_20,ppvVar5,uVar6);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar1);
    if (0xf < uStack_8) break;
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_006d30f0 @ 0x006d30f0 ====

void FUN_006d30f0(void)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  void *unaff_EBP;
  undefined4 unaff_retaddr;
  undefined4 local_38;
  undefined1 local_34;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  void *local_24;
  undefined4 local_20;
  void *pvStack_1c;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = 0;
  FUN_00401740(s_btn_bigmap_show_009e4af4,0xf);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = (void *)0xf;
  uStack_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  if (piVar2 == (int *)0x0) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e4b04,0x12);
    FUN_00406880(&local_20);
    if (uStack_8 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_1c);
    return;
  }
  (**(code **)(*piVar2 + 0x24))(unaff_retaddr);
  uStack_28 = 0xf;
  uStack_2c = 0;
  FUN_00401740(s_btn_bigmap_hide_009e4b18,0xf);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x40);
  if (0xf < uStack_2c) {
    _free(unaff_EBP);
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x24))((char)uStack_8 == '\0');
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_pComposite____NULL_009e4b28,0x12);
  FUN_00406880(&uStack_28);
  if (uStack_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_006d3240 @ 0x006d3240 ====

void FUN_006d3240(void)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  void *unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  void **ppvVar3;
  undefined1 auStack_3a [2];
  void *local_38;
  uint local_34;
  undefined4 uStack_30;
  void *pvStack_2c;
  undefined4 uStack_28;
  void *local_24;
  undefined4 local_20;
  void *pvStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = local_34 & 0xffffff00;
  FUN_00401740(s_btn_minimap_show_009e4b3c,0x10);
  ppvVar3 = &local_38;
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(ppvVar3);
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = (void *)0xf;
  uStack_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  if (piVar2 == (int *)0x0) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e4b50,0x12);
    FUN_00406880(&local_20);
    if (uStack_8 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_1c);
    return;
  }
  (**(code **)(*piVar2 + 0x24))(unaff_retaddr);
  uStack_28 = 0xf;
  pvStack_2c = (void *)0x0;
  FUN_00401740(s_btn_minimap_hide_009e4b64,0x10);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_3a + -6);
  if (0xf < pvStack_2c) {
    _free(unaff_EBX);
    return;
  }
  pvStack_2c = (void *)0xf;
  uStack_30 = 0;
  if (piVar2 == (int *)0x0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e4b78,0x12);
    FUN_00406880(&uStack_28);
    if (uStack_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_24);
    return;
  }
  (**(code **)(*piVar2 + 0x24))((char)uStack_8 == '\0');
  uStack_30 = 0xf;
  local_34 = 0;
  FUN_00401740(s_pan_minimap_009e4b8c,0xb);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_3a + -0xe);
  if (0xf < local_34) {
    _free((void *)CONCAT31((int3)((uint)unaff_ESI >> 8),(char)uStack_8 == '\0'));
    return;
  }
  local_34 = 0xf;
  local_38 = (void *)0x0;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x24))(ppvVar3);
    *(undefined1 *)(in_ECX + 0x20) = (undefined1)uStack_14;
    return;
  }
  uStack_18 = 0xf;
  pvStack_1c = (void *)0x0;
  pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
  FUN_00401740(s_pComposite____NULL_009e4b98,0x12);
  FUN_00406880(&uStack_30);
  if (uStack_18 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_2c);
  return;
}


// ==== FUN_006d3440 @ 0x006d3440 ====

void FUN_006d3440(void)

{
  FUN_006d3240();
  return;
}


// ==== FUN_006d3460 @ 0x006d3460 ====

/* WARNING: Removing unreachable block (ram,0x006d34d4) */

void FUN_006d3460(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int in_ECX;
  undefined1 auStack_36 [18];
  undefined4 uStack_24;
  void *pvStack_20;
  uint uStack_c;
  
  iVar1 = *DAT_00b5add0;
  uVar3 = (**(code **)(*DAT_00b5ae14 + 0x18))();
  cVar2 = (**(code **)(iVar1 + 0x3c))(uVar3);
  if ((cVar2 != '\0') && (cVar2 = (**(code **)(*DAT_00b5add0 + 0x40))(), cVar2 != '\0')) {
    uStack_24 = 0xf;
    FUN_00401740(s_lbl_sentry_009e4bbc,10);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_36 + -6);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x30))();
      piVar4 = DAT_00b5adc8;
      uVar3 = (**(code **)(*DAT_00b5adc8 + 0x14))();
      (**(code **)(*piVar4 + 0x18))(uVar3);
      FUN_00401830(s_<color_F9B600>_d<_color>____d_009e4bc8);
      FUN_00404230(&uStack_24);
      FUN_0055a260(&uStack_24);
      if (0xf < uStack_c) {
        _free(pvStack_20);
        return;
      }
    }
  }
  return;
}


// ==== FUN_006d3560 @ 0x006d3560 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d3560(void)

{
  code *pcVar1;
  float10 fVar2;
  char cVar3;
  undefined1 uVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int in_ECX;
  float10 fVar9;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int iStack_40;
  void *local_38;
  undefined1 local_34;
  undefined4 uStack_28;
  uint local_24;
  undefined4 local_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_pan_pointArrow_009e4be8,0xe);
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = 0xf;
  uStack_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  if (piVar5 == (int *)0x0) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e4bf8,0x12);
    FUN_00406880(&local_20);
    if (uStack_8 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_1c);
    return;
  }
  cVar3 = (**(code **)(*DAT_00b5ae58 + 8))();
  if (cVar3 != *(char *)(in_ECX + 0x21)) {
    iVar6 = (**(code **)(*piVar5 + 0x30))();
    if (iVar6 == 0) {
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      FUN_00401740(s_pPanel____NULL_009e4c0c,0xe);
      FUN_00406880(&local_20);
      if (uStack_8 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_1c);
      return;
    }
    uStack_48 = *(undefined4 *)(iVar6 + 0x8c);
    uStack_44 = *(undefined4 *)(iVar6 + 0x90);
    iStack_40 = *(undefined4 *)(iVar6 + 0x94);
    cVar3 = (**(code **)(*DAT_00b5ae58 + 8))();
    iStack_40 = (cVar3 != '\0') + 0x1e;
    FUN_00587d40(&uStack_48);
    uVar4 = (**(code **)(*DAT_00b5ae58 + 8))();
    *(undefined1 *)(in_ECX + 0x21) = uVar4;
  }
  fVar9 = (float10)FUN_0040d5f0(in_ECX + 0x18);
  fVar2 = (float10)_DAT_00b32f6c;
  puVar7 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar7 == (undefined4 *)0x0) {
    puVar7 = (undefined4 *)0x0;
  }
  else {
    uVar8 = (**(code **)(*piVar5 + 4))();
    *puVar7 = &PTR_FUN_009e46fc;
    puVar7[1] = uVar8;
  }
  puVar7[2] = (float)-(fVar9 - fVar2);
  (**(code **)(*DAT_00b5ad24 + 4))(puVar7);
  (**(code **)*puVar7)(1);
  return;
}


// ==== FUN_006d3710 @ 0x006d3710 ====

/* WARNING: Removing unreachable block (ram,0x006d396a) */

void FUN_006d3710(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  undefined1 auStack_aa [10];
  uint uStack_a0;
  void *pvStack_9c;
  void *pvStack_98;
  void *pvStack_94;
  uint uStack_88;
  void *pvStack_84;
  uint auStack_80 [3];
  undefined4 uStack_74;
  uint uStack_70;
  void *pvStack_68;
  undefined1 auStack_60 [8];
  void *local_58;
  uint uStack_54;
  undefined1 auStack_4c [4];
  int iStack_48;
  uint uStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  void *pvStack_2c;
  undefined4 uStack_1c;
  uint uStack_18;
  
  if ((*(int *)(in_ECX + 0x10) != *(int *)(in_ECX + 8)) ||
     (*(int *)(in_ECX + 0x14) != *(int *)(in_ECX + 0xc))) {
    *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0xc);
    *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 8);
    (**(code **)(*DAT_00b5ae14 + 0xc))(&local_58);
    if (iStack_48 == 0) {
      if (0xf < uStack_44) {
        _free(local_58);
        return;
      }
    }
    else {
      pvStack_98 = (void *)0xf;
      pvStack_9c = (void *)0x0;
      FUN_00401740(s_lbl_mapName_009e4c1c,0xb);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_aa + -6);
      if ((void *)0xf < pvStack_9c) {
        _free(unaff_EBX);
        return;
      }
      pvStack_9c = (void *)0xf;
      uStack_a0 = 0;
      if (piVar2 == (int *)0x0) {
        FUN_00401830(s_pComposite____NULL_009e4c28);
        FUN_00406880(&pvStack_98);
        if (auStack_80[0] < 0x10) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        _free(pvStack_94);
        return;
      }
      iVar3 = (**(code **)(*piVar2 + 0x30))();
      if (iVar3 == 0) {
        FUN_00401830(s_pLabel____NULL_009e4c3c);
        FUN_00406880(&pvStack_98);
        if (auStack_80[0] < 0x10) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        _free(pvStack_94);
        return;
      }
      FUN_0055a260(auStack_60);
      pvStack_9c = (void *)0xf;
      uStack_a0 = 0;
      FUN_00401740(s_lbl_position_009e4c4c,0xc);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_aa + -10);
      if (0xf < uStack_a0) {
        _free(unaff_EBP);
        return;
      }
      uStack_a0 = 0xf;
      if (piVar2 == (int *)0x0) {
        FUN_00401830(s_pComposite____NULL_009e4c5c);
        FUN_00406880(&pvStack_9c);
        if (pvStack_84 < (void *)0x10) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        _free(pvStack_98);
        return;
      }
      iVar3 = (**(code **)(*piVar2 + 0x30))();
      if (iVar3 == 0) {
        FUN_00401830(s_pLabel____NULL_009e4c70);
        FUN_00406880(&pvStack_9c);
        if (pvStack_84 < (void *)0x10) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        _free(pvStack_98);
        return;
      }
      FUN_00401740(s__d____d_009e4c80,7);
      FUN_00404230(auStack_80);
      FUN_0055a260(auStack_80);
      uStack_a0 = 0xf;
      FUN_00401740(s_pan_map_009e4c88,7);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_aa + -0xe);
      if (piVar2 == (int *)0x0) {
        FUN_00401830(s_pComposite____NULL_009e4c90);
        FUN_00406880(&uStack_a0);
        if (uStack_88 < 0x10) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        _free(pvStack_9c);
        return;
      }
      uVar4 = (**(code **)(*piVar2 + 0x10))();
      FUN_005041e0(uVar4);
      iStack_40 = -*(int *)(in_ECX + 8) + 0x52;
      uStack_44 = -*(int *)(in_ECX + 0xc) + 0x54;
      iStack_38 = -*(int *)(in_ECX + 8) + 0x252;
      iStack_3c = -*(int *)(in_ECX + 0xc) + 0x254;
      (**(code **)(*piVar2 + 0xc))(auStack_4c);
      if (0xf < uStack_18) {
        _free(pvStack_2c);
        return;
      }
      uStack_18 = 0xf;
      uStack_1c = 0;
      pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
      if (0xf < uStack_70) {
        _free(pvStack_84);
        return;
      }
      uStack_70 = 0xf;
      uStack_74 = 0;
      pvStack_84 = (void *)((uint)pvStack_84 & 0xffffff00);
      if (0xf < uStack_54) {
        _free(pvStack_68);
        return;
      }
    }
  }
  return;
}


// ==== FUN_006d3a90 @ 0x006d3a90 ====

void FUN_006d3a90(void)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int in_ECX;
  float fStack_c4;
  void *pvStack_b0;
  undefined1 uStack_ac;
  undefined4 uStack_a0;
  uint uStack_9c;
  undefined4 uStack_98;
  undefined1 auStack_5c [92];
  
  iVar3 = (**(code **)(*DAT_00b5ad98 + 0x10))();
  if (iVar3 != 0) {
    fVar1 = *(float *)(iVar3 + 0x18);
    uStack_98 = 0xf;
    uStack_9c = 0;
    uStack_ac = 0;
    FUN_00401740(s_pan_flag_009e4ccc,8);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_b0);
    if (0xf < uStack_9c) {
      _free(pvStack_b0);
      return;
    }
    uStack_9c = 0xf;
    uStack_a0 = 0;
    pvStack_b0 = (void *)((uint)pvStack_b0 & 0xffffff00);
    if (piVar4 != (int *)0x0) {
      if ((fStack_c4 == 0.0) && (fVar1 == 0.0)) {
        (**(code **)(*piVar4 + 0x24))(0);
        return;
      }
      cVar2 = (**(code **)(*DAT_00b5ad9c + 8))();
      if (cVar2 != '\0') {
        uVar5 = (**(code **)(*piVar4 + 0x10))();
        FUN_005041e0(uVar5);
        FUN_00401830(s_pan_minimap_bg_009e4cd8);
        (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_5c);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      (**(code **)(*piVar4 + 0x24))(0);
      return;
    }
  }
  return;
}


// ==== FUN_006d3cd0 @ 0x006d3cd0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006d3cd0(float param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 extraout_EAX;
  int *piVar5;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int iVar6;
  undefined4 *puVar7;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  int in_ECX;
  int iVar8;
  int *unaff_EBP;
  int iVar9;
  float10 fVar10;
  float unaff_retaddr;
  float fStack_cc;
  float fStack_c8;
  int iStack_bc;
  void *pvStack_b4;
  undefined1 uStack_b0;
  undefined4 uStack_a4;
  uint uStack_a0;
  undefined4 auStack_9c [2];
  int iStack_94;
  float fStack_90;
  int iStack_8c;
  int iStack_88;
  void *pvStack_84;
  void *pvStack_7c;
  uint uStack_70;
  uint uStack_68;
  void *local_58 [4];
  undefined4 uStack_48;
  uint uStack_44;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  void *pvStack_2c;
  undefined4 uStack_1c;
  uint uStack_18;
  float fStack_4;
  
  piVar4 = *(int **)(in_ECX + 4);
  FUN_00401740(s_pan_partyindicate__d_009e4ce8,0x14);
  uVar3 = FUN_00404230(local_58);
  piVar4 = (int *)(**(code **)(*piVar4 + 0x34))(uVar3);
  if (0xf < uStack_44) {
    _free(local_58[0]);
    return extraout_EAX;
  }
  uStack_44 = 0xf;
  uStack_48 = 0;
  local_58[0] = (void *)((uint)local_58[0] & 0xffffff00);
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  uVar3 = (**(code **)(*piVar4 + 0x10))();
  FUN_005041e0(uVar3);
  auStack_9c[0] = 0xf;
  uStack_a0 = 0;
  uStack_b0 = 0;
  FUN_00401740(s_pan_minimap_bg_009e4d00,0xe);
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_b4);
  if (0xf < uStack_a0) {
    _free(pvStack_b4);
    return extraout_EAX_00;
  }
  uStack_a0 = 0xf;
  uStack_a4 = 0;
  pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
  if (piVar5 == (int *)0x0) {
    (**(code **)(*piVar4 + 0x24))(0);
    if (uStack_68 < 0x10) {
      return 0;
    }
    _free(pvStack_7c);
    return extraout_EAX_01;
  }
  uVar3 = (**(code **)(*piVar5 + 0x10))();
  FUN_005041e0(uVar3);
  fStack_cc = (float)(int)unaff_retaddr;
  iVar9 = (int)param_1;
  iStack_bc = iStack_88 - (int)fStack_90;
  iVar8 = (iStack_34 - iStack_3c) / 2;
  iVar1 = *(int *)(in_ECX + 0xc);
  iVar2 = *(int *)(in_ECX + 8);
  iVar6 = (iStack_30 - iStack_38) / 2;
  if (iVar8 < iVar1 - iVar9) {
    iVar9 = iVar1 - iVar8;
  }
  else if (iVar8 < iVar9 - iVar1) {
    iVar9 = (iVar1 - (iStack_8c - iStack_94)) + iVar8;
  }
  if (iVar6 < iVar2 - (int)fStack_cc) {
    fStack_cc = (float)(iVar2 - iVar6);
  }
  else if (iVar6 < (int)fStack_cc - iVar2) {
    fStack_cc = (float)((iVar2 - iStack_bc) + iVar6);
  }
  if ((iVar9 == (int)param_1) && (fStack_cc == (float)(int)unaff_retaddr)) {
    (**(code **)(*unaff_EBP + 0x24))(0);
    FUN_00713830();
    FUN_00713830();
    return 0;
  }
  iStack_88 = (int)fStack_cc + iStack_bc;
  iStack_8c = iVar9 + (iStack_8c - iStack_94);
  auStack_9c[0] = CONCAT31(auStack_9c[0]._1_3_,1);
  iStack_94 = iVar9;
  fStack_90 = fStack_cc;
  (**(code **)(*unaff_EBP + 0xc))(auStack_9c);
  fStack_cc = unaff_retaddr - (float)(int)unaff_EBP;
  fStack_c8 = fStack_4 - (float)iVar9;
  if (_DAT_009e4e70 < SQRT(fStack_cc * fStack_cc + fStack_c8 * fStack_c8)) {
    thunk_FUN_0079de77(&fStack_cc,&fStack_cc);
  }
  fVar10 = (float10)FUN_0040d5f0(&fStack_cc);
  puVar7 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar7 == (undefined4 *)0x0) {
    puVar7 = (undefined4 *)0x0;
  }
  else {
    uVar3 = (**(code **)(*unaff_EBP + 4))();
    *puVar7 = &PTR_FUN_009e46fc;
    puVar7[1] = uVar3;
  }
  puVar7[2] = (float)fVar10;
  (**(code **)(*DAT_00b5ad24 + 4))(puVar7);
  (**(code **)*puVar7)(1);
  if (0xf < uStack_18) {
    _free(pvStack_2c);
    return extraout_EAX_02;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
  if (uStack_70 < 0x10) {
    return 1;
  }
  _free(pvStack_84);
  return extraout_EAX_03;
}


// ==== FUN_006d4020 @ 0x006d4020 ====

undefined4 FUN_006d4020(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined1 auStack_1c [28];
  
  iVar1 = (**(code **)(*DAT_00b5a6b0 + 8))();
  if (iVar1 == 1) {
    iVar1 = (**(code **)(*DAT_00b5ac1c + 0x20))();
    if (((iVar1 != 2) && (iVar1 = (**(code **)(*DAT_00b5ac1c + 0x20))(), iVar1 != 3)) &&
       (iVar1 = (**(code **)(*DAT_00b5ac1c + 0x20))(), iVar1 != 1)) {
      return 0;
    }
  }
  else {
    iVar1 = (**(code **)(*DAT_00b5ac1c + 0x20))();
    if (((iVar1 != 2) && (iVar1 = (**(code **)(*DAT_00b5ac1c + 0x20))(), iVar1 != 3)) &&
       (iVar1 = (**(code **)(*DAT_00b5ac1c + 0x20))(), iVar1 != 4)) {
      return 0;
    }
  }
  iVar1 = FUN_005897d0();
  iVar1 = FUN_00403620(0,*(undefined4 *)(iVar1 + 0x14),s_pan_map_009e4e44,7);
  if (iVar1 != 0) {
    return 0;
  }
  piVar2 = (int *)FUN_005897e0();
  if (((0 < *piVar2) && (0 < piVar2[1])) && ((*piVar2 < 0x200 && (piVar2[1] < 0x200)))) {
    FUN_00401830(s_setposition__d__d_009e4e4c);
    uVar3 = FUN_00404230(auStack_1c);
    FUN_00459340(uVar3);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  return 1;
}


// ==== FUN_006d4120 @ 0x006d4120 ====

void FUN_006d4120(undefined4 param_1,int param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uStack_c0;
  undefined4 uStack_a4;
  undefined1 uStack_a0;
  undefined1 uStack_9f;
  undefined4 uStack_9c;
  int iStack_98;
  void *pvStack_94;
  int iStack_90;
  int iStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  uint uStack_80;
  void *pvStack_78;
  undefined4 uStack_68;
  uint auStack_64 [2];
  undefined1 uStack_5c;
  undefined4 uStack_4c;
  void *pvStack_48;
  void *pvStack_44;
  void *pvStack_40;
  undefined1 auStack_38 [4];
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined1 uStack_28;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int *piStack_c;
  int *piStack_8;
  
  uStack_c0 = 0x6d4139;
  piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_c0 = 0xffffffff;
  uStack_9c._0_3_ = CONCAT12(1,(undefined2)uStack_9c);
  iStack_98 = 0;
  pvStack_94 = (void *)0x0;
  iStack_90 = 0;
  iStack_8c = 0;
  uStack_88 = 0;
  uStack_84 = 0;
  uStack_80 = 0;
  auStack_64[0] = 0xf;
  uStack_68 = 0;
  pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
  pvStack_48 = (void *)0xf;
  uStack_4c = 0;
  uStack_5c = 0;
  FUN_00401660(param_2 + 0x34,0);
  uStack_c0 = 0;
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
  FUN_00401660(auStack_64,0,0xffffffff);
  uStack_14 = 0xf;
  uStack_18 = 0;
  uStack_28 = 0;
  uStack_10 = 0;
  piStack_c = (int *)0x0;
  piStack_8 = (int *)0x0;
  FUN_00401740(s_pan_npc__d_009e4958,10);
  uVar4 = FUN_00404230(&pvStack_48);
  FUN_00401660(uVar4,0,0xffffffff);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  FUN_00401660(&uStack_2c,0,0xffffffff);
  pvStack_94 = (void *)(param_2 + -5);
  iStack_98 = param_3 + -5;
  iStack_8c = param_2 + 5;
  iStack_90 = param_3 + 5;
  uStack_9c = 100;
  uStack_a0 = 1;
  uStack_9f = 1;
  uStack_a4 = 0;
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_mainbar_minimap_009e4964,0xf);
  (**(code **)(*DAT_00b5a7c0 + 8))(&pvStack_48);
  if (0xf < uStack_34) {
    _free(pvStack_48);
    return;
  }
  puVar6 = &uStack_a4;
  (**(code **)(*piVar2 + 8))();
  if (piStack_8 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 0x74))(piStack_8);
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(*piStack_8 + 0x78))(piVar2);
      if (cVar1 == '\0') {
        (**(code **)(*piVar2 + 0x74))(0);
      }
      else {
        iVar5 = (**(code **)(*piStack_c + 0x38))();
        piVar2[1] = iVar5;
      }
    }
  }
  (**(code **)(*piVar3 + 0x38))(piVar2);
  (**(code **)(*piVar3 + 0x1c))(auStack_38);
  (**(code **)(*piVar2 + 0x2c))(piVar3);
  FUN_00587d40(&uStack_c0);
  puVar6[10] = puVar6[10] + 1;
  if (0xf < uStack_2c) {
    _free(pvStack_40);
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  if (0xf < auStack_64[0]) {
    _free(pvStack_78);
    return;
  }
  auStack_64[0] = 0xf;
  uStack_68 = 0;
  pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
  if (uStack_80 < 0x10) {
    return;
  }
  _free(pvStack_94);
  return;
}


// ==== FUN_006d43f0 @ 0x006d43f0 ====

void FUN_006d43f0(int param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  undefined1 auStack_9e [2];
  undefined4 uStack_88;
  undefined1 uStack_84;
  undefined1 uStack_83;
  undefined4 uStack_80;
  int iStack_7c;
  void *pvStack_78;
  int iStack_74;
  int iStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  uint uStack_64;
  undefined1 uStack_5c;
  undefined4 uStack_4c;
  void *pvStack_48;
  void *pvStack_44;
  void *pvStack_40;
  undefined1 auStack_38 [4];
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined1 uStack_28;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int *piStack_c;
  int *piStack_8;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_80._0_3_ = CONCAT12(1,(undefined2)uStack_80);
  iStack_7c = 0;
  pvStack_78 = (void *)0x0;
  iStack_74 = 0;
  iStack_70 = 0;
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  pvStack_48 = (void *)0xf;
  uStack_4c = 0;
  uStack_5c = 0;
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
  FUN_00401660(param_3,0);
  uStack_14 = 0xf;
  uStack_18 = 0;
  uStack_28 = 0;
  uStack_10 = 0;
  piStack_c = (int *)0x0;
  piStack_8 = (int *)0x0;
  FUN_00401740(s_pan_checkpoint__d_009e4974,0x11);
  uVar4 = FUN_00404230(&pvStack_48);
  FUN_00401660(uVar4,0);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  FUN_00401660(&uStack_2c,0);
  pvStack_78 = (void *)(param_1 + -5);
  iStack_7c = param_2 + -5;
  iStack_70 = param_1 + 5;
  iStack_74 = param_2 + 5;
  uStack_80 = 200;
  uStack_84 = 1;
  uStack_83 = 1;
  uStack_88 = 0;
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_pcpop_009e4988);
  (**(code **)(*DAT_00b5a7c0 + 8))();
  if (0xf < uStack_34) {
    _free(pvStack_48);
    return;
  }
  (**(code **)(*piVar2 + 8))(&uStack_88);
  if (piStack_8 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 0x74))(piStack_8);
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(*piStack_8 + 0x78))(piVar2);
      if (cVar1 == '\0') {
        (**(code **)(*piVar2 + 0x74))(0);
      }
      else {
        iVar5 = (**(code **)(*piStack_c + 0x38))();
        piVar2[1] = iVar5;
      }
    }
  }
  (**(code **)(*piVar3 + 0x38))(piVar2);
  (**(code **)(*piVar3 + 0x1c))(auStack_38);
  (**(code **)(*piVar2 + 0x2c))(piVar3);
  FUN_00587d40(auStack_9e + -6);
  *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + 1;
  if (0xf < uStack_2c) {
    _free(pvStack_40);
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  if (uStack_64 < 0x10) {
    return;
  }
  _free(pvStack_78);
  return;
}


// ==== FUN_006d4660 @ 0x006d4660 ====

void FUN_006d4660(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_10 = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    uStack_10 = *(undefined4 *)(iVar2 + 0x8c);
    uStack_c = *(undefined4 *)(iVar2 + 0x90);
    uStack_8 = param_1;
    FUN_00587d40(&uStack_10);
    FUN_00401660(param_1,0,0xffffffff);
  }
  return;
}


// ==== FUN_006d46d0 @ 0x006d46d0 ====

void FUN_006d46d0(void)

{
  float fVar1;
  uint uVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  int in_ECX;
  uint uVar10;
  undefined4 uStack_b4;
  void *pvStack_b0;
  undefined1 uStack_ac;
  undefined4 uStack_a4;
  uint uStack_a0;
  uint uStack_9c;
  int *piStack_98;
  uint local_94;
  undefined1 uStack_90;
  undefined4 uStack_8c;
  short sStack_88;
  undefined2 uStack_86;
  undefined2 uStack_84;
  undefined2 uStack_82;
  int iStack_7c;
  undefined1 auStack_64 [28];
  undefined1 auStack_48 [72];
  
  *(undefined4 *)(in_ECX + 0x34) = 0;
  uVar4 = (**(code **)(*DAT_00b5ae14 + 0x18))();
  piStack_98 = (int *)0xf;
  uStack_9c = 0;
  uStack_ac = 0;
  FUN_00401740(s_pan_map_009e49e0,7);
  iVar5 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_b0);
  sStack_88 = (short)iVar5;
  uStack_86 = (undefined2)((uint)iVar5 >> 0x10);
  if (0xf < uStack_9c) {
    _free(pvStack_b0);
    return;
  }
  if ((iVar5 != 0) &&
     (piVar6 = (int *)(**(code **)(*DAT_00b5aaf4 + 4))(uVar4), piVar6 != (int *)0x0)) {
    piStack_98 = piVar6;
    local_94 = (**(code **)(*piVar6 + 0x14))();
    uVar10 = 0;
    if (local_94 != 0) {
      do {
        iVar5 = *DAT_00b5aaf0;
        uVar4 = (**(code **)(*piVar6 + 0x10))(uVar10);
        piVar7 = (int *)(**(code **)(iVar5 + 4))(uVar4);
        if (piVar7 != (int *)0x0) {
          puVar8 = (undefined4 *)(**(code **)(*piVar7 + 8))();
          uVar4 = *puVar8;
          sStack_88 = (short)uVar4;
          sVar3 = sStack_88;
          uStack_86 = (undefined2)((uint)uVar4 >> 0x10);
          uStack_84 = (undefined2)puVar8[1];
          uStack_82 = (undefined2)((uint)puVar8[1] >> 0x10);
          iVar5 = (**(code **)(*DAT_00b5adcc + 0x10))(uVar4);
          if (iVar5 != 0) {
            iStack_7c = (int)*(float *)(iVar5 + 0xc);
            fVar1 = *(float *)(iVar5 + 8);
            iVar9 = (**(code **)(*DAT_00b5ada8 + 0x14))(CONCAT22(uStack_84,uStack_86));
            uStack_a0 = 0xf;
            uStack_a4 = 0;
            uVar2 = (uint)uStack_b4 >> 8;
            uStack_b4 = (void *)(uVar2 << 8);
            if ((iVar9 != 0) && (*(char *)(iVar9 + 2) != '\0')) {
              if (sVar3 == *(short *)(iVar9 + 4)) {
                uStack_90 = (**(code **)(*DAT_00b5ada8 + 0x4c))();
                uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(9,0x12c000c);
                FUN_00401660(uVar4,0,0xffffffff);
                FUN_00401830(s_<CHECKPOINT>_009e49e8);
                FUN_00404440(auStack_64 + -0x5c,auStack_48,iVar5 + 0x34);
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(9,0x12c000b);
              FUN_00401660(uVar4,0,0xffffffff);
              FUN_00401830(s_<CHECKPOINT>_009e4a04);
              FUN_00404440(auStack_64 + -0x5c,auStack_64,iVar5 + 0x34);
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            FUN_00401660(iVar5 + 0x34,0,0xffffffff);
            FUN_006d43f0(uStack_8c,(int)fVar1,iStack_7c,auStack_64 + -0x54,0x6e);
            if (0xf < uStack_a0) {
              _free(uStack_b4);
              return;
            }
            uStack_a0 = 0xf;
            uStack_a4 = 0;
            uStack_b4 = (void *)(uVar2 << 8);
            piVar6 = piStack_98;
          }
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < local_94);
    }
  }
  return;
}


// ==== FUN_006d4990 @ 0x006d4990 ====

void FUN_006d4990(undefined4 param_1,int *param_2)

{
  ushort uVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int *unaff_ESI;
  undefined4 *puVar8;
  undefined1 *puStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_ac;
  undefined1 uStack_a8;
  undefined1 uStack_a7;
  undefined4 uStack_a4;
  int iStack_a0;
  undefined4 uStack_9c;
  int iStack_98;
  int iStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  uint uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined1 uStack_78;
  void *pvStack_6c;
  void *pvStack_68;
  void *pvStack_64;
  undefined1 auStack_5c [4];
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  undefined1 uStack_4c;
  void *pvStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  uint auStack_28 [3];
  undefined1 auStack_1c [12];
  int *piStack_10;
  
  piVar6 = DAT_00b5ae14;
  uStack_c4 = 0x6d49b2;
  iVar4 = (**(code **)(*param_2 + 8))();
  uStack_c4 = 0x6d49bb;
  sVar3 = (**(code **)(*piVar6 + 0x18))();
  if (sVar3 == *(short *)(iVar4 + 6)) {
    uStack_c4 = 0x6d49d0;
    uStack_ac = (**(code **)(*DAT_00b5a7ac + 4))();
    uStack_9c._0_3_ = CONCAT12(1,(undefined2)uStack_9c);
    iStack_98 = 0;
    iStack_94 = 0;
    uStack_90 = 0;
    uStack_8c = 0;
    uStack_88 = 0;
    uStack_84 = 0;
    uStack_80 = 0;
    pvStack_64 = (void *)0xf;
    pvStack_68 = (void *)0x0;
    uStack_78 = 0;
    iVar4 = *DAT_00b5b180;
    uStack_c4 = 0x6d4a16;
    iVar5 = (**(code **)(*param_2 + 8))();
    uStack_c4 = CONCAT22((short)((uint)iVar5 >> 0x10),*(undefined2 *)(iVar5 + 4));
    puStack_c8 = auStack_1c;
    (**(code **)(iVar4 + 0xc))();
    piVar6 = (int *)(**(code **)(*DAT_00b5a7ac + 8))(0);
    FUN_00401660(auStack_28,0,0xffffffff);
    uStack_38 = 0xf;
    pvStack_3c = (void *)0x0;
    uStack_4c = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    FUN_00401740(s_pan_sentry__d_009e4a54,0xd);
    uVar7 = FUN_00404230(&pvStack_6c);
    FUN_00401660(uVar7,0,0xffffffff);
    if (0xf < uStack_54) {
      _free(pvStack_68);
      return;
    }
    FUN_00401660(&uStack_50,0,0xffffffff);
    iVar4 = (**(code **)(*param_2 + 8))();
    uVar1 = *(ushort *)(iVar4 + 8);
    iVar4 = (**(code **)(*param_2 + 8))();
    iStack_a0 = (int)((float)*(ushort *)(iVar4 + 10) * DAT_009b3508 - DAT_009b0120);
    uStack_9c = (void *)(int)((float)uVar1 * DAT_009b3508 - DAT_009b0120);
    iStack_94 = (int)uStack_9c + 10;
    iStack_98 = iStack_a0 + 10;
    uStack_a4 = 100;
    uStack_a8 = 1;
    uStack_a7 = 1;
    uStack_ac = 0;
    uStack_54 = 0xf;
    uStack_58 = 0;
    pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
    FUN_00401740(s_mainbar_minimap_009e4a64,0xf);
    (**(code **)(*DAT_00b5a7c0 + 8))(&pvStack_6c);
    if (0xf < uStack_58) {
      _free(pvStack_6c);
      return;
    }
    puVar8 = &uStack_ac;
    (**(code **)(*unaff_ESI + 8))();
    if (piStack_10 != (int *)0x0) {
      cVar2 = (**(code **)(*unaff_ESI + 0x74))(piStack_10);
      if (cVar2 != '\0') {
        cVar2 = (**(code **)(*piStack_10 + 0x78))(unaff_ESI);
        if (cVar2 == '\0') {
          (**(code **)(*unaff_ESI + 0x74))(0);
        }
        else {
          iVar4 = (**(code **)(*piStack_10 + 0x38))();
          unaff_ESI[1] = iVar4;
        }
      }
    }
    (**(code **)(*piVar6 + 0x38))(unaff_ESI);
    (**(code **)(*piVar6 + 0x1c))(auStack_5c);
    (**(code **)(*unaff_ESI + 0x2c))(piVar6);
    FUN_00587d40(&puStack_c8);
    puVar8[0xb] = puVar8[0xb] + 1;
    if (0xf < uStack_50) {
      _free(pvStack_64);
      return;
    }
    uStack_50 = 0xf;
    uStack_54 = 0;
    pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
    if (0xf < auStack_28[0]) {
      _free(pvStack_3c);
      return;
    }
    auStack_28[0] = 0xf;
    uStack_2c = 0;
    pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
    if (0xf < uStack_88) {
      _free(uStack_9c);
      return;
    }
  }
  return;
}


// ==== FUN_006d4cc0 @ 0x006d4cc0 ====

/* WARNING: Removing unreachable block (ram,0x006d4e96) */
/* WARNING: Removing unreachable block (ram,0x006d4fd0) */
/* WARNING: Removing unreachable block (ram,0x006d4e15) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d4cc0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 uVar5;
  void **ppvVar6;
  undefined4 uStack_118;
  undefined1 auStack_102 [10];
  int *piStack_f8;
  float fStack_ec;
  float fStack_e8;
  undefined4 uStack_e4;
  undefined1 auStack_e0 [4];
  uint uStack_dc;
  uint uStack_d8;
  undefined4 uStack_cc;
  void *pvStack_c8;
  undefined4 uStack_c4;
  int iStack_c0;
  int iStack_bc;
  int iStack_b8;
  uint uStack_b4;
  undefined1 uStack_aa;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  void *pvStack_8c;
  undefined1 uStack_88;
  uint uStack_78;
  undefined4 uStack_74;
  void *pvStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined1 auStack_64 [4];
  void *pvStack_60;
  uint uStack_5c;
  undefined4 uStack_50;
  uint uStack_4c;
  ushort uStack_38;
  undefined1 auStack_30 [16];
  undefined4 uStack_20;
  void *pvStack_1c;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  
  uStack_118 = 0x6d4cd9;
  (**(code **)(*DAT_00b5a7ac + 4))();
  uStack_aa = 1;
  uStack_a8 = 0;
  uStack_a4 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  uStack_98 = 0;
  uStack_94 = 0;
  uStack_90 = 0;
  uStack_74 = 0xf;
  uStack_78 = 0;
  uStack_88 = 0;
  uStack_118 = param_3;
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))();
  if ((piVar1 == (int *)0x0) || (iVar2 = (**(code **)(*piVar1 + 0xc))(), iVar2 != 5)) {
    if (uStack_78 < 0x10) {
      return;
    }
  }
  else {
    uStack_e4 = (**(code **)(*piVar1 + 0x14))();
    (**(code **)(*DAT_00b5ac98 + 0x78))(auStack_30);
    puVar3 = (uint *)(**(code **)(*piVar1 + 0x28))();
    uStack_dc = *puVar3;
    uStack_d8 = puVar3[1];
    piVar1 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
    uVar4 = uStack_38 | 0x1400000;
    uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,uVar4);
    pvStack_c8 = (void *)0xf;
    uStack_cc = 0;
    uStack_dc = uStack_dc & 0xffffff00;
    FUN_00401660(uVar5,0,0xffffffff);
    FUN_00401740(s__GUILDNAME__009e4a74,0xb);
    FUN_00404440(auStack_e0,auStack_102 + -0x12,uStack_10);
    FUN_00401740(s__ZEOLITENAME__009e4a80,0xd);
    ppvVar6 = &pvStack_60;
    uVar5 = (**(code **)(*piStack_f8 + 0x40))();
    FUN_00404440(&uStack_e4,&uStack_118,uVar5);
    if (0xf < uStack_4c) {
      _free(pvStack_60);
      return;
    }
    uStack_4c = 0xf;
    uStack_50 = 0;
    pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
    FUN_00401660(&uStack_e4,0,0xffffffff);
    uStack_74 = 0xf;
    uStack_78 = 0;
    uStack_88 = 0;
    pvStack_70 = (void *)0x0;
    uStack_6c = 0;
    uStack_68 = 0;
    FUN_00401740(s_pan_brick__d_009e4a90,0xc);
    uVar5 = FUN_00404230(auStack_64);
    FUN_00401660(uVar5,0,0xffffffff);
    if (0xf < uStack_4c) {
      _free(pvStack_60);
      return;
    }
    FUN_00401660(&pvStack_8c,0,0xffffffff);
    iStack_bc = (int)fStack_ec + -5;
    iStack_c0 = (int)fStack_e8 + -5;
    uStack_b4 = (int)fStack_ec + 6;
    iStack_b8 = (int)fStack_e8 + 6;
    pvStack_c8 = (void *)CONCAT31(pvStack_c8._1_3_,1);
    uStack_c4 = 200;
    FUN_00401740(s_war_occpuy_009e4aa0,10);
    (**(code **)(*DAT_00b5a7c0 + 8))(&uStack_118);
    (**(code **)(_DAT_00000000 + 8))(&uStack_cc);
    FUN_00557b50(uStack_20);
    (**(code **)(*piVar1 + 0x38))(uVar4);
    (**(code **)(*piVar1 + 0x1c))(&uStack_98);
    (**(code **)((int)*ppvVar6 + 0x2c))(piVar1);
    FUN_00587d40(auStack_102 + -10);
    iRam00000030 = iRam00000030 + 1;
    if (0xf < uStack_5c) {
      _free(pvStack_70);
      return;
    }
    uStack_5c = 0xf;
    pvStack_60 = (void *)0x0;
    pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
    if (0xf < uStack_b4) {
      _free(pvStack_c8);
      return;
    }
    uStack_b4 = 0xf;
    iStack_b8 = 0;
    pvStack_c8 = (void *)((uint)pvStack_c8 & 0xffffff00);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    if (uStack_78 < 0x10) {
      return;
    }
  }
  _free(pvStack_8c);
  return;
}


// ==== FUN_006d50f0 @ 0x006d50f0 ====

undefined4 FUN_006d50f0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_bigmap_show_009e4aac,0xf);
    if (iVar2 == 0) {
      FUN_006d30f0(0);
      (**(code **)(*DAT_00b5add0 + 0x10))();
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_bigmap_hide_009e4abc);
    if (cVar1 != '\0') {
      FUN_006d30f0(1);
      (**(code **)(*DAT_00b5add0 + 0x14))();
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_minimap_show_009e4acc);
    if (cVar1 != '\0') {
      FUN_006d3240(0);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_minimap_hide_009e4ae0);
    if (cVar1 != '\0') {
      FUN_006d3240(1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006d51c0 @ 0x006d51c0 ====

uint FUN_006d51c0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0) {
    uVar1 = FUN_006d4020(param_1);
    if ((char)uVar1 == '\x01') {
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006d51f0 @ 0x006d51f0 ====

void FUN_006d51f0(void)

{
  undefined4 ****ppppuVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  char *pcVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  undefined4 *****pppppuVar10;
  int iVar11;
  undefined4 *****in_ECX;
  char *pcVar12;
  undefined4 unaff_EBP;
  void **ppvVar13;
  undefined1 uVar14;
  uint uStack_98;
  undefined4 *****local_94;
  void *pvStack_90;
  undefined1 uStack_8c;
  undefined4 uStack_84;
  uint uStack_80;
  uint auStack_7c [3];
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  void *apvStack_3c [4];
  undefined4 uStack_2c;
  uint uStack_28;
  void *apvStack_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  if (DAT_00b5a7b4 == (int *)0x0) {
    return;
  }
  local_94 = in_ECX;
  piVar3 = (int *)(**(code **)(*DAT_00b5a7b4 + 0x58))();
  piVar4 = (int *)(**(code **)(*DAT_00b5ac1c + 0x14))();
  pcVar5 = (char *)(**(code **)(*piVar4 + 0x70))();
  auStack_7c[1] = 0xf;
  auStack_7c[0] = 0;
  uStack_8c = 0;
  pcVar12 = pcVar5;
  do {
    cVar2 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar2 != '\0');
  FUN_00401740(pcVar5,(int)pcVar12 - (int)(pcVar5 + 1));
  uStack_98 = 0;
  do {
    ppppuVar1 = in_ECX[1];
    FUN_00401740(s_pan_party__d_009e4ca4,0xc);
    ppvVar13 = apvStack_1c;
    uVar6 = FUN_00404230(ppvVar13);
    piVar4 = (int *)(*(code *)(*ppppuVar1)[0xd])(uVar6);
    if (0xf < uStack_8) {
      _free(apvStack_1c[0]);
      return;
    }
    ppppuVar1 = in_ECX[1];
    uStack_8 = 0xf;
    uStack_c = 0;
    apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
    uVar14 = 0;
    FUN_00401740(s_pan_partyindicate__d_009e4cb4,0x14);
    uVar6 = FUN_00404230(apvStack_3c,ppvVar13,uVar14);
    piVar7 = (int *)(*(code *)(*ppppuVar1)[0xd])(uVar6);
    if (0xf < uStack_28) {
      _free(apvStack_3c[0]);
      return;
    }
    uStack_28 = 0xf;
    uStack_2c = 0;
    apvStack_3c[0] = (void *)((uint)apvStack_3c[0] & 0xffffff00);
    if (piVar3 == (int *)0x0) {
      (**(code **)(*piVar4 + 0x24))(0);
      (**(code **)(*piVar7 + 0x24))(0);
LAB_006d54bd:
      (**(code **)(*piVar3 + 0xc))();
    }
    else {
      uVar8 = (**(code **)(*piVar3 + 0x10))();
      if (((uVar8 <= uStack_98) || (iVar9 = (**(code **)(*piVar3 + 4))(), iVar9 == 0)) ||
         (*(char *)(iVar9 + 0x4c) == '\0')) {
LAB_006d54a8:
        (**(code **)(*piVar4 + 0x24))(0);
        (**(code **)(*piVar7 + 0x24))(0);
        goto LAB_006d54bd;
      }
      pppppuVar10 = local_94;
      if (uStack_80 < 0x10) {
        pppppuVar10 = &local_94;
      }
      iVar11 = FUN_00403620(0,*(undefined4 *)(iVar9 + 0x24),pppppuVar10,uStack_84);
      if (iVar11 == 0) goto LAB_006d54a8;
      if ((*(float *)(iVar9 + 0x50) <= 0.0 && *(float *)(iVar9 + 0x50) != 0.0) ||
         (*(float *)(iVar9 + 0x54) <= 0.0 && *(float *)(iVar9 + 0x54) != 0.0)) {
        (**(code **)(*piVar4 + 0x24))(0);
        (**(code **)(*piVar7 + 0x24))(0);
        (**(code **)(*piVar3 + 0xc))();
      }
      else {
        cVar2 = FUN_006d3cd0(unaff_EBP,*(undefined4 *)(iVar9 + 0x50),*(undefined4 *)(iVar9 + 0x54));
        if (cVar2 == '\0') {
          uVar6 = (**(code **)(*piVar4 + 0x10))();
          FUN_005041e0(uVar6);
          iStack_6c = iStack_6c - auStack_7c[2];
          iStack_68 = iStack_68 - iStack_70;
          auStack_7c[2] = (uint)(*(float *)(iVar9 + 0x54) - (float)(iStack_6c / 2));
          iStack_70 = (int)(*(float *)(iVar9 + 0x50) - (float)(iStack_68 / 2));
          iStack_6c = auStack_7c[2] + iStack_6c;
          iStack_68 = iStack_70 + iStack_68;
          auStack_7c[0] = CONCAT31(auStack_7c[0]._1_3_,1);
          (**(code **)(*piVar4 + 0xc))(auStack_7c);
          (**(code **)(*piVar3 + 0xc))();
          FUN_00713830();
        }
        else {
          (**(code **)(*piVar4 + 0x24))(0);
          (**(code **)(*piVar3 + 0xc))();
        }
      }
    }
    uStack_98 = uStack_98 + 1;
    if (5 < uStack_98) {
      (**(code **)(*DAT_00b5a7b4 + 0x5c))(piVar3);
      if (auStack_7c[0] < 0x10) {
        return;
      }
      _free(pvStack_90);
      return;
    }
    in_ECX = local_94;
  } while( true );
}


// ==== FUN_006d5510 @ 0x006d5510 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d5510(void)

{
  int iVar1;
  float fVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  float unaff_EBP;
  float unaff_ESI;
  float10 fVar5;
  void *_Memory;
  undefined1 auStack_7a [10];
  uint auStack_70 [4];
  undefined4 uStack_60;
  void *pvStack_5c;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [4];
  undefined4 uStack_4c;
  uint uStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  void *pvStack_30;
  uint uStack_1c;
  
  fVar5 = (float10)(**(code **)(*DAT_00b5ac58 + 0x34))();
  pvStack_5c = (void *)0xf;
  uStack_60 = 0;
  auStack_70[0] = auStack_70[0] & 0xffffff00;
  FUN_00401740(s_Env_Time_009e4d18,9);
  (**(code **)(*DAT_00b5ac58 + 0x34))((double)(float)fVar5);
  FUN_00401740(s__f____f_009e4d10,7);
  fVar2 = (float)FUN_00404230(auStack_58);
  (**(code **)(*DAT_00b5a688 + 8))();
  if (0xf < uStack_48) {
    _free(pvStack_5c);
    return;
  }
  uStack_48 = 0xf;
  uStack_4c = 0;
  pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
  if (0xf < auStack_70[3]) {
    _free((void *)(float)fVar5);
    return;
  }
  if ((0.0 <= unaff_EBP) && (unaff_EBP < DAT_009b1840)) {
    if ((DAT_009b0ec4 < unaff_EBP) && (unaff_EBP < DAT_009e4eb8)) {
      FUN_00401830();
      (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    if ((unaff_EBP < DAT_009e4eb8) || (DAT_009b1840 < unaff_EBP)) {
      _Memory = (void *)(unaff_EBP + DAT_0099d0f8);
    }
    else {
      _Memory = (void *)(unaff_EBP - DAT_009e4eb8);
    }
    FUN_00401830();
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if (0xf < auStack_70[2]) {
      _free((void *)(float)fVar5);
      return;
    }
    auStack_70[2] = 0xf;
    auStack_70[1] = 0;
    if (piVar3 == (int *)0x0) {
      FUN_00401830(s_pComposite____NULL_009e4d7c);
      FUN_00406880(auStack_70 + 3);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    uVar4 = (**(code **)(*piVar3 + 0x10))();
    FUN_005041e0(uVar4);
    iStack_40 = (int)(unaff_ESI * _DAT_009e4eb0);
    iStack_38 = iStack_40 + 0x200;
    iStack_34 = iStack_3c + 0x2d;
    (**(code **)(*piVar3 + 0xc))(&uStack_48);
    iVar1 = iStack_44;
    FUN_00401830(s_pan_timebar1_009e4d90);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_7a + -10);
    if (0xf < auStack_70[0]) {
      _free(_Memory);
      return;
    }
    auStack_70[0] = 0xf;
    if (piVar3 == (int *)0x0) {
      FUN_00401830(s_pComposite____NULL_009e4da0);
      FUN_00406880(auStack_70 + 1);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    uVar4 = (**(code **)(*piVar3 + 0x10))();
    FUN_004fed70(uVar4);
    uStack_48 = iVar1 + 0x200;
    iStack_40 = iVar1 + 0x400;
    iStack_3c = iStack_44 + 0x2d;
    (**(code **)(*piVar3 + 0xc))(auStack_50);
    if (0xf < uStack_1c) {
      _free(pvStack_30);
      return;
    }
    if ((DAT_009b0ec4 <= fVar2) && (fVar2 <= DAT_009e4eb8)) {
      FUN_00401830(s_pan_time_sun_009e4db4);
      (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_70);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    if ((DAT_009c3184 < fVar2) && (fVar2 <= DAT_009b0ec8)) {
      FUN_00401830(s_pan_time_moon_009e4dfc);
      (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_70);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  return;
}


// ==== FUN_006d5b50 @ 0x006d5b50 ====

void FUN_006d5b50(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  void *unaff_ESI;
  undefined1 auStack_1a [10];
  uint uStack_10;
  
  iVar3 = *DAT_00b5add0;
  uVar2 = (**(code **)(*DAT_00b5ae14 + 0x18))();
  cVar1 = (**(code **)(iVar3 + 0x3c))(uVar2);
  if (cVar1 != '\0') {
    iVar3 = *DAT_00b5acac;
    uVar2 = (**(code **)(*DAT_00b5a97c + 0xc))();
    cVar1 = (**(code **)(iVar3 + 0x44))(uVar2);
    if ((cVar1 != '\0') && (cVar1 = (**(code **)(*DAT_00b5add0 + 0x40))(), cVar1 != '\0')) {
      FUN_00401830(s_pan_map_009e4990);
      iVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1a + -10);
      if (0xf < uStack_10) {
        _free(unaff_ESI);
        return;
      }
      if (iVar3 != 0) {
        iVar4 = (**(code **)(*DAT_00b5adc8 + 4))();
        *(undefined4 *)(in_ECX + 0x2c) = 0;
        FUN_006d2ed0();
        while (iVar4 != 0) {
          FUN_006d4990(iVar3,iVar4);
          iVar4 = (**(code **)(*DAT_00b5adc8 + 8))();
        }
        FUN_006d3460();
      }
    }
  }
  return;
}


// ==== FUN_006d5c30 @ 0x006d5c30 ====

/* WARNING: Removing unreachable block (ram,0x006d5cfc) */

void FUN_006d5c30(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined1 auStack_36 [22];
  void *pvStack_20;
  undefined1 uStack_1c;
  uint uStack_c;
  undefined4 uStack_8;
  
  iVar3 = *DAT_00b5add0;
  uVar2 = (**(code **)(*DAT_00b5ae14 + 0x18))();
  cVar1 = (**(code **)(iVar3 + 0x3c))(uVar2);
  if (cVar1 != '\0') {
    FUN_006d2ff0();
    *(undefined4 *)(in_ECX + 0x30) = 0;
    uStack_8 = 0xf;
    uStack_c = 0;
    uStack_1c = 0;
    FUN_00401740(s_pan_map_009e4998,7);
    iVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return;
    }
    if (iVar3 != 0) {
      iVar4 = (**(code **)(*DAT_00b5ac98 + 0x7c))(auStack_36 + -10);
      while (iVar4 != 0) {
        FUN_006d4cc0(iVar3,auStack_36 + -0xe,iVar4);
        iVar4 = (**(code **)(*DAT_00b5ac98 + 0x80))(auStack_36 + -0xe);
      }
    }
  }
  return;
}


// ==== FUN_006d5d10 @ 0x006d5d10 ====

/* WARNING: Removing unreachable block (ram,0x006d5f79) */

void FUN_006d5d10(void)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  uint uVar11;
  undefined1 auStack_be [34];
  short local_9c;
  undefined2 uStack_9a;
  undefined2 uStack_98;
  undefined1 auStack_94 [4];
  void *pvStack_90;
  undefined4 uStack_80;
  uint uStack_7c;
  undefined1 auStack_64 [28];
  undefined1 auStack_48 [72];
  
  uVar2 = (**(code **)(*DAT_00b5ae14 + 0x18))();
  cVar1 = (**(code **)(*DAT_00b5add0 + 0x44))(uVar2);
  if ((cVar1 != '\0') &&
     (piVar3 = (int *)(**(code **)(*DAT_00b5aaf4 + 4))(uVar2), piVar3 != (int *)0x0)) {
    uVar4 = (**(code **)(*piVar3 + 0x14))();
    uVar11 = 0;
    if (uVar4 != 0) {
      do {
        iVar7 = *DAT_00b5aaf0;
        uVar2 = (**(code **)(*piVar3 + 0x10))(uVar11);
        piVar5 = (int *)(**(code **)(iVar7 + 4))(uVar2);
        if (piVar5 != (int *)0x0) {
          puVar6 = (undefined4 *)(**(code **)(*piVar5 + 8))();
          uVar2 = *puVar6;
          local_9c = (short)uVar2;
          uStack_9a = (undefined2)((uint)uVar2 >> 0x10);
          uStack_98 = (undefined2)puVar6[1];
          iVar7 = (**(code **)(*DAT_00b5adcc + 0x10))(uVar2);
          if (iVar7 != 0) {
            iVar8 = (**(code **)(*DAT_00b5ada8 + 0x14))(CONCAT22(uStack_98,uStack_9a));
            if ((iVar8 != 0) && (*(char *)(iVar8 + 2) != '\0')) {
              if (local_9c == *(short *)(iVar8 + 4)) {
                uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(9,0x12c000c);
                FUN_00401660(uVar2,0,0xffffffff);
                FUN_00401830(s_<CHECKPOINT>_009e49a0);
                FUN_00404440(auStack_be + -0xe,auStack_48,iVar7 + 0x34);
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(9,0x12c000b);
              FUN_00401660(uVar2,0,0xffffffff);
              FUN_00401830(s_<CHECKPOINT>_009e49bc);
              FUN_00404440(auStack_be + -0xe,auStack_64,iVar7 + 0x34);
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            FUN_00401660(iVar7 + 0x34,0,0xffffffff);
            puVar10 = auStack_be + -6;
            uVar9 = 0x6e;
            FUN_00401740(s_pan_checkpoint__d_009e49cc,0x11);
            uVar2 = FUN_00404230(auStack_94);
            FUN_006d4660(uVar2,uVar9,puVar10);
            if (0xf < uStack_7c) {
              _free(pvStack_90);
              return;
            }
            uStack_7c = 0xf;
            uStack_80 = 0;
            pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
          }
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar4);
    }
  }
  return;
}


// ==== FUN_006d5fc0 @ 0x006d5fc0 ====

void FUN_006d5fc0(void)

{
  code *pcVar1;
  int *piVar2;
  float *pfVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5add0 + 0x48))();
  if (piVar2 != (int *)0x0) {
    pfVar3 = (float *)(**(code **)(*piVar2 + 0x28))();
    *(int *)(in_ECX + 8) = (int)*pfVar3;
    *(int *)(in_ECX + 0xc) = (int)pfVar3[1];
    puVar4 = (undefined4 *)(**(code **)(*piVar2 + 0x2c))();
    *(undefined4 *)(in_ECX + 0x18) = *puVar4;
    *(undefined4 *)(in_ECX + 0x1c) = puVar4[1];
    FUN_006d5510();
    FUN_006d3710();
    FUN_006d3560();
    FUN_006d51f0();
    FUN_006d3a90();
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_pActor____NULL_009e4bac,0xe);
  FUN_00406880(auStack_1c);
  if (uStack_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_18);
  return;
}


// ==== FUN_006d6070 @ 0x006d6070 ====

void FUN_006d6070(void)

{
  float fVar1;
  uint uVar2;
  code *pcVar3;
  char cVar4;
  ushort uVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  void *pvVar11;
  undefined4 *puVar12;
  undefined2 *puVar13;
  int iVar14;
  void *in_ECX;
  void *unaff_EBX;
  void **ppvVar15;
  void *_Memory;
  undefined4 uStack_a0;
  void **ppvStack_98;
  undefined4 local_70;
  void *local_6c;
  void *pvStack_64;
  uint uStack_60;
  void *pvStack_5c;
  void *pvStack_58;
  void *pvStack_54;
  uint uStack_50;
  void *pvStack_4c;
  void *pvStack_48;
  void *pvStack_44;
  void *pvStack_40;
  undefined4 uStack_3c;
  void *local_38;
  void *local_34;
  void *pvStack_30;
  uint uStack_2c;
  void *pvStack_28;
  uint local_24;
  void *local_20;
  uint local_1c;
  void *local_18;
  uint uStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  undefined4 local_8;
  uint local_4;
  
  *(undefined4 *)((int)in_ECX + 0x28) = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  local_6c = in_ECX;
  FUN_00401740();
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_20 = (void *)0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  local_70 = FUN_00410500();
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740();
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  uVar6 = (**(code **)(*DAT_00b5a798 + 4))();
  *(undefined4 *)((int)in_ECX + 4) = uVar6;
  uStack_c = 0xf;
  uStack_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740();
  if (0xf < uStack_c) {
    _free(local_20);
    return;
  }
  (**(code **)(**(int **)((int)in_ECX + 4) + 0x40))();
  *(undefined4 *)((int)in_ECX + 0x24) = 1;
  uStack_2c = 0xf;
  pvStack_30 = (void *)0x0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  ppvStack_98 = (void **)0x6d61ad;
  FUN_00401740();
  piVar7 = (int *)(**(code **)(**(int **)((int)in_ECX + 4) + 0x34))();
  if (0xf < pvStack_30) {
    ppvStack_98 = (void **)0x6d61ce;
    _free(pvStack_44);
    return;
  }
  pvStack_30 = (void *)0xf;
  local_34 = (void *)0x0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  if (piVar7 == (int *)0x0) {
    ppvStack_98 = (void **)s_pComposite____NULL_009e483c;
    uStack_14 = 0xf;
    local_18 = (void *)0x0;
    pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
    FUN_00401740();
    ppvStack_98 = (void **)0x6d6211;
    FUN_00406880();
    if (uStack_14 < 0x10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    ppvStack_98 = (void **)0x6d6224;
    _free(pvStack_28);
    return;
  }
  ppvStack_98 = (void **)0x6d6234;
  (**(code **)(*piVar7 + 0x24))();
  ppvStack_98 = (void **)0x10;
  local_34 = (void *)0xf;
  local_38 = (void *)0x0;
  pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
  uStack_a0 = (char *)0x6d624f;
  FUN_00401740();
  ppvStack_98 = &pvStack_4c;
  piVar7 = (int *)(**(code **)(**(int **)((int)in_ECX + 4) + 0x34))();
  if (0xf < local_38) {
    uStack_a0 = (char *)0x6d6270;
    _free(pvStack_4c);
    return;
  }
  local_38 = (void *)0xf;
  uStack_3c = 0;
  pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
  if (piVar7 == (int *)0x0) {
    uStack_a0 = s_pComposite____NULL_009e4864;
    local_1c = 0xf;
    local_20 = (void *)0x0;
    pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
    FUN_00401740();
    uStack_a0 = (char *)0x6d62b3;
    FUN_00406880();
    if (local_1c < 0x10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    uStack_a0 = (char *)0x6d62c6;
    _free(pvStack_30);
    return;
  }
  uStack_a0 = (char *)0x6d62d7;
  (**(code **)(*piVar7 + 0x24))();
  uStack_a0 = (char *)0xf;
  uStack_3c = 0xf;
  pvStack_40 = (void *)0x0;
  uStack_50 = uStack_50 & 0xffffff00;
  FUN_00401740();
  uStack_a0 = (char *)&pvStack_54;
  piVar7 = (int *)(**(code **)(**(int **)((int)in_ECX + 4) + 0x34))();
  if (0xf < pvStack_40) {
    _free(pvStack_54);
    return;
  }
  pvStack_40 = (void *)0xf;
  pvStack_44 = (void *)0x0;
  pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
  if (piVar7 == (int *)0x0) {
    local_24 = 0xf;
    pvStack_28 = (void *)0x0;
    local_38 = (void *)((uint)local_38 & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e4888);
    FUN_00406880();
    if (local_24 < 0x10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    _free(local_38);
    return;
  }
  (**(code **)(*piVar7 + 0x24))();
  pvStack_44 = (void *)0xf;
  pvStack_48 = (void *)0x0;
  pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
  FUN_00401740(s_btn_bigmap_hide_009e489c,0xf);
  ppvVar15 = &pvStack_5c;
  ppvStack_98 = (void **)(**(code **)(**(int **)((int)in_ECX + 4) + 0x34))();
  if (0xf < pvStack_48) {
    _free(pvStack_5c);
    return;
  }
  pvStack_48 = (void *)0xf;
  pvStack_4c = (void *)0x0;
  pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
  if (ppvStack_98 == (void **)0x0) {
    uStack_2c = 0xf;
    pvStack_30 = (void *)0x0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e48ac,0x12);
    FUN_00406880(&pvStack_44);
    if (uStack_2c < 0x10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    _free(pvStack_40);
    return;
  }
  (**(code **)((int)*ppvStack_98 + 0x24))(0);
  pvStack_4c = (void *)0xf;
  uStack_50 = 0;
  uStack_60 = uStack_60 & 0xffffff00;
  FUN_00401740(s_pan_minimap_bg_009e48c0,0xe);
  piVar7 = (int *)(**(code **)(**(int **)((int)in_ECX + 4) + 0x34))(&pvStack_64);
  if (0xf < uStack_50) {
    _free(pvStack_64);
    return;
  }
  uStack_50 = 0xf;
  pvStack_54 = (void *)0x0;
  pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
  if (piVar7 == (int *)0x0) {
    local_34 = (void *)0xf;
    local_38 = (void *)0x0;
    pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e48d0,0x12);
    FUN_00406880(&pvStack_4c);
    if (local_34 < 0x10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    _free(pvStack_48);
    return;
  }
  uStack_a0 = (char *)(**(code **)(*piVar7 + 0x30))();
  if (uStack_a0 == (char *)0x0) {
    local_34 = (void *)0xf;
    local_38 = (void *)0x0;
    pvStack_48 = (void *)((uint)pvStack_48._1_3_ << 8);
    FUN_00401740(s_pPanel____NULL_009e48e4,0xe);
    FUN_00406880(&pvStack_4c);
    if (local_34 < 0x10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    _free(pvStack_48);
    return;
  }
  iVar14 = *(int *)((int)uStack_a0 + 0x90);
  uVar2 = *(uint *)((int)uStack_a0 + 0x94);
  local_34 = (void *)0xf;
  local_38 = (void *)0x0;
  pvStack_48 = (void *)((uint)pvStack_48._1_3_ << 8);
  FUN_00401740(s_mainbar_minimap_009e48f4,0xf);
  (**(code **)(*DAT_00b5a7c0 + 8))(&pvStack_4c);
  if (0xf < local_38) {
    _free(pvStack_4c);
    return;
  }
  iVar9 = *DAT_00b5add0;
  uVar8 = (**(code **)(*DAT_00b5ae14 + 0x18))();
  uVar8 = uVar8 & 0xffff;
  uVar5 = (**(code **)(iVar9 + 0x4c))(uVar8);
  FUN_00587d40(&ppvStack_98);
  pvStack_5c = (void *)0xf;
  uStack_60 = 0;
  local_70 = local_70 & 0xffffff00;
  FUN_00401740(s_pan_map_009e4904,7);
  piVar7 = (int *)(**(code **)(*(int *)ppvVar15[1] + 0x34))((int)register0x00000010 + -0x74);
  if (0xf < uStack_60) {
    _free(unaff_EBX);
    return;
  }
  uStack_60 = 0xf;
  pvStack_64 = (void *)0x0;
  if (piVar7 == (int *)0x0) {
    pvStack_44 = (void *)0xf;
    pvStack_48 = (void *)0x0;
    pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e490c,0x12);
    FUN_00406880(&pvStack_5c);
    if (pvStack_44 < (void *)0x10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    _free(pvStack_58);
    return;
  }
  iVar9 = (**(code **)(*piVar7 + 0x30))();
  if (iVar9 == 0) {
    pvStack_44 = (void *)0xf;
    pvStack_48 = (void *)0x0;
    pvStack_58 = (void *)((uint)pvStack_58._1_3_ << 8);
    FUN_00401740(s_pPanel____NULL_009e4920,0xe);
    FUN_00406880(&pvStack_5c);
    if (pvStack_44 < (void *)0x10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    _free(pvStack_58);
    return;
  }
  uStack_a0 = *(char **)(iVar9 + 0x8c);
  ppvStack_98 = *(void ***)(iVar9 + 0x94);
  pvStack_44 = (void *)0xf;
  pvStack_48 = (void *)0x0;
  pvStack_58 = (void *)((uint)pvStack_58._1_3_ << 8);
  FUN_00401740(s_minimap_009e4930,7);
  ppvVar15 = &pvStack_5c;
  uStack_a0 = (char *)(**(code **)(*DAT_00b5a7c0 + 8))(ppvVar15);
  if (0xf < pvStack_48) {
    _free(pvStack_5c);
    return;
  }
  uVar10 = (**(code **)(*DAT_00b5ae14 + 0x18))();
  pvVar11 = (void *)(uVar10 & 0xffff);
  _Memory = (void *)0x0;
  FUN_00587d40((int)register0x00000010 + -0xa4);
  (**(code **)(*DAT_00b5ae14 + 0x10))((int)register0x00000010 + -0x9c);
  if (iVar14 == 0) {
    if (0xf < uVar2) {
      _free(pvVar11);
      return;
    }
  }
  else {
    pvVar11 = operator_new(0x10);
    if (pvVar11 == (void *)0x0) {
      puVar12 = (undefined4 *)0x0;
    }
    else {
      puVar12 = (undefined4 *)FUN_0081d3a0(&uStack_a0);
    }
    (**(code **)(*DAT_00b5adcc + 4))(puVar12);
    if (puVar12 != (undefined4 *)0x0) {
      (**(code **)*puVar12)(1);
    }
    puVar13 = (undefined2 *)(**(code **)(*DAT_00b5adcc + 8))();
    while (puVar13 != (undefined2 *)0x0) {
      fVar1 = *(float *)(puVar13 + 4);
      piVar7 = (int *)(**(code **)(*DAT_00b5a770 + 8))(*puVar13);
      if (piVar7 == (int *)0x0) {
        FUN_00401740(s_NotFound_NPC__d_009e4938,0x10);
        uVar6 = FUN_00404230(&local_70);
        FUN_00403e50(uVar6);
        if (0xf < pvStack_58) {
          _free(local_6c);
          return;
        }
        pvStack_58 = (void *)0xf;
        pvStack_5c = (void *)0x0;
        local_6c = (void *)((uint)local_6c & 0xffffff00);
      }
      else {
        iVar14 = (**(code **)(*piVar7 + 4))();
        if (*(char *)(iVar14 + 0x11b) == '\x01') {
          FUN_006d4120(ppvVar15,puVar13,(int)fVar1,uVar8);
        }
      }
      puVar13 = (undefined2 *)(**(code **)(*DAT_00b5adcc + 0xc))();
    }
    uVar6 = (**(code **)(*DAT_00b5ae14 + 0x18))();
    cVar4 = (**(code **)(*DAT_00b5add0 + 0x44))(uVar6);
    if (cVar4 == '\0') {
      FUN_006d5b50();
      FUN_006d2df0(uVar6);
    }
    else {
      FUN_006d46d0();
    }
    if (0xf < uVar5) {
      _free(_Memory);
      return;
    }
  }
  return;
}


// ==== FUN_006d68a0 @ 0x006d68a0 ====

undefined4 FUN_006d68a0(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 < 0x70210011) {
    if (uVar1 == 0x70210010) {
      FUN_006d5b50();
      uVar2 = (**(code **)(*DAT_00b5ae14 + 0x18))();
      FUN_006d2df0(uVar2);
      return 1;
    }
    if (uVar1 == 0x40001) {
      FUN_006d5fc0(param_1);
      return 0;
    }
    if (uVar1 == 0x70210007) {
      FUN_006d30f0((char)param_1[1]);
      return 1;
    }
  }
  else {
    if (uVar1 == 0x70210012) {
      FUN_006d5c30();
      return 1;
    }
    if (uVar1 == 0x70210014) {
      FUN_006d5d10();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006d6940 @ 0x006d6940 ====

void FUN_006d6940(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e4e7c;
  FUN_006d6070();
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 8) = 0;
  *(undefined1 *)((int)in_ECX + 0x21) = 0;
  in_ECX[4] = 0xffffffff;
  in_ECX[5] = 0xffffffff;
  return;
}


// ==== FUN_006d6980 @ 0x006d6980 ====

undefined4 FUN_006d6980(void)

{
  return 0x1c;
}


// ==== FUN_006d6990 @ 0x006d6990 ====

bool FUN_006d6990(void)

{
  int in_ECX;
  
  return *(char *)(in_ECX + 0x20) != '\0';
}


// ==== FUN_006d69a0 @ 0x006d69a0 ====

void FUN_006d69a0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009e4e7c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006d69e0 @ 0x006d69e0 ====

undefined4 FUN_006d69e0(void)

{
  return 0x106;
}


// ==== FUN_006d69f0 @ 0x006d69f0 ====

void FUN_006d69f0(void)

{
  return;
}


// ==== FUN_006d6a00 @ 0x006d6a00 ====

undefined4 FUN_006d6a00(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar1 = &PTR_FUN_009e5168;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_006d6a30 @ 0x006d6a30 ====

undefined1 FUN_006d6a30(void)

{
  return 0;
}


// ==== FUN_006d6a90 @ 0x006d6a90 ====

void FUN_006d6a90(void)

{
  char cVar1;
  code *pcVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  char *pcVar5;
  undefined2 extraout_var;
  int unaff_EBP;
  void **ppvStack_60;
  undefined4 local_4c;
  uint uStack_48;
  void *pvStack_40;
  uint uStack_3c;
  void *local_38;
  void *local_34;
  void *pvStack_30;
  uint uStack_2c;
  void *pvStack_28;
  void *local_24;
  uint local_20;
  void *pvStack_1c;
  uint uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  
  ppvStack_60 = (void **)0xb;
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_lbl_mapName_009e4f6c);
  ppvStack_60 = &local_38;
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = (void *)0xf;
  pvStack_28 = (void *)0x0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  if (piVar3 == (int *)0x0) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e4f78,0x12);
    FUN_00406880(&local_20);
    if (uStack_8 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_1c);
    return;
  }
  local_4c = (void *)(**(code **)(*piVar3 + 0x30))();
  if (local_4c == (void *)0x0) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_pLabel____NULL_009e4f8c,0xe);
    FUN_00406880(&local_20);
    if (uStack_8 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_1c);
    return;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5ab14 + 8))
                            (CONCAT22(extraout_var,*(undefined2 *)(in_ECX + 0x70)));
  iVar4 = (**(code **)(*piVar3 + 0x10))();
  pcVar5 = (char *)(iVar4 + 2);
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar4 + 2),(int)pcVar5 - (iVar4 + 3));
  FUN_0055a260(in_ECX + 0x54);
  pvStack_28 = (void *)0xf;
  uStack_2c = 0;
  uStack_3c = uStack_3c & 0xffffff00;
  FUN_00401740(s_pan_map_bg_009e4f9c,10);
  piVar3 = (int *)(**(code **)(**(int **)(unaff_EBP + 4) + 0x34))();
  if (0xf < uStack_2c) {
    _free(pvStack_40);
    return;
  }
  uStack_2c = 0xf;
  pvStack_30 = (void *)0x0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  if (piVar3 == (int *)0x0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e4fa8,0x12);
    FUN_00406880(&pvStack_28);
    if (uStack_10 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_24);
    return;
  }
  iVar4 = (**(code **)(*piVar3 + 0x30))();
  if (iVar4 == 0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    local_24 = (void *)((uint)local_24._1_3_ << 8);
    FUN_00401740(s_pPanel____NULL_009e4fbc,0xe);
    FUN_00406880(&pvStack_28);
    if (uStack_10 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_24);
    return;
  }
  local_4c = *(void **)(iVar4 + 0x90);
  uStack_48 = *(uint *)(iVar4 + 0x94);
  uStack_10 = 0xf;
  uStack_14 = 0;
  local_24 = (void *)((uint)local_24._1_3_ << 8);
  FUN_00401740(s_mainbar_minimap_009e4fcc,0xf);
  (**(code **)(*DAT_00b5a7c0 + 8))(&pvStack_28);
  if (0xf < uStack_14) {
    _free(pvStack_28);
    return;
  }
  local_4c = (void *)0x6e;
  FUN_00587d40((int)register0x00000010 + -0x54);
  local_34 = (void *)0xf;
  local_38 = (void *)0x0;
  uStack_48 = uStack_48 & 0xffffff00;
  FUN_00401740(s_pan_map_009e4fdc,7);
  piVar3 = (int *)(**(code **)(*(int *)ppvStack_60[1] + 0x34))(&local_4c);
  if ((void *)0xf < local_38) {
    _free(local_4c);
    return;
  }
  local_38 = (void *)0xf;
  uStack_3c = 0;
  local_4c = (void *)((uint)local_4c & 0xffffff00);
  if (piVar3 == (int *)0x0) {
    pvStack_1c = (void *)0xf;
    local_20 = 0;
    pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e4fe4,0x12);
    FUN_00406880(&local_34);
    if (pvStack_1c < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_30);
    return;
  }
  iVar4 = (**(code **)(*piVar3 + 0x30))();
  if (iVar4 != 0) {
    pvStack_1c = (void *)0xf;
    local_20 = 0;
    pvStack_30 = (void *)((uint)pvStack_30._1_3_ << 8);
    FUN_00401740(s_minimap_009e5008,7);
    (**(code **)(*DAT_00b5a7c0 + 8))(&local_34);
    if (local_20 < 0x10) {
      FUN_00587d40(&ppvStack_60);
      return;
    }
    _free(local_34);
    return;
  }
  pvStack_1c = (void *)0xf;
  local_20 = 0;
  pvStack_30 = (void *)((uint)pvStack_30._1_3_ << 8);
  FUN_00401740(s_pPanel____NULL_009e4ff8,0xe);
  FUN_00406880(&local_34);
  if (pvStack_1c < 0x10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _free(pvStack_30);
  return;
}


// ==== FUN_006d6e70 @ 0x006d6e70 ====

void FUN_006d6e70(void)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  void *local_38;
  undefined1 local_34;
  undefined4 uStack_28;
  uint local_24;
  undefined4 local_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_pan_map_009e5038,7);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = 0xf;
  uStack_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x70))();
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  FUN_00401740(s_pComposite____NULL_009e5040,0x12);
  FUN_00406880(&local_20);
  if (uStack_8 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_006d6f20 @ 0x006d6f20 ====

void FUN_006d6f20(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 auStack_3c [4];
  void *local_38;
  undefined1 local_34;
  undefined4 uStack_28;
  uint local_24;
  undefined4 local_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_text_out_009e5070,8);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = 0xf;
  uStack_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x30))();
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(&DAT_009e5079,0);
    puVar1 = *(undefined4 **)(in_ECX + 0x80);
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      FUN_00401740(&DAT_009e507c,0x22);
      uVar4 = FUN_00404230(auStack_3c);
      FUN_00401ff0(uVar4,0,0xffffffff);
      if (0xf < local_24) {
        _free(local_38);
        return;
      }
      local_24 = 0xf;
      uStack_28 = 0;
      local_38 = (void *)((uint)local_38 & 0xffffff00);
    }
    FUN_00401740(&DAT_009e50a0,0x24);
    uVar4 = FUN_00404230(auStack_3c);
    FUN_00401ff0(uVar4,0,0xffffffff);
    if (0xf < local_24) {
      _free(local_38);
      return;
    }
    FUN_005569f0(&local_20,0);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
  }
  return;
}


// ==== FUN_006d7100 @ 0x006d7100 ====

void FUN_006d7100(int param_1)

{
  uint *puVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  void *unaff_EBX;
  uint *puVar4;
  void *pvStack_80;
  undefined1 auStack_7c [8];
  undefined4 uStack_74;
  uint uStack_70;
  uint auStack_6c [22];
  undefined4 uStack_13;
  undefined4 uStack_f;
  byte bStack_b;
  
  if (DAT_00b5a6e4 != (int *)0x0) {
    puVar1 = (uint *)(**(code **)(*DAT_00b5a6e4 + 8))();
    puVar4 = auStack_6c + 2;
    for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar4 = puVar4 + 1;
    }
    param_1 = (uint)bStack_b + param_1;
    if (param_1 < 0x100) {
      if (param_1 < 0x3c) {
        param_1 = 0x3c;
      }
    }
    else {
      param_1 = 0xff;
    }
    bStack_b = (byte)param_1;
    auStack_6c[1] = 0xf;
    auStack_6c[0] = 0;
    auStack_7c[0] = 0;
    FUN_00401740(s_pan_map_bg_009e5114,10);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_80);
    if (0xf < auStack_6c[0]) {
      _free(pvStack_80);
      return;
    }
    auStack_6c[0] = 0xf;
    uStack_70 = 0;
    pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
    if (piVar2 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar2 + 0x30))();
      if (iVar3 != 0) {
        FUN_00587d10(uStack_f);
      }
    }
    auStack_6c[0] = 0xf;
    uStack_70 = 0;
    pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
    FUN_00401740(s_pan_map_009e5120,7);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_6c + -6);
    if (0xf < uStack_70) {
      _free(unaff_EBX);
      return;
    }
    uStack_70 = 0xf;
    uStack_74 = 0;
    if (piVar2 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar2 + 0x30))();
      if (iVar3 != 0) {
        FUN_00587d10(uStack_13);
      }
    }
    (**(code **)(*DAT_00b5a6e4 + 0x10))(auStack_6c);
  }
  return;
}


// ==== FUN_006d7250 @ 0x006d7250 ====

int FUN_006d7250(int param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int extraout_EAX;
  undefined4 uVar4;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int in_ECX;
  char *pcVar5;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(&DAT_009e5128,0);
  iVar3 = *(int *)(in_ECX + 0x18);
  if (iVar3 == 0) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a75c + 8))(param_2);
    if (piVar2 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar2 + 4))();
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      pcVar5 = (char *)(iVar3 + 2);
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      FUN_00401740((char *)(iVar3 + 2),(int)pcVar5 - (iVar3 + 3));
      FUN_00401660(auStack_1c,0,0xffffffff);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return extraout_EAX;
      }
    }
  }
  else if (iVar3 == 1) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a770 + 8))(param_2);
    if (piVar2 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar2 + 4))();
      uVar4 = FUN_00401830(iVar3 + 2);
      FUN_00401660(uVar4,0,0xffffffff);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return extraout_EAX_00;
      }
    }
  }
  else if (iVar3 == 2) {
    piVar2 = (int *)(**(code **)(*DAT_00b5abc8 + 8))(param_2);
    if (piVar2 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar2 + 4))();
      uVar4 = FUN_00401830(iVar3 + 2);
      FUN_00401660(uVar4,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  FUN_00401660(local_38,0,0xffffffff);
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_38,0,0xffffffff);
  if (local_20 < 0x10) {
    return param_1;
  }
  _free(local_34);
  return extraout_EAX_01;
}


// ==== FUN_006d73e0 @ 0x006d73e0 ====

undefined4 FUN_006d73e0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined1 local_1c [28];
  
  iVar1 = FUN_005897d0();
  iVar1 = FUN_00403620(0,*(undefined4 *)(iVar1 + 0x14),s_pan_map_009e512c,7);
  if (iVar1 != 0) {
    return 0;
  }
  piVar2 = (int *)FUN_005897e0();
  if ((((0 < *piVar2) && (0 < piVar2[1])) && (*piVar2 < 0x200)) && (piVar2[1] < 0x200)) {
    FUN_00401830(s_camera_target__d__d__d_009e5134);
    uVar3 = FUN_00404230(local_1c);
    FUN_00459340(uVar3);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  return 1;
}


// ==== FUN_006d7470 @ 0x006d7470 ====

uint FUN_006d7470(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0) {
    uVar1 = FUN_006d73e0(param_1);
    if ((char)uVar1 == '\x01') {
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006d74a0 @ 0x006d74a0 ====

void FUN_006d74a0(void)

{
  int *piVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  void *pvVar2;
  void *pvVar3;
  undefined1 auStack_38 [4];
  void *local_34;
  void *local_30;
  undefined4 local_2c;
  void *local_28;
  void *local_24;
  void *local_20;
  void *pvStack_1c;
  undefined4 uStack_14;
  uint local_10;
  uint local_c;
  uint uStack_8;
  
  local_30 = (void *)0x0;
  local_2c = 0;
  local_28 = (void *)0x0;
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(&DAT_009e5010,4);
  FUN_00406720(&local_24);
  if (0xf < local_c) {
    _free(local_20);
    return;
  }
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(s_Monster_009e5018,7);
  FUN_00406720(&local_24);
  if (0xf < local_c) {
    _free(local_20);
    return;
  }
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(&PTR_LAB_009e5020,3);
  FUN_00406720(&local_24);
  if (0xf < local_c) {
    _free(local_20);
    return;
  }
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(s_Brick_009e5024,5);
  FUN_00406720(&local_24);
  if (0xf < local_c) {
    _free(local_20);
    return;
  }
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(s_com_type_009e502c,8);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_24);
  if (0xf < local_10) {
    _free(local_24);
    return;
  }
  local_10 = 0xf;
  uStack_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    unaff_EBX = (**(code **)(*piVar1 + 0x30))();
    if (local_34 != local_30) {
      pvVar3 = (void *)0x0;
      pvVar2 = local_34;
      do {
        uStack_8 = 0xf;
        local_c = 0;
        pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
        local_28 = pvVar3;
        local_24 = pvVar3;
        FUN_00401660(pvVar2,0,0xffffffff);
        FUN_00577d70(&local_28,0);
        if (0xf < uStack_8) {
          _free(pvStack_1c);
          return;
        }
        pvVar2 = (void *)((int)pvVar2 + 0x1c);
        pvVar3 = (void *)((int)pvVar3 + 1);
        uStack_8 = 0xf;
        local_c = 0;
        pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      } while (pvVar2 != local_30);
    }
    FUN_00578700();
    FUN_00577df0(0);
  }
  if (local_34 == (void *)0x0) {
    return;
  }
  FUN_00405de0(local_34,local_30,auStack_38,unaff_EBX);
  _free(local_34);
  return;
}


// ==== FUN_006d76c0 @ 0x006d76c0 ====

void FUN_006d76c0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *pvVar4;
  undefined2 uVar5;
  uint local_2c;
  void *local_28;
  int local_24 [2];
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  local_24[0] = in_ECX + 0x78;
  FUN_004c4d40(&local_2c,&param_1);
  if (local_2c != *(uint *)(in_ECX + 0x80)) {
    FUN_006d9e20(param_2);
    return;
  }
  local_2c = *(uint *)(in_ECX + 0x84);
  if (0x13 < local_2c) {
    local_2c = 0x13;
  }
  pvVar2 = operator_new(0x34);
  uVar1 = param_2;
  pvVar4 = (void *)0x0;
  if (pvVar2 != (void *)0x0) {
    *(undefined4 *)((int)pvVar2 + 0x14) = 0;
    *(undefined4 *)((int)pvVar2 + 0x18) = 0xf;
    *(undefined1 *)((int)pvVar2 + 4) = 0;
    *(undefined4 *)((int)pvVar2 + 0x28) = 0;
    *(undefined4 *)((int)pvVar2 + 0x2c) = 0;
    *(undefined4 *)((int)pvVar2 + 0x30) = 0;
    *(undefined4 *)((int)pvVar2 + 0x20) = 0xffffffff;
    pvVar4 = pvVar2;
  }
  uVar5 = (undefined2)param_1;
  *(undefined2 *)((int)pvVar4 + 0x1c) = uVar5;
  uVar3 = FUN_006d7250(local_1c,param_1,param_2);
  FUN_00401660(uVar3,0,0xffffffff);
  if (local_4 < 0x10) {
    *(undefined4 *)((int)pvVar4 + 0x20) = *(undefined4 *)(local_2c * 4 + 0x9e4f00);
    FUN_006d9e20(uVar1);
    local_2c = CONCAT22(local_2c._2_2_,uVar5);
    local_28 = pvVar4;
    FUN_006d9b10(local_24,&local_2c);
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_006d77c0 @ 0x006d77c0 ====

void FUN_006d77c0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Maptool_ui_mapwnd_txt_009e4f50,0x18);
  piVar1 = (int *)FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(piVar1 + 0xf,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  FUN_006d74a0();
  FUN_006d6a90();
  FUN_006d7100(0);
  if (piVar1 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar1 + 4))();
    *(undefined4 *)(iVar3 + 0x28) = 0;
    (**(code **)(*DAT_00b5a7cc + 0x2c))(piVar1);
  }
  return;
}


// ==== FUN_006d7870 @ 0x006d7870 ====

void FUN_006d7870(void)

{
  char cVar1;
  undefined2 uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  int in_ECX;
  int iVar6;
  undefined2 extraout_var;
  float10 fVar7;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  void *apvStack_28 [5];
  uint uStack_14;
  float fStack_c;
  float fStack_8;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5ab14 + 8))(*(undefined2 *)(in_ECX + 0x70));
  iVar4 = (**(code **)(*piVar3 + 0x10))();
  pcVar5 = (char *)(iVar4 + 0xa6f);
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar4 + 0xa6f),(int)pcVar5 - (iVar4 + 0xa70));
  pcVar5 = (char *)(iVar4 + 2);
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar4 + 2),(int)pcVar5 - (iVar4 + 3));
  if (*(int *)(in_ECX + 0x4c) != 0) {
    piVar3 = (int *)FUN_00410500(in_ECX + 0x38);
    FUN_0049d760();
    FUN_006d8d40();
    cVar1 = FUN_0049d7c0();
    while (cVar1 == '\0') {
      FUN_0049d800(auStack_44);
      pvStack_50 = (void *)0x0;
      iStack_4c = 0;
      uStack_48 = 0;
      FUN_00404fb0(auStack_44,0x2c,auStack_54);
      if (pvStack_50 == (void *)0x0) {
        pvStack_50 = (void *)0x0;
        iStack_4c = 0;
        uStack_48 = 0;
        if (0xf < uStack_2c) {
          _free(pvStack_40);
          return;
        }
      }
      else {
        iVar4 = iStack_4c - (int)pvStack_50 >> 0x1f;
        iVar6 = (iStack_4c - (int)pvStack_50) / 0x1c + iVar4;
        if ((uint)(iVar6 - iVar4) < 2) {
          FUN_00405de0(pvStack_50,iStack_4c,auStack_54,piVar3);
          _free(pvStack_50);
          return;
        }
        if (iVar6 == iVar4) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uVar2 = thunk_FUN_00796f80(pvStack_50);
        *(undefined2 *)(in_ECX + 0x72) = uVar2;
        if ((pvStack_50 == (void *)0x0) || ((uint)((iStack_4c - (int)pvStack_50) / 0x1c) < 3)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        fVar7 = (float10)thunk_FUN_00796ec0((int)pvStack_50 + 0x38);
        fStack_c = (float)fVar7;
        if ((pvStack_50 == (void *)0x0) || ((uint)((iStack_4c - (int)pvStack_50) / 0x1c) < 4)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        fVar7 = (float10)thunk_FUN_00796ec0((int)pvStack_50 + 0x54);
        fStack_8 = (float)fVar7;
        FUN_006d76c0(CONCAT22(extraout_var,*(undefined2 *)(in_ECX + 0x72)),apvStack_28);
        if (pvStack_50 != (void *)0x0) {
          FUN_00405de0(pvStack_50,iStack_4c,auStack_54,piVar3);
          _free(pvStack_50);
          return;
        }
        pvStack_50 = (void *)0x0;
        iStack_4c = 0;
        uStack_48 = 0;
        if (0xf < uStack_2c) {
          _free(pvStack_40);
          return;
        }
      }
      uStack_48 = 0;
      iStack_4c = 0;
      pvStack_50 = (void *)0x0;
      uStack_2c = 0xf;
      uStack_30 = 0;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
      FUN_0049d780();
      cVar1 = FUN_0049d7c0();
    }
    iVar4 = (**(code **)(*piVar3 + 4))();
    *(undefined4 *)(iVar4 + 0x28) = 0;
    (**(code **)(*DAT_00b5a7cc + 0x2c))(piVar3);
    if (0xf < uStack_14) {
      _free(apvStack_28[0]);
      return;
    }
  }
  return;
}


// ==== FUN_006d7b20 @ 0x006d7b20 ====

void FUN_006d7b20(void)

{
  undefined2 uVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  int in_ECX;
  undefined2 *_Memory;
  void *pvVar7;
  undefined2 *puVar8;
  uint uVar9;
  float10 fVar10;
  float *pfVar11;
  int iStack_68;
  int iStack_64;
  int iStack_60;
  undefined2 auStack_54 [6];
  undefined1 auStack_48 [4];
  void *pvStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  undefined2 *puStack_34;
  undefined2 *puStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  piVar4 = (int *)(**(code **)(*DAT_00b5ab14 + 8))(*(undefined2 *)(in_ECX + 0x70));
  iVar5 = (**(code **)(*piVar4 + 0x10))();
  pcVar6 = (char *)(iVar5 + 0xb6f);
  do {
    cVar3 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar3 != '\0');
  FUN_00401740((char *)(iVar5 + 0xb6f),(int)pcVar6 - (iVar5 + 0xb70));
  pcVar6 = (char *)(iVar5 + 2);
  do {
    cVar3 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar3 != '\0');
  FUN_00401740((char *)(iVar5 + 2),(int)pcVar6 - (iVar5 + 3));
  if (*(int *)(in_ECX + 0x4c) != 0) {
    piVar4 = (int *)FUN_00410500(in_ECX + 0x38);
    FUN_0049d760();
    _Memory = (undefined2 *)0x0;
    iStack_64 = 0;
    puStack_34 = (undefined2 *)0x0;
    puStack_30 = (undefined2 *)0x0;
    uStack_2c = 0;
    cVar3 = FUN_0049d7c0();
    while (cVar3 == '\0') {
      FUN_0049d800(auStack_28);
      pvStack_44 = (void *)0x0;
      iStack_40 = 0;
      uStack_3c = 0;
      FUN_00404fb0(auStack_28,0x2c,auStack_48);
      if (pvStack_44 == (void *)0x0) {
        pvStack_44 = (void *)0x0;
        iStack_40 = 0;
        uStack_3c = 0;
        if (0xf < uStack_10) {
          _free(pvStack_24);
          return;
        }
      }
      else {
        uVar2 = (iStack_40 - (int)pvStack_44) / 0x1c;
        if (uVar2 < 2) {
          FUN_00405de0(pvStack_44,iStack_40,auStack_48,piVar4);
          _free(pvStack_44);
          return;
        }
        uVar9 = 1;
        iVar5 = iStack_40;
        pvVar7 = pvStack_44;
        if (iStack_64 == 0) {
          if (1 < uVar2) {
            iVar5 = 0x1c;
            do {
              if ((pvStack_44 == (void *)0x0) ||
                 ((uint)((iStack_40 - (int)pvStack_44) / 0x1c) <= uVar9)) {
                    /* WARNING: Subroutine does not return */
                FUN_00405ca0();
              }
              auStack_54[0] = thunk_FUN_00796f80((int)pvStack_44 + iVar5);
              FUN_006d9740(auStack_54);
              uVar9 = uVar9 + 1;
              iVar5 = iVar5 + 0x1c;
            } while (uVar9 < uVar2);
            iVar5 = iStack_40;
            _Memory = puStack_34;
            pvVar7 = pvStack_44;
          }
        }
        else if (1 < uVar2) {
          pfVar11 = (float *)(_Memory + 4);
          iStack_68 = 0x1c;
          do {
            if (iStack_64 == 2) {
              if ((pvVar7 == (void *)0x0) || ((uint)((iVar5 - (int)pvVar7) / 0x1c) <= uVar9)) {
                    /* WARNING: Subroutine does not return */
                FUN_00405ca0();
              }
              if ((_Memory == (undefined2 *)0x0) ||
                 ((uint)(((int)puStack_30 - (int)_Memory) / 0xc) <= uVar9 - 1)) {
                    /* WARNING: Subroutine does not return */
                FUN_0085b340();
              }
              fVar10 = (float10)thunk_FUN_00796ec0((int)pvVar7 + iStack_68);
              pfVar11[-1] = (float)fVar10;
LAB_006d7ddd:
              iVar5 = iStack_40;
              pvVar7 = pvStack_44;
            }
            else if (iStack_64 == 3) {
              if ((pvVar7 == (void *)0x0) || ((uint)((iVar5 - (int)pvVar7) / 0x1c) <= uVar9)) {
                    /* WARNING: Subroutine does not return */
                FUN_00405ca0();
              }
              if ((_Memory == (undefined2 *)0x0) ||
                 ((uint)(((int)puStack_30 - (int)_Memory) / 0xc) <= uVar9 - 1)) {
                    /* WARNING: Subroutine does not return */
                FUN_0085b340();
              }
              fVar10 = (float10)thunk_FUN_00796ec0((int)pvVar7 + iStack_68);
              *pfVar11 = (float)fVar10;
              goto LAB_006d7ddd;
            }
            pfVar11 = pfVar11 + 3;
            iStack_68 = iStack_68 + 0x1c;
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar2);
        }
        iStack_64 = iStack_64 + 1;
        if (pvVar7 != (void *)0x0) {
          FUN_00405de0(pvVar7,iVar5,auStack_48,piVar4);
          _free(pvStack_44);
          return;
        }
        pvStack_44 = (void *)0x0;
        iStack_40 = 0;
        uStack_3c = 0;
        if (0xf < uStack_10) {
          _free(pvStack_24);
          return;
        }
        in_ECX = iStack_60;
      }
      uStack_10 = 0xf;
      uStack_3c = 0;
      iStack_40 = 0;
      pvStack_44 = (void *)0x0;
      uStack_14 = 0;
      pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
      FUN_0049d780();
      cVar3 = FUN_0049d7c0();
    }
    puVar8 = _Memory;
    if (_Memory != puStack_30) {
      do {
        uStack_8 = *(undefined4 *)(puVar8 + 4);
        uStack_c = *(undefined4 *)(puVar8 + 2);
        uVar1 = *puVar8;
        uStack_10 = 0xf;
        uStack_14 = 0;
        pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
        *(undefined2 *)(in_ECX + 0x72) = uVar1;
        FUN_006d76c0(CONCAT22((short)((uint)uStack_8 >> 0x10),uVar1),auStack_28);
        if (0xf < uStack_10) {
          _free(pvStack_24);
          return;
        }
        puVar8 = puVar8 + 6;
        uStack_10 = 0xf;
        uStack_14 = 0;
        pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
      } while (puVar8 != puStack_30);
    }
    iVar5 = (**(code **)(*piVar4 + 4))();
    *(undefined4 *)(iVar5 + 0x28) = 0;
    (**(code **)(*DAT_00b5a7cc + 0x2c))(piVar4);
    if (_Memory != (undefined2 *)0x0) {
      _free(_Memory);
      return;
    }
  }
  return;
}


// ==== FUN_006d7f60 @ 0x006d7f60 ====

void FUN_006d7f60(void)

{
  uint uVar1;
  char cVar2;
  undefined2 uVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  int in_ECX;
  undefined2 extraout_var;
  float10 fVar7;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  void *apvStack_28 [5];
  uint uStack_14;
  float fStack_c;
  float fStack_8;
  
  piVar4 = (int *)(**(code **)(*DAT_00b5ab14 + 8))(*(undefined2 *)(in_ECX + 0x70));
  iVar5 = (**(code **)(*piVar4 + 0x10))();
  pcVar6 = (char *)(iVar5 + 0xc6f);
  do {
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  FUN_00401740((char *)(iVar5 + 0xc6f),(int)pcVar6 - (iVar5 + 0xc70));
  pcVar6 = (char *)(iVar5 + 2);
  do {
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  FUN_00401740((char *)(iVar5 + 2),(int)pcVar6 - (iVar5 + 3));
  if (*(int *)(in_ECX + 0x4c) != 0) {
    piVar4 = (int *)FUN_00410500(in_ECX + 0x38);
    FUN_0049d760();
    FUN_0049d780();
    FUN_006d8d40();
    cVar2 = FUN_0049d7c0();
    while (cVar2 == '\0') {
      FUN_0049d800(auStack_44);
      pvStack_50 = (void *)0x0;
      iStack_4c = 0;
      uStack_48 = 0;
      FUN_00404fb0(auStack_44,0x2c,auStack_54);
      if (pvStack_50 == (void *)0x0) {
        pvStack_50 = (void *)0x0;
        iStack_4c = 0;
        uStack_48 = 0;
        if (0xf < uStack_2c) {
          _free(pvStack_40);
          return;
        }
      }
      else {
        uVar1 = (iStack_4c - (int)pvStack_50) / 0x1c;
        if (uVar1 < 2) {
          FUN_00405de0(pvStack_50,iStack_4c,auStack_54,piVar4);
          _free(pvStack_50);
          return;
        }
        if (uVar1 < 2) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uVar3 = thunk_FUN_00796f80((int)pvStack_50 + 0x1c);
        *(undefined2 *)(in_ECX + 0x72) = uVar3;
        if ((pvStack_50 == (void *)0x0) || ((uint)((iStack_4c - (int)pvStack_50) / 0x1c) < 6)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        fVar7 = (float10)thunk_FUN_00796ec0((int)pvStack_50 + 0x8c);
        fStack_c = (float)fVar7;
        if ((pvStack_50 == (void *)0x0) || ((uint)((iStack_4c - (int)pvStack_50) / 0x1c) < 7)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        fVar7 = (float10)thunk_FUN_00796ec0((int)pvStack_50 + 0xa8);
        fStack_8 = (float)fVar7;
        FUN_006d76c0(CONCAT22(extraout_var,*(undefined2 *)(in_ECX + 0x72)),apvStack_28);
        if (pvStack_50 != (void *)0x0) {
          FUN_00405de0(pvStack_50,iStack_4c,auStack_54,piVar4);
          _free(pvStack_50);
          return;
        }
        pvStack_50 = (void *)0x0;
        iStack_4c = 0;
        uStack_48 = 0;
        if (0xf < uStack_2c) {
          _free(pvStack_40);
          return;
        }
      }
      uStack_48 = 0;
      iStack_4c = 0;
      pvStack_50 = (void *)0x0;
      uStack_2c = 0xf;
      uStack_30 = 0;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
      FUN_0049d780();
      cVar2 = FUN_0049d7c0();
    }
    iVar5 = (**(code **)(*piVar4 + 4))();
    *(undefined4 *)(iVar5 + 0x28) = 0;
    (**(code **)(*DAT_00b5a7cc + 0x2c))(piVar4);
    if (0xf < uStack_14) {
      _free(apvStack_28[0]);
      return;
    }
  }
  return;
}


// ==== FUN_006d8220 @ 0x006d8220 ====

void FUN_006d8220(undefined2 param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009e517c;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0xf;
  *(undefined1 *)(in_ECX + 8) = 0;
  in_ECX[0x14] = 0xf;
  in_ECX[0x13] = 0;
  *(undefined1 *)(in_ECX + 0xf) = 0;
  in_ECX[0x1b] = 0xf;
  in_ECX[0x1a] = 0;
  *(undefined1 *)(in_ECX + 0x16) = 0;
  *(undefined1 *)(in_ECX + 0x1e) = (undefined1)param_1;
  uVar1 = FUN_006d8b00();
  in_ECX[0x20] = uVar1;
  in_ECX[0x21] = 0;
  local_4 = in_ECX[0x20];
  FUN_006d9470(9,&local_4);
  in_ECX[0x26] = 1;
  in_ECX[0x27] = 1;
  *(undefined2 *)(in_ECX + 0x1c) = param_1;
  *(undefined2 *)((int)in_ECX + 0x72) = 0;
  in_ECX[6] = 0;
  FUN_006d77c0();
  return;
}


// ==== FUN_006d82c0 @ 0x006d82c0 ====

void FUN_006d82c0(undefined4 param_1,uint param_2)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  void *pvVar6;
  uint *_Memory;
  int iVar7;
  int *unaff_EBX;
  undefined1 local_a4 [4];
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  int iStack_98;
  int iStack_94;
  int iStack_90;
  int iStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined1 uStack_78;
  undefined4 uStack_68;
  undefined4 auStack_64 [2];
  undefined1 uStack_5c;
  undefined4 uStack_4c;
  void *pvStack_48;
  void *pvStack_44;
  undefined1 auStack_38 [4];
  uint uStack_34;
  uint uStack_30;
  undefined1 auStack_2c [4];
  undefined1 uStack_28;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int *piStack_c;
  int *piStack_8;
  
  uStack_a0 = (**(code **)(*DAT_00b5a7ac + 4))();
  uStack_9c._0_3_ = CONCAT12(1,(undefined2)uStack_9c);
  iStack_98 = 0;
  iStack_94 = 0;
  iStack_90 = 0;
  iStack_8c = 0;
  uStack_88 = 0;
  uStack_84 = 0;
  uStack_80 = 0;
  auStack_64[0] = 0xf;
  uStack_68 = 0;
  uStack_78 = 0;
  pvStack_48 = (void *)0xf;
  uStack_4c = 0;
  uStack_5c = 0;
  FUN_00401660(param_2,0,0xffffffff);
  piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 8))(0);
  FUN_00401660(auStack_64,0,0xffffffff);
  uStack_14 = 0xf;
  uStack_18 = 0;
  uStack_28 = 0;
  uStack_10 = 0;
  piStack_c = (int *)0x0;
  piStack_8 = (int *)0x0;
  FUN_00401740(s_pan_mon__d_009e50c8,10);
  uVar3 = FUN_00404230(&pvStack_48);
  FUN_00401660(uVar3,0,0xffffffff);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  FUN_00401660(auStack_2c,0,0xffffffff);
  uVar4 = FUN_00802534();
  uVar5 = FUN_00802534();
  iStack_94 = (uVar5 & 0xffff) - 4;
  iStack_8c = (uVar5 & 0xffff) + 4;
  iStack_90 = (uVar4 & 0xffff) + 4;
  uStack_9c = 100;
  uStack_a0 = CONCAT22(uStack_a0._2_2_,0x101);
  iStack_98 = (uVar4 & 0xffff) - 4;
  pvVar6 = operator_new(0x468);
  if (pvVar6 == (void *)0x0) {
    _Memory = (uint *)0x0;
  }
  else {
    _Memory = (uint *)FUN_00505f10();
  }
  FUN_00503950(*(undefined4 *)(_Memory[0x47] + 4));
  *(uint *)(_Memory[0x47] + 4) = _Memory[0x47];
  _Memory[0x48] = 0;
  *(uint *)_Memory[0x47] = _Memory[0x47];
  *(uint *)(_Memory[0x47] + 8) = _Memory[0x47];
  *(undefined1 *)(_Memory + 0x45) = 0;
  *(undefined1 *)((int)_Memory + 0x115) = 0;
  *_Memory = param_2 | 0xff000000;
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_mainbar_minimap_009e50d4,0xf);
  uVar4 = (**(code **)(*DAT_00b5a7c0 + 8))(&pvStack_48);
  _Memory[1] = uVar4;
  if (0xf < uStack_34) {
    _free(pvStack_48);
    return;
  }
  _Memory[2] = 0x78;
  (**(code **)(*unaff_EBX + 8))(local_a4);
  if (piStack_8 != (int *)0x0) {
    cVar1 = (**(code **)(*unaff_EBX + 0x74))(piStack_8);
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(*piStack_8 + 0x78))(unaff_EBX);
      if (cVar1 == '\0') {
        (**(code **)(*unaff_EBX + 0x74))(0);
      }
      else {
        iVar7 = (**(code **)(*piStack_c + 0x38))();
        unaff_EBX[1] = iVar7;
      }
    }
  }
  (**(code **)(*piVar2 + 0x38))(unaff_EBX);
  (**(code **)(*piVar2 + 0x1c))(auStack_38);
  (**(code **)(*unaff_EBX + 0x2c))(piVar2);
  (**(code **)(*piVar2 + 0x24))(_Memory);
  FUN_00505d80();
  _free(_Memory);
  return;
}


// ==== FUN_006d8600 @ 0x006d8600 ====

void FUN_006d8600(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  if (*(int *)(in_ECX + 0x84) != 0) {
    piVar1 = *(int **)(in_ECX + 0x80);
    piVar2 = (int *)*piVar1;
    if (piVar2 != piVar1) {
      do {
        FUN_006d9eb0(piVar2 + 2);
        piVar2 = (int *)*piVar2;
      } while (piVar2 != piVar1);
    }
    FUN_006d9d50();
  }
  FUN_006d9d50();
  return;
}


// ==== FUN_006d8650 @ 0x006d8650 ====

void FUN_006d8650(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e517c;
  FUN_006d8600();
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if ((void *)in_ECX[0x23] != (void *)0x0) {
    _free((void *)in_ECX[0x23]);
    return;
  }
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  FUN_008984a0();
  if (0xf < (uint)in_ECX[0x1b]) {
    _free((void *)in_ECX[0x16]);
    return;
  }
  in_ECX[0x1b] = 0xf;
  in_ECX[0x1a] = 0;
  *(undefined1 *)(in_ECX + 0x16) = 0;
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
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  _free((void *)in_ECX[8]);
  return;
}


// ==== FUN_006d8710 @ 0x006d8710 ====

void FUN_006d8710(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  int in_ECX;
  int iVar7;
  undefined1 auStack_20 [4];
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_map_009e5054,7);
  iVar6 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  if (iVar6 == 0) {
    local_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e505c,0x12);
    FUN_00406880(auStack_20);
    if (local_8 < 0x10) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    _free(local_1c);
    return;
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x80);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    iVar3 = puVar2[3];
    iVar4 = *(int *)(iVar3 + 0x2c);
    for (iVar7 = *(int *)(iVar3 + 0x28); iVar7 != iVar4; iVar7 = iVar7 + 0x24) {
      FUN_006d82c0(iVar6,iVar7,*(undefined4 *)(iVar3 + 0x20));
    }
  }
  return;
}


// ==== FUN_006d8810 @ 0x006d8810 ====

void FUN_006d8810(int param_1)

{
  int iVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x74) = 0;
  FUN_006d6e70();
  FUN_006d8600();
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_Monster_009e514c,7);
  if (iVar1 == 0) {
    *(undefined4 *)(in_ECX + 0x18) = 0;
    FUN_006d7870();
    FUN_006d8710();
    FUN_006d6f20();
    return;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),&PTR_LAB_009e5154,3);
  if (iVar1 == 0) {
    *(undefined4 *)(in_ECX + 0x18) = 1;
    FUN_006d7b20();
    FUN_006d8710();
    FUN_006d6f20();
    return;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_Brick_009e5158,5);
  if (iVar1 == 0) {
    *(undefined4 *)(in_ECX + 0x18) = 2;
    FUN_006d7f60();
    FUN_006d8710();
    FUN_006d6f20();
  }
  return;
}


// ==== FUN_006d88e0 @ 0x006d88e0 ====

undefined4 FUN_006d88e0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  undefined1 auStack_1a [26];
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_close_009e50e4,9);
      if (iVar2 == 0) {
        (**(code **)(*in_ECX + 0x10))();
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_plus_009e50f0);
      if (cVar1 != '\0') {
        FUN_006d7100(0x14);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_minus_009e50fc);
      if (cVar1 != '\0') {
        FUN_006d7100(0xffffffec);
        return 1;
      }
    }
  }
  else if ((param_1 == 0x15) && (param_3 == 1)) {
    cVar1 = FUN_004036a0(param_2,s_com_type_009e5108);
    if (cVar1 != '\0') {
      piVar3 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(param_2);
      (**(code **)(*piVar3 + 0x30))();
      FUN_005778b0(auStack_1a + -6);
      FUN_006d8810(auStack_1a + -6);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    return 1;
  }
  return 0;
}


// ==== FUN_006d89e0 @ 0x006d89e0 ====

void FUN_006d89e0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 3) {
    *param_1 = *param_3;
    param_1[1] = param_3[1];
    param_1[2] = param_3[2];
  }
  return;
}


// ==== FUN_006d8a20 @ 0x006d8a20 ====

int FUN_006d8a20(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c8b0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0xc) {
    FUN_004e3d80(param_3,param_1);
    param_3 = param_3 + 0xc;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@006d8a86 @ 0x006d8a86 ====

void Catch_006d8a86(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006d8a90 @ 0x006d8a90 ====

int FUN_006d8a90(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c8c0;
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


// ==== Catch@006d8af6 @ 0x006d8af6 ====

void Catch_006d8af6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006d8b00 @ 0x006d8b00 ====

void FUN_006d8b00(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c8d0;
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


// ==== Catch@006d8b6f @ 0x006d8b6f ====

void Catch_006d8b6f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_006d8b90 @ 0x006d8b90 ====

void * FUN_006d8b90(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c8e0;
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


// ==== Catch@006d8bfd @ 0x006d8bfd ====

void Catch_006d8bfd(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_006d8c20 @ 0x006d8c20 ====

void FUN_006d8c20(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c8f0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_004e3d80(param_1,param_3);
    param_1 = param_1 + 0xc;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@006d8c86 @ 0x006d8c86 ====

void Catch_006d8c86(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006d8c90 @ 0x006d8c90 ====

void FUN_006d8c90(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c900;
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


// ==== Catch@006d8cf6 @ 0x006d8cf6 ====

void Catch_006d8cf6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006d8d00 @ 0x006d8d00 ====

void FUN_006d8d00(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_006d8a20(param_1,param_2,param_3);
  return;
}


// ==== FUN_006d8d20 @ 0x006d8d20 ====

void FUN_006d8d20(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_006d8a90(param_1,param_2,param_3);
  return;
}


// ==== FUN_006d8d40 @ 0x006d8d40 ====

void FUN_006d8d40(void)

{
  int in_ECX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  puVar1 = (undefined4 *)(in_ECX + 4);
  local_4 = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)puVar1 = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  local_8 = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    puVar2 = puVar1;
  }
  else {
    puVar2 = (undefined4 *)*puVar1;
  }
  if (0xf < *(uint *)(in_ECX + 0x18)) {
    puVar1 = (undefined4 *)*puVar1;
  }
  FUN_004bdb30(&local_8,puVar1,*(int *)(in_ECX + 0x14) + (int)puVar2);
  return;
}


// ==== FUN_006d8db0 @ 0x006d8db0 ====

int FUN_006d8db0(int param_1,int param_2,undefined4 param_3)

{
  FUN_006d8c20(param_1,param_2,param_3);
  return param_1 + param_2 * 0xc;
}


// ==== FUN_006d8de0 @ 0x006d8de0 ====

int FUN_006d8de0(int param_1,int param_2,undefined4 param_3)

{
  FUN_006d8c90(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_006d8e10 @ 0x006d8e10 ====

void FUN_006d8e10(int param_1,int param_2)

{
  while( true ) {
    if (param_1 == param_2) {
      return;
    }
    if (0xf < *(uint *)(param_1 + 0x18)) break;
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    param_1 = param_1 + 0x24;
  }
  _free(*(void **)(param_1 + 4));
  return;
}


// ==== FUN_006d8e50 @ 0x006d8e50 ====

int FUN_006d8e50(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  puVar1 = (undefined4 *)(param_3 + 0x1c);
  puVar2 = (undefined4 *)(param_2 + 0x1c);
  do {
    param_2 = param_2 + -0x24;
    param_3 = param_3 + -0x24;
    FUN_00401660(param_2,0,0xffffffff);
    puVar1[-9] = puVar2[-9];
    puVar1[-8] = puVar2[-8];
    puVar1 = puVar1 + -9;
    puVar2 = puVar2 + -9;
  } while (param_2 != param_1);
  return param_3;
}


// ==== FUN_006d8ea0 @ 0x006d8ea0 ====

void FUN_006d8ea0(int param_1,int param_2)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(param_2,0,0xffffffff);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0x20);
  }
  return;
}


// ==== FUN_006d8ee0 @ 0x006d8ee0 ====

int FUN_006d8ee0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c910;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x24) {
    FUN_006d8ea0(param_3,param_1);
    param_3 = param_3 + 0x24;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@006d8f4a @ 0x006d8f4a ====

void Catch_006d8f4a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x24) {
    FUN_00405c70(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006d8f70 @ 0x006d8f70 ====

void FUN_006d8f70(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint extraout_ECX;
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
  puStack_c = &LAB_0098c920;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x50);
  local_44 = *param_3;
  local_40 = param_3[1];
  local_3c = param_3[2];
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = (*(int *)(in_ECX + 0xc) - iVar3) / 0xc;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x50);
    if (0x15555555U - iVar2 < param_2) {
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
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
    }
    if (local_20 < iVar2 + param_2) {
      if (0x15555555 - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
      }
      if (local_20 < iVar3 + param_2) {
        iVar3 = FUN_004a3750();
        local_20 = iVar3 + param_2;
      }
      local_20 = local_20 * 0xc;
      local_18 = operator_new(local_20);
      local_8 = 0;
      local_1c = FUN_006d8d00(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_1c = FUN_006d8db0(local_1c,param_2,&local_44);
      FUN_006d8d00(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0xc;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)local_18;
        *(void **)(in_ECX + 8) = (void *)((int)local_18 + (param_2 + iVar3) * 0xc);
        *(void **)(in_ECX + 4) = local_18;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_28 = *(int *)(in_ECX + 8);
    if ((uint)((local_28 - param_1) / 0xc) < param_2) {
      local_24 = param_2 * 0xc;
      FUN_006d8a20(param_1,local_28,local_24 + param_1);
      local_8 = 2;
      FUN_006d8db0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0xc,&local_44);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_24;
      FUN_006d89e0(param_1,*(int *)(in_ECX + 8) - local_24,&local_44);
      ExceptionList = local_10;
      return;
    }
    local_2c = local_28 + param_2 * -0xc;
    uVar4 = FUN_006d8a20(local_2c,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_004ab780(param_1,local_2c,local_28,local_38);
    FUN_006d89e0(param_1,param_2 * 0xc + param_1,&local_44);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@006d9118 @ 0x006d9118 ====

void Catch_006d9118(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_006d9220 @ 0x006d9220 ====

void FUN_006d9220(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0098c930;
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
      uVar5 = FUN_006d8d20(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_006d8de0(uVar5,param_2,&local_18);
      FUN_006d8d20(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_006d8a90(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_006d8de0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_006d8a90(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@006d9381 @ 0x006d9381 ====

void Catch_006d9381(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_006d9470 @ 0x006d9470 ====

void FUN_006d9470(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c940;
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
    uVar2 = FUN_006d8de0(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@006d9504 @ 0x006d9504 ====

void Catch_006d9504(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006d9520 @ 0x006d9520 ====

void FUN_006d9520(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  
  if (param_1 != param_2) {
    puVar1 = (undefined4 *)(param_1 + 0x1c);
    do {
      FUN_00401660(param_3,0,0xffffffff);
      *puVar1 = *(undefined4 *)(param_3 + 0x1c);
      puVar1[1] = *(undefined4 *)(param_3 + 0x20);
      param_1 = param_1 + 0x24;
      puVar1 = puVar1 + 9;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_006d9560 @ 0x006d9560 ====

void FUN_006d9560(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c950;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_006d8ea0(param_1,param_3);
    param_1 = param_1 + 0x24;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@006d95ca @ 0x006d95ca ====

void Catch_006d95ca(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x24) {
    FUN_00405c70(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006d95f0 @ 0x006d95f0 ====

void FUN_006d95f0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0xc != 0) {
      iVar1 = (param_2 - iVar1) / 0xc;
      goto LAB_006d9633;
    }
  }
  iVar1 = 0;
LAB_006d9633:
  FUN_006d8f70(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0xc;
  return;
}


// ==== FUN_006d9660 @ 0x006d9660 ====

void FUN_006d9660(uint param_1,undefined1 param_2)

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
    FUN_006d9220(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_006d96d0 @ 0x006d96d0 ====

/* WARNING: Removing unreachable block (ram,0x006d96eb) */
/* WARNING: Removing unreachable block (ram,0x006d96f0) */
/* WARNING: Removing unreachable block (ram,0x006d96fe) */

void FUN_006d96d0(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_006d9220(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_006d9720 @ 0x006d9720 ====

void FUN_006d9720(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_006d8ee0(param_1,param_2,param_3);
  return;
}


// ==== FUN_006d9740 @ 0x006d9740 ====

void FUN_006d9740(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0xc) <= (uint)((*(int *)(in_ECX + 8) - iVar1) / 0xc)
     )) {
    FUN_006d95f0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_006d8c20(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0xc;
  return;
}


// ==== FUN_006d97c0 @ 0x006d97c0 ====

int FUN_006d97c0(int param_1,int param_2,undefined4 param_3)

{
  FUN_006d9560(param_1,param_2,param_3);
  return param_1 + param_2 * 0x24;
}


// ==== FUN_006d97f0 @ 0x006d97f0 ====

void FUN_006d97f0(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint extraout_ECX;
  undefined1 local_64 [2];
  undefined1 auStack_62 [2];
  void *local_60;
  undefined4 local_50;
  uint local_4c;
  undefined4 local_48;
  undefined4 local_44;
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
  puStack_c = &LAB_0098c960;
  local_10 = ExceptionList;
  local_14 = local_64 + -0xc;
  local_4c = 0xf;
  local_50 = 0;
  local_60 = (void *)((uint)local_60 & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3,0,0xffffffff);
  local_48 = *(undefined4 *)(param_3 + 0x1c);
  local_44 = *(undefined4 *)(param_3 + 0x20);
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
      local_18 = (void *)FUN_006d9720(*(undefined4 *)(in_ECX + 4),param_1,local_1c);
      local_18 = (void *)FUN_006d97c0(local_18,param_2,local_64);
      FUN_006d9720(param_1,*(undefined4 *)(in_ECX + 8),local_18);
      local_8 = 0xffffffff;
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
      }
      if (iVar2 != 0) {
        FUN_006d8e10(iVar2,*(undefined4 *)(in_ECX + 8));
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
        FUN_006d8ee0(param_1,local_2c,local_28 + param_1);
        local_8 = 2;
        FUN_006d97c0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x24,local_64
                    );
        local_8 = 0xffffffff;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_28;
        FUN_006d9520(param_1,*(int *)(in_ECX + 8) - local_28,local_64);
      }
      else {
        local_30 = local_2c + param_2 * -0x24;
        uVar3 = FUN_006d8ee0(local_30,local_2c,local_2c);
        *(undefined4 *)(in_ECX + 8) = uVar3;
        FUN_006d8e50(param_1,local_30,local_2c,local_40);
        FUN_006d9520(param_1,param_2 * 0x24 + param_1,local_64);
      }
    }
  }
  if (local_4c < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_60);
  return;
}


// ==== Catch@006d99c1 @ 0x006d99c1 ====

void Catch_006d99c1(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_004f32d0(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@006d9a75 @ 0x006d9a75 ====

void Catch_006d9a75(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x24;
  FUN_004f32d0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x1c) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006d9b10 @ 0x006d9b10 ====

/* WARNING: Removing unreachable block (ram,0x006d9bff) */

void FUN_006d9b10(int *param_1,ushort *param_2)

{
  undefined4 *puVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  uVar6 = *(uint *)(in_ECX + 0x24);
  if (uVar6 <= *(uint *)(in_ECX + 0xc) >> 2) {
    if (*(int *)(in_ECX + 0x14) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
    }
    if (uVar6 < iVar4 - 1U) {
      if (*(uint *)(in_ECX + 0x20) < uVar6) {
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
      FUN_006d9660(iVar4 * 2 + -1,*(undefined4 *)(in_ECX + 8));
    }
    uVar6 = (*(int *)(in_ECX + 0x24) - (*(uint *)(in_ECX + 0x20) >> 1)) - 1;
    puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
    if (puVar8 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4 + 4)) {
      do {
        iVar4 = uVar6 * 4;
        if (((*(ushort *)(puVar8 + 2) ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20)) == uVar6) {
          puVar9 = (undefined4 *)*puVar8;
        }
        else {
          puVar9 = (undefined4 *)*puVar8;
          if (puVar9 != *(undefined4 **)(in_ECX + 8)) {
            puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4);
            uVar7 = uVar6;
            while ((puVar8 == puVar1 &&
                   (*(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4) = puVar9, uVar7 != 0))) {
              uVar7 = uVar7 - 1;
              iVar4 = uVar7 * 4;
              puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4);
            }
            iVar4 = *(int *)(in_ECX + 8);
            *(undefined4 **)puVar8[1] = puVar9;
            *(int *)puVar9[1] = iVar4;
            **(undefined4 **)(iVar4 + 4) = puVar8;
            uVar3 = *(undefined4 *)(iVar4 + 4);
            *(undefined4 *)(iVar4 + 4) = puVar9[1];
            puVar9[1] = puVar8[1];
            puVar8[1] = uVar3;
            puVar8 = *(undefined4 **)(*(int *)(in_ECX + 8) + 4);
            *(int *)(*(int *)(in_ECX + 0x14) + 4 + *(int *)(in_ECX + 0x24) * 4) =
                 *(int *)(in_ECX + 8);
          }
          for (uVar7 = *(uint *)(in_ECX + 0x24);
              (uVar6 < uVar7 &&
              (*(int *)(*(int *)(in_ECX + 0x14) + uVar7 * 4) == *(int *)(in_ECX + 8)));
              uVar7 = uVar7 - 1) {
            *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar7 * 4) = puVar8;
          }
          if (puVar9 == *(undefined4 **)(in_ECX + 8)) break;
        }
        puVar8 = puVar9;
      } while (puVar9 != *(undefined4 **)(uVar6 * 4 + 4 + *(int *)(in_ECX + 0x14)));
    }
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
  }
  uVar2 = *param_2;
  uVar6 = (uVar2 ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20);
  if (*(uint *)(in_ECX + 0x24) <= uVar6) {
    uVar6 = uVar6 + (-1 - (*(uint *)(in_ECX + 0x20) >> 1));
  }
  iVar4 = uVar6 * 4;
  puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + 4 + iVar4);
  if (puVar8 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4)) {
    do {
      puVar8 = (undefined4 *)puVar8[1];
      if (*(ushort *)(puVar8 + 2) <= uVar2) {
        if (uVar2 <= *(ushort *)(puVar8 + 2)) {
          *param_1 = (int)puVar8;
          *(undefined1 *)(param_1 + 1) = 0;
          return;
        }
        puVar8 = (undefined4 *)*puVar8;
        break;
      }
    } while (puVar8 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4));
  }
  iVar5 = FUN_006d8b90(puVar8,puVar8[1],param_2);
  FUN_00833ae0(1);
  puVar8[1] = iVar5;
  **(int **)(iVar5 + 4) = iVar5;
  iVar5 = puVar8[1];
  puVar9 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4);
  while ((puVar8 == puVar9 && (*(int *)(*(int *)(in_ECX + 0x14) + iVar4) = iVar5, uVar6 != 0))) {
    uVar6 = uVar6 - 1;
    iVar4 = uVar6 * 4;
    puVar9 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4);
  }
  *param_1 = iVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_006d9d50 @ 0x006d9d50 ====

void FUN_006d9d50(void)

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
    FUN_006d96d0(9,&local_4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_006d9db0 @ 0x006d9db0 ====

void FUN_006d9db0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x24 != 0) {
      iVar1 = (param_2 - iVar1) / 0x24;
      goto LAB_006d9df5;
    }
  }
  iVar1 = 0;
LAB_006d9df5:
  FUN_006d97f0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x24;
  return;
}


// ==== FUN_006d9e20 @ 0x006d9e20 ====

void FUN_006d9e20(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x24) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x24))) {
    FUN_006d9db0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_006d9560(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x24;
  return;
}


// ==== FUN_006d9eb0 @ 0x006d9eb0 ====

void FUN_006d9eb0(int param_1)

{
  void *_Memory;
  
  _Memory = *(void **)(param_1 + 4);
  if (_Memory == (void *)0x0) {
    return;
  }
  if (*(int *)((int)_Memory + 0x28) != 0) {
    FUN_006d8e10(*(int *)((int)_Memory + 0x28),*(undefined4 *)((int)_Memory + 0x2c),
                 (int)_Memory + 0x24,param_1);
    _free(*(void **)((int)_Memory + 0x28));
    return;
  }
  *(undefined4 *)((int)_Memory + 0x28) = 0;
  *(undefined4 *)((int)_Memory + 0x2c) = 0;
  *(undefined4 *)((int)_Memory + 0x30) = 0;
  if (*(uint *)((int)_Memory + 0x18) < 0x10) {
    *(undefined4 *)((int)_Memory + 0x18) = 0xf;
    *(undefined4 *)((int)_Memory + 0x14) = 0;
    *(undefined1 *)((int)_Memory + 4) = 0;
    _free(_Memory);
    return;
  }
  _free(*(void **)((int)_Memory + 4));
  return;
}


// ==== FUN_006d9f20 @ 0x006d9f20 ====

void FUN_006d9f20(byte param_1)

{
  void *in_ECX;
  
  FUN_006d8650();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006d9f40 @ 0x006d9f40 ====

void FUN_006d9f40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e51f0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006d9f60 @ 0x006d9f60 ====

undefined4 FUN_006d9f60(void)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0xb8);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_006e8710();
  return uVar2;
}


// ==== FUN_006d9f80 @ 0x006d9f80 ====

void FUN_006d9f80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e5200;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a7bc = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a7bc = in_ECX;
  return;
}


// ==== FUN_006d9fb0 @ 0x006d9fb0 ====

undefined4 FUN_006d9fb0(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(1);
  }
  return 1;
}


// ==== FUN_006d9ff0 @ 0x006d9ff0 ====

void FUN_006d9ff0(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5a7bc = 0;
  *in_ECX = &PTR_FUN_009e51f0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006da020 @ 0x006da020 ====

void FUN_006da020(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e525c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006da050 @ 0x006da050 ====

undefined1 FUN_006da050(void)

{
  return 0;
}


// ==== FUN_006da060 @ 0x006da060 ====

undefined1 FUN_006da060(void)

{
  return 0;
}


// ==== FUN_006da070 @ 0x006da070 ====

undefined1 FUN_006da070(void)

{
  return 0;
}


// ==== FUN_006da080 @ 0x006da080 ====

void FUN_006da080(undefined4 param_1)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009e5274;
  in_ECX[1] = param_1;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_itemDesc_009e5248,8);
  piVar1 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
  }
  return;
}


// ==== FUN_006da110 @ 0x006da110 ====

undefined1 FUN_006da110(void)

{
  return 0;
}


// ==== FUN_006da120 @ 0x006da120 ====

undefined1 FUN_006da120(void)

{
  return 0;
}


// ==== FUN_006da130 @ 0x006da130 ====

undefined1 FUN_006da130(void)

{
  return 0;
}


// ==== FUN_006da140 @ 0x006da140 ====

void FUN_006da140(undefined4 param_1)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009e52d8;
  in_ECX[1] = param_1;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_itemDesc_009e52c4,8);
  piVar1 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
  }
  return;
}


// ==== FUN_006da1d0 @ 0x006da1d0 ====

undefined1 FUN_006da1d0(void)

{
  return 0;
}


// ==== FUN_006da1e0 @ 0x006da1e0 ====

undefined1 FUN_006da1e0(void)

{
  return 0;
}


// ==== FUN_006da1f0 @ 0x006da1f0 ====

undefined1 FUN_006da1f0(void)

{
  return 0;
}


// ==== FUN_006da200 @ 0x006da200 ====

void FUN_006da200(undefined4 param_1)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009e533c;
  in_ECX[1] = param_1;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_itemDesc_009e5328,8);
  piVar1 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
  }
  return;
}


// ==== FUN_006da290 @ 0x006da290 ====

undefined1 FUN_006da290(void)

{
  return 0;
}


// ==== FUN_006da2a0 @ 0x006da2a0 ====

undefined1 FUN_006da2a0(void)

{
  return 0;
}


// ==== FUN_006da2b0 @ 0x006da2b0 ====

undefined1 FUN_006da2b0(void)

{
  return 0;
}


// ==== FUN_006da2c0 @ 0x006da2c0 ====

void FUN_006da2c0(undefined4 param_1)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009e53a0;
  in_ECX[1] = param_1;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_itemDesc_009e538c,8);
  piVar1 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
  }
  return;
}


// ==== FUN_006da350 @ 0x006da350 ====

undefined1 FUN_006da350(void)

{
  return 0;
}


// ==== FUN_006da360 @ 0x006da360 ====

undefined1 FUN_006da360(void)

{
  return 0;
}


// ==== FUN_006da370 @ 0x006da370 ====

undefined1 FUN_006da370(void)

{
  return 0;
}


// ==== FUN_006da380 @ 0x006da380 ====

void FUN_006da380(undefined4 param_1)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009e5404;
  in_ECX[1] = param_1;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_itemDesc_009e53f0,8);
  piVar1 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
  }
  return;
}


// ==== FUN_006da410 @ 0x006da410 ====

undefined2 FUN_006da410(void)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  
  iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if (iVar1 == 0) {
    return 0;
  }
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x48) + 0x28))();
  puVar3 = (undefined2 *)(**(code **)(*piVar2 + 8))();
  return *puVar3;
}


// ==== FUN_006da450 @ 0x006da450 ====

void FUN_006da450(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_2;
  uVar2 = 0;
  if (iVar1 == 0) {
    uVar2 = 0x3f10003;
  }
  else if (iVar1 == 1) {
    uVar2 = 0x3f10002;
  }
  else if (iVar1 == 2) {
    uVar2 = 0x3f10001;
  }
  uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,uVar2);
  FUN_00401660(uVar2,0,0xffffffff);
  return;
}


// ==== FUN_006da4a0 @ 0x006da4a0 ====

void FUN_006da4a0(int *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  uint uVar3;
  undefined1 auStack_88 [12];
  int iStack_7c;
  int iStack_74;
  void *pvStack_68;
  uint uStack_54;
  undefined4 uStack_4c;
  undefined4 uStack_44;
  undefined4 uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  void *pvStack_18;
  uint uStack_4;
  
  uVar1 = (**(code **)(*param_1 + 0x10))();
  FUN_005041e0(uVar1);
  if (param_2 < param_3) {
    auStack_88[0] = 0;
  }
  else if (param_2 < param_4) {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x3c))();
    uVar1 = (**(code **)(*piVar2 + 0x10))();
    FUN_005041e0(uVar1);
    uStack_4c = uStack_34;
    uStack_44 = uStack_2c;
    uVar3 = iStack_28 - iStack_30 >> 0x1f;
    iStack_74 = (iStack_28 - iStack_30 ^ uVar3) - uVar3;
    iStack_7c = (param_2 - param_3) * iStack_74 + iStack_30;
    iStack_74 = iStack_7c + iStack_74;
    auStack_88[0] = 1;
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
  }
  else {
    auStack_88[0] = 0;
  }
  (**(code **)(*param_1 + 0xc))(auStack_88);
  if (uStack_54 < 0x10) {
    return;
  }
  _free(pvStack_68);
  return;
}


// ==== FUN_006da590 @ 0x006da590 ====

void FUN_006da590(undefined4 param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  void *unaff_ESI;
  undefined1 auStack_36 [6];
  uint uStack_30;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  uint uStack_c;
  
  sVar1 = *(short *)(param_2 + 6);
  uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x3f10004);
  FUN_00401660(uVar2,0,0xffffffff);
  if (sVar1 == 0) {
    FUN_00401740(&DAT_009e545c,2);
    uVar2 = FUN_00404230(auStack_24);
    FUN_00401ff0(uVar2,0,0xffffffff);
    if (uStack_c < 0x10) goto LAB_006da67e;
  }
  else {
    FUN_00401740(s__u____u_009e5460,7);
    uVar2 = FUN_00404230(auStack_24);
    FUN_00401ff0(uVar2,0,0xffffffff);
    if (uStack_c < 0x10) {
LAB_006da67e:
      uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x3f10005);
      FUN_00401ff0(uVar2,0,0xffffffff);
      FUN_00401660(auStack_36 + -0x12,0,0xffffffff);
      FUN_00401ff0(param_2 + 8,0,0xffffffff);
      if (uStack_30 < 0x10) {
        return;
      }
      _free(unaff_ESI);
      return;
    }
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_006da6e0 @ 0x006da6e0 ====

int FUN_006da6e0(int param_1)

{
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  FUN_00401740(s_noticectrl__d_009e547c,0xd);
  FUN_00404230(local_1c);
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_1c,0,0xffffffff);
  if (local_4 < 0x10) {
    return param_1;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_006da760 @ 0x006da760 ====

void FUN_006da760(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_38 [5];
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  int *piStack_c;
  uint uStack_8;
  
  FUN_006da6e0(local_38,0);
  piStack_c = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_38);
  if (piStack_c != (int *)0x0) {
    uVar2 = (**(code **)(*piStack_c + 0x30))
                      (0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                       &Framework::UI::Control::Notice::RTTI_Type_Descriptor,0);
    uVar2 = FUN_00803725(uVar2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
    if (uStack_24 < 0x10) {
      return;
    }
    _free(local_38[0]);
    return;
  }
  uStack_8 = 0xf;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  FUN_00401740(s_FALSE_009e5454,5);
  FUN_00406880(auStack_20);
  if (uStack_8 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_006da810 @ 0x006da810 ====

void FUN_006da810(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int local_74;
  undefined1 local_70 [4];
  void *local_6c;
  undefined4 local_5c;
  uint local_58;
  undefined1 local_54 [4];
  void *local_50;
  undefined4 local_40;
  uint local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  uVar3 = 0;
  if (*(int *)(param_2 + 0x28) == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (*(int *)(param_2 + 0x2c) - *(int *)(param_2 + 0x28)) / 0x1c;
  }
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  FUN_00401740(&DAT_009e5468,0);
  if (uVar4 != 0) {
    local_74 = 0;
    do {
      iVar1 = *(int *)(param_2 + 0x28);
      if ((iVar1 == 0) || ((uint)((*(int *)(param_2 + 0x2c) - iVar1) / 0x1c) <= uVar3))
      goto LAB_006daa63;
      FUN_00401ff0(local_74 + iVar1,0,0xffffffff);
      if ((1 < uVar4) && (uVar4 != uVar3 + 1)) {
        FUN_004020e0(&DAT_009e546c,1);
      }
      local_74 = local_74 + 0x1c;
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar4);
  }
  uVar3 = 0;
  FUN_00401660(local_54,0,0xffffffff);
  if (*(int *)(param_2 + 0x38) == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (*(int *)(param_2 + 0x3c) - *(int *)(param_2 + 0x38)) / 0x1c;
  }
  local_58 = 0xf;
  local_5c = 0;
  local_6c = (void *)((uint)local_6c & 0xffffff00);
  FUN_00401740(&DAT_009e546e,0);
  if (uVar4 != 0) {
    local_74 = 0;
    do {
      iVar1 = *(int *)(param_2 + 0x38);
      if ((iVar1 == 0) || ((uint)((*(int *)(param_2 + 0x3c) - iVar1) / 0x1c) <= uVar3)) {
LAB_006daa63:
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      FUN_00401ff0(local_74 + iVar1,0,0xffffffff);
      if ((1 < uVar4) && (uVar4 != uVar3 + 1)) {
        FUN_004020e0(&DAT_009e5470,1);
      }
      local_74 = local_74 + 0x1c;
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar4);
  }
  uVar2 = FUN_004022a0(local_1c,&DAT_009e5478,local_70,&DAT_009e5474);
  uVar2 = FUN_00402220(local_38,uVar2);
  FUN_00401ff0(uVar2,0,0xffffffff);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  if (0xf < local_58) {
    _free(local_6c);
    return;
  }
  local_58 = 0xf;
  local_5c = 0;
  local_6c = (void *)((uint)local_6c & 0xffffff00);
  if (local_3c < 0x10) {
    return;
  }
  _free(local_50);
  return;
}


// ==== FUN_006daa70 @ 0x006daa70 ====

void FUN_006daa70(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e5494;
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  FUN_006da760();
  return;
}


// ==== FUN_006daaa0 @ 0x006daaa0 ====

int * FUN_006daaa0(undefined4 param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  int *extraout_EAX;
  int *extraout_EAX_00;
  int *extraout_EAX_01;
  int *extraout_EAX_02;
  int in_ECX;
  uint uVar7;
  int iVar8;
  int unaff_EDI;
  int iVar9;
  int unaff_retaddr;
  void *pvVar10;
  void *_Memory;
  undefined4 uStack_53c;
  undefined1 uStack_510;
  undefined1 uStack_50f;
  void *pvStack_508;
  int iStack_504;
  int iStack_4fc;
  undefined4 uStack_4f8;
  uint uStack_4f4;
  undefined1 auStack_4d4 [8];
  void *pvStack_4cc;
  int iStack_4c8;
  undefined4 uStack_4c4;
  int iStack_4c0;
  undefined4 uStack_4bc;
  uint uStack_4b8;
  void *pvStack_4b0;
  uint uStack_49c;
  undefined1 auStack_498 [4];
  undefined1 local_494 [20];
  undefined1 auStack_480 [4];
  void *pvStack_47c;
  undefined4 uStack_478;
  undefined4 uStack_474;
  undefined4 uStack_470;
  int iStack_128;
  undefined4 *puStack_124;
  int iStack_120;
  undefined1 auStack_108 [28];
  undefined1 auStack_ec [220];
  undefined4 uStack_10;
  int *piStack_8;
  
  FUN_006da6e0(local_494,param_1);
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  pvVar10 = (void *)0x19;
  piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x3c))();
  uVar6 = (**(code **)(*piVar5 + 0x10))();
  FUN_005041e0(uVar6);
  FUN_005041e0(auStack_4d4);
  (**(code **)(*piVar5 + 0x30))();
  pvStack_47c = pvStack_4cc;
  uStack_474 = uStack_4c4;
  uVar7 = iStack_4c0 - iStack_4c8 >> 0x1f;
  iVar9 = (iStack_4c0 - iStack_4c8 ^ uVar7) - uVar7;
  iVar8 = (unaff_retaddr + -1) * iVar9 + iStack_4c8;
  uStack_510 = 1;
  uStack_50f = 1;
  FUN_00401660(auStack_498,0,0xffffffff);
  iStack_4fc = iVar8 + iVar9;
  iStack_504 = iVar8;
  FUN_00401660(auStack_498,0,0xffffffff);
  (**(code **)(*piVar3 + 8))(&uStack_510);
  (**(code **)(*piVar4 + 0x38))(piVar3);
  (**(code **)(*piVar4 + 0x1c))(auStack_4d4 + -0x6c);
  FUN_0056fd80(unaff_EDI);
  FUN_00505f10();
  piVar5 = piStack_8;
  uStack_478 = *(undefined4 *)(unaff_EDI + 0x70);
  uStack_474 = *(undefined4 *)(unaff_EDI + 0x74);
  uStack_470 = *(undefined4 *)(unaff_EDI + 0x78);
  uVar7 = 0;
  while ((iVar8 = piVar5[0x12], iVar8 != 0 && (uVar7 < (uint)(piVar5[0x13] - iVar8 >> 2)))) {
    if ((iVar8 == 0) || ((uint)(piVar5[0x13] - iVar8 >> 2) <= uVar7)) {
                    /* WARNING: Subroutine does not return */
      FUN_0042f370();
    }
    puVar1 = (undefined4 *)(iVar8 + uVar7 * 4);
    if ((iStack_128 == 0) ||
       ((uint)(iStack_120 - iStack_128 >> 2) <= (uint)((int)puStack_124 - iStack_128 >> 2))) {
      FUN_0042f3e0(puStack_124,1,puVar1);
      uVar7 = uVar7 + 1;
    }
    else {
      *puStack_124 = *puVar1;
      puStack_124 = puStack_124 + 1;
      uVar7 = uVar7 + 1;
    }
  }
  iVar8 = *piStack_8;
  uVar6 = 0;
  if (iVar8 == 0) {
    uVar6 = 0x3f10003;
  }
  else if (iVar8 == 1) {
    uVar6 = 0x3f10002;
  }
  else if (iVar8 == 2) {
    uVar6 = 0x3f10001;
  }
  uVar6 = (**(code **)(*DAT_00b5a794 + 0xc))(0,uVar6);
  FUN_00401660(uVar6,0,0xffffffff);
  _Memory = pvVar10;
  FUN_006da590(auStack_108,uStack_10);
  FUN_006da810(auStack_ec,uStack_10);
  (**(code **)(*piVar4 + 0x24))(auStack_480);
  (**(code **)(*piVar3 + 0x2c))(piVar4);
  piVar5 = (int *)(**(code **)(**(int **)((int)pvVar10 + 4) + 0x2c))();
  if (piVar5 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar3 + 0x74))(piVar5);
    if (cVar2 != '\0') {
      cVar2 = (**(code **)(*piVar5 + 0x78))(piVar3);
      if (cVar2 == '\0') {
        (**(code **)(*piVar3 + 0x74))(0);
      }
      else {
        iVar8 = (**(code **)(*piVar5 + 0x38))();
        piVar3[1] = iVar8;
      }
    }
  }
  FUN_00505d80();
  if (0xf < uStack_53c) {
    _free(_Memory);
    return extraout_EAX;
  }
  if (0xf < uStack_4f4) {
    _free(pvStack_508);
    return extraout_EAX_00;
  }
  uStack_4f4 = 0xf;
  uStack_4f8 = 0;
  pvStack_508 = (void *)((uint)pvStack_508 & 0xffffff00);
  if (0xf < uStack_4b8) {
    _free(pvStack_4cc);
    return extraout_EAX_01;
  }
  uStack_4b8 = 0xf;
  uStack_4bc = 0;
  pvStack_4cc = (void *)((uint)pvStack_4cc & 0xffffff00);
  if (uStack_49c < 0x10) {
    return piVar4;
  }
  _free(pvStack_4b0);
  return extraout_EAX_02;
}


// ==== FUN_006dae40 @ 0x006dae40 ====

void FUN_006dae40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e5494;
  in_ECX[2] = 0;
  in_ECX[1] = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006dae80 @ 0x006dae80 ====

void FUN_006dae80(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e54dc;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_006daee0 @ 0x006daee0 ====

undefined4 FUN_006daee0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if ((iVar2 == 0x20001) && (param_1[1] == 8)) {
    cVar1 = (**(code **)(*DAT_00b5a994 + 0x10))(0x11);
    if (cVar1 != '\0') {
      FUN_006922c0();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006daf30 @ 0x006daf30 ====

void FUN_006daf30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b240c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006daf60 @ 0x006daf60 ====

void FUN_006daf60(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e5528;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_006daf80 @ 0x006daf80 ====

undefined4 FUN_006daf80(int param_1)

{
  char cVar1;
  
  switch(*(undefined4 *)(param_1 + 4)) {
  case 8:
    cVar1 = (**(code **)(*DAT_00b5a994 + 0x10))(0x11);
    if (cVar1 != '\0') {
      FUN_006922c0();
      return 1;
    }
    break;
  case 9:
    FUN_006926c0();
    return 1;
  case 0x26:
    FUN_00692600(1);
    return 1;
  case 0x28:
    FUN_00692600(0);
    return 1;
  }
  return 0;
}


// ==== FUN_006db030 @ 0x006db030 ====

uint FUN_006db030(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x20001) {
    uVar1 = FUN_006daf80(param_1);
    if ((char)uVar1 == '\x01') {
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006db060 @ 0x006db060 ====

void FUN_006db060(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2424;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006db080 @ 0x006db080 ====

void FUN_006db080(void)

{
  return;
}


// ==== FUN_006db090 @ 0x006db090 ====

void FUN_006db090(int *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (int *)0x0) {
    puVar1 = operator_new(8);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_009b1798;
    }
    uVar2 = (**(code **)(*param_1 + 4))();
    puVar1[1] = uVar2;
    FUN_00797a20(puVar1);
    (**(code **)(*param_1 + 0x5c))();
  }
  return;
}


// ==== FUN_006db0e0 @ 0x006db0e0 ====

void FUN_006db0e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e5638;
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


// ==== FUN_006db130 @ 0x006db130 ====

/* WARNING: Removing unreachable block (ram,0x006db2a7) */

void FUN_006db130(void)

{
  char cVar1;
  code *pcVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int in_ECX;
  char acStack_36 [14];
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined1 auStack_20 [4];
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_lbl_type_009e55b4,8);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  iVar4 = (**(code **)(*piVar3 + 0x30))();
  if (iVar4 == 0) {
    local_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    FUN_00401740(s_pLabel_009e55c0,6);
    FUN_00406880(auStack_20);
    if (local_8 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_1c);
    return;
  }
  uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x3200003);
  FUN_00401660(uVar5,0,0xffffffff);
  iVar4 = (**(code **)(*DAT_00b5ad0c + 0x70))();
  if (iVar4 == 1) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24._1_3_ << 8);
    pcVar6 = acStack_36 + -10;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_36 + -10,(int)pcVar6 - (int)(acStack_36 + -9));
    FUN_0055a260(auStack_28);
  }
  else {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24._1_3_ << 8);
    FUN_00401740(&DAT_009e55c8,1);
    FUN_0055a260(auStack_28);
  }
  if (uStack_10 < 0x10) {
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_006db2c0 @ 0x006db2c0 ====

uint FUN_006db2c0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x70040011) {
    uVar1 = FUN_006db130();
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006db2e0 @ 0x006db2e0 ====

void FUN_006db2e0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 auStack_62 [10];
  undefined1 auStack_58 [4];
  void *local_54;
  uint local_50;
  undefined4 uStack_4c;
  undefined4 uStack_44;
  uint local_40;
  undefined4 local_3c;
  void *pvStack_38;
  undefined1 local_34;
  int iStack_28;
  uint local_24;
  undefined4 local_20;
  void *pvStack_1c;
  uint uStack_8;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  local_3c = 0xf;
  local_40 = 0;
  local_50 = local_50 & 0xffffff00;
  FUN_00401740(s_edit_text_009e5600,9);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_54);
  if (0xf < local_40) {
    _free(local_54);
    return;
  }
  local_40 = 0xf;
  uStack_44 = 0;
  local_54 = (void *)((uint)local_54 & 0xffffff00);
  if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x30))(), iVar3 != 0)) {
    FUN_00550970(&local_3c);
    FUN_005514b0();
    if (iStack_28 == 0) {
      if (local_24 < 0x10) {
        return;
      }
      _free(pvStack_38);
      return;
    }
    local_54 = (void *)0x0;
    local_50 = 0;
    uStack_4c = 0;
    FUN_00401830(&DAT_009e560c);
    FUN_00406720(&local_20);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    FUN_00401830(&DAT_009e5610);
    FUN_00406720(&local_20);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    FUN_00401830(&DAT_009e5614);
    FUN_00406720(&local_20);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    FUN_00401830(s___BS___009e5618);
    FUN_00406720(&local_20);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    FUN_00401830(s___GT___009e5620);
    FUN_00406720(&local_20);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    FUN_00401830(s___LT___009e5628);
    FUN_00406720(&local_20);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    uVar4 = FUN_00404a40(&local_20,&local_3c,auStack_58,auStack_62 + -6);
    FUN_00401660(uVar4,0,0xffffffff);
    piVar1 = DAT_00b5ae3c;
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    FUN_00401660(&local_3c,0,0xffffffff);
    FUN_00401660(in_ECX + 8,0,0xffffffff);
    (**(code **)(*piVar1 + 0x94))();
    FUN_006db090(piVar2);
    FUN_00406250();
    FUN_00406250();
  }
  if (local_24 < 0x10) {
    return;
  }
  _free(pvStack_38);
  return;
}


// ==== FUN_006db590 @ 0x006db590 ====

/* WARNING: Removing unreachable block (ram,0x006db6e1) */
/* WARNING: Removing unreachable block (ram,0x006db733) */
/* WARNING: Removing unreachable block (ram,0x006db646) */

void FUN_006db590(void)

{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int in_ECX;
  int unaff_ESI;
  uint unaff_EDI;
  undefined1 auStack_66 [46];
  undefined1 auStack_38 [56];
  
  piVar2 = DAT_00b5ae3c;
  FUN_00401660(in_ECX + 8,0,0xffffffff);
  puVar1 = (undefined1 *)(**(code **)(*piVar2 + 0x84))();
  if ((puVar1 != (undefined1 *)0x0) && (*puVar1 = 1, puVar1[1] != '\0')) {
    FUN_00401740(&DAT_009e55ca,0);
    FUN_00401740(s_textview_009e55cc,8);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_66 + -10);
    if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x30))(), iVar3 != 0)) {
      FUN_00401830(&DAT_009e55d5);
      if (*(int *)(puVar1 + 0x38) != 0) {
        FUN_006dc6f0(puVar1 + 0x28);
        while (unaff_ESI != 0) {
          uVar4 = unaff_EDI;
          if (0xe < unaff_EDI) {
            uVar4 = unaff_EDI - 0xf;
          }
          uVar5 = FUN_00402220(auStack_66 + -10,*(undefined4 *)(uVar4 * 4),&DAT_009e55d8);
          FUN_00401ff0(uVar5,0,0xffffffff);
          FUN_006dbc00();
        }
        *(undefined1 *)(iVar3 + 0x179) = 1;
        FUN_005569f0(auStack_38,0);
      }
      puVar1[1] = 0;
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  FUN_006dbc50();
  return;
}


// ==== FUN_006db760 @ 0x006db760 ====

undefined4 FUN_006db760(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if (param_1 == 2) {
    if (param_3 == 4) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_edit_text_009e55dc,9);
      if (iVar2 == 0) {
        FUN_006db2e0();
        return 1;
      }
    }
  }
  else if ((param_1 == 1) && (param_3 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009e55e8,8);
    if (iVar2 == 0) {
      iVar2 = *DAT_00b5ae3c;
      FUN_00765c50(in_ECX + 8);
      (**(code **)(iVar2 + 0x14))();
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_save_009e55f4);
    if (cVar1 != '\0') {
      iVar2 = *DAT_00b5ae3c;
      FUN_00765c50(in_ECX + 8);
      (**(code **)(iVar2 + 0x3c))();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006db830 @ 0x006db830 ====

/* WARNING: Removing unreachable block (ram,0x006db9d8) */
/* WARNING: Removing unreachable block (ram,0x006dba1b) */
/* WARNING: Removing unreachable block (ram,0x006db91c) */
/* WARNING: Removing unreachable block (ram,0x006db872) */

void FUN_006db830(void)

{
  uint uVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  uint in_ECX;
  undefined4 uStack_69;
  uint uStack_64;
  uint uStack_60;
  char *pcStack_5c;
  undefined4 uStack_44;
  uint uStack_30;
  
  pcStack_5c = s_UI_Game2_Messenger_ui_chatwnd_tx_009e556c;
  uStack_60 = 0x6db85c;
  FUN_00401740();
  pcStack_5c = (char *)0x6db866;
  uVar1 = FUN_00410500();
  pcStack_5c = (char *)(uVar1 + 0x3c);
  uStack_60 = 0x6db88f;
  uVar2 = (**(code **)(*DAT_00b5a798 + 4))();
  *(undefined4 *)(in_ECX + 4) = uVar2;
  if (uVar1 != 0) {
    uStack_64 = 0x6db8a2;
    uStack_60 = uVar1;
    (**(code **)(*DAT_00b5a7cc + 0x14))();
  }
  uStack_64 = 0x6db8ab;
  uStack_60 = in_ECX;
  (**(code **)(**(int **)(in_ECX + 4) + 0x40))();
  piVar3 = DAT_00b5ae3c;
  uStack_64 = 0xf;
  FUN_00401660(in_ECX + 8,0,0xffffffff);
  piVar3 = (int *)(**(code **)(*piVar3 + 0x74))();
  puVar4 = (undefined4 *)(**(code **)(*piVar3 + 0x14))();
  uStack_69._1_3_ = (undefined3)*puVar4;
  uStack_64 = CONCAT22(uStack_64._2_2_,*(undefined2 *)(puVar4 + 1));
  pcStack_5c = (char *)((uint)pcStack_5c & 0xffffff00);
  FUN_00401740(s_lbl_userName_009e5590,0xc);
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_60);
  uStack_60 = uStack_60 & 0xffffff00;
  if ((piVar5 != (int *)0x0) && (iVar6 = (**(code **)(*piVar5 + 0x30))(), iVar6 != 0)) {
    (**(code **)(*DAT_00b5ad1c + 0x30))((int)register0x00000010 + -0x48,uStack_69);
    (**(code **)(*piVar3 + 0xc))();
    FUN_00401740(s__s__s_009e55a0,5);
    FUN_00404230(&uStack_64);
    if (0xf < uStack_30) {
      _free(uStack_44);
      return;
    }
    FUN_0055a260(&uStack_64);
  }
  uStack_60 = uStack_60 & 0xffffff00;
  FUN_00401740(s_textview_009e55a8,8);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_64);
  uStack_64 = uStack_64 & 0xffffff00;
  puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    uVar2 = (**(code **)(*piVar3 + 4))();
    *puVar4 = &PTR_FUN_009bcd68;
    puVar4[1] = uVar2;
  }
  *(undefined1 *)(puVar4 + 2) = 0;
  (**(code **)(*DAT_00b5ad24 + 4))(puVar4);
  (**(code **)*puVar4)(1);
  FUN_006db130();
  FUN_006db590();
  return;
}


// ==== FUN_006dba90 @ 0x006dba90 ====

void FUN_006dba90(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e5638;
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[1] = 0;
  FUN_00401660(param_1,0,0xffffffff);
  FUN_006db830();
  return;
}


// ==== FUN_006dbad0 @ 0x006dbad0 ====

undefined4 FUN_006dbad0(void)

{
  uint uVar1;
  uint uVar2;
  int *in_ECX;
  
  uVar2 = in_ECX[1];
  uVar1 = *(uint *)(*in_ECX + 8);
  if (uVar1 <= uVar2) {
    uVar2 = uVar2 - uVar1;
  }
  return *(undefined4 *)(*(int *)(*in_ECX + 4) + uVar2 * 4);
}


// ==== FUN_006dbb00 @ 0x006dbb00 ====

undefined4 FUN_006dbb00(int param_1)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  
  iVar1 = *in_ECX;
  uVar2 = in_ECX[1] + param_1;
  if (uVar2 < *(uint *)(iVar1 + 8)) {
    return *(undefined4 *)(*(int *)(iVar1 + 4) + uVar2 * 4);
  }
  return *(undefined4 *)(*(int *)(iVar1 + 4) + (uVar2 - *(uint *)(iVar1 + 8)) * 4);
}


// ==== FUN_006dbb30 @ 0x006dbb30 ====

undefined4 FUN_006dbb30(void)

{
  return 0x4d;
}


// ==== FUN_006dbb40 @ 0x006dbb40 ====

void FUN_006dbb40(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009e5638;
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


// ==== FUN_006dbba0 @ 0x006dbba0 ====

void FUN_006dbba0(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) != 0) {
    uVar3 = *(int *)(in_ECX + 0x10) + -1 + *(int *)(in_ECX + 0xc);
    if (*(uint *)(in_ECX + 8) <= uVar3) {
      uVar3 = uVar3 - *(uint *)(in_ECX + 8);
    }
    iVar2 = *(int *)(*(int *)(in_ECX + 4) + uVar3 * 4);
    if (0xf < *(uint *)(iVar2 + 0x18)) {
      _free(*(void **)(iVar2 + 4));
      return;
    }
    *(undefined4 *)(iVar2 + 0x18) = 0xf;
    *(undefined4 *)(iVar2 + 0x14) = 0;
    *(undefined1 *)(iVar2 + 4) = 0;
    piVar1 = (int *)(in_ECX + 0x10);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      *(undefined4 *)(in_ECX + 0xc) = 0;
    }
  }
  return;
}


// ==== FUN_006dbc00 @ 0x006dbc00 ====

void FUN_006dbc00(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) != 0) {
    iVar2 = *(int *)(*(int *)(in_ECX + 4) + *(int *)(in_ECX + 0xc) * 4);
    if (0xf < *(uint *)(iVar2 + 0x18)) {
      _free(*(void **)(iVar2 + 4));
      return;
    }
    *(undefined4 *)(iVar2 + 0x18) = 0xf;
    *(undefined4 *)(iVar2 + 0x14) = 0;
    *(undefined1 *)(iVar2 + 4) = 0;
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 1;
    if (*(uint *)(in_ECX + 8) <= *(uint *)(in_ECX + 0xc)) {
      *(undefined4 *)(in_ECX + 0xc) = 0;
    }
    piVar1 = (int *)(in_ECX + 0x10);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      *(undefined4 *)(in_ECX + 0xc) = 0;
    }
  }
  return;
}


// ==== FUN_006dbc50 @ 0x006dbc50 ====

void FUN_006dbc50(void)

{
  int *piVar1;
  void *_Memory;
  uint uVar2;
  int in_ECX;
  int iVar3;
  
  iVar3 = *(int *)(in_ECX + 0x10);
  while (iVar3 != 0) {
    if (*(int *)(in_ECX + 0x10) != 0) {
      uVar2 = *(int *)(in_ECX + 0x10) + -1 + *(int *)(in_ECX + 0xc);
      if (*(uint *)(in_ECX + 8) <= uVar2) {
        uVar2 = uVar2 - *(uint *)(in_ECX + 8);
      }
      iVar3 = *(int *)(*(int *)(in_ECX + 4) + uVar2 * 4);
      if (0xf < *(uint *)(iVar3 + 0x18)) {
        _free(*(void **)(iVar3 + 4));
        return;
      }
      *(undefined4 *)(iVar3 + 0x18) = 0xf;
      *(undefined4 *)(iVar3 + 0x14) = 0;
      *(undefined1 *)(iVar3 + 4) = 0;
      piVar1 = (int *)(in_ECX + 0x10);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        *(undefined4 *)(in_ECX + 0xc) = 0;
      }
    }
    iVar3 = *(int *)(in_ECX + 0x10);
  }
  iVar3 = *(int *)(in_ECX + 8);
  while (iVar3 != 0) {
    _Memory = *(void **)(*(int *)(in_ECX + 4) + -4 + iVar3 * 4);
    iVar3 = iVar3 + -1;
    if (_Memory != (void *)0x0) {
      _free(_Memory);
      return;
    }
  }
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_006dbcf0 @ 0x006dbcf0 ====

void FUN_006dbcf0(undefined4 *param_1,int param_2,uint param_3,int param_4,uint param_5,
                 undefined4 param_6,int param_7)

{
  uint uVar1;
  
  for (; (param_2 != param_4 || (param_3 != param_5)); param_3 = param_3 + 1) {
    uVar1 = param_3;
    if (*(uint *)(param_2 + 8) <= param_3) {
      uVar1 = param_3 - *(uint *)(param_2 + 8);
    }
    FUN_00401660(*(undefined4 *)(*(int *)(param_2 + 4) + uVar1 * 4),0,0xffffffff);
    param_7 = param_7 + 1;
  }
  param_1[1] = param_7;
  *param_1 = param_6;
  return;
}


// ==== FUN_006dbd60 @ 0x006dbd60 ====

void FUN_006dbd60(undefined4 *param_1,int param_2,uint param_3,int param_4,uint param_5,
                 undefined4 param_6,int param_7)

{
  uint uVar1;
  
  while ((param_2 != param_4 || (param_3 != param_5))) {
    param_5 = param_5 - 1;
    uVar1 = param_5;
    if (*(uint *)(param_4 + 8) <= param_5) {
      uVar1 = param_5 - *(uint *)(param_4 + 8);
    }
    param_7 = param_7 + -1;
    FUN_00401660(*(undefined4 *)(*(int *)(param_4 + 4) + uVar1 * 4),0,0xffffffff);
  }
  param_1[1] = param_7;
  *param_1 = param_6;
  return;
}


// ==== FUN_006dbdd0 @ 0x006dbdd0 ====

undefined4
FUN_006dbdd0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  FUN_006dbcf0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_1);
  return param_1;
}


// ==== FUN_006dbe10 @ 0x006dbe10 ====

undefined4
FUN_006dbe10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  FUN_006dbd60(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_1);
  return param_1;
}


// ==== FUN_006dbe50 @ 0x006dbe50 ====

void FUN_006dbe50(uint param_1)

{
  size_t sVar1;
  uint uVar2;
  undefined4 *_Dst;
  void *pvVar3;
  int in_ECX;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  uVar2 = *(uint *)(in_ECX + 8);
  if (0x9249249 - uVar2 < param_1) {
    uVar2 = FUN_004eb8e0();
  }
  uVar4 = uVar2 >> 1;
  if (uVar4 < 8) {
    uVar4 = 8;
  }
  if ((param_1 < uVar4) && (uVar2 <= 0x9249249 - uVar4)) {
    param_1 = uVar4;
  }
  uVar4 = *(uint *)(in_ECX + 0xc);
  _Dst = operator_new((uVar2 + param_1) * 4);
  iVar5 = uVar4 * 4;
  pvVar3 = (void *)(iVar5 + *(int *)(in_ECX + 4));
  sVar1 = ((*(int *)(in_ECX + 8) * 4 - (int)pvVar3) + *(int *)(in_ECX + 4) >> 2) * 4;
  pvVar3 = _memmove(_Dst + uVar4,pvVar3,sVar1);
  pvVar3 = (void *)((int)pvVar3 + sVar1);
  if (param_1 < uVar4) {
    _memmove(pvVar3,*(void **)(in_ECX + 4),((int)(param_1 * 4) >> 2) * 4);
    pvVar3 = (void *)(param_1 * 4 + *(int *)(in_ECX + 4));
    sVar1 = ((iVar5 - (int)pvVar3) + *(int *)(in_ECX + 4) >> 2) * 4;
    pvVar3 = _memmove(_Dst,pvVar3,sVar1);
    puVar6 = (undefined4 *)((int)pvVar3 + sVar1);
    if (param_1 == 0) goto LAB_006dbf73;
    uVar4 = param_1;
  }
  else {
    sVar1 = (iVar5 >> 2) * 4;
    iVar5 = param_1 - uVar4;
    pvVar3 = _memmove(pvVar3,*(void **)(in_ECX + 4),sVar1);
    if (iVar5 != 0) {
      puVar6 = (undefined4 *)((int)pvVar3 + sVar1);
      for (; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
    }
    if (uVar4 == 0) goto LAB_006dbf73;
    puVar6 = _Dst;
  }
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
LAB_006dbf73:
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
    *(undefined4 **)(in_ECX + 4) = _Dst;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_006dbfa0 @ 0x006dbfa0 ====

void FUN_006dbfa0(void)

{
  int *piVar1;
  void *_Memory;
  uint uVar2;
  int in_ECX;
  int iVar3;
  
  iVar3 = *(int *)(in_ECX + 0x10);
  while (iVar3 != 0) {
    if (*(int *)(in_ECX + 0x10) != 0) {
      uVar2 = *(int *)(in_ECX + 0x10) + -1 + *(int *)(in_ECX + 0xc);
      if (*(uint *)(in_ECX + 8) <= uVar2) {
        uVar2 = uVar2 - *(uint *)(in_ECX + 8);
      }
      iVar3 = *(int *)(*(int *)(in_ECX + 4) + uVar2 * 4);
      if (0xf < *(uint *)(iVar3 + 0x18)) {
        _free(*(void **)(iVar3 + 4));
        return;
      }
      *(undefined4 *)(iVar3 + 0x18) = 0xf;
      *(undefined4 *)(iVar3 + 0x14) = 0;
      *(undefined1 *)(iVar3 + 4) = 0;
      piVar1 = (int *)(in_ECX + 0x10);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        *(undefined4 *)(in_ECX + 0xc) = 0;
      }
    }
    iVar3 = *(int *)(in_ECX + 0x10);
  }
  iVar3 = *(int *)(in_ECX + 8);
  while (iVar3 != 0) {
    _Memory = *(void **)(*(int *)(in_ECX + 4) + -4 + iVar3 * 4);
    iVar3 = iVar3 + -1;
    if (_Memory != (void *)0x0) {
      _free(_Memory);
      return;
    }
  }
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_006dbfb0 @ 0x006dbfb0 ====

void FUN_006dbfb0(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  
  uVar3 = param_3 - *(int *)(in_ECX + 0xc);
  iVar4 = param_5 - param_3;
  if (uVar3 < (uint)((*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0xc)) - param_5)) {
    FUN_006dbd60(&param_2);
    for (; iVar4 != 0; iVar4 = iVar4 + -1) {
      if (*(int *)(in_ECX + 0x10) != 0) {
        iVar2 = *(int *)(*(int *)(in_ECX + 4) + *(int *)(in_ECX + 0xc) * 4);
        if (0xf < *(uint *)(iVar2 + 0x18)) {
          _free(*(void **)(iVar2 + 4));
          return;
        }
        *(undefined4 *)(iVar2 + 0x18) = 0xf;
        *(undefined4 *)(iVar2 + 0x14) = 0;
        *(undefined1 *)(iVar2 + 4) = 0;
        *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 1;
        if (*(uint *)(in_ECX + 8) <= *(uint *)(in_ECX + 0xc)) {
          *(undefined4 *)(in_ECX + 0xc) = 0;
        }
        piVar1 = (int *)(in_ECX + 0x10);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          *(undefined4 *)(in_ECX + 0xc) = 0;
        }
      }
    }
  }
  else {
    FUN_006dbcf0(&param_2,param_4,param_5);
    for (; iVar4 != 0; iVar4 = iVar4 + -1) {
      if (*(int *)(in_ECX + 0x10) != 0) {
        uVar5 = *(int *)(in_ECX + 0x10) + -1 + *(int *)(in_ECX + 0xc);
        if (*(uint *)(in_ECX + 8) <= uVar5) {
          uVar5 = uVar5 - *(uint *)(in_ECX + 8);
        }
        iVar2 = *(int *)(*(int *)(in_ECX + 4) + uVar5 * 4);
        if (0xf < *(uint *)(iVar2 + 0x18)) {
          _free(*(void **)(iVar2 + 4));
          return;
        }
        *(undefined4 *)(iVar2 + 0x18) = 0xf;
        *(undefined4 *)(iVar2 + 0x14) = 0;
        *(undefined1 *)(iVar2 + 4) = 0;
        piVar1 = (int *)(in_ECX + 0x10);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          *(undefined4 *)(in_ECX + 0xc) = 0;
        }
      }
    }
  }
  iVar4 = *(int *)(in_ECX + 0xc);
  *param_1 = in_ECX;
  param_1[1] = iVar4 + uVar3;
  return;
}


// ==== FUN_006dc100 @ 0x006dc100 ====

void FUN_006dc100(undefined4 param_1)

{
  int iVar1;
  void *pvVar2;
  int in_ECX;
  int iVar3;
  
  if (*(uint *)(in_ECX + 8) <= *(int *)(in_ECX + 0x10) + 1U) {
    FUN_006dbe50(1);
  }
  iVar3 = *(int *)(in_ECX + 0xc);
  if (iVar3 == 0) {
    iVar3 = *(int *)(in_ECX + 8);
  }
  iVar3 = iVar3 + -1;
  if (*(int *)(*(int *)(in_ECX + 4) + iVar3 * 4) == 0) {
    pvVar2 = operator_new(0x1c);
    *(void **)(*(int *)(in_ECX + 4) + iVar3 * 4) = pvVar2;
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 4) + iVar3 * 4);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x18) = 0xf;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined1 *)(iVar1 + 4) = 0;
    FUN_00401660(param_1,0,0xffffffff);
  }
  *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + 1;
  *(int *)(in_ECX + 0xc) = iVar3;
  return;
}


// ==== FUN_006dc180 @ 0x006dc180 ====

void FUN_006dc180(undefined4 param_1)

{
  int iVar1;
  void *pvVar2;
  int in_ECX;
  uint uVar3;
  
  if (*(uint *)(in_ECX + 8) <= *(int *)(in_ECX + 0x10) + 1U) {
    FUN_006dbe50(1);
  }
  uVar3 = *(int *)(in_ECX + 0xc) + *(int *)(in_ECX + 0x10);
  if (*(uint *)(in_ECX + 8) <= uVar3) {
    uVar3 = uVar3 - *(uint *)(in_ECX + 8);
  }
  if (*(int *)(*(int *)(in_ECX + 4) + uVar3 * 4) == 0) {
    pvVar2 = operator_new(0x1c);
    *(void **)(*(int *)(in_ECX + 4) + uVar3 * 4) = pvVar2;
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 4) + uVar3 * 4);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x18) = 0xf;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined1 *)(iVar1 + 4) = 0;
    FUN_00401660(param_1,0,0xffffffff);
  }
  *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + 1;
  return;
}


// ==== FUN_006dc200 @ 0x006dc200 ====

void FUN_006dc200(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 int param_6)

{
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_1d4 [4];
  undefined1 local_1c0 [8];
  undefined1 local_1b8 [8];
  undefined1 local_1b0 [8];
  undefined4 local_1a8;
  undefined1 local_1a0 [8];
  undefined4 local_198;
  undefined1 local_190 [8];
  undefined1 local_188 [8];
  undefined4 local_180;
  undefined4 local_178;
  int local_174;
  int local_16c;
  int local_168;
  int local_160;
  int local_15c;
  int local_158;
  int local_154;
  uint local_150;
  int local_148;
  int local_140;
  int local_138;
  int local_130;
  int local_128;
  int local_124;
  int local_11c;
  uint local_118;
  int local_110;
  int local_10c;
  int local_104;
  uint local_100;
  int local_f8;
  uint local_f4;
  int local_ec;
  int local_e8;
  int local_e0;
  int local_dc;
  int local_d4;
  int local_cc;
  int local_c4;
  int local_bc;
  undefined4 local_b4;
  int local_ac;
  int local_a4;
  int local_9c;
  int local_94;
  int local_8c;
  int local_84;
  int local_7c;
  int local_74;
  int local_6c;
  int local_64;
  int local_5c;
  undefined4 local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  int local_38;
  uint local_20;
  uint local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c970;
  local_10 = ExceptionList;
  local_14 = auStack_1d4 + 8;
  local_180 = param_1;
  local_1c = param_2 - *(int *)(in_ECX + 0xc);
  uVar3 = local_1c;
  local_50 = *(int *)(in_ECX + 0x10);
  local_20 = local_50 - local_1c;
  local_1a8 = param_5;
  local_198 = param_3;
  uVar4 = param_6 - param_4;
  if (local_1c < local_20) {
    local_8 = 0;
    if (local_1c < uVar4) {
      local_44 = param_3;
      local_15c = uVar4 - local_1c;
      local_48 = param_4 + local_15c;
      local_4c = param_3;
      ExceptionList = &local_10;
      local_40 = local_48;
      while (cVar1 = FUN_0051b730(&local_4c), cVar1 != '\0') {
        local_48 = local_48 + -1;
        uVar2 = FUN_006dbad0();
        FUN_006dc100(uVar2);
      }
      for (; local_174 = *(int *)(in_ECX + 0xc), local_18 = uVar3, uVar3 != 0; uVar3 = uVar3 - 1) {
        local_10c = local_174;
        local_ac = local_174;
        uVar2 = FUN_006dbb00(uVar4 - 1);
        FUN_006dc100(uVar2);
      }
      local_130 = local_174 + uVar4;
      local_118 = uVar4;
      local_cc = local_174;
      local_9c = local_130;
      FUN_006dbdd0(local_1b8,local_44,local_40,param_5,param_6);
    }
    else {
      ExceptionList = &local_10;
      local_14 = auStack_1d4 + 8;
      for (uVar3 = uVar4; local_160 = *(int *)(in_ECX + 0xc), local_18 = uVar3, uVar3 != 0;
          uVar3 = uVar3 - 1) {
        local_154 = local_160;
        local_74 = local_160;
        uVar2 = FUN_006dbb00(uVar4 - 1);
        FUN_006dc100(uVar2);
      }
      local_140 = local_160 + uVar4;
      local_16c = local_140 + local_1c;
      local_d4 = local_140 + uVar4;
      local_150 = uVar4;
      local_f4 = uVar4;
      local_dc = local_160;
      local_bc = local_140;
      local_64 = local_d4;
      local_5c = local_16c;
      FUN_006dbdd0(local_188);
      local_124 = *(int *)(in_ECX + 0xc);
      local_ec = local_124 + local_1c;
      local_e0 = local_124;
      local_84 = local_ec;
      FUN_006dbdd0(local_190,param_3,param_4,param_5,param_6);
    }
  }
  else {
    local_8 = 2;
    if (local_20 < uVar4) {
      local_58 = param_3;
      local_54 = param_4 + local_20;
      local_3c = param_3;
      ExceptionList = &local_10;
      local_38 = local_54;
      local_14 = auStack_1d4 + 8;
      while (cVar1 = FUN_0051b730(&param_5), cVar1 != '\0') {
        uVar2 = FUN_006dbad0();
        FUN_006dc180(uVar2);
        local_38 = local_38 + 1;
      }
      for (uVar4 = 0; local_f8 = *(int *)(in_ECX + 0xc), local_18 = uVar4, uVar4 < local_20;
          uVar4 = uVar4 + 1) {
        local_158 = local_f8;
        local_94 = local_f8;
        uVar2 = FUN_006dbb00(uVar4 + uVar3);
        FUN_006dc180(uVar2);
      }
      local_104 = local_f8 + uVar3;
      local_e8 = local_f8;
      local_a4 = local_104;
      FUN_006dbdd0(local_1a0,param_3,param_4,local_58,local_54);
    }
    else {
      ExceptionList = &local_10;
      local_14 = auStack_1d4 + 8;
      for (local_18 = 0; local_18 < uVar4; local_18 = local_18 + 1) {
        local_178 = *(undefined4 *)(in_ECX + 0xc);
        local_b4 = local_178;
        uVar2 = FUN_006dbb00((local_18 - uVar4) + local_20 + uVar3);
        FUN_006dc180(uVar2);
      }
      local_168 = *(int *)(in_ECX + 0xc);
      local_11c = local_168 + local_1c;
      local_128 = local_11c + local_20;
      local_138 = local_11c + local_20;
      local_148 = local_138 - uVar4;
      local_110 = local_168;
      local_100 = uVar4;
      local_c4 = local_11c;
      local_8c = local_138;
      local_7c = local_148;
      local_6c = local_128;
      FUN_006dbe10(local_1b0);
      FUN_006dbdd0(local_1c0,param_3,param_4,param_5,param_6);
    }
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@006dc490 @ 0x006dc490 ====

void Catch_006dc490(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int unaff_EBP;
  
  iVar2 = *(int *)(unaff_EBP + -0x30);
  uVar3 = *(uint *)(unaff_EBP + -0x4c);
  uVar1 = *(uint *)(iVar2 + 0x10);
  while (uVar3 < uVar1) {
    FUN_006dbc00();
    uVar1 = *(uint *)(iVar2 + 0x10);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== Catch@006dc6c6 @ 0x006dc6c6 ====

void Catch_006dc6c6(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int unaff_EBP;
  
  iVar2 = *(int *)(unaff_EBP + -0x30);
  uVar3 = *(uint *)(unaff_EBP + -0x4c);
  uVar1 = *(uint *)(iVar2 + 0x10);
  while (uVar3 < uVar1) {
    FUN_006dbba0();
    uVar1 = *(uint *)(iVar2 + 0x10);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006dc6f0 @ 0x006dc6f0 ====

void FUN_006dc6f0(int param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  undefined4 local_8;
  undefined4 local_4;
  
  if (in_ECX != param_1) {
    uVar1 = *(uint *)(param_1 + 0x10);
    if (uVar1 == 0) {
      FUN_006dbc50();
      return;
    }
    iVar2 = *(int *)(param_1 + 0xc);
    if (uVar1 <= *(uint *)(in_ECX + 0x10)) {
      FUN_006dbdd0(&local_8,param_1,iVar2,param_1,uVar1 + iVar2);
      FUN_006dbfb0(&local_8,local_8,local_4,in_ECX,*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0xc))
      ;
      return;
    }
    iVar3 = iVar2 + *(uint *)(in_ECX + 0x10);
    FUN_006dbdd0(&local_8,param_1,iVar2,param_1,iVar3);
    FUN_006dc200(in_ECX,*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0xc),param_1,iVar3,param_1,
                 *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc),param_1);
  }
  return;
}


// ==== FUN_006dc763 @ 0x006dc763 ====

void FUN_006dc763(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int in_EAX;
  int in_ECX;
  int unaff_ESI;
  int unaff_EDI;
  
  FUN_006dbdd0(&param_2);
  FUN_006dc200(unaff_ESI,*(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0xc),unaff_EDI,
               in_EAX + in_ECX,unaff_EDI,*(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0xc),
               param_5);
  return;
}


// ==== FUN_006dc7b0 @ 0x006dc7b0 ====

int FUN_006dc7b0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x58;
}


// ==== FUN_006dc800 @ 0x006dc800 ====

void FUN_006dc800(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
    FUN_00551410(param_1);
  }
  return;
}


// ==== FUN_006dc860 @ 0x006dc860 ====

void FUN_006dc860(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      FUN_0055a260(param_1);
    }
  }
  return;
}


// ==== FUN_006dc890 @ 0x006dc890 ====

uint FUN_006dc890(void)

{
  code *pcVar1;
  int *piVar2;
  uint extraout_EAX;
  byte *pbVar3;
  uint uVar4;
  int in_ECX;
  undefined4 uVar5;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_combo_skybox_009e59ec,0xc);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (piVar2 == (int *)0x0) {
    uVar5 = 0;
  }
  else {
    (**(code **)(*piVar2 + 0x30))();
    uVar5 = FUN_00577d20();
  }
  if (0xf < local_8) {
    _free(local_1c);
    return extraout_EAX;
  }
  pbVar3 = (byte *)(**(code **)(*DAT_00b5acec + 0x18))(uVar5);
  if (pbVar3 == (byte *)0x0) {
    pcVar1 = (code *)swi(3);
    uVar4 = (*pcVar1)();
    return uVar4;
  }
  return (uint)*pbVar3;
}


// ==== FUN_006dc910 @ 0x006dc910 ====

/* WARNING: Removing unreachable block (ram,0x006dc967) */

void FUN_006dc910(undefined4 param_1)

{
  code *pcVar1;
  undefined1 *puVar2;
  int *piVar3;
  int in_ECX;
  undefined1 auStack_1a [26];
  
  puVar2 = (undefined1 *)(**(code **)(*DAT_00b5acec + 0x18))(param_1);
  if (puVar2 == (undefined1 *)0x0) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  FUN_00401740(s_combo_skybox_009e5bdc,0xc);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1a + -6);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x30))();
    FUN_00577df0(*puVar2);
  }
  return;
}


// ==== FUN_006dc9b0 @ 0x006dc9b0 ====

int FUN_006dc9b0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  int unaff_retaddr;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_2);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
    *(undefined4 *)(unaff_retaddr + 0x14) = 0;
    *(undefined1 *)(unaff_retaddr + 4) = 0;
    FUN_00401740(&DAT_009e5c17,0);
    return unaff_retaddr;
  }
  (**(code **)(*piVar1 + 0x30))();
  uVar2 = FUN_00550150();
  *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
  *(undefined4 *)(unaff_retaddr + 0x14) = 0;
  *(undefined1 *)(unaff_retaddr + 4) = 0;
  FUN_00401660(uVar2,0,0xffffffff);
  return unaff_retaddr;
}


// ==== FUN_006dca20 @ 0x006dca20 ====

int FUN_006dca20(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int unaff_retaddr;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_2);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
    *(undefined4 *)(unaff_retaddr + 0x14) = 0;
    *(undefined1 *)(unaff_retaddr + 4) = 0;
    FUN_00401740(&DAT_009e5c18,0);
    return unaff_retaddr;
  }
  iVar2 = (**(code **)(*piVar1 + 0x30))();
  *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
  *(undefined4 *)(unaff_retaddr + 0x14) = 0;
  *(undefined1 *)(unaff_retaddr + 4) = 0;
  FUN_00401660(iVar2 + 0xa0,0,0xffffffff);
  return unaff_retaddr;
}


// ==== FUN_006dca90 @ 0x006dca90 ====

undefined4 FUN_006dca90(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined4 uVar3;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  iVar1 = FUN_006e0ef0(param_1);
  if ((iVar1 == 0) || (iVar1 == 0x1d)) {
    return 0;
  }
  uVar3 = *(undefined4 *)(in_ECX + 0x18);
  FUN_00401740(&DAT_009e5c2c,2);
  uVar2 = FUN_00404230(local_1c);
  FUN_006e14e0(uVar2,iVar1,uVar3);
  if (local_4 < 0x10) {
    return 1;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_006dcb20 @ 0x006dcb20 ====

void FUN_006dcb20(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 auStack_cc [4];
  void *pvStack_c8;
  undefined4 uStack_b8;
  uint uStack_b4;
  undefined1 auStack_b0 [4];
  void *pvStack_ac;
  undefined4 uStack_9c;
  uint uStack_98;
  int *local_94;
  undefined4 auStack_90 [29];
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined1 uStack_18;
  undefined1 uStack_17;
  
  local_94 = DAT_00b5ac58;
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5ac58 + 0x30))();
  puVar4 = auStack_90;
  for (iVar3 = 0x21; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar4 = puVar4 + 1;
  }
  uStack_b4 = 0xf;
  uStack_b8 = 0;
  pvStack_c8 = (void *)((uint)pvStack_c8 & 0xffffff00);
  FUN_00401740(s_edt_cloud_type_009e5720,0xe);
  uVar2 = FUN_006dc9b0(auStack_b0,auStack_cc);
  uStack_1b = thunk_FUN_00796f50(uVar2);
  if (0xf < uStack_98) {
    _free(pvStack_ac);
    return;
  }
  uStack_98 = 0xf;
  uStack_9c = 0;
  pvStack_ac = (void *)((uint)pvStack_ac & 0xffffff00);
  if (0xf < uStack_b4) {
    _free(pvStack_c8);
    return;
  }
  uStack_b4 = 0xf;
  uStack_b8 = 0;
  pvStack_c8 = (void *)((uint)pvStack_c8 & 0xffffff00);
  FUN_00401740(s_edt_cloud_dir_009e5730,0xd);
  uVar2 = FUN_006dc9b0(auStack_b0,auStack_cc);
  uStack_1a = thunk_FUN_00796f50(uVar2);
  if (0xf < uStack_98) {
    _free(pvStack_ac);
    return;
  }
  uStack_98 = 0xf;
  uStack_9c = 0;
  pvStack_ac = (void *)((uint)pvStack_ac & 0xffffff00);
  if (0xf < uStack_b4) {
    _free(pvStack_c8);
    return;
  }
  uStack_b4 = 0xf;
  uStack_b8 = 0;
  pvStack_c8 = (void *)((uint)pvStack_c8 & 0xffffff00);
  FUN_00401740(s_edt_cloud_speed_009e5740,0xf);
  uVar2 = FUN_006dc9b0(auStack_b0,auStack_cc);
  uStack_19 = thunk_FUN_00796f50(uVar2);
  if (0xf < uStack_98) {
    _free(pvStack_ac);
    return;
  }
  uStack_98 = 0xf;
  uStack_9c = 0;
  pvStack_ac = (void *)((uint)pvStack_ac & 0xffffff00);
  if (0xf < uStack_b4) {
    _free(pvStack_c8);
    return;
  }
  uStack_b4 = 0xf;
  uStack_b8 = 0;
  pvStack_c8 = (void *)((uint)pvStack_c8 & 0xffffff00);
  FUN_00401740(s_edt_cloud_alpha_009e5750,0xf);
  uVar2 = FUN_006dc9b0(auStack_b0,auStack_cc);
  uStack_18 = thunk_FUN_00796f50(uVar2);
  if (0xf < uStack_98) {
    _free(pvStack_ac);
    return;
  }
  uStack_98 = 0xf;
  uStack_9c = 0;
  pvStack_ac = (void *)((uint)pvStack_ac & 0xffffff00);
  if (0xf < uStack_b4) {
    _free(pvStack_c8);
    return;
  }
  uStack_b4 = 0xf;
  uStack_b8 = 0;
  pvStack_c8 = (void *)((uint)pvStack_c8 & 0xffffff00);
  FUN_00401740(s_edt_cloud_inout_009e5760,0xf);
  uVar2 = FUN_006dc9b0(auStack_b0,auStack_cc);
  uStack_17 = thunk_FUN_00796f50(uVar2);
  if (0xf < uStack_98) {
    _free(pvStack_ac);
    return;
  }
  uStack_98 = 0xf;
  uStack_9c = 0;
  pvStack_ac = (void *)((uint)pvStack_ac & 0xffffff00);
  if (uStack_b4 < 0x10) {
    (**(code **)(*local_94 + 0x38))(auStack_90);
    return;
  }
  _free(pvStack_c8);
  return;
}


// ==== FUN_006dcda0 @ 0x006dcda0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006dcda0(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  void *unaff_EBX;
  float10 fVar6;
  void *_Memory;
  undefined4 local_c8;
  void *local_c4;
  undefined4 uStack_bc;
  uint uStack_b8;
  uint local_b4;
  void *local_b0;
  undefined1 local_ac [4];
  void *pvStack_a8;
  undefined4 uStack_a0;
  uint uStack_9c;
  undefined4 uStack_98;
  uint uStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float local_84;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  undefined4 uStack_34;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  float fStack_20;
  float fStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_c;
  undefined4 local_8;
  
  FUN_004b6dd0();
  local_8 = *(undefined4 *)(in_ECX + 0x18);
  local_b0 = (void *)0xf;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  FUN_00401740(s_sld_amb_r_lbl_009e585c,0xd);
  uVar3 = FUN_006dca20(local_ac,&local_c8);
  fVar6 = (float10)thunk_FUN_00796ec0(uVar3);
  fStack_90 = (float)(fVar6 * (float10)_DAT_009ae954);
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < local_b0) {
    _free(local_c4);
    return;
  }
  local_b0 = (void *)0xf;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  FUN_00401740(s_sld_amb_g_lbl_009e586c,0xd);
  uVar3 = FUN_006dca20(local_ac,&local_c8);
  fVar6 = (float10)thunk_FUN_00796ec0(uVar3);
  fStack_8c = (float)(fVar6 * (float10)_DAT_009ae954);
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < local_b0) {
    _free(local_c4);
    return;
  }
  local_b0 = (void *)0xf;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  FUN_00401740(s_sld_amb_b_lbl_009e587c,0xd);
  uVar3 = FUN_006dca20(local_ac,&local_c8);
  fVar6 = (float10)thunk_FUN_00796ec0(uVar3);
  fStack_88 = (float)(fVar6 * (float10)_DAT_009ae954);
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < local_b0) {
    _free(local_c4);
    return;
  }
  fStack_40 = fStack_90;
  fStack_3c = fStack_8c;
  local_b0 = (void *)0xf;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  fStack_38 = fStack_88;
  FUN_00401740(s_sld_dir_r_lbl_009e588c,0xd);
  uVar3 = FUN_006dca20(local_ac,&local_c8);
  fVar6 = (float10)thunk_FUN_00796ec0(uVar3);
  fStack_90 = (float)(fVar6 * (float10)_DAT_009ae954);
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < local_b0) {
    _free(local_c4);
    return;
  }
  local_b0 = (void *)0xf;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  FUN_00401740(s_sld_dir_g_lbl_009e589c,0xd);
  uVar3 = FUN_006dca20(local_ac,&local_c8);
  fVar6 = (float10)thunk_FUN_00796ec0(uVar3);
  fStack_8c = (float)(fVar6 * (float10)_DAT_009ae954);
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < local_b0) {
    _free(local_c4);
    return;
  }
  local_b0 = (void *)0xf;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  FUN_00401740(s_sld_dir_b_lbl_009e58ac,0xd);
  uVar3 = FUN_006dca20(local_ac,&local_c8);
  fVar6 = (float10)thunk_FUN_00796ec0(uVar3);
  fStack_88 = (float)(fVar6 * (float10)_DAT_009ae954);
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < local_b0) {
    _free(local_c4);
    return;
  }
  fStack_64 = fStack_90;
  fStack_60 = fStack_8c;
  local_b0 = (void *)0xf;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  fStack_5c = fStack_88;
  FUN_00401740(s_sld_fog_r_lbl_009e58bc,0xd);
  uVar3 = FUN_006dca20(local_ac,&local_c8);
  fVar6 = (float10)thunk_FUN_00796ec0(uVar3);
  fStack_90 = (float)(fVar6 * (float10)_DAT_009ae954);
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < local_b0) {
    _free(local_c4);
    return;
  }
  local_b0 = (void *)0xf;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  FUN_00401740(s_sld_fog_g_lbl_009e58cc,0xd);
  uVar3 = FUN_006dca20(local_ac,&local_c8);
  fVar6 = (float10)thunk_FUN_00796ec0(uVar3);
  fStack_8c = (float)(fVar6 * (float10)_DAT_009ae954);
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < local_b0) {
    _free(local_c4);
    return;
  }
  local_b0 = (void *)0xf;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  FUN_00401740(s_sld_fog_b_lbl_009e58dc,0xd);
  uVar3 = FUN_006dca20(local_ac,&local_c8);
  fVar6 = (float10)thunk_FUN_00796ec0(uVar3);
  fStack_88 = (float)(fVar6 * (float10)_DAT_009ae954);
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < local_b0) {
    _free(local_c4);
    return;
  }
  fStack_7c = fStack_90;
  fStack_78 = fStack_8c;
  local_b0 = (void *)0xf;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  fStack_74 = fStack_88;
  FUN_00401740(s_sld_dir_x_lbl_009e58ec,0xd);
  uVar3 = FUN_006dca20(local_ac,&local_c8);
  fVar6 = (float10)thunk_FUN_00796ec0(uVar3);
  fStack_90 = (float)((fVar6 - (float10)_DAT_009e5ccc) * (float10)_DAT_009e5cc8);
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < local_b0) {
    _free(local_c4);
    return;
  }
  local_b0 = (void *)0xf;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  FUN_00401740(s_sld_dir_y_lbl_009e58fc,0xd);
  uVar3 = FUN_006dca20(local_ac,&local_c8);
  fVar6 = (float10)thunk_FUN_00796ec0(uVar3);
  fStack_8c = (float)((fVar6 - (float10)_DAT_009e5ccc) * (float10)_DAT_009e5cc8);
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < local_b0) {
    _free(local_c4);
    return;
  }
  local_b0 = (void *)0xf;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  FUN_00401740(s_sld_dir_z_lbl_009e590c,0xd);
  uVar3 = FUN_006dca20(local_ac,&local_c8);
  fVar6 = (float10)thunk_FUN_00796ec0(uVar3);
  fStack_88 = (float)((fVar6 - (float10)_DAT_009e5ccc) * (float10)_DAT_009e5cc8);
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < local_b0) {
    _free(local_c4);
    return;
  }
  fStack_70 = fStack_90;
  fStack_6c = fStack_8c;
  local_b0 = (void *)0xf;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  fStack_68 = fStack_88;
  FUN_00401740(s_sld_fog_near_lbl_009e591c,0x10);
  uVar3 = FUN_006dca20(local_ac,&local_c8);
  fVar6 = (float10)thunk_FUN_00796ec0(uVar3);
  local_84 = (float)fVar6;
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < local_b0) {
    _free(local_c4);
    return;
  }
  local_b0 = (void *)0xf;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  FUN_00401740(s_sld_cam_far_lbl_009e5930,0xf);
  uVar3 = FUN_006dca20(local_ac,&local_c8);
  fVar6 = (float10)thunk_FUN_00796ec0(uVar3);
  *(float *)(in_ECX + 0x1c) = (float)fVar6;
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < local_b0) {
    _free(local_c4);
    return;
  }
  local_b0 = (void *)0xf;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  FUN_00401740(s_sld_shade_d_lbl_009e5940,0xf);
  uVar3 = FUN_006dca20(local_ac,&local_c8);
  fVar6 = (float10)thunk_FUN_00796ec0(uVar3);
  uStack_34 = (float)fVar6;
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < local_b0) {
    _free(local_c4);
    return;
  }
  local_b0 = (void *)0xf;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  FUN_00401740(s_sld_bloom_p_lbl_009e5950,0xf);
  uVar3 = FUN_006dca20(local_ac,&local_c8);
  fVar6 = (float10)thunk_FUN_00796ec0(uVar3);
  fStack_20 = (float)fVar6;
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < local_b0) {
    _free(local_c4);
    return;
  }
  local_b0 = (void *)0xf;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  FUN_00401740(s_sld_bloom_w_lbl_009e5960,0xf);
  uVar3 = FUN_006dca20(local_ac,&local_c8);
  fVar6 = (float10)thunk_FUN_00796ec0(uVar3);
  fStack_1c = (float)fVar6;
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < local_b0) {
    _free(local_c4);
    return;
  }
  local_b0 = (void *)0xf;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  FUN_00401740(s_sld_bloom_f_lbl_009e5970,0xf);
  uVar3 = FUN_006dca20(local_ac,&local_c8);
  fVar6 = (float10)thunk_FUN_00796ec0(uVar3);
  uStack_18 = (float)fVar6;
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < local_b0) {
    _free(local_c4);
    return;
  }
  local_b0 = (void *)0xf;
  local_b4 = 0;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  FUN_00401740(s_combo_size_009e5980,10);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_c8);
  if (piVar4 == (int *)0x0) {
    iVar5 = 0;
  }
  else {
    (**(code **)(*piVar4 + 0x30))();
    iVar5 = FUN_00577d20();
  }
  uStack_18 = (float)iVar5;
  if (0xf < local_b4) {
    _free(local_c8);
    return;
  }
  uStack_28 = *(undefined1 *)(in_ECX + 0x12);
  uStack_34 = (float)CONCAT31(uStack_34._1_3_,*(undefined1 *)(in_ECX + 0x13));
  uStack_2c = 100000;
  uStack_34 = (float)CONCAT22(100,(undefined2)uStack_34);
  local_b4 = 0xf;
  uStack_b8 = 0;
  local_c8 = (void *)((uint)local_c8 & 0xffffff00);
  FUN_00401740(s_combo_weather_s_009e598c,0xf);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_ac + -0x20);
  if (piVar4 == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    (**(code **)(*piVar4 + 0x30))();
    uVar2 = FUN_00577d20();
  }
  uStack_34 = (float)CONCAT22(uStack_34._2_2_,uVar2);
  if (0xf < uStack_b8) {
    _free(unaff_EBX);
    return;
  }
  uVar1 = FUN_006dc890();
  uStack_18 = (float)CONCAT31(uStack_18._1_3_,uVar1);
  uStack_b8 = 0xf;
  uStack_bc = 0;
  _Memory = (void *)((uint)unaff_EBX & 0xffffff00);
  FUN_00401740(s_edt_cloud_type_009e599c,0xe);
  uVar3 = FUN_006dc9b0(&local_b4,local_ac + -0x24);
  uVar1 = thunk_FUN_00796f50(uVar3);
  uStack_18._0_2_ = CONCAT11(uVar1,(undefined1)uStack_18);
  if (0xf < uStack_9c) {
    _free(local_b0);
    return;
  }
  uStack_9c = 0xf;
  uStack_a0 = 0;
  local_b0 = (void *)((uint)local_b0 & 0xffffff00);
  if (0xf < uStack_b8) {
    _free(_Memory);
    return;
  }
  FUN_00401830(s_edt_cloud_dir_009e59ac);
  uVar3 = FUN_006dc9b0(&local_b4,local_ac + -0x24);
  uVar1 = thunk_FUN_00796f50(uVar3);
  uStack_18._0_3_ = CONCAT12(uVar1,(undefined2)uStack_18);
  if (0xf < uStack_9c) {
    _free(local_b0);
    return;
  }
  uStack_9c = 0xf;
  uStack_a0 = 0;
  local_b0 = (void *)((uint)local_b0 & 0xffffff00);
  if (0xf < uStack_b8) {
    _free(_Memory);
    return;
  }
  FUN_00401830(s_edt_cloud_speed_009e59bc);
  uVar3 = FUN_006dc9b0(&local_b4,local_ac + -0x24);
  uVar1 = thunk_FUN_00796f50(uVar3);
  uStack_18 = (float)CONCAT13(uVar1,(undefined3)uStack_18);
  if (0xf < uStack_9c) {
    _free(local_b0);
    return;
  }
  uStack_9c = 0xf;
  uStack_a0 = 0;
  local_b0 = (void *)((uint)local_b0 & 0xffffff00);
  if (0xf < uStack_b8) {
    _free(_Memory);
    return;
  }
  FUN_00401830(s_edt_cloud_alpha_009e59cc);
  uVar3 = FUN_006dc9b0(&local_b4,local_ac + -0x24);
  uStack_14 = thunk_FUN_00796f50(uVar3);
  if (0xf < uStack_9c) {
    _free(local_b0);
    return;
  }
  uStack_9c = 0xf;
  uStack_a0 = 0;
  local_b0 = (void *)((uint)local_b0 & 0xffffff00);
  if (0xf < uStack_b8) {
    _free(_Memory);
    return;
  }
  FUN_00401830(s_edt_cloud_inout_009e59dc);
  uVar3 = FUN_006dc9b0(&local_b4,local_ac + -0x24);
  uStack_13 = thunk_FUN_00796f50(uVar3);
  if (0xf < uStack_9c) {
    _free(local_b0);
    return;
  }
  uStack_9c = 0xf;
  uStack_a0 = 0;
  local_b0 = (void *)((uint)local_b0 & 0xffffff00);
  if (uStack_b8 < 0x10) {
    uStack_c = *(undefined1 *)(in_ECX + 0x11);
    FUN_006e18d0(&fStack_8c);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_006dd940 @ 0x006dd940 ====

void FUN_006dd940(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int in_ECX;
  void *unaff_EBX;
  undefined1 auStack_36 [14];
  uint uStack_28;
  void *apvStack_20 [5];
  uint uStack_c;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      FUN_00579b40(param_1);
      FUN_00401740(&DAT_009e5bec,2);
      uVar3 = FUN_00404230(apvStack_20);
      uVar4 = FUN_00402220(auStack_36 + -6,param_1,&DAT_009e5bf0);
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar4);
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 0x30))();
        if (iVar2 != 0) {
          FUN_0055a260(uVar3);
        }
      }
      if (0xf < uStack_28) {
        _free(unaff_EBX);
        return;
      }
      if (0xf < uStack_c) {
        _free(apvStack_20[0]);
        return;
      }
    }
  }
  return;
}


// ==== FUN_006dda20 @ 0x006dda20 ====

void FUN_006dda20(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *unaff_EBX;
  undefined1 auStack_36 [14];
  uint uStack_28;
  void *apvStack_20 [5];
  uint uStack_c;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      thunk_FUN_005799c0();
      FUN_00401740(&DAT_009e5bf8,4);
      uVar3 = FUN_00404230(apvStack_20);
      FUN_00402220(auStack_36 + -6,param_1,&DAT_009e5c00);
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 0x30))();
        if (iVar2 != 0) {
          FUN_0055a260(uVar3);
        }
      }
      if (0xf < uStack_28) {
        _free(unaff_EBX);
        return;
      }
      if (0xf < uStack_c) {
        _free(apvStack_20[0]);
        return;
      }
    }
  }
  return;
}


// ==== FUN_006ddb10 @ 0x006ddb10 ====

void FUN_006ddb10(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  void *local_58 [4];
  undefined4 uStack_48;
  uint uStack_44;
  undefined1 auStack_40 [32];
  void *pvStack_20;
  uint uStack_c;
  
  iVar1 = **(int **)(in_ECX + 4);
  uVar2 = FUN_00402220(local_58,param_1,s__check_009e5c08);
  piVar3 = (int *)(**(code **)(iVar1 + 0x34))(uVar2);
  if (0xf < uStack_44) {
    _free(local_58[0]);
    return;
  }
  uStack_44 = 0xf;
  uStack_48 = 0;
  local_58[0] = (void *)((uint)local_58[0] & 0xffffff00);
  if (piVar3 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar3 + 0x10))();
    FUN_005041e0(uVar2);
    auStack_40[0] = (undefined1)param_1;
    (**(code **)(*piVar3 + 0xc))(auStack_40);
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return;
    }
  }
  return;
}


// ==== FUN_006ddbb0 @ 0x006ddbb0 ====

uint FUN_006ddbb0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  uint extraout_EAX;
  uint extraout_EAX_00;
  int in_ECX;
  void *local_58 [4];
  undefined4 uStack_48;
  uint uStack_44;
  char acStack_40 [32];
  void *pvStack_20;
  uint uStack_c;
  
  iVar1 = **(int **)(in_ECX + 4);
  uVar2 = FUN_00402220(local_58,param_1,s__check_009e5c10);
  piVar3 = (int *)(**(code **)(iVar1 + 0x34))(uVar2);
  if (0xf < uStack_44) {
    _free(local_58[0]);
    return extraout_EAX;
  }
  uStack_44 = 0xf;
  uStack_48 = 0;
  local_58[0] = (void *)((uint)local_58[0] & 0xffffff00);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  uVar2 = (**(code **)(*piVar3 + 0x10))();
  FUN_005041e0(uVar2);
  acStack_40[0] = acStack_40[0] != '\x01';
  (**(code **)(*piVar3 + 0xc))(acStack_40);
  if (uStack_c < 0x10) {
    return uStack_44 & 0xff;
  }
  _free(pvStack_20);
  return extraout_EAX_00;
}


// ==== FUN_006ddc60 @ 0x006ddc60 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006ddc60(int param_1)

{
  undefined1 uVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  void *unaff_EDI;
  void **ppvVar4;
  void **ppvVar5;
  uint uVar6;
  uint in_stack_ffffff8c;
  undefined4 *_Memory;
  void **_Memory_00;
  undefined4 local_3c;
  void *local_38;
  void *local_34;
  void *pvStack_30;
  void *pvStack_2c;
  void *pvStack_28;
  void *local_24;
  uint local_20;
  uint uStack_1c;
  uint uStack_18;
  uint uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  int iStack_4;
  
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  FUN_006dda20();
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  FUN_006dda20();
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  FUN_006dda20();
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  FUN_006dda20();
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  FUN_006dda20();
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  FUN_006dda20();
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  FUN_006dda20();
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  FUN_006dda20();
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  FUN_006dda20();
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  FUN_006dda20();
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  FUN_006dda20();
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  FUN_006dda20();
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  FUN_006dda20();
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  FUN_006dda20();
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  FUN_006dda20();
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  *(undefined1 *)(in_ECX + 0x12) = *(undefined1 *)(param_1 + 0x60);
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  FUN_006ddb10();
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  _Memory_00 = &local_38;
  local_3c = (void *)(int)ROUND(*(float *)(param_1 + 0x70));
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_00577df0();
  }
  if ((void *)0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = (void *)0xf;
  pvStack_28 = (void *)0x0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  FUN_00401740(s_sld_bloom_p_009e5ae4);
  FUN_006dda20(&local_3c);
  if ((void *)0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = (void *)0xf;
  pvStack_28 = (void *)0x0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  FUN_00401740(s_sld_bloom_w_009e5af0);
  FUN_006dda20(&local_3c);
  if ((void *)0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = (void *)0xf;
  pvStack_28 = (void *)0x0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  FUN_00401740(s_sld_bloom_f_009e5afc);
  FUN_006dda20(&local_3c);
  if ((void *)0xf < local_24) {
    _free(local_38);
    return;
  }
  *(undefined1 *)(in_ECX + 0x13) = *(undefined1 *)(param_1 + 0x54);
  local_24 = (void *)0xf;
  pvStack_28 = (void *)0x0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  FUN_00401740(s_pan_weather_enable_009e5b08);
  FUN_006ddb10(&local_3c);
  if ((void *)0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = (void *)0xf;
  pvStack_28 = (void *)0x0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  FUN_00401740(s_combo_weather_s_009e5b1c);
  _Memory = &local_3c;
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_00577df0(iStack_4 + -1);
  }
  if ((void *)0xf < pvStack_28) {
    _free(local_3c);
    return;
  }
  FUN_006dc910(*(undefined1 *)(param_1 + 0x74));
  *(undefined1 *)(in_ECX + 0x11) = *(undefined1 *)(param_1 + 0x80);
  pvStack_28 = (void *)0xf;
  pvStack_2c = (void *)0x0;
  local_3c = (void *)((uint)local_3c & 0xffffff00);
  FUN_00401740(s_pan_night_enable_009e5b2c,0x10);
  FUN_006ddb10((int)register0x00000010 + -0x40,*(undefined1 *)(in_ECX + 0x11));
  if ((void *)0xf < pvStack_28) {
    _free(local_3c);
    return;
  }
  pvStack_28 = (void *)0xf;
  pvStack_2c = (void *)0x0;
  local_3c = (void *)((uint)local_3c & 0xffffff00);
  FUN_00401740(s_edit_time_009e5b44,9);
  FUN_00401740(&DAT_009e5b40,2);
  ppvVar5 = &local_24;
  iStack_4 = FUN_00404230(ppvVar5);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x40);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_00551410(uStack_8);
  }
  if (0xf < uStack_10) {
    _free(local_24);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if ((void *)0xf < pvStack_2c) {
    _free(unaff_EBX);
    return;
  }
  pvStack_2c = (void *)0xf;
  pvStack_30 = (void *)0x0;
  FUN_00401740(s_edt_cloud_type_009e5b54,0xe);
  in_stack_ffffff8c = in_stack_ffffff8c & 0xffffff00;
  FUN_00401740(&DAT_009e5b50,2);
  ppvVar4 = &pvStack_28;
  uStack_8 = FUN_00404230(ppvVar4,ppvVar5,in_stack_ffffff8c);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x44);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_00551410(uStack_c);
  }
  if (0xf < uStack_14) {
    _free(pvStack_28);
    return;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  if ((void *)0xf < pvStack_30) {
    _free(unaff_EBP);
    return;
  }
  pvStack_30 = (void *)0xf;
  local_34 = (void *)0x0;
  FUN_00401740(s_edt_cloud_dir_009e5b68,0xd);
  uVar6 = (uint)ppvVar5 & 0xffffff00;
  FUN_00401740(&DAT_009e5b64,2);
  uStack_c = FUN_00404230(&pvStack_2c,ppvVar4,uVar6);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x48);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_00551410(uStack_10);
  }
  if (0xf < uStack_18) {
    _free(pvStack_2c);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
  if ((void *)0xf < local_34) {
    _free(unaff_ESI);
    return;
  }
  FUN_00401830(s_edt_cloud_speed_009e5b7c);
  FUN_00401830(&DAT_009e5b78);
  uStack_10 = FUN_00404230(&pvStack_30);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x4c);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_00551410(uStack_14);
  }
  if (0xf < uStack_1c) {
    _free(pvStack_30);
    return;
  }
  uStack_1c = 0xf;
  local_20 = 0;
  pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
  if ((void *)0xf < local_38) {
    _free(unaff_EDI);
    return;
  }
  FUN_00401830(s_edt_cloud_alpha_009e5b90);
  FUN_00401830(&DAT_009e5b8c);
  uStack_14 = FUN_00404230(&local_34);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x50);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_00551410(uStack_18);
  }
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  if (0xf < local_3c) {
    _free(_Memory_00);
    return;
  }
  FUN_00401830(s_edt_cloud_inout_009e5ba4);
  FUN_00401830(&DAT_009e5ba0);
  uVar3 = FUN_00404230(&local_38);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x54);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_00551410(uVar3);
  }
  if ((void *)0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = (void *)0xf;
  pvStack_28 = (void *)0x0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  if (0xf < ((uint)unaff_EBX & 0xffffff00)) {
    _free(_Memory);
    return;
  }
  uVar1 = (**(code **)(*DAT_00b5ac58 + 0x40))();
  *(undefined1 *)(in_ECX + 0x10) = uVar1;
  FUN_00401830(s_pan_anim_enable_009e5bb4);
  FUN_006ddb10(&local_3c,*(undefined1 *)(in_ECX + 0x10));
  if (local_24 < (void *)0x10) {
    return;
  }
  _free(local_38);
  return;
}


// ==== FUN_006de750 @ 0x006de750 ====

void FUN_006de750(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_90 [35];
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5ac58 + 0x30))();
  puVar3 = auStack_90;
  for (iVar2 = 0x21; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_006ddc60(auStack_90);
  return;
}


// ==== FUN_006de810 @ 0x006de810 ====

undefined4 FUN_006de810(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int in_ECX;
  float10 fVar6;
  void *pvStack_3c;
  void *pvStack_38;
  undefined4 uStack_2c;
  uint uStack_28;
  uint uStack_24;
  void *apvStack_20 [5];
  uint uStack_c;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if ((piVar2 == (int *)0x0) || (iVar3 = (**(code **)(*piVar2 + 0x30))(), iVar3 == 0)) {
    return 0;
  }
  FUN_00404fb0();
  iVar3 = FUN_00405d30();
  iVar3 = FUN_00403620(0,*(undefined4 *)(iVar3 + 0x14),s_bloom_009e5c30,5);
  if (iVar3 != 0) {
    uVar4 = FUN_00405d30(1);
    cVar1 = FUN_004036a0(uVar4);
    if (cVar1 == '\0') {
      uVar4 = FUN_00405d30(1);
      cVar1 = FUN_004036a0(uVar4);
      if (cVar1 == '\0') {
        uVar4 = FUN_00405d30(1);
        cVar1 = FUN_004036a0(uVar4);
        if (cVar1 == '\0') {
          uVar4 = FUN_00405d30(1);
          cVar1 = FUN_004036a0(uVar4);
          if (cVar1 == '\0') {
            uVar4 = FUN_00405d30(1);
            cVar1 = FUN_004036a0(uVar4);
            if (cVar1 == '\0') {
              uVar4 = FUN_00405d30(1);
              cVar1 = FUN_004036e0(uVar4);
              if (cVar1 != '\0') {
                FUN_005796b0();
                FUN_006e0ef0(param_1);
                FUN_00401830(&DAT_009e5c84);
                FUN_00404230(apvStack_20);
                FUN_006e14e0();
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              uVar4 = FUN_00405d30(1);
              cVar1 = FUN_004036a0(uVar4);
              if (cVar1 != '\0') {
                uVar4 = FUN_00405d30(2);
                cVar1 = FUN_004036a0(uVar4);
                if (cVar1 != '\0') {
                  fVar6 = (float10)FUN_005796c0();
                  *(float *)(in_ECX + 0x1c) = (float)fVar6;
                  FUN_00401830();
                  FUN_006dda20(&pvStack_3c,*(undefined4 *)(in_ECX + 0x1c));
                    /* WARNING: Subroutine does not return */
                  FUN_00446f10();
                }
              }
            }
            else if (*(char *)(in_ECX + 0x10) == '\0') {
              FUN_005796b0();
              FUN_00401830(&DAT_009e5c74);
              uVar4 = FUN_00404230(&pvStack_3c);
              uVar5 = FUN_00402220(apvStack_20,param_1,&DAT_009e5c78,uVar4);
              FUN_006dc860(uVar5,uVar4);
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            FUN_00406250();
            return 0;
          }
        }
      }
    }
  }
  FUN_005796c0();
  iVar3 = FUN_00405d30();
  FUN_00403620(0,*(undefined4 *)(iVar3 + 0x14),&DAT_009e5c4c,4);
  FUN_006e0ef0(param_1);
  FUN_00401740(&DAT_009e5c54,4);
  FUN_00404230(&pvStack_3c);
  FUN_006e14e0();
  if (0xf < uStack_24) {
    _free(pvStack_38);
    return extraout_EAX;
  }
  FUN_00401740(&DAT_009e5c5c,4);
  uVar4 = FUN_00404230(apvStack_20);
  FUN_00402220(&pvStack_3c,param_1,&DAT_009e5c64);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x30))(), iVar3 != 0)) {
    FUN_0055a260(uVar4);
  }
  if (0xf < uStack_28) {
    _free(pvStack_3c);
    return extraout_EAX_00;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  if (uStack_c < 0x10) {
    FUN_00406250();
    return 1;
  }
  _free(apvStack_20[0]);
  return extraout_EAX_01;
}


// ==== FUN_006dec90 @ 0x006dec90 ====

void FUN_006dec90(void)

{
  void *_Memory;
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int in_ECX;
  int iVar5;
  byte bVar6;
  undefined1 auStack_60 [4];
  void *local_5c;
  uint local_58;
  undefined4 uStack_4c;
  uint local_48;
  undefined4 local_44;
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  uint uStack_28;
  uint uStack_24;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  local_44 = 0xf;
  local_48 = 0;
  local_58 = local_58 & 0xffffff00;
  FUN_00401740(s_combo_skybox_009e5bc4,0xc);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_5c);
  if (0xf < local_48) {
    _free(local_5c);
    return;
  }
  local_48 = 0xf;
  uStack_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x30))();
    FUN_00578750(1);
    uVar3 = (**(code **)(*DAT_00b5acec + 0x20))();
    FUN_006dfd90(uVar3);
    bVar6 = 0;
    iVar5 = (int)local_5c + 0x40;
    while( true ) {
      if (local_5c == (void *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = (int)(local_58 - (int)local_5c) / 0x58;
      }
      if (uVar4 <= bVar6) break;
      uStack_28 = (uint)*(byte *)(iVar5 + -0x40);
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      uStack_24 = (uint)bVar6;
      FUN_00401740(s__d__s_009e5bd4,5);
      uVar3 = FUN_00404230(&local_44);
      FUN_00401660(uVar3,0,0xffffffff);
      if (0xf < uStack_2c) {
        _free(pvStack_40);
        return;
      }
      uStack_2c = 0xf;
      uStack_30 = 0;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
      FUN_00577d70(&uStack_28,0);
      iVar5 = iVar5 + 0x58;
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return;
      }
      bVar6 = bVar6 + 1;
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    }
    FUN_00578700();
    FUN_00577df0(0);
    _Memory = local_5c;
    if (local_5c != (void *)0x0) {
      FUN_006dfc20(local_5c,local_58,auStack_60,uVar2);
      _free(_Memory);
      return;
    }
  }
  return;
}


// ==== FUN_006dee60 @ 0x006dee60 ====

void FUN_006dee60(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined1 auStack_20 [4];
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_list_time_009e5c1c,9);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x30))();
    if (*(int *)(in_ECX + 0x24) != 0) {
      FUN_00405de0(*(int *)(in_ECX + 0x24),*(undefined4 *)(in_ECX + 0x28),in_ECX + 0x20,uVar2);
      _free(*(void **)(in_ECX + 0x24));
      return;
    }
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined4 *)(in_ECX + 0x28) = 0;
    *(undefined4 *)(in_ECX + 0x2c) = 0;
    iVar3 = (**(code **)(*DAT_00b5ac58 + 0x10))();
    if (iVar3 != 0) {
      do {
        FUN_00401740(&DAT_009e5c28,2);
        uVar2 = FUN_00404230(auStack_20);
        FUN_00406720(uVar2);
        if (0xf < local_8) {
          _free(local_1c);
          return;
        }
        local_8 = 0xf;
        uStack_c = 0;
        local_1c = (void *)((uint)local_1c & 0xffffff00);
        iVar3 = (**(code **)(*DAT_00b5ac58 + 0x14))(*(undefined4 *)(iVar3 + 0x7c));
      } while (iVar3 != 0);
    }
    FUN_00576750(in_ECX + 0x20);
  }
  return;
}


// ==== FUN_006def90 @ 0x006def90 ====

undefined4 FUN_006def90(int param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int in_ECX;
  undefined *puVar7;
  undefined1 local_38 [28];
  undefined1 local_1c [28];
  
  if (param_1 == 0x14) {
    if ((param_3 == 7) && (cVar1 = FUN_006de810(param_2), cVar1 != '\0')) {
      return 1;
    }
  }
  else if (param_1 == 1) {
    if (param_3 == 1) {
      iVar3 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_add_009e5770,7);
      if (iVar3 == 0) {
        FUN_00401830(s_edit_time_009e5778);
        uVar4 = FUN_006dc9b0(local_1c,local_38);
        uVar4 = thunk_FUN_00796fb0(uVar4);
        *(undefined4 *)(in_ECX + 0x18) = uVar4;
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar1 = FUN_004036a0(param_2,s_btn_del_009e5784);
      if (cVar1 != '\0') {
        (**(code **)(*DAT_00b5ac58 + 0x24))(*(undefined4 *)(in_ECX + 0x18));
        FUN_006dee60();
        FUN_006de750();
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_modify_009e578c);
      if (cVar1 != '\0') {
        (**(code **)(*DAT_00b5ac58 + 0x24))(*(undefined4 *)(in_ECX + 0x18));
        FUN_006dcda0();
        FUN_006dee60();
        FUN_006de750();
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_weather_s_009e5798);
      if (cVar1 != '\0') {
        FUN_00401830(s_edit_weather_s_009e57a8);
        uVar4 = *(undefined4 *)(in_ECX + 0x18);
        uVar5 = FUN_006e0ef0(param_2);
        uVar6 = FUN_006dc9b0(local_1c,local_38);
        FUN_006e14e0(uVar6,uVar5,uVar4);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar1 = FUN_004036a0(param_2,s_btn_cloud_009e57b8);
      if (cVar1 != '\0') {
        FUN_006dcb20();
        return 1;
      }
    }
  }
  else if (param_1 == 0x16) {
    if ((param_3 == 1) && (cVar1 = FUN_004036a0(param_2,s_list_time_009e57c4), cVar1 != '\0')) {
      uVar4 = FUN_00405d30(param_4);
      uVar4 = thunk_FUN_00796fb0(uVar4);
      *(undefined4 *)(in_ECX + 0x18) = uVar4;
      FUN_00401830(s_edit_time_009e57d0);
      uVar4 = FUN_00405d30(param_4);
      FUN_006dc800(local_38,uVar4);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  else if (param_1 == 0x15) {
    if ((param_3 == 1) && (cVar1 = FUN_006dca90(param_2,param_4), cVar1 == '\x01')) {
      return 1;
    }
  }
  else if ((param_1 == 0) && (param_3 == 1)) {
    cVar1 = FUN_004036a0(param_2,s_pan_bloom_enable_009e57dc);
    if (cVar1 == '\0') {
      cVar1 = FUN_004036a0(param_2,s_pan_weather_enable_009e57f4);
      if (cVar1 == '\0') {
        cVar1 = FUN_004036a0(param_2,s_pan_skybox_enable_009e580c);
        if (cVar1 == '\0') {
          cVar1 = FUN_004036a0(param_2,s_pan_night_enable_009e5824);
          if (cVar1 == '\0') {
            cVar1 = FUN_004036a0(param_2,s_pan_anim_enable_009e583c);
            if (cVar1 != '\0') {
              uVar2 = FUN_006ddbb0(param_2);
              *(undefined1 *)(in_ECX + 0x10) = uVar2;
              FUN_00401830(s_edit_onetime_009e584c);
              uVar4 = FUN_006dc9b0(local_1c,local_38);
              thunk_FUN_00796fb0(uVar4);
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            return 0;
          }
          uVar2 = FUN_006ddbb0(param_2);
          uVar4 = *(undefined4 *)(in_ECX + 0x18);
          *(undefined1 *)(in_ECX + 0x11) = uVar2;
          uVar5 = FUN_006e0ef0(param_2);
          puVar7 = &DAT_009e5838;
        }
        else {
          uVar2 = FUN_006ddbb0(param_2);
          uVar4 = *(undefined4 *)(in_ECX + 0x18);
          *(undefined1 *)(in_ECX + 0x14) = uVar2;
          uVar5 = FUN_006e0ef0(param_2);
          puVar7 = &DAT_009e5820;
        }
      }
      else {
        uVar2 = FUN_006ddbb0(param_2);
        uVar4 = *(undefined4 *)(in_ECX + 0x18);
        *(undefined1 *)(in_ECX + 0x13) = uVar2;
        uVar5 = FUN_006e0ef0(param_2);
        puVar7 = &DAT_009e5808;
      }
    }
    else {
      uVar2 = FUN_006ddbb0(param_2);
      uVar4 = *(undefined4 *)(in_ECX + 0x18);
      *(undefined1 *)(in_ECX + 0x12) = uVar2;
      uVar5 = FUN_006e0ef0(param_2);
      puVar7 = &DAT_009e57f0;
    }
    FUN_00401830(puVar7);
    uVar6 = FUN_00404230(local_1c);
    FUN_006e14e0(uVar6,uVar5,uVar4);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  return 0;
}


// ==== FUN_006df400 @ 0x006df400 ====

void FUN_006df400(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_90 [35];
  
  if (*(char *)(in_ECX + 0x10) == '\x01') {
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5ac58 + 0x30))();
    puVar3 = auStack_90;
    for (iVar2 = 0x21; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_006ddc60(auStack_90);
    return;
  }
  iVar2 = (**(code **)(*DAT_00b5ac58 + 0x10))();
  if (iVar2 != 0) {
    iVar2 = (**(code **)(*DAT_00b5ac58 + 0x18))(*(undefined4 *)(iVar2 + 0x7c));
    if (iVar2 != 0) {
      FUN_006ddc60(iVar2);
    }
    FUN_006dee60();
  }
  return;
}


// ==== FUN_006df480 @ 0x006df480 ====

/* WARNING: Removing unreachable block (ram,0x006df501) */

void FUN_006df480(void)

{
  undefined1 uVar1;
  int iVar2;
  int in_ECX;
  undefined1 auStack_1a [26];
  
  iVar2 = (**(code **)(*DAT_00b5ac58 + 0x10))();
  if (iVar2 != 0) {
    iVar2 = (**(code **)(*DAT_00b5ac58 + 0x18))(*(undefined4 *)(iVar2 + 0x7c));
    if (iVar2 != 0) {
      FUN_006ddc60(iVar2);
    }
    FUN_006dee60();
    uVar1 = (**(code **)(*DAT_00b5ac58 + 0x40))();
    *(undefined1 *)(in_ECX + 0x10) = uVar1;
    FUN_00401740(s_pan_anim_enable_009e59fc,0xf);
    FUN_006ddb10(auStack_1a + -6,*(undefined1 *)(in_ECX + 0x10));
  }
  return;
}


// ==== FUN_006df520 @ 0x006df520 ====

void FUN_006df520(int *param_1,undefined4 param_2,ushort param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint in_ECX;
  undefined4 *puVar5;
  undefined1 auStack_4d2 [38];
  undefined4 local_4ac;
  undefined1 local_4a6;
  undefined4 local_4a4;
  void *local_4a0;
  undefined4 local_49c;
  int local_498;
  undefined4 local_494;
  undefined4 local_490;
  uint local_48c [2];
  undefined1 local_484;
  undefined1 auStack_47c [4];
  undefined4 uStack_478;
  undefined4 local_474;
  undefined4 local_470;
  undefined1 uStack_364;
  undefined1 uStack_363;
  undefined1 auStack_360 [4];
  undefined4 *puStack_35c;
  undefined4 uStack_10;
  
  if (param_1 != (int *)0x0) {
    local_4a6 = 1;
    local_4a4 = 0;
    local_4a0 = (void *)0x0;
    local_49c = 0;
    local_498 = 0;
    local_494 = 0;
    local_490 = 0;
    local_48c[0] = 0;
    local_470 = 0xf;
    local_474 = 0;
    local_484 = 0;
    local_4ac = 0;
    piVar1 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
    piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
    uVar3 = (**(code **)(*param_1 + 0x10))();
    FUN_004fed70(uVar3);
    FUN_00401660(param_2,0,0xffffffff);
    FUN_00401660(local_48c,0,0xffffffff);
    local_4a0 = (void *)((int)local_4a0 + (uint)param_3);
    local_498 = local_498 + (uint)param_3;
    puVar5 = &local_4ac;
    (**(code **)(*piVar1 + 8))();
    (**(code **)(*piVar2 + 0x38))(piVar1);
    (**(code **)(*piVar2 + 0x1c))(auStack_4d2 + -10);
    iVar4 = (**(code **)(*param_1 + 0x30))();
    FUN_00505f10();
    uStack_364 = *(undefined1 *)(iVar4 + 0x7c);
    uStack_363 = *(undefined1 *)(iVar4 + 0x7d);
    if (auStack_360 != (undefined1 *)(iVar4 + 0x80)) {
      FUN_00504490(auStack_47c,*puStack_35c,puStack_35c);
      FUN_005040e0(iVar4 + 0x80);
    }
    uStack_478 = *(undefined4 *)(iVar4 + 0x8c);
    local_474 = *(undefined4 *)(iVar4 + 0x90);
    local_470 = *(undefined4 *)(iVar4 + 0x94);
    (**(code **)(*piVar2 + 0x24))(&uStack_478);
    (**(code **)(*piVar1 + 0x2c))(piVar2);
    iVar4 = (**(code **)(*(int *)puVar5[1] + 0x34))(uStack_10);
    if (iVar4 == 0) {
      FUN_00505d80();
      if (0xf < in_ECX) {
        _free((void *)0x0);
        return;
      }
    }
    else {
      FUN_00557b50(iVar4);
      FUN_00505d80();
      if (0xf < in_ECX) {
        _free((void *)0x0);
        return;
      }
    }
    if (0xf < local_48c[0]) {
      _free(local_4a0);
      return;
    }
  }
  return;
}


// ==== FUN_006df760 @ 0x006df760 ====

void FUN_006df760(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  undefined4 unaff_retaddr;
  int iVar4;
  undefined1 local_3c [4];
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_2);
  if ((iVar1 != 0) && (1 < (ushort)param_2)) {
    param_2 = param_2 - 1 & 0xffff;
    iVar3 = 0x16;
    do {
      iVar4 = iVar3;
      FUN_00401740(&DAT_009e571c,2);
      uVar2 = FUN_00404230(auStack_20);
      uVar2 = FUN_00405bd0(local_3c,param_1,uVar2);
      FUN_006df520(iVar1,unaff_retaddr,uVar2,iVar4);
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
      iVar3 = iVar3 + 0x16;
      param_2 = param_2 - 1;
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_006df860 @ 0x006df860 ====

void FUN_006df860(void)

{
  undefined1 uVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_54 [4];
  void *local_50;
  undefined4 local_40;
  uint local_3c;
  void *local_38;
  void *local_34;
  uint local_24;
  uint local_20;
  void *pvStack_1c;
  undefined1 uStack_18;
  uint uStack_8;
  undefined4 uStack_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_pan_amb_line_009e56a4,0xc);
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  FUN_00401740(s_pan_light_009e56b4,9);
  FUN_006df760(local_54,&local_38,3);
  if (0xf < local_3c) {
    _free(local_50);
    return;
  }
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_pan_dir_line_009e56c0,0xc);
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  FUN_00401740(s_pan_light_009e56d0,9);
  FUN_006df760(local_54,&local_38,6);
  if (0xf < local_3c) {
    _free(local_50);
    return;
  }
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_pan_fog_line_009e56dc,0xc);
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  FUN_00401740(s_pan_light_009e56ec,9);
  FUN_006df760(local_54,&local_38,5);
  if (0xf < local_3c) {
    _free(local_50);
    return;
  }
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  FUN_006df400();
  uVar1 = (**(code **)(*DAT_00b5ac58 + 0x40))();
  *(undefined1 *)(in_ECX + 0x10) = uVar1;
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_pan_anim_enable_009e56f8,0xf);
  FUN_006ddb10(&local_38,*(undefined1 *)(in_ECX + 0x10));
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  FUN_00401740(&DAT_009e5708,2);
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_edit_onetime_009e570c,0xc);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_00551410(&local_20);
  }
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  FUN_006dec90();
  if (uStack_8 < 0x10) {
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_006dfad0 @ 0x006dfad0 ====

void FUN_006dfad0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = DAT_009e5ce0;
  *in_ECX = &PTR_FUN_009e5cd4;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined1 *)((int)in_ECX + 0x11) = 0;
  *(undefined1 *)((int)in_ECX + 0x12) = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  *(undefined1 *)((int)in_ECX + 0x13) = 0;
  in_ECX[1] = param_1;
  in_ECX[3] = param_3;
  in_ECX[2] = param_2;
  in_ECX[7] = uVar1;
  FUN_006df860();
  return;
}


// ==== FUN_006dfb30 @ 0x006dfb30 ====

void FUN_006dfb30(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x54)) {
    _free(*(void **)(in_ECX + 0x40));
    return;
  }
  *(undefined4 *)(in_ECX + 0x54) = 0xf;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined1 *)(in_ECX + 0x40) = 0;
  if (0xf < *(uint *)(in_ECX + 0x38)) {
    _free(*(void **)(in_ECX + 0x24));
    return;
  }
  *(undefined4 *)(in_ECX + 0x38) = 0xf;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  if (*(uint *)(in_ECX + 0x1c) < 0x10) {
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0xf;
    *(undefined1 *)(in_ECX + 8) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_006dfba0 @ 0x006dfba0 ====

void FUN_006dfba0(undefined1 *param_1)

{
  undefined1 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  *(undefined4 *)(in_ECX + 0x1c) = 0xf;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  in_ECX[8] = 0;
  FUN_00401660(param_1 + 4,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x38) = 0xf;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  in_ECX[0x24] = 0;
  FUN_00401660(param_1 + 0x20,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x54) = 0xf;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  in_ECX[0x40] = 0;
  FUN_00401660(param_1 + 0x3c,0,0xffffffff);
  return;
}


// ==== FUN_006dfc20 @ 0x006dfc20 ====

void FUN_006dfc20(int param_1,int param_2)

{
  uint *puVar1;
  
  if (param_1 != param_2) {
    puVar1 = (uint *)(param_1 + 0x54);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      if (0xf < puVar1[-7]) {
        _free((void *)puVar1[-0xc]);
        return;
      }
      puVar1[-7] = 0xf;
      puVar1[-8] = 0;
      *(undefined1 *)(puVar1 + -0xc) = 0;
      if (0xf < puVar1[-0xe]) {
        _free((void *)puVar1[-0x13]);
        return;
      }
      puVar1[-0xe] = 0xf;
      puVar1[-0xf] = 0;
      *(undefined1 *)(puVar1 + -0x13) = 0;
      param_1 = param_1 + 0x58;
      puVar1 = puVar1 + 0x16;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_006dfca0 @ 0x006dfca0 ====

void FUN_006dfca0(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    FUN_006dfba0(param_2);
  }
  return;
}


// ==== FUN_006dfcc0 @ 0x006dfcc0 ====

int FUN_006dfcc0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c980;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x58) {
    FUN_006dfca0(param_3,param_1);
    param_3 = param_3 + 0x58;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@006dfd2a @ 0x006dfd2a ====

void Catch_006dfd2a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x58) {
    FUN_006dfb30();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006dfd50 @ 0x006dfd50 ====

void FUN_006dfd50(undefined4 param_1,undefined4 param_2)

{
  FUN_006dfc20(param_1,param_2);
  return;
}


// ==== FUN_006dfd70 @ 0x006dfd70 ====

void FUN_006dfd70(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_006dfcc0(param_1,param_2,param_3);
  return;
}


// ==== FUN_006dfd90 @ 0x006dfd90 ====

void FUN_006dfd90(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c990;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x58;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_005d4980(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_006dfd70(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@006dfe27 @ 0x006dfe27 ====

void Catch_006dfe27(void)

{
  FUN_006dfe40();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006dfe40 @ 0x006dfe40 ====

void FUN_006dfe40(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  FUN_006dfc20(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_006dfe80 @ 0x006dfe80 ====

void FUN_006dfe80(uint param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e5cd4;
  if (in_ECX[9] != 0) {
    FUN_00405de0(in_ECX[9],in_ECX[10],in_ECX + 8,param_1);
    _free((void *)in_ECX[9]);
    return;
  }
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006dfef0 @ 0x006dfef0 ====

void FUN_006dfef0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      FUN_0055a260(param_1);
    }
  }
  return;
}


// ==== FUN_006dff20 @ 0x006dff20 ====

void FUN_006dff20(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int in_ECX;
  void *unaff_EBX;
  undefined1 auStack_36 [14];
  uint uStack_28;
  void *apvStack_20 [5];
  uint uStack_c;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      FUN_00579b40(param_1);
      FUN_00401740(&DAT_009e5e14,2);
      uVar3 = FUN_00404230(apvStack_20);
      uVar4 = FUN_00402220(auStack_36 + -6,param_1,&DAT_009e5e18);
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar4);
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 0x30))();
        if (iVar2 != 0) {
          FUN_0055a260(uVar3);
        }
      }
      if (0xf < uStack_28) {
        _free(unaff_EBX);
        return;
      }
      if (0xf < uStack_c) {
        _free(apvStack_20[0]);
        return;
      }
    }
  }
  return;
}


