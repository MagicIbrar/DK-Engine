// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x670000-0x67ffff

// ==== FUN_006701b0 @ 0x006701b0 ====

void FUN_006701b0(void)

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
  FUN_00401740(s_UI_Game2_Guild_ui_memberInfownd__009d80c4,0x23);
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


// ==== FUN_00670230 @ 0x00670230 ====

void FUN_00670230(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d8144;
  FUN_006701b0();
  return;
}


// ==== FUN_00670250 @ 0x00670250 ====

undefined4 FUN_00670250(void)

{
  return 0x32;
}


// ==== FUN_00670260 @ 0x00670260 ====

void FUN_00670260(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d8144;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006702a0 @ 0x006702a0 ====

undefined4 FUN_006702a0(void)

{
  return 0x70320015;
}


// ==== FUN_006702b0 @ 0x006702b0 ====

undefined4 FUN_006702b0(void)

{
  return 0x70320050;
}


// ==== FUN_006702c0 @ 0x006702c0 ====

undefined4 FUN_006702c0(void)

{
  return 0x70320051;
}


// ==== FUN_006702d0 @ 0x006702d0 ====

undefined4 FUN_006702d0(void)

{
  return 0x70320010;
}


// ==== FUN_006702e0 @ 0x006702e0 ====

undefined4 FUN_006702e0(void)

{
  return 0x70320011;
}


// ==== FUN_006702f0 @ 0x006702f0 ====

undefined4 FUN_006702f0(void)

{
  return 0x70320012;
}


// ==== FUN_00670300 @ 0x00670300 ====

undefined4 FUN_00670300(void)

{
  return 0x70320013;
}


// ==== FUN_00670310 @ 0x00670310 ====

undefined4 FUN_00670310(void)

{
  return 0x70320053;
}


// ==== FUN_00670320 @ 0x00670320 ====

undefined4 FUN_00670320(void)

{
  return 0x70320054;
}


// ==== FUN_00670330 @ 0x00670330 ====

undefined4 FUN_00670330(void)

{
  return 0x70320018;
}


// ==== FUN_00670340 @ 0x00670340 ====

undefined4 FUN_00670340(void)

{
  return 0x70320019;
}


// ==== FUN_00670350 @ 0x00670350 ====

void FUN_00670350(void)

{
  return;
}


// ==== FUN_00670360 @ 0x00670360 ====

void FUN_00670360(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d8894;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00670380 @ 0x00670380 ====

undefined4 FUN_00670380(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 0x14))();
    if (cVar1 != '\0') {
      piVar2 = (int *)(**(code **)(*DAT_00b5acac + 0x30))();
      if (piVar2 != (int *)0x0) {
        piVar2 = (int *)(**(code **)(*piVar2 + 0x14))();
        if (piVar2 != (int *)0x0) {
          iVar3 = (**(code **)(*piVar2 + 0x10))();
          if ((iVar3 == 1) || (iVar3 == 3)) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}


// ==== FUN_006703f0 @ 0x006703f0 ====

void FUN_006703f0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(param_1);
  }
  return;
}


// ==== FUN_00670410 @ 0x00670410 ====

void FUN_00670410(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x28) == 0) {
    return;
  }
  switch(*(int *)(in_ECX + 0x28)) {
  case 1:
    puVar1 = operator_new(4);
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
    *puVar1 = &PTR_FUN_009d8808;
    break;
  case 2:
    puVar1 = operator_new(4);
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
    *puVar1 = &PTR_FUN_009d8830;
    break;
  case 3:
    puVar1 = operator_new(4);
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
    *puVar1 = &PTR_FUN_009d87b8;
    break;
  case 4:
    puVar1 = operator_new(4);
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
    *puVar1 = &PTR_FUN_009d8880;
    break;
  case 5:
    puVar1 = operator_new(4);
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
    *puVar1 = &PTR_FUN_009d87e0;
    break;
  case 6:
    puVar1 = operator_new(4);
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
    *puVar1 = &PTR_FUN_009d8858;
    break;
  default:
    goto switchD_0067042a_default;
  }
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00797a20(puVar1);
switchD_0067042a_default:
    *(undefined4 *)(in_ECX + 0x28) = 0;
  }
  return;
}


// ==== FUN_006704f0 @ 0x006704f0 ====

void FUN_006704f0(undefined4 param_1)

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


// ==== FUN_00670590 @ 0x00670590 ====

undefined4 FUN_00670590(void)

{
  int in_ECX;
  
  FUN_00670410();
  (**(code **)(*DAT_00b5aca8 + 0x40))();
  *(undefined1 *)(in_ECX + 0x30) = 0;
  return 1;
}


// ==== FUN_006705f0 @ 0x006705f0 ====

void FUN_006705f0(undefined4 param_1)

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


// ==== FUN_00670680 @ 0x00670680 ====

undefined4 FUN_00670680(int param_1,uint param_2,int param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined1 auStack_3e [10];
  undefined1 auStack_34 [8];
  undefined1 auStack_2c [8];
  undefined1 auStack_24 [36];
  
  iVar2 = (**(code **)(*in_ECX + 0x14))();
  if (param_1 != iVar2) {
    return 0;
  }
  if (param_3 == 1) {
    uVar3 = param_2 & 0xffff;
    if (uVar3 == 4) {
      (**(code **)(*DAT_00b5aca8 + 0xb4))();
    }
    else {
      if (uVar3 == 5) {
        (**(code **)(*DAT_00b5aca8 + 0x20))(auStack_24,in_ECX[3]);
        iVar2 = *DAT_00b5aca8;
        FUN_00765c50(auStack_2c);
        (**(code **)(iVar2 + 0xb8))();
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      if (uVar3 == 6) {
        uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x820050);
        FUN_00765c50(uVar4);
        cVar1 = FUN_00423420(param_2,auStack_3e + -10);
        if (cVar1 == '\0') {
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        (**(code **)(*DAT_00b5aca8 + 0x20))(auStack_2c,in_ECX[3]);
        iVar2 = *DAT_00b5aca8;
        FUN_00765c50(auStack_34);
        (**(code **)(iVar2 + 0xd0))();
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
  }
  return 1;
}


// ==== FUN_006707b0 @ 0x006707b0 ====

void FUN_006707b0(void)

{
  short sVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  void *local_280;
  undefined1 local_27c;
  undefined4 uStack_270;
  uint uStack_26c;
  undefined4 uStack_268;
  void *pvStack_25c;
  undefined1 uStack_258;
  void *pvStack_24c;
  uint uStack_248;
  undefined4 uStack_244;
  undefined4 uStack_23c;
  uint uStack_238;
  undefined4 uStack_234;
  void *pvStack_228;
  undefined1 uStack_224;
  void *pvStack_218;
  uint uStack_214;
  undefined4 uStack_210;
  uint uStack_204;
  undefined4 uStack_200;
  void *pvStack_1f0;
  undefined1 uStack_1ec;
  uint uStack_1dc;
  undefined4 uStack_1d8;
  undefined1 local_1d0 [464];
  
  if (*(int *)(in_ECX + 0x2c) == 2) {
    local_27c = 0;
    local_280 = (void *)((uint)local_280 & 0xffffff00);
    cVar2 = (**(code **)(*DAT_00b5aca8 + 0x10))();
    if (cVar2 != '\0') {
      local_27c = (*(uint *)(in_ECX + 0x14) & 0x10) != 0;
      local_280 = (void *)CONCAT31(local_280._1_3_,(*(uint *)(in_ECX + 0x14) & 0x20) != 0);
    }
    uStack_244 = 0xf;
    uStack_248 = 0;
    uStack_258 = 0;
    FUN_00401740(s_btn_power_009d8218,9);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_25c);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x44))(local_280);
    }
    if (0xf < uStack_248) {
      _free(pvStack_25c);
      return;
    }
    uStack_248 = 0xf;
    pvStack_24c = (void *)0x0;
    pvStack_25c = (void *)((uint)pvStack_25c & 0xffffff00);
    uStack_1d8 = 0xf;
    uStack_1dc = 0;
    uStack_1ec = 0;
    FUN_00401740(s_btn_notice_009d8224,10);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1f0);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x44))(unaff_EBX);
    }
    if (0xf < uStack_1dc) {
      _free(pvStack_1f0);
      return;
    }
  }
  else if (*(int *)(in_ECX + 0x2c) == 3) {
    local_27c = 0;
    iVar3 = (**(code **)(*DAT_00b5aca8 + 0x18))(local_1d0);
    sVar1 = *(short *)(iVar3 + 0x46);
    FUN_00537c20();
    if (sVar1 != 0) {
      local_280 = (void *)CONCAT31(local_280._1_3_,1);
    }
    uStack_210 = 0xf;
    uStack_214 = 0;
    uStack_224 = 0;
    FUN_00401740(s_btn_minilist_009d81e0,0xc);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_228);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x44))(0);
    }
    if (0xf < uStack_214) {
      _free(pvStack_228);
      return;
    }
    uStack_214 = 0xf;
    pvStack_218 = (void *)0x0;
    pvStack_228 = (void *)((uint)pvStack_228 & 0xffffff00);
    uStack_268 = 0xf;
    uStack_26c = 0;
    local_27c = 0;
    FUN_00401740(s_btn_state_009d81f0,9);
    FUN_00670380();
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_280);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x44))(unaff_EBP);
    }
    if (0xf < uStack_26c) {
      _free(local_280);
      return;
    }
    uStack_26c = 0xf;
    uStack_270 = 0;
    local_280 = (void *)((uint)local_280 & 0xffffff00);
    uStack_234 = 0xf;
    uStack_238 = 0;
    uStack_248 = uStack_248 & 0xffffff00;
    FUN_00401740(s_btn_advanture_009d81fc,0xd);
    (**(code **)(*DAT_00b5aca8 + 0x10))();
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_24c);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x44))(unaff_ESI);
    }
    if (0xf < uStack_238) {
      _free(pvStack_24c);
      return;
    }
    uStack_238 = 0xf;
    uStack_23c = 0;
    pvStack_24c = (void *)((uint)pvStack_24c & 0xffffff00);
    uStack_200 = 0xf;
    uStack_204 = 0;
    uStack_214 = uStack_214 & 0xffffff00;
    FUN_00401740(s_btn_secede_009d820c,10);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_218);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x44))(unaff_ESI);
    }
    if (0xf < uStack_204) {
      _free(pvStack_218);
      return;
    }
  }
  return;
}


// ==== FUN_00670ab0 @ 0x00670ab0 ====

/* WARNING: Removing unreachable block (ram,0x00670fce) */
/* WARNING: Removing unreachable block (ram,0x006710e7) */
/* WARNING: Removing unreachable block (ram,0x00670f2e) */
/* WARNING: Removing unreachable block (ram,0x00670e9a) */
/* WARNING: Removing unreachable block (ram,0x00670e06) */
/* WARNING: Removing unreachable block (ram,0x00670d6e) */
/* WARNING: Removing unreachable block (ram,0x00670cda) */
/* WARNING: Removing unreachable block (ram,0x00670c44) */
/* WARNING: Removing unreachable block (ram,0x00670d16) */
/* WARNING: Removing unreachable block (ram,0x00670daa) */
/* WARNING: Removing unreachable block (ram,0x00670e42) */
/* WARNING: Removing unreachable block (ram,0x00670ed6) */
/* WARNING: Removing unreachable block (ram,0x00670f6a) */
/* WARNING: Removing unreachable block (ram,0x0067109b) */
/* WARNING: Removing unreachable block (ram,0x0067100a) */
/* WARNING: Removing unreachable block (ram,0x0067105c) */
/* WARNING: Removing unreachable block (ram,0x00670c82) */

int FUN_00670ab0(void)

{
  int iVar1;
  int extraout_EAX;
  int extraout_EAX_00;
  int *piVar2;
  int extraout_EAX_01;
  int in_ECX;
  uint uVar3;
  byte *pbVar4;
  byte ****ppppbVar5;
  bool bVar6;
  bool bVar7;
  undefined4 uStack_240;
  undefined4 uStack_224;
  uint uStack_220;
  uint uStack_21c;
  int iStack_218;
  undefined4 uStack_214;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  undefined4 uStack_208;
  byte ****ppppbStack_200;
  undefined1 local_1fc [12];
  uint uStack_1f0;
  uint uStack_1ec;
  undefined1 auStack_1e0 [4];
  void *pvStack_1dc;
  uint uStack_1c8;
  void *pvStack_1b8;
  undefined4 uStack_1a8;
  uint uStack_1a4;
  undefined1 auStack_1a0 [412];
  
  uStack_240 = auStack_1a0 + 0x19c;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined2 *)(in_ECX + 0x1c) = 0;
  *(undefined1 *)(in_ECX + 0x1c) = 1;
  (**(code **)(*DAT_00b5aca8 + 0x20))(local_1fc,*(undefined4 *)(in_ECX + 0xc));
  iVar1 = (**(code **)(*DAT_00b5aca8 + 0x24))();
  uStack_21c = *(uint *)(iVar1 + 0x14);
  if (*(uint *)(iVar1 + 0x18) < 0x10) {
    pbVar4 = (byte *)(iVar1 + 4);
  }
  else {
    pbVar4 = *(byte **)(iVar1 + 4);
  }
  if (uStack_1f0 == 0) {
LAB_00670b45:
    if ((uStack_21c <= uStack_1f0) && (uStack_1f0 == uStack_21c)) goto LAB_00670bd5;
  }
  else {
    uVar3 = uStack_1f0;
    if (uStack_21c <= uStack_1f0) {
      uVar3 = uStack_21c;
    }
    ppppbVar5 = ppppbStack_200;
    if (uStack_1ec < 0x10) {
      ppppbVar5 = (byte ****)&ppppbStack_200;
    }
    bVar6 = false;
    iVar1 = 0;
    bVar7 = true;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      bVar6 = *(byte *)ppppbVar5 < *pbVar4;
      bVar7 = *(byte *)ppppbVar5 == *pbVar4;
      ppppbVar5 = (byte ****)((int)ppppbVar5 + 1);
      pbVar4 = pbVar4 + 1;
    } while (bVar7);
    if (!bVar7) {
      iVar1 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
    }
    if (iVar1 == 0) goto LAB_00670b45;
  }
  *(bool *)(in_ECX + 0x1a) = (*(uint *)(in_ECX + 0x14) & 2) != 0;
  *(bool *)(in_ECX + 0x18) = (*(uint *)(in_ECX + 0x14) & 8) != 0;
  *(undefined1 *)(in_ECX + 0x1b) = 1;
  iVar1 = (**(code **)(*DAT_00b5aca8 + 0x18))(auStack_1e0);
  *(bool *)(in_ECX + 0x1d) = *(short *)(iVar1 + 0x46) == 0;
  if (0xf < uStack_1a4) {
    _free(pvStack_1b8);
    return extraout_EAX;
  }
  uStack_1a4 = 0xf;
  uStack_1a8 = 0;
  pvStack_1b8 = (void *)((uint)pvStack_1b8 & 0xffffff00);
  if (0xf < uStack_1c8) {
    _free(pvStack_1dc);
    return extraout_EAX_00;
  }
LAB_00670bd5:
  iVar1 = 0xc;
  uStack_214 = 0x4b;
  uStack_210 = 0x10;
  uStack_20c = 0x5d;
  uStack_208 = 2;
  if (*(char *)(in_ECX + 0x18) == '\x01') {
    FUN_00401740(s_btn_chgGrade_009d8230,0xc);
    uStack_21c = 0xd;
    iStack_218 = 0xc;
    FUN_006705f0(&uStack_240,&uStack_21c,&uStack_214);
    iVar1 = 0x1c;
  }
  else {
    FUN_00401740(s_btn_chgGrade_009d8240,0xc);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_240);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
  }
  if (*(char *)(in_ECX + 0x1a) == '\x01') {
    FUN_00401740(s_btn_kick_009d8250,8);
    uStack_21c = 0xd;
    iStack_218 = iVar1;
    FUN_006705f0(&uStack_240,&uStack_21c,&uStack_214);
    iVar1 = iVar1 + 0x10;
  }
  else {
    FUN_00401740(s_btn_kick_009d825c,8);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_240);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
  }
  if (iVar1 == 0) {
    FUN_00401740(s_pan_seperator_0_009d8278,0xf);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_240);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
    uVar3 = 0;
  }
  else {
    FUN_00401740(s_pan_seperator_0_009d8268,0xf);
    uStack_21c = 4;
    iStack_218 = iVar1 + 4;
    FUN_006705f0(&uStack_240,&uStack_21c,&uStack_20c);
    uVar3 = iVar1 + 10;
  }
  uStack_21c = uVar3;
  if (*(char *)(in_ECX + 0x1b) == '\x01') {
    FUN_00401740(s_btn_whisper_009d8288,0xb);
    uStack_224 = 0xd;
    uStack_220 = uVar3;
    FUN_006705f0(&uStack_240,&uStack_224,&uStack_214);
    uVar3 = uVar3 + 0x10;
  }
  else {
    FUN_00401740(s_btn_whisper_009d8294,0xb);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_240);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
  }
  if (*(char *)(in_ECX + 0x19) == '\x01') {
    FUN_00401740(s_btn_curPos_009d82a0,10);
    uStack_224 = 0xd;
    uStack_220 = uVar3;
    FUN_006705f0(&uStack_240,&uStack_224,&uStack_214);
    uVar3 = uVar3 + 0x10;
  }
  else {
    FUN_00401740(s_btn_curPos_009d82ac,10);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_240);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
  }
  if (*(char *)(in_ECX + 0x1c) == '\x01') {
    FUN_00401740(s_btn_desc_009d82b8,8);
    uStack_224 = 0xd;
    uStack_220 = uVar3;
    FUN_006705f0(&uStack_240,&uStack_224,&uStack_214);
    uVar3 = uVar3 + 0x10;
  }
  else {
    FUN_00401740(s_btn_desc_009d82c4,8);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_240);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
  }
  if (*(char *)(in_ECX + 0x1d) == '\x01') {
    if (uStack_21c < uVar3) {
      FUN_00401740(s_pan_seperator_1_009d82d0,0xf);
      uStack_224 = 4;
      uStack_220 = uVar3 + 4;
      FUN_006705f0(&uStack_240,&uStack_224,&uStack_20c);
      uVar3 = uVar3 + 10;
    }
    else {
      FUN_00401740(s_pan_seperator_1_009d82e0,0xf);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_240);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x24))(0);
      }
    }
    FUN_00401740(s_btn_delegate_009d82f0,0xc);
    uStack_224 = 0xd;
    uStack_220 = uVar3;
    FUN_006705f0(&uStack_240,&uStack_224,&uStack_214);
    uVar3 = uVar3 + 0x10;
  }
  else {
    FUN_00401740(s_pan_seperator_1_009d8300,0xf);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_240);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
    uStack_240 = (undefined1 *)((uint)uStack_240 & 0xffffff00);
    FUN_00401740(s_btn_delegate_009d8310,0xc);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_1fc + -0x48);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
  }
  if (uStack_1ec < 0x10) {
    return uVar3 + 0xc;
  }
  _free(ppppbStack_200);
  return extraout_EAX_01;
}


// ==== FUN_00671120 @ 0x00671120 ====

void FUN_00671120(void *param_1)

{
  int *piVar1;
  int iVar2;
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
  FUN_00401740(s_textbox_009d8324,7);
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
  if (in_stack_00000018 < 0x10) {
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_006711c0 @ 0x006711c0 ====

int FUN_006711c0(int param_1,char param_2)

{
  undefined4 uVar1;
  int unaff_EBX;
  
  if (param_2 == '\0') {
    uVar1 = 0x820027;
  }
  else {
    if (param_2 != '\x01') {
      *(undefined4 *)(param_1 + 0x18) = 0xf;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      FUN_00401740(&DAT_009d838a,0);
      return param_1;
    }
    uVar1 = 0x820026;
  }
  uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,uVar1);
  *(undefined4 *)(unaff_EBX + 0x18) = 0xf;
  *(undefined4 *)(unaff_EBX + 0x14) = 0;
  *(undefined1 *)(unaff_EBX + 4) = 0;
  FUN_00401660(uVar1,0,0xffffffff);
  return unaff_EBX;
}


// ==== FUN_00671240 @ 0x00671240 ====

int FUN_00671240(int param_1,undefined1 param_2)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  switch(param_2) {
  case 0:
    uVar1 = 0x82008c;
    break;
  case 1:
    uVar1 = 0x82008d;
    break;
  case 2:
    uVar1 = 0x82008e;
    break;
  case 3:
    uVar1 = 0x82008f;
    break;
  case 4:
    uVar1 = 0x820090;
    break;
  case 5:
    uVar1 = 0x820091;
    break;
  default:
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(&DAT_009d838b,0);
    return param_1;
  }
  uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,uVar1);
  *(undefined4 *)(unaff_ESI + 0x18) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined1 *)(unaff_ESI + 4) = 0;
  FUN_00401660(uVar1,0,0xffffffff);
  return unaff_ESI;
}


// ==== FUN_00671300 @ 0x00671300 ====

/* WARNING: Removing unreachable block (ram,0x006713d5) */

int FUN_00671300(int param_1)

{
  char cVar1;
  int iVar2;
  int extraout_EAX;
  int extraout_EAX_00;
  char *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int unaff_retaddr;
  undefined1 auStack_212 [22];
  undefined4 uStack_1fc;
  char acStack_1f6 [38];
  void *local_1d0 [5];
  uint uStack_1bc;
  void *pvStack_1ac;
  undefined4 uStack_19c;
  uint uStack_198;
  
  iVar2 = (**(code **)(*DAT_00b5aca8 + 0x18))(local_1d0);
  puVar5 = (undefined4 *)(iVar2 + 0x48 + param_1 * 0x27);
  puVar6 = &uStack_1fc;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)puVar6 = *(undefined2 *)puVar5;
  *(undefined1 *)((int)puVar6 + 2) = *(undefined1 *)((int)puVar5 + 2);
  if (0xf < uStack_198) {
    _free(pvStack_1ac);
    return extraout_EAX;
  }
  uStack_198 = 0xf;
  uStack_19c = 0;
  pvStack_1ac = (void *)((uint)pvStack_1ac & 0xffffff00);
  if (0xf < uStack_1bc) {
    _free(local_1d0[0]);
    return extraout_EAX_00;
  }
  pcVar3 = acStack_1f6;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(acStack_1f6,(int)pcVar3 - (int)(acStack_1f6 + 1));
  *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
  *(undefined4 *)(unaff_retaddr + 0x14) = 0;
  *(undefined1 *)(unaff_retaddr + 4) = 0;
  FUN_00401660(auStack_212 + -6,0,0xffffffff);
  return unaff_retaddr;
}


// ==== FUN_006713f0 @ 0x006713f0 ====

void FUN_006713f0(undefined4 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  undefined4 unaff_retaddr;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined1 uVar8;
  undefined4 local_1c;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  FUN_00401740(s_lbl_recName__d_009d840c,0xe);
  puVar6 = &local_1c;
  uVar1 = FUN_00404230(puVar6);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar1);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x30))();
    if (iVar3 != 0) {
      FUN_00559170(param_1);
    }
  }
  if (0xf < uStack_8) {
    _free(local_1c);
    return;
  }
  uVar8 = 0;
  FUN_00401740(s_lbl_recClass__d_009d841c,0xf);
  uVar5 = (int)register0x00000010 - 0x20;
  uVar1 = FUN_00404230(uVar5,puVar6,uVar8);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar1);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x30))();
    if (iVar3 != 0) {
      FUN_00559170(unaff_retaddr);
    }
  }
  if (0xf < uStack_c) {
    _free(unaff_EBX);
    return;
  }
  uVar7 = (uint)puVar6 & 0xffffff00;
  FUN_00401740(s_lbl_recGrade__d_009d842c,0xf);
  iVar3 = (int)register0x00000010 + -0x24;
  uVar1 = FUN_00404230(iVar3,uVar5,uVar7);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar1);
  if (piVar2 != (int *)0x0) {
    iVar4 = (**(code **)(*piVar2 + 0x30))();
    if (iVar4 != 0) {
      FUN_00559170(uStack_4);
    }
  }
  if (0xf < uStack_10) {
    _free(unaff_EBP);
    return;
  }
  uVar5 = uVar5 & 0xffffff00;
  FUN_00401740(s_lbl_recConn__d_009d843c,0xe);
  uVar1 = FUN_00404230((int)register0x00000010 + -0x28,iVar3,uVar5);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar1);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x30))();
    if (iVar3 != 0) {
      FUN_00559170(uStack_8);
    }
  }
  if (uStack_14 < 0x10) {
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_00671590 @ 0x00671590 ====

void FUN_00671590(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  uint uStack_74;
  void *pvStack_54;
  uint uStack_40;
  undefined1 auStack_3c [4];
  uint uStack_38;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
  if (piVar1 == (int *)0x0) {
    return;
  }
  uVar2 = (**(code **)(*piVar1 + 0x10))();
  FUN_005041e0(uVar2);
  if (*(int *)(in_ECX + 0x28) == 0) goto switchD_006715c6_caseD_5;
  switch(*(int *)(in_ECX + 0x28)) {
  case 1:
    uVar2 = 0x2f;
    break;
  case 2:
    uVar2 = 0x31;
    break;
  case 3:
    iVar3 = (**(code **)(*DAT_00b5a74c + 0xc))(0x32);
    goto LAB_00671600;
  case 4:
    iVar3 = (**(code **)(*DAT_00b5a74c + 0xc))(0x36);
    goto LAB_00671600;
  default:
    goto switchD_006715c6_caseD_5;
  case 6:
    uVar2 = 0x61;
  }
  iVar3 = (**(code **)(*DAT_00b5a74c + 0xc))(uVar2);
LAB_00671600:
  if (iVar3 == 0) {
switchD_006715c6_caseD_5:
    if (0xf < uStack_40) {
      _free(pvStack_54);
      return;
    }
  }
  else {
    if ((*(int **)(iVar3 + 4) != (int *)0x0) &&
       (piVar1 = (int *)(**(code **)(**(int **)(iVar3 + 4) + 0x2c))(), piVar1 != (int *)0x0)) {
      uVar2 = (**(code **)(*piVar1 + 0x10))();
      FUN_005041e0(uVar2);
      if (uStack_38 <= uStack_74) {
        uStack_38 = uStack_74 + 1000;
        (**(code **)(*piVar1 + 0xc))(auStack_3c);
      }
      FUN_00713830();
    }
    FUN_00713830();
  }
  return;
}


// ==== FUN_00671690 @ 0x00671690 ====

undefined4 FUN_00671690(void)

{
  int *piVar1;
  undefined4 extraout_EAX;
  int *piVar2;
  undefined4 extraout_EAX_00;
  int iVar3;
  int iVar4;
  undefined4 extraout_EAX_01;
  int in_ECX;
  undefined1 auStack_3a [2];
  void *local_38;
  undefined1 local_34;
  undefined4 uStack_28;
  void *local_24;
  void *local_20;
  undefined1 uStack_1c;
  undefined4 uStack_14;
  uint uStack_10;
  uint uStack_c;
  int iStack_8;
  int iStack_4;
  
  local_20 = (void *)0xf;
  local_24 = (void *)0x0;
  local_34 = 0;
  FUN_00401740(s_pan_memList_009d844c,0xb);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if ((void *)0xf < local_24) {
    _free(local_38);
    return extraout_EAX;
  }
  local_24 = (void *)0xf;
  uStack_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = 0;
  FUN_00401740(s_pan_memColumn_009d8458,0xd);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_20);
  if (0xf < uStack_c) {
    _free(local_20);
    return extraout_EAX_00;
  }
  uStack_c = 0xf;
  iVar4 = *(int *)(iStack_4 + 0xc);
  uStack_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  iVar3 = (**(code **)(*piVar1 + 4))();
  if (iVar4 != iVar3) {
    iVar4 = (**(code **)(*piVar1 + 0x48))(auStack_3a + -10);
    if (iVar4 == 0) {
      return 0;
    }
    if (piVar2 != (int *)0x0) {
      iVar4 = *(int *)(iStack_4 + 0xc);
      iVar3 = (**(code **)(*piVar2 + 4))();
      if (iVar4 == iVar3) {
        return 0;
      }
      iVar4 = (**(code **)(*piVar2 + 0x48))(auStack_3a + -10);
      if (iVar4 != 0) {
        return 0;
      }
    }
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(s_memList_scroll_009d8468,0xe);
  piVar1 = (int *)(**(code **)(*piVar1 + 0x4c))(&local_24);
  if (0xf < uStack_10) {
    _free(local_24);
    return extraout_EAX_01;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (((piVar1 == (int *)0x0) || (iVar4 = (**(code **)(*piVar1 + 0x30))(), iVar4 == 0)) ||
     (iVar4 = FUN_00803725(iVar4,0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                           &Framework::UI::Control::VScroll::RTTI_Type_Descriptor,0), iVar4 == 0)) {
    return 0;
  }
  if (0 < *(short *)(iStack_8 + 4)) {
    FUN_0055aa00();
    return 1;
  }
  if (*(short *)(iStack_8 + 4) < 0) {
    FUN_0055aa60();
  }
  return 1;
}


// ==== FUN_00671850 @ 0x00671850 ====

void FUN_00671850(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  void *local_54;
  undefined1 local_50;
  uint local_40;
  undefined4 local_3c;
  void *local_38;
  undefined1 local_34;
  uint local_24;
  undefined4 local_20;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  iVar1 = *(int *)(in_ECX + 0x2c);
  if (iVar1 == 1) {
    FUN_006713f0(*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8),0xffffffff);
    local_4 = 0xf;
    local_8 = 0;
    local_18 = 0;
    FUN_00401740(s_pan_memberPop_009d8478,0xd);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
    if (0xf < local_8) {
      _free(local_1c);
      return;
    }
  }
  else if (iVar1 == 2) {
    local_20 = 0xf;
    local_24 = 0;
    local_34 = 0;
    FUN_00401740(s_pan_managePop_009d8488,0xd);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
    if (0xf < local_24) {
      _free(local_38);
      return;
    }
  }
  else {
    if (iVar1 != 3) {
      *(undefined4 *)(in_ECX + 0x2c) = 0;
      return;
    }
    local_3c = 0xf;
    local_40 = 0;
    local_50 = 0;
    FUN_00401740(s_pan_funcPop_009d8498,0xb);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_54);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x24))(0);
    }
    if (0xf < local_40) {
      _free(local_54);
      return;
    }
  }
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  return;
}


// ==== FUN_006719a0 @ 0x006719a0 ====

void FUN_006719a0(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x2c) != 1) {
    FUN_00671850();
  }
  uVar1 = FUN_00670ab0();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_pan_memberPop_009d84a4,0xd);
  local_24 = 0x65;
  local_20 = uVar1;
  FUN_006705f0(local_1c,param_1,&local_24);
  if (local_4 < 0x10) {
    *(undefined4 *)(in_ECX + 0x2c) = 1;
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00671a30 @ 0x00671a30 ====

void FUN_00671a30(int param_1)

{
  int *piVar1;
  int in_ECX;
  undefined1 local_38 [4];
  void *pvStack_34;
  uint uStack_20;
  undefined1 local_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  if (*(int *)(in_ECX + 0x2c) != param_1) {
    FUN_00671850();
    if (param_1 == 2) {
      FUN_00401830(s_pan_managePop_009d84c0);
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_1c);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x24))(1);
      }
      if (0xf < uStack_4) {
        pvStack_34 = pvStack_18;
LAB_00671abd:
        _free(pvStack_34);
        return;
      }
    }
    else if (param_1 == 3) {
      FUN_00401830(s_pan_funcPop_009d84b4);
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_38);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x24))(1);
      }
      if (0xf < uStack_20) goto LAB_00671abd;
    }
    *(int *)(in_ECX + 0x2c) = param_1;
  }
  FUN_006707b0();
  return;
}


// ==== FUN_00671ae0 @ 0x00671ae0 ====

/* WARNING: Removing unreachable block (ram,0x00671d71) */
/* WARNING: Removing unreachable block (ram,0x00671d29) */
/* WARNING: Removing unreachable block (ram,0x00671dba) */
/* WARNING: Removing unreachable block (ram,0x00671ce2) */

void FUN_00671ae0(void)

{
  int *piVar1;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  void *unaff_EDI;
  void *_Memory;
  undefined4 *_Memory_00;
  uint uVar2;
  undefined4 uStack_30;
  void *local_1c;
  uint local_18;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  uStack_30 = (void **)0xc;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = local_18 & 0xffffff00;
  FUN_00401740();
  uStack_30 = &local_1c;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))();
  }
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740();
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))();
  }
  if (0xf < uStack_c) {
    _free(unaff_EBX);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  FUN_00401740();
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))();
  }
  if (0xf < uStack_10) {
    _free(unaff_EBP);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740();
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))();
  }
  if (0xf < uStack_14) {
    _free(unaff_ESI);
    return;
  }
  uStack_14 = 0xf;
  local_18 = 0;
  FUN_00401740();
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))();
  }
  if (0xf < local_18) {
    _free(unaff_EDI);
    return;
  }
  local_18 = 0xf;
  local_1c = (void *)0x0;
  FUN_00401740();
  _Memory_00 = &uStack_30;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))();
  }
  if ((void *)0xf < local_1c) {
    _free(uStack_30);
    return;
  }
  local_1c = (void *)0xf;
  uStack_30 = (void **)((uint)uStack_30 & 0xffffff00);
  FUN_00401740(s_btn_col_rank_009d8540);
  _Memory = (void *)((int)register0x00000010 + -0x34);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(1);
  }
  FUN_00401740(s_btn_col_rank_asc_009d8550,0x10);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x38);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(0);
  }
  FUN_00401740(s_btn_col_rank_desc_009d8564,0x11);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x3c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(0);
  }
  FUN_00401740(s_btn_col_conn_009d8578,0xc);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x40);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(1);
  }
  uStack_30 = (void **)0x0;
  FUN_00401740(s_btn_col_conn_asc_009d8588,0x10);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x44);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(0);
  }
  if (0xf < uStack_30) {
    _free(_Memory_00);
    return;
  }
  uStack_30 = (void **)0xf;
  uVar2 = 0;
  FUN_00401740(s_btn_col_conn_desc_009d859c,0x11);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x48);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(0);
  }
  if (uVar2 < 0x10) {
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00671e60 @ 0x00671e60 ====

/* WARNING: Removing unreachable block (ram,0x00671f8b) */
/* WARNING: Removing unreachable block (ram,0x00671f9f) */
/* WARNING: Removing unreachable block (ram,0x00671f7a) */

void FUN_00671e60(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined1 *puVar6;
  undefined1 auStack_266 [2];
  undefined1 local_264 [20];
  uint uStack_250;
  undefined1 auStack_248 [28];
  undefined1 auStack_22c [28];
  undefined1 auStack_210 [28];
  undefined1 auStack_1f4 [36];
  undefined1 local_1d0 [32];
  undefined4 uStack_1b0;
  
  if (param_1 == *(int *)(in_ECX + 0x28)) {
    return;
  }
  if (*(int *)(in_ECX + 0x28) != 0) {
    FUN_00670410();
  }
  if (param_1 == 0) {
    return;
  }
  switch(param_1) {
  case 1:
    puVar5 = operator_new(4);
    if (puVar5 == (undefined4 *)0x0) {
      return;
    }
    *puVar5 = &PTR_FUN_009d87f4;
    break;
  case 2:
    (**(code **)(*DAT_00b5aca8 + 0x84))(*(undefined4 *)(in_ECX + 0xc));
    puVar5 = operator_new(4);
    if (puVar5 == (undefined4 *)0x0) {
      return;
    }
    *puVar5 = &PTR_FUN_009d881c;
    break;
  case 3:
    (**(code **)(*DAT_00b5aca8 + 0x20))(local_264,*(undefined4 *)(in_ECX + 0xc));
    pvVar1 = operator_new(0x90);
    if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    FUN_00401830(&DAT_009d8323);
    FUN_00401830(&DAT_009d8320);
    uVar4 = FUN_00404230(auStack_1f4);
    puVar6 = auStack_248;
    uVar2 = FUN_00671300(auStack_22c,uStack_250 >> 8 & 0xff);
    uVar3 = FUN_00671240(auStack_210,uStack_250);
    FUN_006739a0(auStack_266 + -6,uVar3,uVar2,puVar6,uVar4);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 4:
    puVar5 = operator_new(4);
    if (puVar5 == (undefined4 *)0x0) {
      return;
    }
    *puVar5 = &PTR_FUN_009d886c;
    break;
  case 5:
    (**(code **)(*DAT_00b5aca8 + 0x18))(local_1d0);
    puVar5 = operator_new(0xc);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
      FUN_00537c20();
    }
    else {
      uVar4 = (**(code **)(*DAT_00b5ad1c + 0x94))();
      puVar5[1] = uStack_1b0;
      *puVar5 = &PTR_FUN_009d87cc;
      puVar5[2] = uVar4;
      FUN_00537c20();
    }
    break;
  case 6:
    puVar5 = operator_new(4);
    if (puVar5 == (undefined4 *)0x0) {
      return;
    }
    *puVar5 = &PTR_FUN_009d8844;
    break;
  default:
    goto switchD_00671ea1_default;
  }
  if (puVar5 != (undefined4 *)0x0) {
    FUN_00797a20(puVar5);
    *(int *)(in_ECX + 0x28) = param_1;
  }
switchD_00671ea1_default:
  return;
}


