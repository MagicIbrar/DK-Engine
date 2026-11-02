// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x730000-0x73ffff

// ==== FUN_00730130 @ 0x00730130 ====

void FUN_00730130(void)

{
  int unaff_retaddr;
  undefined1 auStack_6c [20];
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_34 [36];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009918dc;
  pvStack_c = ExceptionList;
  uStack_48 = 5;
  uStack_4c = 0x730155;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined4 *)(unaff_retaddr + 0x34)) {
  case 0:
    uStack_4c = 0x82001e;
    uStack_50 = 0;
    uStack_54 = 0x73017e;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x730188;
    FUN_00765c50();
    pvStack_10 = (void *)0x0;
    goto LAB_00730190;
  case 1:
    uStack_4c = 0x820017;
    uStack_50 = 0;
    uStack_54 = 0x7301ca;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x7301d4;
    FUN_00765c50();
    pvStack_10 = (void *)0x1;
    break;
  case 2:
    uStack_4c = 0x82006a;
    uStack_50 = 0;
    uStack_54 = 0x7301f3;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x7301fd;
    FUN_00765c50();
    pvStack_10 = (void *)0x2;
LAB_00730190:
    puStack_8 = auStack_6c;
    FUN_00765c50(&uStack_50);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0073030a;
  case 3:
    uStack_4c = 0x82006c;
    uStack_50 = 0;
    uStack_54 = 0x73028b;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x730295;
    FUN_00765c50();
    pvStack_10 = (void *)0x5;
    break;
  case 4:
    uStack_4c = 0x82006b;
    uStack_50 = 0;
    uStack_54 = 0x730219;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x730223;
    FUN_00765c50();
    pvStack_10 = (void *)0x3;
    break;
  case 5:
    uStack_4c = 0x8200eb;
    uStack_50 = 0;
    uStack_54 = 0x73023f;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x730249;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x4;
    FUN_00765c50(&uStack_50);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0073030a;
  case 6:
    uStack_4c = 0x82001f;
    uStack_50 = 0;
    uStack_54 = 0x7302d4;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x7302de;
    FUN_00765c50();
    puStack_8 = auStack_6c;
    pvStack_10 = (void *)0x6;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_0073030a;
  default:
    ExceptionList = pvStack_10;
    return;
  }
  puStack_8 = auStack_6c;
  FUN_00765c50(&uStack_50);
  (**(code **)(*DAT_00b5ad0c + 0x28))(8);
LAB_0073030a:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00730340 @ 0x00730340 ====

void FUN_00730340(int param_1)

{
  char cVar1;
  int iVar2;
  uint unaff_EBX;
  char *pcVar3;
  void *pvStack_40;
  void *local_28;
  undefined1 local_24;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009918ee;
  pvStack_c = ExceptionList;
  pcVar3 = (char *)(param_1 + 0x18);
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = 0;
  FUN_00401660(&local_28,0,0xffffffff);
  iVar2 = (**(code **)(*DAT_00b5acac + 0x24))();
  if (iVar2 != 0) {
    *(undefined1 *)(iVar2 + 0x1e) = 0;
  }
  (**(code **)(*DAT_00b5aca8 + 0x2c))();
  if (unaff_EBX < 0x10) {
    ExceptionList = local_28;
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_00730400 @ 0x00730400 ====

void FUN_00730400(void)

{
  char cVar1;
  int unaff_retaddr;
  undefined1 auStack_70 [4];
  undefined1 uStack_6c;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  void *pvStack_44;
  undefined1 auStack_34 [4];
  uint uStack_30;
  void *pvStack_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00991908;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5aca8 + 0x80))();
  (**(code **)(*DAT_00b5aca8 + 0xc))();
  cVar1 = *(char *)(unaff_retaddr + 0x10);
  if (cVar1 != '\0') {
    if (cVar1 == '\x01') {
      uStack_54 = 0;
      uStack_58 = 0x73045d;
      uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_58 = 0xffffffff;
      uStack_5c = 0;
      uStack_64 = 0x73047a;
      FUN_00401660();
      puStack_8 = auStack_70;
      uStack_58 = 0xf;
      uStack_5c = 0;
      pvStack_10 = (void *)0x0;
      uStack_6c = 0;
      FUN_00401660(auStack_34 + -0x1c,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(8);
      (**(code **)(*DAT_00b5aca8 + 0x74))(auStack_70);
      if (0xf < uStack_30) {
LAB_0073055b:
        uStack_54 = 0x730561;
        _free(pvStack_44);
        return;
      }
    }
    else if (cVar1 == '\x02') {
      uStack_54 = 0;
      uStack_58 = 0x7304eb;
      uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_58 = 0xffffffff;
      uStack_5c = 0;
      uStack_1c = 0xf;
      uStack_20 = 0;
      uStack_30 = uStack_30 & 0xffffff00;
      uStack_64 = 0x730508;
      FUN_00401660();
      puStack_8 = auStack_70;
      uStack_58 = 0xf;
      uStack_5c = 0;
      pvStack_10 = (void *)0x1;
      uStack_6c = 0;
      FUN_00401660(auStack_34,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(8);
      (**(code **)(*DAT_00b5aca8 + 0x74))(&uStack_54);
      if (0xf < uStack_14) {
        pvStack_44 = pvStack_28;
        goto LAB_0073055b;
      }
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00730580 @ 0x00730580 ====

void FUN_00730580(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  uint uVar5;
  undefined2 extraout_var;
  undefined4 uVar6;
  undefined1 auStack_412 [466];
  char acStack_240 [84];
  void *pvStack_1ec;
  undefined4 uStack_1e4;
  char acStack_40 [34];
  undefined2 uStack_1e;
  undefined4 uStack_1c;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099191d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00733920();
  local_4 = 0;
  pcVar3 = (char *)(param_1 + 0x218);
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740();
  pcVar3 = (char *)(param_1 + 0x18);
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740();
  piVar4 = (int *)(**(code **)(*DAT_00b5acac + 0x30))();
  acStack_240[0] = '\0';
  acStack_40[0] = '\0';
  uVar5 = 0;
  do {
    cVar1 = ((char *)(param_1 + 0x218))[uVar5];
    acStack_40[uVar5] = cVar1;
    if (cVar1 == '\0') goto LAB_0073067e;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x21);
  acStack_40[0] = '\0';
LAB_0073067e:
  uVar5 = 0;
  do {
    cVar1 = ((char *)(param_1 + 0x18))[uVar5];
    acStack_240[uVar5] = cVar1;
    if (cVar1 == '\0') goto LAB_007306a0;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x200);
  acStack_240[0] = '\0';
LAB_007306a0:
  uStack_1e = *(undefined2 *)(param_1 + 0x23a);
  uStack_1c = *(undefined4 *)(param_1 + 0x23c);
  uStack_18 = *(undefined2 *)(param_1 + 0x240);
  uStack_16 = *(undefined2 *)(param_1 + 0x242);
  uStack_10 = *(undefined4 *)(param_1 + 0x24c);
  uStack_14 = 0;
  (**(code **)(*piVar4 + 4))();
  piVar4 = (int *)(**(code **)(*piVar4 + 0x14))();
  (**(code **)(*piVar4 + 0xc))();
  piVar4 = (int *)(**(code **)(*DAT_00b5a980 + 8))();
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 0xc0))();
  }
  FUN_00733990(auStack_412 + -6);
  (**(code **)(*DAT_00b5acac + 8))();
  iVar2 = *DAT_00b5aca8;
  uVar6 = (**(code **)(*DAT_00b5a97c + 0xc))
                    (CONCAT22(extraout_var,*(undefined2 *)(param_1 + 0x244)));
  (**(code **)(iVar2 + 0x7c))(uVar6);
  uStack_1e4 = 0xffffffff;
  FUN_00537c20();
  ExceptionList = pvStack_1ec;
  return;
}


// ==== FUN_007307b0 @ 0x007307b0 ====

void FUN_007307b0(int param_1)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  undefined4 uStack_a4;
  char *pcStack_a0;
  int *piStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  uint uStack_90;
  char *pcStack_8c;
  char *pcStack_88;
  int iStack_84;
  undefined1 uStack_7a;
  char cStack_79;
  undefined4 uStack_74;
  undefined4 uStack_70;
  char acStack_60 [8];
  undefined1 uStack_58;
  int local_54;
  int local_50;
  undefined1 auStack_44 [8];
  void *pvStack_3c;
  undefined1 uStack_38;
  undefined1 uStack_2f;
  uint uStack_28;
  uint uStack_24;
  void *pvStack_1c;
  undefined4 uStack_10;
  void *pvStack_c;
  char cStack_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  piVar3 = DAT_00b5a69c;
  uStack_4 = 0xffffffff;
  cStack_8 = '/';
  uStack_7 = 0x9919;
  pvStack_c = ExceptionList;
  uStack_70 = (int *)0x7307dc;
  ExceptionList = &pvStack_c;
  uVar2 = FUN_00424520();
  local_50 = param_1 + 0x18;
  local_54 = (uVar2 & 0xffff) - 0x18;
  uStack_70 = &local_54;
  uStack_74 = (char *)0x7307f9;
  piVar3 = (int *)(**(code **)(*piVar3 + 4))();
  uStack_74 = acStack_60;
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (iVar4 == 2) {
    iStack_84 = 0x73086d;
    iVar4 = (**(code **)(*piVar3 + 8))();
    if (iVar4 == 1) {
      uStack_58 = 0;
      uStack_24 = 0xf;
      uStack_28 = 0;
      uStack_38 = 0;
      uStack_10 = 0;
      do {
        if (cStack_8 == '\0') {
LAB_007309e0:
          (**(code **)(*DAT_00b5a69c + 8))();
          if (uStack_28 < 0x10) {
            ExceptionList = pvStack_1c;
            return;
          }
          iStack_84 = 0x7309fd;
          _free(pvStack_3c);
          return;
        }
        iStack_84 = 0x7308b6;
        iVar4 = (**(code **)(*piVar3 + 8))();
        if (iVar4 != 1) {
          pcStack_a0 = s_fail_GuildUserInfo___3_009ee844;
LAB_007309ce:
          uStack_a4 = 0x7309d3;
          FUN_00401830();
          pcStack_a0 = (char *)0x8;
          uStack_a4 = 0x7309e0;
          (**(code **)(*DAT_00b5ad0c + 0x28))();
          goto LAB_007309e0;
        }
        iStack_84 = (int)&uStack_74 + 2;
        pcStack_88 = (char *)0x1;
        pcStack_8c = (char *)0x7308cd;
        iVar4 = (**(code **)(*piVar3 + 8))();
        if (iVar4 != 1) {
          uStack_74 = (char *)&uStack_a4;
          FUN_00401830(s_fail_GuildUserInfo___5_009ee85c);
          (**(code **)(*DAT_00b5ad0c + 0x28))(8);
          goto LAB_007309e0;
        }
        cStack_79 = (char)((uint)(acStack_60 + -9) >> 0x18);
        uStack_7a = (undefined1)((uint)(acStack_60 + -9) >> 0x10);
        uVar6 = (uint)(byte)(cStack_79 - 2);
        pcStack_8c = acStack_60 + -8;
        uStack_2f = uStack_7a;
        uStack_94 = 0x7308f4;
        uStack_90 = uVar6;
        uVar2 = (**(code **)(*piVar3 + 8))();
        if (uVar2 != uVar6) {
          pcStack_a0 = s_fail_GuildUserInfo___4_009ee874;
          goto LAB_007309ce;
        }
        pcVar5 = acStack_60;
        acStack_60[uVar6] = '\0';
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        iStack_84 = (int)pcVar5 - (int)(acStack_60 + 1);
        pcStack_88 = acStack_60;
        pcStack_8c = (char *)0x730921;
        FUN_00401740();
        uStack_28._0_3_ = (uint3)(ushort)uStack_28;
        uStack_24 = uStack_24 & 0xffff0000;
        pcStack_8c = (char *)0xf;
        uStack_90 = 0;
        pcStack_a0 = (char *)((uint)pcStack_a0 & 0xffffff00);
        FUN_00401660(auStack_44,0,0xffffffff);
        pcStack_88._0_3_ = (undefined3)uStack_28;
        iStack_84 = CONCAT22(iStack_84._2_2_,(undefined2)uStack_24);
        (**(code **)(*DAT_00b5acac + 0x14))();
        cStack_8 = cStack_8 + -1;
      } while( true );
    }
    piStack_9c = (int *)s_fail_GuildUserInfo___2_009ee82c;
  }
  else {
    piStack_9c = (int *)s_fail_GuildUserInfo___1_009ee814;
  }
  uStack_98 = 0x16;
  uStack_90 = uStack_90 & 0xffffff00;
  pcStack_a0 = (char *)0x730832;
  FUN_00401740();
  uStack_98 = 8;
  piStack_9c = (int *)0x73083f;
  (**(code **)(*DAT_00b5ad0c + 0x28))();
  pcStack_a0 = (char *)0x73084b;
  piStack_9c = piVar3;
  (**(code **)(*DAT_00b5a69c + 8))();
  ExceptionList = pvStack_3c;
  return;
}


// ==== FUN_00730a20 @ 0x00730a20 ====

/* WARNING: Removing unreachable block (ram,0x00730bb8) */
/* WARNING: Removing unreachable block (ram,0x00730b99) */

void FUN_00730a20(int param_1)

{
  char cVar1;
  char *pcVar2;
  undefined1 local_4c [4];
  void *local_48;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  void *local_28;
  undefined1 local_24;
  uint local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099195c;
  pvStack_c = ExceptionList;
  pcVar2 = (char *)(param_1 + 0x18);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &pvStack_c;
  FUN_00401740();
  pcVar2 = (char *)(param_1 + 0x31);
  local_4 = 0;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740();
  local_2c = 0;
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = 0;
  local_4._0_1_ = 2;
  local_30 = 7;
  FUN_00401740(s__s____s_009ee88c,7);
  FUN_00404230(local_4c);
  local_4._0_1_ = 3;
  FUN_00401660();
  local_4 = CONCAT31(local_4._1_3_,2);
  if (0xf < local_34) {
    _free(local_48);
    return;
  }
  (**(code **)(*DAT_00b5ad10 + 8))();
  (**(code **)(*DAT_00b5ad0c + 0x14))();
  if (local_14 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_28);
  return;
}


// ==== FUN_00730be0 @ 0x00730be0 ====

/* WARNING: Removing unreachable block (ram,0x00730d7f) */
/* WARNING: Removing unreachable block (ram,0x00730d9e) */

void FUN_00730be0(int param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 local_50;
  void *pvStack_4c;
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00991989;
  pvStack_c = ExceptionList;
  pcVar2 = (char *)(param_1 + 0x18);
  local_50 = 0xf;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &pvStack_c;
  FUN_00401740();
  pcVar2 = (char *)(param_1 + 0x31);
  local_4 = 0;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740();
  local_4 = CONCAT31(local_4._1_3_,1);
  cVar1 = (**(code **)(*DAT_00b5aca8 + 4))();
  if (cVar1 != '\0') {
    uStack_30 = 0;
    uStack_14 = 0xf;
    uStack_18 = 0;
    pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
    puStack_8._0_1_ = 2;
    uStack_34 = 10;
    FUN_00401740(s__s____s_009ee894,7);
    FUN_00404230(&local_50);
    puStack_8._0_1_ = 3;
    FUN_00401660();
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
    if (0xf < uStack_38) {
      _free(pvStack_4c);
      return;
    }
    (**(code **)(*DAT_00b5ad10 + 8))();
    (**(code **)(*DAT_00b5ad0c + 0x14))();
    if (0xf < uStack_14) {
      _free(pvStack_28);
      return;
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00730dd0 @ 0x00730dd0 ====

/* WARNING: Removing unreachable block (ram,0x00730f68) */
/* WARNING: Removing unreachable block (ram,0x00730f49) */

void FUN_00730dd0(int param_1)

{
  char cVar1;
  char *pcVar2;
  undefined1 local_4c [4];
  void *local_48;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  void *local_28;
  undefined1 local_24;
  uint local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009919b6;
  pvStack_c = ExceptionList;
  pcVar2 = (char *)(param_1 + 0x151);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &pvStack_c;
  FUN_00401740();
  pcVar2 = (char *)(param_1 + 0x31);
  local_4 = 0;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740();
  local_2c = 0;
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = 0;
  local_4._0_1_ = 2;
  local_30 = 9;
  FUN_00401740(s_From__s____s_009ee89c,0xc);
  FUN_00404230(local_4c);
  local_4._0_1_ = 3;
  FUN_00401660();
  local_4 = CONCAT31(local_4._1_3_,2);
  if (0xf < local_34) {
    _free(local_48);
    return;
  }
  (**(code **)(*DAT_00b5ad10 + 8))();
  (**(code **)(*DAT_00b5ad0c + 0x14))();
  if (local_14 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_28);
  return;
}


// ==== FUN_00730f90 @ 0x00730f90 ====

void FUN_00730f90(void)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  char *pcVar4;
  int unaff_retaddr;
  undefined1 auStack_3fc [4];
  undefined1 uStack_3f8;
  void *pvStack_3f0;
  undefined4 uStack_3ec;
  undefined4 uStack_3e8;
  undefined4 uStack_3e4;
  undefined4 uStack_3e0;
  char *pcStack_3dc;
  undefined1 *puStack_3d8;
  undefined1 auStack_3d4 [4];
  undefined1 uStack_3d0;
  undefined4 uStack_3c0;
  undefined4 uStack_3bc;
  undefined4 uStack_214;
  char *pcStack_210;
  int iStack_20c;
  undefined1 *puStack_208;
  undefined1 auStack_1e0 [4];
  undefined1 local_1dc [464];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009919d6;
  pvStack_c = ExceptionList;
  puStack_208 = local_1dc;
  iStack_20c = 0x730fbd;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5acac + 0xc))();
  pcVar4 = (char *)(unaff_retaddr + 0x18);
  puStack_8 = (undefined1 *)0x0;
  pcVar2 = pcVar4;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iStack_20c = (int)pcVar2 - (unaff_retaddr + 0x19);
  uStack_214 = 0x730feb;
  pcStack_210 = pcVar4;
  FUN_00401740();
  pcStack_3dc = auStack_1e0;
  uStack_3e0 = 0x731007;
  FUN_00733990();
  pcStack_3dc = (char *)0x731012;
  (**(code **)(*DAT_00b5acac + 8))();
  pcStack_3dc = (char *)0x73101d;
  (**(code **)(*DAT_00b5aca8 + 0x2c))();
  pcStack_3dc = (char *)0x731028;
  piVar3 = (int *)(**(code **)(*DAT_00b5acac + 0x30))();
  if (piVar3 != (int *)0x0) {
    pcStack_3dc = (char *)0x731033;
    (**(code **)(*piVar3 + 0x10))();
    uStack_3e0 = 0x73103b;
    pcStack_3dc = pcVar4;
    FUN_006f6d10();
  }
  pcStack_3dc = (char *)0x820045;
  uStack_3e0 = 0;
  uStack_3e4 = 0x73104c;
  uStack_3ec = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3e4 = 0xffffffff;
  uStack_3e8 = 0;
  uStack_3bc = 0xf;
  uStack_3c0 = 0;
  uStack_3d0 = 0;
  pvStack_3f0 = (void *)0x73106a;
  FUN_00401660();
  puStack_3d8 = auStack_3fc;
  uStack_3e4 = 0xf;
  uStack_3e8 = 0;
  auStack_1e0[0] = 1;
  uStack_3f8 = 0;
  FUN_00401660(auStack_3d4,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(8);
  if (pcStack_3dc < 0x10) {
    pcStack_3dc = (char *)0xf;
    uStack_3e0 = 0;
    pvStack_3f0 = (void *)((uint)pvStack_3f0 & 0xffffff00);
    FUN_00537c20();
    ExceptionList = puStack_208;
    return;
  }
  _free(pvStack_3f0);
  return;
}


// ==== FUN_007310f0 @ 0x007310f0 ====

void FUN_007310f0(void)

{
  int *piVar1;
  int iVar2;
  int unaff_retaddr;
  undefined1 auStack_3fc [4];
  undefined1 uStack_3f8;
  void *pvStack_3f0;
  undefined4 uStack_3ec;
  undefined4 uStack_3e8;
  undefined4 uStack_3e4;
  undefined4 uStack_3e0;
  undefined1 *puStack_3dc;
  undefined1 *puStack_3d8;
  undefined1 auStack_3d4 [4];
  undefined1 uStack_3d0;
  undefined4 uStack_3c0;
  undefined4 uStack_3bc;
  undefined4 uStack_20c;
  undefined1 *puStack_208;
  undefined1 auStack_1e0 [4];
  undefined1 local_1dc [60];
  undefined2 uStack_1a0;
  undefined2 uStack_19e;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009919f6;
  pvStack_c = ExceptionList;
  puStack_208 = local_1dc;
  uStack_20c = 0x73111d;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5acac + 0xc))();
  uStack_1a0 = *(undefined2 *)(unaff_retaddr + 0x1a);
  uStack_19e = *(undefined2 *)(unaff_retaddr + 0x18);
  puStack_3dc = auStack_1e0;
  puStack_8 = (undefined1 *)0x0;
  uStack_3e0 = 0x731161;
  FUN_00733990();
  puStack_3dc = (undefined1 *)0x73116c;
  (**(code **)(*DAT_00b5acac + 8))();
  puStack_3dc = (undefined1 *)0x731177;
  piVar1 = (int *)(**(code **)(*DAT_00b5acac + 0x30))();
  if (piVar1 != (int *)0x0) {
    puStack_3dc = (undefined1 *)0x731182;
    iVar2 = (**(code **)(*piVar1 + 0x10))();
    *(undefined2 *)(iVar2 + 0x228) = *(undefined2 *)(unaff_retaddr + 0x18);
    *(undefined2 *)(iVar2 + 0x22a) = *(undefined2 *)(unaff_retaddr + 0x1a);
  }
  puStack_3dc = (undefined1 *)0x7311a3;
  (**(code **)(*DAT_00b5aca8 + 0x2c))();
  puStack_3dc = (undefined1 *)0x820046;
  uStack_3e0 = 0;
  uStack_3e4 = 0x7311b4;
  uStack_3ec = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3e4 = 0xffffffff;
  uStack_3e8 = 0;
  uStack_3bc = 0xf;
  uStack_3c0 = 0;
  uStack_3d0 = 0;
  pvStack_3f0 = (void *)0x7311d2;
  FUN_00401660();
  puStack_3d8 = auStack_3fc;
  uStack_3e4 = 0xf;
  uStack_3e8 = 0;
  auStack_1e0[0] = 1;
  uStack_3f8 = 0;
  FUN_00401660(auStack_3d4,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(8);
  if (puStack_3dc < 0x10) {
    puStack_3dc = (undefined1 *)0xf;
    uStack_3e0 = 0;
    pvStack_3f0 = (void *)((uint)pvStack_3f0 & 0xffffff00);
    FUN_00537c20();
    ExceptionList = puStack_208;
    return;
  }
  _free(pvStack_3f0);
  return;
}


// ==== FUN_00731260 @ 0x00731260 ====

void FUN_00731260(int param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  uint unaff_EBX;
  undefined1 auStack_444 [4];
  undefined1 uStack_440;
  undefined4 uStack_438;
  undefined4 uStack_434;
  void *pvStack_430;
  undefined4 uStack_42c;
  undefined4 uStack_428;
  undefined1 *puStack_424;
  undefined4 uStack_420;
  uint uStack_41c;
  undefined1 *puStack_418;
  void *pvStack_414;
  undefined1 uStack_410;
  uint uStack_400;
  undefined4 uStack_3fc;
  undefined4 uStack_260;
  int iStack_25c;
  undefined *puStack_258;
  undefined4 ****ppppuStack_254;
  undefined1 *puStack_250;
  undefined4 ****local_21c;
  undefined1 local_218;
  void *local_208;
  undefined4 local_204;
  undefined1 uStack_200;
  undefined1 auStack_1e0 [4];
  undefined1 local_1dc [74];
  char acStack_192 [390];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00991a21;
  pvStack_c = ExceptionList;
  ppppuStack_254 = (undefined4 ****)(param_1 + 0x19);
  local_204 = 0xf;
  local_208 = (void *)0x0;
  local_218 = 0;
  pcVar2 = (char *)ppppuStack_254;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  puStack_250 = (undefined1 *)((int)pcVar2 - (param_1 + 0x1a));
  puStack_258 = (undefined *)0x7312bc;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  puStack_250 = local_1dc;
  local_4 = 0;
  ppppuStack_254 = (undefined4 ****)0x7312d3;
  (**(code **)(*DAT_00b5acac + 0xc))();
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,1);
  if (local_208 < (void *)0x10) {
    local_21c = &local_21c;
  }
  iStack_25c = (int)&local_204 + 3;
  puStack_258 = &DAT_009ee8b4;
  uStack_260 = 0x7312fa;
  ppppuStack_254 = local_21c;
  FUN_0050cd30();
  pcVar2 = acStack_192 + (unaff_EBX >> 0x18) * 0x27;
  uVar4 = 0;
  pcVar3 = pcVar2;
  do {
    cVar1 = pcVar3[(int)(auStack_1e0 + (-0x21 - (int)pcVar2))];
    *pcVar3 = cVar1;
    if (cVar1 == '\0') goto LAB_00731336;
    uVar4 = uVar4 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar4 < 0x21);
  *pcVar2 = '\0';
LAB_00731336:
  puStack_424 = auStack_1e0;
  uStack_428 = 0x731352;
  FUN_00733990();
  puStack_424 = (undefined1 *)0x73135d;
  (**(code **)(*DAT_00b5acac + 8))();
  puStack_424 = (undefined1 *)0x731368;
  (**(code **)(*DAT_00b5aca8 + 0x2c))();
  puStack_424 = (undefined1 *)0x820071;
  uStack_428 = 0;
  uStack_42c = 0x731379;
  uStack_434 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_42c = 0xffffffff;
  pvStack_430 = (void *)0x0;
  uStack_3fc = 0xf;
  uStack_400 = 0;
  uStack_410 = 0;
  uStack_438 = 0x731397;
  FUN_00401660();
  puStack_418 = auStack_444;
  uStack_42c = 0xf;
  pvStack_430 = (void *)0x0;
  auStack_1e0[0] = 2;
  uStack_440 = 0;
  FUN_00401660(&pvStack_414,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(8);
  (**(code **)(*DAT_00b5aca8 + 0x28))();
  if (0xf < uStack_41c) {
    _free(pvStack_430);
    return;
  }
  uStack_41c = 0xf;
  uStack_420 = 0;
  pvStack_430 = (void *)((uint)pvStack_430 & 0xffffff00);
  uStack_200 = 0;
  FUN_00537c20();
  if (uStack_400 < 0x10) {
    ExceptionList = local_208;
    return;
  }
  _free(pvStack_414);
  return;
}


// ==== FUN_00731440 @ 0x00731440 ====

void FUN_00731440(int param_1)

{
  undefined4 uVar1;
  uint unaff_EBX;
  void *unaff_ESI;
  undefined1 auStack_400 [4];
  undefined1 uStack_3fc;
  undefined4 uStack_3f4;
  void *pvStack_3f0;
  undefined4 uStack_3ec;
  undefined4 uStack_3e8;
  undefined4 uStack_3e4;
  undefined1 *puStack_3e0;
  uint uStack_3dc;
  undefined1 *puStack_3d8;
  undefined1 auStack_3d4 [4];
  undefined1 uStack_3d0;
  undefined4 uStack_3c0;
  undefined4 uStack_3bc;
  undefined4 uStack_210;
  undefined1 *puStack_20c;
  undefined1 auStack_1e0 [4];
  undefined1 local_1dc [70];
  undefined4 auStack_196 [98];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00991a41;
  pvStack_c = ExceptionList;
  uVar1 = *(undefined4 *)(param_1 + 0x1c);
  puStack_20c = local_1dc;
  uStack_210 = 0x73147e;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5acac + 0xc))();
  *(undefined4 *)((int)auStack_196 + (unaff_EBX >> 0x18) * 0x27) = uVar1;
  puStack_3e0 = auStack_1e0;
  puStack_8 = (undefined1 *)0x0;
  uStack_3e4 = 0x7314ba;
  FUN_00733990();
  puStack_3e0 = (undefined1 *)0x7314c5;
  (**(code **)(*DAT_00b5acac + 8))();
  puStack_3e0 = (undefined1 *)0x7314d0;
  (**(code **)(*DAT_00b5aca8 + 0x2c))();
  puStack_3e0 = (undefined1 *)0x820072;
  uStack_3e4 = 0;
  uStack_3e8 = 0x7314e1;
  pvStack_3f0 = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3e8 = 0xffffffff;
  uStack_3ec = 0;
  uStack_3bc = 0xf;
  uStack_3c0 = 0;
  uStack_3d0 = 0;
  uStack_3f4 = 0x7314ff;
  FUN_00401660();
  puStack_3d8 = auStack_400;
  uStack_3e8 = 0xf;
  uStack_3ec = 0;
  auStack_1e0[0] = 1;
  uStack_3fc = 0;
  FUN_00401660(auStack_3d4,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(8);
  (**(code **)(*DAT_00b5aca8 + 0x28))();
  if (uStack_3dc < 0x10) {
    uStack_3dc = 0xf;
    puStack_3e0 = (undefined1 *)0x0;
    pvStack_3f0 = (void *)((uint)pvStack_3f0 & 0xffffff00);
    FUN_00537c20();
    ExceptionList = unaff_ESI;
    return;
  }
  _free(pvStack_3f0);
  return;
}


// ==== FUN_00731590 @ 0x00731590 ====

void FUN_00731590(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint unaff_EBX;
  uint uStack_41c;
  void *pvStack_414;
  undefined1 uStack_410;
  uint uStack_400;
  undefined4 uStack_3fc;
  undefined4 uStack_264;
  int iStack_260;
  undefined *puStack_25c;
  undefined4 ****ppppuStack_258;
  undefined1 *puStack_254;
  undefined4 ****local_21c;
  undefined1 local_218;
  void *local_208;
  undefined4 local_204;
  undefined1 uStack_200;
  undefined1 uStack_1e0;
  undefined1 local_1dc [70];
  undefined4 uStack_196;
  char acStack_192 [390];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00991a6c;
  pvStack_c = ExceptionList;
  ppppuStack_258 = (undefined4 ****)(param_1 + 0x20);
  local_204 = 0xf;
  local_208 = (void *)0x0;
  local_218 = 0;
  pcVar4 = (char *)ppppuStack_258;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  puStack_254 = (undefined1 *)((int)pcVar4 - (param_1 + 0x21));
  puStack_25c = (undefined *)0x7315ed;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  uVar2 = *(undefined4 *)(param_1 + 0x1c);
  puStack_254 = local_1dc;
  local_4 = 0;
  ppppuStack_258 = (undefined4 ****)0x731607;
  (**(code **)(*DAT_00b5acac + 0xc))();
  iVar3 = (unaff_EBX >> 0x18) * 0x27;
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,1);
  *(undefined4 *)(local_1dc + iVar3 + 0x46) = uVar2;
  if (local_208 < (void *)0x10) {
    local_21c = &local_21c;
  }
  iStack_260 = (int)&local_204 + 3;
  puStack_25c = &DAT_009ee8b4;
  uStack_264 = 0x731649;
  ppppuStack_258 = local_21c;
  FUN_0050cd30();
  pcVar4 = acStack_192 + iVar3;
  uVar7 = 0;
  pcVar5 = pcVar4;
  do {
    cVar1 = pcVar5[(int)(local_1dc + (-0x25 - (int)pcVar4))];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_00731676;
    uVar7 = uVar7 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar7 < 0x21);
  *pcVar4 = '\0';
LAB_00731676:
  FUN_00733990();
  (**(code **)(*DAT_00b5acac + 8))();
  (**(code **)(*DAT_00b5aca8 + 0x2c))();
  puVar6 = operator_new(4);
  if (puVar6 != (undefined4 *)0x0) {
    *puVar6 = &PTR_FUN_009ee8cc;
  }
  FUN_00797a20();
  (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3fc = 0xf;
  uStack_400 = 0;
  uStack_410 = 0;
  FUN_00401660();
  uStack_1e0 = 2;
  FUN_00401660(&pvStack_414,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(8);
  (**(code **)(*DAT_00b5aca8 + 0x28))();
  if (0xf < uStack_41c) {
    _free((void *)0xf);
    return;
  }
  uStack_200 = 0;
  FUN_00537c20();
  if (uStack_400 < 0x10) {
    ExceptionList = local_208;
    return;
  }
  _free(pvStack_414);
  return;
}


// ==== FUN_007317a0 @ 0x007317a0 ====

void FUN_007317a0(int param_1)

{
  char cVar1;
  char ****ppppcVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  uint unaff_EBX;
  uint unaff_EBP;
  undefined1 auStack_470 [412];
  undefined4 uStack_2d4;
  undefined *puStack_2d0;
  undefined4 uStack_2cc;
  undefined1 auStack_2c0 [4];
  undefined1 uStack_2bc;
  undefined4 uStack_2b4;
  undefined4 uStack_2b0;
  char *****pppppcStack_2ac;
  undefined4 *****pppppuStack_2a8;
  undefined4 *****pppppuStack_2a4;
  undefined1 *puStack_2a0;
  undefined1 local_298;
  uint uStack_294;
  undefined4 uStack_290;
  undefined4 uStack_28c;
  char *****local_288;
  int local_284;
  undefined4 uStack_270;
  undefined1 local_268 [4];
  undefined4 *****local_264;
  undefined4 uStack_260;
  uint uStack_25c;
  void *local_254;
  undefined4 *****local_250 [3];
  undefined4 uStack_244;
  uint uStack_240;
  uint uStack_23c;
  void *pvStack_238;
  undefined1 uStack_234;
  undefined4 uStack_228;
  uint uStack_224;
  undefined4 uStack_220;
  undefined1 auStack_21c [32];
  undefined1 auStack_1fc [4];
  undefined1 auStack_1f8 [66];
  ushort uStack_1b6;
  void *pvStack_50;
  undefined1 uStack_28;
  undefined1 uStack_24;
  undefined1 uStack_20;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00991ab8;
  pvStack_c = ExceptionList;
  local_288 = (char *****)(param_1 + 0x19);
  uStack_270 = (void *)CONCAT13(*(undefined1 *)(param_1 + 0x18),(undefined3)uStack_270);
  local_250[0] = (undefined4 *****)0xf;
  local_254 = (void *)0x0;
  local_264 = (undefined4 *****)((uint)local_264 & 0xffffff00);
  ppppcVar2 = (char ****)local_288;
  do {
    cVar1 = *(char *)ppppcVar2;
    ppppcVar2 = (char ****)((int)ppppcVar2 + 1);
  } while (cVar1 != '\0');
  local_284 = (int)ppppcVar2 - (param_1 + 0x1a);
  uStack_28c = (undefined1 *)0x7317fe;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  puStack_2a0 = (undefined1 *)0xffffffff;
  pppppuStack_2a4 = (undefined4 *****)0x0;
  pppppuStack_2a8 = (undefined4 *****)local_268;
  local_284 = 0xf;
  local_288 = (char *****)0x0;
  local_4 = 0;
  local_298 = 0;
  pppppcStack_2ac = (char *****)0x731824;
  FUN_00401660();
  puStack_2a0 = (undefined1 *)0x73182f;
  iVar3 = (**(code **)(*DAT_00b5acac + 0x24))();
  *(undefined1 *)(iVar3 + 0x1d) = uStack_28c._3_1_;
  puStack_2a0 = (undefined1 *)0x731841;
  piVar4 = (int *)(**(code **)(*DAT_00b5a980 + 8))();
  if (piVar4 == (int *)0x0) {
    puStack_2a0 = (undefined1 *)0x820075;
    pppppuStack_2a4 = (undefined4 *****)0x0;
    pppppuStack_2a8 = (undefined4 *****)0x73185a;
    uStack_2b0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    pppppuStack_2a8 = (undefined4 *****)0xffffffff;
    pppppcStack_2ac = (char *****)0x0;
    uStack_220 = 0xf;
    uStack_224 = 0;
    uStack_234 = 0;
    uStack_2b4 = 0x731879;
    FUN_00401660();
    uStack_290 = auStack_2c0;
    uStack_2cc = &pvStack_238;
    pppppuStack_2a8 = (void *)0xf;
    pppppcStack_2ac = (char *****)0x0;
    uStack_28 = 1;
    uStack_2bc = 0;
    puStack_2d0 = (undefined *)0x7318a3;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if (0xf < uStack_240) {
      uStack_2cc = (void **)0x7318c8;
      _free(local_254);
      return;
    }
    uStack_240 = 0xf;
    uStack_244 = 0;
    local_254 = (void *)((uint)local_254 & 0xffffff00);
  }
  else {
    puStack_2a0 = (undefined1 *)0x7318f8;
    iVar3 = (**(code **)(*piVar4 + 0x74))();
    pppppuStack_2a4 = (undefined4 *****)(iVar3 + 0x5c);
    local_250[0] = (undefined4 *****)0xf;
    local_254 = (void *)0x0;
    local_264 = (undefined4 *****)((uint)local_264 & 0xffffff00);
    pcVar5 = (char *)pppppuStack_2a4;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    puStack_2a0 = (undefined1 *)((int)pcVar5 - (iVar3 + 0x5d));
    pppppuStack_2a8 = (undefined4 *****)0x731926;
    FUN_00401740();
    uStack_20 = 2;
    pppppuStack_2a4 = local_264;
    if (local_250[0] < (undefined4 ****)0x10) {
      pppppuStack_2a4 = &local_264;
    }
    puStack_2a0 = local_254;
    pppppuStack_2a8 = uStack_270;
    pppppcStack_2ac = (char *****)0x0;
    uStack_2b0 = 0x731956;
    iVar3 = FUN_00403620();
    if (iVar3 == 0) {
      puStack_2a0 = auStack_1f8;
      pppppuStack_2a4 = (undefined4 *****)0x73196d;
      (**(code **)(*DAT_00b5acac + 0xc))();
      uStack_28c = auStack_470;
      uStack_24 = 3;
      uStack_1b6 = (ushort)uStack_290._3_1_;
      FUN_00733990(auStack_1fc);
      (**(code **)(*DAT_00b5acac + 8))();
      uStack_20 = 2;
      puStack_2a0 = (undefined1 *)0x7319be;
      FUN_00537c20();
    }
    puStack_2a0 = (undefined1 *)0x820074;
    pppppuStack_2a4 = (undefined4 *****)0x0;
    pppppuStack_2a8 = (undefined4 *****)0x7319cf;
    uStack_2b0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    pppppuStack_2a8 = (undefined4 *****)0xffffffff;
    pppppcStack_2ac = (char *****)0x0;
    uStack_23c = 0xf;
    uStack_240 = 0;
    local_250[0] = (undefined4 *****)((uint)local_250[0] & 0xffffff00);
    uStack_2b4 = 0x7319e8;
    FUN_00401660();
    uStack_28 = 4;
    pppppuStack_2a8 = local_250[0];
    if (uStack_23c < 0x10) {
      pppppuStack_2a8 = local_250;
    }
    pppppcStack_2ac = local_288;
    if (unaff_EBX < 0x10) {
      pppppcStack_2ac = (char *****)&local_288;
    }
    uStack_290 = auStack_2c0 + -8;
    uStack_2cc = (void **)0x4;
    uStack_2b0 = 0xf;
    uStack_2b4 = 0;
    puStack_2d0 = &DAT_009ee8ac;
    uStack_2d4 = 0x731a2c;
    FUN_00401740();
    uStack_2cc = (void **)auStack_21c;
    puStack_2d0 = (undefined *)0x731a39;
    FUN_00404230();
    uStack_290 = auStack_2c0;
    uStack_2cc = (void **)auStack_21c;
    pppppuStack_2a8 = (void *)0xf;
    pppppcStack_2ac = (char *****)0x0;
    uStack_28 = 5;
    uStack_2bc = 0;
    puStack_2d0 = (undefined *)0x731a63;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    (**(code **)(*DAT_00b5aca8 + 0x28))();
    (**(code **)(*DAT_00b5aca8 + 0x2c))();
    if (0xf < uStack_224) {
      uStack_2cc = (void **)0x731a9c;
      _free(pvStack_238);
      return;
    }
    uStack_224 = 0xf;
    uStack_228 = 0;
    pvStack_238 = (void *)((uint)pvStack_238 & 0xffffff00);
    if (0xf < uStack_25c) {
      uStack_2cc = (void **)0x731ac4;
      _free(uStack_270);
      return;
    }
    uStack_25c = 0xf;
    uStack_260 = 0;
    if (0xf < unaff_EBP) {
      uStack_2cc = (void **)0x731ae3;
      _free(uStack_28c);
      return;
    }
    uStack_28c = (undefined1 *)((uint)uStack_28c & 0xffffff00);
  }
  if (uStack_294 < 0x10) {
    ExceptionList = pvStack_50;
    return;
  }
  uStack_2cc = (void **)0x731b02;
  _free(pppppuStack_2a8);
  return;
}


// ==== FUN_00731b20 @ 0x00731b20 ====

void FUN_00731b20(void)

{
  int unaff_retaddr;
  void *pvStack_ac;
  undefined1 uStack_a8;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  uint uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined1 *puStack_8c;
  undefined4 uStack_88;
  undefined1 auStack_64 [36];
  void *pvStack_40;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00991b22;
  pvStack_c = ExceptionList;
  uStack_88 = 5;
  puStack_8c = (undefined1 *)0x731b46;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined1 *)(unaff_retaddr + 0x18)) {
  case 0:
    puStack_8c = (undefined1 *)0x820001;
    uStack_90 = 0;
    uStack_94 = 0x731b73;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_98 = 0x731b7d;
    FUN_00765c50();
    puStack_8c = (undefined1 *)&pvStack_ac;
    uStack_10 = 0;
    FUN_00765c50();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    (**(code **)(*DAT_00b5aca8 + 0x68))();
    (**(code **)(*DAT_00b5a980 + 8))();
    FUN_00827bf0();
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_40._0_1_ = 1;
    FUN_00401830(s__s___d_DIL__009ee7c4);
    FUN_00404230(auStack_64);
    pvStack_40._0_1_ = 2;
    FUN_00401660();
    pvStack_40 = (void *)CONCAT31(pvStack_40._1_3_,1);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 1:
    puStack_8c = (undefined1 *)0x820002;
    uStack_90 = 0;
    uStack_94 = 0x731cb8;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_98 = 0x731cc2;
    FUN_00765c50();
    uStack_10 = 3;
    break;
  case 2:
    puStack_8c = (undefined1 *)0x820003;
    uStack_90 = 0;
    uStack_94 = 0x731d2f;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_98 = 0x731d39;
    FUN_00765c50();
    puStack_8c = (undefined1 *)&pvStack_ac;
    uStack_10 = 4;
    FUN_00765c50();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    (**(code **)(*DAT_00b5aca8 + 0x68))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 3:
    puStack_8c = (undefined1 *)0x820004;
    uStack_90 = 0;
    uStack_94 = 0x731da6;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_98 = 0x731db0;
    FUN_00765c50();
    uStack_10 = 5;
    break;
  case 4:
    puStack_8c = (undefined1 *)0x820005;
    uStack_90 = 0;
    uStack_94 = 0x731dd2;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_98 = 0x731ddc;
    FUN_00765c50();
    uStack_10 = 6;
    goto LAB_00731e94;
  case 5:
    puStack_8c = (undefined1 *)0x820006;
    uStack_90 = 0;
    uStack_94 = 0x731dfe;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_98 = 0x731e08;
    FUN_00765c50();
    uStack_10 = 7;
    break;
  case 6:
    puStack_8c = (undefined1 *)0x820007;
    uStack_90 = 0;
    uStack_94 = 0x731e2a;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_98 = 0x731e34;
    FUN_00765c50();
    uStack_10 = 8;
    goto LAB_00731e94;
  case 7:
    puStack_8c = (undefined1 *)0x820008;
    uStack_90 = 0;
    uStack_94 = 0x731e53;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_98 = 0x731e5d;
    FUN_00765c50();
    uStack_10 = 9;
    break;
  case 8:
    puStack_8c = (undefined1 *)0x820009;
    uStack_90 = 0;
    uStack_94 = 0x731e7f;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_98 = 0x731e89;
    FUN_00765c50();
    uStack_10 = 10;
LAB_00731e94:
    puStack_8c = (undefined1 *)&pvStack_ac;
    FUN_00765c50();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    (**(code **)(*DAT_00b5aca8 + 0x68))();
    goto LAB_00731cff;
  default:
    puStack_8c = &DAT_0082000a;
    uStack_90 = 0;
    uStack_94 = 0x731edd;
    uStack_9c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_94 = 0xffffffff;
    uStack_98 = 0;
    uStack_a0 = 0x731f01;
    FUN_00401660();
    puStack_8c = (undefined1 *)&pvStack_ac;
    uStack_94 = 0xf;
    uStack_98 = 0;
    uStack_10 = 0xb;
    uStack_a8 = 0;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    (**(code **)(*DAT_00b5aca8 + 0x68))();
    if (uStack_98 < 0x10) {
      ExceptionList = pvStack_40;
      return;
    }
    _free(pvStack_ac);
    return;
  }
  puStack_8c = (undefined1 *)&pvStack_ac;
  FUN_00765c50();
  (**(code **)(*DAT_00b5ad0c + 0x28))();
  (**(code **)(*DAT_00b5aca8 + 0x68))();
