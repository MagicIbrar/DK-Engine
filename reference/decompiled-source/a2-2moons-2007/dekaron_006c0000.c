// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x6c0000-0x6cffff

// ==== __break @ 0x006c00cf ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_006c00d0 @ 0x006c00d0 ====

void FUN_006c00d0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *******pppppppuVar6;
  undefined4 *******pppppppuVar7;
  undefined4 *puVar8;
  int *piVar9;
  int in_ECX;
  int iVar10;
  char *pcVar11;
  undefined1 auStack_3c [8];
  undefined4 *******apppppppuStack_34 [4];
  int iStack_24;
  uint uStack_20;
  undefined1 auStack_1c [28];
  
  iVar1 = param_1;
  param_1 = *(int *)(param_1 + 0x14);
  if (param_1 != 0) {
    iVar2 = (**(code **)(*DAT_00b5a6b0 + 8))();
    if (*(int *)(iVar1 + 0x14) == 0) {
      FUN_0079dba3();
    }
    piVar9 = (int *)(iVar1 + 4);
    if (*(uint *)(iVar1 + 0x18) < 0x10) {
      piVar3 = piVar9;
    }
    else {
      piVar3 = (int *)*piVar9;
    }
    if ((char)*piVar3 != ';') {
      if (*(int *)(iVar1 + 0x14) == 0) {
        FUN_0079dba3();
      }
      if (*(uint *)(iVar1 + 0x18) < 0x10) {
        piVar3 = piVar9;
      }
      else {
        piVar3 = (int *)*piVar9;
      }
      if ((char)*piVar3 == '!') {
        if (iVar2 == 1) {
          uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
          if (uVar4 < *(uint *)(in_ECX + 0x14)) {
            uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x3200004);
            FUN_00765c50(uVar5);
            iVar1 = *DAT_00b5ad0c;
            FUN_00765c50(&iStack_24);
            (**(code **)(iVar1 + 0x28))(2);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          *(uint *)(in_ECX + 0x14) = uVar4 + 10000;
        }
        *(undefined4 *)(in_ECX + 0x50) = 1;
        uStack_20 = 0xf;
        iStack_24 = 0;
        apppppppuStack_34[0] = (undefined4 *******)((uint)apppppppuStack_34[0] & 0xffffff00);
        FUN_00401660(iVar1,0,0xffffffff);
        pppppppuVar7 = apppppppuStack_34[0];
        if (uStack_20 < 0x10) {
          pppppppuVar7 = apppppppuStack_34;
        }
        pppppppuVar6 = apppppppuStack_34[0];
        if (uStack_20 < 0x10) {
          pppppppuVar6 = apppppppuStack_34;
        }
        FUN_004311b0((int)pppppppuVar6 + 1,(int)pppppppuVar7 + iStack_24);
        iVar1 = *(int *)(in_ECX + 0x54);
        if (((iVar1 != 3) && (iVar1 != 2)) && (iVar1 != 4)) {
LAB_006c0312:
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        *(undefined4 *)(in_ECX + 0x54) = 1;
        pcVar11 = s_btn_normal_009e2504;
      }
      else {
        if (*(int *)(iVar1 + 0x14) == 0) {
          FUN_0079dba3();
        }
        if (0xf < *(uint *)(iVar1 + 0x18)) {
          piVar9 = (int *)*piVar9;
        }
        if (*(char *)piVar9 != '#') {
          pcVar11 = (char *)FUN_004d9a40(0);
          if (*pcVar11 == '&') {
            *(undefined4 *)(in_ECX + 0x50) = 10;
            FUN_00765c50(iVar1);
            piVar9 = (int *)FUN_0042eaf0(&param_1);
            iVar1 = *piVar9;
            puVar8 = (undefined4 *)FUN_0042eb10(auStack_3c);
            FUN_004311b0(iVar1 + 1,*puVar8);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          pcVar11 = (char *)FUN_004d9a40(0);
          iVar2 = param_1;
          if (*pcVar11 == '\"') {
            iVar10 = 0;
            if (param_1 < 1) {
              return;
            }
            while ((pcVar11 = (char *)FUN_004d9a40(iVar10), *pcVar11 != ' ' ||
                   (pcVar11 = (char *)FUN_004d9a40(0), *pcVar11 != '\"'))) {
              iVar10 = iVar10 + 1;
              if (iVar2 <= iVar10) {
                return;
              }
            }
            *(undefined4 *)(in_ECX + 0x50) = 3;
            FUN_00765c50(iVar1);
            piVar9 = (int *)FUN_0042eaf0(&param_1);
            iVar1 = *piVar9;
            piVar9 = (int *)FUN_0042eaf0(auStack_3c);
            FUN_004311b0(*piVar9 + 1,iVar1 + iVar10);
            piVar9 = (int *)FUN_0042eaf0(&param_1);
            iVar1 = *piVar9;
            puVar8 = (undefined4 *)FUN_0042eb10(auStack_3c);
            FUN_004311b0(iVar1 + iVar10 + 1,*puVar8);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          pcVar11 = (char *)FUN_004d9a40(0);
          iVar2 = param_1;
          if (*pcVar11 != '\'') {
            return;
          }
          iVar10 = 0;
          if (param_1 < 1) {
            return;
          }
          while ((pcVar11 = (char *)FUN_004d9a40(iVar10), *pcVar11 != ' ' ||
                 (pcVar11 = (char *)FUN_004d9a40(0), *pcVar11 != '\''))) {
            iVar10 = iVar10 + 1;
            if (iVar2 <= iVar10) {
              return;
            }
          }
          *(undefined4 *)(in_ECX + 0x50) = 9;
          FUN_00765c50(iVar1);
          piVar9 = (int *)FUN_0042eaf0(&param_1);
          iVar1 = *piVar9;
          piVar9 = (int *)FUN_0042eaf0(auStack_3c);
          FUN_004311b0(*piVar9 + 1,iVar1 + iVar10);
          piVar9 = (int *)FUN_0042eaf0(&param_1);
          iVar1 = *piVar9;
          puVar8 = (undefined4 *)FUN_0042eb10(auStack_3c);
          FUN_004311b0(iVar1 + iVar10 + 1,*puVar8);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        *(undefined4 *)(in_ECX + 0x50) = 7;
        FUN_00765c50(iVar1);
        pppppppuVar7 = apppppppuStack_34[0];
        if (uStack_20 < 0x10) {
          pppppppuVar7 = apppppppuStack_34;
        }
        puVar8 = (undefined4 *)FUN_0042eb10(&param_1);
        FUN_004311b0((int)pppppppuVar7 + 1,*puVar8);
        if ((*(int *)(in_ECX + 0x54) != 2) && (*(int *)(in_ECX + 0x54) != 4)) goto LAB_006c0312;
        *(undefined4 *)(in_ECX + 0x54) = 3;
        pcVar11 = s_btn_guild_009e2510;
      }
      FUN_00401830(pcVar11);
      FUN_006bdd30(auStack_1c);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    iVar2 = (**(code **)(*DAT_00b5a7b4 + 0x50))();
    if (iVar2 != 0) {
      *(undefined4 *)(in_ECX + 0x50) = 4;
      uStack_20 = 0xf;
      iStack_24 = 0;
      apppppppuStack_34[0] = (undefined4 *******)((uint)apppppppuStack_34[0] & 0xffffff00);
      FUN_00401660(iVar1,0,0xffffffff);
      pppppppuVar7 = apppppppuStack_34[0];
      if (uStack_20 < 0x10) {
        pppppppuVar7 = apppppppuStack_34;
      }
      pppppppuVar6 = apppppppuStack_34[0];
      if (uStack_20 < 0x10) {
        pppppppuVar6 = apppppppuStack_34;
      }
      FUN_004311b0((int)pppppppuVar6 + 1,(int)pppppppuVar7 + iStack_24);
      if ((*(int *)(in_ECX + 0x54) == 3) || (*(int *)(in_ECX + 0x54) == 4)) {
        *(undefined4 *)(in_ECX + 0x54) = 2;
        FUN_00401830(s_btn_party_009e24f8);
        FUN_006bdd30(auStack_1c);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      if (0xf < uStack_20) {
        _free(apppppppuStack_34[0]);
        return;
      }
    }
  }
  return;
}


// ==== FUN_006c05f0 @ 0x006c05f0 ====

void FUN_006c05f0(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_1 != 0) {
    *(int *)(in_ECX + 0x54) = param_1;
    uVar1 = FUN_00405d30(param_1 + -1);
    FUN_006bdd30(uVar1);
    switch(*(undefined4 *)(in_ECX + 0x54)) {
    case 1:
      *(undefined4 *)(in_ECX + 0x50) = 0;
      FUN_006bfe60();
      return;
    case 2:
      *(undefined4 *)(in_ECX + 0x50) = 4;
      FUN_006bfe60();
      return;
    case 3:
      *(undefined4 *)(in_ECX + 0x50) = 7;
      FUN_006bfe60();
      return;
    case 4:
      *(undefined4 *)(in_ECX + 0x50) = 10;
      break;
    case 5:
      *(undefined4 *)(in_ECX + 0x50) = 0xc;
      FUN_006bfe60();
      return;
    }
    FUN_006bfe60();
  }
  return;
}


// ==== FUN_006c06a0 @ 0x006c06a0 ====

/* WARNING: Removing unreachable block (ram,0x006c0ba0) */
/* WARNING: Removing unreachable block (ram,0x006c0a04) */
/* WARNING: Removing unreachable block (ram,0x006c0ae7) */
/* WARNING: Removing unreachable block (ram,0x006c0aec) */
/* WARNING: Removing unreachable block (ram,0x006c0a45) */
/* WARNING: Removing unreachable block (ram,0x006c08d5) */
/* WARNING: Removing unreachable block (ram,0x006c085e) */
/* WARNING: Removing unreachable block (ram,0x006c089a) */
/* WARNING: Removing unreachable block (ram,0x006c0911) */
/* WARNING: Removing unreachable block (ram,0x006c0a9f) */
/* WARNING: Removing unreachable block (ram,0x006c0995) */
/* WARNING: Removing unreachable block (ram,0x006c0b23) */
/* WARNING: Removing unreachable block (ram,0x006c0c05) */
/* WARNING: Removing unreachable block (ram,0x006c0822) */
/* WARNING: Removing unreachable block (ram,0x006c0764) */
/* WARNING: Removing unreachable block (ram,0x006c06e2) */

void FUN_006c06a0(void)

{
  undefined1 uVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  uint in_ECX;
  undefined4 *puVar8;
  int iStack_80;
  undefined *puStack_7c;
  uint uStack_78;
  undefined4 uStack_74;
  undefined2 uStack_3c;
  uint uStack_30;
  
  uStack_74 = s_UI_Game2_ui_chatwnd_txt_009e2000;
  uStack_78 = 0x6c06cc;
  FUN_00401740();
  uStack_74 = (char *)0x6c06d6;
  uVar3 = FUN_00410500();
  uStack_74 = (char *)(uVar3 + 0x3c);
  uStack_78 = 0x6c06ff;
  uVar4 = (**(code **)(*DAT_00b5a798 + 4))();
  *(undefined4 *)(in_ECX + 4) = uVar4;
  if (uVar3 != 0) {
    puStack_7c = (undefined *)0x6c0712;
    uStack_78 = uVar3;
    (**(code **)(*DAT_00b5a7cc + 0x14))();
  }
  puStack_7c = (undefined *)0x6c071b;
  uStack_78 = in_ECX;
  (**(code **)(**(int **)(in_ECX + 4) + 0x40))();
  puStack_7c = &DAT_00b329d4;
  iStack_80 = 0x6c0728;
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  iStack_80 = 0x6c072f;
  uVar1 = (**(code **)(*piVar5 + 0x28))();
  iStack_80 = 8;
  *(undefined1 *)(in_ECX + 8) = uVar1;
  FUN_00401740(s_textview_009e2018);
  iStack_80 = (int)register0x00000010 + -0x68;
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  uVar4 = (**(code **)(*piVar5 + 0x10))();
  FUN_005041e0(uVar4);
  *(undefined2 *)(in_ECX + 0xa8) = uStack_3c;
  puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    uVar4 = (**(code **)(*piVar5 + 4))();
    *puVar6 = &PTR_FUN_009bcd68;
    puVar6[1] = uVar4;
  }
  *(undefined1 *)(puVar6 + 2) = 0;
  puVar8 = puVar6;
  (**(code **)(*DAT_00b5ad24 + 4))();
  (**(code **)*puVar6)();
  uVar1 = (**(code **)(*DAT_00b5ad0c + 0x40))();
  *(undefined1 *)(in_ECX + 10) = uVar1;
  FUN_00401740(s_btn_normal_009e2024,10);
  FUN_00406720(&uStack_74);
  FUN_00401740(s_btn_party_009e2030,9);
  FUN_00406720(&uStack_74);
  FUN_00401740(s_btn_guild_009e203c,9);
  FUN_00406720(&uStack_74);
  FUN_00401740(s_btn_guildmember_009e2048,0xf);
  FUN_00406720(&uStack_74);
  FUN_00401740(s_btn_pcstore_009e2058,0xb);
  FUN_00406720(&uStack_74);
  cVar2 = (**(code **)(*DAT_00b5ae58 + 8))();
  if (cVar2 == '\0') {
    FUN_00401740(s_btn_messenger_009e2064,0xd);
    iVar7 = (**(code **)(*DAT_00b5ae3c + 0x88))();
    uStack_78 = CONCAT31(uStack_78._1_3_,iVar7 != 0);
    piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_74);
    if (piVar5 != (int *)0x0) {
      cVar2 = (**(code **)(*piVar5 + 0x28))();
      if (cVar2 != (char)puStack_7c) {
        (**(code **)(*piVar5 + 0x24))(puStack_7c);
      }
    }
    uStack_74 = (char *)((uint)uStack_74 & 0xffffff00);
    FUN_00401740(s_btn_mail_009e2074,8);
    uVar1 = (**(code **)(*DAT_00b5ae48 + 0x2c))();
    puStack_7c = (undefined *)CONCAT31(puStack_7c._1_3_,uVar1);
    piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_78);
    if (piVar5 != (int *)0x0) {
      cVar2 = (**(code **)(*piVar5 + 0x28))();
      if (cVar2 != (char)iStack_80) {
        (**(code **)(*piVar5 + 0x24))(iStack_80);
      }
    }
  }
  else {
    FUN_00401740(s_btn_messenger_009e2080,0xd);
    piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_74);
    if ((piVar5 != (int *)0x0) && (cVar2 = (**(code **)(*piVar5 + 0x28))(), cVar2 != '\0')) {
      (**(code **)(*piVar5 + 0x24))(0);
    }
    uStack_74 = (char *)((uint)uStack_74 & 0xffffff00);
    FUN_00401740(s_btn_mail_009e2090,8);
    piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_78);
    if ((piVar5 != (int *)0x0) && (cVar2 = (**(code **)(*piVar5 + 0x28))(), cVar2 != '\0')) {
      (**(code **)(*piVar5 + 0x24))(0);
    }
    uStack_78 = uStack_78 & 0xffffff00;
    FUN_00401740(s_btn_action_009e209c,10);
    piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&puStack_7c);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x44))(0);
    }
  }
  uStack_78 = uStack_78 & 0xffffff00;
  FUN_00401740(s_btn_normal_009e20a8,10);
  FUN_006bdd30(&puStack_7c);
  FUN_006be4b0();
  FUN_006be540(0);
  FUN_006bdf50();
  uStack_78 = uStack_78 & 0xffffff00;
  FUN_00401740(s_btn_plus_009e20b4,8);
  iStack_80 = CONCAT31(iStack_80._1_3_,*(undefined1 *)(in_ECX + 10));
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&puStack_7c);
  if ((piVar5 != (int *)0x0) && (cVar2 = (**(code **)(*piVar5 + 0x28))(), cVar2 != (char)puVar8)) {
    (**(code **)(*piVar5 + 0x24))(puVar8);
  }
  puStack_7c = (undefined *)((uint)puStack_7c & 0xffffff00);
  FUN_00401740(s_btn_minus_009e20c0,9);
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&iStack_80);
  if ((piVar5 != (int *)0x0) && (cVar2 = (**(code **)(*piVar5 + 0x28))(), cVar2 != '\x01')) {
    (**(code **)(*piVar5 + 0x24))(1);
  }
  FUN_006be6d0();
  FUN_006be030();
  FUN_006bfe60();
  if (uStack_30 < 0x10) {
    return;
  }
  _free((void *)0x0);
  return;
}


// ==== FUN_006c0c50 @ 0x006c0c50 ====

undefined4 FUN_006c0c50(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined1 auStack_38 [4];
  void *pvStack_34;
  uint uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 < 0x70040009) {
    if (uVar1 == 0x70040008) {
      FUN_006beb90(param_1 + 1);
      return 1;
    }
    if (uVar1 < 0x70040004) {
      if (uVar1 == 0x70040003) {
        FUN_006be880(param_1);
        return 1;
      }
      if (uVar1 == 0x20001) {
        uVar2 = FUN_006bed10(param_1);
        if ((char)uVar2 == '\x01') {
          return uVar2;
        }
      }
      else if (uVar1 == 0x70040002) {
        FUN_006bfe60();
        return 1;
      }
    }
    else if (uVar1 == 0x70040007) {
      FUN_006bea10(param_1 + 1);
      return 1;
    }
  }
  else if (uVar1 < 0x70340022) {
    if (uVar1 == 0x70340021) {
      FUN_00401830(s_btn_messenger_009e20f4);
      iVar3 = (**(code **)(*DAT_00b5ae3c + 0x88))();
      FUN_006bdd00(auStack_38,iVar3 != 0);
      if (uStack_20 < 0x10) {
        return 1;
      }
      _free(pvStack_34);
      return extraout_EAX;
    }
    if (uVar1 == 0x70040011) {
      FUN_006be030();
      return 0;
    }
    if (uVar1 == 0x70040018) {
      FUN_006be940(param_1[1],param_1[2],param_1[3],param_1[4]);
      return 1;
    }
  }
  else if (uVar1 == 0x70360008) {
    FUN_00401830(s_btn_mail_009e2104);
    uVar2 = (**(code **)(*DAT_00b5ae48 + 0x2c))();
    FUN_006bdd00(auStack_1c,uVar2);
    if (uStack_4 < 0x10) {
      return 1;
    }
    _free(pvStack_18);
    return extraout_EAX_00;
  }
  return 0;
}


// ==== FUN_006c0df0 @ 0x006c0df0 ====

void FUN_006c0df0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  void *pvStack_b0;
  char *pcStack_9c;
  undefined4 uStack_7c;
  void *pvStack_78;
  undefined4 uStack_74;
  void *pvStack_70;
  undefined4 uStack_6c;
  int iStack_68;
  uint uStack_64;
  undefined4 uStack_60;
  void *pvStack_5c;
  undefined1 local_58;
  int iStack_4c;
  uint local_48;
  undefined4 local_44;
  void *local_40;
  undefined1 local_3c [4];
  undefined1 uStack_38;
  undefined4 uStack_30;
  uint local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  
  local_44 = 0xf;
  local_48 = 0;
  local_58 = 0;
  local_28 = 0xf;
  local_2c = 0;
  local_3c[0] = 0;
  pcStack_9c = (char *)0x6c0e2b;
  FUN_00401740();
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (0xf < local_2c) {
    pcStack_9c = (char *)0x6c0e4b;
    _free(local_40);
    return;
  }
  local_2c = 0xf;
  uStack_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  (**(code **)(*piVar2 + 0x30))();
  pcStack_9c = (char *)0x6c0e73;
  FUN_00550970();
  if (iStack_4c == 0) {
    FUN_005514b0();
    if (0xf < local_48) {
      pcStack_9c = (char *)0x6c0e95;
      _free(pvStack_5c);
      return;
    }
  }
  else {
    pcStack_9c = &DAT_009e23f0;
    uStack_6c = 0;
    iStack_68 = 0;
    uStack_64 = 0;
    local_2c = 0xf;
    uStack_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401740();
    pcStack_9c = (char *)0x6c0ed9;
    FUN_00406720();
    if (0xf < local_2c) {
      pcStack_9c = (char *)0x6c0eee;
      _free(local_40);
      return;
    }
    pcStack_9c = &DAT_009e23f4;
    local_2c = 0xf;
    uStack_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401740();
    pcStack_9c = (char *)0x6c0f1b;
    FUN_00406720();
    if (0xf < local_2c) {
      pcStack_9c = (char *)0x6c0f2b;
      _free(local_40);
      return;
    }
    pcStack_9c = &DAT_009e23f8;
    local_2c = 0xf;
    uStack_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401740();
    pcStack_9c = (char *)0x6c0f58;
    FUN_00406720();
    if (0xf < local_2c) {
      pcStack_9c = (char *)0x6c0f68;
      _free(local_40);
      return;
    }
    pcStack_9c = s___BS___009e23fc;
    uStack_7c = 0;
    pvStack_78 = (void *)0x0;
    uStack_74 = 0;
    local_2c = 0xf;
    uStack_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401740();
    pcStack_9c = (char *)0x6c0fa1;
    FUN_00406720();
    if (0xf < local_2c) {
      pcStack_9c = (char *)0x6c0fb1;
      _free(local_40);
      return;
    }
    pcStack_9c = s___GT___009e2404;
    local_2c = 0xf;
    uStack_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401740();
    pcStack_9c = (char *)0x6c0fde;
    FUN_00406720();
    if (0xf < local_2c) {
      pcStack_9c = (char *)0x6c0fee;
      _free(local_40);
      return;
    }
    pcStack_9c = s___LT___009e240c;
    local_2c = 0xf;
    uStack_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401740();
    pcStack_9c = (char *)0x6c101b;
    FUN_00406720();
    piVar2 = DAT_00b5ad0c;
    if (0xf < local_2c) {
      pcStack_9c = (char *)0x6c102b;
      _free(local_40);
      return;
    }
    pcStack_9c = (char *)0x0;
    FUN_00401660(&uStack_60,0,0xffffffff);
    (**(code **)(*piVar2 + 0x5c))();
    uVar3 = FUN_00404a40(&uStack_60,&uStack_7c,local_3c + -0x50,&pcStack_9c);
    FUN_00401660(uVar3,0,0xffffffff);
    if (0xf < local_48) {
      _free(pvStack_5c);
      return;
    }
    FUN_006c00d0(&uStack_7c);
    FUN_006bedf0(&uStack_7c);
    FUN_005514b0();
    if (iStack_68 == 0) {
      FUN_00406250();
      FUN_00406250();
      if (0xf < uStack_64) {
        _free(pvStack_78);
        return;
      }
    }
    else {
      local_44 = *(undefined4 *)(in_ECX + 0x50);
      local_40 = (void *)0x0;
      uStack_24 = 0xf;
      local_28 = 0;
      uStack_38 = 0;
      FUN_00401660(&uStack_7c,0,0xffffffff);
      piVar2 = DAT_00b5ad0c;
      iVar1 = *(int *)(in_ECX + 0x50);
      if (iVar1 == 0xc) {
        local_44 = 0;
      }
      if (iVar1 == 3) {
        FUN_00401660(in_ECX + 0x18,0,0xffffffff);
        FUN_00401660(local_3c,0,0xffffffff);
        (**(code **)(*piVar2 + 0x20))();
      }
      else if (iVar1 == 7) {
        iVar1 = *DAT_00b5aca8;
        FUN_00765c50(&uStack_7c);
        (**(code **)(iVar1 + 0xc0))();
      }
      else if (iVar1 == 10) {
        iVar1 = *DAT_00b5aca8;
        FUN_00765c50(&uStack_7c);
        (**(code **)(iVar1 + 0xc4))();
      }
      else if (iVar1 == 9) {
        iVar1 = *DAT_00b5aca8;
        FUN_00765c50(&uStack_7c);
        FUN_00765c50(in_ECX + 0x18);
        (**(code **)(iVar1 + 200))();
      }
      else {
        (**(code **)(*DAT_00b5ad0c + 0x1c))(&local_44);
      }
      if (*(int *)(in_ECX + 0x54) == 1) {
        *(undefined4 *)(in_ECX + 0x50) = 0;
      }
      iVar1 = *(int *)(in_ECX + 0x50);
      if ((((iVar1 != 4) && (iVar1 != 0xc)) && (iVar1 != 7)) && (iVar1 != 10)) {
        *(uint *)(in_ECX + 0x50) = (iVar1 != 9) - 1 & 7;
        FUN_006c1c60();
        FUN_00406250();
        FUN_00406250();
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      if ((void *)0xf < pvStack_5c) {
        _free(pvStack_70);
        return;
      }
      pvStack_5c = (void *)0xf;
      uStack_60 = 0;
      pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
      FUN_00406250();
      FUN_00406250();
      if ((char *)0xf < pcStack_9c) {
        _free(pvStack_b0);
        return;
      }
    }
  }
  return;
}


// ==== FUN_006c12e0 @ 0x006c12e0 ====

void FUN_006c12e0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009e2548;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined1 *)((int)in_ECX + 9) = 0;
  *(undefined1 *)((int)in_ECX + 10) = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[5] = 0;
  in_ECX[0xc] = 0xf;
  in_ECX[0xb] = 0;
  *(undefined1 *)(in_ECX + 7) = 0;
  in_ECX[0x13] = 0xf;
  in_ECX[0x12] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  FUN_006c2530();
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  in_ECX[1] = 0;
  if ((uint)in_ECX[0xc] < 0x10) {
    puVar3 = in_ECX + 7;
  }
  else {
    puVar3 = (undefined4 *)in_ECX[7];
  }
  if ((uint)in_ECX[0xc] < 0x10) {
    puVar2 = in_ECX + 7;
  }
  else {
    puVar2 = (undefined4 *)in_ECX[7];
  }
  FUN_004bdb30(local_4,puVar2,in_ECX[0xb] + (int)puVar3);
  uVar1 = in_ECX[0x12];
  if ((uVar1 < 0x186a1) && (in_ECX[0x13] != 100000)) {
    if ((uint)in_ECX[0x13] < 100000) {
      FUN_00401410(100000,uVar1);
    }
    in_ECX[0x12] = uVar1;
    if ((uint)in_ECX[0x13] < 0x10) {
      puVar3 = in_ECX + 0xe;
    }
    else {
      puVar3 = (undefined4 *)in_ECX[0xe];
    }
    *(undefined1 *)(uVar1 + (int)puVar3) = 0;
  }
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 1;
  FUN_006c06a0();
  return;
}


// ==== FUN_006c13c0 @ 0x006c13c0 ====