// ==== FUN_006720b0 @ 0x006720b0 ====

void FUN_006720b0(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  uint uVar4;
  void **ppvVar5;
  void **ppvVar6;
  uint uVar7;
  undefined1 *in_stack_fffffda0;
  uint in_stack_fffffda4;
  int *piStack_22c;
  int iStack_228;
  void *pvStack_220;
  undefined1 uStack_210;
  undefined1 uStack_20f;
  undefined1 uStack_20e;
  undefined1 uStack_20d;
  undefined1 uStack_20c;
  undefined1 uStack_20b;
  undefined2 uStack_20a;
  char cStack_206;
  undefined1 auStack_200 [4];
  void *pvStack_1fc;
  undefined4 uStack_1f8;
  undefined1 auStack_1f0 [4];
  undefined4 uStack_1ec;
  uint uStack_1e8;
  void *pvStack_1e0;
  undefined1 auStack_1d8 [4];
  void *pvStack_1d4;
  uint uStack_1d0;
  uint uStack_1cc;
  undefined4 uStack_1c4;
  uint uStack_1c0;
  undefined4 uStack_1bc;
  undefined1 auStack_1b4 [12];
  void *pvStack_1a8;
  undefined1 auStack_1a0 [8];
  undefined4 uStack_198;
  uint uStack_194;
  void *pvStack_18c;
  undefined4 uStack_17c;
  uint auStack_178 [2];
  void *pvStack_170;
  undefined4 uStack_160;
  void *pvStack_15c;
  undefined1 uStack_158;
  undefined4 uStack_14c;
  uint uStack_148;
  void *pvStack_144;
  undefined1 uStack_140;
  undefined4 uStack_134;
  uint uStack_130;
  undefined4 uStack_12c;
  undefined1 auStack_128 [4];
  void *pvStack_124;
  undefined4 uStack_114;
  void *apvStack_110 [4];
  undefined4 uStack_100;
  uint uStack_fc;
  undefined1 auStack_f0 [4];
  void *pvStack_ec;
  undefined4 uStack_dc;
  uint uStack_d8;
  void *pvStack_c8;
  undefined4 uStack_b8;
  void *apvStack_b4 [4];
  undefined4 uStack_a4;
  uint uStack_a0;
  undefined1 auStack_94 [4];
  void *pvStack_90;
  undefined4 uStack_80;
  uint uStack_7c;
  void *pvStack_74;
  undefined4 uStack_64;
  void *pvStack_60;
  undefined4 uStack_50;
  uint uStack_4c;
  void *apvStack_48 [4];
  undefined4 uStack_38;
  uint uStack_34;
  void *pvStack_28;
  undefined1 auStack_24 [12];
  undefined4 uStack_18;
  uint uStack_14;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x24) + 0x30))();
  iStack_228 = *(int *)(iVar1 + 0x88);
  *(int *)(in_ECX + 8) = iStack_228;
  uStack_20c = 0xf;
  uStack_20b = 0;
  uStack_20a = 0;
  uStack_210 = 0;
  uStack_20f = 0;
  uStack_20e = 0;
  uStack_20d = 0;
  pvStack_220 = (void *)((uint)pvStack_220 & 0xffffff00);
  pvStack_15c = (void *)0xf;
  uStack_160 = 0;
  pvStack_170 = (void *)((uint)pvStack_170 & 0xffffff00);
  uStack_194 = 0xf;
  uStack_198 = 0;
  pvStack_1a8 = (void *)((uint)pvStack_1a8 & 0xffffff00);
  uStack_1cc = 0xf;
  uStack_1d0 = 0;
  pvStack_1e0 = (void *)((uint)pvStack_1e0 & 0xffffff00);
  auStack_178[0] = 0xf;
  uStack_17c = 0;
  pvStack_18c = (void *)((uint)pvStack_18c & 0xffffff00);
  uVar4 = 0;
  do {
    if (iStack_228 + uVar4 < *(uint *)(in_ECX + 0x10)) {
      iVar1 = (**(code **)(*DAT_00b5aca8 + 0x20))(auStack_24,iStack_228 + uVar4);
      FUN_00401660(iVar1,0,0xffffffff);
      uStack_210 = *(undefined1 *)(iVar1 + 0x1c);
      uStack_20f = *(undefined1 *)(iVar1 + 0x1d);
      uStack_20e = *(undefined1 *)(iVar1 + 0x1e);
      uStack_20c = (undefined1)*(undefined2 *)(iVar1 + 0x20);
      uStack_20b = (undefined1)((ushort)*(undefined2 *)(iVar1 + 0x20) >> 8);
      if (0xf < uStack_14) {
        _free(pvStack_28);
        return;
      }
      uStack_14 = 0xf;
      uStack_18 = 0;
      pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
      FUN_00401660(&piStack_22c,0,0xffffffff);
      uVar2 = FUN_00671240(auStack_128,
                           CONCAT13(uStack_20d,CONCAT12(uStack_20e,CONCAT11(uStack_20f,uStack_210)))
                          );
      FUN_00401660(uVar2,0,0xffffffff);
      if ((void *)0xf < apvStack_110[0]) {
        _free(pvStack_124);
        return;
      }
      apvStack_110[0] = (void *)0xf;
      uStack_114 = 0;
      pvStack_124 = (void *)((uint)pvStack_124 & 0xffffff00);
      uVar2 = FUN_00671300(&uStack_64,uStack_20f);
      FUN_00401660(uVar2,0,0xffffffff);
      if (0xf < uStack_4c) {
        _free(pvStack_60);
        return;
      }
      uStack_4c = 0xf;
      uStack_50 = 0;
      pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
      uVar2 = FUN_006711c0(auStack_f0,
                           CONCAT13(uStack_20b,CONCAT12(uStack_20c,CONCAT11(uStack_20d,uStack_20e)))
                          );
      FUN_00401660(uVar2,0,0xffffffff);
      if (0xf < uStack_d8) {
        _free(pvStack_ec);
        return;
      }
      uStack_d8 = 0xf;
      uStack_dc = 0;
      pvStack_ec = (void *)((uint)pvStack_ec & 0xffffff00);
      in_stack_fffffda0 = (undefined1 *)((uint)in_stack_fffffda0 & 0xffffff00);
      FUN_00401740(s_btn_record__d_009d832c,0xd);
      uVar2 = FUN_00404230(&uStack_80);
      piStack_22c = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar2);
      if (0xf < pvStack_60) {
        _free(pvStack_74);
        return;
      }
      pvStack_60 = (void *)0xf;
      uStack_64 = 0;
      pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
      if (piStack_22c != (int *)0x0) {
        (**(code **)(*piStack_22c + 0x24))(1);
        pvStack_144 = (void *)0xf;
        uStack_148 = 0;
        uStack_158 = 0;
        FUN_00401660(auStack_178,0,0xffffffff);
        in_stack_fffffda4 = in_stack_fffffda4 & 0xffffff00;
        FUN_00401740(s_lbl_recName__d_009d833c,0xe);
        ppvVar5 = apvStack_b4;
        uVar2 = FUN_00404230(ppvVar5,in_stack_fffffda0,in_stack_fffffda4);
        piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar2);
        if ((piVar3 != (int *)0x0) && (iVar1 = (**(code **)(*piVar3 + 0x30))(), iVar1 != 0)) {
          FUN_0055a260(&uStack_160);
        }
        if (0xf < uStack_148) {
          _free(pvStack_15c);
          return;
        }
        uStack_148 = 0xf;
        uStack_14c = 0;
        pvStack_15c = (void *)((uint)pvStack_15c & 0xffffff00);
        if (0xf < uStack_a0) {
          _free(apvStack_b4[0]);
          return;
        }
        uStack_a0 = 0xf;
        uStack_a4 = 0;
        apvStack_b4[0] = (void *)((uint)apvStack_b4[0] & 0xffffff00);
        uStack_12c = 0xf;
        uStack_130 = 0;
        uStack_140 = 0;
        FUN_00401660(auStack_1b4,0,0xffffffff);
        in_stack_fffffda0 = (undefined1 *)((uint)in_stack_fffffda0 & 0xffffff00);
        FUN_00401740(s_lbl_recClass__d_009d834c,0xf);
        ppvVar6 = apvStack_48;
        uVar2 = FUN_00404230(ppvVar6,ppvVar5,in_stack_fffffda0);
        piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar2);
        if ((piVar3 != (int *)0x0) && (iVar1 = (**(code **)(*piVar3 + 0x30))(), iVar1 != 0)) {
          FUN_0055a260(&uStack_148);
        }
        if (0xf < uStack_130) {
          _free(pvStack_144);
          return;
        }
        uStack_130 = 0xf;
        uStack_134 = 0;
        pvStack_144 = (void *)((uint)pvStack_144 & 0xffffff00);
        if (0xf < uStack_34) {
          _free(apvStack_48[0]);
          return;
        }
        uStack_34 = 0xf;
        uStack_38 = 0;
        apvStack_48[0] = (void *)((uint)apvStack_48[0] & 0xffffff00);
        uStack_1bc = 0xf;
        uStack_1c0 = 0;
        uStack_1d0 = uStack_1d0 & 0xffffff00;
        FUN_00401660(auStack_1f0,0,0xffffffff);
        uVar7 = (uint)ppvVar5 & 0xffffff00;
        FUN_00401740(s_lbl_recGrade__d_009d835c,0xf);
        ppvVar5 = apvStack_110;
        uVar2 = FUN_00404230(ppvVar5,ppvVar6,uVar7);
        piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar2);
        if ((piVar3 != (int *)0x0) && (iVar1 = (**(code **)(*piVar3 + 0x30))(), iVar1 != 0)) {
          FUN_0055a260(auStack_1d8);
        }
        if (0xf < uStack_1c0) {
          _free(pvStack_1d4);
          return;
        }
        uStack_1c0 = 0xf;
        uStack_1c4 = 0;
        pvStack_1d4 = (void *)((uint)pvStack_1d4 & 0xffffff00);
        if (0xf < uStack_fc) {
          _free(apvStack_110[0]);
          return;
        }
        uStack_fc = 0xf;
        uStack_100 = 0;
        apvStack_110[0] = (void *)((uint)apvStack_110[0] & 0xffffff00);
        uStack_1f8 = 0xf;
        pvStack_1fc = (void *)0x0;
        uStack_20c = 0;
        in_stack_fffffda4 = 0x6725f0;
        FUN_00401660(auStack_1a0,0,0xffffffff);
        uVar7 = (uint)ppvVar6 & 0xffffff00;
        FUN_00401740(s_lbl_recConn__d_009d836c,0xe);
        uVar2 = FUN_00404230(&uStack_dc,ppvVar5,uVar7);
        piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar2);
        if ((piVar3 != (int *)0x0) && (iVar1 = (**(code **)(*piVar3 + 0x30))(), iVar1 != 0)) {
          FUN_0055a260(auStack_200);
        }
        if (0xf < uStack_1e8) {
          _free(pvStack_1fc);
          return;
        }
        uStack_1e8 = 0xf;
        uStack_1ec = 0;
        pvStack_1fc = (void *)((uint)pvStack_1fc & 0xffffff00);
        if ((void *)0xf < apvStack_b4[0]) {
          _free(pvStack_c8);
          return;
        }
        apvStack_b4[0] = (void *)0xf;
        uStack_b8 = 0;
        pvStack_c8 = (void *)((uint)pvStack_c8 & 0xffffff00);
        if (cStack_206 == '\0') {
          FUN_006713f0(uVar4,0xff888888);
        }
        else {
          FUN_006713f0(uVar4,0xffffffff);
        }
      }
    }
    else {
      FUN_00401740(s_btn_record__d_009d837c,0xd);
      in_stack_fffffda0 = auStack_94;
      uVar2 = FUN_00404230(in_stack_fffffda0);
      piStack_22c = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar2);
      if (0xf < uStack_7c) {
        _free(pvStack_90);
        return;
      }
      uStack_7c = 0xf;
      uStack_80 = 0;
      pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
      if (piStack_22c != (int *)0x0) {
        (**(code **)(*piStack_22c + 0x24))(0);
      }
    }
    uVar4 = uVar4 + 1;
    if (7 < uVar4) {
      iVar1 = 0;
      if (8 < *(uint *)(in_ECX + 0x10)) {
        iVar1 = *(uint *)(in_ECX + 0x10) - 8;
      }
      (**(code **)(**(int **)(in_ECX + 0x24) + 0x30))(iVar1);
      FUN_0055aac0(iVar1);
      if (0xf < auStack_178[0]) {
        _free(pvStack_18c);
        return;
      }
      auStack_178[0] = 0xf;
      uStack_17c = 0;
      pvStack_18c = (void *)((uint)pvStack_18c & 0xffffff00);
      if (0xf < uStack_1cc) {
        _free(pvStack_1e0);
        return;
      }
      uStack_1cc = 0xf;
      uStack_1d0 = 0;
      pvStack_1e0 = (void *)((uint)pvStack_1e0 & 0xffffff00);
      if (0xf < uStack_194) {
        _free(pvStack_1a8);
        return;
      }
      uStack_194 = 0xf;
      uStack_198 = 0;
      pvStack_1a8 = (void *)((uint)pvStack_1a8 & 0xffffff00);
      if ((void *)0xf < pvStack_15c) {
        _free(pvStack_170);
        return;
      }
      pvStack_15c = (void *)0xf;
      uStack_160 = 0;
      pvStack_170 = (void *)((uint)pvStack_170 & 0xffffff00);
      if (CONCAT22(uStack_20a,CONCAT11(uStack_20b,uStack_20c)) < 0x10) {
        return;
      }
      _free(pvStack_220);
      return;
    }
  } while( true );
}


// ==== FUN_00672820 @ 0x00672820 ====

/* WARNING: Removing unreachable block (ram,0x00672b2e) */
/* WARNING: Removing unreachable block (ram,0x00672bb2) */
/* WARNING: Removing unreachable block (ram,0x00672ac9) */

void FUN_00672820(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  void **ppvVar4;
  void **ppvVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uStack_21c;
  undefined1 auStack_206 [6];
  uint uStack_200;
  void *pvStack_1fc;
  void *pvStack_1f8;
  void *pvStack_1f4;
  void *pvStack_1f0;
  uint uStack_1ec;
  uint uStack_1e8;
  uint uStack_1e4;
  void *pvStack_1e0;
  uint uStack_1dc;
  undefined4 uStack_1d8;
  undefined1 auStack_1d4 [4];
  undefined1 local_1d0 [4];
  uint uStack_1cc;
  undefined1 auStack_1c0 [4];
  void *pvStack_1bc;
  undefined4 uStack_1ac;
  uint uStack_1a8;
  undefined2 uStack_1a4;
  undefined2 uStack_1a2;
  ushort uStack_19e;
  undefined4 auStack_19a [102];
  
  uStack_21c = local_1d0;
  (**(code **)(*DAT_00b5aca8 + 0x18))();
  uVar1 = (**(code **)(*DAT_00b5aca8 + 0x1c))();
  *(uint *)(in_ECX + 0x10) = uVar1;
  if (uVar1 <= *(uint *)(in_ECX + 0xc)) {
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
  uStack_1d8 = 0xf;
  uStack_1dc = 0;
  uStack_1ec = uStack_1ec & 0xffffff00;
  FUN_00401740(s_lbl_guildName_009d838c,0xd);
  pvStack_1f4 = (void *)0xf;
  pvStack_1f8 = (void *)0x0;
  FUN_00401660(auStack_1d4,0,0xffffffff);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1f0);
  if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x30))(), iVar3 != 0)) {
    FUN_0055a260(auStack_206 + -10);
  }
  if ((void *)0xf < pvStack_1f8) {
    _free(unaff_EBX);
    return;
  }
  pvStack_1f8 = (void *)0xf;
  pvStack_1fc = (void *)0x0;
  if (0xf < uStack_1dc) {
    _free(pvStack_1f0);
    return;
  }
  pvStack_1f8 = (void *)0xf;
  pvStack_1fc = (void *)0x0;
  FUN_00401740(s_lbl_memberCnt_009d83a0,0xd);
  FUN_00401740(&DAT_009d839c,2);
  ppvVar5 = &pvStack_1f4;
  FUN_00404230(ppvVar5);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_206 + -10);
  if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x30))(), iVar3 != 0)) {
    FUN_0055a260(&pvStack_1f8);
  }
  if (0xf < pvStack_1e0) {
    _free(pvStack_1f4);
    return;
  }
  pvStack_1e0 = (void *)0xf;
  uStack_1e4 = 0;
  pvStack_1f4 = (void *)((uint)pvStack_1f4 & 0xffffff00);
  if ((void *)0xf < pvStack_1fc) {
    _free(unaff_EBP);
    return;
  }
  pvStack_1fc = (void *)0xf;
  uStack_200 = 0;
  FUN_00401740(s_lbl_guildLevel_009d83b4,0xe);
  uVar6 = 0;
  FUN_00401740(&DAT_009d83b0,2);
  ppvVar4 = &pvStack_1f8;
  FUN_00404230(ppvVar4,ppvVar5,uVar6);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_206 + -0xe);
  if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x30))(), iVar3 != 0)) {
    FUN_0055a260(&pvStack_1fc);
  }
  if (0xf < uStack_1e4) {
    _free(pvStack_1f8);
    return;
  }
  uStack_1e4 = 0xf;
  uStack_1e8 = 0;
  pvStack_1f8 = (void *)((uint)pvStack_1f8 & 0xffffff00);
  if (0xf < uStack_200) {
    _free(unaff_ESI);
    return;
  }
  uStack_200 = 0xf;
  FUN_00401740(s_lbl_advanNum_009d83c8,0xc);
  uVar1 = (uint)ppvVar5 & 0xffffff00;
  FUN_00401740(&DAT_009d83c4,2);
  FUN_00404230(&pvStack_1fc,ppvVar4,uVar1);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_206 + -0x12);
  if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x30))(), iVar3 != 0)) {
    FUN_0055a260(&uStack_200);
  }
  if (0xf < uStack_1e8) {
    _free(pvStack_1fc);
    return;
  }
  uStack_1e8 = 0xf;
  uStack_1ec = 0;
  pvStack_1fc = (void *)((uint)pvStack_1fc & 0xffffff00);
  FUN_00401740(s_guildbg_009d83d8,7);
  FUN_00401740(s_pan_markback_009d83e0,0xc);
  FUN_006704f0(&uStack_21c,&uStack_200,uStack_1a4);
  if (0xf < uStack_1e8) {
    _free(pvStack_1fc);
    return;
  }
  uStack_1e8 = 0xf;
  uStack_1ec = 0;
  pvStack_1fc = (void *)((uint)pvStack_1fc & 0xffffff00);
  FUN_00401740(s_guildicon_009d83f0,9);
  FUN_00401740(s_pan_markfront_009d83fc,0xd);
  puVar8 = &uStack_21c;
  uVar7 = 0x672bac;
  FUN_006704f0(puVar8,&uStack_200,uStack_1a2);
  if (0xf < uStack_1e8) {
    _free(pvStack_1fc);
    return;
  }
  uVar10 = 0xf;
  uVar9 = 0;
  uVar1 = uVar1 & 0xffffff00;
  FUN_00401660(auStack_1c0,0,0xffffffff);
  FUN_00671120(ppvVar4,uVar1,uVar6,uVar7,puVar8,uVar9,uVar10);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)((int)auStack_19a + (uint)uStack_19e * 0x27);
  FUN_006720b0();
  if (0xf < uStack_1a8) {
    _free(pvStack_1bc);
    return;
  }
  uStack_1a8 = 0xf;
  uStack_1ac = 0;
  pvStack_1bc = (void *)((uint)pvStack_1bc & 0xffffff00);
  if (uStack_1cc < 0x10) {
    return;
  }
  _free(pvStack_1e0);
  return;
}


// ==== FUN_00672c70 @ 0x00672c70 ====

undefined4 FUN_00672c70(int *param_1)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = (**(code **)(*param_1 + 4))();
  if (uVar2 < 0x70320003) {
    if (uVar2 == 0x70320002) {
      FUN_00672820();
      return 1;
    }
    if (uVar2 == 0x10010) {
      cVar1 = FUN_00671690(param_1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
    else if (uVar2 == 0x40001) {
      FUN_00671590();
      return 0;
    }
  }
  else if (uVar2 == 0x70320007) {
    FUN_00670410();
    return 1;
  }
  return 0;
}


// ==== FUN_00672cf0 @ 0x00672cf0 ====

void FUN_00672cf0(void)

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
  FUN_00401740(s_UI_Game2_Guild_ui_guildwnd_txt_009d81b0,0x1e);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740(s_memList_scroll_009d81d0,0xe);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_34 + 0xc);
  *(undefined4 *)(in_ECX + 0x24) = uVar3;
  if (uStack_14 < 0x10) {
    FUN_00672820();
    return;
  }
  _free(unaff_EDI);
  return;
}


// ==== FUN_00672db0 @ 0x00672db0 ====

void FUN_00672db0(void)

{
  int in_ECX;
  undefined4 uVar1;
  
  (**(code **)(*DAT_00b5aca8 + 0x14))(*(undefined4 *)(in_ECX + 0x20));
  uVar1 = 0;
  (**(code **)(**(int **)(in_ECX + 0x24) + 0x30))(0);
  FUN_0055ab10(uVar1);
  FUN_006720b0();
  return;
}


// ==== FUN_00672de0 @ 0x00672de0 ====

void FUN_00672de0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d8894;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 0xc) = 1;
  in_ECX[8] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  FUN_00672cf0();
  return;
}


// ==== FUN_00672e10 @ 0x00672e10 ====

/* WARNING: Removing unreachable block (ram,0x00672ebb) */

void FUN_00672e10(undefined4 param_1,int param_2,byte param_3,ushort param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  
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
  puVar1[0x14] = uVar2;
  FUN_00401660(param_1,0,0xffffffff);
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),&DAT_009d84ce,0);
  if (iVar3 != 0) {
    FUN_00401660(param_2,0,0xffffffff);
  }
  if (0xff < param_4) {
    param_4 = 0xff;
  }
  *(ushort *)(puVar1 + 0x13) = (ushort)param_3 << 8 | param_4;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00672ee0 @ 0x00672ee0 ====

undefined4 FUN_00672ee0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  void *pvVar6;
  int in_ECX;
  char *pcVar7;
  undefined4 uVar8;
  undefined *puVar9;
  undefined1 local_230 [2];
  undefined1 auStack_22e [2];
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined1 local_220 [4];
  undefined4 local_21c;
  undefined4 local_218;
  undefined4 local_214;
  undefined1 auStack_204 [8];
  undefined1 local_1fc [22];
  char cStack_1e6;
  undefined1 auStack_1e0 [8];
  undefined4 local_1d8;
  undefined1 local_1d0 [32];
  undefined4 uStack_1b0;
  
  local_1d8 = 0;
  if (*(int *)(in_ECX + 0x28) != 0) {
    return 1;
  }
  if (((param_1 == 4) &&
      (iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_memList_scroll_009d85b0,0xe),
      iVar2 == 0)) && (param_3 == 6)) {
    FUN_00671850();
    FUN_006720b0();
    return 1;
  }
  if (param_3 == 4) {
    if (param_1 != 1) {
      return 0;
    }
    local_21c = 0;
    local_218 = 0;
    local_214 = 0;
    FUN_00404fb0(param_2,0x5f,local_220);
    pcVar7 = s_record_009d85c0;
    uVar3 = FUN_00405d30(1);
    cVar1 = FUN_004036a0(uVar3,pcVar7);
    if ((cVar1 != '\0') && (*(int *)(in_ECX + 0x2c) != 1)) {
      uVar8 = 0xff00ff00;
      uVar3 = FUN_00405d30(2);
      uVar3 = thunk_FUN_00796fb0(uVar3,uVar8);
      FUN_006713f0(uVar3,uVar8);
    }
LAB_00672fc4:
    FUN_00406250();
    return 0;
  }
  if (param_3 == 5) {
    if (param_1 != 1) {
      return 0;
    }
    local_21c = 0;
    local_218 = 0;
    local_214 = 0;
    FUN_00404fb0(param_2,0x5f,local_220);
    pcVar7 = s_record_009d85c8;
    uVar3 = FUN_00405d30(1);
    cVar1 = FUN_004036a0(uVar3,pcVar7);
    if ((cVar1 != '\0') && (*(int *)(in_ECX + 0x2c) != 1)) {
      iVar2 = *DAT_00b5aca8;
      uVar3 = FUN_00405d30(2);
      iVar4 = thunk_FUN_00796fb0(uVar3);
      (**(code **)(iVar2 + 0x20))(local_1fc,iVar4 + *(int *)(in_ECX + 8));
      iVar2 = (-(uint)(cStack_1e6 != '\0') & 0x777777) - 0x777778;
      uVar3 = FUN_00405d30(2);
      uVar3 = thunk_FUN_00796fb0(uVar3,iVar2);
      FUN_006713f0(uVar3,iVar2);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    goto LAB_00672fc4;
  }
  if (param_3 == 2) {
    if (param_1 != 1) {
      return 0;
    }
    local_21c = 0;
    local_218 = 0;
    local_214 = 0;
    FUN_00404fb0(param_2,0x5f,local_220);
    pcVar7 = s_record_009d85d0;
    uVar3 = FUN_00405d30(1);
    cVar1 = FUN_004036a0(uVar3,pcVar7);
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5aca8 + 0x20))(local_1fc,*(undefined4 *)(in_ECX + 0xc));
      FUN_006713f0(*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8),
                   (-(uint)(cStack_1e6 != '\0') & 0x777777) - 0x777778);
      uVar3 = FUN_00405d30(2);
      iVar2 = thunk_FUN_00796fb0(uVar3);
      *(int *)(in_ECX + 0xc) = iVar2 + *(int *)(in_ECX + 8);
      (**(code **)(**(int **)(in_ECX + 4) + 0x5c))(auStack_1e0);
      uVar8 = 0xff00ff00;
      uVar3 = FUN_00405d30(2);
      uVar3 = thunk_FUN_00796fb0(uVar3,uVar8);
      FUN_006713f0(uVar3,uVar8);
      FUN_006719a0(local_230 + -0xc);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    goto LAB_00672fc4;
  }
  if (param_3 != 1) {
    return 0;
  }
  if (param_1 != 1) {
    if (param_1 == 0) {
      FUN_00671850();
      return 1;
    }
    return 0;
  }
  local_22c = 0;
  local_228 = 0;
  local_224 = 0;
  FUN_00404fb0(param_2,0x5f,local_230);
  puVar9 = &DAT_009d85d8;
  uVar3 = FUN_00405d30(0);
  cVar1 = FUN_004036a0(uVar3,puVar9);
  if (cVar1 != '\0') {
    pcVar7 = s_party_009d85dc;
    uVar3 = FUN_00405d30(1);
    cVar1 = FUN_004036a0(uVar3,pcVar7);
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5aca8 + 0x40))();
      (**(code **)(*DAT_00b5a7b4 + 0x2c))();
    }
    FUN_00406250();
    return 1;
  }
  puVar9 = &DAT_009d85e4;
  uVar3 = FUN_00405d30(1);
  cVar1 = FUN_004036a0(uVar3,puVar9);
  if (cVar1 != '\0') {
    (**(code **)(*DAT_00b5aca8 + 0x40))();
    *(undefined1 *)(in_ECX + 0x30) = 0;
    FUN_00406250();
    return 1;
  }
  puVar9 = &DAT_009d85ec;
  uVar3 = FUN_00405d30(1);
  cVar1 = FUN_004036a0(uVar3,puVar9);
  if (cVar1 != '\0') {
    FUN_00671ae0();
    puVar9 = &DAT_009d85f0;
    uVar3 = FUN_00405d30(2);
    cVar1 = FUN_004036a0(uVar3,puVar9);
    if (cVar1 != '\0') {
      FUN_00401830(s_btn_col_name_009d85f8);
      FUN_006703f0(local_220,0);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    pcVar7 = s_class_009d8630;
    uVar3 = FUN_00405d30(2);
    cVar1 = FUN_004036a0(uVar3,pcVar7);
    if (cVar1 != '\0') {
      FUN_00401830(s_btn_col_class_009d8638);
      FUN_006703f0(local_220,0);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    puVar9 = &DAT_009d8670;
    uVar3 = FUN_00405d30(2);
    cVar1 = FUN_004036a0(uVar3,puVar9);
    if (cVar1 != '\0') {
      FUN_00401830(s_btn_col_rank_009d8678);
      FUN_006703f0(local_220,0);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    puVar9 = &DAT_009d86b0;
    uVar3 = FUN_00405d30(2);
    cVar1 = FUN_004036a0(uVar3,puVar9);
    if (cVar1 != '\0') {
      FUN_00401830(s_btn_col_conn_009d86b8);
      FUN_006703f0(local_220,0);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    FUN_00672db0();
    FUN_00406250();
    return 1;
  }
  pcVar7 = s_manage_009d86f0;
  uVar3 = FUN_00405d30(1);
  cVar1 = FUN_004036a0(uVar3,pcVar7);
  if (cVar1 == '\0') {
    puVar9 = &DAT_009d86f8;
    uVar3 = FUN_00405d30(1);
    cVar1 = FUN_004036a0(uVar3,puVar9);
    if (cVar1 == '\0') {
      pcVar7 = s_power_009d8700;
      uVar3 = FUN_00405d30(1);
      cVar1 = FUN_004036a0(uVar3,pcVar7);
      if (cVar1 == '\0') {
        pcVar7 = s_notice_009d8708;
        uVar3 = FUN_00405d30(1);
        cVar1 = FUN_004036a0(uVar3,pcVar7);
        if (cVar1 == '\0') {
          pcVar7 = s_miniList_009d8710;
          uVar3 = FUN_00405d30(1);
          cVar1 = FUN_004036a0(uVar3,pcVar7);
          if (cVar1 == '\0') {
            pcVar7 = s_state_009d871c;
            uVar3 = FUN_00405d30(1);
            cVar1 = FUN_004036a0(uVar3,pcVar7);
            if (cVar1 != '\0') {
              FUN_00671850();
              if (*(int *)(in_ECX + 0x28) != 6) {
                if (*(int *)(in_ECX + 0x28) != 0) {
                  FUN_00670410();
                }
                puVar5 = operator_new(4);
                if (puVar5 != (undefined4 *)0x0) {
                  *puVar5 = &PTR_FUN_009d8844;
                  FUN_00797a20(puVar5);
                  *(undefined4 *)(in_ECX + 0x28) = 6;
                }
              }
              goto LAB_006734d3;
            }
            pcVar7 = s_advanture_009d8724;
            uVar3 = FUN_00405d30(1);
            cVar1 = FUN_004036a0(uVar3,pcVar7);
            if (cVar1 != '\0') {
              FUN_00671850();
              if (*(int *)(in_ECX + 0x28) != 5) {
                if (*(int *)(in_ECX + 0x28) != 0) {
                  FUN_00670410();
                }
                (**(code **)(*DAT_00b5aca8 + 0x18))(local_1d0);
                puVar5 = operator_new(0xc);
                if (puVar5 == (undefined4 *)0x0) {
                  puVar5 = (undefined4 *)0x0;
                }
                else {
                  uVar3 = (**(code **)(*DAT_00b5ad1c + 0x94))();
                  *puVar5 = &PTR_FUN_009d87cc;
                  puVar5[1] = uStack_1b0;
                  puVar5[2] = uVar3;
                }
                FUN_00537c20();
                if (puVar5 != (undefined4 *)0x0) {
                  FUN_00797a20(puVar5);
                  *(undefined4 *)(in_ECX + 0x28) = 5;
                }
              }
              goto LAB_006734d3;
            }
            pcVar7 = s_secede_009d8730;
            uVar3 = FUN_00405d30(1);
            cVar1 = FUN_004036a0(uVar3,pcVar7);
            if (cVar1 != '\0') {
              FUN_00671850();
              FUN_00401830(&DAT_009d8737);
              FUN_00401830(s_ui_secedeguild_txt_009d8738);
              FUN_00672e10(local_220,local_1fc,0xf,4);
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            pcVar7 = s_chgGrade_009d874c;
            uVar3 = FUN_00405d30(1);
            cVar1 = FUN_004036a0(uVar3,pcVar7);
            if (cVar1 != '\0') {
              FUN_00671850();
              FUN_00671e60(2);
              goto LAB_006734d3;
            }
            pcVar7 = s_curPos_009d8758;
            uVar3 = FUN_00405d30(1);
            cVar1 = FUN_004036a0(uVar3,pcVar7);
            if (cVar1 == '\0') {
              puVar9 = &DAT_009d8760;
              uVar3 = FUN_00405d30(1);
              cVar1 = FUN_004036a0(uVar3,puVar9);
              if (cVar1 != '\0') {
                FUN_00671850();
                (**(code **)(*DAT_00b5aca8 + 0x20))(local_220,*(undefined4 *)(in_ECX + 0xc));
                FUN_00401830(s_ui_kickguild_txt_009d8768);
                FUN_00672e10(auStack_204,&local_228,0xf,5);
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              pcVar7 = s_whisper_009d877c;
              uVar3 = FUN_00405d30(1);
              cVar1 = FUN_004036a0(uVar3,pcVar7);
              if (cVar1 != '\0') {
                (**(code **)(*DAT_00b5aca8 + 0x20))(local_1fc,*(undefined4 *)(in_ECX + 0xc));
                pvVar6 = operator_new(0x20);
                if (pvVar6 == (void *)0x0) {
                  uVar3 = 0;
                }
                else {
                  uVar3 = FUN_00673b20(auStack_204);
                }
                FUN_00797a20(uVar3);
                FUN_00671850();
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              puVar9 = &DAT_009d8784;
              uVar3 = FUN_00405d30(1);
              cVar1 = FUN_004036a0(uVar3,puVar9);
              if (cVar1 == '\0') {
                pcVar7 = s_delegate_009d878c;
                uVar3 = FUN_00405d30(1);
                cVar1 = FUN_004036a0(uVar3,pcVar7);
                if (cVar1 != '\0') {
                  FUN_00671850();
                  FUN_00401830(&DAT_009d8795);
                  FUN_00401830(s_ui_delegateguild_txt_009d8798);
                  FUN_00672e10(local_1fc,local_220,0xf,6);
                    /* WARNING: Subroutine does not return */
                  FUN_00446f10();
                }
                FUN_00406250();
                return 0;
              }
              FUN_00671850();
              FUN_00671e60(3);
              goto LAB_006734d3;
            }
          }
          FUN_00671850();
        }
        else {
          FUN_00671850();
          FUN_00671e60(1);
        }
      }
      else {
        FUN_00671850();
        if (*(int *)(in_ECX + 0x28) != 4) {
          if (*(int *)(in_ECX + 0x28) != 0) {
            FUN_00670410();
          }
          puVar5 = operator_new(4);
          if (puVar5 != (undefined4 *)0x0) {
            *puVar5 = &PTR_FUN_009d886c;
            FUN_00797a20(puVar5);
            *(undefined4 *)(in_ECX + 0x28) = 4;
          }
        }
      }
      goto LAB_006734d3;
    }
    uVar3 = 3;
  }
  else {
    uVar3 = 2;
  }
  FUN_00671a30(uVar3);
LAB_006734d3:
  FUN_00406250();
  return 1;
}


// ==== FUN_00673940 @ 0x00673940 ====

undefined4 FUN_00673940(void)

{
  return 0x2e;
}


// ==== FUN_00673950 @ 0x00673950 ====

undefined1 FUN_00673950(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x30);
}


// ==== FUN_00673960 @ 0x00673960 ====

void FUN_00673960(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d8894;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006739a0 @ 0x006739a0 ====

void FUN_006739a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d88c8;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  FUN_00401660(param_2,0,0xffffffff);
  in_ECX[0x15] = 0xf;
  in_ECX[0x14] = 0;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  FUN_00401660(param_3,0,0xffffffff);
  in_ECX[0x1c] = 0xf;
  in_ECX[0x1b] = 0;
  *(undefined1 *)(in_ECX + 0x17) = 0;
  FUN_00401660(param_4,0,0xffffffff);
  in_ECX[0x23] = 0xf;
  in_ECX[0x22] = 0;
  *(undefined1 *)(in_ECX + 0x1e) = 0;
  FUN_00401660(param_5,0,0xffffffff);
  return;
}


// ==== FUN_00673a40 @ 0x00673a40 ====

undefined4 FUN_00673a40(void)

{
  return 0x70320014;
}


// ==== FUN_00673a50 @ 0x00673a50 ====

void FUN_00673a50(byte param_1)

{
  void *in_ECX;
  
  FUN_00673a70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00673a70 @ 0x00673a70 ====

void FUN_00673a70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d88c8;
  if (0xf < (uint)in_ECX[0x23]) {
    _free((void *)in_ECX[0x1e]);
    return;
  }
  in_ECX[0x23] = 0xf;
  in_ECX[0x22] = 0;
  *(undefined1 *)(in_ECX + 0x1e) = 0;
  if (0xf < (uint)in_ECX[0x1c]) {
    _free((void *)in_ECX[0x17]);
    return;
  }
  in_ECX[0x1c] = 0xf;
  in_ECX[0x1b] = 0;
  *(undefined1 *)(in_ECX + 0x17) = 0;
  if (0xf < (uint)in_ECX[0x15]) {
    _free((void *)in_ECX[0x10]);
    return;
  }
  in_ECX[0x15] = 0xf;
  in_ECX[0x14] = 0;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  if (0xf < (uint)in_ECX[0xe]) {
    _free((void *)in_ECX[9]);
    return;
  }
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
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


// ==== FUN_00673b20 @ 0x00673b20 ====

void FUN_00673b20(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d88dc;
  in_ECX[6] = 0;
  in_ECX[7] = 0xf;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  return;
}


// ==== FUN_00673b50 @ 0x00673b50 ====

undefined4 FUN_00673b50(void)

{
  return 0x70040008;
}


// ==== FUN_00673b60 @ 0x00673b60 ====

void FUN_00673b60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d88dc;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00673b90 @ 0x00673b90 ====

undefined4 FUN_00673b90(void)

{
  return 0x70140010;
}


// ==== FUN_00673ba0 @ 0x00673ba0 ====

void FUN_00673ba0(void)

{
  return;
}


// ==== FUN_00673bb0 @ 0x00673bb0 ====

undefined1 FUN_00673bb0(void)

{
  return 0;
}


// ==== FUN_00673bc0 @ 0x00673bc0 ====

void FUN_00673bc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d89d8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00673be0 @ 0x00673be0 ====

undefined4 FUN_00673be0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 extraout_var;
  int in_ECX;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_skillup_ok_009d8998,0xe);
    if (iVar2 == 0) {
      puVar3 = operator_new(4);
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        *puVar3 = &PTR_FUN_009d89c4;
      }
      FUN_00797a20(puVar3);
      (**(code **)(*DAT_00b5acc0 + 0x48))(CONCAT22(extraout_var,*(undefined2 *)(in_ECX + 8)));
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_skillup_close_009d89a8);
    if (cVar1 != '\0') {
      puVar3 = operator_new(4);
      if (puVar3 == (undefined4 *)0x0) {
        FUN_00797a20(0);
        return 1;
      }
      *puVar3 = &PTR_FUN_009d89c4;
      FUN_00797a20(puVar3);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00673ca0 @ 0x00673ca0 ====

void FUN_00673ca0(void)

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
  FUN_00401740(s_UI_Game2_skill_ui_skillupwnd_txt_009d8928,0x20);
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


// ==== FUN_00673d20 @ 0x00673d20 ====

void FUN_00673d20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d89d8;
  *(undefined2 *)(in_ECX + 2) = 0;
  FUN_00673ca0();
  return;
}


// ==== FUN_00673d40 @ 0x00673d40 ====

void FUN_00673d40(undefined2 param_1,undefined4 param_2,void *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  uint in_stack_00000020;
  void **ppvStack_a4;
  void *local_90;
  void *local_8c [3];
  undefined4 uStack_80;
  uint local_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  void *apvStack_68 [3];
  int iStack_5c;
  undefined4 uStack_58;
  uint uStack_54;
  undefined1 uStack_38;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined1 uStack_1c;
  undefined4 uStack_c;
  void *pvStack_8;
  
  ppvStack_a4 = (void **)0xb;
  *(undefined2 *)(in_ECX + 8) = param_1;
  local_78 = 0xf;
  local_7c = 0;
  local_8c[0] = (void *)((uint)local_8c[0] & 0xffffff00);
  FUN_00401740();
  ppvStack_a4 = &local_90;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (0xf < local_7c) {
    _free(local_90);
    return;
  }
  local_7c = 0xf;
  uStack_80 = 0;
  local_90 = (void *)((uint)local_90 & 0xffffff00);
  if (piVar1 == (int *)0x0) {
    if (0xf < in_stack_00000020) {
      _free(param_3);
      return;
    }
  }
  else {
    iStack_5c = (**(code **)(*piVar1 + 0x30))();
    if (iStack_5c == 0) {
      if (0xf < in_stack_00000020) {
        _free(param_3);
        return;
      }
    }
    else {
      uStack_74 = 0;
      uStack_70 = 0;
      uStack_6c = 0;
      uStack_24 = 0xf;
      uStack_28 = 0;
      uStack_38 = 0;
      pvStack_8 = (void *)0xf;
      uStack_c = 0;
      uStack_1c = 0;
      FUN_00401740(s_<SKILLPOINT>_009d8958);
      FUN_00401740(&DAT_009d8968,2);
      uVar2 = FUN_00404230(apvStack_68 + -0xb);
      FUN_00401660(uVar2,0);
      if (0xf < local_7c) {
        _free(local_90);
        return;
      }
      FUN_004e6c20();
      FUN_00401740(s_<SKILLNAME>_009d896c);
      FUN_00401740(&DAT_009d8978,2);
      uVar2 = FUN_00404230(apvStack_68 + -0xb);
      FUN_00401660(uVar2,0);
      if (0xf < local_7c) {
        _free(local_90);
        return;
      }
      FUN_004e6c20();
      (**(code **)(*DAT_00b5a794 + 8))(&uStack_58,0,0x3c0033);
      FUN_0055a260(apvStack_68);
      local_8c[0] = (void *)0xf;
      local_90 = (void *)0x0;
      FUN_00401740(s_pan_skill_icon_009d897c,0xe);
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&ppvStack_a4);
      if ((void *)0xf < local_90) {
        _free(ppvStack_a4);
        return;
      }
      local_90 = (void *)0xf;
      ppvStack_a4 = (void **)((uint)ppvStack_a4 & 0xffffff00);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x30))();
        local_78 = 0;
        uStack_74 = 0;
        local_7c = 0xffffffff;
        FUN_00401830(s_skill_icon_009d898c);
        local_7c = (**(code **)(*DAT_00b5a7c0 + 8))(apvStack_68 + -0x10);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      if (0xf < uStack_54) {
        _free(apvStack_68[0]);
        return;
      }
      uStack_54 = 0xf;
      uStack_58 = 0;
      apvStack_68[0] = (void *)((uint)apvStack_68[0] & 0xffffff00);
      FUN_0040a7d0();
      FUN_004e67a0();
      if ((void *)0xf < param_3) {
        _free(pvStack_8);
        return;
      }
    }
  }
  return;
}


// ==== FUN_006740a0 @ 0x006740a0 ====

undefined4 FUN_006740a0(void)

{
  return 0x41;
}


// ==== FUN_006740b0 @ 0x006740b0 ====

void FUN_006740b0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d89d8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006740f0 @ 0x006740f0 ====

undefined4 FUN_006740f0(void)

{
  return 0x70140008;
}


// ==== FUN_00674100 @ 0x00674100 ====

void FUN_00674100(void)

{
  return;
}


// ==== FUN_00674110 @ 0x00674110 ====

undefined1 FUN_00674110(void)

{
  return 0;
}


// ==== FUN_00674120 @ 0x00674120 ====

void FUN_00674120(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d8acc;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00674140 @ 0x00674140 ====

undefined4 FUN_00674140(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_yes_009d8aa8,7);
  if (iVar1 == 0) {
    puVar2 = operator_new(4);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009d8ab8;
    }
    FUN_00797a20(puVar2);
    (**(code **)(*DAT_00b5acbc + 8))();
    return 1;
  }
  puVar2 = operator_new(4);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar2 = &PTR_FUN_009d8ab8;
  FUN_00797a20(puVar2);
  return 1;
}