LAB_00731cff:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00731fa0 @ 0x00731fa0 ====

void FUN_00731fa0(void)

{
  int unaff_retaddr;
  undefined1 auStack_dc [20];
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 ***pppuStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined1 *puStack_b4;
  undefined1 *puStack_b0;
  undefined4 ***apppuStack_ac [5];
  uint uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined1 *puStack_8c;
  undefined4 uStack_88;
  undefined1 auStack_6c [16];
  undefined1 auStack_5c [12];
  undefined1 auStack_50 [24];
  undefined1 uStack_38;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00991b74;
  pvStack_c = ExceptionList;
  uStack_88 = 5;
  puStack_8c = (undefined1 *)0x731fc6;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined1 *)(unaff_retaddr + 0x20)) {
  case 0:
    puStack_8c = (undefined1 *)0x82000f;
    uStack_90 = 0;
    uStack_94 = 0x731ff3;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_98 = 0x731ffd;
    FUN_00765c50();
    puStack_8c = (undefined1 *)apppuStack_ac;
    puStack_b0 = auStack_6c;
    pvStack_10 = (void *)0x0;
    puStack_b4 = (undefined1 *)0x73201b;
    FUN_00765c50();
    puStack_b0 = (undefined1 *)0x8;
    puStack_b4 = (undefined1 *)0x732028;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    puStack_b4 = *(undefined1 **)(unaff_retaddr + 0x18);
    uStack_b8 = 0x732037;
    uStack_b8 = (**(code **)(*DAT_00b5a980 + 8))();
    uStack_bc = 0x73203d;
    FUN_00827bf0();
    puStack_b4 = (undefined1 *)0x820053;
    uStack_b8 = 0;
    uStack_bc = 0x732052;
    uStack_bc = (**(code **)(*DAT_00b5a794 + 0xc))();
    pppuStack_c0 = (undefined4 ***)0x73205c;
    FUN_00765c50();
    uStack_bc = *(undefined4 *)(unaff_retaddr + 0x18);
    uStack_38 = 1;
    if (uStack_98 < 0x10) {
      apppuStack_ac[0] = apppuStack_ac;
    }
    puStack_b4 = auStack_dc;
    pppuStack_c0 = apppuStack_ac[0];
    FUN_00401830(s__s___d_DIL__009ee7d0);
    uStack_c4 = FUN_00404230(auStack_5c);
    uStack_bc = 0xffffffff;
    pppuStack_c0 = (undefined4 ***)0x0;
    uStack_38 = 2;
    uStack_c8 = 0x7320b1;
    FUN_00401660();
    uStack_38 = 1;
                    /* WARNING: Subroutine does not return */
    uStack_bc = 0x7320c2;
    FUN_00446f10();
  case 1:
    puStack_8c = (undefined1 *)0x820054;
    uStack_90 = 0;
    uStack_94 = 0x732148;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_98 = 0x732152;
    FUN_00765c50();
    puStack_8c = (undefined1 *)apppuStack_ac;
    puStack_b0 = auStack_6c;
    pvStack_10 = (void *)0x4;
    puStack_b4 = (undefined1 *)0x732170;
    FUN_00765c50();
    puStack_b0 = (undefined1 *)0x8;
    puStack_b4 = (undefined1 *)0x73217d;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    goto LAB_00732297;
  case 2:
    puStack_8c = (undefined1 *)0x820088;
    uStack_90 = 0;
    uStack_94 = 0x73211c;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_98 = 0x732126;
    FUN_00765c50();
    pvStack_10 = (void *)0x3;
    break;
  case 3:
    puStack_8c = &DAT_0082000c;
    uStack_90 = 0;
    uStack_94 = 0x732198;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_98 = 0x7321a2;
    FUN_00765c50();
    pvStack_10 = (void *)0x5;
    break;
  case 4:
    puStack_8c = (undefined1 *)0x82000d;
    uStack_90 = 0;
    uStack_94 = 0x7321c1;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_98 = 0x7321cb;
    FUN_00765c50();
    puStack_8c = (undefined1 *)apppuStack_ac;
    puStack_b0 = auStack_6c;
    pvStack_10 = (void *)0x6;
    puStack_b4 = (undefined1 *)0x7321e9;
    FUN_00765c50();
    puStack_b0 = (undefined1 *)0x8;
    puStack_b4 = (undefined1 *)0x7321f6;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    goto LAB_00732297;
  case 5:
    puStack_8c = (undefined1 *)0x82000e;
    uStack_90 = 0;
    uStack_94 = 0x73225e;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_98 = 0x732268;
    FUN_00765c50();
    puStack_8c = (undefined1 *)apppuStack_ac;
    puStack_b0 = auStack_50;
    pvStack_10 = (void *)0x8;
    puStack_b4 = (undefined1 *)0x732286;
    FUN_00765c50();
    puStack_b0 = (undefined1 *)0x8;
    puStack_b4 = (undefined1 *)0x732293;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    goto LAB_00732297;
  case 6:
  case 7:
  case 8:
  case 9:
    puStack_8c = (undefined1 *)0x8200e9;
    uStack_90 = 0;
    uStack_94 = 0x732211;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_98 = 0x73221b;
    FUN_00765c50();
    pvStack_10 = (void *)0x7;
    break;
  default:
    ExceptionList = pvStack_10;
    return;
  }
  puStack_8c = (undefined1 *)apppuStack_ac;
  puStack_b0 = auStack_6c;
  puStack_b4 = (undefined1 *)0x732239;
  FUN_00765c50();
  puStack_b0 = (undefined1 *)0x8;
  puStack_b4 = (undefined1 *)0x732246;
  (**(code **)(*DAT_00b5ad0c + 0x28))();
LAB_00732297:
                    /* WARNING: Subroutine does not return */
  puStack_b4 = (undefined1 *)0x73229c;
  FUN_00446f10();
}


// ==== FUN_007322e0 @ 0x007322e0 ====

/* WARNING: Removing unreachable block (ram,0x00732449) */
/* WARNING: Removing unreachable block (ram,0x007324b3) */
/* WARNING: Removing unreachable block (ram,0x007324c0) */

void FUN_007322e0(int param_1)

{
  char cVar1;
  char *pcVar2;
  uint uStack_1e8;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00991baa;
  pvStack_c = ExceptionList;
  pcVar2 = (char *)(param_1 + 0x18);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = 0;
  FUN_00401660();
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401ff0();
  FUN_00401740();
  FUN_00404230();
  pvStack_c._0_1_ = 2;
  FUN_00401ff0();
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
  if (uStack_1e8 < 0x10) {
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401ff0();
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    _free((void *)0x0);
    return;
  }
  _free((void *)0xf);
  return;
}


// ==== FUN_007324e0 @ 0x007324e0 ====

/* WARNING: Removing unreachable block (ram,0x00732608) */

void FUN_007324e0(void)

{
  void *pvStack_1fc;
  uint uStack_1e8;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00991bd5;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401660();
  pvStack_c = (void *)0x0;
  FUN_00401740();
  FUN_00404230();
  pvStack_c._0_1_ = 1;
  FUN_00401ff0();
  pvStack_c = (void *)((uint)pvStack_c._1_3_ << 8);
  if (uStack_1e8 < 0x10) {
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401ff0();
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    _free((void *)0x0);
    return;
  }
  _free(pvStack_1fc);
  return;
}


// ==== FUN_007326a0 @ 0x007326a0 ====

void FUN_007326a0(int param_1)

{
  char cVar1;
  char *pcVar2;
  void **unaff_ESI;
  undefined1 auStack_de [2];
  undefined1 auStack_dc [4];
  undefined1 uStack_d8;
  undefined4 uStack_d0;
  void *pvStack_cc;
  void **ppvStack_c8;
  undefined4 ****ppppuStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  uint uStack_b8;
  undefined1 uStack_b4;
  void *pvStack_b0;
  undefined4 ****ppppuStack_ac;
  undefined1 *puStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  uint uStack_9c;
  uint local_98;
  void *apvStack_94 [3];
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  void *local_7c;
  uint uStack_60;
  undefined1 auStack_54 [8];
  undefined1 uStack_4c;
  undefined1 *puStack_44;
  undefined1 local_30 [4];
  undefined1 local_2c;
  undefined1 *puStack_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined2 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00991bf7;
  pvStack_c = ExceptionList;
  local_18 = 0xf;
  local_1c = 0;
  local_2c = 0;
  local_80 = (char *)(param_1 + 0x22);
  local_4 = 0;
  pcVar2 = local_80;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  local_7c = (void *)((int)pcVar2 - (param_1 + 0x23));
  local_84 = 0x7326f6;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_14 = *(undefined1 *)(param_1 + 0x1a);
  local_13 = *(undefined1 *)(param_1 + 0x1e);
  local_10 = *(undefined2 *)(param_1 + 0x18);
  uStack_a0 = 0xffffffff;
  local_12 = 1;
  uStack_a4 = 0;
  puStack_a8 = local_30;
  local_84 = 0xf;
  local_88 = 0;
  local_98 = local_98 & 0xffffff00;
  ppppuStack_ac = (undefined4 ****)0x732744;
  FUN_00401660();
  pcVar2 = local_80;
  local_80._3_1_ = SUB41(pcVar2,3);
  local_80._0_3_ = CONCAT12(local_12,CONCAT11(local_13,local_14));
  local_7c = (void *)CONCAT22(local_7c._2_2_,local_10);
  uStack_a0 = 0x73277b;
  (**(code **)(*DAT_00b5acac + 0x18))();
  puStack_20 = (undefined1 *)&uStack_b8;
  uStack_bc = 0xffffffff;
  uStack_c0 = 0;
  ppppuStack_c4 = (undefined4 ****)auStack_54;
  uStack_a0 = 0xf;
  uStack_a4 = 0;
  uStack_b4 = 0;
  ppvStack_c8 = (void **)0x73279d;
  FUN_00401660();
  uStack_bc = 0x7327ab;
  (**(code **)(*DAT_00b5aca8 + 0xe8))();
  uStack_bc = 0x7327b6;
  (**(code **)(*DAT_00b5aca8 + 0x2c))();
  uStack_bc = 0x82006d;
  uStack_c0 = 0;
  ppppuStack_c4 = (undefined4 ****)0x7327c7;
  pvStack_cc = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
  ppppuStack_c4 = (undefined4 ****)0xffffffff;
  ppvStack_c8 = (void **)0x0;
  local_98 = 0xf;
  uStack_9c = 0;
  ppppuStack_ac = (undefined4 ****)((uint)ppppuStack_ac & 0xffffff00);
  uStack_d0 = 0x7327e0;
  FUN_00401660();
  uStack_4c = 1;
  ppppuStack_c4 = ppppuStack_ac;
  if (local_98 < 0x10) {
    ppppuStack_c4 = &ppppuStack_ac;
  }
  ppvStack_c8 = unaff_ESI;
  if (uStack_60 < 0x10) {
    ppvStack_c8 = apvStack_94 + 8;
  }
  puStack_44 = auStack_de + -6;
  pvStack_cc = (void *)0xf;
  uStack_d0 = 0;
  FUN_00401740(&DAT_009ee7ec,4);
  FUN_00404230(apvStack_94);
  puStack_44 = auStack_dc;
  ppppuStack_c4 = (undefined4 ****)0xf;
  ppvStack_c8 = (void **)0x0;
  uStack_4c = 2;
  uStack_d8 = 0;
  FUN_00401660(apvStack_94);
  (**(code **)(*DAT_00b5ad0c + 0x28))();
  (**(code **)(*DAT_00b5aca8 + 0x28))();
  (**(code **)(*DAT_00b5aca8 + 0x2c))();
  if (0xf < uStack_9c) {
    _free(pvStack_b0);
    return;
  }
  uStack_9c = 0xf;
  uStack_a0 = 0;
  pvStack_b0 = (void *)((uint)pvStack_b0 & 0xffffff00);
  if (0xf < uStack_b8) {
    _free(pvStack_cc);
    return;
  }
  uStack_b8 = 0xf;
  uStack_bc = 0;
  pvStack_cc = (void *)((uint)pvStack_cc & 0xffffff00);
  if (local_80 < 0x10) {
    ExceptionList = unaff_ESI;
    return;
  }
  _free(apvStack_94[0]);
  return;
}


// ==== FUN_007328f0 @ 0x007328f0 ====

void FUN_007328f0(int param_1)

{
  char cVar1;
  char *pcVar2;
  uint unaff_EDI;
  void *pvStack_50;
  void *local_30;
  undefined1 local_2c;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined2 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00991c09;
  pvStack_c = ExceptionList;
  local_18 = 0xf;
  local_1c = 0;
  local_2c = 0;
  pcVar2 = (char *)(param_1 + 0x31);
  local_4 = 0;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_14 = *(undefined1 *)(param_1 + 0x4c);
  local_13 = *(undefined1 *)(param_1 + 0x50);
  local_10 = *(undefined2 *)(param_1 + 0x4a);
  local_12 = 1;
  FUN_00401660(&local_30,0,0xffffffff);
  (**(code **)(*DAT_00b5acac + 0x18))();
  (**(code **)(*DAT_00b5aca8 + 0x2c))();
  if (unaff_EDI < 0x10) {
    ExceptionList = local_30;
    return;
  }
  _free(pvStack_50);
  return;
}


// ==== FUN_007329f0 @ 0x007329f0 ====

void FUN_007329f0(int param_1)

{
  char cVar1;
  char *pcVar2;
  uint unaff_EDI;
  void *pvStack_50;
  void *local_30;
  undefined1 local_2c;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined2 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00991c1b;
  pvStack_c = ExceptionList;
  local_18 = 0xf;
  local_1c = 0;
  local_2c = 0;
  pcVar2 = (char *)(param_1 + 0x22);
  local_4 = 0;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_14 = *(undefined1 *)(param_1 + 0x1a);
  local_13 = *(undefined1 *)(param_1 + 0x1e);
  local_10 = *(undefined2 *)(param_1 + 0x18);
  local_12 = 1;
  FUN_00401660(&local_30,0,0xffffffff);
  (**(code **)(*DAT_00b5acac + 0x18))();
  (**(code **)(*DAT_00b5aca8 + 0x2c))();
  if (unaff_EDI < 0x10) {
    ExceptionList = local_30;
    return;
  }
  _free(pvStack_50);
  return;
}


// ==== FUN_00732af0 @ 0x00732af0 ====

