// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x680000-0x68ffff

// ==== FUN_00680060 @ 0x00680060 ====

void FUN_00680060(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  void *unaff_EBP;
  void *unaff_ESI;
  undefined1 auStack_3c [4];
  undefined1 auStack_1e [2];
  undefined4 local_1c;
  void *local_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ItemRemoveStone_ui_item_009da534,0x2f);
  iVar2 = FUN_00410500(&local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar2 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar3;
  (**(code **)(*piVar3 + 0x40))();
  if (unaff_ESI != (void *)0x0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(unaff_ESI);
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740(s_slotbag_009da564,7);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1e + -10);
  if (0xf < uStack_14) {
    _free(unaff_EBP);
    return;
  }
  uStack_14 = 0xf;
  local_18 = (void *)0x0;
  (**(code **)(*piVar3 + 0x30))();
  FUN_00580be0(1);
  uStack_14 = 0xf;
  local_18 = (void *)0x0;
  FUN_00401740(s_slotbag_009da56c,7);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_3c + 0x10);
  if (0xf < local_18) {
    _free(unaff_ESI);
    return;
  }
  local_18 = (void *)0xf;
  local_1c = 0;
  uVar1 = (uint)unaff_ESI >> 8;
  uVar4 = (**(code **)(*piVar3 + 0x30))();
  *(undefined4 *)(in_ECX + 0xa4) = uVar4;
  local_18 = (void *)0xf;
  local_1c = 0;
  FUN_00401740(s_pan_stone_0_check_009da574,0x11);
  FUN_0067d390(auStack_3c + 0xc,0);
  if (0xf < local_18) {
    _free((void *)(uVar1 << 8));
    return;
  }
  local_18 = (void *)0xf;
  local_1c = 0;
  FUN_00401740(s_pan_stone_1_check_009da588,0x11);
  FUN_0067d390(auStack_3c + 0xc,0);
  if (0xf < local_18) {
    _free((void *)(uVar1 << 8));
    return;
  }
  local_18 = (void *)0xf;
  local_1c = 0;
  FUN_00401740(s_pan_stone_2_check_009da59c,0x11);
  FUN_0067d390(auStack_3c + 0xc,0);
  if (0xf < local_18) {
    _free((void *)(uVar1 << 8));
    return;
  }
  local_18 = (void *)0xf;
  local_1c = 0;
  FUN_00401740(s_pan_stone_3_check_009da5b0,0x11);
  FUN_0067d390(auStack_3c + 0xc,0);
  if (0xf < local_18) {
    _free((void *)(uVar1 << 8));
    return;
  }
  local_18 = (void *)0xf;
  local_1c = 0;
  FUN_00401740(s_lbl_stone_0_009da5c4,0xb);
  FUN_0067d390(auStack_3c + 0xc,0);
  if (0xf < local_18) {
    _free((void *)(uVar1 << 8));
    return;
  }
  local_18 = (void *)0xf;
  local_1c = 0;
  FUN_00401740(s_lbl_stone_1_009da5d0,0xb);
  FUN_0067d390(auStack_3c + 0xc,0);
  if (0xf < local_18) {
    _free((void *)(uVar1 << 8));
    return;
  }
  local_18 = (void *)0xf;
  local_1c = 0;
  FUN_00401740(s_lbl_stone_2_009da5dc,0xb);
  FUN_0067d390(auStack_3c + 0xc,0);
  if (0xf < local_18) {
    _free((void *)(uVar1 << 8));
    return;
  }
  local_18 = (void *)0xf;
  local_1c = 0;
  FUN_00401740(s_lbl_stone_3_009da5e8,0xb);
  FUN_0067d390(auStack_3c + 0xc,0);
  if (local_18 < 0x10) {
    FUN_0067fe00();
    return;
  }
  _free((void *)(uVar1 << 8));
  return;
}


// ==== FUN_006803a0 @ 0x006803a0 ====

undefined4 FUN_006803a0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 extraout_EAX;
  undefined4 uVar7;
  int *in_ECX;
  char *pcVar8;
  undefined *puVar9;
  undefined1 local_48 [4];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 auStack_24 [4];
  uint local_20;
  undefined1 local_1c [28];
  
  iVar2 = param_2;
  if (param_1 == 1) {
    if (param_3 == 1) {
      iVar6 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_strength_009da5f4,0xc);
      if (iVar6 == 0) {
        param_3 = CONCAT31(param_3._1_3_,0x20);
        FUN_00401830(s_ui_upgradeprogress_txt_009da604);
        FUN_0067f0b0(local_38,&param_3,0xb);
        if (local_20 < 0x10) {
          *(undefined1 *)(in_ECX + 0x2e) = 0;
          return 1;
        }
        _free(local_34);
        return extraout_EAX;
      }
      cVar3 = FUN_004036a0(iVar2,s_btn_exit_009da61c);
      if (cVar3 != '\0') {
        (**(code **)(*in_ECX + 0x10))();
        return 1;
      }
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      FUN_00404fb0(iVar2,0x5f,local_48);
      pcVar8 = s_changebag_009da628;
      uVar7 = FUN_00405d30(1);
      cVar3 = FUN_004036a0(uVar7,pcVar8);
      if (cVar3 != '\0') {
        uVar7 = FUN_00405d30(2);
        uVar7 = thunk_FUN_00796f50(uVar7);
        *(char *)(in_ECX + 0x2b) = (char)uVar7;
        (**(code **)(*DAT_00b5a78c + 0x30))(uVar7);
        FUN_0067fe00();
        FUN_00406250();
        return 1;
      }
      goto LAB_00680964;
    }
  }
  else {
    if (param_1 != 0) {
      if (param_1 == 10) {
        if (param_3 != 1) {
          return 0;
        }
        cVar3 = FUN_0067d3f0(param_2,param_4);
        if (cVar3 == '\0') {
          return 0;
        }
      }
      else {
        if (param_1 != 0xf) {
          if (param_1 != 0xb) {
            return 0;
          }
          if (param_3 != 1) {
            return 0;
          }
          cVar3 = FUN_004036a0(param_2,s_tab_chang_weapon_009da6e8);
          if ((cVar3 != '\0') ||
             (cVar3 = FUN_004036a0(iVar2,s_tab_chang_shield_009da6fc), cVar3 != '\0')) {
            uVar7 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x3e90032);
            FUN_00765c50(uVar7);
            iVar2 = *DAT_00b5ad0c;
            FUN_00765c50(auStack_24);
            (**(code **)(iVar2 + 0x28))(2);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          return 0;
        }
        local_44 = 0;
        local_40 = 0;
        local_3c = 0;
        FUN_00404fb0(param_2,0x5f,local_48);
        if (param_3 == 1) {
          pcVar8 = s_upgrade_009da640;
          uVar7 = FUN_00405d30(0);
          cVar3 = FUN_004036a0(uVar7,pcVar8);
          if (cVar3 != '\0') {
            (**(code **)(*DAT_00b5b0d0 + 0x38))();
            (**(code **)(*DAT_00b5b0cc + 0x54))(in_ECX[0x2d],in_ECX[0x2c],1000,0);
            *(undefined1 *)(in_ECX + 0x2e) = 0;
            FUN_0067fe00();
            FUN_00406250();
            return 1;
          }
          pcVar8 = s_stone_009da648;
          uVar7 = FUN_00405d30(0);
          cVar3 = FUN_004036a0(uVar7,pcVar8);
          if (cVar3 == '\0') {
            pcVar8 = s_suititem_009da660;
            uVar7 = FUN_00405d30(0);
            cVar3 = FUN_004036a0(uVar7,pcVar8);
            if (cVar3 != '\0') {
              uVar7 = FUN_00405d30(1);
              uVar4 = thunk_FUN_00796f50(uVar7);
              (**(code **)(*DAT_00b5a78c + 0xc))(uVar4);
              FUN_00406250();
              return 1;
            }
            pcVar8 = s_slotbag_009da66c;
            uVar7 = FUN_00405d30(0);
            cVar3 = FUN_004036a0(uVar7,pcVar8);
            if (cVar3 != '\0') {
              uVar7 = FUN_00405d30(1);
              uVar4 = thunk_FUN_00796f50(uVar7);
              uVar7 = FUN_00405d30(2);
              uVar5 = thunk_FUN_00796f50(uVar7);
              piVar1 = in_ECX + 0x2a;
              *(char *)piVar1 = (char)in_ECX[0x2b];
              *(undefined1 *)((int)in_ECX + 0xa9) = uVar4;
              *(undefined1 *)((int)in_ECX + 0xaa) = uVar5;
              cVar3 = (**(code **)(*DAT_00b5a78c + 0x34))(piVar1);
              if (cVar3 == '\0') {
                (**(code **)(*DAT_00b5a78c + 4))((int3)*piVar1);
                FUN_00401830(s_Call_________IINVEN__IUIHANDLER__009da684);
                FUN_00796d50(&local_40);
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              param_2 = CONCAT31(param_2._1_3_,3);
              FUN_00401830(s_ui_socket_txt_009da674);
              FUN_0067f0b0(&local_3c,&param_2,4);
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
LAB_00680964:
            FUN_00406250();
            return 0;
          }
          puVar9 = &DAT_009da650;
          uVar7 = FUN_00405d30(1);
          cVar3 = FUN_004036a0(uVar7,puVar9);
          if (cVar3 != '\0') {
            (**(code **)(*DAT_00b5b0d0 + 0x50))();
            FUN_0067fe00();
            FUN_00406250();
            return 1;
          }
          pcVar8 = s_socket_009da658;
          uVar7 = FUN_00405d30(1);
          cVar3 = FUN_004036a0(uVar7,pcVar8);
          if (cVar3 != '\0') {
            uVar7 = FUN_00405d30(2);
            uVar7 = thunk_FUN_00796fb0(uVar7);
            (**(code **)(*DAT_00b5b0d0 + 0x54))(uVar7);
            FUN_0067fe00();
            FUN_00406250();
            return 1;
          }
        }
        else if (param_3 == 2) {
          pcVar8 = s_slotbag_009da6c4;
          uVar7 = FUN_00405d30(0);
          cVar3 = FUN_004036a0(uVar7,pcVar8);
          if (cVar3 != '\0') {
            local_34 = (void *)0x0;
            local_30 = 0;
            local_2c = 0;
            FUN_00404fb0(iVar2,0x5f,local_38);
            uVar7 = FUN_00405d30(1);
            uVar4 = thunk_FUN_00796f50(uVar7);
            uVar7 = FUN_00405d30(2);
            uVar5 = thunk_FUN_00796f50(uVar7);
            param_3._0_2_ = CONCAT11(uVar4,(char)in_ECX[0x2b]);
            (**(code **)(*DAT_00b5a78c + 8))(CONCAT12(uVar5,(undefined2)param_3));
            FUN_00406250();
          }
        }
        else if (param_3 == 0xd) {
          pcVar8 = s_slotbag_009da6cc;
          uVar7 = FUN_00405d30(0);
          cVar3 = FUN_004036a0(uVar7,pcVar8);
          if (cVar3 != '\0') {
            param_3 = CONCAT31(param_3._1_3_,4);
            FUN_00401830(s_ui_stackcount_txt_009da6d4);
            FUN_0067f0b0(local_1c,&param_3,5);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
        }
        else if (((param_3 != 4) && (param_3 != 5)) ||
                (cVar3 = FUN_0067d260(iVar2,param_3,param_4), cVar3 == '\0')) goto LAB_00680964;
        FUN_00406250();
      }
      return 1;
    }
    if (param_3 == 1) {
      iVar6 = FUN_00403620(0,10,s_pan_stone__009da634,10);
      if (iVar6 == 0) {
        FUN_0067e3c0(iVar2);
        return 1;
      }
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00680a10 @ 0x00680a10 ====

undefined4 FUN_00680a10(int *param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    (**(code **)(*in_ECX + 0x30))(param_1);
  }
  else if (iVar1 == 0x70500002) {
    FUN_0067fe00();
    return 1;
  }
  return 0;
}


// ==== FUN_00680a50 @ 0x00680a50 ====

void FUN_00680a50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009daba4;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  *(undefined1 *)(in_ECX + 0x2a) = 0;
  *(undefined1 *)((int)in_ECX + 0xa9) = 0;
  *(undefined1 *)((int)in_ECX + 0xaa) = 0;
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 0x2e) = 0;
  *(undefined1 *)(in_ECX + 0x2b) = 0;
  *(undefined1 *)((int)in_ECX + 0xad) = 0;
  *(undefined1 *)((int)in_ECX + 0xab) = 4;
  in_ECX[0x2c] = 1;
  in_ECX[0x2d] = 0x80808;
  FUN_00680060();
  return;
}


// ==== FUN_00680ae0 @ 0x00680ae0 ====

void FUN_00680ae0(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
  }
  return;
}


// ==== FUN_00680b10 @ 0x00680b10 ====

int FUN_00680b10(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c5e0;
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


// ==== Catch@00680b76 @ 0x00680b76 ====

void Catch_00680b76(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00680b80 @ 0x00680b80 ====

void FUN_00680b80(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c5f0;
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


// ==== Catch@00680be6 @ 0x00680be6 ====

void Catch_00680be6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00680bf0 @ 0x00680bf0 ====

void FUN_00680bf0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00680b10(param_1,param_2,param_3);
  return;
}


// ==== FUN_00680c10 @ 0x00680c10 ====

int FUN_00680c10(int param_1,int param_2,undefined4 param_3)

{
  FUN_00680b80(param_1,param_2,param_3);
  return param_2 * 0x10 + param_1;
}


// ==== FUN_00680c40 @ 0x00680c40 ====

undefined4 FUN_00680c40(void)

{
  return 0x7c;
}


// ==== FUN_00680c50 @ 0x00680c50 ====

void FUN_00680c50(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0098c600;
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
      local_1c = FUN_00680bf0(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      local_1c = FUN_00680c10(local_1c,param_2,&local_44);
      FUN_00680bf0(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
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
      FUN_00680b10(param_1,local_28,local_18 + param_1);
      local_8 = 2;
      FUN_00680c10(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 4),&local_44);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_18;
      FUN_004be040(param_1,*(int *)(in_ECX + 8) - local_18,&local_44);
      ExceptionList = local_10;
      return;
    }
    local_18 = param_2 * 0x10;
    iVar5 = local_28 + param_2 * -0x10;
    uVar4 = FUN_00680b10(iVar5,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_004be080(param_1,iVar5,local_28,local_34);
    FUN_004be040(param_1,local_18 + param_1,&local_44);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00680dc1 @ 0x00680dc1 ====

void Catch_00680dc1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x20));
  return;
}


// ==== FUN_00680eb0 @ 0x00680eb0 ====

void FUN_00680eb0(byte param_1)

{
  void *in_ECX;
  
  FUN_0067e370();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00680ed0 @ 0x00680ed0 ====

void FUN_00680ed0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 4) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 4))) {
    FUN_00680c50(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00680b80(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x10;
  return;
}


// ==== FUN_00680f40 @ 0x00680f40 ====

void FUN_00680f40(void)

{
  return;
}


// ==== FUN_00680f80 @ 0x00680f80 ====

void FUN_00680f80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dad30;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if ((uint)in_ECX[9] < 0x10) {
    in_ECX[9] = 0xf;
    in_ECX[8] = 0;
    *(undefined1 *)(in_ECX + 4) = 0;
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_00680fd0 @ 0x00680fd0 ====

void FUN_00680fd0(void)

{
  code *pcVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  undefined4 local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_lbl_descript_009dac5c,0xc);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar2 != (int *)0x0) {
    uVar3 = (**(code **)(*piVar2 + 0x30))
                      (0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                       &Framework::UI::Control::Label::RTTI_Type_Descriptor,0);
    iVar4 = FUN_00803725(uVar3);
    if (iVar4 == 0) {
      local_8 = 0xf;
      uStack_c = 0;
      local_1c = (void *)((uint)local_1c & 0xffffff00);
      FUN_00401740(s_pLabel____NULL_009dac6c,0xe);
      FUN_00406880((int)register0x00000010 + -0x20);
      if (local_8 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(local_1c);
      return;
    }
    FUN_00401660(in_ECX + 0xc,0,0xffffffff);
    uVar3 = FUN_00404230((int)register0x00000010 + -0x20);
    FUN_0055a260(uVar3);
    if (0xf < local_8) {
      _free(local_1c);
      return;
    }
  }
  return;
}


// ==== FUN_006810f0 @ 0x006810f0 ====

int FUN_006810f0(void)

{
  code *pcVar1;
  int *piVar2;
  int extraout_EAX;
  undefined4 uVar3;
  int iVar4;
  int extraout_EAX_00;
  int in_ECX;
  int unaff_retaddr;
  undefined4 local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_edit_answer_009dac7c,0xb);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return extraout_EAX;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar2 == (int *)0x0) {
    *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
    *(undefined4 *)(unaff_retaddr + 0x14) = 0;
    *(undefined1 *)(unaff_retaddr + 4) = 0;
    FUN_00401740(&DAT_009dac88,0);
    return unaff_retaddr;
  }
  uVar3 = (**(code **)(*piVar2 + 0x30))
                    (0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                     &Framework::UI::Control::Edit::RTTI_Type_Descriptor,0);
  iVar4 = FUN_00803725(uVar3);
  if (iVar4 != 0) {
    uVar3 = FUN_00550150();
    *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
    *(undefined4 *)(unaff_retaddr + 0x14) = 0;
    *(undefined1 *)(unaff_retaddr + 4) = 0;
    FUN_00401660(uVar3,0,0xffffffff);
    return unaff_retaddr;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(s_pEdit____NULL_009dac8c,0xd);
  FUN_00406880((int)register0x00000010 + -0x20);
  if (local_8 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar4 = (*pcVar1)();
    return iVar4;
  }
  _free(local_1c);
  return extraout_EAX_00;
}


// ==== FUN_00681200 @ 0x00681200 ====

void FUN_00681200(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  int iStack_c;
  uint uStack_8;
  
  uStack_2c = param_1;
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar2 != (int *)0x0) {
    uVar3 = (**(code **)(*piVar2 + 0x30))
                      (0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                       &Framework::UI::Control::Panel::RTTI_Type_Descriptor,0);
    iStack_c = FUN_00803725(uVar3);
    if (iStack_c == 0) {
      uStack_8 = 0xf;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      FUN_00401740(s_pPanel____NULL_009dad00,0xe);
      FUN_00406880(auStack_20);
      if (uStack_8 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_1c);
      return;
    }
    uStack_2c = *(undefined4 *)(iStack_c + 0x8c);
    uStack_28 = *(undefined4 *)(iStack_c + 0x90);
    uStack_24 = param_1;
    FUN_00587d40(&uStack_2c);
  }
  return;
}


// ==== FUN_006812c0 @ 0x006812c0 ====

void FUN_006812c0(void)

{
  byte bVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  uint uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  bVar1 = (**(code **)(*DAT_00b5b138 + 0x20))();
  if (bVar1 != 0) {
    uStack_20 = (uint)bVar1;
    do {
      FUN_00401740(s_pan_fail__d_009dad10,0xb);
      uVar2 = FUN_00404230(auStack_1c);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar2);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x24))(1);
      }
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
      uStack_20 = uStack_20 - 1;
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    } while (uStack_20 != 0);
  }
  if (bVar1 < 3) {
    uStack_20 = (uint)(byte)(3 - bVar1);
    do {
      FUN_00401740(s_pan_fail__d_009dad1c,0xb);
      uVar2 = FUN_00404230(auStack_1c);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar2);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x24))(0);
      }
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
      uStack_20 = uStack_20 - 1;
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    } while (uStack_20 != 0);
  }
  return;
}


// ==== FUN_006813e0 @ 0x006813e0 ====

undefined4 FUN_006813e0(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  void *local_1c [5];
  uint uStack_8;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_answer_009dac50,10);
    if (iVar1 == 0) {
      iVar1 = *DAT_00b5b138;
      uVar2 = FUN_006810f0(local_1c);
      uVar2 = thunk_FUN_00796fb0(uVar2);
      (**(code **)(iVar1 + 0xc))(uVar2);
      if (uStack_8 < 0x10) {
        return 1;
      }
      _free(local_1c[0]);
      return extraout_EAX;
    }
  }
  return 0;
}


// ==== FUN_00681460 @ 0x00681460 ====

void FUN_00681460(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  FUN_00680fd0(0x3c - (uint)(iVar1 - *(int *)(in_ECX + 8)) / 1000);
  return;
}


// ==== FUN_00681490 @ 0x00681490 ====

void FUN_00681490(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  int unaff_EBX;
  int iVar6;
  int iVar7;
  undefined2 auStack_20 [2];
  void *pvStack_1c;
  void *pvStack_18;
  uint uStack_8;
  uint uStack_4;
  
  puVar1 = (uint *)(**(code **)(*DAT_00b5b138 + 0x1c))();
  uVar3 = *puVar1;
  auStack_20[0] = (undefined2)puVar1[1];
  uVar2 = _rand();
  uVar2 = uVar2 & 0x80000003;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffffc) + 1;
  }
  uVar3 = (uVar3 & 0xffff) / 10;
  iVar7 = uVar2 * 10;
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_pan_question_base_009dac9c,0x11);
  FUN_00681200(&pvStack_1c,iVar7 + 100);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  if (uVar3 == 0) {
    FUN_00401740(s_pan_question__d_009dacb0,0xf);
    uVar4 = FUN_00404230(&pvStack_1c);
    piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar4);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x24))(0);
    }
    if (uStack_8 < 0x10) goto LAB_00681609;
  }
  else {
    FUN_00401740(s_pan_question__d_009dacc0,0xf);
    uVar4 = FUN_00404230(&pvStack_1c);
    piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar4);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x24))(1);
    }
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    iVar6 = iVar7 + unaff_EBX;
    FUN_00401740(s_pan_question__d_009dacd0,0xf);
    uVar4 = FUN_00404230(auStack_20);
    FUN_00681200(uVar4,iVar6);
    if (uStack_8 < 0x10) {
LAB_00681609:
      iVar6 = iVar7 + uVar3;
      FUN_00401740(s_pan_question__d_009dace0,0xf);
      uVar4 = FUN_00404230(auStack_20);
      FUN_00681200(uVar4,iVar6);
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return;
      }
      FUN_00401740(s_pan_question__d_009dacf0,0xf);
      uVar4 = FUN_00404230(auStack_20);
      FUN_00681200(uVar4,iVar7);
      if (uStack_8 < 0x10) {
        return;
      }
      _free(pvStack_1c);
      return;
    }
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_006816b0 @ 0x006816b0 ====

void FUN_006816b0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int in_ECX;
  void *unaff_ESI;
  undefined1 local_1c [2];
  undefined1 auStack_1a [2];
  void *local_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_AutoUserCheck_ui_AutoQu_009dac14,0x2d);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  FUN_00681490();
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740(s_edit_answer_009dac44,0xb);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_1c + -0xc);
  if (0xf < uStack_14) {
    _free(unaff_ESI);
    return;
  }
  uStack_14 = 0xf;
  local_18 = (void *)0x0;
  puVar3 = operator_new(8);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = &PTR_FUN_009b1798;
  }
  uVar4 = (**(code **)(*piVar2 + 4))();
  puVar3[1] = uVar4;
  FUN_00797a20(puVar3);
  (**(code **)(*piVar2 + 0x5c))();
  FUN_006812c0();
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  *(undefined4 *)(in_ECX + 8) = uVar4;
  uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1180066);
  FUN_00401660(uVar4,0,0xffffffff);
  FUN_00680fd0(0x3c);
  return;
}


// ==== FUN_006817f0 @ 0x006817f0 ====

undefined4 FUN_006817f0(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    iVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    FUN_00680fd0(0x3c - (uint)(iVar1 - *(int *)(in_ECX + 8)) / 1000);
  }
  else if (iVar1 == 0x70920002) {
    FUN_006812c0();
    return 1;
  }
  return 0;
}


// ==== FUN_00681850 @ 0x00681850 ====

void FUN_00681850(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dad30;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_006816b0();
  return;
}


// ==== FUN_00681880 @ 0x00681880 ====

undefined4 FUN_00681880(void)

{
  return 0x77;
}


// ==== FUN_00681890 @ 0x00681890 ====

void FUN_00681890(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009dad30;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if (0xf < (uint)in_ECX[9]) {
    _free((void *)in_ECX[4]);
    return;
  }
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006818f0 @ 0x006818f0 ====

void FUN_006818f0(void)

{
  return;
}


// ==== FUN_00681900 @ 0x00681900 ====

undefined1 FUN_00681900(void)

{
  return 0;
}


// ==== FUN_00681910 @ 0x00681910 ====

void FUN_00681910(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009daebc;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00681930 @ 0x00681930 ====

void FUN_00681930(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 auStack_e [14];
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x4c))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    (**(code **)(*DAT_00b5a7c0 + 8))(param_2);
    FUN_00587d40(auStack_e + -6);
  }
  return;
}


// ==== FUN_006819a0 @ 0x006819a0 ====

void FUN_006819a0(int *param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x4c))(param_2);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(param_2);
  }
  return;
}


// ==== FUN_006819d0 @ 0x006819d0 ====

void FUN_006819d0(int *param_1,void *param_2)

{
  int *piVar1;
  int iVar2;
  uint in_stack_0000001c;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_lbl_percent_009dae9c,0xb);
  piVar1 = (int *)(**(code **)(*param_1 + 0x4c))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(1);
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      FUN_0055a260(&param_1);
    }
  }
  if (in_stack_0000001c < 0x10) {
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00681a70 @ 0x00681a70 ====

void FUN_00681a70(int *param_1)

{
  int *piVar1;
  int iVar2;
  byte unaff_retaddr;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_processbar_009daea8,10);
  piVar1 = (int *)(**(code **)(*param_1 + 0x4c))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(1);
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      FUN_00587ba0((float)unaff_retaddr);
    }
  }
  return;
}


// ==== FUN_00681b10 @ 0x00681b10 ====

void FUN_00681b10(ushort *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  void *in_ECX;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined1 auStack_28c [2];
  undefined1 auStack_28a [18];
  undefined1 auStack_278 [8];
  undefined1 auStack_270 [4];
  void *pvStack_26c;
  undefined4 uStack_25c;
  uint uStack_258;
  undefined1 auStack_250 [4];
  void *local_24c;
  uint uStack_238;
  int iStack_234;
  void *apvStack_228 [4];
  undefined4 uStack_218;
  uint uStack_214;
  undefined1 auStack_1f0 [4];
  undefined4 auStack_1ec [123];
  
  local_24c = in_ECX;
  piVar2 = (int *)(**(code **)(*DAT_00b5aaf8 + 0xc))();
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))();
    FUN_00401740(s_pan_zeolite__d_009dadc8,0xe);
    uVar3 = FUN_00404230(apvStack_228);
    piVar2 = (int *)(**(code **)(**(int **)((int)in_ECX + 4) + 0x34))(uVar3);
    if (0xf < uStack_214) {
      _free(apvStack_228[0]);
      return;
    }
    uStack_214 = 0xf;
    uStack_218 = 0;
    apvStack_228[0] = (void *)((uint)apvStack_228[0] & 0xffffff00);
    if (piVar2 != (int *)0x0) {
      piVar4 = (int *)(**(code **)(*DAT_00b5acac + 0x30))();
      if (piVar4 != (int *)0x0) {
        iVar5 = (**(code **)(*piVar4 + 0xc))();
        puVar7 = (undefined4 *)(iVar5 + 0x200);
        puVar8 = auStack_1ec;
        for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        iVar5 = *DAT_00b5ac9c;
        *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
        iStack_234 = (**(code **)(iVar5 + 0xc))(param_1 + 2);
        iVar5 = (**(code **)(*piVar2 + 0x30))();
        if (iVar5 != 0) {
          uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,*param_1 | 0x1400000);
          FUN_00765c50(uVar3);
          FUN_00401830(s__GUILDNAME__009dadd8);
          uVar3 = FUN_00401830(param_1 + 2);
          FUN_00404440(auStack_278,auStack_28c + -8,uVar3);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        FUN_00401830(s_guildbg_009dadf8);
        FUN_00401830(s_guildBg_009dae00);
        FUN_00681930(piVar2,auStack_270,auStack_250,param_1[0x13]);
        if (0xf < uStack_258) {
          _free(pvStack_26c);
          return;
        }
        uStack_258 = 0xf;
        uStack_25c = 0;
        pvStack_26c = (void *)((uint)pvStack_26c & 0xffffff00);
        if (0xf < uStack_238) {
          _free(local_24c);
          return;
        }
        FUN_00401830(s_guildicon_009dae08);
        FUN_00401830(s_guildicon_009dae14);
        FUN_00681930(piVar2,auStack_270,auStack_250,param_1[0x14]);
        if (0xf < uStack_258) {
          _free(pvStack_26c);
          return;
        }
        uStack_258 = 0xf;
        uStack_25c = 0;
        pvStack_26c = (void *)((uint)pvStack_26c & 0xffffff00);
        if (0xf < uStack_238) {
          _free(local_24c);
          return;
        }
        FUN_00401830(s_siege_009dae20);
        FUN_00401830(s_ownerMark_009dae28);
        FUN_00681930(piVar2,auStack_270,auStack_250,(iStack_234 != 0) + '#');
        if (0xf < uStack_258) {
          _free(pvStack_26c);
          return;
        }
        uStack_258 = 0xf;
        uStack_25c = 0;
        pvStack_26c = (void *)((uint)pvStack_26c & 0xffffff00);
        if (0xf < uStack_238) {
          _free(local_24c);
          return;
        }
        cVar1 = FUN_00629390(auStack_1f0);
        if (cVar1 != '\0') {
          FUN_00401830(s_otherguildhide_009dae34);
          piVar2 = (int *)(**(code **)(*piVar2 + 0x4c))(auStack_28c);
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 0x24))(0);
          }
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
        if (cVar1 == '\0') {
          FUN_00401830(s_otherguildhide_009dae78);
          FUN_006819a0(piVar2,auStack_28c,1);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        FUN_00401830(s_otherguildhide_009dae50);
        FUN_006819a0(piVar2,auStack_28c,0);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
  }
  return;
}


// ==== FUN_00682070 @ 0x00682070 ====

void FUN_00682070(void)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  
  iVar1 = (**(code **)(*DAT_00b5ac98 + 0x6c))();
  bVar2 = *(byte *)(iVar1 + 0x1c);
  if (((bVar2 != 0) && (bVar2 < 6)) && (uVar3 = 0, bVar2 != 0)) {
    do {
      FUN_00681b10(iVar1 + 0x20 + uVar3 * 0xb4);
      bVar2 = (char)uVar3 + 1;
      uVar3 = (uint)bVar2;
    } while (bVar2 < *(byte *)(iVar1 + 0x1c));
  }
  return;
}


// ==== FUN_006820c0 @ 0x006820c0 ====

void FUN_006820c0(void)

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
  FUN_00401740(s_UI_Game2_Siege_ui_allzeolitestat_009dad9c,0x28);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_00682070();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00682140 @ 0x00682140 ====