// ==== FUN_006741e0 @ 0x006741e0 ====

void FUN_006741e0(void)

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
  FUN_00401740(s_UI_Game2_MsgBox_ui_skillreset_tx_009d8a44,0x21);
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


// ==== FUN_00674260 @ 0x00674260 ====

void FUN_00674260(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d8acc;
  FUN_006741e0();
  return;
}


// ==== __break @ 0x00674272 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00674280 @ 0x00674280 ====

void FUN_00674280(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  undefined4 unaff_ESI;
  void *unaff_EDI;
  uint in_stack_ffffff4c;
  uint in_stack_ffffff50;
  undefined1 auStack_82 [14];
  void *local_74;
  void *local_70;
  void *pvStack_68;
  undefined4 uStack_64;
  uint local_60;
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
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 uStack_18;
  
  local_40 = 0xf;
  local_44 = 0;
  local_54 = local_54 & 0xffffff00;
  local_24 = 0xf;
  local_28 = 0;
  local_38 = local_38 & 0xffffff00;
  FUN_00401740(s_<SKILLPOINT>_009d8a68);
  in_stack_ffffff4c = in_stack_ffffff4c & 0xffffff00;
  FUN_00401740(s__u____u___009d8a78,9);
  uVar1 = FUN_00404230(&local_74);
  FUN_00401660(uVar1,0);
  if (0xf < local_5c) {
    _free(local_70);
    return;
  }
  FUN_004e6c20();
  FUN_00401740(s_<COUNT>_009d8a84);
  in_stack_ffffff50 = in_stack_ffffff50 & 0xffffff00;
  FUN_00401740(&DAT_009d8a8c,2);
  uVar1 = FUN_00404230(&local_74,in_stack_ffffff4c,in_stack_ffffff50);
  FUN_00401660(uVar1,0);
  if (0xf < local_5c) {
    _free(local_70);
    return;
  }
  FUN_004e6c20();
  FUN_00401740(s_<BUYVALUE>_009d8a90);
  in_stack_ffffff50 = in_stack_ffffff50 & 0xffffff00;
  FUN_00401740(&DAT_009d8a9c,2);
  uVar1 = FUN_00404230(&local_74,in_stack_ffffff4c,in_stack_ffffff50);
  FUN_00401660(uVar1,0);
  if (0xf < local_5c) {
    _free(local_70);
    return;
  }
  FUN_004e6c20();
  local_5c = 0xf;
  local_60 = 0;
  local_70 = (void *)((uint)local_70 & 0xffffff00);
  FUN_00401740(s_textbox_009d8aa0);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (0xf < local_60) {
    _free(local_74);
    return;
  }
  local_60 = 0xf;
  uStack_64 = 0;
  local_74 = (void *)((uint)local_74 & 0xffffff00);
  (**(code **)(*piVar2 + 0x30))();
  (**(code **)(*DAT_00b5a794 + 8))(&local_24,0,0x3c001d,auStack_82 + -6);
  FUN_005569f0(auStack_34,1);
  if (0xf < uStack_1c) {
    _free(pvStack_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
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
  FUN_004e65b0(unaff_EDI,unaff_ESI,auStack_82 + -0x16,uStack_18);
  _free(unaff_EDI);
  return;
}


// ==== FUN_00674530 @ 0x00674530 ====

undefined4 FUN_00674530(void)

{
  return 0x2c;
}


// ==== FUN_00674540 @ 0x00674540 ====

void FUN_00674540(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d8acc;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00674580 @ 0x00674580 ====

undefined4 FUN_00674580(void)

{
  return 0x70130004;
}


// ==== FUN_00674590 @ 0x00674590 ====

void FUN_00674590(void)

{
  return;
}


// ==== FUN_006745a0 @ 0x006745a0 ====

undefined1 FUN_006745a0(void)

{
  return 0;
}


// ==== FUN_006745b0 @ 0x006745b0 ====

void FUN_006745b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d8bac;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006745d0 @ 0x006745d0 ====

undefined4 FUN_006745d0(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_yes_009d8b88,7);
  if (iVar1 == 0) {
    (**(code **)(*DAT_00b5ae9c + 8))();
  }
  puVar2 = operator_new(4);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar2 = &PTR_FUN_009d8b98;
  FUN_00797a20(puVar2);
  return 1;
}


// ==== FUN_00674640 @ 0x00674640 ====

void FUN_00674640(void)

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
  FUN_00401740(s_UI_Game2_MsgBox_ui_Statreset_txt_009d8b38,0x20);
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


// ==== FUN_006746c0 @ 0x006746c0 ====

void FUN_006746c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d8bac;
  FUN_00674640();
  return;
}


// ==== FUN_006746e0 @ 0x006746e0 ====

void FUN_006746e0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  undefined4 unaff_ESI;
  int unaff_retaddr;
  undefined4 uStack_a0;
  void *_Memory;
  undefined1 auStack_82 [6];
  undefined4 local_7c;
  void *local_78;
  uint uStack_74;
  void *local_70;
  undefined1 local_6c;
  uint uStack_64;
  undefined4 uStack_60;
  void *local_5c;
  undefined4 local_58;
  undefined1 auStack_54 [4];
  undefined1 local_50;
  undefined4 uStack_4c;
  uint uStack_48;
  undefined1 auStack_44 [4];
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_34;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_18;
  int iStack_14;
  undefined4 local_8;
  undefined4 local_4;
  
  local_7c = 0;
  local_78 = (void *)0x0;
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  local_3c = 0xf;
  local_40 = 0;
  local_50 = 0;
  local_58 = 0xf;
  local_5c = (void *)0x0;
  local_6c = 0;
  uStack_a0 = 0x674748;
  FUN_00401740();
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (0xf < local_5c) {
    uStack_a0 = 0x67476c;
    _free(local_70);
    return;
  }
  local_5c = (void *)0xf;
  uStack_60 = 0;
  local_70 = (void *)((uint)local_70 & 0xffffff00);
  local_78 = (void *)(**(code **)(*piVar1 + 0x30))();
  if (unaff_retaddr == 0) {
    _Memory = (void *)0x3c0023;
    uStack_a0 = 0;
    uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660(uVar2,0,0xffffffff);
    FUN_004020e0(&DAT_009d8b64,1);
    FUN_00401740(s_<VALUE>_009d8b68,7);
    FUN_00401740(&DAT_009d8b70,2);
    uVar2 = FUN_00404230(&local_7c);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < uStack_64) {
      _free(local_78);
      return;
    }
    FUN_004e6c20(auStack_44);
    uVar2 = (**(code **)(*DAT_00b5a794 + 8))(&local_7c,0,0x3c0026,auStack_82 + -0xe);
    FUN_00401ff0(uVar2,0,0xffffffff);
    if (0xf < uStack_74) {
      _free(unaff_EBX);
      return;
    }
    FUN_004020e0(&DAT_009d8b74,1);
    if (_Memory != (void *)0x0) {
      FUN_004e65b0(_Memory,&local_70,&uStack_a0,unaff_ESI);
      _free(_Memory);
      return;
    }
    if (iStack_14 != 0) {
      FUN_00401740(s_<DIL>_009d8b78,5);
      FUN_00401740(&DAT_009d8b80,2);
      uVar2 = FUN_00404230(auStack_82 + -10);
      FUN_00401660(uVar2,0,0xffffffff);
      if (0xf < uStack_74) {
        _free(unaff_EBX);
        return;
      }
      FUN_004e6c20(auStack_54);
      uVar2 = (**(code **)(*DAT_00b5a794 + 8))(auStack_82 + -10,0,0x3c0027,&uStack_a0);
      FUN_00401ff0(uVar2,0,0xffffffff);
      if (0xf < uStack_74) {
        _free(unaff_EBX);
        return;
      }
      FUN_004e67a0();
    }
    FUN_004020e0(&DAT_009d8b84,1);
    uVar2 = (**(code **)(*DAT_00b5a794 + 8))(auStack_82 + -10,0,0x3c0028,&uStack_a0);
    FUN_00401ff0(uVar2,0,0xffffffff);
    if (0xf < uStack_64) {
      _free(local_78);
      return;
    }
    FUN_005569f0(&uStack_60,1);
  }
  else {
    uStack_a0 = 0;
    uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660(uVar2,0,0xffffffff);
    FUN_005569f0(&uStack_60,1);
  }
  if (0xf < uStack_48) {
    _free(local_5c);
    return;
  }
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  uStack_4c = 0;
  uStack_48 = 0xf;
  FUN_0040a7d0();
  if (unaff_EBP == (void *)0x0) {
    return;
  }
  FUN_004e65b0(unaff_EBP,unaff_EBX,auStack_82 + -0xe,0);
  _free(unaff_EBP);
  return;
}


// ==== FUN_00674a70 @ 0x00674a70 ====

undefined4 FUN_00674a70(void)

{
  return 0x3a;
}


// ==== FUN_00674a80 @ 0x00674a80 ====

void FUN_00674a80(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d8bac;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00674ac0 @ 0x00674ac0 ====

void FUN_00674ac0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x00674acc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_00674ad0 @ 0x00674ad0 ====

undefined4 FUN_00674ad0(void)

{
  (**(code **)(*DAT_00b5ae20 + 0xc))();
  return 1;
}


// ==== FUN_00674ae0 @ 0x00674ae0 ====

void FUN_00674ae0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 unaff_retaddr;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(), iVar2 != 0)) {
    FUN_00558fd0(param_2);
    FUN_0055a260(unaff_retaddr);
  }
  return;
}


// ==== FUN_00674b20 @ 0x00674b20 ====

void FUN_00674b20(undefined4 param_1)

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
      uStack_10 = *(undefined4 *)(iVar2 + 0x8c);
      uStack_c = *(undefined4 *)(iVar2 + 0x90);
      uStack_8 = param_1;
      FUN_00587d40(&uStack_10);
    }
  }
  return;
}


// ==== FUN_00674ba0 @ 0x00674ba0 ====

undefined4 FUN_00674ba0(int param_1)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = (**(code **)(*DAT_00b5a6b0 + 8))();
  if (iVar4 == 1) {
    return 0;
  }
  if ((iVar4 == 2) || (iVar4 == 4)) {
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      iVar4 = param_1 + 4;
    }
    else {
      iVar4 = *(int *)(param_1 + 4);
    }
    iVar5 = 0;
    if (0 < *(int *)(param_1 + 0x14)) {
      do {
        cVar3 = *(char *)(iVar5 + iVar4);
        if ((((cVar3 == '\t') || (cVar3 == '\r')) || (cVar3 == ' ')) ||
           ((cVar3 == '\n' || ((cVar3 == -0x7f && (*(char *)(iVar5 + 1 + iVar4) == '@')))))) {
          return 0xfa;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(param_1 + 0x14));
    }
    return 0;
  }
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    iVar4 = param_1 + 4;
  }
  else {
    iVar4 = *(int *)(param_1 + 4);
  }
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0x14)) {
    do {
      bVar1 = *(byte *)(iVar5 + iVar4);
      if (((bVar1 < 0xb0) || (200 < bVar1)) ||
         ((bVar2 = *(byte *)(iVar5 + 1 + iVar4), bVar2 < 0xa1 || (bVar2 == 0xff)))) {
        if ((((0xc9 < bVar1) && (bVar1 < 0xfe)) &&
            (bVar2 = *(byte *)(iVar5 + 1 + iVar4), 0xa0 < bVar2)) && (bVar2 != 0xff)) {
          return 0xf0;
        }
        if (((bVar1 < 0x41) || (0x5a < bVar1)) &&
           (((bVar1 < 0x61 || (0x7a < bVar1)) && ((bVar1 < 0x30 || (0x39 < bVar1)))))) {
          bVar1 = *(byte *)(iVar5 + iVar4);
          if ((0xa0 < bVar1) && (0xa0 < *(byte *)(iVar5 + 1 + iVar4))) {
            return 0xf0;
          }
          if ((((bVar1 == 9) || (bVar1 == 0xd)) || (bVar1 == 0x20)) || (bVar1 == 10)) {
            return 0xfa;
          }
          return 0xf0;
        }
      }
      else {
        iVar5 = iVar5 + 1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(param_1 + 0x14));
  }
  return 0;
}


// ==== FUN_00674cc0 @ 0x00674cc0 ====

void FUN_00674cc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d8f40;
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


// ==== FUN_00674d10 @ 0x00674d10 ====

void FUN_00674d10(void)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  undefined1 auStack_44 [4];
  void *local_40;
  undefined1 local_3c;
  undefined4 uStack_30;
  uint local_2c;
  uint local_28;
  uint uStack_24;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  local_28 = 0xf;
  local_2c = 0;
  local_3c = 0;
  FUN_00401740(s_com_server_009d8c88,10);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_40);
  if (0xf < local_2c) {
    _free(local_40);
    return;
  }
  local_2c = 0xf;
  uStack_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_00578750(1);
    uVar3 = (**(code **)(*DAT_00b5ac80 + 0x18))();
    uVar7 = 0;
    if (uVar3 != 0) {
      do {
        iVar4 = (**(code **)(*DAT_00b5ac80 + 8))(uVar7);
        if (iVar4 != 0) {
          local_2c = 0xf;
          uStack_30 = 0;
          local_40 = (void *)((uint)local_40 & 0xffffff00);
          pcVar5 = (char *)(iVar4 + 1);
          do {
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          FUN_00401740((char *)(iVar4 + 1),(int)pcVar5 - (iVar4 + 2));
          iVar6 = (**(code **)(*DAT_00b5ac1c + 8))();
          if (*(char *)(iVar6 + 5) != *(char *)(iVar4 + 0x101)) {
            uStack_8 = 0xf;
            uStack_c = 0;
            pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
            local_28 = uVar7;
            uStack_24 = uVar7;
            FUN_00401660(auStack_44,0,0xffffffff);
            FUN_00577d70(&local_28,0);
            if (0xf < uStack_8) {
              _free(pvStack_1c);
              return;
            }
            uStack_8 = 0xf;
            uStack_c = 0;
            pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
          }
          if (0xf < local_2c) {
            _free(local_40);
            return;
          }
          local_2c = 0xf;
          uStack_30 = 0;
          local_40 = (void *)((uint)local_40 & 0xffffff00);
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar3);
    }
    FUN_00578700();
    FUN_00577df0(uVar7);
  }
  return;
}


// ==== FUN_00674eb0 @ 0x00674eb0 ====

int FUN_00674eb0(void)

{
  uint uVar1;
  int *piVar2;
  int extraout_EAX;
  int extraout_EAX_00;
  int iVar3;
  int in_ECX;
  undefined4 local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_edt_charname_009d8ccc,0xc);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return extraout_EAX;
  }
  local_8 = 0xf;
  uStack_c = 0;
  uVar1 = (uint)local_1c >> 8;
  local_1c = (void *)(uVar1 << 8);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    iVar3 = FUN_00550150();
    return iVar3;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)(uVar1 << 8);
  FUN_00401740(&DAT_009d8cd9,0);
  if (local_8 < 0x10) {
    return (int)register0x00000010 + -0x20;
  }
  _free(local_1c);
  return extraout_EAX_00;
}


// ==== FUN_00674f70 @ 0x00674f70 ====

void FUN_00674f70(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 uVar4;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_textbox_notice_009d8cdc,0xe);
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
      uVar4 = 0;
      uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1130002,0);
      FUN_005569f0(uVar3,uVar4);
    }
  }
  return;
}


// ==== FUN_00675000 @ 0x00675000 ====

uint FUN_00675000(undefined4 param_1,byte *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  uint uVar6;
  uint uVar7;
  byte ****ppppbVar8;
  byte *pbVar9;
  bool bVar10;
  bool bVar11;
  uint in_stack_00000018;
  uint in_stack_0000001c;
  byte ****appppbStack_18 [4];
  uint uStack_8;
  uint uStack_4;
  
  uVar2 = (**(code **)(*DAT_00b5ac80 + 0x18))();
  uVar7 = 0;
  uVar5 = 0;
  if (uVar2 != 0) {
    do {
      iVar3 = (**(code **)(*DAT_00b5ac80 + 8))(uVar7);
      uStack_4 = 0xf;
      uStack_8 = 0;
      appppbStack_18[0] = (byte ****)((uint)appppbStack_18[0] & 0xffffff00);
      pcVar4 = (char *)(iVar3 + 1);
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      uVar5 = FUN_00401740((char *)(iVar3 + 1),(int)pcVar4 - (iVar3 + 2));
      pbVar9 = param_2;
      if (in_stack_0000001c < 0x10) {
        pbVar9 = (byte *)&param_2;
      }
      if (uStack_8 == 0) {
LAB_006750a9:
        if ((in_stack_00000018 <= uStack_8) &&
           (uVar5 = (uint)(uStack_8 != in_stack_00000018), uVar5 == 0)) {
          if (0xf < uStack_4) {
            _free(appppbStack_18[0]);
            return extraout_EAX_01;
          }
          uStack_4 = 0xf;
          uStack_8 = 0;
          appppbStack_18[0] = (byte ****)((uint)appppbStack_18[0]._1_3_ << 8);
          if (in_stack_0000001c < 0x10) {
            return (uint)*(byte *)(iVar3 + 0x101);
          }
          _free(param_2);
          return extraout_EAX_02;
        }
      }
      else {
        uVar6 = in_stack_00000018;
        if (uStack_8 < in_stack_00000018) {
          uVar6 = uStack_8;
        }
        ppppbVar8 = appppbStack_18[0];
        if (uStack_4 < 0x10) {
          ppppbVar8 = (byte ****)appppbStack_18;
        }
        bVar10 = false;
        uVar5 = 0;
        bVar11 = true;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          bVar10 = *(byte *)ppppbVar8 < *pbVar9;
          bVar11 = *(byte *)ppppbVar8 == *pbVar9;
          ppppbVar8 = (byte ****)((int)ppppbVar8 + 1);
          pbVar9 = pbVar9 + 1;
        } while (bVar11);
        if (!bVar11) {
          uVar5 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        }
        if (uVar5 == 0) goto LAB_006750a9;
      }
      if (0xf < uStack_4) {
        _free(appppbStack_18[0]);
        return extraout_EAX;
      }
      uVar7 = uVar7 + 1;
      uStack_4 = 0xf;
      uStack_8 = 0;
      appppbStack_18[0] = (byte ****)((uint)appppbStack_18[0]._1_3_ << 8);
    } while (uVar7 < uVar2);
  }
  if (in_stack_0000001c < 0x10) {
    return uVar5 & 0xffffff00;
  }
  _free(param_2);
  return extraout_EAX_00;
}


// ==== FUN_00675170 @ 0x00675170 ====

void FUN_00675170(void)

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
  FUN_00401740(s_btn_apply_009d8e7c,9);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x30))();
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x28))(*(undefined1 *)(in_ECX + 0x25));
    }
  }
  return;
}


// ==== FUN_006751f0 @ 0x006751f0 ====

void FUN_006751f0(void)

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
  FUN_00401740(s_edt_charname_009d8e88,0xc);
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
    FUN_005514b0();
  }
  return;
}


// ==== FUN_00675270 @ 0x00675270 ====

uint FUN_00675270(void)

{
  byte bVar1;
  uint extraout_EAX;
  int *piVar2;
  int iVar3;
  uint extraout_EAX_00;
  undefined4 uVar4;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  uint extraout_EAX_03;
  uint extraout_EAX_04;
  uint uVar5;
  uint extraout_EAX_05;
  uint extraout_EAX_06;
  uint extraout_EAX_07;
  uint extraout_EAX_08;
  uint extraout_EAX_09;
  uint extraout_EAX_10;
  uint extraout_EAX_11;
  uint extraout_EAX_12;
  int in_ECX;
  int unaff_ESI;
  uint unaff_EDI;
  uint *puStack_9c;
  void *in_stack_ffffff68;
  uint uStack_84;
  void *apvStack_7c [3];
  uint local_70;
  void *local_6c;
  void *pvStack_58;
  uint uStack_4c;
  uint uStack_48;
  void *pvStack_44;
  void *pvStack_40;
  undefined1 auStack_3c [8];
  undefined4 uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  void *pvStack_24;
  undefined1 auStack_1c [12];
  uint uStack_10;
  
  piVar2 = DAT_00b5ae18;
  local_6c = (void *)0xf;
  local_70 = 0;
  FUN_00401660();
  (**(code **)*piVar2)();
  local_70 = local_70 & 0xffffff00;
  FUN_00401740();
  piVar2 = DAT_00b5ae18;
  if (pvStack_44 == (void *)0x0) {
    FUN_00401660(auStack_1c,0,0xffffffff);
    uVar4 = (**(code **)(*piVar2 + 4))(auStack_3c);
    FUN_00401660(uVar4,0,0xffffffff);
    if ((void *)0xf < pvStack_44) {
      _free(pvStack_58);
      return extraout_EAX_01;
    }
    if (unaff_ESI == 0) {
      if (3 < uStack_28) {
        bVar1 = FUN_00674ba0(auStack_3c);
        if (bVar1 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(0,bVar1 | 0x1130000);
        FUN_00401660(uVar4,0,0xffffffff);
        FUN_00401830(s_lbl_charname_error_009d8f04);
        FUN_00674ae0(apvStack_7c + 6,&puStack_9c,1);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x11300f0);
      FUN_00401660(uVar4,0,0xffffffff);
      FUN_00401830(s_lbl_charname_error_009d8ee0);
      FUN_00674ae0(apvStack_7c + 6,&puStack_9c,1);
      if (0xf < uStack_4c) {
        _free((void *)0x0);
        return extraout_EAX_08;
      }
      FUN_00401830(s_pan_charconfirm_009d8ef4);
      FUN_00674b20(apvStack_7c + 6,3);
      if (0xf < uStack_4c) {
        _free((void *)0x0);
        return extraout_EAX_09;
      }
      uVar5 = FUN_006751f0();
      if (0xf < uStack_84) {
        _free(in_stack_ffffff68);
        return extraout_EAX_10;
      }
      if (0xf < unaff_EDI) {
        _free(apvStack_7c[0]);
        return extraout_EAX_11;
      }
      local_6c = (void *)0x0;
      apvStack_7c[0] = (void *)((uint)apvStack_7c[0] & 0xffffff00);
      if (0xf < uStack_2c) {
        _free(pvStack_40);
        return extraout_EAX_12;
      }
      goto LAB_0067568a;
    }
    uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x113014a);
    FUN_00401660(uVar4,0,0xffffffff);
    FUN_00401660(&puStack_9c,0,0xffffffff);
    uVar4 = FUN_00404230(apvStack_7c + 6);
    FUN_00401660(uVar4,0,0xffffffff);
    if (0xf < uStack_4c) {
      _free((void *)0x0);
      return extraout_EAX_02;
    }
    uStack_4c = 0xf;
    FUN_00401740(s_lbl_charname_error_009d8ebc,0x12);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_7c + 6);
    if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x30))(), iVar3 != 0)) {
      puStack_9c = (uint *)0x6754d8;
      FUN_00558fd0();
      puStack_9c = (uint *)0x6754e6;
      FUN_0055a260();
    }
    if (0xf < uStack_30) {
      puStack_9c = (uint *)0x6754f6;
      _free(pvStack_44);
      return extraout_EAX_03;
    }
    puStack_9c = (uint *)s_pan_charconfirm_009d8ed0;
  }
  else {
    puStack_9c = (uint *)(**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    puStack_9c = (uint *)0x0;
    FUN_00401660(apvStack_7c,0,0xffffffff);
    puStack_9c = (uint *)FUN_00404230(&pvStack_44);
    FUN_00401660();
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return extraout_EAX;
    }
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    puStack_9c = (uint *)0x67536a;
    FUN_00401740();
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x30))(), iVar3 != 0)) {
      puStack_9c = (uint *)0x675393;
      FUN_00558fd0();
      puStack_9c = (uint *)0x6753a1;
      FUN_0055a260();
    }
    if (0xf < uStack_30) {
      puStack_9c = (uint *)0x6753b1;
      _free(pvStack_44);
      return extraout_EAX_00;
    }
    puStack_9c = (uint *)s_pan_charconfirm_009d8eac;
  }
  pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
  uStack_34 = 0;
  uStack_30 = 0xf;
  FUN_00401740();
  puStack_9c = &uStack_48;
  FUN_00674b20();
  if (0xf < uStack_30) {
    puStack_9c = (uint *)0x675532;
    _free(pvStack_44);
    return extraout_EAX_04;
  }
  uVar5 = FUN_006751f0();
  if (0xf < unaff_EDI) {
    puStack_9c = (uint *)0x67554c;
    _free(apvStack_7c[0]);
    return extraout_EAX_05;
  }
  local_6c = (void *)0x0;
  apvStack_7c[0] = (void *)((uint)apvStack_7c[0] & 0xffffff00);
  if (0xf < uStack_4c) {
    puStack_9c = (uint *)0x67556b;
    _free((void *)0x0);
    return extraout_EAX_06;
  }
  if (0xf < uStack_10) {
    puStack_9c = (uint *)0x675591;
    _free(pvStack_24);
    return extraout_EAX_07;
  }
LAB_0067568a:
  return uVar5 & 0xffffff00;
}


// ==== FUN_00675770 @ 0x00675770 ====

void FUN_00675770(void)

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
  FUN_00401740(s_edt_charname_009d8f28,0xc);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
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
  return;
}


// ==== FUN_00675810 @ 0x00675810 ====

undefined4 FUN_00675810(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 extraout_EAX;
  int *in_ECX;
  void *unaff_EBX;
  undefined1 auStack_1c [4];
  undefined1 uStack_18;
  uint uStack_10;
  int iStack_8;
  undefined4 uStack_4;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  if (param_1 != iVar1) {
    return 0;
  }
  if (param_3 == 1) {
    uVar2 = FUN_00674eb0();
    uStack_4 = 0xf;
    iStack_8 = 0;
    uStack_18 = 0;
    FUN_00401660(uVar2,0,0xffffffff);
    if (iStack_8 == 0) {
      FUN_00401660(in_ECX + 2,0,0xffffffff);
    }
    iVar1 = *DAT_00b5ae20;
    iVar3 = (**(code **)(*DAT_00b5ac1c + 8))((char)in_ECX[9]);
    (**(code **)(iVar1 + 0x1c))(auStack_1c,*(undefined1 *)(iVar3 + 5));
    (**(code **)(*in_ECX + 0x10))();
    if (0xf < uStack_10) {
      _free(unaff_EBX);
      return extraout_EAX;
    }
  }
  else if (param_3 == 0) {
    FUN_006751f0();
  }
  return 1;
}