undefined4 FUN_006c13c0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 uVar5;
  int in_ECX;
  void *unaff_EBP;
  undefined4 local_1c;
  undefined4 uStack_14;
  uint uStack_10;
  uint uStack_8;
  
  if (param_1 == 2) {
    if (param_3 == 4) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_edit_text_009e21dc,9);
      if (iVar2 == 0) {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009b1798;
        }
        puVar3[1] = 0xffffffff;
        FUN_00797a20(puVar3);
        FUN_006c0df0();
        FUN_00401830(s_edit_text_009e21e8);
        piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
        (**(code **)(*piVar4 + 0x60))();
        if (0xf < uStack_8) {
          _free(local_1c);
          return extraout_EAX;
        }
        *(undefined1 *)(in_ECX + 0xc) = 0;
        piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&DAT_00b329d4);
        if ((piVar4 != (int *)0x0) && (cVar1 = (**(code **)(*piVar4 + 0x28))(), cVar1 != '\0')) {
          (**(code **)(*piVar4 + 0x24))(0);
        }
        FUN_00401830(s_textview_009e21f4);
        piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))
                                  ((int)register0x00000010 + -0x24);
        if (uStack_10 < 0x10) {
          uStack_10 = 0xf;
          uStack_14 = 0;
          iVar2 = (**(code **)(*piVar4 + 0x30))();
          *(undefined1 *)(iVar2 + 0x179) = 1;
          FUN_005569f0(in_ECX + 0x34,0);
          *(undefined1 *)(in_ECX + 8) = 0;
          return 1;
        }
        _free(unaff_EBP);
        return extraout_EAX_00;
      }
    }
    else if ((param_3 == 0xc) && (cVar1 = FUN_004036a0(param_2,s_edit_text_009e2358), cVar1 != '\0')
            ) {
      uVar5 = (**(code **)(*DAT_00b5ad0c + 0x38))(&local_1c);
      FUN_00401660(uVar5,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  else if (param_1 == 1) {
    if (param_3 == 1) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_normal_009e2200,10);
      if (iVar2 == 0) {
        *(undefined4 *)(in_ECX + 0x50) = 0;
        *(undefined4 *)(in_ECX + 0x54) = 1;
      }
      else {
        cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
        if (cVar1 == '\x01') {
          return 1;
        }
        cVar1 = FUN_004036a0(param_2,s_btn_messenger_009e220c);
        if (cVar1 != '\0') {
          iVar2 = (**(code **)(*DAT_00b5a74c + 0xc))(0x4f);
          if (iVar2 != 0) {
            FUN_0069a140();
            FUN_00401830(s_btn_messenger_009e221c);
            (**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x20);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          return 0;
        }
        cVar1 = FUN_004036a0(param_2,s_btn_party_009e222c);
        if (cVar1 == '\0') {
          cVar1 = FUN_004036a0(param_2,s_btn_pcstore_009e2238);
          if (cVar1 == '\0') {
            cVar1 = FUN_004036a0(param_2,s_btn_guild_009e2244);
            if (cVar1 == '\0') {
              cVar1 = FUN_004036a0(param_2,s_btn_guildmember_009e2250);
              if (cVar1 != '\0') {
                *(undefined4 *)(in_ECX + 0x50) = 10;
                *(undefined4 *)(in_ECX + 0x54) = 4;
                FUN_006bfe60();
                FUN_006bdd30(param_2);
                return 1;
              }
              cVar1 = FUN_004036a0(param_2,s_btn_logsave_009e2260);
              if (cVar1 != '\0') {
                piVar4 = (int *)(**(code **)(*DAT_00b5ad10 + 4))();
                (**(code **)(*piVar4 + 0x10))();
                return 1;
              }
              cVar1 = FUN_004036a0(param_2,s_btn_help_009e226c);
              if (cVar1 != '\0') {
                (**(code **)(*DAT_00b5ad0c + 0x6c))();
                return 1;
              }
              cVar1 = FUN_004036a0(param_2,s_btn_plus_009e2278);
              if (cVar1 != '\0') {
                *(undefined1 *)(in_ECX + 10) = 0;
                FUN_006bdd00(param_2,0);
                FUN_00401830(s_btn_minus_009e2284);
                FUN_006bdd00(&local_1c,1);
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              cVar1 = FUN_004036a0(param_2,s_btn_minus_009e2290);
              if (cVar1 != '\0') {
                *(undefined1 *)(in_ECX + 10) = 1;
                FUN_006bdd00(param_2,0);
                FUN_00401830(s_btn_plus_009e229c);
                FUN_006bdd00(&local_1c,1);
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              cVar1 = FUN_004036a0(param_2,s_textview_scroll_endbtn_009e22a8);
              if (cVar1 != '\0') {
                FUN_00401830(s_textview_009e22c0);
                (**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              cVar1 = FUN_004036a0(param_2,s_btn_alpha_009e22cc);
              if (cVar1 != '\0') {
                FUN_00401830(s_pan_alpha_009e22d8);
                (**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              cVar1 = FUN_004036a0(param_2,s_btn_alpha_ok_009e22e4);
              if (cVar1 != '\0') {
                FUN_00401830(s_pan_alpha_009e22f4);
                (**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              cVar1 = FUN_004036a0(param_2,s_btn_alpha_cancel_009e230c);
              if (cVar1 != '\0') {
                FUN_00401830(s_pan_alpha_009e2320);
                (**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              cVar1 = FUN_004036a0(param_2,s_btn_action_009e2338);
              if (cVar1 != '\0') {
                FUN_00401830(s_com_action_drop_btn_009e2344);
                (**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              return 0;
            }
            *(undefined4 *)(in_ECX + 0x50) = 7;
            *(undefined4 *)(in_ECX + 0x54) = 3;
          }
          else {
            *(undefined4 *)(in_ECX + 0x50) = 0xc;
            *(undefined4 *)(in_ECX + 0x54) = 5;
          }
        }
        else {
          *(undefined4 *)(in_ECX + 0x50) = 4;
          *(undefined4 *)(in_ECX + 0x54) = 2;
        }
      }
      FUN_006bdd30(param_2);
      FUN_006bfe60();
      return 1;
    }
  }
  else if (param_1 == 0x14) {
    if ((param_3 == 7) && (cVar1 = FUN_004036a0(param_2,s_sld_alpha_009e2364), cVar1 != '\0')) {
      FUN_006be540(0);
      return 1;
    }
  }
  else if (((param_1 == 0x15) && (param_3 == 1)) &&
          (cVar1 = FUN_004036a0(param_2,s_com_action_009e2370), cVar1 != '\0')) {
    (**(code **)(*DAT_00b5aefc + 0x10))(param_4);
    return 1;
  }
  return 0;
}


// ==== FUN_006c1af0 @ 0x006c1af0 ====

int FUN_006c1af0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c800;
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


// ==== Catch@006c1b56 @ 0x006c1b56 ====

void Catch_006c1b56(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006c1b60 @ 0x006c1b60 ====

void FUN_006c1b60(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c810;
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


// ==== Catch@006c1bcf @ 0x006c1bcf ====

void Catch_006c1bcf(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_006c1bf0 @ 0x006c1bf0 ====

void FUN_006c1bf0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0098c820;
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


// ==== Catch@006c1c56 @ 0x006c1c56 ====

void Catch_006c1c56(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006c1c60 @ 0x006c1c60 ====

void FUN_006c1c60(void)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x20) < 0x10) {
    *(undefined4 *)(in_ECX + 0x20) = 0xf;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined1 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0xc));
  return;
}


// ==== FUN_006c1c90 @ 0x006c1c90 ====

void FUN_006c1c90(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_006c1af0(param_1,param_2,param_3);
  return;
}


// ==== FUN_006c1cb0 @ 0x006c1cb0 ====

int FUN_006c1cb0(int param_1,int param_2,undefined4 param_3)

{
  FUN_006c1bf0(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_006c1ce0 @ 0x006c1ce0 ====

void FUN_006c1ce0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = *param_3;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_3 + 1,0,0xffffffff);
  return;
}


// ==== FUN_006c1d20 @ 0x006c1d20 ====

void FUN_006c1d20(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0098c830;
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
      uVar5 = FUN_006c1c90(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_006c1cb0(uVar5,param_2,&local_18);
      FUN_006c1c90(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_006c1af0(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_006c1cb0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_006c1af0(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@006c1e81 @ 0x006c1e81 ====

void Catch_006c1e81(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_006c1f70 @ 0x006c1f70 ====

void FUN_006c1f70(void)

{
  undefined4 *puVar1;
  void *_Memory;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 4);
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  if (_Memory == *(void **)(in_ECX + 4)) {
    return;
  }
  if (*(uint *)((int)_Memory + 0x24) < 0x10) {
    *(undefined4 *)((int)_Memory + 0x24) = 0xf;
    *(undefined4 *)((int)_Memory + 0x20) = 0;
    *(undefined1 *)((int)_Memory + 0x10) = 0;
    _free(_Memory);
    return;
  }
  _free(*(void **)((int)_Memory + 0x10));
  return;
}


// ==== FUN_006c1fd0 @ 0x006c1fd0 ====

void * FUN_006c1fd0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c840;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x28);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_006c1ce0(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@006c203d @ 0x006c203d ====

void Catch_006c203d(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_006c2060 @ 0x006c2060 ====

void FUN_006c2060(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c850;
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
    uVar2 = FUN_006c1cb0(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@006c20f4 @ 0x006c20f4 ====

void Catch_006c20f4(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_006c2110 @ 0x006c2110 ====

void FUN_006c2110(uint param_1,undefined1 param_2)

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
    FUN_006c1d20(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_006c2180 @ 0x006c2180 ====

void FUN_006c2180(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  
  uVar4 = (param_2[2] ^ 0xdeadbeefU) & *(uint *)(in_ECX + 0x20);
  if (*(uint *)(in_ECX + 0x24) <= uVar4) {
    uVar4 = uVar4 + (-1 - (*(uint *)(in_ECX + 0x20) >> 1));
  }
  iVar3 = *(int *)(in_ECX + 0x14);
  iVar1 = uVar4 * 4;
  piVar2 = *(int **)(iVar1 + iVar3);
  while ((param_2 == piVar2 &&
         (*(undefined4 *)(iVar1 + iVar3) = **(undefined4 **)(iVar1 + iVar3), uVar4 != 0))) {
    iVar3 = *(int *)(in_ECX + 0x14);
    uVar4 = uVar4 - 1;
    iVar1 = uVar4 * 4;
    piVar2 = *(int **)(iVar1 + iVar3);
  }
  if (param_2 == *(int **)(in_ECX + 8)) {
    *param_1 = *param_2;
    return;
  }
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  if ((uint)param_2[9] < 0x10) {
    param_2[9] = 0xf;
    param_2[8] = 0;
    *(undefined1 *)(param_2 + 4) = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[4]);
  return;
}


// ==== FUN_006c2230 @ 0x006c2230 ====

/* WARNING: Removing unreachable block (ram,0x006c224b) */
/* WARNING: Removing unreachable block (ram,0x006c2250) */
/* WARNING: Removing unreachable block (ram,0x006c225e) */

void FUN_006c2230(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_006c1d20(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_006c2280 @ 0x006c2280 ====

/* WARNING: Removing unreachable block (ram,0x006c2368) */

void FUN_006c2280(int *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  uVar6 = *(uint *)(in_ECX + 0x24);
  if (uVar6 <= *(uint *)(in_ECX + 0xc) >> 2) {
    if (*(int *)(in_ECX + 0x14) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
    }
    if (uVar6 < iVar3 - 1U) {
      if (*(uint *)(in_ECX + 0x20) < uVar6) {
        *(uint *)(in_ECX + 0x20) = *(uint *)(in_ECX + 0x20) * 2 + 1;
      }
    }
    else {
      if (*(int *)(in_ECX + 0x14) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
      }
      *(int *)(in_ECX + 0x20) = iVar3 * 2 + -3;
      FUN_006c2110(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
    }
    uVar6 = (*(int *)(in_ECX + 0x24) - (*(uint *)(in_ECX + 0x20) >> 1)) - 1;
    puVar7 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
    if (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4 + 4)) {
      do {
        iVar3 = uVar6 * 4;
        if (((puVar7[2] ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20)) == uVar6) {
          puVar8 = (undefined4 *)*puVar7;
        }
        else {
          puVar8 = (undefined4 *)*puVar7;
          if (puVar8 != *(undefined4 **)(in_ECX + 8)) {
            puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
            uVar4 = uVar6;
            while ((puVar7 == puVar1 &&
                   (*(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3) = puVar8, uVar4 != 0))) {
              uVar4 = uVar4 - 1;
              iVar3 = uVar4 * 4;
              puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
            }
            iVar3 = *(int *)(in_ECX + 8);
            *(undefined4 **)puVar7[1] = puVar8;
            *(int *)puVar8[1] = iVar3;
            **(undefined4 **)(iVar3 + 4) = puVar7;
            uVar2 = *(undefined4 *)(iVar3 + 4);
            *(undefined4 *)(iVar3 + 4) = puVar8[1];
            puVar8[1] = puVar7[1];
            puVar7[1] = uVar2;
            puVar7 = *(undefined4 **)(*(int *)(in_ECX + 8) + 4);
            *(int *)(*(int *)(in_ECX + 0x14) + 4 + *(int *)(in_ECX + 0x24) * 4) =
                 *(int *)(in_ECX + 8);
          }
          for (uVar4 = *(uint *)(in_ECX + 0x24);
              (uVar6 < uVar4 &&
              (*(int *)(*(int *)(in_ECX + 0x14) + uVar4 * 4) == *(int *)(in_ECX + 8)));
              uVar4 = uVar4 - 1) {
            *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar4 * 4) = puVar7;
          }
          if (puVar8 == *(undefined4 **)(in_ECX + 8)) break;
        }
        puVar7 = puVar8;
      } while (puVar8 != *(undefined4 **)(uVar6 * 4 + 4 + *(int *)(in_ECX + 0x14)));
    }
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
  }
  uVar6 = *param_2;
  uVar4 = (uVar6 ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20);
  if (*(uint *)(in_ECX + 0x24) <= uVar4) {
    uVar4 = uVar4 + (-1 - (*(uint *)(in_ECX + 0x20) >> 1));
  }
  iVar3 = uVar4 * 4;
  puVar7 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + 4 + iVar3);
  if (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3)) {
    do {
      puVar7 = (undefined4 *)puVar7[1];
      if ((uint)puVar7[2] <= uVar6) {
        if (uVar6 <= (uint)puVar7[2]) {
          *param_1 = (int)puVar7;
          *(undefined1 *)(param_1 + 1) = 0;
          return;
        }
        puVar7 = (undefined4 *)*puVar7;
        break;
      }
    } while (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3));
  }
  iVar5 = FUN_006c1fd0(puVar7,puVar7[1],param_2);
  FUN_0059c010(1);
  puVar7[1] = iVar5;
  **(int **)(iVar5 + 4) = iVar5;
  iVar5 = puVar7[1];
  puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
  while ((puVar7 == puVar8 && (*(int *)(*(int *)(in_ECX + 0x14) + iVar3) = iVar5, uVar4 != 0))) {
    uVar4 = uVar4 - 1;
    iVar3 = uVar4 * 4;
    puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
  }
  *param_1 = iVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_006c24b0 @ 0x006c24b0 ====

void FUN_006c24b0(undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int in_ECX;
  
  piVar3 = param_3;
  piVar2 = param_2;
  if ((param_2 == (int *)**(int **)(in_ECX + 8)) && (param_3 == *(int **)(in_ECX + 8))) {
    FUN_006c1f70();
    param_2 = *(int **)(in_ECX + 8);
    FUN_006c2230(9,&param_2);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    *param_1 = **(undefined4 **)(in_ECX + 8);
    return;
  }
  while (piVar2 != piVar3) {
    piVar1 = (int *)*piVar2;
    FUN_006c2180(&param_2,piVar2);
    piVar2 = piVar1;
  }
  *param_1 = piVar2;
  return;
}


// ==== FUN_006c2530 @ 0x006c2530 ====

void FUN_006c2530(void)

{
  undefined4 uVar1;
  undefined1 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = local_5;
  uVar1 = FUN_006c1b60();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  local_4 = *(undefined4 *)(in_ECX + 8);
  FUN_006c2060(9,&local_4);
  *(undefined4 *)(in_ECX + 0x20) = 1;
  *(undefined4 *)(in_ECX + 0x24) = 1;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  return;
}


// ==== FUN_006c2590 @ 0x006c2590 ====

undefined4 FUN_006c2590(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x54);
}


// ==== FUN_006c25a0 @ 0x006c25a0 ====

int FUN_006c25a0(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *local_8;
  undefined4 *local_4;
  
  FUN_005a8440(&local_8,param_1);
  iVar2 = 0;
  for (puVar1 = local_8; puVar1 != local_4; puVar1 = (undefined4 *)*puVar1) {
    iVar2 = iVar2 + 1;
  }
  FUN_006c24b0(&param_1,local_8,local_4);
  return iVar2;
}


// ==== FUN_006c25f0 @ 0x006c25f0 ====

void FUN_006c25f0(byte param_1)

{
  void *in_ECX;
  
  FUN_006beea0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006c2610 @ 0x006c2610 ====

void FUN_006c2610(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 10) == '\0') {
    *(undefined1 *)(in_ECX + 10) = 1;
  }
  return;
}


// ==== FUN_006c2620 @ 0x006c2620 ====

undefined4 FUN_006c2620(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 != 0x70000002) {
    return 0;
  }
  if (*(int *)(in_ECX + 0x3c) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x3c) + 0x18))();
  }
  return 1;
}


// ==== FUN_006c2650 @ 0x006c2650 ====

uint FUN_006c2650(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5ac38 + 0x28))();
  if ((char)uVar1 == '\x01') {
    uVar1 = (**(code **)(*DAT_00b5ac38 + 0x2c))();
    if ((char)uVar1 == '\x01') {
      *(undefined1 *)(in_ECX + 0x40) = 0;
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006c2680 @ 0x006c2680 ====

void FUN_006c2680(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  undefined1 auStack_268 [4];
  undefined4 uStack_264;
  undefined4 uStack_260;
  undefined1 *puStack_25c;
  char *pcStack_258;
  char *pcStack_254;
  undefined1 local_238 [4];
  void *local_234;
  undefined4 local_224;
  uint local_220;
  void *local_21c [4];
  undefined4 uStack_20c;
  uint uStack_208;
  undefined1 auStack_204 [260];
  char acStack_100 [256];
  
  local_220 = 0xf;
  local_224 = 0;
  local_234 = (void *)((uint)local_234 & 0xffffff00);
  pcStack_254 = (char *)0x6c26ae;
  FUN_00401740();
  uVar6 = 1;
  if (*(char *)(in_ECX + 9) != '\0') {
    do {
      iVar3 = **(int **)(in_ECX + 4);
      FUN_00402220(auStack_268,local_238,&DAT_009e25dc);
      FUN_00404230(local_21c);
      piVar2 = (int *)(**(code **)(iVar3 + 0x34))();
      if (0xf < uStack_208) {
        pcStack_254 = (char *)0x6c2705;
        _free(local_21c[0]);
        return;
      }
      uStack_208 = 0xf;
      uStack_20c = 0;
      local_21c[0] = (void *)((uint)local_21c[0] & 0xffffff00);
      if (piVar2 == (int *)0x0) {
        pcStack_254 = s___Handler_Quest_QuestWnd_cpp_009e25e0;
        puStack_25c = auStack_204;
        pcStack_258 = s_File___s__Line___d_009e2600;
        auStack_204[0] = 0;
        uStack_260 = 0x6c2736;
        uStack_260 = FUN_0044a580();
        uStack_264 = 0x6c273c;
        FUN_00797b80();
        FUN_00797a40();
      }
      iVar3 = (**(code **)(*piVar2 + 0x30))();
      if (iVar3 == 0) {
        pcStack_258 = acStack_100;
        pcStack_254 = s_File___s__Line___d_009e2634;
        acStack_100[0] = '\0';
        puStack_25c = (undefined1 *)0x6c2771;
        puStack_25c = (undefined1 *)FUN_0044a580();
        uStack_260 = 0x6c2777;
        FUN_00797b80();
        FUN_00797a40();
      }
      FUN_00558730();
      uVar6 = uVar6 + 1;
    } while (uVar6 <= *(byte *)(in_ECX + 9));
  }
  cVar1 = *(char *)(in_ECX + 8);
  if (cVar1 == '\x01') {
    if (*(int **)(in_ECX + 0x3c) != (int *)0x0) {
      iVar3 = (**(code **)(**(int **)(in_ECX + 0x3c) + 0xc))();
      piVar2 = *(int **)(in_ECX + 0x3c);
      if (iVar3 == 0) {
LAB_006c28ab:
        (**(code **)(*piVar2 + 0x18))();
        goto LAB_006c28b0;
      }
      if (piVar2 != (int *)0x0) {
        (**(code **)*piVar2)();
      }
      *(undefined4 *)(in_ECX + 0x3c) = 0;
    }
    pvVar4 = operator_new(0x3c);
    if (pvVar4 != (void *)0x0) {
      uVar5 = FUN_006e4f50();
      *(undefined4 *)(in_ECX + 0x3c) = uVar5;
      goto LAB_006c28b0;
    }
  }
  else if (cVar1 == '\x02') {
    if (*(int **)(in_ECX + 0x3c) != (int *)0x0) {
      iVar3 = (**(code **)(**(int **)(in_ECX + 0x3c) + 0xc))();
      piVar2 = *(int **)(in_ECX + 0x3c);
      if (iVar3 == 1) goto LAB_006c28ab;
      if (piVar2 != (int *)0x0) {
        (**(code **)*piVar2)();
      }
      *(undefined4 *)(in_ECX + 0x3c) = 0;
    }
    pvVar4 = operator_new(0x3c);
    if (pvVar4 != (void *)0x0) {
      uVar5 = FUN_006e70e0();
      *(undefined4 *)(in_ECX + 0x3c) = uVar5;
      goto LAB_006c28b0;
    }
  }
  else {
    if (cVar1 != '\x03') goto LAB_006c28b0;
    if (*(int **)(in_ECX + 0x3c) == (int *)0x0) {
      pvVar4 = operator_new(0x3c);
      if (pvVar4 != (void *)0x0) {
        uVar5 = FUN_006e8130();
        *(undefined4 *)(in_ECX + 0x3c) = uVar5;
        goto LAB_006c28b0;
      }
    }
    else {
      iVar3 = (**(code **)(**(int **)(in_ECX + 0x3c) + 0xc))();
      piVar2 = *(int **)(in_ECX + 0x3c);
      if (iVar3 == 2) goto LAB_006c28ab;
      if (piVar2 != (int *)0x0) {
        (**(code **)*piVar2)();
      }
      *(undefined4 *)(in_ECX + 0x3c) = 0;
      pvVar4 = operator_new(0x3c);
      if (pvVar4 != (void *)0x0) {
        uVar5 = FUN_006e8130();
        *(undefined4 *)(in_ECX + 0x3c) = uVar5;
        goto LAB_006c28b0;
      }
    }
  }
  *(undefined4 *)(in_ECX + 0x3c) = 0;
LAB_006c28b0:
  if (local_220 < 0x10) {
    return;
  }
  _free(local_234);
  return;
}


// ==== FUN_006c28d0 @ 0x006c28d0 ====

undefined4 FUN_006c28d0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  if ((*(int **)(in_ECX + 0x3c) != (int *)0x0) &&
     (cVar1 = (**(code **)(**(int **)(in_ECX + 0x3c) + 0x14))(param_1,param_2,param_3,param_4),
     cVar1 == '\x01')) {
    return 1;
  }
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009e2648,8);
  if (iVar2 == 0) {
    (**(code **)(*DAT_00b5ac38 + 0x2c))();
    *(undefined1 *)(in_ECX + 0x40) = 0;
    return 1;
  }
  cVar1 = FUN_004036a0(param_2,s_btn_cancel_009e2654);
  if (cVar1 == '\0') {
    cVar1 = FUN_004036a0(param_2,s_tab_quest_1_009e2660);
    if (cVar1 == '\0') {
      cVar1 = FUN_004036a0(param_2,s_tab_quest_2_009e266c);
      if (cVar1 == '\0') {
        cVar1 = FUN_004036a0(param_2,s_tab_quest_3_009e2678);
        if (cVar1 == '\0') {
          return 0;
        }
        cVar1 = '\x03';
      }
      else {
        cVar1 = '\x02';
      }
      if (*(char *)(in_ECX + 8) != cVar1) {
        *(char *)(in_ECX + 8) = cVar1;
        FUN_006c2680();
        return 0;
      }
    }
    else if (*(char *)(in_ECX + 8) != '\x01') {
      *(undefined1 *)(in_ECX + 8) = 1;
      FUN_006c2680();
      return 0;
    }
  }
  else if (*(int **)(in_ECX + 0x3c) != (int *)0x0) {
    iVar2 = *DAT_00b5ac38;
    uVar3 = (**(code **)(**(int **)(in_ECX + 0x3c) + 0x10))();
    (**(code **)(iVar2 + 0x18))(uVar3);
  }
  return 1;
}


// ==== FUN_006c29e0 @ 0x006c29e0 ====

void FUN_006c29e0(void)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  void *pvVar4;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_Quest_ui_quest_txt_009e25b4,0x1b);
  iVar2 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar2 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar3;
  (**(code **)(*piVar3 + 0x40))();
  pvVar4 = operator_new(0x10);
  if (pvVar4 == (void *)0x0) {
    pvVar4 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar4 + 4) = 0;
    *(undefined4 *)((int)pvVar4 + 8) = 0;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0;
  }
  *(void **)(in_ECX + 0x38) = pvVar4;
  uVar1 = (**(code **)(*DAT_00b5ac38 + 0x60))();
  *(undefined1 *)(in_ECX + 8) = uVar1;
  *(undefined1 *)(in_ECX + 9) = 3;
  FUN_006c2680();
  return;
}


// ==== FUN_006c2a90 @ 0x006c2a90 ====

void FUN_006c2a90(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e268c;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  iVar1 = FUN_006c2bf0();
  in_ECX[0xc] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[0xc] + 4) = in_ECX[0xc];
  *(undefined4 *)in_ECX[0xc] = in_ECX[0xc];
  *(undefined4 *)(in_ECX[0xc] + 8) = in_ECX[0xc];
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 0x10) = 1;
  in_ECX[1] = 0;
  in_ECX[0xf] = 0;
  FUN_006c29e0();
  return;
}


// ==== FUN_006c2af0 @ 0x006c2af0 ====

void FUN_006c2af0(void)

{
  int iVar1;
  void *_Memory;
  undefined4 *in_ECX;
  undefined4 unaff_ESI;
  undefined1 auStack_2 [2];
  
  *in_ECX = &PTR_FUN_009e268c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  (**(code **)(*DAT_00b5ac38 + 0x5c))(*(undefined1 *)(in_ECX + 2));
  iVar1 = in_ECX[0xe];
  if (*(int *)(iVar1 + 4) != 0) {
    FUN_006c2e00(*(int *)(iVar1 + 4),*(undefined4 *)(iVar1 + 8),iVar1,unaff_ESI);
    _free(*(void **)(iVar1 + 4));
    return;
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  _Memory = (void *)in_ECX[0xe];
  if (_Memory != (void *)0x0) {
    if (*(int *)((int)_Memory + 4) == 0) {
      *(undefined4 *)((int)_Memory + 4) = 0;
      *(undefined4 *)((int)_Memory + 8) = 0;
      *(undefined4 *)((int)_Memory + 0xc) = 0;
      _free(_Memory);
      return;
    }
    FUN_006c2e00(*(int *)((int)_Memory + 4),*(undefined4 *)((int)_Memory + 8),_Memory,unaff_ESI);
    _free(*(void **)((int)_Memory + 4));
    return;
  }
  in_ECX[0xe] = 0;
  if ((undefined4 *)in_ECX[0xf] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xf])(1);
  }
  in_ECX[0xf] = 0;
  FUN_006c2cd0(auStack_2 + -10,*(undefined4 *)in_ECX[0xc],(undefined4 *)in_ECX[0xc]);
  _free((void *)in_ECX[0xc]);
  return;
}


// ==== FUN_006c2bf0 @ 0x006c2bf0 ====

void FUN_006c2bf0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c860;
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


// ==== Catch@006c2c7a @ 0x006c2c7a ====

void Catch_006c2c7a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_006c2c90 @ 0x006c2c90 ====

void FUN_006c2c90(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_006c2c90(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_006c2cd0 @ 0x006c2cd0 ====

void FUN_006c2cd0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_006c2c90(piVar6[1]);
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


// ==== FUN_006c2d90 @ 0x006c2d90 ====

undefined1 FUN_006c2d90(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x40);
}


// ==== FUN_006c2da0 @ 0x006c2da0 ====

void FUN_006c2da0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x24) != 0) {
    FUN_0068e630(*(int *)(in_ECX + 0x24),*(undefined4 *)(in_ECX + 0x28),in_ECX + 0x20);
    _free(*(void **)(in_ECX + 0x24));
    return;
  }
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_006c2e00 @ 0x006c2e00 ====

void FUN_006c2e00(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 != param_2) {
    piVar1 = (int *)(param_1 + 0x24);
    iVar2 = param_1;
    do {
      if (*piVar1 != 0) {
        FUN_0068e630(*piVar1,piVar1[1],piVar1 + -1,param_1);
        _free((void *)*piVar1);
        return;
      }
      *piVar1 = 0;
      piVar1[1] = 0;
      piVar1[2] = 0;
      if (0xf < (uint)piVar1[-3]) {
        _free((void *)piVar1[-8]);
        return;
      }
      piVar1[-3] = 0xf;
      piVar1[-4] = 0;
      *(undefined1 *)(piVar1 + -8) = 0;
      iVar2 = iVar2 + 0x30;
      piVar1 = piVar1 + 0xc;
    } while (iVar2 != param_2);
  }
  return;
}


// ==== FUN_006c2e70 @ 0x006c2e70 ====

void FUN_006c2e70(undefined4 param_1,undefined4 param_2)

{
  FUN_006c2e00(param_1,param_2);
  return;
}


// ==== FUN_006c2e90 @ 0x006c2e90 ====

void FUN_006c2e90(byte param_1)

{
  void *in_ECX;
  
  FUN_006c2af0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006c2eb0 @ 0x006c2eb0 ====

void FUN_006c2eb0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) == '\0') {
    *(undefined1 *)(in_ECX + 8) = 1;
  }
  return;
}


// ==== FUN_006c2ec0 @ 0x006c2ec0 ====

uint FUN_006c2ec0(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a7b4 + 0x3c))();
  if ((char)uVar1 == '\x01') {
    uVar1 = (**(code **)(*DAT_00b5a7b4 + 0x30))();
    if ((char)uVar1 == '\x01') {
      *(undefined1 *)(in_ECX + 0x50) = 0;
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006c2ef0 @ 0x006c2ef0 ====

int FUN_006c2ef0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  
  puVar2 = (undefined4 *)**(undefined4 **)(in_ECX + 0x2c);
  while( true ) {
    if (puVar2 == *(undefined4 **)(in_ECX + 0x2c)) {
      return 0;
    }
    if (*(char *)(puVar2[4] + 0xe9) != '\0') break;
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
  return puVar2[4];
}


// ==== FUN_006c2f60 @ 0x006c2f60 ====

/* WARNING: Removing unreachable block (ram,0x006c2fa2) */

int * FUN_006c2f60(undefined4 param_1,byte *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  byte *pbVar10;
  int *extraout_EAX;
  int *extraout_EAX_00;
  int in_ECX;
  uint uVar11;
  byte *pbVar12;
  bool bVar13;
  bool bVar14;
  uint in_stack_00000018;
  uint in_stack_0000001c;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x2c);
  puVar3 = (undefined4 *)*puVar2;
  do {
    if (puVar3 == puVar2) {
      if (in_stack_0000001c < 0x10) {
        return (int *)0x0;
      }
      _free(param_2);
      return extraout_EAX;
    }
    piVar4 = (int *)puVar3[4];
    piVar8 = (int *)(**(code **)(*piVar4 + 0x3c))();
    iVar9 = (**(code **)(*piVar8 + 0x50))();
    pbVar12 = param_2;
    if (in_stack_0000001c < 0x10) {
      pbVar12 = (byte *)&param_2;
    }
    uVar5 = *(uint *)(iVar9 + 0x14);
    if (uVar5 == 0) {
LAB_006c2fd1:
      if ((in_stack_00000018 <= uVar5) && (uVar5 == in_stack_00000018)) {
        if (in_stack_0000001c < 0x10) {
          return piVar4;
        }
        _free(param_2);
        return extraout_EAX_00;
      }
    }
    else {
      uVar11 = in_stack_00000018;
      if (uVar5 < in_stack_00000018) {
        uVar11 = uVar5;
      }
      if (*(uint *)(iVar9 + 0x18) < 0x10) {
        pbVar10 = (byte *)(iVar9 + 4);
      }
      else {
        pbVar10 = *(byte **)(iVar9 + 4);
      }
      bVar13 = false;
      iVar9 = 0;
      bVar14 = true;
      do {
        if (uVar11 == 0) break;
        uVar11 = uVar11 - 1;
        bVar13 = *pbVar10 < *pbVar12;
        bVar14 = *pbVar10 == *pbVar12;
        pbVar10 = pbVar10 + 1;
        pbVar12 = pbVar12 + 1;
      } while (bVar14);
      if (!bVar14) {
        iVar9 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
      }
      if (iVar9 == 0) goto LAB_006c2fd1;
    }
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar6 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar6 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar6 + 0x15);
        puVar3 = puVar6;
        puVar6 = (undefined4 *)*puVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar6 + 0x15);
          puVar3 = puVar6;
          puVar6 = (undefined4 *)*puVar6;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar7 = (undefined4 *)puVar3[1];
        puVar6 = puVar3;
        while ((puVar3 = puVar7, cVar1 == '\0' && (puVar6 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar7 = (undefined4 *)puVar3[1];
          puVar6 = puVar3;
        }
      }
    }
  } while( true );
}


// ==== FUN_006c3070 @ 0x006c3070 ====

void FUN_006c3070(char param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  void *_Memory;
  undefined4 *puVar6;
  undefined4 uVar7;
  int in_ECX;
  
  if (param_1 != '\0') {
    puVar2 = *(undefined4 **)(in_ECX + 0x2c);
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      iVar4 = **(int **)(in_ECX + 4);
      uVar7 = (**(code **)(*(int *)puVar3[4] + 0x3c))();
      (**(code **)(iVar4 + 0x28))(uVar7);
      if (*(char *)((int)puVar3 + 0x15) == '\0') {
        puVar5 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar5 + 0x15) == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x15);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar5 + 0x15);
            puVar3 = puVar5;
            puVar5 = (undefined4 *)*puVar5;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar6 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
          while ((puVar3 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x15);
            puVar6 = (undefined4 *)puVar3[1];
            puVar5 = puVar3;
          }
        }
      }
    }
  }
  _Memory = *(void **)(*(int *)(in_ECX + 0x2c) + 4);
  if (*(char *)((int)_Memory + 0x15) == '\0') {
    FUN_006c50a0(*(undefined4 *)((int)_Memory + 8));
    _free(_Memory);
    return;
  }
  *(int *)(*(int *)(in_ECX + 0x2c) + 4) = *(int *)(in_ECX + 0x2c);
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(in_ECX + 0x2c);
  *(int *)(*(int *)(in_ECX + 0x2c) + 8) = *(int *)(in_ECX + 0x2c);
  return;
}


// ==== FUN_006c3130 @ 0x006c3130 ====

void FUN_006c3130(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
  if (piVar1 != (int *)0x0) {
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_00401740(s_combo_partyitemway_009e2b70,0x12);
    piVar1 = (int *)(**(code **)(*piVar1 + 0x4c))(auStack_1c);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    if ((piVar1 == (int *)0x0) || (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 == 0)) {
      (**(code **)(*DAT_00b5a7b4 + 0x48))();
      return;
    }
    iVar2 = FUN_00577d20();
    if ((-1 < iVar2) && (iVar2 < 0x100)) {
      return;
    }
  }
  (**(code **)(*DAT_00b5a7b4 + 0x48))();
  return;
}


// ==== FUN_006c31e0 @ 0x006c31e0 ====

/* WARNING: Removing unreachable block (ram,0x006c3263) */
/* WARNING: Removing unreachable block (ram,0x006c32d4) */

void FUN_006c31e0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 auStack_36 [26];
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  FUN_00401740(&DAT_009e2b83,0);
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_panel_partyname_009e2b84,0xf);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    iVar2 = (**(code **)(*DAT_00b5a7b4 + 0x40))();
    if (iVar2 != 0) {
      uVar3 = (**(code **)(*DAT_00b5a7b4 + 0x44))();
      FUN_00401660(uVar3,0,0xffffffff);
    }
    FUN_00401660(auStack_36 + -6,0,0xffffffff);
    FUN_00588340();
  }
  return;
}


// ==== FUN_006c32f0 @ 0x006c32f0 ====

void FUN_006c32f0(void)

{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  void *unaff_EBX;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_10;
  uint uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
  if (piVar2 != (int *)0x0) {
    uStack_4 = 0xf;
    uStack_8 = 0;
    uStack_18 = 0;
    FUN_00401740(s_combo_partyitemway_009e2b94,0x12);
    piVar2 = (int *)(**(code **)(*piVar2 + 0x4c))(&uStack_1c);
    if (0xf < uStack_8) {
      _free(uStack_1c);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    uStack_1c = (void *)((uint)uStack_1c & 0xffffff00);
    if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x30))(), iVar3 != 0)) {
      uVar1 = (**(code **)(*DAT_00b5a7b4 + 0x48))();
      FUN_00577df0(uVar1);
      FUN_00401830(s_lbl_partyitemway_009e2ba8);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x20);
      if (0xf < uStack_c) {
        _free(unaff_EBX);
        return;
      }
      uStack_c = 0xf;
      uStack_10 = 0;
      if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x30))(), iVar3 != 0)) {
        uVar4 = FUN_005778b0((int)register0x00000010 + -0x24);
        FUN_0055a260(uVar4);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
  }
  return;
}


// ==== FUN_006c3410 @ 0x006c3410 ====

undefined4 FUN_006c3410(int param_1,ushort param_2,int param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = (**(code **)(*in_ECX + 0x14))();
  if (param_1 != iVar2) {
    return 0;
  }
  if (param_3 == 1) {
    switch(param_2 - 1) {
    case 0:
      (**(code **)(*DAT_00b5a7b4 + 0x10))(param_4);
      return 1;
    case 1:
      uVar1 = FUN_006c3130();
      param_2 = CONCAT11(param_2._1_1_,uVar1);
      (**(code **)(*DAT_00b5a7b4 + 4))(param_4,&param_2);
      return 1;
    case 2:
      (**(code **)(*DAT_00b5a7b4 + 0x1c))();
      return 1;
    case 3:
      (**(code **)(*DAT_00b5a7b4 + 8))();
    }
  }
  return 1;
}


// ==== FUN_006c34b0 @ 0x006c34b0 ====

undefined4 FUN_006c34b0(undefined1 param_1)

{
  code *pcVar1;
  undefined4 extraout_EAX;
  undefined4 uVar2;
  int in_ECX;
  int local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  FUN_0079bba0(&local_20,&param_1);
  if (local_20 != *(int *)(in_ECX + 0x2c)) {
    return *(undefined4 *)(local_20 + 0x10);
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_itSlotCtrl____m_mapPcInfoSlot_en_009e2ce0,0x23);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)();
    return uVar2;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_006c3530 @ 0x006c3530 ====

int FUN_006c3530(int param_1,undefined4 param_2,char param_3)

{
  int extraout_EAX;
  int extraout_EAX_00;
  char *pcVar1;
  undefined4 uVar2;
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
  if (param_3 == '\0') {
    uVar2 = 0xd;
    pcVar1 = s_pcinfoslot__d_009e2d14;
  }
  else {
    uVar2 = 0xc;
    pcVar1 = s_emptyslot__d_009e2d04;
  }
  FUN_00401740(pcVar1,uVar2);
  uVar2 = FUN_00404230(local_1c);
  FUN_00401660(uVar2,0,0xffffffff);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_38,0,0xffffffff);
  if (local_20 < 0x10) {
    return param_1;
  }
  _free(local_34);
  return extraout_EAX_00;
}


// ==== FUN_006c35e0 @ 0x006c35e0 ====

/* WARNING: Removing unreachable block (ram,0x006c3636) */

undefined4 FUN_006c35e0(void *param_1)

{
  int *piVar1;
  undefined4 extraout_EAX;
  undefined4 uVar2;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int in_ECX;
  void *unaff_retaddr;
  uint in_stack_00000014;
  uint in_stack_00000018;
  undefined1 in_stack_0000001c;
  undefined1 local_3a [46];
  uint uStack_c;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&param_1);
  if (piVar1 == (int *)0x0) {
    if (in_stack_00000018 < 0x10) {
      return 0;
    }
    _free(param_1);
    return extraout_EAX;
  }
  uVar2 = (**(code **)(*piVar1 + 0x10))();
  FUN_004fed70(uVar2);
  uVar2 = (**(code **)(*piVar1 + 0xc))(local_3a + -6);
  in_stack_00000018 = CONCAT31(in_stack_00000018._1_3_,(char)uVar2);
  if (0xf < uStack_c) {
    _free((void *)0x0);
    return extraout_EAX_00;
  }
  if (in_stack_00000014 < 0x10) {
    return uVar2;
  }
  _free(unaff_retaddr);
  return extraout_EAX_01;
}


// ==== FUN_006c36e0 @ 0x006c36e0 ====

void FUN_006c36e0(void)

{
  code *pcVar1;
  char cVar2;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  FUN_00401740(s_btn_partyname_009e2714,0xd);
  cVar2 = FUN_006c35e0();
  if (cVar2 == '\0') {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_SetControllerVisible___btn_party_009e2724,0x2f);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_18);
    return;
  }
  FUN_00401740(s_btn_partyleadertrust_009e2754,0x14);
  cVar2 = FUN_006c35e0();
  if (cVar2 == '\0') {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_SetControllerVisible___btn_party_009e276c,0x36);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_18);
    return;
  }
  FUN_00401740(s_btn_partyunion_009e27a4,0xe);
  cVar2 = FUN_006c35e0();
  if (cVar2 == '\0') {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_SetControllerVisible___btn_party_009e27b4,0x30);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_18);
    return;
  }
  FUN_00401740(s_btn_partydisband_009e27e8,0x10);
  cVar2 = FUN_006c35e0();
  if (cVar2 == '\0') {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_SetControllerVisible___btn_party_009e27fc,0x32);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_18);
    return;
  }
  FUN_00401740(s_btn_partysecession_009e2830,0x12);
  cVar2 = FUN_006c35e0();
  if (cVar2 == '\0') {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_SetControllerVisible___btn_party_009e2844,0x34);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_18);
    return;
  }
  FUN_00401740(s_combo_partyitemway_009e287c,0x12);
  cVar2 = FUN_006c35e0();
  if (cVar2 == '\0') {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_SetControllerVisible___combo_par_009e2890,0x34);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_18);
    return;
  }
  FUN_00401740(s_lbl_partyitemway_009e28c8,0x10);
  cVar2 = FUN_006c35e0();
  if (cVar2 != '\0') {
    FUN_006c31e0();
    FUN_006c32f0();
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_SetControllerVisible___lbl_party_009e28dc,0x32);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_006c39c0 @ 0x006c39c0 ====

undefined4 FUN_006c39c0(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 extraout_EAX;
  undefined4 uVar4;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined4 extraout_EAX_05;
  undefined4 extraout_EAX_06;
  undefined1 auStack_e0 [4];
  void *pvStack_dc;
  undefined4 uStack_cc;
  uint uStack_c8;
  undefined1 auStack_c4 [4];
  void *pvStack_c0;
  undefined4 uStack_b0;
  uint uStack_ac;
  undefined1 auStack_a8 [4];
  void *pvStack_a4;
  undefined4 uStack_94;
  uint uStack_90;
  undefined1 auStack_8c [4];
  void *pvStack_88;
  undefined4 uStack_78;
  uint uStack_74;
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
  
  iVar3 = (**(code **)(*DAT_00b5a7b4 + 0x40))();
  FUN_006c36e0();
  if (iVar3 == 0) {
    FUN_00401740(s_btn_partyunion_009e2934,0xe);
    cVar2 = FUN_006c35e0();
    if (cVar2 == '\0') {
      FUN_00401830(s_SetControllerVisible___btn_party_009e2944);
      FUN_00406880(auStack_70);
      if (uStack_58 < 0x10) {
        uStack_58 = 0xf;
        uStack_5c = 0;
        pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
        pcVar1 = (code *)swi(3);
        uVar4 = (*pcVar1)();
        return uVar4;
      }
      _free(pvStack_6c);
      return extraout_EAX_05;
    }
    FUN_00401740(s_combo_partyitemway_009e2974,0x12);
    cVar2 = FUN_006c35e0();
    if (cVar2 == '\0') {
      FUN_00401830(s_SetControllerVisible___combo_par_009e2988);
      FUN_00406880(auStack_a8);
      if (uStack_90 < 0x10) {
        uStack_90 = 0xf;
        uStack_94 = 0;
        pvStack_a4 = (void *)((uint)pvStack_a4 & 0xffffff00);
        pcVar1 = (code *)swi(3);
        uVar4 = (*pcVar1)();
        return uVar4;
      }
      _free(pvStack_a4);
      return extraout_EAX_06;
    }
  }
  else if (iVar3 == 1) {
    FUN_00401740(s_btn_partyname_009e29c0,0xd);
    cVar2 = FUN_006c35e0();
    if (cVar2 == '\0') {
      FUN_00401830(s_SetControllerVisible___btn_party_009e29d0);
      FUN_00406880(auStack_38);
      if (uStack_20 < 0x10) {
        uStack_20 = 0xf;
        uStack_24 = 0;
        pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
        pcVar1 = (code *)swi(3);
        uVar4 = (*pcVar1)();
        return uVar4;
      }
      _free(pvStack_34);
      return extraout_EAX_01;
    }
    FUN_00401740(s_btn_partyleadertrust_009e2a00,0x14);
    cVar2 = FUN_006c35e0();
    if (cVar2 == '\0') {
      FUN_00401830(s_SetControllerVisible___btn_party_009e2a18);
      FUN_00406880(auStack_e0);
      if (uStack_c8 < 0x10) {
        uStack_c8 = 0xf;
        uStack_cc = 0;
        pvStack_dc = (void *)((uint)pvStack_dc & 0xffffff00);
        pcVar1 = (code *)swi(3);
        uVar4 = (*pcVar1)();
        return uVar4;
      }
      _free(pvStack_dc);
      return extraout_EAX_02;
    }
    FUN_00401740(s_btn_partydisband_009e2a50,0x10);
    cVar2 = FUN_006c35e0();
    if (cVar2 == '\0') {
      FUN_00401830(s_SetControllerVisible___btn_party_009e2a64);
      FUN_00406880(auStack_c4);
      if (uStack_ac < 0x10) {
        uStack_ac = 0xf;
        uStack_b0 = 0;
        pvStack_c0 = (void *)((uint)pvStack_c0 & 0xffffff00);
        pcVar1 = (code *)swi(3);
        uVar4 = (*pcVar1)();
        return uVar4;
      }
      _free(pvStack_c0);
      return extraout_EAX_03;
    }
    FUN_00401740(s_combo_partyitemway_009e2a98,0x12);
    cVar2 = FUN_006c35e0();
    if (cVar2 == '\0') {
      FUN_00401830(s_SetControllerVisible___combo_par_009e2aac);
      FUN_00406880(auStack_8c);
      if (uStack_74 < 0x10) {
        uStack_74 = 0xf;
        uStack_78 = 0;
        pvStack_88 = (void *)((uint)pvStack_88 & 0xffffff00);
        pcVar1 = (code *)swi(3);
        uVar4 = (*pcVar1)();
        return uVar4;
      }
      _free(pvStack_88);
      return extraout_EAX_04;
    }
  }
  else if (iVar3 == 2) {
    FUN_00401740(s_btn_partysecession_009e2ae0,0x12);
    cVar2 = FUN_006c35e0();
    if (cVar2 == '\0') {
      FUN_00401830(s_SetControllerVisible___btn_party_009e2af4);
      FUN_00406880(auStack_54);
      if (uStack_3c < 0x10) {
        uStack_3c = 0xf;
        uStack_40 = 0;
        pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
        pcVar1 = (code *)swi(3);
        uVar4 = (*pcVar1)();
        return uVar4;
      }
      _free(pvStack_50);
      return extraout_EAX;
    }
    FUN_00401740(s_lbl_partyitemway_009e2b28,0x10);
    cVar2 = FUN_006c35e0();
    if (cVar2 == '\0') {
      FUN_00401830(s_SetControllerVisible___lbl_party_009e2b3c);
      FUN_00406880(auStack_1c);
      if (uStack_4 < 0x10) {
        uStack_4 = 0xf;
        uStack_8 = 0;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
        pcVar1 = (code *)swi(3);
        uVar4 = (*pcVar1)();
        return uVar4;
      }
      _free(pvStack_18);
      return extraout_EAX_00;
    }
  }
  return 1;
}


