// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x690000-0x69ffff

// ==== FUN_006900c0 @ 0x006900c0 ====

void FUN_006900c0(void)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  *in_ECX = &PTR_FUN_009dcb98;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  iVar1 = 2;
  puVar2 = in_ECX + 0xd;
  do {
    if ((void *)puVar2[-4] != (void *)0x0) {
      _free((void *)puVar2[-4]);
      return;
    }
    iVar1 = iVar1 + -1;
    puVar2[-4] = 0;
    puVar2[-3] = 0;
    puVar2[-2] = 0;
    puVar2 = puVar2 + -4;
  } while (iVar1 != 0);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00690110 @ 0x00690110 ====

void FUN_00690110(void)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint *puVar4;
  int *piVar5;
  int in_ECX;
  undefined4 uVar6;
  int iVar7;
  undefined4 uStack_2c;
  byte bStack_27;
  byte bStack_26;
  void *local_24;
  void *pvStack_20;
  uint uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  
  if (*(void **)(in_ECX + 0x14) != (void *)0x0) {
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
  (**(code **)(*DAT_00b5a78c + 0x38))(&local_24);
  uStack_14 = 0xffffffff;
  if (local_24 != (void *)0x0) {
    uStack_1c = (uint)bStack_27;
    uStack_18 = (uint)bStack_26;
    pvStack_20 = local_24;
    uVar6 = 0xffff0000;
    cVar1 = FUN_0068f850(local_24);
    if (cVar1 != '\0') {
      uVar6 = 0xffffffff;
    }
    iVar3 = (**(code **)(*DAT_00b5b0e4 + 0x2c))();
    if ((iVar3 != 0) &&
       (puVar4 = (uint *)(**(code **)(*DAT_00b5b0e4 + 0x2c))(), (void *)*puVar4 == local_24)) {
      uVar6 = 0xaa333333;
    }
    uStack_14 = uVar6;
    FUN_00680ed0(&pvStack_20);
    (**(code **)(*DAT_00b5a78c + 0x3c))((int)register0x00000010 + -0x30);
    while (uStack_2c != (void *)0x0) {
      uStack_1c = (uint)local_24 >> 8 & 0xff;
      uStack_18 = (uint)local_24 >> 0x10 & 0xff;
      uVar6 = 0xffff0000;
      pvStack_20 = uStack_2c;
      cVar1 = FUN_0068f850(uStack_2c);
      if (cVar1 != '\0') {
        uVar6 = 0xffffffff;
      }
      iVar3 = (**(code **)(*DAT_00b5b0e4 + 0x2c))();
      if ((iVar3 != 0) &&
         (puVar4 = (uint *)(**(code **)(*DAT_00b5b0e4 + 0x2c))(), (void *)*puVar4 == uStack_2c)) {
        uVar6 = 0xaa333333;
      }
      iVar7 = (((uint)local_24 & 0xff) + 1) * 0x10;
      iVar3 = *(int *)(iVar7 + 4 + in_ECX);
      iVar7 = iVar7 + in_ECX;
      uStack_14 = uVar6;
      if ((iVar3 == 0) ||
         ((uint)(*(int *)(iVar7 + 0xc) - iVar3 >> 4) <= (uint)(*(int *)(iVar7 + 8) - iVar3 >> 4))) {
        FUN_00680c50(*(undefined4 *)(iVar7 + 8),1,&pvStack_20);
      }
      else {
        iVar3 = *(int *)(iVar7 + 8);
        FUN_00680b80(iVar3,1,&pvStack_20,iVar7,local_24);
        *(int *)(iVar7 + 8) = iVar3 + 0x10;
      }
      (**(code **)(*DAT_00b5a78c + 0x3c))((int)register0x00000010 + -0x30);
    }
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = uStack_1c & 0xffffff00;
  FUN_00401740(s_slotbag_009dca2c,7);
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
  if (uStack_c < 0x10) {
    uStack_c = 0xf;
    uStack_10 = 0;
    pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
    (**(code **)(*piVar5 + 0x30))();
    bVar2 = (**(code **)(*DAT_00b5a78c + 0x50))();
    *(byte *)(in_ECX + 0x8b) = bVar2;
    FUN_005817e0((bVar2 + 1) * 0x10 + in_ECX,1);
    return;
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_00690360 @ 0x00690360 ====

/* WARNING: Removing unreachable block (ram,0x006903e7) */

void FUN_00690360(undefined4 param_1,byte *param_2,ushort param_3)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  puVar2 = operator_new(0x58);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009b5340;
    puVar2[6] = 0;
    puVar2[7] = 0xf;
    *(undefined1 *)(puVar2 + 2) = 0;
    puVar2[0xe] = 0xf;
    puVar2[0xd] = 0;
    *(undefined1 *)(puVar2 + 9) = 0;
    puVar2[0x10] = 0;
    puVar2[0x11] = 0;
    puVar2[0x12] = 0;
    *(undefined2 *)(puVar2 + 0x13) = 0;
    puVar2[0x14] = 0;
    puVar2[0x15] = 10000;
  }
  uVar3 = (**(code **)(*in_ECX + 0x14))();
  puVar2[0x14] = uVar3;
  FUN_00401660(param_1,0,0xffffffff);
  bVar1 = *param_2;
  if (0xff < param_3) {
    param_3 = 0xff;
  }
  puVar2[0x15] = 2000;
  *(ushort *)(puVar2 + 0x13) = (ushort)bVar1 << 8 | param_3;
  FUN_00797a20(puVar2);
  return;
}


// ==== FUN_00690410 @ 0x00690410 ====

void FUN_00690410(void)

{
  undefined1 uVar1;
  int *piVar2;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 *puVar3;
  void **ppvVar4;
  undefined4 local_20;
  void *local_1c;
  undefined1 local_18;
  uint uStack_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  FUN_0068fd40();
  FUN_00690110();
  FUN_0068fdf0();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_tab_chang_shield_009dc9e8,0x10);
  local_20 = (void *)CONCAT31(local_20._1_3_,*(undefined1 *)(in_ECX + 0x8c));
  ppvVar4 = &local_1c;
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(ppvVar4);
  (**(code **)(*piVar2 + 0x30))();
  FUN_00582440(unaff_EBX);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(s_tab_chang_weapon_009dc9fc,0x10);
  uVar1 = *(undefined1 *)(in_ECX + 0x8c);
  puVar3 = &local_20;
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(puVar3);
  (**(code **)(*piVar2 + 0x30))();
  FUN_00582440(unaff_ESI);
  if (0xf < uStack_c) {
    _free(local_20);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(s_tab_chang_bag_009dca10,0xd);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))
                            ((int)register0x00000010 + -0x24,puVar3,ppvVar4,
                             *(undefined1 *)(in_ECX + 0x8b));
  (**(code **)(*piVar2 + 0x30))();
  FUN_00582440(ppvVar4);
  if (uStack_10 < 0x10) {
    return;
  }
  _free((void *)CONCAT31((int3)((uint)unaff_EBX >> 8),uVar1));
  return;
}


// ==== FUN_00690550 @ 0x00690550 ====

void FUN_00690550(void)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  FUN_0068fc10();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_btn_ok_009dc9d0,6);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  cVar1 = (**(code **)(*DAT_00b5b0e4 + 0x24))();
  if (cVar1 == '\0') {
    (**(code **)(*piVar2 + 0x44))(0);
    FUN_00690410();
    return;
  }
  (**(code **)(*piVar2 + 0x44))(1);
  FUN_00690410();
  return;
}


// ==== FUN_006905f0 @ 0x006905f0 ====

undefined4 FUN_006905f0(int param_1,int param_2,int param_3,undefined4 param_4)

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
      iVar6 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_ok_009dca40,6);
      if (iVar6 == 0) {
        param_3 = CONCAT31(param_3._1_3_,0x1f);
        FUN_00401830(s_ui_upgradeprogress_txt_009dca48);
        FUN_00690360(local_38,&param_3,0xb);
        if (local_20 < 0x10) {
          return 1;
        }
        _free(local_34);
        return extraout_EAX;
      }
      cVar3 = FUN_004036a0(iVar2,s_btn_exit_009dca60);
      if (cVar3 != '\0') {
        (**(code **)(*in_ECX + 0x10))();
        return 1;
      }
    }
  }
  else if (param_1 == 10) {
    if ((param_3 == 1) && (cVar3 = FUN_0068ff50(param_2,param_4), cVar3 != '\0')) {
      return 1;
    }
  }
  else {
    if (param_1 == 0xf) {
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      FUN_00404fb0(param_2,0x5f,local_48);
      if (param_3 == 1) {
        pcVar8 = s_hasstone_009dca6c;
        uVar7 = FUN_00405d30(0);
        cVar3 = FUN_004036a0(uVar7,pcVar8);
        if (cVar3 != '\0') {
          (**(code **)(*DAT_00b5b0e8 + 0xc))();
          FUN_00690550();
          FUN_00406250();
          return 1;
        }
        pcVar8 = s_suititem_009dca78;
        uVar7 = FUN_00405d30(0);
        cVar3 = FUN_004036a0(uVar7,pcVar8);
        if (cVar3 != '\0') {
          uVar7 = FUN_00405d30(1);
          uVar4 = thunk_FUN_00796f50(uVar7);
          (**(code **)(*DAT_00b5a78c + 0xc))(uVar4);
          FUN_00406250();
          return 1;
        }
        pcVar8 = s_slotbag_009dca84;
        uVar7 = FUN_00405d30(0);
        cVar3 = FUN_004036a0(uVar7,pcVar8);
        if (cVar3 != '\0') {
          uVar7 = FUN_00405d30(1);
          uVar4 = thunk_FUN_00796f50(uVar7);
          uVar7 = FUN_00405d30(2);
          uVar5 = thunk_FUN_00796f50(uVar7);
          piVar1 = in_ECX + 0x22;
          *(undefined1 *)piVar1 = *(undefined1 *)((int)in_ECX + 0x8b);
          *(undefined1 *)((int)in_ECX + 0x89) = uVar4;
          *(undefined1 *)((int)in_ECX + 0x8a) = uVar5;
          cVar3 = (**(code **)(*DAT_00b5a78c + 0x34))(piVar1);
          if (cVar3 == '\0') {
            (**(code **)(*DAT_00b5a78c + 4))((int3)*piVar1);
            FUN_00401830(s_Call_________IINVEN__IUIHANDLER__009dca9c);
            FUN_00796d50(&local_40);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          param_2 = CONCAT31(param_2._1_3_,3);
          FUN_00401830(s_ui_socket_txt_009dca8c);
          FUN_00690360(&local_3c,&param_2,4);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
LAB_00690a14:
        FUN_00406250();
        return 0;
      }
      if (param_3 == 2) {
        pcVar8 = s_slotbag_009dcadc;
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
          param_3._0_2_ = CONCAT11(uVar4,*(undefined1 *)((int)in_ECX + 0x8b));
          (**(code **)(*DAT_00b5a78c + 8))(CONCAT12(uVar5,(undefined2)param_3));
          FUN_00406250();
        }
      }
      else if (param_3 == 0xd) {
        pcVar8 = s_slotbag_009dcae4;
        uVar7 = FUN_00405d30(0);
        cVar3 = FUN_004036a0(uVar7,pcVar8);
        if (cVar3 != '\0') {
          param_3 = CONCAT31(param_3._1_3_,4);
          FUN_00401830(s_ui_stackcount_txt_009dcaec);
          FUN_00690360(local_1c,&param_3,5);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
      }
      else if (((param_3 != 4) && (param_3 != 5)) ||
              (cVar3 = FUN_0068f8d0(iVar2,param_3,param_4), cVar3 == '\0')) goto LAB_00690a14;
      FUN_00406250();
      return 1;
    }
    if ((param_1 == 0xb) && (param_3 == 1)) {
      cVar3 = FUN_004036a0(param_2,s_tab_chang_weapon_009dcb00);
      if ((cVar3 != '\0') ||
         (cVar3 = FUN_004036a0(iVar2,s_tab_chang_shield_009dcb14), cVar3 != '\0')) {
        uVar7 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x28001c);
        FUN_00765c50(uVar7);
        iVar2 = *DAT_00b5ad0c;
        FUN_00765c50(auStack_24);
        (**(code **)(iVar2 + 0x28))(2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar3 = FUN_004036a0(iVar2,s_tab_chang_bag_009dcb28);
      if (cVar3 == '\0') {
        return 0;
      }
      *(char *)((int)in_ECX + 0x8b) = (char)param_4;
      (**(code **)(*DAT_00b5a78c + 0x30))(param_4);
      FUN_00690550();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00690b00 @ 0x00690b00 ====

void FUN_00690b00(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  void *unaff_ESI;
  void *unaff_EDI;
  undefined1 auStack_38 [4];
  undefined4 local_1c;
  void *local_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_seperatestonewnd_txt_009dc990,0x20);
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
  FUN_00401740(s_slotbag_009dc9b4,7);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_38 + 0x10);
  if (0xf < uStack_14) {
    _free(unaff_ESI);
    return;
  }
  uStack_14 = 0xf;
  local_18 = (void *)0x0;
  (**(code **)(*piVar2 + 0x30))();
  FUN_00580be0(1);
  uStack_14 = 0xf;
  local_18 = (void *)0x0;
  FUN_00401740(s_slotbag_009dc9bc,7);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_38 + 0xc);
  if (local_18 < 0x10) {
    local_18 = (void *)0xf;
    local_1c = 0;
    uVar3 = (**(code **)(*piVar2 + 0x30))();
    *(undefined4 *)(in_ECX + 0x84) = uVar3;
    FUN_00690550();
    return;
  }
  _free(unaff_EDI);
  return;
}


// ==== FUN_00690c30 @ 0x00690c30 ====

uint FUN_00690c30(int *param_1)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = (**(code **)(*in_ECX + 0x30))(param_1);
  }
  else if (uVar1 == 0x70400002) {
    uVar1 = FUN_00690550();
    return uVar1 & 0xffffff00;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00690c70 @ 0x00690c70 ====

void FUN_00690c70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dcb98;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  *(undefined1 *)(in_ECX + 0x22) = 0;
  *(undefined1 *)((int)in_ECX + 0x89) = 0;
  *(undefined1 *)((int)in_ECX + 0x8a) = 0;
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 0x23) = 0;
  *(undefined1 *)((int)in_ECX + 0x8b) = 0;
  *(undefined1 *)(in_ECX + 0x22) = 0;
  *(undefined1 *)((int)in_ECX + 0x89) = 0;
  *(undefined1 *)((int)in_ECX + 0x8a) = 0;
  FUN_00690b00();
  return;
}


// ==== FUN_00690ce0 @ 0x00690ce0 ====

undefined4 FUN_00690ce0(void)

{
  return 0x3b;
}


// ==== FUN_00690cf0 @ 0x00690cf0 ====

void FUN_00690cf0(byte param_1)

{
  void *in_ECX;
  
  FUN_006900c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00690d10 @ 0x00690d10 ====

void FUN_00690d10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dccc8;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00690d40 @ 0x00690d40 ====

void FUN_00690d40(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
  if (piVar1 == (int *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00690d50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_00690d60 @ 0x00690d60 ====

undefined4 FUN_00690d60(void)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5ae48 + 0x24))();
  if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5ae48 + 0x1c))();
    return 1;
  }
  return 0;
}


// ==== FUN_00690db0 @ 0x00690db0 ====

void FUN_00690db0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined1 uStack00000000;
  int *piStack_c;
  uint uStack_8;
  
  piStack_c = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
    if (param_1 != (int *)0x0) {
      iVar2 = (**(code **)(*param_1 + 0x2c))();
      uStack_8 = (uint)*(byte *)(iVar2 + 0x31);
      piStack_c = (int *)(uint)*(byte *)(iVar2 + 0x30);
      (**(code **)(*param_1 + 0x1c))();
      FUN_005802c0(&uStack00000000,&piStack_c);
      FUN_00580870(param_1,0);
      return;
    }
    piStack_c = (int *)0x0;
    uStack_8 = 0;
    FUN_005802c0(&uStack00000000,&piStack_c);
    FUN_00580870(0,1);
  }
  return;
}


// ==== FUN_00690e60 @ 0x00690e60 ====

undefined4 FUN_00690e60(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_close_009dcc30,9);
    if (iVar2 == 0) {
      (**(code **)(*DAT_00b5ae48 + 0x1c))();
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_item_009dcc3c);
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5ae48 + 0x40))();
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_money_009dcc48);
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5ae48 + 0x44))();
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_delete_009dcc54);
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5ae48 + 0x48))();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00690f20 @ 0x00690f20 ====

void FUN_00690f20(void)

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
  FUN_00401740(s_textbox_009dccb4,7);
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
    FUN_005569f0(unaff_retaddr,0);
  }
  return;
}


// ==== FUN_00690fa0 @ 0x00690fa0 ====

/* WARNING: Removing unreachable block (ram,0x00691487) */
/* WARNING: Removing unreachable block (ram,0x00691441) */

void FUN_00690fa0(void)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  int *piVar8;
  uint unaff_EBX;
  uint unaff_ESI;
  void *unaff_EDI;
  undefined4 *puVar9;
  undefined4 uStack_3a4;
  undefined4 uStack_394;
  undefined1 *puStack_388;
  void *pvStack_380;
  uint uStack_37c;
  uint uStack_378;
  undefined4 uStack_374;
  uint uStack_370;
  void *pvStack_36c;
  undefined1 auStack_368 [4];
  void *pvStack_364;
  void *pvStack_35c;
  uint uStack_358;
  undefined4 uStack_354;
  uint uStack_350;
  undefined4 uStack_34c;
  void *pvStack_348;
  undefined1 auStack_33c [4];
  undefined4 uStack_338;
  uint uStack_334;
  void *apvStack_32c [2];
  undefined1 auStack_324 [8];
  undefined4 uStack_31c;
  uint uStack_318;
  undefined4 uStack_314;
  void *apvStack_310 [4];
  undefined4 uStack_300;
  uint uStack_2fc;
  void *apvStack_2f4 [4];
  undefined4 uStack_2e4;
  uint uStack_2e0;
  void *apvStack_2d8 [4];
  undefined4 uStack_2c8;
  uint uStack_2c4;
  void *apvStack_2bc [4];
  undefined4 uStack_2ac;
  uint uStack_2a8;
  undefined1 auStack_27c [16];
  undefined4 auStack_26c [3];
  char acStack_25d [17];
  char acStack_24c [67];
  char acStack_209 [517];
  
  puStack_388 = acStack_209 + 0x205;
  uStack_394 = (undefined1 *)0x690fbf;
  piVar3 = (int *)(**(code **)(*DAT_00b5ae4c + 4))();
  if (piVar3 != (int *)0x0) {
    uStack_394 = (undefined1 *)0x690fd6;
    iVar4 = (**(code **)(*DAT_00b5ae48 + 0x4c))();
    if (*(uint *)(iVar4 + 0x18) < 0x10) {
      uStack_394 = (undefined1 *)(iVar4 + 4);
    }
    else {
      uStack_394 = *(undefined1 **)(iVar4 + 4);
    }
    FUN_006915e0();
    uStack_394 = auStack_27c;
    piVar3 = (int *)(**(code **)(*piVar3 + 0xc))();
    puVar5 = (undefined4 *)(**(code **)(*piVar3 + 0x10))();
    puVar9 = auStack_26c;
    for (iVar4 = 0x97; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    pcVar6 = acStack_209;
    pvStack_348 = (void *)0xf;
    uStack_34c = 0;
    pvStack_35c = (void *)((uint)pvStack_35c & 0xffffff00);
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740();
    pvVar2 = pvStack_364;
    FUN_00690f20();
    if (0xf < pvStack_348) {
      _free(pvStack_35c);
      return;
    }
    apvStack_310[0] = (void *)0xf;
    uStack_314 = 0;
    auStack_324[0] = 0;
    uVar7 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_3a4 = (char *)0x0;
    uStack_370 = 0xf;
    uStack_374 = 0;
    FUN_00401660(uVar7);
    uStack_3a4 = (char *)0x0;
    FUN_00401660(&puStack_388);
    pcVar6 = acStack_25d;
    uStack_350 = 0xf;
    uStack_354 = 0;
    pvStack_364 = (void *)((uint)pvStack_364 & 0xffffff00);
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uStack_3a4 = acStack_25d;
    FUN_00401740();
    uStack_3a4 = (char *)0x0;
    FUN_00401ff0(auStack_368);
    if (0xf < uStack_350) {
      uStack_3a4 = (char *)0x691124;
      _free(pvStack_364);
      return;
    }
    if (0xf < uStack_370) {
      uStack_3a4 = (char *)0x691138;
      _free((void *)(unaff_EBX & 0xffffff00));
      return;
    }
    uStack_334 = 0xf;
    uStack_338 = 0;
    pvStack_348 = (void *)((uint)pvStack_348 & 0xffffff00);
    uStack_3a4 = (char *)0x5;
    uVar7 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_358 = 0xf;
    pvStack_35c = (void *)0x0;
    pvStack_36c = (void *)((uint)pvStack_36c & 0xffffff00);
    FUN_00401660(uVar7,0,0xffffffff);
    FUN_00401740(&DAT_009dcc60,7);
    pcVar6 = acStack_24c;
    uStack_378 = 0xf;
    uStack_37c = 0;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_24c,(int)pcVar6 - (int)(acStack_24c + 1));
    FUN_00401ff0(auStack_368 + -0x28,0,0xffffffff);
    if (0xf < uStack_378) {
      _free((void *)(unaff_ESI & 0xffffff00));
      return;
    }
    if (0xf < uStack_358) {
      _free(pvStack_36c);
      return;
    }
    uStack_378 = 0xf;
    uStack_37c = 0;
    FUN_00401740(s_lbl_sendername_009dcc68,0xe);
    piVar8 = (int *)(**(code **)(**(int **)((int)pvVar2 + 4) + 0x34))(auStack_368 + -0x28);
    if (piVar8 != (int *)0x0) {
      (**(code **)(*piVar8 + 0x30))();
      FUN_0055a260(auStack_33c);
    }
    if (0xf < uStack_37c) {
      _free(unaff_EDI);
      return;
    }
    uStack_37c = 0xf;
    pvStack_380 = (void *)0x0;
    FUN_00401740(s_lbl_title_009dcc78,9);
    piVar8 = (int *)(**(code **)(**(int **)((int)pvVar2 + 4) + 0x34))(&uStack_394);
    if (piVar8 != (int *)0x0) {
      (**(code **)(*piVar8 + 0x30))();
      FUN_0055a260(&pvStack_35c);
    }
    if ((void *)0xf < pvStack_380) {
      _free(uStack_394);
      return;
    }
    uVar7 = (**(code **)(*piVar3 + 0x1c))();
    (**(code **)(*DAT_00b5ad20 + 0x48))(auStack_324,uVar7);
    puStack_388 = (undefined1 *)0xf;
    FUN_00401740(s_lbl_money_009dcc9c,9);
    uVar7 = FUN_004041a0(apvStack_2bc,uVar7,s_<_color>_009dcc84);
    uVar7 = FUN_004022a0(apvStack_2f4,s_<color__009dcc94,apvStack_32c,&DAT_009dcc90,uVar7);
    uVar7 = FUN_00402220(apvStack_310,uVar7);
    uVar7 = FUN_00405bd0(apvStack_2d8,uVar7);
    uVar7 = FUN_00402220(&pvStack_380,uVar7);
    piVar8 = (int *)(**(code **)(**(int **)((int)(unaff_EBX & 0xffffff00) + 4) + 0x34))
                              (auStack_368 + -0x38);
    if (piVar8 != (int *)0x0) {
      (**(code **)(*piVar8 + 0x30))();
      FUN_0055a260(uVar7);
    }
    if ((void *)0xf < pvStack_36c) {
      _free(pvStack_380);
      return;
    }
    pvStack_36c = (void *)0xf;
    uStack_370 = 0;
    pvStack_380 = (void *)((uint)pvStack_380 & 0xffffff00);
    if (0xf < uStack_2c4) {
      _free(apvStack_2d8[0]);
      return;
    }
    uStack_2c4 = 0xf;
    uStack_2c8 = 0;
    apvStack_2d8[0] = (void *)((uint)apvStack_2d8[0] & 0xffffff00);
    if (0xf < uStack_2fc) {
      _free(apvStack_310[0]);
      return;
    }
    uStack_2fc = 0xf;
    uStack_300 = 0;
    apvStack_310[0] = (void *)((uint)apvStack_310[0] & 0xffffff00);
    if (0xf < uStack_2e0) {
      _free(apvStack_2f4[0]);
      return;
    }
    uStack_2e0 = 0xf;
    uStack_2e4 = 0;
    apvStack_2f4[0] = (void *)((uint)apvStack_2f4[0] & 0xffffff00);
    if (0xf < uStack_2a8) {
      _free(apvStack_2bc[0]);
      return;
    }
    uStack_2a8 = 0xf;
    uStack_2ac = 0;
    apvStack_2bc[0] = (void *)((uint)apvStack_2bc[0] & 0xffffff00);
    FUN_00401740(s_giveitem_009dcca8,8);
    uVar7 = (**(code **)(*piVar3 + 0x14))();
    FUN_00690db0(&uStack_3a4,uVar7);
    if (0xf < uStack_318) {
      _free(apvStack_32c[0]);
      return;
    }
    uStack_318 = 0xf;
    uStack_31c = 0;
    apvStack_32c[0] = (void *)((uint)apvStack_32c[0] & 0xffffff00);
    if (0xf < uStack_350) {
      _free(pvStack_364);
      return;
    }
    uStack_350 = 0xf;
    uStack_354 = 0;
    pvStack_364 = (void *)((uint)pvStack_364 & 0xffffff00);
    if (0xf < uStack_334) {
      _free(pvStack_348);
      return;
    }
  }
  return;
}


// ==== FUN_00691500 @ 0x00691500 ====

void FUN_00691500(void)

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
  FUN_00401740(s_UI_Game2_Letter_ui_letterreadwnd_009dcc08,0x24);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_00690fa0();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00691580 @ 0x00691580 ====

undefined4 FUN_00691580(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70360005) {
    FUN_00690fa0();
    return 1;
  }
  return 0;
}


// ==== FUN_006915b0 @ 0x006915b0 ====

void FUN_006915b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dccc8;
  in_ECX[1] = 0;
  FUN_00691500();
  return;
}


// ==== FUN_006915d0 @ 0x006915d0 ====

undefined4 FUN_006915d0(void)

{
  return 0x53;
}


// ==== FUN_006915e0 @ 0x006915e0 ====

char * FUN_006915e0(char *param_1,char *param_2,char param_3)

{
  int iVar1;
  
  iVar1 = __vsnprintf(param_1,0x13,param_2,&param_3);
  if ((iVar1 < 0) || (iVar1 == 0x13)) {
    param_1[0x12] = '\0';
  }
  return param_1;
}


// ==== FUN_00691610 @ 0x00691610 ====

void FUN_00691610(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dccc8;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009b1764;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00691650 @ 0x00691650 ====

void FUN_00691650(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
  if (piVar1 == (int *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00691660. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_00691670 @ 0x00691670 ====

undefined4 FUN_00691670(void)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = (**(code **)(*DAT_00b5ae48 + 0x14))();
  if (cVar1 != '\x01') {
    return 0;
  }
  cVar1 = (**(code **)(*DAT_00b5ae48 + 0x24))();
  if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5ae48 + 0x1c))();
    return 1;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5aee8 + 8))();
  (**(code **)(*piVar2 + 0x1c))();
  return 1;
}


// ==== FUN_006916f0 @ 0x006916f0 ====

void FUN_006916f0(void)

{
  int *piVar1;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_maillist_009dcd7c,8);
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
    FUN_00570fc0(in_ECX + 8);
  }
  return;
}


// ==== FUN_00691770 @ 0x00691770 ====

void FUN_00691770(void)

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
  FUN_00401740(s_UI_Game2_Letter_ui_letterboxwnd__009dcd34,0x23);
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


// ==== FUN_006917f0 @ 0x006917f0 ====

undefined4 FUN_006917f0(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_1c [28];
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      iVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_close_009dcd58,9);
      if (iVar1 == 0) {
        piVar2 = (int *)(**(code **)(*DAT_00b5aee8 + 8))();
        (**(code **)(*piVar2 + 0x1c))();
        return 1;
      }
    }
  }
  else if ((param_1 == 0x18) && (param_3 == 1)) {
    iVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_maillist_009dcd64,8);
    if ((iVar1 == 0) && (*(int *)(in_ECX + 0xc) != 0)) {
      if (param_4 < (uint)((*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc)) / 0x78)) {
        uVar3 = FUN_00691dd0(param_4);
        FUN_00689cb0(uVar3);
        (**(code **)(*DAT_00b5ae48 + 0x3c))(local_1c);
        FUN_00689be0();
      }
    }
    return 1;
  }
  return 0;
}


// ==== FUN_006918e0 @ 0x006918e0 ====

void FUN_006918e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dcd90;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[1] = 0;
  FUN_0068a240();
  FUN_00691770();
  return;
}


// ==== FUN_00691910 @ 0x00691910 ====

void FUN_00691910(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dcd90;
  FUN_0068a240();
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  FUN_0068a240();
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00691950 @ 0x00691950 ====

void FUN_00691950(void)

{
  char cVar1;
  undefined2 uVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  void *in_ECX;
  int iVar6;
  int *unaff_EBX;
  int *piVar7;
  void *pvStack_360;
  int *piStack_35c;
  void *pvStack_354;
  uint uStack_34c;
  undefined4 uStack_348;
  undefined4 uStack_344;
  int *piStack_340;
  void *local_33c;
  int *piStack_338;
  undefined4 uStack_32c;
  uint uStack_328;
  uint uStack_324;
  void *pvStack_320;
  undefined1 uStack_31c;
  uint uStack_30c;
  undefined4 uStack_308;
  undefined1 auStack_304 [4];
  void *pvStack_300;
  undefined4 uStack_2f0;
  uint uStack_2ec;
  undefined1 uStack_2e4;
  undefined4 uStack_2e0;
  undefined1 uStack_2dc;
  undefined1 uStack_2d4;
  undefined4 uStack_2c4;
  undefined4 uStack_2c0;
  undefined1 uStack_2b8;
  undefined4 uStack_2a8;
  undefined4 uStack_2a4;
  undefined1 uStack_29c;
  undefined4 uStack_28c;
  undefined4 uStack_288;
  undefined1 uStack_280;
  undefined4 uStack_270;
  char acStack_26c [4];
  int aiStack_268 [5];
  char acStack_251 [25];
  char acStack_238 [552];
  uint uStack_10;
  
  local_33c = in_ECX;
  piVar3 = (int *)(**(code **)(*DAT_00b5ae4c + 4))();
  if (piVar3 != (int *)0x0) {
    piStack_338 = piVar3;
    FUN_0068a240();
    piStack_35c = (int *)(**(code **)(*piVar3 + 0x10))();
    if (piStack_35c != (int *)0x0) {
      do {
        uStack_2c0 = 0xf;
        uStack_2a4 = 0xf;
        uStack_288 = 0xf;
        acStack_26c[0] = '\x0f';
        acStack_26c[1] = '\0';
        acStack_26c[2] = '\0';
        acStack_26c[3] = '\0';
        uStack_2e0 = 0;
        uStack_2dc = 0;
        uStack_2c4 = 0;
        uStack_2d4 = 0;
        uStack_2a8 = 0;
        uStack_2b8 = 0;
        uStack_28c = 0;
        uStack_29c = 0;
        uStack_270 = 0;
        uStack_280 = 0;
        piVar3 = (int *)(**(code **)(*piStack_35c + 0x10))();
        piVar7 = aiStack_268;
        for (iVar6 = 0x97; iVar6 != 0; iVar6 = iVar6 + -1) {
          *piVar7 = *piVar3;
          piVar3 = piVar3 + 1;
          piVar7 = piVar7 + 1;
        }
        if (aiStack_268[0] == 0) {
          uStack_2e0 = 0xb;
        }
        else if (aiStack_268[0] == 1) {
          uStack_2e0 = 0xc;
        }
        pcVar4 = acStack_251;
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        FUN_00401740(acStack_251,(int)pcVar4 - (int)(acStack_251 + 1));
        pcVar4 = acStack_238;
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        FUN_004020e0(acStack_238,(int)pcVar4 - (int)(acStack_238 + 1));
        piStack_340 = (int *)0xf;
        uStack_344 = 0;
        pvStack_354 = (void *)((uint)pvStack_354 & 0xffffff00);
        if (uStack_10 / 0x5a0 < 2) {
          uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,&DAT_006e00a4);
          FUN_00401660(uVar5,0,0xffffffff);
          FUN_00401660(&pvStack_360,0,0xffffffff);
          uVar5 = FUN_00404230(&local_33c);
          FUN_00401660(uVar5,0,0xffffffff);
          if (0xf < uStack_324) {
            _free(piStack_338);
            return;
          }
          uStack_324 = 0xf;
          uStack_328 = 0;
          piStack_338 = (int *)((uint)piStack_338 & 0xffffff00);
        }
        else {
          uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,&DAT_006e00a2);
          FUN_00401660(uVar5,0,0xffffffff);
          FUN_00401660(&pvStack_360,0,0xffffffff);
          uVar5 = FUN_00404230(auStack_304);
          FUN_00401660(uVar5,0,0xffffffff);
          if (0xf < uStack_2ec) {
            _free(pvStack_300);
            return;
          }
          uStack_2ec = 0xf;
          uStack_2f0 = 0;
          pvStack_300 = (void *)((uint)pvStack_300 & 0xffffff00);
        }
        FUN_00401660(&pvStack_360,0,0xffffffff);
        uStack_2e4 = (**(code **)(*unaff_EBX + 0x28))();
        pcVar4 = acStack_26c;
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        FUN_00401740(acStack_26c,(int)pcVar4 - (int)(acStack_26c + 1));
        piVar3 = (int *)(**(code **)(*piStack_340 + 0x14))();
        piStack_35c = piVar3;
        FUN_0068a680(&uStack_2e0);
        if ((int *)0xf < piStack_340) {
          _free(pvStack_354);
          return;
        }
        piStack_340 = (int *)0xf;
        uStack_344 = 0;
        pvStack_354 = (void *)((uint)pvStack_354 & 0xffffff00);
        FUN_00689be0();
      } while (piVar3 != (int *)0x0);
      piVar3 = piStack_338;
      in_ECX = local_33c;
    }
    uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,&DAT_006e00a3);
    uStack_308 = 0xf;
    uStack_30c = 0;
    uStack_31c = 0;
    FUN_00401660(uVar5,0,0xffffffff);
    FUN_006916f0();
    uStack_348 = 0xf;
    uStack_34c = 0;
    piStack_35c = (int *)((uint)piStack_35c & 0xffffff00);
    FUN_00401740(s_lbl_message_009dcd70,0xb);
    uVar2 = (**(code **)(*piVar3 + 0x30))();
    (**(code **)(*piVar3 + 0x28))(uVar2);
    FUN_00401660(&pvStack_320,0,0xffffffff);
    uVar5 = FUN_00404230(&local_33c);
    piVar3 = (int *)(**(code **)(**(int **)((int)in_ECX + 4) + 0x34))(&pvStack_360);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x30))();
      FUN_0055a260(uVar5);
    }
    if (0xf < uStack_328) {
      _free(local_33c);
      return;
    }
    uStack_328 = 0xf;
    uStack_32c = 0;
    local_33c = (void *)((uint)local_33c & 0xffffff00);
    if (0xf < uStack_34c) {
      _free(pvStack_360);
      return;
    }
    if (0xf < uStack_30c) {
      _free(pvStack_320);
      return;
    }
  }
  return;
}