uint FUN_00682140(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x70910022) {
    uVar1 = FUN_00682070();
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00682160 @ 0x00682160 ====

void FUN_00682160(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009daebc;
  FUN_006820c0();
  return;
}


// ==== FUN_00682180 @ 0x00682180 ====

undefined1 FUN_00682180(void)

{
  return 0;
}


// ==== FUN_00682190 @ 0x00682190 ====

void FUN_00682190(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009daebc;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006821d0 @ 0x006821d0 ====

undefined1 FUN_006821d0(void)

{
  return 0;
}


// ==== FUN_006821e0 @ 0x006821e0 ====

void FUN_006821e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009daf8c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00682200 @ 0x00682200 ====

void FUN_00682200(uint *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  void *local_54 [4];
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 auStack_3c [28];
  undefined1 auStack_20 [32];
  
  if (*param_1 < 3) {
    FUN_00401740(s_pan_gate__d_009daf50,0xb);
    uVar1 = FUN_00404230(local_54);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar1);
    if (0xf < uStack_40) {
      _free(local_54[0]);
      return;
    }
    uStack_40 = 0xf;
    uStack_44 = 0;
    local_54[0] = (void *)((uint)local_54[0] & 0xffffff00);
    if (piVar2 != (int *)0x0) {
      if ((char)param_1[1] == '\0') {
        FUN_00401830(s_processbar_009daf70);
        (**(code **)(*piVar2 + 0x4c))(auStack_20);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      FUN_00401830(s_processbar_009daf5c);
      (**(code **)(*piVar2 + 0x4c))(auStack_3c);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  return;
}


// ==== FUN_006823a0 @ 0x006823a0 ====

void FUN_006823a0(void)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  char cStack_1;
  
  pbVar1 = (byte *)(**(code **)(*DAT_00b5ac98 + 0x6c))();
  bVar2 = *pbVar1;
  if ((bVar2 != 0) && (bVar2 < 4)) {
    uVar3 = 0;
    cStack_1 = '\0';
    if (bVar2 != 0) {
      do {
        if (pbVar1[uVar3 * 8 + 8] == 0) {
          cStack_1 = cStack_1 + '\x01';
        }
        FUN_00682200(pbVar1 + uVar3 * 8 + 4);
        bVar2 = (char)uVar3 + 1;
        uVar3 = (uint)bVar2;
      } while (bVar2 < *pbVar1);
      if (cStack_1 == '\x03') {
                    /* WARNING: Could not recover jumptable at 0x00682409. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*DAT_00b5ac94 + 0x38))();
        return;
      }
    }
  }
  return;
}


// ==== FUN_00682420 @ 0x00682420 ====

undefined4 FUN_00682420(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70910025) {
    FUN_006823a0();
    return 1;
  }
  return 0;
}


// ==== FUN_00682450 @ 0x00682450 ====

void FUN_00682450(void)

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
  FUN_00401740(s_UI_Game2_Siege_ui_allgatestatewn_009daf28,0x25);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_006823a0();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_006824d0 @ 0x006824d0 ====

void FUN_006824d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009daf8c;
  FUN_00682450();
  return;
}


// ==== FUN_006824f0 @ 0x006824f0 ====

undefined4 FUN_006824f0(void)

{
  return 99;
}


// ==== FUN_00682500 @ 0x00682500 ====

void FUN_00682500(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009daf8c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00682540 @ 0x00682540 ====

void FUN_00682540(void)

{
  return;
}


// ==== FUN_00682550 @ 0x00682550 ====

undefined1 FUN_00682550(void)

{
  return 0;
}


// ==== FUN_00682560 @ 0x00682560 ====

void FUN_00682560(undefined4 *param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 auStack_24 [5];
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  piVar1 = (int *)param_1[3];
  puVar2 = (undefined4 *)(**(code **)(*(int *)*param_1 + 0x14))();
  puVar5 = auStack_24;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar5 = puVar5 + 1;
  }
  iStack_8 = iStack_10 + param_3;
  iStack_4 = iStack_c + param_2;
  (**(code **)(*(int *)*param_1 + 0x18))(auStack_24);
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    uVar3 = (**(code **)(*piVar1 + 4))();
    *puVar2 = &PTR_FUN_009bcd68;
    puVar2[1] = uVar3;
  }
  *(undefined1 *)(puVar2 + 2) = 0;
  (**(code **)(*DAT_00b5ad24 + 4))(puVar2);
  (**(code **)*puVar2)(1);
  return;
}


// ==== FUN_00682600 @ 0x00682600 ====

void FUN_00682600(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (param_1 != (int *)0x0) {
    uVar1 = (**(code **)(*param_1 + 0x30))
                      (0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                       &Framework::UI::Control::Panel::RTTI_Type_Descriptor,0);
    iVar2 = FUN_00803725(uVar1);
    if (iVar2 != 0) {
      uStack_c = *(undefined4 *)(iVar2 + 0x8c);
      uStack_4 = param_3;
      uStack_8 = param_2;
      FUN_00587d40(&uStack_c);
    }
  }
  return;
}


// ==== FUN_00682670 @ 0x00682670 ====

void FUN_00682670(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puStack_44;
  undefined4 uStack_40;
  undefined1 local_2c [4];
  void *pvStack_28;
  void *pvStack_24;
  uint uStack_14;
  uint uStack_10;
  
  uStack_40 = *param_1;
  puStack_44 = local_2c;
  (**(code **)(*DAT_00b5ac98 + 0x78))();
  piVar1 = (int *)param_1[0xd];
  (**(code **)(*piVar1 + 0x24))(1);
  uVar2 = (**(code **)(*piVar1 + 0x30))
                    (0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                     &Framework::UI::Control::Panel::RTTI_Type_Descriptor,0);
  iVar3 = FUN_00803725(uVar2);
  if (iVar3 == 0) {
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
  }
  else {
    puStack_44 = *(undefined1 **)(iVar3 + 0x8c);
    uStack_40 = *(undefined4 *)(iVar3 + 0x90);
    FUN_00587d40(&puStack_44);
    if (0xf < uStack_14) {
      _free(pvStack_28);
      return;
    }
  }
  return;
}


// ==== FUN_00682720 @ 0x00682720 ====

/* WARNING: Removing unreachable block (ram,0x006827f2) */
/* WARNING: Removing unreachable block (ram,0x00682793) */

void FUN_00682720(int param_1)

{
  undefined4 uVar1;
  undefined1 auStack_1e [30];
  
  if ((*(short *)(param_1 + 6) != 0) || (*(short *)(param_1 + 8) != 0)) {
    (**(code **)(**(int **)(param_1 + 0x2c) + 0x24))(1);
    (**(code **)(**(int **)(param_1 + 0x30) + 0x24))(1);
    if (*(short *)(param_1 + 8) != 0) {
      FUN_00401740(s_guildbg_009db040,7);
      uVar1 = (**(code **)(*DAT_00b5a7c0 + 8))(auStack_1e + -6);
      FUN_00682600(*(undefined4 *)(param_1 + 0x30),uVar1,*(undefined2 *)(param_1 + 8));
    }
    if (*(short *)(param_1 + 6) != 0) {
      FUN_00401740(s_guildicon_009db048,9);
      uVar1 = (**(code **)(*DAT_00b5a7c0 + 8))(auStack_1e + -6);
      FUN_00682600(*(undefined4 *)(param_1 + 0x2c),uVar1,*(undefined2 *)(param_1 + 6));
    }
  }
  return;
}


// ==== FUN_00682820 @ 0x00682820 ====

void FUN_00682820(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  void *unaff_EBX;
  void *unaff_ESI;
  undefined4 local_1c;
  undefined1 local_18;
  uint uStack_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  *param_2 = param_1;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_guild_009db054,9);
  uVar1 = (**(code **)(*param_1 + 0x34))(&local_1c);
  param_2[1] = uVar1;
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(s_pan_guild_bg_009db060,0xc);
  uVar1 = (**(code **)(*param_1 + 0x34))((int)register0x00000010 + -0x20);
  param_2[2] = uVar1;
  if (0xf < uStack_c) {
    _free(unaff_EBX);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  FUN_00401740(s_pan_zeolite_type_009db070,0x10);
  uVar1 = (**(code **)(*param_1 + 0x34))((int)register0x00000010 + -0x24);
  param_2[3] = uVar1;
  if (uStack_10 < 0x10) {
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_00682910 @ 0x00682910 ====

void FUN_00682910(void)

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
  FUN_00401740(s_UI_Game2_Siege_ui_zeolitewnd_txt_009daff8,0x20);
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


// ==== FUN_00682990 @ 0x00682990 ====

void FUN_00682990(int param_1)

{
  int in_ECX;
  int local_4;
  
  param_1 = *(undefined4 *)(param_1 + 4);
  local_4 = in_ECX;
  FUN_006831a0(&local_4,&param_1);
  if (local_4 != *(int *)(in_ECX + 0xc)) {
    if (*(int *)(local_4 + 0x38) != 0) {
      (**(code **)(*DAT_00b5a7a4 + 8))(*(int *)(local_4 + 0x38));
    }
    FUN_00683330(&param_1,local_4);
  }
  return;
}


// ==== FUN_006829f0 @ 0x006829f0 ====

void FUN_006829f0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *in_ECX;
  undefined1 auStack_2 [2];
  
  puVar2 = (undefined4 *)in_ECX[3];
  *in_ECX = &PTR_FUN_009db0ac;
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if (puVar3[0xe] != 0) {
      (**(code **)(*DAT_00b5a7a4 + 8))(puVar3[0xe]);
    }
    if (*(char *)((int)puVar3 + 0x49) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x49) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x49);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x49);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x49);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x49);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  FUN_00683610(*(undefined4 *)(in_ECX[3] + 4));
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  in_ECX[4] = 0;
  *(undefined4 *)in_ECX[3] = in_ECX[3];
  *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  FUN_006838e0(auStack_2 + -6,*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3]);
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00682ad0 @ 0x00682ad0 ====

void FUN_00682ad0(undefined4 *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  float *pfVar4;
  undefined4 *puVar5;
  uint unaff_EBX;
  undefined4 unaff_EBP;
  float unaff_ESI;
  undefined4 *puVar6;
  undefined4 unaff_EDI;
  char cVar8;
  undefined4 *puVar7;
  float10 fVar9;
  float10 fVar10;
  float fVar11;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float afStack_94 [3];
  undefined4 uStack_88;
  undefined4 uStack_84;
  float local_80;
  float fStack_7c;
  float fStack_78;
  undefined4 auStack_74 [3];
  char cStack_68;
  undefined1 auStack_50 [12];
  undefined4 auStack_44 [17];
  
  cVar8 = (char)((uint)unaff_EDI >> 0x18);
  if ((DAT_00b5acd8 != (int *)0x0) &&
     (piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*param_1), piVar2 != (int *)0x0)) {
    iVar3 = (**(code **)(*piVar2 + 0x1c))();
    if ((iVar3 != 0) && (cVar1 = FUN_00511d60(), cVar1 == '\0')) {
      unaff_EBX = unaff_EBX & 0xffffff;
    }
    pfVar4 = (float *)(**(code **)(*piVar2 + 0x28))();
    local_80 = *pfVar4;
    fStack_7c = pfVar4[1];
    fVar9 = (float10)(**(code **)(*piVar2 + 0x34))();
    fVar10 = (float10)(**(code **)(*piVar2 + 0x30))();
    fVar9 = fVar10 + (float10)(float)fVar9 + (float10)DAT_0099d0b4;
    fStack_a0 = local_80;
    fStack_98 = fStack_7c;
    fStack_9c = (float)fVar9;
    puVar6 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 200);
    puVar5 = auStack_44;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar5 = puVar5 + 1;
    }
    thunk_FUN_0079e43e(afStack_94,&fStack_a0,auStack_44);
    fVar11 = DAT_0099d080 / afStack_94[0];
    fStack_a0 = fStack_a0 * fVar11;
    fStack_9c = fStack_9c * fVar11;
    fStack_98 = fVar11 * fStack_98;
    afStack_94[0] = fVar11 * afStack_94[0];
    if ((fStack_98 < 0.0) || (DAT_0099d080 < fStack_98)) {
      cVar8 = '\0';
    }
    puVar6 = param_1 + 10;
    iVar3 = (**(code **)(*(int *)param_1[10] + 0x14))();
    if (cVar8 != *(char *)(iVar3 + 0xc)) {
      puVar5 = (undefined4 *)(**(code **)(*(int *)*puVar6 + 0x14))();
      puVar7 = auStack_74;
      for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      cStack_68 = cVar8;
      (**(code **)(*(int *)*puVar6 + 0x18))(auStack_74);
    }
    if (cVar8 != '\0') {
      uStack_88 = 0;
      uStack_84 = 0;
      local_80 = 0.0;
      FUN_0040f1e0(&fStack_7c,unaff_EBP,unaff_EBX,(float)fVar9,auStack_50,
                   *(undefined4 *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xa0),
                   *(undefined4 *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x9c));
      FUN_00682560(puVar6,0x47,0x32);
      (**(code **)(*(int *)*puVar6 + 0x54))
                ((int)fStack_7c + -0x1d,(int)fStack_78 + 0x4f + (int)unaff_ESI,1);
      FUN_00682670(param_1);
      FUN_00682720(param_1);
      FUN_00406250();
    }
  }
  return;
}


// ==== FUN_00682d00 @ 0x00682d00 ====

void FUN_00682d00(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009db0ac;
  iVar1 = FUN_00683100();
  in_ECX[3] = iVar1;
  *(undefined1 *)(iVar1 + 0x49) = 1;
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  *(undefined4 *)in_ECX[3] = in_ECX[3];
  *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  in_ECX[4] = 0;
  FUN_00683610(*(undefined4 *)(in_ECX[3] + 4));
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  in_ECX[4] = 0;
  *(undefined4 *)in_ECX[3] = in_ECX[3];
  *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  FUN_00682910();
  return;
}


// ==== FUN_00682d70 @ 0x00682d70 ====

void FUN_00682d70(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 0xc);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    FUN_00682ad0(puVar3 + 4);
    if (*(char *)((int)puVar3 + 0x49) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x49) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x49);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x49);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x49);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x49);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  return;
}


// ==== FUN_00682de0 @ 0x00682de0 ====

void FUN_00682de0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  void *unaff_ESI;
  undefined4 *puStack_e4;
  undefined4 uStack_e0;
  char *pcStack_dc;
  undefined4 uStack_c4;
  uint uStack_c0;
  undefined1 auStack_bc [12];
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  void *pvStack_98;
  undefined1 local_88 [4];
  uint uStack_84;
  undefined1 auStack_80 [8];
  void *local_78;
  uint local_64;
  int local_60;
  undefined4 *apuStack_5c [2];
  void *pvStack_54;
  void *pvStack_48;
  undefined4 uStack_44;
  uint uStack_40;
  uint uStack_34;
  
  FUN_00683210();
  FUN_006831a0();
  if (local_60 == *(int *)(in_ECX + 0xc)) {
    pcStack_dc = s_UI_Game2_Siege_ui_zeolitewnd_txt_009db01c;
    uStack_40 = 0xf;
    uStack_44 = 0;
    pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
    uStack_e0 = 0x682e68;
    FUN_00401740();
    pcStack_dc = (char *)0x682e72;
    iVar2 = FUN_00410500();
    if (0xf < uStack_40) {
      pcStack_dc = (char *)0x682e8e;
      _free(pvStack_54);
      return;
    }
    pcStack_dc = (char *)(iVar2 + 0x3c);
    uStack_e0 = 0x682ea1;
    piVar3 = (int *)(**(code **)(*DAT_00b5a798 + 4))();
    puStack_e4 = (undefined4 *)0x682eab;
    (**(code **)(*piVar3 + 0x40))();
    puStack_e4 = (undefined4 *)0xffffffff;
    uStack_ac = 0xf;
    uStack_b0 = 0;
    uStack_c0 = uStack_c0 & 0xffffff00;
    uStack_a8 = 0;
    uStack_a4 = 0;
    uStack_a0 = 0;
    uStack_9c = 0;
    FUN_00401660(local_88,0);
    puStack_e4 = &uStack_c4;
    cVar1 = (**(code **)(*DAT_00b5ac98 + 0x14))();
    (**(code **)(*DAT_00b5ac98 + 100))(pvStack_98,cVar1 != '\0');
    (**(code **)(*DAT_00b5ac98 + 0x68))(uStack_a0,uStack_a4._1_1_ != '\x01');
    FUN_00682820(piVar3,auStack_bc);
    apuStack_5c[0] = puStack_e4;
    FUN_00683270(&puStack_e4);
    FUN_006839a0(auStack_80,apuStack_5c);
    if (0xf < uStack_34) {
      _free(pvStack_48);
      return;
    }
    FUN_00682ad0(&puStack_e4);
    if (iVar2 != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(iVar2);
    }
    if (0xf < uStack_c0) {
      _free(unaff_ESI);
      return;
    }
    uStack_c4 = 0;
    uStack_c0 = 0xf;
    if (0xf < uStack_84) {
      _free(pvStack_98);
      return;
    }
  }
  else if (0xf < local_64) {
    _free(local_78);
    return;
  }
  return;
}


// ==== FUN_00682e37 @ 0x00682e37 ====

void FUN_00682e37(undefined4 param_1,uint param_2,undefined1 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,void *param_12,
                 undefined4 param_13,undefined2 param_14,undefined2 param_15,undefined1 param_16,
                 uint param_17,undefined1 param_18)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  void *unaff_ESI;
  undefined4 uStack0000006c;
  void *in_stack_00000074;
  void *in_stack_00000080;
  undefined4 uStack00000084;
  uint uStack00000088;
  uint in_stack_00000094;
  undefined4 *puStack_1c;
  
  uStack00000088 = 0xf;
  uStack00000084 = 0;
  in_stack_00000074 = (void *)((uint)in_stack_00000074 & 0xffffff00);
  FUN_00401740();
  iVar2 = FUN_00410500();
  if (0xf < uStack00000088) {
    _free(in_stack_00000074);
    return;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a798 + 4))();
  puStack_1c = (undefined4 *)0x682eab;
  (**(code **)(*piVar3 + 0x40))();
  puStack_1c = (undefined4 *)0xffffffff;
  param_7 = 0xf;
  param_6 = 0;
  param_2 = param_2 & 0xffffff00;
  param_8 = 0;
  param_9 = 0;
  param_10 = 0;
  param_11 = 0;
  FUN_00401660(&param_16,0);
  puStack_1c = &param_1;
  cVar1 = (**(code **)(*DAT_00b5ac98 + 0x14))();
  (**(code **)(*DAT_00b5ac98 + 100))(param_12,cVar1 != '\0');
  (**(code **)(*DAT_00b5ac98 + 0x68))(param_10,param_9._1_1_ != '\x01');
  FUN_00682820(piVar3,&param_3);
  uStack0000006c = puStack_1c;
  FUN_00683270(&puStack_1c);
  FUN_006839a0(&param_18,&uStack0000006c);
  if (0xf < in_stack_00000094) {
    _free(in_stack_00000080);
    return;
  }
  FUN_00682ad0(&puStack_1c);
  if (iVar2 != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar2);
  }
  if (0xf < param_2) {
    _free(unaff_ESI);
    return;
  }
  param_1 = 0;
  param_2 = 0xf;
  if (param_17 < 0x10) {
    return;
  }
  _free(param_12);
  return;
}


// ==== FUN_00683020 @ 0x00683020 ====

void FUN_00683020(int param_1)

{
  int iVar1;
  int in_ECX;
  int local_4;
  
  iVar1 = param_1;
  param_1 = *(undefined4 *)(param_1 + 4);
  local_4 = in_ECX;
  FUN_006831a0(&local_4,&param_1);
  if (local_4 != *(int *)(in_ECX + 0xc)) {
    *(undefined1 *)(local_4 + 0x14) = *(undefined1 *)(iVar1 + 8);
    FUN_00682ad0(local_4 + 0x10);
  }
  return;
}


// ==== FUN_00683070 @ 0x00683070 ====

undefined4 FUN_00683070(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 < 0x70910019) {
    if (uVar1 == 0x70910018) {
      FUN_00682990(param_1);
      return 1;
    }
    if (uVar1 == 0x40001) {
      FUN_00682d70(param_1);
      return 0;
    }
    if (uVar1 == 0x70910017) {
      FUN_00682de0(param_1);
      return 1;
    }
  }
  else if (uVar1 == 0x70910019) {
    FUN_00683020(param_1);
    return 1;
  }
  return 0;
}


// ==== FUN_006830e0 @ 0x006830e0 ====

void FUN_006830e0(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x49);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x49);
  }
  return;
}


// ==== FUN_00683100 @ 0x00683100 ====

void FUN_00683100(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c610;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x4c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x12) = 1;
  *(undefined1 *)((int)puVar1 + 0x49) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@0068318a @ 0x0068318a ====

void Catch_0068318a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_006831a0 @ 0x006831a0 ====

void FUN_006831a0(undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x49) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((uint)puVar1[3] < *param_2) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x49) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < (uint)puVar3[3])) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_00683210 @ 0x00683210 ====

void FUN_00683210(undefined1 *param_1)

{
  undefined1 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined2 *)(in_ECX + 8) = *(undefined2 *)(param_1 + 8);
  *(undefined2 *)(in_ECX + 10) = *(undefined2 *)(param_1 + 10);
  *(undefined2 *)(in_ECX + 0xc) = *(undefined2 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x28) = 0xf;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  in_ECX[0x14] = 0;
  FUN_00401660(param_1 + 0x10,0,0xffffffff);
  return;
}


// ==== FUN_00683270 @ 0x00683270 ====

void FUN_00683270(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  *(undefined1 *)(in_ECX + 1) = *(undefined1 *)(param_1 + 1);
  *(undefined1 *)((int)in_ECX + 5) = *(undefined1 *)((int)param_1 + 5);
  *(undefined2 *)((int)in_ECX + 6) = *(undefined2 *)((int)param_1 + 6);
  *(undefined2 *)(in_ECX + 2) = *(undefined2 *)(param_1 + 2);
  *(undefined2 *)((int)in_ECX + 10) = *(undefined2 *)((int)param_1 + 10);
  in_ECX[8] = 0;
  in_ECX[9] = 0xf;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1 + 3,0,0xffffffff);
  in_ECX[10] = param_1[10];
  in_ECX[0xb] = param_1[0xb];
  in_ECX[0xc] = param_1[0xc];
  in_ECX[0xd] = param_1[0xd];
  return;
}


// ==== FUN_006832f0 @ 0x006832f0 ====

void FUN_006832f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = *param_4;
  FUN_00683270(param_4 + 1);
  *(undefined1 *)(in_ECX + 0x12) = param_5;
  *(undefined1 *)((int)in_ECX + 0x49) = 0;
  return;
}


// ==== FUN_00683330 @ 0x00683330 ====

/* WARNING: Removing unreachable block (ram,0x00683449) */
/* WARNING: Removing unreachable block (ram,0x0068345a) */
/* WARNING: Removing unreachable block (ram,0x00683463) */
/* WARNING: Removing unreachable block (ram,0x00683466) */
/* WARNING: Removing unreachable block (ram,0x00683456) */
/* WARNING: Removing unreachable block (ram,0x00683474) */
/* WARNING: Removing unreachable block (ram,0x00683481) */
/* WARNING: Removing unreachable block (ram,0x0068348c) */
/* WARNING: Removing unreachable block (ram,0x00683488) */
/* WARNING: Removing unreachable block (ram,0x0068347c) */
/* WARNING: Removing unreachable block (ram,0x0068348f) */

void FUN_00683330(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0x49) != '\0') {
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
  FUN_00700ad0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x49) == '\0') {
    if (*(char *)(param_2[2] + 0x49) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x49) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x49) == '\0') {
      piVar3 = (int *)FUN_006830e0(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x49) == '\0') {
      uVar4 = FUN_00700ab0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0x12] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x12] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x12] == '\0') {
            *(undefined1 *)(piVar5 + 0x12) = 1;
            *(undefined1 *)(piVar3 + 0x12) = 0;
            FUN_00857bf0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x49) == '\0') {
            if ((*(char *)(*piVar5 + 0x48) == '\x01') && (*(char *)(piVar5[2] + 0x48) == '\x01'))
            goto LAB_00683564;
            if (*(char *)(piVar5[2] + 0x48) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x48) = 1;
              *(undefined1 *)(piVar5 + 0x12) = 0;
              FUN_00700b30(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0x12) = (char)piVar3[0x12];
            *(undefined1 *)(piVar3 + 0x12) = 1;
            *(undefined1 *)(piVar5[2] + 0x48) = 1;
            FUN_00857bf0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0x12] == '\0') {
            *(undefined1 *)(piVar5 + 0x12) = 1;
            *(undefined1 *)(piVar3 + 0x12) = 0;
            FUN_00700b30(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x49) == '\0') {
            if ((*(char *)(piVar5[2] + 0x48) != '\x01') || (*(char *)(*piVar5 + 0x48) != '\x01')) {
              if (*(char *)(*piVar5 + 0x48) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x48) = 1;
                *(undefined1 *)(piVar5 + 0x12) = 0;
                FUN_00857bf0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0x12) = (char)piVar3[0x12];
              *(undefined1 *)(piVar3 + 0x12) = 1;
              *(undefined1 *)(*piVar5 + 0x48) = 1;
              FUN_00700b30(piVar3);
              break;
            }
LAB_00683564:
            *(undefined1 *)(piVar5 + 0x12) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x12) = 1;
  }
  if ((uint)param_2[0xd] < 0x10) {
    param_2[0xd] = 0xf;
    param_2[0xc] = 0;
    *(undefined1 *)(param_2 + 8) = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[8]);
  return;
}


// ==== FUN_00683610 @ 0x00683610 ====

void FUN_00683610(void *param_1)

{
  if (*(char *)((int)param_1 + 0x49) != '\0') {
    return;
  }
  FUN_00683610(*(undefined4 *)((int)param_1 + 8));
  if (*(uint *)((int)param_1 + 0x34) < 0x10) {
    *(undefined4 *)((int)param_1 + 0x34) = 0xf;
    *(undefined4 *)((int)param_1 + 0x30) = 0;
    *(undefined1 *)((int)param_1 + 0x20) = 0;
    _free(param_1);
    return;
  }
  _free(*(void **)((int)param_1 + 0x20));
  return;
}


// ==== FUN_00683670 @ 0x00683670 ====

void * FUN_00683670(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c620;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x4c);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_006832f0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@006836e5 @ 0x006836e5 ====

void Catch_006836e5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00683700 @ 0x00683700 ====

void FUN_00683700(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0x4444442 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00683670(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x48);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x48) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x12] == '\0') {
LAB_00683805:
        *(undefined1 *)(*piVar5 + 0x48) = 1;
        *(undefined1 *)(piVar6 + 0x12) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x48) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_00857bf0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x48) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x48) = 0;
        FUN_00700b30(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x12] == '\0') goto LAB_00683805;
      if (piVar7 == (int *)*piVar2) {
        FUN_00700b30(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x48) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x48) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x49) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x48);
  } while( true );
}


// ==== FUN_006838e0 @ 0x006838e0 ====

void FUN_006838e0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00683610(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x49) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x49) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x49);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x49);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x49);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x49);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00683330(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_006839a0 @ 0x006839a0 ====

void FUN_006839a0(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x49) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x49) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_00683700(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_00857c40();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00683700(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00683a60 @ 0x00683a60 ====

undefined4 FUN_00683a60(void)

{
  return 0x66;
}


// ==== FUN_00683a70 @ 0x00683a70 ====

void FUN_00683a70(byte param_1)

{
  void *in_ECX;
  
  FUN_006829f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00683a90 @ 0x00683a90 ====

void FUN_00683a90(void)

{
  return;
}


// ==== FUN_00683aa0 @ 0x00683aa0 ====

undefined1 FUN_00683aa0(void)

{
  return 0;
}


// ==== FUN_00683ab0 @ 0x00683ab0 ====

undefined1 FUN_00683ab0(void)

{
  return 0;
}


// ==== FUN_00683ac0 @ 0x00683ac0 ====

void FUN_00683ac0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009db160;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00683ae0 @ 0x00683ae0 ====

int FUN_00683ae0(void)

{
  uint uVar1;
  int *piVar2;
  int extraout_EAX;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int extraout_EAX_00;
  int in_ECX;
  void *pvStack_38;
  undefined1 uStack_34;
  undefined4 uStack_28;
  void *pvStack_24;
  undefined4 uStack_20;
  uint uStack_10;
  
  uVar1 = (**(code **)(*DAT_00b5ac94 + 0x60))();
  iVar5 = uVar1 * 0x10624dd3;
  if (*(uint *)(in_ECX + 8) != uVar1 / 1000) {
    *(uint *)(in_ECX + 8) = uVar1 / 1000;
    uStack_20 = 0xf;
    pvStack_24 = (void *)0x0;
    uStack_34 = 0;
    FUN_00401740(s_lbl_waittime_009db13c,0xc);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_38);
    if (0xf < pvStack_24) {
      _free(pvStack_38);
      return extraout_EAX;
    }
    pvStack_24 = (void *)0xf;
    uStack_28 = 0;
    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    iVar5 = 0;
    if (piVar2 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar2 + 0x30))();
      iVar5 = 0;
      if (iVar3 != 0) {
        uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x122002a,*(undefined4 *)(in_ECX + 8));
        FUN_00401660(uVar4,0,0xffffffff);
        FUN_00404230(&uStack_28);
        iVar5 = FUN_0055a260(&uStack_28);
        if (0xf < uStack_10) {
          _free(pvStack_24);
          return extraout_EAX_00;
        }
      }
    }
  }
  return iVar5;
}


// ==== FUN_00683be0 @ 0x00683be0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00683be0(void)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_processbar_009db14c,10);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar3 != (int *)0x0) {
    iVar4 = (**(code **)(*piVar3 + 0x30))();
    if (iVar4 != 0) {
      iVar4 = (**(code **)(*DAT_00b5ac94 + 100))();
      iVar5 = (**(code **)(*DAT_00b5ac94 + 0x60))();
      fVar1 = (float)(iVar4 - iVar5);
      if (iVar4 - iVar5 < 0) {
        fVar1 = fVar1 + _DAT_0099d104;
      }
      fVar2 = (float)iVar4;
      if (iVar4 < 0) {
        fVar2 = fVar2 + _DAT_0099d104;
      }
      FUN_00587ba0((fVar1 / fVar2) * DAT_0099de78);
      FUN_00683ae0();
    }
  }
  return;
}


// ==== FUN_00683cb0 @ 0x00683cb0 ====

void FUN_00683cb0(void)

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
  FUN_00401740(s_UI_Game2_Siege_ui_attachtimewnd__009db118,0x23);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_00683ae0();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00683d30 @ 0x00683d30 ====

uint FUN_00683d30(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_00683be0(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00683d60 @ 0x00683d60 ====

void FUN_00683d60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009db160;
  in_ECX[2] = 0;
  in_ECX[1] = 0;
  FUN_00683cb0();
  return;
}


// ==== FUN_00683d80 @ 0x00683d80 ====

undefined4 FUN_00683d80(void)

{
  return 0x62;
}


// ==== FUN_00683d90 @ 0x00683d90 ====

void FUN_00683d90(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009db160;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00683dd0 @ 0x00683dd0 ====

void FUN_00683dd0(void)

{
  return;
}


// ==== FUN_00683de0 @ 0x00683de0 ====

undefined4 FUN_00683de0(void)

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


// ==== FUN_00683e10 @ 0x00683e10 ====

void FUN_00683e10(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined1 auStack_e [14];
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    (**(code **)(*DAT_00b5a7c0 + 8))(param_1);
    FUN_00587d40(auStack_e + -6);
  }
  return;
}


// ==== FUN_00683e80 @ 0x00683e80 ====

void FUN_00683e80(undefined4 param_1)

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


// ==== FUN_00683eb0 @ 0x00683eb0 ====

uint FUN_00683eb0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = 0;
  if ((param_1 == 1) && (param_3 == 1)) {
    uVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009db300,8);
    if (uVar1 == 0) {
      uVar1 = (**(code **)(*in_ECX + 0x10))();
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00683ef0 @ 0x00683ef0 ====

void FUN_00683ef0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009db314;
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


// ==== FUN_00683f40 @ 0x00683f40 ====

void FUN_00683f40(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 unaff_EBX;
  char acStack_3c [4];
  void *local_38;
  undefined1 local_34;
  uint local_24;
  undefined4 local_20;
  void *pvStack_1c;
  void *pvStack_18;
  uint uStack_8;
  uint uStack_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(&DAT_009db1ee,0);
  piVar1 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x18))();
    acStack_3c[0] = *(char *)(iVar2 + 0xd);
    if (acStack_3c[0] != '\0') {
      acStack_3c[0] = acStack_3c[0] + -1;
    }
    uVar3 = (**(code **)(*DAT_00b5ad1c + 0x2c))(&pvStack_1c);
    FUN_00401660(uVar3,0,0xffffffff);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    FUN_004020e0(&DAT_009db1f0,3);
    uVar3 = (**(code **)(*DAT_00b5ad1c + 0x30))(&local_20,unaff_EBX);
    FUN_00401ff0(uVar3,0,0xffffffff);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_lbl_serverInfo_009db1f4,0xe);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1c);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      FUN_0055a260(acStack_3c);
    }
  }
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return;
  }
  if (local_24 < 0x10) {
    return;
  }
  _free(local_38);
  return;
}


// ==== FUN_00684090 @ 0x00684090 ====

void FUN_00684090(void)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_ESI;
  uint uStack_4c;
  undefined4 uStack_48;
  uint uStack_2c;
  uint uStack_28;
  void *pvStack_24;
  undefined1 uStack_18;
  uint uStack_10;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_48 = 0x6840a3;
  piVar3 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
  if (piVar3 != (int *)0x0) {
    uStack_4 = 0xf;
    uStack_8 = 0;
    uStack_18 = 0;
    uStack_48 = 0x6840c5;
    iVar4 = (**(code **)(*piVar3 + 0x18))();
    if (*(char *)(iVar4 + 0xc) == '\0') {
      uStack_48 = 0x1220074;
      uStack_4c = 0;
      uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))();
      FUN_00401660(uVar5,0,0xffffffff);
      uStack_28 = 0xf;
      uStack_2c = 0;
      FUN_00401740(s_lbl_state_009db204,9);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x40);
      if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
        FUN_0055a260(&uStack_28);
      }
    }
    else {
      uStack_48 = 0x684155;
      uVar1 = (**(code **)(*DAT_00b5ac98 + 0x24))();
      if (uVar1 == 0) {
        uStack_48 = 0x684295;
        uVar1 = (**(code **)(*DAT_00b5ac98 + 0x28))();
        uStack_48 = 0x6842a2;
        uVar2 = (**(code **)(*DAT_00b5ac98 + 0x2c))();
        if (uVar1 != 0) {
          uStack_48 = (uint)(ushort)(uVar2 + uVar1 * -0x3c);
          uStack_4c = (uint)uVar1;
          uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x122006c);
          FUN_00765c50(uVar5);
          uVar5 = FUN_00404230((int)register0x00000010 + -0x40);
          FUN_00401660(uVar5,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        uStack_48 = (uint)uVar2;
        if (uVar2 == 0) {
          uStack_4c = 0x122006e;
          uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
          FUN_00765c50(uVar5);
          uVar5 = FUN_00404230((int)register0x00000010 + -0x40);
          FUN_00401660(uVar5,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        uStack_4c = 0x122006d;
        uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
        FUN_00765c50(uVar5);
        uVar5 = FUN_00404230((int)register0x00000010 + -0x40);
        FUN_00401660(uVar5,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      uStack_48 = (uint)uVar1;
      uStack_4c = 0x122006b;
      uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
      FUN_00401660(uVar5,0,0xffffffff);
      uVar5 = FUN_00404230((int)register0x00000010 + -0x40);
      FUN_00401660(uVar5,0,0xffffffff);
      if (0xf < uStack_28) {
        _free(unaff_EBX);
        return;
      }
      FUN_00401830(s_lbl_time_009db210);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x40);
      if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
        FUN_0055a260(&uStack_28);
      }
      if (0xf < uStack_2c) {
        _free(unaff_ESI);
        return;
      }
      uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x122006f);
      FUN_00401660(uVar5,0,0xffffffff);
      FUN_00401830(s_lbl_state_009db21c);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_4c);
      if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
        FUN_0055a260(&uStack_28);
      }
    }
    if (0xf < uStack_2c) {
      _free(unaff_ESI);
      return;
    }
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
  }
  return;
}


// ==== FUN_006844b0 @ 0x006844b0 ====