// ==== FUN_006c3db0 @ 0x006c3db0 ====

void FUN_006c3db0(void)

{
  undefined4 *in_ECX;
  undefined1 auStack_2 [2];
  
  *in_ECX = &PTR_FUN_009e2d2c;
  FUN_006c3070(0);
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if ((uint)in_ECX[0x13] < 0x10) {
    in_ECX[0x13] = 0xf;
    in_ECX[0x12] = 0;
    *(undefined1 *)(in_ECX + 0xe) = 0;
    FUN_006c5540(auStack_2 + -6,*(undefined4 *)in_ECX[0xb],(undefined4 *)in_ECX[0xb]);
    _free((void *)in_ECX[0xb]);
    return;
  }
  _free((void *)in_ECX[0xe]);
  return;
}


// ==== FUN_006c3e50 @ 0x006c3e50 ====

undefined4 FUN_006c3e50(void)

{
  code *pcVar1;
  int *piVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  undefined4 extraout_EAX_00;
  int *piVar6;
  undefined1 auStack_4fc [4];
  void *pvStack_4f8;
  undefined4 uStack_4e8;
  uint uStack_4e4;
  int iStack_4e0;
  undefined1 auStack_4dc [4];
  undefined1 auStack_4d8 [96];
  undefined1 auStack_478 [12];
  undefined1 uStack_46c;
  undefined1 uStack_46b;
  undefined1 uStack_46a;
  undefined1 uStack_469;
  int iStack_468;
  int iStack_464;
  int iStack_460;
  undefined4 *puStack_2e0;
  undefined1 uStack_2d8;
  undefined1 uStack_2d7;
  undefined1 uStack_2d6;
  undefined1 uStack_2d5;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a7b4 + 0x58))();
  if (piVar2 != (int *)0x0) {
    iStack_4e0 = (**(code **)(*DAT_00b5a7b4 + 0x4c))();
    FUN_00505f10();
    uVar4 = 0;
    do {
      uVar4 = uVar4 + 1;
      piVar5 = (int *)FUN_006c34b0(uVar4);
      if (piVar5 == (int *)0x0) {
        uStack_4e4 = 0xf;
        uStack_4e8 = 0;
        pvStack_4f8 = (void *)((uint)pvStack_4f8 & 0xffffff00);
        FUN_00401740(s_pSlotCtrl_009e2928,9);
        FUN_00406880(auStack_4fc);
        if (uStack_4e4 < 0x10) {
          uStack_4e4 = 0xf;
          uStack_4e8 = 0;
          pvStack_4f8 = (void *)((uint)pvStack_4f8 & 0xffffff00);
          pcVar1 = (code *)swi(3);
          uVar3 = (*pcVar1)();
          return uVar3;
        }
        _free(pvStack_4f8);
        return extraout_EAX_00;
      }
      FUN_006c5210(piVar5 + 0x1f);
      FUN_00571390(piVar5 + 0x37);
      uStack_46c = (undefined1)piVar5[0x3a];
      uStack_46b = *(undefined1 *)((int)piVar5 + 0xe9);
      uStack_46a = *(undefined1 *)((int)piVar5 + 0xea);
      uStack_469 = *(undefined1 *)((int)piVar5 + 0xeb);
      FUN_00585650(auStack_4d8);
      FUN_00504490(auStack_4dc,*puStack_2e0,puStack_2e0);
      FUN_005040e0(auStack_478);
      uStack_2d8 = uStack_46c;
      uStack_2d6 = uStack_46a;
      uStack_2d7 = uStack_46b;
      uStack_2d5 = uStack_469;
      FUN_005050d0();
      if (*(char *)((int)piVar5 + 0xea) == '\0') {
        piVar6 = (int *)(**(code **)(*piVar2 + 4))();
        uStack_2d8 = *piVar6 == iStack_4e0;
        uVar3 = (**(code **)(*piVar2 + 4))();
        FUN_00585650(uVar3);
        (**(code **)(*piVar2 + 0xc))();
      }
      iStack_468 = piVar5[0x1c];
      iStack_464 = piVar5[0x1d];
      iStack_460 = piVar5[0x1e];
      (**(code **)(*piVar5 + 0x24))(&iStack_468);
    } while (uVar4 < 6);
    FUN_006c4f20(2);
    (**(code **)(*DAT_00b5a7b4 + 0x5c))(piVar2);
    FUN_00505d80();
    return 1;
  }
  uStack_4e4 = 0xf;
  uStack_4e8 = 0;
  pvStack_4f8 = (void *)((uint)pvStack_4f8 & 0xffffff00);
  FUN_00401740(s_pPartyInfo_009e291c,10);
  FUN_00406880(auStack_4fc);
  if (uStack_4e4 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  _free(pvStack_4f8);
  return extraout_EAX;
}


// ==== FUN_006c40c0 @ 0x006c40c0 ====

int * FUN_006c40c0(int param_1,int *param_2,undefined4 param_3)

{
  code *pcVar1;
  char cVar2;
  int *extraout_EAX;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int *extraout_EAX_00;
  int *extraout_EAX_01;
  int *piVar6;
  int *piVar7;
  int *extraout_EAX_02;
  int *extraout_EAX_03;
  int *extraout_EAX_04;
  int *extraout_EAX_05;
  int *extraout_EAX_06;
  int in_ECX;
  uint uVar8;
  int unaff_EBP;
  int iVar9;
  undefined4 unaff_EDI;
  undefined4 unaff_retaddr;
  undefined4 uStack_56c;
  undefined1 local_55c [4];
  void *local_558;
  undefined4 local_548;
  uint local_544 [2];
  void *local_53c;
  undefined1 auStack_534 [8];
  undefined4 local_52c;
  uint local_528;
  undefined4 uStack_518;
  void *pvStack_514;
  undefined4 uStack_510;
  undefined4 uStack_50c;
  undefined4 uStack_508;
  undefined1 auStack_504 [4];
  uint uStack_500;
  undefined1 local_4f8;
  undefined4 local_4e8;
  undefined4 local_4e4;
  int iStack_4dc;
  void *pvStack_4d8;
  int iStack_4d4;
  undefined4 uStack_4c8;
  uint uStack_4c4;
  undefined1 auStack_4ac [12];
  int iStack_4a0;
  void *pvStack_49c;
  int iStack_498;
  undefined4 uStack_48c;
  uint uStack_488;
  undefined1 auStack_47c [312];
  undefined4 ***apppuStack_344 [4];
  undefined4 uStack_334;
  uint uStack_330;
  undefined1 uStack_2ec;
  undefined1 uStack_2eb;
  undefined4 *puStack_2e8;
  undefined1 uStack_2e0;
  char cStack_2de;
  undefined4 uStack_c;
  int iStack_4;
  
  cVar2 = (char)param_3;
  local_4e4 = 0xf;
  local_4e8 = 0;
  local_4f8 = 0;
  local_528 = 0xf;
  local_52c = 0;
  local_53c = (void *)((uint)local_53c & 0xffffff00);
  uStack_56c = (uint)(uint3)uStack_56c;
  if (cVar2 == '\0') {
    if (param_2 == (int *)0x0) {
      local_544[0] = 0xf;
      local_548 = 0;
      local_558 = (void *)((uint)local_558 & 0xffffff00);
      FUN_00401740(s_i_pPcInfo_009e2bc8,9);
      FUN_00406880(local_55c);
      if (local_544[0] < 0x10) {
        pcVar1 = (code *)swi(3);
        piVar3 = (int *)(*pcVar1)();
        return piVar3;
      }
      _free(local_558);
      return extraout_EAX;
    }
    iVar4 = (**(code **)(*DAT_00b5a7b4 + 0x4c))();
    uStack_56c = CONCAT13(*param_2 == iVar4,(uint3)uStack_56c);
  }
  uVar5 = FUN_006c3530(local_55c,param_1 + 1,param_3);
  FUN_00401660(uVar5,0,0xffffffff);
  if (0xf < local_544[0]) {
    _free(local_558);
    return extraout_EAX_00;
  }
  uVar5 = FUN_006c3530(local_55c,0,param_3);
  FUN_00401660(uVar5,0,0xffffffff);
  if (0xf < local_544[0]) {
    _free(local_558);
    return extraout_EAX_01;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  piVar6 = (int *)(**(code **)(*DAT_00b5a7ac + 8))(7);
  piVar7 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_544);
  uVar5 = (**(code **)(*piVar7 + 0x10))();
  FUN_005041e0(uVar5);
  FUN_005041e0(auStack_4ac);
  iVar4 = (**(code **)(*piVar7 + 0x30))();
  uVar8 = iStack_498 - iStack_4a0 >> 0x1f;
  uStack_56c = iStack_4a0;
  iVar9 = (iStack_498 - iStack_4a0 ^ uVar8) - uVar8;
  local_4e8 = CONCAT22(local_4e8._2_2_,0x101);
  FUN_00401660(auStack_504,0,0xffffffff);
  iStack_4dc = iVar9 * iStack_4 + uStack_56c;
  iStack_4d4 = iStack_4dc + iVar9;
  FUN_00505f10();
  FUN_0056a7b0();
  uStack_2e0 = (undefined1)((uint)unaff_EBP >> 0x18);
  cStack_2de = cVar2;
  if (cVar2 == '\0') {
    FUN_00585650(unaff_retaddr);
  }
  if (&uStack_2ec != (undefined1 *)(iVar4 + 0xdc)) {
    FUN_00504490(&uStack_56c,*puStack_2e8,puStack_2e8);
    FUN_005040e0((undefined1 *)(iVar4 + 0xdc));
  }
  pvStack_514 = (void *)0xf;
  uStack_518 = 0;
  local_528 = local_528 & 0xffffff00;
  uStack_510 = 0;
  uStack_50c = 0;
  uStack_508 = 0;
  FUN_00401660(auStack_504,0,0xffffffff);
  (**(code **)(*piVar3 + 8))(&local_4e8);
  (**(code **)(*piVar6 + 0x38))(piVar3);
  (**(code **)(*piVar6 + 0x1c))(auStack_534);
  if (cVar2 == '\0') {
    FUN_005851f0(unaff_EDI,uStack_c);
  }
  if (uStack_330 < 0x10) {
    apppuStack_344[0] = apppuStack_344;
  }
  iVar4 = FUN_00403620(0,*(undefined4 *)(unaff_EBP + 0x48),apppuStack_344[0],uStack_334);
  if (iVar4 == 0) {
    uStack_2eb = 1;
  }
  (**(code **)(*piVar6 + 0x24))(auStack_47c);
  (**(code **)(*piVar3 + 0x2c))(piVar6);
  piVar7 = (int *)(**(code **)(**(int **)(unaff_EBP + 4) + 0x2c))();
  if (piVar7 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar3 + 0x74))(piVar7);
    if (cVar2 != '\0') {
      cVar2 = (**(code **)(*piVar7 + 0x78))(piVar3);
      if (cVar2 == '\0') {
        (**(code **)(*piVar3 + 0x74))(0);
      }
      else {
        iVar4 = (**(code **)(*piVar7 + 0x38))();
        piVar3[1] = iVar4;
      }
    }
  }
  if (0xf < local_528) {
    _free(local_53c);
    return extraout_EAX_02;
  }
  local_528 = 0xf;
  local_52c = 0;
  local_53c = (void *)((uint)local_53c & 0xffffff00);
  FUN_00505d80();
  if (0xf < uStack_4c4) {
    _free(pvStack_4d8);
    return extraout_EAX_03;
  }
  uStack_4c4 = 0xf;
  uStack_4c8 = 0;
  pvStack_4d8 = (void *)((uint)pvStack_4d8 & 0xffffff00);
  if (0xf < uStack_488) {
    _free(pvStack_49c);
    return extraout_EAX_04;
  }
  uStack_488 = 0xf;
  uStack_48c = 0;
  pvStack_49c = (void *)((uint)pvStack_49c & 0xffffff00);
  if (0xf < local_544[0]) {
    _free(local_558);
    return extraout_EAX_05;
  }
  local_544[0] = 0xf;
  local_548 = 0;
  local_558 = (void *)((uint)local_558 & 0xffffff00);
  if (uStack_500 < 0x10) {
    return piVar6;
  }
  _free(pvStack_514);
  return extraout_EAX_06;
}


// ==== FUN_006c4500 @ 0x006c4500 ====

void FUN_006c4500(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  code *pcVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  int in_ECX;
  int iVar10;
  undefined1 local_4f8 [4];
  void *local_4f4;
  undefined4 local_4e4;
  uint local_4e0;
  undefined1 local_4dc [4];
  undefined1 local_4d8 [96];
  undefined1 local_478 [12];
  undefined1 local_46c;
  undefined1 local_46b;
  undefined1 local_46a;
  undefined1 local_469;
  undefined1 local_468 [308];
  undefined1 auStack_334 [84];
  undefined4 *local_2e0;
  undefined1 local_2d8;
  undefined1 local_2d7;
  undefined1 local_2d6;
  undefined1 local_2d5;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x2c);
  puVar3 = (undefined4 *)*puVar2;
  FUN_00505f10();
  while( true ) {
    if (puVar3 == puVar2) {
      FUN_00505d80();
      return;
    }
    piVar4 = (int *)puVar3[4];
    if (piVar4 == (int *)0x0) break;
    FUN_006c5210(piVar4 + 0x1f);
    FUN_00571390(piVar4 + 0x37);
    local_46c = (undefined1)piVar4[0x3a];
    local_46b = *(undefined1 *)((int)piVar4 + 0xe9);
    local_46a = *(undefined1 *)((int)piVar4 + 0xea);
    local_469 = *(undefined1 *)((int)piVar4 + 0xeb);
    FUN_00585650(local_4d8);
    FUN_00504490(local_4dc,*local_2e0,local_2e0);
    FUN_005040e0(local_478);
    local_2d8 = local_46c;
    local_2d5 = local_469;
    local_2d7 = local_46b;
    local_2d6 = local_46a;
    FUN_005050d0();
    local_2d7 = 0;
    piVar8 = (int *)(**(code **)(*piVar4 + 0x3c))();
    iVar9 = (**(code **)(*piVar8 + 0x50))();
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      iVar10 = param_1 + 4;
    }
    else {
      iVar10 = *(int *)(param_1 + 4);
    }
    iVar9 = FUN_00403620(0,*(undefined4 *)(iVar9 + 0x14),iVar10,*(undefined4 *)(param_1 + 0x14));
    if (iVar9 == 0) {
      local_2d7 = 1;
      FUN_00401660(auStack_334,0,0xffffffff);
    }
    (**(code **)(*piVar4 + 0x24))(local_468);
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar5 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar5 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x15);
        puVar3 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x15);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar7 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar7, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar7 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  local_4e0 = 0xf;
  local_4e4 = 0;
  local_4f4 = (void *)((uint)local_4f4 & 0xffffff00);
  FUN_00401740(s_FALSE_009e2cd8,5);
  FUN_00406880(local_4f8);
  if (local_4e0 < 0x10) {
    local_4e0 = 0xf;
    local_4e4 = 0;
    local_4f4 = (void *)((uint)local_4f4 & 0xffffff00);
    pcVar6 = (code *)swi(3);
    (*pcVar6)();
    return;
  }
  _free(local_4f4);
  return;
}


// ==== FUN_006c4730 @ 0x006c4730 ====

void FUN_006c4730(int *param_1)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [8];
  undefined1 local_24 [4];
  void *local_20;
  undefined4 local_10;
  uint local_c;
  
  uVar5 = 0;
  if (param_1 != (int *)0x0) {
    do {
      uVar3 = (**(code **)(*param_1 + 0x10))();
      uVar1 = uVar5 + 1;
      if (uVar5 < uVar3) {
        uVar6 = 0;
        uStack_3c = uVar1;
        uVar4 = (**(code **)(*param_1 + 4))(0);
        uStack_38 = FUN_006c40c0(uVar5,uVar4,uVar6);
        FUN_006c5480(auStack_2c,&uStack_3c);
        (**(code **)(*param_1 + 0xc))();
      }
      else {
        uStack_34 = uVar1;
        uStack_30 = FUN_006c40c0(uVar5,0,1);
        FUN_006c5480(auStack_2c,&uStack_34);
      }
      uVar5 = uVar1;
    } while (uVar1 < 6);
    return;
  }
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(s_pPartyInfo_009e2bbc,10);
  FUN_00406880(local_24);
  if (local_c < 0x10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _free(local_20);
  return;
}


// ==== FUN_006c4820 @ 0x006c4820 ====

undefined4 FUN_006c4820(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  void *pvVar7;
  int in_ECX;
  undefined1 local_1c [2];
  undefined1 auStack_1a [26];
  
  if (param_1 != 7) {
    if (param_1 == 0x15) {
      if ((param_3 == 1) &&
         (cVar2 = FUN_004036a0(param_2,s_combo_partyitemway_009e2be0), cVar2 != '\0')) {
        iVar3 = (**(code **)(*DAT_00b5a7b4 + 0x40))();
        if (iVar3 == 1) {
          (**(code **)(*DAT_00b5a7b4 + 0x18))(param_4);
          return 1;
        }
        return 1;
      }
    }
    else if ((param_1 == 1) && (param_3 == 1)) {
      cVar2 = FUN_004036a0(param_2,s_btn_exit_009e2bf4);
      if (cVar2 != '\0') {
        cVar2 = (**(code **)(*DAT_00b5a7b4 + 0x3c))();
        if (cVar2 != '\0') {
          (**(code **)(*DAT_00b5a7b4 + 0x30))();
          *(undefined1 *)(in_ECX + 0x50) = 0;
        }
        return 1;
      }
      cVar2 = FUN_004036a0(param_2,s_btn_partyleadertrust_009e2c00);
      if (cVar2 != '\0') {
        cVar2 = FUN_006c5080();
        if (cVar2 == '\0') {
          return 1;
        }
        piVar6 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
        piVar6 = (int *)(**(code **)(*piVar6 + 0x2c))();
        iVar3 = (**(code **)(*piVar6 + 0x10))();
        if (*(char *)(iVar3 + 0xee0) != '\0') {
          uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x7d40015);
          FUN_00765c50(uVar4);
          iVar3 = *DAT_00b5ad0c;
          FUN_00765c50(local_1c + -8);
          (**(code **)(iVar3 + 0x28))(2);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        iVar3 = FUN_006c2ef0();
        if (((iVar3 != 0) && (*(char *)(iVar3 + 0xea) == '\0')) &&
           (iVar1 = *(int *)(iVar3 + 0x7c), iVar5 = (**(code **)(*DAT_00b5a7b4 + 0x54))(),
           iVar1 != iVar5)) {
          (**(code **)(*DAT_00b5a7b4 + 0x14))(*(undefined4 *)(iVar3 + 0x7c));
          return 1;
        }
        pvVar7 = operator_new(0x58);
        if (pvVar7 != (void *)0x0) {
          FUN_00505380();
        }
        FUN_00401830(s_ui_partyleadertrust_txt_009e2c18);
        FUN_00401660(local_1c,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar2 = FUN_004036a0(param_2,s_btn_partyunion_009e2c30);
      if (cVar2 != '\0') {
        pvVar7 = operator_new(0x58);
        if (pvVar7 != (void *)0x0) {
          FUN_00505380();
        }
        FUN_00401830(s_ui_partyunion_txt_009e2c40);
        FUN_00401660(local_1c,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar2 = FUN_004036a0(param_2,s_btn_partydisband_009e2c54);
      if (cVar2 == '\0') {
        cVar2 = FUN_004036a0(param_2,s_btn_partysecession_009e2c7c);
        if (cVar2 != '\0') {
          cVar2 = (**(code **)(*DAT_00b5ada8 + 0x5c))();
          if (cVar2 != '\0') {
            (**(code **)(*DAT_00b5a7b4 + 8))();
            return 1;
          }
          pvVar7 = operator_new(0x58);
          if (pvVar7 != (void *)0x0) {
            FUN_00505380();
          }
          FUN_00401830(s_ui_partysecession_txt_009e2c90);
          FUN_00401660(local_1c,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar2 = FUN_004036a0(param_2,s_btn_partyname_009e2ca8);
        if (cVar2 == '\0') {
          cVar2 = FUN_004036a0(param_2,s_tab_guild_009e2ccc);
          if (cVar2 == '\0') {
            return 0;
          }
          (**(code **)(*DAT_00b5a7b4 + 0x30))();
          (**(code **)(*DAT_00b5aca8 + 0x34))();
          return 1;
        }
        cVar2 = FUN_006c5080();
        if (cVar2 == '\0') {
          return 1;
        }
        pvVar7 = operator_new(0x58);
        if (pvVar7 != (void *)0x0) {
          FUN_00505380();
        }
        FUN_00401830(s_ui_partyname_txt_009e2cb8);
        FUN_00401660(local_1c,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar2 = FUN_006c5080();
      if (cVar2 == '\0') {
        return 1;
      }
      piVar6 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
      piVar6 = (int *)(**(code **)(*piVar6 + 0x2c))();
      cVar2 = (**(code **)(*piVar6 + 0x20))();
      if (cVar2 != '\0') {
        uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x7d40016);
        FUN_00765c50(uVar4);
        iVar3 = *DAT_00b5ad0c;
        FUN_00765c50(local_1c + -8);
        (**(code **)(iVar3 + 0x28))(2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar2 = (**(code **)(*DAT_00b5ada8 + 0x5c))();
      if (cVar2 != '\0') {
        uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(9,0x64006d);
        FUN_00765c50(uVar4);
        iVar3 = *DAT_00b5ad0c;
        FUN_00765c50(local_1c + -8);
        (**(code **)(iVar3 + 0x28))(2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      pvVar7 = operator_new(0x58);
      if (pvVar7 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_ui_partydisband_txt_009e2c68);
      FUN_00401660(local_1c,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    return 0;
  }
  if (param_3 != 1) {
    return 0;
  }
  if (param_4 != 5) {
LAB_006c494a:
    FUN_006c4500(param_2);
    return 1;
  }
  iVar3 = (**(code **)(*DAT_00b5a7b4 + 0x40))();
  if (iVar3 == 1) {
    iVar3 = *DAT_00b5add0;
    uVar4 = (**(code **)(*DAT_00b5ac1c + 0x38))();
    cVar2 = (**(code **)(iVar3 + 0x44))(uVar4);
    if (cVar2 == '\0') {
      cVar2 = (**(code **)(*DAT_00b5ada8 + 0x5c))();
      if (cVar2 != '\0') {
        uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x46002f);
        FUN_00765c50(uVar4);
        iVar3 = *DAT_00b5ad0c;
        FUN_00765c50(local_1c + -8);
        (**(code **)(iVar3 + 0x28))(2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      FUN_00765c50(param_2);
      iVar3 = FUN_006c2f60();
      if (iVar3 == 0) {
        FUN_00401830(s_pSlotCtrl_009e2bd4);
        FUN_00406880(local_1c);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      if ((*(char *)(iVar3 + 0xea) == '\0') &&
         (iVar1 = *(int *)(iVar3 + 0x7c), iVar5 = (**(code **)(*DAT_00b5a7b4 + 0x54))(),
         iVar1 != iVar5)) {
        (**(code **)(*DAT_00b5a7b4 + 0xc))(*(undefined4 *)(iVar3 + 0x7c));
      }
      goto LAB_006c494a;
    }
  }
  return 1;
}


// ==== FUN_006c48e3 @ 0x006c48e3 ====

undefined4 FUN_006c48e3(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_EBP;
  undefined1 uStack00000010;
  
  FUN_00765c50(unaff_EBP);
  iVar2 = FUN_006c2f60();
  if (iVar2 == 0) {
    FUN_00401830(s_pSlotCtrl_009e2bd4);
    FUN_00406880(&uStack00000010);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  if (*(char *)(iVar2 + 0xea) == '\0') {
    iVar1 = *(int *)(iVar2 + 0x7c);
    iVar3 = (**(code **)(*DAT_00b5a7b4 + 0x54))();
    if (iVar1 != iVar3) {
      (**(code **)(*DAT_00b5a7b4 + 0xc))(*(undefined4 *)(iVar2 + 0x7c));
    }
  }
  FUN_006c4500(unaff_EBP);
  return 1;
}


// ==== FUN_006c4e90 @ 0x006c4e90 ====

undefined4 FUN_006c4e90(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar2 = (**(code **)(*DAT_00b5a7b4 + 0x58))();
  if (iVar2 != 0) {
    FUN_006c3070(1);
    FUN_006c4730(iVar2);
    FUN_006c39c0();
    (**(code **)(*DAT_00b5a7b4 + 0x5c))(iVar2);
    return 1;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_pPartyInfo_009e2910,10);
  FUN_00406880(auStack_1c);
  if (uStack_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  _free(pvStack_18);
  return extraout_EAX;
}


// ==== FUN_006c4f20 @ 0x006c4f20 ====

void FUN_006c4f20(int param_1)

{
  if (param_1 == 0) {
    FUN_006c4e90();
  }
  else {
    if (param_1 == 1) {
      FUN_006c3e50();
      return;
    }
    if (param_1 == 2) {
      FUN_006c39c0();
      return;
    }
  }
  return;
}


// ==== FUN_006c4f50 @ 0x006c4f50 ====

uint FUN_006c4f50(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70010004) {
    uVar2 = FUN_006c4e90();
  }
  else {
    uVar2 = iVar1 + 0x8ffefffb;
    if (uVar2 == 0) {
      uVar2 = FUN_006c3e50();
      return uVar2 & 0xffffff00;
    }
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_006c4f90 @ 0x006c4f90 ====

void FUN_006c4f90(void)

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
  FUN_00401740(s_UI_Game2_ui_partyinfo_txt_009e26f8,0x19);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_00401740(&DAT_009e2712,0);
    FUN_006c4e90();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_006c5020 @ 0x006c5020 ====

void FUN_006c5020(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e2d2c;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  iVar1 = FUN_006c5170();
  in_ECX[0xb] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[0xb] + 4) = in_ECX[0xb];
  *(undefined4 *)in_ECX[0xb] = in_ECX[0xb];
  *(undefined4 *)(in_ECX[0xb] + 8) = in_ECX[0xb];
  in_ECX[0xc] = 0;
  in_ECX[0x13] = 0xf;
  in_ECX[0x12] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  *(undefined1 *)(in_ECX + 0x14) = 1;
  in_ECX[1] = 0;
  FUN_006c4f90();
  return;
}


// ==== FUN_006c5080 @ 0x006c5080 ====

bool FUN_006c5080(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5a7b4 + 0x40))();
  return iVar1 == 1;
}


// ==== FUN_006c50a0 @ 0x006c50a0 ====

void FUN_006c50a0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_006c50a0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_006c50e0 @ 0x006c50e0 ====

void * FUN_006c50e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c870;
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


// ==== Catch@006c5155 @ 0x006c5155 ====

void Catch_006c5155(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_006c5170 @ 0x006c5170 ====

void FUN_006c5170(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c880;
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


// ==== Catch@006c51fa @ 0x006c51fa ====

void Catch_006c51fa(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_006c5210 @ 0x006c5210 ====

void FUN_006c5210(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  FUN_00401660(param_1 + 4,0,0xffffffff);
  in_ECX[0x11] = 0xf;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  FUN_00401660(param_1 + 0xb,0,0xffffffff);
  in_ECX[0x12] = param_1[0x12];
  *(undefined1 *)(in_ECX + 0x13) = *(undefined1 *)(param_1 + 0x13);
  in_ECX[0x14] = param_1[0x14];
  in_ECX[0x15] = param_1[0x15];
  in_ECX[0x16] = param_1[0x16];
  in_ECX[0x17] = param_1[0x17];
  return;
}


// ==== FUN_006c52a0 @ 0x006c52a0 ====

void FUN_006c52a0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_006c50e0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_006c53a5:
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
      if ((char)piVar6[5] == '\0') goto LAB_006c53a5;
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


// ==== FUN_006c5480 @ 0x006c5480 ====

void FUN_006c5480(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_006c52a0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_006c52a0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_006c5540 @ 0x006c5540 ====

void FUN_006c5540(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_006c50a0(piVar6[1]);
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


// ==== FUN_006c5600 @ 0x006c5600 ====

undefined1 FUN_006c5600(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x50);
}


// ==== FUN_006c5610 @ 0x006c5610 ====

void FUN_006c5610(byte param_1)

{
  void *in_ECX;
  
  FUN_006c3db0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006c5630 @ 0x006c5630 ====

void FUN_006c5630(undefined1 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_24 [3];
  undefined1 uStack_18;
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  puVar3 = auStack_24;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  uStack_18 = param_1;
  (**(code **)(**(int **)(in_ECX + 4) + 0x18))(auStack_24);
  return;
}


// ==== FUN_006c5670 @ 0x006c5670 ====

void FUN_006c5670(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 local_10;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar1 = operator_new(0x18);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  puVar1[1] = 1;
  puVar1[2] = local_10;
  puVar1[3] = param_1;
  puVar1[4] = local_8;
  *puVar1 = &PTR_FUN_009b62fc;
  puVar1[5] = local_4;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_006c56e0 @ 0x006c56e0 ====

void FUN_006c56e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e2f10;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if ((uint)in_ECX[10] < 0x10) {
    in_ECX[10] = 0xf;
    in_ECX[9] = 0;
    *(undefined1 *)(in_ECX + 5) = 0;
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_006c5730 @ 0x006c5730 ====

void FUN_006c5730(void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 uStack_20;
  uint uStack_c;
  
  uStack_20 = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
    FUN_00582bc0(&uStack_20);
    iVar2 = (**(code **)(*DAT_00b5a7b8 + 0x4c))(&uStack_20);
    if (iVar2 == 0) {
      if (0xf < uStack_c) {
        _free(uStack_20);
        return;
      }
    }
    else {
      if (*(int *)(iVar2 + 4) == 0) {
        uVar3 = (**(code **)(*DAT_00b5acd8 + 0x10))((int)register0x00000010 + -0x24);
        *(undefined4 *)(iVar2 + 4) = uVar3;
      }
      puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        *puVar4 = &PTR_FUN_009b62d4;
      }
      puVar4[1] = *(undefined4 *)(iVar2 + 4);
      FUN_00797a20(puVar4);
      if (0xf < uStack_c) {
        _free(uStack_20);
        return;
      }
    }
  }
  return;
}


// ==== FUN_006c57f0 @ 0x006c57f0 ====

void FUN_006c57f0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *unaff_EDI;
  undefined4 uStack_24;
  uint uStack_c;
  
  uStack_24 = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
    FUN_00582bc0((int)register0x00000010 + -0x20);
    iVar2 = (**(code **)(*DAT_00b5a7b8 + 0x4c))((int)register0x00000010 + -0x20);
    if (iVar2 == 0) {
      if (0xf < uStack_c) {
        _free(unaff_EDI);
        return;
      }
    }
    else {
      if (*(int *)(iVar2 + 4) == 0) {
        uVar3 = (**(code **)(*DAT_00b5acd8 + 0x10))(&uStack_24);
        *(undefined4 *)(iVar2 + 4) = uVar3;
      }
      FUN_006c5670(*(undefined4 *)(iVar2 + 4));
      if (0xf < uStack_c) {
        _free(unaff_EDI);
        return;
      }
    }
  }
  return;
}


// ==== FUN_006c58f0 @ 0x006c58f0 ====

undefined4 FUN_006c58f0(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  undefined4 uVar7;
  int *piVar8;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  char *pcVar9;
  uint uVar10;
  void *apvStack_38 [4];
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a7b4 + 0x58))();
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5ac1c + 0x14))();
  iVar4 = (**(code **)(*piVar2 + 4))();
  do {
    if (iVar4 == 0) {
      (**(code **)(*DAT_00b5a7b4 + 0x5c))(piVar2);
      return 1;
    }
    piVar5 = (int *)(**(code **)(*piVar2 + 4))();
    if (piVar5 != (int *)0x0) {
      pcVar6 = (char *)(**(code **)(*piVar3 + 0x70))();
      pcVar9 = pcVar6;
      do {
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      iVar4 = FUN_00403620(0,piVar5[9],pcVar6,(int)pcVar9 - (int)(pcVar6 + 1));
      if (iVar4 != 0) {
        FUN_00401740(s_state_d_009e2dd4,7);
        uVar7 = FUN_00404230(apvStack_38);
        piVar8 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar7);
        if (0xf < uStack_24) {
          _free(apvStack_38[0]);
          return extraout_EAX;
        }
        uStack_24 = 0xf;
        uStack_28 = 0;
        apvStack_38[0] = (void *)((uint)apvStack_38[0] & 0xffffff00);
        (**(code **)(*piVar8 + 0x30))();
        iVar4 = (**(code **)(*DAT_00b5a7b4 + 0x4c))();
        uVar10 = (uint)(iVar4 == *piVar5);
        FUN_00401740(s_LV__d__s_009e2ddc,9);
        uVar7 = FUN_00404230(auStack_1c);
        FUN_00582ad0(uVar7,uVar10);
        if (0xf < uStack_4) {
          _free(pvStack_18);
          return extraout_EAX_00;
        }
        uStack_4 = 0xf;
        uStack_8 = 0;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
        FUN_00582f10((float)piVar5[0x12] * DAT_0099de78);
      }
    }
    (**(code **)(*piVar2 + 0xc))();
    iVar4 = (**(code **)(*piVar2 + 4))();
  } while( true );
}


// ==== FUN_006c5ad0 @ 0x006c5ad0 ====

void FUN_006c5ad0(undefined4 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  uint uVar3;
  undefined1 local_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  uVar3 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      FUN_00401740(s_state_d_009e2ec8,7);
      uVar1 = FUN_00404230(local_1c);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar1);
      if (0xf < uStack_4) {
        _free(pvStack_18);
      }
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x24))(param_1);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_ECX + 0xc));
  }
  return;
}


// ==== FUN_006c5b60 @ 0x006c5b60 ====

void FUN_006c5b60(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a7b4 + 0x58))();
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x10))();
    uVar4 = 0;
    if (iVar2 != 1) {
      do {
        FUN_00401740(s_state_d_009e2ee0,7);
        FUN_00404230(auStack_1c);
        piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1c);
        if ((piVar1 != (int *)0x0) && (iVar3 = (**(code **)(*piVar1 + 0x30))(), iVar3 != 0)) {
          if (*(uint *)(param_1 + 0x18) < 0x10) {
            iVar3 = param_1 + 4;
          }
          else {
            iVar3 = *(int *)(param_1 + 4);
          }
          iVar3 = FUN_00403620(0,uStack_8,iVar3,*(undefined4 *)(param_1 + 0x14));
          FUN_00582d70(iVar3 == 0);
        }
        if (0xf < uStack_4) {
          _free(pvStack_18);
          return;
        }
        uVar4 = uVar4 + 1;
        uStack_4 = 0xf;
        uStack_8 = 0;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      } while (uVar4 < iVar2 - 1U);
    }
  }
  return;
}


// ==== FUN_006c5c60 @ 0x006c5c60 ====

void FUN_006c5c60(int param_1)

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
  
  *(bool *)(in_ECX + 0x34) = param_1 != 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_btn_state_plus_009e2ee8,0xe);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  (**(code **)(*piVar1 + 0x24))(*(char *)(in_ECX + 0x34) == '\0');
  uStack_c = 0xf;
  uStack_10 = 0;
  FUN_00401740(s_btn_state_minus_009e2ef8,0xf);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x24);
  if (uStack_10 < 0x10) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    (**(code **)(*piVar1 + 0x24))(*(undefined1 *)(in_ECX + 0x34));
    return;
  }
  _free(unaff_EBP);
  return;
}


// ==== FUN_006c5d40 @ 0x006c5d40 ====

void FUN_006c5d40(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  void *unaff_EDI;
  undefined1 auStack_70 [4];
  undefined1 local_58 [4];
  void *local_54;
  uint uStack_50;
  undefined4 uStack_4c;
  undefined4 local_44;
  uint local_40;
  int iStack_38;
  void *pvStack_28;
  uint uStack_14;
  
  local_40 = 0xf;
  local_44 = 0;
  local_54 = (void *)((uint)local_54 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_partystate_txt_009e2d98,0x1a);
  iVar1 = FUN_00410500(local_58);
  if (0xf < local_40) {
    _free(local_54);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  uStack_4c = 0xf;
  uStack_50 = 0;
  FUN_00401740(s_state0_009e2db4,6);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_70 + 0xc);
  if (0xf < uStack_50) {
    _free(unaff_EDI);
    return;
  }
  uStack_50 = 0xf;
  local_54 = (void *)0x0;
  uVar3 = (**(code **)(*piVar2 + 0x10))();
  FUN_005041e0(uVar3);
  *(uint *)(in_ECX + 0x2c) = iStack_38 - local_40;
  iVar1 = (**(code **)(*piVar2 + 0x30))();
  *(uint *)(in_ECX + 0x30) = (uint)*(byte *)(iVar1 + 0x7d);
  if (uStack_14 < 0x10) {
    return;
  }
  _free(pvStack_28);
  return;
}