void FUN_00732af0(int param_1)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  undefined *puStack_13c;
  undefined1 *puStack_138;
  undefined4 **ppuStack_134;
  uint uStack_130;
  undefined4 **ppuStack_12c;
  uint uStack_128;
  undefined4 uStack_124;
  undefined4 ****ppppuStack_120;
  undefined4 ****ppppuStack_11c;
  undefined4 *puStack_118;
  undefined4 ****ppppuStack_114;
  undefined4 uStack_110;
  undefined1 *local_10c;
  undefined1 *puStack_108;
  undefined1 local_104;
  undefined4 ****ppppuStack_100;
  undefined4 ****local_fc;
  undefined4 ****local_f8;
  undefined4 local_f4;
  undefined4 local_dc;
  void *pvStack_d4;
  undefined4 ****ppppuStack_c8;
  undefined4 ****ppppuStack_c4;
  uint uStack_c0;
  undefined1 local_bc [4];
  void *local_b8;
  uint uStack_b4;
  uint uStack_b0;
  undefined4 local_a8;
  uint local_a4;
  undefined1 local_a0 [4];
  void *local_9c;
  undefined4 local_8c;
  uint local_88;
  undefined4 ****local_84;
  undefined2 local_80;
  void *pvStack_78;
  uint uStack_70;
  undefined4 uStack_68;
  undefined4 ****appppuStack_64 [5];
  uint uStack_50;
  undefined4 ****appppuStack_48 [5];
  uint uStack_34;
  undefined1 uStack_30;
  undefined1 uStack_28;
  undefined1 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00991ca5;
  pvStack_c = ExceptionList;
  cVar1 = *(char *)(param_1 + 0x31);
  if (cVar1 == '\0') {
    local_88 = 0xf;
    local_8c = 0;
    local_9c = (void *)((uint)local_9c & 0xffffff00);
    local_f4 = (char *)(param_1 + 0x18);
    local_4 = 0;
    local_84 = (undefined4 ****)((uint)local_84 & 0xff000000);
    local_80 = 0;
    pcVar2 = local_f4;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    local_f8 = (undefined4 ****)0x732b67;
    ExceptionList = &pvStack_c;
    FUN_00401740();
    local_dc = (undefined1 **)&uStack_110;
    ppppuStack_114 = (undefined4 ****)0xffffffff;
    puStack_118 = (undefined4 *)0x0;
    ppppuStack_11c = (undefined4 ****)local_a0;
    local_f8 = (undefined4 ****)0xf;
    local_fc = (undefined4 ****)0x0;
    local_10c = (undefined1 *)((uint)local_10c & 0xffffff00);
    ppppuStack_120 = (undefined4 ****)0x732b88;
    FUN_00401660();
    local_f4._0_3_ = SUB43(local_84,0);
    ppppuStack_114 = (undefined4 ****)0x732bbd;
    (**(code **)(*DAT_00b5acac + 0x14))();
    ppppuStack_114 = (undefined4 ****)0x82006e;
    puStack_118 = (undefined4 *)0x0;
    ppppuStack_11c = (undefined4 ****)0x732bce;
    uStack_124 = (**(code **)(*DAT_00b5a794 + 0xc))();
    ppppuStack_11c = (undefined4 ****)0xffffffff;
    ppppuStack_120 = (undefined4 ****)0x0;
    ppppuStack_100 = (undefined4 ****)((uint)ppppuStack_100 & 0xffffff00);
    uStack_128 = 0x732be7;
    FUN_00401660();
    uStack_30 = 1;
    ppppuStack_11c = &ppppuStack_100;
    if (uStack_b4 < 0x10) {
      ppppuStack_c8 = &ppppuStack_c8;
    }
    puStack_108 = (undefined1 *)&puStack_13c;
    uStack_124 = 0xf;
    uStack_128 = 0;
    puStack_138 = (undefined1 *)((uint)puStack_138 & 0xffffff00);
    ppppuStack_120 = ppppuStack_c8;
    FUN_00401740(&DAT_009ee7f4,4);
    FUN_00404230(local_bc + -0x2c);
    puStack_108 = (undefined1 *)&ppuStack_134;
    puStack_138 = (undefined1 *)0xffffffff;
    puStack_13c = (undefined *)0x0;
    ppppuStack_11c = (undefined4 ****)0xf;
    ppppuStack_120 = (undefined4 ****)0x0;
    uStack_30 = 2;
    uStack_130 = uStack_130 & 0xffffff00;
    FUN_00401660(local_bc + -0x2c);
    puStack_138 = (undefined1 *)0x8;
    puStack_13c = (undefined *)0x732c6e;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if (0xf < local_a4) {
      local_f4 = (char *)0x732c7e;
      _free(local_b8);
      return;
    }
    local_a4 = 0xf;
    local_a8 = 0;
    local_b8 = (void *)((uint)local_b8 & 0xffffff00);
    if (0xf < uStack_c0) {
      local_f4 = (char *)0x732c9d;
      _free(pvStack_d4);
      return;
    }
    uStack_c0 = 0xf;
    ppppuStack_c4 = (undefined4 ****)0x0;
    pvStack_d4 = (void *)((uint)pvStack_d4 & 0xffffff00);
    local_4 = 0xffffffff;
    if (0xf < local_88) {
      local_f4 = (char *)0x732ccb;
      _free(local_9c);
      return;
    }
  }
  else if (cVar1 == '\x01') {
    local_f4 = (char *)(param_1 + 0x18);
    local_a4 = 0xf;
    local_a8 = 0;
    local_b8 = (void *)((uint)local_b8 & 0xffffff00);
    pcVar2 = local_f4;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    local_f8 = (undefined4 ****)0x732d0b;
    ExceptionList = &pvStack_c;
    FUN_00401740();
    local_dc = &puStack_108;
    local_10c = (undefined1 *)0xffffffff;
    uStack_110 = 0;
    ppppuStack_114 = (undefined4 ****)local_bc;
    local_f4 = (char *)0x0;
    local_4 = 3;
    local_104 = 0;
    puStack_118 = (undefined4 *)0x732d35;
    FUN_00401660();
    local_10c = (undefined1 *)0x732d40;
    (**(code **)(*DAT_00b5acac + 0x28))();
    local_10c = (undefined1 *)0x820040;
    uStack_110 = 0;
    ppppuStack_114 = (undefined4 ****)0x732d51;
    ppppuStack_11c = (undefined4 ****)(**(code **)(*DAT_00b5a794 + 0xc))();
    ppppuStack_114 = (undefined4 ****)0xffffffff;
    puStack_118 = (undefined4 *)0x0;
    local_f8 = (undefined4 ****)((uint)local_f8 & 0xffffff00);
    ppppuStack_120 = (undefined4 ****)0x732d6a;
    FUN_00401660();
    uStack_28 = 4;
    ppppuStack_114 = &local_f8;
    puStack_118 = local_dc;
    if (ppppuStack_c8 < (undefined4 ****)0x10) {
      puStack_118 = &local_dc;
    }
    ppppuStack_100 = (undefined4 ****)&ppuStack_134;
    puStack_138 = (undefined1 *)0x4;
    ppppuStack_11c = (undefined4 ****)0xf;
    ppppuStack_120 = (undefined4 ****)0x0;
    puStack_13c = &DAT_009ee7fc;
    uStack_130 = uStack_130 & 0xffffff00;
    FUN_00401740();
    puStack_138 = local_a0;
    puStack_13c = (undefined *)0x732dc0;
    FUN_00404230();
    ppppuStack_100 = (undefined4 ****)&ppuStack_12c;
    uStack_130 = 0xffffffff;
    ppuStack_134 = (undefined4 **)0x0;
    puStack_138 = local_a0;
    ppppuStack_114 = (undefined4 ****)0xf;
    puStack_118 = (undefined4 *)0x0;
    uStack_28 = 5;
    uStack_128 = uStack_128 & 0xffffff00;
    puStack_13c = (undefined *)0x732dea;
    FUN_00401660();
    uStack_130 = 8;
    ppuStack_134 = (undefined4 **)0x732df7;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if ((undefined4 ****)0xf < appppuStack_64[0]) {
      local_f4 = (char *)0x732e0a;
      _free(pvStack_78);
      return;
    }
    appppuStack_64[0] = (undefined4 ****)0xf;
    uStack_68 = 0;
    pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
    if (0xf < uStack_c0) {
      local_f4 = (char *)0x732e2f;
      _free(pvStack_d4);
      return;
    }
    uStack_c0 = 0xf;
    ppppuStack_c4 = (undefined4 ****)0x0;
    pvStack_d4 = (void *)((uint)pvStack_d4 & 0xffffff00);
    local_4 = 0xffffffff;
    if (0xf < local_a4) {
      local_f4 = (char *)0x732e5d;
      _free(local_b8);
      return;
    }
  }
  else {
    if (cVar1 == '\x02') {
      local_f4 = (char *)0x732e7b;
      ExceptionList = &pvStack_c;
      FUN_00401830();
      local_4 = 6;
      piVar3 = (int *)(**(code **)(*DAT_00b5a980 + 8))();
      if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      (**(code **)(*piVar3 + 0x74))();
      local_f4 = (char *)0x732eba;
      FUN_00401830();
      local_f4 = local_bc;
      local_4 = CONCAT31(local_4._1_3_,7);
      local_f8 = (undefined4 ****)0x732ed4;
      cVar1 = FUN_00423420();
      if (cVar1 == '\0') {
        local_dc = &puStack_108;
        local_10c = local_bc;
        uStack_110 = 0x732f20;
        FUN_00765c50();
        local_10c = (undefined1 *)0x732f2b;
        (**(code **)(*DAT_00b5acac + 0x28))();
      }
      else {
        (**(code **)(*DAT_00b5aca8 + 0x80))();
        local_f4 = (char *)0x732ef5;
        (**(code **)(*DAT_00b5aca8 + 0xc))();
        local_f4 = (char *)0x732f00;
        (**(code **)(*DAT_00b5acac + 0x10))();
        local_f4 = (char *)0x732f0b;
        (**(code **)(*DAT_00b5ac98 + 0x50))();
      }
      local_f4 = (char *)0x82003f;
      local_f8 = (undefined4 ****)0x0;
      local_fc = (undefined4 ****)0x732f3c;
      local_fc = (undefined4 ****)(**(code **)(*DAT_00b5a794 + 0xc))();
      ppppuStack_100 = (undefined4 ****)0x732f46;
      FUN_00765c50();
      uStack_10 = 8;
      if (uStack_70 < 0x10) {
        local_84 = &local_84;
      }
      if (uStack_b0 < 0x10) {
        ppppuStack_c4 = &ppppuStack_c4;
      }
      ppppuStack_120 = (undefined4 ****)&DAT_009ee804;
      uStack_124 = 0x732f87;
      ppppuStack_100 = ppppuStack_c4;
      local_fc = local_84;
      FUN_00401830();
      ppppuStack_120 = (undefined4 ****)(local_bc + -0x28);
      uStack_124 = 0x732f91;
      FUN_00404230();
      puStack_118 = (undefined4 *)(local_bc + -0x28);
      uStack_10 = 9;
      ppppuStack_11c = (undefined4 ****)0x732fac;
      FUN_00765c50();
      puStack_118 = (undefined4 *)0x8;
      ppppuStack_11c = (undefined4 ****)0x732fb9;
      (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
      ppppuStack_11c = (undefined4 ****)0x732fc2;
      FUN_00446f10();
    }
    ExceptionList = &pvStack_c;
    if (cVar1 == '\x03') {
      local_f4 = (char *)0x732ff9;
      ExceptionList = &pvStack_c;
      FUN_00401830();
      local_f4 = (char *)0x0;
      local_4 = 10;
      local_f8 = (undefined4 ****)0x733015;
      local_f8 = (undefined4 ****)(**(code **)(*DAT_00b5a794 + 0xc))();
      local_fc = (undefined4 ****)0x733022;
      FUN_00765c50();
      pvStack_c._0_1_ = 0xb;
      if (uStack_50 < 0x10) {
        appppuStack_64[0] = appppuStack_64;
      }
      if (uStack_34 < 0x10) {
        appppuStack_48[0] = appppuStack_48;
      }
      ppppuStack_11c = (undefined4 ****)&DAT_009ee80c;
      ppppuStack_120 = (undefined4 ****)0x733072;
      local_fc = appppuStack_48[0];
      local_f8 = appppuStack_64[0];
      FUN_00401830();
      ppppuStack_11c = (undefined4 ****)&local_a8;
      ppppuStack_120 = (undefined4 ****)0x73307c;
      FUN_00404230();
      ppppuStack_114 = (undefined4 ****)&local_a8;
      pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,0xc);
      puStack_118 = (undefined4 *)0x733097;
      FUN_00765c50();
      ppppuStack_114 = (undefined4 ****)0x8;
      puStack_118 = (undefined4 *)0x7330a4;
      (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
      puStack_118 = (undefined4 *)0x7330ad;
      FUN_00446f10();
    }
  }
  local_4 = 0xffffffff;
  (**(code **)(*DAT_00b5aca8 + 0x2c))();
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00733100 @ 0x00733100 ====

void FUN_00733100(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  undefined4 *puVar5;
  byte *pbVar6;
  int unaff_retaddr;
  undefined1 auStack_414 [4];
  undefined1 uStack_410;
  undefined4 uStack_408;
  undefined4 uStack_404;
  undefined4 uStack_400;
  undefined4 uStack_3fc;
  undefined4 uStack_3f8;
  byte *pbStack_3d0;
  void *pvStack_3c8;
  uint uStack_3b4;
  undefined1 auStack_3b0 [46];
  byte abStack_382 [6];
  char acStack_37c [412];
  void *pvStack_1e0;
  undefined4 uStack_1d8;
  undefined1 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00991cd0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00733920();
  local_4 = 0;
  (**(code **)(*DAT_00b5acac + 0xc))();
  puStack_8._0_1_ = 1;
  uStack_3f8 = 0x733156;
  FUN_00733a40();
  puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
  FUN_00537c20();
  pbStack_3d0 = abStack_382 + (2 - unaff_retaddr);
  bVar3 = 0;
  puVar5 = (undefined4 *)(unaff_retaddr + 0x1a);
  pbVar6 = abStack_382 + (1 - unaff_retaddr);
  do {
    (abStack_382 + -unaff_retaddr)[(int)puVar5] = *(byte *)((int)puVar5 + -2);
    bVar1 = *(byte *)((int)puVar5 + -1);
    *(undefined4 *)(pbStack_3d0 + (int)puVar5) = *puVar5;
    pbVar6[(int)puVar5] = bVar1;
    uVar4 = 0;
    do {
      cVar2 = *(char *)((int)puVar5 + uVar4 + 4);
      (acStack_37c + -unaff_retaddr + (int)puVar5)[uVar4] = cVar2;
      if (cVar2 == '\0') goto LAB_007331e5;
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x21);
    (acStack_37c + -unaff_retaddr)[(int)puVar5] = '\0';
LAB_007331e5:
    if (pbVar6[(int)puVar5] != bVar3) {
      uStack_3f8 = 0;
      uStack_3fc = 0x733203;
      uStack_404 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_3fc = 0xffffffff;
      uStack_400 = 0;
      pbStack_3d0 = (byte *)((uint)pbStack_3d0 & 0xffffff00);
      uStack_408 = 0x73321c;
      FUN_00401660();
      bVar3 = (byte)((uint)auStack_414 >> 0x18);
      uStack_3fc = 0xf;
      uStack_400 = 0;
      uStack_10 = 2;
      uStack_410 = 0;
      FUN_00401660();
      (**(code **)(*DAT_00b5ad0c + 0x28))();
      pbVar6[(int)puVar5] = (byte)((uint)auStack_414 >> 0x18);
      puStack_8 = (undefined1 *)((uint)puStack_8 & 0xffffff00);
      if (0xf < uStack_3b4) {
        uStack_3f8 = 0x73326f;
        _free(pvStack_3c8);
        return;
      }
      uStack_3b4 = 0xf;
      pvStack_3c8 = (void *)((uint)pvStack_3c8 & 0xffffff00);
    }
    bVar3 = bVar3 + 1;
    puVar5 = (undefined4 *)((int)puVar5 + 0x27);
    if (9 < bVar3) {
      FUN_00733990(auStack_3b0);
      (**(code **)(*DAT_00b5acac + 8))();
      uStack_1d8 = 0xffffffff;
      FUN_00537c20();
      ExceptionList = pvStack_1e0;
      return;
    }
  } while( true );
}


// ==== FUN_007332f0 @ 0x007332f0 ====

undefined4 FUN_007332f0(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined2 extraout_var;
  
  uVar2 = FUN_00424500();
  if (uVar2 < 0x11010005) {
    if (uVar2 == 0x11010004) {
      FUN_0072e0f0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar2 < 0x9020004) {
      if (uVar2 == 0x9020003) {
        FUN_0072fc90(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar2 < 0x900000d) {
        if (uVar2 == 0x900000c) {
switchD_0073333d_caseD_8:
          return 1;
        }
        switch(uVar2 + 0xf6ffffff) {
        case 0:
          FUN_00731b20(*(undefined4 *)(param_1 + 0xc));
          return 1;
        default:
          goto switchD_0073333d_caseD_1;
        case 3:
          (**(code **)(*DAT_00b5aca8 + 0x38))();
          return 1;
        case 5:
          FUN_0072db60(*(undefined4 *)(param_1 + 0xc));
          return 1;
        case 6:
          (**(code **)(*DAT_00b5aca8 + 0x3c))();
          return 1;
        case 8:
          goto switchD_0073333d_caseD_8;
        case 9:
          (**(code **)(*DAT_00b5aca8 + 0x30))();
          return 1;
        }
      }
      if (uVar2 < 0x9010001) {
        if (uVar2 == 0x9010000) {
          FUN_00730400(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
        if (uVar2 == 0x9000010) {
          FUN_0072ed00(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
        if (uVar2 == 0x9000011) {
          (**(code **)(*DAT_00b5aca8 + 0x8c))();
          return 1;
        }
        if (uVar2 == 0x9000013) {
          FUN_0072db80(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
      }
      else {
        if (uVar2 == 0x9010001) {
          FUN_0072e020(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
        if (uVar2 == 0x9020002) {
          FUN_0072fa80(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
      }
    }
    else if (uVar2 < 0x11000005) {
      if (uVar2 == 0x11000004) {
        FUN_0072dbb0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar2 < 0x9030004) {
        if (uVar2 == 0x9030003) {
          FUN_0072f3b0(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
        if (uVar2 == 0x9020004) {
          FUN_0072f8d0(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
        if (uVar2 == 0x9020005) {
          return 1;
        }
        if (uVar2 == 0x9030001) {
          FUN_0072f1e0(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
      }
      else {
        if (uVar2 == 0x9030004) {
          FUN_0072f6a0(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
        if (uVar2 == 0x9030006) {
          FUN_0072dbd0(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
      }
    }
    else if (uVar2 < 0x11000008) {
      if (uVar2 == 0x11000007) {
        FUN_007307b0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar2 == 0x11000005) {
        FUN_00730580(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar2 == 0x11000006) {
        FUN_00733100(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
    }
    else {
      if (uVar2 == 0x11000008) {
        FUN_0072dbf0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar2 == 0x11010001) {
        FUN_0072eef0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
    }
  }
  else if (uVar2 < 0x11010019) {
    if (uVar2 == 0x11010018) {
      iVar1 = *DAT_00b5aca8;
      uVar3 = (**(code **)(*DAT_00b5a97c + 0xc))
                        (CONCAT22(extraout_var,*(undefined2 *)(*(int *)(param_1 + 0xc) + 0x18)));
      (**(code **)(iVar1 + 0x7c))(uVar3);
      return 1;
    }
    switch(uVar2 + 0xeefefffb) {
    case 0:
      FUN_00730f90(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 2:
      FUN_00731fa0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 3:
      FUN_007310f0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 5:
      FUN_0072e330(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 6:
      FUN_00731260(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 8:
      FUN_0072e4f0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 0xb:
      FUN_0072e6b0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 0xc:
      FUN_00731590(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  else if (uVar2 < 0x11030003) {
    if (uVar2 == 0x11030002) {
      FUN_0072dc60(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar2 < 0x1102000c) {
      if (uVar2 == 0x1102000b) {
        FUN_007317a0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      switch(uVar2) {
      case 0x11020000:
        FUN_00732af0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      case 0x11020006:
        FUN_0072feb0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      case 0x11020008:
        FUN_00730130(*(undefined4 *)(param_1 + 0xc));
        return 1;
      case 0x1102000a:
        FUN_0072e8a0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
    }
    else {
      if (uVar2 == 0x1102000d) {
        FUN_0072ea90(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar2 == 0x11030000) {
        FUN_00730a20(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar2 == 0x11030001) {
        FUN_00730dd0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
    }
  }
  else if (uVar2 < 0x11050001) {
    if (uVar2 == 0x11050000) {
      FUN_007322e0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    switch(uVar2 + 0xeefcfffd) {
    case 0:
      FUN_007326a0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 1:
      FUN_007328f0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 2:
      FUN_007329f0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 3:
      FUN_00730340(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 4:
      FUN_00730be0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 5:
      FUN_0072dea0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  else if (uVar2 == 0x11050001) {
    FUN_007324e0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
switchD_0073333d_caseD_1:
  return 0;
}


// ==== FUN_007338c0 @ 0x007338c0 ====

undefined4 FUN_007338c0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_007332f0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007338f0 @ 0x007338f0 ====

undefined4 FUN_007338f0(void)

{
  return 0x70040002;
}


// ==== FUN_00733900 @ 0x00733900 ====

void FUN_00733900(byte param_1)

{
  void *in_ECX;
  
  FUN_0072dc40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00733920 @ 0x00733920 ====

void FUN_00733920(void)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00991503;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0xf;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined1 *)(in_ECX + 0x28) = 0;
  local_4 = 1;
  _eh_vector_constructor_iterator_
            ((void *)(in_ECX + 0x48),0x27,10,(_func_void_void_ptr *)&LAB_0069d310,FUN_006ef6d0);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00733990 @ 0x00733990 ====

void FUN_00733990(int param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00991ce8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x3c) = 0xf;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x28) = 0;
  FUN_00401660(param_1 + 0x24,0,0xffffffff);
  *(undefined2 *)(in_ECX + 0x40) = *(undefined2 *)(param_1 + 0x40);
  *(undefined2 *)(in_ECX + 0x42) = *(undefined2 *)(param_1 + 0x42);
  *(undefined2 *)(in_ECX + 0x44) = *(undefined2 *)(param_1 + 0x44);
  *(undefined2 *)(in_ECX + 0x46) = *(undefined2 *)(param_1 + 0x46);
  puVar2 = (undefined4 *)(param_1 + 0x48);
  puVar3 = (undefined4 *)(in_ECX + 0x48);
  for (iVar1 = 0x61; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = *(undefined2 *)puVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00733a40 @ 0x00733a40 ====

void FUN_00733a40(int param_1)

{
  char cVar1;
  undefined1 *puVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(param_1 + 0x20);
  FUN_00401660(param_1 + 0x24,0,0xffffffff);
  *(undefined2 *)(in_ECX + 0x40) = *(undefined2 *)(param_1 + 0x40);
  *(undefined2 *)(in_ECX + 0x42) = *(undefined2 *)(param_1 + 0x42);
  *(undefined2 *)(in_ECX + 0x44) = *(undefined2 *)(param_1 + 0x44);
  *(undefined2 *)(in_ECX + 0x46) = *(undefined2 *)(param_1 + 0x46);
  iVar5 = param_1 + 0x4e;
  puVar2 = (undefined1 *)(in_ECX + 0x49);
  iVar4 = 10;
  do {
    puVar2[-1] = *(undefined1 *)(iVar5 + -6);
    *puVar2 = puVar2[param_1 - in_ECX];
    *(undefined4 *)(puVar2 + 1) = *(undefined4 *)(iVar5 + -4);
    uVar3 = 0;
    do {
      cVar1 = *(char *)(uVar3 + iVar5);
      puVar2[uVar3 + 5] = cVar1;
      if (cVar1 == '\0') goto LAB_00733aca;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x21);
    puVar2[5] = 0;
LAB_00733aca:
    iVar5 = iVar5 + 0x27;
    puVar2 = puVar2 + 0x27;
    iVar4 = iVar4 + -1;
    if (iVar4 == 0) {
      return;
    }
  } while( true );
}


// ==== FUN_00733ae0 @ 0x00733ae0 ====

void FUN_00733ae0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eed54;
  return;
}


// ==== FUN_00733af0 @ 0x00733af0 ====

void FUN_00733af0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eed54;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00733b10 @ 0x00733b10 ====

undefined1 FUN_00733b10(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 8);
}


// ==== FUN_00733b20 @ 0x00733b20 ====

undefined1 FUN_00733b20(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0xc);
}


// ==== FUN_00733b30 @ 0x00733b30 ====

void FUN_00733b30(void)

{
  return;
}


// ==== FUN_00733b50 @ 0x00733b50 ====

void FUN_00733b50(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009eee70;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00733b80 @ 0x00733b80 ====

void FUN_00733b80(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009eee5c;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00733bb0 @ 0x00733bb0 ====

void FUN_00733bb0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 8) = 1;
    return;
  }
  *puVar1 = &PTR_FUN_009ee750;
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 8) = 1;
  return;
}


// ==== FUN_00733bf0 @ 0x00733bf0 ====

void FUN_00733bf0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009eeed4;
  }
  FUN_00797a20(puVar1);
  (**(code **)(*DAT_00b5acd4 + 4))(6);
  return;
}


// ==== FUN_00733c20 @ 0x00733c20 ====

void FUN_00733c20(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009eee84;
  }
  FUN_00797a20(puVar1);
  (**(code **)(*DAT_00b5acd4 + 4))(6);
  *(undefined1 *)(in_ECX + 9) = 1;
  return;
}


// ==== FUN_00733c60 @ 0x00733c60 ====

void FUN_00733c60(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009eef10;
  }
  FUN_00797a20(puVar1);
  (**(code **)(*DAT_00b5acd4 + 4))(6);
  *(undefined1 *)(in_ECX + 10) = 1;
  return;
}


// ==== FUN_00733ca0 @ 0x00733ca0 ====

void FUN_00733ca0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009eef60;
  }
  FUN_00797a20(puVar1);
  (**(code **)(*DAT_00b5acd4 + 4))(6);
  *(undefined1 *)(in_ECX + 0xd) = 1;
  return;
}


// ==== FUN_00733ce0 @ 0x00733ce0 ====

void FUN_00733ce0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009eef74;
  }
  FUN_00797a20(puVar1);
  (**(code **)(*DAT_00b5acd4 + 4))(0);
  *(undefined1 *)(in_ECX + 0xd) = 0;
  return;
}


// ==== FUN_00733d20 @ 0x00733d20 ====

void FUN_00733d20(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009eef38;
    puVar1[1] = param_2;
    puVar1[2] = param_1;
  }
  FUN_00797a20(puVar1);
  (**(code **)(*DAT_00b5acd4 + 4))(6);
  *(undefined1 *)(in_ECX + 10) = 1;
  return;
}


// ==== FUN_00733d70 @ 0x00733d70 ====

void FUN_00733d70(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = *in_ECX;
  uVar2 = (**(code **)(*DAT_00b5a97c + 0xc))(0);
  (**(code **)(iVar1 + 0x7c))(uVar2);
  return;
}


// ==== FUN_00733d90 @ 0x00733d90 ====

void FUN_00733d90(undefined4 param_1)

{
  undefined4 *puVar1;
  short unaff_retaddr;
  undefined1 local_2c [30];
  short sStack_e;
  
  (**(code **)(*DAT_00b5ad1c + 0x20))(local_2c,param_1);
  if ((unaff_retaddr != 0) || (sStack_e != 0)) {
    puVar1 = operator_new(0xc);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_009eef88;
    }
    puVar1[1] = param_1;
    *(short *)(puVar1 + 2) = unaff_retaddr;
    FUN_00797a20(puVar1);
  }
  return;
}


// ==== FUN_00733df0 @ 0x00733df0 ====

void FUN_00733df0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 8) = 0;
    return;
  }
  *puVar1 = &PTR_FUN_009ee764;
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00733e30 @ 0x00733e30 ====

void FUN_00733e30(void)

{
  undefined4 *puVar1;
  int *in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009eee98;
  }
  FUN_00797a20(puVar1);
  (**(code **)(*in_ECX + 0x98))();
  (**(code **)(*DAT_00b5acd4 + 4))(0);
  *(undefined1 *)((int)in_ECX + 9) = 0;
  return;
}


// ==== FUN_00733e80 @ 0x00733e80 ====

void FUN_00733e80(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009eef4c;
  }
  FUN_00797a20(puVar1);
  (**(code **)(*DAT_00b5acd4 + 4))(0);
  return;
}


// ==== FUN_00733eb0 @ 0x00733eb0 ====

void FUN_00733eb0(void)

{
  undefined4 *puVar1;
  int *in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009eef24;
  }
  FUN_00797a20(puVar1);
  (**(code **)(*in_ECX + 0x9c))();
  (**(code **)(*DAT_00b5acd4 + 4))(0);
  return;
}


// ==== FUN_00733ef0 @ 0x00733ef0 ====

void FUN_00733ef0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009eeefc;
  }
  FUN_00797a20(puVar1);
  (**(code **)(*DAT_00b5acd4 + 4))(0);
  return;
}


// ==== FUN_00733f20 @ 0x00733f20 ====

void FUN_00733f20(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009eeeac;
    puVar1[1] = param_1;
    puVar1[2] = param_2;
  }
  FUN_00797a20(puVar1);
  (**(code **)(*DAT_00b5acd4 + 4))(6);
  *(undefined1 *)(in_ECX + 0xb) = 1;
  return;
}


// ==== FUN_00733f70 @ 0x00733f70 ====

void FUN_00733f70(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009eeec0;
  }
  FUN_00797a20(puVar1);
  (**(code **)(*DAT_00b5acd4 + 4))(0);
  *(undefined1 *)(in_ECX + 0xb) = 0;
  return;
}


// ==== FUN_00733fb0 @ 0x00733fb0 ====

void FUN_00733fb0(char param_1)

{
  int in_ECX;
  
  *(char *)(in_ECX + 0xc) = param_1;
  if (param_1 == '\0') {
    (**(code **)(*DAT_00b5acac + 4))();
  }
  return;
}


// ==== FUN_00733fd0 @ 0x00733fd0 ====

void FUN_00733fd0(void)

{
                    /* WARNING: Could not recover jumptable at 0x00733fd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5acac + 0x2c))();
  return;
}


// ==== FUN_00733fe0 @ 0x00733fe0 ====

void FUN_00733fe0(void)

{
                    /* WARNING: Could not recover jumptable at 0x00733fe8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5acac + 0x1c))();
  return;
}


// ==== FUN_00733ff0 @ 0x00733ff0 ====

void FUN_00733ff0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 0x10))();
  if (cVar1 != '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x11030005;
    *(undefined2 *)((int)pvVar3 + 6) = 0x3c;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
  }
  return;
}


// ==== FUN_00734040 @ 0x00734040 ====

void FUN_00734040(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x9000005;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(5);
  }
  return;
}


// ==== FUN_007340a0 @ 0x007340a0 ====

void FUN_007340a0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x9000012;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(5);
  }
  return;
}


// ==== FUN_00734100 @ 0x00734100 ====

void FUN_00734100(void)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x9000008;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return;
}


// ==== FUN_00734180 @ 0x00734180 ====

void FUN_00734180(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x11010000;
    *(undefined2 *)((int)pvVar3 + 6) = 0x18;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(5);
  }
  return;
}


// ==== FUN_007341e0 @ 0x007341e0 ====

void FUN_007341e0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x11020005;
    *(undefined2 *)((int)pvVar3 + 6) = 0x18;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(5);
  }
  return;
}


// ==== FUN_00734240 @ 0x00734240 ====

void FUN_00734240(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x11030003;
  *(undefined2 *)((int)pvVar2 + 6) = 0x3c;
  iVar3 = FUN_004244d0();
  *(undefined2 *)(iVar3 + 0x20) = 0;
  FUN_004d8570(iVar3);
  return;
}


// ==== FUN_00734290 @ 0x00734290 ====

void FUN_00734290(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  undefined1 unaff_retaddr;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x1101000c;
    *(undefined2 *)((int)pvVar3 + 6) = 0x20;
    iVar4 = FUN_004244d0();
    *(undefined1 *)(iVar4 + 0x18) = unaff_retaddr;
    *(undefined4 *)(iVar4 + 0x1c) = param_1;
    FUN_004d8570(iVar4);
    (**(code **)(*DAT_00b5af2c + 4))(5);
  }
  return;
}


// ==== FUN_00734300 @ 0x00734300 ====

void FUN_00734300(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x900000f;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(5);
  }
  return;
}


// ==== FUN_00734360 @ 0x00734360 ====

void FUN_00734360(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 unaff_retaddr;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x9030000;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    iVar4 = FUN_004244d0();
    *(undefined4 *)(iVar4 + 0x10) = unaff_retaddr;
    FUN_004d8570(iVar4);
                    /* WARNING: Could not recover jumptable at 0x007343c7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_00b5af2c + 4))();
    return;
  }
  return;
}


// ==== FUN_007343d0 @ 0x007343d0 ====

void FUN_007343d0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x9030002;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(5);
  }
  return;
}


// ==== FUN_00734430 @ 0x00734430 ====

void FUN_00734430(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x9030005;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(5);
  }
  return;
}


// ==== FUN_00734490 @ 0x00734490 ====

void FUN_00734490(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  undefined1 auStack_2c [30];
  undefined4 uStack_e;
  
  iVar1 = *DAT_00b5ad1c;
  uVar2 = (**(code **)(*DAT_00b5a97c + 0xc))();
  (**(code **)(iVar1 + 0x20))(auStack_2c,uVar2);
  if ((short)uStack_e != 0) {
    iVar1 = *in_ECX;
    uVar2 = (**(code **)(*DAT_00b5a97c + 0xc))(uStack_e);
    (**(code **)(iVar1 + 0x7c))(uVar2);
  }
  return;
}


// ==== FUN_007344e0 @ 0x007344e0 ====

void FUN_007344e0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *pvVar3;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009eeee8;
  }
  FUN_00797a20(puVar1);
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar3 = operator_new(0x400);
  *(undefined4 *)((int)pvVar3 + 8) = uVar2;
  *(undefined4 *)((int)pvVar3 + 0xc) = 0x900000b;
  *(undefined2 *)((int)pvVar3 + 6) = 0x10;
  uVar2 = FUN_004244d0();
  FUN_004d8570(uVar2);
  (**(code **)(*DAT_00b5acd4 + 4))(0);
  *(undefined1 *)(in_ECX + 9) = 0;
  return;
}


// ==== FUN_00734560 @ 0x00734560 ====

undefined4 FUN_00734560(uint param_1)

{
  int iVar1;
  int *in_ECX;
  undefined1 auStack_1dc [74];
  uint auStack_192 [97];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00991d0b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*in_ECX + 0x24))();
  if (iVar1 != 0) {
    (**(code **)(*in_ECX + 0x18))(auStack_1dc);
    uStack_4 = 0xffffffff;
    if ((param_1 & *(uint *)((int)auStack_192 + (uint)*(byte *)(iVar1 + 0x1d) * 0x27)) != 0) {
      FUN_00537c20();
      ExceptionList = pvStack_c;
      return 1;
    }
    FUN_00537c20();
  }
  ExceptionList = pvStack_c;
  return 0;
}


// ==== FUN_007345f0 @ 0x007345f0 ====

void FUN_007345f0(undefined4 param_1,undefined4 *param_2)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 in_stack_00000018;
  uint in_stack_0000001c;
  undefined4 uStack00000024;
  uint in_stack_00000038;
  undefined1 in_stack_0000003c;
  char acStack_2d [33];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00991d25;
  pvStack_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar4 = operator_new(0x400);
  *(undefined4 *)((int)pvVar4 + 8) = uVar3;
  *(undefined4 *)((int)pvVar4 + 0xc) = 0x9020004;
  *(undefined2 *)((int)pvVar4 + 6) = 0x4c;
  iVar5 = FUN_004244d0();
  *(undefined1 *)(iVar5 + 0x4a) = in_stack_0000003c;
  puVar7 = param_2;
  if (in_stack_0000001c < 0x10) {
    puVar7 = &param_2;
  }
  FUN_0050cd30(acStack_2d,&DAT_009eed28,puVar7);
  pcVar1 = (char *)(iVar5 + 0x10);
  uVar8 = 0;
  pcVar6 = pcVar1;
  do {
    cVar2 = pcVar6[(int)(acStack_2d + -(int)pcVar1)];
    *pcVar6 = cVar2;
    if (cVar2 == '\0') goto LAB_00734697;
    uVar8 = uVar8 + 1;
    pcVar6 = pcVar6 + 1;
  } while (uVar8 < 0x21);
  *pcVar1 = '\0';
LAB_00734697:
  puVar7 = uStack00000024;
  if (in_stack_00000038 < 0x10) {
    puVar7 = &uStack00000024;
  }
  FUN_0047aa30(acStack_2d,&DAT_009eed2c,puVar7);
  pcVar1 = (char *)(iVar5 + 0x31);
  uVar8 = 0;
  pcVar6 = pcVar1;
  do {
    cVar2 = pcVar6[(int)(acStack_2d + -(int)pcVar1)];
    *pcVar6 = cVar2;
    if (cVar2 == '\0') goto LAB_007346dd;
    uVar8 = uVar8 + 1;
    pcVar6 = pcVar6 + 1;
  } while (uVar8 < 0x19);
  *pcVar1 = '\0';
LAB_007346dd:
  FUN_004d8570(iVar5);
  if (0xf < in_stack_0000001c) {
    _free(param_2);
    return;
  }
  in_stack_0000001c = 0xf;
  in_stack_00000018 = 0;
  param_2 = (undefined4 *)((uint)param_2 & 0xffffff00);
  if (in_stack_00000038 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(uStack00000024);
  return;
}


// ==== FUN_00734740 @ 0x00734740 ====

void FUN_00734740(undefined4 *param_1)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  uint uVar8;
  uint in_stack_00000018;
  char acStack_26 [22];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00991d37;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  cVar2 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar2 == '\0') {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined4 *)((int)pvVar4 + 8) = uVar3;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x11020007;
    *(undefined2 *)((int)pvVar4 + 6) = 0x38;
    iVar5 = FUN_004244d0();
    puVar6 = param_1;
    if (in_stack_00000018 < 0x10) {
      puVar6 = &param_1;
    }
    FUN_0047aa30(acStack_26 + -3,&DAT_009eed2c,puVar6);
    pcVar1 = (char *)(iVar5 + 0x18);
    uVar8 = 0;
    pcVar7 = pcVar1;
    do {
      cVar2 = pcVar7[(int)(acStack_26 + (-3 - (int)pcVar1))];
      *pcVar7 = cVar2;
      if (cVar2 == '\0') goto LAB_00734807;
      uVar8 = uVar8 + 1;
      pcVar7 = pcVar7 + 1;
    } while (uVar8 < 0x19);
    *pcVar1 = '\0';
LAB_00734807:
    FUN_004d8570(iVar5);
    (**(code **)(*DAT_00b5af2c + 4))(5);
  }
  if (in_stack_00000018 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_00734850 @ 0x00734850 ====

void FUN_00734850(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  undefined4 *puVar5;
  uint in_stack_00000018;
  undefined4 auStack_210 [128];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00991d49;
  pvStack_c = ExceptionList;
  auStack_210[0] = 5;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if ((cVar1 == '\0') && (iVar2 = (**(code **)(*DAT_00b5a980 + 8))(), iVar2 != 0)) {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined4 *)((int)pvVar4 + 8) = uVar3;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x11010003;
    *(undefined2 *)((int)pvVar4 + 6) = 0x218;
    uVar3 = FUN_004244d0();
    puVar5 = param_1;
    if (in_stack_00000018 < 0x10) {
      puVar5 = &param_1;
    }
    FUN_006f6d40(auStack_210,&DAT_009eed30,puVar5);
    FUN_006f6d10(auStack_210);
    FUN_004d8570(uVar3);
    (**(code **)(*DAT_00b5af2c + 4))(5);
  }
  if (in_stack_00000018 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_00734970 @ 0x00734970 ====

void FUN_00734970(undefined4 param_1,undefined4 *param_2)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  uint uVar8;
  uint in_stack_0000001c;
  char acStack_25 [25];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00991d5b;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar4 = operator_new(0x400);
  *(undefined4 *)((int)pvVar4 + 8) = uVar3;
  *(undefined4 *)((int)pvVar4 + 0xc) = 0x11030004;
  *(undefined2 *)((int)pvVar4 + 6) = 0x54;
  iVar5 = FUN_004244d0();
  puVar6 = param_2;
  if (in_stack_0000001c < 0x10) {
    puVar6 = &param_2;
  }
  FUN_0047aa30(acStack_25,&DAT_009eed2c,puVar6);
  pcVar1 = (char *)(iVar5 + 0x18);
  uVar8 = 0;
  pcVar7 = pcVar1;
  do {
    cVar2 = pcVar7[(int)(acStack_25 + -(int)pcVar1)];
    *pcVar7 = cVar2;
    if (cVar2 == '\0') goto LAB_00734a0c;
    uVar8 = uVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (uVar8 < 0x19);
  *pcVar1 = '\0';
LAB_00734a0c:
  FUN_004d8570(iVar5);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00734a40 @ 0x00734a40 ====

undefined4 FUN_00734a40(undefined4 param_1)

{
  (**(code **)(*DAT_00b5acac + 0xc))(param_1);
  return param_1;
}


// ==== FUN_00734a70 @ 0x00734a70 ====

undefined4 FUN_00734a70(undefined4 param_1,undefined4 param_2)

{
  (**(code **)(*DAT_00b5acac + 0x20))(param_1,param_2);
  return param_1;
}


// ==== FUN_00734aa0 @ 0x00734aa0 ====

void FUN_00734aa0(undefined1 param_1,void *param_2)

{
  void *pvVar1;
  uint in_stack_0000001c;
  void *in_stack_00000024;
  uint in_stack_00000038;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00991d88;
  local_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x3c);
  local_4._0_1_ = 2;
  if (pvVar1 != (void *)0x0) {
    FUN_00401660();
    local_4._0_1_ = 3;
    FUN_00401660(&param_1,0,0xffffffff);
    local_4._0_1_ = 2;
    FUN_00737c70();
  }
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00797a20();
  if (0xf < in_stack_0000001c) {
    _free(param_2);
    return;
  }
  if (in_stack_00000038 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(in_stack_00000024);
  return;
}


// ==== FUN_00734b90 @ 0x00734b90 ====

void FUN_00734b90(undefined4 param_1)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00991d9d;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x20);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00401660(param_1,0,0xffffffff);
    FUN_00737db0();
  }
  local_4 = 0xffffffff;
  FUN_00797a20();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00734c10 @ 0x00734c10 ====

void FUN_00734c10(undefined4 param_1)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00991db2;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x20);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00401660(param_1,0,0xffffffff);
    FUN_00737ea0();
  }
  local_4 = 0xffffffff;
  FUN_00797a20();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00734c90 @ 0x00734c90 ====

void FUN_00734c90(void *param_1)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int *in_ECX;
  uint in_stack_00000018;
  undefined4 uStack_38;
  void *pvStack_28;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00991dcc;
  pvStack_c = ExceptionList;
  uStack_38 = 5;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*in_ECX + 4))();
    if (cVar1 == '\0') {
      (**(code **)(*DAT_00b5a794 + 0xc))();
      FUN_00401660();
      uStack_14 = CONCAT31(uStack_14._1_3_,1);
      FUN_00401660(&uStack_38,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(8);
      if (0xf < uStack_14) {
        _free(pvStack_28);
        return;
      }
    }
    else {
      uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar3 = operator_new(0x400);
      *(undefined4 *)((int)pvVar3 + 8) = uVar2;
      *(undefined4 *)((int)pvVar3 + 0xc) = 0x9020001;
      *(undefined2 *)((int)pvVar3 + 6) = 0x2c;
      FUN_004244d0();
      FUN_0047aa30();
      FUN_0047aa00();
      FUN_004d8570();
      (**(code **)(*DAT_00b5af2c + 4))();
    }
  }
  if (in_stack_00000018 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_00734e10 @ 0x00734e10 ====

/* WARNING: Removing unreachable block (ram,0x00734ecd) */

void FUN_00734e10(void)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  undefined2 unaff_retaddr;
  undefined1 auStack_5c [4];
  undefined1 uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00991dde;
  puStack_c = ExceptionList;
  ExceptionList = &puStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if ((cVar1 == '\0') && (iVar2 = (**(code **)(*DAT_00b5a980 + 8))(), iVar2 != 0)) {
    uStack_3c = (undefined *)0x734e5f;
    cVar1 = (**(code **)(*in_ECX + 4))();
    if (cVar1 == '\0') {
      uStack_3c = &DAT_00820079;
      uStack_40 = 0;
      uStack_44 = 0x734e78;
      uStack_4c = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_44 = 0xffffffff;
      uStack_48 = 0;
      uStack_50 = 0x734e96;
      FUN_00401660();
      puStack_c = auStack_5c;
      uStack_44 = 0xf;
      uStack_48 = 0;
      uStack_58 = 0;
      FUN_00401660(auStack_5c + 0x24,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    }
    else {
      uStack_3c = (undefined *)0x734ef8;
      uStack_3c = (undefined *)(**(code **)(*DAT_00b5a6ac + 0x20))();
      uStack_40 = 0x734efe;
      uStack_3c = (undefined *)FUN_00737a00();
      *(undefined2 *)((int)uStack_3c + 0x18) = (undefined2)uStack_4;
      *(undefined2 *)((int)uStack_3c + 0x1a) = unaff_retaddr;
      uStack_40 = 0x734f1f;
      FUN_004d8570();
      uStack_3c = (undefined *)0x5;
      uStack_40 = 0x734f2c;
      (**(code **)(*DAT_00b5af2c + 4))();
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00734f40 @ 0x00734f40 ====

void FUN_00734f40(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  undefined1 unaff_retaddr;
  undefined1 auStack_80 [4];
  undefined1 uStack_7c;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined1 *puStack_68;
  undefined *puStack_64;
  void *pvStack_4c;
  uint uStack_38;
  undefined1 auStack_31 [33];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00991df0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    puStack_68 = *(undefined1 **)(param_1 + 0x14);
    puStack_64 = &DAT_009eec2f;
    uStack_6c = 0;
    uStack_70 = 0x734f88;
    iVar2 = FUN_00403620();
    if (iVar2 == 0) {
      puStack_64 = (undefined *)0x0;
      puStack_68 = (undefined1 *)0x734fa1;
      uStack_70 = (**(code **)(*DAT_00b5a794 + 0xc))();
      puStack_68 = (undefined1 *)0xffffffff;
      uStack_6c = 0;
      uStack_74 = 0x734fbf;
      FUN_00401660();
      puStack_8 = auStack_80;
      puStack_68 = (undefined1 *)0xf;
      uStack_6c = 0;
      pvStack_10 = (void *)0x0;
      uStack_7c = 0;
      FUN_00401660(auStack_80 + 0x28,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(8);
      if (0xf < uStack_38) {
        puStack_64 = (undefined *)0x735004;
        _free(pvStack_4c);
        return;
      }
    }
    else {
      uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      puStack_64 = (undefined *)0x735032;
      pvVar4 = operator_new(0x400);
      *(undefined4 *)((int)pvVar4 + 8) = uVar3;
      *(undefined4 *)((int)pvVar4 + 0xc) = 0x11010009;
      *(undefined2 *)((int)pvVar4 + 6) = 0x3c;
      iVar2 = FUN_004244d0();
      *(undefined1 *)(iVar2 + 0x18) = unaff_retaddr;
      puStack_68 = auStack_31;
      puStack_64 = &DAT_009eed28;
      uStack_6c = 0x735073;
      FUN_0050cd30();
      puStack_64 = (undefined *)0x735083;
      FUN_00496ed0();
      puStack_64 = (undefined *)0x73508f;
      FUN_004d8570();
      puStack_64 = (undefined *)0x73509c;
      (**(code **)(*DAT_00b5af2c + 4))();
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_007350b0 @ 0x007350b0 ====

void FUN_007350b0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  byte unaff_retaddr;
  undefined4 uStack_7c;
  uint uStack_78;
  uint uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined1 auStack_34 [4];
  undefined1 uStack_30;
  void *pvStack_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00991e12;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    if (unaff_retaddr < 10) {
      if (unaff_retaddr == 0) {
        uStack_60 = 0;
        uStack_64 = 0x735192;
        uStack_6c = (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_64 = 0xffffffff;
        uStack_68 = 0;
        uStack_1c = 0xf;
        uStack_20 = 0;
        uStack_30 = 0;
        uStack_70 = 0x7351b0;
        FUN_00401660();
        puStack_8 = (undefined1 *)&uStack_7c;
        uStack_64 = 0xf;
        uStack_68 = 0;
        pvStack_10 = (void *)0x1;
        uStack_78 = uStack_78 & 0xffffff00;
        FUN_00401660(auStack_34,0,0xffffffff);
        (**(code **)(*DAT_00b5ad0c + 0x28))(8);
        if (0xf < uStack_14) {
          uStack_60 = 0x7351f9;
          _free(pvStack_28);
          return;
        }
      }
      else {
        uStack_78 = 0xffffffff;
        uStack_7c = 0;
        uStack_60 = 0;
        uStack_70 = uStack_70 & 0xffffff00;
        FUN_00401660(param_1);
        uStack_78 = 0x73523e;
        iVar2 = (**(code **)(*DAT_00b5acac + 0x24))();
        if (iVar2 != 0) {
          if (*(char *)(iVar2 + 0x1d) == '\0') {
            uStack_60 = 0;
            uStack_64 = 0x73525c;
            uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
            uStack_68 = 0x735266;
            FUN_00765c50();
            puStack_8 = (undefined1 *)&uStack_7c;
            pvStack_10 = (void *)0x2;
            FUN_00765c50(auStack_34);
            (**(code **)(*DAT_00b5ad0c + 0x28))(8);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          (**(code **)(*DAT_00b5a6ac + 0x20))();
          uStack_60 = 0x7352bc;
          iVar2 = FUN_00737a60();
          *(byte *)(iVar2 + 0x18) = unaff_retaddr;
          uStack_60 = 0x7352e0;
          FUN_0047aa60();
          uStack_60 = 0x7352ed;
          FUN_0047aa00();
          uStack_60 = 0x7352f3;
          FUN_004ef210();
          uStack_60 = 0x735303;
          (**(code **)(*DAT_00b5af2c + 4))();
        }
      }
    }
    else {
      uStack_60 = 0;
      uStack_64 = 0x7350ff;
      uStack_6c = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_64 = 0xffffffff;
      uStack_68 = 0;
      uStack_1c = 0xf;
      uStack_20 = 0;
      uStack_30 = 0;
      uStack_70 = 0x73511d;
      FUN_00401660();
      puStack_8 = (undefined1 *)&uStack_7c;
      uStack_64 = 0xf;
      uStack_68 = 0;
      pvStack_10 = (void *)0x0;
      uStack_78 = uStack_78 & 0xffffff00;
      FUN_00401660(auStack_34,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(8);
      if (0xf < uStack_14) {
        uStack_60 = 0x735162;
        _free(pvStack_28);
        return;
      }
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00735320 @ 0x00735320 ====

void FUN_00735320(void *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  undefined1 uStack00000000;
  uint in_stack_00000018;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00991e24;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    FUN_00401660(&uStack00000000,0,0xffffffff);
    iVar2 = (**(code **)(*DAT_00b5acac + 0x24))();
    if (iVar2 != 0) {
      uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar4 = operator_new(0x400);
      *(undefined4 *)((int)pvVar4 + 8) = uVar3;
      *(undefined4 *)((int)pvVar4 + 0xc) = 0x1102000c;
      *(undefined2 *)((int)pvVar4 + 6) = 0x34;
      FUN_004244d0();
      FUN_0047aa30();
      FUN_0047aa00();
      FUN_004d8570();
      (**(code **)(*DAT_00b5af2c + 4))();
    }
  }
  if (in_stack_00000018 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_00735440 @ 0x00735440 ====

void FUN_00735440(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  uint unaff_EBP;
  void *unaff_EDI;
  undefined1 auStackY_100 [8];
  undefined1 *puVar1;
  undefined1 auStack_ce [6];
  undefined1 **ppuVar2;
  undefined1 **ppuVar3;
  undefined1 *puStack_b8;
  undefined4 uStack_b4;
  undefined4 **ppuVar4;
  undefined1 *puStack_ac;
  undefined4 uStack_a8;
  undefined1 **ppuVar5;
  undefined1 *puStack_a0;
  undefined1 auStack_9c [4];
  uint **ppuVar6;
  undefined1 *puStack_94;
  undefined4 uStack_90;
  undefined1 *puVar7;
  undefined1 *puStack_88;
  undefined4 uStack_84;
  undefined4 *puStack_7c;
  undefined4 uStack_78;
  uint *puVar8;
  undefined1 *puStack_70;
  undefined4 uStack_6c;
  uint *puVar9;
  uint *puStack_64;
  char *pcStack_60;
  undefined4 uStack_5c;
  undefined1 auStack_46 [2];
  uint local_44;
  uint local_40;
  void *pvStack_3c;
  uint uStack_38;
  uint uStack_34;
  void *local_30;
  undefined4 local_2c;
  uint local_28;
  undefined1 local_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00991f06;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ef004;
  in_ECX[1] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5aca8 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5aca8 = in_ECX;
  }
  uStack_5c = (uint *)0x0;
  pcStack_60 = &DAT_009ee922;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined1 *)((int)in_ECX + 10) = 0;
  *(undefined1 *)((int)in_ECX + 9) = 0;
  *(undefined1 *)((int)in_ECX + 0xb) = 0;
  *(undefined1 *)((int)in_ECX + 0xd) = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  puStack_64 = (uint *)0x7354ba;
  FUN_00401740();
  uStack_5c = (uint *)0xe;
  pcStack_60 = s_show_guildjoin_009ee924;
  local_4._0_1_ = 1;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = local_40 & 0xffffff00;
  puStack_64 = (uint *)0x7354db;
  FUN_00401740();
  uStack_5c = &local_28;
  pcStack_60 = (char *)0x0;
  puStack_64 = &local_44;
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < uStack_38) {
    uStack_6c = (char *)0x73550b;
    _free(unaff_EBX);
    return;
  }
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  local_10 = local_10 & 0xffffff00;
  if (0xf < uStack_1c) {
    uStack_6c = (char *)0x73552e;
    _free(local_30);
    return;
  }
  uStack_6c = &DAT_009ee933;
  uStack_1c = 0xf;
  uStack_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffffff00);
  puStack_70 = (undefined1 *)0x73554c;
  FUN_00401740();
  uStack_6c = s_show_guild_009ee934;
  local_10._0_1_ = 3;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  puStack_70 = (undefined1 *)0x73556d;
  FUN_00401740();
  puVar9 = &uStack_34;
  uStack_6c = (char *)0x0;
  puStack_70 = auStack_46 + -10;
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < local_44) {
    uStack_78 = (char *)0x735598;
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  uStack_1c = uStack_1c & 0xffffff00;
  if (0xf < local_28) {
    uStack_78 = (char *)0x7355bb;
    _free(pvStack_3c);
    return;
  }
  uStack_78 = &DAT_009ee93f;
  local_28 = 0xf;
  local_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  puStack_7c = (undefined4 *)0x7355d9;
  FUN_00401740();
  uStack_78 = s_show_createguild_009ee940;
  uStack_1c._0_1_ = 5;
  local_44 = 0xf;
  puStack_7c = (undefined4 *)0x7355f9;
  FUN_00401740();
  puVar8 = &local_40;
  uStack_78 = (char *)0x0;
  puStack_7c = &uStack_5c;
  uStack_1c = CONCAT31(uStack_1c._1_3_,6);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < unaff_EBP) {
    uStack_84 = (char *)0x735624;
    _free(puStack_64);
    return;
  }
  puStack_64 = (uint *)((uint)puStack_64 & 0xffffff00);
  local_28 = local_28 & 0xffffff00;
  if (0xf < uStack_34) {
    uStack_84 = (char *)0x735647;
    _free((void *)0x0);
    return;
  }
  uStack_84 = s_create_guild__name__009ee954;
  uStack_34 = 0xf;
  uStack_38 = 0;
  puStack_88 = (undefined1 *)0x735666;
  FUN_00401740();
  uStack_84 = s_create_guild_009ee968;
  local_28._0_1_ = 7;
  puStack_64 = (uint *)((uint)puStack_64 & 0xffffff00);
  puStack_88 = (undefined1 *)0x735687;
  FUN_00401740();
  puVar1 = auStack_46 + -6;
  uStack_84 = (char *)0x1;
  puStack_88 = auStack_46 + -0x22;
  local_28 = CONCAT31(local_28._1_3_,8);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((uint *)0xf < uStack_5c) {
    uStack_90 = (char *)0x7356b3;
    _free(puStack_70);
    return;
  }
  uStack_5c = (uint *)0xf;
  pcStack_60 = (char *)0x0;
  puStack_70 = (undefined1 *)((uint)puStack_70 & 0xffffff00);
  uStack_34 = uStack_34 & 0xffffff00;
  if (0xf < local_40) {
    uStack_90 = (char *)0x7356d6;
    _free((void *)0x0);
    return;
  }
  uStack_90 = &DAT_009ee975;
  local_40 = 0xf;
  local_44 = 0;
  puStack_94 = (undefined1 *)0x7356f4;
  FUN_00401740();
  uStack_90 = s_secede_guildjoin_009ee978;
  uStack_34._0_1_ = 9;
  uStack_5c = (uint *)0xf;
  pcStack_60 = (void *)0x0;
  puStack_70 = (undefined1 *)((uint)puStack_70 & 0xffffff00);
  puStack_94 = (undefined1 *)0x735714;
  FUN_00401740();
  puVar7 = auStack_46 + -0x12;
  uStack_90 = (char *)0x0;
  puStack_94 = auStack_9c + 0x28;
  uStack_34 = CONCAT31(uStack_34._1_3_,10);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((uint *)0xf < puVar9) {
    _free(puStack_7c);
    return;
  }
  uStack_6c = (char *)0x0;
  puStack_7c = (undefined4 *)((uint)puStack_7c & 0xffffff00);
  local_40 = local_40 & 0xffffff00;
  if (0xf < ((uint)unaff_EBX & 0xffffff00)) {
    _free(pcStack_60);
    return;
  }
  pcStack_60 = (char *)((uint)pcStack_60 & 0xffffff00);
  FUN_00401740();
  local_40._0_1_ = 0xb;
  uStack_6c = (void *)0x0;
  puStack_7c = (undefined4 *)((uint)puStack_7c & 0xffffff00);
  FUN_00401740();
  ppuVar6 = &puStack_64;
  local_40 = CONCAT31(local_40._1_3_,0xc);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((uint *)0xf < puVar8) {
    uStack_a8 = (char *)0x7357cd;
    _free(puStack_88);
    return;
  }
  uStack_78 = (char *)0x0;
  puStack_88 = (undefined1 *)((uint)puStack_88 & 0xffffff00);
  if (0xf < ((uint)unaff_EDI & 0xffffff00)) {
    uStack_a8 = (char *)0x7357f0;
    _free(uStack_6c);
    return;
  }
  uStack_a8 = s_user_name__name__009ee9ac;
  uStack_5c = (uint *)0x0;
  uStack_6c = (char *)((uint)uStack_6c & 0xffffff00);
  puStack_ac = (undefined1 *)0x73580e;
  FUN_00401740();
  uStack_a8 = s_request_guildjoin_009ee9c0;
  uStack_78 = (void *)0x0;
  puStack_88 = (undefined1 *)((uint)puStack_88 & 0xffffff00);
  puStack_ac = (undefined1 *)0x73582f;
  FUN_00401740();
  ppuVar5 = &puStack_70;
  uStack_a8 = (char *)0x1;
  puStack_ac = auStack_9c + 0x10;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((undefined1 *)0xf < puVar1) {
    uStack_b4 = (char *)0x73585b;
    _free(puStack_94);
    return;
  }
  uStack_84 = (char *)0x0;
  puStack_94 = (undefined1 *)((uint)puStack_94 & 0xffffff00);
  if ((uint *)0xf < puStack_64) {
    uStack_b4 = (char *)0x73587e;
    _free(uStack_78);
    return;
  }
  uStack_b4 = s_guildnotice__guildnotice__009ee9d4;
  puStack_64 = (uint *)0xf;
  uStack_78 = (char *)((uint)uStack_78 & 0xffffff00);
  puStack_b8 = (undefined1 *)0x73589d;
  FUN_00401740();
  uStack_b4 = s_change_guildnotice_009ee9f0;
  uStack_84 = (void *)0x0;
  puStack_94 = (undefined1 *)((uint)puStack_94 & 0xffffff00);
  puStack_b8 = (undefined1 *)0x7358be;
  FUN_00401740();
  ppuVar4 = &puStack_7c;
  uStack_b4 = (char *)0x1;
  puStack_b8 = auStack_9c + 4;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((undefined1 *)0xf < puVar7) {
    _free(auStack_9c + 0x1c);
    return;
  }
  uStack_90 = (char *)0x0;
  puStack_a0 = auStackY_100;
  puStack_64 = (uint *)((uint)puStack_64 & 0xffffff00);
  if ((undefined1 *)0xf < puStack_70) {
    _free(uStack_84);
    return;
  }
  puStack_70 = (undefined1 *)0xf;
  uStack_84 = (char *)((uint)uStack_84 & 0xffffff00);
  FUN_00401740();
  puStack_64._0_1_ = 0x11;
  uStack_90 = (void *)0x0;
  FUN_00401740();
  ppuVar3 = &puStack_88;
  puStack_64 = (uint *)CONCAT31(puStack_64._1_3_,0x12);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((uint **)0xf < ppuVar6) {
    _free(puStack_ac);
    return;
  }
  puStack_ac = (undefined1 *)((uint)puStack_ac & 0xffffff00);
  puStack_70 = (undefined1 *)((uint)puStack_70 & 0xffffff00);
  if ((undefined4 *)0xf < puStack_7c) {
    _free(uStack_90);
    return;
  }
  puStack_7c = (undefined4 *)0xf;
  uStack_90 = (char *)((uint)uStack_90 & 0xffffff00);
  FUN_00401740();
  puStack_70._0_1_ = 0x13;
  puStack_ac = (undefined1 *)((uint)puStack_ac & 0xffffff00);
  FUN_00401740();
  ppuVar2 = &puStack_94;
  puStack_70 = (undefined1 *)CONCAT31(puStack_70._1_3_,0x14);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((undefined1 **)0xf < ppuVar5) {
    _free(puStack_b8);
    return;
  }
  uStack_a8 = (char *)0x0;
  puStack_b8 = (undefined1 *)((uint)puStack_b8 & 0xffffff00);
  puStack_7c = (undefined4 *)((uint)puStack_7c & 0xffffff00);
  if ((undefined1 *)0xf < puStack_88) {
    _free((void *)0x0);
    return;
  }
  puStack_88 = (undefined1 *)0xf;
  FUN_00401740(s_guild_changegradepower__gradeind_009eea58);
  puStack_7c._0_1_ = 0x15;
  uStack_a8 = (void *)0x0;
  puStack_b8 = (undefined1 *)((uint)puStack_b8 & 0xffffff00);
  FUN_00401740(s_guild_changegradepower_009eea84);
  puVar1 = auStack_ce + 0x12;
  puStack_7c = (undefined4 *)CONCAT31(puStack_7c._1_3_,0x16);
  (**(code **)(*DAT_00b5a6c8 + 8))(puVar1,2);
  if ((undefined4 **)0xf < ppuVar4) {
    _free(auStack_9c + -8);
    return;
  }
  uStack_b4 = (char *)0x0;
  puStack_88 = (undefined1 *)((uint)puStack_88 & 0xffffff00);
  if ((undefined1 *)0xf < puStack_94) {
    _free(uStack_a8);
    return;
  }
  puStack_94 = (undefined1 *)0xf;
  uStack_a8 = (char *)((uint)uStack_a8 & 0xffffff00);
  FUN_00401740(s_guild_changegradenameNpower__gra_009eea9c,0x37);
  puStack_88._0_1_ = 0x17;
  uStack_b4 = (void *)0x0;
  FUN_00401740(s_guild_changegradenameNpower_009eead4,0x1b);
  puStack_88 = (undefined1 *)CONCAT31(puStack_88._1_3_,0x18);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_ce + 6,3,&puStack_ac);
  if ((undefined1 **)0xf < ppuVar3) {
    _free(auStack_9c + -0x14);
    return;
  }
  puStack_94 = (undefined1 *)((uint)puStack_94 & 0xffffff00);
  if ((undefined1 *)0xf < puStack_a0) {
    _free(uStack_b4);
    return;
  }
  uStack_b4 = (char *)((uint)uStack_b4 & 0xffffff00);
  FUN_00401740(s_guild_changegradenameNpower__gra_009eeaf0,0x31);
  puStack_94._0_1_ = 0x19;
  FUN_00401740(s_guild_givegrade_009eeb24,0xf);
  puStack_94 = (undefined1 *)CONCAT31(puStack_94._1_3_,0x1a);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_ce + -6,2,&puStack_b8);
  if ((undefined1 **)0xf < ppuVar2) {
    _free(puVar1);
    return;
  }
  if (puStack_ac < (undefined1 *)0x10) {
    ExceptionList = uStack_a8;
    return;
  }
  _free((void *)0x0);
  return;
}


// ==== FUN_00735bf0 @ 0x00735bf0 ====

/* WARNING: Removing unreachable block (ram,0x00735ef0) */
/* WARNING: Removing unreachable block (ram,0x00735ea8) */
/* WARNING: Removing unreachable block (ram,0x00735f38) */
/* WARNING: Removing unreachable block (ram,0x00735e60) */
/* WARNING: Removing unreachable block (ram,0x00735e18) */

void FUN_00735bf0(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  void *unaff_EDI;
  void *_Memory;
  undefined4 uStack_40;
  void *local_28;
  uint local_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00991f78;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ef004;
  uStack_40 = (void **)0xe;
  local_4 = 0;
  DAT_00b5aca8 = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = local_24 & 0xffffff00;
  FUN_00401740();
  uStack_40 = &local_28;
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  puStack_8 = (undefined1 *)((uint)puStack_8 & 0xffffff00);
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = 0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740();
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  pvStack_c = (void *)((uint)pvStack_c & 0xffffff00);
  if (0xf < uStack_18) {
    _free(in_ECX);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  FUN_00401740();
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  local_10 = local_10 & 0xffffff00;
  if (0xf < uStack_1c) {
    _free(unaff_EBX);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  FUN_00401740();
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  local_14 = local_14 & 0xffffff00;
  if (0xf < uStack_20) {
    _free(unaff_EBP);
    return;
  }
  uStack_20 = 0xf;
  local_24 = 0;
  FUN_00401740();
  local_14 = CONCAT31(local_14._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  uStack_18 = uStack_18 & 0xffffff00;
  if (0xf < local_24) {
    _free(unaff_ESI);
    return;
  }
  local_24 = 0xf;
  local_28 = (void *)0x0;
  FUN_00401740(s_secede_guildjoin_009eeb84);
  _Memory = (void *)((int)register0x00000010 + -0x3c);
  uStack_18 = CONCAT31(uStack_18._1_3_,6);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  uStack_1c = uStack_1c & 0xffffff00;
  if ((void *)0xf < local_28) {
    _free(unaff_EDI);
    return;
  }
  local_28 = (void *)0xf;
  FUN_00401740(s_kick_guild_009eeb98,10);
  uStack_1c = CONCAT31(uStack_1c._1_3_,7);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&uStack_40);
  uStack_20 = uStack_20 & 0xffffff00;
  uStack_40 = (void **)((uint)uStack_40 & 0xffffff00);
  FUN_00401740(s_change_guildnotice_009eeba4,0x12);
  uStack_20 = CONCAT31(uStack_20._1_3_,8);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x44);
  local_24 = local_24 & 0xffffff00;
  FUN_00401740(s_guild_changegradename_009eebb8,0x15);
  local_24 = CONCAT31(local_24._1_3_,9);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x48);
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_guild_changegradepower_009eebd0,0x16);
  local_28 = (void *)CONCAT31(local_28._1_3_,10);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x4c);
  FUN_00401740(s_guild_changegradenameNpower_009eebe8,0x1b);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x50);
  uStack_40 = (void **)0x0;
  FUN_00401740(s_guild_givegrade_009eec04,0xf);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x54);
  if (uStack_40 < 0x10) {
    *in_ECX = &PTR_FUN_009eed54;
    ExceptionList = (void *)0xf;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00735fb0 @ 0x00735fb0 ====

void FUN_00735fb0(undefined1 param_1,void *param_2)

{
  undefined4 *puVar1;
  void *unaff_ESI;
  uint in_stack_0000001c;
  undefined4 in_stack_00000024;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00991f8a;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  puVar1 = operator_new(0x28);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009eef9c;
    puVar1[8] = 0xf;
    puVar1[7] = 0;
    *(undefined1 *)(puVar1 + 3) = 0;
  }
  *(undefined1 *)(puVar1 + 1) = param_1;
  FUN_00401660(&param_2,0,0xffffffff);
  puVar1[9] = in_stack_00000024;
  FUN_00797a20(puVar1);
  (**(code **)(*DAT_00b5acd4 + 4))(6);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = unaff_ESI;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00736060 @ 0x00736060 ====

void FUN_00736060(undefined1 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x24);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009eefb0;
    puVar1[8] = 0xf;
    puVar1[7] = 0;
    *(undefined1 *)(puVar1 + 3) = 0;
  }
  *(undefined1 *)(puVar1 + 1) = param_1;
  FUN_00401660(param_2,0,0xffffffff);
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007360b0 @ 0x007360b0 ====

undefined4 FUN_007360b0(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined1 auStack_50 [4];
  undefined1 uStack_4c;
  void *pvStack_40;
  char *pcStack_3c;
  int iStack_38;
  void *pvStack_28;
  undefined1 uStack_24;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00991f9c;
  pvStack_c = ExceptionList;
  iStack_38 = 0x7360d5;
  ExceptionList = &pvStack_c;
  piVar2 = (int *)(**(code **)(*DAT_00b5a980 + 8))();
  if (piVar2 == (int *)0x0) {
    ExceptionList = pvStack_c;
    return 0;
  }
  iStack_38 = 0x7360f5;
  iVar3 = (**(code **)(*piVar2 + 0x74))();
  pcStack_3c = (char *)(iVar3 + 0x5c);
  uStack_10 = 0xf;
  uStack_14 = 0;
  uStack_24 = 0;
  pcVar5 = pcStack_3c;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  iStack_38 = (int)pcVar5 - (iVar3 + 0x5d);
  pvStack_40 = (void *)0x736126;
  FUN_00401740();
  iStack_38 = 0xf;
  pcStack_3c = (char *)0x0;
  uStack_4 = 0;
  uStack_4c = 0;
  FUN_00401660(&pvStack_28,0,0xffffffff);
  uVar4 = (**(code **)(*DAT_00b5acac + 0x24))();
  if ((undefined1 *)0xf < auStack_50) {
    _free(pvStack_40);
  }
  ExceptionList = pvStack_28;
  return uVar4;
}


// ==== FUN_00736190 @ 0x00736190 ====

void FUN_00736190(void *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  uint in_stack_00000018;
  undefined1 auStack_6e [6];
  void *pvStack_68;
  undefined4 uStack_58;
  uint uStack_54;
  void *pvStack_4c;
  undefined4 uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  void *pvStack_38;
  uint uStack_24;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00991fde;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    iVar2 = (**(code **)(*DAT_00b5a6b0 + 8))();
    if (iVar2 == 1) {
      FUN_00401830();
      (**(code **)*DAT_00b5ae18)();
      puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,1);
      if (iStack_3c != 0) {
        (**(code **)(*DAT_00b5a794 + 0xc))();
        FUN_00401660();
        pvStack_10._0_1_ = 2;
        FUN_00401660(auStack_6e + -6,0,0xffffffff);
        FUN_00404230(&iStack_3c);
        pvStack_10._0_1_ = 3;
        FUN_00401660();
        pvStack_10 = (void *)CONCAT31(pvStack_10._1_3_,2);
        if (0xf < uStack_24) {
          _free(pvStack_38);
          return;
        }
        FUN_00401660(auStack_6e + -6,0);
        (**(code **)(*DAT_00b5ad0c + 0x28))();
        if (0xf < uStack_54) {
          _free(pvStack_68);
          return;
        }
        uStack_54 = 0xf;
        uStack_58 = 0;
        if ((void *)0xf < pvStack_38) {
          _free(pvStack_4c);
          return;
        }
        pvStack_38 = (void *)0xf;
        iStack_3c = 0;
        pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
        goto joined_r0x007364a5;
      }
      puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
      if ((void *)0xf < pvStack_38) {
        _free(pvStack_4c);
        return;
      }
    }
    pvStack_38 = (void *)0xf;
    iStack_3c = 0;
    pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
    FUN_00401740();
    puStack_8._0_1_ = 4;
    iVar2 = FUN_00403fb0();
    puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
    if ((void *)0xf < pvStack_38) {
      _free(pvStack_4c);
      return;
    }
    if (iVar2 == -1) {
      uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar4 = operator_new(0x400);
      *(undefined4 *)((int)pvVar4 + 8) = uVar3;
      *(undefined4 *)((int)pvVar4 + 0xc) = 0x9000000;
      *(undefined2 *)((int)pvVar4 + 6) = 0x34;
      FUN_004244d0();
      FUN_0050cd30();
      FUN_00496ed0();
      FUN_004d8570();
      (**(code **)(*DAT_00b5af2c + 4))();
    }
    else {
      (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_40 = 0xf;
      uStack_44 = 0;
      uStack_54 = uStack_54 & 0xffffff00;
      FUN_00401660();
      pvStack_10._0_1_ = 5;
      FUN_00401660(&uStack_58,0,0xffffffff);
      FUN_00404230(&iStack_3c);
      pvStack_10._0_1_ = 6;
      FUN_00401660();
      pvStack_10 = (void *)CONCAT31(pvStack_10._1_3_,5);
      if (0xf < uStack_24) {
        _free(pvStack_38);
        return;
      }
      FUN_00401660(&uStack_58,0);
      (**(code **)(*DAT_00b5ad0c + 0x28))();
      if ((void *)0xf < pvStack_38) {
        _free(pvStack_4c);
        return;
      }
      pvStack_38 = (void *)0xf;
      iStack_3c = 0;
      pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
    }
  }
joined_r0x007364a5:
  if (in_stack_00000018 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(param_1);
  return;
}


// ==== __break @ 0x00736569 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== __break @ 0x0073656c ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== __break @ 0x00736825 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00736830 @ 0x00736830 ====

/* WARNING: Removing unreachable block (ram,0x00736a26) */

void FUN_00736830(void *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  void *pvVar4;
  int *in_ECX;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  undefined1 uStack00000000;
  uint in_stack_00000018;
  undefined1 auStack_25c [4];
  undefined4 uStack_248;
  uint uStack_238;
  uint uStack_234;
  void *pvStack_228;
  uint uStack_214;
  undefined1 auStack_130 [264];
  undefined1 uStack_28;
  undefined1 auStack_20 [16];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992033;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*in_ECX + 0x10))();
    if (cVar1 == '\0') {
      (**(code **)(*DAT_00b5a794 + 0xc))();
      FUN_00401660();
      pvStack_10 = (void *)CONCAT31(pvStack_10._1_3_,1);
      FUN_00401660(auStack_25c + 8,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(8);
      if (0xf < uStack_234) {
        _free(uStack_248);
        return;
      }
    }
    else {
      piVar2 = (int *)(**(code **)(*DAT_00b5a980 + 8))();
      if (piVar2 != (int *)0x0) {
        FUN_00401660(&uStack00000000);
        (**(code **)*DAT_00b5b18c)();
        if (uStack_238 != 0) {
          uVar5 = 0;
          uStack_28 = 3;
          if (0 < (int)uStack_238) {
            bVar6 = false;
            bVar7 = uStack_238 == 0;
            do {
              if (bVar6 || bVar7) {
                FUN_0079dba3();
              }
              cVar1 = FUN_00403d70();
              if (cVar1 != '\0') {
                uVar5 = uVar5 + 1;
              }
              FUN_004020e0(&DAT_009eec1c);
              uVar5 = uVar5 + 1;
              bVar6 = uStack_238 < uVar5;
              bVar7 = uStack_238 == uVar5;
            } while (!bVar7 && (int)uVar5 <= (int)uStack_238);
          }
          FUN_00404440(auStack_20,auStack_25c + 0x10);
        }
        uStack_28 = 2;
        FUN_00729120(auStack_130,&DAT_009eed34);
        uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        pvVar4 = operator_new(0x400);
        *(undefined4 *)((int)pvVar4 + 8) = uVar3;
        *(undefined4 *)((int)pvVar4 + 0xc) = 0x11030000;
        *(undefined2 *)((int)pvVar4 + 6) = 0x130;
        FUN_004244d0();
        (**(code **)(*piVar2 + 0x74))();
        FUN_0047aa00();
        FUN_00729120();
        FUN_007290f0();
        FUN_004d8570();
        if (0xf < uStack_214) {
          _free(pvStack_228);
          return;
        }
      }
    }
  }
  if (in_stack_00000018 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_00736b40 @ 0x00736b40 ====

/* WARNING: Removing unreachable block (ram,0x00736d96) */

void FUN_00736b40(void *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  void *pvVar4;
  int *in_ECX;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  uint in_stack_00000018;
  undefined1 auStack_25c [4];
  undefined1 auStack_246 [2];
  void *pvStack_244;
  uint uStack_23c;
  uint uStack_230;
  void *pvStack_228;
  uint uStack_214;
  undefined1 auStack_134 [264];
  undefined1 uStack_2c;
  undefined1 auStack_24 [16];
  undefined1 uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992071;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*in_ECX + 0x10))();
    if (cVar1 == '\0') {
      (**(code **)(*DAT_00b5a794 + 0xc))();
      FUN_00401660();
      pvStack_10 = (void *)CONCAT31(pvStack_10._1_3_,1);
      FUN_00401660(auStack_25c + 0xc,0);
      (**(code **)(*DAT_00b5ad0c + 0x28))();
      if (0xf < uStack_230) {
        _free(pvStack_244);
        return;
      }
    }
    else {
      piVar2 = (int *)(**(code **)(*DAT_00b5a980 + 8))();
      if (piVar2 != (int *)0x0) {
        cVar1 = (**(code **)(*in_ECX + 4))();
        if (cVar1 == '\0') {
          (**(code **)(*DAT_00b5a794 + 0xc))();
          FUN_00765c50();
          uStack_14 = 2;
          FUN_00765c50(auStack_25c + 8);
          (**(code **)(*DAT_00b5ad0c + 0x28))(8);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        FUN_00765c50();
        (**(code **)*DAT_00b5b18c)();
        if (uStack_23c != 0) {
          uVar5 = 0;
          uStack_2c = 4;
          if (0 < (int)uStack_23c) {
            bVar6 = false;
            bVar7 = uStack_23c == 0;
            do {
              if (bVar6 || bVar7) {
                FUN_0079dba3();
              }
              cVar1 = FUN_00403d70();
              if (cVar1 != '\0') {
                uVar5 = uVar5 + 1;
              }
              FUN_004020e0(&DAT_009eec20);
              uVar5 = uVar5 + 1;
              bVar6 = uStack_23c < uVar5;
              bVar7 = uStack_23c == uVar5;
            } while (!bVar7 && (int)uVar5 <= (int)uStack_23c);
          }
          FUN_00404440(auStack_24,auStack_25c + 0xc);
        }
        uStack_2c = 3;
        FUN_00729120(auStack_134,&DAT_009eed34);
        uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        pvVar4 = operator_new(0x400);
        *(undefined4 *)((int)pvVar4 + 8) = uVar3;
        *(undefined4 *)((int)pvVar4 + 0xc) = 0x11030007;
        *(undefined2 *)((int)pvVar4 + 6) = 0x130;
        FUN_004244d0();
        (**(code **)(*piVar2 + 0x74))();
        FUN_0047aa00();
        FUN_00729120();
        FUN_007290f0();
        FUN_004d8570();
        if (0xf < uStack_214) {
          _free(pvStack_228);
          return;
        }
      }
    }
  }
  if (in_stack_00000018 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_00736eb0 @ 0x00736eb0 ====

/* WARNING: Removing unreachable block (ram,0x00737110) */
/* WARNING: Removing unreachable block (ram,0x00737318) */

void FUN_00736eb0(void *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  int *in_ECX;
  int *unaff_EBP;
  uint unaff_ESI;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  uint in_stack_00000018;
  undefined1 uStack0000001c;
  void *in_stack_00000020;
  uint in_stack_00000034;
  undefined1 auStack_1d8 [4];
  uint uStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  void *pvStack_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1a8;
  uint uStack_198;
  uint uStack_194;
  undefined1 auStack_168 [4];
  void *pvStack_164;
  undefined4 uStack_154;
  uint uStack_150;
  undefined1 *puStack_14c;
  void *pvStack_148;
  uint uStack_134;
  undefined1 auStack_12f [263];
  undefined1 uStack_28;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009920d8;
  pvStack_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*in_ECX + 0x10))();
    if (cVar1 == '\0') {
      uStack_1c4 = 0;
      pvStack_1c8 = (void *)0x736f34;
      uStack_1d0 = (**(code **)(*DAT_00b5a794 + 0xc))();
      pvStack_1c8 = (void *)0xffffffff;
      uStack_1cc = 0;
      uStack_1d4 = 0x736f52;
      FUN_00401660();
      pvStack_1c8 = (void *)0xf;
      uStack_1cc = 0;
      pvStack_10 = (void *)CONCAT31(pvStack_10._1_3_,2);
      FUN_00401660(auStack_1d8 + 0x24,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(8);
      if (0xf < uStack_194) {
        uStack_1c4 = 0x736f9b;
        _free(uStack_1a8);
        return;
      }
      if (0xf < in_stack_00000018) {
        uStack_1c4 = 0x736fc0;
        _free(param_1);
        return;
      }
    }
    else {
      iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
      if (iVar2 == 0) {
        if (0xf < in_stack_00000018) {
          uStack_1c4 = 0x736ffc;
          _free(param_1);
          return;
        }
      }
      else {
        puStack_14c = auStack_1d8;
        uStack_1c4 = 0;
        uStack_1d4 = uStack_1d4 & 0xffffff00;
        FUN_00401660(&uStack0000001c);
        (**(code **)*DAT_00b5b18c)();
        if (uStack_198 != 0) {
          unaff_ESI = 0xf;
          pvStack_1c8 = (void *)((uint)pvStack_1c8 & 0xffffff00);
          uVar5 = 0;
          uStack_28 = 4;
          if (0 < (int)uStack_198) {
            bVar6 = false;
            bVar7 = uStack_198 == 0;
            do {
              if (bVar6 || bVar7) {
                FUN_0079dba3();
              }
              cVar1 = FUN_00403d70();
              if (cVar1 != '\0') {
                uVar5 = uVar5 + 1;
              }
              FUN_004020e0(&DAT_009eec24);
              uVar5 = uVar5 + 1;
              bVar6 = uStack_198 < uVar5;
              bVar7 = uStack_198 == uVar5;
            } while (!bVar7 && (int)uVar5 <= (int)uStack_198);
          }
          FUN_00404440(&local_4,auStack_1d8 + 0x2c);
        }
        uStack_28 = 3;
        uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        pvVar4 = operator_new(0x400);
        *(undefined4 *)((int)pvVar4 + 8) = uVar3;
        *(undefined4 *)((int)pvVar4 + 0xc) = 0x11030001;
        *(undefined2 *)((int)pvVar4 + 6) = 0x16c;
        FUN_004244d0();
        (**(code **)(*unaff_EBP + 0x74))();
        FUN_0047aa00();
        FUN_0047aa30(&uStack_1cc,&DAT_009eed2c);
        FUN_0047aa00();
        FUN_00729120(auStack_12f,&DAT_009eed34);
        FUN_007290f0();
        FUN_004d8570();
        uStack_28 = 5;
        uVar3 = FUN_004022a0(&puStack_14c,&DAT_009eec2c);
        uStack_28 = 6;
        uVar3 = FUN_00402220(auStack_168,uVar3,&DAT_009eec28);
        uStack_28 = 7;
        uVar3 = FUN_00405bd0(&uStack_1cc,uVar3,&local_4);
        uStack_28 = 8;
        FUN_00401660(uVar3,0);
        if (0xf < unaff_ESI) {
          _free(pvStack_1c8);
          return;
        }
        pvStack_1c8 = (void *)((uint)pvStack_1c8 & 0xffffff00);
        if (0xf < uStack_150) {
          _free(pvStack_164);
          return;
        }
        uStack_150 = 0xf;
        uStack_154 = 0;
        pvStack_164 = (void *)((uint)pvStack_164 & 0xffffff00);
        uStack_28 = 5;
        if (0xf < uStack_134) {
          _free(pvStack_148);
          return;
        }
        (**(code **)(*DAT_00b5ad10 + 8))();
        (**(code **)(*DAT_00b5ad0c + 0x14))();
        if (0xf < uStack_150) {
          uStack_1c4 = 0x737303;
          _free(pvStack_164);
          return;
        }
        uStack_150 = 0xf;
        uStack_154 = 0;
        pvStack_164 = (void *)((uint)pvStack_164 & 0xffffff00);
        if (0xf < in_stack_00000018) {
          uStack_1c4 = 0x737347;
          _free(param_1);
          return;
        }
      }
    }
  }
  else if (0xf < in_stack_00000018) {
    uStack_1c4 = 0x736f08;
    _free(param_1);
    return;
  }
  if (in_stack_00000034 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  uStack_1c4 = 0x737375;
  _free(in_stack_00000020);
  return;
}


// ==== FUN_007373a0 @ 0x007373a0 ====

undefined4 FUN_007373a0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 extraout_EAX;
  void *pvVar3;
  int *in_ECX;
  void *pvStack_78;
  undefined1 auStack_70 [12];
  uint uStack_64;
  undefined1 uStack_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00992173;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_00403620();
  if (iVar2 == 0) {
    if ((*(int *)(param_1 + 0x28) != 0) &&
       ((*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28)) / 0x1c == 1)) {
      FUN_00459160();
      local_4 = 0;
      FUN_00401660();
      (**(code **)(*in_ECX + 0xa4))();
LAB_007374e0:
      if (uStack_64 < 0x10) {
        ExceptionList = local_c;
        return 1;
      }
      _free(pvStack_78);
      return extraout_EAX;
    }
  }
  else {
    iVar2 = FUN_00403620();
    if (iVar2 == 0) {
      if ((*(int *)(param_1 + 0x28) != 0) &&
         ((*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28)) / 0x1c == 1)) {
        FUN_00459160();
        local_4 = 1;
        FUN_00401660();
        (**(code **)(*in_ECX + 0xac))();
        goto LAB_007374e0;
      }
    }
    else {
      iVar2 = FUN_00403620();
      if (iVar2 == 0) {
        if ((*(int *)(param_1 + 0x28) != 0) &&
           ((*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28)) / 0x1c == 1)) {
          FUN_00459160();
          local_4 = 2;
          FUN_00765c50();
          (**(code **)(*in_ECX + 0xdc))();
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
      }
      else {
        cVar1 = FUN_004036a0();
        if (cVar1 != '\0') {
          (**(code **)(*in_ECX + 0xb4))();
          ExceptionList = local_c;
          return 1;
        }
        cVar1 = FUN_004036a0();
        if (cVar1 == '\0') {
          cVar1 = FUN_004036a0();
          if (cVar1 != '\0') {
            (**(code **)(*in_ECX + 0x38))();
            ExceptionList = local_c;
            return 1;
          }
          cVar1 = FUN_004036a0();
          if (cVar1 != '\0') {
            (**(code **)(*in_ECX + 0x34))();
            ExceptionList = local_c;
            return 1;
          }
          cVar1 = FUN_004036a0();
          if (cVar1 != '\0') {
            (**(code **)(*DAT_00b5a794 + 0xc))();
            FUN_00765c50();
            local_c = (void *)0x4;
            (**(code **)(*DAT_00b5a794 + 0xc))();
            FUN_00765c50();
            uStack_14 = 5;
            pvVar3 = operator_new(0x3c);
            uStack_14 = 6;
            if (pvVar3 != (void *)0x0) {
              FUN_00765c50();
              uStack_14 = 7;
              FUN_00765c50(auStack_70);
              uStack_14 = 6;
              FUN_00737c70();
            }
            uStack_14 = 5;
            FUN_00797a20();
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          cVar1 = FUN_004036a0();
          if (cVar1 == '\0') {
            cVar1 = FUN_004036a0();
            if (cVar1 != '\0') {
              FUN_00459160();
              local_4 = 8;
              thunk_FUN_00796f50();
              local_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            cVar1 = FUN_004036a0();
            if (cVar1 != '\0') {
              FUN_00459160();
              local_4 = 10;
              thunk_FUN_00796f50();
              local_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            cVar1 = FUN_004036a0();
            if (cVar1 != '\0') {
              FUN_00459160();
              local_4 = 0xc;
              thunk_FUN_00796f50();
              local_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            cVar1 = FUN_004036a0();
            if (cVar1 != '\0') {
              FUN_00459160();
              local_4 = 0xf;
              thunk_FUN_00796f50();
              local_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            ExceptionList = local_c;
            return 0;
          }
          (**(code **)(*in_ECX + 0xa8))();
        }
        else {
          iVar2 = FUN_004f45a0();
          if (iVar2 == 1) {
            FUN_00459160();
            local_4 = 3;
            FUN_00765c50();
            (**(code **)(*in_ECX + 0xb8))();
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
        }
      }
    }
  }
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_007379d0 @ 0x007379d0 ====

undefined4 FUN_007379d0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_007373a0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00737a00 @ 0x00737a00 ====

void FUN_00737a00(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x11010006;
  *(undefined2 *)((int)pvVar1 + 6) = 0x1c;
  FUN_004244d0();
  return;
}


// ==== FUN_00737a30 @ 0x00737a30 ====

void FUN_00737a30(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x1101000f;
  *(undefined2 *)((int)pvVar1 + 6) = 0x40;
  FUN_004244d0();
  return;
}


// ==== FUN_00737a60 @ 0x00737a60 ====

void FUN_00737a60(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x11020009;
  *(undefined2 *)((int)pvVar1 + 6) = 0x34;
  FUN_004244d0();
  return;
}


// ==== FUN_00737a90 @ 0x00737a90 ====

undefined4 FUN_00737a90(void)

{
  return 0x70320025;
}


// ==== FUN_00737aa0 @ 0x00737aa0 ====

undefined4 FUN_00737aa0(void)

{
  return 0x70320002;
}


// ==== FUN_00737ab0 @ 0x00737ab0 ====

undefined4 FUN_00737ab0(void)

{
  return 0x70320003;
}


// ==== FUN_00737ac0 @ 0x00737ac0 ====

undefined4 FUN_00737ac0(void)

{
  return 0x70320004;
}


// ==== FUN_00737ad0 @ 0x00737ad0 ====

undefined4 FUN_00737ad0(void)

{
  return 0x70320055;
}


// ==== FUN_00737ae0 @ 0x00737ae0 ====

undefined4 FUN_00737ae0(void)

{
  return 0x70320056;
}


// ==== FUN_00737af0 @ 0x00737af0 ====

undefined4 FUN_00737af0(void)

{
  return 0x70320021;
}


// ==== FUN_00737b00 @ 0x00737b00 ====

undefined4 FUN_00737b00(void)

{
  return 0x70320022;
}


// ==== FUN_00737b10 @ 0x00737b10 ====

undefined4 FUN_00737b10(void)

{
  return 0x70320031;
}


// ==== FUN_00737b20 @ 0x00737b20 ====

undefined4 FUN_00737b20(void)

{
  return 0x70320016;
}


// ==== FUN_00737b30 @ 0x00737b30 ====

undefined4 FUN_00737b30(void)

{
  return 0x70320017;
}


// ==== FUN_00737b40 @ 0x00737b40 ====

undefined4 FUN_00737b40(void)

{
  return 0x70320023;
}


// ==== FUN_00737b50 @ 0x00737b50 ====

undefined4 FUN_00737b50(void)

{
  return 0x70320024;
}


// ==== FUN_00737b60 @ 0x00737b60 ====

undefined4 FUN_00737b60(void)

{
  return 0x70320040;
}


// ==== FUN_00737b70 @ 0x00737b70 ====

undefined4 FUN_00737b70(void)

{
  return 0x70320041;
}


// ==== FUN_00737b80 @ 0x00737b80 ====

undefined4 FUN_00737b80(void)

{
  return 0x70040015;
}


// ==== FUN_00737b90 @ 0x00737b90 ====

undefined4 FUN_00737b90(void)

{
  return 0x70320030;
}


// ==== FUN_00737ba0 @ 0x00737ba0 ====

void FUN_00737ba0(byte param_1)

{
  void *in_ECX;
  
  FUN_00737bc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00737bc0 @ 0x00737bc0 ====

void FUN_00737bc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eef9c;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_0099cf40;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00737c00 @ 0x00737c00 ====

undefined4 FUN_00737c00(void)

{
  return 0x70320006;
}


// ==== FUN_00737c10 @ 0x00737c10 ====

void FUN_00737c10(byte param_1)

{
  void *in_ECX;
  
  FUN_00737c30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00737c30 @ 0x00737c30 ====

void FUN_00737c30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eefb0;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_0099cf40;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00737c70 @ 0x00737c70 ====

void FUN_00737c70(undefined1 param_1,void *param_2)

{
  undefined4 *in_ECX;
  uint in_stack_0000001c;
  undefined1 uStack00000020;
  void *in_stack_00000024;
  uint in_stack_00000038;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009921a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009eefc4;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  local_4 = 2;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401660(&param_1,0,0xffffffff);
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  local_4 = CONCAT31(local_4._1_3_,3);
  *(undefined1 *)(in_ECX + 9) = 0;
  FUN_00401660(&uStack00000020,0,0xffffffff);
  if (0xf < in_stack_0000001c) {
    _free(param_2);
    return;
  }
  if (in_stack_00000038 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(in_stack_00000024);
  return;
}


// ==== FUN_00737d20 @ 0x00737d20 ====

undefined4 FUN_00737d20(void)

{
  return 0x70320008;
}


// ==== FUN_00737d30 @ 0x00737d30 ====

void FUN_00737d30(byte param_1)

{
  void *in_ECX;
  
  FUN_00737d50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00737d50 @ 0x00737d50 ====

void FUN_00737d50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eefc4;
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


// ==== FUN_00737db0 @ 0x00737db0 ====

void FUN_00737db0(undefined1 param_1,void *param_2)

{
  undefined4 *in_ECX;
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009921c0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009eefd8;
  in_ECX[6] = 0;
  in_ECX[7] = 0xf;
  *(undefined1 *)(in_ECX + 2) = 0;
  local_4 = 1;
  FUN_00401660(&param_1,0,0xffffffff);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00737e30 @ 0x00737e30 ====

undefined4 FUN_00737e30(void)

{
  return 0x70320009;
}


// ==== FUN_00737e40 @ 0x00737e40 ====

void FUN_00737e40(byte param_1)

{
  void *in_ECX;
  
  FUN_00737e60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00737e60 @ 0x00737e60 ====

void FUN_00737e60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eefd8;
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


// ==== FUN_00737ea0 @ 0x00737ea0 ====

void FUN_00737ea0(undefined1 param_1,void *param_2)

{
  undefined4 *in_ECX;
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009921c0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009eefec;
  in_ECX[6] = 0;
  in_ECX[7] = 0xf;
  *(undefined1 *)(in_ECX + 2) = 0;
  local_4 = 1;
  FUN_00401660(&param_1,0,0xffffffff);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00737f20 @ 0x00737f20 ====

undefined4 FUN_00737f20(void)

{
  return 0x70320020;
}


// ==== FUN_00737f30 @ 0x00737f30 ====

void FUN_00737f30(byte param_1)

{
  void *in_ECX;
  
  FUN_00737f50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00737f50 @ 0x00737f50 ====

void FUN_00737f50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eefec;
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


// ==== FUN_00737f90 @ 0x00737f90 ====

void FUN_00737f90(byte param_1)

{
  void *in_ECX;
  
  FUN_00735bf0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00737fb0 @ 0x00737fb0 ====

void FUN_00737fb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ef24c;
  return;
}


// ==== FUN_00737fc0 @ 0x00737fc0 ====

void FUN_00737fc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ef24c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007380a0 @ 0x007380a0 ====

undefined4 FUN_007380a0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1e4);
}


// ==== FUN_007380b0 @ 0x007380b0 ====

undefined4 FUN_007380b0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1e4) == 0) {
    return 0;
  }
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x1e4) + 0x14))();
                    /* WARNING: Could not recover jumptable at 0x007380cb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(*piVar1 + 0x10))();
  return uVar2;
}


// ==== FUN_007380d0 @ 0x007380d0 ====

uint FUN_007380d0(void)

{
  uint in_EAX;
  int *piVar1;
  uint uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1e4) == 0) {
    return in_EAX & 0xffffff00;
  }
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x1e4) + 0x14))();
                    /* WARNING: Could not recover jumptable at 0x007380eb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(*piVar1 + 0x18))();
  return uVar2;
}


// ==== FUN_007380f0 @ 0x007380f0 ====

int FUN_007380f0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8)) / 0x24;
}


// ==== FUN_00738170 @ 0x00738170 ====

uint FUN_00738170(int param_1)

{
  uint extraout_EAX;
  uint uVar1;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  int *in_ECX;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00992218;
  local_c = ExceptionList;
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(s_invalide_name_009ef144,0xd);
  local_4 = 0;
  if (param_1 == 0) {
    uVar1 = 0;
    if ((void *)0xf < local_10) {
      _free(local_24);
      return extraout_EAX;
    }
  }
  else {
    uVar1 = (**(code **)(*in_ECX + 0x50))(param_1,&local_28);
    if ((char)uVar1 != '\0') {
      uVar1 = (**(code **)(*in_ECX + 0x34))(&local_28);
      if (local_14 < 0x10) {
        ExceptionList = local_10;
        return uVar1;
      }
      _free(local_28);
      return extraout_EAX_01;
    }
    if ((void *)0xf < local_10) {
      _free(local_24);
      return extraout_EAX_00;
    }
  }
  ExceptionList = local_c;
  return uVar1 & 0xffffff00;
}


// ==== FUN_00738260 @ 0x00738260 ====

/* WARNING: Removing unreachable block (ram,0x007382ef) */
/* WARNING: Removing unreachable block (ram,0x0073834b) */
/* WARNING: Removing unreachable block (ram,0x00738350) */
/* WARNING: Removing unreachable block (ram,0x007382f6) */
/* WARNING: Removing unreachable block (ram,0x00738308) */
/* WARNING: Removing unreachable block (ram,0x00738303) */
/* WARNING: Removing unreachable block (ram,0x0073830b) */
/* WARNING: Removing unreachable block (ram,0x0073831d) */
/* WARNING: Removing unreachable block (ram,0x00738330) */
/* WARNING: Removing unreachable block (ram,0x00738345) */
/* WARNING: Removing unreachable block (ram,0x00738323) */

uint FUN_00738260(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  char *pcVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099222a;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0x14) == 0) {
    return (uint)ExceptionList & 0xffffff00;
  }
  ExceptionList = &local_c;
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x1e4) + 0xc))();
  pcVar4 = (char *)(iVar2 + 0x200);
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar3 = FUN_00401740((char *)(iVar2 + 0x200),(int)pcVar4 - (iVar2 + 0x201));
  ExceptionList = local_c;
  return uVar3 & 0xffffff00;
}


// ==== FUN_00738370 @ 0x00738370 ====

/* WARNING: Removing unreachable block (ram,0x007383dc) */
/* WARNING: Removing unreachable block (ram,0x0073841f) */
/* WARNING: Removing unreachable block (ram,0x007383f3) */
/* WARNING: Removing unreachable block (ram,0x007383fa) */
/* WARNING: Removing unreachable block (ram,0x0073840e) */
/* WARNING: Removing unreachable block (ram,0x00738418) */
/* WARNING: Removing unreachable block (ram,0x00738401) */

undefined1 FUN_00738370(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  char *pcVar6;
  
  iVar2 = (**(code **)(*DAT_00b5a97c + 0xc))();
  if (iVar2 == param_1) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x1e4) + 0xc))();
    pcVar6 = (char *)(iVar2 + 0x200);
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740((char *)(iVar2 + 0x200),(int)pcVar6 - (iVar2 + 0x201));
  }
  else {
    piVar3 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_1);
    if (piVar3 != (int *)0x0) {
      piVar4 = (int *)(**(code **)(*piVar3 + 0x14))();
      iVar2 = (**(code **)(*piVar4 + 0x24))();
      if ((iVar2 != 0) && (iVar5 = (**(code **)(*piVar3 + 0xc))(), iVar5 == 0)) {
        piVar3 = (int *)FUN_00803725(iVar2,0,&Framework::ICreature::RTTI_Type_Descriptor,
                                     &Framework::Creature::IMiniPC::RTTI_Type_Descriptor,0);
        if (piVar3 != (int *)0x0) {
          iVar2 = (**(code **)(*piVar3 + 0x24))();
          return *(undefined1 *)(iVar2 + 0x29);
        }
      }
    }
  }
  return 0;
}


// ==== FUN_007384a0 @ 0x007384a0 ====

uint FUN_007384a0(undefined4 param_1)

{
  code *pcVar1;
  char cVar2;
  uint extraout_EAX;
  int *piVar3;
  uint extraout_EAX_00;
  uint uVar4;
  uint extraout_EAX_01;
  int iVar5;
  uint extraout_EAX_02;
  uint extraout_EAX_03;
  uint extraout_EAX_04;
  int *in_ECX;
  undefined1 *unaff_EBX;
  void *unaff_ESI;
  undefined1 local_4c [2];
  undefined1 auStack_4a [2];
  undefined1 local_48;
  uint uStack_40;
  uint uStack_3c;
  undefined4 local_38;
  void *local_34;
  undefined4 uStack_24;
  uint uStack_20;
  void *pvStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099224c;
  pvStack_c = ExceptionList;
  local_34 = (void *)0xf;
  local_38 = 0;
  local_48 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_invalide_name_009ef154,0xd);
  local_4 = 0;
  cVar2 = (**(code **)(*in_ECX + 0x50))(param_1,local_4c);
  if (cVar2 == '\0') {
    if (uStack_3c < 0x10) {
      ExceptionList = pvStack_14;
      return 0;
    }
    _free(unaff_EBX);
    return extraout_EAX;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5acac + 0x30))();
  if (piVar3 == (int *)0x0) {
    uStack_20 = 0xf;
    uStack_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_00401740(s_pMyLogicGuild____NULL_009ef164,0x15);
    pvStack_c._0_1_ = 1;
    FUN_00406880(&local_38);
    pvStack_c = (void *)((uint)pvStack_c._1_3_ << 8);
    if (uStack_20 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
    _free(local_34);
    return extraout_EAX_00;
  }
  piVar3 = (int *)(**(code **)(*piVar3 + 0x14))();
  if (piVar3 == (int *)0x0) {
    uStack_20 = 0xf;
    uStack_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_00401740(s_pMyGuildSiege____NULL_009ef17c,0x15);
    pvStack_c._0_1_ = 2;
    FUN_00406880(&local_38);
    pvStack_c = (void *)((uint)pvStack_c._1_3_ << 8);
    if (uStack_20 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
    _free(local_34);
    return extraout_EAX_01;
  }
  iVar5 = (**(code **)(*piVar3 + 0x10))();
  if (iVar5 == 1) {
    if (uStack_3c < 0x10) {
      unaff_EBX = local_4c + -4;
    }
    FUN_0050cd30(&local_38,&DAT_009ef23c,unaff_EBX);
    iVar5 = (**(code **)(*DAT_00b5ac9c + 0xc))(&local_38);
    if (0xf < uStack_40) {
      _free(unaff_ESI);
      return extraout_EAX_02;
    }
  }
  else {
    if (iVar5 != 3) {
      if (uStack_3c < 0x10) {
        ExceptionList = pvStack_14;
        return 0;
      }
      _free(unaff_EBX);
      return extraout_EAX_04;
    }
    if (uStack_3c < 0x10) {
      unaff_EBX = local_4c + -4;
    }
    FUN_0050cd30(&local_38,&DAT_009ef23c,unaff_EBX);
    iVar5 = (**(code **)(*DAT_00b5abec + 0xc))(&local_38);
    if (0xf < uStack_40) {
      _free(unaff_ESI);
      return extraout_EAX_03;
    }
  }
  ExceptionList = pvStack_18;
  return (uint)(iVar5 != 0);
}


// ==== FUN_007386d0 @ 0x007386d0 ====

uint FUN_007386d0(int *param_1)

{
  char cVar1;
  code *pcVar2;
  char *pcVar3;
  int *piVar4;
  uint extraout_EAX;
  uint uVar5;
  uint extraout_EAX_00;
  int iVar6;
  uint extraout_EAX_01;
  undefined4 ****ppppuVar7;
  uint extraout_EAX_02;
  uint extraout_EAX_03;
  char *pcVar8;
  void *pvStack_4c;
  undefined4 ****appppuStack_48 [4];
  uint uStack_38;
  uint uStack_34;
  undefined1 auStack_30 [4];
  void *pvStack_2c;
  undefined4 uStack_1c;
  uint uStack_18;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099226e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pcVar3 = (char *)(**(code **)(*param_1 + 0x24))();
  uStack_34 = 0xf;
  uStack_38 = 0;
  appppuStack_48[0] = (undefined4 ****)((uint)appppuStack_48[0] & 0xffffff00);
  pcVar8 = pcVar3;
  do {
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar3,(int)pcVar8 - (int)(pcVar3 + 1));
  iStack_4 = 0;
  piVar4 = (int *)(**(code **)(*DAT_00b5acac + 0x30))();
  if (piVar4 == (int *)0x0) {
    uStack_18 = 0xf;
    uStack_1c = 0;
    pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
    FUN_00401740(s_pMyLogicGuild____NULL_009ef194,0x15);
    iStack_4._0_1_ = 1;
    FUN_00406880(auStack_30);
    iStack_4 = (uint)iStack_4._1_3_ << 8;
    if (uStack_18 < 0x10) {
      pcVar2 = (code *)swi(3);
      uVar5 = (*pcVar2)();
      return uVar5;
    }
    _free(pvStack_2c);
    return extraout_EAX;
  }
  piVar4 = (int *)(**(code **)(*piVar4 + 0x14))();
  if (piVar4 == (int *)0x0) {
    uStack_18 = 0xf;
    uStack_1c = 0;
    pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
    FUN_00401740(s_pMyGuildSiege____NULL_009ef1ac,0x15);
    iStack_4._0_1_ = 2;
    FUN_00406880(auStack_30);
    iStack_4 = (uint)iStack_4._1_3_ << 8;
    if (uStack_18 < 0x10) {
      pcVar2 = (code *)swi(3);
      uVar5 = (*pcVar2)();
      return uVar5;
    }
    _free(pvStack_2c);
    return extraout_EAX_00;
  }
  iVar6 = (**(code **)(*piVar4 + 0x10))();
  if (iVar6 == 1) {
    ppppuVar7 = appppuStack_48[0];
    if (uStack_34 < 0x10) {
      ppppuVar7 = appppuStack_48;
    }
    FUN_0050cd30(auStack_30,&DAT_009ef23c,ppppuVar7);
    iVar6 = (**(code **)(*DAT_00b5ac9c + 0xc))(auStack_30);
    if (0xf < uStack_38) {
      _free(pvStack_4c);
      return extraout_EAX_01;
    }
  }
  else {
    if (iVar6 != 3) {
      if (uStack_34 < 0x10) {
        ExceptionList = pvStack_c;
        return 0;
      }
      _free(appppuStack_48[0]);
      return extraout_EAX_03;
    }
    ppppuVar7 = appppuStack_48[0];
    if (uStack_34 < 0x10) {
      ppppuVar7 = appppuStack_48;
    }
    FUN_0050cd30(auStack_30,&DAT_009ef23c,ppppuVar7);
    iVar6 = (**(code **)(*DAT_00b5abec + 0xc))(auStack_30);
    if (0xf < uStack_38) {
      _free(pvStack_4c);
      return extraout_EAX_02;
    }
  }
  ExceptionList = pvStack_10;
  return (uint)(iVar6 != 0);
}


// ==== FUN_007388e0 @ 0x007388e0 ====

undefined4 FUN_007388e0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_1);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  piVar2 = (int *)(**(code **)(*piVar1 + 0x14))();
  iVar3 = (**(code **)(*piVar2 + 0x24))();
  if (iVar3 != 0) {
    iVar4 = (**(code **)(*DAT_00b5a97c + 0xc))();
    if (iVar4 == param_1) {
LAB_007389bb:
      FUN_00401660(in_ECX + 0x14,0,0xffffffff);
      return 1;
    }
    iVar4 = (**(code **)(*piVar1 + 0xc))();
    if (iVar4 == 0) {
      piVar1 = (int *)FUN_00803725(iVar3,0,&Framework::ICreature::RTTI_Type_Descriptor,
                                   &Framework::Creature::IMiniPC::RTTI_Type_Descriptor,0);
      if (piVar1 != (int *)0x0) {
        iVar3 = *piVar1;
LAB_007389fe:
        uVar5 = (**(code **)(iVar3 + 0x24))();
        FUN_00403810(uVar5);
        return 1;
      }
    }
    else if (iVar4 == 2) {
      piVar1 = (int *)FUN_00803725(iVar3,0,&Framework::ICreature::RTTI_Type_Descriptor,
                                   &Framework::Creature::IServant::RTTI_Type_Descriptor,0);
      if (piVar1 != (int *)0x0) {
        piVar1 = (int *)(**(code **)(*piVar1 + 0x20))();
        if (piVar1 != (int *)0x0) {
          iVar3 = piVar1[0x2b];
          iVar4 = (**(code **)(*DAT_00b5a97c + 0xc))();
          if (iVar4 != iVar3) {
            iVar3 = *piVar1;
            goto LAB_007389fe;
          }
          goto LAB_007389bb;
        }
      }
    }
    else if (iVar4 == 6) {
      iVar3 = (**(code **)(**(int **)(in_ECX + 0x1e4) + 0xc))();
      FUN_00403810(iVar3 + 0x200);
      uVar5 = (**(code **)(*DAT_00b5add0 + 0x40))();
      return uVar5;
    }
  }
  return 0;
}


// ==== FUN_00738a20 @ 0x00738a20 ====

void FUN_00738a20(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  FUN_00401740(&DAT_009ef1c2,0);
  FUN_00401740(&DAT_009ef1c3,0);
  *(undefined2 *)(in_ECX + 0x54) = 0;
  *(undefined2 *)(in_ECX + 0x56) = 0;
  *(undefined2 *)(in_ECX + 0x58) = 0;
  *(undefined2 *)(in_ECX + 0x5a) = 0;
  return;
}


// ==== FUN_00738a60 @ 0x00738a60 ====

undefined4 FUN_00738a60(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00733990(in_ECX + 0x14);
  return param_1;
}


// ==== FUN_00738a80 @ 0x00738a80 ====

void FUN_00738a80(undefined1 param_1)

{
  short sVar1;
  code *pcVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int unaff_EBX;
  undefined4 *puVar9;
  undefined1 local_58 [4];
  void *pvStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 auStack_3c [10];
  undefined4 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009922a0;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  FUN_00733a40(&param_1);
  uVar3 = (**(code **)(*DAT_00b5a97c + 0xc))();
  piVar4 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(uVar3);
  if (piVar4 == (int *)0x0) {
    uStack_40 = 0xf;
    uStack_44 = 0;
    pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
    FUN_00401740(s_pActor____NULL_009ef1c4,0xe);
    puStack_8._0_1_ = 1;
    FUN_00406880(local_58);
    puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
    if (uStack_40 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_54);
    return;
  }
  piVar5 = (int *)(**(code **)(*piVar4 + 0x14))();
  iVar6 = (**(code **)(*piVar5 + 0x24))();
  if (iVar6 == 0) {
    uStack_40 = 0xf;
    uStack_44 = 0;
    pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
    FUN_00401740(s_pCreature____NULL_009ef1d4,0x11);
    puStack_8._0_1_ = 2;
    FUN_00406880(local_58);
    puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
    if (uStack_40 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_54);
    return;
  }
  iVar7 = (**(code **)(*piVar4 + 0xc))();
  if (iVar7 != 0) {
    uStack_40 = 0xf;
    uStack_44 = 0;
    pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
    FUN_00401740(s_pActor_>GetActorType______IActor_009ef1e8,0x2c);
    puStack_8._0_1_ = 3;
    FUN_00406880(local_58);
    puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
    if (uStack_40 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_54);
    return;
  }
  piVar4 = (int *)FUN_00803725(iVar6,0,&Framework::ICreature::RTTI_Type_Descriptor,
                               &Framework::Creature::IMiniPC::RTTI_Type_Descriptor,0);
  if (piVar4 != (int *)0x0) {
    puVar8 = (undefined4 *)(**(code **)(*piVar4 + 0x24))();
    sVar1 = *(short *)(unaff_EBX + 0x5a);
    puVar9 = auStack_3c;
    for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar9 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    }
    *(undefined2 *)puVar9 = *(undefined2 *)puVar8;
    uStack_14._0_2_ = CONCAT11(sVar1 == 0,(undefined1)uStack_14);
    (**(code **)(*piVar4 + 0x20))(auStack_3c);
    (**(code **)(*DAT_00b5ac94 + 4))();
    pvStack_c = (void *)0xffffffff;
    FUN_00537c20();
    ExceptionList = uStack_14;
    return;
  }
  uStack_40 = 0xf;
  uStack_44 = 0;
  pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
  FUN_00401740(s_pLogicPC____NULL_009ef218,0x10);
  puStack_8._0_1_ = 4;
  FUN_00406880(local_58);
  puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
  if (uStack_40 < 0x10) {
    uStack_40 = 0xf;
    uStack_44 = 0;
    pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _free(pvStack_54);
  return;
}


// ==== FUN_00738ca0 @ 0x00738ca0 ====

void FUN_00738ca0(undefined4 param_1,byte *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,uint param_6,uint param_7,undefined4 param_8,undefined2 param_9)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *in_ECX;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  uint local_50;
  byte *pbStack_4c;
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009922c2;
  pvStack_c = ExceptionList;
  iVar5 = 0;
  local_4 = 0;
  local_50 = 0;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar1 != 0) {
    do {
      iVar1 = in_ECX[2];
      if ((iVar1 == 0) || ((uint)((in_ECX[3] - iVar1) / 0x24) <= local_50)) {
        FUN_007396c0();
LAB_00738ebf:
        *(undefined1 *)(iVar5 + 0x1c + iVar1) = (undefined1)param_8;
        *(undefined1 *)(iVar5 + 0x1d + iVar1) = param_8._1_1_;
        *(undefined1 *)(iVar5 + 0x1e + iVar1) = param_8._2_1_;
        *(undefined2 *)(iVar5 + 0x20 + iVar1) = param_9;
        goto joined_r0x00738ef2;
      }
      if (param_7 < 0x10) {
        pbStack_4c = (byte *)&param_2;
      }
      else {
        pbStack_4c = param_2;
      }
      uVar3 = *(uint *)(iVar5 + 0x14 + iVar1);
      if (uVar3 == 0) {
LAB_00738d68:
        if ((param_6 <= uVar3) && (uVar3 == param_6)) goto LAB_00738ebf;
      }
      else {
        uVar4 = param_6;
        if (uVar3 < param_6) {
          uVar4 = uVar3;
        }
        if (*(uint *)(iVar5 + 0x18 + iVar1) < 0x10) {
          pbVar6 = (byte *)(iVar5 + 4 + iVar1);
        }
        else {
          pbVar6 = *(byte **)(iVar5 + 4 + iVar1);
        }
        bVar7 = false;
        iVar2 = 0;
        bVar8 = true;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          bVar7 = *pbVar6 < *pbStack_4c;
          bVar8 = *pbVar6 == *pbStack_4c;
          pbVar6 = pbVar6 + 1;
          pbStack_4c = pbStack_4c + 1;
        } while (bVar8);
        if (!bVar8) {
          iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        }
        if (iVar2 == 0) goto LAB_00738d68;
      }
      local_50 = local_50 + 1;
      iVar5 = iVar5 + 0x24;
      uVar3 = (**(code **)(*in_ECX + 0x1c))();
    } while (local_50 < uVar3);
  }
  (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401660();
  pvStack_c._0_1_ = 1;
  FUN_00401740(s__s___s__009ef22c,7);
  FUN_00404230(&uStack_30);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
  FUN_00401660(&uStack_30);
  (**(code **)(*DAT_00b5ad0c + 0x28))();
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
  uStack_2c = 0xf;
  uStack_30 = 0;
joined_r0x00738ef2:
  if (param_7 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00738f00 @ 0x00738f00 ====

int FUN_00738f00(int param_1,uint param_2)

{
  int iVar1;
  int in_ECX;
  uint extraout_EDX;
  
  iVar1 = *(int *)(in_ECX + 8);
  if (iVar1 != 0) {
    if (param_2 < (uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x24)) goto LAB_00738f37;
  }
  FUN_007396c0();
  param_2 = extraout_EDX;
LAB_00738f37:
  iVar1 = iVar1 + param_2 * 0x24;
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(iVar1,0,0xffffffff);
  *(undefined1 *)(param_1 + 0x1c) = *(undefined1 *)(iVar1 + 0x1c);
  *(undefined1 *)(param_1 + 0x1d) = *(undefined1 *)(iVar1 + 0x1d);
  *(undefined1 *)(param_1 + 0x1e) = *(undefined1 *)(iVar1 + 0x1e);
  *(undefined2 *)(param_1 + 0x20) = *(undefined2 *)(iVar1 + 0x20);
  return param_1;
}


// ==== FUN_00738f90 @ 0x00738f90 ====

/* WARNING: Removing unreachable block (ram,0x00739015) */

int FUN_00738f90(undefined4 param_1,byte *param_2)

{
  int iVar1;
  uint uVar2;
  int extraout_EAX;
  int extraout_EAX_00;
  int *in_ECX;
  uint uVar3;
  int unaff_EBX;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  uint in_stack_00000018;
  uint in_stack_0000001c;
  int iStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009922d4;
  pvStack_c = ExceptionList;
  uVar4 = 0;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar1 != 0) {
    iStack_14 = 0;
    do {
      iVar1 = in_ECX[2];
      if ((iVar1 == 0) || ((uint)((in_ECX[3] - iVar1) / 0x24) <= uVar4)) {
        FUN_007396c0();
        goto LAB_0073907b;
      }
      unaff_EBX = iStack_14 + iVar1;
      pbVar6 = param_2;
      if (in_stack_0000001c < 0x10) {
        pbVar6 = (byte *)&param_2;
      }
      uVar2 = *(uint *)(unaff_EBX + 0x14);
      if (uVar2 == 0) {
LAB_00739043:
        if ((in_stack_00000018 <= uVar2) && (uVar2 == in_stack_00000018)) {
LAB_0073907b:
          if (in_stack_0000001c < 0x10) {
            ExceptionList = pvStack_c;
            return unaff_EBX;
          }
          _free(param_2);
          return extraout_EAX;
        }
      }
      else {
        uVar3 = in_stack_00000018;
        if (uVar2 < in_stack_00000018) {
          uVar3 = uVar2;
        }
        if (*(uint *)(unaff_EBX + 0x18) < 0x10) {
          pbVar5 = (byte *)(unaff_EBX + 4);
        }
        else {
          pbVar5 = *(byte **)(unaff_EBX + 4);
        }
        bVar7 = false;
        iVar1 = 0;
        bVar8 = true;
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          bVar7 = *pbVar5 < *pbVar6;
          bVar8 = *pbVar5 == *pbVar6;
          pbVar5 = pbVar5 + 1;
          pbVar6 = pbVar6 + 1;
        } while (bVar8);
        if (!bVar8) {
          iVar1 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        }
        if (iVar1 == 0) goto LAB_00739043;
      }
      iStack_14 = iStack_14 + 0x24;
      uVar4 = uVar4 + 1;
      uVar2 = (**(code **)(*in_ECX + 0x1c))();
    } while (uVar4 < uVar2);
  }
  if (in_stack_0000001c < 0x10) {
    ExceptionList = pvStack_c;
    return 0;
  }
  _free(param_2);
  return extraout_EAX_00;
}


// ==== FUN_007390e0 @ 0x007390e0 ====

void FUN_007390e0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009922fc;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ef2a4;
  local_4 = 2;
  if ((undefined4 *)in_ECX[0x79] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x79])(1);
  }
  in_ECX[0x79] = 0;
  DAT_00b5acac = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00537c20();
  FUN_0073a120();
  *in_ECX = &PTR_FUN_009ef24c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00739160 @ 0x00739160 ====

void FUN_00739160(void)

{
  FUN_0073a120();
  return;
}


// ==== FUN_00739170 @ 0x00739170 ====

void FUN_00739170(undefined4 param_1,byte *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,uint param_6,uint param_7)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  int iVar5;
  byte ******ppppppbVar6;
  bool bVar7;
  bool bVar8;
  void *pvStack_64;
  undefined4 uStack_54;
  uint uStack_50;
  void *pvStack_48;
  undefined4 uStack_38;
  uint uStack_34;
  byte ******local_2c [4];
  uint local_1c;
  uint local_18;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined2 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  puStack_8 = &LAB_00992326;
  iVar5 = *(int *)(in_ECX + 8);
  iVar1 = *(int *)(in_ECX + 0xc);
  uStack_3 = 0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  do {
    if (iVar5 == iVar1) {
      local_4 = 0;
      (**(code **)(*DAT_00b5a794 + 0xc))();
      FUN_00401660();
      pvStack_c._0_1_ = 2;
      FUN_00401740(s__s___s__009ef234,7);
      FUN_00404230(&uStack_54);
      pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
      FUN_00401660(&uStack_54);
      (**(code **)(*DAT_00b5ad0c + 0x28))();
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
LAB_0073940b:
      if (param_7 < 0x10) {
        ExceptionList = pvStack_c;
        return;
      }
      _free(param_2);
      return;
    }
    local_4 = 0;
    local_18 = 0xf;
    local_1c = 0;
    local_2c[0] = (byte ******)((uint)local_2c[0] & 0xffffff00);
    FUN_00401660();
    local_14 = *(undefined1 *)(iVar5 + 0x1c);
    local_13 = *(undefined1 *)(iVar5 + 0x1d);
    local_12 = *(undefined1 *)(iVar5 + 0x1e);
    local_10 = *(undefined2 *)(iVar5 + 0x20);
    local_4 = 1;
    pbVar2 = param_2;
    if (param_7 < 0x10) {
      pbVar2 = (byte *)&param_2;
    }
    if (local_1c == 0) {
LAB_00739240:
      if ((param_6 <= local_1c) && (local_1c == param_6)) {
        FUN_00739820();
        iVar1 = *(int *)(in_ECX + 0xc);
        for (iVar5 = iVar1 + -0x24; iVar5 != iVar1; iVar5 = iVar5 + 0x24) {
          if (0xf < *(uint *)(iVar5 + 0x18)) {
            _free(*(void **)(iVar5 + 4));
            return;
          }
          *(undefined4 *)(iVar5 + 0x18) = 0xf;
          *(undefined4 *)(iVar5 + 0x14) = 0;
          *(undefined1 *)(iVar5 + 4) = 0;
        }
        *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + -0x24;
        if (0xf < local_18) {
          _free(local_2c[0]);
          return;
        }
        local_18 = 0xf;
        local_1c = 0;
        local_2c[0] = (byte ******)((uint)local_2c[0] & 0xffffff00);
        goto LAB_0073940b;
      }
    }
    else {
      uVar4 = param_6;
      if (local_1c < param_6) {
        uVar4 = local_1c;
      }
      ppppppbVar6 = local_2c[0];
      if (local_18 < 0x10) {
        ppppppbVar6 = (byte ******)local_2c;
      }
      bVar7 = false;
      iVar3 = 0;
      bVar8 = true;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        bVar7 = *(byte *)ppppppbVar6 < *pbVar2;
        bVar8 = *(byte *)ppppppbVar6 == *pbVar2;
        ppppppbVar6 = (byte ******)((int)ppppppbVar6 + 1);
        pbVar2 = pbVar2 + 1;
      } while (bVar8);
      if (!bVar8) {
        iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      }
      if (iVar3 == 0) goto LAB_00739240;
    }
    local_4 = 0;
    if (0xf < local_18) {
      _free(local_2c[0]);
      return;
    }
    iVar5 = iVar5 + 0x24;
    local_18 = 0xf;
    local_1c = 0;
    local_2c[0] = (byte ******)((uint)local_2c[0] & 0xffffff00);
  } while( true );
}


// ==== FUN_00739440 @ 0x00739440 ====

void FUN_00739440(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992359;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ef2a4;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  local_4 = 1;
  FUN_00733920();
  local_4._0_1_ = 2;
  in_ECX[0xd] = 0;
  in_ECX[0xc] = 0;
  FUN_00401740(&DAT_009ef1c2,0);
  FUN_00401740(&DAT_009ef1c3,0);
  *(undefined2 *)(in_ECX + 0x15) = 0;
  *(undefined2 *)((int)in_ECX + 0x56) = 0;
  *(undefined2 *)(in_ECX + 0x16) = 0;
  *(undefined2 *)((int)in_ECX + 0x5a) = 0;
  FUN_0073a120();
  pvVar1 = operator_new(0x23c);
  local_4 = CONCAT31(local_4._1_3_,3);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0089f540();
  }
  in_ECX[0x79] = uVar2;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5acac = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5acac = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00739530 @ 0x00739530 ====

void FUN_00739530(undefined1 param_1)

{
  int iVar1;
  int *in_ECX;
  void *unaff_ESI;
  uint unaff_retaddr;
  void *pvStack_28;
  undefined4 local_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099236b;
  pvStack_c = ExceptionList;
  local_18 = 0xf;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660(&param_1,0,0xffffffff);
  iVar1 = (**(code **)(*in_ECX + 0x24))();
  if (iVar1 == 0) {
    FUN_0073a9f0(&local_18);
  }
  if (unaff_retaddr < 0x10) {
    ExceptionList = pvStack_28;
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_007395c0 @ 0x007395c0 ====

void FUN_007395c0(undefined4 param_1)

{
  int in_ECX;
  
  switch(param_1) {
  case 1:
    FUN_0073abd0(*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),&LAB_00738110);
    return;
  case 2:
    FUN_0073abd0(*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),&LAB_00738140);
    return;
  case 3:
    FUN_0073abd0(*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),&LAB_00737fe0);
    return;
  case 4:
    FUN_0073abd0(*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),&LAB_00738000);
    return;
  case 5:
    FUN_0073abd0(*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),&LAB_00738020);
    return;
  case 6:
    FUN_0073abd0(*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),&LAB_00738040);
    return;
  case 7:
    FUN_0073abd0(*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),&LAB_00738060);
    return;
  case 8:
    FUN_0073abd0(*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),&LAB_00738080);
  }
  return;
}


// ==== FUN_007396c0 @ 0x007396c0 ====

void FUN_007396c0(void)

{
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009921d8;
  pvStack_c = ExceptionList;
  local_38 = 0xf;
  local_3c = 0;
  local_4c = 0;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_invalid_vector<T>_subscript_0099ca88,0x1b);
  local_4 = 0;
  FUN_00403770(local_50);
  local_34[0] = &PTR_FUN_0099ca80;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_34,&DAT_00a9c7c8);
}