// ==== FUN_00691da0 @ 0x00691da0 ====

undefined4 FUN_00691da0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70360004) {
    FUN_00691950();
    return 1;
  }
  return 0;
}


// ==== FUN_00691dd0 @ 0x00691dd0 ====

int FUN_00691dd0(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if (param_1 < (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x78)) {
      return iVar1 + param_1 * 0x78;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0085b340();
}


// ==== FUN_00691e10 @ 0x00691e10 ====

undefined4 FUN_00691e10(void)

{
  return 0x52;
}


// ==== FUN_00691e20 @ 0x00691e20 ====

void FUN_00691e20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dcd90;
  FUN_0068a240();
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  FUN_0068a240();
  *in_ECX = &PTR_FUN_009b1764;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00691e70 @ 0x00691e70 ====

void FUN_00691e70(void)

{
  return;
}


// ==== FUN_00691e80 @ 0x00691e80 ====

void FUN_00691e80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dce4c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00691ea0 @ 0x00691ea0 ====

undefined4 FUN_00691ea0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_title_009dce24,9);
    if (iVar2 == 0) {
      piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0x18))();
      (**(code **)(*piVar3 + 0xc))();
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_exit_009dce30);
    if (cVar1 != '\0') {
      puVar4 = operator_new(4);
      if (puVar4 == (undefined4 *)0x0) {
        FUN_00797a20(0);
        return 1;
      }
      *puVar4 = &PTR_FUN_009bb188;
      FUN_00797a20(puVar4);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00691f40 @ 0x00691f40 ====

void FUN_00691f40(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int in_ECX;
  void *unaff_EDI;
  undefined1 auStack_34 [4];
  undefined1 local_1c [4];
  void *local_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Console_UI_System_txt_009dcdfc,0x18);
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
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740(s_text_view_009dce18,9);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_34 + 0xc);
  *(undefined4 *)(in_ECX + 8) = uVar3;
  if (0xf < uStack_14) {
    _free(unaff_EDI);
    return;
  }
  puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    uVar3 = (**(code **)(**(int **)(in_ECX + 8) + 4))();
    *puVar4 = &PTR_FUN_009bcd68;
    puVar4[1] = uVar3;
  }
  *(undefined1 *)(puVar4 + 2) = 0;
  (**(code **)(*DAT_00b5ad24 + 4))(puVar4);
  (**(code **)*puVar4)(1);
  return;
}


// ==== FUN_00692040 @ 0x00692040 ====

void FUN_00692040(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  undefined1 auStack_70 [4];
  void *pvStack_6c;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined1 auStack_38 [4];
  void *pvStack_34;
  undefined4 uStack_24;
  uint uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  if (*(int *)(in_ECX + 8) != 0) {
    (**(code **)(**(int **)(in_ECX + 8) + 0x30))();
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
    FUN_00401740(&DAT_009dce39,0);
    piVar4 = (int *)(**(code **)(*DAT_00b5a688 + 0x18))();
    iVar5 = (**(code **)(*piVar4 + 8))();
    piVar4 = (int *)**(undefined4 **)(iVar5 + 4);
    piVar6 = (int *)(**(code **)(*DAT_00b5a688 + 0x18))();
    iVar5 = (**(code **)(*piVar6 + 8))();
    piVar6 = *(int **)(iVar5 + 4);
    while (piVar4 != piVar6) {
      uVar7 = FUN_00402220(auStack_1c,piVar4 + 10,&DAT_009dce40,piVar4 + 0x11,&DAT_009dce3c);
      uVar7 = FUN_00405bd0(auStack_38,uVar7);
      uVar7 = FUN_00402220(auStack_54,uVar7);
      FUN_00401ff0(uVar7,0,0xffffffff);
      if (0xf < uStack_3c) {
        _free(pvStack_50);
        return;
      }
      uStack_3c = 0xf;
      uStack_40 = 0;
      pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
      if (0xf < uStack_20) {
        _free(pvStack_34);
        return;
      }
      uStack_20 = 0xf;
      uStack_24 = 0;
      pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      if (*(char *)((int)piVar4 + 0x61) == '\0') {
        piVar2 = (int *)piVar4[2];
        if (*(char *)((int)piVar2 + 0x61) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x61);
          piVar4 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x61);
            piVar4 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar4[1] + 0x61);
          piVar3 = (int *)piVar4[1];
          piVar2 = piVar4;
          while ((piVar4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar4[2]))) {
            cVar1 = *(char *)(piVar4[1] + 0x61);
            piVar3 = (int *)piVar4[1];
            piVar2 = piVar4;
          }
        }
      }
    }
    FUN_005569f0(auStack_70,0);
    if (0xf < uStack_58) {
      _free(pvStack_6c);
      return;
    }
  }
  return;
}


// ==== FUN_006921f0 @ 0x006921f0 ====

void FUN_006921f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dce4c;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  FUN_00691f40();
  return;
}


// ==== FUN_00692210 @ 0x00692210 ====

uint FUN_00692210(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_00692040(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00692240 @ 0x00692240 ====

undefined4 FUN_00692240(void)

{
  return 0x51;
}


// ==== FUN_00692250 @ 0x00692250 ====

void FUN_00692250(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009dce4c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00692290 @ 0x00692290 ====

void FUN_00692290(void)

{
  return;
}


// ==== FUN_006922c0 @ 0x006922c0 ====

void FUN_006922c0(void)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
  pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
  cVar1 = *pcVar3;
  (**(code **)(*piVar2 + 0x24))(cVar1 == '\0');
  if ((cVar1 == '\0') && (*(int *)(in_ECX + 8) != 0)) {
    puVar4 = operator_new(8);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = &PTR_FUN_009b1798;
    }
    uVar5 = (**(code **)(**(int **)(in_ECX + 8) + 4))();
    puVar4[1] = uVar5;
    FUN_00797a20(puVar4);
  }
  return;
}


// ==== FUN_00692350 @ 0x00692350 ====

void FUN_00692350(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 uStack_38;
  void *pvStack_34;
  undefined4 uStack_30;
  undefined4 uStack_24;
  uint uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    piVar1 = (int *)(**(code **)(*DAT_00b5a72c + 0xc))();
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x30))();
    iVar2 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x14))();
    uStack_38 = *(undefined4 *)(iVar2 + 8);
    uStack_30 = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = *(int *)(iVar2 + 0x14) - *(int *)(iVar2 + 0xc);
    if (*(char *)(in_ECX + 0x10) == '\0') {
      iVar3 = (**(code **)(*piVar1 + 4))();
    }
    else {
      iVar3 = (**(code **)(*piVar1 + 4))();
      if (*(int *)(in_ECX + 0x14) <= iVar3) {
        iVar3 = *(int *)(in_ECX + 0x14);
      }
    }
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    for (iVar2 = iVar3 - ((int)(iVar2 + (iVar2 >> 0x1f & 0xfU)) >> 4); iVar2 < iVar3;
        iVar2 = iVar2 + 1) {
      if (-1 < iVar2) {
        uVar4 = (**(code **)(*piVar1 + 8))(&uStack_38,iVar2);
        FUN_00401ff0(uVar4,0,0xffffffff);
        if (0xf < uStack_20) {
          _free(pvStack_34);
          return;
        }
        uStack_20 = 0xf;
        uStack_24 = 0;
        pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
      }
      FUN_004020e0(&DAT_009dcefc,1);
    }
    FUN_005569f0(auStack_1c,0);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
  }
  return;
}


// ==== FUN_00692470 @ 0x00692470 ====

/* WARNING: Removing unreachable block (ram,0x00692549) */
/* WARNING: Removing unreachable block (ram,0x0069258a) */
/* WARNING: Removing unreachable block (ram,0x006924cd) */

void FUN_00692470(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  undefined4 uStack_30;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006daf60();
  }
  uStack_30 = s_UI_Console_UI_Main_txt_009dceb8;
  *(undefined4 *)(in_ECX + 0x2c) = uVar2;
  FUN_00401740();
  uStack_30 = (char *)0x6924c1;
  iVar3 = FUN_00410500();
  uStack_30 = (char *)(iVar3 + 0x3c);
  piVar4 = (int *)(**(code **)(*DAT_00b5a798 + 4))();
  *(int **)(in_ECX + 4) = piVar4;
  (**(code **)(*piVar4 + 0x40))();
  (**(code **)(**(int **)(in_ECX + 4) + 0x48))(*(undefined4 *)(in_ECX + 0x2c));
  if (iVar3 != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar3);
  }
  FUN_00401740(s_text_out_009dced0,8);
  uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x2c);
  *(undefined4 *)(in_ECX + 0xc) = uVar2;
  FUN_00401740(s_edit_command_009dcedc,0xc);
  uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_30);
  *(undefined4 *)(in_ECX + 8) = uVar2;
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006dae80(in_ECX);
  }
  *(undefined4 *)(in_ECX + 0x30) = uVar2;
  (**(code **)(*DAT_00b5a79c + 4))(uVar2);
  return;
}


// ==== FUN_006925d0 @ 0x006925d0 ====

uint FUN_006925d0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_00692350(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00692600 @ 0x00692600 ====

void FUN_00692600(char param_1)

{
  int iVar1;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  if ((*(int *)(in_ECX + 0x1c) != 0) &&
     ((*(int *)(in_ECX + 0x20) - *(int *)(in_ECX + 0x1c)) / 0x1c != 0)) {
    if (param_1 == '\0') {
      if (*(int *)(in_ECX + 0x28) == *(int *)(in_ECX + 0x20)) {
        return;
      }
      *(int *)(in_ECX + 0x28) = *(int *)(in_ECX + 0x28) + 0x1c;
    }
    else {
      if (*(int *)(in_ECX + 0x28) == *(int *)(in_ECX + 0x1c)) {
        return;
      }
      *(int *)(in_ECX + 0x28) = *(int *)(in_ECX + 0x28) + -0x1c;
    }
    iVar1 = *(int *)(in_ECX + 0x28);
    if (iVar1 == *(int *)(in_ECX + 0x20)) {
      FUN_00401830(&DAT_009dcf07);
      if (*(int *)(in_ECX + 8) != 0) {
        (**(code **)(**(int **)(in_ECX + 8) + 0x30))();
        FUN_00551410(local_1c);
      }
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
    }
    else if (*(int *)(in_ECX + 8) != 0) {
      (**(code **)(**(int **)(in_ECX + 8) + 0x30))();
      FUN_00551410(iVar1);
    }
  }
  return;
}


// ==== FUN_006926c0 @ 0x006926c0 ====

void FUN_006926c0(void)

{
  undefined4 uVar1;
  undefined4 ****ppppuVar2;
  undefined4 *in_ECX;
  int iVar3;
  undefined4 *unaff_EBX;
  uint uVar4;
  uint uVar5;
  undefined4 ****ppppuVar6;
  undefined4 *puVar7;
  undefined4 *puStack_ac;
  undefined4 uStack_a8;
  undefined4 *puStack_a4;
  undefined4 uStack_a0;
  undefined4 ****appppuStack_9c [4];
  uint uStack_8c;
  uint uStack_88;
  undefined1 auStack_84 [4];
  undefined4 ****appppuStack_80 [4];
  uint uStack_70;
  uint uStack_6c;
  undefined4 *puStack_68;
  int *piStack_64;
  undefined4 *local_60;
  undefined4 uStack_5c;
  void *pvStack_58;
  undefined1 auStack_54 [4];
  undefined1 uStack_50;
  uint uStack_44;
  undefined4 uStack_40;
  void *pvStack_3c;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  
  local_60 = in_ECX;
  uStack_5c = (**(code **)(*DAT_00b5a72c + 0xc))();
  (**(code **)(*(int *)in_ECX[2] + 0x30))();
  uVar1 = FUN_00550150();
  pvStack_3c = (void *)0xf;
  uStack_40 = 0;
  uStack_50 = 0;
  FUN_00401660(uVar1,0,0xffffffff);
  uStack_a8 = 0;
  puStack_a4 = (undefined4 *)0x0;
  uStack_a0 = 0;
  (**(code **)(*DAT_00b5a7d8 + 0x10))(auStack_54,&puStack_ac);
  if (unaff_EBX != (undefined4 *)0x0) {
    iVar3 = (int)puStack_ac - (int)unaff_EBX >> 2;
    if (iVar3 == 0) {
      _free(unaff_EBX);
      return;
    }
    if (iVar3 == 1) {
      uVar1 = FUN_00402220(auStack_24,*unaff_EBX,&DAT_009dcf00);
      FUN_00551410(uVar1);
      if (0xf < uStack_c) {
        _free(pvStack_20);
        return;
      }
    }
    else {
      local_60 = puStack_ac;
      uStack_88 = 0xf;
      uStack_8c = 0;
      appppuStack_9c[0] = (undefined4 ****)((uint)appppuStack_9c[0] & 0xffffff00);
      puStack_a4 = unaff_EBX;
      FUN_00401660(*unaff_EBX,0,0xffffffff);
      puVar7 = unaff_EBX;
      if (unaff_EBX != puStack_ac) {
        do {
          uStack_6c = 0xf;
          uStack_70 = 0;
          appppuStack_80[0] = (undefined4 ****)((uint)appppuStack_80[0] & 0xffffff00);
          FUN_00401660(*puVar7,0,0xffffffff);
          uVar4 = uStack_70;
          if (uStack_8c <= uStack_70) {
            uVar4 = uStack_8c;
          }
          uVar5 = 0;
          if (uVar4 != 0) {
            do {
              if (uStack_8c <= uVar5) {
                FUN_0079dba3();
              }
              ppppuVar6 = appppuStack_9c[0];
              if (uStack_88 < 0x10) {
                ppppuVar6 = appppuStack_9c;
              }
              if (uStack_70 <= uVar5) {
                FUN_0079dba3();
              }
              ppppuVar2 = appppuStack_80[0];
              if (uStack_6c < 0x10) {
                ppppuVar2 = appppuStack_80;
              }
            } while ((*(char *)((int)ppppuVar6 + uVar5) == *(char *)((int)ppppuVar2 + uVar5)) &&
                    (uVar5 = uVar5 + 1, uVar5 < uVar4));
            puVar7 = puStack_a4;
          }
          uStack_28 = 0xf;
          uStack_2c = 0;
          pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
          FUN_00401660(&uStack_a0,0,uVar5);
          FUN_00401660(&uStack_40,0,0xffffffff);
          if (0xf < uStack_28) {
            _free(pvStack_3c);
            return;
          }
          uStack_28 = 0xf;
          iVar3 = *piStack_64;
          uStack_2c = 0;
          pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
          uVar1 = FUN_004022a0(auStack_24,&DAT_009dcf04,auStack_84);
          (**(code **)(iVar3 + 0xc))(uVar1);
          if (0xf < uStack_c) {
            _free(pvStack_20);
            return;
          }
          uStack_c = 0xf;
          uStack_10 = 0;
          pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
          if (0xf < uStack_6c) {
            _free(appppuStack_80[0]);
            return;
          }
          puStack_a4 = puVar7 + 1;
          uStack_6c = 0xf;
          uStack_70 = 0;
          appppuStack_80[0] = (undefined4 ****)((uint)appppuStack_80[0] & 0xffffff00);
          puVar7 = puStack_a4;
        } while (puStack_a4 != local_60);
        in_ECX = puStack_68;
      }
      if (in_ECX[2] != 0) {
        (**(code **)(*(int *)in_ECX[2] + 0x30))();
        FUN_00551410(&uStack_a0);
      }
      if (0xf < uStack_88) {
        _free(appppuStack_9c[0]);
        return;
      }
      uStack_88 = 0xf;
      uStack_8c = 0;
      appppuStack_9c[0] = (undefined4 ****)((uint)appppuStack_9c[0] & 0xffffff00);
    }
    if (unaff_EBX != (undefined4 *)0x0) {
      _free(unaff_EBX);
      return;
    }
  }
  puStack_ac = (undefined4 *)0x0;
  uStack_a8 = 0;
  if (uStack_44 < 0x10) {
    return;
  }
  _free(pvStack_58);
  return;
}


// ==== FUN_006929f0 @ 0x006929f0 ====

void FUN_006929f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dcf10;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[1] = 0;
  in_ECX[3] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  in_ECX[5] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  FUN_00692470();
  return;
}


// ==== FUN_00692a30 @ 0x00692a30 ====

void FUN_00692a30(void)

{
  undefined4 *in_ECX;
  undefined4 unaff_ESI;
  
  *in_ECX = &PTR_FUN_009dcf10;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  (**(code **)(*DAT_00b5a79c + 0xc))(in_ECX[0xc]);
  if ((undefined4 *)in_ECX[0xc] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xc])(1);
  }
  in_ECX[0xc] = 0;
  if ((undefined4 *)in_ECX[0xb] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xb])(1);
  }
  in_ECX[0xb] = 0;
  if (in_ECX[7] == 0) {
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    in_ECX[9] = 0;
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  FUN_00405de0(in_ECX[7],in_ECX[8],in_ECX + 6,unaff_ESI);
  _free((void *)in_ECX[7]);
  return;
}


// ==== FUN_00692ac0 @ 0x00692ac0 ====

void FUN_00692ac0(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1c) != 0) {
    if ((*(int *)(in_ECX + 0x20) - *(int *)(in_ECX + 0x1c)) / 0x1c != 0) {
      iVar2 = *(int *)(in_ECX + 0x20);
      if (*(uint *)(iVar2 + -4) < 0x10) {
        iVar1 = iVar2 + -0x18;
      }
      else {
        iVar1 = *(int *)(iVar2 + -0x18);
      }
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),iVar1,*(undefined4 *)(iVar2 + -8));
      if (iVar2 == 0) {
        *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(in_ECX + 0x20);
        return;
      }
    }
  }
  FUN_00406720(param_1);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(in_ECX + 0x20);
  return;
}


// ==== FUN_00692b40 @ 0x00692b40 ====

undefined4 FUN_00692b40(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  undefined4 uStack_38;
  undefined1 uStack_34;
  uint uStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  if ((param_1 == 2) && (param_3 == 4)) {
    iVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_edit_command_009dceec,0xc);
    if (iVar1 == 0) {
      (**(code **)(**(int **)(in_ECX + 8) + 0x30))();
      uVar2 = FUN_00550150();
      uStack_20 = 0xf;
      uStack_24 = 0;
      uStack_34 = 0;
      FUN_00401660(uVar2,0,0xffffffff);
      FUN_00401830(&DAT_009dcef9);
      FUN_00551410(auStack_1c);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return extraout_EAX;
      }
      (**(code **)(*DAT_00b5a72c + 4))(&uStack_38);
      FUN_00692ac0(auStack_1c + -0x20);
      if (uStack_24 < 0x10) {
        return 1;
      }
      _free(uStack_38);
      return extraout_EAX_00;
    }
  }
  return 0;
}


// ==== FUN_00692c30 @ 0x00692c30 ====

undefined4 FUN_00692c30(void)

{
  return 0x50;
}


// ==== FUN_00692c40 @ 0x00692c40 ====

void FUN_00692c40(byte param_1)

{
  void *in_ECX;
  
  FUN_00692a30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00692c60 @ 0x00692c60 ====

void FUN_00692c60(void)

{
  return;
}


// ==== FUN_00692c70 @ 0x00692c70 ====

undefined1 FUN_00692c70(void)

{
  return 0;
}


// ==== FUN_00692c80 @ 0x00692c80 ====

void FUN_00692c80(int param_1)

{
  char cVar1;
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 8) + 0x30))();
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(param_1 + 8);
  cVar1 = *(char *)(param_1 + 4);
  *(char *)(in_ECX + 0x10) = cVar1;
  if (cVar1 == '\0') {
    FUN_00587d10(0);
    *(undefined1 *)(in_ECX + 0x11) = 1;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    return;
  }
  FUN_00587d10(0xff);
  *(undefined1 *)(in_ECX + 0x11) = 1;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  return;
}


// ==== FUN_00692d00 @ 0x00692d00 ====

void FUN_00692d00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dcfa8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00692d20 @ 0x00692d20 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00692d20(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x11) != '\0') && (*(uint *)(param_1 + 4) < 0x3e9)) {
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + *(uint *)(param_1 + 4);
    (**(code **)(**(int **)(in_ECX + 8) + 0x30))();
    if (*(uint *)(in_ECX + 0x18) < *(uint *)(in_ECX + 0x14)) {
      *(undefined1 *)(in_ECX + 0x11) = 0;
      if (*(char *)(in_ECX + 0x10) == '\0') {
        FUN_00587d10(0xff);
        return;
      }
      FUN_00587d10(0);
      return;
    }
    uVar1 = FUN_00802534();
    FUN_00587d10(uVar1);
  }
  return;
}


// ==== FUN_00692e10 @ 0x00692e10 ====

uint FUN_00692e10(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_00692d20(param_1);
  }
  else if (uVar1 == 0x30050012) {
    uVar1 = FUN_00692c80(param_1);
    return uVar1 & 0xffffff00;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00692e50 @ 0x00692e50 ====

void FUN_00692e50(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  void *unaff_EDI;
  undefined1 auStack_34 [4];
  undefined1 local_1c [4];
  void *local_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_fadewnd_txt_009dcf7c,0x17);
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
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740(s_pan_back_009dcf94,8);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_34 + 0xc);
  *(undefined4 *)(in_ECX + 8) = uVar3;
  if (uStack_14 < 0x10) {
    return;
  }
  _free(unaff_EDI);
  return;
}


// ==== FUN_00692f20 @ 0x00692f20 ====

void FUN_00692f20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dcfa8;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  *(undefined1 *)((int)in_ECX + 0x11) = 0;
  *(undefined1 *)(in_ECX + 4) = 1;
  in_ECX[6] = 0;
  in_ECX[5] = 0;
  FUN_00692e50();
  return;
}


// ==== FUN_00692f50 @ 0x00692f50 ====

undefined4 FUN_00692f50(void)

{
  return 0x3d;
}


// ==== FUN_00692f60 @ 0x00692f60 ====

void FUN_00692f60(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009dcfa8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00692fa0 @ 0x00692fa0 ====

undefined4 FUN_00692fa0(void)

{
  return 0x70460000;
}


// ==== FUN_00692fb0 @ 0x00692fb0 ====

void FUN_00692fb0(void)

{
  return;
}


// ==== FUN_00692fc0 @ 0x00692fc0 ====

undefined4 FUN_00692fc0(void)

{
  undefined4 *puVar1;
  
  (**(code **)(*DAT_00b5ae74 + 0x14))();
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar1 = &PTR_FUN_009d7740;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_00693080 @ 0x00693080 ====

void FUN_00693080(undefined4 param_1)

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


// ==== FUN_006930e0 @ 0x006930e0 ====

void FUN_006930e0(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  void *unaff_EBX;
  undefined1 local_38 [4];
  undefined1 local_34;
  uint uStack_28;
  undefined4 local_24;
  undefined4 local_20;
  void *local_1c;
  void *local_18;
  undefined4 uStack_c;
  uint uStack_8;
  uint local_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_pan_list__d_check_009dd350,0x11);
  uVar2 = FUN_00404230(&local_1c);
  FUN_00401660(uVar2,0,0xffffffff);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_38);
  if (piVar3 == (int *)0x0) {
    uStack_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009dd364,0x12);
    FUN_00406880(&local_20);
    if (uStack_8 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_1c);
    return;
  }
  (**(code **)(*piVar3 + 0x24))(param_1);
  if (uStack_28 < 0x10) {
    return;
  }
  _free(unaff_EBX);
  return;
}


// ==== FUN_006931d0 @ 0x006931d0 ====

void FUN_006931d0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int *unaff_retaddr;
  undefined4 uStack_28;
  uint uStack_24;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_select_item_009dd3a4,0xb);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (local_8 < 0x10) {
    local_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    (**(code **)(*piVar1 + 0x30))();
    (**(code **)(*unaff_retaddr + 0x1c))();
    iVar2 = (**(code **)(*unaff_retaddr + 0x2c))();
    uStack_24 = (uint)*(byte *)(iVar2 + 0x31);
    uStack_28 = (uint)*(byte *)(iVar2 + 0x30);
    FUN_005802c0((int)register0x00000010 + -0x2c,&uStack_28);
    FUN_00580870(unaff_retaddr,1);
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_00693280 @ 0x00693280 ====

void FUN_00693280(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int in_ECX;
  int *unaff_retaddr;
  undefined4 uVar5;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_itemDesc_009dd3b0,8);
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
      uVar3 = (**(code **)(*unaff_retaddr + 0x1c))();
      FUN_00552610(0);
      uVar5 = 0;
      uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(0,uVar3 & 0xffff | 0x3840000,0);
      FUN_005569f0(uVar4,uVar5);
    }
  }
  return;
}


// ==== FUN_00693330 @ 0x00693330 ====

void FUN_00693330(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  void *unaff_EBP;
  undefined1 auStack_ac [2];
  undefined1 auStack_aa [2];
  void *pvStack_a8;
  undefined4 uStack_a4;
  uint uStack_a0;
  void *pvStack_98;
  uint uStack_94;
  undefined1 uStack_90;
  uint uStack_84;
  undefined4 uStack_80;
  void *pvStack_7c;
  undefined1 auStack_78 [12];
  undefined4 uStack_6c;
  void *pvStack_68;
  undefined1 auStack_64 [16];
  uint uStack_54;
  void *pvStack_4c;
  undefined1 auStack_48 [16];
  uint uStack_38;
  void *pvStack_2c;
  undefined1 auStack_28 [16];
  uint uStack_18;
  
  iVar2 = (**(code **)(*DAT_00b5ad20 + 0x18))(*(undefined4 *)(in_ECX + 8));
  if (iVar2 != 0x50a) {
    uStack_94 = 0xf;
    pvStack_98 = (void *)0x0;
    pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
    FUN_00401740(s_btn_preView_009dd3bc,0xb);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_ac);
    piVar3 = (int *)(**(code **)(*piVar3 + 0x30))();
    (**(code **)(*piVar3 + 0x28))(0);
    if (0xf < uStack_94) {
      _free(pvStack_a8);
      return;
    }
  }
  if (iVar2 == 0x10) {
    iVar2 = *DAT_00b5acac;
    uVar4 = (**(code **)(*DAT_00b5a97c + 0xc))();
    cVar1 = (**(code **)(iVar2 + 0x38))(uVar4);
    if (cVar1 == '\0') {
      pvStack_7c = (void *)0xf;
      uStack_80 = 0;
      uStack_90 = 0;
      FUN_00401740(s_btn_buy_009dd3d0,7);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_94);
      piVar3 = (int *)(**(code **)(*piVar3 + 0x30))();
      (**(code **)(*piVar3 + 0x28))(0);
      if (0xf < uStack_84) {
        _free(pvStack_98);
        return;
      }
    }
    else {
      iVar2 = *DAT_00b5acac;
      uVar4 = (**(code **)(*DAT_00b5a97c + 0xc))();
      cVar1 = (**(code **)(iVar2 + 0x44))(uVar4);
      if (cVar1 != '\0') {
        FUN_00401830(s_btn_buy_009dd3c8);
        piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_28);
        piVar3 = (int *)(**(code **)(*piVar3 + 0x30))();
        (**(code **)(*piVar3 + 0x28))(1);
        if (0xf < uStack_18) {
          _free(pvStack_2c);
          return;
        }
      }
    }
  }
  else if (iVar2 == 0x50a) {
    cVar1 = (**(code **)(*DAT_00b5ad20 + 0x34))(*(undefined4 *)(in_ECX + 8));
    if (cVar1 == '\0') {
      FUN_00401830(s_btn_preView_009dd3ec);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_78);
      piVar3 = (int *)(**(code **)(*piVar3 + 0x30))();
      (**(code **)(*piVar3 + 0x28))(0);
      if ((void *)0xf < pvStack_68) {
        _free(pvStack_7c);
        return;
      }
      pvStack_68 = (void *)0xf;
      uStack_6c = 0;
      pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
      FUN_00401830(s_btn_buy_009dd3f8);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_48);
      piVar3 = (int *)(**(code **)(*piVar3 + 0x30))();
      (**(code **)(*piVar3 + 0x28))(0);
      if (0xf < uStack_38) {
        _free(pvStack_4c);
        return;
      }
    }
    else {
      FUN_00401830(s_btn_preView_009dd3d8);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_ac + -4);
      piVar3 = (int *)(**(code **)(*piVar3 + 0x30))();
      (**(code **)(*piVar3 + 0x28))(1);
      if (0xf < uStack_a0) {
        _free(unaff_EBP);
        return;
      }
      uStack_a0 = 0xf;
      uStack_a4 = 0;
      FUN_00401830(s_btn_buy_009dd3e4);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_64);
      piVar3 = (int *)(**(code **)(*piVar3 + 0x30))();
      (**(code **)(*piVar3 + 0x28))(1);
      if (0xf < uStack_54) {
        _free(pvStack_68);
        return;
      }
    }
  }
  return;
}


// ==== FUN_00693610 @ 0x00693610 ====

/* WARNING: Removing unreachable block (ram,0x006936b7) */

void FUN_00693610(void *param_1)

{
  int *piVar1;
  int in_ECX;
  uint in_stack_00000018;
  undefined4 in_stack_0000001c;
  undefined1 auStack_32 [50];
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&param_1);
  if (piVar1 == (int *)0x0) {
    if (0xf < in_stack_00000018) {
      _free(param_1);
      return;
    }
  }
  else {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x30))();
    if (piVar1 != (int *)0x0) {
      FUN_0056fe50(auStack_32 + -6);
      (**(code **)(*piVar1 + 8))(auStack_32 + -6);
    }
    if (0xf < in_stack_00000018) {
      _free(param_1);
      return;
    }
  }
  return;
}


// ==== FUN_006936f0 @ 0x006936f0 ====

void FUN_006936f0(void)

{
  undefined4 uVar1;
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
  FUN_00401740(s_lbl_name__d_009dd378,0xb);
  uVar1 = FUN_00404230(local_1c);
  FUN_00401660(uVar1,0,0xffffffff);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401660(local_38,0,0xffffffff);
  FUN_00693610();
  FUN_00401740(s_lbl_volume__d_009dd384,0xd);
  uVar1 = FUN_00404230(local_1c);
  FUN_00401660(uVar1,0,0xffffffff);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401660(local_38,0,0xffffffff);
  FUN_00693610();
  FUN_00401740(s_lbl_price__d_009dd394,0xc);
  uVar1 = FUN_00404230(local_1c);
  FUN_00401660(uVar1,0,0xffffffff);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401660(local_38,0,0xffffffff);
  FUN_00693610();
  if (local_20 < 0x10) {
    return;
  }
  _free(local_34);
  return;
}


// ==== FUN_00693890 @ 0x00693890 ====

void FUN_00693890(void)