// ==== FUN_006c5e40 @ 0x006c5e40 ====

void FUN_006c5e40(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  int unaff_EBX;
  int iVar4;
  uint local_a4;
  int iStack_a0;
  undefined1 local_9c [4];
  void *local_98;
  undefined1 local_94;
  undefined4 uStack_88;
  uint local_84;
  int local_80;
  undefined1 local_76;
  undefined4 local_74;
  int local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  void *pvStack_58;
  undefined1 local_54;
  uint local_44;
  undefined4 local_40 [3];
  int iStack_34;
  int iStack_2c;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  local_76 = 1;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_40[0] = 0xf;
  local_44 = 0;
  local_54 = 0;
  local_80 = 0xf;
  local_84 = 0;
  local_94 = 0;
  FUN_00401740(s_state0_009e2ed0,6);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_98);
  if (0xf < local_84) {
    _free(local_98);
    return;
  }
  local_84 = 0xf;
  uStack_88 = 0;
  local_98 = (void *)((uint)local_98 & 0xffffff00);
  uVar3 = (**(code **)(*piVar2 + 0x10))();
  FUN_004fed70(uVar3);
  local_a4 = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    iVar4 = 0;
    while( true ) {
      FUN_00401740(s_state_d_009e2ed8,7);
      uVar3 = FUN_00404230(local_9c);
      local_80 = local_70 + iVar4;
      iVar1 = local_70 + iVar4;
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar3);
      if (piVar2 != (int *)0x0) {
        uVar3 = (**(code **)(*piVar2 + 0x10))();
        FUN_005041e0(uVar3);
        iStack_34 = local_80;
        iStack_2c = iVar1 + unaff_EBX;
        (**(code **)(*piVar2 + 0xc))(local_40);
        if (0xf < uStack_8) {
          _free(pvStack_1c);
          return;
        }
        uStack_8 = 0xf;
        uStack_c = 0;
        pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      }
      if (0xf < local_84) {
        _free(local_98);
        return;
      }
      iVar4 = iVar4 + unaff_EBX;
      local_a4 = local_a4 + 1;
      local_84 = 0xf;
      uStack_88 = 0;
      local_98 = (void *)((uint)local_98 & 0xffffff00);
      if (*(uint *)(iStack_a0 + 0xc) <= local_a4) break;
      in_ECX = iStack_a0;
    }
  }
  if (local_44 < 0x10) {
    return;
  }
  _free(pvStack_58);
  return;
}


// ==== FUN_006c6020 @ 0x006c6020 ====

void FUN_006c6020(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e2f10;
  in_ECX[3] = 0;
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 0xd) = 0;
  FUN_006c5d40();
  return;
}


// ==== FUN_006c6050 @ 0x006c6050 ====

undefined4 FUN_006c6050(int param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  void *unaff_EDI;
  undefined4 local_1c;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_state_plus_009e2e18,0xe);
      if (iVar2 == 0) {
        FUN_00401830(s_btn_state_plus_009e2e28);
        piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
        if (0xf < uStack_8) {
          _free(local_1c);
          return extraout_EAX;
        }
        uStack_8 = 0xf;
        uStack_c = 0;
        local_1c = (void *)((uint)local_1c & 0xffffff00);
        (**(code **)(*piVar3 + 0x24))(0);
        FUN_00401830(s_btn_state_minus_009e2e38);
        piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))
                                  ((int)register0x00000010 + -0x24);
        if (0xf < uStack_10) {
          _free(unaff_EDI);
          return extraout_EAX_00;
        }
        uStack_10 = 0xf;
        uStack_14 = 0;
        (**(code **)(*piVar3 + 0x24))(1);
        *(undefined1 *)(in_ECX + 0x34) = 1;
        FUN_006c5e40();
      }
      else {
        cVar1 = FUN_004036a0(param_2,s_btn_state_minus_009e2e48);
        if (cVar1 != '\0') {
          FUN_00401830(s_btn_state_plus_009e2e58);
          (**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar1 = FUN_004036a0(param_2,s_btn_state_hide_009e2e78);
        if (cVar1 != '\0') {
          FUN_00401830(s_state_menu_009e2e88);
          (**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar1 = FUN_004036a0(param_2,s_btn_state_show_009e2ea0);
        if (cVar1 != '\0') {
          FUN_00401830(s_state_menu_009e2eb0);
          (**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
      }
    }
  }
  else if (param_1 == 9) {
    if (param_3 == 1) {
      if (param_4 == 100) {
        FUN_006c5b60(param_2);
        FUN_006c5730(param_2);
        return 1;
      }
      FUN_006c57f0(param_2);
    }
    return 1;
  }
  return 0;
}


// ==== FUN_006c6310 @ 0x006c6310 ====

void FUN_006c6310(uint param_1)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  void *pvVar7;
  undefined4 *puVar8;
  int in_ECX;
  int *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  int local_b8;
  int aiStack_b4 [6];
  void *local_9c;
  undefined1 local_98;
  undefined1 auStack_90 [4];
  undefined4 uStack_8c;
  uint local_88;
  uint local_84;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 auStack_60 [12];
  int iStack_54;
  int iStack_4c;
  undefined1 auStack_40 [28];
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  
  if (param_1 < *(uint *)(in_ECX + 0xc)) {
    local_b8 = *(uint *)(in_ECX + 0xc) - param_1;
    do {
      FUN_00401740(s_state_d_009e2dbc,7);
      uVar2 = FUN_00404230(&local_9c);
      uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar2);
      if (0xf < local_88) {
        _free(local_9c);
        return;
      }
      local_88 = 0xf;
      uStack_8c = 0;
      local_9c = (void *)((uint)local_9c & 0xffffff00);
      (**(code **)(**(int **)(in_ECX + 4) + 0x28))(uVar2);
      local_b8 = local_b8 + -1;
    } while (local_b8 != 0);
    *(uint *)(in_ECX + 0xc) = param_1;
    return;
  }
  local_84 = 0xf;
  local_88 = 0;
  local_98 = 0;
  FUN_00401740(s_state0_009e2dc4,6);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_9c);
  if (0xf < local_88) {
    _free(local_9c);
    return;
  }
  local_88 = 0xf;
  uStack_8c = 0;
  local_9c = (void *)((uint)local_9c & 0xffffff00);
  (**(code **)(*piVar3 + 0x20))();
  if (param_1 <= *(uint *)(in_ECX + 0xc)) {
    *(uint *)(in_ECX + 0xc) = param_1;
    return;
  }
  piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  (**(code **)(*piVar3 + 0x30))();
  piVar5 = (int *)(**(code **)(*DAT_00b5a7ac + 8))(9);
  uVar2 = (**(code **)(*piVar3 + 0x10))();
  FUN_005041e0(uVar2);
  uStack_70 = 0xf;
  uStack_74 = 0;
  local_84 = local_84 & 0xffffff00;
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  FUN_00401740(s_state_d_009e2dcc,7);
  uVar2 = FUN_00404230(auStack_24);
  FUN_00401660(uVar2,0,0xffffffff);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  FUN_00401660(auStack_40,0,0xffffffff);
  iStack_54 = iStack_54 + *(int *)(unaff_EBP + 0x2c) * (int)unaff_EBX;
  if (unaff_EBX == (int *)0x0) {
    iStack_4c = iStack_54;
  }
  else {
    iStack_4c = *(int *)(unaff_EBP + 0x2c) + iStack_54;
  }
  (**(code **)(*piVar4 + 8))(auStack_60);
  piVar3 = (int *)(**(code **)(**(int **)(unaff_ESI + 4) + 0x2c))();
  if (piVar3 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar4 + 0x74))(piVar3);
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(*piVar3 + 0x78))(piVar4);
      if (cVar1 == '\0') {
        (**(code **)(*piVar4 + 0x74))(0);
      }
      else {
        iVar6 = (**(code **)(*unaff_EBX + 0x38))();
        piVar4[1] = iVar6;
      }
    }
  }
  (**(code **)(*piVar5 + 0x38))(piVar4);
  (**(code **)(*piVar5 + 0x1c))(auStack_90);
  (**(code **)(*piVar4 + 0x2c))(piVar5);
  pvVar7 = operator_new(0x468);
  if (pvVar7 == (void *)0x0) {
    puVar8 = (undefined4 *)0x0;
  }
  else {
    puVar8 = (undefined4 *)FUN_00505f10();
  }
  *(undefined1 *)((int)puVar8 + 0x1a5) = 0;
  *(undefined1 *)(puVar8 + 0x69) = 0;
  *(undefined1 *)(puVar8 + 0x69) = 10;
  *puVar8 = *(undefined4 *)(unaff_EDI + 0x70);
  puVar8[1] = *(undefined4 *)(unaff_EDI + 0x74);
  puVar8[2] = *(undefined4 *)(unaff_EDI + 0x78);
  FUN_00571390(unaff_EDI + 0x80);
  if (piVar5 + 0x20 != aiStack_b4 + -3) {
    FUN_00504490(aiStack_b4 + -5,*(undefined4 *)piVar5[0x21],(undefined4 *)piVar5[0x21]);
    FUN_005040e0(aiStack_b4 + -3);
  }
  FUN_00504490(aiStack_b4 + -5,*unaff_EBX,unaff_EBX);
  _free(unaff_EBX);
  return;
}


// ==== FUN_006c6720 @ 0x006c6720 ====

undefined4 FUN_006c6720(void)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 extraout_EAX;
  int *piVar4;
  undefined4 extraout_EAX_00;
  uint uVar5;
  int iVar6;
  undefined4 *****pppppuVar7;
  undefined4 uVar8;
  undefined4 extraout_EAX_01;
  int in_ECX;
  char *pcVar9;
  void *pvStack_9c;
  undefined4 *****pppppuStack_98;
  void *pvStack_94;
  uint uStack_88;
  uint uStack_84;
  uint uStack_80;
  int *piStack_78;
  int *piStack_74;
  undefined1 auStack_3c [60];
  
  piVar2 = (int *)(**(code **)(*DAT_00b5ac1c + 0x14))();
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  pcVar3 = (char *)(**(code **)(*piVar2 + 0x70))();
  uStack_80 = 0xf;
  uStack_84 = 0;
  pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
  pcVar9 = pcVar3;
  do {
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar3,(int)pcVar9 - (int)(pcVar3 + 1));
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
  piStack_74 = piVar2;
  if (piVar2 == (int *)0x0) {
    if (0xf < uStack_80) {
      _free(pvStack_94);
      return extraout_EAX;
    }
  }
  else {
    piVar4 = (int *)(**(code **)(*DAT_00b5a7b4 + 0x58))();
    piStack_78 = piVar4;
    if (piVar4 != (int *)0x0) {
      uVar5 = (**(code **)(*piVar4 + 0x10))();
      if (uVar5 < 2) {
        (**(code **)(*piVar2 + 0x24))(0);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      (**(code **)(*piVar2 + 0x24))(1);
      uStack_80 = (**(code **)(*DAT_00b5a7b4 + 0x4c))();
      iVar6 = (**(code **)(*piVar4 + 0x10))();
      FUN_006c6310(iVar6 + -1);
      FUN_006c5e40();
      iVar6 = (**(code **)(*piVar4 + 4))();
      do {
        if (iVar6 == 0) {
          (**(code **)(*DAT_00b5a7b4 + 0x5c))(piVar4);
          if (uStack_88 < 0x10) {
            return 1;
          }
          _free(pvStack_9c);
          return extraout_EAX_01;
        }
        iVar6 = (**(code **)(*piVar4 + 4))();
        if (iVar6 != 0) {
          pppppuVar7 = pppppuStack_98;
          if (uStack_84 < 0x10) {
            pppppuVar7 = &pppppuStack_98;
          }
          iVar6 = FUN_00403620(0,*(undefined4 *)(iVar6 + 0x24),pppppuVar7,uStack_88);
          if (iVar6 != 0) {
            iVar6 = *piVar2;
            FUN_00401830(s_state_d_009e2de8);
            uVar8 = FUN_00404230(auStack_3c);
            (**(code **)(iVar6 + 0x4c))(uVar8);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
        }
        (**(code **)(*piVar4 + 0xc))();
        iVar6 = (**(code **)(*piVar4 + 4))();
      } while( true );
    }
    if (0xf < uStack_80) {
      _free(pvStack_94);
      return extraout_EAX_00;
    }
  }
  return 0;
}


// ==== FUN_006c6ac0 @ 0x006c6ac0 ====

uint FUN_006c6ac0(int *param_1)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70010004) {
    (**(code **)(*in_ECX + 0xc))(1);
    uVar2 = FUN_006c6720();
  }
  else {
    if (iVar1 == 0x70010005) {
      uVar2 = FUN_006c58f0();
      return uVar2 & 0xffffff00;
    }
    uVar2 = iVar1 + 0x8ffefffa;
    if (uVar2 == 0) {
      return 1;
    }
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_006c6b10 @ 0x006c6b10 ====

bool FUN_006c6b10(void)

{
  int in_ECX;
  
  return *(char *)(in_ECX + 0x34) != '\0';
}


// ==== FUN_006c6b20 @ 0x006c6b20 ====

void FUN_006c6b20(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009e2f10;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if (0xf < (uint)in_ECX[10]) {
    _free((void *)in_ECX[5]);
    return;
  }
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006c6b80 @ 0x006c6b80 ====

void FUN_006c6b80(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
  (**(code **)(*piVar1 + 0x24))(param_1);
  if (*(char *)(in_ECX + 8) == '\0') {
    *(undefined1 *)(in_ECX + 8) = 1;
  }
  return;
}


// ==== FUN_006c6bb0 @ 0x006c6bb0 ====

void FUN_006c6bb0(void)

{
  char cVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e2fd8;
  cVar1 = (**(code **)(*DAT_00b5aee4 + 0x18))();
  if (cVar1 != '\0') {
    (**(code **)(*DAT_00b5aee4 + 0x20))(1);
  }
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006c6bf0 @ 0x006c6bf0 ====

undefined4 FUN_006c6bf0(void)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5aee4 + 0xc))();
  if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5aee4 + 8))();
    return 1;
  }
  return 0;
}


// ==== FUN_006c6c10 @ 0x006c6c10 ====

void FUN_006c6c10(void *param_1)

{
  int *piVar1;
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
  FUN_00401740(s_textbox_009e2fa0,7);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  (**(code **)(*piVar1 + 0x30))();
  FUN_005569f0(&uStack00000000,1);
  if (in_stack_00000018 < 0x10) {
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_006c6ca0 @ 0x006c6ca0 ====

/* WARNING: Removing unreachable block (ram,0x006c6cf0) */

void FUN_006c6ca0(undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  char cVar3;
  int *piVar4;
  undefined4 uVar5;
  int *in_ECX;
  void *unaff_EBP;
  undefined4 uStack_1c;
  
  piVar4 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(param_1);
  if (piVar4 == (int *)0x0) {
    FUN_00401740(s_pComposite____NULL_009e2fbc,0x12);
    FUN_00406880((int)register0x00000010 + -0x20);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  piVar4 = (int *)(**(code **)(*piVar4 + 0x30))();
  cVar3 = (**(code **)(*piVar4 + 0x48))();
  if (cVar3 != '\x01') {
    (**(code **)(*DAT_00b5aee4 + 4))(param_1);
    return;
  }
  iVar1 = *DAT_00b5aee4;
  uVar5 = (**(code **)(*piVar4 + 0x54))();
  uVar5 = (**(code **)(*piVar4 + 0x4c))(param_1,uVar5);
  uVar5 = (**(code **)(*piVar4 + 0x50))((int)register0x00000010 + -0x20,uVar5);
  (**(code **)(iVar1 + 0x1c))(uVar5);
  if (uStack_1c < 0x10) {
    (**(code **)(*in_ECX + 0xc))(0);
    return;
  }
  _free(unaff_EBP);
  return;
}


// ==== FUN_006c6d90 @ 0x006c6d90 ====

void FUN_006c6d90(void)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_ECX;
  uint uVar4;
  undefined1 in_stack_ffffff44;
  uint in_stack_ffffff48;
  undefined4 in_stack_ffffff4c;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 local_8c [4];
  void *local_88;
  undefined4 local_78;
  uint local_74;
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
  
  local_74 = 0xf;
  local_78 = 0;
  local_88 = (void *)((uint)local_88 & 0xffffff00);
  FUN_00401740(&DAT_009e2f93,0);
  piVar1 = (int *)(**(code **)(*DAT_00b5aee4 + 0x10))();
  *(int **)(in_ECX + 0x10) = piVar1;
  uVar2 = (**(code **)(*piVar1 + 0xc))();
  uVar5 = 0x6c6ddf;
  FUN_00401660(uVar2,0,0xffffffff);
  uVar4 = 0;
  uVar3 = (**(code **)(**(int **)(in_ECX + 0x10) + 0x10))();
  if (uVar3 != 0) {
    do {
      uVar2 = (**(code **)(**(int **)(in_ECX + 0x10) + 0x14))(uVar4);
      in_stack_ffffff44 = 0;
      FUN_00401740(&DAT_009e2f94,2);
      uVar5 = FUN_00404230(auStack_1c);
      in_stack_ffffff48 = 0x6c6e48;
      uVar2 = FUN_004022a0(auStack_54,&DAT_009e2f9c,uVar2,&DAT_009e2f98,uVar5);
      in_stack_ffffff4c = 0x6c6e56;
      uVar2 = FUN_00402220(auStack_38,uVar2);
      uVar2 = FUN_00405bd0(auStack_70,uVar2);
      uVar5 = 0x6c6e74;
      FUN_00401ff0(uVar2,0,0xffffffff);
      if (0xf < uStack_58) {
        _free(pvStack_6c);
        return;
      }
      uStack_58 = 0xf;
      uStack_5c = 0;
      pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
      if (0xf < uStack_20) {
        _free(pvStack_34);
        return;
      }
      uStack_20 = 0xf;
      uStack_24 = 0;
      pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
      if (0xf < uStack_3c) {
        _free(pvStack_50);
        return;
      }
      uStack_3c = 0xf;
      uStack_40 = 0;
      pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
      uVar4 = uVar4 + 1;
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    } while (uVar4 < uVar3);
  }
  uVar7 = 0xf;
  uVar6 = 0;
  in_stack_ffffff48 = in_stack_ffffff48 & 0xffffff00;
  FUN_00401660(local_8c,0,0xffffffff);
  FUN_006c6c10(in_stack_ffffff44,in_stack_ffffff48,in_stack_ffffff4c,uVar5,uVar2,uVar6,uVar7);
  if (local_74 < 0x10) {
    return;
  }
  _free(local_88);
  return;
}


// ==== __break @ 0x006c6f72 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_006c6f80 @ 0x006c6f80 ====

undefined4 FUN_006c6f80(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70020002) {
    FUN_006c6d90();
    return 1;
  }
  return 0;
}


// ==== FUN_006c6fb0 @ 0x006c6fb0 ====

void FUN_006c6fb0(void)

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
  FUN_00401740(s_UI_Game2_ui_dialog_txt_009e2f7c,0x16);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_006c6d90();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_006c7030 @ 0x006c7030 ====

void FUN_006c7030(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e2fd8;
  in_ECX[1] = 0;
  FUN_006c6fb0();
  return;
}


// ==== FUN_006c7050 @ 0x006c7050 ====

undefined4 FUN_006c7050(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined1 local_10 [4];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009e2fa8,8);
  if (iVar2 == 0) {
    (**(code **)(*DAT_00b5aee4 + 8))();
    return 1;
  }
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  FUN_00404fb0(param_2,0x5f,local_10);
  pcVar4 = s_select_009e2fb4;
  uVar3 = FUN_00405d30(1);
  cVar1 = FUN_004036a0(uVar3,pcVar4);
  if (cVar1 != '\0') {
    uVar3 = FUN_00405d30(0);
    uVar3 = thunk_FUN_00796fb0(uVar3);
    FUN_006c6ca0(param_2,uVar3);
  }
  FUN_00406250();
  return 1;
}


// ==== FUN_006c7120 @ 0x006c7120 ====

void FUN_006c7120(void)

{
  char cVar1;
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009e2fd8;
  cVar1 = (**(code **)(*DAT_00b5aee4 + 0x18))();
  if (cVar1 != '\0') {
    (**(code **)(*DAT_00b5aee4 + 0x20))(1);
  }
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006c7170 @ 0x006c7170 ====

void FUN_006c7170(void)

{
  return;
}


// ==== FUN_006c7180 @ 0x006c7180 ====

undefined1 FUN_006c7180(void)

{
  return 0;
}


// ==== FUN_006c7190 @ 0x006c7190 ====

void FUN_006c7190(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e30c8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006c71f0 @ 0x006c71f0 ====

void FUN_006c71f0(void)

{
  undefined1 uVar1;
  char cVar2;
  int *piVar3;
  int in_ECX;
  undefined4 unaff_EBX;
  void *unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 uVar4;
  undefined4 uStack_40;
  uint uStack_38;
  void *pvStack_30;
  uint uStack_2c;
  void *pvStack_24;
  void *pvStack_20;
  void *pvStack_1c;
  uint uStack_18;
  uint uStack_10;
  uint uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  (**(code **)(*DAT_00b5ad1c + 0x60))();
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = uStack_18 & 0xffffff00;
  FUN_00401740(s_btn_pcroom_009e3060,10);
  uVar1 = (**(code **)(*DAT_00b5ac1c + 0x2c))();
  uStack_40 = (float)CONCAT31(uStack_40._1_3_,uVar1);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1c);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x24))(unaff_EBX);
  }
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return;
  }
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  uStack_c = 0;
  uStack_8 = 0xf;
  if (uStack_40 <= DAT_0099cdc8) {
    FUN_00401740(s_btn_expRate_009e3078,0xb);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
    if (piVar3 != (int *)0x0) {
      uVar4 = 0;
      goto LAB_006c72cb;
    }
  }
  else {
    FUN_00401740(s_btn_expRate_009e306c,0xb);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
    if (piVar3 != (int *)0x0) {
      uVar4 = 1;
LAB_006c72cb:
      (**(code **)(*piVar3 + 0x24))(uVar4);
    }
  }
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  FUN_00401740(s_btn_dropRate_009e3094,0xc);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_24);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x24))(0);
  }
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return;
  }
  uStack_2c = 0xf;
  pvStack_30 = (void *)0x0;
  FUN_00401740(s_btn_fishing_009e30a4,0xb);
  cVar2 = (**(code **)(*DAT_00b5ad1c + 0x68))();
  if (cVar2 == '\0') {
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x44);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(0);
    }
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x44);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(1);
    }
    uVar1 = (**(code **)(*DAT_00b5aeec + 0x38))();
    unaff_ESI = (void *)CONCAT31((int3)((uint)unaff_ESI >> 8),uVar1);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x48);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x44))(unaff_EDI);
    }
  }
  cVar2 = (**(code **)(*DAT_00b5ad1c + 0x78))();
  uStack_2c = uStack_2c & 0xffffff00;
  pvStack_1c = (void *)0x0;
  uStack_18 = 0xf;
  if (cVar2 == '\0') {
    FUN_00401740(s_btn_ppl_009e30b8,7);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_30);
    if (piVar3 == (int *)0x0) goto LAB_006c7419;
    uVar4 = 0;
  }
  else {
    FUN_00401740(s_btn_ppl_009e30b0,7);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_30);
    if (piVar3 == (int *)0x0) goto LAB_006c7419;
    uVar4 = 1;
  }
  (**(code **)(*piVar3 + 0x24))(uVar4);
LAB_006c7419:
  if ((void *)0xf < pvStack_1c) {
    _free(pvStack_30);
    return;
  }
  if (uStack_38 < 0x10) {
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_006c7450 @ 0x006c7450 ====

void FUN_006c7450(void)

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
  FUN_00401740(s_UI_Game2_ui_pcroomwnd_txt_009e3044,0x19);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_006c71f0();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_006c74d0 @ 0x006c74d0 ====

undefined4 FUN_006c74d0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70420002) {
    FUN_006c71f0();
    return 1;
  }
  return 0;
}


// ==== FUN_006c7500 @ 0x006c7500 ====

void FUN_006c7500(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e30c8;
  FUN_006c7450();
  return;
}


// ==== FUN_006c7520 @ 0x006c7520 ====

undefined4 FUN_006c7520(void)

{
  return 0x4a;
}


// ==== FUN_006c7530 @ 0x006c7530 ====

void FUN_006c7530(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009e30c8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== __break @ 0x006c756d ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_006c7570 @ 0x006c7570 ====

void FUN_006c7570(void)

{
  return;
}


// ==== FUN_006c75a0 @ 0x006c75a0 ====

void FUN_006c75a0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if (iVar2 != 0) {
    piVar1 = *(int **)(iVar2 + 0x74);
    piVar3 = (int *)(**(code **)(*piVar1 + 0x14))();
    (**(code **)(*piVar3 + 0x10))(*(undefined4 *)(param_1 + 4));
    (**(code **)(*piVar1 + 0x18))();
    (**(code **)(*DAT_00b5ad1c + 8))();
  }
  return;
}


// ==== FUN_006c75e0 @ 0x006c75e0 ====

void FUN_006c75e0(int param_1,undefined4 param_2)

{
  int in_ECX;
  
  FUN_006c9130(&param_1,param_1);
  if (param_1 != *(int *)(in_ECX + 0xc)) {
    *(undefined4 *)(param_1 + 0x28) = param_2;
  }
  return;
}


// ==== FUN_006c7610 @ 0x006c7610 ====

int FUN_006c7610(int param_1,undefined4 param_2)

{
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_004020e0(s_<font_3>_009e3250,8);
  FUN_00401ff0(param_2,0,0xffffffff);
  FUN_004020e0(s_<_font>_009e325c,7);
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


// ==== FUN_006c76d0 @ 0x006c76d0 ====

void FUN_006c76d0(void)

{
  int *piVar1;
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
  FUN_00401740(s_btn_vehicle_009e3264,0xb);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x44))(*(undefined1 *)(unaff_retaddr + 4));
  }
  return;
}


// ==== FUN_006c7850 @ 0x006c7850 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c7850(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  undefined2 *puVar5;
  int *piVar6;
  int *piVar7;
  int in_ECX;
  void *apvStack_20 [4];
  undefined4 uStack_10;
  uint uStack_c;
  
  iVar3 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if ((iVar3 != 0) && (piVar7 = *(int **)(iVar3 + 0x48), piVar7 != (int *)0x0)) {
    piVar4 = (int *)(**(code **)(*piVar7 + 0x24))();
    puVar5 = (undefined2 *)(**(code **)(*piVar4 + 8))();
    piVar4 = (int *)(**(code **)(*DAT_00b5abb0 + 8))(*puVar5);
    if (piVar4 != (int *)0x0) {
      FUN_00401830(&PTR_LAB_009e32cc);
      piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_20);
      if (0xf < uStack_c) {
        _free(apvStack_20[0]);
        return;
      }
      uStack_c = 0xf;
      uStack_10 = 0;
      apvStack_20[0] = (void *)((uint)apvStack_20[0] & 0xffffff00);
      if ((piVar6 != (int *)0x0) && (iVar3 = (**(code **)(*piVar6 + 0x30))(), iVar3 != 0)) {
        iVar3 = (**(code **)(*piVar4 + 4))();
        fVar1 = (float)*(int *)(iVar3 + 4);
        if (*(int *)(iVar3 + 4) < 0) {
          fVar1 = fVar1 + _DAT_0099d104;
        }
        piVar7 = (int *)(**(code **)(*piVar7 + 0x14))();
        fVar2 = (float)*piVar7;
        if (*piVar7 < 0) {
          fVar2 = fVar2 + _DAT_0099d104;
        }
        if (fVar1 < _DAT_009e34a0) {
          FUN_00587ba0(0);
          return;
        }
        FUN_00587ba0((fVar2 / fVar1) * DAT_0099de78);
      }
    }
  }
  return;
}


// ==== FUN_006c7980 @ 0x006c7980 ====

void FUN_006c7980(void)

{
  char cVar1;
  int in_ECX;
  undefined4 local_24;
  int iStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  local_24 = 2;
  cVar1 = (**(code **)(*DAT_00b5ad54 + 0x24))();
  if (cVar1 == '\0') {
    local_24 = 1;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_btn_inven_009e32d0,9);
  FUN_006c9130(&iStack_20,auStack_1c);
  if (iStack_20 != *(int *)(in_ECX + 0xc)) {
    *(undefined4 *)(iStack_20 + 0x28) = local_24;
  }
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_btn_character_009e32dc,0xd);
  FUN_006c9130(&iStack_20,auStack_1c);
  if (iStack_20 != *(int *)(in_ECX + 0xc)) {
    *(undefined4 *)(iStack_20 + 0x28) = local_24;
  }
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_btn_skill_009e32ec,9);
  FUN_006c9130(&iStack_20,auStack_1c);
  if (iStack_20 != *(int *)(in_ECX + 0xc)) {
    *(undefined4 *)(iStack_20 + 0x28) = local_24;
  }
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_btn_quest_009e32f8,9);
  FUN_006c9130(&iStack_20,auStack_1c);
  if (iStack_20 != *(int *)(in_ECX + 0xc)) {
    *(undefined4 *)(iStack_20 + 0x28) = local_24;
  }
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_btn_help_009e3304,8);
  FUN_006c9130(&iStack_20,auStack_1c);
  if (iStack_20 != *(int *)(in_ECX + 0xc)) {
    *(undefined4 *)(iStack_20 + 0x28) = local_24;
  }
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_btn_store_009e3310,9);
  FUN_006c9130(&iStack_20,auStack_1c);
  if (iStack_20 != *(int *)(in_ECX + 0xc)) {
    *(undefined4 *)(iStack_20 + 0x28) = local_24;
  }
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_btn_option_009e331c,10);
  FUN_006c9130(&iStack_20,auStack_1c);
  if (iStack_20 != *(int *)(in_ECX + 0xc)) {
    *(undefined4 *)(iStack_20 + 0x28) = local_24;
  }
  if (uStack_4 < 0x10) {
    return;
  }
  _free(pvStack_18);
  return;
}


// ==== FUN_006c7bf0 @ 0x006c7bf0 ====

undefined4 FUN_006c7bf0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_ECX;
  int *piVar4;
  undefined1 auStack_4c [16];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  char *pcStack_30;
  undefined4 uStack_2c;
  
  uStack_34 = *(undefined4 *)(param_1 + 0x14);
  uStack_2c = (char *)0xb;
  pcStack_30 = s_btn_vehicle_009e33d8;
  uStack_38 = 0;
  uStack_3c = 0x6c7c10;
  iVar2 = FUN_00403620();
  if (iVar2 == 0) {
    uStack_2c = (char *)0x6c7c1f;
    (**(code **)(*DAT_00b5ad84 + 0x14))();
    return 1;
  }
  uStack_34 = *(undefined4 *)(param_1 + 0x14);
  uStack_2c = (char *)0x9;
  pcStack_30 = s_btn_guild_009e33e4;
  uStack_38 = 0;
  uStack_3c = 0x6c7c3e;
  iVar2 = FUN_00403620();
  if (iVar2 == 0) {
    uStack_2c = (char *)0x6c7c4d;
    cVar1 = (**(code **)(*DAT_00b5aca8 + 0x78))();
    if (cVar1 == '\0') {
      uStack_2c = (char *)0x6c7c5c;
      (**(code **)(*DAT_00b5aca8 + 0x34))();
      return 1;
    }
    uStack_2c = (char *)0x6c7c6c;
    (**(code **)(*DAT_00b5aca8 + 0x40))();
    return 1;
  }
  uStack_34 = *(undefined4 *)(param_1 + 0x14);
  uStack_2c = (char *)0x9;
  pcStack_30 = s_btn_party_009e33f0;
  uStack_38 = 0;
  uStack_3c = 0x6c7c8b;
  iVar2 = FUN_00403620();
  if (iVar2 == 0) {
    uStack_2c = (char *)0x6c7c9a;
    cVar1 = (**(code **)(*DAT_00b5a7b4 + 0x3c))();
    if (cVar1 == '\x01') {
      uStack_2c = (char *)0x6c7ca9;
      (**(code **)(*DAT_00b5a7b4 + 0x30))();
      return 1;
    }
    uStack_2c = (char *)0x6c7cb9;
    (**(code **)(*DAT_00b5a7b4 + 0x2c))();
    return 1;
  }
  uStack_2c = s_btn_fish_009e33fc;
  pcStack_30 = (char *)param_1;
  uStack_34 = 0x6c7ccf;
  cVar1 = FUN_004036a0();
  if (cVar1 != '\0') {
    uStack_2c = (char *)0x6c7ce1;
    (**(code **)(*DAT_00b5aeec + 0xc))();
    return 1;
  }
  uStack_2c = s_btn_memo_009e3408;
  pcStack_30 = (char *)param_1;
  uStack_34 = 0x6c7cf7;
  cVar1 = FUN_004036a0();
  if (cVar1 != '\0') {
    uStack_2c = (char *)0x6c7d09;
    cVar1 = (**(code **)(*DAT_00b5ae3c + 0x4c))();
    if (cVar1 == '\0') {
      uStack_2c = (char *)0x6c7d18;
      (**(code **)(*DAT_00b5ae3c + 0x18))();
      return 1;
    }
    uStack_2c = (char *)0x6c7d28;
    (**(code **)(*DAT_00b5ae3c + 0x1c))();
    return 1;
  }
  uStack_2c = s_btn_menu_009e3414;
  pcStack_30 = (char *)param_1;
  uStack_34 = 0x6c7d3e;
  cVar1 = FUN_004036a0();
  if (cVar1 != '\0') {
    iVar2 = *DAT_00b5ad54;
    uStack_2c = (char *)0x6c7d54;
    cVar1 = (**(code **)(*DAT_00b5ad54 + 0x24))();
    uStack_2c = (char *)CONCAT31((int3)((uint)extraout_ECX >> 8),cVar1 == '\0');
    pcStack_30 = (char *)0x6c7d5f;
    (**(code **)(iVar2 + 0x34))();
    pcStack_30 = (char *)0x6c7d66;
    FUN_006c7980();
    return 1;
  }
  uStack_2c = s_btn_inven_009e3420;
  pcStack_30 = (char *)param_1;
  uStack_34 = 0x6c7d7c;
  cVar1 = FUN_004036a0();
  if (cVar1 != '\0') {
    uStack_2c = (char *)0x6c7d8e;
    cVar1 = (**(code **)(*DAT_00b5a78c + 0x5c))();
    if (cVar1 == '\x01') {
      uStack_2c = (char *)0x6c7d9d;
      (**(code **)(*DAT_00b5a78c + 0x24))();
      return 1;
    }
    uStack_2c = (char *)0x6c7dad;
    (**(code **)(*DAT_00b5a78c + 0x20))();
    return 1;
  }
  uStack_2c = s_btn_character_009e342c;
  pcStack_30 = (char *)param_1;
  uStack_34 = 0x6c7dc3;
  cVar1 = FUN_004036a0();
  if (cVar1 != '\0') {
    uStack_2c = (char *)0x6c7dd5;
    cVar1 = (**(code **)(*DAT_00b5ae98 + 0x20))();
    if (cVar1 == '\x01') {
      uStack_2c = (char *)0x6c7de4;
      (**(code **)(*DAT_00b5ae98 + 4))();
      return 1;
    }
    uStack_2c = (char *)0x6c7df4;
    (**(code **)(*DAT_00b5ae98 + 8))();
    return 1;
  }
  uStack_2c = s_btn_skill_009e343c;
  pcStack_30 = (char *)param_1;
  uStack_34 = 0x6c7e0a;
  cVar1 = FUN_004036a0();
  if (cVar1 != '\0') {
    uStack_2c = (char *)0x6c7e1c;
    cVar1 = (**(code **)(*DAT_00b5acb8 + 0x10))();
    if (cVar1 == '\x01') {
      uStack_2c = (char *)0x6c7e2b;
      (**(code **)(*DAT_00b5acb8 + 0xc))();
      return 1;
    }
    uStack_2c = (char *)0x6c7e3b;
    (**(code **)(*DAT_00b5acb8 + 8))();
    return 1;
  }
  uStack_2c = s_btn_quest_009e3448;
  pcStack_30 = (char *)param_1;
  uStack_34 = 0x6c7e51;
  cVar1 = FUN_004036a0();
  if (cVar1 != '\0') {
    uStack_2c = (char *)0x6c7e63;
    cVar1 = (**(code **)(*DAT_00b5ac38 + 0x28))();
    if (cVar1 == '\0') {
      uStack_2c = (char *)0x6c7e72;
      (**(code **)(*DAT_00b5ac38 + 0x24))();
      return 1;
    }
    uStack_2c = (char *)0x6c7e82;
    (**(code **)(*DAT_00b5ac38 + 0x2c))();
    return 1;
  }
  uStack_2c = s_btn_help_009e3454;
  pcStack_30 = (char *)param_1;
  uStack_34 = 0x6c7e98;
  cVar1 = FUN_004036a0();
  if (cVar1 != '\0') {
    uStack_2c = (char *)0x6c7eaa;
    cVar1 = (**(code **)(*DAT_00b5ae94 + 0x10))();
    if (cVar1 == '\0') {
      uStack_2c = (char *)0x6c7eb9;
      (**(code **)(*DAT_00b5ae94 + 8))();
      return 1;
    }
    uStack_2c = (char *)0x6c7ec9;
    (**(code **)(*DAT_00b5ae94 + 0xc))();
    return 1;
  }
  uStack_2c = s_btn_store_009e3460;
  pcStack_30 = (char *)param_1;
  uStack_34 = 0x6c7edf;
  cVar1 = FUN_004036a0();
  if (cVar1 != '\0') {
    uStack_2c = (char *)0x6c7ef5;
    cVar1 = (**(code **)(*DAT_00b5adc4 + 0x38))();
    if (cVar1 == '\0') {
      uStack_2c = (char *)0x28000f;
      pcStack_30 = (char *)0x0;
      uStack_34 = 0x6c7f0f;
      uStack_34 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_38 = 0x6c7f19;
      FUN_00765c50();
      iVar2 = *DAT_00b5ad0c;
      FUN_00765c50(auStack_4c + 0x28);
      (**(code **)(iVar2 + 0x28))(2);
      uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,&DAT_006e006c);
      FUN_00401660(uVar3,0,0xffffffff);
      iVar2 = *DAT_00b5ad0c;
      FUN_00765c50(auStack_4c);
      (**(code **)(iVar2 + 0x28))(2);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    uStack_2c = (char *)0x6c7f94;
    (**(code **)(*DAT_00b5adc4 + 0x10))();
    return 1;
  }
  uStack_2c = s_btn_option_009e346c;
  pcStack_30 = (char *)param_1;
  uStack_34 = 0x6c7faa;
  cVar1 = FUN_004036a0();
  if (cVar1 != '\0') {
    uStack_2c = (char *)0x23;
    pcStack_30 = (char *)0x6c7fbe;
    iVar2 = (**(code **)(*DAT_00b5a74c + 0xc))();
    pcStack_30 = (char *)0x23;
    if (iVar2 == 0) {
      uStack_34 = 0x6c7fcf;
      (**(code **)(*DAT_00b5a750 + 8))();
      return 1;
    }
    uStack_34 = 0x6c7fdf;
    (**(code **)(*DAT_00b5a750 + 0xc))();
    return 1;
  }
  uStack_2c = s_btn_cash_009e3478;
  pcStack_30 = (char *)param_1;
  uStack_34 = 0x6c7ff5;
  cVar1 = FUN_004036a0();
  if (cVar1 == '\0') {
    uStack_2c = s_btn_slot_up_009e3484;
    pcStack_30 = (char *)param_1;
    uStack_34 = 0x6c802c;
    cVar1 = FUN_004036a0();
    if (cVar1 != '\0') {
      uStack_2c = (char *)0x6c803e;
      (**(code **)(*DAT_00b5ad54 + 0x4c))();
      return 1;
    }
    uStack_2c = s_btn_slot_down_009e3490;
    pcStack_30 = (char *)param_1;
    uStack_34 = 0x6c8054;
    cVar1 = FUN_004036a0();
    if (cVar1 == '\0') {
      return 0;
    }
    piVar4 = DAT_00b5ad54;
  }
  else {
    uStack_2c = (char *)0x6c8007;
    cVar1 = (**(code **)(*DAT_00b5ae74 + 0x28))();
    piVar4 = DAT_00b5ae74;
    if (cVar1 == '\0') {
      uStack_2c = (char *)0x6c8016;
      (**(code **)(*DAT_00b5ae74 + 0x4c))();
      return 1;
    }
  }
  uStack_2c = (char *)0x6c8066;
  (**(code **)(*piVar4 + 0x50))();
  return 1;
}