// ==== FUN_00739730 @ 0x00739730 ====

void FUN_00739730(void)

{
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009921d8;
  pvStack_c = ExceptionList;
  local_38 = 0xf;
  local_3c = 0;
  local_4c = 0;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_vector<T>_too_long_0099c99c,0x12);
  local_4 = 0;
  FUN_00403770(local_50);
  local_34[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_34,&DAT_00a9c48c);
}


// ==== FUN_007397a0 @ 0x007397a0 ====

void FUN_007397a0(int param_1,int param_2)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992201;
  local_c = ExceptionList;
  local_4 = 0;
  if (param_1 != 0) {
    ExceptionList = &local_c;
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(param_2,0,0xffffffff);
    *(undefined1 *)(param_1 + 0x1c) = *(undefined1 *)(param_2 + 0x1c);
    *(undefined1 *)(param_1 + 0x1d) = *(undefined1 *)(param_2 + 0x1d);
    *(undefined1 *)(param_1 + 0x1e) = *(undefined1 *)(param_2 + 0x1e);
    *(undefined2 *)(param_1 + 0x20) = *(undefined2 *)(param_2 + 0x20);
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00739820 @ 0x00739820 ====

int FUN_00739820(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    FUN_00401660(param_1,0,0xffffffff);
    *(undefined1 *)(param_3 + 0x1c) = *(undefined1 *)(param_1 + 0x1c);
    *(undefined1 *)(param_3 + 0x1d) = *(undefined1 *)(param_1 + 0x1d);
    *(undefined1 *)(param_3 + 0x1e) = *(undefined1 *)(param_1 + 0x1e);
    *(undefined2 *)(param_3 + 0x20) = *(undefined2 *)(param_1 + 0x20);
    param_1 = param_1 + 0x24;
    param_3 = param_3 + 0x24;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_00739870 @ 0x00739870 ====

int FUN_00739870(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x24;
    iVar2 = param_3 + -0x24;
    FUN_00401660(iVar1,0,0xffffffff);
    *(undefined1 *)(param_3 + -8) = *(undefined1 *)(param_2 + -8);
    *(undefined1 *)(param_3 + -7) = *(undefined1 *)(param_2 + -7);
    *(undefined1 *)(param_3 + -6) = *(undefined1 *)(param_2 + -6);
    *(undefined2 *)(param_3 + -4) = *(undefined2 *)(param_2 + -4);
    param_2 = iVar1;
    param_3 = iVar2;
  } while (iVar1 != param_1);
  return iVar2;
}


// ==== FUN_007398c0 @ 0x007398c0 ====

int FUN_007398c0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00992380;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x24) {
    FUN_007397a0(param_3,param_1);
    param_3 = param_3 + 0x24;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0073990d @ 0x0073990d ====

void Catch_0073990d(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  iVar1 = *(int *)(unaff_EBP + 0x10);
  while( true ) {
    if (iVar2 == iVar1) {
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(0,0);
    }
    if (0xf < *(uint *)(iVar2 + 0x18)) break;
    *(undefined4 *)(iVar2 + 0x18) = 0xf;
    *(undefined4 *)(iVar2 + 0x14) = 0;
    *(undefined1 *)(iVar2 + 4) = 0;
    iVar2 = iVar2 + 0x24;
  }
  _free(*(void **)(iVar2 + 4));
  return;
}


// ==== FUN_00739960 @ 0x00739960 ====

void FUN_00739960(int param_1,int param_2)

{
  undefined1 local_30 [4];
  void *local_2c;
  undefined4 local_1c;
  uint local_18;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined2 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00992398;
  local_c = ExceptionList;
  local_18 = 0xf;
  local_1c = 0;
  local_2c = (void *)((uint)local_2c & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401660(param_1,0,0xffffffff);
  local_14 = *(undefined1 *)(param_1 + 0x1c);
  local_13 = *(undefined1 *)(param_1 + 0x1d);
  local_12 = *(undefined1 *)(param_1 + 0x1e);
  local_10 = *(undefined2 *)(param_1 + 0x20);
  local_4 = 0;
  FUN_00401660(param_2,0,0xffffffff);
  *(undefined1 *)(param_1 + 0x1c) = *(undefined1 *)(param_2 + 0x1c);
  *(undefined1 *)(param_1 + 0x1d) = *(undefined1 *)(param_2 + 0x1d);
  *(undefined1 *)(param_1 + 0x1e) = *(undefined1 *)(param_2 + 0x1e);
  *(undefined2 *)(param_1 + 0x20) = *(undefined2 *)(param_2 + 0x20);
  FUN_00401660(local_30,0,0xffffffff);
  *(undefined1 *)(param_2 + 0x1c) = local_14;
  *(undefined1 *)(param_2 + 0x1d) = local_13;
  *(undefined1 *)(param_2 + 0x1e) = local_12;
  *(undefined2 *)(param_2 + 0x20) = local_10;
  if (local_18 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_00739a50 @ 0x00739a50 ====

void FUN_00739a50(int param_1,int param_2,int param_3,undefined1 param_4,void *param_5)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  uint in_stack_00000028;
  undefined1 uStack0000002c;
  undefined1 uStack0000002d;
  undefined1 uStack0000002e;
  undefined2 in_stack_00000030;
  code *in_stack_00000034;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009923c8;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  if (param_3 < param_2) {
    ExceptionList = &pvStack_c;
    do {
      iVar4 = (param_2 + -1) / 2;
      iVar1 = param_1 + iVar4 * 0x24;
      cVar3 = (*in_stack_00000034)(iVar1,&param_4);
      if (cVar3 == '\0') break;
      iVar2 = param_1 + param_2 * 0x24;
      FUN_00401660(iVar1,0,0xffffffff);
      *(undefined1 *)(iVar2 + 0x1c) = *(undefined1 *)(iVar1 + 0x1c);
      *(undefined1 *)(iVar2 + 0x1d) = *(undefined1 *)(iVar1 + 0x1d);
      *(undefined1 *)(iVar2 + 0x1e) = *(undefined1 *)(iVar1 + 0x1e);
      *(undefined2 *)(iVar2 + 0x20) = *(undefined2 *)(iVar1 + 0x20);
      param_2 = iVar4;
    } while (param_3 < iVar4);
  }
  param_1 = param_1 + param_2 * 0x24;
  FUN_00401660(&param_4,0,0xffffffff);
  *(undefined1 *)(param_1 + 0x1c) = uStack0000002c;
  *(undefined1 *)(param_1 + 0x1d) = uStack0000002d;
  *(undefined1 *)(param_1 + 0x1e) = uStack0000002e;
  *(undefined2 *)(param_1 + 0x20) = in_stack_00000030;
  if (in_stack_00000028 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(param_5);
  return;
}


// ==== FUN_00739b50 @ 0x00739b50 ====

void FUN_00739b50(undefined1 *param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 **ppuVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int local_40;
  undefined1 *local_3c;
  undefined1 *local_38;
  undefined1 *local_34;
  undefined1 local_30 [4];
  void *local_2c;
  undefined4 local_1c;
  uint local_18;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined2 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992398;
  local_c = ExceptionList;
  iVar2 = ((int)param_3 - (int)param_1) / 0x24;
  iVar1 = (param_2 - (int)param_1) / 0x24;
  iVar5 = iVar1;
  local_40 = iVar2;
  while (iVar3 = iVar5, iVar3 != 0) {
    iVar5 = local_40 % iVar3;
    local_40 = iVar3;
  }
  if ((local_40 < iVar2) && (0 < local_40)) {
    param_2 = iVar1 * 0x24;
    puVar7 = param_1 + local_40 * 0x24 + 0x1d;
    ExceptionList = &local_c;
    do {
      iVar2 = param_2;
      local_4 = 0xffffffff;
      puVar9 = puVar7 + -0x1d;
      local_18 = 0xf;
      local_1c = 0;
      local_2c = (void *)((uint)local_2c & 0xffffff00);
      FUN_00401660(puVar7 + -0x1d,0,0xffffffff);
      local_14 = puVar7[-1];
      local_13 = *puVar7;
      local_12 = puVar7[1];
      local_10 = *(undefined2 *)(puVar7 + 3);
      local_4 = 0;
      if (puVar7 + iVar2 + -0x1d == param_3) {
        ppuVar6 = &param_1;
      }
      else {
        local_3c = puVar7 + iVar2 + -0x1d;
        ppuVar6 = &local_3c;
      }
      if (*ppuVar6 != puVar9) {
        puVar4 = *ppuVar6;
        puVar8 = puVar9;
        do {
          puVar9 = puVar4;
          FUN_00401660(puVar9,0,0xffffffff);
          puVar8[0x1c] = puVar9[0x1c];
          puVar8[0x1d] = puVar9[0x1d];
          puVar8[0x1e] = puVar9[0x1e];
          *(undefined2 *)(puVar8 + 0x20) = *(undefined2 *)(puVar9 + 0x20);
          iVar2 = ((int)param_3 - (int)puVar9) / 0x24;
          if (iVar1 < iVar2) {
            local_38 = puVar9 + param_2;
            ppuVar6 = &local_38;
          }
          else {
            local_34 = param_1 + (iVar1 - iVar2) * 0x24;
            ppuVar6 = &local_34;
          }
          puVar4 = *ppuVar6;
          puVar8 = puVar9;
        } while (*ppuVar6 != puVar7 + -0x1d);
      }
      FUN_00401660(local_30,0,0xffffffff);
      puVar9[0x1c] = local_14;
      puVar9[0x1d] = local_13;
      puVar9[0x1e] = local_12;
      *(undefined2 *)(puVar9 + 0x20) = local_10;
      local_4 = 0xffffffff;
      if (0xf < local_18) {
        _free(local_2c);
        return;
      }
      puVar7 = puVar7 + -0x24;
      local_40 = local_40 + -1;
      local_2c = (void *)((uint)local_2c & 0xffffff00);
    } while (local_40 != 0);
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00739d50 @ 0x00739d50 ====

void FUN_00739d50(int param_1,int param_2,int param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x24) {
    FUN_00401660(param_3,0,0xffffffff);
    *(undefined1 *)(param_1 + 0x1c) = *(undefined1 *)(param_3 + 0x1c);
    *(undefined1 *)(param_1 + 0x1d) = *(undefined1 *)(param_3 + 0x1d);
    *(undefined1 *)(param_1 + 0x1e) = *(undefined1 *)(param_3 + 0x1e);
    *(undefined2 *)(param_1 + 0x20) = *(undefined2 *)(param_3 + 0x20);
  }
  return;
}


// ==== FUN_00739da0 @ 0x00739da0 ====

void FUN_00739da0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009923b0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_007397a0(param_1,param_3);
    param_1 = param_1 + 0x24;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00739dec @ 0x00739dec ====

void Catch_00739dec(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  iVar1 = *(int *)(unaff_EBP + 8);
  while( true ) {
    if (iVar2 == iVar1) {
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(0,0);
    }
    if (0xf < *(uint *)(iVar2 + 0x18)) break;
    *(undefined4 *)(iVar2 + 0x18) = 0xf;
    *(undefined4 *)(iVar2 + 0x14) = 0;
    *(undefined1 *)(iVar2 + 4) = 0;
    iVar2 = iVar2 + 0x24;
  }
  _free(*(void **)(iVar2 + 4));
  return;
}


// ==== FUN_00739e40 @ 0x00739e40 ====

void FUN_00739e40(undefined4 param_1,undefined4 param_2,undefined4 param_3,code *param_4)

{
  char cVar1;
  
  cVar1 = (*param_4)(param_2,param_1);
  if (cVar1 != '\0') {
    FUN_00739960(param_2,param_1);
  }
  cVar1 = (*param_4)(param_3,param_2);
  if (cVar1 != '\0') {
    FUN_00739960(param_3,param_2);
  }
  cVar1 = (*param_4)(param_2,param_1);
  if (cVar1 != '\0') {
    FUN_00739960(param_2,param_1);
  }
  return;
}


// ==== FUN_00739ea0 @ 0x00739ea0 ====

void FUN_00739ea0(int param_1,int param_2,int param_3,undefined1 param_4,void *param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint in_stack_00000028;
  undefined1 in_stack_0000002c;
  undefined2 in_stack_00000030;
  code *in_stack_00000034;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009923c8;
  pvStack_c = ExceptionList;
  iVar3 = param_2 * 2 + 2;
  local_4 = 0;
  iVar4 = param_2;
  ExceptionList = &pvStack_c;
  if (iVar3 < param_3) {
    iVar2 = param_2;
    ExceptionList = &pvStack_c;
    do {
      cVar1 = (*in_stack_00000034)();
      iVar4 = iVar3;
      if (cVar1 != '\0') {
        iVar4 = iVar3 + -1;
      }
      iVar3 = param_1 + iVar4 * 0x24;
      iVar2 = param_1 + iVar2 * 0x24;
      FUN_00401660();
      *(undefined1 *)(iVar2 + 0x1c) = *(undefined1 *)(iVar3 + 0x1c);
      *(undefined1 *)(iVar2 + 0x1d) = *(undefined1 *)(iVar3 + 0x1d);
      *(undefined1 *)(iVar2 + 0x1e) = *(undefined1 *)(iVar3 + 0x1e);
      *(undefined2 *)(iVar2 + 0x20) = *(undefined2 *)(iVar3 + 0x20);
      iVar3 = iVar4 * 2 + 2;
      iVar2 = iVar4;
    } while (iVar3 < param_3);
  }
  if (iVar3 == param_3) {
    iVar3 = param_1 + -0x24 + param_3 * 0x24;
    iVar4 = param_1 + iVar4 * 0x24;
    FUN_00401660();
    *(undefined1 *)(iVar4 + 0x1c) = *(undefined1 *)(iVar3 + 0x1c);
    *(undefined1 *)(iVar4 + 0x1d) = *(undefined1 *)(iVar3 + 0x1d);
    *(undefined1 *)(iVar4 + 0x1e) = *(undefined1 *)(iVar3 + 0x1e);
    *(undefined2 *)(iVar4 + 0x20) = *(undefined2 *)(iVar3 + 0x20);
    iVar4 = param_3 + -1;
  }
  FUN_00401660(&param_4,0,0xffffffff);
  FUN_00739a50(param_1,iVar4,param_2);
  if (in_stack_00000028 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(param_5);
  return;
}


// ==== FUN_0073a000 @ 0x0073a000 ====

void FUN_0073a000(int param_1,int param_2,int param_3,undefined1 param_4,void *param_5)

{
  uint in_stack_00000028;
  undefined1 in_stack_0000002c;
  undefined2 in_stack_00000030;
  undefined4 in_stack_00000034;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009923c8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00401660();
  *(undefined1 *)(param_3 + 0x1c) = *(undefined1 *)(param_1 + 0x1c);
  *(undefined1 *)(param_3 + 0x1d) = *(undefined1 *)(param_1 + 0x1d);
  *(undefined1 *)(param_3 + 0x1e) = *(undefined1 *)(param_1 + 0x1e);
  *(undefined2 *)(param_3 + 0x20) = *(undefined2 *)(param_1 + 0x20);
  FUN_00401660(&param_4,0,0xffffffff);
  FUN_00739ea0(param_1,0,(param_2 - param_1) / 0x24);
  if (in_stack_00000028 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_5);
  return;
}


// ==== FUN_0073a0f0 @ 0x0073a0f0 ====

void FUN_0073a0f0(int param_1,int param_2)

{
  if (param_1 != param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  return;
}


// ==== FUN_0073a120 @ 0x0073a120 ====

void FUN_0073a120(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0073a170 @ 0x0073a170 ====

void FUN_0073a170(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (param_3 - param_1) / 0x24;
  if (iVar1 < 0x29) {
    FUN_00739e40(param_1,param_2,param_3,param_4);
    return;
  }
  iVar1 = iVar1 + 1;
  iVar2 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;
  iVar1 = iVar2 * 0x24 + param_1;
  FUN_00739e40(param_1,iVar1,iVar2 * 0x48 + param_1,param_4);
  FUN_00739e40(param_2 + iVar2 * -0x24,param_2,iVar2 * 0x24 + param_2,param_4);
  iVar3 = param_3 + iVar2 * -0x24;
  FUN_00739e40(param_3 + iVar2 * -0x48,iVar3,param_3,param_4);
  FUN_00739e40(iVar1,param_2,iVar3,param_4);
  return;
}


// ==== FUN_0073a230 @ 0x0073a230 ====

void FUN_0073a230(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (param_2 - param_1) / 0x24;
  iVar2 = iVar1 / 2;
  if (0 < iVar2) {
    iVar3 = param_1 + 0x1d + iVar2 * 0x24;
    do {
      iVar2 = iVar2 + -1;
      FUN_00401660(iVar3 + -0x41,0,0xffffffff);
      FUN_00739ea0(param_1,iVar2,iVar1);
      iVar3 = iVar3 + -0x24;
    } while (0 < iVar2);
  }
  return;
}


// ==== FUN_0073a2d0 @ 0x0073a2d0 ====

void FUN_0073a2d0(undefined4 param_1,int param_2)

{
  param_2 = param_2 + -0x24;
  FUN_00401660(param_2,0,0xffffffff);
  FUN_0073a000(param_1,param_2,param_2);
  return;
}


// ==== FUN_0073a330 @ 0x0073a330 ====

void FUN_0073a330(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0073a340 @ 0x0073a340 ====

int FUN_0073a340(int param_1,int param_2,undefined4 param_3)

{
  FUN_00739da0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x24;
}


// ==== FUN_0073a370 @ 0x0073a370 ====

void FUN_0073a370(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  undefined1 local_40 [2];
  undefined1 auStack_3e [2];
  void *local_3c;
  undefined4 local_2c;
  uint local_28;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined2 local_20;
  void *local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009923e8;
  local_10 = ExceptionList;
  local_14 = local_40 + -0xc;
  local_28 = 0xf;
  local_2c = 0;
  local_3c = (void *)((uint)local_3c & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3,0,0xffffffff);
  local_24 = *(undefined1 *)(param_3 + 0x1c);
  local_23 = *(undefined1 *)(param_3 + 0x1d);
  local_22 = *(undefined1 *)(param_3 + 0x1e);
  local_20 = *(undefined2 *)(param_3 + 0x20);
  iVar2 = *(int *)(in_ECX + 4);
  local_8 = 0;
  if (iVar2 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x24;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
    }
    if (0x71c71c7U - iVar1 < param_2) {
      FUN_00739730();
      uVar5 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x71c71c7 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_0066e7e0();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x24);
      local_8 = CONCAT31(local_8._1_3_,1);
      local_1c = pvVar3;
      iVar2 = FUN_007398c0(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_00739da0(iVar2,param_2,local_40);
      FUN_007398c0(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x24);
      iVar2 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x24;
      }
      if (*(int *)(in_ECX + 4) != 0) {
        FUN_0073a0f0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x24 + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar2) * 0x24);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      if ((uint)((iVar2 - param_1) / 0x24) < param_2) {
        FUN_007398c0(param_1,iVar2,param_2 * 0x24 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0073a340(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x24,local_40
                    );
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x24;
        local_8 = 0;
        FUN_00739d50(param_1,*(int *)(in_ECX + 8) + param_2 * -0x24,local_40);
      }
      else {
        iVar1 = iVar2 + param_2 * -0x24;
        uVar4 = FUN_007398c0(iVar1,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_00739870(param_1,iVar1,iVar2,iVar1);
        FUN_00739d50(param_1,param_2 * 0x24 + param_1,local_40);
      }
    }
  }
  if (local_28 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_3c);
  return;
}


// ==== Catch@0073a55b @ 0x0073a55b ====

void Catch_0073a55b(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_0073a0f0(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@0073a60c @ 0x0073a60c ====

void Catch_0073a60c(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x24;
  FUN_0073a0f0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0073a6a0 @ 0x0073a6a0 ====

void FUN_0073a6a0(uint *param_1,uint param_2,uint param_3,code *param_4)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uStack_4;
  
  uVar4 = param_2 + ((int)(param_3 - param_2) / 0x48) * 0x24;
  FUN_0073a170(param_2,uVar4,param_3 - 0x24,param_4);
  uVar1 = uVar4;
  while (uStack_4 = uVar1, param_2 < uStack_4) {
    uVar1 = uStack_4 - 0x24;
    cVar2 = (*param_4)(uVar1,uStack_4);
    if ((cVar2 != '\0') || (cVar2 = (*param_4)(uStack_4,uVar1), cVar2 != '\0')) break;
  }
  do {
    uVar4 = uVar4 + 0x24;
    uVar1 = uVar4;
    uVar5 = uStack_4;
    if (param_3 <= uVar4) break;
    cVar2 = (*param_4)(uVar4,uStack_4);
    if ((cVar2 != '\0') || (cVar2 = (*param_4)(uStack_4,uVar4), cVar2 != '\0')) break;
  } while( true );
joined_r0x0073a739:
  if (param_3 <= uVar1) {
LAB_0073a772:
    if (param_2 < uStack_4) {
      uVar3 = uStack_4;
      do {
        uVar3 = uVar3 - 0x24;
        cVar2 = (*param_4)(uVar3,uVar5);
        if (cVar2 == '\0') {
          cVar2 = (*param_4)(uVar5,uVar3);
          if (cVar2 != '\0') break;
          uVar5 = uVar5 - 0x24;
          FUN_00739960(uVar5,uVar3);
        }
        uStack_4 = uStack_4 - 0x24;
      } while (param_2 < uStack_4);
    }
    if (uStack_4 == param_2) {
      if (uVar1 == param_3) {
        *param_1 = uVar5;
        param_1[1] = uVar4;
        return;
      }
      if (uVar4 != uVar1) {
        FUN_00739960(uVar5,uVar4);
      }
      uVar4 = uVar4 + 0x24;
      FUN_00739960(uVar5,uVar1);
      uVar1 = uVar1 + 0x24;
      uVar5 = uVar5 + 0x24;
    }
    else {
      uStack_4 = uStack_4 - 0x24;
      if (uVar1 == param_3) {
        uVar5 = uVar5 - 0x24;
        if (uStack_4 != uVar5) {
          FUN_00739960(uStack_4,uVar5);
        }
        uVar4 = uVar4 - 0x24;
        FUN_00739960(uVar5,uVar4);
      }
      else {
        FUN_00739960(uVar1,uStack_4);
        uVar1 = uVar1 + 0x24;
      }
    }
    goto joined_r0x0073a739;
  }
  cVar2 = (*param_4)(uVar5,uVar1);
  uVar3 = uVar4;
  if (cVar2 == '\0') {
    cVar2 = (*param_4)(uVar1,uVar5);
    if (cVar2 != '\0') goto LAB_0073a772;
    uVar3 = uVar4 + 0x24;
    FUN_00739960(uVar4,uVar1);
  }
  uVar4 = uVar3;
  uVar1 = uVar1 + 0x24;
  goto joined_r0x0073a739;
}


// ==== FUN_0073a860 @ 0x0073a860 ====

void FUN_0073a860(int param_1,int param_2,code *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  
  iVar1 = param_1;
  if (param_1 != param_2) {
    while (iVar2 = iVar1, iVar1 = iVar2 + 0x24, iVar1 != param_2) {
      cVar4 = (*param_3)(iVar1,param_1);
      if (cVar4 == '\0') {
        cVar4 = (*param_3)(iVar1,iVar2);
        iVar3 = iVar2;
        if (cVar4 != '\0') {
          do {
            iVar5 = iVar3;
            cVar4 = (*param_3)(iVar1,iVar5 + -0x24);
            iVar3 = iVar5 + -0x24;
          } while (cVar4 != '\0');
          if ((iVar5 != iVar1) && (iVar1 != iVar2 + 0x48)) {
            FUN_00739b50(iVar5,iVar1,iVar2 + 0x48,0,0);
          }
        }
      }
      else if ((param_1 != iVar1) && (iVar1 != iVar2 + 0x48)) {
        FUN_00739b50(param_1,iVar1,iVar2 + 0x48,0,0);
      }
    }
  }
  return;
}


// ==== FUN_0073a900 @ 0x0073a900 ====

void FUN_0073a900(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x24 != 0) {
      iVar1 = (param_2 - iVar1) / 0x24;
      goto LAB_0073a945;
    }
  }
  iVar1 = 0;
LAB_0073a945:
  FUN_0073a370(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x24;
  return;
}


// ==== FUN_0073a970 @ 0x0073a970 ====

void FUN_0073a970(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = param_2 - param_1;
  while (1 < iVar1 / 0x24) {
    FUN_0073a2d0(param_1,param_2,param_3,0);
    param_2 = param_2 + -0x24;
    iVar1 = param_2 - param_1;
  }
  return;
}


// ==== FUN_0073a9d0 @ 0x0073a9d0 ====

void FUN_0073a9d0(byte param_1)

{
  void *in_ECX;
  
  FUN_007390e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073a9f0 @ 0x0073a9f0 ====

void FUN_0073a9f0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x24) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x24))) {
    FUN_0073a900(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00739da0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x24;
  return;
}


// ==== FUN_0073aa80 @ 0x0073aa80 ====

void FUN_0073aa80(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int local_8;
  int local_4;
  
  iVar1 = (param_2 - param_1) / 0x24;
  if (0x20 < iVar1) {
    do {
      if (param_3 < 1) {
        if (0x20 < iVar1) {
          if (1 < (param_2 - param_1) / 0x24) {
            FUN_0073a230(param_1,param_2,param_4,0,0);
          }
          FUN_0073a970(param_1,param_2,param_4);
          return;
        }
        break;
      }
      FUN_0073a6a0(&local_8,param_1,param_2,param_4);
      iVar1 = local_4;
      param_3 = param_3 / 2 + (param_3 / 2) / 2;
      if ((local_8 - param_1) / 0x24 < (param_2 - local_4) / 0x24) {
        FUN_0073aa80(param_1,local_8,param_3,param_4);
        param_1 = iVar1;
      }
      else {
        FUN_0073aa80(local_4,param_2,param_3,param_4);
        param_2 = local_8;
      }
      iVar1 = (param_2 - param_1) / 0x24;
    } while (0x20 < iVar1);
  }
  if (1 < iVar1) {
    FUN_0073a860(param_1,param_2,param_4);
  }
  return;
}


// ==== FUN_0073abd0 @ 0x0073abd0 ====

void FUN_0073abd0(int param_1,int param_2,undefined4 param_3)

{
  FUN_0073aa80(param_1,param_2,(param_2 - param_1) / 0x24,param_3);
  return;
}


// ==== FUN_0073ac10 @ 0x0073ac10 ====

void FUN_0073ac10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ef344;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073ac40 @ 0x0073ac40 ====

void FUN_0073ac40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ef350;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b104 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b104 = in_ECX;
  return;
}


// ==== FUN_0073ac70 @ 0x0073ac70 ====

void FUN_0073ac70(void)

{
  undefined4 uVar1;
  
  (**(code **)(*DAT_00b5af2c + 8))(0);
  uVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  FUN_00828650(uVar1);
  (**(code **)(*DAT_00b5b108 + 4))();
  return;
}


// ==== FUN_0073acb0 @ 0x0073acb0 ====

void FUN_0073acb0(void)

{
  undefined4 uVar1;
  
  (**(code **)(*DAT_00b5af2c + 8))(0);
  uVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  FUN_00828650(uVar1);
  (**(code **)(*DAT_00b5b108 + 0xc))();
  return;
}


// ==== FUN_0073ace0 @ 0x0073ace0 ====

void FUN_0073ace0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b104 = 0;
  *in_ECX = &PTR_FUN_009ef344;
  return;
}


// ==== FUN_0073ad00 @ 0x0073ad00 ====

void FUN_0073ad00(void)

{
  char cVar1;
  int unaff_retaddr;
  undefined1 auStack_70 [4];
  void *pvStack_6c;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined1 auStack_34 [36];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00992420;
  pvStack_c = ExceptionList;
  uStack_4c = 0;
  uStack_50 = 0x73ad27;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  cVar1 = *(char *)(unaff_retaddr + 0x10);
  if (cVar1 == '\0') {
    uStack_50 = 0x73ad3d;
    (**(code **)(*DAT_00b5b108 + 0x40))();
    ExceptionList = pvStack_10;
    return;
  }
  if (cVar1 == '\x01') {
    uStack_50 = 0x6e0043;
    uStack_54 = 0;
    uStack_58 = 0x73ad68;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_4c = uStack_4c & 0xffffff00;
    uStack_64 = 0x73ad85;
    FUN_00401660();
    puStack_8 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_10 = (void *)0x0;
    pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
    FUN_00401660(&uStack_50,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_58) {
      _free(pvStack_6c);
      return;
    }
  }
  else {
    if (cVar1 != '\x02') {
      if (cVar1 == '\x03') {
        uStack_50 = 0x6e0045;
        uStack_54 = 0;
        uStack_58 = 0x73ae84;
        uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_5c = 0x73ae8e;
        FUN_00765c50();
        puStack_8 = auStack_70;
        pvStack_10 = (void *)0x2;
        FUN_00765c50(&uStack_50);
        (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      }
      else {
        uStack_50 = 0x6e0046;
        uStack_54 = 0;
        uStack_58 = 0x73aec7;
        uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_5c = 0x73aed1;
        FUN_00765c50();
        puStack_8 = auStack_70;
        pvStack_10 = (void *)0x3;
        FUN_00765c50(auStack_34);
        (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      }
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    uStack_50 = 0x6e0044;
    uStack_54 = 0;
    uStack_58 = 0x73adf6;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_4c = uStack_4c & 0xffffff00;
    uStack_64 = 0x73ae13;
    FUN_00401660();
    puStack_8 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_10 = (void *)0x1;
    pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
    FUN_00401660(&uStack_50,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_58) {
      _free(pvStack_6c);
      return;
    }
  }
  ExceptionList = (void *)0xf;
  return;
}


// ==== FUN_0073af20 @ 0x0073af20 ====

void FUN_0073af20(void)

{
  char cVar1;
  int unaff_retaddr;
  undefined1 auStack_70 [4];
  void *pvStack_6c;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined1 auStack_34 [36];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00992452;
  pvStack_c = ExceptionList;
  uStack_4c = 0;
  uStack_50 = 0x73af47;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  cVar1 = *(char *)(unaff_retaddr + 0x10);
  if (cVar1 == '\0') {
    uStack_50 = 0x73af5d;
    (**(code **)(*DAT_00b5b108 + 0x40))();
    ExceptionList = pvStack_10;
    return;
  }
  if (cVar1 == '\x01') {
    uStack_50 = 0x6e0047;
    uStack_54 = 0;
    uStack_58 = 0x73af88;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_4c = uStack_4c & 0xffffff00;
    uStack_64 = 0x73afa5;
    FUN_00401660();
    puStack_8 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_10 = (void *)0x0;
    pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
    FUN_00401660(&uStack_50,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_58) {
      _free(pvStack_6c);
      return;
    }
  }
  else {
    if (cVar1 != '\x02') {
      if (cVar1 == '\x03') {
        uStack_50 = 0x6e0044;
        uStack_54 = 0;
        uStack_58 = 0x73b0a4;
        uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_5c = 0x73b0ae;
        FUN_00765c50();
        puStack_8 = auStack_70;
        pvStack_10 = (void *)0x2;
        FUN_00765c50(&uStack_50);
        (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      }
      else if (cVar1 == '\x04') {
        uStack_50 = 0x6e0045;
        uStack_54 = 0;
        uStack_58 = 0x73b0ee;
        uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_5c = 0x73b0f8;
        FUN_00765c50();
        puStack_8 = auStack_70;
        pvStack_10 = (void *)0x3;
        FUN_00765c50(&uStack_50);
        (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      }
      else {
        uStack_50 = 0x6e0046;
        uStack_54 = 0;
        uStack_58 = 0x73b131;
        uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_5c = 0x73b13b;
        FUN_00765c50();
        puStack_8 = auStack_70;
        pvStack_10 = (void *)0x4;
        FUN_00765c50(auStack_34);
        (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      }
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    uStack_50 = 0x6e0043;
    uStack_54 = 0;
    uStack_58 = 0x73b016;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_4c = uStack_4c & 0xffffff00;
    uStack_64 = 0x73b033;
    FUN_00401660();
    puStack_8 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_10 = (void *)0x1;
    pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
    FUN_00401660(&uStack_50,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_58) {
      _free(pvStack_6c);
      return;
    }
  }
  ExceptionList = (void *)0xf;
  return;
}


// ==== FUN_0073b180 @ 0x0073b180 ====

void FUN_0073b180(void)

{
  char cVar1;
  int unaff_retaddr;
  undefined1 auStack_74 [4];
  undefined1 uStack_70;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_50;
  void *pvStack_44;
  undefined1 auStack_34 [4];
  uint uStack_30;
  void *pvStack_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00992474;
  pvStack_c = ExceptionList;
  uStack_50 = 0;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  cVar1 = *(char *)(unaff_retaddr + 0x18);
  if (cVar1 == '\0') {
    (**(code **)(*DAT_00b5a980 + 8))();
    uStack_58 = 0x73b1c8;
    FUN_008286b0();
    (**(code **)(*DAT_00b5b108 + 4))();
    uStack_58 = 0;
    uStack_5c = 0x73b1e7;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    uStack_68 = 0x73b205;
    FUN_00401660();
    puStack_8 = auStack_74;
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_10 = (void *)0x0;
    uStack_70 = 0;
    FUN_00401660(&uStack_50,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_30) {
LAB_0073b333:
      uStack_58 = 0x73b339;
      _free(pvStack_44);
      return;
    }
  }
  else if (cVar1 == '\x01') {
    uStack_58 = 0;
    uStack_5c = 0x73b25e;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    uStack_68 = 0x73b27c;
    FUN_00401660();
    puStack_8 = auStack_74;
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_10 = (void *)0x1;
    uStack_70 = 0;
    FUN_00401660(&uStack_50,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_30) goto LAB_0073b333;
  }
  else if (cVar1 == '\x02') {
    uStack_58 = 0;
    uStack_5c = 0x73b2d6;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = uStack_30 & 0xffffff00;
    uStack_68 = 0x73b2f4;
    FUN_00401660();
    puStack_8 = auStack_74;
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_10 = (void *)0x2;
    uStack_70 = 0;
    FUN_00401660(auStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_14) {
      pvStack_44 = pvStack_28;
      goto LAB_0073b333;
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0073b350 @ 0x0073b350 ====

void FUN_0073b350(void)

{
  int unaff_retaddr;
  undefined1 auStack_70 [4];
  undefined1 uStack_6c;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  void *pvStack_44;
  undefined1 auStack_34 [4];
  uint uStack_30;
  void *pvStack_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099248e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  if (*(char *)(unaff_retaddr + 0x10) == '\0') {
    (**(code **)(*DAT_00b5a980 + 8))();
    uStack_54 = 0x73b397;
    FUN_00828790();
    (**(code **)(*DAT_00b5b108 + 4))();
    uStack_54 = 0;
    uStack_58 = 0x73b3b6;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_64 = 0x73b3d3;
    FUN_00401660();
    puStack_8 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_10 = (void *)0x0;
    uStack_6c = 0;
    FUN_00401660(auStack_34 + -0x1c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_30) {
LAB_0073b48d:
      uStack_54 = 0x73b493;
      _free(pvStack_44);
      return;
    }
  }
  else if (*(char *)(unaff_retaddr + 0x10) == '\x01') {
    uStack_54 = 0;
    uStack_58 = 0x73b42d;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = uStack_30 & 0xffffff00;
    uStack_64 = 0x73b44a;
    FUN_00401660();
    puStack_8 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_10 = (void *)0x1;
    uStack_6c = 0;
    FUN_00401660(auStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_14) {
      pvStack_44 = pvStack_28;
      goto LAB_0073b48d;
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0073b4b0 @ 0x0073b4b0 ====

void FUN_0073b4b0(void)

{
  int unaff_retaddr;
  undefined1 auStack_70 [4];
  undefined1 uStack_6c;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  void *pvStack_44;
  undefined1 auStack_34 [4];
  uint uStack_30;
  void *pvStack_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009924a8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  if (*(char *)(unaff_retaddr + 0x10) == '\0') {
    (**(code **)(*DAT_00b5a980 + 8))();
    uStack_54 = 0x73b4f7;
    FUN_00828850();
    (**(code **)(*DAT_00b5b108 + 4))();
    uStack_54 = 0;
    uStack_58 = 0x73b516;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_64 = 0x73b533;
    FUN_00401660();
    puStack_8 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_10 = (void *)0x0;
    uStack_6c = 0;
    FUN_00401660(auStack_34 + -0x1c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_30) {
LAB_0073b5ed:
      uStack_54 = 0x73b5f3;
      _free(pvStack_44);
      return;
    }
  }
  else if (*(char *)(unaff_retaddr + 0x10) == '\x01') {
    uStack_54 = 0;
    uStack_58 = 0x73b58d;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = uStack_30 & 0xffffff00;
    uStack_64 = 0x73b5aa;
    FUN_00401660();
    puStack_8 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_10 = (void *)0x1;
    uStack_6c = 0;
    FUN_00401660(auStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_14) {
      pvStack_44 = pvStack_28;
      goto LAB_0073b5ed;
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0073b610 @ 0x0073b610 ====

/* WARNING: Removing unreachable block (ram,0x0073b6a8) */

void FUN_0073b610(int param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  undefined2 extraout_var;
  undefined1 auStack_26 [18];
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009924ba;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x24) + 0x2c))(*(undefined1 *)(param_1 + 0x12));
  if (piVar3 == (int *)0x0) {
    FUN_00401740(s_FALSE_009ef334,5);
    puStack_8 = (undefined1 *)0x0;
    FUN_00406880(auStack_26 + -6);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  (**(code **)(*piVar3 + 0x28))(CONCAT22(extraout_var,*(undefined2 *)(param_1 + 0x10)));
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_0073b6d0 @ 0x0073b6d0 ====

undefined4 FUN_0073b6d0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  switch(iVar1 + -0x51b0001) {
  case 0:
    FUN_0073ac70(*(undefined4 *)(param_1 + 0xc));
    return 1;
  default:
    return 0;
  case 2:
    FUN_0073ad00(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 4:
    FUN_0073af20(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 6:
    FUN_0073b180(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 8:
    FUN_0073b350(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 10:
    FUN_0073b4b0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0xb:
    FUN_0073b610(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0xc:
    (**(code **)(*DAT_00b5b108 + 8))();
    return 1;
  case 0xe:
    FUN_0073acb0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
}


// ==== FUN_0073b7e0 @ 0x0073b7e0 ====

undefined4 FUN_0073b7e0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_0073b6d0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0073b810 @ 0x0073b810 ====

void FUN_0073b810(byte param_1)

{
  void *in_ECX;
  
  FUN_0073ace0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073b830 @ 0x0073b830 ====

void FUN_0073b830(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ef3d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073b850 @ 0x0073b850 ====

undefined1 FUN_0073b850(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_0073b890 @ 0x0073b890 ====

void FUN_0073b890(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ef45c;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b108 = (undefined4 *)0x0;
    DAT_00000000 = 0;
    return;
  }
  DAT_00b5b108 = in_ECX;
  *(undefined1 *)(in_ECX + 1) = 0;
  return;
}


// ==== FUN_0073b8c0 @ 0x0073b8c0 ====

void FUN_0073b8c0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ef444;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0073b8f0 @ 0x0073b8f0 ====

void FUN_0073b8f0(void)

{
  char cVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar2 = operator_new(4);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009ef41c;
  }
  FUN_00797a20(puVar2);
  *(undefined1 *)(in_ECX + 4) = 1;
  cVar1 = (**(code **)(*DAT_00b5a78c + 0x5c))();
  if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5a78c + 0x24))();
  }
  (**(code **)(*DAT_00b5a78c + 0x60))(5);
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  return;
}


// ==== FUN_0073b950 @ 0x0073b950 ====

void FUN_0073b950(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009ef430;
  }
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 4) = 0;
  (**(code **)(*DAT_00b5a78c + 0x60))(0);
  return;
}


// ==== FUN_0073b990 @ 0x0073b990 ====

void FUN_0073b990(void)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  FUN_00828910(uVar1);
  return;
}


// ==== FUN_0073b9b0 @ 0x0073b9b0 ====

void FUN_0073b9b0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b108 = 0;
  *in_ECX = &PTR_FUN_009ef3d4;
  return;
}


// ==== FUN_0073b9d0 @ 0x0073b9d0 ====

void FUN_0073b9d0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x51b0000;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(0);
  }
  return;
}


// ==== FUN_0073ba30 @ 0x0073ba30 ====

void FUN_0073ba30(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  int *in_ECX;
  undefined1 unaff_BL;
  uint unaff_retaddr;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
    iVar2 = (**(code **)(**(int **)(iVar2 + 0x24) + 0x2c))(unaff_retaddr & 0xff);
    cVar1 = (**(code **)(*in_ECX + 0x44))(iVar2,unaff_retaddr);
    if (cVar1 != '\0') {
      in_ECX[2] = iVar2;
      *(char *)(in_ECX + 3) = (char)unaff_retaddr;
      uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar4 = operator_new(0x400);
      *(undefined4 *)((int)pvVar4 + 8) = uVar3;
      *(undefined4 *)((int)pvVar4 + 0xc) = 0x51b0002;
      *(undefined2 *)((int)pvVar4 + 6) = 0x14;
      iVar2 = FUN_004244d0();
      *(undefined1 *)(iVar2 + 0x10) = unaff_BL;
      *(bool *)(iVar2 + 0x11) = (char)unaff_retaddr == '\x01';
      FUN_004d8570(iVar2);
      (**(code **)(*DAT_00b5af2c + 4))(0);
    }
  }
  return;
}


// ==== FUN_0073bae0 @ 0x0073bae0 ====

void FUN_0073bae0(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  int *in_ECX;
  undefined4 unaff_EBX;
  undefined1 uStack00000000;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
    iVar2 = (**(code **)(**(int **)(iVar2 + 0x20) + 0x28))(&uStack00000000);
    cVar1 = (**(code **)(*in_ECX + 0x44))(iVar2,_uStack00000000);
    if (cVar1 != '\0') {
      in_ECX[2] = iVar2;
      *(char *)(in_ECX + 3) = (char)_uStack00000000;
      uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar4 = operator_new(0x400);
      *(undefined4 *)((int)pvVar4 + 8) = uVar3;
      *(undefined4 *)((int)pvVar4 + 0xc) = 0x51b0004;
      *(undefined2 *)((int)pvVar4 + 6) = 0x14;
      iVar2 = FUN_004244d0();
      *(short *)(iVar2 + 0x10) = (short)unaff_EBX;
      *(char *)(iVar2 + 0x12) = (char)((uint)unaff_EBX >> 0x10);
      *(bool *)(iVar2 + 0x13) = (char)_uStack00000000 == '\x01';
      FUN_004d8570(iVar2);
      (**(code **)(*DAT_00b5af2c + 4))(0);
    }
  }
  return;
}


// ==== FUN_0073bba0 @ 0x0073bba0 ====

void FUN_0073bba0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x51b0006;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(0);
  }
  return;
}


// ==== FUN_0073bc00 @ 0x0073bc00 ====

void FUN_0073bc00(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x51b0008;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(0);
  }
  return;
}


// ==== FUN_0073bc60 @ 0x0073bc60 ====

void FUN_0073bc60(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x51b000a;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(0);
  }
  return;
}


// ==== FUN_0073bcc0 @ 0x0073bcc0 ====

void FUN_0073bcc0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x51b000e;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(0);
  }
  return;
}


// ==== FUN_0073bd20 @ 0x0073bd20 ====

void FUN_0073bd20(void)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int *in_ECX;
  uint unaff_EBP;
  undefined4 uStack_4c;
  undefined1 uStack_48;
  uint auStack_38 [2];
  undefined1 auStack_30 [4];
  uint uStack_2c;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009924f0;
  local_c = ExceptionList;
  piVar1 = (int *)in_ECX[2];
  if (piVar1 != (int *)0x0) {
    ExceptionList = &local_c;
    iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
    piVar2 = *(int **)(iVar4 + 0x38);
    cVar3 = (**(code **)(*piVar1 + 100))();
    if (cVar3 == '\x01') {
      if ((char)in_ECX[3] == '\x01') {
        (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_18 = 0xf;
        uStack_1c = 0;
        uStack_2c = uStack_2c & 0xffffff00;
        FUN_00401660();
        local_c = (void *)0x0;
        FUN_00401660(auStack_30);
        (**(code **)(*DAT_00b5ad0c + 0x28))();
        uStack_2c = 0xffffffff;
        if (0xf < auStack_38[0]) {
          _free(uStack_4c);
          return;
        }
      }
      else {
        uStack_4c = (void *)((uint)uStack_4c._3_1_ << 0x18);
        cVar3 = (**(code **)(*piVar2 + 0x14))();
        if (cVar3 != '\x01') {
          (**(code **)(*DAT_00b5a794 + 0xc))();
          FUN_00765c50();
          uStack_14 = 1;
LAB_0073be51:
          FUN_00765c50(auStack_38);
          (**(code **)(*DAT_00b5ad0c + 0x28))(2);
          auStack_38[1] = 0xffffffff;
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        (**(code **)(*piVar2 + 0x1c))();
        (**(code **)(*piVar1 + 0x60))();
      }
    }
    else if ((char)in_ECX[3] == '\x01') {
      uStack_4c = (void *)((uint)uStack_4c._3_1_ << 0x18);
      cVar3 = (**(code **)(*piVar2 + 0x2c))();
      if (cVar3 != '\x01') {
        (**(code **)(*DAT_00b5a794 + 0xc))();
        FUN_00765c50();
        uStack_14 = 2;
        goto LAB_0073be51;
      }
      (**(code **)(*piVar2 + 0x18))();
      (**(code **)(*piVar1 + 0x60))();
    }
    else {
      (**(code **)(*DAT_00b5a794 + 0xc))();
      auStack_38[1] = 0xf;
      auStack_38[0] = 0;
      uStack_48 = 0;
      FUN_00401660();
      local_c = (void *)0x3;
      FUN_00401660(&uStack_4c);
      (**(code **)(*DAT_00b5ad0c + 0x28))();
      uStack_2c = 0xffffffff;
      if (0xf < unaff_EBP) {
        _free((void *)0xf);
        return;
      }
    }
    in_ECX[2] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    (**(code **)(*in_ECX + 4))();
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0073bfa0 @ 0x0073bfa0 ====

undefined4 FUN_0073bfa0(int *param_1,char param_2)

{
  char cVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined1 uStack00000009;
  undefined1 uStack0000000a;
  undefined1 auStack_54 [4];
  undefined1 uStack_50;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  void *pvStack_24;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00992502;
  pvStack_c = ExceptionList;
  if (param_2 == '\x01') {
    ExceptionList = &pvStack_c;
    cVar1 = (**(code **)(*param_1 + 100))();
    if (cVar1 != '\x01') {
      iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
      uStack00000009 = 0;
      uStack0000000a = 0;
      uStack_38 = param_1;
      uStack_3c = 0x73bfff;
      cVar1 = (**(code **)(**(int **)(iVar2 + 0x38) + 0x2c))();
      if (cVar1 != '\0') {
        ExceptionList = pvStack_c;
        return 1;
      }
      uStack_38 = (int *)0x0;
      uStack_3c = 0x73c018;
      uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_3c = 0xffffffff;
      uStack_40 = 0;
      uStack_48 = 0x73c036;
      FUN_00401660();
      puStack_4 = auStack_54;
      uStack_3c = 0xf;
      uStack_40 = 0;
      pvStack_c = (void *)0x0;
      uStack_50 = 0;
      FUN_00401660(auStack_54 + 0x24,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      if (0xf < uStack_10) {
        uStack_38 = (int *)0x73c077;
        _free(pvStack_24);
        return extraout_EAX;
      }
    }
  }
  else {
    ExceptionList = &pvStack_c;
    cVar1 = (**(code **)(*param_1 + 100))();
    if (cVar1 != '\0') {
      ExceptionList = pvStack_c;
      return 1;
    }
  }
  ExceptionList = pvStack_c;
  return 0;
}


// ==== FUN_0073c0c0 @ 0x0073c0c0 ====

int * FUN_0073c0c0(int *param_1)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int *extraout_EAX;
  int *piVar4;
  undefined4 uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00992514;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar4 = *(int **)(iVar3 + 0x38);
  uStack_2c = (uint)uStack_2c._3_1_ << 0x18;
  iVar3 = (**(code **)(*piVar4 + 0x24))();
  if ((iVar3 == 0) || (cVar2 = (**(code **)(*piVar4 + 0x14))(iVar3,&uStack_2c), cVar2 != '\0')) {
    *param_1 = iVar3;
    param_1[1] = uStack_2c;
    ExceptionList = pvStack_c;
    return param_1;
  }
  FUN_00401830(s_FALSE_009ef394);
  uStack_4 = 0;
  FUN_00406880(auStack_28);
  if (uStack_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    piVar4 = (int *)(*pcVar1)();
    return piVar4;
  }
  _free(pvStack_24);
  return extraout_EAX;
}


// ==== FUN_0073c170 @ 0x0073c170 ====

int * FUN_0073c170(int *param_1)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int *extraout_EAX;
  int *piVar4;
  undefined4 uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00992526;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar4 = *(int **)(iVar3 + 0x38);
  uStack_2c = (uint)uStack_2c._3_1_ << 0x18;
  iVar3 = (**(code **)(*piVar4 + 0x28))();
  if ((iVar3 == 0) || (cVar2 = (**(code **)(*piVar4 + 0x14))(iVar3,&uStack_2c), cVar2 != '\0')) {
    *param_1 = iVar3;
    param_1[1] = uStack_2c;
    ExceptionList = pvStack_c;
    return param_1;
  }
  FUN_00401830(s_FALSE_009ef39c);
  uStack_4 = 0;
  FUN_00406880(auStack_28);
  if (uStack_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    piVar4 = (int *)(*pcVar1)();
    return piVar4;
  }
  _free(pvStack_24);
  return extraout_EAX;
}


// ==== FUN_0073c220 @ 0x0073c220 ====

void FUN_0073c220(undefined1 param_1)

{
  int *piVar1;
  int *piVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  undefined4 unaff_EBX;
  undefined3 unaff_ESI;
  undefined1 auStack_4e [2];
  int *piStack_4c;
  undefined1 local_48 [4];
  void *pvStack_44;
  undefined4 uStack_34;
  void *pvStack_30;
  void *pvStack_20;
  uint uStack_1c;
  void *pvStack_18;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00992540;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar5 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar1 = *(int **)(iVar5 + 0x24);
  piVar2 = *(int **)(iVar5 + 0x20);
  iVar5 = (**(code **)(**(int **)(iVar5 + 0x38) + 0x20))(&param_1);
  if (iVar5 == 0) {
    pvStack_30 = (void *)0xf;
    uStack_34 = 0;
    pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
    FUN_00401740(s_pItem____NULL_009ef3a4,0xd);
    puStack_8 = (undefined1 *)0x0;
    FUN_00406880(local_48);
    puStack_8 = (undefined1 *)0xffffffff;
    if (pvStack_30 < 0x10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    _free(pvStack_44);
    return;
  }
  bVar7 = 0;
  do {
    iVar6 = (**(code **)(*piVar1 + 0x2c))(bVar7);
    if (iVar5 == iVar6) {
      (**(code **)(*piStack_4c + 0x18))(bVar7,0);
      ExceptionList = pvStack_18;
      return;
    }
    bVar7 = bVar7 + 1;
  } while (bVar7 < 0x15);
  bVar7 = (byte)((uint)unaff_EBX >> 0x18);
  cVar4 = (**(code **)(*piVar2 + 0x18))(iVar5,auStack_4e + -6);
  if (cVar4 == '\x01') {
    (**(code **)(*(int *)((uint)bVar7 << 0x18) + 0x1c))(CONCAT13(bVar7,unaff_ESI),0);
    ExceptionList = pvStack_20;
    return;
  }
  uStack_1c = 0xf;
  pvStack_20 = (void *)0x0;
  pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
  FUN_00401740(s_FALSE_009ef3b4,5);
  uStack_10 = 1;
  FUN_00406880(&uStack_34);
  if (uStack_1c < 0x10) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  _free(pvStack_30);
  return;
}


// ==== FUN_0073c3c0 @ 0x0073c3c0 ====

undefined4 FUN_0073c3c0(void)

{
  return 0x70310000;
}


// ==== FUN_0073c3d0 @ 0x0073c3d0 ====

undefined4 FUN_0073c3d0(void)

{
  return 0x70310001;
}


// ==== FUN_0073c3e0 @ 0x0073c3e0 ====

undefined4 FUN_0073c3e0(void)

{
  return 0x70310002;
}


// ==== FUN_0073c3f0 @ 0x0073c3f0 ====

void FUN_0073c3f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0073b9b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073c410 @ 0x0073c410 ====

void FUN_0073c410(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ef4e8;
  return;
}


// ==== FUN_0073c420 @ 0x0073c420 ====

void FUN_0073c420(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ef4e8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073c440 @ 0x0073c440 ====

int FUN_0073c440(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) >> 3;
}


// ==== FUN_0073c460 @ 0x0073c460 ====

void FUN_0073c460(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ef4f8;
  DAT_00b5b10c = 0;
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_009ef4e8;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0073c4a0 @ 0x0073c4a0 ====

int FUN_0073c4a0(uint param_1)

{
  int in_ECX;
  int extraout_EDX;
  int iVar1;
  uint unaff_ESI;
  
  iVar1 = *(int *)(in_ECX + 8);
  if ((iVar1 == 0) || (unaff_ESI = param_1, (uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 3) <= param_1))
  {
    FUN_0073c530();
    iVar1 = extraout_EDX;
    param_1 = unaff_ESI;
  }
  return iVar1 + param_1 * 8;
}


// ==== FUN_0073c4d0 @ 0x0073c4d0 ====

void FUN_0073c4d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ef4f8;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b10c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b10c = in_ECX;
  return;
}


// ==== FUN_0073c530 @ 0x0073c530 ====

void FUN_0073c530(void)

{
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00992558;
  pvStack_c = ExceptionList;
  local_38 = 0xf;
  local_3c = 0;
  local_4c = 0;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_invalid_vector<T>_subscript_0099ca88,0x1b);
  local_4 = 0;
  FUN_00403770(local_50);
  local_34[0] = &PTR_FUN_0099ca80;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_34,&DAT_00a9c7c8);
}


// ==== FUN_0073c5a0 @ 0x0073c5a0 ====

void FUN_0073c5a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0073c460();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073c5c0 @ 0x0073c5c0 ====

void FUN_0073c5c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ef58c;
  return;
}


// ==== FUN_0073c5d0 @ 0x0073c5d0 ====

void FUN_0073c5d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ef58c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073c5f0 @ 0x0073c5f0 ====

void FUN_0073c5f0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0073c5f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_0073c600 @ 0x0073c600 ====

void FUN_0073c600(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_0073c610 @ 0x0073c610 ====

void FUN_0073c610(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  if (iVar1 == 2) {
                    /* WARNING: Could not recover jumptable at 0x0073c626. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
    return;
  }
  return;
}


// ==== FUN_0073c630 @ 0x0073c630 ====

void FUN_0073c630(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0073c635. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x18))();
  return;
}


// ==== FUN_0073c640 @ 0x0073c640 ====

void FUN_0073c640(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0073c645. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x1c))();
  return;
}


// ==== FUN_0073c650 @ 0x0073c650 ====

void FUN_0073c650(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0073c655. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x20))();
  return;
}


// ==== FUN_0073c660 @ 0x0073c660 ====

void FUN_0073c660(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0073c665. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x24))();
  return;
}


// ==== FUN_0073c670 @ 0x0073c670 ====

void FUN_0073c670(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0073c675. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x28))();
  return;
}


// ==== FUN_0073c680 @ 0x0073c680 ====

void FUN_0073c680(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0073c685. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
  return;
}


// ==== FUN_0073c690 @ 0x0073c690 ====

void FUN_0073c690(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0073c695. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x30))();
  return;
}


// ==== FUN_0073c6a0 @ 0x0073c6a0 ====

void FUN_0073c6a0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0073c6a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  return;
}


// ==== FUN_0073c6b0 @ 0x0073c6b0 ====

void FUN_0073c6b0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_0073c6c0 @ 0x0073c6c0 ====

undefined1 FUN_0073c6c0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 8);
}


// ==== FUN_0073c6d0 @ 0x0073c6d0 ====

void FUN_0073c6d0(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5a97c + 8))();
  if (iVar1 == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0073c6e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ac28 + 0x40))();
  return;
}


// ==== FUN_0073c6f0 @ 0x0073c6f0 ====

void FUN_0073c6f0(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5a97c + 8))();
  if (iVar1 == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0073c707. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ac28 + 0x44))();
  return;
}


// ==== FUN_0073c710 @ 0x0073c710 ====

void FUN_0073c710(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009ef5e0;
  }
  FUN_00797a20(puVar1);
  *(undefined4 *)(in_ECX + 4) = DAT_00b5b1b8;
  (**(code **)(*DAT_00b5a78c + 0x60))(0);
  return;
}


// ==== FUN_0073c750 @ 0x0073c750 ====

void FUN_0073c750(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ef5f4;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0073c780 @ 0x0073c780 ====

void FUN_0073c780(void)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x51a000e;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return;
}


// ==== FUN_0073c7c0 @ 0x0073c7c0 ====

undefined4 FUN_0073c7c0(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_auction_009ef560,0xc);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0x10))();
    return 1;
  }
  return 0;
}


// ==== FUN_0073c800 @ 0x0073c800 ====

undefined4 FUN_0073c800(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x38))(param_1);
  return param_1;
}


// ==== FUN_0073c820 @ 0x0073c820 ====

void FUN_0073c820(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  undefined1 auStack_58 [4];
  undefined1 uStack_54;
  void *pvStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  void *pvStack_38;
  undefined4 uStack_34;
  undefined4 uStack_28;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00992598;
  pvStack_c = ExceptionList;
  uStack_34 = 0x73c847;
  ExceptionList = &pvStack_c;
  uStack_34 = (**(code **)(*DAT_00b5ae14 + 0x18))();
  pvStack_38 = (void *)0x73c853;
  cVar1 = (**(code **)(*DAT_00b5add0 + 0x3c))();
  if (cVar1 == '\x01') {
    pvStack_38 = (void *)0x73c866;
    cVar1 = (**(code **)(*DAT_00b5ac98 + 0x44))();
    if (cVar1 == '\0') {
      pvStack_38 = (void *)0x320003d;
      uStack_3c = 0;
      uStack_40 = 0x73c881;
      uStack_48 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_40 = 0xffffffff;
      uStack_44 = 0;
      uStack_4c = 0x73c89f;
      FUN_00401660();
      puStack_8 = auStack_58;
      uStack_40 = 0xf;
      uStack_44 = 0;
      uStack_54 = 0;
      FUN_00401660(&uStack_34,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(0xc);
      if (uStack_3c < 0x10) {
        ExceptionList = pvStack_38;
        return;
      }
      _free(pvStack_50);
      return;
    }
  }
  pvStack_38 = (void *)0x73c8fe;
  iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  if (iVar2 == 0) {
    (**(code **)(**(int **)(in_ECX + 4) + 0xc))(uStack_28);
  }
  ExceptionList = pvStack_38;
  return;
}


// ==== FUN_0073c930 @ 0x0073c930 ====

void FUN_0073c930(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  void *unaff_ESI;
  undefined1 auStack_78 [4];
  undefined1 uStack_74;
  void *pvStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  uint uStack_3c;
  void *pvStack_38;
  undefined1 auStack_34 [4];
  undefined1 uStack_30;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009925b2;
  pvStack_c = ExceptionList;
  uStack_54 = (undefined1 *)0x73c957;
  ExceptionList = &pvStack_c;
  uStack_54 = (undefined1 *)(**(code **)(*DAT_00b5ae14 + 0x18))();
  uStack_58 = 0x73c963;
  cVar1 = (**(code **)(*DAT_00b5add0 + 0x3c))();
  if (cVar1 == '\x01') {
    uStack_58 = 0x73c976;
    cVar1 = (**(code **)(*DAT_00b5ac98 + 0x44))();
    if (cVar1 == '\0') {
      uStack_58 = 0x320003d;
      uStack_5c = 0;
      uStack_60 = 0x73c991;
      uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_60 = 0xffffffff;
      uStack_64 = 0;
      pvStack_6c = (void *)0x73c9af;
      FUN_00401660();
      uStack_54 = auStack_78;
      uStack_60 = 0xf;
      uStack_64 = 0;
      uStack_10 = 0;
      uStack_74 = 0;
      FUN_00401660(auStack_34 + -0x1c,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(0xc);
      if (uStack_58 < 0x10) {
        ExceptionList = (void *)0xf;
        return;
      }
      _free(pvStack_6c);
      return;
    }
  }
  uStack_58 = 0x73ca13;
  iVar2 = (**(code **)(*DAT_00b5ad88 + 4))();
  if (iVar2 == 0) {
    uStack_58 = 0x73caad;
    iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
    if (iVar2 == 0) {
      (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
    }
  }
  else {
    uStack_58 = 0x7d50011;
    uStack_5c = 0;
    uStack_60 = 0x73ca2e;
    uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_60 = 0xffffffff;
    uStack_64 = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = 0;
    pvStack_6c = (void *)0x73ca4c;
    FUN_00401660();
    uStack_54 = auStack_78;
    uStack_60 = 0xf;
    uStack_64 = 0;
    uStack_10 = 1;
    uStack_74 = 0;
    FUN_00401660(auStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_3c) {
      _free(unaff_ESI);
      return;
    }
  }
  ExceptionList = pvStack_38;
  return;
}


// ==== FUN_0073cad0 @ 0x0073cad0 ====

void FUN_0073cad0(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  undefined1 auStack_78 [4];
  undefined1 uStack_74;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 auStack_42 [2];
  void *pvStack_40;
  undefined1 auStack_30 [4];
  uint uStack_2c;
  void *pvStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  void *pvStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_009925d4;
  pvStack_c = ExceptionList;
  cVar1 = *(char *)(param_1 + 0x14);
  if (cVar1 == '\x01') {
    uStack_5c = 0;
    uStack_60 = 0x73cc61;
    ExceptionList = &pvStack_c;
    uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_60 = 0xffffffff;
    uStack_64 = 0;
    uStack_18 = 0xf;
    uStack_1c = 0;
    uStack_2c = uStack_2c & 0xffffff00;
    uStack_6c = 0x73cc7f;
    FUN_00401660();
    pvStack_c = (void *)0x0;
  }
  else {
    if (cVar1 != '\x02') {
      if (cVar1 != '\x03') {
        ExceptionList = &pvStack_c;
        iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
        if (iVar2 == 0) {
          ExceptionList = pvStack_c;
          return;
        }
        if (*(int **)(iVar2 + 0x34) == (int *)0x0) {
          ExceptionList = pvStack_c;
          return;
        }
        piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x34) + 0x3c))();
        if (piVar3 == (int *)0x0) {
          ExceptionList = pvStack_c;
          return;
        }
        if (*(int **)(iVar2 + 0x20) == (int *)0x0) {
          ExceptionList = pvStack_c;
          return;
        }
        piVar4 = (int *)(**(code **)(**(int **)(iVar2 + 0x20) + 0x54))();
        if (piVar4 == (int *)0x0) {
          ExceptionList = pvStack_c;
          return;
        }
        uStack_5c = 0x73cb69;
        (**(code **)(*piVar4 + 8))();
        uStack_5c = 0;
        uStack_60 = 0x73cb71;
        (**(code **)(*piVar3 + 8))();
        uStack_60 = 0x73cb79;
        (**(code **)(*in_ECX + 0x4c))();
        uStack_60 = 0x73cb84;
        (**(code **)(*DAT_00b5a790 + 4))();
        ExceptionList = pvStack_14;
        return;
      }
      uStack_5c = 0;
      uStack_60 = 0x73cbac;
      ExceptionList = &pvStack_c;
      uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_60 = 0xffffffff;
      uStack_64 = 0;
      uStack_6c = 0x73cbca;
      FUN_00401660();
      puStack_4 = auStack_78;
      uStack_60 = 0xf;
      uStack_64 = 0;
      pvStack_c = (void *)0x2;
      uStack_74 = 0;
      FUN_00401660(auStack_42 + -10,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(0xc);
      if (uStack_2c < 0x10) {
        ExceptionList = pvStack_c;
        return;
      }
      goto LAB_0073ccbb;
    }
    uStack_5c = 0;
    uStack_60 = 0x73cc26;
    ExceptionList = &pvStack_c;
    uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_60 = 0xffffffff;
    uStack_64 = 0;
    uStack_18 = 0xf;
    uStack_1c = 0;
    uStack_2c = uStack_2c & 0xffffff00;
    uStack_6c = 0x73cc44;
    FUN_00401660();
    pvStack_c = (void *)0x1;
  }
  puStack_4 = auStack_78;
  uStack_64 = 0;
  uStack_60 = 0xf;
  uStack_74 = 0;
  FUN_00401660(auStack_30,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(0xc);
  if (uStack_10 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  pvStack_40 = pvStack_24;
LAB_0073ccbb:
  uStack_5c = 0x73ccc0;
  _free(pvStack_40);
  return;
}


// ==== FUN_0073cce0 @ 0x0073cce0 ====

void FUN_0073cce0(void)

{
  void *pvVar1;
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  undefined1 local_24;
  uint uStack_18;
  void *local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0099261a;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ef60c;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5adc4 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5adc4 = in_ECX;
  }
  pvVar1 = operator_new(8);
  local_4._0_1_ = 1;
  if (pvVar1 != (void *)0x0) {
    FUN_0078cae0(in_ECX);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  pvVar1 = operator_new(0x10);
  local_4._0_1_ = 2;
  if (pvVar1 != (void *)0x0) {
    FUN_0078b730(in_ECX);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  pvVar1 = operator_new(0x28);
  local_4._0_1_ = 3;
  if (pvVar1 != (void *)0x0) {
    FUN_0078b070(in_ECX);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  pvVar1 = operator_new(0x2c);
  local_4._0_1_ = 4;
  if (pvVar1 != (void *)0x0) {
    FUN_0078a6e0(in_ECX);
  }
  in_ECX[1] = DAT_00b5b1b8;
  local_4 = (uint)local_4._1_3_ << 8;
  *(undefined1 *)(in_ECX + 2) = 0;
  local_10 = 0xf;
  local_14 = (void *)0x0;
  local_24 = 0;
  FUN_00401740(s_show_auction_009ef540,0xc);
  local_4 = CONCAT31(local_4._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(local_28,0);
  if (uStack_18 < 0x10) {
    ExceptionList = local_14;
    return;
  }
  _free(pvVar1);
  return;
}


// ==== FUN_0073ce20 @ 0x0073ce20 ====

void FUN_0073ce20(void)

{
  undefined4 *in_ECX;
  void *local_28;
  undefined1 local_24;
  uint local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992634;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ef60c;
  local_4 = 0;
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740(s_show_auction_009ef550,0xc);
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  puStack_8 = (undefined1 *)((uint)puStack_8 & 0xffffff00);
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  in_ECX[1] = 0;
  if (DAT_00b5b1b8 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5b1b8)(1);
  }
  if (DAT_00b5b1b4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5b1b4)(1);
  }
  if (DAT_00b5b1b0 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5b1b0)(1);
  }
  if (DAT_00b5b1ac != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5b1ac)(1);
  }
  DAT_00b5adc4 = 0;
  *in_ECX = &PTR_FUN_009ef58c;
  ExceptionList = local_10;
  return;
}


// ==== FUN_0073cf30 @ 0x0073cf30 ====

undefined4 FUN_0073cf30(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 4) != 0) &&
     (cVar1 = (**(code **)(**(int **)(in_ECX + 4) + 8))(param_1), cVar1 != '\0')) {
    return 1;
  }
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    iVar2 = FUN_00424500();
    if (iVar2 == 0x51a000f) {
      FUN_0073cad0(param_1[3]);
      return 1;
    }
  }
  else if ((iVar2 == 0x70004) && (cVar1 = FUN_0073c7c0(param_1), cVar1 != '\0')) {
    return 1;
  }
  return 0;
}


// ==== FUN_0073cfa0 @ 0x0073cfa0 ====

undefined4 FUN_0073cfa0(void)

{
  return 0x70300001;
}


// ==== FUN_0073cfb0 @ 0x0073cfb0 ====

undefined4 FUN_0073cfb0(void)

{
  return 0x70300002;
}


// ==== FUN_0073cfc0 @ 0x0073cfc0 ====

void FUN_0073cfc0(byte param_1)

{
  void *in_ECX;
  
  FUN_0073ce20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073cfe0 @ 0x0073cfe0 ====

void FUN_0073cfe0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ef77c;
  return;
}


// ==== FUN_0073cff0 @ 0x0073cff0 ====

void FUN_0073cff0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ef77c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073d010 @ 0x0073d010 ====

void FUN_0073d010(void)

{
  return;
}


// ==== FUN_0073d020 @ 0x0073d020 ====

undefined1 FUN_0073d020(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 8);
}


// ==== FUN_0073d030 @ 0x0073d030 ====

undefined4 FUN_0073d030(int *param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = (**(code **)(*in_ECX + 0x24))(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0073d060 @ 0x0073d060 ====

void FUN_0073d060(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) != '\x01') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009ef7b0;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 8) = 1;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 8) = 1;
  }
  return;
}


// ==== FUN_0073d0a0 @ 0x0073d0a0 ====

undefined4 FUN_0073d0a0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 8) = 0;
    return 1;
  }
  *puVar1 = &PTR_FUN_009ef7c4;
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 8) = 0;
  return 1;
}


// ==== FUN_0073d0e0 @ 0x0073d0e0 ====

undefined4 * FUN_0073d0e0(undefined4 *param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = in_ECX[6];
  if (iVar1 == in_ECX[4]) {
    (**(code **)(*in_ECX + 0x18))(param_1);
    return param_1;
  }
  *param_1 = *(undefined4 *)(iVar1 + 0xe);
  param_1[1] = *(undefined4 *)(iVar1 + 0x12);
  param_1[2] = *(undefined4 *)(iVar1 + 0x16);
  return param_1;
}


// ==== FUN_0073d120 @ 0x0073d120 ====

void FUN_0073d120(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = **(int **)(in_ECX + 0x10);
  *(int *)(in_ECX + 0x18) = iVar1;
  *param_1 = *(undefined4 *)(iVar1 + 0xe);
  param_1[1] = *(undefined4 *)(iVar1 + 0x12);
  param_1[2] = *(undefined4 *)(iVar1 + 0x16);
  return;
}


// ==== FUN_0073d150 @ 0x0073d150 ====

undefined4 FUN_0073d150(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_minihelpwnd_009ef738,0x10);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 8))();
    return 1;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_minihelpwnd_009ef74c,0x10);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0xc))();
    return 1;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_refresh_ministring_009ef760,0x12);
  if (iVar1 == 0) {
    (**(code **)(*DAT_00b5a794 + 0x10))();
    return 1;
  }
  return 0;
}


// ==== FUN_0073d1e0 @ 0x0073d1e0 ====

undefined4 * FUN_0073d1e0(undefined4 *param_1)

{
  int iVar1;
  int *in_ECX;
  
  if (in_ECX[6] == in_ECX[4]) {
    (**(code **)(*in_ECX + 0x18))(param_1);
    return param_1;
  }
  FUN_0073dc40();
  iVar1 = in_ECX[6];
  if (iVar1 == in_ECX[4]) {
    (**(code **)(*in_ECX + 0x18))(param_1);
    return param_1;
  }
  *param_1 = *(undefined4 *)(iVar1 + 0xe);
  param_1[1] = *(undefined4 *)(iVar1 + 0x12);
  param_1[2] = *(undefined4 *)(iVar1 + 0x16);
  return param_1;
}


// ==== FUN_0073d240 @ 0x0073d240 ====

undefined4 FUN_0073d240(undefined4 param_1,undefined2 param_2,undefined2 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(6,CONCAT22(param_2,param_3));
  uRam00000018 = 0xf;
  uRam00000014 = 0;
  uRam00000004 = 0;
  FUN_00401660(uVar1,0,0xffffffff);
  return 0;
}


// ==== FUN_0073d290 @ 0x0073d290 ====

void FUN_0073d290(void)

{
  undefined4 *in_ECX;
  undefined1 auStack_32 [2];
  undefined4 *local_30;
  void *pvStack_2c;
  void *local_28;
  undefined1 local_24;
  uint uStack_1c;
  uint uStack_18;
  uint local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009926b2;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ef7e4;
  in_ECX[1] = &PTR_FUN_009ef7d8;
  local_4 = 2;
  DAT_00b5ae88 = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  local_30 = in_ECX;
  FUN_00401740(s_show_minihelpwnd_009ef6d4,0x10);
  local_4 = CONCAT31(local_4._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  puStack_8._0_1_ = 2;
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = 0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_hide_minihelpwnd_009ef6e8,0x10);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&pvStack_2c);
  pvStack_c._0_1_ = 2;
  if (0xf < uStack_18) {
    _free(pvStack_2c);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
  FUN_00401740(s_refresh_ministring_009ef6fc,0x12);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_30);
  if (uStack_1c < 0x10) {
    local_10 = CONCAT31(local_10._1_3_,1);
    FUN_0073e320(auStack_32 + -6,*(undefined4 *)in_ECX[4],(undefined4 *)in_ECX[4]);
    _free((void *)in_ECX[4]);
    return;
  }
  _free(local_30);
  return;
}


// ==== FUN_0073d400 @ 0x0073d400 ====

/* WARNING: Removing unreachable block (ram,0x0073d5e5) */
/* WARNING: Removing unreachable block (ram,0x0073d615) */
/* WARNING: Removing unreachable block (ram,0x0073d852) */
/* WARNING: Removing unreachable block (ram,0x0073d637) */
/* WARNING: Removing unreachable block (ram,0x0073d6b5) */
/* WARNING: Removing unreachable block (ram,0x0073d693) */
/* WARNING: Removing unreachable block (ram,0x0073d733) */
/* WARNING: Removing unreachable block (ram,0x0073d711) */
/* WARNING: Removing unreachable block (ram,0x0073d7cf) */
/* WARNING: Removing unreachable block (ram,0x0073d753) */
/* WARNING: Removing unreachable block (ram,0x0073d87f) */
/* WARNING: Removing unreachable block (ram,0x0073d5b6) */
/* WARNING: Removing unreachable block (ram,0x0073d775) */
/* WARNING: Removing unreachable block (ram,0x0073d7f1) */
/* WARNING: Removing unreachable block (ram,0x0073d6d2) */
/* WARNING: Removing unreachable block (ram,0x0073d86d) */
/* WARNING: Removing unreachable block (ram,0x0073d6f4) */
/* WARNING: Removing unreachable block (ram,0x0073d876) */
/* WARNING: Removing unreachable block (ram,0x0073d654) */
/* WARNING: Removing unreachable block (ram,0x0073d85b) */
/* WARNING: Removing unreachable block (ram,0x0073d676) */
/* WARNING: Removing unreachable block (ram,0x0073d864) */
/* WARNING: Removing unreachable block (ram,0x0073d4d3) */
/* WARNING: Removing unreachable block (ram,0x0073d5dd) */
/* WARNING: Removing unreachable block (ram,0x0073d849) */
/* WARNING: Removing unreachable block (ram,0x0073d472) */

void FUN_0073d400(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  void *local_40;
  uint local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009926df;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = 0;
  iVar2 = FUN_00410500();
  iVar1 = *(int *)(iVar2 + 0x40);
  iVar2 = *(int *)(iVar2 + 0x44);
  while( true ) {
    iVar1 = iVar1 + 0x1c;
    if (iVar1 == iVar2) {
      local_4 = 0xffffffff;
      *(undefined4 *)(in_ECX + 0x18) = **(undefined4 **)(in_ECX + 0x10);
      (**(code **)(*DAT_00b5a7cc + 0x14))();
      ExceptionList = local_10;
      return;
    }
    local_4 = 1;
    FUN_00404fb0();
    FUN_00401740(s_Invalid_Line_____d__009ef720,0x14);
    FUN_00404230(local_28);
    local_4._0_1_ = 2;
    FUN_00405bd0();
    local_4 = CONCAT31(local_4._1_3_,3);
    FUN_00796d50();
    if (0xf < local_2c) break;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    if ((void *)0xf < local_10) {
      _free(local_24);
      return;
    }
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    local_10 = (void *)0xf;
    local_14 = 0;
    local_2c = 0xf;
  }
  _free(local_40);
  return;
}


// ==== FUN_0073d890 @ 0x0073d890 ====

void FUN_0073d890(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *in_ECX;
  void *unaff_EBX;
  uint unaff_EBP;
  void *unaff_EDI;
  uint *_Memory;
  uint *puStack_5c;
  undefined1 auStack_46 [2];
  uint local_44;
  undefined1 local_40 [4];
  void *pvStack_3c;
  uint uStack_38;
  uint uStack_34;
  void *local_30;
  undefined4 local_2c;
  uint local_28;
  undefined1 local_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992737;
  pvStack_c = ExceptionList;
  puVar1 = in_ECX + 1;
  ExceptionList = &pvStack_c;
  *puVar1 = &PTR_FUN_009ef7a4;
  local_4 = 1;
  *in_ECX = &PTR_FUN_009ef7e4;
  *puVar1 = &PTR_FUN_009ef7d8;
  puStack_5c = (uint *)0x73d8de;
  iVar2 = FUN_0073dd50();
  in_ECX[4] = iVar2;
  *(undefined1 *)(iVar2 + 0x1b) = 1;
  *(undefined4 *)(in_ECX[4] + 4) = in_ECX[4];
  *(undefined4 *)in_ECX[4] = in_ECX[4];
  *(undefined4 *)(in_ECX[4] + 8) = in_ECX[4];
  in_ECX[5] = 0;
  puStack_5c = (uint *)0x0;
  in_ECX[6] = 0;
  local_4._0_1_ = 2;
  *(undefined1 *)(in_ECX + 2) = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740(&DAT_009ef696);
  puStack_5c = (uint *)0x10;
  local_4._0_1_ = 3;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40[0] = 0;
  FUN_00401740(s_show_minihelpwnd_009ef698);
  puStack_5c = &local_28;
  _Memory = &local_44;
  local_4 = CONCAT31(local_4._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 8))(_Memory,0);
  if (0xf < uStack_38) {
    _free(unaff_EBX);
    return;
  }
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  local_10._0_1_ = 2;
  if (0xf < uStack_1c) {
    _free(local_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffffff00);
  FUN_00401740(&DAT_009ef6a9,0);
  local_10._0_1_ = 5;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740(s_hide_minihelpwnd_009ef6ac,0x10);
  local_10 = CONCAT31(local_10._1_3_,6);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_46 + -10,0,&uStack_34);
  if (0xf < local_44) {
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  uStack_1c._0_1_ = 2;
  if (0xf < local_28) {
    _free(pvStack_3c);
    return;
  }
  local_28 = 0xf;
  local_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  FUN_00401740(&DAT_009ef6bd,0);
  uStack_1c._0_1_ = 7;
  local_44 = 0xf;
  FUN_00401740(s_refresh_ministring_009ef6c0,0x12);
  uStack_1c = CONCAT31(uStack_1c._1_3_,8);
  (**(code **)(*DAT_00b5a6c8 + 8))(&puStack_5c,0,local_40);
  if (0xf < unaff_EBP) {
    _free(_Memory);
    return;
  }
  local_28 = CONCAT31(local_28._1_3_,2);
  if (0xf < uStack_34) {
    _free((void *)0x0);
    return;
  }
  FUN_0073d400();
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ae88 = (undefined4 *)0x0;
    ExceptionList = local_30;
    return;
  }
  DAT_00b5ae88 = in_ECX;
  ExceptionList = local_30;
  return;
}


// ==== FUN_0073db00 @ 0x0073db00 ====

void FUN_0073db00(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x1b);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x1b);
  }
  return;
}


// ==== FUN_0073db20 @ 0x0073db20 ====

void FUN_0073db20(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x1b) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x1b) == '\0');
  }
  return;
}


// ==== FUN_0073db40 @ 0x0073db40 ====

void FUN_0073db40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ef7a4;
  return;
}


// ==== FUN_0073db50 @ 0x0073db50 ====

void FUN_0073db50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ef7a4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073db70 @ 0x0073db70 ====

undefined4 FUN_0073db70(void)

{
  return 0x70280000;
}


// ==== FUN_0073db80 @ 0x0073db80 ====

undefined4 FUN_0073db80(void)

{
  return 0x70280001;
}


// ==== FUN_0073db90 @ 0x0073db90 ====

void FUN_0073db90(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x1b) == '\0') {
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


// ==== FUN_0073dbe0 @ 0x0073dbe0 ====

void FUN_0073dbe0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x1b) == '\0') {
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


// ==== FUN_0073dc40 @ 0x0073dc40 ====

void FUN_0073dc40(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x1b) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x1b) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x1b);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x1b);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x1b);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x1b);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_0073dc90 @ 0x0073dc90 ====