{
  undefined4 *in_ECX;
  undefined4 unaff_EBX;
  
  *in_ECX = &PTR_FUN_009dd42c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if (0xf < (uint)in_ECX[0x17]) {
    _free((void *)in_ECX[0x12]);
    return;
  }
  in_ECX[0x17] = 0xf;
  in_ECX[0x16] = 0;
  *(undefined1 *)(in_ECX + 0x12) = 0;
  if (in_ECX[0xe] != 0) {
    FUN_00405de0(in_ECX[0xe],in_ECX[0xf],in_ECX + 0xd,unaff_EBX);
    _free((void *)in_ECX[0xe]);
    return;
  }
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  if ((uint)in_ECX[0xb] < 0x10) {
    in_ECX[10] = 0;
    in_ECX[0xb] = 0xf;
    *(undefined1 *)(in_ECX + 6) = 0;
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_00693930 @ 0x00693930 ====

undefined4 FUN_00693930(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  ushort *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int *in_ECX;
  undefined *puVar7;
  undefined4 uVar8;
  undefined1 local_88 [4];
  int local_84;
  int local_80;
  undefined4 local_7c;
  int iStack_78;
  undefined1 local_70;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 auStack_1c [28];
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      cVar1 = FUN_004036a0(param_2,s_btn_exit_009dd1c8);
      if (cVar1 != '\0') {
        (**(code **)(*in_ECX + 0x10))();
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_buy_009dd1d4);
      if (cVar1 != '\0') {
        if (in_ECX[2] != 0) {
          puVar3 = (undefined2 *)(**(code **)(*(int *)in_ECX[2] + 0x14))();
          uVar2 = CONCAT22((short)((uint)puVar3 >> 0x10),*puVar3);
          (**(code **)(*DAT_00b5ae74 + 0x48))
                    (CONCAT31((int3)((uint)uVar2 >> 8),(char)in_ECX[0xc]),uVar2,1);
        }
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_giftItem_009dd1dc);
      if (cVar1 != '\0') {
        if (in_ECX[2] != 0) {
          puVar3 = (undefined2 *)(**(code **)(*(int *)in_ECX[2] + 0x14))();
          uVar2 = CONCAT22((short)((uint)puVar3 >> 0x10),*puVar3);
          (**(code **)(*DAT_00b5ae74 + 0x48))
                    (CONCAT31((int3)((uint)uVar2 >> 8),(char)in_ECX[0xc]),uVar2,5);
        }
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_preView_009dd1ec);
      if (cVar1 != '\0') {
        cVar1 = (**(code **)(*DAT_00b5ae74 + 100))();
        if ((cVar1 != '\x01') && (in_ECX[2] != 0)) {
          puVar4 = (ushort *)(**(code **)(*(int *)in_ECX[2] + 0x14))();
          uVar2 = (**(code **)(*DAT_00b5ad20 + 0xc))(*puVar4);
          iVar5 = (**(code **)(*DAT_00b5ad20 + 0x18))(uVar2);
          if (iVar5 == 0x50a) {
            puVar6 = operator_new(8);
            if (puVar6 == (undefined4 *)0x0) {
              puVar6 = (undefined4 *)0x0;
            }
            else {
              *puVar6 = &PTR_FUN_009dd418;
            }
            puVar6[1] = (uint)*puVar4;
            FUN_00797a20(puVar6);
            return 1;
          }
        }
        return 1;
      }
      local_84 = 0;
      local_80 = 0;
      local_7c = 0;
      FUN_00404fb0(param_2,0x5f,local_88);
      puVar7 = &DAT_009dd1f8;
      uVar2 = FUN_00405d30(1);
      cVar1 = FUN_004036a0(uVar2,puVar7);
      if (cVar1 != '\0') {
        local_5c = 0xf;
        local_60 = 0;
        local_70 = 0;
        iStack_78 = (**(code **)(*DAT_00b5ae74 + 0x30))();
        if (iStack_78 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        FUN_00401830(s_btn_list__d_009dd200);
        uVar2 = FUN_00404230(auStack_1c);
        FUN_00401660(uVar2,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    else if (param_3 == 4) {
      local_84 = 0;
      local_80 = 0;
      local_7c = 0;
      FUN_00404fb0(param_2,0x5f,local_88);
      if ((local_84 != 0) && (2 < (uint)((local_80 - local_84) / 0x1c))) {
        puVar7 = &DAT_009dd20c;
        uVar2 = FUN_00405d30(1);
        cVar1 = FUN_004036a0(uVar2,puVar7);
        if (cVar1 != '\0') {
          uVar8 = 1;
          uVar2 = FUN_00405d30(2);
          uVar2 = thunk_FUN_00796fb0(uVar2,uVar8);
          FUN_006936f0(uVar2,uVar8);
        }
        FUN_00406250();
        return 1;
      }
    }
    else {
      if (param_3 != 5) {
        return 0;
      }
      local_84 = 0;
      local_80 = 0;
      local_7c = 0;
      FUN_00404fb0(param_2,0x5f,local_88);
      if ((local_84 != 0) && (2 < (uint)((local_80 - local_84) / 0x1c))) {
        puVar7 = &DAT_009dd214;
        uVar2 = FUN_00405d30(1);
        cVar1 = FUN_004036a0(uVar2,puVar7);
        if (cVar1 != '\0') {
          uVar8 = 0;
          uVar2 = FUN_00405d30(2);
          uVar2 = thunk_FUN_00796fb0(uVar2,uVar8);
          FUN_006936f0(uVar2,uVar8);
        }
        FUN_00406250();
        return 1;
      }
    }
    FUN_00406250();
  }
  return 0;
}


// ==== FUN_00693da0 @ 0x00693da0 ====

/* WARNING: Removing unreachable block (ram,0x00693e2d) */

void FUN_00693da0(undefined4 param_1,byte *param_2,ushort param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  ushort uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 auStack_1a [26];
  
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
  uVar2 = (**(code **)(*in_ECX + 0x14))();
  uVar6 = 0xffffffff;
  uVar5 = 0;
  puVar1[0x14] = uVar2;
  uVar2 = 0x693e0d;
  FUN_00401660(param_1,0,0xffffffff);
  uVar4 = 0xff;
  if (param_3 < 0x100) {
    uVar4 = param_3;
  }
  *(ushort *)(puVar1 + 0x13) = (ushort)*param_2 << 8 | uVar4;
  switch(param_3) {
  case 1:
  case 2:
  case 3:
  case 5:
  case 6:
  case 7:
    FUN_00406600(in_ECX + 0xd);
    FUN_00664110(uVar2,param_1,uVar5,uVar6);
    FUN_00797a20(puVar1);
    return;
  case 4:
  case 8:
    iVar3 = (**(code **)(*DAT_00b5a6d4 + 8))();
    if (iVar3 == 0) {
      uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x38400d1);
      FUN_00765c50(uVar2);
      goto LAB_00693edf;
    }
    uVar2 = 0x38400ce;
    break;
  case 9:
    uVar2 = 0x38400e6;
    break;
  default:
    FUN_00797a20(puVar1);
    return;
  }
  uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,uVar2);
  FUN_00765c50(uVar2);
LAB_00693edf:
  FUN_00401660(auStack_1a + -10,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00693f20 @ 0x00693f20 ====

int FUN_00693f20(int *param_1)

{
  int iVar1;
  uint3 uVar4;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  int extraout_EAX;
  int extraout_EAX_00;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 uStack_349;
  undefined1 auStack_348 [4];
  void *pvStack_344;
  undefined4 uStack_334;
  uint uStack_330;
  undefined1 auStack_32c [4];
  void *pvStack_328;
  uint uStack_314;
  undefined1 auStack_310 [28];
  undefined1 auStack_2f4 [56];
  undefined1 auStack_2bc [28];
  undefined1 auStack_2a0 [28];
  undefined1 auStack_284 [28];
  undefined1 auStack_268 [84];
  undefined1 auStack_214 [28];
  undefined1 auStack_1f8 [56];
  undefined1 auStack_1c0 [28];
  undefined1 auStack_1a4 [84];
  undefined1 auStack_150 [112];
  undefined1 auStack_e0 [28];
  undefined1 auStack_c4 [196];
  
  iVar1 = (**(code **)(*param_1 + 4))();
  uVar4 = (uint3)((uint)(iVar1 + -0x70380002) >> 8);
  switch(iVar1) {
  case 0x70380002:
    FUN_00401830(s_lbl_curMycash_009dd138);
    uVar3 = (**(code **)(*DAT_00b5ae74 + 0x44))();
    uVar3 = FUN_004041a0(auStack_348,uVar3);
    FUN_00693080(auStack_32c,uVar3);
    if (0xf < uStack_330) {
      _free(pvStack_344);
      return extraout_EAX;
    }
    uStack_330 = 0xf;
    uStack_334 = 0;
    pvStack_344 = (void *)((uint)pvStack_344 & 0xffffff00);
    if (uStack_314 < 0x10) {
      return 1;
    }
    _free(pvStack_328);
    return extraout_EAX_00;
  default:
    return (uint)uVar4 << 8;
  case 0x70380010:
    break;
  case 0x70380021:
    if (*(int *)(in_ECX + 8) == 0) {
      return CONCAT31(uVar4,1);
    }
    uVar2 = (**(code **)(*DAT_00b5ae74 + 0x44))();
    if (uVar2 < *(uint *)(in_ECX + 0xc)) {
      uStack_349 = 0x21;
      FUN_00401830(s_cashItem_ui_errcash_txt_009dd148);
      FUN_00693da0(auStack_284,&uStack_349,10);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    FUN_00406250();
    uVar3 = (**(code **)(*DAT_00b5ad20 + 0x40))(auStack_1a4,*(undefined4 *)(in_ECX + 8));
    FUN_00406720(uVar3);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 0x70380022:
    if (*(int *)(in_ECX + 8) == 0) {
      return CONCAT31(uVar4,1);
    }
    uVar2 = (**(code **)(*DAT_00b5ae74 + 0x44))();
    if (uVar2 < *(uint *)(in_ECX + 0xc)) {
      uStack_349 = 0x21;
      FUN_00401830(s_cashItem_ui_errcash_txt_009dd188);
      FUN_00693da0(auStack_214,&uStack_349,10);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    FUN_00406250();
    uVar3 = (**(code **)(*DAT_00b5ad20 + 0x40))(auStack_c4,*(undefined4 *)(in_ECX + 8));
    FUN_00406720(uVar3);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  switch(param_1[1]) {
  case 0:
    FUN_00406250();
    iVar1 = (**(code **)(*DAT_00b5ad20 + 0xc))(CONCAT22(extraout_var,(short)param_1[9]));
    if (iVar1 != 0) {
      uVar3 = (**(code **)(*DAT_00b5ad20 + 0x40))(auStack_1c0,iVar1);
      FUN_00406720(uVar3);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  default:
switchD_00693f62_default:
    FUN_00401830(s_lbl_curMycash_009dd128);
    uVar3 = (**(code **)(*DAT_00b5ae74 + 0x44))();
    uVar3 = FUN_004041a0(auStack_e0,uVar3);
    FUN_00693080(auStack_2bc,uVar3);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 1:
    FUN_00406250();
    iVar1 = (**(code **)(*DAT_00b5ad20 + 0xc))(CONCAT22(extraout_var_00,(short)param_1[9]));
    if (iVar1 != 0) {
      FUN_00401830(&DAT_009dd078);
      uVar3 = FUN_00404230(auStack_150);
      FUN_00406720(uVar3);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    goto switchD_00693f62_default;
  case 2:
    uStack_349 = 0x21;
    FUN_00401830(s_cashItem_ui_errcharacter_txt_009dd0a0);
    FUN_00693da0(auStack_1f8,&uStack_349,0xe);
    break;
  case 3:
    uStack_349 = 0x21;
    FUN_00401830(s_cashItem_ui_errpwd_txt_009dd0c0);
    FUN_00693da0(auStack_2a0,&uStack_349,0xb);
    break;
  case 4:
    uStack_349 = 0x21;
    FUN_00401830(s_cashItem_ui_errpwd_txt_009dd0d8);
    FUN_00693da0(auStack_310,&uStack_349,0xc);
    break;
  case 5:
    uStack_349 = 0x21;
    FUN_00401830(s_cashItem_ui_errInventory_txt_009dd0f0);
    FUN_00693da0(auStack_268,&uStack_349,0xd);
    break;
  case 6:
    uStack_349 = 0x21;
    FUN_00401830(s_cashItem_ui_errcash_txt_009dd110);
    FUN_00693da0(auStack_2f4,&uStack_349,10);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_006946e0 @ 0x006946e0 ====

undefined4 FUN_006946e0(int param_1,ushort param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  int *in_ECX;
  undefined2 extraout_var;
  undefined1 auStack_190 [3];
  undefined1 uStack_18d;
  int *piStack_18c;
  undefined1 auStack_16c [28];
  undefined1 auStack_150 [84];
  undefined1 auStack_fc [28];
  undefined1 auStack_e0 [28];
  undefined1 auStack_c4 [28];
  undefined1 auStack_a8 [168];
  
  iVar2 = (**(code **)(*in_ECX + 0x14))();
  if (param_1 != iVar2) {
    return 0;
  }
  if (param_3 != 1) {
    return 1;
  }
  switch(param_2 - 1) {
  case 0:
    if (in_ECX[2] != 0) {
      (**(code **)(*DAT_00b5ae74 + 0x44))();
      FUN_00406250();
      uVar3 = (**(code **)(*DAT_00b5ad20 + 0x40))(auStack_c4,in_ECX[2]);
      FUN_00406720(uVar3);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    break;
  case 1:
    cVar1 = (**(code **)(*DAT_00b5a97c + 0x14))();
    if (cVar1 == '\0') {
      uStack_18d = 0x21;
      FUN_00401830(s_cashItem_ui_pwdcheck_txt_009dd284);
      FUN_00693da0(auStack_150,&uStack_18d,4);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    goto LAB_00694c37;
  case 3:
    cVar1 = (**(code **)(*DAT_00b5a97c + 0x14))();
    if (cVar1 != '\0') goto LAB_00694c37;
    if (in_ECX[2] != 0) {
      puVar4 = (undefined2 *)(**(code **)(*(int *)in_ECX[2] + 0x14))();
      iVar2 = *DAT_00b5ae74;
      FUN_00765c50(param_4);
      (**(code **)(iVar2 + 0x58))(CONCAT22(extraout_var,*puVar4));
      return 1;
    }
    break;
  case 4:
    uVar3 = FUN_00404170(auStack_a8,param_4);
    piStack_18c = in_ECX + 0x11;
    FUN_00401660(uVar3,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 5:
    cVar1 = (**(code **)(*DAT_00b5a97c + 0x14))();
    if (cVar1 == '\0') {
      uStack_18d = 0x21;
      FUN_00401830(s_cashItem_ui_pwdcheck_txt_009dd268);
      FUN_00693da0(auStack_fc,&uStack_18d,8);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    goto LAB_00694b8f;
  case 7:
    cVar1 = (**(code **)(*DAT_00b5a97c + 0x14))();
    if (cVar1 != '\0') {
      uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(5,0x650044);
      FUN_00765c50(uVar3);
      iVar2 = *DAT_00b5ad0c;
      FUN_00765c50(auStack_190);
      (**(code **)(iVar2 + 0x28))(2);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    if (in_ECX[2] != 0) {
      (**(code **)(*(int *)in_ECX[2] + 0x14))();
      iVar2 = *DAT_00b5ae74;
      FUN_00765c50(param_4);
      FUN_00765c50(in_ECX + 0x11);
      (**(code **)(iVar2 + 0x60))();
    }
    break;
  case 10:
    cVar1 = (**(code **)(*DAT_00b5a97c + 0x14))();
    if (cVar1 == '\0') {
      uStack_18d = 0x21;
      FUN_00401830(s_cashItem_ui_pwdcheck_txt_009dd2a0);
      FUN_00693da0(auStack_16c,&uStack_18d,4);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
LAB_00694c37:
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(5,0x650043);
    FUN_00765c50(uVar3);
    iVar2 = *DAT_00b5ad0c;
    FUN_00765c50(auStack_190);
    (**(code **)(iVar2 + 0x28))(2);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 0xb:
    cVar1 = (**(code **)(*DAT_00b5a97c + 0x14))();
    if (cVar1 == '\0') {
      uStack_18d = 0x21;
      FUN_00401830(s_cashItem_ui_pwdcheck_txt_009dd2bc);
      FUN_00693da0(auStack_e0,&uStack_18d,8);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
LAB_00694b8f:
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(5,0x650044);
    FUN_00765c50(uVar3);
    iVar2 = *DAT_00b5ad0c;
    FUN_00765c50(auStack_190);
    (**(code **)(iVar2 + 0x28))(2);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  return 1;
}


// ==== FUN_00694dc0 @ 0x00694dc0 ====

void FUN_00694dc0(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  void *pvVar6;
  int *piVar7;
  int in_ECX;
  int iVar8;
  int *unaff_ESI;
  int *unaff_EDI;
  undefined4 *puVar9;
  int *piVar10;
  undefined1 auStack_286 [2];
  undefined4 uStack_274;
  undefined1 uStack_270;
  undefined1 uStack_26f;
  undefined1 uStack_26e;
  undefined4 uStack_26c;
  undefined4 uStack_268;
  undefined4 uStack_264;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  undefined4 uStack_254;
  void *pvStack_24c;
  undefined4 uStack_23c;
  uint uStack_238;
  undefined1 auStack_224 [12];
  undefined1 auStack_218 [16];
  undefined1 auStack_208 [8];
  undefined1 auStack_200 [4];
  void *pvStack_1fc;
  undefined4 uStack_1ec;
  uint uStack_1e8;
  undefined4 uStack_1e4;
  void *pvStack_1e0;
  uint uStack_1dc;
  undefined1 auStack_1d8 [4];
  int *piStack_1d4;
  int *piStack_1d0;
  uint uStack_1cc;
  undefined4 uStack_1c8;
  void *pvStack_1a8;
  undefined1 uStack_1a4;
  undefined4 uStack_198;
  uint uStack_194;
  undefined4 uStack_190;
  undefined1 auStack_174 [4];
  void *pvStack_170;
  void *pvStack_16c;
  undefined4 uStack_160;
  uint uStack_15c;
  uint uStack_158;
  undefined4 auStack_b0 [43];
  
  uVar2 = (**(code **)(*DAT_00b5ae78 + 0x1c))();
  uVar2 = (**(code **)(*DAT_00b5ae78 + 0xc))(uVar2);
  FUN_00696200(uVar2);
  uStack_190 = 0xf;
  uStack_194 = 0;
  uStack_1a4 = 0;
  FUN_00401740(s_pan_itemlist_009dd2d8,0xc);
  (**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1a8);
  if (0xf < uStack_194) {
    _free(pvStack_1a8);
    return;
  }
  uStack_194 = 0xf;
  uStack_198 = 0;
  pvStack_1a8 = (void *)((uint)pvStack_1a8 & 0xffffff00);
  uStack_26e = 1;
  uStack_26c = 0;
  uStack_268 = 0;
  uStack_264 = 0;
  uStack_260 = 0;
  uStack_25c = 0;
  uStack_258 = 0;
  uStack_254 = 0;
  uStack_238 = 0xf;
  uStack_23c = 0;
  pvStack_24c = (void *)((uint)pvStack_24c & 0xffffff00);
  uStack_1e8 = 0xf;
  uStack_1ec = 0;
  pvStack_1fc = (void *)((uint)pvStack_1fc & 0xffffff00);
  uStack_1e4 = 0;
  pvStack_1e0 = (void *)0x0;
  uStack_1dc = 0;
  piVar7 = piStack_1d4;
  if (piStack_1d4 != piStack_1d0) {
    do {
      if ((int *)*piVar7 != (int *)0x0) {
        puVar3 = (undefined4 *)(**(code **)(*(int *)*piVar7 + 0x2c))();
        puVar9 = auStack_b0;
        for (iVar8 = 0x27; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar9 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar9 = puVar9 + 1;
        }
        piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
        if ((piVar4 != (int *)0x0) &&
           (piVar5 = (int *)(**(code **)(*DAT_00b5a7ac + 8))(1), piVar5 != (int *)0x0)) {
          FUN_00401740(s_btn_list__d_009dd2e8,0xb);
          uVar2 = FUN_00404230(auStack_174);
          FUN_00401660(uVar2,0,0xffffffff);
          if (0xf < uStack_15c) {
            _free(pvStack_170);
            return;
          }
          uStack_15c = 0xf;
          uStack_160 = 0;
          pvStack_170 = (void *)((uint)pvStack_170 & 0xffffff00);
          FUN_00401660(auStack_200,0,0xffffffff);
          uStack_268 = 0;
          uStack_264 = 5;
          uStack_25c = 0x14;
          uStack_260 = 0x122;
          uStack_26c = 100;
          uStack_270 = 1;
          uStack_26f = 1;
          pvVar6 = operator_new(0x468);
          if (pvVar6 == (void *)0x0) {
            piVar7 = (int *)0x0;
          }
          else {
            piVar7 = (int *)FUN_00505f10();
          }
          *(undefined1 *)(piVar7 + 0x41) = 0;
          *(undefined1 *)((int)piVar7 + 0x105) = 0;
          *(undefined1 *)((int)piVar7 + 0x107) = 0;
          *(undefined1 *)(piVar7 + 0x43) = 0;
          piVar7[0x42] = 0xc;
          piVar7[0x44] = 500;
          *(undefined1 *)((int)piVar7 + 0x106) = 0;
          (**(code **)(*piVar4 + 8))(&uStack_270);
          if ((unaff_ESI != (int *)0x0) &&
             (cVar1 = (**(code **)(*piVar4 + 0x74))(unaff_ESI), cVar1 != '\0')) {
            cVar1 = (**(code **)(*unaff_ESI + 0x78))(piVar4);
            if (cVar1 == '\0') {
              (**(code **)(*piVar4 + 0x74))(0);
            }
            else {
              iVar8 = (**(code **)(*unaff_EDI + 0x38))();
              piVar4[1] = iVar8;
            }
          }
          (**(code **)(*piVar5 + 0x38))(piVar4);
          (**(code **)(*piVar5 + 0x1c))(auStack_208);
          piVar10 = piVar5;
          (**(code **)(*piVar4 + 0x2c))();
          piVar4 = piVar7;
          (**(code **)(*piVar5 + 0x24))();
          if (piVar7 != (int *)0x0) {
            FUN_00505d80();
            _free(piVar7);
            return;
          }
          (**(code **)(*DAT_00b5a7ac + 4))();
          piVar7 = (int *)(**(code **)(*DAT_00b5a7ac + 8))(0);
          FUN_00401740(s_pan_list__d_009dd2f4,0xb);
          uVar2 = FUN_00404230(&pvStack_170);
          FUN_00401660(uVar2,0,0xffffffff);
          if (0xf < uStack_158) {
            _free(pvStack_16c);
            return;
          }
          uStack_158 = 0xf;
          uStack_15c = 0;
          pvStack_16c = (void *)((uint)pvStack_16c & 0xffffff00);
          FUN_00401660(auStack_218,0,0xffffffff);
          pvVar6 = operator_new(0x468);
          if (pvVar6 == (void *)0x0) {
            pvVar6 = (void *)0x0;
          }
          else {
            pvVar6 = (void *)FUN_00505f10();
          }
          FUN_00503950(*(undefined4 *)(*(int *)((int)pvVar6 + 0x11c) + 4));
          *(int *)(*(int *)((int)pvVar6 + 0x11c) + 4) = *(int *)((int)pvVar6 + 0x11c);
          *(undefined4 *)((int)pvVar6 + 0x120) = 0;
          *(undefined4 *)*(undefined4 *)((int)pvVar6 + 0x11c) = *(undefined4 *)((int)pvVar6 + 0x11c)
          ;
          *(int *)(*(int *)((int)pvVar6 + 0x11c) + 8) = *(int *)((int)pvVar6 + 0x11c);
          *(undefined1 *)((int)pvVar6 + 0x114) = 0;
          *(undefined1 *)((int)pvVar6 + 0x115) = 0;
          uStack_1c8 = 0xf;
          uStack_1cc = 0;
          uStack_1dc = uStack_1dc & 0xffffff00;
          FUN_00401740(s_etc_01_009dd300,6);
          uVar2 = (**(code **)(*DAT_00b5a7c0 + 8))(&pvStack_1e0);
          *(undefined4 *)((int)pvVar6 + 4) = uVar2;
          if (0xf < uStack_1cc) {
            _free(pvStack_1e0);
            return;
          }
          uStack_1cc = 0xf;
          *(undefined4 *)((int)pvVar6 + 8) = 0x3b;
          piStack_1d0 = (int *)0x0;
          pvStack_1e0 = (void *)((uint)pvStack_1e0 & 0xffffff00);
          (**(code **)(*unaff_EDI + 8))(auStack_286 + -6);
          if ((piVar10 != (int *)0x0) &&
             (cVar1 = (**(code **)(*unaff_EDI + 0x74))(piVar10), cVar1 != '\0')) {
            cVar1 = (**(code **)(*piVar10 + 0x78))(unaff_EDI);
            if (cVar1 == '\0') {
              (**(code **)(*unaff_EDI + 0x74))(0);
            }
            else {
              iVar8 = (**(code **)(*piVar4 + 0x38))();
              unaff_EDI[1] = iVar8;
            }
          }
          (**(code **)(*piVar7 + 0x38))(unaff_EDI);
          (**(code **)(*piVar7 + 0x1c))(auStack_224);
          (**(code **)(*unaff_EDI + 0x2c))(piVar7);
          (**(code **)(*piVar7 + 0x24))(pvVar6);
          FUN_00505d80();
          _free(pvVar6);
          return;
        }
      }
      piVar7 = piVar7 + 0xb;
    } while (piVar7 != piStack_1d0);
    if (0xf < uStack_1e8) {
      _free(pvStack_1fc);
      return;
    }
    piVar7 = piStack_1d4;
  }
  uStack_1e8 = 0xf;
  uStack_1ec = 0;
  pvStack_1fc = (void *)((uint)pvStack_1fc & 0xffffff00);
  if (0xf < uStack_238) {
    _free(pvStack_24c);
    return;
  }
  uStack_238 = 0xf;
  uStack_23c = 0;
  pvStack_24c = (void *)((uint)pvStack_24c & 0xffffff00);
  if (piVar7 == (int *)0x0) {
    return;
  }
  FUN_00695fb0(piVar7,piStack_1d0,auStack_1d8,uStack_274);
  _free(piVar7);
  return;
}


// ==== FUN_00695c10 @ 0x00695c10 ====

/* WARNING: Removing unreachable block (ram,0x00695d12) */

void FUN_00695c10(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  undefined1 auStack_84 [4];
  int *piVar4;
  undefined1 auStack_66 [30];
  undefined1 local_48 [4];
  void *local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  void *pvStack_38;
  undefined4 local_34;
  void *local_30;
  undefined4 uStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined1 uStack_18;
  
  local_30 = (void *)0xf;
  local_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  FUN_00401740(s_UI_Game2_NewCashShop_ui_NewCashS_009dd014,0x2d);
  iVar1 = FUN_00410500(local_48);
  if (0xf < local_30) {
    _free(local_44);
    return;
  }
  piVar4 = (int *)0x0;
  local_30 = (void *)0xf;
  local_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  *(undefined4 *)(in_ECX + 8) = 0;
  FUN_00401740(s_lbl_curMycash_009dd044,0xd);
  uVar3 = (**(code **)(*DAT_00b5ae74 + 0x44))();
  uVar3 = FUN_004041a0(&pvStack_38,uVar3);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_66 + -10);
  if ((piVar2 != (int *)0x0) && (iVar1 = (**(code **)(*piVar2 + 0x30))(), iVar1 != 0)) {
    FUN_0055a260(uVar3);
  }
  if (0xf < uStack_24) {
    _free(pvStack_38);
    return;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  FUN_00694dc0();
  iVar1 = *DAT_00b5ae78;
  uVar3 = (**(code **)(*DAT_00b5ae78 + 0x1c))();
  uVar3 = (**(code **)(iVar1 + 0xc))(uVar3);
  FUN_00696200(uVar3);
  if ((unaff_ESI != (undefined4 *)0x0) &&
     (iVar1 = unaff_EBP - (int)unaff_ESI >> 0x1f,
     (unaff_EBP - (int)unaff_ESI) / 0x2c + iVar1 != iVar1)) {
    uStack_40 = *unaff_ESI;
    uStack_3c = unaff_ESI[1];
    pvStack_38 = (void *)CONCAT22(pvStack_38._2_2_,*(undefined2 *)(unaff_ESI + 2));
    uStack_1c = 0xf;
    uStack_20 = 0;
    local_30 = (void *)((uint)local_30 & 0xffffff00);
    FUN_00401660(unaff_ESI + 3,0,0xffffffff);
    uStack_18 = *(undefined1 *)(unaff_ESI + 10);
    *(undefined4 *)(in_ECX + 8) = uStack_40;
    *(undefined2 *)(in_ECX + 0x10) = pvStack_38._0_2_;
    *(undefined4 *)(in_ECX + 0xc) = uStack_3c;
    FUN_00401660(&local_34,0,0xffffffff);
    *(undefined1 *)(in_ECX + 0x30) = uStack_18;
    FUN_00693280(uStack_40);
    FUN_006931d0(uStack_40);
    FUN_006930e0(0,1);
    FUN_00693330();
    if (0xf < uStack_1c) {
      _free(local_30);
      return;
    }
  }
  piVar2 = piVar4;
  if (piVar4 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar4 + 4))();
    *(undefined4 *)(iVar1 + 0x28) = 0;
    (**(code **)(*DAT_00b5a7cc + 0x2c))(piVar4);
  }
  if (unaff_ESI == (undefined4 *)0x0) {
    return;
  }
  FUN_00695fb0(unaff_ESI,unaff_EBP,auStack_84 + 0xc,piVar2);
  _free(unaff_ESI);
  return;
}


// ==== FUN_00695e60 @ 0x00695e60 ====

void FUN_00695e60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dd42c;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0xf;
  *(undefined1 *)(in_ECX + 6) = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x17] = 0xf;
  in_ECX[0x16] = 0;
  *(undefined1 *)(in_ECX + 0x12) = 0;
  in_ECX[1] = 0;
  FUN_00695c10();
  return;
}


// ==== FUN_00695ef0 @ 0x00695ef0 ====

void FUN_00695ef0(int param_1)

{
  if (*(uint *)(param_1 + 0x24) < 0x10) {
    *(undefined4 *)(param_1 + 0x24) = 0xf;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined1 *)(param_1 + 0x10) = 0;
    return;
  }
  _free(*(void **)(param_1 + 0x10));
  return;
}


// ==== FUN_00695f20 @ 0x00695f20 ====

void FUN_00695f20(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_2 + 2);
    param_1[9] = 0xf;
    param_1[8] = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(param_2 + 3,0,0xffffffff);
    *(undefined1 *)(param_1 + 10) = *(undefined1 *)(param_2 + 10);
  }
  return;
}


// ==== FUN_00695fb0 @ 0x00695fb0 ====

void FUN_00695fb0(int param_1,int param_2)

{
  uint *puVar1;
  
  if (param_1 != param_2) {
    puVar1 = (uint *)(param_1 + 0x24);
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


// ==== FUN_00696000 @ 0x00696000 ====

void FUN_00696000(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_2 + 2);
    param_1[9] = 0xf;
    param_1[8] = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(param_2 + 3,0,0xffffffff);
    *(undefined1 *)(param_1 + 10) = *(undefined1 *)(param_2 + 10);
  }
  return;
}


// ==== FUN_00696050 @ 0x00696050 ====

int FUN_00696050(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if (param_1 < (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x2c)) {
      return iVar1 + param_1 * 0x2c;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0085b340();
}


// ==== FUN_00696090 @ 0x00696090 ====

undefined4 FUN_00696090(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x5d1745d < param_1) {
    param_1 = FUN_0085b3b0();
  }
  pvVar1 = operator_new(param_1 * 0x2c);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x2c + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_006960f0 @ 0x006960f0 ====

int FUN_006960f0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c700;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x2c) {
    FUN_00696000(param_3,param_1);
    param_3 = param_3 + 0x2c;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0069615a @ 0x0069615a ====

void Catch_0069615a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x2c) {
    FUN_00695ef0(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00696180 @ 0x00696180 ====

void FUN_00696180(undefined4 param_1,undefined4 param_2)

{
  FUN_00695fb0(param_1,param_2);
  return;
}


// ==== FUN_006961a0 @ 0x006961a0 ====

void FUN_006961a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  FUN_00695fb0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_006961e0 @ 0x006961e0 ====

void FUN_006961e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_006960f0(param_1,param_2,param_3);
  return;
}


// ==== FUN_00696200 @ 0x00696200 ====

void FUN_00696200(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c710;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x2c;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_00696090(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_006961e0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00696297 @ 0x00696297 ====

void Catch_00696297(void)

{
  FUN_006961a0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006962b0 @ 0x006962b0 ====

void FUN_006962b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00693890();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006962d0 @ 0x006962d0 ====

void FUN_006962d0(void)

{
  return;
}


// ==== FUN_006962e0 @ 0x006962e0 ====

void FUN_006962e0(undefined4 param_1)

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


// ==== FUN_00696320 @ 0x00696320 ====

void FUN_00696320(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      FUN_00558730(param_1);
    }
  }
  return;
}


// ==== FUN_00696430 @ 0x00696430 ====

undefined4 FUN_00696430(void)

{
  undefined4 *puVar1;
  
  (**(code **)(*DAT_00b5b0d4 + 0x58))();
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar1 = &PTR_FUN_009d7740;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_006964f0 @ 0x006964f0 ====

/* WARNING: Removing unreachable block (ram,0x0069695f) */

void FUN_006964f0(void)

{
  undefined1 uVar1;
  char cVar2;
  byte bVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int in_ECX;
  uint uVar7;
  void **ppvVar8;
  void **ppvVar9;
  uint uVar10;
  uint uVar11;
  void *pvVar12;
  void *pvVar13;
  undefined1 auStack_176 [2];
  void *pvStack_160;
  uint uStack_15c;
  void *pvStack_158;
  uint uStack_14c;
  uint uStack_148;
  uint uStack_144;
  void *pvStack_140;
  void *pvStack_13c;
  void *pvStack_138;
  undefined1 auStack_134 [4];
  undefined4 uStack_130;
  uint uStack_12c;
  uint uStack_128;
  uint uStack_124;
  undefined4 uStack_120;
  void *pvStack_10c;
  undefined4 uStack_fc;
  void *pvStack_f8;
  char cStack_f1;
  uint uStack_f0;
  undefined1 auStack_ec [4];
  void *pvStack_e8;
  uint uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined1 auStack_d8 [12];
  void *apvStack_cc [2];
  void *pvStack_c4;
  undefined4 uStack_bc;
  void *pvStack_b8;
  undefined4 uStack_b4;
  uint uStack_b0;
  undefined4 uStack_a8;
  uint uStack_a4;
  void *apvStack_90 [4];
  undefined4 uStack_80;
  uint uStack_7c;
  void *pvStack_70;
  undefined1 auStack_68 [8];
  undefined4 uStack_60;
  uint uStack_5c;
  void *pvStack_54;
  undefined1 auStack_4c [8];
  undefined4 uStack_44;
  uint uStack_40;
  void *apvStack_3c [4];
  undefined4 uStack_2c;
  uint uStack_28;
  
  uVar1 = (**(code **)(*DAT_00b5b0d4 + 0x40))();
  pvStack_13c = (void *)CONCAT31(pvStack_13c._1_3_,uVar1);
  uVar1 = (**(code **)(*DAT_00b5b0d4 + 0x3c))();
  uStack_15c = CONCAT31(uStack_15c._1_3_,uVar1);
  uStack_120 = (**(code **)(*DAT_00b5b0d4 + 0x28))();
  uStack_dc = 0xf;
  uStack_e0 = 0;
  uStack_f0 = uStack_f0 & 0xffffff00;
  bVar3 = 0;
  do {
    FUN_00401740(s_btn_tab__d_009dd620,10);
    FUN_00404230(&uStack_15c);
    FUN_00401660();
    if (0xf < uStack_144) {
      _free(pvStack_158);
      return;
    }
    uStack_144 = 0xf;
    uStack_148 = 0;
    pvStack_158 = (void *)((uint)pvStack_158 & 0xffffff00);
    cVar2 = (**(code **)(*DAT_00b5b0d4 + 0x44))();
    if (cVar2 == '\0') {
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    }
    else {
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    }
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x44))();
    }
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if ((piVar4 != (int *)0x0) && (iVar5 = (**(code **)(*piVar4 + 0x30))(), iVar5 != 0)) {
      FUN_00558730();
    }
    bVar3 = bVar3 + 1;
  } while (bVar3 < 4);
  uVar7 = 0;
  do {
    pvVar13 = pvStack_160;
    uVar10 = uVar7;
    (**(code **)(*DAT_00b5b0d4 + 0x2c))(auStack_d8);
    pvVar12 = pvStack_e8;
    piVar4 = DAT_00b5ad20;
    if (pvStack_e8 == (void *)0x0) {
      FUN_00401740(s_btn_list__d_009dd67c,0xb);
      uVar6 = FUN_00404230(&uStack_14c);
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar6);
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x24))();
      }
      if (0xf < uStack_124) {
        _free(pvStack_138);
        return;
      }
      uStack_124 = 0xf;
      uStack_128 = 0;
      pvStack_138 = (void *)((uint)pvStack_138 & 0xffffff00);
    }
    else {
      uVar11 = 0x696696;
      FUN_00401740(s_lbl_name__d_009dd62c,0xb);
      FUN_00404230(auStack_68);
      uVar6 = (**(code **)(*piVar4 + 0x40))(auStack_4c);
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar10);
      if ((piVar4 != (int *)0x0) && (iVar5 = (**(code **)(*piVar4 + 0x30))(), iVar5 != 0)) {
        FUN_0055a260(uVar6);
      }
      if (0xf < uStack_5c) {
        _free(pvStack_70);
        return;
      }
      uStack_5c = 0xf;
      uStack_60 = 0;
      pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
      if (0xf < uStack_40) {
        _free(pvStack_54);
        return;
      }
      uStack_40 = 0xf;
      uStack_44 = 0;
      pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
      FUN_00401740(s_lbl_price__d_009dd638,0xc);
      ppvVar9 = apvStack_3c;
      uVar6 = FUN_00404230(ppvVar9);
      FUN_004041a0(apvStack_90,uStack_f0);
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar6);
      if ((piVar4 != (int *)0x0) && (iVar5 = (**(code **)(*piVar4 + 0x30))(), iVar5 != 0)) {
        FUN_0055a260(pvVar13);
      }
      if (0xf < uStack_28) {
        _free(apvStack_3c[0]);
        return;
      }
      uStack_28 = 0xf;
      uStack_2c = 0;
      apvStack_3c[0] = (void *)((uint)apvStack_3c[0] & 0xffffff00);
      if (0xf < uStack_7c) {
        _free(apvStack_90[0]);
        return;
      }
      uStack_7c = 0xf;
      uStack_80 = 0;
      apvStack_90[0] = (void *)((uint)apvStack_90[0] & 0xffffff00);
      uVar11 = uVar11 & 0xffffff00;
      FUN_00401740(s_lbl_cate__d_009dd648,0xb);
      ppvVar8 = apvStack_cc;
      uVar6 = FUN_00404230(ppvVar8,ppvVar9,uVar11);
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar6);
      if ((piVar4 != (int *)0x0) && (iVar5 = (**(code **)(*piVar4 + 0x30))(), iVar5 != 0)) {
        FUN_0055a260(auStack_ec);
      }
      if (0xf < pvStack_b8) {
        _free(apvStack_cc[0]);
        return;
      }
      pvStack_b8 = (void *)0xf;
      uStack_bc = 0;
      apvStack_cc[0] = (void *)((uint)apvStack_cc[0] & 0xffffff00);
      uVar10 = (uint)ppvVar9 & 0xffffff00;
      FUN_00401740(s_pan_icon__d_009dd654,0xb);
      FUN_00404230(auStack_134,ppvVar8,uVar10);
      if (cStack_f1 == '\0') {
        piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_134);
        if (piVar4 != (int *)0x0) {
          uVar6 = 0;
          goto LAB_0069699f;
        }
      }
      else {
        FUN_00401740(s_item_shop_icon_009dd660,0xe);
        piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_134);
        if ((piVar4 != (int *)0x0) && (iVar5 = (**(code **)(*piVar4 + 0x30))(), iVar5 != 0)) {
          uStack_144 = *(undefined4 *)(iVar5 + 0x8c);
          pvStack_140 = *(void **)(iVar5 + 0x90);
          pvStack_13c = pvVar12;
          uStack_144 = (**(code **)(*DAT_00b5a7c0 + 8))(auStack_176 + -0xe);
          FUN_00587d40(&uStack_148);
        }
        piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_138);
        if (piVar4 != (int *)0x0) {
          uVar6 = 1;
LAB_0069699f:
          (**(code **)(*piVar4 + 0x24))(uVar6);
        }
      }
      FUN_00401740(s_btn_list__d_009dd670,0xb);
      uVar6 = FUN_00404230(&uStack_bc);
      FUN_00401660(uVar6,0,0xffffffff);
      if (0xf < uStack_a4) {
        _free(pvStack_b8);
        return;
      }
      uStack_a4 = 0xf;
      uStack_a8 = 0;
      pvStack_b8 = (void *)((uint)pvStack_b8 & 0xffffff00);
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_13c);
      if ((piVar4 != (int *)0x0) && (iVar5 = (**(code **)(*piVar4 + 0x30))(), iVar5 != 0)) {
        FUN_00558730(0);
      }
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_140);
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x24))();
      }
      if ((void *)0xf < pvStack_f8) {
        _free(pvStack_10c);
        return;
      }
      pvStack_f8 = (void *)0xf;
      uStack_fc = 0;
      pvStack_10c = (void *)((uint)pvStack_10c & 0xffffff00);
    }
    if (0xf < uStack_b0) {
      _free(pvStack_c4);
      return;
    }
    uVar7 = uVar7 + 1;
    uStack_b0 = 0xf;
    uStack_b4 = 0;
    pvStack_c4 = (void *)((uint)pvStack_c4 & 0xffffff00);
    if (9 < uVar7) {
      FUN_00401740(s_btn_list__d_009dd688,0xb);
      FUN_00404230(&pvStack_13c);
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
      if ((piVar4 != (int *)0x0) && (iVar5 = (**(code **)(*piVar4 + 0x30))(), iVar5 != 0)) {
        FUN_00558730();
      }
      if (0xf < uStack_128) {
        _free(pvStack_13c);
        return;
      }
      uStack_148 = 0xf;
      uStack_14c = 0;
      uStack_15c = uStack_15c & 0xffffff00;
      FUN_00401740();
      FUN_00401740(s__d____d_009dd694,7);
      FUN_00404230(&pvStack_140);
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
      if ((piVar4 != (int *)0x0) && (iVar5 = (**(code **)(*piVar4 + 0x30))(), iVar5 != 0)) {
        FUN_0055a260();
      }
      if (0xf < uStack_12c) {
        _free(pvStack_140);
        return;
      }
      uStack_12c = 0xf;
      uStack_130 = 0;
      pvStack_140 = (void *)((uint)pvStack_140 & 0xffffff00);
      if (0xf < uStack_14c) {
        _free(pvStack_160);
        return;
      }
      if (uStack_e4 < 0x10) {
        return;
      }
      _free(pvStack_f8);
      return;
    }
  } while( true );
}


