// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x630000-0x63ffff

// ==== FUN_00630270 @ 0x00630270 ====

undefined4 FUN_00630270(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  int in_ECX;
  undefined1 local_100 [256];
  
  piVar1 = *(int **)(in_ECX + 0xc);
  if (piVar1 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d0b68,s_____EXCEPTION_____NULL_stat_mana_009d07f8);
    FUN_00797b80(local_100);
    return 0;
  }
  piVar2 = (int *)(**(code **)(*piVar1 + 0x24))();
  if (piVar2 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d0b68,s_____EXCEPTION_____NULL_stat_arti_009d0820);
    FUN_00797b80(local_100);
    return 0;
  }
  (**(code **)(*piVar1 + 0x18))(*(undefined2 *)(param_1 + 0x34));
  (**(code **)(*piVar2 + 0x14))(CONCAT22(extraout_var,*(undefined2 *)(param_1 + 0x20)));
  (**(code **)(*piVar2 + 0x18))(CONCAT22(extraout_var_00,*(undefined2 *)(param_1 + 0x22)));
  (**(code **)(*piVar2 + 0x1c))(CONCAT22(extraout_var_01,*(undefined2 *)(param_1 + 0x24)));
  (**(code **)(*piVar2 + 0x20))(CONCAT22(extraout_var_02,*(undefined2 *)(param_1 + 0x26)));
  (**(code **)(*piVar2 + 0x28))(*(undefined1 *)(param_1 + 0x3e));
  return 1;
}


// ==== FUN_00630350 @ 0x00630350 ====

undefined4 FUN_00630350(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  char *pcVar3;
  undefined1 local_100 [256];
  
  piVar1 = *(int **)(in_ECX + 0x48);
  if (piVar1 == (int *)0x0) {
    pcVar3 = s_____EXCEPTION_____NULL_level_man_009d0848;
  }
  else {
    piVar2 = (int *)(**(code **)(*piVar1 + 0x24))();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x14))(param_1 + 0x38);
      (**(code **)(*piVar1 + 0x18))(param_1 + 8);
      return 1;
    }
    pcVar3 = s_____EXCEPTION_____NULL_level_art_009d0870;
  }
  FUN_0044a580(local_100,&DAT_009d0b68,pcVar3);
  FUN_00797b80(local_100);
  return 0;
}


// ==== FUN_006303d0 @ 0x006303d0 ====

undefined4 FUN_006303d0(int param_1)

{
  int *piVar1;
  int in_ECX;
  undefined1 local_100 [256];
  
  piVar1 = *(int **)(in_ECX + 0x40);
  if (piVar1 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d0b68,s_____EXCEPTION_____NULL_skill_man_009d0898);
    FUN_00797b80(local_100);
    return 0;
  }
  (**(code **)(*piVar1 + 0x14))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x24))();
  (**(code **)(*piVar1 + 4))(*(undefined2 *)(param_1 + 0x36));
  (**(code **)(*piVar1 + 0x14))(*(undefined1 *)(param_1 + 0x3d));
  return 1;
}


// ==== FUN_00630450 @ 0x00630450 ====

undefined4 FUN_00630450(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  int *piVar5;
  int unaff_retaddr;
  undefined1 local_100 [2];
  undefined1 auStack_fe [254];
  
  if (*(int **)(in_ECX + 0x50) == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d0b68,s_____EXCEPTION_____NULL_state_man_009d08c0);
    FUN_00797b80(local_100);
    return 0;
  }
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x50) + 0x14))(10);
  if (piVar2 == (int *)0x0) {
    FUN_0044a580(local_100 + -4,&DAT_009d0b68,s_____EXCEPTION_____NULL_state_art_009d08e8);
    FUN_00797b80(local_100 + -4);
    return 0;
  }
  if (*(int **)(in_ECX + 0x44) == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 0x44) + 0x18))();
  }
  (**(code **)(*piVar2 + 0x6c))((float)*(int *)(unaff_retaddr + 0x18));
  (**(code **)(*piVar2 + 0x70))((float)*(int *)(unaff_retaddr + 0x1c));
  (**(code **)(*piVar2 + 0x8c))((float)*(int *)(unaff_retaddr + 0x44));
  puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x18))();
  (**(code **)(*piVar5 + 0x14))(*puVar3);
  iVar1 = *piVar5;
  iVar4 = (**(code **)(*piVar2 + 0x18))();
  (**(code **)(iVar1 + 0x20))(*(undefined4 *)(iVar4 + 4));
  iVar1 = *piVar5;
  iVar4 = (**(code **)(*piVar2 + 0x18))();
  (**(code **)(iVar1 + 0x2c))(*(undefined4 *)(iVar4 + 8));
  iVar1 = *piVar5;
  iVar4 = (**(code **)(*piVar2 + 0x18))();
  (**(code **)(iVar1 + 0x1c))(*(undefined4 *)(iVar4 + 0xc));
  iVar1 = *piVar5;
  iVar4 = (**(code **)(*piVar2 + 0x18))();
  (**(code **)(iVar1 + 0x28))(*(undefined4 *)(iVar4 + 0x10));
  iVar1 = *piVar5;
  iVar4 = (**(code **)(*piVar2 + 0x18))();
  (**(code **)(iVar1 + 0x34))(*(undefined4 *)(iVar4 + 0x14));
  return 1;
}


// ==== FUN_006305a0 @ 0x006305a0 ====

undefined4 FUN_006305a0(int param_1)

{
  int *piVar1;
  int in_ECX;
  undefined1 local_100 [2];
  undefined1 auStack_fe [254];
  
  if ((*(int **)(in_ECX + 0x20) == (int *)0x0) ||
     (piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x20) + 0x54))(), piVar1 == (int *)0x0)) {
    FUN_0044a580(local_100,&DAT_009d0b68);
    FUN_00797b80(local_100);
    return 0;
  }
  (**(code **)(*piVar1 + 8))(*(undefined4 *)(param_1 + 0xc));
  if (*(int **)(in_ECX + 0x34) == (int *)0x0) {
    FUN_0044a580(local_100 + -4,&DAT_009d0b68,s_____EXCEPTION_____NULL_pStore_ma_009d095c);
    FUN_00797b80(local_100 + -4);
    return 0;
  }
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x34) + 0x3c))();
  if (piVar1 == (int *)0x0) {
    FUN_0044a580(local_100 + -4,&DAT_009d0b68,s_____EXCEPTION_____NULL_account_m_009d0984);
    FUN_00797b80(local_100 + -4);
    return 0;
  }
  (**(code **)(*piVar1 + 8))(*(undefined4 *)(param_1 + 0x10));
  if (*(int **)(in_ECX + 0x2c) == (int *)0x0) {
    FUN_0044a670(s_____EXCEPTION_____NULL_pStorage_m_009d09ac);
    FUN_00797b80(local_100 + -8);
    return 0;
  }
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x2c) + 0x3c))();
  if (piVar1 == (int *)0x0) {
    FUN_0044a670(s_____EXCEPTION_____NULL_account_m_009d09d8);
    FUN_00797b80(local_100 + -8);
    return 0;
  }
  (**(code **)(*piVar1 + 8))(*(undefined4 *)(param_1 + 0x14));
  return 1;
}


// ==== FUN_006306f0 @ 0x006306f0 ====

undefined4 FUN_006306f0(int param_1)

{
  int *piVar1;
  int in_ECX;
  undefined2 extraout_var;
  undefined1 local_100 [256];
  
  if (*(int **)(in_ECX + 0x7c) == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d0b68,s_____EXCEPTION_____NULL_chaotic_m_009d0a00);
    FUN_00797b80(local_100);
    return 0;
  }
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x7c) + 0x14))();
  if (piVar1 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d0b68,s_____EXCEPTION_____NULL_chaotic_a_009d0a28);
    FUN_00797b80(local_100);
    return 0;
  }
  (**(code **)(*piVar1 + 0x24))(CONCAT22(extraout_var,*(undefined2 *)(param_1 + 0x42)));
  (**(code **)(*piVar1 + 0x30))(param_1);
  (**(code **)(*piVar1 + 0x1c))();
  return 1;
}


// ==== FUN_006307a0 @ 0x006307a0 ====

undefined4 FUN_006307a0(void)

{
  int in_ECX;
  undefined1 local_100 [256];
  
  if (*(int **)(in_ECX + 0x84) == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d0b68,s_____EXCEPTION_____NULL_pFishMana_009d0a50);
    FUN_00797b80(local_100);
    return 0;
  }
  (**(code **)(**(int **)(in_ECX + 0x84) + 0x14))();
  return 1;
}


// ==== FUN_006307f0 @ 0x006307f0 ====

undefined4 FUN_006307f0(int param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined2 uStack_10c;
  undefined2 uStack_10a;
  undefined2 uStack_108;
  undefined1 local_100 [256];
  
  if (*(int **)(in_ECX + 0x88) == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d0b68,s_____EXCEPTION_____NULL_pPVPManag_009d0a78);
    FUN_00797b80(local_100);
    return 0;
  }
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x88) + 0x14))();
  if (piVar1 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d0b68,s_____EXCEPTION_____NULL_pPVPManag_009d0a9c);
    FUN_00797b80(local_100);
    return 0;
  }
  uStack_110 = *(undefined4 *)(param_1 + 0x4c);
  uStack_10c = *(undefined2 *)(param_1 + 0x50);
  uStack_10a = *(undefined2 *)(param_1 + 0x52);
  uStack_114 = 0;
  uStack_108 = uStack_10a;
  (**(code **)(*piVar1 + 0x10))(&uStack_114);
  (**(code **)(*piVar1 + 100))(&uStack_114);
  return 1;
}


// ==== FUN_006308c0 @ 0x006308c0 ====

undefined4 FUN_006308c0(int param_1)

{
  byte bVar1;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (*(int **)(in_ECX + 0x20) == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d0b68,s_____EXCEPTION_____NULL_bag_009d0ac0);
    FUN_00797b80(local_100);
    return 0;
  }
  bVar1 = *(byte *)(param_1 + 0x48);
  if ((4 < bVar1) || (bVar1 < 2)) {
    bVar1 = 2;
    *(undefined4 *)(in_ECX + 0xfc) = 2;
  }
  (**(code **)(**(int **)(in_ECX + 0x20) + 0x6c))(bVar1);
  return 1;
}


// ==== FUN_00630940 @ 0x00630940 ====

undefined4 FUN_00630940(undefined4 *param_1)

{
  int *piVar1;
  int in_ECX;
  char *pcVar2;
  undefined1 local_100 [256];
  
  if (*(int **)(in_ECX + 0x90) == (int *)0x0) {
    pcVar2 = s_____EXCEPTION_____NULL_pAdvManag_009d0ae0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x90) + 0x14))();
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0xc))(*param_1);
      return 1;
    }
    pcVar2 = s_____EXCEPTION_____NULL_pAdventur_009d0b04;
  }
  FUN_0044a580(local_100,&DAT_009d0b68,pcVar2);
  FUN_00797b80(local_100);
  return 0;
}


// ==== FUN_006309b0 @ 0x006309b0 ====

undefined1 FUN_006309b0(undefined4 param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int *in_ECX;
  undefined4 unaff_ESI;
  
  piVar1 = in_ECX + 0x2d;
  cVar2 = (**(code **)(*DAT_00b5aa18 + 4))(param_1,piVar1);
  if (cVar2 == '\0') {
    return 0;
  }
  *(undefined1 *)(in_ECX + 0x2c) = 1;
  if ((int *)in_ECX[1] == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x18))();
  }
  (**(code **)(*piVar3 + 0xc))(*(undefined1 *)((int)in_ECX + 0xee));
  cVar2 = FUN_0062fbc0(piVar1);
  if (cVar2 != '\0') {
    cVar2 = FUN_00630270(piVar1);
    if (cVar2 != '\0') {
      cVar2 = FUN_006303d0(piVar1);
      if (cVar2 != '\0') {
        cVar2 = FUN_00630350(piVar1);
        if (cVar2 != '\0') {
          cVar2 = FUN_006305a0(piVar1);
          if (cVar2 != '\0') {
            cVar2 = FUN_00630450(piVar1);
            if (cVar2 != '\0') {
              cVar2 = FUN_0062fd70(piVar1);
              if (cVar2 != '\0') {
                cVar2 = FUN_0062fc40(piVar1,unaff_ESI);
                if (cVar2 != '\0') {
                  cVar2 = FUN_006306f0(piVar1,unaff_ESI);
                  if (cVar2 != '\0') {
                    cVar2 = FUN_006307a0();
                    if (cVar2 != '\0') {
                      cVar2 = FUN_006308c0(piVar1);
                      if (cVar2 != '\0') {
                        cVar2 = FUN_006307f0(piVar1);
                        if (cVar2 != '\0') {
                          cVar2 = FUN_0062fdb0(piVar1);
                          if (cVar2 != '\0') {
                            cVar2 = FUN_00630940(piVar1);
                            if (cVar2 != '\0') {
                              cVar2 = FUN_0062fe00(piVar1);
                              if (cVar2 != '\0') {
                                (**(code **)(*(int *)in_ECX[0x26] + 0x14))();
                                cVar2 = FUN_0062fe30(piVar1);
                                if (cVar2 != '\0') {
                                  cVar2 = FUN_0062fe70();
                                  if (cVar2 != '\0') {
                                    in_ECX[0x4b] = 0;
                                    in_ECX[0x4c] = 0;
                                    in_ECX[0x4e] = 0;
                                    in_ECX[0x4f] = 0;
                                    in_ECX[0x4d] = 0;
                                    in_ECX[0x50] = 0;
                                    in_ECX[0x51] = 0;
                                    *(undefined1 *)(in_ECX + 0x52) = 0;
                                    in_ECX[0x57] = 0;
                                    in_ECX[0x56] = 0;
                                    (**(code **)(*in_ECX + 0xe4))();
                                    FUN_005c8e90();
                                    return 1;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                *(undefined1 *)(in_ECX + 0x2c) = 0;
                return 0;
              }
            }
          }
        }
      }
    }
  }
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  return 0;
}


// ==== FUN_00630b50 @ 0x00630b50 ====

undefined4 FUN_00630b50(undefined4 param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int *in_ECX;
  
  piVar1 = in_ECX + 0x2d;
  FUN_00630cf0(param_1);
  *(undefined1 *)(in_ECX + 0x2c) = 1;
  if ((int *)in_ECX[1] == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x18))();
  }
  (**(code **)(*piVar3 + 0xc))(*(undefined1 *)((int)in_ECX + 0xee));
  cVar2 = FUN_0062fbc0(piVar1);
  if (cVar2 != '\0') {
    cVar2 = FUN_00630270(piVar1);
    if (cVar2 != '\0') {
      cVar2 = FUN_006303d0(piVar1);
      if (cVar2 != '\0') {
        cVar2 = FUN_00630350(piVar1);
        if (cVar2 != '\0') {
          cVar2 = FUN_006305a0(piVar1);
          if (cVar2 != '\0') {
            cVar2 = FUN_00630450(piVar1);
            if (cVar2 != '\0') {
              cVar2 = FUN_0062fd70(piVar1);
              if (cVar2 != '\0') {
                cVar2 = FUN_0062fc40(piVar1,param_1);
                if (cVar2 != '\0') {
                  cVar2 = FUN_006306f0(piVar1,param_1);
                  if (cVar2 != '\0') {
                    cVar2 = FUN_006307a0();
                    if (cVar2 != '\0') {
                      cVar2 = FUN_006307f0(piVar1);
                      if (cVar2 != '\0') {
                        cVar2 = FUN_0062fdb0(piVar1);
                        if (cVar2 != '\0') {
                          cVar2 = FUN_0062fe00(piVar1);
                          if (cVar2 != '\0') {
                            (**(code **)(*(int *)in_ECX[0x26] + 0x14))();
                            cVar2 = FUN_0062fe30(piVar1);
                            if (cVar2 != '\0') {
                              cVar2 = FUN_0062fe70();
                              if (cVar2 != '\0') {
                                in_ECX[0x4b] = 0;
                                in_ECX[0x4c] = 0;
                                in_ECX[0x4e] = 0;
                                in_ECX[0x4f] = 0;
                                in_ECX[0x4d] = 0;
                                in_ECX[0x50] = 0;
                                in_ECX[0x51] = 0;
                                *(undefined1 *)(in_ECX + 0x52) = 0;
                                in_ECX[0x57] = 0;
                                in_ECX[0x56] = 0;
                                (**(code **)(*in_ECX + 0xe4))();
                                FUN_005c8e90();
                                return 1;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                *(undefined1 *)(in_ECX + 0x2c) = 0;
                return 0;
              }
            }
          }
        }
      }
    }
  }
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  return 0;
}


// ==== FUN_00630cd0 @ 0x00630cd0 ====

void FUN_00630cd0(byte param_1)

{
  void *in_ECX;
  
  FUN_0062eed0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00630cf0 @ 0x00630cf0 ====

void FUN_00630cf0(undefined4 *param_1)

{
  char cVar1;
  undefined4 *in_ECX;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar4 = param_1;
  puVar5 = in_ECX;
  for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  uVar3 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar3 + 0x5c);
    *(char *)(uVar3 + 0x5c + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x19);
  *(undefined1 *)(in_ECX + 0x17) = 0;
  return;
}


// ==== FUN_00630d30 @ 0x00630d30 ====

void FUN_00630d30(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xac) = 0;
  return;
}


// ==== FUN_00630d40 @ 0x00630d40 ====

void FUN_00630d40(void)

{
  return;
}


// ==== FUN_00630d50 @ 0x00630d50 ====

int FUN_00630d50(void)

{
  int in_ECX;
  
  return in_ECX + 0xb2;
}


// ==== FUN_00630d60 @ 0x00630d60 ====

undefined4 FUN_00630d60(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xbc);
}


// ==== FUN_00630d70 @ 0x00630d70 ====

undefined4 FUN_00630d70(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc0);
}


// ==== FUN_00630d80 @ 0x00630d80 ====

void FUN_00630d80(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc0) = param_1;
  return;
}


// ==== FUN_00630d90 @ 0x00630d90 ====

undefined4 FUN_00630d90(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc4);
}


// ==== FUN_00630da0 @ 0x00630da0 ====

void FUN_00630da0(void)

{
  return;
}


// ==== FUN_00630dd0 @ 0x00630dd0 ====

void FUN_00630dd0(void)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a408;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = (int)&PTR_FUN_009d0d54;
  local_4 = 0;
  iVar1 = 0x2a;
  piVar2 = in_ECX;
  do {
    piVar2 = piVar2 + 1;
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 0xc))();
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      *piVar2 = 0;
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((undefined4 *)in_ECX[0x31] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x31])(1);
  }
  in_ECX[0x31] = 0;
  *in_ECX = (int)&PTR_FUN_009d02e4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00630e60 @ 0x00630e60 ====

void FUN_00630e60(void)

{
  char cVar1;
  int *in_ECX;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0x2a;
  piVar3 = in_ECX;
  do {
    piVar3 = piVar3 + 1;
    if (*piVar3 != 0) {
      (**(code **)(*(int *)*piVar3 + 0xc))();
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_00797a50((int)in_ECX + 0xb2,0,8);
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    (**(code **)(*(int *)in_ECX[0x31] + 0x2c))();
  }
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  return;
}


// ==== FUN_00630ec0 @ 0x00630ec0 ====

uint FUN_00630ec0(uint *param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  
  uVar3 = 0;
  uVar1 = (**(code **)(**(int **)(in_ECX + 0xbc) + 4))();
  if (*(char *)(uVar1 + 0x120) != '\0') {
    do {
      iVar2 = (**(code **)(**(int **)(in_ECX + 0xbc) + 4))();
      if ((uint)*(byte *)(iVar2 + 0x128 + uVar3 * 4) == *param_1) {
        return 1;
      }
      uVar3 = uVar3 + 1;
      iVar2 = (**(code **)(**(int **)(in_ECX + 0xbc) + 4))();
      uVar1 = (uint)*(byte *)(iVar2 + 0x120);
    } while (uVar3 < uVar1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00630f30 @ 0x00630f30 ====

void FUN_00630f30(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a425;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d0d54;
  pvVar1 = operator_new(0xa1c);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0064f280(in_ECX);
  }
  in_ECX[0x31] = uVar2;
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00797a50(in_ECX + 1,0,0xa8);
  pvVar1 = (void *)0x4;
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x12);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0xb,4);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x15,4);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  FUN_00797a50((int)in_ECX + 0xb2,0,8);
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  in_ECX[0x30] = 0;
  ExceptionList = pvVar1;
  return;
}


// ==== FUN_00631050 @ 0x00631050 ====

undefined4 FUN_00631050(undefined2 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  undefined4 uStack_118;
  undefined1 uStack_10e;
  undefined1 uStack_10d;
  undefined4 uStack_108;
  undefined2 uStack_104;
  undefined1 local_100 [256];
  
  piVar1 = *(int **)(in_ECX + 0x4c);
  if (piVar1 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d0d4c,s_>>>_ERROR_<<<_NULL_action_manage_009d0ca4);
    FUN_00797b80(local_100);
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_009d0ce4,
                         s___Creature_NPC_Provider_cpp_009d0cc8,0x90);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  piVar3 = (int *)(**(code **)(*piVar1 + 0x14))();
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d0d4c,s_>>>_ERROR_<<<_NULL_action_articl_009d0cf8);
    FUN_00797b80(local_100);
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_009d0d38,
                         s___Creature_NPC_Provider_cpp_009d0d1c,0x97);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  uStack_104 = *param_1;
  uStack_108 = 4;
  (**(code **)(*piVar1 + 0x1c))(&uStack_108);
  FUN_005e0c90(local_100 + -0x1c);
  FUN_00797a50(&uStack_118,0,0xc);
  uStack_10d = 1;
  uStack_118 = 0;
  uStack_10e = 0;
  (**(code **)(*piVar3 + 0x24))(&uStack_118);
  return 1;
}


// ==== FUN_00631170 @ 0x00631170 ====

undefined4 FUN_00631170(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined1 auStack_fe [254];
  
  (**(code **)(*in_ECX + 0xc))(param_1);
  *(undefined4 *)((int)in_ECX + 0xb2) = *param_1;
  uVar3 = param_1[1];
  *(undefined4 *)((int)in_ECX + 0xb6) = uVar3;
  iVar2 = (**(code **)(*DAT_00b5a770 + 8))
                    (CONCAT22((short)((uint)uVar3 >> 0x10),*(undefined2 *)param_1));
  if (iVar2 == 0) {
    FUN_0044a580(auStack_fe + -10,&DAT_009d0d4c,s_NPC_Flyweight_is_NULL____So_NPC_L_009d0c64);
    FUN_00797b80(auStack_fe + -10);
    return 0;
  }
  in_ECX[0x2f] = iVar2;
  *(undefined1 *)(in_ECX + 0x2c) = 1;
  cVar1 = FUN_00631050(param_1);
  if (cVar1 != '\0') {
    cVar1 = FUN_006312f0();
    if (cVar1 != '\0') {
      cVar1 = FUN_005c8e90();
      if (cVar1 == '\x01') {
        iVar2 = *(int *)in_ECX[0x31];
        uVar3 = (**(code **)(*DAT_00b5a690 + 4))();
        (**(code **)(iVar2 + 0x28))(uVar3);
      }
      return 1;
    }
  }
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  return 0;
}


// ==== FUN_00631250 @ 0x00631250 ====

void FUN_00631250(byte param_1)

{
  void *in_ECX;
  
  FUN_00630dd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00631270 @ 0x00631270 ====

undefined4 FUN_00631270(undefined2 param_1)

{
  int *piVar1;
  char cVar2;
  int in_ECX;
  char *pcVar3;
  undefined2 local_104 [130];
  
  piVar1 = *(int **)(in_ECX + 0x30);
  local_104[0] = param_1;
  cVar2 = (**(code **)(*piVar1 + 0x20))(local_104);
  if (cVar2 == '\0') {
    pcVar3 = s_Item_Shop_Open_Fail____LogicObje_009d0dbc;
  }
  else {
    cVar2 = (**(code **)(*piVar1 + 0x24))();
    if (cVar2 != '\0') {
      return 1;
    }
    pcVar3 = s_Item_Shop_Build_Fail____LogicObj_009d0d7c;
  }
  FUN_0044a580(local_104,&DAT_009d0d4c,pcVar3);
  FUN_00797b80(local_104);
  return 0;
}


// ==== FUN_006312f0 @ 0x006312f0 ====

bool FUN_006312f0(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  char *pcVar4;
  
  iVar2 = (**(code **)(**(int **)(in_ECX + 0xbc) + 4))();
  uVar3 = 0;
  if (*(uint *)(iVar2 + 0x178) != 0) {
    pcVar4 = (char *)(iVar2 + 0x128);
    do {
      if ((*pcVar4 == '\0') || (*pcVar4 == '!')) {
        cVar1 = FUN_00631270(CONCAT22((short)(uVar3 >> 0x10),
                                      *(undefined2 *)(iVar2 + 0x12a + uVar3 * 4)));
        return cVar1 != '\0';
      }
      uVar3 = uVar3 + 1;
      pcVar4 = pcVar4 + 4;
    } while (uVar3 < *(uint *)(iVar2 + 0x178));
  }
  return true;
}


// ==== FUN_00631370 @ 0x00631370 ====

void FUN_00631370(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00631378. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xbc) + 0x30))();
  return;
}


// ==== FUN_00631380 @ 0x00631380 ====

int FUN_00631380(void)

{
  int in_ECX;
  
  return in_ECX + 0xb2;
}


// ==== FUN_00631390 @ 0x00631390 ====

undefined4 FUN_00631390(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xb4);
}


// ==== FUN_006313a0 @ 0x006313a0 ====

undefined4 FUN_006313a0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xb8);
}


// ==== FUN_006313b0 @ 0x006313b0 ====

void FUN_006313b0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xb8) = param_1;
  return;
}


// ==== FUN_006313c0 @ 0x006313c0 ====

undefined4 FUN_006313c0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xbc);
}


// ==== FUN_006313f0 @ 0x006313f0 ====

void FUN_006313f0(void)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a438;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = (int)&PTR_FUN_009d1030;
  local_4 = 0;
  iVar1 = 0x2a;
  piVar2 = in_ECX;
  do {
    piVar2 = piVar2 + 1;
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 0xc))();
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      *piVar2 = 0;
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((undefined4 *)in_ECX[0x2f] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x2f])(1);
  }
  in_ECX[0x2f] = 0;
  *in_ECX = (int)&PTR_FUN_009d02e4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00631480 @ 0x00631480 ====

void FUN_00631480(void)

{
  char cVar1;
  int *in_ECX;
  int iVar2;
  int *piVar3;
  
  FUN_00797a50((int)in_ECX + 0xb2,0,2);
  iVar2 = 0x2a;
  piVar3 = in_ECX;
  do {
    piVar3 = piVar3 + 1;
    if (*piVar3 != 0) {
      (**(code **)(*(int *)*piVar3 + 0xc))();
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
                    /* WARNING: Could not recover jumptable at 0x006314cf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)in_ECX[0x2f] + 0x2c))();
    return;
  }
  return;
}


// ==== FUN_006314e0 @ 0x006314e0 ====

void FUN_006314e0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5abd0 + 8))(*(undefined2 *)(in_ECX + 0xb2));
                    /* WARNING: Could not recover jumptable at 0x006314f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 4))();
  return;
}


// ==== FUN_00631500 @ 0x00631500 ====

undefined4 FUN_00631500(undefined2 *param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  undefined1 auStack_46 [70];
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x44) + 0x14))();
  piVar2 = (int *)(**(code **)(*DAT_00b5abd0 + 8))(*param_1);
  (**(code **)(*piVar2 + 4))();
  (**(code **)(*piVar1 + 8))(auStack_46 + -6);
  return 1;
}


// ==== FUN_00631570 @ 0x00631570 ====

undefined4 FUN_00631570(undefined2 *param_1)

{
  int in_ECX;
  undefined4 local_8;
  undefined2 local_4;
  
  local_4 = *param_1;
  local_8 = 3;
  (**(code **)(**(int **)(in_ECX + 0x4c) + 0x1c))(&local_8);
  return 1;
}


// ==== FUN_006315a0 @ 0x006315a0 ====

void FUN_006315a0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a455;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d1030;
  pvVar1 = operator_new(0x51c);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0064f770(in_ECX);
  }
  in_ECX[0x2f] = uVar2;
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00797a50(in_ECX + 1,0,0xa8);
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x10,3);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x13,3);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x12,3);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(1);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(3,3);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(4,3);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  FUN_00797a50((int)in_ECX + 0xb2,0,2);
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  in_ECX[0x2e] = 0;
  ExceptionList = (void *)0x3;
  return;
}


// ==== FUN_00631740 @ 0x00631740 ====

undefined4 FUN_00631740(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int in_ECX;
  undefined2 *unaff_retaddr;
  undefined1 local_100 [2];
  undefined1 auStack_fe [254];
  
  piVar2 = *(int **)(in_ECX + 0x50);
  if (piVar2 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d1028,s_____EXCEPTION_____NULL_state_man_009d0e00);
    FUN_00797b80(local_100);
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009d0e48,
                         s___Creature_Guard_Provider_cpp_009d0e28,0xdf);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = (int *)(**(code **)(*piVar2 + 0x14))(10);
  if (piVar2 == (int *)0x0) {
    FUN_0044a580(local_100 + -4,&DAT_009d1028,s_____EXCEPTION_____NULL_state_art_009d0e5c);
    FUN_00797b80(local_100 + -4);
    uVar1 = FUN_0044a580(local_100 + -4,s_File___s__Line___d_009d0ea4,
                         s___Creature_Guard_Provider_cpp_009d0e84,0xe5);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar3 = *(int **)(in_ECX + 0x44);
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100 + -4,&DAT_009d1028,s_____EXCEPTION_____NULL_point_man_009d0eb8);
    FUN_00797b80(local_100 + -4);
    uVar1 = FUN_0044a580(local_100 + -4,s_File___s__Line___d_009d0f00,
                         s___Creature_Guard_Provider_cpp_009d0ee0,0xeb);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar3 = (int *)(**(code **)(*piVar3 + 0x14))();
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100 + -4,&DAT_009d1028,s_____EXCEPTION_____NULL_point_art_009d0f14);
    FUN_00797b80(local_100 + -4);
    uVar1 = FUN_0044a580(local_100 + -4,s_File___s__Line___d_009d0f5c,
                         s___Creature_Guard_Provider_cpp_009d0f3c,0xf1);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar4 = (int *)(**(code **)(*DAT_00b5abd0 + 8))(*unaff_retaddr);
  iVar5 = (**(code **)(*piVar4 + 4))();
  (**(code **)(*piVar2 + 0x6c))((float)*(int *)(iVar5 + 0x28));
  (**(code **)(*piVar2 + 0x8c))(0);
  puVar6 = (undefined4 *)(**(code **)(*piVar2 + 0x18))();
  (**(code **)(*piVar3 + 0x14))(*puVar6);
  iVar5 = *piVar3;
  iVar7 = (**(code **)(*piVar2 + 0x18))();
  (**(code **)(iVar5 + 0x1c))(*(undefined4 *)(iVar7 + 0xc));
  (**(code **)(*piVar3 + 0x34))(0);
  return 1;
}


// ==== FUN_00631910 @ 0x00631910 ====

undefined4 FUN_00631910(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *in_ECX;
  undefined1 local_100 [256];
  
  piVar3 = (int *)in_ECX[2];
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d1028,s_____EXCEPTION_____NULL_state_man_009d0f70);
    FUN_00797b80(local_100);
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_009d0fb8,
                         s___Creature_Guard_Provider_cpp_009d0f98,0x10d);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  piVar3 = (int *)(**(code **)(*piVar3 + 0x14))();
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d1028,s_____EXCEPTION_____NULL_state_art_009d0fcc);
    FUN_00797b80(local_100);
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_009d1014,
                         s___Creature_Guard_Provider_cpp_009d0ff4,0x113);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  piVar4 = (int *)(**(code **)(*in_ECX + 0x20))();
  iVar1 = *piVar3;
  iVar5 = (**(code **)(*piVar4 + 4))();
  (**(code **)(iVar1 + 0x14))(*(undefined1 *)(iVar5 + 0x1c));
  return 1;
}


// ==== FUN_006319f0 @ 0x006319f0 ====

undefined4 FUN_006319f0(undefined2 *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xc))(param_1);
  *(undefined2 *)((int)in_ECX + 0xb2) = *param_1;
  *(undefined1 *)(in_ECX + 0x2c) = 1;
  iVar2 = (**(code **)(*DAT_00b5abd0 + 8))(*param_1);
  in_ECX[0x2d] = iVar2;
  if (iVar2 != 0) {
    cVar1 = FUN_00631500(param_1);
    if (cVar1 != '\0') {
      cVar1 = FUN_00631740(param_1);
      if (cVar1 != '\0') {
        cVar1 = FUN_00631910(param_1);
        if (cVar1 != '\0') {
          cVar1 = FUN_00631570(param_1);
          if (cVar1 != '\0') {
            *(undefined2 *)((int)in_ECX + 0xb2) = *param_1;
            *(undefined1 *)(in_ECX + 0x2c) = 1;
            cVar1 = FUN_005c8e90();
            if (cVar1 == '\x01') {
              iVar2 = *(int *)in_ECX[0x2f];
              uVar3 = (**(code **)(*DAT_00b5a690 + 4))();
              (**(code **)(iVar2 + 0x28))(uVar3);
            }
            return 1;
          }
        }
      }
    }
  }
  return 0;
}


// ==== FUN_00631ab0 @ 0x00631ab0 ====

void FUN_00631ab0(byte param_1)

{
  void *in_ECX;
  
  FUN_006313f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00631af0 @ 0x00631af0 ====

int FUN_00631af0(void)

{
  int in_ECX;
  
  return in_ECX + 0xb6;
}


// ==== FUN_00631b00 @ 0x00631b00 ====

undefined4 FUN_00631b00(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xbc);
}


// ==== FUN_00631b10 @ 0x00631b10 ====

undefined4 FUN_00631b10(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xb0);
}


// ==== FUN_00631b20 @ 0x00631b20 ====

undefined4 FUN_00631b20(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc0);
}


// ==== FUN_00631b30 @ 0x00631b30 ====

void FUN_00631b30(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc0) = param_1;
  (**(code **)(**(int **)(in_ECX + 0xc4) + 0x10))();
  return;
}


// ==== FUN_00631b50 @ 0x00631b50 ====

undefined4 FUN_00631b50(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc4);
}


// ==== FUN_00631b60 @ 0x00631b60 ====

void FUN_00631b60(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00631b68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc4) + 0x30))();
  return;
}


// ==== FUN_00631b70 @ 0x00631b70 ====

void FUN_00631b70(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xb8) = *param_1;
  return;
}


// ==== FUN_00631b80 @ 0x00631b80 ====

void FUN_00631b80(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xba) = 1;
  return;
}


// ==== FUN_00631b90 @ 0x00631b90 ====

void FUN_00631b90(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xba) = 0;
  return;
}


// ==== FUN_00631ba0 @ 0x00631ba0 ====

undefined1 FUN_00631ba0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0xba);
}


// ==== FUN_00631bb0 @ 0x00631bb0 ====

void FUN_00631bb0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xba) = param_1;
  return;
}


// ==== FUN_00631bc0 @ 0x00631bc0 ====

void FUN_00631bc0(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0xb8) = param_1;
  return;
}


// ==== FUN_00631bd0 @ 0x00631bd0 ====

undefined2 FUN_00631bd0(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0xb8);
}


// ==== FUN_00631c00 @ 0x00631c00 ====

void FUN_00631c00(void)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a468;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = (int)&PTR_FUN_009d128c;
  local_4 = 0;
  iVar1 = 0x2a;
  piVar2 = in_ECX;
  do {
    piVar2 = piVar2 + 1;
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 0xc))();
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      *piVar2 = 0;
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((undefined4 *)in_ECX[0x31] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x31])(1);
  }
  in_ECX[0x31] = 0;
  *in_ECX = (int)&PTR_FUN_009d02e4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00631c90 @ 0x00631c90 ====

void FUN_00631c90(void)

{
  char cVar1;
  int *in_ECX;
  int iVar2;
  int *piVar3;
  
  FUN_00797a50((int)in_ECX + 0xb6,0,6);
  iVar2 = 0x2a;
  piVar3 = in_ECX;
  do {
    piVar3 = piVar3 + 1;
    if (*piVar3 != 0) {
      (**(code **)(*(int *)*piVar3 + 0xc))();
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined1 *)(in_ECX + 0x2d) = 0;
  in_ECX[0x2c] = 0;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
                    /* WARNING: Could not recover jumptable at 0x00631ce9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)in_ECX[0x31] + 0x2c))();
    return;
  }
  return;
}


// ==== FUN_00631cf0 @ 0x00631cf0 ====

void FUN_00631cf0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5abd4 + 8))(*(undefined2 *)(in_ECX + 0xb6));
                    /* WARNING: Could not recover jumptable at 0x00631d08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 4))();
  return;
}


// ==== FUN_00631d10 @ 0x00631d10 ====

undefined4 FUN_00631d10(undefined2 *param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  undefined1 auStack_46 [70];
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x44) + 0x14))();
  piVar2 = (int *)(**(code **)(*DAT_00b5abd4 + 8))(*param_1);
  (**(code **)(*piVar2 + 4))();
  (**(code **)(*piVar1 + 8))(auStack_46 + -6);
  return 1;
}


// ==== FUN_00631d80 @ 0x00631d80 ====

undefined4 FUN_00631d80(undefined2 *param_1)

{
  int in_ECX;
  undefined4 local_8;
  undefined2 local_4;
  
  local_4 = *param_1;
  local_8 = 2;
  (**(code **)(**(int **)(in_ECX + 0x4c) + 0x1c))(&local_8);
  return 1;
}


// ==== FUN_00631db0 @ 0x00631db0 ====

void FUN_00631db0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a485;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d128c;
  pvVar1 = operator_new(0x51c);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00650b30(in_ECX);
  }
  in_ECX[0x31] = uVar2;
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00797a50(in_ECX + 1,0,0xa8);
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x10,2);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x13,2);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x12,2);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(1);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(3,2);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(4,2);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  FUN_00797a50((int)in_ECX + 0xb6,0,6);
  *(undefined1 *)(in_ECX + 0x2d) = 0;
  in_ECX[0x2c] = 0;
  in_ECX[0x30] = 0;
  ExceptionList = (void *)0x2;
  return;
}


// ==== FUN_00631f60 @ 0x00631f60 ====

undefined4 FUN_00631f60(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int in_ECX;
  undefined2 *unaff_retaddr;
  undefined1 local_100 [2];
  undefined1 auStack_fe [254];
  
  piVar2 = *(int **)(in_ECX + 0x50);
  if (piVar2 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d1284,s_____EXCEPTION_____NULL_state_man_009d105c);
    FUN_00797b80(local_100);
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009d10a4,
                         s___Creature_Servant_Provider_cpp_009d1084,0x113);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = (int *)(**(code **)(*piVar2 + 0x14))(10);
  if (piVar2 == (int *)0x0) {
    FUN_0044a580(local_100 + -4,&DAT_009d1284,s_____EXCEPTION_____NULL_state_art_009d10b8);
    FUN_00797b80(local_100 + -4);
    uVar1 = FUN_0044a580(local_100 + -4,s_File___s__Line___d_009d1100,
                         s___Creature_Servant_Provider_cpp_009d10e0,0x119);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar3 = *(int **)(in_ECX + 0x44);
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100 + -4,&DAT_009d1284,s_____EXCEPTION_____NULL_point_man_009d1114);
    FUN_00797b80(local_100 + -4);
    uVar1 = FUN_0044a580(local_100 + -4,s_File___s__Line___d_009d115c,
                         s___Creature_Servant_Provider_cpp_009d113c,0x11f);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar3 = (int *)(**(code **)(*piVar3 + 0x14))();
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100 + -4,&DAT_009d1284,s_____EXCEPTION_____NULL_point_art_009d1170);
    FUN_00797b80(local_100 + -4);
    uVar1 = FUN_0044a580(local_100 + -4,s_File___s__Line___d_009d11b8,
                         s___Creature_Servant_Provider_cpp_009d1198,0x125);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar4 = (int *)(**(code **)(*DAT_00b5abd4 + 8))(*unaff_retaddr);
  iVar5 = (**(code **)(*piVar4 + 4))();
  (**(code **)(*piVar2 + 0x6c))((float)*(int *)(iVar5 + 0x30));
  (**(code **)(*piVar2 + 0x8c))(0);
  puVar6 = (undefined4 *)(**(code **)(*piVar2 + 0x18))();
  (**(code **)(*piVar3 + 0x14))(*puVar6);
  iVar5 = *piVar3;
  iVar7 = (**(code **)(*piVar2 + 0x18))();
  (**(code **)(iVar5 + 0x1c))(*(undefined4 *)(iVar7 + 0xc));
  (**(code **)(*piVar3 + 0x34))(0);
  return 1;
}


// ==== FUN_00632130 @ 0x00632130 ====

undefined4 FUN_00632130(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *in_ECX;
  undefined1 local_100 [256];
  
  piVar3 = (int *)in_ECX[2];
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d1284,s_____EXCEPTION_____NULL_state_man_009d11cc);
    FUN_00797b80(local_100);
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_009d1214,
                         s___Creature_Servant_Provider_cpp_009d11f4,0x141);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  piVar3 = (int *)(**(code **)(*piVar3 + 0x14))();
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d1284,s_____EXCEPTION_____NULL_state_art_009d1228);
    FUN_00797b80(local_100);
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_009d1270,
                         s___Creature_Servant_Provider_cpp_009d1250,0x147);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  piVar4 = (int *)(**(code **)(*in_ECX + 0x24))();
  iVar1 = *piVar3;
  iVar5 = (**(code **)(*piVar4 + 4))();
  (**(code **)(iVar1 + 0x14))(*(undefined1 *)(iVar5 + 0x24));
  return 1;
}


// ==== FUN_00632210 @ 0x00632210 ====

undefined4 FUN_00632210(undefined4 *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xc))(param_1);
  *(undefined4 *)((int)in_ECX + 0xb6) = *param_1;
  *(undefined2 *)((int)in_ECX + 0xba) = *(undefined2 *)(param_1 + 1);
  *(undefined1 *)(in_ECX + 0x2d) = 1;
  in_ECX[0x2c] = param_2;
  iVar2 = (**(code **)(*DAT_00b5abd4 + 8))(*(undefined2 *)param_1);
  in_ECX[0x2f] = iVar2;
  if (iVar2 != 0) {
    cVar1 = FUN_00631d10(param_1);
    if (cVar1 != '\0') {
      cVar1 = FUN_00631f60(param_1);
      if (cVar1 != '\0') {
        cVar1 = FUN_00632130(param_1);
        if (cVar1 != '\0') {
          cVar1 = FUN_00631d80(param_1);
          if (cVar1 != '\0') {
            *(undefined4 *)((int)in_ECX + 0xb6) = *param_1;
            *(undefined2 *)((int)in_ECX + 0xba) = *(undefined2 *)(param_1 + 1);
            *(undefined1 *)(in_ECX + 0x2d) = 1;
            cVar1 = FUN_005c8e90();
            if (cVar1 == '\x01') {
              iVar2 = *(int *)in_ECX[0x31];
              uVar3 = (**(code **)(*DAT_00b5a690 + 4))();
              (**(code **)(iVar2 + 0x28))(uVar3);
            }
            return 1;
          }
        }
      }
    }
  }
  return 0;
}


// ==== FUN_006322e0 @ 0x006322e0 ====

void FUN_006322e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00631c00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00632300 @ 0x00632300 ====

void FUN_00632300(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xac) = 0;
  return;
}


// ==== FUN_00632310 @ 0x00632310 ====

void FUN_00632310(void)

{
  return;
}


// ==== FUN_00632320 @ 0x00632320 ====

int FUN_00632320(void)

{
  int in_ECX;
  
  return in_ECX + 0xb2;
}


// ==== FUN_00632330 @ 0x00632330 ====

undefined4 FUN_00632330(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xb4);
}


// ==== FUN_00632340 @ 0x00632340 ====

undefined4 FUN_00632340(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xb8);
}


// ==== FUN_00632350 @ 0x00632350 ====

void FUN_00632350(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xb8) = param_1;
  return;
}


// ==== FUN_00632360 @ 0x00632360 ====

undefined4 FUN_00632360(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xbc);
}


// ==== FUN_00632370 @ 0x00632370 ====

void FUN_00632370(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00632378. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xbc) + 0x30))();
  return;
}


// ==== FUN_006323a0 @ 0x006323a0 ====

void FUN_006323a0(void)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a498;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = (int)&PTR_FUN_009d1508;
  local_4 = 0;
  iVar1 = 0x2a;
  piVar2 = in_ECX;
  do {
    piVar2 = piVar2 + 1;
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 0xc))();
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      *piVar2 = 0;
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((undefined4 *)in_ECX[0x2f] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x2f])(1);
  }
  in_ECX[0x2f] = 0;
  *in_ECX = (int)&PTR_FUN_009d02e4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00632430 @ 0x00632430 ====

void FUN_00632430(void)

{
  char cVar1;
  int *in_ECX;
  int iVar2;
  int *piVar3;
  
  FUN_00797a50((int)in_ECX + 0xb2,0,2);
  iVar2 = 0x2a;
  piVar3 = in_ECX;
  do {
    piVar3 = piVar3 + 1;
    if (*piVar3 != 0) {
      (**(code **)(*(int *)*piVar3 + 0xc))();
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    (**(code **)(*(int *)in_ECX[0x2f] + 0x2c))();
  }
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  return;
}


// ==== FUN_00632490 @ 0x00632490 ====

undefined4 FUN_00632490(undefined2 *param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  undefined1 auStack_46 [70];
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x44) + 0x14))();
  piVar2 = (int *)(**(code **)(*DAT_00b5a75c + 8))(*param_1);
  (**(code **)(*piVar2 + 4))();
  (**(code **)(*piVar1 + 8))(auStack_46 + -6);
  return 1;
}


// ==== FUN_00632500 @ 0x00632500 ====

undefined4 FUN_00632500(undefined2 *param_1)

{
  int in_ECX;
  undefined4 local_8;
  undefined2 local_4;
  
  local_4 = *param_1;
  local_8 = 1;
  (**(code **)(**(int **)(in_ECX + 0x4c) + 0x1c))(&local_8);
  return 1;
}


// ==== FUN_00632530 @ 0x00632530 ====

void FUN_00632530(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a75c + 8))(*(undefined2 *)(in_ECX + 0xb2));
                    /* WARNING: Could not recover jumptable at 0x00632548. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 4))();
  return;
}


// ==== FUN_00632550 @ 0x00632550 ====

void FUN_00632550(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a4b5;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d1508;
  pvVar1 = operator_new(0x51c);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00651f80(in_ECX);
  }
  in_ECX[0x2f] = uVar2;
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00797a50(in_ECX + 1,0,0xa8);
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x10,1);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x13,1);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x12,1);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(1);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(3,1);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(4,1);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  FUN_00797a50((int)in_ECX + 0xb2,0,2);
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  in_ECX[0x2e] = 0;
  ExceptionList = (void *)0x1;
  return;
}


// ==== FUN_006326f0 @ 0x006326f0 ====

undefined4 FUN_006326f0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int in_ECX;
  undefined2 *unaff_retaddr;
  undefined1 local_100 [2];
  undefined1 auStack_fe [254];
  
  piVar2 = *(int **)(in_ECX + 0x50);
  if (piVar2 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d1500,s_____EXCEPTION_____NULL_state_man_009d12d8);
    FUN_00797b80(local_100);
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009d1320,
                         s___Creature_Monster_Provider_cpp_009d1300,0xc0);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = (int *)(**(code **)(*piVar2 + 0x14))(10);
  if (piVar2 == (int *)0x0) {
    FUN_0044a580(local_100 + -4,&DAT_009d1500,s_____EXCEPTION_____NULL_state_art_009d1334);
    FUN_00797b80(local_100 + -4);
    uVar1 = FUN_0044a580(local_100 + -4,s_File___s__Line___d_009d137c,
                         s___Creature_Monster_Provider_cpp_009d135c,0xc6);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar3 = *(int **)(in_ECX + 0x44);
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100 + -4,&DAT_009d1500,s_____EXCEPTION_____NULL_point_man_009d1390);
    FUN_00797b80(local_100 + -4);
    uVar1 = FUN_0044a580(local_100 + -4,s_File___s__Line___d_009d13d8,
                         s___Creature_Monster_Provider_cpp_009d13b8,0xcc);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar3 = (int *)(**(code **)(*piVar3 + 0x14))();
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100 + -4,&DAT_009d1500,s_____EXCEPTION_____NULL_point_art_009d13ec);
    FUN_00797b80(local_100 + -4);
    uVar1 = FUN_0044a580(local_100 + -4,s_File___s__Line___d_009d1434,
                         s___Creature_Monster_Provider_cpp_009d1414,0xd2);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar4 = (int *)(**(code **)(*DAT_00b5a75c + 8))(*unaff_retaddr);
  iVar5 = (**(code **)(*piVar4 + 4))();
  (**(code **)(*piVar2 + 0x6c))((float)*(int *)(iVar5 + 0x50));
  puVar6 = (undefined4 *)(**(code **)(*piVar2 + 0x18))();
  (**(code **)(*piVar3 + 0x14))(*puVar6);
  (**(code **)(*piVar3 + 0x18))(0);
  iVar5 = *piVar3;
  iVar7 = (**(code **)(*piVar2 + 0x18))();
  (**(code **)(iVar5 + 0x1c))(*(undefined4 *)(iVar7 + 0xc));
  (**(code **)(*piVar2 + 0x8c))(0);
  (**(code **)(*piVar3 + 0x2c))(0);
  (**(code **)(*piVar3 + 0x30))(0);
  (**(code **)(*piVar3 + 0x34))(0);
  return 1;
}


// ==== FUN_006328e0 @ 0x006328e0 ====

undefined4 FUN_006328e0(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *in_ECX;
  undefined1 local_100 [256];
  
  piVar3 = (int *)in_ECX[2];
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d1500,s_____EXCEPTION_____NULL_state_man_009d1448);
    FUN_00797b80(local_100);
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_009d1490,
                         s___Creature_Monster_Provider_cpp_009d1470,0xf1);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  piVar3 = (int *)(**(code **)(*piVar3 + 0x14))();
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d1500,s_____EXCEPTION_____NULL_state_art_009d14a4);
    FUN_00797b80(local_100);
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_009d14ec,
                         s___Creature_Monster_Provider_cpp_009d14cc,0xf7);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  piVar4 = (int *)(**(code **)(*in_ECX + 0x20))();
  iVar1 = *piVar3;
  iVar5 = (**(code **)(*piVar4 + 4))();
  (**(code **)(iVar1 + 0x14))(*(undefined1 *)(iVar5 + 0x44));
  return 1;
}


// ==== FUN_006329c0 @ 0x006329c0 ====

undefined4 FUN_006329c0(undefined2 *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xc))(param_1);
  *(undefined2 *)((int)in_ECX + 0xb2) = *param_1;
  *(undefined1 *)(in_ECX + 0x2c) = 1;
  iVar2 = (**(code **)(*DAT_00b5a75c + 8))(*param_1);
  in_ECX[0x2d] = iVar2;
  if (iVar2 != 0) {
    cVar1 = FUN_00632490(param_1);
    if (cVar1 != '\0') {
      cVar1 = FUN_006326f0(param_1);
      if (cVar1 != '\0') {
        cVar1 = FUN_006328e0(param_1);
        if (cVar1 != '\0') {
          cVar1 = FUN_00632500(param_1);
          if (cVar1 != '\0') {
            cVar1 = FUN_005c8e90();
            if (cVar1 == '\x01') {
              iVar2 = *(int *)in_ECX[0x2f];
              uVar3 = (**(code **)(*DAT_00b5a690 + 4))();
              (**(code **)(iVar2 + 0x28))(uVar3);
            }
            return 1;
          }
        }
      }
    }
  }
  return 0;
}


// ==== FUN_00632a70 @ 0x00632a70 ====

void FUN_00632a70(byte param_1)

{
  void *in_ECX;
  
  FUN_006323a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00632a90 @ 0x00632a90 ====

void FUN_00632a90(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xac) = 0;
  return;
}


// ==== FUN_00632aa0 @ 0x00632aa0 ====

void FUN_00632aa0(void)

{
  return;
}


// ==== FUN_00632ab0 @ 0x00632ab0 ====

int FUN_00632ab0(void)

{
  int in_ECX;
  
  return in_ECX + 0xb4;
}


// ==== FUN_00632ac0 @ 0x00632ac0 ====

undefined4 FUN_00632ac0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xb8);
}


// ==== FUN_00632ad0 @ 0x00632ad0 ====

void FUN_00632ad0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xb8) = param_1;
  return;
}


// ==== FUN_00632ae0 @ 0x00632ae0 ====

undefined4 FUN_00632ae0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xbc);
}


// ==== FUN_00632af0 @ 0x00632af0 ====

void FUN_00632af0(void)

{
  return;
}


// ==== FUN_00632b20 @ 0x00632b20 ====

void FUN_00632b20(void)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a4c8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = (int)&PTR_FUN_009d1534;
  local_4 = 0;
  iVar1 = 0x2a;
  piVar2 = in_ECX;
  do {
    piVar2 = piVar2 + 1;
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 0xc))();
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      *piVar2 = 0;
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((undefined4 *)in_ECX[0x2f] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x2f])(1);
  }
  in_ECX[0x2f] = 0;
  *in_ECX = (int)&PTR_FUN_009d02e4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00632bb0 @ 0x00632bb0 ====

void FUN_00632bb0(void)

{
  char cVar1;
  int *in_ECX;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0x2a;
  piVar2 = in_ECX;
  do {
    piVar2 = piVar2 + 1;
    if (*piVar2 != 0) {
      (**(code **)(*(int *)*piVar2 + 0xc))();
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    (**(code **)(*(int *)in_ECX[0x2f] + 0x2c))();
  }
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  return;
}


// ==== FUN_00632c00 @ 0x00632c00 ====

undefined4 FUN_00632c00(void)

{
  int in_ECX;
  undefined4 local_8;
  undefined2 local_4;
  
  local_8 = 10;
  local_4 = 0;
  (**(code **)(**(int **)(in_ECX + 0x4c) + 0x1c))(&local_8);
  return 1;
}


// ==== FUN_00632c30 @ 0x00632c30 ====

void FUN_00632c30(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *in_ECX;
  void *unaff_ESI;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a4e5;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d1534;
  pvVar1 = operator_new(0xa1c);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006533d0(in_ECX);
  }
  in_ECX[0x2f] = uVar2;
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00797a50(in_ECX + 1,0,0xa8);
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(6,10);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x12,1);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  FUN_00797a50(in_ECX + 0x2d,0,4);
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  in_ECX[0x2e] = 0;
  ExceptionList = unaff_ESI;
  return;
}


// ==== FUN_00632d30 @ 0x00632d30 ====

undefined4 FUN_00632d30(int *param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined4 uStack_1c;
  int *piStack_18;
  
  piStack_18 = param_1;
  uStack_1c = 0x632d44;
  (**(code **)(*in_ECX + 0xc))();
  in_ECX[0x2d] = *param_1;
  uStack_1c = 0;
  piVar3 = (int *)(**(code **)(*DAT_00b5a778 + 0xc))(1);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*piVar3 + 0xc))(*param_1);
  (**(code **)(*(int *)in_ECX[7] + 0x14))(piVar3);
  uStack_1c = 10;
  piStack_18 = (int *)((uint)piStack_18 & 0xffff0000);
  (**(code **)(*(int *)in_ECX[0x13] + 0x1c))(&uStack_1c);
  *(undefined1 *)(in_ECX + 0x2c) = 1;
  cVar2 = FUN_005c8e90();
  if (cVar2 == '\x01') {
    iVar1 = *(int *)in_ECX[0x2f];
    uVar4 = (**(code **)(*DAT_00b5a690 + 4))();
    (**(code **)(iVar1 + 0x28))(uVar4);
  }
  return 1;
}


// ==== FUN_00632de0 @ 0x00632de0 ====

void FUN_00632de0(byte param_1)

{
  void *in_ECX;
  
  FUN_00632b20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00632e00 @ 0x00632e00 ====

void FUN_00632e00(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xac) = 0;
  return;
}


// ==== FUN_00632e10 @ 0x00632e10 ====

void FUN_00632e10(void)

{
  return;
}


// ==== FUN_00632e20 @ 0x00632e20 ====

int FUN_00632e20(void)

{
  int in_ECX;
  
  return in_ECX + 300;
}


// ==== FUN_00632e30 @ 0x00632e30 ====

void FUN_00632e30(void)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
                    /* WARNING: Could not recover jumptable at 0x00632e45. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 0x15c) + 0x2c))();
    return;
  }
  return;
}


// ==== FUN_00632e50 @ 0x00632e50 ====

undefined4 FUN_00632e50(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x158);
}


// ==== FUN_00632e60 @ 0x00632e60 ====

void FUN_00632e60(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x158) = param_1;
  return;
}


// ==== FUN_00632e70 @ 0x00632e70 ====

undefined4 FUN_00632e70(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x15c);
}


// ==== FUN_00632e80 @ 0x00632e80 ====

void FUN_00632e80(void)

{
  return;
}


// ==== FUN_00632e90 @ 0x00632e90 ====

void FUN_00632e90(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 0xce);
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== FUN_00632eb0 @ 0x00632eb0 ====

void FUN_00632eb0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xfa) = param_1;
  return;
}


// ==== FUN_00632ec0 @ 0x00632ec0 ====

void FUN_00632ec0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xfc) = param_1;
  return;
}


// ==== FUN_00632ed0 @ 0x00632ed0 ====

void FUN_00632ed0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x100) = *param_1;
  *(undefined4 *)(in_ECX + 0x104) = param_1[1];
  *(undefined4 *)(in_ECX + 0x108) = param_1[2];
  return;
}


// ==== FUN_00632ef0 @ 0x00632ef0 ====

void FUN_00632ef0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10c) = *param_1;
  return;
}


// ==== FUN_00632f00 @ 0x00632f00 ====

void FUN_00632f00(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x129) = param_1;
  return;
}


// ==== FUN_00632f10 @ 0x00632f10 ====

void FUN_00632f10(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x12a) = param_1;
  return;
}


// ==== FUN_00632f40 @ 0x00632f40 ====

void FUN_00632f40(void)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a4f8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = (int)&PTR_FUN_009d1594;
  local_4 = 0;
  iVar1 = 0x2a;
  piVar2 = in_ECX;
  do {
    piVar2 = piVar2 + 1;
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 0xc))();
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      *piVar2 = 0;
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((undefined4 *)in_ECX[0x57] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x57])(1);
  }
  in_ECX[0x57] = 0;
  *in_ECX = (int)&PTR_FUN_009d02e4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00632fd0 @ 0x00632fd0 ====

int FUN_00632fd0(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  if (*(int **)(in_ECX + 0x4c) == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar3 + 8))(param_1);
  puVar1 = (undefined4 *)(**(code **)(*piVar3 + 0x10))();
  puVar4 = (undefined4 *)(in_ECX + 0x110);
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar4 = puVar4 + 1;
  }
  *(undefined1 *)puVar4 = *(undefined1 *)puVar1;
  return in_ECX + 0xb4;
}


// ==== FUN_00633020 @ 0x00633020 ====

undefined4 FUN_00633020(int param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_8;
  ushort local_4;
  
  local_4 = (ushort)*(byte *)(param_1 + 0x44);
  local_8 = 0;
  (**(code **)(**(int **)(in_ECX + 0x4c) + 0x1c))(&local_8);
  if (*(int **)(in_ECX + 0x4c) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar1 + 0x24))(param_1 + 0x5c);
  return 1;
}


// ==== FUN_00633070 @ 0x00633070 ====

void FUN_00633070(void)

{
  char *pcVar1;
  char cVar2;
  void *pvVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *in_ECX;
  uint uVar8;
  char acStack_52 [6];
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a515;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d1594;
  *(undefined1 *)(in_ECX + 0x2d) = 0;
  pcVar1 = (char *)(in_ECX + 0x4b);
  local_4 = 0;
  *pcVar1 = '\0';
  pvVar3 = operator_new(0xa20);
  local_4._0_1_ = 1;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00653950();
  }
  in_ECX[0x57] = uVar4;
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00797a50();
  piVar5 = (int *)(**(code **)(*DAT_00b5a73c + 4))();
  iVar6 = (**(code **)(*piVar5 + 8))();
  if (in_ECX[iVar6 + 1] == 0) {
    in_ECX[iVar6 + 1] = piVar5;
    (**(code **)(*piVar5 + 0x10))();
  }
  piVar5 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x12);
  iVar6 = (**(code **)(*piVar5 + 8))();
  if (in_ECX[iVar6 + 1] == 0) {
    in_ECX[iVar6 + 1] = piVar5;
    (**(code **)(*piVar5 + 0x10))();
  }
  piVar5 = (int *)(**(code **)(*DAT_00b5a73c + 4))(4,0xb);
  iVar6 = (**(code **)(*piVar5 + 8))();
  if (in_ECX[iVar6 + 1] == 0) {
    in_ECX[iVar6 + 1] = piVar5;
    (**(code **)(*piVar5 + 0x10))();
  }
  piVar5 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x13,0xb);
  iVar6 = (**(code **)(*piVar5 + 8))();
  if (in_ECX[iVar6 + 1] == 0) {
    in_ECX[iVar6 + 1] = piVar5;
    (**(code **)(*piVar5 + 0x10))();
  }
  piVar5 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x25,0xb);
  iVar6 = (**(code **)(*piVar5 + 8))();
  if (in_ECX[iVar6 + 1] == 0) {
    in_ECX[iVar6 + 1] = piVar5;
    (**(code **)(*piVar5 + 0x10))();
  }
  *(undefined2 *)(in_ECX + 0x54) = 0;
  *(undefined2 *)((int)in_ECX + 0x14e) = 0;
  *(undefined2 *)((int)in_ECX + 0x152) = 0;
  FUN_0050cd30(acStack_52 + -3,&DAT_009d158c,&DAT_009d1555);
  uVar8 = 0;
  pcVar7 = pcVar1;
  do {
    cVar2 = pcVar7[(int)(acStack_52 + (-3 - (int)pcVar1))];
    *pcVar7 = cVar2;
    if (cVar2 == '\0') goto LAB_0063320e;
    uVar8 = uVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (uVar8 < 0x21);
  *pcVar1 = '\0';
LAB_0063320e:
  *(undefined2 *)((int)in_ECX + 0x152) = 0;
  *(undefined1 *)((int)in_ECX + 0x155) = 0;
  *(undefined1 *)(in_ECX + 0x55) = 0;
  in_ECX[0x56] = 0;
  ExceptionList = pvVar3;
  return;
}


// ==== FUN_00633240 @ 0x00633240 ====

undefined4 FUN_00633240(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098a51f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  (**(code **)(*in_ECX + 0xc))(param_1);
  FUN_00633380(param_2);
  *(undefined1 *)(in_ECX + 0x2c) = 1;
  local_8 = 0;
  cVar2 = FUN_00633020(param_2);
  if (cVar2 == '\0') {
    ExceptionList = local_10;
    return 0;
  }
  local_8 = 0xffffffff;
  cVar2 = FUN_005c8e90();
  if (cVar2 == '\x01') {
    iVar1 = *(int *)in_ECX[0x57];
    uVar3 = (**(code **)(*DAT_00b5a690 + 4))();
    (**(code **)(iVar1 + 0x28))(uVar3);
  }
  ExceptionList = local_10;
  return 1;
}


// ==== Catch@006332e3 @ 0x006332e3 ====

undefined4 Catch_006332e3(void)

{
  int unaff_EBP;
  
  FUN_0044a670(s_____EXCEPTION_____009d1558);
  FUN_00797b80(unaff_EBP + -0x114);
  FUN_00797b80(*(undefined4 *)(unaff_EBP + 8));
  FUN_0044a670(s__________opening_PC_Stock_009d156c);
  FUN_00797b80(unaff_EBP + -0x214);
  *(undefined1 *)(*(int *)(unaff_EBP + -0x14) + 0xb0) = 0;
  return 0x63333a;
}


// ==== FUN_00633350 @ 0x00633350 ====

void FUN_00633350(void)

{
  FUN_00633400();
  return;
}


// ==== FUN_00633360 @ 0x00633360 ====

void FUN_00633360(byte param_1)

{
  void *in_ECX;
  
  FUN_00632f40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00633380 @ 0x00633380 ====

void FUN_00633380(int param_1)

{
  char cVar1;
  char *in_ECX;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  
  uVar4 = 0;
  pcVar2 = in_ECX;
  do {
    cVar1 = pcVar2[param_1 - (int)in_ECX];
    *pcVar2 = cVar1;
    if (cVar1 == '\0') goto LAB_006333a7;
    uVar4 = uVar4 + 1;
    pcVar2 = pcVar2 + 1;
  } while (uVar4 < 0x19);
  *in_ECX = '\0';
LAB_006333a7:
  puVar5 = (undefined4 *)(param_1 + 0x1a);
  pcVar2 = in_ECX + 0x1a;
  for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined4 *)pcVar2 = *puVar5;
    puVar5 = puVar5 + 1;
    pcVar2 = pcVar2 + 4;
  }
  in_ECX[0x46] = *(char *)(param_1 + 0x46);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x58);
  pcVar2 = (char *)(param_1 + 0x5c);
  pcVar6 = in_ECX + 0x5c;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar6 = pcVar6 + 4;
  }
  *pcVar6 = *pcVar2;
  in_ECX[0x75] = *(char *)(param_1 + 0x75);
  in_ECX[0x76] = *(char *)(param_1 + 0x76);
  return;
}


// ==== FUN_00633400 @ 0x00633400 ====

void FUN_00633400(int param_1)

{
  char cVar1;
  char *in_ECX;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0;
  pcVar3 = in_ECX;
  do {
    cVar1 = pcVar3[param_1 - (int)in_ECX];
    *pcVar3 = cVar1;
    if (cVar1 == '\0') goto LAB_00633428;
    uVar2 = uVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar2 < 0x21);
  *in_ECX = '\0';
LAB_00633428:
  *(undefined2 *)(in_ECX + 0x22) = *(undefined2 *)(param_1 + 0x22);
  *(undefined2 *)(in_ECX + 0x24) = *(undefined2 *)(param_1 + 0x24);
  *(undefined2 *)(in_ECX + 0x26) = *(undefined2 *)(param_1 + 0x26);
  in_ECX[0x28] = *(char *)(param_1 + 0x28);
  in_ECX[0x29] = *(char *)(param_1 + 0x29);
  return;
}


// ==== FUN_00633460 @ 0x00633460 ====

void FUN_00633460(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d02e4;
  return;
}


// ==== FUN_00633470 @ 0x00633470 ====

void FUN_00633470(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xac) = 0;
  return;
}


// ==== FUN_00633480 @ 0x00633480 ====

void FUN_00633480(void)

{
  return;
}


// ==== FUN_00633490 @ 0x00633490 ====

int FUN_00633490(void)

{
  int in_ECX;
  
  return in_ECX + 0xb2;
}


// ==== FUN_006334b0 @ 0x006334b0 ====

undefined4 FUN_006334b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xdc);
}


// ==== FUN_006334c0 @ 0x006334c0 ====

void FUN_006334c0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xdc) = param_1;
  return;
}


// ==== FUN_006334d0 @ 0x006334d0 ====

undefined4 FUN_006334d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xe0);
}


// ==== FUN_006334e0 @ 0x006334e0 ====

void FUN_006334e0(void)

{
  return;
}


// ==== FUN_00633510 @ 0x00633510 ====

void FUN_00633510(void)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a538;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = (int)&PTR_FUN_009d1614;
  local_4 = 0;
  iVar1 = 0x2a;
  piVar2 = in_ECX;
  do {
    piVar2 = piVar2 + 1;
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 0xc))();
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      *piVar2 = 0;
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((undefined4 *)in_ECX[0x38] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x38])(1);
  }
  in_ECX[0x38] = 0;
  *in_ECX = (int)&PTR_FUN_009d02e4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_006335a0 @ 0x006335a0 ====

void FUN_006335a0(void)

{
  char cVar1;
  int *in_ECX;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0x2a;
  piVar2 = in_ECX;
  do {
    piVar2 = piVar2 + 1;
    if (*piVar2 != 0) {
      (**(code **)(*(int *)*piVar2 + 0xc))();
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    (**(code **)(*(int *)in_ECX[0x38] + 0x2c))();
  }
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  return;
}


// ==== FUN_006335f0 @ 0x006335f0 ====

undefined4 FUN_006335f0(undefined2 *param_1)

{
  int in_ECX;
  undefined4 local_8;
  undefined2 local_4;
  
  local_4 = *param_1;
  local_8 = 9;
  (**(code **)(**(int **)(in_ECX + 0x4c) + 0x1c))(&local_8);
  return 1;
}


// ==== FUN_00633620 @ 0x00633620 ====

void FUN_00633620(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *in_ECX;
  void *unaff_ESI;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a555;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d1614;
  pvVar1 = operator_new(0xa1c);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00653eb0(in_ECX);
  }
  in_ECX[0x38] = uVar2;
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00797a50(in_ECX + 1,0,0xa8);
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(6,9);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x12,1);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  FUN_00797a50((int)in_ECX + 0xb2,0,0x24);
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  in_ECX[0x37] = 0;
  ExceptionList = unaff_ESI;
  return;
}


// ==== FUN_00633720 @ 0x00633720 ====

undefined4 FUN_00633720(undefined4 *param_1)

{
  char cVar1;
  undefined2 extraout_var;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 auStack_fe [254];
  
  (**(code **)(*in_ECX + 0xc))(param_1);
  puVar5 = param_1;
  puVar6 = (undefined4 *)((int)in_ECX + 0xb2);
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar4 = (**(code **)(*DAT_00b5a738 + 0x10))(CONCAT22(extraout_var,*(undefined2 *)param_1));
  in_ECX[0x36] = iVar4;
  if (iVar4 == 0) {
    FUN_0044a580(auStack_fe + -10,&DAT_009d160c,s_Logic_Item_Open_Fail____Flyweigh_009d15dc);
    FUN_00797b80(auStack_fe + -10);
  }
  else {
    piVar2 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))(1,0);
    if (piVar2 != (int *)0x0) {
      cVar1 = (**(code **)(*piVar2 + 8))(param_1);
      if (cVar1 != '\0') {
        FUN_006335f0(param_1);
        (**(code **)(*(int *)in_ECX[7] + 0x14))(piVar2);
        *(undefined1 *)(in_ECX + 0x2c) = 1;
        cVar1 = FUN_005c8e90();
        if (cVar1 == '\x01') {
          iVar4 = *(int *)in_ECX[0x38];
          uVar3 = (**(code **)(*DAT_00b5a690 + 4))();
          (**(code **)(iVar4 + 0x28))(uVar3);
        }
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_00633810 @ 0x00633810 ====

void FUN_00633810(byte param_1)

{
  void *in_ECX;
  
  FUN_00633510();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00633830 @ 0x00633830 ====

void FUN_00633830(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1638;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00633850 @ 0x00633850 ====

void FUN_00633850(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1638;
  return;
}


// ==== FUN_00633860 @ 0x00633860 ====

int FUN_00633860(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00633870 @ 0x00633870 ====

void FUN_00633870(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  return;
}


// ==== FUN_00633890 @ 0x00633890 ====

void FUN_00633890(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1648;
  return;
}


// ==== FUN_006338a0 @ 0x006338a0 ====

void FUN_006338a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00633850();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006338c0 @ 0x006338c0 ====

void FUN_006338c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d167c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006338e0 @ 0x006338e0 ====

int FUN_006338e0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_006338f0 @ 0x006338f0 ====

void FUN_006338f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d167c;
  return;
}


// ==== FUN_00633900 @ 0x00633900 ====

undefined2 FUN_00633900(ushort param_1)

{
  int in_ECX;
  
  if (param_1 < 16000) {
    *(ushort *)(in_ECX + 4) = param_1;
    *(undefined4 *)(in_ECX + 6) = 0;
    *(undefined1 *)(in_ECX + 10) = 0;
    return 1;
  }
  return 0;
}


// ==== FUN_00633930 @ 0x00633930 ====

void FUN_00633930(byte param_1,undefined1 param_2)

{
  int in_ECX;
  
  *(undefined1 *)(param_1 + 6 + in_ECX) = param_2;
  return;
}


// ==== FUN_00633940 @ 0x00633940 ====

void FUN_00633940(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1694;
  return;
}


// ==== FUN_00633950 @ 0x00633950 ====

void FUN_00633950(byte param_1)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_1 < 2) {
    *(byte *)(in_ECX + 10) = param_1;
    return;
  }
  local_100[0] = 0;
  uVar1 = FUN_0044a580(local_100,s_INVALID_QUEST_STATE________d_009d1658,param_1);
  FUN_00797b80(uVar1);
  return;
}


// ==== FUN_006339a0 @ 0x006339a0 ====

void FUN_006339a0(byte param_1)

{
  void *in_ECX;
  
  FUN_006338f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006339c0 @ 0x006339c0 ====

void FUN_006339c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_006339d0 @ 0x006339d0 ====

void FUN_006339d0(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x2c) + 4))(param_1);
  return;
}


// ==== FUN_006339f0 @ 0x006339f0 ====

undefined1 FUN_006339f0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x13);
}


// ==== FUN_00633a00 @ 0x00633a00 ====

int FUN_00633a00(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00633a40 @ 0x00633a40 ====

void FUN_00633a40(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x38) = 1;
  return;
}


// ==== FUN_00633a50 @ 0x00633a50 ====

undefined1 FUN_00633a50(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x38);
}


// ==== FUN_00633a60 @ 0x00633a60 ====

void FUN_00633a60(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x2c) + 0x10))(param_1);
  return;
}


// ==== FUN_00633a80 @ 0x00633a80 ====

void FUN_00633a80(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00633a85. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x2c) + 0x14))();
  return;
}


// ==== FUN_00633a90 @ 0x00633a90 ====

undefined4 FUN_00633a90(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x30);
}


// ==== FUN_00633aa0 @ 0x00633aa0 ====

undefined4 FUN_00633aa0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x28);
}


// ==== FUN_00633ab0 @ 0x00633ab0 ====

void FUN_00633ab0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x28) = param_1;
  return;
}


// ==== FUN_00633ac0 @ 0x00633ac0 ====

void FUN_00633ac0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x30) = param_1;
  return;
}


// ==== FUN_00633ad0 @ 0x00633ad0 ====

undefined4 FUN_00633ad0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x2c);
}


// ==== FUN_00633ae0 @ 0x00633ae0 ====

void FUN_00633ae0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x2c) = param_1;
  return;
}


// ==== FUN_00633af0 @ 0x00633af0 ====

undefined4 FUN_00633af0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x34);
}


// ==== FUN_00633b00 @ 0x00633b00 ====

void FUN_00633b00(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x34) = param_1;
  return;
}


// ==== FUN_00633b10 @ 0x00633b10 ====

void FUN_00633b10(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x22) = *param_1;
  *(undefined2 *)(in_ECX + 0x26) = *(undefined2 *)(param_1 + 1);
  return;
}


// ==== FUN_00633b30 @ 0x00633b30 ====

int FUN_00633b30(void)

{
  int in_ECX;
  
  return in_ECX + 0x22;
}


// ==== FUN_00633b40 @ 0x00633b40 ====

int FUN_00633b40(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00633b50 @ 0x00633b50 ====

uint FUN_00633b50(undefined4 *param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  undefined4 unaff_retaddr;
  
  piVar2 = (int *)(**(code **)(**(int **)(*(int *)(in_ECX + 0x28) + 0x50) + 0x14))(*param_1);
  iVar3 = (**(code **)(*piVar2 + 0x10))();
  bVar1 = *(byte *)((int)param_1 + 0xb);
  uVar4 = CONCAT31((int3)((uint)iVar3 >> 8),*(char *)(iVar3 + 2));
  if ((bVar1 == 0xf) || ((0x10 < bVar1 && (bVar1 < 0x13)))) {
    if (*(char *)((int)param_1 + 10) != '\0') goto LAB_00633b89;
  }
  else if (*(char *)(iVar3 + 2) != *(char *)((int)param_1 + 10)) goto LAB_00633b89;
  piVar2 = (int *)(**(code **)(*DAT_00b5af4c + 4))(bVar1);
  uVar4 = 0;
  if (piVar2 != (int *)0x0) {
    uVar4 = (**(code **)(*piVar2 + 8))(param_1,unaff_retaddr);
    return uVar4;
  }
LAB_00633b89:
  return uVar4 & 0xffffff00;
}


// ==== FUN_00633bc0 @ 0x00633bc0 ====

uint FUN_00633bc0(uint *param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int in_ECX;
  undefined1 auStack_c [4];
  
  uVar5 = *param_1;
  piVar2 = (int *)(**(code **)(**(int **)(*(int *)(in_ECX + 0x28) + 0x50) + 0x14))();
  iVar3 = (**(code **)(*piVar2 + 0x10))();
  bVar1 = *(byte *)((int)param_1 + 0xb);
  uVar4 = CONCAT31((int3)((uint)iVar3 >> 8),*(char *)(iVar3 + 2));
  if ((bVar1 == 0xf) || ((0x10 < bVar1 && (bVar1 < 0x13)))) {
    if (*(char *)((int)param_1 + 10) != '\0') goto LAB_00633bf9;
  }
  else if (*(char *)(iVar3 + 2) != *(char *)((int)param_1 + 10)) goto LAB_00633bf9;
  piVar2 = (int *)(**(code **)(*DAT_00b5af4c + 4))(bVar1);
  uVar4 = 0;
  if (piVar2 != (int *)0x0) {
    uVar4 = (**(code **)(*piVar2 + 0x18))(param_1,auStack_c + 8);
    if (((char)uVar4 != '\x01') || (*(uint *)(in_ECX + 8) < uVar5)) {
      uVar5 = (**(code **)(**(int **)(in_ECX + 0x2c) + 0xc))(param_1);
      return uVar5;
    }
  }
LAB_00633bf9:
  return uVar4 & 0xffffff00;
}


// ==== FUN_00633c40 @ 0x00633c40 ====

undefined4 FUN_00633c40(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5af4c + 4))(*(undefined1 *)(param_1 + 0xb));
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = FUN_004f4d60();
  FUN_00797a80(in_ECX + 2,param_1,uVar2);
  (**(code **)(*in_ECX + 0x58))(iVar1);
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  return 1;
}


// ==== FUN_00633ca0 @ 0x00633ca0 ====

void FUN_00633ca0(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5af4c + 4))(*(undefined1 *)(param_1 + 0xb));
  (**(code **)(*piVar1 + 0x1c))(param_1,param_1);
  return;
}


// ==== FUN_00633cd0 @ 0x00633cd0 ====

undefined4 FUN_00633cd0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x28) == 0) {
    return 1;
  }
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x28) + 8))();
                    /* WARNING: Could not recover jumptable at 0x00633ce7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(*piVar1 + 0x14))();
  return uVar2;
}


// ==== FUN_00633cf0 @ 0x00633cf0 ====

void FUN_00633cf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d16ac;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  return;
}


// ==== FUN_00633d10 @ 0x00633d10 ====

void FUN_00633d10(byte param_1)

{
  void *in_ECX;
  
  FUN_006339c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00633d30 @ 0x00633d30 ====

void FUN_00633d30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_00633d40 @ 0x00633d40 ====

void FUN_00633d40(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00633d50 @ 0x00633d50 ====

int FUN_00633d50(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00633d60 @ 0x00633d60 ====

void FUN_00633d60(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00633d70 @ 0x00633d70 ====

undefined1 FUN_00633d70(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 8);
}


// ==== FUN_00633d80 @ 0x00633d80 ====

void FUN_00633d80(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a568;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d170c;
  FUN_00797a50(in_ECX + 2,0,1);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00633dd0 @ 0x00633dd0 ====

void FUN_00633dd0(byte param_1)

{
  void *in_ECX;
  
  FUN_00633d30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00633df0 @ 0x00633df0 ====

void FUN_00633df0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_00633e00 @ 0x00633e00 ====

void FUN_00633e00(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00633e10 @ 0x00633e10 ====

int FUN_00633e10(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00633e20 @ 0x00633e20 ====

void FUN_00633e20(int param_1)

{
  int in_ECX;
  
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
  return;
}


// ==== FUN_00633e30 @ 0x00633e30 ====

void FUN_00633e30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1728;
  return;
}


// ==== FUN_00633e40 @ 0x00633e40 ====

void FUN_00633e40(byte param_1)

{
  void *in_ECX;
  
  FUN_00633df0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00633e60 @ 0x00633e60 ====

void FUN_00633e60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_00633e70 @ 0x00633e70 ====

undefined4 FUN_00633e70(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00633e80 @ 0x00633e80 ====

undefined4 FUN_00633e80(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5ab4c + 8))(param_1);
  *(undefined4 *)(in_ECX + 8) = uVar1;
  return 1;
}


// ==== FUN_00633ea0 @ 0x00633ea0 ====

void FUN_00633ea0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00633eb0 @ 0x00633eb0 ====

void FUN_00633eb0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00633ec0 @ 0x00633ec0 ====

void FUN_00633ec0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1740;
  return;
}


// ==== FUN_00633ed0 @ 0x00633ed0 ====

void FUN_00633ed0(byte param_1)

{
  void *in_ECX;
  
  FUN_00633e60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00633ef0 @ 0x00633ef0 ====

void FUN_00633ef0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_00633f00 @ 0x00633f00 ====

undefined4 FUN_00633f00(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00633f10 @ 0x00633f10 ====

undefined4 FUN_00633f10(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5ab50 + 8))(param_1);
  *(undefined4 *)(in_ECX + 8) = uVar1;
  return 1;
}


// ==== FUN_00633f30 @ 0x00633f30 ====

void FUN_00633f30(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00633f40 @ 0x00633f40 ====

void FUN_00633f40(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00633f50 @ 0x00633f50 ====

void FUN_00633f50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d175c;
  return;
}


// ==== FUN_00633f60 @ 0x00633f60 ====

void FUN_00633f60(byte param_1)

{
  void *in_ECX;
  
  FUN_00633ef0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00633f80 @ 0x00633f80 ====

void FUN_00633f80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_00633f90 @ 0x00633f90 ====

undefined4 FUN_00633f90(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00633fa0 @ 0x00633fa0 ====

void FUN_00633fa0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_00633fb0 @ 0x00633fb0 ====

undefined4 FUN_00633fb0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00633fc0 @ 0x00633fc0 ====

undefined4 FUN_00633fc0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5ab54 + 8))(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  *(int *)(in_ECX + 8) = iVar1;
  return 1;
}


// ==== FUN_00633ff0 @ 0x00633ff0 ====

void FUN_00633ff0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00634000 @ 0x00634000 ====

void FUN_00634000(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00634010 @ 0x00634010 ====

void FUN_00634010(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1778;
  in_ECX[3] = 0;
  return;
}


// ==== FUN_00634020 @ 0x00634020 ====

void FUN_00634020(byte param_1)

{
  void *in_ECX;
  
  FUN_00633f80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00634040 @ 0x00634040 ====

void FUN_00634040(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_00634050 @ 0x00634050 ====

int FUN_00634050(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00634060 @ 0x00634060 ====

void FUN_00634060(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00634070 @ 0x00634070 ====

void FUN_00634070(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a588;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d179c;
  FUN_00797a50(in_ECX + 2,0,1);
  ExceptionList = local_c;
  return;
}


// ==== FUN_006340c0 @ 0x006340c0 ====

void FUN_006340c0(byte param_1)

{
  void *in_ECX;
  
  FUN_00634040();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006340e0 @ 0x006340e0 ====

void FUN_006340e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_00634110 @ 0x00634110 ====

int FUN_00634110(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00634120 @ 0x00634120 ====

void FUN_00634120(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00634130 @ 0x00634130 ====

undefined4 FUN_00634130(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00634140 @ 0x00634140 ====

void FUN_00634140(uint param_1)

{
  int in_ECX;
  
  if (param_1 < 0x3b9aca01) {
    if (*(uint *)(in_ECX + 8) <= 1000000000 - param_1) {
      *(uint *)(in_ECX + 8) = *(uint *)(in_ECX + 8) + param_1;
      return;
    }
  }
  *(undefined4 *)(in_ECX + 8) = 1000000000;
  return;
}


// ==== FUN_00634170 @ 0x00634170 ====

void FUN_00634170(uint param_1)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 8) < param_1) {
    *(undefined4 *)(in_ECX + 8) = 0;
    return;
  }
  *(uint *)(in_ECX + 8) = *(uint *)(in_ECX + 8) - param_1;
  return;
}


// ==== FUN_00634190 @ 0x00634190 ====

undefined4 FUN_00634190(uint param_1)

{
  int in_ECX;
  
  return CONCAT31((int3)(*(uint *)(in_ECX + 8) >> 8),param_1 <= *(uint *)(in_ECX + 8));
}


// ==== FUN_006341a0 @ 0x006341a0 ====

undefined1 FUN_006341a0(undefined4 param_1)

{
  char cVar1;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 0x1c))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  (**(code **)(*in_ECX + 0x18))(param_1);
  return 1;
}


// ==== FUN_006341d0 @ 0x006341d0 ====

void FUN_006341d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a5a8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d17b0;
  FUN_00797a50(in_ECX + 2,0,4);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00634220 @ 0x00634220 ====

void FUN_00634220(byte param_1)

{
  void *in_ECX;
  
  FUN_006340e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00634240 @ 0x00634240 ====

void FUN_00634240(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_00634250 @ 0x00634250 ====

undefined1 FUN_00634250(void)

{
  return 1;
}


// ==== FUN_00634260 @ 0x00634260 ====

void FUN_00634260(void)

{
  return;
}


// ==== FUN_00634270 @ 0x00634270 ====

int FUN_00634270(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00634280 @ 0x00634280 ====

void FUN_00634280(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = *param_1;
  *(undefined2 *)(in_ECX + 0xc) = *(undefined2 *)(param_1 + 1);
  return;
}


// ==== FUN_006342a0 @ 0x006342a0 ====

void FUN_006342a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d17d8;
  *(undefined2 *)(in_ECX + 2) = 0;
  *(undefined2 *)((int)in_ECX + 10) = 0;
  *(undefined2 *)(in_ECX + 3) = 0;
  return;
}


// ==== FUN_006342c0 @ 0x006342c0 ====

void FUN_006342c0(byte param_1)

{
  void *in_ECX;
  
  FUN_00634240();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00634300 @ 0x00634300 ====

void FUN_00634300(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50) = 0;
  return;
}


// ==== FUN_00634310 @ 0x00634310 ====

int FUN_00634310(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00634320 @ 0x00634320 ====

void FUN_00634320(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50) = *param_1;
  return;
}


// ==== FUN_00634330 @ 0x00634330 ====

int FUN_00634330(void)

{
  int in_ECX;
  
  return in_ECX + 0x50;
}


// ==== FUN_00634340 @ 0x00634340 ====

int FUN_00634340(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00634350 @ 0x00634350 ====

void FUN_00634350(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x24) = param_1;
  return;
}


// ==== FUN_00634360 @ 0x00634360 ====

undefined4 FUN_00634360(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x24);
}


// ==== FUN_00634370 @ 0x00634370 ====

void FUN_00634370(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x28) = param_1;
  return;
}


// ==== FUN_00634380 @ 0x00634380 ====

undefined4 FUN_00634380(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x28);
}


// ==== FUN_00634390 @ 0x00634390 ====

void FUN_00634390(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x2c) = *param_1;
  *(undefined2 *)(in_ECX + 0x30) = *(undefined2 *)(param_1 + 1);
  return;
}


// ==== FUN_006343b0 @ 0x006343b0 ====

int FUN_006343b0(void)

{
  int in_ECX;
  
  return in_ECX + 0x2c;
}


// ==== FUN_006343c0 @ 0x006343c0 ====

void FUN_006343c0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x28) = *param_1;
  *(undefined4 *)(in_ECX + 0x34) = param_1[3];
  *(undefined4 *)(in_ECX + 0x2c) = param_1[1];
  *(undefined2 *)(in_ECX + 0x30) = *(undefined2 *)(param_1 + 2);
  return;
}


// ==== FUN_006343f0 @ 0x006343f0 ====

void FUN_006343f0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x3c) = param_1;
  return;
}


// ==== FUN_00634400 @ 0x00634400 ====

undefined4 FUN_00634400(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x3c);
}


// ==== FUN_00634410 @ 0x00634410 ====

void FUN_00634410(int param_1)

{
  uint uVar1;
  int in_ECX;
  
  if (param_1 != 0) {
    uVar1 = *(int *)(in_ECX + 0x40) + param_1;
    if (999999999 < uVar1) {
      *(undefined4 *)(in_ECX + 0x40) = 1000000000;
      return;
    }
    *(uint *)(in_ECX + 0x40) = uVar1;
  }
  return;
}


// ==== FUN_00634440 @ 0x00634440 ====

void FUN_00634440(uint param_1)

{
  int in_ECX;
  
  if (param_1 != 0) {
    if (*(uint *)(in_ECX + 0x40) <= param_1) {
      *(undefined4 *)(in_ECX + 0x40) = 0;
      return;
    }
    *(uint *)(in_ECX + 0x40) = *(uint *)(in_ECX + 0x40) - param_1;
  }
  return;
}


// ==== FUN_00634470 @ 0x00634470 ====

void FUN_00634470(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x4c) = param_1;
  return;
}


// ==== FUN_00634480 @ 0x00634480 ====

void FUN_00634480(void)

{
  int in_ECX;
  
  *(short *)(in_ECX + 0x44) = *(short *)(in_ECX + 0x44) + 1;
  return;
}


// ==== FUN_00634490 @ 0x00634490 ====

void FUN_00634490(void)

{
  int in_ECX;
  
  *(short *)(in_ECX + 0x48) = *(short *)(in_ECX + 0x48) + 1;
  return;
}


// ==== FUN_006344a0 @ 0x006344a0 ====

void FUN_006344a0(void)

{
  int in_ECX;
  
  *(short *)(in_ECX + 0x46) = *(short *)(in_ECX + 0x46) + 1;
  return;
}


// ==== FUN_006344b0 @ 0x006344b0 ====

void FUN_006344b0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x40) = *param_1;
  *(undefined2 *)(in_ECX + 0x44) = *(undefined2 *)(param_1 + 1);
  *(undefined2 *)(in_ECX + 0x48) = *(undefined2 *)(param_1 + 2);
  *(undefined2 *)(in_ECX + 0x46) = *(undefined2 *)((int)param_1 + 6);
  return;
}


// ==== FUN_006344e0 @ 0x006344e0 ====

void FUN_006344e0(undefined1 *param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x38) = *param_1;
  *(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)(param_1 + 4);
  return;
}


// ==== FUN_00634500 @ 0x00634500 ====

void FUN_00634500(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_00634510 @ 0x00634510 ====

void FUN_00634510(int param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int in_ECX;
  uint uVar4;
  
  pcVar1 = (char *)(in_ECX + 8);
  uVar4 = 0;
  pcVar3 = pcVar1;
  do {
    cVar2 = pcVar3[param_1 - (int)pcVar1];
    *pcVar3 = cVar2;
    if (cVar2 == '\0') {
      return;
    }
    uVar4 = uVar4 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar4 < 0x19);
  *pcVar1 = '\0';
  return;
}


// ==== FUN_00634540 @ 0x00634540 ====

undefined4 FUN_00634540(int param_1,undefined4 param_2)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_006345d0(param_2);
  if ((cVar1 == '\0') && (*(int *)(in_ECX + 0x24) == param_1)) {
    return 1;
  }
  return 0;
}


// ==== FUN_00634570 @ 0x00634570 ====

void FUN_00634570(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a5c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d17f4;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00797a50(in_ECX + 2,0,0x48);
  in_ECX[0x14] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006345d0 @ 0x006345d0 ====

undefined4 FUN_006345d0(int param_1)

{
  char *in_ECX;
  uint uVar1;
  
  uVar1 = 0;
  param_1 = param_1 - (int)in_ECX;
  while( true ) {
    if (*in_ECX != in_ECX[param_1]) {
      return 1;
    }
    if (*in_ECX == '\0') break;
    uVar1 = uVar1 + 1;
    in_ECX = in_ECX + 1;
    if (0x18 < uVar1) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00634610 @ 0x00634610 ====

void FUN_00634610(byte param_1)

{
  void *in_ECX;
  
  FUN_00634500();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00634630 @ 0x00634630 ====

void FUN_00634630(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_00634640 @ 0x00634640 ====

int FUN_00634640(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00634650 @ 0x00634650 ====

undefined4 FUN_00634650(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1c);
}


// ==== FUN_00634660 @ 0x00634660 ====

undefined4 FUN_00634660(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x20);
}


// ==== FUN_00634670 @ 0x00634670 ====

undefined4 FUN_00634670(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x18);
}


// ==== FUN_006346a0 @ 0x006346a0 ====

undefined4 FUN_006346a0(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5ab78 + 8))(param_1);
  if ((piVar2 == (int *)0x0) || (param_1 == (int *)0x0)) {
    return 0;
  }
  iVar3 = (**(code **)(*piVar2 + 4))();
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(iVar3 + 0xc);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(iVar3 + 0x10);
  iVar3 = (**(code **)(*param_1 + 4))();
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(iVar3 + 0x104);
  uVar1 = *(undefined4 *)(iVar3 + 0x104);
  *(int **)(in_ECX + 0x1c) = piVar2;
  *(undefined4 *)(in_ECX + 0x18) = param_2;
  *(int **)(in_ECX + 0x20) = param_1;
  *(undefined4 *)(in_ECX + 0x10) = uVar1;
  return 1;
}


// ==== FUN_00634710 @ 0x00634710 ====

void FUN_00634710(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  return;
}


// ==== FUN_00634730 @ 0x00634730 ====

void FUN_00634730(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int in_ECX;
  
  if (param_1 < 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(in_ECX + 0xc);
    if (param_1 <= *(int *)(in_ECX + 0xc)) {
      iVar1 = param_1;
    }
  }
  *(int *)(in_ECX + 8) = iVar1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (*(int *)(in_ECX + 0x14) < param_2) {
    *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x14);
    *(undefined4 *)(in_ECX + 0x18) = param_3;
    return;
  }
  *(int *)(in_ECX + 0x10) = param_2;
  *(undefined4 *)(in_ECX + 0x18) = param_3;
  return;
}


// ==== FUN_00634780 @ 0x00634780 ====

void FUN_00634780(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1860;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  return;
}


// ==== FUN_006347a0 @ 0x006347a0 ====

void FUN_006347a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00634630();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006347c0 @ 0x006347c0 ====

void FUN_006347c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d18bc;
  return;
}


// ==== FUN_006347d0 @ 0x006347d0 ====

void FUN_006347d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d18bc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006347f0 @ 0x006347f0 ====

void FUN_006347f0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x60) = param_1;
  return;
}


// ==== FUN_00634800 @ 0x00634800 ====

int FUN_00634800(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00634810 @ 0x00634810 ====

void FUN_00634810(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  for (iVar1 = 0x16; in_ECX = in_ECX + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *in_ECX = *param_1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_00634830 @ 0x00634830 ====

void FUN_00634830(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4,0,0x58);
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  return;
}


// ==== FUN_00634850 @ 0x00634850 ====

undefined4 FUN_00634850(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x5c);
}


// ==== FUN_00634880 @ 0x00634880 ====

void FUN_00634880(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d18bc;
  return;
}


// ==== FUN_00634890 @ 0x00634890 ====

void FUN_00634890(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a5e8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d18e0;
  FUN_00797a50(in_ECX + 1,0,0x58);
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006348f0 @ 0x006348f0 ====

void FUN_006348f0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int in_ECX;
  int iStack_c;
  
  piVar6 = *(int **)(*(int *)(in_ECX + 0x60) + 0x84);
  if (piVar6 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)(**(code **)(*piVar6 + 0x1c))();
  }
  *(int *)(in_ECX + 0x5c) = param_1;
  *(int *)(in_ECX + 4) = param_1;
  piVar6 = (int *)(**(code **)(*piVar6 + 0x14))();
  iVar7 = (**(code **)(*piVar6 + 4))();
  uVar1 = *(uint *)(iVar7 + 0x2c);
  uVar2 = *(uint *)(iVar7 + 0x24);
  uVar3 = *(uint *)(iVar7 + 0x28);
  uVar4 = *(uint *)(iVar7 + 0x20);
  uVar5 = *(uint *)(iVar7 + 0x1c);
  if ((uVar1 < uVar3) || (uVar1 == uVar3)) {
    uVar8 = uVar3;
  }
  else {
    uVar8 = (**(code **)(*DAT_00b5b0a0 + 0x10))(uVar3,uVar1);
  }
  *(int *)(in_ECX + 8) = param_1;
  *(uint *)(in_ECX + 0xc) = uVar8 + param_1;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  piVar6 = (int *)(in_ECX + 0x14);
  iStack_c = 6;
  do {
    uVar8 = (**(code **)(*DAT_00b5b0a0 + 0x10))(0,100000);
    if (piVar6[-1] == 0) {
      uVar9 = uVar4;
      if (uVar5 < uVar8) {
        if ((uVar4 <= uVar2) && (uVar2 != uVar4)) {
          uVar9 = (**(code **)(*DAT_00b5b0a0 + 0x10))(uVar4,uVar2);
        }
        goto LAB_006349ec;
      }
      if ((uVar2 < uVar4) || (uVar2 == uVar4)) {
        piVar6[2] = 1;
      }
      else {
        uVar9 = (**(code **)(*DAT_00b5b0a0 + 0x10))(uVar4,uVar2);
        piVar6[2] = 1;
      }
    }
    else {
      if ((uVar1 < uVar3) || (uVar1 == uVar3)) {
        uVar9 = uVar3;
      }
      else {
        uVar9 = (**(code **)(*DAT_00b5b0a0 + 0x10))(uVar3,uVar1);
      }
LAB_006349ec:
      piVar6[2] = 0;
    }
    *piVar6 = piVar6[-2];
    piVar6[1] = piVar6[-2] + uVar9;
    piVar6 = piVar6 + 3;
    iStack_c = iStack_c + -1;
    if (iStack_c == 0) {
      return;
    }
  } while( true );
}


// ==== FUN_00634a20 @ 0x00634a20 ====

undefined4 FUN_00634a20(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *in_ECX;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint *puStack_114;
  uint *puStack_10c;
  undefined1 local_100 [256];
  
  if (param_1 <= in_ECX[0x17]) {
    return 0;
  }
  in_ECX[0x17] = param_1;
  uVar8 = 0;
  puVar9 = in_ECX;
  while ((param_1 < puVar9[2] || (puVar9[3] <= param_1))) {
    uVar8 = uVar8 + 1;
    puVar9 = puVar9 + 3;
    if (6 < uVar8) {
LAB_00634a6b:
      FUN_0044a580(local_100,&DAT_009d18b4,s_Invalid_UpdateTick_for_Fishting_U_009d1888);
      FUN_00797b80(local_100);
      return 2;
    }
  }
  if (uVar8 != 0xffffffff) {
    if ((int)uVar8 < 2) {
      return 0;
    }
    if (*(int **)(in_ECX[0x18] + 0x84) == (int *)0x0) {
      return 2;
    }
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX[0x18] + 0x84) + 0x1c))();
    if (piVar4 == (int *)0x0) {
      return 2;
    }
    piVar4 = (int *)(**(code **)(*piVar4 + 0x14))();
    puStack_114 = in_ECX + 2;
    puStack_10c = in_ECX + uVar8 * 3 + 2;
    uVar10 = 0;
    uVar5 = 0;
    goto LAB_00634ae5;
  }
  goto LAB_00634a6b;
  while( true ) {
    *puStack_114 = *puStack_10c;
    puStack_114[1] = puStack_10c[1];
    puStack_114[2] = puStack_10c[2];
    puStack_10c = puStack_10c + 3;
    puStack_114 = puStack_114 + 3;
    uVar5 = uVar5 + 1;
    uVar10 = uVar10 + 1;
    if (6 < uVar5) break;
LAB_00634ae5:
    if (6 < uVar5 + uVar8) break;
  }
  iVar6 = (**(code **)(*piVar4 + 4))();
  uVar8 = *(uint *)(iVar6 + 0x20);
  iVar6 = (**(code **)(*piVar4 + 4))();
  uVar5 = *(uint *)(iVar6 + 0x24);
  iVar6 = (**(code **)(*piVar4 + 4))();
  uVar1 = *(uint *)(iVar6 + 0x28);
  iVar6 = (**(code **)(*piVar4 + 4))();
  uVar2 = *(uint *)(iVar6 + 0x2c);
  iVar6 = (**(code **)(*piVar4 + 4))();
  uVar3 = *(uint *)(iVar6 + 0x1c);
  if (uVar10 < 7) {
    puStack_114 = (uint *)(7 - uVar10);
    puVar9 = in_ECX + uVar10 * 3 + 2;
    do {
      uVar10 = (**(code **)(*DAT_00b5b0a0 + 0x10))(0,100000);
      if (puVar9[-1] == 0) {
        uVar7 = uVar8;
        if (uVar3 < uVar10) {
          if ((uVar8 <= uVar5) && (uVar5 != uVar8)) {
            uVar7 = (**(code **)(*DAT_00b5b0a0 + 0x10))(uVar8,uVar5);
          }
          goto LAB_00634bfd;
        }
        if ((uVar5 < uVar8) || (uVar5 == uVar8)) {
          puVar9[2] = 1;
        }
        else {
          uVar7 = (**(code **)(*DAT_00b5b0a0 + 0x10))(uVar8,uVar5);
          puVar9[2] = 1;
        }
      }
      else {
        uVar7 = uVar1;
        if ((uVar1 <= uVar2) && (uVar2 != uVar1)) {
          uVar7 = (**(code **)(*DAT_00b5b0a0 + 0x10))(uVar1,uVar2);
        }
LAB_00634bfd:
        puVar9[2] = 0;
      }
      *puVar9 = puVar9[-2];
      puVar9[1] = puVar9[-2] + uVar7;
      puVar9 = puVar9 + 3;
      puStack_114 = (uint *)((int)puStack_114 + -1);
    } while (puStack_114 != (uint *)0x0);
  }
  return 1;
}


// ==== FUN_00634c30 @ 0x00634c30 ====

void FUN_00634c30(byte param_1)

{
  void *in_ECX;
  
  FUN_00634880();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00634c50 @ 0x00634c50 ====

void FUN_00634c50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1950;
  return;
}


// ==== FUN_00634c60 @ 0x00634c60 ====

void FUN_00634c60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1950;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00634c80 @ 0x00634c80 ====

int FUN_00634c80(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00634c90 @ 0x00634c90 ====

undefined4 FUN_00634c90(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x2c);
}


// ==== FUN_00634ca0 @ 0x00634ca0 ====

void FUN_00634ca0(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4,0,0x2c);
  return;
}


// ==== FUN_00634cc0 @ 0x00634cc0 ====

void FUN_00634cc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1950;
  return;
}


// ==== FUN_00634cd0 @ 0x00634cd0 ====

void FUN_00634cd0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a608;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1964;
  FUN_00797a50(in_ECX + 1,0,0x2c);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00634d20 @ 0x00634d20 ====

void FUN_00634d20(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (*(uint *)(in_ECX + 0x2c) < 5) {
    *(undefined4 *)(in_ECX + 4 + *(uint *)(in_ECX + 0x2c) * 8) = param_1;
    *(undefined4 *)(in_ECX + 8 + *(int *)(in_ECX + 0x2c) * 8) = param_2;
    *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + 1;
    return;
  }
  local_100[0] = 0;
  uVar1 = FUN_0044a580(local_100,s_CANNOT_ADD_FISHING_CONTROL___it__009d1908,5);
  FUN_00797b80(uVar1);
  return;
}


// ==== FUN_00634d80 @ 0x00634d80 ====

void FUN_00634d80(byte param_1)

{
  void *in_ECX;
  
  FUN_00634cc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00634da0 @ 0x00634da0 ====

void FUN_00634da0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d19a0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00634dc0 @ 0x00634dc0 ====

void FUN_00634dc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d19a0;
  return;
}


// ==== FUN_00634dd0 @ 0x00634dd0 ====

int FUN_00634dd0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00634de0 @ 0x00634de0 ====

void FUN_00634de0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined1 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 0x18) = 0;
  return;
}


// ==== FUN_00634e00 @ 0x00634e00 ====

uint FUN_00634e00(uint param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x18) == '\0') {
    return 3;
  }
  if (*(char *)(in_ECX + 0x14) == '\x01') {
    return (uint)(*(uint *)(in_ECX + 0x10) <= param_1);
  }
  return (-(uint)(param_1 < *(uint *)(in_ECX + 8)) & 0xfffffffe) + 2;
}


// ==== FUN_00634e70 @ 0x00634e70 ====

void FUN_00634e70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d19bc;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[4] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  return;
}


// ==== FUN_00634e90 @ 0x00634e90 ====

void FUN_00634e90(undefined2 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  
  iVar2 = (**(code **)(*DAT_00b5a6b8 + 4))();
  uVar3 = *(uint *)(iVar2 + 0xcc);
  iVar2 = (**(code **)(*DAT_00b5a6b8 + 4))();
  uVar1 = *(uint *)(iVar2 + 0xd0);
  if ((uVar3 <= uVar1) && (uVar1 != uVar3)) {
    uVar3 = (**(code **)(*DAT_00b5b0a0 + 0x10))(uVar3,uVar1);
  }
  *(uint *)(in_ECX + 8) = uVar1 + param_2;
  *(int *)(in_ECX + 4) = param_2;
  *(undefined2 *)(in_ECX + 0xc) = param_1;
  *(uint *)(in_ECX + 0x10) = uVar3 + param_2;
  *(undefined1 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 0x18) = 1;
  return;
}


// ==== FUN_00634f00 @ 0x00634f00 ====

void FUN_00634f00(uint param_1)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_1 < *(uint *)(in_ECX + 8)) {
    *(uint *)(in_ECX + 0x10) = param_1;
    *(undefined1 *)(in_ECX + 0x14) = 1;
    return;
  }
  local_100[0] = 0;
  uVar1 = FUN_0044a580(local_100,s_END_TICK_>_MAX_TICK_____u____u_009d197c,param_1,
                       *(uint *)(in_ECX + 8));
  FUN_00797b80(uVar1);
  return;
}


// ==== FUN_00634f50 @ 0x00634f50 ====

void FUN_00634f50(byte param_1)

{
  void *in_ECX;
  
  FUN_00634dc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00634f70 @ 0x00634f70 ====

undefined4 FUN_00634f70(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00634f80 @ 0x00634f80 ====

void FUN_00634f80(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00634f90 @ 0x00634f90 ====

void FUN_00634f90(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_00634fa0 @ 0x00634fa0 ====

undefined4 FUN_00634fa0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00634fb0 @ 0x00634fb0 ====

void FUN_00634fb0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    (**(code **)(*DAT_00b5a730 + 0x10))(1,*(int *)(in_ECX + 0xc));
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
  return;
}


// ==== FUN_00634fe0 @ 0x00634fe0 ====

void FUN_00634fe0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d19d8;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  return;
}


// ==== FUN_00635000 @ 0x00635000 ====

void FUN_00635000(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a628;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d19d8;
  local_4 = 0;
  if (in_ECX[3] != 0) {
    (**(code **)(*DAT_00b5a730 + 0x10))(1,in_ECX[3]);
    in_ECX[3] = 0;
  }
  *in_ECX = &PTR_FUN_009cbbc0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00635060 @ 0x00635060 ====

void FUN_00635060(byte param_1)

{
  void *in_ECX;
  
  FUN_00635000();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00635080 @ 0x00635080 ====

void FUN_00635080(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d19fc;
  return;
}


// ==== FUN_00635090 @ 0x00635090 ====

void FUN_00635090(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d19fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006350b0 @ 0x006350b0 ====

void FUN_006350b0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x006350b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  return;
}


// ==== FUN_006350c0 @ 0x006350c0 ====

void FUN_006350c0(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_006350d0 @ 0x006350d0 ====

undefined2 FUN_006350d0(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0x10);
}


// ==== FUN_006350e0 @ 0x006350e0 ====

void FUN_006350e0(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x12) = param_1;
  return;
}


// ==== FUN_006350f0 @ 0x006350f0 ====

undefined2 FUN_006350f0(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0x12);
}


// ==== FUN_00635100 @ 0x00635100 ====

void FUN_00635100(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = param_1;
  return;
}


// ==== FUN_00635110 @ 0x00635110 ====

undefined4 FUN_00635110(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x18);
}


// ==== FUN_00635120 @ 0x00635120 ====

void FUN_00635120(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x14) = *param_1;
  *(undefined1 *)(in_ECX + 0x16) = *(undefined1 *)(param_1 + 1);
  return;
}


// ==== FUN_00635140 @ 0x00635140 ====

int FUN_00635140(void)

{
  int in_ECX;
  
  return in_ECX + 0x14;
}


// ==== FUN_00635150 @ 0x00635150 ====

undefined4 FUN_00635150(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
  *(int **)(in_ECX + 0xc) = piVar1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 0x14);
}


// ==== FUN_00635170 @ 0x00635170 ====

undefined4 FUN_00635170(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(*(int *)(in_ECX + 0xc));
    *(int **)(in_ECX + 0xc) = piVar1;
    if (piVar1 != (int *)0x0) {
      return *(undefined4 *)(*piVar1 + 0x14);
    }
  }
  return 0;
}


// ==== FUN_006351a0 @ 0x006351a0 ====

undefined4 FUN_006351a0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x10))();
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 0x14);
}


// ==== FUN_006351c0 @ 0x006351c0 ====

void FUN_006351c0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  for (piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))(); piVar2 != (int *)0x0;
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(piVar2)) {
    piVar1 = *(int **)(*piVar2 + 0x14);
    iVar3 = (**(code **)(*piVar1 + 0x14))();
    if (iVar3 != 0) {
      (**(code **)(*DAT_00b5a730 + 0x10))(1,iVar3);
    }
    (**(code **)(*DAT_00b5abe8 + 0x10))(1,piVar1);
  }
  (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}


// ==== FUN_00635230 @ 0x00635230 ====

void FUN_00635230(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a648;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d1ad4;
  local_4 = 0;
  FUN_006351c0();
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009d19fc;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_006352a0 @ 0x006352a0 ====

bool FUN_006352a0(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int in_ECX;
  char *pcVar4;
  int *unaff_EBX;
  uint uVar5;
  
  pcVar2 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  iVar3 = (**(code **)(*unaff_EBX + 0x10))();
  uVar5 = 0;
  pcVar4 = pcVar2;
  do {
    cVar1 = pcVar4[(iVar3 + 4) - (int)pcVar2];
    *pcVar4 = cVar1;
    if (cVar1 == '\0') goto LAB_006352e7;
    uVar5 = uVar5 + 1;
    pcVar4 = pcVar4 + 1;
  } while (uVar5 < 0x13);
  *pcVar2 = '\0';
LAB_006352e7:
  *(int **)(pcVar2 + 0x14) = unaff_EBX;
  iVar3 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))(pcVar2);
  return iVar3 == 0;
}


// ==== FUN_00635300 @ 0x00635300 ====

undefined4 FUN_00635300(int *param_1)

{
  int iVar1;
  int in_ECX;
  undefined1 auStack_18 [24];
  
  iVar1 = (**(code **)(*param_1 + 0x10))();
  FUN_00635500(iVar1 + 4);
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))(auStack_18);
  if (iVar1 == 0) {
    return 0;
  }
  (**(code **)(**(int **)(in_ECX + 8) + 0x40))(iVar1);
  (**(code **)(*DAT_00b5abe8 + 0x10))(1,param_1);
  return 1;
}


// ==== FUN_00635360 @ 0x00635360 ====

undefined4 FUN_00635360(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined1 local_18 [24];
  
  FUN_00635500(param_1);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_18);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 0x14);
}


// ==== FUN_006353a0 @ 0x006353a0 ====

void FUN_006353a0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a670;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1ad4;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  *(undefined1 *)((int)in_ECX + 0x15) = 0;
  *(undefined1 *)((int)in_ECX + 0x16) = 0;
  pvVar1 = operator_new(0x180);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00635550();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x168);
  local_4._0_1_ = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00635c00(in_ECX[1]);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar2;
  in_ECX[3] = 0;
  *(undefined2 *)(in_ECX + 4) = 0;
  *(undefined2 *)((int)in_ECX + 0x12) = 0;
  in_ECX[6] = 0;
  FUN_00797a50(in_ECX + 5,0,3);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00635470 @ 0x00635470 ====

void FUN_00635470(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1a44;
  return;
}


// ==== FUN_00635480 @ 0x00635480 ====

void FUN_00635480(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1a9c;
  return;
}


// ==== FUN_00635490 @ 0x00635490 ====

void FUN_00635490(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1ab4;
  return;
}


// ==== FUN_006354a0 @ 0x006354a0 ====

void FUN_006354a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1a44;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006354c0 @ 0x006354c0 ====

void FUN_006354c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1a9c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006354e0 @ 0x006354e0 ====

void FUN_006354e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1ab4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00635500 @ 0x00635500 ====

void FUN_00635500(int param_1)

{
  char cVar1;
  char *in_ECX;
  char *pcVar2;
  uint uVar3;
  
  uVar3 = 0;
  *in_ECX = '\0';
  pcVar2 = in_ECX;
  do {
    cVar1 = pcVar2[param_1 - (int)in_ECX];
    *pcVar2 = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar3 = uVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (uVar3 < 0x13);
  *in_ECX = '\0';
  return;
}


// ==== FUN_00635530 @ 0x00635530 ====

void FUN_00635530(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1acc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x24,10,FUN_006ef6d0);
  return;
}


// ==== FUN_00635550 @ 0x00635550 ====

void FUN_00635550(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a688;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1b1c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d1acc;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x24,10,FUN_00636380,FUN_006ef6d0);
  in_ECX[0x5c] = 0;
  in_ECX[0x5c] = in_ECX[0x5c] + 10;
  in_ECX[0x5d] = 0;
  in_ECX[0x5e] = 0;
  in_ECX[0x5f] = in_ECX + 2;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[8] = in_ECX + 0xb;
  in_ECX[0x11] = in_ECX + 0x14;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x1a] = in_ECX + 0x1d;
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  in_ECX[0x23] = in_ECX + 0x26;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x2c] = in_ECX + 0x2f;
  in_ECX[0x2d] = 0;
  in_ECX[0x2e] = 0;
  in_ECX[0x35] = in_ECX + 0x38;
  in_ECX[0x36] = 0;
  in_ECX[0x37] = 0;
  in_ECX[0x3e] = in_ECX + 0x41;
  in_ECX[0x3f] = 0;
  in_ECX[0x40] = 0;
  in_ECX[0x47] = in_ECX + 0x4a;
  in_ECX[0x48] = 0;
  in_ECX[0x49] = 0;
  in_ECX[0x50] = in_ECX + 0x53;
  in_ECX[0x51] = 0;
  in_ECX[0x52] = 0;
  in_ECX[0x59] = 0;
  in_ECX[0x5a] = 0;
  in_ECX[0x5b] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00635660 @ 0x00635660 ====

undefined4 FUN_00635660(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x174);
}


// ==== FUN_00635670 @ 0x00635670 ====

undefined1 * FUN_00635670(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098a6ab;
  local_c = ExceptionList;
  if (param_2 == (undefined1 *)0x0) {
    param_2 = *(undefined1 **)(in_ECX + 0x17c);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x174) = *(int *)(in_ECX + 0x174) + 1;
    if (param_2 == (undefined1 *)0x0) {
      param_2 = operator_new(0x24);
      if (param_2 == (undefined1 *)0x0) {
        param_2 = (undefined1 *)0x0;
      }
      else {
        *param_2 = 0;
      }
      *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(in_ECX + 0x178);
      *(undefined1 **)(in_ECX + 0x178) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x17c) = *(undefined4 *)(param_2 + 0x18);
    }
    *(undefined4 *)(param_2 + 0x18) = 0;
    *(int *)(param_2 + 0x20) = param_1;
  }
  else {
    if (*(int *)(param_2 + 0x20) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d1b30,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00635760 @ 0x00635760 ====

undefined4 FUN_00635760(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x20) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d1b30,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x20);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x20);
    }
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(in_ECX + 0x17c);
    *(int *)(in_ECX + 0x174) = *(int *)(in_ECX + 0x174) + -1;
    *(int *)(in_ECX + 0x17c) = param_2;
  }
  return 0;
}


// ==== FUN_006357e0 @ 0x006357e0 ====

void FUN_006357e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00635530();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00635800 @ 0x00635800 ====

void FUN_00635800(byte param_1)

{
  void *in_ECX;
  
  FUN_00635820();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00635820 @ 0x00635820 ====

void FUN_00635820(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a6d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1b1c;
  local_4 = 1;
  if ((void *)in_ECX[0x5e] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d1acc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x24,10,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d1a9c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x5e]);
  return;
}


// ==== FUN_006358a0 @ 0x006358a0 ====

void FUN_006358a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00635230();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006358c0 @ 0x006358c0 ====

void FUN_006358c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1ba8;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,10,FUN_006ef6d0);
  return;
}


// ==== FUN_006358e0 @ 0x006358e0 ====

void FUN_006358e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a6f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1bb0;
  local_4 = 1;
  if ((void *)in_ECX[0x54] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d1ba8;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,10,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d1ab4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x54]);
  return;
}


// ==== FUN_00635960 @ 0x00635960 ====

undefined4 FUN_00635960(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x14c);
}


// ==== FUN_00635970 @ 0x00635970 ====

undefined4 FUN_00635970(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d1b30,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x154);
    *(int *)(in_ECX + 0x14c) = *(int *)(in_ECX + 0x14c) + -1;
    *(int *)(in_ECX + 0x154) = param_2;
  }
  return 0;
}


// ==== FUN_006359f0 @ 0x006359f0 ====

undefined4 * FUN_006359f0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d1b30,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x154);
  *(int *)(in_ECX + 0x14c) = *(int *)(in_ECX + 0x14c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x150);
    *(undefined4 **)(in_ECX + 0x150) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x154) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_00635ab0 @ 0x00635ab0 ====

void FUN_00635ab0(byte param_1)

{
  void *in_ECX;
  
  FUN_006358c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00635ad0 @ 0x00635ad0 ====

void FUN_00635ad0(byte param_1)

{
  void *in_ECX;
  
  FUN_006358e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00635af0 @ 0x00635af0 ====

void FUN_00635af0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a708;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1bb0;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d1ba8;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,10,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x52] = 0;
  in_ECX[0x52] = in_ECX[0x52] + 10;
  in_ECX[0x53] = 0;
  in_ECX[0x54] = 0;
  in_ECX[0x55] = in_ECX + 2;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[7] = in_ECX + 10;
  in_ECX[0xf] = in_ECX + 0x12;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x17] = in_ECX + 0x1a;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1f] = in_ECX + 0x22;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x27] = in_ECX + 0x2a;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x2f] = in_ECX + 0x32;
  in_ECX[0x30] = 0;
  in_ECX[0x31] = 0;
  in_ECX[0x37] = in_ECX + 0x3a;
  in_ECX[0x38] = 0;
  in_ECX[0x39] = 0;
  in_ECX[0x3f] = in_ECX + 0x42;
  in_ECX[0x40] = 0;
  in_ECX[0x41] = 0;
  in_ECX[0x47] = in_ECX + 0x4a;
  in_ECX[0x48] = 0;
  in_ECX[0x49] = 0;
  in_ECX[0x4f] = 0;
  in_ECX[0x50] = 0;
  in_ECX[0x51] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00635c00 @ 0x00635c00 ====

void FUN_00635c00(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a728;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1bcc;
  FUN_00635af0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00635c60 @ 0x00635c60 ====

void FUN_00635c60(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00635c80(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00635c80 @ 0x00635c80 ====

void FUN_00635c80(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00635c80(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00635c80(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00635cc0 @ 0x00635cc0 ====

undefined4 * FUN_00635cc0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  int *unaff_EBP;
  
  iVar1 = in_ECX + 0x10;
  piVar3 = (int *)(**(code **)(*(int *)(in_ECX + 0x10) + 0xc))(1,0);
  *piVar3 = iVar1;
  piVar3[2] = 0;
  piVar3[3] = 0;
  piVar3[4] = 0;
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (puVar2 == (undefined4 *)0x0) {
    *(int **)(in_ECX + 4) = piVar3;
    return (undefined4 *)0x0;
  }
  iVar4 = FUN_00635d70(iVar1,*puVar2);
  do {
    if (iVar4 == 0) {
      (**(code **)(*unaff_EBP + 0x10))(1,piVar3);
      return puVar2;
    }
    if (iVar4 < 1) {
      puVar5 = (undefined4 *)puVar2[2];
      if (puVar5 == (undefined4 *)0x0) {
        piVar3[4] = (int)puVar2;
        puVar2[2] = piVar3;
        goto LAB_00635d59;
      }
    }
    else {
      puVar5 = (undefined4 *)puVar2[3];
      if (puVar5 == (undefined4 *)0x0) {
        piVar3[4] = (int)puVar2;
        puVar2[3] = piVar3;
LAB_00635d59:
        FUN_0061f0e0(piVar3,*(undefined4 *)(in_ECX + 4));
        return (undefined4 *)0x0;
      }
    }
    iVar4 = FUN_00635d70(iVar1,*puVar5);
    puVar2 = puVar5;
  } while( true );
}


// ==== FUN_00635d70 @ 0x00635d70 ====

uint FUN_00635d70(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = FUN_00635db0(param_2);
  if (cVar1 == '\0') {
    cVar1 = FUN_00635db0(param_1);
    return (uint)(cVar1 != '\0');
  }
  return 0xffffffff;
}


// ==== FUN_00635db0 @ 0x00635db0 ====

undefined4 FUN_00635db0(int param_1)

{
  char cVar1;
  char *in_ECX;
  uint uVar2;
  
  uVar2 = 0;
  param_1 = param_1 - (int)in_ECX;
  do {
    cVar1 = *in_ECX;
    if (cVar1 < in_ECX[param_1]) {
      return 1;
    }
    if (in_ECX[param_1] < cVar1) {
      return 0;
    }
    if (cVar1 == '\0') {
      return 0;
    }
    uVar2 = uVar2 + 1;
    in_ECX = in_ECX + 1;
  } while (uVar2 < 0x13);
  return 0;
}


// ==== FUN_00635df0 @ 0x00635df0 ====

void FUN_00635df0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00635e10(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00635e10 @ 0x00635e10 ====

void FUN_00635e10(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00635e10(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00635e10(param_1[3]);
  }
  _Memory = (void *)*param_1;
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 8) + 0x10))(1,_Memory);
    (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
    return;
  }
  if (_Memory == (void *)0x0) {
    (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00635e80 @ 0x00635e80 ====

undefined4 * FUN_00635e80(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = *(undefined4 **)(in_ECX + 4);
  if (*(undefined4 **)(in_ECX + 4) == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  do {
    puVar3 = puVar4;
    cVar1 = FUN_00635db0(*puVar3);
    if (cVar1 == '\0') {
      cVar1 = FUN_00635db0(param_1);
      if (cVar1 == '\0') {
        FUN_0061f0e0(puVar3,*(undefined4 *)(in_ECX + 4));
        return puVar3;
      }
      iVar2 = 1;
    }
    else {
      iVar2 = -1;
    }
    if (iVar2 < 0) {
      puVar4 = (undefined4 *)puVar3[2];
    }
    else {
      puVar4 = (undefined4 *)puVar3[3];
    }
  } while (puVar4 != (undefined4 *)0x0);
  FUN_0061f0e0(puVar3,*(undefined4 *)(in_ECX + 4));
  return (undefined4 *)0x0;
}


// ==== FUN_00635f10 @ 0x00635f10 ====

void FUN_00635f10(byte param_1)

{
  void *in_ECX;
  
  FUN_00635f30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00635f30 @ 0x00635f30 ====

void FUN_00635f30(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098a753;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1bcc;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00635e10(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_006358e0();
  *in_ECX = &PTR_FUN_009d1a44;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00635fa0 @ 0x00635fa0 ====

void FUN_00635fa0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1c24;
  return;
}


// ==== FUN_00635fb0 @ 0x00635fb0 ====

void FUN_00635fb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1c24;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00635fd0 @ 0x00635fd0 ====

void FUN_00635fd0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00635fd5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  return;
}


// ==== FUN_00635fe0 @ 0x00635fe0 ====

void FUN_00635fe0(void)

{
  int *piVar1;
  int in_ECX;
  
  for (piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(piVar1)) {
    (**(code **)(*DAT_00b5abe4 + 0x10))(1,*(undefined4 *)(*piVar1 + 0x1c));
  }
  (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}


// ==== FUN_00636030 @ 0x00636030 ====

undefined4 FUN_00636030(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
  *(int **)(in_ECX + 0xc) = piVar1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 0x1c);
}


// ==== FUN_00636050 @ 0x00636050 ====

undefined4 FUN_00636050(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(*(int *)(in_ECX + 0xc));
    *(int **)(in_ECX + 0xc) = piVar1;
    if (piVar1 != (int *)0x0) {
      return *(undefined4 *)(*piVar1 + 0x1c);
    }
  }
  return 0;
}


// ==== FUN_00636080 @ 0x00636080 ====

void FUN_00636080(void)

{
  int *piVar1;
  int in_ECX;
  
  for (piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(piVar1)) {
    (**(code **)(**(int **)(*piVar1 + 0x1c) + 0x18))();
  }
  return;
}


// ==== FUN_006360b0 @ 0x006360b0 ====

void FUN_006360b0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a768;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d1cdc;
  local_4 = 0;
  FUN_00635fe0();
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009d1c24;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00636120 @ 0x00636120 ====

bool FUN_00636120(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int in_ECX;
  char *pcVar4;
  int *unaff_EBX;
  uint uVar5;
  
  pcVar2 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  iVar3 = (**(code **)(*unaff_EBX + 0xc))();
  uVar5 = 0;
  pcVar4 = pcVar2;
  do {
    cVar1 = pcVar4[iVar3 - (int)pcVar2];
    *pcVar4 = cVar1;
    if (cVar1 == '\0') goto LAB_0063615f;
    uVar5 = uVar5 + 1;
    pcVar4 = pcVar4 + 1;
  } while (uVar5 < 0x19);
  *pcVar2 = '\0';
LAB_0063615f:
  *(int **)(pcVar2 + 0x1c) = unaff_EBX;
  iVar3 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))(pcVar2);
  return iVar3 == 0;
}


// ==== FUN_00636180 @ 0x00636180 ====

undefined4 FUN_00636180(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined1 auStack_20 [32];
  
  uVar1 = (**(code **)(*param_1 + 0xc))();
  FUN_00636350(uVar1);
  iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))(auStack_20);
  if (iVar2 == 0) {
    return 0;
  }
  (**(code **)(**(int **)(in_ECX + 8) + 0x40))(iVar2);
  (**(code **)(*DAT_00b5abe4 + 0x10))(1,param_1);
  return 1;
}


// ==== FUN_006361e0 @ 0x006361e0 ====

undefined4 FUN_006361e0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined1 local_20 [32];
  
  FUN_00636350(param_1);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_20);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 0x1c);
}


// ==== FUN_00636220 @ 0x00636220 ====

void FUN_00636220(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a790;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1cdc;
  pvVar1 = operator_new(0x540);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006363b0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(1000);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006369a0(in_ECX[1]);
  }
  in_ECX[2] = uVar2;
  in_ECX[3] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006362c0 @ 0x006362c0 ====

void FUN_006362c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1c4c;
  return;
}


// ==== FUN_006362d0 @ 0x006362d0 ====

void FUN_006362d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1ca4;
  return;
}


// ==== FUN_006362e0 @ 0x006362e0 ====

void FUN_006362e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1cbc;
  return;
}


// ==== FUN_006362f0 @ 0x006362f0 ====

void FUN_006362f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1c4c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00636310 @ 0x00636310 ====

void FUN_00636310(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1ca4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00636330 @ 0x00636330 ====

void FUN_00636330(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1cbc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00636350 @ 0x00636350 ====

void FUN_00636350(int param_1)

{
  char cVar1;
  char *in_ECX;
  char *pcVar2;
  uint uVar3;
  
  uVar3 = 0;
  *in_ECX = '\0';
  pcVar2 = in_ECX;
  do {
    cVar1 = pcVar2[param_1 - (int)in_ECX];
    *pcVar2 = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar3 = uVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (uVar3 < 0x19);
  *in_ECX = '\0';
  return;
}


// ==== FUN_00636380 @ 0x00636380 ====

void FUN_00636380(void)

{
  FUN_005fd550();
  return;
}


// ==== FUN_00636390 @ 0x00636390 ====

void FUN_00636390(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1cd4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x2c,0x1e,FUN_006ef6d0);
  return;
}


// ==== FUN_006363b0 @ 0x006363b0 ====

void FUN_006363b0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a7a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1d04;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d1cd4;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x2c,0x1e,FUN_00636380,FUN_006ef6d0);
  in_ECX[0x14c] = 0;
  in_ECX[0x14c] = in_ECX[0x14c] + 0x1e;
  in_ECX[0x14f] = in_ECX + 2;
  in_ECX[0x14d] = 0;
  in_ECX[0x14e] = 0;
  iVar2 = 0x1d;
  puVar1 = in_ECX;
  do {
    puVar1[10] = puVar1 + 0xd;
    puVar1[0xb] = 0;
    puVar1[0xc] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0xb;
  } while (iVar2 != 0);
  in_ECX[0x149] = 0;
  in_ECX[0x14a] = 0;
  in_ECX[0x14b] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00636460 @ 0x00636460 ====

undefined4 FUN_00636460(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x534);
}


// ==== FUN_00636470 @ 0x00636470 ====

undefined1 * FUN_00636470(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098a7cb;
  local_c = ExceptionList;
  if (param_2 == (undefined1 *)0x0) {
    param_2 = *(undefined1 **)(in_ECX + 0x53c);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x534) = *(int *)(in_ECX + 0x534) + 1;
    if (param_2 == (undefined1 *)0x0) {
      param_2 = operator_new(0x2c);
      if (param_2 == (undefined1 *)0x0) {
        param_2 = (undefined1 *)0x0;
      }
      else {
        *param_2 = 0;
      }
      *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(in_ECX + 0x538);
      *(undefined1 **)(in_ECX + 0x538) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x53c) = *(undefined4 *)(param_2 + 0x20);
    }
    *(undefined4 *)(param_2 + 0x20) = 0;
    *(int *)(param_2 + 0x28) = param_1;
  }
  else {
    if (*(int *)(param_2 + 0x28) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d1d18,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00636560 @ 0x00636560 ====

undefined4 FUN_00636560(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x28) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d1d18,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x28);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x28);
    }
    *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(in_ECX + 0x53c);
    *(int *)(in_ECX + 0x534) = *(int *)(in_ECX + 0x534) + -1;
    *(int *)(in_ECX + 0x53c) = param_2;
  }
  return 0;
}


// ==== FUN_006365e0 @ 0x006365e0 ====

void FUN_006365e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00636390();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00636600 @ 0x00636600 ====

void FUN_00636600(byte param_1)

{
  void *in_ECX;
  
  FUN_00636620();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00636620 @ 0x00636620 ====

void FUN_00636620(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a7f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1d04;
  local_4 = 1;
  if ((void *)in_ECX[0x14e] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d1cd4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x2c,0x1e,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d1ca4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x14e]);
  return;
}


// ==== FUN_006366a0 @ 0x006366a0 ====

void FUN_006366a0(byte param_1)

{
  void *in_ECX;
  
  FUN_006360b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006366c0 @ 0x006366c0 ====

void FUN_006366c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1d94;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x1e,FUN_006ef6d0);
  return;
}


// ==== FUN_006366e0 @ 0x006366e0 ====

void FUN_006366e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a813;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1d9c;
  local_4 = 1;
  if ((void *)in_ECX[0xf4] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d1d94;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x1e,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d1cbc;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0xf4]);
  return;
}


// ==== FUN_00636760 @ 0x00636760 ====

undefined4 FUN_00636760(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x3cc);
}


// ==== FUN_00636770 @ 0x00636770 ====

undefined4 FUN_00636770(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d1d18,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x3d4);
    *(int *)(in_ECX + 0x3cc) = *(int *)(in_ECX + 0x3cc) + -1;
    *(int *)(in_ECX + 0x3d4) = param_2;
  }
  return 0;
}


// ==== FUN_006367f0 @ 0x006367f0 ====

undefined4 * FUN_006367f0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d1d18,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x3d4);
  *(int *)(in_ECX + 0x3cc) = *(int *)(in_ECX + 0x3cc) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x3d0);
    *(undefined4 **)(in_ECX + 0x3d0) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x3d4) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_006368b0 @ 0x006368b0 ====

void FUN_006368b0(byte param_1)

{
  void *in_ECX;
  
  FUN_006366c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006368d0 @ 0x006368d0 ====

void FUN_006368d0(byte param_1)

{
  void *in_ECX;
  
  FUN_006366e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006368f0 @ 0x006368f0 ====

void FUN_006368f0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a828;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1d9c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d1d94;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x1e,FUN_00607500,FUN_006ef6d0);
  in_ECX[0xf2] = 0;
  in_ECX[0xf2] = in_ECX[0xf2] + 0x1e;
  in_ECX[0xf5] = in_ECX + 2;
  in_ECX[0xf3] = 0;
  in_ECX[0xf4] = 0;
  iVar2 = 0x1d;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0xef] = 0;
  in_ECX[0xf0] = 0;
  in_ECX[0xf1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006369a0 @ 0x006369a0 ====

void FUN_006369a0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a848;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1db4;
  FUN_006368f0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00636a00 @ 0x00636a00 ====

void FUN_00636a00(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00636a20(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00636a20 @ 0x00636a20 ====

void FUN_00636a20(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00636a20(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00636a20(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00636a60 @ 0x00636a60 ====

undefined4 * FUN_00636a60(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  int *unaff_EBP;
  
  iVar1 = in_ECX + 0x10;
  piVar3 = (int *)(**(code **)(*(int *)(in_ECX + 0x10) + 0xc))(1,0);
  *piVar3 = iVar1;
  piVar3[2] = 0;
  piVar3[3] = 0;
  piVar3[4] = 0;
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (puVar2 == (undefined4 *)0x0) {
    *(int **)(in_ECX + 4) = piVar3;
    return (undefined4 *)0x0;
  }
  iVar4 = FUN_00636b10(iVar1,*puVar2);
  do {
    if (iVar4 == 0) {
      (**(code **)(*unaff_EBP + 0x10))(1,piVar3);
      return puVar2;
    }
    if (iVar4 < 1) {
      puVar5 = (undefined4 *)puVar2[2];
      if (puVar5 == (undefined4 *)0x0) {
        piVar3[4] = (int)puVar2;
        puVar2[2] = piVar3;
        goto LAB_00636af9;
      }
    }
    else {
      puVar5 = (undefined4 *)puVar2[3];
      if (puVar5 == (undefined4 *)0x0) {
        piVar3[4] = (int)puVar2;
        puVar2[3] = piVar3;
LAB_00636af9:
        FUN_0061f0e0(piVar3,*(undefined4 *)(in_ECX + 4));
        return (undefined4 *)0x0;
      }
    }
    iVar4 = FUN_00636b10(iVar1,*puVar5);
    puVar2 = puVar5;
  } while( true );
}


// ==== FUN_00636b10 @ 0x00636b10 ====

uint FUN_00636b10(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = FUN_00636b50(param_2);
  if (cVar1 == '\0') {
    cVar1 = FUN_00636b50(param_1);
    return (uint)(cVar1 != '\0');
  }
  return 0xffffffff;
}


// ==== FUN_00636b50 @ 0x00636b50 ====

undefined4 FUN_00636b50(int param_1)

{
  char cVar1;
  char *in_ECX;
  uint uVar2;
  
  uVar2 = 0;
  param_1 = param_1 - (int)in_ECX;
  do {
    cVar1 = *in_ECX;
    if (cVar1 < in_ECX[param_1]) {
      return 1;
    }
    if (in_ECX[param_1] < cVar1) {
      return 0;
    }
    if (cVar1 == '\0') {
      return 0;
    }
    uVar2 = uVar2 + 1;
    in_ECX = in_ECX + 1;
  } while (uVar2 < 0x19);
  return 0;
}


// ==== FUN_00636b90 @ 0x00636b90 ====

void FUN_00636b90(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00636bb0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00636bb0 @ 0x00636bb0 ====

void FUN_00636bb0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00636bb0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00636bb0(param_1[3]);
  }
  _Memory = (void *)*param_1;
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 8) + 0x10))(1,_Memory);
    (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
    return;
  }
  if (_Memory == (void *)0x0) {
    (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00636c20 @ 0x00636c20 ====

undefined4 * FUN_00636c20(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = *(undefined4 **)(in_ECX + 4);
  if (*(undefined4 **)(in_ECX + 4) == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  do {
    puVar3 = puVar4;
    cVar1 = FUN_00636b50(*puVar3);
    if (cVar1 == '\0') {
      cVar1 = FUN_00636b50(param_1);
      if (cVar1 == '\0') {
        FUN_0061f0e0(puVar3,*(undefined4 *)(in_ECX + 4));
        return puVar3;
      }
      iVar2 = 1;
    }
    else {
      iVar2 = -1;
    }
    if (iVar2 < 0) {
      puVar4 = (undefined4 *)puVar3[2];
    }
    else {
      puVar4 = (undefined4 *)puVar3[3];
    }
  } while (puVar4 != (undefined4 *)0x0);
  FUN_0061f0e0(puVar3,*(undefined4 *)(in_ECX + 4));
  return (undefined4 *)0x0;
}


// ==== FUN_00636cb0 @ 0x00636cb0 ====

void FUN_00636cb0(byte param_1)

{
  void *in_ECX;
  
  FUN_00636cd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00636cd0 @ 0x00636cd0 ====

void FUN_00636cd0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098a873;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1db4;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00636bb0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_006366e0();
  *in_ECX = &PTR_FUN_009d1c4c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00636d40 @ 0x00636d40 ====

void FUN_00636d40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_00636d50 @ 0x00636d50 ====

void FUN_00636d50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_00636d80 @ 0x00636d80 ====

int FUN_00636d80(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00636d90 @ 0x00636d90 ====

bool FUN_00636d90(void)

{
  int in_ECX;
  
  return *(short *)(in_ECX + 0x10) != 0;
}


// ==== FUN_00636da0 @ 0x00636da0 ====

undefined1 FUN_00636da0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x12);
}


// ==== FUN_00636db0 @ 0x00636db0 ====

void FUN_00636db0(int param_1)

{
  char cVar1;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 0x10))();
  if (cVar1 == '\x01') {
    (**(code **)(*in_ECX + 0x18))(param_1);
    return;
  }
  in_ECX[2] = param_1;
  *(undefined1 *)((int)in_ECX + 0x12) = 1;
  return;
}


// ==== FUN_00636de0 @ 0x00636de0 ====

void FUN_00636de0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00636df0 @ 0x00636df0 ====

void FUN_00636df0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x12) = 0;
  return;
}


// ==== FUN_00636e00 @ 0x00636e00 ====

undefined2 FUN_00636e00(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0x10);
}


// ==== FUN_00636e10 @ 0x00636e10 ====

void FUN_00636e10(ushort param_1)

{
  int in_ECX;
  
  if (param_1 < 60000) {
    if ((int)(uint)*(ushort *)(in_ECX + 0x10) <= (int)(60000 - (uint)param_1)) {
      *(ushort *)(in_ECX + 0x10) = *(ushort *)(in_ECX + 0x10) + param_1;
      return;
    }
  }
  *(undefined2 *)(in_ECX + 0x10) = 60000;
  return;
}


// ==== FUN_00636e50 @ 0x00636e50 ====

void FUN_00636e50(ushort param_1)

{
  int in_ECX;
  
  if (*(ushort *)(in_ECX + 0x10) < param_1) {
    *(undefined2 *)(in_ECX + 0x10) = 0;
    return;
  }
  *(ushort *)(in_ECX + 0x10) = *(ushort *)(in_ECX + 0x10) - param_1;
  return;
}


// ==== FUN_00636e70 @ 0x00636e70 ====

void FUN_00636e70(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_00636e80 @ 0x00636e80 ====

undefined4 FUN_00636e80(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00636ea0 @ 0x00636ea0 ====

void FUN_00636ea0(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_00636ec0 @ 0x00636ec0 ====

void FUN_00636ec0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a888;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1e0c;
  FUN_00797a50(in_ECX + 2,0,0xc);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00636f10 @ 0x00636f10 ====

void FUN_00636f10(byte param_1)

{
  void *in_ECX;
  
  FUN_00636d50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00636f30 @ 0x00636f30 ====

void FUN_00636f30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_00636f40 @ 0x00636f40 ====

void FUN_00636f40(uint param_1,uint param_2)

{
  int in_ECX;
  
  if (param_1 < param_2) {
    *(uint *)(in_ECX + 0x10) = param_2 - param_1;
    *(uint *)(in_ECX + 8) = param_1;
    *(uint *)(in_ECX + 0xc) = param_2;
  }
  return;
}


// ==== FUN_00636f60 @ 0x00636f60 ====

undefined4 FUN_00636f60(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_00636f70 @ 0x00636f70 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00636f70(void)

{
  int in_ECX;
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  
  fVar2 = (float10)*(int *)(in_ECX + 0x10);
  if (*(int *)(in_ECX + 0x10) < 0) {
    fVar2 = fVar2 + (float10)_DAT_0099d104;
  }
  iVar1 = *(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8);
  fVar3 = (float10)iVar1;
  if (iVar1 < 0) {
    fVar3 = fVar3 + (float10)_DAT_0099d104;
  }
  return fVar2 / fVar3;
}


// ==== FUN_00636fa0 @ 0x00636fa0 ====

bool FUN_00636fa0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x10) == 0;
}


// ==== FUN_00636fb0 @ 0x00636fb0 ====

int FUN_00636fb0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00636fc0 @ 0x00636fc0 ====

void FUN_00636fc0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_00636fd0 @ 0x00636fd0 ====

void FUN_00636fd0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = 0;
  return;
}


// ==== FUN_00636fe0 @ 0x00636fe0 ====

void FUN_00636fe0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1e48;
  in_ECX[4] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  return;
}


// ==== FUN_00637000 @ 0x00637000 ====

void FUN_00637000(byte param_1)

{
  void *in_ECX;
  
  FUN_00636f30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00637020 @ 0x00637020 ====

void FUN_00637020(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1e68;
  return;
}


// ==== FUN_00637030 @ 0x00637030 ====

void FUN_00637030(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1e68;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00637050 @ 0x00637050 ====

void FUN_00637050(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1e8c;
  return;
}


// ==== FUN_00637060 @ 0x00637060 ====

void FUN_00637060(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1ee4;
  return;
}


// ==== FUN_00637070 @ 0x00637070 ====

void FUN_00637070(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1efc;
  return;
}


// ==== FUN_00637080 @ 0x00637080 ====

void FUN_00637080(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1e8c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006370a0 @ 0x006370a0 ====

void FUN_006370a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1ee4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006370c0 @ 0x006370c0 ====

void FUN_006370c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1efc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006370e0 @ 0x006370e0 ====

void FUN_006370e0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a8a8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d1f14;
  local_4 = 0;
  (**(code **)(*(int *)in_ECX[2] + 0x20))();
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009d1e68;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00637150 @ 0x00637150 ====

void FUN_00637150(undefined2 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))(&param_1);
  if (iVar1 == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00637178. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x40))();
  return;
}


// ==== FUN_00637180 @ 0x00637180 ====

bool FUN_00637180(undefined2 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))(&param_1);
  return iVar1 != 0;
}


// ==== FUN_006371a0 @ 0x006371a0 ====

void FUN_006371a0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = 0;
                    /* WARNING: Could not recover jumptable at 0x006371ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  return;
}


// ==== FUN_006371b0 @ 0x006371b0 ====

undefined2 FUN_006371b0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
  *(undefined4 **)(in_ECX + 0xc) = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  return *(undefined2 *)*puVar1;
}


// ==== FUN_006371d0 @ 0x006371d0 ====

undefined4 FUN_006371d0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(*(int *)(in_ECX + 0xc));
    *(undefined4 **)(in_ECX + 0xc) = puVar1;
    if (puVar1 != (undefined4 *)0x0) {
      return CONCAT22((short)((uint)*puVar1 >> 0x10),*(undefined2 *)*puVar1);
    }
  }
  return 0;
}


// ==== FUN_00637200 @ 0x00637200 ====

bool FUN_00637200(short param_1)

{
  short *psVar1;
  int iVar2;
  int in_ECX;
  
  if (param_1 == 0) {
    return false;
  }
  psVar1 = (short *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *psVar1 = param_1;
  iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))(psVar1);
  return iVar2 == 0;
}


// ==== FUN_00637240 @ 0x00637240 ====

void FUN_00637240(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a8d0;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1f14;
  pvVar1 = operator_new(0x818);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00637340();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x1028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006378e0(in_ECX[1]);
  }
  in_ECX[2] = uVar2;
  in_ECX[3] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006372e0 @ 0x006372e0 ====

void FUN_006372e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1f34;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x10,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_00637300 @ 0x00637300 ====

void FUN_00637300(byte param_1)

{
  void *in_ECX;
  
  FUN_006372e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00637320 @ 0x00637320 ====

void FUN_00637320(byte param_1)

{
  void *in_ECX;
  
  FUN_006370e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00637340 @ 0x00637340 ====

void FUN_00637340(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a8e8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1f3c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d1f34;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x10,0x80,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0x202] = 0;
  in_ECX[0x202] = in_ECX[0x202] + 0x80;
  in_ECX[0x205] = in_ECX + 2;
  in_ECX[0x203] = 0;
  in_ECX[0x204] = 0;
  iVar2 = 0x7f;
  puVar1 = in_ECX;
  do {
    puVar1[3] = puVar1 + 6;
    puVar1[4] = 0;
    puVar1[5] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 4;
  } while (iVar2 != 0);
  in_ECX[0x1ff] = 0;
  in_ECX[0x200] = 0;
  in_ECX[0x201] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006373f0 @ 0x006373f0 ====

undefined4 FUN_006373f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x80c);
}


// ==== FUN_00637400 @ 0x00637400 ====

void FUN_00637400(byte param_1)

{
  void *in_ECX;
  
  FUN_00637420();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00637420 @ 0x00637420 ====

void FUN_00637420(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a913;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1f3c;
  local_4 = 1;
  if ((void *)in_ECX[0x204] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d1f34;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x10,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d1ee4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x204]);
  return;
}


// ==== FUN_006374a0 @ 0x006374a0 ====

void * FUN_006374a0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098a92b;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x814);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x80c) = *(int *)(in_ECX + 0x80c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x10);
      *(undefined4 *)((int)param_2 + 8) = *(undefined4 *)(in_ECX + 0x810);
      *(void **)(in_ECX + 0x810) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x814) = *(undefined4 *)((int)param_2 + 4);
    }
    *(undefined4 *)((int)param_2 + 4) = 0;
    *(int *)((int)param_2 + 0xc) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0xc) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d1f50,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0xc) = *(int *)((int)param_2 + 0xc) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00637580 @ 0x00637580 ====

undefined4 FUN_00637580(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0xc) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d1f50,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0xc);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0xc);
    }
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(in_ECX + 0x814);
    *(int *)(in_ECX + 0x80c) = *(int *)(in_ECX + 0x80c) + -1;
    *(int *)(in_ECX + 0x814) = param_2;
  }
  return 0;
}


// ==== FUN_00637600 @ 0x00637600 ====

void FUN_00637600(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d1fc8;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_00637620 @ 0x00637620 ====

void FUN_00637620(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a953;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1fd0;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d1fc8;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d1efc;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_006376a0 @ 0x006376a0 ====

undefined4 FUN_006376a0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x100c);
}


// ==== FUN_006376b0 @ 0x006376b0 ====

undefined4 FUN_006376b0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d1f50,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x1014);
    *(int *)(in_ECX + 0x100c) = *(int *)(in_ECX + 0x100c) + -1;
    *(int *)(in_ECX + 0x1014) = param_2;
  }
  return 0;
}


// ==== FUN_00637730 @ 0x00637730 ====

undefined4 * FUN_00637730(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d1f50,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x1014);
  *(int *)(in_ECX + 0x100c) = *(int *)(in_ECX + 0x100c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x1010);
    *(undefined4 **)(in_ECX + 0x1010) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x1014) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_006377f0 @ 0x006377f0 ====

void FUN_006377f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00637600();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00637810 @ 0x00637810 ====

void FUN_00637810(byte param_1)

{
  void *in_ECX;
  
  FUN_00637620();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00637830 @ 0x00637830 ====

void FUN_00637830(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a968;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1fd0;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d1fc8;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x80,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x402] = 0;
  in_ECX[0x402] = in_ECX[0x402] + 0x80;
  in_ECX[0x405] = in_ECX + 2;
  in_ECX[0x403] = 0;
  in_ECX[0x404] = 0;
  iVar2 = 0x7f;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0x3ff] = 0;
  in_ECX[0x400] = 0;
  in_ECX[0x401] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006378e0 @ 0x006378e0 ====

void FUN_006378e0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a988;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1fec;
  FUN_00637830();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00637940 @ 0x00637940 ====

void FUN_00637940(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00637960(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00637960 @ 0x00637960 ====

void FUN_00637960(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00637960(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00637960(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_006379a0 @ 0x006379a0 ====

void FUN_006379a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_006379c0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_006379c0 @ 0x006379c0 ====

void FUN_006379c0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_006379c0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_006379c0(param_1[3]);
  }
  _Memory = (void *)*param_1;
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 8) + 0x10))(1,_Memory);
    (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
    return;
  }
  if (_Memory == (void *)0x0) {
    (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00637a30 @ 0x00637a30 ====

void FUN_00637a30(byte param_1)

{
  void *in_ECX;
  
  FUN_00637a50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00637a50 @ 0x00637a50 ====

void FUN_00637a50(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098a9b3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d1fec;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_006379c0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00637620();
  *in_ECX = &PTR_FUN_009d1e8c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00637ac0 @ 0x00637ac0 ====

void FUN_00637ac0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2044;
  return;
}


// ==== FUN_00637ad0 @ 0x00637ad0 ====

void FUN_00637ad0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2044;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00637af0 @ 0x00637af0 ====

void FUN_00637af0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00637af5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  return;
}


// ==== FUN_00637b00 @ 0x00637b00 ====

void FUN_00637b00(int *param_1)

{
  int *piVar1;
  undefined2 *puVar2;
  int iVar3;
  int in_ECX;
  undefined2 auStack_8 [4];
  
  piVar1 = (int *)(**(code **)(*param_1 + 0xc))();
  puVar2 = (undefined2 *)(**(code **)(*piVar1 + 4))();
  auStack_8[0] = *puVar2;
  iVar3 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))(auStack_8);
  if (iVar3 != 0) {
    (**(code **)(*param_1 + 0x14))(0);
    (**(code **)(**(int **)(in_ECX + 8) + 0x40))(iVar3);
    (**(code **)(*DAT_00b5abe0 + 0x10))(1,param_1);
  }
  return;
}


// ==== FUN_00637b60 @ 0x00637b60 ====

undefined4 FUN_00637b60(undefined2 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined2 local_8 [4];
  
  local_8[0] = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_00637b90 @ 0x00637b90 ====

void FUN_00637b90(void)

{
  int *piVar1;
  int in_ECX;
  
  for (piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(piVar1)) {
    (**(code **)(*DAT_00b5abe0 + 0x10))(1,*(undefined4 *)(*piVar1 + 4));
  }
  (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}


// ==== FUN_00637be0 @ 0x00637be0 ====

undefined4 FUN_00637be0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
  *(int **)(in_ECX + 0xc) = piVar1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_00637c00 @ 0x00637c00 ====

undefined4 FUN_00637c00(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(*(int *)(in_ECX + 0xc));
    *(int **)(in_ECX + 0xc) = piVar1;
    if (piVar1 != (int *)0x0) {
      return *(undefined4 *)(*piVar1 + 4);
    }
  }
  return 0;
}


// ==== FUN_00637c30 @ 0x00637c30 ====

void FUN_00637c30(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a9c8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d20fc;
  local_4 = 0;
  FUN_00637b90();
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009d2044;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00637ca0 @ 0x00637ca0 ====

bool FUN_00637ca0(int *param_1)

{
  undefined2 *puVar1;
  int *piVar2;
  undefined2 *puVar3;
  int iVar4;
  int in_ECX;
  
  (**(code **)(*param_1 + 0x14))(0);
  puVar1 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  piVar2 = (int *)(**(code **)(*param_1 + 0xc))();
  puVar3 = (undefined2 *)(**(code **)(*piVar2 + 4))();
  *puVar1 = *puVar3;
  *(int **)(puVar1 + 2) = param_1;
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))(puVar1);
  return iVar4 == 0;
}


// ==== FUN_00637cf0 @ 0x00637cf0 ====

void FUN_00637cf0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a9f0;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d20fc;
  pvVar1 = operator_new(0x1a8);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00637e60();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x2a8);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00638420(in_ECX[1]);
  }
  in_ECX[2] = uVar2;
  in_ECX[3] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00637d90 @ 0x00637d90 ====

void FUN_00637d90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d206c;
  return;
}


// ==== FUN_00637da0 @ 0x00637da0 ====

void FUN_00637da0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d20c4;
  return;
}


// ==== FUN_00637db0 @ 0x00637db0 ====

void FUN_00637db0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d20dc;
  return;
}


// ==== FUN_00637dc0 @ 0x00637dc0 ====

void FUN_00637dc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d206c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00637de0 @ 0x00637de0 ====

void FUN_00637de0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d20c4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00637e00 @ 0x00637e00 ====

void FUN_00637e00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d20dc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00637e20 @ 0x00637e20 ====

void FUN_00637e20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d20f4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x14,FUN_006ef6d0);
  return;
}


// ==== FUN_00637e40 @ 0x00637e40 ====

void FUN_00637e40(byte param_1)

{
  void *in_ECX;
  
  FUN_00637e20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00637e60 @ 0x00637e60 ====

void FUN_00637e60(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098aa08;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d2120;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d20f4;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,0x14,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0x66] = 0;
  in_ECX[0x66] = in_ECX[0x66] + 0x14;
  in_ECX[0x69] = in_ECX + 2;
  in_ECX[0x67] = 0;
  in_ECX[0x68] = 0;
  iVar2 = 0x13;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[99] = 0;
  in_ECX[100] = 0;
  in_ECX[0x65] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00637f10 @ 0x00637f10 ====

undefined4 FUN_00637f10(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x19c);
}


// ==== FUN_00637f20 @ 0x00637f20 ====

void FUN_00637f20(byte param_1)

{
  void *in_ECX;
  
  FUN_00637f40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00637f40 @ 0x00637f40 ====

void FUN_00637f40(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098aa33;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d2120;
  local_4 = 1;
  if ((void *)in_ECX[0x68] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d20f4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x14,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d20c4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x68]);
  return;
}


// ==== FUN_00637fc0 @ 0x00637fc0 ====

void * FUN_00637fc0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098aa4b;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x1a4);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x19c) = *(int *)(in_ECX + 0x19c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x1a0);
      *(void **)(in_ECX + 0x1a0) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x1a4) = *(undefined4 *)((int)param_2 + 8);
    }
    *(undefined4 *)((int)param_2 + 8) = 0;
    *(int *)((int)param_2 + 0x10) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d2138,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_006380a0 @ 0x006380a0 ====

undefined4 FUN_006380a0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d2138,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x1a4);
    *(int *)(in_ECX + 0x19c) = *(int *)(in_ECX + 0x19c) + -1;
    *(int *)(in_ECX + 0x1a4) = param_2;
  }
  return 0;
}


// ==== FUN_00638120 @ 0x00638120 ====

void FUN_00638120(byte param_1)

{
  void *in_ECX;
  
  FUN_00637c30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00638140 @ 0x00638140 ====

void FUN_00638140(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d21ac;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x14,FUN_006ef6d0);
  return;
}


// ==== FUN_00638160 @ 0x00638160 ====

void FUN_00638160(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098aa73;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d21b4;
  local_4 = 1;
  if ((void *)in_ECX[0xa4] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d21ac;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x14,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d20dc;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0xa4]);
  return;
}


// ==== FUN_006381e0 @ 0x006381e0 ====

undefined4 FUN_006381e0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x28c);
}


// ==== FUN_006381f0 @ 0x006381f0 ====

undefined4 FUN_006381f0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d2138,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x294);
    *(int *)(in_ECX + 0x28c) = *(int *)(in_ECX + 0x28c) + -1;
    *(int *)(in_ECX + 0x294) = param_2;
  }
  return 0;
}


// ==== FUN_00638270 @ 0x00638270 ====

undefined4 * FUN_00638270(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d2138,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x294);
  *(int *)(in_ECX + 0x28c) = *(int *)(in_ECX + 0x28c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x290);
    *(undefined4 **)(in_ECX + 0x290) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x294) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_00638330 @ 0x00638330 ====

void FUN_00638330(byte param_1)

{
  void *in_ECX;
  
  FUN_00638140();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00638350 @ 0x00638350 ====

void FUN_00638350(byte param_1)

{
  void *in_ECX;
  
  FUN_00638160();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00638370 @ 0x00638370 ====

void FUN_00638370(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098aa88;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d21b4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d21ac;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x14,FUN_00607500,FUN_006ef6d0);
  in_ECX[0xa2] = 0;
  in_ECX[0xa2] = in_ECX[0xa2] + 0x14;
  in_ECX[0xa5] = in_ECX + 2;
  in_ECX[0xa3] = 0;
  in_ECX[0xa4] = 0;
  iVar2 = 0x13;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0x9f] = 0;
  in_ECX[0xa0] = 0;
  in_ECX[0xa1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00638420 @ 0x00638420 ====

void FUN_00638420(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098aaa8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d21cc;
  FUN_00638370();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00638480 @ 0x00638480 ====

void FUN_00638480(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_006384a0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_006384a0 @ 0x006384a0 ====

void FUN_006384a0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_006384a0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_006384a0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_006384e0 @ 0x006384e0 ====

void FUN_006384e0(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 8);
    *(int *)(param_1 + 0xc) = iVar2;
    if (iVar2 != 0) {
      *(int *)(iVar2 + 0x10) = param_1;
    }
    iVar2 = *(int *)(param_1 + 0x10);
    *(int *)(iVar1 + 0x10) = iVar2;
    if (iVar2 == 0) {
      *(int *)(in_ECX + 4) = iVar1;
      *(int *)(iVar1 + 8) = param_1;
      *(int *)(param_1 + 0x10) = iVar1;
      return;
    }
    if (param_1 == *(int *)(iVar2 + 8)) {
      *(int *)(iVar2 + 8) = iVar1;
      *(int *)(iVar1 + 8) = param_1;
      *(int *)(param_1 + 0x10) = iVar1;
      return;
    }
    *(int *)(iVar2 + 0xc) = iVar1;
    *(int *)(iVar1 + 8) = param_1;
    *(int *)(param_1 + 0x10) = iVar1;
  }
  return;
}


// ==== FUN_00638530 @ 0x00638530 ====

void FUN_00638530(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00638550(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00638550 @ 0x00638550 ====

void FUN_00638550(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00638550(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00638550(param_1[3]);
  }
  _Memory = (void *)*param_1;
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 8) + 0x10))(1,_Memory);
    (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
    return;
  }
  if (_Memory == (void *)0x0) {
    (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_006385c0 @ 0x006385c0 ====

void FUN_006385c0(byte param_1)

{
  void *in_ECX;
  
  FUN_006385e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006385e0 @ 0x006385e0 ====

void FUN_006385e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098aad3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d21cc;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00638550(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00638160();
  *in_ECX = &PTR_FUN_009d206c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00638650 @ 0x00638650 ====

void FUN_00638650(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d24c4;
  return;
}


// ==== FUN_00638660 @ 0x00638660 ====

void FUN_00638660(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d24c4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00638680 @ 0x00638680 ====

void FUN_00638680(byte param_1,byte param_2,byte param_3)

{
  uint uVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  int iVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098aae8;
  local_c = ExceptionList;
  iVar3 = (uint)param_1 * (uint)param_2 * (uint)param_3;
  uVar1 = iVar3 * 8;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d252c;
  pvVar2 = operator_new(uVar1);
  in_ECX[2] = pvVar2;
  FUN_00797a50(pvVar2,0,uVar1);
  in_ECX[3] = iVar3;
  *(byte *)((int)in_ECX + 6) = param_3;
  *(byte *)(in_ECX + 1) = param_1;
  *(byte *)((int)in_ECX + 5) = param_2;
  in_ECX[4] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00638720 @ 0x00638720 ====

int FUN_00638720(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00638730 @ 0x00638730 ====

uint FUN_00638730(undefined4 param_1,undefined2 *param_2)

{
  byte bVar1;
  uint in_EAX;
  int *in_ECX;
  byte bVar2;
  byte local_5;
  undefined2 local_4;
  byte local_2;
  
  local_5 = 0;
  if ((char)in_ECX[1] != '\0') {
    do {
      bVar1 = 0;
      if (*(char *)((int)in_ECX + 6) != '\0') {
        do {
          bVar2 = 0;
          if (*(char *)((int)in_ECX + 5) != '\0') {
            do {
              local_4 = CONCAT11(bVar2,local_5);
              local_2 = bVar1;
              in_EAX = (**(code **)(*in_ECX + 0x30))(&local_4,param_1);
              if (in_EAX == 1) {
                *param_2 = local_4;
                *(byte *)(param_2 + 1) = local_2;
                return 1;
              }
              bVar2 = bVar2 + 1;
            } while (bVar2 < *(byte *)((int)in_ECX + 5));
          }
          bVar1 = bVar1 + 1;
          in_EAX = CONCAT31((int3)(in_EAX >> 8),bVar1);
        } while (bVar1 < *(byte *)((int)in_ECX + 6));
      }
      local_5 = local_5 + 1;
      in_EAX = CONCAT31((int3)(in_EAX >> 8),local_5);
    } while (local_5 < *(byte *)(in_ECX + 1));
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_006387f0 @ 0x006387f0 ====

undefined4 FUN_006387f0(byte *param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  int in_ECX;
  int iVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint uStack_8;
  
  iVar2 = (**(code **)(*param_2 + 0x2c))();
  bVar5 = param_1[1];
  uStack_8 = (uint)bVar5;
  if (uStack_8 < *(byte *)(iVar2 + 0x30) + uStack_8) {
    bVar3 = param_1[2];
    uVar6 = (uint)*(byte *)(iVar2 + 0x31) + (uint)bVar3;
    do {
      uVar7 = (uint)bVar3;
      bVar1 = bVar3;
      if (uVar7 < uVar6) {
        do {
          iVar4 = ((uint)*(byte *)(in_ECX + 6) * (uint)*param_1 + uVar7) *
                  (uint)*(byte *)(in_ECX + 5) + uStack_8;
          *(byte *)(*(int *)(in_ECX + 8) + iVar4 * 8) = bVar5 - param_1[1];
          *(byte *)(*(int *)(in_ECX + 8) + 1 + iVar4 * 8) = bVar1 - param_1[2];
          *(int **)(*(int *)(in_ECX + 8) + 4 + iVar4 * 8) = param_2;
          bVar3 = param_1[2];
          uVar6 = (uint)*(byte *)(iVar2 + 0x31) + (uint)bVar3;
          uVar7 = (uint)(byte)(bVar1 + 1);
          bVar1 = bVar1 + 1;
        } while (uVar7 < uVar6);
      }
      bVar5 = bVar5 + 1;
      uStack_8 = (uint)bVar5;
    } while (uStack_8 < (uint)param_1[1] + (uint)*(byte *)(iVar2 + 0x30));
  }
  return 1;
}


// ==== FUN_006388d0 @ 0x006388d0 ====

void FUN_006388d0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_006388e0 @ 0x006388e0 ====

void FUN_006388e0(void)

{
  int in_ECX;
  
  *(char *)(in_ECX + 4) = *(char *)(in_ECX + 4) + '\x01';
  return;
}


// ==== FUN_00638900 @ 0x00638900 ====

void FUN_00638900(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098aafa;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d252c;
  FUN_00797a50(in_ECX + 1,0,3);
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00638960 @ 0x00638960 ====

void FUN_00638960(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ab0c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d252c;
  local_4 = 0;
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_006389c0 @ 0x006389c0 ====

undefined4 FUN_006389c0(byte param_1,byte param_2,byte param_3)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  int iVar3;
  
  if (*(int *)(in_ECX + 8) == 0) {
    iVar3 = (uint)param_1 * (uint)param_2 * (uint)param_3;
    uVar1 = iVar3 * 8;
    pvVar2 = operator_new(uVar1);
    *(void **)(in_ECX + 8) = pvVar2;
    FUN_00797a50(pvVar2,0,uVar1);
    *(int *)(in_ECX + 0xc) = iVar3;
    *(byte *)(in_ECX + 4) = param_1;
    *(byte *)(in_ECX + 6) = param_3;
    *(byte *)(in_ECX + 5) = param_2;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    return 1;
  }
  return 0;
}


// ==== FUN_00638a30 @ 0x00638a30 ====

void FUN_00638a30(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x24))();
  while (iVar1 != 0) {
    (**(code **)(*DAT_00b5a730 + 0x10))(1,iVar1);
    iVar1 = (**(code **)(*in_ECX + 0x28))();
  }
  FUN_00797a50(in_ECX[2],0,in_ECX[3] * 8);
  in_ECX[4] = 0;
  return;
}


// ==== FUN_00638a80 @ 0x00638a80 ====

void FUN_00638a80(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    FUN_00797a50(*(int *)(in_ECX + 8),0,*(int *)(in_ECX + 0xc) * 8);
    *(undefined4 *)(in_ECX + 0x10) = 0;
  }
  return;
}


// ==== FUN_00638ab0 @ 0x00638ab0 ====

void FUN_00638ab0(int *param_1)

{
  char *pcVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  int in_ECX;
  byte bVar5;
  uint uVar6;
  byte bStack_8;
  byte bStack_7;
  char cStack_6;
  byte bStack_5;
  undefined4 uStack_4;
  
  (**(code **)(*param_1 + 0x10))();
  uStack_4 = FUN_00803725(param_1,0,&Framework::Article::IItem::IPackage::RTTI_Type_Descriptor,
                          &Framework::Article::Item::Package::RTTI_Type_Descriptor,0);
  uVar4 = 0;
  bVar3 = 0;
  if (*(char *)(in_ECX + 4) != '\0') {
    do {
      cVar2 = (char)uVar4;
      bStack_8 = 0;
      if (*(char *)(in_ECX + 6) != '\0') {
        do {
          uVar6 = 0;
          if (*(char *)(in_ECX + 5) != '\0') {
            do {
              pcVar1 = (char *)(*(int *)(in_ECX + 8) +
                               ((*(byte *)(in_ECX + 6) * uVar4 + (uint)bStack_8) *
                                (uint)*(byte *)(in_ECX + 5) + uVar6) * 8);
              if (((*(int *)(pcVar1 + 4) != 0) && (*pcVar1 == '\0')) && (pcVar1[1] == '\0')) {
                bStack_7 = bVar3;
                cStack_6 = (char)uVar6;
                bStack_5 = bStack_8;
                FUN_006387f0(&bStack_7,*(int *)(pcVar1 + 4));
              }
              bVar5 = (char)uVar6 + 1;
              uVar6 = (uint)bVar5;
            } while (bVar5 < *(byte *)(in_ECX + 5));
            uVar4 = (uint)bVar3;
          }
          cVar2 = (char)uVar4;
          bStack_8 = bStack_8 + 1;
        } while (bStack_8 < *(byte *)(in_ECX + 6));
      }
      bVar3 = cVar2 + 1;
      uVar4 = (uint)bVar3;
    } while (bVar3 < *(byte *)(in_ECX + 4));
  }
  return;
}


// ==== FUN_00638ba0 @ 0x00638ba0 ====

uint FUN_00638ba0(int param_1,undefined2 *param_2)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  uint in_EAX;
  int iVar4;
  undefined3 uVar5;
  int in_ECX;
  uint uVar6;
  byte bVar7;
  undefined2 local_4;
  
  if (param_1 == 0) {
    return in_EAX & 0xffffff00;
  }
  uVar6 = 0;
  if (*(byte *)(in_ECX + 4) != 0) {
    bVar1 = *(byte *)(in_ECX + 6);
    do {
      in_EAX = in_EAX & 0xffffff00;
      bVar3 = 0;
      if (bVar1 != 0) {
        do {
          bVar7 = 0;
          if (*(byte *)(in_ECX + 5) != 0) {
            iVar2 = *(int *)(in_ECX + 8);
            do {
              iVar4 = (uint)bVar7 + (bVar1 * uVar6 + (in_EAX & 0xff)) * (uint)*(byte *)(in_ECX + 5);
              local_4 = CONCAT11(bVar7,(char)uVar6);
              uVar5 = (undefined3)((uint)iVar4 >> 8);
              if (((*(int *)(iVar2 + 4 + iVar4 * 8) == param_1) &&
                  (*(char *)(iVar2 + iVar4 * 8) == '\0')) &&
                 (*(char *)(iVar2 + 1 + iVar4 * 8) == '\0')) {
                *param_2 = local_4;
                *(byte *)(param_2 + 1) = bVar3;
                return CONCAT31(uVar5,1);
              }
              bVar7 = bVar7 + 1;
            } while (bVar7 < *(byte *)(in_ECX + 5));
            in_EAX = CONCAT31(uVar5,bVar3);
          }
          bVar3 = (char)in_EAX + 1;
          in_EAX = CONCAT31((int3)(in_EAX >> 8),bVar3);
        } while (bVar3 < bVar1);
      }
      bVar3 = (char)uVar6 + 1;
      uVar6 = (uint)bVar3;
    } while (bVar3 < *(byte *)(in_ECX + 4));
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_00638c80 @ 0x00638c80 ====

undefined4 FUN_00638c80(void)

{
  char *pcVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  if (0 < *(int *)(in_ECX + 0xc)) {
    pcVar1 = *(char **)(in_ECX + 8);
    do {
      if (((*(int *)(pcVar1 + 4) != 0) && (*pcVar1 == '\0')) && (pcVar1[1] == '\0')) {
        *(int *)(in_ECX + 0x10) = iVar2;
        return *(undefined4 *)(*(char **)(in_ECX + 8) + iVar2 * 8 + 4);
      }
      iVar2 = iVar2 + 1;
      pcVar1 = pcVar1 + 8;
    } while (iVar2 < *(int *)(in_ECX + 0xc));
  }
  return 0;
}


// ==== FUN_00638cc0 @ 0x00638cc0 ====

undefined4 FUN_00638cc0(void)

{
  int iVar1;
  int in_ECX;
  char *pcVar2;
  
  iVar1 = *(int *)(in_ECX + 0x10) + 1;
  if (iVar1 < *(int *)(in_ECX + 0xc)) {
    pcVar2 = (char *)(*(int *)(in_ECX + 8) + iVar1 * 8);
    do {
      if (((*(int *)(pcVar2 + 4) != 0) && (*pcVar2 == '\0')) && (pcVar2[1] == '\0')) {
        *(int *)(in_ECX + 0x10) = iVar1;
        return *(undefined4 *)(*(int *)(in_ECX + 8) + 4 + iVar1 * 8);
      }
      iVar1 = iVar1 + 1;
      pcVar2 = pcVar2 + 8;
    } while (iVar1 < *(int *)(in_ECX + 0xc));
  }
  return 0;
}


// ==== FUN_00638d00 @ 0x00638d00 ====

int FUN_00638d00(void)

{
  int iVar1;
  int in_ECX;
  char *pcVar2;
  int iVar3;
  
  iVar3 = *(int *)(in_ECX + 0xc);
  iVar1 = 0;
  if (0 < iVar3) {
    pcVar2 = *(char **)(in_ECX + 8);
    do {
      if (((*(int *)(pcVar2 + 4) != 0) && (*pcVar2 == '\0')) && (pcVar2[1] == '\0')) {
        iVar1 = iVar1 + 1;
      }
      pcVar2 = pcVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar1;
}


// ==== FUN_00638d30 @ 0x00638d30 ====

uint FUN_00638d30(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0x30))(param_1,param_2);
  if (uVar1 == 1) {
    uVar1 = FUN_006387f0(param_1,param_2);
    return uVar1;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00638d60 @ 0x00638d60 ====

undefined4 FUN_00638d60(int *param_1,int *param_2)

{
  ushort uVar1;
  ushort uVar2;
  short *psVar3;
  short *psVar4;
  int *piVar5;
  int iVar6;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  
  if ((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) {
    return 0;
  }
  psVar3 = (short *)(**(code **)(*param_2 + 0x14))();
  psVar4 = (short *)(**(code **)(*param_1 + 0x14))();
  if (*psVar3 == *psVar4) {
    piVar5 = (int *)(**(code **)(*param_1 + 0x48))();
    iVar6 = (**(code **)(*piVar5 + 4))();
    uVar1 = *(ushort *)(iVar6 + 0x76);
    if (1 < uVar1) {
      uVar2 = psVar4[6];
      if (uVar2 < uVar1) {
        if ((ushort)psVar3[6] <= (ushort)(uVar1 - uVar2)) {
          (**(code **)(*param_1 + 0x20))
                    (CONCAT22(extraout_var_00,psVar3[6]) + CONCAT22(extraout_var,uVar2));
          (**(code **)(*param_2 + 0x20))(0);
          return 1;
        }
        (**(code **)(*param_1 + 0x20))(uVar1);
        (**(code **)(*param_2 + 0x20))(psVar3[6] - (uVar1 - uVar2));
      }
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00638e20 @ 0x00638e20 ====

undefined4 FUN_00638e20(int *param_1,undefined2 *param_2)

{
  ushort uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *in_ECX;
  byte local_b;
  byte local_a;
  byte local_9;
  undefined2 local_8;
  byte local_6;
  uint uStack_4;
  
  local_a = 0;
  if ((char)in_ECX[1] != '\0') {
    do {
      local_b = 0;
      if (*(char *)((int)in_ECX + 6) != '\0') {
        do {
          local_9 = 0;
          if (*(char *)((int)in_ECX + 5) != '\0') {
            do {
              local_6 = local_b;
              local_8 = CONCAT11(local_9,local_a);
              piVar2 = (int *)(**(code **)(*in_ECX + 0x18))(&local_8);
              if (piVar2 != (int *)0x0) {
                piVar3 = (int *)(**(code **)(*piVar2 + 0x48))();
                iVar4 = (**(code **)(*piVar3 + 4))();
                uVar1 = *(ushort *)(iVar4 + 0x76);
                iVar4 = (**(code **)(*in_ECX + 0x30))(&local_8,param_1);
                if (iVar4 == 5) {
                  iVar4 = (**(code **)(*param_1 + 0x14))();
                  uStack_4 = (uint)*(ushort *)(iVar4 + 0xc);
                  iVar4 = (**(code **)(*piVar2 + 0x14))();
                  if (((int)(uStack_4 + *(ushort *)(iVar4 + 0xc)) <= (int)(uint)uVar1) &&
                     (iVar4 = (**(code **)(*piVar3 + 4))(), *(char *)(iVar4 + 0x78) == '\x01')) {
                    *param_2 = local_8;
                    *(byte *)(param_2 + 1) = local_6;
                    return 1;
                  }
                }
              }
              local_9 = local_9 + 1;
            } while (local_9 < *(byte *)((int)in_ECX + 5));
          }
          local_b = local_b + 1;
        } while (local_b < *(byte *)((int)in_ECX + 6));
      }
      local_a = local_a + 1;
    } while (local_a < *(byte *)(in_ECX + 1));
  }
  return 0;
}


// ==== FUN_00638f50 @ 0x00638f50 ====

byte FUN_00638f50(byte *param_1,int *param_2)

{
  undefined2 uVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  short *psVar9;
  short *psVar10;
  int *in_ECX;
  byte bVar11;
  int *piVar12;
  byte bStack_109;
  byte bStack_108;
  byte bStack_107;
  byte bStack_106;
  int iStack_104;
  undefined1 auStack_100 [256];
  
  if (param_2 == (int *)0x0) {
    return -(*(int *)(in_ECX[2] + 4 +
                     ((uint)*(byte *)((int)in_ECX + 5) *
                      ((uint)*param_1 * (uint)*(byte *)((int)in_ECX + 6) + (uint)param_1[2]) +
                     (uint)param_1[1]) * 8) != 0) & 2;
  }
  piVar12 = (int *)0x0;
  iStack_104 = (**(code **)(*param_2 + 0x2c))();
  bStack_109 = param_1[1];
  if ((uint)*(byte *)(iStack_104 + 0x30) + (uint)bStack_109 <= (uint)bStack_109) {
    return 1;
  }
  do {
    bVar11 = param_1[2];
    if ((uint)bVar11 < (uint)*(byte *)(iStack_104 + 0x31) + (uint)bVar11) {
      do {
        bStack_108 = *param_1;
        bStack_107 = bStack_109;
        bStack_106 = bVar11;
        cVar2 = (**(code **)(*in_ECX + 0x4c))(&bStack_108);
        if (cVar2 == '\0') {
          return 0;
        }
        piVar3 = *(int **)(in_ECX[2] + 4 +
                          (((uint)*(byte *)((int)in_ECX + 6) * (uint)bStack_108 + (uint)bStack_106)
                           * (uint)*(byte *)((int)in_ECX + 5) + (uint)bStack_107) * 8);
        if (piVar3 != (int *)0x0) {
          if (piVar12 == (int *)0x0) {
            piVar12 = piVar3;
          }
          else if (piVar12 != piVar3) {
            return 0;
          }
        }
        bVar11 = bVar11 + 1;
      } while ((uint)bVar11 < (uint)*(byte *)(iStack_104 + 0x31) + (uint)param_1[2]);
    }
    bStack_109 = bStack_109 + 1;
  } while ((uint)bStack_109 < (uint)param_1[1] + (uint)*(byte *)(iStack_104 + 0x30));
  if (piVar12 == (int *)0x0) {
    return 1;
  }
  piVar3 = (int *)(**(code **)(*param_2 + 0x48))();
  iVar4 = (**(code **)(*piVar3 + 4))();
  if (*(int *)(iVar4 + 0xc) == 0x100) {
    bStack_109 = 0;
    iVar4 = (**(code **)(*piVar12 + 0x14))();
    if (*(char *)(iVar4 + 0x1e) != '\0') {
      do {
        iVar4 = (**(code **)(*piVar12 + 0x14))();
        if (*(short *)(iVar4 + 4 + (uint)bStack_109 * 2) == 0) {
          puVar5 = (undefined2 *)(**(code **)(*param_2 + 0x14))();
          uVar1 = *puVar5;
          piVar3 = (int *)(**(code **)(*DAT_00b5abb4 + 4))(uVar1);
          if (piVar3 == (int *)0x0) {
            auStack_100[0] = 0;
            uVar6 = FUN_0044a580(auStack_100,s___ASSERT___Null_SocketStone_Info_009d2274,uVar1);
            FUN_00797b80(uVar6);
          }
          else {
            piVar7 = (int *)(**(code **)(*piVar12 + 0x48))();
            iVar4 = *piVar3;
            iVar8 = (**(code **)(*piVar7 + 4))();
            cVar2 = (**(code **)(iVar4 + 0xc))(*(undefined4 *)(iVar8 + 0xc));
            if (cVar2 != '\0') {
              return 4;
            }
          }
        }
        bStack_109 = bStack_109 + 1;
        iVar4 = (**(code **)(*piVar12 + 0x14))();
      } while (bStack_109 < *(byte *)(iVar4 + 0x1e));
    }
    return 0;
  }
  psVar9 = (short *)(**(code **)(*piVar12 + 0x14))();
  psVar10 = (short *)(**(code **)(*param_2 + 0x14))();
  if (((*psVar9 == *psVar10) &&
      (iVar4 = (**(code **)(*piVar12 + 0x14))(), *(char *)(iVar4 + 0x21) == '\x01')) &&
     (iVar4 = (**(code **)(*param_2 + 0x14))(), *(char *)(iVar4 + 0x21) == '\x01')) {
    return 5;
  }
  return 3;
}


// ==== FUN_006391c0 @ 0x006391c0 ====

int * FUN_006391c0(uint param_1,int *param_2)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int *in_ECX;
  byte bVar10;
  uint uVar11;
  uint uStack_114;
  undefined4 uStack_110;
  
  uStack_110 = param_2;
  uStack_114 = param_1;
  iVar3 = (**(code **)(*in_ECX + 0x30))();
  if (iVar3 == 4) {
    piVar4 = (int *)(**(code **)(*param_2 + 0x48))();
    iVar3 = (**(code **)(*piVar4 + 4))();
    if (*(int *)(iVar3 + 0xc) == 0x100) {
      puVar5 = (undefined2 *)(**(code **)(*param_2 + 0x14))();
      uVar1 = *puVar5;
      piVar4 = (int *)(**(code **)(*in_ECX + 0x18))(param_1);
      piVar7 = (int *)(**(code **)(*DAT_00b5abb4 + 4))(uVar1);
      if (piVar7 == (int *)0x0) {
        uStack_110 = (int *)((uint)uStack_110 & 0xffffff00);
        uVar6 = FUN_0044a580(&uStack_110,s___ASSERT___Null_SocketStone_Info_009d2380,uVar1);
        FUN_00797b80(uVar6);
        return (int *)0x0;
      }
      piVar8 = (int *)(**(code **)(*piVar4 + 0x48))();
      iVar3 = *piVar7;
      iVar9 = (**(code **)(*piVar8 + 4))();
      cVar2 = (**(code **)(iVar3 + 0xc))(*(undefined4 *)(iVar9 + 0xc));
      if (cVar2 == '\0') {
        piVar4 = (int *)(**(code **)(*piVar4 + 0x48))();
        uStack_114 = uStack_114 & 0xffffff00;
        iVar3 = (**(code **)(*piVar4 + 4))();
        uVar6 = FUN_0044a580(&uStack_114,s___ASSERT___Invalie_Socket_Item_C_009d23bc,uVar1,
                             *(undefined4 *)(iVar3 + 0xc));
        FUN_00797b80(uVar6);
      }
      else {
        uVar11 = 0;
        iVar3 = (**(code **)(*piVar4 + 0x14))();
        if (*(char *)(iVar3 + 0x1e) == '\0') {
          return (int *)0x0;
        }
        while( true ) {
          iVar3 = (**(code **)(*piVar4 + 0x14))();
          if (*(short *)(iVar3 + 4 + uVar11 * 2) == 0) break;
          bVar10 = (char)uVar11 + 1;
          uVar11 = (uint)bVar10;
          iVar3 = (**(code **)(*piVar4 + 0x14))();
          if (*(byte *)(iVar3 + 0x1e) <= bVar10) {
            return (int *)0x0;
          }
        }
        cVar2 = (**(code **)(*piVar4 + 0x38))(uVar11,uVar1);
        if (cVar2 != '\0') {
          return piVar4;
        }
      }
      return (int *)0x0;
    }
    puVar5 = (undefined2 *)(**(code **)(*param_2 + 0x14))();
    uVar6 = FUN_0044a580((int)register0x00000010 + -0x108,
                         s_____Package__JoinItem_FAILED_____009d2300,*puVar5);
    FUN_00797b80(uVar6);
    piVar4 = DAT_00b5a698;
    puVar5 = (undefined2 *)(**(code **)(*param_2 + 0x14))();
    iVar3 = *piVar4;
    uVar6 = FUN_0044a580((int)register0x00000010 + -0x108,
                         s_____Package__JoinItem_FAILED_____009d2340,*puVar5);
    (**(code **)(iVar3 + 4))(uVar6);
  }
  return (int *)0x0;
}


// ==== FUN_00639370 @ 0x00639370 ====

int * FUN_00639370(undefined4 param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  iVar2 = (**(code **)(*in_ECX + 0x30))(param_1,param_2);
  if (iVar2 == 5) {
    uVar3 = (**(code **)(*in_ECX + 0x18))(param_1);
    cVar1 = FUN_00638d60(uVar3,param_2);
    if (cVar1 == '\x01') {
      iVar2 = (**(code **)(*param_2 + 0x14))();
      if (*(short *)(iVar2 + 0xc) != 0) {
        return param_2;
      }
      (**(code **)(*DAT_00b5a730 + 0x10))(1,param_2);
    }
  }
  return (int *)0x0;
}


// ==== FUN_006393d0 @ 0x006393d0 ====

undefined4 FUN_006393d0(byte *param_1)

{
  char cVar1;
  int *in_ECX;
  undefined1 auStack_fe [254];
  
  cVar1 = (**(code **)(*in_ECX + 0x4c))(param_1);
  if (cVar1 == '\0') {
    FUN_0044a580(auStack_fe + -6,&DAT_009d24b8,s___WARNING___INVALID_PLACE___geti_009d2224);
    FUN_00797b80(auStack_fe + -6);
    return 0;
  }
  return *(undefined4 *)
          (in_ECX[2] + 4 +
          (((uint)*(byte *)((int)in_ECX + 6) * (uint)*param_1 + (uint)param_1[2]) *
           (uint)*(byte *)((int)in_ECX + 5) + (uint)param_1[1]) * 8);
}


// ==== FUN_00639450 @ 0x00639450 ====

undefined4 FUN_00639450(byte *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int *in_ECX;
  undefined1 auStack_fe [254];
  
  cVar2 = (**(code **)(*in_ECX + 0x4c))(param_1);
  if (cVar2 == '\0') {
    FUN_0044a580(auStack_fe + -6,&DAT_009d24b8,s___WARNING___INVALID_PLACE___geti_009d224c);
    FUN_00797b80(auStack_fe + -6);
  }
  else {
    iVar3 = ((uint)*(byte *)((int)in_ECX + 6) * (uint)*param_1 + (uint)param_1[2]) *
            (uint)*(byte *)((int)in_ECX + 5) + (uint)param_1[1];
    iVar1 = in_ECX[2] + iVar3 * 8;
    if ((*(char *)(in_ECX[2] + iVar3 * 8) == '\0') && (*(char *)(iVar1 + 1) == '\0')) {
      return *(undefined4 *)(iVar1 + 4);
    }
  }
  return 0;
}


// ==== FUN_006394e0 @ 0x006394e0 ====

undefined4 FUN_006394e0(byte *param_1,int *param_2)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  byte bVar6;
  undefined1 auStack_108 [2];
  undefined1 auStack_106 [258];
  undefined4 uStack_4;
  
  iVar4 = (**(code **)(*in_ECX + 0x30))(param_1,param_2);
  if (iVar4 != 3) {
    return 0;
  }
  iVar4 = (**(code **)(*param_2 + 0x2c))();
  bVar3 = param_1[1];
  if ((uint)bVar3 < (uint)*(byte *)(iVar4 + 0x30) + (uint)bVar3) {
    do {
      bVar6 = param_1[2];
      if ((uint)bVar6 < (uint)*(byte *)(iVar4 + 0x31) + (uint)bVar6) {
        do {
          bVar1 = *param_1;
          cVar2 = (**(code **)(*in_ECX + 0x4c))(auStack_108 + -4);
          if (cVar2 == '\0') {
            FUN_0044a580(auStack_108,&DAT_009d24b8,s___WARNING___INVALID_PLACE___Swap_009d22b0);
            FUN_00797b80(auStack_108);
            return 0;
          }
          if (*(int *)(in_ECX[2] + 4 +
                      (((uint)*(byte *)((int)in_ECX + 6) * (CONCAT12(bVar6,(ushort)bVar1) & 0xff) +
                       (uint)bVar6) * (uint)*(byte *)((int)in_ECX + 5) + (uint)bVar3) * 8) != 0) {
            uVar5 = (**(code **)(*in_ECX + 0x3c))(auStack_108 + -4);
            FUN_006387f0(param_1,uStack_4);
            return uVar5;
          }
          bVar6 = bVar6 + 1;
        } while ((uint)bVar6 < (uint)param_1[2] + (uint)*(byte *)(iVar4 + 0x31));
      }
      bVar3 = bVar3 + 1;
    } while ((uint)bVar3 < (uint)param_1[1] + (uint)*(byte *)(iVar4 + 0x30));
  }
  return 0;
}


// ==== FUN_00639630 @ 0x00639630 ====

int * FUN_00639630(int param_1)

{
  ushort uVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  undefined4 unaff_EBX;
  undefined1 auStack_12a [2];
  undefined1 uStack_110;
  undefined1 uStack_10f;
  undefined1 auStack_10c [8];
  undefined1 auStack_104 [260];
  
  piVar3 = (int *)(**(code **)(*in_ECX + 0x18))();
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(auStack_104,&DAT_009d24b8);
    FUN_00797b80(auStack_104);
    return (int *)0x0;
  }
  iVar4 = (**(code **)(*piVar3 + 0x14))();
  uVar1 = *(ushort *)(iVar4 + 0xc);
  if (uVar1 <= (ushort)param_1) {
    FUN_0044a580(auStack_104,&DAT_009d24b8,s_Package__StackPick___wCount_<__w_009d2424);
    FUN_00797b80(auStack_104);
    return (int *)0x0;
  }
  piVar5 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))(1,0);
  if (piVar5 == (int *)0x0) {
    FUN_0044a580(auStack_10c,&DAT_009d24b8,s_Package__StackPick___pNewItem____009d2454);
    FUN_00797b80(auStack_10c);
    return (int *)0x0;
  }
  FUN_00797a50(auStack_12a + -6,0,0x24);
  (**(code **)(*piVar3 + 0x14))();
  uStack_10f = 1;
  cVar2 = (**(code **)(*piVar5 + 8))(auStack_12a + -6);
  if (cVar2 == '\0') {
    FUN_0044a580(&uStack_110,&DAT_009d24b8,s_Package__StackPick___pNewItem_>O_009d247c);
    FUN_00797b80(&uStack_110);
    (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar5);
    return (int *)0x0;
  }
  (**(code **)(*piVar3 + 0x20))(CONCAT22((short)((uint)unaff_EBX >> 0x10),uVar1) - param_1);
  return piVar5;
}


// ==== FUN_006397a0 @ 0x006397a0 ====

undefined4 FUN_006397a0(byte *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte bStack_9;
  byte local_8;
  byte local_7;
  byte local_6;
  uint uStack_4;
  
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  uVar2 = FUN_006399f0(param_1,&local_8);
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  iVar3 = (**(code **)(**(int **)(*(int *)(in_ECX + 8) + 4 +
                                 (((uint)*(byte *)(in_ECX + 6) * (uint)local_8 + (uint)local_6) *
                                  (uint)*(byte *)(in_ECX + 5) + (uint)local_7) * 8) + 0x2c))();
  bStack_9 = local_7;
  uStack_4 = (uint)local_7;
  if (uStack_4 < *(byte *)(iVar3 + 0x30) + uStack_4) {
    uVar6 = (uint)*(byte *)(iVar3 + 0x31) + (uint)local_6;
    do {
      uVar5 = (uint)local_6;
      if (uVar5 < uVar6) {
        bVar1 = local_6;
        do {
          iVar4 = ((uint)*(byte *)(in_ECX + 6) * (uint)*param_1 + uVar5) *
                  (uint)*(byte *)(in_ECX + 5) + uStack_4;
          *(undefined1 *)(*(int *)(in_ECX + 8) + iVar4 * 8) = 0;
          *(undefined1 *)(*(int *)(in_ECX + 8) + 1 + iVar4 * 8) = 0;
          *(undefined4 *)(*(int *)(in_ECX + 8) + 4 + iVar4 * 8) = 0;
          bVar1 = bVar1 + 1;
          uVar6 = (uint)*(byte *)(iVar3 + 0x31) + (uint)local_6;
          uVar5 = (uint)bVar1;
        } while (uVar5 < uVar6);
      }
      bStack_9 = bStack_9 + 1;
      uStack_4 = (uint)bStack_9;
    } while (uStack_4 < (uint)*(byte *)(iVar3 + 0x30) + (uint)local_7);
  }
  return 1;
}


// ==== FUN_006398c0 @ 0x006398c0 ====

undefined4 FUN_006398c0(undefined4 param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int *in_ECX;
  undefined4 uStack_110;
  
  uStack_110 = 0;
  iVar3 = (**(code **)(*in_ECX + 0x30))(param_1);
  if (iVar3 == 2) {
    cVar2 = (**(code **)(*in_ECX + 0x4c))(param_1);
    if (cVar2 != '\0') {
      uVar1 = *(undefined4 *)
               (in_ECX[2] + 4 +
               (((uint)*(byte *)((int)in_ECX + 6) * (uStack_110 & 0xff) +
                (uStack_110 >> 0x10 & 0xff)) * (uint)*(byte *)((int)in_ECX + 5) +
               (uStack_110 >> 8 & 0xff)) * 8);
      FUN_006397a0(&uStack_110);
      return uVar1;
    }
    FUN_0044a580((int)register0x00000010 + -0x10c,&DAT_009d24b8,
                 s___WARNING___INVALID_PLACE___popi_009d22d8);
    FUN_00797b80((int)register0x00000010 + -0x10c);
  }
  return 0;
}


// ==== FUN_006399a0 @ 0x006399a0 ====

bool FUN_006399a0(byte *param_1)

{
  int in_ECX;
  
  if ((*param_1 < *(byte *)(in_ECX + 4)) && (param_1[1] < *(byte *)(in_ECX + 5))) {
    return param_1[2] < *(byte *)(in_ECX + 6);
  }
  return false;
}


// ==== FUN_006399d0 @ 0x006399d0 ====

void FUN_006399d0(byte param_1)

{
  void *in_ECX;
  
  FUN_00638960();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006399f0 @ 0x006399f0 ====

undefined4 FUN_006399f0(byte *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int *in_ECX;
  undefined1 auStack_fe [254];
  
  cVar2 = (**(code **)(*in_ECX + 0x4c))(param_1);
  if (cVar2 == '\0') {
    FUN_0044a580(auStack_fe + -6,&DAT_009d24b8,s___WARNING___INVALID_PLACE___GetI_009d258c);
    FUN_00797b80(auStack_fe + -6);
    return 0;
  }
  iVar3 = ((uint)*(byte *)((int)in_ECX + 6) * (uint)*param_1 + (uint)param_1[2]) *
          (uint)*(byte *)((int)in_ECX + 5) + (uint)param_1[1];
  iVar1 = in_ECX[2];
  if (*(int *)(iVar1 + 4 + iVar3 * 8) != 0) {
    cVar2 = *(char *)(iVar1 + iVar3 * 8);
    param_1[2] = param_1[2] - *(char *)(iVar1 + 1 + iVar3 * 8);
    *param_1 = *param_1;
    param_1[1] = param_1[1] - cVar2;
    cVar2 = (**(code **)(*in_ECX + 0x4c))(param_1);
    if (cVar2 != '\0') {
      return 1;
    }
    FUN_0044a580(auStack_fe + -10,&DAT_009d24b8,s___WARNING___INVALID_PLACE___GetI_009d258c);
    FUN_00797b80(auStack_fe + -10);
  }
  return 0;
}


// ==== FUN_00639ad0 @ 0x00639ad0 ====

void FUN_00639ad0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d25bc;
  return;
}


// ==== FUN_00639ae0 @ 0x00639ae0 ====

void FUN_00639ae0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d25bc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00639b00 @ 0x00639b00 ====

void FUN_00639b00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d25bc;
  return;
}


// ==== FUN_00639b10 @ 0x00639b10 ====

int FUN_00639b10(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00639b20 @ 0x00639b20 ====

undefined1 FUN_00639b20(int param_1)

{
  char cVar1;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 0x14))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  in_ECX[1] = in_ECX[1] + param_1;
  return 1;
}


// ==== FUN_00639b50 @ 0x00639b50 ====

undefined1 FUN_00639b50(int param_1)

{
  char cVar1;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 0x18))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  in_ECX[1] = in_ECX[1] - param_1;
  return 1;
}


// ==== FUN_00639b80 @ 0x00639b80 ====

bool FUN_00639b80(uint param_1)

{
  int in_ECX;
  
  if (param_1 < 0x3b9aca01) {
    return *(uint *)(in_ECX + 4) <= 1000000000 - param_1;
  }
  return false;
}


// ==== FUN_00639ba0 @ 0x00639ba0 ====

bool FUN_00639ba0(uint param_1)

{
  int in_ECX;
  
  return param_1 <= *(uint *)(in_ECX + 4);
}


// ==== FUN_00639bc0 @ 0x00639bc0 ====

void FUN_00639bc0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ab28;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d25dc;
  FUN_00797a50(in_ECX + 1,0,4);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00639c10 @ 0x00639c10 ====

void FUN_00639c10(uint param_1)

{
  int in_ECX;
  
  if (1000000000 < param_1) {
    param_1 = 1000000000;
  }
  *(uint *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_00639c30 @ 0x00639c30 ====

void FUN_00639c30(byte param_1)

{
  void *in_ECX;
  
  FUN_00639b00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00639c50 @ 0x00639c50 ====

void FUN_00639c50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d263c;
  return;
}


// ==== FUN_00639c60 @ 0x00639c60 ====

void FUN_00639c60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d263c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00639c80 @ 0x00639c80 ====

void FUN_00639c80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d267c;
  return;
}


// ==== FUN_00639c90 @ 0x00639c90 ====

void FUN_00639c90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d26d4;
  return;
}


// ==== FUN_00639ca0 @ 0x00639ca0 ====

void FUN_00639ca0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d26ec;
  return;
}


// ==== FUN_00639cb0 @ 0x00639cb0 ====

void FUN_00639cb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d267c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00639cd0 @ 0x00639cd0 ====

void FUN_00639cd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d26d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00639cf0 @ 0x00639cf0 ====

void FUN_00639cf0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d26ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00639d10 @ 0x00639d10 ====

void FUN_00639d10(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  for (piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(piVar1)) {
    iVar2 = (**(code **)(**(int **)(*piVar1 + 4) + 0x14))();
    if (iVar2 != 0) {
      (**(code **)(*DAT_00b5a730 + 0x10))(1,iVar2);
    }
  }
  return;
}


// ==== FUN_00639d50 @ 0x00639d50 ====

void FUN_00639d50(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  
  (**(code **)(*param_1 + 0x10))();
  for (piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))(); piVar3 != (int *)0x0;
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(piVar3)) {
    piVar1 = *(int **)(*piVar3 + 4);
    iVar4 = (**(code **)(*piVar1 + 0x18))();
    if (iVar4 != 0) {
      iVar2 = *param_1;
      uVar5 = (**(code **)(*piVar1 + 4))(iVar4);
      (**(code **)(iVar2 + 0x18))(uVar5);
    }
  }
  return;
}


// ==== FUN_00639db0 @ 0x00639db0 ====

void FUN_00639db0(void)

{
  int *piVar1;
  int in_ECX;
  
  for (piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(piVar1)) {
    (**(code **)(**(int **)(*piVar1 + 4) + 0x14))();
  }
  return;
}


// ==== FUN_00639de0 @ 0x00639de0 ====

void FUN_00639de0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_8 [2];
  
  local_8[0] = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return;
  }
  (**(code **)(**(int **)(*piVar1 + 4) + 0x14))();
  return;
}


// ==== FUN_00639e10 @ 0x00639e10 ====

undefined4 FUN_00639e10(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 local_8 [2];
  
  local_8[0] = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  uVar2 = (**(code **)(**(int **)(*piVar1 + 4) + 0x10))(param_1);
  return uVar2;
}


// ==== FUN_00639e50 @ 0x00639e50 ====

void FUN_00639e50(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_8 [2];
  
  local_8[0] = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return;
  }
  (**(code **)(**(int **)(*piVar1 + 4) + 0x18))();
  return;
}


// ==== FUN_00639e80 @ 0x00639e80 ====

uint FUN_00639e80(undefined4 param_1,int param_2)

{
  uint in_EAX;
  int *piVar1;
  uint uVar2;
  int in_ECX;
  undefined4 local_8 [2];
  
  if (param_2 != 0) {
    local_8[0] = param_1;
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
    in_EAX = 0;
    if (piVar1 != (int *)0x0) {
      uVar2 = (**(code **)(**(int **)(*piVar1 + 4) + 0x1c))(param_2);
      return uVar2;
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_00639ec0 @ 0x00639ec0 ====

void FUN_00639ec0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_8 [2];
  
  local_8[0] = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return;
  }
  (**(code **)(**(int **)(*piVar1 + 4) + 0xc))(param_1);
  return;
}


// ==== __break @ 0x00639ef7 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00639f00 @ 0x00639f00 ====

undefined4 FUN_00639f00(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
  *(int **)(in_ECX + 0xc) = piVar1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_00639f20 @ 0x00639f20 ====

undefined4 FUN_00639f20(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(*(int *)(in_ECX + 0xc));
    *(int **)(in_ECX + 0xc) = piVar1;
    if (piVar1 != (int *)0x0) {
      return *(undefined4 *)(*piVar1 + 4);
    }
  }
  return 0;
}


// ==== FUN_00639f50 @ 0x00639f50 ====

undefined4 FUN_00639f50(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_8 [2];
  
  local_8[0] = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_00639f80 @ 0x00639f80 ====

undefined4 FUN_00639f80(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 local_8 [2];
  
  local_8[0] = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  uVar2 = (**(code **)(**(int **)(*piVar1 + 4) + 0x20))();
  return uVar2;
}


// ==== FUN_00639fc0 @ 0x00639fc0 ====

void FUN_00639fc0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_8 [2];
  
  local_8[0] = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  (**(code **)(**(int **)(*piVar1 + 4) + 0x24))(param_1);
  return;
}


// ==== FUN_00639ff0 @ 0x00639ff0 ====

void FUN_00639ff0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098abd8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d270c;
  local_4 = 0;
  FUN_00639d10();
  piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))();
  if (piVar1 != (int *)0x0) {
    do {
      if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
      }
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x48))(piVar1);
    } while (piVar1 != (int *)0x0);
  }
  (**(code **)(*(int *)in_ECX[2] + 0x20))();
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009d263c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0063a090 @ 0x0063a090 ====

void FUN_0063a090(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  undefined1 auStack_fe [254];
  
  uVar1 = FUN_0063a1a0(param_1);
  puVar2 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar2 = param_1;
  puVar2[1] = uVar1;
  iVar3 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar2);
  if (iVar3 != 0) {
    FUN_0044a580(auStack_fe + -0xe,&DAT_009d2634,s_LogicObjet_Article_Item_List_ePl_009d25fc);
    FUN_00797b80(auStack_fe + -0xe);
  }
  return;
}


// ==== FUN_0063a100 @ 0x0063a100 ====

void FUN_0063a100(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098ac00;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d270c;
  pvVar1 = operator_new(0x298);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0063a4f0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x428);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0063aa70(in_ECX[1]);
  }
  in_ECX[2] = uVar2;
  in_ECX[3] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063a1a0 @ 0x0063a1a0 ====

undefined4 FUN_0063a1a0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098abb9;
  local_c = ExceptionList;
  switch(param_1) {
  case 0:
  case 1:
  case 2:
  case 3:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00655ae0(param_1,in_ECX);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 4:
  case 5:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 7;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00654950(param_1,in_ECX);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 6:
  case 7:
  case 0x13:
  case 0x14:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 6;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00654d70(param_1,in_ECX);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 8:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 1;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_006558e0(8,in_ECX);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 9:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 2;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_006556e0(9,in_ECX);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 10:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 3;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_006554e0(10,in_ECX);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0xb:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 4;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_006552e0(0xb,in_ECX);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0xc:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 5;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_006550e0(0xc,in_ECX);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0xd:
  case 0xe:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 8;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00654680(param_1,in_ECX);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0xf:
  case 0x10:
  case 0x11:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 9;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00654480(param_1,in_ECX);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x12:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 10;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00654270(0x12,in_ECX);
      ExceptionList = local_c;
      return uVar2;
    }
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_0063a4b0 @ 0x0063a4b0 ====

void FUN_0063a4b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2704;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x20,FUN_006ef6d0);
  return;
}


// ==== FUN_0063a4d0 @ 0x0063a4d0 ====

void FUN_0063a4d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0063a4b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063a4f0 @ 0x0063a4f0 ====

void FUN_0063a4f0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ac18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d274c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d2704;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,0x20,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0xa2] = 0;
  in_ECX[0xa2] = in_ECX[0xa2] + 0x20;
  in_ECX[0xa5] = in_ECX + 2;
  in_ECX[0xa3] = 0;
  in_ECX[0xa4] = 0;
  iVar2 = 0x1f;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0x9f] = 0;
  in_ECX[0xa0] = 0;
  in_ECX[0xa1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063a5a0 @ 0x0063a5a0 ====

void FUN_0063a5a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0063a5c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063a5c0 @ 0x0063a5c0 ====

void FUN_0063a5c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ac43;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d274c;
  local_4 = 1;
  if ((void *)in_ECX[0xa4] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d2704;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x20,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d26d4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0xa4]);
  return;
}


// ==== FUN_0063a640 @ 0x0063a640 ====

void * FUN_0063a640(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d2760,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x294);
  *(int *)(in_ECX + 0x28c) = *(int *)(in_ECX + 0x28c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x14);
    *(undefined4 *)((int)pvVar2 + 0xc) = *(undefined4 *)(in_ECX + 0x290);
    *(void **)(in_ECX + 0x290) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x294) = *(undefined4 *)((int)pvVar2 + 8);
  }
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(int *)((int)pvVar2 + 0x10) = param_1;
  return pvVar2;
}


// ==== FUN_0063a6f0 @ 0x0063a6f0 ====

undefined4 FUN_0063a6f0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d2760,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x294);
    *(int *)(in_ECX + 0x28c) = *(int *)(in_ECX + 0x28c) + -1;
    *(int *)(in_ECX + 0x294) = param_2;
  }
  return 0;
}


// ==== FUN_0063a770 @ 0x0063a770 ====

void FUN_0063a770(byte param_1)

{
  void *in_ECX;
  
  FUN_00639ff0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063a790 @ 0x0063a790 ====

void FUN_0063a790(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d27d4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x20,FUN_006ef6d0);
  return;
}


// ==== FUN_0063a7b0 @ 0x0063a7b0 ====

void FUN_0063a7b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ac63;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d27dc;
  local_4 = 1;
  if ((void *)in_ECX[0x104] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d27d4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x20,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d26ec;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x104]);
  return;
}


// ==== FUN_0063a830 @ 0x0063a830 ====

undefined4 FUN_0063a830(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x40c);
}


// ==== FUN_0063a840 @ 0x0063a840 ====

undefined4 FUN_0063a840(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d2760,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x414);
    *(int *)(in_ECX + 0x40c) = *(int *)(in_ECX + 0x40c) + -1;
    *(int *)(in_ECX + 0x414) = param_2;
  }
  return 0;
}


// ==== FUN_0063a8c0 @ 0x0063a8c0 ====

undefined4 * FUN_0063a8c0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d2760,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x414);
  *(int *)(in_ECX + 0x40c) = *(int *)(in_ECX + 0x40c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x410);
    *(undefined4 **)(in_ECX + 0x410) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x414) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_0063a980 @ 0x0063a980 ====

void FUN_0063a980(byte param_1)

{
  void *in_ECX;
  
  FUN_0063a790();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063a9a0 @ 0x0063a9a0 ====

void FUN_0063a9a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0063a7b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063a9c0 @ 0x0063a9c0 ====

void FUN_0063a9c0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ac78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d27dc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d27d4;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x20,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x102] = 0;
  in_ECX[0x102] = in_ECX[0x102] + 0x20;
  in_ECX[0x105] = in_ECX + 2;
  in_ECX[0x103] = 0;
  in_ECX[0x104] = 0;
  iVar2 = 0x1f;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0xff] = 0;
  in_ECX[0x100] = 0;
  in_ECX[0x101] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063aa70 @ 0x0063aa70 ====

void FUN_0063aa70(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ac98;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d27f4;
  FUN_0063a9c0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063aad0 @ 0x0063aad0 ====

void FUN_0063aad0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0063aaf0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0063aaf0 @ 0x0063aaf0 ====

void FUN_0063aaf0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_0063aaf0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_0063aaf0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0063ab30 @ 0x0063ab30 ====

undefined4 * FUN_0063ab30(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int *unaff_EBX;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)(in_ECX + 0x10) + 0xc))(1,0);
  *puVar1 = unaff_EBX;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  if (*(undefined4 **)(in_ECX + 4) == (undefined4 *)0x0) {
    *(undefined4 **)(in_ECX + 4) = puVar1;
    return (undefined4 *)0x0;
  }
  puVar2 = *(undefined4 **)(in_ECX + 4);
  while( true ) {
    while (*unaff_EBX < *(int *)*puVar2) {
      if ((undefined4 *)puVar2[2] == (undefined4 *)0x0) {
        puVar1[4] = puVar2;
        puVar2[2] = puVar1;
        FUN_0061f0e0(puVar1,*(undefined4 *)(in_ECX + 4));
        return (undefined4 *)0x0;
      }
      puVar2 = (undefined4 *)puVar2[2];
    }
    if (*unaff_EBX <= *(int *)*puVar2) break;
    if ((undefined4 *)puVar2[3] == (undefined4 *)0x0) {
      puVar1[4] = puVar2;
      puVar2[3] = puVar1;
      FUN_0061f0e0(puVar1,*(undefined4 *)(in_ECX + 4));
      return (undefined4 *)0x0;
    }
    puVar2 = (undefined4 *)puVar2[3];
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,puVar1);
  return puVar2;
}


// ==== FUN_0063abe0 @ 0x0063abe0 ====

void FUN_0063abe0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0063ac00(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0063ac00 @ 0x0063ac00 ====

void FUN_0063ac00(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_0063ac00(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_0063ac00(param_1[3]);
  }
  _Memory = (void *)*param_1;
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 8) + 0x10))(1,_Memory);
    (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
    return;
  }
  if (_Memory == (void *)0x0) {
    (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_0063ac80 @ 0x0063ac80 ====

void FUN_0063ac80(byte param_1)

{
  void *in_ECX;
  
  FUN_0063aca0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063aca0 @ 0x0063aca0 ====

void FUN_0063aca0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098acc3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d27f4;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_0063ac00(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_0063a7b0();
  *in_ECX = &PTR_FUN_009d267c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063ad10 @ 0x0063ad10 ====

void FUN_0063ad10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d284c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063ad30 @ 0x0063ad30 ====

void FUN_0063ad30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d284c;
  return;
}


// ==== FUN_0063ad40 @ 0x0063ad40 ====

void FUN_0063ad40(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_0063ad50 @ 0x0063ad50 ====

undefined2 FUN_0063ad50(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 4);
}


// ==== FUN_0063ad60 @ 0x0063ad60 ====

undefined2 FUN_0063ad60(short param_1)

{
  int in_ECX;
  
  *(short *)(in_ECX + 4) = *(short *)(in_ECX + 4) + param_1;
  return 1;
}


// ==== FUN_0063ad70 @ 0x0063ad70 ====

uint FUN_0063ad70(int param_1)

{
  undefined4 in_EAX;
  uint uVar1;
  int in_ECX;
  
  uVar1 = CONCAT22((short)((uint)in_EAX >> 0x10),*(ushort *)(in_ECX + 4));
  if (*(ushort *)(in_ECX + 4) < (ushort)param_1) {
    return uVar1 & 0xffffff00;
  }
  param_1 = uVar1 - param_1;
  *(short *)(in_ECX + 4) = (short)param_1;
  return CONCAT31((int3)((uint)param_1 >> 8),1);
}


// ==== FUN_0063ad90 @ 0x0063ad90 ====

void FUN_0063ad90(byte param_1)

{
  int in_ECX;
  
  if (param_1 < 5) {
    *(byte *)(in_ECX + 6) = param_1;
    return;
  }
  *(undefined1 *)(in_ECX + 6) = 5;
  return;
}


// ==== FUN_0063adb0 @ 0x0063adb0 ====

undefined1 FUN_0063adb0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 6);
}


// ==== FUN_0063adc0 @ 0x0063adc0 ====

void FUN_0063adc0(void)

{
  int in_ECX;
  
  if (*(byte *)(in_ECX + 6) < 5) {
    *(byte *)(in_ECX + 6) = *(byte *)(in_ECX + 6) + 1;
    return;
  }
  *(undefined1 *)(in_ECX + 6) = 5;
  return;
}


// ==== FUN_0063ade0 @ 0x0063ade0 ====

void FUN_0063ade0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2870;
  *(undefined2 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  return;
}


// ==== FUN_0063ae00 @ 0x0063ae00 ====

void FUN_0063ae00(byte param_1)

{
  void *in_ECX;
  
  FUN_0063ad30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063ae20 @ 0x0063ae20 ====

void FUN_0063ae20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2894;
  return;
}


// ==== FUN_0063ae30 @ 0x0063ae30 ====

void FUN_0063ae30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2894;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063ae50 @ 0x0063ae50 ====

void FUN_0063ae50(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_0063ae60 @ 0x0063ae60 ====

undefined4 FUN_0063ae60(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_0063ae70 @ 0x0063ae70 ====

undefined1 FUN_0063ae70(int *param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  cVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  piVar2 = (int *)(**(code **)(*param_1 + 0x18))();
  (**(code **)(*piVar2 + 0x18))();
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x10))();
    (**(code **)(*piVar2 + 0x14))();
  }
  return 1;
}


// ==== FUN_0063aec0 @ 0x0063aec0 ====

void FUN_0063aec0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0063aec5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_0063aed0 @ 0x0063aed0 ====

void FUN_0063aed0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0063aed5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  return;
}


// ==== FUN_0063aee0 @ 0x0063aee0 ====

void FUN_0063aee0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0063aee5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x18))();
  return;
}


// ==== FUN_0063aef0 @ 0x0063aef0 ====

void FUN_0063aef0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ace3;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d28c8;
  pvVar1 = operator_new(0x10);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00655fe0();
  }
  in_ECX[1] = uVar2;
  in_ECX[2] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063af60 @ 0x0063af60 ====

void FUN_0063af60(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098acf5;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d28c8;
  local_4 = 0;
  iVar1 = (**(code **)(*(int *)in_ECX[1] + 0x14))();
  while (iVar1 != 0) {
    (**(code **)(*DAT_00b5abd8 + 8))(iVar1);
    iVar1 = (**(code **)(*(int *)in_ECX[1] + 0x18))();
  }
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009d2894;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0063afe0 @ 0x0063afe0 ====

void FUN_0063afe0(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  while (piVar2 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*piVar2 + 0x18))();
    iVar3 = (**(code **)(*piVar2 + 0x1c))();
    if (iVar3 != 0) {
      (**(code **)(*piVar2 + 0x20))(0);
    }
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x18))();
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x10))();
                    /* WARNING: Could not recover jumptable at 0x0063b038. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar2 + 0x14))();
    return;
  }
  return;
}


// ==== FUN_0063b040 @ 0x0063b040 ====

void FUN_0063b040(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *in_ECX;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x18))(param_1);
  if (piVar2 != (int *)0x0) {
    piVar3 = (int *)(**(code **)(*piVar2 + 0x18))();
    (**(code **)(*piVar3 + 0x18))(0);
    (**(code **)(*(int *)in_ECX[1] + 8))(param_1);
    (**(code **)(*DAT_00b5abd8 + 8))(piVar2);
    cVar1 = FUN_005c8e90();
    if (cVar1 == '\x01') {
      piVar2 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x10))();
      (**(code **)(*piVar2 + 0x14))();
    }
  }
  return;
}


// ==== FUN_0063b0a0 @ 0x0063b0a0 ====

bool FUN_0063b0a0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0xc))(param_1);
  return iVar1 == 0;
}


// ==== FUN_0063b0c0 @ 0x0063b0c0 ====

undefined4 FUN_0063b0c0(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  do {
    if (piVar2 == (int *)0x0) {
      return 1;
    }
    iVar3 = 0;
    do {
      cVar1 = (**(code **)(*piVar2 + 0x2c))(param_1);
      if (cVar1 == '\0') break;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x18))();
  } while( true );
}


// ==== FUN_0063b110 @ 0x0063b110 ====

undefined4 FUN_0063b110(undefined4 param_1)

{
  int *piVar1;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x28))(param_1);
  piVar1 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x14))();
  while (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))(param_1);
    piVar1 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x18))();
  }
  return 1;
}


// ==== FUN_0063b150 @ 0x0063b150 ====

void FUN_0063b150(byte param_1)

{
  void *in_ECX;
  
  FUN_0063af60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063b170 @ 0x0063b170 ====

void FUN_0063b170(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d28fc;
  return;
}


// ==== FUN_0063b180 @ 0x0063b180 ====

void FUN_0063b180(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d28fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063b1a0 @ 0x0063b1a0 ====

void FUN_0063b1a0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0063b1a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x20))();
  return;
}


// ==== FUN_0063b1b0 @ 0x0063b1b0 ====

undefined1 FUN_0063b1b0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = param_1;
  return 1;
}


// ==== FUN_0063b1c0 @ 0x0063b1c0 ====

undefined1 FUN_0063b1c0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 5) = param_1;
  return 1;
}


// ==== FUN_0063b1d0 @ 0x0063b1d0 ====

undefined1 FUN_0063b1d0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_0063b1e0 @ 0x0063b1e0 ====

undefined1 FUN_0063b1e0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 5);
}


// ==== FUN_0063b1f0 @ 0x0063b1f0 ====

void FUN_0063b1f0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ad08;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d29ac;
  local_4 = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_009d28fc;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0063b260 @ 0x0063b260 ====

undefined4 FUN_0063b260(undefined2 *param_1)

{
  int *piVar1;
  int in_ECX;
  undefined2 local_8 [4];
  
  local_8[0] = *param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_0063b290 @ 0x0063b290 ====

undefined4 FUN_0063b290(void)

{
  int *piVar1;
  int in_ECX;
  undefined2 local_8 [4];
  
  local_8[0] = *(undefined2 *)(in_ECX + 4);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_0063b2d0 @ 0x0063b2d0 ====

undefined4 FUN_0063b2d0(byte *param_1)

{
  int iVar1;
  undefined2 *puVar2;
  int in_ECX;
  undefined2 local_8 [2];
  undefined4 uStack_4;
  
  if ((1 < *param_1) || (8 < param_1[1])) {
    return 0;
  }
  local_8[0] = *(undefined2 *)param_1;
  iVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x30))(local_8);
  if (iVar1 != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x40))(iVar1);
  }
  puVar2 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 8) + 0xc))(1,0);
  *puVar2 = *(undefined2 *)param_1;
  *(undefined4 *)(puVar2 + 2) = uStack_4;
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x28))(puVar2);
  return 1;
}


// ==== FUN_0063b340 @ 0x0063b340 ====

void FUN_0063b340(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098ad30;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d29ac;
  pvVar1 = operator_new(0x298);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0063b4e0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x428);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0063ba70(in_ECX[2]);
  }
  in_ECX[3] = uVar2;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063b3e0 @ 0x0063b3e0 ====

void FUN_0063b3e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2924;
  return;
}


// ==== FUN_0063b3f0 @ 0x0063b3f0 ====

void FUN_0063b3f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d293c;
  return;
}


// ==== FUN_0063b400 @ 0x0063b400 ====

void FUN_0063b400(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2994;
  return;
}


// ==== FUN_0063b410 @ 0x0063b410 ====

void FUN_0063b410(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2924;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063b430 @ 0x0063b430 ====

void FUN_0063b430(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d293c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063b450 @ 0x0063b450 ====

void FUN_0063b450(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2994;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063b470 @ 0x0063b470 ====

void FUN_0063b470(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d29d4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x20,FUN_006ef6d0);
  return;
}


// ==== FUN_0063b490 @ 0x0063b490 ====

void FUN_0063b490(byte param_1)

{
  void *in_ECX;
  
  FUN_0063b470();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063b4c0 @ 0x0063b4c0 ====

void FUN_0063b4c0(byte param_1)

{
  void *in_ECX;
  
  FUN_0063b1f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063b4e0 @ 0x0063b4e0 ====

void FUN_0063b4e0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ad48;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d29dc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d29d4;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x14,0x20,(_func_void_void_ptr *)&LAB_0063b4b0,FUN_006ef6d0);
  in_ECX[0xa2] = 0;
  in_ECX[0xa2] = in_ECX[0xa2] + 0x20;
  in_ECX[0xa5] = in_ECX + 2;
  in_ECX[0xa3] = 0;
  in_ECX[0xa4] = 0;
  iVar2 = 0x1f;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0x9f] = 0;
  in_ECX[0xa0] = 0;
  in_ECX[0xa1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063b590 @ 0x0063b590 ====

void FUN_0063b590(byte param_1)

{
  void *in_ECX;
  
  FUN_0063b5b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063b5b0 @ 0x0063b5b0 ====

void FUN_0063b5b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ad73;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d29dc;
  local_4 = 1;
  if ((void *)in_ECX[0xa4] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d29d4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x20,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d2924;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0xa4]);
  return;
}


// ==== FUN_0063b630 @ 0x0063b630 ====

undefined1 * FUN_0063b630(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098ad8b;
  local_c = ExceptionList;
  if (param_2 == (undefined1 *)0x0) {
    param_2 = *(undefined1 **)(in_ECX + 0x294);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x28c) = *(int *)(in_ECX + 0x28c) + 1;
    if (param_2 == (undefined1 *)0x0) {
      param_2 = operator_new(0x14);
      if (param_2 == (undefined1 *)0x0) {
        param_2 = (undefined1 *)0x0;
      }
      else {
        *param_2 = 0;
        param_2[1] = 0;
      }
      *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x290);
      *(undefined1 **)(in_ECX + 0x290) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x294) = *(undefined4 *)(param_2 + 8);
    }
    *(undefined4 *)(param_2 + 8) = 0;
    *(int *)(param_2 + 0x10) = param_1;
  }
  else {
    if (*(int *)(param_2 + 0x10) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d29f0,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0063b720 @ 0x0063b720 ====

undefined4 FUN_0063b720(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d29f0,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x294);
    *(int *)(in_ECX + 0x28c) = *(int *)(in_ECX + 0x28c) + -1;
    *(int *)(in_ECX + 0x294) = param_2;
  }
  return 0;
}


// ==== FUN_0063b7a0 @ 0x0063b7a0 ====

void FUN_0063b7a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2a6c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x20,FUN_006ef6d0);
  return;
}


// ==== FUN_0063b7c0 @ 0x0063b7c0 ====

void FUN_0063b7c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098adb3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d2a74;
  local_4 = 1;
  if ((void *)in_ECX[0x104] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d2a6c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x20,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d2994;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x104]);
  return;
}


// ==== FUN_0063b840 @ 0x0063b840 ====

undefined4 FUN_0063b840(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d29f0,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x414);
    *(int *)(in_ECX + 0x40c) = *(int *)(in_ECX + 0x40c) + -1;
    *(int *)(in_ECX + 0x414) = param_2;
  }
  return 0;
}


// ==== FUN_0063b8c0 @ 0x0063b8c0 ====

undefined4 * FUN_0063b8c0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d29f0,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x414);
  *(int *)(in_ECX + 0x40c) = *(int *)(in_ECX + 0x40c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x410);
    *(undefined4 **)(in_ECX + 0x410) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x414) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_0063b980 @ 0x0063b980 ====

void FUN_0063b980(byte param_1)

{
  void *in_ECX;
  
  FUN_0063b7a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063b9a0 @ 0x0063b9a0 ====

void FUN_0063b9a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0063b7c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063b9c0 @ 0x0063b9c0 ====

void FUN_0063b9c0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098adc8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d2a74;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d2a6c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x20,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x102] = 0;
  in_ECX[0x102] = in_ECX[0x102] + 0x20;
  in_ECX[0x105] = in_ECX + 2;
  in_ECX[0x103] = 0;
  in_ECX[0x104] = 0;
  iVar2 = 0x1f;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0xff] = 0;
  in_ECX[0x100] = 0;
  in_ECX[0x101] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063ba70 @ 0x0063ba70 ====

void FUN_0063ba70(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ade8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d2a8c;
  FUN_0063b9c0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063bad0 @ 0x0063bad0 ====

void FUN_0063bad0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0063baf0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0063baf0 @ 0x0063baf0 ====

void FUN_0063baf0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_0063baf0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_0063baf0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0063bb30 @ 0x0063bb30 ====

undefined4 * FUN_0063bb30(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  int *unaff_EBP;
  
  iVar1 = in_ECX + 0x10;
  piVar3 = (int *)(**(code **)(*(int *)(in_ECX + 0x10) + 0xc))(1,0);
  *piVar3 = iVar1;
  piVar3[2] = 0;
  piVar3[3] = 0;
  piVar3[4] = 0;
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (puVar2 == (undefined4 *)0x0) {
    *(int **)(in_ECX + 4) = piVar3;
    return (undefined4 *)0x0;
  }
  iVar4 = FUN_0063bbe0(iVar1,*puVar2);
  do {
    if (iVar4 == 0) {
      (**(code **)(*unaff_EBP + 0x10))(1,piVar3);
      return puVar2;
    }
    if (iVar4 < 1) {
      puVar5 = (undefined4 *)puVar2[2];
      if (puVar5 == (undefined4 *)0x0) {
        piVar3[4] = (int)puVar2;
        puVar2[2] = piVar3;
        goto LAB_0063bbc9;
      }
    }
    else {
      puVar5 = (undefined4 *)puVar2[3];
      if (puVar5 == (undefined4 *)0x0) {
        piVar3[4] = (int)puVar2;
        puVar2[3] = piVar3;
LAB_0063bbc9:
        FUN_0061f0e0(piVar3,*(undefined4 *)(in_ECX + 4));
        return (undefined4 *)0x0;
      }
    }
    iVar4 = FUN_0063bbe0(iVar1,*puVar5);
    puVar2 = puVar5;
  } while( true );
}


// ==== FUN_0063bbe0 @ 0x0063bbe0 ====

uint FUN_0063bbe0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = FUN_0063bc20(param_2);
  if (cVar1 == '\0') {
    cVar1 = FUN_0063bc20(param_1);
    return (uint)(cVar1 != '\0');
  }
  return 0xffffffff;
}


// ==== FUN_0063bc20 @ 0x0063bc20 ====

undefined1 FUN_0063bc20(byte *param_1)

{
  byte *in_ECX;
  
  if ((*in_ECX < *param_1) || ((*in_ECX <= *param_1 && (in_ECX[1] < param_1[1])))) {
    return 1;
  }
  return 0;
}


// ==== FUN_0063bc50 @ 0x0063bc50 ====

void FUN_0063bc50(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0063bc70(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0063bc70 @ 0x0063bc70 ====

void FUN_0063bc70(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_0063bc70(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_0063bc70(param_1[3]);
  }
  _Memory = (void *)*param_1;
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 8) + 0x10))(1,_Memory);
    (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
    return;
  }
  if (_Memory == (void *)0x0) {
    (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_0063bcf0 @ 0x0063bcf0 ====

undefined4 * FUN_0063bcf0(byte *param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar5 = *(undefined4 **)(in_ECX + 4);
  if (*(undefined4 **)(in_ECX + 4) == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  do {
    puVar4 = puVar5;
    bVar1 = *(byte *)*puVar4;
    if ((*param_1 < bVar1) || ((*param_1 <= bVar1 && (param_1[1] < ((byte *)*puVar4)[1])))) {
      iVar3 = -1;
    }
    else {
      cVar2 = FUN_0063bd70(param_1);
      if (cVar2 == '\0') {
        FUN_0061f0e0(puVar4,*(undefined4 *)(in_ECX + 4));
        return puVar4;
      }
      iVar3 = 1;
    }
    if (iVar3 < 0) {
      puVar5 = (undefined4 *)puVar4[2];
    }
    else {
      puVar5 = (undefined4 *)puVar4[3];
    }
  } while (puVar5 != (undefined4 *)0x0);
  FUN_0061f0e0(puVar4,*(undefined4 *)(in_ECX + 4));
  return (undefined4 *)0x0;
}


// ==== FUN_0063bd70 @ 0x0063bd70 ====

bool FUN_0063bd70(byte *param_1)

{
  byte *in_ECX;
  
  if (*in_ECX < *param_1) {
    return true;
  }
  if (*param_1 < *in_ECX) {
    return false;
  }
  return in_ECX[1] < param_1[1];
}


// ==== FUN_0063bda0 @ 0x0063bda0 ====

void FUN_0063bda0(byte param_1)

{
  void *in_ECX;
  
  FUN_0063bdc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063bdc0 @ 0x0063bdc0 ====

void FUN_0063bdc0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098ae13;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d2a8c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_0063bc70(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_0063b7c0();
  *in_ECX = &PTR_FUN_009d293c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063be30 @ 0x0063be30 ====

int FUN_0063be30(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0063be40 @ 0x0063be40 ====

int FUN_0063be40(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0063be50 @ 0x0063be50 ====

int FUN_0063be50(void)

{
  int in_ECX;
  
  return in_ECX + 0xc;
}


// ==== FUN_0063be60 @ 0x0063be60 ====

int FUN_0063be60(void)

{
  int in_ECX;
  
  return in_ECX + 0x14;
}


// ==== FUN_0063be70 @ 0x0063be70 ====

int FUN_0063be70(void)

{
  int in_ECX;
  
  return in_ECX + 0x44;
}


// ==== FUN_0063be80 @ 0x0063be80 ====

int FUN_0063be80(void)

{
  int in_ECX;
  
  return in_ECX + 0xc0;
}


// ==== FUN_0063be90 @ 0x0063be90 ====

int FUN_0063be90(void)

{
  int in_ECX;
  
  return in_ECX + 200;
}


// ==== FUN_0063bea0 @ 0x0063bea0 ====

int FUN_0063bea0(void)

{
  int in_ECX;
  
  return in_ECX + 0xce;
}


// ==== FUN_0063beb0 @ 0x0063beb0 ====

int FUN_0063beb0(void)

{
  int in_ECX;
  
  return in_ECX + 0xd8;
}


// ==== FUN_0063bec0 @ 0x0063bec0 ====

int FUN_0063bec0(void)

{
  int in_ECX;
  
  return in_ECX + 0xf0;
}


// ==== FUN_0063bed0 @ 0x0063bed0 ====

int FUN_0063bed0(void)

{
  int in_ECX;
  
  return in_ECX + 0x100;
}


// ==== FUN_0063bee0 @ 0x0063bee0 ====

int FUN_0063bee0(void)

{
  int in_ECX;
  
  return in_ECX + 0x114;
}


// ==== FUN_0063bef0 @ 0x0063bef0 ====

int FUN_0063bef0(void)

{
  int in_ECX;
  
  return in_ECX + 0x116;
}


// ==== FUN_0063bf00 @ 0x0063bf00 ====

int FUN_0063bf00(void)

{
  int in_ECX;
  
  return in_ECX + 0xa8;
}


// ==== FUN_0063bf10 @ 0x0063bf10 ====

int FUN_0063bf10(void)

{
  int in_ECX;
  
  return in_ECX + 0x11e;
}


// ==== FUN_0063bf20 @ 0x0063bf20 ====

void FUN_0063bf20(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa8) = param_1;
  return;
}


// ==== FUN_0063bf30 @ 0x0063bf30 ====

int FUN_0063bf30(void)

{
  int in_ECX;
  
  return in_ECX + 0xac;
}


// ==== FUN_0063bf40 @ 0x0063bf40 ====

int FUN_0063bf40(void)

{
  int in_ECX;
  
  return in_ECX + 0xb4;
}


// ==== FUN_0063bf50 @ 0x0063bf50 ====

int FUN_0063bf50(void)

{
  int in_ECX;
  
  return in_ECX + 0x128;
}


// ==== FUN_0063bf60 @ 0x0063bf60 ====

void FUN_0063bf60(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_0063bf70 @ 0x0063bf70 ====

void FUN_0063bf70(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 10) = param_1;
  return;
}


// ==== FUN_0063bf80 @ 0x0063bf80 ====

void FUN_0063bf80(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_0063bf90 @ 0x0063bf90 ====

void FUN_0063bf90(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0xe) = param_1;
  return;
}


// ==== FUN_0063bfa0 @ 0x0063bfa0 ====

void FUN_0063bfa0(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_0063bfb0 @ 0x0063bfb0 ====

void FUN_0063bfb0(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x12) = param_1;
  return;
}


// ==== FUN_0063bfc0 @ 0x0063bfc0 ====

void FUN_0063bfc0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = param_1;
  return;
}


// ==== FUN_0063bfd0 @ 0x0063bfd0 ====

void FUN_0063bfd0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = param_1;
  return;
}


// ==== FUN_0063bfe0 @ 0x0063bfe0 ====

void FUN_0063bfe0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1c) = param_1;
  return;
}


// ==== FUN_0063bff0 @ 0x0063bff0 ====

void FUN_0063bff0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x20) = param_1;
  return;
}


// ==== FUN_0063c000 @ 0x0063c000 ====

void FUN_0063c000(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x24) = param_1;
  return;
}


// ==== FUN_0063c010 @ 0x0063c010 ====

void FUN_0063c010(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x28) = param_1;
  return;
}


// ==== FUN_0063c020 @ 0x0063c020 ====

void FUN_0063c020(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x2c) = param_1;
  return;
}


// ==== FUN_0063c030 @ 0x0063c030 ====

void FUN_0063c030(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x30) = param_1;
  return;
}


// ==== FUN_0063c040 @ 0x0063c040 ====

void FUN_0063c040(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x34) = param_1;
  return;
}


// ==== FUN_0063c050 @ 0x0063c050 ====

void FUN_0063c050(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x38) = param_1;
  return;
}


// ==== FUN_0063c060 @ 0x0063c060 ====

void FUN_0063c060(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x3c) = param_1;
  return;
}


// ==== FUN_0063c070 @ 0x0063c070 ====

void FUN_0063c070(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x40) = param_1;
  return;
}


// ==== FUN_0063c080 @ 0x0063c080 ====

void FUN_0063c080(undefined1 param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xfc) = param_1;
  *(undefined4 *)(in_ECX + 0xf0) = param_2;
  return;
}


// ==== FUN_0063c0a0 @ 0x0063c0a0 ====

void FUN_0063c0a0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xf4) = param_1;
  return;
}


// ==== FUN_0063c0c0 @ 0x0063c0c0 ====

void FUN_0063c0c0(undefined1 param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xfd) = param_1;
  *(undefined4 *)(in_ECX + 0xf8) = param_2;
  return;
}


// ==== FUN_0063c0e0 @ 0x0063c0e0 ====

void FUN_0063c0e0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10c) = param_1;
  return;
}


// ==== FUN_0063c0f0 @ 0x0063c0f0 ====

void FUN_0063c0f0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x128) = param_1;
  return;
}


// ==== FUN_0063c100 @ 0x0063c100 ====

void FUN_0063c100(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 300) = param_1;
  return;
}


// ==== FUN_0063c120 @ 0x0063c120 ====

undefined4 FUN_0063c120(int *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 8))();
  puVar3 = (undefined4 *)(in_ECX + 8);
  for (iVar2 = 0x4b; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  return 1;
}


// ==== FUN_0063c150 @ 0x0063c150 ====

void FUN_0063c150(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *param_1;
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0xac) = 0;
  }
  else if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0xac) = iVar1;
  }
  else {
    *(undefined4 *)(in_ECX + 0xac) = 0xffff;
  }
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0xb0) = 0;
    return;
  }
  if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0xb0) = iVar1;
    return;
  }
  *(undefined4 *)(in_ECX + 0xb0) = 0xffff;
  return;
}


// ==== FUN_0063c3a0 @ 0x0063c3a0 ====

void FUN_0063c3a0(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *param_1;
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x44) = 0;
  }
  else if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x44) = iVar1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x44) = 0xffff;
  }
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x48) = 0;
    return;
  }
  if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x48) = iVar1;
    return;
  }
  *(undefined4 *)(in_ECX + 0x48) = 0xffff;
  return;
}


// ==== FUN_0063c3f0 @ 0x0063c3f0 ====

void FUN_0063c3f0(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *param_1;
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x4c) = 0;
  }
  else if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x4c) = iVar1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x4c) = 0xffff;
  }
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x50) = 0;
    return;
  }
  if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x50) = iVar1;
    return;
  }
  *(undefined4 *)(in_ECX + 0x50) = 0xffff;
  return;
}


// ==== FUN_0063c440 @ 0x0063c440 ====

void FUN_0063c440(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *param_1;
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x54) = 0;
  }
  else if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x54) = iVar1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x54) = 0xffff;
  }
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x58) = 0;
    return;
  }
  if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x58) = iVar1;
    return;
  }
  *(undefined4 *)(in_ECX + 0x58) = 0xffff;
  return;
}


// ==== FUN_0063c490 @ 0x0063c490 ====

void FUN_0063c490(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *param_1;
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x5c) = 0;
  }
  else if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x5c) = iVar1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x5c) = 0xffff;
  }
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x60) = 0;
    return;
  }
  if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x60) = iVar1;
    return;
  }
  *(undefined4 *)(in_ECX + 0x60) = 0xffff;
  return;
}


// ==== FUN_0063c4e0 @ 0x0063c4e0 ====

void FUN_0063c4e0(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *param_1;
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 100) = 0;
  }
  else if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 100) = iVar1;
  }
  else {
    *(undefined4 *)(in_ECX + 100) = 0xffff;
  }
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x68) = 0;
    return;
  }
  if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x68) = iVar1;
    return;
  }
  *(undefined4 *)(in_ECX + 0x68) = 0xffff;
  return;
}


// ==== FUN_0063c530 @ 0x0063c530 ====

void FUN_0063c530(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *param_1;
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x6c) = 0;
  }
  else if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x6c) = iVar1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x6c) = 0xffff;
  }
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x74) = 0;
  }
  else if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x74) = iVar1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x74) = 0xffff;
  }
  iVar1 = (*(int *)(in_ECX + 0x6c) + *(int *)(in_ECX + 0x74)) / 2;
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x70) = 0;
    return;
  }
  if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x70) = iVar1;
    return;
  }
  *(undefined4 *)(in_ECX + 0x70) = 0xffff;
  return;
}


// ==== FUN_0063c5b0 @ 0x0063c5b0 ====

void FUN_0063c5b0(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *param_1;
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x78) = 0;
  }
  else if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x78) = iVar1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x78) = 0xffff;
  }
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x80) = 0;
  }
  else if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x80) = iVar1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x80) = 0xffff;
  }
  iVar1 = (*(int *)(in_ECX + 0x78) + *(int *)(in_ECX + 0x80)) / 2;
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x7c) = 0;
    return;
  }
  if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x7c) = iVar1;
    return;
  }
  *(undefined4 *)(in_ECX + 0x7c) = 0xffff;
  return;
}


// ==== FUN_0063c640 @ 0x0063c640 ====

void FUN_0063c640(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *param_1;
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x84) = 0;
  }
  else if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x84) = iVar1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x84) = 0xffff;
  }
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x8c) = 0;
  }
  else if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x8c) = iVar1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x8c) = 0xffff;
  }
  iVar1 = (*(int *)(in_ECX + 0x84) + *(int *)(in_ECX + 0x8c)) / 2;
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x88) = 0;
    return;
  }
  if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x88) = iVar1;
    return;
  }
  *(undefined4 *)(in_ECX + 0x88) = 0xffff;
  return;
}


// ==== FUN_0063c6e0 @ 0x0063c6e0 ====

void FUN_0063c6e0(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *param_1;
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x90) = 0;
  }
  else if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x90) = iVar1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x90) = 0xffff;
  }
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x98) = 0;
  }
  else if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x98) = iVar1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x98) = 0xffff;
  }
  iVar1 = (*(int *)(in_ECX + 0x90) + *(int *)(in_ECX + 0x98)) / 2;
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x94) = 0;
    return;
  }
  if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x94) = iVar1;
    return;
  }
  *(undefined4 *)(in_ECX + 0x94) = 0xffff;
  return;
}


// ==== FUN_0063c780 @ 0x0063c780 ====

void FUN_0063c780(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *param_1;
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0x9c) = 0;
  }
  else if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0x9c) = iVar1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x9c) = 0xffff;
  }
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0xa4) = 0;
  }
  else if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0xa4) = iVar1;
  }
  else {
    *(undefined4 *)(in_ECX + 0xa4) = 0xffff;
  }
  iVar1 = (*(int *)(in_ECX + 0x9c) + *(int *)(in_ECX + 0xa4)) / 2;
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 0xa0) = 0;
    return;
  }
  if (iVar1 < 0x10000) {
    *(int *)(in_ECX + 0xa0) = iVar1;
    return;
  }
  *(undefined4 *)(in_ECX + 0xa0) = 0xffff;
  return;
}


// ==== FUN_0063c820 @ 0x0063c820 ====

void FUN_0063c820(int param_1,int param_2)

{
  int in_ECX;
  
  if (param_1 < 0) {
    *(undefined4 *)(in_ECX + 0xc0) = 0;
  }
  else if (param_1 < 0x10000) {
    *(int *)(in_ECX + 0xc0) = param_1;
  }
  else {
    *(undefined4 *)(in_ECX + 0xc0) = 0xffff;
  }
  if (param_2 < 0) {
    *(undefined4 *)(in_ECX + 0xc4) = 0;
    return;
  }
  if (param_2 < 0x10000) {
    *(int *)(in_ECX + 0xc4) = param_2;
    return;
  }
  *(undefined4 *)(in_ECX + 0xc4) = 0xffff;
  return;
}


// ==== FUN_0063c880 @ 0x0063c880 ====

void FUN_0063c880(int param_1,byte param_2)

{
  int in_ECX;
  
  if (param_2 < 0x65) {
    *(byte *)(param_1 + 200 + in_ECX) = param_2;
    return;
  }
  *(undefined1 *)(param_1 + 200 + in_ECX) = 100;
  return;
}


// ==== FUN_0063c8b0 @ 0x0063c8b0 ====

void FUN_0063c8b0(int param_1,byte param_2)

{
  int in_ECX;
  
  if (param_2 < 0xfb) {
    *(byte *)(param_1 + 0xce + in_ECX) = param_2;
    return;
  }
  *(undefined1 *)(param_1 + 0xce + in_ECX) = 0xfa;
  return;
}


// ==== FUN_0063c8e0 @ 0x0063c8e0 ====

void FUN_0063c8e0(byte param_1,byte param_2)

{
  int in_ECX;
  
  if (param_1 < 0xfb) {
    *(byte *)(in_ECX + 0xd5) = param_1;
  }
  else {
    *(undefined1 *)(in_ECX + 0xd5) = 0xfa;
  }
  if (param_2 < 0xfb) {
    *(byte *)(in_ECX + 0xd6) = param_2;
    return;
  }
  *(undefined1 *)(in_ECX + 0xd6) = 0xfa;
  return;
}


// ==== FUN_0063c920 @ 0x0063c920 ====

void FUN_0063c920(int param_1,int param_2)

{
  int in_ECX;
  
  if (param_2 < 0) {
    *(undefined4 *)(in_ECX + 0xd8 + param_1 * 4) = 0;
    return;
  }
  if (param_2 < 0x10000) {
    *(int *)(in_ECX + 0xd8 + param_1 * 4) = param_2;
    return;
  }
  *(undefined4 *)(in_ECX + 0xd8 + param_1 * 4) = 0xffff;
  return;
}


// ==== FUN_0063c960 @ 0x0063c960 ====

void FUN_0063c960(byte param_1)

{
  int in_ECX;
  
  if (param_1 < 0xfb) {
    *(byte *)(in_ECX + 0xd4) = param_1;
    return;
  }
  *(undefined1 *)(in_ECX + 0xd4) = 0xfa;
  return;
}


// ==== FUN_0063c980 @ 0x0063c980 ====

void FUN_0063c980(byte param_1,byte param_2)

{
  int in_ECX;
  
  if (param_1 < 0x65) {
    *(byte *)(in_ECX + 0xb4) = param_1;
  }
  else {
    *(undefined1 *)(in_ECX + 0xb4) = 100;
  }
  if (param_2 < 0x65) {
    *(byte *)(in_ECX + 0xb5) = param_2;
    return;
  }
  *(undefined1 *)(in_ECX + 0xb5) = 100;
  return;
}


// ==== FUN_0063c9c0 @ 0x0063c9c0 ====

void FUN_0063c9c0(ushort param_1)

{
  int in_ECX;
  
  if (param_1 < 10000) {
    *(ushort *)(in_ECX + 0x100) = param_1;
    return;
  }
  *(undefined2 *)(in_ECX + 0x100) = 9999;
  return;
}


// ==== FUN_0063c9f0 @ 0x0063c9f0 ====

void FUN_0063c9f0(byte param_1)

{
  int in_ECX;
  
  if (param_1 < 0x65) {
    *(byte *)(in_ECX + 0x102) = param_1;
    return;
  }
  *(undefined1 *)(in_ECX + 0x102) = 100;
  return;
}


// ==== FUN_0063ca10 @ 0x0063ca10 ====

void FUN_0063ca10(byte param_1)

{
  int in_ECX;
  
  if (param_1 < 0x65) {
    *(byte *)(in_ECX + 0x103) = param_1;
    return;
  }
  *(undefined1 *)(in_ECX + 0x103) = 100;
  return;
}


// ==== FUN_0063ca30 @ 0x0063ca30 ====

void FUN_0063ca30(byte param_1)

{
  int in_ECX;
  
  if (param_1 < 0x65) {
    *(byte *)(in_ECX + 0x104) = param_1;
    return;
  }
  *(undefined1 *)(in_ECX + 0x104) = 100;
  return;
}


// ==== FUN_0063ca50 @ 0x0063ca50 ====

void FUN_0063ca50(byte param_1)

{
  int in_ECX;
  
  if (param_1 < 0x65) {
    *(byte *)(in_ECX + 0x105) = param_1;
    return;
  }
  *(undefined1 *)(in_ECX + 0x105) = 100;
  return;
}


// ==== FUN_0063ca70 @ 0x0063ca70 ====

void FUN_0063ca70(byte param_1,byte param_2)

{
  int in_ECX;
  
  if (param_1 < 0x65) {
    *(byte *)(in_ECX + 0x106) = param_1;
  }
  else {
    *(undefined1 *)(in_ECX + 0x106) = 100;
  }
  if (param_2 < 0x65) {
    *(byte *)(in_ECX + 0x107) = param_2;
    return;
  }
  *(undefined1 *)(in_ECX + 0x107) = 100;
  return;
}


// ==== FUN_0063cab0 @ 0x0063cab0 ====

void FUN_0063cab0(byte param_1)

{
  int in_ECX;
  
  if (param_1 < 0x65) {
    *(byte *)(in_ECX + 0x108) = param_1;
    return;
  }
  *(undefined1 *)(in_ECX + 0x108) = 100;
  return;
}


// ==== FUN_0063cad0 @ 0x0063cad0 ====

void FUN_0063cad0(int param_1,char param_2)

{
  int in_ECX;
  
  if (param_2 < -100) {
    *(undefined1 *)(param_1 + 0x116 + in_ECX) = 0x9c;
    return;
  }
  if (param_2 < 'e') {
    *(char *)(param_1 + 0x116 + in_ECX) = param_2;
    return;
  }
  *(undefined1 *)(param_1 + 0x116 + in_ECX) = 100;
  return;
}


// ==== FUN_0063cb00 @ 0x0063cb00 ====

void FUN_0063cb00(byte param_1)

{
  int in_ECX;
  
  if (param_1 < 0x65) {
    *(byte *)(in_ECX + 0x114) = param_1;
    return;
  }
  *(undefined1 *)(in_ECX + 0x114) = 100;
  return;
}


// ==== FUN_0063cb20 @ 0x0063cb20 ====

void FUN_0063cb20(byte param_1)

{
  int in_ECX;
  
  if (param_1 < 0x65) {
    *(byte *)(in_ECX + 0x115) = param_1;
    return;
  }
  *(undefined1 *)(in_ECX + 0x115) = 100;
  return;
}


// ==== FUN_0063cb40 @ 0x0063cb40 ====

void FUN_0063cb40(byte param_1,undefined2 param_2)

{
  int in_ECX;
  
  if (param_1 < 0x65) {
    *(byte *)(in_ECX + 0x11e) = param_1;
    *(undefined2 *)(in_ECX + 0x120) = param_2;
    return;
  }
  *(undefined1 *)(in_ECX + 0x11e) = 100;
  *(undefined2 *)(in_ECX + 0x120) = param_2;
  return;
}


// ==== FUN_0063cb80 @ 0x0063cb80 ====

void FUN_0063cb80(byte param_1,undefined2 param_2)

{
  int in_ECX;
  
  if (param_1 < 0x65) {
    *(byte *)(in_ECX + 0x122) = param_1;
    *(undefined2 *)(in_ECX + 0x124) = param_2;
    return;
  }
  *(undefined1 *)(in_ECX + 0x122) = 100;
  *(undefined2 *)(in_ECX + 0x124) = param_2;
  return;
}


// ==== FUN_0063cbc0 @ 0x0063cbc0 ====

void FUN_0063cbc0(byte param_1)

{
  int in_ECX;
  
  if (param_1 < 0x33) {
    *(byte *)(in_ECX + 0x11b) = param_1;
    return;
  }
  *(undefined1 *)(in_ECX + 0x11b) = 0x32;
  return;
}


// ==== FUN_0063cbe0 @ 0x0063cbe0 ====

void FUN_0063cbe0(byte param_1)

{
  int in_ECX;
  
  if (param_1 < 0x33) {
    *(byte *)(in_ECX + 0x11b) = param_1;
    return;
  }
  *(undefined1 *)(in_ECX + 0x11b) = 0x32;
  return;
}


// ==== FUN_0063cc00 @ 0x0063cc00 ====

void FUN_0063cc00(char param_1)

{
  int in_ECX;
  
  if (param_1 < -100) {
    *(undefined1 *)(in_ECX + 0x126) = 0x9c;
    return;
  }
  if (param_1 < 'e') {
    *(char *)(in_ECX + 0x126) = param_1;
    return;
  }
  *(undefined1 *)(in_ECX + 0x126) = 100;
  return;
}


// ==== FUN_0063cc30 @ 0x0063cc30 ====

void FUN_0063cc30(byte param_1)

{
  int in_ECX;
  
  if (param_1 < 0x65) {
    *(byte *)(in_ECX + 0x110) = param_1;
    return;
  }
  *(undefined1 *)(in_ECX + 0x110) = 100;
  return;
}


// ==== FUN_0063cc50 @ 0x0063cc50 ====

void FUN_0063cc50(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ae68;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d2ae4;
  local_4 = 0;
  FUN_0063cec0();
  *in_ECX = &PTR_FUN_009cbbc0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063cca0 @ 0x0063cca0 ====

void FUN_0063cca0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ae85;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d2ae4;
  FUN_0063cd20();
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00797a50(in_ECX + 2,0,300);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063cd00 @ 0x0063cd00 ====

void FUN_0063cd00(void)

{
  void *in_ECX;
  
  _eh_vector_destructor_iterator_(in_ECX,1,6,FUN_006ef6d0);
  return;
}


// ==== FUN_0063cd10 @ 0x0063cd10 ====

void FUN_0063cd10(void)

{
  void *in_ECX;
  
  _eh_vector_destructor_iterator_(in_ECX,4,6,FUN_006ef6d0);
  return;
}


// ==== FUN_0063cd20 @ 0x0063cd20 ====

void FUN_0063cd20(void)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098ae4a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  *(undefined4 *)(in_ECX + 0x70) = 0;
  *(undefined4 *)(in_ECX + 0x74) = 0;
  *(undefined4 *)(in_ECX + 0x78) = 0;
  *(undefined4 *)(in_ECX + 0x7c) = 0;
  *(undefined4 *)(in_ECX + 0x80) = 0;
  *(undefined4 *)(in_ECX + 0x84) = 0;
  *(undefined4 *)(in_ECX + 0x88) = 0;
  *(undefined4 *)(in_ECX + 0x8c) = 0;
  *(undefined4 *)(in_ECX + 0x90) = 0;
  *(undefined4 *)(in_ECX + 0x94) = 0;
  *(undefined4 *)(in_ECX + 0x98) = 0;
  *(undefined4 *)(in_ECX + 0x9c) = 0;
  *(undefined4 *)(in_ECX + 0xa4) = 0;
  *(undefined4 *)(in_ECX + 0xa8) = 0;
  *(undefined1 *)(in_ECX + 0xac) = 0;
  *(undefined1 *)(in_ECX + 0xad) = 0;
  *(undefined4 *)(in_ECX + 0xb8) = 0;
  *(undefined4 *)(in_ECX + 0xbc) = 0;
  _eh_vector_constructor_iterator_((void *)(in_ECX + 0xc0),1,6,FUN_005fd550,FUN_006ef6d0);
  local_4 = 0;
  _eh_vector_constructor_iterator_((void *)(in_ECX + 0xc6),1,6,FUN_005fd550,FUN_006ef6d0);
  *(undefined1 *)(in_ECX + 0xcc) = 0;
  *(undefined1 *)(in_ECX + 0xcd) = 0;
  *(undefined1 *)(in_ECX + 0xce) = 0;
  local_4._0_1_ = 1;
  _eh_vector_constructor_iterator_((void *)(in_ECX + 0xd0),4,6,FUN_0061c6c0,FUN_006ef6d0);
  *(undefined2 *)(in_ECX + 0xf8) = 0;
  *(undefined1 *)(in_ECX + 0xfa) = 0;
  *(undefined1 *)(in_ECX + 0xfb) = 0;
  *(undefined1 *)(in_ECX + 0xfc) = 0;
  *(undefined1 *)(in_ECX + 0xfd) = 0;
  *(undefined1 *)(in_ECX + 0xfe) = 0;
  *(undefined1 *)(in_ECX + 0xff) = 0;
  *(undefined1 *)(in_ECX + 0x100) = 0;
  *(undefined1 *)(in_ECX + 0x108) = 0;
  *(undefined1 *)(in_ECX + 0x10c) = 0;
  local_4 = CONCAT31(local_4._1_3_,2);
  *(undefined1 *)(in_ECX + 0x10d) = 0;
  _eh_vector_constructor_iterator_
            ((void *)(in_ECX + 0x10e),1,5,(_func_void_void_ptr *)&LAB_00616cf0,FUN_006ef6d0);
  *(undefined1 *)(in_ECX + 0x113) = 0;
  *(undefined1 *)(in_ECX + 0x114) = 0;
  *(undefined1 *)(in_ECX + 0x116) = 0;
  *(undefined1 *)(in_ECX + 0x11a) = 0;
  *(undefined1 *)(in_ECX + 0x11e) = 0x9c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063cec0 @ 0x0063cec0 ====

void FUN_0063cec0(void)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098ae4a;
  local_c = ExceptionList;
  local_4 = 2;
  ExceptionList = &local_c;
  _eh_vector_destructor_iterator_((void *)(in_ECX + 0x10e),1,5,FUN_006ef6d0);
  local_4._0_1_ = 1;
  _eh_vector_destructor_iterator_((void *)(in_ECX + 0xd0),4,6,FUN_006ef6d0);
  local_4 = (uint)local_4._1_3_ << 8;
  _eh_vector_destructor_iterator_((void *)(in_ECX + 0xc6),1,6,FUN_006ef6d0);
  local_4 = 0xffffffff;
  _eh_vector_destructor_iterator_((void *)(in_ECX + 0xc0),1,6,FUN_006ef6d0);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063cf60 @ 0x0063cf60 ====

void FUN_0063cf60(byte param_1)

{
  void *in_ECX;
  
  FUN_0063cc50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063cf80 @ 0x0063cf80 ====

void FUN_0063cf80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_0063cf90 @ 0x0063cf90 ====

undefined4 FUN_0063cf90(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00797a80(in_ECX + 8,param_1,8);
  return 1;
}


// ==== FUN_0063cfb0 @ 0x0063cfb0 ====

int FUN_0063cfb0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0063cfc0 @ 0x0063cfc0 ====

void FUN_0063cfc0(void)

{
  return;
}


// ==== FUN_0063cfd0 @ 0x0063cfd0 ====

void FUN_0063cfd0(undefined2 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 8) = param_1;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x10) + 0x10))();
    (**(code **)(*piVar2 + 0xc))();
  }
  return;
}


// ==== FUN_0063d000 @ 0x0063d000 ====

void FUN_0063d000(undefined2 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 10) = param_1;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x10) + 0x10))();
    (**(code **)(*piVar2 + 0xc))();
  }
  return;
}


// ==== FUN_0063d030 @ 0x0063d030 ====

void FUN_0063d030(undefined2 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0xc) = param_1;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x10) + 0x10))();
    (**(code **)(*piVar2 + 0xc))();
  }
  return;
}


// ==== FUN_0063d060 @ 0x0063d060 ====

void FUN_0063d060(undefined2 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0xe) = param_1;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x10) + 0x10))();
    (**(code **)(*piVar2 + 0xc))();
  }
  return;
}


// ==== FUN_0063d090 @ 0x0063d090 ====

void FUN_0063d090(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_0063d0a0 @ 0x0063d0a0 ====

void FUN_0063d0a0(void)

{
  int in_ECX;
  
  *(char *)(in_ECX + 0x14) = *(char *)(in_ECX + 0x14) + '\x01';
  return;
}


// ==== FUN_0063d0b0 @ 0x0063d0b0 ====

void FUN_0063d0b0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x14) = param_1;
  return;
}


// ==== FUN_0063d0c0 @ 0x0063d0c0 ====

undefined1 FUN_0063d0c0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x14);
}


// ==== FUN_0063d0d0 @ 0x0063d0d0 ====

void FUN_0063d0d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ae98;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d2c1c;
  in_ECX[4] = 0;
  FUN_00797a50(in_ECX + 2,0,8);
  *(undefined1 *)(in_ECX + 5) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063d130 @ 0x0063d130 ====

void FUN_0063d130(byte param_1)

{
  void *in_ECX;
  
  FUN_0063cf80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063d150 @ 0x0063d150 ====

void FUN_0063d150(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_0063d160 @ 0x0063d160 ====

int FUN_0063d160(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0063d170 @ 0x0063d170 ====

void FUN_0063d170(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_0063d180 @ 0x0063d180 ====

void FUN_0063d180(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098aeb8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d2ca0;
  FUN_00797a50(in_ECX + 2,0,1);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063d1d0 @ 0x0063d1d0 ====

undefined4 FUN_0063d1d0(byte param_1)

{
  int in_ECX;
  undefined1 local_100 [256];
  
  if ((int)(uint)*(byte *)(in_ECX + 8) < (int)(0xff - (uint)param_1)) {
    *(byte *)(in_ECX + 8) = *(byte *)(in_ECX + 8) + param_1;
    return 1;
  }
  *(undefined1 *)(in_ECX + 8) = 0xff;
  FUN_0044a580(local_100,&DAT_009d2c98,s_____WARNING_____Peerage_Overflow_009d2c50);
  FUN_00797b80(local_100);
  return 0;
}


// ==== FUN_0063d240 @ 0x0063d240 ====

undefined4 FUN_0063d240(byte param_1)

{
  int in_ECX;
  undefined1 local_100 [256];
  
  if (*(byte *)(in_ECX + 8) < param_1) {
    *(undefined1 *)(in_ECX + 8) = 0;
    FUN_0044a580(local_100,&DAT_009d2c98,s_____WARNING_____Peerage_Underflo_009d2c74);
    FUN_00797b80(local_100);
    return 0;
  }
  *(byte *)(in_ECX + 8) = *(byte *)(in_ECX + 8) - param_1;
  return 1;
}


// ==== FUN_0063d2a0 @ 0x0063d2a0 ====

void FUN_0063d2a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0063d150();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063d2c0 @ 0x0063d2c0 ====

void FUN_0063d2c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_0063d2d0 @ 0x0063d2d0 ====

int FUN_0063d2d0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0063d2e0 @ 0x0063d2e0 ====

void FUN_0063d2e0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00797a80(in_ECX + 8,param_1,8);
  return;
}


// ==== FUN_0063d300 @ 0x0063d300 ====

void FUN_0063d300(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_0063d310 @ 0x0063d310 ====

void FUN_0063d310(byte param_1)

{
  int in_ECX;
  
  *(byte *)(in_ECX + 0xc) = -(*(int *)(in_ECX + 8) != 0) & param_1;
  return;
}


// ==== FUN_0063d330 @ 0x0063d330 ====

void FUN_0063d330(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098aed8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d2cbc;
  FUN_00797a50(in_ECX + 2,0,8);
  in_ECX[2] = 1;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063d390 @ 0x0063d390 ====

void FUN_0063d390(byte param_1)

{
  void *in_ECX;
  
  FUN_0063d2c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063d3b0 @ 0x0063d3b0 ====

void FUN_0063d3b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_0063d3c0 @ 0x0063d3c0 ====

int FUN_0063d3c0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0063d3d0 @ 0x0063d3d0 ====

undefined4 FUN_0063d3d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_0063d3e0 @ 0x0063d3e0 ====

void FUN_0063d3e0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_0063d3f0 @ 0x0063d3f0 ====

void FUN_0063d3f0(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 8) = *param_1;
  return;
}


// ==== FUN_0063d400 @ 0x0063d400 ====

int FUN_0063d400(ushort *param_1)

{
  ushort uVar1;
  char cVar2;
  int *piVar3;
  int in_ECX;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar4;
  
  uVar1 = *(ushort *)(in_ECX + 8);
  if ((uint)uVar1 < *param_1 + 1) {
    *(undefined2 *)(in_ECX + 8) = 1;
  }
  else {
    *(ushort *)(in_ECX + 8) = uVar1 - *param_1;
  }
  cVar2 = FUN_005c8e90();
  uVar4 = extraout_var;
  if (cVar2 == '\x01') {
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0x10) + 0x10))();
    (**(code **)(*piVar3 + 8))();
    uVar4 = extraout_var_00;
  }
  return (uint)uVar1 - CONCAT22(uVar4,*(undefined2 *)(in_ECX + 8));
}


// ==== FUN_0063d450 @ 0x0063d450 ====

void FUN_0063d450(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_0063d480 @ 0x0063d480 ====

uint FUN_0063d480(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  undefined4 in_EAX;
  uint uVar4;
  ushort *puVar5;
  undefined4 uVar6;
  int *piVar7;
  int in_ECX;
  undefined4 unaff_EDI;
  
  uVar1 = *param_1;
  uVar4 = CONCAT22((short)((uint)in_EAX >> 0x10),uVar1);
  if ((uVar1 == 0) ||
     (uVar4 = (uint)uVar1, (int)(0xffff - uVar4) <= (int)(uint)*(ushort *)(in_ECX + 8))) {
    return uVar4 & 0xffff0000;
  }
  puVar5 = (ushort *)(**(code **)(*DAT_00b5a6b8 + 4))();
  uVar1 = *(ushort *)(in_ECX + 8);
  if (*puVar5 <= uVar1) {
    return (uint)puVar5 & 0xffff0000;
  }
  uVar2 = *param_1;
  puVar5 = (ushort *)(**(code **)(*DAT_00b5a6b8 + 4))();
  uVar3 = *puVar5;
  if ((ushort)(uVar2 + uVar1) < *puVar5) {
    uVar3 = uVar2 + uVar1;
  }
  *(ushort *)(in_ECX + 8) = uVar3;
  uVar6 = FUN_005c8e90();
  if ((char)uVar6 == '\x01') {
    piVar7 = (int *)(**(code **)(**(int **)(in_ECX + 0x10) + 0x10))();
    uVar6 = (**(code **)(*piVar7 + 8))();
  }
  return CONCAT22((short)((uint)uVar6 >> 0x10),*(undefined2 *)(in_ECX + 8)) -
         CONCAT22((short)((uint)unaff_EDI >> 0x10),uVar1);
}


// ==== FUN_0063d510 @ 0x0063d510 ====

void FUN_0063d510(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2cd8;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_0063d520 @ 0x0063d520 ====

void FUN_0063d520(byte param_1)

{
  void *in_ECX;
  
  FUN_0063d3b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063d540 @ 0x0063d540 ====

void FUN_0063d540(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_0063d550 @ 0x0063d550 ====

undefined4 FUN_0063d550(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00797a80(in_ECX + 8,param_1,0x48);
  return 1;
}


// ==== FUN_0063d570 @ 0x0063d570 ====

int FUN_0063d570(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0063d580 @ 0x0063d580 ====

void FUN_0063d580(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 8,0,0x48);
  return;
}


// ==== FUN_0063d5a0 @ 0x0063d5a0 ====

void FUN_0063d5a0(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x50) + 0x10))();
    (**(code **)(*piVar2 + 0x20))();
  }
  return;
}


// ==== FUN_0063d5d0 @ 0x0063d5d0 ====

void FUN_0063d5d0(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = param_1;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x50) + 0x10))();
    (**(code **)(*piVar2 + 0x20))();
  }
  return;
}


// ==== FUN_0063d600 @ 0x0063d600 ====

void FUN_0063d600(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x50) + 0x10))();
    (**(code **)(*piVar2 + 0x20))();
  }
  return;
}


// ==== FUN_0063d630 @ 0x0063d630 ====

void FUN_0063d630(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x20) = param_1;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x50) + 0x10))();
    (**(code **)(*piVar2 + 0x20))();
  }
  return;
}


// ==== FUN_0063d660 @ 0x0063d660 ====

void FUN_0063d660(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x24) = param_1;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x50) + 0x10))();
    (**(code **)(*piVar2 + 0x20))();
  }
  return;
}


// ==== FUN_0063d690 @ 0x0063d690 ====

void FUN_0063d690(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1c) = param_1;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x50) + 0x10))();
    (**(code **)(*piVar2 + 0x20))();
  }
  return;
}


// ==== FUN_0063d6c0 @ 0x0063d6c0 ====

void FUN_0063d6c0(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x34) = param_1;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x50) + 0x10))();
    (**(code **)(*piVar2 + 0x20))();
  }
  return;
}


// ==== FUN_0063d6f0 @ 0x0063d6f0 ====

void FUN_0063d6f0(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x38) = param_1;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x50) + 0x10))();
    (**(code **)(*piVar2 + 0x20))();
  }
  return;
}


// ==== FUN_0063d720 @ 0x0063d720 ====

void FUN_0063d720(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x30) = param_1;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x50) + 0x10))();
    (**(code **)(*piVar2 + 0x20))();
  }
  return;
}


// ==== FUN_0063d750 @ 0x0063d750 ====

void FUN_0063d750(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x3c) = param_1;
  return;
}


// ==== FUN_0063d760 @ 0x0063d760 ====

void FUN_0063d760(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x40) = param_1;
  return;
}


// ==== FUN_0063d770 @ 0x0063d770 ====

void FUN_0063d770(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x44) = param_1;
  *(undefined4 *)(in_ECX + 0x4c) = param_2;
  return;
}


// ==== FUN_0063d790 @ 0x0063d790 ====

void FUN_0063d790(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x48) = param_1;
  *(undefined4 *)(in_ECX + 0x4c) = param_2;
  return;
}


// ==== FUN_0063d7b0 @ 0x0063d7b0 ====

void FUN_0063d7b0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50) = param_1;
  return;
}


// ==== FUN_0063d7c0 @ 0x0063d7c0 ====

void FUN_0063d7c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098aef8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  in_ECX[0x14] = 0;
  *in_ECX = &PTR_FUN_009d2cfc;
  FUN_00797a50(in_ECX + 2,0,0x48);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063d810 @ 0x0063d810 ====

void FUN_0063d810(byte param_1)

{
  void *in_ECX;
  
  FUN_0063d540();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063d830 @ 0x0063d830 ====

void FUN_0063d830(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_0063d860 @ 0x0063d860 ====

int FUN_0063d860(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0063d870 @ 0x0063d870 ====

void FUN_0063d870(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 8,0,0x2c);
  return;
}


// ==== FUN_0063d890 @ 0x0063d890 ====

void FUN_0063d890(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00797a80(in_ECX + 8,param_1,0x2c);
  return;
}


// ==== FUN_0063d8b0 @ 0x0063d8b0 ====

void FUN_0063d8b0(int param_1,undefined2 param_2)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 8 + param_1 * 2) = param_2;
  return;
}


// ==== FUN_0063d8d0 @ 0x0063d8d0 ====

void FUN_0063d8d0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x32) = param_1;
  return;
}


// ==== FUN_0063d8e0 @ 0x0063d8e0 ====

void FUN_0063d8e0(int param_1,int *param_2)

{
  int iVar1;
  int in_ECX;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      if (param_2 == (int *)0x0) {
        *(undefined1 *)(in_ECX + 0x21) = 0;
        return;
      }
      iVar1 = (**(code **)(*param_2 + 0x14))();
      *(undefined1 *)(in_ECX + 0x21) = *(undefined1 *)(iVar1 + 0x1e);
      *(undefined2 *)(in_ECX + 0x2a) = *(undefined2 *)(iVar1 + 4);
      *(undefined2 *)(in_ECX + 0x2c) = *(undefined2 *)(iVar1 + 6);
      *(undefined2 *)(in_ECX + 0x2e) = *(undefined2 *)(iVar1 + 8);
      *(undefined2 *)(in_ECX + 0x30) = *(undefined2 *)(iVar1 + 10);
    }
    return;
  }
  if (param_2 == (int *)0x0) {
    *(undefined1 *)(in_ECX + 0x20) = 0;
    return;
  }
  iVar1 = (**(code **)(*param_2 + 0x14))();
  *(undefined1 *)(in_ECX + 0x20) = *(undefined1 *)(iVar1 + 0x1e);
  *(undefined2 *)(in_ECX + 0x22) = *(undefined2 *)(iVar1 + 4);
  *(undefined2 *)(in_ECX + 0x24) = *(undefined2 *)(iVar1 + 6);
  *(undefined2 *)(in_ECX + 0x26) = *(undefined2 *)(iVar1 + 8);
  *(undefined2 *)(in_ECX + 0x28) = *(undefined2 *)(iVar1 + 10);
  return;
}


// ==== FUN_0063d970 @ 0x0063d970 ====

void FUN_0063d970(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098af18;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d2d48;
  FUN_00797a50(in_ECX + 2,0,0x2c);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063d9c0 @ 0x0063d9c0 ====

void FUN_0063d9c0(byte param_1)

{
  void *in_ECX;
  
  FUN_0063d830();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063d9e0 @ 0x0063d9e0 ====

void FUN_0063d9e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_0063d9f0 @ 0x0063d9f0 ====

undefined1 FUN_0063d9f0(void)

{
  return 1;
}


// ==== FUN_0063da00 @ 0x0063da00 ====

int FUN_0063da00(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0063da10 @ 0x0063da10 ====

void FUN_0063da10(void)

{
  return;
}


// ==== FUN_0063da20 @ 0x0063da20 ====

void FUN_0063da20(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_0063da30 @ 0x0063da30 ====

void FUN_0063da30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2d5c;
  return;
}


// ==== FUN_0063da40 @ 0x0063da40 ====

void FUN_0063da40(byte param_1)

{
  void *in_ECX;
  
  FUN_0063d9e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063da60 @ 0x0063da60 ====

void FUN_0063da60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_0063da70 @ 0x0063da70 ====

int FUN_0063da70(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0063da80 @ 0x0063da80 ====

undefined4 FUN_0063da80(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_0063da90 @ 0x0063da90 ====

void FUN_0063da90(undefined1 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 8) = param_1;
  uVar1 = (**(code **)(*DAT_00b5abac + 0x10))(param_1);
  *(undefined4 *)(in_ECX + 0xc) = uVar1;
  return;
}


// ==== FUN_0063dab0 @ 0x0063dab0 ====

void FUN_0063dab0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098af38;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  in_ECX[3] = 0;
  *in_ECX = &PTR_FUN_009d2d78;
  FUN_00797a50(in_ECX + 2,0,1);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063db00 @ 0x0063db00 ====

void FUN_0063db00(byte param_1)

{
  void *in_ECX;
  
  FUN_0063da60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063db20 @ 0x0063db20 ====

void FUN_0063db20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2d94;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063db40 @ 0x0063db40 ====

undefined4 FUN_0063db40(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 8))(param_1,param_2);
  if ((iVar1 == 0) || (iVar1 == 1)) {
    return 1;
  }
  return 0;
}


// ==== FUN_0063db70 @ 0x0063db70 ====

undefined1 FUN_0063db70(void)

{
  return 1;
}


// ==== FUN_0063db80 @ 0x0063db80 ====

bool FUN_0063db80(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)(**(code **)(*param_1 + 0x20))();
  cVar1 = (**(code **)(*piVar2 + 8))();
  return cVar1 != '\x01';
}


// ==== FUN_0063dba0 @ 0x0063dba0 ====

void FUN_0063dba0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x20))();
  (**(code **)(*piVar1 + 0x1c))(param_1);
  return;
}


// ==== FUN_0063dbc0 @ 0x0063dbc0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0063dbc0(int *param_1)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *in_ECX;
  
  piVar3 = (int *)(**(code **)(*param_1 + 0x18))();
  iVar4 = (**(code **)(*in_ECX + 0x34))(param_1);
  iVar5 = (**(code **)(*piVar3 + 0x10))();
  iVar6 = (**(code **)(*piVar3 + 0x10))();
  iVar5 = *(int *)(iVar5 + 0xc) - *(int *)(iVar6 + 8);
  if (iVar4 != 0) {
    fVar1 = (float)iVar5;
    if (iVar5 < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    fVar2 = (float)iVar4;
    if (iVar4 < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar1 = fVar1 / fVar2;
    if (DAT_0099cdc8 <= fVar1) {
      if (DAT_0099d080 < fVar1) {
        return (float10)DAT_0099d080;
      }
      return (float10)fVar1;
    }
  }
  return (float10)DAT_0099cdc8;
}


// ==== FUN_0063dc60 @ 0x0063dc60 ====

void FUN_0063dc60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2ddc;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5acc8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5acc8 = in_ECX;
  return;
}


// ==== FUN_0063dc90 @ 0x0063dc90 ====

undefined4 FUN_0063dc90(int param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  byte *pbVar6;
  int *in_ECX;
  undefined4 unaff_ESI;
  
  iVar2 = (**(code **)(*in_ECX + 0xc))(param_1,param_2);
  if (iVar2 == 0) {
    piVar4 = *(int **)(param_1 + 0x40);
    piVar3 = (int *)(**(code **)(*piVar4 + 0x20))();
    piVar4 = (int *)(**(code **)(*piVar4 + 0x24))();
    piVar3 = (int *)(**(code **)(*piVar3 + 0x18))(param_2);
    piVar5 = (int *)(**(code **)(*piVar3 + 0x18))();
    piVar3 = (int *)(**(code **)(*piVar3 + 0x10))();
    pbVar6 = (byte *)(**(code **)(*piVar5 + 0xc))();
    bVar1 = *pbVar6;
    iVar2 = (**(code **)(*piVar3 + 4))();
    iVar2 = iVar2 + 4 + (uint)(byte)((bVar1 & 0xf) + 1) * 0x80;
    (**(code **)(*piVar4 + 0x10))
              (CONCAT22((short)((uint)iVar2 >> 0x10),(ushort)*(byte *)(iVar2 + 0x7c)));
    (**(code **)(*piVar5 + 0x2c))(unaff_ESI);
    return 1;
  }
  return 0;
}


// ==== FUN_0063dd30 @ 0x0063dd30 ====

undefined4 FUN_0063dd30(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *in_ECX;
  uint unaff_ESI;
  undefined1 uStack00000000;
  
  iVar1 = (**(code **)(*in_ECX + 8))(param_1,param_2);
  if (iVar1 != 0) {
    return 0;
  }
  piVar3 = *(int **)(param_1 + 0x40);
  piVar2 = (int *)(**(code **)(*piVar3 + 0x20))();
  piVar3 = (int *)(**(code **)(*piVar3 + 0x24))();
  piVar4 = (int *)(**(code **)(*DAT_00b5abd8 + 4))(&uStack00000000);
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*piVar4 + 0x18))();
  piVar5 = (int *)(**(code **)(*piVar4 + 0x10))();
  iVar1 = (**(code **)(*piVar5 + 4))();
  (**(code **)(*piVar3 + 0x10))(*(undefined1 *)(((unaff_ESI & 0xf) + 1) * 0x80 + iVar1));
  (**(code **)(*piVar2 + 0x10))(piVar4);
  return 1;
}


// ==== FUN_0063ddd0 @ 0x0063ddd0 ====

uint FUN_0063ddd0(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5aa30 + 8))(*(undefined2 *)(param_1 + 0xc));
  uVar2 = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
    uVar2 = *(uint *)(param_1 + 0xf);
    if (uVar2 < 4) {
      piVar1 = (int *)(**(code **)(*DAT_00b5acd0 + 4))(uVar2);
      uVar2 = 0;
      if (piVar1 != (int *)0x0) {
        uVar2 = (**(code **)(*piVar1 + 8))();
        return uVar2;
      }
    }
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_0063de20 @ 0x0063de20 ====

void FUN_0063de20(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5aa30 + 8))(*(undefined2 *)(param_1 + 0xc));
  (**(code **)(*piVar1 + 4))();
  piVar1 = (int *)(**(code **)(*DAT_00b5acd0 + 4))(*(undefined4 *)(param_1 + 0xf));
  (**(code **)(*piVar1 + 0xc))(param_1);
  return;
}


// ==== FUN_0063de60 @ 0x0063de60 ====

undefined4 FUN_0063de60(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5aa30 + 8))(*(undefined2 *)(param_1 + 0xc));
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*piVar1 + 4))();
  piVar1 = (int *)(**(code **)(*DAT_00b5acd0 + 4))(*(undefined4 *)(param_1 + 0xf));
  uVar2 = (**(code **)(*piVar1 + 0x10))();
  return uVar2;
}


// ==== FUN_0063dea0 @ 0x0063dea0 ====

void FUN_0063dea0(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5aa30 + 8))(*(undefined2 *)(param_1 + 0xc));
  (**(code **)(*piVar1 + 4))();
  piVar1 = (int *)(**(code **)(*DAT_00b5acd0 + 4))(*(undefined4 *)(param_1 + 0xf));
  (**(code **)(*piVar1 + 0x14))(param_1);
  return;
}


// ==== FUN_0063dee0 @ 0x0063dee0 ====

void FUN_0063dee0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5acc8 = 0;
  *in_ECX = &PTR_FUN_009d2d94;
  return;
}


// ==== FUN_0063df00 @ 0x0063df00 ====

int FUN_0063df00(int param_1,int *param_2)

{
  byte bVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  undefined2 *puVar8;
  int iVar9;
  ushort unaff_BP;
  int *piVar10;
  int *unaff_ESI;
  int *unaff_EDI;
  int unaff_retaddr;
  int *local_24;
  undefined2 auStack_20 [4];
  undefined4 uStack_18;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar10 = (int *)0x0;
  if (param_1 == 0) {
    return 0xc;
  }
  if (*(int **)(param_1 + 0x4c) == (int *)0x0) {
    local_24 = (int *)0x0;
  }
  else {
    local_24 = (int *)(**(code **)(**(int **)(param_1 + 0x4c) + 0x18))();
  }
  if (param_2 == (int *)0x0) {
    return 9;
  }
  piVar3 = (int *)(**(code **)(*param_2 + 0x18))();
  piVar4 = (int *)(**(code **)(*param_2 + 0x10))();
  iVar5 = FUN_00803725(param_1,0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  if (iVar5 == 0) {
    return 0xc;
  }
  if (*(int **)(iVar5 + 4) == (int *)0x0) {
    param_2 = (int *)0x0;
  }
  else {
    param_2 = (int *)(**(code **)(**(int **)(iVar5 + 4) + 0x18))();
  }
  if (*(int **)(iVar5 + 0x48) != (int *)0x0) {
    piVar10 = (int *)(**(code **)(**(int **)(iVar5 + 0x48) + 0x28))();
  }
  iVar6 = (**(code **)(*piVar4 + 4))();
  pbVar7 = (byte *)(**(code **)(*param_2 + 8))();
  bVar1 = *pbVar7;
  puVar8 = (undefined2 *)(**(code **)(*piVar10 + 8))();
  auStack_20[0] = *puVar8;
  if ((*(uint *)(iVar6 + 0x2bc8) & 0x80000000U >> (bVar1 & 0x1f)) != 0) {
    if (*(int *)(iVar5 + 0x24) == 0) {
      return 0xc;
    }
    uStack_18 = (**(code **)(**(int **)(iVar5 + 0x74) + 0x14))();
    cVar2 = (**(code **)(*piVar4 + 0x10))(uStack_18);
    if (cVar2 == '\0') {
      return 7;
    }
    cVar2 = (**(code **)(*piVar4 + 0x14))(unaff_retaddr);
    if (cVar2 != '\0') {
      piVar10 = (int *)(**(code **)(*piVar3 + 0x10))();
      if (*piVar10 != 0) {
        return 4;
      }
      piVar10 = (int *)(**(code **)(**(int **)(unaff_retaddr + 0x50) + 0x14))(0);
      (**(code **)(*piVar10 + 8))();
      uStack_8 = FUN_00802534();
      (**(code **)(*piVar10 + 8))();
      uStack_4 = FUN_00802534();
      pbVar7 = (byte *)(**(code **)(*piVar3 + 0xc))();
      iVar9 = (*pbVar7 & 0xf) * 0x80;
      iVar5 = iVar9 + 4 + iVar6;
      if (unaff_BP < *(byte *)(iVar9 + 0x54 + iVar6)) {
        return 10;
      }
      piVar10 = (int *)(**(code **)(*unaff_ESI + 0x10))();
      cVar2 = (**(code **)(*piVar10 + 0x44))();
      if (cVar2 == '\x01') {
        return 0xb;
      }
      if ((*(byte *)(iVar6 + 0x2bc4) & 0x30) == 0) {
        return 8;
      }
      if ((ushort)uStack_8 < *(ushort *)(iVar5 + 0x5c)) {
        return 1;
      }
      if ((ushort)uStack_4 < *(ushort *)(iVar5 + 0x5a)) {
        return 2;
      }
      if (*(char *)(iVar5 + 0x58) != '\0') {
        iVar6 = FUN_0063ea40(unaff_retaddr,*(undefined4 *)(iVar5 + 0x54),*(char *)(iVar5 + 0x58));
        if (iVar6 < (int)(uint)*(byte *)(iVar5 + 0x58)) {
          iVar9 = FUN_0063eab0(unaff_retaddr,*(undefined4 *)(iVar5 + 0x54),
                               (uint)*(byte *)(iVar5 + 0x58) - iVar6);
          iVar6 = iVar6 + iVar9;
        }
        if (iVar6 < (int)(uint)*(byte *)(iVar5 + 0x58)) {
          return 3;
        }
      }
      iVar5 = (**(code **)(*local_24 + 8))();
      FUN_00506d80(auStack_20,unaff_retaddr,*(undefined1 *)(iVar5 + 4));
      cVar2 = (**(code **)(*unaff_EDI + 0x20))(auStack_20);
      return (-(uint)(cVar2 != '\0') & 0xfffffffb) + 5;
    }
  }
  return 6;
}


// ==== FUN_0063e1c0 @ 0x0063e1c0 ====

byte FUN_0063e1c0(int param_1,undefined4 param_2)

{
  short sVar1;
  ushort uVar2;
  int *piVar3;
  ushort *puVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  uint uVar10;
  byte bVar11;
  int *unaff_EBX;
  uint uVar12;
  
  if (*(int **)(param_1 + 0x48) == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x48) + 0x28))();
  }
  puVar4 = (ushort *)(**(code **)(*piVar3 + 8))();
  uVar2 = *puVar4;
  if (*(int *)(param_1 + 0x40) == 0) {
    return 6;
  }
  piVar3 = *(int **)(param_1 + 0x40);
  piVar5 = (int *)(**(code **)(*piVar3 + 0x20))();
  (**(code **)(*piVar3 + 0x24))();
  iVar6 = (**(code **)(*piVar5 + 0x18))(param_2);
  if (iVar6 != 0) {
    return 1;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5aa30 + 8))(param_2);
  if (piVar3 == (int *)0x0) {
    return 6;
  }
  iVar6 = (**(code **)(*piVar3 + 4))();
  iVar7 = FUN_00803725(param_1,0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  if (iVar7 != 0) {
    piVar3 = (int *)0x0;
    if (*(int **)(iVar7 + 4) != (int *)0x0) {
      piVar3 = (int *)(**(code **)(**(int **)(iVar7 + 4) + 0x18))();
    }
    pbVar8 = (byte *)(**(code **)(*piVar3 + 8))();
    if ((*(uint *)(iVar6 + 0x2bc8) & 0x80000000U >> (*pbVar8 & 0x1f)) != 0) {
      uVar10 = CONCAT22((short)((uint)pbVar8 >> 0x10),(ushort)*(byte *)(iVar6 + 0xd4));
      if (uVar2 < *(byte *)(iVar6 + 0xd4)) {
        return 2;
      }
      bVar11 = 0;
      if (*(int *)(iVar6 + 0xd0) != 0) {
        uVar12 = 0;
        do {
          sVar1 = *(short *)(iVar6 + 0xc0 + uVar12 * 4);
          uVar10 = CONCAT22((short)(uVar10 >> 0x10),sVar1);
          if (sVar1 != 0) {
            piVar3 = (int *)(**(code **)(*piVar5 + 0x18))(uVar10);
            if (piVar3 == (int *)0x0) {
              return 3;
            }
            piVar3 = (int *)(**(code **)(*piVar3 + 0x18))();
            puVar9 = (undefined1 *)(**(code **)(*piVar3 + 0xc))();
            uVar10 = CONCAT31((int3)((uint)puVar9 >> 8),*puVar9) & 0xffffff0f;
            if ((byte)uVar10 < *(byte *)(iVar6 + 0xc2 + uVar12 * 4)) {
              return 3;
            }
          }
          bVar11 = bVar11 + 1;
          uVar12 = (uint)bVar11;
        } while (uVar12 < *(uint *)(iVar6 + 0xd0));
      }
      bVar11 = *(byte *)(iVar6 + 0x100);
      uVar2 = (**(code **)(*unaff_EBX + 8))();
      return -(uVar2 < bVar11) & 4;
    }
  }
  return 5;
}


// ==== FUN_0063e330 @ 0x0063e330 ====

byte FUN_0063e330(int param_1,undefined4 param_2)

{
  int iVar1;
  short sVar2;
  ushort uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  byte bVar11;
  int *unaff_ESI;
  uint uVar12;
  ushort unaff_retaddr;
  
  if (*(int **)(param_1 + 0x48) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(param_1 + 0x48) + 0x28))();
  }
  (**(code **)(*piVar4 + 8))();
  if (*(int *)(param_1 + 0x40) == 0) {
    return 5;
  }
  piVar4 = *(int **)(param_1 + 0x40);
  piVar5 = (int *)(**(code **)(*piVar4 + 0x20))();
  piVar4 = (int *)(**(code **)(*piVar4 + 0x24))();
  piVar6 = (int *)(**(code **)(*piVar5 + 0x18))(param_2);
  if (piVar6 == (int *)0x0) {
    return 5;
  }
  piVar7 = (int *)(**(code **)(*piVar6 + 0x18))();
  pbVar8 = (byte *)(**(code **)(*piVar7 + 0xc))();
  bVar11 = *pbVar8;
  piVar6 = (int *)(**(code **)(*piVar6 + 0x10))();
  iVar9 = (**(code **)(*piVar6 + 4))();
  if (*(int *)(iVar9 + 0x804) - 1U <= (uint)(bVar11 & 0xf)) {
    return 1;
  }
  iVar10 = (uint)(byte)((bVar11 & 0xf) + 1) * 0x80;
  iVar1 = iVar10 + 4 + iVar9;
  if (unaff_retaddr < *(byte *)(iVar10 + 0x54 + iVar9)) {
    return 2;
  }
  bVar11 = 0;
  if (*(int *)(iVar1 + 0x4c) != 0) {
    uVar12 = 0;
    do {
      sVar2 = *(short *)(iVar1 + 0x3c + uVar12 * 4);
      if (sVar2 != 0) {
        piVar4 = (int *)(**(code **)(*piVar5 + 0x18))(sVar2);
        if (piVar4 == (int *)0x0) {
          return 3;
        }
        piVar4 = (int *)(**(code **)(*piVar4 + 0x18))();
        pbVar8 = (byte *)(**(code **)(*piVar4 + 0xc))();
        if ((*pbVar8 & 0xf) < *(byte *)(iVar1 + 0x3e + uVar12 * 4)) {
          return 3;
        }
      }
      bVar11 = bVar11 + 1;
      uVar12 = (uint)bVar11;
    } while (uVar12 < *(uint *)(iVar1 + 0x4c));
    piVar4 = unaff_ESI;
  }
  bVar11 = *(byte *)(iVar1 + 0x7c);
  uVar3 = (**(code **)(*piVar4 + 8))();
  return -(uVar3 < bVar11) & 4;
}


// ==== FUN_0063e480 @ 0x0063e480 ====

bool FUN_0063e480(int *param_1,undefined4 param_2)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  float *pfVar4;
  float unaff_EBX;
  float unaff_retaddr;
  
  (**(code **)(*param_1 + 0x20))();
  piVar2 = (int *)(**(code **)(*param_1 + 0x18))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x14))();
  iVar3 = (**(code **)(*piVar2 + 0xc))();
  piVar2 = (int *)(**(code **)(*param_1 + 0x18))();
  (**(code **)(*piVar2 + 0xc))();
  piVar2 = (int *)(**(code **)(*param_1 + 0x10))();
  (**(code **)(*piVar2 + 4))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar3 + 0x50) + 0x14))(param_2);
  pfVar4 = (float *)(**(code **)(*piVar2 + 0x18))();
  if (*pfVar4 <= unaff_retaddr) {
    iVar3 = (**(code **)(*piVar2 + 0x18))();
    if (*(float *)(iVar3 + 4) <= unaff_EBX) {
      (**(code **)(*piVar2 + 0x18))();
      sVar1 = FUN_00802534();
      return sVar1 != 0;
    }
  }
  return false;
}


// ==== FUN_0063e550 @ 0x0063e550 ====

undefined4 FUN_0063e550(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  float fVar2;
  byte bVar3;
  ushort uVar4;
  int *piVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  float *pfVar9;
  ushort in_CX;
  int iVar10;
  float unaff_EBX;
  
  (**(code **)(*param_1 + 0x20))();
  piVar5 = (int *)(**(code **)(*param_1 + 0x18))();
  piVar5 = (int *)(**(code **)(*piVar5 + 0x14))();
  iVar6 = (**(code **)(*piVar5 + 0xc))();
  piVar5 = (int *)(**(code **)(*param_1 + 0x18))();
  pbVar7 = (byte *)(**(code **)(*piVar5 + 0xc))();
  bVar3 = *pbVar7;
  piVar5 = (int *)(**(code **)(*param_1 + 0x10))();
  iVar8 = (**(code **)(*piVar5 + 4))();
  iVar10 = (uint)(bVar3 & 0xf) * 0x80;
  uVar4 = *(ushort *)(iVar8 + 0x5e + iVar10);
  puVar1 = (undefined4 *)(iVar8 + 0x58 + iVar10);
  piVar5 = (int *)(**(code **)(**(int **)(iVar6 + 0x50) + 0x14))(param_2);
  pfVar9 = (float *)(**(code **)(*piVar5 + 0x18))();
  fVar2 = *pfVar9;
  iVar8 = (**(code **)(*piVar5 + 0x18))();
  if ((unaff_EBX <= fVar2) && ((float)uVar4 <= *(float *)(iVar8 + 4))) {
    uVar4 = FUN_00802534();
    FUN_00802534();
    if (uVar4 != 0) {
      if (*(int **)(iVar6 + 0x44) == (int *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)(**(code **)(**(int **)(iVar6 + 0x44) + 0x18))();
      }
      (**(code **)(*piVar5 + 0x14))((float)uVar4);
      (**(code **)(*piVar5 + 0x20))((float)in_CX);
      if (*(char *)(puVar1 + 1) != '\0') {
        iVar8 = FUN_0063e6c0(iVar6,*puVar1,*(char *)(puVar1 + 1));
        if (iVar8 < (int)(uint)*(byte *)(puVar1 + 1)) {
          FUN_0063e7e0(iVar6,*puVar1,(uint)*(byte *)(puVar1 + 1) - iVar8);
        }
      }
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0063e6c0 @ 0x0063e6c0 ====

int FUN_0063e6c0(uint param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined1 uStack_8;
  undefined1 uStack_7;
  undefined1 auStack_6 [2];
  int iStack_4;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar8 = 0;
  piVar2 = (int *)(**(code **)(*piVar1 + 0x30))();
  while( true ) {
    while( true ) {
      if (piVar2 == (int *)0x0) {
        return iVar8;
      }
      psVar3 = (short *)(**(code **)(*piVar2 + 0x14))();
      if (*psVar3 == (short)param_2) break;
      piVar2 = (int *)(**(code **)(*piVar1 + 0x34))();
    }
    iVar4 = (**(code **)(*piVar2 + 0x14))();
    if (*(char *)(iVar4 + 0x21) == '\x01') {
      iVar7 = param_3 - iVar8;
      iVar5 = (**(code **)(*piVar2 + 0x14))();
      iVar4 = *piVar2;
      if (iVar7 < (int)(uint)*(ushort *)(iVar5 + 0xc)) {
        iStack_4 = iVar4;
        iVar4 = (**(code **)(iVar4 + 0x14))();
        (**(code **)(iStack_4 + 0x20))(*(short *)(iVar4 + 0xc) - (short)iVar7);
        iVar8 = iVar8 + iVar7;
      }
      else {
        iVar4 = (**(code **)(iVar4 + 0x14))();
        iVar8 = iVar8 + (uint)*(ushort *)(iVar4 + 0xc);
        param_1 = param_1 & 0xff000000;
        (**(code **)(*piVar1 + 0x18))(piVar2,&param_1);
        uVar6 = (**(code **)(*piVar1 + 0x20))(&iStack_4);
        (**(code **)(*DAT_00b5a730 + 0x10))(1,uVar6);
      }
    }
    else {
      uStack_8 = 0;
      uStack_7 = 0;
      auStack_6[0] = 0;
      (**(code **)(*piVar1 + 0x18))(piVar2,&uStack_8);
      uVar6 = (**(code **)(*piVar1 + 0x20))(auStack_6 + -10);
      (**(code **)(*DAT_00b5a730 + 0x10))(1,uVar6);
      iVar8 = iVar8 + 1;
    }
    if (iVar8 == param_2) break;
    piVar2 = (int *)(**(code **)(*piVar1 + 0x34))();
  }
  return iVar8;
}


// ==== FUN_0063e7e0 @ 0x0063e7e0 ====

uint FUN_0063e7e0(int param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  short sVar8;
  uint unaff_EBX;
  uint unaff_EBP;
  uint uVar9;
  short unaff_retaddr;
  
  sVar8 = (short)unaff_EBX;
  piVar1 = *(int **)(param_1 + 0x24);
  uVar9 = 0;
  piVar2 = (int *)(**(code **)(*piVar1 + 0x2c))(0xf);
  if (piVar2 != (int *)0x0) {
    psVar3 = (short *)(**(code **)(*piVar2 + 0x14))();
    if (*psVar3 == (short)param_1) {
      iVar4 = (**(code **)(*piVar2 + 0x14))();
      if (*(char *)(iVar4 + 0x21) == '\x01') {
        iVar4 = (**(code **)(*piVar2 + 0x14))();
        if ((int)param_2 < (int)(uint)*(ushort *)(iVar4 + 0xc)) {
          iVar4 = *piVar2;
          iVar5 = (**(code **)(iVar4 + 0x14))();
          (**(code **)(iVar4 + 0x20))(*(short *)(iVar5 + 0xc) - (short)param_2);
          return param_2;
        }
        iVar4 = (**(code **)(*piVar2 + 0x14))();
        uVar9 = (uint)*(ushort *)(iVar4 + 0xc);
        uVar6 = (**(code **)(*piVar1 + 0x20))(0xf);
        (**(code **)(*DAT_00b5a730 + 0x10))(1,uVar6);
        if (uVar9 == param_2) {
          return uVar9;
        }
      }
      else {
        uVar6 = (**(code **)(*piVar1 + 0x20))(0xf);
        (**(code **)(*DAT_00b5a730 + 0x10))(1,uVar6);
        uVar9 = 1;
        if (param_2 == 1) {
          return 1;
        }
      }
    }
  }
  piVar2 = (int *)(**(code **)(*piVar1 + 0x2c))(0x10);
  if ((piVar2 != (int *)0x0) &&
     (psVar3 = (short *)(**(code **)(*piVar2 + 0x14))(), *psVar3 == unaff_retaddr)) {
    iVar4 = (**(code **)(*piVar2 + 0x14))();
    if (*(char *)(iVar4 + 0x21) == '\x01') {
      unaff_EBX = param_2 - uVar9;
      iVar4 = (**(code **)(*piVar2 + 0x14))();
      if ((int)unaff_EBX < (int)(uint)*(ushort *)(iVar4 + 0xc)) {
        iVar4 = *piVar2;
        iVar5 = (**(code **)(iVar4 + 0x14))();
        (**(code **)(iVar4 + 0x20))(*(short *)(iVar5 + 0xc) - (short)unaff_EBX);
        uVar7 = unaff_EBX;
      }
      else {
        iVar4 = (**(code **)(*piVar2 + 0x14))();
        uVar7 = (uint)*(ushort *)(iVar4 + 0xc);
        uVar6 = (**(code **)(*piVar1 + 0x20))(0x10);
        (**(code **)(*DAT_00b5a730 + 0x10))(1,uVar6);
      }
      uVar9 = uVar9 + uVar7;
    }
    else {
      uVar6 = (**(code **)(*piVar1 + 0x20))(0x10);
      (**(code **)(*DAT_00b5a730 + 0x10))(1,uVar6);
      uVar9 = uVar9 + 1;
    }
    sVar8 = (short)unaff_EBX;
    if (uVar9 == param_2) {
      return uVar9;
    }
  }
  piVar2 = (int *)(**(code **)(*piVar1 + 0x2c))(0x11);
  if ((piVar2 != (int *)0x0) &&
     (psVar3 = (short *)(**(code **)(*piVar2 + 0x14))(), *psVar3 == sVar8)) {
    iVar4 = (**(code **)(*piVar2 + 0x14))();
    if (*(char *)(iVar4 + 0x21) == '\x01') {
      iVar4 = (**(code **)(*piVar2 + 0x14))();
      if ((int)(param_2 - uVar9) < (int)(uint)*(ushort *)(iVar4 + 0xc)) {
        iVar4 = *piVar2;
        iVar5 = (**(code **)(iVar4 + 0x14))();
        (**(code **)(iVar4 + 0x20))(*(short *)(iVar5 + 0xc) - (short)(param_2 - uVar9));
      }
      else {
        iVar4 = (**(code **)(*piVar2 + 0x14))();
        unaff_EBP = (uint)*(ushort *)(iVar4 + 0xc);
        uVar6 = (**(code **)(*piVar1 + 0x20))(0x11);
        (**(code **)(*DAT_00b5a730 + 0x10))(1,uVar6);
      }
      if (uVar9 + unaff_EBP == param_2) {
        return uVar9 + unaff_EBP;
      }
    }
    else {
      uVar6 = (**(code **)(*piVar1 + 0x20))(0x11);
      (**(code **)(*DAT_00b5a730 + 0x10))(1,uVar6);
      if (uVar9 + 1 == param_2) {
        return uVar9 + 1;
      }
    }
  }
  return 0;
}


// ==== FUN_0063ea40 @ 0x0063ea40 ====

int FUN_0063ea40(int param_1,short param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar5 = 0;
  piVar2 = (int *)(**(code **)(*piVar1 + 0x30))();
  do {
    if (piVar2 == (int *)0x0) {
      return iVar5;
    }
    psVar3 = (short *)(**(code **)(*piVar2 + 0x14))();
    if (*psVar3 == param_2) {
      iVar4 = (**(code **)(*piVar2 + 0x14))();
      if (*(char *)(iVar4 + 0x21) == '\x01') {
        iVar4 = (**(code **)(*piVar2 + 0x14))();
        iVar5 = iVar5 + (uint)*(ushort *)(iVar4 + 0xc);
      }
      else {
        iVar5 = iVar5 + 1;
      }
      if (param_3 <= iVar5) {
        return iVar5;
      }
    }
    piVar2 = (int *)(**(code **)(*piVar1 + 0x34))();
  } while( true );
}


// ==== FUN_0063eab0 @ 0x0063eab0 ====

uint FUN_0063eab0(uint param_1,int param_2)

{
  int *piVar1;
  short *psVar2;
  int iVar3;
  int *piVar4;
  short sVar5;
  uint uVar6;
  uint unaff_retaddr;
  
  piVar4 = *(int **)(param_1 + 0x24);
  uVar6 = 0;
  piVar1 = (int *)(**(code **)(*piVar4 + 0x2c))(0xf);
  sVar5 = (short)param_1;
  if ((piVar1 != (int *)0x0) &&
     (psVar2 = (short *)(**(code **)(*piVar1 + 0x14))(), *psVar2 == sVar5)) {
    iVar3 = (**(code **)(*piVar1 + 0x14))();
    if (*(char *)(iVar3 + 0x21) == '\x01') {
      iVar3 = (**(code **)(*piVar1 + 0x14))();
      uVar6 = (uint)*(ushort *)(iVar3 + 0xc);
    }
    else {
      uVar6 = 1;
      if (param_2 == 1) {
        return 1;
      }
    }
  }
  piVar1 = (int *)(**(code **)(*piVar4 + 0x2c))(0x10);
  if ((piVar1 != (int *)0x0) &&
     (psVar2 = (short *)(**(code **)(*piVar1 + 0x14))(), *psVar2 == sVar5)) {
    iVar3 = (**(code **)(*piVar1 + 0x14))();
    if (*(char *)(iVar3 + 0x21) == '\x01') {
      iVar3 = (**(code **)(*piVar1 + 0x14))();
      uVar6 = uVar6 + *(ushort *)(iVar3 + 0xc);
    }
    else {
      uVar6 = uVar6 + 1;
      if (uVar6 == param_1) {
        return uVar6;
      }
    }
  }
  piVar4 = (int *)(**(code **)(*piVar4 + 0x2c))(0x11);
  if ((piVar4 != (int *)0x0) &&
     (psVar2 = (short *)(**(code **)(*piVar4 + 0x14))(), *psVar2 == sVar5)) {
    iVar3 = (**(code **)(*piVar4 + 0x14))();
    if (*(char *)(iVar3 + 0x21) == '\x01') {
      (**(code **)(*piVar4 + 0x14))();
    }
    else if (uVar6 + 1 == unaff_retaddr) {
      return uVar6 + 1;
    }
  }
  return 0;
}


// ==== FUN_0063eb90 @ 0x0063eb90 ====

void FUN_0063eb90(byte param_1)

{
  void *in_ECX;
  
  FUN_0063dee0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063ebb0 @ 0x0063ebb0 ====

void FUN_0063ebb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2e24;
  return;
}


// ==== FUN_0063ebc0 @ 0x0063ebc0 ====

void FUN_0063ebc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2e24;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063ebe0 @ 0x0063ebe0 ====

undefined4 FUN_0063ebe0(int param_1)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4 + param_1 * 4);
}


// ==== FUN_0063ec10 @ 0x0063ec10 ====

void FUN_0063ec10(void)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098af84;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d2e30;
  FUN_00797a50(in_ECX + 1,0,0x10);
  pvVar1 = operator_new(4);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_006570c0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  iVar3 = (**(code **)(*piVar2 + 4))();
  in_ECX[iVar3 + 1] = piVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 2;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00656e10();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  iVar3 = (**(code **)(*piVar2 + 4))();
  in_ECX[iVar3 + 1] = piVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 3;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00656ad0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  iVar3 = (**(code **)(*piVar2 + 4))();
  in_ECX[iVar3 + 1] = piVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 4;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00656940();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  iVar3 = (**(code **)(*piVar2 + 4))();
  in_ECX[iVar3 + 1] = piVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5acd0 = (undefined4 *)0x0;
    ExceptionList = pvStack_c;
    return;
  }
  DAT_00b5acd0 = in_ECX;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0063ed60 @ 0x0063ed60 ====

void FUN_0063ed60(void)

{
  int *in_ECX;
  int *piVar1;
  int iVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098af96;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = (int)&PTR_FUN_009d2e30;
  local_4 = 0;
  DAT_00b5acd0 = 0;
  iVar2 = 4;
  piVar1 = in_ECX;
  do {
    piVar1 = piVar1 + 1;
    if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar1)(1);
    }
    *piVar1 = 0;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *in_ECX = (int)&PTR_FUN_009d2e24;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0063ede0 @ 0x0063ede0 ====

void FUN_0063ede0(byte param_1)

{
  void *in_ECX;
  
  FUN_0063ed60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063ee00 @ 0x0063ee00 ====

void FUN_0063ee00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2e3c;
  return;
}


// ==== FUN_0063ee10 @ 0x0063ee10 ====

void FUN_0063ee10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2e3c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063ee30 @ 0x0063ee30 ====

undefined4 FUN_0063ee30(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x28))(param_1);
  return 1;
}


// ==== FUN_0063ee50 @ 0x0063ee50 ====

void FUN_0063ee50(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0063ee55. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x20))();
  return;
}


// ==== FUN_0063ee60 @ 0x0063ee60 ====

undefined4 FUN_0063ee60(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x30))(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x40))(iVar1);
  return 1;
}


// ==== FUN_0063ee90 @ 0x0063ee90 ====

void FUN_0063ee90(int *param_1)

{
  int *piVar1;
  ushort *puVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  int iVar5;
  int in_ECX;
  undefined4 uStack_1c;
  ushort uStack_18;
  byte bStack_16;
  undefined4 uStack_14;
  undefined1 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x18))();
  (**(code **)(*param_1 + 0x10))();
  uStack_1c = 0;
  puVar2 = (ushort *)(**(code **)(*piVar1 + 0xc))();
  uStack_18 = *puVar2 >> 4;
  pbVar3 = (byte *)(**(code **)(*piVar1 + 0xc))();
  bStack_16 = *pbVar3 & 0xf;
  puVar4 = (undefined4 *)(**(code **)(*piVar1 + 0x10))();
  uStack_14 = *puVar4;
  iVar5 = (**(code **)(*piVar1 + 0x10))();
  uStack_10 = *(undefined1 *)(iVar5 + 0x11);
  iVar5 = (**(code **)(*piVar1 + 0x10))();
  uStack_c = *(undefined4 *)(iVar5 + 4);
  iVar5 = (**(code **)(*piVar1 + 0x10))();
  uStack_8 = *(undefined4 *)(iVar5 + 8);
  iVar5 = (**(code **)(*piVar1 + 0x10))();
  uStack_4 = *(undefined4 *)(iVar5 + 0x18);
  for (puVar4 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 8))();
      puVar4 != (undefined4 *)0x0;
      puVar4 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x48))(puVar4)) {
    (**(code **)(*(int *)*puVar4 + 4))(&uStack_1c);
  }
  return;
}


// ==== FUN_0063ef60 @ 0x0063ef60 ====

undefined4 FUN_0063ef60(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 8))();
  *(undefined4 **)(in_ECX + 8) = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  return *puVar1;
}


// ==== FUN_0063ef80 @ 0x0063ef80 ====

undefined4 FUN_0063ef80(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x48))(*(undefined4 *)(in_ECX + 8));
  *(undefined4 **)(in_ECX + 8) = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  return *puVar1;
}


// ==== FUN_0063efa0 @ 0x0063efa0 ====

void FUN_0063efa0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098afa8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d2ecc;
  DAT_00b5accc = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009d2e3c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063f000 @ 0x0063f000 ====

void FUN_0063f000(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098afc5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d2ecc;
  pvVar1 = operator_new(0x1ec);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0063f420();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5accc = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5accc = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063f090 @ 0x0063f090 ====

void FUN_0063f090(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2e5c;
  return;
}


// ==== FUN_0063f0a0 @ 0x0063f0a0 ====

void FUN_0063f0a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2eb4;
  return;
}


// ==== FUN_0063f0b0 @ 0x0063f0b0 ====

void FUN_0063f0b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2e5c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063f0d0 @ 0x0063f0d0 ====

void FUN_0063f0d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2eb4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063f0f0 @ 0x0063f0f0 ====

void FUN_0063f0f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0063efa0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063f110 @ 0x0063f110 ====

void FUN_0063f110(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2eec;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x1c,0x10,FUN_006ef6d0);
  return;
}


// ==== FUN_0063f130 @ 0x0063f130 ====

void FUN_0063f130(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098afe3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d2ef4;
  local_4 = 1;
  if ((void *)in_ECX[0x74] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d2eec;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x1c,0x10,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d2eb4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x74]);
  return;
}


// ==== FUN_0063f1b0 @ 0x0063f1b0 ====

undefined4 FUN_0063f1b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1cc);
}


// ==== FUN_0063f1c0 @ 0x0063f1c0 ====

undefined4 FUN_0063f1c0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098affb;
  local_c = ExceptionList;
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x18) < param_1) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar2 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d2f08,0xa9);
      FUN_00797b80(uVar2);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x18);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      ExceptionList = local_c;
      return *(undefined4 *)(param_2 + 0x18);
    }
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(in_ECX + 0x1d4);
    *(int *)(in_ECX + 0x1cc) = *(int *)(in_ECX + 0x1cc) + -1;
    *(int *)(in_ECX + 0x1d4) = param_2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_0063f270 @ 0x0063f270 ====

undefined4 * FUN_0063f270(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[6] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d2f08,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[6] = param_2[6] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x1d4);
  *(int *)(in_ECX + 0x1cc) = *(int *)(in_ECX + 0x1cc) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x1c);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[5] = *(undefined4 *)(in_ECX + 0x1d0);
    *(undefined4 **)(in_ECX + 0x1d0) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x1d4) = puVar2[4];
  }
  puVar2[4] = 0;
  puVar2[6] = param_1;
  return puVar2;
}


// ==== FUN_0063f330 @ 0x0063f330 ====

void FUN_0063f330(byte param_1)

{
  void *in_ECX;
  
  FUN_0063f110();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063f350 @ 0x0063f350 ====

void FUN_0063f350(byte param_1)

{
  void *in_ECX;
  
  FUN_0063f130();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063f370 @ 0x0063f370 ====

void FUN_0063f370(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b018;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d2ef4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d2eec;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x1c,0x10,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x72] = 0;
  in_ECX[0x72] = in_ECX[0x72] + 0x10;
  in_ECX[0x75] = in_ECX + 2;
  in_ECX[0x73] = 0;
  in_ECX[0x74] = 0;
  iVar2 = 0xf;
  puVar1 = in_ECX;
  do {
    puVar1[6] = puVar1 + 9;
    puVar1[7] = 0;
    puVar1[8] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 7;
  } while (iVar2 != 0);
  in_ECX[0x6f] = 0;
  in_ECX[0x70] = 0;
  in_ECX[0x71] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063f420 @ 0x0063f420 ====

void FUN_0063f420(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b038;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d2f84;
  FUN_0063f370();
  in_ECX[3] = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063f470 @ 0x0063f470 ====

void FUN_0063f470(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 0xc);
  if (param_1 == *(int *)(in_ECX + 4)) {
    *(int *)(in_ECX + 4) = iVar1;
  }
  else {
    *(int *)(iVar2 + 8) = iVar1;
  }
  if (param_1 == *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = iVar2;
    return;
  }
  *(int *)(iVar1 + 0xc) = iVar2;
  return;
}


// ==== FUN_0063f4a0 @ 0x0063f4a0 ====

void FUN_0063f4a0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  if (*(undefined4 **)(in_ECX + 4) != (undefined4 *)0x0) {
    puVar2 = *(undefined4 **)(in_ECX + 4);
    do {
      puVar1 = (undefined4 *)puVar2[2];
      FUN_0063f4e0(*puVar2);
      (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,puVar2);
      puVar2 = puVar1;
    } while (puVar1 != (undefined4 *)0x0);
  }
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_0063f4e0 @ 0x0063f4e0 ====

void FUN_0063f4e0(undefined4 *param_1)

{
  int in_ECX;
  
  if (*(int **)(in_ECX + 0xc) == (int *)0x0) {
    if (param_1 != (undefined4 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0063f508. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)*param_1)();
      return;
    }
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))(1,param_1);
  }
  return;
}


// ==== FUN_0063f510 @ 0x0063f510 ====

undefined4 FUN_0063f510(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)(in_ECX + 0x14) + 0xc))(1,0);
  *puVar1 = unaff_ESI;
  puVar1[3] = 0;
  puVar1[2] = *(undefined4 *)(in_ECX + 4);
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 **)(in_ECX + 8) = puVar1;
    *(undefined4 **)(in_ECX + 4) = puVar1;
    return 0;
  }
  *(undefined4 **)(*(int *)(in_ECX + 4) + 0xc) = puVar1;
  *(undefined4 **)(in_ECX + 4) = puVar1;
  return 0;
}


// ==== FUN_0063f560 @ 0x0063f560 ====

uint * FUN_0063f560(uint param_1)

{
  uint *puVar1;
  int in_ECX;
  
  puVar1 = *(uint **)(in_ECX + 4);
  while( true ) {
    if (puVar1 == (uint *)0x0) {
      return (uint *)0x0;
    }
    if ((*puVar1 <= param_1) && (param_1 <= *puVar1)) break;
    puVar1 = (uint *)puVar1[2];
  }
  return puVar1;
}


// ==== FUN_0063f590 @ 0x0063f590 ====

void FUN_0063f590(int *param_1)

{
  undefined4 *puVar1;
  int *in_ECX;
  
  puVar1 = (undefined4 *)*param_1;
  if ((int *)in_ECX[3] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[3] + 0x10))(1,puVar1);
    (**(code **)(*in_ECX + 0x3c))(param_1);
    return;
  }
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
  }
  (**(code **)(*in_ECX + 0x3c))(param_1);
  return;
}


// ==== FUN_0063f5d0 @ 0x0063f5d0 ====

void FUN_0063f5d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0063f5f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063f5f0 @ 0x0063f5f0 ====

void FUN_0063f5f0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098b063;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d2f84;
  local_4 = 1;
  FUN_0063f4a0();
  local_4 = local_4 & 0xffffff00;
  FUN_0063f130();
  *in_ECX = &PTR_FUN_009d2e5c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063f650 @ 0x0063f650 ====

void FUN_0063f650(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2fdc;
  return;
}


// ==== FUN_0063f660 @ 0x0063f660 ====

void FUN_0063f660(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2fdc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063f680 @ 0x0063f680 ====

void FUN_0063f680(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2fec;
  return;
}


// ==== FUN_0063f690 @ 0x0063f690 ====

void FUN_0063f690(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d2fec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063f6c0 @ 0x0063f6c0 ====

void FUN_0063f6c0(void)

{
  FUN_00657370();
  return;
}


// ==== FUN_0063f6d0 @ 0x0063f6d0 ====

void FUN_0063f6d0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)FUN_00803725(param_1,0,&Framework::Article::ISkill::IMemento::RTTI_Type_Descriptor
                               ,&Framework::Article::Skill::Memento::Provider::RTTI_Type_Descriptor,
                               0);
  (**(code **)(*piVar1 + 8))();
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,piVar1);
  return;
}


// ==== FUN_0063f710 @ 0x0063f710 ====

void FUN_0063f710(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b0c3;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3024;
  pvVar1 = operator_new(0x54);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0063f850();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5abdc = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5abdc = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063f7a0 @ 0x0063f7a0 ====

void FUN_0063f7a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b0d5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3024;
  DAT_00b5abdc = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009d2fdc;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063f800 @ 0x0063f800 ====

int * FUN_0063f800(void)

{
  int *piVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  (**(code **)(*piVar1 + 4))(unaff_ESI);
  return piVar1;
}


// ==== FUN_0063f830 @ 0x0063f830 ====

void FUN_0063f830(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3004;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x3c,1,(_func_void_void_ptr *)&LAB_0063f6b0);
  return;
}


// ==== FUN_0063f850 @ 0x0063f850 ====

void FUN_0063f850(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b078;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d300c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d3004;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x3c,1,FUN_0063f6c0,(_func_void_void_ptr *)&LAB_0063f6b0);
  in_ECX[0x11] = 0;
  in_ECX[0x11] = in_ECX[0x11] + 1;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = in_ECX + 2;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0063f8d0 @ 0x0063f8d0 ====

undefined4 FUN_0063f8d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x48);
}


// ==== FUN_0063f8e0 @ 0x0063f8e0 ====

void FUN_0063f8e0(byte param_1)

{
  void *in_ECX;
  
  FUN_0063f830();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063f900 @ 0x0063f900 ====

void FUN_0063f900(byte param_1)

{
  void *in_ECX;
  
  FUN_0063f920();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063f920 @ 0x0063f920 ====

void FUN_0063f920(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b0a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d300c;
  _Memory = (void *)in_ECX[0x13];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d3004;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x3c,1,(_func_void_void_ptr *)&LAB_0063f6b0);
    *in_ECX = &PTR_FUN_009d2fec;
    ExceptionList = local_c;
    return;
  }
  FUN_00657230();
  _free(_Memory);
  return;
}


// ==== FUN_0063f9b0 @ 0x0063f9b0 ====

void * FUN_0063f9b0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098b0f9;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x50);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x48) = *(int *)(in_ECX + 0x48) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x3c);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_00657370();
      }
      *(undefined4 *)((int)param_2 + 0x34) = *(undefined4 *)(in_ECX + 0x4c);
      *(void **)(in_ECX + 0x4c) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)((int)param_2 + 0x30);
    }
    *(undefined4 *)((int)param_2 + 0x30) = 0;
    *(int *)((int)param_2 + 0x38) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0x38) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3030,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x38) = *(int *)((int)param_2 + 0x38) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0063fab0 @ 0x0063fab0 ====

undefined4 FUN_0063fab0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x38) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3030,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x38);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x38);
    }
    *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(in_ECX + 0x50);
    *(int *)(in_ECX + 0x48) = *(int *)(in_ECX + 0x48) + -1;
    *(int *)(in_ECX + 0x50) = param_2;
  }
  return 0;
}


// ==== FUN_0063fb30 @ 0x0063fb30 ====

void FUN_0063fb30(byte param_1)

{
  void *in_ECX;
  
  FUN_0063f7a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063fb50 @ 0x0063fb50 ====

void FUN_0063fb50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3158;
  return;
}


// ==== FUN_0063fb60 @ 0x0063fb60 ====

void FUN_0063fb60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3158;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063fb80 @ 0x0063fb80 ====

void FUN_0063fb80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3184;
  return;
}


// ==== FUN_0063fb90 @ 0x0063fb90 ====

void FUN_0063fb90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d31dc;
  return;
}


// ==== FUN_0063fba0 @ 0x0063fba0 ====

void FUN_0063fba0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d31f4;
  return;
}


// ==== FUN_0063fbb0 @ 0x0063fbb0 ====

void FUN_0063fbb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d320c;
  return;
}


// ==== FUN_0063fbc0 @ 0x0063fbc0 ====

void FUN_0063fbc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3264;
  return;
}


// ==== FUN_0063fbd0 @ 0x0063fbd0 ====

void FUN_0063fbd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3184;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063fbf0 @ 0x0063fbf0 ====

void FUN_0063fbf0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d31dc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063fc10 @ 0x0063fc10 ====

void FUN_0063fc10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d31f4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063fc30 @ 0x0063fc30 ====

void FUN_0063fc30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d320c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063fc50 @ 0x0063fc50 ====

void FUN_0063fc50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3264;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0063fc70 @ 0x0063fc70 ====

undefined4 FUN_0063fc70(ushort param_1)

{
  int *piVar1;
  int in_ECX;
  uint local_8 [2];
  
  local_8[0] = (uint)param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_0063fca0 @ 0x0063fca0 ====

undefined4 FUN_0063fca0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
  *(int **)(in_ECX + 0xc) = piVar1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_0063fcc0 @ 0x0063fcc0 ====

undefined4 FUN_0063fcc0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(*(undefined4 *)(in_ECX + 0xc));
  *(int **)(in_ECX + 0xc) = piVar1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_0063fce0 @ 0x0063fce0 ====

bool FUN_0063fce0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x10) + 8))();
  *(int *)(in_ECX + 0x14) = iVar1;
  return iVar1 != 0;
}


// ==== FUN_0063fd00 @ 0x0063fd00 ====

bool FUN_0063fd00(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x10) + 0x48))(*(undefined4 *)(in_ECX + 0x14));
  *(int *)(in_ECX + 0x14) = iVar1;
  return iVar1 != 0;
}


// ==== FUN_0063fd20 @ 0x0063fd20 ====

void FUN_0063fd20(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b118;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d3284;
  DAT_00b5aa30 = 0;
  local_4 = 0;
  (**(code **)(*(int *)in_ECX[4] + 0x20))();
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  in_ECX[4] = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009d3158;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0063fdd0 @ 0x0063fdd0 ====

void FUN_0063fdd0(int param_1)

{
  void *pvVar1;
  uint uVar2;
  uint *puVar3;
  int in_ECX;
  void *unaff_ESI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098b12d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x2bd0);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006575a0(param_1);
  }
  local_4 = 0xffffffff;
  puVar3 = (uint *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar3 = (uint)*(ushort *)(param_1 + 0x2bb8);
  puVar3[1] = uVar2;
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
  ExceptionList = unaff_ESI;
  return;
}


// ==== FUN_0063fe60 @ 0x0063fe60 ====

undefined4 FUN_0063fe60(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (*(int *)(in_ECX + 0x14) == 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009d313c,
                         s___Article_Skill_Flyweight_Contai_009d3114,0xe0);
    FUN_00797b80(uVar1);
    FUN_00797a40();
    return **(undefined4 **)(in_ECX + 0x14);
  }
  return **(undefined4 **)(in_ECX + 0x14);
}


// ==== FUN_0063fec0 @ 0x0063fec0 ====

void FUN_0063fec0(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  char local_208 [256];
  undefined4 local_108;
  char local_104 [4];
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009d3150,s_SkillFile_009d30a8);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0063ff0e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0063ff0e:
  local_108 = param_1;
  local_104[0] = '\n';
  local_104[1] = 0x2c;
  local_104[2] = 1;
  piVar2 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_208);
  (**(code **)(*piVar2 + 8))();
  iVar6 = 3;
  do {
    iVar5 = 0;
    do {
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))(iVar5 + 2,iVar6);
      FUN_0044a580(local_104,&DAT_009d3150,&DAT_009d3110);
      uVar1 = 0;
      pcVar4 = pcVar3;
      do {
        if (*pcVar4 != pcVar4[(int)(local_104 + -(int)pcVar3)]) {
          FUN_00640140(pcVar3);
          break;
        }
        if (*pcVar4 == '\0') break;
        uVar1 = uVar1 + 1;
        pcVar4 = pcVar4 + 1;
      } while (uVar1 < 0x100);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 100);
    iVar6 = iVar6 + 3;
    if (0x26 < iVar6) {
      (**(code **)(*DAT_00b5aa34 + 0xc))(piVar2);
      return;
    }
  } while( true );
}