void FUN_006844b0(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined4 uVar5;
  char *pcVar6;
  int in_ECX;
  int iVar7;
  void *unaff_EBX;
  void **ppvVar8;
  void **ppvVar9;
  uint uVar10;
  undefined1 uVar11;
  undefined4 uStack_110;
  void *pvStack_10c;
  undefined4 uStack_104;
  void *pvStack_100;
  uint uStack_fc;
  uint uStack_f8;
  void *pvStack_f4;
  void *pvStack_f0;
  uint uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  uint uStack_e0;
  uint uStack_dc;
  uint uStack_d8;
  int iStack_d4;
  int local_d0;
  int iStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined1 auStack_c0 [4];
  void *pvStack_bc;
  undefined1 uStack_b8;
  undefined4 uStack_ac;
  uint uStack_a8;
  undefined4 uStack_a4;
  void *apvStack_a0 [4];
  undefined4 uStack_90;
  uint uStack_8c;
  void *apvStack_88 [4];
  undefined4 uStack_78;
  uint uStack_74;
  void *apvStack_64 [4];
  undefined4 uStack_54;
  uint uStack_50;
  char acStack_44 [58];
  undefined2 uStack_a;
  undefined2 uStack_8;
  
  local_d0 = in_ECX;
  piVar2 = (int *)(**(code **)(*DAT_00b5ac9c + 0x10))();
  if (piVar2 != (int *)0x0) {
    puVar3 = (undefined4 *)(**(code **)(*piVar2 + 4))();
    pcVar4 = acStack_44;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined4 *)pcVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      pcVar4 = pcVar4 + 4;
    }
    *(undefined2 *)pcVar4 = *(undefined2 *)puVar3;
    uStack_dc = 0xf;
    uStack_e0 = 0;
    pvStack_f0 = (void *)((uint)pvStack_f0 & 0xffffff00);
    FUN_00401740(s_guildbg_009db270,7);
    uStack_f8 = 0xf;
    uStack_fc = 0;
    pvStack_10c = (void *)((uint)pvStack_10c & 0xffffff00);
    FUN_00401740(s_pan_defMarkBg_009db278,0xd);
    FUN_00683e10(&uStack_110,&pvStack_f4,uStack_8);
    if (0xf < uStack_f8) {
      _free(pvStack_10c);
      return;
    }
    uStack_f8 = 0xf;
    uStack_fc = 0;
    pvStack_10c = (void *)((uint)pvStack_10c & 0xffffff00);
    if (0xf < uStack_dc) {
      _free(pvStack_f0);
      return;
    }
    uStack_dc = 0xf;
    uStack_e0 = 0;
    pvStack_f0 = (void *)((uint)pvStack_f0 & 0xffffff00);
    FUN_00401740(s_guildicon_009db288,9);
    uStack_f8 = 0xf;
    uStack_fc = 0;
    pvStack_10c = (void *)((uint)pvStack_10c & 0xffffff00);
    FUN_00401740(s_pan_defMark_009db294,0xb);
    FUN_00683e10(&uStack_110,&pvStack_f4,uStack_a);
    if (0xf < uStack_f8) {
      _free(pvStack_10c);
      return;
    }
    uStack_f8 = 0xf;
    uStack_fc = 0;
    pvStack_10c = (void *)((uint)pvStack_10c & 0xffffff00);
    if (0xf < uStack_dc) {
      _free(pvStack_f0);
      return;
    }
    uStack_dc = 0xf;
    uStack_e0 = 0;
    pvStack_f0 = (void *)((uint)pvStack_f0 & 0xffffff00);
    FUN_00401740(s_lbl_defenderName_009db2a0,0x10);
    pcVar4 = acStack_44;
    uStack_f8 = 0xf;
    uStack_fc = 0;
    pvStack_10c = (void *)((uint)pvStack_10c & 0xffffff00);
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_44,(int)pcVar4 - (int)(acStack_44 + 1));
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_f4);
    if ((piVar2 != (int *)0x0) && (iVar7 = (**(code **)(*piVar2 + 0x30))(), iVar7 != 0)) {
      FUN_0055a260(auStack_c0 + -0x54);
    }
    if (0xf < uStack_fc) {
      _free(uStack_110);
      return;
    }
    uStack_fc = 0xf;
    pvStack_100 = (void *)0x0;
    uStack_110 = (void *)((uint)uStack_110 & 0xffffff00);
    if (0xf < uStack_e0) {
      _free(pvStack_f4);
      return;
    }
    piVar2 = (int *)(**(code **)(*DAT_00b5abec + 0x10))();
    while (piVar2 != (int *)0x0) {
      pcVar4 = (char *)(**(code **)(*piVar2 + 4))();
      uStack_fc = 0xf;
      pvStack_100 = (void *)0x0;
      uStack_110 = (void *)((uint)uStack_110 & 0xffffff00);
      FUN_00401740(s_guildbg_009db2b4,7);
      FUN_00401740(s_pan_attMarkBg__d_009db2bc,0x10);
      ppvVar9 = apvStack_64;
      uVar5 = FUN_00404230(ppvVar9);
      uStack_d8 = (uint)*(ushort *)(pcVar4 + 0x3c);
      piVar2 = (int *)(**(code **)(**(int **)(iStack_d4 + 4) + 0x34))(uVar5);
      if ((piVar2 != (int *)0x0) && (uStack_e0 = (**(code **)(*piVar2 + 0x30))(), uStack_e0 != 0)) {
        iStack_d4 = *(undefined4 *)(uStack_e0 + 0x8c);
        local_d0 = *(int *)(uStack_e0 + 0x90);
        iStack_cc = uStack_dc;
        iStack_d4 = (**(code **)(*DAT_00b5a7c0 + 8))(auStack_c0 + -0x58);
        FUN_00587d40(&uStack_d8);
      }
      if (0xf < uStack_50) {
        _free(apvStack_64[0]);
        return;
      }
      uStack_50 = 0xf;
      uStack_54 = 0;
      apvStack_64[0] = (void *)((uint)apvStack_64[0] & 0xffffff00);
      if (0xf < pvStack_100) {
        _free(unaff_EBX);
        return;
      }
      pvStack_100 = (void *)0xf;
      uStack_104 = 0;
      unaff_EBX = (void *)((uint)unaff_EBX & 0xffffff00);
      uStack_a4 = 0xf;
      uStack_a8 = 0;
      uStack_b8 = 0;
      FUN_00401740(s_guildicon_009db2d0,9);
      uVar11 = 0;
      FUN_00401740(s_pan_attMark__d_009db2dc,0xe);
      ppvVar8 = apvStack_a0;
      uVar5 = FUN_00404230(ppvVar8,ppvVar9,uVar11);
      uStack_e0 = (uint)*(ushort *)(pcVar4 + 0x3a);
      piVar2 = (int *)(**(code **)(**(int **)(uStack_d8 + 4) + 0x34))(uVar5);
      if ((piVar2 != (int *)0x0) && (uStack_e0 = (**(code **)(*piVar2 + 0x30))(), uStack_e0 != 0)) {
        iStack_cc = *(undefined4 *)(uStack_e0 + 0x8c);
        uStack_c8 = *(undefined4 *)(uStack_e0 + 0x90);
        uStack_c4 = uStack_e4;
        iStack_cc = (**(code **)(*DAT_00b5a7c0 + 8))(auStack_c0);
        FUN_00587d40(&local_d0);
      }
      if (0xf < uStack_8c) {
        _free(apvStack_a0[0]);
        return;
      }
      uStack_8c = 0xf;
      uStack_90 = 0;
      apvStack_a0[0] = (void *)((uint)apvStack_a0[0] & 0xffffff00);
      if (0xf < uStack_a8) {
        _free(pvStack_bc);
        return;
      }
      uStack_a8 = 0xf;
      uStack_ac = 0;
      pvStack_bc = (void *)((uint)pvStack_bc & 0xffffff00);
      uStack_e8 = 0xf;
      uStack_ec = 0;
      uStack_fc = uStack_fc & 0xffffff00;
      pcVar6 = pcVar4;
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_00401740(pcVar4,(int)pcVar6 - (int)(pcVar4 + 1));
      uVar10 = (uint)ppvVar9 & 0xffffff00;
      FUN_00401740(s_lbl_attackerName__d_009db2ec,0x13);
      uVar5 = FUN_00404230(apvStack_88,ppvVar8,uVar10);
      piVar2 = (int *)(**(code **)(**(int **)(uStack_dc + 4) + 0x34))(uVar5);
      if ((piVar2 != (int *)0x0) && (iVar7 = (**(code **)(*piVar2 + 0x30))(), iVar7 != 0)) {
        FUN_0055a260(&uStack_104);
      }
      if (0xf < uStack_74) {
        _free(apvStack_88[0]);
        return;
      }
      uStack_74 = 0xf;
      uStack_78 = 0;
      apvStack_88[0] = (void *)((uint)apvStack_88[0] & 0xffffff00);
      if (0xf < uStack_ec) {
        _free(pvStack_100);
        return;
      }
      uStack_ec = 0xf;
      pvStack_f0 = (void *)0x0;
      pvStack_100 = (void *)((uint)pvStack_100 & 0xffffff00);
      piVar2 = (int *)(**(code **)(*DAT_00b5abec + 0x14))();
    }
  }
  return;
}


// ==== FUN_00684a00 @ 0x00684a00 ====

void FUN_00684a00(void)

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
  FUN_00401740(s_UI_Game2_Siege_ui_warstatewnd_tx_009db1cc,0x21);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_00683f40();
    FUN_00684090();
    FUN_006844b0();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00684a90 @ 0x00684a90 ====

uint FUN_00684a90(int *param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if ((uVar1 == 0x40001) &&
     (*(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + param_1[1], 999 < *(uint *)(in_ECX + 0x24)
     )) {
    FUN_00684090();
    uVar1 = FUN_006844b0();
    *(undefined4 *)(in_ECX + 0x24) = 0;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00684ae0 @ 0x00684ae0 ====

void FUN_00684ae0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009db314;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[1] = 0;
  in_ECX[9] = 0;
  FUN_00684a00();
  return;
}


// ==== FUN_00684b10 @ 0x00684b10 ====

void FUN_00684b10(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009db314;
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


// ==== FUN_00684b70 @ 0x00684b70 ====

void FUN_00684b70(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x00684b7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_00684b80 @ 0x00684b80 ====

undefined1 FUN_00684b80(void)

{
  return 0;
}


// ==== FUN_00684b90 @ 0x00684b90 ====

undefined1 FUN_00684b90(void)

{
  return 0;
}


// ==== FUN_00684ba0 @ 0x00684ba0 ====

void FUN_00684ba0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009db450;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00684bc0 @ 0x00684bc0 ====

void FUN_00684bc0(void)

{
  char cVar1;
  int *piVar2;
  int *in_ECX;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x2c))();
  cVar1 = (**(code **)(*piVar2 + 0x1c))();
  if (cVar1 == '\x01') {
    (**(code **)(*in_ECX + 0xc))(1);
    *(undefined1 *)(in_ECX + 4) = 1;
    *(undefined1 *)((int)in_ECX + 0x11) = 1;
    return;
  }
  (**(code **)(*in_ECX + 0xc))(0);
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined1 *)((int)in_ECX + 0x11) = 1;
  return;
}


// ==== FUN_00684c10 @ 0x00684c10 ====

void FUN_00684c10(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
    FUN_0055a260(param_1);
  }
  return;
}


// ==== FUN_00684c40 @ 0x00684c40 ====

/* WARNING: Removing unreachable block (ram,0x00684ccd) */

void FUN_00684c40(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *in_ECX;
  undefined4 uStack_44;
  undefined4 uStack_2c;
  void *pvStack_28;
  undefined1 uStack_24;
  uint uStack_14;
  undefined4 uStack_10;
  
  uStack_44 = 1;
  (**(code **)(*in_ECX + 0xc))();
  uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1220078);
  uStack_10 = 0xf;
  uStack_14 = 0;
  uStack_24 = 0;
  FUN_00401660(uVar1,0,0xffffffff);
  uStack_2c = 0xf;
  FUN_00401740(s_lbl_text_009db3ac,8);
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(&uStack_44);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_0055a260(&uStack_2c);
  }
  if (uStack_14 < 0x10) {
    return;
  }
  _free(pvStack_28);
  return;
}


// ==== FUN_00684d00 @ 0x00684d00 ====

/* WARNING: Removing unreachable block (ram,0x00684e1b) */

void FUN_00684d00(void)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  char *pcVar4;
  undefined4 uStack_48;
  undefined4 uStack_44;
  void *apvStack_28 [5];
  uint uStack_14;
  
  uStack_44 = 1;
  uStack_48 = 0x684d12;
  (**(code **)(*in_ECX + 0xc))();
  uStack_48 = 0x684d1d;
  piVar2 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  uStack_48 = 0x684d24;
  piVar2 = (int *)(**(code **)(*piVar2 + 0x2c))();
  uStack_48 = 0x684d2b;
  cVar1 = (**(code **)(*piVar2 + 0x1c))();
  if (cVar1 == '\x01') {
    in_ECX[3] = 1;
    *(undefined1 *)(in_ECX + 4) = 1;
    return;
  }
  uStack_48 = 0x684d46;
  cVar1 = (**(code **)(*DAT_00b5ac98 + 0x44))();
  if (cVar1 == '\0') {
    if (in_ECX[3] == 0) {
      return;
    }
    in_ECX[3] = 0;
    uStack_48 = 0x122007b;
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
    FUN_00401660(uVar3,0,0xffffffff);
    pcVar4 = s_lbl_text_009db3b8;
  }
  else {
    if (in_ECX[3] == 2) {
      return;
    }
    in_ECX[3] = 2;
    uStack_48 = 0x122007c;
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
    FUN_00401660(uVar3,0,0xffffffff);
    pcVar4 = s_lbl_text_009db3c4;
  }
  FUN_00401830(pcVar4);
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(apvStack_28);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_0055a260(&uStack_48);
  }
  if (uStack_14 < 0x10) {
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(apvStack_28[0]);
  return;
}


// ==== FUN_00684e40 @ 0x00684e40 ====

/* WARNING: Removing unreachable block (ram,0x00684ecd) */

void FUN_00684e40(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *in_ECX;
  undefined4 uStack_44;
  undefined4 uStack_2c;
  void *pvStack_28;
  undefined1 uStack_24;
  uint uStack_14;
  undefined4 uStack_10;
  
  uStack_44 = 1;
  (**(code **)(*in_ECX + 0xc))();
  uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1220079);
  uStack_10 = 0xf;
  uStack_14 = 0;
  uStack_24 = 0;
  FUN_00401660(uVar1,0,0xffffffff);
  uStack_2c = 0xf;
  FUN_00401740(s_lbl_text_009db3d0,8);
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(&uStack_44);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_0055a260(&uStack_2c);
  }
  if (uStack_14 < 0x10) {
    return;
  }
  _free(pvStack_28);
  return;
}


// ==== FUN_00684f00 @ 0x00684f00 ====

/* WARNING: Removing unreachable block (ram,0x00684f8d) */

void FUN_00684f00(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *in_ECX;
  undefined4 uStack_44;
  undefined4 uStack_2c;
  void *pvStack_28;
  undefined1 uStack_24;
  uint uStack_14;
  undefined4 uStack_10;
  
  uStack_44 = 1;
  (**(code **)(*in_ECX + 0xc))();
  uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x122007a);
  uStack_10 = 0xf;
  uStack_14 = 0;
  uStack_24 = 0;
  FUN_00401660(uVar1,0,0xffffffff);
  uStack_2c = 0xf;
  FUN_00401740(s_lbl_text_009db3dc,8);
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(&uStack_44);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_0055a260(&uStack_2c);
  }
  if (uStack_14 < 0x10) {
    return;
  }
  _free(pvStack_28);
  return;
}


// ==== FUN_00684fc0 @ 0x00684fc0 ====

/* WARNING: Removing unreachable block (ram,0x006850d6) */
/* WARNING: Removing unreachable block (ram,0x0068520d) */

void FUN_00684fc0(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int in_ECX;
  void *unaff_EBX;
  char *pcVar6;
  undefined1 auStack_56 [14];
  uint uStack_48;
  undefined4 uStack_44;
  void *pvStack_40;
  undefined1 uStack_3c;
  uint uStack_2c;
  undefined4 uStack_28;
  void *apvStack_24 [5];
  uint uStack_10;
  
  uVar2 = (**(code **)(*DAT_00b5ac98 + 0x34))();
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  if (uVar3 / 1000 <= uVar2) {
    uVar3 = uVar2 - uVar3 / 1000;
    if (uVar2 == 0) {
      uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1220032);
      uStack_28 = 0xf;
      uStack_2c = 0;
      uStack_3c = 0;
      FUN_00401660(uVar5,0,0xffffffff);
      uStack_44 = 0xf;
      FUN_00401740(s_lbl_text_009db418,8);
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_56 + -6);
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x30))();
        FUN_0055a260(&uStack_44);
      }
      if (uStack_2c < 0x10) {
        return;
      }
      _free(pvStack_40);
      return;
    }
    if (uVar3 / 0x3c == 0) {
      if (uVar3 % 0x3c == 0) {
        uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1220036);
        FUN_00765c50(uVar5);
        FUN_00401830(s_lbl_text_009db43c);
        FUN_00684c10(apvStack_24,&pvStack_40);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1220034);
      FUN_00765c50(uVar5);
      FUN_00401830(s_lbl_text_009db430);
      FUN_00765c50(&pvStack_40);
      uVar5 = FUN_00404230(auStack_56 + -6);
      FUN_00684c10(apvStack_24,uVar5);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1220033);
    uStack_28 = 0xf;
    uStack_2c = 0;
    uStack_3c = 0;
    FUN_00401660(uVar5,0,0xffffffff);
    FUN_00401830(s_lbl_text_009db424);
    FUN_00401660(&pvStack_40,0,0xffffffff);
    uVar5 = FUN_00404230(auStack_56 + -6);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_24);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x30))();
      FUN_0055a260(uVar5);
    }
    if (0xf < uStack_48) {
      _free(unaff_EBX);
      return;
    }
    if (0xf < uStack_10) {
      _free(apvStack_24[0]);
      return;
    }
    if (uStack_2c < 0x10) {
      return;
    }
    _free(pvStack_40);
    return;
  }
  piVar4 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar4 = (int *)(**(code **)(*piVar4 + 0x2c))();
  cVar1 = (**(code **)(*piVar4 + 0x1c))();
  if (cVar1 == '\x01') {
    cVar1 = (**(code **)(*DAT_00b5ac98 + 0x44))();
    if (cVar1 == '\x01') {
      uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1220036);
      uStack_44 = 0xf;
      FUN_00401660(uVar5,0,0xffffffff);
      pcVar6 = s_lbl_text_009db3e8;
    }
    else {
      uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1220035);
      uStack_44 = 0xf;
      FUN_00401660(uVar5,0,0xffffffff);
      pcVar6 = s_lbl_text_009db3f4;
    }
  }
  else {
    cVar1 = (**(code **)(*DAT_00b5ac98 + 0x44))();
    if (cVar1 == '\0') {
      uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1220032);
      uStack_44 = 0xf;
      FUN_00401660(uVar5,0,0xffffffff);
      FUN_00401830(s_lbl_text_009db400);
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_40);
      goto LAB_0068509d;
    }
    uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1220035);
    uStack_44 = 0xf;
    FUN_00401660(uVar5,0,0xffffffff);
    pcVar6 = s_lbl_text_009db40c;
  }
  FUN_00401830(pcVar6);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_40);
LAB_0068509d:
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 0x30))();
    FUN_0055a260(auStack_56 + -10);
  }
  if (uStack_2c < 0x10) {
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_006853d0 @ 0x006853d0 ====

void FUN_006853d0(void)

{
  char cVar1;
  int *in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
  if (cVar1 == '\0') {
    in_ECX[3] = 3;
    (**(code **)(*in_ECX + 0xc))(0);
    return;
  }
  FUN_00684fc0();
  return;
}


// ==== FUN_00685400 @ 0x00685400 ====

void FUN_00685400(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8);
  if (iVar1 == param_1) {
    if (iVar1 == 2) {
      return;
    }
    if (iVar1 == 4) {
      return;
    }
    if (iVar1 == 5) {
      return;
    }
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
    cVar2 = (**(code **)(*piVar3 + 0x28))();
    if (cVar2 == '\0') {
      return;
    }
  }
  switch(param_1) {
  case 0:
    FUN_006853d0();
    *(int *)(in_ECX + 8) = param_1;
    return;
  case 1:
    if (*(char *)(in_ECX + 0x11) != '\x01') {
      FUN_00684bc0();
      *(int *)(in_ECX + 8) = param_1;
      return;
    }
    break;
  case 2:
    FUN_00684c40();
    *(int *)(in_ECX + 8) = param_1;
    return;
  case 3:
    FUN_00684d00();
    *(int *)(in_ECX + 8) = param_1;
    return;
  case 4:
    FUN_00684e40();
    *(int *)(in_ECX + 8) = param_1;
    return;
  case 5:
    FUN_00684f00();
  default:
    *(int *)(in_ECX + 8) = param_1;
  }
  return;
}


// ==== FUN_006854c0 @ 0x006854c0 ====

void FUN_006854c0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_Siege_ui_siege_play_tim_009db380,0x28);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    *(undefined1 *)(in_ECX + 0x10) = 0;
    *(undefined1 *)(in_ECX + 0x11) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 3;
    uVar3 = (**(code **)(*DAT_00b5acac + 0x48))();
    FUN_00685400(uVar3);
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00685560 @ 0x00685560 ====

uint FUN_00685560(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    if (*(char *)(in_ECX + 0x10) == '\x01') {
      FUN_00684fc0();
    }
    uVar2 = (**(code **)(*DAT_00b5acac + 0x48))();
    uVar1 = FUN_00685400(uVar2);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006855a0 @ 0x006855a0 ====

void FUN_006855a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009db450;
  FUN_006854c0();
  return;
}


// ==== FUN_006855c0 @ 0x006855c0 ====

undefined4 FUN_006855c0(void)

{
  return 0x65;
}


// ==== FUN_006855d0 @ 0x006855d0 ====

void FUN_006855d0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009db450;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00685610 @ 0x00685610 ====

void FUN_00685610(void)

{
  return;
}


// ==== FUN_00685620 @ 0x00685620 ====

void FUN_00685620(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009db548;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00685640 @ 0x00685640 ====

int FUN_00685640(void)

{
  int *piVar1;
  int extraout_EAX;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int extraout_EAX_00;
  int in_ECX;
  uint uVar5;
  void *local_38;
  undefined1 local_34;
  undefined4 uStack_28;
  void *local_24;
  undefined4 local_20;
  uint uStack_10;
  
  uVar5 = *(int *)(in_ECX + 8) - *(int *)(in_ECX + 0xc);
  iVar4 = uVar5 * 0x10624dd3;
  uVar5 = uVar5 / 1000;
  if (*(uint *)(in_ECX + 0x10) != uVar5) {
    *(uint *)(in_ECX + 0x10) = uVar5;
    local_20 = 0xf;
    local_24 = (void *)0x0;
    local_34 = 0;
    FUN_00401740(s_lbl_waittime_009db4e0,0xc);
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
    if (0xf < local_24) {
      _free(local_38);
      return extraout_EAX;
    }
    local_24 = (void *)0xf;
    uStack_28 = 0;
    local_38 = (void *)((uint)local_38 & 0xffffff00);
    iVar4 = 0;
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x30))();
      iVar4 = 0;
      if (iVar2 != 0) {
        uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1220029,*(undefined4 *)(in_ECX + 0x10));
        FUN_00401660(uVar3,0,0xffffffff);
        FUN_00404230(&uStack_28);
        iVar4 = FUN_0055a260(&uStack_28);
        if (0xf < uStack_10) {
          _free(local_24);
          return extraout_EAX_00;
        }
      }
    }
  }
  return iVar4;
}


// ==== FUN_00685730 @ 0x00685730 ====

/* WARNING: Removing unreachable block (ram,0x00685b9a) */
/* WARNING: Removing unreachable block (ram,0x006859db) */

void FUN_00685730(void)

{
  char cVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 ****ppppuVar8;
  char *pcVar9;
  undefined1 auStack_13e [22];
  int iStack_128;
  int iStack_124;
  void *local_120;
  undefined1 uStack_114;
  undefined4 uStack_110;
  uint uStack_10c;
  void *pvStack_104;
  undefined4 ****appppuStack_100 [2];
  undefined1 uStack_f8;
  uint uStack_f0;
  uint uStack_ec;
  undefined4 uStack_e8;
  void *pvStack_e4;
  undefined4 uStack_d4;
  uint uStack_d0;
  undefined1 auStack_cc [4];
  void *pvStack_c8;
  undefined4 uStack_b8;
  uint uStack_b4;
  undefined1 auStack_b0 [4];
  void *pvStack_ac;
  undefined4 uStack_9c;
  uint uStack_98;
  undefined1 auStack_94 [4];
  void *pvStack_90;
  undefined4 uStack_80;
  uint uStack_7c;
  undefined1 auStack_78 [4];
  void *pvStack_74;
  undefined4 uStack_64;
  uint uStack_60;
  undefined1 auStack_5c [4];
  void *pvStack_58;
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
  
  piVar3 = (int *)(**(code **)(*DAT_00b5acac + 0x30))();
  if (piVar3 != (int *)0x0) {
    iVar4 = (**(code **)(*piVar3 + 0xc))();
    pvStack_e4 = (void *)0xf;
    uStack_e8 = 0;
    uStack_f8 = 0;
    pcVar9 = (char *)(iVar4 + 0x200);
    do {
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    FUN_00401740((char *)(iVar4 + 0x200),(int)pcVar9 - (iVar4 + 0x201));
    appppuStack_100[0] = (undefined4 ****)0xf;
    pvStack_104 = (void *)0x0;
    uStack_114 = 0;
    uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(8,0x1fe0001);
    FUN_00401660(uVar5,0,0xffffffff);
    iStack_124 = (**(code **)(*DAT_00b5ac98 + 8))();
    piVar3 = (int *)(**(code **)(*DAT_00b5ab04 + 8))();
    while (piVar3 != (int *)0x0) {
      puVar6 = (undefined4 *)(**(code **)(*piVar3 + 4))();
      piVar3 = DAT_00b5a794;
      if (puVar6[2] == iStack_124) {
        uVar2 = *(ushort *)((int)puVar6 + 6);
        FUN_00401740(&DAT_009db4f0,2);
        uVar5 = FUN_00404230(auStack_78);
        uVar5 = (**(code **)(*piVar3 + 0xc))(8,uVar2 | 0x1fe0000,&DAT_009db4f4,uVar5);
        uVar5 = FUN_004022a0(auStack_40,&DAT_009db4f8,uVar5);
        uVar5 = FUN_00402220(auStack_b0,uVar5);
        uVar5 = FUN_00405bd0(&uStack_e8,uVar5);
        FUN_00401ff0(uVar5,0,0xffffffff);
        if (0xf < uStack_d0) {
          _free(pvStack_e4);
          return;
        }
        uStack_d0 = 0xf;
        uStack_d4 = 0;
        pvStack_e4 = (void *)((uint)pvStack_e4 & 0xffffff00);
        if (0xf < uStack_98) {
          _free(pvStack_ac);
          return;
        }
        uStack_98 = 0xf;
        uStack_9c = 0;
        pvStack_ac = (void *)((uint)pvStack_ac & 0xffffff00);
        if (0xf < uStack_28) {
          _free(pvStack_3c);
          return;
        }
        uStack_28 = 0xf;
        uStack_2c = 0;
        pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
        if (0xf < uStack_60) {
          _free(pvStack_74);
          return;
        }
        uStack_60 = 0xf;
        uStack_64 = 0;
        pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
      }
      else if (((puVar6[2] == 4) &&
               (piVar3 = (int *)(**(code **)(*DAT_00b5aaf8 + 8))(*puVar6), piVar3 != (int *)0x0)) &&
              (piVar3 = (int *)(**(code **)(*piVar3 + 0xc))(), piVar3 != (int *)0x0)) {
        pcVar7 = (char *)(**(code **)(*piVar3 + 4))();
        pcVar9 = pcVar7;
        do {
          cVar1 = *pcVar9;
          pcVar9 = pcVar9 + 1;
        } while (cVar1 != '\0');
        FUN_00401740(pcVar7,(int)pcVar9 - (int)(pcVar7 + 1));
        ppppuVar8 = appppuStack_100[0];
        if (uStack_ec < 0x10) {
          ppppuVar8 = appppuStack_100;
        }
        iVar4 = FUN_00403620(0,0,ppppuVar8,uStack_f0);
        piVar3 = DAT_00b5a794;
        if (iVar4 == 0) {
          uVar2 = *(ushort *)((int)puVar6 + 6);
          FUN_00401830(&DAT_009db4fc);
          uVar5 = FUN_00404230(auStack_24);
          uVar5 = (**(code **)(*piVar3 + 0xc))(8,uVar2 | 0x1fe0000,&DAT_009db500,uVar5);
          uVar5 = FUN_004022a0(auStack_5c,&DAT_009db504,uVar5);
          uVar5 = FUN_00402220(auStack_94,uVar5);
          uVar5 = FUN_00405bd0(auStack_cc,uVar5);
          FUN_00401ff0(uVar5,0,0xffffffff);
          if (0xf < uStack_b4) {
            _free(pvStack_c8);
            return;
          }
          uStack_b4 = 0xf;
          uStack_b8 = 0;
          pvStack_c8 = (void *)((uint)pvStack_c8 & 0xffffff00);
          if (0xf < uStack_7c) {
            _free(pvStack_90);
            return;
          }
          uStack_7c = 0xf;
          uStack_80 = 0;
          pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
          if (0xf < uStack_44) {
            _free(pvStack_58);
            return;
          }
          uStack_44 = 0xf;
          uStack_48 = 0;
          pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
          if (0xf < uStack_c) {
            _free(pvStack_20);
            return;
          }
          uStack_c = 0xf;
          uStack_10 = 0;
          pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
        }
      }
      piVar3 = (int *)(**(code **)(*DAT_00b5ab04 + 0xc))();
    }
    FUN_00401740(s_textbox_009db508,7);
    piVar3 = (int *)(**(code **)(**(int **)(iStack_128 + 4) + 0x34))(auStack_13e + -6);
    (**(code **)(*piVar3 + 0x30))();
    FUN_005569f0(&iStack_124,1);
    if (0xf < uStack_10c) {
      _free(local_120);
      return;
    }
    uStack_10c = 0xf;
    uStack_110 = 0;
    local_120 = (void *)((uint)local_120 & 0xffffff00);
    if (0xf < uStack_f0) {
      _free(pvStack_104);
      return;
    }
  }
  return;
}


// ==== FUN_00685c10 @ 0x00685c10 ====

void FUN_00685c10(void)

{
  int *piVar1;
  int in_ECX;
  void *unaff_EBP;
  undefined4 local_1c;
  undefined1 local_18;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  FUN_00685730();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_waittime_009db510,0xc);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(0);
    uStack_c = 0xf;
    uStack_10 = 0;
    FUN_00401740(s_pan_list_009db520,8);
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x24);
    if (0xf < uStack_10) {
      _free(unaff_EBP);
      return;
    }
    uStack_10 = 0xf;
    uStack_14 = 0;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x24))(1);
      *(undefined4 *)(in_ECX + 8) = 0;
    }
  }
  return;
}


// ==== FUN_00685ce0 @ 0x00685ce0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00685ce0(int param_1)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  void *local_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  uVar1 = *(uint *)(in_ECX + 8);
  if ((uVar1 != 0) && (*(uint *)(in_ECX + 0xc) < uVar1)) {
    uVar6 = *(uint *)(in_ECX + 0xc) + *(int *)(param_1 + 4);
    *(uint *)(in_ECX + 0xc) = uVar6;
    if (uVar1 < uVar6) {
      *(uint *)(in_ECX + 0xc) = uVar1;
    }
    if (*(uint *)(in_ECX + 0xc) < uVar1) {
      FUN_00401830(s_processbar_009db52c);
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_1c);
      if (0xf < uStack_8) {
        _free(local_1c[0]);
        return;
      }
      uStack_8 = 0xf;
      uStack_c = 0;
      local_1c[0] = (void *)((uint)local_1c[0] & 0xffffff00);
      if ((piVar4 != (int *)0x0) && (iVar5 = (**(code **)(*piVar4 + 0x30))(), iVar5 != 0)) {
        fVar2 = (float)*(int *)(in_ECX + 0xc);
        if (*(int *)(in_ECX + 0xc) < 0) {
          fVar2 = fVar2 + _DAT_0099d104;
        }
        fVar3 = (float)*(int *)(in_ECX + 8);
        if (*(int *)(in_ECX + 8) < 0) {
          fVar3 = fVar3 + _DAT_0099d104;
        }
        FUN_00587ba0((fVar2 / fVar3) * DAT_0099de78);
        FUN_00685640();
      }
    }
    else if (*(uint *)(in_ECX + 0xc) == uVar1) {
      FUN_00685c10();
      return;
    }
  }
  return;
}


// ==== FUN_00685dd0 @ 0x00685dd0 ====

/* WARNING: Removing unreachable block (ram,0x00685e12) */

void FUN_00685dd0(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  undefined1 auStack_34 [4];
  int iVar5;
  
  FUN_00401740(s_UI_Game2_Siege_ui_respawnwnd_txt_009db4bc);
  iVar1 = FUN_00410500();
  iVar5 = 0;
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar1 != 0) {
    iVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    FUN_00826dc0(iVar1,iVar3,auStack_34 + 8);
    uVar4 = iVar5 - iVar3;
    *(uint *)(in_ECX + 8) = uVar4;
    *(uint *)(in_ECX + 0x10) = uVar4 / 1000;
    if (uVar4 == 0) {
      FUN_00685c10();
      return;
    }
    FUN_00685640();
  }
  return;
}


// ==== FUN_00685ea0 @ 0x00685ea0 ====

void FUN_00685ea0(void)

{
  int *in_ECX;
  
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  in_ECX[1] = 0;
  (**(code **)(*in_ECX + 4))();
  FUN_00685c10();
  return;
}


// ==== FUN_00685ed0 @ 0x00685ed0 ====

void FUN_00685ed0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009db548;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[1] = 0;
  FUN_00685dd0();
  return;
}


// ==== FUN_00685ef0 @ 0x00685ef0 ====

undefined4 FUN_00685ef0(int *param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    FUN_00685ce0(param_1);
  }
  else if (iVar1 == 0x70910026) {
    (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
    in_ECX[1] = 0;
    (**(code **)(*in_ECX + 4))();
    FUN_00685c10();
    return 1;
  }
  return 0;
}


// ==== FUN_00685f50 @ 0x00685f50 ====

undefined4 FUN_00685f50(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_10 [4];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  FUN_00404fb0(param_2,0x5f,local_10);
  iVar1 = FUN_00405d30(1);
  iVar1 = FUN_00403620(0,*(undefined4 *)(iVar1 + 0x14),s_select_009db538,6);
  if (iVar1 == 0) {
    uVar2 = FUN_00405d30(0);
    uVar2 = thunk_FUN_00796f80(uVar2);
    (**(code **)(*DAT_00b5ac94 + 0x6c))(uVar2);
  }
  FUN_00406250();
  return 1;
}