// ==== FUN_00696c50 @ 0x00696c50 ====

void FUN_00696c50(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int *unaff_retaddr;
  undefined4 uStack_28;
  uint uStack_24;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_select_item_009dd704,0xb);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (local_8 < 0x10) {
    local_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    (**(code **)(*piVar1 + 0x30))();
    (**(code **)(*unaff_retaddr + 0x1c))();
    iVar2 = (**(code **)(*unaff_retaddr + 0x2c))();
    uStack_24 = (uint)*(byte *)(iVar2 + 0x31);
    uStack_28 = (uint)*(byte *)(iVar2 + 0x30);
    FUN_005802c0((int)register0x00000010 + -0x2c,&uStack_28);
    FUN_00580870(unaff_retaddr,1);
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_00696d00 @ 0x00696d00 ====

/* WARNING: Removing unreachable block (ram,0x00696eea) */
/* WARNING: Removing unreachable block (ram,0x00696f29) */
/* WARNING: Removing unreachable block (ram,0x00696e58) */

void FUN_00696d00(void)

{
  char cVar1;
  undefined4 in_EAX;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int in_ECX;
  uint unaff_EBX;
  undefined4 uStack_84;
  uint uStack_80;
  void *pvStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_64;
  void *pvStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  void *pvStack_48;
  undefined4 uStack_44;
  int *piStack_3c;
  uint uStack_34;
  undefined1 auStack_2c [4];
  void *pvStack_28;
  uint uStack_14;
  
  piVar3 = DAT_00b5b0d4;
  uStack_78 = CONCAT31((int3)((uint)in_EAX >> 8),*(undefined1 *)(in_ECX + 0xc));
  iVar4 = *DAT_00b5b0d4;
  pvStack_7c = (void *)0x696d1e;
  pvStack_7c = (void *)(**(code **)(*DAT_00b5b0d4 + 0x40))();
  uStack_80 = 0x696d26;
  uStack_80 = (**(code **)(*piVar3 + 0x3c))();
  uStack_84 = auStack_2c;
  (**(code **)(iVar4 + 0x2c))();
  if (piStack_3c == (int *)0x0) {
LAB_00697066:
    if (uStack_14 < 0x10) {
      return;
    }
    _free(pvStack_28);
    return;
  }
  FUN_00696c50();
  uStack_5c = 0xf;
  pvStack_60 = (void *)0x0;
  FUN_00401740(s_lbl_itemName_009dd6a8);
  uVar2 = (**(code **)(*DAT_00b5ad20 + 0x40))(&uStack_58);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_7c);
  if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
    FUN_0055a260(uVar2);
  }
  if (0xf < uStack_4c) {
    _free(pvStack_60);
    return;
  }
  uStack_4c = 0xf;
  uStack_50 = 0;
  pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
  if (0xf < unaff_EBX) {
    _free(pvStack_7c);
    return;
  }
  pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
  FUN_00401740(s_lbl_cash_009dd6b8,8);
  uVar2 = FUN_004041a0(&uStack_64,uStack_44);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_80);
  if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
    FUN_0055a260(uVar2);
  }
  if (0xf < uStack_50) {
    _free(uStack_64);
    return;
  }
  uStack_50 = 0xf;
  uStack_54 = 0;
  uStack_64 = (void *)((uint)uStack_64 & 0xffffff00);
  uStack_80 = uStack_80 & 0xffffff00;
  FUN_00401740(s_lbl_curMycash_009dd6c4,0xd);
  uVar2 = (**(code **)(*DAT_00b5b0d4 + 0x4c))();
  uVar2 = FUN_004041a0(auStack_2c + -0x3c,uVar2);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_84);
  if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
    FUN_0055a260(uVar2);
  }
  if (0xf < uStack_54) {
    _free((void *)0xf);
    return;
  }
  uStack_54 = 0xf;
  uStack_58 = 0;
  uStack_84 = (undefined1 *)((uint)uStack_84 & 0xffffff00);
  FUN_00401740(s_itemDesc_009dd6d4,8);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_2c + -0x5c);
  uStack_78 = 0;
  if (piVar3 != (int *)0x0) {
    uVar2 = 0x696f4e;
    iVar4 = (**(code **)(*piVar3 + 0x30))();
    if (iVar4 == 0) goto LAB_00697066;
    uVar5 = (**(code **)(*piStack_3c + 0x1c))();
    FUN_00552610();
    uVar6 = (**(code **)(*DAT_00b5a794 + 0xc))(0,uVar5 & 0xffff | 0x3840000);
    FUN_005569f0(uVar6,uVar2);
  }
  iVar4 = (**(code **)(*DAT_00b5ad20 + 0x18))(uStack_54);
  if (iVar4 != 0x50a) {
    FUN_00401830(s_btn_preView_009dd6e0);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_2c + -0x48);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x44))(0);
    }
    if (0xf < pvStack_60) {
      _free((void *)0xf);
      return;
    }
    if (uStack_34 < 0x10) {
      return;
    }
    _free(pvStack_48);
    return;
  }
  cVar1 = (**(code **)(*DAT_00b5ad20 + 0x34))(uStack_58);
  if (cVar1 == '\0') {
    FUN_00401830(s_btn_preView_009dd6f8);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_78);
    if (piVar3 == (int *)0x0) goto LAB_0069705d;
    uVar2 = 0;
  }
  else {
    FUN_00401830(s_btn_preView_009dd6ec);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_78);
    if (piVar3 == (int *)0x0) goto LAB_0069705d;
    uVar2 = 1;
  }
  (**(code **)(*piVar3 + 0x44))(uVar2);
LAB_0069705d:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00697090 @ 0x00697090 ====

void FUN_00697090(void)

{
  FUN_006964f0();
  FUN_00696d00();
  return;
}


// ==== FUN_006970a0 @ 0x006970a0 ====

void FUN_006970a0(void)

{
  undefined4 *in_ECX;
  undefined4 unaff_EBX;
  
  *in_ECX = &PTR_FUN_009dd8e0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if (0xf < (uint)in_ECX[0xe]) {
    _free((void *)in_ECX[9]);
    return;
  }
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
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


// ==== FUN_00697120 @ 0x00697120 ====

/* WARNING: Removing unreachable block (ram,0x006971ad) */

void FUN_00697120(undefined4 param_1,byte *param_2,ushort param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  ushort uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 auStack_1a [26];
  
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
  uVar2 = (**(code **)(*in_ECX + 0x14))();
  uVar6 = 0xffffffff;
  uVar5 = 0;
  puVar1[0x14] = uVar2;
  uVar2 = 0x69718d;
  FUN_00401660(param_1,0,0xffffffff);
  uVar4 = 0xff;
  if (param_3 < 0x100) {
    uVar4 = param_3;
  }
  *(ushort *)(puVar1 + 0x13) = (ushort)*param_2 << 8 | uVar4;
  switch(param_3) {
  case 1:
  case 2:
  case 3:
  case 5:
  case 6:
  case 7:
    FUN_00406600(in_ECX + 4);
    FUN_00664110(uVar2,param_1,uVar5,uVar6);
    FUN_00797a20(puVar1);
    return;
  case 4:
  case 8:
    iVar3 = (**(code **)(*DAT_00b5a6d4 + 8))();
    if (iVar3 == 0) {
      uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x38400d1);
      FUN_00765c50(uVar2);
      goto LAB_0069725f;
    }
    uVar2 = 0x38400ce;
    break;
  case 9:
    uVar2 = 0x38400e6;
    break;
  default:
    FUN_00797a20(puVar1);
    return;
  }
  uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,uVar2);
  FUN_00765c50(uVar2);
