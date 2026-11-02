// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x500000-0x50ffff

// ==== FUN_005001c0 @ 0x005001c0 ====

void FUN_005001c0(void)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s________________receive_pclist_ac_009b4ed0,0x27);
  FUN_00796d20(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s________________receive_pclist_ac_009b4ef8,0x27);
  FUN_00403e50(local_1c);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00500250 @ 0x00500250 ====

void FUN_00500250(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined1 auStack_1c [2];
  undefined1 auStack_1a [2];
  void *pvStack_18;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  uint uStack_4;
  
  if (*(int *)(param_1 + 0x10) < 0) {
    if (*(int *)(param_1 + 0x10) == -0x14) {
      uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x820051);
      uStack_c = 0xf;
      uStack_10 = 0;
      FUN_00401660(uVar1,0,0xffffffff);
      piVar2 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
      (**(code **)*piVar2)(0x17,auStack_1c + -8);
      (**(code **)(*piVar2 + 4))(0);
      (**(code **)(*DAT_00b5a9e0 + 0x20))(1);
      (**(code **)(*DAT_00b5a9dc + 0xc))();
      FUN_00796d20(auStack_1c);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
    }
    FUN_00401740(s_Destroy_Character_Fail__d____009b500c,0x1c);
    uVar1 = FUN_00404230(auStack_1c);
    FUN_00796d20(uVar1);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
  }
  else {
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_00401740(s_Destroy_Character_OK___009b502c,0x16);
    FUN_00796d20(auStack_1c);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
    FUN_004ffd40();
  }
  return;
}


// ==== FUN_0050025f @ 0x0050025f ====

/* WARNING: Removing unreachable block (ram,0x00500383) */

void FUN_0050025f(undefined1 param_1,void *param_2)

{
  int in_EAX;
  undefined4 uVar1;
  int *piVar2;
  undefined4 unaff_EBX;
  char in_SF;
  char in_OF;
  uint in_stack_0000001c;
  undefined1 auStack_24 [8];
  
  if (in_OF == in_SF) {
    param_2 = (void *)CONCAT31(param_2._1_3_,(char)unaff_EBX);
    FUN_00401740(s_Destroy_Character_OK___009b502c,0x16);
    FUN_00796d20(&param_1);
    FUN_004ffd40();
  }
  else {
    if (in_EAX == -0x14) {
      uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))();
      FUN_00401660(uVar1,unaff_EBX,0xffffffff);
      piVar2 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
      (**(code **)*piVar2)(0x17,auStack_24 + 0x20);
      (**(code **)(*piVar2 + 4))();
      (**(code **)(*DAT_00b5a9e0 + 0x20))(1);
      (**(code **)(*DAT_00b5a9dc + 0xc))();
      FUN_00796d20(&param_1);
      if (0xf < in_stack_0000001c) {
        _free(param_2);
        return;
      }
    }
    FUN_00401740(s_Destroy_Character_Fail__d____009b500c,0x1c);
    uVar1 = FUN_00404230(&param_1);
    FUN_00796d20(uVar1);
    if (0xf < in_stack_0000001c) {
      _free(param_2);
      return;
    }
  }
  return;
}


// ==== FUN_005003a0 @ 0x005003a0 ====

/* WARNING: Removing unreachable block (ram,0x005004d4) */

void FUN_005003a0(int param_1,uint *param_2)

{
  char cVar1;
  short sVar2;
  undefined1 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  undefined4 *puVar10;
  void **ppvVar11;
  uint uVar12;
  uint uStack_84;
  undefined4 uStack_64;
  void *pvStack_60;
  undefined1 uStack_5c;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined4 uStack_48;
  void *pvStack_44;
  undefined1 uStack_40;
  uint local_30 [8];
  undefined2 uStack_e;
  undefined2 uStack_c;
  undefined2 uStack_a;
  
  puVar8 = local_30;
  for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = *param_2;
    param_2 = param_2 + 1;
    puVar8 = puVar8 + 1;
  }
  sVar2 = *(short *)((int)local_30 + param_1 * 2);
  uVar7 = CONCAT22((short)((uint)param_2 >> 0x10),sVar2);
  uStack_84 = uVar7;
  iVar6 = (**(code **)(*DAT_00b5ad20 + 0x14))();
  if (((iVar6 == 0x601) && (sVar2 != 0)) &&
     (uVar12 = uVar7, iVar6 = (**(code **)(*DAT_00b5a738 + 0x10))(uVar7), iVar6 != 0)) {
    (**(code **)(*DAT_00b5a6dc + 8))(CONCAT22(uStack_c,uStack_e),param_1,uVar7);
    local_30[1] = 0xf;
    local_30[0] = 0;
    uStack_40 = 0;
    FUN_00401740(s_weaponW_009b50c0,7);
    uStack_48 = 0xf;
    uStack_84 = 9;
    uStack_4c = 0;
    uStack_5c = 0;
    pcVar4 = PTR_DAT_00aea714;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_DAT_00aea714,(int)pcVar4 - (int)(PTR_DAT_00aea714 + 1));
    uStack_64 = 0xf;
    FUN_00401740(s_WingArmor_009b50c8,9);
    puVar8 = &uStack_84;
    ppvVar11 = &pvStack_44;
    uVar5 = (**(code **)(*DAT_00b5a7e4 + 4))(ppvVar11,puVar8,0);
    puVar10 = &uStack_64;
    puVar9 = local_30 + -0x14;
    FUN_00511d10(puVar9,puVar10,uVar5);
    FUN_00513030(puVar9,puVar10,uVar5,ppvVar11,puVar8);
    if (0xf < uStack_4c) {
      _free(pvStack_60);
      return;
    }
    uStack_4c = 0xf;
    uStack_50 = 0;
    pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
    FUN_00401740(s_WingArmor_009b50d4,9);
    puVar10 = &uStack_64;
    FUN_00511d10(puVar10);
    FUN_00512ca0(puVar10);
    if (0xf < uStack_4c) {
      _free(pvStack_60);
      return;
    }
    uVar3 = FUN_004ffab0(uVar7,CONCAT22(uStack_a,uStack_c),1);
    FUN_00512a90(uVar12 + 0x78,uVar12 + 0x94,uVar3,0);
    if (0xf < local_30[0]) {
      _free(pvStack_44);
      return;
    }
  }
  return;
}


// ==== FUN_005005a0 @ 0x005005a0 ====

void FUN_005005a0(undefined4 param_1,uint param_2)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined2 uVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  int in_ECX;
  int iVar9;
  float10 fVar10;
  undefined1 auStack_20 [4];
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar3 = param_2;
  iVar7 = *(int *)(param_2 + 4);
  if (iVar7 != 0) {
    iVar9 = *(int *)(param_2 + 8) - iVar7;
    iVar2 = iVar9 >> 0x1f;
    iVar9 = iVar9 / 0x1c + iVar2;
    if (2 < (uint)(iVar9 - iVar2)) {
      if (iVar9 == iVar2) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      FUN_00401660(iVar7,0,0xffffffff);
      iVar7 = *(int *)(iVar3 + 4);
      if ((iVar7 == 0) || ((uint)((*(int *)(iVar3 + 8) - iVar7) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      param_2 = thunk_FUN_00796f50(iVar7 + 0x1c);
      param_2 = param_2 & 0xff;
      piVar6 = (int *)FUN_0079bba0(auStack_20,&param_2);
      if (*piVar6 == *(int *)(in_ECX + 0x14)) {
        if (0xf < local_4) {
          _free(local_18);
          return;
        }
      }
      else {
        pfVar1 = *(float **)(*piVar6 + 0x10);
        iVar7 = FUN_00403620(0,local_8,s_stand_009b5044,5);
        if (iVar7 == 0) {
          uVar8 = FUN_00405d30(2);
          fVar10 = (float10)thunk_FUN_00796ec0(uVar8);
          *pfVar1 = (float)fVar10;
        }
        else {
          cVar4 = FUN_004036a0(local_1c,s_stand_special_009b504c);
          if (cVar4 == '\0') {
            cVar4 = FUN_004036a0(local_1c,s_scale_009b505c);
            if (cVar4 == '\0') {
              cVar4 = FUN_004036a0(local_1c,s_position_009b5064);
              if (cVar4 == '\0') {
                cVar4 = FUN_004036a0(local_1c,s_mapindex_009b5070);
                if (cVar4 == '\0') {
                  cVar4 = FUN_004036a0(local_1c,s_cameratarget_009b507c);
                  if (cVar4 == '\0') {
                    cVar4 = FUN_004036a0(local_1c,s_direction_009b508c);
                    if (cVar4 != '\0') {
                      uVar8 = FUN_00405d30(2);
                      fVar10 = (float10)thunk_FUN_00796ec0(uVar8);
                      pfVar1[9] = (float)fVar10;
                    }
                  }
                  else {
                    uVar8 = FUN_00405d30(2);
                    fVar10 = (float10)thunk_FUN_00796ec0(uVar8);
                    pfVar1[6] = (float)fVar10;
                    uVar8 = FUN_00405d30(3);
                    fVar10 = (float10)thunk_FUN_00796ec0(uVar8);
                    pfVar1[7] = (float)fVar10;
                    uVar8 = FUN_00405d30(4);
                    fVar10 = (float10)thunk_FUN_00796ec0(uVar8);
                    pfVar1[8] = (float)fVar10;
                  }
                }
                else {
                  uVar8 = FUN_00405d30(2);
                  uVar5 = thunk_FUN_00796f80(uVar8);
                  *(undefined2 *)(pfVar1 + 5) = uVar5;
                }
              }
              else {
                uVar8 = FUN_00405d30(2);
                fVar10 = (float10)thunk_FUN_00796ec0(uVar8);
                pfVar1[3] = (float)fVar10;
                uVar8 = FUN_00405d30(3);
                fVar10 = (float10)thunk_FUN_00796ec0(uVar8);
                pfVar1[4] = (float)fVar10;
              }
            }
            else {
              uVar8 = FUN_00405d30(2);
              fVar10 = (float10)thunk_FUN_00796ec0(uVar8);
              pfVar1[2] = (float)fVar10;
            }
          }
          else {
            uVar8 = FUN_00405d30(2);
            fVar10 = (float10)thunk_FUN_00796ec0(uVar8);
            pfVar1[1] = (float)fVar10;
          }
        }
        if (0xf < local_4) {
          _free(local_18);
          return;
        }
      }
    }
  }
  return;
}


// ==== FUN_00500820 @ 0x00500820 ====

/* WARNING: Removing unreachable block (ram,0x00500a54) */

void FUN_00500820(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  undefined3 *puVar4;
  uint uVar5;
  undefined4 uStack_98;
  uint uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  int *local_40;
  undefined1 auStack_3c [4];
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  
  iVar2 = (**(code **)(*DAT_00b5a74c + 0xc))(0x10);
  if (iVar2 == 0) {
    uStack_84 = 0xf;
    uStack_98 = (void *)((uint)uStack_98._1_3_ << 8);
    FUN_00401740(s_pUIHandler____NULL_009b5160,0x12);
    FUN_00406880(auStack_3c + -0x60);
    if (uStack_84 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(uStack_98);
    return;
  }
  local_40 = *(int **)(iVar2 + 4);
  if (local_40 == (int *)0x0) {
    uStack_84 = 0xf;
    uStack_98 = (void *)((uint)uStack_98._1_3_ << 8);
    FUN_00401740(s_pWindow____NULL_009b5174,0xf);
    FUN_00406880(auStack_3c + -0x60);
    if (uStack_84 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(uStack_98);
    return;
  }
  uStack_80._0_3_ = CONCAT12(1,(undefined2)uStack_80);
  uStack_7c = 0;
  uStack_78 = 0;
  uStack_74 = 0;
  uStack_70 = 0;
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  uStack_48 = 0xf;
  uStack_4c = 0;
  pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
  uVar5 = 0;
  do {
    piVar3 = local_40;
    FUN_00401740(s_character_list_btn__d_009b5184,0x15);
    FUN_00404230(auStack_3c);
    piVar3 = (int *)(**(code **)(*piVar3 + 0x34))(auStack_3c);
    if (piVar3 == (int *)0x0) {
      uStack_c = 0xf;
      uStack_10 = 0;
      pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
      FUN_00401740(s_pComposite____NULL_009b519c,0x12);
      FUN_00406880(&uStack_24);
      if (uStack_c < 0x10) {
        uStack_c = 0xf;
        uStack_10 = 0;
        pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_20);
      return;
    }
    iVar2 = (**(code **)(*piVar3 + 0x30))();
    puVar4 = (undefined3 *)(**(code **)(*piVar3 + 0x10))();
    uStack_84 = CONCAT13(uStack_84._3_1_,*puVar4);
    uStack_80 = *(undefined4 *)(puVar4 + 1);
    uStack_7c = *(undefined4 *)(puVar4 + 2);
    uStack_78 = *(undefined4 *)(puVar4 + 3);
    uStack_74 = *(undefined4 *)(puVar4 + 4);
    uStack_70 = *(undefined4 *)(puVar4 + 5);
    uStack_6c = *(undefined4 *)(puVar4 + 6);
    uStack_68 = *(undefined4 *)(puVar4 + 7);
    FUN_00401660(puVar4 + 8,0,0xffffffff);
    if (iVar2 == 0) {
      FUN_00401740(s_pButton____NULL_009b51b0,0xf);
      FUN_00406880(auStack_3c + -100);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_00558730(*(uint *)(uStack_48 + 0xc) == uVar5);
    (**(code **)(*piVar3 + 0xc))(&uStack_84);
    if (0xf < uStack_24) {
      _free(pvStack_38);
      return;
    }
    uVar5 = uVar5 + 1;
    uStack_24 = 0xf;
    uStack_28 = 0;
    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  } while (uVar5 < 6);
  if (uStack_48 < 0x10) {
    return;
  }
  _free(pvStack_5c);
  return;
}


// ==== FUN_00500af0 @ 0x00500af0 ====

void FUN_00500af0(int param_1)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  int local_24;
  int local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x50) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(in_ECX + 0x54) - *(int *)(in_ECX + 0x50) >> 2;
  }
  if (iVar3 <= *(int *)(in_ECX + 0x5c)) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_m_iSuitCount_<_static_cast<INT>(_009b4df4,0x34);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_18);
    return;
  }
  iVar3 = *(int *)(in_ECX + 0x50);
  uVar4 = *(uint *)(in_ECX + 0x5c);
  if ((iVar3 == 0) || ((uint)(*(int *)(in_ECX + 0x54) - iVar3 >> 2) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  piVar1 = *(int **)(iVar3 + uVar4 * 4);
  *(uint *)(in_ECX + 0x5c) = uVar4 + 1;
  uVar4 = FUN_00424520();
  local_24 = (uVar4 & 0xffff) - 0x18;
  local_20 = param_1 + 0x18;
  (**(code **)(*piVar1 + 0x20))(&local_24);
  return;
}


// ==== FUN_00500bb0 @ 0x00500bb0 ====

void FUN_00500bb0(int param_1)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  int local_24;
  int local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x50) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(in_ECX + 0x54) - *(int *)(in_ECX + 0x50) >> 2;
  }
  if (iVar3 <= *(int *)(in_ECX + 0x5c)) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_m_iSuitCount_<_static_cast<INT>(_009b4e2c,0x34);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_18);
    return;
  }
  iVar3 = *(int *)(in_ECX + 0x50);
  uVar4 = *(uint *)(in_ECX + 0x5c);
  if ((iVar3 == 0) || ((uint)(*(int *)(in_ECX + 0x54) - iVar3 >> 2) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  piVar1 = *(int **)(iVar3 + uVar4 * 4);
  *(uint *)(in_ECX + 0x5c) = uVar4 + 1;
  uVar4 = FUN_00424520();
  local_24 = (uVar4 & 0xffff) - 0x18;
  local_20 = param_1 + 0x18;
  (**(code **)(*piVar1 + 0x24))(&local_24);
  return;
}


// ==== FUN_00500c70 @ 0x00500c70 ====

void FUN_00500c70(int param_1)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  int local_24;
  int local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x50) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(in_ECX + 0x54) - *(int *)(in_ECX + 0x50) >> 2;
  }
  if (iVar3 <= *(int *)(in_ECX + 0x5c)) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_m_iSuitCount_<_static_cast<INT>(_009b4e64,0x34);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_18);
    return;
  }
  iVar3 = *(int *)(in_ECX + 0x50);
  uVar4 = *(uint *)(in_ECX + 0x5c);
  if ((iVar3 == 0) || ((uint)(*(int *)(in_ECX + 0x54) - iVar3 >> 2) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  piVar1 = *(int **)(iVar3 + uVar4 * 4);
  *(uint *)(in_ECX + 0x5c) = uVar4 + 1;
  uVar4 = FUN_00424520();
  local_24 = (uVar4 & 0xffff) - 0x18;
  local_20 = param_1 + 0x18;
  (**(code **)(*piVar1 + 0x28))(&local_24);
  return;
}


// ==== FUN_00500d30 @ 0x00500d30 ====

void FUN_00500d30(int param_1)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x50) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(in_ECX + 0x54) - *(int *)(in_ECX + 0x50) >> 2;
  }
  if (iVar2 <= *(int *)(in_ECX + 0x60)) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_m_iNameCount_<_static_cast<INT>(_009b4e9c,0x33);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_18);
    return;
  }
  iVar2 = *(int *)(in_ECX + 0x50);
  if ((iVar2 == 0) || ((uint)(*(int *)(in_ECX + 0x54) - iVar2 >> 2) <= *(uint *)(in_ECX + 0x60))) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar2 + *(uint *)(in_ECX + 0x60) * 4) + 0x6c))(param_1 + 0x18);
  *(int *)(in_ECX + 0x60) = *(int *)(in_ECX + 0x60) + 1;
  return;
}


// ==== FUN_00500de0 @ 0x00500de0 ====

int FUN_00500de0(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int in_ECX;
  char *pcVar4;
  
  if ((*(int *)(in_ECX + 0x50) == 0) ||
     ((uint)(*(int *)(in_ECX + 0x54) - *(int *)(in_ECX + 0x50) >> 2) <= param_2)) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(&DAT_009b51f3,0);
    return param_1;
  }
  iVar2 = *(int *)(in_ECX + 0x50);
  if ((iVar2 == 0) || ((uint)(*(int *)(in_ECX + 0x54) - iVar2 >> 2) <= param_2)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  pcVar3 = (char *)(**(code **)(**(int **)(iVar2 + param_2 * 4) + 0x70))();
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  pcVar4 = pcVar3;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar3,(int)pcVar4 - (int)(pcVar3 + 1));
  return param_1;
}


// ==== FUN_00500e80 @ 0x00500e80 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00500e80(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x50) == 0) ||
     ((uint)(*(int *)(in_ECX + 0x54) - *(int *)(in_ECX + 0x50) >> 2) <= param_1)) {
    return 0;
  }
  iVar1 = *(int *)(in_ECX + 0x50);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x54) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  piVar3 = *(int **)(*(int *)(iVar1 + param_1 * 4) + 0x18);
  if (piVar3 == (int *)0x0) {
    uVar2 = (**(code **)(_DAT_00000000 + 8))();
    return uVar2;
  }
  piVar3 = (int *)(**(code **)(*piVar3 + 0x18))();
  uVar2 = (**(code **)(*piVar3 + 8))();
  return uVar2;
}


// ==== FUN_00500ee0 @ 0x00500ee0 ====

void FUN_00500ee0(void)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  void *unaff_EBX;
  int unaff_ESI;
  char *pcVar7;
  undefined1 auStack_56 [14];
  uint uStack_48;
  void *pvStack_40;
  void *pvStack_3c;
  undefined4 uStack_30;
  uint uStack_2c;
  uint uStack_28;
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  
  iVar4 = *DAT_00b5ac80;
  iVar3 = (**(code **)(*DAT_00b5ac1c + 8))();
  iVar4 = (**(code **)(iVar4 + 8))(*(undefined1 *)(iVar3 + 4));
  pvStack_40 = (void *)0xf;
  if (iVar4 == 0) {
    iVar4 = 5;
    pcVar7 = s_EMPTY_009b51f4;
  }
  else {
    pcVar7 = (char *)(iVar4 + 1);
    pcVar6 = pcVar7;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    iVar4 = (int)pcVar6 - (iVar4 + 2);
  }
  FUN_00401740(pcVar7,iVar4);
  iVar4 = (**(code **)(*DAT_00b5a74c + 0xc))(0x10);
  if (iVar4 == 0) {
    uStack_28 = 0xf;
    uStack_2c = 0;
    pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
    FUN_00401740(s_pUIHandler____NULL_009b51fc,0x12);
    FUN_00406880(&pvStack_40);
    if (uStack_28 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_3c);
    return;
  }
  piVar5 = *(int **)(iVar4 + 4);
  if (piVar5 == (int *)0x0) {
    uStack_28 = 0xf;
    uStack_2c = 0;
    pvStack_3c = (void *)((uint)pvStack_3c._1_3_ << 8);
    FUN_00401740(s_pWindow____NULL_009b5210,0xf);
    FUN_00406880(&pvStack_40);
    if (uStack_28 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_3c);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c._1_3_ << 8);
  FUN_00401740(s_lbl_select_msg_009b5220,0xe);
  piVar5 = (int *)(**(code **)(*piVar5 + 0x34))(&pvStack_40);
  if (0xf < uStack_2c) {
    _free(pvStack_40);
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  if (piVar5 == (int *)0x0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009b5230,0x12);
    FUN_00406880(&uStack_28);
    if (uStack_10 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_24);
    return;
  }
  FUN_004020e0(&DAT_009b5244,1);
  iVar4 = *(int *)(unaff_ESI + 0x50);
  if ((iVar4 == 0) ||
     ((uint)(*(int *)(unaff_ESI + 0x54) - iVar4 >> 2) <= *(uint *)(unaff_ESI + 0xc))) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  pcVar6 = (char *)(**(code **)(**(int **)(iVar4 + *(uint *)(unaff_ESI + 0xc) * 4) + 0x70))();
  pcVar7 = pcVar6;
  do {
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_004020e0(pcVar6,(int)pcVar7 - (int)(pcVar6 + 1));
  (**(code **)(*piVar5 + 0x30))();
  FUN_0055a260(auStack_56 + -10);
  if (uStack_48 < 0x10) {
    return;
  }
  _free(unaff_EBX);
  return;
}


// ==== FUN_00501100 @ 0x00501100 ====

void FUN_00501100(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  uint uStack_14;
  
  *in_ECX = &PTR_FUN_009b5354;
  uStack_14 = 0x501111;
  FUN_004ffa50();
  uStack_14 = 0x50111c;
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  uStack_14 = in_ECX[1];
  (**(code **)(*piVar1 + 8))(s___SceneModel_Game_CharSelectScen_009b4cb4,0x59,0);
  if (in_ECX[6] != 0) {
    uStack_14 = uStack_14 & 0xffffff00;
    FUN_005354c0(*(undefined4 *)in_ECX[5],(undefined4 *)in_ECX[5],uStack_14);
    FUN_00503e00(*(undefined4 *)(in_ECX[5] + 4));
    *(undefined4 *)(in_ECX[5] + 4) = in_ECX[5];
    in_ECX[6] = 0;
    *(undefined4 *)in_ECX[5] = in_ECX[5];
    *(undefined4 *)(in_ECX[5] + 8) = in_ECX[5];
  }
  if ((undefined4 *)in_ECX[0x1d] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x1d])(1);
  }
  in_ECX[0x1d] = 0;
  if ((void *)in_ECX[0x14] != (void *)0x0) {
    _free((void *)in_ECX[0x14]);
    return;
  }
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  if ((void *)in_ECX[0x10] == (void *)0x0) {
    in_ECX[0x10] = 0;
    in_ECX[0x11] = 0;
    in_ECX[0x12] = 0;
    FUN_00504660(&uStack_14,*(undefined4 *)in_ECX[5],(undefined4 *)in_ECX[5]);
    _free((void *)in_ECX[5]);
    return;
  }
  _free((void *)in_ECX[0x10]);
  return;
}


// ==== FUN_005011f0 @ 0x005011f0 ====

/* WARNING: Removing unreachable block (ram,0x005013a7) */

undefined4 FUN_005011f0(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  undefined4 extraout_EAX_00;
  int *piVar4;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  int *piVar5;
  undefined4 extraout_EAX_03;
  int in_ECX;
  undefined1 auStack_aa [22];
  void *pvStack_94;
  undefined1 uStack_90;
  undefined4 uStack_84;
  uint uStack_80;
  undefined4 uStack_7c;
  undefined1 auStack_78 [4];
  void *pvStack_74;
  undefined4 uStack_64;
  uint uStack_60;
  undefined1 auStack_5c [4];
  void *pvStack_58;
  undefined4 uStack_48;
  uint uStack_44;
  void *pvStack_40;
  undefined4 uStack_30;
  void *pvStack_2c;
  undefined4 uStack_1c;
  uint uStack_18;
  
  if (*(int *)(in_ECX + 0xc) == -1) {
    return 1;
  }
  if (*(int *)(param_1 + 4) != 0) {
    return 0;
  }
  *(undefined1 *)(in_ECX + 0x68) = *(undefined1 *)(param_1 + 8);
  iVar2 = (**(code **)(*DAT_00b5a74c + 0xc))(0x10);
  if (iVar2 == 0) {
    FUN_00401830(s_pUIHandler____NULL_009b4d80);
    FUN_00406880(auStack_78);
    if (uStack_60 < 0x10) {
      uStack_60 = 0xf;
      uStack_64 = 0;
      pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    _free(pvStack_74);
    return extraout_EAX;
  }
  piVar5 = *(int **)(iVar2 + 4);
  if (piVar5 == (int *)0x0) {
    FUN_00401830(s_pWindow____NULL_009b4d94);
    FUN_00406880(auStack_5c);
    if (uStack_44 < 0x10) {
      uStack_44 = 0xf;
      uStack_48 = 0;
      pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    _free(pvStack_58);
    return extraout_EAX_00;
  }
  uStack_7c = 0xf;
  uStack_80 = 0;
  uStack_90 = 0;
  FUN_00401740(s_btn_connect_009b4da4,0xb);
  piVar4 = (int *)(**(code **)(*piVar5 + 0x34))(&pvStack_94);
  if (0xf < uStack_80) {
    _free(pvStack_94);
    return extraout_EAX_01;
  }
  uStack_80 = 0xf;
  uStack_84 = 0;
  pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
  if (piVar4 == (int *)0x0) {
    FUN_00401830(s_pComposite____NULL_009b4db0);
    FUN_00406880(&uStack_44);
    if (pvStack_2c < (void *)0x10) {
      pvStack_2c = (void *)0xf;
      uStack_30 = 0;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    _free(pvStack_40);
    return extraout_EAX_02;
  }
  (**(code **)(*piVar4 + 0x44))(1);
  FUN_00401740(s_pan_select_char_009b4dc4,0xf);
  piVar5 = (int *)(**(code **)(*piVar5 + 0x34))(auStack_aa + -0xe);
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 0x24))(1);
    FUN_00500ee0();
    return 1;
  }
  FUN_00401830(s_pComposite____NULL_009b4dd4);
  FUN_00406880(&uStack_30);
  if (uStack_18 < 0x10) {
    uStack_18 = 0xf;
    uStack_1c = 0;
    pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  _free(pvStack_2c);
  return extraout_EAX_03;
}


// ==== FUN_00501440 @ 0x00501440 ====

undefined4 FUN_00501440(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  int local_8;
  uint local_4;
  
  iVar1 = *(int *)(in_ECX + 8);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = &PTR_FUN_009b5304;
      FUN_00797a20(puVar2);
      return 1;
    }
  }
  else {
    if (iVar1 != 1) {
      if (iVar1 != 2) {
        return 0;
      }
      FUN_00500de0(local_1c,*(undefined4 *)(in_ECX + 0xc));
      if ((local_8 != 0) && (*(char *)(in_ECX + 0x1c) == '\0')) {
        *(undefined1 *)(in_ECX + 0x1c) = 1;
        puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
        if (puVar2 == (undefined4 *)0x0) {
          puVar2 = (undefined4 *)0x0;
        }
        else {
          *puVar2 = &PTR_FUN_009b532c;
          puVar2[8] = 0xf;
          puVar2[7] = 0;
          *(undefined1 *)(puVar2 + 3) = 0;
        }
        *(undefined1 *)(puVar2 + 1) = *(undefined1 *)(in_ECX + 0x68);
        FUN_00401660(local_1c,0,0xffffffff);
        FUN_00797a20(puVar2);
      }
      if (local_4 < 0x10) {
        return 1;
      }
      _free(local_18);
      return extraout_EAX;
    }
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = &PTR_FUN_009b5318;
      FUN_00797a20(puVar2);
      return 1;
    }
  }
  FUN_00797a20(0);
  return 1;
}


// ==== FUN_00501550 @ 0x00501550 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00501550(undefined4 param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14 [8];
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  if (*(int *)(in_ECX + 0xc) != -1) {
    iVar1 = FUN_00500e80(*(int *)(in_ECX + 0xc));
    if (iVar1 != 0) {
      local_24 = (uint)*(byte *)(iVar1 + 0x2a);
      FUN_0079bba0(&local_20,&local_24);
      if (local_20 != *(int *)(in_ECX + 0x14)) {
        puVar3 = *(undefined4 **)(local_20 + 0x10);
        local_8 = param_1;
        local_c = 0;
        local_4 = param_2;
        if (param_2 == 3) {
          uVar2 = puVar3[1];
        }
        else {
          uVar2 = *puVar3;
        }
        local_1c = puVar3[3];
        local_18 = puVar3[4];
        FUN_0040d600(local_14,(float)puVar3[9] * _DAT_00aea718);
        uVar5 = 0;
        puVar4 = local_14;
        puVar3 = &local_1c;
        FUN_00511d20(puVar3,puVar4,0);
        FUN_005118f0(puVar3,puVar4,uVar5);
        uVar6 = 0;
        uVar5 = 0;
        puVar4 = local_14;
        puVar3 = &local_c;
        FUN_00511d20(puVar3,puVar4,uVar2,0,0);
        FUN_00511c00(puVar3,puVar4,uVar2,uVar5,uVar6);
      }
    }
  }
  return;
}


// ==== FUN_00501640 @ 0x00501640 ====

void FUN_00501640(void)

{
  code *pcVar1;
  undefined4 uVar2;
  char cVar3;
  int *piVar4;
  byte *pbVar5;
  int iVar6;
  undefined4 uVar7;
  int in_ECX;
  undefined4 *puVar8;
  int local_78;
  uint uStack_6c;
  undefined4 *puStack_68;
  undefined1 auStack_64 [8];
  undefined4 uStack_5c;
  void *pvStack_58;
  int iStack_54;
  undefined4 uStack_50;
  undefined4 uStack_48;
  uint uStack_44;
  undefined1 auStack_40 [4];
  void *pvStack_3c;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  
  piVar4 = (int *)(**(code **)(*DAT_00b5abac + 8))();
  while (piVar4 != (int *)0x0) {
    pbVar5 = (byte *)(**(code **)(*piVar4 + 4))();
    puStack_68 = operator_new(0x28);
    uVar2 = DAT_009b0120;
    uVar7 = DAT_0099d080;
    if (puStack_68 == (undefined4 *)0x0) {
      puStack_68 = (undefined4 *)0x0;
    }
    else {
      *puStack_68 = DAT_0099d080;
      puStack_68[2] = uVar7;
      puStack_68[3] = 0;
      puStack_68[4] = 0;
      uStack_5c = 0;
      puStack_68[6] = 0;
      pvStack_58 = (void *)0x0;
      puStack_68[7] = 0;
      iStack_54 = 0;
      puStack_68[1] = uVar2;
      *(undefined2 *)(puStack_68 + 5) = 100;
      puStack_68[8] = 0;
      puStack_68[9] = 0;
    }
    uStack_6c = (uint)*pbVar5;
    FUN_00504760(auStack_64,&uStack_6c);
    piVar4 = (int *)(**(code **)(*DAT_00b5abac + 0xc))();
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  FUN_00401740(s_Producer_char_selectinfo_txt_009b51c0,0x1c);
  iVar6 = FUN_00410500(auStack_40);
  if (0xf < uStack_28) {
    _free(pvStack_3c);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  if (iVar6 == 0) {
    uStack_44 = 0xf;
    uStack_48 = 0;
    pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
    FUN_00401740(s_pScriptRes____NULL_009b51e0,0x12);
    FUN_00406880(&uStack_5c);
    if (uStack_44 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_58);
    return;
  }
  *(undefined4 *)(*(int *)(iVar6 + 0x4c) + 4) = 0;
  cVar3 = FUN_0049d7c0();
  local_78 = in_ECX;
  while( true ) {
    if (cVar3 != '\0') {
      (**(code **)(*DAT_00b5a7cc + 0x14))(iVar6);
      return;
    }
    puVar8 = &uStack_5c;
    pvStack_58 = (void *)0x0;
    iStack_54 = 0;
    uStack_50 = 0;
    uVar7 = FUN_0049d800(auStack_24);
    FUN_00405670(uVar7,puVar8);
    if (0xf < uStack_c) break;
    uStack_c = 0xf;
    uStack_10 = 0;
    pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
    if ((pvStack_58 != (void *)0x0) &&
       (local_78 = (iStack_54 - (int)pvStack_58) / 0x1c, local_78 != 0)) {
      FUN_005005a0(iVar6,&uStack_5c);
    }
    FUN_0049d780();
    if (pvStack_58 != (void *)0x0) {
      FUN_00405de0(pvStack_58,iStack_54,&uStack_5c,local_78);
      _free(pvStack_58);
      return;
    }
    pvStack_58 = (void *)0x0;
    iStack_54 = 0;
    uStack_50 = 0;
    cVar3 = FUN_0049d7c0();
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_005018b0 @ 0x005018b0 ====

void FUN_005018b0(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x58);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b5340;
    puVar1[6] = 0;
    puVar1[7] = 0xf;
    *(undefined1 *)(puVar1 + 2) = 0;
    puVar1[0xe] = 0xf;
    puVar1[0xd] = 0;
    *(undefined1 *)(puVar1 + 9) = 0;
    puVar1[0x10] = 0;
    puVar1[0x11] = 0;
    puVar1[0x12] = 0;
    *(undefined2 *)(puVar1 + 0x13) = 0;
    puVar1[0x14] = 0;
    puVar1[0x15] = 10000;
  }
  puVar1[0x14] = 0x10;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined2 *)(puVar1 + 0x13) = 0x2900;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00501930 @ 0x00501930 ====

void FUN_00501930(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  void *local_3c;
  void *pvStack_38;
  undefined4 uStack_2c;
  uint uStack_28;
  void *pvStack_24;
  void *pvStack_20;
  undefined4 uStack_14;
  uint uStack_10;
  uint uStack_c;
  
  iVar2 = (**(code **)(*DAT_00b5a74c + 0xc))(0x10);
  if (iVar2 == 0) {
    pvStack_24 = (void *)0xf;
    uStack_28 = 0;
    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    FUN_00401740(s_pUIHandler____NULL_009b5248,0x12);
    FUN_00406880(&local_3c);
    if (pvStack_24 < (void *)0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_38);
    return;
  }
  piVar3 = *(int **)(iVar2 + 4);
  if (piVar3 == (int *)0x0) {
    pvStack_24 = (void *)0xf;
    uStack_28 = 0;
    pvStack_38 = (void *)((uint)pvStack_38._1_3_ << 8);
    FUN_00401740(s_pWindow____NULL_009b525c,0xf);
    FUN_00406880(&local_3c);
    if (pvStack_24 < (void *)0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_38);
    return;
  }
  pvStack_24 = (void *)0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38._1_3_ << 8);
  FUN_00401740(s_btn_servertransfer_009b526c,0x12);
  piVar3 = (int *)(**(code **)(*piVar3 + 0x34))(&local_3c);
  if (0xf < uStack_28) {
    _free(local_3c);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  local_3c = (void *)((uint)local_3c & 0xffffff00);
  if (piVar3 == (int *)0x0) {
    uStack_c = 0xf;
    uStack_10 = 0;
    pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009b5280,0x12);
    FUN_00406880(&pvStack_24);
    if (uStack_c < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_20);
    return;
  }
  iVar2 = *DAT_00b5ac80;
  iVar4 = (**(code **)(*DAT_00b5ac1c + 8))();
  iVar2 = (**(code **)(iVar2 + 8))(*(undefined1 *)(iVar4 + 4));
  if (*(char *)(iVar2 + 0x102) == '\0') {
    (**(code **)(*piVar3 + 0x44))(0);
    (**(code **)(*piVar3 + 0x24))(0);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_servertransfer_ui_servertransfer_009b5294,0x2c);
  FUN_005018b0(&uStack_28);
  if (uStack_10 < 0x10) {
    (**(code **)(*piVar3 + 0x44))(1);
    (**(code **)(*piVar3 + 0x24))(1);
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_00501b00 @ 0x00501b00 ====

void FUN_00501b00(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5354;
  iVar1 = FUN_00503a20();
  in_ECX[5] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[5] + 4) = in_ECX[5];
  *(undefined4 *)in_ECX[5] = in_ECX[5];
  *(undefined4 *)(in_ECX[5] + 8) = in_ECX[5];
  in_ECX[6] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  uVar3 = (**(code **)(*piVar2 + 4))(0,s___SceneModel_Game_CharSelectScen_009b4c8c,0x46);
  in_ECX[1] = uVar3;
  in_ECX[10] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  *(undefined1 *)((int)in_ECX + 0x39) = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1d] = 0;
  *(undefined1 *)((int)in_ECX + 0x3a) = 0;
  in_ECX[2] = 0xffffffff;
  *(undefined1 *)(in_ECX + 0xe) = 1;
  in_ECX[0x1c] = 1;
  return;
}


// ==== FUN_00501ba0 @ 0x00501ba0 ====

void FUN_00501ba0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int in_ECX;
  void *unaff_EBP;
  void *unaff_ESI;
  void *unaff_EDI;
  undefined4 local_20;
  void *pvStack_1c;
  uint uStack_18;
  uint uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  
  local_20 = 0;
  (**(code **)(*DAT_00b5add8 + 4))(1);
  FUN_00501640();
  puVar7 = *(undefined4 **)(in_ECX + 0x14);
  puVar2 = (undefined4 *)*puVar7;
  pvVar5 = operator_new(0x84);
  uVar6 = 0;
  if (pvVar5 != (void *)0x0) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_Empty_009b4d04,5);
    uVar6 = FUN_004b5800(&local_20);
  }
  *(undefined4 *)(in_ECX + 0x6c) = uVar6;
  if ((pvVar5 != (void *)0x0) && (0xf < uStack_8)) {
    _free(pvStack_1c);
    return;
  }
  while (puVar2 != puVar7) {
    FUN_004fff20(*(undefined2 *)(puVar2[4] + 0x14));
    if (*(char *)((int)puVar2 + 0x15) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x15);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x15);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x15);
        puVar4 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar4, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x15);
          puVar4 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  (**(code **)(*DAT_00b5a750 + 8))(0x10);
  pvVar5 = operator_new(0x14);
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_0050f0d0();
  }
  *(undefined4 *)(in_ECX + 0x28) = uVar6;
  FUN_0050f180(600);
  *(undefined1 *)(in_ECX + 0x68) = 0xff;
  *(undefined4 *)(in_ECX + 0xc) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x34) = 0xffffffff;
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 100) = 0xffffffff;
  uStack_c = 0xf;
  uStack_10 = 0;
  local_20 = local_20 & 0xffffff00;
  FUN_00401740(s_rc_mipmap__10_009b4d0c,0xd);
  (**(code **)(*DAT_00b5a688 + 4))((int)register0x00000010 + -0x24);
  if (0xf < uStack_10) {
    _free(puVar7);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740(s_ds_zfar_1000_009b4d1c,0xc);
  (**(code **)(*DAT_00b5a688 + 4))((int)register0x00000010 + -0x28);
  if (0xf < uStack_14) {
    _free(unaff_EBP);
    return;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  FUN_00401740(s_rc_waterlevel_2_009b4d2c,0xf);
  (**(code **)(*DAT_00b5a688 + 4))((int)register0x00000010 + -0x2c);
  if (0xf < uStack_18) {
    _free(unaff_ESI);
    return;
  }
  uStack_18 = 0xf;
  pvStack_1c = (void *)0x0;
  FUN_00401740(s_ds_lod_0_009b4d3c,8);
  (**(code **)(*DAT_00b5a688 + 4))((int)register0x00000010 + -0x30);
  if (0xf < pvStack_1c) {
    _free(unaff_EDI);
    return;
  }
  puVar7 = operator_new(4);
  if (puVar7 == (undefined4 *)0x0) {
    puVar7 = (undefined4 *)0x0;
  }
  else {
    *puVar7 = &PTR_FUN_009b45dc;
  }
  FUN_00797a20(puVar7);
  FUN_00501930();
  return;
}


// ==== FUN_00501e20 @ 0x00501e20 ====

void FUN_00501e20(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x38) == '\0') {
    iVar2 = *(int *)(in_ECX + 0x28);
    if (iVar2 != 0) {
      if (*(char *)(iVar2 + 0xc) != '\0') {
        param_1 = *(undefined4 *)(param_1 + 4);
        FUN_0050f0f0(&param_1);
        return;
      }
      if (*(int *)(iVar2 + 0x10) == 2) {
        FUN_00501440();
        return;
      }
    }
  }
  else {
    iVar2 = (**(code **)(*DAT_00b5a6ac + 0x24))();
    cVar1 = FUN_004b59a0();
    while (cVar1 == '\0') {
      iVar3 = (**(code **)(*DAT_00b5a6ac + 0x24))();
      if (200 < (uint)(iVar3 - iVar2)) {
        return;
      }
      cVar1 = FUN_004b59a0();
    }
    *(undefined1 *)(in_ECX + 0x38) = 0;
    FUN_004ffd40();
    FUN_0050f180(1000);
  }
  return;
}


// ==== FUN_00501ec0 @ 0x00501ec0 ====

/* WARNING: Removing unreachable block (ram,0x00501f95) */

void FUN_00501ec0(void)

{
  int iVar1;
  undefined4 *puVar2;
  code *pcVar3;
  int *piVar4;
  char cVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  undefined1 auStack_22 [34];
  
  piVar6 = (int *)(**(code **)(*DAT_00b5a6e0 + 0xc))(1,0);
  iVar1 = *(int *)(in_ECX + 0x50);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x58) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x54) - iVar1 >> 2)))
  {
    FUN_00504820(*(undefined4 *)(in_ECX + 0x54),1,auStack_22 + -10);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0x54);
    *puVar2 = piVar6;
    *(undefined4 **)(in_ECX + 0x54) = puVar2 + 1;
  }
  piVar4 = DAT_00b5a6ac;
  FUN_00424520();
  iVar1 = *piVar6;
  uVar7 = (**(code **)(*piVar4 + 0x20))();
  cVar5 = (**(code **)(iVar1 + 0x1c))(auStack_22 + -10,uVar7);
  if (cVar5 == '\0') {
    FUN_00401740(s_openResult_009b4de8,10);
    FUN_00406880(auStack_22 + -10);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  return;
}


// ==== FUN_00501fb0 @ 0x00501fb0 ====

uint FUN_00501fb0(uint param_1)

{
  int in_ECX;
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + 1;
    if (*(int *)(in_ECX + 0x2c) == 1) {
      uVar1 = 3;
    }
    else {
      uVar1 = 2;
    }
    param_1 = FUN_00501550(1,uVar1);
    param_1 = param_1 & 0xffffff00;
    if (5 < *(uint *)(in_ECX + 0x2c)) {
      *(undefined4 *)(in_ECX + 0x2c) = 0;
      return param_1;
    }
  }
  else {
    param_1 = param_1 & 0xffffff00;
  }
  return param_1;
}


// ==== FUN_00501ff0 @ 0x00501ff0 ====

void FUN_00501ff0(int param_1)

{
  short *psVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined3 uVar7;
  undefined4 uVar6;
  ushort uVar8;
  int in_ECX;
  undefined2 extraout_var;
  undefined4 in_EDX;
  undefined2 uVar9;
  int unaff_EBX;
  int iVar10;
  undefined2 *puVar11;
  undefined1 uStack_50;
  undefined1 uStack_4f;
  undefined1 uStack_4e;
  undefined1 uStack_4d;
  undefined4 local_4c;
  undefined4 uStack_48;
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  byte bStack_8;
  
  if (*(void **)(in_ECX + 0x40) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x40));
    return;
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  uVar6 = CONCAT22((short)((uint)in_EDX >> 0x10),*(undefined2 *)(param_1 + 0x16));
  iVar3 = (**(code **)(*DAT_00b5a6dc + 8))
                    (CONCAT31((int3)((uint)uVar6 >> 8),*(undefined1 *)(param_1 + 0x2a)),0,uVar6);
  uStack_2c = 0xf;
  uStack_10 = 0xf;
  uVar7 = 0;
  puVar11 = (undefined2 *)(param_1 + 4);
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  uStack_4d = 0;
  uStack_50 = 0;
  uStack_4f = 0;
  uStack_4e = 0;
  uStack_48 = DAT_0099d080;
  local_4c = 0xffffffff;
  bStack_8 = 2;
  iVar10 = 2;
  do {
    uVar9 = (undefined2)((uint)puVar11 >> 0x10);
    if ((bStack_8 < 7) || (10 < bStack_8)) {
      puVar4 = (undefined2 *)CONCAT31(uVar7,bStack_8 - 2);
      uVar8 = (byte)(bStack_8 - 2) + 1;
      if ((*(ushort *)(iVar3 + 0x114) & uVar8) != uVar8) {
        iVar5 = (**(code **)(*DAT_00b5a6dc + 8))
                          (CONCAT31(uVar7,*(undefined1 *)(param_1 + 0x2a)),puVar4,
                           CONCAT22(uVar9,*puVar11));
        FUN_00401660(iVar5 + 0x78,0,0xffffffff);
        FUN_00401660(iVar5 + 0x94,0,0xffffffff);
        uStack_4d = FUN_004ffb70(CONCAT22(extraout_var,*puVar11));
        FUN_004ff800(&uStack_50);
        puVar4 = (undefined2 *)(iVar5 + 0xb0);
        if (*(short *)(iVar5 + 0xb0) != 0) {
          iVar5 = *(int *)(in_ECX + 0x40);
          if ((iVar5 == 0) ||
             ((uint)(*(int *)(in_ECX + 0x48) - iVar5 >> 1) <=
              (uint)(*(int *)(in_ECX + 0x44) - iVar5 >> 1))) {
            puVar4 = (undefined2 *)FUN_00427290(*(undefined4 *)(in_ECX + 0x44),1,puVar4);
          }
          else {
            puVar2 = *(undefined2 **)(in_ECX + 0x44);
            uVar9 = *puVar4;
            puVar4 = (undefined2 *)CONCAT22((short)((uint)puVar4 >> 0x10),uVar9);
            *puVar2 = uVar9;
            *(undefined2 **)(in_ECX + 0x44) = puVar2 + 1;
          }
        }
      }
    }
    else {
      puVar4 = (undefined2 *)(**(code **)(*DAT_00b5a6dc + 0x18))(0,CONCAT22(uVar9,*puVar11));
      if (puVar4 != (undefined2 *)0x0) {
        FUN_005003a0(iVar10,param_1,*(undefined4 *)(unaff_EBX + 0x20));
        psVar1 = puVar4 + 0x58;
        puVar4 = puVar4 + 0x58;
        if (*psVar1 != 0) {
          puVar4 = (undefined2 *)FUN_004275a0(puVar4);
        }
      }
    }
    uVar7 = (undefined3)((uint)puVar4 >> 8);
    iVar10 = iVar10 + 1;
    bStack_8 = bStack_8 + 1;
    puVar11 = puVar11 + 1;
  } while (bStack_8 < 0xb);
  if (*(short *)(iVar3 + 0x114) != 0) {
    uVar6 = CONCAT22((short)((uint)&uStack_50 >> 0x10),*(undefined2 *)(param_1 + 0x16));
    iVar10 = (**(code **)(*DAT_00b5a6dc + 0x14))
                       (CONCAT31((int3)((uint)uVar6 >> 8),*(undefined1 *)(param_1 + 0x2a)),uVar6,
                        &uStack_50);
    FUN_00401660(iVar10,0,0xffffffff);
    FUN_00401660(iVar10 + 0x1c,0,0xffffffff);
    uStack_4d = 0;
    FUN_004ff800(&uStack_50);
  }
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return;
  }
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  uStack_10 = 0xf;
  if (uStack_2c < 0x10) {
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_00502270 @ 0x00502270 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00502270(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  int in_ECX;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined1 auStack_4c [8];
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 auStack_38 [4];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  uint uStack_10;
  undefined4 auStack_8 [2];
  
  piVar2 = param_1;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  iVar1 = FUN_00500e80(*param_1);
  if (iVar1 == 0) {
    FUN_004ffa50();
    param_1 = (int *)0x0;
    FUN_004ffc40(&param_1);
    return;
  }
  if (*(int *)(in_ECX + 0xc) != *piVar2) {
    *(undefined1 *)(in_ECX + 0x39) = 0;
    *(int *)(in_ECX + 0xc) = *piVar2;
    *(uint *)(in_ECX + 0x34) = (uint)*(byte *)(iVar1 + 0x2a);
    FUN_004ffa50();
    param_1 = *(int **)(in_ECX + 0x34);
    FUN_004ffc40(&param_1);
    param_1 = (int *)(uint)*(byte *)(iVar1 + 0x2a);
    FUN_0079bba0(&local_54,&param_1);
    if (local_54 == *(int *)(in_ECX + 0x14)) {
      FUN_00500820();
      return;
    }
    puVar6 = *(undefined4 **)(local_54 + 0x10);
    piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
    uVar3 = (**(code **)(*piVar2 + 4))(0,s___SceneModel_Game_CharSelectScen_009b5098,0x4a3);
    local_54 = puVar6[3];
    uStack_50 = puVar6[4];
    FUN_0040d600(auStack_4c,(float)puVar6[9] * _DAT_00aea718);
    pvVar4 = operator_new(0x40);
    if (pvVar4 == (void *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_005121e0();
    }
    *(int *)(in_ECX + 0x20) = iVar5;
    *(undefined1 *)(iVar5 + 0xf) = 1;
    auStack_8[0] = 0;
    FUN_00512130(uVar3,&local_54,auStack_4c,0,puVar6[2],auStack_4c + -0x10,auStack_8,1,1,1);
    FUN_00401830(PTR_DAT_00aea714);
    puVar7 = auStack_4c + -0x10;
    puVar9 = auStack_28;
    FUN_00511d10(puVar9,puVar7);
    FUN_00512e40(puVar9,puVar7);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    FUN_00501ff0(iVar1,auStack_38);
    FUN_00511ea0(0);
    puVar7 = auStack_38;
    FUN_00511d10(puVar7);
    FUN_00512cd0();
    FUN_00512a20(puVar7);
    uVar3 = 0;
    puVar7 = auStack_4c;
    puVar8 = &local_54;
    uStack_44 = 0;
    uStack_40 = 1;
    uStack_3c = 2;
    auStack_8[0] = *puVar6;
    FUN_00511d20(puVar8,puVar7,0);
    FUN_005118f0(puVar8,puVar7,uVar3);
    uVar11 = 0;
    uVar10 = 0;
    puVar7 = auStack_4c;
    puVar6 = &uStack_44;
    uVar3 = auStack_8[0];
    FUN_00511d20(puVar6,puVar7,auStack_8[0],0,0);
    FUN_00511c00(puVar6,puVar7,uVar3,uVar10,uVar11);
    FUN_00500820();
    FUN_004ffc00();
    FUN_004ff750();
  }
  return;
}


// ==== FUN_005024c0 @ 0x005024c0 ====

undefined4 FUN_005024c0(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined1 auStack_24 [36];
  
  switch(*(undefined4 *)(param_1 + 4)) {
  case 0:
    if ((*(int *)(in_ECX + 0x50) == 0) ||
       ((uint)(*(int *)(in_ECX + 0x54) - *(int *)(in_ECX + 0x50) >> 2) < 6)) {
      *(undefined4 *)(in_ECX + 8) = 0;
      uStack_44 = 0x502505;
      FUN_0050f200();
    }
    return 1;
  case 1:
    *(undefined4 *)(in_ECX + 8) = 1;
    uStack_44 = 0x502522;
    FUN_0050f200();
    return 1;
  case 2:
    if ((*(int *)(in_ECX + 0xc) != -1) && (*(char *)(in_ECX + 0x68) != -1)) {
      *(undefined4 *)(in_ECX + 8) = 2;
      uStack_44 = 0x502589;
      FUN_0050f200();
    }
    return 1;
  case 3:
    uStack_44 = 0x1e000b;
    uStack_48 = 0;
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50(uVar3);
    FUN_00500de0(auStack_24 + -0x1c,*(undefined4 *)(in_ECX + 0xc));
    piVar2 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
    *(undefined4 *)(in_ECX + 8) = 3;
    (**(code **)*piVar2)(0x16,auStack_24);
    iVar1 = *piVar2;
    uVar3 = FUN_006eb2b0(&uStack_48);
    (**(code **)(iVar1 + 4))(uVar3);
    (**(code **)(*DAT_00b5a9e0 + 0x20))(1);
    (**(code **)(*DAT_00b5a9dc + 0xc))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 4:
    *(undefined4 *)(in_ECX + 8) = 4;
    uStack_44 = 0x502643;
    FUN_00502270();
    FUN_00500ee0();
    break;
  default:
    return 0;
  case 8:
    *(undefined4 *)(in_ECX + 8) = 8;
    if (*(int *)(in_ECX + 0x50) != *(int *)(in_ECX + 0x54)) {
      uStack_44 = 0x50254a;
      piVar2 = (int *)FUN_00689e70();
      if (*piVar2 != 0) {
        uStack_44 = 0x502560;
        (**(code **)(*DAT_00b5ae20 + 0x14))();
        return 1;
      }
    }
  }
  return 1;
}


// ==== FUN_00502680 @ 0x00502680 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_00502680(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined2 *param_5)

{
  char cVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  void *pvVar8;
  char *pcVar9;
  undefined4 unaff_EBX;
  undefined4 *puVar10;
  void **ppvVar11;
  uint in_stack_ffffef3c;
  uint3 uVar12;
  undefined4 uStack_1094;
  undefined1 auStack_1090 [4];
  void *pvStack_108c;
  int iStack_1088;
  int *piStack_1084;
  uint uStack_1080;
  void *pvStack_107c;
  undefined4 uStack_1078;
  undefined4 uStack_1074;
  undefined4 uStack_1070;
  void *pvStack_106c;
  undefined4 uStack_1068;
  undefined4 uStack_1064;
  undefined4 uStack_1060;
  undefined4 uStack_105c;
  uint uStack_1058;
  int *piStack_1050;
  void *pvStack_1048;
  int *piStack_1044;
  int *piStack_1040;
  int iStack_103c;
  undefined4 uStack_1038;
  uint uStack_1034;
  void *apvStack_1018 [4];
  undefined4 uStack_1008;
  uint uStack_1004;
  undefined4 uStack_c;
  
  uStack_c = 0x502690;
  iVar4 = (**(code **)(*DAT_00b5a74c + 0xc))(0x10);
  if (iVar4 == 0) {
    uStack_1080 = 0xf;
    piStack_1084 = (int *)0x0;
    uStack_1094 = (void *)((uint)uStack_1094._1_3_ << 8);
    FUN_00401740(s_pUIHandler____NULL_009b50e0,0x12);
    FUN_00406880(auStack_1090 + -8);
    if (uStack_1080 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(uStack_1094);
    return;
  }
  piVar6 = *(int **)(iVar4 + 4);
  if (piVar6 == (int *)0x0) {
    uStack_1080 = 0xf;
    piStack_1084 = (int *)0x0;
    uStack_1094 = (void *)((uint)uStack_1094._1_3_ << 8);
    FUN_00401740(s_pWindow____NULL_009b50f4,0xf);
    FUN_00406880(auStack_1090 + -8);
    if (uStack_1080 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(uStack_1094);
    return;
  }
  FUN_00401740(s_character_list_btn__d_009b5104,0x15);
  ppvVar11 = apvStack_1018;
  uVar5 = FUN_00404230(ppvVar11);
  piStack_1040 = (int *)(**(code **)(*piVar6 + 0x34))(uVar5);
  if (0xf < uStack_1004) {
    _free(apvStack_1018[0]);
    return;
  }
  uStack_1004 = 0xf;
  uStack_1008 = 0;
  apvStack_1018[0] = (void *)((uint)apvStack_1018[0] & 0xffffff00);
  iStack_103c = (**(code **)(*piStack_1040 + 0x30))();
  uVar12 = (uint3)((uint)unaff_EBX >> 8);
  if (iStack_103c == 0) {
    piStack_1084 = (int *)0xf;
    iStack_1088 = 0;
    FUN_00401740(s_pButton____NULL_009b511c,0xf);
    FUN_00406880(auStack_1090 + -0xc);
    if (piStack_1084 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free((void *)((uint)uVar12 << 8));
    return;
  }
  uStack_1068 = 0;
  uStack_1064 = 0;
  uStack_1060 = 0;
  piStack_1084 = (int *)0xf;
  iStack_1088 = 0;
  uVar3 = (uint)uVar12;
  FUN_00401740(&DAT_009b512c,1);
  FUN_00406720(auStack_1090 + -0xc);
  if (0xf < piStack_1084) {
    _free((void *)(uVar3 << 8));
    return;
  }
  piStack_1084 = (int *)0xf;
  iStack_1088 = 0;
  FUN_00401740(&DAT_009b5130,1);
  FUN_00406720(auStack_1090 + -0xc);
  if (0xf < piStack_1084) {
    _free((void *)(uVar3 << 8));
    return;
  }
  piStack_1084 = (int *)0xf;
  iStack_1088 = 0;
  FUN_00401740(&DAT_009b5134,1);
  FUN_00406720(auStack_1090 + -0xc);
  if (0xf < piStack_1084) {
    _free((void *)(uVar3 << 8));
    return;
  }
  uStack_1078 = 0;
  uStack_1074 = 0;
  uStack_1070 = 0;
  piStack_1084 = (int *)0xf;
  iStack_1088 = 0;
  FUN_00401740(s___BS___009b5138,6);
  FUN_00406720(auStack_1090 + -0xc);
  if (0xf < piStack_1084) {
    _free((void *)(uVar3 << 8));
    return;
  }
  piStack_1084 = (int *)0xf;
  iStack_1088 = 0;
  FUN_00401740(s___GT___009b5140,6);
  FUN_00406720(auStack_1090 + -0xc);
  if (0xf < piStack_1084) {
    _free((void *)(uVar3 << 8));
    return;
  }
  piStack_1084 = (int *)0xf;
  iStack_1088 = 0;
  FUN_00401740(s___LT___009b5148,6);
  FUN_00406720(auStack_1090 + -0xc);
  if (0xf < piStack_1084) {
    _free((void *)(uVar3 << 8));
    return;
  }
  FUN_00404a40(&uStack_1038,param_2,&pvStack_106c,&pvStack_107c);
  piStack_1044 = (int *)0xf;
  pvStack_1048 = (void *)0x0;
  uStack_1058 = uStack_1058 & 0xffffff00;
  FUN_00401ff0(&uStack_1038,0,0xffffffff);
  FUN_004020e0(&DAT_009b5150,1);
  in_stack_ffffef3c = in_stack_ffffef3c & 0xffffff00;
  FUN_00401740(s_LV__d_009b5154,6);
  uVar5 = FUN_00404230(auStack_1090 + -0xc,ppvVar11,in_stack_ffffef3c);
  FUN_00401ff0(uVar5,0,0xffffffff);
  if (0xf < piStack_1084) {
    _free((void *)(uVar3 << 8));
    return;
  }
  piStack_1084 = (int *)(**(code **)(*DAT_00b5abac + 0x10))(*param_4);
  if (piStack_1084 != (int *)0x0) {
    iVar4 = (**(code **)(*piStack_1084 + 4))();
    pcVar9 = (char *)(iVar4 + 0x20);
    do {
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    FUN_004020e0((char *)(iVar4 + 0x20),(int)pcVar9 - (iVar4 + 0x21));
    FUN_004020e0(&DAT_009b515c,1);
  }
  piVar6 = (int *)(**(code **)(*DAT_00b5ab14 + 8))(*param_5);
  if (piVar6 != (int *)0x0) {
    puVar7 = (undefined4 *)(**(code **)(*piVar6 + 0x10))();
    pcVar9 = (char *)((int)&uStack_1008 + 2);
    puVar10 = &uStack_1008;
    for (iVar4 = 0x3fb; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar10 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar10 = puVar10 + 1;
    }
    do {
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    FUN_004020e0((int)&uStack_1008 + 2,(int)pcVar9 - ((int)&uStack_1008 + 3));
  }
  pvVar8 = operator_new(0x468);
  if (pvVar8 == (void *)0x0) {
    pvVar8 = (void *)0x0;
  }
  else {
    pvVar8 = (void *)FUN_00505f10();
  }
  FUN_00505cc0(piStack_1044 + 0x32);
  if (iStack_1088 != 0) {
    iStack_1088 = 0;
    FUN_00505850(&iStack_1088);
    FUN_00401660(&uStack_1064,0,0xffffffff);
  }
  piVar6 = piStack_1044;
  FUN_00558730(0);
  (**(code **)(*piVar6 + 0x24))(pvVar8);
  if (pvVar8 != (void *)0x0) {
    FUN_00505d80();
    _free(pvVar8);
    return;
  }
  iVar4 = *piVar6;
  uVar5 = FUN_00558120();
  (**(code **)(iVar4 + 8))(uVar5);
  (**(code **)(*piStack_1050 + 0x24))(1);
  if (0xf < uStack_1058) {
    _free(pvStack_106c);
    return;
  }
  uStack_1058 = 0xf;
  uStack_105c = 0;
  pvStack_106c = (void *)((uint)pvStack_106c & 0xffffff00);
  if (0xf < uStack_1034) {
    _free(pvStack_1048);
    return;
  }
  uStack_1034 = 0xf;
  uStack_1038 = 0;
  pvStack_1048 = (void *)((uint)pvStack_1048 & 0xffffff00);
  if (pvStack_108c != (void *)0x0) {
    FUN_00405de0(pvStack_108c,iStack_1088,auStack_1090,uStack_1094);
    _free(pvStack_108c);
    return;
  }
  pvStack_108c = (void *)0x0;
  iStack_1088 = 0;
  piStack_1084 = (int *)0x0;
  if (pvStack_107c == (void *)0x0) {
    return;
  }
  FUN_00405de0(pvStack_107c,uStack_1078,&uStack_1080,uStack_1094);
  _free(pvStack_107c);
  return;
}


// ==== FUN_00502c10 @ 0x00502c10 ====

void FUN_00502c10(void)

{
  char cVar1;
  ushort uVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  int *piVar8;
  undefined2 *puVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  int *piVar12;
  undefined3 *puVar13;
  char *pcVar14;
  void *unaff_EBP;
  uint uVar15;
  undefined1 auStack_182 [2];
  void *pvStack_180;
  void *pvStack_17c;
  uint uStack_178;
  void *pvStack_174;
  void *pvStack_170;
  uint uStack_16c;
  uint uStack_168;
  undefined4 uStack_164;
  void *pvStack_160;
  void *pvStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_150;
  uint uStack_14c;
  uint uStack_148;
  int *piStack_144;
  uint local_140;
  uint uStack_13c;
  uint uStack_138;
  uint uStack_134;
  int *piStack_130;
  void *pvStack_12c;
  void *pvStack_128;
  undefined1 uStack_124;
  undefined1 uStack_123;
  undefined1 uStack_122;
  undefined4 uStack_120;
  int iStack_11c;
  uint uStack_118;
  uint uStack_114;
  int iStack_110;
  void *pvStack_10c;
  undefined4 uStack_108;
  undefined1 uStack_100;
  undefined4 uStack_fc;
  uint uStack_f8;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  int iStack_d8;
  undefined4 uStack_d4;
  void *pvStack_d0;
  undefined1 uStack_c8;
  undefined4 uStack_c0;
  uint uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined1 uStack_ac;
  undefined1 uStack_ab;
  undefined1 uStack_aa;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  void *pvStack_94;
  undefined4 uStack_90;
  undefined1 uStack_88;
  undefined4 uStack_84;
  uint uStack_80;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined1 uStack_70;
  undefined1 uStack_6f;
  undefined1 uStack_6e;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  int iStack_60;
  undefined4 uStack_5c;
  void *pvStack_58;
  undefined4 uStack_54;
  undefined1 uStack_4c;
  uint uStack_44;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  void *apvStack_28 [2];
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  undefined4 uStack_c;
  uint uStack_8;
  
  iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))();
  if (iVar5 == 0) {
    uStack_168 = 0xf;
    uStack_16c = 0;
    pvStack_17c = (void *)((uint)pvStack_17c._1_3_ << 8);
    FUN_00401740(s_pUIHandler____NULL_009b4f20,0x12);
    FUN_00406880(&pvStack_180);
    if (uStack_168 < 0x10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    _free(pvStack_17c);
    return;
  }
  piVar12 = *(int **)(iVar5 + 4);
  piStack_130 = piVar12;
  if (piVar12 == (int *)0x0) {
    uStack_168 = 0xf;
    uStack_16c = 0;
    pvStack_17c = (void *)((uint)pvStack_17c._1_3_ << 8);
    FUN_00401740(s_pWindow____NULL_009b4f34,0xf);
    FUN_00406880(&pvStack_180);
    if (uStack_168 < 0x10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    _free(pvStack_17c);
    return;
  }
  uVar15 = 0;
  do {
    FUN_00401740(s_character_list_btn__d_009b4f44,0x15);
    FUN_00404230(&pvStack_180);
    piVar6 = (int *)(**(code **)(*piVar12 + 0x34))(&pvStack_180);
    if (piVar6 == (int *)0x0) {
      uStack_118 = 0xf;
      iStack_11c = 0;
      pvStack_12c = (void *)((uint)pvStack_12c & 0xffffff00);
      FUN_00401740(s_pComposite____NULL_009b4f5c,0x12);
      FUN_00406880(&piStack_130);
      if (uStack_118 < 0x10) {
        uStack_118 = 0xf;
        iStack_11c = 0;
        pvStack_12c = (void *)((uint)pvStack_12c & 0xffffff00);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      _free(pvStack_12c);
      return;
    }
    (**(code **)(*piVar6 + 0x24))(0);
    piVar6 = piStack_144;
    if (0xf < uStack_168) {
      _free(pvStack_17c);
      return;
    }
    uVar15 = uVar15 + 1;
    uStack_168 = 0xf;
    uStack_16c = 0;
    uVar4 = (uint)pvStack_17c >> 8;
    pvStack_17c = (void *)(uVar4 << 8);
  } while (uVar15 < 6);
  piStack_144[3] = -1;
  if (piStack_144[0x14] == 0) {
    uVar15 = 0;
  }
  else {
    uVar15 = piStack_144[0x15] - piStack_144[0x14] >> 2;
    if (6 < uVar15) {
      uStack_168 = 0xf;
      uStack_16c = 0;
      pvStack_17c = (void *)(uVar4 << 8);
      FUN_00401740(s_dwNumChar_<__s_dwMaxCharCount_009b4f70,0x1d);
      FUN_00406880(&pvStack_180);
      if (uStack_168 < 0x10) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      _free(pvStack_17c);
      return;
    }
  }
  local_140 = 0;
  if (uVar15 != 0) {
    do {
      iVar5 = piVar6[0x14];
      if ((iVar5 == 0) || ((uint)(piVar6[0x15] - iVar5 >> 2) <= local_140)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      piVar12 = *(int **)(iVar5 + local_140 * 4);
      pcVar7 = (char *)(**(code **)(*piVar12 + 0x70))();
      uStack_114 = 0xf;
      uStack_118 = 0;
      pvStack_128 = (void *)((uint)pvStack_128 & 0xffffff00);
      pcVar14 = pcVar7;
      do {
        cVar1 = *pcVar14;
        pcVar14 = pcVar14 + 1;
      } while (cVar1 != '\0');
      FUN_00401740(pcVar7,(int)pcVar14 - (int)(pcVar7 + 1));
      if ((int *)piVar12[0x12] == (int *)0x0) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = (int *)(**(code **)(*(int *)piVar12[0x12] + 0x28))();
      }
      puVar9 = (undefined2 *)(**(code **)(*piVar8 + 8))();
      uStack_134 = CONCAT22(uStack_134._2_2_,*puVar9);
      if ((int *)piVar12[1] == (int *)0x0) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = (int *)(**(code **)(*(int *)piVar12[1] + 0x18))();
      }
      puVar10 = (undefined1 *)(**(code **)(*piVar8 + 8))();
      uStack_164 = CONCAT13(*puVar10,(undefined3)uStack_164);
      iVar5 = (**(code **)(*piVar12 + 0x74))();
      uVar4 = local_140;
      uVar2 = *(ushort *)(iVar5 + 0x30);
      FUN_00401740(&DAT_009b4f90,3);
      uVar11 = FUN_00404230(auStack_20);
      uStack_148 = 0xf;
      uStack_14c = 0;
      pvStack_15c = (void *)((uint)pvStack_15c & 0xffffff00);
      FUN_00401660(uVar11,0,0xffffffff);
      uVar11 = FUN_00401ff0(&pvStack_12c,0,0xffffffff);
      uStack_168 = 0xf;
      uStack_16c = 0;
      pvStack_17c = (void *)((uint)pvStack_17c & 0xffffff00);
      FUN_00401660(uVar11,0,0xffffffff);
      if (0xf < uStack_148) {
        _free(pvStack_15c);
        return;
      }
      uStack_148 = 0xf;
      uStack_14c = 0;
      pvStack_15c = (void *)((uint)pvStack_15c & 0xffffff00);
      FUN_00796d20(&pvStack_180);
      if (0xf < uStack_168) {
        _free(pvStack_17c);
        return;
      }
      uStack_168 = 0xf;
      uStack_16c = 0;
      pvStack_17c = (void *)((uint)pvStack_17c & 0xffffff00);
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return;
      }
      uStack_13c = uStack_164 >> 0x18;
      uStack_134 = uStack_134 & 0xffff;
      uStack_138 = (uint)uVar2;
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      FUN_00502680(&local_140,&pvStack_12c,&uStack_134,&uStack_13c,&uStack_138);
      if (0xf < uStack_114) {
        _free(pvStack_128);
        return;
      }
      local_140 = uVar4 + 1;
      uStack_114 = 0xf;
      uStack_118 = 0;
      pvStack_128 = (void *)((uint)pvStack_128 & 0xffffff00);
    } while (local_140 < uVar15);
    piVar12 = piStack_130;
  }
  piStack_144[0xc] = uVar15;
  uStack_13c = uVar15 - 1;
  uStack_138 = uStack_13c;
  FUN_00502270(&uStack_13c);
  (**(code **)(*DAT_00b5ae30 + 8))();
  uStack_168 = 0xf;
  uStack_16c = 0;
  pvStack_17c = (void *)((uint)pvStack_17c & 0xffffff00);
  FUN_00401740(s_btn_create_char_009b4f94,0xf);
  piVar8 = (int *)(**(code **)(*piVar12 + 0x34))(&pvStack_180);
  if (0xf < uStack_16c) {
    _free(pvStack_180);
    return;
  }
  uStack_16c = 0xf;
  pvStack_170 = (void *)0x0;
  pvStack_180 = (void *)((uint)pvStack_180 & 0xffffff00);
  if (piVar8 == (int *)0x0) {
    uStack_14c = 0xf;
    uStack_150 = 0;
    pvStack_160 = (void *)((uint)pvStack_160 & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009b4fa4,0x12);
    FUN_00406880(&uStack_164);
    if (uStack_14c < 0x10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    _free(pvStack_160);
    return;
  }
  if ((piVar6[0x14] == 0) || ((uint)(piVar6[0x15] - piVar6[0x14] >> 2) < 6)) {
    piVar6 = (int *)0x1;
    (**(code **)(*piVar8 + 0x44))();
  }
  else {
    piVar6 = (int *)0x0;
    (**(code **)(*piVar8 + 0x44))();
  }
  FUN_00401740(s_character_list_btn__d_009b4fb8,0x15);
  uVar11 = FUN_00404230(apvStack_28);
  piVar8 = (int *)(**(code **)(*piVar12 + 0x34))(uVar11);
  if (0xf < uStack_14) {
    _free(apvStack_28[0]);
    return;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  apvStack_28[0] = (void *)((uint)apvStack_28[0] & 0xffffff00);
  if (piVar8 != (int *)0x0) {
    pvStack_174 = (void *)0xf;
    uStack_178 = 0;
    FUN_00401740(s_pan_class_select3_009b4fd0,0x11);
    (**(code **)(*piVar12 + 0x34))(auStack_182 + -10);
    if (0xf < uStack_178) {
      _free(unaff_EBP);
      return;
    }
    uStack_178 = 0xf;
    pvStack_17c = (void *)0x0;
    uStack_158 = 0xf;
    pvStack_15c = (void *)0x0;
    uStack_16c = uStack_16c & 0xffffff00;
    FUN_00401740(s_pan_class_select1_009b4fe4,0x11);
    piVar12 = (int *)(**(code **)(*piVar12 + 0x34))(&pvStack_170);
    if (0xf < pvStack_15c) {
      _free(pvStack_170);
      return;
    }
    pvStack_15c = (void *)0xf;
    pvStack_160 = (void *)0x0;
    pvStack_170 = (void *)((uint)pvStack_170 & 0xffffff00);
    puVar10 = (undefined1 *)(**(code **)(*piVar8 + 0x10))();
    uStack_70 = *puVar10;
    uStack_6f = puVar10[1];
    uStack_6e = puVar10[2];
    uStack_6c = *(undefined4 *)(puVar10 + 4);
    uStack_68 = *(undefined4 *)(puVar10 + 8);
    uStack_64 = *(undefined4 *)(puVar10 + 0xc);
    iStack_60 = *(int *)(puVar10 + 0x10);
    uStack_5c = *(undefined4 *)(puVar10 + 0x14);
    pvStack_58 = *(void **)(puVar10 + 0x18);
    uStack_54 = *(undefined4 *)(puVar10 + 0x1c);
    uStack_38 = 0xf;
    uStack_3c = 0;
    uStack_4c = 0;
    FUN_00401660(puVar10 + 0x20,0,0xffffffff);
    puVar10 = (undefined1 *)(**(code **)(iRam00000010 + 0x10))();
    uStack_124 = *puVar10;
    uStack_123 = puVar10[1];
    uStack_122 = puVar10[2];
    uStack_120 = *(undefined4 *)(puVar10 + 4);
    iStack_11c = *(int *)(puVar10 + 8);
    uStack_118 = *(uint *)(puVar10 + 0xc);
    uStack_114 = *(uint *)(puVar10 + 0x10);
    iStack_110 = *(int *)(puVar10 + 0x14);
    pvStack_10c = *(void **)(puVar10 + 0x18);
    uStack_108 = *(undefined4 *)(puVar10 + 0x1c);
    uStack_ec = 0xf;
    uStack_f0 = 0;
    uStack_100 = 0;
    FUN_00401660(puVar10 + 0x20,0,0xffffffff);
    puVar10 = (undefined1 *)(**(code **)(*piVar12 + 0x10))();
    uStack_ac = *puVar10;
    uStack_ab = puVar10[1];
    uStack_aa = puVar10[2];
    uStack_a8 = *(undefined4 *)(puVar10 + 4);
    uStack_a4 = *(undefined4 *)(puVar10 + 8);
    uStack_a0 = *(undefined4 *)(puVar10 + 0xc);
    uStack_9c = *(undefined4 *)(puVar10 + 0x10);
    uStack_98 = *(undefined4 *)(puVar10 + 0x14);
    pvStack_94 = *(void **)(puVar10 + 0x18);
    uStack_90 = *(undefined4 *)(puVar10 + 0x1c);
    uStack_74 = 0xf;
    uStack_78 = 0;
    uStack_88 = 0;
    FUN_00401660(puVar10 + 0x20,0,0xffffffff);
    iVar5 = iStack_110 - uStack_118;
    pvStack_15c = (void *)0xf;
    pvStack_160 = (void *)0x0;
    pvStack_170 = (void *)((uint)pvStack_170 & 0xffffff00);
    FUN_00401740(s_pan_class_select2_009b4ff8,0x11);
    piVar12 = (int *)(**(code **)(*piStack_144 + 0x34))(&pvStack_174);
    if (0xf < pvStack_160) {
      _free(pvStack_174);
      return;
    }
    pvStack_160 = (void *)0xf;
    uStack_164 = 0;
    pvStack_174 = (void *)((uint)pvStack_174 & 0xffffff00);
    puVar13 = (undefined3 *)(**(code **)(*piVar12 + 0x10))();
    uStack_ec = CONCAT13(uStack_ec._3_1_,*puVar13);
    uStack_e8 = *(undefined4 *)(puVar13 + 1);
    uStack_e4 = *(undefined4 *)(puVar13 + 2);
    uStack_e0 = *(undefined4 *)(puVar13 + 3);
    uStack_dc = *(undefined4 *)(puVar13 + 4);
    iStack_d8 = *(int *)(puVar13 + 5);
    uStack_d4 = *(undefined4 *)(puVar13 + 6);
    pvStack_d0 = *(void **)(puVar13 + 7);
    uStack_b4 = 0xf;
    uStack_b8 = 0;
    uStack_c8 = 0;
    FUN_00401660(puVar13 + 8,0,0xffffffff);
    uStack_114 = iStack_60 + 0x5b;
    iStack_11c = uStack_114 - iVar5;
    uStack_e0 = uStack_9c;
    iStack_d8 = iStack_11c;
    (**(code **)(*piVar12 + 0xc))(&uStack_ec);
    (**(code **)(*piVar6 + 0xc))(&pvStack_12c);
    if (0xf < uStack_bc) {
      _free(pvStack_d0);
      return;
    }
    uStack_bc = 0xf;
    uStack_c0 = 0;
    pvStack_d0 = (void *)((uint)pvStack_d0 & 0xffffff00);
    if (0xf < uStack_80) {
      _free(pvStack_94);
      return;
    }
    uStack_80 = 0xf;
    uStack_84 = 0;
    pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
    if (0xf < uStack_f8) {
      _free(pvStack_10c);
      return;
    }
    uStack_f8 = 0xf;
    uStack_fc = 0;
    pvStack_10c = (void *)((uint)pvStack_10c & 0xffffff00);
    if (0xf < uStack_44) {
      _free(pvStack_58);
      return;
    }
  }
  return;
}


// ==== FUN_005035e0 @ 0x005035e0 ====

undefined4 FUN_005035e0(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00424500();
  if (uVar1 < 0x2060002) {
    if (uVar1 == 0x2060001) {
      FUN_005001c0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    switch(uVar1) {
    case 0x2040000:
      FUN_00501ec0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 0x2040001:
      FUN_00500af0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 0x2040016:
      FUN_00500bb0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 0x204001a:
      FUN_00500c70(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  else {
    if (uVar1 == 0x2060002) {
      FUN_00500d30(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 == 0x2060003) {
      FUN_00502c10(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 == 0x3020003) {
      FUN_00500250(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  return 0;
}


// ==== FUN_005036f0 @ 0x005036f0 ====

undefined4 FUN_005036f0(int *param_1)

{
  char cVar1;
  uint uVar2;
  int in_ECX;
  
  uVar2 = (**(code **)(*param_1 + 4))();
  if (uVar2 < 0x70005) {
    if (uVar2 != 0x70004) {
      if (uVar2 < 0x40002) {
        if (uVar2 == 0x40001) {
          FUN_00501e20(param_1);
        }
        else if (uVar2 == 0x20001) {
          cVar1 = FUN_004ff9f0(param_1);
          if (cVar1 != '\0') {
            return 1;
          }
        }
        else if ((uVar2 == 0x20002) && (cVar1 = FUN_004ffa20(param_1), cVar1 != '\0')) {
          return 1;
        }
      }
      else if ((uVar2 == 0x50011) && (cVar1 = FUN_005035e0(param_1), cVar1 != '\0')) {
        return 1;
      }
    }
  }
  else if (uVar2 < 0x30030121) {
    if (uVar2 == 0x30030120) {
      cVar1 = FUN_005011f0(param_1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
    else if (uVar2 == 0x20010022) {
      cVar1 = FUN_00501fb0(param_1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
    else if ((uVar2 == 0x30030118) && (cVar1 = FUN_005024c0(param_1), cVar1 != '\0')) {
      return 1;
    }
  }
  else if (uVar2 == 0x30030121) {
    FUN_004ffd40();
    return 1;
  }
  if ((*(int *)(in_ECX + 0x74) != 0) &&
     (cVar1 = (**(code **)(**(int **)(in_ECX + 0x74) + 4))(param_1), cVar1 == '\x01')) {
    return 1;
  }
  if ((*(int *)(in_ECX + 0x24) == 0) || (cVar1 = FUN_005084d0(param_1), cVar1 == '\0')) {
    return 0;
  }
  return 1;
}


// ==== FUN_00503810 @ 0x00503810 ====

void FUN_00503810(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x45);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x45);
  }
  return;
}


// ==== FUN_00503830 @ 0x00503830 ====

void FUN_00503830(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x45) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x45) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x45);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x45);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x45) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x45) == '\0');
    if (*(char *)((int)piVar4 + 0x45) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_00503890 @ 0x00503890 ====

void FUN_00503890(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x45) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x45) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x45);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x45);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x45);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x45);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_005038e0 @ 0x005038e0 ====

void FUN_005038e0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x1d) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x1d) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x1d);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x1d);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x1d);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x1d);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_00503930 @ 0x00503930 ====

undefined4 FUN_00503930(void)

{
  return 0x50010000;
}


// ==== FUN_00503940 @ 0x00503940 ====

undefined4 FUN_00503940(void)

{
  return 0x50000004;
}


// ==== FUN_00503950 @ 0x00503950 ====

void FUN_00503950(void *param_1)

{
  if (*(char *)((int)param_1 + 0x1d) == '\0') {
    FUN_00503950(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00503990 @ 0x00503990 ====

void * FUN_00503990(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009815b0;
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


// ==== Catch@00503a05 @ 0x00503a05 ====

void Catch_00503a05(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00503a20 @ 0x00503a20 ====

void FUN_00503a20(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009815c0;
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


// ==== Catch@00503aaa @ 0x00503aaa ====

void Catch_00503aaa(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00503ac0 @ 0x00503ac0 ====

void FUN_00503ac0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009815d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x48);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x11) = 1;
  *(undefined1 *)((int)puVar1 + 0x45) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@00503b4a @ 0x00503b4a ====

void Catch_00503b4a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00503b60 @ 0x00503b60 ====

void FUN_00503b60(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009815e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x20);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 7) = 1;
  *(undefined1 *)((int)puVar1 + 0x1d) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@00503bea @ 0x00503bea ====

void Catch_00503bea(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00503c00 @ 0x00503c00 ====

void * FUN_00503c00(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009815f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x20);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_005bb0c0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00503c75 @ 0x00503c75 ====

void Catch_00503c75(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00503c90 @ 0x00503c90 ====

void FUN_00503c90(void *param_1)

{
  if (*(char *)((int)param_1 + 0x21) == '\0') {
    FUN_00503c90(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00503cd0 @ 0x00503cd0 ====

void FUN_00503cd0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981600;
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


// ==== Catch@00503d5a @ 0x00503d5a ====

void Catch_00503d5a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00503d70 @ 0x00503d70 ====

void * FUN_00503d70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981610;
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


// ==== Catch@00503de5 @ 0x00503de5 ====

void Catch_00503de5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00503e00 @ 0x00503e00 ====

void FUN_00503e00(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_00503e00(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00503e40 @ 0x00503e40 ====

undefined4 * FUN_00503e40(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981620;
  local_10 = ExceptionList;
  local_18 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)param_1 + 0x1d) == '\0') {
    ExceptionList = &local_10;
    puVar1 = (undefined4 *)
             FUN_00503c00(local_18,param_2,local_18,param_1 + 3,*(undefined1 *)(param_1 + 7));
    if (*(char *)((int)local_18 + 0x1d) != '\0') {
      local_18 = puVar1;
    }
    local_8 = 0;
    uVar2 = FUN_00503e40(*param_1,puVar1);
    *puVar1 = uVar2;
    uVar2 = FUN_00503e40(param_1[2],puVar1);
    puVar1[2] = uVar2;
  }
  ExceptionList = local_10;
  return local_18;
}


// ==== Catch@00503ed8 @ 0x00503ed8 ====

void Catch_00503ed8(void)

{
  int unaff_EBP;
  
  FUN_00503950(*(undefined4 *)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00503ef0 @ 0x00503ef0 ====

undefined4 * FUN_00503ef0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981630;
  local_10 = ExceptionList;
  local_18 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)param_1 + 0x21) == '\0') {
    ExceptionList = &local_10;
    puVar1 = (undefined4 *)
             FUN_00503d70(local_18,param_2,local_18,param_1 + 3,*(undefined1 *)(param_1 + 8));
    if (*(char *)((int)local_18 + 0x21) != '\0') {
      local_18 = puVar1;
    }
    local_8 = 0;
    uVar2 = FUN_00503ef0(*param_1,puVar1);
    *puVar1 = uVar2;
    uVar2 = FUN_00503ef0(param_1[2],puVar1);
    puVar1[2] = uVar2;
  }
  ExceptionList = local_10;
  return local_18;
}


// ==== Catch@00503f88 @ 0x00503f88 ====

void Catch_00503f88(void)

{
  int unaff_EBP;
  
  FUN_00503c90(*(undefined4 *)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00503fa0 @ 0x00503fa0 ====

undefined4 FUN_00503fa0(void)

{
  return 0x50000001;
}


// ==== FUN_00503fb0 @ 0x00503fb0 ====

void FUN_00503fb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b532c;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00503fe0 @ 0x00503fe0 ====

void FUN_00503fe0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[9] = 1;
  in_ECX[10] = 0;
  in_ECX[0xb] = 1;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  *(undefined1 *)((int)in_ECX + 0x31) = 0;
  return;
}


// ==== FUN_00504010 @ 0x00504010 ====

void FUN_00504010(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x60)) {
    _free(*(void **)(in_ECX + 0x4c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x60) = 0xf;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined1 *)(in_ECX + 0x4c) = 0;
  if (0xf < *(uint *)(in_ECX + 0x44)) {
    _free(*(void **)(in_ECX + 0x30));
    return;
  }
  *(undefined4 *)(in_ECX + 0x44) = 0xf;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined1 *)(in_ECX + 0x30) = 0;
  if (0xf < *(uint *)(in_ECX + 0x28)) {
    _free(*(void **)(in_ECX + 0x14));
    return;
  }
  *(undefined4 *)(in_ECX + 0x28) = 0xf;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined1 *)(in_ECX + 0x14) = 0;
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00504090 @ 0x00504090 ====

void FUN_00504090(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x44)) {
    _free(*(void **)(in_ECX + 0x30));
    return;
  }
  *(undefined4 *)(in_ECX + 0x44) = 0xf;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined1 *)(in_ECX + 0x30) = 0;
  if (*(uint *)(in_ECX + 0x28) < 0x10) {
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined4 *)(in_ECX + 0x28) = 0xf;
    *(undefined1 *)(in_ECX + 0x14) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x14));
  return;
}


// ==== FUN_005040e0 @ 0x005040e0 ====

void FUN_005040e0(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  uVar7 = FUN_00503e40(*(undefined4 *)(*(int *)(param_1 + 4) + 4),iVar2);
  *(undefined4 *)(iVar2 + 4) = uVar7;
  piVar3 = *(int **)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  piVar4 = (int *)piVar3[1];
  if (*(char *)((int)piVar4 + 0x1d) != '\0') {
    *piVar3 = (int)piVar3;
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    return;
  }
  cVar1 = *(char *)(*piVar4 + 0x1d);
  piVar6 = (int *)*piVar4;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*piVar6 + 0x1d);
    piVar4 = piVar6;
    piVar6 = (int *)*piVar6;
  }
  *piVar3 = (int)piVar4;
  iVar2 = *(int *)(*(int *)(in_ECX + 4) + 4);
  iVar5 = *(int *)(iVar2 + 8);
  cVar1 = *(char *)(iVar5 + 0x1d);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(int *)(iVar5 + 8) + 0x1d);
    iVar2 = iVar5;
    iVar5 = *(int *)(iVar5 + 8);
  }
  *(int *)(*(int *)(in_ECX + 4) + 8) = iVar2;
  return;
}


// ==== FUN_00504160 @ 0x00504160 ====

void FUN_00504160(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  uVar7 = FUN_00503ef0(*(undefined4 *)(*(int *)(param_1 + 4) + 4),iVar2);
  *(undefined4 *)(iVar2 + 4) = uVar7;
  piVar3 = *(int **)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  piVar4 = (int *)piVar3[1];
  if (*(char *)((int)piVar4 + 0x21) != '\0') {
    *piVar3 = (int)piVar3;
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    return;
  }
  cVar1 = *(char *)(*piVar4 + 0x21);
  piVar6 = (int *)*piVar4;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*piVar6 + 0x21);
    piVar4 = piVar6;
    piVar6 = (int *)*piVar6;
  }
  *piVar3 = (int)piVar4;
  iVar2 = *(int *)(*(int *)(in_ECX + 4) + 4);
  iVar5 = *(int *)(iVar2 + 8);
  cVar1 = *(char *)(iVar5 + 0x21);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(int *)(iVar5 + 8) + 0x21);
    iVar2 = iVar5;
    iVar5 = *(int *)(iVar5 + 8);
  }
  *(int *)(*(int *)(in_ECX + 4) + 8) = iVar2;
  return;
}


// ==== FUN_005041e0 @ 0x005041e0 ====

void FUN_005041e0(undefined1 *param_1)

{
  undefined1 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x38) = 0xf;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  in_ECX[0x24] = 0;
  FUN_00401660(param_1 + 0x20,0,0xffffffff);
  return;
}


// ==== FUN_00504250 @ 0x00504250 ====

void FUN_00504250(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  FUN_00401660(param_1 + 2,0,0xffffffff);
  in_ECX[9] = param_1[9];
  in_ECX[10] = param_1[10];
  in_ECX[0xb] = param_1[0xb];
  *(undefined1 *)(in_ECX + 0xc) = *(undefined1 *)(param_1 + 0xc);
  *(undefined1 *)((int)in_ECX + 0x31) = *(undefined1 *)((int)param_1 + 0x31);
  return;
}


// ==== FUN_005042b0 @ 0x005042b0 ====

void FUN_005042b0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_00503990(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_005043b5:
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
      if ((char)piVar6[5] == '\0') goto LAB_005043b5;
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


// ==== FUN_00504490 @ 0x00504490 ====

void FUN_00504490(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00503950(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x1d) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x1d) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x1d);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x1d);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x1d);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x1d);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_004e1ac0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00504550 @ 0x00504550 ====

void FUN_00504550(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00504490(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00504580 @ 0x00504580 ====

void FUN_00504580(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00503c90(piVar6[1]);
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


// ==== FUN_00504640 @ 0x00504640 ====

void FUN_00504640(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  FUN_00504250(param_2);
  return;
}


// ==== FUN_00504660 @ 0x00504660 ====

void FUN_00504660(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00503e00(piVar6[1]);
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


// ==== FUN_00504720 @ 0x00504720 ====

void FUN_00504720(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = *param_4;
  FUN_00504250(param_4 + 1);
  *(undefined1 *)(in_ECX + 0x11) = param_5;
  *(undefined1 *)((int)in_ECX + 0x45) = 0;
  return;
}


// ==== FUN_00504760 @ 0x00504760 ====

void FUN_00504760(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_005042b0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_005042b0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00504820 @ 0x00504820 ====

void FUN_00504820(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00981640;
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


// ==== Catch@00504981 @ 0x00504981 ====

void Catch_00504981(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00504a70 @ 0x00504a70 ====

/* WARNING: Removing unreachable block (ram,0x00504b89) */
/* WARNING: Removing unreachable block (ram,0x00504b9a) */
/* WARNING: Removing unreachable block (ram,0x00504ba3) */
/* WARNING: Removing unreachable block (ram,0x00504ba6) */
/* WARNING: Removing unreachable block (ram,0x00504b96) */
/* WARNING: Removing unreachable block (ram,0x00504bb4) */
/* WARNING: Removing unreachable block (ram,0x00504bc1) */
/* WARNING: Removing unreachable block (ram,0x00504bcc) */
/* WARNING: Removing unreachable block (ram,0x00504bc8) */
/* WARNING: Removing unreachable block (ram,0x00504bbc) */
/* WARNING: Removing unreachable block (ram,0x00504bcf) */

void FUN_00504a70(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28 [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(char *)((int)param_2 + 0x45) != '\0') {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = 0;
    FUN_00401740(s_invalid_map_set<T>_iterator_0099cd68,0x1b);
    FUN_00801756();
    local_28[0] = &PTR_FUN_0099c980;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = 0;
    FUN_00401660(local_44,0,0xffffffff);
    local_28[0] = &PTR_FUN_0099ca80;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00a9c7c8);
  }
  FUN_00503890();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x45) == '\0') {
    if (*(char *)(param_2[2] + 0x45) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x45) == '\0') {
    piVar6[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)(in_ECX + 4) + 4) == param_2) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar6;
  }
  else if ((int *)*piVar5 == param_2) {
    *piVar5 = (int)piVar6;
  }
  else {
    piVar5[2] = (int)piVar6;
  }
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if ((int *)*puVar1 == param_2) {
    if (*(char *)((int)piVar6 + 0x45) == '\0') {
      piVar3 = (int *)FUN_00503810(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x45) == '\0') {
      uVar4 = FUN_00868460(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0x11] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x11] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x11] == '\0') {
            *(undefined1 *)(piVar5 + 0x11) = 1;
            *(undefined1 *)(piVar3 + 0x11) = 0;
            FUN_00868500(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x45) == '\0') {
            if ((*(char *)(*piVar5 + 0x44) == '\x01') && (*(char *)(piVar5[2] + 0x44) == '\x01'))
            goto LAB_00504ca4;
            if (*(char *)(piVar5[2] + 0x44) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x44) = 1;
              *(undefined1 *)(piVar5 + 0x11) = 0;
              FUN_00868550(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0x11) = (char)piVar3[0x11];
            *(undefined1 *)(piVar3 + 0x11) = 1;
            *(undefined1 *)(piVar5[2] + 0x44) = 1;
            FUN_00868500(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0x11] == '\0') {
            *(undefined1 *)(piVar5 + 0x11) = 1;
            *(undefined1 *)(piVar3 + 0x11) = 0;
            FUN_00868550(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x45) == '\0') {
            if ((*(char *)(piVar5[2] + 0x44) != '\x01') || (*(char *)(*piVar5 + 0x44) != '\x01')) {
              if (*(char *)(*piVar5 + 0x44) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x44) = 1;
                *(undefined1 *)(piVar5 + 0x11) = 0;
                FUN_00868500(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0x11) = (char)piVar3[0x11];
              *(undefined1 *)(piVar3 + 0x11) = 1;
              *(undefined1 *)(*piVar5 + 0x44) = 1;
              FUN_00868550(piVar3);
              break;
            }
LAB_00504ca4:
            *(undefined1 *)(piVar5 + 0x11) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x11) = 1;
  }
  if ((uint)param_2[0xc] < 0x10) {
    param_2[0xc] = 0xf;
    param_2[0xb] = 0;
    *(undefined1 *)(param_2 + 7) = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[7]);
  return;
}


// ==== FUN_00504d50 @ 0x00504d50 ====

void FUN_00504d50(void *param_1)

{
  if (*(char *)((int)param_1 + 0x45) != '\0') {
    return;
  }
  FUN_00504d50(*(undefined4 *)((int)param_1 + 8));
  if (*(uint *)((int)param_1 + 0x30) < 0x10) {
    *(undefined4 *)((int)param_1 + 0x30) = 0xf;
    *(undefined4 *)((int)param_1 + 0x2c) = 0;
    *(undefined1 *)((int)param_1 + 0x1c) = 0;
    _free(param_1);
    return;
  }
  _free(*(void **)((int)param_1 + 0x1c));
  return;
}


// ==== FUN_00504db0 @ 0x00504db0 ====

void * FUN_00504db0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981650;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x48);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00504720(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00504e25 @ 0x00504e25 ====

void Catch_00504e25(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00504e40 @ 0x00504e40 ====

undefined4 * FUN_00504e40(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981660;
  local_10 = ExceptionList;
  local_18 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)param_1 + 0x45) == '\0') {
    ExceptionList = &local_10;
    puVar1 = (undefined4 *)
             FUN_00504db0(local_18,param_2,local_18,param_1 + 3,*(undefined1 *)(param_1 + 0x11));
    if (*(char *)((int)local_18 + 0x45) != '\0') {
      local_18 = puVar1;
    }
    local_8 = 0;
    uVar2 = FUN_00504e40(*param_1,puVar1);
    *puVar1 = uVar2;
    uVar2 = FUN_00504e40(param_1[2],puVar1);
    puVar1[2] = uVar2;
  }
  ExceptionList = local_10;
  return local_18;
}


// ==== Catch@00504ed8 @ 0x00504ed8 ====

void Catch_00504ed8(void)

{
  int unaff_EBP;
  
  FUN_00504d50(*(undefined4 *)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00504ef0 @ 0x00504ef0 ====

void FUN_00504ef0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0x4924922 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00504db0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x44);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x44) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x11] == '\0') {
LAB_00504ff5:
        *(undefined1 *)(*piVar5 + 0x44) = 1;
        *(undefined1 *)(piVar6 + 0x11) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x44) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_00868500(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x44) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x44) = 0;
        FUN_00868550(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x11] == '\0') goto LAB_00504ff5;
      if (piVar7 == (int *)*piVar2) {
        FUN_00868550(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x44) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x44) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x45) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x44);
  } while( true );
}


// ==== FUN_005050d0 @ 0x005050d0 ====

void FUN_005050d0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00504490(local_4,**(undefined4 **)(in_ECX + 100),*(undefined4 **)(in_ECX + 100));
  _free(*(void **)(in_ECX + 100));
  return;
}


// ==== FUN_00505150 @ 0x00505150 ====

void FUN_00505150(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00503b60();
  *(int *)(in_ECX + 4) = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  iVar1 = FUN_00503b60();
  *(int *)(in_ECX + 0x10) = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(int *)(*(int *)(in_ECX + 0x10) + 4) = *(int *)(in_ECX + 0x10);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x10);
  *(int *)(*(int *)(in_ECX + 0x10) + 8) = *(int *)(in_ECX + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = 0;
  return;
}


// ==== FUN_005051b0 @ 0x005051b0 ====

void FUN_005051b0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00504490(local_4,**(undefined4 **)(in_ECX + 0x10),*(undefined4 **)(in_ECX + 0x10));
  _free(*(void **)(in_ECX + 0x10));
  return;
}


// ==== FUN_00505210 @ 0x00505210 ====

void FUN_00505210(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  if (*(int *)(in_ECX + 0x5c) == 0) {
    *(undefined4 *)(in_ECX + 0x5c) = 0;
    *(undefined4 *)(in_ECX + 0x60) = 0;
    *(undefined4 *)(in_ECX + 100) = 0;
    FUN_00504490(local_4,**(undefined4 **)(in_ECX + 0x10),*(undefined4 **)(in_ECX + 0x10));
    _free(*(void **)(in_ECX + 0x10));
    return;
  }
  FUN_00405de0(*(int *)(in_ECX + 0x5c),*(undefined4 *)(in_ECX + 0x60),in_ECX + 0x58);
  _free(*(void **)(in_ECX + 0x5c));
  return;
}


// ==== FUN_00505280 @ 0x00505280 ====

void FUN_00505280(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00503b60();
  *(int *)(in_ECX + 100) = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(int *)(*(int *)(in_ECX + 100) + 4) = *(int *)(in_ECX + 100);
  *(undefined4 *)*(undefined4 *)(in_ECX + 100) = *(undefined4 *)(in_ECX + 100);
  *(int *)(*(int *)(in_ECX + 100) + 8) = *(int *)(in_ECX + 100);
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  *(undefined4 *)(in_ECX + 0x70) = 0;
  *(undefined4 *)(in_ECX + 0x74) = 0;
  *(undefined4 *)(in_ECX + 0x78) = 0;
  *(undefined4 *)(in_ECX + 0x7c) = 0;
  *(undefined4 *)(in_ECX + 0x80) = 0;
  *(undefined4 *)(in_ECX + 0x84) = 0;
  *(undefined4 *)(in_ECX + 0x88) = 0;
  *(undefined4 *)(in_ECX + 0xa0) = 0;
  *(undefined4 *)(in_ECX + 0xa4) = 0xf;
  *(undefined1 *)(in_ECX + 0x90) = 0;
  *(undefined4 *)(in_ECX + 0xac) = 0;
  *(undefined1 *)(in_ECX + 0xb4) = 0;
  *(undefined1 *)(in_ECX + 0xb5) = 0;
  *(undefined4 *)(in_ECX + 0xa8) = 1;
  *(undefined4 *)(in_ECX + 0xb0) = 1;
  return;
}


// ==== FUN_00505310 @ 0x00505310 ====

void FUN_00505310(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  if (*(uint *)(in_ECX + 0xa4) < 0x10) {
    *(undefined4 *)(in_ECX + 0xa4) = 0xf;
    *(undefined4 *)(in_ECX + 0xa0) = 0;
    *(undefined1 *)(in_ECX + 0x90) = 0;
    FUN_00504490(local_4,**(undefined4 **)(in_ECX + 100),*(undefined4 **)(in_ECX + 100));
    _free(*(void **)(in_ECX + 100));
    return;
  }
  _free(*(void **)(in_ECX + 0x90));
  return;
}


// ==== FUN_00505380 @ 0x00505380 ====

void FUN_00505380(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5340;
  in_ECX[6] = 0;
  in_ECX[7] = 0xf;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  *(undefined2 *)(in_ECX + 0x13) = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 10000;
  return;
}


// ==== FUN_005053c0 @ 0x005053c0 ====

undefined4 FUN_005053c0(void)

{
  return 0x70030000;
}


// ==== FUN_005053d0 @ 0x005053d0 ====

void FUN_005053d0(byte param_1)

{
  void *in_ECX;
  
  FUN_005053f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005053f0 @ 0x005053f0 ====

void FUN_005053f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5340;
  if (in_ECX[0x10] != 0) {
    FUN_00405de0(in_ECX[0x10],in_ECX[0x11],in_ECX + 0xf);
    _free((void *)in_ECX[0x10]);
    return;
  }
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  if (0xf < (uint)in_ECX[0xe]) {
    _free((void *)in_ECX[9]);
    return;
  }
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[6] = 0;
    in_ECX[7] = 0xf;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_0099cf40;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00505480 @ 0x00505480 ====

int FUN_00505480(int param_1)

{
  char cVar1;
  undefined *puVar2;
  char *pcVar3;
  
  puVar2 = PTR_s_SceneCharSelect_00aea6f4;
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  pcVar3 = puVar2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(puVar2,(int)pcVar3 - (int)(puVar2 + 1));
  return param_1;
}


// ==== FUN_005054c0 @ 0x005054c0 ====

void FUN_005054c0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00504d50(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x45) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x45) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x45);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x45);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x45);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x45);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00504a70(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00505580 @ 0x00505580 ====

void FUN_00505580(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  uVar7 = FUN_00504e40(*(undefined4 *)(*(int *)(param_1 + 4) + 4),iVar2);
  *(undefined4 *)(iVar2 + 4) = uVar7;
  piVar3 = *(int **)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  piVar4 = (int *)piVar3[1];
  if (*(char *)((int)piVar4 + 0x45) != '\0') {
    *piVar3 = (int)piVar3;
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    return;
  }
  cVar1 = *(char *)(*piVar4 + 0x45);
  piVar6 = (int *)*piVar4;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*piVar6 + 0x45);
    piVar4 = piVar6;
    piVar6 = (int *)*piVar6;
  }
  *piVar3 = (int)piVar4;
  iVar2 = *(int *)(*(int *)(in_ECX + 4) + 4);
  iVar5 = *(int *)(iVar2 + 8);
  cVar1 = *(char *)(iVar5 + 0x45);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(int *)(iVar5 + 8) + 0x45);
    iVar2 = iVar5;
    iVar5 = *(int *)(iVar5 + 8);
  }
  *(int *)(*(int *)(in_ECX + 4) + 8) = iVar2;
  return;
}


// ==== FUN_00505600 @ 0x00505600 ====

void FUN_00505600(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x45) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x45) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_00504ef0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_00503830();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00504ef0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_005056c0 @ 0x005056c0 ====

void FUN_005056c0(byte param_1)

{
  void *in_ECX;
  
  FUN_00501100();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005056e0 @ 0x005056e0 ====

undefined4 * FUN_005056e0(undefined4 *param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 local_8 [8];
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_00504ef0(param_1,1,*(undefined4 *)(in_ECX + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    if (*param_3 < (uint)param_2[3]) {
      FUN_00504ef0(param_1,1,param_2,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    if (*(uint *)(piVar1[2] + 0xc) < *param_3) {
      FUN_00504ef0(param_1,0,piVar1[2],param_3);
      return param_1;
    }
  }
  else {
    uVar2 = *param_3;
    uVar3 = param_2[3];
    if (uVar2 < uVar3) {
      FUN_00503830();
      if ((uint)param_2[3] < uVar2) {
        if (*(char *)(param_2[2] + 0x45) == '\0') {
          FUN_00504ef0(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_00504ef0(param_1,0,param_2,param_3);
        return param_1;
      }
      uVar3 = param_2[3];
    }
    if (uVar3 < uVar2) {
      FUN_00503890();
      if ((param_2 == *(int **)(in_ECX + 4)) || (uVar2 < (uint)param_2[3])) {
        if (*(char *)(param_2[2] + 0x45) == '\0') {
          FUN_00504ef0(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_00504ef0(param_1,0,param_2,param_3);
        return param_1;
      }
    }
  }
  puVar4 = (undefined4 *)FUN_00505600(local_8,param_3);
  *param_1 = *puVar4;
  return param_1;
}


// ==== __break @ 0x00505845 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00505850 @ 0x00505850 ====

undefined4 * FUN_00505850(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *extraout_EAX;
  undefined4 *extraout_EAX_00;
  int in_ECX;
  undefined4 local_6c;
  undefined4 local_68;
  void *local_60;
  undefined4 local_50;
  uint local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 local_3c;
  undefined1 local_3b;
  uint local_38 [4];
  void *local_28;
  undefined4 local_18;
  uint local_14;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x45) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((uint)puVar1[3] < *param_1) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x45) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_1 < (uint)puVar3[3])) {
    local_38[0] = *param_1;
    local_6c = 0;
    local_68 = 0;
    local_4c = 0xf;
    local_50 = 0;
    local_60 = (void *)((uint)local_60 & 0xffffff00);
    local_48 = 1;
    local_44 = 0;
    local_40 = 1;
    local_3c = 0;
    local_3b = 0;
    FUN_00504250(&local_6c);
    puVar3 = (undefined4 *)FUN_005056e0(&param_1,puVar3,local_38);
    puVar3 = (undefined4 *)*puVar3;
    if (0xf < local_14) {
      _free(local_28);
      return extraout_EAX;
    }
    local_14 = 0xf;
    local_18 = 0;
    local_28 = (void *)((uint)local_28 & 0xffffff00);
    if (0xf < local_4c) {
      _free(local_60);
      return extraout_EAX_00;
    }
  }
  return puVar3 + 4;
}


// ==== FUN_00505940 @ 0x00505940 ====

void FUN_00505940(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00503ac0();
  *(int *)(in_ECX + 4) = iVar1;
  *(undefined1 *)(iVar1 + 0x45) = 1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  iVar1 = FUN_00503b60();
  *(int *)(in_ECX + 0x10) = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(int *)(*(int *)(in_ECX + 0x10) + 4) = *(int *)(in_ECX + 0x10);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x10);
  *(int *)(*(int *)(in_ECX + 0x10) + 8) = *(int *)(in_ECX + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = 0;
  return;
}


// ==== FUN_005059a0 @ 0x005059a0 ====

void FUN_005059a0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00504490(local_4,**(undefined4 **)(in_ECX + 0x10),*(undefined4 **)(in_ECX + 0x10));
  _free(*(void **)(in_ECX + 0x10));
  return;
}


// ==== FUN_00505a00 @ 0x00505a00 ====

void FUN_00505a00(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_005054c0(local_4,**(undefined4 **)(in_ECX + 0x44),*(undefined4 **)(in_ECX + 0x44));
  _free(*(void **)(in_ECX + 0x44));
  return;
}


// ==== FUN_00505a60 @ 0x00505a60 ====

void FUN_00505a60(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00503ac0();
  *(int *)(in_ECX + 4) = iVar1;
  *(undefined1 *)(iVar1 + 0x45) = 1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  iVar1 = FUN_00503b60();
  *(int *)(in_ECX + 0x10) = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(int *)(*(int *)(in_ECX + 0x10) + 4) = *(int *)(in_ECX + 0x10);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x10);
  *(int *)(*(int *)(in_ECX + 0x10) + 8) = *(int *)(in_ECX + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = 0;
  iVar1 = FUN_00503cd0();
  *(int *)(in_ECX + 0x1c) = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(int *)(*(int *)(in_ECX + 0x1c) + 4) = *(int *)(in_ECX + 0x1c);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(in_ECX + 0x1c);
  *(int *)(*(int *)(in_ECX + 0x1c) + 8) = *(int *)(in_ECX + 0x1c);
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0xf;
  *(undefined1 *)(in_ECX + 0x28) = 0;
  return;
}


// ==== FUN_00505af0 @ 0x00505af0 ====

void FUN_00505af0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  if (*(uint *)(in_ECX + 0x3c) < 0x10) {
    *(undefined4 *)(in_ECX + 0x3c) = 0xf;
    *(undefined4 *)(in_ECX + 0x38) = 0;
    *(undefined1 *)(in_ECX + 0x28) = 0;
    FUN_00504580(local_4,**(undefined4 **)(in_ECX + 0x1c),*(undefined4 **)(in_ECX + 0x1c));
    _free(*(void **)(in_ECX + 0x1c));
    return;
  }
  _free(*(void **)(in_ECX + 0x28));
  return;
}


// ==== FUN_00505ba0 @ 0x00505ba0 ====

void FUN_00505ba0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00503ac0();
  *(int *)(in_ECX + 4) = iVar1;
  *(undefined1 *)(iVar1 + 0x45) = 1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  iVar1 = FUN_00503b60();
  *(int *)(in_ECX + 0x10) = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(int *)(*(int *)(in_ECX + 0x10) + 4) = *(int *)(in_ECX + 0x10);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x10);
  *(int *)(*(int *)(in_ECX + 0x10) + 8) = *(int *)(in_ECX + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0xf;
  *(undefined1 *)(in_ECX + 0x3c) = 0;
  return;
}


// ==== FUN_00505c10 @ 0x00505c10 ====

void FUN_00505c10(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  if (0xf < *(uint *)(in_ECX + 0x50)) {
    _free(*(void **)(in_ECX + 0x3c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x50) = 0xf;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined1 *)(in_ECX + 0x3c) = 0;
  if (*(int *)(in_ECX + 0x2c) == 0) {
    *(undefined4 *)(in_ECX + 0x2c) = 0;
    *(undefined4 *)(in_ECX + 0x30) = 0;
    *(undefined4 *)(in_ECX + 0x34) = 0;
    FUN_00504490(local_4,**(undefined4 **)(in_ECX + 0x10),*(undefined4 **)(in_ECX + 0x10));
    _free(*(void **)(in_ECX + 0x10));
    return;
  }
  FUN_00405de0(*(int *)(in_ECX + 0x2c),*(undefined4 *)(in_ECX + 0x30),in_ECX + 0x28);
  _free(*(void **)(in_ECX + 0x2c));
  return;
}


// ==== FUN_00505cc0 @ 0x00505cc0 ====

void FUN_00505cc0(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = param_1;
  if (in_ECX != param_1) {
    FUN_005054c0(&param_1,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
    FUN_00505580(iVar1);
  }
  if (in_ECX + 0xc != iVar1 + 0xc) {
    FUN_00504490(&param_1,**(undefined4 **)(in_ECX + 0x10),*(undefined4 **)(in_ECX + 0x10));
    FUN_005040e0(iVar1 + 0xc);
  }
  if (in_ECX + 0x18 != iVar1 + 0x18) {
    FUN_00504580(&param_1,**(undefined4 **)(in_ECX + 0x1c),*(undefined4 **)(in_ECX + 0x1c));
    FUN_00504160(iVar1 + 0x18);
  }
  FUN_00401660(iVar1 + 0x24,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0x40) = *(undefined1 *)(iVar1 + 0x40);
  *(undefined1 *)(in_ECX + 0x41) = *(undefined1 *)(iVar1 + 0x41);
  *(undefined1 *)(in_ECX + 0x42) = *(undefined1 *)(iVar1 + 0x42);
  *(undefined1 *)(in_ECX + 0x43) = *(undefined1 *)(iVar1 + 0x43);
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(iVar1 + 0x44);
  *(undefined1 *)(in_ECX + 0x48) = *(undefined1 *)(iVar1 + 0x48);
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(iVar1 + 0x4c);
  return;
}


// ==== FUN_00505d80 @ 0x00505d80 ====

void FUN_00505d80(void)

{
  int in_ECX;
  undefined1 auStack_4 [4];
  
  FUN_00505310();
  FUN_00504010();
  FUN_00505210();
  FUN_005054c0(auStack_4,**(undefined4 **)(in_ECX + 0x2b4),*(undefined4 **)(in_ECX + 0x2b4));
  _free(*(void **)(in_ECX + 0x2b4));
  return;
}


// ==== FUN_00505f10 @ 0x00505f10 ====

void FUN_00505f10(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0xf;
  *(undefined1 *)(in_ECX + 6) = 0;
  in_ECX[4] = 0xff000000;
  *(undefined2 *)(in_ECX + 0xc) = 0xfa;
  *(undefined1 *)((int)in_ECX + 0x36) = 0;
  *(undefined1 *)((int)in_ECX + 0x35) = 0;
  *(undefined1 *)((int)in_ECX + 0x37) = 1;
  *(undefined1 *)((int)in_ECX + 0x32) = 3;
  *(undefined1 *)((int)in_ECX + 0x33) = 0;
  *(undefined1 *)(in_ECX + 0xd) = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 1;
  FUN_00505940();
  iVar1 = FUN_00503b60();
  in_ECX[0x1c] = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[0x1c] + 4) = in_ECX[0x1c];
  *(undefined4 *)in_ECX[0x1c] = in_ECX[0x1c];
  *(undefined4 *)(in_ECX[0x1c] + 8) = in_ECX[0x1c];
  in_ECX[0x1d] = 0;
  in_ECX[0x24] = 0xf;
  in_ECX[0x23] = 0;
  *(undefined1 *)(in_ECX + 0x1f) = 0;
  iVar1 = FUN_00503ac0();
  in_ECX[0x2f] = iVar1;
  *(undefined1 *)(iVar1 + 0x45) = 1;
  *(undefined4 *)(in_ECX[0x2f] + 4) = in_ECX[0x2f];
  *(undefined4 *)in_ECX[0x2f] = in_ECX[0x2f];
  *(undefined4 *)(in_ECX[0x2f] + 8) = in_ECX[0x2f];
  in_ECX[0x30] = 0;
  FUN_00505a60();
  iVar1 = FUN_00503b60();
  in_ECX[0x47] = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[0x47] + 4) = in_ECX[0x47];
  *(undefined4 *)in_ECX[0x47] = in_ECX[0x47];
  *(undefined4 *)(in_ECX[0x47] + 8) = in_ECX[0x47];
  in_ECX[0x48] = 0;
  in_ECX[0x53] = 0xf;
  in_ECX[0x52] = 0;
  *(undefined1 *)(in_ECX + 0x4e) = 0;
  in_ECX[0x5a] = 0xf;
  in_ECX[0x59] = 0;
  *(undefined1 *)(in_ECX + 0x55) = 0;
  iVar1 = FUN_00503b60();
  in_ECX[0x62] = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[0x62] + 4) = in_ECX[0x62];
  *(undefined4 *)in_ECX[0x62] = in_ECX[0x62];
  *(undefined4 *)(in_ECX[0x62] + 8) = in_ECX[0x62];
  in_ECX[99] = 0;
  iVar1 = FUN_00503b60();
  in_ECX[0x6e] = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[0x6e] + 4) = in_ECX[0x6e];
  *(undefined4 *)in_ECX[0x6e] = in_ECX[0x6e];
  *(undefined4 *)(in_ECX[0x6e] + 8) = in_ECX[0x6e];
  in_ECX[0x6f] = 0;
  iVar1 = FUN_00503b60();
  in_ECX[0x7b] = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[0x7b] + 4) = in_ECX[0x7b];
  *(undefined4 *)in_ECX[0x7b] = in_ECX[0x7b];
  *(undefined4 *)(in_ECX[0x7b] + 8) = in_ECX[0x7b];
  in_ECX[0x7c] = 0;
  FUN_00505150();
  in_ECX[0x8c] = 0;
  in_ECX[0x8d] = 0;
  in_ECX[0x8e] = 0;
  FUN_00505ba0();
  iVar1 = FUN_00503ac0();
  in_ECX[0xad] = iVar1;
  *(undefined1 *)(iVar1 + 0x45) = 1;
  *(undefined4 *)(in_ECX[0xad] + 4) = in_ECX[0xad];
  *(undefined4 *)in_ECX[0xad] = in_ECX[0xad];
  *(undefined4 *)(in_ECX[0xad] + 8) = in_ECX[0xad];
  in_ECX[0xae] = 0;
  in_ECX[0xb0] = 0;
  in_ECX[0xb1] = 0;
  in_ECX[0xb2] = 0;
  iVar1 = FUN_00503b60();
  in_ECX[0xb4] = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[0xb4] + 4) = in_ECX[0xb4];
  *(undefined4 *)in_ECX[0xb4] = in_ECX[0xb4];
  *(undefined4 *)(in_ECX[0xb4] + 8) = in_ECX[0xb4];
  in_ECX[0xb5] = 0;
  in_ECX[199] = 0;
  in_ECX[200] = 0;
  in_ECX[0xc9] = 0;
  in_ECX[0xd4] = 0;
  in_ECX[0xd5] = 0;
  in_ECX[0xd6] = 0;
  in_ECX[0xdd] = 0xf;
  in_ECX[0xdc] = 0;
  *(undefined1 *)(in_ECX + 0xd8) = 0;
  in_ECX[0xe4] = 0xf;
  in_ECX[0xe3] = 0;
  *(undefined1 *)(in_ECX + 0xdf) = 0;
  in_ECX[0xeb] = 0xf;
  in_ECX[0xea] = 0;
  *(undefined1 *)(in_ECX + 0xe6) = 0;
  FUN_00505280();
  *in_ECX = 0;
  *(undefined1 *)(in_ECX + 3) = 1;
  return;
}


// ==== FUN_00506190 @ 0x00506190 ====

void FUN_00506190(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5374;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005061b0 @ 0x005061b0 ====

void FUN_005061b0(int param_1)

{
  int *in_ECX;
  
  if (param_1 != 0) {
    (**(code **)(*in_ECX + 0x10))(100,param_1);
  }
  return;
}


// ==== FUN_005061d0 @ 0x005061d0 ====

bool FUN_005061d0(void)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = FUN_007979d0();
  if (cVar1 != '\0') {
    uVar2 = (**(code **)(*DAT_00b5ae34 + 4))();
    if (0x3b < uVar2) {
      uVar2 = (**(code **)(*DAT_00b5ae34 + 8))();
      return 499 < uVar2;
    }
  }
  return false;
}


// ==== FUN_00506200 @ 0x00506200 ====

void FUN_00506200(void)

{
  if (DAT_00b5ad4c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ad4c)(1);
  }
  return;
}


// ==== FUN_00506220 @ 0x00506220 ====

void FUN_00506220(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (**(code **)(*DAT_00b5acf4 + 4))(param_1 << 0x10 | param_2 & 0xffff);
  if (iVar3 != 0) {
    iVar1 = *(int *)(iVar3 + 0x28);
    for (iVar3 = *(int *)(iVar3 + 0x24); iVar3 != iVar1; iVar3 = iVar3 + 0x20) {
      iVar4 = (**(code **)(*DAT_00b5acf0 + 4))(iVar3 + 4);
      if ((iVar4 != 0) && (iVar2 = *(int *)(iVar4 + 0x1c), iVar2 != 0)) {
        if (*(int *)(iVar2 + 0x1c) != 0) {
          FUN_005066c0(iVar2 + 8);
        }
        if (*(int *)(*(int *)(iVar4 + 0x1c) + 0x38) != 0) {
          FUN_00506720(*(int *)(iVar4 + 0x1c) + 0x24);
        }
        if (*(int *)(*(int *)(iVar4 + 0x1c) + 0x54) != 0) {
          FUN_00506780(*(int *)(iVar4 + 0x1c) + 0x40);
        }
      }
    }
  }
  return;
}


// ==== FUN_005062c0 @ 0x005062c0 ====

void FUN_005062c0(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int in_ECX;
  int local_8 [2];
  
  iVar2 = param_1;
  iVar1 = *(int *)(in_ECX + 8);
  param_1 = FUN_00506660(param_1);
  if (param_1 != *(int *)(in_ECX + 8)) {
    cVar3 = FUN_004a0860(iVar2,param_1 + 0xc);
    if (cVar3 == '\0') {
      piVar4 = &param_1;
      goto LAB_00506305;
    }
  }
  local_8[0] = *(int *)(in_ECX + 8);
  piVar4 = local_8;
LAB_00506305:
  if (*piVar4 == iVar1) {
    iVar1 = *(int *)(in_ECX + 0x14);
    piVar4 = (int *)FUN_004a0970(&param_1,iVar2);
    if (*piVar4 == iVar1) {
      FUN_00506ab0(local_8,iVar2);
    }
  }
  return;
}


// ==== FUN_00506340 @ 0x00506340 ====

void FUN_00506340(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 auStack_2a [2];
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    iVar1 = **(int **)(in_ECX + 8);
    uVar2 = (**(code **)(*DAT_00b5a7cc + 8))(iVar1 + 0xc);
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401660(iVar1 + 0xc,0,0xffffffff);
    uStack_c = *(undefined4 *)(iVar1 + 0x28);
    uStack_8 = uVar2;
    FUN_004a1090(auStack_2a + -6,auStack_28);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
    FUN_005a4100(auStack_2a + -6,iVar1);
  }
  return;
}


// ==== FUN_005063d0 @ 0x005063d0 ====

void FUN_005063d0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 *puVar5;
  
  FUN_00506870(*(undefined4 *)(*(int *)(in_ECX + 8) + 4));
  *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 8);
  *(int *)(*(int *)(in_ECX + 8) + 8) = *(int *)(in_ECX + 8);
  puVar2 = *(undefined4 **)(in_ECX + 0x14);
  puVar3 = (undefined4 *)*puVar2;
  do {
    do {
      while( true ) {
        do {
          puVar5 = puVar3;
          if (puVar5 == puVar2) {
            FUN_004a0ba0(*(undefined4 *)(*(int *)(in_ECX + 0x14) + 4));
            *(int *)(*(int *)(in_ECX + 0x14) + 4) = *(int *)(in_ECX + 0x14);
            *(undefined4 *)(in_ECX + 0x18) = 0;
            *(undefined4 *)*(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x14);
            *(int *)(*(int *)(in_ECX + 0x14) + 8) = *(int *)(in_ECX + 0x14);
            return;
          }
          if (puVar5[0xb] != 0) {
            (**(code **)(*DAT_00b5a7cc + 0x14))(puVar5[0xb]);
          }
          puVar3 = puVar5;
        } while (*(char *)((int)puVar5 + 0x31) != '\0');
        puVar3 = (undefined4 *)puVar5[2];
        if (*(char *)((int)puVar3 + 0x31) != '\0') break;
        cVar1 = *(char *)((int)*puVar3 + 0x31);
        puVar5 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x31);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      puVar3 = (undefined4 *)puVar5[1];
    } while (*(char *)((int)puVar3 + 0x31) != '\0');
    do {
      puVar4 = puVar3;
      puVar3 = puVar4;
      if (puVar5 != (undefined4 *)puVar4[2]) break;
      puVar3 = (undefined4 *)puVar4[1];
      puVar5 = puVar4;
    } while (*(char *)((int)puVar3 + 0x31) == '\0');
  } while( true );
}


// ==== FUN_005064a0 @ 0x005064a0 ====

void FUN_005064a0(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009b5394;
  FUN_005063d0();
  DAT_00b5ad4c = 0;
  FUN_004a1190(local_4,*(undefined4 *)in_ECX[5],(undefined4 *)in_ECX[5]);
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_00506520 @ 0x00506520 ====

void FUN_00506520(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5394;
  iVar1 = FUN_005065c0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  iVar1 = FUN_00821b80();
  in_ECX[5] = iVar1;
  *(undefined1 *)(iVar1 + 0x31) = 1;
  *(undefined4 *)(in_ECX[5] + 4) = in_ECX[5];
  *(undefined4 *)in_ECX[5] = in_ECX[5];
  *(undefined4 *)(in_ECX[5] + 8) = in_ECX[5];
  in_ECX[6] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ad4c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ad4c = in_ECX;
  return;
}


// ==== FUN_005065a0 @ 0x005065a0 ====

void FUN_005065a0(void)

{
  void *pvVar1;
  
  if (DAT_00b5ad4c == 0) {
    pvVar1 = operator_new(0x1c);
    if (pvVar1 != (void *)0x0) {
      FUN_00506520();
      return;
    }
  }
  return;
}


// ==== FUN_005065c0 @ 0x005065c0 ====

void FUN_005065c0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981670;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x30);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0xb) = 1;
  *(undefined1 *)((int)puVar1 + 0x2d) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@0050664a @ 0x0050664a ====

void Catch_0050664a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00506660 @ 0x00506660 ====

undefined4 * FUN_00506660(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar4 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  cVar1 = *(char *)((int)puVar4 + 0x2d);
  puVar2 = *(undefined4 **)(in_ECX + 4);
  do {
    if (cVar1 != '\0') {
      return puVar2;
    }
    if ((int)puVar4[10] < *(int *)(param_1 + 0x1c)) {
LAB_005066a6:
      puVar5 = (undefined4 *)puVar4[2];
      puVar4 = puVar2;
    }
    else {
      if ((int)puVar4[10] <= *(int *)(param_1 + 0x1c)) {
        if (*(uint *)(param_1 + 0x18) < 0x10) {
          iVar3 = param_1 + 4;
        }
        else {
          iVar3 = *(int *)(param_1 + 4);
        }
        iVar3 = FUN_00403620(0,puVar4[8],iVar3,*(undefined4 *)(param_1 + 0x14));
        if (iVar3 < 0) goto LAB_005066a6;
      }
      puVar5 = (undefined4 *)*puVar4;
    }
    cVar1 = *(char *)((int)puVar5 + 0x2d);
    puVar2 = puVar4;
    puVar4 = puVar5;
  } while( true );
}


// ==== FUN_005066c0 @ 0x005066c0 ====

void FUN_005066c0(undefined4 param_1)

{
  int *in_ECX;
  void *local_20;
  undefined1 local_1c;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0;
  local_1c = 0;
  local_8 = 0xf;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 9;
  (**(code **)(*in_ECX + 0x18))(&local_20);
  if (local_c < 0x10) {
    return;
  }
  _free(local_20);
  return;
}


// ==== FUN_00506720 @ 0x00506720 ====

void FUN_00506720(undefined4 param_1)

{
  int *in_ECX;
  void *local_20;
  undefined1 local_1c;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0;
  local_1c = 0;
  local_8 = 0xf;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 8;
  (**(code **)(*in_ECX + 0x18))(&local_20);
  if (local_c < 0x10) {
    return;
  }
  _free(local_20);
  return;
}


// ==== FUN_00506780 @ 0x00506780 ====

void FUN_00506780(undefined4 param_1)

{
  int *in_ECX;
  void *local_20;
  undefined1 local_1c;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0;
  local_1c = 0;
  local_8 = 0xf;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 7;
  (**(code **)(*in_ECX + 0x18))(&local_20);
  if (local_c < 0x10) {
    return;
  }
  _free(local_20);
  return;
}


// ==== FUN_005067e0 @ 0x005067e0 ====

void * FUN_005067e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981680;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x30);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_004bbcf0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00506855 @ 0x00506855 ====

void Catch_00506855(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00506870 @ 0x00506870 ====

void FUN_00506870(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) != '\0') {
    return;
  }
  FUN_00506870(*(undefined4 *)((int)param_1 + 8));
  if (*(uint *)((int)param_1 + 0x24) < 0x10) {
    *(undefined4 *)((int)param_1 + 0x24) = 0xf;
    *(undefined4 *)((int)param_1 + 0x20) = 0;
    *(undefined1 *)((int)param_1 + 0x10) = 0;
    _free(param_1);
    return;
  }
  _free(*(void **)((int)param_1 + 0x10));
  return;
}


// ==== FUN_005068d0 @ 0x005068d0 ====

void FUN_005068d0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0x7fffffd < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_005067e0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x2c);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x2c) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0xb] == '\0') {
LAB_005069d5:
        *(undefined1 *)(*piVar5 + 0x2c) = 1;
        *(undefined1 *)(piVar6 + 0xb) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x2c) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_004eb7a0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x2c) = 0;
        FUN_005a3430(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0xb] == '\0') goto LAB_005069d5;
      if (piVar7 == (int *)*piVar2) {
        FUN_005a3430(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x2c) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x2c) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x2d) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x2c);
  } while( true );
}


// ==== FUN_00506ab0 @ 0x00506ab0 ====

void FUN_00506ab0(undefined4 *param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int in_ECX;
  undefined4 *puVar7;
  undefined4 local_4;
  
  iVar2 = (int)param_2;
  puVar4 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  cVar3 = *(char *)((int)puVar4 + 0x2d);
  bVar1 = true;
  local_4 = 1;
  puVar5 = *(undefined4 **)(in_ECX + 4);
  do {
    if (cVar3 != '\0') {
      param_2 = puVar5;
      if (bVar1) {
        if (puVar5 == (undefined4 *)**(int **)(in_ECX + 4)) {
          puVar4 = (undefined4 *)FUN_005068d0(&param_2,1,puVar5,iVar2);
          *param_1 = *puVar4;
          *(undefined1 *)(param_1 + 1) = 1;
          return;
        }
        FUN_0079c420();
      }
      puVar4 = param_2;
      cVar3 = FUN_004a0860(param_2 + 3,iVar2);
      if (cVar3 == '\0') {
        *param_1 = puVar4;
        *(undefined1 *)(param_1 + 1) = 0;
        return;
      }
      puVar4 = (undefined4 *)FUN_005068d0(&param_2,local_4,puVar5,iVar2);
      *param_1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    if (*(int *)(iVar2 + 0x1c) < (int)puVar4[10]) {
LAB_00506b46:
      puVar7 = (undefined4 *)*puVar4;
      bVar1 = true;
      local_4 = 1;
    }
    else {
      if (*(int *)(iVar2 + 0x1c) <= (int)puVar4[10]) {
        if ((uint)puVar4[9] < 0x10) {
          puVar5 = puVar4 + 4;
        }
        else {
          puVar5 = (undefined4 *)puVar4[4];
        }
        iVar6 = FUN_00403620(0,*(undefined4 *)(iVar2 + 0x14),puVar5,puVar4[8]);
        if (iVar6 < 0) goto LAB_00506b46;
      }
      puVar7 = (undefined4 *)puVar4[2];
      bVar1 = false;
      local_4 = 0;
    }
    cVar3 = *(char *)((int)puVar7 + 0x2d);
    puVar5 = puVar4;
    puVar4 = puVar7;
  } while( true );
}


// ==== FUN_00506c70 @ 0x00506c70 ====

void FUN_00506c70(byte param_1)

{
  void *in_ECX;
  
  FUN_005064a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00506c90 @ 0x00506c90 ====

undefined4 FUN_00506c90(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  FUN_00797a50(param_1,0,0x11);
  *param_1 = param_2;
  *(undefined1 *)((int)param_1 + 0xb) = 0;
  *(undefined1 *)((int)param_1 + 10) = param_3;
  return 1;
}


// ==== FUN_00506cc0 @ 0x00506cc0 ====

undefined4 FUN_00506cc0(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  FUN_00797a50(param_1,0,0x1c);
  *param_1 = param_2;
  *(undefined1 *)((int)param_1 + 0xb) = 4;
  *(undefined1 *)((int)param_1 + 10) = param_3;
  return 1;
}


// ==== FUN_00506cf0 @ 0x00506cf0 ====

undefined4 FUN_00506cf0(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  FUN_00797a50(param_1,0,0x15);
  *param_1 = param_2;
  *(undefined1 *)((int)param_1 + 0xb) = 7;
  *(undefined1 *)((int)param_1 + 10) = param_3;
  return 1;
}


// ==== FUN_00506d20 @ 0x00506d20 ====

undefined4 FUN_00506d20(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  FUN_00797a50(param_1,0,0x14);
  *param_1 = param_2;
  *(undefined1 *)((int)param_1 + 0xb) = 8;
  *(undefined1 *)((int)param_1 + 10) = param_3;
  return 1;
}


// ==== FUN_00506d50 @ 0x00506d50 ====

undefined4 FUN_00506d50(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  FUN_00797a50(param_1,0,0x11);
  *param_1 = param_2;
  *(undefined1 *)((int)param_1 + 0xb) = 9;
  *(undefined1 *)((int)param_1 + 10) = param_3;
  return 1;
}


// ==== FUN_00506d80 @ 0x00506d80 ====

undefined4 FUN_00506d80(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  FUN_00797a50(param_1,0,0x14);
  *param_1 = param_2;
  *(undefined1 *)((int)param_1 + 0xb) = 10;
  *(undefined1 *)((int)param_1 + 10) = param_3;
  return 1;
}


// ==== FUN_00506db0 @ 0x00506db0 ====

undefined4 FUN_00506db0(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  FUN_00797a50(param_1,0,0x11);
  *param_1 = param_2;
  *(undefined1 *)((int)param_1 + 0xb) = 0xb;
  *(undefined1 *)((int)param_1 + 10) = param_3;
  return 1;
}


// ==== FUN_00506de0 @ 0x00506de0 ====

undefined4 FUN_00506de0(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  FUN_00797a50(param_1,0,0x13);
  *param_1 = param_2;
  *(undefined1 *)((int)param_1 + 0xb) = 0xc;
  *(undefined1 *)((int)param_1 + 10) = param_3;
  return 1;
}


// ==== FUN_00506e10 @ 0x00506e10 ====

undefined4 FUN_00506e10(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  FUN_00797a50(param_1,0,0x13);
  *param_1 = param_2;
  *(undefined1 *)((int)param_1 + 0xb) = 0xd;
  *(undefined1 *)((int)param_1 + 10) = param_3;
  return 1;
}


// ==== FUN_00506e40 @ 0x00506e40 ====

undefined4 FUN_00506e40(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  FUN_00797a50(param_1,0,0x13);
  *param_1 = param_2;
  *(undefined1 *)((int)param_1 + 0xb) = 0xe;
  *(undefined1 *)((int)param_1 + 10) = param_3;
  return 1;
}


// ==== FUN_00506e70 @ 0x00506e70 ====

undefined4 FUN_00506e70(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  FUN_00797a50(param_1,0,0xd);
  *param_1 = param_2;
  *(undefined1 *)((int)param_1 + 0xb) = 0xf;
  *(undefined1 *)((int)param_1 + 10) = param_3;
  return 1;
}


// ==== FUN_00506ea0 @ 0x00506ea0 ====

void FUN_00506ea0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_004f5730(&local_c);
  *param_2 = local_c;
  param_2[1] = local_8;
  puVar1 = (undefined4 *)FUN_0040d600(&local_c,local_4);
  param_2[2] = *puVar1;
  param_2[3] = puVar1[1];
  param_2[4] = *param_1;
  *(undefined1 *)(param_2 + 5) = *(undefined1 *)((int)param_1 + 10);
  return;
}


// ==== FUN_00506f00 @ 0x00506f00 ====

void FUN_00506f00(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_004f5730(&local_c);
  *param_2 = local_c;
  param_2[1] = local_8;
  puVar1 = (undefined4 *)FUN_0040d600(&local_c,local_4);
  param_2[2] = *puVar1;
  param_2[3] = puVar1[1];
  param_2[4] = *param_1;
  *(undefined1 *)(param_2 + 5) = *(undefined1 *)((int)param_1 + 10);
  return;
}


// ==== FUN_00506f60 @ 0x00506f60 ====

void FUN_00506f60(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint local_18;
  uint local_14;
  undefined4 local_10;
  uint local_c [2];
  undefined4 local_4;
  
  FUN_004f5730(&local_18);
  *param_2 = local_18;
  param_2[1] = local_14;
  puVar1 = (uint *)FUN_0040d600(&local_18,local_10);
  param_2[2] = *puVar1;
  param_2[3] = puVar1[1];
  param_2[4] = *param_1;
  *(undefined1 *)(param_2 + 5) = *(undefined1 *)((int)param_1 + 10);
  local_18 = (uint)*(ushort *)((int)param_1 + 0xe);
  local_14 = CONCAT31(local_14._1_3_,(char)param_1[3]);
  FUN_004f5730(local_c);
  puVar1 = (uint *)FUN_0040d600(&local_18,local_4);
  param_2[6] = *puVar1;
  param_2[7] = puVar1[1];
  *(bool *)(param_2 + 8) = *(char *)((int)param_1 + 0xd) == '\x01';
  param_2[9] = local_c[0];
  return;
}


// ==== FUN_00507020 @ 0x00507020 ====

void FUN_00507020(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint local_18;
  uint local_14;
  undefined4 local_10;
  uint local_c [3];
  
  FUN_004f5730(&local_18);
  *param_2 = local_18;
  param_2[1] = local_14;
  puVar2 = (uint *)FUN_0040d600(&local_18,local_10);
  param_2[2] = *puVar2;
  param_2[3] = puVar2[1];
  param_2[4] = *param_1;
  *(undefined1 *)(param_2 + 5) = *(undefined1 *)((int)param_1 + 10);
  local_14 = local_14 & 0xffffff00;
  local_18 = (uint)(ushort)param_1[3];
  FUN_004f5730(local_c);
  param_2[6] = local_c[0];
  param_2[7] = (uint)*(byte *)((int)param_1 + 0xe);
  uVar1 = *(uint *)((int)param_1 + 0xf);
  param_2[8] = uVar1;
  param_2[9] = uVar1 - param_2[4];
  return;
}


// ==== FUN_005070c0 @ 0x005070c0 ====

void FUN_005070c0(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint local_18;
  uint local_14;
  undefined4 local_10;
  uint local_c [2];
  undefined4 local_4;
  
  FUN_004f5730(&local_18);
  *param_2 = local_18;
  param_2[1] = local_14;
  puVar2 = (uint *)FUN_0040d600(&local_18,local_10);
  param_2[2] = *puVar2;
  param_2[3] = puVar2[1];
  param_2[4] = *param_1;
  *(undefined1 *)(param_2 + 5) = *(undefined1 *)((int)param_1 + 10);
  local_18 = (uint)*(ushort *)((int)param_1 + 0xf);
  local_14 = CONCAT31(local_14._1_3_,*(undefined1 *)((int)param_1 + 0xe));
  FUN_004f5730(local_c);
  *(char *)(param_2 + 6) = (char)param_1[3];
  *(undefined1 *)((int)param_2 + 0x19) = *(undefined1 *)((int)param_1 + 0xd);
  puVar2 = (uint *)FUN_0040d600(&local_18,local_4);
  param_2[7] = *puVar2;
  param_2[8] = puVar2[1];
  param_2[9] = local_c[0];
  uVar1 = *(uint *)((int)param_1 + 0x11);
  param_2[10] = uVar1;
  param_2[0xb] = uVar1 - param_2[4];
  return;
}


// ==== FUN_00507190 @ 0x00507190 ====

void FUN_00507190(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_004f5730(&local_c);
  *param_2 = local_c;
  param_2[1] = local_8;
  puVar1 = (undefined4 *)FUN_0040d600(&local_c,local_4);
  param_2[2] = *puVar1;
  param_2[3] = puVar1[1];
  param_2[4] = *param_1;
  *(undefined1 *)(param_2 + 5) = *(undefined1 *)((int)param_1 + 10);
  param_2[6] = param_1[3];
  *(undefined1 *)(param_2 + 7) = *(undefined1 *)(param_1 + 4);
  *(undefined1 *)((int)param_2 + 0x1d) = *(undefined1 *)((int)param_1 + 0x11);
  param_2[8] = (uint)*(byte *)((int)param_1 + 0x12);
  return;
}


// ==== FUN_00507210 @ 0x00507210 ====

void FUN_00507210(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint local_18;
  uint local_14;
  undefined4 local_10;
  uint local_c [3];
  
  FUN_004f5730(&local_18);
  *param_2 = local_18;
  param_2[1] = local_14;
  puVar2 = (uint *)FUN_0040d600(&local_18,local_10);
  param_2[2] = *puVar2;
  param_2[3] = puVar2[1];
  param_2[4] = *param_1;
  *(undefined1 *)(param_2 + 5) = *(undefined1 *)((int)param_1 + 10);
  local_14 = local_14 & 0xffffff00;
  local_18 = (uint)*(ushort *)((int)param_1 + 0xd);
  FUN_004f5730(local_c);
  *(char *)(param_2 + 6) = (char)param_1[3];
  param_2[7] = local_c[0];
  uVar1 = *(uint *)((int)param_1 + 0xf);
  param_2[8] = uVar1;
  param_2[9] = uVar1 - param_2[4];
  return;
}


// ==== FUN_005072b0 @ 0x005072b0 ====

void FUN_005072b0(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_004f5730(&local_c);
  *param_2 = local_c;
  param_2[1] = local_8;
  puVar3 = (undefined4 *)FUN_0040d600(&local_c,local_4);
  param_2[2] = *puVar3;
  param_2[3] = puVar3[1];
  iVar1 = *param_1;
  param_2[4] = iVar1;
  *(undefined1 *)(param_2 + 5) = *(undefined1 *)((int)param_1 + 10);
  param_2[6] = (uint)*(byte *)(param_1 + 3);
  iVar2 = *(int *)((int)param_1 + 0xd);
  param_2[7] = iVar2;
  param_2[8] = iVar2 - iVar1;
  return;
}


// ==== FUN_005074b0 @ 0x005074b0 ====

void FUN_005074b0(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint local_18;
  uint local_14;
  undefined4 local_10;
  uint local_c [3];
  
  FUN_004f5730(&local_18);
  *param_2 = local_18;
  param_2[1] = local_14;
  puVar2 = (uint *)FUN_0040d600(&local_18,local_10);
  param_2[2] = *puVar2;
  param_2[3] = puVar2[1];
  param_2[4] = *param_1;
  *(undefined1 *)(param_2 + 5) = *(undefined1 *)((int)param_1 + 10);
  local_14 = local_14 & 0xffffff00;
  local_18 = (uint)*(ushort *)((int)param_1 + 0xd);
  FUN_004f5730(local_c);
  *(char *)(param_2 + 6) = (char)param_1[3];
  param_2[7] = local_c[0];
  uVar1 = *(uint *)((int)param_1 + 0xf);
  param_2[8] = uVar1;
  param_2[9] = uVar1 - param_2[4];
  return;
}


// ==== FUN_00507550 @ 0x00507550 ====

void FUN_00507550(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_004f5730(&local_c);
  *param_2 = local_c;
  param_2[1] = local_8;
  puVar1 = (undefined4 *)FUN_0040d600(&local_c,local_4);
  param_2[2] = *puVar1;
  param_2[3] = puVar1[1];
  param_2[4] = *param_1;
  *(undefined1 *)(param_2 + 5) = *(undefined1 *)((int)param_1 + 10);
  *(undefined1 *)(param_2 + 6) = *(undefined1 *)(param_1 + 3);
  return;
}


// ==== FUN_005077f0 @ 0x005077f0 ====

void FUN_005077f0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  float10 fVar3;
  undefined1 local_1e [6];
  undefined4 local_18 [2];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  FUN_004ef6c0(local_18,param_1[4],*(undefined1 *)(param_1 + 5));
  local_c = *param_1;
  local_8 = param_1[1];
  fVar3 = (float10)FUN_0040d5f0(param_1 + 2);
  local_4 = (float)fVar3;
  puVar2 = (undefined4 *)FUN_004ef0e0(local_1e);
  uVar1 = *puVar2;
  local_10 = CONCAT22(local_10._2_2_,*(undefined2 *)(puVar2 + 1));
  *param_2 = local_18[0];
  param_2[1] = uVar1;
  param_2[2] = local_10;
  return;
}


// ==== FUN_00507870 @ 0x00507870 ====

void FUN_00507870(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  float10 fVar3;
  undefined2 local_24 [2];
  undefined1 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_004eff90(&local_10,param_1[4],*(undefined1 *)(param_1 + 5));
  local_1c = *param_1;
  local_18 = param_1[1];
  fVar3 = (float10)FUN_0040d5f0(param_1 + 2);
  local_14 = (float)fVar3;
  puVar2 = (undefined4 *)FUN_004ef0e0(local_24);
  local_c = *puVar2;
  local_8 = CONCAT22(local_8._2_2_,*(undefined2 *)(puVar2 + 1));
  *param_2 = local_10;
  param_2[1] = local_c;
  param_2[2] = local_8;
  param_2[3] = local_4;
  local_1c = param_1[9];
  local_18 = 0;
  fVar3 = (float10)FUN_0040d5f0(param_1 + 6);
  local_14 = (float)fVar3;
  FUN_004ef0e0(local_24);
  *(undefined1 *)(param_2 + 3) = local_20;
  cVar1 = *(char *)(param_1 + 8);
  *(undefined2 *)((int)param_2 + 0xe) = local_24[0];
  *(bool *)((int)param_2 + 0xd) = cVar1 != '\0';
  return;
}


// ==== FUN_00507940 @ 0x00507940 ====

void FUN_00507940(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  float10 fVar2;
  undefined2 local_28 [4];
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined2 local_4;
  undefined1 local_2;
  
  FUN_004eef40(&local_14,param_1[4],*(undefined1 *)(param_1 + 5));
  local_20 = *param_1;
  local_1c = param_1[1];
  fVar2 = (float10)FUN_0040d5f0(param_1 + 2);
  local_18 = (float)fVar2;
  puVar1 = (undefined4 *)FUN_004ef0e0(local_28);
  local_10 = *puVar1;
  local_c = CONCAT22(local_c._2_2_,*(undefined2 *)(puVar1 + 1));
  *param_2 = local_14;
  param_2[1] = local_10;
  param_2[2] = local_c;
  param_2[3] = local_8;
  *(undefined2 *)(param_2 + 4) = local_4;
  *(undefined1 *)((int)param_2 + 0x12) = local_2;
  local_20 = param_1[6];
  local_1c = 0;
  local_18 = 0.0;
  FUN_004ef0e0(local_28);
  *(undefined2 *)(param_2 + 3) = local_28[0];
  *(undefined1 *)((int)param_2 + 0xe) = *(undefined1 *)(param_1 + 7);
  *(undefined4 *)((int)param_2 + 0xf) = param_1[8];
  return;
}


// ==== FUN_00507b00 @ 0x00507b00 ====

void FUN_00507b00(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  float10 fVar3;
  undefined1 local_26 [6];
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  undefined4 local_14 [2];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_00506d20(local_14,param_1[4],*(undefined1 *)(param_1 + 5));
  local_20 = *param_1;
  local_1c = param_1[1];
  fVar3 = (float10)FUN_0040d5f0(param_1 + 2);
  local_18 = (float)fVar3;
  puVar2 = (undefined4 *)FUN_004ef0e0(local_26);
  uVar1 = *puVar2;
  local_c = CONCAT22(local_c._2_2_,*(undefined2 *)(puVar2 + 1));
  *param_2 = local_14[0];
  param_2[1] = uVar1;
  param_2[2] = local_c;
  param_2[3] = local_8;
  param_2[4] = local_4;
  param_2[3] = param_1[6];
  *(undefined1 *)(param_2 + 4) = *(undefined1 *)(param_1 + 7);
  *(undefined1 *)((int)param_2 + 0x11) = *(undefined1 *)((int)param_1 + 0x1d);
  *(undefined1 *)((int)param_2 + 0x12) = *(undefined1 *)(param_1 + 8);
  return;
}


// ==== FUN_00507bb0 @ 0x00507bb0 ====

void FUN_00507bb0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  float10 fVar2;
  undefined2 local_28 [4];
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined2 local_4;
  undefined1 local_2;
  
  FUN_00506e40(&local_14,param_1[4],*(undefined1 *)(param_1 + 5));
  local_20 = *param_1;
  local_1c = param_1[1];
  fVar2 = (float10)FUN_0040d5f0(param_1 + 2);
  local_18 = (float)fVar2;
  puVar1 = (undefined4 *)FUN_004ef0e0(local_28);
  local_10 = *puVar1;
  local_c = CONCAT22(local_c._2_2_,*(undefined2 *)(puVar1 + 1));
  *param_2 = local_14;
  param_2[1] = local_10;
  param_2[2] = local_c;
  param_2[3] = local_8;
  *(undefined2 *)(param_2 + 4) = local_4;
  *(undefined1 *)((int)param_2 + 0x12) = local_2;
  local_20 = param_1[7];
  local_1c = 0;
  local_18 = 0.0;
  FUN_004ef0e0(local_28);
  *(undefined1 *)(param_2 + 3) = *(undefined1 *)(param_1 + 6);
  *(undefined2 *)((int)param_2 + 0xd) = local_28[0];
  *(undefined4 *)((int)param_2 + 0xf) = param_1[8];
  return;
}


// ==== FUN_00507c80 @ 0x00507c80 ====

void FUN_00507c80(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  float10 fVar3;
  undefined1 local_26 [6];
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  undefined4 local_14 [2];
  undefined4 local_c;
  undefined4 local_8;
  undefined1 local_4;
  
  FUN_00506d50(local_14,param_1[4],*(undefined1 *)(param_1 + 5));
  local_20 = *param_1;
  local_1c = param_1[1];
  fVar3 = (float10)FUN_0040d5f0(param_1 + 2);
  local_18 = (float)fVar3;
  puVar2 = (undefined4 *)FUN_004ef0e0(local_26);
  uVar1 = *puVar2;
  local_c = CONCAT22(local_c._2_2_,*(undefined2 *)(puVar2 + 1));
  *param_2 = local_14[0];
  param_2[1] = uVar1;
  param_2[2] = local_c;
  param_2[3] = local_8;
  *(undefined1 *)(param_2 + 4) = local_4;
  *(undefined1 *)(param_2 + 3) = *(undefined1 *)(param_1 + 6);
  *(undefined4 *)((int)param_2 + 0xd) = param_1[7];
  return;
}


// ==== FUN_00507d20 @ 0x00507d20 ====

void FUN_00507d20(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  float10 fVar3;
  undefined1 local_26 [6];
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  undefined4 local_14 [2];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_00506d80(local_14,param_1[4],*(undefined1 *)(param_1 + 5));
  local_20 = *param_1;
  local_1c = param_1[1];
  fVar3 = (float10)FUN_0040d5f0(param_1 + 2);
  local_18 = (float)fVar3;
  puVar2 = (undefined4 *)FUN_004ef0e0(local_26);
  uVar1 = *puVar2;
  local_c = CONCAT22(local_c._2_2_,*(undefined2 *)(puVar2 + 1));
  *param_2 = local_14[0];
  param_2[1] = uVar1;
  param_2[2] = local_c;
  param_2[3] = local_8;
  param_2[4] = local_4;
  *(undefined2 *)(param_2 + 3) = *(undefined2 *)(param_1 + 6);
  *(undefined1 *)((int)param_2 + 0xe) = *(undefined1 *)((int)param_1 + 0x1a);
  *(undefined4 *)((int)param_2 + 0xf) = param_1[7];
  *(undefined1 *)((int)param_2 + 0x13) = *(undefined1 *)((int)param_1 + 0x21);
  return;
}


// ==== FUN_00507dd0 @ 0x00507dd0 ====

void FUN_00507dd0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  float10 fVar3;
  undefined1 local_26 [6];
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  undefined4 local_14 [2];
  undefined4 local_c;
  undefined4 local_8;
  undefined1 local_4;
  
  FUN_00506db0(local_14,param_1[4],*(undefined1 *)(param_1 + 5));
  local_20 = *param_1;
  local_1c = param_1[1];
  fVar3 = (float10)FUN_0040d5f0(param_1 + 2);
  local_18 = (float)fVar3;
  puVar2 = (undefined4 *)FUN_004ef0e0(local_26);
  uVar1 = *puVar2;
  local_c = CONCAT22(local_c._2_2_,*(undefined2 *)(puVar2 + 1));
  *param_2 = local_14[0];
  param_2[1] = uVar1;
  param_2[2] = local_c;
  param_2[3] = local_8;
  *(undefined1 *)(param_2 + 4) = local_4;
  *(undefined1 *)(param_2 + 3) = *(undefined1 *)(param_1 + 6);
  *(undefined4 *)((int)param_2 + 0xd) = param_1[7];
  return;
}


// ==== FUN_00507e70 @ 0x00507e70 ====

void FUN_00507e70(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  float10 fVar2;
  undefined2 local_28 [4];
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined2 local_4;
  undefined1 local_2;
  
  FUN_00506de0(&local_14,param_1[4],*(undefined1 *)(param_1 + 5));
  local_20 = *param_1;
  local_1c = param_1[1];
  fVar2 = (float10)FUN_0040d5f0(param_1 + 2);
  local_18 = (float)fVar2;
  puVar1 = (undefined4 *)FUN_004ef0e0(local_28);
  local_10 = *puVar1;
  local_c = CONCAT22(local_c._2_2_,*(undefined2 *)(puVar1 + 1));
  *param_2 = local_14;
  param_2[1] = local_10;
  param_2[2] = local_c;
  param_2[3] = local_8;
  *(undefined2 *)(param_2 + 4) = local_4;
  *(undefined1 *)((int)param_2 + 0x12) = local_2;
  local_20 = param_1[7];
  local_1c = 0;
  local_18 = 0.0;
  FUN_004ef0e0(local_28);
  *(undefined1 *)(param_2 + 3) = *(undefined1 *)(param_1 + 6);
  *(undefined2 *)((int)param_2 + 0xd) = local_28[0];
  *(undefined4 *)((int)param_2 + 0xf) = param_1[8];
  return;
}


// ==== FUN_00507f40 @ 0x00507f40 ====

void FUN_00507f40(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  float10 fVar2;
  undefined2 local_28 [4];
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined2 local_4;
  undefined1 local_2;
  
  FUN_00506e10(&local_14,param_1[4],*(undefined1 *)(param_1 + 5));
  local_20 = *param_1;
  local_1c = param_1[1];
  fVar2 = (float10)FUN_0040d5f0(param_1 + 2);
  local_18 = (float)fVar2;
  puVar1 = (undefined4 *)FUN_004ef0e0(local_28);
  local_10 = *puVar1;
  local_c = CONCAT22(local_c._2_2_,*(undefined2 *)(puVar1 + 1));
  *param_2 = local_14;
  param_2[1] = local_10;
  param_2[2] = local_c;
  param_2[3] = local_8;
  *(undefined2 *)(param_2 + 4) = local_4;
  *(undefined1 *)((int)param_2 + 0x12) = local_2;
  local_20 = param_1[7];
  local_1c = 0;
  local_18 = 0.0;
  FUN_004ef0e0(local_28);
  *(undefined1 *)(param_2 + 3) = *(undefined1 *)(param_1 + 6);
  *(undefined2 *)((int)param_2 + 0xd) = local_28[0];
  *(undefined4 *)((int)param_2 + 0xf) = param_1[8];
  return;
}


// ==== FUN_00508010 @ 0x00508010 ====

void FUN_00508010(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  float10 fVar3;
  undefined1 local_22 [6];
  undefined4 local_1c;
  undefined4 local_18;
  float local_14;
  undefined4 local_10 [2];
  undefined4 local_8;
  undefined1 local_4;
  
  FUN_00506e70(local_10,param_1[4],0);
  local_1c = *param_1;
  local_18 = param_1[1];
  fVar3 = (float10)FUN_0040d5f0(param_1 + 2);
  local_14 = (float)fVar3;
  puVar2 = (undefined4 *)FUN_004ef0e0(local_22);
  uVar1 = *puVar2;
  local_8 = CONCAT22(local_8._2_2_,*(undefined2 *)(puVar2 + 1));
  *param_2 = local_10[0];
  param_2[1] = uVar1;
  param_2[2] = local_8;
  *(undefined1 *)(param_2 + 3) = local_4;
  *(undefined1 *)(param_2 + 3) = *(undefined1 *)(param_1 + 6);
  return;
}


// ==== FUN_005080a0 @ 0x005080a0 ====

void FUN_005080a0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  return;
}


// ==== FUN_005080b0 @ 0x005080b0 ====

undefined4 FUN_005080b0(int param_1)

{
  if ((param_1 == 2) || (param_1 == 1)) {
    return 1;
  }
  return 0;
}


// ==== FUN_005080d0 @ 0x005080d0 ====

float10 FUN_005080d0(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  
  if ((int *)*in_ECX == (int *)0x0) {
    return (float10)DAT_0099cdc8;
  }
  piVar1 = (int *)(**(code **)(*(int *)*in_ECX + 0x10))();
  iVar2 = (**(code **)(*piVar1 + 4))();
  return (float10)*(ushort *)(iVar2 + 0x2bc2);
}


// ==== FUN_00508180 @ 0x00508180 ====

void FUN_00508180(undefined4 param_1)

{
  (**(code **)(*DAT_00b5acc8 + 0x24))(param_1);
  return;
}


// ==== FUN_005081a0 @ 0x005081a0 ====

undefined1 FUN_005081a0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = (**(code **)(*DAT_00b5acc8 + 0x24))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  iVar2 = (**(code **)(*DAT_00b5acc8 + 0x28))(param_1);
  return *(undefined1 *)(iVar2 + 1);
}


// ==== FUN_005081d0 @ 0x005081d0 ====

undefined4 FUN_005081d0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = (**(code **)(*DAT_00b5acc8 + 0x24))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  iVar2 = (**(code **)(*DAT_00b5acc8 + 0x28))(param_1);
  return *(undefined4 *)(iVar2 + 4);
}


// ==== FUN_00508200 @ 0x00508200 ====

undefined4 FUN_00508200(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = (**(code **)(*DAT_00b5acc8 + 0x24))(param_1);
  if (cVar1 == '\0') {
    return 1000;
  }
  iVar2 = (**(code **)(*DAT_00b5acc8 + 0x28))(param_1);
  return *(undefined4 *)(iVar2 + 8);
}


// ==== FUN_00508230 @ 0x00508230 ====

undefined4 FUN_00508230(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = (**(code **)(*DAT_00b5acc8 + 0x24))(param_1);
  if (cVar1 == '\0') {
    return 1;
  }
  iVar2 = (**(code **)(*DAT_00b5acc8 + 0x28))(param_1);
  return *(undefined4 *)(iVar2 + 4);
}


// ==== FUN_00508260 @ 0x00508260 ====

void FUN_00508260(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *in_ECX = *param_1;
    param_1 = param_1 + 1;
    in_ECX = in_ECX + 1;
  }
  return;
}


// ==== FUN_00508280 @ 0x00508280 ====

void FUN_00508280(void)

{
  return;
}


// ==== FUN_00508290 @ 0x00508290 ====

undefined1 FUN_00508290(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x1a);
}


// ==== FUN_005082a0 @ 0x005082a0 ====

undefined1 FUN_005082a0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x18);
}


// ==== FUN_005082b0 @ 0x005082b0 ====

undefined1 FUN_005082b0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x19);
}


// ==== FUN_005082c0 @ 0x005082c0 ====

undefined1 FUN_005082c0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x24);
}


// ==== FUN_005082d0 @ 0x005082d0 ====

void FUN_005082d0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x24) = 1;
  return;
}


// ==== FUN_005082e0 @ 0x005082e0 ====

undefined4 FUN_005082e0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_005082f0 @ 0x005082f0 ====

int FUN_005082f0(void)

{
  int in_ECX;
  
  return in_ECX + 0x10;
}


// ==== FUN_00508310 @ 0x00508310 ====

undefined4 FUN_00508310(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00508320 @ 0x00508320 ====

undefined4 FUN_00508320(uint param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(int *)(in_ECX + 4) + 200;
  return CONCAT31((int3)(uVar1 >> 8),param_1 <= uVar1);
}


// ==== FUN_00508340 @ 0x00508340 ====

int FUN_00508340(void)

{
  undefined4 in_EAX;
  int in_ECX;
  
  return CONCAT31((int3)((uint)in_EAX >> 8),*(undefined1 *)(in_ECX + 0x1e)) + 1;
}


// ==== FUN_00508390 @ 0x00508390 ====

undefined4 FUN_00508390(uint param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(int *)(in_ECX + 8) - 300;
  return CONCAT31((int3)(uVar1 >> 8),uVar1 <= param_1);
}


// ==== FUN_005083b0 @ 0x005083b0 ====

void FUN_005083b0(void)

{
  undefined4 *in_ECX;
  
  *(undefined1 *)(in_ECX + 6) = 0;
  *(undefined1 *)((int)in_ECX + 0x19) = 0;
  *(undefined1 *)((int)in_ECX + 0x1a) = 0;
  in_ECX[3] = 0;
  in_ECX[2] = 0;
  *in_ECX = 0;
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  return;
}


// ==== FUN_005083d0 @ 0x005083d0 ====

bool FUN_005083d0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0xc) != -1;
}


// ==== FUN_005083e0 @ 0x005083e0 ====

void FUN_005083e0(undefined4 param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x50d0000;
  *(undefined2 *)((int)pvVar2 + 6) = 0x30;
  iVar3 = FUN_004244d0();
  uVar1 = (**(code **)(*DAT_00b5a97c + 0xc))();
  *(undefined4 *)(iVar3 + 0x10) = uVar1;
  FUN_00403e60(iVar3 + 0x14,param_1,0x19);
  FUN_004d8570(iVar3);
  return;
}


// ==== FUN_00508450 @ 0x00508450 ====

void FUN_00508450(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b2d88;
  }
  uVar2 = (**(code **)(*DAT_00b5a97c + 0xc))();
  puVar1[1] = uVar2;
  FUN_00403e60(puVar1 + 2,param_1,0x19);
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_005084a0 @ 0x005084a0 ====

void FUN_005084a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5448;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  *(undefined1 *)(in_ECX + 5) = 1;
  return;
}


// ==== FUN_005084d0 @ 0x005084d0 ====

uint FUN_005084d0(void)

{
  uint in_EAX;
  int iVar1;
  int in_ECX;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(char *)(in_ECX + 0x14) != '\0') {
    iVar1 = (**(code **)(*DAT_00b5a988 + 0xc))();
    uStack_14 = *(undefined4 *)(in_ECX + 4);
    uStack_8 = *(undefined4 *)(iVar1 + 0xc);
    uStack_4 = *(undefined4 *)(iVar1 + 0x10);
    uStack_10 = *(undefined4 *)(in_ECX + 0xc);
    uStack_c = *(undefined4 *)(in_ECX + 8);
    in_EAX = (**(code **)(*DAT_00b5a988 + 0x10))(&uStack_14);
    *(undefined1 *)(in_ECX + 0x14) = 0;
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_00508550 @ 0x00508550 ====

void FUN_00508550(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5448;
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b5478;
  }
  FUN_00797a20(puVar1);
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b548c;
  }
  FUN_00797a20(puVar1);
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009b5464;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_005085d0 @ 0x005085d0 ====

void FUN_005085d0(undefined4 param_1,undefined2 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b54a0;
    *(undefined1 *)(puVar1 + 1) = 0;
    puVar1[8] = 0xf;
    puVar1[7] = 0;
    *(undefined1 *)(puVar1 + 3) = 0;
  }
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined2 *)((int)puVar1 + 6) = param_2;
  FUN_00797a20(puVar1);
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    uRam00000004 = 1;
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009b5450;
  *(undefined1 *)(puVar1 + 1) = 1;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00508750 @ 0x00508750 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Removing unreachable block (ram,0x00508b11) */
/* WARNING: Removing unreachable block (ram,0x005089fa) */
/* WARNING: Removing unreachable block (ram,0x00508a83) */
/* WARNING: Removing unreachable block (ram,0x00508ba5) */
/* WARNING: Removing unreachable block (ram,0x00508940) */

void FUN_00508750(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  void *_Memory;
  int iVar7;
  void *unaff_EDI;
  undefined4 *puVar8;
  undefined1 auStack_107e [2];
  void *pvStack_105c;
  void *pvStack_1058;
  void *pvStack_1054;
  undefined4 uStack_1050;
  uint uStack_1048;
  uint uStack_1044;
  void *pvStack_1040;
  undefined4 uStack_103c;
  undefined4 uStack_1038;
  undefined4 uStack_1034;
  undefined4 uStack_1030;
  uint uStack_102c;
  undefined4 uStack_1028;
  undefined4 local_1024;
  undefined4 uStack_1020;
  undefined4 auStack_ffc [57];
  char acStack_f16 [256];
  char acStack_e16 [256];
  char acStack_d16 [256];
  char acStack_c16 [510];
  undefined4 uStack_a18;
  undefined4 uStack_a14;
  undefined4 uStack_a10;
  undefined4 uStack_a0c;
  undefined4 uStack_a08;
  undefined4 uStack_a04;
  undefined4 uStack_a00;
  undefined4 uStack_9f4;
  char acStack_9d4 [744];
  undefined4 uStack_6ec;
  uint uStack_6a0;
  undefined4 uStack_c;
  
  uStack_c = 0x508760;
  piVar3 = (int *)(**(code **)(*DAT_00b5ab14 + 8))();
  if (piVar3 == (int *)0x0) {
    FUN_00401740(s__s__u_009b53ec,5);
    uVar4 = FUN_00404230(&uStack_1044);
    FUN_00796d50(uVar4);
    if (0xf < uStack_102c) {
      _free(pvStack_1040);
      return;
    }
  }
  else {
    puVar5 = (undefined4 *)(**(code **)(*piVar3 + 0x10))();
    puVar8 = auStack_ffc;
    for (iVar7 = 0x3fb; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar8 = puVar8 + 1;
    }
    (**(code **)(*DAT_00b5ac58 + 0x3c))();
    (**(code **)(*DAT_00b5ac58 + 0x28))();
    (**(code **)(*DAT_00b5ac58 + 0x44))();
    pcVar6 = acStack_9d4;
    uStack_1050 = 0xf;
    pvStack_1054 = (void *)0x0;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740();
    (**(code **)(*DAT_00b5ac58 + 0xc))();
    if ((void *)0xf < pvStack_1054) {
      _free(unaff_EDI);
      return;
    }
    (**(code **)(*DAT_00b5ac58 + 0x1c))();
    FUN_00401740(s_ds_clipfar__f_009b53f4,0xd);
    FUN_00404230(&pvStack_1054);
    (**(code **)(*DAT_00b5a688 + 4))();
    if ((void *)0xf < pvStack_1040) {
      _free(pvStack_1054);
      return;
    }
    pvStack_105c = (void *)0xf;
    FUN_00401740();
    FUN_00402220(&pvStack_1058);
    (**(code **)(*DAT_00b5a688 + 4))();
    if (0xf < uStack_1044) {
      _free(pvStack_1058);
      return;
    }
    uStack_1044 = 0xf;
    uStack_1048 = 0;
    pvStack_1058 = (void *)((uint)pvStack_1058 & 0xffffff00);
    FUN_00401740(s_rc_geomipmap__d__f_009b5410,0x12);
    _Memory = (void *)FUN_00404230(&pvStack_105c);
    (**(code **)(*DAT_00b5a688 + 4))();
    if (0xf < uStack_1048) {
      _free(pvStack_105c);
      return;
    }
    pcVar6 = acStack_f16;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_f16,(int)pcVar6 - (int)(acStack_f16 + 1));
    uVar2 = uStack_1044;
    FUN_005085d0(auStack_107e + 2,param_1);
    pcVar6 = acStack_e16;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_e16,(int)pcVar6 - (int)(acStack_e16 + 1));
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = &PTR_FUN_009b54c8;
      puVar5[7] = 0xf;
      puVar5[6] = 0;
      *(undefined1 *)(puVar5 + 2) = 0;
    }
    FUN_00401660(auStack_107e + 2,0,0xffffffff);
    FUN_00797a20(puVar5);
    pcVar6 = acStack_d16;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_d16,(int)pcVar6 - (int)(acStack_d16 + 1));
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = &PTR_FUN_009b54dc;
      puVar5[7] = 0xf;
      puVar5[6] = 0;
      *(undefined1 *)(puVar5 + 2) = 0;
    }
    FUN_00401660(auStack_107e + 2,0,0xffffffff);
    FUN_00797a20(puVar5);
    pcVar6 = acStack_c16;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_c16,(int)pcVar6 - (int)(acStack_c16 + 1));
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = &PTR_FUN_009b54b4;
      puVar5[7] = 0xf;
      puVar5[6] = 0;
      *(undefined1 *)(puVar5 + 2) = 0;
    }
    FUN_00401660(auStack_107e + 2,0,0xffffffff);
    FUN_00797a20(puVar5);
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a988 + 0xc))();
    pvStack_1040 = (void *)*puVar5;
    uStack_103c = puVar5[1];
    uStack_1038 = puVar5[2];
    uStack_1034 = puVar5[3];
    uStack_1030 = uStack_9f4;
    (**(code **)(*DAT_00b5a988 + 0x10))();
    uStack_1030 = uStack_a18;
    uStack_102c = uStack_a14;
    uStack_1028 = uStack_a0c;
    local_1024 = uStack_a08;
    uStack_1020 = uStack_a10;
    (**(code **)(*DAT_00b5ae24 + 4))(&uStack_1030);
    *(undefined4 *)(uVar2 + 4) = uStack_a08;
    *(undefined4 *)(uVar2 + 8) = uStack_a04;
    *(undefined4 *)(uVar2 + 0xc) = uStack_a00;
    *(undefined4 *)(uVar2 + 0x10) = uStack_6ec;
    FUN_00401740(s_grid_visible_009b5424,0xc);
    (**(code **)(*DAT_00b5a6c8 + 0xc))(auStack_107e + -6,1);
    if (0xf < uStack_6a0) {
      _free(_Memory);
      return;
    }
  }
  return;
}


// ==== FUN_00508ce0 @ 0x00508ce0 ====

undefined4 FUN_00508ce0(void)

{
  return 0x10040014;
}


// ==== FUN_00508cf0 @ 0x00508cf0 ====

undefined4 FUN_00508cf0(void)

{
  return 0x10040018;
}


// ==== FUN_00508d00 @ 0x00508d00 ====

undefined4 FUN_00508d00(void)

{
  return 0x10040201;
}


// ==== FUN_00508d10 @ 0x00508d10 ====

undefined4 FUN_00508d10(void)

{
  return 0x10040211;
}


// ==== FUN_00508d20 @ 0x00508d20 ====

void FUN_00508d20(byte param_1)

{
  void *in_ECX;
  
  FUN_00508550();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00508d40 @ 0x00508d40 ====

undefined4 FUN_00508d40(void)

{
  return 0x10040010;
}


// ==== FUN_00508d50 @ 0x00508d50 ====

void FUN_00508d50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b54a0;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00508d80 @ 0x00508d80 ====

undefined4 FUN_00508d80(void)

{
  return 0x10040100;
}


// ==== FUN_00508d90 @ 0x00508d90 ====

void FUN_00508d90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b54b4;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00508dc0 @ 0x00508dc0 ====

undefined4 FUN_00508dc0(void)

{
  return 0x10040200;
}


// ==== FUN_00508dd0 @ 0x00508dd0 ====

void FUN_00508dd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b54c8;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00508e00 @ 0x00508e00 ====

undefined4 FUN_00508e00(void)

{
  return 0x10040210;
}


// ==== FUN_00508e10 @ 0x00508e10 ====

void FUN_00508e10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b54dc;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00508e50 @ 0x00508e50 ====

undefined4 FUN_00508e50(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00508e60 @ 0x00508e60 ====

void FUN_00508e60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b553c;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  return;
}


// ==== FUN_00508e80 @ 0x00508e80 ====

void FUN_00508e80(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 auStack_64 [24];
  char cStack_1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
  puVar4 = auStack_64;
  for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar4 = puVar4 + 1;
  }
  if (cStack_1 != '\0') {
    (**(code **)(*DAT_00b5a838 + 0xc))(1);
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x18))();
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  return;
}


// ==== FUN_00508ed0 @ 0x00508ed0 ====

void FUN_00508ed0(undefined4 param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int in_ECX;
  undefined1 auStack_1c [28];
  
  piVar1 = DAT_00b5a6ac;
  if (*(int *)(param_2 + 0xb8) == 0) {
    *(undefined4 *)(in_ECX + 4) = 1;
    (**(code **)(*DAT_00b5a838 + 0x10))();
    return;
  }
  if (*(int *)(in_ECX + 8) != 0) {
    piVar3 = (int *)(**(code **)(*DAT_00b5a838 + 4))(1);
    iVar4 = (**(code **)(*piVar1 + 0x18))();
    iVar6 = *(int *)(in_ECX + 8);
    uVar5 = (**(code **)(*piVar3 + 0xc))();
    if (uVar5 < (uint)(iVar4 - iVar6)) {
      (**(code **)(*DAT_00b5a838 + 0x10))();
      *(undefined4 *)(in_ECX + 8) = 0;
    }
  }
  iVar6 = (**(code **)(*DAT_00b5a6ac + 0x24))();
  cVar2 = FUN_004b59a0();
  while( true ) {
    if (cVar2 == '\x01') {
      if (*(int *)(in_ECX + 8) == 0) {
        FUN_00401830(s_>>_Preload_END_009b54f0);
        FUN_00796d50(auStack_1c);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      return;
    }
    iVar4 = (**(code **)(*DAT_00b5a6ac + 0x24))();
    if (0x32 < (uint)(iVar4 - iVar6)) break;
    cVar2 = FUN_004b59a0();
  }
  uVar7 = FUN_004b5520();
  FUN_0065bcd0(uVar7);
  uVar7 = FUN_004b5580();
  FUN_0065ba30(uVar7);
  return;
}


// ==== FUN_00509000 @ 0x00509000 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_00509000(int param_1)

{
  char cVar1;
  code *pcVar2;
  int *piVar3;
  undefined4 *puVar4;
  char *pcVar5;
  void *pvVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined1 local_10a0 [4];
  void *local_109c;
  undefined4 local_108c;
  uint local_1088;
  undefined1 auStack_1084 [4];
  void *pvStack_1080;
  undefined4 uStack_1070;
  uint uStack_106c;
  undefined1 auStack_1068 [4];
  void *pvStack_1064;
  undefined4 uStack_1054;
  uint uStack_1050;
  void *pvStack_1048;
  undefined4 uStack_1038;
  uint uStack_1034;
  void *pvStack_102c;
  undefined4 uStack_101c;
  uint uStack_1018;
  undefined1 auStack_1014 [4];
  void *pvStack_1010;
  undefined4 uStack_1000;
  uint uStack_ffc;
  undefined4 auStack_ff8 [64];
  char acStack_ef6 [256];
  char acStack_df6 [256];
  char acStack_cf6 [256];
  char acStack_bf6 [1074];
  char acStack_7c4 [1976];
  undefined4 uStack_c;
  
  uStack_c = 0x509010;
  piVar3 = (int *)FUN_004e9b60();
  if (piVar3 == (int *)0x0) {
    local_1088 = 0xf;
    local_108c = 0;
    local_109c = (void *)((uint)local_109c & 0xffffff00);
    FUN_00401740(s_pMap_L____NULL_009b5504,0xe);
    FUN_00406880(local_10a0);
    if (local_1088 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_109c);
    return;
  }
  piVar3 = (int *)(**(code **)(*piVar3 + 0x2c))();
  puVar4 = (undefined4 *)(**(code **)(*piVar3 + 0x10))();
  puVar9 = auStack_ff8;
  for (iVar8 = 0x3fb; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar9 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar9 = puVar9 + 1;
  }
  pcVar5 = acStack_ef6;
  uStack_ffc = 0xf;
  uStack_1000 = 0;
  pvStack_1010 = (void *)((uint)pvStack_1010 & 0xffffff00);
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(acStack_ef6,(int)pcVar5 - (int)(acStack_ef6 + 1));
  pcVar5 = acStack_df6;
  uStack_1050 = 0xf;
  uStack_1054 = 0;
  pvStack_1064 = (void *)((uint)pvStack_1064 & 0xffffff00);
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(acStack_df6,(int)pcVar5 - (int)(acStack_df6 + 1));
  pcVar5 = acStack_cf6;
  uStack_1018 = 0xf;
  uStack_101c = 0;
  pvStack_102c = (void *)((uint)pvStack_102c & 0xffffff00);
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(acStack_cf6,(int)pcVar5 - (int)(acStack_cf6 + 1));
  pcVar5 = acStack_bf6;
  uStack_1034 = 0xf;
  uStack_1038 = 0;
  pvStack_1048 = (void *)((uint)pvStack_1048 & 0xffffff00);
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(acStack_bf6,(int)pcVar5 - (int)(acStack_bf6 + 1));
  pcVar5 = acStack_7c4;
  uStack_106c = 0xf;
  uStack_1070 = 0;
  pvStack_1080 = (void *)((uint)pvStack_1080 & 0xffffff00);
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(acStack_7c4,(int)pcVar5 - (int)(acStack_7c4 + 1));
  if (*(undefined4 **)(param_1 + 0xb8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0xb8))(1);
  }
  *(undefined4 *)(param_1 + 0xb8) = 0;
  pvVar6 = operator_new(0x84);
  if (pvVar6 == (void *)0x0) {
    uVar7 = 0;
  }
  else {
    local_1088 = 0xf;
    local_108c = 0;
    local_109c = (void *)((uint)local_109c & 0xffffff00);
    FUN_00401740(s_Empty_009b5514,5);
    uVar7 = FUN_004b5800(local_10a0);
  }
  *(undefined4 *)(param_1 + 0xb8) = uVar7;
  if ((pvVar6 != (void *)0x0) && (0xf < local_1088)) {
    _free(local_109c);
    return;
  }
  local_1088 = 0xf;
  local_108c = 0;
  local_109c = (void *)((uint)local_109c & 0xffffff00);
  FUN_00401740(s_common_pre_009b551c,10);
  FUN_004b5bf0(0x15,local_10a0);
  if (0xf < local_1088) {
    _free(local_109c);
    return;
  }
  FUN_004b5bf0(1,auStack_1014);
  FUN_004b5bf0(2,auStack_1068);
  FUN_004b5bf0(0x15,auStack_1084);
  FUN_0065bb00((undefined2)auStack_ff8[0]);
  if (0xf < uStack_106c) {
    _free(pvStack_1080);
    return;
  }
  uStack_106c = 0xf;
  uStack_1070 = 0;
  pvStack_1080 = (void *)((uint)pvStack_1080 & 0xffffff00);
  if (0xf < uStack_1034) {
    _free(pvStack_1048);
    return;
  }
  uStack_1034 = 0xf;
  uStack_1038 = 0;
  pvStack_1048 = (void *)((uint)pvStack_1048 & 0xffffff00);
  if (0xf < uStack_1018) {
    _free(pvStack_102c);
    return;
  }
  uStack_1018 = 0xf;
  uStack_101c = 0;
  pvStack_102c = (void *)((uint)pvStack_102c & 0xffffff00);
  if (0xf < uStack_1050) {
    _free(pvStack_1064);
    return;
  }
  uStack_1050 = 0xf;
  uStack_1054 = 0;
  pvStack_1064 = (void *)((uint)pvStack_1064 & 0xffffff00);
  if (uStack_ffc < 0x10) {
    return;
  }
  _free(pvStack_1010);
  return;
}


// ==== FUN_00509380 @ 0x00509380 ====

uint FUN_00509380(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 auStack_60 [22];
  char cStack_5;
  
  FUN_004ea090();
  FUN_00509000(param_1);
  uVar1 = FUN_004b5580();
  FUN_0065ba30(uVar1);
  FUN_0065bcd0(0);
  (**(code **)(**(int **)(param_1 + 0xa8) + 0xc))(1);
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
  puVar4 = puVar2;
  puVar5 = auStack_60 + -2;
  for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  if (cStack_5 != '\0') {
    (**(code **)(*DAT_00b5a838 + 0xc))(1);
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6ac + 0x18))();
    *(undefined4 **)(in_ECX + 8) = puVar2;
  }
  return (uint)puVar2 & 0xffffff00;
}


// ==== FUN_00509420 @ 0x00509420 ====

uint FUN_00509420(int *param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_00508ed0(param_1,param_2);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00509460 @ 0x00509460 ====

undefined1 FUN_00509460(void)

{
  return 0;
}


// ==== FUN_00509470 @ 0x00509470 ====

undefined4 FUN_00509470(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00509480 @ 0x00509480 ====

void FUN_00509480(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5568;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_00509490 @ 0x00509490 ====

undefined4 FUN_00509490(int param_1)

{
  int in_ECX;
  
  if (*(undefined4 **)(param_1 + 0xb8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0xb8))(1);
  }
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(in_ECX + 4) = 1;
  *(undefined2 *)(param_1 + 0xb4) = 0xffff;
  return 1;
}


// ==== FUN_005094e0 @ 0x005094e0 ====

void FUN_005094e0(void)

{
  int in_ECX;
  
  FUN_004f4630();
  *(undefined4 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_00509500 @ 0x00509500 ====

undefined1 FUN_00509500(void)

{
  return 0;
}


// ==== FUN_00509510 @ 0x00509510 ====

undefined4 FUN_00509510(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00509520 @ 0x00509520 ====

void FUN_00509520(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5580;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_00509540 @ 0x00509540 ====

void FUN_00509540(void)

{
  int in_ECX;
  
  FUN_004f4640();
  *(undefined4 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_00509560 @ 0x00509560 ====

undefined1 FUN_00509560(void)

{
  return 0;
}


// ==== FUN_00509570 @ 0x00509570 ====

undefined4 FUN_00509570(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00509580 @ 0x00509580 ====

void FUN_00509580(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5598;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_005095a0 @ 0x005095a0 ====

void FUN_005095a0(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0xc);
  return;
}


// ==== FUN_005095b0 @ 0x005095b0 ====

void FUN_005095b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b562c;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  *(undefined2 *)(in_ECX + 3) = 0;
  *(undefined2 *)((int)in_ECX + 0xe) = 0;
  return;
}


// ==== FUN_00509600 @ 0x00509600 ====

undefined4 FUN_00509600(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  if (uVar1 < *(int *)(in_ECX + 4) + 1000U) {
    return 0;
  }
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00509630 @ 0x00509630 ====

uint FUN_00509630(int *param_1)

{
  uint extraout_EAX;
  void *pvVar1;
  undefined4 uVar2;
  uint uVar3;
  uint extraout_EAX_00;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if ((param_1[2] == 1) && (*param_1 == DAT_00b5ad40)) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18._1_3_ << 8);
    FUN_00401740(s_>>_LOGOUTCMD_Start_009b55cc,0x16);
    FUN_00796d50(local_1c);
    if (local_4 < 0x10) {
      pvVar1 = operator_new(0x400);
      *(undefined4 *)((int)pvVar1 + 8) = 0;
      *(undefined4 *)((int)pvVar1 + 0xc) = 0x3000002;
      *(undefined2 *)((int)pvVar1 + 6) = 0x10;
      uVar2 = FUN_004244d0();
      FUN_004d8570(uVar2);
      uVar3 = (**(code **)(*DAT_00b5a6ac + 0x18))();
      *(uint *)(in_ECX + 4) = uVar3;
      *(undefined4 *)(in_ECX + 8) = 0;
      *(undefined2 *)(in_ECX + 0xc) = 0;
      *(undefined2 *)(in_ECX + 0xe) = 0;
      return uVar3 & 0xffffff00;
    }
    _free(local_18);
    return extraout_EAX;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18._1_3_ << 8);
  FUN_00401740(s_>>_LOGOUTCMD_Start_Fail_009b55b0,0x1b);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    uVar3 = FUN_004ea450();
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    *(undefined2 *)(in_ECX + 0xe) = 1;
    return uVar3 & 0xffffff00;
  }
  _free(local_18);
  return extraout_EAX_00;
}


// ==== FUN_00509760 @ 0x00509760 ====

void FUN_00509760(int param_1,int param_2)

{
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  local_8 = 0;
  local_4 = 0xf;
  if (*(int *)(param_1 + 0x10) == 0) {
    *(undefined4 *)(in_ECX + 8) = 1;
    *(undefined2 *)(in_ECX + 0xc) = 0;
    *(undefined2 *)(in_ECX + 0xe) = 0;
    *(undefined4 *)(param_2 + 0x54) = 0;
    *(undefined4 *)(param_2 + 0x58) = 0;
    FUN_00401740(s_>>_LOGOUTCMD_End_009b5600,0x14);
    FUN_00796d50(local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
  }
  else {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    *(undefined2 *)(in_ECX + 0xe) = 0xc;
    FUN_00401740(s_>>_LOGOUTCMD_End_Fail_009b55e4,0x19);
    FUN_00796d50(local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
  }
  return;
}


// ==== FUN_00509860 @ 0x00509860 ====

undefined4 FUN_00509860(int *param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    if ((*(int *)(in_ECX + 8) == 0) && (*(int *)(in_ECX + 4) + 20000U < (uint)param_1[2])) {
      *(undefined4 *)(in_ECX + 8) = 3;
      *(undefined2 *)(in_ECX + 0xc) = 300;
      *(undefined2 *)(in_ECX + 0xe) = 1;
    }
  }
  else if (iVar1 == 0x50011) {
    iVar1 = FUN_00424500();
    if (iVar1 == 0x3000003) {
      FUN_00509760(param_1[3],param_2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_005098e0 @ 0x005098e0 ====

void FUN_005098e0(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0xc);
  return;
}


// ==== FUN_005098f0 @ 0x005098f0 ====

void FUN_005098f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5738;
  in_ECX[2] = 0;
  *(undefined2 *)(in_ECX + 3) = 0;
  *(undefined2 *)((int)in_ECX + 0xe) = 0;
  return;
}


// ==== FUN_00509940 @ 0x00509940 ====

undefined4 FUN_00509940(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  if (uVar1 < *(int *)(in_ECX + 4) + 1000U) {
    return 0;
  }
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00509970 @ 0x00509970 ====

void FUN_00509970(int param_1,int param_2)

{
  short sVar1;
  int in_ECX;
  int *piVar2;
  int *piVar3;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    *(undefined4 *)(in_ECX + 8) = 1;
    *(undefined2 *)(in_ECX + 0xc) = 0;
    *(undefined2 *)(in_ECX + 0xe) = 0;
    piVar2 = (int *)(param_2 + 0x84);
    if (*(uint *)(param_2 + 0x98) < 0x10) {
      piVar3 = piVar2;
    }
    else {
      piVar3 = (int *)*piVar2;
    }
    if (0xf < *(uint *)(param_2 + 0x98)) {
      piVar2 = (int *)*piVar2;
    }
    FUN_004bdb30(&param_1,piVar2,*(int *)(param_2 + 0x94) + (int)piVar3);
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_>>_CHECKINCMD_End_009b570c,0x15);
    FUN_00796d50(local_1c);
  }
  else {
    *(undefined4 *)(in_ECX + 8) = 2;
    sVar1 = *(short *)(param_1 + 0x10);
    *(undefined2 *)(in_ECX + 0xc) = 0x191;
    *(short *)(in_ECX + 0xe) = -sVar1;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_>>_CHECKINCMD_End___Fail___009b56ec,0x1e);
    FUN_00796d50(local_1c);
  }
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00509a60 @ 0x00509a60 ====

uint FUN_00509a60(int *param_1)

{
  uint extraout_EAX;
  undefined4 uVar1;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  uint extraout_EAX_03;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  uint extraout_EAX_04;
  int in_ECX;
  int *piVar5;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if ((param_1[2] != 1) || (*param_1 != DAT_00b5ad3c)) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18._1_3_ << 8);
    FUN_00401740(s_>>_CHECKINCMD_Fail_009b5644,0x16);
    FUN_00796d50(local_1c);
    if (local_4 < 0x10) {
      uVar4 = FUN_004ea450();
      *(undefined4 *)(in_ECX + 8) = 2;
      *(undefined2 *)(in_ECX + 0xe) = 1;
      *(undefined2 *)(in_ECX + 0xc) = 200;
      return uVar4 & 0xffffff00;
    }
    _free(local_18);
    return extraout_EAX_04;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18._1_3_ << 8);
  FUN_00401740(s_>>_CHECKINCMD_Start_009b565c,0x17);
  FUN_00796d50(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  FUN_00401740(s_SerialKey___0x_08X_009b5674,0x19);
  uVar1 = FUN_00404230(local_1c);
  FUN_00796d50(uVar1);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX_00;
  }
  FUN_00401740(s_Session_Server_ID___0x_08X_009b5690,0x21);
  uVar1 = FUN_00404230(local_1c);
  FUN_00796d50(uVar1);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX_01;
  }
  uVar1 = FUN_004022a0(local_1c,s_Character_Name_009b56b4,param_1 + 0x20);
  FUN_00796d50(uVar1);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX_02;
  }
  uVar1 = FUN_004022a0(local_1c,s_Character_NO_009b56cc,param_1 + 0x17);
  FUN_00796d50(uVar1);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX_03;
  }
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x3010002;
  *(undefined2 *)((int)pvVar2 + 6) = 0x40;
  iVar3 = FUN_004244d0();
  *(int *)(iVar3 + 0x10) = param_1[0x15];
  *(int *)(iVar3 + 0x14) = param_1[0x16];
  if ((uint)param_1[0x26] < 0x10) {
    piVar5 = param_1 + 0x21;
  }
  else {
    piVar5 = (int *)param_1[0x21];
  }
  FUN_0047aa30(iVar3 + 0x18,&DAT_009b56e4,piVar5);
  if ((uint)param_1[0x1d] < 0x10) {
    param_1 = param_1 + 0x18;
  }
  else {
    param_1 = (int *)param_1[0x18];
  }
  FUN_00509d90(iVar3 + 0x31,&DAT_009b56e8,param_1);
  FUN_004d8570(iVar3);
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  *(uint *)(in_ECX + 4) = uVar4;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined2 *)(in_ECX + 0xc) = 0;
  *(undefined2 *)(in_ECX + 0xe) = 0;
  return uVar4 & 0xffffff00;
}


// ==== FUN_00509d20 @ 0x00509d20 ====

undefined4 FUN_00509d20(int *param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    if ((*(int *)(in_ECX + 8) == 0) && (*(int *)(in_ECX + 4) + 20000U < (uint)param_1[2])) {
      *(undefined4 *)(in_ECX + 8) = 3;
      *(undefined2 *)(in_ECX + 0xc) = 300;
      *(undefined2 *)(in_ECX + 0xe) = 1;
    }
  }
  else if (iVar1 == 0x50011) {
    iVar1 = FUN_00424500();
    if (iVar1 == 0x3010003) {
      FUN_00509970(param_1[3],param_2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00509d90 @ 0x00509d90 ====

char * FUN_00509d90(char *param_1,char *param_2,char param_3)

{
  int iVar1;
  
  iVar1 = __vsnprintf(param_1,0xf,param_2,&param_3);
  if ((iVar1 < 0) || (iVar1 == 0xf)) {
    param_1[0xe] = '\0';
  }
  return param_1;
}


// ==== FUN_00509dd0 @ 0x00509dd0 ====

undefined4 FUN_00509dd0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x14);
}


// ==== FUN_00509de0 @ 0x00509de0 ====

void FUN_00509de0(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x18);
  return;
}


// ==== FUN_00509df0 @ 0x00509df0 ====

void FUN_00509df0(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *(undefined2 *)(in_ECX + 3) = param_3;
  *in_ECX = &PTR_FUN_009b57d4;
  in_ECX[2] = param_2;
  in_ECX[5] = 0;
  *(undefined2 *)(in_ECX + 6) = 0;
  *(undefined2 *)((int)in_ECX + 0x1a) = 0;
  return;
}


// ==== FUN_00509e50 @ 0x00509e50 ====

uint FUN_00509e50(int param_1)

{
  uint extraout_EAX;
  uint uVar1;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  undefined4 uVar2;
  int in_ECX;
  undefined2 extraout_var;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (((*(int *)(param_1 + 8) == *(int *)(in_ECX + 4)) &&
      (*(int *)(param_1 + 0xc) == *(int *)(in_ECX + 8))) &&
     (*(short *)(param_1 + 0x10) == *(short *)(in_ECX + 0xc))) {
    FUN_00401830(s_>>_CONNECTCMD_Start_Fail_009b5750);
    FUN_00796d50(local_1c);
    if (local_4 < 0x10) {
      uVar1 = FUN_004ea450();
      *(undefined4 *)(in_ECX + 0x14) = 1;
      *(undefined2 *)(in_ECX + 0x18) = 0;
      *(undefined2 *)(in_ECX + 0x1a) = 0;
      return uVar1 & 0xffffff00;
    }
    _free(local_18);
    return extraout_EAX;
  }
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  local_8 = 0;
  local_4 = 0xf;
  if (*(int *)(param_1 + 8) == 0) {
    FUN_00401740(s_>>_CONNECTCMD_Start_009b5790,0x17);
    FUN_00796d50(local_1c);
    if (local_4 < 0x10) {
      uVar2 = (**(code **)(*DAT_00b5a6ac + 0x18))();
      *(undefined4 *)(in_ECX + 0x10) = uVar2;
      *(undefined4 *)(in_ECX + 0x14) = 0;
      *(undefined2 *)(in_ECX + 0x18) = 0;
      *(undefined2 *)(in_ECX + 0x1a) = 0;
      uVar1 = FUN_004d84d0(*(undefined4 *)(in_ECX + 8),
                           CONCAT22(extraout_var,*(undefined2 *)(in_ECX + 0xc)));
      return uVar1 & 0xffffff00;
    }
    _free(local_18);
    return extraout_EAX_01;
  }
  FUN_00401740(s_>>_CONNECTCMD_Start_Fail_009b5770,0x1c);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    FUN_004ea450();
    *(undefined4 *)(in_ECX + 0x14) = 2;
    *(undefined2 *)(in_ECX + 0x1a) = 2;
    *(undefined2 *)(in_ECX + 0x18) = 200;
    return 0;
  }
  _free(local_18);
  return extraout_EAX_00;
}


// ==== FUN_00509fa0 @ 0x00509fa0 ====

void FUN_00509fa0(int param_1,int param_2)

{
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(param_1 + 4) != 0) {
    *(undefined4 *)(in_ECX + 0x14) = 2;
    *(undefined2 *)(in_ECX + 0x18) = 200;
    *(undefined2 *)(in_ECX + 0x1a) = 2;
    *(undefined4 *)(param_2 + 8) = 0;
    return;
  }
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  local_4 = 0xf;
  FUN_00401740(s_>>_CONNECTCMD_End_009b57a8,0x15);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    *(undefined4 *)(in_ECX + 0x14) = 1;
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 4);
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(in_ECX + 8);
    *(undefined2 *)(param_2 + 0x10) = *(undefined2 *)(in_ECX + 0xc);
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0050a040 @ 0x0050a040 ====

undefined4 FUN_0050a040(int *param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    if ((*(int *)(in_ECX + 0x14) == 0) && (*(int *)(in_ECX + 0x10) + 20000U < (uint)param_1[2])) {
      *(undefined4 *)(in_ECX + 0x14) = 3;
      *(undefined2 *)(in_ECX + 0x18) = 300;
      *(undefined2 *)(in_ECX + 0x1a) = 1;
    }
  }
  else if (iVar1 == -0x7fffffff) {
    FUN_00509fa0(param_1,param_2);
    return 1;
  }
  return 0;
}


// ==== FUN_0050a0b0 @ 0x0050a0b0 ====

void FUN_0050a0b0(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0xc);
  return;
}


// ==== FUN_0050a0c0 @ 0x0050a0c0 ====

void FUN_0050a0c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5864;
  in_ECX[2] = 0;
  *(undefined2 *)(in_ECX + 3) = 0;
  *(undefined2 *)((int)in_ECX + 0xe) = 0;
  return;
}


// ==== FUN_0050a110 @ 0x0050a110 ====

undefined4 FUN_0050a110(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  if (uVar1 < *(int *)(in_ECX + 4) + 1000U) {
    return 0;
  }
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_0050a140 @ 0x0050a140 ====

uint FUN_0050a140(int *param_1)

{
  uint extraout_EAX;
  undefined4 uVar1;
  uint extraout_EAX_00;
  void *pvVar2;
  uint uVar3;
  uint extraout_EAX_01;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if ((param_1[2] != 2) || (*param_1 != DAT_00b5ad38)) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18._1_3_ << 8);
    FUN_00401740(s_>>_UNLOCKCMD_Start_Fail_009b57ec,0x1b);
    FUN_00796d50(local_1c);
    if (local_4 < 0x10) {
      uVar3 = FUN_004ea450();
      *(undefined4 *)(in_ECX + 8) = 2;
      *(undefined2 *)(in_ECX + 0xc) = 200;
      *(undefined2 *)(in_ECX + 0xe) = 1;
      return uVar3 & 0xffffff00;
    }
    _free(local_18);
    return extraout_EAX_01;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18._1_3_ << 8);
  FUN_00401740(s_>>_UNLOCKCMD_Start_009b5808,0x16);
  FUN_00796d50(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  FUN_00401740(s_SerialKey___0x_08X_009b5820,0x16);
  uVar1 = FUN_00404230(local_1c);
  FUN_00796d50(uVar1);
  if (local_4 < 0x10) {
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = 0;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x4000006;
    *(undefined2 *)((int)pvVar2 + 6) = 0x10;
    uVar1 = FUN_004244d0();
    FUN_004d8570(uVar1);
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    *(uint *)(in_ECX + 4) = uVar3;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined2 *)(in_ECX + 0xc) = 0;
    *(undefined2 *)(in_ECX + 0xe) = 0;
    return uVar3 & 0xffffff00;
  }
  _free(local_18);
  return extraout_EAX_00;
}


// ==== FUN_0050a2b0 @ 0x0050a2b0 ====

void FUN_0050a2b0(void)

{
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_>>_UNLOCKCMD_End_009b5838,0x14);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    *(undefined4 *)(in_ECX + 8) = 1;
    *(undefined2 *)(in_ECX + 0xc) = 0;
    *(undefined2 *)(in_ECX + 0xe) = 0;
    FUN_004f4f30();
    FUN_004ea310();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0050a360 @ 0x0050a360 ====

undefined4 FUN_0050a360(int *param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    if ((*(int *)(in_ECX + 8) == 0) && (*(int *)(in_ECX + 4) + 20000U < (uint)param_1[2])) {
      *(undefined4 *)(in_ECX + 8) = 3;
      *(undefined2 *)(in_ECX + 0xc) = 300;
      *(undefined2 *)(in_ECX + 0xe) = 1;
    }
  }
  else if (iVar1 == 0x50011) {
    iVar1 = FUN_00424500();
    if (iVar1 == 0x4000007) {
      FUN_0050a2b0(param_1[3],param_2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0050a3e0 @ 0x0050a3e0 ====

void FUN_0050a3e0(void)

{
  int in_ECX;
  
  FUN_004e9b00();
  *(undefined4 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_0050a400 @ 0x0050a400 ====

undefined1 FUN_0050a400(void)

{
  return 0;
}


// ==== FUN_0050a410 @ 0x0050a410 ====

undefined4 FUN_0050a410(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0050a420 @ 0x0050a420 ====

void FUN_0050a420(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5890;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_0050a440 @ 0x0050a440 ====

undefined1 FUN_0050a440(void)

{
  return 0;
}


// ==== FUN_0050a450 @ 0x0050a450 ====

undefined4 FUN_0050a450(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0050a460 @ 0x0050a460 ====

void FUN_0050a460(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b58a8;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_0050a470 @ 0x0050a470 ====

void FUN_0050a470(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5ac30 + 0x14))();
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5ac30 + 0xc))();
    (**(code **)(*DAT_00b5ace4 + 4))();
  }
  *(undefined4 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_0050a4b0 @ 0x0050a4b0 ====

undefined4 FUN_0050a4b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0050a4d0 @ 0x0050a4d0 ====

void FUN_0050a4d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b58f8;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  return;
}


// ==== FUN_0050a4f0 @ 0x0050a4f0 ====

void FUN_0050a4f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b58f8;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_009b358c;
  return;
}


// ==== FUN_0050a520 @ 0x0050a520 ====

void FUN_0050a520(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 1;
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x9020000;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar3 = FUN_004244d0();
  FUN_004d8570(uVar3);
  (**(code **)(*DAT_00b5ae3c + 0x8c))();
  (**(code **)(*DAT_00b5ae3c + 8))();
  iVar1 = *DAT_00b5a9e4;
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(iVar1 + 8))(uVar3);
  return;
}


// ==== FUN_0050a5a0 @ 0x0050a5a0 ====

uint FUN_0050a5a0(int param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_cancel_wait_009b58d8,0xb);
  if (uVar1 == 0) {
    *(undefined4 *)(in_ECX + 4) = 2;
    return 1;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0050a5e0 @ 0x0050a5e0 ====

/* WARNING: Removing unreachable block (ram,0x0050a6bc) */

void FUN_0050a5e0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined1 auStack_54 [12];
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  
  uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_44 = 0x50a61e;
  FUN_00401660();
  (**(code **)(**(int **)(in_ECX + 8) + 0xc))();
  piVar1 = *(int **)(in_ECX + 8);
  if (piVar1[1] != 0) {
    iVar2 = (**(code **)(*piVar1 + 0x14))();
    if ((iVar2 == 10) || (iVar2 = (**(code **)(*piVar1 + 0x14))(), iVar2 == 0x7b)) {
      uStack_40 = 0x20c;
      uStack_44 = 0x14d;
      uStack_48 = 0x50a671;
      (**(code **)(*(int *)piVar1[1] + 0x54))();
    }
    else {
      uStack_40 = 0x20c;
      uStack_44 = 0x14d;
      uStack_48 = 0x50a661;
      (**(code **)(*(int *)piVar1[1] + 0x54))();
    }
  }
  FUN_00401660(auStack_54 + 0x2c,0,0xffffffff);
  FUN_00404230(auStack_54);
  FUN_0065dbe0();
  return;
}


// ==== FUN_0050a6e0 @ 0x0050a6e0 ====

uint FUN_0050a6e0(void)

{
  uint extraout_EAX;
  void *pvVar1;
  int *piVar2;
  uint uVar3;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_>>_WAITENTER_Start_009b58c0,0x16);
  FUN_00796d50(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  *(undefined4 *)(in_ECX + 4) = 0;
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0065dcf0();
  }
  *(int **)(in_ECX + 8) = piVar2;
  uVar3 = (**(code **)(*piVar2 + 0xc))(0);
  return uVar3 & 0xffffff00;
}


// ==== FUN_0050a770 @ 0x0050a770 ====

undefined4 FUN_0050a770(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x4000008) {
    FUN_0050a5e0(*(undefined4 *)(param_1 + 0xc),param_2);
    return 1;
  }
  if (iVar1 == 0x50d0007) {
    FUN_0050a520(*(undefined4 *)(param_1 + 0xc),param_2);
    return 1;
  }
  return 0;
}


// ==== FUN_0050a7d0 @ 0x0050a7d0 ====

undefined4 FUN_0050a7d0(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_0050a770(param_1,param_2);
    if (cVar1 == '\x01') {
      return 1;
    }
  }
  else if (iVar2 == 0x70004) {
    iVar2 = FUN_00403620(0,param_1[7],s_cancel_wait_009b58d8,0xb);
    if (iVar2 == 0) {
      *(undefined4 *)(in_ECX + 4) = 2;
      return 1;
    }
  }
  else if (iVar2 == 0x70250001) {
    *(undefined4 *)(in_ECX + 4) = 2;
    return 1;
  }
  return 0;
}


// ==== FUN_0050a850 @ 0x0050a850 ====

void FUN_0050a850(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  
  if (in_ECX[1] == 0) {
    return;
  }
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  if ((iVar1 == 10) || (iVar1 = (**(code **)(*in_ECX + 0x14))(), iVar1 == 0x7b)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  (**(code **)(*(int *)in_ECX[1] + 0x54))(param_1,param_2,uVar2);
  return;
}


// ==== FUN_0050a890 @ 0x0050a890 ====

void FUN_0050a890(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b58f8;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_009b358c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0050a8e0 @ 0x0050a8e0 ====

void FUN_0050a8e0(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0xc);
  return;
}


// ==== FUN_0050a900 @ 0x0050a900 ====

void FUN_0050a900(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b59dc;
  in_ECX[2] = 0;
  *(undefined2 *)(in_ECX + 3) = 0;
  *(undefined2 *)((int)in_ECX + 0xe) = 0;
  return;
}


// ==== FUN_0050a950 @ 0x0050a950 ====

void FUN_0050a950(int param_1,int param_2)

{
  int in_ECX;
  
  if (*(int **)(param_2 + 0xbc) == (int *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    return;
  }
  (**(code **)(**(int **)(param_2 + 0xbc) + 0x6c))(param_1 + 0x18);
  return;
}


// ==== FUN_0050a990 @ 0x0050a990 ====

void FUN_0050a990(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(param_2 + 0xbc);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    return;
  }
  uVar3 = FUN_00424520();
  local_4 = param_1 + 0x18;
  local_8 = (uVar3 & 0xffff) - 0x18;
  cVar2 = (**(code **)(*piVar1 + 0x20))(&local_8);
  if (cVar2 == '\0') {
    FUN_004ea310();
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 5;
    *(undefined2 *)(in_ECX + 0xc) = 200;
  }
  return;
}


// ==== FUN_0050aa20 @ 0x0050aa20 ====

void FUN_0050aa20(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(param_2 + 0xbc);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    return;
  }
  uVar3 = FUN_00424520();
  local_4 = param_1 + 0x18;
  local_8 = (uVar3 & 0xffff) - 0x18;
  cVar2 = (**(code **)(*piVar1 + 0x2c))(&local_8);
  if (cVar2 == '\0') {
    FUN_004ea310();
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 6;
    *(undefined2 *)(in_ECX + 0xc) = 200;
  }
  return;
}


// ==== FUN_0050aab0 @ 0x0050aab0 ====

void FUN_0050aab0(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(param_2 + 0xbc);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    return;
  }
  uVar3 = FUN_00424520();
  local_4 = param_1 + 0x18;
  local_8 = (uVar3 & 0xffff) - 0x18;
  cVar2 = (**(code **)(*piVar1 + 0x38))(&local_8);
  if (cVar2 == '\0') {
    FUN_004ea310();
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 7;
    *(undefined2 *)(in_ECX + 0xc) = 200;
  }
  return;
}


// ==== FUN_0050ab40 @ 0x0050ab40 ====

void FUN_0050ab40(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(param_2 + 0xbc);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    return;
  }
  uVar3 = FUN_00424520();
  local_4 = param_1 + 0x18;
  local_8 = (uVar3 & 0xffff) - 0x18;
  cVar2 = (**(code **)(*piVar1 + 0x44))(&local_8);
  if (cVar2 == '\0') {
    FUN_004ea310();
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 0xd;
    *(undefined2 *)(in_ECX + 0xc) = 200;
  }
  return;
}


// ==== FUN_0050abd0 @ 0x0050abd0 ====

void FUN_0050abd0(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(param_2 + 0xbc);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    return;
  }
  uVar3 = FUN_00424520();
  local_4 = param_1 + 0x18;
  local_8 = (uVar3 & 0xffff) - 0x18;
  cVar2 = (**(code **)(*piVar1 + 0x50))(&local_8);
  if (cVar2 == '\0') {
    FUN_004ea310();
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 8;
    *(undefined2 *)(in_ECX + 0xc) = 200;
  }
  return;
}


// ==== FUN_0050ac60 @ 0x0050ac60 ====

void FUN_0050ac60(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(param_2 + 0xbc);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    return;
  }
  uVar3 = FUN_00424520();
  local_4 = param_1 + 0x18;
  local_8 = (uVar3 & 0xffff) - 0x18;
  cVar2 = (**(code **)(*piVar1 + 0x54))(&local_8);
  if (cVar2 == '\0') {
    FUN_004ea310();
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 9;
    *(undefined2 *)(in_ECX + 0xc) = 200;
  }
  return;
}


// ==== FUN_0050acf0 @ 0x0050acf0 ====

void FUN_0050acf0(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(param_2 + 0xbc);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    return;
  }
  uVar3 = FUN_00424520();
  local_4 = param_1 + 0x18;
  local_8 = (uVar3 & 0xffff) - 0x18;
  cVar2 = (**(code **)(*piVar1 + 0x58))(&local_8);
  if (cVar2 == '\0') {
    FUN_004ea310();
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 10;
    *(undefined2 *)(in_ECX + 0xc) = 200;
  }
  return;
}


// ==== FUN_0050ad80 @ 0x0050ad80 ====

void FUN_0050ad80(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(param_2 + 0xbc);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    return;
  }
  uVar3 = FUN_00424520();
  local_4 = param_1 + 0x18;
  local_8 = (uVar3 & 0xffff) - 0x18;
  cVar2 = (**(code **)(*piVar1 + 0x5c))(&local_8);
  if (cVar2 == '\0') {
    FUN_004ea310();
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 10;
    *(undefined2 *)(in_ECX + 0xc) = 200;
  }
  return;
}


// ==== FUN_0050ae10 @ 0x0050ae10 ====

void FUN_0050ae10(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(param_2 + 0xbc);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    return;
  }
  uVar3 = FUN_00424520();
  local_4 = param_1 + 0x18;
  local_8 = (uVar3 & 0xffff) - 0x18;
  cVar2 = (**(code **)(*piVar1 + 0x60))(&local_8);
  if (cVar2 == '\0') {
    FUN_004ea310();
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 10;
    *(undefined2 *)(in_ECX + 0xc) = 200;
  }
  return;
}


// ==== FUN_0050aea0 @ 0x0050aea0 ====

void FUN_0050aea0(int param_1,int param_2)

{
  undefined2 extraout_var;
  int in_ECX;
  
  if (*(int **)(param_2 + 0xbc) == (int *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    return;
  }
  (**(code **)(**(int **)(param_2 + 0xbc) + 100))
            (*(undefined2 *)(param_1 + 0x18),*(undefined2 *)(param_1 + 0x1a));
  (**(code **)(*DAT_00b5ae4c + 8))
            (CONCAT22(extraout_var,*(undefined2 *)(param_1 + 0x18)),
             CONCAT22(extraout_var,*(undefined2 *)(param_1 + 0x1a)));
  return;
}


// ==== FUN_0050af00 @ 0x0050af00 ====

void FUN_0050af00(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(param_2 + 0xbc);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    return;
  }
  uVar3 = FUN_00424520();
  local_4 = param_1 + 0x18;
  local_8 = (uVar3 & 0xffff) - 0x18;
  cVar2 = (**(code **)(*piVar1 + 0x24))(&local_8);
  if (cVar2 == '\0') {
    FUN_004ea310();
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 6;
    *(undefined2 *)(in_ECX + 0xc) = 200;
  }
  return;
}


// ==== FUN_0050af90 @ 0x0050af90 ====

void FUN_0050af90(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(param_2 + 0xbc);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    return;
  }
  uVar3 = FUN_00424520();
  local_4 = param_1 + 0x18;
  local_8 = (uVar3 & 0xffff) - 0x18;
  cVar2 = (**(code **)(*piVar1 + 0x30))(&local_8);
  if (cVar2 == '\0') {
    FUN_004ea310();
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 6;
    *(undefined2 *)(in_ECX + 0xc) = 200;
  }
  return;
}


// ==== FUN_0050b020 @ 0x0050b020 ====

void FUN_0050b020(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(param_2 + 0xbc);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    return;
  }
  uVar3 = FUN_00424520();
  local_4 = param_1 + 0x18;
  local_8 = (uVar3 & 0xffff) - 0x18;
  cVar2 = (**(code **)(*piVar1 + 0x3c))(&local_8);
  if (cVar2 == '\0') {
    FUN_004ea310();
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 6;
    *(undefined2 *)(in_ECX + 0xc) = 200;
  }
  return;
}


// ==== FUN_0050b0b0 @ 0x0050b0b0 ====

void FUN_0050b0b0(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(param_2 + 0xbc);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    return;
  }
  uVar3 = FUN_00424520();
  local_4 = param_1 + 0x18;
  local_8 = (uVar3 & 0xffff) - 0x18;
  cVar2 = (**(code **)(*piVar1 + 0x48))(&local_8);
  if (cVar2 == '\0') {
    FUN_004ea310();
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 6;
    *(undefined2 *)(in_ECX + 0xc) = 200;
  }
  return;
}


// ==== FUN_0050b140 @ 0x0050b140 ====

void FUN_0050b140(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(param_2 + 0xbc);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    return;
  }
  uVar3 = FUN_00424520();
  local_4 = param_1 + 0x18;
  local_8 = (uVar3 & 0xffff) - 0x18;
  cVar2 = (**(code **)(*piVar1 + 0x28))(&local_8);
  if (cVar2 == '\0') {
    FUN_004ea310();
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 6;
    *(undefined2 *)(in_ECX + 0xc) = 200;
  }
  return;
}


// ==== FUN_0050b1d0 @ 0x0050b1d0 ====

void FUN_0050b1d0(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(param_2 + 0xbc);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    return;
  }
  uVar3 = FUN_00424520();
  local_4 = param_1 + 0x18;
  local_8 = (uVar3 & 0xffff) - 0x18;
  cVar2 = (**(code **)(*piVar1 + 0x34))(&local_8);
  if (cVar2 == '\0') {
    FUN_004ea310();
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 6;
    *(undefined2 *)(in_ECX + 0xc) = 200;
  }
  return;
}


// ==== FUN_0050b260 @ 0x0050b260 ====

void FUN_0050b260(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(param_2 + 0xbc);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    return;
  }
  uVar3 = FUN_00424520();
  local_4 = param_1 + 0x18;
  local_8 = (uVar3 & 0xffff) - 0x18;
  cVar2 = (**(code **)(*piVar1 + 0x40))(&local_8);
  if (cVar2 == '\0') {
    FUN_004ea310();
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 6;
    *(undefined2 *)(in_ECX + 0xc) = 200;
  }
  return;
}


// ==== FUN_0050b2f0 @ 0x0050b2f0 ====

void FUN_0050b2f0(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(param_2 + 0xbc);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    return;
  }
  uVar3 = FUN_00424520();
  local_4 = param_1 + 0x18;
  local_8 = (uVar3 & 0xffff) - 0x18;
  cVar2 = (**(code **)(*piVar1 + 0x4c))(&local_8);
  if (cVar2 == '\0') {
    FUN_004ea310();
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xe) = 6;
    *(undefined2 *)(in_ECX + 0xc) = 200;
  }
  return;
}


// ==== FUN_0050b380 @ 0x0050b380 ====

undefined4 FUN_0050b380(void)

{
  int in_ECX;
  
  (**(code **)(*DAT_00b5a6ac + 0x18))();
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_0050b3a0 @ 0x0050b3a0 ====

void FUN_0050b3a0(void)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined1 auStack_6 [6];
  
  piVar4 = (int *)(**(code **)(*DAT_00b5a6e0 + 0xc))(1,0);
  piVar2 = DAT_00b5a6ac;
  FUN_00424520();
  iVar1 = *piVar4;
  uVar5 = (**(code **)(*piVar2 + 0x20))();
  cVar3 = (**(code **)(iVar1 + 0x1c))(auStack_6 + -10,uVar5);
  if (cVar3 == '\0') {
    (**(code **)(*DAT_00b5a6e0 + 0x10))(1,piVar4);
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    *(undefined2 *)(in_ECX + 0xe) = 4;
    return;
  }
  iVar1 = *(int *)piVar4[0x14];
  uVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(iVar1 + 0x18))(uVar5);
  iVar1 = *(int *)piVar4[0x11];
  uVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(iVar1 + 0x1c))(uVar5);
  FUN_004ea700(piVar4);
  (**(code **)(*DAT_00b5ac30 + 4))();
  return;
}


// ==== FUN_0050b470 @ 0x0050b470 ====

void FUN_0050b470(int param_1,int param_2)

{
  short sVar1;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    sVar1 = *(short *)(param_1 + 0x10);
    *(undefined2 *)(in_ECX + 0xc) = 500;
    *(short *)(in_ECX + 0xe) = -sVar1;
    return;
  }
  *(bool *)(param_2 + 0x79) = *(char *)(param_1 + 0x14) == '\x01';
  *(bool *)(param_2 + 0x7b) = *(char *)(param_1 + 0x15) == '\x01';
  *(bool *)(param_2 + 0x7a) = *(char *)(param_1 + 0x16) == '\x01';
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_>>_Receive_LOCKACKSTART_009b5990,0x18);
  FUN_00403e50(local_1c);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0050b510 @ 0x0050b510 ====

void FUN_0050b510(int param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar1 = *(int *)(param_2 + 0xbc);
  if (iVar1 == 0) {
    *(undefined4 *)(in_ECX + 8) = 2;
    *(undefined2 *)(in_ECX + 0xc) = 200;
    *(undefined2 *)(in_ECX + 0xe) = 0xb;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_>>_Receive_LOCKACKEND_009b59ac,0x19);
  FUN_00403e50(local_1c);
  if (local_4 < 0x10) {
    *(undefined4 *)(in_ECX + 8) = 1;
    *(undefined2 *)(in_ECX + 0xc) = 0;
    *(undefined2 *)(in_ECX + 0xe) = 0;
    *(undefined4 *)(iVar1 + 0xac) = *(undefined4 *)(param_1 + 0x10);
    FUN_004f5200();
    *(bool *)(param_2 + 0x7c) = *(char *)(param_1 + 0x14) == '\x01';
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0050b5c0 @ 0x0050b5c0 ====

uint FUN_0050b5c0(int *param_1)

{
  uint extraout_EAX;
  undefined4 uVar1;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  uint extraout_EAX_03;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if ((param_1[2] != 2) || (*param_1 != DAT_00b5ad3c)) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18._1_3_ << 8);
    FUN_00401740(s_>>_LOCKCMD_Start_Fail_009b5910,0x19);
    FUN_00403e50(local_1c);
    if (local_4 < 0x10) {
      uVar4 = FUN_004ea450();
      *(undefined4 *)(in_ECX + 8) = 2;
      *(undefined2 *)(in_ECX + 0xc) = 200;
      *(undefined2 *)(in_ECX + 0xe) = 3;
      return uVar4 & 0xffffff00;
    }
    _free(local_18);
    return extraout_EAX_03;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18._1_3_ << 8);
  FUN_00401740(s_>>_LOCKCMD_Start_009b592c,0x14);
  FUN_00403e50(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  FUN_00401740(s_SerialKey___0x_08X_009b5944,0x16);
  uVar1 = FUN_00404230(local_1c);
  FUN_00403e50(uVar1);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX_00;
  }
  FUN_00401740(s_SessionServer_ID___0x_08X_009b595c,0x1d);
  uVar1 = FUN_00404230(local_1c);
  FUN_00403e50(uVar1);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX_01;
  }
  uVar1 = FUN_004022a0(local_1c,s_User_NO___009b597c,param_1 + 0x17);
  FUN_00403e50(uVar1);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX_02;
  }
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x4000000;
  *(undefined2 *)((int)pvVar2 + 6) = 0x40;
  iVar3 = FUN_004244d0();
  *(int *)(iVar3 + 0x10) = param_1[0x16];
  *(int *)(iVar3 + 0x14) = param_1[0x15];
  if ((uint)param_1[0x1d] < 0x10) {
    param_1 = param_1 + 0x18;
  }
  else {
    param_1 = (int *)param_1[0x18];
  }
  FUN_00509d90(iVar3 + 0x18,&DAT_009b598c,param_1);
  uVar1 = (**(code **)(*DAT_00b5ac14 + 4))(local_1c);
  FUN_0047aa00(uVar1);
  FUN_004d8570(iVar3);
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  *(uint *)(in_ECX + 4) = uVar4;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined2 *)(in_ECX + 0xc) = 0;
  *(undefined2 *)(in_ECX + 0xe) = 0;
  return uVar4 & 0xffffff00;
}


// ==== FUN_0050b800 @ 0x0050b800 ====

undefined4 FUN_0050b800(int param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = FUN_00424500();
  if (uVar1 < 0x2040017) {
    if (uVar1 == 0x2040016) {
      FUN_0050af00(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    }
    switch(uVar1) {
    case 0x2040000:
      FUN_0050b3a0(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    case 0x2040001:
      FUN_0050a990(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    case 0x2040002:
      FUN_0050aa20(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    case 0x2040003:
      FUN_0050aab0(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    case 0x204000f:
      FUN_0050abd0(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    case 0x2040010:
      FUN_0050ac60(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    case 0x2040011:
      FUN_0050acf0(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    case 0x2040012:
      FUN_0050ad80(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    case 0x2040013:
      FUN_0050ab40(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    case 0x2040014:
      FUN_0050ae10(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    case 0x2040015:
      FUN_0050aea0(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    }
  }
  else if (uVar1 < 0x2060003) {
    if (uVar1 == 0x2060002) {
      FUN_0050a950(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    }
    switch(uVar1 + 0xfdfbffe9) {
    case 0:
      FUN_0050af90(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    case 1:
      FUN_0050b020(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    case 2:
      FUN_0050b0b0(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    case 3:
      FUN_0050b140(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    case 4:
      FUN_0050b1d0(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    case 5:
      FUN_0050b260(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    case 6:
      FUN_0050b2f0(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    }
  }
  else {
    if (uVar1 == 0x4000002) {
      FUN_0050b470(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    }
    if (uVar1 == 0x4000003) {
      FUN_0050b510(*(undefined4 *)(param_1 + 0xc),param_2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0050bae0 @ 0x0050bae0 ====

uint FUN_0050bae0(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    if ((*(int *)(in_ECX + 8) == 0) && (*(int *)(in_ECX + 4) + 20000U < (uint)param_1[2])) {
      *(undefined4 *)(in_ECX + 8) = 3;
      *(undefined2 *)(in_ECX + 0xc) = 300;
      *(undefined2 *)(in_ECX + 0xe) = 1;
    }
  }
  else if (uVar1 == 0x50011) {
    uVar1 = FUN_0050b800(param_1,param_2);
    if ((char)uVar1 == '\x01') {
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0050bb50 @ 0x0050bb50 ====

void FUN_0050bb50(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x28);
  return;
}


// ==== FUN_0050bbb0 @ 0x0050bbb0 ====

undefined4 FUN_0050bbb0(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  if (uVar1 < *(int *)(in_ECX + 4) + 1000U) {
    return 0;
  }
  return *(undefined4 *)(in_ECX + 0x24);
}


// ==== FUN_0050bbe0 @ 0x0050bbe0 ====

void FUN_0050bbe0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5b5c;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_009b358c;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_0050bc20 @ 0x0050bc20 ====

void FUN_0050bc20(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5b5c;
  in_ECX[1] = 0;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  in_ECX[9] = 0;
  *(undefined2 *)(in_ECX + 10) = 0;
  *(undefined2 *)((int)in_ECX + 0x2a) = 0;
  return;
}


// ==== FUN_0050bc60 @ 0x0050bc60 ====

void FUN_0050bc60(int param_1,int param_2)

{
  short sVar1;
  uint uVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  void *pvVar6;
  undefined4 uVar7;
  int iVar8;
  int in_ECX;
  char *pcVar9;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar2 = *(uint *)(param_1 + 0x1c);
    iVar5 = (**(code **)(*DAT_00b5a6b0 + 8))();
    iVar8 = param_2;
    if ((iVar5 == 1) && (uVar2 < 0x3c)) {
      FUN_00401660(in_ECX + 8,0,0xffffffff);
      *(undefined4 *)(in_ECX + 0x24) = 1;
      FUN_004e9d50();
      pvVar6 = operator_new(0xc);
      if (pvVar6 == (void *)0x0) {
        uVar7 = 0;
      }
      else {
        uVar7 = FUN_004f58c0(DAT_00b5ad3c);
      }
      FUN_004ea750(uVar7);
      pvVar6 = operator_new(0x10);
      if (pvVar6 == (void *)0x0) {
        uVar7 = 0;
      }
      else {
        uVar7 = FUN_005098f0();
      }
      FUN_004ea750(uVar7);
      pvVar6 = operator_new(0xc);
      if (pvVar6 == (void *)0x0) {
        uVar7 = 0;
      }
      else {
        uVar7 = FUN_004f58c0(DAT_00b5ad40);
      }
      FUN_004ea750(uVar7);
      pvVar6 = operator_new(8);
      if (pvVar6 == (void *)0x0) {
        uVar7 = 0;
      }
      else {
        uVar7 = FUN_0050a420();
      }
      FUN_004ea750(uVar7);
      pvVar6 = operator_new(0x24);
      if (pvVar6 == (void *)0x0) {
        uVar7 = 0;
      }
      else {
        FUN_00401830(PTR_s_SceneCharSelect_00aeadb8);
        uVar7 = FUN_004f8810(local_1c);
      }
      FUN_004ea750(uVar7);
      if ((pvVar6 != (void *)0x0) && (0xf < local_4)) {
        _free(local_18);
        return;
      }
      pvVar6 = operator_new(0x10);
      if (pvVar6 == (void *)0x0) {
        FUN_004ea750(0);
        return;
      }
      param_2 = 0x50190;
      uVar7 = FUN_004f5d20(&param_2,10000);
      FUN_004ea750(uVar7);
      return;
    }
    *(undefined4 *)(in_ECX + 0x24) = 1;
    iVar5 = in_ECX + 8;
    *(undefined2 *)(in_ECX + 0x28) = 0;
    *(undefined2 *)(in_ECX + 0x2a) = 0;
    FUN_00401660(iVar5,0,0xffffffff);
    *(undefined4 *)(iVar8 + 0x9c) = 0;
    if (3 < *(uint *)(in_ECX + 0x1c)) {
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      FUN_00401660(iVar5,0,4);
      cVar3 = FUN_004036a0(local_1c,&DAT_009b5b0c);
      param_2 = CONCAT31(param_2._1_3_,cVar3);
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
      if (cVar3 != '\0') {
        *(undefined4 *)(iVar8 + 0x9c) = 2;
      }
    }
    if (4 < *(uint *)(in_ECX + 0x1c)) {
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      FUN_00401660(iVar5,0,5);
      cVar3 = FUN_004036a0(local_1c,s__DEV__009b5b14);
      param_2 = CONCAT31(param_2._1_3_,cVar3);
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
      if (cVar3 != '\0') {
        *(undefined4 *)(iVar8 + 0x9c) = 3;
      }
    }
    if (8 < *(uint *)(in_ECX + 0x1c)) {
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      FUN_00401660(iVar5,0,9);
      cVar3 = FUN_004036a0(local_1c,s__DEKARON__009b5b1c);
      param_2 = CONCAT31(param_2._1_3_,cVar3);
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
      if (cVar3 != '\0') {
        *(undefined4 *)(iVar8 + 0x9c) = 4;
      }
    }
    iVar8 = (**(code **)(*DAT_00b5a6b0 + 8))();
    if ((iVar8 == 1) && (4 < *(uint *)(in_ECX + 0x1c))) {
      pcVar9 = s__OPR__009b5b28;
      uVar7 = FUN_00405b90(local_1c,0,5);
      uVar4 = FUN_004036a0(uVar7,pcVar9);
      param_2 = CONCAT31(param_2._1_3_,uVar4);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_>>_CHECKOUTCMD_End_009b5b30,0x16);
    FUN_00796d50(local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x9c) = 0;
    *(undefined4 *)(in_ECX + 0x24) = 2;
    sVar1 = *(short *)(param_1 + 0x10);
    *(undefined2 *)(in_ECX + 0x28) = 400;
    *(short *)(in_ECX + 0x2a) = -sVar1;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_>>_CHECKOUTCMD_End___Fail___009b5aec,0x1f);
    FUN_00796d50(local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
  }
  return;
}


// ==== FUN_0050c040 @ 0x0050c040 ====

uint FUN_0050c040(int *param_1)

{
  uint extraout_EAX;
  undefined4 uVar1;
  uint extraout_EAX_00;
  void *pvVar2;
  uint uVar3;
  uint extraout_EAX_01;
  int in_ECX;
  undefined1 auStack_48 [12];
  undefined4 uStack_3c;
  int iStack_38;
  char *pcStack_34;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if ((param_1[2] != 1) || (*param_1 != DAT_00b5ad40)) {
    pcStack_34 = s_>>_CHECKOUTCMD_Start_Fail_009b5a94;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18._1_3_ << 8);
    iStack_38 = 0x50c186;
    FUN_00401740();
    pcStack_34 = (char *)0x50c190;
    FUN_00796d50();
    if (local_4 < 0x10) {
      uVar3 = FUN_004ea450();
      *(undefined4 *)(in_ECX + 0x24) = 2;
      *(undefined2 *)(in_ECX + 0x2a) = 1;
      *(undefined2 *)(in_ECX + 0x28) = 200;
      return uVar3 & 0xffffff00;
    }
    pcStack_34 = (char *)0x50c1a4;
    _free(local_18);
    return extraout_EAX_01;
  }
  pcStack_34 = s_>>_CHECKOUTCMD_Start_009b5ab4;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18._1_3_ << 8);
  iStack_38 = 0x50c08b;
  FUN_00401740();
  pcStack_34 = (char *)0x50c095;
  FUN_00796d50();
  if (0xf < local_4) {
    pcStack_34 = (char *)0x50c0ad;
    _free(local_18);
    return extraout_EAX;
  }
  FUN_004022a0(auStack_48,s_Character_Name_009b5ad0,in_ECX + 8);
  uVar1 = FUN_00404230(local_1c);
  FUN_00796d50(uVar1);
  if (local_4 < 0x10) {
    pcStack_34 = (char *)0x50c0f7;
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = 0;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x3010000;
    *(undefined2 *)((int)pvVar2 + 6) = 0x2c;
    iStack_38 = FUN_004244d0();
    iStack_38 = iStack_38 + 0x10;
    pcStack_34 = &DAT_009b5ae8;
    uStack_3c = 0x50c130;
    FUN_0047aa30();
    pcStack_34 = (char *)0x50c13f;
    FUN_004d8570();
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x18))();
    *(uint *)(in_ECX + 4) = uVar3;
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined2 *)(in_ECX + 0x28) = 0;
    *(undefined2 *)(in_ECX + 0x2a) = 0;
    return uVar3 & 0xffffff00;
  }
  pcStack_34 = (char *)0x50c0ea;
  _free(local_18);
  return extraout_EAX_00;
}


// ==== FUN_0050c210 @ 0x0050c210 ====

undefined4 FUN_0050c210(int *param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    if ((*(int *)(in_ECX + 0x24) == 0) && (*(int *)(in_ECX + 4) + 20000U < (uint)param_1[2])) {
      *(undefined4 *)(in_ECX + 0x24) = 3;
      *(undefined2 *)(in_ECX + 0x28) = 300;
      *(undefined2 *)(in_ECX + 0x2a) = 1;
    }
  }
  else if (iVar1 == 0x50011) {
    iVar1 = FUN_00424500();
    if (iVar1 == 0x3010001) {
      FUN_0050bc60(param_1[3],param_2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0050c280 @ 0x0050c280 ====

void FUN_0050c280(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5b5c;
  if (0xf < (uint)in_ECX[8]) {
    _free((void *)in_ECX[3]);
    return;
  }
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  *in_ECX = &PTR_FUN_009b358c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0050c2e0 @ 0x0050c2e0 ====

undefined4 FUN_0050c2e0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_0050c2f0 @ 0x0050c2f0 ====

void FUN_0050c2f0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5b9c;
  uVar1 = *param_1;
  in_ECX[2] = param_2;
  in_ECX[1] = uVar1;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_0050c320 @ 0x0050c320 ====

undefined4 FUN_0050c320(int param_1)

{
  undefined4 *puVar1;
  
  if (*(char *)(param_1 + 0x78) == '\0') {
    return 1;
  }
  FUN_004e9b00();
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 0;
  }
  *puVar1 = &PTR_FUN_009b5b88;
  FUN_00797a20(puVar1);
  return 0;
}


// ==== FUN_0050c370 @ 0x0050c370 ====

uint FUN_0050c370(int *param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    iVar2 = (**(code **)(*DAT_00b5a6ac + 0x18))();
    uVar1 = iVar2 - *(int *)(in_ECX + 0x10);
    if (*(uint *)(in_ECX + 8) < uVar1) {
      *(undefined4 *)(in_ECX + 0xc) = 1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0050c3b0 @ 0x0050c3b0 ====

undefined4 FUN_0050c3b0(void)

{
  return 0x70030002;
}


// ==== FUN_0050c3c0 @ 0x0050c3c0 ====

void FUN_0050c3c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099cf40;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0050c3e0 @ 0x0050c3e0 ====

void FUN_0050c3e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b358c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0050c400 @ 0x0050c400 ====

void FUN_0050c400(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x48);
  return;
}


// ==== FUN_0050c440 @ 0x0050c440 ====

undefined4 FUN_0050c440(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  if (uVar1 < *(int *)(in_ECX + 0x40) + 1000U) {
    return 0;
  }
  return *(undefined4 *)(in_ECX + 0x44);
}


// ==== FUN_0050c470 @ 0x0050c470 ====

void FUN_0050c470(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5c7c;
  if (0xf < (uint)in_ECX[0xe]) {
    _free((void *)in_ECX[9]);
    return;
  }
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[6] = 0;
    in_ECX[7] = 0xf;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_009b358c;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0050c4d0 @ 0x0050c4d0 ====

void FUN_0050c4d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5c7c;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  FUN_00401660(param_2,0,0xffffffff);
  in_ECX[0xf] = param_3;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  *(undefined2 *)(in_ECX + 0x12) = 0;
  *(undefined2 *)((int)in_ECX + 0x4a) = 0;
  return;
}


// ==== FUN_0050c540 @ 0x0050c540 ====

void FUN_0050c540(int param_1,int param_2)

{
  char cVar1;
  short sVar2;
  char *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined4 *puVar6;
  undefined1 local_8c [4];
  void *local_88;
  undefined4 local_78;
  uint local_74;
  undefined4 uStack_70;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    *(undefined4 *)(param_2 + 0x54) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(param_2 + 0x58) = *(undefined4 *)(param_1 + 0x18);
    pcVar3 = (char *)(param_1 + 0x1c);
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00401740((char *)(param_1 + 0x1c),(int)pcVar3 - (param_1 + 0x1d));
    iVar4 = (**(code **)(*DAT_00b5a6b0 + 8))();
    if (iVar4 == 1) {
      iVar4 = (**(code **)(*DAT_00b5a6d4 + 0x14))();
      if (iVar4 == 2) {
        *(undefined1 *)(param_2 + 0x78) = 0;
      }
      else {
        *(bool *)(param_2 + 0x78) = iVar4 != 0;
      }
    }
    else if (iVar4 == 2) {
      puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
      puVar6 = &uStack_70;
      for (iVar4 = 0x19; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      *(undefined1 *)(param_2 + 0x78) = (undefined1)uStack_70;
    }
    else if (iVar4 == 4) {
      *(undefined1 *)(param_2 + 0x78) = 1;
    }
    else {
      puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
      uStack_70._1_1_ = *(char *)(param_1 + 0x2b) != '\x01';
      puVar6 = &uStack_70;
      for (iVar4 = 0x19; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      if ((bool)uStack_70._1_1_) {
        *(undefined1 *)(param_2 + 0x78) = 0;
      }
      else {
        *(undefined1 *)(param_2 + 0x78) = (undefined1)uStack_70;
      }
      (**(code **)(*DAT_00b5a6e4 + 0x10))(&uStack_70);
    }
    *(undefined4 *)(in_ECX + 0x44) = 1;
    *(undefined2 *)(in_ECX + 0x48) = 0;
    *(undefined2 *)(in_ECX + 0x4a) = 0;
    local_74 = 0xf;
    local_78 = 0;
    local_88 = (void *)((uint)local_88 & 0xffffff00);
    FUN_00401740(s_>>_LOGINCMD_End_009b5c54,0x13);
    FUN_00796d50(local_8c);
    if (0xf < local_74) {
      _free(local_88);
      return;
    }
  }
  else {
    *(undefined4 *)(in_ECX + 0x44) = 2;
    sVar2 = *(short *)(param_1 + 0x14);
    *(undefined2 *)(in_ECX + 0x48) = 600;
    *(short *)(in_ECX + 0x4a) = -sVar2;
    local_74 = 0xf;
    local_78 = 0;
    local_88 = (void *)((uint)local_88 & 0xffffff00);
    FUN_00401740(s_>>_LOGINCMD_End_Fail_009b5c38,0x18);
    FUN_00796d50(local_8c);
    if (0xf < local_74) {
      _free(local_88);
      return;
    }
  }
  return;
}


// ==== FUN_0050c710 @ 0x0050c710 ====

uint FUN_0050c710(int *param_1)

{
  uint extraout_EAX;
  undefined4 uVar1;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  int iVar2;
  uint extraout_EAX_02;
  uint uVar3;
  int in_ECX;
  int iVar4;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if ((param_1[2] != 1) || (*param_1 != DAT_00b5ad44)) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18._1_3_ << 8);
    FUN_00401740(s_>>_LOGINCMD_Start_Fail_009b5bb4,0x1a);
    FUN_00796d50(local_1c);
    if (local_4 < 0x10) {
      uVar3 = FUN_004ea450();
      *(undefined4 *)(in_ECX + 0x44) = 2;
      *(undefined2 *)(in_ECX + 0x4a) = 1;
      *(undefined2 *)(in_ECX + 0x48) = 200;
      return uVar3 & 0xffffff00;
    }
    _free(local_18);
    return extraout_EAX_02;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18._1_3_ << 8);
  FUN_00401740(s_>>_LOGINCMD_Start_009b5bd0,0x15);
  FUN_00796d50(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  uVar1 = FUN_004022a0(local_1c,s_UserID_009b5be8,in_ECX + 4);
  FUN_00796d50(uVar1);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX_00;
  }
  uVar1 = FUN_004022a0(local_1c,s_UserPWD_009b5bf8,in_ECX + 0x20);
  FUN_00796d50(uVar1);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX_01;
  }
  switch(*(undefined4 *)(in_ECX + 0x3c)) {
  case 1:
    iVar2 = FUN_0050cb70(0);
    if (*(uint *)(in_ECX + 0x1c) < 0x10) {
      iVar4 = in_ECX + 8;
    }
    else {
      iVar4 = *(int *)(in_ECX + 8);
    }
    FUN_0050cc90(iVar2 + 0x10,&DAT_009b5c08,iVar4);
    if (*(uint *)(in_ECX + 0x38) < 0x10) {
      iVar4 = in_ECX + 0x24;
    }
    else {
      iVar4 = *(int *)(in_ECX + 0x24);
    }
    FUN_0050ccc0(iVar2 + 0x21,&DAT_009b5c0c,iVar4);
    FUN_004ef210(iVar2);
    break;
  case 2:
    iVar2 = FUN_0050cba0(0);
    if (*(uint *)(in_ECX + 0x1c) < 0x10) {
      iVar4 = in_ECX + 8;
    }
    else {
      iVar4 = *(int *)(in_ECX + 8);
    }
    FUN_0050ccc0(iVar2 + 0x10,&DAT_009b5c10,iVar4);
    if (*(uint *)(in_ECX + 0x38) < 0x10) {
      iVar4 = in_ECX + 0x24;
    }
    else {
      iVar4 = *(int *)(in_ECX + 0x24);
    }
    FUN_0050ccc0(iVar2 + 0x51,&DAT_009b5c14,iVar4);
    FUN_004ef210(iVar2);
    break;
  case 3:
    iVar2 = FUN_0050cbd0(0);
    if (*(uint *)(in_ECX + 0x1c) < 0x10) {
      iVar4 = in_ECX + 8;
    }
    else {
      iVar4 = *(int *)(in_ECX + 8);
    }
    FUN_0050ccf0(iVar2 + 0x10,&DAT_009b5c18,iVar4);
    if (*(uint *)(in_ECX + 0x38) < 0x10) {
      iVar4 = in_ECX + 0x24;
    }
    else {
      iVar4 = *(int *)(in_ECX + 0x24);
    }
    FUN_0050ccc0(iVar2 + 0x91,&DAT_009b5c1c,iVar4);
    FUN_004ef210(iVar2);
    break;
  case 4:
    iVar2 = FUN_0050cc00(0);
    if (*(uint *)(in_ECX + 0x1c) < 0x10) {
      iVar4 = in_ECX + 8;
    }
    else {
      iVar4 = *(int *)(in_ECX + 8);
    }
    FUN_0050cd30(iVar2 + 0x10,&DAT_009b5c20,iVar4);
    if (*(uint *)(in_ECX + 0x38) < 0x10) {
      iVar4 = in_ECX + 0x24;
    }
    else {
      iVar4 = *(int *)(in_ECX + 0x24);
    }
    FUN_0050ccc0(iVar2 + 0x31,&DAT_009b5c24,iVar4);
    FUN_004ef210(iVar2);
    break;
  default:
    iVar2 = (**(code **)(*DAT_00b5a6b0 + 8))();
    if (iVar2 == 3) {
      iVar2 = FUN_0050cc30();
      if (*(uint *)(in_ECX + 0x1c) < 0x10) {
        iVar4 = in_ECX + 8;
      }
      else {
        iVar4 = *(int *)(in_ECX + 8);
      }
      FUN_0050cd30(iVar2 + 0x10,&DAT_009b5c28,iVar4);
      if (*(uint *)(in_ECX + 0x38) < 0x10) {
        FUN_0050ccc0(iVar2 + 0x31,&DAT_009b5c2c,in_ECX + 0x24);
      }
      else {
        FUN_0050ccc0(iVar2 + 0x31,&DAT_009b5c2c,*(undefined4 *)(in_ECX + 0x24));
      }
    }
    else {
      iVar2 = FUN_0050cc60(0);
      if (*(uint *)(in_ECX + 0x1c) < 0x10) {
        iVar4 = in_ECX + 8;
      }
      else {
        iVar4 = *(int *)(in_ECX + 8);
      }
      FUN_0050cc90(iVar2 + 0x10,&DAT_009b5c30,iVar4);
      if (*(uint *)(in_ECX + 0x38) < 0x10) {
        iVar4 = in_ECX + 0x24;
      }
      else {
        iVar4 = *(int *)(in_ECX + 0x24);
      }
      FUN_0050cc90(iVar2 + 0x21,&DAT_009b5c34,iVar4);
    }
    FUN_004d8570(iVar2);
  }
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  *(undefined4 *)(in_ECX + 0x40) = uVar1;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined2 *)(in_ECX + 0x48) = 0;
  *(undefined2 *)(in_ECX + 0x4a) = 0;
  return 0;
}


// ==== FUN_0050cb00 @ 0x0050cb00 ====

undefined4 FUN_0050cb00(int *param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    if ((*(int *)(in_ECX + 0x44) == 0) && (*(int *)(in_ECX + 0x40) + 20000U < (uint)param_1[2])) {
      *(undefined4 *)(in_ECX + 0x44) = 3;
      *(undefined2 *)(in_ECX + 0x48) = 300;
      *(undefined2 *)(in_ECX + 0x4a) = 1;
    }
  }
  else if (iVar1 == 0x50011) {
    iVar1 = FUN_00424500();
    if (iVar1 == 0x3000001) {
      FUN_0050c540(param_1[3],param_2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0050cb70 @ 0x0050cb70 ====

void FUN_0050cb70(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x3000004;
  *(undefined2 *)((int)pvVar1 + 6) = 100;
  FUN_004244d0();
  return;
}


// ==== FUN_0050cba0 @ 0x0050cba0 ====

void FUN_0050cba0(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x3000005;
  *(undefined2 *)((int)pvVar1 + 6) = 0x94;
  FUN_004244d0();
  return;
}


// ==== FUN_0050cbd0 @ 0x0050cbd0 ====

void FUN_0050cbd0(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x3000006;
  *(undefined2 *)((int)pvVar1 + 6) = 0xd4;
  FUN_004244d0();
  return;
}


// ==== FUN_0050cc00 @ 0x0050cc00 ====

void FUN_0050cc00(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x3000008;
  *(undefined2 *)((int)pvVar1 + 6) = 0x74;
  FUN_004244d0();
  return;
}


// ==== FUN_0050cc30 @ 0x0050cc30 ====

void FUN_0050cc30(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x3000007;
  *(undefined2 *)((int)pvVar1 + 6) = 0x74;
  FUN_004244d0();
  return;
}


// ==== FUN_0050cc60 @ 0x0050cc60 ====

void FUN_0050cc60(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x3000000;
  *(undefined2 *)((int)pvVar1 + 6) = 0x34;
  FUN_004244d0();
  return;
}


// ==== FUN_0050cc90 @ 0x0050cc90 ====

char * FUN_0050cc90(char *param_1,char *param_2,char param_3)

{
  int iVar1;
  
  iVar1 = __vsnprintf(param_1,0x11,param_2,&param_3);
  if ((iVar1 < 0) || (iVar1 == 0x11)) {
    param_1[0x10] = '\0';
  }
  return param_1;
}


// ==== FUN_0050ccc0 @ 0x0050ccc0 ====

char * FUN_0050ccc0(char *param_1,char *param_2,char param_3)

{
  int iVar1;
  
  iVar1 = __vsnprintf(param_1,0x41,param_2,&param_3);
  if ((iVar1 < 0) || (iVar1 == 0x41)) {
    param_1[0x40] = '\0';
  }
  return param_1;
}


// ==== FUN_0050ccf0 @ 0x0050ccf0 ====

char * FUN_0050ccf0(char *param_1,char *param_2,char param_3)

{
  int iVar1;
  
  iVar1 = __vsnprintf(param_1,0x81,param_2,&param_3);
  if ((iVar1 < 0) || (iVar1 == 0x81)) {
    param_1[0x80] = '\0';
  }
  return param_1;
}


// ==== FUN_0050cd30 @ 0x0050cd30 ====

char * FUN_0050cd30(char *param_1,char *param_2,char param_3)

{
  int iVar1;
  
  iVar1 = __vsnprintf(param_1,0x21,param_2,&param_3);
  if ((iVar1 < 0) || (iVar1 == 0x21)) {
    param_1[0x20] = '\0';
  }
  return param_1;
}


// ==== FUN_0050cd60 @ 0x0050cd60 ====

void FUN_0050cd60(byte param_1)

{
  void *in_ECX;
  
  FUN_0050c470();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0050cd80 @ 0x0050cd80 ====

void FUN_0050cd80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5cb0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0050cdb0 @ 0x0050cdb0 ====

void FUN_0050cdb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5cbc;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_009b5cb0;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_0050cdf0 @ 0x0050cdf0 ====

void FUN_0050cdf0(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5cbc;
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[1] = param_1;
  FUN_00401660(param_2,0,0xffffffff);
  *(undefined1 *)(in_ECX + 9) = param_3;
  return;
}


// ==== FUN_0050ce30 @ 0x0050ce30 ====

undefined4 FUN_0050ce30(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  void *pvVar3;
  undefined4 *puVar4;
  undefined4 extraout_EAX_00;
  int in_ECX;
  void *unaff_ESI;
  undefined4 uStack_1c;
  uint uStack_10;
  uint uStack_8;
  
  if (*(char *)(in_ECX + 0x24) == '\0') {
    (**(code **)(*DAT_00b5a6b0 + 0x14))();
  }
  else {
    (**(code **)(*DAT_00b5a6b0 + 0x10))(0);
  }
  (**(code **)(*DAT_00b5a688 + 0x48))();
  iVar1 = in_ECX + 8;
  uVar2 = FUN_00402220((int)register0x00000010 + -0x20,iVar1,s_Loading____009b5c94);
  FUN_00796d50(uVar2);
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return extraout_EAX;
  }
  pvVar3 = operator_new(0x10);
  if (pvVar3 == (void *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)FUN_0081d3a0(iVar1);
  }
  (**(code **)(*DAT_00b5aa08 + 8))(in_ECX + 4,puVar4);
  uVar2 = FUN_00402220((int)register0x00000010 + -0x28,iVar1,s_Loading_OK_009b5ca0);
  FUN_00796d50(uVar2);
  if (0xf < uStack_10) {
    _free(unaff_ESI);
    return extraout_EAX_00;
  }
  if (puVar4 != (undefined4 *)0x0) {
    (**(code **)*puVar4)(1);
  }
  (**(code **)(*DAT_00b5a6b0 + 0x14))();
  (**(code **)(*DAT_00b5a688 + 0x48))();
  return 1;
}


// ==== FUN_0050cf20 @ 0x0050cf20 ====

void FUN_0050cf20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5cbc;
  if (0xf < (uint)in_ECX[8]) {
    _free((void *)in_ECX[3]);
    return;
  }
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  *in_ECX = &PTR_FUN_009b5cb0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0050cf80 @ 0x0050cf80 ====

void FUN_0050cf80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5cf8;
  return;
}


// ==== FUN_0050cf90 @ 0x0050cf90 ====

undefined4 FUN_0050cf90(void)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  void *pvVar2;
  undefined4 *puVar3;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined1 local_54 [4];
  void *local_50;
  undefined4 uStack_40;
  uint local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(&DAT_009b5cc8,3);
  FUN_00402220(local_54,local_38,s_AISetting_csv_009b5ccc);
  uVar1 = FUN_00402220(local_1c,local_54,s_Loading____009b5cdc);
  FUN_00796d50(uVar1);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  pvVar2 = operator_new(0x10);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_0081d3a0(local_54);
  }
  FUN_0044a4d0(puVar3);
  uVar1 = FUN_00402220(local_1c,local_54,s_Loading_OK_009b5ce8);
  FUN_00796d50(uVar1);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX_00;
  }
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  if (0xf < local_3c) {
    _free(local_50);
    return extraout_EAX_01;
  }
  uStack_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  local_3c = 0xf;
  if (local_20 < 0x10) {
    return 1;
  }
  _free(local_34);
  return extraout_EAX_02;
}


// ==== FUN_0050d0c0 @ 0x0050d0c0 ====

void FUN_0050d0c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5d30;
  return;
}


// ==== FUN_0050d0d0 @ 0x0050d0d0 ====

undefined4 FUN_0050d0d0(void)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  void *pvVar2;
  undefined4 *puVar3;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 local_54;
  undefined4 uStack_44;
  uint uStack_40;
  void *local_38;
  undefined1 local_34;
  uint local_24;
  undefined4 local_20;
  void *local_1c;
  void *local_18;
  uint uStack_8;
  uint local_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(&DAT_009b5d04,3);
  FUN_00402220(&local_54,&local_38,s_Info_csv_009b5d08);
  uVar1 = FUN_00402220(&local_1c,&local_54,s_Loading____009b5d14);
  FUN_00796d50(uVar1);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  pvVar2 = operator_new(0x10);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_0081d3a0(&local_54);
  }
  (**(code **)(*DAT_00b5a710 + 4))(puVar3);
  uVar1 = FUN_00402220(&local_20,(int)register0x00000010 + -0x58,s_Loading_OK_009b5d20);
  FUN_00796d50(uVar1);
  if (0xf < uStack_8) {
    _free(local_1c);
    return extraout_EAX_00;
  }
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  if (0xf < uStack_40) {
    _free(local_54);
    return extraout_EAX_01;
  }
  uStack_44 = 0;
  local_54 = (void *)((uint)local_54 & 0xffffff00);
  uStack_40 = 0xf;
  if (local_24 < 0x10) {
    return 1;
  }
  _free(local_38);
  return extraout_EAX_02;
}


// ==== FUN_0050d1f0 @ 0x0050d1f0 ====

void FUN_0050d1f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5d70;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_009b5cb0;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_0050d230 @ 0x0050d230 ====

void FUN_0050d230(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5d70;
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[1] = param_1;
  FUN_00401660(param_2,0,0xffffffff);
  return;
}


// ==== FUN_0050d270 @ 0x0050d270 ====

undefined4 FUN_0050d270(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  void *pvVar3;
  undefined4 *puVar4;
  undefined4 extraout_EAX_00;
  int in_ECX;
  void *unaff_EBX;
  undefined1 local_1c [2];
  undefined1 auStack_1a [2];
  void *local_18;
  uint uStack_c;
  uint local_4;
  
  iVar1 = in_ECX + 8;
  uVar2 = FUN_00402220(local_1c,iVar1,s_Pattern_Loding_009b5d3c);
  FUN_00796d50(uVar2);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  pvVar3 = operator_new(0x10);
  if (pvVar3 == (void *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)FUN_0081d3a0(iVar1);
  }
  (**(code **)(*DAT_00b5a700 + 4))(*(undefined4 *)(in_ECX + 4),puVar4);
  if (puVar4 != (undefined4 *)0x0) {
    (**(code **)*puVar4)(1);
  }
  uVar2 = FUN_00402220(local_1c + -8,iVar1,s_Pattern_Loding_OK_009b5d50);
  FUN_00796d50(uVar2);
  if (uStack_c < 0x10) {
    return 1;
  }
  _free(unaff_EBX);
  return extraout_EAX_00;
}


// ==== FUN_0050d320 @ 0x0050d320 ====

void FUN_0050d320(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5d70;
  if (0xf < (uint)in_ECX[8]) {
    _free((void *)in_ECX[3]);
    return;
  }
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  *in_ECX = &PTR_FUN_009b5cb0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0050d380 @ 0x0050d380 ====

void FUN_0050d380(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5d90;
  return;
}


// ==== FUN_0050d390 @ 0x0050d390 ====

undefined4 FUN_0050d390(void)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 extraout_EAX;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_movecache_csv_009b5d7c,0xd);
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_0081d3a0(&local_1c);
  }
  (**(code **)(*DAT_00b5ae50 + 4))(puVar2);
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
  }
  if (local_8 < 0x10) {
    return 1;
  }
  _free(local_1c);
  return extraout_EAX;
}


// ==== FUN_0050d420 @ 0x0050d420 ====

void FUN_0050d420(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5d9c;
  return;
}


// ==== FUN_0050d430 @ 0x0050d430 ====

undefined4 FUN_0050d430(void)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  char *pcVar4;
  undefined1 auStack_3c [4];
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  void *pvStack_20;
  undefined1 uStack_1c;
  undefined4 uStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  cVar1 = (**(code **)(*DAT_00b5ad4c + 0xc))();
  if (cVar1 != '\0') {
    piVar2 = (int *)(**(code **)(*DAT_00b5a780 + 0xc))();
    while (piVar2 != (int *)0x0) {
      pcVar3 = (char *)(**(code **)(*piVar2 + 8))();
      uStack_24 = 0xf;
      uStack_28 = 0;
      pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
      pcVar4 = pcVar3;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      FUN_00401740(pcVar3,(int)pcVar4 - (int)(pcVar3 + 1));
      piVar2 = DAT_00b5ad4c;
      uStack_8 = 0xf;
      uStack_c = 0;
      uStack_1c = 0;
      FUN_00401660(auStack_3c,0,0xffffffff);
      uStack_4 = 7;
      (**(code **)(*piVar2 + 0x18))(&pvStack_20);
      if (0xf < uStack_c) {
        _free(pvStack_20);
        return extraout_EAX;
      }
      uStack_c = 0xf;
      uStack_10 = 0;
      pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
      piVar2 = (int *)(**(code **)(*DAT_00b5a780 + 0x10))();
      if (0xf < uStack_24) {
        _free(pvStack_38);
        return extraout_EAX_00;
      }
      uStack_24 = 0xf;
      uStack_28 = 0;
      pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    }
  }
  return 1;
}


// ==== FUN_0050d540 @ 0x0050d540 ====

void FUN_0050d540(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5de8;
  return;
}


// ==== FUN_0050d550 @ 0x0050d550 ====

undefined4 FUN_0050d550(void)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 extraout_EAX;
  undefined4 *_Memory;
  undefined1 auStack_1a [6];
  uint uStack_14;
  
  FUN_00401740();
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_0081d550();
  }
  (**(code **)(*DAT_00b5ac80 + 4))();
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)();
  }
  FUN_00401740(s_Loginlist_csv_009b5db8);
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_0081d3a0();
  }
  _Memory = puVar2;
  (**(code **)(*DAT_00b5ac7c + 4))();
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
  }
  FUN_00401740(s_channellist_csv_009b5dc8,0xf);
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_0081d3a0(auStack_1a + -10);
  }
  (**(code **)(*DAT_00b5ac78 + 4))(puVar2);
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
  }
  FUN_00401740(s_period_csv_009b5dd8,10);
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_0081d3a0(auStack_1a + -0xe);
  }
  (**(code **)(*DAT_00b5ace0 + 4))(puVar2);
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
  }
  if (uStack_14 < 0x10) {
    return 1;
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_0050d6d0 @ 0x0050d6d0 ====

void FUN_0050d6d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5e1c;
  return;
}


// ==== FUN_0050d6e0 @ 0x0050d6e0 ====

undefined4 FUN_0050d6e0(void)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  void *pvVar2;
  undefined4 *puVar3;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 local_38;
  undefined1 local_34;
  uint local_24;
  undefined4 local_20;
  void *local_1c;
  void *local_18;
  uint uStack_8;
  uint local_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_version_ini_009b5df4);
  uVar1 = FUN_00402220(&local_1c,&local_38);
  FUN_00796d50(uVar1);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  pvVar2 = operator_new(0x10);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_0081d3a0(&local_38);
  }
  (**(code **)(*DAT_00b5ac14 + 0xc))(puVar3);
  uVar1 = FUN_00402220(&local_20,(int)register0x00000010 + -0x3c,s_Loading_OK_009b5e0c);
  FUN_00796d50(uVar1);
  if (0xf < uStack_8) {
    _free(local_1c);
    return extraout_EAX_00;
  }
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  if (local_24 < 0x10) {
    return 1;
  }
  _free(local_38);
  return extraout_EAX_01;
}


// ==== FUN_0050d7e0 @ 0x0050d7e0 ====

void FUN_0050d7e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5f48;
  return;
}


// ==== FUN_0050d7f0 @ 0x0050d7f0 ====

void FUN_0050d7f0(void)

{
  code *pcVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined4 *puVar4;
  void *unaff_EBX;
  undefined1 local_38 [2];
  undefined1 auStack_36 [2];
  undefined1 local_34;
  uint uStack_28;
  undefined4 local_24;
  void *local_20;
  undefined1 local_1c [4];
  void *local_18;
  uint uStack_c;
  undefined4 local_8;
  uint local_4;
  
  local_20 = (void *)0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_Partywar__009b5e28,9);
  FUN_004020e0(s_Set_csv_009b5e34,7);
  uVar2 = FUN_00402220(local_1c,local_38,s_Loading____009b5e3c);
  FUN_00796d50(uVar2);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  pvVar3 = operator_new(0x10);
  if ((pvVar3 != (void *)0x0) &&
     (puVar4 = (undefined4 *)FUN_0081d3a0(local_38), puVar4 != (undefined4 *)0x0)) {
    (**(code **)(*DAT_00b5a9f0 + 4))(0,puVar4);
    if (puVar4 != (undefined4 *)0x0) {
      (**(code **)*puVar4)(1);
    }
    uVar2 = FUN_00402220(&local_24,local_38 + -8,s_Loading_OK_009b5e60);
    FUN_00796d50(uVar2);
    if (0xf < uStack_c) {
      _free(local_20);
      return;
    }
    if (uStack_28 < 0x10) {
      return;
    }
    _free(unaff_EBX);
    return;
  }
  uVar2 = FUN_00402220(local_1c,local_38,s_Loading_FAIL_009b5e48);
  FUN_00796d50(uVar2);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_FALSE_009b5e58,5);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0050d960 @ 0x0050d960 ====

void FUN_0050d960(void)

{
  code *pcVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined4 *puVar4;
  void *unaff_EBX;
  undefined1 local_38 [2];
  undefined1 auStack_36 [2];
  undefined1 local_34;
  uint uStack_28;
  undefined4 local_24;
  void *local_20;
  undefined1 local_1c [4];
  void *local_18;
  uint uStack_c;
  undefined4 local_8;
  uint local_4;
  
  local_20 = (void *)0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_Partywar__009b5e6c,9);
  FUN_004020e0(s_Field_csv_009b5e78,9);
  uVar2 = FUN_00402220(local_1c,local_38,s_Loading____009b5e84);
  FUN_00796d50(uVar2);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  pvVar3 = operator_new(0x10);
  if ((pvVar3 != (void *)0x0) &&
     (puVar4 = (undefined4 *)FUN_0081d3a0(local_38), puVar4 != (undefined4 *)0x0)) {
    (**(code **)(*DAT_00b5a9f0 + 4))(1,puVar4);
    if (puVar4 != (undefined4 *)0x0) {
      (**(code **)*puVar4)(1);
    }
    uVar2 = FUN_00402220(&local_24,local_38 + -8,s_Loading_OK_009b5ea8);
    FUN_00796d50(uVar2);
    if (0xf < uStack_c) {
      _free(local_20);
      return;
    }
    if (uStack_28 < 0x10) {
      return;
    }
    _free(unaff_EBX);
    return;
  }
  uVar2 = FUN_00402220(local_1c,local_38,s_Loading_FAIL_009b5e90);
  FUN_00796d50(uVar2);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_FALSE_009b5ea0,5);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0050dad0 @ 0x0050dad0 ====

void FUN_0050dad0(void)

{
  code *pcVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined4 *puVar4;
  void *unaff_EBX;
  undefined1 local_38 [2];
  undefined1 auStack_36 [2];
  undefined1 local_34;
  uint uStack_28;
  undefined4 local_24;
  void *local_20;
  undefined1 local_1c [4];
  void *local_18;
  uint uStack_c;
  undefined4 local_8;
  uint local_4;
  
  local_20 = (void *)0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_Partywar__009b5eb4,9);
  FUN_004020e0(s_Name_csv_009b5ec0,8);
  uVar2 = FUN_00402220(local_1c,local_38,s_Loading____009b5ecc);
  FUN_00796d50(uVar2);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  pvVar3 = operator_new(0x10);
  if ((pvVar3 != (void *)0x0) &&
     (puVar4 = (undefined4 *)FUN_0081d3a0(local_38), puVar4 != (undefined4 *)0x0)) {
    (**(code **)(*DAT_00b5a9f0 + 4))(5,puVar4);
    if (puVar4 != (undefined4 *)0x0) {
      (**(code **)*puVar4)(1);
    }
    uVar2 = FUN_00402220(&local_24,local_38 + -8,s_Loading_OK_009b5ef0);
    FUN_00796d50(uVar2);
    if (0xf < uStack_c) {
      _free(local_20);
      return;
    }
    if (uStack_28 < 0x10) {
      return;
    }
    _free(unaff_EBX);
    return;
  }
  uVar2 = FUN_00402220(local_1c,local_38,s_Loading_FAIL_009b5ed8);
  FUN_00796d50(uVar2);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_FALSE_009b5ee8,5);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0050dc40 @ 0x0050dc40 ====

void FUN_0050dc40(void)

{
  code *pcVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined4 *puVar4;
  void *unaff_EBX;
  undefined1 local_38 [2];
  undefined1 auStack_36 [2];
  undefined1 local_34;
  uint uStack_28;
  undefined4 local_24;
  void *local_20;
  undefined1 local_1c [4];
  void *local_18;
  uint uStack_c;
  undefined4 local_8;
  uint local_4;
  
  local_20 = (void *)0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_Partywar__009b5efc,9);
  FUN_004020e0(s_Zeolite_csv_009b5f08,0xb);
  uVar2 = FUN_00402220(local_1c,local_38,s_Loading____009b5f14);
  FUN_00796d50(uVar2);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  pvVar3 = operator_new(0x10);
  if ((pvVar3 != (void *)0x0) &&
     (puVar4 = (undefined4 *)FUN_0081d3a0(local_38), puVar4 != (undefined4 *)0x0)) {
    (**(code **)(*DAT_00b5a9f0 + 4))(2,puVar4);
    if (puVar4 != (undefined4 *)0x0) {
      (**(code **)*puVar4)(1);
    }
    uVar2 = FUN_00402220(&local_24,local_38 + -8,s_Loading_OK_009b5f38);
    FUN_00796d50(uVar2);
    if (0xf < uStack_c) {
      _free(local_20);
      return;
    }
    if (uStack_28 < 0x10) {
      return;
    }
    _free(unaff_EBX);
    return;
  }
  uVar2 = FUN_00402220(local_1c,local_38,s_Loading_FAIL_009b5f20);
  FUN_00796d50(uVar2);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_FALSE_009b5f30,5);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0050ddb0 @ 0x0050ddb0 ====

undefined1 FUN_0050ddb0(void)

{
  FUN_0050d7f0();
  FUN_0050dad0();
  FUN_0050d960();
  FUN_0050dc40();
  return 1;
}


// ==== FUN_0050de10 @ 0x0050de10 ====

void FUN_0050de10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b5fe4;
  return;
}


// ==== FUN_0050de20 @ 0x0050de20 ====

undefined4 FUN_0050de20(void)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  void *pvVar3;
  undefined4 *puVar4;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 local_38;
  undefined1 local_34;
  uint local_24;
  undefined4 local_20;
  void *local_1c;
  void *local_18;
  uint local_8;
  uint local_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_Siege__009b5f54,6);
  FUN_004020e0(s_Config_csv_009b5f5c,10);
  uVar2 = FUN_00402220(&local_1c,&local_38,s_Loading____009b5f68);
  FUN_00796d50(uVar2);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  pvVar3 = operator_new(0x10);
  if ((pvVar3 != (void *)0x0) &&
     (puVar4 = (undefined4 *)FUN_0081d3a0(&local_38), puVar4 != (undefined4 *)0x0)) {
    (**(code **)(*DAT_00b5adb4 + 8))(puVar4);
    if (puVar4 != (undefined4 *)0x0) {
      (**(code **)*puVar4)(1);
    }
    uVar2 = FUN_00402220(&local_20,(int)register0x00000010 + -0x3c,s_Loading_OK_009b5f8c);
    FUN_00796d50(uVar2);
    if (0xf < local_8) {
      _free(local_1c);
      return extraout_EAX_02;
    }
    if (local_24 < 0x10) {
      return 1;
    }
    _free(local_38);
    return extraout_EAX_03;
  }
  uVar2 = FUN_00402220(&local_1c,&local_38,s_Loading_FAIL_009b5f74);
  FUN_00796d50(uVar2);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX_00;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_FALSE_009b5f84,5);
  FUN_00406880(&local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)();
    return uVar2;
  }
  _free(local_18);
  return extraout_EAX_01;
}


// ==== FUN_0050df90 @ 0x0050df90 ====

undefined4 FUN_0050df90(void)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  void *pvVar3;
  undefined4 *puVar4;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  void *unaff_EBX;
  undefined1 local_38 [2];
  undefined1 auStack_36 [2];
  undefined1 local_34;
  uint uStack_28;
  undefined4 local_24;
  void *local_20;
  undefined1 local_1c [4];
  void *local_18;
  uint uStack_c;
  undefined4 local_8;
  uint local_4;
  
  local_20 = (void *)0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_Siege__009b5f98,6);
  FUN_004020e0(s_Location_csv_009b5fa0,0xc);
  uVar2 = FUN_00402220(local_1c,local_38,s_Loading____009b5fb0);
  FUN_00796d50(uVar2);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  pvVar3 = operator_new(0x10);
  if ((pvVar3 != (void *)0x0) &&
     (puVar4 = (undefined4 *)FUN_0081d3a0(local_38), puVar4 != (undefined4 *)0x0)) {
    (**(code **)(*DAT_00b5a9f4 + 4))(puVar4,0);
    if (puVar4 != (undefined4 *)0x0) {
      (**(code **)*puVar4)(1);
    }
    uVar2 = FUN_00402220(&local_24,local_38 + -8,s_Loading_OK_009b5fd4);
    FUN_00796d50(uVar2);
    if (0xf < uStack_c) {
      _free(local_20);
      return extraout_EAX_02;
    }
    if (uStack_28 < 0x10) {
      return 1;
    }
    _free(unaff_EBX);
    return extraout_EAX_03;
  }
  uVar2 = FUN_00402220(local_1c,local_38,s_Loading_FAIL_009b5fbc);
  FUN_00796d50(uVar2);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX_00;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_FALSE_009b5fcc,5);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)();
    return uVar2;
  }
  _free(local_18);
  return extraout_EAX_01;
}


// ==== FUN_0050e100 @ 0x0050e100 ====

undefined1 FUN_0050e100(void)

{
  FUN_0050de20();
  FUN_0050df90();
  return 1;
}


// ==== FUN_0050e140 @ 0x0050e140 ====

void FUN_0050e140(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b608c;
  return;
}


// ==== FUN_0050e150 @ 0x0050e150 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_0050e150(void)

{
  char cVar1;
  code *pcVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  char *pcVar6;
  void *pvVar7;
  int iVar8;
  uint uVar9;
  byte *****pppppbVar10;
  undefined4 *puVar11;
  byte *pbVar12;
  bool bVar13;
  bool bVar14;
  byte *****apppppbStack_1048 [4];
  uint uStack_1038;
  uint uStack_1034;
  undefined1 auStack_1030 [4];
  void *pvStack_102c;
  undefined4 uStack_101c;
  uint uStack_1018;
  undefined1 auStack_1014 [4];
  void *pvStack_1010;
  undefined4 uStack_1000;
  uint uStack_ffc;
  undefined4 auStack_ff8 [256];
  char acStack_bf6 [2792];
  char acStack_10e [258];
  undefined4 uStack_c;
  
  uStack_c = 0x50e160;
  piVar4 = (int *)(**(code **)(*DAT_00b5ab14 + 0x10))();
  do {
    if (piVar4 == (int *)0x0) {
      return;
    }
    puVar5 = (undefined4 *)(**(code **)(*piVar4 + 0x10))();
    puVar11 = auStack_ff8;
    for (iVar8 = 0x3fb; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar11 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar11 = puVar11 + 1;
    }
    pcVar6 = acStack_bf6;
    uStack_1034 = 0xf;
    uStack_1038 = 0;
    apppppbStack_1048[0] = (byte *****)((uint)apppppbStack_1048[0] & 0xffffff00);
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_bf6,(int)pcVar6 - (int)(acStack_bf6 + 1));
    uVar3 = auStack_ff8[0];
    if (uStack_1038 == 0) {
LAB_0050e239:
      pcVar6 = acStack_10e;
      uStack_1018 = 0xf;
      uStack_101c = 0;
      pvStack_102c = (void *)((uint)pvStack_102c & 0xffffff00);
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_00401740(acStack_10e,(int)pcVar6 - (int)(acStack_10e + 1));
      pvVar7 = operator_new(0x10);
      if ((pvVar7 == (void *)0x0) ||
         (puVar5 = (undefined4 *)FUN_0081d3a0(auStack_1030), puVar5 == (undefined4 *)0x0)) {
        uStack_ffc = 0xf;
        uStack_1000 = 0;
        pvStack_1010 = (void *)((uint)pvStack_1010 & 0xffffff00);
        FUN_00401740(s_pLvlGapReader____NULL_009b6030,0x15);
        FUN_00406880(auStack_1014);
        if (uStack_ffc < 0x10) {
          uStack_ffc = 0xf;
          uStack_1000 = 0;
          pvStack_1010 = (void *)((uint)pvStack_1010 & 0xffffff00);
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        _free(pvStack_1010);
        return;
      }
      (**(code **)(*DAT_00b5a9f8 + 0xc))(uVar3,puVar5);
      if (puVar5 != (undefined4 *)0x0) {
        (**(code **)*puVar5)(1);
      }
      piVar4 = (int *)(**(code **)(*DAT_00b5ab14 + 0x14))();
      if (0xf < uStack_1018) {
        _free(pvStack_102c);
        return;
      }
      uStack_1018 = 0xf;
      uStack_101c = 0;
      pvStack_102c = (void *)((uint)pvStack_102c & 0xffffff00);
    }
    else {
      uVar9 = uStack_1038;
      if (10 < uStack_1038) {
        uVar9 = 0xb;
      }
      pppppbVar10 = apppppbStack_1048[0];
      if (uStack_1034 < 0x10) {
        pppppbVar10 = (byte *****)apppppbStack_1048;
      }
      bVar13 = false;
      iVar8 = 0;
      bVar14 = true;
      pbVar12 = &DAT_009b6024;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        bVar13 = *(byte *)pppppbVar10 < *pbVar12;
        bVar14 = *(byte *)pppppbVar10 == *pbVar12;
        pppppbVar10 = (byte *****)((int)pppppbVar10 + 1);
        pbVar12 = pbVar12 + 1;
      } while (bVar14);
      if (!bVar14) {
        iVar8 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
      }
      if (((iVar8 != 0) || (uStack_1038 < 0xb)) || (uStack_1038 != 0xb)) goto LAB_0050e239;
      piVar4 = (int *)(**(code **)(*DAT_00b5ab14 + 0x14))();
    }
    if (0xf < uStack_1034) {
      _free(apppppbStack_1048[0]);
      return;
    }
    uStack_1034 = 0xf;
    uStack_1038 = 0;
    apppppbStack_1048[0] = (byte *****)((uint)apppppbStack_1048[0] & 0xffffff00);
  } while( true );
}


// ==== FUN_0050e360 @ 0x0050e360 ====

undefined4 FUN_0050e360(void)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  void *pvVar2;
  undefined4 *puVar3;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 local_38;
  undefined1 local_34;
  uint local_24;
  undefined4 local_20;
  void *local_1c;
  void *local_18;
  uint uStack_8;
  uint local_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_maplist_csv_009b5ff0,0xb);
  uVar1 = FUN_00402220(&local_1c,&local_38,s_Loading____009b5ffc);
  FUN_00796d50(uVar1);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  pvVar2 = operator_new(0x10);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_0081d3a0(&local_38);
    if (puVar3 != (undefined4 *)0x0) goto LAB_0050e415;
  }
  uVar1 = FUN_00402220(&local_1c,&local_38,s_Loading_FAIL_009b6008);
  FUN_00796d50(uVar1);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX_00;
  }
LAB_0050e415:
  (**(code **)(*DAT_00b5a9f8 + 4))(puVar3);
  uVar1 = FUN_00402220(&local_20,(int)register0x00000010 + -0x3c,s_Loading_OK_009b6018);
  FUN_00796d50(uVar1);
  if (0xf < uStack_8) {
    _free(local_1c);
    return extraout_EAX_01;
  }
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  FUN_0050e150();
  if (local_24 < 0x10) {
    return 1;
  }
  _free(local_38);
  return extraout_EAX_02;
}


// ==== FUN_0050e490 @ 0x0050e490 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_0050e490(void)

{
  char cVar1;
  code *pcVar2;
  int *piVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 uVar6;
  void *pvVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  byte *****pppppbVar11;
  undefined4 *puVar12;
  byte *pbVar13;
  bool bVar14;
  bool bVar15;
  undefined1 auStack_1084 [4];
  byte *****apppppbStack_1080 [4];
  uint uStack_1070;
  uint uStack_106c;
  undefined1 auStack_1068 [4];
  void *pvStack_1064;
  undefined4 uStack_1054;
  uint uStack_1050;
  undefined1 auStack_104c [4];
  void *pvStack_1048;
  undefined4 uStack_1038;
  void *pvStack_1034;
  undefined4 uStack_1024;
  uint uStack_1020;
  undefined1 auStack_1014 [4];
  void *pvStack_1010;
  undefined4 uStack_1000;
  uint uStack_ffc;
  undefined4 auStack_ff8 [256];
  char acStack_bf6 [3050];
  undefined4 uStack_c;
  
  uStack_c = 0x50e4a0;
  piVar3 = (int *)(**(code **)(*DAT_00b5ab14 + 0x10))();
  do {
    if (piVar3 == (int *)0x0) {
      return;
    }
    puVar4 = (undefined4 *)(**(code **)(*piVar3 + 0x10))();
    puVar12 = auStack_ff8;
    for (iVar9 = 0x3fb; uVar8 = auStack_ff8[0], iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar12 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar12 = puVar12 + 1;
    }
    pcVar5 = acStack_bf6;
    uStack_106c = 0xf;
    uStack_1070 = 0;
    apppppbStack_1080[0] = (byte *****)((uint)apppppbStack_1080[0] & 0xffffff00);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_bf6,(int)pcVar5 - (int)(acStack_bf6 + 1));
    if (uStack_1070 == 0) {
LAB_0050e58d:
      FUN_004022a0(auStack_1068,s_MapRedCell__009b6054,auStack_1084);
      uVar6 = FUN_00402220(auStack_1014,auStack_1068,s_Loading____009b6060);
      FUN_00796d50(uVar6);
      if (0xf < uStack_ffc) {
        _free(pvStack_1010);
        return;
      }
      uStack_ffc = 0xf;
      uStack_1000 = 0;
      pvStack_1010 = (void *)((uint)pvStack_1010 & 0xffffff00);
      pvVar7 = operator_new(0x10);
      if ((pvVar7 == (void *)0x0) ||
         (puVar4 = (undefined4 *)FUN_0081d3a0(auStack_1068), puVar4 == (undefined4 *)0x0)) {
        pvStack_1034 = (void *)0xf;
        uStack_1038 = 0;
        pvStack_1048 = (void *)((uint)pvStack_1048 & 0xffffff00);
        FUN_00401740(s_pReader____NULL_009b606c,0xf);
        FUN_00406880(auStack_104c);
        if (pvStack_1034 < 0x10) {
          pvStack_1034 = (void *)0xf;
          uStack_1038 = 0;
          pvStack_1048 = (void *)((uint)pvStack_1048 & 0xffffff00);
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        _free(pvStack_1048);
        return;
      }
      (**(code **)(*DAT_00b5a9f8 + 8))(uVar8,puVar4);
      uVar8 = FUN_00402220(&uStack_1038,&uStack_1070,s_Loading_OK_009b607c);
      FUN_00796d50(uVar8);
      if (0xf < uStack_1020) {
        _free(pvStack_1034);
        return;
      }
      uStack_1020 = 0xf;
      uStack_1024 = 0;
      pvStack_1034 = (void *)((uint)pvStack_1034 & 0xffffff00);
      if (puVar4 != (undefined4 *)0x0) {
        (**(code **)*puVar4)(1);
      }
      piVar3 = (int *)(**(code **)(*DAT_00b5ab14 + 0x14))();
      if (0xf < uStack_1050) {
        _free(pvStack_1064);
        return;
      }
      uStack_1050 = 0xf;
      uStack_1054 = 0;
      pvStack_1064 = (void *)((uint)pvStack_1064 & 0xffffff00);
      if (0xf < uStack_106c) {
        _free(apppppbStack_1080[0]);
        return;
      }
    }
    else {
      uVar10 = uStack_1070;
      if (10 < uStack_1070) {
        uVar10 = 0xb;
      }
      pppppbVar11 = apppppbStack_1080[0];
      if (uStack_106c < 0x10) {
        pppppbVar11 = (byte *****)apppppbStack_1080;
      }
      bVar14 = false;
      iVar9 = 0;
      bVar15 = true;
      pbVar13 = &DAT_009b6048;
      do {
        if (uVar10 == 0) break;
        uVar10 = uVar10 - 1;
        bVar14 = *(byte *)pppppbVar11 < *pbVar13;
        bVar15 = *(byte *)pppppbVar11 == *pbVar13;
        pppppbVar11 = (byte *****)((int)pppppbVar11 + 1);
        pbVar13 = pbVar13 + 1;
      } while (bVar15);
      if (!bVar15) {
        iVar9 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
      }
      if (((iVar9 != 0) || (uStack_1070 < 0xb)) || (uStack_1070 != 0xb)) goto LAB_0050e58d;
      piVar3 = (int *)(**(code **)(*DAT_00b5ab14 + 0x14))();
      if (0xf < uStack_106c) {
        _free(apppppbStack_1080[0]);
        return;
      }
    }
    uStack_106c = 0xf;
    uStack_1070 = 0;
    apppppbStack_1080[0] = (byte *****)((uint)apppppbStack_1080[0] & 0xffffff00);
  } while( true );
}


// ==== FUN_0050e740 @ 0x0050e740 ====

void FUN_0050e740(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b60c4;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_009b5cb0;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_0050e780 @ 0x0050e780 ====

void FUN_0050e780(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b60c4;
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[1] = param_1;
  FUN_00401660(param_2,0,0xffffffff);
  *(undefined1 *)(in_ECX + 9) = param_3;
  return;
}


// ==== FUN_0050e7c0 @ 0x0050e7c0 ====

undefined4 FUN_0050e7c0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  void *pvVar3;
  undefined4 *puVar4;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int in_ECX;
  void *unaff_ESI;
  undefined4 uStack_1c;
  uint uStack_10;
  uint uStack_8;
  
  if (*(char *)(in_ECX + 0x24) == '\0') {
    (**(code **)(*DAT_00b5a6b0 + 0x14))();
  }
  else {
    (**(code **)(*DAT_00b5a6b0 + 0x10))(0);
  }
  (**(code **)(*DAT_00b5a688 + 0x48))();
  iVar1 = in_ECX + 8;
  uVar2 = FUN_00402220((int)register0x00000010 + -0x20,iVar1,s_Loading____009b6098);
  FUN_00796d50(uVar2);
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return extraout_EAX;
  }
  pvVar3 = operator_new(0x10);
  if (pvVar3 == (void *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)FUN_0081d3a0(iVar1);
    if (puVar4 != (undefined4 *)0x0) goto LAB_0050e86a;
  }
  uVar2 = FUN_00402220((int)register0x00000010 + -0x20,iVar1,s_Loading_FAIL_009b60a4);
  FUN_00796d50(uVar2);
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return extraout_EAX_00;
  }
LAB_0050e86a:
  (**(code **)(*DAT_00b5aa00 + 4))(in_ECX + 4,puVar4);
  uVar2 = FUN_00402220((int)register0x00000010 + -0x28,iVar1,s_Loading_OK_009b60b4);
  FUN_00796d50(uVar2);
  if (0xf < uStack_10) {
    _free(unaff_ESI);
    return extraout_EAX_01;
  }
  if (puVar4 != (undefined4 *)0x0) {
    (**(code **)*puVar4)(1);
  }
  (**(code **)(*DAT_00b5a6b0 + 0x14))();
  (**(code **)(*DAT_00b5a688 + 0x48))();
  return 1;
}


// ==== FUN_0050e8e0 @ 0x0050e8e0 ====

void FUN_0050e8e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b60c4;
  if (0xf < (uint)in_ECX[8]) {
    _free((void *)in_ECX[3]);
    return;
  }
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  *in_ECX = &PTR_FUN_009b5cb0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0050e940 @ 0x0050e940 ====

void FUN_0050e940(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b60ec;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_009b5cb0;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_0050e980 @ 0x0050e980 ====

void FUN_0050e980(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b60ec;
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[1] = param_1;
  FUN_00401660(param_2,0,0xffffffff);
  *(undefined1 *)(in_ECX + 9) = param_3;
  return;
}


// ==== FUN_0050e9c0 @ 0x0050e9c0 ====

undefined4 FUN_0050e9c0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  void *pvVar3;
  undefined4 *puVar4;
  undefined4 extraout_EAX_00;
  int in_ECX;
  void *unaff_ESI;
  undefined4 uStack_1c;
  uint uStack_10;
  uint uStack_8;
  
  if (*(char *)(in_ECX + 0x24) == '\0') {
    (**(code **)(*DAT_00b5a6b0 + 0x14))();
  }
  else {
    (**(code **)(*DAT_00b5a6b0 + 0x10))(0);
  }
  (**(code **)(*DAT_00b5a688 + 0x48))();
  iVar1 = in_ECX + 8;
  uVar2 = FUN_00402220((int)register0x00000010 + -0x20,iVar1,s_Loading____009b60d0);
  FUN_00796d50(uVar2);
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return extraout_EAX;
  }
  pvVar3 = operator_new(0x10);
  if (pvVar3 == (void *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)FUN_0081d3a0(iVar1);
  }
  (**(code **)(*DAT_00b5aa04 + 4))(in_ECX + 4,puVar4);
  uVar2 = FUN_00402220((int)register0x00000010 + -0x28,iVar1,s_Loading_OK_009b60dc);
  FUN_00796d50(uVar2);
  if (0xf < uStack_10) {
    _free(unaff_ESI);
    return extraout_EAX_00;
  }
  if (puVar4 != (undefined4 *)0x0) {
    (**(code **)*puVar4)(1);
  }
  (**(code **)(*DAT_00b5a6b0 + 0x14))();
  (**(code **)(*DAT_00b5a688 + 0x48))();
  return 1;
}


// ==== FUN_0050eab0 @ 0x0050eab0 ====

void FUN_0050eab0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b60ec;
  if (0xf < (uint)in_ECX[8]) {
    _free((void *)in_ECX[3]);
    return;
  }
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  *in_ECX = &PTR_FUN_009b5cb0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0050eb10 @ 0x0050eb10 ====

void FUN_0050eb10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6124;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_009b5cb0;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_0050eb50 @ 0x0050eb50 ====

void FUN_0050eb50(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6124;
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[1] = param_1;
  FUN_00401660(param_2,0,0xffffffff);
  *(undefined1 *)(in_ECX + 9) = param_3;
  return;
}


// ==== FUN_0050eb90 @ 0x0050eb90 ====

undefined4 FUN_0050eb90(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  void *pvVar3;
  undefined4 *puVar4;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int in_ECX;
  void *unaff_ESI;
  undefined4 uStack_1c;
  uint uStack_10;
  uint uStack_8;
  
  if (*(char *)(in_ECX + 0x24) == '\0') {
    (**(code **)(*DAT_00b5a6b0 + 0x14))();
  }
  else {
    (**(code **)(*DAT_00b5a6b0 + 0x10))(0);
  }
  (**(code **)(*DAT_00b5a688 + 0x48))();
  iVar1 = in_ECX + 8;
  uVar2 = FUN_00402220((int)register0x00000010 + -0x20,iVar1,s_Loading____009b60f8);
  FUN_00796d50(uVar2);
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return extraout_EAX;
  }
  pvVar3 = operator_new(0x10);
  if (pvVar3 == (void *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)FUN_0081d3a0(iVar1);
    if (puVar4 != (undefined4 *)0x0) goto LAB_0050ec3a;
  }
  uVar2 = FUN_00402220((int)register0x00000010 + -0x20,iVar1,s_Loading_FAIL_009b6104);
  FUN_00796d50(uVar2);
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return extraout_EAX_00;
  }
LAB_0050ec3a:
  (**(code **)(*DAT_00b5aa0c + 4))(in_ECX + 4,puVar4);
  uVar2 = FUN_00402220((int)register0x00000010 + -0x28,iVar1,s_Loading_OK_009b6114);
  FUN_00796d50(uVar2);
  if (0xf < uStack_10) {
    _free(unaff_ESI);
    return extraout_EAX_01;
  }
  if (puVar4 != (undefined4 *)0x0) {
    (**(code **)*puVar4)(1);
  }
  (**(code **)(*DAT_00b5a6b0 + 0x14))();
  (**(code **)(*DAT_00b5a688 + 0x48))();
  return 1;
}


// ==== FUN_0050ecb0 @ 0x0050ecb0 ====

void FUN_0050ecb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6124;
  if (0xf < (uint)in_ECX[8]) {
    _free((void *)in_ECX[3]);
    return;
  }
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  *in_ECX = &PTR_FUN_009b5cb0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0050ed10 @ 0x0050ed10 ====

void FUN_0050ed10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6164;
  return;
}


// ==== FUN_0050ed20 @ 0x0050ed20 ====

undefined4 FUN_0050ed20(void)

{
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ItemShape_Loading____009b6130,0x14);
  FUN_00796d50(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  (**(code **)(*DAT_00b5a6dc + 4))();
  (**(code **)(*DAT_00b5a6d8 + 4))();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ItemShape_Loading_OK_009b6148,0x14);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    return 1;
  }
  _free(local_18);
  return extraout_EAX_00;
}


// ==== FUN_0050edd0 @ 0x0050edd0 ====

void FUN_0050edd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b618c;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_009b5cb0;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_0050ee10 @ 0x0050ee10 ====

void FUN_0050ee10(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b618c;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[1] = param_1;
  FUN_00401660(param_2,0,0xffffffff);
  *(undefined1 *)(in_ECX + 9) = 0;
  return;
}


// ==== FUN_0050ee50 @ 0x0050ee50 ====

undefined4 FUN_0050ee50(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  void *unaff_EDI;
  undefined1 local_1c [2];
  undefined1 auStack_1a [2];
  void *local_18;
  uint uStack_c;
  uint local_4;
  
  if (*(char *)(in_ECX + 0x24) != '\x01') {
    iVar1 = in_ECX + 8;
    uVar2 = FUN_00402220(local_1c,iVar1,s_Loading____009b6170);
    FUN_00796d50(uVar2);
    if (0xf < local_4) {
      _free(local_18);
      return extraout_EAX;
    }
    (**(code **)(*DAT_00b5ace8 + 4))(iVar1,*(undefined4 *)(in_ECX + 4));
    uVar2 = FUN_00402220(local_1c + -8,iVar1,s_Loading_OK_009b617c);
    FUN_00796d50(uVar2);
    if (0xf < uStack_c) {
      _free(unaff_EDI);
      return extraout_EAX_00;
    }
    *(undefined1 *)(in_ECX + 0x24) = 1;
  }
  return 1;
}


// ==== FUN_0050eee0 @ 0x0050eee0 ====

void FUN_0050eee0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b618c;
  if (0xf < (uint)in_ECX[8]) {
    _free((void *)in_ECX[3]);
    return;
  }
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  *in_ECX = &PTR_FUN_009b5cb0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0050ef40 @ 0x0050ef40 ====

void FUN_0050ef40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b61d4;
  return;
}


// ==== FUN_0050ef60 @ 0x0050ef60 ====

undefined4 FUN_0050ef60(void)

{
  undefined4 extraout_EAX;
  int iVar1;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_28 [8];
  undefined1 auStack_20 [4];
  void *local_1c;
  void *local_18;
  undefined4 uStack_c;
  uint local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_Formula_ini_Read____009b6198,0x13);
  FUN_00796d50(&local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_share_formula_ini_009b61ac,0x11);
  iVar1 = FUN_0050f070(&local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX_00;
  }
  FUN_004cc940(iVar1);
  (**(code **)(*DAT_00b5a6b8 + 8))(local_28);
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(s_Formula_ini_OK_009b61c0,0xe);
  FUN_00796d50(auStack_20);
  if (local_8 < 0x10) {
    FUN_004cc8d0();
    return 1;
  }
  _free(local_1c);
  return extraout_EAX_01;
}


// ==== FUN_0050f070 @ 0x0050f070 ====

undefined4 FUN_0050f070(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  void *local_20;
  undefined1 local_1c;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar1 = DAT_00b5a7cc;
  local_c = 0;
  local_1c = 0;
  local_8 = 0xf;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0xb;
  uVar2 = (**(code **)(*piVar1 + 8))(&local_20);
  if (local_c < 0x10) {
    return uVar2;
  }
  _free(local_20);
  return extraout_EAX;
}


// ==== FUN_0050f0d0 @ 0x0050f0d0 ====

void FUN_0050f0d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b61e0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_0050f0f0 @ 0x0050f0f0 ====

void FUN_0050f0f0(uint *param_1)

{
  int in_ECX;
  
  if ((*param_1 < 0x3e9) &&
     (*(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + *param_1,
     *(uint *)(in_ECX + 4) < *(uint *)(in_ECX + 8))) {
    *(undefined1 *)(in_ECX + 0xc) = 0;
  }
  return;
}


// ==== FUN_0050f180 @ 0x0050f180 ====

void FUN_0050f180(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x10) != 1) || (*(char *)(in_ECX + 0xc) != '\x01')) {
    *(undefined4 *)(in_ECX + 4) = param_1;
    *(undefined4 *)(in_ECX + 8) = 0;
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_009b61fc;
    }
    FUN_00797a20(puVar1);
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_009b61e8;
    }
    *(undefined1 *)(puVar1 + 1) = 1;
    puVar1[2] = param_1;
    FUN_00797a20(puVar1);
    *(undefined4 *)(in_ECX + 0x10) = 1;
    *(undefined1 *)(in_ECX + 0xc) = 1;
  }
  return;
}


// ==== FUN_0050f200 @ 0x0050f200 ====

void FUN_0050f200(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x10) != 2) || (*(char *)(in_ECX + 0xc) != '\x01')) {
    *(undefined4 *)(in_ECX + 4) = param_1;
    *(undefined4 *)(in_ECX + 8) = 0;
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_009b61fc;
    }
    FUN_00797a20(puVar1);
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_009b61e8;
    }
    *(undefined1 *)(puVar1 + 1) = 0;
    puVar1[2] = param_1;
    FUN_00797a20(puVar1);
    *(undefined4 *)(in_ECX + 0x10) = 2;
    *(undefined1 *)(in_ECX + 0xc) = 1;
  }
  return;
}


// ==== FUN_0050f280 @ 0x0050f280 ====

undefined4 FUN_0050f280(void)

{
  return 0x30050012;
}


// ==== FUN_0050f290 @ 0x0050f290 ====

undefined4 FUN_0050f290(void)

{
  return 0x30050010;
}


// ==== FUN_0050f2a0 @ 0x0050f2a0 ====

undefined4 FUN_0050f2a0(void)

{
  return 0x30050011;
}


// ==== FUN_0050f2b0 @ 0x0050f2b0 ====

void FUN_0050f2b0(byte param_1)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b61e0;
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b6210;
  }
  FUN_00797a20(puVar1);
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0050f300 @ 0x0050f300 ====

undefined4 FUN_0050f300(void)

{
  return 0x70800000;
}


// ==== FUN_0050f310 @ 0x0050f310 ====

undefined4 FUN_0050f310(void)

{
  return 0x70230001;
}


// ==== FUN_0050f320 @ 0x0050f320 ====

undefined4 FUN_0050f320(void)

{
  return 0x70290001;
}


// ==== FUN_0050f330 @ 0x0050f330 ====

undefined4 FUN_0050f330(void)

{
  return 0x70290004;
}


// ==== FUN_0050f340 @ 0x0050f340 ====

undefined4 FUN_0050f340(void)

{
  return 0x70290005;
}


// ==== FUN_0050f350 @ 0x0050f350 ====

undefined4 FUN_0050f350(void)

{
  return 0x70290006;
}


// ==== FUN_0050f360 @ 0x0050f360 ====

undefined4 FUN_0050f360(void)

{
  return 0x70290007;
}


// ==== FUN_0050f370 @ 0x0050f370 ====

void FUN_0050f370(void)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*DAT_00b5a748 + 0x14))(0xd);
    if (cVar1 == '\x01') {
      (**(code **)(*DAT_00b5acb8 + 8))();
    }
    cVar1 = (**(code **)(*DAT_00b5a748 + 0x14))(7);
    if (cVar1 == '\x01') {
      (**(code **)(*DAT_00b5a78c + 0x20))();
    }
    cVar1 = (**(code **)(*DAT_00b5a748 + 0x14))(0xe);
    if (cVar1 == '\x01') {
      (**(code **)(*DAT_00b5ae98 + 8))();
    }
    cVar1 = (**(code **)(*DAT_00b5a748 + 0x14))(2);
    if (cVar1 == '\x01') {
      (**(code **)(*DAT_00b5a7b4 + 0x2c))();
    }
    cVar1 = (**(code **)(*DAT_00b5a748 + 0x14))(0x2e);
    if (cVar1 == '\x01') {
      (**(code **)(*DAT_00b5aca8 + 0x34))();
    }
    cVar1 = (**(code **)(*DAT_00b5a748 + 0x14))(3);
    if (cVar1 == '\x01') {
                    /* WARNING: Could not recover jumptable at 0x0050f428. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*DAT_00b5ac38 + 0x24))();
      return;
    }
  }
  return;
}


// ==== FUN_0050f430 @ 0x0050f430 ====

void FUN_0050f430(void)

{
  char cVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined1 auStack_2 [2];
  
  cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
  puVar2 = (undefined2 *)(**(code **)(*DAT_00b5ae54 + 0x24))();
  if (cVar1 != '\0') {
    if ((char)*puVar2 != '\0') {
      (**(code **)(*DAT_00b5ad0c + 0xc))();
    }
    (**(code **)(*DAT_00b5add0 + 8))();
    (**(code **)(*DAT_00b5add0 + 0x14))();
    return;
  }
  uVar3 = (**(code **)(*DAT_00b5ae14 + 0x18))();
  (**(code **)(*DAT_00b5ad0c + 0xc))();
  (**(code **)(*DAT_00b5ad54 + 0x60))();
  (**(code **)(*DAT_00b5ae84 + 0x10))();
  (**(code **)(*DAT_00b5ae84 + 0xc))();
  (**(code **)(*DAT_00b5add0 + 8))();
  (**(code **)(*DAT_00b5add0 + 0x14))();
  (**(code **)(*DAT_00b5a790 + 8))();
  (**(code **)(*DAT_00b5ae3c + 0x20))();
  (**(code **)(*DAT_00b5ae3c + 0x28))();
  (**(code **)(*DAT_00b5aca8 + 0x94))();
  cVar1 = (**(code **)(*DAT_00b5a9e4 + 0x14))();
  if (cVar1 != '\0') {
    (**(code **)(*DAT_00b5a9e4 + 0x1c))();
  }
  iVar4 = (**(code **)(*DAT_00b5a6e4 + 8))();
  if (*(char *)(iVar4 + 4) == '\x01') {
    (**(code **)(*DAT_00b5ae88 + 8))();
  }
  iVar4 = (**(code **)(*DAT_00b5a6e4 + 8))();
  if (*(char *)(iVar4 + 0xc) == '\x01') {
    puVar5 = operator_new(4);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = &PTR_FUN_009b6288;
    }
    FUN_00797a20(puVar5);
  }
  iVar4 = (**(code **)(*DAT_00b5a6e4 + 8))();
  if (*(char *)(iVar4 + 0xd) == '\x01') {
    puVar5 = operator_new(4);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = &PTR_FUN_009b6260;
    }
    FUN_00797a20(puVar5);
  }
  iVar4 = (**(code **)(*DAT_00b5a6e4 + 8))();
  if (*(char *)(iVar4 + 0x40) == '\x01') {
    puVar5 = operator_new(4);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = &PTR_FUN_009b6224;
    }
    FUN_00797a20(puVar5);
  }
  iVar4 = (**(code **)(*DAT_00b5a7b4 + 0x40))();
  if (iVar4 != 0) {
    (**(code **)(*DAT_00b5a7b4 + 0x34))();
  }
  cVar1 = (**(code **)(*DAT_00b5add0 + 0x44))(uVar3);
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*DAT_00b5ada4 + 0x28))();
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5ada4 + 4))(auStack_2 + -6,0);
    }
  }
  (**(code **)(*DAT_00b5ac3c + 0x18))();
  (**(code **)(*DAT_00b5ae6c + 4))();
  return;
}


// ==== FUN_0050f640 @ 0x0050f640 ====

void FUN_0050f640(void)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uStack_4;
  
  (**(code **)(*DAT_00b5ad0c + 0x10))();
  (**(code **)(*DAT_00b5ad54 + 100))();
  (**(code **)(*DAT_00b5a78c + 0x24))();
  (**(code **)(*DAT_00b5a7b4 + 0x30))();
  (**(code **)(*DAT_00b5a7b4 + 0x38))();
  (**(code **)(*DAT_00b5ae98 + 4))();
  (**(code **)(*DAT_00b5ae6c + 8))();
  (**(code **)(*DAT_00b5ae6c + 0x18))();
  (**(code **)(*DAT_00b5ac38 + 0x2c))();
  (**(code **)(*DAT_00b5acb8 + 0xc))();
  (**(code **)(*DAT_00b5ae94 + 0xc))();
  (**(code **)(*DAT_00b5add0 + 0xc))();
  (**(code **)(*DAT_00b5add0 + 0x14))();
  (**(code **)(*DAT_00b5ae90 + 0x10))();
  (**(code **)(*DAT_00b5ae88 + 0xc))();
  (**(code **)(*DAT_00b5aca8 + 0x40))();
  (**(code **)(*DAT_00b5ae84 + 0x14))();
  (**(code **)(*DAT_00b5ae74 + 0xc))();
  (**(code **)(*DAT_00b5ae74 + 0x14))();
  cVar1 = (**(code **)(*DAT_00b5a9e4 + 0x14))();
  if (cVar1 != '\0') {
    (**(code **)(*DAT_00b5a9e4 + 0x20))();
  }
  cVar1 = (**(code **)(*DAT_00b5ae3c + 0x4c))();
  if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5ae3c + 0x1c))();
  }
  (**(code **)(*DAT_00b5ae3c + 0x2c))();
  (**(code **)(*DAT_00b5ae3c + 0x24))();
  cVar1 = (**(code **)(*DAT_00b5adb8 + 0x10))();
  if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5adb8 + 0xc))();
  }
  (**(code **)(*DAT_00b5adc4 + 0x1c))();
  puVar2 = operator_new(4);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009b6238;
  }
  FUN_00797a20(puVar2);
  puVar2 = operator_new(4);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009b624c;
  }
  FUN_00797a20(puVar2);
  (**(code **)(*DAT_00b5ac94 + 0x2c))();
  (**(code **)(*DAT_00b5ac94 + 0x30))();
  (**(code **)(*DAT_00b5ac94 + 0x40))();
  (**(code **)(*DAT_00b5ae64 + 0xc))();
  (**(code **)(*DAT_00b5ae64 + 0x14))();
  (**(code **)(*DAT_00b5ae64 + 0x1c))();
  uVar4 = 1;
  do {
    uStack_4 = uVar4;
    cVar1 = (**(code **)(*DAT_00b5ada4 + 0x1c))(&uStack_4);
    if (cVar1 != '\0') {
      uStack_4 = uVar4;
      (**(code **)(*DAT_00b5ada4 + 8))(&uStack_4);
    }
    uVar4 = uVar4 * 2;
  } while (uVar4 < 0x20);
  iVar3 = (**(code **)(*DAT_00b5a6e4 + 8))();
  if (*(char *)(iVar3 + 0xc) == '\x01') {
    puVar2 = operator_new(4);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009b629c;
    }
    FUN_00797a20(puVar2);
  }
  iVar3 = (**(code **)(*DAT_00b5a6e4 + 8))();
  if (*(char *)(iVar3 + 0xd) == '\x01') {
    puVar2 = operator_new(4);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = &PTR_FUN_009b6274;
      FUN_00797a20(puVar2);
      return;
    }
    FUN_00797a20(0);
  }
  return;
}


// ==== FUN_0050f8d0 @ 0x0050f8d0 ====

void FUN_0050f8d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6324;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[5] = 1;
  in_ECX[6] = 1;
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined1 *)((int)in_ECX + 0x11) = 0;
  return;
}


// ==== FUN_0050f960 @ 0x0050f960 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050f960(int param_1)

{
  int in_ECX;
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = 0.0;
  fVar1 = 0.0;
  fVar3 = 0.0;
  if (*(int *)(in_ECX + 8) == 1) {
    fVar2 = (float)*(int *)(param_1 + 4);
    if (*(int *)(param_1 + 4) < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar2 = fVar2 * _DAT_009b632c;
  }
  else if (*(int *)(in_ECX + 8) == 2) {
    fVar2 = (float)*(int *)(param_1 + 4);
    if (*(int *)(param_1 + 4) < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar2 = fVar2 * DAT_0099d0ec;
  }
  if (*(int *)(in_ECX + 4) == 1) {
    fVar1 = (float)*(int *)(param_1 + 4);
    if (*(int *)(param_1 + 4) < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    fVar1 = fVar1 * _DAT_009b632c;
  }
  else if (*(int *)(in_ECX + 4) == 2) {
    fVar1 = (float)*(int *)(param_1 + 4);
    if (*(int *)(param_1 + 4) < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    fVar1 = fVar1 * DAT_0099d0ec;
  }
  if (*(int *)(in_ECX + 0xc) == 1) {
    fVar3 = (float)*(int *)(param_1 + 4);
    if (*(int *)(param_1 + 4) < 0) {
      fVar3 = fVar3 + _DAT_0099d104;
    }
    fVar3 = fVar3 * _DAT_009b632c;
  }
  else if (*(int *)(in_ECX + 0xc) == 2) {
    fVar3 = (float)*(int *)(param_1 + 4);
    if (*(int *)(param_1 + 4) < 0) {
      fVar3 = fVar3 + _DAT_0099d104;
    }
    fVar3 = fVar3 * DAT_0099d0ec;
  }
  (**(code **)(*DAT_00b5aea4 + 0x10))(fVar2,fVar1,fVar1,fVar2,fVar3);
                    /* WARNING: Could not recover jumptable at 0x0050fa63. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5aea4 + 0x1c))(fVar1);
  return;
}


// ==== FUN_0050fa70 @ 0x0050fa70 ====

void FUN_0050fa70(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a74c + 0xc))(param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))();
  }
  return;
}


// ==== FUN_0050fa90 @ 0x0050fa90 ====

void FUN_0050fa90(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x18);
  iVar2 = *(int *)(in_ECX + 0x14);
  puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    *puVar4 = &PTR_FUN_009b62c0;
  }
  puVar4[1] = iVar1 * 3 + iVar2;
  FUN_00797a20(puVar4);
  cVar3 = (**(code **)(*DAT_00b5aee4 + 0x18))();
  if (cVar3 != '\0') {
    (**(code **)(*DAT_00b5aee4 + 0x20))(1);
  }
  return;
}


// ==== FUN_0050fae0 @ 0x0050fae0 ====

undefined4 FUN_0050fae0(int param_1)

{
  int in_ECX;
  
  switch(*(undefined4 *)(param_1 + 4)) {
  case 0x10:
    *(undefined1 *)(in_ECX + 0x11) = 0;
    break;
  case 0x11:
    *(undefined1 *)(in_ECX + 0x10) = 0;
    return 0;
  case 0x21:
    if (*(int *)(in_ECX + 0xc) == 2) {
      *(undefined4 *)(in_ECX + 0xc) = 0;
      return 0;
    }
    break;
  case 0x22:
    if (*(int *)(in_ECX + 0xc) == 1) {
      *(undefined4 *)(in_ECX + 0xc) = 0;
      return 0;
    }
    break;
  case 0x25:
    if (*(int *)(in_ECX + 8) == 1) {
      *(undefined4 *)(in_ECX + 8) = 0;
      return 1;
    }
    return 1;
  case 0x26:
    if (*(int *)(in_ECX + 4) == 1) {
      *(undefined4 *)(in_ECX + 4) = 0;
      return 0;
    }
    break;
  case 0x27:
    if (*(int *)(in_ECX + 8) == 2) {
      *(undefined4 *)(in_ECX + 8) = 0;
    }
    return 1;
  case 0x28:
    if (*(int *)(in_ECX + 4) == 2) {
      *(undefined4 *)(in_ECX + 4) = 0;
      return 0;
    }
    break;
  case 0x41:
    if (*(int *)(in_ECX + 0x14) == 0) {
      *(undefined4 *)(in_ECX + 0x14) = 1;
      FUN_0050fa90();
      return 1;
    }
    return 1;
  case 0x44:
    if (*(int *)(in_ECX + 0x14) == 2) {
      *(undefined4 *)(in_ECX + 0x14) = 1;
      FUN_0050fa90();
    }
    return 1;
  case 0x53:
    if (*(int *)(in_ECX + 0x18) == 2) {
      *(undefined4 *)(in_ECX + 0x18) = 1;
      FUN_0050fa90();
      return 1;
    }
    return 1;
  case 0x57:
    if (*(int *)(in_ECX + 0x18) == 0) {
      *(undefined4 *)(in_ECX + 0x18) = 1;
      FUN_0050fa90();
      return 1;
    }
    return 1;
  }
  return 0;
}


// ==== FUN_0050fc60 @ 0x0050fc60 ====

void FUN_0050fc60(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 uStack_24;
  int *piStack_20;
  undefined1 auStack_1c [12];
  int *local_10;
  undefined4 local_c;
  
  local_10 = (int *)FUN_00510650();
  *(undefined1 *)((int)local_10 + 0x15) = 1;
  local_10[1] = (int)local_10;
  *local_10 = (int)local_10;
  local_10[2] = (int)local_10;
  local_c = 0;
  piVar2 = (int *)(**(code **)(*DAT_00b5a7a0 + 0x30))();
  piVar7 = local_10;
  while (local_10 = piVar7, piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x14))();
    uStack_24 = *(undefined4 *)(iVar3 + 0x10);
    piStack_20 = piVar2;
    FUN_00510a60(auStack_1c,&uStack_24);
    piVar2 = (int *)(**(code **)(*DAT_00b5a7a0 + 0x34))();
    piVar7 = local_10;
  }
  if (piVar7 != (int *)*piVar7) {
    do {
      if (*(char *)((int)piVar7 + 0x15) == '\0') {
        piVar2 = (int *)*piVar7;
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar1 = *(char *)(piVar2[2] + 0x15);
          piVar5 = (int *)piVar2[2];
          while (cVar1 == '\0') {
            cVar1 = *(char *)(piVar5[2] + 0x15);
            piVar2 = piVar5;
            piVar5 = (int *)piVar5[2];
          }
        }
        else {
          piVar5 = (int *)piVar7[1];
          piVar2 = piVar7;
          if (*(char *)(piVar7[1] + 0x15) == '\0') {
            do {
              piVar4 = piVar5;
              piVar5 = piVar4;
              if (piVar2 != (int *)*piVar4) break;
              piVar5 = (int *)piVar4[1];
              piVar2 = piVar4;
            } while (*(char *)((int)piVar5 + 0x15) == '\0');
            if (*(char *)((int)piVar5 + 0x15) == '\0') {
              piVar2 = piVar5;
            }
          }
        }
      }
      else {
        piVar2 = (int *)piVar7[2];
      }
      piVar2 = (int *)(**(code **)(*(int *)piVar2[4] + 0x44))();
      if ((piVar2 != (int *)0x0) && (cVar1 = (**(code **)(*piVar2 + 0x10))(), cVar1 == '\x01'))
      goto LAB_0050fdf9;
      if (*(char *)((int)piVar7 + 0x15) == '\0') {
        piVar2 = (int *)*piVar7;
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar1 = *(char *)(piVar2[2] + 0x15);
          piVar5 = (int *)piVar2[2];
          while (piVar7 = piVar2, cVar1 == '\0') {
            cVar1 = *(char *)(piVar5[2] + 0x15);
            piVar2 = piVar5;
            piVar5 = (int *)piVar5[2];
          }
        }
        else {
          piVar2 = (int *)piVar7[1];
          if (*(char *)(piVar7[1] + 0x15) == '\0') {
            do {
              piVar5 = piVar2;
              piVar2 = piVar5;
              if (piVar7 != (int *)*piVar5) break;
              piVar2 = (int *)piVar5[1];
              piVar7 = piVar5;
            } while (*(char *)((int)piVar2 + 0x15) == '\0');
            if (*(char *)((int)piVar2 + 0x15) == '\0') {
              piVar7 = piVar2;
            }
          }
        }
      }
      else {
        piVar7 = (int *)piVar7[2];
      }
    } while (piVar7 != (int *)*local_10);
  }
  iVar3 = (**(code **)(*DAT_00b5a74c + 0xc))(0x23);
  if (iVar3 == 0) {
    puVar6 = operator_new(4);
    if (puVar6 != (undefined4 *)0x0) {
      *puVar6 = &PTR_FUN_009b6310;
      goto LAB_0050fdf0;
    }
  }
  else {
    puVar6 = operator_new(4);
    if (puVar6 != (undefined4 *)0x0) {
      *puVar6 = &PTR_FUN_009b6238;
      goto LAB_0050fdf0;
    }
  }
  puVar6 = (undefined4 *)0x0;
LAB_0050fdf0:
  FUN_00797a20(puVar6);
LAB_0050fdf9:
  FUN_005107c0(&uStack_24,*local_10,local_10);
  _free(local_10);
  return;
}


// ==== FUN_0050fe30 @ 0x0050fe30 ====

undefined1 FUN_0050fe30(int param_1)

{
  char cVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int in_ECX;
  undefined1 auStack_68 [20];
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_36 [54];
  
  cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
  if (cVar1 != '\0') {
    switch(*(undefined4 *)(param_1 + 4)) {
    case 0x10:
    case 0x11:
    case 0x1b:
    case 0x21:
    case 0x22:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x41:
    case 0x44:
    case 0x4d:
    case 0x53:
    case 0x57:
    case 0x7b:
      break;
    default:
      return 0;
    }
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 4) = 0;
  switch(*(undefined4 *)(param_1 + 4)) {
  case 0x10:
    *(undefined1 *)(in_ECX + 0x11) = 1;
    return 0;
  case 0x11:
    *(undefined1 *)(in_ECX + 0x10) = 1;
    return 0;
  default:
    return 0;
  case 0x1b:
    break;
  case 0x21:
    *(undefined4 *)(in_ECX + 0xc) = 2;
    return 0;
  case 0x22:
    *(undefined4 *)(in_ECX + 0xc) = 1;
    return 0;
  case 0x25:
    *(undefined4 *)(in_ECX + 8) = 1;
    return 1;
  case 0x26:
    *(undefined4 *)(in_ECX + 4) = 1;
    return 0;
  case 0x27:
    *(undefined4 *)(in_ECX + 8) = 2;
    return 1;
  case 0x28:
    *(undefined4 *)(in_ECX + 4) = 2;
    return 0;
  case 0x41:
    *(undefined4 *)(in_ECX + 0x14) = 0;
    FUN_0050fa90();
    return 1;
  case 0x43:
    cVar1 = (**(code **)(*DAT_00b5ae98 + 0x20))();
    if (cVar1 == '\0') {
      (**(code **)(*DAT_00b5ae98 + 8))();
      return 1;
    }
    uStack_4c = 0x50ff93;
    FUN_0050fa70();
    return 1;
  case 0x44:
    *(undefined4 *)(in_ECX + 0x14) = 2;
    FUN_0050fa90();
    return 1;
  case 0x45:
    (**(code **)(*DAT_00b5a97c + 0xc))();
    piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    (**(code **)(*piVar2 + 0x28))();
    uStack_4c = 0x50ff28;
    pvVar3 = operator_new(0x18);
    if (pvVar3 == (void *)0x0) {
      uStack_4c = 0x50ff57;
      FUN_00797a20();
      return 1;
    }
    uStack_4c = 0x50ff3b;
    FUN_00510600();
    uStack_4c = 0x50ff41;
    FUN_00797a20();
    return 1;
  case 0x46:
    cVar1 = (**(code **)(*DAT_00b5ae3c + 0x4c))();
    if (cVar1 == '\x01') {
      (**(code **)(*DAT_00b5ae3c + 0x1c))();
      return 1;
    }
    (**(code **)(*DAT_00b5ae3c + 0x18))();
    return 1;
  case 0x47:
    cVar1 = (**(code **)(*DAT_00b5aca8 + 0x78))();
    if (cVar1 == '\x01') {
      uStack_4c = 0x50ffef;
      FUN_0050fa70();
      return 1;
    }
    (**(code **)(*DAT_00b5aca8 + 0x34))();
    return 1;
  case 0x48:
    cVar1 = (**(code **)(*DAT_00b5ae94 + 0x10))();
    if (cVar1 == '\x01') {
      (**(code **)(*DAT_00b5ae94 + 0xc))();
      return 1;
    }
    (**(code **)(*DAT_00b5ae94 + 8))();
    return 1;
  case 0x4b:
    cVar1 = (**(code **)(*DAT_00b5acb8 + 0x10))();
    if (cVar1 == '\0') {
      (**(code **)(*DAT_00b5acb8 + 8))();
      return 1;
    }
    uStack_4c = 0x50ffcc;
    FUN_0050fa70();
    return 1;
  case 0x4c:
    cVar1 = (**(code **)(*DAT_00b5aee4 + 0x18))();
    if (cVar1 != '\0') {
      uStack_4c = 0x5102d1;
      (**(code **)(*DAT_00b5aee4 + 0x20))();
    }
    (**(code **)(*DAT_00b5aeec + 0xc))();
    return 1;
  case 0x4d:
    cVar1 = (**(code **)(*DAT_00b5add0 + 0x34))();
    if (cVar1 == '\0') {
      (**(code **)(*DAT_00b5add0 + 0x10))();
    }
    else {
      (**(code **)(*DAT_00b5add0 + 0x14))();
    }
    uStack_4c = 0x510174;
    puVar5 = operator_new(8);
    if (puVar5 == (undefined4 *)0x0) {
      uStack_4c = 0x5101b2;
      FUN_00797a20();
      return 1;
    }
    cVar1 = (**(code **)(*DAT_00b5add0 + 0x34))();
    *puVar5 = &PTR_FUN_009b62e8;
    *(bool *)(puVar5 + 1) = cVar1 == '\0';
    uStack_4c = 0x51019c;
    FUN_00797a20();
    return 1;
  case 0x50:
    cVar1 = (**(code **)(*DAT_00b5a7b4 + 0x3c))();
    if (cVar1 == '\x01') {
      uStack_4c = 0x51005d;
      FUN_0050fa70();
      return 1;
    }
    (**(code **)(*DAT_00b5a7b4 + 0x2c))();
    return 1;
  case 0x51:
    cVar1 = (**(code **)(*DAT_00b5ac38 + 0x28))();
    if (cVar1 == '\x01') {
      uStack_4c = 0x5100f6;
      FUN_0050fa70();
      return 1;
    }
    (**(code **)(*DAT_00b5ac38 + 0x24))();
    return 1;
  case 0x53:
    *(undefined4 *)(in_ECX + 0x18) = 2;
    FUN_0050fa90();
    return 1;
  case 0x55:
    if (((*(char *)(in_ECX + 0x10) != '\0') &&
        (cVar1 = (**(code **)(*DAT_00b5adb8 + 0x10))(), cVar1 != '\0')) &&
       (iVar4 = (**(code **)(*DAT_00b5adc0 + 0x1c))(), iVar4 == 0)) {
      puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        *puVar5 = &PTR_FUN_009b62d4;
      }
      uVar6 = (**(code **)(*DAT_00b5adc0 + 0x18))();
      puVar5[1] = uVar6;
      uStack_4c = 0x5100d0;
      FUN_00797a20();
    }
    return 1;
  case 0x57:
    *(undefined4 *)(in_ECX + 0x18) = 0;
    FUN_0050fa90();
    return 1;
  case 0x58:
    (**(code **)(*DAT_00b5ad54 + 0x4c))();
    return 1;
  case 0x5a:
    (**(code **)(*DAT_00b5ad54 + 0x50))();
    return 1;
  case 0x7b:
    uStack_4c = 0x510265;
    FUN_00401830();
    uStack_4c = 0x510275;
    (**(code **)(*DAT_00b5a688 + 4))();
                    /* WARNING: Subroutine does not return */
    uStack_4c = 0x51027e;
    FUN_00446f10();
  case 0xbf:
    cVar1 = (**(code **)(*DAT_00b5aee4 + 0x18))();
    if (cVar1 != '\0') {
      uStack_4c = 0x510303;
      (**(code **)(*DAT_00b5aee4 + 0x20))();
    }
    cVar1 = (**(code **)(*DAT_00b5adc4 + 0x38))();
    if (cVar1 == '\0') {
      uStack_4c = 0;
      uStack_50 = 0x510327;
      uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_54 = 0x510331;
      FUN_00765c50();
      iVar4 = *DAT_00b5ad0c;
      FUN_00765c50(auStack_36 + -10);
      (**(code **)(iVar4 + 0x28))(2);
      uVar6 = (**(code **)(*DAT_00b5a794 + 0xc))(0,&DAT_006e006c);
      FUN_00401660(uVar6,0,0xffffffff);
      iVar4 = *DAT_00b5ad0c;
      FUN_00765c50(auStack_68);
      (**(code **)(iVar4 + 0x28))(2);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    (**(code **)(*DAT_00b5adc4 + 0x10))();
    return 1;
  }
  cVar1 = (**(code **)(*DAT_00b5aeec + 0x38))();
  if (cVar1 == '\x01') {
    return 0;
  }
  cVar1 = FUN_0050fc60();
  if (cVar1 == '\x01') {
    return 1;
  }
  return 0;
}