// ==== FUN_006758e0 @ 0x006758e0 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_006758e0(void)

{
  char cVar1;
  undefined2 uVar2;
  void *pvVar3;
  int *piVar4;
  char *pcVar5;
  int *piVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  char *pcVar10;
  void *unaff_EBX;
  undefined4 *puVar11;
  undefined1 auStack_1098 [4];
  void *pvStack_1090;
  undefined4 uStack_108c;
  uint local_1088;
  uint uStack_1080;
  uint uStack_107c;
  void *pvStack_1078;
  undefined4 auStack_1074 [3];
  undefined4 uStack_1068;
  uint uStack_1064;
  undefined1 auStack_1060 [4];
  void *pvStack_105c;
  undefined4 uStack_1054;
  undefined4 uStack_1050;
  uint uStack_104c;
  uint uStack_1048;
  void *pvStack_1040;
  undefined4 uStack_103c;
  undefined4 uStack_1038;
  undefined4 uStack_1030;
  uint uStack_102c;
  void *pvStack_1024;
  uint local_1010;
  undefined4 local_1000;
  undefined4 local_ffc;
  undefined4 uStack_c;
  
  uStack_c = 0x6758f0;
  local_ffc = 0xf;
  local_1000 = 0;
  local_1010 = local_1010 & 0xffffff00;
  FUN_00401740(&DAT_009d8c93,0);
  piVar4 = (int *)(**(code **)(*DAT_00b5ae20 + 0x38))();
  pcVar5 = (char *)(**(code **)(*piVar4 + 0x70))();
  uStack_1050 = 0xf;
  uStack_1054 = 0;
  uStack_1064 = uStack_1064 & 0xffffff00;
  pcVar10 = pcVar5;
  do {
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar5,(int)pcVar10 - (int)(pcVar5 + 1));
  FUN_00401660(&uStack_1068,0,0xffffffff);
  if ((int *)piVar4[0x12] == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)(**(code **)(*(int *)piVar4[0x12] + 0x28))();
  }
  (**(code **)(*piVar6 + 8))();
  if ((int *)piVar4[1] == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)(**(code **)(*(int *)piVar4[1] + 0x18))();
  }
  puVar7 = (undefined1 *)(**(code **)(*piVar6 + 8))();
  uStack_108c = (void *)CONCAT13(*puVar7,(undefined3)uStack_108c);
  iVar8 = (**(code **)(*piVar4 + 0x74))();
  uVar2 = *(undefined2 *)(iVar8 + 0x30);
  FUN_00401740(s_LV__d_009d8c94,6);
  FUN_00404230(&uStack_1030);
  piVar4 = (int *)(**(code **)(*DAT_00b5abac + 0x10))((uint)uStack_108c >> 0x18);
  if (piVar4 != (int *)0x0) {
    iVar8 = (**(code **)(*piVar4 + 4))();
    pcVar10 = (char *)(iVar8 + 0x20);
    do {
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    FUN_004020e0((char *)(iVar8 + 0x20),(int)pcVar10 - (iVar8 + 0x21));
  }
  uStack_1038 = 0xf;
  uStack_103c = 0;
  uStack_104c = uStack_104c & 0xffffff00;
  FUN_00401740(&DAT_009d8c9b,0);
  piVar4 = (int *)(**(code **)(*DAT_00b5ab14 + 8))
                            (CONCAT22((short)((uint)(pcVar5 + 1) >> 0x10),uVar2));
  if (piVar4 != (int *)0x0) {
    puVar9 = (undefined4 *)(**(code **)(*piVar4 + 0x10))();
    pcVar10 = (char *)((int)&local_1000 + 2);
    puVar11 = &local_1000;
    for (iVar8 = 0x3fb; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar11 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
    }
    do {
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    FUN_00401740((int)&local_1000 + 2,(int)pcVar10 - ((int)&local_1000 + 3));
  }
  auStack_1074[0] = 0xf;
  pvStack_1078 = (void *)0x0;
  local_1088 = local_1088 & 0xffffff00;
  FUN_00401740(s_lbl_char_name_009d8c9c,0xd);
  pvVar3 = pvStack_1090;
  piVar4 = (int *)(**(code **)(**(int **)((int)pvStack_1090 + 4) + 0x34))(&uStack_108c);
  if ((piVar4 != (int *)0x0) && (iVar8 = (**(code **)(*piVar4 + 0x30))(), iVar8 != 0)) {
    FUN_00558fd0(1);
    FUN_0055a260(auStack_1074);
  }
  if (0xf < pvStack_1078) {
    _free(uStack_108c);
    return;
  }
  pvStack_1078 = (void *)0xf;
  uStack_107c = 0;
  uStack_108c = (void *)((uint)uStack_108c & 0xffffff00);
  FUN_00401740(s_lbl_char_desc_009d8cac,0xd);
  piVar4 = (int *)(**(code **)(**(int **)((int)pvVar3 + 4) + 0x34))(&pvStack_1090);
  if ((piVar4 != (int *)0x0) && (iVar8 = (**(code **)(*piVar4 + 0x30))(), iVar8 != 0)) {
    FUN_00558fd0(1);
    FUN_0055a260(&pvStack_1040);
  }
  if (0xf < uStack_107c) {
    _free(pvStack_1090);
    return;
  }
  uStack_107c = 0xf;
  uStack_1080 = 0;
  pvStack_1090 = (void *)((uint)pvStack_1090 & 0xffffff00);
  FUN_00401740(s_lbl_char_map_009d8cbc,0xc);
  piVar4 = (int *)(**(code **)(**(int **)((int)pvVar3 + 4) + 0x34))(auStack_1098 + 4);
  if ((piVar4 != (int *)0x0) && (iVar8 = (**(code **)(*piVar4 + 0x30))(), iVar8 != 0)) {
    FUN_00558fd0(1);
    FUN_0055a260(auStack_1060);
  }
  if (0xf < uStack_1080) {
    _free(unaff_EBX);
    return;
  }
  if (0xf < uStack_1048) {
    _free(pvStack_105c);
    return;
  }
  uStack_1048 = 0xf;
  uStack_104c = 0;
  pvStack_105c = (void *)((uint)pvStack_105c & 0xffffff00);
  if (0xf < uStack_102c) {
    _free(pvStack_1040);
    return;
  }
  uStack_102c = 0xf;
  uStack_1030 = 0;
  pvStack_1040 = (void *)((uint)pvStack_1040 & 0xffffff00);
  if (0xf < uStack_1064) {
    _free(pvStack_1078);
    return;
  }
  uStack_1064 = 0xf;
  uStack_1068 = 0;
  pvStack_1078 = (void *)((uint)pvStack_1078 & 0xffffff00);
  if (local_1010 < 0x10) {
    return;
  }
  _free(pvStack_1024);
  return;
}


// ==== FUN_00675c60 @ 0x00675c60 ====

void FUN_00675c60(void)

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
  FUN_00401740(s_UI_Game2_ui_ServerTransfer_txt_009d8c18,0x1e);
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
  FUN_00674d10();
  FUN_006758e0();
  FUN_00674f70();
  FUN_00675170();
  if (piVar1 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar1 + 4))();
    *(undefined4 *)(iVar3 + 0x28) = 0;
    (**(code **)(*DAT_00b5a7cc + 0x2c))(piVar1);
  }
  return;
}


// ==== FUN_00675d20 @ 0x00675d20 ====

void FUN_00675d20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d8f40;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[1] = 0;
  *(undefined1 *)((int)in_ECX + 0x25) = 0;
  FUN_00675c60();
  return;
}


// ==== FUN_00675d50 @ 0x00675d50 ====

void FUN_00675d50(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *in_ECX;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  puVar1 = operator_new(0x58);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b5340;
    puVar1[7] = 0xf;
    puVar1[6] = 0;
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
  puVar1[0x14] = uVar2;
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_servertransfer_ui_servertransfer_009d8e50,0x29);
  FUN_00401660(auStack_1c,0,0xffffffff);
  if (uStack_4 < 0x10) {
    *(undefined2 *)(puVar1 + 0x13) = 0x2901;
    FUN_00797a20(puVar1);
    return;
  }
  _free(pvStack_18);
  return;
}


// ==== FUN_00675e10 @ 0x00675e10 ====

/* WARNING: Removing unreachable block (ram,0x00676316) */
/* WARNING: Removing unreachable block (ram,0x0067635e) */
/* WARNING: Removing unreachable block (ram,0x006762c8) */

void FUN_00675e10(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  undefined1 auStack_1da [18];
  undefined1 auStack_1c8 [4];
  undefined1 auStack_1c4 [8];
  undefined1 local_1bc;
  uint uStack_1b8;
  undefined4 local_1ac;
  void *local_1a8;
  undefined1 uStack_1a4;
  undefined4 uStack_198;
  uint uStack_194;
  undefined4 uStack_190;
  void *pvStack_18c;
  undefined4 uStack_17c;
  uint uStack_178;
  void *pvStack_16c;
  undefined1 uStack_168;
  undefined4 uStack_15c;
  uint uStack_158;
  undefined4 uStack_154;
  undefined1 auStack_13c [84];
  undefined1 auStack_e8 [28];
  undefined1 auStack_cc [112];
  undefined1 auStack_5c [36];
  undefined1 auStack_38 [56];
  
  local_1a8 = (void *)0xf;
  local_1ac = 0;
  local_1bc = 0;
  FUN_00401740(&DAT_009d8ceb,0);
  uVar1 = (**(code **)(*DAT_00b5ae20 + 0x2c))();
  switch(uVar1) {
  case 0:
    FUN_00401830(s_pan_serverconfirm_009d8d18);
    FUN_00674b20(auStack_38,2);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 0xfffffffc:
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x113014a);
    FUN_00401660(uVar1,0,0xffffffff);
    FUN_00401830(s_lbl_charname_error_009d8db8);
    FUN_00674ae0(auStack_5c,auStack_1c8,1);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 0xfffffffd:
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1130140);
    FUN_00401660(uVar1,0,0xffffffff);
    FUN_00401830(s_lbl_charname_error_009d8d94);
    FUN_00674ae0(auStack_cc,auStack_1c8,1);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 0xfffffffe:
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1130154);
    FUN_00401660(uVar1,0,0xffffffff);
    FUN_00401830(s_pan_serverconfirm_009d8d68);
    FUN_00674b20(auStack_13c,3);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 0xffffffff:
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x11300dc);
    FUN_00401660(uVar1,0,0xffffffff);
    FUN_00401830(s_lbl_serverselect_fail_009d8cec);
    FUN_00674ae0(auStack_e8,auStack_1c8,1);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  FUN_00401740(&DAT_009d8ddc,0);
  uStack_154 = 0xf;
  uStack_158 = 0;
  uStack_168 = 0;
  FUN_00401740(s_lbl_serverselect_fail_009d8de0,0x15);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_16c);
  if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x30))(), iVar3 != 0)) {
    FUN_00558fd0(0);
    FUN_0055a260(auStack_1c4);
  }
  if (0xf < uStack_158) {
    _free(pvStack_16c);
    return;
  }
  uStack_158 = 0xf;
  uStack_15c = 0;
  pvStack_16c = (void *)((uint)pvStack_16c & 0xffffff00);
  uStack_190 = 0xf;
  uStack_194 = 0;
  uStack_1a4 = 0;
  FUN_00401740(s_lbl_charname_error_009d8df8,0x12);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1a8);
  if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x30))(), iVar3 != 0)) {
    FUN_00558fd0(0);
    FUN_0055a260(auStack_1c8);
  }
  if (0xf < uStack_194) {
    _free(local_1a8);
    return;
  }
  uStack_194 = 0xf;
  uStack_198 = 0;
  local_1a8 = (void *)((uint)local_1a8 & 0xffffff00);
  uStack_178 = 0xf;
  uStack_17c = 0;
  pvStack_18c = (void *)((uint)pvStack_18c & 0xffffff00);
  FUN_00401740(s_pan_charconfirm_009d8e0c,0xf);
  FUN_00674b20(&uStack_190,4);
  if (0xf < uStack_178) {
    _free(pvStack_18c);
    return;
  }
  uStack_178 = 0xf;
  uStack_17c = 0;
  pvStack_18c = (void *)((uint)pvStack_18c & 0xffffff00);
  FUN_00401740(s_pan_charconfirm_009d8e1c,0xf);
  FUN_00674b20(auStack_1da + -10,4);
  FUN_00401740(s_pan_serverconfirm_009d8e2c,0x11);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1da + -10);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x24))(1);
  }
  FUN_00401740(s_pan_charconfirm_009d8e40,0xf);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1da + -0xe);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x24))(1);
  }
  if (uStack_1b8 < 0x10) {
    return;
  }
  _free((void *)0xf);
  return;
}


// ==== FUN_006763a0 @ 0x006763a0 ====

undefined4 FUN_006763a0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70510002) {
    FUN_00675e10();
    return 1;
  }
  return 0;
}


// ==== FUN_006763d0 @ 0x006763d0 ====

undefined4 FUN_006763d0(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int *in_ECX;
  undefined4 in_stack_ffffff9c;
  undefined1 local_38 [2];
  undefined1 auStack_36 [2];
  undefined1 local_34;
  int local_24;
  undefined4 local_20;
  undefined1 local_1c [28];
  
  if (param_1 == 0x15) {
    if (param_3 == 1) {
      iVar3 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_com_server_009d8c38,10);
      if (iVar3 != 0) {
        return 1;
      }
      piVar4 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(param_2);
      if (piVar4 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar4 + 0x30))();
        if (iVar3 != 0) {
          FUN_005778b0(local_38 + -4);
          FUN_00577df0(0);
          FUN_00675770();
          FUN_00765c50(local_38 + -4);
          uVar1 = FUN_00675000(in_stack_ffffff9c);
          *(undefined1 *)(in_ECX + 9) = uVar1;
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        return 1;
      }
    }
  }
  else if (param_1 == 1) {
    if (param_3 == 1) {
      iVar3 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_apply_009d8c44,9);
      if (iVar3 != 0) {
        cVar2 = FUN_004036a0(param_2,s_btn_exit_009d8c60);
        if (cVar2 != '\0') {
          (**(code **)(*in_ECX + 0x10))();
        }
        return 1;
      }
      uVar5 = FUN_00674eb0();
      local_20 = 0xf;
      local_24 = 0;
      local_34 = 0;
      FUN_00401660(uVar5,0,0xffffffff);
      if (local_24 == 0) {
        FUN_00401660(in_ECX + 2,0,0xffffffff);
        FUN_00401830(s_edt_charname_009d8c50);
        (**(code **)(*(int *)in_ECX[1] + 0x34))(local_1c);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      FUN_00765c50(local_38);
      cVar2 = FUN_00675270();
      if (cVar2 != '\0') {
        iVar3 = *DAT_00b5ae20;
        iVar6 = (**(code **)(*DAT_00b5ac1c + 8))((char)in_ECX[9]);
        (**(code **)(iVar3 + 0x18))(local_38,*(undefined1 *)(iVar6 + 5));
        FUN_00675e10();
      }
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  else if ((param_1 == 0) && (param_3 == 1)) {
    cVar2 = FUN_004036a0(param_2,s_pan_agree_009d8c6c);
    if (cVar2 == '\0') {
      return 1;
    }
    *(bool *)((int)in_ECX + 0x25) = *(char *)((int)in_ECX + 0x25) == '\0';
    FUN_00401830(s_pan_agree_check_009d8c78);
    piVar4 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(local_1c);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x24))(param_2);
    }
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  return 0;
}


// ==== FUN_00676640 @ 0x00676640 ====

undefined4 FUN_00676640(void)

{
  return 0x89;
}


// ==== FUN_00676650 @ 0x00676650 ====

void FUN_00676650(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d8f40;
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


// ==== FUN_006766b0 @ 0x006766b0 ====

void FUN_006766b0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x006766bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_006766c0 @ 0x006766c0 ====

undefined1 FUN_006766c0(void)

{
  return 0;
}


// ==== FUN_006766d0 @ 0x006766d0 ====

void FUN_006766d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d90cc;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006766f0 @ 0x006766f0 ====

undefined4 FUN_006766f0(void)

{
  undefined4 local_4;
  
  local_4 = 8;
  (**(code **)(*DAT_00b5ada4 + 8))(&local_4);
  return 1;
}


// ==== FUN_00676740 @ 0x00676740 ====

undefined4 FUN_00676740(int param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar1 = param_2;
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009d8fd0,8);
  if ((iVar3 == 0) || (cVar2 = FUN_004036a0(iVar1,s_btn_ok_009d8fdc), cVar2 != '\0')) {
    param_1 = 8;
    (**(code **)(*DAT_00b5ada4 + 8))(&param_1);
    return 1;
  }
  return 0;
}


// ==== FUN_006767b0 @ 0x006767b0 ====

void FUN_006767b0(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  undefined4 *puVar6;
  undefined4 unaff_EBX;
  int unaff_EBP;
  undefined4 unaff_ESI;
  void **ppvVar7;
  uint uVar8;
  void **ppvVar9;
  uint in_stack_fffffdc8;
  undefined1 auStack_206 [18];
  void *pvStack_1f4;
  uint uStack_1e0;
  void *apvStack_1dc [4];
  undefined4 uStack_1cc;
  uint uStack_1c8;
  void *apvStack_1c0 [4];
  undefined4 uStack_1b0;
  uint uStack_1ac;
  void *apvStack_1a4 [4];
  undefined4 uStack_194;
  uint uStack_190;
  void *apvStack_18c [4];
  undefined4 uStack_17c;
  uint uStack_178;
  void *apvStack_170 [4];
  undefined4 uStack_160;
  uint uStack_15c;
  void *apvStack_158 [4];
  undefined4 uStack_148;
  uint uStack_144;
  void *apvStack_138 [3];
  undefined1 auStack_12c [4];
  undefined4 uStack_128;
  uint uStack_124;
  void *pvStack_114;
  void *pvStack_104;
  uint uStack_100;
  undefined4 uStack_f4;
  uint uStack_f0;
  void *apvStack_e4 [4];
  undefined4 uStack_d4;
  uint uStack_d0;
  void *apvStack_cc [4];
  undefined4 uStack_bc;
  uint uStack_b8;
  void *apvStack_a8 [2];
  undefined1 auStack_a0 [8];
  undefined4 uStack_98;
  uint uStack_94;
  void *pvStack_88;
  void *pvStack_78;
  uint uStack_74;
  undefined4 uStack_68;
  uint uStack_64;
  void *pvStack_50;
  undefined1 auStack_44 [4];
  undefined4 uStack_40;
  uint uStack_3c;
  void *pvStack_34;
  undefined1 auStack_28 [4];
  undefined4 uStack_24;
  uint uStack_20;
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar2 = (**(code **)(*DAT_00b5ada4 + 0x18))();
  if (iVar2 != 0) {
    puVar1 = *(undefined4 **)(iVar2 + 8);
    for (puVar6 = *(undefined4 **)(iVar2 + 4); puVar6 != puVar1; puVar6 = puVar6 + 1) {
      if ((char *)*puVar6 != (char *)0x0) {
        if (*(char *)*puVar6 == '\x01') {
          FUN_00401740(s_<color_FFFF00>_d<_color>_009d8fe4,0x18);
          uVar3 = FUN_00404230(apvStack_1c0);
          FUN_00401740(s_lbl_Rank_d_009d9000,10);
          ppvVar9 = apvStack_a8;
          uVar4 = FUN_00404230(ppvVar9);
          piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar4);
          if (piVar5 != (int *)0x0) {
            (**(code **)(*piVar5 + 0x30))();
            FUN_0055a260(unaff_EBX);
          }
          if (0xf < uStack_94) {
            _free(apvStack_a8[0]);
            return;
          }
          uStack_94 = 0xf;
          uStack_98 = 0;
          apvStack_a8[0] = (void *)((uint)apvStack_a8[0] & 0xffffff00);
          if (0xf < uStack_1ac) {
            _free(apvStack_1c0[0]);
            return;
          }
          uStack_1ac = 0xf;
          uStack_1b0 = 0;
          apvStack_1c0[0] = (void *)((uint)apvStack_1c0[0] & 0xffffff00);
          in_stack_fffffdc8 = in_stack_fffffdc8 & 0xffffff00;
          FUN_00401740(s_<color_FFFF00>_d<_color>_009d900c,0x18);
          unaff_EBX = FUN_00404230(apvStack_18c,ppvVar9,in_stack_fffffdc8);
          in_stack_fffffdc8 = in_stack_fffffdc8 & 0xffffff00;
          FUN_00401740(s_lbl_Point_d_009d9028,0xb);
          ppvVar7 = apvStack_e4;
          uVar4 = FUN_00404230(ppvVar7,ppvVar9,in_stack_fffffdc8);
          piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar4);
          if (piVar5 != (int *)0x0) {
            (**(code **)(*piVar5 + 0x30))();
            FUN_0055a260(unaff_EBP);
          }
          if (0xf < uStack_d0) {
            _free(apvStack_e4[0]);
            return;
          }
          uStack_d0 = 0xf;
          uStack_d4 = 0;
          apvStack_e4[0] = (void *)((uint)apvStack_e4[0] & 0xffffff00);
          if (0xf < uStack_178) {
            _free(apvStack_18c[0]);
            return;
          }
          uStack_178 = 0xf;
          uStack_17c = 0;
          apvStack_18c[0] = (void *)((uint)apvStack_18c[0] & 0xffffff00);
          uVar8 = (uint)ppvVar9 & 0xffffff00;
          FUN_00401740(s_<color_FFFF00>_d<_color>_009d9034,0x18);
          unaff_EBP = FUN_00404230(apvStack_158,ppvVar7,uVar8);
          uVar8 = uVar8 & 0xffffff00;
          FUN_00401740(s_lbl_Exp_d_009d9050,9);
          uVar4 = FUN_00404230(&pvStack_78,ppvVar7,uVar8);
          piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar4);
          if (piVar5 != (int *)0x0) {
            (**(code **)(*piVar5 + 0x30))();
            FUN_0055a260(unaff_ESI);
          }
          if (0xf < uStack_64) {
            _free(pvStack_78);
            return;
          }
          uStack_64 = 0xf;
          uStack_68 = 0;
          pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
          if (0xf < uStack_144) {
            _free(apvStack_158[0]);
            return;
          }
          uStack_144 = 0xf;
          uStack_148 = 0;
          apvStack_158[0] = (void *)((uint)apvStack_158[0] & 0xffffff00);
          (**(code **)(*DAT_00b5ada4 + 0x20))(auStack_44,*(undefined1 *)(unaff_EBP + 1));
          FUN_00401740(s_<color_FFFF00>_s<_color>_009d905c,0x18);
          FUN_00404230(auStack_12c);
          in_stack_fffffdc8 = 0;
          FUN_00401740(s_lbl_Party_d_009d9078,0xb);
          uVar4 = FUN_00404230(auStack_206 + -6);
          piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar4);
          if (piVar5 != (int *)0x0) {
            (**(code **)(*piVar5 + 0x30))();
            FUN_0055a260(uVar3);
          }
          if (0xf < uStack_1e0) {
            _free(pvStack_1f4);
            return;
          }
          uStack_1e0 = 0xf;
          pvStack_1f4 = (void *)((uint)pvStack_1f4 & 0xffffff00);
          if (0xf < uStack_100) {
            _free(pvStack_114);
            return;
          }
          uStack_100 = 0xf;
          pvStack_104 = (void *)0x0;
          pvStack_114 = (void *)((uint)pvStack_114 & 0xffffff00);
          if (0xf < uStack_20) {
            _free(pvStack_34);
            return;
          }
          uStack_20 = 0xf;
          uStack_24 = 0;
          pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
        }
        else {
          FUN_00401740(&DAT_009d9084,2);
          uVar3 = FUN_00404230(apvStack_1a4);
          FUN_00401740(s_lbl_Rank_d_009d9088,10);
          ppvVar9 = apvStack_1dc;
          uVar4 = FUN_00404230(ppvVar9);
          piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar4);
          if (piVar5 != (int *)0x0) {
            (**(code **)(*piVar5 + 0x30))();
            FUN_0055a260(unaff_EBX);
          }
          if (0xf < uStack_1c8) {
            _free(apvStack_1dc[0]);
            return;
          }
          uStack_1c8 = 0xf;
          uStack_1cc = 0;
          apvStack_1dc[0] = (void *)((uint)apvStack_1dc[0] & 0xffffff00);
          if (0xf < uStack_190) {
            _free(apvStack_1a4[0]);
            return;
          }
          uStack_190 = 0xf;
          uStack_194 = 0;
          apvStack_1a4[0] = (void *)((uint)apvStack_1a4[0] & 0xffffff00);
          in_stack_fffffdc8 = in_stack_fffffdc8 & 0xffffff00;
          FUN_00401740(&DAT_009d9094,2);
          unaff_EBX = FUN_00404230(apvStack_138,ppvVar9,in_stack_fffffdc8);
          in_stack_fffffdc8 = in_stack_fffffdc8 & 0xffffff00;
          FUN_00401740(s_lbl_Point_d_009d9098,0xb);
          ppvVar7 = apvStack_170;
          uVar4 = FUN_00404230(ppvVar7,ppvVar9,in_stack_fffffdc8);
          piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar4);
          if (piVar5 != (int *)0x0) {
            (**(code **)(*piVar5 + 0x30))();
            FUN_0055a260(unaff_EBP);
          }
          if (0xf < uStack_15c) {
            _free(apvStack_170[0]);
            return;
          }
          uStack_15c = 0xf;
          uStack_160 = 0;
          apvStack_170[0] = (void *)((uint)apvStack_170[0] & 0xffffff00);
          if (0xf < uStack_124) {
            _free(apvStack_138[0]);
            return;
          }
          uStack_124 = 0xf;
          uStack_128 = 0;
          apvStack_138[0] = (void *)((uint)apvStack_138[0] & 0xffffff00);
          uVar8 = (uint)ppvVar9 & 0xffffff00;
          FUN_00401740(&DAT_009d90a4,2);
          unaff_EBP = FUN_00404230(apvStack_cc,ppvVar7,uVar8);
          uVar8 = uVar8 & 0xffffff00;
          FUN_00401740(s_lbl_Exp_d_009d90a8,9);
          uVar4 = FUN_00404230(&pvStack_104,ppvVar7,uVar8);
          piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar4);
          if (piVar5 != (int *)0x0) {
            (**(code **)(*piVar5 + 0x30))();
            FUN_0055a260(unaff_ESI);
          }
          if (0xf < uStack_f0) {
            _free(pvStack_104);
            return;
          }
          uStack_f0 = 0xf;
          uStack_f4 = 0;
          pvStack_104 = (void *)((uint)pvStack_104 & 0xffffff00);
          if (0xf < uStack_b8) {
            _free(apvStack_cc[0]);
            return;
          }
          uStack_b8 = 0xf;
          uStack_bc = 0;
          apvStack_cc[0] = (void *)((uint)apvStack_cc[0] & 0xffffff00);
          (**(code **)(*DAT_00b5ada4 + 0x20))(auStack_28,*(undefined1 *)(unaff_EBP + 1));
          FUN_00401740(&DAT_009d90b4,2);
          FUN_00404230(&uStack_68);
          in_stack_fffffdc8 = 0;
          FUN_00401740(s_lbl_Party_d_009d90b8,0xb);
          uVar4 = FUN_00404230(auStack_a0);
          piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar4);
          if (piVar5 != (int *)0x0) {
            (**(code **)(*piVar5 + 0x30))();
            FUN_0055a260(uVar3);
          }
          if (0xf < uStack_74) {
            _free(pvStack_88);
            return;
          }
          uStack_74 = 0xf;
          pvStack_78 = (void *)0x0;
          pvStack_88 = (void *)((uint)pvStack_88 & 0xffffff00);
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
          uStack_4 = 0xf;
          uStack_8 = 0;
          pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
        }
      }
    }
  }
  return;
}


// ==== FUN_00676fa0 @ 0x00676fa0 ====

void FUN_00676fa0(void)

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
  FUN_00401740(s_UI_Game2_Partywar_ui_resultwnd_t_009d8fac,0x22);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_006767b0();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00677020 @ 0x00677020 ====

void FUN_00677020(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d90cc;
  FUN_00676fa0();
  return;
}


// ==== FUN_00677040 @ 0x00677040 ====

undefined4 FUN_00677040(void)

{
  return 0x6b;
}


// ==== FUN_00677050 @ 0x00677050 ====

void FUN_00677050(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d90cc;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00677090 @ 0x00677090 ====

void FUN_00677090(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0067709c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_006770a0 @ 0x006770a0 ====

undefined1 FUN_006770a0(void)

{
  return 0;
}


// ==== FUN_006770b0 @ 0x006770b0 ====

undefined1 FUN_006770b0(void)

{
  return 0;
}


// ==== FUN_006770c0 @ 0x006770c0 ====

void FUN_006770c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d9188;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00677110 @ 0x00677110 ====

void FUN_00677110(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  void *unaff_EBX;
  void **ppvVar3;
  undefined1 uVar4;
  void *local_38;
  undefined1 local_34 [12];
  uint uStack_28;
  uint local_24;
  void *local_20;
  void *apvStack_1c [3];
  undefined4 uStack_10;
  uint uStack_c;
  uint uStack_8;
  
  local_20 = (void *)0xf;
  local_24 = 0;
  local_34[0] = 0;
  FUN_00401740(s_lbl_point_009d9164,9);
  (**(code **)(*DAT_00b5ada8 + 0x34))();
  FUN_00401740(&DAT_009d9160,2);
  ppvVar3 = apvStack_1c;
  uVar1 = FUN_00404230(ppvVar3);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_8) {
    _free(apvStack_1c[0]);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = 0xf;
  uStack_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  FUN_00401740(s_lbl_rank_009d9174,8);
  (**(code **)(*DAT_00b5ada8 + 0x28))();
  uVar4 = 0;
  FUN_00401740(&DAT_009d9170,2);
  uVar1 = FUN_00404230(&local_20,ppvVar3,uVar4);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_1c + -8);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_0055a260(uVar1);
  }
  if (0xf < uStack_c) {
    _free(local_20);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  if (uStack_28 < 0x10) {
    return;
  }
  _free(unaff_EBX);
  return;
}


// ==== FUN_00677280 @ 0x00677280 ====

void FUN_00677280(void)

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
  FUN_00401740(s_UI_Game2_Partywar_ui_mypartyinfo_009d9138,0x27);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_00677110();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00677300 @ 0x00677300 ====

uint FUN_00677300(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x70490007) {
    uVar1 = FUN_00677110();
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00677320 @ 0x00677320 ====

void FUN_00677320(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d9188;
  FUN_00677280();
  return;
}


// ==== FUN_00677340 @ 0x00677340 ====

undefined4 FUN_00677340(void)

{
  return 0x6a;
}


// ==== __break @ 0x0067734d ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00677350 @ 0x00677350 ====

void FUN_00677350(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d9188;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00677390 @ 0x00677390 ====

void FUN_00677390(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0067739c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_006773a0 @ 0x006773a0 ====

undefined1 FUN_006773a0(void)

{
  return 0;
}


// ==== FUN_006773b0 @ 0x006773b0 ====

undefined1 FUN_006773b0(void)

{
  return 0;
}


// ==== FUN_006773c0 @ 0x006773c0 ====

void FUN_006773c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d929c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006773e0 @ 0x006773e0 ====

void FUN_006773e0(undefined4 param_1)

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


// ==== FUN_00677410 @ 0x00677410 ====

void FUN_00677410(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  void *unaff_EBP;
  undefined1 local_38 [2];
  undefined1 auStack_36 [2];
  void *local_34;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *local_24;
  uint local_20;
  uint uStack_10;
  
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_UI_Game2_Partywar_ui_remainwarti_009d91f4,0x29);
  iVar1 = FUN_00410500(local_38);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  *(undefined4 *)(in_ECX + 8) = 0;
  (**(code **)(*DAT_00b5ada4 + 0x2c))();
  FUN_00401740(&DAT_009d9220,0x19);
  uVar3 = FUN_00404230(auStack_28);
  uVar3 = FUN_004022a0(local_38 + -0xc,s__debug_enter__009d923c,uVar3);
  FUN_00796d50(uVar3);
  if (0xf < uStack_2c) {
    _free(unaff_EBP);
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  if (0xf < uStack_10) {
    _free(local_24);
    return;
  }
  (**(code **)(*DAT_00b5a6ac + 0x20))();
  FUN_00401740(&DAT_009d924c,0x1f);
  uVar3 = FUN_00404230(auStack_28);
  uVar3 = FUN_004022a0(local_38 + -0xc,s__debug_enter__009d926c,uVar3);
  FUN_00796d50(uVar3);
  if (0xf < uStack_2c) {
    _free((void *)((uint)unaff_EBP & 0xffffff00));
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  if (uStack_10 < 0x10) {
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_00677590 @ 0x00677590 ====

void FUN_00677590(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int in_ECX;
  undefined1 auStack_52 [18];
  undefined1 auStack_40 [28];
  undefined1 auStack_24 [36];
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    return;
  }
  uVar1 = *(uint *)(in_ECX + 8);
  if (uVar1 != 0) {
    if (uVar1 < *(uint *)(param_1 + 4)) {
      param_1 = 1;
      (**(code **)(*DAT_00b5ada4 + 8))(&param_1);
      return;
    }
    *(uint *)(in_ECX + 8) = uVar1 - *(uint *)(param_1 + 4);
    return;
  }
  iVar2 = (**(code **)(*DAT_00b5ada4 + 0x2c))();
  if ((iVar2 == 0) && (*(int *)(in_ECX + 0xc) == 3)) {
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(9,0xc80068);
    FUN_00765c50(uVar3);
    FUN_00401830(s_lbl_text_009d927c);
    FUN_006773e0(auStack_52 + -10,auStack_40);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  iVar2 = *(int *)(in_ECX + 0xc);
  if (iVar2 == 1) {
    uVar3 = 0x64000b;
  }
  else if (iVar2 == 2) {
    uVar3 = 0x64000c;
  }
  else {
    if (iVar2 != 3) {
      return;
    }
    uVar3 = 0xc80067;
  }
  uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(9,uVar3);
  FUN_00401660(uVar3,0,0xffffffff);
  FUN_00401830(s_lbl_text_009d9288);
  FUN_00401660(auStack_52 + -10,0,0xffffffff);
  uVar3 = FUN_00404230(auStack_24);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_40);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 0x30))();
    FUN_0055a260(uVar3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00677750 @ 0x00677750 ====

void FUN_00677750(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d929c;
  in_ECX[3] = 0;
  FUN_00677410();
  return;
}


// ==== FUN_00677770 @ 0x00677770 ====

uint FUN_00677770(int *param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_00677590(param_1);
  }
  else if (uVar1 == 0x70490012) {
    *(int *)(in_ECX + 0xc) = param_1[1];
    return 0x70490000;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_006777b0 @ 0x006777b0 ====

undefined4 FUN_006777b0(void)

{
  return 0x69;
}


// ==== FUN_006777c0 @ 0x006777c0 ====

void FUN_006777c0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d929c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00677800 @ 0x00677800 ====

void FUN_00677800(void)

{
  return;
}


// ==== FUN_00677810 @ 0x00677810 ====

undefined1 FUN_00677810(void)

{
  return 0;
}


// ==== FUN_00677820 @ 0x00677820 ====

undefined1 FUN_00677820(void)

{
  return 0;
}


// ==== FUN_00677830 @ 0x00677830 ====

void FUN_00677830(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d9354;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00677880 @ 0x00677880 ====

/* WARNING: Removing unreachable block (ram,0x00677982) */

void FUN_00677880(void)

{
  undefined2 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  char *pcStack_4c;
  void *local_34;
  void *apvStack_30 [3];
  undefined4 local_24;
  uint local_20;
  uint uStack_1c;
  
  pcStack_4c = s_UI_Game2_Partywar_ui_attachproce_009d9308;
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  pcStack_4c = (char *)0x6778b4;
  iVar2 = FUN_00410500();
  if (0xf < local_20) {
    pcStack_4c = (char *)0x6778ca;
    _free(local_34);
    return;
  }
  pcStack_4c = (char *)(iVar2 + 0x3c);
  piVar3 = (int *)(**(code **)(*DAT_00b5a798 + 4))();
  *(int **)(in_ECX + 4) = piVar3;
  (**(code **)(*piVar3 + 0x40))();
  piVar3 = DAT_00b5a794;
  uVar1 = (**(code **)(*DAT_00b5ada8 + 0x40))();
  uVar4 = (**(code **)(*piVar3 + 0xc))(9,0x12c000a,uVar1);
  FUN_00401660(uVar4,0,0xffffffff);
  FUN_00404230(apvStack_30);
  local_34 = (void *)0xf;
  FUN_00401740(s_lbl_name_009d9334,8);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pcStack_4c);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x30))();
    FUN_0055a260(&local_34);
  }
  uVar4 = (**(code **)(*DAT_00b5ada8 + 0x44))();
  *(undefined4 *)(in_ECX + 8) = uVar4;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uStack_1c < 0x10) {
    return;
  }
  _free(apvStack_30[0]);
  return;
}


// ==== FUN_006779c0 @ 0x006779c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006779c0(int param_1)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + *(int *)(param_1 + 4);
  if (*(uint *)(in_ECX + 8) < *(uint *)(in_ECX + 0xc)) {
    param_1 = 0x10;
    (**(code **)(*DAT_00b5ada4 + 8))(&param_1);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_processbar_009d9340,10);
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
      fVar1 = (float)*(int *)(in_ECX + 0xc);
      if (*(int *)(in_ECX + 0xc) < 0) {
        fVar1 = fVar1 + _DAT_0099d104;
      }
      fVar2 = (float)*(int *)(in_ECX + 8);
      if (*(int *)(in_ECX + 8) < 0) {
        fVar2 = fVar2 + _DAT_0099d104;
      }
      FUN_00587ba0((fVar1 / fVar2) * DAT_0099de78);
    }
  }
  return;
}