LAB_0069725f:
  FUN_00401660(auStack_1a + -10,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_006972a0 @ 0x006972a0 ====

undefined4 FUN_006972a0(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  int iVar3;
  undefined4 extraout_EAX;
  uint uVar4;
  undefined4 extraout_EAX_00;
  int in_ECX;
  uint unaff_EBP;
  int unaff_ESI;
  undefined1 uStack_306;
  undefined1 uStack_305;
  undefined1 auStack_304 [4];
  void *pvStack_300;
  uint uStack_2ec;
  undefined1 auStack_2d8 [28];
  undefined1 auStack_2bc [12];
  undefined1 auStack_2b0 [44];
  undefined1 auStack_284 [68];
  undefined1 auStack_240 [44];
  undefined1 auStack_214 [56];
  undefined1 auStack_1dc [136];
  undefined1 auStack_154 [72];
  undefined1 auStack_10c [28];
  undefined1 auStack_f0 [208];
  undefined1 auStack_20 [32];
  
  uVar2 = (**(code **)(*param_1 + 4))();
  piVar1 = DAT_00b5b0d4;
  switch(uVar2) {
  case 0x70380002:
    FUN_006964f0();
    FUN_00696d00();
    return 1;
  default:
    return 0;
  case 0x70380010:
    switch(param_1[1]) {
    case 0:
      FUN_00406250();
      iVar3 = (**(code **)(*DAT_00b5ad20 + 0xc))(CONCAT22(extraout_var,(short)param_1[9]));
      if (iVar3 != 0) {
        uVar2 = (**(code **)(*DAT_00b5ad20 + 0x40))(auStack_20,iVar3);
        FUN_00406720(uVar2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      break;
    case 1:
      FUN_00406250();
      iVar3 = (**(code **)(*DAT_00b5ad20 + 0xc))(CONCAT22(extraout_var_00,(short)param_1[9]));
      if (iVar3 != 0) {
        FUN_00401830(&DAT_009dd4f0);
        uVar2 = FUN_00404230(auStack_154);
        FUN_00406720(uVar2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      break;
    case 2:
      uStack_305 = 0x21;
      FUN_00401830(s_cashItem_ui_errcharacter_txt_009dd518);
      FUN_00697120(auStack_1dc,&uStack_305,0xe);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 3:
      uStack_305 = 0x21;
      FUN_00401830(s_cashItem_ui_errpwd_txt_009dd538);
      FUN_00697120(auStack_284,&uStack_305,0xb);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 4:
      uStack_305 = 0x21;
      FUN_00401830(s_cashItem_ui_errpwd_txt_009dd550);
      FUN_00697120(auStack_214,&uStack_305,0xc);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 5:
      uStack_305 = 0x21;
      FUN_00401830(s_cashItem_ui_errInventory_txt_009dd568);
      FUN_00697120(auStack_2d8,&uStack_305,0xd);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 6:
      uStack_305 = 0x21;
      FUN_00401830(s_cashItem_ui_errcash_txt_009dd588);
      FUN_00697120(auStack_2bc,&uStack_305,10);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    return 1;
  case 0x70380021:
    iVar3 = *DAT_00b5b0d4;
    uVar2 = (**(code **)(*DAT_00b5b0d4 + 0x40))(*(undefined1 *)(in_ECX + 0xc));
    uVar2 = (**(code **)(*piVar1 + 0x3c))(uVar2);
    (**(code **)(iVar3 + 0x2c))(auStack_304,uVar2);
    if (unaff_ESI != 0) {
      uVar4 = (**(code **)(*DAT_00b5b0d4 + 0x4c))();
      if (uVar4 < unaff_EBP) {
        FUN_00401830(s_cashItem_ui_errcash_txt_009dd5a0);
        FUN_00697120(auStack_2b0,auStack_304 + -0x11,10);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      FUN_00406250();
      uVar2 = (**(code **)(*DAT_00b5ad20 + 0x40))(auStack_f0,unaff_ESI);
      FUN_00406720(uVar2);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    if (0xf < uStack_2ec) {
      _free(pvStack_300);
      return extraout_EAX;
    }
    break;
  case 0x70380022:
    iVar3 = *DAT_00b5b0d4;
    uVar2 = (**(code **)(*DAT_00b5b0d4 + 0x40))(*(undefined1 *)(in_ECX + 0xc));
    uVar2 = (**(code **)(*piVar1 + 0x3c))(uVar2);
    (**(code **)(iVar3 + 0x2c))(auStack_304,uVar2);
    if (unaff_ESI != 0) {
      uVar4 = (**(code **)(*DAT_00b5b0d4 + 0x4c))();
      if (uVar4 < unaff_EBP) {
        FUN_00401830(s_cashItem_ui_errcash_txt_009dd5e0);
        FUN_00697120(auStack_240,auStack_304 + -0x11,10);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      FUN_00406250();
      uVar2 = (**(code **)(*DAT_00b5ad20 + 0x40))(auStack_10c,unaff_ESI);
      FUN_00406720(uVar2);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    if (0xf < uStack_2ec) {
      _free(pvStack_300);
      return extraout_EAX_00;
    }
  }
  return 1;
}


// ==== FUN_00697a60 @ 0x00697a60 ====

undefined4 FUN_00697a60(int param_1,int param_2,int param_3)

{
  int *piVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined2 *puVar8;
  uint uVar9;
  uint uVar10;
  ushort *puVar11;
  undefined4 *puVar12;
  undefined4 extraout_EAX;
  int *in_ECX;
  undefined2 extraout_var;
  undefined4 uVar13;
  undefined *puVar14;
  undefined1 local_3c [4];
  void *local_38;
  undefined4 local_34;
  undefined4 local_30;
  int *local_2c [3];
  undefined4 uStack_20;
  
  iVar7 = param_2;
  if (param_1 != 1) {
    if (param_1 != 0xf) {
      return 0;
    }
    local_38 = (void *)0x0;
    local_34 = 0;
    local_30 = 0;
    FUN_00404fb0(param_2,0x5f,local_3c);
    if (local_38 == (void *)0x0) {
      return 1;
    }
    FUN_00405de0(local_38,local_34,local_3c,param_2);
    _free(local_38);
    return extraout_EAX;
  }
  if (param_3 != 1) {
    return 0;
  }
  local_38 = (void *)0x0;
  local_34 = 0;
  local_30 = 0;
  FUN_00404fb0(param_2,0x5f,local_3c);
  iVar5 = FUN_00405d30(1);
  iVar5 = FUN_00403620(0,*(undefined4 *)(iVar5 + 0x14),&DAT_009dd710,4);
  if (iVar5 == 0) {
    uVar6 = FUN_00405d30(2);
    iVar7 = thunk_FUN_00796fb0(uVar6);
    if (in_ECX[3] != iVar7) {
      uVar13 = 0;
      FUN_00401830(s_btn_list__d_009dd718);
      uVar6 = FUN_00404230(local_2c);
      FUN_00696320(uVar6,uVar13);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    goto LAB_00697e97;
  }
  puVar14 = &DAT_009dd724;
  uVar6 = FUN_00405d30(1);
  cVar2 = FUN_004036a0(uVar6,puVar14);
  if (cVar2 != '\0') {
    uVar6 = FUN_00405d30(2);
    cVar2 = thunk_FUN_00796f50(uVar6);
    param_2 = CONCAT31(param_2._1_3_,cVar2);
    cVar3 = (**(code **)(*DAT_00b5b0d4 + 0x3c))();
    if (cVar2 != cVar3) {
      (**(code **)(*DAT_00b5b0d4 + 0x34))(param_2);
      (**(code **)(*DAT_00b5b0d4 + 0x38))(0);
      in_ECX[3] = 0;
      FUN_006964f0();
      FUN_00696d00();
      FUN_00406250();
      return 1;
    }
    goto LAB_00697e97;
  }
  cVar2 = FUN_004036a0(iVar7,s_btn_buyInfo_009dd728);
  if (cVar2 != '\0') {
    FUN_006962e0(iVar7,0);
    param_2 = CONCAT31(param_2._1_3_,0x21);
    FUN_00401830(s_cashItem_ui_buyInfo_txt_009dd734);
    FUN_00697120(local_2c,&param_2,9);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  cVar2 = FUN_004036a0(iVar7,s_btn_exit_009dd74c);
  if (cVar2 != '\0') {
    (**(code **)(*in_ECX + 0x10))();
    FUN_00406250();
    return 1;
  }
  cVar2 = FUN_004036a0(iVar7,s_btn_buy_009dd758);
  piVar1 = DAT_00b5b0d4;
  if (cVar2 == '\0') {
    cVar2 = FUN_004036a0(iVar7,s_btn_giftItem_009dd760);
    piVar1 = DAT_00b5b0d4;
    if (cVar2 == '\0') {
      cVar2 = FUN_004036a0(iVar7,s_btn_rightArrow_009dd770);
      if (cVar2 == '\0') {
        cVar2 = FUN_004036a0(iVar7,s_btn_leftArrow_009dd780);
        if (cVar2 == '\0') {
          cVar2 = FUN_004036a0(iVar7,s_btn_preView_009dd790);
          if (cVar2 == '\0') {
            FUN_00406250();
            return 0;
          }
          cVar2 = (**(code **)(*DAT_00b5b0d4 + 0x6c))();
          piVar1 = DAT_00b5b0d4;
          if (cVar2 == '\x01') goto LAB_00697e97;
          param_2 = *DAT_00b5b0d4;
          uVar6 = (**(code **)(*DAT_00b5b0d4 + 0x40))((char)in_ECX[3]);
          uVar6 = (**(code **)(*piVar1 + 0x3c))(uVar6);
          (**(code **)(param_2 + 0x2c))(local_2c,uVar6);
          if (local_2c[0] != (int *)0x0) {
            puVar11 = (ushort *)(**(code **)(*local_2c[0] + 0x14))();
            uVar6 = (**(code **)(*DAT_00b5ad20 + 0xc))(CONCAT22(extraout_var,*puVar11));
            iVar7 = (**(code **)(*DAT_00b5ad20 + 0x18))(uVar6);
            if (iVar7 == 0x50a) {
              puVar12 = operator_new(8);
              if (puVar12 == (undefined4 *)0x0) {
                puVar12 = (undefined4 *)0x0;
              }
              else {
                *puVar12 = &PTR_FUN_009dd418;
              }
              puVar12[1] = (uint)*puVar11;
              FUN_00797a20(puVar12);
            }
          }
          goto LAB_00697e8e;
        }
        cVar2 = (**(code **)(*DAT_00b5b0d4 + 0x40))();
        if (cVar2 == '\0') goto LAB_00697dc7;
        cVar2 = cVar2 + -1;
      }
      else {
        iVar7 = *DAT_00b5b0d4;
        uVar6 = (**(code **)(*DAT_00b5b0d4 + 0x3c))();
        uVar9 = (**(code **)(iVar7 + 0x28))(uVar6);
        uVar10 = uVar9 / 10;
        if (uVar9 % 10 != 0) {
          uVar10 = uVar10 + 1;
        }
        bVar4 = (**(code **)(*DAT_00b5b0d4 + 0x40))();
        if (uVar10 <= bVar4 + 1) goto LAB_00697dc7;
        cVar2 = bVar4 + 1;
      }
      (**(code **)(*DAT_00b5b0d4 + 0x38))(cVar2);
      in_ECX[3] = 0;
      FUN_006964f0();
      FUN_00696d00();
LAB_00697dc7:
      FUN_00406250();
      return 1;
    }
    param_2 = *DAT_00b5b0d4;
    uVar6 = (**(code **)(*DAT_00b5b0d4 + 0x40))((char)in_ECX[3]);
    uVar6 = (**(code **)(*piVar1 + 0x3c))(uVar6);
    (**(code **)(param_2 + 0x2c))(local_2c,uVar6);
    if (local_2c[0] != (int *)0x0) {
      puVar8 = (undefined2 *)(**(code **)(*local_2c[0] + 0x14))();
      (**(code **)(*DAT_00b5b0d4 + 0x50))(uStack_20,*puVar8,5);
    }
  }
  else {
    param_2 = *DAT_00b5b0d4;
    uVar6 = (**(code **)(*DAT_00b5b0d4 + 0x40))((char)in_ECX[3]);
    uVar6 = (**(code **)(*piVar1 + 0x3c))(uVar6);
    (**(code **)(param_2 + 0x2c))(local_2c,uVar6);
    if (local_2c[0] != (int *)0x0) {
      puVar8 = (undefined2 *)(**(code **)(*local_2c[0] + 0x14))();
      (**(code **)(*DAT_00b5b0d4 + 0x50))(uStack_20,*puVar8,1);
    }
  }
LAB_00697e8e:
  FUN_00792590();
LAB_00697e97:
  FUN_00406250();
  return 1;
}


// ==== FUN_00697f20 @ 0x00697f20 ====

undefined4 FUN_00697f20(int param_1,ushort param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined2 extraout_var;
  int *unaff_EBP;
  undefined4 unaff_retaddr;
  undefined1 auStack_1e5 [5];
  undefined1 auStack_1e0 [28];
  int iStack_1c4;
  undefined1 auStack_1b4 [44];
  undefined1 auStack_188 [28];
  undefined1 auStack_16c [56];
  undefined1 auStack_134 [28];
  undefined1 auStack_118 [56];
  undefined1 auStack_e0 [112];
  undefined1 auStack_70 [68];
  undefined1 auStack_2c [44];
  
  iVar2 = (**(code **)(*in_ECX + 0x14))();
  piVar1 = DAT_00b5b0d4;
  if (param_1 != iVar2) {
    return 0;
  }
  if (param_3 == 1) {
    switch(param_2 - 1) {
    case 0:
      iVar2 = *DAT_00b5b0d4;
      uVar4 = (**(code **)(*DAT_00b5b0d4 + 0x40))((char)in_ECX[3]);
      uVar4 = (**(code **)(*piVar1 + 0x3c))(uVar4);
      (**(code **)(iVar2 + 0x2c))(auStack_1b4,uVar4);
      if (iStack_1c4 != 0) {
        (**(code **)(*DAT_00b5b0d4 + 0x4c))();
        FUN_00406250();
        uVar4 = (**(code **)(*DAT_00b5ad20 + 0x40))(auStack_2c,iStack_1c4);
        FUN_00406720(uVar4);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      FUN_00792590();
      return 1;
    case 1:
      auStack_1e5[0] = 0x21;
      FUN_00401830(s_cashItem_ui_pwdcheck_txt_009dd804);
      FUN_00697120(auStack_134,auStack_1e5,4);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 3:
      iVar2 = *DAT_00b5b0d4;
      uVar4 = (**(code **)(*DAT_00b5b0d4 + 0x40))((char)in_ECX[3]);
      uVar4 = (**(code **)(*piVar1 + 0x3c))(uVar4);
      (**(code **)(iVar2 + 0x2c))(auStack_1e0,uVar4);
      if (unaff_EBP != (int *)0x0) {
        puVar3 = (undefined2 *)(**(code **)(*unaff_EBP + 0x14))();
        iVar2 = *DAT_00b5b0d4;
        FUN_00765c50(unaff_retaddr);
        (**(code **)(iVar2 + 0x60))(CONCAT22(extraout_var,*puVar3));
      }
      FUN_00792590();
      return 1;
    case 4:
      uVar4 = FUN_00404170(auStack_70,param_4);
      FUN_00401660(uVar4,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 5:
      auStack_1e5[0] = 0x21;
      FUN_00401830(s_cashItem_ui_pwdcheck_txt_009dd7e8);
      FUN_00697120(auStack_e0,auStack_1e5,8);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 7:
      iVar2 = *DAT_00b5b0d4;
      uVar4 = (**(code **)(*DAT_00b5b0d4 + 0x40))((char)in_ECX[3]);
      uVar4 = (**(code **)(*piVar1 + 0x3c))(uVar4);
      (**(code **)(iVar2 + 0x2c))(auStack_1e0,uVar4);
      if (unaff_EBP != (int *)0x0) {
        (**(code **)(*unaff_EBP + 0x14))();
        iVar2 = *DAT_00b5b0d4;
        FUN_00765c50(unaff_retaddr);
        FUN_00765c50(in_ECX + 8);
        (**(code **)(iVar2 + 0x68))();
      }
      FUN_00792590();
      return 1;
    case 8:
      FUN_00401830(s_btn_buyInfo_009dd858);
      iVar2 = (**(code **)(*DAT_00b5b0d4 + 0x4c))();
      FUN_006962e0(auStack_118,iVar2 == 0);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 10:
      auStack_1e5[0] = 0x21;
      FUN_00401830(s_cashItem_ui_pwdcheck_txt_009dd820);
      FUN_00697120(auStack_16c,auStack_1e5,4);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 0xb:
      auStack_1e5[0] = 0x21;
      FUN_00401830(s_cashItem_ui_pwdcheck_txt_009dd83c);
      FUN_00697120(auStack_188,auStack_1e5,8);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  return 1;
}


// ==== FUN_00698520 @ 0x00698520 ====

void FUN_00698520(void)

{
  char cVar1;
  int *piVar2;
  void *pvVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int in_ECX;
  int *unaff_ESI;
  int *unaff_EDI;
  int *piVar8;
  undefined4 uStack_24c;
  undefined4 *puStack_248;
  int *piStack_244;
  undefined1 *puStack_240;
  undefined4 *puStack_23c;
  int *piStack_238;
  undefined1 *puStack_234;
  void *pvStack_228;
  void **ppvStack_224;
  undefined4 *puStack_220;
  undefined4 *puStack_21c;
  int *piVar9;
  int *piStack_1f8;
  int iStack_1f0;
  undefined4 *puStack_1ec;
  undefined4 uStack_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  int aiStack_1dc [3];
  int *piStack_1d0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  int *piStack_1c4;
  undefined1 auStack_1c0 [4];
  undefined4 uStack_1bc;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined1 auStack_1a4 [8];
  undefined1 uStack_19c;
  undefined1 auStack_194 [8];
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined1 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined1 uStack_154;
  undefined1 uStack_153;
  void *pvStack_134;
  undefined1 uStack_130;
  undefined4 uStack_124;
  uint uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  void *local_110;
  uint local_10c;
  undefined4 uStack_100;
  uint local_fc;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined1 auStack_dc [4];
  void *pvStack_d8;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  uint uStack_c4;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined1 auStack_a8 [4];
  undefined4 uStack_a4;
  undefined1 auStack_9c [4];
  void *pvStack_98;
  undefined1 auStack_90 [4];
  void *pvStack_8c;
  undefined4 uStack_88;
  uint uStack_84;
  undefined4 uStack_7c;
  uint uStack_78;
  undefined1 auStack_64 [4];
  void *pvStack_60;
  undefined4 uStack_50;
  uint uStack_4c;
  
  local_f8 = 0xf;
  local_fc = 0;
  local_10c = local_10c & 0xffffff00;
  FUN_00401740();
  puStack_1ec = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (0xf < local_fc) {
    _free(local_110);
    return;
  }
  local_fc = 0xf;
  uStack_100 = 0;
  local_110 = (void *)((uint)local_110 & 0xffffff00);
  uStack_1e4._0_3_ = CONCAT12(1,(undefined2)uStack_1e4);
  uStack_1e0 = 0;
  aiStack_1dc[0] = 0;
  aiStack_1dc[1] = 0;
  aiStack_1dc[2] = 0;
  piStack_1d0 = (int *)0x0;
  uStack_1cc = 0;
  uStack_1c8 = 0;
  uStack_1ac = 0xf;
  uStack_1b0 = 0;
  auStack_1c0[0] = 0;
  uStack_188 = 0xf;
  uStack_18c = 0;
  uStack_19c = 0;
  uStack_184 = 0;
  uStack_180 = 0;
  uStack_17c = 0;
  uStack_1e8 = 0;
  uStack_e8 = 0;
  uStack_c8 = 1;
  local_f8 = 2;
  uStack_b8 = 4;
  pvStack_d8 = (void *)0x0;
  uStack_a4 = 5;
  iStack_1f0 = (**(code **)(*DAT_00b5a7ac + 4))();
  piVar9 = (int *)0x1;
  piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
  puStack_234 = (undefined1 *)0xb;
  puStack_21c = (undefined4 *)0x0;
  piStack_238 = (int *)s_btn_list__d_009dd874;
  puStack_23c = (undefined4 *)0x698680;
  FUN_00401740();
  puStack_234 = auStack_64;
  piStack_238 = (int *)0x69868d;
  puStack_21c = (undefined4 *)FUN_00404230();
  puStack_220 = (undefined4 *)0x69869d;
  FUN_00401660();
  if (0xf < uStack_4c) {
    _free(pvStack_60);
    return;
  }
  puStack_21c = (undefined4 *)auStack_1a4;
  uStack_4c = 0xf;
  uStack_50 = 0;
  pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
  puStack_220 = (undefined4 *)0x6986dd;
  FUN_00401660();
  uStack_1e0 = 0;
  aiStack_1dc[0] = (int)puStack_1ec;
  aiStack_1dc[2] = (int)puStack_1ec + 0x1d;
  aiStack_1dc[1] = 0x18d;
  uStack_1e4 = 100;
  uStack_1e8 = CONCAT22(uStack_1e8._2_2_,0x101);
  pvVar3 = operator_new(0x468);
  if (pvVar3 == (void *)0x0) {
    pvVar3 = (void *)0x0;
  }
  else {
    pvVar3 = (void *)FUN_00505f10();
  }
  uStack_e8 = 0xff000000;
  uStack_e4 = 0;
  *(undefined1 *)((int)pvVar3 + 0x104) = 0;
  *(undefined1 *)((int)pvVar3 + 0x105) = 0;
  *(undefined1 *)((int)pvVar3 + 0x107) = 0;
  *(undefined1 *)((int)pvVar3 + 0x10c) = 0;
  *(undefined4 *)((int)pvVar3 + 0x108) = 0xc;
  *(undefined4 *)((int)pvVar3 + 0x110) = 500;
  *(undefined1 *)((int)pvVar3 + 0x106) = 0;
  uStack_e0 = 0;
  puStack_21c = (undefined4 *)0x698796;
  FUN_0056ac60();
  uStack_11c = 0xf;
  uStack_120 = 0;
  uStack_130 = 0;
  puStack_21c = (undefined4 *)0x6987be;
  FUN_00401740();
  uStack_174 = (**(code **)(*DAT_00b5a7c0 + 8))();
  if (0xf < uStack_120) {
    puStack_21c = (undefined4 *)0x6987ef;
    _free(pvStack_134);
    return;
  }
  uStack_c4 = 2;
  uStack_cc = 0;
  puStack_21c = &uStack_180;
  uStack_120 = 0xf;
  uStack_124 = 0;
  pvStack_134 = (void *)((uint)pvStack_134 & 0xffffff00);
  puStack_220 = (undefined4 *)0x698841;
  uStack_c8 = uStack_174;
  FUN_0056ac60();
  local_fc = 0;
  uStack_f4 = 2;
  puStack_21c = &uStack_1b0;
  local_f8 = uStack_174;
  puStack_220 = (undefined4 *)0x698878;
  FUN_0056ac60();
  uStack_bc = 0;
  uStack_b4 = 2;
  puStack_21c = (undefined4 *)auStack_a8;
  uStack_b8 = uStack_174;
  puStack_220 = (undefined4 *)0x6988b2;
  FUN_0056ac60();
  puStack_21c = (undefined4 *)0x6988c2;
  (**(code **)(*piStack_1f8 + 8))();
  if (piStack_1f8 != (int *)0x0) {
    puStack_220 = (undefined4 *)0x6988d2;
    cVar1 = (**(code **)(*piStack_1f8 + 0x74))();
    if (cVar1 != '\0') {
      puStack_220 = (undefined4 *)0x6988e0;
      cVar1 = (**(code **)(*piStack_1f8 + 0x78))();
      if (cVar1 == '\0') {
        puStack_220 = (undefined4 *)0x0;
        ppvStack_224 = (void **)0x6988ec;
        (**(code **)(*piStack_1f8 + 0x74))();
      }
      else {
        puStack_220 = (undefined4 *)0x6988f7;
        iVar7 = (**(code **)(*piVar2 + 0x38))();
        piStack_1f8[1] = iVar7;
      }
    }
  }
  puStack_220 = (undefined4 *)0x698904;
  (**(code **)(*unaff_ESI + 0x38))();
  puStack_220 = &uStack_1b0;
  ppvStack_224 = (void **)0x698912;
  (**(code **)(*unaff_EDI + 0x1c))();
  pvStack_228 = (void *)0x69891e;
  ppvStack_224 = &local_110;
  (**(code **)(*piStack_1f8 + 0x2c))();
  pvStack_228 = pvVar3;
  (**(code **)(*piVar9 + 0x24))();
  if (pvVar3 != (void *)0x0) {
    FUN_00505d80();
    _free(pvVar3);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_1c8 = (**(code **)(*DAT_00b5a7ac + 8))();
  puStack_234 = (undefined1 *)0xf;
  piStack_238 = (int *)0x0;
  puStack_248 = (undefined4 *)((uint)puStack_248 & 0xffffff00);
  FUN_00401740(s_lbl_name__d_009dd890,0xb);
  piStack_238 = (int *)FUN_00404230(auStack_9c);
  puStack_234 = (undefined1 *)0x0;
  puStack_23c = (undefined4 *)0x698996;
  FUN_00401660();
  if (0xf < uStack_84) {
    puStack_234 = (undefined1 *)0x6989ad;
    _free(pvStack_98);
    return;
  }
  puStack_234 = (undefined1 *)0x0;
  piStack_238 = (int *)auStack_1c0;
  uStack_84 = 0xf;
  uStack_88 = 0;
  pvStack_98 = (void *)((uint)pvStack_98 & 0xffffff00);
  puStack_23c = (undefined4 *)0x6989d6;
  FUN_00401660();
  iStack_1f0 = 0x15;
  puStack_234 = &DAT_009dd89c;
  uStack_164 = 0xf;
  uStack_168 = 0;
  uStack_178 = 0;
  uStack_158 = 1;
  uStack_153 = 0;
  uStack_154 = 0;
  uStack_15c = 0xffffffff;
  uStack_184 = 0;
  uStack_180 = 0;
  uStack_160 = 2;
  piStack_238 = (int *)0x698a70;
  FUN_00401740();
  puStack_234 = (undefined1 *)0x698a7c;
  (**(code **)(*piVar2 + 8))();
  piStack_238 = (int *)0x698a84;
  cVar1 = (**(code **)(*piVar2 + 0x74))();
  if (cVar1 != '\0') {
    puStack_23c = (undefined4 *)0x698a90;
    piStack_238 = piVar2;
    cVar1 = (**(code **)(*piStack_1f8 + 0x78))();
    if (cVar1 == '\0') {
      puStack_23c = (undefined4 *)0x0;
      puStack_240 = (undefined1 *)0x698a9c;
      (**(code **)(*piVar2 + 0x74))();
    }
    else {
      puStack_23c = (undefined4 *)0x698aa5;
      iVar7 = (**(code **)(*piStack_1f8 + 0x38))();
      piVar2[1] = iVar7;
    }
  }
  piVar9 = piStack_1d0;
  puStack_23c = (undefined4 *)0x698ab4;
  piStack_238 = piVar2;
  (**(code **)(*piStack_1d0 + 0x38))();
  puStack_23c = &uStack_1cc;
  puStack_240 = (undefined1 *)0x698ac0;
  (**(code **)(*piVar9 + 0x1c))();
  puStack_240 = auStack_194;
  piStack_244 = (int *)0x698acf;
  (**(code **)(*piVar9 + 8))();
  piStack_244 = piVar9;
  puStack_248 = (undefined4 *)0x698ad7;
  (**(code **)(*piVar2 + 0x2c))();
  puStack_248 = (undefined4 *)0x698ae2;
  puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puStack_248 = (undefined4 *)0x698aef;
    uVar5 = (**(code **)(*piVar2 + 4))();
    *puVar4 = &PTR_FUN_009bcd68;
    puVar4[1] = uVar5;
  }
  *(undefined1 *)(puVar4 + 2) = 0;
  uStack_24c = 0x698b0d;
  puStack_248 = puVar4;
  (**(code **)(*DAT_00b5ad24 + 4))();
  uStack_24c = 1;
  (**(code **)*puVar4)();
  piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_1bc = (**(code **)(*DAT_00b5a7ac + 8))(0);
  FUN_00401740(s_pan_icon__d_009dd8a0,0xb);
  uVar5 = FUN_00404230(auStack_dc);
  FUN_00401660(uVar5,0,0xffffffff);
  if (0xf < uStack_c4) {
    _free(pvStack_d8);
    return;
  }
  uStack_c4 = 0xf;
  uStack_c8 = 0;
  pvStack_d8 = (void *)((uint)pvStack_d8 & 0xffffff00);
  FUN_00401660(&uStack_1e4,0,0xffffffff);
  puStack_220 = (undefined4 *)0x85;
  puStack_21c = (undefined4 *)0x1;
  ppvStack_224 = (void **)0x6e;
  pvStack_228 = (void *)CONCAT22(pvStack_228._2_2_,0x101);
  pvVar3 = operator_new(0x468);
  if (pvVar3 == (void *)0x0) {
    pvVar3 = (void *)0x0;
  }
  else {
    pvVar3 = (void *)FUN_00505f10();
  }
  puStack_23c = *(undefined4 **)(*(int *)((int)pvVar3 + 0x11c) + 4);
  puStack_1ec = puStack_23c;
  if (*(char *)((int)puStack_23c + 0x1d) == '\0') {
    FUN_00503950(puStack_23c[2]);
    puStack_23c = (undefined4 *)*puStack_23c;
    _free(puStack_1ec);
    return;
  }
  *(int *)(*(int *)((int)pvVar3 + 0x11c) + 4) = *(int *)((int)pvVar3 + 0x11c);
  *(undefined4 *)((int)pvVar3 + 0x120) = 0;
  *(undefined4 *)*(undefined4 *)((int)pvVar3 + 0x11c) = *(undefined4 *)((int)pvVar3 + 0x11c);
  uStack_118 = 0xff000000;
  local_110 = (void *)0x2;
  *(int *)(*(int *)((int)pvVar3 + 0x11c) + 8) = *(int *)((int)pvVar3 + 0x11c);
  uStack_114 = uStack_1b0;
  *(undefined1 *)((int)pvVar3 + 0x114) = 0;
  *(undefined1 *)((int)pvVar3 + 0x115) = 0;
  FUN_0056ac60(&uStack_e4,&uStack_11c);
  (**(code **)(*piVar2 + 8))(&pvStack_228);
  piVar9 = piStack_238;
  cVar1 = (**(code **)(*piVar2 + 0x74))(piStack_238);
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*piVar9 + 0x78))(piVar2);
    if (cVar1 == '\0') {
      (**(code **)(*piVar2 + 0x74))(0);
    }
    else {
      iVar7 = (**(code **)(*piVar9 + 0x38))();
      piVar2[1] = iVar7;
    }
  }
  piVar8 = piVar2;
  (**(code **)(*piStack_1c4 + 0x38))(piVar2);
  piVar9 = &iStack_1f0;
  (**(code **)(*piStack_1c4 + 0x1c))();
  (**(code **)(*piVar2 + 0x2c))();
  (**(code **)(*piStack_1c4 + 0x24))(pvVar3);
  if (pvVar3 != (void *)0x0) {
    FUN_00505d80();
    _free(pvVar3);
    return;
  }
  puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    uVar5 = (**(code **)(*piVar2 + 4))();
    *puVar4 = &PTR_FUN_009bcd68;
    puVar4[1] = uVar5;
  }
  *(undefined1 *)(puVar4 + 2) = 0;
  (**(code **)(*DAT_00b5ad24 + 4))(puVar4);
  (**(code **)*puVar4)(1);
  piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  piVar6 = (int *)(**(code **)(*DAT_00b5a7ac + 8))(8);
  FUN_00401740(s_lbl_price__d_009dd8ac,0xc);
  uVar5 = FUN_00404230(auStack_90);
  FUN_00401660(uVar5,0,0xffffffff);
  if (0xf < uStack_78) {
    _free(pvStack_8c);
    return;
  }
  uStack_78 = 0xf;
  uStack_7c = 0;
  pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  pvVar3 = operator_new(0x468);
  if (pvVar3 == (void *)0x0) {
    pvVar3 = (void *)0x0;
  }
  else {
    pvVar3 = (void *)FUN_00505f10();
  }
  *(uint *)((int)pvVar3 + 0x19c) = local_10c;
  *(undefined4 *)((int)pvVar3 + 0x198) = 5;
  *(undefined1 *)((int)pvVar3 + 0x194) = 0;
  *(undefined1 *)((int)pvVar3 + 0x195) = 0;
  *(undefined1 *)((int)pvVar3 + 0x196) = 0;
  *(undefined4 *)((int)pvVar3 + 0x1a0) = 0xc;
  *(undefined1 *)((int)pvVar3 + 0x196) = 2;
  FUN_00401660(aiStack_1dc + -0xb,0,0xffffffff);
  puStack_240 = (undefined1 *)0x9;
  piStack_238 = (int *)0x15;
  piStack_244 = (int *)0xb7;
  puStack_23c = (undefined4 *)0x107;
  (**(code **)(*piVar2 + 8))(&uStack_24c);
  cVar1 = (**(code **)(*piVar2 + 0x74))(piVar8);
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*piVar9 + 0x78))(piVar2);
    if (cVar1 == '\0') {
      (**(code **)(*piVar2 + 0x74))(0);
    }
    else {
      iVar7 = (**(code **)(*piStack_1c4 + 0x38))();
      piVar2[1] = iVar7;
    }
  }
  (**(code **)(*piVar6 + 0x38))(piVar2);
  (**(code **)(*piVar6 + 0x1c))(aiStack_1dc + -0xe);
  (**(code **)(*piVar6 + 8))(aiStack_1dc);
  (**(code **)(*piVar2 + 0x2c))(piVar6);
  (**(code **)(*piVar6 + 0x24))(pvVar3);
  FUN_00505d80();
  _free(pvVar3);
  return;
}


// ==== FUN_00699150 @ 0x00699150 ====

void FUN_00699150(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  void *unaff_ESI;
  undefined4 uVar3;
  undefined1 auStack_1e [2];
  undefined1 local_1c [4];
  void *local_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_CashShop_ui_cashshopwnd_009dd498,0x24);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  uVar3 = 0;
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  FUN_00698520();
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740(s_btn_buyInfo_009dd4c0,0xb);
  (**(code **)(*DAT_00b5b0d4 + 0x4c))();
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1e + -10);
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 0x30))();
    if ((iVar1 != 0) && (*(char *)(iVar1 + 0x10b) != (char)uVar3)) {
      FUN_00558130(uVar3);
      FUN_005586a0();
    }
  }
  if (uStack_14 < 0x10) {
    FUN_006964f0();
    FUN_00696d00();
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_00699260 @ 0x00699260 ====

void FUN_00699260(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dd8e0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  in_ECX[1] = 0;
  in_ECX[3] = 0;
  FUN_00699150();
  return;
}


// ==== FUN_00699290 @ 0x00699290 ====

undefined4 FUN_00699290(void)

{
  return 0x3e;
}


// ==== FUN_006992a0 @ 0x006992a0 ====

void FUN_006992a0(byte param_1)

{
  void *in_ECX;
  
  FUN_006970a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006992c0 @ 0x006992c0 ====

void FUN_006992c0(void)

{
  return;
}


// ==== FUN_006992d0 @ 0x006992d0 ====

void FUN_006992d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dda3c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006992f0 @ 0x006992f0 ====

void FUN_006992f0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_10 = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      uStack_10 = *(undefined4 *)(iVar2 + 0x78);
      uStack_c = *(undefined4 *)(iVar2 + 0x7c);
      uStack_8 = param_1;
      FUN_005581c0(&uStack_10);
    }
  }
  return;
}


// ==== FUN_006993a0 @ 0x006993a0 ====

void FUN_006993a0(void)

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
  FUN_00401740(s_UI_Game2_Messenger_ui_msnNotifyw_009dd94c,0x26);
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


// ==== FUN_00699420 @ 0x00699420 ====

void FUN_00699420(void)

{
  undefined4 *in_ECX;
  
  *(undefined1 *)((int)in_ECX + 0xb) = 1;
  *(undefined1 *)(in_ECX + 3) = 1;
  in_ECX[5] = 5000;
  in_ECX[6] = 5000;
  *in_ECX = &PTR_FUN_009dda3c;
  in_ECX[1] = 0;
  *(undefined1 *)((int)in_ECX + 10) = 0;
  FUN_006993a0();
  return;
}


// ==== FUN_00699450 @ 0x00699450 ====

/* WARNING: Removing unreachable block (ram,0x00699a52) */

void FUN_00699450(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  void *unaff_ESI;
  undefined1 auStack_a0 [2];
  undefined1 auStack_9e [2];
  void *pvStack_9c;
  uint uStack_98;
  undefined4 uStack_8c;
  uint uStack_88;
  int iStack_84;
  undefined1 auStack_80 [4];
  void *local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined1 auStack_70 [4];
  void *pvStack_6c;
  undefined4 uStack_68;
  undefined1 auStack_64 [8];
  undefined4 uStack_5c;
  uint uStack_58;
  void *pvStack_50;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined1 auStack_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_7c = (void *)0x0;
  local_78 = 0;
  local_74 = 0;
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  iVar1 = (**(code **)(*DAT_00b5ae3c + 100))();
  iStack_84 = (**(code **)(*DAT_00b5ae3c + 0x88))();
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
  if (iVar1 == 0) {
    if (*(char *)(in_ECX + 0xb) == '\x01') {
      uStack_88 = 0xf;
      uStack_8c = 0;
      pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
      FUN_00401740(s_btn_memo_009dd9b0,8);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_a0);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x24))(0);
      }
      if (0xf < uStack_88) {
        _free(pvStack_9c);
        return;
      }
      *(undefined1 *)(in_ECX + 0xb) = 0;
    }
  }
  else {
    FUN_00401740(s_<VALUE>_009dd974,7);
    FUN_00401740(&DAT_009dd97c,2);
    uVar2 = FUN_00404230(auStack_a0);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < uStack_88) {
      _free(pvStack_9c);
      return;
    }
    FUN_004e6c20(auStack_38);
    uVar2 = (**(code **)(*DAT_00b5a794 + 8))(auStack_a0,0,0x3ee002c,auStack_80);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < uStack_98) {
      _free(unaff_ESI);
      return;
    }
    uStack_98 = 0xf;
    pvStack_9c = (void *)0x0;
    unaff_ESI = (void *)((uint)unaff_ESI & 0xffffff00);
    FUN_00401740(s_lbl_memoNum_009dd980,0xb);
    uStack_68 = 0xf;
    pvStack_6c = (void *)0x0;
    local_7c = (void *)((uint)local_7c & 0xffffff00);
    FUN_00401660(auStack_64,0,0xffffffff);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_a0 + -0x10);
    if ((piVar3 != (int *)0x0) && (iVar1 = (**(code **)(*piVar3 + 0x30))(), iVar1 != 0)) {
      FUN_0055a260(auStack_70);
    }
    if (0xf < uStack_58) {
      _free(pvStack_6c);
      return;
    }
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
    if (0xf < uStack_88) {
      _free(pvStack_9c);
      return;
    }
    if (*(char *)(in_ECX + 0xb) == '\0') {
      uStack_88 = 0xf;
      uStack_8c = 0;
      pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
      FUN_00401740(s_btn_memo_009dd98c,8);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_a0);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x24))(1);
      }
      if (0xf < uStack_88) {
        _free(pvStack_9c);
        return;
      }
      *(undefined1 *)(in_ECX + 0xb) = 1;
    }
    pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
    uStack_8c = 0;
    uStack_88 = 0xf;
    if ((*(uint *)(in_ECX + 0x14) / 500 & 1) == 0) {
      FUN_00401740(s_btn_memo_009dd998,8);
      FUN_006992f0(auStack_a0,1);
      if (0xf < uStack_88) {
        _free(pvStack_9c);
        return;
      }
    }
    else {
      FUN_00401740(s_btn_memo_009dd9a4,8);
      FUN_006992f0(auStack_a0,2);
      if (0xf < uStack_88) {
        _free(pvStack_9c);
        return;
      }
    }
  }
  if (iStack_84 == 0) {
    if (*(char *)(in_ECX + 0xc) == '\x01') {
      uStack_88 = 0xf;
      uStack_8c = 0;
      pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
      FUN_00401740(s_btn_message_009dd9f8,0xb);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_a0);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x24))(0);
      }
      if (0xf < uStack_88) {
        _free(pvStack_9c);
        return;
      }
      *(undefined1 *)(in_ECX + 0xc) = 0;
    }
  }
  else {
    FUN_00401740(s_<VALUE>_009dd9bc,7);
    FUN_00401740(&DAT_009dd9c4,2);
    uVar2 = FUN_00404230(auStack_a0);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < uStack_88) {
      _free(pvStack_9c);
      return;
    }
    FUN_004e6c20(auStack_38);
    uVar2 = (**(code **)(*DAT_00b5a794 + 8))(auStack_a0,0,0x3ee002b,auStack_80);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < uStack_98) {
      _free(unaff_ESI);
      return;
    }
    uStack_98 = 0xf;
    pvStack_9c = (void *)0x0;
    FUN_00401740(s_lbl_msgNum_009dd9c8,10);
    uStack_68 = 0xf;
    pvStack_6c = (void *)0x0;
    local_7c = (void *)((uint)local_7c & 0xffffff00);
    FUN_00401660(auStack_64,0,0xffffffff);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_a0 + -0x10);
    if ((piVar3 != (int *)0x0) && (iVar1 = (**(code **)(*piVar3 + 0x30))(), iVar1 != 0)) {
      FUN_0055a260(auStack_70);
    }
    if (0xf < uStack_58) {
      _free(pvStack_6c);
      return;
    }
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
    if (0xf < uStack_88) {
      _free(pvStack_9c);
      return;
    }
    if (*(char *)(in_ECX + 0xc) == '\0') {
      uStack_88 = 0xf;
      uStack_8c = 0;
      pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
      FUN_00401740(s_btn_message_009dd9d4,0xb);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_a0);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x24))(1);
      }
      if (0xf < uStack_88) {
        _free(pvStack_9c);
        return;
      }
      *(undefined1 *)(in_ECX + 0xc) = 1;
    }
    pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
    uStack_8c = 0;
    uStack_88 = 0xf;
    if ((*(uint *)(in_ECX + 0x18) / 500 & 1) == 0) {
      FUN_00401740(s_btn_message_009dd9e0,0xb);
      FUN_006992f0(auStack_a0,0xb);
      if (0xf < uStack_88) {
        _free(pvStack_9c);
        return;
      }
    }
    else {
      FUN_00401740(s_btn_message_009dd9ec,0xb);
      FUN_006992f0(auStack_a0,0xc);
      if (0xf < uStack_88) {
        _free(pvStack_9c);
        return;
      }
    }
  }
  if (local_7c != (void *)0x0) {
    FUN_004e65b0(local_7c,local_78,auStack_80,iStack_84);
    _free(local_7c);
    return;
  }
  local_7c = (void *)0x0;
  local_78 = 0;
  local_74 = 0;
  if (0xf < uStack_3c) {
    _free(pvStack_50);
    return;
  }
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  if (local_20 < 0x10) {
    return;
  }
  _free(local_34);
  return;
}


// ==== FUN_00699ac0 @ 0x00699ac0 ====

uint FUN_00699ac0(int param_1,int param_2,int param_3)

{
  uint in_EAX;
  int iVar1;
  int in_ECX;
  undefined1 auStack_1a [26];
  
  if ((param_1 == 1) && (param_3 == 1)) {
    in_EAX = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_message_009dda04,0xb);
    if (in_EAX == 0) {
      iVar1 = (**(code **)(*DAT_00b5a74c + 0xc))(0x4f);
      in_EAX = 0;
      if (iVar1 != 0) {
        FUN_0069a140();
        *(undefined4 *)(in_ECX + 0x18) = 5000;
        FUN_00401830(&DAT_009dda10);
        FUN_00796d50(auStack_1a + -6);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_00699b50 @ 0x00699b50 ====

uint FUN_00699b50(int *param_1)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  
  uVar2 = (**(code **)(*param_1 + 4))();
  if (uVar2 == 0x40001) {
    iVar1 = param_1[1];
    if (*(uint *)(in_ECX + 0x18) < 5000) {
      *(uint *)(in_ECX + 0x18) = *(uint *)(in_ECX + 0x18) + iVar1;
      FUN_00699450();
    }
    uVar2 = *(uint *)(in_ECX + 0x14);
    if (uVar2 < 5000) {
      *(uint *)(in_ECX + 0x14) = uVar2 + iVar1;
      uVar2 = FUN_00699450();
    }
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_00699ba0 @ 0x00699ba0 ====

undefined4 FUN_00699ba0(void)

{
  return 0x4e;
}


// ==== FUN_00699bb0 @ 0x00699bb0 ====

void FUN_00699bb0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009dda3c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00699bf0 @ 0x00699bf0 ====

void FUN_00699bf0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x2d) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x2d) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x2d);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x2d);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x2d);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x2d);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_00699c40 @ 0x00699c40 ====

void FUN_00699c40(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c720;
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


// ==== Catch@00699cca @ 0x00699cca ====

void Catch_00699cca(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00699ce0 @ 0x00699ce0 ====

void FUN_00699ce0(undefined4 param_1)

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
    (**(code **)(*(int *)puVar3[10] + 8))(param_1);
    if (*(char *)((int)puVar3 + 0x2d) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x2d) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x2d);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x2d);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x2d);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x2d);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  return;
}


// ==== FUN_00699d50 @ 0x00699d50 ====

undefined4 FUN_00699d50(int param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_0069a470(&param_1,param_1);
    if (param_1 != *(int *)(in_ECX + 0xc)) {
      return *(undefined4 *)(param_1 + 0x28);
    }
  }
  return 0;
}


// ==== FUN_00699d90 @ 0x00699d90 ====

undefined4 FUN_00699d90(void)

{
  uint in_ECX;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x10) != 0) {
    local_4 = in_ECX & 0xffffff00;
    FUN_0082c4f0(**(undefined4 **)(in_ECX + 0xc),*(undefined4 **)(in_ECX + 0xc),local_4);
    FUN_0069a4e0(*(undefined4 *)(*(int *)(in_ECX + 0xc) + 4));
    *(int *)(*(int *)(in_ECX + 0xc) + 4) = *(int *)(in_ECX + 0xc);
    *(undefined4 *)(in_ECX + 0x10) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(in_ECX + 0xc);
    *(int *)(*(int *)(in_ECX + 0xc) + 8) = *(int *)(in_ECX + 0xc);
  }
  return 1;
}


// ==== FUN_00699de0 @ 0x00699de0 ====

void FUN_00699de0(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined1 uStack00000000;
  
  FUN_0069a470(&param_1,param_1);
  iVar1 = param_1;
  if (param_1 != *(int *)(in_ECX + 0xc)) {
    (**(code **)(*DAT_00b5a7a4 + 8))(*(undefined4 *)(*(int *)(param_1 + 0x28) + 4));
    FUN_005a4100(&uStack00000000,iVar1);
  }
  return;
}


// ==== FUN_00699e30 @ 0x00699e30 ====

void FUN_00699e30(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 uVar8;
  int iVar9;
  uint in_ECX;
  undefined4 uVar10;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x10) != 0) {
    puVar2 = *(undefined4 **)(in_ECX + 0xc);
    puVar3 = (undefined4 *)*puVar2;
    piVar5 = DAT_00b5ae3c;
    while (DAT_00b5ae3c = piVar5, puVar3 != puVar2) {
      iVar9 = puVar3[10];
      if (iVar9 != 0) {
        FUN_00401660(puVar3 + 3,0,0xffffffff);
        pcVar7 = (char *)(**(code **)(*piVar5 + 0x84))();
        if ((pcVar7 != (char *)0x0) && (*pcVar7 == '\x01')) {
          if (*(int *)(iVar9 + 4) == 0) {
            uVar10 = 0;
            uVar8 = 0;
          }
          else {
            iVar9 = (**(code **)(**(int **)(iVar9 + 4) + 0x14))();
            uVar10 = *(undefined4 *)(iVar9 + 0x14);
            uVar8 = *(undefined4 *)(iVar9 + 0x18);
          }
          *(undefined4 *)(pcVar7 + 4) = uVar10;
          *(undefined4 *)(pcVar7 + 8) = uVar8;
          pcVar7[1] = '\x01';
        }
      }
      piVar5 = DAT_00b5ae3c;
      if (*(char *)((int)puVar3 + 0x2d) == '\0') {
        puVar4 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar4 + 0x2d) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x2d);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x2d);
            puVar3 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x2d);
          puVar6 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar6, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x2d);
            puVar6 = (undefined4 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
    if (*(int *)(in_ECX + 0x10) != 0) {
      local_4 = in_ECX & 0xffffff00;
      FUN_0082c4f0(**(undefined4 **)(in_ECX + 0xc),*(undefined4 **)(in_ECX + 0xc),local_4);
      FUN_0069a4e0(*(undefined4 *)(*(int *)(in_ECX + 0xc) + 4));
      *(int *)(*(int *)(in_ECX + 0xc) + 4) = *(int *)(in_ECX + 0xc);
      *(undefined4 *)(in_ECX + 0x10) = 0;
      *(undefined4 *)*(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(in_ECX + 0xc);
      *(int *)(*(int *)(in_ECX + 0xc) + 8) = *(int *)(in_ECX + 0xc);
    }
  }
  return;
}


// ==== FUN_00699f60 @ 0x00699f60 ====

void FUN_00699f60(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  undefined1 local_28 [8];
  undefined1 local_20 [4];
  void *local_1c;
  undefined4 local_c;
  uint local_8;
  undefined4 local_4;
  
  uVar2 = param_1;
  iVar1 = *(int *)(in_ECX + 0xc);
  piVar3 = (int *)FUN_0069a470(&param_1,param_1);
  if (*piVar3 == iVar1) {
    local_8 = 0xf;
    local_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    FUN_00401660(uVar2,0,0xffffffff);
    local_4 = param_2;
    FUN_0069a870(local_28,local_20);
    if (0xf < local_8) {
      _free(local_1c);
      return;
    }
  }
  return;
}