// ==== FUN_006c8080 @ 0x006c8080 ====

/* WARNING: Removing unreachable block (ram,0x006c8402) */
/* WARNING: Removing unreachable block (ram,0x006c83eb) */

void FUN_006c8080(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint unaff_EBX;
  void *unaff_EDI;
  undefined1 auStack_86 [6];
  void **ppvStack_70;
  uint uStack_6c;
  undefined4 uStack_68;
  void *pvStack_54;
  void *pvStack_50;
  void *pvStack_4c;
  void *pvStack_48;
  uint uStack_44;
  void *pvStack_40;
  void *pvStack_3c;
  uint uStack_38;
  uint uStack_34;
  void *pvStack_30;
  uint uStack_2c;
  uint uStack_28;
  void *pvStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 uStack_14;
  uint uStack_10;
  
  uStack_68 = 0x280021;
  uStack_6c = 0;
  ppvStack_70 = (void **)0x6c809c;
  (**(code **)(*DAT_00b5a794 + 0xc))();
  ppvStack_70 = (void **)0xffffffff;
  uStack_44 = 0xf;
  pvStack_48 = (void *)0x0;
  FUN_00401660();
  ppvStack_70 = (void **)0x9;
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  FUN_00401740();
  ppvStack_70 = (void **)(auStack_86 + 0x2a);
  FUN_006c7610();
  ppvStack_70 = &pvStack_40;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    FUN_00401660();
  }
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  if (0xf < uStack_2c) {
    _free(pvStack_40);
    return;
  }
  (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401660();
  uStack_34 = 0xf;
  uStack_38 = 0;
  pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
  FUN_00401740();
  FUN_006c7610();
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    FUN_00401660();
  }
  if (0xf < uStack_1c) {
    _free(pvStack_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
  if (0xf < uStack_38) {
    _free(pvStack_4c);
    return;
  }
  uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401660(uVar3);
  pvStack_40 = (void *)0xf;
  uStack_44 = 0;
  pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
  FUN_00401740();
  uVar3 = FUN_006c7610();
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    FUN_00401660(uVar3,0);
  }
  if (0xf < uStack_28) {
    _free(pvStack_3c);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  if (0xf < uStack_44) {
    _free((void *)(unaff_EBX & 0xffffff00));
    return;
  }
  uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
  FUN_00401660(uVar3,0,0xffffffff);
  pvStack_4c = (void *)0xf;
  pvStack_50 = (void *)0x0;
  FUN_00401740(s_btn_memo_009e3238,8);
  uVar3 = FUN_006c7610(&pvStack_48,auStack_86 + 6);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_86 + 0x22);
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    FUN_00401660(uVar3,0,0xffffffff);
  }
  if (0xf < uStack_34) {
    _free(pvStack_48);
    return;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
  if (0xf < pvStack_50) {
    _free(unaff_EDI);
    return;
  }
  uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x7d50010);
  FUN_00401660(uVar3,0,0xffffffff);
  uStack_6c = uStack_6c & 0xffffff00;
  FUN_00401740(s_btn_vehicle_009e3244,0xb);
  uVar3 = FUN_006c7610(&pvStack_54,auStack_86 + -6);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&ppvStack_70);
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    FUN_00401660(uVar3,0,0xffffffff);
  }
  if (pvStack_40 < (void *)0x10) {
    return;
  }
  _free(pvStack_54);
  return;
}


// ==== FUN_006c8420 @ 0x006c8420 ====

/* WARNING: Removing unreachable block (ram,0x006c84ba) */

void FUN_006c8420(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 auStack_3a [58];
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x10))();
    FUN_004fed70(uVar2);
    (**(code **)(*piVar1 + 0xc))(auStack_3a + -6);
  }
  return;
}


// ==== FUN_006c84d0 @ 0x006c84d0 ====

void FUN_006c84d0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int in_ECX;
  int iVar7;
  int iVar8;
  
  iVar2 = *(int *)(param_1 + 4);
  puVar3 = *(undefined4 **)(in_ECX + 0xc);
  puVar4 = (undefined4 *)*puVar3;
  do {
    if (puVar4 == puVar3) {
      return;
    }
    puVar4[0xb] = puVar4[0xb] + iVar2;
    if (0x31 < (uint)puVar4[0xb]) {
      puVar4[0xb] = 0;
      switch(puVar4[10]) {
      case 1:
        puVar4[0xd] = puVar4[0xd] + 10;
        iVar7 = puVar4[0xd];
        if (iVar7 < 0x43) {
LAB_006c858e:
          iVar8 = iVar7;
        }
        else {
          puVar4[0xd] = 0x43;
          puVar4[10] = 0;
          iVar8 = 0x43;
        }
        break;
      case 2:
        puVar4[0xd] = puVar4[0xd] + -10;
        iVar7 = puVar4[0xd];
        if (0x27 < iVar7) goto LAB_006c858e;
        puVar4[0xd] = 0x27;
        puVar4[10] = 3;
        iVar8 = 0x27;
        break;
      default:
        goto switchD_006c8522_caseD_3;
      case 4:
        puVar4[0xd] = puVar4[0xd] + -10;
        iVar8 = puVar4[0xd];
        iVar7 = puVar4[0xc];
        if (iVar8 <= iVar7) {
          puVar4[0xd] = iVar7;
          puVar4[10] = 6;
          goto LAB_006c858e;
        }
        break;
      case 5:
        puVar4[0xd] = puVar4[0xd] + 10;
        iVar7 = puVar4[0xd];
        if (iVar7 < 0x27) goto LAB_006c858e;
        puVar4[0xd] = 0x27;
        puVar4[10] = 3;
        iVar8 = 0x27;
      }
      FUN_006c8420(puVar4 + 3,iVar8);
    }
switchD_006c8522_caseD_3:
    if (*(char *)((int)puVar4 + 0x39) == '\0') {
      puVar5 = (undefined4 *)puVar4[2];
      if (*(char *)((int)puVar5 + 0x39) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x39);
        puVar4 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x39);
          puVar4 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar4[1] + 0x39);
        puVar6 = (undefined4 *)puVar4[1];
        puVar5 = puVar4;
        while ((puVar4 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar4[2]))) {
          cVar1 = *(char *)((int)puVar4[1] + 0x39);
          puVar6 = (undefined4 *)puVar4[1];
          puVar5 = puVar4;
        }
      }
    }
  } while( true );
}


// ==== FUN_006c8600 @ 0x006c8600 ====

undefined4 FUN_006c8600(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      uVar2 = FUN_006c7bf0(param_2,param_4);
      return uVar2;
    }
    if (param_3 == 4) {
      cVar1 = FUN_004036a0(param_2,s_btn_inven_009e3328);
      if ((((cVar1 == '\0') &&
           (cVar1 = FUN_004036a0(param_2,s_btn_character_009e3334), cVar1 == '\0')) &&
          (cVar1 = FUN_004036a0(param_2,s_btn_skill_009e3344), cVar1 == '\0')) &&
         (((cVar1 = FUN_004036a0(param_2,s_btn_quest_009e3350), cVar1 == '\0' &&
           (cVar1 = FUN_004036a0(param_2,s_btn_help_009e335c), cVar1 == '\0')) &&
          ((cVar1 = FUN_004036a0(param_2,s_btn_store_009e3368), cVar1 == '\0' &&
           (cVar1 = FUN_004036a0(param_2,s_btn_option_009e3374), cVar1 == '\0')))))) {
        return 0;
      }
      cVar1 = (**(code **)(*DAT_00b5ad54 + 0x24))();
      if (cVar1 != '\0') {
        FUN_006c75e0(param_2,4);
      }
      return 1;
    }
    if (param_3 == 5) {
      cVar1 = FUN_004036a0(param_2,s_btn_inven_009e3380);
      if ((((cVar1 == '\0') &&
           (cVar1 = FUN_004036a0(param_2,s_btn_character_009e338c), cVar1 == '\0')) &&
          ((cVar1 = FUN_004036a0(param_2,s_btn_skill_009e339c), cVar1 == '\0' &&
           (((cVar1 = FUN_004036a0(param_2,s_btn_quest_009e33a8), cVar1 == '\0' &&
             (cVar1 = FUN_004036a0(param_2,s_btn_help_009e33b4), cVar1 == '\0')) &&
            (cVar1 = FUN_004036a0(param_2,s_btn_store_009e33c0), cVar1 == '\0')))))) &&
         (cVar1 = FUN_004036a0(param_2,s_btn_option_009e33cc), cVar1 == '\0')) {
        return 0;
      }
      cVar1 = (**(code **)(*DAT_00b5ad54 + 0x24))();
      if (cVar1 != '\0') {
        FUN_006c75e0(param_2,5);
      }
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006c8790 @ 0x006c8790 ====

undefined4 FUN_006c8790(int *param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  
  uVar3 = (**(code **)(*param_1 + 4))();
  if (uVar3 < 0x70050008) {
    if (uVar3 == 0x70050007) {
      iVar1 = *DAT_00b5ad54;
      cVar2 = (**(code **)(*DAT_00b5ad54 + 0x68))();
      (**(code **)(iVar1 + 0x6c))(cVar2 == '\0');
      return 1;
    }
    if (uVar3 == 0x40001) {
      FUN_006c84d0(param_1);
      FUN_006c7850();
      return 0;
    }
    if (uVar3 == 0x70050002) {
      FUN_006c7850();
      *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 8;
      if ((char)param_1[1] == '\x0f') {
        return 1;
      }
    }
  }
  else {
    if (uVar3 == 0x70050008) {
      FUN_006c75a0(param_1);
      return 1;
    }
    if (uVar3 == 0x7005000c) {
      FUN_006c76d0(param_1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006c8840 @ 0x006c8840 ====

void FUN_006c8840(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 auStack_60 [8];
  undefined4 uStack_58;
  undefined1 auStack_48 [4];
  void *pvStack_44;
  undefined4 uStack_34;
  uint uStack_30;
  undefined1 auStack_2c [4];
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  cVar1 = (**(code **)(*DAT_00b5ad54 + 0x24))();
  if (cVar1 == '\0') {
    uVar2 = 0x43;
    uStack_58 = 0;
  }
  else {
    uVar2 = 0x27;
    uStack_58 = 3;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_btn_inven_009e3164,9);
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  FUN_00401660(auStack_48,0,0xffffffff);
  uStack_c = 0;
  uStack_8 = 0xf;
  uStack_10 = uStack_58;
  uStack_4 = uVar2;
  FUN_006c97c0(auStack_60,auStack_2c);
  if (0xf < uStack_14) {
    _free(pvStack_28);
    return;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_btn_character_009e3170,0xd);
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  FUN_00401660(auStack_48,0,0xffffffff);
  uStack_c = 0;
  uStack_8 = 0xf;
  uStack_10 = uStack_58;
  uStack_4 = uVar2;
  FUN_006c97c0(auStack_60,auStack_2c);
  if (0xf < uStack_14) {
    _free(pvStack_28);
    return;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_btn_skill_009e3180,9);
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  FUN_00401660(auStack_48,0,0xffffffff);
  uStack_c = 0;
  uStack_8 = 0xf;
  uStack_10 = uStack_58;
  uStack_4 = uVar2;
  FUN_006c97c0(auStack_60,auStack_2c);
  if (0xf < uStack_14) {
    _free(pvStack_28);
    return;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_btn_quest_009e318c,9);
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  FUN_00401660(auStack_48,0,0xffffffff);
  uStack_c = 0;
  uStack_8 = 0xf;
  uStack_10 = uStack_58;
  uStack_4 = uVar2;
  FUN_006c97c0(auStack_60,auStack_2c);
  if (0xf < uStack_14) {
    _free(pvStack_28);
    return;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_btn_help_009e3198,8);
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  FUN_00401660(auStack_48,0,0xffffffff);
  uStack_c = 0;
  uStack_8 = 0xf;
  uStack_10 = uStack_58;
  uStack_4 = uVar2;
  FUN_006c97c0(auStack_60,auStack_2c);
  if (0xf < uStack_14) {
    _free(pvStack_28);
    return;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_btn_store_009e31a4,9);
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  FUN_00401660(auStack_48,0,0xffffffff);
  uStack_c = 0;
  uStack_8 = 0xf;
  uStack_10 = uStack_58;
  uStack_4 = uVar2;
  FUN_006c97c0(auStack_60,auStack_2c);
  if (0xf < uStack_14) {
    _free(pvStack_28);
    return;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_btn_option_009e31b0,10);
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  FUN_00401660(auStack_48,0,0xffffffff);
  uStack_c = 0;
  uStack_8 = 0;
  uStack_10 = uStack_58;
  uStack_4 = uVar2;
  FUN_006c97c0(auStack_60,auStack_2c);
  if (0xf < uStack_14) {
    _free(pvStack_28);
    return;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_btn_inven_009e31bc,9);
  FUN_006c8420(auStack_48,uVar2);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_btn_character_009e31c8,0xd);
  FUN_006c8420(auStack_48,uVar2);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_btn_skill_009e31d8,9);
  FUN_006c8420(auStack_48,uVar2);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_btn_quest_009e31e4,9);
  FUN_006c8420(auStack_48,uVar2);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_btn_help_009e31f0,8);
  FUN_006c8420(auStack_48,uVar2);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_btn_store_009e31fc,9);
  FUN_006c8420(auStack_48,uVar2);
  if (0xf < uStack_30) {
    _free(pvStack_44);
    return;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  FUN_00401740(s_btn_option_009e3208,10);
  FUN_006c8420(auStack_48,uVar2);
  if (uStack_30 < 0x10) {
    return;
  }
  _free(pvStack_44);
  return;
}


// ==== FUN_006c8e70 @ 0x006c8e70 ====

void FUN_006c8e70(void)

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
  FUN_00401740(s_UI_Game2_Mainbar_ui_mainmenuwnd__009e3134,0x23);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  uVar3 = 0;
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740(s_btn_cash_009e3158,8);
  (**(code **)(*DAT_00b5ac1c + 0x28))();
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1e + -10);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x44))(uVar3);
  }
  if (uStack_14 < 0x10) {
    FUN_006c8840();
    FUN_006c8080();
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_006c8f50 @ 0x006c8f50 ====

void FUN_006c8f50(void)

{
  undefined4 *in_ECX;
  undefined1 auStack_2 [2];
  
  *in_ECX = &PTR_FUN_009e34ac;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  FUN_006c9930(auStack_2 + -6,*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3]);
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_006c8fa0 @ 0x006c8fa0 ====

void FUN_006c8fa0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e34ac;
  iVar1 = FUN_006c9090();
  in_ECX[3] = iVar1;
  *(undefined1 *)(iVar1 + 0x39) = 1;
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  *(undefined4 *)in_ECX[3] = in_ECX[3];
  *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  in_ECX[4] = 0;
  in_ECX[1] = 0;
  FUN_006c8e70();
  return;
}


// ==== FUN_006c8fe0 @ 0x006c8fe0 ====

void FUN_006c8fe0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x39) == '\0') {
    *(int *)(*piVar1 + 4) = param_1;
  }
  piVar1[1] = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(*(int *)(in_ECX + 4) + 4)) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2 = *(int **)(param_1 + 4);
  if (param_1 == *piVar2) {
    *piVar2 = (int)piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2[2] = (int)piVar1;
  *piVar1 = param_1;
  *(int **)(param_1 + 4) = piVar1;
  return;
}


// ==== FUN_006c9030 @ 0x006c9030 ====

void FUN_006c9030(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x39) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_1;
  }
  *(int *)(iVar1 + 4) = param_1[1];
  if (param_1 == *(int **)(*(int *)(in_ECX + 4) + 4)) {
    *(int *)(*(int *)(in_ECX + 4) + 4) = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  piVar2 = (int *)param_1[1];
  if (param_1 == (int *)piVar2[2]) {
    piVar2[2] = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  *piVar2 = iVar1;
  *(int **)(iVar1 + 8) = param_1;
  param_1[1] = iVar1;
  return;
}


// ==== FUN_006c9090 @ 0x006c9090 ====

void FUN_006c9090(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c890;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x3c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0xe) = 1;
  *(undefined1 *)((int)puVar1 + 0x39) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@006c911a @ 0x006c911a ====

void Catch_006c911a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_006c9130 @ 0x006c9130 ====

void FUN_006c9130(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_0042ec70(param_2);
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


// ==== FUN_006c91a0 @ 0x006c91a0 ====

void FUN_006c91a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_2;
  *in_ECX = param_1;
  in_ECX[2] = param_3;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_4,0,0xffffffff);
  in_ECX[10] = *(undefined4 *)(param_4 + 0x1c);
  in_ECX[0xb] = *(undefined4 *)(param_4 + 0x20);
  in_ECX[0xc] = *(undefined4 *)(param_4 + 0x24);
  in_ECX[0xd] = *(undefined4 *)(param_4 + 0x28);
  *(undefined1 *)(in_ECX + 0xe) = param_5;
  *(undefined1 *)((int)in_ECX + 0x39) = 0;
  return;
}


// ==== FUN_006c9210 @ 0x006c9210 ====

void * FUN_006c9210(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098c8a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x3c);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_006c91a0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@006c9285 @ 0x006c9285 ====

void Catch_006c9285(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_006c92a0 @ 0x006c92a0 ====

/* WARNING: Removing unreachable block (ram,0x006c93b9) */
/* WARNING: Removing unreachable block (ram,0x006c93ca) */
/* WARNING: Removing unreachable block (ram,0x006c93d3) */
/* WARNING: Removing unreachable block (ram,0x006c93d6) */
/* WARNING: Removing unreachable block (ram,0x006c93c6) */
/* WARNING: Removing unreachable block (ram,0x006c93e4) */
/* WARNING: Removing unreachable block (ram,0x006c93f1) */
/* WARNING: Removing unreachable block (ram,0x006c93fc) */
/* WARNING: Removing unreachable block (ram,0x006c93f8) */
/* WARNING: Removing unreachable block (ram,0x006c93ec) */
/* WARNING: Removing unreachable block (ram,0x006c93ff) */

void FUN_006c92a0(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0x39) != '\0') {
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
  FUN_004be1c0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x39) == '\0') {
    if (*(char *)(param_2[2] + 0x39) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x39) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x39) == '\0') {
      piVar3 = (int *)FUN_00412850(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x39) == '\0') {
      uVar4 = FUN_004be020(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0xe] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0xe] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0xe] == '\0') {
            *(undefined1 *)(piVar5 + 0xe) = 1;
            *(undefined1 *)(piVar3 + 0xe) = 0;
            FUN_006c8fe0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x39) == '\0') {
            if ((*(char *)(*piVar5 + 0x38) == '\x01') && (*(char *)(piVar5[2] + 0x38) == '\x01'))
            goto LAB_006c94d4;
            if (*(char *)(piVar5[2] + 0x38) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x38) = 1;
              *(undefined1 *)(piVar5 + 0xe) = 0;
              FUN_006c9030(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0xe) = (char)piVar3[0xe];
            *(undefined1 *)(piVar3 + 0xe) = 1;
            *(undefined1 *)(piVar5[2] + 0x38) = 1;
            FUN_006c8fe0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0xe] == '\0') {
            *(undefined1 *)(piVar5 + 0xe) = 1;
            *(undefined1 *)(piVar3 + 0xe) = 0;
            FUN_006c9030(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x39) == '\0') {
            if ((*(char *)(piVar5[2] + 0x38) != '\x01') || (*(char *)(*piVar5 + 0x38) != '\x01')) {
              if (*(char *)(*piVar5 + 0x38) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x38) = 1;
                *(undefined1 *)(piVar5 + 0xe) = 0;
                FUN_006c8fe0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0xe) = (char)piVar3[0xe];
              *(undefined1 *)(piVar3 + 0xe) = 1;
              *(undefined1 *)(*piVar5 + 0x38) = 1;
              FUN_006c9030(piVar3);
              break;
            }
LAB_006c94d4:
            *(undefined1 *)(piVar5 + 0xe) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xe) = 1;
  }
  if ((uint)param_2[9] < 0x10) {
    param_2[9] = 0xf;
    param_2[8] = 0;
    *(undefined1 *)(param_2 + 4) = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[4]);
  return;
}


// ==== FUN_006c9580 @ 0x006c9580 ====

void FUN_006c9580(void *param_1)

{
  if (*(char *)((int)param_1 + 0x39) != '\0') {
    return;
  }
  FUN_006c9580(*(undefined4 *)((int)param_1 + 8));
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


// ==== FUN_006c95e0 @ 0x006c95e0 ====

void FUN_006c95e0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0x5d1745b < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_006c9210(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x38);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x38) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0xe] == '\0') {
LAB_006c96e5:
        *(undefined1 *)(*piVar5 + 0x38) = 1;
        *(undefined1 *)(piVar6 + 0xe) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x38) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_006c8fe0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x38) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x38) = 0;
        FUN_006c9030(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0xe] == '\0') goto LAB_006c96e5;
      if (piVar7 == (int *)*piVar2) {
        FUN_006c9030(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x38) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x38) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x39) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x38);
  } while( true );
}


// ==== FUN_006c97c0 @ 0x006c97c0 ====

/* WARNING: Removing unreachable block (ram,0x006c981f) */

void FUN_006c97c0(undefined4 *param_1,undefined4 *param_2)

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
  if (*(char *)((int)puVar6[1] + 0x39) == '\0') {
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
LAB_006c9850:
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
        if (uVar5 == 0) goto LAB_006c9850;
      }
      bVar11 = (int)uVar5 < 0;
      if (bVar11) {
        puVar9 = (undefined4 *)*puVar6;
      }
      else {
        puVar9 = (undefined4 *)puVar6[2];
      }
    } while (*(char *)((int)puVar9 + 0x39) == '\0');
  }
  param_2 = puVar6;
  if (bVar11) {
    if (puVar6 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar6 = (undefined4 *)FUN_006c95e0(&param_2,1,puVar6,iVar3);
      *param_1 = *puVar6;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_004be260();
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
    puVar6 = (undefined4 *)FUN_006c95e0(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_006c9930 @ 0x006c9930 ====

void FUN_006c9930(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_006c9580(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x39) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x39) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x39);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x39);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x39);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x39);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_006c92a0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_006c99f0 @ 0x006c99f0 ====

undefined4 FUN_006c99f0(void)

{
  return 0x49;
}


// ==== FUN_006c9a00 @ 0x006c9a00 ====

void FUN_006c9a00(byte param_1)

{
  void *in_ECX;
  
  FUN_006c8f50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006c9a20 @ 0x006c9a20 ====

void FUN_006c9a20(void)

{
  return;
}


// ==== FUN_006c9a30 @ 0x006c9a30 ====

undefined1 FUN_006c9a30(void)

{
  return 0;
}


// ==== FUN_006c9a40 @ 0x006c9a40 ====

void FUN_006c9a40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e35e0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006c9a80 @ 0x006c9a80 ====

void FUN_006c9a80(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 auStack_3a [26];
  void *pvStack_20;
  uint uStack_c;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x10))();
    FUN_005041e0(uVar2);
    (**(code **)(*piVar1 + 0xc))(auStack_3a + -6);
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return;
    }
  }
  return;
}


// ==== FUN_006c9b00 @ 0x006c9b00 ====

void FUN_006c9b00(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  int iStack_b4;
  undefined1 auStack_ac [4];
  void *pvStack_a8;
  undefined4 uStack_98;
  uint uStack_94;
  undefined4 auStack_90 [5];
  int iStack_7c;
  int iStack_78;
  int iStack_74;
  int iStack_70;
  int iStack_6c;
  undefined4 auStack_64 [21];
  uint uStack_10;
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  puVar7 = auStack_90;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar7 = puVar7 + 1;
  }
  iVar2 = iStack_70 - iStack_78;
  iVar4 = *(int *)(in_ECX + 0xc);
  iStack_6c = iStack_74 - iStack_7c;
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
  iVar8 = *(int *)(in_ECX + 0x10);
  puVar7 = auStack_64;
  for (iVar5 = 0x19; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar7 = puVar7 + 1;
  }
  uVar6 = 0;
  if ((int)-(uStack_10 >> 1) < iVar8 + 0x23) {
    iStack_b4 = (iVar8 - iStack_70) + iStack_78;
    if (*(int *)(in_ECX + 8) != 0) {
      do {
        iVar8 = (2 - uVar6) * 0x16;
        FUN_00401740(s_pan_buffline__d_009e3594,0xf);
        uVar3 = FUN_00404230(auStack_ac);
        FUN_006c9a80(uVar3,iVar8);
        if (0xf < uStack_94) {
          _free(pvStack_a8);
          return;
        }
        uVar6 = uVar6 + 1;
        uStack_94 = 0xf;
        uStack_98 = 0;
        pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
      } while (uVar6 < *(uint *)(in_ECX + 8));
    }
  }
  else {
    iStack_b4 = *(int *)(in_ECX + 0x18);
    if (*(int *)(in_ECX + 8) != 0) {
      iVar8 = 0;
      do {
        iVar5 = iVar8;
        FUN_00401740(s_pan_buffline__d_009e35a4,0xf);
        uVar3 = FUN_00404230(auStack_ac);
        FUN_006c9a80(uVar3,iVar5);
        if (0xf < uStack_94) {
          _free(pvStack_a8);
          return;
        }
        uVar6 = uVar6 + 1;
        iVar8 = iVar8 + 0x16;
        uStack_94 = 0xf;
        uStack_98 = 0;
        pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
      } while (uVar6 < *(uint *)(in_ECX + 8));
    }
  }
  iStack_74 = iVar4 + iStack_6c;
  iStack_78 = iStack_b4;
  iStack_70 = iStack_b4 + iVar2;
  iStack_7c = iVar4;
  (**(code **)(**(int **)(in_ECX + 4) + 0x18))(auStack_90);
  return;
}


// ==== FUN_006c9cc0 @ 0x006c9cc0 ====

void FUN_006c9cc0(undefined4 param_1,int param_2,void *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  void **ppvStack_a4;
  undefined4 uStack_a0;
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
  void *pvStack_5c;
  undefined1 auStack_54 [8];
  undefined4 uStack_4c;
  uint uStack_48;
  undefined1 uStack_44;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  void *pvStack_20;
  undefined1 uStack_1c;
  int *piStack_c;
  int *piStack_8;
  
  uStack_a0 = 0x6c9cd5;
  piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_80._0_3_ = CONCAT12(1,(undefined2)uStack_80);
  iStack_7c = 0;
  pvStack_78 = (void *)0x0;
  iStack_74 = 0;
  iStack_70 = 0;
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  uStack_48 = 0xf;
  uStack_4c = 0;
  pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
  uStack_a0 = 0;
  ppvStack_a4 = (void **)0x6c9d17;
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 8))();
  ppvStack_a4 = (void **)0xffffffff;
  uStack_30 = 0xf;
  uStack_34 = 0;
  uStack_44 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  FUN_00401660(param_1,0);
  ppvStack_a4 = (void **)0xffffffff;
  FUN_00401660(&uStack_48,0);
  pvStack_78 = param_3;
  iStack_70 = (int)param_3 + 0x16;
  iStack_7c = param_2;
  ppvStack_a4 = (void **)0x6;
  iStack_74 = param_2 + 0x16;
  uStack_80 = 100;
  uStack_84 = 0;
  uStack_83 = 1;
  uStack_88 = 0;
  piStack_8 = (int *)0xf;
  piStack_c = (int *)0x0;
  uStack_1c = 0;
  FUN_00401740(s_buffer_009e35d0);
  ppvStack_a4 = &pvStack_20;
  (**(code **)(*DAT_00b5a7c0 + 8))();
  if ((int *)0xf < piStack_c) {
    _free(pvStack_20);
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
        iVar4 = (**(code **)(*piStack_c + 0x38))();
        piVar2[1] = iVar4;
      }
    }
  }
  (**(code **)(*piVar3 + 0x38))(piVar2);
  (**(code **)(*piVar3 + 0x1c))(auStack_54);
  (**(code **)(*piVar2 + 0x2c))(piVar3);
  FUN_00587d40(&ppvStack_a4);
  if (0xf < uStack_48) {
    _free(pvStack_5c);
    return;
  }
  uStack_48 = 0xf;
  uStack_4c = 0;
  pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
  if (uStack_64 < 0x10) {
    return;
  }
  _free(pvStack_78);
  return;
}


// ==== FUN_006c9ec0 @ 0x006c9ec0 ====

void FUN_006c9ec0(void)

{
  code *pcVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  uint unaff_EBP;
  uint uVar6;
  undefined1 *puVar7;
  undefined1 uVar8;
  uint uStack_dc;
  int local_d8;
  uint local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  void *pvStack_c8;
  undefined1 uStack_c4;
  undefined4 uStack_b8;
  uint uStack_b4;
  void *pvStack_b0;
  undefined1 local_ac [4];
  void *pvStack_a8;
  undefined4 uStack_a0;
  int *piStack_9c;
  int *piStack_98;
  uint uStack_94;
  undefined1 auStack_90 [4];
  void *pvStack_8c;
  undefined1 local_88;
  uint local_78;
  void *local_74;
  undefined4 uStack_64;
  uint uStack_60;
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
  
  local_74 = (void *)0xf;
  local_78 = 0;
  local_88 = 0;
  local_d4 = 0;
  local_d0 = 0;
  local_cc = 0;
  local_d8 = 3;
  do {
    FUN_00401740(s_pan_buffline__d_009e3538,0xf);
    puVar7 = local_ac;
    uVar3 = FUN_00404230(puVar7);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar3);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x24))(0);
    }
    if (0xf < uStack_94) {
      _free(pvStack_a8);
      return;
    }
    local_d8 = local_d8 + -1;
    uStack_94 = 0xf;
    piStack_98 = (int *)0x0;
    pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  } while (local_d8 != 0);
  *(undefined4 *)(in_ECX + 8) = 0;
  pvStack_b0 = (void *)0xf;
  uStack_b4 = 0;
  uStack_c4 = 0;
  local_d8 = 0;
  cVar2 = (**(code **)(*DAT_00b5ae84 + 0x18))(&pvStack_c8);
  while( true ) {
    if (cVar2 == '\0') {
      if (*(int *)(in_ECX + 8) == 0) {
        if (0xf < uStack_b4) {
          _free(pvStack_c8);
          return;
        }
        uStack_b4 = 0xf;
        uStack_b8 = 0;
        pvStack_c8 = (void *)((uint)pvStack_c8 & 0xffffff00);
        if (0xf < local_78) {
          _free(pvStack_8c);
          return;
        }
      }
      else {
        FUN_006c9b00();
        if (0xf < uStack_b4) {
          _free(pvStack_c8);
          return;
        }
        uStack_b4 = 0xf;
        uStack_b8 = 0;
        pvStack_c8 = (void *)((uint)pvStack_c8 & 0xffffff00);
        if (0xf < local_78) {
          _free(pvStack_8c);
          return;
        }
      }
      return;
    }
    if (*(uint *)(in_ECX + 8) == (uStack_dc & 0xffff) / 0xd) {
      uVar8 = 0;
      FUN_00401740(s_pan_buffline__d_009e3548,0xf);
      uVar3 = FUN_00404230(auStack_58,puVar7,uVar8);
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar3);
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x24))(1);
      }
      if (0xf < uStack_40) {
        _free(pvStack_54);
        return;
      }
      uStack_40 = 0xf;
      uStack_44 = 0;
      pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
      uVar6 = 0;
      do {
        uVar8 = 0;
        FUN_00401740(s_buffIcon__d_009e3558,0xb);
        uVar3 = FUN_00404230(auStack_3c,puVar7,uVar8);
        piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar3);
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 0x24))(0);
        }
        if (0xf < uStack_24) {
          _free(pvStack_38);
          return;
        }
        uVar6 = uVar6 + 1;
        uStack_24 = 0xf;
        uStack_28 = 0;
        pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
      } while (uVar6 < 0xd);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 1;
    }
    uVar8 = 0;
    FUN_00401740(s_buffIcon__d_009e3564,0xb);
    uVar3 = FUN_00404230(auStack_20,puVar7,uVar8);
    FUN_00401660(uVar3,0,0xffffffff);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    piStack_98 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_90);
    if (piStack_98 == (int *)0x0) break;
    iVar5 = (**(code **)(*piStack_98 + 0x30))();
    if (iVar5 == 0) {
      piStack_9c = (int *)0xf;
      uStack_a0 = 0;
      pvStack_b0 = (void *)((uint)pvStack_b0 & 0xffffff00);
      FUN_00401740(s_pPanel____NULL_009e3584,0xe);
      FUN_00406880(&uStack_b4);
      if (piStack_9c < 0x10) {
        piStack_9c = (int *)0xf;
        uStack_a0 = 0;
        pvStack_b0 = (void *)((uint)pvStack_b0 & 0xffffff00);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_b0);
      return;
    }
    uStack_dc = *(uint *)(iVar5 + 0x8c);
    local_d8 = *(int *)(iVar5 + 0x90);
    local_d4 = unaff_EBP >> 0x18;
    FUN_00587d40(&uStack_dc);
    FUN_00401660(&local_d4,0,0xffffffff);
    (**(code **)(*piStack_9c + 0x24))(1);
    cVar2 = (**(code **)(*DAT_00b5ae84 + 0x1c))(&local_d8);
  }
  uStack_60 = 0xf;
  uStack_64 = 0;
  local_74 = (void *)((uint)local_74 & 0xffffff00);
  FUN_00401740(s_pComposite____NULL_009e3570,0x12);
  FUN_00406880(&local_78);
  if (uStack_60 < 0x10) {
    uStack_60 = 0xf;
    uStack_64 = 0;
    local_74 = (void *)((uint)local_74 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_74);
  return;
}


// ==== FUN_006ca300 @ 0x006ca300 ====