// ==== FUN_00685ff0 @ 0x00685ff0 ====

void FUN_00685ff0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009db548;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00686030 @ 0x00686030 ====

void FUN_00686030(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00686032. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 4))();
  return;
}


// ==== FUN_00686050 @ 0x00686050 ====

undefined4 FUN_00686050(void)

{
  (**(code **)(*DAT_00b5ac94 + 0x4c))();
  return 1;
}


// ==== FUN_00686090 @ 0x00686090 ====

undefined4 FUN_00686090(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_yes_009db5e8,7);
  if ((iVar2 == 0) || (cVar1 = FUN_004036a0(param_2,s_btn_exit_009db5f0), cVar1 != '\0')) {
    (**(code **)(*DAT_00b5ac94 + 0x4c))();
    return 1;
  }
  return 0;
}


// ==== FUN_00686150 @ 0x00686150 ====

/* WARNING: Removing unreachable block (ram,0x006861ac) */

undefined4 FUN_00686150(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uStack_24;
  
  uStack_24 = param_1;
  uVar2 = (**(code **)(*DAT_00b5ac98 + 0x20))();
  piVar3 = (int *)(**(code **)(*DAT_00b5abc8 + 8))(uVar2);
  if (piVar3 == (int *)0x0) {
    FUN_00401740(s_pFlyweight_009db5fc,10);
    FUN_00406880(&uStack_24);
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)();
    return uVar2;
  }
  iVar4 = (**(code **)(*piVar3 + 4))();
  return *(undefined4 *)(iVar4 + 0x30);
}


// ==== FUN_006861d0 @ 0x006861d0 ====

/* WARNING: Removing unreachable block (ram,0x0068622c) */

undefined4 FUN_006861d0(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uStack_24;
  
  uStack_24 = param_1;
  uVar2 = (**(code **)(*DAT_00b5ac98 + 0x20))();
  piVar3 = (int *)(**(code **)(*DAT_00b5abc8 + 8))(uVar2);
  if (piVar3 == (int *)0x0) {
    FUN_00401740(s_pFlyweight_009db608,10);
    FUN_00406880(&uStack_24);
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)();
    return uVar2;
  }
  iVar4 = (**(code **)(*piVar3 + 4))();
  return *(undefined4 *)(iVar4 + 0x2c);
}


// ==== FUN_00686250 @ 0x00686250 ====

int FUN_00686250(int param_1,int param_2)

{
  code *pcVar1;
  int extraout_EAX;
  int iVar2;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int extraout_EAX_02;
  char *pcVar3;
  undefined4 uVar4;
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
  
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  FUN_00401740(&DAT_009db613,0);
  if (param_2 == 0) {
    uVar4 = 4;
    pcVar3 = &DAT_009db614;
  }
  else if (param_2 == 1) {
    uVar4 = 4;
    pcVar3 = &DAT_009db61c;
  }
  else {
    if (param_2 != 2) {
      FUN_00401830(s_FALSE_009db62c);
      FUN_00406880(local_38);
      if (local_20 < 0x10) {
        local_20 = 0xf;
        local_24 = 0;
        local_34 = (void *)((uint)local_34 & 0xffffff00);
        pcVar1 = (code *)swi(3);
        iVar2 = (*pcVar1)();
        return iVar2;
      }
      _free(local_34);
      return extraout_EAX;
    }
    uVar4 = 5;
    pcVar3 = s_south_009db624;
  }
  FUN_00401740(pcVar3,uVar4);
  uVar4 = FUN_004022a0(local_1c,&DAT_009db63c,local_54,s__value_009db634);
  uVar4 = FUN_00402220(local_38,uVar4);
  FUN_00401660(uVar4,0,0xffffffff);
  if (0xf < local_20) {
    _free(local_34);
    return extraout_EAX_00;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX_01;
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_54,0,0xffffffff);
  if (local_3c < 0x10) {
    return param_1;
  }
  _free(local_50);
  return extraout_EAX_02;
}


// ==== FUN_006863a0 @ 0x006863a0 ====

void FUN_006863a0(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009db64c;
  _Memory = (void *)in_ECX[3];
  if ((_Memory != (void *)0x0) && (in_ECX[4] - (int)_Memory >> 3 != 0)) {
    if (_Memory != (void *)0x0) {
      _free(_Memory);
      return;
    }
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
  }
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if ((void *)in_ECX[3] == (void *)0x0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00686410 @ 0x00686410 ====

void FUN_00686410(void)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  int in_ECX;
  uint local_58;
  undefined1 local_54 [4];
  void *local_50;
  undefined4 local_40;
  uint local_3c;
  undefined1 local_38 [4];
  void *pvStack_34;
  undefined4 uStack_24;
  uint uStack_20;
  undefined1 local_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  local_58 = 0;
  while( true ) {
    if ((2 < local_58) || (iVar1 = *(int *)(in_ECX + 0xc) + local_58 * 8, iVar1 == 0)) {
      local_3c = 0xf;
      local_40 = 0;
      local_50 = (void *)((uint)local_50 & 0xffffff00);
      FUN_00401740(s_pStock_009db5d8,6);
      FUN_00406880(local_54);
      if (local_3c < 0x10) {
        local_3c = 0xf;
        local_40 = 0;
        local_50 = (void *)((uint)local_50 & 0xffffff00);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      _free(local_50);
      return;
    }
    FUN_006861d0(*(undefined4 *)(iVar1 + 4));
    FUN_00686150(*(undefined4 *)(iVar1 + 4));
    FUN_00401740(s__d____d_009db5e0,7);
    FUN_00404230(local_1c);
    FUN_00686250(local_38,local_58);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_38);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x30))();
      FUN_0055a260(local_1c);
    }
    if (0xf < uStack_20) break;
    uStack_20 = 0xf;
    uStack_24 = 0;
    pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
    local_58 = local_58 + 1;
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    if (2 < local_58) {
      return;
    }
  }
  _free(pvStack_34);
  return;
}


// ==== FUN_00686560 @ 0x00686560 ====

void FUN_00686560(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009db64c;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  return;
}


// ==== FUN_00686580 @ 0x00686580 ====

void FUN_00686580(void)

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
  FUN_00401740(s_UI_Game2_Siege_ui_GateStateWnd_t_009db5b4,0x22);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_00686410();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00686600 @ 0x00686600 ====

void FUN_00686600(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = param_2;
  local_4 = param_1;
  FUN_00686a20(&local_8);
  return;
}


// ==== FUN_00686630 @ 0x00686630 ====

void FUN_00686630(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 2) {
    *param_1 = *param_3;
    param_1[1] = param_3[1];
  }
  return;
}


// ==== FUN_00686660 @ 0x00686660 ====

int FUN_00686660(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c630;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 8) {
    FUN_005767c0(param_3,param_1);
    param_3 = param_3 + 8;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@006866c6 @ 0x006866c6 ====

void Catch_006866c6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006866d0 @ 0x006866d0 ====

void FUN_006866d0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c640;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_005767c0(param_1,param_3);
    param_1 = param_1 + 8;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00686736 @ 0x00686736 ====

void Catch_00686736(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00686740 @ 0x00686740 ====

void FUN_00686740(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00686660(param_1,param_2,param_3);
  return;
}


// ==== FUN_00686760 @ 0x00686760 ====

int FUN_00686760(int param_1,int param_2,undefined4 param_3)

{
  FUN_006866d0(param_1,param_2,param_3);
  return param_1 + param_2 * 8;
}


// ==== FUN_00686790 @ 0x00686790 ====

void FUN_00686790(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int extraout_ECX;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
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
  puStack_c = &LAB_0098c650;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x44);
  local_38 = *param_3;
  local_34 = param_3[1];
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = *(int *)(in_ECX + 0xc) - iVar2 >> 3;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar2 >> 3;
    }
    uVar5 = param_2;
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x44);
    if (0x1fffffffU - iVar6 < param_2) {
      ExceptionList = &local_10;
      uVar7 = FUN_0085b3b0();
      uVar5 = (uint)((ulonglong)uVar7 >> 0x20);
      local_20 = (uint)uVar7;
      iVar2 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar2 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar2 >> 3;
    }
    if (local_20 < iVar6 + uVar5) {
      if (0x1fffffff - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar2 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(in_ECX + 8) - iVar2 >> 3;
      }
      if (local_20 < iVar6 + uVar5) {
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 3;
        }
        local_20 = iVar2 + uVar5;
      }
      local_20 = local_20 * 8;
      pvVar3 = operator_new(local_20);
      local_8 = 0;
      local_24 = pvVar3;
      local_1c = FUN_00686740(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      local_1c = FUN_00686760(local_1c,param_2,&local_38);
      FUN_00686740(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(in_ECX + 8) - (int)_Memory >> 3;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)pvVar3;
        *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar2) * 8);
        *(void **)(in_ECX + 4) = pvVar3;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar2 = *(int *)(in_ECX + 8);
    if ((uint)(iVar2 - param_1 >> 3) < uVar5) {
      local_18 = uVar5 * 8;
      FUN_00686660(param_1,iVar2,local_18 + param_1);
      local_8 = 2;
      FUN_00686760(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 3),&local_38);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_18;
      FUN_00686630(param_1,*(int *)(in_ECX + 8) - local_18,&local_38);
      ExceptionList = local_10;
      return;
    }
    local_18 = uVar5 * 8;
    local_28 = iVar2 + uVar5 * -8;
    uVar4 = FUN_00686660(local_28,iVar2,iVar2);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_00576790(param_1,local_28,iVar2);
    FUN_00686630(param_1,local_18 + param_1,&local_38);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@006868f9 @ 0x006868f9 ====

void Catch_006868f9(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x20));
  return;
}


// ==== FUN_006869f0 @ 0x006869f0 ====

undefined4 FUN_006869f0(void)

{
  return 0x5f;
}


// ==== FUN_00686a00 @ 0x00686a00 ====

void FUN_00686a00(byte param_1)

{
  void *in_ECX;
  
  FUN_006863a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00686a20 @ 0x00686a20 ====

void FUN_00686a20(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 3) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 3))) {
    FUN_00686790(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_006866d0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 8;
  return;
}


// ==== FUN_00686a90 @ 0x00686a90 ====

void FUN_00686a90(int param_1,int param_2)

{
  int *in_ECX;
  
  in_ECX[3] = param_1;
  in_ECX[2] = param_2;
  (**(code **)(*in_ECX + 4))();
  return;
}


// ==== FUN_00686ac0 @ 0x00686ac0 ====

void FUN_00686ac0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009db74c;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  return;
}


// ==== FUN_00686ae0 @ 0x00686ae0 ====

void FUN_00686ae0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009db74c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00686b50 @ 0x00686b50 ====

undefined4 FUN_00686b50(void)

{
  (**(code **)(*DAT_00b5ac94 + 0x94))();
  (**(code **)(*DAT_00b5ac94 + 0x48))();
  return 1;
}


// ==== FUN_00686ba0 @ 0x00686ba0 ====

undefined4 FUN_00686ba0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_yes_009db728,7);
  if (iVar2 == 0) {
    (**(code **)(*DAT_00b5ac94 + 0x98))(*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 8));
    (**(code **)(*DAT_00b5ac94 + 0x48))();
    return 1;
  }
  cVar1 = FUN_004036a0(param_2,s_btn_no_009db730);
  if ((cVar1 == '\0') && (cVar1 = FUN_004036a0(param_2,s_btn_exit_009db738), cVar1 == '\0')) {
    return 0;
  }
  (**(code **)(*DAT_00b5ac94 + 0x94))();
  (**(code **)(*DAT_00b5ac94 + 0x48))();
  return 1;
}


// ==== FUN_00686c50 @ 0x00686c50 ====

void FUN_00686c50(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  void *pvStack_84;
  undefined1 uStack_80;
  uint uStack_70;
  undefined4 uStack_6c;
  void *apvStack_68 [5];
  uint uStack_54;
  undefined4 auStack_4c [19];
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5adb4 + 4))();
  puVar4 = auStack_4c;
  for (iVar3 = 0x13; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_00401740(&DAT_009db6dc,2);
  FUN_00404230(apvStack_68);
  uStack_6c = 0xf;
  uStack_70 = 0;
  uStack_80 = 0;
  FUN_00401740(s_lbl_addhp_value_009db6e0,0xf);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_84);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_0055a260(&uStack_6c);
  }
  if (0xf < uStack_70) {
    _free(pvStack_84);
    return;
  }
  if (uStack_54 < 0x10) {
    return;
  }
  _free(apvStack_68[0]);
  return;
}


// ==== FUN_00686d30 @ 0x00686d30 ====

/* WARNING: Removing unreachable block (ram,0x00686e65) */
/* WARNING: Removing unreachable block (ram,0x00686d93) */

void FUN_00686d30(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined4 *puVar6;
  undefined1 auStack_8a [18];
  undefined1 auStack_78 [4];
  void *apvStack_74 [5];
  uint uStack_60;
  undefined4 auStack_58 [22];
  
  uVar2 = (**(code **)(*DAT_00b5ac98 + 0x20))(*(undefined4 *)(in_ECX + 0xc));
  piVar3 = (int *)(**(code **)(*DAT_00b5abc8 + 8))(uVar2);
  if (piVar3 == (int *)0x0) {
    FUN_00401740(s_pFlyweight_009db6f0,10);
    FUN_00406880(auStack_8a + -10);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  iVar4 = (**(code **)(*piVar3 + 4))();
  apvStack_74[0] = *(void **)(iVar4 + 0x30);
  (**(code **)(*DAT_00b5ac98 + 0x1c))(*(undefined4 *)(in_ECX + 0xc));
  puVar5 = (undefined4 *)(**(code **)(*DAT_00b5adb4 + 4))();
  puVar6 = auStack_58;
  for (iVar4 = 0x13; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  FUN_00401740(&DAT_009db6fc,2);
  FUN_00404230(apvStack_74);
  FUN_00401740(s_lbl_totalhp_value_009db700,0x11);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_8a + -0xe);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x30))();
    FUN_0055a260(auStack_78);
  }
  if (uStack_60 < 0x10) {
    return;
  }
  _free(apvStack_74[0]);
  return;
}


// ==== FUN_00686e90 @ 0x00686e90 ====

void FUN_00686e90(void)

{
  int *piVar1;
  int in_ECX;
  void *local_38;
  undefined1 local_34;
  uint local_24;
  undefined4 local_20;
  void *local_1c [5];
  uint uStack_8;
  
  FUN_004041a0(local_1c,*(undefined4 *)(in_ECX + 8));
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_lbl_invdil_value_009db714,0x10);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
    FUN_0055a260(&local_20);
  }
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  if (uStack_8 < 0x10) {
    return;
  }
  _free(local_1c[0]);
  return;
}


// ==== FUN_00686f20 @ 0x00686f20 ====

void FUN_00686f20(void)

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
  FUN_00401740(s_UI_Game2_Siege_ui_GateInfoWnd_tx_009db6b8,0x21);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_00686e90();
    FUN_00686c50();
    FUN_00686d30();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00686fb0 @ 0x00686fb0 ====

undefined4 FUN_00686fb0(void)

{
  return 0x5e;
}


// ==== FUN_00686fc0 @ 0x00686fc0 ====

void FUN_00686fc0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009db74c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00687000 @ 0x00687000 ====

void FUN_00687000(undefined4 param_1,byte param_2)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = (uint)param_2;
  if ((0x1a < uVar1) || (uVar1 < 0x1e)) {
    in_ECX[2] = uVar1 - 0x1b;
    (**(code **)(*in_ECX + 4))();
  }
  return;
}


// ==== FUN_00687020 @ 0x00687020 ====

void FUN_00687020(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009db86c;
  in_ECX[2] = 0;
  return;
}


// ==== FUN_00687030 @ 0x00687030 ====

void FUN_00687030(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009db86c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00687070 @ 0x00687070 ====

undefined4 FUN_00687070(void)

{
  (**(code **)(*DAT_00b5ac94 + 0x94))();
  (**(code **)(*DAT_00b5ac94 + 0x3c))();
  return 1;
}


// ==== FUN_006870c0 @ 0x006870c0 ====

/* WARNING: Removing unreachable block (ram,0x006871b1) */

void FUN_006870c0(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  uint unaff_EBX;
  undefined1 auStack_36 [14];
  uint uStack_28;
  void *apvStack_24 [5];
  uint uStack_10;
  
  uVar2 = (**(code **)(*DAT_00b5ac98 + 0x20))(*(undefined4 *)(in_ECX + 8));
  piVar3 = (int *)(**(code **)(*DAT_00b5abc8 + 8))(uVar2);
  if (piVar3 == (int *)0x0) {
    uStack_28 = 0xf;
    FUN_00401740(s_pFlyweight_009db7e0,10);
    FUN_00406880(auStack_36 + -10);
    if (uStack_28 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free((void *)(unaff_EBX & 0xffffff00));
    return;
  }
  (**(code **)(*piVar3 + 4))();
  FUN_00401740(&DAT_009db7ec,2);
  FUN_00404230(apvStack_24);
  uStack_28 = 0xf;
  FUN_00401740(s_lbl_maxdef_value_009db7f0,0x10);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_36 + -10);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x30))();
    FUN_0055a260(&uStack_28);
  }
  if (uStack_10 < 0x10) {
    return;
  }
  _free(apvStack_24[0]);
  return;
}


// ==== FUN_006871e0 @ 0x006871e0 ====

/* WARNING: Removing unreachable block (ram,0x006872e3) */

void FUN_006871e0(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  uint unaff_EBX;
  undefined1 auStack_36 [10];
  undefined4 uStack_2c;
  void *apvStack_28 [5];
  uint uStack_14;
  
  uVar2 = (**(code **)(*DAT_00b5ac98 + 0x20))(*(undefined4 *)(in_ECX + 8));
  piVar3 = (int *)(**(code **)(*DAT_00b5abc8 + 8))(uVar2);
  if (piVar3 == (int *)0x0) {
    apvStack_28[0] = (void *)0xf;
    uStack_2c = 0;
    FUN_00401740(s_pFlyweight_009db804,10);
    FUN_00406880(auStack_36 + -10);
    if (apvStack_28[0] < (void *)0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free((void *)(unaff_EBX & 0xffffff00));
    return;
  }
  (**(code **)(*piVar3 + 4))();
  (**(code **)(*DAT_00b5ac98 + 0x1c))(*(undefined4 *)(in_ECX + 8));
  FUN_00401740(&DAT_009db810,2);
  FUN_00404230(apvStack_28);
  uStack_2c = 0xf;
  FUN_00401740(s_lbl_def_value_009db814,0xd);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_36 + -0xe);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x30))();
    FUN_0055a260(&uStack_2c);
  }
  if (uStack_14 < 0x10) {
    return;
  }
  _free(apvStack_28[0]);
  return;
}


// ==== FUN_00687310 @ 0x00687310 ====

void FUN_00687310(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  void *pvStack_38;
  undefined1 uStack_34;
  uint uStack_24;
  undefined4 uStack_20;
  void *apvStack_1c [5];
  uint uStack_8;
  
  uVar1 = (**(code **)(*DAT_00b5a78c + 0x40))();
  FUN_004041a0(apvStack_1c,uVar1);
  uStack_20 = 0xf;
  uStack_24 = 0;
  uStack_34 = 0;
  FUN_00401740(s_lbl_dil_value_009db824,0xd);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_38);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_0055a260(&uStack_20);
  }
  if (0xf < uStack_24) {
    _free(pvStack_38);
    return;
  }
  if (uStack_8 < 0x10) {
    return;
  }
  _free(apvStack_1c[0]);
  return;
}


// ==== FUN_006873b0 @ 0x006873b0 ====

int FUN_006873b0(undefined4 param_1,undefined4 param_2)

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
    FUN_00401740(&DAT_009db861,0);
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


// ==== FUN_00687420 @ 0x00687420 ====

void FUN_00687420(void)

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
  FUN_00401740(s_UI_Game2_Siege_ui_gateupgradewnd_009db7b8,0x24);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_006870c0();
    FUN_006871e0();
    FUN_00687310();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_006874b0 @ 0x006874b0 ====

undefined4 FUN_006874b0(void)

{
  undefined4 extraout_EAX;
  undefined4 uVar1;
  undefined4 extraout_EAX_00;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_edit_invdil_value_009db834,0x11);
  FUN_006873b0(local_1c,local_38);
  if (0xf < local_20) {
    _free(local_34);
    return extraout_EAX;
  }
  uVar1 = thunk_FUN_00796fb0(local_1c);
  if (uStack_4 < 0x10) {
    return uVar1;
  }
  _free(pvStack_18);
  return extraout_EAX_00;
}


// ==== FUN_00687530 @ 0x00687530 ====

void FUN_00687530(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 8);
  iVar2 = FUN_006874b0();
  (**(code **)(*DAT_00b5ac94 + 0x3c))();
  (**(code **)(*DAT_00b5ac94 + 0x24))(uVar1,iVar2 * 1000);
  return;
}


// ==== FUN_00687570 @ 0x00687570 ====

undefined4 FUN_00687570(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_yes_009db848,7);
  if (iVar2 == 0) {
    FUN_00687530();
    return 1;
  }
  cVar1 = FUN_004036a0(param_2,s_btn_no_009db850);
  if ((cVar1 == '\0') && (cVar1 = FUN_004036a0(param_2,s_btn_exit_009db858), cVar1 == '\0')) {
    return 0;
  }
  (**(code **)(*DAT_00b5ac94 + 0x94))();
  (**(code **)(*DAT_00b5ac94 + 0x3c))();
  return 1;
}


// ==== FUN_00687600 @ 0x00687600 ====

undefined4 FUN_00687600(void)

{
  return 0x5d;
}


// ==== FUN_00687610 @ 0x00687610 ====

void FUN_00687610(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009db86c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00687650 @ 0x00687650 ====

void FUN_00687650(void)

{
  return;
}


// ==== FUN_00687660 @ 0x00687660 ====

void FUN_00687660(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009db9b0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00687680 @ 0x00687680 ====

undefined4 FUN_00687680(void)

{
  (**(code **)(*DAT_00b5ac94 + 0x34))();
  return 1;
}


// ==== FUN_006876c0 @ 0x006876c0 ====

void FUN_006876c0(void)

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
  FUN_00401740(s_UI_Game2_Siege_ui_siegetimesetwn_009db8d8,0x25);
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


// ==== FUN_00687740 @ 0x00687740 ====

undefined4 FUN_00687740(int param_1,int param_2,int param_3)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 extraout_EAX;
  undefined4 uVar5;
  int in_ECX;
  void *local_38 [4];
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [32];
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar3 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_yes_009db900,7);
    if (iVar3 != 0) {
      cVar1 = FUN_004036a0(param_2,s_btn_no_009db914);
      if ((cVar1 == '\0') && (cVar1 = FUN_004036a0(param_2,s_btn_exit_009db91c), cVar1 == '\0')) {
        return 0;
      }
      (**(code **)(*DAT_00b5ac94 + 0x34))();
      return 1;
    }
    FUN_00401830(s_edit_time_009db908);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_38);
    if (0xf < uStack_24) {
      _free(local_38[0]);
      return extraout_EAX;
    }
    uStack_24 = 0xf;
    uStack_28 = 0;
    local_38[0] = (void *)((uint)local_38[0] & 0xffffff00);
    if ((piVar4 != (int *)0x0) && (iVar3 = (**(code **)(*piVar4 + 0x30))(), iVar3 != 0)) {
      uVar5 = FUN_00550150();
      FUN_00765c50(uVar5);
      cVar1 = FUN_00403f60(auStack_20);
      if (cVar1 == '\0') {
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      uVar2 = thunk_FUN_00796f50(auStack_20);
      (**(code **)(*DAT_00b5ac94 + 0x78))(uVar2);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  return 0;
}


// ==== FUN_00687880 @ 0x00687880 ====

void FUN_00687880(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009db9b0;
  FUN_006876c0();
  return;
}


// ==== FUN_006878a0 @ 0x006878a0 ====

void FUN_006878a0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  undefined4 unaff_ESI;
  void *unaff_EDI;
  undefined4 local_84;
  uint local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined1 local_74 [4];
  void *local_70;
  undefined4 uStack_6c;
  void *pvStack_68;
  uint local_5c;
  undefined4 local_58;
  uint local_54;
  void *pvStack_4c;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  undefined1 auStack_34 [4];
  void *pvStack_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint uStack_1c;
  undefined4 uStack_18;
  
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_40 = 0xf;
  local_44 = 0;
  local_54 = local_54 & 0xffffff00;
  local_24 = 0xf;
  local_28 = 0;
  local_38 = local_38 & 0xffffff00;
  FUN_00401740(s_<YEAR>_009db928);
  FUN_00401740(s_<color_F9B600>20_02d<_color>_009db930,0x1c);
  uVar1 = FUN_00404230(local_74);
  FUN_00401660(uVar1,0);
  if (0xf < local_5c) {
    _free(local_70);
    return;
  }
  FUN_004e6c20();
  FUN_00401740(s_<MONTH>_009db950);
  FUN_00401740(s_<color_F9B600>_2d<_color>_009db958,0x19);
  uVar1 = FUN_00404230(local_74);
  FUN_00401660(uVar1,0);
  if (0xf < local_5c) {
    _free(local_70);
    return;
  }
  FUN_004e6c20();
  FUN_00401740(s_<DAY>_009db974);
  FUN_00401740(s_<color_F9B600>_2d<_color>_009db97c,0x19);
  uVar1 = FUN_00404230(local_74);
  FUN_00401660(uVar1,0);
  if (0xf < local_5c) {
    _free(local_70);
    return;
  }
  FUN_004e6c20();
  (**(code **)(*DAT_00b5a794 + 8))(&local_20,0,0x1220008);
  uStack_6c = 0xf;
  local_70 = (void *)0x0;
  local_80 = local_80 & 0xffffff00;
  FUN_00401740(s_lbl_siegeDate_009db998,0xd);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_84);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_0055a260(auStack_34);
  }
  if (0xf < local_70) {
    _free(local_84);
    return;
  }
  if (0xf < uStack_1c) {
    _free(pvStack_30);
    return;
  }
  uStack_1c = 0xf;
  local_20 = 0;
  pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
  if (0xf < local_38) {
    _free(pvStack_4c);
    return;
  }
  local_38 = 0xf;
  local_3c = 0;
  pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
  if (0xf < local_54) {
    _free(pvStack_68);
    return;
  }
  local_54 = 0xf;
  local_58 = 0;
  pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
  if (unaff_EDI == (void *)0x0) {
    return;
  }
  FUN_004e65b0(unaff_EDI,unaff_ESI,local_74 + -0x24,uStack_18);
  _free(unaff_EDI);
  return;
}


// ==== FUN_00687b40 @ 0x00687b40 ====

undefined4 FUN_00687b40(void)

{
  return 0x5c;
}


// ==== FUN_00687b50 @ 0x00687b50 ====

void FUN_00687b50(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009db9b0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00687b90 @ 0x00687b90 ====

void FUN_00687b90(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 9) == '\0') {
    *(undefined1 *)(in_ECX + 9) = 1;
  }
  return;
}


// ==== FUN_00687ba0 @ 0x00687ba0 ====

undefined1 FUN_00687ba0(void)

{
  return 0;
}


// ==== FUN_00687bb0 @ 0x00687bb0 ====

undefined1 FUN_00687bb0(void)

{
  return 0;
}


// ==== FUN_00687be0 @ 0x00687be0 ====

void FUN_00687be0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) != '\0') {
    (**(code **)(*DAT_00b5a7a4 + 8))(*(undefined4 *)(in_ECX + 4));
    *(undefined1 *)(in_ECX + 8) = 0;
  }
  return;
}


// ==== FUN_00687c00 @ 0x00687c00 ====

void FUN_00687c00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dba90;
  if (*(char *)(in_ECX + 2) != '\0') {
    (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
    *(undefined1 *)(in_ECX + 2) = 0;
  }
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00687c30 @ 0x00687c30 ====

void FUN_00687c30(void)

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
    FUN_00401740(s_UI_Game2_Dungeon_ui_dungeontimew_009dba1c,0x26);
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


// ==== FUN_00687cc0 @ 0x00687cc0 ====

void FUN_00687cc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dba90;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[1] = 0;
  FUN_00687c30();
  return;
}


// ==== FUN_00687ce0 @ 0x00687ce0 ====

undefined4 FUN_00687ce0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 uVar3;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined4 extraout_EAX_05;
  undefined4 *puVar4;
  undefined4 extraout_EAX_06;
  undefined4 extraout_EAX_07;
  undefined4 extraout_EAX_08;
  undefined4 extraout_EAX_09;
  undefined4 extraout_EAX_10;
  undefined4 extraout_EAX_11;
  undefined4 extraout_EAX_12;
  int in_ECX;
  uint unaff_EBX;
  uint unaff_EBP;
  void **ppvVar5;
  int unaff_retaddr;
  uint *_Memory;
  uint *_Memory_00;
  uint uStack_dc;
  uint uStack_d8;
  void *pvStack_d4;
  void *pvStack_d0;
  undefined4 uStack_c4;
  uint uStack_c0;
  uint uStack_bc;
  void *pvStack_b0;
  void *pvStack_ac;
  undefined4 uStack_a8;
  uint uStack_a4;
  undefined1 auStack_a0 [4];
  uint uStack_9c;
  uint uStack_98;
  void *local_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined1 auStack_84 [4];
  uint uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  void *apvStack_74 [6];
  uint uStack_5c;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined1 auStack_38 [4];
  void *pvStack_34;
  undefined4 uStack_24;
  uint uStack_20;
  uint uStack_4;
  
  FUN_00401740(s_pan_time__d_009dba50,0xb);
  FUN_00404230(&local_94);
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (iVar1 != 0) {
    _Memory_00 = &uStack_98;
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(1);
    }
    FUN_00401740(s_textbox_time__d_009dba5c,0xf);
    FUN_00404230(&uStack_dc);
    _Memory = &uStack_dc;
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if (piVar2 != (int *)0x0) {
      uStack_a8 = (**(code **)(*piVar2 + 0x30))();
      uStack_a4 = uStack_4 / 0x3c;
      iVar1 = (**(code **)(*DAT_00b5ac1c + 0x38))();
      uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(7,iVar1 << 0x10 | unaff_retaddr + 0x1eU);
      FUN_00401660(uVar3,0,0xffffffff);
      uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x7d40063);
      uStack_bc = 0xf;
      uStack_c0 = 0;
      pvStack_d0 = (void *)((uint)pvStack_d0 & 0xffffff00);
      FUN_00401660(uVar3,0,0xffffffff);
      iVar1 = FUN_00403620(0,unaff_EBP,s_NOTEXT_009dba6c,6);
      if (iVar1 == 0) {
        piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_b0);
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 0x24))(0);
        }
        if (0xf < uStack_c0) {
          _free(pvStack_d4);
          return extraout_EAX_01;
        }
        uStack_c0 = 0xf;
        uStack_c4 = 0;
        pvStack_d4 = (void *)((uint)pvStack_d4 & 0xffffff00);
        if (0xf < unaff_EBP) {
          _free(_Memory);
          return extraout_EAX_02;
        }
        if (0xf < uStack_dc) {
          _free((void *)0x0);
          return extraout_EAX_03;
        }
        uStack_dc = 0xf;
        if (uStack_9c < 0x10) {
          return 0;
        }
        _free(pvStack_b0);
        return extraout_EAX_04;
      }
      FUN_00401660(&pvStack_d4,0,0xffffffff);
      FUN_00404230(auStack_38);
      uStack_80 = 0;
      uStack_7c = 0;
      uStack_78 = 0;
      FUN_00401830(s_<MAP_COUNT_6>_009dba74);
      FUN_00406720(apvStack_74);
      if (0xf < uStack_5c) {
        _free(apvStack_74[1]);
        return extraout_EAX_05;
      }
      piVar2 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
      piVar2 = (int *)(**(code **)(*piVar2 + 0x24))();
      puVar4 = (undefined4 *)(**(code **)(*piVar2 + 0x10))();
      ppvVar5 = apvStack_74;
      for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppvVar5 = (void *)*puVar4;
        puVar4 = puVar4 + 1;
        ppvVar5 = ppvVar5 + 1;
      }
      uStack_90 = 0;
      uStack_8c = 0;
      uStack_88 = 0;
      FUN_00401830(&DAT_009dba84);
      uVar3 = FUN_00404230(apvStack_74);
      FUN_00406720(uVar3);
      if (0xf < uStack_5c) {
        _free(apvStack_74[1]);
        return extraout_EAX_06;
      }
      FUN_00404a40(auStack_54,auStack_38,auStack_84,&local_94);
      FUN_005569f0(auStack_54,1);
      if (0xf < uStack_3c) {
        _free(pvStack_50);
        return extraout_EAX_07;
      }
      uStack_3c = 0xf;
      uStack_40 = 0;
      pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
      FUN_00406250();
      FUN_00406250();
      if (0xf < uStack_20) {
        _free(pvStack_34);
        return extraout_EAX_08;
      }
      uStack_20 = 0xf;
      uStack_24 = 0;
      pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
      if (0xf < uStack_bc) {
        _free(pvStack_d0);
        return extraout_EAX_09;
      }
      uStack_bc = 0xf;
      uStack_c0 = 0;
      pvStack_d0 = (void *)((uint)pvStack_d0 & 0xffffff00);
      if (0xf < unaff_EBX) {
        _free(_Memory_00);
        return extraout_EAX_10;
      }
      if (0xf < uStack_d8) {
        _free((void *)0xf);
        return extraout_EAX_11;
      }
      uStack_d8 = 0xf;
      uStack_dc = 0;
      if (uStack_98 < 0x10) {
        return 1;
      }
      _free(pvStack_ac);
      return extraout_EAX_12;
    }
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_a0);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))();
    }
    if (0xf < uStack_c0) {
      _free(pvStack_d4);
      return extraout_EAX;
    }
    uStack_c0 = 0xf;
    uStack_c4 = 0;
    pvStack_d4 = (void *)((uint)pvStack_d4 & 0xffffff00);
  }
  if (uStack_80 < 0x10) {
    return 0;
  }
  _free(local_94);
  return extraout_EAX_00;
}