// ==== FUN_00699fe0 @ 0x00699fe0 ====

int FUN_00699fe0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int in_ECX;
  
  iVar2 = param_1;
  if (((*(int *)(in_ECX + 0x10) != 0) &&
      (FUN_0069a470(&param_1,param_1), param_1 != *(int *)(in_ECX + 0xc))) &&
     (*(int *)(param_1 + 0x28) != 0)) {
    return *(int *)(param_1 + 0x28);
  }
  piVar1 = DAT_00b5ae3c;
  FUN_00401660(iVar2,0,0xffffffff);
  iVar3 = (**(code **)(*piVar1 + 0x74))();
  if (iVar3 == 0) {
    return 0;
  }
  pvVar4 = operator_new(0x24);
  if (pvVar4 == (void *)0x0) {
    FUN_00699f60(iVar2,0);
    return 0;
  }
  iVar3 = FUN_006dba90(iVar2);
  FUN_00699f60(iVar2,iVar3);
  return iVar3;
}


// ==== FUN_0069a090 @ 0x0069a090 ====

void FUN_0069a090(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  
  uVar3 = (**(code **)(*DAT_00b5ae3c + 0x7c))();
  uVar7 = 0;
  if (uVar3 != 0) {
    do {
      pcVar4 = (char *)(**(code **)(*DAT_00b5ae3c + 0x80))(uVar7);
      if ((*pcVar4 != '\0') && (piVar5 = (int *)FUN_00699fe0(pcVar4 + 0xc), piVar5 != (int *)0x0)) {
        uVar1 = *(undefined4 *)(pcVar4 + 4);
        uVar2 = *(undefined4 *)(pcVar4 + 8);
        if (piVar5[1] != 0) {
          iVar6 = (**(code **)(*piVar5 + 0x14))();
          if ((iVar6 == 10) || (iVar6 = (**(code **)(*piVar5 + 0x14))(), iVar6 == 0x7b)) {
            (**(code **)(*(int *)piVar5[1] + 0x54))(uVar1,uVar2,0);
          }
          else {
            (**(code **)(*(int *)piVar5[1] + 0x54))(uVar1,uVar2,1);
          }
        }
        FUN_006db590();
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar3);
  }
  return;
}


// ==== FUN_0069a140 @ 0x0069a140 ====

void FUN_0069a140(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  int iVar6;
  int in_ECX;
  uint uStack_c;
  
  uVar3 = (**(code **)(*DAT_00b5ae3c + 0x7c))();
  uStack_c = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 100;
  if (uVar3 != 0) {
    do {
      pcVar4 = (char *)(**(code **)(*DAT_00b5ae3c + 0x80))(uStack_c);
      if ((*pcVar4 != '\x01') && (piVar5 = (int *)FUN_00699fe0(pcVar4 + 0xc), piVar5 != (int *)0x0))
      {
        uVar1 = *(undefined4 *)(in_ECX + 0x30);
        uVar2 = *(undefined4 *)(in_ECX + 0x34);
        if (piVar5[1] != 0) {
          iVar6 = (**(code **)(*piVar5 + 0x14))();
          if ((iVar6 == 10) || (iVar6 = (**(code **)(*piVar5 + 0x14))(), iVar6 == 0x7b)) {
            (**(code **)(*(int *)piVar5[1] + 0x54))(uVar1,uVar2,0);
          }
          else {
            (**(code **)(*(int *)piVar5[1] + 0x54))(uVar1,uVar2,1);
          }
        }
        *(undefined4 *)(pcVar4 + 4) = *(undefined4 *)(in_ECX + 0x30);
        *(undefined4 *)(pcVar4 + 8) = *(undefined4 *)(in_ECX + 0x34);
        if (*(int *)(in_ECX + 0x34) < 500) {
          *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + 0x14;
        }
        else {
          *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + 0x14;
          *(undefined4 *)(in_ECX + 0x34) = 100;
        }
        FUN_006db590();
      }
      uStack_c = uStack_c + 1;
    } while (uStack_c < uVar3);
  }
  return;
}


// ==== FUN_0069a240 @ 0x0069a240 ====

void FUN_0069a240(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = (**(code **)(*DAT_00b5ae3c + 0x7c))();
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      iVar2 = (**(code **)(*DAT_00b5ae3c + 0x80))(uVar3);
      iVar2 = FUN_00699fe0(iVar2 + 0xc);
      if (iVar2 != 0) {
        FUN_006db590();
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}


// ==== FUN_0069a290 @ 0x0069a290 ====

undefined4 FUN_0069a290(int *param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 < 0x70340021) {
    if (uVar1 == 0x70340020) {
      FUN_0069a240();
      return 1;
    }
    if (uVar1 == 0x70040011) {
      FUN_00699ce0(param_1);
      return 0;
    }
    if (uVar1 == 0x70340003) {
      iVar2 = FUN_00699fe0(param_1 + 1);
      if (iVar2 == 0) {
        return 1;
      }
      FUN_0050a850(*(undefined4 *)(in_ECX + 0x30),*(undefined4 *)(in_ECX + 0x34));
      if (*(int *)(in_ECX + 0x34) < 500) {
        *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + 0x14;
        return 1;
      }
      *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + 0x14;
      *(undefined4 *)(in_ECX + 0x34) = 100;
      return 1;
    }
    if (uVar1 == 0x70340004) {
      FUN_00699de0(param_1 + 1);
      return 1;
    }
  }
  else {
    if (uVar1 == 0x70340030) {
      FUN_0069a090();
      return 1;
    }
    if (uVar1 == 0x70340031) {
      FUN_00699e30();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0069a370 @ 0x0069a370 ====

void FUN_0069a370(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009ddab0;
  FUN_00699d90();
  if ((uint)in_ECX[0xb] < 0x10) {
    in_ECX[0xb] = 0xf;
    in_ECX[10] = 0;
    *(undefined1 *)(in_ECX + 6) = 0;
    FUN_0069a7b0(local_4,*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3]);
    _free((void *)in_ECX[3]);
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_0069a3e0 @ 0x0069a3e0 ====

void FUN_0069a3e0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 *in_ECX;
  char *pcVar5;
  
  *in_ECX = &PTR_FUN_009ddab0;
  iVar2 = FUN_00699c40();
  in_ECX[3] = iVar2;
  *(undefined1 *)(iVar2 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  *(undefined4 *)in_ECX[3] = in_ECX[3];
  *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  in_ECX[4] = 0;
  in_ECX[0xb] = 0xf;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  piVar3 = (int *)(**(code **)(*DAT_00b5ac1c + 0x14))();
  pcVar4 = (char *)(**(code **)(*piVar3 + 0x70))();
  pcVar5 = pcVar4;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar4,(int)pcVar5 - (int)(pcVar4 + 1));
  in_ECX[0xc] = 0;
  in_ECX[1] = 0;
  in_ECX[0xd] = 100;
  return;
}


// ==== FUN_0069a470 @ 0x0069a470 ====

void FUN_0069a470(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_004bb4d0(param_2);
  if (iVar1 != *(int *)(in_ECX + 4)) {
    if (*(uint *)(iVar1 + 0x24) < 0x10) {
      iVar2 = iVar1 + 0x10;
    }
    else {
      iVar2 = *(int *)(iVar1 + 0x10);
    }
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),iVar2,*(undefined4 *)(iVar1 + 0x20));
    if (-1 < iVar2) {
      *param_1 = iVar1;
      return;
    }
  }
  *param_1 = *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_0069a4e0 @ 0x0069a4e0 ====

void FUN_0069a4e0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) != '\0') {
    return;
  }
  FUN_0069a4e0(*(undefined4 *)((int)param_1 + 8));
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


// ==== FUN_0069a540 @ 0x0069a540 ====

void * FUN_0069a540(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c730;
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


// ==== Catch@0069a5b5 @ 0x0069a5b5 ====

void Catch_0069a5b5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0069a5d0 @ 0x0069a5d0 ====

void FUN_0069a5d0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_0069a540(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_0069a6d5:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_0069a6d5;
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


// ==== FUN_0069a7b0 @ 0x0069a7b0 ====

void FUN_0069a7b0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0069a4e0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x2d) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x2d) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x2d);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x2d);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x2d);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x2d);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_005a4100(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0069a870 @ 0x0069a870 ====

/* WARNING: Removing unreachable block (ram,0x0069a8cf) */

void FUN_0069a870(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int in_ECX;
  uint uVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  
  iVar3 = (int)param_2;
  puVar6 = *(undefined4 **)(in_ECX + 4);
  bVar11 = true;
  if (*(char *)((int)puVar6[1] + 0x2d) == '\0') {
    uVar1 = *(uint *)((int)param_2 + 0x14);
    puVar9 = (undefined4 *)puVar6[1];
    do {
      puVar6 = puVar9;
      uVar2 = puVar6[8];
      if ((uint)puVar6[9] < 0x10) {
        pbVar4 = (byte *)(puVar6 + 4);
      }
      else {
        pbVar4 = (byte *)puVar6[4];
      }
      if (uVar1 == 0) {
LAB_0069a900:
        if (uVar1 < uVar2) {
          uVar5 = 0xffffffff;
        }
        else {
          uVar5 = (uint)(uVar1 != uVar2);
        }
      }
      else {
        uVar8 = uVar1;
        if (uVar2 <= uVar1) {
          uVar8 = uVar2;
        }
        if (*(uint *)((int)param_2 + 0x18) < 0x10) {
          pbVar10 = (byte *)((int)param_2 + 4);
        }
        else {
          pbVar10 = *(byte **)((int)param_2 + 4);
        }
        bVar11 = false;
        uVar5 = 0;
        bVar12 = true;
        do {
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          bVar11 = *pbVar10 < *pbVar4;
          bVar12 = *pbVar10 == *pbVar4;
          pbVar10 = pbVar10 + 1;
          pbVar4 = pbVar4 + 1;
        } while (bVar12);
        if (!bVar12) {
          uVar5 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        }
        if (uVar5 == 0) goto LAB_0069a900;
      }
      bVar11 = (int)uVar5 < 0;
      if (bVar11) {
        puVar9 = (undefined4 *)*puVar6;
      }
      else {
        puVar9 = (undefined4 *)puVar6[2];
      }
    } while (*(char *)((int)puVar9 + 0x2d) == '\0');
  }
  param_2 = puVar6;
  if (bVar11) {
    if (puVar6 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar6 = (undefined4 *)FUN_0069a5d0(&param_2,1,puVar6,iVar3);
      *param_1 = *puVar6;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_0079c420();
  }
  puVar9 = param_2;
  if (*(uint *)(iVar3 + 0x18) < 0x10) {
    iVar7 = iVar3 + 4;
  }
  else {
    iVar7 = *(int *)(iVar3 + 4);
  }
  iVar7 = FUN_00403620(0,param_2[8],iVar7,*(undefined4 *)(iVar3 + 0x14));
  if (iVar7 < 0) {
    puVar6 = (undefined4 *)FUN_0069a5d0(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_0069a9e0 @ 0x0069a9e0 ====

undefined4 FUN_0069a9e0(void)

{
  return 0x4f;
}


// ==== FUN_0069a9f0 @ 0x0069a9f0 ====

void FUN_0069a9f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0069a370();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0069aa10 @ 0x0069aa10 ====

void FUN_0069aa10(void)

{
  return;
}


// ==== FUN_0069aa20 @ 0x0069aa20 ====

void FUN_0069aa20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ddca8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0069aa40 @ 0x0069aa40 ====

undefined4 FUN_0069aa40(void)

{
  (**(code **)(*DAT_00b5ae3c + 0x1c))();
  return 1;
}


// ==== FUN_0069aa50 @ 0x0069aa50 ====

void FUN_0069aa50(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(param_1);
  }
  return;
}


// ==== FUN_0069aa70 @ 0x0069aa70 ====

void FUN_0069aa70(void)

{
  int *piVar1;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_messenger_tree_009ddb54,0xe);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (local_8 < 0x10) {
    local_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    (**(code **)(*piVar1 + 0x30))();
    FUN_00573800();
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_0069aae0 @ 0x0069aae0 ====

undefined4 FUN_0069aae0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70340002) {
    FUN_0069aa70();
    return 1;
  }
  return 0;
}


// ==== FUN_0069ab10 @ 0x0069ab10 ====

void FUN_0069ab10(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 auStack_3a [22];
  void *pvStack_24;
  uint uStack_10;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x10))();
    FUN_005041e0(uVar2);
    (**(code **)(*piVar1 + 0xc))(auStack_3a + -6);
    (**(code **)(*piVar1 + 0x44))(1);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
  }
  return;
}


// ==== FUN_0069aba0 @ 0x0069aba0 ====

void FUN_0069aba0(void)

{
  int *piVar1;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_menuPop_009ddb70,0xb);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(0);
  }
  if (local_8 < 0x10) {
    *(undefined1 *)(in_ECX + 10) = 0;
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_0069ac00 @ 0x0069ac00 ====

void FUN_0069ac00(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  void *unaff_ESI;
  undefined4 uVar4;
  uint uVar5;
  undefined1 auStack_1e [2];
  undefined1 local_1c [4];
  void *local_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_Messenger_ui_messengerw_009ddb1c,0x26);
  iVar2 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  uVar4 = 0;
  piVar3 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar2 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar3;
  (**(code **)(*piVar3 + 0x40))();
  *(undefined1 *)(in_ECX + 8) = 1;
  *(undefined1 *)(in_ECX + 9) = 3;
  FUN_0069aa70();
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740(s_pan_noMsg_check_009ddb44,0xf);
  cVar1 = (**(code **)(*DAT_00b5ae3c + 0x5c))();
  uVar5 = (uint)(cVar1 == '\0');
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1e + -10);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x24))(uVar4,uVar4,uVar5);
  }
  if (uStack_14 < 0x10) {
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_0069acf0 @ 0x0069acf0 ====

void FUN_0069acf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ddca8;
  in_ECX[1] = 0;
  *(undefined1 *)((int)in_ECX + 10) = 0;
  FUN_0069ac00();
  return;
}


// ==== FUN_0069ad10 @ 0x0069ad10 ====

int FUN_0069ad10(void)

{
  int iVar1;
  int *piVar2;
  int extraout_EAX;
  int iVar3;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int extraout_EAX_02;
  int extraout_EAX_03;
  int extraout_EAX_04;
  int extraout_EAX_05;
  int extraout_EAX_06;
  int extraout_EAX_07;
  int in_ECX;
  int iVar4;
  undefined1 auStack_32 [2];
  undefined4 uStack_30;
  int aiStack_2c [2];
  void *pvStack_24;
  void *pvStack_20;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_messenger_tree_009ddbe8,0xe);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return extraout_EAX;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  iVar3 = (**(code **)(*piVar2 + 0x30))();
  iVar1 = *(int *)(iVar3 + 0xbc);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar3 + 0xc0) - iVar1 >> 2) <= *(uint *)(iVar3 + 0x94))) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  iVar4 = 0;
  uStack_30 = 0x4b;
  aiStack_2c[0] = 0x10;
  aiStack_2c[1] = 0x5d;
  pvStack_24 = (void *)0x2;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  uStack_c = 0;
  local_8 = 0xf;
  if (**(char **)(iVar1 + *(uint *)(iVar3 + 0x94) * 4) == '\0') {
    FUN_00401740(s_btn_chat_009ddc04,8);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
  }
  else {
    FUN_00401740(s_btn_chat_009ddbf8,8);
    FUN_0069ab10(&pvStack_20,auStack_32 + -6,&uStack_30);
    iVar4 = 0x10;
  }
  if (0xf < local_8) {
    _free(local_1c);
    return extraout_EAX_00;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(s_btn_sendMsg_009ddc1c,0xb);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x24))(0);
  }
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return extraout_EAX_01;
  }
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  uStack_10 = 0;
  uStack_c = 0xf;
  if (iVar4 == 0) {
    FUN_00401740(s_pan_seperator_0_009ddc38,0xf);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_24);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
    iVar4 = 0;
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return extraout_EAX_03;
    }
  }
  else {
    FUN_00401740(s_pan_seperator_0_009ddc28,0xf);
    FUN_0069ab10(&pvStack_24,auStack_32 + -10,aiStack_2c);
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return extraout_EAX_02;
    }
    iVar4 = iVar4 + 10;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  FUN_00401740(s_btn_moveGroup_009ddc58,0xd);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_24);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x24))(0);
  }
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return extraout_EAX_04;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_btn_delete_009ddc68,10);
  uStack_30 = 0xd;
  aiStack_2c[0] = iVar4;
  FUN_0069ab10(aiStack_2c + 1,&uStack_30,auStack_32 + -6);
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return extraout_EAX_05;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_pan_menuPop_bgM_009ddc80,0xf);
  uStack_30 = 0x65;
  aiStack_2c[0] = iVar4 + 0x10;
  FUN_0069ab10(aiStack_2c + 1,auStack_32 + -6,&uStack_30);
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return extraout_EAX_06;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_pan_menuPop_bgB_009ddc90,0xf);
  uStack_30 = 0x65;
  aiStack_2c[0] = 0xc;
  FUN_0069ab10(aiStack_2c + 1,auStack_32 + -6,&uStack_30);
  if (uStack_10 < 0x10) {
    return iVar4 + 0x10;
  }
  _free(pvStack_24);
  return extraout_EAX_07;
}


// ==== FUN_0069b090 @ 0x0069b090 ====

void FUN_0069b090(int *param_1)

{
  int in_ECX;
  undefined4 local_24;
  int local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_20 = FUN_0069ad10();
  local_20 = local_20 + 0x18;
  if (0xe6 < *param_1) {
    *param_1 = *param_1 + -0x65;
  }
  if (0x1b8 - local_20 < param_1[1]) {
    param_1[1] = param_1[1] - local_20;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_pan_menuPop_009ddb64,0xb);
  local_24 = 0x65;
  FUN_0069ab10(local_1c,param_1,&local_24);
  if (local_4 < 0x10) {
    *(undefined1 *)(in_ECX + 10) = 1;
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0069b130 @ 0x0069b130 ====

undefined4 FUN_0069b130(int param_1,int param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  int unaff_EBX;
  int local_2c;
  int iStack_28;
  int iStack_24;
  undefined1 auStack_20 [4];
  undefined1 local_1c [28];
  
  if (param_1 == 1) {
    if (param_3 != 1) {
      return 0;
    }
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009ddb7c,8);
    if (iVar2 == 0) {
      (**(code **)(*DAT_00b5ae3c + 0x1c))();
      FUN_0069aba0();
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_friend_009ddb88);
    if (cVar1 != '\0') {
      FUN_0069aba0();
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_chat_009ddb94);
    if (cVar1 != '\0') {
      FUN_00401830(s_messenger_tree_009ddba0);
      (**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_1c);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    cVar1 = FUN_004036a0(param_2,s_btn_delete_009ddbb0);
    if (cVar1 != '\0') {
      FUN_00401830(s_messenger_tree_009ddbbc);
      (**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_1c);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  else {
    if (param_1 == 0xe) {
      if ((param_3 == 1) || (param_3 == 2)) {
        (**(code **)(**(int **)(in_ECX + 4) + 0x5c))(&local_2c);
        iStack_28 = (param_3 >> 0x10) - unaff_EBX;
        iStack_24 = (param_3 & 0xffff) - local_2c;
        FUN_0069b090(&iStack_28);
        return 1;
      }
      return 0;
    }
    if (param_1 != 0) {
      return 0;
    }
    if (param_3 != 1) {
      return 0;
    }
    cVar1 = FUN_004036a0(param_2,s_pan_noMsg_009ddbcc);
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(*DAT_00b5ae3c + 0x5c))();
      (**(code **)(*DAT_00b5ae3c + 0x58))(cVar1 == '\0');
      FUN_00401830(s_pan_noMsg_check_009ddbd8);
      cVar1 = (**(code **)(*DAT_00b5ae3c + 0x5c))();
      FUN_0069aa50(auStack_20,cVar1 == '\0');
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  FUN_0069aba0();
  return 0;
}


// ==== FUN_0069b3c0 @ 0x0069b3c0 ====

undefined4 FUN_0069b3c0(void)

{
  return 0x4c;
}


// ==== FUN_0069b3d0 @ 0x0069b3d0 ====

void FUN_0069b3d0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009ddca8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0069b410 @ 0x0069b410 ====

undefined4 FUN_0069b410(void)

{
  return 0x70340003;
}


// ==== FUN_0069b420 @ 0x0069b420 ====

void FUN_0069b420(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ddcdc;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0069b480 @ 0x0069b480 ====

void FUN_0069b480(void)

{
  return;
}


// ==== FUN_0069b490 @ 0x0069b490 ====

uint FUN_0069b490(int *param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if ((uVar1 == 0x40001) && (*(char *)(*(int *)(in_ECX + 0x10) + 0x10) == '\x01')) {
    uVar1 = FUN_006df400();
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0069b540 @ 0x0069b540 ====

void FUN_0069b540(int param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      uVar3 = 0;
      if (param_1 == 0) {
        FUN_00587d10(10);
        return;
      }
      if (param_1 == 1) {
        uVar3 = 0xfffffff6;
      }
      FUN_00587d10(uVar3);
    }
  }
  return;
}


// ==== FUN_0069b5c0 @ 0x0069b5c0 ====

/* WARNING: Removing unreachable block (ram,0x0069b679) */
/* WARNING: Removing unreachable block (ram,0x0069b6c8) */
/* WARNING: Removing unreachable block (ram,0x0069b600) */

void FUN_0069b5c0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined4 uStack_30;
  
  uStack_30 = s_UI_EnvironmentWindow_ui_envwnd_t_009ddd28;
  FUN_00401740();
  uStack_30 = (char *)0x69b5f4;
  iVar1 = FUN_00410500();
  uStack_30 = (char *)(iVar1 + 0x3c);
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))();
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  (**(code **)(*DAT_00b5a750 + 8))(0x1f);
  FUN_00401740(s_pan_cam_009ddd4c,7);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x2c);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x24))(0);
  }
  FUN_00401740(s_pan_etc_009ddd54,7);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_30);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x24))(0);
  }
  return;
}


// ==== FUN_0069b6e0 @ 0x0069b6e0 ====

/* WARNING: Removing unreachable block (ram,0x0069b9e5) */

void FUN_0069b6e0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 auStack_14e [26];
  void *local_134;
  undefined1 local_130;
  undefined4 uStack_124;
  uint local_120;
  void *local_11c;
  undefined1 uStack_118;
  undefined4 uStack_10c;
  uint uStack_108;
  undefined4 uStack_104;
  void *pvStack_100;
  undefined1 uStack_fc;
  undefined4 uStack_f0;
  uint uStack_ec;
  undefined4 uStack_e8;
  void *local_e0;
  undefined1 local_dc;
  undefined4 uStack_d0;
  void *local_cc;
  uint local_c8;
  undefined4 uStack_bc;
  uint uStack_b8;
  undefined4 uStack_b4;
  void *local_a8;
  undefined1 local_a4;
  undefined4 uStack_98;
  uint local_94;
  void *local_90;
  undefined1 uStack_8c;
  undefined4 uStack_80;
  uint uStack_7c;
  void *pvStack_78;
  undefined1 uStack_74;
  undefined4 uStack_68;
  uint uStack_64;
  void *pvStack_60;
  undefined1 uStack_5c;
  uint uStack_4c;
  undefined4 uStack_48;
  void *pvStack_44;
  undefined1 uStack_40;
  uint uStack_30;
  undefined4 uStack_2c;
  void *pvStack_28;
  undefined1 uStack_24;
  uint uStack_14;
  undefined4 uStack_10;
  
  iVar1 = *(int *)(in_ECX + 0x18);
  if (iVar1 == 0) {
    local_11c = (void *)0xf;
    local_120 = 0;
    local_130 = 0;
    FUN_00401740(s_pan_light_009ddd5c,9);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_134);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(1);
    }
    if (0xf < local_120) {
      _free(local_134);
      return;
    }
    local_120 = 0xf;
    uStack_124 = 0;
    local_134 = (void *)((uint)local_134 & 0xffffff00);
    uStack_e8 = 0xf;
    uStack_ec = 0;
    uStack_fc = 0;
    FUN_00401740(s_pan_time_009ddd68,8);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_100);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(1);
    }
    if (0xf < uStack_ec) {
      _free(pvStack_100);
      return;
    }
    uStack_ec = 0xf;
    uStack_f0 = 0;
    pvStack_100 = (void *)((uint)pvStack_100 & 0xffffff00);
    uStack_b4 = 0xf;
    uStack_b8 = 0;
    local_c8 = local_c8 & 0xffffff00;
    FUN_00401740(s_pan_cam_009ddd74,7);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_cc);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
    if (0xf < uStack_b8) {
      _free(local_cc);
      return;
    }
    uStack_b8 = 0xf;
    uStack_bc = 0;
    local_cc = (void *)((uint)local_cc & 0xffffff00);
    uStack_10 = 0xf;
    uStack_14 = 0;
    uStack_24 = 0;
    FUN_00401740(s_pan_etc_009ddd7c,7);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_28);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
    if (0xf < uStack_14) {
      _free(pvStack_28);
      return;
    }
  }
  else if (iVar1 == 1) {
    local_c8 = 0xf;
    local_cc = (void *)0x0;
    local_dc = 0;
    FUN_00401740(s_pan_cam_009ddd84,7);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_e0);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(1);
    }
    if ((void *)0xf < local_cc) {
      _free(local_e0);
      return;
    }
    local_cc = (void *)0xf;
    uStack_d0 = 0;
    local_e0 = (void *)((uint)local_e0 & 0xffffff00);
    pvStack_78 = (void *)0xf;
    uStack_7c = 0;
    uStack_8c = 0;
    FUN_00401740(s_pan_time_009ddd8c,8);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_90);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
    if (0xf < uStack_7c) {
      _free(local_90);
      return;
    }
    uStack_7c = 0xf;
    uStack_80 = 0;
    local_90 = (void *)((uint)local_90 & 0xffffff00);
    FUN_00401740(s_pan_light_009ddd98,9);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_14e + -10);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
    uStack_2c = 0xf;
    uStack_30 = 0;
    uStack_40 = 0;
    FUN_00401740(s_pan_etc_009ddda4,7);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_44);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
    if (0xf < uStack_30) {
      _free(pvStack_44);
      return;
    }
  }
  else if (iVar1 == 2) {
    local_90 = (void *)0xf;
    local_94 = 0;
    local_a4 = 0;
    FUN_00401740(s_pan_cam_009dddac,7);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_a8);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
    if (0xf < local_94) {
      _free(local_a8);
      return;
    }
    local_94 = 0xf;
    uStack_98 = 0;
    local_a8 = (void *)((uint)local_a8 & 0xffffff00);
    uStack_104 = 0xf;
    uStack_108 = 0;
    uStack_118 = 0;
    FUN_00401740(s_pan_time_009dddb4,8);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_11c);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(1);
    }
    if (0xf < uStack_108) {
      _free(local_11c);
      return;
    }
    uStack_108 = 0xf;
    uStack_10c = 0;
    local_11c = (void *)((uint)local_11c & 0xffffff00);
    pvStack_60 = (void *)0xf;
    uStack_64 = 0;
    uStack_74 = 0;
    FUN_00401740(s_pan_light_009dddc0,9);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_78);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
    if (0xf < uStack_64) {
      _free(pvStack_78);
      return;
    }
    uStack_64 = 0xf;
    uStack_68 = 0;
    pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
    uStack_48 = 0xf;
    uStack_4c = 0;
    uStack_5c = 0;
    FUN_00401740(s_pan_etc_009dddcc,7);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_60);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(1);
    }
    if (0xf < uStack_4c) {
      _free(pvStack_60);
      return;
    }
  }
  return;
}


// ==== FUN_0069bc80 @ 0x0069bc80 ====

void FUN_0069bc80(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009dde50;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[1] = 0;
  FUN_0069b5c0();
  pvVar1 = operator_new(4);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006e1360();
  }
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(4);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006e0ed0();
  }
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(0x30);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006dfad0(in_ECX[1],in_ECX[2],in_ECX[3]);
  }
  in_ECX[4] = uVar2;
  pvVar1 = operator_new(0x14);
  if (pvVar1 == (void *)0x0) {
    in_ECX[6] = 0;
    in_ECX[5] = 0;
    return;
  }
  uVar2 = FUN_006e0e70(in_ECX[1],in_ECX[2],in_ECX[3]);
  in_ECX[6] = 0;
  in_ECX[5] = uVar2;
  return;
}


// ==== FUN_0069bd40 @ 0x0069bd40 ====

void FUN_0069bd40(void)

{
  undefined4 *in_ECX;
  undefined4 unaff_EBX;
  
  *in_ECX = &PTR_FUN_009dde50;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  in_ECX[4] = 0;
  if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[5])(1);
  }
  in_ECX[5] = 0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if (in_ECX[8] == 0) {
    in_ECX[8] = 0;
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  FUN_00405de0(in_ECX[8],in_ECX[9],in_ECX + 7,unaff_EBX);
  _free((void *)in_ECX[8]);
  return;
}


// ==== FUN_0069bde0 @ 0x0069bde0 ====

undefined4 FUN_0069bde0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined1 auStack_e [14];
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      FUN_00404fb0(param_1,0x5f,auStack_e + -6);
      iVar2 = FUN_00405d30(1);
      iVar2 = FUN_00403620(0,*(undefined4 *)(iVar2 + 0x14),&DAT_009dde34,3);
      if (iVar2 == 0) {
        FUN_00406250();
        return 1;
      }
      FUN_00406250();
    }
  }
  return 0;
}


// ==== FUN_0069be70 @ 0x0069be70 ====

undefined4 FUN_0069be70(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  undefined1 auStack_1c [28];
  
  iVar4 = *(int *)(in_ECX + 0x18);
  if (iVar4 != 0) {
    if (iVar4 == 1) {
      cVar1 = (**(code **)(**(int **)(in_ECX + 0x14) + 8))(param_1,param_2,param_3,param_4);
      if (cVar1 != '\0') {
        return 1;
      }
      goto LAB_0069beaf;
    }
    if (iVar4 != 2) goto LAB_0069beaf;
  }
  cVar1 = (**(code **)(**(int **)(in_ECX + 0x10) + 8))(param_1,param_2,param_3,param_4);
  if (cVar1 != '\0') {
    return 1;
  }
LAB_0069beaf:
  if (param_1 == 0x14) {
    if ((param_3 == 7) && (cVar1 = FUN_0069bde0(param_2), cVar1 != '\0')) {
      return 1;
    }
  }
  else if (param_1 == 1) {
    if (param_3 == 1) {
      cVar1 = FUN_004036a0(param_2,s_btn_exit_009dddd4);
      if (cVar1 != '\0') {
        puVar2 = operator_new(4);
        if (puVar2 == (undefined4 *)0x0) {
          FUN_00797a20(0);
          return 1;
        }
        *puVar2 = &PTR_FUN_009b14d0;
        FUN_00797a20(puVar2);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_plus_009ddde0);
      if (cVar1 != '\0') {
        FUN_00401830(s_pan_bg_009dddec);
        FUN_0069b540(auStack_1c,0);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar1 = FUN_004036a0(param_2,s_btn_minus_009dddf4);
      if (cVar1 != '\0') {
        FUN_00401830(s_pan_bg_009dde00);
        piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1c);
        if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
          FUN_00587d10(0xf6);
        }
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar1 = FUN_004036a0(param_2,s_btn_open_009dde08);
      if (cVar1 != '\0') {
        FUN_006e18e0();
        FUN_006df480();
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_save_009dde14);
      if (cVar1 != '\0') {
        FUN_006e1ab0();
        return 1;
      }
    }
  }
  else if (((param_1 == 0x15) && (param_3 == 1)) &&
          (cVar1 = FUN_004036a0(param_2,s_combo_select_type_009dde20), cVar1 != '\0')) {
    *(undefined4 *)(in_ECX + 0x18) = param_4;
    FUN_0069b6e0();
    return 1;
  }
  return 0;
}


// ==== FUN_0069c0a0 @ 0x0069c0a0 ====

undefined4 FUN_0069c0a0(void)

{
  return 0x37;
}


// ==== FUN_0069c0b0 @ 0x0069c0b0 ====

void FUN_0069c0b0(byte param_1)

{
  void *in_ECX;
  
  FUN_0069bd40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0069c0d0 @ 0x0069c0d0 ====

undefined4 FUN_0069c0d0(void)

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


// ==== FUN_0069c100 @ 0x0069c100 ====

void FUN_0069c100(void)

{
  return;
}


// ==== FUN_0069c110 @ 0x0069c110 ====

void FUN_0069c110(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      FUN_00558730(param_1);
    }
  }
  return;
}


// ==== FUN_0069c140 @ 0x0069c140 ====

int FUN_0069c140(void)

{
  int *piVar1;
  int extraout_EAX;
  int iVar2;
  int extraout_EAX_00;
  int in_ECX;
  int unaff_retaddr;
  void *local_38;
  undefined1 local_34;
  undefined4 uStack_28;
  uint local_24;
  undefined4 local_20;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(&DAT_009ddfab,0);
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_edit_gradeName_009ddfac,0xe);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if (0xf < local_24) {
    _free(local_38);
    return extraout_EAX;
  }
  local_24 = 0xf;
  uStack_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      FUN_00550970(&local_20);
    }
  }
  *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
  *(undefined4 *)(unaff_retaddr + 0x14) = 0;
  *(undefined1 *)(unaff_retaddr + 4) = 0;
  FUN_00401660(&local_20,0,0xffffffff);
  if (local_8 < 0x10) {
    return unaff_retaddr;
  }
  _free(local_1c);
  return extraout_EAX_00;
}