void FUN_006ca300(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined1 local_38 [4];
  void *pvStack_34;
  undefined4 uStack_24;
  uint uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  uVar3 = 0;
  do {
    FUN_00401740(s_pan_buffline__d_009e35b4,0xf);
    uVar1 = FUN_00404230(local_38);
    iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar1);
    if (0xf < uStack_20) {
      _free(pvStack_34);
      return;
    }
    uVar3 = uVar3 + 1;
    uStack_20 = 0xf;
    uStack_24 = 0;
    pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
    *(uint *)(in_ECX + 8) = uVar3;
    if (iVar2 != 0) {
      uVar4 = 0;
      do {
        uVar6 = 0;
        uVar5 = uVar4;
        FUN_00401740(s_buffIcon__d_009e35c4,0xb);
        uVar1 = FUN_00404230(auStack_1c);
        FUN_006c9cc0(iVar2,uVar1,uVar5,uVar6);
        if (0xf < uStack_4) {
          _free(pvStack_18);
          return;
        }
        uVar4 = uVar4 + 0x15;
        uStack_4 = 0xf;
        uStack_8 = 0;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      } while (uVar4 < 0x111);
    }
  } while (uVar3 < 3);
  return;
}


// ==== FUN_006ca410 @ 0x006ca410 ====

void FUN_006ca410(void)

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
  FUN_00401740(s_UI_Game2_Mainbar_ui_buffwnd_txt_009e3518,0x1f);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_006ca300();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_006ca490 @ 0x006ca490 ====

undefined4 FUN_006ca490(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70200002) {
    FUN_006c9ec0();
    return 1;
  }
  return 0;
}


// ==== FUN_006ca4c0 @ 0x006ca4c0 ====

void FUN_006ca4c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e35e0;
  in_ECX[2] = 0;
  FUN_006ca410();
  return;
}


// ==== FUN_006ca4e0 @ 0x006ca4e0 ====

undefined4 FUN_006ca4e0(void)

{
  return 0x48;
}


// ==== FUN_006ca4f0 @ 0x006ca4f0 ====

void FUN_006ca4f0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009e35e0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ca530 @ 0x006ca530 ====

void FUN_006ca530(void)

{
  return;
}


// ==== FUN_006ca540 @ 0x006ca540 ====

void FUN_006ca540(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e384c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006ca560 @ 0x006ca560 ====

void FUN_006ca560(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  undefined1 uStack00000000;
  undefined1 auStack_12 [2];
  uint uStack_10;
  uint uStack_c;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ad54 + 4))(param_2);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(_uStack00000000);
  (**(code **)(*piVar2 + 0x30))();
  if (piVar1 == (int *)0x0) {
    FUN_005802c0(&uStack00000000,auStack_12 + -6);
    FUN_00580870(0,1);
    return;
  }
  (**(code **)(*piVar1 + 0x1c))();
  iVar3 = (**(code **)(*piVar1 + 0x2c))();
  uStack_c = (uint)*(byte *)(iVar3 + 0x31);
  uStack_10 = (uint)*(byte *)(iVar3 + 0x30);
  FUN_005802c0(auStack_12 + -10,&uStack_10);
  FUN_00580870(piVar1,0);
  return;
}


// ==== FUN_006ca640 @ 0x006ca640 ====

undefined4 FUN_006ca640(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  if (param_1 == 0xf) {
    if (param_3 == 1) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_item0_009e3814,5);
      if (iVar2 == 0) {
        (**(code **)(*DAT_00b5ad54 + 0x14))(0xf);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_item1_009e381c);
      if (cVar1 != '\0') {
        (**(code **)(*DAT_00b5ad54 + 0x14))(0x10);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_item2_009e3824);
      if (cVar1 != '\0') {
        (**(code **)(*DAT_00b5ad54 + 0x14))(0x11);
        return 1;
      }
    }
    else if (param_3 == 2) {
      cVar1 = FUN_004036a0(param_2,s_item0_009e382c);
      if (cVar1 != '\0') {
        (**(code **)(*DAT_00b5ad54 + 0x10))(0xf);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_item1_009e3834);
      if (cVar1 != '\0') {
        (**(code **)(*DAT_00b5ad54 + 0x10))(0x10);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_item2_009e383c);
      if (cVar1 != '\0') {
        (**(code **)(*DAT_00b5ad54 + 0x10))(0x11);
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_006ca750 @ 0x006ca750 ====

undefined4 FUN_006ca750(void)

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
  FUN_00401740(s_pan_bg_009e36c4,6);
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
      iVar2 = (**(code **)(*DAT_00b5a74c + 0xc))(0x46);
      if (iVar2 != 0) {
        iVar2 = *DAT_00b5ad54;
        uVar4 = FUN_0065deb0(auStack_22 + -0xe);
        (**(code **)(iVar2 + 0x2c))(uVar4);
      }
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006ca820 @ 0x006ca820 ====

void FUN_006ca820(undefined4 param_1,int param_2)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  bool bVar5;
  undefined4 unaff_retaddr;
  undefined4 uStack_20;
  void *pvStack_1c;
  int iStack_c;
  uint uStack_8;
  
  uStack_20 = param_1;
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar2 == (int *)0x0) {
    return;
  }
  iStack_c = (**(code **)(*piVar2 + 0x30))();
  if (iStack_c == 0) {
    uStack_8 = 0xf;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_pItemCtrl____NULL_009e3744,0x11);
    FUN_00406880(&uStack_20);
    if (uStack_8 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_1c);
    return;
  }
  iVar3 = FUN_0057f270();
  if (iVar3 == 0) {
    return;
  }
  iVar3 = *DAT_00b5ad20;
  uVar4 = FUN_0057f270();
  iVar3 = (**(code **)(iVar3 + 0x18))(uVar4);
  if (param_2 == 1) {
    bVar5 = iVar3 == 0xc;
  }
  else if (param_2 == 0) {
    if (((iVar3 == 1) || (iVar3 == 2)) || ((iVar3 == 0xc || (iVar3 == 0x11)))) goto LAB_006ca8f1;
    bVar5 = iVar3 == 0x12;
  }
  else {
    if (((param_2 != 3) || (iVar3 == 0x902)) || (iVar3 == 0x900)) goto LAB_006ca8f1;
    bVar5 = iVar3 == 0x901;
  }
  if (!bVar5) {
    return;
  }
LAB_006ca8f1:
  FUN_0057f480(unaff_retaddr,param_1);
  return;
}


// ==== FUN_006ca910 @ 0x006ca910 ====

void FUN_006ca910(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined4 uStack_20;
  void *pvStack_1c;
  int iStack_c;
  uint uStack_8;
  
  uStack_20 = param_1;
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x30))();
    if (iVar3 == 0) {
      uStack_8 = 0xf;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      iStack_c = iVar3;
      FUN_00401740(s_pItemCtrl____NULL_009e3758,0x11);
      FUN_00406880(&uStack_20);
      if (uStack_8 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_1c);
      return;
    }
    iVar4 = FUN_0057f270();
    if (iVar4 != 0) {
      *(undefined1 *)(iVar3 + 0xe0) = 0;
    }
  }
  return;
}


// ==== FUN_006ca990 @ 0x006ca990 ====

void FUN_006ca990(undefined4 param_1)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int in_ECX;
  undefined4 uStack_20;
  void *pvStack_1c;
  void *pvStack_18;
  undefined4 uStack_10;
  int *piStack_c;
  int *piStack_8;
  int *piStack_4;
  
  iVar3 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if (iVar3 != 0) {
    piVar6 = *(int **)(iVar3 + 0x78);
    uStack_20 = piVar6;
    if (piVar6 == (int *)0x0) {
      piStack_4 = (int *)0xf;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      piStack_8 = piVar6;
      FUN_00401740(s_pCoolTimeManager____NULL_009e36e4,0x18);
      FUN_00406880(&pvStack_1c);
      if (piStack_4 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_18);
      return;
    }
    piVar4 = (int *)(**(code **)(*piVar6 + 0x20))(param_1);
    if (piVar4 == (int *)0x0) {
      piStack_8 = (int *)0xf;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      piStack_c = piVar4;
      FUN_00401740(s_pCoolTime____NULL_009e3700,0x11);
      FUN_00406880(&uStack_20);
      if (piStack_8 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_1c);
      return;
    }
    iVar3 = *piVar6;
    uVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    (**(code **)(iVar3 + 0x18))(uVar5);
    cVar2 = (**(code **)(*piVar4 + 0xc))();
    if (cVar2 == '\x01') {
      if (*(char *)(in_ECX + 8) != '\0') {
        FUN_00401830(s_item0_009e3714);
        FUN_006ca910((int)register0x00000010 + -0x24,param_1);
        if (0xf < piStack_c) {
          _free(uStack_20);
          return;
        }
        FUN_00401830(s_item1_009e371c);
        FUN_006ca910((int)register0x00000010 + -0x24,param_1);
        if (0xf < piStack_c) {
          _free(uStack_20);
          return;
        }
        FUN_00401830(s_item2_009e3724);
        FUN_006ca910((int)register0x00000010 + -0x24,param_1);
        if (piStack_c < 0x10) {
          *(undefined1 *)(in_ECX + 8) = 0;
          return;
        }
        _free(uStack_20);
        return;
      }
    }
    else {
      *(undefined1 *)(in_ECX + 8) = 1;
      iVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      piVar6 = (int *)(**(code **)(*piVar4 + 0x18))();
      iVar3 = iVar3 - *piVar6;
      piStack_4 = (int *)(**(code **)(*piVar4 + 0x18))();
      iVar7 = (**(code **)(*piVar4 + 0x18))();
      iVar7 = *(int *)(iVar7 + 4) - *piStack_4;
      piStack_c = (int *)0xf;
      uStack_10 = 0;
      uStack_20 = (int *)((uint)uStack_20 & 0xffffff00);
      FUN_00401740(s_item0_009e372c,5);
      FUN_006ca820((int)register0x00000010 + -0x24,iVar3,iVar7,param_1);
      if (0xf < piStack_c) {
        _free(uStack_20);
        return;
      }
      piStack_c = (int *)0xf;
      uStack_10 = 0;
      uStack_20 = (int *)((uint)uStack_20 & 0xffffff00);
      FUN_00401740(s_item1_009e3734,5);
      FUN_006ca820((int)register0x00000010 + -0x24,iVar3,iVar7,param_1);
      if (0xf < piStack_c) {
        _free(uStack_20);
        return;
      }
      piStack_c = (int *)0xf;
      uStack_10 = 0;
      uStack_20 = (int *)((uint)uStack_20 & 0xffffff00);
      FUN_00401740(s_item2_009e373c,5);
      FUN_006ca820((int)register0x00000010 + -0x24,iVar3,iVar7,param_1);
      if (0xf < piStack_c) {
        _free(uStack_20);
        return;
      }
    }
  }
  return;
}


// ==== FUN_006cac30 @ 0x006cac30 ====

void FUN_006cac30(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *unaff_ESI;
  undefined4 auStack_20 [4];
  uint uStack_10;
  
  auStack_20[0] = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    uVar3 = (**(code **)(*DAT_00b5ad54 + 0xc))(auStack_20,param_1);
    FUN_00401660(uVar3,0,0xffffffff);
    if (0xf < uStack_10) {
      _free(unaff_ESI);
      return;
    }
  }
  return;
}


// ==== FUN_006cac90 @ 0x006cac90 ====

void FUN_006cac90(void)

{
  FUN_006ca990(0);
  FUN_006ca990(1);
  FUN_006ca990(3);
  return;
}


// ==== FUN_006cacb0 @ 0x006cacb0 ====

/* WARNING: Removing unreachable block (ram,0x006cb26d) */
/* WARNING: Removing unreachable block (ram,0x006cb433) */

void FUN_006cacb0(void)

{
  void *pvVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_ESI;
  undefined4 uStack_4c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  void *pvStack_30;
  void *pvStack_2c;
  void *pvStack_28;
  void *pvStack_24;
  void *pvStack_20;
  void *pvStack_1c;
  uint uStack_18;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint uStack_8;
  
  uVar5 = (uint)uStack_38;
  uStack_4c = (void *)0xf;
  uVar2 = (**(code **)(*DAT_00b5ad54 + 8))();
  pvStack_24 = (void *)0xf;
  pvStack_28 = (void *)0x0;
  uStack_38 = (void *)((uint)uStack_38 & 0xffffff00);
  pvVar1 = uStack_38;
  FUN_00401740(s_item0_009e376c);
  FUN_006cac30((int)register0x00000010 + -0x3c);
  if ((void *)0xf < pvStack_24) {
    _free(uStack_38);
    return;
  }
  uStack_38._1_3_ = SUB43(uVar5,1);
  if (uVar2 == 0) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c._1_3_ << 8);
    FUN_00401740(&DAT_009e3772);
    pvStack_24 = (void *)0xf;
    pvStack_28 = (void *)0x0;
    uStack_38 = (void *)((uint)uStack_38._1_3_ << 8);
    FUN_00401740(s_lbl_item0_009e3774);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
      FUN_0055a260(&pvStack_24);
    }
    if ((void *)0xf < pvStack_28) {
      _free(unaff_EBX);
      return;
    }
    pvStack_28 = (void *)0xf;
    pvStack_2c = (void *)0x0;
    if (0xf < uStack_c) goto LAB_006caf2d;
  }
  else if (uVar2 < 10000) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c._1_3_ << 8);
    FUN_00401740(s_lbl_item0_009e3784);
    FUN_00401740(&DAT_009e3780,2);
    uVar6 = FUN_00404230((int)register0x00000010 + -0x3c);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
      FUN_0055a260(uVar6);
    }
    if ((void *)0xf < pvStack_28) {
      _free(unaff_EBX);
      return;
    }
    pvStack_28 = (void *)0xf;
    pvStack_2c = (void *)0x0;
    uStack_38 = pvVar1;
    if (0xf < uStack_c) goto LAB_006caf2d;
  }
  else {
    pvStack_24 = (void *)0xf;
    pvStack_28 = (void *)0x0;
    uStack_38 = (void *)((uint)uStack_38._1_3_ << 8);
    FUN_00401740(&DAT_009e3790);
    FUN_00401740(&DAT_009e3794,2);
    uVar6 = FUN_00404230(&pvStack_20);
    FUN_00401ff0(uVar6,0);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_lbl_item0_009e3798);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
      FUN_0055a260((int)register0x00000010 + -0x40);
    }
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return;
    }
    if ((void *)0xf < pvStack_28) {
      pvStack_20 = unaff_EBX;
LAB_006caf2d:
      _free(pvStack_20);
      return;
    }
  }
  uVar5 = (**(code **)(*DAT_00b5ad54 + 8))(0x10);
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_item1_009e37a4,5);
  FUN_006cac30(&pvStack_28,0x10);
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return;
  }
  if (uVar5 == 0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24._1_3_ << 8);
    FUN_00401740(&DAT_009e37aa,0);
    pvStack_2c = (void *)0xf;
    pvStack_30 = (void *)0x0;
    FUN_00401740(s_lbl_item1_009e37ac,9);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x44);
    if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
      FUN_0055a260(&pvStack_2c);
    }
    if ((void *)0xf < pvStack_30) {
      _free(unaff_ESI);
      return;
    }
    pvStack_30 = (void *)0xf;
    uStack_34 = 0;
    if (uStack_14 < 0x10) goto LAB_006cb1ac;
    unaff_ESI = pvStack_28;
  }
  else {
    if (uVar5 < 10000) {
      uStack_10 = 0xf;
      uStack_14 = 0;
      pvStack_24 = (void *)((uint)pvStack_24._1_3_ << 8);
      FUN_00401740(s_lbl_item1_009e37bc,9);
      FUN_00401740(&DAT_009e37b8,2);
      uVar6 = FUN_00404230((int)register0x00000010 + -0x44);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_28);
      if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
        FUN_0055a260(uVar6);
      }
      if ((void *)0xf < pvStack_30) {
        _free(unaff_ESI);
        return;
      }
      pvStack_30 = (void *)0xf;
      uStack_34 = 0;
      if (uStack_14 < 0x10) goto LAB_006cb1ac;
      unaff_ESI = pvStack_28;
      goto LAB_006cb1a4;
    }
    pvStack_2c = (void *)0xf;
    pvStack_30 = (void *)0x0;
    FUN_00401740(&DAT_009e37c8,2);
    FUN_00401740(&DAT_009e37cc,2);
    uVar6 = FUN_00404230(&pvStack_28);
    FUN_00401ff0(uVar6,0,0xffffffff);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_lbl_item1_009e37d0,9);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_28);
    if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
      FUN_0055a260((int)register0x00000010 + -0x48);
    }
    if (0xf < uStack_14) {
      _free(pvStack_28);
      return;
    }
    if (pvStack_30 < (void *)0x10) {
LAB_006cb1ac:
      uVar5 = (**(code **)(*DAT_00b5ad54 + 8))(0x11);
      uStack_18 = 0xf;
      pvStack_1c = (void *)0x0;
      pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
      FUN_00401740(s_item2_009e37dc,5);
      FUN_006cac30(&pvStack_30,0x11);
      if (0xf < uStack_18) {
        _free(pvStack_2c);
        return;
      }
      if (uVar5 == 0) {
        uStack_18 = 0xf;
        pvStack_1c = (void *)0x0;
        pvStack_2c = (void *)((uint)pvStack_2c._1_3_ << 8);
        FUN_00401740(&DAT_009e37e2,0);
        uStack_34 = 0xf;
        FUN_00401740(s_lbl_item2_009e37e4,9);
        piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_4c);
        if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
          FUN_0055a260(&uStack_34);
        }
        uStack_4c = (void *)((uint)uStack_4c & 0xffffff00);
        if (0xf < pvStack_1c) {
          _free(pvStack_30);
          return;
        }
      }
      else if (uVar5 < 10000) {
        uStack_18 = 0xf;
        pvStack_1c = (void *)0x0;
        pvStack_2c = (void *)((uint)pvStack_2c._1_3_ << 8);
        FUN_00401740(s_lbl_item2_009e37f4,9);
        FUN_00401740(&DAT_009e37f0,2);
        uVar6 = FUN_00404230(&uStack_4c);
        piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_30);
        if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
          FUN_0055a260(uVar6);
        }
        if ((void *)0xf < uStack_38) {
          _free(uStack_4c);
          return;
        }
        uStack_4c = (void *)((uint)uStack_4c & 0xffffff00);
        if (0xf < pvStack_1c) {
          _free(pvStack_30);
          return;
        }
      }
      else {
        uStack_34 = 0xf;
        FUN_00401740(&DAT_009e3800,2);
        FUN_00401740(&DAT_009e3804,2);
        uVar6 = FUN_00404230(&pvStack_30);
        FUN_00401ff0(uVar6,0,0xffffffff);
        if (0xf < uStack_18) {
          _free(pvStack_2c);
          return;
        }
        uStack_18 = 0xf;
        pvStack_1c = (void *)0x0;
        pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
        FUN_00401740(s_lbl_item2_009e3808,9);
        piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_30);
        if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
          FUN_0055a260((int)register0x00000010 + -0x50);
        }
        if (0xf < pvStack_1c) {
          _free(pvStack_30);
          return;
        }
      }
      return;
    }
  }
LAB_006cb1a4:
  _free(unaff_ESI);
  return;
}


// ==== FUN_006cb450 @ 0x006cb450 ====

void FUN_006cb450(void)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_item0_009e36cc,5);
  FUN_006ca560(local_1c,0xf);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_item1_009e36d4,5);
  FUN_006ca560(local_1c,0x10);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_item2_009e36dc,5);
  FUN_006ca560(local_1c,0x11);
  if (local_4 < 0x10) {
    FUN_006cacb0();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_006cb530 @ 0x006cb530 ====

/* WARNING: Removing unreachable block (ram,0x006cb71d) */
/* WARNING: Removing unreachable block (ram,0x006cb676) */
/* WARNING: Removing unreachable block (ram,0x006cb5d3) */
/* WARNING: Removing unreachable block (ram,0x006cb62d) */
/* WARNING: Removing unreachable block (ram,0x006cb6d0) */
/* WARNING: Removing unreachable block (ram,0x006cb776) */
/* WARNING: Removing unreachable block (ram,0x006cb572) */

void FUN_006cb530(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined4 uStack_34;
  
  uStack_34 = s_UI_Game2_Mainbar_ui_ItemBeltWnd__009e364c;
  FUN_00401740();
  uStack_34 = (char *)0x6cb566;
  iVar2 = FUN_00410500();
  uStack_34 = (char *)(iVar2 + 0x3c);
  piVar3 = (int *)(**(code **)(*DAT_00b5a798 + 4))();
  *(int **)(in_ECX + 4) = piVar3;
  (**(code **)(*piVar3 + 0x40))();
  FUN_006cb450();
  FUN_00401740(s_item0_009e3670,5);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x28);
  if (piVar3 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar3 + 0x30))();
    if (iVar2 == 0) {
      FUN_00401740(s_pItemCtrl____NULL_009e3678,0x11);
      FUN_00406880((int)register0x00000010 + -0x2c);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_0057f910(1);
  }
  FUN_00401740(s_item1_009e368c,5);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x2c);
  if (piVar3 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar3 + 0x30))();
    if (iVar2 == 0) {
      FUN_00401740(s_pItemCtrl____NULL_009e3694,0x11);
      FUN_00406880((int)register0x00000010 + -0x30);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_0057f910(1);
  }
  FUN_00401740(s_item2_009e36a8,5);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x30);
  if (piVar3 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar3 + 0x30))();
    if (iVar2 == 0) {
      FUN_00401740(s_pItemCtrl____NULL_009e36b0,0x11);
      FUN_00406880(&uStack_34);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_0057f910(1);
  }
  return;
}


// ==== FUN_006cb7a0 @ 0x006cb7a0 ====

undefined4 FUN_006cb7a0(int *param_1)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = (**(code **)(*param_1 + 4))();
  if (uVar2 < 0x70050003) {
    if (uVar2 == 0x70050002) {
      FUN_006cb450();
      *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 1;
      if ((char)param_1[1] == '\x0f') {
        return 1;
      }
    }
    else if (uVar2 == 0x10003) {
      cVar1 = FUN_006ca750(param_1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
    else if (uVar2 == 0x40001) {
      FUN_006cac90();
      return 0;
    }
  }
  else if (uVar2 == 0x7005000b) {
    FUN_006cacb0();
    return 1;
  }
  return 0;
}


// ==== FUN_006cb820 @ 0x006cb820 ====

void FUN_006cb820(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e384c;
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_006cb530();
  return;
}


// ==== FUN_006cb840 @ 0x006cb840 ====

undefined4 FUN_006cb840(void)

{
  return 0x46;
}


// ==== FUN_006cb850 @ 0x006cb850 ====

void FUN_006cb850(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009e384c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006cb890 @ 0x006cb890 ====

void FUN_006cb890(void)

{
  return;
}


// ==== FUN_006cb8d0 @ 0x006cb8d0 ====

void FUN_006cb8d0(int param_1)

{
  int in_ECX;
  
  FUN_0069a470(&param_1,param_1);
  if (param_1 != *(int *)(in_ECX + 0xc)) {
    (**(code **)(*DAT_00b5ad54 + 0x54))(0,*(undefined4 *)(param_1 + 0x28));
  }
  return;
}


// ==== FUN_006cb940 @ 0x006cb940 ====

undefined4 FUN_006cb940(void)

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
  FUN_00401740(s_pan_bg_009e38e8,6);
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
      iVar2 = (**(code **)(*DAT_00b5a74c + 0xc))(0x45);
      if (iVar2 != 0) {
        iVar2 = *DAT_00b5ad54;
        uVar4 = FUN_0065deb0(auStack_22 + -0xe);
        (**(code **)(iVar2 + 0x28))(uVar4);
      }
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006cba10 @ 0x006cba10 ====

void FUN_006cba10(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  uint uVar3;
  undefined1 local_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  uVar3 = 0;
  do {
    FUN_00401740(s_slot__d_009e39e4,7);
    uVar1 = FUN_00404230(local_1c);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar1);
    (**(code **)(*piVar2 + 0x30))();
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_0057b0f0();
    uVar3 = uVar3 + 1;
  } while (uVar3 < 9);
  return;
}


// ==== FUN_006cbaa0 @ 0x006cbaa0 ====

void FUN_006cbaa0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  
  iVar2 = param_1;
  FUN_0069a470(&param_1,param_1);
  if (param_1 != *(int *)(in_ECX + 0xc)) {
    uVar1 = *(undefined4 *)(param_1 + 0x28);
    iVar3 = (**(code **)(*DAT_00b5ad54 + 0x38))(uVar1);
    iVar4 = (**(code **)(*DAT_00b5acb8 + 0x1c))();
    if (iVar3 == 0) {
      if (iVar4 != 0) {
        iVar3 = *DAT_00b5ad54;
LAB_006cbaee:
        (**(code **)(iVar3 + 0x54))(iVar4,uVar1);
        (**(code **)(*DAT_00b5acb8 + 0x20))();
        return;
      }
    }
    else {
      iVar3 = *DAT_00b5ad54;
      if (iVar4 != 0) goto LAB_006cbaee;
      (**(code **)(iVar3 + 0x40))(uVar1);
      FUN_00401660(iVar2,0,0xffffffff);
    }
  }
  return;
}


// ==== FUN_006cbb30 @ 0x006cbb30 ====

void FUN_006cbb30(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  int iVar7;
  void *local_1c;
  void *pvStack_18;
  undefined4 uStack_c;
  uint uStack_8;
  uint uStack_4;
  
  uVar6 = 0;
  do {
    FUN_00401740(s_slot__d_009e39ec,7);
    uVar1 = FUN_00404230(&local_1c);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar1);
    iVar3 = (**(code **)(*piVar2 + 0x30))();
    if (0xf < uStack_8) {
      _free(local_1c);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    piVar2 = (int *)(**(code **)(*DAT_00b5ad54 + 0x38))(uVar6);
    if (piVar2 != (int *)0x0) {
      piVar4 = (int *)(**(code **)(*piVar2 + 0x20))();
      iVar5 = (**(code **)(*piVar4 + 4))();
      if (iVar5 == 0) {
        FUN_0057b1f0();
      }
      else {
        piVar4 = (int *)(**(code **)(*piVar2 + 0x20))();
        iVar5 = (**(code **)(*piVar4 + 4))();
        if ((iVar5 == 3) && (*(char *)(iVar3 + 0xdc) != '\x02')) {
          piVar4 = (int *)(**(code **)(*piVar2 + 0x18))();
          iVar3 = (**(code **)(*piVar4 + 0x10))();
          iVar3 = *(int *)(iVar3 + 8);
          piVar2 = (int *)(**(code **)(*piVar2 + 0x18))();
          iVar5 = (**(code **)(*piVar2 + 0x10))();
          iVar7 = *(int *)(iVar5 + 0x14) - iVar3;
          iVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
          if (iVar7 == 0) {
            FUN_00401830(&DAT_009e39f4);
            FUN_00796d50(&local_1c);
            if (uStack_4 < 0x10) {
              return;
            }
            _free(pvStack_18);
            return;
          }
          FUN_0057aa60(iVar5 - iVar3,iVar7);
        }
      }
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 < 9);
  return;
}


// ==== FUN_006cbc90 @ 0x006cbc90 ====

undefined4 FUN_006cbc90(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  
  if (param_1 != 0x12) {
    if ((param_1 == 1) && (param_3 == 1)) {
      cVar1 = FUN_004036a0(param_2,s_btn_slot_up_009e38f0);
      if (cVar1 != '\0') {
        (**(code **)(*DAT_00b5ad54 + 0x4c))();
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_slot_down_009e38fc);
      if (cVar1 != '\0') {
        (**(code **)(*DAT_00b5ad54 + 0x50))();
        return 1;
      }
    }
    return 0;
  }
  if (param_3 == 1) {
    FUN_006cbaa0(param_2);
    return 1;
  }
  if (param_3 != 0xb) {
    if (param_3 == 10) {
      FUN_006cba10();
      return 1;
    }
    if (param_3 == 2) {
      FUN_006cb8d0(param_2);
      return 1;
    }
    if (param_3 != 4) {
      if (param_3 == 5) {
        return 1;
      }
      return 0;
    }
  }
  return 1;
}


// ==== FUN_006cbd50 @ 0x006cbd50 ====

void FUN_006cbd50(void)

{
  undefined4 *in_ECX;
  undefined1 auStack_2 [2];
  
  *in_ECX = &PTR_FUN_009e3a0c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if ((uint)in_ECX[0xb] < 0x10) {
    in_ECX[0xb] = 0xf;
    in_ECX[10] = 0;
    *(undefined1 *)(in_ECX + 6) = 0;
    FUN_004a7020(auStack_2 + -6,*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3]);
    _free((void *)in_ECX[3]);
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_006cbdc0 @ 0x006cbdc0 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Removing unreachable block (ram,0x006cc10d) */
/* WARNING: Removing unreachable block (ram,0x006cc20f) */
/* WARNING: Removing unreachable block (ram,0x006cc022) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_006cbdc0(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  byte *pbVar4;
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int extraout_EAX_02;
  int extraout_EAX_03;
  int extraout_EAX_04;
  int extraout_EAX_05;
  int extraout_EAX_06;
  int extraout_EAX_07;
  int extraout_EAX_08;
  int extraout_EAX_09;
  int extraout_EAX_10;
  int extraout_EAX_11;
  undefined4 unaff_EBP;
  void *unaff_ESI;
  undefined1 *puVar5;
  uint in_stack_ffffd2b4;
  undefined1 auStack_2d12 [10];
  undefined1 auStack_2d08 [4];
  void *pvStack_2d04;
  undefined1 auStack_2cf4 [4];
  void *pvStack_2cf0;
  undefined1 uStack_2ce0;
  uint uStack_2cdc;
  void *pvStack_2cd4;
  undefined4 uStack_2cd0;
  uint uStack_2ccc;
  undefined4 uStack_2cc4;
  uint uStack_2cc0;
  undefined4 uStack_2cbc;
  void *pvStack_2cb8;
  undefined1 uStack_2cb0;
  undefined4 uStack_2ca8;
  uint uStack_2ca4;
  undefined4 uStack_2ca0;
  void *pvStack_2c9c;
  undefined4 uStack_2c8c;
  uint uStack_2c88;
  void *pvStack_2c80;
  undefined1 auStack_2c7c [4];
  undefined1 uStack_2c78;
  undefined4 uStack_2c70;
  uint uStack_2c6c;
  undefined4 uStack_2c68;
  undefined4 uStack_2c64;
  short sStack_2c5a;
  undefined4 uStack_2c58;
  undefined4 uStack_2c54;
  undefined4 uStack_2bf8;
  undefined4 uStack_2bf4;
  int iStack_2bf0;
  undefined1 auStack_2bc8 [11180];
  undefined2 uStack_1c;
  undefined2 uStack_14;
  int iStack_c;
  undefined4 uStack_4;
  
  uStack_4 = 0x6cbdca;
  piVar1 = (int *)(**(code **)(*param_2 + 0x18))();
  piVar2 = (int *)(**(code **)(*param_2 + 0x10))();
  uVar3 = (**(code **)(*piVar2 + 4))();
  FUN_006afd30(uVar3);
  pbVar4 = (byte *)(**(code **)(*piVar1 + 0xc))();
  FUN_006afbf0(auStack_2bc8 + (uint)(*pbVar4 & 0xf) * 0x80);
  uStack_2c54 = uStack_2bf4;
  uStack_2c58 = uStack_2bf8;
  uStack_2ccc = 0xf;
  uStack_2cd0 = 0;
  uStack_2ce0 = 0;
  FUN_004020e0(s_<font_3>_009e3950,8);
  FUN_004020e0(s_<color_C1C1FF>_009e395c,0xe);
  uVar3 = (**(code **)(*DAT_00b5ace8 + 8))(uStack_14,0);
  uStack_2c64 = 0xf;
  uStack_2c68 = 0;
  uStack_2c78 = 0;
  FUN_00401660(uVar3,0,0xffffffff);
  FUN_00401ff0(auStack_2c7c,0,0xffffffff);
  FUN_00401740(s_Lv_d_009e396c,5);
  puVar5 = auStack_2d08;
  uVar3 = FUN_00404230(puVar5);
  FUN_00401ff0(uVar3,0,0xffffffff);
  if ((void *)0xf < pvStack_2cf0) {
    _free(pvStack_2d04);
    return extraout_EAX;
  }
  FUN_004020e0(s_<_color>_009e3974,8);
  FUN_004020e0(s_<_font>___009e3980,9);
  FUN_004020e0(s_<font_2>_009e398c,8);
  pvStack_2cb8 = (void *)0xf;
  uStack_2cbc = 0;
  uStack_2ccc = uStack_2ccc & 0xffffff00;
  pvStack_2c9c = (void *)0xf;
  uStack_2ca0 = 0;
  uStack_2cb0 = 0;
  if (sStack_2c5a != 0) {
    FUN_00401740(s_<VALUE>_009e3998,7);
    FUN_00401740(&DAT_009e39a0,3);
    puVar5 = auStack_2d08;
    uVar3 = FUN_00404230(puVar5);
    FUN_00401660(uVar3,0,0xffffffff);
    if ((void *)0xf < pvStack_2cf0) {
      _free(pvStack_2d04);
      return extraout_EAX_00;
    }
    FUN_004e6c20();
    uVar3 = (**(code **)(*DAT_00b5a794 + 8))(auStack_2d08,2,0x70);
    FUN_00401ff0(uVar3,0,0xffffffff);
    if ((void *)0xf < pvStack_2cf0) {
      _free(pvStack_2d04);
      return extraout_EAX_01;
    }
  }
  if ((short)uStack_2bf8 != 0) {
    FUN_00401740(s_<VALUE>_009e39a4,7);
    FUN_00401740(&DAT_009e39ac,3);
    puVar5 = auStack_2d08;
    uVar3 = FUN_00404230(puVar5);
    FUN_00401660(uVar3,0,0xffffffff);
    if ((void *)0xf < pvStack_2cf0) {
      _free(pvStack_2d04);
      return extraout_EAX_02;
    }
    FUN_004e6c20();
    uVar3 = (**(code **)(*DAT_00b5a794 + 8))(auStack_2d08,2,0x71);
    FUN_00401ff0(uVar3,0,0xffffffff);
    if ((void *)0xf < pvStack_2cf0) {
      _free(pvStack_2d04);
      return extraout_EAX_03;
    }
  }
  if (iStack_2bf0 != 0) {
    FUN_00401740(s_<VALUE>_009e39b0,7);
    in_stack_ffffd2b4 = in_stack_ffffd2b4 & 0xffffff00;
    FUN_00401740(s__4_1f__009e39b8,6);
    uVar3 = FUN_00404230(auStack_2d08,puVar5,in_stack_ffffd2b4);
    FUN_00401660(uVar3,0,0xffffffff);
    if ((void *)0xf < pvStack_2cf0) {
      _free(pvStack_2d04);
      return extraout_EAX_04;
    }
    FUN_004e6c20();
    uVar3 = (**(code **)(*DAT_00b5a794 + 8))(auStack_2d08,2,0x72);
    FUN_00401ff0(uVar3,0,0xffffffff);
    if ((void *)0xf < pvStack_2cf0) {
      _free(pvStack_2d04);
      return extraout_EAX_05;
    }
  }
  FUN_004020e0(s_<color_FDDE5C>_009e39c0,0xe);
  uVar3 = (**(code **)(*DAT_00b5ace8 + 8))(uStack_1c,1);
  uStack_2c88 = 0xf;
  uStack_2c8c = 0;
  pvStack_2c9c = (void *)((uint)pvStack_2c9c & 0xffffff00);
  FUN_00401660(uVar3,0,0xffffffff);
  FUN_00401ff0(&uStack_2ca0,0,0xffffffff);
  FUN_004020e0(s_<_color>_009e39d0,8);
  FUN_004020e0(s_<_font>_009e39dc,7);
  *(undefined4 *)(iStack_c + 0x18) = 0xf;
  *(undefined4 *)(iStack_c + 0x14) = 0;
  *(undefined1 *)(iStack_c + 4) = 0;
  FUN_00401660(auStack_2cf4,0,0xffffffff);
  if (0xf < uStack_2c88) {
    _free(pvStack_2c9c);
    return extraout_EAX_06;
  }
  uStack_2c88 = 0xf;
  uStack_2c8c = 0;
  pvStack_2c9c = (void *)((uint)pvStack_2c9c & 0xffffff00);
  if (0xf < uStack_2ca4) {
    _free(pvStack_2cb8);
    return extraout_EAX_07;
  }
  uStack_2ca4 = 0xf;
  uStack_2ca8 = 0;
  pvStack_2cb8 = (void *)((uint)pvStack_2cb8 & 0xffffff00);
  if (0xf < uStack_2cc0) {
    _free(pvStack_2cd4);
    return extraout_EAX_08;
  }
  uStack_2cc0 = 0xf;
  uStack_2cc4 = 0;
  pvStack_2cd4 = (void *)((uint)pvStack_2cd4 & 0xffffff00);
  if (unaff_ESI != (void *)0x0) {
    FUN_004e65b0(unaff_ESI,unaff_EBP,auStack_2d12 + -0x12,0);
    _free(unaff_ESI);
    return extraout_EAX_09;
  }
  if (0xf < uStack_2c6c) {
    _free(pvStack_2c80);
    return extraout_EAX_10;
  }
  uStack_2c6c = 0xf;
  uStack_2c70 = 0;
  pvStack_2c80 = (void *)((uint)pvStack_2c80 & 0xffffff00);
  if (uStack_2cdc < 0x10) {
    FUN_0047f180();
    return iStack_c;
  }
  _free(pvStack_2cf0);
  return extraout_EAX_11;
}


// ==== FUN_006cc3f0 @ 0x006cc3f0 ====

void FUN_006cc3f0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  int unaff_EBX;
  int iVar7;
  byte bVar8;
  undefined4 uStack_b0;
  uint uStack_a8;
  void *pvStack_a4;
  undefined1 uStack_a0;
  undefined4 uStack_94;
  uint uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  uint uStack_80;
  int iStack_7c;
  int *piStack_78;
  int iStack_74;
  undefined1 auStack_70 [4];
  void *pvStack_6c;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  undefined4 uStack_40;
  uint uStack_3c;
  void *pvStack_38;
  void *pvStack_34;
  uint uStack_24;
  uint uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x74) + 0x14))();
    iVar1 = (**(code **)(*piVar2 + 8))();
    uStack_b0 = CONCAT13(*(undefined1 *)(iVar1 + 4),(undefined3)uStack_b0);
    iVar1 = uStack_b0;
    iStack_7c = (**(code **)(*DAT_00b5ad54 + 0x44))();
    uStack_a8 = 0;
    do {
      piVar2 = (int *)(**(code **)(*DAT_00b5ad54 + 0x38))(uStack_a8);
      piStack_78 = piVar2;
      FUN_00401740(s_slot__d_009e390c,7);
      uVar3 = FUN_00404230(&uStack_3c);
      piVar4 = (int *)(**(code **)(**(int **)(iVar1 + 4) + 0x34))(uVar3);
      piStack_78 = (int *)(**(code **)(*piVar4 + 0x30))();
      if (0xf < uStack_20) {
        _free(pvStack_34);
        return;
      }
      uStack_20 = 0xf;
      uStack_24 = 0;
      pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
      if (piStack_78 == (int *)0x0) {
        uStack_58 = 0xf;
        uStack_5c = 0;
        pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
        FUN_00401740(&DAT_009e3914,0x1f);
        FUN_00796d50(auStack_70);
        if (0xf < uStack_58) {
          _free(pvStack_6c);
          return;
        }
        uStack_58 = 0xf;
        uStack_5c = 0;
        pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
      }
      else if ((piVar2 == (int *)0x0) ||
              (piVar2 = (int *)(**(code **)(*piVar2 + 0x10))(), piVar2 == (int *)0x0)) {
        FUN_0057b2f0();
        uStack_3c = 0xf;
        uStack_40 = 0;
        pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
        FUN_0057ae50(auStack_54);
        FUN_0057abb0();
        if (0xf < uStack_3c) {
          _free(pvStack_50);
          return;
        }
        uStack_3c = 0xf;
        uStack_40 = 0;
        pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
      }
      else {
        uStack_84 = 0;
        uStack_80 = 0;
        uStack_88 = 0xffffffff;
        uStack_8c = 0xf;
        uStack_90 = 0;
        uStack_a0 = 0;
        FUN_00401740(s_skill_icon_009e3934,10);
        uStack_88 = (**(code **)(*DAT_00b5a7c0 + 8))(&pvStack_a4);
        if (0xf < uStack_90) {
          _free(pvStack_a4);
          return;
        }
        uStack_90 = 0xf;
        uStack_94 = 0;
        pvStack_a4 = (void *)((uint)pvStack_a4 & 0xffffff00);
        iVar5 = (**(code **)(*piVar2 + 4))();
        iVar5 = *(int *)(iVar5 + 0x85c);
        iVar7 = 0;
        bVar8 = (byte)((uint)unaff_EBX >> 0x18);
        unaff_EBX = (uint)bVar8 << 0x18;
        if (0 < iVar5) {
          do {
            iVar6 = (**(code **)(*piVar2 + 4))();
            if (*(uint *)(iVar6 + 0x80c + iVar7 * 4) == (uint)bVar8) {
              unaff_EBX = (uint)bVar8 << 0x18;
              break;
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < iVar5);
        }
        (**(code **)(*DAT_00b5a97c + 0x18))();
        iVar5 = (**(code **)(*piVar2 + 4))();
        uStack_80 = (uint)*(ushort *)(iVar5 + 0x2b88);
        if (uStack_b0._2_1_ == '\0') {
          uStack_80 = uStack_80 + 10000;
        }
        FUN_0057a860(&uStack_88);
        iVar5 = iStack_74;
        FUN_0057b0c0(iStack_74 == iStack_7c);
        FUN_006cbdc0(auStack_1c,iVar5);
        FUN_0057ae50(auStack_1c);
        if (0xf < uStack_4) {
          _free(pvStack_18);
          return;
        }
        uStack_4 = 0xf;
        uStack_8 = 0;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      }
      uStack_a8 = uStack_a8 + 1;
    } while (uStack_a8 < 9);
    FUN_006cba10();
    uStack_8c = 0xf;
    uStack_90 = 0;
    uStack_a0 = 0;
    FUN_00401740(s_lbl_slotNum_009e3940,0xb);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_a4);
    if (0xf < uStack_90) {
      _free(pvStack_a4);
      return;
    }
    uStack_90 = 0xf;
    uStack_94 = 0;
    pvStack_a4 = (void *)((uint)pvStack_a4 & 0xffffff00);
    if ((piVar2 != (int *)0x0) && (iVar1 = (**(code **)(*piVar2 + 0x30))(), iVar1 != 0)) {
      (**(code **)(*DAT_00b5ad54 + 0x48))();
      FUN_00401740(&DAT_009e394c,2);
      uVar3 = FUN_00404230(&uStack_3c);
      FUN_0055a260(uVar3);
      if (0xf < uStack_24) {
        _free(pvStack_38);
        return;
      }
    }
  }
  return;
}


// ==== FUN_006cc7e0 @ 0x006cc7e0 ====

void FUN_006cc7e0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  int *piVar5;
  undefined1 local_48 [2];
  undefined1 auStack_46 [2];
  void *pvStack_44;
  undefined1 local_3c [4];
  void *local_38;
  undefined4 uStack_34;
  uint uStack_30;
  undefined1 auStack_2c [4];
  void *local_28;
  uint local_24;
  undefined4 uStack_18;
  uint uStack_14;
  uint uStack_10;
  
  local_24 = 0xf;
  local_28._0_1_ = 0;
  local_28._1_3_ = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  FUN_00401740(s_UI_Game2_Mainbar_ui_quickslotwnd_009e38b8,0x24);
  iVar1 = FUN_00410500(local_3c);
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  piVar2 = (int *)(in_ECX + 0x18);
  if (*(uint *)(in_ECX + 0x2c) < 0x10) {
    piVar5 = piVar2;
  }
  else {
    piVar5 = (int *)*piVar2;
  }
  if (0xf < *(uint *)(in_ECX + 0x2c)) {
    piVar2 = (int *)*piVar2;
  }
  FUN_004bdb30(local_48 + -8,piVar2,*(int *)(in_ECX + 0x28) + (int)piVar5);
  uVar4 = 0;
  while( true ) {
    FUN_00401740(s_slot__d_009e38e0,7);
    uVar3 = FUN_00404230(local_48);
    uStack_14 = 0xf;
    uStack_18 = 0;
    local_28 = (void *)((uint)local_28._1_3_ << 8);
    FUN_00401660(uVar3,0,0xffffffff);
    uStack_10 = uVar4;
    FUN_004a6eb0(local_48 + -8,auStack_2c);
    if (0xf < uStack_14) {
      _free(local_28);
      return;
    }
    uStack_14 = 0xf;
    uStack_18 = 0;
    local_28._0_1_ = 0;
    if (0xf < uStack_30) break;
    uVar4 = uVar4 + 1;
    uStack_30 = 0xf;
    uStack_34 = 0;
    pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
    if (8 < uVar4) {
      FUN_006cc3f0();
      return;
    }
  }
  _free(pvStack_44);
  return;
}


// ==== FUN_006cc940 @ 0x006cc940 ====

undefined4 FUN_006cc940(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x10003) {
    cVar1 = FUN_006cb940(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else {
    if (iVar2 == 0x40001) {
      FUN_006cbb30(param_1[3]);
      return 0;
    }
    if (iVar2 == 0x70050002) {
      FUN_006cc3f0();
      *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 2;
      if ((char)param_1[1] == '\x0f') {
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_006cc9b0 @ 0x006cc9b0 ====

void FUN_006cc9b0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e3a0c;
  iVar1 = FUN_004a37b0();
  in_ECX[3] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  *(undefined4 *)in_ECX[3] = in_ECX[3];
  *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  in_ECX[4] = 0;
  in_ECX[0xb] = 0xf;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  in_ECX[1] = 0;
  FUN_006cc7e0();
  return;
}


// ==== FUN_006cca00 @ 0x006cca00 ====

undefined4 FUN_006cca00(void)

{
  return 0x45;
}


// ==== FUN_006cca10 @ 0x006cca10 ====

void FUN_006cca10(byte param_1)

{
  void *in_ECX;
  
  FUN_006cbd50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006cca30 @ 0x006cca30 ====

undefined4 FUN_006cca30(void)

{
  return 0x30030120;
}


// ==== FUN_006cca40 @ 0x006cca40 ====

void FUN_006cca40(void)

{
  return;
}


// ==== FUN_006cca50 @ 0x006cca50 ====

undefined1 FUN_006cca50(void)

{
  return 0;
}


// ==== FUN_006cca60 @ 0x006cca60 ====

void FUN_006cca60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e3b34;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006ccac0 @ 0x006ccac0 ====

void FUN_006ccac0(byte param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  byte local_59;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  local_59 = 0;
  do {
    FUN_00401740(s_btn_channel__d_009e3aac,0xe);
    uVar2 = FUN_00404230(local_1c);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_38);
    if (piVar3 != (int *)0x0) {
      iVar4 = (**(code **)(*piVar3 + 0x30))();
      if (iVar4 == 0) {
        uStack_3c = 0xf;
        uStack_40 = 0;
        pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
        FUN_00401740(s_pControl____NULL_009e3abc,0x10);
        FUN_00406880(auStack_54);
        if (uStack_3c < 0x10) {
          uStack_3c = 0xf;
          uStack_40 = 0;
          pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        _free(pvStack_50);
        return;
      }
      FUN_00558730(param_1 == local_59);
    }
    local_59 = local_59 + 1;
  } while (local_59 < 0x14);
  if (local_20 < 0x10) {
    return;
  }
  _free(local_34);
  return;
}


// ==== FUN_006ccbf0 @ 0x006ccbf0 ====

/* WARNING: Removing unreachable block (ram,0x006cccca) */
/* WARNING: Removing unreachable block (ram,0x006ccd24) */

undefined4 FUN_006ccbf0(uint param_1,int param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  int iVar3;
  undefined4 *puVar4;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    param_1 = 0;
    do {
      FUN_00401740(s_btn_channel__d_009e3a9c,0xe);
      uVar2 = FUN_00404230(local_1c);
      FUN_00401660(uVar2,0,0xffffffff);
      if (0xf < local_4) {
        _free(local_18);
        return extraout_EAX;
      }
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      if (*(uint *)(param_2 + 0x18) < 0x10) {
        iVar3 = param_2 + 4;
      }
      else {
        iVar3 = *(int *)(param_2 + 4);
      }
      iVar3 = FUN_00403620(0,0,iVar3,*(undefined4 *)(param_2 + 0x14));
      if (iVar3 == 0) {
        puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          *puVar4 = &PTR_FUN_009e3b20;
          puVar4[1] = 0;
          puVar4[2] = param_1;
        }
        FUN_00797a20(puVar4);
        FUN_006ccac0(param_1);
        return 1;
      }
      bVar1 = (char)param_1 + 1;
      param_1 = (uint)bVar1;
    } while (bVar1 < 0x14);
  }
  return 0;
}