// ==== FUN_006881c0 @ 0x006881c0 ====

void FUN_006881c0(int param_1)

{
  char cVar1;
  int *piVar2;
  uint *puVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int iStack_e4;
  int iStack_e0;
  undefined1 auStack_d8 [4];
  void *pvStack_d4;
  undefined4 uStack_c4;
  uint uStack_c0;
  undefined1 auStack_bc [4];
  void *pvStack_b8;
  undefined4 uStack_a8;
  uint uStack_a4;
  uint auStack_a0 [40];
  
  if (DAT_00b5ac1c != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
    piVar2 = (int *)(**(code **)(*piVar2 + 0x20))();
    puVar3 = (uint *)(**(code **)(*piVar2 + 0x10))();
    puVar7 = auStack_a0;
    for (iVar5 = 0x28; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar7 = puVar7 + 1;
    }
    iStack_e0 = 1;
    iVar5 = 3;
    do {
      uStack_c0 = 0xf;
      uStack_c4 = 0;
      pvStack_d4 = (void *)((uint)pvStack_d4 & 0xffffff00);
      FUN_00401740(s_pan_time__d_009dba44,0xb);
      uVar4 = FUN_00404230(auStack_bc);
      FUN_00401660(uVar4,0,0xffffffff);
      if (0xf < uStack_a4) {
        _free(pvStack_b8);
        return;
      }
      uStack_a4 = 0xf;
      uStack_a8 = 0;
      pvStack_b8 = (void *)((uint)pvStack_b8 & 0xffffff00);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_d8);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x24))(0);
      }
      if (0xf < uStack_c0) {
        _free(pvStack_d4);
        return;
      }
      iVar5 = iVar5 + -1;
      uStack_c0 = 0xf;
      uStack_c4 = 0;
      pvStack_d4 = (void *)((uint)pvStack_d4 & 0xffffff00);
    } while (iVar5 != 0);
    iVar5 = 0;
    puVar3 = auStack_a0 + 1;
    iStack_e4 = 8;
    do {
      if (((*(char *)((int)puVar3 + 0xd) != '\0') && ((ushort)iStack_e0 < 4)) &&
         (uVar6 = (*puVar3 - *(int *)(param_1 + 0xc)) + puVar3[-1], uVar6 <= *puVar3)) {
        cVar1 = FUN_00687ce0(iStack_e0,uVar6 / 1000,iVar5);
        if (cVar1 != '\0') {
          iStack_e0 = iStack_e0 + 1;
        }
      }
      iVar5 = iVar5 + 1;
      puVar3 = puVar3 + 5;
      iStack_e4 = iStack_e4 + -1;
    } while (iStack_e4 != 0);
  }
  return;
}


// ==== FUN_00688330 @ 0x00688330 ====

uint FUN_00688330(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_006881c0(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00688360 @ 0x00688360 ====

undefined4 FUN_00688360(void)

{
  return 0x71;
}


// ==== FUN_00688370 @ 0x00688370 ====

void FUN_00688370(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dba90;
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


// ==== FUN_006883b0 @ 0x006883b0 ====

void FUN_006883b0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 9) == '\0') {
    *(undefined1 *)(in_ECX + 9) = 1;
  }
  return;
}


// ==== FUN_006883c0 @ 0x006883c0 ====

undefined1 FUN_006883c0(void)

{
  return 0;
}


// ==== FUN_006883d0 @ 0x006883d0 ====

void FUN_006883d0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) != '\0') {
    (**(code **)(*DAT_00b5a7a4 + 8))(*(undefined4 *)(in_ECX + 4));
    *(undefined1 *)(in_ECX + 8) = 0;
  }
  return;
}


// ==== FUN_006883f0 @ 0x006883f0 ====

void FUN_006883f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dbb44;
  if (*(char *)(in_ECX + 2) != '\0') {
    (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
    *(undefined1 *)(in_ECX + 2) = 0;
  }
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00688420 @ 0x00688420 ====

void FUN_00688420(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_btn_alarm_009dbb30,9);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (local_8 < 0x10) {
    local_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    uVar2 = (**(code **)(*piVar1 + 0x30))
                      (0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                       &Framework::UI::Control::Button::RTTI_Type_Descriptor,0);
    FUN_00803725(uVar2);
    FUN_00558130(*(undefined1 *)(in_ECX + 10));
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_006884b0 @ 0x006884b0 ====

void FUN_006884b0(void)

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
    FUN_00401740(s_UI_Game2_Dungeon_ui_dungeonalarm_009dbafc,0x27);
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


// ==== FUN_00688540 @ 0x00688540 ====

undefined4 FUN_00688540(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70450002) {
    *(undefined1 *)(in_ECX + 10) = 1;
    FUN_00688420(1);
    return 1;
  }
  return 0;
}


// ==== FUN_00688570 @ 0x00688570 ====

undefined4 FUN_00688570(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_alarm_009dbb24,9);
    if (iVar2 == 0) {
      cVar1 = (**(code **)(*DAT_00b5ae64 + 0x20))();
      if (cVar1 == '\0') {
        (**(code **)(*DAT_00b5ae64 + 0x10))();
        *(undefined1 *)(in_ECX + 10) = 0;
        FUN_00688420(0);
        return 1;
      }
      (**(code **)(*DAT_00b5ae64 + 0x14))();
      *(undefined1 *)(in_ECX + 10) = 0;
      FUN_00688420(0);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006885f0 @ 0x006885f0 ====

void FUN_006885f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dbb44;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined1 *)((int)in_ECX + 10) = 0;
  in_ECX[1] = 0;
  FUN_006884b0();
  return;
}


// ==== FUN_00688610 @ 0x00688610 ====

undefined4 FUN_00688610(void)

{
  return 0x70;
}


// ==== FUN_00688620 @ 0x00688620 ====

void FUN_00688620(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dbb44;
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


// ==== FUN_00688670 @ 0x00688670 ====

void FUN_00688670(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0068867c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_00688680 @ 0x00688680 ====

undefined1 FUN_00688680(void)

{
  return 0;
}


// ==== FUN_006886c0 @ 0x006886c0 ====

void FUN_006886c0(void *param_1)

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


// ==== FUN_00688720 @ 0x00688720 ====

void FUN_00688720(undefined4 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  void *local_38;
  undefined1 local_34;
  uint local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_pan_object_check__d_009dbc9c,0x13);
  uVar1 = FUN_00404230(local_1c);
  FUN_00401660(uVar1,0,0xffffffff);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x24))(param_1);
  }
  if (local_24 < 0x10) {
    return;
  }
  _free(local_38);
  return;
}


// ==== FUN_006887c0 @ 0x006887c0 ====

void FUN_006887c0(undefined4 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  void *local_38;
  undefined1 local_34;
  uint local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_pan_object_fail__d_009dbcb0,0x12);
  uVar1 = FUN_00404230(local_1c);
  FUN_00401660(uVar1,0,0xffffffff);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x24))(param_1);
  }
  if (local_24 < 0x10) {
    return;
  }
  _free(local_38);
  return;
}


// ==== FUN_00688860 @ 0x00688860 ====

void FUN_00688860(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    FUN_00688720(iVar4,0);
    FUN_006887c0(iVar4,0);
    if (*(int *)(in_ECX + 0x24) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24) >> 1;
    }
    uVar3 = *(int *)(in_ECX + 0xc) + iVar4;
    if (uVar3 < uVar2) {
      iVar1 = *(int *)(in_ECX + 0x24);
      if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x28) - iVar1 >> 1) <= uVar3)) {
LAB_006888f3:
                    /* WARNING: Subroutine does not return */
        FUN_00426d40();
      }
      if (*(short *)(iVar1 + uVar3 * 2) == 2) {
        FUN_00688720(iVar4,1);
      }
      else {
        iVar1 = *(int *)(in_ECX + 0x24);
        if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x28) - iVar1 >> 1) <= uVar3))
        goto LAB_006888f3;
        if (*(short *)(iVar1 + uVar3 * 2) == 1) {
          FUN_006887c0(iVar4,1);
        }
      }
    }
    iVar4 = iVar4 + 1;
    if (5 < iVar4) {
      return;
    }
  } while( true );
}


// ==== FUN_00688900 @ 0x00688900 ====

void FUN_00688900(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_list_objectlist_009dbcc4,0xf);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (local_8 < 0x10) {
    local_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    (**(code **)(*piVar1 + 0x30))();
    uVar2 = FUN_005754e0();
    *(undefined4 *)(in_ECX + 0xc) = uVar2;
    FUN_00688860();
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_00688980 @ 0x00688980 ====

undefined4 FUN_00688980(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_close_009dbc10,9);
      if (iVar2 == 0) {
        (**(code **)(*DAT_00b5ae64 + 0x14))();
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_dungeoninfo_ok_009dbc1c);
      if (cVar1 != '\0') {
        (**(code **)(*DAT_00b5ae64 + 0x14))();
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_list_objectlist_scroll_upbtn_009dbc30);
      if ((cVar1 == '\0') &&
         (cVar1 = FUN_004036a0(param_2,s_list_objectlist_scroll_downbtn_009dbc50), cVar1 == '\0')) {
        return 0;
      }
LAB_00688a11:
      FUN_00688900();
      return 1;
    }
  }
  else if (((param_1 == 0) && (param_3 == 7)) &&
          (iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),
                                s_list_objectlist_scroll_bar_009dbc70,0x1a), iVar2 == 0))
  goto LAB_00688a11;
  return 0;
}


// ==== FUN_00688a50 @ 0x00688a50 ====

void FUN_00688a50(void)

{
  undefined4 *in_ECX;
  undefined4 unaff_EBX;
  
  *in_ECX = &PTR_FUN_009dbcdc;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if ((void *)in_ECX[9] != (void *)0x0) {
    _free((void *)in_ECX[9]);
    return;
  }
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  if (in_ECX[5] == 0) {
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  FUN_00405de0(in_ECX[5],in_ECX[6],in_ECX + 4,unaff_EBX);
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_00688ac0 @ 0x00688ac0 ====

void FUN_00688ac0(void)

{
  int iVar1;
  ushort *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined2 *puVar6;
  int iVar7;
  int in_ECX;
  int *unaff_EBP;
  undefined1 auStack_42 [10];
  void *pvStack_38;
  undefined1 uStack_34;
  undefined4 uStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar3 = (int *)(**(code **)(*piVar3 + 0x28))();
  piVar3 = (int *)(**(code **)(*piVar3 + 0x18))();
  uStack_20 = 0xf;
  uStack_24 = 0;
  uStack_34 = 0;
  FUN_00401740(s_list_objectlist_009dbc8c,0xf);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_38);
  if (0xf < uStack_24) {
    _free(pvStack_38);
    return;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  uVar5 = (**(code **)(*piVar4 + 0x30))();
  if (*(int *)(in_ECX + 0x14) != 0) {
    FUN_00405de0(*(int *)(in_ECX + 0x14),*(undefined4 *)(in_ECX + 0x18),in_ECX + 0x10,uVar5);
    _free(*(void **)(in_ECX + 0x14));
    return;
  }
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  if (*(void **)(in_ECX + 0x24) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x24));
    return;
  }
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  while (piVar3 != (int *)0x0) {
    puVar6 = (undefined2 *)(**(code **)(*piVar3 + 4))();
    uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(7,CONCAT22(*(undefined2 *)(in_ECX + 10),*puVar6));
    FUN_00401660(uVar5,0,0xffffffff);
    FUN_00406720(&uStack_28);
    iVar7 = (**(code **)(*piVar3 + 4))();
    iVar1 = *(int *)(in_ECX + 0x24);
    if ((iVar1 == 0) ||
       ((uint)(*(int *)(in_ECX + 0x2c) - iVar1 >> 1) <= (uint)(*(int *)(in_ECX + 0x28) - iVar1 >> 1)
       )) {
      FUN_00427290(*(undefined4 *)(in_ECX + 0x28),1,auStack_42 + -0xe);
    }
    else {
      puVar2 = *(ushort **)(in_ECX + 0x28);
      *puVar2 = (ushort)*(byte *)(iVar7 + 2);
      *(ushort **)(in_ECX + 0x28) = puVar2 + 1;
    }
    piVar3 = (int *)(**(code **)(*unaff_EBP + 0x1c))();
  }
  FUN_00576750(in_ECX + 0x10);
  FUN_00575530();
  uVar5 = FUN_005754e0();
  *(undefined4 *)(in_ECX + 0xc) = uVar5;
  FUN_00688860();
  if (uStack_8 < 0x10) {
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_00688ca0 @ 0x00688ca0 ====

/* WARNING: Removing unreachable block (ram,0x00688d23) */
/* WARNING: Removing unreachable block (ram,0x00688ce2) */

void FUN_00688ca0(void)

{
  ushort uVar1;
  code *pcVar2;
  void *pvVar3;
  int *piVar4;
  ushort *puVar5;
  undefined4 uVar6;
  int in_ECX;
  uint unaff_ESI;
  char *pcVar7;
  uint uVar8;
  char *pcVar9;
  uint uVar10;
  undefined4 in_stack_ffffff64;
  uint *puVar11;
  uint in_stack_ffffff68;
  undefined4 in_stack_ffffff6c;
  undefined4 *puVar12;
  undefined4 uVar13;
  int iVar14;
  uint uVar15;
  undefined4 uVar16;
  uint uVar17;
  undefined4 in_stack_ffffff80;
  uint in_stack_ffffff84;
  undefined4 uVar18;
  undefined4 in_stack_ffffff88;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  uint uStack_60;
  void *pvStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  
  uStack_54 = s_UI_Game2_Dungeon_ui_dungeoninfow_009dbbb0;
  uStack_58 = 0x688ccc;
  FUN_00401740();
  uStack_54 = (char *)0x688cd6;
  pvVar3 = (void *)FUN_00410500();
  if (pvVar3 == (void *)0x0) {
    uStack_54 = s_FALSE_009dbbd8;
    uStack_58 = 0x688d0f;
    FUN_00401740();
    uStack_54 = (char *)0x688d19;
    FUN_00406880();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  uStack_54 = (char *)((int)pvVar3 + 0x3c);
  uStack_58 = 0x688d49;
  piVar4 = (int *)(**(code **)(*DAT_00b5a798 + 4))();
  *(int **)(in_ECX + 4) = piVar4;
  pvStack_5c = (void *)0x688d54;
  (**(code **)(*piVar4 + 0x40))();
  uStack_60 = 0x688d60;
  pvStack_5c = pvVar3;
  (**(code **)(*DAT_00b5a7cc + 0x14))();
  uStack_60 = 0x688d6b;
  piVar4 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  uStack_60 = 0x688d72;
  puVar5 = (ushort *)(**(code **)(*piVar4 + 0x1c))();
  uVar1 = *puVar5;
  *(ushort *)(in_ECX + 10) = uVar1;
  uStack_60 = (uint)uVar1 << 0x10 | 1;
  uVar24 = 7;
  uVar6 = (**(code **)(*DAT_00b5a794 + 0xc))(7);
  uVar20 = 0x688da8;
  FUN_00401660(uVar6,0,0xffffffff);
  iVar14 = (int)register0x00000010 + -0x50;
  uVar23 = 0xf;
  uVar22 = 0;
  in_stack_ffffff84 = in_stack_ffffff84 & 0xffffff00;
  uVar13 = 0x688dc3;
  FUN_00401660(iVar14,0,0xffffffff);
  uVar17 = 0xf;
  uVar16 = 0;
  pcVar9 = s_lbl_dungeon_name2_009dbbe0;
  in_stack_ffffff68 = in_stack_ffffff68 & 0xffffff00;
  FUN_00401740(s_lbl_dungeon_name2_009dbbe0,0x11);
  uVar10 = 0x688de4;
  FUN_006886c0(in_stack_ffffff64,in_stack_ffffff68,in_stack_ffffff6c,uVar13,iVar14,uVar16,uVar17,
               in_stack_ffffff80,in_stack_ffffff84,in_stack_ffffff88,uVar20,uVar6,uVar22,uVar23);
  uVar6 = (**(code **)(*DAT_00b5a794 + 0xc))(7,(uint)*(ushort *)(in_ECX + 10) << 0x10 | 2);
  uVar20 = 0x688e08;
  FUN_00401660(uVar6,0,0xffffffff);
  puVar12 = &uStack_58;
  uVar21 = 0xf;
  uVar22 = 0;
  uVar17 = uVar17 & 0xffffff00;
  uVar13 = 0x688e23;
  FUN_00401660(puVar12,0,0xffffffff);
  uVar15 = 0xf;
  uVar23 = 0;
  pcVar7 = s_lbl_misson2_009dbbf4;
  uVar10 = uVar10 & 0xffffff00;
  FUN_00401740(s_lbl_misson2_009dbbf4,0xb);
  uVar8 = 0x688e44;
  FUN_006886c0(pcVar9,uVar10,in_stack_ffffff64,uVar13,puVar12,uVar23,uVar15,uVar16,uVar17,
               in_stack_ffffff80,uVar20,uVar6,uVar22,uVar21);
  uVar6 = (**(code **)(*DAT_00b5a794 + 0xc))(7,(uint)*(ushort *)(in_ECX + 10) << 0x10 | 3);
  uVar21 = 0x688e68;
  FUN_00401660(uVar6,0,0xffffffff);
  puVar11 = &uStack_60;
  uVar19 = 0xf;
  uVar18 = 0;
  uVar15 = uVar15 & 0xffffff00;
  uVar13 = 0x688e83;
  FUN_00401660(puVar11,0,0xffffffff);
  uVar22 = 0xf;
  uVar20 = 0;
  uVar8 = uVar8 & 0xffffff00;
  FUN_00401740(s_lbl_limit_time2_009dbc00,0xf);
  FUN_006886c0(pcVar7,uVar8,pcVar9,uVar13,puVar11,uVar20,uVar22,uVar23,uVar15,uVar16,uVar21,uVar6,
               uVar18,uVar19);
  if (*(int *)(in_ECX + 0x14) != 0) {
    FUN_00405de0(*(int *)(in_ECX + 0x14),*(undefined4 *)(in_ECX + 0x18),in_ECX + 0x10,uVar24);
    _free(*(void **)(in_ECX + 0x14));
    return;
  }
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  if (*(void **)(in_ECX + 0x24) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x24));
    return;
  }
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  FUN_00688ac0();
  if (unaff_ESI < 0x10) {
    return;
  }
  _free(pvStack_5c);
  return;
}


// ==== FUN_00688f10 @ 0x00688f10 ====

undefined4 FUN_00688f10(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70450007) {
    FUN_00688ac0();
    return 1;
  }
  return 0;
}


// ==== FUN_00688f40 @ 0x00688f40 ====

void FUN_00688f40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dbcdc;
  *(undefined2 *)((int)in_ECX + 10) = 0;
  in_ECX[3] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  FUN_00688ca0();
  return;
}


// ==== FUN_00688f70 @ 0x00688f70 ====

undefined4 FUN_00688f70(void)

{
  return 0x6f;
}


// ==== FUN_00688f80 @ 0x00688f80 ====

void FUN_00688f80(byte param_1)

{
  void *in_ECX;
  
  FUN_00688a50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00688fa0 @ 0x00688fa0 ====

void FUN_00688fa0(void)

{
  return;
}


// ==== FUN_00688fb0 @ 0x00688fb0 ====

undefined1 FUN_00688fb0(void)

{
  return 0;
}


// ==== FUN_00688fc0 @ 0x00688fc0 ====

undefined4 FUN_00688fc0(void)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5ac38 + 0x50))();
  if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5ac38 + 0x48))();
    return 1;
  }
  return 0;
}


// ==== FUN_00688fe0 @ 0x00688fe0 ====

void FUN_00688fe0(void)

{
  int *piVar1;
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
  FUN_00401740(s_maillist_009dbdbc,8);
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
    FUN_00570fc0(unaff_retaddr);
    FUN_00570a10(in_ECX + 0x18);
  }
  return;
}


// ==== FUN_00689070 @ 0x00689070 ====

undefined4 FUN_00689070(int param_1,int param_2,int param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int in_ECX;
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009dbd70,8);
      if (iVar2 == 0) {
        (**(code **)(*DAT_00b5ac38 + 0x48))();
        return 1;
      }
    }
  }
  else if ((param_1 == 0x18) && (param_3 == 1)) {
    cVar1 = FUN_004036e0(param_2,s_maillist_009dbd7c);
    if (cVar1 == '\0') {
      if (*(int *)(in_ECX + 0xc) == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc) >> 2;
      }
      if (param_4 <= uVar3) {
        puVar4 = (undefined4 *)FUN_00689e70(param_4);
        if ((char)((uint)*puVar4 >> 0x10) == '\x01') {
          (**(code **)(*DAT_00b5ac38 + 0x58))(*puVar4);
        }
      }
    }
    return 1;
  }
  return 0;
}


// ==== FUN_00689120 @ 0x00689120 ====

void FUN_00689120(undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  undefined2 *puVar5;
  undefined4 *puVar6;
  undefined1 uStack00000000;
  undefined4 uStack_28;
  undefined2 auStack_24 [18];
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ab60 + 8))(param_1);
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined4 *)(**(code **)(*piVar1 + 4))();
    puVar6 = &uStack_28;
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar6 = puVar6 + 1;
    }
    *(undefined2 *)puVar6 = *(undefined2 *)puVar2;
    if (uStack_28._2_1_ != 0) {
      uVar3 = (uint)uStack_28._2_1_;
      puVar5 = auStack_24;
      do {
        iVar4 = *(int *)(in_ECX + 0xc);
        _uStack00000000 = CONCAT12(1,*puVar5);
        if ((iVar4 == 0) ||
           ((uint)(*(int *)(in_ECX + 0x14) - iVar4 >> 2) <=
            (uint)(*(int *)(in_ECX + 0x10) - iVar4 >> 2))) {
          FUN_00689ea0(*(undefined4 *)(in_ECX + 0x10),1,&uStack00000000);
        }
        else {
          iVar4 = *(int *)(in_ECX + 0x10);
          FUN_00689b70(iVar4,1,&uStack00000000,in_ECX + 8,_uStack00000000);
          *(int *)(in_ECX + 0x10) = iVar4 + 4;
        }
        puVar5 = puVar5 + 1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
  }
  return;
}


// ==== FUN_00689200 @ 0x00689200 ====

void FUN_00689200(void)

{
  undefined4 *in_ECX;
  undefined4 unaff_EBX;
  
  *in_ECX = &PTR_FUN_009dbdd0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if (in_ECX[7] != 0) {
    FUN_00405de0(in_ECX[7],in_ECX[8],in_ECX + 6,unaff_EBX);
    _free((void *)in_ECX[7]);
    return;
  }
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  if ((void *)in_ECX[3] == (void *)0x0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00689270 @ 0x00689270 ====

void FUN_00689270(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  undefined4 uStack_198;
  uint uStack_184;
  byte bStack_60;
  char acStack_58 [2];
  undefined2 auStack_56 [43];
  
  uVar5 = 0;
  if (*(void **)(in_ECX + 0xc) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0xc));
    return;
  }
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  iVar4 = *DAT_00b5acd8;
  uVar2 = (**(code **)(*DAT_00b5ac38 + 0x54))();
  piVar3 = (int *)(**(code **)(iVar4 + 0xc))(uVar2);
  if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0xc))(), iVar4 == 4)) {
    piVar3 = (int *)(**(code **)(*piVar3 + 0x14))();
    piVar3 = (int *)(**(code **)(*piVar3 + 0x24))();
    if (piVar3 == (int *)0x0) {
      FUN_00401830(s_pCreature__NULL_009dbd98);
      FUN_00406880((int)register0x00000010 + -0x19c);
      if (uStack_184 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(uStack_198);
      return;
    }
    piVar3 = (int *)(**(code **)(*piVar3 + 0x20))();
    if (piVar3 == (int *)0x0) {
      FUN_00401830(s_pFlyweight____NULL_009dbda8);
      FUN_00406880((int)register0x00000010 + -0x19c);
      if (uStack_184 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(uStack_198);
      return;
    }
    uVar2 = (**(code **)(*piVar3 + 4))();
    FUN_00689a70(uVar2);
    if (bStack_60 != 0) {
      do {
        if (acStack_58[uVar5 * 4] == '\x12') {
          FUN_00689120(auStack_56[uVar5 * 2]);
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < bStack_60);
    }
  }
  return;
}


// ==== FUN_006893a0 @ 0x006893a0 ====

void FUN_006893a0(void)

{
  char cVar1;
  undefined4 *puVar2;
  void *pvVar3;
  void *pvVar4;
  int *piVar5;
  uint *puVar6;
  undefined4 uVar7;
  char *pcVar8;
  ushort *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int in_ECX;
  int iVar12;
  uint *puVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  undefined1 local_24c [4];
  void *local_248;
  void *local_244;
  undefined4 local_240;
  undefined4 local_23c;
  void *pvStack_234;
  undefined4 uStack_224;
  uint uStack_220;
  undefined1 auStack_21c [4];
  void *pvStack_218;
  undefined4 uStack_208;
  undefined4 uStack_204;
  undefined1 auStack_200 [4];
  void *pvStack_1fc;
  undefined4 uStack_1ec;
  uint uStack_1e8;
  undefined1 auStack_1e4 [4];
  void *pvStack_1e0;
  undefined4 uStack_1d0;
  uint uStack_1cc;
  int iStack_1c8;
  undefined1 uStack_1c4;
  undefined1 auStack_1c0 [4];
  undefined1 uStack_1bc;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  undefined1 uStack_1a0;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined1 uStack_184;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined1 uStack_168;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined1 auStack_144 [4];
  void *pvStack_140;
  undefined4 uStack_130;
  uint uStack_12c;
  undefined1 auStack_128 [4];
  void *pvStack_124;
  undefined4 uStack_114;
  void *pvStack_110;
  undefined4 uStack_100;
  uint uStack_fc;
  undefined1 auStack_f8 [4];
  void *pvStack_f4;
  undefined4 uStack_e4;
  uint uStack_e0;
  undefined1 auStack_d4 [4];
  void *pvStack_d0;
  undefined4 uStack_c0;
  uint uStack_bc;
  char acStack_b8 [40];
  undefined4 uStack_90;
  char acStack_8c [136];
  
  FUN_00689270();
  puVar11 = *(undefined4 **)(in_ECX + 0xc);
  puVar2 = *(undefined4 **)(in_ECX + 0x10);
  local_248 = (void *)0x0;
  local_244 = (void *)0x0;
  local_240 = 0;
  do {
    if (puVar11 == puVar2) {
      FUN_00688fe0(local_24c);
      pvVar4 = local_244;
      pvVar3 = local_248;
      if (local_248 == (void *)0x0) {
        return;
      }
      for (; pvVar3 != pvVar4; pvVar3 = (void *)((int)pvVar3 + 0x78)) {
        FUN_00689be0();
      }
      _free(local_248);
      return;
    }
    local_23c = *puVar11;
    piVar5 = (int *)(**(code **)(*DAT_00b5ab64 + 8))(local_23c);
    puVar6 = (uint *)(**(code **)(*piVar5 + 4))();
    puVar13 = &uStack_bc;
    for (iVar12 = 0x2b; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar13 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar13 = puVar13 + 1;
    }
    iVar12 = (**(code **)(*DAT_00b5ac1c + 0x14))();
    piVar5 = (int *)(**(code **)(**(int **)(iVar12 + 0x60) + 0x14))();
    piVar5 = (int *)(**(code **)(*piVar5 + 0xc))(local_240);
    iStack_1c8 = 0;
    uStack_1c4 = 0;
    uStack_1a8 = 0xf;
    uStack_1ac = 0;
    uStack_1bc = 0;
    uStack_18c = 0xf;
    uStack_190 = 0;
    uStack_1a0 = 0;
    uStack_170 = 0xf;
    uStack_174 = 0;
    uStack_184 = 0;
    uStack_154 = 0xf;
    uStack_158 = 0;
    uStack_168 = 0;
    if (piVar5 == (int *)0x0) {
      piVar5 = *(int **)(iVar12 + 0x48);
      uVar14 = 0;
      FUN_00401740(&DAT_009dbd88,2);
      uVar7 = FUN_00404230(&uStack_114);
      FUN_00401660(uVar7,0,0xffffffff);
      if (0xf < uStack_fc) {
        _free(pvStack_110);
        return;
      }
      pcVar8 = acStack_b8;
      uStack_fc = 0xf;
      uStack_100 = 0;
      pvStack_110 = (void *)((uint)pvStack_110 & 0xffffff00);
      uStack_1e8 = 0xf;
      uStack_1ec = 0;
      pvStack_1fc = (void *)((uint)pvStack_1fc & 0xffffff00);
      do {
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_00401740(acStack_b8,(int)pcVar8 - (int)(acStack_b8 + 1));
      FUN_00401660(auStack_200,0,0xffffffff);
      if (0xf < uStack_1e8) {
        _free(pvStack_1fc);
        return;
      }
      uStack_1e8 = 0xf;
      uStack_1ec = 0;
      pvStack_1fc = (void *)((uint)pvStack_1fc & 0xffffff00);
      FUN_00401740(&DAT_009dbd8c,1);
      piVar5 = (int *)(**(code **)(*piVar5 + 0x28))();
      puVar9 = (ushort *)(**(code **)(*piVar5 + 8))();
      if (uStack_c0._2_2_ <= *puVar9) {
        iStack_1c8 = 0xd;
        goto LAB_00689736;
      }
      iStack_1c8 = 0xb;
      uStack_1c4 = 1;
    }
    else {
      piVar5 = (int *)(**(code **)(*piVar5 + 0xc))();
      puVar10 = (undefined4 *)(**(code **)(*piVar5 + 4))();
      uStack_208 = *puVar10;
      uStack_204 = puVar10[1];
      uVar14 = 0;
      FUN_00401740(&DAT_009dbd90,2);
      uVar7 = FUN_00404230(auStack_f8);
      FUN_00401660(uVar7,0,0xffffffff);
      if (0xf < uStack_e0) {
        _free(pvStack_f4);
        return;
      }
      pcVar8 = acStack_b8;
      uStack_e0 = 0xf;
      uStack_e4 = 0;
      pvStack_f4 = (void *)((uint)pvStack_f4 & 0xffffff00);
      uStack_1cc = 0xf;
      uStack_1d0 = 0;
      pvStack_1e0 = (void *)((uint)pvStack_1e0 & 0xffffff00);
      do {
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_00401740(acStack_b8,(int)pcVar8 - (int)(acStack_b8 + 1));
      FUN_00401660(auStack_1e4,0,0xffffffff);
      if (0xf < uStack_1cc) {
        _free(pvStack_1e0);
        return;
      }
      uStack_1cc = 0xf;
      uStack_1d0 = 0;
      pvStack_1e0 = (void *)((uint)pvStack_1e0 & 0xffffff00);
      FUN_00401740(&DAT_009dbd94,1);
      iStack_1c8 = (uint)(uStack_204._2_1_ != '\0') * 2 + 10;
LAB_00689736:
      uStack_1c4 = 0;
    }
    uVar7 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x7d10031);
    uStack_204 = 0xf;
    uStack_208 = 0;
    pvStack_218 = (void *)((uint)pvStack_218 & 0xffffff00);
    FUN_00401660(uVar7,0,0xffffffff);
    FUN_004041a0(auStack_128,uStack_90);
    pcVar8 = acStack_8c;
    uStack_220 = 0xf;
    uStack_224 = 0;
    pvStack_234 = (void *)((uint)pvStack_234 & 0xffffff00);
    do {
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_8c,(int)pcVar8 - (int)(acStack_8c + 1));
    FUN_004041a0(auStack_d4,uStack_90);
    uVar15 = 0;
    FUN_00401660(auStack_21c,0,0xffffffff);
    uVar7 = FUN_00404230(auStack_144,uVar14,uVar15);
    FUN_00401660(uVar7,0,0xffffffff);
    if (0xf < uStack_12c) {
      _free(pvStack_140);
      return;
    }
    uStack_12c = 0xf;
    uStack_130 = 0;
    pvStack_140 = (void *)((uint)pvStack_140 & 0xffffff00);
    if (0xf < uStack_bc) {
      _free(pvStack_d0);
      return;
    }
    uStack_bc = 0xf;
    uStack_c0 = 0;
    pvStack_d0 = (void *)((uint)pvStack_d0 & 0xffffff00);
    if (0xf < uStack_220) {
      _free(pvStack_234);
      return;
    }
    uStack_220 = 0xf;
    uStack_224 = 0;
    pvStack_234 = (void *)((uint)pvStack_234 & 0xffffff00);
    FUN_00406720(auStack_21c);
    FUN_0068a680(auStack_1c0);
    if ((void *)0xf < pvStack_110) {
      _free(pvStack_124);
      return;
    }
    pvStack_110 = (void *)0xf;
    uStack_114 = 0;
    pvStack_124 = (void *)((uint)pvStack_124 & 0xffffff00);
    if (0xf < uStack_204) {
      _free(pvStack_218);
      return;
    }
    uStack_204 = 0xf;
    uStack_208 = 0;
    pvStack_218 = (void *)((uint)pvStack_218 & 0xffffff00);
    FUN_00689be0();
    puVar11 = puVar11 + 1;
  } while( true );
}


// ==== FUN_00689980 @ 0x00689980 ====

void FUN_00689980(void)

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
  FUN_00401740(s_UI_Game2_Quest_ui_clientquestlis_009dbd48,0x25);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  if (*(void **)(in_ECX + 0xc) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    FUN_006893a0();
    return;
  }
  _free(*(void **)(in_ECX + 0xc));
  return;
}


// ==== FUN_00689a10 @ 0x00689a10 ====

void FUN_00689a10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dbdd0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[1] = 0;
  FUN_00689980();
  return;
}


// ==== FUN_00689a40 @ 0x00689a40 ====

int FUN_00689a40(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x78;
}


// ==== FUN_00689a70 @ 0x00689a70 ====

void FUN_00689a70(undefined2 *param_1)

{
  undefined2 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *in_ECX = *param_1;
  puVar2 = (undefined4 *)(param_1 + 1);
  puVar3 = (undefined4 *)(in_ECX + 1);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined1 *)puVar3 = *(undefined1 *)puVar2;
  puVar2 = (undefined4 *)((int)param_1 + 0x1b);
  puVar3 = (undefined4 *)((int)in_ECX + 0x1b);
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = (undefined4 *)((int)param_1 + 0x9b);
  puVar3 = (undefined4 *)((int)in_ECX + 0x9b);
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined1 *)((int)in_ECX + 0x11b) = *(undefined1 *)((int)param_1 + 0x11b);
  *(undefined4 *)(in_ECX + 0x8e) = *(undefined4 *)(param_1 + 0x8e);
  *(undefined1 *)(in_ECX + 0x90) = *(undefined1 *)(param_1 + 0x90);
  *(undefined ***)(in_ECX + 0x92) = &PTR_FUN_009a6d44;
  puVar2 = (undefined4 *)(param_1 + 0x94);
  puVar3 = (undefined4 *)(in_ECX + 0x94);
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(in_ECX + 0xbc) = *(undefined4 *)(param_1 + 0xbc);
  return;
}