// ==== FUN_00677aa0 @ 0x00677aa0 ====

void FUN_00677aa0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d9354;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[1] = 0;
  FUN_00677880();
  return;
}


// ==== FUN_00677ac0 @ 0x00677ac0 ====

uint FUN_00677ac0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_006779c0(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00677af0 @ 0x00677af0 ====

undefined4 FUN_00677af0(void)

{
  return 0x68;
}


// ==== FUN_00677b00 @ 0x00677b00 ====

void FUN_00677b00(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d9354;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00677b40 @ 0x00677b40 ====

void FUN_00677b40(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x00677b4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_00677b50 @ 0x00677b50 ====

undefined1 FUN_00677b50(void)

{
  return 0;
}


// ==== FUN_00677b60 @ 0x00677b60 ====

undefined1 FUN_00677b60(void)

{
  return 0;
}


// ==== FUN_00677b70 @ 0x00677b70 ====

void FUN_00677b70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d9448;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00677bc0 @ 0x00677bc0 ====

void FUN_00677bc0(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  void *unaff_EBX;
  uint uStack_58;
  void *apvStack_54 [3];
  uint uStack_48;
  undefined4 uStack_44;
  void *pvStack_40;
  undefined1 uStack_3c;
  uint uStack_2c;
  undefined4 uStack_28;
  void *apvStack_24 [4];
  undefined4 uStack_14;
  uint uStack_10;
  
  iVar1 = (**(code **)(*DAT_00b5ada4 + 0x2c))();
  if (iVar1 == 0) {
    uStack_58 = 2;
    (**(code **)(*DAT_00b5ada4 + 8))(&uStack_58);
    return;
  }
  uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(9,*(int *)(in_ECX + 8) + 3U | 0x12c0000);
  uStack_28 = 0xf;
  uStack_2c = 0;
  uStack_3c = 0;
  FUN_00401660(uVar2,0,0xffffffff);
  uStack_44 = 0xf;
  uStack_48 = 0;
  uStack_58 = uStack_58 & 0xffffff00;
  FUN_00401740(s_lbl_text_009d9434,8);
  FUN_00401660(&pvStack_40,0,0xffffffff);
  uVar2 = FUN_00404230(apvStack_24);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_24 + -0xe);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x30))();
    FUN_0055a260(uVar2);
  }
  if (0xf < uStack_10) {
    _free(apvStack_24[0]);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  apvStack_24[0] = (void *)((uint)apvStack_24[0] & 0xffffff00);
  if (0xf < uStack_48) {
    _free(unaff_EBX);
    return;
  }
  if (uStack_2c < 0x10) {
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_00677d10 @ 0x00677d10 ====

void FUN_00677d10(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  void *unaff_EBP;
  undefined1 local_38 [2];
  undefined1 auStack_36 [2];
  void *local_34;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *local_24;
  uint local_20;
  uint uStack_10;
  
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_UI_Game2_Partywar_ui_limittimewn_009d93c0,0x25);
  iVar1 = FUN_00410500(local_38);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  FUN_00677bc0();
  (**(code **)(*DAT_00b5ada4 + 0x2c))();
  FUN_00401740(&DAT_009d93e8,0x19);
  uVar3 = FUN_00404230(auStack_28);
  uVar3 = FUN_004022a0(local_38 + -0xc,s__debug__009d9404,uVar3);
  FUN_00796d50(uVar3);
  if (0xf < uStack_2c) {
    _free(unaff_EBP);
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  if (0xf < uStack_10) {
    _free(local_24);
    return;
  }
  (**(code **)(*DAT_00b5a6ac + 0x20))();
  FUN_00401740(&DAT_009d940c,0x1f);
  uVar3 = FUN_00404230(auStack_28);
  uVar3 = FUN_004022a0(local_38 + -0xc,s__debug__009d942c,uVar3);
  FUN_00796d50(uVar3);
  if (0xf < uStack_2c) {
    _free((void *)((uint)unaff_EBP & 0xffffff00));
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  if (uStack_10 < 0x10) {
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_00677e90 @ 0x00677e90 ====

uint FUN_00677e90(int *param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 != 0x40001) {
    if (uVar1 != 0x70490002) goto LAB_00677eba;
    *(int *)(in_ECX + 8) = param_1[1];
  }
  uVar1 = FUN_00677bc0();
LAB_00677eba:
  return uVar1 & 0xffffff00;
}


// ==== FUN_00677ed0 @ 0x00677ed0 ====

void FUN_00677ed0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d9448;
  in_ECX[2] = 0;
  FUN_00677d10();
  return;
}


// ==== FUN_00677ef0 @ 0x00677ef0 ====

undefined4 FUN_00677ef0(void)

{
  return 0x67;
}


// ==== FUN_00677f00 @ 0x00677f00 ====

void FUN_00677f00(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d9448;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00677f40 @ 0x00677f40 ====

void FUN_00677f40(void)

{
  return;
}


// ==== FUN_00677f50 @ 0x00677f50 ====

undefined1 FUN_00677f50(void)

{
  return 0;
}


// ==== FUN_00677f60 @ 0x00677f60 ====

void FUN_00677f60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d9554;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00677f80 @ 0x00677f80 ====

undefined4 FUN_00677f80(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar1 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009d94e0,8);
    if (iVar1 == 0) {
      (**(code **)(*DAT_00b5aee4 + 0x20))(1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00677fc0 @ 0x00677fc0 ====

void FUN_00677fc0(void)

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
  FUN_00401740(s_UI_Game2_MsgBox_ui_npcdialog_sel_009d94b4,0x2b);
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


// ==== FUN_00678040 @ 0x00678040 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00678040(void)

{
  code *pcVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  int unaff_retaddr;
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
  FUN_00401740(s_processbar_009d94ec,10);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = 0xf;
  uStack_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  if (piVar4 == (int *)0x0) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_pComposite____NULL_009d94f8,0x12);
    FUN_00406880(&local_20);
    if (uStack_8 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_1c);
    return;
  }
  iVar5 = (**(code **)(*piVar4 + 0x30))();
  if (iVar5 != 0) {
    fVar2 = (float)unaff_retaddr;
    if (unaff_retaddr < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar3 = (float)*(int *)(in_ECX + 8);
    if (*(int *)(in_ECX + 8) < 0) {
      fVar3 = fVar3 + _DAT_0099d104;
    }
    FUN_00587ba0((fVar2 / fVar3) * DAT_0099de78);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  FUN_00401740(s_pBar____NULL_009d950c,0xc);
  FUN_00406880(&local_20);
  if (uStack_8 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_00678170 @ 0x00678170 ====

void FUN_00678170(void)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  undefined4 unaff_retaddr;
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
  FUN_00401740(s_lbl_title_009d951c,9);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = 0xf;
  uStack_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x30))();
    FUN_0055a260(unaff_retaddr);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  FUN_00401740(s_pComposite____NULL_009d9528,0x12);
  FUN_00406880(&local_20);
  if (uStack_8 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_00678230 @ 0x00678230 ====

void FUN_00678230(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d9554;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  FUN_00677fc0();
  return;
}


// ==== FUN_00678250 @ 0x00678250 ====

void FUN_00678250(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  int in_ECX;
  
  uVar6 = param_1 - *(int *)(in_ECX + 0xc);
  if (*(uint *)(in_ECX + 8) < uVar6) {
    if (*(int *)(in_ECX + 0x10) != 0) {
      (**(code **)(*DAT_00b5ac70 + 0x20))(0,*(int *)(in_ECX + 0x10));
    }
                    /* WARNING: Could not recover jumptable at 0x0067828d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_00b5aee4 + 0x20))();
    return;
  }
  iVar1 = *(int *)(in_ECX + 0x14);
  if (iVar1 != 0) {
    if ((*(int *)(iVar1 + 4) != 0) && (4 < (uint)(*(int *)(iVar1 + 8) - *(int *)(iVar1 + 4) >> 2)))
    {
      return;
    }
    iVar2 = *(int *)(iVar1 + 4);
    if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 8) - iVar2 >> 2) < 4)) {
                    /* WARNING: Subroutine does not return */
      FUN_0042f370();
    }
    iVar3 = *(int *)(iVar1 + 4);
    if ((iVar3 == 0) || ((uint)(*(int *)(iVar1 + 8) - iVar3 >> 2) < 3)) {
                    /* WARNING: Subroutine does not return */
      FUN_0042f370();
    }
    iVar4 = *(int *)(iVar1 + 4);
    if ((iVar4 == 0) || ((uint)(*(int *)(iVar1 + 8) - iVar4 >> 2) < 2)) {
                    /* WARNING: Subroutine does not return */
      FUN_0042f370();
    }
    puVar5 = *(undefined4 **)(iVar1 + 4);
    if ((puVar5 == (undefined4 *)0x0) || (*(int *)(iVar1 + 8) - (int)puVar5 >> 2 == 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_0042f370();
    }
    uVar7 = FUN_004dd240(*puVar5,*(undefined4 *)(iVar4 + 4),*(undefined4 *)(iVar3 + 8),
                         *(undefined4 *)(iVar2 + 0xc),0);
    *(undefined4 *)(in_ECX + 0x10) = uVar7;
  }
  FUN_00678040(uVar6);
  return;
}


// ==== FUN_00678350 @ 0x00678350 ====

uint FUN_00678350(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_00678250(param_1[3]);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00678380 @ 0x00678380 ====

void FUN_00678380(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int in_ECX;
  
  FUN_00678170(param_1);
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  *(undefined4 *)(in_ECX + 8) = param_2;
  *(undefined4 *)(in_ECX + 0xc) = uVar1;
  *(undefined4 *)(in_ECX + 0x14) = param_3;
  FUN_00678250(uVar1);
  return;
}


// ==== FUN_006783c0 @ 0x006783c0 ====

undefined4 FUN_006783c0(void)

{
  return 0x8a;
}


// ==== FUN_006783d0 @ 0x006783d0 ====

void FUN_006783d0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d9554;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00678410 @ 0x00678410 ====

void FUN_00678410(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  if (*(char *)(iVar1 + 0xc) == '\x01') {
    iVar1 = **(int **)(in_ECX + 4);
    uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
    (**(code **)(iVar1 + 0x18))(uVar2);
  }
  return;
}


// ==== FUN_00678440 @ 0x00678440 ====

void FUN_00678440(void)

{
  return;
}


// ==== FUN_00678450 @ 0x00678450 ====

undefined1 FUN_00678450(void)

{
  return 0;
}


// ==== FUN_00678460 @ 0x00678460 ====

void FUN_00678460(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d961c;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006784b0 @ 0x006784b0 ====

void FUN_006784b0(int param_1)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  undefined4 unaff_retaddr;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),&DAT_009d9610,1);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0xc))(0);
    return;
  }
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x34))(param_1);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x24))(1);
    (**(code **)(*piVar2 + 0x30))();
    FUN_0055a260(unaff_retaddr);
  }
  return;
}


// ==== FUN_00678510 @ 0x00678510 ====

void FUN_00678510(void)

{
  short sVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined1 auStack_3c [4];
  void *pvStack_38;
  void *pvStack_34;
  undefined4 uStack_28;
  uint uStack_24;
  uint uStack_20;
  void *pvStack_1c;
  void *pvStack_18;
  undefined4 uStack_c;
  uint uStack_8;
  uint uStack_4;
  
  uVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  sVar1 = FUN_00826c30(uVar2);
  if (sVar1 == 0) {
    if (*(char *)(in_ECX + 10) != '\0') {
      *(undefined1 *)(in_ECX + 10) = 0;
      uStack_20 = 0xf;
      uStack_24 = 0;
      pvStack_34 = (void *)((uint)pvStack_34._1_3_ << 8);
      FUN_00401740(s_pan_bg_009d95e0,6);
      auStack_3c[0] = *(undefined1 *)(in_ECX + 10);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_38);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x24))(unaff_EBX);
      }
      if (0xf < uStack_24) {
        _free(pvStack_38);
        return;
      }
    }
  }
  else if (*(char *)(in_ECX + 10) == '\0') {
    *(undefined1 *)(in_ECX + 10) = 1;
    *(short *)(in_ECX + 8) = sVar1;
    uStack_20 = 0xf;
    uStack_24 = 0;
    pvStack_34 = (void *)((uint)pvStack_34._1_3_ << 8);
    FUN_00401740(s_pan_bg_009d95e8,6);
    auStack_3c[0] = *(undefined1 *)(in_ECX + 10);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_38);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(unaff_EBX);
    }
    if (0xf < uStack_24) {
      _free(pvStack_38);
      return;
    }
    uStack_24 = 0xf;
    uStack_28 = 0;
    pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
    FUN_00401740(s_lbl_stock_009d95f4,9);
    FUN_00401740(&DAT_009d95f0,2);
    uVar2 = FUN_00404230(&uStack_20);
    FUN_006784b0(auStack_3c,uVar2);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    if (0xf < uStack_24) {
      _free(pvStack_38);
      return;
    }
  }
  else if (sVar1 != *(short *)(in_ECX + 8)) {
    *(short *)(in_ECX + 8) = sVar1;
    FUN_00401830(s_lbl_stock_009d9604);
    FUN_00401830(&DAT_009d9600);
    uVar2 = FUN_00404230(&pvStack_1c);
    FUN_006784b0(&pvStack_38,uVar2);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    if (0xf < uStack_20) {
      _free(pvStack_34);
      return;
    }
  }
  return;
}


// ==== FUN_00678730 @ 0x00678730 ====

void FUN_00678730(void)

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
  FUN_00401740(s_UI_Game2_ui_stackcountwnd_txt_009d95c0,0x1d);
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


// ==== FUN_006787b0 @ 0x006787b0 ====

undefined4 FUN_006787b0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    FUN_00678510();
  }
  else if (iVar1 == 0x50050002) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
    if (*(char *)(iVar1 + 0xc) == '\x01') {
      iVar1 = **(int **)(in_ECX + 4);
      uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
      (**(code **)(iVar1 + 0x18))(uVar2);
    }
    return 1;
  }
  return 0;
}


// ==== FUN_00678800 @ 0x00678800 ====

void FUN_00678800(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d961c;
  *(undefined2 *)(in_ECX + 2) = 0;
  *(undefined1 *)((int)in_ECX + 10) = 1;
  in_ECX[1] = 0;
  FUN_00678730();
  return;
}


// ==== FUN_00678820 @ 0x00678820 ====

void FUN_00678820(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d961c;
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


// ==== FUN_00678860 @ 0x00678860 ====

void FUN_00678860(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0067886c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_00678870 @ 0x00678870 ====

undefined1 FUN_00678870(void)

{
  return 0;
}


// ==== FUN_00678880 @ 0x00678880 ====

undefined1 FUN_00678880(void)

{
  return 0;
}


// ==== FUN_00678890 @ 0x00678890 ====

void FUN_00678890(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d97e4;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006788b0 @ 0x006788b0 ====

/* WARNING: Removing unreachable block (ram,0x006788fc) */

uint FUN_006788b0(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  uint uVar3;
  int in_ECX;
  undefined1 auStack_1a [26];
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar2 == (int *)0x0) {
    FUN_00401740(s_pComposite____NULL_009d97c8,0x12);
    FUN_00406880(auStack_1a + -6);
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  (**(code **)(*piVar2 + 0x24))((char)param_1 == '\0');
  return (uint)((char)param_1 == '\0');
}


// ==== FUN_00678930 @ 0x00678930 ====

/* WARNING: Removing unreachable block (ram,0x00678aaf) */
/* WARNING: Removing unreachable block (ram,0x00678bad) */

void FUN_00678930(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  uint unaff_ESI;
  undefined4 uStack_50;
  void *pvStack_34;
  uint uStack_30;
  void *pvStack_2c;
  undefined1 auStack_28 [4];
  undefined1 uStack_24;
  uint uStack_20;
  undefined4 local_1c;
  void *local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 local_8;
  uint local_4;
  
  uStack_50 = s_UI_Game2_observer_ui_observer_po_009d9688;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740();
  uStack_50 = (char *)0x678966;
  iVar2 = FUN_00410500();
  if (0xf < local_4) {
    uStack_50 = (char *)0x67897c;
    _free(local_18);
    return;
  }
  uStack_50 = (char *)(iVar2 + 0x3c);
  piVar3 = (int *)(**(code **)(*DAT_00b5a798 + 4))();
  *(int **)(in_ECX + 4) = piVar3;
  (**(code **)(*piVar3 + 0x40))();
  iVar2 = (**(code **)(*DAT_00b5ae58 + 0x20))();
  uStack_24 = 0;
  uStack_14 = 0;
  uStack_10 = 0xf;
  if (iVar2 == 2) {
    FUN_00401740(s_pan_observerpop_guild_009d96b4,0x15);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_28);
    if (piVar3 == (int *)0x0) {
      uStack_30 = 0xf;
      FUN_00401740(s_pComposite____NULL_009d97c8,0x12);
      FUN_00406880(auStack_28 + -0x20);
      if (uStack_30 < 0x10) {
        uStack_30 = 0xf;
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free((void *)(unaff_ESI & 0xffffff00));
      return;
    }
    (**(code **)(*piVar3 + 0x24))(0);
    *(undefined1 *)(in_ECX + 8) = 0;
    if ((void *)0xf < local_18) {
      _free(pvStack_2c);
      return;
    }
    local_18 = (void *)0xf;
    local_1c = 0;
    pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
    FUN_00401740(s_pan_observerpop_siege_009d96cc,0x15);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_30);
    if (piVar3 == (int *)0x0) {
      FUN_00401740(s_pComposite____NULL_009d97c8,0x12);
      FUN_00406880(&uStack_50);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  else {
    FUN_00401740(s_pan_observerpop_siege_009d96e4,0x15);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_28);
    if (piVar3 == (int *)0x0) {
      uStack_30 = 0xf;
      FUN_00401740(s_pComposite____NULL_009d97c8,0x12);
      FUN_00406880(auStack_28 + -0x20);
      if (uStack_30 < 0x10) {
        uStack_30 = 0xf;
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free((void *)(unaff_ESI & 0xffffff00));
      return;
    }
    (**(code **)(*piVar3 + 0x24))(0);
    *(undefined1 *)(in_ECX + 8) = 0;
    if ((void *)0xf < local_18) {
      _free(pvStack_2c);
      return;
    }
    local_18 = (void *)0xf;
    local_1c = 0;
    pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
    FUN_00401740(s_pan_observerpop_guild_009d96fc,0x15);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_30);
    if (piVar3 == (int *)0x0) {
      FUN_00401740(s_pComposite____NULL_009d97c8,0x12);
      FUN_00406880(&uStack_50);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  (**(code **)(*piVar3 + 0x24))(0);
  if (uStack_20 < 0x10) {
    return;
  }
  _free(pvStack_34);
  return;
}


// ==== FUN_00678be0 @ 0x00678be0 ====

undefined4 FUN_00678be0(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  undefined1 auStack_1c [28];
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_eye_009d9714,7);
  if (iVar3 == 0) {
    iVar3 = (**(code **)(*DAT_00b5ae58 + 0x20))();
    if (iVar3 == 2) {
      FUN_00401830(s_pan_observerpop_guild_009d971c);
      uVar1 = FUN_006788b0(auStack_1c,*(undefined1 *)(in_ECX + 8));
      *(undefined1 *)(in_ECX + 8) = uVar1;
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    FUN_00401830(s_pan_observerpop_siege_009d974c);
    uVar1 = FUN_006788b0(auStack_1c,*(undefined1 *)(in_ECX + 8));
    *(undefined1 *)(in_ECX + 8) = uVar1;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  cVar2 = FUN_004036a0(param_2,s_btn_warp_009d977c);
  if (cVar2 != '\0') {
    (**(code **)(*DAT_00b5ae5c + 0x20))();
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_btn_follow_009d9788);
  if (cVar2 != '\0') {
    (**(code **)(*DAT_00b5ae58 + 0x14))();
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_btn_UI_009d9794);
  if ((cVar2 != '\0') || (cVar2 = FUN_004036a0(param_2,s_btn_UI_guild_009d979c), cVar2 != '\0')) {
    (**(code **)(*DAT_00b5ae5c + 0x30))();
    return 1;
  }
  cVar2 = FUN_004036a0(param_2,s_btn_exit_009d97ac);
  if ((cVar2 == '\0') && (cVar2 = FUN_004036a0(param_2,s_btn_exit_guild_009d97b8), cVar2 == '\0')) {
    return 0;
  }
  (**(code **)(*DAT_00b5ae5c + 0x28))();
  return 1;
}


// ==== FUN_00678d80 @ 0x00678d80 ====

void FUN_00678d80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d97e4;
  FUN_00678930();
  return;
}


// ==== FUN_00678da0 @ 0x00678da0 ====

undefined4 FUN_00678da0(void)

{
  return 0x88;
}


// ==== FUN_00678db0 @ 0x00678db0 ====

void FUN_00678db0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d97e4;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00678df0 @ 0x00678df0 ====

undefined4 FUN_00678df0(void)

{
  return 0x70040000;
}


// ==== FUN_00678e00 @ 0x00678e00 ====

undefined4 FUN_00678e00(void)

{
  return 0x70040001;
}


// ==== FUN_00678e10 @ 0x00678e10 ====

void FUN_00678e10(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x00678e1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_00678e20 @ 0x00678e20 ====

undefined1 FUN_00678e20(void)

{
  return 0;
}


// ==== FUN_00678e30 @ 0x00678e30 ====

void FUN_00678e30(char param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (param_1 != '\x01') {
    if (puVar1 == (undefined4 *)0x0) {
      FUN_00797a20(0);
      return;
    }
    *puVar1 = &PTR_FUN_009d9998;
    FUN_00797a20(puVar1);
    return;
  }
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009d9984;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00678e90 @ 0x00678e90 ====

void FUN_00678e90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d99ac;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00678eb0 @ 0x00678eb0 ====

undefined4 FUN_00678eb0(void)

{
  int iVar1;
  int in_ECX;
  
  (**(code **)(*DAT_00b5ae54 + 0x20))((undefined1 *)(in_ECX + 0xb));
  (**(code **)(*DAT_00b5ae5c + 0x34))();
  if (*(char *)(in_ECX + 0xc) == '\0') {
    (**(code **)(*DAT_00b5ac94 + 0x2c))();
    (**(code **)(*DAT_00b5ac94 + 0x44))();
  }
  else {
    iVar1 = (**(code **)(*DAT_00b5ae58 + 0x20))();
    if (iVar1 != 2) {
      (**(code **)(*DAT_00b5ac94 + 4))();
      (**(code **)(*DAT_00b5ac94 + 0x18))();
    }
  }
  FUN_00678e30(*(undefined1 *)(in_ECX + 0xb));
  (**(code **)(*DAT_00b5a97c + 0x50))(*(undefined1 *)(in_ECX + 0xd));
  return 1;
}


// ==== FUN_00678f30 @ 0x00678f30 ====

/* WARNING: Removing unreachable block (ram,0x00678f7d) */

void FUN_00678f30(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  undefined1 auStack_1a [26];
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar2 == (int *)0x0) {
    FUN_00401740(s_pComposite____NULL_009d9960,0x12);
    FUN_00406880(auStack_1a + -6);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  (**(code **)(*piVar2 + 0x24))(param_1);
  return;
}


// ==== FUN_00678fa0 @ 0x00678fa0 ====

void FUN_00678fa0(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined2 *puVar4;
  int in_ECX;
  uint unaff_EBP;
  undefined1 local_1c [2];
  undefined1 auStack_1a [2];
  void *local_18;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_observer_ui_observer_op_009d9850,0x2b);
  iVar2 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar2 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar3;
  (**(code **)(*piVar3 + 0x40))();
  puVar4 = (undefined2 *)(**(code **)(*DAT_00b5ae54 + 0x24))();
  *(undefined2 *)(in_ECX + 8) = *puVar4;
  *(undefined1 *)(in_ECX + 10) = *(undefined1 *)(puVar4 + 1);
  puVar4 = (undefined2 *)(**(code **)(*DAT_00b5ae54 + 0x24))();
  *(undefined2 *)(in_ECX + 0xb) = *puVar4;
  *(undefined1 *)(in_ECX + 0xd) = *(undefined1 *)(puVar4 + 1);
  uStack_10 = 0xf;
  uStack_14 = 0;
  uVar1 = unaff_EBP >> 8;
  FUN_00401740(s_pan_situationmode_check_009d987c,0x17);
  FUN_00678f30(local_1c + -0xc,*(undefined1 *)(in_ECX + 9));
  if (0xf < uStack_10) {
    _free((void *)(uVar1 << 8));
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740(s_pan_chatmode_check_009d9894,0x12);
  FUN_00678f30(local_1c + -0xc,*(undefined1 *)(in_ECX + 8));
  if (0xf < uStack_10) {
    _free((void *)(uVar1 << 8));
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740(s_pan_cameramode_check_009d98a8,0x14);
  FUN_00678f30(local_1c + -0xc,*(undefined1 *)(in_ECX + 10));
  if (0xf < uStack_10) {
    _free((void *)(uVar1 << 8));
    return;
  }
  iVar2 = (**(code **)(*DAT_00b5ae58 + 0x20))();
  if (iVar2 == 2) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    FUN_00401740(s_pan_situationmode_check_009d98c0,0x17);
    FUN_00678f30(local_1c + -0xc,0);
    if (0xf < uStack_10) {
      _free((void *)(uVar1 << 8));
      return;
    }
    uStack_10 = 0xf;
    uStack_14 = 0;
    FUN_00401740(s_pan_situationmode_009d98d8,0x11);
    FUN_00678f30(local_1c + -0xc,0);
    if (0xf < uStack_10) {
      _free((void *)(uVar1 << 8));
      return;
    }
    uStack_10 = 0xf;
    uStack_14 = 0;
    FUN_00401740(s_lbl_situationmode_009d98ec,0x11);
    FUN_00678f30(local_1c + -0xc,0);
    if (0xf < uStack_10) {
      _free((void *)(uVar1 << 8));
      return;
    }
  }
  return;
}


// ==== FUN_006791e0 @ 0x006791e0 ====

uint FUN_006791e0(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  uint extraout_EAX;
  int in_ECX;
  void *local_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  iVar1 = **(int **)(in_ECX + 4);
  uVar3 = FUN_00402220(local_1c,param_1,s__check_009d9974);
  piVar4 = (int *)(**(code **)(iVar1 + 0x34))(uVar3);
  if (0xf < uStack_8) {
    _free(local_1c[0]);
    return extraout_EAX;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  local_1c[0] = (void *)((uint)local_1c[0] & 0xffffff00);
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  cVar2 = (**(code **)(*piVar4 + 0x28))();
  (**(code **)(*piVar4 + 0x24))(cVar2 == '\0');
  return (uint)(cVar2 == '\0');
}


// ==== FUN_00679270 @ 0x00679270 ====

void FUN_00679270(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d99ac;
  *(undefined1 *)(in_ECX + 2) = 1;
  *(undefined1 *)((int)in_ECX + 9) = 1;
  *(undefined1 *)((int)in_ECX + 10) = 1;
  *(undefined1 *)((int)in_ECX + 0xb) = 1;
  *(undefined1 *)(in_ECX + 3) = 1;
  *(undefined1 *)((int)in_ECX + 0xd) = 1;
  FUN_00678fa0();
  return;
}


// ==== FUN_006792a0 @ 0x006792a0 ====

undefined4 FUN_006792a0(int param_1,int param_2,int param_3)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int in_ECX;
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      iVar3 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009d9900,8);
      if ((iVar3 == 0) || (cVar1 = FUN_004036a0(param_2,s_btn_cancel_009d990c), cVar1 != '\0')) {
        (**(code **)(*DAT_00b5ae54 + 0x20))((undefined1 *)(in_ECX + 0xb));
        (**(code **)(*DAT_00b5ae5c + 0x34))();
        if (*(char *)(in_ECX + 0xc) == '\0') {
          (**(code **)(*DAT_00b5ac94 + 0x2c))();
          (**(code **)(*DAT_00b5ac94 + 0x44))();
        }
        else {
          iVar3 = (**(code **)(*DAT_00b5ae58 + 0x20))();
          if (iVar3 != 2) {
            (**(code **)(*DAT_00b5ac94 + 4))();
            (**(code **)(*DAT_00b5ac94 + 0x18))();
          }
        }
        FUN_00678e30(*(undefined1 *)(in_ECX + 0xb));
        (**(code **)(*DAT_00b5a97c + 0x50))(*(undefined1 *)(in_ECX + 0xd));
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_ok_009d9918);
      if (cVar1 != '\0') {
        (**(code **)(*DAT_00b5ae54 + 0x20))((undefined1 *)(in_ECX + 8));
        (**(code **)(*DAT_00b5ae5c + 0x34))();
        if (*(char *)(in_ECX + 9) == '\0') {
          (**(code **)(*DAT_00b5ac94 + 0x2c))();
          (**(code **)(*DAT_00b5ac94 + 0x44))();
        }
        else {
          iVar3 = (**(code **)(*DAT_00b5ae58 + 0x20))();
          if (iVar3 != 2) {
            (**(code **)(*DAT_00b5ac94 + 4))();
            (**(code **)(*DAT_00b5ac94 + 0x18))();
          }
        }
        FUN_00678e30(*(undefined1 *)(in_ECX + 8));
        (**(code **)(*DAT_00b5a97c + 0x50))(*(undefined1 *)(in_ECX + 10));
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_apply_009d9920);
      if (cVar1 == '\0') {
        return 0;
      }
      (**(code **)(*DAT_00b5ae54 + 0x20))((undefined1 *)(in_ECX + 8));
      if (*(char *)(in_ECX + 9) == '\0') {
        (**(code **)(*DAT_00b5ac94 + 0x2c))();
        (**(code **)(*DAT_00b5ac94 + 0x44))();
      }
      else {
        iVar3 = (**(code **)(*DAT_00b5ae58 + 0x20))();
        if (iVar3 != 2) {
          (**(code **)(*DAT_00b5ac94 + 4))();
          (**(code **)(*DAT_00b5ac94 + 0x18))();
        }
      }
      FUN_00678e30(*(undefined1 *)(in_ECX + 8));
      if (*(char *)(in_ECX + 10) == '\0') {
        (**(code **)(*DAT_00b5a97c + 0x50))(0);
        return 1;
      }
      (**(code **)(*DAT_00b5a97c + 0x50))(1);
      return 1;
    }
  }
  else if ((param_1 == 0) && (param_3 == 1)) {
    iVar3 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_pan_situationmode_009d992c,0x11);
    if (iVar3 == 0) {
      uVar2 = FUN_006791e0(param_2);
      *(undefined1 *)(in_ECX + 9) = uVar2;
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_pan_chatmode_009d9940);
    if (cVar1 != '\0') {
      uVar2 = FUN_006791e0(param_2);
      *(undefined1 *)(in_ECX + 8) = uVar2;
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_pan_cameramode_009d9950);
    if (cVar1 != '\0') {
      uVar2 = FUN_006791e0(param_2);
      *(undefined1 *)(in_ECX + 10) = uVar2;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00679530 @ 0x00679530 ====

undefined4 FUN_00679530(void)

{
  return 0x87;
}


// ==== FUN_00679540 @ 0x00679540 ====

void FUN_00679540(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d99ac;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00679580 @ 0x00679580 ====

void FUN_00679580(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0067958c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_00679590 @ 0x00679590 ====

undefined1 FUN_00679590(void)

{
  return 0;
}


// ==== FUN_006795a0 @ 0x006795a0 ====

void FUN_006795a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d9a6c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_006795c0 @ 0x006795c0 ====

undefined4 FUN_006795c0(void)

{
  (**(code **)(*DAT_00b5ae5c + 0x2c))();
  return 1;
}


// ==== FUN_006795d0 @ 0x006795d0 ====

undefined4 FUN_006795d0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009d9a44,8);
  if ((iVar2 == 0) || (cVar1 = FUN_004036a0(param_2,s_btn_cancel_009d9a50), cVar1 != '\0')) {
    (**(code **)(*DAT_00b5ae5c + 0x2c))();
    return 1;
  }
  cVar1 = FUN_004036a0(param_2,s_btn_ok_009d9a5c);
  if (cVar1 == '\0') {
    return 0;
  }
  (**(code **)(*DAT_00b5ae58 + 0x18))();
  return 1;
}


// ==== FUN_00679650 @ 0x00679650 ====

void FUN_00679650(void)

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
  FUN_00401740(s_UI_Game2_observer_ui_observer_ex_009d9a18,0x29);
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


// ==== FUN_006796d0 @ 0x006796d0 ====

void FUN_006796d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d9a6c;
  FUN_00679650();
  return;
}


// ==== FUN_006796f0 @ 0x006796f0 ====

undefined4 FUN_006796f0(void)

{
  return 0x86;
}


// ==== FUN_00679700 @ 0x00679700 ====

void FUN_00679700(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d9a6c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00679740 @ 0x00679740 ====

void FUN_00679740(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0067974c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_00679750 @ 0x00679750 ====

undefined1 FUN_00679750(void)

{
  return 0;
}


// ==== FUN_00679760 @ 0x00679760 ====

void FUN_00679760(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d9b30;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00679780 @ 0x00679780 ====

undefined4 FUN_00679780(void)

{
  (**(code **)(*DAT_00b5ae5c + 0x1c))();
  return 1;
}


// ==== FUN_00679790 @ 0x00679790 ====

undefined4 FUN_00679790(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009d9b08,8);
  if ((iVar2 == 0) || (cVar1 = FUN_004036a0(param_2,s_btn_cancel_009d9b14), cVar1 != '\0')) {
    (**(code **)(*DAT_00b5ae5c + 0x1c))();
    return 1;
  }
  cVar1 = FUN_004036a0(param_2,s_btn_ok_009d9b20);
  if (cVar1 == '\0') {
    return 0;
  }
  (**(code **)(*DAT_00b5ae58 + 0x10))();
  return 1;
}


// ==== FUN_00679810 @ 0x00679810 ====

void FUN_00679810(void)

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
  FUN_00401740(s_UI_Game2_observer_ui_observer_co_009d9ad8,0x2c);
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


// ==== FUN_00679890 @ 0x00679890 ====

void FUN_00679890(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d9b30;
  FUN_00679810();
  return;
}


// ==== FUN_006798b0 @ 0x006798b0 ====

undefined4 FUN_006798b0(void)

{
  return 0x85;
}


// ==== FUN_006798c0 @ 0x006798c0 ====

void FUN_006798c0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d9b30;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00679900 @ 0x00679900 ====

void FUN_00679900(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0067990c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_00679910 @ 0x00679910 ====

undefined1 FUN_00679910(void)

{
  return 0;
}


// ==== FUN_00679920 @ 0x00679920 ====

void FUN_00679920(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d9c00;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00679940 @ 0x00679940 ====

undefined4 FUN_00679940(void)

{
  (**(code **)(*DAT_00b5ae5c + 0x24))();
  return 1;
}


// ==== FUN_00679950 @ 0x00679950 ====

void FUN_00679950(void *param_1)

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
  FUN_00401740(s_txt_area_009d9bec,8);
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


// ==== FUN_006799e0 @ 0x006799e0 ====

void FUN_006799e0(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 in_stack_ffffff18;
  uint in_stack_ffffff1c;
  undefined4 in_stack_ffffff20;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 local_b4 [4];
  void *pvStack_b0;
  undefined4 uStack_a0;
  uint uStack_9c;
  undefined4 uStack_98;
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
  
  uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x8340010);
  uStack_7c = 0xf;
  uStack_80 = 0;
  pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
  uVar5 = 0x679a1f;
  FUN_00401660(uVar1,0,0xffffffff);
  uVar2 = (**(code **)(*DAT_00b5ae54 + 0x18))();
  uVar4 = 0;
  if (uVar2 != 0) {
    do {
      iVar3 = (**(code **)(*DAT_00b5ae54 + 0x1c))(uVar4);
      uStack_9c = 0xf;
      uStack_a0 = 0;
      pvStack_b0 = (void *)((uint)pvStack_b0 & 0xffffff00);
      FUN_00401660(iVar3,0,0xffffffff);
      uStack_98 = *(undefined4 *)(iVar3 + 0x1c);
      in_stack_ffffff18 = 0;
      FUN_00401740(&DAT_009d9be0,2);
      uVar1 = FUN_00404230(auStack_5c);
      in_stack_ffffff1c = 0x679ab6;
      uVar1 = FUN_004022a0(auStack_40,&DAT_009d9be8,local_b4,&DAT_009d9be4,uVar1);
      in_stack_ffffff20 = 0x679ac7;
      uVar1 = FUN_00402220(auStack_24,uVar1);
      uVar1 = FUN_00405bd0(auStack_78,uVar1);
      uVar5 = 0x679ae5;
      FUN_00401ff0(uVar1,0,0xffffffff);
      if (0xf < uStack_60) {
        _free(pvStack_74);
        return;
      }
      uStack_60 = 0xf;
      uStack_64 = 0;
      pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
      if (0xf < uStack_c) {
        _free(pvStack_20);
        return;
      }
      uStack_c = 0xf;
      uStack_10 = 0;
      pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
      if (0xf < uStack_28) {
        _free(pvStack_3c);
        return;
      }
      uStack_28 = 0xf;
      uStack_2c = 0;
      pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
      if (0xf < uStack_44) {
        _free(pvStack_58);
        return;
      }
      uStack_44 = 0xf;
      uStack_48 = 0;
      pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
      if (0xf < uStack_9c) {
        _free(pvStack_b0);
        return;
      }
      uVar4 = uVar4 + 1;
      uStack_9c = 0xf;
      uStack_a0 = 0;
      pvStack_b0 = (void *)((uint)pvStack_b0 & 0xffffff00);
    } while (uVar4 < uVar2);
  }
  uVar7 = 0xf;
  uVar6 = 0;
  in_stack_ffffff1c = in_stack_ffffff1c & 0xffffff00;
  FUN_00401660(auStack_94,0,0xffffffff);
  FUN_00679950(in_stack_ffffff18,in_stack_ffffff1c,in_stack_ffffff20,uVar5,uVar1,uVar6,uVar7);
  if (uStack_7c < 0x10) {
    return;
  }
  _free(pvStack_90);
  return;
}


// ==== FUN_00679c10 @ 0x00679c10 ====

void FUN_00679c10(void)

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
  FUN_00401740(s_UI_Game2_observer_ui_observer_ar_009d9b9c,0x2d);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    FUN_006799e0();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00679c90 @ 0x00679c90 ====

void FUN_00679c90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d9c00;
  FUN_00679c10();
  return;
}


// ==== FUN_00679cb0 @ 0x00679cb0 ====

undefined4 FUN_00679cb0(int param_1,int param_2,int param_3)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined1 local_10 [4];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar3 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009d9bcc,8);
    if (iVar3 == 0) {
      (**(code **)(*DAT_00b5ae5c + 0x24))();
      return 1;
    }
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    FUN_00404fb0(param_2,0x5f,local_10);
    pcVar5 = s_select_009d9bd8;
    uVar4 = FUN_00405d30(1);
    cVar1 = FUN_004036a0(uVar4,pcVar5);
    if (cVar1 != '\0') {
      uVar4 = FUN_00405d30(0);
      uVar2 = thunk_FUN_00796f80(uVar4);
      (**(code **)(*DAT_00b5ae58 + 0xc))(uVar2);
      FUN_00406250();
      return 1;
    }
    FUN_00406250();
  }
  return 0;
}


// ==== FUN_00679d90 @ 0x00679d90 ====

undefined4 FUN_00679d90(void)

{
  return 0x84;
}


// ==== FUN_00679da0 @ 0x00679da0 ====

void FUN_00679da0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d9c00;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00679de0 @ 0x00679de0 ====

void FUN_00679de0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x00679dec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_00679df0 @ 0x00679df0 ====

undefined1 FUN_00679df0(void)

{
  return 0;
}


// ==== FUN_00679e00 @ 0x00679e00 ====

void FUN_00679e00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d9cfc;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_00679e20 @ 0x00679e20 ====

undefined4 FUN_00679e20(void)

{
  (**(code **)(*DAT_00b5ae5c + 0x10))();
  (**(code **)(*DAT_00b5ae58 + 0x1c))(0);
  return 1;
}


// ==== FUN_00679e70 @ 0x00679e70 ====

undefined4 FUN_00679e70(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  if ((param_1 != 1) || (param_3 != 1)) {
    return 0;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009d9cac,8);
  if ((iVar2 == 0) || (cVar1 = FUN_004036a0(param_2,s_btn_cancel_009d9cb8), cVar1 != '\0')) {
    (**(code **)(*DAT_00b5ae5c + 0x10))();
    (**(code **)(*DAT_00b5ae58 + 0x1c))(0);
    return 1;
  }
  cVar1 = FUN_004036a0(param_2,s_btn_ok_009d9cc4);
  if (cVar1 == '\0') {
    return 0;
  }
  (**(code **)(*DAT_00b5ae58 + 0x10))();
  return 1;
}


// ==== FUN_00679f00 @ 0x00679f00 ====

void FUN_00679f00(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  void *unaff_EBX;
  void **ppvVar4;
  undefined1 uVar5;
  void *local_38;
  undefined1 local_34 [12];
  uint uStack_28;
  uint local_24;
  void *local_20;
  void *apvStack_1c [3];
  undefined4 uStack_10;
  uint uStack_c;
  uint uStack_8;
  
  local_20 = (void *)0xf;
  local_24 = 0;
  local_34[0] = 0;
  FUN_00401740(s_lbl_usercount_009d9cd0,0xd);
  (**(code **)(*DAT_00b5ae54 + 8))();
  FUN_00401740(&DAT_009d9ccc,2);
  ppvVar4 = apvStack_1c;
  uVar1 = FUN_00404230(ppvVar4);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x30))();
    if (iVar3 != 0) {
      FUN_0055a260(uVar1);
    }
  }
  if (0xf < uStack_8) {
    _free(apvStack_1c[0]);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = 0xf;
  uStack_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  FUN_00401740(s_lbl_entercount_009d9ce4,0xe);
  (**(code **)(*DAT_00b5ae54 + 0x10))();
  uVar5 = 0;
  FUN_00401740(&DAT_009d9ce0,2);
  uVar1 = FUN_00404230(&local_20,ppvVar4,uVar5);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(apvStack_1c + -8);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x30))();
    if (iVar3 != 0) {
      FUN_0055a260(uVar1);
    }
  }
  if (0xf < uStack_c) {
    _free(local_20);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  if (uStack_28 < 0x10) {
    return;
  }
  _free(unaff_EBX);
  return;
}