// ==== FUN_0069c210 @ 0x0069c210 ====

void FUN_0069c210(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 *puVar4;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  puVar4 = *(undefined1 **)(in_ECX + 0xc);
  puVar2 = *(undefined1 **)(in_ECX + 0x10);
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  if (puVar4 != puVar2) {
    do {
      uVar1 = *puVar4;
      uVar3 = *(undefined4 *)(puVar4 + 4);
      FUN_00401660(puVar4 + 8,0,0xffffffff);
      (**(code **)(*DAT_00b5aca8 + 0xf4))(uVar1,local_1c,uVar3);
      puVar4 = puVar4 + 0x24;
    } while (puVar4 != puVar2);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
  }
  return;
}


// ==== FUN_0069c290 @ 0x0069c290 ====

void FUN_0069c290(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_50 [5];
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  void *pvStack_2c;
  undefined4 uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  FUN_00401740(s_btn_list__d_009ddf90,0xb);
  FUN_00404230(local_50);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_50);
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x30))();
    if (piVar1 != (int *)0x0) {
      uStack_38 = 0;
      uStack_34 = 0;
      uStack_18 = 0xf;
      uStack_1c = 0;
      pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
      uStack_14 = 1;
      uStack_10 = 0;
      uStack_c = 1;
      uStack_8 = 0;
      uStack_7 = 0;
      uVar2 = FUN_00558120();
      FUN_005523f0(uVar2);
      FUN_00401660(param_1,0,0xffffffff);
      (**(code **)(*piVar1 + 8))(&uStack_38);
      FUN_00558730(param_1 == *(int *)(in_ECX + 0x18));
      if (0xf < uStack_18) {
        _free(pvStack_2c);
        return;
      }
    }
  }
  if (uStack_3c < 0x10) {
    return;
  }
  _free(local_50[0]);
  return;
}


// ==== FUN_0069c390 @ 0x0069c390 ====

void FUN_0069c390(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  void *local_40 [5];
  uint uStack_2c;
  undefined1 local_24;
  undefined4 local_20;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  uVar4 = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  uVar5 = 0;
  do {
    iVar3 = *(int *)(in_ECX + 0xc);
    if ((iVar3 == 0) || ((uint)((*(int *)(in_ECX + 0x10) - iVar3) / 0x24) <= uVar5)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    local_24 = *(undefined1 *)(uVar4 + iVar3);
    local_20 = *(undefined4 *)(uVar4 + 4 + iVar3);
    FUN_00401660(uVar4 + 8 + iVar3,0,0xffffffff);
    FUN_0069c290(uVar5,&local_1c);
    uVar4 = uVar4 + 0x24;
    uVar5 = uVar5 + 1;
  } while (uVar4 < 0x168);
  FUN_00401740(s_btn_list__d_009ddedc,0xb);
  uVar1 = FUN_00404230(local_40);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar1);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x30))();
    if (iVar3 != 0) {
      FUN_00558730(1);
    }
  }
  if (0xf < uStack_2c) {
    _free(local_40[0]);
    return;
  }
  if (local_8 < 0x10) {
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_0069c4b0 @ 0x0069c4b0 ====

/* WARNING: Removing unreachable block (ram,0x0069c52a) */

undefined4 FUN_0069c4b0(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xc);
  if ((iVar1 == 0) || ((uint)((*(int *)(in_ECX + 0x10) - iVar1) / 0x24) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  iVar1 = iVar1 + param_1 * 0x24;
  uVar2 = *(uint *)(iVar1 + 4);
  FUN_00401660(iVar1 + 8,0,0xffffffff);
  return CONCAT31((int3)(uVar2 >> 8),(param_2 & uVar2) != 0);
}


// ==== FUN_0069c550 @ 0x0069c550 ====

void FUN_0069c550(void)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int in_ECX;
  undefined4 *puVar7;
  void *local_40;
  undefined1 local_3c;
  undefined4 uStack_30;
  uint local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  local_28 = 0xf;
  local_2c = 0;
  local_3c = 0;
  FUN_00401740(s_edit_gradeName_009ddf9c,0xe);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_40);
  if (0xf < local_2c) {
    _free(local_40);
    return;
  }
  local_2c = 0xf;
  uStack_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  if (piVar3 != (int *)0x0) {
    iVar4 = (**(code **)(*piVar3 + 0x30))();
    if (iVar4 != 0) {
      uVar2 = *(uint *)(in_ECX + 0x18);
      iVar4 = *(int *)(in_ECX + 0xc);
      if ((iVar4 == 0) || ((uint)((*(int *)(in_ECX + 0x10) - iVar4) / 0x24) <= uVar2)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      iVar1 = iVar4 + uVar2 * 0x24;
      local_28 = CONCAT31(local_28._1_3_,*(undefined1 *)(iVar4 + uVar2 * 0x24));
      uStack_24 = *(undefined4 *)(iVar1 + 4);
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      FUN_00401660(iVar1 + 8,0,0xffffffff);
      FUN_00551410(auStack_20);
      puVar5 = operator_new(8);
      puVar7 = (undefined4 *)0x0;
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = &PTR_FUN_009b1798;
        puVar7 = puVar5;
      }
      uVar6 = (**(code **)(*piVar3 + 4))();
      puVar7[1] = uVar6;
      FUN_00797a20(puVar7);
      (**(code **)(*piVar3 + 0x5c))();
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return;
      }
    }
  }
  return;
}


// ==== FUN_0069c690 @ 0x0069c690 ====

/* WARNING: Removing unreachable block (ram,0x0069ca6e) */
/* WARNING: Removing unreachable block (ram,0x0069ca1a) */
/* WARNING: Removing unreachable block (ram,0x0069cac2) */
/* WARNING: Removing unreachable block (ram,0x0069c9b2) */
/* WARNING: Removing unreachable block (ram,0x0069c94a) */

void FUN_0069c690(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  void *unaff_EDI;
  undefined4 *_Memory;
  void *_Memory_00;
  uint uVar8;
  undefined4 uStack_34;
  undefined4 local_20;
  void *local_1c;
  uint local_18;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  uStack_34 = (void **)0xb;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = local_18 & 0xffffff00;
  FUN_00401740();
  uStack_34 = (void **)0x1;
  uVar1 = FUN_0069c4b0();
  local_20 = (void *)CONCAT31(local_20._1_3_,uVar1);
  uStack_34 = &local_1c;
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
    FUN_00558730();
  }
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740();
  uVar1 = FUN_0069c4b0();
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
    FUN_00558730();
  }
  if (0xf < uStack_c) {
    _free(local_20);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  FUN_00401740();
  uVar2 = FUN_0069c4b0();
  iVar4 = (int)register0x00000010 + -0x24;
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar3 != (int *)0x0) && (iVar5 = (**(code **)(*piVar3 + 0x30))(), iVar5 != 0)) {
    FUN_00558730();
  }
  if (0xf < uStack_10) {
    _free((void *)CONCAT31((int3)((uint)unaff_EBX >> 8),uVar1));
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740();
  uVar1 = FUN_0069c4b0();
  iVar5 = (int)register0x00000010 + -0x28;
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar3 != (int *)0x0) && (iVar6 = (**(code **)(*piVar3 + 0x30))(), iVar6 != 0)) {
    FUN_00558730();
  }
  if (0xf < uStack_14) {
    _free((void *)CONCAT31((int3)((uint)unaff_EBP >> 8),uVar2));
    return;
  }
  uStack_14 = 0xf;
  local_18 = 0;
  FUN_00401740();
  iVar6 = (int)register0x00000010 + -0x2c;
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar3 != (int *)0x0) && (iVar7 = (**(code **)(*piVar3 + 0x30))(), iVar7 != 0)) {
    FUN_00558730();
  }
  if (0xf < local_18) {
    _free((void *)CONCAT31((int3)((uint)unaff_ESI >> 8),uVar1));
    return;
  }
  local_18 = 0xf;
  local_1c = (void *)0x0;
  FUN_00401740();
  _Memory_00 = (void *)((int)register0x00000010 + -0x30);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar3 != (int *)0x0) && (iVar7 = (**(code **)(*piVar3 + 0x30))(), iVar7 != 0)) {
    FUN_00558730();
  }
  if ((void *)0xf < local_1c) {
    _free(unaff_EDI);
    return;
  }
  local_1c = (void *)0xf;
  FUN_00401740(s_btn_check_12_009ddf34);
  FUN_0069c4b0(*(undefined4 *)(in_ECX + 0x18));
  _Memory = &uStack_34;
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar3 != (int *)0x0) && (iVar7 = (**(code **)(*piVar3 + 0x30))(), iVar7 != 0)) {
    FUN_00558730(iVar4);
  }
  uStack_34 = (void **)((uint)uStack_34 & 0xffffff00);
  FUN_00401740(s_btn_check_1_009ddf44,0xb);
  FUN_0069c4b0(*(undefined4 *)(in_ECX + 0x18),0x20);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x38);
  if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
    FUN_00558730(iVar5);
  }
  FUN_00401740(s_btn_check_3_009ddf50,0xb);
  FUN_0069c4b0(*(undefined4 *)(in_ECX + 0x18),4);
  iVar4 = (int)register0x00000010 + -0x3c;
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(iVar4);
  if ((piVar3 != (int *)0x0) && (iVar5 = (**(code **)(*piVar3 + 0x30))(), iVar5 != 0)) {
    FUN_00558730(iVar6);
  }
  FUN_00401740(s_btn_check_5_009ddf5c,0xb);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x40);
  if ((piVar3 != (int *)0x0) && (iVar5 = (**(code **)(*piVar3 + 0x30))(), iVar5 != 0)) {
    FUN_00558730(1);
  }
  FUN_00401740(s_btn_check_7_009ddf68,0xb);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x44);
  if ((piVar3 != (int *)0x0) && (iVar5 = (**(code **)(*piVar3 + 0x30))(), iVar5 != 0)) {
    FUN_00558730(1);
  }
  uStack_34 = (void **)0x0;
  FUN_00401740(s_btn_check_9_009ddf74,0xb);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x48);
  if ((piVar3 != (int *)0x0) && (iVar5 = (**(code **)(*piVar3 + 0x30))(), iVar5 != 0)) {
    FUN_00558730(1);
  }
  if (0xf < uStack_34) {
    _free(_Memory_00);
    return;
  }
  uStack_34 = (void **)0xf;
  uVar8 = 0;
  FUN_00401740(s_btn_check_11_009ddf80,0xc);
  FUN_0069c4b0(*(undefined4 *)(in_ECX + 0x18),0x80);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x4c);
  if ((piVar3 != (int *)0x0) && (iVar5 = (**(code **)(*piVar3 + 0x30))(), iVar5 != 0)) {
    FUN_00558730(iVar4);
  }
  if (uVar8 < 0x10) {
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_0069cba0 @ 0x0069cba0 ====

void FUN_0069cba0(void)

{
  undefined4 *in_ECX;
  undefined4 unaff_ESI;
  
  *in_ECX = &PTR_FUN_009ddff8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if (in_ECX[3] == 0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  FUN_0069d3a0(in_ECX[3],in_ECX[4],in_ECX + 2,unaff_ESI);
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_0069cc00 @ 0x0069cc00 ====

void FUN_0069cc00(void)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 *puVar4;
  int iVar5;
  undefined1 auStack_220 [4];
  undefined4 uStack_21c;
  void *pvStack_214;
  undefined4 uStack_204;
  uint uStack_200;
  undefined1 uStack_1fc;
  undefined1 uStack_1fb;
  undefined4 uStack_1fa;
  char acStack_1f6 [38];
  void *local_1d0 [5];
  uint uStack_1bc;
  void *pvStack_1ac;
  undefined4 uStack_19c;
  uint uStack_198;
  undefined4 auStack_18a [98];
  
  (**(code **)(*DAT_00b5aca8 + 0x18))(local_1d0);
  acStack_1f6[0] = '\0';
  if (*(int *)(in_ECX + 0xc) != 0) {
    FUN_0069d3a0(*(int *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x10),in_ECX + 8,unaff_EBX);
    _free(*(void **)(in_ECX + 0xc));
    return;
  }
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  puVar4 = auStack_18a;
  iVar5 = 10;
  do {
    uStack_21c = *puVar4;
    uStack_1fc = *(undefined1 *)((int)puVar4 + -2);
    auStack_220[0] = *(undefined1 *)((int)puVar4 + -1);
    uStack_200 = 0xf;
    uStack_204 = 0;
    pvStack_214 = (void *)((uint)pvStack_214 & 0xffffff00);
    uVar2 = 0;
    do {
      cVar1 = *(char *)((int)puVar4 + uVar2 + 4);
      acStack_1f6[uVar2] = cVar1;
      if (cVar1 == '\0') goto LAB_0069cca8;
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x21);
    acStack_1f6[0] = '\0';
LAB_0069cca8:
    pcVar3 = acStack_1f6;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    uStack_1fb = auStack_220[0];
    uStack_1fa = uStack_21c;
    FUN_00401740(acStack_1f6,(int)pcVar3 - (int)(acStack_1f6 + 1));
    FUN_0069d9f0(auStack_220);
    if (0xf < uStack_200) {
      _free(pvStack_214);
      return;
    }
    puVar4 = (undefined4 *)((int)puVar4 + 0x27);
    iVar5 = iVar5 + -1;
    uStack_200 = 0xf;
    uStack_204 = 0;
    pvStack_214 = (void *)((uint)pvStack_214 & 0xffffff00);
    if (iVar5 == 0) {
      if (0xf < uStack_198) {
        _free(pvStack_1ac);
        return;
      }
      uStack_198 = 0xf;
      uStack_19c = 0;
      pvStack_1ac = (void *)((uint)pvStack_1ac & 0xffffff00);
      if (uStack_1bc < 0x10) {
        return;
      }
      _free(local_1d0[0]);
      return;
    }
  } while( true );
}


// ==== FUN_0069cd70 @ 0x0069cd70 ====

void FUN_0069cd70(void)

{
  FUN_0069cc00();
  FUN_0069c390();
  FUN_0069c550();
  FUN_0069c690();
  return;
}


// ==== FUN_0069cd90 @ 0x0069cd90 ====

/* WARNING: Removing unreachable block (ram,0x0069ceec) */

void FUN_0069cd90(void)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 auStack_26c [12];
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  char *pcStack_254;
  int iStack_238;
  void *pvStack_214;
  uint uStack_200;
  undefined1 auStack_1fc [6];
  char acStack_1f6 [38];
  void *local_1d0;
  uint uStack_1bc;
  void *pvStack_1ac;
  undefined4 uStack_19c;
  uint uStack_198;
  undefined4 auStack_18c [99];
  
  if ((*(int *)(in_ECX + 0xc) == 0) ||
     ((uint)((*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc)) / 0x24) <= *(uint *)(in_ECX + 0x18))
     ) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(*DAT_00b5aca8 + 0x18))();
  puVar5 = (undefined4 *)((int)auStack_18c + *(int *)(in_ECX + 0x18) * 0x27);
  puVar6 = (undefined4 *)auStack_1fc;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)puVar6 = *(undefined2 *)puVar5;
  pcVar3 = acStack_1f6;
  *(undefined1 *)((int)puVar6 + 2) = *(undefined1 *)((int)puVar5 + 2);
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcStack_254 = acStack_1f6;
  uStack_258 = 0x69ce3c;
  FUN_00401740();
  pcStack_254 = (char *)0x69ce4c;
  iVar4 = FUN_0069c140();
  if (*(uint *)(iVar4 + 0x18) < 0x10) {
    pcStack_254 = (char *)(iVar4 + 4);
  }
  else {
    pcStack_254 = *(char **)(iVar4 + 4);
  }
  uStack_258 = 0;
  uStack_25c = 0;
  uStack_260 = 0x69ce72;
  iVar4 = FUN_00403620();
  if ((iVar4 != 0) || (bVar2 = false, auStack_1fc._2_4_ != *(int *)(iStack_238 + 4))) {
    bVar2 = true;
  }
  if (0xf < uStack_200) {
    pcStack_254 = (char *)0x69ce98;
    _free(pvStack_214);
    return;
  }
  if (bVar2) {
    iVar4 = *DAT_00b5aca8;
    FUN_0069c140(auStack_26c);
    (**(code **)(iVar4 + 0x60))(*(undefined1 *)(in_ECX + 0x18));
  }
  FUN_0069cc00();
  FUN_0069c390();
  FUN_0069c550();
  FUN_0069c690();
  if (0xf < uStack_198) {
    pcStack_254 = (char *)0x69cf20;
    _free(pvStack_1ac);
    return;
  }
  uStack_198 = 0xf;
  uStack_19c = 0;
  pvStack_1ac = (void *)((uint)pvStack_1ac & 0xffffff00);
  if (uStack_1bc < 0x10) {
    return;
  }
  pcStack_254 = (char *)0x69cf4b;
  _free(local_1d0);
  return;
}


// ==== FUN_0069cf60 @ 0x0069cf60 ====

undefined4 FUN_0069cf60(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  int in_ECX;
  undefined *puVar8;
  char *pcVar9;
  undefined1 local_38 [4];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_1c [28];
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009ddfbc,8);
  if (iVar2 == 0) {
    puVar3 = operator_new(4);
    if (puVar3 == (undefined4 *)0x0) {
      FUN_00797a20(0);
      return 1;
    }
    *puVar3 = &PTR_FUN_009d7f70;
    FUN_00797a20(puVar3);
    return 1;
  }
  cVar1 = FUN_004036a0(param_2,s_btn_apply_009ddfc8);
  if (cVar1 != '\0') {
    puVar4 = (undefined1 *)FUN_0069d510(*(undefined4 *)(in_ECX + 0x18));
    uVar6 = *(undefined4 *)(puVar4 + 4);
    iVar2 = *DAT_00b5aca8;
    uVar5 = FUN_0069c140(local_38);
    (**(code **)(iVar2 + 0xf4))(*puVar4,uVar5,uVar6);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  FUN_00404fb0(param_2,0x5f,local_38);
  puVar8 = &DAT_009ddfd4;
  uVar6 = FUN_00405d30(1);
  cVar1 = FUN_004036a0(uVar6,puVar8);
  if (cVar1 != '\0') {
    FUN_0069cd90();
    uVar5 = 0;
    FUN_00401830(s_btn_list__d_009ddfdc);
    uVar6 = FUN_00404230(local_1c);
    FUN_0069c110(uVar6,uVar5);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  pcVar9 = s_check_009ddfe8;
  uVar6 = FUN_00405d30(1);
  cVar1 = FUN_004036a0(uVar6,pcVar9);
  if (cVar1 == '\0') {
    FUN_00406250();
    return 0;
  }
  if (*(int *)(in_ECX + 0x18) == 0) goto LAB_0069d1d7;
  iVar2 = FUN_0069d510(*(int *)(in_ECX + 0x18));
  uVar6 = FUN_00405d30(2);
  uVar6 = thunk_FUN_00796fb0(uVar6);
  switch(uVar6) {
  case 0:
    uVar7 = *(uint *)(iVar2 + 4);
    if ((uVar7 & 1) == 0) {
      uVar7 = uVar7 | 1;
    }
    else {
      uVar7 = uVar7 - 1;
    }
    break;
  case 1:
    uVar7 = *(uint *)(iVar2 + 4);
    if ((uVar7 & 0x20) == 0) {
      uVar7 = uVar7 | 0x20;
    }
    else {
      uVar7 = uVar7 - 0x20;
    }
    break;
  case 2:
    uVar7 = *(uint *)(iVar2 + 4);
    if ((uVar7 & 2) == 0) {
      uVar7 = uVar7 | 2;
    }
    else {
      uVar7 = uVar7 - 2;
    }
    break;
  case 3:
    uVar7 = *(uint *)(iVar2 + 4);
    if ((uVar7 & 4) == 0) {
      uVar7 = uVar7 | 4;
    }
    else {
      uVar7 = uVar7 - 4;
    }
    break;
  case 4:
    uVar7 = *(uint *)(iVar2 + 4);
    if ((uVar7 & 8) == 0) {
      uVar7 = uVar7 | 8;
    }
    else {
      uVar7 = uVar7 - 8;
    }
    break;
  default:
    goto switchD_0069d13f_caseD_5;
  case 6:
    uVar7 = *(uint *)(iVar2 + 4);
    if ((uVar7 & 0x10) == 0) {
      uVar7 = uVar7 | 0x10;
    }
    else {
      uVar7 = uVar7 - 0x10;
    }
    break;
  case 0xb:
    uVar7 = *(uint *)(iVar2 + 4);
    if ((uVar7 & 0x80) == 0) {
      uVar7 = uVar7 | 0x80;
    }
    else {
      uVar7 = uVar7 - 0x80;
    }
    break;
  case 0xc:
    uVar7 = *(uint *)(iVar2 + 4);
    if ((uVar7 & 0x100) == 0) {
      uVar7 = uVar7 | 0x100;
    }
    else {
      uVar7 = uVar7 - 0x100;
    }
  }
  *(uint *)(iVar2 + 4) = uVar7;
switchD_0069d13f_caseD_5:
  FUN_0069c690();
LAB_0069d1d7:
  FUN_00406250();
  return 1;
}


// ==== FUN_0069d220 @ 0x0069d220 ====

void FUN_0069d220(void)

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
  FUN_00401740(s_UI_Game2_Guild_ui_gradewnd_txt_009ddebc,0x1e);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_0069cc00();
    FUN_0069c390();
    FUN_0069c550();
    FUN_0069c690();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0069d2b0 @ 0x0069d2b0 ====

undefined4 FUN_0069d2b0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70320025) {
    FUN_0069cc00();
    FUN_0069c390();
    FUN_0069c550();
    FUN_0069c690();
    return 1;
  }
  return 0;
}


// ==== FUN_0069d2f0 @ 0x0069d2f0 ====

void FUN_0069d2f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ddff8;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  FUN_0069d220();
  return;
}


// ==== FUN_0069d320 @ 0x0069d320 ====

void FUN_0069d320(undefined1 *param_1)

{
  char cVar1;
  undefined1 *in_ECX;
  uint uVar2;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  *(undefined4 *)(in_ECX + 2) = *(undefined4 *)(param_1 + 2);
  uVar2 = 0;
  do {
    cVar1 = param_1[uVar2 + 6];
    in_ECX[uVar2 + 6] = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x21);
  in_ECX[6] = 0;
  return;
}


// ==== FUN_0069d360 @ 0x0069d360 ====

void FUN_0069d360(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_1 = *param_3;
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_3 + 4);
      FUN_00401660(param_3 + 8,0,0xffffffff);
      param_1 = param_1 + 0x24;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_0069d3a0 @ 0x0069d3a0 ====

void FUN_0069d3a0(int param_1,int param_2)

{
  uint *puVar1;
  
  if (param_1 != param_2) {
    puVar1 = (uint *)(param_1 + 0x20);
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


// ==== FUN_0069d3f0 @ 0x0069d3f0 ====

undefined1 * FUN_0069d3f0(int param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x24;
    puVar2 = param_3 + -0x24;
    *puVar2 = *(undefined1 *)(param_2 + -0x24);
    *(undefined4 *)(param_3 + -0x20) = *(undefined4 *)(param_2 + -0x20);
    FUN_00401660(param_2 + -0x1c,0,0xffffffff);
    param_2 = iVar1;
    param_3 = puVar2;
  } while (iVar1 != param_1);
  return puVar2;
}


// ==== FUN_0069d440 @ 0x0069d440 ====

void FUN_0069d440(undefined1 *param_1,undefined1 *param_2)

{
  if (param_1 != (undefined1 *)0x0) {
    *param_1 = *param_2;
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
    *(undefined4 *)(param_1 + 0x20) = 0xf;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    param_1[0xc] = 0;
    FUN_00401660(param_2 + 8,0,0xffffffff);
  }
  return;
}


// ==== FUN_0069d480 @ 0x0069d480 ====

int FUN_0069d480(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c740;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x24) {
    FUN_0069d440(param_3,param_1);
    param_3 = param_3 + 0x24;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0069d4ea @ 0x0069d4ea ====

void Catch_0069d4ea(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x24) {
    FUN_005c0d50(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0069d510 @ 0x0069d510 ====

int FUN_0069d510(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if (param_1 < (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x24)) {
      return iVar1 + param_1 * 0x24;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0085b340();
}


// ==== FUN_0069d550 @ 0x0069d550 ====

void FUN_0069d550(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c750;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_0069d440(param_1,param_3);
    param_1 = param_1 + 0x24;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0069d5ba @ 0x0069d5ba ====

void Catch_0069d5ba(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x24) {
    FUN_005c0d50(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0069d5e0 @ 0x0069d5e0 ====

void FUN_0069d5e0(undefined4 param_1,undefined4 param_2)

{
  FUN_0069d3a0(param_1,param_2);
  return;
}


// ==== FUN_0069d600 @ 0x0069d600 ====

void FUN_0069d600(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0069d480(param_1,param_2,param_3);
  return;
}


// ==== FUN_0069d620 @ 0x0069d620 ====

int FUN_0069d620(int param_1,int param_2,undefined4 param_3)

{
  FUN_0069d550(param_1,param_2,param_3);
  return param_1 + param_2 * 0x24;
}


// ==== FUN_0069d650 @ 0x0069d650 ====

void FUN_0069d650(int param_1,uint param_2,undefined1 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint extraout_ECX;
  undefined1 local_64 [2];
  undefined1 auStack_62 [2];
  undefined4 local_60;
  void *local_58;
  undefined4 local_48;
  uint local_44;
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
  puStack_c = &LAB_0098c760;
  local_10 = ExceptionList;
  local_14 = local_64 + -0xc;
  local_64[0] = *param_3;
  local_60 = *(undefined4 *)(param_3 + 4);
  local_44 = 0xf;
  local_48 = 0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3 + 8,0,0xffffffff);
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
      local_18 = (void *)FUN_0069d600(*(undefined4 *)(in_ECX + 4),param_1,local_1c);
      local_18 = (void *)FUN_0069d620(local_18,param_2,local_64);
      FUN_0069d600(param_1,*(undefined4 *)(in_ECX + 8),local_18);
      local_8 = 0xffffffff;
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
      }
      if (iVar2 != 0) {
        FUN_0069d3a0(iVar2,*(undefined4 *)(in_ECX + 8));
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
        FUN_0069d480(param_1,local_2c,local_28 + param_1);
        local_8 = 2;
        FUN_0069d620(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x24,local_64
                    );
        local_8 = 0xffffffff;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_28;
        FUN_0069d360(param_1,*(int *)(in_ECX + 8) - local_28,local_64);
      }
      else {
        local_30 = local_2c + param_2 * -0x24;
        uVar3 = FUN_0069d480(local_30,local_2c,local_2c);
        *(undefined4 *)(in_ECX + 8) = uVar3;
        FUN_0069d3f0(param_1,local_30,local_2c,local_40);
        FUN_0069d360(param_1,param_2 * 0x24 + param_1,local_64);
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


// ==== Catch@0069d823 @ 0x0069d823 ====

void Catch_0069d823(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_0069d5e0(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@0069d8d7 @ 0x0069d8d7 ====

void Catch_0069d8d7(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x24;
  FUN_0069d5e0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x1c) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0069d970 @ 0x0069d970 ====

void FUN_0069d970(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x24 != 0) {
      iVar1 = (param_2 - iVar1) / 0x24;
      goto LAB_0069d9b5;
    }
  }
  iVar1 = 0;
LAB_0069d9b5:
  FUN_0069d650(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x24;
  return;
}


// ==== FUN_0069d9e0 @ 0x0069d9e0 ====

undefined4 FUN_0069d9e0(void)

{
  return 0x36;
}


// ==== FUN_0069d9f0 @ 0x0069d9f0 ====

void FUN_0069d9f0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x24) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x24))) {
    FUN_0069d970(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0069d550(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x24;
  return;
}


// ==== FUN_0069da80 @ 0x0069da80 ====

void FUN_0069da80(byte param_1)

{
  void *in_ECX;
  
  FUN_0069cba0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0069daa0 @ 0x0069daa0 ====

void FUN_0069daa0(void)

{
  return;
}


// ==== FUN_0069dab0 @ 0x0069dab0 ====

undefined1 FUN_0069dab0(void)

{
  return 0;
}


// ==== FUN_0069dac0 @ 0x0069dac0 ====

void FUN_0069dac0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009de1f0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0069dae0 @ 0x0069dae0 ====

undefined4 FUN_0069dae0(void)

{
  (**(code **)(*DAT_00b5aca8 + 0x48))();
  return 1;
}


// ==== FUN_0069db10 @ 0x0069db10 ====

void FUN_0069db10(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_14;
  
  uStack_14 = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    (**(code **)(*DAT_00b5a7c0 + 8))(param_1);
    FUN_00587d40(&uStack_14);
    (**(code **)(*piVar1 + 0x24))(1);
  }
  return;
}


// ==== FUN_0069db90 @ 0x0069db90 ====

void FUN_0069db90(void)

{
  int in_ECX;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_guildbg_009de110,7);
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_pan_guildMarkBg_009de118,0xf);
  FUN_0069db10(local_38,local_1c,*(undefined4 *)(in_ECX + 0xc));
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
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_guildicon_009de128,9);
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_pan_guildMark_009de134,0xd);
  FUN_0069db10(local_38,local_1c,*(undefined4 *)(in_ECX + 8));
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0069dcb0 @ 0x0069dcb0 ====

void FUN_0069dcb0(undefined4 param_1,char param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 uVar6;
  int in_ECX;
  char *pcVar7;
  uint unaff_retaddr;
  void *local_58;
  undefined1 local_54;
  uint local_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  pcVar7 = s_pan_bgCursor_009de0f0;
  if (param_2 != '\x01') {
    pcVar7 = s_pan_iconCursor_009de100;
  }
  local_40 = 0xf;
  local_44 = 0;
  local_54 = 0;
  pcVar4 = pcVar7;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar7,(int)pcVar4 - (int)(pcVar7 + 1));
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_58);
  if (piVar5 != (int *)0x0) {
    local_40._0_3_ = CONCAT12(1,(undefined2)local_40);
    uStack_3c = 0;
    iStack_38 = 0;
    iStack_34 = 0;
    iStack_30 = 0;
    iStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    iVar2 = (unaff_retaddr % 0x14) * 0x18;
    iVar3 = (unaff_retaddr / 0x14) * 0x18;
    uVar6 = (**(code **)(*piVar5 + 0x10))();
    FUN_004fed70(uVar6);
    iStack_30 = iVar2 + 0x18;
    iStack_2c = iVar3 + 0x18;
    iStack_38 = iVar2;
    iStack_34 = iVar3;
    (**(code **)(*piVar5 + 0xc))(&local_40);
    (**(code **)(*piVar5 + 0x24))(1);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
  }
  if (local_44 < 0x10) {
    return;
  }
  _free(local_58);
  return;
}


// ==== FUN_0069ddd0 @ 0x0069ddd0 ====

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_0069ddd0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int in_ECX;
  char in_stack_00000010;
  undefined4 uStack_100;
  void **ppvStack_fc;
  int *piStack_f8;
  undefined1 *puStack_f4;
  int *piStack_f0;
  int *piVar5;
  void *local_c4;
  void *local_b0;
  void *local_ac [4];
  uint uStack_9c;
  uint uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined1 uStack_88;
  undefined1 uStack_87;
  undefined4 uStack_84;
  void *pvStack_60;
  undefined1 auStack_5c [12];
  undefined4 uStack_50;
  uint uStack_4c;
  undefined1 uStack_48;
  void *pvStack_44;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 auStack_24 [8];
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740();
  local_b0 = (void *)0x0;
  local_ac[0] = (void *)0xf;
  if (in_stack_00000010 == '\x01') {
    FUN_00401740();
    iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if ((void *)0xf < local_b0) {
      _free(local_c4);
      return;
    }
  }
  else {
    FUN_00401740();
    iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if ((void *)0xf < local_b0) {
      _free(local_c4);
      return;
    }
  }
  local_b0 = (void *)0xf;
  local_c4 = (void *)((uint)local_c4 & 0xffffff00);
  FUN_00401740();
  if (iVar2 != 0) {
    piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
    uStack_84._0_3_ = CONCAT12(1,(undefined2)uStack_84);
    uStack_4c = 0xf;
    uStack_50 = 0;
    pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
    piVar5 = (int *)0x0;
    piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
    uStack_34 = 0xf;
    uStack_38 = 0;
    uStack_48 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    FUN_00402220(&uStack_100,auStack_24,&DAT_009de170);
    FUN_00404230(&local_b0);
    piStack_f0 = (int *)0x69df70;
    FUN_00401660();
    if (0xf < uStack_98) {
      _free(local_ac[0]);
      return;
    }
    piStack_f0 = (int *)0x69df9b;
    FUN_00401660();
    uStack_84 = 100;
    uStack_88 = 1;
    uStack_87 = 1;
    uStack_94 = 0;
    uStack_90 = 0;
    uStack_8c = 0;
    local_ac[0] = (void *)((uint)local_ac[0] & 0xffffff00);
    uStack_9c = 0;
    uStack_98 = 0xf;
    FUN_00401740();
    uStack_94 = (**(code **)(*DAT_00b5a7c0 + 8))();
    if (0xf < uStack_9c) {
      _free(local_b0);
      return;
    }
    uStack_90 = 1;
    (**(code **)(*piVar3 + 8))();
    piStack_f0 = (int *)0x69e054;
    cVar1 = (**(code **)(*piVar3 + 0x74))();
    if (cVar1 != '\0') {
      puStack_f4 = (undefined1 *)0x69e062;
      piStack_f0 = piVar3;
      cVar1 = (**(code **)((int)local_c4 + 0x78))();
      if (cVar1 == '\0') {
        puStack_f4 = (undefined1 *)0x0;
        piStack_f8 = (int *)0x69e06e;
        (**(code **)(*piVar3 + 0x74))();
      }
      else {
        puStack_f4 = (undefined1 *)0x69e079;
        iVar2 = (**(code **)(*piVar5 + 0x38))();
        piVar3[1] = iVar2;
      }
    }
    puStack_f4 = (undefined1 *)0x69e085;
    piStack_f0 = piVar3;
    (**(code **)(*piVar4 + 0x38))();
    puStack_f4 = auStack_5c;
    piStack_f8 = (int *)0x69e095;
    (**(code **)(*piVar4 + 0x1c))();
    ppvStack_fc = (void **)0x69e09d;
    piStack_f8 = piVar4;
    (**(code **)(*piVar3 + 0x2c))();
    ppvStack_fc = local_ac;
    uStack_100 = 0x69e0a9;
    FUN_00587d40();
    if (0xf < uStack_30) {
      _free(pvStack_44);
      return;
    }
    uStack_30 = 0xf;
    uStack_34 = 0;
    pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
    if (0xf < uStack_4c) {
      _free(pvStack_60);
      return;
    }
  }
  if (local_8 < 0x10) {
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_0069e120 @ 0x0069e120 ====

void FUN_0069e120(char param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  uint uVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined1 local_54 [4];
  void *local_50;
  undefined4 local_40;
  uint local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  if (param_1 == '\0') {
    _param_1 = *(uint *)(in_ECX + 0x10);
    local_20 = 0xf;
    local_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_00401740(s_guildicon_s_009de088,0xb);
    uVar3 = 0;
    do {
      if (_param_1 < 0x274) {
        puVar4 = local_38;
        uVar5 = _param_1;
        FUN_00401740(s_pan_icon__d_009de0a0,0xb);
        uVar1 = FUN_00404230(local_1c);
        FUN_0069db10(uVar1,puVar4,uVar5);
        if (0xf < uStack_4) {
          _free(pvStack_18);
          return;
        }
        uStack_4 = 0xf;
        uStack_8 = 0;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      }
      else {
        FUN_00401740(s_pan_icon__d_009de094,0xb);
        uVar1 = FUN_00404230(local_54);
        piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar1);
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 0x24))(0);
        }
        if (0xf < local_3c) {
          _free(local_50);
          return;
        }
        local_3c = 0xf;
        local_40 = 0;
        local_50 = (void *)((uint)local_50 & 0xffffff00);
      }
      _param_1 = _param_1 + 1;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x3c);
    uVar3 = *(uint *)(in_ECX + 8);
    uVar5 = *(uint *)(in_ECX + 0x10);
    if ((uVar3 < uVar5) || (uVar5 + 0x3c < uVar3)) {
      local_3c = 0xf;
      local_40 = 0;
      local_50 = (void *)((uint)local_50 & 0xffffff00);
      FUN_00401740(s_pan_iconCursor_009de0ac,0xe);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_54);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x24))(0);
      }
      if (0xf < local_3c) {
        _free(local_50);
        return;
      }
    }
    else {
      FUN_0069dcb0(uVar3 - uVar5,0);
    }
    if (0xf < local_20) {
      _free(local_34);
      return;
    }
  }
  else {
    _param_1 = *(uint *)(in_ECX + 0x14);
    local_3c = 0xf;
    local_40 = 0;
    local_50 = (void *)((uint)local_50 & 0xffffff00);
    FUN_00401740(s_guildbg_s_009de0bc,9);
    uVar3 = 0;
    do {
      if (_param_1 < 0xde) {
        puVar4 = local_54;
        uVar5 = _param_1;
        FUN_00401740(s_pan_bg__d_009de0d4,9);
        uVar1 = FUN_00404230(local_38);
        FUN_0069db10(uVar1,puVar4,uVar5);
        if (0xf < local_20) {
          _free(local_34);
          return;
        }
        local_20 = 0xf;
        local_24 = 0;
        local_34 = (void *)((uint)local_34 & 0xffffff00);
      }
      else {
        FUN_00401740(s_pan_bg__d_009de0c8,9);
        uVar1 = FUN_00404230(local_1c);
        piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar1);
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 0x24))(0);
        }
        if (0xf < uStack_4) {
          _free(pvStack_18);
          return;
        }
        uStack_4 = 0xf;
        uStack_8 = 0;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      }
      _param_1 = _param_1 + 1;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x3c);
    uVar3 = *(uint *)(in_ECX + 0xc);
    uVar5 = *(uint *)(in_ECX + 0x14);
    if ((uVar3 < uVar5) || (uVar5 + 0x3c < uVar3)) {
      local_20 = 0xf;
      local_24 = 0;
      local_34 = (void *)((uint)local_34 & 0xffffff00);
      FUN_00401740(s_pan_bgCursor_009de0e0,0xc);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_38);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x24))(0);
      }
      if (0xf < local_20) {
        _free(local_34);
        return;
      }
    }
    else {
      FUN_0069dcb0(uVar3 - uVar5,1);
    }
    if (0xf < local_3c) {
      _free(local_50);
      return;
    }
  }
  return;
}