// ==== FUN_00689b00 @ 0x00689b00 ====

int FUN_00689b00(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c660;
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


// ==== Catch@00689b66 @ 0x00689b66 ====

void Catch_00689b66(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00689b70 @ 0x00689b70 ====

void FUN_00689b70(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c670;
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


// ==== Catch@00689bd6 @ 0x00689bd6 ====

void Catch_00689bd6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00689be0 @ 0x00689be0 ====

void FUN_00689be0(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x74)) {
    _free(*(void **)(in_ECX + 0x60));
    return;
  }
  *(undefined4 *)(in_ECX + 0x74) = 0xf;
  *(undefined4 *)(in_ECX + 0x70) = 0;
  *(undefined1 *)(in_ECX + 0x60) = 0;
  if (0xf < *(uint *)(in_ECX + 0x58)) {
    _free(*(void **)(in_ECX + 0x44));
    return;
  }
  *(undefined4 *)(in_ECX + 0x58) = 0xf;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined1 *)(in_ECX + 0x44) = 0;
  if (0xf < *(uint *)(in_ECX + 0x3c)) {
    _free(*(void **)(in_ECX + 0x28));
    return;
  }
  *(undefined4 *)(in_ECX + 0x3c) = 0xf;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined1 *)(in_ECX + 0x28) = 0;
  if (*(uint *)(in_ECX + 0x20) < 0x10) {
    *(undefined4 *)(in_ECX + 0x20) = 0xf;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined1 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0xc));
  return;
}


// ==== FUN_00689c60 @ 0x00689c60 ====

void FUN_00689c60(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00689b00(param_1,param_2,param_3);
  return;
}


// ==== FUN_00689c80 @ 0x00689c80 ====

int FUN_00689c80(int param_1,int param_2,undefined4 param_3)

{
  FUN_00689b70(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_00689cb0 @ 0x00689cb0 ====

void FUN_00689cb0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  *(undefined1 *)(in_ECX + 1) = *(undefined1 *)(param_1 + 1);
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  FUN_00401660(param_1 + 2,0,0xffffffff);
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  FUN_00401660(param_1 + 9,0,0xffffffff);
  in_ECX[0x16] = 0xf;
  in_ECX[0x15] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  FUN_00401660(param_1 + 0x10,0,0xffffffff);
  in_ECX[0x1d] = 0xf;
  in_ECX[0x1c] = 0;
  *(undefined1 *)(in_ECX + 0x18) = 0;
  FUN_00401660(param_1 + 0x17,0,0xffffffff);
  return;
}


// ==== FUN_00689d40 @ 0x00689d40 ====

undefined4 * FUN_00689d40(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x78;
    puVar2 = param_3 + -0x1e;
    *puVar2 = *(undefined4 *)(param_2 + -0x78);
    *(undefined1 *)(param_3 + -0x1d) = *(undefined1 *)(param_2 + -0x74);
    FUN_00401660(param_2 + -0x70,0,0xffffffff);
    FUN_00401660(param_2 + -0x54,0,0xffffffff);
    FUN_00401660(param_2 + -0x38,0,0xffffffff);
    FUN_00401660(param_2 + -0x1c,0,0xffffffff);
    param_2 = iVar1;
    param_3 = puVar2;
  } while (iVar1 != param_1);
  return puVar2;
}


// ==== FUN_00689dc0 @ 0x00689dc0 ====

void FUN_00689dc0(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    FUN_00689cb0(param_2);
  }
  return;
}


// ==== FUN_00689de0 @ 0x00689de0 ====

int FUN_00689de0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c680;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x78) {
    FUN_00689dc0(param_3,param_1);
    param_3 = param_3 + 0x78;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00689e4a @ 0x00689e4a ====

void Catch_00689e4a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x78) {
    FUN_00689be0();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00689e70 @ 0x00689e70 ====

int FUN_00689e70(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  return iVar1 + param_1 * 4;
}


// ==== FUN_00689ea0 @ 0x00689ea0 ====

void FUN_00689ea0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0098c690;
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
      uVar5 = FUN_00689c60(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00689c80(uVar5,param_2,&local_18);
      FUN_00689c60(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_00689b00(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_00689c80(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_00689b00(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0068a001 @ 0x0068a001 ====

void Catch_0068a001(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0068a0f0 @ 0x0068a0f0 ====

void FUN_0068a0f0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_1 = *param_3;
      *(undefined1 *)(param_1 + 1) = *(undefined1 *)(param_3 + 1);
      FUN_00401660(param_3 + 2,0,0xffffffff);
      FUN_00401660(param_3 + 9,0,0xffffffff);
      FUN_00401660(param_3 + 0x10,0,0xffffffff);
      FUN_00401660(param_3 + 0x17,0,0xffffffff);
      param_1 = param_1 + 0x1e;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_0068a160 @ 0x0068a160 ====

void FUN_0068a160(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c6a0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_00689dc0(param_1,param_3);
    param_1 = param_1 + 0x78;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0068a1ca @ 0x0068a1ca ====

void Catch_0068a1ca(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x78) {
    FUN_00689be0();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0068a1f0 @ 0x0068a1f0 ====

void FUN_0068a1f0(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x78) {
    FUN_00689be0();
  }
  return;
}


// ==== FUN_0068a220 @ 0x0068a220 ====

void FUN_0068a220(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00689de0(param_1,param_2,param_3);
  return;
}


// ==== FUN_0068a240 @ 0x0068a240 ====

void FUN_0068a240(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x78) {
    FUN_00689be0();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0068a290 @ 0x0068a290 ====

int FUN_0068a290(int param_1,int param_2,undefined4 param_3)

{
  FUN_0068a160(param_1,param_2,param_3);
  return param_1 + param_2 * 0x78;
}


// ==== FUN_0068a2c0 @ 0x0068a2c0 ====

void FUN_0068a2c0(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint extraout_ECX;
  undefined1 local_b4 [2];
  undefined1 auStack_b2 [122];
  undefined4 local_38;
  int local_30;
  uint local_2c;
  int local_28;
  void *local_20;
  void *local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c6b0;
  local_10 = ExceptionList;
  local_14 = local_b4 + -0xc;
  ExceptionList = &local_10;
  FUN_00689cb0(param_3);
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (*(int *)(in_ECX + 0xc) - iVar1) / 0x78;
  }
  if (param_2 != 0) {
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x78;
    }
    if (0x2222222U - iVar1 < param_2) {
      FUN_0085b3b0();
      uVar4 = extraout_ECX;
    }
    if (*(int *)(in_ECX + 4) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x78;
    }
    if (uVar4 < iVar1 + param_2) {
      if (0x2222222 - (uVar4 >> 1) < uVar4) {
        uVar4 = 0;
      }
      else {
        uVar4 = uVar4 + (uVar4 >> 1);
      }
      if (*(int *)(in_ECX + 4) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x78;
      }
      if (uVar4 < iVar1 + param_2) {
        iVar1 = FUN_00689a40();
        uVar4 = iVar1 + param_2;
      }
      local_2c = uVar4 * 0x78;
      local_20 = operator_new(local_2c);
      local_8 = 0;
      local_1c = local_20;
      local_1c = (void *)FUN_0068a220(*(undefined4 *)(in_ECX + 4),param_1,local_20);
      local_1c = (void *)FUN_0068a290(local_1c,param_2,local_b4);
      FUN_0068a220(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      iVar1 = *(int *)(in_ECX + 4);
      if (iVar1 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar1) / 0x78;
      }
      if (iVar1 != 0) {
        FUN_0068a1f0(iVar1,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(uint *)(in_ECX + 0xc) = local_2c + (int)local_20;
      *(void **)(in_ECX + 8) = (void *)((int)local_20 + (param_2 + iVar2) * 0x78);
      *(void **)(in_ECX + 4) = local_20;
    }
    else {
      local_30 = *(int *)(in_ECX + 8);
      local_28 = local_30 - param_1;
      if ((uint)(local_28 / 0x78) < param_2) {
        local_18 = param_2 * 0x78;
        FUN_00689de0(param_1,local_30,local_18 + param_1);
        local_8 = 2;
        FUN_0068a290(*(undefined4 *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x78,
                     local_b4);
        local_8 = 0xffffffff;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_18;
        FUN_0068a0f0(param_1,*(int *)(in_ECX + 8) - local_18,local_b4);
      }
      else {
        local_18 = param_2 * 0x78;
        iVar1 = local_30 + param_2 * -0x78;
        uVar3 = FUN_00689de0(iVar1,local_30,local_30);
        *(undefined4 *)(in_ECX + 8) = uVar3;
        FUN_00689d40(param_1,iVar1,local_30,local_38);
        FUN_0068a0f0(param_1,local_18 + param_1,local_b4);
      }
    }
  }
  FUN_00689be0();
  ExceptionList = local_10;
  return;
}


// ==== Catch@0068a490 @ 0x0068a490 ====

void Catch_0068a490(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x1c);
  FUN_0068a1f0(_Memory,*(undefined4 *)(unaff_EBP + -0x18));
  _free(_Memory);
  return;
}


// ==== Catch@0068a559 @ 0x0068a559 ====

void Catch_0068a559(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x78;
  FUN_0068a1f0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x20) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0068a5f0 @ 0x0068a5f0 ====

void FUN_0068a5f0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x78 != 0) {
      iVar1 = (param_2 - iVar1) / 0x78;
      goto LAB_0068a639;
    }
  }
  iVar1 = 0;
LAB_0068a639:
  FUN_0068a2c0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x78;
  return;
}


// ==== FUN_0068a670 @ 0x0068a670 ====

undefined4 FUN_0068a670(void)

{
  return 0x6e;
}


// ==== FUN_0068a680 @ 0x0068a680 ====

void FUN_0068a680(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x78) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x78))) {
    FUN_0068a5f0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0068a160(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x78;
  return;
}


// ==== FUN_0068a710 @ 0x0068a710 ====

void FUN_0068a710(byte param_1)

{
  void *in_ECX;
  
  FUN_00689200();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0068a730 @ 0x0068a730 ====

void FUN_0068a730(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 9) == '\0') {
    *(undefined1 *)(in_ECX + 9) = 1;
  }
  return;
}


// ==== FUN_0068a740 @ 0x0068a740 ====

undefined1 FUN_0068a740(void)

{
  return 0;
}


// ==== FUN_0068a750 @ 0x0068a750 ====

void FUN_0068a750(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) != '\0') {
    (**(code **)(*DAT_00b5a7a4 + 8))(*(undefined4 *)(in_ECX + 4));
    *(undefined1 *)(in_ECX + 8) = 0;
  }
  return;
}


// ==== FUN_0068a7a0 @ 0x0068a7a0 ====

void FUN_0068a7a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dbe84;
  if (*(char *)(in_ECX + 2) != '\0') {
    (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
    *(undefined1 *)(in_ECX + 2) = 0;
  }
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0068a7d0 @ 0x0068a7d0 ====

undefined4 FUN_0068a7d0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_alarm_009dbe70,9);
    if (iVar2 == 0) {
      cVar1 = (**(code **)(*DAT_00b5ae6c + 0x28))();
      if (cVar1 != '\0') {
        (**(code **)(*DAT_00b5ae6c + 0x18))();
      }
      (**(code **)(*DAT_00b5ae6c + 0xc))();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0068a830 @ 0x0068a830 ====

undefined4 FUN_0068a830(void)

{
  short sVar1;
  undefined4 *puVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  short *psVar7;
  undefined4 extraout_EAX;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar5 = (**(code **)(*DAT_00b5ae70 + 0x14))();
  puVar9 = *(undefined4 **)(iVar5 + 0x10);
  puVar2 = *(undefined4 **)(iVar5 + 0x14);
  iVar5 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if (iVar5 != 0) {
    piVar6 = (int *)(**(code **)(**(int **)(iVar5 + 0x48) + 0x28))();
    psVar7 = (short *)(**(code **)(*piVar6 + 8))();
    sVar1 = *psVar7;
    if (sVar1 != 0) {
      if (puVar9 == puVar2) {
        return 0;
      }
      do {
        cVar4 = (**(code **)(*(int *)*puVar9 + 0x1c))(sVar1);
        if (cVar4 == '\x01') {
          return 1;
        }
        puVar9 = puVar9 + 1;
      } while (puVar9 != puVar2);
      return 0;
    }
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_FALSE_009dbe68,5);
  FUN_00406880(auStack_1c);
  if (uStack_4 < 0x10) {
    pcVar3 = (code *)swi(3);
    uVar8 = (*pcVar3)();
    return uVar8;
  }
  _free(pvStack_18);
  return extraout_EAX;
}


// ==== FUN_0068a8f0 @ 0x0068a8f0 ====

void FUN_0068a8f0(void)

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
    FUN_00401740(s_UI_Game2_ui_QNoticeAlarm_txt_009dbe3c,0x1c);
    iVar1 = FUN_00410500(local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    *(undefined1 *)(in_ECX + 8) = 1;
  }
  return;
}


// ==== FUN_0068a970 @ 0x0068a970 ====

void FUN_0068a970(void)

{
  undefined1 uVar1;
  int *piVar2;
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
  FUN_00401740(s_btn_alarm_009dbe5c,9);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar2 != (int *)0x0) {
    uVar1 = FUN_0068a830();
    uVar3 = (**(code **)(*piVar2 + 0x30))
                      (0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                       &Framework::UI::Control::Button::RTTI_Type_Descriptor,0);
    FUN_00803725(uVar3);
    FUN_00558130(uVar1);
  }
  return;
}


// ==== FUN_0068aa10 @ 0x0068aa10 ====

void FUN_0068aa10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dbe84;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[1] = 0;
  FUN_0068a8f0();
  return;
}


// ==== FUN_0068aa30 @ 0x0068aa30 ====

undefined4 FUN_0068aa30(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70440005) {
    FUN_0068a970();
    return 1;
  }
  return 0;
}


// ==== FUN_0068aa60 @ 0x0068aa60 ====

undefined4 FUN_0068aa60(void)

{
  return 0x6d;
}


// ==== FUN_0068aa70 @ 0x0068aa70 ====

void FUN_0068aa70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dbe84;
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


// ==== FUN_0068aab0 @ 0x0068aab0 ====

void FUN_0068aab0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 9) == '\0') {
    *(undefined1 *)(in_ECX + 9) = 1;
  }
  return;
}


// ==== FUN_0068aad0 @ 0x0068aad0 ====

undefined4 FUN_0068aad0(void)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5ae6c + 0x24))();
  if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5ae6c + 0x10))();
    (**(code **)(*DAT_00b5ae6c + 0x14))();
    return 1;
  }
  return 0;
}


// ==== FUN_0068ab00 @ 0x0068ab00 ====

undefined4 FUN_0068ab00(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char cVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x24);
  puVar4 = *(undefined4 **)(in_ECX + 0x20);
  while( true ) {
    if (puVar4 == puVar1) {
      return 0;
    }
    uVar2 = *puVar4;
    cVar3 = FUN_0056f680(param_1);
    if (cVar3 == '\x01') break;
    puVar4 = puVar4 + 1;
  }
  return uVar2;
}


// ==== FUN_0068ab40 @ 0x0068ab40 ====

void FUN_0068ab40(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x24);
  for (puVar4 = *(undefined4 **)(in_ECX + 0x20); puVar4 != puVar1; puVar4 = puVar4 + 1) {
    iVar2 = **(int **)(in_ECX + 4);
    uVar3 = (**(code **)(*(int *)*puVar4 + 0x3c))();
    (**(code **)(iVar2 + 0x28))(uVar3);
  }
  if (*(void **)(in_ECX + 0x20) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x20) = 0;
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined4 *)(in_ECX + 0x28) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x20));
  return;
}


// ==== FUN_0068ab90 @ 0x0068ab90 ====

void FUN_0068ab90(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) != '\0') {
    FUN_0068ab40();
    if (*(undefined4 **)(in_ECX + 0x10) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x10))(1);
    }
    *(undefined4 *)(in_ECX + 0x10) = 0;
    (**(code **)(*DAT_00b5a7a4 + 8))(*(undefined4 *)(in_ECX + 4));
    *(undefined1 *)(in_ECX + 8) = 0;
  }
  return;
}


// ==== FUN_0068abd0 @ 0x0068abd0 ====

void FUN_0068abd0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  undefined1 auStack_3c [32];
  void *pvStack_1c;
  uint uStack_8;
  
  if (*(int *)(in_ECX + 0x14) != 0) {
    if (*(int *)(in_ECX + 0x20) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(in_ECX + 0x24) - *(int *)(in_ECX + 0x20) >> 2;
    }
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x14) + 0x3c))();
    uVar2 = (**(code **)(*piVar1 + 0x10))();
    FUN_005041e0(uVar2);
    auStack_3c[0] = iVar3 == 0;
    (**(code **)(*piVar1 + 0xc))(auStack_3c);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
  }
  return;
}


// ==== FUN_0068ac40 @ 0x0068ac40 ====

void FUN_0068ac40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dbf54;
  if (*(char *)(in_ECX + 2) != '\0') {
    FUN_0068ab40();
    if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[4])(1);
    }
    in_ECX[4] = 0;
    (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
    *(undefined1 *)(in_ECX + 2) = 0;
  }
  if ((void *)in_ECX[8] == (void *)0x0) {
    in_ECX[8] = 0;
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  _free((void *)in_ECX[8]);
  return;
}


// ==== FUN_0068aca0 @ 0x0068aca0 ====

void FUN_0068aca0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  int in_ECX;
  int iVar7;
  
  if (*(int *)(in_ECX + 0x18) != 0) {
    if (*(int *)(in_ECX + 0x20) == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = *(int *)(in_ECX + 0x24) - *(int *)(in_ECX + 0x20) >> 2;
    }
    uVar5 = iVar7 - *(int *)(in_ECX + 0xc);
    FUN_0055aac0(uVar5 & ((int)uVar5 < 1) - 1);
    iVar1 = *(int *)(*(int *)(in_ECX + 0x18) + 0x88);
    iVar2 = *(int *)(in_ECX + 0xc);
    uVar5 = 0;
    if (0 < iVar7) {
      do {
        iVar3 = *(int *)(in_ECX + 0x20);
        if ((iVar3 == 0) || ((uint)(*(int *)(in_ECX + 0x24) - iVar3 >> 2) <= uVar5)) {
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        piVar4 = *(int **)(iVar3 + uVar5 * 4);
        if (piVar4 != (int *)0x0) {
          uVar6 = (**(code **)(*piVar4 + 0x3c))();
          FUN_006da4a0(uVar6,uVar5,iVar1,iVar2 + iVar1);
        }
        uVar5 = uVar5 + 1;
      } while ((int)uVar5 < iVar7);
    }
  }
  return;
}


// ==== FUN_0068ad40 @ 0x0068ad40 ====

undefined4 FUN_0068ad40(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009dbf30,8);
      if (iVar2 == 0) {
        cVar1 = (**(code **)(*DAT_00b5ae6c + 0x24))();
        if (cVar1 != '\0') {
          (**(code **)(*DAT_00b5ae6c + 0x10))();
        }
        (**(code **)(*DAT_00b5ae6c + 0x14))();
        return 1;
      }
    }
  }
  else if ((param_1 == 4) && (param_3 == 6)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_scroll_notice_009dbf3c,0xd);
    if (iVar2 == 0) {
      FUN_0068aca0();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0068add0 @ 0x0068add0 ====

void FUN_0068add0(void)

{
  undefined4 *puVar1;
  int *piVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int in_ECX;
  undefined4 *puVar7;
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 *puStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar5 = (**(code **)(*DAT_00b5ae70 + 0x14))();
  puVar1 = *(undefined4 **)(iVar5 + 0x14);
  puVar7 = *(undefined4 **)(iVar5 + 0x10);
  puStack_20 = puVar1;
  uVar6 = FUN_006da410();
  uStack_24 = uVar6;
  if ((short)uVar6 != 0) {
    iStack_2c = 1;
    if (puVar7 != puVar1) {
      do {
        piVar2 = (int *)*puVar7;
        cVar4 = (**(code **)(*piVar2 + 0x1c))(uVar6);
        if (cVar4 != '\0') {
          (**(code **)(*piVar2 + 4))();
          uVar6 = (**(code **)(*piVar2 + 8))();
          uStack_28 = FUN_006daaa0(iStack_2c,uVar6);
          iVar5 = *(int *)(in_ECX + 0x20);
          if ((iVar5 == 0) ||
             ((uint)(*(int *)(in_ECX + 0x28) - iVar5 >> 2) <=
              (uint)(*(int *)(in_ECX + 0x24) - iVar5 >> 2))) {
            FUN_0068b1e0(*(undefined4 *)(in_ECX + 0x24),1,&uStack_28);
          }
          else {
            puVar1 = *(undefined4 **)(in_ECX + 0x24);
            *puVar1 = uStack_28;
            *(undefined4 **)(in_ECX + 0x24) = puVar1 + 1;
          }
          iStack_2c = iStack_2c + 1;
          uVar6 = uStack_24;
        }
        puVar7 = puVar7 + 1;
      } while (puVar7 != puStack_20);
    }
    FUN_0068abd0();
    FUN_0068aca0();
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_FALSE_009dbf28,5);
  FUN_00406880(auStack_1c);
  if (uStack_4 < 0x10) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  _free(pvStack_18);
  return;
}


// ==== FUN_0068af10 @ 0x0068af10 ====

void FUN_0068af10(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  void *pvVar4;
  int in_ECX;
  void *unaff_EBP;
  void *unaff_EDI;
  undefined1 auStack_38 [4];
  undefined4 local_1c;
  void *local_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 local_8;
  uint local_4;
  
  if (*(char *)(in_ECX + 8) != '\x01') {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_UI_Game2_ui_QNoticeInfo_txt_009dbef0,0x1b);
    iVar1 = FUN_00410500(&local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    uStack_10 = 0xf;
    uStack_14 = 0;
    FUN_00401740(s_scroll_notice_009dbf0c,0xd);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_38 + 0x10);
    if (0xf < uStack_14) {
      _free(unaff_EBP);
      return;
    }
    uStack_14 = 0xf;
    local_18 = (void *)0x0;
    uVar3 = (**(code **)(*piVar2 + 0x30))
                      (0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                       &Framework::UI::Control::VScroll::RTTI_Type_Descriptor,0);
    uVar3 = FUN_00803725(uVar3);
    *(undefined4 *)(in_ECX + 0x18) = uVar3;
    uStack_14 = 0xf;
    local_18 = (void *)0x0;
    FUN_00401740(s_lbl_empty_009dbf1c,9);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_38 + 0xc);
    if (0xf < local_18) {
      _free(unaff_EDI);
      return;
    }
    local_18 = (void *)0xf;
    local_1c = 0;
    uVar3 = (**(code **)(*piVar2 + 0x30))
                      (0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                       &Framework::UI::Control::Label::RTTI_Type_Descriptor,0);
    uVar3 = FUN_00803725(uVar3);
    *(undefined4 *)(in_ECX + 0x14) = uVar3;
    pvVar4 = operator_new(0xc);
    if (pvVar4 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_006daa70(*(undefined4 *)(in_ECX + 4));
    }
    *(undefined4 *)(in_ECX + 0x10) = uVar3;
    FUN_0068add0();
    *(undefined1 *)(in_ECX + 8) = 1;
  }
  return;
}


// ==== FUN_0068b090 @ 0x0068b090 ====

void FUN_0068b090(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dbf54;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[3] = 3;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[1] = 0;
  FUN_0068af10();
  return;
}


// ==== FUN_0068b0d0 @ 0x0068b0d0 ====

void FUN_0068b0d0(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 auStack_4ca [94];
  int iStack_46c;
  int iStack_468;
  int iStack_464;
  undefined1 auStack_110 [272];
  
  if (((*(char *)(in_ECX + 8) != '\0') &&
      (piVar1 = (int *)FUN_0068ab00(param_1), piVar1 != (int *)0x0)) &&
     (piVar2 = (int *)(**(code **)(*DAT_00b5ae70 + 0x10))(param_1), piVar2 != (int *)0x0)) {
    (**(code **)(*piVar2 + 4))();
    FUN_00505f10();
    iStack_46c = piVar1[0x1c];
    iStack_468 = piVar1[0x1d];
    iStack_464 = piVar1[0x1e];
    FUN_0068b450(piVar1 + 0x1f);
    FUN_0056feb0(auStack_4ca + -6);
    FUN_00504010();
    uVar3 = (**(code **)(*piVar2 + 8))();
    FUN_006da450(auStack_110,uVar3);
    (**(code **)(*piVar1 + 0x24))(&iStack_46c);
    FUN_00505d80();
  }
  return;
}


// ==== FUN_0068b1a0 @ 0x0068b1a0 ====

undefined4 FUN_0068b1a0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70440004) {
    FUN_0068b0d0(param_1[1]);
    return 1;
  }
  return 0;
}


// ==== FUN_0068b1d0 @ 0x0068b1d0 ====

undefined4 FUN_0068b1d0(void)

{
  return 0x6c;
}


// ==== FUN_0068b1e0 @ 0x0068b1e0 ====

void FUN_0068b1e0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0098c6c0;
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


// ==== Catch@0068b341 @ 0x0068b341 ====

void Catch_0068b341(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0068b430 @ 0x0068b430 ====

void FUN_0068b430(byte param_1)

{
  void *in_ECX;
  
  FUN_0068ac40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0068b450 @ 0x0068b450 ====

void FUN_0068b450(int param_1)

{
  int in_ECX;
  
  FUN_00430c20(param_1);
  *(undefined4 *)(in_ECX + 0x28) = 0xf;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined1 *)(in_ECX + 0x14) = 0;
  FUN_00401660(param_1 + 0x10,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x44) = 0xf;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined1 *)(in_ECX + 0x30) = 0;
  FUN_00401660(param_1 + 0x2c,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x60) = 0xf;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined1 *)(in_ECX + 0x4c) = 0;
  FUN_00401660(param_1 + 0x48,0,0xffffffff);
  return;
}


// ==== FUN_0068b4c0 @ 0x0068b4c0 ====

void FUN_0068b4c0(void)

{
  return;
}


// ==== FUN_0068b4d0 @ 0x0068b4d0 ====

void FUN_0068b4d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dc034;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0068b4f0 @ 0x0068b4f0 ====

undefined4 FUN_0068b4f0(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_accept_009dc020,10);
    if (iVar1 == 0) {
      (**(code **)(*DAT_00b5ad90 + 0x2c))();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0068b530 @ 0x0068b530 ====

void FUN_0068b530(void)

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
  FUN_00401740(s_UI_Game2_PVPBattleWnd_ui_restore_009dbfc0,0x27);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    *(undefined4 *)(in_ECX + 8) = 15000;
    *(undefined4 *)(in_ECX + 0x10) = 0xf;
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0068b5b0 @ 0x0068b5b0 ====

int FUN_0068b5b0(void)

{
  int *piVar1;
  int extraout_EAX;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int extraout_EAX_00;
  int in_ECX;
  uint uVar5;
  void *local_38;
  undefined1 local_34;
  undefined4 uStack_28;
  void *local_24;
  undefined4 local_20;
  uint uStack_10;
  
  uVar5 = *(int *)(in_ECX + 8) - *(int *)(in_ECX + 0xc);
  iVar4 = uVar5 * 0x10624dd3;
  uVar5 = uVar5 / 1000;
  if (*(uint *)(in_ECX + 0x10) != uVar5) {
    *(uint *)(in_ECX + 0x10) = uVar5;
    local_20 = 0xf;
    local_24 = (void *)0x0;
    local_34 = 0;
    FUN_00401740(s_lbl_waittime_009dc010,0xc);
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
    if (0xf < local_24) {
      _free(local_38);
      return extraout_EAX;
    }
    local_24 = (void *)0xf;
    uStack_28 = 0;
    local_38 = (void *)((uint)local_38 & 0xffffff00);
    iVar4 = 0;
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x30))();
      iVar4 = 0;
      if (iVar2 != 0) {
        uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1220029,*(undefined4 *)(in_ECX + 0x10));
        FUN_00401660(uVar3,0,0xffffffff);
        FUN_00404230(&uStack_28);
        iVar4 = FUN_0055a260(&uStack_28);
        if (0xf < uStack_10) {
          _free(local_24);
          return extraout_EAX_00;
        }
      }
    }
  }
  return iVar4;
}


// ==== FUN_0068b6a0 @ 0x0068b6a0 ====

void FUN_0068b6a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dc034;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  FUN_0068b530();
  return;
}


// ==== FUN_0068b6c0 @ 0x0068b6c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068b6c0(int param_1)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  void *local_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  uVar1 = *(uint *)(in_ECX + 8);
  if ((uVar1 != 0) && (*(uint *)(in_ECX + 0xc) < uVar1)) {
    uVar6 = *(uint *)(in_ECX + 0xc) + *(int *)(param_1 + 4);
    *(uint *)(in_ECX + 0xc) = uVar6;
    if (uVar1 < uVar6) {
      *(uint *)(in_ECX + 0xc) = uVar1;
    }
    if (*(uint *)(in_ECX + 0xc) < uVar1) {
      FUN_00401830(s_processbar_009dbfe8);
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_1c);
      if (0xf < uStack_8) {
        _free(local_1c[0]);
        return;
      }
      uStack_8 = 0xf;
      uStack_c = 0;
      local_1c[0] = (void *)((uint)local_1c[0] & 0xffffff00);
      if ((piVar4 != (int *)0x0) && (iVar5 = (**(code **)(*piVar4 + 0x30))(), iVar5 != 0)) {
        fVar2 = (float)*(int *)(in_ECX + 0xc);
        if (*(int *)(in_ECX + 0xc) < 0) {
          fVar2 = fVar2 + _DAT_0099d104;
        }
        fVar3 = (float)*(int *)(in_ECX + 8);
        if (*(int *)(in_ECX + 8) < 0) {
          fVar3 = fVar3 + _DAT_0099d104;
        }
        FUN_00587ba0((fVar2 / fVar3) * DAT_0099de78);
        FUN_0068b5b0();
        return;
      }
    }
    else if (*(uint *)(in_ECX + 0xc) == uVar1) {
      FUN_00401830(s_pan_waittime_009dbff4);
      (**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_1c);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  return;
}


// ==== FUN_0068b820 @ 0x0068b820 ====

uint FUN_0068b820(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_0068b6c0(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0068b850 @ 0x0068b850 ====

undefined4 FUN_0068b850(void)

{
  return 0x5b;
}


// ==== FUN_0068b860 @ 0x0068b860 ====

void FUN_0068b860(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009dc034;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0068b8a0 @ 0x0068b8a0 ====

void FUN_0068b8a0(void)

{
  return;
}


// ==== FUN_0068b8b0 @ 0x0068b8b0 ====

undefined1 FUN_0068b8b0(void)

{
  return 0;
}


// ==== FUN_0068b8c0 @ 0x0068b8c0 ====

undefined1 FUN_0068b8c0(void)

{
  return 0;
}


// ==== FUN_0068b8d0 @ 0x0068b8d0 ====

void FUN_0068b8d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dc118;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0068b940 @ 0x0068b940 ====

void FUN_0068b940(void)

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
  FUN_00401740(s_UI_Game2_PVPBattleWnd_ui_pvpcoun_009dc0a0,0x28);
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


// ==== FUN_0068b9c0 @ 0x0068b9c0 ====

void FUN_0068b9c0(undefined1 param_1)

{
  int *piVar1;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  *(undefined1 *)(in_ECX + 8) = param_1;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_back_count_009dc0cc,0xe);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(1);
  }
  if (local_8 < 0x10) {
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_0068bb60 @ 0x0068bb60 ====

void FUN_0068bb60(void)

{
  int *piVar1;
  int in_ECX;
  undefined4 unaff_retaddr;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_lbl_text_009dc0f0,8);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
    FUN_0055a260(unaff_retaddr);
  }
  if (local_8 < 0x10) {
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_0068bbd0 @ 0x0068bbd0 ====

/* WARNING: Removing unreachable block (ram,0x0068bd2b) */

void FUN_0068bbd0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  void *apvStack_40 [4];
  undefined4 uStack_30;
  uint uStack_2c;
  void *apvStack_24 [5];
  uint uStack_10;
  
  uVar4 = *(int *)(param_1 + 0xc) - *(int *)(in_ECX + 0x10);
  if (*(uint *)(in_ECX + 0xc) < uVar4) {
    piVar1 = (int *)(**(code **)(*DAT_00b5ad98 + 8))();
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0xc))();
      if (iVar2 == 4) {
        FUN_006ee480();
      }
      iVar2 = (**(code **)(*piVar1 + 0xc))();
      if (iVar2 == 5) {
        FUN_006ee240();
      }
      (**(code **)(*DAT_00b5ad90 + 0x20))();
      *(undefined4 *)(in_ECX + 0xc) = 0;
      return;
    }
  }
  else if ((*(char *)(in_ECX + 8) != '\0') && (uVar4 <= *(uint *)(in_ECX + 0xc))) {
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x3f0000a);
    FUN_00401660(uVar3,0,0xffffffff);
    FUN_00401830(s_lbl_count_009dc104);
    FUN_00401830(s__d__s_009dc0fc);
    uVar3 = FUN_00404230(apvStack_40);
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_24);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x30))();
      FUN_0055a260(uVar3);
    }
    if (0xf < uStack_2c) {
      _free(apvStack_40[0]);
      return;
    }
    uStack_2c = 0xf;
    uStack_30 = 0;
    apvStack_40[0] = (void *)((uint)apvStack_40[0] & 0xffffff00);
    if (0xf < uStack_10) {
      _free(apvStack_24[0]);
      return;
    }
  }
  return;
}