// ==== FUN_0067a070 @ 0x0067a070 ====

void FUN_0067a070(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  void *unaff_ESI;
  char *pcStack_4c;
  void *local_34;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *local_24;
  uint local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_10;
  
  pcStack_4c = s_UI_Game2_observer_ui_observer_en_009d9c6c;
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  pcStack_4c = (char *)0x67a0a4;
  iVar1 = FUN_00410500();
  if (0xf < local_20) {
    pcStack_4c = (char *)0x67a0ba;
    _free(local_34);
    return;
  }
  pcStack_4c = (char *)(iVar1 + 0x3c);
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))();
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  iVar1 = (**(code **)(*DAT_00b5ae58 + 0x20))();
  if (iVar1 == 2) {
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x834000c);
    uStack_18 = 0xf;
    uStack_1c = 0;
    uStack_2c = uStack_2c & 0xffffff00;
    FUN_00401660(uVar3,0,0xffffffff);
    FUN_00401740(s_lbl_usercount_text_009d9c98,0x12);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pcStack_4c);
    if (piVar2 != (int *)0x0) {
      iVar1 = (**(code **)(*piVar2 + 0x30))();
      if (iVar1 != 0) {
        FUN_0055a260(auStack_28);
      }
    }
    if (0xf < uStack_2c) {
      _free(unaff_ESI);
      return;
    }
    if (0xf < uStack_10) {
      _free(local_24);
      return;
    }
  }
  FUN_00679f00();
  return;
}


// ==== FUN_0067a1a0 @ 0x0067a1a0 ====

void FUN_0067a1a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d9cfc;
  FUN_0067a070();
  return;
}


// ==== FUN_0067a1c0 @ 0x0067a1c0 ====

undefined4 FUN_0067a1c0(void)

{
  return 0x83;
}


// ==== FUN_0067a1d0 @ 0x0067a1d0 ====

void FUN_0067a1d0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d9cfc;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0067a210 @ 0x0067a210 ====

undefined4 FUN_0067a210(void)

{
  return 0x191;
}


// ==== FUN_0067a220 @ 0x0067a220 ====

uint FUN_0067a220(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  return uVar1 & 0xffffff00;
}


// ==== FUN_0067a230 @ 0x0067a230 ====

void FUN_0067a230(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0067a23c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_0067a240 @ 0x0067a240 ====

undefined4 FUN_0067a240(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar1 = &PTR_FUN_009d9d8c;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_0067a270 @ 0x0067a270 ====

undefined1 FUN_0067a270(void)

{
  return 0;
}


// ==== FUN_0067a280 @ 0x0067a280 ====

void FUN_0067a280(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d9da0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0067a2a0 @ 0x0067a2a0 ====

void FUN_0067a2a0(void)

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
  FUN_00401740(s_UI_Maptool_ui_testwnd_txt_009d9d68,0x19);
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


// ==== FUN_0067a340 @ 0x0067a340 ====

void FUN_0067a340(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d9da0;
  FUN_0067a2a0();
  return;
}


// ==== FUN_0067a360 @ 0x0067a360 ====

undefined4 FUN_0067a360(void)

{
  return 0x7f;
}


// ==== FUN_0067a370 @ 0x0067a370 ====

void FUN_0067a370(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d9da0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0067a3b0 @ 0x0067a3b0 ====

undefined4 FUN_0067a3b0(void)

{
  return 0x102;
}


// ==== FUN_0067a3c0 @ 0x0067a3c0 ====

undefined4 FUN_0067a3c0(void)

{
  return 0x103;
}


// ==== FUN_0067a3d0 @ 0x0067a3d0 ====

uint FUN_0067a3d0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  return uVar1 & 0xffffff00;
}


// ==== FUN_0067a3e0 @ 0x0067a3e0 ====

void FUN_0067a3e0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0067a3ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_0067a3f0 @ 0x0067a3f0 ====

byte FUN_0067a3f0(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),&DAT_009d9f94,4);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),&DAT_009d9f9c,7);
  if (iVar2 == 0) {
    return 1;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),&DAT_009d9fa4,7);
  if (iVar2 == 0) {
    return 2;
  }
  cVar1 = FUN_004036a0(param_1,&DAT_009d9fac);
  if (cVar1 != '\0') {
    return 3;
  }
  cVar1 = FUN_004036a0(param_1,&DAT_009d9fb4);
  if (cVar1 != '\0') {
    return 4;
  }
  cVar1 = FUN_004036a0(param_1,&DAT_009d9fbc);
  if (cVar1 != '\0') {
    return 5;
  }
  cVar1 = FUN_004036a0(param_1,&DAT_009d9fc0);
  if (cVar1 != '\0') {
    return 6;
  }
  cVar1 = FUN_004036a0(param_1,&DAT_009d9fc8);
  if (cVar1 != '\0') {
    return 7;
  }
  cVar1 = FUN_004036a0(param_1,&DAT_009d9fd0);
  if (cVar1 != '\0') {
    return 8;
  }
  cVar1 = FUN_004036a0(param_1,&DAT_009d9fd4);
  if (cVar1 == '\0') {
    cVar1 = FUN_004036a0(param_1,&DAT_009d9fdc);
    return -(cVar1 != '\0') & 10;
  }
  return 9;
}


// ==== FUN_0067a530 @ 0x0067a530 ====

void FUN_0067a530(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009da034;
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


// ==== FUN_0067a580 @ 0x0067a580 ====

void FUN_0067a580(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  void *local_1c;
  void *pvStack_18;
  undefined4 uStack_c;
  uint uStack_8;
  uint uStack_4;
  
  uVar5 = 1;
  do {
    FUN_00401740(s_btn_tile_d_009d9eb4,10);
    FUN_00404230(&local_1c);
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x30))();
      FUN_00558730(*(uint *)(in_ECX + 0x24) == uVar5);
    }
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
    uVar5 = uVar5 + 1;
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  } while (uVar5 < 6);
  iVar2 = (**(code **)(*DAT_00b5afb4 + 0x10))();
  if (*(int *)(iVar2 + 0x34) != 0) {
    puVar3 = operator_new(0x28);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = &PTR_FUN_009da068;
      puVar3[8] = 0xf;
      puVar3[7] = 0;
      *(undefined1 *)(puVar3 + 3) = 0;
      *(undefined1 *)(puVar3 + 9) = 0;
    }
    if (*(int *)(in_ECX + 0x24) == 5) {
      *(undefined1 *)(puVar3 + 9) = 1;
      FUN_00401660(in_ECX + 8,0,0xffffffff);
      uVar4 = FUN_004d3960(in_ECX + 8);
    }
    else {
      puVar3[1] = *(int *)(in_ECX + 0x24);
      uVar4 = FUN_004d3970(*(int *)(in_ECX + 0x24) + -1);
    }
    FUN_00797a20(puVar3);
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_00401740(s_com_type_009d9ec0,8);
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
    if (0xf < uStack_8) {
      _free(local_1c);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x30))();
      FUN_00577df0(uVar4);
    }
  }
  return;
}


// ==== FUN_0067a730 @ 0x0067a730 ====

void FUN_0067a730(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  undefined4 uStack_c4;
  undefined1 uStack_c0;
  undefined4 uStack_b4;
  uint uStack_b0;
  uint uStack_ac;
  int iStack_a8;
  int local_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  int iStack_98;
  int iStack_94;
  int iStack_90;
  int iStack_8c;
  undefined1 auStack_88 [4];
  undefined1 uStack_84;
  void *pvStack_80;
  undefined4 uStack_74;
  undefined4 uStack_70;
  uint auStack_6c [2];
  void *pvStack_64;
  undefined1 uStack_60;
  uint uStack_50;
  undefined4 uStack_4c;
  void *pvStack_48;
  undefined4 uStack_38;
  uint uStack_34;
  undefined1 auStack_30 [4];
  void *pvStack_2c;
  undefined4 uStack_1c;
  uint uStack_18;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  local_a4 = in_ECX;
  iVar1 = (**(code **)(*DAT_00b5afb4 + 0x10))();
  if (*(int *)(iVar1 + 0x34) != 0) {
    uStack_4c = 0xf;
    uStack_50 = 0;
    uStack_60 = 0;
    FUN_00401660(*(int *)(*(int *)(iVar1 + 0x34) + 0xc0) + 0xac,0,0xffffffff);
    uStack_ac = 0xf;
    uStack_b0 = 0;
    uStack_c0 = 0;
    FUN_00401740(s_lbl_title_009d9f28,9);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_c4);
    if (0xf < uStack_b0) {
      _free(uStack_c4);
      return;
    }
    uStack_b0 = 0xf;
    uStack_b4 = 0;
    uStack_c4 = (void *)((uint)uStack_c4 & 0xffffff00);
    FUN_00401740(s_Title____s_009d9f34,10);
    FUN_00404230(auStack_30);
    (**(code **)(*piVar2 + 0x30))();
    FUN_0055a260(auStack_30);
    FUN_004020e0(s_maptex_first_dds_009d9f40,0x10);
    uStack_34 = 0xf;
    uStack_38 = 0;
    pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
    FUN_00401740(s_pan_tile_009d9f54,8);
    uStack_8 = 0x40;
    uStack_10 = 2;
    uVar5 = 0;
    while( true ) {
      uStack_ac = uVar5 + 1;
      FUN_00401740(s_btn_tile_d_009d9f60,10);
      FUN_00404230(auStack_88 + -0x40);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_88 + -0x40);
      puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        *puVar3 = &PTR_FUN_009da07c;
        puVar3[0x10] = 0xf;
        puVar3[0xf] = 0;
        *(undefined1 *)(puVar3 + 0xb) = 0;
      }
      uVar4 = (**(code **)(*piVar2 + 4))();
      puVar3[1] = uVar4;
      iStack_98 = (uVar5 & 1) * 0x100;
      iStack_90 = iStack_98 + 0x40;
      uStack_a0 = 0x40;
      iStack_94 = (uVar5 >> 1) * 0x40;
      uStack_9c = uStack_c;
      local_a4 = iStack_14;
      iStack_8c = iStack_94 + 0x40;
      uStack_70 = 0xf;
      uStack_74 = 0;
      uStack_84 = 0;
      iStack_a8 = 2;
      FUN_00401660(auStack_6c,0,0xffffffff);
      puVar3[2] = iStack_a8;
      puVar3[3] = local_a4;
      puVar3[4] = uStack_a0;
      puVar3[5] = uStack_9c;
      puVar3[6] = iStack_98;
      puVar3[7] = iStack_94;
      puVar3[8] = iStack_90;
      puVar3[9] = iStack_8c;
      FUN_00401660(auStack_88,0,0xffffffff);
      (**(code **)(*DAT_00b5ad24 + 4))(puVar3);
      (**(code **)*puVar3)(1);
      if (0xf < auStack_6c[0]) {
        _free(pvStack_80);
        return;
      }
      auStack_6c[0] = 0xf;
      uStack_70 = 0;
      pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
      if (0xf < uStack_b0) {
        _free(uStack_c4);
        return;
      }
      uStack_b0 = 0xf;
      uStack_b4 = 0;
      uStack_c4 = (void *)((uint)uStack_c4 & 0xffffff00);
      if (3 < uStack_ac) break;
      in_ECX = iStack_a8;
      uVar5 = uStack_ac;
    }
    if (0xf < uStack_34) {
      _free(pvStack_48);
      return;
    }
    uStack_34 = 0xf;
    uStack_38 = 0;
    pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
    if (0xf < uStack_18) {
      _free(pvStack_2c);
      return;
    }
    uStack_18 = 0xf;
    uStack_1c = 0;
    pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
    if (0xf < uStack_50) {
      _free(pvStack_64);
      return;
    }
  }
  return;
}


// ==== FUN_0067ace0 @ 0x0067ace0 ====

undefined4 FUN_0067ace0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  undefined1 auStack_52 [26];
  undefined1 local_38 [24];
  undefined1 auStack_20 [4];
  undefined1 local_1c [28];
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009d9e30,8);
      if (iVar2 == 0) {
        puVar3 = operator_new(4);
        if (puVar3 == (undefined4 *)0x0) {
          FUN_00797a20(0);
          return 1;
        }
        *puVar3 = &PTR_FUN_009da020;
        FUN_00797a20(puVar3);
        return 1;
      }
      iVar2 = FUN_00405850(s_btn_tile_009d9e3c,0,8);
      if (iVar2 != -1) {
        uVar4 = FUN_00405b90(local_1c,8,*(int *)(param_2 + 0x14) + -1);
        uVar4 = thunk_FUN_00796fb0(uVar4);
        *(undefined4 *)(in_ECX + 0x24) = uVar4;
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
  }
  else if (param_1 == 0x15) {
    if (param_3 == 1) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_com_type_009d9e48,8);
      if (iVar2 == 0) {
        iVar2 = (**(code **)(*DAT_00b5afb4 + 0x10))();
        if (*(int *)(iVar2 + 0x34) == 0) {
          return 1;
        }
        piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_2);
        (**(code **)(*piVar5 + 0x30))();
        FUN_005778b0(auStack_52 + -6);
        uVar4 = FUN_0067a3f0(auStack_52 + -6);
        if (*(int *)(in_ECX + 0x24) == 5) {
          FUN_004d3930(uVar4,in_ECX + 8);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        FUN_004d3940(uVar4,*(int *)(in_ECX + 0x24) + -1);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar1 = FUN_004036a0(param_2,s_com_list_009d9e54);
      if (cVar1 != '\0') {
        piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_2);
        (**(code **)(*piVar5 + 0x30))();
        uVar4 = FUN_005778b0(auStack_20);
        FUN_00401660(uVar4,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
  }
  else if ((param_1 == 2) && (param_3 == 4)) {
    cVar1 = FUN_004036a0(param_2,s_edit_text_009d9e60);
    if (cVar1 != '\0') {
      FUN_00401830(s_edit_text_009d9e6c);
      (**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_38);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  return 0;
}


// ==== FUN_0067b060 @ 0x0067b060 ====

void FUN_0067b060(void)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  void *pvVar6;
  undefined1 auStack_8c [4];
  void *pvStack_88;
  void *pvStack_84;
  undefined4 uStack_80;
  undefined1 auStack_7c [4];
  void *pvStack_78;
  undefined1 uStack_74;
  undefined4 uStack_68;
  uint uStack_64;
  int iStack_60;
  int iStack_5c;
  void *pvStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 auStack_3c [4];
  void *pvStack_38;
  undefined1 uStack_34;
  uint uStack_24;
  undefined4 uStack_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  iVar2 = (**(code **)(*DAT_00b5afb4 + 0x10))();
  if (*(int *)(iVar2 + 0x34) != 0) {
    uStack_20 = 0xf;
    uStack_24 = 0;
    uStack_34 = 0;
    FUN_00401660(*(int *)(*(int *)(iVar2 + 0x34) + 0xc0) + 0xac,0,0xffffffff);
    iStack_60 = 0xf;
    uStack_64 = 0;
    uStack_74 = 0;
    FUN_00401740(s_com_list_009d9e88,8);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_78);
    if (0xf < uStack_64) {
      _free(pvStack_78);
      return;
    }
    uStack_64 = 0xf;
    uStack_68 = 0;
    pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
    if (piVar3 == (int *)0x0) {
      if (0xf < uStack_24) {
        _free(pvStack_38);
        return;
      }
    }
    else {
      (**(code **)(*piVar3 + 0x30))();
      FUN_00578750(1);
      uVar4 = FUN_004022a0(auStack_7c,s_Texture__009d9e9c,auStack_3c,&DAT_009d9e94);
      FUN_00402220(&uStack_20,uVar4);
      if (0xf < uStack_64) {
        _free(pvStack_78);
        return;
      }
      FUN_00401660(&uStack_20,0,0xffffffff);
      FUN_004056c0(auStack_8c,1);
      uStack_40 = 0xf;
      uStack_44 = 0;
      pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
      iStack_5c = 0;
      iStack_60 = 0;
      FUN_00401740(&DAT_009d9ea8,4);
      FUN_00577d70(&iStack_60,0);
      pvVar1 = pvStack_84;
      if (pvStack_88 != pvStack_84) {
        iVar2 = 1;
        pvVar6 = pvStack_88;
        do {
          iVar5 = FUN_00405850(&DAT_009d9eb0,0,1);
          if (iVar5 == -1) {
            iStack_60 = iVar2;
            iStack_5c = iVar2;
            FUN_00401660(pvVar6,0,0xffffffff);
            FUN_00577d70(&iStack_60,0);
            iVar2 = iVar2 + 1;
          }
          pvVar6 = (void *)((int)pvVar6 + 0x1c);
        } while (pvVar6 != pvVar1);
      }
      FUN_00578700();
      FUN_00577df0(0);
      if (0xf < uStack_40) {
        _free(pvStack_54);
        return;
      }
      uStack_40 = 0xf;
      uStack_44 = 0;
      pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
      if (pvStack_88 != (void *)0x0) {
        FUN_00405de0(pvStack_88,pvStack_84,auStack_8c,pvVar1);
        _free(pvStack_88);
        return;
      }
      pvStack_88 = (void *)0x0;
      pvStack_84 = (void *)0x0;
      uStack_80 = 0;
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return;
      }
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      if (0xf < uStack_24) {
        _free(pvStack_38);
        return;
      }
    }
  }
  return;
}


// ==== FUN_0067b2f0 @ 0x0067b2f0 ====

void FUN_0067b2f0(void)

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
  FUN_00401740(&DAT_009d9ecc,4);
  FUN_00406720(&local_24);
  if (0xf < local_c) {
    _free(local_20);
    return;
  }
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(&DAT_009d9ed4,7);
  FUN_00406720(&local_24);
  if (0xf < local_c) {
    _free(local_20);
    return;
  }
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(&DAT_009d9edc,7);
  FUN_00406720(&local_24);
  if (0xf < local_c) {
    _free(local_20);
    return;
  }
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(&DAT_009d9ee4,7);
  FUN_00406720(&local_24);
  if (0xf < local_c) {
    _free(local_20);
    return;
  }
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(&DAT_009d9eec,7);
  FUN_00406720(&local_24);
  if (0xf < local_c) {
    _free(local_20);
    return;
  }
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(&DAT_009d9ef4,2);
  FUN_00406720(&local_24);
  if (0xf < local_c) {
    _free(local_20);
    return;
  }
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(&DAT_009d9ef8,4);
  FUN_00406720(&local_24);
  if (0xf < local_c) {
    _free(local_20);
    return;
  }
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(&DAT_009d9f00,4);
  FUN_00406720(&local_24);
  if (0xf < local_c) {
    _free(local_20);
    return;
  }
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(&DAT_009d9f08,2);
  FUN_00406720(&local_24);
  if (0xf < local_c) {
    _free(local_20);
    return;
  }
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(&DAT_009d9f0c,4);
  FUN_00406720(&local_24);
  if (0xf < local_c) {
    _free(local_20);
    return;
  }
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(&DAT_009d9f14,4);
  FUN_00406720(&local_24);
  if (0xf < local_c) {
    _free(local_20);
    return;
  }
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(s_com_type_009d9f1c,8);
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
    FUN_00578750(1);
    pvVar3 = (void *)0x0;
    pvVar2 = local_34;
    if (local_34 != local_30) {
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


// ==== FUN_0067b6c0 @ 0x0067b6c0 ====

void FUN_0067b6c0(void)

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
  FUN_00401740(s_UI_Maptool_ui_tilewnd_txt_009d9e14,0x19);
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
  FUN_0067b060();
  FUN_0067b2f0();
  FUN_0067a730();
  FUN_0067a580();
  if (piVar1 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar1 + 4))();
    *(undefined4 *)(iVar3 + 0x28) = 0;
    (**(code **)(*DAT_00b5a7cc + 0x2c))(piVar1);
  }
  return;
}


// ==== FUN_0067b780 @ 0x0067b780 ====

void FUN_0067b780(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009da034;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[1] = 0;
  FUN_00401740(&DAT_009d9e0c,4);
  in_ECX[9] = 1;
  FUN_0067b6c0();
  return;
}


// ==== FUN_0067b7c0 @ 0x0067b7c0 ====

undefined4 FUN_0067b7c0(void)

{
  return 0x7e;
}


// ==== FUN_0067b7f0 @ 0x0067b7f0 ====

undefined4 FUN_0067b7f0(void)

{
  return 0x30040053;
}


// ==== FUN_0067b800 @ 0x0067b800 ====

void FUN_0067b800(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009da068;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0067b830 @ 0x0067b830 ====

undefined4 FUN_0067b830(void)

{
  return 0x60000045;
}


// ==== FUN_0067b840 @ 0x0067b840 ====

void FUN_0067b840(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009da07c;
  FUN_00713830();
  *in_ECX = &PTR_FUN_0099cf40;
  if ((param_1 & 1) != 0) {
    (**(code **)(*DAT_00b5a6a8 + 8))();
  }
  return;
}


// ==== FUN_0067b870 @ 0x0067b870 ====

void FUN_0067b870(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009da034;
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


// ==== FUN_0067b8d0 @ 0x0067b8d0 ====

void FUN_0067b8d0(undefined1 param_1,void *param_2)

{
  undefined4 *in_ECX;
  uint in_stack_0000001c;
  
  *in_ECX = &PTR_FUN_009da094;
  in_ECX[6] = 0;
  in_ECX[7] = 0xf;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401660(&param_1,0,0xffffffff);
  if (in_stack_0000001c < 0x10) {
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_0067b920 @ 0x0067b920 ====

undefined4 FUN_0067b920(void)

{
  return 0x30040054;
}


// ==== FUN_0067b930 @ 0x0067b930 ====

void FUN_0067b930(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009da094;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0067b9b0 @ 0x0067b9b0 ====

undefined4 FUN_0067b9b0(void)

{
  return 0x101;
}


// ==== FUN_0067b9c0 @ 0x0067b9c0 ====

void FUN_0067b9c0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0067b9cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_0067b9d0 @ 0x0067b9d0 ====

undefined4 FUN_0067b9d0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar1 = &PTR_FUN_009da4a0;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_0067ba00 @ 0x0067ba00 ====

void FUN_0067ba00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009da4c8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0067ba20 @ 0x0067ba20 ====

void FUN_0067ba20(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_ECX;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined1 uStack_11;
  undefined1 local_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined1 local_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  
  uVar1 = *(undefined4 *)(param_1 + 4);
  uVar2 = *(undefined4 *)(param_1 + 8);
  uStack_11 = (undefined1)((uint)uVar1 >> 0x18);
  uVar6 = *(uint *)(param_1 + 0xc);
  local_10 = (undefined1)uVar2;
  uStack_f = (undefined1)((uint)uVar2 >> 8);
  uStack_e = (undefined1)((uint)uVar2 >> 0x10);
  uStack_d = (undefined1)((uint)uVar2 >> 0x18);
  uVar3 = *(uint *)(param_1 + 0x10);
  uVar5 = 0;
  local_c = (undefined1)uVar6;
  uStack_b = (undefined1)(uVar6 >> 8);
  uStack_a = (undefined1)(uVar6 >> 0x10);
  puVar4 = (undefined4 *)(in_ECX + 8);
  do {
    (**(code **)(*(int *)*puVar4 + 0x30))();
    FUN_00558730((uVar6 >> 0x10 & 0xff) == uVar5);
    uVar5 = uVar5 + 1;
    puVar4 = puVar4 + 1;
  } while ((int)uVar5 < 3);
  uVar5 = 0;
  puVar4 = (undefined4 *)(in_ECX + 0x14);
  do {
    (**(code **)(*(int *)*puVar4 + 0x30))();
    FUN_00558730(uVar6 >> 0x18 == uVar5);
    uVar5 = uVar5 + 1;
    puVar4 = puVar4 + 1;
  } while ((int)uVar5 < 4);
  uVar6 = 0;
  puVar4 = (undefined4 *)(in_ECX + 0x24);
  do {
    (**(code **)(*(int *)*puVar4 + 0x30))();
    FUN_00558730(uVar6 == (uVar3 & 0xff));
    uVar6 = uVar6 + 1;
    puVar4 = puVar4 + 1;
  } while ((int)uVar6 < 3);
  uVar6 = 0;
  puVar4 = (undefined4 *)(in_ECX + 0x30);
  do {
    (**(code **)(*(int *)*puVar4 + 0x30))();
    FUN_00558730(uVar6 == (uVar3 >> 8 & 0xff));
    uVar6 = uVar6 + 1;
    puVar4 = puVar4 + 1;
  } while ((int)uVar6 < 8);
  (**(code **)(**(int **)(in_ECX + 0x50) + 0x30))();
  FUN_00577df0(uVar3 >> 0x10 & 0xff);
  (**(code **)(**(int **)(in_ECX + 0x54) + 0x30))();
  FUN_00558730(CONCAT13(uStack_a,CONCAT12(uStack_b,CONCAT11(local_c,uStack_d))));
  (**(code **)(**(int **)(in_ECX + 0x58) + 0x30))();
  FUN_00558730(uVar1);
  (**(code **)(**(int **)(in_ECX + 0x5c) + 0x30))();
  FUN_00558730(CONCAT13(local_10,(int3)((uint)uVar1 >> 8)));
  (**(code **)(**(int **)(in_ECX + 0x60) + 0x30))();
  FUN_00558730(CONCAT13(uStack_f,CONCAT12(local_10,(short)((uint)uVar1 >> 0x10))));
  (**(code **)(**(int **)(in_ECX + 100) + 0x30))();
  FUN_00558730(CONCAT13(uStack_e,CONCAT12(uStack_f,CONCAT11(local_10,uStack_11))));
  (**(code **)(**(int **)(in_ECX + 0x68) + 0x30))();
  FUN_00558730(uVar2);
  (**(code **)(**(int **)(in_ECX + 0x6c) + 0x30))();
  FUN_00558730(CONCAT13(local_c,(int3)((uint)uVar2 >> 8)));
  (**(code **)(**(int **)(in_ECX + 0x78) + 0x30))();
  FUN_00558730(CONCAT13(uStack_b,CONCAT12(local_c,(short)((uint)uVar2 >> 0x10))));
  (**(code **)(**(int **)(in_ECX + 0x70) + 0x30))();
  FUN_00558730();
  return;
}


// ==== FUN_0067bbe0 @ 0x0067bbe0 ====

uint FUN_0067bbe0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x201) {
    uVar1 = FUN_0067ba20(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0067bc10 @ 0x0067bc10 ====

void FUN_0067bc10(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009da4b4;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_OBJECT_009da47c,6);
  if (iVar2 == 0) {
    puVar1[1] = 0x13;
    FUN_00797a20(puVar1);
    return;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_EFFECT_009da484,6);
  if (iVar2 == 0) {
    puVar1[1] = 0x12;
    FUN_00797a20(puVar1);
    return;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_CREATURE_009da48c,8);
  if (iVar2 == 0) {
    puVar1[1] = 0x11;
  }
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0067bcc0 @ 0x0067bcc0 ====

undefined4 FUN_0067bcc0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int in_ECX;
  undefined1 auStack_1a [26];
  
  if (param_1 == 1) {
    if (param_3 == 1) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_new_009da298,7);
      if (iVar2 == 0) {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 1;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_open_009da2a0);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 4;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_save_009da2ac);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 5;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_camerazoom_009da2b8);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 7;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_camerarot_009da2c8);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 8;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_camerapan_009da2d8);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 9;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_tile_009da2e8);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 10;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_vcolor_009da2f4);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0xb;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_water_009da300);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0xc;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_height_009da30c);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0xd;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_heightb_009da318);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0xe;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_selector_009da324);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0xf;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_attr_009da334);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0x10;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_objstamp_009da340);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0x14;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_objmovexz_009da350);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0x15;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_objmovey_009da360);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0x16;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_objrotatey_009da370);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0x17;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_objrotatex_009da380);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0x18;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_objrotatez_009da390);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0x19;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_objscale_009da3a0);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0x1a;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_objdelete_009da3b0);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0x1b;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_attron_009da3c0);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0x1d;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_wateron_009da3cc);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0x1e;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_effecton_009da3d8);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0x1f;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_objanion_009da3e8);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0x20;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_mapon_009da3f8);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0x22;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_gridon_009da404);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0x23;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_playeron_009da410);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0x24;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_objon_009da420);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0x21;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_creatureon_009da42c);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0x1c;
        FUN_00797a20(puVar3);
        return 1;
      }
      cVar1 = FUN_004036a0(param_2,s_btn_brush_009da43c);
      if (cVar1 != '\0') {
        puVar3 = operator_new(8);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009da4b4;
        }
        puVar3[1] = 0x25;
        FUN_00797a20(puVar3);
        return 1;
      }
    }
  }
  else if ((param_1 == 0x15) && (param_3 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_com_type_009da448,8);
    if (iVar2 == 0) {
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_2);
      (**(code **)(*piVar4 + 0x30))();
      FUN_005778b0(auStack_1a + -6);
      FUN_0067bc10(auStack_1a + -6);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    return 1;
  }
  return 0;
}