// ==== FUN_006ccd40 @ 0x006ccd40 ====

/* WARNING: Removing unreachable block (ram,0x006cd231) */

int * FUN_006ccd40(uint param_1,undefined1 param_2,void *param_3,void *param_4)

{
  int *extraout_EAX;
  int *piVar1;
  int *extraout_EAX_00;
  int *extraout_EAX_01;
  int *extraout_EAX_02;
  undefined4 uVar2;
  int *extraout_EAX_03;
  int *piVar3;
  int iVar4;
  void *pvVar5;
  int *extraout_EAX_04;
  int *extraout_EAX_05;
  int *extraout_EAX_06;
  int *extraout_EAX_07;
  int *extraout_EAX_08;
  int *extraout_EAX_09;
  int *extraout_EAX_10;
  int *extraout_EAX_11;
  int *extraout_EAX_12;
  undefined1 uStack00000000;
  uint in_stack_00000020;
  uint in_stack_00000024;
  undefined1 auStack_f6 [30];
  void *pvStack_d8;
  void *pvStack_cc;
  int *piStack_c8;
  uint auStack_c4 [4];
  undefined1 auStack_b4 [4];
  void *pvStack_b0;
  undefined1 uStack_ac;
  undefined4 uStack_a0;
  void *pvStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  uint uStack_88;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined1 uStack_64;
  undefined1 uStack_63;
  undefined4 auStack_60 [2];
  undefined1 auStack_58 [4];
  void *pvStack_54;
  void *pvStack_50;
  uint uStack_40;
  uint uStack_3c;
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [12];
  undefined4 uStack_14;
  void *pvStack_10;
  undefined4 uStack_c;
  
  auStack_c4[2] = (**(code **)(*DAT_00b5a7ac + 4))();
  if (auStack_c4[2] == 0) {
    if (0xf < in_stack_00000024) {
      _free(param_4);
      return extraout_EAX;
    }
  }
  else {
    auStack_c4[1] = 0xf;
    auStack_c4[0] = 0;
    uStack_98 = 0xf;
    pvStack_9c = (void *)0x0;
    uStack_ac = 0;
    uStack_94 = 0;
    uStack_90 = 0;
    uStack_8c = 0;
    piVar1 = (int *)(**(code **)(*DAT_00b5a7ac + 8))(1);
    if (piVar1 != (int *)0x0) {
      FUN_00401740(s_btn_channel__d_009e3ad0,0xe);
      uVar2 = FUN_00404230(auStack_58);
      FUN_00401660(uVar2,0,0xffffffff);
      if (0xf < uStack_40) {
        _free(pvStack_54);
        return extraout_EAX_03;
      }
      FUN_00401660(auStack_b4,0,0xffffffff);
      piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
      (**(code **)(*piVar3 + 8))(auStack_20,&param_2);
      iVar4 = FUN_00403620(0,uStack_14,&DAT_009e3ae0,1);
      if (iVar4 == 0) {
        uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1e001a);
        FUN_00401660(uVar2,0,0xffffffff);
      }
      uStack_94 = 0;
      uStack_90 = 0;
      uStack_74 = 0xf;
      uStack_78 = 0;
      uStack_88 = uStack_88 & 0xffffff00;
      uStack_70 = 1;
      uStack_6c = 0;
      uStack_68 = 1;
      uStack_64 = 0;
      uStack_63 = 0;
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
      uStack_6c = 0xffffffff;
      uStack_70 = 2;
      FUN_00401660(&uStack00000000,0,0xffffffff);
      auStack_60[0] = 0;
      FUN_00504250(&uStack_94);
      FUN_00505600(auStack_c4,auStack_60);
      if (0xf < uStack_3c) {
        _free(pvStack_50);
        return extraout_EAX_04;
      }
      uStack_6c = 0xff76f856;
      auStack_60[0] = 1;
      FUN_00504250(&uStack_94);
      FUN_00505600(auStack_c4,auStack_60);
      if (0xf < uStack_3c) {
        _free(pvStack_50);
        return extraout_EAX_05;
      }
      auStack_60[0] = 2;
      FUN_00504250(&uStack_94);
      FUN_00505600(auStack_c4,auStack_60);
      if (0xf < uStack_3c) {
        _free(pvStack_50);
        return extraout_EAX_06;
      }
      auStack_60[0] = 4;
      FUN_00504250(&uStack_94);
      FUN_00505600(auStack_c4,auStack_60);
      if (0xf < uStack_3c) {
        _free(pvStack_50);
        return extraout_EAX_07;
      }
      (**(code **)(*piStack_c8 + 8))(auStack_f6 + -0xe);
      FUN_00557b50(uStack_c);
      (**(code **)(*piVar1 + 0x38))(piStack_c8);
      (**(code **)(*piVar1 + 0x1c))(auStack_c4);
      (**(code **)(*piStack_c8 + 0x2c))(piVar1);
      (**(code **)(*piVar1 + 0x24))(pvVar5);
      if (pvVar5 != (void *)0x0) {
        FUN_00505d80();
        _free(pvVar5);
        return extraout_EAX_08;
      }
      if (0xf < uStack_88) {
        _free(pvStack_9c);
        return extraout_EAX_09;
      }
      uStack_88 = 0xf;
      uStack_8c = 0;
      pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
      if (0xf < uStack_24) {
        _free(pvStack_38);
        return extraout_EAX_10;
      }
      uStack_24 = 0xf;
      uStack_28 = 0;
      pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
      if (0xf < auStack_c4[3]) {
        _free(pvStack_cc);
        return extraout_EAX_11;
      }
      auStack_c4[3] = 0xf;
      auStack_c4[2] = 0;
      if (param_1 < 0x10) {
        return piStack_c8;
      }
      _free(pvStack_10);
      return extraout_EAX_12;
    }
    if ((void *)0xf < pvStack_9c) {
      _free(pvStack_b0);
      return extraout_EAX_00;
    }
    pvStack_9c = (void *)0xf;
    uStack_a0 = 0;
    pvStack_b0 = (void *)((uint)pvStack_b0 & 0xffffff00);
    if (0xf < auStack_c4[0]) {
      _free(pvStack_d8);
      return extraout_EAX_01;
    }
    auStack_c4[0] = 0xf;
    if (0xf < in_stack_00000020) {
      _free(param_3);
      return extraout_EAX_02;
    }
  }
  return (int *)0x0;
}


// ==== FUN_006cd280 @ 0x006cd280 ====

void FUN_006cd280(void)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  void *unaff_EBP;
  ushort uVar4;
  undefined1 uVar5;
  uint in_stack_fffffee0;
  undefined4 in_stack_fffffee4;
  undefined4 in_stack_fffffee8;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uStack_f4;
  undefined1 uStack_f0;
  void *local_ec;
  uint local_e8;
  undefined4 uStack_e4;
  uint uStack_e0;
  undefined4 uStack_dc;
  uint local_d8;
  undefined4 local_d4;
  int iStack_d0;
  int iStack_c8;
  void *pvStack_c0;
  void *pvStack_b8;
  undefined4 uStack_b0;
  uint uStack_ac;
  undefined4 uStack_a8;
  uint uStack_a4;
  undefined1 auStack_98 [4];
  void *pvStack_94;
  undefined4 uStack_84;
  uint uStack_80;
  undefined1 auStack_7c [12];
  int iStack_70;
  void *pvStack_68;
  void *pvStack_60;
  uint uStack_54;
  undefined1 auStack_50 [4];
  uint uStack_4c;
  undefined4 uStack_3c;
  void *pvStack_2c;
  undefined4 uStack_1c;
  uint uStack_18;
  
  uVar4 = 0;
  local_d4 = 0xf;
  local_d8 = 0;
  local_e8 = local_e8 & 0xffffff00;
  FUN_00401740(s_pan_bg_009e3ae4,6);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_ec);
  if (0xf < local_d8) {
    _free(local_ec);
    return;
  }
  local_d8 = 0xf;
  uStack_dc = 0;
  local_ec = (void *)((uint)local_ec & 0xffffff00);
  if (piVar2 != (int *)0x0) {
    bVar1 = 0;
    do {
      iVar3 = (**(code **)(*DAT_00b5ac1c + 8))();
      uStack_f4._0_2_ = CONCAT11(bVar1,*(undefined1 *)(iVar3 + 5));
      iVar3 = (**(code **)(*DAT_00b5ac78 + 8))(&uStack_f4);
      if (iVar3 != 0) {
        uVar6 = 0;
        uVar5 = 0;
        FUN_00401740(&DAT_009e3aec,2);
        FUN_00404230(auStack_98);
        uVar8 = 0xf;
        uVar7 = 0;
        in_stack_fffffee0 = in_stack_fffffee0 & 0xffffff00;
        FUN_00401660(auStack_98,0,0xffffffff);
        FUN_006ccd40(piVar2,uVar4,uVar5,in_stack_fffffee0,in_stack_fffffee4,in_stack_fffffee8,uVar6,
                     uVar7,uVar8);
        uVar4 = uVar4 + 1;
        if (0xf < uStack_80) {
          _free(pvStack_94);
          return;
        }
        uStack_80 = 0xf;
        uStack_84 = 0;
        pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
      }
      bVar1 = bVar1 + 1;
    } while (bVar1 < 0x14);
    if (uVar4 != 0) {
      uVar6 = (**(code **)(*piVar2 + 0x10))();
      FUN_005041e0(uVar6);
      pvStack_68 = (void *)(iStack_70 + 0xf + (uint)uVar4 * 0x12);
      (**(code **)(*piVar2 + 0xc))(auStack_7c);
      uStack_dc = 0xf;
      uStack_e0 = 0;
      uStack_f0 = 0;
      FUN_00401740(s_pan_class_select3_009e3af0,0x11);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_f4);
      if (0xf < uStack_e0) {
        _free(uStack_f4);
        return;
      }
      uStack_e0 = 0xf;
      uStack_e4 = 0;
      uStack_f4 = (void *)((uint)uStack_f4 & 0xffffff00);
      if (piVar2 == (int *)0x0) {
        if (0xf < uStack_4c) {
          _free(pvStack_60);
          return;
        }
      }
      else {
        uVar6 = (**(code **)(*piVar2 + 0x10))();
        FUN_005041e0(uVar6);
        if (iStack_70 < iStack_c8) {
          if (0xf < uStack_a4) {
            _free(pvStack_b8);
            return;
          }
          uStack_a4 = 0xf;
          uStack_a8 = 0;
          pvStack_b8 = (void *)((uint)pvStack_b8 & 0xffffff00);
          if (0xf < uStack_4c) {
            _free(pvStack_60);
            return;
          }
        }
        else {
          iStack_d0 = iStack_c8 - iStack_d0;
          iStack_c8 = iStack_70;
          iStack_d0 = iStack_70 - iStack_d0;
          (**(code **)(*piVar2 + 0xc))(&uStack_dc);
          uStack_e4 = 0xf;
          local_e8 = 0;
          FUN_00401740(s_pan_class_select2_009e3b04,0x11);
          piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_98 + -100);
          if (0xf < local_e8) {
            _free(unaff_EBP);
            return;
          }
          local_e8 = 0xf;
          local_ec = (void *)0x0;
          if (piVar2 != (int *)0x0) {
            uVar6 = (**(code **)(*piVar2 + 0x10))();
            FUN_005041e0(uVar6);
            uStack_3c = local_d8;
            (**(code **)(*piVar2 + 0xc))(auStack_50);
            if (0xf < uStack_18) {
              _free(pvStack_2c);
              return;
            }
            uStack_18 = 0xf;
            uStack_1c = 0;
            pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
          }
          if (0xf < uStack_ac) {
            _free(pvStack_c0);
            return;
          }
          uStack_ac = 0xf;
          uStack_b0 = 0;
          pvStack_c0 = (void *)((uint)pvStack_c0 & 0xffffff00);
          if (0xf < uStack_54) {
            _free(pvStack_68);
            return;
          }
        }
      }
    }
  }
  return;
}


// ==== FUN_006cd600 @ 0x006cd600 ====

void FUN_006cd600(void)

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
  FUN_00401740(s_UI_Game2_ui_channelselectwnd_txt_009e3a78,0x20);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  uVar2 = (**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(undefined4 *)(in_ECX + 4) = uVar2;
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x40))();
  FUN_006cd280();
  return;
}


// ==== FUN_006cd690 @ 0x006cd690 ====

void FUN_006cd690(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e3b34;
  FUN_006cd600();
  return;
}


// ==== FUN_006cd6b0 @ 0x006cd6b0 ====

undefined4 FUN_006cd6b0(void)

{
  return 0x12;
}


// ==== FUN_006cd6c0 @ 0x006cd6c0 ====

void FUN_006cd6c0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009e3b34;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006cd700 @ 0x006cd700 ====

void FUN_006cd700(void)

{
  return;
}


// ==== FUN_006cd720 @ 0x006cd720 ====

void FUN_006cd720(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e3d0c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006cd740 @ 0x006cd740 ====

void FUN_006cd740(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009dff54;
  puVar1[1] = param_1;
  puVar1[2] = param_2;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_006cd7d0 @ 0x006cd7d0 ====

undefined4 FUN_006cd7d0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  if (param_3 == 0) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_turn_left_009e3c18,0xd);
    if (iVar2 == 0) {
      *(undefined4 *)(in_ECX + 8) = 1;
      puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar3 == (undefined4 *)0x0) {
        FUN_00797a20(0);
        return 1;
      }
      *puVar3 = &PTR_FUN_009dff54;
      puVar3[1] = 2;
      puVar3[2] = 0;
      FUN_00797a20(puVar3);
      return 1;
    }
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_turn_right_009e3c28,0xe);
    if (iVar2 == 0) {
      *(undefined4 *)(in_ECX + 8) = 2;
      FUN_006cd740(3,0);
      return 1;
    }
  }
  else if ((param_3 == 1) && (param_1 == 1)) {
    cVar1 = FUN_004036a0(param_2,s_btn_ok_009e3c38);
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5a750 + 8))(0x13);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_back_009e3c40);
    if (cVar1 != '\0') {
      FUN_006cd740(0,0);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_list_1_009e3c4c);
    if (cVar1 != '\0') {
      FUN_006cd740(4,0);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_list_2_009e3c58);
    if (cVar1 != '\0') {
      FUN_006cd740(5,0);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_list_3_009e3c64);
    if (cVar1 != '\0') {
      FUN_006cd740(6,0);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_list_4_009e3c70);
    if (cVar1 != '\0') {
      FUN_006cd740(7,0);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_list_5_009e3c7c);
    if (cVar1 != '\0') {
      FUN_006cd740(8,0);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_list_6_009e3c88);
    if (cVar1 != '\0') {
      FUN_006cd740(9,0);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006cd9c0 @ 0x006cd9c0 ====

void FUN_006cd9c0(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  void *local_38;
  undefined1 local_34;
  undefined4 uStack_28;
  uint local_24;
  undefined4 local_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  if (*(int *)(in_ECX + 8) == 1) {
    local_20 = 0xf;
    local_24 = 0;
    local_34 = 0;
    FUN_00401740(s_btn_turn_left_009e3c94,0xd);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
    if (0xf < local_24) {
      _free(local_38);
      return;
    }
    local_24 = 0xf;
    uStack_28 = 0;
    local_38 = (void *)((uint)local_38 & 0xffffff00);
    if (piVar2 == (int *)0x0) {
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      FUN_00401740(s_pComposite____NULL_009e3ca4,0x12);
      FUN_00406880(&local_20);
      if (uStack_8 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_1c);
      return;
    }
    iVar3 = (**(code **)(*piVar2 + 0x30))();
    if (iVar3 == 0) {
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      FUN_00401740(s_pControl____NULL_009e3cb8,0x10);
      FUN_00406880(&local_20);
      if (uStack_8 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_1c);
      return;
    }
    if (*(char *)(iVar3 + 0x70) == '\0') {
      puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar4 == (undefined4 *)0x0) {
        FUN_00797a20(0);
        *(undefined4 *)(in_ECX + 8) = 0;
        return;
      }
      *puVar4 = &PTR_FUN_009dff54;
      puVar4[1] = 0xc;
      puVar4[2] = 0;
      FUN_00797a20(puVar4);
      *(undefined4 *)(in_ECX + 8) = 0;
      return;
    }
  }
  else if (*(int *)(in_ECX + 8) == 2) {
    local_20 = 0xf;
    local_24 = 0;
    local_34 = 0;
    FUN_00401740(s_btn_turn_right_009e3ccc,0xe);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
    if (0xf < local_24) {
      _free(local_38);
      return;
    }
    local_24 = 0xf;
    uStack_28 = 0;
    local_38 = (void *)((uint)local_38 & 0xffffff00);
    if (piVar2 == (int *)0x0) {
      FUN_00401830(s_pComposite____NULL_009e3cdc);
      FUN_00406880(&local_20);
      if (uStack_8 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_1c);
      return;
    }
    iVar3 = (**(code **)(*piVar2 + 0x30))();
    if (iVar3 == 0) {
      FUN_00401830(s_pControl____NULL_009e3cf0);
      FUN_00406880(&local_20);
      if (uStack_8 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_1c);
      return;
    }
    if (*(char *)(iVar3 + 0x70) == '\0') {
      FUN_006cd740(0xc,0);
      *(undefined4 *)(in_ECX + 8) = 0;
    }
  }
  return;
}


// ==== FUN_006cdbf0 @ 0x006cdbf0 ====

uint FUN_006cdbf0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    iVar1 = param_1[1];
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009dff54;
      puVar2[1] = 0xd;
      puVar2[2] = iVar1;
    }
    FUN_00797a20(puVar2);
  }
  uVar3 = FUN_006cd9c0();
  return uVar3 & 0xffffff00;
}


// ==== FUN_006cdc50 @ 0x006cdc50 ====

void FUN_006cdc50(void)

{
  uint uVar1;
  char cVar2;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  void *pvVar8;
  int *piVar9;
  void *in_ECX;
  char *pcVar10;
  void *unaff_EBX;
  void *unaff_ESI;
  uint uVar11;
  void *pvVar12;
  undefined1 auStack_132 [6];
  uint local_12c;
  void *local_128;
  uint uStack_124;
  void *pvStack_11c;
  void *local_118;
  uint local_114;
  undefined4 uStack_10c;
  void *pvStack_108;
  uint uStack_104;
  undefined1 auStack_100 [12];
  uint uStack_f4;
  undefined1 auStack_ec [8];
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  int iStack_dc;
  int iStack_d4;
  void *pvStack_cc;
  undefined4 uStack_bc;
  uint uStack_b8;
  void *apvStack_a0 [4];
  undefined4 uStack_90;
  uint uStack_8c;
  undefined4 uStack_7c;
  void *pvStack_74;
  undefined4 uStack_64;
  uint uStack_60;
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  
  local_114 = 0xf;
  local_118 = (void *)0x0;
  local_128 = (void *)((uint)local_128 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_classselectwnd_txt_009e3ba0,0x1e);
  iVar4 = FUN_00410500(&local_12c);
  if (0xf < local_114) {
    _free(local_128);
    return;
  }
  piVar5 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar4 + 0x3c,0);
  *(int **)((int)in_ECX + 4) = piVar5;
  (**(code **)(*piVar5 + 0x40))();
  uStack_e0 = 0xf;
  uStack_e4 = 0;
  uStack_f4 = uStack_f4 & 0xffffff00;
  uVar11 = 0;
  do {
    piVar5 = *(int **)((int)in_ECX + 4);
    uVar1 = uVar11 + 1;
    FUN_00401740(s_btn_list__d_009e3bc0,0xb);
    uVar6 = FUN_00404230(auStack_132 + -6);
    piVar5 = (int *)(**(code **)(*piVar5 + 0x34))(uVar6);
    if (0xf < uStack_124) {
      _free(unaff_EBX);
      return;
    }
    uStack_124 = 0xf;
    local_128 = (void *)0x0;
    unaff_EBX = (void *)((uint)unaff_EBX & 0xffffff00);
    if (piVar5 == (int *)0x0) {
      uStack_104 = 0xf;
      pvStack_108 = (void *)0x0;
      local_118 = (void *)((uint)local_118 & 0xffffff00);
      FUN_00401740(s_pBaseComposite____NULL_009e3bcc,0x16);
      FUN_00406880(&pvStack_11c);
      if (uStack_104 < 0x10) {
        uStack_104 = 0xf;
        pvStack_108 = (void *)0x0;
        local_118 = (void *)((uint)local_118 & 0xffffff00);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      _free(local_118);
      return;
    }
    piVar5 = (int *)(**(code **)(*piVar5 + 0x30))();
    piVar7 = (int *)(**(code **)(*DAT_00b5abac + 0x10))(uVar11);
    pvVar8 = operator_new(0x468);
    if (pvVar8 == (void *)0x0) {
      pvVar8 = (void *)0x0;
    }
    else {
      pvVar8 = (void *)FUN_00505f10();
    }
    FUN_00505cc0(piVar5 + 0x32);
    if (piVar7 != (int *)0x0) {
      iVar4 = (**(code **)(*piVar7 + 4))();
      pcVar10 = (char *)(iVar4 + 0x20);
      do {
        cVar2 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar2 != '\0');
      FUN_00401740((char *)(iVar4 + 0x20),(int)pcVar10 - (iVar4 + 0x21));
      uStack_104 = 0;
      FUN_00505850(&uStack_104);
      FUN_00401660(auStack_100,0,0xffffffff);
    }
    FUN_00558730(0);
    pvVar12 = pvVar8;
    (**(code **)(*piVar5 + 0x24))(pvVar8);
    if (pvVar8 != (void *)0x0) {
      FUN_00505d80();
      _free(pvVar8);
      return;
    }
    iVar4 = *piVar5;
    uVar6 = FUN_00558120();
    (**(code **)(iVar4 + 8))(uVar6);
    pvVar8 = pvStack_11c;
    in_ECX = pvStack_11c;
    uVar11 = uVar1;
  } while (uVar1 < 6);
  piVar5 = *(int **)((int)pvStack_11c + 4);
  FUN_00401740(s_btn_list__d_009e3be4,0xb);
  uVar6 = FUN_00404230(apvStack_a0);
  piVar5 = (int *)(**(code **)(*piVar5 + 0x34))(uVar6);
  if (0xf < uStack_8c) {
    _free(apvStack_a0[0]);
    return;
  }
  uStack_8c = 0xf;
  uStack_90 = 0;
  apvStack_a0[0] = (void *)((uint)apvStack_a0[0] & 0xffffff00);
  uVar6 = (**(code **)(*piVar5 + 0x10))();
  FUN_005041e0(uVar6);
  uStack_104 = 0xf;
  pvStack_108 = (void *)0x0;
  local_118 = (void *)((uint)local_118 & 0xffffff00);
  FUN_00401740(s_pan_class_select3_009e3bf0,0x11);
  piVar7 = (int *)(**(code **)(**(int **)((int)pvVar8 + 4) + 0x34))(&pvStack_11c);
  if (0xf < pvStack_108) {
    _free(pvStack_11c);
    return;
  }
  pvStack_108 = (void *)0xf;
  uStack_10c = 0;
  pvStack_11c = (void *)((uint)pvStack_11c & 0xffffff00);
  uVar6 = (**(code **)(*piVar7 + 0x10))();
  FUN_005041e0(uVar6);
  local_128 = (void *)0xf;
  local_12c = 0;
  FUN_00401740(s_pan_class_select2_009e3c04,0x11);
  piVar9 = (int *)(**(code **)(**(int **)((int)pvVar8 + 4) + 0x34))(auStack_132 + -0xe);
  if (0xf < local_12c) {
    _free(unaff_ESI);
    return;
  }
  local_12c = 0xf;
  uVar6 = (**(code **)(*piVar9 + 0x10))();
  FUN_005041e0(uVar6);
  iVar4 = (**(code **)(*piVar5 + 0x14))();
  uStack_7c = *(undefined4 *)(iVar4 + 0x14);
  iStack_dc = *(int *)(iVar4 + 0x14);
  iStack_d4 = iStack_dc + (int)pvVar12;
  (**(code **)(*piVar9 + 0xc))(&uStack_90);
  (**(code **)(*piVar7 + 0xc))(auStack_ec);
  if (0xf < uStack_60) {
    _free(pvStack_74);
    return;
  }
  uStack_60 = 0xf;
  uStack_64 = 0;
  pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
  if (0xf < uStack_b8) {
    _free(pvStack_cc);
    return;
  }
  uStack_b8 = 0xf;
  uStack_bc = 0;
  pvStack_cc = (void *)((uint)pvStack_cc & 0xffffff00);
  if (0xf < uStack_24) {
    _free(pvStack_38);
    return;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  if (uStack_f4 < 0x10) {
    return;
  }
  _free(pvStack_108);
  return;
}


// ==== FUN_006ce0c0 @ 0x006ce0c0 ====

void FUN_006ce0c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e3d0c;
  FUN_006cdc50();
  return;
}


// ==== FUN_006ce0e0 @ 0x006ce0e0 ====

void FUN_006ce0e0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009e3d0c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006ce120 @ 0x006ce120 ====

void FUN_006ce120(void)

{
  return;
}


// ==== FUN_006ce130 @ 0x006ce130 ====

undefined1 FUN_006ce130(void)

{
  return 0;
}


// ==== FUN_006ce140 @ 0x006ce140 ====