void FUN_0073dc90(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x1b) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x1b) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x1b);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x1b);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x1b) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x1b) == '\0');
    if (*(char *)((int)piVar4 + 0x1b) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_0073dcf0 @ 0x0073dcf0 ====

void FUN_0073dcf0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[3] = *param_4;
    puVar1[4] = param_4[1];
    puVar1[5] = param_4[2];
    *(undefined2 *)(puVar1 + 6) = *(undefined2 *)(param_4 + 3);
    *(undefined1 *)((int)puVar1 + 0x1a) = param_5;
    *(undefined1 *)((int)puVar1 + 0x1b) = 0;
  }
  return;
}


// ==== FUN_0073dd50 @ 0x0073dd50 ====

void FUN_0073dd50(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)((int)puVar1 + 0x1a) = 1;
  *(undefined1 *)((int)puVar1 + 0x1b) = 0;
  return;
}


// ==== FUN_0073dd90 @ 0x0073dd90 ====

void FUN_0073dd90(void *param_1)

{
  if (*(char *)((int)param_1 + 0x1b) == '\0') {
    FUN_0073dd90(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0073ddd0 @ 0x0073ddd0 ====

void FUN_0073ddd0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  int *piVar7;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00992648;
  local_c = ExceptionList;
  if (0x12492490 < *(uint *)(in_ECX + 8)) {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    ExceptionList = &local_c;
    FUN_00401740(s_map_set<T>_too_long_0099cd54,0x13);
    local_4 = 0;
    FUN_00403770(local_50);
    local_34[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00a9c48c);
  }
  ExceptionList = &local_c;
  piVar4 = (int *)FUN_0073dcf0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x1a);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x1a) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if (*(char *)((int)piVar6 + 0x1a) == '\0') {
LAB_0073dec9:
        *(undefined1 *)(*piVar5 + 0x1a) = 1;
        *(undefined1 *)((int)piVar6 + 0x1a) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x1a) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0073db90(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x1a) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x1a) = 0;
        FUN_0073dbe0(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if (*(char *)((int)piVar6 + 0x1a) == '\0') goto LAB_0073dec9;
      if (piVar7 == (int *)*piVar2) {
        FUN_0073dbe0(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x1a) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x1a) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x1b) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x1a);
  } while( true );
}