// ==== FUN_0068bd50 @ 0x0068bd50 ====

void FUN_0068bd50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dc118;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  FUN_0068b940();
  return;
}


// ==== FUN_0068bd70 @ 0x0068bd70 ====

uint FUN_0068bd70(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_0068bbd0(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0068bda0 @ 0x0068bda0 ====

undefined4 FUN_0068bda0(void)

{
  return 0x5a;
}


// ==== FUN_0068bdb0 @ 0x0068bdb0 ====

void FUN_0068bdb0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009dc118;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0068bdf0 @ 0x0068bdf0 ====

void FUN_0068bdf0(void)

{
  return;
}


// ==== FUN_0068be00 @ 0x0068be00 ====

undefined1 FUN_0068be00(void)

{
  return 0;
}


// ==== FUN_0068be10 @ 0x0068be10 ====

undefined1 FUN_0068be10(void)

{
  return 0;
}


// ==== FUN_0068be20 @ 0x0068be20 ====

void FUN_0068be20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dc218;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0068be90 @ 0x0068be90 ====

uint FUN_0068be90(int *param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if ((uVar1 == 0x40001) && (5000 < (uint)(param_1[3] - *(int *)(in_ECX + 8)))) {
    uVar1 = (**(code **)(*DAT_00b5ad90 + 0x24))();
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0068bed0 @ 0x0068bed0 ====

void FUN_0068bed0(void)

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
  FUN_00401740(s_UI_Game2_PVPBattleWnd_ui_pvpbatt_009dc184,0x29);
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


// ==== FUN_0068bf50 @ 0x0068bf50 ====

void FUN_0068bf50(char param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_EDI;
  void *pvStack_54;
  void *pvStack_50;
  undefined4 uStack_4c;
  void *pvStack_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_34;
  undefined4 uStack_30;
  void *pvStack_20;
  void *apvStack_1c [4];
  uint uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  iVar1 = (**(code **)(*DAT_00b5ad98 + 0x10))();
  if (iVar1 != 0) {
    if (param_1 == '\0') {
      FUN_00401830(s_lbl_getpoint_009dc1e0);
      FUN_00401830(&DAT_009dc1d8);
      uVar2 = FUN_00404230(&pvStack_54);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_1c);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x30))();
        FUN_0055a260(uVar2);
      }
      if (0xf < uStack_40) {
        _free(pvStack_54);
        return;
      }
      uStack_40 = 0xf;
      uStack_44 = 0;
      pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
      if (0xf < uStack_8) {
        _free(apvStack_1c[0]);
        return;
      }
      FUN_00401830(s_lbl_totalpoint_009dc1f4);
      FUN_00401830(&DAT_009dc1f0);
      uVar2 = FUN_00404230(apvStack_1c + -0xf);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x30))();
        FUN_0055a260(uVar2);
      }
      if (0xf < uStack_44) {
        _free(unaff_EBX);
        return;
      }
      uStack_44 = 0xf;
      pvStack_48 = (void *)0x0;
      if (0xf < uStack_c) {
        _free(pvStack_20);
        return;
      }
    }
    else {
      FUN_00401830(s_lbl_getpoint_009dc1b4);
      FUN_00401830(&DAT_009dc1b0);
      uVar2 = FUN_00404230(&pvStack_54);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_1c);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x30))();
        FUN_0055a260(uVar2);
      }
      if (0xf < uStack_40) {
        _free(pvStack_54);
        return;
      }
      uStack_40 = 0xf;
      uStack_44 = 0;
      pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
      if (0xf < uStack_8) {
        _free(apvStack_1c[0]);
        return;
      }
      FUN_00401830(s_lbl_totalpoint_009dc1c8);
      FUN_00401830(&DAT_009dc1c4);
      uVar2 = FUN_00404230(apvStack_1c + -0xf);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x30))();
        FUN_0055a260(uVar2);
      }
      if (0xf < uStack_44) {
        _free(unaff_EBX);
        return;
      }
      uStack_44 = 0xf;
      pvStack_48 = (void *)0x0;
      if (0xf < uStack_c) {
        _free(pvStack_20);
        return;
      }
    }
    uStack_44 = 0xf;
    pvStack_48 = (void *)0x0;
    uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,uStack_4);
    uStack_30 = 0xf;
    uStack_34 = 0;
    uStack_44 = uStack_44 & 0xffffff00;
    FUN_00401660(uVar2,0,0xffffffff);
    uStack_4c = 0xf;
    pvStack_50 = (void *)0x0;
    FUN_00401740(s_lbl_result_009dc204,10);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_1c + -0x12);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x30))();
      FUN_0055a260(&uStack_4c);
    }
    if (0xf < pvStack_50) {
      _free(unaff_EDI);
      return;
    }
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    *(undefined4 *)(in_ECX + 8) = uVar2;
    if (0xf < uStack_34) {
      _free(pvStack_48);
      return;
    }
  }
  return;
}


// ==== FUN_0068c260 @ 0x0068c260 ====

void FUN_0068c260(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dc218;
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  in_ECX[2] = uVar1;
  FUN_0068bed0();
  return;
}


// ==== FUN_0068c290 @ 0x0068c290 ====

undefined4 FUN_0068c290(void)

{
  return 0x59;
}


// ==== FUN_0068c2a0 @ 0x0068c2a0 ====

void FUN_0068c2a0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009dc218;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0068c2e0 @ 0x0068c2e0 ====

undefined4 FUN_0068c2e0(void)

{
  return 0x30030109;
}


// ==== FUN_0068c330 @ 0x0068c330 ====

void FUN_0068c330(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0068c33c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_0068c340 @ 0x0068c340 ====

void FUN_0068c340(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(param_1);
  }
  return;
}


// ==== FUN_0068c360 @ 0x0068c360 ====

undefined1 FUN_0068c360(void)

{
  return 0;
}


// ==== FUN_0068c370 @ 0x0068c370 ====

float10 FUN_0068c370(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  float10 fVar2;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 == (int *)0x0) {
    return (float10)DAT_0099cdc8;
  }
  (**(code **)(*piVar1 + 0x30))();
  fVar2 = (float10)FUN_005796c0();
  return fVar2;
}


// ==== FUN_0068c3a0 @ 0x0068c3a0 ====

float10 FUN_0068c3a0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  float10 fVar2;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 == (int *)0x0) {
    return (float10)DAT_0099cdc8;
  }
  (**(code **)(*piVar1 + 0x30))();
  fVar2 = (float10)FUN_005796d0();
  return fVar2;
}


// ==== FUN_0068c430 @ 0x0068c430 ====

void FUN_0068c430(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined1 auStack_5e [2];
  undefined4 auStack_5c [15];
  void *pvStack_20;
  uint uStack_c;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  uVar2 = (**(code **)(*piVar1 + 0x10))();
  FUN_005041e0(uVar2);
  puVar3 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  puVar5 = (undefined4 *)(auStack_5e + -6);
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x18))(auStack_5e + -6);
  if (uStack_c < 0x10) {
    return;
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_0068c4b0 @ 0x0068c4b0 ====

void FUN_0068c4b0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  void *unaff_EBX;
  undefined4 unaff_retaddr;
  undefined4 local_1c;
  undefined1 local_18;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  *(undefined4 *)(in_ECX + 0x18) = param_1;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_probar_play_009dc3c8,0xb);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  (**(code **)(*piVar1 + 0x30))();
  FUN_00587ba0(unaff_retaddr);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(s_sld_play_009dc3d4,8);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x20);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      FUN_00579b10(local_4);
    }
  }
  if (0xf < uStack_c) {
    _free(unaff_EBX);
    return;
  }
  if (DAT_0099de78 <= *(float *)(in_ECX + 0x18)) {
    FUN_0068cce0();
  }
  return;
}


// ==== FUN_0068c5b0 @ 0x0068c5b0 ====

undefined4 FUN_0068c5b0(int param_1)

{
  int iVar1;
  undefined4 ****ppppuVar2;
  int iVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  int iVar4;
  undefined4 ****local_38 [4];
  undefined4 local_28;
  uint local_24;
  void *local_1c;
  undefined4 local_c;
  uint local_8;
  undefined4 local_4;
  
  if (*(int *)(param_1 + 4) != 3) {
    return 0;
  }
  local_24 = 0xf;
  local_28 = 0;
  local_38[0] = (undefined4 ****)((uint)local_38[0] & 0xffffff00);
  FUN_00401660(param_1 + 0xc,0,0xffffffff);
  iVar1 = *(int *)(param_1 + 8);
  if ((0 < iVar1) && (iVar4 = *(int *)(in_ECX + 0x24), iVar4 != *(int *)(in_ECX + 0x28))) {
    do {
      local_8 = 0xf;
      local_c = 0;
      local_1c = (void *)((uint)local_1c & 0xffffff00);
      FUN_00401660(iVar4,0,0xffffffff);
      local_4 = *(undefined4 *)(iVar4 + 0x1c);
      ppppuVar2 = local_38[0];
      if (local_24 < 0x10) {
        ppppuVar2 = local_38;
      }
      iVar3 = FUN_00403620(0,local_c,ppppuVar2,local_28);
      if (iVar3 == 0) {
        *(int *)(iVar4 + 0x1c) = iVar1;
      }
      if (0xf < local_8) {
        _free(local_1c);
        return extraout_EAX;
      }
      iVar4 = iVar4 + 0x20;
      local_8 = 0xf;
      local_c = 0;
      local_1c = (void *)((uint)local_1c & 0xffffff00);
    } while (iVar4 != *(int *)(in_ECX + 0x28));
  }
  if (local_24 < 0x10) {
    return 1;
  }
  _free(local_38[0]);
  return extraout_EAX_00;
}


// ==== FUN_0068c6a0 @ 0x0068c6a0 ====

void FUN_0068c6a0(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined1 auStack_5e [2];
  undefined4 auStack_5c [15];
  void *pvStack_20;
  uint uStack_c;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  uVar2 = (**(code **)(*piVar1 + 0x10))();
  FUN_005041e0(uVar2);
  puVar3 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  puVar5 = (undefined4 *)(auStack_5e + -6);
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x18))(auStack_5e + -6);
  if (uStack_c < 0x10) {
    return;
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_0068c730 @ 0x0068c730 ====

void FUN_0068c730(int param_1)

{
  int *piVar1;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  undefined4 local_1c;
  undefined1 local_18;
  undefined4 uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  if (param_1 != 1) {
    if (param_1 == 0) {
      local_4 = 0xf;
      local_8 = 0;
      local_18 = 0;
      FUN_00401740(s_btn_mp3note_009dc628,0xb);
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x24))(0);
      }
      if (0xf < local_8) {
        _free(local_1c);
        return;
      }
      local_8 = 0xf;
      uStack_c = 0;
      local_1c = (void *)((uint)local_1c & 0xffffff00);
      FUN_00401740(s_pan_mp3back_009dc634,0xb);
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x20);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x24))(1);
      }
      if (0xf < uStack_c) {
        _free(unaff_EBX);
        return;
      }
      uStack_c = 0xf;
      uStack_10 = 0;
      FUN_00401740(s_pan_mp3list_009dc640,0xb);
      local_4 = CONCAT31(local_4._1_3_,*(undefined1 *)(in_ECX + 8));
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x24);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x24))(local_8);
      }
      if (0xf < uStack_10) {
        _free(unaff_EBP);
        return;
      }
      uStack_10 = 0xf;
      uStack_14 = 0;
      FUN_00401740(s_pan_mp3back_009dc64c,0xb);
      FUN_0068c6a0((int)register0x00000010 + -0x28);
      if (0xf < uStack_10) {
        _free((void *)((uint)unaff_EBP & 0xffffff00));
        return;
      }
      *(undefined1 *)(in_ECX + 10) = 0;
      if (*(char *)(in_ECX + 8) != '\0') {
        FUN_00401830(s_pan_mp3list_009dc658);
        FUN_0068c430((int)register0x00000010 + -0x28);
        if (0xf < uStack_10) {
          _free((void *)((uint)unaff_EBP & 0xffffff00));
          return;
        }
      }
    }
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_mp3back_009dc5f8,0xb);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(0);
  }
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(s_pan_mp3list_009dc604,0xb);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x20);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(0);
  }
  if (0xf < uStack_c) {
    _free(unaff_EBX);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  FUN_00401740(s_btn_mp3note_009dc610,0xb);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x24);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(1);
  }
  if (0xf < uStack_10) {
    _free(unaff_EBP);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740(s_btn_mp3note_009dc61c,0xb);
  FUN_0068c6a0((int)register0x00000010 + -0x28);
  if (uStack_10 < 0x10) {
    *(undefined1 *)(in_ECX + 10) = 1;
    return;
  }
  _free((void *)((uint)unaff_EBP & 0xffffff00));
  return;
}


// ==== FUN_0068c9f0 @ 0x0068c9f0 ====

void FUN_0068c9f0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  void *local_5c;
  void *local_58 [4];
  uint uStack_48;
  uint uStack_44;
  undefined1 auStack_28 [28];
  int iStack_c;
  
  if (((*(int *)(in_ECX + 0x10) == -1) || (*(int *)(in_ECX + 0x24) == 0)) ||
     (local_5c = (void *)(*(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24) >> 5),
     local_5c == (void *)0x0)) {
    return;
  }
  if (*(int *)(in_ECX + 0x40) != 2) {
    *(undefined4 *)(in_ECX + 0x40) = 1;
    FUN_00401830(s_btn_mp3pause_009dc680);
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_58);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x24))(1);
    }
    if (0xf < uStack_44) {
      _free(local_58[0]);
      return;
    }
    FUN_00401830(s_btn_mp3play_009dc690);
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_5c);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x24))(0);
    }
    if (0xf < uStack_48) {
      _free(local_5c);
      return;
    }
    iVar3 = *(int *)(in_ECX + 0x24);
    if ((iVar3 == 0) || ((uint)(*(int *)(in_ECX + 0x28) - iVar3 >> 5) <= *(uint *)(in_ECX + 0x10)))
    {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    FUN_0068e600(*(uint *)(in_ECX + 0x10) * 0x20 + iVar3);
    if (iStack_c < 1) {
      FUN_0068cce0();
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    iVar3 = (**(code **)(*DAT_00b5a6a8 + 4))();
    if (iVar3 == 0) {
      uVar4 = 0;
    }
    else {
      FUN_00765c50(in_ECX + 0x48);
      FUN_00765c50(auStack_28);
      uVar4 = FUN_004ddfa0(3,*(undefined4 *)(in_ECX + 0xc));
    }
    FUN_00797a20(uVar4);
    FUN_00401830(s_lbl_mp3file_title_009dc69c);
    (**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_58 + -2);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  FUN_00401830(s_btn_mp3pause_009dc664);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_58);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(1);
  }
  if (0xf < uStack_44) {
    _free(local_58[0]);
    return;
  }
  FUN_00401830(s_btn_mp3play_009dc674);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_5c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(0);
  }
  if (0xf < uStack_48) {
    _free(local_5c);
    return;
  }
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar2 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar2 = &PTR_FUN_009dc718;
  FUN_00797a20(puVar2);
  return;
}


// ==== FUN_0068cce0 @ 0x0068cce0 ====

void FUN_0068cce0(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x44) == 1) {
    FUN_0068c9f0();
    return;
  }
  *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + 1;
  if (*(int *)(in_ECX + 0x24) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24) >> 5;
  }
  if ((((*(int *)(in_ECX + 0x10) < iVar1) ||
       (*(undefined4 *)(in_ECX + 0x10) = 0, *(int *)(in_ECX + 0x44) != 0)) &&
      (*(int *)(in_ECX + 0x24) != 0)) &&
     ((*(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24) >> 5 != 0 && (*(int *)(in_ECX + 0x40) == 1)
      ))) {
    FUN_0068c9f0();
    return;
  }
  return;
}


// ==== FUN_0068cd50 @ 0x0068cd50 ====

uint FUN_0068cd50(void)

{
  code *pcVar1;
  int *piVar2;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint uVar3;
  undefined4 uVar4;
  undefined4 ****ppppuVar5;
  int iVar6;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  uint extraout_EAX_03;
  uint extraout_EAX_04;
  uint extraout_EAX_05;
  uint extraout_EAX_06;
  int in_ECX;
  int iVar7;
  uint uVar8;
  undefined1 auStack_5c [4];
  void *local_58;
  undefined1 local_54;
  undefined4 uStack_48;
  uint local_44;
  undefined4 local_40;
  undefined4 ****appppuStack_3c [4];
  undefined4 uStack_2c;
  uint uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  
  local_40 = 0xf;
  local_44 = 0;
  local_54 = 0;
  FUN_00401740(s_list_mp3list_009dc6d4,0xc);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_58);
  if (0xf < local_44) {
    _free(local_58);
    return extraout_EAX;
  }
  local_44 = 0xf;
  uStack_48 = 0;
  uVar3 = (uint)local_58 >> 8;
  local_58 = (void *)(uVar3 << 8);
  if (piVar2 == (int *)0x0) {
    local_44 = 0xf;
    uStack_48 = 0;
    local_58 = (void *)(uVar3 << 8);
    FUN_00401740(s_FALSE_009dc6e4,5);
    FUN_00406880(auStack_5c);
    if (local_44 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    _free(local_58);
    return extraout_EAX_00;
  }
  (**(code **)(*piVar2 + 0x30))();
  if ((*(int *)(in_ECX + 0x24) == 0) ||
     (*(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24) >> 5 == 0)) {
    return 0xffffffff;
  }
  uVar4 = FUN_00575790();
  uStack_28 = 0xf;
  uStack_2c = 0;
  appppuStack_3c[0] = (undefined4 ****)((uint)appppuStack_3c[0] & 0xffffff00);
  FUN_00401660(uVar4,0,0xffffffff);
  if (*(int *)(in_ECX + 0x24) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24) >> 5;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  if (uVar3 != 0) {
    iVar7 = 0;
    uVar8 = 0;
    do {
      iVar6 = *(int *)(in_ECX + 0x24);
      if ((iVar6 == 0) || ((uint)(*(int *)(in_ECX + 0x28) - iVar6 >> 5) <= uVar8)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      FUN_00401660(iVar6 + iVar7,0,0xffffffff);
      uStack_8 = *(undefined4 *)(iVar6 + iVar7 + 0x1c);
      local_44 = 0xf;
      uStack_48 = 0;
      local_58 = (void *)((uint)local_58 & 0xffffff00);
      FUN_00401660(auStack_24,0,0xffffffff);
      ppppuVar5 = appppuStack_3c[0];
      if (uStack_28 < 0x10) {
        ppppuVar5 = appppuStack_3c;
      }
      iVar6 = FUN_00403620(0,uStack_48,ppppuVar5,uStack_2c);
      if (iVar6 == 0) {
        if (0xf < local_44) {
          _free(local_58);
          return extraout_EAX_02;
        }
        local_44 = 0xf;
        uStack_48 = 0;
        local_58 = (void *)((uint)local_58._1_3_ << 8);
        if (0xf < uStack_c) {
          _free(pvStack_20);
          return extraout_EAX_03;
        }
        uStack_c = 0xf;
        uStack_10 = 0;
        pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
        if (uStack_28 < 0x10) {
          return uVar8;
        }
        _free(appppuStack_3c[0]);
        return extraout_EAX_04;
      }
      if (0xf < local_44) {
        _free(local_58);
        return extraout_EAX_01;
      }
      uVar8 = uVar8 + 1;
      iVar7 = iVar7 + 0x20;
      local_44 = 0xf;
      uStack_48 = 0;
      local_58 = (void *)((uint)local_58._1_3_ << 8);
    } while (uVar8 < uVar3);
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return extraout_EAX_05;
    }
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  if (uStack_28 < 0x10) {
    return 0;
  }
  _free(appppuStack_3c[0]);
  return extraout_EAX_06;
}


// ==== FUN_0068cfd0 @ 0x0068cfd0 ====

void FUN_0068cfd0(int param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  uint uVar3;
  void *unaff_EBX;
  undefined4 uStack_5c;
  void *local_58;
  undefined1 local_54;
  undefined4 uStack_50;
  uint uStack_4c;
  uint uStack_48;
  void *local_44;
  void *local_40;
  void *local_38;
  uint uStack_30;
  uint uStack_2c;
  void *local_28;
  uint local_24;
  undefined4 uStack_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_8;
  
  local_24 = 0xf;
  local_28 = (void *)0x0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  FUN_00401660(param_1 + 4,0,0xffffffff);
  *(char *)(in_ECX + 0xb) = *(char *)(in_ECX + 0xb) + '\x01';
  if (*(int *)(in_ECX + 0x24) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24) >> 5;
  }
  if (*(byte *)(in_ECX + 0xb) < uVar3) {
    FUN_0068cce0();
    if (0xf < local_24) {
      _free(local_38);
      return;
    }
  }
  else {
    local_40 = (void *)0xf;
    local_44 = (void *)0x0;
    local_54 = 0;
    FUN_00401740(s_btn_mp3pause_009dc39c,0xc);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_58);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
    if (0xf < local_44) {
      _free(local_58);
      return;
    }
    local_44 = (void *)0xf;
    uStack_48 = 0;
    local_58 = (void *)((uint)local_58 & 0xffffff00);
    FUN_00401740(s_btn_mp3play_009dc3ac,0xb);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_5c);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(1);
    }
    if (0xf < uStack_48) {
      _free(uStack_5c);
      return;
    }
    if ((*(int *)(in_ECX + 0x24) == 0) ||
       (*(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24) >> 5 == 0)) {
      if (0xf < uStack_2c) {
        _free(local_40);
        return;
      }
    }
    else {
      uStack_48 = 0xf;
      uStack_4c = 0;
      uStack_5c = (void *)((uint)uStack_5c & 0xffffff00);
      FUN_00401740(s_list_mp3list_009dc3b8,0xc);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x60);
      if (0xf < uStack_4c) {
        _free(unaff_EBX);
        return;
      }
      uStack_4c = 0xf;
      uStack_50 = 0;
      uStack_8 = (**(code **)(*piVar2 + 0x30))();
      iVar1 = *(int *)(in_ECX + 0x24);
      if ((iVar1 == 0) || (*(int *)(in_ECX + 0x28) - iVar1 >> 5 == 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      uStack_14 = 0xf;
      uStack_18 = 0;
      local_28 = (void *)((uint)local_28 & 0xffffff00);
      FUN_00401660(iVar1,0,0xffffffff);
      uStack_10 = *(undefined4 *)(iVar1 + 0x1c);
      FUN_00401660(&uStack_2c,0,0xffffffff);
      FUN_00575700();
      FUN_0068c4b0(0);
      if (0xf < uStack_14) {
        _free(local_28);
        return;
      }
      uStack_14 = 0xf;
      uStack_18 = 0;
      local_28 = (void *)((uint)local_28 & 0xffffff00);
      if (0xf < uStack_30) {
        _free(local_44);
        return;
      }
    }
  }
  return;
}


// ==== FUN_0068d230 @ 0x0068d230 ====