// ==== FUN_0067c580 @ 0x0067c580 ====

void FUN_0067c580(void)

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
  FUN_00401740(s_OBJECT_009da454,6);
  FUN_00406720(&local_24);
  if (0xf < local_c) {
    _free(local_20);
    return;
  }
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(s_EFFECT_009da45c,6);
  FUN_00406720(&local_24);
  if (0xf < local_c) {
    _free(local_20);
    return;
  }
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(s_CREATURE_009da464,8);
  FUN_00406720(&local_24);
  if (0xf < local_c) {
    _free(local_20);
    return;
  }
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401740(s_com_type_009da470,8);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_24);
  if (0xf < local_10) {
    _free(local_24);
    return;
  }
  local_10 = 0xf;
  uStack_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
    FUN_00578750(1);
    pvVar3 = (void *)0x0;
    pvVar2 = local_34;
    if (local_34 != local_30) {
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


// ==== FUN_0067c790 @ 0x0067c790 ====

/* WARNING: Removing unreachable block (ram,0x0067c9b0) */
/* WARNING: Removing unreachable block (ram,0x0067c932) */
/* WARNING: Removing unreachable block (ram,0x0067c971) */
/* WARNING: Removing unreachable block (ram,0x0067c9ef) */
/* WARNING: Removing unreachable block (ram,0x0067c8f3) */
/* WARNING: Removing unreachable block (ram,0x0067c875) */
/* WARNING: Removing unreachable block (ram,0x0067c836) */
/* WARNING: Removing unreachable block (ram,0x0067c8b4) */
/* WARNING: Removing unreachable block (ram,0x0067c7d8) */

void FUN_0067c790(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  uint in_ECX;
  undefined1 auStackY_134 [128];
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  uint uVar11;
  undefined4 *_Memory;
  uint *_Memory_00;
  undefined4 *_Memory_01;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  uint uVar12;
  undefined1 auStack_1e [30];
  
  uStack_38 = s_UI_Maptool_ui_ToolBarWnd_txt_009da0e0;
  uStack_3c = 0x67c7bc;
  FUN_00401740();
  uStack_38 = (char *)0x67c7c6;
  iVar1 = FUN_00410500();
  uStack_38 = (char *)(iVar1 + 0x3c);
  uStack_3c = 0x67c7f9;
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))();
  *(int **)(in_ECX + 4) = piVar2;
  uStack_40 = (undefined1 *)0x67c804;
  uStack_3c = in_ECX;
  (**(code **)(*piVar2 + 0x40))();
  uStack_40 = (undefined1 *)0xe;
  FUN_00401740();
  uStack_40 = auStack_1e + -10;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 8) = uVar3;
  FUN_00401740();
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0xc) = uVar3;
  FUN_00401740();
  puVar10 = auStack_1e + -0x12;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x10) = uVar3;
  FUN_00401740();
  puVar9 = auStack_1e + -0x16;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x14) = uVar3;
  FUN_00401740();
  _Memory_01 = &uStack_38;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x18) = uVar3;
  uStack_38 = (char *)((uint)uStack_38 & 0xffffff00);
  FUN_00401740();
  _Memory_00 = &uStack_3c;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x1c) = uVar3;
  uStack_3c = uStack_3c & 0xffffff00;
  FUN_00401740();
  _Memory = &uStack_40;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x20) = uVar3;
  uStack_40 = (undefined1 *)((uint)uStack_40 & 0xffffff00);
  FUN_00401740();
  puVar5 = auStack_1e + -0x26;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x24) = uVar3;
  uVar12 = 0;
  FUN_00401740();
  puVar4 = auStack_1e + -0x2a;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x28) = uVar3;
  if (0xf < uVar12) {
    _free(puVar10);
    return;
  }
  uStack_38 = (char *)0x0;
  FUN_00401740();
  puVar10 = auStack_1e + -0x2e;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x2c) = uVar3;
  if (0xf < uStack_38) {
    _free(puVar9);
    return;
  }
  uStack_38 = (char *)0xf;
  uStack_3c = 0;
  FUN_00401740();
  puVar9 = auStack_1e + -0x32;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x50) = uVar3;
  if (0xf < uStack_3c) {
    _free(_Memory_01);
    return;
  }
  uStack_3c = 0xf;
  uStack_40 = (undefined1 *)0x0;
  FUN_00401740();
  puVar8 = auStack_1e + -0x36;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x30) = uVar3;
  if (0xf < uStack_40) {
    _free(_Memory_00);
    return;
  }
  uStack_40 = (undefined1 *)0xf;
  uVar12 = 0;
  FUN_00401740();
  puVar7 = auStack_1e + -0x3a;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x34) = uVar3;
  if (0xf < uVar12) {
    _free(_Memory);
    return;
  }
  uVar12 = 0;
  FUN_00401740();
  puVar6 = auStack_1e + -0x3e;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x38) = uVar3;
  if (0xf < uVar12) {
    _free(puVar5);
    return;
  }
  uVar12 = 0;
  FUN_00401740();
  puVar5 = auStack_1e + -0x42;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x3c) = uVar3;
  if (0xf < uVar12) {
    _free(puVar4);
    return;
  }
  uVar12 = 0;
  FUN_00401740();
  puVar4 = auStack_1e + -0x46;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x40) = uVar3;
  if (0xf < uVar12) {
    _free(puVar10);
    return;
  }
  uVar12 = 0;
  FUN_00401740();
  puVar10 = auStack_1e + -0x4a;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x44) = uVar3;
  if (0xf < uVar12) {
    _free(puVar9);
    return;
  }
  uVar12 = 0;
  FUN_00401740();
  puVar9 = auStackY_134 + 200;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x48) = uVar3;
  if (0xf < uVar12) {
    _free(puVar8);
    return;
  }
  uVar12 = 0;
  FUN_00401740();
  puVar8 = auStackY_134 + 0xc4;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x4c) = uVar3;
  if (0xf < uVar12) {
    _free(puVar7);
    return;
  }
  uVar12 = 0;
  FUN_00401740();
  puVar7 = auStackY_134 + 0xc0;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x54) = uVar3;
  if (0xf < uVar12) {
    _free(puVar6);
    return;
  }
  uVar12 = 0;
  FUN_00401740();
  puVar6 = auStackY_134 + 0xbc;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x58) = uVar3;
  if (0xf < uVar12) {
    _free(puVar5);
    return;
  }
  uVar12 = 0;
  FUN_00401740();
  puVar5 = auStackY_134 + 0xb8;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x5c) = uVar3;
  if (0xf < uVar12) {
    _free(puVar4);
    return;
  }
  uVar12 = 0;
  FUN_00401740(s_btn_effecton_009da23c);
  puVar4 = auStackY_134 + 0xb4;
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  *(undefined4 *)(in_ECX + 0x60) = uVar3;
  if (0xf < uVar12) {
    _free(puVar10);
    return;
  }
  uVar12 = 0;
  FUN_00401740(s_btn_objon_009da24c,9);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStackY_134 + 0xb0);
  *(undefined4 *)(in_ECX + 100) = uVar3;
  if (0xf < uVar12) {
    _free(puVar9);
    return;
  }
  uVar11 = 0;
  uVar12 = (uint)puVar9 & 0xffffff00;
  FUN_00401740(s_btn_mapon_009da258,9);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStackY_134 + 0xac);
  *(undefined4 *)(in_ECX + 0x68) = uVar3;
  if (0xf < uVar11) {
    _free(puVar8);
    return;
  }
  uVar11 = 0;
  FUN_00401740(s_btn_playeron_009da264,0xc);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStackY_134 + 0xa8);
  *(undefined4 *)(in_ECX + 0x70) = uVar3;
  if (0xf < uVar11) {
    _free(puVar7);
    return;
  }
  uVar11 = 0;
  FUN_00401740(s_btn_gridon_009da274,10);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStackY_134 + 0xa4);
  *(undefined4 *)(in_ECX + 0x6c) = uVar3;
  if (0xf < uVar11) {
    _free(puVar6);
    return;
  }
  uVar11 = 0;
  FUN_00401740(s_btn_objani_009da280,10);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStackY_134 + 0xa0);
  *(undefined4 *)(in_ECX + 0x74) = uVar3;
  if (0xf < uVar11) {
    _free(puVar5);
    return;
  }
  FUN_00401830(s_btn_brush_009da28c);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStackY_134 + 0x9c);
  *(undefined4 *)(in_ECX + 0x78) = uVar3;
  if (uVar12 < 0x10) {
    FUN_0067c580();
    return;
  }
  _free(puVar4);
  return;
}


// ==== FUN_0067cf30 @ 0x0067cf30 ====

void FUN_0067cf30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009da4c8;
  in_ECX[1] = 0;
  in_ECX[0x1f] = 1;
  FUN_0067c790();
  return;
}


// ==== FUN_0067cf50 @ 0x0067cf50 ====

undefined4 FUN_0067cf50(void)

{
  return 0x7d;
}


// ==== FUN_0067cf60 @ 0x0067cf60 ====

void FUN_0067cf60(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009da4c8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0067cfa0 @ 0x0067cfa0 ====

void FUN_0067cfa0(void)

{
  return;
}


// ==== FUN_0067d010 @ 0x0067d010 ====

undefined4 FUN_0067d010(void)

{
  (**(code **)(*DAT_00b5b0cc + 0x18))();
  return 1;
}


// ==== FUN_0067d050 @ 0x0067d050 ====

void FUN_0067d050(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(*DAT_00b5a78c + 0x1c))
            (CONCAT13((char)((uint)(in_ECX + 0xa8) >> 0x18),*(undefined3 *)(in_ECX + 0xa8)),param_1)
  ;
  return;
}


// ==== FUN_0067d0d0 @ 0x0067d0d0 ====

undefined1 FUN_0067d0d0(int *param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined1 uVar4;
  
  uVar4 = 0;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  piVar3 = (int *)(**(code **)(*param_1 + 0x2c))();
  cVar2 = (**(code **)(*DAT_00b5b0d0 + 0x58))(param_1);
  if ((((cVar2 != '\0') || (iVar1 = piVar3[2], iVar1 == 0x100)) || (iVar1 == 0x10b)) ||
     ((iVar1 == 0x101 && (*piVar3 == 0)))) {
    uVar4 = 1;
  }
  return uVar4;
}


// ==== FUN_0067d150 @ 0x0067d150 ====

undefined4 FUN_0067d150(int param_1,undefined2 param_2,int param_3,undefined4 param_4)

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
      (**(code **)(*DAT_00b5a78c + 4))((int3)in_ECX[0x2a]);
      return 1;
    case 5:
      uVar2 = thunk_FUN_00796f80(param_4);
      FUN_0067d050(uVar2);
      return 1;
    case 0xb:
      (**(code **)(*DAT_00b5b0cc + 0x1c))();
    }
  }
  return 1;
}


// ==== FUN_0067d260 @ 0x0067d260 ====

undefined4 FUN_0067d260(int param_1)

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
    cVar1 = FUN_0067d0d0(iVar3);
    if (cVar1 == '\x01') {
      FUN_0057f390(0x40000060);
      return 1;
    }
    FUN_0057f390(0x60b00000);
  }
  return 1;
}


// ==== FUN_0067d2e0 @ 0x0067d2e0 ====

undefined4 FUN_0067d2e0(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar5 = 0xffff0000;
  cVar1 = FUN_0067d0d0(param_1);
  if (cVar1 == '\x01') {
    uVar5 = 0xffffffff;
  }
  iVar2 = (**(code **)(*DAT_00b5b0cc + 0x24))();
  if ((iVar2 != 0) && (piVar3 = (int *)(**(code **)(*DAT_00b5b0cc + 0x24))(), *piVar3 == param_1)) {
    return 0xaa333333;
  }
  iVar2 = (**(code **)(*DAT_00b5b0cc + 0x28))();
  if ((iVar2 != 0) && (piVar3 = (int *)(**(code **)(*DAT_00b5b0cc + 0x28))(), *piVar3 == param_1)) {
    return 0xaa333333;
  }
  uVar4 = (**(code **)(*DAT_00b5b0cc + 0x34))();
  if ((uVar4 != 0) && (uVar6 = 0, uVar4 != 0)) {
    do {
      piVar3 = (int *)(**(code **)(*DAT_00b5b0cc + 0x2c))(uVar6);
      if ((piVar3 != (int *)0x0) && ((*piVar3 != 0 && (*piVar3 == param_1)))) {
        return 0xaa333333;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar4);
  }
  return uVar5;
}


// ==== FUN_0067d390 @ 0x0067d390 ====

void FUN_0067d390(undefined4 param_1)

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


// ==== FUN_0067d3f0 @ 0x0067d3f0 ====

undefined4 FUN_0067d3f0(int param_1)

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
  
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_slotbag_009da7fc,7);
  if (iVar2 != 0) {
    return 0;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a78c + 0x48))();
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x2c))();
    uStack_20 = CONCAT11(uStack_20._1_1_,*(undefined1 *)(in_ECX + 0xac));
    uVar1 = FUN_00802534();
    uStack_20 = CONCAT11(uVar1,(undefined1)uStack_20);
    uVar1 = FUN_00802534();
    (**(code **)(*DAT_00b5a78c + 4))(CONCAT12(uVar1,uStack_20));
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_Call_________IINVEN__IUIHANDLER__009da804,0x3c);
    FUN_00796d50(&uStack_20);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return extraout_EAX;
    }
  }
  return 1;
}


// ==== FUN_0067d560 @ 0x0067d560 ====

void FUN_0067d560(void)

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
  cVar1 = (**(code **)(*DAT_00b5b0cc + 0x44))();
  if (cVar1 == '\x01') {
    cVar1 = (**(code **)(*DAT_00b5b0cc + 0x48))();
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
    FUN_00401740(s_pan_effect_009da8b8,10);
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
    (**(code **)(*DAT_00b5b0cc + 0x40))(0);
  }
  return;
}


// ==== FUN_0067d690 @ 0x0067d690 ====

void FUN_0067d690(void)

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
  piVar7 = (int *)(in_ECX + 0x50);
  do {
    if ((uVar2 < 0xd) || (0x12 < uVar2)) {
      iVar3 = (**(code **)(*DAT_00b5a78c + 0x44))(iVar6);
      *piVar7 = iVar3;
      FUN_00401740(s_suititem__d_009da918,0xb);
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
  *(undefined1 *)(in_ECX + 0xad) = uVar1;
  return;
}


// ==== FUN_0067d7f0 @ 0x0067d7f0 ====

void FUN_0067d7f0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  char *pcVar4;
  undefined1 auStack_32 [2];
  undefined4 uStack_30;
  uint uStack_2c;
  uint uStack_28;
  void *pvStack_20;
  void *local_1c;
  undefined1 local_18;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_upgrade_item_009da924,0xc);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  (**(code **)(*piVar1 + 0x30))();
  piVar1 = (int *)(**(code **)(*DAT_00b5b0cc + 0x24))();
  if (piVar1 == (int *)0x0) {
    uStack_30 = 1;
    uStack_2c = 1;
    FUN_005802c0(auStack_32 + -6,&uStack_30);
    FUN_00580870(0,1);
    pcVar4 = s_pan_upgradeItem_bg_009da934;
  }
  else {
    if (*piVar1 != 0) {
      local_8 = 0xf;
      uStack_c = 0;
      local_1c = (void *)((uint)local_1c & 0xffffff00);
      FUN_00401740(s_pan_upgradeItem_bg_009da95c,0x12);
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x24))(1);
      }
      if (uStack_c < 0x10) {
        (**(code **)(*(int *)*piVar1 + 0x1c))();
        iVar3 = (**(code **)(*(int *)*piVar1 + 0x2c))();
        uStack_28 = (uint)*(byte *)(iVar3 + 0x31);
        uStack_2c = (uint)*(byte *)(iVar3 + 0x30);
        FUN_005802c0(auStack_32 + -6,&uStack_2c);
        FUN_00580870(*piVar1,1);
        return;
      }
      _free(pvStack_20);
      return;
    }
    uStack_30 = 1;
    uStack_2c = 1;
    FUN_005802c0(auStack_32 + -6,&uStack_30);
    FUN_00580870(0,1);
    pcVar4 = s_pan_upgradeItem_bg_009da948;
  }
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  uStack_c = 0;
  local_8 = 0xf;
  FUN_00401740(pcVar4,0x12);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(0);
  }
  if (uStack_c < 0x10) {
    return;
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_0067d9c0 @ 0x0067d9c0 ====

void FUN_0067d9c0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined1 auStack_32 [2];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  void *pvStack_20;
  void *local_1c;
  undefined1 local_18;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_stone_cash_socket_009daa90,0x11);
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
      piVar1 = (int *)(**(code **)(*DAT_00b5b0cc + 0x28))();
      if (piVar1 != (int *)0x0) {
        if (*piVar1 == 0) {
          uStack_30 = 1;
          uStack_2c = 1;
          FUN_005802c0(auStack_32 + -6,&uStack_30);
          FUN_00580870(0,1);
          FUN_00401830(s_pan_cash_bg_009daab0);
          piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 0x24))(0);
          }
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        FUN_00401830(s_pan_cash_bg_009daabc);
        piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 0x24))(1);
        }
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      uStack_30 = 1;
      uStack_2c = 1;
      FUN_005802c0(auStack_32 + -6,&uStack_30);
      FUN_00580870(0,1);
      FUN_00401830(s_pan_cash_bg_009daaa4);
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x24))(0);
      }
      if (0xf < uStack_c) {
        _free(pvStack_20);
        return;
      }
    }
  }
  return;
}


// ==== FUN_0067dba0 @ 0x0067dba0 ====

void FUN_0067dba0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint in_ECX;
  uint uVar5;
  undefined1 *puVar6;
  undefined1 uVar7;
  int iStack_a0;
  uint local_9c [2];
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  uint uStack_80;
  uint uStack_7c;
  undefined1 local_78 [4];
  void *pvStack_74;
  undefined4 uStack_64;
  uint auStack_60 [2];
  void *pvStack_58;
  undefined4 uStack_48;
  uint auStack_44 [2];
  void *pvStack_3c;
  undefined4 uStack_2c;
  void *apvStack_28 [4];
  undefined4 uStack_18;
  uint uStack_14;
  
  uVar5 = 0;
  local_9c[0] = in_ECX;
  do {
    FUN_00401740(s_stone_socket__d_009daac8,0xf);
    puVar6 = local_78;
    uVar1 = FUN_00404230(puVar6);
    piVar2 = (int *)(**(code **)(**(int **)(local_9c[0] + 4) + 0x34))(uVar1);
    if (0xf < auStack_60[0]) {
      _free(pvStack_74);
      return;
    }
    auStack_60[0] = 0xf;
    uStack_64 = 0;
    pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
    if (piVar2 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar2 + 0x30))();
      if (iVar3 != 0) {
        piVar2 = (int *)(**(code **)(*DAT_00b5b0cc + 0x2c))(uVar5);
        if (piVar2 == (int *)0x0) {
          local_9c[0] = 0;
          uStack_8c = 1;
          uStack_88 = 1;
          FUN_005802c0(local_9c,&uStack_8c);
          FUN_00580870(0,1);
          uVar7 = 0;
          FUN_00401740(s_pan_socket__d_bg_009daad8,0x10);
          uVar1 = FUN_00404230(auStack_44,puVar6,uVar7);
          piVar2 = (int *)(**(code **)(**(int **)(iStack_a0 + 4) + 0x34))(uVar1);
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 0x24))(0);
          }
          if ((void *)0xf < apvStack_28[0]) {
            _free(pvStack_3c);
            return;
          }
          apvStack_28[0] = (void *)0xf;
          uStack_2c = 0;
          pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
        }
        else if (*piVar2 == 0) {
          local_9c[0] = 0;
          uStack_94 = 1;
          uStack_90 = 1;
          FUN_005802c0(local_9c,&uStack_94);
          FUN_00580870(0,1);
          uVar7 = 0;
          FUN_00401740(s_pan_socket__d_bg_009daaec,0x10);
          uVar1 = FUN_00404230(auStack_60,puVar6,uVar7);
          piVar2 = (int *)(**(code **)(**(int **)(iStack_a0 + 4) + 0x34))(uVar1);
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 0x24))(0);
          }
          if (0xf < auStack_44[0]) {
            _free(pvStack_58);
            return;
          }
          auStack_44[0] = 0xf;
          uStack_48 = 0;
          pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
        }
        else {
          uVar7 = 0;
          FUN_00401740(s_pan_socket__d_bg_009dab00,0x10);
          uVar1 = FUN_00404230(apvStack_28,puVar6,uVar7);
          piVar4 = (int *)(**(code **)(**(int **)(iStack_a0 + 4) + 0x34))(uVar1);
          if (piVar4 != (int *)0x0) {
            (**(code **)(*piVar4 + 0x24))(1);
          }
          if (0xf < uStack_14) {
            _free(apvStack_28[0]);
            return;
          }
          uStack_14 = 0xf;
          uStack_18 = 0;
          apvStack_28[0] = (void *)((uint)apvStack_28[0] & 0xffffff00);
          local_9c[0] = (**(code **)(*(int *)*piVar2 + 0x1c))();
          local_9c[0] = local_9c[0] & 0xffff;
          iVar3 = (**(code **)(*(int *)*piVar2 + 0x2c))();
          uStack_7c = (uint)*(byte *)(iVar3 + 0x31);
          uStack_80 = (uint)*(byte *)(iVar3 + 0x30);
          FUN_005802c0(&uStack_94,&uStack_80);
          FUN_00580870(*piVar2,1);
        }
      }
    }
    uVar5 = uVar5 + 1;
    if (4 < uVar5) {
      return;
    }
  } while( true );
}


// ==== FUN_0067de60 @ 0x0067de60 ====

void FUN_0067de60(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  uVar1 = (**(code **)(*DAT_00b5b0cc + 0x30))();
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  FUN_00401740(s_lbl_cost_009dab14,8);
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


// ==== FUN_0067df10 @ 0x0067df10 ====

void FUN_0067df10(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  (**(code **)(*DAT_00b5b0cc + 0x38))();
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  FUN_00401740(s_lbl_percent_009dab20,0xb);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_1c);
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = (void *)((uint)uStack_1c & 0xffffff00);
  (**(code **)(*piVar1 + 0x30))();
  FUN_00401740(s__d____009dab2c,5);
  uVar2 = FUN_00404230((int)register0x00000010 + -0x20);
  FUN_0055a260(uVar2);
  if (uStack_8 < 0x10) {
    return;
  }
  _free(uStack_1c);
  return;
}


// ==== FUN_0067dfe0 @ 0x0067dfe0 ====

void FUN_0067dfe0(byte param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 uStack_20;
  void *pvStack_1c;
  void *pvStack_18;
  uint uStack_c;
  uint uStack_8;
  uint uStack_4;
  
  bVar1 = (**(code **)(*DAT_00b5ad1c + 0x7c))();
  uStack_20 = (void *)CONCAT13(bVar1,(undefined3)uStack_20);
  if ((param_1 < bVar1) &&
     (uStack_20 = (void *)(CONCAT13(bVar1,(undefined3)uStack_20) & 0xff00ffff), bVar1 != 0)) {
    do {
      FUN_00401740(s_btn_changebag__d_009dab34,0x10);
      uVar2 = FUN_00404230(&pvStack_1c);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(uVar2);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x30))(), iVar4 != 0)) {
        FUN_00558730(uStack_20._2_1_ == param_1);
      }
      bVar1 = uStack_20._2_1_ + 1;
      uStack_20._0_3_ = CONCAT12(bVar1,(undefined2)uStack_20);
    } while (bVar1 < uStack_20._3_1_);
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_btn_changebag_2_009dab48,0xf);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1c);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x24))(2 < (byte)((uint)unaff_EBX >> 0x18));
  }
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  FUN_00401740(s_btn_changebag_3_009dab58,0xf);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_20);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x24))(3 < (byte)((uint)unaff_EBP >> 0x18));
  }
  if (uStack_c < 0x10) {
    return;
  }
  _free(uStack_20);
  return;
}


// ==== FUN_0067e160 @ 0x0067e160 ====

void FUN_0067e160(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  int in_ECX;
  int iVar9;
  int unaff_EBX;
  undefined4 *puVar10;
  void **ppvVar11;
  undefined1 auStack_74 [8];
  undefined4 local_6c;
  void *pvStack_68;
  uint uStack_64;
  int iStack_60;
  int iStack_5c;
  void *pvStack_58;
  undefined4 uStack_54;
  undefined4 auStack_50 [2];
  int iStack_48;
  uint uStack_44;
  int iStack_40;
  int iStack_3c;
  void *pvStack_30;
  uint uStack_1c;
  
  iVar3 = (**(code **)(*DAT_00b5b0d0 + 4))();
  if (iVar3 != 0) {
    iStack_40 = 0xf;
    uStack_44 = 0;
    uStack_54 = uStack_54 & 0xffffff00;
    FUN_00401740(s_upgrade_item_009dab68,0xc);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_58);
    if (0xf < uStack_44) {
      _free(pvStack_58);
      return;
    }
    uStack_44 = 0xf;
    iStack_48 = 0;
    pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
    iVar5 = (**(code **)(*piVar4 + 0x14))();
    iVar3 = (**(code **)(*piVar4 + 0x10))();
    piVar2 = DAT_00b5b0d0;
    piVar1 = DAT_00b5ad20;
    local_6c = *(undefined4 *)(iVar3 + 8);
    pvStack_68 = *(void **)(iVar3 + 0xc);
    uStack_64 = *(uint *)(iVar3 + 0x10);
    iStack_60 = *(int *)(iVar3 + 0x14);
    puVar6 = (undefined4 *)(**(code **)(*DAT_00b5b0d0 + 4))();
    iVar3 = *piVar1;
    uVar7 = (**(code **)(*piVar2 + 0x40))();
    (**(code **)(iVar3 + 0x5c))(auStack_74,*puVar6,uVar7);
    iVar8 = (**(code **)(*piVar4 + 0x30))();
    puVar10 = (undefined4 *)(iVar8 + 0x74);
    ppvVar11 = &pvStack_68;
    for (iVar9 = 7; iVar9 != 0; iVar9 = iVar9 + -1) {
      *ppvVar11 = (void *)*puVar10;
      puVar10 = puVar10 + 1;
      ppvVar11 = ppvVar11 + 1;
    }
    if ((pvStack_68 == (void *)0x1) || (uStack_54._2_1_ == '\x01')) {
      iVar9 = (int)((*(int *)(unaff_EBX + 0x10) - iStack_5c * uStack_64) - *(int *)(unaff_EBX + 8))
              / 2;
      iVar8 = ((*(int *)(unaff_EBX + 0x14) - (int)pvStack_58 * iStack_60) -
              *(int *)(unaff_EBX + 0xc)) / 2;
    }
    else {
      iVar9 = 0;
      iVar8 = 0;
    }
    iVar9 = iVar9 + ((uint)puVar6 & 0xff);
    iVar8 = iVar8 + ((uint)puVar6 >> 8 & 0xff);
    auStack_50[0] = 0xf;
    uStack_54 = 0;
    uStack_64 = uStack_64 & 0xffffff00;
    FUN_00401740(s_pan_effect_socket_009dab78,0x11);
    piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 4) + 0x34))(&pvStack_68);
    if (0xf < uStack_54) {
      _free(pvStack_68);
      return;
    }
    uStack_54 = 0xf;
    pvStack_58 = (void *)0x0;
    pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
    uVar7 = (**(code **)(*piVar4 + 0x10))();
    FUN_005041e0(uVar7);
    uStack_44 = iVar5 + iVar8;
    iStack_48 = iVar3 + iVar9;
    iStack_40 = iVar3 + 0x20 + iVar9;
    iStack_3c = iVar5 + 0x20 + iVar8;
    (**(code **)(*piVar4 + 0xc))(auStack_50);
    if (0xf < uStack_1c) {
      _free(pvStack_30);
      return;
    }
  }
  return;
}


// ==== FUN_0067e370 @ 0x0067e370 ====

void FUN_0067e370(void)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  *in_ECX = &PTR_FUN_009daba4;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  iVar1 = 4;
  puVar2 = in_ECX + 0x15;
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


// ==== FUN_0067e3c0 @ 0x0067e3c0 ====

undefined4 FUN_0067e3c0(int param_1)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  int iVar5;
  undefined4 extraout_EAX_00;
  int *piVar6;
  undefined3 *puVar7;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  long lVar8;
  undefined4 extraout_EAX_04;
  undefined4 extraout_EAX_05;
  undefined4 extraout_EAX_06;
  undefined4 extraout_EAX_07;
  undefined4 extraout_EAX_08;
  undefined4 extraout_EAX_09;
  undefined4 extraout_EAX_10;
  undefined4 extraout_EAX_11;
  undefined4 extraout_EAX_12;
  undefined4 extraout_EAX_13;
  undefined4 extraout_EAX_14;
  undefined4 extraout_EAX_15;
  undefined4 extraout_EAX_16;
  undefined4 extraout_EAX_17;
  undefined4 extraout_EAX_18;
  undefined4 extraout_EAX_19;
  undefined4 extraout_EAX_20;
  void *_Memory;
  undefined4 extraout_EAX_21;
  int in_ECX;
  void *unaff_EBX;
  undefined4 *_Memory_00;
  undefined4 uStack_bc;
  void *pvStack_b8;
  void *pvStack_b4;
  undefined4 uStack_b0;
  uint uStack_ac;
  uint uStack_a8;
  void *pvStack_a4;
  void *pvStack_a0;
  void *pvStack_9c;
  void *pvStack_98;
  undefined4 uStack_94;
  uint uStack_90;
  undefined4 uStack_8c;
  uint uStack_88;
  uint uStack_84;
  uint uStack_7c;
  uint uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  void *pvStack_58;
  void *pvStack_54;
  undefined4 uStack_48;
  uint uStack_44;
  uint uStack_40;
  undefined4 uStack_3c;
  void *pvStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 uStack_20;
  undefined4 uStack_10;
  undefined4 uStack_c;
  int iStack_8;
  
  cVar2 = (**(code **)(*DAT_00b5b0cc + 0x4c))();
  pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
  pvStack_a4 = (void *)0x0;
  pvStack_a0 = (void *)0xf;
  if (cVar2 == '\0') {
    FUN_00401740(s_pan_stone_0_check_009da73c,0x11);
    FUN_0067d390(&pvStack_b8,0);
    if ((void *)0xf < pvStack_a0) {
      _free(pvStack_b4);
      return extraout_EAX_06;
    }
    pvStack_a0 = (void *)0xf;
    pvStack_a4 = (void *)0x0;
    pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
    FUN_00401740(s_pan_stone_1_check_009da750,0x11);
    FUN_0067d390(&pvStack_b8,0);
    if ((void *)0xf < pvStack_a0) {
      _free(pvStack_b4);
      return extraout_EAX_07;
    }
    pvStack_a0 = (void *)0xf;
    pvStack_a4 = (void *)0x0;
    pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
    FUN_00401740(s_pan_stone_2_check_009da764,0x11);
    FUN_0067d390(&pvStack_b8,0);
    if ((void *)0xf < pvStack_a0) {
      _free(pvStack_b4);
      return extraout_EAX_08;
    }
    pvStack_a0 = (void *)0xf;
    pvStack_a4 = (void *)0x0;
    pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
    FUN_00401740(s_pan_stone_3_check_009da778,0x11);
    FUN_0067d390(&pvStack_b8,0);
    if ((void *)0xf < pvStack_a0) {
      _free(pvStack_b4);
      return extraout_EAX_09;
    }
    pvStack_a0 = (void *)0xf;
    pvStack_a4 = (void *)0x0;
    pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
    FUN_00401740(s_lbl_stone_0_009da78c,0xb);
    FUN_0067d390(&pvStack_b8,0);
    if ((void *)0xf < pvStack_a0) {
      _free(pvStack_b4);
      return extraout_EAX_10;
    }
    uStack_84 = 0xf;
    uStack_88 = 0;
    pvStack_98 = (void *)((uint)pvStack_98 & 0xffffff00);
    FUN_00401740(s_lbl_stone_0_009da798,0xb);
    pvStack_a0 = (void *)0xf;
    pvStack_a4 = (void *)0x0;
    pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
    FUN_00401740(&DAT_009da7a4,0);
    piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_9c);
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 0x30))();
      FUN_0055a260(&uStack_bc);
    }
    if ((void *)0xf < pvStack_a4) {
      _free(pvStack_b8);
      return extraout_EAX_11;
    }
    pvStack_a4 = (void *)0xf;
    uStack_a8 = 0;
    pvStack_b8 = (void *)((uint)pvStack_b8 & 0xffffff00);
    if (0xf < uStack_88) {
      _free(pvStack_9c);
      return extraout_EAX_12;
    }
    uStack_88 = 0xf;
    uStack_8c = 0;
    pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
    FUN_00401740(s_lbl_stone_1_009da7a8,0xb);
    FUN_0067d390(&pvStack_a0,0);
    if (0xf < uStack_88) {
      _free(pvStack_9c);
      return extraout_EAX_13;
    }
    uStack_88 = 0xf;
    uStack_8c = 0;
    pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
    FUN_00401740(s_lbl_stone_1_009da7b4,0xb);
    pvStack_a4 = (void *)0xf;
    uStack_a8 = 0;
    pvStack_b8 = (void *)((uint)pvStack_b8 & 0xffffff00);
    FUN_00401740(&DAT_009da7c0,0);
    piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_a0);
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 0x30))();
      FUN_0055a260((int)register0x00000010 + -0xc0);
    }
    if (0xf < uStack_a8) {
      _free(uStack_bc);
      return extraout_EAX_14;
    }
    uStack_a8 = 0xf;
    uStack_ac = 0;
    uStack_bc = (void *)((uint)uStack_bc & 0xffffff00);
    if (0xf < uStack_8c) {
      _free(pvStack_a0);
      return extraout_EAX_15;
    }
    uStack_8c = 0xf;
    uStack_90 = 0;
    pvStack_a0 = (void *)((uint)pvStack_a0 & 0xffffff00);
    FUN_00401740(s_lbl_stone_2_009da7c4,0xb);
    FUN_0067d390(&pvStack_a4,0);
    if (0xf < uStack_8c) {
      _free(pvStack_a0);
      return extraout_EAX_16;
    }
    uStack_8c = 0xf;
    uStack_90 = 0;
    pvStack_a0 = (void *)((uint)pvStack_a0 & 0xffffff00);
    FUN_00401740(s_lbl_stone_2_009da7d0,0xb);
    uStack_a8 = 0xf;
    uStack_ac = 0;
    uStack_bc = (void *)((uint)uStack_bc & 0xffffff00);
    FUN_00401740(&DAT_009da7dc,0);
    piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_a4);
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 0x30))();
      FUN_0055a260((int)register0x00000010 + -0xc4);
    }
    if (0xf < uStack_ac) {
      _free(unaff_EBX);
      return extraout_EAX_17;
    }
    uStack_ac = 0xf;
    uStack_b0 = 0;
    if (0xf < uStack_90) {
      _free(pvStack_a4);
      return extraout_EAX_18;
    }
    uStack_90 = 0xf;
    uStack_94 = 0;
    pvStack_a4 = (void *)((uint)pvStack_a4 & 0xffffff00);
    FUN_00401740(s_lbl_stone_3_009da7e0,0xb);
    FUN_0067d390(&uStack_a8,0);
    if (0xf < uStack_90) {
      _free(pvStack_a4);
      return extraout_EAX_19;
    }
    uStack_90 = 0xf;
    uStack_94 = 0;
    pvStack_a4 = (void *)((uint)pvStack_a4 & 0xffffff00);
    FUN_00401740(s_lbl_stone_3_009da7ec,0xb);
    uStack_ac = 0xf;
    uStack_b0 = 0;
    FUN_00401740(&DAT_009da7f8,0);
    piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_a8);
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 0x30))();
      FUN_0055a260(&pvStack_b8);
    }
    if ((void *)0xf < pvStack_a0) {
      _free(pvStack_b4);
      return extraout_EAX_20;
    }
    pvStack_a0 = (void *)0xf;
    pvStack_a4 = (void *)0x0;
    pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
    if (uStack_84 < 0x10) {
      return 0;
    }
    _Memory = pvStack_98;