// ==== FUN_0073dfb0 @ 0x0073dfb0 ====

/* WARNING: Removing unreachable block (ram,0x0073e0c3) */
/* WARNING: Removing unreachable block (ram,0x0073e0d3) */
/* WARNING: Removing unreachable block (ram,0x0073e0dc) */
/* WARNING: Removing unreachable block (ram,0x0073e0df) */
/* WARNING: Removing unreachable block (ram,0x0073e0cf) */
/* WARNING: Removing unreachable block (ram,0x0073e0ed) */
/* WARNING: Removing unreachable block (ram,0x0073e0fa) */
/* WARNING: Removing unreachable block (ram,0x0073e105) */
/* WARNING: Removing unreachable block (ram,0x0073e101) */
/* WARNING: Removing unreachable block (ram,0x0073e0f5) */
/* WARNING: Removing unreachable block (ram,0x0073e108) */

void FUN_0073dfb0(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00992648;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x1b) != '\0') {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    ExceptionList = &pvStack_c;
    FUN_00401740(s_invalid_map_set<T>_iterator_0099cd68,0x1b);
    local_4 = 0;
    FUN_00403770(local_50);
    local_34[0] = &PTR_FUN_0099ca80;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00a9c7c8);
  }
  ExceptionList = &pvStack_c;
  FUN_0073dc40();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x1b) == '\0') {
    if (*(char *)(param_2[2] + 0x1b) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x1b) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x1b) == '\0') {
      piVar3 = (int *)FUN_0073db00(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x1b) == '\0') {
      uVar4 = FUN_0073db20(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if (*(char *)((int)param_2 + 0x1a) == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if (*(char *)((int)piVar6 + 0x1a) != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if (*(char *)((int)piVar5 + 0x1a) == '\0') {
            *(undefined1 *)((int)piVar5 + 0x1a) = 1;
            *(undefined1 *)((int)piVar3 + 0x1a) = 0;
            FUN_0073db90(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x1b) == '\0') {
            if ((*(char *)(*piVar5 + 0x1a) == '\x01') && (*(char *)(piVar5[2] + 0x1a) == '\x01'))
            goto LAB_0073e1d5;
            if (*(char *)(piVar5[2] + 0x1a) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x1a) = 1;
              *(undefined1 *)((int)piVar5 + 0x1a) = 0;
              FUN_0073dbe0(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(undefined1 *)((int)piVar5 + 0x1a) = *(undefined1 *)((int)piVar3 + 0x1a);
            *(undefined1 *)((int)piVar3 + 0x1a) = 1;
            *(undefined1 *)(piVar5[2] + 0x1a) = 1;
            FUN_0073db90(piVar3);
            break;
          }
        }
        else {
          if (*(char *)((int)piVar5 + 0x1a) == '\0') {
            *(undefined1 *)((int)piVar5 + 0x1a) = 1;
            *(undefined1 *)((int)piVar3 + 0x1a) = 0;
            FUN_0073dbe0(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x1b) == '\0') {
            if ((*(char *)(piVar5[2] + 0x1a) != '\x01') || (*(char *)(*piVar5 + 0x1a) != '\x01')) {
              if (*(char *)(*piVar5 + 0x1a) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x1a) = 1;
                *(undefined1 *)((int)piVar5 + 0x1a) = 0;
                FUN_0073db90(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(undefined1 *)((int)piVar5 + 0x1a) = *(undefined1 *)((int)piVar3 + 0x1a);
              *(undefined1 *)((int)piVar3 + 0x1a) = 1;
              *(undefined1 *)(*piVar5 + 0x1a) = 1;
              FUN_0073dbe0(piVar3);
              break;
            }
LAB_0073e1d5:
            *(undefined1 *)((int)piVar5 + 0x1a) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)((int)piVar6 + 0x1a) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_0073e260 @ 0x0073e260 ====

void FUN_0073e260(undefined4 *param_1,ushort *param_2)

{
  undefined4 uVar1;
  ushort *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  bool bVar5;
  
  puVar2 = param_2;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  bVar5 = true;
  if (*(char *)((int)puVar4[1] + 0x1b) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      bVar5 = *param_2 < *(ushort *)(puVar4 + 3);
      if (bVar5) {
        puVar3 = (undefined4 *)*puVar4;
      }
      else {
        puVar3 = (undefined4 *)puVar4[2];
      }
    } while (*(char *)((int)puVar3 + 0x1b) == '\0');
  }
  param_2 = (ushort *)puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_0073ddd0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0073dc90();
  }
  if (*(ushort *)((int)param_2 + 0xc) < *puVar2) {
    puVar4 = (undefined4 *)FUN_0073ddd0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0073e320 @ 0x0073e320 ====

void FUN_0073e320(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0073dd90(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x1b) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x1b) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x1b);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x1b);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x1b);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x1b);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_0073dfb0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0073e3e0 @ 0x0073e3e0 ====

void FUN_0073e3e0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_0073e320(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0073e410 @ 0x0073e410 ====

void FUN_0073e410(void)

{
  FUN_0073e420();
  return;
}


// ==== FUN_0073e420 @ 0x0073e420 ====

void FUN_0073e420(byte param_1)

{
  void *in_ECX;
  
  FUN_0073d290();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073e440 @ 0x0073e440 ====

void FUN_0073e440(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ef810;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073e470 @ 0x0073e470 ====

void FUN_0073e470(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ef81c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ae8c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ae8c = in_ECX;
  return;
}


// ==== FUN_0073e4a0 @ 0x0073e4a0 ====

uint FUN_0073e4a0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  return uVar1 & 0xffffff00;
}


// ==== FUN_0073e4b0 @ 0x0073e4b0 ====

void FUN_0073e4b0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ae8c = 0;
  *in_ECX = &PTR_FUN_009ef810;
  return;
}


// ==== FUN_0073e4d0 @ 0x0073e4d0 ====

void FUN_0073e4d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0073e4b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073e4f0 @ 0x0073e4f0 ====

void FUN_0073e4f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efae4;
  return;
}


// ==== FUN_0073e500 @ 0x0073e500 ====

void FUN_0073e500(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efae4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073e520 @ 0x0073e520 ====

undefined4 FUN_0073e520(void)

{
  return 0x70240000;
}


// ==== FUN_0073e530 @ 0x0073e530 ====

undefined4 FUN_0073e530(void)

{
  return 0x70240001;
}


// ==== FUN_0073e540 @ 0x0073e540 ====

undefined4 FUN_0073e540(void)

{
  return 0x70240002;
}


// ==== FUN_0073e550 @ 0x0073e550 ====

void FUN_0073e550(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099cf40;
  return;
}


// ==== FUN_0073e560 @ 0x0073e560 ====

undefined4 FUN_0073e560(void)

{
  return 0x70240003;
}


// ==== FUN_0073e580 @ 0x0073e580 ====

void FUN_0073e580(void)

{
  undefined4 *puVar1;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xc))();
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009efb44;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0073e5b0 @ 0x0073e5b0 ====

void FUN_0073e5b0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\x01') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009efb1c;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 4) = 1;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 4) = 1;
  }
  return;
}