// ==== FUN_0069e440 @ 0x0069e440 ====

void FUN_0069e440(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  uint uVar3;
  undefined1 local_1ec [4];
  void *local_1e8;
  void *pvStack_1dc;
  undefined4 local_1d8;
  uint local_1d4;
  uint uStack_1c8;
  void *pvStack_1b8;
  undefined4 uStack_1a8;
  uint uStack_1a4;
  ushort uStack_1a0;
  ushort uStack_19e;
  
  local_1d4 = 0xf;
  local_1d8 = 0;
  local_1e8 = (void *)((uint)local_1e8 & 0xffffff00);
  FUN_00401740(s_UI_Game2_Guild_ui_markselectwnd__009de064,0x23);
  iVar1 = FUN_00410500(local_1ec);
  if (0xf < local_1d4) {
    _free(local_1e8);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  uVar3 = 0;
  do {
    FUN_0069ddd0(uVar3,(uVar3 % 0x14) * 0x18,(uVar3 / 0x14) * 0x18,1);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x3c);
  uVar3 = 0;
  do {
    FUN_0069ddd0(uVar3,(uVar3 % 0x14) * 0x18,(uVar3 / 0x14) * 0x18,0);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x3c);
  (**(code **)(*DAT_00b5aca8 + 0x18))(&pvStack_1dc);
  if ((uStack_1a0 == 0) || (uStack_19e == 0)) {
    *(undefined4 *)(in_ECX + 8) = 1;
    *(undefined4 *)(in_ECX + 0xc) = 1;
  }
  else {
    *(uint *)(in_ECX + 8) = (uint)uStack_19e;
    *(uint *)(in_ECX + 0xc) = (uint)uStack_1a0;
  }
  if (*(int *)(in_ECX + 8) == 0) {
    *(undefined4 *)(in_ECX + 0x10) = 1;
  }
  else {
    *(uint *)(in_ECX + 0x10) = ((*(int *)(in_ECX + 8) - 1U) / 0x3c) * 0x3c + 1;
  }
  if (*(int *)(in_ECX + 0xc) == 0) {
    *(undefined4 *)(in_ECX + 0x14) = 1;
  }
  else {
    *(uint *)(in_ECX + 0x14) = ((*(int *)(in_ECX + 0xc) - 1U) / 0x3c) * 0x3c + 1;
  }
  if (0xf < uStack_1a4) {
    _free(pvStack_1b8);
    return;
  }
  uStack_1a4 = 0xf;
  uStack_1a8 = 0;
  pvStack_1b8 = (void *)((uint)pvStack_1b8 & 0xffffff00);
  if (uStack_1c8 < 0x10) {
    FUN_0069e120(1);
    FUN_0069e120(0);
    FUN_0069db90();
    return;
  }
  _free(pvStack_1dc);
  return;
}


// ==== FUN_0069e600 @ 0x0069e600 ====

void FUN_0069e600(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009de1f0;
  in_ECX[2] = 1;
  in_ECX[3] = 1;
  in_ECX[4] = 1;
  in_ECX[5] = 1;
  FUN_0069e440();
  return;
}


// ==== FUN_0069e630 @ 0x0069e630 ====

undefined4 FUN_0069e630(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  undefined4 uVar4;
  undefined *puVar5;
  undefined1 local_10 [4];
  int local_c;
  int local_8;
  int local_4;
  
  if (param_3 != 1) {
    return 0;
  }
  if (param_1 == 1) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009de18c,8);
    if (iVar2 == 0) {
      (**(code **)(*DAT_00b5aca8 + 0x48))();
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_regist_009de198);
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5aca8 + 0x48))();
      (**(code **)(*DAT_00b5aca8 + 0x5c))(*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 8))
      ;
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_iconLeft_009de1a4);
    if (cVar1 == '\0') {
      cVar1 = FUN_004036a0(param_2,s_btn_iconRight_009de1b4);
      if (cVar1 == '\0') {
        cVar1 = FUN_004036a0(param_2,s_btn_bgLeft_009de1c4);
        if (cVar1 == '\0') {
          cVar1 = FUN_004036a0(param_2,s_btn_bgRight_009de1d0);
          if (cVar1 == '\0') {
            return 0;
          }
          uVar3 = *(int *)(in_ECX + 0x14) + 0x3c;
          if (0xdd < uVar3) {
            return 1;
          }
        }
        else {
          if (*(uint *)(in_ECX + 0x14) < 0x3d) {
            return 1;
          }
          uVar3 = *(uint *)(in_ECX + 0x14) - 0x3c;
        }
        *(uint *)(in_ECX + 0x14) = uVar3;
        uVar4 = 1;
      }
      else {
        uVar3 = *(int *)(in_ECX + 0x10) + 0x3c;
        if (0x273 < uVar3) {
          return 1;
        }
        *(uint *)(in_ECX + 0x10) = uVar3;
        uVar4 = 0;
      }
    }
    else {
      if (*(uint *)(in_ECX + 0x10) < 0x3d) {
        return 1;
      }
      *(uint *)(in_ECX + 0x10) = *(uint *)(in_ECX + 0x10) - 0x3c;
      uVar4 = 0;
    }
    FUN_0069e120(uVar4);
    FUN_0069db90();
    return 1;
  }
  if (param_1 != 0) {
    return 0;
  }
  local_c = param_1;
  local_8 = param_1;
  local_4 = param_1;
  FUN_00404fb0(param_2,0x5f,local_10);
  if ((local_c == 0) || ((uint)((local_8 - local_c) / 0x1c) < 3)) goto LAB_0069e850;
  puVar5 = &DAT_009de1dc;
  uVar4 = FUN_00405d30(1);
  cVar1 = FUN_004036a0(uVar4,puVar5);
  if (cVar1 == '\0') {
    puVar5 = &DAT_009de1e4;
    uVar4 = FUN_00405d30(1);
    cVar1 = FUN_004036a0(uVar4,puVar5);
    if (cVar1 != '\0') {
      uVar4 = FUN_00405d30(2);
      iVar2 = thunk_FUN_00796fb0(uVar4);
      *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0x14) + iVar2;
      uVar4 = 1;
      goto LAB_0069e841;
    }
  }
  else {
    uVar4 = FUN_00405d30(2);
    iVar2 = thunk_FUN_00796fb0(uVar4);
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 0x10) + iVar2;
    uVar4 = 0;
LAB_0069e841:
    FUN_0069dcb0(iVar2,uVar4);
  }
  FUN_0069db90();
LAB_0069e850:
  FUN_00406250();
  return 1;
}


// ==== FUN_0069e870 @ 0x0069e870 ====

undefined4 FUN_0069e870(void)

{
  return 0x34;
}


// ==== FUN_0069e880 @ 0x0069e880 ====

void FUN_0069e880(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009de1f0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0069e8c0 @ 0x0069e8c0 ====

undefined4 FUN_0069e8c0(void)

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


// ==== FUN_0069e8f0 @ 0x0069e8f0 ====

void FUN_0069e8f0(void)

{
  return;
}


// ==== FUN_0069e900 @ 0x0069e900 ====

undefined1 FUN_0069e900(void)

{
  return 0;
}


// ==== FUN_0069e910 @ 0x0069e910 ====

bool FUN_0069e910(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  return param_1 == iVar1;
}


// ==== FUN_0069e920 @ 0x0069e920 ====

void FUN_0069e920(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009de2d0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0069e940 @ 0x0069e940 ====

undefined4 FUN_0069e940(int param_1,int param_2,int param_3,undefined2 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  int in_ECX;
  void *unaff_EBP;
  undefined1 auStack_24 [2];
  undefined1 auStack_22 [6];
  uint uStack_1c;
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_ok_009de29c,6);
      if (iVar2 != 0) {
        cVar1 = FUN_004036a0(param_2,s_btn_exit_009de2a4);
        if ((cVar1 == '\0') && (cVar1 = FUN_004036a0(param_2,s_btn_cancel_009de2b0), cVar1 == '\0'))
        {
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
      puVar3 = operator_new(4);
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        *puVar3 = &PTR_FUN_009d7f70;
      }
      FUN_00797a20(puVar3);
      iVar2 = *DAT_00b5aca8;
      uVar4 = (**(code **)(*DAT_00b5aca8 + 0x88))();
      (**(code **)(iVar2 + 0x20))(auStack_24,uVar4);
      (**(code **)(*DAT_00b5aca8 + 0xf8))
                (CONCAT31((int3)((uint)(auStack_24 + -8) >> 8),*(undefined1 *)(in_ECX + 8)),
                 auStack_24 + -8);
      if (uStack_1c < 0x10) {
        return 1;
      }
      _free(unaff_EBP);
      return extraout_EAX;
    }
  }
  else if (((param_1 == 0x15) && (param_3 == 1)) &&
          (iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_combo_grade_009de2bc,0xb),
          iVar2 == 0)) {
    *(undefined2 *)(in_ECX + 8) = param_4;
    return 1;
  }
  return 0;
}


// ==== FUN_0069eaa0 @ 0x0069eaa0 ====

/* WARNING: Removing unreachable block (ram,0x0069eb01) */

void FUN_0069eaa0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  undefined1 auStack_3e [14];
  undefined4 uStack_30;
  void *pvStack_2c;
  undefined1 auStack_24 [12];
  uint uStack_18;
  
  iVar3 = *DAT_00b5aca8;
  uVar1 = (**(code **)(*DAT_00b5aca8 + 0x88))();
  (**(code **)(iVar3 + 0x20))(auStack_24,uVar1);
  uStack_30 = 0xf;
  FUN_00401740(s_lbl_memberName_009de280,0xe);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_3e + -10);
  if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x30))(), iVar3 != 0)) {
    FUN_0055a260(&uStack_30);
  }
  if (uStack_18 < 0x10) {
    return;
  }
  _free(pvStack_2c);
  return;
}


// ==== FUN_0069eb60 @ 0x0069eb60 ====

void FUN_0069eb60(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int in_ECX;
  void *_Memory;
  void *pvVar6;
  undefined1 *puVar7;
  undefined1 auStack_25a [14];
  uint uStack_24c;
  void *local_238;
  undefined1 local_234;
  void *pvStack_228;
  uint local_224 [3];
  undefined4 uStack_218;
  uint uStack_214;
  byte bStack_20f;
  char acStack_1fa [30];
  void *pvStack_1dc;
  undefined1 auStack_1d4 [12];
  uint uStack_1c8;
  void *pvStack_1b8;
  undefined4 uStack_1a8;
  uint uStack_1a4;
  undefined1 auStack_169 [361];
  
  local_224[1] = 0xf;
  local_224[0] = 0;
  local_234 = 0;
  FUN_00401740(s_combo_grade_009de290,0xb);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_238);
  if (0xf < local_224[0]) {
    _free(local_238);
    return;
  }
  local_224[0] = 0xf;
  pvStack_228 = (void *)0x0;
  local_238 = (void *)((uint)local_238 & 0xffffff00);
  if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x30))(), iVar3 != 0)) {
    (**(code **)(*DAT_00b5aca8 + 0x18))(auStack_1d4);
    acStack_1fa[0] = '\0';
    puVar7 = auStack_169;
    pvVar6 = (void *)0x0;
    do {
      _Memory = pvVar6;
      FUN_0069d320(puVar7);
      pcVar4 = acStack_1fa;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      FUN_00401740(acStack_1fa,(int)pcVar4 - (int)(acStack_1fa + 1));
      FUN_00577d70(auStack_25a + -10,0);
      pvVar6 = (void *)((int)_Memory + 1);
      puVar7 = puVar7 + 0x27;
    } while (pvVar6 < (void *)0x9);
    FUN_00578700();
    iVar3 = *DAT_00b5aca8;
    uVar5 = (**(code **)(*DAT_00b5aca8 + 0x88))();
    (**(code **)(iVar3 + 0x20))(local_224,uVar5);
    if (bStack_20f != 0) {
      FUN_00577df0(bStack_20f - 1);
    }
    if (0xf < uStack_214) {
      _free(pvStack_228);
      return;
    }
    uStack_214 = 0xf;
    uStack_218 = 0;
    pvStack_228 = (void *)((uint)pvStack_228 & 0xffffff00);
    if (0xf < uStack_24c) {
      _free(_Memory);
      return;
    }
    if (0xf < uStack_1a4) {
      _free(pvStack_1b8);
      return;
    }
    uStack_1a4 = 0xf;
    uStack_1a8 = 0;
    pvStack_1b8 = (void *)((uint)pvStack_1b8 & 0xffffff00);
    if (0xf < uStack_1c8) {
      _free(pvStack_1dc);
      return;
    }
  }
  return;
}


// ==== FUN_0069ed30 @ 0x0069ed30 ====

void FUN_0069ed30(void)

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
  FUN_00401740(s_UI_Game2_Guild_ui_chgGradewnd_tx_009de25c,0x21);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_0069eaa0();
    FUN_0069eb60();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0069edb0 @ 0x0069edb0 ====

void FUN_0069edb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009de2d0;
  *(undefined2 *)(in_ECX + 2) = 0;
  FUN_0069ed30();
  return;
}


// ==== FUN_0069edd0 @ 0x0069edd0 ====

undefined4 FUN_0069edd0(void)

{
  return 0x31;
}


// ==== FUN_0069ede0 @ 0x0069ede0 ====

void FUN_0069ede0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009de2d0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0069ee20 @ 0x0069ee20 ====

undefined4 FUN_0069ee20(void)

{
  return 0x110;
}


// ==== FUN_0069ee30 @ 0x0069ee30 ====

undefined4 FUN_0069ee30(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar1 = &PTR_FUN_009de3b0;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_0069ee60 @ 0x0069ee60 ====

void FUN_0069ee60(void)

{
  return;
}


// ==== FUN_0069ee70 @ 0x0069ee70 ====

undefined1 FUN_0069ee70(void)

{
  return 0;
}


// ==== FUN_0069ee80 @ 0x0069ee80 ====

void FUN_0069ee80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009de3c4;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0069eea0 @ 0x0069eea0 ====

undefined4 FUN_0069eea0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009de370,8);
    if (iVar2 == 0) {
      (**(code **)(*in_ECX + 0x10))();
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_close_009de37c);
    if (cVar1 != '\0') {
      (**(code **)(*in_ECX + 0x10))();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0069ef10 @ 0x0069ef10 ====

void FUN_0069ef10(void *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 uStack00000000;
  uint in_stack_00000018;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  void *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  void *local_1c;
  void *local_18;
  undefined4 uStack_c;
  uint local_8;
  uint local_4;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_009de388,1);
  FUN_00406720(&local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_009de38c,1);
  FUN_00406720(&local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s___GT___009de390,6);
  FUN_00406720(&local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s___LT___009de398,6);
  FUN_00406720(&local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  uVar1 = FUN_00404a40(&local_1c,&param_1,&local_2c,&local_3c);
  FUN_00401660(uVar1,0,0xffffffff);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_textbox_009de3a0,7);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x30))();
    if (iVar3 != 0) {
      FUN_005569f0(&uStack00000000,0);
    }
  }
  puVar4 = operator_new(8);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    *puVar4 = &PTR_FUN_009b1798;
  }
  uVar1 = (**(code **)(*piVar2 + 4))();
  puVar4[1] = uVar1;
  FUN_00797a20(puVar4);
  if (local_3c != (void *)0x0) {
    FUN_00405de0(local_3c,local_38,(int)register0x00000010 + -0x40,_uStack00000000);
    _free(local_3c);
    return;
  }
  local_3c = (void *)0x0;
  local_38 = 0;
  local_34 = 0;
  if (local_2c != (void *)0x0) {
    FUN_00405de0(local_2c,local_28,&local_30,_uStack00000000);
    _free(local_2c);
    return;
  }
  local_2c = (void *)0x0;
  local_28 = 0;
  local_24 = 0;
  if (in_stack_00000018 < 0x10) {
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_0069f190 @ 0x0069f190 ====

void FUN_0069f190(void)

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
  FUN_00401740(s_UI_Maptool_ui_noticepreviewwnd_t_009de33c,0x22);
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
  FUN_00401740(&DAT_009de360,0xd);
  FUN_0069ef10();
  if (piVar1 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar1 + 4))();
    *(undefined4 *)(iVar3 + 0x28) = 0;
    (**(code **)(*DAT_00b5a7cc + 0x2c))(piVar1);
  }
  return;
}


// ==== FUN_0069f250 @ 0x0069f250 ====

void FUN_0069f250(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009de3c4;
  FUN_0069f190();
  return;
}


// ==== FUN_0069f270 @ 0x0069f270 ====

undefined4 FUN_0069f270(void)

{
  return 0x82;
}


// ==== FUN_0069f280 @ 0x0069f280 ====

void FUN_0069f280(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009de3c4;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0069f2c0 @ 0x0069f2c0 ====

undefined4 FUN_0069f2c0(void)

{
  return 0x109;
}


// ==== FUN_0069f2d0 @ 0x0069f2d0 ====

undefined4 FUN_0069f2d0(void)

{
  return 0x108;
}


// ==== FUN_0069f2e0 @ 0x0069f2e0 ====

undefined4 FUN_0069f2e0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009de3b0;
  }
  FUN_00797a20(puVar1);
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar1 = &PTR_FUN_009de4a4;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_0069f330 @ 0x0069f330 ====

void FUN_0069f330(void)

{
  return;
}


// ==== FUN_0069f340 @ 0x0069f340 ====

void FUN_0069f340(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009de4b8;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0069f370 @ 0x0069f370 ====

undefined4 FUN_0069f370(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009de454,8);
  if (iVar2 == 0) {
    (**(code **)(*in_ECX + 0x10))();
    return 1;
  }
  cVar1 = FUN_004036a0(param_2,s_btn_open_009de460);
  if (((cVar1 == '\0') && (cVar1 = FUN_004036a0(param_2,s_btn_deleteAll_009de46c), cVar1 == '\0'))
     && (cVar1 = FUN_004036a0(param_2,s_btn_regist_009de47c), cVar1 == '\0')) {
    cVar1 = FUN_004036a0(param_2,s_btn_preview_009de488);
    if (cVar1 == '\0') {
      return 0;
    }
    FUN_0069f340();
  }
  return 1;
}


// ==== FUN_0069f420 @ 0x0069f420 ====

void FUN_0069f420(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009de4cc;
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


// ==== FUN_0069f470 @ 0x0069f470 ====

uint FUN_0069f470(void)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint extraout_EAX;
  uint extraout_EAX_00;
  int in_ECX;
  int *unaff_retaddr;
  void *pvStack_58;
  undefined1 uStack_54;
  undefined4 uStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  void *pvStack_3c;
  undefined1 uStack_38;
  uint uStack_28;
  undefined4 auStack_24 [9];
  
  iVar1 = (**(code **)(*DAT_00b5a74c + 0xc))(0x82);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = (**(code **)(*unaff_retaddr + 4))();
    if (uVar2 == 0x20002) {
      auStack_24[0] = 0xf;
      uStack_28 = 0;
      uStack_38 = 0;
      uStack_40 = 0xf;
      uStack_44 = 0;
      uStack_54 = 0;
      FUN_00401740(s_textbox_009de44c,7);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_58);
      if (0xf < uStack_44) {
        _free(pvStack_58);
        return extraout_EAX;
      }
      uStack_44 = 0xf;
      uStack_48 = 0;
      pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
      if (piVar3 != (int *)0x0) {
        iVar1 = (**(code **)(*piVar3 + 0x30))();
        if (iVar1 != 0) {
          iVar1 = FUN_00668860(auStack_24);
          if (*(uint *)(iVar1 + 0x18) < 0x10) {
            iVar1 = iVar1 + 4;
          }
          else {
            iVar1 = *(int *)(iVar1 + 4);
          }
          FUN_00403810(iVar1);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
      }
      uVar2 = (**(code **)(*piVar3 + 0x5c))();
      if (0xf < uStack_28) {
        _free(pvStack_3c);
        return extraout_EAX_00;
      }
    }
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_0069f5b0 @ 0x0069f5b0 ====

void FUN_0069f5b0(void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
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
  FUN_00401740(s_textbox_009de494,7);
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
      FUN_005569f0(&uStack00000000,0);
    }
  }
  puVar3 = operator_new(8);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = &PTR_FUN_009b1798;
  }
  uVar4 = (**(code **)(*piVar1 + 4))();
  puVar3[1] = uVar4;
  FUN_00797a20(puVar3);
  if (in_stack_00000018 < 0x10) {
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_0069f670 @ 0x0069f670 ====

void FUN_0069f670(void)

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
  FUN_00401740(s_UI_Maptool_ui_noticewnd_txt_009de430,0x1b);
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
  if (piVar1 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar1 + 4))();
    *(undefined4 *)(iVar3 + 0x28) = 0;
    (**(code **)(*DAT_00b5a7cc + 0x2c))(piVar1);
  }
  return;
}


// ==== FUN_0069f710 @ 0x0069f710 ====

void FUN_0069f710(void)

{
  undefined4 *in_ECX;
  int *piVar1;
  int *piVar2;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009de4cc;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  piVar1 = in_ECX + 3;
  if ((uint)in_ECX[8] < 0x10) {
    piVar2 = piVar1;
  }
  else {
    piVar2 = (int *)*piVar1;
  }
  if (0xf < (uint)in_ECX[8]) {
    piVar1 = (int *)*piVar1;
  }
  FUN_004bdb30(local_4,piVar1,in_ECX[7] + (int)piVar2);
  FUN_0069f670();
  return;
}


// ==== FUN_0069f770 @ 0x0069f770 ====

undefined4 FUN_0069f770(void)

{
  return 0x81;
}


// ==== FUN_0069f780 @ 0x0069f780 ====

void FUN_0069f780(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009de4cc;
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


// ==== FUN_0069f7e0 @ 0x0069f7e0 ====

undefined4 FUN_0069f7e0(void)

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


// ==== FUN_0069f810 @ 0x0069f810 ====

void FUN_0069f810(void)

{
  return;
}


// ==== FUN_0069f820 @ 0x0069f820 ====

undefined1 FUN_0069f820(void)

{
  return 0;
}


// ==== FUN_0069f830 @ 0x0069f830 ====

void FUN_0069f830(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009de598;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0069f850 @ 0x0069f850 ====

void FUN_0069f850(void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
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
  FUN_00401740(s_textbox_009de558,7);
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
      FUN_005569f0(&uStack00000000,0);
    }
  }
  puVar3 = operator_new(8);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = &PTR_FUN_009b1798;
  }
  uVar4 = (**(code **)(*piVar1 + 4))();
  puVar3[1] = uVar4;
  FUN_00797a20(puVar3);
  if (in_stack_00000018 < 0x10) {
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_0069f910 @ 0x0069f910 ====

undefined4 FUN_0069f910(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined1 local_1c [28];
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009de560,8);
    if (iVar2 == 0) {
      puVar3 = operator_new(4);
      if (puVar3 == (undefined4 *)0x0) {
        FUN_00797a20(0);
        return 1;
      }
      *puVar3 = &PTR_FUN_009d7f70;
      FUN_00797a20(puVar3);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_deleteAll_009de56c);
    if (cVar1 == '\0') {
      cVar1 = FUN_004036a0(param_2,s_btn_regist_009de57c);
      if (cVar1 != '\0') {
        FUN_00401830(s_textbox_009de588);
        (**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_1c);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    else {
      FUN_00401830(&DAT_009de57a);
      FUN_0069f850();
    }
  }
  return 0;
}


// ==== FUN_0069fa20 @ 0x0069fa20 ====

void FUN_0069fa20(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1ec [4];
  void *local_1e8;
  void *pvStack_1dc;
  undefined4 local_1d8;
  uint local_1d4;
  uint uStack_1c8;
  undefined1 auStack_1bc [4];
  void *pvStack_1b8;
  undefined4 uStack_1a8;
  uint uStack_1a4;
  
  local_1d4 = 0xf;
  local_1d8 = 0;
  local_1e8 = (void *)((uint)local_1e8 & 0xffffff00);
  FUN_00401740(s_UI_Game2_Guild_ui_noticewnd_txt_009de538,0x1f);
  iVar1 = FUN_00410500(local_1ec);
  if (0xf < local_1d4) {
    _free(local_1e8);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  (**(code **)(*DAT_00b5aca8 + 0x18))(&pvStack_1dc);
  FUN_00401660(auStack_1bc,0,0xffffffff);
  FUN_0069f850();
  if (0xf < uStack_1a4) {
    _free(pvStack_1b8);
    return;
  }
  uStack_1a4 = 0xf;
  uStack_1a8 = 0;
  pvStack_1b8 = (void *)((uint)pvStack_1b8 & 0xffffff00);
  if (uStack_1c8 < 0x10) {
    return;
  }
  _free(pvStack_1dc);
  return;
}


// ==== FUN_0069fb00 @ 0x0069fb00 ====

void FUN_0069fb00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009de598;
  FUN_0069fa20();
  return;
}


// ==== FUN_0069fb20 @ 0x0069fb20 ====

undefined4 FUN_0069fb20(void)

{
  return 0x2f;
}


// ==== FUN_0069fb30 @ 0x0069fb30 ====

void FUN_0069fb30(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009de598;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0069fb70 @ 0x0069fb70 ====

void FUN_0069fb70(void)

{
  return;
}


// ==== FUN_0069fb80 @ 0x0069fb80 ====

bool FUN_0069fb80(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  return param_1 == iVar1;
}


// ==== FUN_0069fb90 @ 0x0069fb90 ====

void FUN_0069fb90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009de65c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0069fbb0 @ 0x0069fbb0 ====

undefined4 FUN_0069fbb0(void)

{
  (**(code **)(*DAT_00b5aca8 + 0x44))();
  return 1;
}


// ==== FUN_0069fbc0 @ 0x0069fbc0 ====

void FUN_0069fbc0(void)

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
  FUN_00401740(s_edit_text_009de628,9);
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


// ==== FUN_0069fc60 @ 0x0069fc60 ====

/* WARNING: Removing unreachable block (ram,0x0069fd64) */
/* WARNING: Removing unreachable block (ram,0x0069fdab) */
/* WARNING: Removing unreachable block (ram,0x0069fdc7) */

void FUN_0069fc60(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 auStack_36 [14];
  int iStack_28;
  undefined4 local_20;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_20 = 0xf;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_edit_text_009de634,9);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    FUN_00550970(auStack_36 + -6);
    uVar3 = FUN_00404300(&local_20,auStack_36 + -6);
    FUN_00401660(uVar3,0,0xffffffff);
    piVar1 = DAT_00b5aca8;
    if (0xf < local_8) {
      _free(local_1c);
      return;
    }
    if (iStack_28 == 0) {
      FUN_00401830(&DAT_009de63e);
      FUN_00551410(&local_20);
      if (0xf < local_8) {
        _free(local_1c);
        return;
      }
      FUN_0069fbc0();
    }
    else {
      FUN_00401660(auStack_36 + -6,0,0xffffffff);
      (**(code **)(*piVar1 + 0xa4))();
    }
  }
  return;
}


// ==== FUN_0069fde0 @ 0x0069fde0 ====

undefined4 FUN_0069fde0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *in_ECX;
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      iVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_yes_009de640,7);
      if (iVar1 == 0) {
        FUN_0069fc60();
        return 1;
      }
      (**(code **)(*in_ECX + 0x10))();
      return 1;
    }
  }
  else if ((param_1 == 2) && (param_3 == 4)) {
    iVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_edit_text_009de648,9);
    if (iVar1 == 0) {
      FUN_0069fc60();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0069fe60 @ 0x0069fe60 ====

void FUN_0069fe60(void)

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
  FUN_00401740(s_UI_Game2_Guild_ui_nameInputWnd_t_009de604,0x22);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_0069fbc0();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0069fee0 @ 0x0069fee0 ====

undefined4 FUN_0069fee0(int *param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 != 0x70320006) {
    return 0;
  }
  if ((char)param_1[1] == '\x01') {
    (**(code **)(*in_ECX + 0x10))();
    return 1;
  }
  FUN_0069fbc0();
  return 1;
}


// ==== FUN_0069ff20 @ 0x0069ff20 ====

void FUN_0069ff20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009de65c;
  FUN_0069fe60();
  return;
}


// ==== FUN_0069ff40 @ 0x0069ff40 ====

undefined4 FUN_0069ff40(void)

{
  return 0x2d;
}


// ==== FUN_0069ff50 @ 0x0069ff50 ====

void FUN_0069ff50(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009de65c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0069ff90 @ 0x0069ff90 ====

void FUN_0069ff90(void)

{
  return;
}