undefined4 FUN_0068d230(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int in_ECX;
  float10 fVar6;
  float fVar7;
  undefined1 local_3c [60];
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_mp3play_009dc3e0,0xb);
      if (iVar2 == 0) {
        *(undefined1 *)(in_ECX + 0xb) = 0;
        uVar3 = FUN_0068cd50();
        *(undefined4 *)(in_ECX + 0x10) = uVar3;
        FUN_0068c9f0();
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_mp3pause_009dc3ec);
      if (cVar1 != '\0') {
        *(undefined4 *)(in_ECX + 0x40) = 2;
        FUN_00401830(s_btn_mp3pause_009dc3fc);
        piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_3c);
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 0x24))(0);
        }
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar1 = FUN_004036a0(param_2,s_btn_mp3stop_009dc418);
      if (cVar1 != '\0') {
        if (*(int *)(in_ECX + 0x10) != -1) {
          *(undefined4 *)(in_ECX + 0x40) = 0;
          FUN_00401830(s_btn_mp3pause_009dc424);
          FUN_0068c340(local_3c,0);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_mp3prev_009dc440);
      if (cVar1 == '\0') {
        cVar1 = FUN_004036a0(param_2,s_btn_mp3next_009dc44c);
        if (cVar1 != '\0') {
          FUN_0068cce0();
          return 1;
        }
        cVar1 = FUN_004036a0(param_2,s_btn_mp3list_009dc458);
        if (cVar1 != '\0') {
          *(bool *)(in_ECX + 8) = *(char *)(in_ECX + 8) == '\0';
          FUN_00401830(s_pan_mp3list_009dc464);
          FUN_0068c340(local_3c,*(undefined1 *)(in_ECX + 8));
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar1 = FUN_004036a0(param_2,s_btn_listclose_009dc480);
        if (cVar1 != '\0') {
          *(undefined1 *)(in_ECX + 8) = 0;
          FUN_00401830(s_pan_mp3list_009dc490);
          FUN_0068c340(local_3c,*(undefined1 *)(in_ECX + 8));
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar1 = FUN_004036a0(param_2,s_btn_playtype1_009dc49c);
        if (cVar1 != '\0') {
          *(undefined4 *)(in_ECX + 0x44) = 1;
          FUN_00401830(s_btn_playtype1_009dc4ac);
          FUN_0068c340(local_3c,0);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar1 = FUN_004036a0(param_2,s_btn_playtype2_009dc4cc);
        if (cVar1 != '\0') {
          *(undefined4 *)(in_ECX + 0x44) = 0;
          FUN_00401830(s_btn_playtype2_009dc4dc);
          FUN_0068c340(local_3c,0);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar1 = FUN_004036a0(param_2,s_btn_playtype3_009dc4fc);
        if (cVar1 != '\0') {
          *(undefined4 *)(in_ECX + 0x44) = 2;
          FUN_00401830(s_btn_playtype1_009dc50c);
          FUN_0068c340(local_3c,1);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar1 = FUN_004036a0(param_2,s_btn_mp3close_009dc52c);
        if (cVar1 != '\0') {
          puVar5 = operator_new(4);
          if (puVar5 == (undefined4 *)0x0) {
            FUN_00797a20(0);
            *(undefined1 *)(in_ECX + 9) = 0;
            return 1;
          }
          *puVar5 = &PTR_FUN_009b45dc;
          FUN_00797a20(puVar5);
          *(undefined1 *)(in_ECX + 9) = 0;
          return 1;
        }
        cVar1 = FUN_004036a0(param_2,s_btn_mp3min_009dc53c);
        if (cVar1 != '\0') {
          FUN_00401830(s_pan_mp3back_009dc548);
          FUN_0068c340(local_3c,0);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar1 = FUN_004036a0(param_2,s_btn_mp3note_009dc578);
        if (cVar1 != '\0') {
          FUN_00401830(s_btn_mp3note_009dc584);
          FUN_0068c340(local_3c,0);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
      }
      else {
        piVar4 = (int *)(in_ECX + 0x10);
        *piVar4 = *piVar4 + -1;
        if (*piVar4 < 0) {
          *(undefined4 *)(in_ECX + 0x10) = 0;
        }
        if (*(int *)(in_ECX + 0x40) == 1) {
          FUN_0068c9f0();
          return 1;
        }
      }
      return 1;
    }
  }
  else if (param_1 == 0x14) {
    if (param_3 == 7) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_sld_volume_009dc5c0,10);
      if (iVar2 == 0) {
        fVar6 = (float10)FUN_0068c3a0(param_2);
        *(float *)(in_ECX + 0x14) = (float)fVar6;
        puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          fVar7 = *(float *)(in_ECX + 0x14) * DAT_009a09b8;
          *puVar5 = &PTR_FUN_009dc704;
          puVar5[1] = fVar7;
          puVar5[2] = 0;
          puVar5[3] = 3;
        }
        FUN_00797a20(puVar5);
        FUN_00401830(s_probar_volume_009dc5cc);
        piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_3c);
        (**(code **)(*piVar4 + 0x30))();
        FUN_00587ba0(param_2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar1 = FUN_004036a0(param_2,s_sld_play_009dc5dc);
      if (cVar1 != '\0') {
        FUN_0068c370(param_2);
        return 1;
      }
    }
  }
  else if ((param_1 == 0x16) && (param_3 == 1)) {
    cVar1 = FUN_004036a0(param_2,s_list_mp3list_009dc5e8);
    if (cVar1 == '\0') {
      return 1;
    }
    if (*(int *)(in_ECX + 0x10) == -1) {
      return 1;
    }
    *(undefined4 *)(in_ECX + 0x40) = 1;
    uVar3 = FUN_0068cd50();
    *(undefined4 *)(in_ECX + 0x10) = uVar3;
    FUN_0068c9f0();
    return 1;
  }
  return 0;
}


// ==== FUN_0068d9d0 @ 0x0068d9d0 ====

undefined4 FUN_0068d9d0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0xb0011) {
    cVar1 = FUN_0068c5b0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else {
    if (iVar2 == 0xb0012) {
      FUN_0068c4b0(param_1[2]);
      return 0;
    }
    if (iVar2 == 0xb0013) {
      FUN_0068cfd0(param_1);
    }
  }
  return 0;
}


// ==== FUN_0068da30 @ 0x0068da30 ====

void FUN_0068da30(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *in_ECX;
  int iVar5;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 *puVar6;
  
  *in_ECX = &PTR_FUN_009dc72c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if (in_ECX[9] != 0) {
    FUN_0068e630(in_ECX[9],in_ECX[10],in_ECX + 8,unaff_EBX);
    _free((void *)in_ECX[9]);
    return;
  }
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
  uVar1 = *(undefined1 *)((int)in_ECX + 9);
  puVar6 = in_ECX + 0x19;
  for (iVar5 = 0x19; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar6 = puVar6 + 1;
  }
  in_ECX[0x28] = in_ECX[5];
  *(undefined1 *)(in_ECX + 0x29) = uVar1;
  *(undefined1 *)((int)in_ECX + 0xc1) = *(undefined1 *)(in_ECX + 0x11);
  (**(code **)(*DAT_00b5a6e4 + 0x10))(in_ECX + 0x19);
  (**(code **)(*DAT_00b5a6e4 + 0x14))();
  iVar5 = (**(code **)(*DAT_00b5a6a8 + 4))();
  if (iVar5 == 0) {
    uVar4 = 0;
  }
  else {
    FUN_00401660(in_ECX + 0x12,0,0xffffffff);
    FUN_00401740(&DAT_009dc282,0);
    uVar4 = FUN_004de080(3);
  }
  FUN_00797a20(uVar4);
  if (DAT_00b5ae14 != (int *)0x0) {
    uVar2 = (**(code **)(*DAT_00b5ae14 + 0x18))();
    FUN_004de2a0(0,uVar2);
  }
  if (0xf < (uint)in_ECX[0x18]) {
    _free((void *)in_ECX[0x13]);
    return;
  }
  in_ECX[0x18] = 0xf;
  in_ECX[0x17] = 0;
  *(undefined1 *)(in_ECX + 0x13) = 0;
  if (in_ECX[0xd] != 0) {
    FUN_00405de0(in_ECX[0xd],in_ECX[0xe],in_ECX + 0xc,unaff_EBP);
    _free((void *)in_ECX[0xd]);
    return;
  }
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  if (in_ECX[9] == 0) {
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    in_ECX[0xb] = 0;
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  FUN_0068e630(in_ECX[9],in_ECX[10],in_ECX + 8,unaff_EBP);
  _free((void *)in_ECX[9]);
  return;
}


// ==== FUN_0068dbe0 @ 0x0068dbe0 ====

void FUN_0068dbe0(LPCSTR param_1)

{
  char cVar1;
  HANDLE hFindFile;
  int iVar2;
  CHAR *pCVar3;
  undefined4 uVar4;
  BOOL BVar5;
  int *piVar6;
  int in_ECX;
  int iVar7;
  bool bVar8;
  void *pvStack_164;
  void *pvStack_160;
  undefined4 uStack_154;
  uint uStack_150;
  uint uStack_14c;
  undefined4 uStack_148;
  int local_144;
  _WIN32_FIND_DATAA local_140;
  
  bVar8 = true;
  hFindFile = FindFirstFileA(param_1,&local_140);
  if (*(int *)(in_ECX + 0x24) != 0) {
    FUN_0068e630(*(int *)(in_ECX + 0x24),*(undefined4 *)(in_ECX + 0x28),in_ECX + 0x20,hFindFile);
    _free(*(void **)(in_ECX + 0x24));
    return;
  }
  iVar7 = in_ECX + 0x30;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  local_144 = iVar7;
  if (*(int *)(in_ECX + 0x34) != 0) {
    FUN_00405de0(*(int *)(in_ECX + 0x34),*(undefined4 *)(in_ECX + 0x38),iVar7,hFindFile);
    _free(*(void **)(in_ECX + 0x34));
    return;
  }
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  if (hFindFile != (HANDLE)0xffffffff) {
    while (bVar8) {
      if (((byte)local_140.dwFileAttributes & 0x10) == 0) {
        iVar2 = (**(code **)(*DAT_00b5a6a8 + 4))();
        if (iVar2 == 0) {
          uVar4 = 0;
        }
        else {
          pCVar3 = local_140.cFileName;
          do {
            cVar1 = *pCVar3;
            pCVar3 = pCVar3 + 1;
          } while (cVar1 != '\0');
          FUN_00401740(local_140.cFileName,(int)pCVar3 - (int)(local_140.cFileName + 1));
          FUN_00401660(in_ECX + 0x48,0,0xffffffff);
          uVar4 = FUN_004de150(3);
          iVar7 = local_144;
        }
        FUN_00797a20(uVar4);
        pCVar3 = local_140.cFileName;
        uStack_14c = 0xf;
        uStack_150 = 0;
        pvStack_160 = (void *)((uint)pvStack_160 & 0xffffff00);
        uStack_148 = 0;
        do {
          cVar1 = *pCVar3;
          pCVar3 = pCVar3 + 1;
        } while (cVar1 != '\0');
        FUN_00401740(local_140.cFileName,(int)pCVar3 - (int)(local_140.cFileName + 1));
        iVar2 = *(int *)(in_ECX + 0x24);
        if ((iVar2 == 0) ||
           ((uint)(*(int *)(in_ECX + 0x2c) - iVar2 >> 5) <=
            (uint)(*(int *)(in_ECX + 0x28) - iVar2 >> 5))) {
          FUN_0068e870(*(undefined4 *)(in_ECX + 0x28),1,&pvStack_164);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x28);
          FUN_0068e770(iVar2,1,&pvStack_164,in_ECX + 0x20,hFindFile);
          *(int *)(in_ECX + 0x28) = iVar2 + 0x20;
        }
        FUN_00406720(&pvStack_164);
        if (0xf < uStack_14c) {
          _free(pvStack_160);
          return;
        }
        uStack_14c = 0xf;
        uStack_150 = 0;
        pvStack_160 = (void *)((uint)pvStack_160 & 0xffffff00);
      }
      BVar5 = FindNextFileA(hFindFile,&local_140);
      bVar8 = BVar5 != 0;
    }
  }
  FindClose(hFindFile);
  uStack_14c = 0xf;
  uStack_150 = 0;
  pvStack_160 = (void *)((uint)pvStack_160 & 0xffffff00);
  FUN_00401740(s_list_mp3list_009dc38c,0xc);
  piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_164);
  if (uStack_150 < 0x10) {
    uStack_150 = 0xf;
    uStack_154 = 0;
    pvStack_164 = (void *)((uint)pvStack_164 & 0xffffff00);
    (**(code **)(*piVar6 + 0x30))();
    FUN_00576750(iVar7);
    return;
  }
  _free(pvStack_164);
  return;
}


// ==== FUN_0068de70 @ 0x0068de70 ====

/* WARNING: Removing unreachable block (ram,0x0068e25e) */
/* WARNING: Removing unreachable block (ram,0x0068e1fc) */
/* WARNING: Removing unreachable block (ram,0x0068e1a6) */
/* WARNING: Removing unreachable block (ram,0x0068e15d) */

void FUN_0068de70(void)

{
  code *pcVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  LPCSTR lpPathName;
  undefined4 ****ppppuVar6;
  undefined4 *puVar7;
  int in_ECX;
  uint unaff_ESI;
  undefined4 *puVar8;
  float fVar9;
  void *pvStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined1 auStack_136 [2];
  void *local_134;
  undefined4 uStack_12c;
  uint uStack_128;
  void *local_124;
  uint local_120;
  undefined4 uStack_114;
  uint uStack_110;
  undefined1 auStack_10c [4];
  undefined4 ****appppuStack_108 [5];
  uint uStack_f4;
  undefined1 auStack_f0 [4];
  void *pvStack_ec;
  void *apvStack_e8 [4];
  uint uStack_d8;
  uint uStack_d4;
  void *apvStack_c8 [4];
  undefined4 uStack_b8;
  uint uStack_b4;
  void *apvStack_b0 [4];
  undefined4 uStack_a0;
  uint uStack_9c;
  void *apvStack_90 [4];
  undefined4 uStack_80;
  void *pvStack_7c;
  uint uStack_68;
  undefined1 auStack_64 [4];
  undefined4 ****appppuStack_60 [5];
  uint uStack_4c;
  undefined4 ****appppuStack_44 [5];
  uint uStack_30;
  
  uStack_150 = s_UI_Game2_MP3Player_ui_mp3playerw_009dc284;
  local_120 = 0xf;
  local_124 = (void *)0x0;
  local_134 = (void *)((uint)local_134 & 0xffffff00);
  uStack_154 = 0x68de9f;
  FUN_00401740();
  uStack_150 = (char *)0x68dea9;
  pvVar2 = (void *)FUN_00410500();
  if (0xf < local_120) {
    uStack_150 = (char *)0x68debf;
    _free(local_134);
    return;
  }
  if (pvVar2 == (void *)0x0) {
    uStack_150 = s_FALSE_009dc2ac;
    local_120 = 0xf;
    local_124 = (void *)0x0;
    uStack_154 = 0x68dee2;
    FUN_00401740();
    uStack_150 = (char *)0x68deec;
    FUN_00406880();
    if (local_120 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uStack_150 = (char *)0x68df00;
    _free(local_134);
    return;
  }
  uStack_150 = (char *)((int)pvVar2 + 0x3c);
  uStack_154 = 0x68df1f;
  piVar3 = (int *)(**(code **)(*DAT_00b5a798 + 4))();
  *(int **)(in_ECX + 4) = piVar3;
  pvStack_158 = (void *)0x68df2a;
  (**(code **)(*piVar3 + 0x40))();
  pvStack_158 = pvVar2;
  (**(code **)(*DAT_00b5a7cc + 0x14))();
  *(undefined4 *)(in_ECX + 0xc) = 1;
  *(undefined4 *)(in_ECX + 0x10) = 0xffffffff;
  iVar4 = (**(code **)(*DAT_00b5a6a8 + 4))();
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    FUN_00401660(in_ECX + 0x48,0,0xffffffff);
    FUN_00401740(&DAT_009dc2b2,0);
    uVar5 = FUN_004de080(3);
  }
  FUN_00797a20(uVar5);
  uVar5 = FUN_00404890(auStack_f0);
  FUN_004045b0(auStack_64,uVar5);
  if (0xf < uStack_d8) {
    _free(pvStack_ec);
    return;
  }
  uVar5 = FUN_004046f0(auStack_f0,auStack_64,s_music__009dc2b4);
  uVar5 = FUN_00402220(&uStack_128,uVar5);
  FUN_00401660(uVar5,0,0xffffffff);
  if (0xf < uStack_110) {
    _free(local_124);
    return;
  }
  uStack_110 = 0xf;
  uStack_114 = 0;
  local_124 = (void *)((uint)local_124 & 0xffffff00);
  if (0xf < uStack_d8) {
    _free(pvStack_ec);
    return;
  }
  if (*(uint *)(in_ECX + 0x60) < 0x10) {
    lpPathName = (LPCSTR)(in_ECX + 0x4c);
  }
  else {
    lpPathName = *(LPCSTR *)(in_ECX + 0x4c);
  }
  CreateDirectoryA(lpPathName,(LPSECURITY_ATTRIBUTES)0x0);
  FUN_00402220(auStack_10c,in_ECX + 0x48,s___mp3_009dc2bc);
  if (*(int *)(in_ECX + 0x24) != 0) {
    FUN_0068e630(*(int *)(in_ECX + 0x24),*(undefined4 *)(in_ECX + 0x28),in_ECX + 0x20,uStack_12c);
    _free(*(void **)(in_ECX + 0x24));
    return;
  }
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  ppppuVar6 = appppuStack_108[0];
  if (uStack_f4 < 0x10) {
    ppppuVar6 = appppuStack_108;
  }
  FUN_0068dbe0(ppppuVar6);
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  puVar7 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
  puVar8 = (undefined4 *)(in_ECX + 100);
  for (iVar4 = 0x19; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0xa0);
  puVar7 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar7 == (undefined4 *)0x0) {
    puVar7 = (undefined4 *)0x0;
  }
  else {
    fVar9 = *(float *)(in_ECX + 0x14) * DAT_009a09b8;
    *puVar7 = &PTR_FUN_009dc704;
    puVar7[1] = fVar9;
    puVar7[2] = 0;
    puVar7[3] = 3;
  }
  FUN_00797a20(puVar7);
  *(undefined4 *)(in_ECX + 0x40) = 0;
  FUN_00401740(s_btn_mp3pause_009dc2c4,0xc);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_136 + -0x12);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x24))(0);
  }
  FUN_00401740(s_btn_mp3play_009dc2d4,0xb);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_136 + -0x16);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x24))(1);
  }
  FUN_00401740(s_probar_volume_009dc2e0,0xd);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_150);
  (**(code **)(*piVar3 + 0x30))();
  FUN_00587ba0(0xf);
  uStack_150 = (char *)((uint)uStack_150 & 0xffffff00);
  FUN_00401740(s_sld_volume_009dc2f0,10);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_154);
  if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
    FUN_00579b10(0xf);
  }
  *(undefined1 *)(in_ECX + 8) = 1;
  *(undefined1 *)(in_ECX + 9) = 1;
  if (*(char *)(in_ECX + 0xc1) == '\0') {
    *(undefined4 *)(in_ECX + 0x44) = 0;
    FUN_00401830(s_btn_playtype1_009dc2fc);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_90);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(0);
    }
    if ((void *)0xf < pvStack_7c) {
      _free(apvStack_90[0]);
      return;
    }
    pvStack_7c = (void *)0xf;
    uStack_80 = 0;
    apvStack_90[0] = (void *)((uint)apvStack_90[0] & 0xffffff00);
    FUN_00401830(s_btn_playtype2_009dc30c);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_136 + -6);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(0);
    }
    if (0xf < uStack_128) {
      _free((void *)0xf);
      return;
    }
    uStack_128 = 0xf;
    FUN_00401830(s_btn_playtype3_009dc31c);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(appppuStack_108);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(1);
    }
    if (uStack_f4 < 0x10) goto LAB_0068e560;
    appppuStack_44[0] = appppuStack_108[0];
  }
  else if (*(char *)(in_ECX + 0xc1) == '\x01') {
    *(undefined4 *)(in_ECX + 0x44) = 1;
    FUN_00401830(s_btn_playtype1_009dc32c);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_c8);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(0);
    }
    if (0xf < uStack_b4) {
      _free(apvStack_c8[0]);
      return;
    }
    uStack_b4 = 0xf;
    uStack_b8 = 0;
    apvStack_c8[0] = (void *)((uint)apvStack_c8[0] & 0xffffff00);
    FUN_00401830(s_btn_playtype2_009dc33c);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_e8);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(1);
    }
    if (0xf < uStack_d4) {
      _free(apvStack_e8[0]);
      return;
    }
    uStack_d4 = 0xf;
    uStack_d8 = 0;
    apvStack_e8[0] = (void *)((uint)apvStack_e8[0] & 0xffffff00);
    FUN_00401830(s_btn_playtype3_009dc34c);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(appppuStack_60);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(0);
    }
    if (uStack_4c < 0x10) goto LAB_0068e560;
    appppuStack_44[0] = appppuStack_60[0];
  }
  else {
    *(undefined4 *)(in_ECX + 0x44) = 2;
    FUN_00401830(s_btn_playtype1_009dc35c);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_158);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(1);
    }
    if (0xf < (unaff_ESI & 0xffffff00)) {
      _free(pvStack_158);
      return;
    }
    pvStack_158 = (void *)((uint)pvStack_158 & 0xffffff00);
    FUN_00401830(s_btn_playtype2_009dc36c);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_b0);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(0);
    }
    if (0xf < uStack_9c) {
      _free(apvStack_b0[0]);
      return;
    }
    uStack_9c = 0xf;
    uStack_a0 = 0;
    apvStack_b0[0] = (void *)((uint)apvStack_b0[0] & 0xffffff00);
    FUN_00401830(s_btn_playtype3_009dc37c);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(appppuStack_44);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(0);
    }
    if (uStack_30 < 0x10) {
LAB_0068e560:
      FUN_0068c4b0(0);
      *(undefined1 *)(in_ECX + 0xb) = 0;
      if (0xf < uStack_110) {
        _free(local_124);
        return;
      }
      uStack_110 = 0xf;
      uStack_114 = 0;
      local_124 = (void *)((uint)local_124 & 0xffffff00);
      if (uStack_68 < 0x10) {
        return;
      }
      _free(pvStack_7c);
      return;
    }
  }
  _free(appppuStack_44[0]);
  return;
}


// ==== FUN_0068e5b0 @ 0x0068e5b0 ====

void FUN_0068e5b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dc72c;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x18] = 0xf;
  in_ECX[0x17] = 0;
  *(undefined1 *)(in_ECX + 0x13) = 0;
  FUN_0068de70();
  return;
}


// ==== FUN_0068e5f0 @ 0x0068e5f0 ====

undefined4 FUN_0068e5f0(void)

{
  return 0xb0006;
}


// ==== FUN_0068e600 @ 0x0068e600 ====

void FUN_0068e600(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  return;
}


// ==== FUN_0068e630 @ 0x0068e630 ====

void FUN_0068e630(int param_1,int param_2)

{
  while( true ) {
    if (param_1 == param_2) {
      return;
    }
    if (0xf < *(uint *)(param_1 + 0x18)) break;
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    param_1 = param_1 + 0x20;
  }
  _free(*(void **)(param_1 + 4));
  return;
}


// ==== FUN_0068e670 @ 0x0068e670 ====

int FUN_0068e670(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x20;
    iVar2 = param_3 + -0x20;
    FUN_00401660(iVar1,0,0xffffffff);
    *(undefined4 *)(param_3 + -4) = *(undefined4 *)(param_2 + -4);
    param_2 = iVar1;
    param_3 = iVar2;
  } while (iVar1 != param_1);
  return iVar2;
}


// ==== FUN_0068e6b0 @ 0x0068e6b0 ====

int FUN_0068e6b0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c6d0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x20) {
    FUN_00843820(param_3,param_1);
    param_3 = param_3 + 0x20;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0068e71a @ 0x0068e71a ====

void Catch_0068e71a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x20) {
    FUN_00405c70(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0068e770 @ 0x0068e770 ====

void FUN_0068e770(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c6e0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_00843820(param_1,param_3);
    param_1 = param_1 + 0x20;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0068e7da @ 0x0068e7da ====

void Catch_0068e7da(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x20) {
    FUN_00405c70(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0068e800 @ 0x0068e800 ====

void FUN_0068e800(undefined4 param_1,undefined4 param_2)

{
  FUN_0068e630(param_1,param_2);
  return;
}


// ==== FUN_0068e820 @ 0x0068e820 ====

void FUN_0068e820(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0068e6b0(param_1,param_2,param_3);
  return;
}


// ==== FUN_0068e840 @ 0x0068e840 ====

int FUN_0068e840(int param_1,int param_2,undefined4 param_3)

{
  FUN_0068e770(param_1,param_2,param_3);
  return param_2 * 0x20 + param_1;
}


// ==== FUN_0068e870 @ 0x0068e870 ====

void FUN_0068e870(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int extraout_ECX;
  int iVar5;
  undefined1 local_5c [2];
  undefined1 auStack_5a [2];
  void *local_58;
  undefined4 local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_2c;
  void *local_28;
  uint local_24;
  int local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c6f0;
  local_10 = ExceptionList;
  local_14 = local_5c + -0xc;
  local_44 = 0xf;
  local_48 = 0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3,0,0xffffffff);
  local_40 = *(undefined4 *)(param_3 + 0x1c);
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 0xc) - iVar2 >> 5;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 8) - iVar2 >> 5;
    }
    if (0x7ffffffU - iVar5 < param_2) {
      uVar1 = FUN_0085b3b0();
      iVar2 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 8) - iVar2 >> 5;
    }
    if (uVar1 < iVar5 + param_2) {
      if (0x7ffffff - (uVar1 >> 1) < uVar1) {
        local_24 = 0;
      }
      else {
        local_24 = uVar1 + (uVar1 >> 1);
      }
      if (iVar2 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - iVar2 >> 5;
      }
      if (local_24 < iVar5 + param_2) {
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 5;
        }
        local_24 = iVar2 + param_2;
      }
      local_24 = local_24 << 5;
      pvVar3 = operator_new(local_24);
      local_8 = 0;
      local_28 = pvVar3;
      local_18 = pvVar3;
      local_18 = (void *)FUN_0068e820(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      local_18 = (void *)FUN_0068e840(local_18,param_2,local_5c);
      FUN_0068e820(param_1,*(undefined4 *)(in_ECX + 8),local_18);
      local_8 = 0xffffffff;
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - iVar2 >> 5;
      }
      if (iVar2 != 0) {
        FUN_0068e630(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(uint *)(in_ECX + 0xc) = local_24 + (int)pvVar3;
      *(void **)(in_ECX + 8) = (void *)((param_2 + iVar5) * 0x20 + (int)pvVar3);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      local_2c = *(int *)(in_ECX + 8);
      if ((uint)(local_2c - param_1 >> 5) < param_2) {
        local_1c = param_2 * 0x20;
        FUN_0068e6b0(param_1,local_2c,local_1c + param_1);
        local_8 = 2;
        FUN_0068e840(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 5),local_5c);
        local_8 = 0xffffffff;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_1c;
        FUN_00793c20(param_1,*(int *)(in_ECX + 8) - local_1c,local_5c);
      }
      else {
        local_1c = param_2 * 0x20;
        iVar2 = local_2c + param_2 * -0x20;
        uVar4 = FUN_0068e6b0(iVar2,local_2c,local_2c);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_0068e670(param_1,iVar2,local_2c,local_3c);
        FUN_00793c20(param_1,local_1c + param_1,local_5c);
      }
    }
  }
  if (local_44 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_58);
  return;
}


// ==== Catch@0068e9f5 @ 0x0068e9f5 ====

void Catch_0068e9f5(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x24);
  FUN_0068e800(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@0068ea87 @ 0x0068ea87 ====

void Catch_0068ea87(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x20;
  FUN_0068e800(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x1c) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0068eb10 @ 0x0068eb10 ====

undefined4 FUN_0068eb10(void)

{
  return 0x57;
}


// ==== FUN_0068eb20 @ 0x0068eb20 ====

bool FUN_0068eb20(void)

{
  int in_ECX;
  
  return *(char *)(in_ECX + 10) != '\0';
}


// ==== FUN_0068eb30 @ 0x0068eb30 ====

void FUN_0068eb30(byte param_1)

{
  void *in_ECX;
  
  FUN_0068da30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0068eb50 @ 0x0068eb50 ====

void FUN_0068eb50(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0068eb5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_0068eb60 @ 0x0068eb60 ====

undefined1 FUN_0068eb60(void)

{
  return 0;
}


// ==== FUN_0068eb70 @ 0x0068eb70 ====

undefined1 FUN_0068eb70(void)

{
  return 0;
}


// ==== FUN_0068ebb0 @ 0x0068ebb0 ====

void FUN_0068ebb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dc924;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0068ebd0 @ 0x0068ebd0 ====

void FUN_0068ebd0(int param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  if (*(char *)(DAT_00b5b140 + 8) != '\0') {
    if ((*(char *)(DAT_00b5b140 + 9) == '\x01') && (*(int *)(DAT_00b5b140 + 0x20) == 0)) {
      iVar2 = *(int *)(in_ECX + 0xc);
      iVar1 = *(int *)(in_ECX + 8);
      switch(*(uint *)(param_1 + 0xc) / 0x32 & 3) {
      case 0:
        (**(code **)(**(int **)(in_ECX + 4) + 0x54))(iVar1 + -3,iVar2,1);
        return;
      case 1:
        (**(code **)(**(int **)(in_ECX + 4) + 0x54))(iVar1 + 3,iVar2,1);
        return;
      case 2:
        (**(code **)(**(int **)(in_ECX + 4) + 0x54))(iVar1,iVar2 + -3,1);
        return;
      case 3:
        iVar2 = iVar2 + 3;
      }
      (**(code **)(**(int **)(in_ECX + 4) + 0x54))(iVar1,iVar2,1);
      return;
    }
    (**(code **)(**(int **)(in_ECX + 4) + 0x54))
              (*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),1);
  }
  return;
}


// ==== FUN_0068ec90 @ 0x0068ec90 ====

void FUN_0068ec90(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(param_1);
  }
  return;
}


// ==== FUN_0068ee50 @ 0x0068ee50 ====

void FUN_0068ee50(void)

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
  FUN_00401740(s_pan_fighting_009dc7bc,0xc);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      uVar3 = (**(code **)(*piVar1 + 4))();
      *puVar2 = &PTR_FUN_009bba08;
      puVar2[1] = uVar3;
      puVar2[3] = 1;
      puVar2[5] = 0;
      *(undefined1 *)(puVar2 + 6) = 0;
    }
    *(undefined1 *)((int)puVar2 + 0x19) = 1;
    puVar2[2] = 0x807d3;
    puVar2[3] = 1;
    puVar2[4] = 500;
    *(undefined1 *)(puVar2 + 6) = 1;
    (**(code **)(*DAT_00b5ad24 + 4))(puVar2);
    (**(code **)*puVar2)(1);
  }
  return;
}


// ==== FUN_0068ef20 @ 0x0068ef20 ====

void FUN_0068ef20(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 unaff_EBX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_fighting_eff_009dc7cc,0x10);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      uVar3 = (**(code **)(*piVar1 + 4))();
      *puVar2 = &PTR_FUN_009bba08;
      puVar2[1] = uVar3;
      puVar2[3] = 1;
      puVar2[5] = 0;
      *(undefined1 *)(puVar2 + 6) = 0;
    }
    *(undefined1 *)((int)puVar2 + 0x19) = 1;
    puVar2[2] = unaff_EBX;
    puVar2[3] = 1;
    puVar2[4] = 1000;
    *(undefined1 *)(puVar2 + 6) = 1;
    (**(code **)(*DAT_00b5ad24 + 4))(puVar2);
    (**(code **)*puVar2)(1);
  }
  return;
}


// ==== FUN_0068f010 @ 0x0068f010 ====

void FUN_0068f010(void)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  undefined1 auStack_26 [10];
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_fish_rank_009dc908,0xd);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (piVar1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
  }
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (iVar2 != 0) {
    FUN_006eeb60();
    FUN_00587d40(auStack_26 + -6);
  }
  return;
}


// ==== FUN_0068f190 @ 0x0068f190 ====

/* WARNING: Removing unreachable block (ram,0x0068f1d2) */

void FUN_0068f190(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined1 auStack_38 [4];
  
  FUN_00401740(s_UI_Game2_Fishing_ui_fishingwnd_t_009dc798);
  iVar1 = FUN_00410500();
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  puVar3 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x5c))(auStack_38 + 8);
  *(undefined4 *)(in_ECX + 8) = *puVar3;
  *(undefined4 *)(in_ECX + 0xc) = puVar3[1];
  return;
}


// ==== FUN_0068f220 @ 0x0068f220 ====

void FUN_0068f220(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 auStack_38 [8];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 auStack_1c [28];
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar1 != 0) && (piVar2 = *(int **)(iVar1 + 0x84), piVar2 != (int *)0x0)) {
    iVar1 = (**(code **)(*DAT_00b5aeec + 8))();
    if (iVar1 == 1) {
      piVar2 = (int *)(**(code **)(*piVar2 + 0x30))();
      if (piVar2 != (int *)0x0) {
        iVar1 = (**(code **)(*piVar2 + 0xc))();
        uStack_30 = *(undefined4 *)(iVar1 + 8);
        uStack_2c = *(undefined4 *)(iVar1 + 0xc);
        uStack_28 = *(undefined4 *)(iVar1 + 0x10);
        FUN_00401830(s_pan_fighting_009dc7e0);
        piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_38);
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 0x24))(0);
        }
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    else {
      iVar1 = (**(code **)(*DAT_00b5aeec + 8))();
      if (iVar1 == 2) {
        piVar2 = (int *)(**(code **)(*piVar2 + 0x18))();
        iVar1 = (**(code **)(*piVar2 + 8))();
        uStack_2c = *(undefined4 *)(iVar1 + 0xc);
        uStack_28 = *(undefined4 *)(iVar1 + 0x10);
        FUN_00401830(s_pan_fighting_009dc84c);
        piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1c);
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 0x24))(1);
        }
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      iVar1 = (**(code **)(*DAT_00b5aeec + 8))();
      if (iVar1 == 0) {
        FUN_00401830(s_pan_fighting_009dc8ec);
        FUN_0068ec90(auStack_1c,0);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
  }
  return;
}


// ==== FUN_0068f6a0 @ 0x0068f6a0 ====

void FUN_0068f6a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dc924;
  FUN_0068f190();
  return;
}


// ==== FUN_0068f6c0 @ 0x0068f6c0 ====

undefined4 FUN_0068f6c0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 < 0x70390004) {
    if (uVar1 == 0x70390003) {
      FUN_0068ee50();
      return 1;
    }
    if (uVar1 == 0x40001) {
      FUN_0068ebd0(param_1);
      return 0;
    }
    if (uVar1 == 0x70390002) {
      FUN_0068f220();
      return 1;
    }
  }
  else {
    if (uVar1 == 0x70390004) {
      FUN_0068ef20((char)param_1[1]);
      return 1;
    }
    if (uVar1 == 0x70390005) {
      FUN_0068f010();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0068f750 @ 0x0068f750 ====

undefined4 FUN_0068f750(void)

{
  return 0x54;
}


// ==== FUN_0068f760 @ 0x0068f760 ====

void FUN_0068f760(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009dc924;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0068f7a0 @ 0x0068f7a0 ====

void FUN_0068f7a0(void)

{
  return;
}


// ==== FUN_0068f850 @ 0x0068f850 ====

undefined1 FUN_0068f850(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined2 *puVar7;
  
  uVar5 = 0;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar2 = (**(code **)(*param_1 + 0x14))();
  cVar1 = *(char *)(iVar2 + 0x1e);
  uVar4 = CONCAT31((int3)((uint)iVar2 >> 8),cVar1);
  if (cVar1 != '\0') {
    uVar6 = 0;
    uVar5 = 0;
    if (cVar1 != '\0') {
      puVar7 = (undefined2 *)(iVar2 + 4);
      while (iVar3 = (**(code **)(*DAT_00b5ad20 + 0xc))(CONCAT22((short)(uVar4 >> 0x10),*puVar7)),
            iVar3 == 0) {
        uVar4 = (uint)*(byte *)(iVar2 + 0x1e);
        uVar6 = uVar6 + 1;
        puVar7 = puVar7 + 1;
        if (uVar4 <= uVar6) {
          return 0;
        }
      }
      uVar5 = 1;
    }
  }
  return uVar5;
}


// ==== FUN_0068f8c0 @ 0x0068f8c0 ====

undefined4 FUN_0068f8c0(void)

{
  (**(code **)(*DAT_00b5b0e4 + 0x10))();
  return 1;
}


// ==== FUN_0068f8d0 @ 0x0068f8d0 ====

undefined4 FUN_0068f8d0(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  iVar3 = (**(code **)(*piVar2 + 0x30))();
  if (iVar3 != 0) {
    if (param_1 != 4) {
      return 0;
    }
    iVar3 = (**(code **)(*DAT_00b5a78c + 0x48))();
    if ((iVar3 == 0) && (iVar3 = FUN_0057f270(), iVar3 == 0)) {
      return 1;
    }
    cVar1 = (**(code **)(*DAT_00b5ad20 + 0x34))(iVar3);
    if (cVar1 != '\0') {
      FUN_0057f390(0x40000060);
      return 1;
    }
    FUN_0057f390(0x60b00000);
  }
  return 1;
}


// ==== FUN_0068f950 @ 0x0068f950 ====

void FUN_0068f950(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(*DAT_00b5a78c + 0x1c))
            (CONCAT13((char)((uint)(in_ECX + 0x88) >> 0x18),*(undefined3 *)(in_ECX + 0x88)),param_1)
  ;
  return;
}


// ==== FUN_0068f9d0 @ 0x0068f9d0 ====

undefined4 FUN_0068f9d0(int param_1,undefined2 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  if (param_1 != iVar1) {
    return 0;
  }
  if (param_3 == 1) {
    switch(param_2) {
    case 1:
      iVar1 = *DAT_00b5a78c;
      uVar2 = thunk_FUN_00796fb0(param_4);
      (**(code **)(iVar1 + 0x28))(uVar2);
      return 1;
    case 3:
      iVar1 = *DAT_00b5b114;
      uVar2 = thunk_FUN_00796fb0(param_4);
      (**(code **)(iVar1 + 0x34))(uVar2);
      return 1;
    case 4:
      (**(code **)(*DAT_00b5a78c + 4))((int3)in_ECX[0x22]);
      return 1;
    case 5:
      uVar2 = thunk_FUN_00796f80(param_4);
      FUN_0068f950(uVar2);
      return 1;
    case 0xb:
      (**(code **)(*DAT_00b5b0e4 + 0x1c))();
    }
  }
  return 1;
}


// ==== FUN_0068fae0 @ 0x0068fae0 ====

void FUN_0068fae0(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 uVar4;
  void *pvStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  FUN_005811f0();
  cVar1 = (**(code **)(*DAT_00b5b0e4 + 0x38))();
  if (cVar1 == '\x01') {
    cVar1 = (**(code **)(*DAT_00b5b0e4 + 0x3c))();
    if (cVar1 == '\0') {
      uVar4 = 100;
    }
    else {
      uVar4 = 0x65;
    }
    FUN_004dd240(0x16,uVar4,0,0,0);
    uStack_4 = 0xf;
    uStack_8 = 0;
    uStack_18 = 0;
    FUN_00401740(s_pan_effect_009dc9c4,10);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1c);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
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
    puVar3[2] = 0x80014;
    puVar3[3] = unaff_ESI;
    puVar3[4] = 1000;
    *(undefined1 *)(puVar3 + 6) = 1;
    (**(code **)(*DAT_00b5ad24 + 4))(puVar3);
    (**(code **)*puVar3)(1);
    (**(code **)(*DAT_00b5b0e4 + 0x34))(0);
  }
  return;
}


// ==== FUN_0068fc10 @ 0x0068fc10 ====

void FUN_0068fc10(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  uint uStack_24;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_hasstone_item_009dc9d8,0xd);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  (**(code **)(*piVar1 + 0x30))();
  piVar1 = (int *)(**(code **)(*DAT_00b5b0e4 + 0x2c))();
  if (piVar1 == (int *)0x0) {
    uStack_30 = 1;
    uStack_2c = 1;
    FUN_005802c0((int)register0x00000010 + -0x38,&uStack_30);
    FUN_00580870(0,1);
    return;
  }
  if ((int *)*piVar1 == (int *)0x0) {
    uStack_30 = 1;
    uStack_2c = 1;
    FUN_005802c0((int)register0x00000010 + -0x38,&uStack_30);
    FUN_00580870(0,1);
    return;
  }
  uStack_34 = (**(code **)(*(int *)*piVar1 + 0x1c))();
  uStack_34 = uStack_34 & 0xffff;
  iVar2 = (**(code **)(*(int *)*piVar1 + 0x2c))();
  uStack_24 = (uint)*(byte *)(iVar2 + 0x31);
  uStack_28 = (uint)*(byte *)(iVar2 + 0x30);
  FUN_005802c0(&uStack_34,&uStack_28);
  FUN_00580870(*piVar1,1);
  return;
}


// ==== FUN_0068fd40 @ 0x0068fd40 ====

void FUN_0068fd40(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  uVar1 = (**(code **)(*DAT_00b5a78c + 0x40))();
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  FUN_00401740(s_lbl_money_009dca20,9);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_1c);
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = (void *)((uint)uStack_1c & 0xffffff00);
  (**(code **)(*piVar2 + 0x30))();
  uVar1 = FUN_004041a0((int)register0x00000010 + -0x20,uVar1);
  FUN_0055a260(uVar1);
  if (uStack_8 < 0x10) {
    return;
  }
  _free(uStack_1c);
  return;
}


// ==== FUN_0068fdf0 @ 0x0068fdf0 ====

void FUN_0068fdf0(void)

{
  undefined1 uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  int iVar6;
  int *piVar7;
  uint auStack_3c [3];
  uint uStack_30;
  undefined4 uStack_2c;
  void *apvStack_28 [4];
  undefined4 uStack_18;
  uint uStack_14;
  
  uVar2 = 0;
  iVar6 = 0;
  piVar7 = (int *)(in_ECX + 0x30);
  do {
    if ((uVar2 < 0xd) || (0x12 < uVar2)) {
      iVar3 = (**(code **)(*DAT_00b5a78c + 0x44))(iVar6);
      *piVar7 = iVar3;
      FUN_00401740(s_suititem__d_009dca34,0xb);
      uVar4 = FUN_00404230(apvStack_28);
      piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar4);
      if (0xf < uStack_14) {
        _free(apvStack_28[0]);
        return;
      }
      uStack_14 = 0xf;
      uStack_18 = 0;
      apvStack_28[0] = (void *)((uint)apvStack_28[0] & 0xffffff00);
      (**(code **)(*piVar5 + 0x30))();
      if ((int *)*piVar7 == (int *)0x0) {
        auStack_3c[1] = 0;
        uStack_2c = 1;
        apvStack_28[0] = (void *)0x1;
        FUN_005802c0(auStack_3c + 1,&uStack_2c);
        FUN_00580870(0,1);
      }
      else {
        auStack_3c[0] = (**(code **)(*(int *)*piVar7 + 0x1c))();
        auStack_3c[0] = auStack_3c[0] & 0xffff;
        iVar3 = (**(code **)(*(int *)*piVar7 + 0x2c))();
        uStack_30 = (uint)*(byte *)(iVar3 + 0x31);
        auStack_3c[2] = (uint)*(byte *)(iVar3 + 0x30);
        FUN_005802c0(auStack_3c,auStack_3c + 2);
        FUN_00580870(*piVar7,1);
        FUN_0057f430(0xffffffff);
      }
    }
    uVar2 = uVar2 + 1;
    iVar6 = iVar6 + 1;
    piVar7 = piVar7 + 1;
  } while (uVar2 < 0x15);
  uVar1 = (**(code **)(*DAT_00b5a78c + 0x54))();
  *(undefined1 *)(in_ECX + 0x8c) = uVar1;
  return;
}


// ==== FUN_0068ff50 @ 0x0068ff50 ====

undefined4 FUN_0068ff50(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined2 uStack_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_slotbag_009dcb38,7);
  if (iVar2 != 0) {
    return 0;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a78c + 0x48))();
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x2c))();
    uStack_20 = CONCAT11(uStack_20._1_1_,*(undefined1 *)(in_ECX + 0x8b));
    uVar1 = FUN_00802534();
    uStack_20 = CONCAT11(uVar1,(undefined1)uStack_20);
    uVar1 = FUN_00802534();
    (**(code **)(*DAT_00b5a78c + 4))(CONCAT12(uVar1,uStack_20));
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_Call_________IINVEN__IUIHANDLER__009dcb40,0x3c);
    FUN_00796d50(&uStack_20);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return extraout_EAX;
    }
  }
  return 1;
}