// ==== FUN_0073e5f0 @ 0x0073e5f0 ====

void FUN_0073e5f0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009efb30;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 4) = 0;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0073e630 @ 0x0073e630 ====

void FUN_0073e630(undefined1 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    uRam00000004 = param_1;
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009efb58;
  *(undefined1 *)(puVar1 + 1) = param_1;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0073e670 @ 0x0073e670 ====

void FUN_0073e670(void)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x5190002;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return;
}


// ==== FUN_0073e6b0 @ 0x0073e6b0 ====

void FUN_0073e6b0(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  undefined1 local_48 [4];
  void *local_44;
  uint local_40;
  void *pvStack_3c;
  uint uStack_38;
  void *pvStack_34;
  uint local_30;
  undefined4 local_2c;
  uint local_28;
  uint local_24;
  uint uStack_20;
  undefined1 uStack_1c;
  uint local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992780;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009efb6c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ae90 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ae90 = in_ECX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = local_24 & 0xffffff00;
  FUN_00401740(s_callservant__servant_type____ser_009ef830,0x40);
  local_4._0_1_ = 1;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = local_40 & 0xffffff00;
  FUN_00401740(s_callservant_009ef874,0xb);
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 4))(&local_44,1,3,&local_28);
  if (0xf < pvStack_3c) {
    _free(unaff_EBP);
    return;
  }
  pvStack_3c = (void *)0xf;
  local_40 = 0;
  local_14 = local_14 & 0xffffff00;
  if (0xf < uStack_20) {
    _free(pvStack_34);
    return;
  }
  uStack_20 = 0xf;
  local_24 = 0;
  pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
  FUN_00401740(s_destroyservant_009ef880,0xe);
  local_14 = CONCAT31(local_14._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(&uStack_38,0);
  uStack_1c = 0;
  if (0xf < local_28) {
    _free(pvStack_3c);
    return;
  }
  local_28 = 0xf;
  local_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  FUN_00401740(s_show_servant_009ef890,0xc);
  uStack_1c = 4;
  (**(code **)(*DAT_00b5a6c8 + 0xc))(&local_40,0);
  local_24 = local_24 & 0xffffff00;
  if (0xf < local_30) {
    _free(local_44);
    return;
  }
  local_30 = 0xf;
  pvStack_34 = (void *)0x0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  FUN_00401740(s_hide_servant_009ef8a0,0xc);
  local_24 = CONCAT31(local_24._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(local_48,0);
  if (uStack_38 < 0x10) {
    *(undefined1 *)(in_ECX + 1) = 0;
    in_ECX[2] = 1;
    ExceptionList = pvStack_34;
    return;
  }
  _free(unaff_EBX);
  return;
}


// ==== FUN_0073e890 @ 0x0073e890 ====

void FUN_0073e890(void)

{
  undefined4 *in_ECX;
  undefined4 *local_2c;
  void *local_28;
  undefined1 local_24;
  uint uStack_18;
  void *local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009927a2;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009efb6c;
  local_4 = 0;
  DAT_00b5ae90 = 0;
  local_10 = 0xf;
  local_14 = (void *)0x0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_show_servant_009ef8b0,0xc);
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  puStack_8 = (undefined1 *)((uint)puStack_8 & 0xffffff00);
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = (void *)0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_hide_servant_009ef8c0,0xc);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  if (uStack_18 < 0x10) {
    *in_ECX = &PTR_FUN_009efae4;
    ExceptionList = local_14;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_0073e970 @ 0x0073e970 ====

/* WARNING: Removing unreachable block (ram,0x0073ea0f) */

int FUN_0073e970(void)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  undefined1 auStack_26 [22];
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009927b4;
  local_c = ExceptionList;
  if (DAT_00b5acd8 == (int *)0x0) {
    return 0;
  }
  ExceptionList = &local_c;
  uVar1 = (**(code **)(*DAT_00b5af10 + 0xc))();
  iVar2 = (**(code **)(*DAT_00b5acd8 + 0xc))(uVar1);
  if (iVar2 == 0) {
    (**(code **)(*DAT_00b5af10 + 0x14))();
    (**(code **)(*in_ECX + 0x10))();
    FUN_00401740(s_InitServantStatus__Can_t_find_ac_009ef8dc,0x23);
    puStack_8 = (undefined1 *)iVar2;
    FUN_00796d50(auStack_26 + -6);
  }
  ExceptionList = pvStack_10;
  return iVar2;
}