LAB_0067eca8:
    _free(_Memory);
    return extraout_EAX_21;
  }
  uStack_7c = uStack_7c & 0xffffff00;
  cVar2 = (**(code **)(*DAT_00b5b0d0 + 0x48))();
  if (cVar2 != '\0') {
    do {
      FUN_00401740(s_pan_stone__d_009da710,0xc);
      uVar4 = FUN_00404230(&pvStack_9c);
      FUN_00401660(uVar4,0,0xffffffff);
      if (0xf < uStack_84) {
        _free(pvStack_98);
        return extraout_EAX;
      }
      uStack_84 = 0xf;
      uStack_88 = 0;
      pvStack_98 = (void *)((uint)pvStack_98 & 0xffffff00);
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        iVar5 = param_1 + 4;
      }
      else {
        iVar5 = *(int *)(param_1 + 4);
      }
      iVar5 = FUN_00403620(0,pvStack_a4,iVar5,*(undefined4 *)(param_1 + 0x14));
      if ((iVar5 == 0) && (iVar5 = (**(code **)(*DAT_00b5b0d0 + 0x44))(uStack_7c), iVar5 == 0)) {
        if (pvStack_a0 < (void *)0x10) {
          return 0;
        }
        _Memory = pvStack_b4;
        goto LAB_0067eca8;
      }
      uStack_7c = CONCAT31(uStack_7c._1_3_,(byte)uStack_7c + '\x01');
      bVar3 = (**(code **)(*DAT_00b5b0d0 + 0x48))();
    } while ((byte)uStack_7c < bVar3);
  }
  uStack_bc = (void *)((uint)uStack_bc & 0xffffff);
  if (*(char *)(in_ECX + 0xab) != '\0') {
    do {
      FUN_00401740(s_pan_stone__d_check_009da720,0x12);
      uVar4 = FUN_00404230(&pvStack_9c);
      FUN_00401660(uVar4,0,0xffffffff);
      if (0xf < uStack_84) {
        _free(pvStack_98);
        return extraout_EAX_00;
      }
      uStack_84 = 0xf;
      uStack_88 = 0;
      pvStack_98 = (void *)((uint)pvStack_98 & 0xffffff00);
      piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_b8);
      if (piVar6 != (int *)0x0) {
        puVar7 = (undefined3 *)(**(code **)(*piVar6 + 0x10))();
        uStack_78 = CONCAT13(uStack_78._3_1_,*puVar7);
        uStack_74 = *(undefined4 *)(puVar7 + 1);
        uStack_70 = *(undefined4 *)(puVar7 + 2);
        uStack_6c = *(undefined4 *)(puVar7 + 3);
        uStack_68 = *(undefined4 *)(puVar7 + 4);
        uStack_64 = *(undefined4 *)(puVar7 + 5);
        uStack_60 = *(undefined4 *)(puVar7 + 6);
        uStack_5c = *(undefined4 *)(puVar7 + 7);
        uStack_40 = 0xf;
        uStack_44 = 0;
        pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
        FUN_00401660(puVar7 + 8,0,0xffffffff);
        uStack_78 = uStack_78 & 0xffffff00;
        (**(code **)(*piVar6 + 0xc))(&uStack_78);
        if (0xf < uStack_40) {
          _free(pvStack_54);
          return extraout_EAX_01;
        }
        uStack_40 = 0xf;
        uStack_44 = 0;
        pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
      }
      bVar3 = uStack_bc._3_1_ + 1;
      uStack_bc = (void *)CONCAT13(bVar3,(undefined3)uStack_bc);
    } while (bVar3 < *(byte *)(in_ECX + 0xab));
  }
  uVar4 = FUN_00402220(&pvStack_9c,param_1,s__check_009da734);
  FUN_00401660(uVar4,0,0xffffffff);
  if (0xf < uStack_84) {
    _free(pvStack_98);
    return extraout_EAX_02;
  }
  piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_b8);
  if (piVar6 != (int *)0x0) {
    puVar7 = (undefined3 *)(**(code **)(*piVar6 + 0x10))();
    uStack_7c = CONCAT13(uStack_7c._3_1_,*puVar7);
    uStack_78 = *(uint *)(puVar7 + 1);
    uStack_74 = *(undefined4 *)(puVar7 + 2);
    uStack_70 = *(undefined4 *)(puVar7 + 3);
    uStack_6c = *(undefined4 *)(puVar7 + 4);
    uStack_68 = *(undefined4 *)(puVar7 + 5);
    uStack_64 = *(undefined4 *)(puVar7 + 6);
    uStack_60 = *(undefined4 *)(puVar7 + 7);
    uStack_44 = 0xf;
    uStack_48 = 0;
    pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
    FUN_00401660(puVar7 + 8,0,0xffffffff);
    uStack_7c = CONCAT31(uStack_7c._1_3_,1);
    (**(code **)(*piVar6 + 0xc))(&uStack_7c);
    if (0xf < uStack_44) {
      _free(pvStack_58);
      return extraout_EAX_03;
    }
  }
  _Memory_00 = &uStack_bc;
  piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  puVar7 = (undefined3 *)(**(code **)(*piVar6 + 0x10))();
  uStack_44 = CONCAT13(uStack_44._3_1_,*puVar7);
  uStack_40 = *(uint *)(puVar7 + 1);
  uStack_3c = *(undefined4 *)(puVar7 + 2);
  pvStack_38 = *(void **)(puVar7 + 3);
  uStack_34 = *(undefined4 *)(puVar7 + 4);
  uStack_30 = *(undefined4 *)(puVar7 + 5);
  uStack_2c = *(undefined4 *)(puVar7 + 6);
  uStack_28 = *(undefined4 *)(puVar7 + 7);
  uStack_c = 0xf;
  uStack_10 = 0;
  uStack_20 = 0;
  FUN_00401660(puVar7 + 8,0,0xffffffff);
  uStack_44 = CONCAT31(uStack_44._1_3_,1);
  (**(code **)(*piVar6 + 0xc))(&uStack_44);
  uVar1 = *(uint *)(iStack_8 + 0x14) - 1;
  if (*(uint *)(iStack_8 + 0x14) <= uVar1) {
    FUN_0079dba3();
  }
  if (*(uint *)(iStack_8 + 0x18) < 0x10) {
    iStack_8 = iStack_8 + 4;
  }
  else {
    iStack_8 = *(int *)(iStack_8 + 4);
  }
  uStack_8c = CONCAT13(*(undefined1 *)(iStack_8 + uVar1),(undefined3)uStack_8c);
  lVar8 = _atol((char *)((int)&uStack_8c + 3));
  (**(code **)(*DAT_00b5b0d0 + 0x28))(lVar8);
  FUN_0067e160();
  (**(code **)(*DAT_00b5b0cc + 0x50))
            (*(undefined4 *)(in_ECX + 0xb4),*(undefined4 *)(in_ECX + 0xb0),1000,0);
  if (0xf < uStack_24) {
    _free(pvStack_38);
    return extraout_EAX_04;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  if (unaff_EBX < (void *)0x10) {
    return 1;
  }
  _free(_Memory_00);
  return extraout_EAX_05;
}


// ==== FUN_0067ecc0 @ 0x0067ecc0 ====

void FUN_0067ecc0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  void *unaff_EBP;
  undefined4 uStack_a8;
  undefined1 uStack_a4;
  undefined4 uStack_a0;
  uint uStack_9c;
  undefined4 uStack_98;
  void *pvStack_94;
  undefined4 uStack_90;
  undefined4 uStack_84;
  uint uStack_80;
  undefined1 auStack_7c [4];
  void *pvStack_78;
  undefined4 uStack_68;
  uint uStack_64;
  undefined1 auStack_60 [4];
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined1 auStack_3c [16];
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  uint uStack_10;
  
  uVar1 = (**(code **)(*DAT_00b5a78c + 0x40))();
  uStack_90 = 0xf;
  pvStack_94 = (void *)0x0;
  uStack_a4 = 0;
  FUN_00401740(s_lbl_money_009da8ec,9);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_a8);
  if (0xf < pvStack_94) {
    _free(uStack_a8);
    return;
  }
  pvStack_94 = (void *)0xf;
  uStack_98 = 0;
  uStack_a8 = (void *)((uint)uStack_a8 & 0xffffff00);
  (**(code **)(*DAT_00b5ad20 + 0x48))(auStack_3c,uVar1);
  (**(code **)(*piVar2 + 0x30))();
  uVar1 = FUN_004041a0(auStack_28,uVar1,s_<_color>_009da8f8);
  uVar1 = FUN_004022a0(auStack_7c,s_<color__009da908,auStack_44,&DAT_009da904,uVar1);
  uVar1 = FUN_00402220(&uStack_98,uVar1);
  uVar1 = FUN_00405bd0(auStack_60,uVar1);
  uVar1 = FUN_00402220(auStack_7c + -0x38,uVar1);
  FUN_0055a260(uVar1);
  if (0xf < uStack_9c) {
    _free(unaff_EBP);
    return;
  }
  uStack_9c = 0xf;
  uStack_a0 = 0;
  if (0xf < uStack_48) {
    _free(pvStack_5c);
    return;
  }
  uStack_48 = 0xf;
  uStack_4c = 0;
  pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
  if (0xf < uStack_80) {
    _free(pvStack_94);
    return;
  }
  uStack_80 = 0xf;
  uStack_84 = 0;
  pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
  if (0xf < uStack_64) {
    _free(pvStack_78);
    return;
  }
  uStack_64 = 0xf;
  uStack_68 = 0;
  pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return;
  }
  if (uStack_2c < 0x10) {
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_0067ee80 @ 0x0067ee80 ====

void FUN_0067ee80(void)

{
  byte bVar1;
  int *piVar2;
  int in_ECX;
  uint unaff_EBX;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uStack_2c;
  byte bStack_28;
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
  
  puVar4 = (undefined4 *)(in_ECX + 0x14);
  iVar3 = 4;
  do {
    if ((void *)*puVar4 != (void *)0x0) {
      _free((void *)*puVar4);
      return;
    }
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4 = puVar4 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  (**(code **)(*DAT_00b5a78c + 0x38))(&local_24);
  uStack_14 = 0xffffffff;
  if (local_24 != (void *)0x0) {
    uStack_1c = (uint)bStack_27;
    uStack_18 = (uint)bStack_26;
    pvStack_20 = local_24;
    uStack_14 = FUN_0067d2e0(local_24);
    iVar5 = (bStack_28 + 1) * 0x10 + in_ECX;
    iVar3 = *(int *)(iVar5 + 4);
    if ((iVar3 == 0) ||
       ((uint)(*(int *)(iVar5 + 0xc) - iVar3 >> 4) <= (uint)(*(int *)(iVar5 + 8) - iVar3 >> 4))) {
      FUN_00680c50(*(undefined4 *)(iVar5 + 8),1,&pvStack_20);
    }
    else {
      iVar3 = *(int *)(iVar5 + 8);
      FUN_00680b80(iVar3,1,&pvStack_20,iVar5,unaff_EBX);
      *(int *)(iVar5 + 8) = iVar3 + 0x10;
    }
    (**(code **)(*DAT_00b5a78c + 0x3c))((int)register0x00000010 + -0x30);
    while (uStack_2c != (void *)0x0) {
      uStack_1c = unaff_EBX >> 8 & 0xff;
      uStack_18 = unaff_EBX >> 0x10 & 0xff;
      pvStack_20 = uStack_2c;
      uStack_14 = FUN_0067d2e0(uStack_2c);
      iVar5 = ((unaff_EBX & 0xff) + 1) * 0x10 + in_ECX;
      iVar3 = *(int *)(iVar5 + 4);
      if ((iVar3 == 0) ||
         ((uint)(*(int *)(iVar5 + 0xc) - iVar3 >> 4) <= (uint)(*(int *)(iVar5 + 8) - iVar3 >> 4))) {
        FUN_00680c50(*(undefined4 *)(iVar5 + 8),1,&pvStack_20);
      }
      else {
        iVar3 = *(int *)(iVar5 + 8);
        FUN_00680b80(iVar3,1,&pvStack_20,iVar5,unaff_EBX);
        *(int *)(iVar5 + 8) = iVar3 + 0x10;
      }
      (**(code **)(*DAT_00b5a78c + 0x3c))((int)register0x00000010 + -0x30);
    }
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = uStack_1c & 0xffffff00;
  FUN_00401740(s_slotbag_009da910,7);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
  if (uStack_c < 0x10) {
    uStack_c = 0xf;
    uStack_10 = 0;
    pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
    (**(code **)(*piVar2 + 0x30))();
    bVar1 = (**(code **)(*DAT_00b5a78c + 0x50))();
    *(byte *)(in_ECX + 0xac) = bVar1;
    FUN_005817e0((bVar1 + 1) * 0x10 + in_ECX,1);
    return;
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_0067f0b0 @ 0x0067f0b0 ====

/* WARNING: Removing unreachable block (ram,0x0067f137) */

void FUN_0067f0b0(undefined4 param_1,byte *param_2,ushort param_3)

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


// ==== FUN_0067f160 @ 0x0067f160 ====

void FUN_0067f160(void)

{
  int *piVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  void *local_20;
  void *local_1c;
  undefined1 local_18;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  FUN_0067ecc0();
  FUN_0067ee80();
  FUN_0067d690();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_tab_chang_shield_009da8c4,0x10);
  local_20 = (void *)CONCAT31(local_20._1_3_,*(undefined1 *)(in_ECX + 0xad));
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  (**(code **)(*piVar1 + 0x30))();
  FUN_00582440(unaff_EBX);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(s_tab_chang_weapon_009da8d8,0x10);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_20);
  (**(code **)(*piVar1 + 0x30))();
  FUN_00582440(unaff_ESI);
  if (uStack_c < 0x10) {
    FUN_0067dfe0(*(undefined1 *)(in_ECX + 0xac));
    return;
  }
  _free(local_20);
  return;
}


// ==== FUN_0067f250 @ 0x0067f250 ====

int FUN_0067f250(undefined4 param_1,ushort *param_2)

{
  undefined4 uVar1;
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int extraout_EAX_02;
  int extraout_EAX_03;
  int extraout_EAX_04;
  undefined4 unaff_EBP;
  void *unaff_ESI;
  undefined1 local_84 [2];
  undefined1 auStack_82 [2];
  void *local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined1 local_74 [4];
  undefined4 uStack_70;
  uint uStack_6c;
  void *pvStack_64;
  undefined1 local_58 [4];
  uint local_54;
  uint uStack_50;
  void *pvStack_48;
  undefined4 local_44;
  undefined4 local_40;
  uint local_38;
  uint uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [4];
  void *local_28;
  undefined4 local_24;
  undefined1 local_1c [4];
  void *local_18;
  uint uStack_14;
  int iStack_c;
  uint local_4;
  
  local_80 = (void *)0x0;
  local_7c = 0;
  local_78 = 0;
  local_40 = 0xf;
  local_44 = 0;
  local_54 = local_54 & 0xffffff00;
  local_24 = 0xf;
  local_28 = (void *)0x0;
  local_38 = local_38 & 0xffffff00;
  FUN_00401740(s_<VALUE>_009daa64,7);
  FUN_00401740(&DAT_009daa6c,2);
  uVar1 = FUN_00404230(local_1c);
  FUN_00401660(uVar1,0,0xffffffff);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  FUN_004e6c20(local_58);
  (**(code **)(*DAT_00b5a794 + 8))(local_74,2,*param_2 | 0xc80000,local_84);
  FUN_00401740(s_<color__x>_s<_color>_009daa70,0x14);
  uVar1 = FUN_00404230(auStack_2c);
  FUN_00401660(uVar1,0,0xffffffff);
  if (0xf < uStack_14) {
    _free(local_28);
    return extraout_EAX_00;
  }
  FUN_004020e0(s_<_font>_009daa88,7);
  *(undefined4 *)(iStack_c + 0x18) = 0xf;
  *(undefined4 *)(iStack_c + 0x14) = 0;
  *(undefined1 *)(iStack_c + 4) = 0;
  FUN_00401660(local_84,0,0xffffffff);
  if (0xf < uStack_6c) {
    _free(local_80);
    return extraout_EAX_01;
  }
  uStack_6c = 0xf;
  uStack_70 = 0;
  local_80 = (void *)((uint)local_80 & 0xffffff00);
  if (0xf < uStack_34) {
    _free(pvStack_48);
    return extraout_EAX_02;
  }
  uStack_34 = 0xf;
  local_38 = 0;
  pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
  if (0xf < uStack_50) {
    _free(pvStack_64);
    return extraout_EAX_03;
  }
  uStack_50 = 0xf;
  local_54 = 0;
  pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
  if (unaff_ESI == (void *)0x0) {
    return iStack_c;
  }
  FUN_004e65b0(unaff_ESI,unaff_EBP,local_84 + -0x10,uStack_30);
  _free(unaff_ESI);
  return extraout_EAX_04;
}


// ==== FUN_0067f450 @ 0x0067f450 ====

int FUN_0067f450(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_EAX;
  int extraout_EAX_00;
  int iVar3;
  uint uVar4;
  undefined1 auStack_38 [4];
  void *pvStack_34;
  undefined4 uStack_24;
  uint uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar1 = (**(code **)(*param_2 + 4))();
  uStack_20 = 0xf;
  uStack_24 = 0;
  pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
  uVar4 = 0;
  if (*(int *)(iVar1 + 0xe4) != 0) {
    iVar3 = iVar1 + 0xb4;
    do {
      uVar2 = FUN_0067f250(auStack_1c,iVar3);
      FUN_00401660(uVar2,0,0xffffffff);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return extraout_EAX;
      }
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 8;
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    } while (uVar4 < *(uint *)(iVar1 + 0xe4));
  }
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


// ==== FUN_0067f520 @ 0x0067f520 ====

void FUN_0067f520(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  int in_ECX;
  int iVar6;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  short *psVar7;
  uint uVar8;
  undefined4 uStack_1cc;
  void *pvStack_1c8;
  uint uStack_1c4;
  uint uStack_1c0;
  uint uStack_1bc;
  void *pvStack_1b8;
  void *pvStack_1b4;
  void *pvStack_1b0;
  void *pvStack_1ac;
  undefined4 uStack_1a8;
  uint uStack_1a4;
  uint uStack_1a0;
  uint uStack_19c;
  int *piStack_198;
  int *piStack_194;
  uint uStack_190;
  uint uStack_188;
  void *pvStack_184;
  undefined4 uStack_174;
  uint uStack_170;
  undefined1 auStack_16c [4];
  void *pvStack_168;
  void *pvStack_158;
  uint uStack_154;
  undefined4 uStack_148;
  uint uStack_144;
  undefined1 auStack_140 [4];
  void *pvStack_13c;
  undefined4 uStack_12c;
  uint uStack_128;
  undefined1 auStack_114 [36];
  void *pvStack_f0;
  undefined1 auStack_e4 [4];
  undefined4 uStack_e0;
  uint uStack_dc;
  void *pvStack_c0;
  undefined4 uStack_b0;
  uint uStack_ac;
  undefined1 auStack_a4 [36];
  void *pvStack_80;
  undefined4 uStack_70;
  uint uStack_6c;
  undefined1 auStack_60 [36];
  void *pvStack_3c;
  undefined4 uStack_2c;
  uint uStack_28;
  short asStack_24 [18];
  
  cVar1 = (**(code **)(*DAT_00b5b0cc + 0x4c))();
  if (cVar1 == '\0') {
    pvStack_1b4 = (void *)0xf;
    pvStack_1b8 = (void *)0x0;
    pvStack_1c8 = (void *)((uint)pvStack_1c8 & 0xffffff00);
    FUN_00401740(s_pan_stone_0_check_009da9a4,0x11);
    FUN_0067d390(&uStack_1cc,0);
    if ((void *)0xf < pvStack_1b4) {
      _free(pvStack_1c8);
      return;
    }
    pvStack_1b4 = (void *)0xf;
    pvStack_1b8 = (void *)0x0;
    pvStack_1c8 = (void *)((uint)pvStack_1c8 & 0xffffff00);
    FUN_00401740(s_pan_stone_1_check_009da9b8,0x11);
    FUN_0067d390(&uStack_1cc,0);
    if ((void *)0xf < pvStack_1b4) {
      _free(pvStack_1c8);
      return;
    }
    pvStack_1b4 = (void *)0xf;
    pvStack_1b8 = (void *)0x0;
    pvStack_1c8 = (void *)((uint)pvStack_1c8 & 0xffffff00);
    FUN_00401740(s_pan_stone_2_check_009da9cc,0x11);
    FUN_0067d390(&uStack_1cc,0);
    if ((void *)0xf < pvStack_1b4) {
      _free(pvStack_1c8);
      return;
    }
    pvStack_1b4 = (void *)0xf;
    pvStack_1b8 = (void *)0x0;
    pvStack_1c8 = (void *)((uint)pvStack_1c8 & 0xffffff00);
    FUN_00401740(s_pan_stone_3_check_009da9e0,0x11);
    FUN_0067d390(&uStack_1cc,0);
    if ((void *)0xf < pvStack_1b4) {
      _free(pvStack_1c8);
      return;
    }
    pvStack_1b4 = (void *)0xf;
    pvStack_1b8 = (void *)0x0;
    pvStack_1c8 = (void *)((uint)pvStack_1c8 & 0xffffff00);
    FUN_00401740(s_lbl_stone_0_009da9f4,0xb);
    FUN_0067d390(&uStack_1cc,0);
    if ((void *)0xf < pvStack_1b4) {
      _free(pvStack_1c8);
      return;
    }
    piStack_198 = (int *)0xf;
    uStack_19c = 0;
    pvStack_1ac = (void *)((uint)pvStack_1ac & 0xffffff00);
    FUN_00401740(s_lbl_stone_0_009daa00,0xb);
    pvStack_1b4 = (void *)0xf;
    pvStack_1b8 = (void *)0x0;
    pvStack_1c8 = (void *)((uint)pvStack_1c8 & 0xffffff00);
    FUN_00401740(&DAT_009daa0c,0);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1b0);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x30))();
      FUN_0055a260(auStack_16c + -100);
    }
    if ((void *)0xf < pvStack_1b8) {
      _free(uStack_1cc);
      return;
    }
    pvStack_1b8 = (void *)0xf;
    uStack_1bc = 0;
    uVar8 = (uint)uStack_1cc >> 8;
    uStack_1cc = (void *)(uVar8 << 8);
    if (0xf < uStack_19c) {
      _free(pvStack_1b0);
      return;
    }
    pvStack_1b8 = (void *)0xf;
    uStack_1bc = 0;
    uStack_1cc = (void *)(uVar8 << 8);
    FUN_00401740(s_lbl_stone_1_009daa10,0xb);
    FUN_0067d390(auStack_16c + -100,0);
    if ((void *)0xf < pvStack_1b8) {
      _free(uStack_1cc);
      return;
    }
    uStack_19c = 0xf;
    uStack_1a0 = 0;
    pvStack_1b0 = (void *)((uint)pvStack_1b0 & 0xffffff00);
    FUN_00401740(s_lbl_stone_1_009daa1c,0xb);
    pvStack_1b8 = (void *)0xf;
    uStack_1bc = 0;
    uStack_1cc = (void *)((uint)uStack_1cc & 0xffffff00);
    FUN_00401740(&DAT_009daa28,0);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1b4);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x30))();
      FUN_0055a260(auStack_16c + -0x68);
    }
    if (0xf < uStack_1bc) {
      _free(unaff_EBX);
      return;
    }
    uStack_1bc = 0xf;
    uStack_1c0 = 0;
    if (0xf < uStack_1a0) {
      _free(pvStack_1b4);
      return;
    }
    uStack_1bc = 0xf;
    uStack_1c0 = 0;
    FUN_00401740(s_lbl_stone_2_009daa2c,0xb);
    FUN_0067d390(auStack_16c + -0x68,0);
    if (0xf < uStack_1bc) {
      _free((void *)((uint)unaff_EBX & 0xffffff00));
      return;
    }
    uStack_1a0 = 0xf;
    uStack_1a4 = 0;
    pvStack_1b4 = (void *)((uint)pvStack_1b4 & 0xffffff00);
    FUN_00401740(s_lbl_stone_2_009daa38,0xb);
    uStack_1bc = 0xf;
    uStack_1c0 = 0;
    FUN_00401740(&DAT_009daa44,0);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1b8);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x30))();
      FUN_0055a260(auStack_16c + -0x6c);
    }
    if (0xf < uStack_1c0) {
      _free(unaff_EBP);
      return;
    }
    uStack_1c0 = 0xf;
    uStack_1c4 = 0;
    if (0xf < uStack_1a4) {
      _free(pvStack_1b8);
      return;
    }
    uStack_1c0 = 0xf;
    uStack_1c4 = 0;
    FUN_00401740(s_lbl_stone_3_009daa48,0xb);
    FUN_0067d390(auStack_16c + -0x6c,0);
    if (0xf < uStack_1c0) {
      _free((void *)((uint)unaff_EBP & 0xffffff00));
      return;
    }
    uStack_1a4 = 0xf;
    uStack_1a8 = 0;
    pvStack_1b8 = (void *)((uint)pvStack_1b8 & 0xffffff00);
    FUN_00401740(s_lbl_stone_3_009daa54,0xb);
    uStack_1c0 = 0xf;
    uStack_1c4 = 0;
    FUN_00401740(&DAT_009daa60,0);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_1bc);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x30))();
      FUN_0055a260(&uStack_1cc);
    }
    if ((void *)0xf < pvStack_1b4) {
      _free(pvStack_1c8);
      return;
    }
    pvStack_1b4 = (void *)0xf;
    pvStack_1b8 = (void *)0x0;
    pvStack_1c8 = (void *)((uint)pvStack_1c8 & 0xffffff00);
  }
  else {
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5b0cc + 0x24))();
    puVar2 = (undefined4 *)(**(code **)(*(int *)*puVar2 + 0x14))();
    psVar7 = asStack_24;
    for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined4 *)psVar7 = *puVar2;
      puVar2 = puVar2 + 1;
      psVar7 = psVar7 + 2;
    }
    uStack_188 = (**(code **)(*DAT_00b5b0d0 + 0x48))();
    uStack_188 = uStack_188 & 0xff;
    piStack_198 = (int *)0xf;
    uStack_19c = 0;
    pvStack_1ac = (void *)((uint)pvStack_1ac & 0xffffff00);
    uStack_190 = 0;
    if (uStack_188 == 0) {
      return;
    }
    do {
      uVar8 = uStack_190;
      piStack_198 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(asStack_24[uStack_190 + 2]);
      if (asStack_24[uVar8] == 0) {
        FUN_00401740(s_lbl_stone__d_009da970,0xc);
        uVar3 = FUN_00404230(auStack_16c);
        FUN_00401660(uVar3,0,0xffffffff);
        if (0xf < uStack_154) {
          _free(pvStack_168);
          return;
        }
        uStack_154 = 0xf;
        pvStack_158 = (void *)0x0;
        pvStack_168 = (void *)((uint)pvStack_168 & 0xffffff00);
        piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1b4);
        if (piVar4 != (int *)0x0) {
          uVar3 = (**(code **)(*piVar4 + 0x10))();
          FUN_005041e0(uVar3);
          auStack_a4[0] = 0;
          (**(code **)(*piVar4 + 0xc))(auStack_a4);
          if (0xf < uStack_6c) {
            _free(pvStack_80);
            return;
          }
          uStack_6c = 0xf;
          uStack_70 = 0;
          pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
        }
        piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1b8);
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 0x44))(0);
        }
        uStack_1c0 = 0xf;
        uStack_1c4 = 0;
        FUN_00401740(&DAT_009da97d,0);
        piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_1bc);
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 0x30))();
          FUN_0055a260(auStack_16c + -0x70);
        }
        if (0xf < uStack_1c4) {
          _free(unaff_ESI);
          return;
        }
        uStack_1c4 = 0xf;
        pvStack_1c8 = (void *)0x0;
        unaff_ESI = (void *)((uint)unaff_ESI & 0xffffff00);
        uVar8 = uStack_1a0;
      }
      else {
        FUN_00401740(s_lbl_stone__d_009da980,0xc);
        uVar3 = FUN_00404230(&uStack_188);
        FUN_00401660(uVar3,0,0xffffffff);
        if (0xf < uStack_170) {
          _free(pvStack_184);
          return;
        }
        uStack_170 = 0xf;
        uStack_174 = 0;
        pvStack_184 = (void *)((uint)pvStack_184 & 0xffffff00);
        piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1b4);
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 0x44))(1);
        }
        piStack_198 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1b8);
        if (piStack_198 != (int *)0x0) {
          uVar3 = (**(code **)(*piStack_198 + 0x10))();
          FUN_005041e0(uVar3);
          auStack_e4[0] = 1;
          (**(code **)(*piStack_198 + 0xc))(auStack_e4);
          if (0xf < uStack_ac) {
            _free(pvStack_c0);
            return;
          }
          uStack_ac = 0xf;
          uStack_b0 = 0;
          pvStack_c0 = (void *)((uint)pvStack_c0 & 0xffffff00);
        }
        uStack_1a0 = FUN_0067f450(&pvStack_158,uStack_1a0);
        piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_1bc);
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 0x30))();
          FUN_0055a260(uStack_1a4);
        }
        if (0xf < uStack_144) {
          _free(pvStack_158);
          return;
        }
        uStack_144 = 0xf;
        uStack_148 = 0;
        pvStack_158 = (void *)((uint)pvStack_158 & 0xffffff00);
      }
      FUN_00401740(s_pan_stone__d_check_009da990,0x12);
      uVar3 = FUN_00404230(auStack_140);
      FUN_00401660(uVar3,0,0xffffffff);
      if (0xf < uStack_128) {
        _free(pvStack_13c);
        return;
      }
      uStack_128 = 0xf;
      uStack_12c = 0;
      pvStack_13c = (void *)((uint)pvStack_13c & 0xffffff00);
      uVar5 = (**(code **)(*DAT_00b5b0d0 + 0x40))();
      if (uVar5 == uVar8) {
        piStack_194 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_1c0);
        if (piStack_194 != (int *)0x0) {
          uVar3 = (**(code **)(*piStack_194 + 0x10))();
          FUN_005041e0(uVar3);
          auStack_60[0] = 1;
          (**(code **)(*piStack_194 + 0xc))(auStack_60);
          if (0xf < uStack_28) {
            _free(pvStack_3c);
            return;
          }
          uStack_28 = 0xf;
          uStack_2c = 0;
          pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
        }
      }
      else {
        piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_1c0);
        if (piVar4 != (int *)0x0) {
          uVar3 = (**(code **)(*piVar4 + 0x10))();
          FUN_005041e0(uVar3);
          auStack_114[0] = 0;
          (**(code **)(*piVar4 + 0xc))(auStack_114);
          if (0xf < uStack_dc) {
            _free(pvStack_f0);
            return;
          }
          uStack_dc = 0xf;
          uStack_e0 = 0;
          pvStack_f0 = (void *)((uint)pvStack_f0 & 0xffffff00);
        }
        uVar8 = uStack_190;
      }
      uStack_190 = uVar8 + 1;
    } while (uStack_190 < uStack_188);
  }
  if (piStack_198 < (int *)0x10) {
    return;
  }
  _free(pvStack_1ac);
  return;
}


// ==== FUN_0067fe00 @ 0x0067fe00 ====

void FUN_0067fe00(void)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  undefined4 uVar5;
  int in_ECX;
  void *unaff_EBX;
  uint unaff_EBP;
  undefined1 auStack_1e [2];
  void *local_1c;
  uint local_18;
  uint uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  FUN_0067de60();
  FUN_0067dba0();
  FUN_0067d7f0();
  FUN_0067d9c0();
  FUN_0067df10();
  FUN_0067f520();
  FUN_0067e160();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = local_18 & 0xffffff00;
  FUN_00401740(s_btn_strength_009da844,0xc);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  cVar3 = (**(code **)(*DAT_00b5b0cc + 0x4c))();
  if (cVar3 == '\0') {
    (**(code **)(*piVar4 + 0x44))(0);
    uStack_14 = 0xf;
    local_18 = 0;
    uVar2 = unaff_EBP >> 8;
    FUN_00401740(s_pan_stone_0_check_009da868,0x11);
    FUN_0067d390(auStack_1e + -0xe,0);
    if (0xf < uStack_14) {
      _free((void *)(uVar2 << 8));
      return;
    }
    uStack_14 = 0xf;
    local_18 = 0;
    FUN_00401740(s_pan_stone_1_check_009da87c,0x11);
    FUN_0067d390(auStack_1e + -0xe,0);
    if (0xf < uStack_14) {
      _free((void *)(uVar2 << 8));
      return;
    }
    uStack_14 = 0xf;
    local_18 = 0;
    FUN_00401740(s_pan_stone_2_check_009da890,0x11);
    FUN_0067d390(auStack_1e + -0xe,0);
    if (0xf < uStack_14) {
      _free((void *)(uVar2 << 8));
      return;
    }
    uStack_14 = 0xf;
    local_18 = 0;
    FUN_00401740(s_pan_stone_3_check_009da8a4,0x11);
    FUN_0067d390(auStack_1e + -0xe,0);
    if (0xf < uStack_14) {
      _free((void *)(uVar2 << 8));
      return;
    }
  }
  else {
    (**(code **)(*piVar4 + 0x44))(1);
    uStack_c = 0xf;
    uStack_10 = 0;
    FUN_00401740(s_pan_effect_socket_009da854,0x11);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_1e + -6);
    if (0xf < uStack_10) {
      _free(unaff_EBX);
      return;
    }
    uStack_10 = 0xf;
    iVar1 = *DAT_00b5b0d0;
    uStack_14 = 0;
    uVar5 = (**(code **)(*piVar4 + 4))();
    (**(code **)(iVar1 + 0x34))(uVar5);
    if (*(char *)(in_ECX + 0xb8) == '\0') {
      (**(code **)(*DAT_00b5b0cc + 0x50))
                (*(undefined4 *)(in_ECX + 0xb4),*(undefined4 *)(in_ECX + 0xb0),1000,0);
      *(undefined1 *)(in_ECX + 0xb8) = 1;
      FUN_0067f160();
      return;
    }
  }
  FUN_0067f160();
  return;
}