uint FUN_006ce140(void)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*DAT_00b5ae94 + 0x10))();
  if ((char)uVar1 == '\x01') {
    uVar1 = (**(code **)(*DAT_00b5ae94 + 0xc))();
    if ((char)uVar1 == '\x01') {
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006ce170 @ 0x006ce170 ====

void FUN_006ce170(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e4020;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if ((uint)in_ECX[10] < 0x10) {
    in_ECX[10] = 0xf;
    in_ECX[9] = 0;
    *(undefined1 *)(in_ECX + 5) = 0;
    *in_ECX = &PTR_FUN_009b1764;
    return;
  }
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_006ce1c0 @ 0x006ce1c0 ====

void FUN_006ce1c0(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  undefined1 *puVar5;
  undefined1 uVar6;
  int local_9c;
  int iStack_94;
  void *pvStack_90;
  undefined1 auStack_8c [4];
  void *pvStack_88;
  undefined4 uStack_80;
  uint uStack_7c;
  undefined4 uStack_78;
  uint uStack_74;
  undefined1 local_70 [4];
  void *local_6c;
  undefined4 local_5c;
  uint local_58;
  void *pvStack_54;
  void *pvStack_50;
  undefined4 uStack_44;
  uint uStack_40;
  uint uStack_3c;
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_58 = 0xf;
  local_5c = 0;
  local_6c = (void *)((uint)local_6c & 0xffffff00);
  local_9c = 3;
  while( true ) {
    FUN_00401740(s_btn_tab_d_009e3e6c,9);
    puVar5 = local_1c;
    uVar2 = FUN_00404230(puVar5);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_70);
    if (piVar3 == (int *)0x0) {
      uStack_24 = 0xf;
      uStack_28 = 0;
      pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
      FUN_00401740(s_pComposite____NULL_009e3e78,0x12);
      FUN_00406880(&uStack_3c);
      if (uStack_24 < 0x10) {
        uStack_24 = 0xf;
        uStack_28 = 0;
        pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_38);
      return;
    }
    (**(code **)(*piVar3 + 0x30))();
    FUN_00558730(0);
    uVar6 = 0;
    FUN_00401740(s_pan_tab_d_009e3e8c,9);
    uVar2 = FUN_00404230(&local_58,puVar5,uVar6);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < uStack_40) {
      _free(pvStack_54);
      return;
    }
    uStack_40 = 0xf;
    uStack_44 = 0;
    pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
    piVar3 = (int *)(**(code **)(**(int **)(local_9c + 4) + 0x34))(&uStack_74);
    if (piVar3 == (int *)0x0) break;
    (**(code **)(*piVar3 + 0x24))(0);
    local_9c = local_9c + -1;
    if (local_9c == 0) {
      pvStack_90 = (void *)0x3;
      do {
        iStack_94 = 0x14;
        do {
          uVar6 = 0;
          FUN_00401740(s_btn_sub__d__d_009e3eac,0xd);
          uVar2 = FUN_00404230(&pvStack_54,puVar5,uVar6);
          FUN_00401660(uVar2,0,0xffffffff);
          if (0xf < uStack_3c) {
            _free(pvStack_50);
            return;
          }
          uStack_3c = 0xf;
          uStack_40 = 0;
          pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
          piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_70);
          if (piVar3 != (int *)0x0) {
            iVar4 = (**(code **)(*piVar3 + 0x30))();
            if (iVar4 == 0) {
              uStack_74 = 0xf;
              uStack_78 = 0;
              pvStack_88 = (void *)((uint)pvStack_88 & 0xffffff00);
              FUN_00401740(s_pButton____NULL_009e3ebc,0xf);
              FUN_00406880(auStack_8c);
              if (uStack_74 < 0x10) {
                uStack_74 = 0xf;
                uStack_78 = 0;
                pvStack_88 = (void *)((uint)pvStack_88 & 0xffffff00);
                pcVar1 = (code *)swi(3);
                (*pcVar1)();
                return;
              }
              _free(pvStack_88);
              return;
            }
            FUN_00558730(0);
          }
          iStack_94 = iStack_94 + -1;
        } while (iStack_94 != 0);
        pvStack_90 = (void *)((int)pvStack_90 + -1);
        if (pvStack_90 == (void *)0x0) {
          if (local_58 < 0x10) {
            return;
          }
          _free(local_6c);
          return;
        }
      } while( true );
    }
  }
  uStack_7c = 0xf;
  uStack_80 = 0;
  pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
  FUN_00401740(s_pComposite____NULL_009e3e98,0x12);
  FUN_00406880(&iStack_94);
  if (uStack_7c < 0x10) {
    uStack_7c = 0xf;
    uStack_80 = 0;
    pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_90);
  return;
}


// ==== FUN_006ce4e0 @ 0x006ce4e0 ====

/* WARNING: Removing unreachable block (ram,0x006ce5c0) */

void FUN_006ce4e0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined1 auStack_52 [22];
  undefined1 auStack_3c [4];
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  void *local_1c [5];
  uint uStack_8;
  
  FUN_00401740(s_btn_sub__d__d_009e3ecc,0xd);
  FUN_00404230(local_1c);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_1c);
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    FUN_00401660(iVar2 + 0x9c,0,0xffffffff);
    uStack_24 = 0xf;
    uStack_28 = 0;
    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    FUN_00401740(s_lbl_subTitle_009e3edc,0xc);
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_3c);
    if (0xf < uStack_24) {
      _free(pvStack_38);
      return;
    }
    uStack_24 = 0xf;
    uStack_28 = 0;
    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x30))();
      if (iVar2 != 0) {
        FUN_0055a260(auStack_52 + -6);
      }
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  if (uStack_8 < 0x10) {
    return;
  }
  _free(local_1c[0]);
  return;
}


// ==== FUN_006ce630 @ 0x006ce630 ====

/* WARNING: Removing unreachable block (ram,0x006cea31) */
/* WARNING: Removing unreachable block (ram,0x006ce9e5) */
/* WARNING: Removing unreachable block (ram,0x006ce8cf) */
/* WARNING: Removing unreachable block (ram,0x006ceca1) */
/* WARNING: Removing unreachable block (ram,0x006ce884) */

void FUN_006ce630(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  code *pcVar1;
  char cVar2;
  undefined2 uVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  undefined4 uVar6;
  void *_Memory;
  undefined4 uStack_d8;
  void *pvStack_d4;
  char *pcStack_d0;
  char *pcStack_cc;
  uint *puStack_c8;
  void *pvStack_c4;
  void *local_c0;
  undefined4 uStack_bc;
  uint uVar7;
  void *pvStack_90;
  void *pvStack_8c;
  void *pvStack_84;
  uint uStack_7c;
  void *pvStack_78;
  undefined1 auStack_74 [4];
  void *pvStack_70;
  undefined1 auStack_6c [4];
  void *pvStack_68;
  uint auStack_64 [2];
  uint uStack_5c;
  undefined4 uStack_58;
  uint local_54 [2];
  void *pvStack_4c;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  
  FUN_006ce1c0();
  *(undefined2 *)(in_ECX + 10) = param_1;
  *(undefined2 *)(in_ECX + 8) = param_2;
  *(undefined2 *)(in_ECX + 0xc) = param_3;
  puStack_c8 = (uint *)0x9;
  pcStack_cc = s_btn_tab_d_009e3eec;
  local_c0 = (void *)((uint)local_c0 & 0xffffff00);
  pcStack_d0 = (char *)0x6ce68c;
  FUN_00401740();
  puStack_c8 = local_54;
  pcStack_cc = (char *)0x6ce696;
  FUN_00404230();
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar4 == (int *)0x0) {
    pvStack_78 = (void *)0xf;
    uStack_7c = 0;
    pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
    FUN_00401740();
    FUN_00406880();
    if (pvStack_78 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_8c);
    return;
  }
  iVar5 = (**(code **)(*piVar4 + 0x30))();
  if (iVar5 == 0) {
    pvStack_78 = (void *)0xf;
    uStack_7c = 0;
    pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
    FUN_00401740();
    FUN_00406880();
    if (pvStack_78 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_8c);
    return;
  }
  FUN_00558730();
  pcStack_cc = (char *)0x9;
  pcStack_d0 = s_pan_tab_d_009e3f1c;
  pvStack_c4 = (void *)((uint)pvStack_c4 & 0xffffff00);
  pvStack_d4 = (void *)0x6ce760;
  FUN_00401740();
  pcStack_cc = auStack_74;
  pcStack_d0 = (char *)0x6ce76a;
  FUN_00404230();
  FUN_00401660();
  if (0xf < uStack_5c) {
    _free(pvStack_70);
    return;
  }
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar4 == (int *)0x0) {
    uStack_7c = 0xf;
    pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
    FUN_00401740();
    FUN_00406880();
    if (uStack_7c < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_90);
    return;
  }
  (**(code **)(*piVar4 + 0x24))();
  uStack_d8 = (uint *)0xd;
  uStack_bc = (char *)0xf;
  local_c0 = (void *)0x0;
  pcStack_d0 = (char *)((uint)pcStack_d0 & 0xffffff00);
  FUN_00401740();
  uStack_d8 = &uStack_7c;
  uStack_bc = (char *)FUN_00404230();
  local_c0 = (void *)0x6ce82d;
  FUN_00401660();
  if (0xf < auStack_64[0]) {
    _free(pvStack_78);
    return;
  }
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar4 == (int *)0x0) {
    uStack_bc = s_pComposite____NULL_009e3f4c;
    local_c0 = (void *)0x6ce870;
    FUN_00401740();
    uStack_bc = (char *)0x6ce87a;
    FUN_00406880();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  iVar5 = (**(code **)(*piVar4 + 0x30))();
  if (iVar5 == 0) {
    uStack_bc = s_pButton____NULL_009e3f60;
    local_c0 = (void *)0x6ce8bb;
    FUN_00401740();
    uStack_bc = (char *)0x6ce8c5;
    FUN_00406880();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  uStack_bc = (char *)0x6ce8e6;
  FUN_00558730();
  piVar4 = DAT_00b5ae94;
  uStack_bc = auStack_74 + -0x2c;
  local_c0 = (void *)0xf;
  pvStack_c4 = (void *)0x0;
  pvStack_d4 = (void *)((uint)pvStack_d4 & 0xffffff00);
  FUN_00401660(in_ECX + 0x10,0);
  cVar2 = (**(code **)(*piVar4 + 0x14))();
  if (cVar2 == '\0') goto joined_r0x006ce921;
  _Memory = pvStack_c4;
  uVar3 = (**(code **)(*DAT_00b5ae94 + 0x18))();
  *(undefined2 *)(in_ECX + 0xe) = uVar3;
  (**(code **)(*DAT_00b5ae94 + 0x1c))(local_54,puStack_c8,*(short *)(in_ECX + 0xc) + 1);
  uStack_bc = (char *)0x0;
  pcStack_cc = (char *)((uint)pcStack_cc & 0xffffff00);
  FUN_00401740(s_textbox_009e3f70,7);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pcStack_d0);
  if (0xf < uStack_bc) {
    _free(pcStack_d0);
    return;
  }
  uStack_bc = (char *)0xf;
  local_c0 = (void *)0x0;
  pcStack_d0 = (char *)((uint)pcStack_d0 & 0xffffff00);
  if (piVar4 == (int *)0x0) {
    FUN_00401740(s_pComposite____NULL_009e3f78,0x12);
    FUN_00406880(auStack_74 + -0x44);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  iVar5 = (**(code **)(*piVar4 + 0x30))();
  if (iVar5 == 0) {
    FUN_00401740(s_pTextBox____NULL_009e3f8c,0x10);
    FUN_00406880(auStack_74 + -0x44);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  FUN_005569f0(auStack_64,0);
  FUN_006ce4e0(uStack_44,uStack_40);
  pcStack_d0 = (char *)((uint)pcStack_d0 & 0xffffff00);
  local_c0 = (void *)0x0;
  uStack_bc = (undefined1 *)0xf;
  if (*(short *)(in_ECX + 0xe) == 0) {
    FUN_00401740(s_btn_leftArrow_009e3fc0,0xd);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_d4);
    if (0xf < local_c0) {
      _free(pvStack_d4);
      return;
    }
    local_c0 = (void *)0xf;
    pvStack_c4 = (void *)0x0;
    pvStack_d4 = (void *)((uint)pvStack_d4 & 0xffffff00);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x44))(0);
    }
    local_c0 = (void *)0xf;
    pvStack_c4 = (void *)0x0;
    pvStack_d4 = (void *)((uint)pvStack_d4 & 0xffffff00);
    FUN_00401740(s_btn_rightArrow_009e3fd0,0xe);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_d8);
    if ((void *)0xf < pvStack_c4) {
      _free(uStack_d8);
      return;
    }
    uStack_d8 = (uint *)((uint)uStack_d8 & 0xffffff00);
    if (piVar4 != (int *)0x0) {
      uVar6 = 0;
      goto LAB_006cebce;
    }
  }
  else {
    FUN_00401740(s_btn_leftArrow_009e3fa0,0xd);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_d4);
    if (0xf < local_c0) {
      _free(pvStack_d4);
      return;
    }
    local_c0 = (void *)0xf;
    pvStack_c4 = (void *)0x0;
    pvStack_d4 = (void *)((uint)pvStack_d4 & 0xffffff00);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x44))(*(short *)(in_ECX + 0xc) != 0);
    }
    local_c0 = (void *)0xf;
    pvStack_c4 = (void *)0x0;
    pvStack_d4 = (void *)((uint)pvStack_d4 & 0xffffff00);
    FUN_00401740(s_btn_rightArrow_009e3fb0,0xe);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_d8);
    if ((void *)0xf < pvStack_c4) {
      _free(uStack_d8);
      return;
    }
    uStack_d8 = (uint *)((uint)uStack_d8 & 0xffffff00);
    if (piVar4 != (int *)0x0) {
      iVar5 = *(ushort *)(in_ECX + 0xe) - 1;
      uVar6 = CONCAT31((int3)((uint)iVar5 >> 8),(int)(uint)*(ushort *)(in_ECX + 0xc) < iVar5);
LAB_006cebce:
      pvStack_c4 = (void *)0xf;
      puStack_c8 = (uint *)0x0;
      (**(code **)(*piVar4 + 0x44))(uVar6);
    }
  }
  pvStack_c4 = (void *)0xf;
  puStack_c8 = (uint *)0x0;
  uStack_d8 = (uint *)((uint)uStack_d8 & 0xffffff00);
  FUN_00401740(s_lbl_pageNum_009e3fe0,0xb);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_74 + -0x68);
  if (0xf < puStack_c8) {
    _free(_Memory);
    return;
  }
  puStack_c8 = (uint *)0xf;
  pcStack_cc = (undefined1 *)0x0;
  if (piVar4 == (int *)0x0) {
    uVar7 = 0xf;
    local_c0 = (void *)((uint)local_c0 & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e3fec,0x12);
    FUN_00406880(&pvStack_c4);
    if (uVar7 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_c0);
    return;
  }
  iVar5 = (**(code **)(*piVar4 + 0x30))();
  if (iVar5 == 0) {
    FUN_00401740(s_pLable____NULL_009e4000);
    FUN_00406880();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  FUN_00401740(s__d____d_009e4010,7);
  FUN_00404230(auStack_6c);
  FUN_0055a260();
  if (0xf < local_54[0]) {
    _free(pvStack_68);
    return;
  }
  local_54[0] = 0xf;
  uStack_58 = 0;
  pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
  if (0xf < uStack_38) {
    _free(pvStack_4c);
    return;
  }
  uStack_38 = 0xf;
  uStack_3c = 0;
  pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
joined_r0x006ce921:
  if (pvStack_70 < (void *)0x10) {
    return;
  }
  _free(pvStack_84);
  return;
}


// ==== FUN_006ced70 @ 0x006ced70 ====

void FUN_006ced70(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  void *unaff_ESI;
  undefined1 local_38 [2];
  undefined1 auStack_36 [2];
  void *local_34;
  uint uStack_30;
  undefined4 uStack_2c;
  void *pvStack_28;
  undefined4 local_24;
  uint local_20;
  undefined4 uStack_18;
  uint uStack_14;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_infownd_txt_009e3d78,0x17);
  iVar2 = FUN_00410500(local_38);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar2 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar3;
  (**(code **)(*piVar3 + 0x40))();
  uStack_2c = 0xf;
  uStack_30 = 0;
  FUN_00401740(s_btn_sub_1_1_009e3d90,0xb);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_38 + -0xc);
  if (0xf < uStack_30) {
    _free(unaff_ESI);
    return;
  }
  uStack_30 = 0xf;
  local_34 = (void *)0x0;
  if (piVar3 == (int *)0x0) {
    uStack_14 = 0xf;
    uStack_18 = 0;
    pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009e3d9c,0x12);
    FUN_00406880(&uStack_2c);
    if (uStack_14 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_28);
    return;
  }
  iVar2 = (**(code **)(*piVar3 + 0x30))();
  if (iVar2 != 0) {
    uStack_14 = 0xf;
    uStack_18 = 0;
    pvStack_28 = (void *)((uint)pvStack_28._1_3_ << 8);
    FUN_00401660(iVar2 + 0x9c,0,0xffffffff);
    FUN_00401660(&uStack_2c,0,0xffffffff);
    if (uStack_14 < 0x10) {
      FUN_006ce630(0,0,0);
      return;
    }
    _free(pvStack_28);
    return;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28._1_3_ << 8);
  FUN_00401740(s_pControl____NULL_009e3db0,0x10);
  FUN_00406880(&uStack_2c);
  if (uStack_14 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_28);
  return;
}


// ==== FUN_006cef10 @ 0x006cef10 ====

/* WARNING: Removing unreachable block (ram,0x006cefed) */

undefined4 FUN_006cef10(int param_1)

{
  uint uVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  int iVar4;
  undefined4 extraout_EAX_00;
  int *piVar5;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  int in_ECX;
  uint uVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  int local_4c;
  int local_48;
  byte ****local_44;
  undefined1 local_38 [4];
  byte ****local_34 [4];
  uint local_24;
  uint local_20;
  void *local_1c;
  void *local_18;
  undefined4 uStack_c;
  uint local_8;
  uint local_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = (byte ****)((uint)local_34[0] & 0xffffff00);
  local_4c = 0;
  local_48 = 0;
  do {
    FUN_00401740(s_btn_sub__d__d_009e3df0,0xd);
    uVar3 = FUN_00404230(&local_1c);
    FUN_00401660(uVar3,0,0xffffffff);
    if (0xf < local_4) {
      _free(local_18);
      return extraout_EAX;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    if (local_20 < 0x10) {
      local_44 = (byte ****)local_34;
    }
    else {
      local_44 = local_34[0];
    }
    uVar1 = *(uint *)(param_1 + 0x14);
    if (uVar1 == 0) {
LAB_006cf021:
      if ((local_24 <= uVar1) && (uVar1 == local_24)) {
        if ((*(short *)(in_ECX + 10) != (short)local_4c) ||
           (*(short *)(in_ECX + 8) != (short)local_48)) {
          piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_38);
          if (piVar5 == (int *)0x0) {
            local_8 = 0xf;
            uStack_c = 0;
            local_1c = (void *)((uint)local_1c & 0xffffff00);
            FUN_00401740(s_pComposite____NULL_009e3e00,0x12);
            FUN_00406880(&local_20);
            if (local_8 < 0x10) {
              pcVar2 = (code *)swi(3);
              uVar3 = (*pcVar2)();
              return uVar3;
            }
            _free(local_1c);
            return extraout_EAX_01;
          }
          iVar4 = (**(code **)(*piVar5 + 0x30))();
          if (iVar4 == 0) {
            local_4 = 0xf;
            local_8 = 0;
            local_18 = (void *)((uint)local_18._1_3_ << 8);
            FUN_00401740(s_pControl____NULL_009e3e14,0x10);
            FUN_00406880(&local_1c);
            if (local_4 < 0x10) {
              pcVar2 = (code *)swi(3);
              uVar3 = (*pcVar2)();
              return uVar3;
            }
            _free(local_18);
            return extraout_EAX_02;
          }
          local_4 = 0xf;
          local_8 = 0;
          local_18 = (void *)((uint)local_18._1_3_ << 8);
          FUN_00401660(iVar4 + 0x9c,0,0xffffffff);
          FUN_00401660(&local_1c,0,0xffffffff);
          if (0xf < local_4) {
            _free(local_18);
            return extraout_EAX_03;
          }
          FUN_006ce630(local_4c,local_48,0);
        }
        if (local_20 < 0x10) {
          return 1;
        }
        _free(local_34[0]);
        return extraout_EAX_04;
      }
    }
    else {
      uVar6 = uVar1;
      if (local_24 <= uVar1) {
        uVar6 = local_24;
      }
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        pbVar7 = (byte *)(param_1 + 4);
      }
      else {
        pbVar7 = *(byte **)(param_1 + 4);
      }
      bVar8 = false;
      iVar4 = 0;
      bVar9 = true;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        bVar8 = *pbVar7 < *(byte *)local_44;
        bVar9 = *pbVar7 == *(byte *)local_44;
        pbVar7 = pbVar7 + 1;
        local_44 = (byte ****)((int)local_44 + 1);
      } while (bVar9);
      if (!bVar9) {
        iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      }
      if (iVar4 == 0) goto LAB_006cf021;
    }
    local_48 = local_48 + 1;
    if (0x13 < (ushort)local_48) {
      local_4c = local_4c + 1;
      if (2 < (ushort)local_4c) {
        if (local_20 < 0x10) {
          return 0;
        }
        _free(local_34[0]);
        return extraout_EAX_00;
      }
      local_48 = 0;
    }
  } while( true );
}


// ==== FUN_006cf1b0 @ 0x006cf1b0 ====

/* WARNING: Removing unreachable block (ram,0x006cf25a) */

undefined4 FUN_006cf1b0(int param_1)

{
  uint uVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  int iVar4;
  undefined4 extraout_EAX_00;
  int *piVar5;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined4 extraout_EAX_05;
  int in_ECX;
  uint uVar6;
  uint unaff_EBX;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  byte local_5d;
  byte ****local_5c;
  void *local_54;
  byte ****local_50 [4];
  uint local_40;
  uint local_3c;
  void *local_38;
  void *local_34;
  undefined4 uStack_28;
  uint local_24;
  uint local_20;
  void *local_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  local_3c = 0xf;
  local_40 = 0;
  local_50[0] = (byte ****)((uint)local_50[0] & 0xffffff00);
  local_5d = 0;
  do {
    FUN_00401740(s_btn_tab_d_009e3e28,9);
    uVar3 = FUN_00404230(&local_38);
    FUN_00401660(uVar3,0,0xffffffff);
    if (0xf < local_20) {
      _free(local_34);
      return extraout_EAX;
    }
    local_20 = 0xf;
    local_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    if (local_3c < 0x10) {
      local_5c = (byte ****)local_50;
    }
    else {
      local_5c = local_50[0];
    }
    uVar1 = *(uint *)(param_1 + 0x14);
    if (uVar1 == 0) {
LAB_006cf28f:
      if ((local_40 <= uVar1) && (uVar1 == local_40)) {
        piVar5 = *(int **)(in_ECX + 4);
        FUN_00401740(s_btn_sub__d_1_009e3e34,0xc);
        uVar3 = FUN_00404230(local_1c);
        piVar5 = (int *)(**(code **)(*piVar5 + 0x34))(uVar3);
        if (0xf < uStack_8) {
          _free(local_1c[0]);
          return extraout_EAX_01;
        }
        uStack_8 = 0xf;
        uStack_c = 0;
        local_1c[0] = (void *)((uint)local_1c[0] & 0xffffff00);
        if (piVar5 == (int *)0x0) {
          local_24 = 0xf;
          uStack_28 = 0;
          local_38 = (void *)((uint)local_38 & 0xffffff00);
          FUN_00401740(s_pComposite____NULL_009e3e44,0x12);
          FUN_00406880(&local_3c);
          if (local_24 < 0x10) {
            pcVar2 = (code *)swi(3);
            uVar3 = (*pcVar2)();
            return uVar3;
          }
          _free(local_38);
          return extraout_EAX_02;
        }
        iVar4 = (**(code **)(*piVar5 + 0x30))();
        if (iVar4 == 0) {
          local_24 = 0xf;
          uStack_28 = 0;
          local_38 = (void *)((uint)local_38._1_3_ << 8);
          FUN_00401740(s_pControl____NULL_009e3e58,0x10);
          FUN_00406880(&local_3c);
          if (local_24 < 0x10) {
            pcVar2 = (code *)swi(3);
            uVar3 = (*pcVar2)();
            return uVar3;
          }
          _free(local_38);
          return extraout_EAX_03;
        }
        local_24 = 0xf;
        uStack_28 = 0;
        local_38 = (void *)((uint)local_38._1_3_ << 8);
        FUN_00401660(iVar4 + 0x9c,0,0xffffffff);
        FUN_00401660(&local_3c,0,0xffffffff);
        if (0xf < local_24) {
          _free(local_38);
          return extraout_EAX_04;
        }
        FUN_006ce630(unaff_EBX >> 0x18,0,0);
        if (local_40 < 0x10) {
          return 1;
        }
        _free(local_54);
        return extraout_EAX_05;
      }
    }
    else {
      uVar6 = uVar1;
      if (local_40 <= uVar1) {
        uVar6 = local_40;
      }
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        pbVar7 = (byte *)(param_1 + 4);
      }
      else {
        pbVar7 = *(byte **)(param_1 + 4);
      }
      bVar8 = false;
      iVar4 = 0;
      bVar9 = true;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        bVar8 = *pbVar7 < *(byte *)local_5c;
        bVar9 = *pbVar7 == *(byte *)local_5c;
        pbVar7 = pbVar7 + 1;
        local_5c = (byte ****)((int)local_5c + 1);
      } while (bVar9);
      if (!bVar9) {
        iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      }
      if (iVar4 == 0) goto LAB_006cf28f;
    }
    local_5d = local_5d + 1;
    if (2 < local_5d) {
      if (local_3c < 0x10) {
        return 0;
      }
      _free(local_50[0]);
      return extraout_EAX_00;
    }
  } while( true );
}


// ==== FUN_006cf440 @ 0x006cf440 ====

void FUN_006cf440(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e4020;
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  FUN_006ced70();
  return;
}


// ==== FUN_006cf470 @ 0x006cf470 ====

undefined4 FUN_006cf470(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  undefined8 uVar5;
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  cVar1 = FUN_006cf1b0(param_2);
  if (cVar1 == '\x01') {
    return 1;
  }
  cVar1 = FUN_006cef10(param_2);
  if (cVar1 == '\x01') {
    return 1;
  }
  uVar5 = FUN_004036a0(param_2,s_btn_leftArrow_009e3dc4);
  uVar4 = (uint)((ulonglong)uVar5 >> 0x20);
  if ((char)uVar5 == '\0') {
    uVar3 = FUN_004036a0(param_2,s_btn_rightArrow_009e3dd4);
    if ((char)uVar3 == '\0') {
      cVar1 = FUN_004036a0(param_2,s_btn_exit_009e3de4);
      if (cVar1 == '\0') {
        return 0;
      }
      (**(code **)(*DAT_00b5ae94 + 0xc))();
      return 0;
    }
    iVar2 = CONCAT22((short)((uint)uVar3 >> 0x10),*(ushort *)(in_ECX + 0xc));
    uVar4 = (uint)*(ushort *)(in_ECX + 0xc);
    if ((int)(*(ushort *)(in_ECX + 0xe) - 1) <= (int)uVar4) goto LAB_006cf4ef;
    iVar2 = iVar2 + 1;
  }
  else {
    iVar2 = CONCAT22((short)((ulonglong)uVar5 >> 0x10),*(short *)(in_ECX + 0xc));
    if (*(short *)(in_ECX + 0xc) == 0) goto LAB_006cf4ef;
    iVar2 = iVar2 + -1;
  }
  *(short *)(in_ECX + 0xc) = (short)iVar2;
LAB_006cf4ef:
  FUN_006ce630(CONCAT22((short)(uVar4 >> 0x10),*(undefined2 *)(in_ECX + 10)),
               *(undefined2 *)(in_ECX + 8),
               CONCAT22((short)((uint)iVar2 >> 0x10),*(undefined2 *)(in_ECX + 0xc)));
  return 1;
}


// ==== FUN_006cf530 @ 0x006cf530 ====

void FUN_006cf530(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009e4020;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if (0xf < (uint)in_ECX[10]) {
    _free((void *)in_ECX[5]);
    return;
  }
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006cf590 @ 0x006cf590 ====

void FUN_006cf590(void)

{
  return;
}


// ==== FUN_006cf5a0 @ 0x006cf5a0 ====

undefined1 FUN_006cf5a0(void)

{
  return 0;
}


// ==== FUN_006cf5b0 @ 0x006cf5b0 ====

void FUN_006cf5b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e41a4;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006cf5d0 @ 0x006cf5d0 ====

void FUN_006cf5d0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009e4190;
  puVar1[1] = param_1;
  puVar1[2] = param_2;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_006cf610 @ 0x006cf610 ====

undefined1 FUN_006cf610(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5ae20 + 0x10))();
  if (cVar1 == '\x01') {
    return 1;
  }
  if ((param_1 == 1) && (param_3 == 1)) {
    cVar1 = FUN_004036a0(param_2,s_btn_create_char_009e40ac);
    if (cVar1 != '\0') {
      FUN_006cf5d0(0,0);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_connect_009e40bc);
    if (cVar1 != '\0') {
      FUN_006cf5d0(2,0);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_servertransfer_009e40c8);
    if (cVar1 != '\0') {
      FUN_006cf5d0(8,0);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_logout_009e40dc);
    if (cVar1 != '\0') {
      FUN_006cf5d0(1,0);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_delete_char_009e40e8);
    if (cVar1 != '\0') {
      FUN_006cf5d0(3,0);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_character_list_btn_0_009e40f8);
    if (cVar1 != '\0') {
      FUN_006cf5d0(4,0);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_character_list_btn_1_009e4110);
    if (cVar1 != '\0') {
      FUN_006cf5d0(4,1);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_character_list_btn_2_009e4128);
    if (cVar1 != '\0') {
      FUN_006cf5d0(4,2);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_character_list_btn_3_009e4140);
    if (cVar1 != '\0') {
      FUN_006cf5d0(4,3);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_character_list_btn_4_009e4158);
    if (cVar1 != '\0') {
      FUN_006cf5d0(4,4);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_character_list_btn_5_009e4170);
    if (cVar1 != '\0') {
      FUN_006cf5d0(4,5);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006cf7e0 @ 0x006cf7e0 ====

undefined4 FUN_006cf7e0(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  int *in_ECX;
  short unaff_retaddr;
  undefined4 uStack_24;
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  
  pvStack_20 = (void *)0x6cf7e8;
  iVar2 = (**(code **)(*in_ECX + 0x14))();
  if (param_1 != iVar2) {
    return 0;
  }
  if (param_3 == 1) {
    pvStack_20 = (void *)0x1e001b;
    uStack_24 = 0;
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_c = 0xf;
    uStack_10 = 0;
    pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
    FUN_00401660(uVar3,0,0xffffffff);
    if (unaff_retaddr == 1) {
      cVar1 = FUN_00423420(param_2,&uStack_24);
      if (cVar1 != '\0') {
        (**(code **)(*DAT_00b5a9dc + 8))(1);
      }
    }
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return extraout_EAX;
    }
  }
  return 1;
}


// ==== FUN_006cf880 @ 0x006cf880 ====

void FUN_006cf880(void)

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
  FUN_00401740(s_UI_Game2_ui_charselectwnd_txt_009e408c,0x1d);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  uVar2 = (**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(undefined4 *)(in_ECX + 4) = uVar2;
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x40))();
  return;
}


// ==== FUN_006cf910 @ 0x006cf910 ====

void FUN_006cf910(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e41a4;
  FUN_006cf880();
  return;
}


// ==== FUN_006cf930 @ 0x006cf930 ====

void FUN_006cf930(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009e41a4;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006cf970 @ 0x006cf970 ====

void FUN_006cf970(void)

{
  return;
}


// ==== FUN_006cf990 @ 0x006cf990 ====

void FUN_006cf990(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e4714;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006cfa00 @ 0x006cfa00 ====

void FUN_006cfa00(void)

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
    FUN_00401740(s_pan_sentry__d_009e42e0,0xd);
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
      FUN_00401740(s_pan_sentry__d_009e42f0,0xd);
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


// ==== FUN_006cfb20 @ 0x006cfb20 ====

void FUN_006cfb20(void)

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
  
  FUN_00401740(s_pan_brick__d_009e437c,0xc);
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
    FUN_00401740(s_pan_brick__d_009e438c,0xc);
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


// ==== FUN_006cfc20 @ 0x006cfc20 ====

void FUN_006cfc20(void)

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
  FUN_00401740(s_pan_sentryinfo_009e442c,0xe);
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


// ==== FUN_006cfd00 @ 0x006cfd00 ====

void FUN_006cfd00(void)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  int in_ECX;
  void *unaff_EBX;
  uint unaff_ESI;
  void **ppvVar5;
  undefined4 uStack_78;
  void *_Memory;
  undefined4 uStack_68;
  undefined1 auStack_52 [6];
  void *pvStack_4c;
  void *pvStack_48;
  uint uStack_44;
  void *pvStack_40;
  void *pvStack_3c;
  void *pvStack_38;
  uint uStack_34;
  undefined1 auStack_30 [4];
  void *pvStack_2c;
  uint uStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  
  uStack_68 = (void **)0x6cfd14;
  cVar1 = (**(code **)(*DAT_00b5ac98 + 0x44))();
  uStack_68 = (void **)0x13;
  uStack_34 = uStack_34 & 0xffffff00;
  uStack_24 = 0;
  uStack_20 = 0xf;
  if (cVar1 == '\0') {
    FUN_00401740();
    uStack_68 = &pvStack_38;
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))();
    }
    if (0xf < uStack_24) {
      _free(pvStack_38);
      return;
    }
    uStack_24 = 0xf;
    uStack_28 = 0;
    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    FUN_00401740();
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))();
    }
    if (0xf < uStack_28) {
      _free(pvStack_3c);
      return;
    }
    uStack_28 = 0xf;
    pvStack_2c = (void *)0x0;
    pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
    uStack_78 = 0x6cfdd4;
    FUN_00401740();
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if (piVar2 != (int *)0x0) {
      uStack_78 = 0x6cfded;
      (**(code **)(*piVar2 + 0x24))();
    }
    if ((void *)0xf < pvStack_2c) {
      uStack_78 = 0x6cfdfd;
      _free(pvStack_40);
      return;
    }
    _Memory = (void *)0x122001e;
    uStack_78 = 0;
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660(uVar3,0,0xffffffff);
    uStack_34 = 0xf;
    pvStack_38 = (void *)0x0;
    pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
    FUN_00401740(s__BLINK__009e4484,7);
    (**(code **)(*DAT_00b5adc8 + 0x14))();
    FUN_00401740(&DAT_009e4480,2);
    uVar4 = FUN_00404230(auStack_30);
    ppvVar5 = &pvStack_4c;
    FUN_00404440(&uStack_68,ppvVar5,uVar4);
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
    pvStack_38 = (void *)0x0;
    pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
    FUN_00401740(s_lbl_sentry_maxcount_009e448c,0x13);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_4c);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x30))();
      FUN_0055a260(auStack_52 + -0x1a);
    }
    if ((void *)0xf < pvStack_38) {
      _free(pvStack_4c);
      return;
    }
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x122001f);
    FUN_00401660(uVar3,0,0xffffffff);
    pvStack_40 = (void *)0xf;
    uStack_44 = 0;
    FUN_00401740(s__BLINK__009e44a4,7);
    (**(code **)(*DAT_00b5adc8 + 0x18))();
    uVar4 = uVar4 & 0xffffff00;
    FUN_00401740(&DAT_009e44a0,2);
    uVar3 = FUN_00404230(&pvStack_3c,ppvVar5,uVar4);
    FUN_00404440(auStack_52 + -0x22,auStack_52 + -6,uVar3);
    if (0xf < uStack_24) {
      _free(pvStack_38);
      return;
    }
    uStack_24 = 0xf;
    uStack_28 = 0;
    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    if (0xf < pvStack_40) {
      _free((void *)0x0);
      return;
    }
    pvStack_40 = (void *)0xf;
    uStack_44 = 0;
    FUN_00401740(s_lbl_sentry_count_009e44ac,0x10);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_52 + -6);
  }
  else {
    FUN_00401740();
    uStack_68 = &pvStack_38;
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))();
    }
    if (0xf < uStack_24) {
      _free(pvStack_38);
      return;
    }
    uStack_24 = 0xf;
    uStack_28 = 0;
    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    FUN_00401740();
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))();
    }
    if (0xf < uStack_28) {
      _free(pvStack_3c);
      return;
    }
    uStack_28 = 0xf;
    pvStack_2c = (void *)0x0;
    pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
    uStack_78 = 0x6d0087;
    FUN_00401740();
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if (piVar2 != (int *)0x0) {
      uStack_78 = 0x6d00a1;
      (**(code **)(*piVar2 + 0x24))();
    }
    if ((void *)0xf < pvStack_2c) {
      uStack_78 = 0x6d00b1;
      _free(pvStack_40);
      return;
    }
    _Memory = (void *)0x1220020;
    uStack_78 = 0;
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660(uVar3,0,0xffffffff);
    uStack_34 = 0xf;
    pvStack_38 = (void *)0x0;
    pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
    FUN_00401740(s__BLINK__009e4500,7);
    (**(code **)(*DAT_00b5adc8 + 0x18))();
    FUN_00401740(&DAT_009e44fc,2);
    uVar3 = FUN_00404230(auStack_30);
    FUN_00404440(&uStack_68,&pvStack_4c,uVar3);
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
    pvStack_38 = (void *)0x0;
    pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
    FUN_00401740(s_lbl_sentry_fight_009e4508,0x10);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_4c);
  }
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_0055a260(&uStack_78);
  }
  if (0xf < uStack_44) {
    _free(unaff_EBX);
    return;
  }
  if (unaff_ESI < 0x10) {
    return;
  }
  _free(_Memory);
  return;
}