// ==== FUN_0073ea30 @ 0x0073ea30 ====

int FUN_0073ea30(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int extraout_EAX;
  int iVar3;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009927c6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  piVar1 = (int *)FUN_0073e970();
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(s_NoName_009ef900,6);
    ExceptionList = local_c;
    return param_1;
  }
  piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
  uVar2 = (**(code **)(*piVar1 + 0x24))();
  piVar1 = (int *)FUN_00803725(uVar2,0,&Framework::ICreature::RTTI_Type_Descriptor,
                               &Framework::Creature::IServant::RTTI_Type_Descriptor,0);
  if (piVar1 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar1 + 0x28))();
    FUN_00401830(iVar3 + 8);
    ExceptionList = local_c;
    return param_1;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_Invalid_Actor_Info_009ef908,0x12);
  uStack_4 = 0;
  FUN_00796d50(auStack_28);
  uStack_4 = 0xffffffff;
  if (uStack_10 < 0x10) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(s_NoName_009ef91c,6);
    ExceptionList = local_c;
    return param_1;
  }
  _free(pvStack_24);
  return extraout_EAX;
}


// ==== FUN_0073eb70 @ 0x0073eb70 ====

uint FUN_0073eb70(void)

{
  int *piVar1;
  undefined4 uVar2;
  uint extraout_EAX;
  int iVar3;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  int *piStack_14;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009927d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  piVar1 = (int *)FUN_0073e970();
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
    uVar2 = (**(code **)(*piVar1 + 0x24))();
    piStack_14 = (int *)FUN_00803725(uVar2,0,&Framework::ICreature::RTTI_Type_Descriptor,
                                     &Framework::Creature::IServant::RTTI_Type_Descriptor,0);
    if (piStack_14 != (int *)0x0) {
      iVar3 = (**(code **)(*piStack_14 + 0x28))();
      ExceptionList = local_c;
      return (uint)*(ushort *)(iVar3 + 0x2ac);
    }
    uStack_10 = 0xf;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_Invalid_Actor_Info_009ef924,0x12);
    uStack_4 = 0;
    FUN_00796d50(auStack_28);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return extraout_EAX;
    }
  }
  ExceptionList = local_c;
  return 0x50;
}


// ==== FUN_0073ec40 @ 0x0073ec40 ====

void FUN_0073ec40(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  void *pvStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  void *pvStack_14;
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099280a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[2] = param_1;
  piVar1 = (int *)FUN_0073e970();
  if (piVar1 == (int *)0x0) {
    ExceptionList = local_c;
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
  if (piVar2 == (int *)0x0) {
    pvStack_2c = (void *)0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    FUN_00401740(s_InitServantStatus__Can_t_find_Al_009ef938,0x25);
    uStack_4 = 0;
    FUN_00796d50(auStack_44);
    if (pvStack_2c < 0x10) {
      ExceptionList = local_c;
      return;
    }
    _free(pvStack_40);
    return;
  }
  uVar3 = (**(code **)(*DAT_00b5af10 + 0xc))();
  uStack_64 = uVar3;
  piVar2 = (int *)(**(code **)(*piVar2 + 0x30))(&uStack_64);
  if (piVar2 == (int *)0x0) {
    FUN_00401830(s_InitServantStatus__Can_t_find_Se_009ef960);
    uStack_4 = 1;
    FUN_00796d50(auStack_44);
    if (pvStack_2c < (void *)0x10) {
      ExceptionList = local_c;
      return;
    }
    _free(pvStack_40);
    return;
  }
  piVar2 = *(int **)(*piVar2 + 4);
  if (piVar2 == (int *)0x0) {
    FUN_00401830(s_InitServantStatus__Can_t_find_Se_009ef988);
    uStack_4 = 2;
  }
  else {
    iVar4 = (**(code **)(*piVar2 + 0x28))();
    if (iVar4 != 0) {
      (**(code **)(*DAT_00b5af10 + 4))(0);
      switch(in_ECX[2]) {
      case 0:
        (**(code **)(*DAT_00b5af10 + 4))(1);
        ExceptionList = pvStack_10;
        return;
      case 1:
        piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
        uVar5 = (**(code **)(*piVar1 + 0x24))();
        piVar1 = (int *)FUN_00803725(uVar5,0,&Framework::ICreature::RTTI_Type_Descriptor,
                                     &Framework::Creature::IServant::RTTI_Type_Descriptor,0);
        if (piVar1 != (int *)0x0) {
          iVar4 = (**(code **)(*piVar1 + 0x28))();
          uStack_64 = 0;
          uStack_60 = 0;
          piVar1 = (int *)(**(code **)(*piVar2 + 0x28))();
          (**(code **)(*piVar1 + 0xc))(&uStack_64);
          uVar5 = (**(code **)(*DAT_00b5a6f4 + 8))(*(undefined2 *)(iVar4 + 0xee));
          piVar1 = (int *)(**(code **)(*piVar2 + 0x28))();
          (**(code **)(*piVar1 + 4))(uVar5);
          iVar4 = (**(code **)(*piVar2 + 0x30))();
          uStack_64 = *(undefined4 *)(iVar4 + 4);
          (**(code **)(*piVar2 + 0x2c))(auStack_44 + -0x24);
          uVar5 = FUN_00457870(0,uVar3);
          (**(code **)(*DAT_00b5a804 + 0xc))(uVar3,uVar5);
          (**(code **)(*DAT_00b5a70c + 0x10))(1,uVar5);
          ExceptionList = pvStack_2c;
          return;
        }
        FUN_00401830(s_Invalid_Actor_Info_009ef9d8);
        uStack_4 = 4;
        FUN_00796d50(auStack_28);
        goto LAB_0073ed84;
      case 2:
        uStack_64 = 0;
        uStack_60 = 0;
        piVar1 = (int *)(**(code **)(*piVar2 + 0x28))();
        iVar4 = (**(code **)(*piVar1 + 0xc))(&uStack_64);
        if ((iVar4 == 0) || (*(int *)(iVar4 + 4) != 1)) {
          uStack_4 = (**(code **)(*DAT_00b5a6f4 + 8))(1000);
          piVar1 = (int *)(**(code **)(*piVar2 + 0x28))();
          (**(code **)(*piVar1 + 4))(uStack_4);
        }
        iVar4 = (**(code **)(*piVar2 + 0x30))();
        uStack_54 = *(undefined4 *)(iVar4 + 4);
        uStack_58 = 1;
        (**(code **)(*piVar2 + 0x2c))(&uStack_58);
        uVar5 = FUN_00457870(0,uVar3);
        (**(code **)(*DAT_00b5a804 + 0xc))(uVar3,uVar5);
        (**(code **)(*DAT_00b5a70c + 0x10))(1,uVar5);
        ExceptionList = pvStack_24;
        return;
      case 3:
        uVar5 = FUN_0073f5e0(0,uVar3);
        (**(code **)(*DAT_00b5a804 + 0xc))(uVar3,uVar5);
        (**(code **)(*DAT_00b5a70c + 0x10))(1,uVar5);
        uStack_5c = 0;
        uStack_58 = 0;
        piVar1 = (int *)(**(code **)(*piVar2 + 0x28))();
        piVar1 = (int *)(**(code **)(*piVar1 + 0xc))(&uStack_5c);
        if (((piVar1 == (int *)0x0) || (piVar1[1] != 1)) || (*piVar1 != 6)) {
          uVar3 = (**(code **)(*DAT_00b5a6f4 + 8))(0x3ea);
          piVar1 = (int *)(**(code **)(*piVar2 + 0x28))();
          (**(code **)(*piVar1 + 4))(uVar3);
          ExceptionList = pvStack_14;
          return;
        }
        break;
      case 4:
        (**(code **)(*in_ECX + 0x1c))();
      }
      ExceptionList = local_c;
      return;
    }
    FUN_00401830(s_InitServantStatus__Is_Not_Contro_009ef9b0);
    uStack_4 = 3;
  }
  FUN_00796d50(auStack_44);
LAB_0073ed84:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0073f070 @ 0x0073f070 ====

void FUN_0073f070(void)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 auStack_4c [2];
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099283c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  piVar1 = (int *)FUN_0073e970();
  if (piVar1 == (int *)0x0) {
    ExceptionList = local_c;
    return;
  }
  uVar2 = (**(code **)(*DAT_00b5af10 + 0xc))();
  piVar3 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
  if (piVar3 == (int *)0x0) {
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    FUN_00401740(s_InitServantStatus__Can_t_find_Al_009ef9ec,0x25);
    uStack_4 = 0;
    FUN_00796d50(auStack_44);
    if (uStack_2c < 0x10) {
      ExceptionList = local_c;
      return;
    }
    _free(pvStack_40);
    return;
  }
  auStack_4c[0] = uVar2;
  piVar3 = (int *)(**(code **)(*piVar3 + 0x30))(auStack_4c);
  if (piVar3 == (int *)0x0) {
    FUN_00401830(s_InitServantStatus__Can_t_find_Se_009efa14);
    uStack_4 = 1;
    FUN_00796d50(auStack_44);
    if (uStack_2c < 0x10) {
      ExceptionList = local_c;
      return;
    }
    _free(pvStack_40);
    return;
  }
  piVar3 = *(int **)(*piVar3 + 4);
  if (piVar3 == (int *)0x0) {
    FUN_00401830(s_InitServantStatus__Can_t_find_Se_009efa3c);
    uStack_4 = 2;
  }
  else {
    iVar4 = (**(code **)(*piVar3 + 0x28))();
    if (iVar4 != 0) {
      uStack_54 = 4;
      uStack_50 = 0x19;
      piVar5 = (int *)(**(code **)(*piVar3 + 0x28))();
      (**(code **)(*piVar5 + 0xc))(&uStack_54);
      piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
      uVar6 = (**(code **)(*piVar1 + 0x24))();
      piVar1 = (int *)FUN_00803725(uVar6,0,&Framework::ICreature::RTTI_Type_Descriptor,
                                   &Framework::Creature::IServant::RTTI_Type_Descriptor,0);
      if (piVar1 != (int *)0x0) {
        iVar4 = (**(code **)(*piVar1 + 0x28))();
        uVar6 = (**(code **)(*DAT_00b5a6f4 + 8))(*(undefined2 *)(iVar4 + 0xee));
        piVar1 = (int *)(**(code **)(*piVar3 + 0x28))();
        (**(code **)(*piVar1 + 4))(uVar6);
        uVar6 = (**(code **)(*DAT_00b5a6ac + 0x20))(uStack_4);
        iVar4 = FUN_0073f610(uVar6);
        *(undefined4 *)(iVar4 + 0xc) = 0;
        (**(code **)(*DAT_00b5a804 + 0xc))(uVar2,iVar4);
        (**(code **)(*DAT_00b5a70c + 0x10))(1,iVar4);
        ExceptionList = local_c;
        return;
      }
      FUN_00401830(s_Invalid_Actor_Info_009efa8c);
      uStack_4 = 4;
      FUN_00796d50(auStack_28);
      goto LAB_0073f1a6;
    }
    FUN_00401830(s_InitServantStatus__Is_Not_Contro_009efa64);
    uStack_4 = 3;
  }
  FUN_00796d50(auStack_44);
LAB_0073f1a6:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0073f2e0 @ 0x0073f2e0 ====

void FUN_0073f2e0(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *unaff_retaddr;
  
  piVar1 = (int *)FUN_0073e970();
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
    iVar2 = (**(code **)(*piVar1 + 0x24))();
    iVar2 = **(int **)(iVar2 + 0x50);
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    piVar1 = (int *)(**(code **)(iVar2 + 0x14))(uVar3);
    puVar4 = (undefined4 *)(**(code **)(*piVar1 + 0x18))();
    *unaff_retaddr = *puVar4;
    iVar2 = (**(code **)(*piVar1 + 0x18))();
    *param_1 = *(undefined4 *)(iVar2 + 0xc);
  }
  return;
}


// ==== FUN_0073f340 @ 0x0073f340 ====

void FUN_0073f340(undefined2 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  void *pvVar4;
  undefined4 *puVar5;
  undefined1 auStack_2c [4];
  void *pvStack_28;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00992856;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*DAT_00b5abd4 + 8))();
  if (iVar1 == 0) {
    FUN_00401740(s___select_invalid_monster___009efaa0);
    uVar2 = FUN_00404230();
    puStack_8 = (undefined1 *)0x0;
    FUN_00796d20(uVar2);
    if (0xf < uStack_14) {
      _free(pvStack_28);
      return;
    }
  }
  else {
    FUN_00401740(s_call__u_monster__009efabc,0x11);
    uVar2 = FUN_00404230(auStack_2c);
    puStack_8 = (undefined1 *)0x1;
    FUN_00796d20(uVar2);
    puStack_8 = (undefined1 *)0xffffffff;
    if (0xf < uStack_14) {
      _free(pvStack_28);
      return;
    }
    piVar3 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    (**(code **)(*piVar3 + 0x28))();
    (**(code **)(*piVar3 + 0x2c))();
    FUN_0040d5f0();
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined4 *)((int)pvVar4 + 8) = uVar2;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x5190001;
    *(undefined2 *)((int)pvVar4 + 6) = 0x1c;
    iVar1 = FUN_004244d0();
    *(undefined2 *)(iVar1 + 0x10) = param_1;
    puVar5 = (undefined4 *)FUN_004ef0e0();
    *(undefined4 *)(iVar1 + 0x16) = *puVar5;
    *(undefined2 *)(iVar1 + 0x1a) = *(undefined2 *)(puVar5 + 1);
    FUN_004d8570();
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0073f4f0 @ 0x0073f4f0 ====

undefined4 FUN_0073f4f0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  int *in_ECX;
  undefined1 local_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00992868;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_callservant_009ef8d0,0xb);
  if (iVar1 != 0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar2 = FUN_00459160(local_28,0);
  local_4 = 0;
  uVar2 = thunk_FUN_00796f80(uVar2);
  local_4 = 0xffffffff;
  if (pvStack_10 < 0x10) {
    pvStack_10 = (void *)0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    (**(code **)(*in_ECX + 0x18))(uVar2);
    ExceptionList = pvStack_10;
    return 1;
  }
  _free(pvStack_24);
  return extraout_EAX;
}


// ==== FUN_0073f5b0 @ 0x0073f5b0 ====

undefined4 FUN_0073f5b0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_0073f4f0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0073f5e0 @ 0x0073f5e0 ====

void FUN_0073f5e0(void)

{
  undefined4 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1);
  *puVar1 = 0x1a;
  puVar1[1] = 0;
  puVar1[2] = unaff_retaddr;
  return;
}


// ==== FUN_0073f610 @ 0x0073f610 ====

void FUN_0073f610(void)

{
  undefined4 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1);
  *puVar1 = 0x19;
  puVar1[1] = 0;
  puVar1[2] = unaff_retaddr;
  return;
}


// ==== FUN_0073f640 @ 0x0073f640 ====

void FUN_0073f640(byte param_1)

{
  void *in_ECX;
  
  FUN_0073e890();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073f660 @ 0x0073f660 ====

void FUN_0073f660(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efbf8;
  return;
}


// ==== FUN_0073f670 @ 0x0073f670 ====

void FUN_0073f670(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efbf8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073f690 @ 0x0073f690 ====

int FUN_0073f690(int param_1,undefined1 param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int extraout_EAX;
  int extraout_EAX_00;
  int in_ECX;
  int iVar3;
  uint in_stack_00000020;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992888;
  iVar3 = *(int *)(in_ECX + 8);
  iVar1 = *(int *)(in_ECX + 0xc);
  local_4 = 0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  for (; iVar3 != iVar1; iVar3 = iVar3 + 0x1c) {
    iVar2 = FUN_00403fb0(&param_2,iVar3);
    if (iVar2 != -1) {
      *(undefined4 *)(param_1 + 0x18) = 0xf;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      FUN_00401660(iVar3,0,0xffffffff);
      if (in_stack_00000020 < 0x10) {
        ExceptionList = local_c;
        return param_1;
      }
      _free(param_3);
      return extraout_EAX_00;
    }
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401740(&DAT_009efbed,0);
  if (in_stack_00000020 < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(param_3);
  return extraout_EAX;
}


// ==== FUN_0073f770 @ 0x0073f770 ====

void FUN_0073f770(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efc04;
  DAT_00b5b18c = 0;
  if (in_ECX[2] == 0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_009efbf8;
    return;
  }
  FUN_00405de0(in_ECX[2],in_ECX[3],in_ECX + 1);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0073f7c0 @ 0x0073f7c0 ====

void FUN_0073f7c0(void *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint in_stack_00000018;
  undefined1 local_38 [4];
  void *local_34;
  int local_30;
  undefined4 local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  puStack_8 = &LAB_009928aa;
  pvStack_c = ExceptionList;
  local_4 = 0;
  uStack_3 = 0;
  ExceptionList = &pvStack_c;
  iVar2 = FUN_00410500(&param_1);
  iVar1 = *(int *)(iVar2 + 0x44);
  iVar3 = *(int *)(iVar2 + 0x40);
  while( true ) {
    if (iVar3 == iVar1) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(iVar2);
      if (in_stack_00000018 < 0x10) {
        ExceptionList = local_10;
        return;
      }
      _free(param_1);
      return;
    }
    local_34 = (void *)0x0;
    local_30 = 0;
    local_2c = 0;
    local_4 = 1;
    FUN_00404fb0(iVar3,0x2c,local_38);
    if ((local_34 == (void *)0x0) || ((local_30 - (int)local_34) / 0x1c == 0)) break;
    local_10 = (void *)0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00401660(local_34,0,0xffffffff);
    local_4 = 2;
    FUN_00406720(local_28);
    if (0xf < local_10) {
      _free(local_24);
      return;
    }
    local_10 = (void *)0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    local_4 = 0;
    if (local_34 != (void *)0x0) {
      FUN_00405de0(local_34,local_30,local_38,param_1);
      _free(local_34);
      return;
    }
    iVar3 = iVar3 + 0x1c;
    local_34 = (void *)0x0;
    local_30 = 0;
    local_2c = 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00405ca0();
}


// ==== FUN_0073f940 @ 0x0073f940 ====

void FUN_0073f940(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009928c7;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009efc04;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  local_4 = 1;
  FUN_00401740(s_slangfillter_txt_009efbdc,0x10);
  FUN_0073f7c0();
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b18c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5b18c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0073f9e0 @ 0x0073f9e0 ====

void FUN_0073f9e0(byte param_1)

{
  void *in_ECX;
  
  FUN_0073f770();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073fa00 @ 0x0073fa00 ====

void FUN_0073fa00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efc10;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073fa20 @ 0x0073fa20 ====

void FUN_0073fa20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efc1c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b190 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b190 = in_ECX;
  return;
}


// ==== FUN_0073fa50 @ 0x0073fa50 ====

void FUN_0073fa50(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b190 = 0;
  *in_ECX = &PTR_FUN_009efc10;
  return;
}


// ==== FUN_0073fa70 @ 0x0073fa70 ====

int * FUN_0073fa70(float *param_1)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  float *pfVar4;
  int *piVar5;
  float local_4;
  
  piVar5 = (int *)0x0;
  if (DAT_00b5acd8 == (int *)0x0) {
    return (int *)0x0;
  }
  local_4 = DAT_009efc24;
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0x18))();
  if (piVar2 == (int *)0x0) {
    return (int *)0x0;
  }
  do {
    iVar3 = (**(code **)(*piVar2 + 0xc))();
    if ((iVar3 == 10) || (iVar3 = (**(code **)(*piVar2 + 0xc))(), iVar3 == 9)) {
      pfVar4 = (float *)(**(code **)(*piVar2 + 0x28))();
      fVar1 = SQRT((param_1[1] - pfVar4[1]) * (param_1[1] - pfVar4[1]) +
                   (*param_1 - *pfVar4) * (*param_1 - *pfVar4));
      if (fVar1 < local_4) {
        piVar5 = piVar2;
        local_4 = fVar1;
      }
    }
    piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0x1c))();
  } while (piVar2 != (int *)0x0);
  return piVar5;
}


// ==== FUN_0073fb20 @ 0x0073fb20 ====

uint FUN_0073fb20(void)

{
  int iVar1;
  uint in_EAX;
  int *piVar2;
  undefined4 uVar3;
  
  if (DAT_00b5a97c != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    uVar3 = (**(code **)(*piVar2 + 0x28))();
    piVar2 = (int *)FUN_0073fa70(uVar3);
    in_EAX = 0;
    if (piVar2 != (int *)0x0) {
      piVar2 = (int *)(**(code **)(*piVar2 + 0x14))();
      iVar1 = *DAT_00b5ac28;
      uVar3 = (**(code **)(*piVar2 + 8))();
      in_EAX = (**(code **)(iVar1 + 0xc))(uVar3);
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_0073fb70 @ 0x0073fb70 ====

void FUN_0073fb70(byte param_1)

{
  void *in_ECX;
  
  FUN_0073fa50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073fb90 @ 0x0073fb90 ====

void FUN_0073fb90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efc90;
  return;
}


// ==== FUN_0073fba0 @ 0x0073fba0 ====

void FUN_0073fba0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efc90;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0073fbc0 @ 0x0073fbc0 ====

int FUN_0073fbc0(int param_1,undefined1 param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int extraout_EAX;
  int extraout_EAX_00;
  int in_ECX;
  int iVar3;
  uint in_stack_00000020;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009928e8;
  iVar3 = *(int *)(in_ECX + 8);
  iVar1 = *(int *)(in_ECX + 0xc);
  local_4 = 0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  for (; iVar3 != iVar1; iVar3 = iVar3 + 0x1c) {
    iVar2 = FUN_00403fb0(&param_2,iVar3);
    if (iVar2 != -1) {
      *(undefined4 *)(param_1 + 0x18) = 0xf;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      FUN_00401660(iVar3,0,0xffffffff);
      if (in_stack_00000020 < 0x10) {
        ExceptionList = local_c;
        return param_1;
      }
      _free(param_3);
      return extraout_EAX_00;
    }
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401740(&DAT_009efc84,0);
  if (in_stack_00000020 < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(param_3);
  return extraout_EAX;
}


// ==== FUN_0073fca0 @ 0x0073fca0 ====

int FUN_0073fca0(int param_1,undefined4 param_2,byte *param_3)

{
  uint uVar1;
  int iVar2;
  int extraout_EAX;
  int in_ECX;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  uint in_stack_0000001c;
  uint in_stack_00000020;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009928fa;
  local_c = ExceptionList;
  iVar4 = *(int *)(in_ECX + 0x18);
  local_4 = 0;
  do {
    if (iVar4 == *(int *)(in_ECX + 0x1c)) {
      ExceptionList = &local_c;
      *(undefined4 *)(param_1 + 0x18) = 0xf;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      FUN_00401740(&DAT_009efc85,0);
joined_r0x0073fda9:
      if (in_stack_00000020 < 0x10) {
        ExceptionList = local_c;
        return param_1;
      }
      _free(param_3);
      return extraout_EAX;
    }
    uVar1 = *(uint *)(iVar4 + 0x14);
    if (*(uint *)(iVar4 + 0x18) < 0x10) {
      pbVar6 = (byte *)(iVar4 + 4);
    }
    else {
      pbVar6 = *(byte **)(iVar4 + 4);
    }
    if (in_stack_0000001c == 0) {
LAB_0073fd1e:
      if ((uVar1 <= in_stack_0000001c) && (in_stack_0000001c == uVar1)) {
        ExceptionList = &local_c;
        *(undefined4 *)(param_1 + 0x18) = 0xf;
        *(undefined4 *)(param_1 + 0x14) = 0;
        *(undefined1 *)(param_1 + 4) = 0;
        FUN_00401660(iVar4,0,0xffffffff);
        goto joined_r0x0073fda9;
      }
    }
    else {
      uVar3 = in_stack_0000001c;
      if (uVar1 <= in_stack_0000001c) {
        uVar3 = uVar1;
      }
      pbVar5 = param_3;
      if (in_stack_00000020 < 0x10) {
        pbVar5 = (byte *)&param_3;
      }
      bVar7 = false;
      iVar2 = 0;
      bVar8 = true;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        bVar7 = *pbVar5 < *pbVar6;
        bVar8 = *pbVar5 == *pbVar6;
        pbVar5 = pbVar5 + 1;
        pbVar6 = pbVar6 + 1;
      } while (bVar8);
      if (!bVar8) {
        iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      }
      if (iVar2 == 0) goto LAB_0073fd1e;
    }
    iVar4 = iVar4 + 0x1c;
  } while( true );
}


// ==== FUN_0073fdc0 @ 0x0073fdc0 ====

void FUN_0073fdc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efca0;
  DAT_00b5ae18 = 0;
  if (in_ECX[6] != 0) {
    FUN_00405de0(in_ECX[6],in_ECX[7],in_ECX + 5);
    _free((void *)in_ECX[6]);
    return;
  }
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  if (in_ECX[2] == 0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_009efc90;
    return;
  }
  FUN_00405de0(in_ECX[2],in_ECX[3],in_ECX + 1);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0073fe40 @ 0x0073fe40 ====

void FUN_0073fe40(void *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint in_stack_00000018;
  undefined1 local_38 [4];
  void *local_34;
  int local_30;
  undefined4 local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  puStack_8 = &LAB_0099291c;
  pvStack_c = ExceptionList;
  local_4 = 0;
  uStack_3 = 0;
  ExceptionList = &pvStack_c;
  iVar2 = FUN_00410500(&param_1);
  iVar1 = *(int *)(iVar2 + 0x44);
  iVar3 = *(int *)(iVar2 + 0x40);
  while( true ) {
    if (iVar3 == iVar1) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(iVar2);
      if (in_stack_00000018 < 0x10) {
        ExceptionList = local_10;
        return;
      }
      _free(param_1);
      return;
    }
    local_34 = (void *)0x0;
    local_30 = 0;
    local_2c = 0;
    local_4 = 1;
    FUN_00404fb0(iVar3,0x2c,local_38);
    if ((local_34 == (void *)0x0) || ((local_30 - (int)local_34) / 0x1c == 0)) break;
    local_10 = (void *)0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00401660(local_34,0,0xffffffff);
    local_4 = 2;
    FUN_00406720(local_28);
    if (0xf < local_10) {
      _free(local_24);
      return;
    }
    local_10 = (void *)0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    local_4 = 0;
    if (local_34 != (void *)0x0) {
      FUN_00405de0(local_34,local_30,local_38,param_1);
      _free(local_34);
      return;
    }
    iVar3 = iVar3 + 0x1c;
    local_34 = (void *)0x0;
    local_30 = 0;
    local_2c = 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00405ca0();
}


// ==== FUN_0073ffc0 @ 0x0073ffc0 ====

void FUN_0073ffc0(void *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint in_stack_00000018;
  undefined1 local_38 [4];
  void *local_34;
  int local_30;
  undefined4 local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  puStack_8 = &LAB_0099293e;
  pvStack_c = ExceptionList;
  local_4 = 0;
  uStack_3 = 0;
  ExceptionList = &pvStack_c;
  iVar2 = FUN_00410500(&param_1);
  iVar1 = *(int *)(iVar2 + 0x44);
  iVar3 = *(int *)(iVar2 + 0x40);
  while( true ) {
    if (iVar3 == iVar1) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(iVar2);
      if (in_stack_00000018 < 0x10) {
        ExceptionList = local_10;
        return;
      }
      _free(param_1);
      return;
    }
    local_34 = (void *)0x0;
    local_30 = 0;
    local_2c = 0;
    local_4 = 1;
    FUN_00404fb0(iVar3,0x2c,local_38);
    if ((local_34 == (void *)0x0) || ((local_30 - (int)local_34) / 0x1c == 0)) break;
    local_10 = (void *)0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00401660(local_34,0,0xffffffff);
    local_4 = 2;
    FUN_00406720(local_28);
    if (0xf < local_10) {
      _free(local_24);
      return;
    }
    local_10 = (void *)0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    local_4 = 0;
    if (local_34 != (void *)0x0) {
      FUN_00405de0(local_34,local_30,local_38,param_1);
      _free(local_34);
      return;
    }
    iVar3 = iVar3 + 0x1c;
    local_34 = (void *)0x0;
    local_30 = 0;
    local_2c = 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00405ca0();
}


